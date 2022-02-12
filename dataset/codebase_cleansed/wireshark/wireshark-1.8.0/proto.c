static int
wrs_count_bitshift(const guint32 bitmask)
{
int bitshift = 0;
while ((bitmask & (1 << bitshift)) == 0)
bitshift++;
return bitshift;
}
static void save_same_name_hfinfo(gpointer data)
{
same_name_hfinfo = (header_field_info*)data;
}
static gint
proto_compare_name(gconstpointer p1_arg, gconstpointer p2_arg)
{
const protocol_t *p1 = p1_arg;
const protocol_t *p2 = p2_arg;
return g_ascii_strcasecmp(p1->short_name, p2->short_name);
}
void
proto_init(void (register_all_protocols_func)(register_cb cb, gpointer client_data),
void (register_all_handoffs_func)(register_cb cb, gpointer client_data),
register_cb cb,
gpointer client_data)
{
static hf_register_info hf[] = {
{ &hf_text_only,
{ "Text item", "text", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
proto_cleanup();
proto_names = g_hash_table_new_full(g_int_hash, g_int_equal, g_free, NULL);
proto_short_names = g_hash_table_new(wrs_str_hash, g_str_equal);
proto_filter_names = g_hash_table_new(wrs_str_hash, g_str_equal);
gpa_hfinfo.len = 0;
gpa_hfinfo.allocated_len = 0;
gpa_hfinfo.hfi = NULL;
gpa_name_tree = g_tree_new_full(wrs_strcmp_with_data, NULL, NULL, save_same_name_hfinfo);
ftypes_initialize();
proto_register_field_array(-1, hf, array_length(hf));
register_all_protocols_func(cb, client_data);
#ifdef HAVE_PYTHON
if (cb)
(*cb)(RA_PYTHON_REGISTER, NULL, client_data);
register_all_py_protocols_func();
#endif
#ifdef HAVE_PLUGINS
if (cb)
(*cb)(RA_PLUGIN_REGISTER, NULL, client_data);
init_plugins();
register_all_plugin_registrations();
#endif
register_all_handoffs_func(cb, client_data);
#ifdef HAVE_PYTHON
if (cb)
(*cb)(RA_PYTHON_HANDOFF, NULL, client_data);
register_all_py_handoffs_func();
#endif
#ifdef HAVE_PLUGINS
if (cb)
(*cb)(RA_PLUGIN_HANDOFF, NULL, client_data);
register_all_plugin_handoffs();
#endif
protocols = g_list_sort(protocols, proto_compare_name);
tree_is_expanded = g_new0(gboolean, num_tree_types);
}
void
proto_cleanup(void)
{
if (gpa_name_tree) {
g_tree_destroy(gpa_name_tree);
gpa_name_tree = NULL;
}
while (protocols) {
protocol_t *protocol = protocols->data;
header_field_info *hfinfo;
PROTO_REGISTRAR_GET_NTH(protocol->proto_id, hfinfo);
DISSECTOR_ASSERT(protocol->proto_id == hfinfo->id);
g_slice_free(header_field_info, hfinfo);
g_list_free(protocol->fields);
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
node = node->first_child;
while (node != NULL) {
current = node;
node = current->next;
func((proto_tree *)current, data);
}
}
void
proto_tree_free(proto_tree *tree)
{
proto_tree_traverse_post_order(tree, proto_tree_free_node, NULL);
}
static void
free_GPtrArray_value(gpointer key, gpointer value, gpointer user_data _U_)
{
GPtrArray *ptrs = value;
gint hfid = (gint)(long)key;
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
free_node_tree_data(tree_data_t *tree_data)
{
if (tree_data->interesting_hfids) {
g_hash_table_foreach(tree_data->interesting_hfids,
free_GPtrArray_value, NULL);
g_hash_table_destroy(tree_data->interesting_hfids);
}
g_free(tree_data);
}
static gboolean
proto_tree_free_node(proto_node *node, gpointer data _U_)
{
field_info *finfo = PNODE_FINFO(node);
#if 0
proto_node *parent = node->parent;
#endif
if (finfo == NULL) {
if (PTREE_DATA(node))
free_node_tree_data(PTREE_DATA(node));
}
else {
FREE_NODE_FIELD_INFO(finfo);
}
#if 0
if (parent) {
proto_item *prev_item = NULL;
if (parent->first_child == node) {
parent->first_child = node->next;
} else {
for (prev_item = parent->first_child; prev_item; prev_item = prev_item->next) {
if (prev_item->next == node) {
break;
}
}
DISSECTOR_ASSERT(prev_item);
prev_item->next = node->next;
}
if (parent->last_child == node) {
parent->last_child = prev_item;
}
}
DISSECTOR_ASSERT(node->first_child == NULL && node->last_child == NULL);
#endif
PROTO_NODE_FREE(node);
return FALSE;
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
gchar* copy = ep_strdup(key);
gchar* c = copy;
for (; *c; c++) {
if (*c == '.') {
*c = 0;
break;
}
}
return g_str_hash(copy);
}
static gboolean
prefix_equal (gconstpointer ap, gconstpointer bp) {
const gchar* a = ap;
const gchar* b = bp;
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
g_hash_table_insert(prefixes, (gpointer)prefix, pi);
}
static gboolean
initialize_prefix(gpointer k, gpointer v, gpointer u _U_) {
((prefix_initializer_t)v)(k);
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
hfinfo = g_tree_lookup(gpa_name_tree, field_name);
if (hfinfo)
return hfinfo;
if (!prefixes)
return NULL;
if ((pi = g_hash_table_lookup(prefixes, field_name) ) != NULL) {
pi(field_name);
g_hash_table_remove(prefixes, field_name);
} else {
return NULL;
}
return g_tree_lookup(gpa_name_tree, field_name);
}
static void
ptvcursor_new_subtree_levels(ptvcursor_t *ptvc)
{
subtree_lvl *pushed_tree;
DISSECTOR_ASSERT(ptvc->pushed_tree_max <= SUBTREE_MAX_LEVELS-SUBTREE_ONCE_ALLOCATION_NUMBER);
ptvc->pushed_tree_max += SUBTREE_ONCE_ALLOCATION_NUMBER;
pushed_tree = ep_alloc(sizeof(subtree_lvl) * ptvc->pushed_tree_max);
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
ptvc = ep_alloc(sizeof(ptvcursor_t));
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
proto_item *it;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(ptvcursor_tree(ptvc), hf_text_only, hfinfo);
it = proto_tree_add_text_node(ptvcursor_tree(ptvc), ptvcursor_tvbuff(ptvc),
ptvcursor_current_offset(ptvc), length);
if (it == NULL)
return NULL;
va_start(ap, format);
proto_tree_set_representation(it, format, ap);
va_end(ap);
return ptvcursor_add_subtree_item(ptvc, it, ett_subtree, length);
}
static proto_item *
proto_tree_add_text_node(proto_tree *tree, tvbuff_t *tvb, gint start, gint length)
{
proto_item *pi;
pi = proto_tree_add_pi(tree, hf_text_only, tvb, start, &length, NULL);
if (pi == NULL)
return NULL;
return pi;
}
proto_item *
proto_tree_add_text(proto_tree *tree, tvbuff_t *tvb, gint start, gint length,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hf_text_only, hfinfo);
pi = proto_tree_add_text_node(tree, tvb, start, length);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_text_valist(proto_tree *tree, tvbuff_t *tvb, gint start,
gint length, const char *format, va_list ap)
{
proto_item *pi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hf_text_only, hfinfo);
pi = proto_tree_add_text_node(tree, tvb, start, length);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
proto_tree_set_representation(pi, format, ap);
return pi;
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
static guint32
get_uint_value(tvbuff_t *tvb, gint offset, gint length, const guint encoding)
{
guint32 value;
switch (length) {
case 1:
value = tvb_get_guint8(tvb, offset);
break;
case 2:
value = encoding ? tvb_get_letohs(tvb, offset)
: tvb_get_ntohs(tvb, offset);
break;
case 3:
value = encoding ? tvb_get_letoh24(tvb, offset)
: tvb_get_ntoh24(tvb, offset);
break;
case 4:
value = encoding ? tvb_get_letohl(tvb, offset)
: tvb_get_ntohl(tvb, offset);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
value = 0;
break;
}
return value;
}
static gint32
get_int_value(tvbuff_t *tvb, gint offset, gint length, const guint encoding)
{
gint32 value;
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
DISSECTOR_ASSERT_NOT_REACHED();
value = 0;
break;
}
return value;
}
static GPtrArray *
proto_lookup_or_create_interesting_hfids(proto_tree *tree,
header_field_info *hfinfo)
{
GPtrArray *ptrs = NULL;
DISSECTOR_ASSERT(tree);
DISSECTOR_ASSERT(hfinfo);
if (hfinfo->ref_type == HF_REF_TYPE_DIRECT) {
if (PTREE_DATA(tree)->interesting_hfids == NULL) {
PTREE_DATA(tree)->interesting_hfids =
g_hash_table_new(g_direct_hash, NULL );
}
ptrs = g_hash_table_lookup(PTREE_DATA(tree)->interesting_hfids,
GINT_TO_POINTER(hfinfo->id));
if (!ptrs) {
ptrs = g_ptr_array_new();
g_hash_table_insert(PTREE_DATA(tree)->interesting_hfids,
GINT_TO_POINTER(hfinfo->id), ptrs);
}
}
return ptrs;
}
static proto_item *
proto_tree_new_item(field_info *new_fi, proto_tree *tree,
tvbuff_t *tvb, gint start, gint length,
const guint encoding_arg)
{
guint encoding = encoding_arg;
proto_item *pi;
guint32 value, n;
float floatval;
double doubleval;
const char *string;
nstime_t time_stamp;
GPtrArray *ptrs;
if (field_info_tmp) {
FIELD_INFO_FREE(field_info_tmp);
}
field_info_tmp = new_fi;
switch (new_fi->hfinfo->type) {
case FT_NONE:
break;
case FT_PROTOCOL:
proto_tree_set_protocol_tvb(new_fi, tvb);
break;
case FT_BYTES:
proto_tree_set_bytes_tvb(new_fi, tvb, start, length);
break;
case FT_UINT_BYTES:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
n = get_uint_value(tvb, start, length, encoding);
proto_tree_set_bytes_tvb(new_fi, tvb, start + length, n);
new_fi->length = n + length;
break;
case FT_BOOLEAN:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
proto_tree_set_boolean(new_fi,
get_uint_value(tvb, start, length, encoding));
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
proto_tree_set_uint(new_fi,
get_uint_value(tvb, start, length, encoding));
break;
case FT_INT64:
case FT_UINT64:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
DISSECTOR_ASSERT( length <= 8 && length >= 1);
proto_tree_set_uint64_tvb(new_fi, tvb, start, length, encoding);
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
proto_tree_set_int(new_fi,
get_int_value(tvb, start, length, encoding));
break;
case FT_IPv4:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
DISSECTOR_ASSERT(length == FT_IPv4_LEN);
value = tvb_get_ipv4(tvb, start);
proto_tree_set_ipv4(new_fi, encoding ? GUINT32_SWAP_LE_BE(value) : value);
break;
case FT_IPXNET:
DISSECTOR_ASSERT(length == FT_IPXNET_LEN);
proto_tree_set_ipxnet(new_fi,
get_uint_value(tvb, start, 4, FALSE));
break;
case FT_IPv6:
DISSECTOR_ASSERT(length >= 0 && length <= FT_IPv6_LEN);
proto_tree_set_ipv6_tvb(new_fi, tvb, start, length);
break;
case FT_ETHER:
DISSECTOR_ASSERT(length == FT_ETHER_LEN);
proto_tree_set_ether_tvb(new_fi, tvb, start);
break;
case FT_EUI64:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
DISSECTOR_ASSERT(length == FT_EUI64_LEN);
proto_tree_set_eui64_tvb(new_fi, tvb, start, encoding);
break;
case FT_GUID:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
DISSECTOR_ASSERT(length == FT_GUID_LEN);
proto_tree_set_guid_tvb(new_fi, tvb, start, encoding);
break;
case FT_OID:
proto_tree_set_oid_tvb(new_fi, tvb, start, length);
break;
case FT_FLOAT:
if (encoding)
encoding = ENC_LITTLE_ENDIAN;
DISSECTOR_ASSERT(length == 4);
if (encoding)
floatval = tvb_get_letohieee_float(tvb, start);
else
floatval = tvb_get_ntohieee_float(tvb, start);
proto_tree_set_float(new_fi, floatval);
break;
case FT_DOUBLE:
if (encoding == TRUE)
encoding = ENC_LITTLE_ENDIAN;
DISSECTOR_ASSERT(length == 8);
if (encoding)
doubleval = tvb_get_letohieee_double(tvb, start);
else
doubleval = tvb_get_ntohieee_double(tvb, start);
proto_tree_set_double(new_fi, doubleval);
break;
case FT_STRING:
proto_tree_set_string_tvb(new_fi, tvb, start, length,
encoding);
break;
case FT_STRINGZ:
DISSECTOR_ASSERT(length >= -1);
if (length == -1) {
string = tvb_get_stringz_enc(tvb, start, &length, encoding);
} else if (length == 0) {
string = "[Empty]";
} else {
string = tvb_get_ephemeral_string_enc(tvb, start, length, encoding);
}
new_fi->length = length;
proto_tree_set_string(new_fi, string);
break;
case FT_UINT_STRING:
if (encoding == TRUE)
encoding = ENC_ASCII|ENC_LITTLE_ENDIAN;
n = get_uint_value(tvb, start, length, encoding);
proto_tree_set_string_tvb(new_fi, tvb, start + length, n,
encoding);
new_fi->length = n + length;
break;
case FT_ABSOLUTE_TIME:
if (encoding == TRUE)
encoding = ENC_TIME_TIMESPEC|ENC_LITTLE_ENDIAN;
switch (encoding) {
case ENC_TIME_TIMESPEC|ENC_BIG_ENDIAN:
DISSECTOR_ASSERT(length == 8 || length == 4);
time_stamp.secs = tvb_get_ntohl(tvb, start);
if (length == 8)
time_stamp.nsecs = tvb_get_ntohl(tvb, start+4);
else
time_stamp.nsecs = 0;
break;
case ENC_TIME_TIMESPEC|ENC_LITTLE_ENDIAN:
DISSECTOR_ASSERT(length == 8 || length == 4);
time_stamp.secs = tvb_get_letohl(tvb, start);
if (length == 8)
time_stamp.nsecs = tvb_get_letohl(tvb, start+4);
else
time_stamp.nsecs = 0;
break;
case ENC_TIME_NTP|ENC_BIG_ENDIAN:
DISSECTOR_ASSERT(length == 8 || length == 4);
#define NTP_BASETIME 2208988800ul
time_stamp.secs = tvb_get_ntohl(tvb, start);
if (time_stamp.secs)
time_stamp.secs -= NTP_BASETIME;
if (length == 8) {
time_stamp.nsecs = (int)(1000000*(tvb_get_ntohl(tvb, start+4)/4294967296.0));
time_stamp.nsecs *= 1000;
} else {
time_stamp.nsecs = 0;
}
break;
case ENC_TIME_NTP|ENC_LITTLE_ENDIAN:
DISSECTOR_ASSERT(length == 8 || length == 4);
time_stamp.secs = tvb_get_letohl(tvb, start);
if (time_stamp.secs)
time_stamp.secs -= NTP_BASETIME;
if (length == 8) {
time_stamp.nsecs = (int)(1000000*(tvb_get_letohl(tvb, start+4)/4294967296.0));
time_stamp.nsecs *= 1000;
} else {
time_stamp.nsecs = 0;
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
time_stamp.secs = 0;
time_stamp.nsecs = 0;
break;
}
proto_tree_set_time(new_fi, &time_stamp);
break;
case FT_RELATIVE_TIME:
if (encoding == TRUE)
encoding = ENC_TIME_TIMESPEC|ENC_LITTLE_ENDIAN;
switch (encoding) {
case ENC_TIME_TIMESPEC|ENC_BIG_ENDIAN:
DISSECTOR_ASSERT(length == 8 || length == 4);
time_stamp.secs = tvb_get_ntohl(tvb, start);
if (length == 8)
time_stamp.nsecs = tvb_get_ntohl(tvb, start+4);
else
time_stamp.nsecs = 0;
break;
case ENC_TIME_TIMESPEC|ENC_LITTLE_ENDIAN:
DISSECTOR_ASSERT(length == 8 || length == 4);
time_stamp.secs = tvb_get_letohl(tvb, start);
if (length == 8)
time_stamp.nsecs = tvb_get_letohl(tvb, start+4);
else
time_stamp.nsecs = 0;
break;
}
proto_tree_set_time(new_fi, &time_stamp);
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
field_info_tmp = NULL;
ptrs = proto_lookup_or_create_interesting_hfids(tree, new_fi->hfinfo);
if (ptrs)
g_ptr_array_add(ptrs, new_fi);
return pi;
}
proto_item *
ptvcursor_add(ptvcursor_t *ptvc, int hfindex, gint length,
const guint encoding)
{
field_info *new_fi;
header_field_info *hfinfo;
gint item_length;
guint32 n;
int offset;
offset = ptvc->offset;
hfinfo = get_hfi_and_length(hfindex, ptvc->tvb, offset, &length,
&item_length);
ptvc->offset += length;
if (hfinfo->type == FT_UINT_BYTES || hfinfo->type == FT_UINT_STRING) {
n = get_uint_value(ptvc->tvb, offset, length, encoding);
ptvc->offset += n;
}
TRY_TO_FAKE_THIS_ITEM(ptvc->tree, hfindex, hfinfo);
new_fi = new_field_info(ptvc->tree, hfinfo, ptvc->tvb, offset, item_length);
if (new_fi == NULL)
return NULL;
return proto_tree_new_item(new_fi, ptvc->tree, ptvc->tvb,
offset, length, encoding);
}
proto_item *
proto_tree_add_item(proto_tree *tree, const int hfindex, tvbuff_t *tvb,
const gint start, gint length, const guint encoding)
{
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
new_fi = alloc_field_info(tree, hfindex, tvb, start, &length);
if (new_fi == NULL)
return NULL;
return proto_tree_new_item(new_fi, tree, tvb, start,
length, encoding);
}
proto_item *
proto_tree_add_none_format(proto_tree *tree, const int hfindex, tvbuff_t *tvb,
const gint start, gint length, const char *format,
...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_NONE);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, NULL);
TRY_TO_FAKE_THIS_REPR(tree, pi);
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
proto_tree_set_protocol_tvb(field_info *fi, tvbuff_t *tvb)
{
fvalue_set(&fi->value, tvb, TRUE);
}
proto_item *
proto_tree_add_protocol_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const char *format, ...)
{
proto_item *pi;
va_list ap;
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_PROTOCOL);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
proto_tree_set_protocol_tvb(new_fi, (start == 0 ? tvb : tvb_new_subset(tvb, start, length, length)));
TRY_TO_FAKE_THIS_REPR(tree, pi);
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
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_BYTES);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
proto_tree_set_bytes(new_fi, start_ptr, length);
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
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
if (start_ptr)
pi = proto_tree_add_bytes(tree, hfindex, tvb, start, length,
start_ptr);
else
pi = proto_tree_add_bytes(tree, hfindex, tvb, start, length,
tvb_get_ptr(tvb, start, length));
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
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
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
if (start_ptr)
pi = proto_tree_add_bytes(tree, hfindex, tvb, start, length,
start_ptr);
else
pi = proto_tree_add_bytes(tree, hfindex, tvb, start, length,
tvb_get_ptr(tvb, start, length));
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
static void
proto_tree_set_bytes(field_info *fi, const guint8* start_ptr, gint length)
{
GByteArray *bytes;
bytes = g_byte_array_new();
if (length > 0) {
g_byte_array_append(bytes, start_ptr, length);
}
fvalue_set(&fi->value, bytes, TRUE);
}
static void
proto_tree_set_bytes_tvb(field_info *fi, tvbuff_t *tvb, gint offset, gint length)
{
proto_tree_set_bytes(fi, tvb_get_ptr(tvb, offset, length), length);
}
proto_item *
proto_tree_add_time(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, nstime_t *value_ptr)
{
proto_item *pi;
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_ABSOLUTE_TIME ||
hfinfo->type == FT_RELATIVE_TIME);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
proto_tree_set_time(new_fi, value_ptr);
return pi;
}
proto_item *
proto_tree_add_time_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, nstime_t *value_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_time(tree, hfindex, tvb, start, length, value_ptr);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_time_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, nstime_t *value_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_time(tree, hfindex, tvb, start, length, value_ptr);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
static void
proto_tree_set_time(field_info *fi, nstime_t *value_ptr)
{
DISSECTOR_ASSERT(value_ptr != NULL);
fvalue_set(&fi->value, value_ptr, FALSE);
}
proto_item *
proto_tree_add_ipxnet(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, guint32 value)
{
proto_item *pi;
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_IPXNET);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
proto_tree_set_ipxnet(new_fi, value);
return pi;
}
proto_item *
proto_tree_add_ipxnet_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint32 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_ipxnet(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_ipxnet_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint32 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_ipxnet(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
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
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_IPv4);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
proto_tree_set_ipv4(new_fi, value);
return pi;
}
proto_item *
proto_tree_add_ipv4_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint32 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_ipv4(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_ipv4_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint32 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_ipv4(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
static void
proto_tree_set_ipv4(field_info *fi, guint32 value)
{
fvalue_set_uinteger(&fi->value, value);
}
proto_item *
proto_tree_add_ipv6(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, const guint8* value_ptr)
{
proto_item *pi;
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_IPv6);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
proto_tree_set_ipv6(new_fi, value_ptr);
return pi;
}
proto_item *
proto_tree_add_ipv6_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length,
const guint8* value_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_ipv6(tree, hfindex, tvb, start, length, value_ptr);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_ipv6_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const guint8* value_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_ipv6(tree, hfindex, tvb, start, length, value_ptr);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
static void
proto_tree_set_ipv6(field_info *fi, const guint8* value_ptr)
{
DISSECTOR_ASSERT(value_ptr != NULL);
fvalue_set(&fi->value, (gpointer) value_ptr, FALSE);
}
static void
proto_tree_set_ipv6_tvb(field_info *fi, tvbuff_t *tvb, gint start, gint length)
{
proto_tree_set_ipv6(fi, tvb_get_ptr(tvb, start, length));
}
proto_item *
proto_tree_add_guid(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, const e_guid_t *value_ptr)
{
proto_item *pi;
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_GUID);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
proto_tree_set_guid(new_fi, value_ptr);
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
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_guid(tree, hfindex, tvb, start, length, value_ptr);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_guid_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const e_guid_t *value_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_guid(tree, hfindex, tvb, start, length, value_ptr);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
static void
proto_tree_set_guid(field_info *fi, const e_guid_t *value_ptr)
{
DISSECTOR_ASSERT(value_ptr != NULL);
fvalue_set(&fi->value, (gpointer) value_ptr, FALSE);
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
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_OID);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
proto_tree_set_oid(new_fi, value_ptr, length);
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
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_oid(tree, hfindex, tvb, start, length, value_ptr);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_oid_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const guint8* value_ptr,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_oid(tree, hfindex, tvb, start, length, value_ptr);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
static void
proto_tree_set_oid(field_info *fi, const guint8* value_ptr, gint length)
{
GByteArray *bytes;
DISSECTOR_ASSERT(value_ptr != NULL);
bytes = g_byte_array_new();
if (length > 0) {
g_byte_array_append(bytes, value_ptr, length);
}
fvalue_set(&fi->value, bytes, TRUE);
}
static void
proto_tree_set_oid_tvb(field_info *fi, tvbuff_t *tvb, gint start, gint length)
{
proto_tree_set_oid(fi, tvb_get_ptr(tvb, start, length), length);
}
static void
proto_tree_set_uint64(field_info *fi, guint64 value)
{
fvalue_set_integer64(&fi->value, value);
}
static void
proto_tree_set_uint64_tvb(field_info *fi, tvbuff_t *tvb, gint start,
guint length, const guint encoding)
{
guint64 value = 0;
guint8* b = ep_tvb_memdup(tvb, start, length);
if (encoding) {
b += length;
switch (length) {
default: DISSECTOR_ASSERT_NOT_REACHED();
case 8: value <<= 8; value += *--b;
case 7: value <<= 8; value += *--b;
case 6: value <<= 8; value += *--b;
case 5: value <<= 8; value += *--b;
case 4: value <<= 8; value += *--b;
case 3: value <<= 8; value += *--b;
case 2: value <<= 8; value += *--b;
case 1: value <<= 8; value += *--b;
break;
}
} else {
switch (length) {
default: DISSECTOR_ASSERT_NOT_REACHED();
case 8: value <<= 8; value += *b++;
case 7: value <<= 8; value += *b++;
case 6: value <<= 8; value += *b++;
case 5: value <<= 8; value += *b++;
case 4: value <<= 8; value += *b++;
case 3: value <<= 8; value += *b++;
case 2: value <<= 8; value += *b++;
case 1: value <<= 8; value += *b++;
break;
}
}
proto_tree_set_uint64(fi, value);
}
proto_item *
proto_tree_add_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, const char* value)
{
proto_item *pi;
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_STRING || hfinfo->type == FT_STRINGZ);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
DISSECTOR_ASSERT(length >= 0);
proto_tree_set_string(new_fi, value);
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
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_string(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_string_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const char* value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_string(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
void
proto_item_append_string(proto_item *pi, const char *str)
{
field_info *fi;
header_field_info *hfinfo;
gchar *old_str, *new_str;
if (!pi)
return;
if (!*str)
return;
fi = PITEM_FINFO(pi);
DISSECTOR_ASSERT_HINT(fi, "proto_tree_set_visible(tree, TRUE) should have been called previously");
hfinfo = fi->hfinfo;
if (hfinfo->type == FT_PROTOCOL) {
return;
}
DISSECTOR_ASSERT(hfinfo->type == FT_STRING || hfinfo->type == FT_STRINGZ);
old_str = fvalue_get(&fi->value);
new_str = ep_strdup_printf("%s%s", old_str, str);
fvalue_set(&fi->value, new_str, FALSE);
}
static void
proto_tree_set_string(field_info *fi, const char* value)
{
if (value) {
fvalue_set(&fi->value, (gpointer) value, FALSE);
} else {
fvalue_set(&fi->value, (gpointer) "[ Null ]", FALSE);
}
}
static void
proto_tree_set_string_tvb(field_info *fi, tvbuff_t *tvb, gint start, gint length, gint encoding)
{
gchar *string;
if (length == -1) {
length = tvb_ensure_length_remaining(tvb, start);
}
string = tvb_get_ephemeral_string_enc(tvb, start, length, encoding);
proto_tree_set_string(fi, string);
}
proto_item *
proto_tree_add_ether(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, const guint8* value)
{
proto_item *pi;
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_ETHER);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
proto_tree_set_ether(new_fi, value);
return pi;
}
proto_item *
proto_tree_add_ether_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const guint8* value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_ether(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_ether_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const guint8* value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_ether(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
static void
proto_tree_set_ether(field_info *fi, const guint8* value)
{
fvalue_set(&fi->value, (gpointer) value, FALSE);
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
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_BOOLEAN);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
proto_tree_set_boolean(new_fi, value);
return pi;
}
proto_item *
proto_tree_add_boolean_format_value(proto_tree *tree, int hfindex,
tvbuff_t *tvb, gint start, gint length,
guint32 value, const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_boolean(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_boolean_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint32 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_boolean(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
static void
proto_tree_set_boolean(field_info *fi, guint32 value)
{
proto_tree_set_uint(fi, value);
}
proto_item *
proto_tree_add_float(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, float value)
{
proto_item *pi;
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_FLOAT);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
proto_tree_set_float(new_fi, value);
return pi;
}
proto_item *
proto_tree_add_float_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, float value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_float(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_float_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, float value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_float(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
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
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_DOUBLE);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
proto_tree_set_double(new_fi, value);
return pi;
}
proto_item *
proto_tree_add_double_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, double value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_double(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_double_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, double value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_double(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
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
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
switch (hfinfo->type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_FRAMENUM:
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length,
&new_fi);
proto_tree_set_uint(new_fi, value);
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
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_uint(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_uint_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint32 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_uint(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
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
integer &= hfinfo->bitmask;
if (hfinfo->bitshift > 0) {
integer >>= hfinfo->bitshift;
}
}
fvalue_set_uinteger(&fi->value, integer);
}
proto_item *
proto_tree_add_uint64(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, guint64 value)
{
proto_item *pi = NULL;
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_UINT64);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
proto_tree_set_uint64(new_fi, value);
return pi;
}
proto_item *
proto_tree_add_uint64_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint64 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_uint64(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_uint64_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, guint64 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_uint64(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_int(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, gint32 value)
{
proto_item *pi = NULL;
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
switch (hfinfo->type) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length,
&new_fi);
proto_tree_set_int(new_fi, value);
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
proto_item *pi = NULL;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_int(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_int_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, gint32 value,
const char *format, ...)
{
proto_item *pi = NULL;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_int(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
static void
proto_tree_set_int(field_info *fi, gint32 value)
{
header_field_info *hfinfo;
guint32 integer;
hfinfo = fi->hfinfo;
integer = (guint32) value;
if (hfinfo->bitmask) {
integer &= hfinfo->bitmask;
if (hfinfo->bitshift > 0) {
integer >>= hfinfo->bitshift;
}
}
fvalue_set_sinteger(&fi->value, integer);
}
proto_item *
proto_tree_add_int64(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, gint64 value)
{
proto_item *pi = NULL;
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_INT64);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
proto_tree_set_uint64(new_fi, (guint64)value);
return pi;
}
proto_item *
proto_tree_add_int64_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, gint64 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_int64(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_int64_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, gint64 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_int64(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_eui64(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint length, const guint64 value)
{
proto_item *pi;
field_info *new_fi;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_EUI64);
pi = proto_tree_add_pi(tree, hfindex, tvb, start, &length, &new_fi);
proto_tree_set_eui64(new_fi, value);
return pi;
}
proto_item *
proto_tree_add_eui64_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const guint64 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_eui64(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation_value(pi, format, ap);
va_end(ap);
return pi;
}
proto_item *
proto_tree_add_eui64_format(proto_tree *tree, int hfindex, tvbuff_t *tvb,
gint start, gint length, const guint64 value,
const char *format, ...)
{
proto_item *pi;
va_list ap;
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo);
pi = proto_tree_add_eui64(tree, hfindex, tvb, start, length, value);
if (pi == NULL)
return NULL;
TRY_TO_FAKE_THIS_REPR(tree, pi);
va_start(ap, format);
proto_tree_set_representation(pi, format, ap);
va_end(ap);
return pi;
}
static void
proto_tree_set_eui64(field_info *fi, const guint64 value)
{
fvalue_set_integer64(&fi->value, value);
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
tnode = tree;
tfi = PNODE_FINFO(tnode);
if (tfi != NULL && (tfi->tree_type < 0 || tfi->tree_type >= num_tree_types)) {
REPORT_DISSECTOR_BUG(ep_strdup_printf("\"%s\" - \"%s\" tfi->tree_type: %u invalid (%s:%u)",
fi->hfinfo->name, fi->hfinfo->abbrev, tfi->tree_type, __FILE__, __LINE__));
}
DISSECTOR_ASSERT(tfi == NULL ||
(tfi->tree_type >= 0 && tfi->tree_type < num_tree_types));
PROTO_NODE_NEW(pnode);
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
return (proto_item *)pnode;
}
static proto_item *
proto_tree_add_pi(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start,
gint *length, field_info **pfi)
{
proto_item *pi;
field_info *fi;
GPtrArray *ptrs;
if (!tree)
return NULL;
fi = alloc_field_info(tree, hfindex, tvb, start, length);
pi = proto_tree_add_node(tree, fi);
ptrs = proto_lookup_or_create_interesting_hfids(tree, fi->hfinfo);
if (ptrs)
g_ptr_array_add(ptrs, fi);
if (pfi) {
*pfi = fi;
}
return pi;
}
static header_field_info *
get_hfi_and_length(int hfindex, tvbuff_t *tvb, const gint start, gint *length,
gint *item_length)
{
header_field_info *hfinfo;
gint length_remaining;
DISSECTOR_ASSERT(tvb != NULL || *length == 0);
PROTO_REGISTRAR_GET_NTH(hfindex, hfinfo);
if (*length == -1) {
switch (hfinfo->type) {
case FT_PROTOCOL:
*length = tvb_length_remaining(tvb, start);
if (*length < 0) {
tvb_ensure_bytes_exist(tvb, start, 0);
}
DISSECTOR_ASSERT(*length >= 0);
break;
case FT_NONE:
case FT_BYTES:
case FT_STRING:
*length = tvb_ensure_length_remaining(tvb, start);
DISSECTOR_ASSERT(*length >= 0);
break;
case FT_STRINGZ:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
*item_length = *length;
} else {
*item_length = *length;
if (hfinfo->type == FT_PROTOCOL || hfinfo->type == FT_NONE) {
if (tvb) {
length_remaining = tvb_length_remaining(tvb, start);
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
return hfinfo;
}
static field_info *
new_field_info(proto_tree *tree, header_field_info *hfinfo, tvbuff_t *tvb,
const gint start, const gint item_length)
{
field_info *fi;
FIELD_INFO_NEW(fi);
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
static field_info *
alloc_field_info(proto_tree *tree, int hfindex, tvbuff_t *tvb, const gint start,
gint *length)
{
header_field_info *hfinfo;
gint item_length;
hfinfo = get_hfi_and_length(hfindex, tvb, start, length, &item_length);
return new_field_info(tree, hfinfo, tvb, start, item_length);
}
static void
proto_tree_set_representation_value(proto_item *pi, const char *format, va_list ap)
{
int ret;
field_info *fi = PITEM_FINFO(pi);
header_field_info *hf;
DISSECTOR_ASSERT(fi);
hf = fi->hfinfo;
if (!PROTO_ITEM_IS_HIDDEN(pi)) {
ITEM_LABEL_NEW(fi->rep);
if (hf->bitmask && (hf->type == FT_BOOLEAN || IS_FT_UINT(hf->type))) {
char tmpbuf[64];
guint32 val;
val = fvalue_get_uinteger(&fi->value);
if (hf->bitshift > 0) {
val <<= hf->bitshift;
}
decode_bitfield_value(tmpbuf, val, hf->bitmask, hfinfo_bitwidth(hf));
ret = g_snprintf(fi->rep->representation, ITEM_LABEL_LENGTH,
"%s%s: ", tmpbuf, fi->hfinfo->name);
} else {
ret = g_snprintf(fi->rep->representation, ITEM_LABEL_LENGTH,
"%s: ", fi->hfinfo->name);
}
if (ret < ITEM_LABEL_LENGTH) {
ret += g_vsnprintf(fi->rep->representation + ret,
ITEM_LABEL_LENGTH - ret, format, ap);
}
if (ret >= ITEM_LABEL_LENGTH) {
char *oldrep;
oldrep = g_strdup(fi->rep->representation);
g_snprintf(fi->rep->representation,
ITEM_LABEL_LENGTH,
"[truncated] %s",
oldrep);
g_free(oldrep);
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
ITEM_LABEL_NEW(fi->rep);
ret = g_vsnprintf(fi->rep->representation, ITEM_LABEL_LENGTH,
format, ap);
if (ret >= ITEM_LABEL_LENGTH) {
char *oldrep;
oldrep = g_strdup(fi->rep->representation);
g_snprintf(fi->rep->representation, ITEM_LABEL_LENGTH,
"[truncated] %s", oldrep);
g_free(oldrep);
}
}
}
static int
protoo_strlcpy(gchar *dest, const gchar *src, gsize dest_size)
{
gsize res = g_strlcpy(dest, src, dest_size);
if (res > dest_size)
res = dest_size;
return (int) res;
}
const gchar *
proto_custom_set(proto_tree* tree, const int field_id, gint occurrence,
gchar *result, gchar *expr, const int size)
{
guint32 u_integer;
gint32 integer;
guint8 *bytes;
ipv4_addr *ipv4;
struct e_in6_addr *ipv6;
address addr;
guint32 n_addr;
const true_false_string *tfstring;
int len, prev_len = 0, last, i, offset_r = 0, offset_e = 0;
GPtrArray *finfos;
field_info *finfo = NULL;
header_field_info* hfinfo;
const gchar *abbrev = NULL;
g_assert(field_id >= 0);
hfinfo = proto_registrar_get_nth((guint)field_id);
if (!hfinfo)
return "";
if (occurrence < 0) {
while (hfinfo->same_name_prev) {
hfinfo = hfinfo->same_name_prev;
}
}
while (hfinfo) {
finfos = proto_get_finfo_ptr_array(tree, hfinfo->id);
if (!finfos || !(len = g_ptr_array_len(finfos))) {
if (occurrence < 0) {
hfinfo = hfinfo->same_name_next;
} else {
hfinfo = hfinfo->same_name_prev;
}
continue;
}
if (((occurrence - prev_len) > len) || ((occurrence + prev_len) < -len)) {
if (occurrence < 0) {
hfinfo = hfinfo->same_name_next;
} else {
hfinfo = hfinfo->same_name_prev;
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
finfo = g_ptr_array_index(finfos, i);
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
bytes = fvalue_get(&finfo->value);
offset_r += protoo_strlcpy(result+offset_r,
bytes_to_str(bytes,
fvalue_length(&finfo->value)),
size-offset_r);
break;
case FT_ABSOLUTE_TIME:
offset_r += protoo_strlcpy(result+offset_r,
abs_time_to_str(fvalue_get(&finfo->value),
hfinfo->display, TRUE),
size-offset_r);
break;
case FT_RELATIVE_TIME:
offset_r += protoo_strlcpy(result+offset_r,
rel_time_to_secs_str(fvalue_get(&finfo->value)),
size-offset_r);
break;
case FT_BOOLEAN:
u_integer = fvalue_get_uinteger(&finfo->value);
tfstring = (const true_false_string *)&tfs_true_false;
if (hfinfo->strings) {
tfstring = (const struct true_false_string*) hfinfo->strings;
}
offset_r += protoo_strlcpy(result+offset_r,
u_integer ?
tfstring->true_string :
tfstring->false_string, size-offset_r);
g_snprintf(expr+offset_e, size-offset_e, "%u",
fvalue_get_uinteger(&finfo->value) ? 1 : 0);
offset_e = (int)strlen(expr);
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_FRAMENUM:
u_integer = fvalue_get_uinteger(&finfo->value);
if ((hfinfo->display & BASE_DISPLAY_E_MASK) == BASE_CUSTOM) {
gchar tmp[ITEM_LABEL_LENGTH];
custom_fmt_func_t fmtfunc = (custom_fmt_func_t)hfinfo->strings;
DISSECTOR_ASSERT(fmtfunc);
fmtfunc(tmp, u_integer);
g_snprintf(result+offset_r, size-offset_r, "%s", tmp);
} else if (hfinfo->strings) {
if (hfinfo->display & BASE_RANGE_STRING) {
g_strlcpy(result+offset_r,
rval_to_str(u_integer, hfinfo->strings, "%u"),
size-offset_r);
} else if (hfinfo->display & BASE_EXT_STRING) {
g_strlcpy(result+offset_r,
val_to_str_ext(u_integer,
(value_string_ext *)(hfinfo->strings),
"%u"), size-offset_r);
} else {
g_strlcpy(result+offset_r,
val_to_str(u_integer, cVALS(hfinfo->strings), "%u"),
size-offset_r);
}
} else if (IS_BASE_DUAL(hfinfo->display)) {
g_snprintf(result+offset_r, size-offset_r,
hfinfo_uint_value_format(hfinfo), u_integer, u_integer);
} else {
g_snprintf(result+offset_r, size-offset_r,
hfinfo_uint_value_format(hfinfo), u_integer);
}
if (hfinfo->strings && (hfinfo->display & BASE_DISPLAY_E_MASK) == BASE_NONE) {
g_snprintf(expr+offset_e, size-offset_e,
"\"%s\"", result+offset_r);
} else {
g_snprintf(expr+offset_e, size-offset_e,
hfinfo_numeric_value_format(hfinfo),
fvalue_get_uinteger(&finfo->value));
}
offset_r = (int)strlen(result);
offset_e = (int)strlen(expr);
break;
case FT_INT64:
g_snprintf(result+offset_r, size-offset_r,
"%" G_GINT64_MODIFIER "d",
fvalue_get_integer64(&finfo->value));
offset_r = (int)strlen(result);
break;
case FT_UINT64:
g_snprintf(result+offset_r, size-offset_r,
"%" G_GINT64_MODIFIER "u",
fvalue_get_integer64(&finfo->value));
offset_r = (int)strlen(result);
break;
case FT_EUI64:
offset_r += protoo_strlcpy(result+offset_r,
eui64_to_str(fvalue_get_integer64(&finfo->value)),
size-offset_r);
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
integer = fvalue_get_sinteger(&finfo->value);
if ((hfinfo->display & BASE_DISPLAY_E_MASK) == BASE_CUSTOM) {
gchar tmp[ITEM_LABEL_LENGTH];
custom_fmt_func_t fmtfunc = (custom_fmt_func_t)hfinfo->strings;
DISSECTOR_ASSERT(fmtfunc);
fmtfunc(tmp, integer);
g_snprintf(result+offset_r, size-offset_r, "%s", tmp);
} else if (hfinfo->strings) {
if (hfinfo->display & BASE_RANGE_STRING) {
g_strlcpy(result+offset_r,
rval_to_str(integer, hfinfo->strings, "%d"),
size-offset_r);
} else if (hfinfo->display & BASE_EXT_STRING) {
g_strlcpy(result+offset_r,
val_to_str_ext(integer,
(value_string_ext *)(hfinfo->strings),
"%d"),
size-offset_r);
} else {
g_strlcpy(result+offset_r,
val_to_str(integer, cVALS(hfinfo->strings), "%d"),
size-offset_r);
}
} else if (IS_BASE_DUAL(hfinfo->display)) {
g_snprintf(result+offset_r, size-offset_r,
hfinfo_int_value_format(hfinfo), integer, integer);
} else {
g_snprintf(result+offset_r, size-offset_r,
hfinfo_int_value_format(hfinfo), integer);
}
if (hfinfo->strings && (hfinfo->display & BASE_DISPLAY_E_MASK) == BASE_NONE) {
g_snprintf(expr+offset_e, size-offset_e, "\"%s\"", result+offset_r);
} else {
g_snprintf(expr+offset_e, size-offset_e,
hfinfo_numeric_value_format(hfinfo),
fvalue_get_sinteger(&finfo->value));
}
offset_r = (int)strlen(result);
offset_e = (int)strlen(expr);
break;
case FT_IPv4:
ipv4 = fvalue_get(&finfo->value);
n_addr = ipv4_get_net_order_addr(ipv4);
offset_r += protoo_strlcpy(result+offset_r,
ip_to_str((guint8 *)&n_addr),
size-offset_r);
break;
case FT_IPv6:
ipv6 = fvalue_get(&finfo->value);
SET_ADDRESS (&addr, AT_IPv6, sizeof(struct e_in6_addr), ipv6);
address_to_str_buf(&addr, result+offset_r, size-offset_r);
offset_r = (int)strlen(result);
break;
case FT_ETHER:
offset_r += protoo_strlcpy(result+offset_r,
bytes_to_str_punct(fvalue_get(&finfo->value),
FT_ETHER_LEN, ':'),
size-offset_r);
break;
case FT_GUID:
offset_r += protoo_strlcpy(result+offset_r,
guid_to_str((e_guid_t *)fvalue_get(&finfo->value)),
size-offset_r);
break;
case FT_OID:
bytes = fvalue_get(&finfo->value);
offset_r += protoo_strlcpy(result+offset_r,
oid_resolved_from_encoded(bytes,
fvalue_length(&finfo->value)),
size-offset_r);
offset_e += protoo_strlcpy(expr+offset_e,
oid_encoded2string(bytes, fvalue_length(&finfo->value)),
size-offset_e);
break;
case FT_FLOAT:
g_snprintf(result+offset_r, size-offset_r,
"%." STRINGIFY(FLT_DIG) "g", fvalue_get_floating(&finfo->value));
offset_r = (int)strlen(result);
break;
case FT_DOUBLE:
g_snprintf(result+offset_r, size-offset_r,
"%." STRINGIFY(DBL_DIG) "g", fvalue_get_floating(&finfo->value));
offset_r = (int)strlen(result);
break;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
bytes = fvalue_get(&finfo->value);
offset_r += protoo_strlcpy(result+offset_r,
format_text(bytes, strlen(bytes)),
size-offset_r);
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
case FT_FRAMENUM:
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_OID:
break;
default:
g_strlcpy(expr, result, size);
break;
}
if (!abbrev) {
abbrev = hfinfo->abbrev;
}
if (occurrence == 0) {
hfinfo = hfinfo->same_name_prev;
} else {
hfinfo = NULL;
}
}
return abbrev ? abbrev : "";
}
void
proto_item_set_text(proto_item *pi, const char *format, ...)
{
field_info *fi = NULL;
va_list ap;
if (pi == NULL) {
return;
}
fi = PITEM_FINFO(pi);
if (fi == NULL)
return;
if (fi->rep) {
ITEM_LABEL_FREE(fi->rep);
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
if (pi == NULL) {
return;
}
fi = PITEM_FINFO(pi);
if (fi == NULL) {
return;
}
if (!PROTO_ITEM_IS_HIDDEN(pi)) {
if (fi->rep == NULL) {
ITEM_LABEL_NEW(fi->rep);
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
if (pi == NULL) {
return;
}
fi = PITEM_FINFO(pi);
if (fi == NULL) {
return;
}
if (!PROTO_ITEM_IS_HIDDEN(pi)) {
if (fi->rep == NULL) {
ITEM_LABEL_NEW(fi->rep);
proto_item_fill_label(fi, fi->rep->representation);
}
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
if (pi == NULL)
return;
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
if (pi == NULL)
return;
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
gboolean
proto_item_set_expert_flags(proto_item *pi, const int group, const guint severity)
{
if (pi == NULL || PITEM_FINFO(pi) == NULL)
return FALSE;
if (severity >= FI_GET_FLAG(PITEM_FINFO(pi), PI_SEVERITY_MASK)) {
FI_REPLACE_FLAGS(PITEM_FINFO(pi), PI_GROUP_MASK, group);
FI_REPLACE_FLAGS(PITEM_FINFO(pi), PI_SEVERITY_MASK, severity);
return TRUE;
}
return FALSE;
}
proto_tree *
proto_tree_create_root(void)
{
proto_node *pnode;
PROTO_NODE_NEW(pnode);
pnode->parent = NULL;
PNODE_FINFO(pnode) = NULL;
pnode->tree_data = g_new(tree_data_t, 1);
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
proto_item_get_subtree(const proto_item *pi) {
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
proto_tree_get_parent(const proto_tree *tree) {
if (!tree)
return NULL;
return (proto_item *)tree;
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
header_field_info *hfinfo;
int proto_id;
char *existing_name;
gint *key;
guint i;
guchar c;
gboolean found_invalid;
key = g_malloc (sizeof(gint));
*key = wrs_str_hash(name);
existing_name = g_hash_table_lookup(proto_names, key);
if (existing_name != NULL) {
g_error("Duplicate protocol name \"%s\"!"
" This might be caused by an inappropriate plugin or a development error.", name);
}
g_hash_table_insert(proto_names, key, (gpointer)name);
existing_name = g_hash_table_lookup(proto_short_names, (gpointer)short_name);
if (existing_name != NULL) {
g_error("Duplicate protocol short_name \"%s\"!"
" This might be caused by an inappropriate plugin or a development error.", short_name);
}
g_hash_table_insert(proto_short_names, (gpointer)short_name, (gpointer)short_name);
found_invalid = FALSE;
for (i = 0; filter_name[i]; i++) {
c = filter_name[i];
if (!(islower(c) || isdigit(c) || c == '-' || c == '_' || c == '.')) {
found_invalid = TRUE;
}
}
if (found_invalid) {
g_error("Protocol filter name \"%s\" has one or more invalid characters."
" Allowed are lower characters, digits, '-', '_' and '.'."
" This might be caused by an inappropriate plugin or a development error.", filter_name);
}
existing_name = g_hash_table_lookup(proto_filter_names, (gpointer)filter_name);
if (existing_name != NULL) {
g_error("Duplicate protocol filter_name \"%s\"!"
" This might be caused by an inappropriate plugin or a development error.", filter_name);
}
g_hash_table_insert(proto_filter_names, (gpointer)filter_name, (gpointer)filter_name);
protocol = g_new(protocol_t, 1);
protocol->name = name;
protocol->short_name = short_name;
protocol->filter_name = filter_name;
protocol->fields = NULL;
protocol->is_enabled = TRUE;
protocol->can_toggle = TRUE;
protocol->is_private = FALSE;
protocols = g_list_prepend(protocols, protocol);
hfinfo = g_slice_new(header_field_info);
hfinfo->name = name;
hfinfo->abbrev = filter_name;
hfinfo->type = FT_PROTOCOL;
hfinfo->display = BASE_NONE;
hfinfo->strings = protocol;
hfinfo->bitmask = 0;
hfinfo->bitshift = 0;
hfinfo->ref_type = HF_REF_TYPE_NONE;
hfinfo->blurb = NULL;
hfinfo->parent = -1;
proto_id = proto_register_field_init(hfinfo, hfinfo->parent);
protocol->proto_id = proto_id;
return proto_id;
}
void
proto_mark_private(const int proto_id)
{
protocol_t *protocol = find_protocol_by_id(proto_id);
if (protocol)
protocol->is_private = TRUE;
}
gboolean
proto_is_private(const int proto_id)
{
protocol_t *protocol = find_protocol_by_id(proto_id);
if (protocol)
return protocol->is_private;
else
return FALSE;
}
int
proto_get_first_protocol(void **cookie)
{
protocol_t *protocol;
if (protocols == NULL)
return -1;
*cookie = protocols;
protocol = protocols->data;
return protocol->proto_id;
}
int
proto_get_data_protocol(void *cookie)
{
GList *list_item = cookie;
protocol_t *protocol = list_item->data;
return protocol->proto_id;
}
int
proto_get_next_protocol(void **cookie)
{
GList *list_item = *cookie;
protocol_t *protocol;
list_item = g_list_next(list_item);
if (list_item == NULL)
return -1;
*cookie = list_item;
protocol = list_item->data;
return protocol->proto_id;
}
header_field_info *
proto_get_first_protocol_field(const int proto_id, void **cookie)
{
protocol_t *protocol = find_protocol_by_id(proto_id);
hf_register_info *ptr;
if ((protocol == NULL) || (protocol->fields == NULL))
return NULL;
*cookie = protocol->fields;
ptr = protocol->fields->data;
return &ptr->hfinfo;
}
header_field_info *
proto_get_next_protocol_field(void **cookie)
{
GList *list_item = *cookie;
hf_register_info *ptr;
list_item = g_list_next(list_item);
if (list_item == NULL)
return NULL;
*cookie = list_item;
ptr = list_item->data;
return &ptr->hfinfo;
}
protocol_t *
find_protocol_by_id(const int proto_id)
{
header_field_info *hfinfo;
if (proto_id < 0)
return NULL;
PROTO_REGISTRAR_GET_NTH(proto_id, hfinfo);
DISSECTOR_ASSERT(hfinfo->type == FT_PROTOCOL);
return (protocol_t *)hfinfo->strings;
}
static gint compare_filter_name(gconstpointer proto_arg,
gconstpointer filter_name)
{
const protocol_t *protocol = proto_arg;
const gchar *f_name = filter_name;
return (strcmp(protocol->filter_name, f_name));
}
int
proto_get_id(const protocol_t *protocol)
{
return protocol->proto_id;
}
int proto_get_id_by_filter_name(const gchar* filter_name)
{
GList *list_entry;
protocol_t *protocol;
list_entry = g_list_find_custom(protocols, filter_name,
compare_filter_name);
if (list_entry == NULL)
return -1;
protocol = list_entry->data;
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
protocol = list_item->data;
if (protocol->can_toggle)
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
void
proto_register_field_array(const int parent, hf_register_info *hf, const int num_records)
{
int field_id, i;
hf_register_info *ptr = hf;
protocol_t *proto;
proto = find_protocol_by_id(parent);
for (i = 0; i < num_records; i++, ptr++) {
if (*ptr->p_id != -1 && *ptr->p_id != 0) {
fprintf(stderr,
"Duplicate field detected in call to proto_register_field_array: %s is already registered\n",
ptr->hfinfo.abbrev);
return;
}
if (proto != NULL) {
if (proto->fields == NULL) {
proto->fields = g_list_append(NULL, ptr);
proto->last_field = proto->fields;
} else {
proto->last_field =
g_list_append(proto->last_field, ptr)->next;
}
}
field_id = proto_register_field_init(&ptr->hfinfo, parent);
*ptr->p_id = field_id;
}
}
void
proto_unregister_field (const int parent, gint hf_id)
{
hf_register_info *hf;
protocol_t *proto;
GList *field;
if (hf_id == -1 || hf_id == 0)
return;
proto = find_protocol_by_id (parent);
if (!proto || !proto->fields) {
return;
}
for (field = g_list_first (proto->fields); field; field = g_list_next (field)) {
hf = field->data;
if (*hf->p_id == hf_id) {
g_tree_steal (gpa_name_tree, hf->hfinfo.abbrev);
proto->fields = g_list_remove_link (proto->fields, field);
proto->last_field = g_list_last (proto->fields);
break;
}
}
}
static void
tmp_fld_check_assert(header_field_info *hfinfo) {
static const value_string hf_types[] = {
{ FT_NONE, "FT_NONE" },
{ FT_PROTOCOL, "FT_PROTOCOL" },
{ FT_BOOLEAN, "FT_BOOLEAN" },
{ FT_UINT8, "FT_UINT8" },
{ FT_UINT16, "FT_UINT16" },
{ FT_UINT24, "FT_UINT24" },
{ FT_UINT32, "FT_UINT32" },
{ FT_UINT64, "FT_UINT64" },
{ FT_INT8, "FT_INT8" },
{ FT_INT16, "FT_INT16" },
{ FT_INT24, "FT_INT24" },
{ FT_INT32, "FT_INT32" },
{ FT_INT64, "FT_INT64" },
{ FT_EUI64, "FT_EUI64" },
{ FT_FLOAT, "FT_FLOAT" },
{ FT_DOUBLE, "FT_DOUBLE" },
{ FT_ABSOLUTE_TIME, "FT_ABSOLUTE_TIME" },
{ FT_RELATIVE_TIME, "FT_RELATIVE_TIME" },
{ FT_STRING, "FT_STRING" },
{ FT_STRINGZ, "FT_STRINGZ" },
{ FT_UINT_STRING, "FT_UINT_STRING" },
{ FT_ETHER, "FT_ETHER" },
{ FT_BYTES, "FT_BYTES" },
{ FT_UINT_BYTES, "FT_UINT_BYTES" },
{ FT_IPv4, "FT_IPv4" },
{ FT_IPv6, "FT_IPv6" },
{ FT_IPXNET, "FT_IPXNET" },
{ FT_FRAMENUM, "FT_FRAMENUM" },
{ FT_PCRE, "FT_PCR" },
{ FT_GUID, "FT_GUID" },
{ FT_OID, "FT_OID" },
{ 0, NULL } };
static const value_string hf_display[] = {
{ BASE_NONE, "BASE_NONE" },
{ BASE_DEC, "BASE_DEC" },
{ BASE_HEX, "BASE_HEX" },
{ BASE_OCT, "BASE_OCT" },
{ BASE_DEC_HEX, "BASE_DEC_HEX" },
{ BASE_HEX_DEC, "BASE_HEX_DEC" },
{ BASE_CUSTOM, "BASE_CUSTOM" },
{ BASE_NONE|BASE_RANGE_STRING, "BASE_NONE|BASE_RANGE_STRING" },
{ BASE_DEC|BASE_RANGE_STRING, "BASE_DEC|BASE_RANGE_STRING" },
{ BASE_HEX|BASE_RANGE_STRING, "BASE_HEX|BASE_RANGE_STRING" },
{ BASE_OCT|BASE_RANGE_STRING, "BASE_OCT|BASE_RANGE_STRING" },
{ BASE_DEC_HEX|BASE_RANGE_STRING, "BASE_DEC_HEX|BASE_RANGE_STRING" },
{ BASE_HEX_DEC|BASE_RANGE_STRING, "BASE_HEX_DEC|BASE_RANGE_STRING" },
{ BASE_CUSTOM|BASE_RANGE_STRING, "BASE_CUSTOM|BASE_RANGE_STRING" },
{ ABSOLUTE_TIME_LOCAL, "ABSOLUTE_TIME_LOCAL" },
{ ABSOLUTE_TIME_UTC, "ABSOLUTE_TIME_UTC" },
{ ABSOLUTE_TIME_DOY_UTC, "ABSOLUTE_TIME_DOY_UTC" },
{ 0, NULL } };
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
(hfinfo->type == FT_INT8) ||
(hfinfo->type == FT_INT16) ||
(hfinfo->type == FT_INT24) ||
(hfinfo->type == FT_INT32) ||
(hfinfo->type == FT_BOOLEAN) ||
(hfinfo->type == FT_PROTOCOL) ||
(hfinfo->type == FT_FRAMENUM) ))
g_error("Field '%s' (%s) has a 'strings' value but is of type %s"
" (which is not allowed to have strings)\n",
hfinfo->name, hfinfo->abbrev,
val_to_str(hfinfo->type, hf_types, "(Unknown: %d)"));
#if 0
if ((hfinfo->strings != NULL) &&
!(hfinfo->display & BASE_RANGE_STRING) &&
!((hfinfo->display & BASE_DISPLAY_E_MASK) == BASE_CUSTOM) &&
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
case FT_INT64:
if (hfinfo->display == BASE_HEX ||
hfinfo->display == BASE_OCT)
g_error("Field '%s' (%s) is signed (%s) but is being displayed unsigned (%s)\n",
hfinfo->name, hfinfo->abbrev,
val_to_str(hfinfo->type, hf_types, "(Unknown: %d)"),
val_to_str(hfinfo->display, hf_display, "(Bit count: %d)"));
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT64:
if (hfinfo->strings == NULL) {
if (hfinfo->display == BASE_NONE)
g_error("Field '%s' (%s) is an integral value (%s)"
" without strings but is being displayed as BASE_NONE\n",
hfinfo->name, hfinfo->abbrev,
val_to_str(hfinfo->type, hf_types, "(Unknown: %d)"));
}
break;
case FT_PROTOCOL:
case FT_FRAMENUM:
if (hfinfo->display != BASE_NONE)
g_error("Field '%s' (%s) is an %s but is being displayed as %s instead of BASE_NONE\n",
hfinfo->name, hfinfo->abbrev,
val_to_str(hfinfo->type, hf_types, "(Unknown: %d)"),
val_to_str(hfinfo->display, hf_display, "(Bit count: %d)"));
if (hfinfo->bitmask != 0)
g_error("Field '%s' (%s) is an %s but has a bitmask\n",
hfinfo->name, hfinfo->abbrev,
val_to_str(hfinfo->type, hf_types, "(Unknown: %d)"));
break;
case FT_BOOLEAN:
break;
case FT_ABSOLUTE_TIME:
if (!(hfinfo->display == ABSOLUTE_TIME_LOCAL ||
hfinfo->display == ABSOLUTE_TIME_UTC ||
hfinfo->display == ABSOLUTE_TIME_DOY_UTC))
g_error("Field '%s' (%s) is a %s but is being displayed as %s instead of as a time\n",
hfinfo->name, hfinfo->abbrev,
val_to_str(hfinfo->type, hf_types, "(Unknown: %d)"),
val_to_str(hfinfo->display, hf_display, "(Bit count: %d)"));
if (hfinfo->bitmask != 0)
g_error("Field '%s' (%s) is an %s but has a bitmask\n",
hfinfo->name, hfinfo->abbrev,
val_to_str(hfinfo->type, hf_types, "(Unknown: %d)"));
break;
default:
if (hfinfo->display != BASE_NONE)
g_error("Field '%s' (%s) is an %s but is being displayed as %s instead of BASE_NONE\n",
hfinfo->name, hfinfo->abbrev,
val_to_str(hfinfo->type, hf_types, "(Unknown: %d)"),
val_to_str(hfinfo->display, hf_display, "(Bit count: %d)"));
if (hfinfo->bitmask != 0)
g_error("Field '%s' (%s) is an %s but has a bitmask\n",
hfinfo->name, hfinfo->abbrev,
val_to_str(hfinfo->type, hf_types, "(Unknown: %d)"));
if (hfinfo->strings != NULL)
g_error("Field '%s' (%s) is an %s but has a strings value\n",
hfinfo->name, hfinfo->abbrev,
val_to_str(hfinfo->type, hf_types, "(Unknown: %d)"));
break;
}
}
static int
proto_register_field_init(header_field_info *hfinfo, const int parent)
{
tmp_fld_check_assert(hfinfo);
if (hfinfo->bitmask) {
hfinfo->bitshift = wrs_count_bitshift(hfinfo->bitmask);
}
hfinfo->parent = parent;
hfinfo->same_name_next = NULL;
hfinfo->same_name_prev = NULL;
if (gpa_hfinfo.len >= gpa_hfinfo.allocated_len) {
if (!gpa_hfinfo.hfi) {
gpa_hfinfo.allocated_len = PROTO_PRE_ALLOC_HF_FIELDS_MEM;
gpa_hfinfo.hfi = g_malloc(sizeof(header_field_info *)*PROTO_PRE_ALLOC_HF_FIELDS_MEM);
} else {
gpa_hfinfo.allocated_len += 1000;
gpa_hfinfo.hfi = g_realloc(gpa_hfinfo.hfi,
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
fprintf(stderr, "Invalid character '%c' in filter name '%s'\n", c, hfinfo->abbrev);
DISSECTOR_ASSERT(!c);
}
same_name_hfinfo = NULL;
g_tree_insert(gpa_name_tree, (gpointer) (hfinfo->abbrev), hfinfo);
if (same_name_hfinfo) {
same_name_next_hfinfo =
same_name_hfinfo->same_name_next;
hfinfo->same_name_next = same_name_next_hfinfo;
if (same_name_next_hfinfo)
same_name_next_hfinfo->same_name_prev = hfinfo;
same_name_hfinfo->same_name_next = hfinfo;
hfinfo->same_name_prev = same_name_hfinfo;
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
tree_is_expanded =
g_realloc(tree_is_expanded,
(num_tree_types + num_indices)*sizeof (gboolean));
memset(tree_is_expanded + num_tree_types, 0,
num_indices*sizeof (gboolean));
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
void
proto_item_fill_label(field_info *fi, gchar *label_str)
{
header_field_info *hfinfo;
guint8 *bytes;
guint32 integer;
guint64 integer64;
ipv4_addr *ipv4;
e_guid_t *guid;
guint32 n_addr;
const gchar *name;
int ret;
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
bytes = fvalue_get(&fi->value);
if (bytes) {
ret = g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s", hfinfo->name,
bytes_to_str(bytes, fvalue_length(&fi->value)));
if (ret >= ITEM_LABEL_LENGTH) {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s [truncated]: %s",
hfinfo->name,
bytes_to_str(bytes, fvalue_length(&fi->value)));
}
}
else {
g_snprintf(label_str, ITEM_LABEL_LENGTH, "%s: <MISSING>", hfinfo->name);
}
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
if (hfinfo->bitmask) {
fill_label_bitfield(fi, label_str);
} else {
fill_label_uint(fi, label_str);
}
break;
case FT_FRAMENUM:
fill_label_uint(fi, label_str);
break;
case FT_UINT64:
fill_label_uint64(fi, label_str);
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
DISSECTOR_ASSERT(!hfinfo->bitmask);
fill_label_int(fi, label_str);
break;
case FT_INT64:
fill_label_int64(fi, label_str);
break;
case FT_FLOAT:
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %." STRINGIFY(FLT_DIG) "g",
hfinfo->name, fvalue_get_floating(&fi->value));
break;
case FT_DOUBLE:
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %." STRINGIFY(DBL_DIG) "g",
hfinfo->name, fvalue_get_floating(&fi->value));
break;
case FT_ABSOLUTE_TIME:
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s", hfinfo->name,
abs_time_to_str(fvalue_get(&fi->value), hfinfo->display, TRUE));
break;
case FT_RELATIVE_TIME:
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s seconds", hfinfo->name,
rel_time_to_secs_str(fvalue_get(&fi->value)));
break;
case FT_IPXNET:
integer = fvalue_get_uinteger(&fi->value);
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s (0x%08X)", hfinfo->name,
get_ipxnet_name(integer), integer);
break;
case FT_ETHER:
bytes = fvalue_get(&fi->value);
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s (%s)", hfinfo->name,
get_ether_name(bytes),
ether_to_str(bytes));
break;
case FT_IPv4:
ipv4 = fvalue_get(&fi->value);
n_addr = ipv4_get_net_order_addr(ipv4);
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s (%s)", hfinfo->name,
get_hostname(n_addr),
ip_to_str((guint8*)&n_addr));
break;
case FT_IPv6:
bytes = fvalue_get(&fi->value);
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s (%s)", hfinfo->name,
get_hostname6((struct e_in6_addr *)bytes),
ip6_to_str((struct e_in6_addr*)bytes));
break;
case FT_GUID:
guid = fvalue_get(&fi->value);
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s", hfinfo->name,
guid_to_str(guid));
break;
case FT_OID:
bytes = fvalue_get(&fi->value);
name = oid_resolved_from_encoded(bytes, fvalue_length(&fi->value));
if (name) {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s (%s)", hfinfo->name,
oid_encoded2string(bytes, fvalue_length(&fi->value)), name);
} else {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s", hfinfo->name,
oid_encoded2string(bytes, fvalue_length(&fi->value)));
}
break;
case FT_EUI64:
integer64 = fvalue_get_integer64(&fi->value);
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s (%s)", hfinfo->name,
get_eui64_name(integer64),
eui64_to_str(integer64));
break;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
bytes = fvalue_get(&fi->value);
ret = g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s: %s", hfinfo->name,
format_text(bytes, strlen(bytes)));
if (ret >= ITEM_LABEL_LENGTH) {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
"%s [truncated]: %s", hfinfo->name,
format_text(bytes, strlen(bytes)));
}
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
guint32 unshifted_value;
guint32 value;
header_field_info *hfinfo = fi->hfinfo;
const true_false_string *tfstring = (const true_false_string *)&tfs_true_false;
if (hfinfo->strings) {
tfstring = (const struct true_false_string*) hfinfo->strings;
}
value = fvalue_get_uinteger(&fi->value);
if (hfinfo->bitmask) {
bitwidth = hfinfo_bitwidth(hfinfo);
unshifted_value = value;
if (hfinfo->bitshift > 0) {
unshifted_value <<= hfinfo->bitshift;
}
p = decode_bitfield_value(label_str, unshifted_value, hfinfo->bitmask, bitwidth);
bitfield_byte_length = (int) (p - label_str);
}
g_snprintf(p, ITEM_LABEL_LENGTH - bitfield_byte_length,
"%s: %s", hfinfo->name,
value ? tfstring->true_string : tfstring->false_string);
}
static void
fill_label_bitfield(field_info *fi, gchar *label_str)
{
const char *format = NULL;
char *p;
int bitfield_byte_length, bitwidth;
guint32 unshifted_value;
guint32 value;
header_field_info *hfinfo = fi->hfinfo;
bitwidth = hfinfo_bitwidth(hfinfo);
unshifted_value = fvalue_get_uinteger(&fi->value);
value = unshifted_value;
if (hfinfo->bitshift > 0) {
unshifted_value <<= hfinfo->bitshift;
}
p = decode_bitfield_value(label_str, unshifted_value, hfinfo->bitmask, bitwidth);
bitfield_byte_length = (int) (p - label_str);
if (hfinfo->display == BASE_CUSTOM) {
gchar tmp[ITEM_LABEL_LENGTH];
custom_fmt_func_t fmtfunc = (custom_fmt_func_t)hfinfo->strings;
DISSECTOR_ASSERT(fmtfunc);
fmtfunc(tmp, value);
g_snprintf(p, ITEM_LABEL_LENGTH - bitfield_byte_length,
"%s: %s", hfinfo->name, tmp);
}
else if (hfinfo->strings) {
format = hfinfo_uint_vals_format(hfinfo);
if (hfinfo->display & BASE_RANGE_STRING) {
g_snprintf(p, ITEM_LABEL_LENGTH - bitfield_byte_length,
format, hfinfo->name,
rval_to_str(value, hfinfo->strings, "Unknown"), value);
} else if (hfinfo->display & BASE_EXT_STRING) {
g_snprintf(p, ITEM_LABEL_LENGTH - bitfield_byte_length,
format, hfinfo->name,
val_to_str_ext_const(value, (value_string_ext *) hfinfo->strings, "Unknown"), value);
} else {
g_snprintf(p, ITEM_LABEL_LENGTH - bitfield_byte_length,
format, hfinfo->name,
val_to_str_const(value, cVALS(hfinfo->strings), "Unknown"), value);
}
}
else {
format = hfinfo_uint_format(hfinfo);
if (IS_BASE_DUAL(hfinfo->display)) {
g_snprintf(p, ITEM_LABEL_LENGTH - bitfield_byte_length,
format, hfinfo->name, value, value);
} else {
g_snprintf(p, ITEM_LABEL_LENGTH - bitfield_byte_length,
format, hfinfo->name, value);
}
}
}
static void
fill_label_uint(field_info *fi, gchar *label_str)
{
const char *format = NULL;
header_field_info *hfinfo = fi->hfinfo;
guint32 value;
value = fvalue_get_uinteger(&fi->value);
if (hfinfo->display == BASE_CUSTOM) {
gchar tmp[ITEM_LABEL_LENGTH];
custom_fmt_func_t fmtfunc = (custom_fmt_func_t)hfinfo->strings;
DISSECTOR_ASSERT(fmtfunc);
fmtfunc(tmp, value);
g_snprintf(label_str, ITEM_LABEL_LENGTH, "%s: %s", hfinfo->name, tmp);
}
else if (hfinfo->strings) {
format = hfinfo_uint_vals_format(hfinfo);
if (hfinfo->display & BASE_RANGE_STRING) {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
format, hfinfo->name,
rval_to_str(value, hfinfo->strings, "Unknown"), value);
} else if (hfinfo->display & BASE_EXT_STRING) {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
format, hfinfo->name,
val_to_str_ext_const(value, (value_string_ext *) hfinfo->strings, "Unknown"), value);
} else {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
format, hfinfo->name,
val_to_str_const(value, cVALS(hfinfo->strings), "Unknown"), value);
}
}
else {
format = hfinfo_uint_format(hfinfo);
if (IS_BASE_DUAL(hfinfo->display)) {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
format, hfinfo->name, value, value);
} else {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
format, hfinfo->name, value);
}
}
}
static void
fill_label_uint64(field_info *fi, gchar *label_str)
{
const char *format = NULL;
header_field_info *hfinfo = fi->hfinfo;
guint64 value;
format = hfinfo_uint64_format(hfinfo);
value = fvalue_get_integer64(&fi->value);
if (IS_BASE_DUAL(hfinfo->display)) {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
format, hfinfo->name, value, value);
} else {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
format, hfinfo->name, value);
}
}
static void
fill_label_int(field_info *fi, gchar *label_str)
{
const char *format = NULL;
header_field_info *hfinfo = fi->hfinfo;
guint32 value;
value = fvalue_get_sinteger(&fi->value);
if (hfinfo->display == BASE_CUSTOM) {
gchar tmp[ITEM_LABEL_LENGTH];
custom_fmt_func_t fmtfunc = (custom_fmt_func_t)hfinfo->strings;
DISSECTOR_ASSERT(fmtfunc);
fmtfunc(tmp, value);
g_snprintf(label_str, ITEM_LABEL_LENGTH, "%s: %s", hfinfo->name, tmp);
}
else if (hfinfo->strings) {
format = hfinfo_int_vals_format(hfinfo);
if (hfinfo->display & BASE_RANGE_STRING) {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
format, hfinfo->name,
rval_to_str(value, hfinfo->strings, "Unknown"), value);
} else if (hfinfo->display & BASE_EXT_STRING) {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
format, hfinfo->name,
val_to_str_ext_const(value, (value_string_ext *) hfinfo->strings, "Unknown"), value);
} else {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
format, hfinfo->name,
val_to_str_const(value, cVALS(hfinfo->strings), "Unknown"), value);
}
}
else {
format = hfinfo_int_format(hfinfo);
if (IS_BASE_DUAL(hfinfo->display)) {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
format, hfinfo->name, value, value);
} else {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
format, hfinfo->name, value);
}
}
}
static void
fill_label_int64(field_info *fi, gchar *label_str)
{
const char *format = NULL;
header_field_info *hfinfo = fi->hfinfo;
guint64 value;
format = hfinfo_int64_format(hfinfo);
value = fvalue_get_integer64(&fi->value);
if (IS_BASE_DUAL(hfinfo->display)) {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
format, hfinfo->name, value, value);
} else {
g_snprintf(label_str, ITEM_LABEL_LENGTH,
format, hfinfo->name, value);
}
}
int
hfinfo_bitwidth(const header_field_info *hfinfo)
{
int bitwidth = 0;
if (!hfinfo->bitmask) {
return 0;
}
switch (hfinfo->type) {
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
case FT_BOOLEAN:
bitwidth = hfinfo->display;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
return bitwidth;
}
static const char *
hfinfo_uint_vals_format(const header_field_info *hfinfo)
{
const char *format = NULL;
switch (hfinfo->display & BASE_DISPLAY_E_MASK) {
case BASE_NONE:
format = "%s: %s";
break;
case BASE_DEC:
case BASE_DEC_HEX:
format = "%s: %s (%u)";
break;
case BASE_OCT:
format = "%s: %s (%#o)";
break;
case BASE_HEX:
case BASE_HEX_DEC:
switch (hfinfo->type) {
case FT_UINT8:
format = "%s: %s (0x%02x)";
break;
case FT_UINT16:
format = "%s: %s (0x%04x)";
break;
case FT_UINT24:
format = "%s: %s (0x%06x)";
break;
case FT_UINT32:
format = "%s: %s (0x%08x)";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
return format;
}
static const char *
hfinfo_uint_format(const header_field_info *hfinfo)
{
const char *format = NULL;
if (hfinfo->type == FT_FRAMENUM) {
format = "%s: %u";
} else {
switch (hfinfo->display) {
case BASE_DEC:
format = "%s: %u";
break;
case BASE_DEC_HEX:
switch (hfinfo->type) {
case FT_UINT8:
format = "%s: %u (0x%02x)";
break;
case FT_UINT16:
format = "%s: %u (0x%04x)";
break;
case FT_UINT24:
format = "%s: %u (0x%06x)";
break;
case FT_UINT32:
format = "%s: %u (0x%08x)";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
case BASE_OCT:
format = "%s: %#o";
break;
case BASE_HEX:
switch (hfinfo->type) {
case FT_UINT8:
format = "%s: 0x%02x";
break;
case FT_UINT16:
format = "%s: 0x%04x";
break;
case FT_UINT24:
format = "%s: 0x%06x";
break;
case FT_UINT32:
format = "%s: 0x%08x";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
case BASE_HEX_DEC:
switch (hfinfo->type) {
case FT_UINT8:
format = "%s: 0x%02x (%u)";
break;
case FT_UINT16:
format = "%s: 0x%04x (%u)";
break;
case FT_UINT24:
format = "%s: 0x%06x (%u)";
break;
case FT_UINT32:
format = "%s: 0x%08x (%u)";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
}
return format;
}
static const char *
hfinfo_uint_value_format(const header_field_info *hfinfo)
{
const char *format = NULL;
if (hfinfo->type == FT_FRAMENUM) {
format = "%u";
} else {
switch (hfinfo->display) {
case BASE_DEC:
format = "%u";
break;
case BASE_DEC_HEX:
switch (hfinfo->type) {
case FT_UINT8:
format = "%u (0x%02x)";
break;
case FT_UINT16:
format = "%u (0x%04x)";
break;
case FT_UINT24:
format = "%u (0x%06x)";
break;
case FT_UINT32:
format = "%u (0x%08x)";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
case BASE_OCT:
format = "%#o";
break;
case BASE_HEX:
switch (hfinfo->type) {
case FT_UINT8:
format = "0x%02x";
break;
case FT_UINT16:
format = "0x%04x";
break;
case FT_UINT24:
format = "0x%06x";
break;
case FT_UINT32:
format = "0x%08x";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
case BASE_HEX_DEC:
switch (hfinfo->type) {
case FT_UINT8:
format = "0x%02x (%u)";
break;
case FT_UINT16:
format = "0x%04x (%u)";
break;
case FT_UINT24:
format = "0x%06x (%u)";
break;
case FT_UINT32:
format = "0x%08x (%u)";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
}
return format;
}
static const char *
hfinfo_int_vals_format(const header_field_info *hfinfo)
{
const char *format = NULL;
switch (hfinfo->display & BASE_DISPLAY_E_MASK) {
case BASE_NONE:
format = "%s: %s";
break;
case BASE_DEC:
case BASE_DEC_HEX:
format = "%s: %s (%d)";
break;
case BASE_OCT:
format = "%s: %s (%#o)";
break;
case BASE_HEX:
case BASE_HEX_DEC:
switch (hfinfo->type) {
case FT_INT8:
format = "%s: %s (0x%02x)";
break;
case FT_INT16:
format = "%s: %s (0x%04x)";
break;
case FT_INT24:
format = "%s: %s (0x%06x)";
break;
case FT_INT32:
format = "%s: %s (0x%08x)";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
return format;
}
static const char *
hfinfo_uint64_format(const header_field_info *hfinfo)
{
const char *format = NULL;
switch (hfinfo->display) {
case BASE_DEC:
format = "%s: %" G_GINT64_MODIFIER "u";
break;
case BASE_DEC_HEX:
format = "%s: %" G_GINT64_MODIFIER "u (0x%016" G_GINT64_MODIFIER "x)";
break;
case BASE_OCT:
format = "%s: %#" G_GINT64_MODIFIER "o";
break;
case BASE_HEX:
format = "%s: 0x%016" G_GINT64_MODIFIER "x";
break;
case BASE_HEX_DEC:
format = "%s: 0x%016" G_GINT64_MODIFIER "x (%" G_GINT64_MODIFIER "u)";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
return format;
}
static const char *
hfinfo_int_format(const header_field_info *hfinfo)
{
const char *format = NULL;
switch (hfinfo->display) {
case BASE_DEC:
format = "%s: %d";
break;
case BASE_DEC_HEX:
switch (hfinfo->type) {
case FT_INT8:
format = "%s: %d (0x%02x)";
break;
case FT_INT16:
format = "%s: %d (0x%04x)";
break;
case FT_INT24:
format = "%s: %d (0x%06x)";
break;
case FT_INT32:
format = "%s: %d (0x%08x)";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
case BASE_OCT:
format = "%s: %#o";
break;
case BASE_HEX:
switch (hfinfo->type) {
case FT_INT8:
format = "%s: 0x%02x";
break;
case FT_INT16:
format = "%s: 0x%04x";
break;
case FT_INT24:
format = "%s: 0x%06x";
break;
case FT_INT32:
format = "%s: 0x%08x";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
case BASE_HEX_DEC:
switch (hfinfo->type) {
case FT_INT8:
format = "%s: 0x%02x (%d)";
break;
case FT_INT16:
format = "%s: 0x%04x (%d)";
break;
case FT_INT24:
format = "%s: 0x%06x (%d)";
break;
case FT_INT32:
format = "%s: 0x%08x (%d)";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
return format;
}
static const char *
hfinfo_int_value_format(const header_field_info *hfinfo)
{
const char *format = NULL;
switch (hfinfo->display) {
case BASE_DEC:
format = "%d";
break;
case BASE_DEC_HEX:
switch (hfinfo->type) {
case FT_INT8:
format = "%d (0x%02x)";
break;
case FT_INT16:
format = "%d (0x%04x)";
break;
case FT_INT24:
format = "%d (0x%06x)";
break;
case FT_INT32:
format = "%d (0x%08x)";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
case BASE_OCT:
format = "%#o";
break;
case BASE_HEX:
switch (hfinfo->type) {
case FT_INT8:
format = "0x%02x";
break;
case FT_INT16:
format = "0x%04x";
break;
case FT_INT24:
format = "0x%06x";
break;
case FT_INT32:
format = "0x%08x";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
case BASE_HEX_DEC:
switch (hfinfo->type) {
case FT_INT8:
format = "0x%02x (%d)";
break;
case FT_INT16:
format = "0x%04x (%d)";
break;
case FT_INT24:
format = "0x%06x (%d)";
break;
case FT_INT32:
format = "0x%08x (%d)";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
return format;
}
static const char *
hfinfo_int64_format(const header_field_info *hfinfo)
{
const char *format = NULL;
switch (hfinfo->display) {
case BASE_DEC:
format = "%s: %" G_GINT64_MODIFIER "d";
break;
case BASE_DEC_HEX:
format = "%s: %" G_GINT64_MODIFIER "d (0x%016" G_GINT64_MODIFIER "x)";
break;
case BASE_OCT:
format = "%s: %#" G_GINT64_MODIFIER "o";
break;
case BASE_HEX:
format = "%s: 0x%016" G_GINT64_MODIFIER "x";
break;
case BASE_HEX_DEC:
format = "%s: 0x%016" G_GINT64_MODIFIER "x (%" G_GINT64_MODIFIER "d)";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
return format;
}
int
proto_registrar_n(void)
{
return gpa_hfinfo.len;
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
return (hfinfo->parent == -1 ? TRUE : FALSE);
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
if (!ptrs) {
return FALSE;
}
else if (g_ptr_array_len(ptrs) > 0) {
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
return g_hash_table_lookup(PTREE_DATA(tree)->interesting_hfids,
GINT_TO_POINTER(id));
else
return NULL;
}
gboolean
proto_tracking_interesting_fields(const proto_tree *tree)
{
if (!tree)
return FALSE;
return (PTREE_DATA(tree)->interesting_hfids != NULL);
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
check_for_offset(proto_node *node, const gpointer data)
{
field_info *fi = PNODE_FINFO(node);
offset_search_t *offsearch = data;
if (fi && !PROTO_ITEM_IS_HIDDEN(node) && fi->ds_tvb && offsearch->tvb == fi->ds_tvb) {
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
const range_string *range;
const true_false_string *tfs;
len = gpa_hfinfo.len;
for (i = 0; i < len ; i++) {
PROTO_REGISTRAR_GET_NTH(i, hfinfo);
if (hfinfo->id == hf_text_only) {
continue;
}
if (proto_registrar_is_protocol(i)) {
continue;
}
else {
if (hfinfo->same_name_prev != NULL)
continue;
vals = NULL;
range = NULL;
tfs = NULL;
if (hfinfo->strings != NULL) {
if ((hfinfo->display & BASE_DISPLAY_E_MASK) != BASE_CUSTOM &&
(hfinfo->type == FT_UINT8 ||
hfinfo->type == FT_UINT16 ||
hfinfo->type == FT_UINT24 ||
hfinfo->type == FT_UINT32 ||
hfinfo->type == FT_UINT64 ||
hfinfo->type == FT_INT8 ||
hfinfo->type == FT_INT16 ||
hfinfo->type == FT_INT24 ||
hfinfo->type == FT_INT32 ||
hfinfo->type == FT_INT64)) {
if (hfinfo->display & BASE_EXT_STRING) {
vals = VALUE_STRING_EXT_VS_P((value_string_ext *)hfinfo->strings);
} else if ((hfinfo->display & BASE_RANGE_STRING) == 0) {
vals = hfinfo->strings;
} else {
range = hfinfo->strings;
}
}
else if (hfinfo->type == FT_BOOLEAN) {
tfs = hfinfo->strings;
}
}
if (vals) {
if (hfinfo->display & BASE_EXT_STRING) {
value_string_ext *vse_p = (value_string_ext *)hfinfo->strings;
if (!value_string_ext_validate(vse_p)) {
g_warning("Invalid value_string_ext ptr for: %s", hfinfo->abbrev);
continue;
}
match_strval_ext(0, vse_p);
printf("E\t%s\t%d\t%s\t%s\n",
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
else if (range) {
vi = 0;
while (range[vi].strptr) {
if ((hfinfo->display & BASE_DISPLAY_E_MASK) == BASE_HEX) {
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
}
void
proto_registrar_dump_fields(const int format)
{
header_field_info *hfinfo, *parent_hfinfo;
int i, len;
const char *enum_name;
const char *base_name;
const char *blurb;
char width[5];
len = gpa_hfinfo.len;
for (i = 0; i < len ; i++) {
PROTO_REGISTRAR_GET_NTH(i, hfinfo);
if (hfinfo->id == hf_text_only)
continue;
if (proto_registrar_is_protocol(i)) {
printf("P\t%s\t%s\n", hfinfo->name, hfinfo->abbrev);
}
else {
if (hfinfo->same_name_prev != NULL)
continue;
PROTO_REGISTRAR_GET_NTH(hfinfo->parent, parent_hfinfo);
enum_name = ftype_name(hfinfo->type);
base_name = "";
if (format > 1) {
if (hfinfo->type == FT_UINT8 ||
hfinfo->type == FT_UINT16 ||
hfinfo->type == FT_UINT24 ||
hfinfo->type == FT_UINT32 ||
hfinfo->type == FT_UINT64 ||
hfinfo->type == FT_INT8 ||
hfinfo->type == FT_INT16 ||
hfinfo->type == FT_INT24 ||
hfinfo->type == FT_INT32 ||
hfinfo->type == FT_INT64) {
switch (hfinfo->display & BASE_DISPLAY_E_MASK) {
case BASE_NONE:
base_name = "BASE_NONE";
break;
case BASE_DEC:
base_name = "BASE_DEC";
break;
case BASE_HEX:
base_name = "BASE_HEX";
break;
case BASE_OCT:
base_name = "BASE_OCT";
break;
case BASE_DEC_HEX:
base_name = "BASE_DEC_HEX";
break;
case BASE_HEX_DEC:
base_name = "BASE_HEX_DEC";
break;
case BASE_CUSTOM:
base_name = "BASE_CUSTOM";
break;
default:
base_name = "????";
break;
}
} else if (hfinfo->type == FT_BOOLEAN) {
g_snprintf(width, sizeof(width), "%d", hfinfo->display);
base_name = width;
}
}
blurb = hfinfo->blurb;
if (blurb == NULL)
blurb = "";
else if (strlen(blurb) == 0)
blurb = "\"\"";
if (format == 1) {
printf("F\t%s\t%s\t%s\t%s\t%s\n",
hfinfo->name, hfinfo->abbrev, enum_name,
parent_hfinfo->abbrev, blurb);
}
else if (format == 2) {
printf("F\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
hfinfo->name, hfinfo->abbrev, enum_name,
parent_hfinfo->abbrev, blurb,
base_name, blurb);
}
else if (format == 3) {
printf("F\t%s\t%s\t%s\t%s\t%s\t%s\t0x%x\n",
hfinfo->name, hfinfo->abbrev, enum_name,
parent_hfinfo->abbrev, blurb,
base_name, hfinfo->bitmask);
}
else {
g_assert_not_reached();
}
}
}
}
void
proto_registrar_dump_ftypes(void)
{
ftenum_t fte;
for (fte = 0; fte < FT_NUM_TYPES; fte++) {
printf("%s\t%s\n", ftype_name(fte), ftype_pretty_name(fte));
}
}
static const char *
hfinfo_numeric_format(const header_field_info *hfinfo)
{
const char *format = NULL;
if (hfinfo->type == FT_FRAMENUM) {
format = "%s == %u";
} else {
switch (hfinfo->display & BASE_DISPLAY_E_MASK) {
case BASE_DEC:
case BASE_DEC_HEX:
case BASE_OCT:
case BASE_CUSTOM:
switch (hfinfo->type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
format = "%s == %u";
break;
case FT_UINT64:
format = "%s == %" G_GINT64_MODIFIER "u";
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
format = "%s == %d";
break;
case FT_INT64:
format = "%s == %" G_GINT64_MODIFIER "d";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
case BASE_HEX:
case BASE_HEX_DEC:
switch (hfinfo->type) {
case FT_UINT8:
case FT_INT8:
format = "%s == 0x%02x";
break;
case FT_UINT16:
case FT_INT16:
format = "%s == 0x%04x";
break;
case FT_UINT24:
case FT_INT24:
format = "%s == 0x%06x";
break;
case FT_UINT32:
case FT_INT32:
format = "%s == 0x%08x";
break;
case FT_UINT64:
case FT_INT64:
format = "%s == 0x%016" G_GINT64_MODIFIER "x";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
}
return format;
}
static const char *
hfinfo_numeric_value_format(const header_field_info *hfinfo)
{
const char *format = NULL;
if (hfinfo->type == FT_FRAMENUM) {
format = "%u";
} else {
switch (hfinfo->display & BASE_DISPLAY_E_MASK) {
case BASE_NONE:
case BASE_DEC:
case BASE_DEC_HEX:
case BASE_OCT:
case BASE_CUSTOM:
switch (hfinfo->type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
format = "%u";
break;
case FT_UINT64:
format = "%" G_GINT64_MODIFIER "u";
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
format = "%d";
break;
case FT_INT64:
format = "%" G_GINT64_MODIFIER "d";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
case BASE_HEX:
case BASE_HEX_DEC:
switch (hfinfo->type) {
case FT_UINT8:
case FT_INT8:
format = "0x%02x";
break;
case FT_UINT16:
case FT_INT16:
format = "0x%04x";
break;
case FT_UINT24:
case FT_INT24:
format = "0x%06x";
break;
case FT_UINT32:
case FT_INT32:
format = "0x%08x";
break;
case FT_UINT64:
case FT_INT64:
format = "0x%016" G_GINT64_MODIFIER "x";
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
;
}
}
return format;
}
static gboolean
construct_match_selected_string(field_info *finfo, epan_dissect_t *edt,
char **filter)
{
header_field_info *hfinfo;
int abbrev_len;
char *ptr;
int buf_len;
const char *format;
int dfilter_len, i;
gint start, length, length_remaining;
guint8 c;
gchar is_signed_num = FALSE;
hfinfo = finfo->hfinfo;
DISSECTOR_ASSERT(hfinfo);
abbrev_len = (int) strlen(hfinfo->abbrev);
if (hfinfo->strings && (hfinfo->display & BASE_DISPLAY_E_MASK) == BASE_NONE) {
const gchar *str = NULL;
switch (hfinfo->type) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
if (hfinfo->display & BASE_RANGE_STRING) {
str = match_strrval(fvalue_get_sinteger(&finfo->value), hfinfo->strings);
} else if (hfinfo->display & BASE_EXT_STRING) {
str = match_strval_ext(fvalue_get_sinteger(&finfo->value), hfinfo->strings);
} else {
str = match_strval(fvalue_get_sinteger(&finfo->value), hfinfo->strings);
}
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
if (hfinfo->display & BASE_RANGE_STRING) {
str = match_strrval(fvalue_get_uinteger(&finfo->value), hfinfo->strings);
} else if (hfinfo->display & BASE_EXT_STRING) {
str = match_strval_ext(fvalue_get_uinteger(&finfo->value), hfinfo->strings);
} else {
str = match_strval(fvalue_get_uinteger(&finfo->value), hfinfo->strings);
}
break;
default:
break;
}
if (str != NULL && filter != NULL) {
*filter = ep_strdup_printf("%s == \"%s\"", hfinfo->abbrev, str);
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
if (filter != NULL) {
format = hfinfo_numeric_format(hfinfo);
if (is_signed_num) {
*filter = ep_strdup_printf(format,
hfinfo->abbrev,
fvalue_get_sinteger(&finfo->value));
} else {
*filter = ep_strdup_printf(format,
hfinfo->abbrev,
fvalue_get_uinteger(&finfo->value));
}
}
break;
case FT_FRAMENUM:
DISSECTOR_ASSERT(!is_signed_num);
if (filter != NULL) {
format = hfinfo_numeric_format(hfinfo);
*filter = ep_strdup_printf(format,
hfinfo->abbrev,
fvalue_get_uinteger(&finfo->value));
}
break;
case FT_INT64:
case FT_UINT64:
if (filter != NULL) {
format = hfinfo_numeric_format(hfinfo);
*filter = ep_strdup_printf(format,
hfinfo->abbrev,
fvalue_get_integer64(&finfo->value));
}
break;
case FT_PROTOCOL:
if (filter != NULL)
*filter = ep_strdup(finfo->hfinfo->abbrev);
break;
case FT_NONE:
length = finfo->length;
if (length == 0) {
if (filter != NULL)
*filter = ep_strdup(finfo->hfinfo->abbrev);
break;
}
if (length < 0)
return FALSE;
if (edt == NULL)
return FALSE;
if (finfo->ds_tvb != edt->tvb)
return FALSE;
length_remaining = tvb_length_remaining(finfo->ds_tvb, finfo->start);
if (length > length_remaining)
length = length_remaining;
if (length <= 0)
return FALSE;
if (filter != NULL) {
start = finfo->start;
buf_len = 32 + length * 3;
*filter = ep_alloc0(buf_len);
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
dfilter_len = fvalue_string_repr_len(&finfo->value,
FTREPR_DFILTER);
dfilter_len += abbrev_len + 4 + 1;
*filter = ep_alloc0(dfilter_len);
g_snprintf(*filter, dfilter_len, "%s == ",
hfinfo->abbrev);
fvalue_to_string_repr(&finfo->value,
FTREPR_DFILTER,
&(*filter)[abbrev_len + 4]);
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
char *filter;
if (!construct_match_selected_string(finfo, edt, &filter))
return NULL;
return filter;
}
static gboolean
proto_item_add_bitmask_tree(proto_item *item, tvbuff_t *tvb, const int offset,
const int len, const gint ett, const int **fields,
const guint encoding, const int flags,
gboolean first)
{
guint32 value = 0;
guint32 tmpval;
proto_tree *tree = NULL;
header_field_info *hf;
const char *fmt;
switch (len) {
case 1:
value = tvb_get_guint8(tvb, offset);
break;
case 2:
value = encoding ? tvb_get_letohs(tvb, offset) :
tvb_get_ntohs(tvb, offset);
break;
case 3:
value = encoding ? tvb_get_letoh24(tvb, offset) :
tvb_get_ntoh24(tvb, offset);
break;
case 4:
value = encoding ? tvb_get_letohl(tvb, offset) :
tvb_get_ntohl(tvb, offset);
break;
default:
g_assert_not_reached();
}
tree = proto_item_add_subtree(item, ett);
while (*fields) {
proto_tree_add_item(tree, **fields, tvb, offset, len, encoding);
if (flags & BMT_NO_APPEND) {
fields++;
continue;
}
hf = proto_registrar_get_nth(**fields);
DISSECTOR_ASSERT(hf->bitmask != 0);
tmpval = (value & hf->bitmask) >> hf->bitshift;
switch (hf->type) {
case FT_INT8:
case FT_UINT8:
case FT_INT16:
case FT_UINT16:
case FT_INT24:
case FT_UINT24:
case FT_INT32:
case FT_UINT32:
DISSECTOR_ASSERT(len == ftype_length(hf->type));
if (hf->display == BASE_CUSTOM) {
gchar lbl[ITEM_LABEL_LENGTH];
custom_fmt_func_t fmtfunc = (custom_fmt_func_t)hf->strings;
DISSECTOR_ASSERT(fmtfunc);
fmtfunc(lbl, tmpval);
proto_item_append_text(item, "%s%s: %s", first ? "" : ", ",
hf->name, lbl);
first = FALSE;
}
else if (hf->strings) {
if (hf->display & BASE_RANGE_STRING) {
proto_item_append_text(item, "%s%s: %s", first ? "" : ", ",
hf->name, rval_to_str(tmpval, hf->strings, "Unknown"));
} else if (hf->display & BASE_EXT_STRING) {
proto_item_append_text(item, "%s%s: %s", first ? "" : ", ",
hf->name, val_to_str_ext_const(tmpval, (value_string_ext *) (hf->strings), "Unknown"));
} else {
proto_item_append_text(item, "%s%s: %s", first ? "" : ", ",
hf->name, val_to_str_const(tmpval, cVALS(hf->strings), "Unknown"));
}
first = FALSE;
}
else if (!(flags & BMT_NO_INT)) {
if (!first) {
proto_item_append_text(item, ", ");
}
fmt = IS_FT_INT(hf->type) ? hfinfo_int_format(hf) : hfinfo_uint_format(hf);
if (IS_BASE_DUAL(hf->display)) {
proto_item_append_text(item, fmt, hf->name, tmpval, tmpval);
} else {
proto_item_append_text(item, fmt, hf->name, tmpval);
}
first = FALSE;
}
break;
case FT_BOOLEAN:
DISSECTOR_ASSERT(len * 8 == hf->display);
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
g_assert_not_reached();
}
fields++;
}
return first;
}
proto_item *
proto_tree_add_bitmask(proto_tree *parent_tree, tvbuff_t *tvb,
const guint offset, const int hf_hdr,
const gint ett, const int **fields,
const guint encoding)
{
proto_item *item = NULL;
header_field_info *hf;
int len;
hf = proto_registrar_get_nth(hf_hdr);
DISSECTOR_ASSERT(IS_FT_INT(hf->type) || IS_FT_UINT(hf->type));
len = ftype_length(hf->type);
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_hdr, tvb, offset, len, encoding);
proto_item_add_bitmask_tree(item, tvb, offset, len, ett, fields, encoding,
BMT_NO_INT|BMT_NO_TFS, FALSE);
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
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, len, "%s", name ? name : "");
if (proto_item_add_bitmask_tree(item, tvb, offset, len, ett, fields, encoding,
flags, TRUE) && fallback) {
proto_item_append_text(item, "%s", fallback);
}
}
return item;
}
proto_item *
proto_tree_add_bits_item(proto_tree *tree, const int hf_index, tvbuff_t *tvb,
const guint bit_offset, const gint no_of_bits,
const guint encoding)
{
header_field_info *hfinfo;
TRY_TO_FAKE_THIS_ITEM(tree, hf_index, hfinfo);
return proto_tree_add_bits_ret_val(tree, hf_index, tvb, bit_offset, no_of_bits, NULL, encoding);
}
static proto_item *
_proto_tree_add_bits_ret_val(proto_tree *tree, const int hf_index, tvbuff_t *tvb,
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
PROTO_REGISTRAR_GET_NTH(hf_index, hf_field);
if (hf_field->bitmask != 0) {
REPORT_DISSECTOR_BUG(ep_strdup_printf("Incompatible use of proto_tree_add_bits_ret_val"
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
case FT_INT64:
if (value & (G_GINT64_CONSTANT(1) << (no_of_bits-1)))
value |= (G_GINT64_CONSTANT(-1) << no_of_bits);
break;
default:
break;
}
if (return_value) {
*return_value = value;
}
TRY_TO_FAKE_THIS_ITEM(tree, hf_index, hf_field);
bf_str = decode_bits_in_field(bit_offset, no_of_bits, value);
switch (hf_field->type) {
case FT_BOOLEAN:
tfstring = (const true_false_string *) &tfs_true_false;
if (hf_field->strings)
tfstring = (const true_false_string *)hf_field->strings;
return proto_tree_add_boolean_format(tree, hf_index, tvb, offset, length, (guint32)value,
"%s = %s: %s",
bf_str, hf_field->name,
(guint32)value ? tfstring->true_string : tfstring->false_string);
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
pi = proto_tree_add_uint(tree, hf_index, tvb, offset, length, (guint32)value);
fill_label_uint(PITEM_FINFO(pi), lbl_str);
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
pi = proto_tree_add_int(tree, hf_index, tvb, offset, length, (gint32)value);
fill_label_int(PITEM_FINFO(pi), lbl_str);
break;
case FT_UINT64:
pi = proto_tree_add_uint64(tree, hf_index, tvb, offset, length, value);
fill_label_uint64(PITEM_FINFO(pi), lbl_str);
break;
case FT_INT64:
pi = proto_tree_add_int64(tree, hf_index, tvb, offset, length, (gint64)value);
fill_label_int64(PITEM_FINFO(pi), lbl_str);
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
proto_tree_add_split_bits_item_ret_val(proto_tree *tree, const int hf_index, tvbuff_t *tvb,
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
char *bf_str;
char lbl_str[ITEM_LABEL_LENGTH];
guint64 value;
guint64 composite_bitmask;
guint64 composite_bitmap;
header_field_info *hf_field;
const true_false_string *tfstring;
PROTO_REGISTRAR_GET_NTH(hf_index, hf_field);
if (hf_field->bitmask != 0) {
REPORT_DISSECTOR_BUG(ep_strdup_printf(
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
case FT_INT64:
if (value & no_of_bits && (G_GINT64_CONSTANT(1) << (no_of_bits-1)))
value |= (G_GINT64_CONSTANT(-1) << no_of_bits);
break;
default:
break;
}
if (return_value) {
*return_value = value;
}
TRY_TO_FAKE_THIS_ITEM(tree, hf_index, hf_field);
bf_str = ep_alloc(256);
bf_str[0] = '\0';
octet_offset = bit_offset >> 3;
octet_length = ((mask_greatest_bit_offset + 7) >> 3);
mask_greatest_bit_offset = octet_length << 3;
if (mask_greatest_bit_offset <= 32) {
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
return proto_tree_add_boolean_format(tree, hf_index,
tvb, octet_offset, octet_length, (guint32)value,
"%s = %s: %s",
bf_str, hf_field->name,
(guint32)value ? tfstring->true_string : tfstring->false_string);
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
pi = proto_tree_add_uint(tree, hf_index, tvb, octet_offset, octet_length, (guint32)value);
fill_label_uint(PITEM_FINFO(pi), lbl_str);
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
pi = proto_tree_add_int(tree, hf_index, tvb, octet_offset, octet_length, (gint32)value);
fill_label_int(PITEM_FINFO(pi), lbl_str);
break;
case FT_UINT64:
pi = proto_tree_add_uint64(tree, hf_index, tvb, octet_offset, octet_length, value);
fill_label_uint64(PITEM_FINFO(pi), lbl_str);
break;
case FT_INT64:
pi = proto_tree_add_int64(tree, hf_index, tvb, octet_offset, octet_length, (gint64)value);
fill_label_int64(PITEM_FINFO(pi), lbl_str);
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
proto_tree_add_split_bits_crumb(proto_tree *tree, const int hf_index, tvbuff_t *tvb, const guint bit_offset,
const crumb_spec_t *crumb_spec, guint16 crumb_index)
{
header_field_info *hf_info;
PROTO_REGISTRAR_GET_NTH(hf_index, hf_info);
proto_tree_add_text(tree, tvb,
bit_offset >> 3,
((bit_offset + crumb_spec[crumb_index].crumb_bit_length - 1) >> 3) - (bit_offset >> 3) + 1,
"%s crumb %d of %s (decoded above)",
decode_bits_in_field(bit_offset, crumb_spec[crumb_index].crumb_bit_length,
tvb_get_bits(tvb,
bit_offset,
crumb_spec[crumb_index].crumb_bit_length,
ENC_BIG_ENDIAN)),
crumb_index,
hf_info->name);
}
proto_item *
proto_tree_add_bits_ret_val(proto_tree *tree, const int hf_index, tvbuff_t *tvb,
const guint bit_offset, const gint no_of_bits,
guint64 *return_value, const guint encoding)
{
proto_item *item;
if ((item = _proto_tree_add_bits_ret_val(tree, hf_index, tvb,
bit_offset, no_of_bits,
return_value, encoding))) {
FI_SET_FLAG(PNODE_FINFO(item), FI_BITS_OFFSET(bit_offset));
FI_SET_FLAG(PNODE_FINFO(item), FI_BITS_SIZE(no_of_bits));
}
return item;
}
static proto_item *
_proto_tree_add_bits_format_value(proto_tree *tree, const int hf_index,
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
TRY_TO_FAKE_THIS_ITEM(tree, hf_index, hf_field);
if (hf_field->bitmask != 0) {
REPORT_DISSECTOR_BUG(ep_strdup_printf(
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
strcat(str, " = ");
strcat(str, hf_field->name);
switch (hf_field->type) {
case FT_BOOLEAN:
return proto_tree_add_boolean_format(tree, hf_index, tvb, offset, length, *(guint32 *)value_ptr,
"%s: %s", str, value_str);
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
return proto_tree_add_uint_format(tree, hf_index, tvb, offset, length, *(guint32 *)value_ptr,
"%s: %s", str, value_str);
break;
case FT_UINT64:
return proto_tree_add_uint64_format(tree, hf_index, tvb, offset, length, *(guint64 *)value_ptr,
"%s: %s", str, value_str);
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
return proto_tree_add_int_format(tree, hf_index, tvb, offset, length, *(gint32 *)value_ptr,
"%s: %s", str, value_str);
break;
case FT_INT64:
return proto_tree_add_int64_format(tree, hf_index, tvb, offset, length, *(gint64 *)value_ptr,
"%s: %s", str, value_str);
break;
case FT_FLOAT:
return proto_tree_add_float_format(tree, hf_index, tvb, offset, length, *(float *)value_ptr,
"%s: %s", str, value_str);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
return NULL;
break;
}
}
proto_item *
proto_tree_add_bits_format_value(proto_tree *tree, const int hf_index,
tvbuff_t *tvb, const guint bit_offset,
const gint no_of_bits, void *value_ptr,
gchar *value_str)
{
proto_item *item;
if ((item = _proto_tree_add_bits_format_value(tree, hf_index,
tvb, bit_offset, no_of_bits,
value_ptr, value_str))) {
FI_SET_FLAG(PNODE_FINFO(item), FI_BITS_OFFSET(bit_offset));
FI_SET_FLAG(PNODE_FINFO(item), FI_BITS_SIZE(no_of_bits));
}
return item;
}
proto_item *
proto_tree_add_uint_bits_format_value(proto_tree *tree, const int hf_index,
tvbuff_t *tvb, const guint bit_offset,
const gint no_of_bits, guint32 value,
const char *format, ...)
{
va_list ap;
gchar *dst;
header_field_info *hf_field;
TRY_TO_FAKE_THIS_ITEM(tree, hf_index, hf_field);
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
return proto_tree_add_bits_format_value(tree, hf_index, tvb, bit_offset, no_of_bits, &value, dst);
}
proto_item *
proto_tree_add_float_bits_format_value(proto_tree *tree, const int hf_index,
tvbuff_t *tvb, const guint bit_offset,
const gint no_of_bits, float value,
const char *format, ...)
{
va_list ap;
gchar *dst;
header_field_info *hf_field;
TRY_TO_FAKE_THIS_ITEM(tree, hf_index, hf_field);
DISSECTOR_ASSERT(hf_field->type == FT_FLOAT);
CREATE_VALUE_STRING(dst, format, ap);
return proto_tree_add_bits_format_value(tree, hf_index, tvb, bit_offset, no_of_bits, &value, dst);
}
proto_item *
proto_tree_add_int_bits_format_value(proto_tree *tree, const int hf_index,
tvbuff_t *tvb, const guint bit_offset,
const gint no_of_bits, gint32 value,
const char *format, ...)
{
va_list ap;
gchar *dst;
header_field_info *hf_field;
TRY_TO_FAKE_THIS_ITEM(tree, hf_index, hf_field);
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
return proto_tree_add_bits_format_value(tree, hf_index, tvb, bit_offset, no_of_bits, &value, dst);
}
proto_item *
proto_tree_add_boolean_bits_format_value(proto_tree *tree, const int hf_index,
tvbuff_t *tvb, const guint bit_offset,
const gint no_of_bits, guint32 value,
const char *format, ...)
{
va_list ap;
gchar *dst;
header_field_info *hf_field;
TRY_TO_FAKE_THIS_ITEM(tree, hf_index, hf_field);
DISSECTOR_ASSERT(hf_field->type == FT_BOOLEAN);
CREATE_VALUE_STRING(dst, format, ap);
return proto_tree_add_bits_format_value(tree, hf_index, tvb, bit_offset, no_of_bits, &value, dst);
}
guchar
proto_check_field_name(const gchar *field_name)
{
return wrs_check_charset(fld_abbrev_chars, field_name);
}
