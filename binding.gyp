{
    'targets': [
        {
            "target_name": "hello",
            "cflags!": [ "-fno-exceptions"],
            "cflags_cc!": [ "-fno-exceptions" ],
            "libraries": [
            	"../third_party/obs-studio/libobs/libobs.so"
            ],
            "sources": [ "cpp/Hello.cpp"],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
        }
    ]
}
