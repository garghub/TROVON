static void
airpcap_toolbar_fcs_filter_combo_cb(GtkWidget *fcs_filter_cb, gpointer user_data _U_)
{
PAirpcapHandle ad;
gchar ebuf[AIRPCAP_ERRBUF_SIZE];
gchar *fcs_filter_str;
if (fcs_filter_cb != NULL && !block_toolbar_signals && (airpcap_if_active != NULL)) {
fcs_filter_str = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(fcs_filter_cb));
ad = airpcap_if_open(airpcap_if_active->name, ebuf);
if (fcs_filter_str && (g_ascii_strcasecmp("", fcs_filter_str)) && ad) {
airpcap_if_selected->CrcValidationOn = airpcap_get_validation_type(fcs_filter_str);
airpcap_if_selected->saved = FALSE;
airpcap_if_set_fcs_validation(ad,airpcap_if_active->CrcValidationOn);
airpcap_if_store_cur_config_as_adapter_default(ad);
airpcap_if_close(ad);
}
g_free(fcs_filter_str);
}
}
void
airpcap_toolbar_encryption_cb(GtkWidget *entry _U_, gpointer user_data _U_)
{
gchar ebuf[AIRPCAP_ERRBUF_SIZE];
PAirpcapHandle ad;
gint n = 0;
gint i = 0;
airpcap_if_info_t* curr_if = NULL;
if( (airpcap_if_active != NULL)) {
ad = airpcap_if_open(airpcap_if_active->name, ebuf);
if(ad) {
if(airpcap_if_active->DecryptionOn == AIRPCAP_DECRYPTION_ON) {
airpcap_if_active->DecryptionOn = AIRPCAP_DECRYPTION_OFF;
airpcap_if_set_decryption_state(ad,airpcap_if_active->DecryptionOn);
if(!airpcap_if_store_cur_config_as_adapter_default(ad)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Cannot save configuration.\nRemember that in order to store the configuration in the registry you have to:\n\n- Close all the airpcap-based applications.\n- Be sure to have administrative privileges.");
}
airpcap_if_close(ad);
} else {
airpcap_if_active->DecryptionOn = AIRPCAP_DECRYPTION_ON;
airpcap_if_set_decryption_state(ad,airpcap_if_active->DecryptionOn);
if(!airpcap_if_store_cur_config_as_adapter_default(ad)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Cannot save configuration.\nRemember that in order to store the configuration in the registry you have to:\n\n- Close all the airpcap-based applications.\n- Be sure to have administrative privileges.");
}
airpcap_if_close(ad);
}
}
} else {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "No active AirPcap Adapter selected.");
return;
}
if (!(g_airpcap_if_list == NULL)) {
n = g_list_length(g_airpcap_if_list);
for(i = 0; i < n; i++) {
curr_if = (airpcap_if_info_t*)g_list_nth_data(g_airpcap_if_list,i);
if( (curr_if != NULL) && (curr_if != airpcap_if_selected) ) {
ad = airpcap_if_open(curr_if->name, ebuf);
if(ad) {
curr_if->DecryptionOn = airpcap_if_selected->DecryptionOn;
airpcap_if_set_decryption_state(ad,curr_if->DecryptionOn);
if(!airpcap_if_store_cur_config_as_adapter_default(ad)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Unable to save configuration."
"\nIn order to store the configuration in the registry you"
"\nhave to close all other AirPcap-based applications and"
"\nhave Administrator privileges.");
}
airpcap_if_close(ad);
}
}
}
} else {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "AirPcap Adapter Error.");
return;
}
}
static void
toolbar_display_airpcap_advanced_cb(GtkWidget *w, gpointer data)
{
int *from_widget;
from_widget = (gint*)g_malloc(sizeof(gint));
*from_widget = AIRPCAP_ADVANCED_FROM_TOOLBAR;
g_object_set_data(G_OBJECT(wireless_tb),AIRPCAP_ADVANCED_FROM_KEY,from_widget);
display_airpcap_advanced_cb(w,data);
}
static void
toolbar_display_airpcap_key_management_cb(GtkWidget *w, gpointer data)
{
int *from_widget;
from_widget = (gint*)g_malloc(sizeof(gint));
*from_widget = AIRPCAP_ADVANCED_FROM_TOOLBAR;
g_object_set_data(G_OBJECT(wireless_tb), AIRPCAP_ADVANCED_FROM_KEY, from_widget);
display_airpcap_key_management_cb(w,data);
}
GtkWidget *airpcap_toolbar_new(void)
{
GtkWidget *channel_lb = NULL,
*channel_cb = NULL,
*channel_offset_lb = NULL,
*channel_offset_cb = NULL,
*fcs_filter_lb = NULL,
*fcs_filter_cb = NULL;
GtkWidget *lcl_wireless_tb;
GtkWidget *decryption_mode_lb;
GtkWidget *decryption_mode_cb;
GtkToolItem *key_management_bt = NULL,
*advanced_bt = NULL,
*tool_item;
lcl_wireless_tb = gtk_toolbar_new();
gtk_orientable_set_orientation(GTK_ORIENTABLE(lcl_wireless_tb),
GTK_ORIENTATION_HORIZONTAL);
channel_lb = gtk_label_new("802.11 Channel: ");
g_object_set_data(G_OBJECT(lcl_wireless_tb), AIRPCAP_TOOLBAR_CHANNEL_LABEL_KEY, channel_lb);
gtk_widget_show(channel_lb);
tool_item = gtk_tool_item_new ();
gtk_container_add (GTK_CONTAINER (tool_item), channel_lb);
gtk_widget_show (GTK_WIDGET (tool_item));
gtk_toolbar_insert(GTK_TOOLBAR(lcl_wireless_tb), tool_item, -1);
gtk_widget_set_tooltip_text(GTK_WIDGET(tool_item), "Current 802.11 Channel");
channel_cb = gtk_combo_box_text_new();
g_object_set_data(G_OBJECT(lcl_wireless_tb), AIRPCAP_TOOLBAR_CHANNEL_KEY, channel_cb);
airpcap_update_channel_combo(GTK_WIDGET(channel_cb), airpcap_if_selected);
gtk_widget_show(channel_cb);
tool_item = gtk_tool_item_new ();
gtk_container_add (GTK_CONTAINER (tool_item), channel_cb);
gtk_widget_show (GTK_WIDGET (tool_item));
gtk_toolbar_insert(GTK_TOOLBAR(lcl_wireless_tb), tool_item, -1);
gtk_widget_set_tooltip_text(GTK_WIDGET(tool_item), "802.11 Channel");
channel_offset_lb = gtk_label_new("Channel Offset: ");
g_object_set_data(G_OBJECT(lcl_wireless_tb), AIRPCAP_TOOLBAR_CHANNEL_OFFSET_LABEL_KEY, channel_offset_lb);
gtk_widget_show(channel_offset_lb);
tool_item = gtk_tool_item_new ();
gtk_container_add (GTK_CONTAINER (tool_item), channel_offset_lb);
gtk_widget_show (GTK_WIDGET (tool_item));
gtk_toolbar_insert(GTK_TOOLBAR(lcl_wireless_tb), tool_item, -1);
gtk_widget_set_tooltip_text(GTK_WIDGET(tool_item), "Current 802.11 Channel Offset");
channel_offset_cb = gtk_combo_box_text_new();
g_object_set_data(G_OBJECT(lcl_wireless_tb), AIRPCAP_TOOLBAR_CHANNEL_OFFSET_KEY, channel_offset_cb);
if(airpcap_if_active != NULL){
airpcap_update_channel_offset_combo(airpcap_if_active, airpcap_if_active->channelInfo.Frequency, channel_offset_cb, FALSE);
} else {
gtk_combo_box_set_active(GTK_COMBO_BOX(channel_offset_cb), -1);
}
gtk_widget_set_tooltip_text(channel_offset_cb, "Current 802.11 Channel Offset");
gtk_widget_show(channel_offset_cb);
tool_item = gtk_tool_item_new ();
gtk_container_add (GTK_CONTAINER (tool_item), channel_offset_cb);
gtk_widget_show (GTK_WIDGET (tool_item));
gtk_toolbar_insert(GTK_TOOLBAR(lcl_wireless_tb), tool_item, -1);
g_signal_connect(channel_cb,"changed", G_CALLBACK(airpcap_channel_changed_set_cb), channel_offset_cb);
g_signal_connect(channel_offset_cb, "changed", G_CALLBACK(airpcap_channel_offset_changed_cb), NULL);
fcs_filter_lb = gtk_label_new(" FCS Filter: ");
g_object_set_data(G_OBJECT(lcl_wireless_tb), AIRPCAP_TOOLBAR_FCS_FILTER_LABEL_KEY, fcs_filter_lb);
gtk_widget_show(fcs_filter_lb);
tool_item = gtk_tool_item_new ();
gtk_container_add (GTK_CONTAINER (tool_item), fcs_filter_lb);
gtk_widget_show (GTK_WIDGET (tool_item));
gtk_toolbar_insert(GTK_TOOLBAR(lcl_wireless_tb), tool_item, -1);
fcs_filter_cb = gtk_combo_box_text_new();
g_object_set_data(G_OBJECT(lcl_wireless_tb), AIRPCAP_TOOLBAR_FCS_FILTER_KEY, fcs_filter_cb);
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(fcs_filter_cb), airpcap_get_validation_name(AIRPCAP_VT_ACCEPT_EVERYTHING));
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(fcs_filter_cb), airpcap_get_validation_name(AIRPCAP_VT_ACCEPT_CORRECT_FRAMES));
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(fcs_filter_cb), airpcap_get_validation_name(AIRPCAP_VT_ACCEPT_CORRUPT_FRAMES));
gtk_combo_box_set_active(GTK_COMBO_BOX(fcs_filter_cb), 0);
gtk_widget_set_tooltip_text(fcs_filter_cb, "Select the 802.11 FCS filter that the wireless adapter will apply.");
if (airpcap_if_selected != NULL) {
airpcap_validation_type_combo_set_by_type(fcs_filter_cb, airpcap_if_selected->CrcValidationOn);
}
g_signal_connect (fcs_filter_cb, "changed", G_CALLBACK(airpcap_toolbar_fcs_filter_combo_cb), NULL);
gtk_widget_show(fcs_filter_cb);
tool_item = gtk_tool_item_new ();
gtk_container_add (GTK_CONTAINER (tool_item), fcs_filter_cb);
gtk_widget_show (GTK_WIDGET (tool_item));
gtk_toolbar_insert(GTK_TOOLBAR(lcl_wireless_tb), tool_item, -1);
decryption_mode_lb = gtk_label_new ("Decryption Mode: ");
g_object_set_data(G_OBJECT(lcl_wireless_tb), AIRPCAP_TOOLBAR_DECRYPTION_LABEL_KEY, decryption_mode_lb);
gtk_widget_set_name (decryption_mode_lb, "decryption_mode_lb");
gtk_widget_show (decryption_mode_lb);
decryption_mode_cb = gtk_combo_box_text_new();
gtk_widget_set_name (decryption_mode_cb, "decryption_mode_cb");
gtk_widget_show (decryption_mode_cb);
update_decryption_mode_list(decryption_mode_cb);
tool_item = gtk_tool_item_new ();
gtk_container_add (GTK_CONTAINER (tool_item), decryption_mode_cb);
gtk_widget_show (GTK_WIDGET (tool_item));
gtk_toolbar_insert(GTK_TOOLBAR(lcl_wireless_tb), tool_item, -1);
gtk_widget_set_tooltip_text(fcs_filter_lb, "Choose a Decryption Mode");
update_decryption_mode(decryption_mode_cb);
g_signal_connect(decryption_mode_cb, "changed", G_CALLBACK(on_decryption_mode_cb_changed), NULL);
g_object_set_data(G_OBJECT(lcl_wireless_tb), AIRPCAP_TOOLBAR_DECRYPTION_KEY, decryption_mode_cb);
advanced_bt = gtk_tool_button_new(NULL,
"Wireless Settings...");
g_object_set_data(G_OBJECT(lcl_wireless_tb), AIRPCAP_TOOLBAR_ADVANCED_KEY, advanced_bt);
g_signal_connect(advanced_bt, "clicked", G_CALLBACK(toolbar_display_airpcap_advanced_cb), lcl_wireless_tb);
gtk_widget_show(GTK_WIDGET(advanced_bt));
gtk_toolbar_insert(GTK_TOOLBAR(lcl_wireless_tb), advanced_bt, -1);
gtk_widget_set_tooltip_text(GTK_WIDGET(advanced_bt), "Set Advanced Wireless Settings");
key_management_bt = gtk_tool_button_new(NULL,
"Decryption Keys...");
g_object_set_data(G_OBJECT(lcl_wireless_tb), AIRPCAP_TOOLBAR_KEY_MANAGEMENT_KEY, key_management_bt);
g_signal_connect(key_management_bt, "clicked", G_CALLBACK(toolbar_display_airpcap_key_management_cb), lcl_wireless_tb);
gtk_widget_show(GTK_WIDGET(key_management_bt));
gtk_toolbar_insert(GTK_TOOLBAR(lcl_wireless_tb), key_management_bt, -1);
gtk_widget_set_tooltip_text(GTK_WIDGET(key_management_bt), "Manage Decryption Keys");
if(airpcap_if_active == NULL) {
if(g_airpcap_if_list == NULL || g_list_length(g_airpcap_if_list) == 0) {
airpcap_enable_toolbar_widgets(lcl_wireless_tb, FALSE);
} else {
airpcap_set_toolbar_stop_capture(airpcap_if_active);
airpcap_enable_toolbar_widgets(lcl_wireless_tb, FALSE);
}
} else {
airpcap_set_toolbar_stop_capture(airpcap_if_active);
}
return lcl_wireless_tb;
}
static void
driver_warning_dialog_cb(gpointer dialog, gint btn _U_, gpointer data _U_)
{
gboolean r;
r = simple_dialog_check_get(dialog);
recent.airpcap_driver_check_show = !r;
}
void airpcap_toolbar_show(GtkWidget *lcl_wireless_tb _U_)
{
if(g_airpcap_if_list != NULL && g_list_length(g_airpcap_if_list) > 0){
if (!airpcap_check_decryption_keys(g_airpcap_if_list)) {
airpcap_keys_check_w(NULL,NULL);
} else {
airpcap_load_decryption_keys(g_airpcap_if_list);
}
}
switch (airpcap_dll_ret_val) {
case AIRPCAP_DLL_OK:
break;
case AIRPCAP_DLL_OLD:
if(recent.airpcap_driver_check_show) {
driver_warning_dialog = (GtkWidget *)simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s",
"WARNING: The version of AirPcap on this system\n"
"does not support driver-level decryption. Please\n"
"download a more recent version from\n" "http://www.cacetech.com/support/downloads.htm \n");
simple_dialog_check_set(driver_warning_dialog,"Don't show this message again.");
simple_dialog_set_cb(driver_warning_dialog, driver_warning_dialog_cb, NULL);
}
break;
#if 0
case AIRPCAP_DLL_ERROR:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s","AIRPCAP_DLL_ERROR\n");
break;
case AIRPCAP_DLL_NOT_FOUND:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s","AIRPCAP_DDL_NOT_FOUND\n");
break;
#endif
}
}
