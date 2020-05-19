//
// Created by seres on 05/05/2020.
//

#ifndef DISCORD_BOT_DLLWRAPPER_HPP
#define DISCORD_BOT_DLLWRAPPER_HPP

#include <string>

template<class T>
class DLLWrapper {
public:
    DLLWrapper() = default;

    DLLWrapper(const std::string &path, const std::string &fun)
    {
        _handle = dlopen(path.c_str(), RTLD_NOW);
        if (_handle != nullptr) {
            auto loader = reinterpret_cast<T *(*)()>((dlsym(_handle, fun.c_str())));
            _fun = std::shared_ptr<T>(loader());
        } else
            std::cout << dlerror() << std::endl;
    }

    std::shared_ptr<T> getFunction()
    {
        return _fun;
    }

    void destroy()
    {
        dlclose(_handle);
    }

private:
    void *_handle{};
    std::shared_ptr<T> _fun;
};

template
class DLLWrapper<Module *>;

#endif //DISCORD_BOT_DLLWRAPPER_HPP
