const { app, BrowserWindow } = require('electron')
const path = require('path')

var addon = require('bindings')('hello');

console.log(addon.hello());

function createWindow () {
    const win = new BrowserWindow({
        width: 1000,
        height: 800,
        webPreferences: {
            preload: path.join(__dirname, 'javascript', 'preload.js')
        }
    })

    win.loadFile(path.join('html', 'index.html'))
}

app.whenReady().then(() => {
    createWindow()

    app.on('activate', function () {
        if(BrowserWindow.getAllWindows().length === 0) createWindow()
    })
})

app.on('window-all-closed', function () {
    if(process.platform !== 'darwin') app.quit()
})

