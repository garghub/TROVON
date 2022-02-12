gboolean
range_check_validity(packet_range_t *range)
{
switch (packet_range_check(range)) {
case CVT_NO_ERROR:
return TRUE;
case CVT_SYNTAX_ERROR:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"The specified range of packets isn't a valid range.");
return FALSE;
case CVT_NUMBER_TOO_BIG:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"The specified range of packets has a packet number that's too large.");
return FALSE;
default:
g_assert_not_reached();
return FALSE;
}
}
gboolean
range_check_validity_modal(GtkWidget *parent, packet_range_t *range)
{
GtkWidget *dialog;
switch (packet_range_check(range)) {
case CVT_NO_ERROR:
return TRUE;
case CVT_SYNTAX_ERROR:
dialog = gtk_message_dialog_new(GTK_WINDOW(parent),
GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_ERROR,
GTK_BUTTONS_OK,
"The specified range of packets isn't a valid range.");
gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog);
return FALSE;
case CVT_NUMBER_TOO_BIG:
dialog = gtk_message_dialog_new(GTK_WINDOW(parent),
GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_ERROR,
GTK_BUTTONS_OK,
"The specified range of packets has a packet number that's too large.");
gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog);
return FALSE;
default:
g_assert_not_reached();
return FALSE;
}
}
void
range_update_dynamics(gpointer data)
{
packet_range_t *range;
GtkWidget *range_displayed_bt;
gboolean filtered_active;
gint selected_num;
gboolean can_select;
gboolean selected_packets;
gchar label_text[100];
guint32 ignored_cnt = 0, displayed_ignored_cnt = 0;
guint32 displayed_cnt;
range = g_object_get_data(G_OBJECT(data), RANGE_VALUES_KEY);
range_displayed_bt = g_object_get_data(G_OBJECT(data), RANGE_DISPLAYED_BT_KEY);
filtered_active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(range_displayed_bt));
if (range->displayed_cnt != 0)
gtk_widget_set_sensitive(range_displayed_bt, TRUE);
else {
filtered_active = FALSE;
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(g_object_get_data(G_OBJECT(data), RANGE_SELECT_ALL_KEY)), FALSE);
gtk_widget_set_sensitive(range_displayed_bt, FALSE);
}
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_ALL_C_KEY), !filtered_active);
if (range->remove_ignored) {
g_snprintf(label_text, sizeof(label_text), "%u", cfile.count - range->ignored_cnt);
} else {
g_snprintf(label_text, sizeof(label_text), "%u", cfile.count);
}
gtk_label_set_text(GTK_LABEL(g_object_get_data(G_OBJECT(data), RANGE_SELECT_ALL_C_KEY)), label_text);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_ALL_D_KEY), filtered_active);
if (range->include_dependents)
displayed_cnt = range->displayed_plus_dependents_cnt;
else
displayed_cnt = range->displayed_cnt;
if (range->remove_ignored) {
g_snprintf(label_text, sizeof(label_text), "%u", displayed_cnt - range->displayed_ignored_cnt);
} else {
g_snprintf(label_text, sizeof(label_text), "%u", displayed_cnt);
}
gtk_label_set_text(GTK_LABEL(g_object_get_data(G_OBJECT(data), RANGE_SELECT_ALL_D_KEY)), label_text);
selected_num = (cfile.current_frame) ? cfile.current_frame->num : 0;
can_select = (selected_num != 0);
if (can_select) {
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_CURR_KEY), TRUE);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_CURR_C_KEY), !filtered_active);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_CURR_D_KEY), filtered_active);
} else {
if (range->process == range_process_selected) {
range->process = range_process_all;
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(g_object_get_data(G_OBJECT(data), RANGE_SELECT_ALL_KEY)), TRUE);
}
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_CURR_KEY), FALSE);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_CURR_C_KEY), FALSE);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_CURR_D_KEY), FALSE);
}
if (range->remove_ignored && can_select && cfile.current_frame->flags.ignored) {
g_snprintf(label_text, sizeof(label_text), "0");
} else {
g_snprintf(label_text, sizeof(label_text), "%u", selected_num ? 1 : 0);
}
gtk_label_set_text(GTK_LABEL(g_object_get_data(G_OBJECT(data), RANGE_SELECT_CURR_C_KEY)), label_text);
if (range->remove_ignored && can_select && cfile.current_frame->flags.ignored) {
g_snprintf(label_text, sizeof(label_text), "0");
} else {
g_snprintf(label_text, sizeof(label_text), "%u", selected_num ? 1 : 0);
}
gtk_label_set_text(GTK_LABEL(g_object_get_data(G_OBJECT(data), RANGE_SELECT_CURR_D_KEY)), label_text);
if (filtered_active)
selected_packets = (range->displayed_marked_cnt != 0);
else
selected_packets = (cfile.marked_count > 0);
if (selected_packets) {
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_KEY), TRUE);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_C_KEY), !filtered_active);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_D_KEY), filtered_active);
}
else {
if (range->process == range_process_marked) {
range->process = range_process_all;
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(g_object_get_data(G_OBJECT(data), RANGE_SELECT_ALL_KEY)), TRUE);
}
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_KEY), FALSE);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_C_KEY), FALSE);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_D_KEY), FALSE);
}
if (range->remove_ignored) {
g_snprintf(label_text, sizeof(label_text), "%u", cfile.marked_count - range->ignored_marked_cnt);
} else {
g_snprintf(label_text, sizeof(label_text), "%u", cfile.marked_count);
}
gtk_label_set_text(GTK_LABEL(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_C_KEY)), label_text);
if (range->remove_ignored) {
g_snprintf(label_text, sizeof(label_text), "%u", range->displayed_marked_cnt - range->displayed_ignored_marked_cnt);
} else {
g_snprintf(label_text, sizeof(label_text), "%u", range->displayed_marked_cnt);
}
gtk_label_set_text(GTK_LABEL(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_D_KEY)), label_text);
if (filtered_active)
selected_packets = (range->displayed_mark_range_cnt != 0);
else
selected_packets = (range->mark_range_cnt != 0);
if (selected_packets) {
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_RANGE_KEY), TRUE);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_RANGE_C_KEY), !filtered_active);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_RANGE_D_KEY), filtered_active);
}
else {
if (range->process == range_process_marked_range) {
range->process = range_process_all;
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(g_object_get_data(G_OBJECT(data), RANGE_SELECT_ALL_KEY)), TRUE);
}
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_RANGE_KEY), FALSE);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_RANGE_C_KEY), FALSE);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_RANGE_D_KEY), FALSE);
}
if (range->remove_ignored) {
g_snprintf(label_text, sizeof(label_text), "%u", range->mark_range_cnt - range->ignored_mark_range_cnt);
} else {
g_snprintf(label_text, sizeof(label_text), "%u", range->mark_range_cnt);
}
gtk_label_set_text(GTK_LABEL(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_RANGE_C_KEY)), label_text);
if (range->remove_ignored) {
g_snprintf(label_text, sizeof(label_text), "%u", range->displayed_mark_range_cnt - range->displayed_ignored_mark_range_cnt);
} else {
g_snprintf(label_text, sizeof(label_text), "%u", range->displayed_mark_range_cnt);
}
gtk_label_set_text(GTK_LABEL(g_object_get_data(G_OBJECT(data), RANGE_SELECT_MARKED_RANGE_D_KEY)), label_text);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_USER_KEY), TRUE);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_USER_C_KEY), !filtered_active);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_USER_D_KEY), filtered_active);
if (range->remove_ignored) {
g_snprintf(label_text, sizeof(label_text), "%u", range->user_range_cnt - range->ignored_user_range_cnt);
} else {
g_snprintf(label_text, sizeof(label_text), "%u", range->user_range_cnt);
}
gtk_label_set_text(GTK_LABEL(g_object_get_data(G_OBJECT(data), RANGE_SELECT_USER_C_KEY)), label_text);
if (range->remove_ignored) {
g_snprintf(label_text, sizeof(label_text), "%u", range->displayed_user_range_cnt - range->displayed_ignored_user_range_cnt);
} else {
g_snprintf(label_text, sizeof(label_text), "%u", range->displayed_user_range_cnt);
}
gtk_label_set_text(GTK_LABEL(g_object_get_data(G_OBJECT(data), RANGE_SELECT_USER_D_KEY)), label_text);
switch(range->process) {
case(range_process_all):
ignored_cnt = range->ignored_cnt;
displayed_ignored_cnt = range->displayed_ignored_cnt;
break;
case(range_process_selected):
ignored_cnt = (can_select && cfile.current_frame->flags.ignored) ? 1 : 0;
displayed_ignored_cnt = ignored_cnt;
break;
case(range_process_marked):
ignored_cnt = range->ignored_marked_cnt;
displayed_ignored_cnt = range->displayed_ignored_marked_cnt;
break;
case(range_process_marked_range):
ignored_cnt = range->ignored_mark_range_cnt;
displayed_ignored_cnt = range->displayed_ignored_mark_range_cnt;
break;
case(range_process_user_range):
ignored_cnt = range->ignored_user_range_cnt;
displayed_ignored_cnt = range->displayed_ignored_user_range_cnt;
break;
default:
g_assert_not_reached();
}
if (filtered_active)
selected_packets = (displayed_ignored_cnt != 0);
else
selected_packets = (ignored_cnt != 0);
if (selected_packets) {
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_REMOVE_IGNORED_KEY), TRUE);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_IGNORED_C_KEY), !filtered_active);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_IGNORED_D_KEY), filtered_active);
} else {
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_REMOVE_IGNORED_KEY), FALSE);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_IGNORED_C_KEY), FALSE);
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_IGNORED_D_KEY), FALSE);
}
g_snprintf(label_text, sizeof(label_text), "%u", ignored_cnt);
gtk_label_set_text(GTK_LABEL(g_object_get_data(G_OBJECT(data), RANGE_IGNORED_C_KEY)), label_text); g_snprintf(label_text, sizeof(label_text), "%u", displayed_ignored_cnt);
gtk_label_set_text(GTK_LABEL(g_object_get_data(G_OBJECT(data), RANGE_IGNORED_D_KEY)), label_text);
}
static void
toggle_captured_cb(GtkWidget *widget, gpointer data)
{
GtkWidget *bt;
packet_range_t *range;
range = g_object_get_data(G_OBJECT(data), RANGE_VALUES_KEY);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget))) {
range->process_filtered = FALSE;
bt = g_object_get_data(G_OBJECT(data), RANGE_CAPTURED_BT_KEY);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bt), TRUE);
bt = g_object_get_data(G_OBJECT(data), RANGE_DISPLAYED_BT_KEY);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bt), FALSE);
range_update_dynamics(data);
}
}
static void
toggle_filtered_cb(GtkWidget *widget, gpointer data)
{
GtkWidget *bt;
packet_range_t *range;
range = g_object_get_data(G_OBJECT(data), RANGE_VALUES_KEY);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget))) {
range->process_filtered = TRUE;
bt = g_object_get_data(G_OBJECT(data), RANGE_CAPTURED_BT_KEY);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bt), FALSE);
bt = g_object_get_data(G_OBJECT(data), RANGE_DISPLAYED_BT_KEY);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bt), TRUE);
range_update_dynamics(data);
}
}
static void
toggle_select_all(GtkWidget *widget, gpointer data)
{
packet_range_t *range;
range = g_object_get_data(G_OBJECT(data), RANGE_VALUES_KEY);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget))) {
range->process = range_process_all;
range_update_dynamics(data);
}
}
static void
toggle_select_selected(GtkWidget *widget, gpointer data)
{
packet_range_t *range;
range = g_object_get_data(G_OBJECT(data), RANGE_VALUES_KEY);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget))) {
range->process = range_process_selected;
range_update_dynamics(data);
}
}
static void
toggle_select_marked_only(GtkWidget *widget, gpointer data)
{
packet_range_t *range;
range = g_object_get_data(G_OBJECT(data), RANGE_VALUES_KEY);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget))) {
range->process = range_process_marked;
range_update_dynamics(data);
}
}
static void
toggle_select_marked_range(GtkWidget *widget, gpointer data)
{
packet_range_t *range;
range = g_object_get_data(G_OBJECT(data), RANGE_VALUES_KEY);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget))) {
range->process = range_process_marked_range;
range_update_dynamics(data);
}
}
static void
toggle_select_user_range(GtkWidget *widget, gpointer data)
{
packet_range_t *range;
range = g_object_get_data(G_OBJECT(data), RANGE_VALUES_KEY);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget))) {
range->process = range_process_user_range;
range_update_dynamics(data);
}
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(data), RANGE_SELECT_USER_ENTRY_KEY), range->process == range_process_user_range);
if (range->process == range_process_user_range)
gtk_widget_grab_focus(g_object_get_data(G_OBJECT(data), RANGE_SELECT_USER_ENTRY_KEY));
}
static void
toggle_remove_ignored(GtkWidget *widget, gpointer data)
{
packet_range_t *range;
range = g_object_get_data(G_OBJECT(data), RANGE_VALUES_KEY);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget))) {
range->remove_ignored = TRUE;
} else {
range->remove_ignored = FALSE;
}
range_update_dynamics(data);
}
static void
range_entry(GtkWidget *widget _U_, gpointer data)
{
const gchar *entry_text;
GtkWidget *entry;
packet_range_t *range;
range = g_object_get_data(G_OBJECT(data), RANGE_VALUES_KEY);
entry = g_object_get_data(G_OBJECT(data), RANGE_SELECT_USER_ENTRY_KEY);
gtk_toggle_button_set_active(g_object_get_data(G_OBJECT(data), RANGE_SELECT_USER_KEY), TRUE);
entry_text = gtk_entry_get_text (GTK_ENTRY (entry));
packet_range_convert_str(range, entry_text);
range_update_dynamics(data);
}
static void
range_entry_in_event(GtkWidget *widget _U_, GdkEventFocus *event _U_, gpointer user_data _U_)
{
}
GtkWidget *range_new(packet_range_t *range, gboolean saving)
{
GtkWidget *range_tb;
GtkWidget *captured_bt;
GtkWidget *displayed_bt;
GtkWidget *select_all_rb;
GtkWidget *select_all_c_lb;
GtkWidget *select_all_d_lb;
GtkWidget *select_curr_rb;
GtkWidget *select_curr_c_lb;
GtkWidget *select_curr_d_lb;
GtkWidget *select_marked_only_rb;
GtkWidget *select_marked_only_c_lb;
GtkWidget *select_marked_only_d_lb;
GtkWidget *select_marked_range_rb;
GtkWidget *select_marked_range_c_lb;
GtkWidget *select_marked_range_d_lb;
GtkWidget *select_user_range_rb;
GtkWidget *select_user_range_c_lb;
GtkWidget *select_user_range_d_lb;
GtkWidget *select_user_range_entry;
GtkWidget *remove_ignored_cb;
GtkWidget *ignored_c_lb;
GtkWidget *ignored_d_lb;
range_tb = gtk_table_new(7, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(range_tb), 5);
captured_bt = gtk_toggle_button_new_with_mnemonic("_Captured");
gtk_table_attach_defaults(GTK_TABLE(range_tb), captured_bt, 1, 2, 0, 1);
g_signal_connect(captured_bt, "toggled", G_CALLBACK(toggle_captured_cb), range_tb);
gtk_widget_set_tooltip_text (captured_bt,("Process all the below chosen packets"));
displayed_bt = gtk_toggle_button_new_with_mnemonic("_Displayed");
gtk_table_attach_defaults(GTK_TABLE(range_tb), displayed_bt, 2, 3, 0, 1);
g_signal_connect(displayed_bt, "toggled", G_CALLBACK(toggle_filtered_cb), range_tb);
if (saving)
gtk_widget_set_tooltip_text (displayed_bt,("Save the packets chosen below which also pass the current display filter. If"
" \"all packets\" is selected then packets required (e.g., for reassembled data) by the packets"
" that passed the display filter are also included."));
else
gtk_widget_set_tooltip_text (displayed_bt,("Process only the below chosen packets which also pass the current display filter"));
select_all_rb = gtk_radio_button_new_with_mnemonic_from_widget(NULL, "_All packets");
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_all_rb, 0, 1, 1, 2);
gtk_widget_set_tooltip_text (select_all_rb, ("Process all packets"));
g_signal_connect(select_all_rb, "toggled", G_CALLBACK(toggle_select_all), range_tb);
select_all_c_lb = gtk_label_new("?");
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_all_c_lb, 1, 2, 1, 2);
select_all_d_lb = gtk_label_new("?");
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_all_d_lb, 2, 3, 1, 2);
select_curr_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(select_all_rb), "_Selected packet only");
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_curr_rb, 0, 1, 2, 3);
gtk_widget_set_tooltip_text (select_curr_rb, ("Process the currently selected packet only"));
g_signal_connect(select_curr_rb, "toggled", G_CALLBACK(toggle_select_selected), range_tb);
select_curr_c_lb = gtk_label_new("?");
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_curr_c_lb, 1, 2, 2, 3);
select_curr_d_lb = gtk_label_new("?");
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_curr_d_lb, 2, 3, 2, 3);
select_marked_only_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(select_all_rb), "_Marked packets only");
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_marked_only_rb, 0, 1, 3, 4);
gtk_widget_set_tooltip_text (select_marked_only_rb, ("Process marked packets only"));
g_signal_connect(select_marked_only_rb, "toggled", G_CALLBACK(toggle_select_marked_only), range_tb);
select_marked_only_c_lb = gtk_label_new("?");
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_marked_only_c_lb, 1, 2, 3, 4);
select_marked_only_d_lb = gtk_label_new("?");
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_marked_only_d_lb, 2, 3, 3, 4);
select_marked_range_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(select_all_rb), "From first _to last marked packet");
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_marked_range_rb, 0, 1, 4, 5);
gtk_widget_set_tooltip_text (select_marked_range_rb,("Process all packets between the first and last marker"));
g_signal_connect(select_marked_range_rb, "toggled", G_CALLBACK(toggle_select_marked_range), range_tb);
select_marked_range_c_lb = gtk_label_new("?");
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_marked_range_c_lb, 1, 2, 4, 5);
select_marked_range_d_lb = gtk_label_new("?");
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_marked_range_d_lb, 2, 3, 4, 5);
select_user_range_rb = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(select_all_rb), "Specify a packet _range:");
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_user_range_rb, 0, 1, 5, 6);
gtk_widget_set_tooltip_text (select_user_range_rb,("Process a specified packet range"));
g_signal_connect(select_user_range_rb, "toggled", G_CALLBACK(toggle_select_user_range), range_tb);
select_user_range_c_lb = gtk_label_new("?");
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_user_range_c_lb, 1, 2, 5, 6);
select_user_range_d_lb = gtk_label_new("?");
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_user_range_d_lb, 2, 3, 5, 6);
select_user_range_entry = gtk_entry_new();
gtk_entry_set_max_length (GTK_ENTRY (select_user_range_entry), 254);
gtk_table_attach_defaults(GTK_TABLE(range_tb), select_user_range_entry, 0, 1, 6, 7);
gtk_widget_set_tooltip_text (select_user_range_entry, ("Specify a range of packet numbers : \nExample : 1-10,18,25-100,332-"));
g_signal_connect(select_user_range_entry,"changed", G_CALLBACK(range_entry), range_tb);
g_signal_connect(select_user_range_entry,"activate", G_CALLBACK(range_entry_in_event), range_tb);
remove_ignored_cb = gtk_check_button_new_with_mnemonic("Remove _Ignored packets");
gtk_table_attach_defaults(GTK_TABLE(range_tb), remove_ignored_cb, 0, 1, 7, 8);
gtk_widget_set_tooltip_text (remove_ignored_cb,("Remove all packets marked as Ignored"));
g_signal_connect(remove_ignored_cb, "toggled", G_CALLBACK(toggle_remove_ignored), range_tb);
ignored_c_lb = gtk_label_new("?");
gtk_table_attach_defaults(GTK_TABLE(range_tb), ignored_c_lb, 1, 2, 7, 8);
ignored_d_lb = gtk_label_new("?");
gtk_table_attach_defaults(GTK_TABLE(range_tb), ignored_d_lb, 2, 3, 7, 8);
gtk_widget_show_all(range_tb);
g_object_set_data(G_OBJECT(range_tb), RANGE_VALUES_KEY, range);
g_object_set_data(G_OBJECT(range_tb), RANGE_CAPTURED_BT_KEY, captured_bt);
g_object_set_data(G_OBJECT(range_tb), RANGE_DISPLAYED_BT_KEY, displayed_bt);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_ALL_KEY, select_all_rb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_ALL_C_KEY, select_all_c_lb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_ALL_D_KEY, select_all_d_lb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_CURR_KEY, select_curr_rb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_CURR_C_KEY, select_curr_c_lb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_CURR_D_KEY, select_curr_d_lb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_CURR_D_KEY, select_curr_d_lb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_MARKED_KEY, select_marked_only_rb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_MARKED_C_KEY, select_marked_only_c_lb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_MARKED_D_KEY, select_marked_only_d_lb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_MARKED_RANGE_KEY, select_marked_range_rb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_MARKED_RANGE_C_KEY,select_marked_range_c_lb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_MARKED_RANGE_D_KEY,select_marked_range_d_lb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_USER_KEY, select_user_range_rb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_USER_C_KEY, select_user_range_c_lb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_USER_D_KEY, select_user_range_d_lb);
g_object_set_data(G_OBJECT(range_tb), RANGE_SELECT_USER_ENTRY_KEY, select_user_range_entry);
g_object_set_data(G_OBJECT(range_tb), RANGE_REMOVE_IGNORED_KEY, remove_ignored_cb);
g_object_set_data(G_OBJECT(range_tb), RANGE_IGNORED_C_KEY, ignored_c_lb);
g_object_set_data(G_OBJECT(range_tb), RANGE_IGNORED_D_KEY, ignored_d_lb);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(captured_bt), !range->process_filtered);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(displayed_bt), range->process_filtered);
switch(range->process) {
case(range_process_all):
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(select_all_rb), TRUE);
break;
case(range_process_selected):
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(select_curr_rb), TRUE);
break;
case(range_process_marked):
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(select_marked_only_rb), TRUE);
break;
case(range_process_marked_range):
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(select_marked_range_rb), TRUE);
break;
case(range_process_user_range):
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(select_user_range_rb), TRUE);
break;
default:
g_assert_not_reached();
}
return range_tb;
}
