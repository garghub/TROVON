static int si_cmp(const stock_item_t * a, const stock_item_t * b) {
return strcmp(a->name, b->name);
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
