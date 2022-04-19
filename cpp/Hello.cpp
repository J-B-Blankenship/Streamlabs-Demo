#include <napi.h>

Napi::String Method(const Napi::CallbackInfo& info)
{
    Napi::Env environment{ info.Env() };
    return Napi::String::New(environment, "world");
}

Napi::Object Init(Napi::Env environment, Napi::Object exports)
{
    exports.Set(Napi::String::New(environment, "hello"),
        Napi::Function::New(environment, Method));
    return exports;
}

NODE_API_MODULE(Hello, Init)