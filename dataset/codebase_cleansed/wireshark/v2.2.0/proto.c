static void save_same_name_hfinfo(gpointer data)
{
same_name_hfinfo = (header_field_info*)data;
}
static gint
proto_compare_name(gconstpointer p1_arg, gconstpointer p2_arg)
{
const protocol_t *p1 = (const protocol_t *)p1_arg;
const protocol_t *p2 = (const protocol_t *)p2_arg;
return g_ascii_strcasecmp(p1->short_name, p2->short_name);
}
static gboolean
check_for_dissector_plugin(GModule *handle)
{
gpointer gp;
void (*register_protoinfo)(void);
void (*reg_handoff)(void);
dissector_plugin *plugin;
if (g_module_symbol(handle, "plugin_register", &gp)) {
DIAG_OFF(pedantic)
register_protoinfo = (void (*)(void))gp;
DIAG_ON(pedantic)
}
else {
register_protoinfo = NULL;
}
if (g_module_symbol(handle, "plugin_reg_handoff", &gp)) {
DIAG_OFF(pedantic)
reg_handoff = (void (*)(void))gp;
DIAG_ON(pedantic)
}
else {
reg_handoff = NULL;
}
if (register_protoinfo == NULL && reg_handoff == NULL)
return FALSE;
plugin = (dissector_plugin *)g_malloc(sizeof (dissector_plugin));
plugin->register_protoinfo = register_protoinfo;
plugin->reg_handoff = reg_handoff;
dissector_plugins = g_slist_append(dissector_plugins, plugin);
return TRUE;
}
static void
register_dissector_plugin(gpointer data, gpointer user_data _U_)
{
dissector_plugin *plugin = (dissector_plugin *)data;
if (plugin->register_protoinfo)
(plugin->register_protoinfo)();
}
static void
reg_handoff_dissector_plugin(gpointer data, gpointer user_data _U_)
{
dissector_plugin *plugin = (dissector_plugin *)data;
if (plugin->reg_handoff)
(plugin->reg_handoff)();
}
void
register_dissector_plugin_type(void)
{
add_plugin_type("dissector", check_for_dissector_plugin);
}
void
proto_init(void (register_all_protocols_func)(register_cb cb, gpointer client_data),
void (register_all_handoffs_func)(register_cb cb, gpointer client_data),
register_cb cb,
gpointer client_data)
{
proto_cleanup();
proto_names = g_hash_table_new_full(g_int_hash, g_int_equal, g_free, NULL);
proto_short_names = g_hash_table_new(wrs_str_hash, g_str_equal);
proto_filter_names = g_hash_table_new(wrs_str_hash, g_str_equal);
gpa_hfinfo.len = 0;
gpa_hfinfo.allocated_len = 0;
gpa_hfinfo.hfi = NULL;
gpa_name_map = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, save_same_name_hfinfo);
deregistered_fields = g_ptr_array_new();
deregistered_data = g_ptr_array_new();
ftypes_initialize();
address_types_initialize();
hf_text_only = proto_register_field_init(&hfi_text_only, -1);
register_show_exception();
register_type_length_mismatch();
register_number_string_decoding_error();
register_all_protocols_func(cb, client_data);
vines_address_type = address_type_get_by_name("AT_VINES");
#ifdef HAVE_PLUGINS
if (cb)
(*cb)(RA_PLUGIN_REGISTER, NULL, client_data);
g_slist_foreach(dissector_plugins, register_dissector_plugin, NULL);
#endif
register_all_handoffs_func(cb, client_data);
#ifdef HAVE_PLUGINS
if (cb)
(*cb)(RA_PLUGIN_HANDOFF, NULL, client_data);
g_slist_foreach(dissector_plugins, reg_handoff_dissector_plugin, NULL);
#endif
protocols = g_list_sort(protocols, proto_compare_name);
tree_is_expanded = g_new0(guint32, (num_tree_types/32)+1);
}
void
proto_cleanup(void)
{
if (gpa_name_map) {
g_hash_table_destroy(gpa_name_map);
gpa_name_map = NULL;
}
g_free(last_field_name);
last_field_name = NULL;
while (protocols) {
protocol_t *protocol = (protocol_t *)protocols->data;
header_field_info *hfinfo;
PROTO_REGISTRAR_GET_NTH(protocol->proto_id, hfinfo);
DISSECTOR_ASSERT(protocol->proto_id == hfinfo->id);
g_slice_free(header_field_info, hfinfo);
g_ptr_array_free(protocol->fields, TRUE);
g_list_free(protocol->heur_list);
protocols = g_list_remove(protocols, protocol);
g_free(protocol);
}
if (proto_names) {
g_hash_table_destroy(proto_names);
proto_names = NULL;
}
if (proto_short_names) {
g_hash_table_destroy(proto_short_names);
proto_short_names = NULL;
}
if (proto_filter_names) {
g_hash_table_destroy(proto_filter_names);
proto_filter_names = NULL;
}
if (gpa_hfinfo.allocated_len) {
gpa_hfinfo.len = 0;
gpa_hfinfo.allocated_len = 0;
g_free(gpa_hfinfo.hfi);
gpa_hfinfo.hfi = NULL;
}
if (deregistered_fields) {
g_ptr_array_free(deregistered_fields, FALSE);
deregistered_fields = NULL;
}
if (deregistered_data) {
g_ptr_array_free(deregistered_data, FALSE);
deregistered_data = NULL;
}
g_free(tree_is_expanded);
tree_is_expanded = NULL;
}
static gboolean
proto_tree_traverse_pre_order(proto_tree *tree, proto_tree_traverse_func func,
gpointer data)
{
proto_node *pnode = tree;
proto_node *child;
proto_node *current;
if (func(pnode, data))
return TRUE;
child = pnode->first_child;
while (child != NULL) {
current = child;
child = current->next;
if (proto_tree_traverse_pre_order((proto_tree *)current, func, data))
return TRUE;
}
return FALSE;
}
gboolean
proto_tree_traverse_post_order(proto_tree *tree, proto_tree_traverse_func func,
gpointer data)
{
proto_node *pnode = tree;
proto_node *child;
proto_node *current;
child = pnode->first_child;
while (child != NULL) {
current = child;
child = current->next;
if (proto_tree_traverse_post_order((proto_tree *)current, func, data))
return TRUE;
}
if (func(pnode, data))
return TRUE;
return FALSE;
}
void
proto_tree_children_foreach(proto_tree *tree, proto_tree_foreach_func func,
gpointer data)
{
proto_node *node = tree;
proto_node *current;
if (!node)
return;
node = node->first_child;
while (node != NULL) {
current = node;
node = current->next;
func((proto_tree *)current, data);
}
}
static void
free_GPtrArray_value(gpointer key, gpointer value, gpointer user_data _U_)
{
GPtrArray *ptrs = (GPtrArray *)value;
gint hfid = GPOINTER_TO_UINT(key);
header_field_info *hfinfo;
PROTO_REGISTRAR_GET_NTH(hfid, hfinfo);
if (hfinfo->ref_type != HF_REF_TYPE_NONE) {
if (hfinfo->parent != -1) {
header_field_info *parent_hfinfo;
PROTO_REGISTRAR_GET_NTH(hfinfo->parent, parent_hfinfo);
parent_hfinfo->ref_type = HF_REF_TYPE_NONE;
}
hfinfo->ref_type = HF_REF_TYPE_NONE;
}
g_ptr_array_free(ptrs, TRUE);
}
static void
proto_tree_free_node(proto_node *node, gpointer data _U_)
{
field_info *finfo = PNODE_FINFO(node);
proto_tree_children_foreach(node, proto_tree_free_node, NULL);
FVALUE_CLEANUP(&finfo->value);
}
void
proto_tree_reset(proto_tree *tree)
{
tree_data_t *tree_data = PTREE_DATA(tree);
proto_tree_children_foreach(tree, proto_tree_free_node, NULL);
if (tree_data->interesting_hfids) {
g_hash_table_foreach(tree_data->interesting_hfids,
free_GPtrArray_value, NULL);
g_hash_table_remove_all(tree_data->interesting_hfids);
}
tree_data->count = 0;
PROTO_NODE_INIT(tree);
}
void
proto_tree_free(proto_tree *tree)
{
tree_data_t *tree_data = PTREE_DATA(tree);
proto_tree_children_foreach(tree, proto_tree_free_node, NULL);
if (tree_data->interesting_hfids) {
g_hash_table_foreach(tree_data->interesting_hfids,
free_GPtrArray_value, NULL);
g_hash_table_destroy(tree_data->interesting_hfids);
}
g_slice_free(tree_data_t, tree_data);
g_slice_free(proto_tree, tree);
}
gboolean
proto_tree_set_visible(proto_tree *tree, gboolean visible)
{
gboolean old_visible = PTREE_DATA(tree)->visible;
PTREE_DATA(tree)->visible = visible;
return old_visible;
}
void
proto_tree_set_fake_protocols(proto_tree *tree, gboolean fake_protocols)
{
PTREE_DATA(tree)->fake_protocols = fake_protocols;
}
gboolean
proto_field_is_referenced(proto_tree *tree, int proto_id)
{
register header_field_info *hfinfo;
if (!tree)
return FALSE;
if (PTREE_DATA(tree)->visible)
return TRUE;
PROTO_REGISTRAR_GET_NTH(proto_id, hfinfo);
if (hfinfo->ref_type != HF_REF_TYPE_NONE)
return TRUE;
if (hfinfo->type == FT_PROTOCOL && !PTREE_DATA(tree)->fake_protocols)
return TRUE;
return FALSE;
}
header_field_info *
proto_registrar_get_nth(guint hfindex)
{
register header_field_info *hfinfo;
PROTO_REGISTRAR_GET_NTH(hfindex, hfinfo);
return hfinfo;
}
static guint
prefix_hash (gconstpointer key) {
gchar* copy = g_strdup((const gchar *)key);
gchar* c = copy;
guint tmp;
for (; *c; c++) {
if (*c == '.') {
*c = 0;
break;
}
}
tmp = g_str_hash(copy);
g_free(copy);
return tmp;
}
static gboolean
prefix_equal (gconstpointer ap, gconstpointer bp) {
const gchar* a = (const gchar *)ap;
const gchar* b = (const gchar *)bp;
do {
gchar ac = *a++;
gchar bc = *b++;
if ( (ac == '.' || ac == '\0') && (bc == '.' || bc == '\0') ) return TRUE;
if ( (ac == '.' || ac == '\0') && ! (bc == '.' || bc == '\0') ) return FALSE;
if ( (bc == '.' || bc == '\0') && ! (ac == '.' || ac == '\0') ) return FALSE;
if (ac != bc) return FALSE;
} while (1);
return FALSE;
}
void
proto_register_prefix(const char *prefix, prefix_initializer_t pi ) {
if (! prefixes ) {
prefixes = g_hash_table_new(prefix_hash, prefix_equal);
}
g_hash_table_insert(prefixes, (gpointer)prefix, (gpointer)pi);
}
static gboolean
initialize_prefix(gpointer k, gpointer v, gpointer u _U_) {
((prefix_initializer_t)v)((const char *)k);
return TRUE;
}
void
proto_initialize_all_prefixes(void) {
g_hash_table_foreach_remove(prefixes, initialize_prefix, NULL);
}
header_field_info *
proto_registrar_get_byname(const char *field_name)
{
header_field_info *hfinfo;
prefix_initializer_t pi;
if (!field_name)
return NULL;
if (g_strcmp0(field_name, last_field_name) == 0) {
return last_hfinfo;
}
hfinfo = (header_field_info *)g_hash_table_lookup(gpa_name_map, field_name);
if (hfinfo) {
g_free(last_field_name);
last_field_name = g_strdup(field_name);
last_hfinfo = hfinfo;
return hfinfo;
}
if (!prefixes)
return NULL;
if ((pi = (prefix_initializer_t)g_hash_table_lookup(prefixes, field_name) ) != NULL) {
pi(field_name);
g_hash_table_remove(prefixes, field_name);
} else {
return NULL;
}
hfinfo = (header_field_info *)g_hash_table_lookup(gpa_name_map, field_name);
if (hfinfo) {
g_free(last_field_name);
last_field_name = g_strdup(field_name);
last_hfinfo = hfinfo;
}
return hfinfo;
}
int
proto_registrar_get_id_byname(const char *field_name)
{
header_field_info *hfinfo;
hfinfo = proto_registrar_get_byname(field_name);
if (!hfinfo)
return -1;
return hfinfo->id;
}
static void
ptvcursor_new_subtree_levels(ptvcursor_t *ptvc)
{
subtree_lvl *pushed_tree;
DISSECTOR_ASSERT(ptvc->pushed_tree_max <= SUBTREE_MAX_LEVELS-SUBTREE_ONCE_ALLOCATION_NUMBER);
ptvc->pushed_tree_max += SUBTREE_ONCE_ALLOCATION_NUMBER;
pushed_tree = (subtree_lvl *)wmem_alloc(wmem_packet_scope(), sizeof(subtree_lvl) * ptvc->pushed_tree_max);
DISSECTOR_ASSERT(pushed_tree != NULL);
if (ptvc->pushed_tree)
memcpy(pushed_tree, ptvc->pushed_tree, ptvc->pushed_tree_max - SUBTREE_ONCE_ALLOCATION_NUMBER);
ptvc->pushed_tree = pushed_tree;
}
static void
ptvcursor_free_subtree_levels(ptvcursor_t *ptvc)
{
ptvc->pushed_tree = NULL;
ptvc->pushed_tree_max = 0;
DISSECTOR_ASSERT(ptvc->pushed_tree_index == 0);
ptvc->pushed_tree_index = 0;
}
ptvcursor_t *
ptvcursor_new(proto_tree *tree, tvbuff_t *tvb, gint offset)
{
ptvcursor_t *ptvc;
ptvc = (ptvcursor_t *)wmem_alloc(wmem_packet_scope(), sizeof(ptvcursor_t));
ptvc->tree = tree;
ptvc->tvb = tvb;
ptvc->offset = offset;
ptvc->pushed_tree = NULL;
ptvc->pushed_tree_max = 0;
ptvc->pushed_tree_index = 0;
return ptvc;
}
void
ptvcursor_free(ptvcursor_t *ptvc)
{
ptvcursor_free_subtree_levels(ptvc);
}
tvbuff_t *
ptvcursor_tvbuff(ptvcursor_t *ptvc)
{
return ptvc->tvb;
}
gint
ptvcursor_current_offset(ptvcursor_t *ptvc)
{
return ptvc->offset;
}
proto_tree *
ptvcursor_tree(ptvcursor_t *ptvc)
{
if (!ptvc)
return NULL;
return ptvc->tree;
}
void
ptvcursor_set_tree(ptvcursor_t *ptvc, proto_tree *tree)
{
ptvc->tree = tree;
}
proto_tree *
ptvcursor_push_subtree(ptvcursor_t *ptvc, proto_item *it, gint ett_subtree)
{
subtree_lvl *subtree;
if (ptvc->pushed_tree_index >= ptvc->pushed_tree_max)
ptvcursor_new_subtree_levels(ptvc);
subtree = ptvc->pushed_tree + ptvc->pushed_tree_index;
subtree->tree = ptvc->tree;
subtree->it= NULL;
ptvc->pushed_tree_index++;
return ptvcursor_set_subtree(ptvc, it, ett_subtree);
}
void
ptvcursor_pop_subtree(ptvcursor_t *ptvc)
{
subtree_lvl *subtree;
if (ptvc->pushed_tree_index <= 0)
return;
ptvc->pushed_tree_index--;
subtree = ptvc->pushed_tree + ptvc->pushed_tree_index;
if (subtree->it != NULL)
proto_item_set_len(subtree->it, ptvcursor_current_offset(ptvc) - subtree->cursor_offset);
ptvc->tree = subtree->tree;
}
static void
ptvcursor_subtree_set_item(ptvcursor_t *ptvc, proto_item *it)
{
subtree_lvl *subtree;
DISSECTOR_ASSERT(ptvc->pushed_tree_index > 0);
subtree = ptvc->pushed_tree + ptvc->pushed_tree_index - 1;
subtree->it = it;
subtree->cursor_offset = ptvcursor_current_offset(ptvc);
}
proto_tree *
ptvcursor_set_subtree(ptvcursor_t *ptvc, proto_item *it, gint ett_subtree)
{
ptvc->tree = proto_item_add_subtree(it, ett_subtree);
return ptvc->tree;
}
static proto_tree *
ptvcursor_add_subtree_item(ptvcursor_t *ptvc, proto_item *it, gint ett_subtree, gint length)
{
ptvcursor_push_subtree(ptvc, it, ett_subtree);
if (length == SUBTREE_UNDEFINED_LENGTH)
ptvcursor_subtree_set_item(ptvc, it);
return ptvcursor_tree(ptvc);
}
proto_tree *
ptvcursor_add_with_subtree(ptvcursor_t *ptvc, int hfindex, gint length,
const guint encoding, gint ett_subtree)
{
proto_item *it;
it = ptvcursor_add_no_advance(ptvc, hfindex, length, encoding);
return ptvcursor_add_subtree_item(ptvc, it, ett_subtree, length);
}
proto_tree *
ptvcursor_add_text_with_subtree(ptvcursor_t *ptvc, gint length,
gint ett_subtree, const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
proto_tree *tree;
tree = ptvcursor_tree(ptvc);
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hf_text_only, hfinfo);
pi = proto_tree_add_text_node(tree, ptvcursor_tvbuff(ptvc),
ptvcursor_current_offset(ptvc), length);
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return ptvcursor_add_subtree_item(ptvc, pi, ett_subtree, length);
}
static proto_item *
proto_tree_add_text_node(proto_tree *tree, tvbuff_t *tvb, gint start, gint length)
{
proto_item *pi;
if (tree == NULL)
return NULL;
pi = proto_tree_add_pi(tree, &hfi_text_only, tvb, start, &length);
return pi;
}
proto_item *
proto_tree_add_text_internal(proto_tree *tree, tvbuff_t *tvb, gint start, gint length,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
if (tvb) {
if (length == -1) {
length = 0;
}
tvb_ensure_bytes_exist(tvb, start, length);
}
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hf_text_only, hfinfo);
pi = proto_tree_add_text_node(tree, tvb, start, length);
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_text_valist_internal(proto_tree *tree, tvbuff_t *tvb, gint start,
gint length, const char *format, va_list ap)
{
proto_item *pi;
header_field_info *hfinfo;
if (tvb) {
if (length == -1) {
length = 0;
}
tvb_ensure_bytes_exist(tvb, start, length);
}
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hf_text_only, hfinfo);
pi = proto_tree_add_text_node(tree, tvb, start, length);
TRY_TO_FAKE_THIS_REPR(pi);
proto_tree_set_representation(pi, format, ap);
return pi;
}
proto_tree *
proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, gint start, gint length, gint idx, proto_item **tree_item, const char *text)
{
return proto_tree_add_subtree_format(tree, tvb, start, length, idx, tree_item, "%s", text);
}
proto_tree *
proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, gint start, gint length, gint idx, proto_item **tree_item, const char *format, ...)
{
proto_tree *pt;
proto_item *pi;
va_list ap;
va_start(ap, format);
pi = proto_tree_add_text_valist_internal(tree, tvb, start, length, format, ap);
va_end(ap);
if (tree_item != NULL)
*tree_item = pi;
pt = proto_item_add_subtree(pi, idx);
return pt;
}
proto_item *
proto_tree_add_debug_text(proto_tree *tree, const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_text_node(tree, NULL, 0, 0);
if (pi) {
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
va_start(ap, format);
vprintf(format, ap);
va_end(ap);
printf("\n");
return pi;
}
proto_item *
proto_tree_add_format_text(proto_tree *tree, tvbuff_t *tvb, gint start, gint length)
{
proto_item *pi;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hf_text_only, hfinfo);
pi = proto_tree_add_text_node(tree, tvb, start, length);
TRY_TO_FAKE_THIS_REPR(pi);
proto_item_set_text(pi, "%s", tvb_format_text(tvb, start, length));
return pi;
}
proto_item *
proto_tree_add_format_wsp_text(proto_tree *tree, tvbuff_t *tvb, gint start, gint length)
{
proto_item *pi;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hf_text_only, hfinfo);
pi = proto_tree_add_text_node(tree, tvb, start, length);
TRY_TO_FAKE_THIS_REPR(pi);
proto_item_set_text(pi, "%s", tvb_format_text_wsp(tvb, start, length));
return pi;
}
void proto_report_dissector_bug(const char *message)
{
if (getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG") != NULL)
abort();
else
THROW_MESSAGE(DissectorError, message);
}
static void
report_type_length_mismatch(proto_tree *tree, const gchar *descr, int length, gboolean is_error) {
if (is_error) {
expert_add_info_format(NULL, tree, &ei_type_length_mismatch_error, "Trying to fetch %s with length %d", descr, length);
} else {
expert_add_info_format(NULL, tree, &ei_type_length_mismatch_warn, "Trying to fetch %s with length %d", descr, length);
}
if (is_error) {
THROW(ReportedBoundsError);
}
}
static guint32
get_uint_value(proto_tree *tree, tvbuff_t *tvb, gint offset, gint length, const guint encoding)
{
guint32 value;
gboolean length_error;
switch (length) {
case 1:
value = tvb_get_guint8(tvb, offset);
break;
case 2:
value = (encoding & ENC_LITTLE_ENDIAN) ? tvb_get_letohs(tvb, offset)
: tvb_get_ntohs(tvb, offset);
break;
case 3:
value = (encoding & ENC_LITTLE_ENDIAN) ? tvb_get_letoh24(tvb, offset)
: tvb_get_ntoh24(tvb, offset);
break;
case 4:
value = (encoding & ENC_LITTLE_ENDIAN) ? tvb_get_letohl(tvb, offset)
: tvb_get_ntohl(tvb, offset);
break;
default:
if (length < 1) {
length_error = TRUE;
value = 0;
} else {
length_error = FALSE;
value = (encoding & ENC_LITTLE_ENDIAN) ? tvb_get_letohl(tvb, offset)
: tvb_get_ntohl(tvb, offset);
}
report_type_length_mismatch(tree, "an unsigned integer", length, length_error);
break;
}
return value;
}
static inline guint64
get_uint64_value(proto_tree *tree, tvbuff_t *tvb, gint offset, guint length, const guint encoding)
{
guint64 value;
gboolean length_error;
switch (length) {
case 1:
value = tvb_get_guint8(tvb, offset);
break;
case 2:
value = (encoding & ENC_LITTLE_ENDIAN) ? tvb_get_letohs(tvb, offset)
: tvb_get_ntohs(tvb, offset);
break;
case 3:
value = (encoding & ENC_LITTLE_ENDIAN) ? tvb_get_letoh24(tvb, offset)
: tvb_get_ntoh24(tvb, offset);
break;
case 4:
value = (encoding & ENC_LITTLE_ENDIAN) ? tvb_get_letohl(tvb, offset)
: tvb_get_ntohl(tvb, offset);
break;
case 5:
value = (encoding & ENC_LITTLE_ENDIAN) ? tvb_get_letoh40(tvb, offset)
: tvb_get_ntoh40(tvb, offset);
break;
case 6:
value = (encoding & ENC_LITTLE_ENDIAN) ? tvb_get_letoh48(tvb, offset)
: tvb_get_ntoh48(tvb, offset);
break;
case 7:
value = (encoding & ENC_LITTLE_ENDIAN) ? tvb_get_letoh56(tvb, offset)
: tvb_get_ntoh56(tvb, offset);
break;
case 8:
value = (encoding & ENC_LITTLE_ENDIAN) ? tvb_get_letoh64(tvb, offset)
: tvb_get_ntoh64(tvb, offset);
break;
default:
if (length < 1) {
length_error = TRUE;
value = 0;
} else {
length_error = FALSE;
value = (encoding & ENC_LITTLE_ENDIAN) ? tvb_get_letoh64(tvb, offset)
: tvb_get_ntoh64(tvb, offset);
}
report_type_length_mismatch(tree, "an unsigned integer", length, length_error);
break;
}
return value;
}
static gint32
get_int_value(proto_tree *tree, tvbuff_t *tvb, gint offset, gint length, const guint encoding)
{
gint32 value;
gboolean length_error;
switch (length) {
case 1:
value = (gint8)tvb_get_guint8(tvb, offset);
break;
case 2:
value = (gint16) (encoding ? tvb_get_letohs(tvb, offset)
: tvb_get_ntohs(tvb, offset));
break;
case 3:
value = encoding ? tvb_get_letoh24(tvb, offset)
: tvb_get_ntoh24(tvb, offset);
if (value & 0x00800000) {
value |= 0xFF000000;
}
break;
case 4:
value = encoding ? tvb_get_letohl(tvb, offset)
: tvb_get_ntohl(tvb, offset);
break;
default:
if (length < 1) {
length_error = TRUE;
value = 0;
} else {
length_error = FALSE;
value = encoding ? tvb_get_letohl(tvb, offset)
: tvb_get_ntohl(tvb, offset);
}
report_type_length_mismatch(tree, "a signed integer", length, length_error);
break;
}
return value;
}
static inline guint64
get_int64_value(proto_tree *tree, tvbuff_t *tvb, gint start, guint length, const guint encoding)
{
guint64 value = get_uint64_value(tree, tvb, start, length, encoding);
switch(length)
{
case 7:
value = ws_sign_ext64(value, 56);
break;
case 6:
value = ws_sign_ext64(value, 48);
break;
case 5:
value = ws_sign_ext64(value, 40);
break;
case 4:
value = ws_sign_ext64(value, 32);
break;
case 3:
value = ws_sign_ext64(value, 24);
break;
case 2:
value = ws_sign_ext64(value, 16);
break;
case 1:
value = ws_sign_ext64(value, 8);
break;
}
return value;
}
static inline const guint8 *
get_string_value(wmem_allocator_t *scope, tvbuff_t *tvb, gint start,
gint length, gint *ret_length, const guint encoding)
{
if (length == -1) {
length = tvb_ensure_captured_length_remaining(tvb, start);
}
*ret_length = length;
return tvb_get_string_enc(scope, tvb, start, length, encoding);
}
static inline const guint8 *
get_stringz_value(wmem_allocator_t *scope, proto_tree *tree, tvbuff_t *tvb,
gint start, gint length, gint *ret_length, const guint encoding)
{
const guint8 *value;
if (length < -1) {
report_type_length_mismatch(tree, "a string", length, TRUE);
}
if (length == -1) {
value = tvb_get_stringz_enc(scope, tvb, start, &length, encoding);
} else if (length == 0) {
value = "[Empty]";
} else {
value = tvb_get_string_enc(scope, tvb, start, length, encoding);
}
*ret_length = length;
return value;
}
static inline const guint8 *
get_uint_string_value(wmem_allocator_t *scope, proto_tree *tree,
tvbuff_t *tvb, gint start, gint length, gint *ret_length,
const guint encoding)
{
guint32 n;
const guint8 *value;
n = get_uint_value(tree, tvb, start, length, encoding & ~ENC_CHARENCODING_MASK);
value = tvb_get_string_enc(scope, tvb, start + length, n, encoding);
length += n;
*ret_length = length;
return value;
}
static inline const guint8 *
get_stringzpad_value(wmem_allocator_t *scope, tvbuff_t *tvb, gint start,
gint length, gint *ret_length, const guint encoding)
{
if (length == -1) {
length = tvb_ensure_captured_length_remaining(tvb, start);
}
*ret_length = length;
return tvb_get_string_enc(scope, tvb, start, length, encoding);
}
static void
get_time_value(tvbuff_t *tvb, const gint start, const gint length, const guint encoding,
nstime_t *time_stamp, const gboolean is_relative)
{
guint32 tmpsecs;
guint64 todsecs;
if (is_relative &&
(encoding != (ENC_TIME_TIMESPEC|ENC_BIG_ENDIAN)) &&
(encoding != (ENC_TIME_TIMESPEC|ENC_LITTLE_ENDIAN)) )
{
return;
}
switch (encoding) {
case ENC_TIME_TIMESPEC|ENC_BIG_ENDIAN:
time_stamp->secs = (time_t)tvb_get_ntohl(tvb, start);
if (length == 8)
time_stamp->nsecs = tvb_get_ntohl(tvb, start+4);
else
time_stamp->nsecs = 0;
break;
case ENC_TIME_TIMESPEC|ENC_LITTLE_ENDIAN:
time_stamp->secs = (time_t)tvb_get_letohl(tvb, start);
if (length == 8)
time_stamp->nsecs = tvb_get_letohl(tvb, start+4);
else
time_stamp->nsecs = 0;
break;
case ENC_TIME_TOD|ENC_BIG_ENDIAN:
#define TOD_BASETIME G_GUINT64_CONSTANT(2208988800)
todsecs = tvb_get_ntoh64(tvb, start) >> 12;
time_stamp->secs = (time_t)((todsecs / 1000000) - TOD_BASETIME);
time_stamp->nsecs = (int)((todsecs % 1000000) * 1000);
break;
case ENC_TIME_TOD|ENC_LITTLE_ENDIAN:
todsecs = tvb_get_letoh64(tvb, start) >> 12 ;
time_stamp->secs = (time_t)((todsecs / 1000000) - TOD_BASETIME);
time_stamp->nsecs = (int)((todsecs % 1000000) * 1000);
break;
case ENC_TIME_NTP|ENC_BIG_ENDIAN:
#define NTP_BASETIME G_GUINT64_CONSTANT(2208988800)
tmpsecs = tvb_get_ntohl(tvb, start);
if (tmpsecs)
time_stamp->secs = (time_t)(tmpsecs - (guint32)NTP_BASETIME);
else
time_stamp->secs = tmpsecs;
if (length == 8) {
time_stamp->nsecs = (int)(1000000*(tvb_get_ntohl(tvb, start+4)/4294967296.0));
time_stamp->nsecs *= 1000;
} else {
time_stamp->nsecs = 0;
}
break;
case ENC_TIME_NTP|ENC_LITTLE_ENDIAN:
tmpsecs = tvb_get_letohl(tvb, start);
if (tmpsecs)
time_stamp->secs = (time_t)(tmpsecs - (guint32)NTP_BASETIME);
else
time_stamp->secs = tmpsecs;
if (length == 8) {
time_stamp->nsecs = (int)(1000000*(tvb_get_letohl(tvb, start+4)/4294967296.0));
time_stamp->nsecs *= 1000;
} else {
time_stamp->nsecs = 0;
}
break;
case ENC_TIME_NTP_BASE_ZERO|ENC_BIG_ENDIAN:
#define NTP_BASETIME_ZERO G_GUINT64_CONSTANT(0)
tmpsecs = tvb_get_ntohl(tvb, start);
if (tmpsecs)
time_stamp->secs = (time_t)(tmpsecs - (guint32)NTP_BASETIME_ZERO);
else
time_stamp->secs = tmpsecs;
if (length == 8) {
time_stamp->nsecs = (int)(1000000*(tvb_get_ntohl(tvb, start+4)/4294967296.0));
time_stamp->nsecs *= 1000;
} else {
time_stamp->nsecs = 0;
}
break;
case ENC_TIME_NTP_BASE_ZERO|ENC_LITTLE_ENDIAN:
tmpsecs = tvb_get_letohl(tvb, start);
if (tmpsecs)
time_stamp->secs = (time_t)(tmpsecs - (guint32)NTP_BASETIME_ZERO);
else
time_stamp->secs = tmpsecs;
time_stamp->secs = (time_t)tvb_get_letohl(tvb, start);
if (length == 8) {
time_stamp->nsecs = (int)(1000000*(tvb_get_letohl(tvb, start+4)/4294967296.0));
time_stamp->nsecs *= 1000;
} else {
time_stamp->nsecs = 0;
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
static void
tree_data_add_maybe_interesting_field(tree_data_t *tree_data, field_info *fi)
{
const header_field_info *hfinfo = fi->hfinfo;
if (hfinfo->ref_type == HF_REF_TYPE_DIRECT) {
GPtrArray *ptrs = NULL;
if (tree_data->interesting_hfids == NULL) {
tree_data->interesting_hfids =
g_hash_table_new(g_direct_hash, NULL );
} else if (g_hash_table_size(tree_data->interesting_hfids)) {
ptrs = (GPtrArray *)g_hash_table_lookup(tree_data->interesting_hfids,
GINT_TO_POINTER(hfinfo->id));
}
if (!ptrs) {
ptrs = g_ptr_array_new();
g_hash_table_insert(tree_data->interesting_hfids,
GINT_TO_POINTER(hfinfo->id), ptrs);
}
g_ptr_array_add(ptrs, fi);
}
}
static proto_item *
proto_tree_new_item(field_info *new_fi, proto_tree *tree,
tvbuff_t *tvb, gint start, gint length,
guint encoding)
{
proto_item *pi;
guint32 value, n;
float floatval;
double doubleval;
const char *stringval;
nstime_t time_stamp;
gboolean length_error;
switch (new_fi->hfinfo->type) {
case FT_NONE:
break;
case FT_PROTOCOL:
proto_tree_set_protocol_tvb(new_fi, tvb, new_fi->hfinfo->name);
break;
case FT_BYTES:
proto_tree_set_bytes_tvb(new_fi, tvb, start, length);
break;
case FT_UINT_BYTES:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
n = get_uint_value(tree, tvb, start, length, encoding);
proto_tree_set_bytes_tvb(new_fi, tvb, start + length, n);
new_fi->length = n + length;
break;
case FT_BOOLEAN:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
proto_tree_set_boolean(new_fi,
get_uint64_value(tree, tvb, start, length, encoding));
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
proto_tree_set_uint(new_fi,
get_uint_value(tree, tvb, start, length, encoding));
break;
case FT_UINT40:
case FT_UINT48:
case FT_UINT56:
case FT_UINT64:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
proto_tree_set_uint64(new_fi,
get_uint64_value(tree, tvb, start, length, encoding));
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
proto_tree_set_int(new_fi,
get_int_value(tree, tvb, start, length, encoding));
break;
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_INT64:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
proto_tree_set_int64(new_fi,
get_int64_value(tree, tvb, start, length, encoding));
break;
case FT_IPv4:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
if (length != FT_IPv4_LEN) {
length_error = length < FT_IPv4_LEN ? TRUE : FALSE;
report_type_length_mismatch(tree, "an IPv4 address", length, length_error);
}
value = tvb_get_ipv4(tvb, start);
proto_tree_set_ipv4(new_fi, encoding ? GUINT32_SWAP_LE_BE(value) : value);
break;
case FT_IPXNET:
if (length != FT_IPXNET_LEN) {
length_error = length < FT_IPXNET_LEN ? TRUE : FALSE;
report_type_length_mismatch(tree, "an IPXNET address", length, length_error);
}
proto_tree_set_ipxnet(new_fi,
get_uint_value(tree, tvb, start, FT_IPXNET_LEN, ENC_BIG_ENDIAN));
break;
case FT_IPv6:
if (length != FT_IPv6_LEN) {
length_error = length < FT_IPv6_LEN ? TRUE : FALSE;
report_type_length_mismatch(tree, "an IPv6 address", length, length_error);
}
proto_tree_set_ipv6_tvb(new_fi, tvb, start, length);
break;
case FT_FCWWN:
if (length != FT_FCWWN_LEN) {
length_error = length < FT_FCWWN_LEN ? TRUE : FALSE;
report_type_length_mismatch(tree, "an FCWWN address", length, length_error);
}
proto_tree_set_fcwwn_tvb(new_fi, tvb, start, length);
break;
case FT_AX25:
if (length != 7) {
length_error = length < 7 ? TRUE : FALSE;
report_type_length_mismatch(tree, "an AX.25 address", length, length_error);
}
proto_tree_set_ax25_tvb(new_fi, tvb, start);
break;
case FT_VINES:
if (length != VINES_ADDR_LEN) {
length_error = length < VINES_ADDR_LEN ? TRUE : FALSE;
report_type_length_mismatch(tree, "a Vines address", length, length_error);
}
proto_tree_set_vines_tvb(new_fi, tvb, start);
break;
case FT_ETHER:
if (length != FT_ETHER_LEN) {
length_error = length < FT_ETHER_LEN ? TRUE : FALSE;
report_type_length_mismatch(tree, "a MAC address", length, length_error);
}
proto_tree_set_ether_tvb(new_fi, tvb, start);
break;
case FT_EUI64:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
if (length != FT_EUI64_LEN) {
length_error = length < FT_EUI64_LEN ? TRUE : FALSE;
report_type_length_mismatch(tree, "an EUI-64 address", length, length_error);
}
proto_tree_set_eui64_tvb(new_fi, tvb, start, encoding);
break;
case FT_GUID:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
if (length != FT_GUID_LEN) {
length_error = length < FT_GUID_LEN ? TRUE : FALSE;
report_type_length_mismatch(tree, "a GUID", length, length_error);
}
proto_tree_set_guid_tvb(new_fi, tvb, start, encoding);
break;
case FT_OID:
case FT_REL_OID:
proto_tree_set_oid_tvb(new_fi, tvb, start, length);
break;
case FT_SYSTEM_ID:
proto_tree_set_system_id_tvb(new_fi, tvb, start, length);
break;
case FT_FLOAT:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
if (length != 4) {
length_error = length < 4 ? TRUE : FALSE;
report_type_length_mismatch(tree, "a single-precision floating point number", length, length_error);
}
if (encoding)
floatval = tvb_get_letohieee_float(tvb, start);
else
floatval = tvb_get_ntohieee_float(tvb, start);
proto_tree_set_float(new_fi, floatval);
break;
case FT_DOUBLE:
if (encoding == TRUE)
encoding = ENC_LITTLE_ENDIAN;
if (length != 8) {
length_error = length < 8 ? TRUE : FALSE;
report_type_length_mismatch(tree, "a double-precision floating point number", length, length_error);
}
if (encoding)
doubleval = tvb_get_letohieee_double(tvb, start);
else
doubleval = tvb_get_ntohieee_double(tvb, start);
proto_tree_set_double(new_fi, doubleval);
break;
case FT_STRING:
stringval = get_string_value(wmem_packet_scope(),
tvb, start, length, &length, encoding);
proto_tree_set_string(new_fi, stringval);
new_fi->length = length;
break;
case FT_STRINGZ:
stringval = get_stringz_value(wmem_packet_scope(),
tree, tvb, start, length, &length, encoding);
proto_tree_set_string(new_fi, stringval);
new_fi->length = length;
break;
case FT_UINT_STRING:
if (encoding == TRUE)
encoding = ENC_ASCII|ENC_LITTLE_ENDIAN;
stringval = get_uint_string_value(wmem_packet_scope(),
tree, tvb, start, length, &length, encoding);
proto_tree_set_string(new_fi, stringval);
new_fi->length = length;
break;
case FT_STRINGZPAD:
stringval = get_stringzpad_value(wmem_packet_scope(),
tvb, start, length, &length, encoding);
proto_tree_set_string(new_fi, stringval);
new_fi->length = length;
break;
case FT_ABSOLUTE_TIME:
if (encoding == TRUE)
encoding = ENC_TIME_TIMESPEC|ENC_LITTLE_ENDIAN;
if (length != 8 && length != 4) {
length_error = length < 4 ? TRUE : FALSE;
report_type_length_mismatch(tree, "an absolute time value", length, length_error);
}
get_time_value(tvb, start, length, encoding, &time_stamp, FALSE);
proto_tree_set_time(new_fi, &time_stamp);
break;
case FT_RELATIVE_TIME:
if (encoding == TRUE)
encoding = ENC_TIME_TIMESPEC|ENC_LITTLE_ENDIAN;
if (length != 8 && length != 4) {
length_error = length < 4 ? TRUE : FALSE;
report_type_length_mismatch(tree, "a relative time value", length, length_error);
}
get_time_value(tvb, start, length, encoding, &time_stamp, TRUE);
proto_tree_set_time(new_fi, &time_stamp);
break;
case FT_IEEE_11073_SFLOAT:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
if (length != 2) {
length_error = length < 2 ? TRUE : FALSE;
report_type_length_mismatch(tree, "a IEEE 11073 SFLOAT", length, length_error);
}
fvalue_set_uinteger(&new_fi->value, tvb_get_guint16(tvb, start, encoding));
break;
case FT_IEEE_11073_FLOAT:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
if (length != 4) {
length_error = length < 4 ? TRUE : FALSE;
report_type_length_mismatch(tree, "a IEEE 11073 FLOAT", length, length_error);
}
break;
default:
g_error("new_fi->hfinfo->type %d (%s) not handled\n",
new_fi->hfinfo->type,
ftype_name(new_fi->hfinfo->type));
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
FI_SET_FLAG(new_fi, (encoding & ENC_LITTLE_ENDIAN) ? FI_LITTLE_ENDIAN : FI_BIG_ENDIAN);
pi = proto_tree_add_node(tree, new_fi);
return pi;
}
proto_item *
proto_tree_add_item_ret_int(proto_tree *tree, int hfindex, tvbuff_t *tvb,
const gint start, gint length,
const guint encoding, gint32 *retval)
{
header_field_info *hfinfo = proto_registrar_get_nth(hfindex);
field_info *new_fi;
gint32 value;
DISSECTOR_ASSERT_HINT(hfinfo != NULL, "Not passed hfi!");
switch (hfinfo->type){
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
if (length < -1 || length == 0)
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"Invalid length %d passed to proto_tree_add_item_ret_int",
length));
if (encoding & ENC_STRING) {
REPORT_DISSECTOR_BUG("wrong encoding");
}
value = get_int_value(tree, tvb, start, length, encoding);
if (retval)
*retval = value;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfinfo->id, hfinfo);
new_fi = new_field_info(tree, hfinfo, tvb, start, length);
proto_tree_set_int(new_fi, value);
new_fi->flags |= (encoding & ENC_LITTLE_ENDIAN) ? FI_LITTLE_ENDIAN : FI_BIG_ENDIAN;
return proto_tree_add_node(tree, new_fi);
}
proto_item *
proto_tree_add_item_ret_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb,
const gint start, gint length,
const guint encoding, guint32 *retval)
{
header_field_info *hfinfo = proto_registrar_get_nth(hfindex);
field_info *new_fi;
guint32 value;
DISSECTOR_ASSERT_HINT(hfinfo != NULL, "Not passed hfi!");
switch (hfinfo->type){
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
if (length < -1 || length == 0)
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"Invalid length %d passed to proto_tree_add_item_ret_uint",
length));
if (encoding & ENC_STRING) {
REPORT_DISSECTOR_BUG("wrong encoding");
}
value = get_uint_value(tree, tvb, start, length, encoding);
if (retval)
*retval = value;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfinfo->id, hfinfo);
new_fi = new_field_info(tree, hfinfo, tvb, start, length);
proto_tree_set_uint(new_fi, value);
new_fi->flags |= (encoding & ENC_LITTLE_ENDIAN) ? FI_LITTLE_ENDIAN : FI_BIG_ENDIAN;
return proto_tree_add_node(tree, new_fi);
}
proto_item *
proto_tree_add_item_ret_string_and_length(proto_tree *tree, int hfindex,
tvbuff_t *tvb,
const gint start, gint length,
const guint encoding,
wmem_allocator_t *scope,
const guint8 **retval,
gint *lenretval)
{
header_field_info *hfinfo = proto_registrar_get_nth(hfindex);
field_info *new_fi;
const guint8 *value;
DISSECTOR_ASSERT_HINT(hfinfo != NULL, "Not passed hfi!");
switch (hfinfo->type){
case FT_STRING:
value = get_string_value(scope, tvb, start, length, lenretval, encoding);
break;
case FT_STRINGZ:
value = get_stringz_value(scope, tree, tvb, start, length, lenretval, encoding);
break;
case FT_UINT_STRING:
value = get_uint_string_value(scope, tree, tvb, start, length, lenretval, encoding);
break;
case FT_STRINGZPAD:
value = get_stringzpad_value(scope, tvb, start, length, lenretval, encoding);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
if (retval)
*retval = value;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfinfo->id, hfinfo);
new_fi = new_field_info(tree, hfinfo, tvb, start, length);
proto_tree_set_string(new_fi, value);
new_fi->flags |= (encoding & ENC_LITTLE_ENDIAN) ? FI_LITTLE_ENDIAN : FI_BIG_ENDIAN;
return proto_tree_add_node(tree, new_fi);
}
proto_item *
proto_tree_add_item_ret_string(proto_tree *tree, int hfindex, tvbuff_t *tvb,
const gint start, gint length,
const guint encoding, wmem_allocator_t *scope,
const guint8 **retval)
{
return proto_tree_add_item_ret_string_and_length(tree, hfindex,
tvb, start, length, encoding, scope, retval, &length);
}
static void
test_length(header_field_info *hfinfo, tvbuff_t *tvb,
gint start, gint length)
{
gint size = length;
if (!tvb)
return;
if (hfinfo->type == FT_STRINGZ) {
if (length == -1)
size = 0;
}
tvb_ensure_bytes_exist(tvb, start, size);
}
proto_item *
ptvcursor_add(ptvcursor_t *ptvc, int hfindex, gint length,
const guint encoding)
{
field_info *new_fi;
header_field_info *hfinfo;
gint item_length;
int offset;
offset = ptvc->offset;
PROTO_REGISTRAR_GET_NTH(hfindex, hfinfo);
get_hfi_length(hfinfo, ptvc->tvb, offset, &length, &item_length);
test_length(hfinfo, ptvc->tvb, offset, item_length);
ptvc->offset += get_full_length(hfinfo, ptvc->tvb, offset, length,
item_length, encoding);
CHECK_FOR_NULL_TREE(ptvc->tree);
TRY_TO_FAKE_THIS_ITEM(ptvc->tree, hfindex, hfinfo);
new_fi = new_field_info(ptvc->tree, hfinfo, ptvc->tvb, offset, item_length);
return proto_tree_new_item(new_fi, ptvc->tree, ptvc->tvb,
offset, length, encoding);
}
proto_item *
proto_tree_add_item_new(proto_tree *tree, header_field_info *hfinfo, tvbuff_t *tvb,
const gint start, gint length, const guint encoding)
{
field_info *new_fi;
gint item_length;
DISSECTOR_ASSERT_HINT(hfinfo != NULL, "Not passed hfi!");
get_hfi_length(hfinfo, tvb, start, &length, &item_length);
test_length(hfinfo, tvb, start, item_length);
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfinfo->id, hfinfo);
new_fi = new_field_info(tree, hfinfo, tvb, start, item_length);
return proto_tree_new_item(new_fi, tree, tvb, start, length, encoding);
}
proto_item *
proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb,
const gint start, gint length, const guint encoding)
{
register header_field_info *hfinfo;
PROTO_REGISTRAR_GET_NTH(hfindex, hfinfo);
return proto_tree_add_item_new(tree, hfinfo, tvb, start, length, encoding);
}
proto_item *
proto_tree_add_item_new_ret_length(proto_tree *tree, header_field_info *hfinfo,
tvbuff_t *tvb, const gint start,
gint length, const guint encoding,
gint *lenretval)
{
field_info *new_fi;
gint item_length;
proto_item *item;
DISSECTOR_ASSERT_HINT(hfinfo != NULL, "Not passed hfi!");
get_hfi_length(hfinfo, tvb, start, &length, &item_length);
test_length(hfinfo, tvb, start, item_length);
if (!tree) {
*lenretval = get_full_length(hfinfo, tvb, start, length,
item_length, encoding);
return NULL;
}
TRY_TO_FAKE_THIS_ITEM(tree, hfinfo->id, hfinfo);
new_fi = new_field_info(tree, hfinfo, tvb, start, item_length);
item = proto_tree_new_item(new_fi, tree, tvb, start, length, encoding);
*lenretval = new_fi->length;
return item;
}
proto_item *
proto_tree_add_item_ret_length(proto_tree *tree, int hfindex, tvbuff_t *tvb,
const gint start, gint length,
const guint encoding, gint *lenretval)
{
register header_field_info *hfinfo;
PROTO_REGISTRAR_GET_NTH(hfindex, hfinfo);
return proto_tree_add_item_new_ret_length(tree, hfinfo, tvb, start, length, encoding, lenretval);
}
static inline gboolean
validate_proto_tree_add_bytes_ftype(const enum ftenum type)
{
return (type == FT_BYTES ||
type == FT_UINT_BYTES ||
type == FT_OID ||
type == FT_REL_OID ||
type == FT_SYSTEM_ID );
}
proto_item *
proto_tree_add_bytes_item(proto_tree *tree, int hfindex, tvbuff_t *tvb,
const gint start, gint length, const guint encoding,
GByteArray *retval, gint *endoff, gint *err)
{
field_info *new_fi;
GByteArray *bytes = retval;
GByteArray *created_bytes = NULL;
gint saved_err = 0;
guint32 n = 0;
header_field_info *hfinfo;
gboolean generate = (bytes || tree) ? TRUE : FALSE;
PROTO_REGISTRAR_GET_NTH(hfindex, hfinfo);
DISSECTOR_ASSERT_HINT(hfinfo != NULL, "Not passed hfi!");
DISSECTOR_ASSERT_HINT(validate_proto_tree_add_bytes_ftype(hfinfo->type),
"Called proto_tree_add_bytes_item but not a bytes-based FT_XXX type");
if (length < -1 || length == 0) {
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"Invalid length %d passed to proto_tree_add_bytes_item for %s",
length, ftype_name(hfinfo->type)));
}
if (encoding & ENC_STR_NUM) {
REPORT_DISSECTOR_BUG("Decoding number strings for byte arrays is not supported");
}
if (generate && (encoding & ENC_STR_HEX)) {
if (hfinfo->type == FT_UINT_BYTES) {
REPORT_DISSECTOR_BUG("proto_tree_add_bytes_item called for "
"FT_UINT_BYTES type, but as ENC_STR_HEX");
}
if (!bytes) {
bytes = created_bytes = g_byte_array_new();
}
bytes = tvb_get_string_bytes(tvb, start, length, encoding, bytes, endoff);
saved_err = errno;
}
else if (generate) {
tvb_ensure_bytes_exist(tvb, start, length);
if (!bytes) {
bytes = created_bytes = g_byte_array_new();
}
if (hfinfo->type == FT_UINT_BYTES) {
n = length;
length = get_uint_value(tree, tvb, start, n, encoding);
g_byte_array_append(bytes, tvb_get_ptr(tvb, start + n, length), length);
}
else if (length > 0) {
g_byte_array_append(bytes, tvb_get_ptr(tvb, start, length), length);
}
if (endoff)
*endoff = start + n + length;
}
if (err) *err = saved_err;
CHECK_FOR_NULL_TREE_AND_FREE(tree,
{
if (created_bytes)
g_byte_array_free(created_bytes, TRUE);
created_bytes = NULL;
bytes = NULL;
} );
TRY_TO_FAKE_THIS_ITEM_OR_FREE(tree, hfinfo->id, hfinfo,
{
if (created_bytes)
g_byte_array_free(created_bytes, TRUE);
created_bytes = NULL;
bytes = NULL;
} );
new_fi = new_field_info(tree, hfinfo, tvb, start, n + length);
if (encoding & ENC_STRING) {
if (saved_err == ERANGE)
expert_add_info(NULL, tree, &ei_number_string_decoding_erange_error);
else if (!bytes || saved_err != 0)
expert_add_info(NULL, tree, &ei_number_string_decoding_failed_error);
if (bytes)
proto_tree_set_bytes_gbytearray(new_fi, bytes);
else
proto_tree_set_bytes(new_fi, NULL, 0);
if (created_bytes)
g_byte_array_free(created_bytes, TRUE);
}
else {
proto_tree_set_bytes_tvb(new_fi, tvb, start + n, length);
FI_SET_FLAG(new_fi,
(encoding & ENC_LITTLE_ENDIAN) ? FI_LITTLE_ENDIAN : FI_BIG_ENDIAN);
}
return proto_tree_add_node(tree, new_fi);
}
proto_item *
proto_tree_add_time_item(proto_tree *tree, int hfindex, tvbuff_t *tvb,
const gint start, gint length, const guint encoding,
nstime_t *retval, gint *endoff, gint *err)
{
field_info *new_fi;
nstime_t time_stamp;
gint saved_err = 0;
header_field_info *hfinfo;
PROTO_REGISTRAR_GET_NTH(hfindex, hfinfo);
DISSECTOR_ASSERT_HINT(hfinfo != NULL, "Not passed hfi!");
DISSECTOR_ASSERT_FIELD_TYPE_IS_TIME(hfinfo);
if (length < -1 || length == 0) {
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"Invalid length %d passed to proto_tree_add_time_item", length));
}
time_stamp.secs = 0;
time_stamp.nsecs = 0;
if (encoding & ENC_STR_TIME_MASK) {
tvb_get_string_time(tvb, start, length, encoding, &time_stamp, endoff);
saved_err = errno;
}
else {
const gboolean is_relative = (hfinfo->type == FT_RELATIVE_TIME) ? TRUE : FALSE;
if (length != 8 && length != 4) {
const gboolean length_error = length < 4 ? TRUE : FALSE;
if (is_relative)
report_type_length_mismatch(tree, "a relative time value", length, length_error);
else
report_type_length_mismatch(tree, "an absolute time value", length, length_error);
}
tvb_ensure_bytes_exist(tvb, start, length);
get_time_value(tvb, start, length, encoding, &time_stamp, is_relative);
if (endoff) *endoff = length;
}
if (err) *err = saved_err;
if (retval) {
retval->secs = time_stamp.secs;
retval->nsecs = time_stamp.nsecs;
}
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfinfo->id, hfinfo);
new_fi = new_field_info(tree, hfinfo, tvb, start, length);
proto_tree_set_time(new_fi, &time_stamp);
if (encoding & ENC_STRING) {
if (saved_err == ERANGE)
expert_add_info(NULL, tree, &ei_number_string_decoding_erange_error);
else if (saved_err == EDOM)
expert_add_info(NULL, tree, &ei_number_string_decoding_failed_error);
}
else {
FI_SET_FLAG(new_fi,
(encoding & ENC_LITTLE_ENDIAN) ? FI_LITTLE_ENDIAN : FI_BIG_ENDIAN);
}
return proto_tree_add_node(tree, new_fi);
}
proto_item *
proto_tree_add_none_format(proto_tree *tree, const int hfindex, tvbuff_t *tvb,
const gint start, gint length, const char *format,
...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_NONE);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
ptvcursor_add_no_advance(ptvcursor_t* ptvc, int hf, gint length,
const guint encoding)
{
proto_item *item;
item = proto_tree_add_item(ptvc->tree, hf, ptvc->tvb, ptvc->offset,
length, encoding);
return item;
}
void
ptvcursor_advance(ptvcursor_t* ptvc, gint length)
{
ptvc->offset += length;
}
static void
proto_tree_set_protocol_tvb(field_info *fi, tvbuff_t *tvb, const char* field_data)
{
fvalue_set_protocol(&fi->value, tvb, field_data);
}
proto_item *
proto_tree_add_protocol_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
gchar* protocol_rep;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_PROTOCOL);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
va_start(ap, format);
protocol_rep = g_strdup_vprintf(format, ap);
proto_tree_set_protocol_tvb(PNODE_FINFO(pi), (start == 0 ? tvb : tvb_new_subset_length(tvb, start, length)), protocol_rep);
g_free(protocol_rep);
va_end(ap);
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_bytes(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, const guint8 *start_ptr)
{
proto_item *pi;
header_field_info *hfinfo;
gint item_length;
PROTO_REGISTRAR_GET_NTH(hfindex, hfinfo);
get_hfi_length(hfinfo, tvb, start, &length, &item_length);
test_length(hfinfo, tvb, start, item_length);
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_BYTES);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_bytes(PNODE_FINFO(pi), start_ptr, length);
return pi;
}
proto_item *
proto_tree_add_bytes_with_length(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint tvbuff_length, const guint8 *start_ptr, gint ptr_length)
{
proto_item *pi;
header_field_info *hfinfo;
gint item_length;
PROTO_REGISTRAR_GET_NTH(hfindex, hfinfo);
get_hfi_length(hfinfo, tvb, start, &tvbuff_length, &item_length);
test_length(hfinfo, tvb, start, item_length);
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_BYTES);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &tvbuff_length);
proto_tree_set_bytes(PNODE_FINFO(pi), start_ptr, ptr_length);
return pi;
}
proto_item *
proto_tree_add_bytes_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length,
const guint8 *start_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
gint item_length;
PROTO_REGISTRAR_GET_NTH(hfindex, hfinfo);
get_hfi_length(hfinfo, tvb, start, &length, &item_length);
test_length(hfinfo, tvb, start, item_length);
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
if (start_ptr)
pi = proto_tree_add_bytes(tree, hfindex, tvb, start, length,
start_ptr);
else
pi = proto_tree_add_bytes(tree, hfindex, tvb, start, length,
tvb_get_ptr(tvb, start, length));
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_bytes_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const guint8 *start_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
gint item_length;
PROTO_REGISTRAR_GET_NTH(hfindex, hfinfo);
get_hfi_length(hfinfo, tvb, start, &length, &item_length);
test_length(hfinfo, tvb, start, item_length);
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
if (start_ptr)
pi = proto_tree_add_bytes(tree, hfindex, tvb, start, length,
start_ptr);
else
pi = proto_tree_add_bytes(tree, hfindex, tvb, start, length,
tvb_get_ptr(tvb, start, length));
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
static void
proto_tree_set_bytes(field_info *fi, const guint8* start_ptr, gint length)
{
GByteArray *bytes;
DISSECTOR_ASSERT(start_ptr != NULL || length == 0);
bytes = g_byte_array_new();
if (length > 0) {
g_byte_array_append(bytes, start_ptr, length);
}
fvalue_set_byte_array(&fi->value, bytes);
}
static void
proto_tree_set_bytes_tvb(field_info *fi, tvbuff_t *tvb, gint offset, gint length)
{
proto_tree_set_bytes(fi, tvb_get_ptr(tvb, offset, length), length);
}
static void
proto_tree_set_bytes_gbytearray(field_info *fi, const GByteArray *value)
{
GByteArray *bytes;
DISSECTOR_ASSERT(value != NULL);
bytes = byte_array_dup(value);
fvalue_set_byte_array(&fi->value, bytes);
}
proto_item *
proto_tree_add_time(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, const nstime_t *value_ptr)
{
proto_item *pi;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE_IS_TIME(hfinfo);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_time(PNODE_FINFO(pi), value_ptr);
return pi;
}
proto_item *
proto_tree_add_time_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, nstime_t *value_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_time(tree, hfindex, tvb, start, length, value_ptr);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_time_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, nstime_t *value_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_time(tree, hfindex, tvb, start, length, value_ptr);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
static void
proto_tree_set_time(field_info *fi, const nstime_t *value_ptr)
{
DISSECTOR_ASSERT(value_ptr != NULL);
fvalue_set_time(&fi->value, value_ptr);
}
proto_item *
proto_tree_add_ipxnet(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, guint32 value)
{
proto_item *pi;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_IPXNET);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_ipxnet(PNODE_FINFO(pi), value);
return pi;
}
proto_item *
proto_tree_add_ipxnet_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint32 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_ipxnet(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_ipxnet_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint32 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_ipxnet(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
static void
proto_tree_set_ipxnet(field_info *fi, guint32 value)
{
fvalue_set_uinteger(&fi->value, value);
}
proto_item *
proto_tree_add_ipv4(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, guint32 value)
{
proto_item *pi;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_IPv4);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_ipv4(PNODE_FINFO(pi), value);
return pi;
}
proto_item *
proto_tree_add_ipv4_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint32 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_ipv4(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_ipv4_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint32 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_ipv4(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
static void
proto_tree_set_ipv4(field_info *fi, guint32 value)
{
fvalue_set_uinteger(&fi->value, value);
}
proto_item *
proto_tree_add_ipv6(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, const struct e_in6_addr *value_ptr)
{
proto_item *pi;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_IPv6);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_ipv6(PNODE_FINFO(pi), value_ptr->bytes);
return pi;
}
proto_item *
proto_tree_add_ipv6_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length,
const struct e_in6_addr *value_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_ipv6(tree, hfindex, tvb, start, length, value_ptr);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_ipv6_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length,
const struct e_in6_addr *value_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_ipv6(tree, hfindex, tvb, start, length, value_ptr);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
static void
proto_tree_set_ipv6(field_info *fi, const guint8* value_ptr)
{
DISSECTOR_ASSERT(value_ptr != NULL);
fvalue_set_bytes(&fi->value, value_ptr);
}
static void
proto_tree_set_ipv6_tvb(field_info *fi, tvbuff_t *tvb, gint start, gint length)
{
proto_tree_set_ipv6(fi, tvb_get_ptr(tvb, start, length));
}
static void
proto_tree_set_fcwwn(field_info *fi, const guint8* value_ptr)
{
DISSECTOR_ASSERT(value_ptr != NULL);
fvalue_set_bytes(&fi->value, value_ptr);
}
static void
proto_tree_set_fcwwn_tvb(field_info *fi, tvbuff_t *tvb, gint start, gint length)
{
proto_tree_set_fcwwn(fi, tvb_get_ptr(tvb, start, length));
}
proto_item *
proto_tree_add_guid(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, const e_guid_t *value_ptr)
{
proto_item *pi;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_GUID);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_guid(PNODE_FINFO(pi), value_ptr);
return pi;
}
proto_item *
proto_tree_add_guid_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length,
const e_guid_t *value_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_guid(tree, hfindex, tvb, start, length, value_ptr);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_guid_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const e_guid_t *value_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_guid(tree, hfindex, tvb, start, length, value_ptr);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
static void
proto_tree_set_guid(field_info *fi, const e_guid_t *value_ptr)
{
DISSECTOR_ASSERT(value_ptr != NULL);
fvalue_set_guid(&fi->value, value_ptr);
}
static void
proto_tree_set_guid_tvb(field_info *fi, tvbuff_t *tvb, gint start,
const guint encoding)
{
e_guid_t guid;
tvb_get_guid(tvb, start, &guid, encoding);
proto_tree_set_guid(fi, &guid);
}
proto_item *
proto_tree_add_oid(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, const guint8* value_ptr)
{
proto_item *pi;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_OID);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_oid(PNODE_FINFO(pi), value_ptr, length);
return pi;
}
proto_item *
proto_tree_add_oid_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length,
const guint8* value_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_oid(tree, hfindex, tvb, start, length, value_ptr);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_oid_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const guint8* value_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_oid(tree, hfindex, tvb, start, length, value_ptr);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
static void
proto_tree_set_oid(field_info *fi, const guint8* value_ptr, gint length)
{
GByteArray *bytes;
DISSECTOR_ASSERT(value_ptr != NULL || length == 0);
bytes = g_byte_array_new();
if (length > 0) {
g_byte_array_append(bytes, value_ptr, length);
}
fvalue_set_byte_array(&fi->value, bytes);
}
static void
proto_tree_set_oid_tvb(field_info *fi, tvbuff_t *tvb, gint start, gint length)
{
proto_tree_set_oid(fi, tvb_get_ptr(tvb, start, length), length);
}
static void
proto_tree_set_system_id(field_info *fi, const guint8* value_ptr, gint length)
{
GByteArray *bytes;
DISSECTOR_ASSERT(value_ptr != NULL || length == 0);
bytes = g_byte_array_new();
if (length > 0) {
g_byte_array_append(bytes, value_ptr, length);
}
fvalue_set_byte_array(&fi->value, bytes);
}
static void
proto_tree_set_system_id_tvb(field_info *fi, tvbuff_t *tvb, gint start, gint length)
{
proto_tree_set_system_id(fi, tvb_get_ptr(tvb, start, length), length);
}
proto_item *
proto_tree_add_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, const char* value)
{
proto_item *pi;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE_IS_STRING(hfinfo);
if (hfinfo->display == STR_UNICODE) {
DISSECTOR_ASSERT(g_utf8_validate(value, -1, NULL));
}
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
DISSECTOR_ASSERT(length >= 0);
proto_tree_set_string(PNODE_FINFO(pi), value);
return pi;
}
proto_item *
proto_tree_add_string_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const char* value,
const char *format,
...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_string(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_string_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const char* value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_string(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
static void
proto_tree_set_string(field_info *fi, const char* value)
{
if (value) {
fvalue_set_string(&fi->value, value);
} else {
fvalue_set_string(&fi->value, "[ Null ]");
}
}
static void
proto_tree_set_ax25(field_info *fi, const guint8* value)
{
fvalue_set_bytes(&fi->value, value);
}
static void
proto_tree_set_ax25_tvb(field_info *fi, tvbuff_t *tvb, gint start)
{
proto_tree_set_ax25(fi, tvb_get_ptr(tvb, start, 7));
}
static void
proto_tree_set_vines(field_info *fi, const guint8* value)
{
fvalue_set_bytes(&fi->value, value);
}
static void
proto_tree_set_vines_tvb(field_info *fi, tvbuff_t *tvb, gint start)
{
proto_tree_set_vines(fi, tvb_get_ptr(tvb, start, FT_VINES_ADDR_LEN));
}
proto_item *
proto_tree_add_ether(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, const guint8* value)
{
proto_item *pi;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_ETHER);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_ether(PNODE_FINFO(pi), value);
return pi;
}
proto_item *
proto_tree_add_ether_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const guint8* value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_ether(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_ether_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const guint8* value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_ether(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
static void
proto_tree_set_ether(field_info *fi, const guint8* value)
{
fvalue_set_bytes(&fi->value, value);
}
static void
proto_tree_set_ether_tvb(field_info *fi, tvbuff_t *tvb, gint start)
{
proto_tree_set_ether(fi, tvb_get_ptr(tvb, start, FT_ETHER_LEN));
}
proto_item *
proto_tree_add_boolean(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, guint32 value)
{
proto_item *pi;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_BOOLEAN);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_boolean(PNODE_FINFO(pi), value);
return pi;
}
proto_item *
proto_tree_add_boolean_format_value(proto_tree *tree, int hfindex,
tvbuff_t *tvb, gint start, gint length,
guint32 value, const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_boolean(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_boolean_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint32 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_boolean(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
static proto_item *
proto_tree_add_boolean64(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, guint64 value)
{
proto_item *pi;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_BOOLEAN);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_boolean(PNODE_FINFO(pi), value);
return pi;
}
static void
proto_tree_set_boolean(field_info *fi, guint64 value)
{
proto_tree_set_uint64(fi, value);
}
static char *
other_decode_bitfield_value(char *buf, const guint64 val, const guint64 mask, const int width)
{
int i;
guint64 bit;
char *p;
i = 0;
p = buf;
bit = G_GUINT64_CONSTANT(1) << (width - 1);
for (;;) {
if (mask & bit) {
if (val & bit)
*p++ = '1';
else
*p++ = '0';
} else {
*p++ = '.';
}
bit >>= 1;
i++;
if (i >= width)
break;
if (i % 4 == 0)
*p++ = ' ';
}
*p = '\0';
return p;
}
static char *
decode_bitfield_value(char *buf, const guint64 val, const guint64 mask, const int width)
{
char *p;
p = other_decode_bitfield_value(buf, val, mask, width);
p = g_stpcpy(p, " = ");
return p;
}
proto_item *
proto_tree_add_float(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, float value)
{
proto_item *pi;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_FLOAT);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_float(PNODE_FINFO(pi), value);
return pi;
}
proto_item *
proto_tree_add_float_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, float value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_float(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_float_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, float value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_float(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
static void
proto_tree_set_float(field_info *fi, float value)
{
fvalue_set_floating(&fi->value, value);
}
proto_item *
proto_tree_add_double(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, double value)
{
proto_item *pi;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_DOUBLE);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_double(PNODE_FINFO(pi), value);
return pi;
}
proto_item *
proto_tree_add_double_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, double value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_double(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_double_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, double value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_double(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
static void
proto_tree_set_double(field_info *fi, double value)
{
fvalue_set_floating(&fi->value, value);
}
proto_item *
proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, guint32 value)
{
proto_item *pi = NULL;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
switch (hfinfo->type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_FRAMENUM:
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_uint(PNODE_FINFO(pi), value);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
return pi;
}
proto_item *
proto_tree_add_uint_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint32 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_uint(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_uint_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint32 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_uint(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
static void
proto_tree_set_uint(field_info *fi, guint32 value)
{
header_field_info *hfinfo;
guint32 integer;
hfinfo = fi->hfinfo;
integer = value;
if (hfinfo->bitmask) {
integer &= (guint32)(hfinfo->bitmask);
integer >>= hfinfo_bitshift(hfinfo);
}
fvalue_set_uinteger(&fi->value, integer);
}
proto_item *
proto_tree_add_uint64(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, guint64 value)
{
proto_item *pi = NULL;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
switch (hfinfo->type) {
case FT_UINT40:
case FT_UINT48:
case FT_UINT56:
case FT_UINT64:
case FT_FRAMENUM:
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_uint64(PNODE_FINFO(pi), value);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
return pi;
}
proto_item *
proto_tree_add_uint64_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint64 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_uint64(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_uint64_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint64 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_uint64(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
static void
proto_tree_set_uint64(field_info *fi, guint64 value)
{
header_field_info *hfinfo;
guint64 integer;
hfinfo = fi->hfinfo;
integer = value;
if (hfinfo->bitmask) {
integer &= hfinfo->bitmask;
integer >>= hfinfo_bitshift(hfinfo);
}
fvalue_set_uinteger64(&fi->value, integer);
}
proto_item *
proto_tree_add_int(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, gint32 value)
{
proto_item *pi = NULL;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
switch (hfinfo->type) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_int(PNODE_FINFO(pi), value);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
return pi;
}
proto_item *
proto_tree_add_int_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, gint32 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_int(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_int_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, gint32 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_int(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
static void
proto_tree_set_int(field_info *fi, gint32 value)
{
header_field_info *hfinfo;
guint32 integer;
gint no_of_bits;
hfinfo = fi->hfinfo;
integer = (guint32) value;
if (hfinfo->bitmask) {
integer &= (guint32)(hfinfo->bitmask);
integer >>= hfinfo_bitshift(hfinfo);
no_of_bits = ws_count_ones(hfinfo->bitmask);
integer = ws_sign_ext32(integer, no_of_bits);
}
fvalue_set_sinteger(&fi->value, integer);
}
proto_item *
proto_tree_add_int64(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, gint64 value)
{
proto_item *pi = NULL;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
switch (hfinfo->type) {
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_INT64:
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_int64(PNODE_FINFO(pi), value);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
return pi;
}
proto_item *
proto_tree_add_int64_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, gint64 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_int64(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
static void
proto_tree_set_int64(field_info *fi, gint64 value)
{
header_field_info *hfinfo;
guint64 integer;
gint no_of_bits;
hfinfo = fi->hfinfo;
integer = value;
if (hfinfo->bitmask) {
integer &= hfinfo->bitmask;
integer >>= hfinfo_bitshift(hfinfo);
no_of_bits = ws_count_ones(hfinfo->bitmask);
integer = ws_sign_ext64(integer, no_of_bits);
}
fvalue_set_sinteger64(&fi->value, integer);
}
proto_item *
proto_tree_add_int64_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, gint64 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_int64(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_eui64(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, const guint64 value)
{
proto_item *pi;
header_field_info *hfinfo;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_EUI64);
pi = proto_tree_add_pi(tree, hfinfo, tvb, start, &length);
proto_tree_set_eui64(PNODE_FINFO(pi), value);
return pi;
}
proto_item *
proto_tree_add_eui64_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const guint64 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_eui64(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
}
return pi;
}
proto_item *
proto_tree_add_eui64_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const guint64 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
pi = proto_tree_add_eui64(tree, hfindex, tvb, start, length, value);
if (pi != tree) {
TRY_TO_FAKE_THIS_REPR(pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
return pi;
}
static void
proto_tree_set_eui64(field_info *fi, const guint64 value)
{
fvalue_set_uinteger64(&fi->value, value);
}
static void
proto_tree_set_eui64_tvb(field_info *fi, tvbuff_t *tvb, gint start, const guint encoding)
{
if (encoding)
{
proto_tree_set_eui64(fi, tvb_get_letoh64(tvb, start));
} else {
proto_tree_set_eui64(fi, tvb_get_ntoh64(tvb, start));
}
}
static proto_item *
proto_tree_add_node(proto_tree *tree, field_info *fi)
{
proto_node *pnode, *tnode, *sibling;
field_info *tfi;
int depth = 1;
if (tree->first_child == NULL) {
for (tnode = tree; tnode != NULL; tnode = tnode->parent) {
depth++;
if (G_UNLIKELY(depth > MAX_TREE_LEVELS)) {
THROW_MESSAGE(DissectorError, wmem_strdup_printf(wmem_packet_scope(),
"Maximum tree depth %d exceeded for \"%s\" - \"%s\" (%s:%u)",
MAX_TREE_LEVELS,
fi->hfinfo->name, fi->hfinfo->abbrev, G_STRFUNC, __LINE__));
}
}
}
tnode = tree;
tfi = PNODE_FINFO(tnode);
if (tfi != NULL && (tfi->tree_type < 0 || tfi->tree_type >= num_tree_types)) {
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"\"%s\" - \"%s\" tfi->tree_type: %u invalid (%s:%u)",
fi->hfinfo->name, fi->hfinfo->abbrev, tfi->tree_type, __FILE__, __LINE__));
}
pnode = wmem_new(PNODE_POOL(tree), proto_node);
PROTO_NODE_INIT(pnode);
pnode->parent = tnode;
PNODE_FINFO(pnode) = fi;
pnode->tree_data = PTREE_DATA(tree);
if (tnode->last_child != NULL) {
sibling = tnode->last_child;
DISSECTOR_ASSERT(sibling->next == NULL);
sibling->next = pnode;
} else
tnode->first_child = pnode;
tnode->last_child = pnode;
tree_data_add_maybe_interesting_field(pnode->tree_data, fi);
return (proto_item *)pnode;
}
static proto_item *
proto_tree_add_pi(proto_tree *tree, header_field_info *hfinfo, tvbuff_t *tvb, gint start,
gint *length)
{
proto_item *pi;
field_info *fi;
gint item_length;
get_hfi_length(hfinfo, tvb, start, length, &item_length);
fi = new_field_info(tree, hfinfo, tvb, start, item_length);
pi = proto_tree_add_node(tree, fi);
return pi;
}
static void
get_hfi_length(header_field_info *hfinfo, tvbuff_t *tvb, const gint start, gint *length,
gint *item_length)
{
gint length_remaining;
DISSECTOR_ASSERT(tvb != NULL || *length == 0);
if (*length == -1) {
switch (hfinfo->type) {
case FT_PROTOCOL:
case FT_NONE:
case FT_BYTES:
case FT_STRING:
case FT_STRINGZPAD:
*length = tvb_captured_length(tvb) ? tvb_ensure_captured_length_remaining(tvb, start) : 0;
DISSECTOR_ASSERT(*length >= 0);
break;
case FT_STRINGZ:
break;
default:
THROW(ReportedBoundsError);
DISSECTOR_ASSERT_NOT_REACHED();
}
*item_length = *length;
} else {
*item_length = *length;
if (hfinfo->type == FT_PROTOCOL || hfinfo->type == FT_NONE) {
if (tvb) {
length_remaining = tvb_captured_length_remaining(tvb, start);
if (*item_length < 0 ||
(*item_length > 0 &&
(length_remaining < *item_length)))
*item_length = length_remaining;
}
}
if (*item_length < 0) {
THROW(ReportedBoundsError);
}
}
}
static gint
get_full_length(header_field_info *hfinfo, tvbuff_t *tvb, const gint start,
gint length, guint item_length, const gint encoding)
{
guint32 n;
switch (hfinfo->type) {
case FT_NONE:
case FT_PROTOCOL:
case FT_BYTES:
break;
case FT_UINT_BYTES:
n = get_uint_value(NULL, tvb, start, length,
encoding ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
item_length += n;
break;
case FT_BOOLEAN:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT40:
case FT_UINT48:
case FT_UINT56:
case FT_UINT64:
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_INT64:
case FT_IPv4:
case FT_IPXNET:
case FT_IPv6:
case FT_FCWWN:
case FT_AX25:
case FT_VINES:
case FT_ETHER:
case FT_EUI64:
case FT_GUID:
case FT_OID:
case FT_REL_OID:
case FT_SYSTEM_ID:
case FT_FLOAT:
case FT_DOUBLE:
case FT_STRING:
break;
case FT_STRINGZ:
if (length < -1) {
report_type_length_mismatch(NULL, "a string", length, TRUE);
}
if (length == -1) {
tvb_get_stringz_enc(wmem_packet_scope(), tvb, start, &length, encoding);
}
item_length = length;
break;
case FT_UINT_STRING:
n = get_uint_value(NULL, tvb, start, length, encoding & ~ENC_CHARENCODING_MASK);
item_length += n;
break;
case FT_STRINGZPAD:
case FT_ABSOLUTE_TIME:
case FT_RELATIVE_TIME:
case FT_IEEE_11073_SFLOAT:
case FT_IEEE_11073_FLOAT:
break;
default:
g_error("hfinfo->type %d (%s) not handled\n",
hfinfo->type,
ftype_name(hfinfo->type));
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
return item_length;
}
static field_info *
new_field_info(proto_tree *tree, header_field_info *hfinfo, tvbuff_t *tvb,
const gint start, const gint item_length)
{
field_info *fi;
FIELD_INFO_NEW(PNODE_POOL(tree), fi);
fi->hfinfo = hfinfo;
fi->start = start;
fi->start += (tvb)?tvb_raw_offset(tvb):0;
fi->length = item_length;
fi->tree_type = -1;
fi->flags = 0;
if (!PTREE_DATA(tree)->visible)
FI_SET_FLAG(fi, FI_HIDDEN);
fvalue_init(&fi->value, fi->hfinfo->type);
fi->rep = NULL;
fi->ds_tvb = tvb ? tvb_get_ds_tvb(tvb) : NULL;
fi->appendix_start = 0;
fi->appendix_length = 0;
return fi;
}
static void
proto_tree_set_representation_value(proto_item *pi, const char *format, va_list ap)
{
g_assert(pi);
if (PTREE_DATA(pi)->visible && !PROTO_ITEM_IS_HIDDEN(pi)) {
int ret = 0;
field_info *fi = PITEM_FINFO(pi);
header_field_info *hf;
DISSECTOR_ASSERT(fi);
hf = fi->hfinfo;
ITEM_LABEL_NEW(PNODE_POOL(pi), fi->rep);
if (hf->bitmask && (hf->type == FT_BOOLEAN || IS_FT_UINT(hf->type))) {
guint64 val;
char *p;
if (IS_FT_UINT(hf->type))
val = fvalue_get_uinteger(&fi->value);
else
val = fvalue_get_uinteger64(&fi->value);
val <<= hfinfo_bitshift(hf);
p = decode_bitfield_value(fi->rep->representation, val, hf->bitmask, hfinfo_container_bitwidth(hf));
ret = (int) (p - fi->rep->representation);
}
ret += g_snprintf(fi->rep->representation + ret, ITEM_LABEL_LENGTH - ret, "%s: ", hf->name);
if (ret < ITEM_LABEL_LENGTH) {
ret += g_vsnprintf(fi->rep->representation + ret,
ITEM_LABEL_LENGTH - ret, format, ap);
}
if (ret >= ITEM_LABEL_LENGTH) {
LABEL_MARK_TRUNCATED_START(fi->rep->representation);
}
}
}
static void
proto_tree_set_representation(proto_item *pi, const char *format, va_list ap)
{
int ret;
field_info *fi = PITEM_FINFO(pi);
DISSECTOR_ASSERT(fi);
if (!PROTO_ITEM_IS_HIDDEN(pi)) {
ITEM_LABEL_NEW(PNODE_POOL(pi), fi->rep);
ret = g_vsnprintf(fi->rep->representation, ITEM_LABEL_LENGTH,
format, ap);
if (ret >= ITEM_LABEL_LENGTH) {
LABEL_MARK_TRUNCATED_START(fi->rep->representation);
}
}
}
static const char *
hfinfo_format_text(const header_field_info *hfinfo, const guchar *string)
{
switch (hfinfo->display) {
case STR_ASCII:
return format_text(string, strlen(string));
case STR_UNICODE:
return string;
}
return format_text(string, strlen(string));
}
static int
protoo_strlcpy(gchar *dest, const gchar *src, gsize dest_size)
{
gsize res = g_strlcpy(dest, src, dest_size);
if (res > dest_size)
res = dest_size;
return (int) res;
}
static header_field_info *
hfinfo_same_name_get_prev(const header_field_info *hfinfo)
{
header_field_info *dup_hfinfo;
if (hfinfo->same_name_prev_id == -1)
return NULL;
PROTO_REGISTRAR_GET_NTH(hfinfo->same_name_prev_id, dup_hfinfo);
return dup_hfinfo;
}
static void
hfinfo_remove_from_gpa_name_map(const header_field_info *hfinfo)
{
g_free(last_field_name);
last_field_name = NULL;
if (!hfinfo->same_name_next && hfinfo->same_name_prev_id == -1) {
g_hash_table_steal(gpa_name_map, hfinfo->abbrev);
return;
}
if (hfinfo->same_name_next) {
hfinfo->same_name_next->same_name_prev_id = hfinfo->same_name_prev_id;
}
if (hfinfo->same_name_prev_id != -1) {
header_field_info *same_name_prev = hfinfo_same_name_get_prev(hfinfo);
same_name_prev->same_name_next = hfinfo->same_name_next;
if (!hfinfo->same_name_next) {
g_hash_table_insert(gpa_name_map, (gpointer) (same_name_prev->abbrev), same_name_prev);
}
}
}
const gchar *
proto_custom_set(proto_tree* tree, GSList *field_ids, gint occurrence,
gchar *result, gchar *expr, const int size)
{
guint32 number;
guint64 number64;
guint8 *bytes;
ipv4_addr_and_mask *ipv4;
struct e_in6_addr *ipv6;
address addr;
guint32 n_addr;
const true_false_string *tfstring;
int len, prev_len = 0, last, i, offset_r = 0, offset_e = 0;
GPtrArray *finfos;
field_info *finfo = NULL;
header_field_info* hfinfo;
const gchar *abbrev = NULL;
const char *hf_str_val;
char number_buf[48];
const char *number_out;
char *tmpbuf, *str;
int *field_idx;
int field_id;
int ii = 0;
g_assert(field_ids != NULL);
while ((field_idx = (int *) g_slist_nth_data(field_ids, ii++))) {
field_id = *field_idx;
PROTO_REGISTRAR_GET_NTH((guint)field_id, hfinfo);
if (!hfinfo)
return "";
if (occurrence < 0) {
while (hfinfo->same_name_prev_id != -1) {
PROTO_REGISTRAR_GET_NTH(hfinfo->same_name_prev_id, hfinfo);
}
}
while (hfinfo) {
finfos = proto_get_finfo_ptr_array(tree, hfinfo->id);
if (!finfos || !(len = g_ptr_array_len(finfos))) {
if (occurrence < 0) {
hfinfo = hfinfo->same_name_next;
} else {
hfinfo = hfinfo_same_name_get_prev(hfinfo);
}
continue;
}
if (((occurrence - prev_len) > len) || ((occurrence + prev_len) < -len)) {
if (occurrence < 0) {
hfinfo = hfinfo->same_name_next;
} else {
hfinfo = hfinfo_same_name_get_prev(hfinfo);
}
prev_len += len;
continue;
}
if (occurrence < 0) {
i = occurrence + len + prev_len;
last = i;
} else if (occurrence > 0) {
i = occurrence - 1 - prev_len;
last = i;
} else {
i = 0;
last = len - 1;
}
prev_len += len;
while (i <= last) {
finfo = (field_info *)g_ptr_array_index(finfos, i);
if (offset_r && (offset_r < (size - 2)))
result[offset_r++] = ',';
if (offset_e && (offset_e < (size - 2)))
expr[offset_e++] = ',';
switch (hfinfo->type) {
case FT_NONE:
if (offset_r == 0) {
result[0] = '\0';
} else if (result[offset_r-1] == ',') {
result[offset_r-1] = '\0';
}
break;
case FT_PROTOCOL:
g_strlcpy(result, "Yes", size);
break;
case FT_UINT_BYTES:
case FT_BYTES:
bytes = (guint8 *)fvalue_get(&finfo->value);
if (bytes) {
switch(hfinfo->display)
{
case SEP_DOT:
str = bytestring_to_str(NULL, bytes, fvalue_length(&finfo->value), '.');
break;
case SEP_DASH:
str = bytestring_to_str(NULL, bytes, fvalue_length(&finfo->value), '-');
break;
case SEP_COLON:
str = bytestring_to_str(NULL, bytes, fvalue_length(&finfo->value), ':');
break;
case SEP_SPACE:
str = bytestring_to_str(NULL, bytes, fvalue_length(&finfo->value), ' ');
break;
case BASE_NONE:
default:
if (prefs.display_byte_fields_with_spaces)
{
str = bytestring_to_str(NULL, bytes, fvalue_length(&finfo->value), ' ');
}
else
{
str = bytes_to_str(NULL, bytes, fvalue_length(&finfo->value));
}
break;
}
offset_r += protoo_strlcpy(result+offset_r, str, size-offset_r);
wmem_free(NULL, str);
}
else {
if (hfinfo->display & BASE_ALLOW_ZERO) {
offset_r += protoo_strlcpy(result+offset_r, "<none>", size-offset_r);
} else {
offset_r += protoo_strlcpy(result+offset_r, "<MISSING>", size-offset_r);
}
}
break;
case FT_ABSOLUTE_TIME:
tmpbuf = abs_time_to_str(NULL, (const nstime_t *)fvalue_get(&finfo->value), (absolute_time_display_e)hfinfo->display, TRUE);
offset_r += protoo_strlcpy(result+offset_r,
tmpbuf,
size-offset_r);
wmem_free(NULL, tmpbuf);
break;
case FT_RELATIVE_TIME:
tmpbuf = rel_time_to_secs_str(NULL, (const nstime_t *)fvalue_get(&finfo->value));
offset_r += protoo_strlcpy(result+offset_r,
tmpbuf,
size-offset_r);
wmem_free(NULL, tmpbuf);
break;
case FT_BOOLEAN:
number64 = fvalue_get_uinteger64(&finfo->value);
tfstring = (const true_false_string *)&tfs_true_false;
if (hfinfo->strings) {
tfstring = (const struct true_false_string*) hfinfo->strings;
}
offset_r += protoo_strlcpy(result+offset_r,
number64 ?
tfstring->true_string :
tfstring->false_string, size-offset_r);
offset_e += protoo_strlcpy(expr+offset_e,
number64 ? "1" : "0", size-offset_e);
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_FRAMENUM:
hf_str_val = NULL;
number = IS_FT_INT(hfinfo->type) ?
(guint32) fvalue_get_sinteger(&finfo->value) :
fvalue_get_uinteger(&finfo->value);
if ((hfinfo->display & FIELD_DISPLAY_E_MASK) == BASE_CUSTOM) {
gchar tmp[ITEM_LABEL_LENGTH];
custom_fmt_func_t fmtfunc = (custom_fmt_func_t)hfinfo->strings;
DISSECTOR_ASSERT(fmtfunc);
fmtfunc(tmp, number);
offset_r += protoo_strlcpy(result+offset_r, tmp, size-offset_r);
} else if (hfinfo->strings && hfinfo->type != FT_FRAMENUM) {
number_out = hf_str_val = hf_try_val_to_str(number, hfinfo);
if (!number_out)
number_out = hfinfo_number_value_format_display(hfinfo, BASE_DEC, number_buf, number);
offset_r += protoo_strlcpy(result+offset_r, number_out, size-offset_r);
} else {
number_out = hfinfo_number_value_format(hfinfo, number_buf, number);
offset_r += protoo_strlcpy(result+offset_r, number_out, size-offset_r);
}
if (hf_str_val && (hfinfo->display & FIELD_DISPLAY_E_MASK) == BASE_NONE) {
g_snprintf(expr+offset_e, size-offset_e, "\"%s\"", hf_str_val);
} else {
number_out = hfinfo_numeric_value_format(hfinfo, number_buf, number);
g_strlcpy(expr+offset_e, number_out, size-offset_e);
}
offset_e = (int)strlen(expr);
break;
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_INT64:
case FT_UINT40:
case FT_UINT48:
case FT_UINT56:
case FT_UINT64:
hf_str_val = NULL;
number64 = IS_FT_INT(hfinfo->type) ?
(guint64) fvalue_get_sinteger64(&finfo->value) :
fvalue_get_uinteger64(&finfo->value);
if ((hfinfo->display & FIELD_DISPLAY_E_MASK) == BASE_CUSTOM) {
gchar tmp[ITEM_LABEL_LENGTH];
custom_fmt_func_64_t fmtfunc64 = (custom_fmt_func_64_t)hfinfo->strings;
DISSECTOR_ASSERT(fmtfunc64);
fmtfunc64(tmp, number64);
offset_r += protoo_strlcpy(result+offset_r, tmp, size-offset_r);
} else if (hfinfo->strings) {
number_out = hf_str_val = hf_try_val64_to_str(number64, hfinfo);
if (!number_out)
number_out = hfinfo_number_value_format_display64(hfinfo, BASE_DEC, number_buf, number64);
offset_r += protoo_strlcpy(result+offset_r, number_out, size-offset_r);
} else {
number_out = hfinfo_number_value_format64(hfinfo, number_buf, number64);
offset_r += protoo_strlcpy(result+offset_r, number_out, size-offset_r);
}
if (hf_str_val && (hfinfo->display & FIELD_DISPLAY_E_MASK) == BASE_NONE) {
g_snprintf(expr+offset_e, size-offset_e, "\"%s\"", hf_str_val);
} else {
number_out = hfinfo_numeric_value_format64(hfinfo, number_buf, number64);
g_strlcpy(expr+offset_e, number_out, size-offset_e);
}
offset_e = (int)strlen(expr);
break;
case FT_EUI64:
str = eui64_to_str(NULL, fvalue_get_uinteger64(&finfo->value));
offset_r += protoo_strlcpy(result+offset_r, str, size-offset_r);
wmem_free(NULL, str);
break;
case FT_IPv4:
ipv4 = (ipv4_addr_and_mask *)fvalue_get(&finfo->value);
n_addr = ipv4_get_net_order_addr(ipv4);
set_address (&addr, AT_IPv4, 4, &n_addr);
address_to_str_buf(&addr, result+offset_r, size-offset_r);
offset_r = (int)strlen(result);
break;
case FT_IPv6:
ipv6 = (struct e_in6_addr *)fvalue_get(&finfo->value);
set_address (&addr, AT_IPv6, sizeof(struct e_in6_addr), ipv6);
address_to_str_buf(&addr, result+offset_r, size-offset_r);
offset_r = (int)strlen(result);
break;
case FT_FCWWN:
set_address (&addr, AT_FCWWN, FCWWN_ADDR_LEN, fvalue_get(&finfo->value));
address_to_str_buf(&addr, result+offset_r, size-offset_r);
offset_r = (int)strlen(result);
break;
case FT_ETHER:
set_address (&addr, AT_ETHER, FT_ETHER_LEN, fvalue_get(&finfo->value));
address_to_str_buf(&addr, result+offset_r, size-offset_r);
offset_r = (int)strlen(result);
break;
case FT_GUID:
str = guid_to_str(NULL, (e_guid_t *)fvalue_get(&finfo->value));
offset_r += protoo_strlcpy(result+offset_r, str, size-offset_r);
wmem_free(NULL, str);
break;
case FT_REL_OID:
bytes = (guint8 *)fvalue_get(&finfo->value);
str = rel_oid_resolved_from_encoded(NULL, bytes, fvalue_length(&finfo->value));
offset_r += protoo_strlcpy(result+offset_r, str, size-offset_r);
wmem_free(NULL, str);
str = rel_oid_encoded2string(NULL, bytes, fvalue_length(&finfo->value));
offset_e += protoo_strlcpy(expr+offset_e, str, size-offset_e);
wmem_free(NULL, str);
break;
case FT_OID:
bytes = (guint8 *)fvalue_get(&finfo->value);
str = oid_resolved_from_encoded(NULL, bytes, fvalue_length(&finfo->value));
offset_r += protoo_strlcpy(result+offset_r, str, size-offset_r);
wmem_free(NULL, str);
str = oid_encoded2string(NULL, bytes, fvalue_length(&finfo->value));
offset_e += protoo_strlcpy(expr+offset_e, str, size-offset_e);
wmem_free(NULL, str);
break;
case FT_SYSTEM_ID:
bytes = (guint8 *)fvalue_get(&finfo->value);
str = print_system_id(NULL, bytes, fvalue_length(&finfo->value));
offset_r += protoo_strlcpy(result+offset_r, str, size-offset_r);
offset_e += protoo_strlcpy(expr+offset_e, str, size-offset_e);
wmem_free(NULL, str);
break;
case FT_FLOAT:
g_snprintf(result+offset_r, size-offset_r,
"%." G_STRINGIFY(FLT_DIG) "g", fvalue_get_floating(&finfo->value));
offset_r = (int)strlen(result);
break;
case FT_DOUBLE:
g_snprintf(result+offset_r, size-offset_r,
"%." G_STRINGIFY(DBL_DIG) "g", fvalue_get_floating(&finfo->value));
offset_r = (int)strlen(result);
break;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
bytes = (guint8 *)fvalue_get(&finfo->value);
offset_r += protoo_strlcpy(result+offset_r,
hfinfo_format_text(hfinfo, bytes),
size-offset_r);
break;
case FT_IEEE_11073_SFLOAT:
str = fvalue_to_string_repr(NULL, &finfo->value, FTREPR_DISPLAY, hfinfo->display);
g_snprintf(result+offset_r, size-offset_r,
"%s: %s",
hfinfo->name, str);
wmem_free(NULL, str);
offset_r = (int)strlen(result);
break;
case FT_IEEE_11073_FLOAT:
str = fvalue_to_string_repr(NULL, &finfo->value, FTREPR_DISPLAY, hfinfo->display);
g_snprintf(result+offset_r, size-offset_r,
"%s: %s",
hfinfo->name, str);
offset_r = (int)strlen(result);
wmem_free(NULL, str);
break;
case FT_IPXNET:
case FT_PCRE:
default:
g_error("hfinfo->type %d (%s) not handled\n",
hfinfo->type,
ftype_name(hfinfo->type));
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
i++;
}
switch (hfinfo->type) {
case FT_BOOLEAN:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT40:
case FT_UINT48:
case FT_UINT56:
case FT_UINT64:
case FT_FRAMENUM:
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_INT64:
case FT_OID:
case FT_REL_OID:
case FT_SYSTEM_ID:
break;
default:
g_strlcpy(expr, result, size);
break;
}
if (!abbrev) {
abbrev = hfinfo->abbrev;
}
if (occurrence == 0) {
hfinfo = hfinfo_same_name_get_prev(hfinfo);
} else {
hfinfo = NULL;
}
}
}
return abbrev ? abbrev : "";
}
void
proto_item_set_text(proto_item *pi, const char *format, ...)
{
field_info *fi = NULL;
va_list ap;
TRY_TO_FAKE_THIS_REPR_VOID(pi);
fi = PITEM_FINFO(pi);
if (fi == NULL)
return;
if (fi->rep) {
ITEM_LABEL_FREE(PNODE_POOL(pi), fi->rep);
fi->rep = NULL;
}
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
}
void
proto_item_append_text(proto_item *pi, const char *format, ...)
{
field_info *fi = NULL;
size_t curlen;
va_list ap;
TRY_TO_FAKE_THIS_REPR_VOID(pi);
fi = PITEM_FINFO(pi);
if (fi == NULL) {
return;
}
if (!PROTO_ITEM_IS_HIDDEN(pi)) {
if (fi->rep == NULL) {
ITEM_LABEL_NEW(PNODE_POOL(pi), fi->rep);
proto_item_fill_label(fi, fi->rep->representation);
}
curlen = strlen(fi->rep->representation);
if (ITEM_LABEL_LENGTH > curlen) {
va_start(ap, format);
g_vsnprintf(fi->rep->representation + curlen,
ITEM_LABEL_LENGTH - (gulong) curlen, format, ap);
va_end(ap);
}
}
}
void
proto_item_prepend_text(proto_item *pi, const char *format, ...)
{
field_info *fi = NULL;
char representation[ITEM_LABEL_LENGTH];
va_list ap;
TRY_TO_FAKE_THIS_REPR_VOID(pi);
fi = PITEM_FINFO(pi);
if (fi == NULL) {
return;
}
if (!PROTO_ITEM_IS_HIDDEN(pi)) {
if (fi->rep == NULL) {
ITEM_LABEL_NEW(PNODE_POOL(pi), fi->rep);
proto_item_fill_label(fi, representation);
} else
g_strlcpy(representation, fi->rep->representation, ITEM_LABEL_LENGTH);
va_start(ap, format);
g_vsnprintf(fi->rep->representation,
ITEM_LABEL_LENGTH, format, ap);
va_end(ap);
g_strlcat(fi->rep->representation, representation, ITEM_LABEL_LENGTH);
}
}
void
proto_item_set_len(proto_item *pi, const gint length)
{
field_info *fi;
TRY_TO_FAKE_THIS_REPR_VOID(pi);
fi = PITEM_FINFO(pi);
if (fi == NULL)
return;
DISSECTOR_ASSERT(length >= 0);
fi->length = length;
if (fi->value.ftype->ftype == FT_BYTES && length <= (gint)fi->value.value.bytes->len)
fi->value.value.bytes->len = length;
}
void
proto_item_set_end(proto_item *pi, tvbuff_t *tvb, gint end)
{
field_info *fi;
TRY_TO_FAKE_THIS_REPR_VOID(pi);
fi = PITEM_FINFO(pi);
if (fi == NULL)
return;
end += tvb_raw_offset(tvb);
DISSECTOR_ASSERT(end >= fi->start);
fi->length = end - fi->start;
}
int
proto_item_get_len(const proto_item *pi)
{
field_info *fi = PITEM_FINFO(pi);
return fi ? fi->length : -1;
}
proto_tree *
proto_tree_create_root(packet_info *pinfo)
{
proto_node *pnode;
pnode = g_slice_new(proto_tree);
PROTO_NODE_INIT(pnode);
pnode->parent = NULL;
PNODE_FINFO(pnode) = NULL;
pnode->tree_data = g_slice_new(tree_data_t);
pnode->tree_data->pinfo = pinfo;
pnode->tree_data->interesting_hfids = NULL;
pnode->tree_data->visible = FALSE;
pnode->tree_data->fake_protocols = TRUE;
pnode->tree_data->count = 0;
return (proto_tree *)pnode;
}
void
proto_tree_prime_hfid(proto_tree *tree _U_, const gint hfid)
{
header_field_info *hfinfo;
PROTO_REGISTRAR_GET_NTH(hfid, hfinfo);
hfinfo->ref_type = HF_REF_TYPE_DIRECT;
if (hfinfo->parent != -1) {
header_field_info *parent_hfinfo;
PROTO_REGISTRAR_GET_NTH(hfinfo->parent, parent_hfinfo);
if (parent_hfinfo->ref_type != HF_REF_TYPE_DIRECT)
parent_hfinfo->ref_type = HF_REF_TYPE_INDIRECT;
}
}
proto_tree *
proto_item_add_subtree(proto_item *pi, const gint idx) {
field_info *fi;
if (!pi)
return NULL;
DISSECTOR_ASSERT(idx >= 0 && idx < num_tree_types);
fi = PITEM_FINFO(pi);
if (!fi)
return (proto_tree *)pi;
fi->tree_type = idx;
return (proto_tree *)pi;
}
proto_tree *
proto_item_get_subtree(proto_item *pi) {
field_info *fi;
if (!pi)
return NULL;
fi = PITEM_FINFO(pi);
if ( (!fi) || (fi->tree_type == -1) )
return NULL;
return (proto_tree *)pi;
}
proto_item *
proto_item_get_parent(const proto_item *ti) {
if (!ti)
return NULL;
return ti->parent;
}
proto_item *
proto_item_get_parent_nth(proto_item *ti, int gen) {
if (!ti)
return NULL;
while (gen--) {
ti = ti->parent;
if (!ti)
return NULL;
}
return ti;
}
proto_item *
proto_tree_get_parent(proto_tree *tree) {
if (!tree)
return NULL;
return (proto_item *)tree;
}
proto_tree *
proto_tree_get_parent_tree(proto_tree *tree) {
if (!tree)
return NULL;
if (!tree->parent)
return tree;
return (proto_tree *)tree->parent;
}
proto_tree *
proto_tree_get_root(proto_tree *tree) {
if (!tree)
return NULL;
while (tree->parent) {
tree = tree->parent;
}
return tree;
}
void
proto_tree_move_item(proto_tree *tree, proto_item *fixed_item,
proto_item *item_to_move)
{
if (!tree || !PTREE_DATA(tree)->visible)
return;
DISSECTOR_ASSERT(item_to_move->parent == tree);
DISSECTOR_ASSERT(fixed_item->parent == tree);
if (tree->first_child == item_to_move) {
tree->first_child = item_to_move->next;
DISSECTOR_ASSERT(tree->last_child != item_to_move);
} else {
proto_item *curr_item;
for(curr_item = tree->first_child; curr_item != NULL; curr_item = curr_item->next) {
if (curr_item->next == item_to_move) {
break;
}
}
DISSECTOR_ASSERT(curr_item);
curr_item->next = item_to_move->next;
if (tree->last_child == item_to_move) {
tree->last_child = curr_item;
}
}
item_to_move->next = fixed_item->next;
fixed_item->next = item_to_move;
if (tree->last_child == fixed_item) {
tree->last_child = item_to_move;
}
}
void
proto_tree_set_appendix(proto_tree *tree, tvbuff_t *tvb, gint start,
const gint length)
{
field_info *fi;
if (tree == NULL)
return;
fi = PTREE_FINFO(tree);
if (fi == NULL)
return;
start += tvb_raw_offset(tvb);
DISSECTOR_ASSERT(start >= 0);
DISSECTOR_ASSERT(length >= 0);
fi->appendix_start = start;
fi->appendix_length = length;
}
int
proto_register_protocol(const char *name, const char *short_name,
const char *filter_name)
{
protocol_t *protocol;
const protocol_t *existing_protocol = NULL;
header_field_info *hfinfo;
int proto_id;
const char *existing_name;
gint *key;
guint i;
gchar c;
gboolean found_invalid;
key = (gint *)g_malloc (sizeof(gint));
*key = wrs_str_hash(name);
existing_name = (const char *)g_hash_table_lookup(proto_names, key);
if (existing_name != NULL) {
g_error("Duplicate protocol name \"%s\"!"
" This might be caused by an inappropriate plugin or a development error.", name);
}
g_hash_table_insert(proto_names, key, (gpointer)name);
existing_protocol = (const protocol_t *)g_hash_table_lookup(proto_short_names, short_name);
if (existing_protocol != NULL) {
g_error("Duplicate protocol short_name \"%s\"!"
" This might be caused by an inappropriate plugin or a development error.", short_name);
}
found_invalid = FALSE;
for (i = 0; filter_name[i]; i++) {
c = filter_name[i];
if (!(g_ascii_islower(c) || g_ascii_isdigit(c) || c == '-' || c == '_' || c == '.')) {
found_invalid = TRUE;
}
}
if (found_invalid) {
g_error("Protocol filter name \"%s\" has one or more invalid characters."
" Allowed are lower characters, digits, '-', '_' and '.'."
" This might be caused by an inappropriate plugin or a development error.", filter_name);
}
existing_protocol = (const protocol_t *)g_hash_table_lookup(proto_filter_names, filter_name);
if (existing_protocol != NULL) {
g_error("Duplicate protocol filter_name \"%s\"!"
" This might be caused by an inappropriate plugin or a development error.", filter_name);
}
protocol = g_new(protocol_t, 1);
protocol->name = name;
protocol->short_name = short_name;
protocol->filter_name = filter_name;
protocol->fields = g_ptr_array_new();
protocol->is_enabled = TRUE;
protocol->enabled_by_default = TRUE;
protocol->can_toggle = TRUE;
protocol->heur_list = NULL;
protocols = g_list_prepend(protocols, protocol);
g_hash_table_insert(proto_filter_names, (gpointer)filter_name, protocol);
g_hash_table_insert(proto_short_names, (gpointer)short_name, protocol);
hfinfo = g_slice_new(header_field_info);
hfinfo->name = name;
hfinfo->abbrev = filter_name;
hfinfo->type = FT_PROTOCOL;
hfinfo->display = BASE_NONE;
hfinfo->strings = protocol;
hfinfo->bitmask = 0;
hfinfo->ref_type = HF_REF_TYPE_NONE;
hfinfo->blurb = NULL;
hfinfo->parent = -1;
proto_id = proto_register_field_init(hfinfo, hfinfo->parent);
protocol->proto_id = proto_id;
return proto_id;
}
gboolean
proto_deregister_protocol(const char *short_name)
{
protocol_t *protocol;
header_field_info *hfinfo;
int proto_id;
gint key;
guint i;
proto_id = proto_get_id_by_short_name(short_name);
protocol = find_protocol_by_id(proto_id);
if (protocol == NULL)
return FALSE;
key = wrs_str_hash(protocol->name);
g_hash_table_remove(proto_names, &key);
g_hash_table_remove(proto_short_names, (gpointer)short_name);
g_hash_table_remove(proto_filter_names, (gpointer)protocol->filter_name);
for (i = 0; i < protocol->fields->len; i++) {
hfinfo = (header_field_info *)g_ptr_array_index(protocol->fields, i);
hfinfo_remove_from_gpa_name_map(hfinfo);
expert_deregister_expertinfo(hfinfo->abbrev);
g_ptr_array_add(deregistered_fields, gpa_hfinfo.hfi[hfinfo->id]);
}
g_ptr_array_free(protocol->fields, TRUE);
protocol->fields = NULL;
protocols = g_list_remove(protocols, protocol);
g_ptr_array_add(deregistered_fields, gpa_hfinfo.hfi[proto_id]);
g_hash_table_steal(gpa_name_map, protocol->filter_name);
g_free(last_field_name);
last_field_name = NULL;
return TRUE;
}
int
proto_get_first_protocol(void **cookie)
{
protocol_t *protocol;
if (protocols == NULL)
return -1;
*cookie = protocols;
protocol = (protocol_t *)protocols->data;
return protocol->proto_id;
}
int
proto_get_data_protocol(void *cookie)
{
GList *list_item = (GList *)cookie;
protocol_t *protocol = (protocol_t *)list_item->data;
return protocol->proto_id;
}
int
proto_get_next_protocol(void **cookie)
{
GList *list_item = (GList *)*cookie;
protocol_t *protocol;
list_item = g_list_next(list_item);
if (list_item == NULL)
return -1;
*cookie = list_item;
protocol = (protocol_t *)list_item->data;
return protocol->proto_id;
}
header_field_info *
proto_get_first_protocol_field(const int proto_id, void **cookie)
{
protocol_t *protocol = find_protocol_by_id(proto_id);
if ((protocol == NULL) || (protocol->fields->len == 0))
return NULL;
*cookie = GUINT_TO_POINTER(0 + 1);
return (header_field_info *)g_ptr_array_index(protocol->fields, 0);
}
header_field_info *
proto_get_next_protocol_field(const int proto_id, void **cookie)
{
protocol_t *protocol = find_protocol_by_id(proto_id);
guint i = GPOINTER_TO_UINT(*cookie) - 1;
i++;
if (i >= protocol->fields->len)
return NULL;
*cookie = GUINT_TO_POINTER(i + 1);
return (header_field_info *)g_ptr_array_index(protocol->fields, i);
}
protocol_t *
find_protocol_by_id(const int proto_id)
{
header_field_info *hfinfo;
if (proto_id < 0)
return NULL;
PROTO_REGISTRAR_GET_NTH(proto_id, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_PROTOCOL);
return (protocol_t *)hfinfo->strings;
}
int
proto_get_id(const protocol_t *protocol)
{
return protocol->proto_id;
}
gboolean
proto_name_already_registered(const gchar *name)
{
gint key;
DISSECTOR_ASSERT_HINT(name, "No name present");
key = wrs_str_hash(name);
if (g_hash_table_lookup(proto_names, &key) != NULL)
return TRUE;
return FALSE;
}
int
proto_get_id_by_filter_name(const gchar *filter_name)
{
const protocol_t *protocol = NULL;
DISSECTOR_ASSERT_HINT(filter_name, "No filter name present");
protocol = (const protocol_t *)g_hash_table_lookup(proto_filter_names, filter_name);
if (protocol == NULL)
return -1;
return protocol->proto_id;
}
int
proto_get_id_by_short_name(const gchar *short_name)
{
const protocol_t *protocol = NULL;
DISSECTOR_ASSERT_HINT(short_name, "No short name present");
protocol = (const protocol_t *)g_hash_table_lookup(proto_short_names, short_name);
if (protocol == NULL)
return -1;
return protocol->proto_id;
}
const char *
proto_get_protocol_name(const int proto_id)
{
protocol_t *protocol;
protocol = find_protocol_by_id(proto_id);
if (protocol == NULL)
return NULL;
return protocol->name;
}
const char *
proto_get_protocol_short_name(const protocol_t *protocol)
{
if (protocol == NULL)
return "(none)";
return protocol->short_name;
}
const char *
proto_get_protocol_long_name(const protocol_t *protocol)
{
if (protocol == NULL)
return "(none)";
return protocol->name;
}
const char *
proto_get_protocol_filter_name(const int proto_id)
{
protocol_t *protocol;
protocol = find_protocol_by_id(proto_id);
if (protocol == NULL)
return "(none)";
return protocol->filter_name;
}
void proto_add_heuristic_dissector(protocol_t *protocol, const char *short_name)
{
heur_dtbl_entry_t* heuristic_dissector;
if (protocol == NULL)
return;
heuristic_dissector = find_heur_dissector_by_unique_short_name(short_name);
if (heuristic_dissector != NULL)
{
protocol->heur_list = g_list_append (protocol->heur_list, heuristic_dissector);
}
}
void proto_heuristic_dissector_foreach(const protocol_t *protocol, GFunc func, gpointer user_data)
{
if (protocol == NULL)
return;
g_list_foreach(protocol->heur_list, func, user_data);
}
void
proto_get_frame_protocols(const wmem_list_t *layers, gboolean *is_ip,
gboolean *is_tcp, gboolean *is_udp,
gboolean *is_sctp, gboolean *is_ssl,
gboolean *is_rtp,
gboolean *is_lte_rlc)
{
wmem_list_frame_t *protos = wmem_list_head(layers);
int proto_id;
const char *proto_name;
while (protos != NULL)
{
proto_id = GPOINTER_TO_INT(wmem_list_frame_data(protos));
proto_name = proto_get_protocol_filter_name(proto_id);
if (is_ip && ((!strcmp(proto_name, "ip")) ||
(!strcmp(proto_name, "ipv6")))) {
*is_ip = TRUE;
} else if (is_tcp && !strcmp(proto_name, "tcp")) {
*is_tcp = TRUE;
} else if (is_udp && !strcmp(proto_name, "udp")) {
*is_udp = TRUE;
} else if (is_sctp && !strcmp(proto_name, "sctp")) {
*is_sctp = TRUE;
} else if (is_ssl && !strcmp(proto_name, "ssl")) {
*is_ssl = TRUE;
} else if (is_rtp && !strcmp(proto_name, "rtp")) {
*is_rtp = TRUE;
} else if (is_lte_rlc && !strcmp(proto_name, "rlc-lte")) {
*is_lte_rlc = TRUE;
}
protos = wmem_list_frame_next(protos);
}
}
gboolean
proto_is_frame_protocol(const wmem_list_t *layers, const char* proto_name)
{
wmem_list_frame_t *protos = wmem_list_head(layers);
int proto_id;
const char *name;
while (protos != NULL)
{
proto_id = GPOINTER_TO_INT(wmem_list_frame_data(protos));
name = proto_get_protocol_filter_name(proto_id);
if (!strcmp(name, proto_name))
{
return TRUE;
}
protos = wmem_list_frame_next(protos);
}
return FALSE;
}
gboolean
proto_is_protocol_enabled(const protocol_t *protocol)
{
return protocol->is_enabled;
}
gboolean
proto_can_toggle_protocol(const int proto_id)
{
protocol_t *protocol;
protocol = find_protocol_by_id(proto_id);
return protocol->can_toggle;
}
void
proto_disable_by_default(const int proto_id)
{
protocol_t *protocol;
protocol = find_protocol_by_id(proto_id);
DISSECTOR_ASSERT(protocol->can_toggle);
protocol->is_enabled = FALSE;
protocol->enabled_by_default = FALSE;
}
void
proto_set_decoding(const int proto_id, const gboolean enabled)
{
protocol_t *protocol;
protocol = find_protocol_by_id(proto_id);
DISSECTOR_ASSERT(protocol->can_toggle);
protocol->is_enabled = enabled;
}
void
proto_enable_all(void)
{
protocol_t *protocol;
GList *list_item = protocols;
if (protocols == NULL)
return;
while (list_item) {
protocol = (protocol_t *)list_item->data;
if (protocol->can_toggle && protocol->enabled_by_default)
protocol->is_enabled = TRUE;
list_item = g_list_next(list_item);
}
}
void
proto_set_cant_toggle(const int proto_id)
{
protocol_t *protocol;
protocol = find_protocol_by_id(proto_id);
protocol->can_toggle = FALSE;
}
static int
proto_register_field_common(protocol_t *proto, header_field_info *hfi, const int parent)
{
if (proto != NULL) {
g_ptr_array_add(proto->fields, hfi);
}
return proto_register_field_init(hfi, parent);
}
void
proto_register_field_array(const int parent, hf_register_info *hf, const int num_records)
{
hf_register_info *ptr = hf;
protocol_t *proto;
int i;
proto = find_protocol_by_id(parent);
for (i = 0; i < num_records; i++, ptr++) {
if (*ptr->p_id != -1 && *ptr->p_id != 0) {
fprintf(stderr,
"Duplicate field detected in call to proto_register_field_array: %s is already registered\n",
ptr->hfinfo.abbrev);
return;
}
*ptr->p_id = proto_register_field_common(proto, &ptr->hfinfo, parent);
}
}
void
proto_register_fields_section(const int parent, header_field_info *hfi, const int num_records)
{
int i;
protocol_t *proto;
proto = find_protocol_by_id(parent);
for (i = 0; i < num_records; i++) {
if (hfi[i].id != -1) {
fprintf(stderr,
"Duplicate field detected in call to proto_register_fields: %s is already registered\n",
hfi[i].abbrev);
return;
}
proto_register_field_common(proto, &hfi[i], parent);
}
}
void
proto_register_fields_manual(const int parent, header_field_info **hfi, const int num_records)
{
int i;
protocol_t *proto;
proto = find_protocol_by_id(parent);
for (i = 0; i < num_records; i++) {
if (hfi[i]->id != -1) {
fprintf(stderr,
"Duplicate field detected in call to proto_register_fields: %s is already registered\n",
hfi[i]->abbrev);
return;
}
proto_register_field_common(proto, hfi[i], parent);
}
}
void
proto_deregister_field (const int parent, gint hf_id)
{
header_field_info *hfi;
protocol_t *proto;
guint i;
g_free(last_field_name);
last_field_name = NULL;
if (hf_id == -1 || hf_id == 0)
return;
proto = find_protocol_by_id (parent);
if (!proto || proto->fields->len == 0) {
return;
}
for (i = 0; i < proto->fields->len; i++) {
hfi = (header_field_info *)g_ptr_array_index(proto->fields, i);
if (hfi->id == hf_id) {
g_hash_table_steal(gpa_name_map, hfi->abbrev);
g_ptr_array_remove_index_fast(proto->fields, i);
g_ptr_array_add(deregistered_fields, gpa_hfinfo.hfi[hf_id]);
return;
}
}
}
void
proto_add_deregistered_data (void *data)
{
g_ptr_array_add(deregistered_data, data);
}
static void
free_deregistered_field (gpointer data, gpointer user_data _U_)
{
header_field_info *hfi = (header_field_info *) data;
gint hf_id = hfi->id;
g_free((char *)hfi->name);
g_free((char *)hfi->abbrev);
g_free((char *)hfi->blurb);
if (hfi->strings) {
switch (hfi->type) {
case FT_FRAMENUM:
break;
case FT_PROTOCOL: {
protocol_t *protocol = (protocol_t *)hfi->strings;
g_free((gchar *)protocol->short_name);
break;
}
case FT_BOOLEAN: {
true_false_string *tf = (true_false_string *)hfi->strings;
g_free ((gchar *)tf->true_string);
g_free ((gchar *)tf->false_string);
break;
}
case FT_UINT64:
case FT_INT64: {
val64_string *vs64 = (val64_string *)hfi->strings;
while (vs64->strptr) {
g_free((gchar *)vs64->strptr);
vs64++;
}
break;
}
default: {
value_string *vs = (value_string *)hfi->strings;
while (vs->strptr) {
g_free((gchar *)vs->strptr);
vs++;
}
break;
}
}
if (hfi->type != FT_FRAMENUM) {
g_free((void *)hfi->strings);
}
}
if (hfi->parent == -1)
g_slice_free(header_field_info, hfi);
gpa_hfinfo.hfi[hf_id] = NULL;
}
static void
free_deregistered_data (gpointer data, gpointer user_data _U_)
{
g_free (data);
}
void
proto_free_deregistered_fields (void)
{
expert_free_deregistered_expertinfos();
g_ptr_array_foreach(deregistered_fields, free_deregistered_field, NULL);
g_ptr_array_free(deregistered_fields, TRUE);
deregistered_fields = g_ptr_array_new();
g_ptr_array_foreach(deregistered_data, free_deregistered_data, NULL);
g_ptr_array_free(deregistered_data, TRUE);
deregistered_data = g_ptr_array_new();
}
const char* proto_field_display_to_string(int field_display)
{
return val_to_str_const(field_display, hf_display, "Unknown");
}
static inline port_type
display_to_port_type(field_display_e e)
{
switch (e) {
case BASE_PT_UDP:
return PT_UDP;
case BASE_PT_TCP:
return PT_TCP;
case BASE_PT_DCCP:
return PT_DCCP;
case BASE_PT_SCTP:
return PT_SCTP;
default:
break;
}
return PT_NONE;
}
static void
tmp_fld_check_assert(header_field_info *hfinfo)
{
gchar* tmp_str;
if (!hfinfo->name || !hfinfo->name[0]) {
if (hfinfo->abbrev)
g_error("Field (abbrev='%s') does not have a name\n",
hfinfo->abbrev);
else
g_error("Field does not have a name (nor an abbreviation)\n");
}
if (!hfinfo->abbrev || !hfinfo->abbrev[0])
g_error("Field '%s' does not have an abbreviation\n", hfinfo->name);
if (hfinfo->strings != NULL && !(
(hfinfo->type == FT_UINT8) ||
(hfinfo->type == FT_UINT16) ||
(hfinfo->type == FT_UINT24) ||
(hfinfo->type == FT_UINT32) ||
(hfinfo->type == FT_UINT40) ||
(hfinfo->type == FT_UINT48) ||
(hfinfo->type == FT_UINT56) ||
(hfinfo->type == FT_UINT64) ||
(hfinfo->type == FT_INT8) ||
(hfinfo->type == FT_INT16) ||
(hfinfo->type == FT_INT24) ||
(hfinfo->type == FT_INT32) ||
(hfinfo->type == FT_INT40) ||
(hfinfo->type == FT_INT48) ||
(hfinfo->type == FT_INT56) ||
(hfinfo->type == FT_INT64) ||
(hfinfo->type == FT_BOOLEAN) ||
(hfinfo->type == FT_PROTOCOL) ||
(hfinfo->type == FT_FRAMENUM) ))
g_error("Field '%s' (%s) has a 'strings' value but is of type %s"
" (which is not allowed to have strings)\n",
hfinfo->name, hfinfo->abbrev, ftype_name(hfinfo->type));
#if 0
if ((hfinfo->strings != NULL) &&
!(hfinfo->display & BASE_RANGE_STRING) &&
!((hfinfo->display & FIELD_DISPLAY_E_MASK) == BASE_CUSTOM) &&
(
(hfinfo->type == FT_UINT8) ||
(hfinfo->type == FT_UINT16) ||
(hfinfo->type == FT_UINT24) ||
(hfinfo->type == FT_UINT32) ||
(hfinfo->type == FT_INT8) ||
(hfinfo->type == FT_INT16) ||
(hfinfo->type == FT_INT24) ||
(hfinfo->type == FT_INT32) ||
(hfinfo->type == FT_FRAMENUM) )) {
int n, m;
const value_string *start_values;
const value_string *current;
if (hfinfo->display & BASE_EXT_STRING)
start_values = VALUE_STRING_EXT_VS_P(((const value_string_ext*)hfinfo->strings));
else
start_values = (const value_string*)hfinfo->strings;
current = start_values;
for (n=0; current; n++, current++) {
if ((current->value == 0) && (current->strptr == NULL)) {
break;
}
for (m=0; m < n; m++) {
if ((start_values[m].value == current->value) &&
(strcmp(start_values[m].strptr, current->strptr) != 0)) {
g_warning("Field '%s' (%s) has a conflicting entry in its"
" value_string: %u is at indices %u (%s) and %u (%s))\n",
hfinfo->name, hfinfo->abbrev,
current->value, m, start_values[m].strptr, n, current->strptr);
}
}
}
}
#endif
switch (hfinfo->type) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_INT64:
switch (hfinfo->display & FIELD_DISPLAY_E_MASK) {
case BASE_HEX:
case BASE_OCT:
case BASE_DEC_HEX:
case BASE_HEX_DEC:
tmp_str = val_to_str_wmem(NULL, hfinfo->display, hf_display, "(Bit count: %d)");
g_error("Field '%s' (%s) is signed (%s) but is being displayed unsigned (%s)\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type), tmp_str);
wmem_free(NULL, tmp_str);
}
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT40:
case FT_UINT48:
case FT_UINT56:
case FT_UINT64:
if (IS_BASE_PORT(hfinfo->display)) {
tmp_str = val_to_str_wmem(NULL, hfinfo->display, hf_display, "(Unknown: 0x%x)");
if (hfinfo->type != FT_UINT16) {
g_error("Field '%s' (%s) has 'display' value %s but it can only be used with FT_UINT16, not %s\n",
hfinfo->name, hfinfo->abbrev,
tmp_str, ftype_name(hfinfo->type));
}
if (hfinfo->strings != NULL) {
g_error("Field '%s' (%s) is an %s (%s) but has a strings value\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type), tmp_str);
}
if (hfinfo->bitmask != 0) {
g_error("Field '%s' (%s) is an %s (%s) but has a bitmask\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type), tmp_str);
}
wmem_free(NULL, tmp_str);
break;
}
switch (hfinfo->display & FIELD_DISPLAY_E_MASK) {
case BASE_DEC:
case BASE_HEX:
case BASE_OCT:
case BASE_DEC_HEX:
case BASE_HEX_DEC:
case BASE_CUSTOM:
break;
case BASE_NONE:
if (hfinfo->strings == NULL)
g_error("Field '%s' (%s) is an integral value (%s)"
" but is being displayed as BASE_NONE but"
" without a strings conversion",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type));
break;
default:
tmp_str = val_to_str_wmem(NULL, hfinfo->display, hf_display, "(Unknown: 0x%x)");
g_error("Field '%s' (%s) is an integral value (%s)"
" but is being displayed as %s\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type), tmp_str);
wmem_free(NULL, tmp_str);
}
break;
case FT_BYTES:
switch (hfinfo->display & FIELD_DISPLAY_E_MASK) {
case BASE_NONE:
case SEP_DOT:
case SEP_DASH:
case SEP_COLON:
case SEP_SPACE:
break;
default:
tmp_str = val_to_str_wmem(NULL, hfinfo->display, hf_display, "(Bit count: %d)");
g_error("Field '%s' (%s) is an byte array but is being displayed as %s instead of BASE_NONE, SEP_DOT, SEP_DASH, SEP_COLON, or SEP_SPACE\n",
hfinfo->name, hfinfo->abbrev, tmp_str);
wmem_free(NULL, tmp_str);
}
if (hfinfo->bitmask != 0)
g_error("Field '%s' (%s) is an %s but has a bitmask\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type));
if (hfinfo->strings != NULL)
g_error("Field '%s' (%s) is an %s but has a strings value\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type));
break;
case FT_PROTOCOL:
case FT_FRAMENUM:
if (hfinfo->display != BASE_NONE) {
tmp_str = val_to_str_wmem(NULL, hfinfo->display, hf_display, "(Bit count: %d)");
g_error("Field '%s' (%s) is an %s but is being displayed as %s instead of BASE_NONE\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type), tmp_str);
wmem_free(NULL, tmp_str);
}
if (hfinfo->bitmask != 0)
g_error("Field '%s' (%s) is an %s but has a bitmask\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type));
break;
case FT_BOOLEAN:
break;
case FT_ABSOLUTE_TIME:
if (!(hfinfo->display == ABSOLUTE_TIME_LOCAL ||
hfinfo->display == ABSOLUTE_TIME_UTC ||
hfinfo->display == ABSOLUTE_TIME_DOY_UTC)) {
tmp_str = val_to_str_wmem(NULL, hfinfo->display, hf_display, "(Bit count: %d)");
g_error("Field '%s' (%s) is a %s but is being displayed as %s instead of as a time\n",
hfinfo->name, hfinfo->abbrev, ftype_name(hfinfo->type), tmp_str);
wmem_free(NULL, tmp_str);
}
if (hfinfo->bitmask != 0)
g_error("Field '%s' (%s) is an %s but has a bitmask\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type));
break;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
switch (hfinfo->display) {
case STR_ASCII:
case STR_UNICODE:
break;
default:
tmp_str = val_to_str_wmem(NULL, hfinfo->display, hf_display, "(Unknown: 0x%x)");
g_error("Field '%s' (%s) is an string value (%s)"
" but is being displayed as %s\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type), tmp_str);
wmem_free(NULL, tmp_str);
}
if (hfinfo->bitmask != 0)
g_error("Field '%s' (%s) is an %s but has a bitmask\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type));
if (hfinfo->strings != NULL)
g_error("Field '%s' (%s) is an %s but has a strings value\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type));
break;
case FT_IPv4:
switch (hfinfo->display) {
case BASE_NONE:
case BASE_NETMASK:
break;
default:
tmp_str = val_to_str_wmem(NULL, hfinfo->display, hf_display, "(Unknown: 0x%x)");
g_error("Field '%s' (%s) is an IPv4 value (%s)"
" but is being displayed as %s\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type), tmp_str);
wmem_free(NULL, tmp_str);
break;
}
break;
default:
if (hfinfo->display != BASE_NONE) {
tmp_str = val_to_str_wmem(NULL, hfinfo->display, hf_display, "(Bit count: %d)");
g_error("Field '%s' (%s) is an %s but is being displayed as %s instead of BASE_NONE\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type),
tmp_str);
wmem_free(NULL, tmp_str);
}
if (hfinfo->bitmask != 0)
g_error("Field '%s' (%s) is an %s but has a bitmask\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type));
if (hfinfo->strings != NULL)
g_error("Field '%s' (%s) is an %s but has a strings value\n",
hfinfo->name, hfinfo->abbrev,
ftype_name(hfinfo->type));
break;
}
}
static enum ftenum
_ftype_common(enum ftenum type)
{
switch (type) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
return FT_INT32;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_IPXNET:
case FT_FRAMENUM:
return FT_UINT32;
case FT_UINT64:
case FT_EUI64:
return FT_UINT64;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
return FT_STRING;
case FT_FLOAT:
case FT_DOUBLE:
return FT_DOUBLE;
case FT_BYTES:
case FT_UINT_BYTES:
case FT_ETHER:
case FT_OID:
return FT_BYTES;
case FT_ABSOLUTE_TIME:
case FT_RELATIVE_TIME:
return FT_ABSOLUTE_TIME;
default:
return type;
}
}
static void
register_type_length_mismatch(void)
{
static ei_register_info ei[] = {
{ &ei_type_length_mismatch_error, { "_ws.type_length.mismatch", PI_MALFORMED, PI_ERROR, "Trying to fetch X with length Y", EXPFILL }},
{ &ei_type_length_mismatch_warn, { "_ws.type_length.mismatch", PI_MALFORMED, PI_WARN, "Trying to fetch X with length Y", EXPFILL }},
};
expert_module_t* expert_type_length_mismatch;
proto_type_length_mismatch = proto_register_protocol("Type Length Mismatch", "Type length mismatch", "_ws.type_length");
expert_type_length_mismatch = expert_register_protocol(proto_type_length_mismatch);
expert_register_field_array(expert_type_length_mismatch, ei, array_length(ei));
proto_set_cant_toggle(proto_type_length_mismatch);
}
static void
register_number_string_decoding_error(void)
{
static ei_register_info ei[] = {
{ &ei_number_string_decoding_failed_error,
{ "_ws.number_string.decoding_error.failed", PI_MALFORMED, PI_ERROR,
"Failed to decode number from string", EXPFILL
}
},
{ &ei_number_string_decoding_erange_error,
{ "_ws.number_string.decoding_error.erange", PI_MALFORMED, PI_ERROR,
"Decoded number from string is out of valid range", EXPFILL
}
},
};
expert_module_t* expert_number_string_decoding_error;
proto_number_string_decoding_error =
proto_register_protocol("Number-String Decoding Error",
"Number-string decoding error",
"_ws.number_string.decoding_error");
expert_number_string_decoding_error =
expert_register_protocol(proto_number_string_decoding_error);
expert_register_field_array(expert_number_string_decoding_error, ei, array_length(ei));
proto_set_cant_toggle(proto_number_string_decoding_error);
}
static int
proto_register_field_init(header_field_info *hfinfo, const int parent)
{
tmp_fld_check_assert(hfinfo);
hfinfo->parent = parent;
hfinfo->same_name_next = NULL;
hfinfo->same_name_prev_id = -1;
if (gpa_hfinfo.len >= gpa_hfinfo.allocated_len) {
if (!gpa_hfinfo.hfi) {
gpa_hfinfo.allocated_len = PROTO_PRE_ALLOC_HF_FIELDS_MEM;
gpa_hfinfo.hfi = (header_field_info **)g_malloc(sizeof(header_field_info *)*PROTO_PRE_ALLOC_HF_FIELDS_MEM);
} else {
gpa_hfinfo.allocated_len += 1000;
gpa_hfinfo.hfi = (header_field_info **)g_realloc(gpa_hfinfo.hfi,
sizeof(header_field_info *)*gpa_hfinfo.allocated_len);
}
}
gpa_hfinfo.hfi[gpa_hfinfo.len] = hfinfo;
gpa_hfinfo.len++;
hfinfo->id = gpa_hfinfo.len - 1;
if ((hfinfo->name[0] != 0) && (hfinfo->abbrev[0] != 0 )) {
header_field_info *same_name_next_hfinfo;
guchar c;
c = wrs_check_charset(fld_abbrev_chars, hfinfo->abbrev);
if (c) {
if (g_ascii_isprint(c))
fprintf(stderr, "Invalid character '%c' in filter name '%s'\n", c, hfinfo->abbrev);
else
fprintf(stderr, "Invalid byte \\%03o in filter name '%s'\n", c, hfinfo->abbrev);
DISSECTOR_ASSERT_NOT_REACHED();
}
same_name_hfinfo = NULL;
g_hash_table_insert(gpa_name_map, (gpointer) (hfinfo->abbrev), hfinfo);
if (same_name_hfinfo) {
same_name_next_hfinfo =
same_name_hfinfo->same_name_next;
hfinfo->same_name_next = same_name_next_hfinfo;
if (same_name_next_hfinfo)
same_name_next_hfinfo->same_name_prev_id = hfinfo->id;
same_name_hfinfo->same_name_next = hfinfo;
hfinfo->same_name_prev_id = same_name_hfinfo->id;
#ifdef ENABLE_CHECK_FILTER
while (same_name_hfinfo) {
if (_ftype_common(hfinfo->type) != _ftype_common(same_name_hfinfo->type))
fprintf(stderr, "'%s' exists multiple times with NOT compatible types: %s and %s\n", hfinfo->abbrev, ftype_name(hfinfo->type), ftype_name(same_name_hfinfo->type));
same_name_hfinfo = same_name_hfinfo->same_name_next;
}
#endif
}
}
return hfinfo->id;
}
void
proto_register_subtree_array(gint *const *indices, const int num_indices)
{
int i;
gint *const *ptr = indices;
if (tree_is_expanded != NULL) {
tree_is_expanded = (guint32 *)g_realloc(tree_is_expanded, (1+((num_tree_types + num_indices)/32)) * sizeof(guint32));
for (i = num_tree_types; i < num_tree_types + num_indices; i++)
tree_is_expanded[i >> 5] &= ~(1U << (i & 31));
}
for (i = 0; i < num_indices; i++, ptr++, num_tree_types++) {
if (**ptr != -1) {
g_error("register_subtree_array: subtree item type (ett_...) not -1 !"
" This is a development error:"
" Either the subtree item type has already been assigned or"
" was not initialized to -1.");
}
**ptr = num_tree_types;
}
}
static inline gsize
label_concat(char *label_str, gsize pos, const char *str)
{
if (pos < ITEM_LABEL_LENGTH)
pos += g_strlcpy(label_str + pos, str, ITEM_LABEL_LENGTH - pos);
return pos;
}
static void
label_mark_truncated(char *label_str, gsize name_pos)
{
static const char trunc_str[] = " [truncated]";
const size_t trunc_len = sizeof(trunc_str)-1;
gchar *last_char;
if (name_pos < ITEM_LABEL_LENGTH - trunc_len) {
memmove(label_str + name_pos + trunc_len, label_str + name_pos, ITEM_LABEL_LENGTH - name_pos - trunc_len);
memcpy(label_str + name_pos, trunc_str, trunc_len);
last_char = g_utf8_prev_char(&label_str[ITEM_LABEL_LENGTH]);
*last_char = '\0';
} else if (name_pos < ITEM_LABEL_LENGTH)
g_strlcpy(label_str + name_pos, trunc_str, ITEM_LABEL_LENGTH - name_pos);
}
static gsize
label_fill(char *label_str, gsize pos, const header_field_info *hfinfo, const char *text)
{
gsize name_pos;
name_pos = pos = label_concat(label_str, pos, hfinfo->name);
pos = label_concat(label_str, pos, ": ");
pos = label_concat(label_str, pos, text ? text : "(null)");
if (pos >= ITEM_LABEL_LENGTH) {
label_mark_truncated(label_str, name_pos);
}
return pos;
}
static gsize
label_fill_descr(char *label_str, gsize pos, const header_field_info *hfinfo, const char *text, const char *descr)
{
gsize name_pos;
name_pos = pos = label_concat(label_str, pos, hfinfo->name);
pos = label_concat(label_str, pos, ": ");
pos = label_concat(label_str, pos, text ? text : "(null)");
pos = label_concat(label_str, pos, " (");
pos = label_concat(label_str, pos, descr ? descr : "(null)");
pos = label_concat(label_str, pos, ")");
if (pos >= ITEM_LABEL_LENGTH) {
label_mark_truncated(label_str, name_pos);
}
return pos;
}
void
proto_item_fill_label(field_info *fi, gchar *label_str)
{
header_field_info *hfinfo;
guint8 *bytes;
guint32 integer;
guint64 integer64;
ipv4_addr_and_mask *ipv4;
e_guid_t *guid;
guint32 n_addr;
gchar *name;
address addr;
char *addr_str;
char *tmp;
if (!fi) {
if (label_str)
label_str[0]= '\0';
return;
}
hfinfo = fi->hfinfo;
switch (hfinfo->type) {
case FT_NONE:
case FT_PROTOCOL:
g_strlcpy(label_str, hfinfo->name, ITEM_LABEL_LENGTH);
break;
case FT_BOOLEAN:
fill_label_boolean(fi, label_str);
break;
case FT_BYTES:
case FT_UINT_BYTES:
bytes = (guint8 *)fvalue_get(&fi->value);
if (bytes) {
char* str = NULL;
switch(hfinfo->display)
{
case SEP_DOT:
str = bytestring_to_str(NULL, bytes, fvalue_length(&fi->value), '.');
break;
case SEP_DASH:
str = bytestring_to_str(NULL, bytes, fvalue_length(&fi->value), '-');
break;
case SEP_COLON:
str = bytestring_to_str(NULL, bytes, fvalue_length(&fi->value), ':');
break;
case SEP_SPACE:
str = bytestring_to_str(NULL, bytes, fvalue_length(&fi->value), ' ');
break;
case BASE_NONE:
default:
if (prefs.display_byte_fields_with_spaces)
{
str = bytestring_to_str(NULL, bytes, fvalue_length(&fi->value), ' ');
}
else
{
str = bytes_to_str(NULL, bytes, fvalue_length(&fi->value));
}
break;
}
label_fill(label_str, 0, hfinfo, str);
wmem_free(NULL, str);
} else {
if (hfinfo->display & BASE_ALLOW_ZERO) {
label_fill(label_str, 0, hfinfo, "<none>");
} else {
label_fill(label_str, 0, hfinfo, "<MISSING>");
}
}
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
if (hfinfo->bitmask) {
fill_label_bitfield(fi, label_str, FALSE);
} else {
fill_label_number(fi, label_str, FALSE);
}
break;
case FT_FRAMENUM:
fill_label_number(fi, label_str, FALSE);
break;
case FT_UINT40:
case FT_UINT48:
case FT_UINT56:
case FT_UINT64:
if (hfinfo->bitmask) {
fill_label_bitfield64(fi, label_str, FALSE);
} else {
fill_label_number64(fi, label_str, FALSE);
}
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
if (hfinfo->bitmask) {
fill_label_bitfield(fi, label_str, TRUE);
} else {
fill_label_number(fi, label_str, TRUE);
}
break;
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_INT64:
if (hfinfo->bitmask) {
fill_label_bitfield64(fi, label_str, TRUE);
} else {
fill_label_number64(fi, label_str, TRUE);
}
break;
case FT_FLOAT:
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %." G_STRINGIFY(FLT_DIG) "g",
hfinfo->name, fvalue_get_floating(&fi->value));
break;
case FT_DOUBLE:
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %." G_STRINGIFY(DBL_DIG) "g",
hfinfo->name, fvalue_get_floating(&fi->value));
break;
case FT_ABSOLUTE_TIME:
tmp = abs_time_to_str(NULL, (const nstime_t *)fvalue_get(&fi->value), (absolute_time_display_e)hfinfo->display, TRUE);
label_fill(label_str, 0, hfinfo, tmp);
wmem_free(NULL, tmp);
break;
case FT_RELATIVE_TIME:
tmp = rel_time_to_secs_str(NULL, (const nstime_t *)fvalue_get(&fi->value));
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s seconds", hfinfo->name, tmp);
wmem_free(NULL, tmp);
break;
case FT_IPXNET:
integer = fvalue_get_uinteger(&fi->value);
tmp = get_ipxnet_name(NULL, integer);
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s (0x%08X)", hfinfo->name,
tmp, integer);
wmem_free(NULL, tmp);
break;
case FT_AX25:
addr.type = AT_AX25;
addr.len = AX25_ADDR_LEN;
addr.data = (guint8 *)fvalue_get(&fi->value);
addr_str = (char*)address_to_str(NULL, &addr);
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s", hfinfo->name, addr_str);
wmem_free(NULL, addr_str);
break;
case FT_VINES:
addr.type = vines_address_type;
addr.len = VINES_ADDR_LEN;
addr.data = (guint8 *)fvalue_get(&fi->value);
addr_str = (char*)address_to_str(NULL, &addr);
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s", hfinfo->name, addr_str);
wmem_free(NULL, addr_str);
break;
case FT_ETHER:
bytes = (guint8 *)fvalue_get(&fi->value);
addr.type = AT_ETHER;
addr.len = 6;
addr.data = bytes;
addr_str = (char*)address_with_resolution_to_str(NULL, &addr);
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s", hfinfo->name, addr_str);
wmem_free(NULL, addr_str);
break;
case FT_IPv4:
ipv4 = (ipv4_addr_and_mask *)fvalue_get(&fi->value);
n_addr = ipv4_get_net_order_addr(ipv4);
addr.type = AT_IPv4;
addr.len = 4;
addr.data = &n_addr;
if (hfinfo->display == BASE_NETMASK)
{
addr_str = (char*)address_to_str(NULL, &addr);
}
else
{
addr_str = (char*)address_with_resolution_to_str(NULL, &addr);
}
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s", hfinfo->name, addr_str);
wmem_free(NULL, addr_str);
break;
case FT_IPv6:
bytes = (guint8 *)fvalue_get(&fi->value);
addr.type = AT_IPv6;
addr.len = 16;
addr.data = bytes;
addr_str = (char*)address_with_resolution_to_str(NULL, &addr);
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s", hfinfo->name, addr_str);
wmem_free(NULL, addr_str);
break;
case FT_FCWWN:
addr.type = AT_FCWWN;
addr.len = FCWWN_ADDR_LEN;
addr.data = (guint8 *)fvalue_get(&fi->value);
addr_str = (char*)address_with_resolution_to_str(NULL, &addr);
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s", hfinfo->name, addr_str);
wmem_free(NULL, addr_str);
break;
case FT_GUID:
guid = (e_guid_t *)fvalue_get(&fi->value);
tmp = guid_to_str(NULL, guid);
label_fill(label_str, 0, hfinfo, tmp);
wmem_free(NULL, tmp);
break;
case FT_OID:
bytes = (guint8 *)fvalue_get(&fi->value);
name = oid_resolved_from_encoded(NULL, bytes, fvalue_length(&fi->value));
tmp = oid_encoded2string(NULL, bytes, fvalue_length(&fi->value));
if (name) {
label_fill_descr(label_str, 0, hfinfo, tmp, name);
wmem_free(NULL, name);
} else {
label_fill(label_str, 0, hfinfo, tmp);
}
wmem_free(NULL, tmp);
break;
case FT_REL_OID:
bytes = (guint8 *)fvalue_get(&fi->value);
name = rel_oid_resolved_from_encoded(NULL, bytes, fvalue_length(&fi->value));
tmp = rel_oid_encoded2string(NULL, bytes, fvalue_length(&fi->value));
if (name) {
label_fill_descr(label_str, 0, hfinfo, tmp, name);
wmem_free(NULL, name);
} else {
label_fill(label_str, 0, hfinfo, tmp);
}
wmem_free(NULL, tmp);
break;
case FT_SYSTEM_ID:
bytes = (guint8 *)fvalue_get(&fi->value);
tmp = print_system_id(NULL, bytes, fvalue_length(&fi->value));
label_fill(label_str, 0, hfinfo, tmp);
wmem_free(NULL, tmp);
break;
case FT_EUI64:
integer64 = fvalue_get_uinteger64(&fi->value);
addr_str = eui64_to_str(NULL, integer64);
tmp = (char*)eui64_to_display(NULL, integer64);
label_fill_descr(label_str, 0, hfinfo, tmp, addr_str);
wmem_free(NULL, tmp);
wmem_free(NULL, addr_str);
break;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
bytes = (guint8 *)fvalue_get(&fi->value);
label_fill(label_str, 0, hfinfo, hfinfo_format_text(hfinfo, bytes));
break;
case FT_IEEE_11073_SFLOAT:
tmp = fvalue_to_string_repr(NULL, &fi->value, FTREPR_DISPLAY, hfinfo->display);
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s",
hfinfo->name, tmp);
wmem_free(NULL, tmp);
break;
case FT_IEEE_11073_FLOAT:
tmp = fvalue_to_string_repr(NULL, &fi->value, FTREPR_DISPLAY, hfinfo->display);
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s",
hfinfo->name, tmp);
wmem_free(NULL, tmp);
break;
default:
g_error("hfinfo->type %d (%s) not handled\n",
hfinfo->type, ftype_name(hfinfo->type));
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
static void
fill_label_boolean(field_info *fi, gchar *label_str)
{
char *p = label_str;
int bitfield_byte_length = 0, bitwidth;
guint64 unshifted_value;
guint64 value;
header_field_info *hfinfo = fi->hfinfo;
const true_false_string *tfstring = (const true_false_string *)&tfs_true_false;
if (hfinfo->strings) {
tfstring = (const struct true_false_string*) hfinfo->strings;
}
value = fvalue_get_uinteger64(&fi->value);
if (hfinfo->bitmask) {
bitwidth = hfinfo_container_bitwidth(hfinfo);
unshifted_value = value;
unshifted_value <<= hfinfo_bitshift(hfinfo);
p = decode_bitfield_value(label_str, unshifted_value, hfinfo->bitmask, bitwidth);
bitfield_byte_length = (int) (p - label_str);
}
label_fill(label_str, bitfield_byte_length, hfinfo, value ? tfstring->true_string : tfstring->false_string);
}
static const char *
hf_try_val_to_str(guint32 value, const header_field_info *hfinfo)
{
if (hfinfo->display & BASE_RANGE_STRING)
return try_rval_to_str(value, (const range_string *) hfinfo->strings);
if (hfinfo->display & BASE_EXT_STRING)
return try_val_to_str_ext(value, (value_string_ext *) hfinfo->strings);
if (hfinfo->display & BASE_VAL64_STRING)
return try_val64_to_str(value, (const val64_string *) hfinfo->strings);
return try_val_to_str(value, (const value_string *) hfinfo->strings);
}
static const char *
hf_try_val64_to_str(guint64 value, const header_field_info *hfinfo)
{
if (hfinfo->display & BASE_VAL64_STRING)
return try_val64_to_str(value, (const val64_string *) hfinfo->strings);
DISSECTOR_ASSERT_NOT_REACHED();
return NULL;
}
static const char *
hf_try_val_to_str_const(guint32 value, const header_field_info *hfinfo, const char *unknown_str)
{
const char *str = hf_try_val_to_str(value, hfinfo);
return (str) ? str : unknown_str;
}
static const char *
hf_try_val64_to_str_const(guint64 value, const header_field_info *hfinfo, const char *unknown_str)
{
const char *str = hf_try_val64_to_str(value, hfinfo);
return (str) ? str : unknown_str;
}
static void
fill_label_bitfield(field_info *fi, gchar *label_str, gboolean is_signed)
{
char *p;
int bitfield_byte_length, bitwidth;
guint32 unshifted_value;
guint32 value;
char buf[32];
const char *out;
header_field_info *hfinfo = fi->hfinfo;
bitwidth = hfinfo_container_bitwidth(hfinfo);
if (is_signed)
value = fvalue_get_sinteger(&fi->value);
else
value = fvalue_get_uinteger(&fi->value);
unshifted_value = value;
if (hfinfo->bitmask) {
unshifted_value <<= hfinfo_bitshift(hfinfo);
}
p = decode_bitfield_value(label_str, unshifted_value, hfinfo->bitmask, bitwidth);
bitfield_byte_length = (int) (p - label_str);
if (hfinfo->display == BASE_CUSTOM) {
gchar tmp[ITEM_LABEL_LENGTH];
const custom_fmt_func_t fmtfunc = (const custom_fmt_func_t)hfinfo->strings;
DISSECTOR_ASSERT(fmtfunc);
fmtfunc(tmp, value);
label_fill(label_str, bitfield_byte_length, hfinfo, tmp);
}
else if (hfinfo->strings) {
const char *val_str = hf_try_val_to_str_const(value, hfinfo, "Unknown");
out = hfinfo_number_vals_format(hfinfo, buf, value);
if (out == NULL)
label_fill(label_str, bitfield_byte_length, hfinfo, val_str);
else
label_fill_descr(label_str, bitfield_byte_length, hfinfo, val_str, out);
}
else {
out = hfinfo_number_value_format(hfinfo, buf, value);
label_fill(label_str, bitfield_byte_length, hfinfo, out);
}
}
static void
fill_label_bitfield64(field_info *fi, gchar *label_str, gboolean is_signed)
{
char *p;
int bitfield_byte_length, bitwidth;
guint64 unshifted_value;
guint64 value;
char buf[48];
const char *out;
header_field_info *hfinfo = fi->hfinfo;
bitwidth = hfinfo_container_bitwidth(hfinfo);
if (is_signed)
value = fvalue_get_sinteger64(&fi->value);
else
value = fvalue_get_uinteger64(&fi->value);
unshifted_value = value;
if (hfinfo->bitmask) {
unshifted_value <<= hfinfo_bitshift(hfinfo);
}
p = decode_bitfield_value(label_str, unshifted_value, hfinfo->bitmask, bitwidth);
bitfield_byte_length = (int) (p - label_str);
if (hfinfo->display == BASE_CUSTOM) {
gchar tmp[ITEM_LABEL_LENGTH];
const custom_fmt_func_64_t fmtfunc64 = (const custom_fmt_func_64_t)hfinfo->strings;
DISSECTOR_ASSERT(fmtfunc64);
fmtfunc64(tmp, value);
label_fill(label_str, bitfield_byte_length, hfinfo, tmp);
}
else if (hfinfo->strings) {
const char *val_str = hf_try_val64_to_str_const(value, hfinfo, "Unknown");
out = hfinfo_number_vals_format64(hfinfo, buf, value);
if (out == NULL)
label_fill(label_str, bitfield_byte_length, hfinfo, val_str);
else
label_fill_descr(label_str, bitfield_byte_length, hfinfo, val_str, out);
}
else {
out = hfinfo_number_value_format64(hfinfo, buf, value);
label_fill(label_str, bitfield_byte_length, hfinfo, out);
}
}
static void
fill_label_number(field_info *fi, gchar *label_str, gboolean is_signed)
{
header_field_info *hfinfo = fi->hfinfo;
guint32 value;
char buf[32];
const char *out;
if (is_signed)
value = fvalue_get_sinteger(&fi->value);
else
value = fvalue_get_uinteger(&fi->value);
if (hfinfo->display == BASE_CUSTOM) {
gchar tmp[ITEM_LABEL_LENGTH];
const custom_fmt_func_t fmtfunc = (const custom_fmt_func_t)hfinfo->strings;
DISSECTOR_ASSERT(fmtfunc);
fmtfunc(tmp, value);
label_fill(label_str, 0, hfinfo, tmp);
}
else if (hfinfo->strings && hfinfo->type != FT_FRAMENUM) {
const char *val_str = hf_try_val_to_str_const(value, hfinfo, "Unknown");
out = hfinfo_number_vals_format(hfinfo, buf, value);
if (out == NULL)
label_fill(label_str, 0, hfinfo, val_str);
else
label_fill_descr(label_str, 0, hfinfo, val_str, out);
}
else if (IS_BASE_PORT(hfinfo->display)) {
gchar tmp[ITEM_LABEL_LENGTH];
port_with_resolution_to_str_buf(tmp, sizeof(tmp),
display_to_port_type((field_display_e)hfinfo->display), value);
label_fill(label_str, 0, hfinfo, tmp);
}
else {
out = hfinfo_number_value_format(hfinfo, buf, value);
label_fill(label_str, 0, hfinfo, out);
}
}
static void
fill_label_number64(field_info *fi, gchar *label_str, gboolean is_signed)
{
header_field_info *hfinfo = fi->hfinfo;
guint64 value;
char buf[48];
const char *out;
if (is_signed)
value = fvalue_get_sinteger64(&fi->value);
else
value = fvalue_get_uinteger64(&fi->value);
if (hfinfo->display == BASE_CUSTOM) {
gchar tmp[ITEM_LABEL_LENGTH];
const custom_fmt_func_64_t fmtfunc64 = (const custom_fmt_func_64_t)hfinfo->strings;
DISSECTOR_ASSERT(fmtfunc64);
fmtfunc64(tmp, value);
label_fill(label_str, 0, hfinfo, tmp);
}
else if (hfinfo->strings) {
const char *val_str = hf_try_val64_to_str_const(value, hfinfo, "Unknown");
out = hfinfo_number_vals_format64(hfinfo, buf, value);
if (out == NULL)
label_fill(label_str, 0, hfinfo, val_str);
else
label_fill_descr(label_str, 0, hfinfo, val_str, out);
}
else {
out = hfinfo_number_value_format64(hfinfo, buf, value);
label_fill(label_str, 0, hfinfo, out);
}
}
int
hfinfo_bitshift(const header_field_info *hfinfo)
{
return ws_ctz(hfinfo->bitmask);
}
static int
hfinfo_mask_bitwidth(const header_field_info *hfinfo)
{
if (!hfinfo->bitmask) {
return 0;
}
return ws_ilog2(hfinfo->bitmask) - ws_ctz(hfinfo->bitmask) + 1;
}
static int
hfinfo_type_bitwidth(enum ftenum type)
{
int bitwidth = 0;
switch (type) {
case FT_UINT8:
case FT_INT8:
bitwidth = 8;
break;
case FT_UINT16:
case FT_INT16:
bitwidth = 16;
break;
case FT_UINT24:
case FT_INT24:
bitwidth = 24;
break;
case FT_UINT32:
case FT_INT32:
bitwidth = 32;
break;
case FT_UINT40:
case FT_INT40:
bitwidth = 40;
break;
case FT_UINT48:
case FT_INT48:
bitwidth = 48;
break;
case FT_UINT56:
case FT_INT56:
bitwidth = 56;
break;
case FT_UINT64:
case FT_INT64:
bitwidth = 64;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
return bitwidth;
}
static int
hfinfo_container_bitwidth(const header_field_info *hfinfo)
{
if (!hfinfo->bitmask) {
return 0;
}
if (hfinfo->type == FT_BOOLEAN) {
return hfinfo->display;
}
return hfinfo_type_bitwidth(hfinfo->type);
}
static int
hfinfo_hex_digits(const header_field_info *hfinfo)
{
int bitwidth;
if (hfinfo->bitmask != 0) {
bitwidth = hfinfo_mask_bitwidth(hfinfo);
} else {
bitwidth = hfinfo_type_bitwidth(hfinfo->type);
}
return (bitwidth + 3) / 4;
}
static const char *
hfinfo_number_value_format_display(const header_field_info *hfinfo, int display, char buf[32], guint32 value)
{
char *ptr = &buf[31];
gboolean isint = IS_FT_INT(hfinfo->type);
*ptr = '\0';
switch (display & FIELD_DISPLAY_E_MASK) {
case BASE_DEC:
return isint ? int_to_str_back(ptr, (gint32) value) : uint_to_str_back(ptr, value);
case BASE_DEC_HEX:
*(--ptr) = ')';
ptr = hex_to_str_back(ptr, hfinfo_hex_digits(hfinfo), value);
*(--ptr) = '(';
*(--ptr) = ' ';
ptr = isint ? int_to_str_back(ptr, (gint32) value) : uint_to_str_back(ptr, value);
return ptr;
case BASE_OCT:
return oct_to_str_back(ptr, value);
case BASE_HEX:
return hex_to_str_back(ptr, hfinfo_hex_digits(hfinfo), value);
case BASE_HEX_DEC:
*(--ptr) = ')';
ptr = isint ? int_to_str_back(ptr, (gint32) value) : uint_to_str_back(ptr, value);
*(--ptr) = '(';
*(--ptr) = ' ';
ptr = hex_to_str_back(ptr, hfinfo_hex_digits(hfinfo), value);
return ptr;
case BASE_PT_UDP:
case BASE_PT_TCP:
case BASE_PT_DCCP:
case BASE_PT_SCTP:
port_with_resolution_to_str_buf(buf, 32,
display_to_port_type((field_display_e)display), value);
return buf;
default:
g_assert_not_reached();
}
return ptr;
}
static const char *
hfinfo_number_value_format_display64(const header_field_info *hfinfo, int display, char buf[48], guint64 value)
{
char *ptr = &buf[47];
gboolean isint = IS_FT_INT(hfinfo->type);
*ptr = '\0';
switch (display) {
case BASE_DEC:
return isint ? int64_to_str_back(ptr, (gint64) value) : uint64_to_str_back(ptr, value);
case BASE_DEC_HEX:
*(--ptr) = ')';
ptr = hex64_to_str_back(ptr, hfinfo_hex_digits(hfinfo), value);
*(--ptr) = '(';
*(--ptr) = ' ';
ptr = isint ? int64_to_str_back(ptr, (gint64) value) : uint64_to_str_back(ptr, value);
return ptr;
case BASE_OCT:
return oct64_to_str_back(ptr, value);
case BASE_HEX:
return hex64_to_str_back(ptr, hfinfo_hex_digits(hfinfo), value);
case BASE_HEX_DEC:
*(--ptr) = ')';
ptr = isint ? int64_to_str_back(ptr, (gint64) value) : uint64_to_str_back(ptr, value);
*(--ptr) = '(';
*(--ptr) = ' ';
ptr = hex64_to_str_back(ptr, hfinfo_hex_digits(hfinfo), value);
return ptr;
default:
g_assert_not_reached();
}
return ptr;
}
static const char *
hfinfo_number_value_format(const header_field_info *hfinfo, char buf[32], guint32 value)
{
int display = hfinfo->display;
if (hfinfo->type == FT_FRAMENUM) {
display = BASE_DEC;
}
return hfinfo_number_value_format_display(hfinfo, display, buf, value);
}
static const char *
hfinfo_number_value_format64(const header_field_info *hfinfo, char buf[64], guint64 value)
{
int display = hfinfo->display;
if (hfinfo->type == FT_FRAMENUM) {
display = BASE_DEC;
}
return hfinfo_number_value_format_display64(hfinfo, display, buf, value);
}
static const char *
hfinfo_numeric_value_format(const header_field_info *hfinfo, char buf[32], guint32 value)
{
int display = hfinfo->display & FIELD_DISPLAY_E_MASK;
if (hfinfo->type == FT_FRAMENUM) {
display = BASE_DEC;
}
if (IS_BASE_PORT(display)) {
display = BASE_DEC;
}
switch (display) {
case BASE_NONE:
case BASE_DEC_HEX:
case BASE_OCT:
case BASE_CUSTOM:
display = BASE_DEC;
break;
case BASE_HEX_DEC:
display = BASE_HEX;
break;
}
return hfinfo_number_value_format_display(hfinfo, display, buf, value);
}
static const char *
hfinfo_numeric_value_format64(const header_field_info *hfinfo, char buf[64], guint64 value)
{
int display = hfinfo->display & FIELD_DISPLAY_E_MASK;
if (hfinfo->type == FT_FRAMENUM) {
display = BASE_DEC;
}
switch (display) {
case BASE_NONE:
case BASE_DEC_HEX:
case BASE_OCT:
case BASE_CUSTOM:
display = BASE_DEC;
break;
case BASE_HEX_DEC:
display = BASE_HEX;
break;
}
return hfinfo_number_value_format_display64(hfinfo, display, buf, value);
}
static const char *
hfinfo_number_vals_format(const header_field_info *hfinfo, char buf[32], guint32 value)
{
int display = hfinfo->display & FIELD_DISPLAY_E_MASK;
if (display == BASE_NONE)
return NULL;
if (display == BASE_DEC_HEX)
display = BASE_DEC;
if (display == BASE_HEX_DEC)
display = BASE_HEX;
return hfinfo_number_value_format_display(hfinfo, display, buf, value);
}
static const char *
hfinfo_number_vals_format64(const header_field_info *hfinfo, char buf[64], guint64 value)
{
int display = hfinfo->display & FIELD_DISPLAY_E_MASK;
if (display == BASE_NONE)
return NULL;
if (display == BASE_DEC_HEX)
display = BASE_DEC;
if (display == BASE_HEX_DEC)
display = BASE_HEX;
return hfinfo_number_value_format_display64(hfinfo, display, buf, value);
}
const char *
proto_registrar_get_name(const int n)
{
header_field_info *hfinfo;
PROTO_REGISTRAR_GET_NTH(n, hfinfo);
return hfinfo->name;
}
const char *
proto_registrar_get_abbrev(const int n)
{
header_field_info *hfinfo;
PROTO_REGISTRAR_GET_NTH(n, hfinfo);
return hfinfo->abbrev;
}
enum ftenum
proto_registrar_get_ftype(const int n)
{
header_field_info *hfinfo;
PROTO_REGISTRAR_GET_NTH(n, hfinfo);
return hfinfo->type;
}
int
proto_registrar_get_parent(const int n)
{
header_field_info *hfinfo;
PROTO_REGISTRAR_GET_NTH(n, hfinfo);
return hfinfo->parent;
}
gboolean
proto_registrar_is_protocol(const int n)
{
header_field_info *hfinfo;
PROTO_REGISTRAR_GET_NTH(n, hfinfo);
return (((hfinfo->id != hf_text_only) && (hfinfo->parent == -1)) ? TRUE : FALSE);
}
gint
proto_registrar_get_length(const int n)
{
header_field_info *hfinfo;
PROTO_REGISTRAR_GET_NTH(n, hfinfo);
return ftype_length(hfinfo->type);
}
gboolean
proto_check_for_protocol_or_field(const proto_tree* tree, const int id)
{
GPtrArray *ptrs = proto_get_finfo_ptr_array(tree, id);
if (g_ptr_array_len(ptrs) > 0) {
return TRUE;
}
else {
return FALSE;
}
}
GPtrArray *
proto_get_finfo_ptr_array(const proto_tree *tree, const int id)
{
if (!tree)
return NULL;
if (PTREE_DATA(tree)->interesting_hfids != NULL)
return (GPtrArray *)g_hash_table_lookup(PTREE_DATA(tree)->interesting_hfids,
GINT_TO_POINTER(id));
else
return NULL;
}
gboolean
proto_tracking_interesting_fields(const proto_tree *tree)
{
GHashTable *interesting_hfids;
if (!tree)
return FALSE;
interesting_hfids = PTREE_DATA(tree)->interesting_hfids;
return (interesting_hfids != NULL) && g_hash_table_size(interesting_hfids);
}
static gboolean
find_finfo(proto_node *node, gpointer data)
{
field_info *fi = PNODE_FINFO(node);
if (fi && fi->hfinfo) {
if (fi->hfinfo->id == ((ffdata_t*)data)->id) {
g_ptr_array_add(((ffdata_t*)data)->array, fi);
}
}
return FALSE;
}
GPtrArray *
proto_find_finfo(proto_tree *tree, const int id)
{
ffdata_t ffdata;
ffdata.array = g_ptr_array_new();
ffdata.id = id;
proto_tree_traverse_pre_order(tree, find_finfo, &ffdata);
return ffdata.array;
}
static gboolean
every_finfo(proto_node *node, gpointer data)
{
field_info *fi = PNODE_FINFO(node);
if (fi && fi->hfinfo) {
g_ptr_array_add(((ffdata_t*)data)->array, fi);
}
return FALSE;
}
GPtrArray *
proto_all_finfos(proto_tree *tree)
{
ffdata_t ffdata;
ffdata.array = g_ptr_array_new();
ffdata.id = 0;
proto_tree_traverse_pre_order(tree, every_finfo, &ffdata);
return ffdata.array;
}
static gboolean
check_for_offset(proto_node *node, gpointer data)
{
field_info *fi = PNODE_FINFO(node);
offset_search_t *offsearch = (offset_search_t *)data;
if (fi && !PROTO_ITEM_IS_HIDDEN(node) && !PROTO_ITEM_IS_GENERATED(node) && fi->ds_tvb && offsearch->tvb == fi->ds_tvb) {
if (offsearch->offset >= (guint) fi->start &&
offsearch->offset < (guint) (fi->start + fi->length)) {
offsearch->finfo = fi;
return FALSE;
}
}
return FALSE;
}
field_info *
proto_find_field_from_offset(proto_tree *tree, guint offset, tvbuff_t *tvb)
{
offset_search_t offsearch;
offsearch.offset = offset;
offsearch.finfo = NULL;
offsearch.tvb = tvb;
proto_tree_traverse_pre_order(tree, check_for_offset, &offsearch);
return offsearch.finfo;
}
static gboolean
check_for_undecoded(proto_node *node, gpointer data)
{
field_info *fi = PNODE_FINFO(node);
gchar* decoded = (gchar*)data;
gint i;
guint byte;
guint bit;
if (fi && fi->hfinfo->type != FT_PROTOCOL) {
for (i = fi->start; i < fi->start + fi->length; i++) {
byte = i / 8;
bit = i % 8;
decoded[byte] |= (1 << bit);
}
}
return FALSE;
}
gchar*
proto_find_undecoded_data(proto_tree *tree, guint length)
{
gchar* decoded = (gchar*)wmem_alloc0(wmem_packet_scope(), length / 8 + 1);
proto_tree_traverse_pre_order(tree, check_for_undecoded, decoded);
return decoded;
}
void
proto_registrar_dump_protocols(void)
{
protocol_t *protocol;
int i;
void *cookie = NULL;
i = proto_get_first_protocol(&cookie);
while (i != -1) {
protocol = find_protocol_by_id(i);
printf("%s\t%s\t%s\n", protocol->name, protocol->short_name,
protocol->filter_name);
i = proto_get_next_protocol(&cookie);
}
}
void
proto_registrar_dump_values(void)
{
header_field_info *hfinfo;
int i, len, vi;
const value_string *vals;
const val64_string *vals64;
const range_string *range;
const true_false_string *tfs;
len = gpa_hfinfo.len;
for (i = 0; i < len ; i++) {
if (gpa_hfinfo.hfi[i] == NULL)
continue;
PROTO_REGISTRAR_GET_NTH(i, hfinfo);
if (hfinfo->id == hf_text_only) {
continue;
}
if (proto_registrar_is_protocol(i)) {
continue;
}
#if 0
if (hfinfo->same_name_prev_id != -1)
continue;
#endif
vals = NULL;
vals64 = NULL;
range = NULL;
tfs = NULL;
if (hfinfo->strings != NULL) {
if ((hfinfo->display & FIELD_DISPLAY_E_MASK) != BASE_CUSTOM &&
(hfinfo->type == FT_UINT8 ||
hfinfo->type == FT_UINT16 ||
hfinfo->type == FT_UINT24 ||
hfinfo->type == FT_UINT32 ||
hfinfo->type == FT_UINT40 ||
hfinfo->type == FT_UINT48 ||
hfinfo->type == FT_UINT56 ||
hfinfo->type == FT_UINT64 ||
hfinfo->type == FT_INT8 ||
hfinfo->type == FT_INT16 ||
hfinfo->type == FT_INT24 ||
hfinfo->type == FT_INT32 ||
hfinfo->type == FT_INT40 ||
hfinfo->type == FT_INT48 ||
hfinfo->type == FT_INT56 ||
hfinfo->type == FT_INT64)) {
if (hfinfo->display & BASE_RANGE_STRING) {
range = (const range_string *)hfinfo->strings;
} else if (hfinfo->display & BASE_EXT_STRING) {
vals = VALUE_STRING_EXT_VS_P((value_string_ext *)hfinfo->strings);
} else if (hfinfo->display & BASE_VAL64_STRING) {
vals64 = (const val64_string *)hfinfo->strings;
} else {
vals = (const value_string *)hfinfo->strings;
}
}
else if (hfinfo->type == FT_BOOLEAN) {
tfs = (const struct true_false_string *)hfinfo->strings;
}
}
if (vals) {
if (hfinfo->display & BASE_EXT_STRING) {
value_string_ext *vse_p = (value_string_ext *)hfinfo->strings;
if (!value_string_ext_validate(vse_p)) {
g_warning("Invalid value_string_ext ptr for: %s", hfinfo->abbrev);
continue;
}
try_val_to_str_ext(0, vse_p);
printf("E\t%s\t%u\t%s\t%s\n",
hfinfo->abbrev,
VALUE_STRING_EXT_VS_NUM_ENTRIES(vse_p),
VALUE_STRING_EXT_VS_NAME(vse_p),
value_string_ext_match_type_str(vse_p));
}
vi = 0;
while (vals[vi].strptr) {
if (hfinfo->display == BASE_HEX) {
printf("V\t%s\t0x%x\t%s\n",
hfinfo->abbrev,
vals[vi].value,
vals[vi].strptr);
}
else {
printf("V\t%s\t%u\t%s\n",
hfinfo->abbrev,
vals[vi].value,
vals[vi].strptr);
}
vi++;
}
}
else if (vals64) {
vi = 0;
while (vals64[vi].strptr) {
printf("V64\t%s\t%" G_GINT64_MODIFIER "u\t%s\n",
hfinfo->abbrev,
vals64[vi].value,
vals64[vi].strptr);
vi++;
}
}
else if (range) {
vi = 0;
while (range[vi].strptr) {
if ((hfinfo->display & FIELD_DISPLAY_E_MASK) == BASE_HEX) {
printf("R\t%s\t0x%x\t0x%x\t%s\n",
hfinfo->abbrev,
range[vi].value_min,
range[vi].value_max,
range[vi].strptr);
}
else {
printf("R\t%s\t%u\t%u\t%s\n",
hfinfo->abbrev,
range[vi].value_min,
range[vi].value_max,
range[vi].strptr);
}
vi++;
}
}
else if (tfs) {
printf("T\t%s\t%s\t%s\n", hfinfo->abbrev,
tfs->true_string, tfs->false_string);
}
}
}
gboolean
proto_registrar_dump_fieldcount(void)
{
guint32 i;
header_field_info *hfinfo;
guint32 deregistered_count = 0;
guint32 same_name_count = 0;
guint32 protocol_count = 0;
for (i = 0; i < gpa_hfinfo.len; i++) {
if (gpa_hfinfo.hfi[i] == NULL) {
deregistered_count++;
continue;
}
PROTO_REGISTRAR_GET_NTH(i, hfinfo);
if (proto_registrar_is_protocol(i))
protocol_count++;
if (hfinfo->same_name_prev_id != -1)
same_name_count++;
}
printf ("There are %u header fields registered, of which:\n"
"\t%u are deregistered\n"
"\t%u are protocols\n"
"\t%u have the same name as another field\n\n",
gpa_hfinfo.len, deregistered_count, protocol_count,
same_name_count);
printf ("%d fields were pre-allocated.\n%s", PROTO_PRE_ALLOC_HF_FIELDS_MEM,
(gpa_hfinfo.allocated_len > PROTO_PRE_ALLOC_HF_FIELDS_MEM) ?
"* * Please increase PROTO_PRE_ALLOC_HF_FIELDS_MEM (in epan/proto.c)! * *\n\n" :
"\n");
printf ("The header field table consumes %u KiB of memory.\n",
(unsigned int)(gpa_hfinfo.allocated_len * sizeof(header_field_info *) / 1024));
printf ("The fields themselves consume %u KiB of memory.\n",
(unsigned int)(gpa_hfinfo.len * sizeof(header_field_info) / 1024));
return (gpa_hfinfo.allocated_len > PROTO_PRE_ALLOC_HF_FIELDS_MEM);
}
void
proto_registrar_dump_fields(void)
{
header_field_info *hfinfo, *parent_hfinfo;
int i, len;
const char *enum_name;
const char *base_name;
const char *blurb;
char width[5];
len = gpa_hfinfo.len;
for (i = 0; i < len ; i++) {
if (gpa_hfinfo.hfi[i] == NULL)
continue;
PROTO_REGISTRAR_GET_NTH(i, hfinfo);
if (hfinfo->id == hf_text_only)
continue;
if (proto_registrar_is_protocol(i)) {
printf("P\t%s\t%s\n", hfinfo->name, hfinfo->abbrev);
}
else {
if (hfinfo->same_name_prev_id != -1)
continue;
PROTO_REGISTRAR_GET_NTH(hfinfo->parent, parent_hfinfo);
enum_name = ftype_name(hfinfo->type);
base_name = "";
if (hfinfo->type == FT_UINT8 ||
hfinfo->type == FT_UINT16 ||
hfinfo->type == FT_UINT24 ||
hfinfo->type == FT_UINT32 ||
hfinfo->type == FT_UINT40 ||
hfinfo->type == FT_UINT48 ||
hfinfo->type == FT_UINT56 ||
hfinfo->type == FT_UINT64 ||
hfinfo->type == FT_INT8 ||
hfinfo->type == FT_INT16 ||
hfinfo->type == FT_INT24 ||
hfinfo->type == FT_INT32 ||
hfinfo->type == FT_INT40 ||
hfinfo->type == FT_INT48 ||
hfinfo->type == FT_INT56 ||
hfinfo->type == FT_INT64) {
switch (FIELD_DISPLAY(hfinfo->display)) {
case BASE_NONE:
case BASE_DEC:
case BASE_HEX:
case BASE_OCT:
case BASE_DEC_HEX:
case BASE_HEX_DEC:
case BASE_CUSTOM:
case BASE_PT_UDP:
case BASE_PT_TCP:
case BASE_PT_DCCP:
case BASE_PT_SCTP:
base_name = val_to_str_const(FIELD_DISPLAY(hfinfo->display), hf_display, "????");
break;
default:
base_name = "????";
break;
}
} else if (hfinfo->type == FT_BOOLEAN) {
g_snprintf(width, sizeof(width), "%d", hfinfo->display);
base_name = width;
}
blurb = hfinfo->blurb;
if (blurb == NULL)
blurb = "";
else if (strlen(blurb) == 0)
blurb = "\"\"";
printf("F\t%s\t%s\t%s\t%s\t%s\t0x%" G_GINT64_MODIFIER "x\t%s\n",
hfinfo->name, hfinfo->abbrev, enum_name,
parent_hfinfo->abbrev, base_name,
hfinfo->bitmask, blurb);
}
}
}
void
proto_registrar_dump_ftypes(void)
{
int fte;
for (fte = 0; fte < FT_NUM_TYPES; fte++) {
printf("%s\t%s\n", ftype_name((ftenum_t)fte), ftype_pretty_name((ftenum_t)fte));
}
}
static gboolean
construct_match_selected_string(field_info *finfo, epan_dissect_t *edt,
char **filter)
{
header_field_info *hfinfo;
int abbrev_len;
char *ptr;
int buf_len;
int dfilter_len, i;
gint start, length, length_remaining;
guint8 c;
gchar is_signed_num = FALSE;
if (!finfo)
return FALSE;
hfinfo = finfo->hfinfo;
DISSECTOR_ASSERT(hfinfo);
abbrev_len = (int) strlen(hfinfo->abbrev);
if (hfinfo->strings && (hfinfo->display & FIELD_DISPLAY_E_MASK) == BASE_NONE) {
const gchar *str = NULL;
switch (hfinfo->type) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
str = hf_try_val_to_str(fvalue_get_sinteger(&finfo->value), hfinfo);
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
str = hf_try_val_to_str(fvalue_get_uinteger(&finfo->value), hfinfo);
break;
default:
break;
}
if (str != NULL && filter != NULL) {
*filter = wmem_strdup_printf(NULL, "%s == \"%s\"", hfinfo->abbrev, str);
return TRUE;
}
}
switch (hfinfo->type) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
is_signed_num = TRUE;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_FRAMENUM:
if (filter != NULL) {
guint32 number;
char buf[32];
const char *out;
if (is_signed_num)
number = fvalue_get_sinteger(&finfo->value);
else
number = fvalue_get_uinteger(&finfo->value);
out = hfinfo_numeric_value_format(hfinfo, buf, number);
*filter = wmem_strdup_printf(NULL, "%s == %s", hfinfo->abbrev, out);
}
break;
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_INT64:
is_signed_num = TRUE;
case FT_UINT40:
case FT_UINT48:
case FT_UINT56:
case FT_UINT64:
if (filter != NULL) {
guint64 number;
char buf [48];
const char *out;
if (is_signed_num)
number = fvalue_get_sinteger64(&finfo->value);
else
number = fvalue_get_uinteger64(&finfo->value);
out = hfinfo_numeric_value_format64(hfinfo, buf, number);
*filter = wmem_strdup_printf(NULL, "%s == %s", hfinfo->abbrev, out);
}
break;
case FT_PROTOCOL:
if (filter != NULL)
*filter = wmem_strdup(NULL, finfo->hfinfo->abbrev);
break;
case FT_NONE:
length = finfo->length;
if (length == 0) {
if (filter != NULL)
*filter = wmem_strdup(NULL, finfo->hfinfo->abbrev);
break;
}
if (length < 0)
return FALSE;
if (edt == NULL)
return FALSE;
if (finfo->ds_tvb != edt->tvb)
return FALSE;
length_remaining = tvb_captured_length_remaining(finfo->ds_tvb, finfo->start);
if (length > length_remaining)
length = length_remaining;
if (length <= 0)
return FALSE;
if (filter != NULL) {
start = finfo->start;
buf_len = 32 + length * 3;
*filter = (char *)wmem_alloc0(NULL, buf_len);
ptr = *filter;
ptr += g_snprintf(ptr, (gulong) (buf_len-(ptr-*filter)),
"frame[%d:%d] == ", finfo->start, length);
for (i=0; i<length; i++) {
c = tvb_get_guint8(finfo->ds_tvb, start);
start++;
if (i == 0 ) {
ptr += g_snprintf(ptr, (gulong) (buf_len-(ptr-*filter)), "%02x", c);
}
else {
ptr += g_snprintf(ptr, (gulong) (buf_len-(ptr-*filter)), ":%02x", c);
}
}
}
break;
case FT_PCRE:
DISSECTOR_ASSERT_NOT_REACHED();
break;
default:
if (filter != NULL) {
char* str;
dfilter_len = fvalue_string_repr_len(&finfo->value,
FTREPR_DFILTER, finfo->hfinfo->display);
dfilter_len += abbrev_len + 4 + 1;
*filter = (char *)wmem_alloc0(NULL, dfilter_len);
str = fvalue_to_string_repr(NULL, &finfo->value, FTREPR_DFILTER, finfo->hfinfo->display);
g_snprintf(*filter, dfilter_len, "%s == %s", hfinfo->abbrev, str);
wmem_free(NULL, str);
}
break;
}
return TRUE;
}
gboolean
proto_can_match_selected(field_info *finfo, epan_dissect_t *edt)
{
return construct_match_selected_string(finfo, edt, NULL);
}
char *
proto_construct_match_selected_string(field_info *finfo, epan_dissect_t *edt)
{
char *filter = NULL;
if (!construct_match_selected_string(finfo, edt, &filter))
{
wmem_free(NULL, filter);
return NULL;
}
return filter;
}
static gboolean
proto_item_add_bitmask_tree(proto_item *item, tvbuff_t *tvb, const int offset,
const int len, const gint ett, const int **fields,
const int flags, gboolean first,
gboolean use_parent_tree,
proto_tree* tree, guint64 value)
{
guint bitshift;
guint64 available_bits = 0;
guint64 tmpval;
header_field_info *hf;
if (len < 0 || len > 8)
g_assert_not_reached();
bitshift = (8 - (guint)len)*8;
available_bits = G_GUINT64_CONSTANT(0xFFFFFFFFFFFFFFFF) >> bitshift;
if (use_parent_tree == FALSE)
tree = proto_item_add_subtree(item, ett);
while (*fields) {
guint64 present_bits;
PROTO_REGISTRAR_GET_NTH(**fields,hf);
DISSECTOR_ASSERT_HINT(hf->bitmask != 0, hf->abbrev);
present_bits = available_bits & hf->bitmask;
if (present_bits != hf->bitmask) {
fields++;
continue;
}
switch (hf->type) {
case FT_INT8:
case FT_UINT8:
case FT_INT16:
case FT_UINT16:
case FT_INT24:
case FT_UINT24:
case FT_INT32:
case FT_UINT32:
proto_tree_add_uint(tree, **fields, tvb, offset, len, (guint32)value);
break;
case FT_INT40:
case FT_UINT40:
case FT_INT48:
case FT_UINT48:
case FT_INT56:
case FT_UINT56:
case FT_INT64:
case FT_UINT64:
proto_tree_add_uint64(tree, **fields, tvb, offset, len, value);
break;
case FT_BOOLEAN:
proto_tree_add_boolean64(tree, **fields, tvb, offset, len, value);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
if (flags & BMT_NO_APPEND) {
fields++;
continue;
}
tmpval = (value & hf->bitmask) >> hfinfo_bitshift(hf);
switch (hf->type) {
case FT_INT8:
case FT_UINT8:
case FT_INT16:
case FT_UINT16:
case FT_INT24:
case FT_UINT24:
case FT_INT32:
case FT_UINT32:
case FT_INT40:
case FT_UINT40:
case FT_INT48:
case FT_UINT48:
case FT_INT56:
case FT_UINT56:
case FT_INT64:
case FT_UINT64:
if (hf->display == BASE_CUSTOM) {
gchar lbl[ITEM_LABEL_LENGTH];
const custom_fmt_func_t fmtfunc = (const custom_fmt_func_t)hf->strings;
DISSECTOR_ASSERT(fmtfunc);
fmtfunc(lbl, (guint32) tmpval);
proto_item_append_text(item, "%s%s: %s", first ? "" : ", ",
hf->name, lbl);
first = FALSE;
}
else if (hf->strings) {
proto_item_append_text(item, "%s%s: %s", first ? "" : ", ",
hf->name, hf_try_val_to_str_const((guint32) tmpval, hf, "Unknown"));
first = FALSE;
}
else if (!(flags & BMT_NO_INT)) {
char buf[32];
const char *out;
if (!first) {
proto_item_append_text(item, ", ");
}
out = hfinfo_number_value_format(hf, buf, (guint32) tmpval);
proto_item_append_text(item, "%s: %s", hf->name, out);
first = FALSE;
}
break;
case FT_BOOLEAN:
if (hf->strings && !(flags & BMT_NO_TFS)) {
const struct true_false_string *tfs =
(const struct true_false_string *)hf->strings;
if (tmpval) {
proto_item_append_text(item, "%s%s: %s", first ? "" : ", ",
hf->name, tfs->true_string);
first = FALSE;
} else if (!(flags & BMT_NO_FALSE)) {
proto_item_append_text(item, "%s%s: %s", first ? "" : ", ",
hf->name, tfs->false_string);
first = FALSE;
}
} else if (hf->bitmask & value) {
proto_item_append_text(item, "%s%s", first ? "" : ", ", hf->name);
first = FALSE;
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
fields++;
}
return first;
}
proto_item *
proto_tree_add_bitmask_ret_uint64(proto_tree *parent_tree, tvbuff_t *tvb,
const guint offset, const int hf_hdr,
const gint ett, const int **fields,
const guint encoding, guint64 *retval)
{
return proto_tree_add_bitmask_with_flags_ret_uint64(parent_tree, tvb, offset, hf_hdr, ett, fields, encoding, BMT_NO_INT|BMT_NO_TFS, retval);
}
proto_item *
proto_tree_add_bitmask(proto_tree *parent_tree, tvbuff_t *tvb,
const guint offset, const int hf_hdr,
const gint ett, const int **fields,
const guint encoding)
{
return proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_hdr, ett, fields, encoding, BMT_NO_INT|BMT_NO_TFS);
}
proto_item *
proto_tree_add_bitmask_with_flags_ret_uint64(proto_tree *parent_tree, tvbuff_t *tvb, const guint offset,
const int hf_hdr, const gint ett, const int **fields, const guint encoding, const int flags,
guint64 *retval)
{
proto_item *item = NULL;
header_field_info *hf;
int len;
guint64 value;
PROTO_REGISTRAR_GET_NTH(hf_hdr,hf);
DISSECTOR_ASSERT_FIELD_TYPE_IS_INTEGRAL(hf);
len = ftype_length(hf->type);
value = get_uint64_value(parent_tree, tvb, offset, len, encoding);
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_hdr, tvb, offset, len, encoding);
proto_item_add_bitmask_tree(item, tvb, offset, len, ett, fields,
flags, FALSE, FALSE, NULL, value);
}
*retval = value;
return item;
}
proto_item *
proto_tree_add_bitmask_with_flags(proto_tree *parent_tree, tvbuff_t *tvb, const guint offset,
const int hf_hdr, const gint ett, const int **fields, const guint encoding, const int flags)
{
proto_item *item = NULL;
header_field_info *hf;
int len;
guint64 value;
PROTO_REGISTRAR_GET_NTH(hf_hdr,hf);
DISSECTOR_ASSERT_FIELD_TYPE_IS_INTEGRAL(hf);
if (parent_tree) {
len = ftype_length(hf->type);
item = proto_tree_add_item(parent_tree, hf_hdr, tvb, offset, len, encoding);
value = get_uint64_value(parent_tree, tvb, offset, len, encoding);
proto_item_add_bitmask_tree(item, tvb, offset, len, ett, fields,
flags, FALSE, FALSE, NULL, value);
}
return item;
}
proto_item *
proto_tree_add_bitmask_value(proto_tree *parent_tree, tvbuff_t *tvb, const guint offset,
const int hf_hdr, const gint ett, const int **fields, const guint64 value)
{
return proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset,
hf_hdr, ett, fields, value, BMT_NO_INT|BMT_NO_TFS);
}
WS_DLL_PUBLIC proto_item *
proto_tree_add_bitmask_value_with_flags(proto_tree *parent_tree, tvbuff_t *tvb, const guint offset,
const int hf_hdr, const gint ett, const int **fields, const guint64 value, const int flags)
{
proto_item *item = NULL;
header_field_info *hf;
int len;
PROTO_REGISTRAR_GET_NTH(hf_hdr,hf);
DISSECTOR_ASSERT_FIELD_TYPE_IS_INTEGRAL(hf);
len = ftype_length(hf->type);
if (parent_tree) {
if (len <= 4)
item = proto_tree_add_uint(parent_tree, hf_hdr, tvb, offset, len, (guint32)value);
else
item = proto_tree_add_uint64(parent_tree, hf_hdr, tvb, offset, len, value);
proto_item_add_bitmask_tree(item, tvb, offset, len, ett, fields,
flags, FALSE, FALSE, NULL, value);
}
return item;
}
void
proto_tree_add_bitmask_list(proto_tree *tree, tvbuff_t *tvb, const guint offset,
const int len, const int **fields, const guint encoding)
{
guint64 value;
if (tree) {
value = get_uint64_value(tree, tvb, offset, len, encoding);
proto_item_add_bitmask_tree(NULL, tvb, offset, len, -1, fields,
BMT_NO_APPEND, FALSE, TRUE, tree, value);
}
}
WS_DLL_PUBLIC void
proto_tree_add_bitmask_list_value(proto_tree *tree, tvbuff_t *tvb, const guint offset,
const int len, const int **fields, const guint64 value)
{
if (tree) {
proto_item_add_bitmask_tree(NULL, tvb, offset, len, -1, fields,
BMT_NO_APPEND, FALSE, TRUE, tree, value);
}
}
proto_item *
proto_tree_add_bitmask_len(proto_tree *parent_tree, tvbuff_t *tvb,
const guint offset, const guint len, const int hf_hdr,
const gint ett, const int **fields, struct expert_field* exp,
const guint encoding)
{
proto_item *item = NULL;
header_field_info *hf;
guint decodable_len;
guint decodable_offset;
guint32 decodable_value;
guint64 value;
PROTO_REGISTRAR_GET_NTH(hf_hdr, hf);
DISSECTOR_ASSERT_FIELD_TYPE_IS_INTEGRAL(hf);
decodable_offset = offset;
decodable_len = MIN(len, (guint) ftype_length(hf->type));
if (encoding == ENC_BIG_ENDIAN) {
decodable_offset += (len - decodable_len);
}
if (parent_tree) {
decodable_value = get_uint_value(parent_tree, tvb, decodable_offset,
decodable_len, encoding);
item = proto_tree_add_uint(parent_tree, hf_hdr, tvb, offset, len,
decodable_value);
}
if (decodable_len < len) {
expert_add_info_format(NULL, item, exp,
"Only least-significant %d of %d bytes decoded",
decodable_len, len);
}
if (item) {
value = get_uint64_value(parent_tree, tvb, decodable_offset, decodable_len, encoding);
proto_item_add_bitmask_tree(item, tvb, decodable_offset, decodable_len,
ett, fields, BMT_NO_INT|BMT_NO_TFS, FALSE, FALSE, NULL, value);
}
return item;
}
proto_item *
proto_tree_add_bitmask_text(proto_tree *parent_tree, tvbuff_t *tvb,
const guint offset, const guint len,
const char *name, const char *fallback,
const gint ett, const int **fields,
const guint encoding, const int flags)
{
proto_item *item = NULL;
guint64 value;
if (parent_tree) {
item = proto_tree_add_text_internal(parent_tree, tvb, offset, len, "%s", name ? name : "");
value = get_uint64_value(parent_tree, tvb, offset, len, encoding);
if (proto_item_add_bitmask_tree(item, tvb, offset, len, ett, fields,
flags, TRUE, FALSE, NULL, value) && fallback) {
proto_item_append_text(item, "%s", fallback);
}
}
return item;
}
proto_item *
proto_tree_add_bits_item(proto_tree *tree, const int hfindex, tvbuff_t *tvb,
const guint bit_offset, const gint no_of_bits,
const guint encoding)
{
header_field_info *hfinfo;
gint octet_length;
gint octet_offset;
PROTO_REGISTRAR_GET_NTH(hfindex, hfinfo);
octet_length = (no_of_bits + 7) >> 3;
octet_offset = bit_offset >> 3;
test_length(hfinfo, tvb, octet_offset, octet_length);
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
return proto_tree_add_bits_ret_val(tree, hfindex, tvb, bit_offset, no_of_bits, NULL, encoding);
}
static proto_item *
_proto_tree_add_bits_ret_val(proto_tree *tree, const int hfindex, tvbuff_t *tvb,
const guint bit_offset, const gint no_of_bits,
guint64 *return_value, const guint encoding)
{
gint offset;
guint length;
guint8 tot_no_bits;
char *bf_str;
char lbl_str[ITEM_LABEL_LENGTH];
guint64 value = 0;
proto_item *pi;
header_field_info *hf_field;
const true_false_string *tfstring;
PROTO_REGISTRAR_GET_NTH(hfindex, hf_field);
if (hf_field->bitmask != 0) {
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"Incompatible use of proto_tree_add_bits_ret_val"
" with field '%s' (%s) with bitmask != 0",
hf_field->abbrev, hf_field->name));
}
DISSECTOR_ASSERT(no_of_bits > 0);
offset = bit_offset>>3;
tot_no_bits = ((bit_offset&0x7) + no_of_bits);
length = (tot_no_bits + 7) >> 3;
if (no_of_bits < 65) {
value = tvb_get_bits64(tvb, bit_offset, no_of_bits, encoding);
} else {
DISSECTOR_ASSERT_NOT_REACHED();
return NULL;
}
switch (hf_field->type) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_INT64:
value = ws_sign_ext64(value, no_of_bits);
break;
default:
break;
}
if (return_value) {
*return_value = value;
}
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hf_field);
bf_str = decode_bits_in_field(bit_offset, no_of_bits, value);
switch (hf_field->type) {
case FT_BOOLEAN:
tfstring = (const true_false_string *) &tfs_true_false;
if (hf_field->strings)
tfstring = (const true_false_string *)hf_field->strings;
return proto_tree_add_boolean_format(tree, hfindex, tvb, offset, length, (guint32)value,
"%s = %s: %s",
bf_str, hf_field->name,
(guint64)value ? tfstring->true_string : tfstring->false_string);
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
pi = proto_tree_add_uint(tree, hfindex, tvb, offset, length, (guint32)value);
fill_label_number(PITEM_FINFO(pi), lbl_str, FALSE);
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
pi = proto_tree_add_int(tree, hfindex, tvb, offset, length, (gint32)value);
fill_label_number(PITEM_FINFO(pi), lbl_str, TRUE);
break;
case FT_UINT40:
case FT_UINT48:
case FT_UINT56:
case FT_UINT64:
pi = proto_tree_add_uint64(tree, hfindex, tvb, offset, length, value);
fill_label_number64(PITEM_FINFO(pi), lbl_str, FALSE);
break;
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_INT64:
pi = proto_tree_add_int64(tree, hfindex, tvb, offset, length, (gint64)value);
fill_label_number64(PITEM_FINFO(pi), lbl_str, TRUE);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
return NULL;
break;
}
proto_item_set_text(pi, "%s = %s", bf_str, lbl_str);
return pi;
}
proto_item *
proto_tree_add_split_bits_item_ret_val(proto_tree *tree, const int hfindex, tvbuff_t *tvb,
const guint bit_offset, const crumb_spec_t *crumb_spec,
guint64 *return_value)
{
proto_item *pi;
gint no_of_bits;
gint octet_offset;
guint mask_initial_bit_offset;
guint mask_greatest_bit_offset;
guint octet_length;
guint8 i;
char bf_str[256];
char lbl_str[ITEM_LABEL_LENGTH];
guint64 value;
guint64 composite_bitmask;
guint64 composite_bitmap;
header_field_info *hf_field;
const true_false_string *tfstring;
PROTO_REGISTRAR_GET_NTH(hfindex, hf_field);
if (hf_field->bitmask != 0) {
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"Incompatible use of proto_tree_add_split_bits_item_ret_val"
" with field '%s' (%s) with bitmask != 0",
hf_field->abbrev, hf_field->name));
}
mask_initial_bit_offset = bit_offset % 8;
no_of_bits = 0;
value = 0;
i = 0;
mask_greatest_bit_offset = 0;
composite_bitmask = 0;
composite_bitmap = 0;
while (crumb_spec[i].crumb_bit_length != 0) {
guint64 crumb_mask, crumb_value;
guint8 crumb_end_bit_offset;
DISSECTOR_ASSERT(i < 64);
crumb_value = tvb_get_bits64(tvb,
bit_offset + crumb_spec[i].crumb_bit_offset,
crumb_spec[i].crumb_bit_length,
ENC_BIG_ENDIAN);
value += crumb_value;
no_of_bits += crumb_spec[i].crumb_bit_length;
if (mask_greatest_bit_offset < 32) {
crumb_end_bit_offset = mask_initial_bit_offset
+ crumb_spec[i].crumb_bit_offset
+ crumb_spec[i].crumb_bit_length;
crumb_mask = (G_GUINT64_CONSTANT(1) << crumb_spec[i].crumb_bit_length) - 1;
if (crumb_end_bit_offset > mask_greatest_bit_offset) {
mask_greatest_bit_offset = crumb_end_bit_offset;
}
composite_bitmask |= (crumb_mask << (64 - crumb_end_bit_offset));
composite_bitmap |= (crumb_value << (64 - crumb_end_bit_offset));
}
value <<= crumb_spec[++i].crumb_bit_length;
}
switch (hf_field->type) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_INT64:
value = ws_sign_ext64(value, no_of_bits);
break;
default:
break;
}
if (return_value) {
*return_value = value;
}
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hf_field);
bf_str[0] = '\0';
octet_offset = bit_offset >> 3;
octet_length = ((mask_greatest_bit_offset + 7) >> 3);
mask_greatest_bit_offset = octet_length << 3;
if (mask_greatest_bit_offset > 0 && mask_greatest_bit_offset <= 32) {
other_decode_bitfield_value(bf_str,
(guint32)(composite_bitmap >> (64 - mask_greatest_bit_offset)),
(guint32)(composite_bitmask >> (64 - mask_greatest_bit_offset)),
mask_greatest_bit_offset);
}
switch (hf_field->type) {
case FT_BOOLEAN:
tfstring = (const true_false_string *) &tfs_true_false;
if (hf_field->strings)
tfstring = (const true_false_string *) hf_field->strings;
return proto_tree_add_boolean_format(tree, hfindex,
tvb, octet_offset, octet_length, (guint32)value,
"%s = %s: %s",
bf_str, hf_field->name,
(guint64)value ? tfstring->true_string : tfstring->false_string);
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
pi = proto_tree_add_uint(tree, hfindex, tvb, octet_offset, octet_length, (guint32)value);
fill_label_number(PITEM_FINFO(pi), lbl_str, FALSE);
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
pi = proto_tree_add_int(tree, hfindex, tvb, octet_offset, octet_length, (gint32)value);
fill_label_number(PITEM_FINFO(pi), lbl_str, TRUE);
break;
case FT_UINT40:
case FT_UINT48:
case FT_UINT56:
case FT_UINT64:
pi = proto_tree_add_uint64(tree, hfindex, tvb, octet_offset, octet_length, value);
fill_label_number64(PITEM_FINFO(pi), lbl_str, FALSE);
break;
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_INT64:
pi = proto_tree_add_int64(tree, hfindex, tvb, octet_offset, octet_length, (gint64)value);
fill_label_number64(PITEM_FINFO(pi), lbl_str, TRUE);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
return NULL;
break;
}
proto_item_set_text(pi, "%s = %s", bf_str, lbl_str);
return pi;
}
void
proto_tree_add_split_bits_crumb(proto_tree *tree, const int hfindex, tvbuff_t *tvb, const guint bit_offset,
const crumb_spec_t *crumb_spec, guint16 crumb_index)
{
header_field_info *hfinfo;
PROTO_REGISTRAR_GET_NTH(hfindex, hfinfo);
proto_tree_add_text_internal(tree, tvb,
bit_offset >> 3,
((bit_offset + crumb_spec[crumb_index].crumb_bit_length - 1) >> 3) - (bit_offset >> 3) + 1,
"%s crumb %d of %s (decoded above)",
decode_bits_in_field(bit_offset, crumb_spec[crumb_index].crumb_bit_length,
tvb_get_bits(tvb,
bit_offset,
crumb_spec[crumb_index].crumb_bit_length,
ENC_BIG_ENDIAN)),
crumb_index,
hfinfo->name);
}
proto_item *
proto_tree_add_bits_ret_val(proto_tree *tree, const int hfindex, tvbuff_t *tvb,
const guint bit_offset, const gint no_of_bits,
guint64 *return_value, const guint encoding)
{
proto_item *item;
if ((item = _proto_tree_add_bits_ret_val(tree, hfindex, tvb,
bit_offset, no_of_bits,
return_value, encoding))) {
FI_SET_FLAG(PNODE_FINFO(item), FI_BITS_OFFSET(bit_offset));
FI_SET_FLAG(PNODE_FINFO(item), FI_BITS_SIZE(no_of_bits));
}
return item;
}
static proto_item *
_proto_tree_add_bits_format_value(proto_tree *tree, const int hfindex,
tvbuff_t *tvb, const guint bit_offset,
const gint no_of_bits, void *value_ptr,
gchar *value_str)
{
gint offset;
guint length;
guint8 tot_no_bits;
char *str;
guint64 value = 0;
header_field_info *hf_field;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hf_field);
if (hf_field->bitmask != 0) {
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"Incompatible use of proto_tree_add_bits_format_value"
" with field '%s' (%s) with bitmask != 0",
hf_field->abbrev, hf_field->name));
}
DISSECTOR_ASSERT(no_of_bits > 0);
offset = bit_offset>>3;
tot_no_bits = ((bit_offset&0x7) + no_of_bits);
length = tot_no_bits>>3;
if (tot_no_bits & 0x07)
length++;
if (no_of_bits < 65) {
value = tvb_get_bits64(tvb, bit_offset, no_of_bits, ENC_BIG_ENDIAN);
} else {
DISSECTOR_ASSERT_NOT_REACHED();
return NULL;
}
str = decode_bits_in_field(bit_offset, no_of_bits, value);
g_strlcat(str, " = ", 256+64);
g_strlcat(str, hf_field->name, 256+64);
switch (hf_field->type) {
case FT_BOOLEAN:
return proto_tree_add_boolean_format(tree, hfindex, tvb, offset, length, *(guint32 *)value_ptr,
"%s: %s", str, value_str);
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
return proto_tree_add_uint_format(tree, hfindex, tvb, offset, length, *(guint32 *)value_ptr,
"%s: %s", str, value_str);
break;
case FT_UINT40:
case FT_UINT48:
case FT_UINT56:
case FT_UINT64:
return proto_tree_add_uint64_format(tree, hfindex, tvb, offset, length, *(guint64 *)value_ptr,
"%s: %s", str, value_str);
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
return proto_tree_add_int_format(tree, hfindex, tvb, offset, length, *(gint32 *)value_ptr,
"%s: %s", str, value_str);
break;
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_INT64:
return proto_tree_add_int64_format(tree, hfindex, tvb, offset, length, *(gint64 *)value_ptr,
"%s: %s", str, value_str);
break;
case FT_FLOAT:
return proto_tree_add_float_format(tree, hfindex, tvb, offset, length, *(float *)value_ptr,
"%s: %s", str, value_str);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
return NULL;
break;
}
}
static proto_item *
proto_tree_add_bits_format_value(proto_tree *tree, const int hfindex,
tvbuff_t *tvb, const guint bit_offset,
const gint no_of_bits, void *value_ptr,
gchar *value_str)
{
proto_item *item;
if ((item = _proto_tree_add_bits_format_value(tree, hfindex,
tvb, bit_offset, no_of_bits,
value_ptr, value_str))) {
FI_SET_FLAG(PNODE_FINFO(item), FI_BITS_OFFSET(bit_offset));
FI_SET_FLAG(PNODE_FINFO(item), FI_BITS_SIZE(no_of_bits));
}
return item;
}
proto_item *
proto_tree_add_uint_bits_format_value(proto_tree *tree, const int hfindex,
tvbuff_t *tvb, const guint bit_offset,
const gint no_of_bits, guint32 value,
const char *format, ...)
{
va_list ap;
gchar *dst;
header_field_info *hf_field;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hf_field);
switch (hf_field->type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
return NULL;
break;
}
CREATE_VALUE_STRING(dst, format, ap);
return proto_tree_add_bits_format_value(tree, hfindex, tvb, bit_offset, no_of_bits, &value, dst);
}
proto_item *
proto_tree_add_uint64_bits_format_value(proto_tree *tree, const int hfindex,
tvbuff_t *tvb, const guint bit_offset,
const gint no_of_bits, guint64 value,
const char *format, ...)
{
va_list ap;
gchar *dst;
header_field_info *hf_field;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hf_field);
switch (hf_field->type) {
case FT_UINT40:
case FT_UINT48:
case FT_UINT56:
case FT_UINT64:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
return NULL;
break;
}
CREATE_VALUE_STRING(dst, format, ap);
return proto_tree_add_bits_format_value(tree, hfindex, tvb, bit_offset, no_of_bits, &value, dst);
}
proto_item *
proto_tree_add_float_bits_format_value(proto_tree *tree, const int hfindex,
tvbuff_t *tvb, const guint bit_offset,
const gint no_of_bits, float value,
const char *format, ...)
{
va_list ap;
gchar *dst;
header_field_info *hf_field;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hf_field);
DISSECTOR_ASSERT_FIELD_TYPE(hf_field, FT_FLOAT);
CREATE_VALUE_STRING(dst, format, ap);
return proto_tree_add_bits_format_value(tree, hfindex, tvb, bit_offset, no_of_bits, &value, dst);
}
proto_item *
proto_tree_add_int_bits_format_value(proto_tree *tree, const int hfindex,
tvbuff_t *tvb, const guint bit_offset,
const gint no_of_bits, gint32 value,
const char *format, ...)
{
va_list ap;
gchar *dst;
header_field_info *hf_field;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hf_field);
switch (hf_field->type) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
return NULL;
break;
}
CREATE_VALUE_STRING(dst, format, ap);
return proto_tree_add_bits_format_value(tree, hfindex, tvb, bit_offset, no_of_bits, &value, dst);
}
proto_item *
proto_tree_add_int64_bits_format_value(proto_tree *tree, const int hfindex,
tvbuff_t *tvb, const guint bit_offset,
const gint no_of_bits, gint64 value,
const char *format, ...)
{
va_list ap;
gchar *dst;
header_field_info *hf_field;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hf_field);
switch (hf_field->type) {
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_INT64:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
return NULL;
break;
}
CREATE_VALUE_STRING(dst, format, ap);
return proto_tree_add_bits_format_value(tree, hfindex, tvb, bit_offset, no_of_bits, &value, dst);
}
proto_item *
proto_tree_add_boolean_bits_format_value(proto_tree *tree, const int hfindex,
tvbuff_t *tvb, const guint bit_offset,
const gint no_of_bits, guint32 value,
const char *format, ...)
{
va_list ap;
gchar *dst;
header_field_info *hf_field;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hf_field);
DISSECTOR_ASSERT_FIELD_TYPE(hf_field, FT_BOOLEAN);
CREATE_VALUE_STRING(dst, format, ap);
return proto_tree_add_bits_format_value(tree, hfindex, tvb, bit_offset, no_of_bits, &value, dst);
}
proto_item *
proto_tree_add_boolean_bits_format_value64(proto_tree *tree, const int hfindex,
tvbuff_t *tvb, const guint bit_offset,
const gint no_of_bits, guint64 value,
const char *format, ...)
{
va_list ap;
gchar *dst;
header_field_info *hf_field;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hf_field);
DISSECTOR_ASSERT(hf_field->type == FT_BOOLEAN);
CREATE_VALUE_STRING(dst, format, ap);
return proto_tree_add_bits_format_value(tree, hfindex, tvb, bit_offset, no_of_bits, &value, dst);
}
proto_item *
proto_tree_add_ts_23_038_7bits_item(proto_tree *tree, const int hfindex, tvbuff_t *tvb,
const guint bit_offset, const gint no_of_chars)
{
proto_item *pi;
header_field_info *hfinfo;
gint byte_length;
gint byte_offset;
gchar *string;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_STRING);
byte_length = (((no_of_chars + 1) * 7) + (bit_offset & 0x07)) >> 3;
byte_offset = bit_offset >> 3;
string = tvb_get_ts_23_038_7bits_string(wmem_packet_scope(), tvb, bit_offset, no_of_chars);
if (hfinfo->display == STR_UNICODE) {
DISSECTOR_ASSERT(g_utf8_validate(string, -1, NULL));
}
pi = proto_tree_add_pi(tree, hfinfo, tvb, byte_offset, &byte_length);
DISSECTOR_ASSERT(byte_length >= 0);
proto_tree_set_string(PNODE_FINFO(pi), string);
return pi;
}
proto_item *
proto_tree_add_ascii_7bits_item(proto_tree *tree, const int hfindex, tvbuff_t *tvb,
const guint bit_offset, const gint no_of_chars)
{
proto_item *pi;
header_field_info *hfinfo;
gint byte_length;
gint byte_offset;
gchar *string;
CHECK_FOR_NULL_TREE(tree);
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT_FIELD_TYPE(hfinfo, FT_STRING);
byte_length = (((no_of_chars + 1) * 7) + (bit_offset & 0x07)) >> 3;
byte_offset = bit_offset >> 3;
string = tvb_get_ascii_7bits_string(wmem_packet_scope(), tvb, bit_offset, no_of_chars);
if (hfinfo->display == STR_UNICODE) {
DISSECTOR_ASSERT(g_utf8_validate(string, -1, NULL));
}
pi = proto_tree_add_pi(tree, hfinfo, tvb, byte_offset, &byte_length);
DISSECTOR_ASSERT(byte_length >= 0);
proto_tree_set_string(PNODE_FINFO(pi), string);
return pi;
}
proto_item *
proto_tree_add_checksum(proto_tree *tree, tvbuff_t *tvb, const guint offset,
const int hf_checksum, const int hf_checksum_status, struct expert_field* bad_checksum_expert,
packet_info *pinfo, guint32 computed_checksum, const guint encoding, const guint flags)
{
header_field_info *hfinfo = proto_registrar_get_nth(hf_checksum);
guint32 checksum;
guint32 len;
proto_item* ti = NULL;
proto_item* ti2;
gboolean incorrect_checksum = TRUE;
DISSECTOR_ASSERT_HINT(hfinfo != NULL, "Not passed hfi!");
if (flags & PROTO_CHECKSUM_NOT_PRESENT) {
ti = proto_tree_add_uint_format_value(tree, hf_checksum, tvb, offset, 0, 0, "[missing]");
PROTO_ITEM_SET_GENERATED(ti);
if (hf_checksum_status != -1) {
ti2 = proto_tree_add_uint(tree, hf_checksum_status, tvb, offset, 0, PROTO_CHECKSUM_E_NOT_PRESENT);
PROTO_ITEM_SET_GENERATED(ti2);
}
return ti;
}
switch (hfinfo->type){
case FT_UINT8:
len = 1;
break;
case FT_UINT16:
len = 2;
break;
case FT_UINT24:
len = 3;
break;
case FT_UINT32:
len = 4;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
if (flags & PROTO_CHECKSUM_GENERATED) {
ti = proto_tree_add_uint(tree, hf_checksum, tvb, offset, 0, computed_checksum);
PROTO_ITEM_SET_GENERATED(ti);
} else {
ti = proto_tree_add_item_ret_uint(tree, hf_checksum, tvb, offset, len, encoding, &checksum);
if (flags & PROTO_CHECKSUM_VERIFY) {
if (flags & (PROTO_CHECKSUM_IN_CKSUM|PROTO_CHECKSUM_ZERO)) {
if (computed_checksum == 0) {
proto_item_append_text(ti, " [correct]");
if (hf_checksum_status != -1) {
ti2 = proto_tree_add_uint(tree, hf_checksum_status, tvb, offset, 0, PROTO_CHECKSUM_E_GOOD);
PROTO_ITEM_SET_GENERATED(ti2);
}
incorrect_checksum = FALSE;
} else if (flags & PROTO_CHECKSUM_IN_CKSUM) {
computed_checksum = in_cksum_shouldbe(checksum, computed_checksum);
}
} else {
if (checksum == computed_checksum) {
proto_item_append_text(ti, " [correct]");
if (hf_checksum_status != -1) {
ti2 = proto_tree_add_uint(tree, hf_checksum_status, tvb, offset, 0, PROTO_CHECKSUM_E_GOOD);
PROTO_ITEM_SET_GENERATED(ti2);
}
incorrect_checksum = FALSE;
}
}
if (incorrect_checksum) {
if (hf_checksum_status != -1) {
ti2 = proto_tree_add_uint(tree, hf_checksum_status, tvb, offset, 0, PROTO_CHECKSUM_E_BAD);
PROTO_ITEM_SET_GENERATED(ti2);
}
if (flags & PROTO_CHECKSUM_ZERO) {
proto_item_append_text(ti, " [incorrect]");
if (bad_checksum_expert != NULL)
expert_add_info_format(pinfo, ti, bad_checksum_expert, "Bad checksum");
} else {
switch(hfinfo->type)
{
case FT_UINT8:
proto_item_append_text(ti, " [incorrect, should be 0x%02x]", computed_checksum);
if (bad_checksum_expert != NULL)
expert_add_info_format(pinfo, ti, bad_checksum_expert, "Bad checksum [should be 0x%02x]", computed_checksum);
break;
case FT_UINT16:
proto_item_append_text(ti, " [incorrect, should be 0x%04x]", computed_checksum);
if (bad_checksum_expert != NULL)
expert_add_info_format(pinfo, ti, bad_checksum_expert, "Bad checksum [should be 0x%04x]", computed_checksum);
break;
case FT_UINT24:
proto_item_append_text(ti, " [incorrect, should be 0x%06x]", computed_checksum);
if (bad_checksum_expert != NULL)
expert_add_info_format(pinfo, ti, bad_checksum_expert, "Bad checksum [should be 0x%06x]", computed_checksum);
break;
case FT_UINT32:
proto_item_append_text(ti, " [incorrect, should be 0x%08x]", computed_checksum);
if (bad_checksum_expert != NULL)
expert_add_info_format(pinfo, ti, bad_checksum_expert, "Bad checksum [should be 0x%08x]", computed_checksum);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
}
}
} else {
if (hf_checksum_status != -1) {
proto_item_append_text(ti, " [unverified]");
ti2 = proto_tree_add_uint(tree, hf_checksum_status, tvb, offset, 0, PROTO_CHECKSUM_E_UNVERIFIED);
PROTO_ITEM_SET_GENERATED(ti2);
}
}
}
return ti;
}
guchar
proto_check_field_name(const gchar *field_name)
{
return wrs_check_charset(fld_abbrev_chars, field_name);
}
gboolean
tree_expanded(int tree_type)
{
g_assert(tree_type >= 0 && tree_type < num_tree_types);
return tree_is_expanded[tree_type >> 5] & (1U << (tree_type & 31));
}
void
tree_expanded_set(int tree_type, gboolean value)
{
g_assert(tree_type >= 0 && tree_type < num_tree_types);
if (value)
tree_is_expanded[tree_type >> 5] |= (1U << (tree_type & 31));
else
tree_is_expanded[tree_type >> 5] &= ~(1U << (tree_type & 31));
}
