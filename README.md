# Streamlabs-Demo

This is the coding assignment provided to assess a candidate's knowledge and technical expertise.

## General Approach

I know the purpose of this was probably to assess the ability to quickly adapt to third-party libraries, setups, and what not, but I am hijacking your assessment. Commits may span over a day or two because I am taking breaks and reading more into the different components. I want to kill two birds with one stone rather than blazing through the stuff without understanding any of it. This stuff looks exactly like what I may need for a private repository I have, particularly the C++ addons/extensions. 

I hope you do not mind. The rest of the README will list different pieces I either attempted, partially completed, or completed fully. There are some issues with OpenGL on my machine, so I skipped the "bonus" content. 

The initial stuff took about an hour and a half. As for the rest, I spent a handful of hours exploring the capabilities of the different libraries and documentation.  

## Commits

Commits were done directly to ```master```. This is not typical in my workflow, but the project is relatively small. My other projects utilize GitHub Actions, merge requests, and branches to utilize the full version control capabilities.

## Packaging of the Application

The project installed the dependencies necessary for Electron Forge. GitHub actions could be set up to ensure ```npx electron-forge import``` is run every time. I built it with ```npm run package``` that produced an ```out``` folder. There were files that were too large, but this is available and works. The tutorial wanted to do ```npm run make```, but this had missing dependencies and vulenerabilities for ```rpmbuild```. Given the alternative works (I think), I went with it instead.

## Dependency Management

Normally, I would utilize Bazel's git repository feature to specify a particular version or latest. CMake has the same capabilities, but previous experience at a previous job was that it was a hassle. Depending on system permissions, this may not be a valid option if you were to use it.

Due to these reasons, I remembered git has submodules. While I have not used submodules in the past, this seemed fairly straightforward and a good way to keep the dependency(ies) together. It also allows the CMakelist component to be more straightforward with third-party libraries within the same repository. To boot, everything is one place, visibile to users of the repository, and removes system privilege concerns. 

## Object Wrapper Effort

I attempted to use the object wrapper, but there were issues with the ```InstanceMethod```. After a while, I got tired of messing with it, but the effort is included in the respository. There was a namespace around it and ```const``` applied where appropriate at one point. However, I was not sure where the issue was coming from besides the typical obscure template compile time error. 

The overarching goal was to take that message and display it in the NodeJS display. Maybe call an update method or something on a timer in the background with the ```appendMessage()``` function to update the display.

