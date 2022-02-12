static void
ncpstat_set_title(ncpstat_t *ss)
{
set_window_title(ss->win, "NCP Service Response Time statistics");
}
static void
ncpstat_reset(void *pss)
{
ncpstat_t *ss=(ncpstat_t *)pss;
reset_srt_table_data(&ss->ncp_srt_table);
reset_srt_table_data(&ss->func_srt_table);
reset_srt_table_data(&ss->nds_srt_table);
reset_srt_table_data(&ss->sss_srt_table);
reset_srt_table_data(&ss->nmas_srt_table);
reset_srt_table_data(&ss->sub_17_srt_table);
reset_srt_table_data(&ss->sub_21_srt_table);
reset_srt_table_data(&ss->sub_22_srt_table);
reset_srt_table_data(&ss->sub_23_srt_table);
reset_srt_table_data(&ss->sub_32_srt_table);
reset_srt_table_data(&ss->sub_34_srt_table);
reset_srt_table_data(&ss->sub_35_srt_table);
reset_srt_table_data(&ss->sub_36_srt_table);
reset_srt_table_data(&ss->sub_86_srt_table);
reset_srt_table_data(&ss->sub_87_srt_table);
reset_srt_table_data(&ss->sub_89_srt_table);
reset_srt_table_data(&ss->sub_90_srt_table);
reset_srt_table_data(&ss->sub_92_srt_table);
reset_srt_table_data(&ss->sub_94_srt_table);
reset_srt_table_data(&ss->sub_104_srt_table);
reset_srt_table_data(&ss->sub_111_srt_table);
reset_srt_table_data(&ss->sub_114_srt_table);
reset_srt_table_data(&ss->sub_123_srt_table);
reset_srt_table_data(&ss->sub_131_srt_table);
ncpstat_set_title(ss);
}
static int
ncpstat_packet(void *pss, packet_info *pinfo, epan_dissect_t *edt _U_, const void *prv)
{
ncpstat_t *ss=(ncpstat_t *)pss;
const ncp_req_hash_value *request_val=(ncp_req_hash_value *)prv;
if(!request_val || request_val->ncp_rec==0){
return 0;
}
init_srt_table_row(&ss->ncp_srt_table, request_val->ncp_rec->group, val_to_str(request_val->ncp_rec->group, ncp_group_vals, "Unknown(%u)"));
add_srt_table_data(&ss->ncp_srt_table, request_val->ncp_rec->group, &request_val->req_frame_time, pinfo);
if (request_val->ncp_rec->subfunc==0) {
init_srt_table_row(&ss->func_srt_table, request_val->ncp_rec->func, request_val->ncp_rec->name);
add_srt_table_data(&ss->func_srt_table, request_val->ncp_rec->func, &request_val->req_frame_time, pinfo);
}
if(request_val->ncp_rec->subfunc!=0){
if (request_val->ncp_rec->func==17) {
init_srt_table_row(&ss->sub_17_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_17_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==21) {
init_srt_table_row(&ss->sub_21_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_21_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==22) {
init_srt_table_row(&ss->sub_22_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_22_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==23) {
init_srt_table_row(&ss->sub_23_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_23_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==32) {
init_srt_table_row(&ss->sub_32_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_32_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==34) {
init_srt_table_row(&ss->sub_34_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_34_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==35) {
init_srt_table_row(&ss->sub_35_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_35_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==36) {
init_srt_table_row(&ss->sub_36_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_36_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==86) {
init_srt_table_row(&ss->sub_86_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_86_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==87) {
init_srt_table_row(&ss->sub_87_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_87_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==89) {
init_srt_table_row(&ss->sub_89_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_89_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==90) {
init_srt_table_row(&ss->sub_90_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_90_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==92) {
init_srt_table_row(&ss->sub_92_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_92_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==94) {
init_srt_table_row(&ss->sub_94_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_94_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==104) {
init_srt_table_row(&ss->sub_104_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_104_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==111) {
init_srt_table_row(&ss->sub_111_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_111_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==114) {
init_srt_table_row(&ss->sub_114_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_114_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==123) {
init_srt_table_row(&ss->sub_123_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_123_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==131) {
init_srt_table_row(&ss->sub_131_srt_table, (request_val->ncp_rec->subfunc), request_val->ncp_rec->name);
add_srt_table_data(&ss->sub_131_srt_table, (request_val->ncp_rec->subfunc), &request_val->req_frame_time, pinfo);
}
}
if (request_val->ncp_rec->func==0x68) {
init_srt_table_row(&ss->nds_srt_table, (request_val->nds_request_verb), val_to_str(request_val->nds_request_verb, ncp_nds_verb_vals, "Unknown(%u)"));
add_srt_table_data(&ss->nds_srt_table, (request_val->nds_request_verb), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==0x5c) {
init_srt_table_row(&ss->sss_srt_table, (request_val->req_nds_flags), val_to_str(request_val->req_nds_flags, sss_verb_enum, "Unknown(%u)"));
add_srt_table_data(&ss->sss_srt_table, (request_val->req_nds_flags), &request_val->req_frame_time, pinfo);
}
if (request_val->ncp_rec->func==0x5e) {
init_srt_table_row(&ss->nmas_srt_table, (request_val->req_nds_flags), val_to_str(request_val->req_nds_flags, nmas_subverb_enum, "Unknown(%u)"));
add_srt_table_data(&ss->nmas_srt_table, (request_val->req_nds_flags), &request_val->req_frame_time, pinfo);
}
return 1;
}
static void
ncpstat_draw(void *pss)
{
ncpstat_t *ss=(ncpstat_t *)pss;
draw_srt_table_data(&ss->ncp_srt_table);
draw_srt_table_data(&ss->func_srt_table);
draw_srt_table_data(&ss->nds_srt_table);
draw_srt_table_data(&ss->sss_srt_table);
draw_srt_table_data(&ss->nmas_srt_table);
draw_srt_table_data(&ss->sub_17_srt_table);
draw_srt_table_data(&ss->sub_21_srt_table);
draw_srt_table_data(&ss->sub_22_srt_table);
draw_srt_table_data(&ss->sub_23_srt_table);
draw_srt_table_data(&ss->sub_32_srt_table);
draw_srt_table_data(&ss->sub_34_srt_table);
draw_srt_table_data(&ss->sub_35_srt_table);
draw_srt_table_data(&ss->sub_36_srt_table);
draw_srt_table_data(&ss->sub_86_srt_table);
draw_srt_table_data(&ss->sub_87_srt_table);
draw_srt_table_data(&ss->sub_89_srt_table);
draw_srt_table_data(&ss->sub_90_srt_table);
draw_srt_table_data(&ss->sub_92_srt_table);
draw_srt_table_data(&ss->sub_94_srt_table);
draw_srt_table_data(&ss->sub_104_srt_table);
draw_srt_table_data(&ss->sub_111_srt_table);
draw_srt_table_data(&ss->sub_114_srt_table);
draw_srt_table_data(&ss->sub_123_srt_table);
draw_srt_table_data(&ss->sub_131_srt_table);
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
ncpstat_t *ss=(ncpstat_t *)data;
remove_tap_listener(ss);
free_srt_table_data(&ss->ncp_srt_table);
free_srt_table_data(&ss->func_srt_table);
free_srt_table_data(&ss->nds_srt_table);
free_srt_table_data(&ss->sss_srt_table);
free_srt_table_data(&ss->nmas_srt_table);
free_srt_table_data(&ss->sub_17_srt_table);
free_srt_table_data(&ss->sub_21_srt_table);
free_srt_table_data(&ss->sub_22_srt_table);
free_srt_table_data(&ss->sub_23_srt_table);
free_srt_table_data(&ss->sub_32_srt_table);
free_srt_table_data(&ss->sub_34_srt_table);
free_srt_table_data(&ss->sub_35_srt_table);
free_srt_table_data(&ss->sub_36_srt_table);
free_srt_table_data(&ss->sub_86_srt_table);
free_srt_table_data(&ss->sub_87_srt_table);
free_srt_table_data(&ss->sub_89_srt_table);
free_srt_table_data(&ss->sub_90_srt_table);
free_srt_table_data(&ss->sub_92_srt_table);
free_srt_table_data(&ss->sub_94_srt_table);
free_srt_table_data(&ss->sub_104_srt_table);
free_srt_table_data(&ss->sub_111_srt_table);
free_srt_table_data(&ss->sub_114_srt_table);
free_srt_table_data(&ss->sub_123_srt_table);
free_srt_table_data(&ss->sub_131_srt_table);
g_free(ss);
}
static void
gtk_ncpstat_init(const char *opt_arg, void *userdata _U_)
{
ncpstat_t *ss;
const char *filter=NULL;
GtkWidget *label;
char *filter_string;
GString *error_string;
GtkWidget *temp_page;
GtkWidget *main_nb;
GtkWidget *vbox;
GtkWidget *bbox;
GtkWidget *close_bt;
if(!strncmp(opt_arg,"ncp,srt,",8)){
filter=opt_arg+8;
} else {
filter=NULL;
}
ss=(ncpstat_t *)g_malloc(sizeof(ncpstat_t));
ss->win = dlg_window_new("ncp-stat");
gtk_window_set_destroy_with_parent (GTK_WINDOW(ss->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(ss->win), 300, 400);
ncpstat_set_title(ss);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(ss->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
label=gtk_label_new("NCP Service Response Time Statistics");
gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
filter_string = g_strdup_printf("Filter: %s",filter ? filter : "");
label=gtk_label_new(filter_string);
g_free(filter_string);
gtk_label_set_line_wrap(GTK_LABEL(label), TRUE);
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
main_nb = gtk_notebook_new();
gtk_box_pack_start(GTK_BOX(vbox), main_nb, TRUE, TRUE, 0);
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label = gtk_label_new("Groups");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
gtk_widget_show_all(ss->win);
label=gtk_label_new("NCP by Group Type");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->ncp_srt_table, 256, temp_page, "ncp.group");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label = gtk_label_new("Functions");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("NCP Functions without Subfunctions");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->func_srt_table, 256, temp_page, "ncp.func");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label = gtk_label_new("17");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 17");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_17_srt_table, 256, temp_page, "ncp.func==17 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("21");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 21");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_21_srt_table, 256, temp_page, "ncp.func==21 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("22");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 22");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_22_srt_table, 256, temp_page, "ncp.func==22 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("23");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 23");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_23_srt_table, 256, temp_page, "ncp.func==23 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("32");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 32");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_32_srt_table, 256, temp_page, "ncp.func==32 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("34");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 34");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_34_srt_table, 256, temp_page, "ncp.func==34 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("35");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 35");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_35_srt_table, 256, temp_page, "ncp.func==35 && ncp.subfunc");
temp_page =ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("36");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 36");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_36_srt_table, 256, temp_page, "ncp.func==36 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("86");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 86");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_86_srt_table, 256, temp_page, "ncp.func==86 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("87");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 87");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_87_srt_table, 256, temp_page, "ncp.func==87 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("89");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 89 (Extended NCP's with UTF8 Support)");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_89_srt_table, 256, temp_page, "ncp.func==89 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("90");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 90");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_90_srt_table, 256, temp_page, "ncp.func==90 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("92");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 92 (Secret Store Services)");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_92_srt_table, 256, temp_page, "ncp.func==92 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("94");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 94 (Novell Modular Authentication Services)");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_94_srt_table, 256, temp_page, "ncp.func==94 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("104");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 104");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_104_srt_table, 256, temp_page, "ncp.func==104 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("111");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 111");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_111_srt_table, 256, temp_page, "ncp.func==111 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("114");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 114");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_114_srt_table, 256, temp_page, "ncp.func==114 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("123");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 123");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_123_srt_table, 256, temp_page, "ncp.func==123 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("131");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Subfunctions for NCP 131");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sub_131_srt_table, 256, temp_page, "ncp.func==131 && ncp.subfunc");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("NDS");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("NDS Verbs");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->nds_srt_table, 256, temp_page, "ncp.ndsverb");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("SSS");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("Secret Store Verbs");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->sss_srt_table, 256, temp_page, "sss.subverb");
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
label=gtk_label_new("NMAS");
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, label);
label=gtk_label_new("NMAS Verbs");
gtk_box_pack_start(GTK_BOX(temp_page), label, FALSE, FALSE, 0);
init_srt_table(&ss->nmas_srt_table, 256, temp_page, "nmas.subverb");
error_string=register_tap_listener("ncp_srt", ss, filter, 0, ncpstat_reset, ncpstat_packet, ncpstat_draw);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
g_free(ss);
return;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_end(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(ss->win, close_bt, window_cancel_button_cb);
g_signal_connect(ss->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(ss->win, "destroy", G_CALLBACK(win_destroy_cb), ss);
gtk_widget_show_all(ss->win);
window_present(ss->win);
cf_redissect_packets(&cfile);
}
void
register_tap_listener_gtkncpstat(void)
{
register_dfilter_stat(&ncp_stat_dlg, "NCP",
REGISTER_STAT_GROUP_RESPONSE_TIME);
}
void ncp_srt_cb(GtkAction *action, gpointer user_data _U_)
{
tap_param_dlg_cb(action, &ncp_stat_dlg);
}
