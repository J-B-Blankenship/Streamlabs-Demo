#include <napi.h>
#include "../third_party/obs-studio/libobs/obs.h"

Napi::String Method(const Napi::CallbackInfo& info)
{
    Napi::Env environment{ info.Env() };
    if(obs_startup())
    {
        return Napi::String::New(environment, "world");
    }
    return Napi::String::New(environment, "not linked");
}

Napi::Object Init(Napi::Env environment, Napi::Object exports)
{
    exports.Set(Napi::String::New(environment, "hello"),
        Napi::Function::New(environment, Method));
    return exports;
}

NODE_API_MODULE(Hello, Init)