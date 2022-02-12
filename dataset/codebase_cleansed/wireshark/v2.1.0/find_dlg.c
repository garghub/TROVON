void
find_frame_cb(GtkWidget *w _U_, gpointer d _U_)
{
GtkWidget *main_vb, *main_find_hb, *main_options_hb,
*find_type_frame, *find_type_vb,
*find_type_hb, *find_type_lb, *hex_rb, *string_rb, *filter_rb,
*filter_hb, *filter_bt,
*direction_frame, *direction_vb,
*up_rb, *down_rb,
*data_frame, *data_vb,
*packet_data_rb, *decode_data_rb, *summary_data_rb,
*string_opt_frame, *string_opt_vb,
*case_cb, *combo_lb, *combo_cb,
*bbox, *ok_bt, *cancel_bt, *help_bt;
static construct_args_t args = {
"Wireshark: Search Filter",
FALSE,
TRUE,
FALSE
};
if (find_frame_w != NULL) {
reactivate_window(find_frame_w);
return;
}
find_frame_w = dlg_window_new("Wireshark: Find Packet");
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(find_frame_w), main_vb);
gtk_widget_show(main_vb);
main_find_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX (main_vb), main_find_hb, TRUE, TRUE, 0);
gtk_widget_show(main_find_hb);
find_type_frame = gtk_frame_new("Find");
gtk_box_pack_start(GTK_BOX(main_find_hb), find_type_frame, TRUE, TRUE, 0);
gtk_widget_show(find_type_frame);
find_type_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(find_type_vb), 3);
gtk_container_add(GTK_CONTAINER(find_type_frame), find_type_vb);
gtk_widget_show(find_type_vb);
find_type_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX (find_type_vb), find_type_hb, TRUE, TRUE, 0);
gtk_widget_show(find_type_hb);
find_type_lb = gtk_label_new("By:");
gtk_box_pack_start(GTK_BOX(find_type_hb), find_type_lb, FALSE, FALSE, 0);
gtk_widget_show(find_type_lb);
filter_rb = gtk_radio_button_new_with_mnemonic_from_widget(NULL, "_Display filter");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(filter_rb), !cfile.hex && !cfile.string);
gtk_box_pack_start(GTK_BOX(find_type_hb), filter_rb, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text(filter_rb, "Search for data by display filter syntax.\ne.g. ip.addr==10.1.1.1");
gtk_widget_show(filter_rb);
hex_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(filter_rb), "_Hex value");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(hex_rb), cfile.hex);
gtk_box_pack_start(GTK_BOX(find_type_hb), hex_rb, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text(hex_rb, "Search for data by hex string.\ne.g. fffffda5");
gtk_widget_show(hex_rb);
string_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(filter_rb), "_String");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(string_rb), cfile.string);
gtk_box_pack_start(GTK_BOX(find_type_hb), string_rb, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text(string_rb, "Search for data by string value.\ne.g. My String");
gtk_widget_show(string_rb);
filter_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(find_type_vb), filter_hb, FALSE, FALSE, 0);
gtk_widget_show(filter_hb);
filter_bt = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_DISPLAY_FILTER_ENTRY);
g_signal_connect(filter_bt, "clicked", G_CALLBACK(display_filter_construct_cb), &args);
g_signal_connect(filter_bt, "destroy", G_CALLBACK(filter_button_destroy_cb), NULL);
g_object_set_data(G_OBJECT(filter_bt), E_FILT_TE_BUTTON_KEY, filter_bt);
gtk_box_pack_start(GTK_BOX(filter_hb), filter_bt, FALSE, TRUE, 0);
gtk_widget_set_tooltip_text(filter_bt, "Click on the filter button to select a display filter,\nor enter your search criteria into the text box");
gtk_widget_show(filter_bt);
filter_text_box = gtk_entry_new();
if (cfile.sfilter) gtk_entry_set_text(GTK_ENTRY(filter_text_box), cfile.sfilter);
g_object_set_data(G_OBJECT(filter_bt), E_FILT_TE_PTR_KEY, filter_text_box);
g_object_set_data(G_OBJECT(find_frame_w), E_FILT_TE_PTR_KEY, filter_text_box);
gtk_box_pack_start(GTK_BOX(filter_hb), filter_text_box, TRUE, TRUE, 0);
g_signal_connect(filter_text_box, "changed", G_CALLBACK(find_filter_te_syntax_check_cb), find_frame_w);
g_object_set_data(G_OBJECT(find_frame_w), E_FILT_AUTOCOMP_PTR_KEY, NULL);
te_presskey_handler_id = g_signal_connect(filter_text_box, "key-press-event", G_CALLBACK (filter_string_te_key_pressed_cb), NULL);
win_presskey_handler_id = g_signal_connect(find_frame_w, "key-press-event", G_CALLBACK (filter_parent_dlg_key_pressed_cb), NULL);
gtk_widget_show(filter_text_box);
main_options_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX (main_vb), main_options_hb, TRUE, TRUE, 0);
gtk_widget_show(main_options_hb);
data_frame = gtk_frame_new("Search In");
gtk_box_pack_start(GTK_BOX(main_options_hb), data_frame, TRUE, TRUE, 0);
gtk_widget_show(data_frame);
data_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(data_vb), 3);
gtk_container_add(GTK_CONTAINER(data_frame), data_vb);
gtk_widget_show(data_vb);
summary_data_rb = gtk_radio_button_new_with_mnemonic_from_widget(NULL, "Packet list");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(summary_data_rb), summary_data);
gtk_box_pack_start(GTK_BOX(data_vb), summary_data_rb, TRUE, TRUE, 0);
gtk_widget_set_tooltip_text(summary_data_rb, "Search for string in the Info column of the packet summary (summary pane)");
gtk_widget_show(summary_data_rb);
decode_data_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(summary_data_rb), "Packet details");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(decode_data_rb), decode_data);
gtk_box_pack_start(GTK_BOX(data_vb), decode_data_rb, TRUE, TRUE, 0);
gtk_widget_set_tooltip_text(decode_data_rb, "Search for string among the decoded packet display labels (tree view pane)");
gtk_widget_show(decode_data_rb);
packet_data_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(summary_data_rb), "Packet bytes");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(packet_data_rb), packet_data);
gtk_box_pack_start(GTK_BOX(data_vb), packet_data_rb, TRUE, TRUE, 0);
gtk_widget_set_tooltip_text(packet_data_rb, "Search for string in the ASCII-converted packet data (hex view pane)");
gtk_widget_show(packet_data_rb);
string_opt_frame = gtk_frame_new("String Options");
gtk_box_pack_start(GTK_BOX(main_options_hb), string_opt_frame, TRUE, TRUE, 0);
gtk_widget_show(string_opt_frame);
string_opt_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(string_opt_frame), string_opt_vb);
gtk_container_set_border_width(GTK_CONTAINER(string_opt_vb), 3);
gtk_widget_show(string_opt_vb);
case_cb = gtk_check_button_new_with_mnemonic("Case sensitive");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(case_cb), !case_type);
gtk_box_pack_start(GTK_BOX (string_opt_vb), case_cb, TRUE, TRUE, 0);
gtk_widget_set_tooltip_text(case_cb, "Search by mixed upper/lower case?");
gtk_widget_show(case_cb);
combo_lb = gtk_label_new("Character width:");
gtk_box_pack_start(GTK_BOX (string_opt_vb), combo_lb, TRUE, TRUE, 0);
gtk_misc_set_alignment(GTK_MISC(combo_lb), 0.0f, 0.5f);
gtk_widget_show(combo_lb);
combo_cb = gtk_combo_box_text_new();
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(combo_cb), "Narrow & wide");
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(combo_cb), "Narrow (UTF-8 / ASCII)");
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(combo_cb), "Wide (UTF-16)");
gtk_combo_box_set_active(GTK_COMBO_BOX(combo_cb),0);
gtk_box_pack_start(GTK_BOX (string_opt_vb), combo_cb, TRUE, TRUE, 0);
gtk_widget_show(combo_cb);
direction_frame = gtk_frame_new("Direction");
gtk_box_pack_start(GTK_BOX(main_options_hb), direction_frame, FALSE, FALSE, 0);
gtk_widget_show(direction_frame);
direction_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(direction_vb), 3);
gtk_container_add(GTK_CONTAINER(direction_frame), direction_vb);
gtk_widget_show(direction_vb);
up_rb = gtk_radio_button_new_with_mnemonic_from_widget(NULL, "_Up");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(up_rb), cfile.dir == SD_BACKWARD);
gtk_box_pack_start(GTK_BOX(direction_vb), up_rb, FALSE, FALSE, 0);
gtk_widget_show(up_rb);
down_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(up_rb), "_Down");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(down_rb), cfile.dir == SD_FORWARD);
gtk_box_pack_start(GTK_BOX(direction_vb), down_rb, FALSE, FALSE, 0);
gtk_widget_show(down_rb);
bbox = dlg_button_row_new(GTK_STOCK_FIND, GTK_STOCK_CANCEL, GTK_STOCK_HELP, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_FIND);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(find_frame_ok_cb), find_frame_w);
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
g_signal_connect(cancel_bt, "clicked", G_CALLBACK(find_frame_close_cb), find_frame_w);
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_FIND_DIALOG);
g_object_set_data(G_OBJECT(find_frame_w), E_FIND_FILT_KEY, filter_text_box);
g_object_set_data(G_OBJECT(find_frame_w), E_FIND_BACKWARD_KEY, up_rb);
g_object_set_data(G_OBJECT(find_frame_w), E_FIND_FILTERDATA_KEY, filter_rb);
g_object_set_data(G_OBJECT(find_frame_w), E_FIND_HEXDATA_KEY, hex_rb);
g_object_set_data(G_OBJECT(find_frame_w), E_FIND_STRINGDATA_KEY, string_rb);
g_object_set_data(G_OBJECT(find_frame_w), E_FIND_STRINGTYPE_LABEL_KEY, combo_lb);
g_object_set_data(G_OBJECT(find_frame_w), E_FIND_STRINGTYPE_KEY, combo_cb);
g_object_set_data(G_OBJECT(find_frame_w), E_CASE_SEARCH_KEY, case_cb);
g_object_set_data(G_OBJECT(find_frame_w), E_SOURCE_DATA_KEY, packet_data_rb);
g_object_set_data(G_OBJECT(find_frame_w), E_SOURCE_DECODE_KEY, decode_data_rb);
g_object_set_data(G_OBJECT(find_frame_w), E_SOURCE_SUMMARY_KEY, summary_data_rb);
g_object_set_data(G_OBJECT(find_frame_w), E_FILT_TE_BUTTON_KEY, filter_bt);
g_signal_connect(hex_rb, "clicked", G_CALLBACK(hex_selected_cb), find_frame_w);
g_signal_connect(string_rb, "clicked", G_CALLBACK(string_selected_cb), find_frame_w);
g_signal_connect(filter_rb, "clicked", G_CALLBACK(filter_selected_cb), find_frame_w);
string_selected_cb(NULL, find_frame_w);
filter_selected_cb(NULL, find_frame_w);
window_set_cancel_button(find_frame_w, cancel_bt, window_cancel_button_cb);
gtk_widget_grab_default(ok_bt);
dlg_set_activate(filter_text_box, ok_bt);
gtk_widget_grab_focus(filter_text_box);
g_signal_connect(find_frame_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(find_frame_w, "destroy", G_CALLBACK(find_frame_destroy_cb), NULL);
gtk_widget_show(find_frame_w);
window_present(find_frame_w);
}
void
find_frame_with_filter(char *filter)
{
find_frame_cb(NULL, NULL);
gtk_entry_set_text(GTK_ENTRY(filter_text_box), filter);
}
static void
find_filter_te_syntax_check_cb(GtkWidget *w, gpointer parent_w)
{
const gchar *strval;
GtkWidget *hex_rb, *string_rb;
guint8 *bytes = NULL;
size_t nbytes;
hex_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_FIND_HEXDATA_KEY);
string_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_FIND_STRINGDATA_KEY);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (hex_rb))) {
strval = gtk_entry_get_text(GTK_ENTRY(w));
if (strval == NULL) {
colorize_filter_te_as_invalid(w);
} else {
bytes = convert_string_to_hex(strval, &nbytes);
if (bytes == NULL)
colorize_filter_te_as_invalid(w);
else {
g_free(bytes);
colorize_filter_te_as_valid(w);
}
}
} else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (string_rb))) {
strval = gtk_entry_get_text(GTK_ENTRY(w));
if (strval == NULL) {
colorize_filter_te_as_invalid(w);
} else {
if (strcmp(strval, "") == 0)
colorize_filter_te_as_invalid(w);
else
colorize_filter_te_as_valid(w);
}
} else {
filter_te_syntax_check_cb(w, NULL);
}
}
static void
hex_selected_cb(GtkWidget *button_rb _U_, gpointer parent_w)
{
GtkWidget *filter_tb, *hex_rb, *filter_entry;
filter_tb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_FILT_TE_PTR_KEY);
hex_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_FIND_HEXDATA_KEY);
filter_entry = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),E_FIND_FILT_KEY);
gtk_widget_grab_focus(filter_entry);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hex_rb)) && g_signal_handler_is_connected(filter_tb, te_presskey_handler_id)) {
g_signal_handler_disconnect(filter_tb, te_presskey_handler_id);
g_signal_handler_disconnect(parent_w, win_presskey_handler_id);
}
find_filter_te_syntax_check_cb(filter_tb, parent_w);
return;
}
static void
string_selected_cb(GtkWidget *button_rb _U_, gpointer parent_w)
{
GtkWidget *string_rb, *packet_data_rb, *decode_data_rb, *summary_data_rb,
*data_combo_lb, *data_combo_cb, *data_case_cb, *filter_tb, *filter_entry;
string_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_FIND_STRINGDATA_KEY);
packet_data_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_SOURCE_DATA_KEY);
decode_data_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_SOURCE_DECODE_KEY);
summary_data_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_SOURCE_SUMMARY_KEY);
data_combo_lb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_FIND_STRINGTYPE_LABEL_KEY);
data_combo_cb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_FIND_STRINGTYPE_KEY);
data_case_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CASE_SEARCH_KEY);
filter_tb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_FILT_TE_PTR_KEY);
filter_entry = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),E_FIND_FILT_KEY);
gtk_widget_grab_focus(filter_entry);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(string_rb))) {
gtk_widget_set_sensitive(GTK_WIDGET(packet_data_rb), TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(decode_data_rb), TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(summary_data_rb), TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(data_combo_lb), TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(data_combo_cb), TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(data_case_cb), TRUE);
if(g_signal_handler_is_connected(filter_tb, te_presskey_handler_id)) {
g_signal_handler_disconnect(filter_tb, te_presskey_handler_id);
g_signal_handler_disconnect(parent_w, win_presskey_handler_id);
}
} else {
gtk_widget_set_sensitive(GTK_WIDGET(packet_data_rb), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(decode_data_rb), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(summary_data_rb), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(data_combo_lb), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(data_combo_cb), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(data_case_cb), FALSE);
}
find_filter_te_syntax_check_cb(filter_tb, parent_w);
return;
}
static void
filter_selected_cb(GtkWidget *button_rb _U_, gpointer parent_w)
{
GtkWidget *filter_bt, *filter_rb, *filter_te, *filter_entry;
filter_bt = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_FILT_TE_BUTTON_KEY);
filter_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_FIND_FILTERDATA_KEY);
filter_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_FILT_TE_PTR_KEY);
filter_entry = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),E_FIND_FILT_KEY);
gtk_widget_grab_focus(filter_entry);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(filter_rb)))
{
gtk_widget_set_sensitive(GTK_WIDGET(filter_bt), TRUE);
if(!g_signal_handler_is_connected(filter_te, te_presskey_handler_id)) {
te_presskey_handler_id = g_signal_connect(filter_te, "key-press-event", G_CALLBACK (filter_string_te_key_pressed_cb), NULL);
win_presskey_handler_id = g_signal_connect(parent_w, "key-press-event", G_CALLBACK (filter_parent_dlg_key_pressed_cb), NULL);
}
}
else
{
gtk_widget_set_sensitive(GTK_WIDGET(filter_bt), FALSE);
}
return;
}
static void
find_frame_ok_cb(GtkWidget *ok_bt _U_, gpointer parent_w)
{
GtkWidget *filter_te, *up_rb, *hex_rb, *string_rb, *combo_cb,
*case_cb, *packet_data_rb, *decode_data_rb, *summary_data_rb;
const gchar *filter_text;
search_charset_t scs_type = SCS_NARROW_AND_WIDE;
guint8 *bytes = NULL;
size_t nbytes = 0;
char *string = NULL;
dfilter_t *sfcode = NULL;
gboolean found_packet=FALSE;
gboolean hex_search;
gboolean string_search;
int string_type;
filter_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_FIND_FILT_KEY);
up_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_FIND_BACKWARD_KEY);
hex_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_FIND_HEXDATA_KEY);
string_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_FIND_STRINGDATA_KEY);
combo_cb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_FIND_STRINGTYPE_KEY);
case_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CASE_SEARCH_KEY);
packet_data_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_SOURCE_DATA_KEY);
decode_data_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_SOURCE_DECODE_KEY);
summary_data_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_SOURCE_SUMMARY_KEY);
filter_text = gtk_entry_get_text(GTK_ENTRY(filter_te));
string_type = gtk_combo_box_get_active (GTK_COMBO_BOX(combo_cb));
case_type = !gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(case_cb));
packet_data = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(packet_data_rb));
decode_data = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(decode_data_rb));
summary_data = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(summary_data_rb));
hex_search = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (hex_rb));
string_search = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (string_rb));
if (hex_search) {
bytes = convert_string_to_hex(filter_text, &nbytes);
if (bytes == NULL) {
statusbar_push_temporary_msg("That's not a valid hex string.");
return;
}
} else if (string_search) {
if (strcmp(filter_text, "") == 0) {
statusbar_push_temporary_msg("You didn't specify any text for which to search.");
return;
}
if (string_type == SCS_NARROW_AND_WIDE)
scs_type = SCS_NARROW_AND_WIDE;
else if (string_type == SCS_NARROW)
scs_type = SCS_NARROW;
else if (string_type == SCS_WIDE)
scs_type = SCS_WIDE;
else {
statusbar_push_temporary_msg("You didn't choose a valid character set.");
return;
}
string = convert_string_case(filter_text, case_type);
} else {
gchar *err_msg;
if (!dfilter_compile(filter_text, &sfcode, &err_msg)) {
bad_dfilter_alert_box(GTK_WIDGET(parent_w), filter_text, err_msg);
g_free(err_msg);
return;
}
if (sfcode == NULL) {
statusbar_push_temporary_msg("That filter doesn't test anything.");
return;
}
}
g_free(cfile.sfilter);
cfile.sfilter = g_strdup(filter_text);
cfile.dir = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (up_rb)) ? SD_BACKWARD : SD_FORWARD;
cfile.hex = hex_search;
cfile.string = string_search;
cfile.scs_type = scs_type;
cfile.case_type = case_type;
cfile.regex = NULL;
cfile.packet_data = packet_data;
cfile.decode_data = decode_data;
cfile.summary_data = summary_data;
if (cfile.hex) {
found_packet = cf_find_packet_data(&cfile, bytes, nbytes, cfile.dir);
g_free(bytes);
if (!found_packet) {
statusbar_push_temporary_msg("No packet contained those bytes.");
return;
}
} else if (cfile.string) {
if (cfile.summary_data) {
found_packet = cf_find_packet_summary_line(&cfile, string, cfile.dir);
g_free(string);
if (!found_packet) {
statusbar_push_temporary_msg("No packet contained that string in its Info column.");
return;
}
} else if (cfile.decode_data) {
found_packet = cf_find_packet_protocol_tree(&cfile, string, cfile.dir);
g_free(string);
if (!found_packet) {
statusbar_push_temporary_msg("No packet contained that string in its dissected display.");
return;
}
} else if (cfile.packet_data && string) {
found_packet = cf_find_packet_data(&cfile, string, strlen(string), cfile.dir);
g_free(string);
if (!found_packet) {
statusbar_push_temporary_msg("No packet contained that string in its ASCII-converted data.");
return;
}
}
} else {
found_packet = cf_find_packet_dfilter(&cfile, sfcode, cfile.dir);
dfilter_free(sfcode);
if (!found_packet) {
statusbar_push_temporary_msg("No packet matched that filter.");
g_free(bytes);
return;
}
}
window_destroy(GTK_WIDGET(parent_w));
}
static void
find_frame_close_cb(GtkWidget *close_bt _U_, gpointer parent_w)
{
gtk_grab_remove(GTK_WIDGET(parent_w));
window_destroy(GTK_WIDGET(parent_w));
}
static void
find_frame_destroy_cb(GtkWidget *win _U_, gpointer user_data _U_)
{
find_frame_w = NULL;
}
static void
find_previous_next(GtkWidget *w, gpointer d, search_direction dir)
{
guint8 *bytes;
size_t nbytes;
char *string;
dfilter_t *sfcode;
if (cfile.sfilter) {
cfile.dir = dir;
if (cfile.hex) {
bytes = convert_string_to_hex(cfile.sfilter, &nbytes);
if (bytes == NULL) {
return;
}
cf_find_packet_data(&cfile, bytes, nbytes, dir);
g_free(bytes);
} else if (cfile.string) {
string = convert_string_case(cfile.sfilter, cfile.case_type);
if (cfile.decode_data) {
cf_find_packet_protocol_tree(&cfile, string, dir);
} else if (cfile.summary_data) {
cf_find_packet_summary_line(&cfile, string, dir);
} else {
cf_find_packet_data(&cfile, string, strlen(string), dir);
}
g_free(string);
} else {
if (!dfilter_compile(cfile.sfilter, &sfcode, NULL)) {
return;
}
if (sfcode == NULL) {
return;
}
cf_find_packet_dfilter(&cfile, sfcode, dir);
dfilter_free(sfcode);
}
} else
find_frame_cb(w, d);
}
void
find_next_cb(GtkWidget *w , gpointer d)
{
find_previous_next(w, d, SD_FORWARD);
}
void
find_previous_cb(GtkWidget *w , gpointer d)
{
find_previous_next(w, d, SD_BACKWARD);
}
