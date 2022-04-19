# Streamlabs-Demo

This is the coding assignment provided to assess a candidate's knowledge and technical expertise.

## Packaging of the Application

The project installed the dependencies necessary for Electron Forge. GitHub actions could be set up to ensure ```npx electron-forge import``` is run every time. I built it with ```npm run package``` that produced an ```out``` folder. There were files that were too large, but this is available and works. The tutorial wanted to do ```npm run make```, but this had missing dependencies and vulenerabilities for ```rpmbuild```. Given the alternative works (I think), I went with it instead.
