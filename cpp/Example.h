#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <napi.h>

class Example final : public Napi::ObjectWrap<Example>
{
public:
    static Napi::Object Init(Napi::Env environment, Napi::Object exports);
    Example(const Napi::CallbackInfo& info);

    //Complete the Rule of Five because of defining constructor above.
    Example() = delete;
    ~Example() = default;
    
    Example(const Example& other) = delete;
    
    Example(Example&& other) = delete;
    
    Example& operator=(Example other) = delete;


private:
    std::string m_message{};

    Napi::String GetMessage(const Napi::CallbackInfo& info);
    Napi::String AppendMessage(const Napi::CallbackInfo& info);
    Napi::String ClearMessage(const Napi::CallbackInfo& info);
};

#endif //EXAMPLE_H