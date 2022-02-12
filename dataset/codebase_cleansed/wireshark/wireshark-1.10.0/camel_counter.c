static void gtk_camelcounter_reset(void *phs)
{
struct camelcounter_t * p_counter= ( struct camelcounter_t *) phs;
int i;
for(i=0;i<camel_MAX_NUM_OPR_CODES;i++) {
p_counter->camel_msg[i]=0;
}
}
static int gtk_camelcounter_packet(void *phs,
packet_info *pinfo _U_,
epan_dissect_t *edt _U_,
const void *phi)
{
struct camelcounter_t * p_counter =(struct camelcounter_t *)phs;
const struct camelsrt_info_t * pi=(struct camelsrt_info_t *)phi;
if (pi->opcode != 255)
p_counter->camel_msg[pi->opcode]++;
return 1;
}
static void gtk_camelcounter_draw(void *phs)
{
struct camelcounter_t *p_counter=(struct camelcounter_t *)phs;
int i;
char str[256];
GtkListStore *store;
GtkTreeIter iter;
store = GTK_LIST_STORE(gtk_tree_view_get_model(p_counter->table));
gtk_list_store_clear(store);
for(i=0;i<camel_MAX_NUM_OPR_CODES;i++) {
if(p_counter->camel_msg[i]!=0) {
g_snprintf(str, 256, "Request %s", val_to_str(i,camel_opr_code_strings,"Unknown message "));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, str,
1, p_counter->camel_msg[i],
-1);
}
}
}
static void win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
struct camelcounter_t *hs=(struct camelcounter_t *)data;
remove_tap_listener(hs);
if(hs->filter){
g_free(hs->filter);
hs->filter=NULL;
}
g_free(hs);
}
static void gtk_camelcounter_init(const char *opt_arg, void *userdata _U_)
{
struct camelcounter_t *p_camelcounter;
const char *filter=NULL;
GString *error_string;
GtkWidget *bbox;
GtkWidget *close_bt;
if(strncmp(opt_arg,"camel,counter,",14) == 0){
filter=opt_arg+14;
} else {
filter=NULL;
}
p_camelcounter=(struct camelcounter_t *)g_malloc(sizeof(struct camelcounter_t));
p_camelcounter->filter=g_strdup(filter);
gtk_camelcounter_reset(p_camelcounter);
p_camelcounter->win=dlg_window_new("Wireshark: CAMEL counters");
gtk_window_set_destroy_with_parent (GTK_WINDOW(p_camelcounter->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(p_camelcounter->win), 500, 300);
p_camelcounter->vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(p_camelcounter->vbox), 12);
init_main_stat_window(p_camelcounter->win, p_camelcounter->vbox, "CAMEL Messages Counters", filter);
p_camelcounter->scrolled_window = scrolled_window_new(NULL, NULL);
p_camelcounter->table = create_stat_table(p_camelcounter->scrolled_window, p_camelcounter->vbox, 2, titles);
error_string=register_tap_listener("CAMEL", p_camelcounter, filter, 0,
gtk_camelcounter_reset,
gtk_camelcounter_packet,
gtk_camelcounter_draw);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
g_free(p_camelcounter);
return;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_end(GTK_BOX(p_camelcounter->vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(p_camelcounter->win, close_bt, window_cancel_button_cb);
g_signal_connect(p_camelcounter->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(p_camelcounter->win, "destroy", G_CALLBACK(win_destroy_cb), p_camelcounter);
gtk_widget_show_all(p_camelcounter->win);
window_present(p_camelcounter->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(p_camelcounter->win));
}
void
register_tap_listener_gtk_camelcounter(void)
{
register_dfilter_stat(&camel_counter_dlg, "_GSM/CAMEL",
REGISTER_STAT_GROUP_TELEPHONY);
}
void camel_counter_cb(GtkAction *action, gpointer user_data _U_)
{
tap_param_dlg_cb(action, &camel_counter_dlg);
}
