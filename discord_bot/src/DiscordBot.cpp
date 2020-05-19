//
// Created by seres on 19/05/2020.
//

#include <DiscordBot.hpp>

bool DiscordBot::checkModuleExists(const std::string &module)
{
    for (auto &mod : _modules)
        if (mod.second == module)
            return true;
    return false;
}

void DiscordBot::loadModule(const SleepyDiscord::Message &message)
{
    std::string moduleName(message.content.substr(std::strlen(PREFIX) + 5));
    if (checkModuleExists(moduleName)) {
        sendMessage(message.channelID, "Module `" + moduleName + "` is already loaded! You can check loaded modules with `" PREFIX"list`!");
        return;
    }
    std::string tmp("../../lib/lib" + moduleName + ".so");
    std::cout << "Loading module " << moduleName << std::endl;
    DLLWrapper<Module> dll(tmp, "loader");
    _modules.emplace_back(std::pair<DLLWrapper<Module> &, std::string>(dll, moduleName));
    sendMessage(message.channelID, "Loaded module `" + moduleName + "`!");
}

void DiscordBot::unloadModule(const SleepyDiscord::Message &message)
{
    std::string moduleName(message.content.substr(std::strlen(PREFIX) + 7));
    std::cout << "Removing module " << moduleName << std::endl;
    for (auto &module : _modules)
        if (module.second == moduleName)
            module.first.destroy();
    for (auto it = _modules.begin(); it != _modules.end(); ++it)
        if (it->second == moduleName)
            _modules.erase(it--);
    sendMessage(message.channelID, "Unloaded module `" + moduleName + "`!");
}

void DiscordBot::runModule(const SleepyDiscord::Message &message)
{
    std::string moduleName(message.content.substr(std::strlen(PREFIX)));

    for (auto &module : _modules)
        if (module.second == moduleName)
            module.first.getFunction()->run(this, message);
}

void DiscordBot::listModules(const SleepyDiscord::Message &message)
{
    std::string list;

    if (_modules.empty())
        sendMessage(message.channelID, "No modules loaded.");
    else {
        for (auto &module : _modules)
            list.append("`" + module.second + "`, ");
        list.erase(list.size() - 2, list.size() - 1);
        sendMessage(message.channelID, "Here is the list of loaded modules: " + list + ".");
    }
}

void DiscordBot::onMessage(SleepyDiscord::Message message)
{
    if (message.startsWith(PREFIX"load"))
        loadModule(message);
    else if (message.startsWith(PREFIX"unload"))
        unloadModule(message);
    else if (message.startsWith(PREFIX"list"))
        listModules(message);
    else if (message.startsWith(PREFIX"quit"))
        quit();
    else if (message.startsWith(PREFIX) && message.length() > 2)
        runModule(message);
}
