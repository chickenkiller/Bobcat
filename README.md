

![bobcat-icon](resources/bobcat-icon.png)

![Fast Make Status](https://github.com/ismail-yilmaz/Bobcat/actions/workflows/fast-make.yml/badge.svg)
![Linux Build Status](https://github.com/ismail-yilmaz/Bobcat/actions/workflows/linux-make.yml/badge.svg)
![MacOS Build Status](https://github.com/ismail-yilmaz/Bobcat/actions/workflows/macos-make.yml/badge.svg)
![Windows Build Status](https://github.com/ismail-yilmaz/Bobcat/actions/workflows/windows-make.yml/badge.svg)
[![License](https://img.shields.io/badge/License-GPL_3-orange.svg)](https://opensource.org/licenses/GPL-3)


# Bobcat - Terminal Emulator

Bobcat is a modern, feature-rich terminal emulator that works across all major operating systems. It's built using the [U++](https://www.ultimatepp.org/index.html) framework and [TerminalCtrl](https://github.com/ismail-yilmaz/Terminal) widget to create a powerful yet user-friendly command-line experience.

## Table of Contents

1. [Features](#features)
2. [Requirements](#requirements)
3. [Installation](#installation)
4. [ToDo](#todo)
5. [Screenshots](#screenshots)
6. [Videos](#videos)
7. [Acknowledgements](#acknowledgements)
8. [License](#license)

## Features

*For complete VT feature details, see TerminalCtrl's [features](https://github.com/ismail-yilmaz/Terminal#features) list and technical specs [document](https://github.com/ismail-yilmaz/Terminal/blob/master/Terminal/Specs.md).*

### Core Capabilities

 - Runs smoothly on Linux, Windows, MacOS, and BSD systems
 - Very high compatibility with VT (DEC/ANSI) and xterm standards
 - Displays images right in your terminal: Supports both classic Sixel and modern formats (PNG, JPG, BMP, TIFF)
 - Smart shell integration that tracks your working directory
 - Powerful text selection and manipulation tools

### Modern Terminal Features

- Clickable hyperlinks and advanced clipboard handling
- Support for emojis and rich text annotations
- Full mouse support across all protocols
- Customizable keyboard shortcuts
- Vibrant color support (16, 256, and 24-bit colors)

### Smart Tools

- **Finder**: Advanced search engine with regular expression support and data extraction to CSV
- **Linkifier**: Turn any text into clickable links using custom patterns
- **Smart Text Selection**: Define your own selection patterns
- **QuickText**: Easy access to frequently used commands and text

### Customization & Interface

- Create multiple profiles for different tasks
- Choose between minimal and full-featured interfaces
- Stack-based design with easy terminal management
- Simple JSON configuration with immediate settings updates

### Windows-Specific Features

- Supports both ConPty and WinPty
- No external environment dependencies required

### Experimental Features

- Web support: Access your terminal through any modern browser
- Headless UI: Run on minimal systems using SDL2-GL

And yes, it can run Doom! 🎮


## Requirements

Bobcat has minimal requirements. You'll need:

- CLANG/GCC (C++17 or later)
- [U++](https://www.ultimatepp.org) framework
- [TerminalCtrl](https://github.com/ismail-yilmaz/Terminal)
- [StackCtrl](https://github.com/ismail-yilmaz/StackCtrl)
- [MessageCtrl](https://github.com/ismail-yilmaz/MessageCtrl)

## Installation

You can install Bobcat in three ways:

### 1. Via UppHub (Recommended)

- Available through [UppHub](https://www.ultimatepp.org/app$ide$UppHub_en-us.html), U++'s package manager
- Requires TheIDE (U++'s development environment)
   - Windows: Included in U++ installer
   - Linux: Available via [Flathub](https://flathub.org/apps/org.ultimatepp.TheIDE) or manual build

### 2. Using Make (Linux)

- Uses pre-compiled umk (U++ make) for faster builds:

	1. `make download`
	2. `make build` or `make build-web` or `make build-headless`
	3. `make run`

### 3. Manual Setup

- Clone or download the repository and set up as a U++ assembly/nest. See the U++ [documentation](https://www.ultimatepp.org/app$ide$PackagesAssembliesAndNests$en-us.html) for details.

## [ToDo](#todo)

- Macro infrastructure, based on Upp::Esc scripting language.
- A "lite" plugin framework.

## [Screenshots](#Screenshots)

Below you can find a handful of screenshots of Bobcat, running on Linux & Windows.

Bobcat on Linux 

![bobcat-linux](resources/bobcat-about-linux.png)

Bobcat on Windows

![bobcat-windows](resources/bobcat-about-windows.png)

Bobcat, running zellij, with a background image of well..., a bobcat!

![bobcat-zellij](resources/bobcat-zellij-background-linux.png)

Bobcat, running yazi, in borderless mode on Linux.

![bobcat-yazi](resources/bobcat-yazi-borderless-linux.png)

Bobcat, running yazi with image preview feature on Windows
![bobcat-yazi2](resources/bobcat-yazi-imagepreview-windows.png)

Bobcat, running Neovim on Windows
![bobcat-nvim](resources/bobcat-neovim-windows.png)

Multiple terminal profile support (linux, btop)

![bobcat-profiles](resources/bobcat-profiles-linux.png)

Inline images support (linux, jexer)

![bobcat-sixel](resources/bobcat-jexer-sixel-linux.png)

Navigator (linux)

![bobcat-navigator](resources/bobcat-navigator-linux.png)

Finder, in regex-based search mode (linux)
![bobcat-finder](resources/bobcat-finder-linux.png)

Harvester, harvesting 124660 URLs from the buffer, and mapping them into a csv file (linux)
![bobcat-finder-harvester](resources/bobcat-finder-harvester-linux.png)

Settings windows (linux)

![bobcat-settings](resources/bobcat-settings-linux.png)

Far manager running on Bobcat (Windows 10)

![bobcat-far-manager](resources/bobcat-far-manager-windows.png)


Bobcat deployed as a simple web server with access from web browsers (Linux)

![bobcat-webgui1](resources/bobcat-webgui-linux.png)

Bobcat deployed as a simple web server with access from web browsers (Windows)

![bobcat-webgui2](resources/bobcat-webgui-windows.png)

Bobcat running "headless" on SDL2 (GL) backend (Linux)

![bobcat-headless](resources/bobcat-sdlgui-linux.png)


Doom, running on Bobcat, via [mochadoom](https://github.com/AutumnMeowMeow/mochadoom) (Linux)

![bobcat-mochadoom](resources/bobcat-mochadoom.jpg)

## [Videos](#Videos)

A very short [demonstration](https://vimeo.com/999236026) of Bobcat, running DOOM!

A very short [demonstration](https://vimeo.com/1003353669?share=copy) of finder/harvester and unicode character (emoji) input.

## [Acknowledgements](#Acknowledgements)

To be written...

## [License](#License)

Copyright (c) 2023-2025, İsmail Yılmaz

Bobcat is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Bobcat is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for details. You should have received a copy of the GNU General Public License along with Bobcat. If not, see [gnu licenses](http://www.gnu.org/licenses/)

