
# ShapeCorners
<img src="https://i.imgur.com/H9nuCv8.png" alt="img" align="right" width="400px">
KDE effect rounds/chisels corners of your windows.

Fork of https://sourceforge.net/projects/shapecorners/

### Features:
- Customizable via config file
- Different types of corner: `Rounded` and `Chiseled`
- Each corner can have different radius
- Ability to square corner when windows edge is at screen edge.
- Ability to define `Whitelist` and `Blacklist` to exclude/force applying ShapeCorners

## Dependencies
- Distro Debian based (Ubuntu, Kubuntu):
```
sudo apt install git cmake g++ gettext extra-cmake-modules qttools5-dev libqt5x11extras5-dev libkf5configwidgets-dev libkf5crash-dev libkf5globalaccel-dev libkf5kio-dev libkf5notifications-dev kinit-dev kwin-dev 
```

## Build
```
git clone https://github.com/khanhas/ShapeCorners
cd ShapeCorners
mkdir build; cd build
cmake ../ -DCMAKE_INSTALL_PREFIX=/usr -DQT5BUILD=ON
make && sudo make install
kwin_x11 --replace &
```

It should be now activated.

## Config
- Create file `shapecornersrc` in `~/.config`
- Follow this template:
```ini
[General]
Radius=10
Type=Rounded
SquareAtScreenEdge=false
FilterShadow=false
Whitelist=
Blacklist=
```

- `Radius`: Define all corners' or specific corner's radius. Accept 1 to 4 numbers, separate by `,`. E.g.:
    - `Radius=20`: All corners have 20 radius
    - `Radius=10,20`: Top Left and Bottom Right has 10; Top Right and Bottom Left has 20
    - `Radius=30,40,50`: Top Left has 30; Top Right and Bottom Left has 40; Bottom Right has 50
    - `Radius=20,50,30,10`: Top Left has 20; Top Right has 50; Bottom Right has 30; Bottom Left has 10
- `Type`: `Rounded` or `Chiseled`
- `SquareAtScreenEdge`: Square off corner at when window edge is at screen edge. Boolean `true` or `false`.
- `FilterShadow`: Since there is no way to change corners of shadow layer, you might want to remove shadow layer out. Boolean `true` or `false`.
- `Whitelist`: List of window class names that will be forced to apply ShapeCorners. Separate them by `,`. E.g.:
    - `Whitelist=conky`
    - `Whitelist=plasma,conky`
- `Blacklist`: List of window class names that will be excluded from applying ShapeCorners. Separate them by `,`. E.g.:
    - `Blacklist=krunner`
    - `Blacklist=krunner,display`

After changing config, run:
```bash
kwin_x11 --replace &
```