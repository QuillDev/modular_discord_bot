#include <DiscordBot.hpp>
#include <Config.hpp>

int main()
{
    DiscordBot client(TOKEN);
    client.run();
}