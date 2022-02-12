static char *
build_conversation_filter(int action, gboolean show_dialog)
{
packet_info *pi = &cfile.edt->pi;
char *buf;
switch(action) {
case(CONV_CBA):
if (pi->profinet_type == 0) {
if (show_dialog) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Error filtering conversation. Please make\n"
"sure you have a PROFINET CBA packet selected.");
}
return NULL;
}
if( pi->net_src.type == AT_IPv4 && pi->net_dst.type == AT_IPv4
&& pi->ipproto == IP_PROTO_TCP ) {
switch(pi->profinet_type) {
case(1):
buf = g_strdup_printf("(ip.src eq %s and ip.dst eq %s and cba.acco.dcom == 1) || (ip.src eq %s and ip.dst eq %s and cba.acco.dcom == 0)",
ip_to_str( (const guint8 *)pi->net_dst.data),
ip_to_str( (const guint8 *)pi->net_src.data),
ip_to_str( (const guint8 *)pi->net_src.data),
ip_to_str( (const guint8 *)pi->net_dst.data));
break;
case(2):
buf = g_strdup_printf("(ip.src eq %s and ip.dst eq %s and cba.acco.dcom == 1) || (ip.src eq %s and ip.dst eq %s and cba.acco.dcom == 0)",
ip_to_str( (const guint8 *)pi->net_src.data),
ip_to_str( (const guint8 *)pi->net_dst.data),
ip_to_str( (const guint8 *)pi->net_dst.data),
ip_to_str( (const guint8 *)pi->net_src.data));
break;
case(3):
buf = g_strdup_printf("(ip.src eq %s and ip.dst eq %s and cba.acco.srt == 1) || (ip.src eq %s and ip.dst eq %s and cba.acco.srt == 0)",
ip_to_str( (const guint8 *)pi->net_dst.data),
ip_to_str( (const guint8 *)pi->net_src.data),
ip_to_str( (const guint8 *)pi->net_src.data),
ip_to_str( (const guint8 *)pi->net_dst.data));
break;
case(4):
buf = g_strdup_printf("(ip.src eq %s and ip.dst eq %s and cba.acco.srt == 1) || (ip.src eq %s and ip.dst eq %s and cba.acco.srt == 0)",
ip_to_str( (const guint8 *)pi->net_src.data),
ip_to_str( (const guint8 *)pi->net_dst.data),
ip_to_str( (const guint8 *)pi->net_dst.data),
ip_to_str( (const guint8 *)pi->net_src.data));
break;
default:
return NULL;
}
} else {
return NULL;
}
break;
case(CONV_TCP):
if (pi->ipproto != IP_PROTO_TCP) {
if (show_dialog) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Error filtering conversation. Please make\n"
"sure you have a TCP packet selected.");
}
return NULL;
}
if( pi->net_src.type == AT_IPv4 && pi->net_dst.type == AT_IPv4 ) {
buf = g_strdup_printf("(ip.addr eq %s and ip.addr eq %s) and (tcp.port eq %d and tcp.port eq %d)",
ip_to_str( (const guint8 *)pi->net_src.data),
ip_to_str( (const guint8 *)pi->net_dst.data),
pi->srcport, pi->destport );
} else if( pi->net_src.type == AT_IPv6 && pi->net_dst.type == AT_IPv6 ) {
buf = g_strdup_printf("(ipv6.addr eq %s and ipv6.addr eq %s) and (tcp.port eq %d and tcp.port eq %d)",
ip6_to_str((const struct e_in6_addr *)pi->net_src.data),
ip6_to_str((const struct e_in6_addr *)pi->net_dst.data),
pi->srcport, pi->destport );
} else {
return NULL;
}
break;
case(CONV_UDP):
if (pi->ipproto != IP_PROTO_UDP) {
if (show_dialog) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Error filtering conversation. Please make\n"
"sure you have a UDP packet selected.");
}
return NULL;
}
if( pi->net_src.type == AT_IPv4 && pi->net_dst.type == AT_IPv4 ) {
buf = g_strdup_printf("(ip.addr eq %s and ip.addr eq %s) and (udp.port eq %d and udp.port eq %d)",
ip_to_str( (const guint8 *)pi->net_src.data),
ip_to_str( (const guint8 *)pi->net_dst.data),
pi->srcport, pi->destport );
} else if( pi->net_src.type == AT_IPv6 && pi->net_dst.type == AT_IPv6 ) {
buf = g_strdup_printf("(ipv6.addr eq %s and ipv6.addr eq %s) and (udp.port eq %d and udp.port eq %d)",
ip6_to_str((const struct e_in6_addr *)pi->net_src.data),
ip6_to_str((const struct e_in6_addr *)pi->net_dst.data),
pi->srcport, pi->destport );
} else {
return NULL;
}
break;
case(CONV_IP):
if ((pi->ethertype != ETHERTYPE_IP) && (pi->ethertype != ETHERTYPE_IPv6)) {
if (show_dialog) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Error filtering conversation. Please make\n"
"sure you have a IP packet selected.");
}
return NULL;
}
if( pi->net_src.type == AT_IPv4 && pi->net_dst.type == AT_IPv4 ) {
buf = g_strdup_printf("ip.addr eq %s and ip.addr eq %s",
ip_to_str( (const guint8 *)pi->net_src.data),
ip_to_str( (const guint8 *)pi->net_dst.data));
} else if( pi->net_src.type == AT_IPv6 && pi->net_dst.type == AT_IPv6 ) {
buf = g_strdup_printf("ipv6.addr eq %s and ipv6.addr eq %s",
ip6_to_str((const struct e_in6_addr *)pi->net_src.data),
ip6_to_str((const struct e_in6_addr *)pi->net_dst.data));
} else {
return NULL;
}
break;
case(CONV_ETHER):
if (pi->dl_src.type != AT_ETHER) {
if (show_dialog) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Error filtering conversation. Please make\n"
"sure you have a Ethernet packet selected.");
}
return NULL;
}
if( pi->dl_src.type == AT_ETHER && pi->dl_dst.type == AT_ETHER ) {
buf = g_strdup_printf("eth.addr eq %s and eth.addr eq %s",
ether_to_str( (const guint8 *)pi->dl_src.data),
ether_to_str( (const guint8 *)pi->dl_dst.data));
} else {
return NULL;
}
break;
default:
return NULL;
}
return buf;
}
static void
new_window_cb(GtkWidget *widget)
{
new_packet_window(widget, FALSE, FALSE);
}
static void
new_window_cb_ref(GtkWidget *widget)
{
new_packet_window(widget, TRUE, FALSE);
}
static void
edit_window_cb(GtkWidget *widget _U_)
{
new_packet_window(widget, FALSE, TRUE);
}
static void
conversation_cb(GtkAction *a _U_, gpointer data _U_, int action)
{
gchar *filter;
GtkWidget *filter_te;
if (cfile.current_frame) {
filter = build_conversation_filter(action, TRUE);
filter_te = gtk_bin_get_child(GTK_BIN(g_object_get_data(G_OBJECT(top_level), E_DFILTER_CM_KEY)));
gtk_entry_set_text(GTK_ENTRY(filter_te), filter);
main_filter_packets(&cfile, filter, TRUE);
g_free(filter);
}
}
static void
colorize_conversation_cb(GtkAction *action _U_, gpointer data _U_, int action_num)
{
gchar *filter = NULL;
if( (action_num>>8) == 255 ) {
color_filters_reset_tmp();
packet_list_colorize_packets();
} else if (cfile.current_frame) {
if( (action_num&0xff) == 0 ) {
filter = build_conversation_filter(CONV_TCP,FALSE);
if( filter == NULL )
filter = build_conversation_filter(CONV_UDP,FALSE);
if( filter == NULL )
filter = build_conversation_filter(CONV_IP,FALSE);
if( filter == NULL )
filter = build_conversation_filter(CONV_ETHER,FALSE);
if( filter == NULL ) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Unable to build conversation filter.");
return;
}
} else {
filter = build_conversation_filter(action_num&0xff, TRUE);
}
if( (action_num>>8) == 0) {
color_display_with_filter(filter);
} else {
color_filters_set_tmp((guint8)(action_num>>8),filter,FALSE);
packet_list_colorize_packets();
}
g_free(filter);
}
}
static void
goto_conversation_frame(gboolean dir)
{
gchar *filter;
dfilter_t *dfcode = NULL;
gboolean found_packet = FALSE;
filter = build_conversation_filter(CONV_TCP,FALSE);
if( filter == NULL )
filter = build_conversation_filter(CONV_UDP,FALSE);
if( filter == NULL )
filter = build_conversation_filter(CONV_IP,FALSE);
if( filter == NULL ) {
statusbar_push_temporary_msg("Unable to build conversation filter.");
g_free(filter);
return;
}
if (!dfilter_compile(filter, &dfcode)) {
statusbar_push_temporary_msg("Error compiling filter for this conversation.");
g_free(filter);
return;
}
found_packet = cf_find_packet_dfilter(&cfile, dfcode, dir?SD_BACKWARD:SD_FORWARD);
if (!found_packet) {
statusbar_push_temporary_msg("No previous/next packet in conversation.");
}
dfilter_free(dfcode);
g_free(filter);
}
static void
goto_next_frame_conversation_cb(GtkAction *action _U_, gpointer user_data _U_)
{
goto_conversation_frame(FALSE);
}
static void
goto_previous_frame_conversation_cb(GtkAction *action _U_, gpointer user_data _U_)
{
goto_conversation_frame(TRUE);
}
static void
copy_description_cb(GtkAction *action _U_, gpointer user_data)
{
copy_selected_plist_cb( NULL , user_data, COPY_SELECTED_DESCRIPTION);
}
static void
copy_fieldname_cb(GtkAction *action _U_, gpointer user_data)
{
copy_selected_plist_cb( NULL , user_data, COPY_SELECTED_FIELDNAME);
}
static void
copy_value_cb(GtkAction *action _U_, gpointer user_data)
{
copy_selected_plist_cb( NULL , user_data, COPY_SELECTED_VALUE);
}
static void
copy_as_filter_cb(GtkAction *action _U_, gpointer user_data _U_)
{
match_selected_ptree_cb( popup_menu_object, (MATCH_SELECTED_E)(MATCH_SELECTED_REPLACE|MATCH_SELECTED_COPY_ONLY));
}
static void
set_reftime_cb(GtkAction *action _U_, gpointer user_data)
{
reftime_frame_cb( NULL , user_data, REFTIME_TOGGLE);
}
static void
find_next_ref_time_cb(GtkAction *action _U_, gpointer user_data)
{
reftime_frame_cb( NULL , user_data, REFTIME_FIND_NEXT);
}
static void
find_previous_ref_time_cb(GtkAction *action _U_, gpointer user_data)
{
reftime_frame_cb( NULL , user_data, REFTIME_FIND_PREV);
}
static void
menus_prefs_cb(GtkAction *action _U_, gpointer user_data)
{
prefs_page_cb( NULL , user_data, PREFS_PAGE_USER_INTERFACE);
}
static void
main_toolbar_show_hide_cb(GtkAction *action _U_, gpointer user_data _U_)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/MainToolbar");
recent.main_toolbar_show = gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget));
main_widgets_show_or_hide();
}
static void
filter_toolbar_show_hide_cb(GtkAction * action _U_, gpointer user_data _U_)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/FilterToolbar");
recent.filter_toolbar_show = gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget));
main_widgets_show_or_hide();
}
static void
wireless_toolbar_show_hide_cb(GtkAction *action _U_, gpointer user_data _U_)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/WirelessToolbar");
if(widget) {
recent.wireless_toolbar_show = gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget));
} else {
recent.wireless_toolbar_show = FALSE;
}
main_widgets_show_or_hide();
}
static void
status_bar_show_hide_cb(GtkAction *action _U_, gpointer user_data _U_)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/StatusBar");
recent.statusbar_show = gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget));
main_widgets_show_or_hide();
}
static void
packet_list_show_hide_cb(GtkAction *action _U_, gpointer user_data _U_)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/PacketList");
recent.packet_list_show = gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget));
main_widgets_show_or_hide();
}
static void
packet_details_show_hide_cb(GtkAction *action _U_, gpointer user_data _U_)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/PacketDetails");
recent.tree_view_show = gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget));
main_widgets_show_or_hide();
}
static void
packet_bytes_show_hide_cb(GtkAction *action _U_, gpointer user_data _U_)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/PacketBytes");
recent.byte_view_show = gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget));
main_widgets_show_or_hide();
}
static void
timestamp_seconds_time_cb(GtkAction *action _U_, gpointer user_data _U_)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/TimeDisplayFormat/DisplaySecondsWithHoursAndMinutes");
if (gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget))) {
recent.gui_seconds_format = TS_SECONDS_HOUR_MIN_SEC;
} else {
recent.gui_seconds_format = TS_SECONDS_DEFAULT;
}
timestamp_set_seconds_type (recent.gui_seconds_format);
cf_timestamp_auto_precision(&cfile);
packet_list_queue_draw();
}
static void
timestamp_format_new_cb (GtkRadioAction *action, GtkRadioAction *current _U_, gpointer user_data _U_)
{
ts_type value;
value = (ts_type) gtk_radio_action_get_current_value (action);
if (recent.gui_time_format != value) {
timestamp_set_type(value);
recent.gui_time_format = value;
cf_timestamp_auto_precision(&cfile);
packet_list_queue_draw();
}
}
static void
timestamp_precision_new_cb (GtkRadioAction *action, GtkRadioAction *current _U_, gpointer user_data _U_)
{
gint value;
value = gtk_radio_action_get_current_value (action);
if (recent.gui_time_precision != value) {
if (value == TS_PREC_AUTO) {
timestamp_set_precision(TS_PREC_AUTO_SEC);
} else {
timestamp_set_precision(value);
}
recent.gui_time_precision = value;
cf_timestamp_auto_precision(&cfile);
packet_list_queue_draw();
}
}
static void
view_menu_en_for_MAC_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/NameResolution/EnableforMACLayer");
if (!widget){
g_warning("view_menu_en_for_MAC_cb: No widget found");
}else{
name_resolution_cb( widget , user_data, &gbl_resolv_flags.mac_name);
}
}
static void
view_menu_en_for_network_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/NameResolution/EnableforNetworkLayer");
if (!widget){
g_warning("view_menu_en_for_network_cb: No widget found");
}else{
name_resolution_cb( widget , user_data, &gbl_resolv_flags.network_name);
}
}
static void
view_menu_en_for_transport_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/NameResolution/EnableforTransportLayer");
if (!widget){
g_warning("view_menu_en_for_transport_cb: No widget found");
}else{
name_resolution_cb( widget , user_data, &gbl_resolv_flags.transport_name);
}
}
static void
view_menu_en_use_external_resolver_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/NameResolution/UseExternalNetworkNameResolver");
if (!widget){
g_warning("view_menu_en_use_external_resolver_cb: No widget found");
}else{
name_resolution_cb( widget , user_data, &gbl_resolv_flags.use_external_net_name_resolver);
}
}
static void
view_menu_colorize_pkt_lst_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/ColorizePacketList");
if (!widget){
g_warning("view_menu_colorize_pkt_lst_cb: No widget found");
}else{
colorize_cb( widget , user_data);
}
}
static void
view_menu_auto_scroll_live_cb(GtkAction *action _U_, gpointer user_data _U_)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/AutoScrollinLiveCapture");
if (!widget){
g_warning("view_menu_auto_scroll_live_cb: No widget found");
}else{
main_auto_scroll_live_changed(gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget)));
}
}
static void
view_menu_color_conv_color1_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, 1*256);
}
static void
view_menu_color_conv_color2_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, 2*256);
}
static void
view_menu_color_conv_color3_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, 3*256);
}
static void
view_menu_color_conv_color4_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, 4*256);
}
static void
view_menu_color_conv_color5_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, 5*256);
}
static void
view_menu_color_conv_color6_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, 6*256);
}
static void
view_menu_color_conv_color7_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, 7*256);
}
static void
view_menu_color_conv_color8_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, 8*256);
}
static void
view_menu_color_conv_color9_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, 9*256);
}
static void
view_menu_color_conv_color10_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, 10*256);
}
static void
view_menu_color_conv_new_rule_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, 0);
}
static void
view_menu_reset_coloring_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, 255*256);
}
static void
capture_if_action_cb(GtkAction *action _U_, gpointer user_data)
{
capture_if_cb(NULL , user_data);
}
static void
capture_prep_action_cb(GtkAction *action _U_, gpointer user_data)
{
capture_prep_cb(NULL , user_data);
}
static void
capture_start_action_cb(GtkAction *action _U_, gpointer user_data)
{
capture_start_cb(NULL , user_data);
}
static void
capture_stop_action_cb(GtkAction *action _U_, gpointer user_data)
{
capture_stop_cb(NULL , user_data);
}
static void
capture_restart_action_cb(GtkAction *action _U_, gpointer user_data)
{
capture_restart_cb(NULL , user_data);
}
static void
capture_filters_action_cb(GtkAction *action _U_, gpointer user_data _U_)
{
cfilter_dialog_cb(NULL );
}
static void
refresh_interfaces_action_cb(GtkAction *action _U_, gpointer user_data _U_)
{
refresh_local_interface_lists();
}
static void
help_menu_cont_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(HELP_CONTENT));
}
static void
help_menu_faq_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(ONLINEPAGE_FAQ));
}
static void
help_menu_ask_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(ONLINEPAGE_ASK));
}
static void
help_menu_wireshark_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(LOCALPAGE_MAN_WIRESHARK));
}
static void
help_menu_wireshark_flt_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(LOCALPAGE_MAN_WIRESHARK_FILTER));
}
static void
help_menu_Capinfos_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(LOCALPAGE_MAN_CAPINFOS));
}
static void
help_menu_Dumpcap_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(LOCALPAGE_MAN_DUMPCAP));
}
static void
help_menu_Editcap_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(LOCALPAGE_MAN_EDITCAP));
}
static void
help_menu_Mergecap_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(LOCALPAGE_MAN_MERGECAP));
}
static void
help_menu_RawShark_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(LOCALPAGE_MAN_RAWSHARK));
}
static void
help_menu_Reorder_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(LOCALPAGE_MAN_REORDERCAP));
}
static void
help_menu_Text2pcap_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(LOCALPAGE_MAN_TEXT2PCAP));
}
static void
help_menu_TShark_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(LOCALPAGE_MAN_TSHARK));
}
static void
help_menu_Website_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(ONLINEPAGE_HOME));
}
static void
help_menu_Wiki_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(ONLINEPAGE_WIKI));
}
static void
help_menu_Downloads_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb(NULL, NULL , GINT_TO_POINTER(ONLINEPAGE_DOWNLOAD));
}
static void
help_menu_SampleCaptures_cb(GtkAction *action _U_, gpointer user_data _U_)
{
topic_menu_cb( NULL, NULL , GINT_TO_POINTER(ONLINEPAGE_SAMPLE_FILES));
}
static void
check_for_updates_cb(GtkAction *action _U_, gpointer user_data _U_)
{
software_update_check();
}
static void
select_bytes_view_cb (GtkRadioAction *action, GtkRadioAction *current _U_, gpointer user_data _U_)
{
gint value;
value = gtk_radio_action_get_current_value (action);
select_bytes_view( NULL, NULL, value);
}
static void
sort_ascending_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_packet_list_heading, "/PacketListHeadingPopup/SortAscending");
packet_list_column_menu_cb( widget , user_data, COLUMN_SELECTED_SORT_ASCENDING);
}
static void
sort_descending_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_packet_list_heading, "/PacketListHeadingPopup/SortDescending");
packet_list_column_menu_cb( widget , user_data, COLUMN_SELECTED_SORT_DESCENDING);
}
static void
no_sorting_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_packet_list_heading, "/PacketListHeadingPopup/NoSorting");
packet_list_column_menu_cb( widget , user_data, COLUMN_SELECTED_SORT_NONE);
}
static void
packet_list_heading_show_resolved_cb(GtkAction *action _U_, gpointer user_data _U_)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_packet_list_heading, "/PacketListHeadingPopup/ShowResolved");
packet_list_column_menu_cb( widget , user_data, COLUMN_SELECTED_TOGGLE_RESOLVED);
}
static void
packet_list_heading_align_left_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_packet_list_heading, "/PacketListHeadingPopup/AlignLeft");
packet_list_column_menu_cb( widget , user_data, COLUMN_SELECTED_ALIGN_LEFT);
}
static void
packet_list_heading_align_center_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_packet_list_heading, "/PacketListHeadingPopup/AlignCenter");
packet_list_column_menu_cb( widget , user_data, COLUMN_SELECTED_ALIGN_CENTER);
}
static void
packet_list_heading_align_right_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_packet_list_heading, "/PacketListHeadingPopup/AlignRight");
packet_list_column_menu_cb( widget , user_data, COLUMN_SELECTED_ALIGN_RIGHT);
}
static void
packet_list_heading_col_pref_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_packet_list_heading, "/PacketListHeadingPopup/ColumnPreferences");
prefs_page_cb( widget , user_data, PREFS_PAGE_COLUMNS);
}
static void
packet_list_heading_resize_col_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_packet_list_heading, "/PacketListHeadingPopup/ResizeColumn");
packet_list_column_menu_cb( widget , user_data, COLUMN_SELECTED_RESIZE);
}
static void
packet_list_heading_change_col_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_packet_list_heading, "/PacketListHeadingPopup/EditColumnDetails");
packet_list_column_menu_cb( widget , user_data, COLUMN_SELECTED_CHANGE);
}
static void
packet_list_heading_activate_all_columns_cb(GtkAction *action _U_, gpointer user_data _U_)
{
packet_list_set_all_columns_visible ();
}
static void
packet_list_heading_hide_col_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_packet_list_heading, "/PacketListHeadingPopup/HideColumn");
packet_list_column_menu_cb( widget , user_data, COLUMN_SELECTED_HIDE);
}
static void
packet_list_heading_remove_col_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_packet_list_heading, "/PacketListHeadingPopup/RemoveColumn");
packet_list_column_menu_cb( widget , user_data, COLUMN_SELECTED_REMOVE);
}
static void
packet_list_menu_set_ref_time_cb(GtkAction *action _U_, gpointer user_data)
{
reftime_frame_cb( NULL , user_data, REFTIME_TOGGLE);
}
static void
apply_selected_filter_cb(GtkAction *action, gpointer user_data)
{
const gchar *path = gtk_action_get_accel_path(action);
if (strncmp (path+9,"/PacketListPopUpMenuActionGroup",31) == 0){
match_selected_plist_cb(user_data, (MATCH_SELECTED_E)(MATCH_SELECTED_REPLACE|MATCH_SELECTED_APPLY_NOW));
} else {
match_selected_ptree_cb(user_data, (MATCH_SELECTED_E)(MATCH_SELECTED_REPLACE|MATCH_SELECTED_APPLY_NOW));
}
}
static void
apply_not_selected_cb(GtkAction *action, gpointer user_data)
{
const gchar *path = gtk_action_get_accel_path(action);
if (strncmp (path+9,"/PacketListPopUpMenuActionGroup",31) == 0){
match_selected_plist_cb(user_data, (MATCH_SELECTED_E)(MATCH_SELECTED_NOT|MATCH_SELECTED_APPLY_NOW));
} else {
match_selected_ptree_cb(user_data, (MATCH_SELECTED_E)(MATCH_SELECTED_NOT|MATCH_SELECTED_APPLY_NOW));
}
}
static void
apply_and_selected_cb(GtkAction *action, gpointer user_data)
{
const gchar *path = gtk_action_get_accel_path(action);
if (strncmp (path+9,"/PacketListPopUpMenuActionGroup",31) == 0){
match_selected_plist_cb(user_data, (MATCH_SELECTED_E)(MATCH_SELECTED_AND|MATCH_SELECTED_APPLY_NOW));
} else {
match_selected_ptree_cb(user_data, (MATCH_SELECTED_E)(MATCH_SELECTED_AND|MATCH_SELECTED_APPLY_NOW));
}
}
static void
apply_or_selected_cb(GtkAction *action, gpointer user_data)
{
const gchar *path = gtk_action_get_accel_path(action);
if (strncmp (path+9,"/PacketListPopUpMenuActionGroup",31) == 0){
match_selected_plist_cb(user_data, (MATCH_SELECTED_E)(MATCH_SELECTED_OR|MATCH_SELECTED_APPLY_NOW));
} else {
match_selected_ptree_cb(user_data, (MATCH_SELECTED_E)(MATCH_SELECTED_OR|MATCH_SELECTED_APPLY_NOW));
}
}
static void
apply_and_not_selected_cb(GtkAction *action, gpointer user_data)
{
const gchar *path = gtk_action_get_accel_path(action);
if (strncmp (path+9,"/PacketListPopUpMenuActionGroup",31) == 0){
match_selected_plist_cb(user_data, (MATCH_SELECTED_E)(MATCH_SELECTED_AND_NOT|MATCH_SELECTED_APPLY_NOW));
} else {
match_selected_ptree_cb(user_data, (MATCH_SELECTED_E)(MATCH_SELECTED_AND_NOT|MATCH_SELECTED_APPLY_NOW));
}
}
static void
apply_or_not_selected_cb(GtkAction *action, gpointer user_data)
{
const gchar *path = gtk_action_get_accel_path(action);
if (strncmp (path+9,"/PacketListPopUpMenuActionGroup",31) == 0){
match_selected_plist_cb(user_data,(MATCH_SELECTED_E)(MATCH_SELECTED_OR_NOT|MATCH_SELECTED_APPLY_NOW));
} else {
match_selected_ptree_cb(user_data, (MATCH_SELECTED_E)(MATCH_SELECTED_OR_NOT|MATCH_SELECTED_APPLY_NOW));
}
}
static void
prepare_selected_cb(GtkAction *action, gpointer user_data)
{
const gchar *path = gtk_action_get_accel_path(action);
if (strncmp (path+9,"/PacketListPopUpMenuActionGroup",31) == 0){
match_selected_plist_cb(user_data, MATCH_SELECTED_REPLACE);
} else {
match_selected_ptree_cb(user_data, MATCH_SELECTED_REPLACE);
}
}
static void
prepare_not_selected_cb(GtkAction *action, gpointer user_data)
{
const gchar *path = gtk_action_get_accel_path(action);
if (strncmp (path+9,"/PacketListPopUpMenuActionGroup",31) == 0){
match_selected_plist_cb(user_data, MATCH_SELECTED_NOT);
} else {
match_selected_ptree_cb(user_data, MATCH_SELECTED_NOT);
}
}
static void
prepare_and_selected_cb(GtkAction *action, gpointer user_data)
{
const gchar *path = gtk_action_get_accel_path(action);
if (strncmp (path+9,"/PacketListPopUpMenuActionGroup",31) == 0){
match_selected_plist_cb(user_data, MATCH_SELECTED_AND);
} else {
match_selected_ptree_cb(user_data, MATCH_SELECTED_AND);
}
}
static void
prepare_or_selected_cb(GtkAction *action, gpointer user_data)
{
const gchar *path = gtk_action_get_accel_path(action);
if (strncmp (path+9,"/PacketListPopUpMenuActionGroup",31) == 0){
match_selected_plist_cb(user_data, MATCH_SELECTED_OR);
} else {
match_selected_ptree_cb(user_data, MATCH_SELECTED_OR);
}
}
static void
prepare_and_not_selected_cb(GtkAction *action, gpointer user_data)
{
const gchar *path = gtk_action_get_accel_path(action);
if (strncmp (path+9,"/PacketListPopUpMenuActionGroup",31) == 0){
match_selected_plist_cb(user_data, MATCH_SELECTED_AND_NOT);
} else {
match_selected_ptree_cb(user_data, MATCH_SELECTED_AND_NOT);
}
}
static void
prepare_or_not_selected_cb(GtkAction *action, gpointer user_data)
{
const gchar *path = gtk_action_get_accel_path(action);
if (strncmp (path+9,"/PacketListPopUpMenuActionGroup",31) == 0){
match_selected_plist_cb(user_data, MATCH_SELECTED_OR_NOT);
} else {
match_selected_ptree_cb(user_data, MATCH_SELECTED_OR_NOT);
}
}
static void
packet_list_menu_conversation_ethernet_cb(GtkAction *action, gpointer user_data)
{
conversation_cb( action, user_data, CONV_ETHER);
}
static void
packet_list_menu_conversation_ip_cb(GtkAction *action _U_, gpointer user_data)
{
conversation_cb( action, user_data, CONV_IP);
}
static void
packet_list_menu_conversation_tcp_cb(GtkAction *action _U_, gpointer user_data)
{
conversation_cb( action, user_data, CONV_TCP);
}
static void
packet_list_menu_conversation_udp_cb(GtkAction *action _U_, gpointer user_data)
{
conversation_cb( action, user_data, CONV_UDP);
}
static void
packet_list_menu_conversation_pn_cba_cb(GtkAction *action _U_, gpointer user_data)
{
conversation_cb( action, user_data, CONV_CBA);
}
static void
packet_list_menu_color_conv_ethernet_color1_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_ETHER+1*256);
}
static void
packet_list_menu_color_conv_ethernet_color2_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_ETHER+2*256);
}
static void
packet_list_menu_color_conv_ethernet_color3_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_ETHER+3*256);
}
static void
packet_list_menu_color_conv_ethernet_color4_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_ETHER+4*256);
}
static void
packet_list_menu_color_conv_ethernet_color5_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_ETHER+5*256);
}
static void
packet_list_menu_color_conv_ethernet_color6_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_ETHER+6*256);
}
static void
packet_list_menu_color_conv_ethernet_color7_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_ETHER+7*256);
}
static void
packet_list_menu_color_conv_ethernet_color8_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_ETHER+8*256);
}
static void
packet_list_menu_color_conv_ethernet_color9_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_ETHER+9*256);
}
static void
packet_list_menu_color_conv_ethernet_color10_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_ETHER+10*256);
}
static void
packet_list_menu_color_conv_ethernet_new_rule_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_ETHER);
}
static void
packet_list_menu_color_conv_ip_color1_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_IP+1*256);
}
static void
packet_list_menu_color_conv_ip_color2_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_IP+2*256);
}
static void
packet_list_menu_color_conv_ip_color3_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_IP+3*256);
}
static void
packet_list_menu_color_conv_ip_color4_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_IP+4*256);
}
static void
packet_list_menu_color_conv_ip_color5_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_IP+5*256);
}
static void
packet_list_menu_color_conv_ip_color6_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_IP+6*256);
}
static void
packet_list_menu_color_conv_ip_color7_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_IP+7*256);
}
static void
packet_list_menu_color_conv_ip_color8_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_IP+8*256);
}
static void
packet_list_menu_color_conv_ip_color9_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_IP+9*256);
}
static void
packet_list_menu_color_conv_ip_color10_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_IP+10*256);
}
static void
packet_list_menu_color_conv_ip_new_rule_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_TCP);
}
static void
packet_list_menu_color_conv_tcp_color1_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_TCP+1*256);
}
static void
packet_list_menu_color_conv_tcp_color2_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_TCP+2*256);
}
static void
packet_list_menu_color_conv_tcp_color3_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_TCP+3*256);
}
static void
packet_list_menu_color_conv_tcp_color4_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_TCP+4*256);
}
static void
packet_list_menu_color_conv_tcp_color5_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_TCP+5*256);
}
static void
packet_list_menu_color_conv_tcp_color6_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_TCP+6*256);
}
static void
packet_list_menu_color_conv_tcp_color7_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_TCP+7*256);
}
static void
packet_list_menu_color_conv_tcp_color8_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_TCP+8*256);
}
static void
packet_list_menu_color_conv_tcp_color9_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_TCP+9*256);
}
static void
packet_list_menu_color_conv_tcp_color10_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_TCP+10*256);
}
static void
packet_list_menu_color_conv_tcp_new_rule_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_TCP);
}
static void
packet_list_menu_color_conv_udp_color1_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_UDP+1*256);
}
static void
packet_list_menu_color_conv_udp_color2_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_UDP+2*256);
}
static void
packet_list_menu_color_conv_udp_color3_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_UDP+3*256);
}
static void
packet_list_menu_color_conv_udp_color4_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_UDP+4*256);
}
static void
packet_list_menu_color_conv_udp_color5_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_UDP+5*256);
}
static void
packet_list_menu_color_conv_udp_color6_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_UDP+6*256);
}
static void
packet_list_menu_color_conv_udp_color7_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_UDP+7*256);
}
static void
packet_list_menu_color_conv_udp_color8_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_UDP+8*256);
}
static void
packet_list_menu_color_conv_udp_color9_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_UDP+9*256);
}
static void
packet_list_menu_color_conv_udp_color10_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_UDP+10*256);
}
static void
packet_list_menu_color_conv_udp_new_rule_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_UDP);
}
static void
packet_list_menu_color_conv_cba_color1_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_CBA+1*256);
}
static void
packet_list_menu_color_conv_cba_color2_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_CBA+2*256);
}
static void
packet_list_menu_color_conv_cba_color3_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_CBA+3*256);
}
static void
packet_list_menu_color_conv_cba_color4_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_CBA+4*256);
}
static void
packet_list_menu_color_conv_cba_color5_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_CBA+5*256);
}
static void
packet_list_menu_color_conv_cba_color6_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_CBA+6*256);
}
static void
packet_list_menu_color_conv_cba_color7_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_CBA+7*256);
}
static void
packet_list_menu_color_conv_cba_color8_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_CBA+8*256);
}
static void
packet_list_menu_color_conv_cba_color9_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_CBA+9*256);
}
static void
packet_list_menu_color_conv_cba_color10_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_CBA+10*256);
}
static void
packet_list_menu_color_conv_cba_new_rule_cb(GtkAction *action, gpointer user_data)
{
colorize_conversation_cb(action, user_data, CONV_CBA);
}
static void
packet_list_menu_copy_sum_txt(GtkAction *action _U_, gpointer user_data)
{
packet_list_copy_summary_cb(user_data, CS_TEXT);
}
static void
packet_list_menu_copy_sum_csv(GtkAction *action _U_, gpointer user_data)
{
packet_list_copy_summary_cb(user_data, CS_CSV);
}
static void
packet_list_menu_copy_as_flt(GtkAction *action _U_, gpointer user_data)
{
match_selected_plist_cb(user_data, (MATCH_SELECTED_E)(MATCH_SELECTED_REPLACE|MATCH_SELECTED_COPY_ONLY));
}
static void
packet_list_menu_copy_bytes_oht_cb(GtkAction *action _U_, gpointer user_data)
{
copy_hex_cb( NULL , user_data, (copy_data_type)(CD_ALLINFO | CD_FLAGS_SELECTEDONLY));
}
static void
packet_list_menu_copy_bytes_oh_cb(GtkAction *action _U_, gpointer user_data)
{
copy_hex_cb( NULL , user_data, (copy_data_type)(CD_HEXCOLUMNS | CD_FLAGS_SELECTEDONLY));
}
static void
packet_list_menu_copy_bytes_text_cb(GtkAction *action _U_, gpointer user_data)
{
copy_hex_cb( NULL , user_data, (copy_data_type)(CD_TEXTONLY | CD_FLAGS_SELECTEDONLY));
}
static void
packet_list_menu_copy_bytes_hex_strm_cb(GtkAction *action _U_, gpointer user_data)
{
copy_hex_cb( NULL , user_data, (copy_data_type)(CD_HEX | CD_FLAGS_SELECTEDONLY));
}
static void
packet_list_menu_copy_bytes_bin_strm_cb(GtkAction *action _U_, gpointer user_data)
{
copy_hex_cb( NULL , user_data, (copy_data_type)(CD_BINARY | CD_FLAGS_SELECTEDONLY));
}
static void
tree_view_menu_color_with_flt_color1_cb(GtkAction *action _U_, gpointer user_data)
{
colorize_selected_ptree_cb( NULL , user_data, 1);
}
static void
tree_view_menu_color_with_flt_color2_cb(GtkAction *action _U_, gpointer user_data)
{
colorize_selected_ptree_cb( NULL , user_data, 2);
}
static void
tree_view_menu_color_with_flt_color3_cb(GtkAction *action _U_, gpointer user_data)
{
colorize_selected_ptree_cb( NULL , user_data, 3);
}
static void
tree_view_menu_color_with_flt_color4_cb(GtkAction *action _U_, gpointer user_data)
{
colorize_selected_ptree_cb( NULL , user_data, 4);
}
static void
tree_view_menu_color_with_flt_color5_cb(GtkAction *action _U_, gpointer user_data)
{
colorize_selected_ptree_cb( NULL , user_data, 5);
}
static void
tree_view_menu_color_with_flt_color6_cb(GtkAction *action _U_, gpointer user_data)
{
colorize_selected_ptree_cb( NULL , user_data, 6);
}
static void
tree_view_menu_color_with_flt_color7_cb(GtkAction *action _U_, gpointer user_data)
{
colorize_selected_ptree_cb( NULL , user_data, 7);
}
static void
tree_view_menu_color_with_flt_color8_cb(GtkAction *action _U_, gpointer user_data)
{
colorize_selected_ptree_cb( NULL , user_data, 8);
}
static void
tree_view_menu_color_with_flt_color9_cb(GtkAction *action _U_, gpointer user_data)
{
colorize_selected_ptree_cb( NULL , user_data, 9);
}
static void
tree_view_menu_color_with_flt_color10_cb(GtkAction *action _U_, gpointer user_data)
{
colorize_selected_ptree_cb( NULL , user_data, 10);
}
static void
tree_view_menu_color_with_flt_new_rule_cb(GtkAction *action _U_, gpointer user_data)
{
colorize_selected_ptree_cb( NULL , user_data, 0);
}
static void
tree_view_menu_copy_desc(GtkAction *action _U_, gpointer user_data)
{
copy_selected_plist_cb( NULL , user_data, COPY_SELECTED_DESCRIPTION);
}
static void
tree_view_menu_copy_field(GtkAction *action _U_, gpointer user_data)
{
copy_selected_plist_cb( NULL , user_data, COPY_SELECTED_FIELDNAME);
}
static void
tree_view_menu_copy_value(GtkAction *action _U_, gpointer user_data)
{
copy_selected_plist_cb( NULL , user_data, COPY_SELECTED_VALUE);
}
static void
tree_view_menu_copy_as_flt(GtkAction *action _U_, gpointer user_data _U_)
{
match_selected_ptree_cb( popup_menu_object, (MATCH_SELECTED_E)(MATCH_SELECTED_REPLACE|MATCH_SELECTED_COPY_ONLY));
}
GtkWidget *
main_menu_new(GtkAccelGroup ** table)
{
GtkWidget *menubar;
#ifdef HAVE_IGE_MAC_INTEGRATION
GtkWidget *quit_item, *about_item, *preferences_item;
IgeMacMenuGroup *group;
#endif
#ifdef HAVE_GTKOSXAPPLICATION
GtkosxApplication *theApp;
GtkWidget * item;
GtkWidget * dock_menu;
#endif
grp = gtk_accel_group_new();
if (initialize)
menus_init();
menubar = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar");
#ifdef HAVE_IGE_MAC_INTEGRATION
if(prefs.gui_macosx_style) {
ige_mac_menu_set_menu_bar(GTK_MENU_SHELL(menubar));
ige_mac_menu_set_global_key_handler_enabled(TRUE);
group = ige_mac_menu_add_app_menu_group();
about_item = gtk_menu_item_new_with_label("About");
g_signal_connect(about_item, "activate", G_CALLBACK(about_wireshark_cb),
NULL);
ige_mac_menu_add_app_menu_item(group, GTK_MENU_ITEM(about_item), NULL);
group = ige_mac_menu_add_app_menu_group();
preferences_item = gtk_menu_item_new_with_label("Preferences");
g_signal_connect(preferences_item, "activate", G_CALLBACK(prefs_cb),
NULL);
ige_mac_menu_add_app_menu_item(group, GTK_MENU_ITEM(preferences_item),
NULL);
}
quit_item = gtk_menu_item_new_with_label("Quit");
g_signal_connect(quit_item, "activate", G_CALLBACK(file_quit_cmd_cb), NULL);
ige_mac_menu_set_quit_menu_item(GTK_MENU_ITEM(quit_item));
#endif
#ifdef HAVE_GTKOSXAPPLICATION
theApp = (GtkosxApplication *)g_object_new(GTKOSX_TYPE_APPLICATION, NULL);
if(prefs.gui_macosx_style) {
gtk_widget_hide(menubar);
gtkosx_application_set_menu_bar(theApp, GTK_MENU_SHELL(menubar));
gtkosx_application_set_use_quartz_accelerators(theApp, TRUE);
item = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/HelpMenu/AboutWireshark");
gtkosx_application_insert_app_menu_item(theApp, item, 0);
gtkosx_application_insert_app_menu_item(theApp, gtk_separator_menu_item_new(), 1);
item = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/EditMenu/Preferences");
gtkosx_application_insert_app_menu_item(theApp, item, 2);
item = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/HelpMenu");
gtkosx_application_set_help_menu(theApp,GTK_MENU_ITEM(item));
item = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/FileMenu/Quit");
gtk_widget_hide(item);
}
dock_menu = gtk_menu_new();
item = gtk_menu_item_new_with_label("Start");
g_signal_connect(item, "activate", G_CALLBACK (capture_start_cb), NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(dock_menu), item);
item = gtk_menu_item_new_with_label("Stop");
g_signal_connect(item, "activate", G_CALLBACK (capture_stop_cb), NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(dock_menu), item);
item = gtk_menu_item_new_with_label("Restart");
g_signal_connect(item, "activate", G_CALLBACK (capture_restart_cb), NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(dock_menu), item);
gtkosx_application_set_dock_menu(theApp, GTK_MENU_SHELL(dock_menu));
#endif
if (table)
*table = grp;
return menubar;
}
static void
menu_dissector_filter_cb(GtkAction *action _U_, gpointer callback_data)
{
dissector_filter_t *filter_entry = (dissector_filter_t *)callback_data;
GtkWidget *filter_te;
const char *buf;
filter_te = gtk_bin_get_child(GTK_BIN(g_object_get_data(G_OBJECT(top_level), E_DFILTER_CM_KEY)));
buf = filter_entry->build_filter_string(&cfile.edt->pi);
gtk_entry_set_text(GTK_ENTRY(filter_te), buf);
main_filter_packets(&cfile, buf, TRUE);
g_free( (void *) buf);
}
static gboolean
menu_dissector_filter_spe_cb(frame_data *fd _U_, epan_dissect_t *edt, gpointer callback_data)
{
dissector_filter_t *filter_entry = (dissector_filter_t *)callback_data;
return (edt != NULL) ? filter_entry->is_filter_valid(&edt->pi) : FALSE;
}
static void
menu_dissector_filter(capture_file *cf)
{
GList *list_entry = dissector_filter_list;
dissector_filter_t *filter_entry;
guint merge_id;
GtkActionGroup *action_group;
GtkAction *action;
GtkWidget *submenu_dissector_filters;
gchar *action_name;
guint i = 0;
merge_id = gtk_ui_manager_new_merge_id (ui_manager_main_menubar);
action_group = gtk_action_group_new ("dissector-filters-group");
submenu_dissector_filters = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/AnalyzeMenu/ConversationFilterMenu");
if(!submenu_dissector_filters){
g_warning("add_recent_items: No submenu_dissector_filters found, path= /Menubar/AnalyzeMenu/ConversationFilterMenu");
}
gtk_ui_manager_insert_action_group (ui_manager_main_menubar, action_group, 0);
g_object_set_data (G_OBJECT (ui_manager_main_menubar),
"diessector-filters-merge-id", GUINT_TO_POINTER (merge_id));
if (!list_entry){
action = (GtkAction *)g_object_new (GTK_TYPE_ACTION,
"name", "filter-list-empty",
"label", "No filters",
"sensitive", FALSE,
NULL);
gtk_action_group_add_action (action_group, action);
gtk_action_set_sensitive(action, FALSE);
g_object_unref (action);
gtk_ui_manager_add_ui (ui_manager_main_menubar, merge_id,
"/Menubar/AnalyzeMenu/ConversationFilterMenu/Filters",
"filter-list-empty",
"filter-list-empty",
GTK_UI_MANAGER_MENUITEM,
FALSE);
return;
}
while (list_entry != NULL) {
filter_entry = (dissector_filter_t *)list_entry->data;
action_name = g_strdup_printf ("filter-%u", i);
action = (GtkAction *)g_object_new (GTK_TYPE_ACTION,
"name", action_name,
"label", filter_entry->name,
"sensitive", menu_dissector_filter_spe_cb( NULL, cf->edt, filter_entry),
NULL);
g_signal_connect (action, "activate",
G_CALLBACK (menu_dissector_filter_cb), filter_entry);
gtk_action_group_add_action (action_group, action);
g_object_unref (action);
gtk_ui_manager_add_ui (ui_manager_main_menubar, merge_id,
"/Menubar/AnalyzeMenu/ConversationFilterMenu/Filters",
action_name,
action_name,
GTK_UI_MANAGER_MENUITEM,
FALSE);
g_free(action_name);
i++;
list_entry = g_list_next(list_entry);
}
}
static void
menus_init(void)
{
GtkActionGroup *packet_list_heading_action_group, *packet_list_action_group,
*packet_list_details_action_group, *packet_list_byte_menu_action_group,
*statusbar_profiles_action_group;
GtkAction *name_res_action;
GError *error = NULL;
guint merge_id;
if (initialize) {
initialize = FALSE;
popup_menu_object = gtk_menu_new();
packet_list_heading_action_group = gtk_action_group_new ("PacketListHeadingPopUpMenuActionGroup");
gtk_action_group_add_actions (packet_list_heading_action_group,
packet_list_heading_menu_popup_action_entries,
G_N_ELEMENTS(packet_list_heading_menu_popup_action_entries),
popup_menu_object);
gtk_action_group_add_toggle_actions(packet_list_heading_action_group,
(GtkToggleActionEntry *)packet_list_heading_menu_toggle_action_entries,
G_N_ELEMENTS(packet_list_heading_menu_toggle_action_entries),
NULL);
ui_manager_packet_list_heading = gtk_ui_manager_new ();
gtk_ui_manager_insert_action_group (ui_manager_packet_list_heading,
packet_list_heading_action_group,
0);
gtk_ui_manager_add_ui_from_string (ui_manager_packet_list_heading,ui_desc_packet_list_heading_menu_popup, -1, &error);
if (error != NULL)
{
fprintf (stderr, "Warning: building Packet List Heading Pop-Up failed: %s\n",
error->message);
g_error_free (error);
error = NULL;
}
g_object_set_data(G_OBJECT(popup_menu_object), PM_PACKET_LIST_COL_KEY,
gtk_ui_manager_get_widget(ui_manager_packet_list_heading, "/PacketListHeadingPopup"));
popup_menu_list = g_slist_append((GSList *)popup_menu_list, ui_manager_packet_list_heading);
packet_list_action_group = gtk_action_group_new ("PacketListPopUpMenuActionGroup");
gtk_action_group_add_actions (packet_list_action_group,
(GtkActionEntry *)packet_list_menu_popup_action_entries,
G_N_ELEMENTS(packet_list_menu_popup_action_entries),
popup_menu_object);
gtk_action_group_add_actions (packet_list_action_group,
(GtkActionEntry *)apply_prepare_filter_action_entries,
G_N_ELEMENTS(apply_prepare_filter_action_entries),
popup_menu_object);
ui_manager_packet_list_menu = gtk_ui_manager_new ();
gtk_ui_manager_insert_action_group (ui_manager_packet_list_menu,
packet_list_action_group,
0);
gtk_ui_manager_add_ui_from_string (ui_manager_packet_list_menu, ui_desc_packet_list_menu_popup, -1, &error);
if (error != NULL)
{
fprintf (stderr, "Warning: building Packet List Pop-Up menu failed: %s\n",
error->message);
g_error_free (error);
error = NULL;
}
g_object_set_data(G_OBJECT(popup_menu_object), PM_PACKET_LIST_KEY,
gtk_ui_manager_get_widget(ui_manager_packet_list_menu, "/PacketListMenuPopup"));
popup_menu_list = g_slist_append((GSList *)popup_menu_list, ui_manager_packet_list_menu);
packet_list_details_action_group = gtk_action_group_new ("PacketListDetailsMenuPopUpActionGroup");
gtk_action_group_add_actions (packet_list_details_action_group,
(GtkActionEntry *)tree_view_menu_popup_action_entries,
G_N_ELEMENTS(tree_view_menu_popup_action_entries),
popup_menu_object);
gtk_action_group_add_actions (packet_list_details_action_group,
(GtkActionEntry *)apply_prepare_filter_action_entries,
G_N_ELEMENTS(apply_prepare_filter_action_entries),
popup_menu_object);
ui_manager_tree_view_menu = gtk_ui_manager_new ();
gtk_ui_manager_insert_action_group (ui_manager_tree_view_menu,
packet_list_details_action_group,
0);
gtk_ui_manager_add_ui_from_string (ui_manager_tree_view_menu, ui_desc_tree_view_menu_popup, -1, &error);
#if 0
gui_desc_file_name_and_path = get_ui_file_path("tree-view-ui.xml");
gtk_ui_manager_add_ui_from_file ( ui_manager_tree_view_menu, gui_desc_file_name_and_path, &error);
g_free (gui_desc_file_name_and_path);
#endif
if (error != NULL)
{
fprintf (stderr, "Warning: building TreeView Pop-Up menu failed: %s\n",
error->message);
g_error_free (error);
error = NULL;
}
g_object_set_data(G_OBJECT(popup_menu_object), PM_TREE_VIEW_KEY,
gtk_ui_manager_get_widget(ui_manager_tree_view_menu, "/TreeViewPopup"));
popup_menu_list = g_slist_append((GSList *)popup_menu_list, ui_manager_tree_view_menu);
packet_list_byte_menu_action_group = gtk_action_group_new ("PacketListByteMenuPopUpActionGroup");
gtk_action_group_add_radio_actions (packet_list_byte_menu_action_group,
(GtkRadioActionEntry *)bytes_menu_radio_action_entries,
G_N_ELEMENTS(bytes_menu_radio_action_entries),
recent.gui_bytes_view,
G_CALLBACK(select_bytes_view_cb),
popup_menu_object);
ui_manager_bytes_menu = gtk_ui_manager_new ();
gtk_ui_manager_insert_action_group (ui_manager_bytes_menu,
packet_list_byte_menu_action_group,
0);
gtk_ui_manager_add_ui_from_string (ui_manager_bytes_menu, ui_desc_bytes_menu_popup, -1, &error);
#if 0
gui_desc_file_name_and_path = get_ui_file_path("bytes-view-ui.xml");
gtk_ui_manager_add_ui_from_file ( ui_manager_bytes_menu, gui_desc_file_name_and_path, &error);
g_free (gui_desc_file_name_and_path);
#endif
if (error != NULL)
{
fprintf (stderr, "Warning: building Bytes Pop-Up menu failed: %s\n",
error->message);
g_error_free (error);
error = NULL;
}
g_object_unref(packet_list_byte_menu_action_group);
g_object_set_data(G_OBJECT(popup_menu_object), PM_BYTES_VIEW_KEY,
gtk_ui_manager_get_widget(ui_manager_bytes_menu, "/BytesMenuPopup"));
popup_menu_list = g_slist_append((GSList *)popup_menu_list, ui_manager_bytes_menu);
main_menu_bar_action_group = gtk_action_group_new ("MenuActionGroup");
gtk_action_group_add_actions (main_menu_bar_action_group,
main_menu_bar_entries,
G_N_ELEMENTS(main_menu_bar_entries),
NULL);
#ifdef HAVE_LIBPCAP
gtk_action_group_add_actions (main_menu_bar_action_group,
capture_menu_entries,
G_N_ELEMENTS(capture_menu_entries),
NULL);
#endif
gtk_action_group_add_actions (main_menu_bar_action_group,
(GtkActionEntry *)apply_prepare_filter_action_entries,
G_N_ELEMENTS(apply_prepare_filter_action_entries),
popup_menu_object);
gtk_action_group_add_toggle_actions(main_menu_bar_action_group,
main_menu_bar_toggle_action_entries,
G_N_ELEMENTS(main_menu_bar_toggle_action_entries),
NULL);
gtk_action_group_add_radio_actions (main_menu_bar_action_group,
main_menu_bar_radio_view_time_entries,
G_N_ELEMENTS(main_menu_bar_radio_view_time_entries),
recent.gui_time_format,
G_CALLBACK(timestamp_format_new_cb),
NULL);
gtk_action_group_add_radio_actions (main_menu_bar_action_group,
main_menu_bar_radio_view_time_fileformat_prec_entries,
G_N_ELEMENTS(main_menu_bar_radio_view_time_fileformat_prec_entries),
recent.gui_time_precision,
G_CALLBACK(timestamp_precision_new_cb),
NULL);
ui_manager_main_menubar = gtk_ui_manager_new ();
gtk_ui_manager_insert_action_group (ui_manager_main_menubar, main_menu_bar_action_group, 0);
gtk_ui_manager_add_ui_from_string (ui_manager_main_menubar,ui_desc_menubar, -1, &error);
if (error != NULL)
{
fprintf (stderr, "Warning: building main menubar failed: %s\n",
error->message);
g_error_free (error);
error = NULL;
}
g_object_unref(main_menu_bar_action_group);
gtk_window_add_accel_group (GTK_WINDOW(top_level),
gtk_ui_manager_get_accel_group(ui_manager_main_menubar));
merge_id = gtk_ui_manager_new_merge_id (ui_manager_main_menubar);
add_recent_items (merge_id, ui_manager_main_menubar);
merge_id = gtk_ui_manager_new_merge_id (ui_manager_main_menubar);
add_tap_plugins (merge_id, ui_manager_main_menubar);
statusbar_profiles_action_group = gtk_action_group_new ("StatusBarProfilesPopUpMenuActionGroup");
gtk_action_group_add_actions (statusbar_profiles_action_group,
(GtkActionEntry *)statusbar_profiles_menu_action_entries,
G_N_ELEMENTS(statusbar_profiles_menu_action_entries),
popup_menu_object);
ui_manager_statusbar_profiles_menu = gtk_ui_manager_new ();
gtk_ui_manager_insert_action_group (ui_manager_statusbar_profiles_menu,
statusbar_profiles_action_group,
0);
gtk_ui_manager_add_ui_from_string (ui_manager_statusbar_profiles_menu,ui_statusbar_profiles_menu_popup, -1, &error);
if (error != NULL)
{
fprintf (stderr, "Warning: building StatusBar Profiles Pop-Up failed: %s\n",
error->message);
g_error_free (error);
error = NULL;
}
g_object_unref(statusbar_profiles_action_group);
g_object_set_data(G_OBJECT(popup_menu_object), PM_STATUSBAR_PROFILES_KEY,
gtk_ui_manager_get_widget(ui_manager_statusbar_profiles_menu, "/ProfilesMenuPopup"));
popup_menu_list = g_slist_append((GSList *)popup_menu_list, ui_manager_statusbar_profiles_menu);
menu_dissector_filter(&cfile);
merge_menu_items(merge_menu_items_list);
ws_menubar_build_external_menus();
set_menus_for_capture_file(NULL);
#if 0
set_menu_sensitivity_old("/Edit/Cut", FALSE);
set_menu_sensitivity_old("/Edit/Copy", FALSE);
set_menu_sensitivity_old("/Edit/Paste", FALSE);
#endif
set_menus_for_captured_packets(FALSE);
set_menus_for_selected_packet(&cfile);
set_menus_for_selected_tree_row(&cfile);
set_menus_for_capture_in_progress(FALSE);
set_menus_for_file_set(TRUE, FALSE, FALSE);
name_res_action = gtk_action_group_get_action(main_menu_bar_action_group, "/View/NameResolution");
g_signal_connect (name_res_action, "activate", G_CALLBACK (menu_name_resolution_update_cb), NULL);
}
}
void
ws_add_build_menubar_items_callback(gpointer callback)
{
build_menubar_items_callback_list = g_list_append(build_menubar_items_callback_list, callback);
}
static void
ws_menubar_build_external_menus(void)
{
void (*callback)(gpointer);
while (build_menubar_items_callback_list != NULL) {
callback = (void (*)(gpointer))build_menubar_items_callback_list->data;
callback(ui_manager_main_menubar);
build_menubar_items_callback_list = g_list_next(build_menubar_items_callback_list);
}
}
static gint
insert_sorted_by_label(gconstpointer aparam, gconstpointer bparam)
{
const menu_item_t *a = (menu_item_t *)aparam;
const menu_item_t *b = (menu_item_t *)bparam;
return g_ascii_strcasecmp(a->label, b->label);
}
void register_menu_bar_menu_items(
const char *gui_path,
const char *name,
const gchar *stock_id,
const char *label,
const char *accelerator,
const gchar *tooltip,
gpointer callback,
gpointer callback_data,
gboolean enabled,
gboolean (*selected_packet_enabled)(frame_data *, epan_dissect_t *, gpointer callback_data),
gboolean (*selected_tree_row_enabled)(field_info *, gpointer callback_data))
{
menu_item_t *menu_item_data;
menu_item_data = g_new0(menu_item_t,1);
menu_item_data->gui_path = gui_path;
menu_item_data->name = name;
menu_item_data->label = label;
menu_item_data->stock_id = stock_id;
menu_item_data->accelerator = accelerator;
menu_item_data->tooltip = tooltip;
menu_item_data->callback = (GCallback)callback;
menu_item_data->callback_data = callback_data;
menu_item_data->enabled = enabled;
menu_item_data->selected_packet_enabled = selected_packet_enabled;
menu_item_data->selected_tree_row_enabled = selected_tree_row_enabled;
merge_menu_items_list = g_list_insert_sorted(merge_menu_items_list,
menu_item_data,
insert_sorted_by_label);
}
static const gchar*
make_menu_xml(const char *path)
{
GString *xml;
char **p;
char **tokens, **name_action_tokens;
const char *tok = path;
gchar *markup;
guint num_menus;
size_t len;
int i;
if (path == NULL) return NULL;
xml = g_string_new(XMENU_HEADER);
len = strlen("/Menubar");
if (g_ascii_strncasecmp(path, "/Menubar", len) == 0) {
path += len;
}
num_menus = 0;
tokens = g_strsplit(path, "/", XMENU_MAX_DEPTH);
for (p = tokens; (p != NULL) && (*p != NULL); p++) {
tok = g_strstrip(*p);
if (tok[0] == '\0') continue;
if (*(p+1) == NULL) break;
if (g_strcmp0(tok, "-") == 0) {
xml = g_string_append(xml, "<separator/>\n");
} else {
name_action_tokens = g_strsplit(tok, "|", 2);
if (name_action_tokens[1]) {
i = -1;
while (name_action_tokens[1][++i])
if (name_action_tokens[1][i] == '#')
name_action_tokens[1][i] = '/';
}
if (name_action_tokens[1])
markup = g_markup_printf_escaped("<menu name='%s' action='/%s'>\n", name_action_tokens[0], name_action_tokens[1]);
else
markup = g_markup_printf_escaped("<menu action='%s'>\n", tok);
xml = g_string_append(xml, markup);
g_free(markup);
g_strfreev(name_action_tokens);
num_menus++;
}
}
if ( (tok != NULL) ) {
if (g_strcmp0(tok, "-") == 0) {
xml = g_string_append(xml, "<separator/>\n");
} else {
markup = g_markup_printf_escaped("<menuitem action='%s'/>\n", tok);
xml = g_string_append(xml, markup);
g_free(markup);
}
}
g_strfreev(tokens);
for (; num_menus > 0; num_menus--) {
xml = g_string_append(xml, "</menu>");
}
xml = g_string_append(xml, XMENU_FOOTER);
markup = g_string_free(xml, FALSE);
return markup;
}
static GtkActionGroup*
make_menu_actions(char *path, const menu_item_t *menu_item_data)
{
GtkActionGroup *action_group;
GtkAction *action;
char **p;
char **tokens;
char *tok = path, *lbl;
action_group = gtk_action_group_new (path);
tokens = g_strsplit(path, "/", XMENU_MAX_DEPTH);
for (p = tokens; (p != NULL) && (*p != NULL); p++) {
tok = g_strstrip(*p);
if (tok[0] == '\0') continue;
if ( *(p+1) == NULL ) break;
if (g_strcmp0(tok, "-") != 0) {
lbl = strchr(tok, '|');
if (lbl != NULL) {
*lbl++ = '\0';
}
if ((lbl == NULL) || (*lbl == '\0')) {
lbl = tok;
}
action = (GtkAction *)g_object_new (
GTK_TYPE_ACTION,
"name", tok,
"label", lbl,
NULL
);
gtk_action_group_add_action (action_group, action);
g_object_unref (action);
}
}
if ( (tok != NULL) && (menu_item_data != NULL) ) {
action = (GtkAction *)g_object_new (
GTK_TYPE_ACTION,
"name", tok,
"label", menu_item_data->label,
"stock-id", menu_item_data->stock_id,
"tooltip", menu_item_data->tooltip,
"sensitive", menu_item_data->enabled,
NULL
);
if (menu_item_data->callback != NULL) {
g_signal_connect (
action,
"activate",
G_CALLBACK (menu_item_data->callback),
menu_item_data->callback_data
);
}
gtk_action_group_add_action (action_group, action);
g_object_unref (action);
}
g_strfreev(tokens);
return action_group;
}
static void
merge_menu_items(GList *lcl_merge_menu_items_list)
{
guint merge_id;
GtkActionGroup *action_group;
menu_item_t *menu_item_data;
GError *err;
const gchar *xml;
gchar *xpath;
while (lcl_merge_menu_items_list != NULL) {
menu_item_data = (menu_item_t *)lcl_merge_menu_items_list->data;
xpath = g_strdup_printf("%s/%s", menu_item_data->gui_path, menu_item_data->name);
xml = make_menu_xml(xpath);
if (xml != NULL) {
action_group = make_menu_actions(xpath, menu_item_data);
gtk_ui_manager_insert_action_group (ui_manager_main_menubar, action_group, 0);
err = NULL;
merge_id = gtk_ui_manager_add_ui_from_string (ui_manager_main_menubar, xml, -1, &err);
if (err != NULL) {
fprintf (stderr, "Warning: building menus failed: %s\n",
err->message);
g_error_free (err);
gtk_ui_manager_remove_ui (ui_manager_main_menubar, merge_id);
gtk_ui_manager_remove_action_group (ui_manager_main_menubar, action_group);
}
g_free ((gchar*)xml);
g_object_unref (action_group);
}
g_free(xpath);
lcl_merge_menu_items_list = g_list_next(lcl_merge_menu_items_list);
}
}
const char *
stat_group_name(register_stat_group_t group)
{
static const value_string group_name_vals[] = {
{REGISTER_ANALYZE_GROUP_UNSORTED, "/Menubar/AnalyzeMenu|Analyze"},
{REGISTER_ANALYZE_GROUP_CONVERSATION_FILTER, "/Menubar/AnalyzeMenu|Analyze/ConversationFilterMenu|Analyze#ConversationFilter"},
{REGISTER_STAT_GROUP_UNSORTED, "/Menubar/StatisticsMenu|Statistics"},
{REGISTER_STAT_GROUP_GENERIC, "/Menubar/StatisticsMenu|Statistics"},
{REGISTER_STAT_GROUP_CONVERSATION_LIST, "/Menubar/StatisticsMenu|Statistics/ConversationListMenu|Statistics#ConversationList"},
{REGISTER_STAT_GROUP_ENDPOINT_LIST, "/Menubar/StatisticsMenu|Statistics/EndpointListMenu|Statistics#EndpointList"},
{REGISTER_STAT_GROUP_RESPONSE_TIME, "/Menubar/StatisticsMenu|Statistics/ServiceResponseTimeMenu|Statistics#ServiceResponseTime"},
{REGISTER_STAT_GROUP_TELEPHONY, "/Menubar/TelephonyMenu|Telephony"},
{REGISTER_STAT_GROUP_TELEPHONY_GSM, "/Menubar/TelephonyMenu|Telephony/GSM|Telephony#GSM"},
{REGISTER_STAT_GROUP_TELEPHONY_LTE, "/Menubar/TelephonyMenu|Telephony/LTEmenu|Telephony#LTE"},
{REGISTER_STAT_GROUP_TELEPHONY_SCTP, "/Menubar/TelephonyMenu|Telephony/SCTPmenu|Telephony#SCTP"},
{REGISTER_TOOLS_GROUP_UNSORTED, "/Menubar/ToolsMenu|Tools"},
{0, NULL}
};
return val_to_str_const(group, group_name_vals, "/Menubar/ToolsMenu|Tools");
}
static void
set_menu_sensitivity(GtkUIManager *ui_manager, const gchar *path, gint val)
{
GtkAction *action;
action = gtk_ui_manager_get_action(ui_manager, path);
if(!action){
fprintf (stderr, "Warning: set_menu_sensitivity couldn't find action path= %s\n",
path);
return;
}
gtk_action_set_sensitive (action, val);
}
static void
set_menu_object_data_meat(GtkUIManager *ui_manager, const gchar *path, const gchar *key, gpointer data)
{
GtkWidget *menu = NULL;
if ((menu = gtk_ui_manager_get_widget(ui_manager, path)) != NULL){
g_object_set_data(G_OBJECT(menu), key, data);
}else{
#if 0
g_warning("set_menu_object_data_meat: no menu, path: %s",path);
#endif
}
}
void
set_menu_object_data (const gchar *path, const gchar *key, gpointer data)
{
if (strncmp (path,"/Menubar",8) == 0){
set_menu_object_data_meat(ui_manager_main_menubar, path, key, data);
}else if (strncmp (path,"/PacketListMenuPopup",20) == 0){
set_menu_object_data_meat(ui_manager_packet_list_menu, path, key, data);
}else if (strncmp (path,"/TreeViewPopup",14) == 0){
set_menu_object_data_meat(ui_manager_tree_view_menu, path, key, data);
}else if (strncmp (path,"/BytesMenuPopup",15) == 0){
set_menu_object_data_meat(ui_manager_bytes_menu, path, key, data);
}else if (strncmp (path,"/ProfilesMenuPopup",18) == 0){
set_menu_object_data_meat(ui_manager_statusbar_profiles_menu, path, key, data);
}
}
static GList *
remove_present_file_name(GList *recent_files_list, const gchar *cf_name)
{
GList *li;
gchar *widget_cf_name;
for (li = g_list_first(recent_files_list); li; li = li->next) {
widget_cf_name = (gchar *)li->data;
if (
#ifdef _WIN32
g_ascii_strncasecmp(widget_cf_name, cf_name, 1000) == 0){
#else
strncmp(widget_cf_name, cf_name, 1000) == 0 ){
#endif
recent_files_list = g_list_remove(recent_files_list,widget_cf_name);
}
}
return recent_files_list;
}
static void
recent_changed_cb (GtkUIManager *ui_manager,
gpointer user_data _U_)
{
guint merge_id;
GList *action_groups, *l;
merge_id = GPOINTER_TO_UINT (g_object_get_data (G_OBJECT (ui_manager),
"recent-files-merge-id"));
gtk_ui_manager_remove_ui (ui_manager, merge_id);
action_groups = gtk_ui_manager_get_action_groups (ui_manager);
for (l = action_groups; l != NULL; l = l->next)
{
GtkActionGroup *group = (GtkActionGroup *)l->data;
if (strcmp (gtk_action_group_get_name (group), "recent-files-group") == 0){
gtk_ui_manager_remove_action_group (ui_manager, group);
break;
}
}
merge_id = gtk_ui_manager_new_merge_id (ui_manager);
add_recent_items (merge_id, ui_manager);
}
static void
recent_clear_cb(GtkAction *action _U_, gpointer user_data _U_)
{
GtkWidget *submenu_recent_files;
GList *recent_files_list;
submenu_recent_files = gtk_ui_manager_get_widget(ui_manager_main_menubar, MENU_RECENT_FILES_PATH);
recent_files_list = (GList *)g_object_get_data(G_OBJECT(submenu_recent_files), "recent-files-list");
g_list_free(recent_files_list);
recent_files_list = NULL;
g_object_set_data(G_OBJECT(submenu_recent_files), "recent-files-list", recent_files_list);
recent_changed_cb(ui_manager_main_menubar, NULL);
}
static void
add_recent_items (guint merge_id, GtkUIManager *ui_manager)
{
GtkActionGroup *action_group;
GtkAction *action;
GtkWidget *submenu_recent_files;
GList *items, *l;
gchar *action_name;
guint i;
main_welcome_reset_recent_capture_files();
action_group = gtk_action_group_new ("recent-files-group");
submenu_recent_files = gtk_ui_manager_get_widget(ui_manager, MENU_RECENT_FILES_PATH);
if(!submenu_recent_files){
g_warning("add_recent_items: No submenu_recent_files found, path= MENU_RECENT_FILES_PATH");
}
items = (GList *)g_object_get_data(G_OBJECT(submenu_recent_files), "recent-files-list");
gtk_ui_manager_insert_action_group (ui_manager, action_group, 0);
g_object_set_data (G_OBJECT (ui_manager),
"recent-files-merge-id", GUINT_TO_POINTER (merge_id));
if (!items){
action = (GtkAction *)g_object_new (GTK_TYPE_ACTION,
"name", "recent-info-empty",
"label", "No recently used files",
"sensitive", FALSE,
NULL);
gtk_action_group_add_action (action_group, action);
gtk_action_set_sensitive(action, FALSE);
g_object_unref (action);
gtk_ui_manager_add_ui (ui_manager, merge_id,
"/Menubar/FileMenu/OpenRecent/RecentFiles",
"recent-info-empty",
"recent-info-empty",
GTK_UI_MANAGER_MENUITEM,
FALSE);
return;
}
for (i = 0, l = items;
i < prefs.gui_recent_files_count_max && l != NULL;
i +=1, l = l->next)
{
gchar *item_name = (gchar *)l->data;
action_name = g_strdup_printf ("recent-info-%u", i);
action = (GtkAction *)g_object_new (GTK_TYPE_ACTION,
"name", action_name,
"label", item_name,
"stock_id", WIRESHARK_STOCK_SAVE,
NULL);
g_signal_connect (action, "activate",
G_CALLBACK (menu_open_recent_file_cmd_cb), NULL);
#if !GTK_CHECK_VERSION(2,16,0)
g_object_set_data (G_OBJECT (action), "FileName", item_name);
#endif
gtk_action_group_add_action (action_group, action);
g_object_unref (action);
gtk_ui_manager_add_ui (ui_manager, merge_id,
"/Menubar/FileMenu/OpenRecent/RecentFiles",
action_name,
action_name,
GTK_UI_MANAGER_MENUITEM,
FALSE);
main_welcome_add_recent_capture_file(item_name, G_OBJECT(action));
g_free (action_name);
}
gtk_ui_manager_add_ui (ui_manager, merge_id,
"/Menubar/FileMenu/OpenRecent/RecentFiles",
"separator-recent-info",
NULL,
GTK_UI_MANAGER_SEPARATOR,
FALSE);
action = (GtkAction *)g_object_new (GTK_TYPE_ACTION,
"name", "clear-recent-info",
"label", "Clear the recent files list",
"stock_id", GTK_STOCK_CLEAR,
NULL);
g_signal_connect (action, "activate",
G_CALLBACK (recent_clear_cb), NULL);
gtk_action_group_add_action (action_group, action);
g_object_unref (action);
gtk_ui_manager_add_ui (ui_manager, merge_id,
"/Menubar/FileMenu/OpenRecent/RecentFiles",
"clear-recent-info",
"clear-recent-info",
GTK_UI_MANAGER_MENUITEM,
FALSE);
}
static void
add_tap_plugins (guint merge_id, GtkUIManager *ui_manager)
{
GtkActionGroup *action_group;
GtkAction *action;
GtkWidget *submenu_statistics;
GList *cfg_list;
GList *iter;
gchar *action_name;
action_group = gtk_action_group_new ("tap-plugins-group");
submenu_statistics = gtk_ui_manager_get_widget(ui_manager_main_menubar, MENU_STATISTICS_PATH);
if(!submenu_statistics){
g_warning("add_tap_plugins: No submenu_statistics found, path= MENU_STATISTICS_PATH");
return;
}
gtk_ui_manager_insert_action_group (ui_manager_main_menubar, action_group, 0);
g_object_set_data (G_OBJECT (ui_manager_main_menubar),
"tap-plugins-merge-id", GUINT_TO_POINTER (merge_id));
cfg_list = stats_tree_get_cfg_list();
iter = g_list_first(cfg_list);
while (iter) {
stats_tree_cfg *cfg = (stats_tree_cfg*)iter->data;
if (cfg->plugin) {
action_name = g_strdup_printf(MENU_STATISTICS_PATH "/%s", cfg->abbr);
action = (GtkAction *)g_object_new (GTK_TYPE_ACTION,
"name", action_name,
"label", cfg->name,
NULL);
g_signal_connect (action, "activate", G_CALLBACK (gtk_stats_tree_cb), NULL);
gtk_action_group_add_action (action_group, action);
g_object_unref (action);
gtk_ui_manager_add_ui (ui_manager, merge_id,
MENU_STATISTICS_PATH,
action_name,
action_name,
GTK_UI_MANAGER_MENUITEM,
FALSE);
g_free (action_name);
}
iter = g_list_next(iter);
}
g_list_free(cfg_list);
}
void
menu_open_filename(gchar *cf_name)
{
GtkWidget *submenu_recent_files;
int err;
GList *recent_files_list;
submenu_recent_files = gtk_ui_manager_get_widget(ui_manager_main_menubar, MENU_RECENT_FILES_PATH);
if(!submenu_recent_files){
g_warning("menu_open_filename: No submenu_recent_files found, path= MENU_RECENT_FILES_PATH");
}
recent_files_list = (GList *)g_object_get_data(G_OBJECT(submenu_recent_files), "recent-files-list");
if (cf_open(&cfile, cf_name, FALSE, &err) == CF_OK) {
cf_read(&cfile, FALSE);
}else{
recent_files_list = remove_present_file_name(recent_files_list, cf_name);
g_object_set_data(G_OBJECT(submenu_recent_files), "recent-files-list", recent_files_list);
recent_changed_cb(ui_manager_main_menubar, NULL);
}
}
static void
menu_open_recent_file_cmd(GtkAction *action)
{
GtkWidget *submenu_recent_files;
GList *recent_files_list;
const gchar *cf_name;
int err;
#if GTK_CHECK_VERSION(2,16,0)
cf_name = gtk_action_get_label(action);
#else
cf_name = (const gchar *)g_object_get_data(G_OBJECT(action), "FileName");
#endif
if (cf_open(&cfile, cf_name, FALSE, &err) == CF_OK) {
cf_read(&cfile, FALSE);
} else {
submenu_recent_files = gtk_ui_manager_get_widget(ui_manager_main_menubar, MENU_RECENT_FILES_PATH);
recent_files_list = (GList *)g_object_get_data(G_OBJECT(submenu_recent_files), "recent-files-list");
recent_files_list = remove_present_file_name(recent_files_list, cf_name);
g_object_set_data(G_OBJECT(submenu_recent_files), "recent-files-list", recent_files_list);
recent_changed_cb(ui_manager_main_menubar, NULL);
}
}
static void
menu_open_recent_file_cmd_cb(GtkAction *action, gpointer data _U_)
{
if (do_file_close(&cfile, FALSE, " before opening a new capture file"))
menu_open_recent_file_cmd(action);
}
static void
add_menu_recent_capture_file_absolute(const gchar *cf_name)
{
GtkWidget *submenu_recent_files;
GList *li;
gchar *widget_cf_name;
gchar *normalized_cf_name;
guint cnt;
GList *recent_files_list;
normalized_cf_name = g_strdup(cf_name);
#ifdef _WIN32
g_strdelimit(normalized_cf_name, "/", '\\');
#endif
submenu_recent_files = gtk_ui_manager_get_widget(ui_manager_main_menubar, MENU_RECENT_FILES_PATH);
if(!submenu_recent_files){
g_warning("add_menu_recent_capture_file_absolute: No submenu_recent_files found, path= MENU_RECENT_FILES_PATH");
g_free(normalized_cf_name);
return;
}
recent_files_list = (GList *)g_object_get_data(G_OBJECT(submenu_recent_files), "recent-files-list");
cnt = 1;
for (li = g_list_first(recent_files_list); li; cnt++) {
widget_cf_name = (gchar *)li->data;
li = li->next;
if (
#ifdef _WIN32
g_ascii_strncasecmp(widget_cf_name, normalized_cf_name, 1000) == 0 ||
#else
strncmp(widget_cf_name, normalized_cf_name, 1000) == 0 ||
#endif
cnt >= prefs.gui_recent_files_count_max) {
recent_files_list = g_list_remove(recent_files_list,widget_cf_name);
cnt--;
}
}
recent_files_list = g_list_prepend(recent_files_list, normalized_cf_name);
g_object_set_data(G_OBJECT(submenu_recent_files), "recent-files-list", recent_files_list);
recent_changed_cb( ui_manager_main_menubar, NULL);
}
void
add_menu_recent_capture_file(const gchar *cf_name)
{
gchar *curr;
gchar *absolute;
if (g_path_is_absolute(cf_name)) {
add_menu_recent_capture_file_absolute(cf_name);
return;
}
curr = g_get_current_dir();
absolute = g_strdup_printf("%s%s%s", curr, G_DIR_SEPARATOR_S, cf_name);
add_menu_recent_capture_file_absolute(absolute);
g_free(curr);
g_free(absolute);
}
void
menu_recent_file_write_all(FILE *rf)
{
GtkWidget *submenu_recent_files;
GList *children;
GList *child;
gchar *cf_name;
GList *recent_files_list, *list;
submenu_recent_files = gtk_ui_manager_get_widget(ui_manager_main_menubar, MENU_RECENT_FILES_PATH);
if(!submenu_recent_files){
g_warning("menu_recent_file_write_all: No submenu_recent_files found, path= MENU_RECENT_FILES_PATH");
}
recent_files_list = (GList *)g_object_get_data(G_OBJECT(submenu_recent_files), "recent-files-list");
list = g_list_last(recent_files_list);
while (list != NULL) {
cf_name = (gchar *)list->data;
if (cf_name) {
if(u3_active())
fprintf (rf, RECENT_KEY_CAPTURE_FILE ": %s\n", u3_contract_device_path(cf_name));
else
fprintf (rf, RECENT_KEY_CAPTURE_FILE ": %s\n", cf_name);
}
list = g_list_previous(list);
}
g_list_free(recent_files_list);
return;
children = gtk_container_get_children(GTK_CONTAINER(submenu_recent_files));
child = g_list_last(children);
while (child != NULL) {
cf_name = (gchar *)g_object_get_data(G_OBJECT(child->data), MENU_RECENT_FILES_KEY);
if (cf_name) {
if(u3_active())
fprintf (rf, RECENT_KEY_CAPTURE_FILE ": %s\n", u3_contract_device_path(cf_name));
else
fprintf (rf, RECENT_KEY_CAPTURE_FILE ": %s\n", cf_name);
}
child = g_list_previous(child);
}
g_list_free(children);
}
void
menu_name_resolution_changed(void)
{
GtkWidget *menu;
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/NameResolution/EnableforMACLayer");
if(!menu){
g_warning("menu_name_resolution_changed: No menu found, path= /Menubar/ViewMenu/NameResolution/EnableforMACLayer");
}
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), gbl_resolv_flags.mac_name);
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/NameResolution/EnableforNetworkLayer");
if(!menu){
g_warning("menu_name_resolution_changed: No menu found, path= /Menubar/ViewMenu/NameResolution/EnableforNetworkLayer");
}
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), gbl_resolv_flags.network_name);
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/NameResolution/EnableforTransportLayer");
if(!menu){
g_warning("menu_name_resolution_changed: No menu found, path= /Menubar/ViewMenu/NameResolution/EnableforTransportLayer");
}
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), gbl_resolv_flags.transport_name);
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/NameResolution/UseExternalNetworkNameResolver");
if(!menu){
g_warning("menu_name_resolution_changed: No menu found, path= /Menubar/ViewMenu/NameResolution/UseExternalNetworkNameResolver");
}
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), gbl_resolv_flags.use_external_net_name_resolver);
}
static void
menu_name_resolution_update_cb(GtkAction *action _U_, gpointer data _U_)
{
menu_name_resolution_changed();
}
static void
name_resolution_cb(GtkWidget *w, gpointer d _U_, gboolean* res_flag)
{
if (gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(w))) {
*res_flag = TRUE;
} else {
*res_flag = FALSE;
}
packet_list_recreate();
redraw_packet_bytes_all();
}
void
menu_auto_scroll_live_changed(gboolean auto_scroll_live_in)
{
GtkWidget *menu;
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/AutoScrollinLiveCapture");
if(!menu){
g_warning("menu_auto_scroll_live_changed: No menu found, path= /Menubar/ViewMenu/AutoScrollinLiveCapture");
}
if( ((gboolean) gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(menu)) != auto_scroll_live_in) ) {
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), auto_scroll_live_in);
}
}
void
menu_colorize_changed(gboolean packet_list_colorize)
{
GtkWidget *menu;
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/ColorizePacketList");
if(!menu){
g_warning("menu_colorize_changed: No menu found, path= /Menubar/ViewMenu/ColorizePacketList");
}
if( (gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(menu)) != packet_list_colorize) ) {
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), packet_list_colorize);
}
}
static void
colorize_cb(GtkWidget *w, gpointer d _U_)
{
main_colorize_changed(gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(w)));
}
void
menu_recent_read_finished(void)
{
GtkWidget *menu;
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/MainToolbar");
if(!menu){
g_warning("menu_recent_read_finished: No menu found, path= /Menubar/ViewMenu/MainToolbar");
}else{
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), recent.main_toolbar_show);
}
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/FilterToolbar");
if(!menu){
g_warning("menu_recent_read_finished: No menu found, path= /Menubar/ViewMenu/FilterToolbar");
}else{
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), recent.filter_toolbar_show);
};
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/WirelessToolbar");
if(!menu){
g_warning("menu_recent_read_finished: No menu found, path= /Menubar/ViewMenu/WirelessToolbar");
}else{
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), recent.wireless_toolbar_show);
}
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/StatusBar");
if(!menu){
g_warning("menu_recent_read_finished: No menu found, path= /Menubar/ViewMenu/StatusBar");
}else{
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), recent.statusbar_show);
}
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/PacketList");
if(!menu){
g_warning("menu_recent_read_finished: No menu found, path= /Menubar/ViewMenu/PacketList");
}else{
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), recent.packet_list_show);
}
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/PacketDetails");
if(!menu){
g_warning("menu_recent_read_finished: No menu found, path= /Menubar/ViewMenu/PacketDetails");
}else{
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), recent.tree_view_show);
}
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/PacketBytes");
if(!menu){
g_warning("menu_recent_read_finished: No menu found, path= /Menubar/ViewMenu/PacketBytes");
}else{
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), recent.byte_view_show);
}
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/ColorizePacketList");
if(!menu){
g_warning("menu_recent_read_finished: No menu found, path= /Menubar/ViewMenu/ColorizePacketList");
}else{
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), recent.packet_list_colorize);
}
menu_name_resolution_changed();
#ifdef HAVE_LIBPCAP
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/AutoScrollinLiveCapture");
if(!menu){
g_warning("menu_recent_read_finished: No menu found, path= /Menubar/ViewMenu/AutoScrollinLiveCapture");
}else{
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), auto_scroll_live);
}
#endif
main_widgets_rearrange();
if (timestamp_get_type() != TS_NOT_SET) {
recent.gui_time_format = timestamp_get_type();
}
timestamp_set_type(recent.gui_time_format);
cf_timestamp_auto_precision(&cfile);
packet_list_queue_draw();
if (recent.gui_time_precision == TS_PREC_AUTO) {
timestamp_set_precision(TS_PREC_AUTO_SEC);
} else {
timestamp_set_precision(recent.gui_time_precision);
}
cf_timestamp_auto_precision(&cfile);
packet_list_queue_draw();
if (timestamp_get_seconds_type() != TS_SECONDS_NOT_SET) {
recent.gui_seconds_format = timestamp_get_seconds_type();
}
menu = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/TimeDisplayFormat/DisplaySecondsWithHoursAndMinutes");
if(!menu){
g_warning("menu_recent_read_finished: No menu found, path= /Menubar/ViewMenu/TimeDisplayFormat/DisplaySecondsWithHoursAndMinutes");
}
switch (recent.gui_seconds_format) {
case TS_SECONDS_DEFAULT:
recent.gui_seconds_format = (ts_seconds_type)-1;
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), TRUE);
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), FALSE);
break;
case TS_SECONDS_HOUR_MIN_SEC:
recent.gui_seconds_format = (ts_seconds_type)-1;
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), FALSE);
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), TRUE);
break;
default:
g_assert_not_reached();
}
main_colorize_changed(recent.packet_list_colorize);
}
gboolean
popup_menu_handler(GtkWidget *widget, GdkEvent *event, gpointer data)
{
GtkWidget *menu = (GtkWidget *)data;
GdkEventButton *event_button = NULL;
gint row, column;
if(widget == NULL || event == NULL || data == NULL) {
return FALSE;
}
if (widget == g_object_get_data(G_OBJECT(popup_menu_object), E_MPACKET_LIST_KEY) &&
((GdkEventButton *)event)->button != 1) {
gint physical_row;
if (packet_list_get_event_row_column((GdkEventButton *)event, &physical_row, &row, &column)) {
g_object_set_data(G_OBJECT(popup_menu_object), E_MPACKET_LIST_ROW_KEY,
GINT_TO_POINTER(row));
g_object_set_data(G_OBJECT(popup_menu_object), E_MPACKET_LIST_COL_KEY,
GINT_TO_POINTER(column));
packet_list_set_selected_row(row);
}
}
if (widget == tree_view_gbl) {
tree_view_select(widget, (GdkEventButton *) event);
}
if(event->type == GDK_BUTTON_PRESS) {
event_button = (GdkEventButton *) event;
if(event_button->button == 3) {
gtk_menu_popup(GTK_MENU(menu), NULL, NULL, NULL, NULL,
event_button->button,
event_button->time);
g_signal_stop_emission_by_name(widget, "button_press_event");
return TRUE;
}
}
if(widget == get_notebook_bv_ptr(byte_nb_ptr_gbl)) {
byte_view_select(widget, (GdkEventButton *) event);
}
if (widget == tree_view_gbl && event->type == GDK_2BUTTON_PRESS) {
GtkTreePath *path;
if (gtk_tree_view_get_path_at_pos(GTK_TREE_VIEW(widget),
(gint) (((GdkEventButton *)event)->x),
(gint) (((GdkEventButton *)event)->y),
&path, NULL, NULL, NULL))
{
if (gtk_tree_view_row_expanded(GTK_TREE_VIEW(widget), path))
gtk_tree_view_collapse_row(GTK_TREE_VIEW(widget), path);
else
gtk_tree_view_expand_row(GTK_TREE_VIEW(widget), path,
FALSE);
gtk_tree_path_free(path);
}
}
return FALSE;
}
void
set_menus_for_capture_file(capture_file *cf)
{
if (cf == NULL || cf->state == FILE_READ_IN_PROGRESS) {
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/Merge", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/Close", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/Save", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/SaveAs", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportSpecifiedPackets", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportPacketDissections", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportSelectedPacketBytes", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportSSLSessionKeys", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportObjects", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportPDUs", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/ViewMenu/Reload", FALSE);
} else {
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/Merge", cf_can_write_with_wiretap(cf));
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/Close", TRUE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/Save",
cf_can_save(cf));
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/SaveAs",
cf_can_save_as(cf));
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportSpecifiedPackets",
cf_can_write_with_wiretap(cf));
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportPacketDissections", TRUE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportSelectedPacketBytes", TRUE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportSSLSessionKeys", TRUE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportObjects", TRUE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportPDUs", TRUE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/ViewMenu/Reload", TRUE);
}
}
void
set_menus_for_capture_in_progress(gboolean capture_in_progress)
{
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/Quit",
TRUE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/Open",
!capture_in_progress);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/OpenRecent",
!capture_in_progress);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportPacketDissections",
capture_in_progress);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportSelectedPacketBytes",
capture_in_progress);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportSSLSessionKeys",
capture_in_progress);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/ExportObjects",
capture_in_progress);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/Set",
!capture_in_progress);
set_menu_sensitivity(ui_manager_packet_list_heading, "/PacketListHeadingPopup/SortAscending",
!capture_in_progress);
set_menu_sensitivity(ui_manager_packet_list_heading, "/PacketListHeadingPopup/SortDescending",
!capture_in_progress);
set_menu_sensitivity(ui_manager_packet_list_heading, "/PacketListHeadingPopup/NoSorting",
!capture_in_progress);
#ifdef HAVE_LIBPCAP
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/CaptureMenu/Options",
!capture_in_progress);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/CaptureMenu/Start",
!capture_in_progress && global_capture_opts.num_selected > 0);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/CaptureMenu/Stop",
capture_in_progress);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/CaptureMenu/Restart",
capture_in_progress);
#endif
}
void
set_menus_capture_start_sensitivity(gboolean enable)
{
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/CaptureMenu/Start",
enable);
}
void
set_menus_for_capture_stopping(void)
{
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/Quit",
FALSE);
#ifdef HAVE_LIBPCAP
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/CaptureMenu/Stop",
FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/CaptureMenu/Restart",
FALSE);
#endif
}
void
set_menus_for_captured_packets(gboolean have_captured_packets)
{
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/Print",
have_captured_packets);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/Print",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/FindPacket",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/FindNext",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/FindPrevious",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/ViewMenu/ZoomIn",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/ViewMenu/ZoomOut",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/ViewMenu/NormalSize",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/GoMenu/Goto",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/GoMenu/PreviousPacket",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/GoMenu/NextPacket",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/GoMenu/FirstPacket",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/GoMenu/LastPacket",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/GoMenu/PreviousPacketInConversation",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/GoMenu/NextPacketInConversation",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/StatisticsMenu/Summary",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/StatisticsMenu/ShowCommentsSummary",
have_captured_packets);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/StatisticsMenu/ProtocolHierarchy",
have_captured_packets);
}
void
set_menus_for_selected_packet(capture_file *cf)
{
GList *list_entry = dissector_filter_list;
guint i = 0;
gboolean properties = FALSE;
const char *abbrev = NULL;
char *prev_abbrev;
gboolean is_ssl = epan_dissect_packet_contains_field(cf->edt, "ssl");
gboolean frame_selected = cf->current_frame != NULL;
gboolean have_marked = frame_selected && cf->marked_count > 0;
gboolean another_is_marked = have_marked &&
!(cf->marked_count == 1 && cf->current_frame->flags.marked);
gboolean have_time_ref = cf->ref_time_count > 0;
gboolean another_is_time_ref = frame_selected && have_time_ref &&
!(cf->ref_time_count == 1 && cf->current_frame->flags.ref_time);
gboolean tcp_packet_selected = FALSE;
tcp_packet_selected = frame_selected && (cf->edt->pi.ipproto == IP_PROTO_TCP);
if (cfile.edt && cfile.edt->tree) {
GPtrArray *ga;
header_field_info *hfinfo;
field_info *v;
guint ii;
ga = proto_all_finfos(cfile.edt->tree);
for (ii = ga->len - 1; ii > 0 ; ii -= 1) {
v = (field_info *)g_ptr_array_index (ga, ii);
hfinfo = v->hfinfo;
if (!g_str_has_prefix(hfinfo->abbrev, "text") &&
!g_str_has_prefix(hfinfo->abbrev, "_ws.expert") &&
!g_str_has_prefix(hfinfo->abbrev, "_ws.malformed")) {
if (hfinfo->parent == -1) {
abbrev = hfinfo->abbrev;
} else {
abbrev = proto_registrar_get_abbrev(hfinfo->parent);
}
properties = prefs_is_registered_protocol(abbrev);
break;
}
}
}
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/MarkPacket",
frame_selected);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/MarkPacket",
frame_selected);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/MarkAllDisplayedPackets",
cf->displayed_count > 0);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/UnmarkAllDisplayedPackets",
have_marked);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/FindNextMark",
another_is_marked);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/FindPreviousMark",
another_is_marked);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/IgnorePacket",
frame_selected);
#ifdef WANT_PACKET_EDITOR
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/EditPacket",
frame_selected);
#endif
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/AddEditPktComment",
frame_selected && wtap_dump_can_write(cf->linktypes, WTAP_COMMENT_PER_PACKET));
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/IgnorePacket",
frame_selected);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/IgnoreAllDisplayedPackets",
cf->displayed_count > 0 && cf->displayed_count != cf->count);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/Un-IgnoreAllPackets",
cf->ignored_count > 0);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/SetTimeReference",
frame_selected);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/Un-TimeReferenceAllPackets",
have_time_ref);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/TimeShift",
cf->count > 0);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/SetTimeReference",
frame_selected);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/FindNextTimeReference",
another_is_time_ref);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/FindPreviousTimeReference",
another_is_time_ref);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/ViewMenu/ResizeAllColumns",
frame_selected);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/ViewMenu/CollapseAll",
frame_selected);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/CollapseAll",
frame_selected);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/ViewMenu/ExpandAll",
frame_selected);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/ExpandAll",
frame_selected);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/ViewMenu/ColorizeConversation",
frame_selected);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/ViewMenu/ResetColoring1-10",
tmp_color_filters_used());
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/ViewMenu/ShowPacketinNewWindow",
frame_selected);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ShowPacketinNewWindow",
frame_selected);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ManuallyResolveAddress",
frame_selected ? ((cf->edt->pi.ethertype == ETHERTYPE_IP)||(cf->edt->pi.ethertype == ETHERTYPE_IPv6)) : FALSE);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/SCTP",
frame_selected ? (cf->edt->pi.ipproto == IP_PROTO_SCTP) : FALSE);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/FollowTCPStream",
tcp_packet_selected);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/FollowTCPStream",
tcp_packet_selected);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/FollowUDPStream",
frame_selected ? (cf->edt->pi.ipproto == IP_PROTO_UDP) : FALSE);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/FollowSSLStream",
frame_selected ? is_ssl : FALSE);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/FollowSSLStream",
frame_selected ? is_ssl : FALSE);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ConversationFilter",
frame_selected);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ConversationFilter/Ethernet",
frame_selected ? (cf->edt->pi.dl_src.type == AT_ETHER) : FALSE);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ConversationFilter/IP",
frame_selected ? ((cf->edt->pi.ethertype == ETHERTYPE_IP)||(cf->edt->pi.ethertype == ETHERTYPE_IPv6)) : FALSE);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ConversationFilter/TCP",
tcp_packet_selected);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ConversationFilter/UDP",
frame_selected ? (cf->edt->pi.ipproto == IP_PROTO_UDP) : FALSE);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/FollowUDPStream",
frame_selected ? (cf->edt->pi.ipproto == IP_PROTO_UDP) : FALSE);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ConversationFilter/PN-CBA",
frame_selected ? (cf->edt->pi.profinet_type != 0 && cf->edt->pi.profinet_type < 10) : FALSE);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ColorizeConversation",
frame_selected);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ColorizeConversation/Ethernet",
frame_selected ? (cf->edt->pi.dl_src.type == AT_ETHER) : FALSE);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ColorizeConversation/IP",
frame_selected ? ((cf->edt->pi.ethertype == ETHERTYPE_IP)||(cf->edt->pi.ethertype == ETHERTYPE_IPv6)) : FALSE);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ColorizeConversation/TCP",
tcp_packet_selected);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ColorizeConversation/UDP",
frame_selected ? (cf->edt->pi.ipproto == IP_PROTO_UDP) : FALSE);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ColorizeConversation/PN-CBA",
frame_selected ? (cf->edt->pi.profinet_type != 0 && cf->edt->pi.profinet_type < 10) : FALSE);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/DecodeAs",
frame_selected && decode_as_ok());
if (properties) {
prev_abbrev = (char *)g_object_get_data(G_OBJECT(ui_manager_packet_list_menu), "menu_abbrev");
if (!prev_abbrev || (strcmp(prev_abbrev, abbrev) != 0)) {
module_t *prefs_module_p = prefs_find_module(abbrev);
rebuild_protocol_prefs_menu(prefs_module_p, properties, ui_manager_packet_list_menu, "/PacketListMenuPopup/ProtocolPreferences");
g_object_set_data(G_OBJECT(ui_manager_packet_list_menu), "menu_abbrev", g_strdup(abbrev));
g_free (prev_abbrev);
}
}
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ProtocolPreferences",
properties);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/DecodeAs",
frame_selected && decode_as_ok());
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/Copy",
frame_selected);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/ApplyAsFilter",
frame_selected);
set_menu_sensitivity(ui_manager_packet_list_menu, "/PacketListMenuPopup/PrepareaFilter",
frame_selected);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/ResolveName",
frame_selected && (gbl_resolv_flags.mac_name || gbl_resolv_flags.network_name ||
gbl_resolv_flags.transport_name || gbl_resolv_flags.concurrent_dns));
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/AnalyzeMenu/FollowTCPStream",
tcp_packet_selected);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/AnalyzeMenu/FollowUDPStream",
frame_selected ? (cf->edt->pi.ipproto == IP_PROTO_UDP) : FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/AnalyzeMenu/FollowSSLStream",
frame_selected ? is_ssl : FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/AnalyzeMenu/DecodeAs",
frame_selected && decode_as_ok());
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/ViewMenu/NameResolution/ResolveName",
frame_selected && (gbl_resolv_flags.mac_name || gbl_resolv_flags.network_name ||
gbl_resolv_flags.transport_name || gbl_resolv_flags.concurrent_dns));
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/ToolsMenu/FirewallACLRules",
frame_selected);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/StatisticsMenu/TCPStreamGraphMenu",
tcp_packet_selected);
while (list_entry != NULL) {
dissector_filter_t *filter_entry;
gchar *path;
filter_entry = (dissector_filter_t *)list_entry->data;
path = g_strdup_printf("/Menubar/AnalyzeMenu/ConversationFilterMenu/Filters/filter-%u", i);
set_menu_sensitivity(ui_manager_main_menubar, path,
menu_dissector_filter_spe_cb( NULL, cf->edt, filter_entry));
g_free(path);
i++;
list_entry = g_list_next(list_entry);
}
}
static void
menu_prefs_toggle_bool (GtkWidget *w, gpointer data)
{
gboolean *value = (gboolean *)data;
module_t *module = (module_t *)g_object_get_data (G_OBJECT(w), "module");
module->prefs_changed = TRUE;
*value = !(*value);
prefs_apply (module);
if (!prefs.gui_use_pref_save) {
prefs_main_write();
}
redissect_packets();
redissect_all_packet_windows();
}
static void
menu_prefs_change_enum (GtkWidget *w, gpointer data)
{
gint *value = (gint *)data;
module_t *module = (module_t *)g_object_get_data (G_OBJECT(w), "module");
gint new_value = GPOINTER_TO_INT(g_object_get_data (G_OBJECT(w), "enumval"));
if (!gtk_check_menu_item_get_active (GTK_CHECK_MENU_ITEM(w)))
return;
if (*value != new_value) {
module->prefs_changed = TRUE;
*value = new_value;
prefs_apply (module);
if (!prefs.gui_use_pref_save) {
prefs_main_write();
}
redissect_packets();
redissect_all_packet_windows();
}
}
void
menu_prefs_reset(void)
{
g_free (g_object_get_data(G_OBJECT(ui_manager_tree_view_menu), "menu_abbrev"));
g_object_set_data(G_OBJECT(ui_manager_tree_view_menu), "menu_abbrev", NULL);
}
static void
menu_prefs_change_ok (GtkWidget *w, gpointer parent_w)
{
GtkWidget *entry = (GtkWidget *)g_object_get_data (G_OBJECT(w), "entry");
module_t *module = (module_t *)g_object_get_data (G_OBJECT(w), "module");
pref_t *pref = (pref_t *)g_object_get_data (G_OBJECT(w), "pref");
const gchar *new_value = gtk_entry_get_text(GTK_ENTRY(entry));
range_t *newrange;
gchar *p;
guint uval;
switch (pref->type) {
case PREF_UINT:
uval = (guint)strtoul(new_value, &p, pref->info.base);
if (p == new_value || *p != '\0') {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"The value \"%s\" isn't a valid number.",
new_value);
return;
}
if (*pref->varp.uint != uval) {
module->prefs_changed = TRUE;
*pref->varp.uint = uval;
}
break;
case PREF_STRING:
if (strcmp (*pref->varp.string, new_value) != 0) {
module->prefs_changed = TRUE;
g_free((void*)*pref->varp.string);
*pref->varp.string = g_strdup(new_value);
}
break;
case PREF_RANGE:
if (range_convert_str(&newrange, new_value, pref->info.max_value) != CVT_NO_ERROR) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"The value \"%s\" isn't a valid range.",
new_value);
return;
}
if (!ranges_are_equal(*pref->varp.range, newrange)) {
module->prefs_changed = TRUE;
g_free(*pref->varp.range);
*pref->varp.range = newrange;
} else {
g_free (newrange);
}
break;
default:
g_assert_not_reached();
break;
}
if (module->prefs_changed) {
menu_prefs_reset();
prefs_apply (module);
if (!prefs.gui_use_pref_save) {
prefs_main_write();
}
redissect_packets();
redissect_all_packet_windows();
}
window_destroy(GTK_WIDGET(parent_w));
}
static void
menu_prefs_change_cancel (GtkWidget *w _U_, gpointer parent_w)
{
window_destroy(GTK_WIDGET(parent_w));
}
static void
menu_prefs_edit_dlg (GtkWidget *w, gpointer data)
{
pref_t *pref = (pref_t *)data;
module_t *module = (module_t *)g_object_get_data (G_OBJECT(w), "module");
gchar *value = NULL;
GtkWidget *win, *main_grid, *main_vb, *bbox, *cancel_bt, *ok_bt;
GtkWidget *entry, *label;
switch (pref->type) {
case PREF_UINT:
switch (pref->info.base) {
case 8:
value = g_strdup_printf("%o", *pref->varp.uint);
break;
case 10:
value = g_strdup_printf("%u", *pref->varp.uint);
break;
case 16:
value = g_strdup_printf("%x", *pref->varp.uint);
break;
default:
g_assert_not_reached();
break;
}
break;
case PREF_STRING:
value = g_strdup(*pref->varp.string);
break;
case PREF_RANGE:
value = g_strdup(range_convert_range (*pref->varp.range));
break;
default:
g_assert_not_reached();
break;
}
win = dlg_window_new(module->description);
gtk_window_set_resizable(GTK_WINDOW(win),FALSE);
gtk_window_resize(GTK_WINDOW(win), 400, 100);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_add(GTK_CONTAINER(win), main_vb);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 6);
main_grid = ws_gtk_grid_new();
gtk_box_pack_start(GTK_BOX(main_vb), main_grid, FALSE, FALSE, 0);
ws_gtk_grid_set_column_spacing(GTK_GRID(main_grid), 10);
label = gtk_label_new(ep_strdup_printf("%s:", pref->title));
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), label, 0, 1, 1, 1);
gtk_misc_set_alignment(GTK_MISC(label), 1.0f, 0.5f);
if (pref->description)
gtk_widget_set_tooltip_text(label, pref->description);
entry = gtk_entry_new();
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), entry, 1, 1, 1, 1);
gtk_entry_set_text(GTK_ENTRY(entry), value);
if (pref->description)
gtk_widget_set_tooltip_text(entry, pref->description);
bbox = dlg_button_row_new(GTK_STOCK_CANCEL,GTK_STOCK_OK, NULL);
gtk_box_pack_end(GTK_BOX(main_vb), bbox, FALSE, FALSE, 0);
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_object_set_data (G_OBJECT(ok_bt), "module", module);
g_object_set_data (G_OBJECT(ok_bt), "entry", entry);
g_object_set_data (G_OBJECT(ok_bt), "pref", pref);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(menu_prefs_change_ok), win);
dlg_set_activate(entry, ok_bt);
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
g_signal_connect(cancel_bt, "clicked", G_CALLBACK(menu_prefs_change_cancel), win);
window_set_cancel_button(win, cancel_bt, NULL);
gtk_widget_grab_default(ok_bt);
gtk_widget_show_all(win);
g_free(value);
}
static guint
add_protocol_prefs_generic_menu(pref_t *pref, gpointer data, GtkUIManager *ui_menu, const char *path)
{
GtkWidget *menu_preferences;
GtkWidget *menu_item, *menu_sub_item, *sub_menu;
GSList *group = NULL;
module_t *module = (module_t *)data;
const enum_val_t *enum_valp;
gchar *label = NULL;
switch (pref->type) {
case PREF_UINT:
switch (pref->info.base) {
case 8:
label = g_strdup_printf ("%s: %o", pref->title, *pref->varp.uint);
break;
case 10:
label = g_strdup_printf ("%s: %u", pref->title, *pref->varp.uint);
break;
case 16:
label = g_strdup_printf ("%s: %x", pref->title, *pref->varp.uint);
break;
default:
g_assert_not_reached();
break;
}
menu_item = gtk_menu_item_new_with_label(label);
g_object_set_data (G_OBJECT(menu_item), "module", module);
g_signal_connect(menu_item, "activate", G_CALLBACK(menu_prefs_edit_dlg), pref);
g_free (label);
break;
case PREF_BOOL:
menu_item = gtk_check_menu_item_new_with_label(pref->title);
gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM(menu_item), *pref->varp.boolp);
g_object_set_data (G_OBJECT(menu_item), "module", module);
g_signal_connect(menu_item, "activate", G_CALLBACK(menu_prefs_toggle_bool), pref->varp.boolp);
break;
case PREF_ENUM:
menu_item = gtk_menu_item_new_with_label(pref->title);
sub_menu = gtk_menu_new();
gtk_menu_item_set_submenu (GTK_MENU_ITEM(menu_item), sub_menu);
enum_valp = pref->info.enum_info.enumvals;
while (enum_valp->name != NULL) {
menu_sub_item = gtk_radio_menu_item_new_with_label(group, enum_valp->description);
group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (menu_sub_item));
if (enum_valp->value == *pref->varp.enump) {
gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM(menu_sub_item), TRUE);
}
g_object_set_data (G_OBJECT(menu_sub_item), "module", module);
g_object_set_data (G_OBJECT(menu_sub_item), "enumval", GINT_TO_POINTER(enum_valp->value));
g_signal_connect(menu_sub_item, "activate", G_CALLBACK(menu_prefs_change_enum), pref->varp.enump);
gtk_menu_shell_append (GTK_MENU_SHELL(sub_menu), menu_sub_item);
gtk_widget_show (menu_sub_item);
enum_valp++;
}
break;
case PREF_STRING:
label = g_strdup_printf ("%s: %s", pref->title, *pref->varp.string);
menu_item = gtk_menu_item_new_with_label(label);
g_object_set_data (G_OBJECT(menu_item), "module", module);
g_signal_connect(menu_item, "activate", G_CALLBACK(menu_prefs_edit_dlg), pref);
g_free (label);
break;
case PREF_RANGE:
label = g_strdup_printf ("%s: %s", pref->title, range_convert_range (*pref->varp.range));
menu_item = gtk_menu_item_new_with_label(label);
g_object_set_data (G_OBJECT(menu_item), "module", module);
g_signal_connect(menu_item, "activate", G_CALLBACK(menu_prefs_edit_dlg), pref);
g_free (label);
break;
case PREF_UAT:
label = g_strdup_printf ("%s...", pref->title);
menu_item = gtk_menu_item_new_with_label(label);
g_signal_connect (menu_item, "activate", G_CALLBACK(uat_window_cb), pref->varp.uat);
g_free (label);
break;
case PREF_COLOR:
case PREF_CUSTOM:
case PREF_STATIC_TEXT:
case PREF_OBSOLETE:
default:
return 0;
}
menu_preferences = gtk_ui_manager_get_widget(ui_menu, path);
if(!menu_preferences)
g_warning("menu_preferences Not found path");
sub_menu = gtk_menu_item_get_submenu (GTK_MENU_ITEM(menu_preferences));
gtk_menu_shell_append (GTK_MENU_SHELL(sub_menu), menu_item);
gtk_widget_show (menu_item);
return 0;
}
static guint
add_protocol_prefs_menu(pref_t *pref, gpointer data)
{
return add_protocol_prefs_generic_menu(pref, data, ui_manager_tree_view_menu, "/TreeViewPopup/ProtocolPreferences");
}
static guint
add_protocol_prefs_packet_list_menu(pref_t *pref, gpointer data)
{
return add_protocol_prefs_generic_menu(pref, data, ui_manager_packet_list_menu, "/PacketListMenuPopup/ProtocolPreferences");
}
static void
rebuild_protocol_prefs_menu(module_t *prefs_module_p, gboolean preferences,
GtkUIManager *ui_menu, const char *path)
{
GtkWidget *menu_preferences, *menu_item;
GtkWidget *sub_menu;
gchar *label;
menu_preferences = gtk_ui_manager_get_widget(ui_menu, path);
if (prefs_module_p && preferences) {
sub_menu = gtk_menu_new();
gtk_menu_item_set_submenu (GTK_MENU_ITEM(menu_preferences), sub_menu);
label = g_strdup_printf ("%s Preferences...", prefs_module_p->description);
menu_item = gtk_image_menu_item_new_with_label(label);
gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM(menu_item),
gtk_image_new_from_stock(GTK_STOCK_PREFERENCES, GTK_ICON_SIZE_MENU));
gtk_menu_shell_append(GTK_MENU_SHELL(sub_menu), menu_item);
g_signal_connect_swapped(G_OBJECT(menu_item), "activate",
G_CALLBACK(properties_cb), (GObject *) menu_item);
gtk_widget_show(menu_item);
g_free(label);
menu_item = gtk_menu_item_new();
gtk_menu_shell_append(GTK_MENU_SHELL(sub_menu), menu_item);
gtk_widget_show(menu_item);
if (ui_menu == ui_manager_tree_view_menu) {
prefs_pref_foreach(prefs_module_p, add_protocol_prefs_menu, prefs_module_p);
} else {
prefs_pref_foreach(prefs_module_p, add_protocol_prefs_packet_list_menu, prefs_module_p);
}
} else {
gtk_menu_item_set_submenu (GTK_MENU_ITEM(menu_preferences), NULL);
}
}
static void
menu_visible_column_toggle (GtkWidget *w _U_, gpointer data)
{
packet_list_toggle_visible_column (GPOINTER_TO_INT(data));
}
void
rebuild_visible_columns_menu (void)
{
GtkWidget *menu_columns[2], *menu_item;
GtkWidget *sub_menu;
GList *clp;
fmt_data *cfmt;
gchar *title;
gint i, col_id;
menu_columns[0] = gtk_ui_manager_get_widget(ui_manager_main_menubar, "/Menubar/ViewMenu/DisplayedColumns");
if(! menu_columns[0]){
fprintf (stderr, "Warning: couldn't find menu_columns[0] path=/Menubar/ViewMenu/DisplayedColumns");
}
menu_columns[1] = gtk_ui_manager_get_widget(ui_manager_packet_list_heading, "/PacketListHeadingPopup/DisplayedColumns");
if(! menu_columns[1]){
fprintf (stderr, "Warning: couldn't find menu_columns[1] path=/PacketListHeadingPopup/DisplayedColumns");
}
for (i = 0; i < 2; i++) {
sub_menu = gtk_menu_new();
gtk_menu_item_set_submenu (GTK_MENU_ITEM(menu_columns[i]), sub_menu);
clp = g_list_first (prefs.col_list);
col_id = 0;
while (clp) {
cfmt = (fmt_data *) clp->data;
if (cfmt->title[0]) {
if (cfmt->fmt == COL_CUSTOM) {
title = g_strdup_printf ("%s (%s)", cfmt->title, cfmt->custom_field);
} else {
title = g_strdup_printf ("%s (%s)", cfmt->title, col_format_desc (cfmt->fmt));
}
} else {
if (cfmt->fmt == COL_CUSTOM) {
title = g_strdup_printf ("(%s)", cfmt->custom_field);
} else {
title = g_strdup_printf ("(%s)", col_format_desc (cfmt->fmt));
}
}
menu_item = gtk_check_menu_item_new_with_label(title);
g_free (title);
gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM(menu_item), cfmt->visible);
g_signal_connect(menu_item, "activate", G_CALLBACK(menu_visible_column_toggle), GINT_TO_POINTER(col_id));
gtk_menu_shell_append (GTK_MENU_SHELL(sub_menu), menu_item);
gtk_widget_show (menu_item);
clp = g_list_next (clp);
col_id++;
}
menu_item = gtk_separator_menu_item_new();
gtk_menu_shell_append (GTK_MENU_SHELL(sub_menu), menu_item);
gtk_widget_show (menu_item);
menu_item = gtk_menu_item_new_with_label ("Display All");
gtk_menu_shell_append (GTK_MENU_SHELL(sub_menu), menu_item);
g_signal_connect(menu_item, "activate", G_CALLBACK(packet_list_heading_activate_all_columns_cb), NULL);
gtk_widget_show (menu_item);
}
}
void
menus_set_column_resolved (gboolean resolved, gboolean can_resolve)
{
GtkWidget *menu;
menu = gtk_ui_manager_get_widget(ui_manager_packet_list_heading, "/PacketListHeadingPopup/ShowResolved");
if(!menu){
fprintf (stderr, "Warning: couldn't find menu path=/PacketListHeadingPopup/ShowResolved");
}
g_object_set_data(G_OBJECT(menu), "skip-update", (void *)1);
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu), resolved && can_resolve);
set_menu_sensitivity(ui_manager_packet_list_heading, "/PacketListHeadingPopup/ShowResolved", can_resolve);
g_object_set_data(G_OBJECT(menu), "skip-update", NULL);
}
void
menus_set_column_align_default (gboolean right_justify)
{
GtkWidget *submenu, *menu_item_child;
GList *child_list, *child_list_item;
const gchar *menu_item_name;
size_t menu_item_len;
submenu = gtk_ui_manager_get_widget (ui_manager_packet_list_heading, "/PacketListHeadingPopup");
if(!submenu){
fprintf (stderr, "Warning: couldn't find submenu path=/PacketListHeadingPopup");
}
child_list = gtk_container_get_children(GTK_CONTAINER(submenu));
child_list_item = child_list;
while (child_list_item) {
menu_item_child = gtk_bin_get_child(GTK_BIN(child_list_item->data));
if (menu_item_child != NULL) {
menu_item_name = gtk_label_get_text(GTK_LABEL(menu_item_child));
menu_item_len = strlen (menu_item_name);
if(strncmp(menu_item_name, "Align Left", 10) == 0) {
if (!right_justify && menu_item_len == 10) {
gtk_label_set_text(GTK_LABEL(menu_item_child), "Align Left\t(default)");
} else if (right_justify && menu_item_len > 10) {
gtk_label_set_text(GTK_LABEL(menu_item_child), "Align Left");
}
} else if (strncmp (menu_item_name, "Align Right", 11) == 0) {
if (right_justify && menu_item_len == 11) {
gtk_label_set_text(GTK_LABEL(menu_item_child), "Align Right\t(default)");
} else if (!right_justify && menu_item_len > 11) {
gtk_label_set_text(GTK_LABEL(menu_item_child), "Align Right");
}
}
}
child_list_item = g_list_next(child_list_item);
}
g_list_free(child_list);
}
void
set_menus_for_selected_tree_row(capture_file *cf)
{
gboolean properties;
gint id;
if (cf->finfo_selected != NULL) {
header_field_info *hfinfo = cf->finfo_selected->hfinfo;
const char *abbrev;
char *prev_abbrev;
if (hfinfo->parent == -1) {
abbrev = hfinfo->abbrev;
id = (hfinfo->type == FT_PROTOCOL) ? proto_get_id((protocol_t *)hfinfo->strings) : -1;
} else {
abbrev = proto_registrar_get_abbrev(hfinfo->parent);
id = hfinfo->parent;
}
properties = prefs_is_registered_protocol(abbrev);
set_menu_sensitivity(ui_manager_tree_view_menu,
"/TreeViewPopup/GotoCorrespondingPacket", hfinfo->type == FT_FRAMENUM);
set_menu_sensitivity(ui_manager_tree_view_menu,
"/TreeViewPopup/ShowPacketRefinNewWindow", hfinfo->type == FT_FRAMENUM);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/Copy",
TRUE);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/Copy/AsFilter",
proto_can_match_selected(cf->finfo_selected, cf->edt));
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/ApplyasColumn",
hfinfo->type != FT_NONE);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/ApplyAsFilter",
proto_can_match_selected(cf->finfo_selected, cf->edt));
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/PrepareaFilter",
proto_can_match_selected(cf->finfo_selected, cf->edt));
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/ColorizewithFilter",
proto_can_match_selected(cf->finfo_selected, cf->edt));
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/ProtocolPreferences",
properties);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/DisableProtocol",
(id == -1) ? FALSE : proto_can_toggle_protocol(id));
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/ExpandSubtrees",
cf->finfo_selected->tree_type != -1);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/WikiProtocolPage",
(id == -1) ? FALSE : TRUE);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/FilterFieldReference",
(id == -1) ? FALSE : TRUE);
set_menu_sensitivity(ui_manager_main_menubar,
"/Menubar/FileMenu/ExportSelectedPacketBytes", TRUE);
set_menu_sensitivity(ui_manager_main_menubar,
"/Menubar/GoMenu/GotoCorrespondingPacket", hfinfo->type == FT_FRAMENUM);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/Copy/Description",
proto_can_match_selected(cf->finfo_selected, cf->edt));
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/Copy/Fieldname",
proto_can_match_selected(cf->finfo_selected, cf->edt));
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/Copy/Value",
proto_can_match_selected(cf->finfo_selected, cf->edt));
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/Copy/AsFilter",
proto_can_match_selected(cf->finfo_selected, cf->edt));
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/AnalyzeMenu/ApplyasColumn",
hfinfo->type != FT_NONE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/AnalyzeMenu/ApplyAsFilter",
proto_can_match_selected(cf->finfo_selected, cf->edt));
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/AnalyzeMenu/PrepareaFilter",
proto_can_match_selected(cf->finfo_selected, cf->edt));
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/ViewMenu/ExpandSubtrees",
cf->finfo_selected->tree_type != -1);
prev_abbrev = (char *)g_object_get_data(G_OBJECT(ui_manager_tree_view_menu), "menu_abbrev");
if (!prev_abbrev || (strcmp (prev_abbrev, abbrev) != 0)) {
module_t *prefs_module_p = prefs_find_module(abbrev);
rebuild_protocol_prefs_menu(prefs_module_p, properties, ui_manager_tree_view_menu, "/TreeViewPopup/ProtocolPreferences");
g_object_set_data(G_OBJECT(ui_manager_tree_view_menu), "menu_abbrev", g_strdup(abbrev));
g_free (prev_abbrev);
}
} else {
set_menu_sensitivity(ui_manager_tree_view_menu,
"/TreeViewPopup/GotoCorrespondingPacket", FALSE);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/Copy", FALSE);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/ApplyasColumn", FALSE);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/ApplyAsFilter", FALSE);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/PrepareaFilter", FALSE);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/ColorizewithFilter", FALSE);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/ProtocolPreferences",
FALSE);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/DisableProtocol", FALSE);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/ExpandSubtrees", FALSE);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/WikiProtocolPage",
FALSE);
set_menu_sensitivity(ui_manager_tree_view_menu, "/TreeViewPopup/FilterFieldReference",
FALSE);
set_menu_sensitivity(ui_manager_main_menubar,
"/Menubar/FileMenu/ExportSelectedPacketBytes", FALSE);
set_menu_sensitivity(ui_manager_main_menubar,
"/Menubar/GoMenu/GotoCorrespondingPacket", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/Copy/Description", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/Copy/Fieldname", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/Copy/Value", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/EditMenu/Copy/AsFilter", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/AnalyzeMenu/ApplyasColumn", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/AnalyzeMenu/ApplyAsFilter", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/AnalyzeMenu/PrepareaFilter", FALSE);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/ViewMenu/ExpandSubtrees", FALSE);
}
}
void set_menus_for_packet_history(gboolean back_history, gboolean forward_history)
{
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/GoMenu/Back", back_history);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/GoMenu/Forward", forward_history);
}
void set_menus_for_file_set(gboolean file_set, gboolean previous_file, gboolean next_file)
{
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/Set/ListFiles", file_set);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/Set/PreviousFile", previous_file);
set_menu_sensitivity(ui_manager_main_menubar, "/Menubar/FileMenu/Set/NextFile", next_file);
}
GtkWidget *menus_get_profiles_rename_menu (void)
{
return gtk_ui_manager_get_widget(ui_manager_statusbar_profiles_menu, "/ProfilesMenuPopup/Rename");
}
GtkWidget *menus_get_profiles_delete_menu (void)
{
return gtk_ui_manager_get_widget(ui_manager_statusbar_profiles_menu, "/ProfilesMenuPopup/Delete");
}
GtkWidget *menus_get_profiles_change_menu (void)
{
return gtk_ui_manager_get_widget(ui_manager_statusbar_profiles_menu, "/ProfilesMenuPopup/Change");
}
void set_menus_for_profiles(gboolean default_profile)
{
set_menu_sensitivity(ui_manager_statusbar_profiles_menu, "/ProfilesMenuPopup/Rename", !default_profile);
set_menu_sensitivity(ui_manager_statusbar_profiles_menu, "/ProfilesMenuPopup/Delete", !default_profile);
}
