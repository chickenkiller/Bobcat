// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2023-2024, İsmail Yılmaz

#ifndef _Bobcat_Terminal_h_
#define _Bobcat_Terminal_h_

struct Terminal : TerminalCtrl {
    typedef Terminal CLASSNAME;

    Terminal(Bobcat& ctx);

    void        PostParse() override;
    void        SetData(const Value& data) override;
    Value       GetData() const override;

    void        MouseEnter(Point pt, dword keyflags) override;
    void        MouseLeave() override;
    void        MouseMove(Point pt, dword keyflags) override;
    void        LeftDouble(Point pt, dword keyflags) override;
    Image       CursorImage(Point pt, dword keyflags) override;
    
    bool        StartPty(const Profile& profile);
    bool        Start(const String& profile_name);
    bool        Start(const Profile& profile);
    void        Stop();
    int         Do();
    void        Restart();
    void        Reset();
    
    bool        ShouldExit(bool failed) const;
    bool        ShouldRestart(bool failed) const;
    
    hash_t      GetHashValue() const;
    
    void        Update();
    Terminal&   Sync();
    void        SyncHighlight();
    
    void        Layout() override;
    
    Terminal&   SetProfile(const Profile& p);
    Terminal&   SetPalette(const Palette& p);
    Terminal&   SetExitMode(const String& s);
    Terminal&   SetLocale(const String& s);
    Terminal&   SetEraseKey(const String& s);
    Terminal&   SetCursorStyle(const String& s);
    Terminal&   SetFontZoom(int n);
    Terminal&   SetLineSpacing(int n);
    Terminal&   SetWordSelectionFilter(const String& s);
    
    void        MakeTitle(const String& txt);
    String      GetTitle() const;

    void        ShowTitleBar(bool b);
    void        HideTitleBar();
    bool        HasTitleBar() const;
    
    void        ShowFinder(bool b);
    void        HideFinder();
    bool        HasFinder() const;
    
    bool        IsEditable();
    
    void        CopyImage();
    void        OpenImage();

    String      GetLink();
    void        CopyLink();
    void        OpenLink();
    void        OnLink(const String& s);
    
    void        Hyperlinks(bool b);
    bool        HasHyperlinks() const;
    bool        HasLinkifier() const;
    bool        IsMouseOverExplicitHyperlink();
    bool        IsMouseOverImplicitHyperlink();
    bool        IsMouseOverLink();
    
    int         GetPosAsIndex(Point pt);
    int         GetMousePosAsIndex();
    
    void        OnHighlight(VectorMap<int, VTLine>& hl);
    
    void        EmulationMenu(Bar& menu);
    void        FileMenu(Bar& menu);
    void        EditMenu(Bar& menu);
    void        ViewMenu(Bar& menu);
    void        ContextMenu(Bar& menu);
    
    int         GetExitCode()                   { return pty.GetExitCode();     }
    String      GetExitMessage()                { return pty.GetExitMessage();  }
 
    enum class ExitMode {
        Keep,
        Restart,
        RestartFailed,
        Exit
    };

    Bobcat&      ctx;
    PtyProcess   pty;
    bool         bell:1;
    bool         filter:1;
    ExitMode     exitmode;
    String       profilename;
    Value        data;
    Finder       finder;
    Linkifier    linkifier;
    Color        highlight[4];
    TimeCallback timer;
    
    struct TitleBar : FrameTB<Ctrl> {
        TitleBar(Terminal& ctx);
        void        SetData(const Value& v) override;
        Value       GetData() const override;
        void        FrameLayout(Rect& r) override;
 
        void        Show();
        void        Hide();

        Terminal&   ctx;
        ToolButton  close;
        ToolButton  menu;
        ToolButton  newterm;
        StaticText  title;
        Value       data;
    }  titlebar;
};

// Global functions
Terminal& AsTerminal(Ctrl& c);
void      InsertUnicodeCodePoint(Terminal& term);

// Operators

inline bool operator==(const Terminal& p, const Terminal& q)  { return p.GetHashValue() == q.GetHashValue(); }
inline bool operator==(const Terminal& t, const Profile& p)   { return t.GetHashValue() == p.GetHashValue(); }
inline bool operator==(const Profile& p, const Terminal& t)   { return t == p; }
inline bool operator==(const Terminal& t,hash_t id)           { return t.GetHashValue() == id; }
inline bool operator==(hash_t id, const Terminal& t)          { return t == id; }

#endif
