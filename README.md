# Streamlabs-Demo

This is the coding assignment provided to assess a candidate's knowledge and technical expertise.

## General Approach

I know the purpose of this was probably to assess the ability to quickly adapt to third-party libraries, setups, and what not, but I am hijacking your assessment. Commits may span over a day or two because I am taking breaks and reading more into the different components. I want to kill two birds with one stone rather than blazing through the stuff without understanding any of it. This stuff looks exactly like what I may need for a private repository I have, particularly the C++ addons/extensions. 

I hope you do not mind. The rest of the README will list different pieces I either attempted, partially completed, or completed fully.

## Commits

Commits were done directly to ```master```. This is not typical in my workflow, but the project is relatively small. My other projects utilize GitHub Actions, merge requests, and branches to utilize the full version control capabilities.

## Packaging of the Application

The project installed the dependencies necessary for Electron Forge. GitHub actions could be set up to ensure ```npx electron-forge import``` is run every time. I built it with ```npm run package``` that produced an ```out``` folder. There were files that were too large, but this is available and works. The tutorial wanted to do ```npm run make```, but this had missing dependencies and vulenerabilities for ```rpmbuild```. Given the alternative works (I think), I went with it instead.
