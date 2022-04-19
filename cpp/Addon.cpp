#include "Example.h"

Napi::Object InitAll(Napi::Env environment, Napi::Object exports)
{
    return Example::Init(environment, exports);
}

NODE_API_MODULE(addon, InitAll)