static void
h225counter_reset(void *phs)
{
h225counter_t *hs=(h225counter_t *)phs;
int i;
for(i=0;i<=RAS_MSG_TYPES;i++) {
hs->ras_msg[i] = 0;
}
for(i=0;i<=CS_MSG_TYPES;i++) {
hs->cs_msg[i] = 0;
}
for(i=0;i<=GRJ_REASONS;i++) {
hs->grj_reason[i] = 0;
}
for(i=0;i<=RRJ_REASONS;i++) {
hs->rrj_reason[i] = 0;
}
for(i=0;i<=URQ_REASONS;i++) {
hs->urq_reason[i] = 0;
}
for(i=0;i<=URJ_REASONS;i++) {
hs->urj_reason[i] = 0;
}
for(i=0;i<=ARJ_REASONS;i++) {
hs->arj_reason[i] = 0;
}
for(i=0;i<=BRJ_REASONS;i++) {
hs->brj_reason[i] = 0;
}
for(i=0;i<=DRQ_REASONS;i++) {
hs->drq_reason[i] = 0;
}
for(i=0;i<=DRJ_REASONS;i++) {
hs->drj_reason[i] = 0;
}
for(i=0;i<=LRJ_REASONS;i++) {
hs->lrj_reason[i] = 0;
}
for(i=0;i<=IRQNAK_REASONS;i++) {
hs->irqnak_reason[i] = 0;
}
for(i=0;i<=REL_CMP_REASONS;i++) {
hs->rel_cmp_reason[i] = 0;
}
for(i=0;i<=FACILITY_REASONS;i++) {
hs->facility_reason[i] = 0;
}
}
static int
h225counter_packet(void *phs, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *phi)
{
h225counter_t *hs=(h225counter_t *)phs;
const h225_packet_info *pi=(h225_packet_info *)phi;
switch (pi->msg_type) {
case H225_RAS:
if(pi->msg_tag==-1) {
return 0;
}
else if (pi->msg_tag >= RAS_MSG_TYPES) {
hs->ras_msg[RAS_MSG_TYPES]++;
}
else {
hs->ras_msg[pi->msg_tag]++;
}
if(pi->reason==-1) {
break;
}
switch(pi->msg_tag) {
case 2:
if(pi->reason < GRJ_REASONS)
hs->grj_reason[pi->reason]++;
else
hs->grj_reason[GRJ_REASONS]++;
break;
case 5:
if(pi->reason < RRJ_REASONS)
hs->rrj_reason[pi->reason]++;
else
hs->rrj_reason[RRJ_REASONS]++;
break;
case 6:
if(pi->reason < URQ_REASONS)
hs->urq_reason[pi->reason]++;
else
hs->urq_reason[URQ_REASONS]++;
break;
case 8:
if(pi->reason < URJ_REASONS)
hs->urj_reason[pi->reason]++;
else
hs->urj_reason[URJ_REASONS]++;
break;
case 11:
if(pi->reason < ARJ_REASONS)
hs->arj_reason[pi->reason]++;
else
hs->arj_reason[ARJ_REASONS]++;
break;
case 14:
if(pi->reason < BRJ_REASONS)
hs->brj_reason[pi->reason]++;
else
hs->brj_reason[BRJ_REASONS]++;
break;
case 15:
if(pi->reason < DRQ_REASONS)
hs->drq_reason[pi->reason]++;
else
hs->drq_reason[DRQ_REASONS]++;
break;
case 17:
if(pi->reason < DRJ_REASONS)
hs->drj_reason[pi->reason]++;
else
hs->drj_reason[DRJ_REASONS]++;
break;
case 20:
if(pi->reason < LRJ_REASONS)
hs->lrj_reason[pi->reason]++;
else
hs->lrj_reason[LRJ_REASONS]++;
break;
case 29:
if(pi->reason < IRQNAK_REASONS)
hs->irqnak_reason[pi->reason]++;
else
hs->irqnak_reason[IRQNAK_REASONS]++;
break;
default:
break;
}
break;
case H225_CS:
if(pi->msg_tag==-1) {
return 0;
}
else if (pi->msg_tag >= CS_MSG_TYPES) {
hs->cs_msg[CS_MSG_TYPES]++;
}
else {
hs->cs_msg[pi->msg_tag]++;
}
if(pi->reason==-1) {
break;
}
switch(pi->msg_tag) {
case 5:
if(pi->reason < REL_CMP_REASONS)
hs->rel_cmp_reason[pi->reason]++;
else
hs->rel_cmp_reason[REL_CMP_REASONS]++;
break;
case 6:
if(pi->reason < FACILITY_REASONS)
hs->facility_reason[pi->reason]++;
else
hs->facility_reason[FACILITY_REASONS]++;
break;
default:
break;
}
break;
default:
return 0;
}
return 1;
}
static void
h225counter_draw(void *phs)
{
h225counter_t *hs=(h225counter_t *)phs;
int i,j;
char str[256];
GtkListStore *store;
GtkTreeIter iter;
store = GTK_LIST_STORE(gtk_tree_view_get_model(hs->table));
gtk_list_store_clear(store);
for(i=0;i<=RAS_MSG_TYPES;i++) {
if(hs->ras_msg[i]!=0) {
g_snprintf(str, 256, "%s", val_to_str(i,h225_RasMessage_vals,"unknown ras-messages"));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, val_to_str(i,h225_RasMessage_vals,"unknown ras-messages"),
1, hs->ras_msg[i], -1);
switch(i) {
case 2:
for(j=0;j<=GRJ_REASONS;j++) {
if(hs->grj_reason[j]!=0) {
g_snprintf(str, 256," %s",
val_to_str(j,GatekeeperRejectReason_vals,"unknown reason"));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, str,
1, hs->grj_reason[j], -1);
}
}
break;
case 5:
for(j=0;j<=RRJ_REASONS;j++) {
if(hs->rrj_reason[j]!=0) {
g_snprintf(str, 256," %s",
val_to_str(j,RegistrationRejectReason_vals,"unknown reason"));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, str,
1, hs->rrj_reason[j], -1);
}
}
break;
case 6:
for(j=0;j<=URQ_REASONS;j++) {
if(hs->urq_reason[j]!=0) {
g_snprintf(str, 256," %s",
val_to_str(j,UnregRequestReason_vals,"unknown reason"));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, str,
1, hs->urq_reason[j], -1);
}
}
break;
case 8:
for(j=0;j<=URJ_REASONS;j++) {
if(hs->urj_reason[j]!=0) {
g_snprintf(str, 256," %s",
val_to_str(j,UnregRejectReason_vals,"unknown reason"));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, str,
1, hs->urj_reason[j], -1);
}
}
break;
case 11:
for(j=0;j<=ARJ_REASONS;j++) {
if(hs->arj_reason[j]!=0) {
g_snprintf(str, 256," %s",
val_to_str(j,AdmissionRejectReason_vals,"unknown reason"));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, str,
1, hs->arj_reason[j], -1);
}
}
break;
case 14:
for(j=0;j<=BRJ_REASONS;j++) {
if(hs->brj_reason[j]!=0) {
g_snprintf(str, 256," %s",
val_to_str(j,BandRejectReason_vals,"unknown reason"));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, str,
1, hs->brj_reason[j], -1);
}
}
break;
case 15:
for(j=0;j<=DRQ_REASONS;j++) {
if(hs->drq_reason[j]!=0) {
g_snprintf(str, 256," %s",
val_to_str(j,DisengageReason_vals,"unknown reason"));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, str,
1, hs->drq_reason[j], -1);
}
}
break;
case 17:
for(j=0;j<=DRJ_REASONS;j++) {
if(hs->drj_reason[j]!=0) {
g_snprintf(str, 256," %s",
val_to_str(j,DisengageRejectReason_vals,"unknown reason"));
gtk_list_store_set(store, &iter,
0, str,
1, hs->drj_reason[j], -1);
}
}
break;
case 20:
for(j=0;j<=LRJ_REASONS;j++) {
if(hs->lrj_reason[j]!=0) {
g_snprintf(str, 256," %s",
val_to_str(j,LocationRejectReason_vals,"unknown reason"));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, str,
1, hs->lrj_reason[j], -1);
}
}
break;
case 29:
for(j=0;j<=IRQNAK_REASONS;j++) {
if(hs->irqnak_reason[j]!=0) {
g_snprintf(str, 256," %s",
val_to_str(j,InfoRequestNakReason_vals,"unknown reason"));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, str,
1, hs->irqnak_reason[j], -1);
}
}
break;
default:
break;
}
}
}
for(i=0;i<=CS_MSG_TYPES;i++) {
if(hs->cs_msg[i]!=0) {
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, val_to_str(i,T_h323_message_body_vals,"unknown cs-messages"),
1, hs->cs_msg[i], -1);
switch(i) {
case 5:
for(j=0;j<=REL_CMP_REASONS;j++) {
if(hs->rel_cmp_reason[j]!=0) {
g_snprintf(str, 256," %s",
val_to_str(j,h225_ReleaseCompleteReason_vals,"unknown reason"));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, str,
1, hs->rel_cmp_reason[j], -1);
}
}
break;
case 6:
for(j=0;j<=FACILITY_REASONS;j++) {
if(hs->facility_reason[j]!=0) {
g_snprintf(str, 256," %s",
val_to_str(j,FacilityReason_vals,"unknown reason"));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, str,
1, hs->facility_reason[j], -1);
}
}
break;
default:
break;
}
}
}
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
h225counter_t *hs=(h225counter_t *)data;
remove_tap_listener(hs);
if(hs->filter){
g_free(hs->filter);
hs->filter=NULL;
}
g_free(hs);
}
static void
gtk_h225counter_init(const char *opt_arg, void *userdata _U_)
{
h225counter_t *hs;
GString *error_string;
GtkWidget *bbox;
GtkWidget *close_bt;
hs=(h225counter_t *)g_malloc(sizeof(h225counter_t));
if(strncmp(opt_arg,"h225,counter,",13) == 0){
hs->filter=g_strdup(opt_arg+13);
} else {
hs->filter=NULL;
}
h225counter_reset(hs);
hs->win = dlg_window_new("Wireshark: H.225 counters");
gtk_window_set_destroy_with_parent (GTK_WINDOW(hs->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(hs->win), 400, 200);
hs->vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(hs->vbox), 12);
init_main_stat_window(hs->win, hs->vbox, "H.225 Message and Message Reason Counter", hs->filter);
hs->scrolled_window = scrolled_window_new(NULL, NULL);
hs->table = create_stat_table(hs->scrolled_window, hs->vbox, 2, titles);
error_string=register_tap_listener("h225", hs, hs->filter, 0, h225counter_reset, h225counter_packet, h225counter_draw);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
g_free(hs->filter);
g_free(hs);
return;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_end(GTK_BOX(hs->vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(hs->win, close_bt, window_cancel_button_cb);
g_signal_connect(hs->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(hs->win, "destroy", G_CALLBACK(win_destroy_cb), hs);
gtk_widget_show_all(hs->win);
window_present(hs->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(hs->win));
}
void
register_tap_listener_gtk_h225counter(void)
{
register_param_stat(&h225_counter_dlg, "_H.225",
REGISTER_STAT_GROUP_TELEPHONY);
}
