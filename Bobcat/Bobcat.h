// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2023-2025, İsmail Yılmaz

#ifndef _Bobcat_Bobcat_h
#define _Bobcat_Bobcat_h

#ifdef flagWEBGUI
#include <Turtle/Turtle.h>
#elif  flagSDLGUI
#include <VirtualGui/SDL2GL/SDL2GL.h>
#endif

#include <plugin/pcre/Pcre.h> // WebGui Windows compilation fix: This has to be above the other include files.

#include <MessageCtrl/MessageCtrl.h>
#include <StackCtrl/StackCtrl.h>
#include <Terminal/Terminal.h>
#include <PtyProcess/PtyProcess.h>

#ifdef PLATFORM_POSIX
#include <poll.h>
template <>
inline constexpr bool Upp::is_upp_guest<pollfd> = true;
#endif

namespace Upp {

#define TOPICFILE <Bobcat/docs.tpp/all.i>
#include <Core/topic_group.h>

#define KEYGROUPNAME "General"
#define KEYNAMESPACE AppKeys
#define KEYFILE <Bobcat/Application.key>
#include <CtrlLib/key_header.h>

#define IMAGEFILE <Bobcat/Bobcat.iml>
#define IMAGECLASS Images
#include <Draw/iml_header.h>

// Forward declaration
struct Bobcat;
struct Terminal;
struct Profile;

// Global context
Ptr<Bobcat> GetContext();
void SetContext(Bobcat& ctx);

#include "Palette.h"

#define LAYOUTFILE <Bobcat/Bobcat.lay>
#include <CtrlCore/lay.h>

#include "QuickText.h"
#include "Linkifier.h"
#include "Finder.h"
#include "Navigator.h"
#include "Profile.h"
#include "Terminal.h"

struct Bobcat : Pte<Bobcat> {
    Bobcat();

    bool        AddTerminal(const String& key = Null);
    bool        AddTerminal(const Profile& profile);
    bool        NewTerminalFromActiveProfile();
    void        RemoveTerminal(Terminal& t);
    void        ActivateTerminal();
    Terminal*   GetActiveTerminal();
    String      GetActiveProfile();

    Vector<Terminal*> GetTerminalGroup(hash_t id);
    Vector<Terminal*> GetTerminalGroup(const Profile& p);
    
    void        Run(const Profile& profile, Size size, bool fullscreen = false);
    
    void        Close();
    void        Settings();

    Bobcat&     Maximize(bool b = true);
    bool        IsMaximized() const;
    Bobcat&     Minimize(bool b = true);
    bool        IsMinimized() const;

    Bobcat&     FullScreen(int mode);
    Bobcat&     ToggleFullScreen();
    Bobcat&     NoFullScreen();
    bool        IsFullScreen() const;

    Bobcat&     Resize(Size sz);
    Bobcat&     SetPageSize(Size sz);
    Bobcat&     SetRect(Rect r);

    Bobcat&     ShowMenuBar(bool b = true);
    Bobcat&     HideMenuBar();
    bool        HasMenuBar() const;
    
    Bobcat&     ToggleBars();
    Bobcat&     ToggleNavigator();

    void        Sync();
    void        SyncTitle();
    void        SyncBackground();
    void        SyncTerminalProfiles();
    
    void        MainMenu(Bar& menu);
    void        FileMenu(Bar& menu);
    void        EditMenu(Bar& menu);
    void        ViewMenu(Bar& menu);
    void        SetupMenu(Bar& menu);
    void        HelpMenu(Bar& menu);
    void        TermMenu(Bar& menu);
    void        TermSubmenu(Bar& menu, const Vector<String>& list);
    void        ListMenu(Bar& menu);
    void        SizeMenu(Bar& menu);
    
    void        ScreenShot();
    void        About();
    void        Help();

    void        Wait(int timeout);
    void        ProcessEvents();
    
    struct  Config {
        Config();
        String      guitheme;
        Font        guifont;
        String      defaultprofile;
        String      titlealignment;
        String      notificationalignment;
        bool        notificationanimation;
        String      finderalignment;
        String      stackdirection;
        int         stackanimation;
        bool        stackwheel;
        bool        savescreenshot;
        bool        custominputmethod;
        String      custompagesizes;
        bool        showmenu;
        bool        showtitle;
        bool        frameless;
        bool        serializeplacement;
        bool        backgroundimage;
        String      backgroundimagepath;
        String      backgroundimagemode;
        int         backgroundimageblur;
        void        Jsonize(JsonIO& jio);
    };
    
    struct ViewCtrl : ParentCtrl {
        ViewCtrl();
        void        SetData(const Value& v) final;
        Value       GetData() const final;
        void        Paint(Draw& w) final;
        Value       data;
        String      mode;
    };
    
    TopWindow  window;
    MenuBar    menubar;
    Navigator  navigator;
    ViewCtrl   view;
    StackCtrl  stack;
    Config     settings;
    Array<Terminal> terminals;
};

FileSel& BobcatFs();

void LoadConfig(Bobcat& ctx);
void SaveConfig(Bobcat& ctx);

String GetDefaultShell();
String GetBuildInfo();

const Display& StdBackgroundDisplay();
const Display& NormalImageDisplay();
const Display& TiledImageDisplay();

void LoadGuiTheme(Bobcat& ctx);
void LoadGuiFont(Bobcat& ctx);
Vector<Tuple<void (*)(), String, String>> GetAllGuiThemes();

MessageCtrl& GetNotificationDaemon();

void AskYesNo(Ctrl& c, const String& text, const String& yes, const String& no,
                            MessageBox::Type type, const Event<int>& action);

}
#endif
