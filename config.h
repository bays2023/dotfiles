/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 172;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=12" };
static const char dmenufont[]       = "monospace:size=12";
static const char col_gray1[]       = "#ddcc00";
//static const char col_gray1[]       = "#0077c8";
static const char col_gray2[]       = "#00c750";
//static const char col_gray2[]       = "#00c750";
static const char col_gray3[]       = "#FFFFFF";
//static const char col_gray3[]       = "#78c800";
static const char col_gray4[]       = "#000000";
//static const char col_gray4[]       = "#5000c8";
static const char col_cyan[]        = "#0077c8";
//static const char col_cyan[]        = "#FFFFFF";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	//[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_cyan, col_gray4, col_cyan  },
	[SchemeNorm] = { col_gray3, col_gray4, col_gray4 },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	 //WM_CLASS(STRING) = "galculator", "galculator";
	/* class      instance    title       tags mask     isfloating   monitor */
	{ NULL,	  NULL,	      "galculator", 	  0,	      True,	   -1 },
	{ NULL,	  NULL,	      "BQ Score",		  0,	      True,	   -1 },
	//{ NULL,	  NULL,	      "CanSat Ground Station", 	  0,	      True,	   -1 },
	//{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	//{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	//{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "TTT",      bstack },
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define ALTKEY Mod1Mask

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-b", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray4, "-nf", col_cyan, "-sb", col_cyan, "-sf", col_gray3, NULL };
//static const char *termcmd[]  = { "st", NULL };
static const char *termcmd[]  = { "alacritty", NULL };

static const char *altWebBrowser[] = { "librewolf", NULL };
static const char *altWebBrowserPrivate[] = { "librewolf", "--private-window", NULL };
static const char *altWebBrowser2[] = { "firefox", NULL };
static const char *altWebBrowserPrivate2[] = { "firefox", "--private-window", NULL };
static const char *bibleSelect[] = { "bible-select", NULL };
static const char *bluetooth[] = { "alacritty", "-e", "bluetoothctl", NULL };
static const char *calculator[] = { "galculator", NULL };
static const char *cmus[] = {"alacritty", "-e", "cmus", NULL };
static const char *cmusMenu[] = {"cmus-menu", NULL};
static const char *cmusQueue[] = {"cmus-queue", NULL};
static const char *cmusNext[] = { "cmus-next", NULL };
static const char *cmusPrev[] = { "cmus-prev", NULL };
static const char *cmusPause[] = { "cmus-pause", NULL };
static const char *cmusFwd[] = { "cmus-fwd", NULL };
static const char *cmusBkw[] = { "cmus-bkw", NULL };
static const char *ctrlAltDel[] = { "ctrl-alt-del-menu", NULL };
static const char *fileExplorer[] = { "pcmanfm", NULL };
static const char *killBar[] = { "pkill", "dwm-bar", NULL };
static const char *mailReader[] = { "alacritty", "-e", "mutt", NULL };
static const char *monExtend[] = { "xrandr", "--output", "DP-2", "--left-of", "eDP-1", NULL };
static const char *monMirror[] = { "xrandr", "--output", "DP-2", "--same-as", "eDP-1", NULL };
static const char *screenshot[] = { "xfce4-screenshooter", NULL };
static const char *screenshotFull[] = { "xfce4-screenshooter", "-f", NULL };
static const char *taskManager[] = { "alacritty", "-e", "htim", NULL };
static const char *taskManagerRoot[] = { "alacritty", "-e", "sudo", "htim", NULL };
static const char *volumeUp[] = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%", NULL };
static const char *volumeDown[] = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%", NULL };
static const char *volumeUpLow[] = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "+1%", NULL };
static const char *volumeDownLow[] = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "-1%", NULL };
static const char *volumeManager[] = { "alacritty", "-e", "pulsemixer", NULL };
static const char *webBrowser[] = { "brave-browser-beta", NULL };
static const char *webBrowserPrivate[] = { "brave-browser-beta", "--incognito", NULL };
static const char *xrandrMenu[] = { "xrandr-select", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,						XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,						XK_b,	   spawn,		   {.v = webBrowser} },
	{ MODKEY|ShiftMask,				XK_b,	   spawn,	       {.v = webBrowserPrivate} },
	{ MODKEY,						XK_n,	   spawn,		   {.v = altWebBrowser} },
	{ MODKEY|ShiftMask,				XK_n,	   spawn,	       {.v = altWebBrowserPrivate} },
	{ MODKEY,						XK_v,	   spawn,		   {.v = altWebBrowser2} },
	{ MODKEY|ShiftMask,				XK_v,	   spawn,	       {.v = altWebBrowserPrivate2} },
	{ ALTKEY,						XK_b,	   spawn,		   {.v = bluetooth} },
	{ MODKEY|ShiftMask,				XK_k,	   spawn,	       {.v = bibleSelect} },
	{ MODKEY,						XK_c,	   spawn,	       {.v = calculator} },
	{ MODKEY,						XK_p,	   spawn,	       {.v = screenshot} },
	{ MODKEY|ShiftMask,				XK_p,	   spawn,	       {.v = screenshotFull} },
	{ MODKEY,						XK_e,	   spawn,	       {.v = fileExplorer} },
	{ MODKEY,						XK_x,	   spawn,	       {.v = mailReader} },
	{ MODKEY,						XK_s,	   spawn,	       {.v = monExtend} },
	{ MODKEY|ShiftMask,				XK_s,	   spawn,	       {.v = monMirror} },
	{ MODKEY,						XK_u,	   spawn,	       {.v = taskManager} },
	{ MODKEY|ShiftMask,				XK_u,	   spawn,	       {.v = taskManagerRoot} },
	{ MODKEY,						XK_m,	   spawn,	       {.v = cmus} },
	{ MODKEY|ShiftMask,				XK_m,	   spawn,	       {.v = volumeManager} },
	{ ALTKEY,						XK_m,	   spawn,	       {.v = xrandrMenu} },
	{ MODKEY,						XK_o,	   spawn,	       {.v = volumeUp} },
	{ MODKEY|ShiftMask,				XK_o,	   spawn,    	   {.v = volumeUpLow} },
	{ MODKEY,						XK_i,	   spawn,	       {.v = volumeDown} },
	{ MODKEY|ShiftMask,				XK_i,	   spawn,	       {.v = volumeDownLow} },
	{ ALTKEY|MODKEY,				XK_m,	   spawn,	       {.v = cmusMenu} },
	{ ALTKEY|MODKEY,				XK_n,	   spawn,	       {.v = cmusQueue} },
	{ ALTKEY|MODKEY,				XK_b,	   spawn,	       {.v = cmusNext} },
	{ ALTKEY|MODKEY,				XK_z,	   spawn,	       {.v = cmusPrev} },
	{ ALTKEY|MODKEY,				XK_c,	   spawn,	       {.v = cmusPause} },
	{ ALTKEY|MODKEY,				XK_l,	   spawn,	       {.v = cmusFwd} },
	{ ALTKEY|MODKEY,				XK_h,	   spawn,	       {.v = cmusBkw} },
	{ ALTKEY|ControlMask,			XK_Delete, spawn,		   {.v = ctrlAltDel} },
	{ MODKEY|ShiftMask,             XK_f,      togglebar,      {0} },
	{ MODKEY,                       XK_Right,  focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Left,   focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_period, incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_comma,  incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ ALTKEY,                       XK_Tab,    focusstack,     {.i = +1 } },
	{ ALTKEY|ShiftMask,             XK_Tab,    focusstack,     {.i = -1 } },
	{ MODKEY,						XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,						XK_w,	   nextlayout,	  {0} },
	{ MODKEY|ShiftMask,				XK_w,	   prevlayout,	  {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,          {0} },
	{ ALTKEY|ShiftMask,				XK_q,	   spawn,	       {.v = killBar} },
	{ MODKEY|ShiftMask,				XK_Left,  zoom,		  {0} },
	{ MODKEY|ShiftMask,				XK_Right, zoom,		  {1} },
	//{ MODKEY,                       XK_Return, zoom,           {0} },
	//{ MODKEY,                       XK_Tab,    view,           {0} },
	//{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	//{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	//{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_Tab,  focusmon,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Tab, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

