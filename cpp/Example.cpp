#include "Example.h"
#include "../third_party/obs-studio/libobs/obs.h"

Napi::Object Example::Init(Napi::Env environment, Napi::Object exports)
{
    Napi::Function function = DefineClass(environment,
        "Example",
        {
            InstanceMethod("getMessage", &Example::GetMessage),
            InstanceMethod("appendMessage", &Example::AppendMessage),
            InstanceMethod("clearMessage", &Example::ClearMessage)
        }
    );

    Napi::FunctionReference* constructor{ new Napi::FunctionReference{} };
    *constructor = Napi::Persistent(function);
    environment.SetInstanceData(constructor);

    exports.Set("Example", function);
    return exports;
}

Example::Example(const Napi::CallbackInfo& info) :
    Napi::ObjectWrap<Example>{ info }
{
    Napi::Env environment{ info.Env() };
    uint64_t length{ info.Length() };

    if(length == 0 || !info[0].IsString())
    {
        Napi::TypeError::New(environment, "String expected.").ThrowAsJavaScriptException();
        return;
    }

    Napi::String value{ info[0].As<Napi::String>() };
    this->m_message = value.Utf8Value();
}

Napi::String Example::GetMessage(const Napi::CallbackInfo& info)
{
    return Napi::String::New(info.Env(), this->m_message);
}

Napi::String Example::AppendMessage(const Napi::CallbackInfo& info)
{
    const std::string temp{ this->m_message + " appending" };
    return Napi::String::New(info.Env(), temp);
}

Napi::String Example::ClearMessage(const Napi::CallbackInfo& info)
{
    this->m_message.clear();
    return Napi::String::New(info.Env(), this->m_message);
}