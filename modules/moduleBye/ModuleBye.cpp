//
// Created by seres on 05/05/2020.
//
#include <Module.hpp>

class ModuleBye : public Module {
public:
    void run(SleepyDiscord::BaseDiscordClient *client, SleepyDiscord::Message message) override
    {
        client->sendMessage(message.channelID, "bye from module");
    }
};

extern "C" Module *loader()
{
    return new ModuleBye();
}
