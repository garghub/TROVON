static void
field_select_row_cb(GtkTreeSelection *sel, gpointer tree)
{
GtkWidget *window = (GtkWidget *)gtk_widget_get_toplevel((GtkWidget *)tree);
GtkWidget *relation_list = (GtkWidget *)g_object_get_data(G_OBJECT(window),
E_DFILTER_EXPR_RELATION_LIST_KEY);
GtkWidget *range_label = (GtkWidget *)g_object_get_data(G_OBJECT(window),
E_DFILTER_EXPR_RANGE_LABEL_KEY);
GtkWidget *range_entry = (GtkWidget *)g_object_get_data(G_OBJECT(window),
E_DFILTER_EXPR_RANGE_ENTRY_KEY);
GtkWidget *value_label = (GtkWidget *)g_object_get_data(G_OBJECT(window),
E_DFILTER_EXPR_VALUE_LABEL_KEY);
GtkWidget *value_entry = (GtkWidget *)g_object_get_data(G_OBJECT(window),
E_DFILTER_EXPR_VALUE_ENTRY_KEY);
GtkWidget *value_list_label = (GtkWidget *)g_object_get_data(G_OBJECT(window),
E_DFILTER_EXPR_VALUE_LIST_LABEL_KEY);
GtkWidget *value_list = (GtkWidget *)g_object_get_data(G_OBJECT(window),
E_DFILTER_EXPR_VALUE_LIST_KEY);
GtkWidget *value_list_scrolled_win = (GtkWidget *)g_object_get_data(G_OBJECT(window),
E_DFILTER_EXPR_VALUE_LIST_SW_KEY);
GtkWidget *ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(window),
E_DFILTER_EXPR_OK_BT_KEY);
header_field_info *hfinfo, *cur_hfinfo;
const char *value_type;
char value_label_string[1024+1];
GtkTreeModel *model;
GtkTreeIter iter;
if (!gtk_tree_selection_get_selected(sel, &model, &iter))
return;
gtk_tree_model_get(model, &iter, 0, &hfinfo, -1);
cur_hfinfo = (header_field_info *)g_object_get_data(G_OBJECT(window), E_DFILTER_EXPR_CURRENT_VAR_KEY);
if (cur_hfinfo == hfinfo) {
return;
}
g_object_set_data(G_OBJECT(window), E_DFILTER_EXPR_CURRENT_VAR_KEY, hfinfo);
show_relations(relation_list, hfinfo->type);
value_type = ftype_pretty_name(hfinfo->type);
if (value_type != NULL) {
g_snprintf(value_label_string, sizeof value_label_string,
"Value (%s)", value_type);
gtk_label_set_text(GTK_LABEL(value_label), value_label_string);
}
gtk_entry_set_text(GTK_ENTRY(value_entry), "");
switch (hfinfo->type) {
case FT_BOOLEAN:
build_boolean_values(value_list_scrolled_win, value_list,
(const true_false_string *)hfinfo->strings);
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
if ((hfinfo->strings != NULL) &&
! (hfinfo->display & BASE_RANGE_STRING) &&
! (hfinfo->display & BASE_VAL64_STRING) &&
! ((hfinfo->display & BASE_DISPLAY_E_MASK) == BASE_CUSTOM)) {
const value_string *vals = (const value_string *)hfinfo->strings;
if (hfinfo->display & BASE_EXT_STRING)
vals = VALUE_STRING_EXT_VS_P((const value_string_ext *)vals);
build_enum_values(value_list_scrolled_win, value_list, vals);
} else
gtk_list_store_clear(GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(value_list))));
break;
default:
gtk_list_store_clear(GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(value_list))));
break;
}
display_value_fields(hfinfo, FALSE, value_label, value_entry,
value_list_label, value_list, value_list_scrolled_win, range_label, range_entry);
gtk_widget_set_sensitive(ok_bt, TRUE);
}
static void
show_relations(GtkWidget *relation_list, ftenum_t ftype)
{
GtkTreeIter iter;
gtk_list_store_clear(GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(relation_list))));
add_relation_list(relation_list, "is present", TRUE);
add_relation_list(relation_list, "==",
ftype_can_eq(ftype) || (ftype_can_slice(ftype) && ftype_can_eq(FT_BYTES)));
add_relation_list(relation_list, "!=",
ftype_can_ne(ftype) || (ftype_can_slice(ftype) && ftype_can_ne(FT_BYTES)));
add_relation_list(relation_list, ">",
ftype_can_gt(ftype) || (ftype_can_slice(ftype) && ftype_can_gt(FT_BYTES)));
add_relation_list(relation_list, "<",
ftype_can_lt(ftype) || (ftype_can_slice(ftype) && ftype_can_lt(FT_BYTES)));
add_relation_list(relation_list, ">=",
ftype_can_ge(ftype) || (ftype_can_slice(ftype) && ftype_can_ge(FT_BYTES)));
add_relation_list(relation_list, "<=",
ftype_can_le(ftype) || (ftype_can_slice(ftype) && ftype_can_le(FT_BYTES)));
add_relation_list(relation_list, "contains",
ftype_can_contains(ftype) || (ftype_can_slice(ftype) && ftype_can_contains(FT_BYTES)));
add_relation_list(relation_list, "matches",
ftype_can_matches(ftype) || (ftype_can_slice(ftype) && ftype_can_matches(FT_BYTES)));
gtk_tree_model_get_iter_first(gtk_tree_view_get_model(GTK_TREE_VIEW(relation_list)), &iter);
gtk_tree_selection_select_iter(gtk_tree_view_get_selection(GTK_TREE_VIEW(relation_list)), &iter);
}
static gboolean
relation_is_presence_test(const char *string)
{
return (strcmp(string, "is present") == 0);
}
static void
add_relation_list(GtkWidget *relation_list, const char *relation, gboolean sensitive)
{
GtkListStore *store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(relation_list)));
GtkTreeIter iter;
if (!sensitive) {
return;
}
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, 0, relation, -1);
}
static void
relation_list_sel_cb(GtkTreeSelection *sel, gpointer user_data _U_)
{
GtkWidget *window = gtk_widget_get_toplevel(GTK_WIDGET(gtk_tree_selection_get_tree_view(sel)));
GtkWidget *range_label =
(GtkWidget *)g_object_get_data(G_OBJECT(window), E_DFILTER_EXPR_RANGE_LABEL_KEY);
GtkWidget *range_entry =
(GtkWidget *)g_object_get_data(G_OBJECT(window), E_DFILTER_EXPR_RANGE_ENTRY_KEY);
GtkWidget *value_label =
(GtkWidget *)g_object_get_data(G_OBJECT(window), E_DFILTER_EXPR_VALUE_LABEL_KEY);
GtkWidget *value_entry =
(GtkWidget *)g_object_get_data(G_OBJECT(window), E_DFILTER_EXPR_VALUE_ENTRY_KEY);
GtkWidget *value_list_label =
(GtkWidget *)g_object_get_data(G_OBJECT(window), E_DFILTER_EXPR_VALUE_LIST_LABEL_KEY);
GtkWidget *value_list =
(GtkWidget *)g_object_get_data(G_OBJECT(window), E_DFILTER_EXPR_VALUE_LIST_KEY);
GtkWidget *value_list_scrolled_win =
(GtkWidget *)g_object_get_data(G_OBJECT(window), E_DFILTER_EXPR_VALUE_LIST_SW_KEY);
header_field_info *hfinfo =
(header_field_info *)g_object_get_data(G_OBJECT(window), E_DFILTER_EXPR_CURRENT_VAR_KEY);
gchar *item_str;
GtkTreeModel *model;
GtkTreeIter iter;
if (!gtk_tree_selection_get_selected(sel, &model, &iter))
return;
gtk_tree_model_get(model, &iter, 0, &item_str, -1);
display_value_fields(hfinfo,
!relation_is_presence_test(item_str),
value_label, value_entry, value_list_label, value_list,
value_list_scrolled_win, range_label, range_entry);
g_free(item_str);
}
static void
build_boolean_values(GtkWidget *value_list_scrolled_win, GtkWidget *value_list,
const true_false_string *values)
{
static const true_false_string true_false = { "True", "False" };
GtkTreeSelection *sel;
GtkTreeIter iter;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(value_list));
gtk_list_store_clear(GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(value_list))));
gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
if (values == NULL)
values = &true_false;
add_value_list_item(value_list, values->true_string, (gpointer) values);
add_value_list_item(value_list, values->false_string, NULL);
gtk_tree_selection_set_mode(sel, GTK_SELECTION_BROWSE);
gtk_tree_model_get_iter_first(gtk_tree_view_get_model(GTK_TREE_VIEW(value_list)), &iter);
gtk_tree_selection_select_iter(sel, &iter);
gtk_widget_show_all(value_list_scrolled_win);
}
static void
build_enum_values(GtkWidget *value_list_scrolled_win _U_, GtkWidget *value_list,
const value_string *values)
{
GtkTreeSelection *sel;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(value_list));
gtk_list_store_clear(GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(value_list))));
gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
while (values->strptr != NULL) {
add_value_list_item(value_list, values->strptr, (const gpointer) values);
values++;
}
gtk_tree_selection_set_mode(sel, GTK_SELECTION_BROWSE);
}
static void
add_value_list_item(GtkWidget *value_list, const gchar *string, const gpointer data)
{
GtkListStore *store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(value_list)));
GtkTreeIter iter;
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, 0, string, 1, data, -1);
}
static void
display_value_fields(header_field_info *hfinfo, gboolean is_comparison,
GtkWidget *value_label, GtkWidget *value_entry,
GtkWidget *value_list_label,
GtkWidget *value_list _U_,
GtkWidget *value_list_scrolled_win, GtkWidget *range_label,
GtkWidget *range_entry)
{
gboolean show_value_label = FALSE;
gboolean show_value_list = FALSE;
gboolean show_range = FALSE;
switch (hfinfo->type) {
case FT_BOOLEAN:
if (is_comparison) {
show_value_label = TRUE;
show_value_list = TRUE;
}
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
if (is_comparison) {
show_value_label = TRUE;
if ((hfinfo->strings != NULL) && !(hfinfo->display & BASE_RANGE_STRING)) {
show_value_list = TRUE;
}
}
break;
default:
if (is_comparison)
show_value_label = TRUE;
break;
}
gtk_widget_set_sensitive(value_label, show_value_label);
gtk_widget_set_sensitive(value_entry, show_value_label);
gtk_widget_set_sensitive(value_list_label, show_value_list);
gtk_widget_set_sensitive(value_list_scrolled_win, show_value_list);
show_range = (is_comparison && ftype_can_slice(hfinfo->type));
gtk_widget_set_sensitive(range_label, show_range);
gtk_widget_set_sensitive(range_entry, show_range);
}
static void
value_list_sel_cb(GtkTreeSelection *sel, gpointer value_entry_arg)
{
GtkWidget *value_entry = (GtkWidget *)value_entry_arg;
GtkWidget *window = gtk_widget_get_toplevel(GTK_WIDGET(gtk_tree_selection_get_tree_view(sel)));
GtkTreeModel *model;
GtkTreeIter iter;
header_field_info *hfinfo = (header_field_info *)g_object_get_data(G_OBJECT(window),
E_DFILTER_EXPR_CURRENT_VAR_KEY);
const value_string *value = NULL;
gchar *value_display_string = NULL;
if (!gtk_tree_selection_get_selected(sel, &model, &iter))
return;
gtk_tree_model_get(model, &iter, 1, &value, -1);
if (hfinfo->type == FT_BOOLEAN) {
if (value != NULL)
value_display_string = g_strdup("1");
else
value_display_string = g_strdup("0");
} else {
switch ((hfinfo->display) & BASE_DISPLAY_E_MASK) {
case BASE_NONE:
case BASE_DEC:
case BASE_DEC_HEX:
switch (hfinfo->type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
value_display_string = g_strdup_printf("%u", value->value);
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
value_display_string = g_strdup_printf("%d", value->value);
break;
default:
g_assert_not_reached();
}
break;
case BASE_HEX:
case BASE_HEX_DEC:
value_display_string = g_strdup_printf("0x%x", value->value);
break;
case BASE_OCT:
value_display_string = g_strdup_printf("%#o", value->value);
break;
default:
g_assert_not_reached();
}
}
gtk_entry_set_text(GTK_ENTRY(value_entry), value_display_string);
g_free (value_display_string);
}
static void
dfilter_report_bad_value(const char *format, ...)
{
char error_msg_buf[1024];
va_list args;
va_start(args, format);
g_vsnprintf(error_msg_buf, sizeof error_msg_buf, format, args);
va_end(args);
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_msg_buf);
}
static void
dfilter_expr_dlg_accept_cb(GtkWidget *w, gpointer filter_te_arg)
{
GtkWidget *filter_te = (GtkWidget *)filter_te_arg;
GtkWidget *window = gtk_widget_get_toplevel(w);
GtkWidget *relation_list =
(GtkWidget *)g_object_get_data(G_OBJECT(window), E_DFILTER_EXPR_RELATION_LIST_KEY);
GtkWidget *range_entry =
(GtkWidget *)g_object_get_data(G_OBJECT(window), E_DFILTER_EXPR_RANGE_ENTRY_KEY);
GtkWidget *value_entry =
(GtkWidget *)g_object_get_data(G_OBJECT(window), E_DFILTER_EXPR_VALUE_ENTRY_KEY);
header_field_info *hfinfo;
gchar *item_str;
gchar *range_str, *stripped_range_str;
gchar *value_str, *stripped_value_str;
int pos;
gchar *chars;
ftenum_t ftype;
gboolean can_compare;
fvalue_t *fvalue;
GtkTreeModel *model;
GtkTreeIter iter;
gboolean quote_it;
hfinfo = (header_field_info *)g_object_get_data(G_OBJECT(window), E_DFILTER_EXPR_CURRENT_VAR_KEY);
if (gtk_tree_selection_get_selected(gtk_tree_view_get_selection(GTK_TREE_VIEW(relation_list)),
&model, &iter)) {
gtk_tree_model_get(model, &iter, 0, &item_str, -1);
} else {
return;
}
if (gtk_widget_get_sensitive(range_entry)) {
range_str = g_strdup(gtk_entry_get_text(GTK_ENTRY(range_entry)));
stripped_range_str = g_strstrip(range_str);
if (strcmp(stripped_range_str, "") == 0) {
g_free(range_str);
range_str = NULL;
stripped_range_str = NULL;
}
} else {
range_str = NULL;
stripped_range_str = NULL;
}
if (range_str == NULL)
ftype = hfinfo->type;
else
ftype = FT_BYTES;
if (strcmp(item_str, "==") == 0)
can_compare = ftype_can_eq(ftype);
else if (strcmp(item_str, "!=") == 0)
can_compare = ftype_can_ne(ftype);
else if (strcmp(item_str, ">") == 0)
can_compare = ftype_can_gt(ftype);
else if (strcmp(item_str, "<") == 0)
can_compare = ftype_can_lt(ftype);
else if (strcmp(item_str, ">=") == 0)
can_compare = ftype_can_ge(ftype);
else if (strcmp(item_str, "<=") == 0)
can_compare = ftype_can_le(ftype);
else if (strcmp(item_str, "contains") == 0)
can_compare = ftype_can_contains(ftype);
else if (strcmp(item_str, "matches") == 0)
can_compare = ftype_can_matches(ftype);
else
can_compare = TRUE;
if (!can_compare) {
if (range_str == NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"That field can't be tested with \"%s\".",
item_str);
} else {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Ranges of that field can't be tested with \"%s\".",
item_str);
}
g_free(range_str);
g_free(item_str);
return;
}
if (gtk_widget_get_sensitive(value_entry)) {
value_str = g_strdup(gtk_entry_get_text(GTK_ENTRY(value_entry)));
stripped_value_str = g_strstrip(value_str);
if (strcmp(stripped_value_str, "") == 0) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"That field must be compared with a value, "
"but you didn't specify a value with which to "
"compare it.");
g_free(range_str);
g_free(value_str);
g_free(item_str);
return;
}
if (strcmp(item_str, "contains") == 0) {
fvalue = fvalue_from_unparsed(ftype, stripped_value_str, TRUE,
dfilter_report_bad_value);
}
else {
fvalue = fvalue_from_unparsed(ftype, stripped_value_str, FALSE,
dfilter_report_bad_value);
}
if (fvalue == NULL) {
g_free(range_str);
g_free(value_str);
g_free(item_str);
return;
}
FVALUE_FREE(fvalue);
} else {
value_str = NULL;
stripped_value_str = NULL;
}
pos = gtk_editable_get_position(GTK_EDITABLE(filter_te));
chars = gtk_editable_get_chars(GTK_EDITABLE(filter_te), pos, pos + 1);
if (strcmp(chars, "") != 0 && !isspace((unsigned char)chars[0]))
gtk_editable_insert_text(GTK_EDITABLE(filter_te), " ", 1, &pos);
g_free(chars);
gtk_editable_insert_text(GTK_EDITABLE(filter_te), hfinfo->abbrev,
(gint) strlen(hfinfo->abbrev), &pos);
if (range_str != NULL) {
gtk_editable_insert_text(GTK_EDITABLE(filter_te), "[", 1, &pos);
gtk_editable_insert_text(GTK_EDITABLE(filter_te),
stripped_range_str, (gint) strlen(stripped_range_str), &pos);
gtk_editable_insert_text(GTK_EDITABLE(filter_te), "]", 1, &pos);
g_free(range_str);
}
if (!relation_is_presence_test(item_str)) {
gtk_editable_insert_text(GTK_EDITABLE(filter_te), " ", 1, &pos);
gtk_editable_insert_text(GTK_EDITABLE(filter_te), item_str,
(gint) strlen(item_str), &pos);
}
if (value_str != NULL) {
gtk_editable_insert_text(GTK_EDITABLE(filter_te), " ", 1, &pos);
switch (hfinfo->type) {
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_ABSOLUTE_TIME:
quote_it = TRUE;
break;
default:
quote_it = (strpbrk(stripped_value_str, " \t") != NULL);
break;
}
if (quote_it) {
gtk_editable_insert_text(GTK_EDITABLE(filter_te), "\"",
1, &pos);
}
gtk_editable_insert_text(GTK_EDITABLE(filter_te),
stripped_value_str, (gint) strlen(stripped_value_str), &pos);
if (quote_it) {
gtk_editable_insert_text(GTK_EDITABLE(filter_te), "\"",
1, &pos);
}
g_free(value_str);
}
chars = gtk_editable_get_chars(GTK_EDITABLE(filter_te), pos + 1, pos + 2);
if (strcmp(chars, "") != 0 && !isspace((unsigned char)chars[0]))
gtk_editable_insert_text(GTK_EDITABLE(filter_te), " ", 1, &pos);
g_free(chars);
gtk_editable_set_position(GTK_EDITABLE(filter_te), pos);
window_destroy(window);
g_free(item_str);
}
static void
dfilter_expr_dlg_cancel_cb(GtkWidget *w _U_, gpointer parent_w)
{
window_destroy(GTK_WIDGET(parent_w));
}
static gboolean
dfilter_expr_dlg_delete_event_cb(GtkWidget *w _U_, GdkEvent *event _U_,
gpointer parent_w)
{
dfilter_expr_dlg_cancel_cb(NULL, parent_w);
return FALSE;
}
static void
dfilter_expr_dlg_destroy_cb(GtkWidget *w, gpointer filter_te)
{
g_signal_handlers_disconnect_by_func(filter_te, dfilter_expr_dlg_cancel_cb, w);
}
GtkWidget *
dfilter_expr_dlg_new(GtkWidget *filter_te)
{
GtkWidget *window, *main_vb, *main_hb;
GtkWidget *field_vb, *field_tree_lb, *field_tree, *tree_scrolled_win;
GtkWidget *relation_vb, *relation_label, *relation_list, *relation_list_scrolled_win;
GtkWidget *value_vb, *value_label, *value_entry;
GtkWidget *value_list_label, *value_list_scrolled_win, *value_list;
GtkWidget *range_label, *range_entry;
GtkWidget *list_bb, *ok_bt, *cancel_bt;
ProtoHierTreeModel *store_proto;
GtkTreeModel *store;
GtkTreeSelection *selection;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkListStore *l_store;
GtkTreeSelection *l_sel;
proto_initialize_all_prefixes();
window = dlg_conf_window_new("Wireshark: Filter Expression");
gtk_window_set_default_size(GTK_WINDOW(window), 500, 400);
gtk_container_set_border_width(GTK_CONTAINER(window), 5);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(window), main_vb);
main_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_hb), 5);
gtk_box_pack_start(GTK_BOX (main_vb), main_hb, TRUE, TRUE, 0);
field_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(field_vb), 5);
gtk_box_pack_start(GTK_BOX (main_hb), field_vb, TRUE, TRUE, 0);
field_tree_lb = gtk_label_new("Field name");
gtk_misc_set_alignment(GTK_MISC(field_tree_lb), 0.0f, 0.0f);
gtk_box_pack_start(GTK_BOX(field_vb), field_tree_lb, FALSE, FALSE, 0);
tree_scrolled_win = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(tree_scrolled_win),
GTK_SHADOW_IN);
gtk_box_pack_start(GTK_BOX(field_vb), tree_scrolled_win, TRUE, TRUE, 0);
gtk_widget_set_size_request(tree_scrolled_win, 300, -1);
field_tree = tree_view_new(GTK_TREE_MODEL(NULL));
gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(field_tree), FALSE);
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(field_tree));
gtk_tree_selection_set_mode(selection, GTK_SELECTION_BROWSE);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Field name", renderer,
"text", 1, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(field_tree), column);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
gtk_tree_view_column_set_sort_column_id(column, 0);
g_signal_connect(selection, "changed", G_CALLBACK(field_select_row_cb), field_tree);
gtk_container_add(GTK_CONTAINER(tree_scrolled_win), field_tree);
relation_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(relation_vb), 5);
gtk_box_pack_start(GTK_BOX (main_hb), relation_vb, TRUE, TRUE, 0);
relation_label = gtk_label_new("Relation");
gtk_misc_set_alignment(GTK_MISC(relation_label), 0.0f, 0.0f);
gtk_box_pack_start(GTK_BOX(relation_vb), relation_label, FALSE, FALSE, 0);
relation_list_scrolled_win = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(relation_list_scrolled_win),
GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(relation_list_scrolled_win),
GTK_SHADOW_IN);
l_store = gtk_list_store_new(1, G_TYPE_STRING);
relation_list = tree_view_new(GTK_TREE_MODEL(l_store));
gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(relation_list), FALSE);
g_object_unref(G_OBJECT(l_store));
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("relation", renderer,
"text", 0, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(relation_list), column);
l_sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(relation_list));
gtk_tree_selection_set_mode(l_sel, GTK_SELECTION_BROWSE);
gtk_container_add(GTK_CONTAINER(relation_list_scrolled_win), relation_list);
gtk_box_pack_start(GTK_BOX(relation_vb), relation_list_scrolled_win, TRUE, TRUE, 0);
show_relations(relation_list, FT_UINT8);
value_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(value_vb), 5);
gtk_box_pack_start(GTK_BOX (main_hb), value_vb, TRUE, TRUE, 0);
value_label = gtk_label_new("Value");
gtk_misc_set_alignment(GTK_MISC(value_label), 0.0f, 0.0f);
gtk_box_pack_start(GTK_BOX(value_vb), value_label, FALSE, FALSE, 0);
value_entry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(value_vb), value_entry, FALSE, FALSE, 0);
value_list_label = gtk_label_new("Predefined values:");
gtk_misc_set_alignment(GTK_MISC(value_list_label), 0.0f, 0.0f);
gtk_box_pack_start(GTK_BOX(value_vb), value_list_label, FALSE, FALSE, 0);
value_list_scrolled_win = scrolled_window_new(NULL, NULL);
gtk_box_pack_start(GTK_BOX(value_vb), value_list_scrolled_win, TRUE,
TRUE, 0);
l_store = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_POINTER);
value_list = tree_view_new(GTK_TREE_MODEL(l_store));
gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(value_list), FALSE);
g_object_unref(G_OBJECT(l_store));
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("value", renderer,
"text", 0, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(value_list), column);
g_signal_connect(gtk_tree_view_get_selection(GTK_TREE_VIEW(value_list)),
"changed", G_CALLBACK(value_list_sel_cb), value_entry);
g_signal_connect(gtk_tree_view_get_selection(GTK_TREE_VIEW(relation_list)),
"changed", G_CALLBACK(relation_list_sel_cb), NULL);
l_sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(value_list));
gtk_tree_selection_set_mode(l_sel, GTK_SELECTION_SINGLE);
#if ! GTK_CHECK_VERSION(3,8,0)
gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(value_list_scrolled_win),
value_list);
#else
gtk_container_add(GTK_CONTAINER(value_list_scrolled_win),
value_list);
#endif
store_proto = proto_hier_tree_model_new();
store = gtk_tree_model_sort_new_with_model(GTK_TREE_MODEL(store_proto));
gtk_tree_sortable_set_sort_column_id(GTK_TREE_SORTABLE(store), 1, GTK_SORT_ASCENDING);
g_object_unref(G_OBJECT(store_proto));
gtk_tree_view_set_model(GTK_TREE_VIEW(field_tree), GTK_TREE_MODEL(store));
gtk_tree_view_set_search_column(GTK_TREE_VIEW(field_tree), 1);
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(field_tree), TRUE);
g_object_unref(G_OBJECT(store));
range_label = gtk_label_new("Range (offset:length)");
gtk_misc_set_alignment(GTK_MISC(range_label), 0.0f, 0.0f);
gtk_box_pack_start(GTK_BOX(value_vb), range_label, FALSE, FALSE, 0);
range_entry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(value_vb), range_entry, FALSE, FALSE, 0);
list_bb = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_CANCEL, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), list_bb, FALSE, FALSE, 0);
gtk_container_set_border_width (GTK_CONTAINER (list_bb), 0);
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(list_bb), GTK_STOCK_OK);
gtk_widget_set_sensitive(ok_bt, FALSE);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(dfilter_expr_dlg_accept_cb), filter_te);
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(list_bb), GTK_STOCK_CANCEL);
window_set_cancel_button(window, cancel_bt, NULL);
g_signal_connect(cancel_bt, "clicked", G_CALLBACK(dfilter_expr_dlg_cancel_cb), window);
gtk_widget_grab_default(ok_bt);
dlg_set_activate(range_entry, ok_bt);
dlg_set_activate(value_entry, ok_bt);
g_object_set_data(G_OBJECT(window), E_DFILTER_EXPR_RELATION_LIST_KEY, relation_list);
g_object_set_data(G_OBJECT(window), E_DFILTER_EXPR_RANGE_LABEL_KEY, range_label);
g_object_set_data(G_OBJECT(window), E_DFILTER_EXPR_RANGE_ENTRY_KEY, range_entry);
g_object_set_data(G_OBJECT(window), E_DFILTER_EXPR_VALUE_LABEL_KEY, value_label);
g_object_set_data(G_OBJECT(window), E_DFILTER_EXPR_VALUE_ENTRY_KEY, value_entry);
g_object_set_data(G_OBJECT(window), E_DFILTER_EXPR_VALUE_LIST_KEY, value_list);
g_object_set_data(G_OBJECT(window), E_DFILTER_EXPR_VALUE_LIST_LABEL_KEY, value_list_label);
g_object_set_data(G_OBJECT(window), E_DFILTER_EXPR_VALUE_LIST_SW_KEY,
value_list_scrolled_win);
g_object_set_data(G_OBJECT(window), E_DFILTER_EXPR_OK_BT_KEY, ok_bt);
g_signal_connect(window, "delete_event", G_CALLBACK(dfilter_expr_dlg_delete_event_cb), window);
g_signal_connect(window, "destroy", G_CALLBACK(dfilter_expr_dlg_destroy_cb), filter_te);
g_signal_connect(filter_te, "destroy", G_CALLBACK(dfilter_expr_dlg_cancel_cb), window);
gtk_widget_show_all(window);
window_present(window);
return window;
}
