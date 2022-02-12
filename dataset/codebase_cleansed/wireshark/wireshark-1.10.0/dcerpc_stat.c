static gboolean
uuid_equal(e_uuid_t *uuid1, e_uuid_t *uuid2)
{
if( (uuid1->Data1 != uuid2->Data1)
||(uuid1->Data2 != uuid2->Data2)
||(uuid1->Data3 != uuid2->Data3)
||(uuid1->Data4[0] != uuid2->Data4[0])
||(uuid1->Data4[1] != uuid2->Data4[1])
||(uuid1->Data4[2] != uuid2->Data4[2])
||(uuid1->Data4[3] != uuid2->Data4[3])
||(uuid1->Data4[4] != uuid2->Data4[4])
||(uuid1->Data4[5] != uuid2->Data4[5])
||(uuid1->Data4[6] != uuid2->Data4[6])
||(uuid1->Data4[7] != uuid2->Data4[7]) ){
return FALSE;
}
return TRUE;
}
static char *
dcerpcstat_gen_title(dcerpcstat_t *rs)
{
char *title;
char *display_name;
display_name = cf_get_display_name(&cfile);
title = g_strdup_printf("DCE-RPC Service Response Time statistics for %s major version %u: %s", rs->prog, rs->ver, display_name);
g_free(display_name);
return title;
}
static void
dcerpcstat_set_title(dcerpcstat_t *rs)
{
char *title;
title = dcerpcstat_gen_title(rs);
gtk_window_set_title(GTK_WINDOW(rs->win), title);
g_free(title);
}
static void
dcerpcstat_reset(void *rs_arg)
{
dcerpcstat_t *rs = (dcerpcstat_t *)rs_arg;
reset_srt_table_data(&rs->srt_table);
dcerpcstat_set_title(rs);
}
static gboolean
dcerpcstat_packet(void *rs_arg, packet_info *pinfo, epan_dissect_t *edt _U_, const void *ri_arg)
{
dcerpcstat_t *rs = (dcerpcstat_t *)rs_arg;
const dcerpc_info *ri = (dcerpc_info *)ri_arg;
if(!ri->call_data){
return FALSE;
}
if(!ri->call_data->req_frame){
return FALSE;
}
if(ri->call_data->opnum >= rs->num_procedures){
return FALSE;
}
if(ri->ptype != PDU_RESP){
return FALSE;
}
if( (!uuid_equal( (&ri->call_data->uuid), (&rs->uuid)))
||(ri->call_data->ver != rs->ver)){
return FALSE;
}
add_srt_table_data(&rs->srt_table, ri->call_data->opnum, &ri->call_data->req_time, pinfo);
return TRUE;
}
static void
dcerpcstat_draw(void *rs_arg)
{
dcerpcstat_t *rs = (dcerpcstat_t *)rs_arg;
draw_srt_table_data(&rs->srt_table);
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
dcerpcstat_t *rs = (dcerpcstat_t *)data;
remove_tap_listener(rs);
free_srt_table_data(&rs->srt_table);
g_free(rs);
}
static void
gtk_dcerpcstat_init(const char *opt_arg, void* userdata _U_)
{
dcerpcstat_t *rs;
guint32 i, max_procs;
char *title_string;
char *filter_string;
GtkWidget *vbox;
GtkWidget *stat_label;
GtkWidget *filter_label;
GtkWidget *bbox;
GtkWidget *close_bt;
dcerpc_sub_dissector *procs;
e_uuid_t uuid;
guint d1,d2,d3,d40,d41,d42,d43,d44,d45,d46,d47;
int major, minor;
guint16 ver;
int pos = 0;
const char *filter = NULL;
GString *error_string;
int hf_opnum;
if(sscanf(
opt_arg,
"dcerpc,srt,%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x,%d.%d,%n",
&d1,&d2,&d3,&d40,&d41,&d42,&d43,&d44,&d45,&d46,&d47,&major,&minor,&pos)
== 13) {
uuid.Data1 = d1;
uuid.Data2 = d2;
uuid.Data3 = d3;
uuid.Data4[0] = d40;
uuid.Data4[1] = d41;
uuid.Data4[2] = d42;
uuid.Data4[3] = d43;
uuid.Data4[4] = d44;
uuid.Data4[5] = d45;
uuid.Data4[6] = d46;
uuid.Data4[7] = d47;
if(pos) {
filter = opt_arg+pos;
} else {
filter = NULL;
}
} else {
fprintf(stderr, "wireshark: invalid \"-z dcerpc,srt,<uuid>,<major version>.<minor version>[,<filter>]\" argument\n");
exit(1);
}
if ((major < 0) || (major > 65535)) {
fprintf(stderr,"wireshark: dcerpcstat_init() Major version number %d is invalid - must be positive and <= 65535\n", major);
exit(1);
}
if ((minor < 0) || (minor > 65535)) {
fprintf(stderr,"wireshark: dcerpcstat_init() Minor version number %d is invalid - must be positive and <= 65535\n", minor);
exit(1);
}
ver = major;
rs = (dcerpcstat_t *)g_malloc(sizeof(dcerpcstat_t));
rs->prog = dcerpc_get_proto_name(&uuid, ver);
if(!rs->prog){
g_free(rs);
fprintf(stderr,
"wireshark: dcerpcstat_init() Protocol with uuid:%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x v%u not supported\n",
uuid.Data1,uuid.Data2,uuid.Data3,uuid.Data4[0],uuid.Data4[1],uuid.Data4[2],uuid.Data4[3],uuid.Data4[4],uuid.Data4[5],uuid.Data4[6],uuid.Data4[7],ver);
exit(1);
}
hf_opnum = dcerpc_get_proto_hf_opnum(&uuid, ver);
procs = dcerpc_get_proto_sub_dissector(&uuid, ver);
rs->uuid = uuid;
rs->ver = ver;
rs->win = dlg_window_new("dcerpc-stat");
gtk_window_set_destroy_with_parent(GTK_WINDOW(rs->win), TRUE);
dcerpcstat_set_title(rs);
gtk_window_set_default_size(GTK_WINDOW(rs->win), 550, 400);
vbox =ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(rs->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
title_string = dcerpcstat_gen_title(rs);
stat_label = gtk_label_new(title_string);
g_free(title_string);
gtk_box_pack_start(GTK_BOX(vbox), stat_label, FALSE, FALSE, 0);
filter_string = g_strdup_printf("Filter: %s",filter ? filter : "");
filter_label = gtk_label_new(filter_string);
g_free(filter_string);
gtk_label_set_line_wrap(GTK_LABEL(filter_label), TRUE);
gtk_box_pack_start(GTK_BOX(vbox), filter_label, FALSE, FALSE, 0);
for(i=0,max_procs=0;procs[i].name;i++){
if(procs[i].num>max_procs){
max_procs = procs[i].num;
}
}
rs->num_procedures = max_procs+1;
gtk_widget_show_all(rs->win);
if(hf_opnum != -1){
init_srt_table(&rs->srt_table, max_procs+1, vbox, proto_registrar_get_nth(hf_opnum)->abbrev);
} else {
init_srt_table(&rs->srt_table, max_procs+1, vbox, NULL);
}
for(i=0;i<(max_procs+1);i++){
int j;
const char *proc_name;
proc_name = "unknown";
for(j=0;procs[j].name;j++){
if (procs[j].num == i){
proc_name = procs[j].name;
}
}
init_srt_table_row(&rs->srt_table, i, proc_name);
}
error_string = register_tap_listener("dcerpc", rs, filter, 0, dcerpcstat_reset, dcerpcstat_packet, dcerpcstat_draw);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
free_srt_table_data(&rs->srt_table);
g_free(rs);
return;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_end(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(rs->win, close_bt, window_cancel_button_cb);
g_signal_connect(rs->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(rs->win, "destroy", G_CALLBACK(win_destroy_cb), rs);
gtk_widget_show_all(rs->win);
window_present(rs->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(rs->win));
}
static void
dcerpcstat_start_button_clicked(GtkWidget *item _U_, gpointer data _U_)
{
GString *str;
const char *filter;
if (dcerpc_uuid_program == NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Please select a program");
return;
}
str = g_string_new("dcerpc,srt");
g_string_append_printf(str,
",%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x,%u.%u",
dcerpc_uuid_program->Data1, dcerpc_uuid_program->Data2,
dcerpc_uuid_program->Data3,
dcerpc_uuid_program->Data4[0], dcerpc_uuid_program->Data4[1],
dcerpc_uuid_program->Data4[2], dcerpc_uuid_program->Data4[3],
dcerpc_uuid_program->Data4[4], dcerpc_uuid_program->Data4[5],
dcerpc_uuid_program->Data4[6], dcerpc_uuid_program->Data4[7],
dcerpc_version, 0);
filter = gtk_entry_get_text(GTK_ENTRY(filter_entry));
if(filter[0] != 0){
g_string_append_printf(str, ",%s", filter);
}
gtk_dcerpcstat_init(str->str,NULL);
g_string_free(str, TRUE);
}
static void
dcerpcstat_version_select(GtkWidget *vers_combo_box, gpointer user_data _U_)
{
dcerpc_uuid_key *k;
if (! ws_combo_box_get_active_pointer(GTK_COMBO_BOX(vers_combo_box), (gpointer *)&k)) {
g_assert_not_reached();
}
dcerpc_version = k->ver;
}
static void
dcerpcstat_find_vers(gpointer *key, gpointer *value _U_, gpointer user_data)
{
dcerpc_uuid_key *k = (dcerpc_uuid_key *)key;
GtkWidget *vers_combo_box = (GtkWidget *)user_data;
char vs[5];
if(!uuid_equal(&(k->uuid), dcerpc_uuid_program)){
return;
}
g_snprintf(vs, sizeof(vs), "%u", k->ver);
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(vers_combo_box), vs, k);
}
static void
dcerpcstat_program_select(GtkWidget *prog_combo_box, gpointer user_data)
{
dcerpc_uuid_key *k;
GtkWidget *vers_combo_box;
vers_combo_box = (GtkWidget *)user_data;
if (! ws_combo_box_get_active_pointer(GTK_COMBO_BOX(prog_combo_box), (gpointer *)&k)) {
g_assert_not_reached();
}
g_signal_handlers_disconnect_by_func(vers_combo_box, G_CALLBACK(dcerpcstat_version_select), NULL );
ws_combo_box_clear_text_and_pointer(GTK_COMBO_BOX(vers_combo_box));
g_assert(k != NULL);
dcerpc_uuid_program = &(k->uuid);
g_signal_handlers_disconnect_by_func(vers_combo_box, G_CALLBACK(dcerpcstat_version_select), NULL );
ws_combo_box_clear_text_and_pointer(GTK_COMBO_BOX(vers_combo_box));
g_hash_table_foreach(dcerpc_uuids, (GHFunc)dcerpcstat_find_vers, vers_combo_box);
g_signal_connect(vers_combo_box, "changed", G_CALLBACK(dcerpcstat_version_select), NULL);
ws_combo_box_set_active(GTK_COMBO_BOX(vers_combo_box), 0);
}
static GtkTreeIter
dcerpcstat_add_program_to_menu(dcerpc_uuid_key *k, dcerpc_uuid_value *v, GtkWidget *prog_combo_box, int program_item_index)
{
static GtkTreeIter iter;
char str[64];
switch(program_item_index%15){
case 0:
g_snprintf(str,sizeof(str),"%s ...",v->name);
iter = ws_combo_box_append_text_and_pointer_full(
GTK_COMBO_BOX(prog_combo_box), NULL, str, NULL, FALSE);
break;
default:
break;
}
return ws_combo_box_append_text_and_pointer_full(
GTK_COMBO_BOX(prog_combo_box), &iter, v->name, k, TRUE);
}
static void
dcerpcstat_find_next_program(gpointer *key, gpointer *value, gpointer *user_data _U_)
{
dcerpc_uuid_key *k = (dcerpc_uuid_key *)key;
dcerpc_uuid_value *v = (dcerpc_uuid_value *)value;
if((current_uuid_key==NULL) && (new_uuid_key==NULL)){
new_uuid_key = k;
new_uuid_value = v;
return;
}
if(current_uuid_key==NULL){
if(strcmp(new_uuid_value->name, v->name)>0){
new_uuid_key = k;
new_uuid_value = v;
return;
}
return;
}
if(strcmp(current_uuid_value->name, v->name) >= 0){
return;
}
if(new_uuid_key==NULL){
new_uuid_key = k;
new_uuid_value = v;
return;
}
if(strcmp(new_uuid_value->name, v->name) > 0){
new_uuid_key = k;
new_uuid_value = v;
return;
}
return;
}
static void
dlg_destroy_cb(GtkWidget *w _U_, gpointer user_data _U_)
{
dlg = NULL;
}
void gtk_dcerpcstat_cb(GtkAction *action _U_, gpointer user_data _U_)
{
GtkWidget *dlg_box;
GtkWidget *prog_box, *prog_label, *prog_combo_box;
GtkWidget *vers_label, *vers_combo_box;
GtkWidget *filter_box, *filter_bt;
GtkWidget *bbox, *start_button, *cancel_button;
GtkCellRenderer *cell_renderer;
#if 0
GtkTreeIter program_first_item_iter;
#endif
const char *filter;
int program_item_index = 0;
static construct_args_t args = {
"Service Response Time Statistics Filter",
FALSE,
FALSE,
FALSE
};
if(dlg){
reactivate_window(dlg);
return;
}
dlg = dlg_window_new("Wireshark: Compute DCE-RPC SRT statistics");
gtk_window_set_default_size(GTK_WINDOW(dlg), 400, -1);
dlg_box = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 10, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(dlg_box), 10);
gtk_container_add(GTK_CONTAINER(dlg), dlg_box);
gtk_widget_show(dlg_box);
prog_box = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(prog_box), 10);
prog_label = gtk_label_new("Program:");
gtk_box_pack_start(GTK_BOX(prog_box), prog_label, FALSE, FALSE, 0);
gtk_widget_show(prog_label);
dcerpc_uuid_program = NULL;
prog_combo_box = ws_combo_box_new_text_and_pointer_full(&cell_renderer);
{
#if GTK_CHECK_VERSION(3,0,0)
GtkStyleContext *context;
GdkRGBA *new_rgba_fg_color;
context = gtk_widget_get_style_context (prog_combo_box);
gtk_style_context_get (context, GTK_STATE_FLAG_NORMAL,
"color", &new_rgba_fg_color,
NULL);
g_object_set(cell_renderer,
"foreground-rgba", &new_rgba_fg_color,
"foreground-set", TRUE,
NULL);
#else
GtkStyle *s;
s = gtk_widget_get_style(prog_combo_box);
g_object_set(cell_renderer,
"foreground-gdk", &(s->fg[GTK_STATE_NORMAL]),
"foreground-set", TRUE,
NULL);
#endif
}
current_uuid_key = NULL;
current_uuid_value = NULL;
do {
new_uuid_key = NULL;
new_uuid_value = NULL;
g_hash_table_foreach(dcerpc_uuids, (GHFunc)dcerpcstat_find_next_program, NULL);
if(new_uuid_key){
#if 0
GtkTreeIter tmp_iter;
tmp_iter = dcerpcstat_add_program_to_menu(new_uuid_key, new_uuid_value,
prog_combo_box, program_item_index);
if (program_item_index == 0)
program_first_item_iter = tmp_iter;
#else
dcerpcstat_add_program_to_menu(new_uuid_key, new_uuid_value,
prog_combo_box, program_item_index);
#endif
program_item_index += 1;
}
current_uuid_key = new_uuid_key;
current_uuid_value = new_uuid_value;
} while(new_uuid_key != NULL);
gtk_box_pack_start(GTK_BOX(prog_box), prog_combo_box, TRUE, TRUE, 0);
gtk_widget_show(prog_combo_box);
gtk_container_set_border_width(GTK_CONTAINER(prog_box), 10);
vers_label = gtk_label_new("Version:");
gtk_box_pack_start(GTK_BOX(prog_box), vers_label, FALSE, FALSE, 0);
gtk_widget_show(vers_label);
vers_combo_box = ws_combo_box_new_text_and_pointer();
gtk_box_pack_start(GTK_BOX(prog_box), vers_combo_box, TRUE, TRUE, 0);
gtk_widget_show(vers_combo_box);
g_signal_connect(prog_combo_box, "changed", G_CALLBACK(dcerpcstat_program_select), vers_combo_box);
#if 0
ws_combo_box_set_active_iter(GTK_COMBO_BOX(prog_combo_box), &program_first_item_iter);
#endif
gtk_box_pack_start(GTK_BOX(dlg_box), prog_box, TRUE, TRUE, 0);
gtk_widget_show(prog_box);
filter_box = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
filter_bt = gtk_button_new_from_stock(WIRESHARK_STOCK_DISPLAY_FILTER_ENTRY);
g_signal_connect(filter_bt, "clicked", G_CALLBACK(display_filter_construct_cb), &args);
gtk_box_pack_start(GTK_BOX(filter_box), filter_bt, FALSE, FALSE, 0);
gtk_widget_show(filter_bt);
filter_entry = gtk_entry_new();
g_signal_connect(filter_entry, "changed", G_CALLBACK(filter_te_syntax_check_cb), NULL);
g_object_set_data(G_OBJECT(filter_box), E_FILT_AUTOCOMP_PTR_KEY, NULL);
g_signal_connect(filter_entry, "key-press-event", G_CALLBACK (filter_string_te_key_pressed_cb), NULL);
g_signal_connect(dlg, "key-press-event", G_CALLBACK (filter_parent_dlg_key_pressed_cb), NULL);
gtk_box_pack_start(GTK_BOX(filter_box), filter_entry, TRUE, TRUE, 0);
filter = gtk_entry_get_text(GTK_ENTRY(main_display_filter_widget));
if(filter){
gtk_entry_set_text(GTK_ENTRY(filter_entry), filter);
} else {
colorize_filter_te_as_empty(filter_entry);
}
gtk_widget_show(filter_entry);
gtk_box_pack_start(GTK_BOX(dlg_box), filter_box, TRUE, TRUE, 0);
gtk_widget_show(filter_box);
g_object_set_data(G_OBJECT(filter_bt), E_FILT_TE_PTR_KEY, filter_entry);
bbox = dlg_button_row_new(WIRESHARK_STOCK_CREATE_STAT, GTK_STOCK_CANCEL, NULL);
gtk_box_pack_start(GTK_BOX(dlg_box), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
start_button = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_CREATE_STAT);
g_signal_connect_swapped(start_button, "clicked",
G_CALLBACK(dcerpcstat_start_button_clicked), NULL);
cancel_button = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
window_set_cancel_button(dlg, cancel_button, window_cancel_button_cb);
g_signal_connect(dlg, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(dlg, "destroy", G_CALLBACK(dlg_destroy_cb), NULL);
dlg_set_activate(filter_entry, start_button);
gtk_widget_grab_default(start_button );
gtk_widget_grab_focus(filter_entry);
gtk_widget_show_all(dlg);
window_present(dlg);
}
void
register_tap_listener_gtkdcerpcstat(void)
{
register_stat_cmd_arg("dcerpc,srt,", gtk_dcerpcstat_init,NULL);
}
