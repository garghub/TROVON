GType
packet_list_get_type(void)
{
static GType packet_list_type = 0;
if(packet_list_type == 0) {
static const GTypeInfo packet_list_info = {
sizeof(PacketListClass),
NULL,
NULL,
(GClassInitFunc) packet_list_class_init,
NULL,
NULL,
sizeof(PacketList),
0,
(GInstanceInitFunc) packet_list_init,
NULL
};
static const GInterfaceInfo tree_model_info = {
(GInterfaceInitFunc) packet_list_tree_model_init,
NULL,
NULL
};
static const GInterfaceInfo tree_sortable_info = {
(GInterfaceInitFunc) packet_list_sortable_init,
NULL,
NULL
};
packet_list_type = g_type_register_static(G_TYPE_OBJECT,
"PacketList",
&packet_list_info,
(GTypeFlags)0);
g_type_add_interface_static(packet_list_type,
GTK_TYPE_TREE_MODEL,
&tree_model_info);
g_type_add_interface_static(packet_list_type,
GTK_TYPE_TREE_SORTABLE,
&tree_sortable_info);
}
return packet_list_type;
}
static void
packet_list_sortable_init(GtkTreeSortableIface *iface)
{
iface->get_sort_column_id = packet_list_sortable_get_sort_column_id;
iface->set_sort_column_id = packet_list_sortable_set_sort_column_id;
iface->set_sort_func = packet_list_sortable_set_sort_func;
iface->set_default_sort_func =
packet_list_sortable_set_default_sort_func;
iface->has_default_sort_func =
packet_list_sortable_has_default_sort_func;
}
static void
packet_list_class_init(PacketListClass *klass)
{
GObjectClass *object_class;
parent_class = (GObjectClass*) g_type_class_peek_parent(klass);
object_class = (GObjectClass*) klass;
object_class->finalize = packet_list_finalize;
#if !GTK_CHECK_VERSION(3,0,0)
gtk_rc_parse_string (
"style \"PacketList-style\"\n"
"{\n"
" GtkTreeView::horizontal-separator = 0\n"
" GtkTreeView::vertical-separator = 1\n"
"} widget_class \"*TreeView*\""
" style \"PacketList-style\"");
#endif
}
static void
packet_list_tree_model_init(GtkTreeModelIface *iface)
{
iface->get_flags = packet_list_get_flags;
iface->get_n_columns = packet_list_get_n_columns;
iface->get_column_type = packet_list_get_column_type;
iface->get_iter = packet_list_get_iter;
iface->get_path = packet_list_get_path;
iface->get_value = packet_list_get_value;
iface->iter_next = packet_list_iter_next;
iface->iter_children = packet_list_iter_children;
iface->iter_has_child = packet_list_iter_has_child;
iface->iter_n_children = packet_list_iter_n_children;
iface->iter_nth_child = packet_list_iter_nth_child;
iface->iter_parent = packet_list_iter_parent;
}
static void
packet_list_init(PacketList *packet_list)
{
guint i;
for(i = 0; i < (guint)cfile.cinfo.num_cols; i++) {
packet_list->column_types[i] = G_TYPE_STRING;
}
packet_list->stamp = g_random_int();
packet_list->column_types[i] = G_TYPE_POINTER;
packet_list->n_columns = (guint)cfile.cinfo.num_cols+1;
packet_list->physical_rows = g_ptr_array_new();
packet_list->visible_rows = g_ptr_array_new();
packet_list->columnized = FALSE;
packet_list->sort_id = 0;
packet_list->sort_order = GTK_SORT_ASCENDING;
#ifdef NEW_PACKET_LIST_STATISTICS
packet_list->const_strings = 0;
#endif
}
static void
packet_list_finalize(GObject *object)
{
(* parent_class->finalize) (object);
}
static GtkTreeModelFlags
packet_list_get_flags(GtkTreeModel *tree_model)
{
g_return_val_if_fail(PACKETLIST_IS_LIST(tree_model),
(GtkTreeModelFlags)0);
return (GTK_TREE_MODEL_LIST_ONLY | GTK_TREE_MODEL_ITERS_PERSIST);
}
static gint
packet_list_get_n_columns(GtkTreeModel *tree_model)
{
g_return_val_if_fail(PACKETLIST_IS_LIST(tree_model), 0);
return PACKET_LIST(tree_model)->n_columns;
}
static GType
packet_list_get_column_type(GtkTreeModel *tree_model, gint idx)
{
PacketList *packet_list;
g_return_val_if_fail(PACKETLIST_IS_LIST(tree_model), G_TYPE_INVALID);
packet_list = PACKET_LIST(tree_model);
g_return_val_if_fail(idx < packet_list->n_columns &&
idx >= 0, G_TYPE_INVALID);
return packet_list->column_types[idx];
}
static gboolean
packet_list_get_iter(GtkTreeModel *tree_model, GtkTreeIter *iter,
GtkTreePath *path)
{
PacketList *packet_list;
PacketListRecord *record;
gint *indices, depth;
gint n;
g_assert(PACKETLIST_IS_LIST(tree_model));
g_assert(path != NULL);
indices = gtk_tree_path_get_indices(path);
depth = gtk_tree_path_get_depth(path);
g_assert(depth == 1);
n = indices[0];
packet_list = PACKET_LIST(tree_model);
if(PACKET_LIST_RECORD_COUNT(packet_list->visible_rows) == 0)
return FALSE;
if(!PACKET_LIST_RECORD_INDEX_VALID(packet_list->visible_rows, n))
return FALSE;
record = PACKET_LIST_RECORD_GET(packet_list->visible_rows, n);
g_assert(record->visible_pos == n);
iter->stamp = packet_list->stamp;
iter->user_data = record;
iter->user_data2 = NULL;
iter->user_data3 = NULL;
return TRUE;
}
static GtkTreePath *
packet_list_get_path(GtkTreeModel *tree_model, GtkTreeIter *iter)
{
GtkTreePath *path;
PacketListRecord *record;
g_return_val_if_fail(PACKETLIST_IS_LIST(tree_model), NULL);
g_return_val_if_fail(iter != NULL, NULL);
g_return_val_if_fail(iter->user_data != NULL, NULL);
record = (PacketListRecord*) iter->user_data;
path = gtk_tree_path_new();
gtk_tree_path_append_index(path, record->visible_pos);
return path;
}
static void
packet_list_get_value(GtkTreeModel *tree_model, GtkTreeIter *iter, gint column,
GValue *value)
{
PacketListRecord *record;
PacketList *packet_list;
GType type;
g_return_if_fail(PACKETLIST_IS_LIST(tree_model));
g_return_if_fail(iter != NULL);
packet_list = PACKET_LIST(tree_model);
g_return_if_fail(column < packet_list->n_columns);
record = (PacketListRecord*) iter->user_data;
g_return_if_fail(PACKET_LIST_RECORD_INDEX_VALID(packet_list->physical_rows, record->physical_pos));
g_return_if_fail(PACKET_LIST_RECORD_INDEX_VALID(packet_list->visible_rows, record->visible_pos));
type = packet_list->column_types[column];
g_value_init(value, type);
switch(type){
case G_TYPE_POINTER:
g_value_set_pointer(value, record);
break;
case G_TYPE_STRING:
g_return_if_fail(record->col_text);
g_value_set_string(value, record->col_text[column]);
break;
default:
g_warning (G_STRLOC ": Unsupported type (%s) retrieved.", g_type_name (value->g_type));
break;
}
}
static PacketListRecord *
packet_list_iter_next_visible(PacketList *packet_list, PacketListRecord *record)
{
PacketListRecord *nextrecord;
gint next_visible_pos;
g_assert(record->visible_pos >= 0);
next_visible_pos = record->visible_pos + 1;
if(!PACKET_LIST_RECORD_INDEX_VALID(packet_list->visible_rows, next_visible_pos))
return NULL;
nextrecord = PACKET_LIST_RECORD_GET(packet_list->visible_rows, next_visible_pos);
g_assert(nextrecord->visible_pos == (record->visible_pos + 1));
g_assert(nextrecord->physical_pos >= (record->physical_pos + 1));
return nextrecord;
}
static gboolean
packet_list_iter_next(GtkTreeModel *tree_model, GtkTreeIter *iter)
{
PacketListRecord *record, *nextrecord;
PacketList *packet_list;
g_return_val_if_fail(PACKETLIST_IS_LIST(tree_model), FALSE);
if(iter == NULL)
return FALSE;
g_return_val_if_fail(iter->user_data, FALSE);
packet_list = PACKET_LIST(tree_model);
record = (PacketListRecord*) iter->user_data;
nextrecord = packet_list_iter_next_visible(packet_list, record);
if (!nextrecord)
return FALSE;
iter->stamp = packet_list->stamp;
iter->user_data = nextrecord;
return TRUE;
}
static gboolean
packet_list_iter_children(GtkTreeModel *tree_model, GtkTreeIter *iter,
GtkTreeIter *parent)
{
PacketList *packet_list;
g_return_val_if_fail(parent == NULL || parent->user_data != NULL, FALSE);
if(parent)
return FALSE;
g_return_val_if_fail(PACKETLIST_IS_LIST(tree_model), FALSE);
packet_list = PACKET_LIST(tree_model);
if(PACKET_LIST_RECORD_COUNT(packet_list->visible_rows) == 0)
return FALSE;
iter->stamp = packet_list->stamp;
iter->user_data = PACKET_LIST_RECORD_GET(packet_list->visible_rows, 0);
return TRUE;
}
static gboolean
packet_list_iter_has_child(GtkTreeModel *tree_model _U_, GtkTreeIter *iter _U_)
{
return FALSE;
}
static gint
packet_list_iter_n_children(GtkTreeModel *tree_model, GtkTreeIter *iter)
{
PacketList *packet_list;
g_return_val_if_fail(PACKETLIST_IS_LIST(tree_model), 0);
g_return_val_if_fail(iter == NULL || iter->user_data != NULL, 0);
packet_list = PACKET_LIST(tree_model);
if(!iter) {
return PACKET_LIST_RECORD_COUNT(packet_list->visible_rows);
}
else {
return 0;
}
}
static gboolean
packet_list_iter_nth_child(GtkTreeModel *tree_model, GtkTreeIter *iter,
GtkTreeIter *parent, gint n)
{
PacketListRecord *record;
PacketList *packet_list;
g_return_val_if_fail(PACKETLIST_IS_LIST(tree_model), FALSE);
packet_list = PACKET_LIST(tree_model);
if(parent)
return FALSE;
if(!PACKET_LIST_RECORD_INDEX_VALID(packet_list->visible_rows, n))
return FALSE;
record = PACKET_LIST_RECORD_GET(packet_list->visible_rows, n);
g_assert(record->visible_pos == n);
iter->stamp = packet_list->stamp;
iter->user_data = record;
return TRUE;
}
static gboolean
packet_list_iter_parent(GtkTreeModel *tree_model _U_, GtkTreeIter *iter _U_,
GtkTreeIter *child _U_)
{
return FALSE;
}
PacketList *
new_packet_list_new(void)
{
PacketList *newpacketlist;
newpacketlist = (PacketList*) g_object_new(PACKETLIST_TYPE_LIST, NULL);
g_assert(newpacketlist != NULL);
return newpacketlist;
}
void
new_packet_list_store_clear(PacketList *packet_list)
{
g_return_if_fail(packet_list != NULL);
g_return_if_fail(PACKETLIST_IS_LIST(packet_list));
if(packet_list->physical_rows)
g_ptr_array_free(packet_list->physical_rows, TRUE);
if(packet_list->visible_rows)
g_ptr_array_free(packet_list->visible_rows, TRUE);
packet_list->physical_rows = g_ptr_array_new();
packet_list->visible_rows = g_ptr_array_new();
packet_list->columnized = FALSE;
#ifdef NEW_PACKET_LIST_STATISTICS
g_warning("Const strings: %u", packet_list->const_strings);
packet_list->const_strings = 0;
#endif
}
static void
packet_list_row_inserted(PacketList *packet_list, guint pos)
{
GtkTreeIter iter;
GtkTreePath *path;
path = gtk_tree_path_new();
gtk_tree_path_append_index(path, pos);
packet_list_get_iter(GTK_TREE_MODEL(packet_list), &iter, path);
gtk_tree_model_row_inserted(GTK_TREE_MODEL(packet_list), path, &iter);
gtk_tree_path_free(path);
}
gboolean
packet_list_visible_record(PacketList *packet_list, GtkTreeIter *iter)
{
PacketListRecord *record;
g_return_val_if_fail(PACKETLIST_IS_LIST(packet_list), FALSE);
if(iter == NULL || iter->user_data == NULL)
return FALSE;
record = (PacketListRecord*) iter->user_data;
g_return_val_if_fail(record, FALSE);
g_return_val_if_fail(record->fdata, FALSE);
return (record->fdata->flags.passed_dfilter || record->fdata->flags.ref_time);
}
gint
packet_list_append_record(PacketList *packet_list, frame_data *fdata)
{
PacketListRecord *newrecord;
GtkTreeModel *model = GTK_TREE_MODEL(packet_list);
g_return_val_if_fail(PACKETLIST_IS_LIST(packet_list), -1);
newrecord = se_alloc(sizeof(PacketListRecord));
newrecord->columnized = FALSE;
newrecord->colorized = FALSE;
newrecord->col_text_len = se_alloc0(sizeof(*newrecord->col_text_len) * cfile.cinfo.num_cols);
newrecord->col_text = se_alloc0(sizeof(*newrecord->col_text) * cfile.cinfo.num_cols);
newrecord->fdata = fdata;
newrecord->physical_pos = PACKET_LIST_RECORD_COUNT(packet_list->physical_rows);
if (fdata->flags.passed_dfilter || fdata->flags.ref_time) {
newrecord->visible_pos = PACKET_LIST_RECORD_COUNT(packet_list->visible_rows);
PACKET_LIST_RECORD_APPEND(packet_list->visible_rows, newrecord);
}
else
newrecord->visible_pos = -1;
PACKET_LIST_RECORD_APPEND(packet_list->physical_rows, newrecord);
packet_list->columnized = FALSE;
if((model)&&(newrecord->visible_pos!=-1))
packet_list_row_inserted(packet_list, newrecord->visible_pos);
return newrecord->visible_pos;
}
void
packet_list_change_record(PacketList *packet_list, guint row, gint col, column_info *cinfo)
{
PacketListRecord *record;
gchar *str;
g_return_if_fail(packet_list);
g_return_if_fail(PACKETLIST_IS_LIST(packet_list));
g_assert(row < PACKET_LIST_RECORD_COUNT(packet_list->physical_rows));
record = PACKET_LIST_RECORD_GET(packet_list->physical_rows, row);
g_assert(record->physical_pos == row);
g_assert((record->col_text != NULL)&&(record->col_text_len != NULL));
if (record->col_text[col] != NULL)
return;
switch (cfile.cinfo.col_fmt[col]) {
case COL_DEF_SRC:
case COL_RES_SRC:
case COL_UNRES_SRC:
case COL_DEF_DL_SRC:
case COL_RES_DL_SRC:
case COL_UNRES_DL_SRC:
case COL_DEF_NET_SRC:
case COL_RES_NET_SRC:
case COL_UNRES_NET_SRC:
case COL_DEF_DST:
case COL_RES_DST:
case COL_UNRES_DST:
case COL_DEF_DL_DST:
case COL_RES_DL_DST:
case COL_UNRES_DL_DST:
case COL_DEF_NET_DST:
case COL_RES_NET_DST:
case COL_UNRES_NET_DST:
case COL_PROTOCOL:
case COL_INFO:
case COL_IF_DIR:
case COL_DCE_CALL:
case COL_8021Q_VLAN_ID:
case COL_EXPERT:
case COL_FREQ_CHAN:
if (cinfo->col_data[col] && cinfo->col_data[col] != cinfo->col_buf[col]) {
record->col_text[col] = (gchar *) cinfo->col_data[col];
record->col_text_len[col] = (guint) strlen(record->col_text[col]);
#ifdef NEW_PACKET_LIST_STATISTICS
++packet_list->const_strings;
#endif
break;
}
default:
record->col_text_len[col] = (guint) strlen(cinfo->col_data[col]);
if (!record->col_text_len[col]) {
record->col_text[col] = "";
#ifdef NEW_PACKET_LIST_STATISTICS
++packet_list->const_strings;
#endif
break;
}
if(!packet_list->string_pool)
packet_list->string_pool = g_string_chunk_new(32);
if (!get_column_resolved (col) && cinfo->col_expr.col_expr_val[col]) {
str = g_string_chunk_insert_const (packet_list->string_pool, (const gchar *)cinfo->col_expr.col_expr_val[col]);
} else {
str = g_string_chunk_insert_const (packet_list->string_pool, (const gchar *)cinfo->col_data[col]);
}
record->col_text[col] = str;
break;
}
}
static gboolean
packet_list_sortable_get_sort_column_id(GtkTreeSortable *sortable,
gint *sort_col_id,
GtkSortType *order)
{
PacketList *packet_list;
g_return_val_if_fail(sortable != NULL, FALSE);
g_return_val_if_fail(PACKETLIST_IS_LIST(sortable), FALSE);
packet_list = PACKET_LIST(sortable);
if(sort_col_id)
*sort_col_id = packet_list->sort_id;
if(order)
*order = packet_list->sort_order;
return TRUE;
}
static gboolean
packet_list_column_contains_values(PacketList *packet_list, gint sort_col_id)
{
if (packet_list->columnized || col_based_on_frame_data(&cfile.cinfo, sort_col_id))
return TRUE;
else
return FALSE;
}
static gboolean
packet_list_dissect_and_cache_all(PacketList *packet_list)
{
PacketListRecord *record;
int progbar_nextstep;
int progbar_quantum;
gboolean progbar_stop_flag;
GTimeVal progbar_start_time;
float progbar_val;
progdlg_t *progbar = NULL;
gchar progbar_status_str[100];
gint progbar_loop_max;
gint progbar_loop_var;
gint progbar_updates = 100 ;
g_assert(packet_list->columnized == FALSE);
progbar_loop_max = PACKET_LIST_RECORD_COUNT(packet_list->physical_rows);
progbar_nextstep = 0;
progbar_quantum = progbar_loop_max/progbar_updates;
progbar_val = 0.0f;
progbar_stop_flag = FALSE;
g_get_current_time(&progbar_start_time);
main_window_update();
for (progbar_loop_var = 0; progbar_loop_var < progbar_loop_max; ++progbar_loop_var) {
record = PACKET_LIST_RECORD_GET(packet_list->physical_rows, progbar_loop_var);
packet_list_dissect_and_cache_record(packet_list, record, TRUE, FALSE);
if (progbar == NULL)
progbar = delayed_create_progress_dlg("Construct", "Columns",
TRUE, &progbar_stop_flag,
&progbar_start_time, progbar_val);
if (progbar_loop_var >= progbar_nextstep) {
g_assert(progbar_loop_max > 0);
progbar_val = (gfloat) progbar_loop_var / progbar_loop_max;
if (progbar != NULL) {
g_snprintf(progbar_status_str, sizeof(progbar_status_str),
"%u of %u frames", progbar_loop_var+1, progbar_loop_max);
update_progress_dlg(progbar, progbar_val, progbar_status_str);
}
progbar_nextstep += progbar_quantum;
}
if (progbar_stop_flag) {
break;
}
}
if (progbar != NULL)
destroy_progress_dlg(progbar);
if (progbar_stop_flag) {
return FALSE;
}
packet_list->columnized = TRUE;
return TRUE;
}
gboolean
packet_list_do_packet_list_dissect_and_cache_all(PacketList *packet_list, gint sort_col_id)
{
if (!packet_list_column_contains_values(packet_list, sort_col_id)) {
return packet_list_dissect_and_cache_all(packet_list);
}
return TRUE;
}
static void
packet_list_sortable_set_sort_column_id(GtkTreeSortable *sortable,
gint sort_col_id,
GtkSortType order)
{
PacketList *packet_list;
g_return_if_fail(sortable != NULL);
g_return_if_fail(PACKETLIST_IS_LIST(sortable));
packet_list = PACKET_LIST(sortable);
if(packet_list->sort_id == sort_col_id &&
packet_list->sort_order == order)
return;
packet_list->sort_id = sort_col_id;
packet_list->sort_order = order;
if(PACKET_LIST_RECORD_COUNT(packet_list->physical_rows) == 0)
return;
packet_list_resort(packet_list);
gtk_tree_sortable_sort_column_changed(sortable);
}
static void
packet_list_sortable_set_sort_func(GtkTreeSortable *sortable _U_,
gint sort_col_id _U_,
GtkTreeIterCompareFunc sort_func _U_,
gpointer user_data _U_,
GDestroyNotify destroy_func _U_)
{
g_warning(G_STRLOC ": is not supported by the PacketList model.\n");
}
static void
packet_list_sortable_set_default_sort_func(GtkTreeSortable *sortable _U_,
GtkTreeIterCompareFunc sort_func _U_,
gpointer user_data _U_,
GDestroyNotify destroy_func _U_)
{
g_warning(G_STRLOC ": is not supported by the PacketList model.\n");
}
static gboolean
packet_list_sortable_has_default_sort_func(GtkTreeSortable *sortable _U_)
{
return FALSE;
}
static gint
packet_list_compare_custom(gint sort_id, PacketListRecord *a, PacketListRecord *b)
{
header_field_info *hfi;
hfi = proto_registrar_get_byname(cfile.cinfo.col_custom_field[sort_id]);
if (hfi == NULL) {
return frame_data_compare(a->fdata, b->fdata, COL_NUMBER);
} else if ((hfi->strings == NULL) &&
(((IS_FT_INT(hfi->type) || IS_FT_UINT(hfi->type)) &&
((hfi->display == BASE_DEC) || (hfi->display == BASE_DEC_HEX) ||
(hfi->display == BASE_OCT))) ||
(hfi->type == FT_DOUBLE) || (hfi->type == FT_FLOAT) ||
(hfi->type == FT_BOOLEAN) || (hfi->type == FT_FRAMENUM) ||
(hfi->type == FT_RELATIVE_TIME)))
{
double num_a = atof(a->col_text[sort_id]);
double num_b = atof(b->col_text[sort_id]);
if (num_a < num_b)
return -1;
else if (num_a > num_b)
return 1;
else
return frame_data_compare(a->fdata, b->fdata, COL_NUMBER);
}
return strcmp(a->col_text[sort_id], b->col_text[sort_id]);
}
static gint
_packet_list_compare_records(gint sort_id, PacketListRecord *a,
PacketListRecord *b)
{
g_assert(a->col_text);
g_assert(b->col_text);
g_assert(a->col_text[sort_id]);
g_assert(b->col_text[sort_id]);
if(a->col_text[sort_id] == b->col_text[sort_id])
return 0;
if (cfile.cinfo.col_fmt[sort_id] == COL_CUSTOM) {
return packet_list_compare_custom (sort_id, a, b);
}
return strcmp(a->col_text[sort_id], b->col_text[sort_id]);
}
static gint
packet_list_compare_records(gint sort_id, PacketListRecord *a,
PacketListRecord *b)
{
gint ret;
if (col_based_on_frame_data(&cfile.cinfo, sort_id))
return frame_data_compare(a->fdata, b->fdata, cfile.cinfo.col_fmt[sort_id]);
ret = _packet_list_compare_records(sort_id, a, b);
if (ret == 0)
ret = a->fdata->num - b->fdata->num;
return ret;
}
static gint
packet_list_qsort_physical_compare_func(PacketListRecord **a, PacketListRecord **b,
PacketList *packet_list)
{
gint ret;
g_assert((a) && (b) && (packet_list));
ret = packet_list_compare_records(packet_list->sort_id, *a, *b);
if(ret != 0 && packet_list->sort_order == GTK_SORT_DESCENDING)
ret = (ret < 0) ? 1 : -1;
return ret;
}
static void
packet_list_resort(PacketList *packet_list)
{
PacketListRecord *record;
GtkTreePath *path;
gint *neworder;
guint phy_idx;
guint vis_idx;
g_return_if_fail(packet_list != NULL);
g_return_if_fail(PACKETLIST_IS_LIST(packet_list));
if(PACKET_LIST_RECORD_COUNT(packet_list->visible_rows) == 0)
return;
g_ptr_array_sort_with_data(packet_list->physical_rows,
(GCompareDataFunc) packet_list_qsort_physical_compare_func,
packet_list);
neworder = g_new0(gint, PACKET_LIST_RECORD_COUNT(packet_list->visible_rows));
for(phy_idx = 0, vis_idx = 0; phy_idx < PACKET_LIST_RECORD_COUNT(packet_list->physical_rows); ++phy_idx) {
record = PACKET_LIST_RECORD_GET(packet_list->physical_rows, phy_idx);
record->physical_pos = phy_idx;
g_assert(record->visible_pos >= -1);
if (record->visible_pos >= 0) {
g_assert(record->fdata->flags.passed_dfilter || record->fdata->flags.ref_time);
neworder[vis_idx] = record->visible_pos;
PACKET_LIST_RECORD_SET(packet_list->visible_rows, vis_idx, record);
record->visible_pos = vis_idx;
++vis_idx;
}
}
g_assert(vis_idx == PACKET_LIST_RECORD_COUNT(packet_list->visible_rows));
path = gtk_tree_path_new();
gtk_tree_model_rows_reordered(GTK_TREE_MODEL(packet_list), path, NULL,
neworder);
gtk_tree_path_free(path);
g_free(neworder);
}
guint
packet_list_recreate_visible_rows(PacketList *packet_list)
{
guint phy_idx;
guint vis_idx;
PacketListRecord *record;
g_return_val_if_fail(packet_list != NULL, 0);
g_return_val_if_fail(PACKETLIST_IS_LIST(packet_list), 0);
if(PACKET_LIST_RECORD_COUNT(packet_list->physical_rows) == 0)
return 0;
if(packet_list->visible_rows)
g_ptr_array_free(packet_list->visible_rows, TRUE);
packet_list->visible_rows = g_ptr_array_new();
for(phy_idx = 0, vis_idx = 0; phy_idx < PACKET_LIST_RECORD_COUNT(packet_list->physical_rows); ++phy_idx) {
record = PACKET_LIST_RECORD_GET(packet_list->physical_rows, phy_idx);
if (record->fdata->flags.passed_dfilter || record->fdata->flags.ref_time) {
record->visible_pos = vis_idx++;
PACKET_LIST_RECORD_APPEND(packet_list->visible_rows, record);
}
else
record->visible_pos = -1;
}
return vis_idx;
}
void
packet_list_dissect_and_cache_iter(PacketList *packet_list, GtkTreeIter *iter, gboolean dissect_columns, gboolean dissect_color)
{
PacketListRecord *record;
g_return_if_fail(packet_list != NULL);
g_return_if_fail(PACKETLIST_IS_LIST(packet_list));
g_return_if_fail(iter != NULL);
g_return_if_fail(iter->user_data != NULL);
record = iter->user_data;
packet_list_dissect_and_cache_record(packet_list, record, dissect_columns, dissect_color);
}
static void
packet_list_dissect_and_cache_record(PacketList *packet_list, PacketListRecord *record, gboolean dissect_columns, gboolean dissect_color)
{
epan_dissect_t edt;
frame_data *fdata;
column_info *cinfo;
gint col;
gboolean create_proto_tree;
union wtap_pseudo_header pseudo_header;
guint8 pd[WTAP_MAX_PACKET_SIZE];
fdata = record->fdata;
if (dissect_columns)
cinfo = &cfile.cinfo;
else
cinfo = NULL;
if (!cf_read_frame_r(&cfile, fdata, &pseudo_header, pd)) {
if (dissect_columns) {
col_fill_in_error(cinfo, fdata, FALSE, FALSE );
for(col = 0; col < cinfo->num_cols; ++col) {
if (!col_based_on_frame_data(cinfo, col))
packet_list_change_record(packet_list, record->physical_pos, col, cinfo);
}
record->columnized = TRUE;
}
if (dissect_color) {
fdata->color_filter = NULL;
record->colorized = TRUE;
}
return;
}
create_proto_tree = (color_filters_used() && dissect_color) ||
(have_custom_cols(cinfo) && dissect_columns);
epan_dissect_init(&edt,
create_proto_tree,
FALSE );
if (dissect_color)
color_filters_prime_edt(&edt);
if (dissect_columns)
col_custom_prime_edt(&edt, cinfo);
epan_dissect_run(&edt, &pseudo_header, pd, fdata, cinfo);
if (dissect_color)
fdata->color_filter = color_filters_colorize_packet(&edt);
if (dissect_columns) {
epan_dissect_fill_in_columns(&edt, FALSE, FALSE );
for(col = 0; col < cinfo->num_cols; ++col) {
if (!col_based_on_frame_data(cinfo, col))
packet_list_change_record(packet_list, record->physical_pos, col, cinfo);
}
}
if (dissect_columns)
record->columnized = TRUE;
if (dissect_color)
record->colorized = TRUE;
epan_dissect_cleanup(&edt);
}
void
packet_list_reset_colorized(PacketList *packet_list)
{
PacketListRecord *record;
guint i;
for(i = 0; i < PACKET_LIST_RECORD_COUNT(packet_list->physical_rows); ++i) {
record = PACKET_LIST_RECORD_GET(packet_list->physical_rows, i);
record->colorized = FALSE;
}
}
const char*
packet_list_get_widest_column_string(PacketList *packet_list, gint col)
{
g_return_val_if_fail(packet_list != NULL, NULL);
g_return_val_if_fail(PACKETLIST_IS_LIST(packet_list), NULL);
g_return_val_if_fail(col < packet_list->n_columns && col >= 0, NULL);
if (PACKET_LIST_RECORD_COUNT(packet_list->visible_rows) == 0)
return "";
if (col_based_on_frame_data(&cfile.cinfo, col)) {
PacketListRecord *record;
guint vis_idx;
frame_data fdata;
memset (&fdata, 0, sizeof fdata);
nstime_set_zero(&fdata.abs_ts);
nstime_set_zero(&fdata.rel_ts);
nstime_set_zero(&fdata.del_cap_ts);
nstime_set_zero(&fdata.del_dis_ts);
for(vis_idx = 0; vis_idx < PACKET_LIST_RECORD_COUNT(packet_list->visible_rows); ++vis_idx) {
record = PACKET_LIST_RECORD_GET(packet_list->visible_rows, vis_idx);
switch (cfile.cinfo.col_fmt[col]) {
case COL_NUMBER:
if (record->fdata->num > fdata.num)
fdata.num = record->fdata->num;
break;
case COL_PACKET_LENGTH:
if (record->fdata->pkt_len > fdata.pkt_len)
fdata.pkt_len = record->fdata->pkt_len;
break;
case COL_CUMULATIVE_BYTES:
if (record->fdata->cum_bytes > fdata.cum_bytes)
fdata.cum_bytes = record->fdata->cum_bytes;
break;
case COL_ABS_TIME:
case COL_ABS_DATE_TIME:
case COL_UTC_TIME:
case COL_UTC_DATE_TIME:
if (nstime_cmp(&record->fdata->abs_ts, &fdata.abs_ts) > 0)
fdata.abs_ts = record->fdata->abs_ts;
break;
case COL_REL_TIME:
if (nstime_cmp(&record->fdata->rel_ts, &fdata.rel_ts) > 0)
fdata.rel_ts = record->fdata->rel_ts;
break;
case COL_DELTA_TIME:
if (nstime_cmp(&record->fdata->del_cap_ts, &fdata.del_cap_ts) > 0)
fdata.del_cap_ts = record->fdata->del_cap_ts;
break;
case COL_DELTA_TIME_DIS:
if (nstime_cmp(&record->fdata->del_dis_ts, &fdata.del_dis_ts) > 0)
fdata.del_dis_ts = record->fdata->del_dis_ts;
break;
case COL_CLS_TIME:
switch (timestamp_get_type()) {
case TS_ABSOLUTE:
case TS_ABSOLUTE_WITH_DATE:
case TS_UTC:
case TS_UTC_WITH_DATE:
if (nstime_cmp(&record->fdata->abs_ts, &fdata.abs_ts) > 0)
fdata.abs_ts = record->fdata->abs_ts;
break;
case TS_RELATIVE:
if (nstime_cmp(&record->fdata->rel_ts, &fdata.rel_ts) > 0)
fdata.rel_ts = record->fdata->rel_ts;
break;
case TS_DELTA:
if (nstime_cmp(&record->fdata->del_cap_ts, &fdata.del_cap_ts) > 0)
fdata.del_cap_ts = record->fdata->del_cap_ts;
break;
case TS_DELTA_DIS:
if (nstime_cmp(&record->fdata->del_dis_ts, &fdata.del_dis_ts) > 0)
fdata.del_dis_ts = record->fdata->del_dis_ts;
break;
case TS_EPOCH:
if (nstime_cmp(&record->fdata->abs_ts, &fdata.abs_ts) > 0)
fdata.abs_ts = record->fdata->abs_ts;
break;
case TS_NOT_SET:
g_assert_not_reached();
break;
}
break;
default:
g_assert_not_reached();
}
}
col_fill_in_frame_data(&fdata, &cfile.cinfo, col, FALSE);
return cfile.cinfo.col_buf[col];
}
else {
PacketListRecord *record;
guint vis_idx;
gchar *widest_column_str = NULL;
guint widest_column_len = 0;
if (!packet_list->columnized)
packet_list_dissect_and_cache_all(packet_list);
for(vis_idx = 0; vis_idx < PACKET_LIST_RECORD_COUNT(packet_list->visible_rows); ++vis_idx) {
record = PACKET_LIST_RECORD_GET(packet_list->visible_rows, vis_idx);
if (record->col_text_len[col] > widest_column_len) {
widest_column_str = record->col_text[col];
widest_column_len = record->col_text_len[col];
}
}
return widest_column_str;
}
}
