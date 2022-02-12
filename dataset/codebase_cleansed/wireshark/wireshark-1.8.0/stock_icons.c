void stock_icons_init(void) {
GtkIconFactory * factory;
gint32 i;
GdkPixbuf * pixbuf;
GtkIconSet *icon_set;
static const GtkStockItem stock_items[] = {
{ WIRESHARK_STOCK_CAPTURE_INTERFACES, "_Interfaces", 0, 0, NULL },
{ WIRESHARK_STOCK_CAPTURE_OPTIONS, "_Options", 0, 0, NULL },
{ WIRESHARK_STOCK_CAPTURE_START, "_Start", 0, 0, NULL },
{ WIRESHARK_STOCK_CAPTURE_STOP, "S_top", 0, 0, NULL },
{ WIRESHARK_STOCK_CAPTURE_RESTART, "_Restart", 0, 0, NULL },
{ WIRESHARK_STOCK_CAPTURE_FILTER, "_Capture Filter", 0, 0, NULL },
{ WIRESHARK_STOCK_CAPTURE_FILTER_ENTRY, "_Capture Filter:", 0, 0, NULL },
{ WIRESHARK_STOCK_CAPTURE_DETAILS, "_Details", 0, 0, NULL },
#ifdef HAVE_GEOIP
{ WIRESHARK_STOCK_MAP, "Map", 0, 0, NULL },
#endif
{ WIRESHARK_STOCK_FOLLOW_STREAM, "Follow Stream", 0, 0, NULL },
{ WIRESHARK_STOCK_DISPLAY_FILTER, "Display _Filter", 0, 0, NULL },
{ WIRESHARK_STOCK_DISPLAY_FILTER_ENTRY, "F_ilter:", 0, 0, NULL },
{ WIRESHARK_STOCK_BROWSE, "_Browse...", 0, 0, NULL },
{ WIRESHARK_STOCK_CREATE_STAT, "Create _Stat", 0, 0, NULL },
{ WIRESHARK_STOCK_EXPORT, "_Export...", 0, 0, NULL },
{ WIRESHARK_STOCK_IMPORT, "_Import...", 0, 0, NULL },
{ WIRESHARK_STOCK_EDIT, "_Edit...", 0, 0, NULL },
{ WIRESHARK_STOCK_ADD_EXPRESSION, "E_xpression..." , 0, 0, NULL },
{ WIRESHARK_STOCK_CLEAR_EXPRESSION, "Clea_r" , 0, 0, NULL },
{ WIRESHARK_STOCK_APPLY_EXPRESSION, "App_ly" , 0, 0, NULL },
{ WIRESHARK_STOCK_SAVE_ALL, "Save A_ll", 0, 0, NULL },
{ WIRESHARK_STOCK_DONT_SAVE, "Continue _without Saving", 0, 0, NULL },
{ WIRESHARK_STOCK_QUIT_DONT_SAVE, "Quit _without Saving", 0, 0, NULL },
{ WIRESHARK_STOCK_STOP_DONT_SAVE, "Stop and Continue _without Saving", 0, 0, NULL },
{ WIRESHARK_STOCK_STOP_QUIT_DONT_SAVE, "Stop and Quit _without Saving", 0, 0, NULL },
{ WIRESHARK_STOCK_STOP_SAVE, "Stop and Save", 0, 0, NULL },
{ WIRESHARK_STOCK_ABOUT, "_About", 0, 0, NULL },
{ WIRESHARK_STOCK_COLORIZE, "_Colorize", 0, 0, NULL },
{ WIRESHARK_STOCK_AUTOSCROLL, "_Auto Scroll", 0, 0, NULL },
{ WIRESHARK_STOCK_RESIZE_COLUMNS, "Resize Columns", 0, 0, NULL },
{ WIRESHARK_STOCK_TIME, "Time", 0, 0, NULL },
{ WIRESHARK_STOCK_INTERNET, "Internet", 0, 0, NULL },
{ WIRESHARK_STOCK_WEB_SUPPORT, "Web Support", 0, 0, NULL },
{ WIRESHARK_STOCK_WIKI, "Wiki", 0, 0, NULL },
{ WIRESHARK_STOCK_CONVERSATIONS, "Conversations", 0, 0, NULL },
{ WIRESHARK_STOCK_ENDPOINTS, "Endpoints", 0, 0, NULL },
{ WIRESHARK_STOCK_EXPERT_INFO, "Expert Info", 0, 0, NULL },
{ WIRESHARK_STOCK_GRAPHS, "Graphs", 0, 0, NULL },
{ WIRESHARK_STOCK_FLOW_GRAPH, "Flow Graph", 0, 0, NULL },
{ WIRESHARK_STOCK_TELEPHONY, "Telephony", 0, 0, NULL },
{ WIRESHARK_STOCK_DECODE_AS, "Decode As", 0, 0, NULL },
{ WIRESHARK_STOCK_CHECKBOX, "Checkbox", 0, 0, NULL },
{ WIRESHARK_STOCK_FILE_SET_LIST, "List Files", 0, 0, NULL },
{ WIRESHARK_STOCK_FILE_SET_NEXT, "Next File", 0, 0, NULL },
{ WIRESHARK_STOCK_FILE_SET_PREVIOUS, "Previous File", 0, 0, NULL },
{ WIRESHARK_STOCK_FILTER_OUT_STREAM, "Filter Out This Stream", 0, 0, NULL },
{ WIRESHARK_STOCK_ENABLE, "Enable", 0, 0, NULL },
{ WIRESHARK_STOCK_DISABLE, "Disable", 0, 0, NULL },
{ WIRESHARK_STOCK_COLOR1, "Color 1", 0, 0, NULL },
{ WIRESHARK_STOCK_COLOR2, "Color 2", 0, 0, NULL },
{ WIRESHARK_STOCK_COLOR3, "Color 3", 0, 0, NULL },
{ WIRESHARK_STOCK_COLOR4, "Color 4", 0, 0, NULL },
{ WIRESHARK_STOCK_COLOR5, "Color 5", 0, 0, NULL },
{ WIRESHARK_STOCK_COLOR6, "Color 6", 0, 0, NULL },
{ WIRESHARK_STOCK_COLOR7, "Color 7", 0, 0, NULL },
{ WIRESHARK_STOCK_COLOR8, "Color 8", 0, 0, NULL },
{ WIRESHARK_STOCK_COLOR9, "Color 9", 0, 0, NULL },
{ WIRESHARK_STOCK_COLOR0, "Color 10", 0, 0, NULL },
{ WIRESHARK_STOCK_DECODE, "Decode", 0, 0, NULL },
{ WIRESHARK_STOCK_AUDIO_PLAYER, "Player", 0, 0, NULL },
{ WIRESHARK_STOCK_VOIP_FLOW, "Flow", 0, 0, NULL },
{ WIRESHARK_STOCK_TELEPHONE, "Telephone", 0, 0, NULL },
{ WIRESHARK_STOCK_PREPARE_FILTER, "Prepare Filter", 0, 0, NULL },
{ WIRESHARK_STOCK_ANALYZE, "Analyze", 0, 0, NULL },
{ WIRESHARK_STOCK_FILE, "File", 0, 0, NULL }
};
static const stock_pixmap_t pixmaps[] = {
{ WIRESHARK_STOCK_CAPTURE_INTERFACES, capture_interfaces_24_xpm },
{ WIRESHARK_STOCK_CAPTURE_OPTIONS, capture_options_24_xpm },
{ WIRESHARK_STOCK_CAPTURE_START, capture_start_24_xpm },
{ WIRESHARK_STOCK_CAPTURE_STOP, capture_stop_24_xpm },
{ WIRESHARK_STOCK_CAPTURE_RESTART, capture_restart_24_xpm },
{ WIRESHARK_STOCK_CAPTURE_FILTER, capture_filter_24_xpm },
{ WIRESHARK_STOCK_CAPTURE_FILTER_ENTRY, capture_filter_24_xpm },
{ WIRESHARK_STOCK_CAPTURE_DETAILS, capture_details_24_xpm },
#ifdef HAVE_GEOIP
{ WIRESHARK_STOCK_MAP, internet_24_xpm},
#endif
{ WIRESHARK_STOCK_DISPLAY_FILTER, display_filter_24_xpm },
{ WIRESHARK_STOCK_DISPLAY_FILTER_ENTRY, display_filter_24_xpm },
{ WIRESHARK_STOCK_ABOUT, wsicon16_xpm },
{ WIRESHARK_STOCK_COLORIZE, colorize_24_xpm },
{ WIRESHARK_STOCK_AUTOSCROLL, autoscroll_24_xpm },
{ WIRESHARK_STOCK_RESIZE_COLUMNS, resize_columns_24_xpm},
{ WIRESHARK_STOCK_TIME, time_24_xpm},
{ WIRESHARK_STOCK_INTERNET, internet_24_xpm},
{ WIRESHARK_STOCK_WEB_SUPPORT, web_support_24_xpm},
{ WIRESHARK_STOCK_WIKI, wiki_24_xpm},
{ WIRESHARK_STOCK_CONVERSATIONS, conversations_16_xpm},
{ WIRESHARK_STOCK_ENDPOINTS, endpoints_16_xpm},
{ WIRESHARK_STOCK_EXPERT_INFO, expert_info_16_xpm},
{ WIRESHARK_STOCK_GRAPHS, graphs_16_xpm},
{ WIRESHARK_STOCK_FLOW_GRAPH, flow_graph_16_xpm},
{ WIRESHARK_STOCK_TELEPHONY, telephony_16_xpm},
{ WIRESHARK_STOCK_DECODE_AS, decode_as_16_xpm},
{ WIRESHARK_STOCK_CHECKBOX, checkbox_16_xpm},
{ WIRESHARK_STOCK_FILE_SET_LIST, file_set_list_16_xpm},
{ WIRESHARK_STOCK_FILE_SET_NEXT, file_set_next_16_xpm},
{ WIRESHARK_STOCK_FILE_SET_PREVIOUS, file_set_previous_16_xpm},
{ WIRESHARK_STOCK_FILTER_OUT_STREAM, display_filter_24_xpm},
{ WIRESHARK_STOCK_ENABLE, checkbox_16_xpm},
{ WIRESHARK_STOCK_COLOR1, icon_color_1_xpm},
{ WIRESHARK_STOCK_COLOR2, icon_color_2_xpm},
{ WIRESHARK_STOCK_COLOR3, icon_color_3_xpm},
{ WIRESHARK_STOCK_COLOR4, icon_color_4_xpm},
{ WIRESHARK_STOCK_COLOR5, icon_color_5_xpm},
{ WIRESHARK_STOCK_COLOR6, icon_color_6_xpm},
{ WIRESHARK_STOCK_COLOR7, icon_color_7_xpm},
{ WIRESHARK_STOCK_COLOR8, icon_color_8_xpm},
{ WIRESHARK_STOCK_COLOR9, icon_color_9_xpm},
{ WIRESHARK_STOCK_COLOR0, icon_color_0_xpm},
{ WIRESHARK_STOCK_DECODE, decode_24_xpm},
{ WIRESHARK_STOCK_AUDIO_PLAYER, audio_player_24_xpm},
{ WIRESHARK_STOCK_VOIP_FLOW, voip_flow_24_xpm},
{ WIRESHARK_STOCK_TELEPHONE, telephone_16_xpm},
{ WIRESHARK_STOCK_PREPARE_FILTER, display_filter_24_xpm},
{ WIRESHARK_STOCK_ANALYZE, analyze_24_xpm},
{ WIRESHARK_STOCK_FILE, WiresharkDoc_24_xpm},
{ NULL, NULL }
};
gtk_stock_add (stock_items, G_N_ELEMENTS (stock_items));
factory = gtk_icon_factory_new();
gtk_icon_factory_add_default(factory);
for (i = 0; pixmaps[i].name != NULL; i++) {
pixbuf = gdk_pixbuf_new_from_xpm_data((const char **) (pixmaps[i].xpm_data));
g_assert(pixbuf);
icon_set = gtk_icon_set_new_from_pixbuf (pixbuf);
gtk_icon_factory_add (factory, pixmaps[i].name, icon_set);
gtk_icon_set_unref (icon_set);
g_object_unref (G_OBJECT (pixbuf));
}
icon_set = gtk_icon_factory_lookup_default(GTK_STOCK_OPEN);
gtk_icon_factory_add(factory, WIRESHARK_STOCK_BROWSE, icon_set);
icon_set = gtk_icon_factory_lookup_default(GTK_STOCK_OK);
gtk_icon_factory_add(factory, WIRESHARK_STOCK_CREATE_STAT, icon_set);
icon_set = gtk_icon_factory_lookup_default(GTK_STOCK_SAVE);
gtk_icon_factory_add(factory, WIRESHARK_STOCK_EXPORT, icon_set);
icon_set = gtk_icon_factory_lookup_default(GTK_STOCK_OPEN);
gtk_icon_factory_add(factory, WIRESHARK_STOCK_IMPORT, icon_set);
icon_set = gtk_icon_factory_lookup_default(GTK_STOCK_PROPERTIES);
gtk_icon_factory_add(factory, WIRESHARK_STOCK_EDIT, icon_set);
icon_set = gtk_icon_factory_lookup_default(GTK_STOCK_ADD);
gtk_icon_factory_add(factory, WIRESHARK_STOCK_ADD_EXPRESSION, icon_set);
icon_set = gtk_icon_factory_lookup_default(GTK_STOCK_CLEAR);
gtk_icon_factory_add(factory, WIRESHARK_STOCK_CLEAR_EXPRESSION, icon_set);
icon_set = gtk_icon_factory_lookup_default(GTK_STOCK_APPLY);
gtk_icon_factory_add(factory, WIRESHARK_STOCK_APPLY_EXPRESSION, icon_set);
icon_set = gtk_icon_factory_lookup_default(GTK_STOCK_CLEAR);
gtk_icon_factory_add(factory, WIRESHARK_STOCK_DONT_SAVE, icon_set);
gtk_icon_factory_add(factory, WIRESHARK_STOCK_QUIT_DONT_SAVE, icon_set);
gtk_icon_factory_add(factory, WIRESHARK_STOCK_STOP_DONT_SAVE, icon_set);
gtk_icon_factory_add(factory, WIRESHARK_STOCK_STOP_QUIT_DONT_SAVE, icon_set);
icon_set = gtk_icon_factory_lookup_default(GTK_STOCK_SAVE);
gtk_icon_factory_add(factory, WIRESHARK_STOCK_STOP_SAVE, icon_set);
gtk_icon_factory_add(factory, WIRESHARK_STOCK_SAVE_ALL, icon_set);
icon_set = gtk_icon_factory_lookup_default(GTK_STOCK_CLOSE);
gtk_icon_factory_add(factory, WIRESHARK_STOCK_DISABLE, icon_set);
g_object_unref (G_OBJECT (factory));
}
