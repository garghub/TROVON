static char *
ct_port_to_str(int port_type_val, guint32 port)
{
static int i=0;
static gchar *strp, str[4][12];
gchar *bp;
strp=str[i];
switch(port_type_val){
case PT_TCP:
case PT_UDP:
case PT_SCTP:
case PT_NCP:
i = (i+1)%4;
bp = &strp[11];
*bp = 0;
do {
*--bp = (port % 10) +'0';
} while ((port /= 10) != 0 && bp > strp);
return bp;
}
return NULL;
}
static const char *
ct_get_filter_name(address *addr, int specific_addr_type_val, int port_type_val, int name_type_val)
{
switch(name_type_val){
case FN_SRC_ADDRESS:
switch(addr->type){
case AT_ETHER:
switch(specific_addr_type_val){
case SAT_ETHER:
return "eth.src";
case SAT_WLAN:
return "wlan.sa";
case SAT_FDDI:
return "fddi.src";
case SAT_TOKENRING:
return "tr.src";
default:
break;
}
break;
case AT_IPv4:
return "ip.src";
case AT_IPv6:
return "ipv6.src";
case AT_IPX:
return "ipx.src";
case AT_FC:
return "fc.s_id";
case AT_URI:
switch(specific_addr_type_val){
case SAT_JXTA:
return "jxta.message.src";
default:
break;
}
break;
case AT_USB:
return "usb.sa";
default:
break;
}
break;
case FN_DST_ADDRESS:
switch(addr->type){
case AT_ETHER:
switch(specific_addr_type_val){
case SAT_ETHER:
return "eth.dst";
case SAT_WLAN:
return "wlan.da";
case SAT_FDDI:
return "fddi.dst";
case SAT_TOKENRING:
return "tr.dst";
default:
break;
}
break;
case AT_IPv4:
return "ip.dst";
case AT_IPv6:
return "ipv6.dst";
case AT_IPX:
return "ipx.dst";
case AT_FC:
return "fc.d_id";
case AT_URI:
switch(specific_addr_type_val){
case SAT_JXTA:
return "jxta.message.dst";
default:
break;
}
break;
case AT_USB:
return "usb.da";
default:
break;
}
break;
case FN_ANY_ADDRESS:
switch(addr->type){
case AT_ETHER:
switch(specific_addr_type_val){
case SAT_ETHER:
return "eth.addr";
case SAT_WLAN:
return "wlan.addr";
case SAT_FDDI:
return "fddi.addr";
case SAT_TOKENRING:
return "tr.addr";
default:
break;
}
break;
case AT_IPv4:
return "ip.addr";
case AT_IPv6:
return "ipv6.addr";
case AT_IPX:
return "ipx.addr";
case AT_FC:
return "fc.id";
case AT_URI:
switch(specific_addr_type_val){
case SAT_JXTA:
return "jxta.message.address";
default:
break;
}
break;
case AT_USB:
return "usb.addr";
default:
break;
}
break;
case FN_SRC_PORT:
switch(port_type_val){
case PT_TCP:
return "tcp.srcport";
case PT_UDP:
return "udp.srcport";
case PT_SCTP:
return "sctp.srcport";
case PT_NCP:
return "ncp.connection";
default:
break;
}
break;
case FN_DST_PORT:
switch(port_type_val){
case PT_TCP:
return "tcp.dstport";
case PT_UDP:
return "udp.dstport";
case PT_SCTP:
return "sctp.dstport";
case PT_NCP:
return "ncp.connection";
default:
break;
}
break;
case FN_ANY_PORT:
switch(port_type_val){
case PT_TCP:
return "tcp.port";
case PT_UDP:
return "udp.port";
case PT_SCTP:
return "sctp.port";
case PT_NCP:
return "ncp.connection";
default:
break;
}
break;
}
g_assert_not_reached();
return NULL;
}
static void
reset_ct_table_data(conversations_table *ct)
{
guint32 i;
char *display_name;
char title[256];
GString *error_string;
const char *filter;
GtkListStore *store;
if (ct->use_dfilter) {
filter = gtk_entry_get_text(GTK_ENTRY(main_display_filter_widget));
} else {
filter = ct->filter;
}
error_string = set_tap_dfilter (ct, filter);
if (error_string) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
return;
}
if(ct->page_lb) {
display_name = cf_get_display_name(&cfile);
g_snprintf(title, sizeof(title), "Conversations: %s", display_name);
g_free(display_name);
gtk_window_set_title(GTK_WINDOW(ct->win), title);
g_snprintf(title, sizeof(title), "%s", ct->name);
gtk_label_set_text(GTK_LABEL(ct->page_lb), title);
gtk_widget_set_sensitive(ct->page_lb, FALSE);
if (ct->use_dfilter) {
if (filter && strlen(filter)) {
g_snprintf(title, sizeof(title), "%s Conversations - Filter: %s", ct->name, filter);
} else {
g_snprintf(title, sizeof(title), "%s Conversations - No Filter", ct->name);
}
} else {
g_snprintf(title, sizeof(title), "%s Conversations", ct->name);
}
gtk_label_set_text(GTK_LABEL(ct->name_lb), title);
} else {
display_name = cf_get_display_name(&cfile);
g_snprintf(title, sizeof(title), "%s Conversations: %s", ct->name, display_name);
g_free(display_name);
gtk_window_set_title(GTK_WINDOW(ct->win), title);
}
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(ct->table)));
gtk_list_store_clear(store);
for(i=0;i<ct->num_conversations;i++){
conv_t *conv = &g_array_index(ct->conversations, conv_t, i);
g_free((gpointer)conv->src_address.data);
g_free((gpointer)conv->dst_address.data);
}
if (ct->conversations)
g_array_free(ct->conversations, TRUE);
if (ct->hashtable != NULL)
g_hash_table_destroy(ct->hashtable);
ct->conversations=NULL;
ct->hashtable=NULL;
ct->num_conversations=0;
}
static void
reset_ct_table_data_cb(void *arg)
{
reset_ct_table_data(arg);
}
static void
ct_win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
conversations_table *conversations=(conversations_table *)data;
protect_thread_critical_region();
remove_tap_listener(conversations);
unprotect_thread_critical_region();
reset_ct_table_data(conversations);
g_free(conversations);
}
static gint
ct_sort_func(GtkTreeModel *model,
GtkTreeIter *a,
GtkTreeIter *b,
gpointer user_data)
{
guint32 idx1, idx2;
gint data_column = GPOINTER_TO_INT(user_data);
conversations_table *ct = g_object_get_data(G_OBJECT(model), CONV_PTR_KEY);
conv_t *conv1 = NULL;
conv_t *conv2 = NULL;
double duration1, duration2;
gtk_tree_model_get(model, a, INDEX_COLUMN, &idx1, -1);
gtk_tree_model_get(model, b, INDEX_COLUMN, &idx2, -1);
if (!ct || idx1 >= ct->num_conversations || idx2 >= ct->num_conversations)
return 0;
conv1 = &g_array_index(ct->conversations, conv_t, idx1);
conv2 = &g_array_index(ct->conversations, conv_t, idx2);
switch(data_column){
case SRC_ADR_COLUMN:
return(CMP_ADDRESS(&conv1->src_address, &conv2->src_address));
case DST_ADR_COLUMN:
return(CMP_ADDRESS(&conv1->dst_address, &conv2->dst_address));
case SRC_PORT_COLUMN:
CMP_NUM(conv1->src_port, conv2->src_port);
case DST_PORT_COLUMN:
CMP_NUM(conv1->dst_port, conv2->dst_port);
case START_COLUMN:
return nstime_cmp(&conv1->start_time, &conv2->start_time);
}
duration1 = nstime_to_sec(&conv1->stop_time) - nstime_to_sec(&conv1->start_time);
duration2 = nstime_to_sec(&conv2->stop_time) - nstime_to_sec(&conv2->start_time);
switch(data_column){
case DURATION_COLUMN:
CMP_NUM(duration1, duration2);
case BPS_AB_COLUMN:
if (duration1 > 0 && conv1->tx_frames > 1 && duration2 > 0 && conv2->tx_frames > 1) {
CMP_NUM((gint64) conv1->tx_bytes / duration1, (gint64) conv2->tx_bytes / duration2);
} else {
CMP_NUM(conv1->tx_bytes, conv2->tx_bytes);
}
case BPS_BA_COLUMN:
if (duration1 > 0 && conv1->rx_frames > 1 && duration2 > 0 && conv2->rx_frames > 1) {
CMP_NUM((gint64) conv1->rx_bytes / duration1, (gint64) conv2->rx_bytes / duration2);
} else {
CMP_NUM(conv1->rx_bytes, conv2->rx_bytes);
}
default:
g_assert_not_reached();
}
return 0;
}
static void
ct_select_filter_cb(GtkWidget *widget _U_, gpointer callback_data, guint callback_action)
{
int direction;
guint32 idx = 0;
conversations_table *ct = (conversations_table *)callback_data;
GtkTreeIter iter;
GtkTreeModel *model;
GtkTreeSelection *sel;
char *str = NULL;
char *sport, *dport;
conv_t *conv;
direction=FILTER_EXTRA(callback_action);
sel = gtk_tree_view_get_selection (GTK_TREE_VIEW(ct->table));
if (!gtk_tree_selection_get_selected(sel, &model, &iter))
return;
gtk_tree_model_get (model, &iter,
INDEX_COLUMN, &idx,
-1);
if(idx>= ct->num_conversations){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "No conversation selected");
return;
}
conv = &g_array_index(ct->conversations, conv_t, idx);
sport=ct_port_to_str(conv->port_type, conv->src_port);
dport=ct_port_to_str(conv->port_type, conv->dst_port);
switch(direction){
case DIR_A_TO_FROM_B:
str = g_strdup_printf("%s==%s%s%s%s%s && %s==%s%s%s%s%s",
ct_get_filter_name(&conv->src_address, conv->sat, conv->port_type, FN_ANY_ADDRESS),
ep_address_to_str(&conv->src_address),
sport?" && ":"",
sport?ct_get_filter_name(&conv->src_address, conv->sat, conv->port_type, FN_ANY_PORT):"",
sport?"==":"",
sport?sport:"",
ct_get_filter_name(&conv->dst_address, conv->sat, conv->port_type, FN_ANY_ADDRESS),
ep_address_to_str(&conv->dst_address),
dport?" && ":"",
dport?ct_get_filter_name(&conv->dst_address, conv->sat, conv->port_type, FN_ANY_PORT):"",
dport?"==":"",
dport?dport:""
);
break;
case DIR_A_TO_B:
str = g_strdup_printf("%s==%s%s%s%s%s && %s==%s%s%s%s%s",
ct_get_filter_name(&conv->src_address, conv->sat, conv->port_type, FN_SRC_ADDRESS),
ep_address_to_str(&conv->src_address),
sport?" && ":"",
sport?ct_get_filter_name(&conv->src_address, conv->sat, conv->port_type, FN_SRC_PORT):"",
sport?"==":"",
sport?sport:"",
ct_get_filter_name(&conv->dst_address, conv->sat, conv->port_type, FN_DST_ADDRESS),
ep_address_to_str(&conv->dst_address),
dport?" && ":"",
dport?ct_get_filter_name(&conv->dst_address, conv->sat, conv->port_type, FN_DST_PORT):"",
dport?"==":"",
dport?dport:""
);
break;
case DIR_A_FROM_B:
str = g_strdup_printf("%s==%s%s%s%s%s && %s==%s%s%s%s%s",
ct_get_filter_name(&conv->src_address, conv->sat, conv->port_type, FN_DST_ADDRESS),
ep_address_to_str(&conv->src_address),
sport?" && ":"",
sport?ct_get_filter_name(&conv->src_address, conv->sat, conv->port_type, FN_DST_PORT):"",
sport?"==":"",
sport?sport:"",
ct_get_filter_name(&conv->dst_address, conv->sat, conv->port_type, FN_SRC_ADDRESS),
ep_address_to_str(&conv->dst_address),
dport?" && ":"",
dport?ct_get_filter_name(&conv->dst_address, conv->sat, conv->port_type, FN_SRC_PORT):"",
dport?"==":"",
dport?dport:""
);
break;
case DIR_A_TO_FROM_ANY:
str = g_strdup_printf("%s==%s%s%s%s%s",
ct_get_filter_name(&conv->src_address, conv->sat, conv->port_type, FN_ANY_ADDRESS),
ep_address_to_str(&conv->src_address),
sport?" && ":"",
sport?ct_get_filter_name(&conv->src_address, conv->sat, conv->port_type, FN_ANY_PORT):"",
sport?"==":"",
sport?sport:""
);
break;
case DIR_A_TO_ANY:
str = g_strdup_printf("%s==%s%s%s%s%s",
ct_get_filter_name(&conv->src_address, conv->sat, conv->port_type, FN_SRC_ADDRESS),
ep_address_to_str(&conv->src_address),
sport?" && ":"",
sport?ct_get_filter_name(&conv->src_address, conv->sat, conv->port_type, FN_SRC_PORT):"",
sport?"==":"",
sport?sport:""
);
break;
case DIR_A_FROM_ANY:
str = g_strdup_printf("%s==%s%s%s%s%s",
ct_get_filter_name(&conv->src_address, conv->sat, conv->port_type, FN_DST_ADDRESS),
ep_address_to_str(&conv->src_address),
sport?" && ":"",
sport?ct_get_filter_name(&conv->src_address, conv->sat, conv->port_type, FN_DST_PORT):"",
sport?"==":"",
sport?sport:""
);
break;
case DIR_ANY_TO_FROM_B:
str = g_strdup_printf("%s==%s%s%s%s%s",
ct_get_filter_name(&conv->dst_address, conv->sat, conv->port_type, FN_ANY_ADDRESS),
ep_address_to_str(&conv->dst_address),
dport?" && ":"",
dport?ct_get_filter_name(&conv->dst_address, conv->sat, conv->port_type, FN_ANY_PORT):"",
dport?"==":"",
dport?dport:""
);
break;
case DIR_ANY_FROM_B:
str = g_strdup_printf("%s==%s%s%s%s%s",
ct_get_filter_name(&conv->dst_address, conv->sat, conv->port_type, FN_SRC_ADDRESS),
ep_address_to_str(&conv->dst_address),
dport?" && ":"",
dport?ct_get_filter_name(&conv->dst_address, conv->sat, conv->port_type, FN_SRC_PORT):"",
dport?"==":"",
dport?dport:""
);
break;
case DIR_ANY_TO_B:
str = g_strdup_printf("%s==%s%s%s%s%s",
ct_get_filter_name(&conv->dst_address, conv->sat, conv->port_type, FN_DST_ADDRESS),
ep_address_to_str(&conv->dst_address),
dport?" && ":"",
dport?ct_get_filter_name(&conv->dst_address, conv->sat, conv->port_type, FN_DST_PORT):"",
dport?"==":"",
dport?dport:""
);
break;
default:
g_assert_not_reached();
}
apply_selected_filter (callback_action, str);
g_free (str);
}
static gboolean
ct_show_popup_menu_cb(void *widg _U_, GdkEvent *event, conversations_table *ct)
{
GdkEventButton *bevent = (GdkEventButton *)event;
if(event->type==GDK_BUTTON_PRESS && bevent->button==3){
gtk_menu_popup(GTK_MENU(ct->menu), NULL, NULL, NULL, NULL,
bevent->button, bevent->time);
}
return FALSE;
}
static void
conv_apply_as_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_apply_as_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, DIR_A_TO_B));
}
static void
conv_apply_as_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, DIR_A_FROM_B));
}
static void
conv_apply_as_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_apply_as_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, DIR_A_TO_ANY));
}
static void
conv_apply_as_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_apply_as_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_apply_as_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_apply_as_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, DIR_ANY_TO_B));
}
static void
conv_apply_as_not_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_apply_as_not_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, DIR_A_TO_B));
}
static void
conv_apply_as_not_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, DIR_A_FROM_B));
}
static void
conv_apply_as_not_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_apply_as_not_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, DIR_A_TO_ANY));
}
static void
conv_apply_as_not_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_apply_as_not_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_apply_as_not_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_apply_as_not_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, DIR_ANY_TO_B));
}
static void
conv_apply_and_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_apply_and_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, DIR_A_TO_B));
}
static void
conv_apply_and_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, DIR_A_FROM_B));
}
static void
conv_apply_and_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_apply_and_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, DIR_A_TO_ANY));
}
static void
conv_apply_and_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_apply_and_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_apply_and_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_apply_and_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, DIR_ANY_TO_B));
}
static void
conv_apply_or_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_apply_or_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, DIR_A_TO_B));
}
static void
conv_apply_or_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, DIR_A_FROM_B));
}
static void
conv_apply_or_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_apply_or_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, DIR_A_TO_ANY));
}
static void
conv_apply_or_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_apply_or_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_apply_or_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_apply_or_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, DIR_ANY_TO_B));
}
static void
conv_apply_and_not_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_apply_and_not_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, DIR_A_TO_B));
}
static void
conv_apply_and_not_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, DIR_A_FROM_B));
}
static void
conv_apply_and_not_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_apply_and_not_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, DIR_A_TO_ANY));
}
static void
conv_apply_and_not_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_apply_and_not_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_apply_and_not_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_apply_and_not_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, DIR_ANY_TO_B));
}
static void
conv_apply_or_not_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_apply_or_not_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, DIR_A_TO_B));
}
static void
conv_apply_or_not_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, DIR_A_FROM_B));
}
static void
conv_apply_or_not_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_apply_or_not_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, DIR_A_TO_ANY));
}
static void
conv_apply_or_not_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_apply_or_not_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_apply_or_not_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_apply_or_not_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, DIR_ANY_TO_B));
}
static void
conv_prepare_as_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_prepare_as_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, DIR_A_TO_B));
}
static void
conv_prepare_as_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, DIR_A_FROM_B));
}
static void
conv_prepare_as_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_prepare_as_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, DIR_A_TO_ANY));
}
static void
conv_prepare_as_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_prepare_as_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_prepare_as_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_prepare_as_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, DIR_ANY_TO_B));
}
static void
conv_prepare_as_not_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_prepare_as_not_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, DIR_A_TO_B));
}
static void
conv_prepare_as_not_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, DIR_A_FROM_B));
}
static void
conv_prepare_as_not_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_prepare_as_not_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, DIR_A_TO_ANY));
}
static void
conv_prepare_as_not_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_prepare_as_not_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_prepare_as_not_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_prepare_as_not_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, DIR_ANY_TO_B));
}
static void
conv_prepare_and_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_prepare_and_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, DIR_A_TO_B));
}
static void
conv_prepare_and_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, DIR_A_FROM_B));
}
static void
conv_prepare_and_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_prepare_and_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, DIR_A_TO_ANY));
}
static void
conv_prepare_and_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_prepare_and_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_prepare_and_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_prepare_and_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, DIR_ANY_TO_B));
}
static void
conv_prepare_or_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_prepare_or_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, DIR_A_TO_B));
}
static void
conv_prepare_or_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, DIR_A_FROM_B));
}
static void
conv_prepare_or_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_prepare_or_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, DIR_A_TO_ANY));
}
static void
conv_prepare_or_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_prepare_or_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_prepare_or_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_prepare_or_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, DIR_ANY_TO_B));
}
static void
conv_prepare_and_not_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_prepare_and_not_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, DIR_A_TO_B));
}
static void
conv_prepare_and_not_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, DIR_A_FROM_B));
}
static void
conv_prepare_and_not_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_prepare_and_not_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, DIR_A_TO_ANY));
}
static void
conv_prepare_and_not_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_prepare_and_not_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_prepare_and_not_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_prepare_and_not_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, DIR_ANY_TO_B));
}
static void
conv_prepare_or_not_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_prepare_or_not_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, DIR_A_TO_B));
}
static void
conv_prepare_or_not_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, DIR_A_FROM_B));
}
static void
conv_prepare_or_not_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_prepare_or_not_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, DIR_A_TO_ANY));
}
static void
conv_prepare_or_not_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_prepare_or_not_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_prepare_or_not_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_prepare_or_not_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, DIR_ANY_TO_B));
}
static void
conv_find_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_find_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, DIR_A_TO_B));
}
static void
conv_find_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, DIR_A_FROM_B));
}
static void
conv_find_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_find_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, DIR_A_TO_ANY));
}
static void
conv_find_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_find_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_find_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_find_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, DIR_ANY_TO_B));
}
static void
conv_find_next_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_find_next_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, DIR_A_TO_B));
}
static void
conv_find_next_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, DIR_A_FROM_B));
}
static void
conv_find_next_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_find_next_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, DIR_A_TO_ANY));
}
static void
conv_find_next_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_find_next_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_find_next_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_find_next_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, DIR_ANY_TO_B));
}
static void
conv_find_previous_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_find_previous_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, DIR_A_TO_B));
}
static void
conv_find_previous_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, DIR_A_FROM_B));
}
static void
conv_find_previous_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_find_previous_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, DIR_A_TO_ANY));
}
static void
conv_find_previous_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_find_previous_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_find_previous_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_find_previous_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, DIR_ANY_TO_B));
}
static void
conv_color_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, DIR_A_TO_FROM_B));
}
static void
conv_color_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, DIR_A_TO_B));
}
static void
conv_color_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, DIR_A_FROM_B));
}
static void
conv_color_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, DIR_A_TO_FROM_ANY));
}
static void
conv_color_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, DIR_A_TO_ANY));
}
static void
conv_color_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, DIR_A_FROM_ANY));
}
static void
conv_color_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, DIR_ANY_TO_FROM_B));
}
static void
conv_color_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, DIR_ANY_FROM_B));
}
static void
conv_color_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, DIR_ANY_TO_B));
}
static void
ct_create_popup_menu(conversations_table *ct)
{
GtkUIManager *ui_manager;
GtkActionGroup *action_group;
GError *error = NULL;
action_group = gtk_action_group_new ("ConvActionGroup");
gtk_action_group_add_actions (action_group,
(gpointer)conv_filter_menu_entries,
G_N_ELEMENTS(conv_filter_menu_entries),
(gpointer)ct);
ui_manager = gtk_ui_manager_new ();
gtk_ui_manager_insert_action_group (ui_manager, action_group, 0);
gtk_ui_manager_add_ui_from_string (ui_manager,ui_desc_conv_filter_popup, -1, &error);
if (error != NULL)
{
fprintf (stderr, "Warning: building conversation filter popup failed: %s\n",
error->message);
g_error_free (error);
error = NULL;
}
ct->menu = gtk_ui_manager_get_widget(ui_manager, "/ConversationFilterPopup");
g_signal_connect(ct->table, "button_press_event", G_CALLBACK(ct_show_popup_menu_cb), ct);
}
static void
get_ct_table_address(conversations_table *ct, conv_t *conv, char **entries)
{
char *port;
guint32 pt;
if(!ct->resolve_names)
entries[0] = ep_address_to_str(&conv->src_address);
else {
entries[0] = (char *)get_addr_name(&conv->src_address);
}
pt = conv->port_type;
if(!ct->resolve_names) pt = PT_NONE;
switch(pt) {
case(PT_TCP):
entries[1] = get_tcp_port(conv->src_port);
break;
case(PT_UDP):
entries[1] = get_udp_port(conv->src_port);
break;
case(PT_SCTP):
entries[1] = get_sctp_port(conv->src_port);
break;
default:
port=ct_port_to_str(conv->port_type, conv->src_port);
entries[1] = port?port:"";
}
if(!ct->resolve_names)
entries[2]=ep_address_to_str(&conv->dst_address);
else {
entries[2]=(char *)get_addr_name(&conv->dst_address);
}
switch(pt) {
case(PT_TCP):
entries[3]=get_tcp_port(conv->dst_port);
break;
case(PT_UDP):
entries[3]=get_udp_port(conv->dst_port);
break;
case(PT_SCTP):
entries[3]=get_sctp_port(conv->dst_port);
break;
default:
port=ct_port_to_str(conv->port_type, conv->dst_port);
entries[3]=port?port:"";
}
}
static void
draw_ct_table_addresses(conversations_table *ct)
{
guint32 i;
char *entries[4];
GtkListStore *store;
if (!ct->num_conversations)
return;
store = GTK_LIST_STORE(gtk_tree_view_get_model(ct->table));
g_object_ref(store);
gtk_tree_view_set_model(GTK_TREE_VIEW(ct->table), NULL);
for(i=0;i<ct->num_conversations;i++){
conv_t *conv = &g_array_index(ct->conversations, conv_t, i);
if (!conv->iter_valid)
continue;
get_ct_table_address(ct, conv, entries);
gtk_list_store_set (store, &conv->iter,
SRC_ADR_COLUMN, entries[0],
SRC_PORT_COLUMN, entries[1],
DST_ADR_COLUMN, entries[2],
DST_PORT_COLUMN, entries[3],
-1);
}
gtk_tree_view_set_model(GTK_TREE_VIEW(ct->table), GTK_TREE_MODEL(store));
g_object_unref(store);
}
static void
draw_ct_table_data(conversations_table *ct)
{
guint32 i;
char title[256];
GtkListStore *store;
gboolean first = TRUE;
if (ct->page_lb) {
if(ct->num_conversations) {
g_snprintf(title, sizeof(title), "%s: %u", ct->name, ct->num_conversations);
} else {
g_snprintf(title, sizeof(title), "%s", ct->name);
}
gtk_label_set_text(GTK_LABEL(ct->page_lb), title);
gtk_widget_set_sensitive(ct->page_lb, ct->num_conversations);
} else {
if(ct->num_conversations) {
g_snprintf(title, sizeof(title), "%s Conversations: %u", ct->name, ct->num_conversations);
} else {
g_snprintf(title, sizeof(title), "%s Conversations", ct->name);
}
gtk_label_set_text(GTK_LABEL(ct->name_lb), title);
}
store = GTK_LIST_STORE(gtk_tree_view_get_model(ct->table));
for(i=0;i<ct->num_conversations;i++){
char start_time[COL_STR_LEN], duration[COL_STR_LEN],
txbps[COL_STR_LEN], rxbps[COL_STR_LEN];
char *tx_ptr, *rx_ptr;
double duration_s;
conv_t *conversation = &g_array_index(ct->conversations, conv_t, i);
if (!conversation->modified)
continue;
if (first) {
g_object_ref(store);
gtk_tree_view_set_model(GTK_TREE_VIEW(ct->table), NULL);
first = FALSE;
}
duration_s = nstime_to_sec(&conversation->stop_time) - nstime_to_sec(&conversation->start_time);
g_snprintf(start_time, COL_STR_LEN, "%.9f", nstime_to_sec(&conversation->start_time));
g_snprintf(duration, COL_STR_LEN, "%.4f", duration_s);
if (duration_s > 0 && conversation->tx_frames > 1) {
g_snprintf(txbps, COL_STR_LEN, "%.2f", (gint64) conversation->tx_bytes * 8 / duration_s);
tx_ptr = txbps;
} else {
tx_ptr = NO_BPS_STR;
}
if (duration_s > 0 && conversation->rx_frames > 1) {
g_snprintf(rxbps, COL_STR_LEN, "%.2f", (gint64) conversation->rx_bytes * 8 / duration_s);
rx_ptr = rxbps;
} else {
rx_ptr = NO_BPS_STR;
}
conversation->modified = FALSE;
if (!conversation->iter_valid) {
char *entries[4];
get_ct_table_address(ct, conversation, entries);
conversation->iter_valid = TRUE;
gtk_list_store_insert_with_values( store , &conversation->iter, G_MAXINT,
SRC_ADR_COLUMN, entries[0],
SRC_PORT_COLUMN, entries[1],
DST_ADR_COLUMN, entries[2],
DST_PORT_COLUMN, entries[3],
PACKETS_COLUMN, conversation->tx_frames+conversation->rx_frames,
BYTES_COLUMN, conversation->tx_bytes+conversation->rx_bytes,
PKT_AB_COLUMN, conversation->tx_frames,
BYTES_AB_COLUMN, conversation->tx_bytes,
PKT_BA_COLUMN, conversation->rx_frames,
BYTES_BA_COLUMN, conversation->rx_bytes,
START_COLUMN, start_time,
DURATION_COLUMN, duration,
BPS_AB_COLUMN, tx_ptr,
BPS_BA_COLUMN, rx_ptr,
INDEX_COLUMN, i,
-1);
}
else {
gtk_list_store_set (store, &conversation->iter,
PACKETS_COLUMN, conversation->tx_frames+conversation->rx_frames,
BYTES_COLUMN, conversation->tx_bytes+conversation->rx_bytes,
PKT_AB_COLUMN, conversation->tx_frames,
BYTES_AB_COLUMN, conversation->tx_bytes,
PKT_BA_COLUMN, conversation->rx_frames,
BYTES_BA_COLUMN, conversation->rx_bytes,
START_COLUMN, start_time,
DURATION_COLUMN, duration,
BPS_AB_COLUMN, tx_ptr,
BPS_BA_COLUMN, rx_ptr,
-1);
}
}
if (!first) {
if (!ct->fixed_col && ct->num_conversations >= 1000) {
ct->fixed_col = TRUE;
switch_to_fixed_col(ct->table);
}
gtk_tree_view_set_model(GTK_TREE_VIEW(ct->table), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
static void
draw_ct_table_data_cb(void *arg)
{
draw_ct_table_data(arg);
}
static gboolean
csv_handle(GtkTreeModel *model, GtkTreePath *path _U_, GtkTreeIter *iter,
gpointer data)
{
csv_t *csv = (csv_t *)data;
gchar *table_text;
int i;
unsigned idx;
conv_t *conv;
double duration_s;
guint64 value;
gtk_tree_model_get(model, iter, INDEX_COLUMN, &idx, -1);
conv=&g_array_index(csv->talkers->conversations, conv_t, idx);
duration_s = nstime_to_sec(&conv->stop_time) - nstime_to_sec(&conv->start_time);
for (i=0; i< csv->nb_cols; i++) {
if (i)
g_string_append(csv->CSV_str, ",");
switch(csv->columns_order[i]) {
case SRC_ADR_COLUMN:
case SRC_PORT_COLUMN:
case DST_ADR_COLUMN:
case DST_PORT_COLUMN:
gtk_tree_model_get(model, iter, csv->columns_order[i], &table_text, -1);
if (table_text) {
g_string_append_printf(csv->CSV_str, "\"%s\"", table_text);
g_free(table_text);
}
break;
case PACKETS_COLUMN:
case BYTES_COLUMN:
case PKT_AB_COLUMN:
case BYTES_AB_COLUMN:
case PKT_BA_COLUMN:
case BYTES_BA_COLUMN:
gtk_tree_model_get(model, iter, csv->columns_order[i], &value, -1);
g_string_append_printf(csv->CSV_str, "\"%" G_GINT64_MODIFIER "u\"", value);
break;
case START_COLUMN:
g_string_append_printf(csv->CSV_str, "\"%.9f\"", nstime_to_sec(&conv->start_time));
break;
case DURATION_COLUMN:
g_string_append_printf(csv->CSV_str, "\"%.4f\"", duration_s);
break;
case BPS_AB_COLUMN:
if (duration_s > 0 && conv->tx_frames > 1) {
g_string_append_printf(csv->CSV_str, "\"%.2f\"", (gint64) conv->tx_bytes * 8 / duration_s);
} else {
g_string_append(csv->CSV_str, "\"" NO_BPS_STR "\"");
}
break;
case BPS_BA_COLUMN:
if (duration_s > 0 && conv->rx_frames > 1) {
g_string_append_printf(csv->CSV_str, "\"%.2f\"", (gint64) conv->rx_bytes * 8 / duration_s);
} else {
g_string_append(csv->CSV_str, "\"" NO_BPS_STR "\"");
}
break;
default:
break;
}
}
g_string_append(csv->CSV_str,"\n");
return FALSE;
}
static void
copy_as_csv_cb(GtkWindow *copy_bt, gpointer data _U_)
{
GtkClipboard *cb;
GList *columns, *list;
GtkTreeViewColumn *column;
GtkListStore *store;
csv_t csv;
csv.talkers=g_object_get_data(G_OBJECT(copy_bt), CONV_PTR_KEY);
if (!csv.talkers)
return;
csv.CSV_str = g_string_new("");
columns = gtk_tree_view_get_columns(GTK_TREE_VIEW(csv.talkers->table));
csv.nb_cols = 0;
list = columns;
while(columns) {
column = columns->data;
if (gtk_tree_view_column_get_visible(column)) {
csv.columns_order[csv.nb_cols] = gtk_tree_view_column_get_sort_column_id(column);
if (csv.nb_cols)
g_string_append(csv.CSV_str, ",");
g_string_append_printf(csv.CSV_str, "\"%s\"", gtk_tree_view_column_get_title(column));
csv.nb_cols++;
}
columns = g_list_next(columns);
}
g_list_free(list);
g_string_append(csv.CSV_str,"\n");
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(csv.talkers->table)));
gtk_tree_model_foreach(GTK_TREE_MODEL(store), csv_handle, &csv);
cb = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
gtk_clipboard_set_text(cb, csv.CSV_str->str, -1);
g_string_free(csv.CSV_str, TRUE);
}
static void
init_default_col_size(GtkWidget *view)
{
default_col_size[SRC_ADR_COLUMN] = get_default_col_size(view, "00000000.000000000000");
default_col_size[DST_ADR_COLUMN] = default_col_size[SRC_ADR_COLUMN];
default_col_size[SRC_PORT_COLUMN] = get_default_col_size(view, "000000");
default_col_size[DST_PORT_COLUMN] = default_col_size[SRC_PORT_COLUMN];
default_col_size[PACKETS_COLUMN] = get_default_col_size(view, "00 000 000");
default_col_size[BYTES_COLUMN] = get_default_col_size(view, "0 000 000 000");
default_col_size[PKT_AB_COLUMN] = default_col_size[PACKETS_COLUMN];
default_col_size[PKT_BA_COLUMN] = default_col_size[PACKETS_COLUMN];
default_col_size[BYTES_AB_COLUMN] = default_col_size[BYTES_COLUMN];
default_col_size[BYTES_BA_COLUMN] = default_col_size[BYTES_COLUMN];
default_col_size[START_COLUMN] = get_default_col_size(view, "000000.000000000");
default_col_size[DURATION_COLUMN] = get_default_col_size(view, "000000.0000");
default_col_size[BPS_AB_COLUMN] = get_default_col_size(view, "000000000.00");
default_col_size[BPS_BA_COLUMN] = default_col_size[BPS_AB_COLUMN];
}
static gboolean
init_ct_table_page(conversations_table *conversations, GtkWidget *vbox, gboolean hide_ports, const char *table_name, const char *tap_name, const char *filter,
tap_packet_cb packet_func)
{
int i;
GString *error_string;
char title[256];
GtkListStore *store;
GtkWidget *tree;
GtkTreeViewColumn *column;
GtkCellRenderer *renderer;
GtkTreeSortable *sortable;
GtkTreeSelection *sel;
static gboolean col_size = FALSE;
conversations->page_lb=NULL;
conversations->resolve_names=TRUE;
conversations->has_ports=!hide_ports;
conversations->fixed_col = FALSE;
conversations->default_titles[0]="Address A",
conversations->default_titles[1]="Port A";
conversations->default_titles[2]="Address B";
conversations->default_titles[3]="Port B";
conversations->default_titles[4]="Packets";
conversations->default_titles[5]="Bytes";
conversations->default_titles[6]="Packets A" UTF8_RIGHTWARDS_ARROW "B";
conversations->default_titles[7]="Bytes A" UTF8_RIGHTWARDS_ARROW "B";
conversations->default_titles[8]="Packets A" UTF8_LEFTWARDS_ARROW "B";
conversations->default_titles[9]="Bytes A" UTF8_LEFTWARDS_ARROW "B";
conversations->default_titles[10]="Rel Start";
conversations->default_titles[11]="Duration";
conversations->default_titles[12]="bps A" UTF8_RIGHTWARDS_ARROW "B";
conversations->default_titles[13]="bps A" UTF8_LEFTWARDS_ARROW "B";
if (strcmp(table_name, "NCP")==0) {
conversations->default_titles[1]="Connection A";
conversations->default_titles[3]="Connection B";
}
g_snprintf(title, sizeof(title), "%s Conversations", table_name);
conversations->name_lb=gtk_label_new(title);
store = gtk_list_store_new (N_COLUMNS,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_UINT64,
G_TYPE_UINT64,
G_TYPE_UINT64,
G_TYPE_UINT64,
G_TYPE_UINT64,
G_TYPE_UINT64,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_UINT);
gtk_box_pack_start(GTK_BOX(vbox), conversations->name_lb, FALSE, FALSE, 0);
conversations->scrolled_window=scrolled_window_new(NULL, NULL);
gtk_box_pack_start(GTK_BOX(vbox), conversations->scrolled_window, TRUE, TRUE, 0);
tree = gtk_tree_view_new_with_model (GTK_TREE_MODEL (store));
conversations->table = GTK_TREE_VIEW(tree);
sortable = GTK_TREE_SORTABLE(store);
if (!col_size) {
col_size = TRUE;
init_default_col_size(GTK_WIDGET(conversations->table));
}
g_object_unref (G_OBJECT (store));
g_object_set_data(G_OBJECT(store), CONV_PTR_KEY, conversations);
g_object_set_data(G_OBJECT(conversations->table), CONV_PTR_KEY, conversations);
for (i = 0; i < N_COLUMNS -1; i++) {
renderer = gtk_cell_renderer_text_new ();
g_object_set(renderer, "ypad", 0, NULL);
switch(i) {
case SRC_ADR_COLUMN:
case SRC_PORT_COLUMN:
case DST_ADR_COLUMN:
case DST_PORT_COLUMN:
column = gtk_tree_view_column_new_with_attributes (conversations->default_titles[i], renderer, "text",
i, NULL);
if(hide_ports && (i == 1 || i == 3)){
gtk_tree_view_column_set_visible(column, FALSE);
}
gtk_tree_sortable_set_sort_func(sortable, i, ct_sort_func, GINT_TO_POINTER(i), NULL);
break;
case PACKETS_COLUMN:
case BYTES_COLUMN:
case PKT_AB_COLUMN:
case BYTES_AB_COLUMN:
case PKT_BA_COLUMN:
case BYTES_BA_COLUMN:
g_object_set(G_OBJECT(renderer), "xalign", 1.0, NULL);
column = gtk_tree_view_column_new_with_attributes (conversations->default_titles[i], renderer, NULL);
gtk_tree_view_column_set_cell_data_func(column, renderer, u64_data_func, GINT_TO_POINTER(i), NULL);
break;
default:
g_object_set(G_OBJECT(renderer), "xalign", 1.0, NULL);
column = gtk_tree_view_column_new_with_attributes (conversations->default_titles[i], renderer, "text",
i, NULL);
gtk_tree_sortable_set_sort_func(sortable, i, ct_sort_func, GINT_TO_POINTER(i), NULL);
break;
}
gtk_tree_view_column_set_sort_column_id(column, i);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_reorderable(column, TRUE);
gtk_tree_view_column_set_min_width(column, 40);
gtk_tree_view_column_set_fixed_width(column, default_col_size[i]);
gtk_tree_view_append_column (conversations->table, column);
#if 0
if (i == PACKETS_COLUMN) {
gtk_tree_view_column_clicked(column);
gtk_tree_view_column_clicked(column);
}
#endif
}
gtk_container_add(GTK_CONTAINER(conversations->scrolled_window), (GtkWidget *)conversations->table);
gtk_tree_view_set_rules_hint(conversations->table, TRUE);
gtk_tree_view_set_headers_clickable(conversations->table, TRUE);
gtk_tree_view_set_reorderable (conversations->table, TRUE);
conversations->num_conversations=0;
conversations->conversations=NULL;
conversations->hashtable=NULL;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(conversations->table));
gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
ct_create_popup_menu(conversations);
error_string=register_tap_listener(tap_name, conversations, filter, 0, reset_ct_table_data_cb, packet_func,
draw_ct_table_data_cb);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
return FALSE;
}
return TRUE;
}
static void
follow_stream_cb(GtkWidget *follow_stream_bt, gpointer data _U_)
{
conversations_table *ct = g_object_get_data (G_OBJECT(follow_stream_bt), CONV_PTR_KEY);
GtkTreeIter iter;
GtkTreeModel *model;
GtkTreeSelection *sel;
guint32 idx = 0;
gchar *filter = NULL;
conv_t *conv;
if (!ct)
return;
sel = gtk_tree_view_get_selection (GTK_TREE_VIEW(ct->table));
if (!gtk_tree_selection_get_selected(sel, &model, &iter)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "No conversation selected");
return;
}
gtk_tree_model_get (model, &iter, INDEX_COLUMN, &idx, -1);
if (idx >= ct->num_conversations) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "No conversation selected");
return;
}
conv = &g_array_index(ct->conversations, conv_t, idx);
if ((strcmp(ct->name, "TCP") == 0) && (conv->conv_id != CONV_ID_UNSET))
{
filter = g_strdup_printf("tcp.stream eq %d", conv->conv_id);
}
else
{
filter = g_strdup_printf("%s==%s && %s==%s && %s==%s && %s==%s",
ct_get_filter_name(&conv->src_address, conv->sat, conv->port_type, FN_ANY_ADDRESS),
ep_address_to_str(&conv->src_address),
ct_get_filter_name(&conv->src_address, conv->sat, conv->port_type, FN_ANY_PORT),
ct_port_to_str(conv->port_type, conv->src_port),
ct_get_filter_name(&conv->dst_address, conv->sat, conv->port_type, FN_ANY_ADDRESS),
ep_address_to_str(&conv->dst_address),
ct_get_filter_name(&conv->dst_address, conv->sat, conv->port_type, FN_ANY_PORT),
ct_port_to_str(conv->port_type, conv->dst_port));
}
apply_selected_filter(ACTYPE_SELECTED|ACTION_MATCH, filter);
g_free(filter);
filter = NULL;
if (strcmp(ct->name, "TCP") == 0)
follow_tcp_stream_cb(follow_stream_bt, data);
else if (strcmp(ct->name, "UDP") == 0)
follow_udp_stream_cb(follow_stream_bt, data);
else
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Unknown stream: %s", ct->name);
}
void
init_conversation_table(gboolean hide_ports, const char *table_name, const char *tap_name, const char *filter, tap_packet_cb packet_func)
{
conversations_table *conversations;
char *display_name;
char title[256];
GtkWidget *vbox;
GtkWidget *bbox;
GtkWidget *close_bt, *help_bt;
gboolean ret;
GtkWidget *copy_bt, *follow_stream_bt;
gboolean add_follow_stream_button = FALSE;
conversations=g_malloc0(sizeof(conversations_table));
conversations->name=table_name;
conversations->filter=filter;
conversations->use_dfilter=FALSE;
display_name = cf_get_display_name(&cfile);
g_snprintf(title, sizeof(title), "%s Conversations: %s", table_name, display_name);
g_free(display_name);
conversations->win = dlg_window_new(title);
gtk_window_set_destroy_with_parent (GTK_WINDOW(conversations->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(conversations->win), 750, 400);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(conversations->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
ret = init_ct_table_page(conversations, vbox, hide_ports, table_name, tap_name, filter, packet_func);
if(ret == FALSE) {
g_free(conversations);
return;
}
if ((strcmp(table_name, "TCP") == 0) || (strcmp(table_name, "UDP") == 0))
add_follow_stream_button = TRUE;
if (add_follow_stream_button)
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, GTK_STOCK_COPY, WIRESHARK_STOCK_FOLLOW_STREAM, GTK_STOCK_HELP, NULL);
else
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, GTK_STOCK_COPY, GTK_STOCK_HELP, NULL);
gtk_box_pack_end(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
close_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(conversations->win, close_bt, window_cancel_button_cb);
copy_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_COPY);
gtk_widget_set_tooltip_text(copy_bt, "Copy all statistical values of this page to the clipboard in CSV (Comma Separated Values) format.");
g_object_set_data(G_OBJECT(copy_bt), CONV_PTR_KEY, conversations);
g_signal_connect(copy_bt, "clicked", G_CALLBACK(copy_as_csv_cb), NULL);
if (add_follow_stream_button) {
follow_stream_bt = g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_FOLLOW_STREAM);
g_object_set_data(G_OBJECT(follow_stream_bt), E_DFILTER_TE_KEY, main_display_filter_widget);
g_object_set_data(G_OBJECT(follow_stream_bt), CONV_PTR_KEY, conversations);
g_signal_connect(follow_stream_bt, "clicked", G_CALLBACK(follow_stream_cb), NULL);
}
help_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_STATS_CONVERSATIONS_DIALOG);
g_signal_connect(conversations->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(conversations->win, "destroy", G_CALLBACK(ct_win_destroy_cb), conversations);
gtk_widget_show_all(conversations->win);
window_present(conversations->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(conversations->win));
}
static void
ct_nb_switch_page_cb(GtkNotebook *nb, gpointer *pg _U_, guint page, gpointer data)
{
GtkWidget *copy_bt = (GtkWidget *) data;
GtkWidget *follow_stream_bt = g_object_get_data(G_OBJECT(nb), FOLLOW_STREAM_BT_KEY);
void **pages = g_object_get_data(G_OBJECT(nb), NB_PAGES_KEY);
page++;
if (pages && (page > 0) && ((int) page <= GPOINTER_TO_INT(pages[0]))) {
g_object_set_data(G_OBJECT(copy_bt), CONV_PTR_KEY, pages[page]);
g_object_set_data(G_OBJECT(follow_stream_bt), CONV_PTR_KEY, pages[page]);
if (strcmp(((conversations_table *)pages[page])->name, "TCP") == 0) {
gtk_widget_set_tooltip_text(follow_stream_bt, "Follow TCP Stream.");
gtk_widget_set_sensitive(follow_stream_bt, TRUE);
} else if (strcmp(((conversations_table *)pages[page])->name, "UDP") == 0) {
gtk_widget_set_tooltip_text(follow_stream_bt, "Follow UDP Stream.");
gtk_widget_set_sensitive(follow_stream_bt, TRUE);
} else {
gtk_widget_set_tooltip_text(follow_stream_bt, "Follow TCP or UDP Stream.");
gtk_widget_set_sensitive(follow_stream_bt, FALSE);
}
}
}
static void
ct_win_destroy_notebook_cb(GtkWindow *win _U_, gpointer data)
{
void ** pages = data;
int page;
for (page=1; page<=GPOINTER_TO_INT(pages[0]); page++) {
ct_win_destroy_cb(NULL, pages[page]);
}
g_free(pages);
}
static conversations_table *
init_ct_notebook_page_cb(gboolean hide_ports, const char *table_name, const char *tap_name, const char *filter, tap_packet_cb packet_func)
{
gboolean ret;
GtkWidget *page_vbox;
conversations_table *conversations;
conversations=g_malloc0(sizeof(conversations_table));
conversations->name=table_name;
conversations->filter=filter;
conversations->resolve_names=TRUE;
conversations->use_dfilter=FALSE;
page_vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
conversations->win = page_vbox;
gtk_container_set_border_width(GTK_CONTAINER(page_vbox), 6);
ret = init_ct_table_page(conversations, page_vbox, hide_ports, table_name, tap_name, filter, packet_func);
if(ret == FALSE) {
g_free(conversations);
return NULL;
}
return conversations;
}
void
register_conversation_table(gboolean hide_ports, const char *table_name, const char *tap_name, const char *filter, tap_packet_cb packet_func)
{
register_ct_t *table;
table = g_malloc(sizeof(register_ct_t));
table->hide_ports = hide_ports;
table->table_name = table_name;
table->tap_name = tap_name;
table->filter = filter;
table->packet_func = packet_func;
registered_ct_tables = g_slist_append(registered_ct_tables, table);
}
static void
ct_resolve_toggle_dest(GtkWidget *widget, gpointer data)
{
int page;
void ** pages = data;
gboolean resolve_names;
conversations_table *conversations;
resolve_names = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget));
for (page=1; page<=GPOINTER_TO_INT(pages[0]); page++) {
conversations = pages[page];
conversations->resolve_names = resolve_names;
draw_ct_table_addresses(conversations);
}
}
static void
ct_filter_toggle_dest(GtkWidget *widget, gpointer data)
{
int page;
void ** pages = data;
gboolean use_filter;
conversations_table *conversations = NULL;
use_filter = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget));
for (page=1; page<=GPOINTER_TO_INT(pages[0]); page++) {
conversations = pages[page];
conversations->use_dfilter = use_filter;
reset_ct_table_data(conversations);
}
cf_retap_packets(&cfile);
if (conversations) {
gdk_window_raise(gtk_widget_get_window(conversations->win));
}
}
void
init_conversation_notebook_cb(GtkWidget *w _U_, gpointer d _U_)
{
conversations_table *conversations;
char *display_name;
char title[256];
GtkWidget *vbox;
GtkWidget *hbox;
GtkWidget *bbox;
GtkWidget *close_bt, *help_bt;
GtkWidget *win;
GtkWidget *resolv_cb;
GtkWidget *filter_cb;
int page;
void ** pages;
GtkWidget *nb;
GtkWidget *page_lb;
GSList *current_table;
register_ct_t *registered;
GtkWidget *copy_bt;
GtkWidget *follow_stream_bt;
pages = g_malloc(sizeof(void *) * (g_slist_length(registered_ct_tables) + 1));
display_name = cf_get_display_name(&cfile);
g_snprintf(title, sizeof(title), "Conversations: %s", display_name);
g_free(display_name);
win = dlg_window_new(title);
gtk_window_set_destroy_with_parent (GTK_WINDOW(win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(win), 750, 400);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
gtk_container_add(GTK_CONTAINER(win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
nb = gtk_notebook_new();
gtk_container_add(GTK_CONTAINER(vbox), nb);
g_object_set_data(G_OBJECT(nb), NB_PAGES_KEY, pages);
page = 0;
current_table = registered_ct_tables;
while(current_table) {
registered = current_table->data;
conversations = init_ct_notebook_page_cb(registered->hide_ports, registered->table_name, registered->tap_name,
registered->filter, registered->packet_func);
if (conversations) {
g_object_set_data(G_OBJECT(conversations->win), CONV_PTR_KEY, conversations);
page_lb = gtk_label_new("");
gtk_notebook_append_page(GTK_NOTEBOOK(nb), conversations->win, page_lb);
conversations->win = win;
conversations->page_lb = page_lb;
pages[++page] = conversations;
}
current_table = g_slist_next(current_table);
}
pages[0] = GINT_TO_POINTER(page);
hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);
resolv_cb = gtk_check_button_new_with_mnemonic("Name resolution");
gtk_container_add(GTK_CONTAINER(hbox), resolv_cb);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(resolv_cb), TRUE);
gtk_widget_set_tooltip_text(resolv_cb, "Show results of name resolutions rather than the \"raw\" values. "
"Please note: The corresponding name resolution must be enabled.");
g_signal_connect(resolv_cb, "toggled", G_CALLBACK(ct_resolve_toggle_dest), pages);
filter_cb = gtk_check_button_new_with_mnemonic("Limit to display filter");
gtk_container_add(GTK_CONTAINER(hbox), filter_cb);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(filter_cb), FALSE);
gtk_widget_set_tooltip_text(filter_cb, "Limit the list to conversations matching the current display filter.");
g_signal_connect(filter_cb, "toggled", G_CALLBACK(ct_filter_toggle_dest), pages);
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, GTK_STOCK_COPY, WIRESHARK_STOCK_FOLLOW_STREAM, GTK_STOCK_HELP, NULL);
gtk_box_pack_end(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
close_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(win, close_bt, window_cancel_button_cb);
copy_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_COPY);
gtk_widget_set_tooltip_text(copy_bt, "Copy all statistical values of this page to the clipboard in CSV (Comma Separated Values) format.");
g_signal_connect(copy_bt, "clicked", G_CALLBACK(copy_as_csv_cb), NULL);
g_object_set_data(G_OBJECT(copy_bt), CONV_PTR_KEY, pages[page]);
follow_stream_bt = g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_FOLLOW_STREAM);
gtk_widget_set_tooltip_text(follow_stream_bt, "Follow Stream.");
g_object_set_data(G_OBJECT(follow_stream_bt), E_DFILTER_TE_KEY, main_display_filter_widget);
g_object_set_data(G_OBJECT(follow_stream_bt), CONV_PTR_KEY, pages[page]);
g_signal_connect(follow_stream_bt, "clicked", G_CALLBACK(follow_stream_cb), NULL);
g_object_set_data(G_OBJECT(nb), FOLLOW_STREAM_BT_KEY, follow_stream_bt);
g_signal_connect(nb, "switch-page", G_CALLBACK(ct_nb_switch_page_cb), copy_bt);
help_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_STATS_CONVERSATIONS_DIALOG);
g_signal_connect(win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(win, "destroy", G_CALLBACK(ct_win_destroy_notebook_cb), pages);
gtk_widget_show_all(win);
window_present(win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(win));
}
static guint
conversation_hash(gconstpointer v)
{
const conv_key_t *key = (const conv_key_t *)v;
guint hash_val;
hash_val = 0;
ADD_ADDRESS_TO_HASH(hash_val, &key->addr1);
hash_val += key->port1;
ADD_ADDRESS_TO_HASH(hash_val, &key->addr2);
hash_val += key->port2;
hash_val ^= key->conv_id;
return hash_val;
}
static gint
conversation_match(gconstpointer v, gconstpointer w)
{
const conv_key_t *v1 = (const conv_key_t *)v;
const conv_key_t *v2 = (const conv_key_t *)w;
if (v1->conv_id == v2->conv_id)
{
if (v1->port1 == v2->port1 &&
v1->port2 == v2->port2 &&
ADDRESSES_EQUAL(&v1->addr1, &v2->addr1) &&
ADDRESSES_EQUAL(&v1->addr2, &v2->addr2)) {
return 1;
}
if (v1->port2 == v2->port1 &&
v1->port1 == v2->port2 &&
ADDRESSES_EQUAL(&v1->addr2, &v2->addr1) &&
ADDRESSES_EQUAL(&v1->addr1, &v2->addr2)) {
return 1;
}
}
return 0;
}
void
add_conversation_table_data(conversations_table *ct, const address *src, const address *dst, guint32 src_port, guint32 dst_port, int num_frames, int num_bytes, nstime_t *ts, SAT_E sat, int port_type_val)
{
add_conversation_table_data_with_conv_id(ct, src, dst, src_port, dst_port, CONV_ID_UNSET, num_frames, num_bytes, ts, sat, port_type_val);
}
void
add_conversation_table_data_with_conv_id(
conversations_table *ct,
const address *src,
const address *dst,
guint32 src_port,
guint32 dst_port,
conv_id_t conv_id,
int num_frames,
int num_bytes,
nstime_t *ts,
SAT_E sat,
int port_type_val)
{
const address *addr1, *addr2;
guint32 port1, port2;
conv_t *conversation = NULL;
unsigned int conversation_idx = 0;
if (src_port > dst_port) {
addr1 = src;
addr2 = dst;
port1 = src_port;
port2 = dst_port;
} else if (src_port < dst_port) {
addr2 = src;
addr1 = dst;
port2 = src_port;
port1 = dst_port;
} else if (CMP_ADDRESS(src, dst) < 0) {
addr1 = src;
addr2 = dst;
port1 = src_port;
port2 = dst_port;
} else {
addr2 = src;
addr1 = dst;
port2 = src_port;
port1 = dst_port;
}
if (ct->conversations == NULL) {
ct->conversations = g_array_sized_new(FALSE, FALSE, sizeof(conv_t), 10000);
ct->hashtable = g_hash_table_new_full(conversation_hash,
conversation_match,
g_free,
NULL);
} else {
conv_key_t existing_key;
existing_key.addr1 = *addr1;
existing_key.addr2 = *addr2;
existing_key.port1 = port1;
existing_key.port2 = port2;
existing_key.conv_id = conv_id;
conversation_idx = GPOINTER_TO_UINT(g_hash_table_lookup(ct->hashtable, &existing_key));
if (conversation_idx) {
conversation_idx--;
conversation=&g_array_index(ct->conversations, conv_t, conversation_idx);
}
}
if (conversation == NULL) {
conv_key_t *new_key;
conv_t conv;
COPY_ADDRESS(&conv.src_address, addr1);
COPY_ADDRESS(&conv.dst_address, addr2);
conv.sat = sat;
conv.port_type = port_type_val;
conv.src_port = port1;
conv.dst_port = port2;
conv.conv_id = conv_id;
conv.rx_frames = 0;
conv.tx_frames = 0;
conv.rx_bytes = 0;
conv.tx_bytes = 0;
conv.iter_valid = FALSE;
conv.modified = TRUE;
if (ts) {
memcpy(&conv.start_time, ts, sizeof(conv.start_time));
memcpy(&conv.stop_time, ts, sizeof(conv.stop_time));
} else {
nstime_set_unset(&conv.start_time);
nstime_set_unset(&conv.stop_time);
}
g_array_append_val(ct->conversations, conv);
conversation_idx = ct->num_conversations;
conversation=&g_array_index(ct->conversations, conv_t, conversation_idx);
new_key = g_new(conv_key_t, 1);
SET_ADDRESS(&new_key->addr1, conversation->src_address.type, conversation->src_address.len, conversation->src_address.data);
SET_ADDRESS(&new_key->addr2, conversation->dst_address.type, conversation->dst_address.len, conversation->dst_address.data);
new_key->port1 = port1;
new_key->port2 = port2;
new_key->conv_id = conv_id;
g_hash_table_insert(ct->hashtable, new_key, GUINT_TO_POINTER(conversation_idx +1));
ct->num_conversations++;
}
conversation->modified = TRUE;
if ( (!CMP_ADDRESS(src, addr1)) && (!CMP_ADDRESS(dst, addr2)) && (src_port==port1) && (dst_port==port2) ) {
conversation->tx_frames += num_frames;
conversation->tx_bytes += num_bytes;
} else {
conversation->rx_frames += num_frames;
conversation->rx_bytes += num_bytes;
}
if (ts) {
if (nstime_cmp(ts, &conversation->stop_time) > 0) {
memcpy(&conversation->stop_time, ts, sizeof(conversation->stop_time));
} else if (nstime_cmp(ts, &conversation->start_time) < 0) {
memcpy(&conversation->start_time, ts, sizeof(conversation->start_time));
}
}
}
