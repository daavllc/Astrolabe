# Astrolabe v0.0.1
Easy to use cross-platform maps and navigation application

## Purpose
Provide a one-stop-shop for anything maps and weather related. While we intend to support various features that not everyone may use, we hope to streamline the experience for both advanced use cases, and users who simply want navigation.

## Details
 - Project lead: [Anonoei](https://github.com/Anonoei)
 - Language: C++17
 - License: GPLv3

----
## Current status/roadmap:
 - [ ] Initial Release
 - **Mobile Support** *(not implemented)*
   - [ ] Initial Release
 - [**Web Support**](https://astrolabe.daav.us) *(not implemented)*
   - [ ] Initial Release
 - **Desktop Support** *(not implemented)*
   - [ ] Initial Release
 - [ ] Initial maps/navigation API
 - [ ] GUI/rendering implementation
 - [ ] Initial multi-platform structure

----
### Features
 - Usable online/offline
 - Advanced features
   1. Navigation (driving, walking, public transport, etc.)
   2. Hikinh trails
   3. Cell towers
   4. Radio towers
   5. Airplanes and routes
   6. Weather radar and temperatures
 - Cross-platform
   1. Desktop (Windows, Linux, Mac)
   2. Web (astrolabe.daav.us)
   3. Mobile (iOS/Android)

## Installation
Currently there are no releases, so you must download and compile from source

## Compile from source
 1. Download
    - [Download directly](https://github.com/daavofficial/Astrolabe/archive/refs/heads/main.zip) from GitHub, or
    - Run `git clone https://github.com/daavofficial/Astrolabe.git`
 2. Unzip and/or open the downloaded folder
 3. Open `Scripts` folder and double click [Win-Setup.bat](https://github.com/daavofficial/Astrolabe/blob/main/Scripts/Win-Launch.bat)
    1. This checks your python version
    2. Installs required python packages
    3. Checks git submodules for updates
    4. Downloads/runs premake
 4. Double click `Astrolabe.sln`.

### How does it work?
Instead of relying on servers that may get shut down in the future, out application takes careof all the data and formatting. This has a slight performance overhead, but means instead of relying on us, our app relies on the servers of huge companies and organizations that won't disappear any time soon. This aso improves development time by eliminating the need to maintain a server.
#### Services we use: (subject to change)
 - [National Weather Service API](https://www.weather.gov/documentation/services-web-api)

## Problems
 - While this application remains free to use, we are limited by our API calls to the services we use.
 - API Costs
   - Google Maps: $200 free usage every month (Static Maps $2 per 1,000; Directions $5 per 1,000; Place details $17 per 1,000)
   - Yelp: 5,000 free calls daily

## License
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>