/*******************************************************************************
* Copyright (c) 2000, 2004 IBM Corporation and others. All rights reserved.
* The contents of this file are made available under the terms
* of the GNU Lesser General Public License (LGPL) Version 2.1 that
* accompanies this distribution (lgpl-v21.txt).  The LGPL is also
* available at http://www.gnu.org/licenses/lgpl.html.  If the version
* of the LGPL at http://www.gnu.org is different to the version of
* the LGPL accompanying this distribution and there is any conflict
* between the two license versions, the terms of the LGPL accompanying
* this distribution shall govern.
* 
* Contributors:
*     IBM Corporation - initial API and implementation
*******************************************************************************/

#include "swt.h"
#include "os_structs.h"

#ifdef NATIVE_STATS

int OS_nativeFunctionCount = 873;
int OS_nativeFunctionCallCount[873];
char * OS_nativeFunctionNames[] = {
	"GDK_1DISPLAY", 
	"GDK_1ROOT_1PARENT", 
	"GDK_1TYPE_1COLOR", 
	"GDK_1TYPE_1PIXBUF", 
	"GDK_1WINDOWING_1X11", 
	"GInterfaceInfo_1sizeof", 
	"GTK_1ACCEL_1LABEL_1GET_1ACCEL_1STRING", 
	"GTK_1ACCEL_1LABEL_1SET_1ACCEL_1STRING", 
	"GTK_1ENTRY_1IM_1CONTEXT", 
	"GTK_1IS_1BUTTON", 
	"GTK_1IS_1CELL_1RENDERER_1PIXBUF", 
	"GTK_1IS_1IMAGE_1MENU_1ITEM", 
	"GTK_1SCROLLED_1WINDOW_1HSCROLLBAR", 
	"GTK_1SCROLLED_1WINDOW_1SCROLLBAR_1SPACING", 
	"GTK_1SCROLLED_1WINDOW_1VSCROLLBAR", 
	"GTK_1TEXTVIEW_1IM_1CONTEXT", 
	"GTK_1TYPE_1FIXED", 
	"GTK_1WIDGET_1FLAGS", 
	"GTK_1WIDGET_1HAS_1DEFAULT", 
	"GTK_1WIDGET_1HAS_1FOCUS", 
	"GTK_1WIDGET_1HEIGHT", 
	"GTK_1WIDGET_1IS_1SENSITIVE", 
	"GTK_1WIDGET_1MAPPED", 
	"GTK_1WIDGET_1SENSITIVE", 
	"GTK_1WIDGET_1SET_1FLAGS", 
	"GTK_1WIDGET_1UNSET_1FLAGS", 
	"GTK_1WIDGET_1VISIBLE", 
	"GTK_1WIDGET_1WIDTH", 
	"GTK_1WIDGET_1WINDOW", 
	"GTK_1WIDGET_1X", 
	"GTK_1WIDGET_1Y", 
	"GTypeInfo_1sizeof", 
	"GTypeQuery_1sizeof", 
	"G_1OBJECT_1CLASS", 
	"G_1OBJECT_1GET_1CLASS", 
	"G_1OBJECT_1TYPE", 
	"G_1TYPE_1BOOLEAN", 
	"G_1TYPE_1INT", 
	"G_1TYPE_1STRING", 
	"GdkColor_1sizeof", 
	"GdkDragContext_1sizeof", 
	"GdkEventButton_1sizeof", 
	"GdkEventCrossing_1sizeof", 
	"GdkEventExpose_1sizeof", 
	"GdkEventFocus_1sizeof", 
	"GdkEventKey_1sizeof", 
	"GdkEventMotion_1sizeof", 
	"GdkEventVisibility_1sizeof", 
	"GdkEventWindowState_1sizeof", 
	"GdkEvent_1sizeof", 
	"GdkGCValues_1sizeof", 
	"GdkGeometry_1sizeof", 
	"GdkImage_1sizeof", 
	"GdkRectangle_1sizeof", 
	"GdkVisual_1sizeof", 
	"GdkWindowAttr_1sizeof", 
	"GtkAdjustment_1sizeof", 
	"GtkAllocation_1sizeof", 
	"GtkColorSelectionDialog_1sizeof", 
	"GtkCombo_1sizeof", 
	"GtkFileSelection_1sizeof", 
	"GtkFixedClass_1sizeof", 
	"GtkFixed_1sizeof", 
	"GtkRequisition_1sizeof", 
	"GtkSelectionData_1sizeof", 
	"GtkTargetEntry_1sizeof", 
	"GtkTargetPair_1sizeof", 
	"GtkTextIter_1sizeof", 
	"GtkTreeIter_1sizeof", 
	"PANGO_1PIXELS", 
	"PANGO_1TYPE_1FONT_1DESCRIPTION", 
	"PTR_1sizeof", 
	"PangoAttribute_1sizeof", 
	"PangoItem_1sizeof", 
	"PangoLayoutLine_1sizeof", 
	"PangoLayoutRun_1sizeof", 
	"PangoLogAttr_1sizeof", 
	"PangoRectangle_1sizeof", 
	"XAnyEvent_1sizeof", 
	"XCheckIfEvent", 
	"XCheckMaskEvent", 
	"XCheckWindowEvent", 
	"XClientMessageEvent_1sizeof", 
	"XCrossingEvent_1sizeof", 
	"XDefaultRootWindow", 
	"XDefaultScreen", 
	"XEvent_1sizeof", 
	"XExposeEvent_1sizeof", 
	"XFocusChangeEvent_1sizeof", 
	"XGetSelectionOwner", 
	"XKeysymToKeycode", 
	"XQueryTree", 
	"XReconfigureWMWindow", 
	"XSendEvent", 
	"XSetInputFocus", 
	"XSynchronize", 
	"XTestFakeButtonEvent", 
	"XTestFakeKeyEvent", 
	"XTestFakeMotionEvent", 
	"XVisibilityEvent_1sizeof", 
	"XWarpPointer", 
	"XWindowChanges_1sizeof", 
	"g_1filename_1from_1uri", 
	"g_1filename_1from_1utf8", 
	"g_1filename_1to_1uri", 
	"g_1filename_1to_1utf8", 
	"g_1free", 
	"g_1list_1append", 
	"g_1list_1data", 
	"g_1list_1free", 
	"g_1list_1free_11", 
	"g_1list_1length", 
	"g_1list_1next", 
	"g_1list_1nth", 
	"g_1list_1nth_1data", 
	"g_1list_1prepend", 
	"g_1list_1previous", 
	"g_1list_1remove_1link", 
	"g_1list_1reverse", 
	"g_1list_1set_1next", 
	"g_1list_1set_1previous", 
	"g_1locale_1from_1utf8", 
	"g_1locale_1to_1utf8", 
	"g_1log_1default_1handler", 
	"g_1log_1remove_1handler", 
	"g_1log_1set_1handler", 
	"g_1malloc", 
	"g_1object_1get_1qdata", 
	"g_1object_1new", 
	"g_1object_1ref", 
	"g_1object_1set__I_3BFI", 
	"g_1object_1set__I_3BII", 
	"g_1object_1set__I_3BZI", 
	"g_1object_1set_1qdata", 
	"g_1object_1unref", 
	"g_1quark_1from_1string", 
	"g_1signal_1connect", 
	"g_1signal_1connect_1after", 
	"g_1signal_1emit_1by_1name__I_3B", 
	"g_1signal_1emit_1by_1name__I_3BI", 
	"g_1signal_1emit_1by_1name__I_3BII", 
	"g_1signal_1emit_1by_1name__I_3B_3B", 
	"g_1signal_1handler_1disconnect", 
	"g_1signal_1handlers_1block_1matched", 
	"g_1signal_1handlers_1disconnect_1matched", 
	"g_1signal_1handlers_1unblock_1matched", 
	"g_1signal_1lookup", 
	"g_1signal_1stop_1emission_1by_1name", 
	"g_1slist_1data", 
	"g_1slist_1next", 
	"g_1strfreev", 
	"g_1type_1add_1interface_1static", 
	"g_1type_1class_1peek", 
	"g_1type_1class_1peek_1parent", 
	"g_1type_1from_1name", 
	"g_1type_1interface_1peek_1parent", 
	"g_1type_1is_1a", 
	"g_1type_1name", 
	"g_1type_1parent", 
	"g_1type_1query", 
	"g_1type_1register_1static", 
	"g_1utf16_1to_1utf8", 
	"g_1utf8_1offset_1to_1pointer", 
	"g_1utf8_1pointer_1to_1offset", 
	"g_1utf8_1strlen", 
	"g_1utf8_1to_1utf16__II_3I_3I_3I", 
	"g_1utf8_1to_1utf16___3BI_3I_3I_3I", 
	"gdk_1atom_1intern", 
	"gdk_1atom_1name", 
	"gdk_1beep", 
	"gdk_1bitmap_1create_1from_1data", 
	"gdk_1color_1white", 
	"gdk_1colormap_1alloc_1color", 
	"gdk_1colormap_1free_1colors", 
	"gdk_1colormap_1get_1system", 
	"gdk_1colormap_1query_1color", 
	"gdk_1cursor_1destroy", 
	"gdk_1cursor_1new", 
	"gdk_1cursor_1new_1from_1pixmap", 
	"gdk_1drag_1status", 
	"gdk_1draw_1arc", 
	"gdk_1draw_1drawable", 
	"gdk_1draw_1layout", 
	"gdk_1draw_1layout_1with_1colors", 
	"gdk_1draw_1line", 
	"gdk_1draw_1lines", 
	"gdk_1draw_1point", 
	"gdk_1draw_1polygon", 
	"gdk_1draw_1rectangle", 
	"gdk_1drawable_1get_1image", 
	"gdk_1drawable_1get_1size", 
	"gdk_1drawable_1get_1visible_1region", 
	"gdk_1error_1trap_1pop", 
	"gdk_1error_1trap_1push", 
	"gdk_1event_1copy", 
	"gdk_1event_1free", 
	"gdk_1event_1get", 
	"gdk_1event_1get_1coords", 
	"gdk_1event_1get_1graphics_1expose", 
	"gdk_1event_1get_1root_1coords", 
	"gdk_1event_1get_1state", 
	"gdk_1event_1get_1time", 
	"gdk_1event_1handler_1set", 
	"gdk_1event_1put", 
	"gdk_1flush", 
	"gdk_1free_1text_1list", 
	"gdk_1gc_1get_1values", 
	"gdk_1gc_1new", 
	"gdk_1gc_1set_1background", 
	"gdk_1gc_1set_1clip_1mask", 
	"gdk_1gc_1set_1clip_1origin", 
	"gdk_1gc_1set_1clip_1rectangle", 
	"gdk_1gc_1set_1clip_1region", 
	"gdk_1gc_1set_1dashes", 
	"gdk_1gc_1set_1exposures", 
	"gdk_1gc_1set_1fill", 
	"gdk_1gc_1set_1foreground", 
	"gdk_1gc_1set_1function", 
	"gdk_1gc_1set_1line_1attributes", 
	"gdk_1gc_1set_1stipple", 
	"gdk_1gc_1set_1subwindow", 
	"gdk_1gc_1set_1values", 
	"gdk_1image_1get", 
	"gdk_1image_1get_1pixel", 
	"gdk_1keyboard_1ungrab", 
	"gdk_1keymap_1get_1default", 
	"gdk_1keymap_1translate_1keyboard_1state", 
	"gdk_1keyval_1to_1lower", 
	"gdk_1keyval_1to_1unicode", 
	"gdk_1pango_1context_1get", 
	"gdk_1pango_1context_1set_1colormap", 
	"gdk_1pango_1layout_1get_1clip_1region", 
	"gdk_1pixbuf_1get_1from_1drawable", 
	"gdk_1pixbuf_1get_1pixels", 
	"gdk_1pixbuf_1get_1rowstride", 
	"gdk_1pixbuf_1new", 
	"gdk_1pixbuf_1render_1pixmap_1and_1mask", 
	"gdk_1pixbuf_1render_1to_1drawable", 
	"gdk_1pixbuf_1render_1to_1drawable_1alpha", 
	"gdk_1pixbuf_1scale", 
	"gdk_1pixbuf_1scale_1simple", 
	"gdk_1pixmap_1new", 
	"gdk_1pointer_1grab", 
	"gdk_1pointer_1is_1grabbed", 
	"gdk_1pointer_1ungrab", 
	"gdk_1property_1get", 
	"gdk_1region_1destroy", 
	"gdk_1region_1empty", 
	"gdk_1region_1get_1clipbox", 
	"gdk_1region_1get_1rectangles", 
	"gdk_1region_1intersect", 
	"gdk_1region_1new", 
	"gdk_1region_1offset", 
	"gdk_1region_1point_1in", 
	"gdk_1region_1polygon", 
	"gdk_1region_1rect_1in", 
	"gdk_1region_1rectangle", 
	"gdk_1region_1subtract", 
	"gdk_1region_1union", 
	"gdk_1region_1union_1with_1rect", 
	"gdk_1rgb_1init", 
	"gdk_1screen_1get_1default", 
	"gdk_1screen_1get_1monitor_1at_1window", 
	"gdk_1screen_1get_1monitor_1geometry", 
	"gdk_1screen_1get_1n_1monitors", 
	"gdk_1screen_1get_1number", 
	"gdk_1screen_1height", 
	"gdk_1screen_1width", 
	"gdk_1screen_1width_1mm", 
	"gdk_1set_1program_1class", 
	"gdk_1text_1property_1to_1utf8_1list", 
	"gdk_1unicode_1to_1keyval", 
	"gdk_1utf8_1to_1compound_1text", 
	"gdk_1visual_1get_1system", 
	"gdk_1window_1add_1filter", 
	"gdk_1window_1at_1pointer", 
	"gdk_1window_1begin_1paint_1rect", 
	"gdk_1window_1destroy", 
	"gdk_1window_1end_1paint", 
	"gdk_1window_1focus", 
	"gdk_1window_1freeze_1updates", 
	"gdk_1window_1get_1children", 
	"gdk_1window_1get_1events", 
	"gdk_1window_1get_1frame_1extents", 
	"gdk_1window_1get_1origin", 
	"gdk_1window_1get_1parent", 
	"gdk_1window_1get_1pointer", 
	"gdk_1window_1get_1user_1data", 
	"gdk_1window_1hide", 
	"gdk_1window_1invalidate_1rect", 
	"gdk_1window_1invalidate_1region", 
	"gdk_1window_1lookup", 
	"gdk_1window_1lower", 
	"gdk_1window_1move", 
	"gdk_1window_1new", 
	"gdk_1window_1process_1all_1updates", 
	"gdk_1window_1process_1updates", 
	"gdk_1window_1raise", 
	"gdk_1window_1resize", 
	"gdk_1window_1scroll", 
	"gdk_1window_1set_1accept_1focus", 
	"gdk_1window_1set_1back_1pixmap", 
	"gdk_1window_1set_1cursor", 
	"gdk_1window_1set_1decorations", 
	"gdk_1window_1set_1events", 
	"gdk_1window_1set_1icon", 
	"gdk_1window_1set_1icon_1list", 
	"gdk_1window_1set_1keep_1above", 
	"gdk_1window_1set_1override_1redirect", 
	"gdk_1window_1set_1user_1data", 
	"gdk_1window_1shape_1combine_1region", 
	"gdk_1window_1show", 
	"gdk_1window_1show_1unraised", 
	"gdk_1window_1thaw_1updates", 
	"gdk_1x11_1atom_1to_1xatom", 
	"gdk_1x11_1drawable_1get_1xdisplay", 
	"gdk_1x11_1drawable_1get_1xid", 
	"gtk_1accel_1group_1new", 
	"gtk_1accel_1groups_1activate", 
	"gtk_1accel_1label_1set_1accel_1widget", 
	"gtk_1adjustment_1changed", 
	"gtk_1adjustment_1new", 
	"gtk_1adjustment_1set_1value", 
	"gtk_1adjustment_1value_1changed", 
	"gtk_1arrow_1new", 
	"gtk_1arrow_1set", 
	"gtk_1bin_1get_1child", 
	"gtk_1button_1new", 
	"gtk_1button_1set_1relief", 
	"gtk_1cell_1renderer_1get_1size", 
	"gtk_1cell_1renderer_1pixbuf_1new", 
	"gtk_1cell_1renderer_1text_1new", 
	"gtk_1cell_1renderer_1toggle_1new", 
	"gtk_1check_1button_1new", 
	"gtk_1check_1menu_1item_1get_1active", 
	"gtk_1check_1menu_1item_1new_1with_1label", 
	"gtk_1check_1menu_1item_1set_1active", 
	"gtk_1check_1version", 
	"gtk_1clipboard_1clear", 
	"gtk_1clipboard_1get", 
	"gtk_1clipboard_1set_1with_1data", 
	"gtk_1clipboard_1wait_1for_1contents", 
	"gtk_1color_1selection_1dialog_1new", 
	"gtk_1color_1selection_1get_1current_1color", 
	"gtk_1color_1selection_1set_1current_1color", 
	"gtk_1combo_1disable_1activate", 
	"gtk_1combo_1new", 
	"gtk_1combo_1set_1case_1sensitive", 
	"gtk_1combo_1set_1popdown_1strings", 
	"gtk_1container_1add", 
	"gtk_1container_1get_1border_1width", 
	"gtk_1container_1get_1children", 
	"gtk_1container_1remove", 
	"gtk_1container_1resize_1children", 
	"gtk_1container_1set_1border_1width", 
	"gtk_1dialog_1add_1button", 
	"gtk_1dialog_1run", 
	"gtk_1drag_1begin", 
	"gtk_1drag_1check_1threshold", 
	"gtk_1drag_1dest_1find_1target", 
	"gtk_1drag_1dest_1set", 
	"gtk_1drag_1dest_1unset", 
	"gtk_1drag_1finish", 
	"gtk_1drag_1get_1data", 
	"gtk_1drawing_1area_1new", 
	"gtk_1editable_1copy_1clipboard", 
	"gtk_1editable_1cut_1clipboard", 
	"gtk_1editable_1delete_1selection", 
	"gtk_1editable_1delete_1text", 
	"gtk_1editable_1get_1chars", 
	"gtk_1editable_1get_1editable", 
	"gtk_1editable_1get_1position", 
	"gtk_1editable_1get_1selection_1bounds", 
	"gtk_1editable_1insert_1text", 
	"gtk_1editable_1paste_1clipboard", 
	"gtk_1editable_1select_1region", 
	"gtk_1editable_1set_1editable", 
	"gtk_1editable_1set_1position", 
	"gtk_1entry_1get_1invisible_1char", 
	"gtk_1entry_1get_1layout", 
	"gtk_1entry_1get_1max_1length", 
	"gtk_1entry_1get_1text", 
	"gtk_1entry_1get_1visibility", 
	"gtk_1entry_1new", 
	"gtk_1entry_1set_1activates_1default", 
	"gtk_1entry_1set_1alignment", 
	"gtk_1entry_1set_1has_1frame", 
	"gtk_1entry_1set_1invisible_1char", 
	"gtk_1entry_1set_1max_1length", 
	"gtk_1entry_1set_1text", 
	"gtk_1entry_1set_1visibility", 
	"gtk_1events_1pending", 
	"gtk_1file_1selection_1complete", 
	"gtk_1file_1selection_1get_1filename", 
	"gtk_1file_1selection_1get_1selections", 
	"gtk_1file_1selection_1hide_1fileop_1buttons", 
	"gtk_1file_1selection_1new", 
	"gtk_1file_1selection_1set_1filename", 
	"gtk_1file_1selection_1set_1select_1multiple", 
	"gtk_1fixed_1move", 
	"gtk_1fixed_1new", 
	"gtk_1fixed_1set_1has_1window", 
	"gtk_1font_1selection_1dialog_1get_1font_1name", 
	"gtk_1font_1selection_1dialog_1new", 
	"gtk_1font_1selection_1dialog_1set_1font_1name", 
	"gtk_1frame_1get_1label_1widget", 
	"gtk_1frame_1new", 
	"gtk_1frame_1set_1label", 
	"gtk_1frame_1set_1label_1widget", 
	"gtk_1frame_1set_1shadow_1type", 
	"gtk_1get_1current_1event", 
	"gtk_1get_1current_1event_1state", 
	"gtk_1get_1current_1event_1time", 
	"gtk_1get_1default_1language", 
	"gtk_1get_1event_1widget", 
	"gtk_1grab_1add", 
	"gtk_1grab_1get_1current", 
	"gtk_1grab_1remove", 
	"gtk_1hbox_1new", 
	"gtk_1hscale_1new", 
	"gtk_1hscrollbar_1new", 
	"gtk_1hseparator_1new", 
	"gtk_1icon_1factory_1lookup_1default", 
	"gtk_1icon_1set_1render_1icon", 
	"gtk_1im_1context_1filter_1keypress", 
	"gtk_1im_1context_1focus_1in", 
	"gtk_1im_1context_1focus_1out", 
	"gtk_1im_1context_1get_1preedit_1string", 
	"gtk_1im_1context_1get_1type", 
	"gtk_1im_1context_1reset", 
	"gtk_1im_1context_1set_1client_1window", 
	"gtk_1im_1context_1set_1cursor_1location", 
	"gtk_1im_1multicontext_1append_1menuitems", 
	"gtk_1im_1multicontext_1new", 
	"gtk_1image_1menu_1item_1new_1with_1label", 
	"gtk_1image_1menu_1item_1set_1image", 
	"gtk_1image_1new", 
	"gtk_1image_1new_1from_1pixmap", 
	"gtk_1image_1set_1from_1pixmap", 
	"gtk_1init_1check", 
	"gtk_1label_1get_1mnemonic_1keyval", 
	"gtk_1label_1new", 
	"gtk_1label_1new_1with_1mnemonic", 
	"gtk_1label_1set_1attributes", 
	"gtk_1label_1set_1justify", 
	"gtk_1label_1set_1line_1wrap", 
	"gtk_1label_1set_1text", 
	"gtk_1label_1set_1text_1with_1mnemonic", 
	"gtk_1list_1store_1append", 
	"gtk_1list_1store_1clear", 
	"gtk_1list_1store_1insert", 
	"gtk_1list_1store_1newv", 
	"gtk_1list_1store_1remove", 
	"gtk_1list_1store_1set__IIIII", 
	"gtk_1list_1store_1set__IIIJI", 
	"gtk_1list_1store_1set__IIILorg_eclipse_swt_internal_gtk_GdkColor_2I", 
	"gtk_1list_1store_1set__IIIZI", 
	"gtk_1list_1store_1set__III_3BI", 
	"gtk_1main", 
	"gtk_1main_1do_1event", 
	"gtk_1main_1iteration", 
	"gtk_1major_1version", 
	"gtk_1menu_1bar_1new", 
	"gtk_1menu_1item_1remove_1submenu", 
	"gtk_1menu_1item_1set_1submenu", 
	"gtk_1menu_1new", 
	"gtk_1menu_1popdown", 
	"gtk_1menu_1popup", 
	"gtk_1menu_1shell_1deactivate", 
	"gtk_1menu_1shell_1insert", 
	"gtk_1menu_1shell_1select_1item", 
	"gtk_1message_1dialog_1new", 
	"gtk_1micro_1version", 
	"gtk_1minor_1version", 
	"gtk_1misc_1set_1alignment", 
	"gtk_1notebook_1get_1current_1page", 
	"gtk_1notebook_1get_1scrollable", 
	"gtk_1notebook_1insert_1page", 
	"gtk_1notebook_1new", 
	"gtk_1notebook_1remove_1page", 
	"gtk_1notebook_1set_1current_1page", 
	"gtk_1notebook_1set_1scrollable", 
	"gtk_1notebook_1set_1show_1tabs", 
	"gtk_1notebook_1set_1tab_1pos", 
	"gtk_1object_1sink", 
	"gtk_1paint_1handle", 
	"gtk_1plug_1get_1id", 
	"gtk_1plug_1new", 
	"gtk_1progress_1bar_1new", 
	"gtk_1progress_1bar_1pulse", 
	"gtk_1progress_1bar_1set_1fraction", 
	"gtk_1progress_1bar_1set_1orientation", 
	"gtk_1radio_1button_1get_1group", 
	"gtk_1radio_1button_1new", 
	"gtk_1radio_1menu_1item_1new_1with_1label", 
	"gtk_1range_1get_1adjustment", 
	"gtk_1range_1set_1increments", 
	"gtk_1range_1set_1range", 
	"gtk_1range_1set_1value", 
	"gtk_1rc_1parse_1string", 
	"gtk_1rc_1style_1get_1bg_1pixmap_1name", 
	"gtk_1rc_1style_1get_1color_1flags", 
	"gtk_1rc_1style_1set_1bg", 
	"gtk_1rc_1style_1set_1bg_1pixmap_1name", 
	"gtk_1rc_1style_1set_1color_1flags", 
	"gtk_1scale_1set_1digits", 
	"gtk_1scale_1set_1draw_1value", 
	"gtk_1scrolled_1window_1get_1hadjustment", 
	"gtk_1scrolled_1window_1get_1policy", 
	"gtk_1scrolled_1window_1get_1shadow_1type", 
	"gtk_1scrolled_1window_1get_1vadjustment", 
	"gtk_1scrolled_1window_1new", 
	"gtk_1scrolled_1window_1set_1placement", 
	"gtk_1scrolled_1window_1set_1policy", 
	"gtk_1scrolled_1window_1set_1shadow_1type", 
	"gtk_1selection_1data_1free", 
	"gtk_1selection_1data_1set", 
	"gtk_1separator_1menu_1item_1new", 
	"gtk_1set_1locale", 
	"gtk_1socket_1get_1id", 
	"gtk_1socket_1new", 
	"gtk_1style_1get_1base", 
	"gtk_1style_1get_1bg", 
	"gtk_1style_1get_1black", 
	"gtk_1style_1get_1dark", 
	"gtk_1style_1get_1fg", 
	"gtk_1style_1get_1font_1desc", 
	"gtk_1style_1get_1light", 
	"gtk_1style_1get_1text", 
	"gtk_1style_1get_1xthickness", 
	"gtk_1style_1get_1ythickness", 
	"gtk_1target_1list_1new", 
	"gtk_1target_1list_1unref", 
	"gtk_1text_1buffer_1copy_1clipboard", 
	"gtk_1text_1buffer_1cut_1clipboard", 
	"gtk_1text_1buffer_1delete", 
	"gtk_1text_1buffer_1get_1bounds", 
	"gtk_1text_1buffer_1get_1char_1count", 
	"gtk_1text_1buffer_1get_1end_1iter", 
	"gtk_1text_1buffer_1get_1insert", 
	"gtk_1text_1buffer_1get_1iter_1at_1line", 
	"gtk_1text_1buffer_1get_1iter_1at_1mark", 
	"gtk_1text_1buffer_1get_1iter_1at_1offset", 
	"gtk_1text_1buffer_1get_1line_1count", 
	"gtk_1text_1buffer_1get_1selection_1bound", 
	"gtk_1text_1buffer_1get_1selection_1bounds", 
	"gtk_1text_1buffer_1get_1text", 
	"gtk_1text_1buffer_1insert__II_3BI", 
	"gtk_1text_1buffer_1insert__I_3B_3BI", 
	"gtk_1text_1buffer_1move_1mark", 
	"gtk_1text_1buffer_1paste_1clipboard", 
	"gtk_1text_1buffer_1place_1cursor", 
	"gtk_1text_1buffer_1set_1text", 
	"gtk_1text_1iter_1get_1line", 
	"gtk_1text_1iter_1get_1offset", 
	"gtk_1text_1view_1buffer_1to_1window_1coords", 
	"gtk_1text_1view_1get_1buffer", 
	"gtk_1text_1view_1get_1editable", 
	"gtk_1text_1view_1get_1iter_1location", 
	"gtk_1text_1view_1get_1line_1at_1y", 
	"gtk_1text_1view_1get_1visible_1rect", 
	"gtk_1text_1view_1get_1window", 
	"gtk_1text_1view_1new", 
	"gtk_1text_1view_1scroll_1mark_1onscreen", 
	"gtk_1text_1view_1scroll_1to_1iter", 
	"gtk_1text_1view_1set_1editable", 
	"gtk_1text_1view_1set_1justification", 
	"gtk_1text_1view_1set_1tabs", 
	"gtk_1text_1view_1set_1wrap_1mode", 
	"gtk_1timeout_1add", 
	"gtk_1timeout_1remove", 
	"gtk_1toggle_1button_1get_1active", 
	"gtk_1toggle_1button_1new", 
	"gtk_1toggle_1button_1set_1active", 
	"gtk_1toggle_1button_1set_1mode", 
	"gtk_1toolbar_1insert_1widget", 
	"gtk_1toolbar_1new", 
	"gtk_1toolbar_1set_1orientation", 
	"gtk_1tooltips_1disable", 
	"gtk_1tooltips_1enable", 
	"gtk_1tooltips_1new", 
	"gtk_1tooltips_1set_1tip", 
	"gtk_1tree_1model_1get__III_3II", 
	"gtk_1tree_1model_1get__III_3JI", 
	"gtk_1tree_1model_1get_1iter", 
	"gtk_1tree_1model_1get_1iter_1first", 
	"gtk_1tree_1model_1get_1n_1columns", 
	"gtk_1tree_1model_1get_1path", 
	"gtk_1tree_1model_1get_1type", 
	"gtk_1tree_1model_1iter_1children", 
	"gtk_1tree_1model_1iter_1n_1children", 
	"gtk_1tree_1model_1iter_1next", 
	"gtk_1tree_1model_1iter_1nth_1child", 
	"gtk_1tree_1path_1append_1index", 
	"gtk_1tree_1path_1free", 
	"gtk_1tree_1path_1get_1depth", 
	"gtk_1tree_1path_1get_1indices", 
	"gtk_1tree_1path_1new", 
	"gtk_1tree_1path_1new_1first", 
	"gtk_1tree_1path_1new_1from_1string__I", 
	"gtk_1tree_1path_1new_1from_1string___3B", 
	"gtk_1tree_1path_1up", 
	"gtk_1tree_1selection_1get_1selected", 
	"gtk_1tree_1selection_1get_1selected_1rows", 
	"gtk_1tree_1selection_1path_1is_1selected", 
	"gtk_1tree_1selection_1select_1all", 
	"gtk_1tree_1selection_1select_1iter", 
	"gtk_1tree_1selection_1selected_1foreach", 
	"gtk_1tree_1selection_1set_1mode", 
	"gtk_1tree_1selection_1unselect_1all", 
	"gtk_1tree_1selection_1unselect_1iter", 
	"gtk_1tree_1store_1append", 
	"gtk_1tree_1store_1clear", 
	"gtk_1tree_1store_1insert", 
	"gtk_1tree_1store_1newv", 
	"gtk_1tree_1store_1remove", 
	"gtk_1tree_1store_1set__IIIII", 
	"gtk_1tree_1store_1set__IIIJI", 
	"gtk_1tree_1store_1set__IIILorg_eclipse_swt_internal_gtk_GdkColor_2I", 
	"gtk_1tree_1store_1set__IIIZI", 
	"gtk_1tree_1store_1set__III_3BI", 
	"gtk_1tree_1view_1collapse_1row", 
	"gtk_1tree_1view_1column_1add_1attribute", 
	"gtk_1tree_1view_1column_1cell_1get_1position", 
	"gtk_1tree_1view_1column_1cell_1get_1size", 
	"gtk_1tree_1view_1column_1cell_1set_1cell_1data", 
	"gtk_1tree_1view_1column_1clear", 
	"gtk_1tree_1view_1column_1get_1cell_1renderers", 
	"gtk_1tree_1view_1column_1get_1resizable", 
	"gtk_1tree_1view_1column_1get_1spacing", 
	"gtk_1tree_1view_1column_1get_1visible", 
	"gtk_1tree_1view_1column_1get_1width", 
	"gtk_1tree_1view_1column_1new", 
	"gtk_1tree_1view_1column_1pack_1end", 
	"gtk_1tree_1view_1column_1pack_1start", 
	"gtk_1tree_1view_1column_1set_1alignment", 
	"gtk_1tree_1view_1column_1set_1cell_1data_1func", 
	"gtk_1tree_1view_1column_1set_1clickable", 
	"gtk_1tree_1view_1column_1set_1fixed_1width", 
	"gtk_1tree_1view_1column_1set_1resizable", 
	"gtk_1tree_1view_1column_1set_1sizing", 
	"gtk_1tree_1view_1column_1set_1title", 
	"gtk_1tree_1view_1column_1set_1visible", 
	"gtk_1tree_1view_1column_1set_1widget", 
	"gtk_1tree_1view_1expand_1row", 
	"gtk_1tree_1view_1get_1bin_1window", 
	"gtk_1tree_1view_1get_1cell_1area", 
	"gtk_1tree_1view_1get_1column", 
	"gtk_1tree_1view_1get_1cursor", 
	"gtk_1tree_1view_1get_1expander_1column", 
	"gtk_1tree_1view_1get_1headers_1visible", 
	"gtk_1tree_1view_1get_1path_1at_1pos", 
	"gtk_1tree_1view_1get_1rules_1hint", 
	"gtk_1tree_1view_1get_1selection", 
	"gtk_1tree_1view_1get_1visible_1rect", 
	"gtk_1tree_1view_1insert_1column", 
	"gtk_1tree_1view_1new_1with_1model", 
	"gtk_1tree_1view_1remove_1column", 
	"gtk_1tree_1view_1row_1expanded", 
	"gtk_1tree_1view_1scroll_1to_1cell", 
	"gtk_1tree_1view_1scroll_1to_1point", 
	"gtk_1tree_1view_1set_1cursor", 
	"gtk_1tree_1view_1set_1drag_1dest_1row", 
	"gtk_1tree_1view_1set_1headers_1visible", 
	"gtk_1tree_1view_1set_1model", 
	"gtk_1tree_1view_1set_1rules_1hint", 
	"gtk_1tree_1view_1tree_1to_1widget_1coords", 
	"gtk_1tree_1view_1unset_1rows_1drag_1dest", 
	"gtk_1tree_1view_1widget_1to_1tree_1coords", 
	"gtk_1vbox_1new", 
	"gtk_1vscale_1new", 
	"gtk_1vscrollbar_1new", 
	"gtk_1vseparator_1new", 
	"gtk_1widget_1add_1accelerator", 
	"gtk_1widget_1add_1events", 
	"gtk_1widget_1child_1focus", 
	"gtk_1widget_1create_1pango_1layout__II", 
	"gtk_1widget_1create_1pango_1layout__I_3B", 
	"gtk_1widget_1destroy", 
	"gtk_1widget_1event", 
	"gtk_1widget_1get_1child_1visible", 
	"gtk_1widget_1get_1default_1direction", 
	"gtk_1widget_1get_1default_1style", 
	"gtk_1widget_1get_1direction", 
	"gtk_1widget_1get_1events", 
	"gtk_1widget_1get_1modifier_1style", 
	"gtk_1widget_1get_1pango_1context", 
	"gtk_1widget_1get_1parent", 
	"gtk_1widget_1get_1style", 
	"gtk_1widget_1get_1toplevel", 
	"gtk_1widget_1grab_1focus", 
	"gtk_1widget_1hide", 
	"gtk_1widget_1is_1focus", 
	"gtk_1widget_1map", 
	"gtk_1widget_1mnemonic_1activate", 
	"gtk_1widget_1modify_1base", 
	"gtk_1widget_1modify_1bg", 
	"gtk_1widget_1modify_1fg", 
	"gtk_1widget_1modify_1font", 
	"gtk_1widget_1modify_1style", 
	"gtk_1widget_1modify_1text", 
	"gtk_1widget_1realize", 
	"gtk_1widget_1remove_1accelerator", 
	"gtk_1widget_1reparent", 
	"gtk_1widget_1set_1default_1direction", 
	"gtk_1widget_1set_1direction", 
	"gtk_1widget_1set_1double_1buffered", 
	"gtk_1widget_1set_1name", 
	"gtk_1widget_1set_1redraw_1on_1allocate", 
	"gtk_1widget_1set_1sensitive", 
	"gtk_1widget_1set_1size_1request", 
	"gtk_1widget_1set_1state", 
	"gtk_1widget_1shape_1combine_1mask", 
	"gtk_1widget_1show", 
	"gtk_1widget_1show_1now", 
	"gtk_1widget_1size_1allocate", 
	"gtk_1widget_1size_1request", 
	"gtk_1widget_1style_1get", 
	"gtk_1widget_1unrealize", 
	"gtk_1window_1activate_1default", 
	"gtk_1window_1add_1accel_1group", 
	"gtk_1window_1deiconify", 
	"gtk_1window_1get_1focus", 
	"gtk_1window_1get_1mnemonic_1modifier", 
	"gtk_1window_1get_1position", 
	"gtk_1window_1get_1size", 
	"gtk_1window_1iconify", 
	"gtk_1window_1maximize", 
	"gtk_1window_1move", 
	"gtk_1window_1new", 
	"gtk_1window_1present", 
	"gtk_1window_1remove_1accel_1group", 
	"gtk_1window_1resize", 
	"gtk_1window_1set_1default", 
	"gtk_1window_1set_1destroy_1with_1parent", 
	"gtk_1window_1set_1geometry_1hints", 
	"gtk_1window_1set_1modal", 
	"gtk_1window_1set_1resizable", 
	"gtk_1window_1set_1title", 
	"gtk_1window_1set_1transient_1for", 
	"gtk_1window_1set_1type_1hint", 
	"gtk_1window_1unmaximize", 
	"memmove__ILorg_eclipse_swt_internal_gtk_GInterfaceInfo_2I", 
	"memmove__ILorg_eclipse_swt_internal_gtk_GObjectClass_2", 
	"memmove__ILorg_eclipse_swt_internal_gtk_GTypeInfo_2I", 
	"memmove__ILorg_eclipse_swt_internal_gtk_GdkEventButton_2I", 
	"memmove__ILorg_eclipse_swt_internal_gtk_GtkAdjustment_2", 
	"memmove__ILorg_eclipse_swt_internal_gtk_GtkFixed_2", 
	"memmove__ILorg_eclipse_swt_internal_gtk_GtkTargetEntry_2I", 
	"memmove__ILorg_eclipse_swt_internal_gtk_GtkWidgetClass_2", 
	"memmove__ILorg_eclipse_swt_internal_gtk_PangoAttribute_2I", 
	"memmove__ILorg_eclipse_swt_internal_gtk_XClientMessageEvent_2I", 
	"memmove__ILorg_eclipse_swt_internal_gtk_XCrossingEvent_2I", 
	"memmove__ILorg_eclipse_swt_internal_gtk_XExposeEvent_2I", 
	"memmove__ILorg_eclipse_swt_internal_gtk_XFocusChangeEvent_2I", 
	"memmove__I_3BI", 
	"memmove__I_3II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GObjectClass_2I", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GTypeQuery_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GdkColor_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GdkDragContext_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GdkEventButton_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GdkEventCrossing_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GdkEventExpose_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GdkEventFocus_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GdkEventKey_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GdkEventMotion_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GdkEventVisibility_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GdkEventWindowState_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GdkEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GdkImage_2I", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GdkRectangle_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GdkVisual_2I", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GtkAdjustment_2I", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GtkColorSelectionDialog_2I", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GtkCombo_2I", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GtkFileSelection_2I", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GtkFixed_2I", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GtkSelectionData_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GtkTargetPair_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_GtkWidgetClass_2I", 
	"memmove__Lorg_eclipse_swt_internal_gtk_PangoAttribute_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_PangoItem_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_PangoLayoutLine_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_PangoLayoutRun_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_PangoLogAttr_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_XCrossingEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_XExposeEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_XFocusChangeEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_gtk_XVisibilityEvent_2II", 
	"memmove___3BII", 
	"memmove___3CII", 
	"memmove___3III", 
	"memmove___3I_3BI", 
	"memmove___3JII", 
	"memset", 
	"pango_1attr_1background_1new", 
	"pango_1attr_1font_1desc_1new", 
	"pango_1attr_1foreground_1new", 
	"pango_1attr_1list_1change", 
	"pango_1attr_1list_1insert", 
	"pango_1attr_1list_1new", 
	"pango_1attr_1list_1unref", 
	"pango_1attr_1shape_1new", 
	"pango_1attr_1strikethrough_1new", 
	"pango_1attr_1underline_1new", 
	"pango_1attr_1weight_1new", 
	"pango_1context_1get_1base_1dir", 
	"pango_1context_1get_1language", 
	"pango_1context_1get_1metrics", 
	"pango_1context_1list_1families", 
	"pango_1context_1set_1base_1dir", 
	"pango_1context_1set_1language", 
	"pango_1font_1description_1copy", 
	"pango_1font_1description_1free", 
	"pango_1font_1description_1from_1string", 
	"pango_1font_1description_1get_1family", 
	"pango_1font_1description_1get_1size", 
	"pango_1font_1description_1get_1style", 
	"pango_1font_1description_1get_1weight", 
	"pango_1font_1description_1new", 
	"pango_1font_1description_1set_1family", 
	"pango_1font_1description_1set_1size", 
	"pango_1font_1description_1set_1stretch", 
	"pango_1font_1description_1set_1style", 
	"pango_1font_1description_1set_1weight", 
	"pango_1font_1description_1to_1string", 
	"pango_1font_1face_1describe", 
	"pango_1font_1family_1list_1faces", 
	"pango_1font_1get_1metrics", 
	"pango_1font_1metrics_1get_1approximate_1char_1width", 
	"pango_1font_1metrics_1get_1ascent", 
	"pango_1font_1metrics_1get_1descent", 
	"pango_1font_1metrics_1unref", 
	"pango_1language_1from_1string", 
	"pango_1layout_1context_1changed", 
	"pango_1layout_1get_1alignment", 
	"pango_1layout_1get_1attributes", 
	"pango_1layout_1get_1iter", 
	"pango_1layout_1get_1line", 
	"pango_1layout_1get_1line_1count", 
	"pango_1layout_1get_1log_1attrs", 
	"pango_1layout_1get_1size", 
	"pango_1layout_1get_1spacing", 
	"pango_1layout_1get_1tabs", 
	"pango_1layout_1get_1text", 
	"pango_1layout_1get_1width", 
	"pango_1layout_1index_1to_1pos", 
	"pango_1layout_1iter_1free", 
	"pango_1layout_1iter_1get_1index", 
	"pango_1layout_1iter_1get_1line_1extents", 
	"pango_1layout_1iter_1get_1run", 
	"pango_1layout_1iter_1next_1line", 
	"pango_1layout_1iter_1next_1run", 
	"pango_1layout_1line_1get_1extents", 
	"pango_1layout_1line_1x_1to_1index", 
	"pango_1layout_1new", 
	"pango_1layout_1set_1alignment", 
	"pango_1layout_1set_1attributes", 
	"pango_1layout_1set_1font_1description", 
	"pango_1layout_1set_1single_1paragraph_1mode", 
	"pango_1layout_1set_1spacing", 
	"pango_1layout_1set_1tabs", 
	"pango_1layout_1set_1text", 
	"pango_1layout_1set_1width", 
	"pango_1layout_1set_1wrap", 
	"pango_1layout_1xy_1to_1index", 
	"pango_1tab_1array_1free", 
	"pango_1tab_1array_1get_1size", 
	"pango_1tab_1array_1get_1tabs", 
	"pango_1tab_1array_1new", 
	"pango_1tab_1array_1set_1tab", 
	"strlen", 
};

#endif
