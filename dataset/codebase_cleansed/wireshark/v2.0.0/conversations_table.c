static void
reset_ct_table_data(conversations_table *ct)
{
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
error_string = set_tap_dfilter (&ct->hash, filter);
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
reset_conversation_table_data(&ct->hash);
}
static void
reset_ct_table_data_cb(void *arg)
{
conv_hash_t *hash = (conv_hash_t*)arg;
reset_ct_table_data((conversations_table *)hash->user_data);
}
static void
ct_win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
conversations_table *conversations=(conversations_table *)data;
remove_tap_listener(&conversations->hash);
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
conversations_table *ct = (conversations_table *)g_object_get_data(G_OBJECT(model), CONV_PTR_KEY);
conv_item_t *conv1 = NULL;
conv_item_t *conv2 = NULL;
double duration1, duration2;
gtk_tree_model_get(model, a, CONV_INDEX_COLUMN, &idx1, -1);
gtk_tree_model_get(model, b, CONV_INDEX_COLUMN, &idx2, -1);
if (!ct || idx1 >= ct->hash.conv_array->len || idx2 >= ct->hash.conv_array->len)
return 0;
conv1 = &g_array_index(ct->hash.conv_array, conv_item_t, idx1);
conv2 = &g_array_index(ct->hash.conv_array, conv_item_t, idx2);
switch(data_column){
case CONV_COLUMN_SRC_ADDR:
return(CMP_ADDRESS(&conv1->src_address, &conv2->src_address));
case CONV_COLUMN_DST_ADDR:
return(CMP_ADDRESS(&conv1->dst_address, &conv2->dst_address));
case CONV_COLUMN_SRC_PORT:
CMP_NUM(conv1->src_port, conv2->src_port);
case CONV_COLUMN_DST_PORT:
CMP_NUM(conv1->dst_port, conv2->dst_port);
case CONV_COLUMN_START:
return nstime_cmp(&conv1->start_time, &conv2->start_time);
}
duration1 = nstime_to_sec(&conv1->stop_time) - nstime_to_sec(&conv1->start_time);
duration2 = nstime_to_sec(&conv2->stop_time) - nstime_to_sec(&conv2->start_time);
switch(data_column){
case CONV_COLUMN_DURATION:
CMP_NUM(duration1, duration2);
case CONV_COLUMN_BPS_AB:
if (duration1 > 0 && conv1->tx_frames > 1 && duration2 > 0 && conv2->tx_frames > 1) {
CMP_NUM((gint64) conv1->tx_bytes / duration1, (gint64) conv2->tx_bytes / duration2);
} else {
CMP_NUM(conv1->tx_bytes, conv2->tx_bytes);
}
case CONV_COLUMN_BPS_BA:
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
conv_direction_e direction;
guint32 idx = 0;
conversations_table *ct = (conversations_table *)callback_data;
GtkTreeIter iter;
GtkTreeModel *model;
GtkTreeSelection *sel;
const char *str;
conv_item_t *conv;
direction = (conv_direction_e) FILTER_EXTRA(callback_action);
sel = gtk_tree_view_get_selection (GTK_TREE_VIEW(ct->table));
if (!gtk_tree_selection_get_selected(sel, &model, &iter))
return;
gtk_tree_model_get (model, &iter,
CONV_INDEX_COLUMN, &idx,
-1);
if(idx >= ct->hash.conv_array->len){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "No conversation selected");
return;
}
conv = &g_array_index(ct->hash.conv_array, conv_item_t, idx);
str = get_conversation_filter(conv, direction);
apply_selected_filter(callback_action, str);
g_free((char*)str);
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
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_apply_as_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_apply_as_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_apply_as_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_apply_as_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_apply_as_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_apply_as_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_apply_as_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_apply_as_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
conv_apply_as_not_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_apply_as_not_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_apply_as_not_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_apply_as_not_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_apply_as_not_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_apply_as_not_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_apply_as_not_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_apply_as_not_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_apply_as_not_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
conv_apply_and_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_apply_and_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_apply_and_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_apply_and_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_apply_and_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_apply_and_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_apply_and_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_apply_and_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_apply_and_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
conv_apply_or_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_apply_or_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_apply_or_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_apply_or_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_apply_or_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_apply_or_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_apply_or_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_apply_or_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_apply_or_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
conv_apply_and_not_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_apply_and_not_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_apply_and_not_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_apply_and_not_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_apply_and_not_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_apply_and_not_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_apply_and_not_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_apply_and_not_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_apply_and_not_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
conv_apply_or_not_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_apply_or_not_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_apply_or_not_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_apply_or_not_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_apply_or_not_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_apply_or_not_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_apply_or_not_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_apply_or_not_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_apply_or_not_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
conv_prepare_as_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_prepare_as_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_prepare_as_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_prepare_as_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_prepare_as_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_prepare_as_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_prepare_as_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_prepare_as_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_prepare_as_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
conv_prepare_as_not_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_prepare_as_not_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_prepare_as_not_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_prepare_as_not_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_prepare_as_not_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_prepare_as_not_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_prepare_as_not_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_prepare_as_not_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_prepare_as_not_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
conv_prepare_and_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_prepare_and_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_prepare_and_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_prepare_and_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_prepare_and_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_prepare_and_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_prepare_and_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_prepare_and_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_prepare_and_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
conv_prepare_or_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_prepare_or_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_prepare_or_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_prepare_or_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_prepare_or_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_prepare_or_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_prepare_or_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_prepare_or_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_prepare_or_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
conv_prepare_and_not_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_prepare_and_not_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_prepare_and_not_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_prepare_and_not_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_prepare_and_not_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_prepare_and_not_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_prepare_and_not_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_prepare_and_not_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_prepare_and_not_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
conv_prepare_or_not_selected_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_prepare_or_not_selected_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_prepare_or_not_selected_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_prepare_or_not_selected_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_prepare_or_not_selected_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_prepare_or_not_selected_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_prepare_or_not_selected_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_prepare_or_not_selected_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_prepare_or_not_selected_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
conv_find_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_find_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_find_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_find_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_find_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_find_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_find_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_find_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_find_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
conv_find_next_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_find_next_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_find_next_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_find_next_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_find_next_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_find_next_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_find_next_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_find_next_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_find_next_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
conv_find_previous_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_find_previous_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_find_previous_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_find_previous_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_find_previous_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_find_previous_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_find_previous_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_find_previous_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_find_previous_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_AND_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
conv_color_AtofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, CONV_DIR_A_TO_FROM_B));
}
static void
conv_color_AtoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, CONV_DIR_A_TO_B));
}
static void
conv_color_AfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, CONV_DIR_A_FROM_B));
}
static void
conv_color_AtofromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, CONV_DIR_A_TO_FROM_ANY));
}
static void
conv_color_AtoAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, CONV_DIR_A_TO_ANY));
}
static void
conv_color_AfromAny_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, CONV_DIR_A_FROM_ANY));
}
static void
conv_color_AnytofromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, CONV_DIR_ANY_TO_FROM_B));
}
static void
conv_color_AnyfromB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, CONV_DIR_ANY_FROM_B));
}
static void
conv_color_AnytoB_cb(GtkAction *action _U_, gpointer user_data)
{
ct_select_filter_cb( NULL, user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, CONV_DIR_ANY_TO_B));
}
static void
ct_create_popup_menu(conversations_table *ct)
{
GtkUIManager *ui_manager;
GtkActionGroup *action_group;
GError *error = NULL;
action_group = gtk_action_group_new ("ConvActionGroup");
gtk_action_group_add_actions (action_group,
(GtkActionEntry *)conv_filter_menu_entries,
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
draw_ct_table_addresses(conversations_table *ct)
{
guint idx;
GtkListStore *store;
GtkTreeIter iter;
gboolean iter_valid;
store = GTK_LIST_STORE(gtk_tree_view_get_model(ct->table));
g_object_ref(store);
gtk_tree_view_set_model(GTK_TREE_VIEW(ct->table), NULL);
iter_valid = gtk_tree_model_get_iter_first(GTK_TREE_MODEL(store), &iter);
while (iter_valid) {
conv_item_t *conv_item;
char *src_addr, *dst_addr, *src_port, *dst_port;
gtk_tree_model_get(GTK_TREE_MODEL(store), &iter, CONV_INDEX_COLUMN, &idx, -1);
conv_item = &g_array_index(ct->hash.conv_array, conv_item_t, idx);
src_addr = (char*)get_conversation_address(NULL, &conv_item->src_address, ct->resolve_names);
dst_addr = (char*)get_conversation_address(NULL, &conv_item->dst_address, ct->resolve_names);
src_port = (char*)get_conversation_port(NULL, conv_item->src_port, conv_item->ptype, ct->resolve_names);
dst_port = (char*)get_conversation_port(NULL, conv_item->dst_port, conv_item->ptype, ct->resolve_names);
gtk_list_store_set (store, &iter,
CONV_COLUMN_SRC_ADDR, src_addr,
CONV_COLUMN_SRC_PORT, src_port,
CONV_COLUMN_DST_ADDR, dst_addr,
CONV_COLUMN_DST_PORT, dst_port,
-1);
iter_valid = gtk_tree_model_iter_next(GTK_TREE_MODEL(store), &iter);
wmem_free(NULL, src_addr);
wmem_free(NULL, dst_addr);
wmem_free(NULL, src_port);
wmem_free(NULL, dst_port);
}
gtk_tree_view_set_model(GTK_TREE_VIEW(ct->table), GTK_TREE_MODEL(store));
g_object_unref(store);
}
static void
draw_ct_table_data(conversations_table *ct)
{
guint idx, new_idx;
char title[256];
GtkListStore *store;
GtkTreeIter iter, reselect_iter;
gboolean iter_valid;
gboolean first = TRUE;
if (ct->page_lb) {
if(ct->hash.conv_array && ct->hash.conv_array->len) {
g_snprintf(title, sizeof(title), "%s: %u", ct->name, ct->hash.conv_array->len);
} else {
g_snprintf(title, sizeof(title), "%s", ct->name);
}
gtk_label_set_text(GTK_LABEL(ct->page_lb), title);
gtk_widget_set_sensitive(ct->page_lb, ct->hash.conv_array && ct->hash.conv_array->len);
} else {
if(ct->hash.conv_array && ct->hash.conv_array->len) {
g_snprintf(title, sizeof(title), "%s Conversations: %u", ct->name, ct->hash.conv_array->len);
} else {
g_snprintf(title, sizeof(title), "%s Conversations", ct->name);
}
gtk_label_set_text(GTK_LABEL(ct->name_lb), title);
}
store = GTK_LIST_STORE(gtk_tree_view_get_model(ct->table));
iter_valid = gtk_tree_model_get_iter_first(GTK_TREE_MODEL(store), &iter);
new_idx = gtk_tree_model_iter_n_children(GTK_TREE_MODEL(store), NULL);
while (iter_valid || (ct->hash.conv_array && new_idx < ct->hash.conv_array->len)) {
char start_time[COL_STR_LEN], duration[COL_STR_LEN],
txbps[COL_STR_LEN], rxbps[COL_STR_LEN];
const char *tx_ptr, *rx_ptr;
double duration_s;
conv_item_t *conv_item;
if (!ct->hash.conv_array) {
continue;
}
if (iter_valid) {
gtk_tree_model_get(GTK_TREE_MODEL(store), &iter, CONV_INDEX_COLUMN, &idx, -1);
} else {
idx = new_idx;
new_idx++;
}
conv_item = &g_array_index(ct->hash.conv_array, conv_item_t, idx);
if (!conv_item->modified) {
iter_valid = gtk_tree_model_iter_next(GTK_TREE_MODEL(store), &iter);
continue;
}
if (iter_valid && (int)idx == ct->reselection_idx) {
reselect_iter = iter;
}
if (first) {
g_object_ref(store);
gtk_tree_view_set_model(GTK_TREE_VIEW(ct->table), NULL);
first = FALSE;
}
duration_s = nstime_to_sec(&conv_item->stop_time) - nstime_to_sec(&conv_item->start_time);
g_snprintf(start_time, COL_STR_LEN, "%.9f", nstime_to_sec(&conv_item->start_time));
g_snprintf(duration, COL_STR_LEN, "%.4f", duration_s);
if (duration_s > 0 && conv_item->tx_frames > 1) {
g_snprintf(txbps, COL_STR_LEN, "%.2f", (gint64) conv_item->tx_bytes * 8 / duration_s);
tx_ptr = txbps;
} else {
tx_ptr = NO_BPS_STR;
}
if (duration_s > 0 && conv_item->rx_frames > 1) {
g_snprintf(rxbps, COL_STR_LEN, "%.2f", (gint64) conv_item->rx_bytes * 8 / duration_s);
rx_ptr = rxbps;
} else {
rx_ptr = NO_BPS_STR;
}
conv_item->modified = FALSE;
if (iter_valid) {
gtk_list_store_set(store, &iter,
CONV_COLUMN_PACKETS, conv_item->tx_frames+conv_item->rx_frames,
CONV_COLUMN_BYTES, conv_item->tx_bytes+conv_item->rx_bytes,
CONV_COLUMN_PKT_AB, conv_item->tx_frames,
CONV_COLUMN_BYTES_AB, conv_item->tx_bytes,
CONV_COLUMN_PKT_BA, conv_item->rx_frames,
CONV_COLUMN_BYTES_BA, conv_item->rx_bytes,
CONV_COLUMN_START, start_time,
CONV_COLUMN_DURATION, duration,
CONV_COLUMN_BPS_AB, tx_ptr,
CONV_COLUMN_BPS_BA, rx_ptr,
-1);
} else {
char *src_addr, *dst_addr, *src_port, *dst_port;
src_addr = (char*)get_conversation_address(NULL, &conv_item->src_address, ct->resolve_names);
dst_addr = (char*)get_conversation_address(NULL, &conv_item->dst_address, ct->resolve_names);
src_port = (char*)get_conversation_port(NULL, conv_item->src_port, conv_item->ptype, ct->resolve_names);
dst_port = (char*)get_conversation_port(NULL, conv_item->dst_port, conv_item->ptype, ct->resolve_names);
gtk_list_store_insert_with_values(store, &iter, G_MAXINT,
CONV_COLUMN_SRC_ADDR, src_addr,
CONV_COLUMN_SRC_PORT, src_port,
CONV_COLUMN_DST_ADDR, dst_addr,
CONV_COLUMN_DST_PORT, dst_port,
CONV_COLUMN_PACKETS, conv_item->tx_frames+conv_item->rx_frames,
CONV_COLUMN_BYTES, conv_item->tx_bytes+conv_item->rx_bytes,
CONV_COLUMN_PKT_AB, conv_item->tx_frames,
CONV_COLUMN_BYTES_AB, conv_item->tx_bytes,
CONV_COLUMN_PKT_BA, conv_item->rx_frames,
CONV_COLUMN_BYTES_BA, conv_item->rx_bytes,
CONV_COLUMN_START, start_time,
CONV_COLUMN_DURATION, duration,
CONV_COLUMN_BPS_AB, tx_ptr,
CONV_COLUMN_BPS_BA, rx_ptr,
CONV_INDEX_COLUMN, idx,
-1);
wmem_free(NULL, src_addr);
wmem_free(NULL, dst_addr);
wmem_free(NULL, src_port);
wmem_free(NULL, dst_port);
}
iter_valid = gtk_tree_model_iter_next(GTK_TREE_MODEL(store), &iter);
}
if (!first) {
if (!ct->fixed_col && ct->hash.conv_array && ct->hash.conv_array->len >= 1000) {
ct->fixed_col = TRUE;
switch_to_fixed_col(ct->table);
}
gtk_tree_view_set_model(GTK_TREE_VIEW(ct->table), GTK_TREE_MODEL(store));
g_object_unref(store);
}
if (ct->hash.conv_array && ct->reselection_idx != -1) {
gtk_tree_selection_select_iter(gtk_tree_view_get_selection(GTK_TREE_VIEW(ct->table)),
&reselect_iter);
}
}
static void
draw_ct_table_data_cb(void *arg)
{
conv_hash_t *hash = (conv_hash_t*)arg;
draw_ct_table_data((conversations_table *)hash->user_data);
}
static gboolean
csv_handle(GtkTreeModel *model, GtkTreePath *path _U_, GtkTreeIter *iter,
gpointer data)
{
csv_t *csv = (csv_t *)data;
gchar *table_text;
int i;
guint idx;
conv_item_t *conv;
double duration_s;
guint64 value;
gtk_tree_model_get(model, iter, CONV_INDEX_COLUMN, &idx, -1);
conv=&g_array_index(csv->talkers->hash.conv_array, conv_item_t, idx);
duration_s = nstime_to_sec(&conv->stop_time) - nstime_to_sec(&conv->start_time);
for (i=0; i< csv->nb_cols; i++) {
if (i)
g_string_append(csv->CSV_str, ",");
switch(csv->columns_order[i]) {
case CONV_COLUMN_SRC_ADDR:
case CONV_COLUMN_SRC_PORT:
case CONV_COLUMN_DST_ADDR:
case CONV_COLUMN_DST_PORT:
gtk_tree_model_get(model, iter, csv->columns_order[i], &table_text, -1);
if (table_text) {
g_string_append_printf(csv->CSV_str, "\"%s\"", table_text);
g_free(table_text);
}
break;
case CONV_COLUMN_PACKETS:
case CONV_COLUMN_BYTES:
case CONV_COLUMN_PKT_AB:
case CONV_COLUMN_BYTES_AB:
case CONV_COLUMN_PKT_BA:
case CONV_COLUMN_BYTES_BA:
gtk_tree_model_get(model, iter, csv->columns_order[i], &value, -1);
g_string_append_printf(csv->CSV_str, "\"%" G_GINT64_MODIFIER "u\"", value);
break;
case CONV_COLUMN_START:
g_string_append_printf(csv->CSV_str, "\"%.9f\"", nstime_to_sec(&conv->start_time));
break;
case CONV_COLUMN_DURATION:
g_string_append_printf(csv->CSV_str, "\"%.4f\"", duration_s);
break;
case CONV_COLUMN_BPS_AB:
if (duration_s > 0 && conv->tx_frames > 1) {
g_string_append_printf(csv->CSV_str, "\"%.2f\"", (gint64) conv->tx_bytes * 8 / duration_s);
} else {
g_string_append(csv->CSV_str, "\"" NO_BPS_STR "\"");
}
break;
case CONV_COLUMN_BPS_BA:
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
csv.talkers=(conversations_table *)g_object_get_data(G_OBJECT(copy_bt), CONV_PTR_KEY);
if (!csv.talkers)
return;
csv.CSV_str = g_string_new("");
columns = gtk_tree_view_get_columns(GTK_TREE_VIEW(csv.talkers->table));
csv.nb_cols = 0;
list = columns;
while(columns) {
column = (GtkTreeViewColumn *)columns->data;
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
default_col_size[CONV_COLUMN_SRC_ADDR] = get_default_col_size(view, "00000000.000000000000");
default_col_size[CONV_COLUMN_DST_ADDR] = default_col_size[CONV_COLUMN_SRC_ADDR];
default_col_size[CONV_COLUMN_SRC_PORT] = get_default_col_size(view, "000000");
default_col_size[CONV_COLUMN_DST_PORT] = default_col_size[CONV_COLUMN_SRC_PORT];
default_col_size[CONV_COLUMN_PACKETS] = get_default_col_size(view, "00 000 000");
default_col_size[CONV_COLUMN_BYTES] = get_default_col_size(view, "0 000 000 000");
default_col_size[CONV_COLUMN_PKT_AB] = default_col_size[CONV_COLUMN_PACKETS];
default_col_size[CONV_COLUMN_PKT_BA] = default_col_size[CONV_COLUMN_PACKETS];
default_col_size[CONV_COLUMN_BYTES_AB] = default_col_size[CONV_COLUMN_BYTES];
default_col_size[CONV_COLUMN_BYTES_BA] = default_col_size[CONV_COLUMN_BYTES];
default_col_size[CONV_COLUMN_START] = get_default_col_size(view, "000000.000000000");
default_col_size[CONV_COLUMN_DURATION] = get_default_col_size(view, "000000.0000");
default_col_size[CONV_COLUMN_BPS_AB] = get_default_col_size(view, "000000000.00");
default_col_size[CONV_COLUMN_BPS_BA] = default_col_size[CONV_COLUMN_BPS_AB];
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
for (i = 0; i < CONV_NUM_COLUMNS; i++) {
conversations->default_titles[i] = conv_column_titles[i];
}
if (strcmp(table_name, "NCP")==0) {
conversations->default_titles[CONV_COLUMN_SRC_PORT] = conv_conn_a_title;
conversations->default_titles[CONV_COLUMN_DST_PORT] = conv_conn_b_title;
}
g_snprintf(title, sizeof(title), "%s Conversations", table_name);
conversations->name_lb=gtk_label_new(title);
store = gtk_list_store_new (CONV_NUM_COLUMNS + 1,
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
for (i = 0; i < CONV_NUM_COLUMNS; i++) {
renderer = gtk_cell_renderer_text_new ();
g_object_set(renderer, "ypad", 0, NULL);
switch(i) {
case CONV_COLUMN_SRC_ADDR:
case CONV_COLUMN_SRC_PORT:
case CONV_COLUMN_DST_ADDR:
case CONV_COLUMN_DST_PORT:
column = gtk_tree_view_column_new_with_attributes (conversations->default_titles[i], renderer, "text",
i, NULL);
if(hide_ports && (i == 1 || i == 3)){
gtk_tree_view_column_set_visible(column, FALSE);
}
gtk_tree_sortable_set_sort_func(sortable, i, ct_sort_func, GINT_TO_POINTER(i), NULL);
break;
case CONV_COLUMN_PACKETS:
case CONV_COLUMN_BYTES:
case CONV_COLUMN_PKT_AB:
case CONV_COLUMN_BYTES_AB:
case CONV_COLUMN_PKT_BA:
case CONV_COLUMN_BYTES_BA:
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
conversations->hash.conv_array = NULL;
conversations->hash.hashtable = NULL;
conversations->hash.user_data = conversations;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(conversations->table));
gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
ct_create_popup_menu(conversations);
error_string=register_tap_listener(tap_name, &conversations->hash, filter, 0, reset_ct_table_data_cb, packet_func,
draw_ct_table_data_cb);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
return FALSE;
}
return TRUE;
}
static void
graph_cb(GtkWidget *follow_stream_bt, gboolean reverse_direction)
{
conversations_table *ct = (conversations_table *)g_object_get_data (G_OBJECT(follow_stream_bt), CONV_PTR_KEY);
GtkTreeIter iter;
GtkTreeModel *model;
GtkTreeSelection *sel;
guint32 idx = 0;
conv_item_t *conv;
if (!ct || !ct->hash.conv_array)
return;
sel = gtk_tree_view_get_selection (GTK_TREE_VIEW(ct->table));
if (!gtk_tree_selection_get_selected(sel, &model, &iter)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "No conversation selected");
return;
}
gtk_tree_model_get (model, &iter, CONV_INDEX_COLUMN, &idx, -1);
if (idx >= ct->hash.conv_array->len) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "No conversation selected");
return;
}
conv = &g_array_index(ct->hash.conv_array, conv_item_t, idx);
if (strcmp(ct->name, "TCP") == 0) {
if (!reverse_direction) {
tcp_graph_known_stream_launch(&conv->src_address, conv->src_port,
&conv->dst_address, conv->dst_port,
conv->conv_id);
}
else {
tcp_graph_known_stream_launch(&conv->dst_address, conv->dst_port,
&conv->src_address, conv->src_port,
conv->conv_id);
}
}
else {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Unknown stream: %s", ct->name);
}
ct->reselection_idx = idx;
}
static void
follow_stream_cb(GtkWidget *follow_stream_bt, gpointer data _U_)
{
conversations_table *ct = (conversations_table *)g_object_get_data (G_OBJECT(follow_stream_bt), CONV_PTR_KEY);
GtkTreeIter iter;
GtkTreeModel *model;
GtkTreeSelection *sel;
guint32 idx = 0;
gchar *filter = NULL;
conv_item_t *conv;
if (!ct || !ct->hash.conv_array)
return;
sel = gtk_tree_view_get_selection (GTK_TREE_VIEW(ct->table));
if (!gtk_tree_selection_get_selected(sel, &model, &iter)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "No conversation selected");
return;
}
gtk_tree_model_get (model, &iter, CONV_INDEX_COLUMN, &idx, -1);
if (idx >= ct->hash.conv_array->len) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "No conversation selected");
return;
}
conv = &g_array_index(ct->hash.conv_array, conv_item_t, idx);
switch (conv->ptype) {
case PT_TCP:
filter = g_strdup_printf("tcp.stream eq %d", conv->conv_id);
break;
case PT_UDP:
filter = g_strdup_printf("udp.stream eq %d", conv->conv_id);
break;
default:
filter = g_strdup("INVALID");
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
ct->reselection_idx = idx;
}
void
init_conversation_table(struct register_ct* ct, const char *filter)
{
conversations_table *conversations;
char *display_name;
char title[256];
const char *table_name = proto_get_protocol_short_name(find_protocol_by_id(get_conversation_proto_id(ct)));
GtkWidget *vbox;
GtkWidget *bbox;
GtkWidget *close_bt, *help_bt;
gboolean ret;
GtkWidget *copy_bt, *follow_stream_bt;
GtkWidget *graph_a_b_bt;
GtkWidget *graph_b_a_bt;
gboolean add_follow_stream_button = FALSE;
gboolean add_graph_buttons = FALSE;
window_geometry_t tl_geom;
conversations=g_new0(conversations_table,1);
conversations->name=table_name;
conversations->filter=filter;
conversations->use_dfilter=FALSE;
display_name = cf_get_display_name(&cfile);
g_snprintf(title, sizeof(title), "%s Conversations: %s", table_name, display_name);
g_free(display_name);
conversations->win = dlg_window_new(title);
gtk_window_set_destroy_with_parent (GTK_WINDOW(conversations->win), TRUE);
window_get_geometry(top_level, &tl_geom);
gtk_window_set_default_size(GTK_WINDOW(conversations->win), tl_geom.width * 8 / 10, CONV_DLG_HEIGHT);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, DLG_LABEL_SPACING, FALSE);
gtk_container_add(GTK_CONTAINER(conversations->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), DLG_OUTER_MARGIN);
ret = init_ct_table_page(conversations, vbox,
get_conversation_hide_ports(ct),
table_name, proto_get_protocol_filter_name(get_conversation_proto_id(ct)),
filter, get_conversation_packet_func(ct));
if(ret == FALSE) {
g_free(conversations);
return;
}
if (strcmp(table_name, "TCP") == 0) {
add_graph_buttons = TRUE;
add_follow_stream_button = TRUE;
bbox = dlg_button_row_new(
GTK_STOCK_CLOSE,
GTK_STOCK_COPY,
WIRESHARK_STOCK_FOLLOW_STREAM,
WIRESHARK_STOCK_GRAPH_A_B,
WIRESHARK_STOCK_GRAPH_B_A,
GTK_STOCK_HELP, NULL);
}
else if (strcmp(table_name, "UDP") == 0) {
add_follow_stream_button = TRUE;
bbox = dlg_button_row_new(
GTK_STOCK_CLOSE,
GTK_STOCK_COPY,
WIRESHARK_STOCK_FOLLOW_STREAM,
GTK_STOCK_HELP, NULL);
}
else {
bbox = dlg_button_row_new(
GTK_STOCK_CLOSE,
GTK_STOCK_COPY,
GTK_STOCK_HELP, NULL);
}
gtk_box_pack_end(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(conversations->win, close_bt, window_cancel_button_cb);
copy_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_COPY);
gtk_widget_set_tooltip_text(copy_bt, "Copy all statistical values of this page to the clipboard in CSV (Comma Separated Values) format.");
g_object_set_data(G_OBJECT(copy_bt), CONV_PTR_KEY, conversations);
g_signal_connect(copy_bt, "clicked", G_CALLBACK(copy_as_csv_cb), NULL);
if (add_follow_stream_button) {
follow_stream_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_FOLLOW_STREAM);
g_object_set_data(G_OBJECT(follow_stream_bt), E_DFILTER_TE_KEY, main_display_filter_widget);
g_object_set_data(G_OBJECT(follow_stream_bt), CONV_PTR_KEY, conversations);
g_signal_connect(follow_stream_bt, "clicked", G_CALLBACK(follow_stream_cb), NULL);
}
if (add_graph_buttons) {
graph_a_b_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_GRAPH_A_B);
gtk_widget_set_tooltip_text(graph_a_b_bt, "Graph traffic from address A to address B.");
g_object_set_data(G_OBJECT(graph_a_b_bt), E_DFILTER_TE_KEY, main_display_filter_widget);
g_object_set_data(G_OBJECT(graph_a_b_bt), CONV_PTR_KEY, conversations);
g_signal_connect(graph_a_b_bt, "clicked", G_CALLBACK(graph_cb), (gpointer)FALSE);
graph_b_a_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_GRAPH_B_A);
gtk_widget_set_tooltip_text(graph_b_a_bt, "Graph traffic from address B to address A.");
g_object_set_data(G_OBJECT(graph_b_a_bt), E_DFILTER_TE_KEY, main_display_filter_widget);
g_object_set_data(G_OBJECT(graph_b_a_bt), CONV_PTR_KEY, conversations);
g_signal_connect(graph_b_a_bt, "clicked", G_CALLBACK(graph_cb), (gpointer)TRUE);
}
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_STATS_CONVERSATIONS_DIALOG);
g_signal_connect(conversations->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(conversations->win, "destroy", G_CALLBACK(ct_win_destroy_cb), conversations);
conversations->reselection_idx = -1;
gtk_widget_show_all(conversations->win);
window_present(conversations->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(conversations->win));
}
static void
ct_nb_switch_page_cb(GtkNotebook *nb, gpointer *pg _U_, guint page, gpointer data)
{
GtkWidget *copy_bt = (GtkWidget *) data;
GtkWidget *graph_a_b_bt = (GtkWidget *)g_object_get_data(G_OBJECT(nb), GRAPH_A_B_BT_KEY);
GtkWidget *graph_b_a_bt = (GtkWidget *)g_object_get_data(G_OBJECT(nb), GRAPH_B_A_BT_KEY);
GtkWidget *follow_stream_bt = (GtkWidget *)g_object_get_data(G_OBJECT(nb), FOLLOW_STREAM_BT_KEY);
void **pages = (void**)g_object_get_data(G_OBJECT(nb), NB_PAGES_KEY);
page++;
if (pages && (page > 0) && ((int) page <= GPOINTER_TO_INT(pages[0]))) {
g_object_set_data(G_OBJECT(copy_bt), CONV_PTR_KEY, pages[page]);
g_object_set_data(G_OBJECT(follow_stream_bt), CONV_PTR_KEY, pages[page]);
g_object_set_data(G_OBJECT(graph_a_b_bt), CONV_PTR_KEY, pages[page]);
g_object_set_data(G_OBJECT(graph_b_a_bt), CONV_PTR_KEY, pages[page]);
if (strcmp(((conversations_table *)pages[page])->name, "TCP") == 0) {
gtk_widget_set_tooltip_text(follow_stream_bt, "Follow TCP Stream.");
gtk_widget_set_sensitive(follow_stream_bt, TRUE);
gtk_widget_set_tooltip_text(follow_stream_bt, "Graph traffic from address A to address B.");
gtk_widget_set_sensitive(graph_a_b_bt, TRUE);
gtk_widget_set_sensitive(graph_b_a_bt, TRUE);
} else if (strcmp(((conversations_table *)pages[page])->name, "UDP") == 0) {
gtk_widget_set_tooltip_text(follow_stream_bt, "Follow UDP Stream.");
gtk_widget_set_sensitive(graph_a_b_bt, FALSE);
gtk_widget_set_sensitive(graph_b_a_bt, FALSE);
gtk_widget_set_sensitive(follow_stream_bt, TRUE);
} else {
gtk_widget_set_tooltip_text(follow_stream_bt, "Follow TCP or UDP Stream.");
gtk_widget_set_sensitive(graph_a_b_bt, FALSE);
gtk_widget_set_sensitive(graph_b_a_bt, FALSE);
gtk_widget_set_sensitive(follow_stream_bt, FALSE);
}
}
}
static void
ct_win_destroy_notebook_cb(GtkWindow *win _U_, gpointer data)
{
void ** pages = (void **)data;
int page;
for (page=1; page<=GPOINTER_TO_INT(pages[0]); page++) {
ct_win_destroy_cb(NULL, pages[page]);
}
g_free(pages);
}
static conversations_table *
init_ct_notebook_page_cb(register_ct_t *table, const char *filter)
{
gboolean ret;
GtkWidget *page_vbox;
conversations_table *conversations;
conversations=g_new0(conversations_table,1);
conversations->name=proto_get_protocol_short_name(find_protocol_by_id(get_conversation_proto_id(table)));
conversations->filter=filter;
conversations->resolve_names=TRUE;
conversations->use_dfilter=FALSE;
page_vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
conversations->win = page_vbox;
gtk_container_set_border_width(GTK_CONTAINER(page_vbox), 6);
ret = init_ct_table_page(conversations, page_vbox, get_conversation_hide_ports(table), conversations->name,
proto_get_protocol_filter_name(get_conversation_proto_id(table)), filter, get_conversation_packet_func(table));
if(ret == FALSE) {
g_free(conversations);
return NULL;
}
return conversations;
}
static void
ct_resolve_toggle_dest(GtkWidget *widget, gpointer data)
{
int page;
void ** pages = (void **)data;
gboolean resolve_names;
conversations_table *conversations;
resolve_names = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget));
for (page=1; page<=GPOINTER_TO_INT(pages[0]); page++) {
conversations = (conversations_table *)pages[page];
conversations->resolve_names = resolve_names;
draw_ct_table_addresses(conversations);
}
}
static void
ct_filter_toggle_dest(GtkWidget *widget, gpointer data)
{
int page;
void ** pages = (void **)data;
gboolean use_filter;
conversations_table *conversations = NULL;
use_filter = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget));
for (page=1; page<=GPOINTER_TO_INT(pages[0]); page++) {
conversations = (conversations_table *)pages[page];
conversations->use_dfilter = use_filter;
reset_ct_table_data(conversations);
}
cf_retap_packets(&cfile);
if (conversations) {
gdk_window_raise(gtk_widget_get_window(conversations->win));
}
}
static void
init_ct_page(gpointer data, gpointer user_data)
{
register_ct_t *table = (register_ct_t*)data;
init_ct_page_data* ct_page_data = (init_ct_page_data*)user_data;
conversations_table *conversations;
GtkWidget *page_lb;
conversations = init_ct_notebook_page_cb(table, NULL );
if (conversations) {
g_object_set_data(G_OBJECT(conversations->win), CONV_PTR_KEY, conversations);
page_lb = gtk_label_new("");
gtk_notebook_append_page(GTK_NOTEBOOK(ct_page_data->nb), conversations->win, page_lb);
conversations->win = ct_page_data->win;
conversations->page_lb = page_lb;
ct_page_data->pages[++ct_page_data->page] = conversations;
}
}
void
init_conversation_notebook_cb(GtkWidget *w _U_, gpointer d _U_)
{
char *display_name;
char title[256];
GtkWidget *vbox;
GtkWidget *hbox;
GtkWidget *bbox;
GtkWidget *close_bt, *help_bt;
GtkWidget *win;
GtkWidget *resolv_cb;
GtkWidget *filter_cb;
void ** pages;
GtkWidget *nb;
GtkWidget *copy_bt;
GtkWidget *follow_stream_bt;
GtkWidget *graph_a_b_bt;
GtkWidget *graph_b_a_bt;
window_geometry_t tl_geom;
init_ct_page_data ct_page_iter_data;
pages = (void **)g_malloc(sizeof(void *) * (conversation_table_get_num() + 1));
display_name = cf_get_display_name(&cfile);
g_snprintf(title, sizeof(title), "Conversations: %s", display_name);
g_free(display_name);
win = dlg_window_new(title);
gtk_window_set_destroy_with_parent (GTK_WINDOW(win), TRUE);
window_get_geometry(top_level, &tl_geom);
gtk_window_set_default_size(GTK_WINDOW(win), tl_geom.width * 8 / 10, CONV_DLG_HEIGHT);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, DLG_LABEL_SPACING, FALSE);
gtk_container_add(GTK_CONTAINER(win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), DLG_OUTER_MARGIN);
nb = gtk_notebook_new();
gtk_box_pack_start(GTK_BOX (vbox), nb, TRUE, TRUE, 0);
g_object_set_data(G_OBJECT(nb), NB_PAGES_KEY, pages);
ct_page_iter_data.page = 0;
ct_page_iter_data.pages = pages;
ct_page_iter_data.nb = nb;
ct_page_iter_data.win = win;
conversation_table_iterate_tables(init_ct_page, &ct_page_iter_data);
pages[0] = GINT_TO_POINTER(ct_page_iter_data.page);
hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, DLG_UNRELATED_SPACING, FALSE);
gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);
resolv_cb = gtk_check_button_new_with_mnemonic("Name resolution");
gtk_box_pack_start(GTK_BOX (hbox), resolv_cb, FALSE, FALSE, 0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(resolv_cb), TRUE);
gtk_widget_set_tooltip_text(resolv_cb, "Show results of name resolutions rather than the \"raw\" values. "
"Please note: The corresponding name resolution must be enabled.");
g_signal_connect(resolv_cb, "toggled", G_CALLBACK(ct_resolve_toggle_dest), pages);
filter_cb = gtk_check_button_new_with_mnemonic("Limit to display filter");
gtk_box_pack_start(GTK_BOX (hbox), filter_cb, FALSE, FALSE, 0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(filter_cb), FALSE);
gtk_widget_set_tooltip_text(filter_cb, "Limit the list to conversations matching the current display filter.");
g_signal_connect(filter_cb, "toggled", G_CALLBACK(ct_filter_toggle_dest), pages);
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, GTK_STOCK_COPY,
WIRESHARK_STOCK_FOLLOW_STREAM,
WIRESHARK_STOCK_GRAPH_A_B,
WIRESHARK_STOCK_GRAPH_B_A,
GTK_STOCK_HELP, NULL);
gtk_box_pack_end(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(win, close_bt, window_cancel_button_cb);
copy_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_COPY);
gtk_widget_set_tooltip_text(copy_bt, "Copy all statistical values of this page to the clipboard in CSV (Comma Separated Values) format.");
g_signal_connect(copy_bt, "clicked", G_CALLBACK(copy_as_csv_cb), NULL);
g_object_set_data(G_OBJECT(copy_bt), CONV_PTR_KEY, pages[ct_page_iter_data.page]);
graph_a_b_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_GRAPH_A_B);
gtk_widget_set_tooltip_text(graph_a_b_bt, "Graph traffic from address A to address B.");
g_object_set_data(G_OBJECT(graph_a_b_bt), E_DFILTER_TE_KEY, main_display_filter_widget);
g_object_set_data(G_OBJECT(graph_a_b_bt), CONV_PTR_KEY, pages[ct_page_iter_data.page]);
g_signal_connect(graph_a_b_bt, "clicked", G_CALLBACK(graph_cb), (gpointer)FALSE);
g_object_set_data(G_OBJECT(nb), GRAPH_A_B_BT_KEY, graph_a_b_bt);
graph_b_a_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_GRAPH_B_A);
gtk_widget_set_tooltip_text(graph_b_a_bt, "Graph traffic from address B to address A.");
g_object_set_data(G_OBJECT(graph_b_a_bt), E_DFILTER_TE_KEY, main_display_filter_widget);
g_object_set_data(G_OBJECT(graph_b_a_bt), CONV_PTR_KEY, pages[ct_page_iter_data.page]);
g_signal_connect(graph_b_a_bt, "clicked", G_CALLBACK(graph_cb), (gpointer)TRUE);
g_object_set_data(G_OBJECT(nb), GRAPH_B_A_BT_KEY, graph_b_a_bt);
follow_stream_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_FOLLOW_STREAM);
gtk_widget_set_tooltip_text(follow_stream_bt, "Follow Stream.");
g_object_set_data(G_OBJECT(follow_stream_bt), E_DFILTER_TE_KEY, main_display_filter_widget);
g_object_set_data(G_OBJECT(follow_stream_bt), CONV_PTR_KEY, pages[ct_page_iter_data.page]);
g_signal_connect(follow_stream_bt, "clicked", G_CALLBACK(follow_stream_cb), NULL);
g_object_set_data(G_OBJECT(nb), FOLLOW_STREAM_BT_KEY, follow_stream_bt);
g_signal_connect(nb, "switch-page", G_CALLBACK(ct_nb_switch_page_cb), copy_bt);
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_STATS_CONVERSATIONS_DIALOG);
g_signal_connect(win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(win, "destroy", G_CALLBACK(ct_win_destroy_notebook_cb), pages);
gtk_widget_show_all(win);
window_present(win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(win));
}
void conversation_endpoint_cb(register_ct_t* table)
{
char cmd_str[50];
g_snprintf(cmd_str, 50, "conv,%s", proto_get_protocol_filter_name(get_conversation_proto_id(table)));
dissector_conversation_init(cmd_str, table);
}
