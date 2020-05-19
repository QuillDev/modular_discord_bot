//
// Created by seres on 19/05/2020.
//

#ifndef DISCORD_BOT_WITH_MODULES_DISCORDBOT_HPP
#define DISCORD_BOT_WITH_MODULES_DISCORDBOT_HPP

#ifndef PREFIX
#define PREFIX "?"
#endif //PREFIX

#include <sleepy_discord/sleepy_discord.h>
#include <sleepy_discord/websocketpp_websocket.h>
#include <Module.hpp>
#include <DllWrapper.hpp>


class DiscordBot : public SleepyDiscord::DiscordClient {
public:
    using SleepyDiscord::DiscordClient::DiscordClient;

    bool checkModuleExists(const std::string &module);

    void loadModule(const SleepyDiscord::Message &message);

    void unloadModule(const SleepyDiscord::Message &message);

    void runModule(const SleepyDiscord::Message &message);

    void listModules(const SleepyDiscord::Message &message);

    void onMessage(SleepyDiscord::Message message) override;

private:
    std::vector<std::pair<DLLWrapper<Module>, std::string>> _modules;
};

#endif //DISCORD_BOT_WITH_MODULES_DISCORDBOT_HPP
