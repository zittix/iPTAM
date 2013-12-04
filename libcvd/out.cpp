# 1 "test.cpp"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 163 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "test.cpp" 2
# 1 "/usr/local/include/X11/Xlib.h" 1
# 31 "/usr/local/include/X11/Xlib.h"
# 1 "/usr/local/include/X11/X.h" 1
# 46 "/usr/local/include/X11/X.h"
typedef unsigned long XID;


typedef XID Window;
typedef XID Drawable;
typedef XID Font;
typedef XID Pixmap;
typedef XID Cursor;
typedef XID Colormap;
typedef XID GContext;
typedef XID KeySym;

typedef unsigned long Mask;

typedef unsigned long Atom;

typedef unsigned long VisualID;

typedef unsigned long Time;

typedef unsigned long KeyCode;
# 32 "/usr/local/include/X11/Xlib.h" 2








# 1 "/usr/local/include/X11/Xfuncproto.h" 1
# 41 "/usr/local/include/X11/Xlib.h" 2








# 1 "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../lib/clang/5.0/include/stddef.h" 1 3 4
# 34 "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../lib/clang/5.0/include/stddef.h" 3 4
typedef int ptrdiff_t;







typedef long unsigned int size_t;
# 50 "/usr/local/include/X11/Xlib.h" 2





typedef char *XPointer;






typedef int Status;
# 128 "/usr/local/include/X11/Xlib.h"
typedef struct _XExtData {
 int number;
 struct _XExtData *next;
 int (*free_private)();
 XPointer private_data;
} XExtData;




typedef struct {
 int extension;
 int major_opcode;
 int first_event;
 int first_error;
} XExtCodes;





typedef struct {
    int depth;
    int bits_per_pixel;
    int scanline_pad;
} XPixmapFormatValues;





typedef struct {
 int function;
 unsigned long plane_mask;
 unsigned long foreground;
 unsigned long background;
 int line_width;
 int line_style;
 int cap_style;

 int join_style;
 int fill_style;

 int fill_rule;
 int arc_mode;
 Pixmap tile;
 Pixmap stipple;
 int ts_x_origin;
 int ts_y_origin;
        Font font;
 int subwindow_mode;
 int graphics_exposures;
 int clip_x_origin;
 int clip_y_origin;
 Pixmap clip_mask;
 int dash_offset;
 char dashes;
} XGCValues;






typedef XGCValues *GC;




typedef struct {
 XExtData *ext_data;
 VisualID visualid;

 int c_class;



 unsigned long red_mask, green_mask, blue_mask;
 int bits_per_rgb;
 int map_entries;
} Visual;




typedef struct {
 int depth;
 int nvisuals;
 Visual *visuals;
} Depth;






typedef struct {
 XExtData *ext_data;
 struct _XDisplay *display;
 Window root;
 int width, height;
 int mwidth, mheight;
 int ndepths;
 Depth *depths;
 int root_depth;
 Visual *root_visual;
 GC default_gc;
 Colormap cmap;
 unsigned long white_pixel;
 unsigned long black_pixel;
 int max_maps, min_maps;
 int backing_store;
 int save_unders;
 long root_input_mask;
} Screen;




typedef struct {
 XExtData *ext_data;
 int depth;
 int bits_per_pixel;
 int scanline_pad;
} ScreenFormat;




typedef struct {
    Pixmap background_pixmap;
    unsigned long background_pixel;
    Pixmap border_pixmap;
    unsigned long border_pixel;
    int bit_gravity;
    int win_gravity;
    int backing_store;
    unsigned long backing_planes;
    unsigned long backing_pixel;
    int save_under;
    long event_mask;
    long do_not_propagate_mask;
    int override_redirect;
    Colormap colormap;
    Cursor cursor;
} XSetWindowAttributes;

typedef struct {
    int x, y;
    int width, height;
    int border_width;
    int depth;
    Visual *visual;
    Window root;

    int c_class;



    int bit_gravity;
    int win_gravity;
    int backing_store;
    unsigned long backing_planes;
    unsigned long backing_pixel;
    int save_under;
    Colormap colormap;
    int map_installed;
    int map_state;
    long all_event_masks;
    long your_event_mask;
    long do_not_propagate_mask;
    int override_redirect;
    Screen *screen;
} XWindowAttributes;






typedef struct {
 int family;
 int length;
 char *address;
} XHostAddress;




typedef struct _XImage {
    int width, height;
    int xoffset;
    int format;
    char *data;
    int byte_order;
    int bitmap_unit;
    int bitmap_bit_order;
    int bitmap_pad;
    int depth;
    int bytes_per_line;
    int bits_per_pixel;
    unsigned long red_mask;
    unsigned long green_mask;
    unsigned long blue_mask;
    XPointer obdata;
    struct funcs {
 struct _XImage *(*create_image)();

 int (*destroy_image) (struct _XImage *);
 unsigned long (*get_pixel) (struct _XImage *, int, int);
 int (*put_pixel) (struct _XImage *, int, int, unsigned long);
 struct _XImage *(*sub_image)(struct _XImage *, int, int, unsigned int, unsigned int);
 int (*add_pixel) (struct _XImage *, long);







 } f;
} XImage;




typedef struct {
    int x, y;
    int width, height;
    int border_width;
    Window sibling;
    int stack_mode;
} XWindowChanges;




typedef struct {
 unsigned long pixel;
 unsigned short red, green, blue;
 char flags;
 char pad;
} XColor;






typedef struct {
    short x1, y1, x2, y2;
} XSegment;

typedef struct {
    short x, y;
} XPoint;

typedef struct {
    short x, y;
    unsigned short width, height;
} XRectangle;

typedef struct {
    short x, y;
    unsigned short width, height;
    short angle1, angle2;
} XArc;




typedef struct {
        int key_click_percent;
        int bell_percent;
        int bell_pitch;
        int bell_duration;
        int led;
        int led_mode;
        int key;
        int auto_repeat_mode;
} XKeyboardControl;



typedef struct {
        int key_click_percent;
 int bell_percent;
 unsigned int bell_pitch, bell_duration;
 unsigned long led_mask;
 int global_auto_repeat;
 char auto_repeats[32];
} XKeyboardState;



typedef struct {
        Time time;
 short x, y;
} XTimeCoord;



typedef struct {
  int max_keypermod;
  KeyCode *modifiermap;
} XModifierKeymap;







typedef struct _XDisplay {
 XExtData *ext_data;
 struct _XFreeFuncs *free_funcs;
 int fd;
 int conn_checker;
 int proto_major_version;
 int proto_minor_version;
 char *vendor;
        XID resource_base;
 XID resource_mask;
 XID resource_id;
 int resource_shift;
 XID (*resource_alloc)();
 int byte_order;
 int bitmap_unit;
 int bitmap_pad;
 int bitmap_bit_order;
 int nformats;
 ScreenFormat *pixmap_format;
 int vnumber;
 int release;
 struct _XSQEvent *head, *tail;
 int qlen;
 unsigned long request;
 char *last_req;
 char *buffer;
 char *bufptr;
 char *bufmax;
 unsigned max_request_size;
 struct _XrmHashBucketRec *db;
 int (*synchandler)();
 char *display_name;
 int default_screen;
 int nscreens;
 Screen *screens;
 unsigned long motion_buffer;
 unsigned long flags;
 int min_keycode;
 int max_keycode;
 KeySym *keysyms;
 XModifierKeymap *modifiermap;
 int keysyms_per_keycode;
 char *xdefaults;
 char *scratch_buffer;
 unsigned long scratch_length;
 int ext_number;
 struct _XExten *ext_procs;
# 496 "/usr/local/include/X11/Xlib.h"
 int (*event_vec[128])();
 Status (*wire_vec[128])();
 KeySym lock_meaning;
 struct _XLockInfo *lock;
 struct _XInternalAsync *async_handlers;
 unsigned long bigreq_size;
 struct _XLockPtrs *lock_fns;

 struct _XKeytrans *key_bindings;
 Font cursor_font;
 struct _XDisplayAtoms *atoms;
 unsigned int mode_switch;
 struct _XContextDB *context_db;
 int (**error_vec)();



 struct {
    XPointer defaultCCCs;
    XPointer clientCmaps;
    XPointer perVisualIntensityMaps;

 } cms;
 struct _XIMFilter *im_filters;
 struct _XSQEvent *qfree;
 unsigned long next_event_serial_num;
 int (*savedsynchandler)();
} Display;
# 535 "/usr/local/include/X11/Xlib.h"
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Window root;
 Window subwindow;
 Time time;
 int x, y;
 int x_root, y_root;
 unsigned int state;
 unsigned int keycode;
 int same_screen;
        char trans_chars[4];

 int nbytes;
} XKeyEvent;
typedef XKeyEvent XKeyPressedEvent;
typedef XKeyEvent XKeyReleasedEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Window root;
 Window subwindow;
 Time time;
 int x, y;
 int x_root, y_root;
 unsigned int state;
 unsigned int button;
 int same_screen;
} XButtonEvent;
typedef XButtonEvent XButtonPressedEvent;
typedef XButtonEvent XButtonReleasedEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Window root;
 Window subwindow;
 Time time;
 int x, y;
 int x_root, y_root;
 unsigned int state;
 char is_hint;
 int same_screen;
} XMotionEvent;
typedef XMotionEvent XPointerMovedEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Window root;
 Window subwindow;
 Time time;
 int x, y;
 int x_root, y_root;
 int mode;
 int detail;




 int same_screen;
 int focus;
 unsigned int state;
} XCrossingEvent;
typedef XCrossingEvent XEnterWindowEvent;
typedef XCrossingEvent XLeaveWindowEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 int mode;
 int detail;





} XFocusChangeEvent;
typedef XFocusChangeEvent XFocusInEvent;
typedef XFocusChangeEvent XFocusOutEvent;


typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 char key_vector[32];
} XKeymapEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 int x, y;
 int width, height;
 int count;
} XExposeEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Drawable drawable;
 int x, y;
 int width, height;
 int count;
 int major_code;
 int minor_code;
} XGraphicsExposeEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Drawable drawable;
 int major_code;
 int minor_code;
} XNoExposeEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 int state;
} XVisibilityEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window parent;
 Window window;
 int x, y;
 int width, height;
 int border_width;
 int override_redirect;
} XCreateWindowEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
} XDestroyWindowEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 int from_configure;
} XUnmapEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 int override_redirect;
} XMapEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window parent;
 Window window;
} XMapRequestEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 Window parent;
 int x, y;
 int override_redirect;
} XReparentEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 int x, y;
 int width, height;
 int border_width;
 Window above;
 int override_redirect;
} XConfigureEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 int x, y;
} XGravityEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 int width, height;
} XResizeRequestEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window parent;
 Window window;
 int x, y;
 int width, height;
 int border_width;
 Window above;
 int detail;
 unsigned long value_mask;
} XConfigureRequestEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 int place;
} XCirculateEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window parent;
 Window window;
 int place;
} XCirculateRequestEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Atom atom;
 Time time;
 int state;
} XPropertyEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Atom selection;
 Time time;
} XSelectionClearEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window owner;
 Window requestor;
 Atom selection;
 Atom target;
 Atom property;
 Time time;
} XSelectionRequestEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window requestor;
 Atom selection;
 Atom target;
 Atom property;
 Time time;
} XSelectionEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Colormap colormap;

 int c_new;



 int state;
} XColormapEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Atom message_type;
 int format;
 union {
  char b[20];
  short s[10];
  long l[5];
  } data;
} XClientMessageEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 int request;

 int first_keycode;
 int count;
} XMappingEvent;

typedef struct {
 int type;
 Display *display;
 XID resourceid;
 unsigned long serial;
 unsigned char error_code;
 unsigned char request_code;
 unsigned char minor_code;
} XErrorEvent;

typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
} XAnyEvent;





typedef union _XEvent {
        int type;
 XAnyEvent xany;
 XKeyEvent xkey;
 XButtonEvent xbutton;
 XMotionEvent xmotion;
 XCrossingEvent xcrossing;
 XFocusChangeEvent xfocus;
 XExposeEvent xexpose;
 XGraphicsExposeEvent xgraphicsexpose;
 XNoExposeEvent xnoexpose;
 XVisibilityEvent xvisibility;
 XCreateWindowEvent xcreatewindow;
 XDestroyWindowEvent xdestroywindow;
 XUnmapEvent xunmap;
 XMapEvent xmap;
 XMapRequestEvent xmaprequest;
 XReparentEvent xreparent;
 XConfigureEvent xconfigure;
 XGravityEvent xgravity;
 XResizeRequestEvent xresizerequest;
 XConfigureRequestEvent xconfigurerequest;
 XCirculateEvent xcirculate;
 XCirculateRequestEvent xcirculaterequest;
 XPropertyEvent xproperty;
 XSelectionClearEvent xselectionclear;
 XSelectionRequestEvent xselectionrequest;
 XSelectionEvent xselection;
 XColormapEvent xcolormap;
 XClientMessageEvent xclient;
 XMappingEvent xmapping;
 XErrorEvent xerror;
 XKeymapEvent xkeymap;
 long pad[24];
} XEvent;







typedef struct {
    short lbearing;
    short rbearing;
    short width;
    short ascent;
    short descent;
    unsigned short attributes;
} XCharStruct;





typedef struct {
    Atom name;
    unsigned long card32;
} XFontProp;

typedef struct {
    XExtData *ext_data;
    Font fid;
    unsigned direction;
    unsigned min_char_or_byte2;
    unsigned max_char_or_byte2;
    unsigned min_byte1;
    unsigned max_byte1;
    int all_chars_exist;
    unsigned default_char;
    int n_properties;
    XFontProp *properties;
    XCharStruct min_bounds;
    XCharStruct max_bounds;
    XCharStruct *per_char;
    int ascent;
    int descent;
} XFontStruct;




typedef struct {
    char *chars;
    int nchars;
    int delta;
    Font font;
} XTextItem;

typedef struct {
    unsigned char byte1;
    unsigned char byte2;
} XChar2b;

typedef struct {
    XChar2b *chars;
    int nchars;
    int delta;
    Font font;
} XTextItem16;


typedef union { Display *display;
  GC gc;
  Visual *visual;
  Screen *screen;
  ScreenFormat *pixmap_format;
  XFontStruct *font; } XEDataObject;

typedef struct {
    XRectangle max_ink_extent;
    XRectangle max_logical_extent;
} XFontSetExtents;

typedef struct _XFontSet *XFontSet;

typedef struct {
    char *chars;
    int nchars;
    int delta;
    XFontSet font_set;
} XmbTextItem;

typedef struct {
    wchar_t *chars;
    int nchars;
    int delta;
    XFontSet font_set;
} XwcTextItem;

typedef void (*XIMProc)();

typedef struct _XIM *XIM;
typedef struct _XIC *XIC;

typedef unsigned long XIMStyle;

typedef struct {
    unsigned short count_styles;
    XIMStyle *supported_styles;
} XIMStyles;
# 1114 "/usr/local/include/X11/Xlib.h"
typedef void *XVaNestedList;




typedef struct {
    XPointer client_data;
    XIMProc callback;
} XIMCallback;

typedef unsigned long XIMFeedback;
# 1133 "/usr/local/include/X11/Xlib.h"
typedef struct _XIMText {
    unsigned short length;
    XIMFeedback *feedback;
    int encoding_is_wchar;
    union {
 char *multi_byte;
 wchar_t *wide_char;
    } string;
} XIMText;

typedef struct _XIMPreeditDrawCallbackStruct {
    int caret;
    int chg_first;
    int chg_length;
    XIMText *text;
} XIMPreeditDrawCallbackStruct;

typedef enum {
    XIMForwardChar, XIMBackwardChar,
    XIMForwardWord, XIMBackwardWord,
    XIMCaretUp, XIMCaretDown,
    XIMNextLine, XIMPreviousLine,
    XIMLineStart, XIMLineEnd,
    XIMAbsolutePosition,
    XIMDontChange
} XIMCaretDirection;

typedef enum {
    XIMIsInvisible,
    XIMIsPrimary,
    XIMIsSecondary
} XIMCaretStyle;

typedef struct _XIMPreeditCaretCallbackStruct {
    int position;
    XIMCaretDirection direction;
    XIMCaretStyle style;
} XIMPreeditCaretCallbackStruct;

typedef enum {
    XIMTextType,
    XIMBitmapType
} XIMStatusDataType;

typedef struct _XIMStatusDrawCallbackStruct {
    XIMStatusDataType type;
    union {
 XIMText *text;
 Pixmap bitmap;
    } data;
} XIMStatusDrawCallbackStruct;

typedef int (*XErrorHandler) (

    Display* ,
    XErrorEvent*

);

extern "C" {




# 1 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/usr/include/tkIntXlibDecls.h" 1 3 4
# 18 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/usr/include/tkIntXlibDecls.h" 3 4
# 1 "/usr/local/include/X11/Xutil.h" 1 3 4
# 53 "/usr/local/include/X11/Xutil.h" 3 4
typedef struct {
     long flags;
 int x, y;
 int width, height;
 int min_width, min_height;
 int max_width, max_height;
     int width_inc, height_inc;
 struct {
  int x;
  int y;
 } min_aspect, max_aspect;
 int base_width, base_height;
 int win_gravity;
} XSizeHints;
# 91 "/usr/local/include/X11/Xutil.h" 3 4
typedef struct {
 long flags;
 int input;

 int initial_state;
 Pixmap icon_pixmap;
 Window icon_window;
 int icon_x, icon_y;
 Pixmap icon_mask;
 XID window_group;

} XWMHints;
# 134 "/usr/local/include/X11/Xutil.h" 3 4
typedef struct {
    unsigned char *value;
    Atom encoding;
    int format;
    unsigned long nitems;
} XTextProperty;





typedef enum {
    XStringStyle,
    XCompoundTextStyle,
    XTextStyle,
    XStdICCTextStyle
} XICCEncodingStyle;

typedef struct {
 int min_width, min_height;
 int max_width, max_height;
 int width_inc, height_inc;
} XIconSize;

typedef struct {
 char *res_name;
 char *res_class;
} XClassHint;
# 181 "/usr/local/include/X11/Xutil.h" 3 4
typedef struct _XComposeStatus {
    XPointer compose_ptr;
    int chars_matched;
} XComposeStatus;
# 211 "/usr/local/include/X11/Xutil.h" 3 4
typedef struct _XRegion *Region;
# 225 "/usr/local/include/X11/Xutil.h" 3 4
typedef struct {
  Visual *visual;
  VisualID visualid;
  int screen;
  int depth;

  int c_class;



  unsigned long red_mask;
  unsigned long green_mask;
  unsigned long blue_mask;
  int colormap_size;
  int bits_per_rgb;
} XVisualInfo;
# 258 "/usr/local/include/X11/Xutil.h" 3 4
typedef struct {
 Colormap colormap;
 unsigned long red_max;
 unsigned long red_mult;
 unsigned long green_max;
 unsigned long green_mult;
 unsigned long blue_max;
 unsigned long blue_mult;
 unsigned long base_pixel;
 VisualID visualid;
 XID killid;
} XStandardColormap;
# 295 "/usr/local/include/X11/Xutil.h" 3 4
typedef int XContext;




extern "C" {



extern XClassHint *XAllocClassHint (

    void

);

extern XIconSize *XAllocIconSize (

    void

);

extern XSizeHints *XAllocSizeHints (

    void

);

extern XStandardColormap *XAllocStandardColormap (

    void

);

extern XWMHints *XAllocWMHints (

    void

);

extern void XClipBox(

    Region ,
    XRectangle*

);

extern Region XCreateRegion(

    void

);

extern char *XDefaultString(

    void

);

extern int XDeleteContext(

    Display* ,
    XID ,
    XContext

);

extern void XDestroyRegion(

    Region

);

extern void XEmptyRegion(

    Region

);

extern void XEqualRegion(

    Region ,
    Region

);

extern int XFindContext(

    Display* ,
    XID ,
    XContext ,
    XPointer*

);

extern Status XGetClassHint(

    Display* ,
    Window ,
    XClassHint*

);

extern Status XGetIconSizes(

    Display* ,
    Window ,
    XIconSize** ,
    int*

);

extern Status XGetNormalHints(

    Display* ,
    Window ,
    XSizeHints*

);

extern Status XGetRGBColormaps(

    Display* ,
    Window ,
    XStandardColormap** ,
    int* ,
    Atom

);

extern Status XGetSizeHints(

    Display* ,
    Window ,
    XSizeHints* ,
    Atom

);

extern Status XGetStandardColormap(

    Display* ,
    Window ,
    XStandardColormap* ,
    Atom

);

extern Status XGetTextProperty(

    Display* ,
    Window ,
    XTextProperty* ,
    Atom

);


extern Status XGetWMClientMachine(

    Display* ,
    Window ,
    XTextProperty*

);

extern XWMHints *XGetWMHints(

    Display* ,
    Window

);

extern Status XGetWMIconName(

    Display* ,
    Window ,
    XTextProperty*

);

extern Status XGetWMName(

    Display* ,
    Window ,
    XTextProperty*

);

extern Status XGetWMNormalHints(

    Display* ,
    Window ,
    XSizeHints* ,
    long*

);

extern Status XGetWMSizeHints(

    Display* ,
    Window ,
    XSizeHints* ,
    long* ,
    Atom

);

extern Status XGetZoomHints(

    Display* ,
    Window ,
    XSizeHints*

);

extern void XIntersectRegion(

    Region ,
    Region ,
    Region

);

extern int XLookupString(

    XKeyEvent* ,
    char* ,
    int ,
    KeySym* ,
    XComposeStatus*

);

extern Status XMatchVisualInfo(

    Display* ,
    int ,
    int ,
    int ,
    XVisualInfo*

);

extern void XOffsetRegion(

    Region ,
    int ,
    int

);

extern int XPointInRegion(

    Region ,
    int ,
    int

);

extern Region XPolygonRegion(

    XPoint* ,
    int ,
    int

);

extern int XRectInRegion(

    Region ,
    int ,
    int ,
    unsigned int ,
    unsigned int

);

extern int XSaveContext(

    Display* ,
    XID ,
    XContext ,
    const char*

);

extern void XSetClassHint(

    Display* ,
    Window ,
    XClassHint*

);

extern void XSetIconSizes(

    Display* ,
    Window ,
    XIconSize* ,
    int

);

extern void XSetNormalHints(

    Display* ,
    Window ,
    XSizeHints*

);

extern void XSetRGBColormaps(

    Display* ,
    Window ,
    XStandardColormap* ,
    int ,
    Atom

);

extern void XSetSizeHints(

    Display* ,
    Window ,
    XSizeHints* ,
    Atom

);

extern void XSetStandardProperties(

    Display* ,
    Window ,
    const char* ,
    const char* ,
    Pixmap ,
    char** ,
    int ,
    XSizeHints*

);

extern void XSetTextProperty(

    Display* ,
    Window ,
    XTextProperty* ,
    Atom

);

extern void XSetWMHints(

    Display* ,
    Window ,
    XWMHints*

);

extern void XSetWMIconName(

    Display* ,
    Window ,
    XTextProperty*

);

extern void XSetWMName(

    Display* ,
    Window ,
    XTextProperty*

);

extern void XSetWMNormalHints(

    Display* ,
    Window ,
    XSizeHints*

);

extern void XSetWMProperties(

    Display* ,
    Window ,
    XTextProperty* ,
    XTextProperty* ,
    char** ,
    int ,
    XSizeHints* ,
    XWMHints* ,
    XClassHint*

);

extern void XmbSetWMProperties(

    Display* ,
    Window ,
    const char* ,
    const char* ,
    char** ,
    int ,
    XSizeHints* ,
    XWMHints* ,
    XClassHint*

);

extern void XSetWMSizeHints(

    Display* ,
    Window ,
    XSizeHints* ,
    Atom

);

extern void XSetRegion(

    Display* ,
    GC ,
    Region

);

extern void XSetStandardColormap(

    Display* ,
    Window ,
    XStandardColormap* ,
    Atom

);

extern void XSetZoomHints(

    Display* ,
    Window ,
    XSizeHints*

);

extern void XShrinkRegion(

    Region ,
    int ,
    int

);

extern void XSubtractRegion(

    Region ,
    Region ,
    Region

);

extern int XmbTextListToTextProperty(

    Display* ,
    char** ,
    int ,
    XICCEncodingStyle ,
    XTextProperty*

);

extern int XwcTextListToTextProperty(

    Display* ,
    wchar_t** ,
    int ,
    XICCEncodingStyle ,
    XTextProperty*

);

extern void XwcFreeStringList(

    wchar_t**

);

extern Status XTextPropertyToStringList(

    XTextProperty* ,
    char*** ,
    int*

);

extern int XmbTextPropertyToTextList(

    Display* ,
    XTextProperty* ,
    char*** ,
    int*

);

extern int XwcTextPropertyToTextList(

    Display* ,
    XTextProperty* ,
    wchar_t*** ,
    int*

);

extern void XUnionRectWithRegion(

    XRectangle* ,
    Region ,
    Region

);

extern void XUnionRegion(

    Region ,
    Region ,
    Region

);

extern int XWMGeometry(

    Display* ,
    int ,
    const char* ,
    const char* ,
    unsigned int ,
    XSizeHints* ,
    int* ,
    int* ,
    int* ,
    int* ,
    int*

);

extern void XXorRegion(

    Region ,
    Region ,
    Region

);

}
# 19 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/usr/include/tkIntXlibDecls.h" 2 3 4
# 1194 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/usr/include/tkIntXlibDecls.h" 3 4
typedef struct TkIntXlibStubs {
    int magic;
    struct TkIntXlibStubHooks *hooks;
# 1401 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/usr/include/tkIntXlibDecls.h" 3 4
} TkIntXlibStubs;


extern "C" {

extern TkIntXlibStubs *tkIntXlibStubsPtr;

}
# 1197 "/usr/local/include/X11/Xlib.h" 2

}
# 2 "test.cpp" 2
 int main()
  {
   XOpenDisplay(__null);
  }
