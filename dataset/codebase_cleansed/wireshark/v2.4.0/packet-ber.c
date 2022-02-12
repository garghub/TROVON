static void *
oid_copy_cb(void *dest, const void *orig, size_t len _U_)
{
oid_user_t *u = (oid_user_t *)dest;
const oid_user_t *o = (const oid_user_t *)orig;
u->oid = g_strdup(o->oid);
u->name = g_strdup(o->name);
u->syntax = o->syntax;
return dest;
}
static void
oid_free_cb(void *r)
{
oid_user_t *u = (oid_user_t *)r;
g_free(u->oid);
g_free(u->name);
}
static int
cmp_value_string(const void *v1, const void *v2)
{
const value_string *vs1 = (const value_string *)v1;
const value_string *vs2 = (const value_string *)v2;
return strcmp(vs1->strptr, vs2->strptr);
}
static void ber_prompt(packet_info *pinfo _U_, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Decode ASN.1 file as");
}
static gpointer ber_value(packet_info *pinfo _U_)
{
return NULL;
}
static void
decode_ber_add_to_list(gpointer key, gpointer value, gpointer user_data)
{
struct ber_decode_as_populate* populate = (struct ber_decode_as_populate*)user_data;
populate->add_to_list("ASN.1", (gchar *)key, value, populate->ui_element);
}
static void ber_populate_list(const gchar *table_name _U_, decode_as_add_to_list_func add_to_list, gpointer ui_element)
{
struct ber_decode_as_populate populate;
populate.add_to_list = add_to_list;
populate.ui_element = ui_element;
ber_decode_as_foreach(decode_ber_add_to_list, &populate);
}
static gboolean ber_decode_as_reset(const char *name _U_, gconstpointer pattern _U_)
{
ber_decode_as(NULL);
return FALSE;
}
static gboolean ber_decode_as_change(const char *name _U_, gconstpointer pattern _U_, gpointer handle _U_, gchar* list_name)
{
ber_decode_as(list_name);
return FALSE;
}
int
dissect_ber_oid_NULL_callback(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
void
register_ber_oid_dissector_handle(const char *oid, dissector_handle_t dissector, int proto _U_, const char *name)
{
dissector_add_string("ber.oid", oid, dissector);
oid_add_from_string(name, oid);
}
void
register_ber_oid_dissector(const char *oid, dissector_t dissector, int proto, const char *name)
{
dissector_handle_t dissector_handle;
dissector_handle = create_dissector_handle(dissector, proto);
dissector_add_string("ber.oid", oid, dissector_handle);
oid_add_from_string(name, oid);
}
void
register_ber_syntax_dissector(const char *syntax, int proto, dissector_t dissector)
{
dissector_handle_t dissector_handle;
dissector_handle = create_dissector_handle(dissector, proto);
dissector_add_string("ber.syntax", syntax, dissector_handle);
}
void
register_ber_oid_syntax(const char *oid, const char *name, const char *syntax)
{
if (syntax && *syntax)
g_hash_table_insert(syntax_table, (gpointer)g_strdup(oid), (gpointer)g_strdup(syntax));
if (name && *name)
register_ber_oid_name(oid, name);
}
void
register_ber_oid_name(const char *oid, const char *name)
{
oid_add_from_string(name, oid);
}
static void
ber_add_syntax_name(gpointer key, gpointer value _U_, gpointer user_data)
{
guint *i = (guint*)user_data;
if (*i < MAX_SYNTAX_NAMES) {
syntax_names[*i].value = *i;
syntax_names[*i].strptr = (const gchar*)key;
(*i)++;
}
}
static void
ber_decode_as_dt(const gchar *table_name _U_, ftenum_t selector_type _U_, gpointer key, gpointer value, gpointer user_data)
{
da_data *decode_as_data;
decode_as_data = (da_data *)user_data;
decode_as_data->func(key, value, decode_as_data->user_data);
}
void
ber_decode_as_foreach(GHFunc func, gpointer user_data)
{
da_data decode_as_data;
decode_as_data.func = func;
decode_as_data.user_data = user_data;
dissector_table_foreach("ber.syntax", ber_decode_as_dt, &decode_as_data);
}
void
ber_decode_as(const gchar *syntax)
{
if (decode_as_syntax) {
g_free(decode_as_syntax);
decode_as_syntax = NULL;
}
if (syntax)
decode_as_syntax = g_strdup(syntax);
}
static const gchar *
get_ber_oid_syntax(const char *oid)
{
return (const char *)g_hash_table_lookup(syntax_table, oid);
}
void
ber_set_filename(gchar *filename)
{
gchar *ptr;
if (ber_filename) {
g_free(ber_filename);
ber_filename = NULL;
}
if (filename) {
ber_filename = g_strdup(filename);
if ((ptr = strrchr(ber_filename, '.')) != NULL) {
ber_decode_as(get_ber_oid_syntax(ptr));
}
}
}
static void
ber_update_oids(void)
{
guint i;
for (i = 0; i < num_oid_users; i++)
register_ber_oid_syntax(oid_users[i].oid, oid_users[i].name, oid_users[i].syntax);
}
static void
ber_check_length (guint32 length, gint32 min_len, gint32 max_len, asn1_ctx_t *actx, proto_item *item, gboolean bit)
{
if ((min_len != -1) && (length < (guint32)min_len)) {
expert_add_info_format(
actx->pinfo, item, &ei_ber_size_constraint_string,
"Size constraint: %sstring too short: %d (%d .. %d)",
bit ? "bit " : "", length, min_len, max_len);
} else if ((max_len != -1) && (length > (guint32)max_len)) {
expert_add_info_format(
actx->pinfo, item, &ei_ber_size_constraint_string,
"Size constraint: %sstring too long: %d (%d .. %d)",
bit ? "bit " : "", length, min_len, max_len);
}
}
static void
ber_check_value64 (gint64 value, gint64 min_len, gint64 max_len, asn1_ctx_t *actx, proto_item *item)
{
if ((min_len != -1) && (value < min_len)) {
expert_add_info_format(
actx->pinfo, item, &ei_ber_size_constraint_value,
"Size constraint: value too small: %" G_GINT64_MODIFIER "d (%" G_GINT64_MODIFIER "d .. %" G_GINT64_MODIFIER "d)",
value, min_len, max_len);
} else if ((max_len != -1) && (value > max_len)) {
expert_add_info_format(
actx->pinfo, item, &ei_ber_size_constraint_value,
"Size constraint: value too big: %" G_GINT64_MODIFIER "d (%" G_GINT64_MODIFIER "d .. %" G_GINT64_MODIFIER "d)",
value, min_len, max_len);
}
}
static void
ber_check_value (guint32 value, gint32 min_len, gint32 max_len, asn1_ctx_t *actx, proto_item *item)
{
if ((min_len != -1) && (value < (guint32)min_len)) {
expert_add_info_format(
actx->pinfo, item, &ei_ber_size_constraint_value,
"Size constraint: value too small: %d (%d .. %d)",
value, min_len, max_len);
} else if ((max_len != -1) && (value > (guint32)max_len)) {
expert_add_info_format(
actx->pinfo, item, &ei_ber_size_constraint_value,
"Size constraint: value too big: %d (%d .. %d)",
value, min_len, max_len);
}
}
static void
ber_check_items (int cnt, gint32 min_len, gint32 max_len, asn1_ctx_t *actx, proto_item *item)
{
if ((min_len != -1) && (cnt < min_len)) {
expert_add_info_format(
actx->pinfo, item, &ei_ber_size_constraint_items,
"Size constraint: too few items: %d (%d .. %d)",
cnt, min_len, max_len);
} else if ((max_len != -1) && (cnt > max_len)) {
expert_add_info_format(
actx->pinfo, item, &ei_ber_size_constraint_items,
"Size constraint: too many items: %d (%d .. %d)",
cnt, min_len, max_len);
}
}
static tvbuff_t *
ber_tvb_new_subset_length(tvbuff_t *tvb, const gint backing_offset, const gint backing_length)
{
gint length_remaining;
length_remaining = tvb_reported_length_remaining(tvb, backing_offset);
return tvb_new_subset_length(tvb, backing_offset, (length_remaining > backing_length) ? backing_length : length_remaining);
}
int
dissect_ber_tagged_type(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id, gint8 tag_cls, gint32 tag_tag, gboolean tag_impl, ber_type_fn type)
{
gint8 tmp_cls;
gint32 tmp_tag;
guint32 tmp_len;
tvbuff_t *next_tvb = tvb;
proto_item *cause;
#ifdef DEBUG_BER
{
const char *name;
header_field_info *hfinfo;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
name = hfinfo->name;
} else {
name = "unnamed";
}
if (tvb_reported_length_remaining(tvb, offset) > 3) {
proto_tree_add_debug_text(tree, "dissect_ber_tagged_type(%s) entered implicit_tag:%d offset:%d len:%d %02x:%02x:%02x\n", name, implicit_tag, offset, tvb_reported_length_remaining(tvb, offset), tvb_get_guint8(tvb, offset), tvb_get_guint8(tvb, offset+1), tvb_get_guint8(tvb, offset+2));
} else {
proto_tree_add_debug_text(tree, "dissect_ber_tagged_type(%s) entered\n", name);
}
}
#endif
if (implicit_tag) {
offset = type(tag_impl, tvb, offset, actx, tree, hf_id);
return offset;
}
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &tmp_cls, NULL, &tmp_tag);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, &tmp_len, NULL);
if ((tmp_cls != tag_cls) || (tmp_tag != tag_tag)) {
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, tmp_len, "wrong_tag",
"Wrong tag in tagged type - expected class:%s(%d) tag:%d (%s) but found class:%s(%d) tag:%d",
val_to_str_const(tag_cls, ber_class_codes, "Unknown"),
tag_cls,
tag_tag,
val_to_str_ext_const(tag_tag, &ber_uni_tag_codes_ext, "Unknown"),
val_to_str_const(tmp_cls, ber_class_codes, "Unknown"),
tmp_cls,
tmp_tag);
expert_add_info(actx->pinfo, cause, &ei_ber_wrong_tag_in_tagged_type);
}
if (tag_impl) {
next_tvb = ber_tvb_new_subset_length(tvb, offset, tmp_len);
type(tag_impl, next_tvb, 0, actx, tree, hf_id);
offset += tmp_len;
} else {
offset = type(tag_impl, tvb, offset, actx, tree, hf_id);
}
return offset;
}
static proto_item *
ber_add_bad_length_error(packet_info *pinfo, proto_tree *tree,
const char *name, tvbuff_t *tvb, const gint start,
gint length)
{
proto_item *ti;
ti = proto_tree_add_string_format(
tree, hf_ber_error, tvb, start, length, "illegal_length",
"%s: length of item (%d) is not valid",
name, length);
expert_add_info_format(
pinfo, ti, &ei_ber_error_length,
"Length of item (%d) is not valid", length);
return ti;
}
static proto_item *
ber_proto_tree_add_item(packet_info *pinfo, proto_tree *tree,
const int hfindex, tvbuff_t *tvb, const gint start,
gint length, const guint encoding)
{
header_field_info *hfinfo;
hfinfo = proto_registrar_get_nth((guint)hfindex);
if (hfinfo != NULL) {
switch (hfinfo->type) {
case FT_BOOLEAN:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
if ((length != 1) && (length != 2) && (length != 3) &&
(length != 4))
return ber_add_bad_length_error(pinfo, tree,
hfinfo->name, tvb, start, length);
break;
case FT_IPv4:
if (length != FT_IPv4_LEN)
return ber_add_bad_length_error(pinfo, tree,
hfinfo->name, tvb, start, length);
break;
case FT_IPXNET:
if (length != FT_IPXNET_LEN)
return ber_add_bad_length_error(pinfo, tree,
hfinfo->name, tvb, start, length);
break;
case FT_IPv6:
if ((length < 0) || (length > FT_IPv6_LEN))
return ber_add_bad_length_error(pinfo, tree,
hfinfo->name, tvb, start, length);
break;
case FT_ETHER:
if (length != FT_ETHER_LEN)
return ber_add_bad_length_error(pinfo, tree,
hfinfo->name, tvb, start, length);
break;
case FT_GUID:
if (length != FT_GUID_LEN)
return ber_add_bad_length_error(pinfo, tree,
hfinfo->name, tvb, start, length);
break;
case FT_FLOAT:
if (length != 4)
return ber_add_bad_length_error(pinfo, tree,
hfinfo->name, tvb, start, length);
break;
case FT_DOUBLE:
if (length != 8)
return ber_add_bad_length_error(pinfo, tree,
hfinfo->name, tvb, start, length);
break;
case FT_ABSOLUTE_TIME:
case FT_RELATIVE_TIME:
if ((length != 4) && (length != 8))
return ber_add_bad_length_error(pinfo, tree,
hfinfo->name, tvb, start, length);
break;
default:
break;
}
}
return proto_tree_add_item(tree, hfindex, tvb, start, length, encoding);
}
static int
try_dissect_unknown_ber(packet_info *pinfo, tvbuff_t *tvb, volatile int offset, proto_tree *tree, gint nest_level)
{
int start_offset;
gint8 ber_class;
gboolean pc, ind;
gint32 tag;
guint32 len;
int hdr_len;
proto_item *item = NULL;
proto_tree *next_tree = NULL;
guint8 c;
guint32 i;
gboolean is_printable;
volatile gboolean is_decoded_as;
proto_item *pi, *cause;
asn1_ctx_t asn1_ctx;
if (nest_level > BER_MAX_NESTING) {
THROW(ReportedBoundsError);
}
start_offset = offset;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = get_ber_identifier(tvb, offset, &ber_class, &pc, &tag);
offset = get_ber_length(tvb, offset, &len, &ind);
if (len > (guint32)tvb_reported_length_remaining(tvb, offset)) {
if (show_internal_ber_fields) {
offset = dissect_ber_identifier(pinfo, tree, tvb, start_offset, &ber_class, &pc, &tag);
offset = dissect_ber_length(pinfo, tree, tvb, offset, &len, NULL);
}
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "illegal_length",
"length:%u longer than tvb_reported_length_remaining:%d",
len,
tvb_reported_length_remaining(tvb, offset));
expert_add_info(pinfo, cause, &ei_ber_error_length);
return tvb_reported_length(tvb);
}
switch (pc) {
case FALSE:
switch (ber_class) {
case BER_CLASS_UNI:
switch (tag) {
case BER_UNI_TAG_EOC:
break;
case BER_UNI_TAG_INTEGER:
offset = dissect_ber_integer(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_INTEGER, NULL);
break;
case BER_UNI_TAG_REAL:
offset = dissect_ber_real(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_REAL, NULL);
break;
case BER_UNI_TAG_BITSTRING:
offset = dissect_ber_bitstring(FALSE, &asn1_ctx, tree, tvb, start_offset, NULL, hf_ber_unknown_BITSTRING, -1, NULL);
break;
case BER_UNI_TAG_ENUMERATED:
offset = dissect_ber_integer(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_ENUMERATED, NULL);
break;
case BER_UNI_TAG_GraphicString:
offset = dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_GraphicString, NULL);
break;
case BER_UNI_TAG_OCTETSTRING:
is_decoded_as = FALSE;
if (decode_octetstring_as_ber && (len >= 2)) {
volatile int ber_offset = 0;
guint32 ber_len = 0;
TRY {
ber_offset = get_ber_identifier(tvb, offset, NULL, &pc, NULL);
ber_offset = get_ber_length(tvb, ber_offset, &ber_len, NULL);
} CATCH_ALL {
}
ENDTRY;
if (pc && (ber_len > 0) && (ber_len + (ber_offset - offset) == len)) {
is_decoded_as = TRUE;
if (show_internal_ber_fields) {
offset = dissect_ber_identifier(pinfo, tree, tvb, start_offset, NULL, NULL, NULL);
offset = dissect_ber_length(pinfo, tree, tvb, offset, NULL, NULL);
}
item = ber_proto_tree_add_item(pinfo, tree, hf_ber_unknown_BER_OCTETSTRING, tvb, offset, len, ENC_NA);
next_tree = proto_item_add_subtree(item, ett_ber_octet_string);
offset = try_dissect_unknown_ber(pinfo, tvb, offset, next_tree, nest_level+1);
}
}
if (!is_decoded_as) {
offset = dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_OCTETSTRING, NULL);
}
break;
case BER_UNI_TAG_OID:
offset = dissect_ber_object_identifier_str(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_OID, NULL);
break;
case BER_UNI_TAG_RELATIVE_OID:
offset = dissect_ber_relative_oid_str(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_relative_OID, NULL);
break;
case BER_UNI_TAG_NumericString:
offset = dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_NumericString, NULL);
break;
case BER_UNI_TAG_PrintableString:
offset = dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_PrintableString, NULL);
break;
case BER_UNI_TAG_TeletexString:
offset = dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_TeletexString, NULL);
break;
case BER_UNI_TAG_VisibleString:
offset = dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_VisibleString, NULL);
break;
case BER_UNI_TAG_GeneralString:
offset = dissect_ber_GeneralString(&asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_GeneralString, NULL, 0);
break;
case BER_UNI_TAG_BMPString:
offset = dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_BMPString, NULL);
break;
case BER_UNI_TAG_UniversalString:
offset = dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_UniversalString, NULL);
break;
case BER_UNI_TAG_IA5String:
offset = dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_IA5String, NULL);
break;
case BER_UNI_TAG_UTCTime:
offset = dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_UTCTime, NULL);
break;
case BER_UNI_TAG_NULL:
proto_tree_add_item(tree, hf_ber_null_tag, tvb, offset, len, ENC_NA);
break;
case BER_UNI_TAG_UTF8String:
offset = dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_UTF8String, NULL);
break;
case BER_UNI_TAG_GeneralizedTime:
offset = dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_GeneralizedTime, NULL);
break;
case BER_UNI_TAG_BOOLEAN:
offset = dissect_ber_boolean(FALSE, &asn1_ctx, tree, tvb, start_offset, hf_ber_unknown_BOOLEAN, NULL);
break;
default:
offset = dissect_ber_identifier(pinfo, tree, tvb, start_offset, &ber_class, &pc, &tag);
offset = dissect_ber_length(pinfo, tree, tvb, offset, &len, NULL);
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "unknown_universal_tag",
"can not handle universal tag:%d",
tag);
expert_add_info(pinfo, cause, &ei_ber_universal_tag_unknown);
offset += len;
}
break;
case BER_CLASS_APP:
case BER_CLASS_CON:
case BER_CLASS_PRI:
default:
if (show_internal_ber_fields) {
offset = dissect_ber_identifier(pinfo, tree, tvb, start_offset, &ber_class, &pc, &tag);
offset = dissect_ber_length(pinfo, tree, tvb, offset, &len, NULL);
}
pi = proto_tree_add_none_format(tree, hf_ber_unknown_BER_primitive, tvb, offset, len,
"[%s %d] ", val_to_str_const(ber_class, ber_class_codes, "Unknown"), tag);
is_decoded_as = FALSE;
if (decode_primitive_as_ber && (len >= 2)) {
volatile int ber_offset = 0;
guint32 ber_len = 0;
TRY {
ber_offset = get_ber_identifier(tvb, offset, NULL, &pc, NULL);
ber_offset = get_ber_length(tvb, ber_offset, &ber_len, NULL);
} CATCH_ALL {
}
ENDTRY;
if (pc && (ber_len > 0) && (ber_len + (ber_offset - offset) == len)) {
is_decoded_as = TRUE;
proto_item_append_text (pi, "[BER encoded]");
next_tree = proto_item_add_subtree(pi, ett_ber_primitive);
offset = try_dissect_unknown_ber(pinfo, tvb, offset, next_tree, nest_level+1);
}
}
if (!is_decoded_as && len) {
is_printable = TRUE;
for (i=0; i<len; i++) {
c = tvb_get_guint8(tvb, offset+i);
if (is_printable && !g_ascii_isprint(c))
is_printable = FALSE;
proto_item_append_text(pi, "%02x", c);
}
if (is_printable) {
proto_item_append_text(pi, " (");
for (i=0; i<len; i++) {
proto_item_append_text(pi, "%c", tvb_get_guint8(tvb, offset+i));
}
proto_item_append_text(pi, ")");
}
offset += len;
}
break;
}
break;
case TRUE:
if (show_internal_ber_fields) {
offset = dissect_ber_identifier(pinfo, tree, tvb, start_offset, &ber_class, &pc, &tag);
offset = dissect_ber_length(pinfo, tree, tvb, offset, &len, NULL);
}
hdr_len = offset-start_offset;
switch (ber_class) {
case BER_CLASS_UNI:
next_tree = proto_tree_add_subtree(tree, tvb, offset, len, ett_ber_SEQUENCE, NULL,
val_to_str_ext_const(tag, &ber_uni_tag_codes_ext, "Unknown"));
while (offset < (int)(start_offset + len + hdr_len))
offset = try_dissect_unknown_ber(pinfo, tvb, offset, next_tree, nest_level+1);
break;
case BER_CLASS_APP:
case BER_CLASS_CON:
case BER_CLASS_PRI:
default:
next_tree = proto_tree_add_subtree_format(tree, tvb, offset, len, ett_ber_SEQUENCE, NULL,
"[%s %d]", val_to_str_const(ber_class, ber_class_codes, "Unknown"), tag);
while (offset < (int)(start_offset + len + hdr_len))
offset = try_dissect_unknown_ber(pinfo, tvb, offset, next_tree, nest_level+1);
break;
}
break;
}
return offset;
}
int
dissect_unknown_ber(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree)
{
return try_dissect_unknown_ber(pinfo, tvb, offset, tree, 1);
}
int
call_ber_oid_callback(const char *oid, tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data)
{
tvbuff_t *next_tvb;
const char *syntax = NULL;
int len = 0;
if (!tvb) {
return offset;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (oid == NULL ||
((((syntax = get_ber_oid_syntax(oid)) == NULL) ||
(len = dissector_try_string(ber_syntax_dissector_table, syntax, next_tvb, pinfo, tree, data)) == 0) &&
(len = dissector_try_string(ber_oid_dissector_table, oid, next_tvb, pinfo, tree, data)) == 0))
{
proto_item *item = NULL;
proto_tree *next_tree = NULL;
gint length_remaining;
length_remaining = tvb_reported_length_remaining(tvb, offset);
if (oid == NULL) {
item = proto_tree_add_expert(tree, pinfo, &ei_ber_no_oid, next_tvb, 0, length_remaining);
} else if (tvb_get_ntohs (tvb, offset) != 0x0500) {
if (syntax) {
item = proto_tree_add_expert_format(
tree, pinfo, &ei_ber_syntax_not_implemented, next_tvb, 0, length_remaining,
"BER: Dissector for syntax:%s not implemented."
" Contact Wireshark developers if you want this supported",
syntax);
} else {
item = proto_tree_add_expert(tree, pinfo, &ei_ber_oid_not_implemented, next_tvb, 0, length_remaining);
}
} else {
next_tree = tree;
}
if (decode_unexpected) {
int ber_offset;
gint32 ber_len;
if (item) {
next_tree = proto_item_add_subtree(item, ett_ber_unknown);
}
ber_offset = get_ber_identifier(next_tvb, 0, NULL, NULL, NULL);
ber_offset = get_ber_length(next_tvb, ber_offset, &ber_len, NULL);
if ((ber_len + ber_offset) == length_remaining) {
dissect_unknown_ber(pinfo, next_tvb, 0, next_tree);
} else {
proto_tree_add_item(next_tree, hf_ber_unknown_data, next_tvb, 0, length_remaining, ENC_NA);
}
}
len = length_remaining;
}
offset += len;
return offset;
}
static int
call_ber_syntax_callback(const char *syntax, tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
int len = 0;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (syntax == NULL ||
(len = dissector_try_string(ber_syntax_dissector_table, syntax, next_tvb, pinfo, tree, NULL)) == 0)
{
proto_item *item = NULL;
if (syntax == NULL) {
item = proto_tree_add_expert_format(
tree, pinfo, &ei_ber_no_oid, next_tvb, 0, tvb_reported_length_remaining(tvb, offset),
"BER: No syntax supplied to call_ber_syntax_callback");
} else {
item = proto_tree_add_expert_format(
tree, pinfo, &ei_ber_syntax_not_implemented, next_tvb, 0, tvb_reported_length_remaining(tvb, offset),
"BER: Dissector for syntax:%s not implemented."
" Contact Wireshark developers if you want this supported",
syntax);
}
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(item, ett_ber_unknown);
dissect_unknown_ber(pinfo, next_tvb, 0, unknown_tree);
}
len = tvb_reported_length_remaining(tvb, offset);
}
offset += len;
return offset;
}
int
get_ber_identifier(tvbuff_t *tvb, int offset, gint8 *ber_class, gboolean *pc, gint32 *tag) {
guint8 id, t;
gint8 tmp_class;
gboolean tmp_pc;
gint32 tmp_tag;
id = tvb_get_guint8(tvb, offset);
offset += 1;
#ifdef DEBUG_BER
ws_debug_printf("BER ID=%02x", id);
#endif
tmp_class = (id >> 6) & 0x03;
tmp_pc = (id >> 5) & 0x01;
tmp_tag = id & 0x1F;
if (tmp_tag == 0x1F) {
tmp_tag = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
t = tvb_get_guint8(tvb, offset);
#ifdef DEBUG_BER
ws_debug_printf(" %02x", t);
#endif
offset += 1;
tmp_tag <<= 7;
tmp_tag |= t & 0x7F;
if (!(t & 0x80))
break;
}
}
#ifdef DEBUG_BER
ws_debug_printf("\n");
#endif
if (ber_class)
*ber_class = tmp_class;
if (pc)
*pc = tmp_pc;
if (tag)
*tag = tmp_tag;
last_class = tmp_class;
last_pc = tmp_pc;
last_tag = tmp_tag;
return offset;
}
static void
get_last_ber_identifier(gint8 *ber_class, gboolean *pc, gint32 *tag)
{
if (ber_class)
*ber_class = last_class;
if (pc)
*pc = last_pc;
if (tag)
*tag = last_tag;
}
int
dissect_ber_identifier(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gint8 *ber_class, gboolean *pc, gint32 *tag)
{
int old_offset = offset;
gint8 tmp_class;
gboolean tmp_pc;
gint32 tmp_tag;
offset = get_ber_identifier(tvb, offset, &tmp_class, &tmp_pc, &tmp_tag);
if (show_internal_ber_fields) {
proto_tree_add_uint(tree, hf_ber_id_class, tvb, old_offset, 1, tmp_class << 6);
proto_tree_add_boolean(tree, hf_ber_id_pc, tvb, old_offset, 1, (tmp_pc) ? 0x20 : 0x00);
if (tmp_tag > 0x1F) {
if (tmp_class == BER_CLASS_UNI) {
proto_tree_add_uint(tree, hf_ber_id_uni_tag_ext, tvb, old_offset + 1, offset - (old_offset + 1), tmp_tag);
} else {
proto_tree_add_uint(tree, hf_ber_id_tag_ext, tvb, old_offset + 1, offset - (old_offset + 1), tmp_tag);
}
} else {
if (tmp_class == BER_CLASS_UNI) {
proto_tree_add_uint(tree, hf_ber_id_uni_tag, tvb, old_offset, 1, tmp_tag);
} else {
proto_tree_add_uint(tree, hf_ber_id_tag, tvb, old_offset, 1, tmp_tag);
}
}
}
if (ber_class)
*ber_class = tmp_class;
if (pc)
*pc = tmp_pc;
if (tag)
*tag = tmp_tag;
return offset;
}
static int
try_get_ber_length(tvbuff_t *tvb, int offset, guint32 *length, gboolean *ind, gint nest_level) {
guint8 oct, len;
guint32 indef_len;
guint32 tmp_length;
gboolean tmp_ind;
int tmp_offset, s_offset;
gint8 tclass;
gboolean tpc;
gint32 ttag;
tmp_length = 0;
tmp_ind = FALSE;
if (nest_level > BER_MAX_NESTING) {
THROW(ReportedBoundsError);
}
oct = tvb_get_guint8(tvb, offset);
offset += 1;
if (!(oct & 0x80)) {
tmp_length = oct;
} else {
len = oct & 0x7F;
if (len) {
while (len--) {
oct = tvb_get_guint8(tvb, offset);
offset++;
tmp_length = (tmp_length<<8) + oct;
}
} else {
tmp_offset = offset;
while (tvb_get_guint8(tvb, offset) || tvb_get_guint8(tvb, offset+1)) {
s_offset = offset;
offset= get_ber_identifier(tvb, offset, &tclass, &tpc, &ttag);
offset= try_get_ber_length(tvb, offset, &indef_len, NULL, nest_level+1);
tmp_length += indef_len+(offset-s_offset);
offset += indef_len;
if (offset <= s_offset)
THROW(ReportedBoundsError);
}
tmp_length += 2;
tmp_ind = TRUE;
offset = tmp_offset;
}
}
if (length)
*length = tmp_length;
if (ind)
*ind = tmp_ind;
#ifdef DEBUG_BER
ws_debug_printf("get BER length %d, offset %d (remaining %d)\n", tmp_length, offset, tvb_reported_length_remaining(tvb, offset));
#endif
return offset;
}
int
get_ber_length(tvbuff_t *tvb, int offset, guint32 *length, gboolean *ind)
{
return try_get_ber_length(tvb, offset, length, ind, 1);
}
static void
get_last_ber_length(guint32 *length, gboolean *ind)
{
if (length)
*length = last_length;
if (ind)
*ind = last_ind;
}
int
dissect_ber_length(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, guint32 *length, gboolean *ind)
{
int old_offset = offset;
guint32 tmp_length;
gboolean tmp_ind;
offset = get_ber_length(tvb, offset, &tmp_length, &tmp_ind);
if (show_internal_ber_fields) {
if (tmp_ind) {
proto_tree_add_uint_format_value(tree, hf_ber_length, tvb, old_offset, 1, tmp_length, "Indefinite length %d", tmp_length);
} else {
proto_tree_add_uint(tree, hf_ber_length, tvb, old_offset, offset - old_offset, tmp_length);
}
}
if (length)
*length = tmp_length;
if (ind)
*ind = tmp_ind;
#ifdef DEBUG_BER
proto_tree_add_debug_text("dissect BER length %d, offset %d (remaining %d)\n", tmp_length, offset, tvb_reported_length_remaining(tvb, offset));
#endif
last_length = tmp_length;
last_ind = tmp_ind;
return offset;
}
static int
reassemble_octet_string(asn1_ctx_t *actx, proto_tree *tree, gint hf_id, tvbuff_t *tvb, int offset, guint32 con_len, gboolean ind, tvbuff_t **out_tvb, guint nest_level)
{
fragment_head *fd_head = NULL;
tvbuff_t *next_tvb = NULL;
tvbuff_t *reassembled_tvb = NULL;
guint16 dst_ref = 0;
int start_offset = offset;
gboolean fragment = TRUE;
gboolean firstFragment = TRUE;
if (nest_level > BER_MAX_NESTING) {
THROW(ReportedBoundsError);
}
if (out_tvb)
*out_tvb = NULL;
if (con_len == 0)
return offset;
actx->pinfo->fragmented = TRUE;
while(!fd_head) {
offset = dissect_ber_constrained_octet_string_impl(FALSE, actx, NULL,
tvb, offset, NO_BOUND, NO_BOUND, hf_id, &next_tvb, nest_level + 1);
if (next_tvb == NULL) {
THROW(ReportedBoundsError);
}
if (ind) {
if ((tvb_get_guint8(tvb, offset) == 0) && (tvb_get_guint8(tvb, offset+1) == 0)) {
fragment = FALSE;
offset +=2;
}
} else {
if ((guint32)(offset - start_offset) >= con_len)
fragment = FALSE;
}
if (!fragment && firstFragment) {
gboolean pc;
get_ber_identifier(tvb, start_offset, NULL, &pc, NULL);
if (!pc && tree) {
dissect_ber_octet_string(FALSE, actx, tree, tvb, start_offset, hf_id, NULL);
}
reassembled_tvb = next_tvb;
break;
}
if (tvb_reported_length(next_tvb) < 1) {
THROW(ReportedBoundsError);
}
fd_head = fragment_add_seq_next(&octet_segment_reassembly_table,
next_tvb, 0, actx->pinfo, dst_ref, NULL,
tvb_reported_length(next_tvb),
fragment);
firstFragment = FALSE;
}
if (fd_head) {
if (fd_head->next) {
proto_tree *next_tree;
proto_item *frag_tree_item;
reassembled_tvb = tvb_new_chain(next_tvb, fd_head->tvb_data);
actx->created_item = proto_tree_add_item(tree, hf_id, reassembled_tvb, 0, -1, ENC_BIG_ENDIAN);
next_tree = proto_item_add_subtree (actx->created_item, ett_ber_reassembled_octet_string);
add_new_data_source(actx->pinfo, reassembled_tvb, "Reassembled OCTET STRING");
show_fragment_seq_tree(fd_head, &octet_string_frag_items, next_tree, actx->pinfo, reassembled_tvb, &frag_tree_item);
}
}
if (out_tvb)
*out_tvb = reassembled_tvb;
actx->pinfo->fragmented = FALSE;
return offset;
}
int
dissect_ber_constrained_octet_string(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint32 min_len, gint32 max_len, gint hf_id, tvbuff_t **out_tvb) {
return dissect_ber_constrained_octet_string_impl(implicit_tag, actx, tree, tvb, offset, min_len, max_len, hf_id, out_tvb, 0);
}
static int
dissect_ber_constrained_octet_string_impl(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint32 min_len, gint32 max_len, gint hf_id, tvbuff_t **out_tvb, guint nest_level) {
gint8 ber_class;
gboolean pc, ind;
gint32 tag;
guint32 len;
guint encoding;
int hoffset;
int end_offset;
proto_item *it, *cause;
guint32 len_remain;
#ifdef DEBUG_BER
{
const char *name;
header_field_info *hfinfo;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
name = hfinfo->name;
} else {
name = "unnamed";
}
if (tvb_reported_length_remaining(tvb, offset) > 3) {
proto_tree_add_debug_text(tree, "OCTET STRING dissect_ber_octet string(%s) entered implicit_tag:%d offset:%d len:%d %02x:%02x:%02x\n", name, implicit_tag, offset, tvb_reported_length_remaining(tvb, offset), tvb_get_guint8(tvb, offset), tvb_get_guint8(tvb, offset+1), tvb_get_guint8(tvb, offset+2));
} else {
proto_tree_add_debug_text(tree, "OCTET STRING dissect_ber_octet_string(%s) entered\n", name);
}
}
#endif
if (out_tvb)
*out_tvb = NULL;
if (!implicit_tag) {
hoffset = offset;
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, &ind);
end_offset = offset+len;
if ((ber_class != BER_CLASS_APP) && (ber_class != BER_CLASS_PRI)) {
if ( (ber_class != BER_CLASS_UNI)
|| ((tag < BER_UNI_TAG_NumericString) && (tag != BER_UNI_TAG_OCTETSTRING) && (tag != BER_UNI_TAG_UTF8String)) ) {
tvb_ensure_bytes_exist(tvb, hoffset, 2);
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "octetstring_expected",
"OctetString expected but class:%s(%d) %s tag:%d was unexpected",
val_to_str_const(ber_class, ber_class_codes, "Unknown"),
ber_class,
pc ? ber_pc_codes_short.true_string : ber_pc_codes_short.false_string,
tag);
expert_add_info(actx->pinfo, cause, &ei_ber_expected_octet_string);
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(cause, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, hoffset, unknown_tree);
}
return end_offset;
}
}
} else {
get_last_ber_identifier(&ber_class, &pc, &tag);
get_last_ber_length(&len, &ind);
end_offset = offset+len;
len_remain = (guint32)tvb_reported_length_remaining(tvb, offset);
if (ind && (len_remain == (len - 2))) {
len -= 2;
end_offset -= 2;
ind = FALSE;
} else if (len_remain < len) {
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "illegal_length",
"length:%u longer than tvb_reported_length_remaining:%d",
len,
len_remain);
expert_add_info(actx->pinfo, cause, &ei_ber_error_length);
return end_offset;
}
}
actx->created_item = NULL;
if (pc) {
end_offset = reassemble_octet_string(actx, tree, hf_id, tvb, offset, len, ind, out_tvb, nest_level);
} else {
gint length_remaining;
length_remaining = tvb_reported_length_remaining(tvb, offset);
#if 0
if (length_remaining < 1) {
return end_offset;
}
#endif
if (len <= (guint32)length_remaining) {
length_remaining = len;
}
if (hf_id >= 0) {
switch (tag) {
case BER_UNI_TAG_UTF8String:
encoding = ENC_UTF_8|ENC_NA;
break;
case BER_UNI_TAG_NumericString:
case BER_UNI_TAG_PrintableString:
case BER_UNI_TAG_VisibleString:
case BER_UNI_TAG_IA5String:
encoding = ENC_ASCII|ENC_NA;
break;
case BER_UNI_TAG_TeletexString:
encoding = ENC_T61|ENC_NA;
break;
case BER_UNI_TAG_VideotexString:
encoding = ENC_T61|ENC_NA;
break;
case BER_UNI_TAG_GraphicString:
case BER_UNI_TAG_GeneralString:
encoding = ENC_ASCII|ENC_NA;
break;
case BER_UNI_TAG_UniversalString:
encoding = ENC_UCS_4|ENC_BIG_ENDIAN;
break;
case BER_UNI_TAG_CHARACTERSTRING:
encoding = ENC_ASCII|ENC_NA;
break;
case BER_UNI_TAG_BMPString:
encoding = ENC_UCS_2|ENC_BIG_ENDIAN;
break;
default:
encoding = ENC_BIG_ENDIAN;
break;
}
it = ber_proto_tree_add_item(actx->pinfo, tree, hf_id, tvb, offset, length_remaining, encoding);
actx->created_item = it;
ber_check_length(length_remaining, min_len, max_len, actx, it, FALSE);
} else {
proto_tree_add_item(tree, hf_ber_unknown_octetstring, tvb, offset, len, ENC_NA);
}
if (out_tvb) {
*out_tvb = ber_tvb_new_subset_length(tvb, offset, len);
}
}
return end_offset;
}
int
dissect_ber_octet_string(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id, tvbuff_t **out_tvb) {
return dissect_ber_constrained_octet_string(implicit_tag, actx, tree, tvb, offset, NO_BOUND, NO_BOUND, hf_id, out_tvb);
}
int
dissect_ber_octet_string_wcb(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id, ber_callback func)
{
tvbuff_t *out_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_id, (func) ? &out_tvb : NULL);
if (func && out_tvb && (tvb_reported_length(out_tvb) > 0)) {
if (hf_id >= 0)
tree = proto_item_add_subtree(actx->created_item, ett_ber_octet_string);
func(FALSE, out_tvb, 0, actx, tree, -1);
}
return offset;
}
int
dissect_ber_null(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id) {
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
int offset_old;
proto_item* cause;
if (!implicit_tag) {
offset_old = offset;
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
if (pc ||
(!implicit_tag && ((ber_class != BER_CLASS_UNI) || (tag != BER_UNI_TAG_NULL)))) {
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset_old, offset - offset_old, "null_expected",
"NULL expected but class:%s(%d) %s tag:%d was unexpected",
val_to_str_const(ber_class, ber_class_codes, "Unknown"),
ber_class,
pc ? ber_pc_codes_short.true_string : ber_pc_codes_short.false_string,
tag);
expert_add_info(actx->pinfo, cause, &ei_ber_expected_null);
}
offset_old = offset;
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, NULL);
if (len) {
proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset_old, offset - offset_old, "illegal_length",
"NULL expect zero length but Length=%d",
len);
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "unexpected_data",
"unexpected data in NULL type");
expert_add_info(actx->pinfo, cause, &ei_ber_expected_null_zero_length);
offset += len;
}
}
if (hf_id >= 0)
proto_tree_add_item(tree, hf_id, tvb, offset, 0, ENC_BIG_ENDIAN);
return offset;
}
int
dissect_ber_integer64(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id, gint64 *value)
{
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
gint64 val;
guint32 i;
gboolean used_too_many_bytes = FALSE;
guint8 first;
#ifdef DEBUG_BER
{
const char *name;
header_field_info *hfinfo;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
name = hfinfo->name;
} else {
name = "unnamed";
}
if (tvb_reported_length_remaining(tvb, offset) > 3) {
proto_tree_add_debug_text(tree, "INTEGERnew dissect_ber_integer(%s) entered implicit_tag:%d offset:%d len:%d %02x:%02x:%02x\n", name, implicit_tag, offset, tvb_reported_length_remaining(tvb, offset), tvb_get_guint8(tvb, offset), tvb_get_guint8(tvb, offset+1), tvb_get_guint8(tvb, offset+2));
} else {
proto_tree_add_debug_text(tree, "INTEGERnew dissect_ber_integer(%s) entered implicit_tag:%d \n", name, implicit_tag);
}
}
#endif
if (value) {
*value = 0;
}
if (!implicit_tag) {
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, NULL);
} else {
gint32 remaining = tvb_reported_length_remaining(tvb, offset);
len = remaining>0 ? remaining : 0;
}
first = tvb_get_guint8(tvb, offset);
if ((len > 9) || ((len == 9) && (first != 0))) {
if (hf_id >= 0) {
header_field_info *hfinfo = proto_registrar_get_nth(hf_id);
if (hfinfo->type != FT_BYTES)
hf_id = hf_ber_64bit_uint_as_bytes;
proto_tree_add_bytes_format(tree, hf_id, tvb, offset, len, NULL,
"%s: 0x%s", hfinfo->name, tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, len));
}
offset += len;
return offset;
}
val=0;
if (len > 0) {
enum ftenum type = FT_INT32;
if (hf_id >= 0) {
type = proto_registrar_get_ftype(hf_id);
}
if (first & 0x80 && IS_FT_INT(type)) {
val = -1;
}
if ((len > 1) && decode_warning_leading_zero_bits) {
guint8 second = tvb_get_guint8(tvb, offset+1);
if (((first == 0x00) && ((second & 0x80) == 0)) ||
((first == 0xff) && ((second & 0x80) != 0))) {
used_too_many_bytes = TRUE;
}
}
for (i=0; i<len; i++) {
val = ((guint64)val<<8) | tvb_get_guint8(tvb, offset);
offset++;
}
}
actx->created_item = NULL;
if (hf_id >= 0) {
if ((len < 1) || (len > 9) || ((len == 9) && (first != 0))) {
proto_item *pi = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset-len, len, "invalid length",
"Can't handle integer length: %u",
len);
expert_add_info_format(actx->pinfo, pi, &ei_ber_error_length,
"BER Error: Illegal integer length: %u", len);
} else {
header_field_info* hfi;
hfi = proto_registrar_get_nth(hf_id);
switch (hfi->type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
actx->created_item = proto_tree_add_uint(tree, hf_id, tvb, offset-len, len, (guint32)val);
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
actx->created_item = proto_tree_add_int(tree, hf_id, tvb, offset-len, len, (gint32)val);
break;
case FT_INT64:
actx->created_item = proto_tree_add_int64(tree, hf_id, tvb, offset-len, len, val);
break;
case FT_UINT64:
actx->created_item = proto_tree_add_uint64(tree, hf_id, tvb, offset-len, len, (guint64)val);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
if (used_too_many_bytes) {
expert_add_info_format(
actx->pinfo, actx->created_item, &ei_ber_value_too_many_bytes,
"Value is encoded with too many bytes(9 leading zero or one bits), hf_abbr: %s",
hfi->abbrev);
}
}
}
if (value) {
*value = val;
}
return offset;
}
int
dissect_ber_constrained_integer64(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint64 min_len, gint64 max_len, gint hf_id, gint64 *value)
{
gint64 val;
offset = dissect_ber_integer64(implicit_tag, actx, tree, tvb, offset, hf_id, &val);
if (value) {
*value = val;
}
ber_check_value64 (val, min_len, max_len, actx, actx->created_item);
return offset;
}
int
dissect_ber_integer(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id, guint32 *value)
{
gint64 val;
offset = dissect_ber_integer64(implicit_tag, actx, tree, tvb, offset, hf_id, &val);
if (value) {
*value = (guint32)val;
}
return offset;
}
int
dissect_ber_constrained_integer(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint32 min_len, gint32 max_len, gint hf_id, guint32 *value)
{
gint64 val;
offset = dissect_ber_integer64(implicit_tag, actx, tree, tvb, offset, hf_id, &val);
if (value) {
*value = (guint32)val;
}
ber_check_value ((guint32)val, min_len, max_len, actx, actx->created_item);
return offset;
}
int
dissect_ber_boolean(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id, gboolean *value)
{
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
guint8 val;
header_field_info *hfi;
if (!implicit_tag) {
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, NULL);
} else {
}
val = tvb_get_guint8(tvb, offset);
offset += 1;
actx->created_item = NULL;
if (hf_id >= 0) {
hfi = proto_registrar_get_nth(hf_id);
if (hfi->type == FT_BOOLEAN)
actx->created_item = proto_tree_add_boolean(tree, hf_id, tvb, offset-1, 1, val);
else
actx->created_item = proto_tree_add_uint(tree, hf_id, tvb, offset-1, 1, val ? 1 : 0);
}
if (value) {
*value = (val ? TRUE : FALSE);
}
return offset;
}
int
dissect_ber_real(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id, double *value)
{
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 val_length = 0, len_remain, end_offset;
double val = 0;
proto_item *cause;
if (!implicit_tag) {
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, &val_length, NULL);
end_offset = offset + val_length;
} else {
get_last_ber_identifier(&ber_class, &pc, &tag);
get_last_ber_length(&val_length, NULL);
end_offset = offset + val_length;
len_remain = (guint32)tvb_reported_length_remaining(tvb, offset);
if (len_remain < val_length) {
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, val_length, "illegal_length",
"length:%u longer than tvb_reported_length_remaining:%d",
val_length,
len_remain);
expert_add_info(actx->pinfo, cause, &ei_ber_error_length);
return end_offset;
}
}
if(pc) {
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset - 2, 1, "wrong_tag",
"REAL class must be encoded as primitive");
expert_add_info(actx->pinfo, cause, &ei_ber_error_length);
}
val = asn1_get_real(tvb_get_ptr(tvb, offset, val_length), val_length);
actx->created_item = proto_tree_add_double(tree, hf_id, tvb, end_offset - val_length, val_length, val);
if (value)
*value = val;
return end_offset;
}
int
dissect_ber_sequence(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *parent_tree, tvbuff_t *tvb, int offset, const ber_sequence_t *seq, gint hf_id, gint ett_id) {
gint8 classx;
gboolean pcx, ind = 0, ind_field, imp_tag = FALSE;
gint32 tagx;
guint32 lenx;
proto_tree *tree = parent_tree;
proto_item *item = NULL;
proto_item *cause;
int end_offset = 0;
int hoffset;
tvbuff_t *next_tvb;
#ifdef DEBUG_BER
{
const char *name;
header_field_info *hfinfo;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
name = hfinfo->name;
} else {
name = "unnamed";
}
if (tvb_reported_length_remaining(tvb, offset) > 3) {
proto_tree_add_debug_text(tree, "SEQUENCE dissect_ber_sequence(%s) entered offset:%d len:%d %02x:%02x:%02x\n", name, offset, tvb_reported_length_remaining(tvb, offset), tvb_get_guint8(tvb, offset), tvb_get_guint8(tvb, offset+1), tvb_get_guint8(tvb, offset+2));
} else {
proto_tree_add_debug_text(tree, "SEQUENCE dissect_ber_sequence(%s) entered\n", name);
}
}
#endif
hoffset = offset;
if (!implicit_tag) {
offset = get_ber_identifier(tvb, offset, NULL, NULL, NULL);
offset = get_ber_length(tvb, offset, &lenx, NULL);
} else {
lenx = tvb_reported_length_remaining(tvb, offset);
end_offset = offset+lenx;
}
if (hf_id >= 0) {
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_id, tvb, hoffset, lenx + offset - hoffset, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_id);
}
}
offset = hoffset;
if (!implicit_tag) {
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &classx, &pcx, &tagx);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, &lenx, &ind);
if (ind) {
end_offset = offset + lenx -2;
} else {
end_offset = offset + lenx;
}
if ((classx != BER_CLASS_APP) && (classx != BER_CLASS_PRI)) {
if (!pcx
|| (!implicit_tag && ((classx != BER_CLASS_UNI) || (tagx != BER_UNI_TAG_SEQUENCE)))) {
tvb_ensure_bytes_exist(tvb, hoffset, 2);
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, lenx, "sequence_expected",
"Sequence expected but class:%s(%d) %s tag:%d was unexpected",
val_to_str_const(classx, ber_class_codes, "Unknown"),
classx,
pcx ? ber_pc_codes_short.true_string : ber_pc_codes_short.false_string,
tagx);
expert_add_info(actx->pinfo, cause, &ei_ber_expected_sequence);
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(cause, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, hoffset, unknown_tree);
}
return end_offset;
}
}
}
if(offset == end_offset){
proto_item_append_text(item, " [0 length]");
}
while (offset < end_offset) {
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
int eoffset, count;
if ((tvb_get_guint8(tvb, offset) == 0) && (tvb_get_guint8(tvb, offset+1) == 0)) {
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, &ind);
proto_item_append_text(item, " 0 items");
return end_offset;
}
hoffset = offset;
offset = get_ber_identifier(tvb, offset, &ber_class, &pc, &tag);
offset = get_ber_length(tvb, offset, &len, &ind_field);
eoffset = offset + len;
if (eoffset <= hoffset)
THROW(ReportedBoundsError);
ber_sequence_try_again:
if (!seq->func) {
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, NULL, NULL);
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "unknown_field",
"This field lies beyond the end of the known sequence definition.");
expert_add_info(actx->pinfo, cause, &ei_ber_unknown_field_sequence);
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(cause, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, hoffset, unknown_tree);
}
offset = eoffset;
continue;
}
if ( ((seq->ber_class == BER_CLASS_CON) || (seq->ber_class == BER_CLASS_APP) || (seq->ber_class == BER_CLASS_PRI))
&& (!(seq->flags & BER_FLAGS_NOOWNTAG)) ) {
if ( (seq->ber_class != BER_CLASS_ANY)
&& (seq->tag != -1)
&& ( (seq->ber_class != ber_class)
|| (seq->tag != tag) ) ) {
if (seq->flags & BER_FLAGS_OPTIONAL) {
seq++;
goto ber_sequence_try_again;
}
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, NULL, NULL);
if (seq->ber_class == BER_CLASS_UNI) {
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "wrong_field",
"Wrong field in SEQUENCE expected class:%s(%d) tag:%d (%s) but found class:%s(%d) tag:%d",
val_to_str_const(seq->ber_class, ber_class_codes, "Unknown"),
seq->ber_class,
seq->tag,
val_to_str_ext_const(seq->tag, &ber_uni_tag_codes_ext, "Unknown"),
val_to_str_const(ber_class, ber_class_codes, "Unknown"),
ber_class,
tag);
} else {
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "wrong_field",
"Wrong field in SEQUENCE expected class:%s(%d) tag:%d but found class:%s(%d) tag:%d",
val_to_str_const(seq->ber_class, ber_class_codes, "Unknown"),
seq->ber_class,
seq->tag,
val_to_str_const(ber_class, ber_class_codes, "Unknown"),
ber_class,
tag);
}
expert_add_info(actx->pinfo, cause, &ei_ber_sequence_field_wrong);
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(cause, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, hoffset, unknown_tree);
}
seq++;
offset = eoffset;
continue;
}
} else if (!(seq->flags & BER_FLAGS_NOTCHKTAG)) {
if ( (seq->ber_class != BER_CLASS_ANY)
&& (seq->tag != -1)
&& ( (seq->ber_class != ber_class)
|| (seq->tag != tag) ) ) {
if (seq->flags & BER_FLAGS_OPTIONAL) {
seq++;
goto ber_sequence_try_again;
}
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, NULL, NULL);
if ( seq->ber_class == BER_CLASS_UNI) {
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "wrong_field",
"Wrong field in SEQUENCE expected class:%s(%d) tag:%d(%s) but found class:%s(%d) tag:%d",
val_to_str_const(seq->ber_class, ber_class_codes, "Unknown"),
seq->ber_class,
seq->tag,
val_to_str_ext_const(seq->tag, &ber_uni_tag_codes_ext, "Unknown"),
val_to_str_const(ber_class, ber_class_codes, "Unknown"),
ber_class, tag);
} else {
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "wrong_field",
"Wrong field in SEQUENCE expected class:%s(%d) tag:%d but found class:%s(%d) tag:%d",
val_to_str_const(seq->ber_class, ber_class_codes, "Unknown"),
seq->ber_class,
seq->tag,
val_to_str_const(ber_class, ber_class_codes, "Unknown"),
ber_class,
tag);
}
expert_add_info(actx->pinfo, cause, &ei_ber_sequence_field_wrong);
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(cause, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, hoffset, unknown_tree);
}
seq++;
offset = eoffset;
continue;
}
}
if (!(seq->flags & BER_FLAGS_NOOWNTAG) ) {
if (ind_field && (len == 2)) {
next_tvb = ber_tvb_new_subset_length(tvb, offset, len);
hoffset = eoffset;
} else {
hoffset = dissect_ber_identifier(actx->pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
hoffset = dissect_ber_length(actx->pinfo, tree, tvb, hoffset, NULL, NULL);
next_tvb = ber_tvb_new_subset_length(tvb, hoffset, eoffset - hoffset - (2 * ind_field));
}
} else {
next_tvb = ber_tvb_new_subset_length(tvb, hoffset, eoffset - hoffset);
}
#if 0
if ((eoffset-hoffset) > length_remaining) {
next_tvb = tvb_new_subset_remaining(tvb, hoffset);
} else {
}
#endif
#ifdef DEBUG_BER
{
const char *name;
header_field_info *hfinfo;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
name = hfinfo->name;
} else {
name = "unnamed";
}
if (tvb_reported_length_remaining(next_tvb, 0) > 3) {
proto_tree_add_debug_text(tree, "SEQUENCE dissect_ber_sequence(%s) calling subdissector offset:%d len:%d %02x:%02x:%02x\n", name, offset, tvb_reported_length_remaining(next_tvb, 0), tvb_get_guint8(next_tvb, 0), tvb_get_guint8(next_tvb, 1), tvb_get_guint8(next_tvb, 2));
} else {
proto_tree_add_debug_text(tree, "SEQUENCE dissect_ber_sequence(%s) calling subdissector\n", name);
}
}
#endif
if (next_tvb == NULL) {
THROW(ReportedBoundsError);
}
imp_tag = FALSE;
if (seq->flags & BER_FLAGS_IMPLTAG) {
imp_tag = TRUE;
}
count = seq->func(imp_tag, next_tvb, 0, actx, tree, *seq->p_id);
#ifdef DEBUG_BER
{
const char *name;
header_field_info *hfinfo;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
name = hfinfo->name;
} else {
name = "unnamed";
}
proto_tree_add_debug_text(tree, "SEQUENCE dissect_ber_sequence(%s) subdissector ate %d bytes\n", name, count);
}
#endif
if ((len != 0) && (count == 0) && (seq->flags & BER_FLAGS_OPTIONAL)) {
seq++;
goto ber_sequence_try_again;
}
offset = eoffset;
if (!(seq->flags & BER_FLAGS_NOOWNTAG) ) {
if ((ind_field == 1) && (len > 2))
{
if (show_internal_ber_fields) {
proto_tree_add_item(tree, hf_ber_seq_field_eoc, tvb, offset-2, 2, ENC_NA);
}
}
}
seq++;
}
if (offset != end_offset) {
tvb_ensure_bytes_exist(tvb, offset-2, 2);
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset-2, 2, "illegal_length",
"Sequence ate %d too many bytes",
offset - end_offset);
expert_add_info_format(actx->pinfo, cause, &ei_ber_error_length,
"BER Error: too many bytes in Sequence");
}
if (ind) {
end_offset += 2;
if (show_internal_ber_fields) {
proto_tree_add_item(tree, hf_ber_seq_eoc, tvb, end_offset-2, 2, ENC_NA);
}
}
return end_offset;
}
int
dissect_ber_set(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *parent_tree, tvbuff_t *tvb, int offset, const ber_sequence_t *set, gint hf_id, gint ett_id) {
gint8 classx;
gboolean pcx, ind = 0, ind_field, imp_tag = FALSE;
gint32 tagx;
guint32 lenx;
proto_tree *tree = parent_tree;
proto_item *item = NULL;
proto_item *cause;
int end_offset, s_offset;
int hoffset;
tvbuff_t *next_tvb;
guint32 mandatory_fields = 0;
guint8 set_idx;
gboolean first_pass;
const ber_sequence_t *cset = NULL;
#define MAX_SET_ELEMENTS 32
s_offset = offset;
#ifdef DEBUG_BER
{
const char *name;
header_field_info *hfinfo;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
name = hfinfo->name;
} else {
name = "unnamed";
}
if (tvb_reported_length_remaining(tvb, offset) > 3) {
proto_tree_add_debug_text(tree, "SET dissect_ber_set(%s) entered offset:%d len:%d %02x:%02x:%02x\n", name, offset, tvb_reported_length_remaining(tvb, offset), tvb_get_guint8(tvb, offset), tvb_get_guint8(tvb, offset+1), tvb_get_guint8(tvb, offset+2));
} else {
proto_tree_add_debug_text(tree, "SET dissect_ber_set(%s) entered\n", name);
}
}
#endif
if (!implicit_tag) {
hoffset = offset;
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &classx, &pcx, &tagx);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, &lenx, &ind);
if (ind) {
end_offset = offset + lenx -2;
} else {
end_offset = offset + lenx;
}
if ((classx != BER_CLASS_APP) && (classx != BER_CLASS_PRI)) {
if (!pcx
|| (!implicit_tag && ((classx != BER_CLASS_UNI)
|| (tagx != BER_UNI_TAG_SET)))) {
tvb_ensure_bytes_exist(tvb, hoffset, 2);
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, lenx, "set_expected",
"SET expected but class:%s(%d) %s tag:%d was found",
val_to_str_const(classx, ber_class_codes, "Unknown"),
classx,
pcx ? ber_pc_codes_short.true_string : ber_pc_codes_short.false_string,
tagx);
expert_add_info(actx->pinfo, cause, &ei_ber_expected_set);
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(cause, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, hoffset, unknown_tree);
}
return end_offset;
}
}
} else {
lenx = tvb_reported_length_remaining(tvb, offset);
end_offset = offset+lenx;
}
if (hf_id >= 0) {
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_id, tvb, offset, lenx, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_id);
}
}
for (set_idx = 0; (cset = &set[set_idx])->func && (set_idx < MAX_SET_ELEMENTS); set_idx++) {
if (!(cset->flags & BER_FLAGS_OPTIONAL))
mandatory_fields |= 1 << set_idx;
}
while (offset < end_offset) {
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
int eoffset, count;
if ((tvb_get_guint8(tvb, offset) == 0) && (tvb_get_guint8(tvb, offset+1) == 0)) {
if (show_internal_ber_fields) {
proto_tree_add_item(tree, hf_ber_seq_eoc, tvb, s_offset, offset+2, ENC_NA);
}
return end_offset;
}
hoffset = offset;
offset = get_ber_identifier(tvb, offset, &ber_class, &pc, &tag);
offset = get_ber_length(tvb, offset, &len, &ind_field);
eoffset = offset + len;
for (first_pass = TRUE, cset = set, set_idx = 0; cset->func || first_pass; cset++, set_idx++) {
if (!cset->func) {
first_pass = FALSE;
cset = set;
set_idx = 0;
if (!cset->func) {
break;
}
}
if ((first_pass && ((cset->ber_class == ber_class) && (cset->tag == tag))) ||
(!first_pass && ((cset->ber_class == BER_CLASS_ANY) && (cset->tag == -1))) )
{
if (!(cset->flags & BER_FLAGS_NOOWNTAG) ) {
hoffset = dissect_ber_identifier(actx->pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
hoffset = dissect_ber_length(actx->pinfo, tree, tvb, hoffset, NULL, NULL);
next_tvb = ber_tvb_new_subset_length(tvb, hoffset, eoffset - hoffset - (2 * ind_field));
} else {
next_tvb = ber_tvb_new_subset_length(tvb, hoffset, eoffset - hoffset);
}
#if 0
if ((eoffset-hoffset)>length_remaining) {
next_tvb = tvb_new_subset_remaining(tvb, hoffset);
} else {
}
#endif
#ifdef DEBUG_BER
{
const char *name;
header_field_info *hfinfo;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
name = hfinfo->name;
} else {
name = "unnamed";
}
if (tvb_reported_length_remaining(next_tvb, 0) > 3) {
proto_tree_add_debug_text(tree, "SET dissect_ber_set(%s) calling subdissector offset:%d len:%d %02x:%02x:%02x\n", name, offset, tvb_reported_length_remaining(next_tvb, 0), tvb_get_guint8(next_tvb, 0), tvb_get_guint8(next_tvb, 1), tvb_get_guint8(next_tvb, 2));
} else {
proto_tree_add_debug_text(tree, "SET dissect_ber_set(%s) calling subdissector\n", name);
}
}
#endif
if (next_tvb == NULL) {
THROW(ReportedBoundsError);
}
imp_tag = FALSE;
if ((cset->flags & BER_FLAGS_IMPLTAG))
imp_tag = TRUE;
count = cset->func(imp_tag, next_tvb, 0, actx, tree, *cset->p_id);
if (count || (first_pass && ((len == 0) || ((ind_field == 1) && (len == 2))))) {
if (set_idx < MAX_SET_ELEMENTS)
mandatory_fields &= ~(1 << set_idx);
offset = eoffset;
if (!(cset->flags & BER_FLAGS_NOOWNTAG) ) {
if (ind_field == 1) {
if (show_internal_ber_fields) {
proto_tree_add_item(tree, hf_ber_set_field_eoc, tvb, offset, count, ENC_NA);
}
}
}
break;
}
}
}
if (!cset->func) {
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "unknown_field",
"Unknown field in SET class:%s(%d) tag:%d",
val_to_str_const(ber_class, ber_class_codes, "Unknown"),
ber_class,
tag);
expert_add_info(actx->pinfo, cause, &ei_ber_unknown_field_set);
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(cause, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, hoffset, unknown_tree);
}
offset = eoffset;
}
}
if (mandatory_fields) {
for (set_idx = 0; (cset = &set[set_idx])->func && (set_idx < MAX_SET_ELEMENTS); set_idx++) {
if (mandatory_fields & (1 << set_idx)) {
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, lenx, "missing_field",
"Missing field in SET class:%s(%d) tag:%d expected",
val_to_str_const(cset->ber_class, ber_class_codes, "Unknown"),
cset->ber_class,
cset->tag);
expert_add_info(actx->pinfo, cause, &ei_ber_missing_field_set);
}
}
}
if (offset != end_offset) {
tvb_ensure_bytes_exist(tvb, offset-2, 2);
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset-2, 2, "illegal_length",
"SET ate %d too many bytes",
offset - end_offset);
expert_add_info_format(actx->pinfo, cause, &ei_ber_error_length,
"BER Error: too many bytes in SET");
}
if (ind) {
end_offset += 2;
if (show_internal_ber_fields) {
proto_tree_add_item(tree, hf_ber_set_eoc, tvb, end_offset-2, 2, ENC_NA);
}
}
return end_offset;
}
int
dissect_ber_choice(asn1_ctx_t *actx, proto_tree *parent_tree, tvbuff_t *tvb, int offset, const ber_choice_t *choice, gint hf_id, gint ett_id, gint *branch_taken)
{
gint8 ber_class;
gboolean pc, ind, imp_tag = FALSE;
gint32 tag;
guint32 len;
proto_tree *tree = parent_tree;
proto_item *item = NULL;
int end_offset, start_offset, count;
int hoffset = offset;
gint length;
tvbuff_t *next_tvb;
gboolean first_pass;
header_field_info *hfinfo;
const ber_choice_t *ch;
#ifdef DEBUG_BER_CHOICE
{
const char *name;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
name = hfinfo->name;
} else {
name = "unnamed";
}
if (tvb_reported_length_remaining(tvb, offset) > 3) {
proto_tree_add_debug_text(tree, "CHOICE dissect_ber_choice(%s) entered offset:%d len:%d %02x:%02x:%02x\n", name, offset, tvb_reported_length_remaining(tvb, offset), tvb_get_guint8(tvb, offset), tvb_get_guint8(tvb, offset+1), tvb_get_guint8(tvb, offset+2));
} else {
proto_tree_add_debug_text(tree, "CHOICE dissect_ber_choice(%s) entered len:%d\n", name, tvb_reported_length_remaining(tvb, offset));
}
}
#endif
start_offset = offset;
if (branch_taken) {
*branch_taken = -1;
}
if (tvb_reported_length_remaining(tvb, offset) == 0) {
item = proto_tree_add_string_format_value(
parent_tree, hf_ber_error, tvb, offset, 0, "empty_choice",
"Empty choice was found");
expert_add_info(actx->pinfo, item, &ei_ber_empty_choice);
return offset;
}
offset = get_ber_identifier(tvb, offset, &ber_class, &pc, &tag);
offset = get_ber_length(tvb, offset, &len, &ind);
end_offset = offset + len ;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
switch (hfinfo->type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
break;
default:
proto_tree_add_expert_format(
tree, actx->pinfo, &ei_hf_field_not_integer_type, tvb, offset, len,
"dissect_ber_choice(): frame:%u offset:%d Was passed an HF field that was not integer type : %s",
actx->pinfo->num, offset, hfinfo->abbrev);
return end_offset;
}
}
ch = choice;
first_pass = TRUE;
while (ch->func || first_pass) {
if (branch_taken) {
(*branch_taken)++;
}
if (!ch->func) {
first_pass = FALSE;
ch = choice;
if (branch_taken) {
*branch_taken = -1;
}
continue;
}
#ifdef DEBUG_BER_CHOICE
proto_tree_add_debug_text(tree, "CHOICE testing potential subdissector class[%p]:%d:(expected)%d tag:%d:(expected)%d flags:%d\n", ch, ber_class, ch->ber_class, tag, ch->tag, ch->flags);
#endif
if ( (first_pass
&& (((ch->ber_class == ber_class) && (ch->tag == tag))
|| ((ch->ber_class == ber_class) && (ch->tag == -1) && (ch->flags & BER_FLAGS_NOOWNTAG))))
|| (!first_pass && (((ch->ber_class == BER_CLASS_ANY) && (ch->tag == -1))))
) {
if (!(ch->flags & BER_FLAGS_NOOWNTAG)) {
hoffset = dissect_ber_identifier(actx->pinfo, tree, tvb, start_offset, NULL, NULL, NULL);
hoffset = dissect_ber_length(actx->pinfo, tree, tvb, hoffset, NULL, NULL);
start_offset = hoffset;
if (ind) {
length = len - 2;
} else {
length = len;
}
} else {
length = end_offset- hoffset;
}
if (hf_id >= 0) {
if (parent_tree) {
item = proto_tree_add_uint(parent_tree, hf_id, tvb, hoffset, end_offset - hoffset, ch->value);
tree = proto_item_add_subtree(item, ett_id);
}
}
#ifdef REMOVED
if (first_pass)
next_tvb = ber_tvb_new_subset_length(tvb, hoffset, length);
else
next_tvb = tvb;
#endif
next_tvb = ber_tvb_new_subset_length(tvb, hoffset, length);
#ifdef DEBUG_BER_CHOICE
{
const char *name;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
name = hfinfo->name;
} else {
name = "unnamed";
}
if (tvb_reported_length_remaining(next_tvb, 0) > 3) {
proto_tree_add_debug_text(tree, "CHOICE dissect_ber_choice(%s) calling subdissector start_offset:%d offset:%d len:%d %02x:%02x:%02x\n", name, start_offset, offset, tvb_reported_length_remaining(next_tvb, 0), tvb_get_guint8(next_tvb, 0), tvb_get_guint8(next_tvb, 1), tvb_get_guint8(next_tvb, 2));
} else {
proto_tree_add_debug_text(tree, "CHOICE dissect_ber_choice(%s) calling subdissector len:%d\n", name, tvb_reported_length(next_tvb));
}
}
#endif
if (next_tvb == NULL) {
THROW(ReportedBoundsError);
}
imp_tag = FALSE;
if ((ch->flags & BER_FLAGS_IMPLTAG))
imp_tag = TRUE;
count = ch->func(imp_tag, next_tvb, 0, actx, tree, *ch->p_id);
#ifdef DEBUG_BER_CHOICE
{
const char *name;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
name = hfinfo->name;
} else {
name = "unnamed";
}
proto_tree_add_debug_text(tree, "CHOICE dissect_ber_choice(%s) subdissector ate %d bytes\n", name, count);
}
#endif
if ((count == 0) && (((ch->ber_class == ber_class) && (ch->tag == -1) && (ch->flags & BER_FLAGS_NOOWNTAG)) || !first_pass)) {
ch++;
#ifdef DEBUG_BER_CHOICE
{
const char *name;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
name = hfinfo->name;
} else {
name = "unnamed";
}
proto_tree_add_debug_text(tree, "CHOICE dissect_ber_choice(%s) trying again\n", name);
}
#endif
continue;
}
if (!(ch->flags & BER_FLAGS_NOOWNTAG)) {
if (ind) {
if (show_internal_ber_fields) {
proto_tree_add_item(tree, hf_ber_choice_eoc, tvb, end_offset-2, 2, ENC_NA);
}
}
}
return end_offset;
}
ch++;
}
if (branch_taken) {
*branch_taken = -1;
}
#ifdef REMOVED
item = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "missing_choice_field",
"This choice field was not found.");
expert_add_info(actx->pinfo, item, &ei_ber_choice_not_found);
return end_offset;
#endif
return start_offset;
}
int
dissect_ber_constrained_restricted_string(gboolean implicit_tag, gint32 type, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint32 min_len, gint32 max_len, gint hf_id, tvbuff_t **out_tvb) {
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
int eoffset;
int hoffset = offset;
proto_item *cause;
#ifdef DEBUG_BER
{
const char *name;
header_field_info *hfinfo;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
name = hfinfo->name;
} else {
name = "unnamed";
}
if (tvb_reported_length_remaining(tvb, offset) > 3) {
proto_tree_add_debug_text(tree, "RESTRICTED STRING dissect_ber_octet string(%s) entered implicit_tag:%d offset:%d len:%d %02x:%02x:%02x\n", name, implicit_tag, offset, tvb_reported_length_remaining(tvb, offset), tvb_get_guint8(tvb, offset), tvb_get_guint8(tvb, offset+1), tvb_get_guint8(tvb, offset+2));
} else {
proto_tree_add_debug_text(tree, "RESTRICTED STRING dissect_ber_octet_string(%s) entered\n", name);
}
}
#endif
if (!implicit_tag) {
offset = get_ber_identifier(tvb, offset, &ber_class, &pc, &tag);
offset = get_ber_length(tvb, offset, &len, NULL);
eoffset = offset + len;
if ( (ber_class != BER_CLASS_UNI)
|| (tag != type) ) {
tvb_ensure_bytes_exist(tvb, hoffset, 2);
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "string_expected",
"String with tag=%d expected but class:%s(%d) %s tag:%d was unexpected",
type,
val_to_str_const(ber_class, ber_class_codes, "Unknown"),
ber_class, pc ? ber_pc_codes_short.true_string : ber_pc_codes_short.false_string,
tag);
expert_add_info(actx->pinfo, cause, &ei_ber_expected_string);
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(cause, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, hoffset, unknown_tree);
}
return eoffset;
}
}
return dissect_ber_constrained_octet_string(implicit_tag, actx, tree, tvb, hoffset, min_len, max_len, hf_id, out_tvb);
}
int dissect_ber_restricted_string(gboolean implicit_tag, gint32 type, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id, tvbuff_t **out_tvb)
{
return dissect_ber_constrained_restricted_string(implicit_tag, type, actx, tree, tvb, offset, NO_BOUND, NO_BOUND, hf_id, out_tvb);
}
int
dissect_ber_GeneralString(asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id, char *name_string, guint name_len)
{
tvbuff_t *out_tvb = NULL;
gint tvb_len;
offset = dissect_ber_restricted_string(FALSE, BER_UNI_TAG_GeneralString, actx, tree, tvb, offset, hf_id, (name_string) ? &out_tvb : NULL);
if (name_string) {
if (out_tvb) {
tvb_len = tvb_reported_length(out_tvb);
if ((guint)tvb_len >= name_len) {
tvb_memcpy(out_tvb, (guint8*)name_string, 0, name_len-1);
name_string[name_len-1] = '\0';
} else {
tvb_memcpy(out_tvb, (guint8*)name_string, 0, tvb_len);
name_string[tvb_len] = '\0';
}
}
}
return offset;
}
static int
dissect_ber_any_oid(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id, tvbuff_t **value_tvb, gboolean is_absolute)
{
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
int eoffset;
int hoffset;
const char *str;
proto_item *cause;
const gchar *name;
header_field_info *hfi;
#ifdef DEBUG_BER
{
header_field_info *hfinfo;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
name = hfinfo->name;
} else {
name = "unnamed";
}
if (tvb_reported_length_remaining(tvb, offset) > 3) {
proto_tree_add_debug_text(tree, "OBJECT IDENTIFIER dissect_ber_any_oid(%s) entered implicit_tag:%d offset:%d len:%d %02x:%02x:%02x\n", name, implicit_tag, offset, tvb_reported_length_remaining(tvb, offset), tvb_get_guint8(tvb, offset), tvb_get_guint8(tvb, offset+1), tvb_get_guint8(tvb, offset+2));
} else {
proto_tree_add_debug_text(tree, "OBJECT IDENTIFIER dissect_ber_any_oid(%s) entered\n", name);
}
}
#endif
if (!implicit_tag) {
hoffset = offset;
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, NULL);
eoffset = offset + len;
if ( (ber_class != BER_CLASS_UNI)
|| (is_absolute && tag != BER_UNI_TAG_OID)
|| (!is_absolute && tag != BER_UNI_TAG_RELATIVE_OID) ) {
tvb_ensure_bytes_exist(tvb, hoffset, 2);
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "oid_expected",
"Object Identifier expected but class:%s(%d) %s tag:%d was unexpected",
val_to_str_const(ber_class, ber_class_codes, "Unknown"),
ber_class,
pc ? ber_pc_codes_short.true_string : ber_pc_codes_short.false_string,
tag);
expert_add_info(actx->pinfo, cause, &ei_ber_expected_object_identifier);
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(cause, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, hoffset, unknown_tree);
}
return eoffset;
}
} else {
len = tvb_reported_length_remaining(tvb, offset);
eoffset = offset+len;
}
actx->created_item = NULL;
hfi = proto_registrar_get_nth(hf_id);
if ((is_absolute && hfi->type == FT_OID) || (!is_absolute && hfi->type == FT_REL_OID)) {
actx->created_item = proto_tree_add_item(tree, hf_id, tvb, offset, len, ENC_BIG_ENDIAN);
} else if (IS_FT_STRING(hfi->type)) {
str = oid_encoded2string(wmem_packet_scope(), tvb_get_ptr(tvb, offset, len), len);
actx->created_item = proto_tree_add_string(tree, hf_id, tvb, offset, len, str);
if (actx->created_item) {
name = oid_resolved_from_encoded(wmem_packet_scope(), tvb_get_ptr(tvb, offset, len), len);
if (name) {
proto_item_append_text(actx->created_item, " (%s)", name);
}
}
} else {
DISSECTOR_ASSERT_NOT_REACHED();
}
if (value_tvb)
*value_tvb = ber_tvb_new_subset_length(tvb, offset, len);
return eoffset;
}
static int
dissect_ber_any_oid_str(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id, const char **value_stringx, gboolean is_absolute)
{
tvbuff_t *value_tvb = NULL;
guint length;
offset = dissect_ber_any_oid(implicit_tag, actx, tree, tvb, offset, hf_id, (value_stringx) ? &value_tvb : NULL, is_absolute);
if (value_stringx) {
if (value_tvb && (length = tvb_reported_length(value_tvb))) {
*value_stringx = oid_encoded2string(wmem_packet_scope(), tvb_get_ptr(value_tvb, 0, length), length);
} else {
*value_stringx = "";
}
}
return offset;
}
int
dissect_ber_relative_oid(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id, tvbuff_t **value_tvb)
{
return dissect_ber_any_oid(implicit_tag, actx, tree, tvb, offset, hf_id, value_tvb, FALSE);
}
int
dissect_ber_relative_oid_str(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id, const char **value_stringx)
{
return dissect_ber_any_oid_str(implicit_tag, actx, tree, tvb, offset, hf_id, value_stringx, FALSE);
}
int
dissect_ber_object_identifier(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id, tvbuff_t **value_tvb)
{
return dissect_ber_any_oid(implicit_tag, actx, tree, tvb, offset, hf_id, value_tvb, TRUE);
}
int
dissect_ber_object_identifier_str(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id, const char **value_stringx)
{
return dissect_ber_any_oid_str(implicit_tag, actx, tree, tvb, offset, hf_id, value_stringx, TRUE);
}
static int
dissect_ber_sq_of(gboolean implicit_tag, gint32 type, asn1_ctx_t *actx, proto_tree *parent_tree, tvbuff_t *tvb, int offset, gint32 min_len, gint32 max_len, const ber_sequence_t *seq, gint hf_id, gint ett_id) {
gint8 classx;
gboolean pcx, ind = FALSE, ind_field;
gint32 tagx;
guint32 lenx;
proto_tree *tree = parent_tree;
proto_item *item = NULL;
proto_item *causex;
int cnt, hoffsetx, end_offset;
gboolean have_cnt;
header_field_info *hfi;
tvbuff_t *next_tvb;
#ifdef DEBUG_BER_SQ_OF
{
const char *name;
header_field_info *hfinfo;
if (hf_id >= 0) {
hfinfo = proto_registrar_get_nth(hf_id);
name = hfinfo->name;
} else {
name = "unnamed";
}
if (tvb_reported_length_remaining(tvb,offset) > 3) {
proto_tree_add_debug_text(tree, "SQ OF dissect_ber_sq_of(%s) entered implicit_tag:%d offset:%d len:%d %02x:%02x:%02x\n", name, implicit_tag, offset, tvb_reported_length_remaining(tvb, offset), tvb_get_guint8(tvb, offset), tvb_get_guint8(tvb, offset+1), tvb_get_guint8(tvb, offset+2));
} else {
proto_tree_add_debug_text(tree, "SQ OF dissect_ber_sq_of(%s) entered\n", name);
}
}
#endif
if (!implicit_tag) {
hoffsetx = offset;
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &classx, &pcx, &tagx);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, &lenx, &ind);
end_offset = offset + lenx;
if ((classx != BER_CLASS_APP) && (classx != BER_CLASS_PRI)) {
if (!pcx
|| (!implicit_tag && ((classx != BER_CLASS_UNI)
|| (tagx != type)))) {
tvb_ensure_bytes_exist(tvb, hoffsetx, 2);
causex = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, lenx,
(type == BER_UNI_TAG_SEQUENCE) ? "set_of_expected" : "sequence_of_expected",
"%s Of expected but class:%s(%d) %s tag:%d was unexpected",
(type == BER_UNI_TAG_SEQUENCE) ? "Set" : "Sequence",
val_to_str_const(classx, ber_class_codes, "Unknown"),
classx, pcx ? ber_pc_codes_short.true_string : ber_pc_codes_short.false_string,
tagx);
if (type == BER_UNI_TAG_SEQUENCE) {
expert_add_info_format(
actx->pinfo, causex, &ei_ber_expected_set,
"BER Error: Set Of expected");
} else {
expert_add_info_format(
actx->pinfo, causex, &ei_ber_expected_sequence,
"BER Error: Sequence Of expected");
}
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(causex, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, hoffsetx, unknown_tree);
}
return end_offset;
}
}
} else {
lenx = tvb_reported_length_remaining(tvb, offset);
end_offset = offset + lenx;
}
cnt = 0;
have_cnt = FALSE;
hoffsetx = offset;
if (tvb_captured_length_remaining(tvb, offset) == tvb_reported_length_remaining(tvb, offset)) {
have_cnt = TRUE;
while (offset < end_offset) {
guint32 len;
gint s_offset;
s_offset = offset;
if ((tvb_get_guint8(tvb, offset) == 0) && (tvb_get_guint8(tvb, offset+1) == 0)) {
break;
}
offset = get_ber_identifier(tvb, offset, NULL, NULL, NULL);
offset = get_ber_length(tvb, offset, &len, &ind);
offset += len;
cnt++;
if (offset <= s_offset) {
have_cnt = FALSE;
cnt = 0;
break;
}
}
}
offset = hoffsetx;
if (hf_id >= 0) {
hfi = proto_registrar_get_nth(hf_id);
if (parent_tree) {
if (hfi->type == FT_NONE) {
item = proto_tree_add_item(parent_tree, hf_id, tvb, offset, lenx, ENC_BIG_ENDIAN);
proto_item_append_text(item, ":");
} else {
if (have_cnt) {
item = proto_tree_add_uint(parent_tree, hf_id, tvb, offset, lenx, cnt);
proto_item_append_text(item, (cnt == 1) ? " item" : " items");
} else
item = proto_tree_add_uint_format_value(parent_tree, hf_id, tvb, offset, lenx, cnt, "unknown number of items");
}
tree = proto_item_add_subtree(item, ett_id);
ber_check_items (cnt, min_len, max_len, actx, item);
}
}
while (offset < end_offset) {
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
int eoffset;
int hoffset;
proto_item *cause;
gboolean imp_tag;
hoffset = offset;
if ((tvb_get_guint8(tvb, offset) == 0) && (tvb_get_guint8(tvb, offset+1) == 0)) {
if (show_internal_ber_fields) {
proto_tree_add_item(tree, hf_ber_seq_of_eoc, tvb, hoffset, end_offset-hoffset, ENC_NA);
}
return offset+2;
}
offset = get_ber_identifier(tvb, offset, &ber_class, &pc, &tag);
offset = get_ber_length(tvb, offset, &len, &ind_field);
eoffset = offset + len;
if (eoffset <= hoffset)
THROW(ReportedBoundsError);
if ((ber_class == BER_CLASS_UNI) && (tag == BER_UNI_TAG_EOC)) {
hoffset = dissect_ber_identifier(actx->pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
dissect_ber_length(actx->pinfo, tree, tvb, hoffset, NULL, NULL);
return eoffset;
}
if (seq->ber_class != BER_CLASS_ANY) {
if ((seq->ber_class != ber_class)
|| (seq->tag != tag) ) {
if (!(seq->flags & BER_FLAGS_NOTCHKTAG)) {
if ( seq->ber_class == BER_CLASS_UNI) {
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "wrong_field",
"Wrong field in SQ OF expected class:%s(%d) tag:%d(%s) but found class:%s(%d) tag:%d",
val_to_str_const(seq->ber_class, ber_class_codes, "Unknown"),
seq->ber_class,
seq->tag,
val_to_str_ext_const(seq->tag, &ber_uni_tag_codes_ext, "Unknown"),
val_to_str_const(ber_class, ber_class_codes, "Unknown"),
ber_class, tag);
} else {
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "wrong_field",
"Wrong field in SQ OF expected class:%s(%d) tag:%d but found class:%s(%d) tag:%d",
val_to_str_const(seq->ber_class, ber_class_codes, "Unknown"),
seq->ber_class,
seq->tag,
val_to_str_const(ber_class, ber_class_codes, "Unknown"),
ber_class,
tag);
}
expert_add_info_format(
actx->pinfo, cause, &ei_ber_sequence_field_wrong,
"BER Error: Wrong field in SEQUENCE OF");
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(cause, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, hoffset, unknown_tree);
}
offset = eoffset;
continue;
}
}
}
if (!(seq->flags & BER_FLAGS_NOOWNTAG) && !(seq->flags & BER_FLAGS_IMPLTAG)) {
hoffset = dissect_ber_identifier(actx->pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
hoffset = dissect_ber_length(actx->pinfo, tree, tvb, hoffset, NULL, NULL);
}
if ((seq->flags == BER_FLAGS_IMPLTAG) && (seq->ber_class == BER_CLASS_CON)) {
hoffset = dissect_ber_identifier(actx->pinfo, tree, tvb, hoffset, NULL, NULL, NULL);
hoffset = dissect_ber_length(actx->pinfo, tree, tvb, hoffset, NULL, NULL);
}
next_tvb = ber_tvb_new_subset_length(tvb, hoffset, eoffset-hoffset);
imp_tag = FALSE;
if (seq->flags == BER_FLAGS_IMPLTAG)
imp_tag = TRUE;
seq->func(imp_tag, next_tvb, 0, actx, tree, *seq->p_id);
cnt++;
offset = eoffset;
}
if (offset != end_offset) {
tvb_ensure_bytes_exist(tvb, offset-2, 2);
causex = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset-2, 2, "illegal_length",
"%s Of ate %d too many bytes",
(type == BER_UNI_TAG_SEQUENCE) ? "Set" : "Sequence",
offset - end_offset);
expert_add_info_format(actx->pinfo, causex, &ei_ber_error_length,
"BER Error:too many byte in %s",
(type == BER_UNI_TAG_SEQUENCE) ? "Set" : "Sequence");
}
return end_offset;
}
int
dissect_ber_constrained_sequence_of(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *parent_tree, tvbuff_t *tvb, int offset, gint32 min_len, gint32 max_len, const ber_sequence_t *seq, gint hf_id, gint ett_id) {
return dissect_ber_sq_of(implicit_tag, BER_UNI_TAG_SEQUENCE, actx, parent_tree, tvb, offset, min_len, max_len, seq, hf_id, ett_id);
}
int
dissect_ber_sequence_of(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *parent_tree, tvbuff_t *tvb, int offset, const ber_sequence_t *seq, gint hf_id, gint ett_id) {
return dissect_ber_sq_of(implicit_tag, BER_UNI_TAG_SEQUENCE, actx, parent_tree, tvb, offset, NO_BOUND, NO_BOUND, seq, hf_id, ett_id);
}
int
dissect_ber_constrained_set_of(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *parent_tree, tvbuff_t *tvb, int offset, gint32 min_len, gint32 max_len, const ber_sequence_t *seq, gint hf_id, gint ett_id) {
return dissect_ber_sq_of(implicit_tag, BER_UNI_TAG_SET, actx, parent_tree, tvb, offset, min_len, max_len, seq, hf_id, ett_id);
}
int
dissect_ber_set_of(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *parent_tree, tvbuff_t *tvb, int offset, const ber_sequence_t *seq, gint hf_id, gint ett_id) {
return dissect_ber_sq_of(implicit_tag, BER_UNI_TAG_SET, actx, parent_tree, tvb, offset, NO_BOUND, NO_BOUND, seq, hf_id, ett_id);
}
int
dissect_ber_GeneralizedTime(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id)
{
char str[35];
int tmp_int;
const guint8 *tmpstr;
char *strptr;
char first_delim[2];
int first_digits;
char second_delim[2];
int second_digits;
int ret;
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
int end_offset;
int hoffset;
proto_item *cause;
if (!implicit_tag) {
hoffset = offset;
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, NULL);
end_offset = offset+len;
if ( (ber_class != BER_CLASS_UNI)
|| (tag != BER_UNI_TAG_GeneralizedTime)) {
tvb_ensure_bytes_exist(tvb, hoffset, 2);
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "generalized_time_expected",
"GeneralizedTime expected but class:%s(%d) %s tag:%d was unexpected",
val_to_str_const(ber_class, ber_class_codes, "Unknown"),
ber_class,
pc ? ber_pc_codes_short.true_string : ber_pc_codes_short.false_string,
tag);
expert_add_info(actx->pinfo, cause, &ei_ber_expected_generalized_time);
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(cause, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, hoffset, unknown_tree);
}
return end_offset;
}
} else {
len = tvb_reported_length_remaining(tvb, offset);
end_offset = offset+len;
}
if ((len < 14) || (len > 23)) {
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "illegal_length",
"GeneralizedTime invalid length: %u",
len);
expert_add_info_format(actx->pinfo, cause, &ei_ber_error_length,
"BER Error: GeneralizedTime invalid length");
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(cause, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, offset, unknown_tree);
}
return end_offset;
}
tmpstr = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII);
strptr = str;
strptr += g_snprintf(str, 20, "%.4s-%.2s-%.2s %.2s:%.2s:%.2s",
tmpstr, tmpstr+4, tmpstr+6, tmpstr+8,
tmpstr+10, tmpstr+12);
first_delim[0] = 0;
second_delim[0] = 0;
ret = sscanf( tmpstr, "%14d%1[.,+-Z]%4d%1[+-Z]%4d", &tmp_int, first_delim, &first_digits, second_delim, &second_digits);
if (ret < 1) {
goto invalid;
}
if (ret >= 2) {
switch (first_delim[0]) {
case '.':
case ',':
if (ret == 2) {
goto invalid;
}
strptr += g_snprintf(strptr, 5, "%c%.3d", first_delim[0], first_digits);
if (ret >= 4) {
switch (second_delim[0]) {
case '+':
case '-':
if (ret == 4) {
goto invalid;
}
g_snprintf(strptr, 12, " (UTC%c%.4d)", second_delim[0], second_digits);
break;
case 'Z':
g_snprintf(strptr, 7, " (UTC)");
break;
default:
break;
}
}
break;
case '+':
case '-':
if (ret == 2) {
goto invalid;
}
g_snprintf(strptr, 12, " (UTC%c%.4d)", first_delim[0], first_digits);
break;
case 'Z':
g_snprintf(strptr, 7, " (UTC)");
break;
default:
break;
}
}
if (hf_id >= 0) {
proto_tree_add_string(tree, hf_id, tvb, offset, len, str);
}
offset+=len;
return offset;
invalid:
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "invalid_generalized_time",
"GeneralizedTime invalid format: %s",
tmpstr);
expert_add_info(actx->pinfo, cause, &ei_ber_invalid_format_generalized_time);
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(cause, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, offset, unknown_tree);
}
return end_offset;
}
int
dissect_ber_UTCTime(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, gint hf_id)
{
char outstr[33];
char *outstrptr = outstr;
const guint8 *instr;
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len, i, n;
int hoffset;
proto_item *cause;
proto_tree *error_tree;
const gchar *error_str = NULL;
if (!implicit_tag) {
hoffset = offset;
offset = dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset = dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, NULL);
if ( (ber_class != BER_CLASS_UNI) || (tag != BER_UNI_TAG_UTCTime) ) {
tvb_ensure_bytes_exist(tvb, hoffset, 2);
cause = proto_tree_add_string_format_value(
tree, hf_ber_error, tvb, offset, len, "utctime_expected",
"UTCTime expected but class:%s(%d) %s tag:%d was unexpected",
val_to_str_const(ber_class, ber_class_codes, "Unknown"),
ber_class,
pc ? ber_pc_codes_short.true_string : ber_pc_codes_short.false_string,
tag);
expert_add_info(actx->pinfo, cause, &ei_ber_expected_utc_time);
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(cause, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, hoffset, unknown_tree);
}
return offset+len;
}
} else {
len = tvb_reported_length_remaining(tvb, offset);
}
if ((len < 10) || (len > 19)) {
error_str = wmem_strdup_printf(wmem_packet_scope(), "BER Error: UTCTime invalid length: %u", len);
instr = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len > 19 ? 19 : len, ENC_ASCII);
goto malformed;
}
instr = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII);
for (i=0; i<10; i++) {
if ((instr[i] < '0') || (instr[i] > '9')) {
error_str = "BER Error: malformed UTCTime encoding, "
"first 10 octets have to contain YYMMDDhhmm in digits";
goto malformed;
}
}
g_snprintf(outstrptr, 15, "%.2s-%.2s-%.2s %.2s:%.2s", instr, instr+2, instr+4, instr+6, instr+8);
outstrptr+= 14;
if (len >= 12) {
if ((instr[i] >= '0') && (instr[i] <= '9')) {
i++;
if ((instr[i] >= '0') && (instr[i] <= '9')) {
i++;
g_snprintf(outstrptr, 4, ":%.2s", instr+10);
outstrptr+=3;
} else {
error_str = "BER Error: malformed UTCTime encoding, "
"if 11th octet is a digit for seconds, "
"the 12th octet has to be a digit, too";
goto malformed;
}
}
}
switch (instr[i]) {
case 'Z':
if (len != (i+1)) {
error_str = "BER Error: malformed UTCTime encoding, "
"there must be no further octets after \'Z\'";
goto malformed;
}
g_snprintf(outstrptr, 7, " (UTC)");
i++;
break;
case '-':
case '+':
if (len != (i+5)) {
error_str = "BER Error: malformed UTCTime encoding, "
"4 digits must follow on \'+\' resp. \'-\'";
goto malformed;
}
for (n=i+1; n<i+5; n++) {
if ((instr[n] < '0') || (instr[n] > '9')) {
error_str = "BER Error: malformed UTCTime encoding, "
"4 digits must follow on \'+\' resp. \'-\'";
goto malformed;
}
}
g_snprintf(outstrptr, 12, " (UTC%c%.4s)", instr[i], instr+i+1);
i+=5;
break;
default:
error_str = wmem_strdup_printf(wmem_packet_scope(),
"BER Error: malformed UTCTime encoding, "
"unexpected character in %dth octet, "
"must be \'Z\', \'+\' or \'-\'", i+1);
goto malformed;
break;
}
if (len != i) {
error_str = wmem_strdup_printf(wmem_packet_scope(),
"BER Error: malformed UTCTime encoding, %d unexpected character%s after %dth octet",
len - i,
(len == (i - 1) ? "s" : ""),
i);
goto malformed;
}
if (hf_id >= 0) {
proto_tree_add_string(tree, hf_id, tvb, offset, len, outstr);
}
return offset+len;
malformed:
if (hf_id >= 0) {
cause = proto_tree_add_string(tree, hf_id, tvb, offset, len, instr);
error_tree = proto_item_add_subtree(cause, ett_ber_unknown);
} else {
error_tree = tree;
}
cause = proto_tree_add_string_format(
error_tree, hf_ber_error, tvb, offset, len, "invalid_utctime",
"%s",
error_str);
expert_add_info(actx->pinfo, cause, &ei_ber_invalid_format_utctime);
return offset+len;
}
int
dissect_ber_constrained_bitstring(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *parent_tree, tvbuff_t *tvb, int offset, gint32 min_len, gint32 max_len, const asn_namedbit *named_bits, gint hf_id, gint ett_id, tvbuff_t **out_tvb)
{
gint8 ber_class;
gboolean pc, ind;
gint32 tag;
guint32 len, byteno;
guint8 pad = 0, b0, b1, val, *bitstring;
int end_offset;
int hoffset;
proto_item *item = NULL;
proto_item *cause;
proto_tree *tree = NULL;
const char *sep;
gboolean term;
const asn_namedbit *nb;
if (!implicit_tag) {
hoffset = offset;
offset = dissect_ber_identifier(actx->pinfo, parent_tree, tvb, offset, &ber_class, &pc, &tag);
offset = dissect_ber_length(actx->pinfo, parent_tree, tvb, offset, &len, &ind);
end_offset = offset + len;
if (!implicit_tag && (ber_class != BER_CLASS_APP)) {
if ( (ber_class != BER_CLASS_UNI)
|| (tag != BER_UNI_TAG_BITSTRING) ) {
tvb_ensure_bytes_exist(tvb, hoffset, 2);
cause = proto_tree_add_string_format_value(
parent_tree, hf_ber_error, tvb, offset, len, "bitstring_expected",
"BitString expected but class:%s(%d) %s tag:%d was unexpected",
val_to_str_const(ber_class, ber_class_codes, "Unknown"),
ber_class, pc ? ber_pc_codes_short.true_string : ber_pc_codes_short.false_string,
tag);
expert_add_info(actx->pinfo, cause, &ei_ber_expected_bitstring);
if (decode_unexpected) {
proto_tree *unknown_tree = proto_item_add_subtree(cause, ett_ber_unknown);
dissect_unknown_ber(actx->pinfo, tvb, hoffset, unknown_tree);
}
return end_offset;
}
}
} else {
pc=0;
len = tvb_reported_length_remaining(tvb, offset);
end_offset = offset+len;
}
if (len == 0) {
proto_tree_add_expert_format(
parent_tree, actx->pinfo, &ei_ber_constr_bitstr, tvb, offset, len,
"dissect_ber_constrained_bitstring(): frame:%u offset:%d Was passed an illegal length of 0",
actx->pinfo->num, offset);
return offset;
}
actx->created_item = NULL;
if (pc) {
} else {
pad = tvb_get_guint8(tvb, offset);
if ((pad == 0) && (len == 1)) {
proto_tree_add_item(parent_tree, hf_ber_bitstring_empty, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_item *pad_item = proto_tree_add_item(parent_tree, hf_ber_bitstring_padding, tvb, offset, 1, ENC_BIG_ENDIAN);
if (pad > 7) {
expert_add_info_format(
actx->pinfo, pad_item, &ei_ber_illegal_padding,
"Illegal padding (0 .. 7): %d", pad);
}
}
offset++;
len--;
if (hf_id >= 0) {
item = proto_tree_add_item(parent_tree, hf_id, tvb, offset, len, ENC_BIG_ENDIAN);
actx->created_item = item;
if (ett_id != -1) {
tree = proto_item_add_subtree(item, ett_id);
}
}
if (out_tvb) {
*out_tvb = ber_tvb_new_subset_length(tvb, offset, len);
}
}
if (named_bits) {
sep = " (";
term = FALSE;
nb = named_bits;
bitstring = (guint8 *)tvb_memdup(wmem_packet_scope(), tvb, offset, len);
while (nb->p_id) {
if ((len > 0) && (pad < 8*len) && (nb->bit < (8*len-pad))) {
val = tvb_get_guint8(tvb, offset + nb->bit/8);
bitstring[(nb->bit/8)] &= ~(0x80 >> (nb->bit%8));
val &= 0x80 >> (nb->bit%8);
b0 = (nb->gb0 == -1) ? nb->bit/8 :
((guint32)nb->gb0)/8;
b1 = (nb->gb1 == -1) ? nb->bit/8 :
((guint32)nb->gb1)/8;
proto_tree_add_item(tree, *(nb->p_id), tvb, offset + b0, b1 - b0 + 1, ENC_BIG_ENDIAN);
} else {
val = 0;
proto_tree_add_boolean(tree, *(nb->p_id), tvb, offset + len, 0, 0x00);
}
if (val) {
if (item && nb->tstr) {
proto_item_append_text(item, "%s%s", sep, nb->tstr);
sep = ", ";
term = TRUE;
}
} else {
if (item && nb->fstr) {
proto_item_append_text(item, "%s%s", sep, nb->fstr);
sep = ", ";
term = TRUE;
}
}
nb++;
}
if (term)
proto_item_append_text(item, ")");
for (byteno = 0; byteno < len; byteno++) {
if (bitstring[byteno]) {
expert_add_info_format(
actx->pinfo, item, &ei_ber_bits_unknown,
"Unknown bit(s): 0x%s", bytes_to_str(wmem_packet_scope(), bitstring, len));
break;
}
}
}
if ((pad > 0) && (pad < 8) && (len > 0)) {
guint8 bits_in_pad = tvb_get_guint8(tvb, offset + len - 1) & (0xFF >> (8-pad));
if (bits_in_pad) {
expert_add_info_format(
actx->pinfo, item, &ei_ber_bits_set_padded,
"Bits set in padded area: 0x%02x", bits_in_pad);
}
}
ber_check_length(8*len-pad, min_len, max_len, actx, item, TRUE);
return end_offset;
}
int
dissect_ber_bitstring(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *parent_tree, tvbuff_t *tvb, int offset, const asn_namedbit *named_bits, gint hf_id, gint ett_id, tvbuff_t **out_tvb)
{
return dissect_ber_constrained_bitstring(implicit_tag, actx, parent_tree, tvb, offset, -1, -1, named_bits, hf_id, ett_id, out_tvb);
}
int
dissect_ber_bitstring32(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *parent_tree, tvbuff_t *tvb, int offset, int **bit_fields, gint hf_id, gint ett_id, tvbuff_t **out_tvb)
{
tvbuff_t *tmp_tvb = NULL;
proto_tree *tree;
guint32 val;
int **bf;
header_field_info *hfi;
const char *sep;
gboolean term;
unsigned int i, tvb_len;
offset = dissect_ber_bitstring(implicit_tag, actx, parent_tree, tvb, offset, NULL, hf_id, ett_id, &tmp_tvb);
tree = proto_item_get_subtree(actx->created_item);
if (bit_fields && tree && tmp_tvb) {
val = 0;
tvb_len = tvb_reported_length(tmp_tvb);
for (i=0; i<4; i++) {
val <<= 8;
if (i < tvb_len) {
val |= tvb_get_guint8(tmp_tvb, i);
}
}
bf = bit_fields;
sep = " (";
term = FALSE;
while (*bf) {
if (**bf >= 0) {
proto_tree_add_boolean(tree, **bf, tmp_tvb, 0, tvb_len, val);
hfi = proto_registrar_get_nth(**bf);
if (val & hfi->bitmask) {
proto_item_append_text(actx->created_item, "%s%s", sep, hfi->name);
sep = ", ";
term = TRUE;
}
}
bf++;
}
if (term)
proto_item_append_text(actx->created_item, ")");
}
if (out_tvb)
*out_tvb = tmp_tvb;
return offset;
}
static int
dissect_ber_INTEGER(gboolean implicit_tag, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&actx->external.indirect_reference);
actx->external.indirect_ref_present = TRUE;
return offset;
}
static int
dissect_ber_T_octet_aligned(gboolean implicit_tag, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index)
{
if (actx->external.u.ber.ber_callback) {
offset = actx->external.u.ber.ber_callback(FALSE, tvb, offset, actx, tree, hf_index);
} else if (actx->external.direct_ref_present &&
dissector_get_string_handle(ber_oid_dissector_table, actx->external.direct_reference)) {
offset = call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
} else {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &actx->external.octet_aligned);
}
return offset;
}
static int
dissect_ber_OBJECT_IDENTIFIER(gboolean implicit_tag, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index)
{
DISSECTOR_ASSERT(actx);
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &actx->external.direct_reference);
actx->external.direct_ref_present = TRUE;
return offset;
}
static int
dissect_ber_ObjectDescriptor(gboolean implicit_tag, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index)
{
DISSECTOR_ASSERT(actx);
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_ObjectDescriptor,
actx, tree, tvb, offset, hf_index,
&actx->external.data_value_descriptor);
return offset;
}
static int
dissect_ber_T_single_ASN1_type(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index)
{
if (actx->external.u.ber.ber_callback) {
offset = actx->external.u.ber.ber_callback(FALSE, tvb, offset, actx, tree, hf_index);
} else {
offset = call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
}
return offset;
}
static int
dissect_ber_T_arbitrary(gboolean implicit_tag, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index)
{
if (actx->external.u.ber.ber_callback) {
offset = actx->external.u.ber.ber_callback(FALSE, tvb, offset, actx, tree, hf_index);
} else {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1, &actx->external.arbitrary);
}
return offset;
}
static int
dissect_ber_T_encoding(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_encoding_choice, hf_index, ett_ber_T_encoding,
&actx->external.encoding);
return offset;
}
static int
dissect_ber_external_U(gboolean implicit_tag, tvbuff_t *tvb, int offset, asn1_ctx_t *actx , proto_tree *tree, int hf_index)
{
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
external_U_sequence, hf_index, ett_ber_EXTERNAL);
return offset;
}
int
dissect_ber_external_type(gboolean implicit_tag, proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, gint hf_id, ber_callback func) {
actx->external.u.ber.ber_callback = func;
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_id, BER_CLASS_UNI, BER_UNI_TAG_EXTERNAL, TRUE, dissect_ber_external_U);
asn1_ctx_clean_external(actx);
return offset;
}
int
dissect_ber_EmbeddedPDV_Type(gboolean implicit_tag, proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, gint hf_id, ber_callback func _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_id, BER_CLASS_UNI, BER_UNI_TAG_EMBEDDED_PDV, TRUE, dissect_ber_external_U);
return offset;
}
static int
dissect_ber_syntax(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
return dissect_unknown_ber(pinfo, tvb, 0, tree);
}
static int
dissect_ber(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
const char *name;
int offset;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BER");
col_set_str(pinfo->cinfo, COL_DEF_SRC, "BER encoded file");
if (!decode_as_syntax) {
col_set_str(pinfo->cinfo, COL_INFO, "Unknown BER");
offset = dissect_unknown_ber(pinfo, tvb, 0, tree);
} else {
offset = call_ber_syntax_callback(decode_as_syntax, tvb, 0, pinfo, tree);
name = get_ber_oid_syntax(decode_as_syntax);
col_add_fstr(pinfo->cinfo, COL_INFO, "Decoded as %s", name ? name : decode_as_syntax);
}
return offset;
}
gboolean
oid_has_dissector(const char *oid) {
return(dissector_get_string_handle(ber_oid_dissector_table, oid) != NULL);
}
static void
ber_shutdown(void)
{
g_hash_table_destroy(syntax_table);
}
void
proto_register_ber(void)
{
static hf_register_info hf[] = {
{ &hf_ber_id_class, {
"Class", "ber.id.class", FT_UINT8, BASE_DEC,
VALS(ber_class_codes), 0xc0, "Class of BER TLV Identifier", HFILL }},
{ &hf_ber_bitstring_padding, {
"Padding", "ber.bitstring.padding", FT_UINT8, BASE_DEC,
NULL, 0x0, "Number of unused bits in the last octet of the bitstring", HFILL }},
{ &hf_ber_bitstring_empty, {
"Empty", "ber.bitstring.empty", FT_UINT8, BASE_DEC,
NULL, 0x0, "This is an empty bitstring", HFILL }},
{ &hf_ber_id_pc, {
"P/C", "ber.id.pc", FT_BOOLEAN, 8,
TFS(&ber_pc_codes), 0x20, "Primitive or Constructed BER encoding", HFILL }},
{ &hf_ber_id_uni_tag, {
"Tag", "ber.id.uni_tag", FT_UINT8, BASE_DEC|BASE_EXT_STRING,
&ber_uni_tag_codes_ext, 0x1f, "Universal tag type", HFILL }},
{ &hf_ber_id_uni_tag_ext, {
"Tag", "ber.id.uni_tag", FT_UINT32, BASE_DEC,
NULL, 0, "Universal tag type", HFILL }},
{ &hf_ber_id_tag, {
"Tag", "ber.id.tag", FT_UINT8, BASE_DEC,
NULL, 0x1f, "Tag value for non-Universal classes", HFILL }},
{ &hf_ber_id_tag_ext, {
"Tag", "ber.id.tag", FT_UINT32, BASE_DEC,
NULL, 0, "Tag value for non-Universal classes", HFILL }},
{ &hf_ber_length, {
"Length", "ber.length", FT_UINT32, BASE_DEC,
NULL, 0, "Length of contents", HFILL }},
{ &hf_ber_unknown_OCTETSTRING, {
"OCTETSTRING", "ber.unknown.OCTETSTRING", FT_BYTES, BASE_NONE,
NULL, 0, "This is an unknown OCTETSTRING", HFILL }},
{ &hf_ber_unknown_BER_OCTETSTRING, {
"OCTETSTRING [BER encoded]", "ber.unknown.OCTETSTRING", FT_NONE, BASE_NONE,
NULL, 0, "This is an BER encoded OCTETSTRING", HFILL }},
{ &hf_ber_unknown_BER_primitive, {
"Primitive [BER encoded]", "ber.unknown.primitive", FT_NONE, BASE_NONE,
NULL, 0, "This is a BER encoded Primitive", HFILL }},
{ &hf_ber_unknown_OID, {
"OID", "ber.unknown.OID", FT_OID, BASE_NONE,
NULL, 0, "This is an unknown Object Identifier", HFILL }},
{ &hf_ber_unknown_relative_OID, {
"OID", "ber.unknown.relative_OID", FT_REL_OID, BASE_NONE,
NULL, 0, "This is an unknown relative Object Identifier", HFILL }},
{ &hf_ber_unknown_GraphicString, {
"GRAPHICSTRING", "ber.unknown.GRAPHICSTRING", FT_STRING, BASE_NONE,
NULL, 0, "This is an unknown GRAPHICSTRING", HFILL }},
{ &hf_ber_unknown_NumericString, {
"NumericString", "ber.unknown.NumericString", FT_STRING, BASE_NONE,
NULL, 0, "This is an unknown NumericString", HFILL }},
{ &hf_ber_unknown_PrintableString, {
"PrintableString", "ber.unknown.PrintableString", FT_STRING, BASE_NONE,
NULL, 0, "This is an unknown PrintableString", HFILL }},
{ &hf_ber_unknown_TeletexString, {
"TeletexString", "ber.unknown.TeletexString", FT_STRING, BASE_NONE,
NULL, 0, "This is an unknown TeletexString", HFILL }},
{ &hf_ber_unknown_VisibleString, {
"VisibleString", "ber.unknown.VisibleString", FT_STRING, BASE_NONE,
NULL, 0, "This is an unknown VisibleString", HFILL }},
{ &hf_ber_unknown_GeneralString, {
"GeneralString", "ber.unknown.GeneralString", FT_STRING, BASE_NONE,
NULL, 0, "This is an unknown GeneralString", HFILL }},
{ &hf_ber_unknown_UniversalString, {
"UniversalString", "ber.unknown.UniversalString", FT_STRING, BASE_NONE,
NULL, 0, "This is an unknown UniversalString", HFILL }},
{ &hf_ber_unknown_BMPString, {
"BMPString", "ber.unknown.BMPString", FT_STRING, BASE_NONE,
NULL, 0, "This is an unknown BMPString", HFILL }},
{ &hf_ber_unknown_IA5String, {
"IA5String", "ber.unknown.IA5String", FT_STRING, BASE_NONE,
NULL, 0, "This is an unknown IA5String", HFILL }},
{ &hf_ber_unknown_UTCTime, {
"UTCTime", "ber.unknown.UTCTime", FT_STRING, BASE_NONE,
NULL, 0, "This is an unknown UTCTime", HFILL }},
{ &hf_ber_unknown_UTF8String, {
"UTF8String", "ber.unknown.UTF8String", FT_STRING, BASE_NONE,
NULL, 0, "This is an unknown UTF8String", HFILL }},
{ &hf_ber_unknown_GeneralizedTime, {
"GeneralizedTime", "ber.unknown.GeneralizedTime", FT_STRING, BASE_NONE,
NULL, 0, "This is an unknown GeneralizedTime", HFILL }},
{ &hf_ber_unknown_INTEGER, {
"INTEGER", "ber.unknown.INTEGER", FT_INT64, BASE_DEC,
NULL, 0, "This is an unknown INTEGER", HFILL }},
{ &hf_ber_unknown_REAL, {
"REAL", "ber.unknown.REAL", FT_DOUBLE, BASE_NONE,
NULL, 0, "This is an unknown REAL", HFILL }},
{ &hf_ber_unknown_BITSTRING, {
"BITSTRING", "ber.unknown.BITSTRING", FT_BYTES, BASE_NONE,
NULL, 0, "This is an unknown BITSTRING", HFILL }},
{ &hf_ber_unknown_BOOLEAN, {
"BOOLEAN", "ber.unknown.BOOLEAN", FT_UINT8, BASE_HEX,
NULL, 0, "This is an unknown BOOLEAN", HFILL }},
{ &hf_ber_unknown_ENUMERATED, {
"ENUMERATED", "ber.unknown.ENUMERATED", FT_UINT32, BASE_DEC,
NULL, 0, "This is an unknown ENUMERATED", HFILL }},
{ &hf_ber_error, {
"BER Error", "ber.error", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ber_direct_reference,
{ "direct-reference", "ber.direct_reference",
FT_OID, BASE_NONE, NULL, 0,
"ber.OBJECT_IDENTIFIER", HFILL }},
{ &hf_ber_indirect_reference,
{ "indirect-reference", "ber.indirect_reference",
FT_INT32, BASE_DEC, NULL, 0,
"ber.INTEGER", HFILL }},
{ &hf_ber_data_value_descriptor,
{ "data-value-descriptor", "ber.data_value_descriptor",
FT_STRING, BASE_NONE, NULL, 0,
"ber.ObjectDescriptor", HFILL }},
{ &hf_ber_encoding,
{ "encoding", "ber.encoding",
FT_UINT32, BASE_DEC, VALS(ber_T_encoding_vals), 0,
"ber.T_encoding", HFILL }},
{ &hf_ber_octet_aligned,
{ "octet-aligned", "ber.octet_aligned",
FT_BYTES, BASE_NONE, NULL, 0,
"ber.T_octet_aligned", HFILL }},
{ &hf_ber_arbitrary,
{ "arbitrary", "ber.arbitrary",
FT_BYTES, BASE_NONE, NULL, 0,
"ber.T_arbitrary", HFILL }},
{ &hf_ber_single_ASN1_type,
{ "single-ASN1-type", "ber.single_ASN1_type",
FT_NONE, BASE_NONE, NULL, 0,
"ber.T_single_ASN1_type", HFILL }},
{ &hf_ber_fragments,
{ "OCTET STRING fragments", "ber.octet_string.fragments", FT_NONE, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_ber_fragment,
{ "OCTET STRING fragment", "ber.octet_string.fragment", FT_FRAMENUM, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_ber_fragment_overlap,
{ "OCTET STRING fragment overlap", "ber.octet_string.fragment.overlap", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_ber_fragment_overlap_conflicts,
{ "OCTET STRING fragment overlapping with conflicting data",
"ber.octet_string.fragment.overlap.conflicts", FT_BOOLEAN, BASE_NONE, NULL,
0x0, NULL, HFILL } },
{ &hf_ber_fragment_multiple_tails,
{ "OCTET STRING has multiple tail fragments",
"ber.octet_string.fragment.multiple_tails", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL } },
{ &hf_ber_fragment_too_long_fragment,
{ "OCTET STRING fragment too long", "ber.octet_string.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL,
HFILL } },
{ &hf_ber_fragment_error,
{ "OCTET STRING defragmentation error", "ber.octet_string.fragment.error", FT_FRAMENUM,
BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_ber_fragment_count,
{ "OCTET STRING fragment count", "ber.octet_string.fragment.count", FT_UINT32, BASE_DEC,
NULL, 0x00, NULL, HFILL } },
{ &hf_ber_reassembled_in,
{ "Reassembled in", "ber.octet_string.reassembled.in", FT_FRAMENUM, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_ber_reassembled_length,
{ "Reassembled OCTET STRING length", "ber.octet_string.reassembled.length", FT_UINT32, BASE_DEC,
NULL, 0x00, NULL, HFILL } },
{ &hf_ber_null_tag, { "NULL tag", "ber.null_tag", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ber_unknown_data, { "Unknown Data", "ber.unknown_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ber_unknown_octetstring, { "Unknown OctetString", "ber.unknown_octetstring", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ber_seq_field_eoc, { "SEQ FIELD EOC", "ber.seq_field_eoc", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ber_seq_eoc, { "SEQ EOC", "ber.seq_eoc", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ber_set_field_eoc, { "SET FIELD EOC", "ber.set_field_eoc", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ber_set_eoc, { "SET EOC", "ber.set_eoc", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ber_choice_eoc, { "CHOICE EOC", "ber.choice_eoc", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ber_seq_of_eoc, { "SEQ OF EOC", "ber.seq_of_eoc", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ber_64bit_uint_as_bytes, { "64bits unsigned integer", "ber.64bit_uint_as_bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ber_octet_string,
&ett_ber_reassembled_octet_string,
&ett_ber_primitive,
&ett_ber_unknown,
&ett_ber_SEQUENCE,
&ett_ber_EXTERNAL,
&ett_ber_T_encoding,
&ett_ber_fragment,
&ett_ber_fragments
};
static ei_register_info ei[] = {
{ &ei_ber_size_constraint_string, { "ber.size_constraint.string", PI_PROTOCOL, PI_WARN, "Size constraint: string", EXPFILL }},
{ &ei_ber_size_constraint_value, { "ber.size_constraint.value", PI_PROTOCOL, PI_WARN, "Size constraint: values", EXPFILL }},
{ &ei_ber_size_constraint_items, { "ber.size_constraint.items", PI_PROTOCOL, PI_WARN, "Size constraint: items", EXPFILL }},
{ &ei_ber_sequence_field_wrong, { "ber.error.sequence.field_wrong", PI_MALFORMED, PI_WARN, "BER Error: Wrong field in SEQUENCE", EXPFILL }},
{ &ei_ber_expected_octet_string, { "ber.error.expected.octet_string", PI_MALFORMED, PI_WARN, "BER Error: OctetString expected", EXPFILL }},
{ &ei_ber_expected_null, { "ber.error.expected.null", PI_MALFORMED, PI_WARN, "BER Error: NULL expected", EXPFILL }},
{ &ei_ber_expected_null_zero_length, { "ber.error.expected.null_zero_length", PI_MALFORMED, PI_WARN, "BER Error: NULL expect zero length", EXPFILL }},
{ &ei_ber_expected_sequence, { "ber.error.expected.sequence", PI_MALFORMED, PI_WARN, "BER Error: Sequence expected", EXPFILL }},
{ &ei_ber_expected_set, { "ber.error.expected.set", PI_MALFORMED, PI_WARN, "BER Error: SET expected", EXPFILL }},
{ &ei_ber_expected_string, { "ber.error.expected.string", PI_MALFORMED, PI_WARN, "BER Error: String expected", EXPFILL }},
{ &ei_ber_expected_object_identifier, { "ber.error.expected.object_identifier", PI_MALFORMED, PI_WARN, "BER Error: Object Identifier expected", EXPFILL }},
{ &ei_ber_expected_generalized_time, { "ber.error.expected.generalized_time", PI_MALFORMED, PI_WARN, "BER Error: GeneralizedTime expected", EXPFILL }},
{ &ei_ber_expected_utc_time, { "ber.error.expected.utc_time", PI_MALFORMED, PI_WARN, "BER Error: UTCTime expected", EXPFILL }},
{ &ei_ber_expected_bitstring, { "ber.error.expected.bitstring", PI_MALFORMED, PI_WARN, "BER Error: BitString expected", EXPFILL }},
{ &ei_ber_error_length, { "ber.error.length", PI_MALFORMED, PI_WARN, "BER Error length", EXPFILL }},
{ &ei_ber_wrong_tag_in_tagged_type, { "ber.error.wrong_tag_in_tagged_type", PI_MALFORMED, PI_WARN, "BER Error: Wrong tag in tagged type", EXPFILL }},
{ &ei_ber_universal_tag_unknown, { "ber.error.universal_tag_unknown", PI_MALFORMED, PI_WARN, "BER Error: can not handle universal", EXPFILL }},
{ &ei_ber_no_oid, { "ber.error.no_oid", PI_MALFORMED, PI_WARN, "BER Error: No OID supplied to call_ber_oid_callback", EXPFILL }},
{ &ei_ber_oid_not_implemented, { "ber.error.oid_not_implemented", PI_UNDECODED, PI_WARN, "BER: Dissector for OID not implemented. Contact Wireshark developers if you want this supported", EXPFILL }},
{ &ei_ber_syntax_not_implemented, { "ber.error.syntax_not_implemented", PI_UNDECODED, PI_WARN, "BER: Syntax not implemented", EXPFILL }},
{ &ei_ber_value_too_many_bytes, { "ber.error.value_too_many_bytes", PI_MALFORMED, PI_WARN, "Value is encoded with too many bytes", EXPFILL }},
{ &ei_ber_unknown_field_sequence, { "ber.error.unknown_field.sequence", PI_MALFORMED, PI_WARN, "BER Error: Unknown field in Sequence", EXPFILL }},
{ &ei_ber_unknown_field_set, { "ber.error.unknown_field.set", PI_MALFORMED, PI_WARN, "BER Error: Unknown field in SET", EXPFILL }},
{ &ei_ber_missing_field_set, { "ber.error.missing_field.set", PI_MALFORMED, PI_WARN, "BER Error: Missing field in SET", EXPFILL }},
{ &ei_ber_empty_choice, { "ber.error.empty_choice", PI_MALFORMED, PI_WARN, "BER Error: Empty choice was found", EXPFILL }},
{ &ei_ber_choice_not_found, { "ber.error.choice_not_found", PI_MALFORMED, PI_WARN, "BER Error: This choice field was not found", EXPFILL }},
{ &ei_ber_bits_unknown, { "ber.error.bits_unknown", PI_UNDECODED, PI_WARN, "BER Error: Bits unknown", EXPFILL }},
{ &ei_ber_bits_set_padded, { "ber.error.bits_set_padded", PI_UNDECODED, PI_WARN, "BER Error: Bits set in padded area", EXPFILL }},
{ &ei_ber_illegal_padding, { "ber.error.illegal_padding", PI_UNDECODED, PI_WARN, "Illegal padding", EXPFILL }},
{ &ei_ber_invalid_format_generalized_time, { "ber.error.invalid_format.generalized_time", PI_MALFORMED, PI_WARN, "BER Error: GeneralizedTime invalid format", EXPFILL }},
{ &ei_ber_invalid_format_utctime, { "ber.error.invalid_format.utctime", PI_MALFORMED, PI_WARN, "BER Error: malformed UTCTime encoding", EXPFILL }},
{ &ei_hf_field_not_integer_type, { "ber.error.hf_field_not_integer_type", PI_PROTOCOL, PI_ERROR, "Was passed a HF field that was not integer type", EXPFILL }},
{ &ei_ber_constr_bitstr,{ "ber.error.constr_bitstr.len", PI_MALFORMED, PI_WARN, "BER Error: malformed Bitstring encoding", EXPFILL } },
};
static build_valid_func ber_da_build_value[1] = {ber_value};
static decode_as_value_t ber_da_values = {ber_prompt, 1, ber_da_build_value};
static decode_as_t ber_da = {"ber", "ASN.1", "ber.syntax", 1, 0, &ber_da_values, NULL, NULL,
ber_populate_list, ber_decode_as_reset, ber_decode_as_change, NULL};
module_t *ber_module;
expert_module_t* expert_ber;
uat_t* users_uat = uat_new("OID Tables",
sizeof(oid_user_t),
"oid",
FALSE,
&oid_users,
&num_oid_users,
UAT_AFFECTS_DISSECTION,
"ChObjectIdentifiers",
oid_copy_cb,
NULL,
oid_free_cb,
ber_update_oids,
NULL,
users_flds);
proto_ber = proto_register_protocol("Basic Encoding Rules (ASN.1 X.690)", "BER", "ber");
ber_handle = register_dissector("ber", dissect_ber, proto_ber);
proto_register_field_array(proto_ber, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ber = expert_register_protocol(proto_ber);
expert_register_field_array(expert_ber, ei, array_length(ei));
proto_set_cant_toggle(proto_ber);
ber_module = prefs_register_protocol(proto_ber, NULL);
prefs_register_bool_preference(ber_module, "show_internals",
"Show internal BER encapsulation tokens",
"Whether the dissector should also display internal"
" ASN.1 BER details such as Identifier and Length fields", &show_internal_ber_fields);
prefs_register_bool_preference(ber_module, "decode_unexpected",
"Decode unexpected tags as BER encoded data",
"Whether the dissector should decode unexpected tags as"
" ASN.1 BER encoded data", &decode_unexpected);
prefs_register_bool_preference(ber_module, "decode_octetstring",
"Decode OCTET STRING as BER encoded data",
"Whether the dissector should try decoding OCTET STRINGs as"
" constructed ASN.1 BER encoded data", &decode_octetstring_as_ber);
prefs_register_bool_preference(ber_module, "decode_primitive",
"Decode Primitive as BER encoded data",
"Whether the dissector should try decoding unknown primitive as"
" constructed ASN.1 BER encoded data", &decode_primitive_as_ber);
prefs_register_bool_preference(ber_module, "warn_too_many_bytes",
"Warn if too many leading zero bits in encoded data",
"Whether the dissector should warn if excessive leading zero (0) bits",
&decode_warning_leading_zero_bits);
prefs_register_uat_preference(ber_module, "oid_table", "Object Identifiers",
"A table that provides names for object identifiers"
" and the syntax of any associated values",
users_uat);
ber_oid_dissector_table = register_dissector_table("ber.oid", "BER OID", proto_ber, FT_STRING, BASE_NONE);
ber_syntax_dissector_table = register_dissector_table("ber.syntax", "BER syntax", proto_ber, FT_STRING, BASE_NONE);
syntax_table = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
register_ber_syntax_dissector("ASN.1", proto_ber, dissect_ber_syntax);
reassembly_table_register(&octet_segment_reassembly_table,
&addresses_reassembly_table_functions);
register_shutdown_routine(ber_shutdown);
register_decode_as(&ber_da);
}
void
proto_reg_handoff_ber(void)
{
guint i = 1;
oid_add_from_string("asn1", "2.1");
oid_add_from_string("basic-encoding", "2.1.1");
dissector_add_uint("wtap_encap", WTAP_ENCAP_BER, ber_handle);
ber_decode_as_foreach(ber_add_syntax_name, &i);
if (i > 1)
qsort(&syntax_names[1], i - 1, sizeof(value_string), cmp_value_string);
syntax_names[i].value = 0;
syntax_names[i].strptr = NULL;
dissector_add_for_decode_as_with_preference("tcp.port", ber_handle);
ber_update_oids();
}
