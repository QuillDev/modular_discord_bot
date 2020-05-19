//
// Created by seres on 05/05/2020.
//

#ifndef DISCORD_BOT_MODULE_HPP
#define DISCORD_BOT_MODULE_HPP

#include <string>
#include <dlfcn.h>
#include <sleepy_discord/client.h>

class Module {
public:
    virtual void run(SleepyDiscord::BaseDiscordClient *, SleepyDiscord::Message) = 0;
};

#endif //DISCORD_BOT_MODULE_HPP
