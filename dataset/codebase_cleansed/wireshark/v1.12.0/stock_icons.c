static int si_cmp(const stock_item_t * a, const stock_item_t * b) {
return strcmp(a->name, b->name);
}
void stock_icons_init(void) {
guint32 i;
#if !GTK_CHECK_VERSION(3, WS_GTK3_MINOR_STOCK_DEPRECATION_STARTS, 0)
GtkIconFactory * factory;
GtkIconSet *icon_set;
GtkIconSource *source16;
#endif
static const stock_pixbuf_t pixbufs[] = {
{ WIRESHARK_STOCK_ABOUT, wsicon_16_pb_data, wsicon_24_pb_data },
{ WIRESHARK_STOCK_CAPTURE_INTERFACES, capture_interfaces_16_pb_data, capture_interfaces_24_pb_data },
{ WIRESHARK_STOCK_CAPTURE_OPTIONS, capture_options_alt1_16_pb_data, capture_options_alt1_24_pb_data },
{ WIRESHARK_STOCK_CAPTURE_RESTART, capture_restart_16_pb_data, capture_restart_24_pb_data },
{ WIRESHARK_STOCK_CAPTURE_START, capture_start_16_pb_data, capture_start_24_pb_data },
{ WIRESHARK_STOCK_CAPTURE_STOP, capture_stop_16_pb_data, capture_stop_24_pb_data },
{ WIRESHARK_STOCK_SAVE, toolbar_wireshark_file_16_pb_data, toolbar_wireshark_file_24_pb_data},
{ WIRESHARK_STOCK_WIKI, gnome_emblem_web_16_pb_data, gnome_emblem_web_24_pb_data },
{ NULL, NULL, NULL }
};
static const stock_pixmap_t pixmaps[] = {
{ WIRESHARK_STOCK_CAPTURE_FILTER, capture_filter_24_xpm, 24},
{ WIRESHARK_STOCK_CAPTURE_FILTER_ENTRY, capture_filter_24_xpm, 24},
{ WIRESHARK_STOCK_CAPTURE_DETAILS, capture_details_24_xpm, 24},
#ifdef HAVE_GEOIP
{ WIRESHARK_STOCK_MAP, internet_24_xpm, 24},
#endif
{ WIRESHARK_STOCK_DISPLAY_FILTER, display_filter_24_xpm, 24},
{ WIRESHARK_STOCK_DISPLAY_FILTER_ENTRY, display_filter_24_xpm, 24},
{ WIRESHARK_STOCK_COLORIZE, colorize_24_xpm, 24},
{ WIRESHARK_STOCK_AUTOSCROLL, autoscroll_24_xpm, 24},
{ WIRESHARK_STOCK_RESIZE_COLUMNS, resize_columns_24_xpm, 24},
{ WIRESHARK_STOCK_TIME, time_24_xpm, 24},
{ WIRESHARK_STOCK_INTERNET, internet_24_xpm, 24},
{ WIRESHARK_STOCK_WEB_SUPPORT, web_support_24_xpm, 24},
{ WIRESHARK_STOCK_CONVERSATIONS, conversations_16_xpm, 16},
{ WIRESHARK_STOCK_ENDPOINTS, endpoints_16_xpm, 16},
{ WIRESHARK_STOCK_EXPERT_INFO, expert_info_16_xpm, 16},
{ WIRESHARK_STOCK_GRAPHS, graphs_16_xpm, 16},
{ WIRESHARK_STOCK_FLOW_GRAPH, flow_graph_16_xpm, 16},
{ WIRESHARK_STOCK_TELEPHONY, telephony_16_xpm, 16},
{ WIRESHARK_STOCK_DECODE_AS, decode_as_16_xpm, 16},
{ WIRESHARK_STOCK_CHECKBOX, checkbox_16_xpm, 16},
{ WIRESHARK_STOCK_FILE_SET_LIST, file_set_list_16_xpm, 16},
{ WIRESHARK_STOCK_FILE_SET_NEXT, file_set_next_16_xpm, 16},
{ WIRESHARK_STOCK_FILE_SET_PREVIOUS, file_set_previous_16_xpm, 16},
{ WIRESHARK_STOCK_FILTER_OUT_STREAM, display_filter_24_xpm, 24},
{ WIRESHARK_STOCK_ENABLE, checkbox_16_xpm, 16},
{ WIRESHARK_STOCK_COLOR1, icon_color_1_xpm, 24},
{ WIRESHARK_STOCK_COLOR2, icon_color_2_xpm, 24},
{ WIRESHARK_STOCK_COLOR3, icon_color_3_xpm, 24},
{ WIRESHARK_STOCK_COLOR4, icon_color_4_xpm, 24},
{ WIRESHARK_STOCK_COLOR5, icon_color_5_xpm, 24},
{ WIRESHARK_STOCK_COLOR6, icon_color_6_xpm, 24},
{ WIRESHARK_STOCK_COLOR7, icon_color_7_xpm, 24},
{ WIRESHARK_STOCK_COLOR8, icon_color_8_xpm, 24},
{ WIRESHARK_STOCK_COLOR9, icon_color_9_xpm, 24},
{ WIRESHARK_STOCK_COLOR0, icon_color_0_xpm, 24},
{ WIRESHARK_STOCK_DECODE, decode_24_xpm, 24},
{ WIRESHARK_STOCK_AUDIO_PLAYER, audio_player_24_xpm, 24},
{ WIRESHARK_STOCK_VOIP_FLOW, voip_flow_24_xpm, 24},
{ WIRESHARK_STOCK_TELEPHONE, telephone_16_xpm, 16},
{ WIRESHARK_STOCK_PREPARE_FILTER, display_filter_24_xpm, 24},
{ WIRESHARK_STOCK_ANALYZE, analyze_24_xpm, 24},
{ NULL, NULL, 0}
};
qsort(ws_stock_items, sizeof(ws_stock_items)/sizeof(ws_stock_items[0]),
sizeof(ws_stock_items[0]), (int (*)(const void *, const void *))si_cmp);
qsort(gtk_stock_items, sizeof(gtk_stock_items)/sizeof(gtk_stock_items[0]),
sizeof(gtk_stock_items[0]), (int (*)(const void *, const void *))si_cmp);
#if !GTK_CHECK_VERSION(3, WS_GTK3_MINOR_STOCK_DEPRECATION_STARTS, 0)
for (i = 0; i < (sizeof(ws_stock_items) / sizeof(ws_stock_items[0])) ; i++) {
GtkStockItem stock_item =
{(char *)ws_stock_items[i].name,
(char *)ws_stock_items[i].label,
(GdkModifierType)0, 0, NULL};
gtk_stock_add(&stock_item, 1);
}
factory = gtk_icon_factory_new();
gtk_icon_factory_add_default(factory);
#endif
for (i = 0; pixmaps[i].name != NULL; i++) {
GdkPixbuf * pixbuf = gdk_pixbuf_new_from_xpm_data((const char **) (pixmaps[i].xpm_data));
g_assert(pixbuf);
#if !GTK_CHECK_VERSION(3, WS_GTK3_MINOR_STOCK_DEPRECATION_STARTS, 0)
icon_set = gtk_icon_set_new_from_pixbuf (pixbuf);
gtk_icon_factory_add (factory, pixmaps[i].name, icon_set);
gtk_icon_set_unref (icon_set);
#endif
gtk_icon_theme_add_builtin_icon(pixmaps[i].name, pixmaps[i].size, pixbuf);
g_object_unref (G_OBJECT (pixbuf));
}
for (i = 0; pixbufs[i].name != NULL; i++) {
GdkPixbuf * pixbuf24 = gdk_pixbuf_new_from_inline(-1, pixbufs[i].pb_data24, FALSE, NULL);
g_assert(pixbuf24);
#if !GTK_CHECK_VERSION(3, WS_GTK3_MINOR_STOCK_DEPRECATION_STARTS, 0)
icon_set = gtk_icon_set_new_from_pixbuf(pixbuf24);
gtk_icon_factory_add (factory, pixbufs[i].name, icon_set);
gtk_icon_set_unref (icon_set);
#endif
gtk_icon_theme_add_builtin_icon(pixbufs[i].name, 24, pixbuf24);
if (pixbufs[i].pb_data16) {
GdkPixbuf * pixbuf16 = gdk_pixbuf_new_from_inline(-1, pixbufs[i].pb_data16, FALSE, NULL);
g_assert(pixbuf16);
#if !GTK_CHECK_VERSION(3, WS_GTK3_MINOR_STOCK_DEPRECATION_STARTS, 0)
source16 = gtk_icon_source_new();
gtk_icon_source_set_pixbuf(source16, pixbuf16);
gtk_icon_source_set_size_wildcarded(source16, FALSE);
gtk_icon_source_set_size(source16, GTK_ICON_SIZE_MENU);
source16 = gtk_icon_source_new();
gtk_icon_source_set_pixbuf(source16, pixbuf16);
gtk_icon_source_set_size_wildcarded(source16, FALSE);
gtk_icon_source_set_size(source16, GTK_ICON_SIZE_SMALL_TOOLBAR);
#else
gtk_icon_theme_add_builtin_icon(pixbufs[i].name, 16, pixbuf16);
#endif
g_object_unref (G_OBJECT (pixbuf16));
}
g_object_unref (G_OBJECT (pixbuf24));
}
#if !GTK_CHECK_VERSION(3, WS_GTK3_MINOR_STOCK_DEPRECATION_STARTS, 0)
for (i = 0; i < (sizeof(ws_stock_items) / sizeof(ws_stock_items[0])) ; i++) {
stock_item_t * fallback_item = NULL;
if (NULL != (fallback_item = BS(ws_stock_items[i].icon, gtk_stock_items))) {
icon_set = gtk_icon_factory_lookup_default(fallback_item->name);
gtk_icon_factory_add(factory, ws_stock_items[i].name, icon_set);
}
}
#endif
}
GtkWidget * ws_gtk_button_new_from_stock(const gchar *stock_id) {
#if !GTK_CHECK_VERSION(3, WS_GTK3_MINOR_STOCK_DEPRECATION_STARTS, 0)
return gtk_button_new_from_stock(stock_id);
#else
GtkWidget * b;
stock_item_t * i = NULL;
if (NULL != (i = BS(stock_id, gtk_stock_items))) {
return gtk_button_new_with_mnemonic(i->label);
} else if (NULL != (i = BS(stock_id, ws_stock_items))) {
stock_item_t * fallback_item;
if (NULL != (fallback_item = BS(i->icon, gtk_stock_items))) {
b = gtk_button_new_from_icon_name(fallback_item->icon, GTK_ICON_SIZE_BUTTON);
} else {
b = gtk_button_new_from_icon_name(i->icon, GTK_ICON_SIZE_BUTTON);
}
gtk_button_set_label(GTK_BUTTON(b), i->label);
gtk_button_set_use_underline(GTK_BUTTON(b), TRUE);
return b;
}
return NULL;
#endif
}
GtkToolItem * ws_gtk_tool_button_new_from_stock(const gchar *stock_id) {
#if !GTK_CHECK_VERSION(3, WS_GTK3_MINOR_STOCK_DEPRECATION_STARTS, 0)
return gtk_tool_button_new_from_stock(stock_id);
#else
GtkToolItem * b = NULL;
stock_item_t * i = NULL;
if (NULL != (i = BS(stock_id, gtk_stock_items))) {
b = gtk_tool_button_new(NULL, i->label);
gtk_tool_button_set_use_underline(GTK_TOOL_BUTTON(b), TRUE);
gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON (b), i->icon);
} else if (NULL != (i = BS(stock_id, ws_stock_items))) {
stock_item_t * fallback_item;
if (NULL != (fallback_item = BS(i->icon, gtk_stock_items))) {
b = gtk_tool_button_new(NULL, i->label);
gtk_tool_button_set_use_underline(GTK_TOOL_BUTTON(b), TRUE);
gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(b), fallback_item->icon);
} else {
b = gtk_tool_button_new(NULL, i->label);
gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(b), i->icon);
}
}
return b;
#endif
}
GtkToolItem * ws_gtk_toggle_tool_button_new_from_stock(const gchar *stock_id) {
#if !GTK_CHECK_VERSION(3, WS_GTK3_MINOR_STOCK_DEPRECATION_STARTS, 0)
return gtk_toggle_tool_button_new_from_stock(stock_id);
#else
GtkToolItem * b = NULL;
stock_item_t * i = NULL;
if (NULL != (i = BS(stock_id, gtk_stock_items))) {
b = gtk_toggle_tool_button_new();
gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON (b), i->icon);
LBL_UNDERLINE(GTK_TOOL_BUTTON, b, i);
} else if (NULL != (i = BS(stock_id, ws_stock_items))) {
stock_item_t * fallback_item;
if (NULL != (fallback_item = BS(i->icon, gtk_stock_items))) {
b = gtk_toggle_tool_button_new();
gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON (b), fallback_item->icon);
LBL_UNDERLINE(GTK_TOOL_BUTTON, b, i);
} else {
b = gtk_toggle_tool_button_new();
gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON (b), i->icon);
LBL_UNDERLINE(GTK_TOOL_BUTTON, b, i);
}
}
return b;
#endif
}
GtkWidget * ws_gtk_image_new_from_stock(const gchar *stock_id, GtkIconSize size) {
#if !GTK_CHECK_VERSION(3, WS_GTK3_MINOR_STOCK_DEPRECATION_STARTS, 0)
return gtk_image_new_from_stock(stock_id, size);
#else
stock_item_t * i = NULL;
if (NULL != (i = BS(stock_id, gtk_stock_items))) {
return gtk_image_new_from_icon_name(i->icon, size);
} else if (NULL != (i = BS(stock_id, ws_stock_items))) {
stock_item_t * fallback_item;
if (NULL != (fallback_item = BS(i->icon, gtk_stock_items))) {
return gtk_image_new_from_icon_name(fallback_item->icon, size);
} else {
return gtk_image_new_from_icon_name(i->icon, size);
}
}
return NULL;
#endif
}
