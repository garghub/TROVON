static gint msg_data_find(struct message_data *a, struct message_data *b)
{
if (a->fid == b->fid
&& a->frame == b->frame
&& a->msg_id == b->msg_id
&& a->smb_level == b->smb_level
&& a->is_request == b->is_request) {
return 0;
}
return 1;
}
static smb_fid_info_t *find_fid_info(smb_info_t *si)
{
smb_fid_info_t *fid_info = NULL;
smb_transact_info_t *tri = (smb_transact_info_t *)((si->sip && (si->sip->extra_info_type == SMB_EI_TRI)) ? si->sip->extra_info : NULL);
GSList *iter;
guint32 fid = 0;
if (tri == NULL) {
if (si->sip && (si->sip->extra_info_type == SMB_EI_RWINFO)) {
fid = si->sip->fid;
}
} else {
fid = tri->fid;
}
if (!fid) {
return NULL;
}
for (iter = si->ct->GSL_fid_info; iter; iter = iter->next) {
smb_fid_info_t *info = (smb_fid_info_t *)iter->data;
if ((info->tid == si->tid) && (info->fid == fid)) {
fid_info = info;
break;
}
}
return fid_info;
}
static gboolean get_fid_and_frame(packet_info *pinfo, guint32 *fid, guint *frame,
void *data)
{
gboolean result = TRUE;
int *p_smb_level = (int*)p_get_proto_data(wmem_file_scope(), pinfo, proto_mswsp, 0);
if (!p_smb_level) {
return FALSE;
}
*frame = pinfo->num;
if (*p_smb_level == SMB1) {
smb_info_t *si = (smb_info_t*)data;
smb_fid_info_t *info;
info = find_fid_info(si);
if (!info) {
return FALSE;
}
*fid = info->fid;
} else {
smb2_info_t *si2 = (smb2_info_t*)data;
guint32 open_frame = 0, close_frame = 0;
char *fid_name = NULL;
if (si2->saved) {
dcerpc_fetch_polhnd_data(&si2->saved->policy_hnd, &fid_name, NULL, &open_frame, &close_frame, pinfo->num);
*fid = open_frame;
} else {
result = FALSE;
}
}
return result;
}
static void
mswsp_init_protocol(void)
{
GSList *table_iter;
if (conv_tables) {
for(table_iter = conv_tables; table_iter;
table_iter = table_iter->next) {
struct mswsp_ct *ct = (struct mswsp_ct *)table_iter->data;
g_slist_free(ct->GSL_message_data);
g_free(ct);
}
g_slist_free(conv_tables);
conv_tables = NULL;
}
}
static struct message_data *find_or_create_message_data(struct mswsp_ct *conv_data, packet_info *pinfo, guint16 msg_id, gboolean is_request, void *data)
{
struct message_data to_find;
struct message_data* msg_data = NULL;
GSList *result = NULL;
int *p_smb_level = (int*)p_get_proto_data(wmem_file_scope(), pinfo, proto_mswsp, 0);
to_find.is_request = is_request;
to_find.msg_id = msg_id;
to_find.smb_level = *p_smb_level;
if (!get_fid_and_frame(pinfo, &to_find.fid, &to_find.frame, data) || !conv_data) {
return msg_data;
}
result = g_slist_find_custom(conv_data->GSL_message_data,
&to_find, (GCompareFunc)msg_data_find);
if (!result) {
msg_data = (struct message_data *)wmem_alloc(wmem_file_scope(), sizeof(struct message_data));
*msg_data = to_find;
conv_data->GSL_message_data = g_slist_prepend(conv_data->GSL_message_data, msg_data);
} else {
msg_data = (struct message_data*)result->data;
}
return msg_data;
}
static struct mswsp_ct *get_create_converstation_data(packet_info *pinfo)
{
struct mswsp_ct *ct = NULL;
conversation_t *conversation;
conversation = find_or_create_conversation(pinfo);
if (!conversation) {
goto out;
}
ct = (struct mswsp_ct*)conversation_get_proto_data(conversation, proto_mswsp);
if (!ct) {
ct = (struct mswsp_ct *)g_malloc(sizeof(struct mswsp_ct));
ct->GSL_message_data = NULL;
conv_tables = g_slist_prepend(conv_tables, ct);
conversation_add_proto_data(conversation, proto_mswsp, ct);
}
out:
return ct;
}
static struct message_data *
find_matching_request_by_fid(struct mswsp_ct *ct, packet_info *pinfo, guint32 msg, gboolean in, void *private_data)
{
guint32 fid = 0;
guint frame = 0;
GSList *iter;
int *p_smb_level = (int*)p_get_proto_data(wmem_file_scope(), pinfo, proto_mswsp, 0);
struct message_data *result = NULL;
get_fid_and_frame(pinfo, &fid, &frame, private_data);
for (iter = ct->GSL_message_data; iter; iter = iter->next) {
struct message_data* data = (struct message_data*)iter->data;
if (data->frame < frame && data->fid == fid && data->is_request == in
&& data->msg_id == msg && data->smb_level == *p_smb_level) {
result = data;
break;
}
}
return result;
}
static struct CPMSetBindingsIn *
find_binding_msg_data(struct mswsp_ct *ct, packet_info *pinfo, void *private_data)
{
struct CPMSetBindingsIn *result = NULL;
struct message_data *data = find_matching_request_by_fid(ct, pinfo, 0xD0, TRUE, private_data);
if (data) {
result = &data->content.bindingsin;
}
return result;
}
static struct rows_data *
find_rowsin_msg_data(struct mswsp_ct *ct, packet_info *pinfo, void *private_data)
{
struct rows_data *result = NULL;
struct message_data *data = find_matching_request_by_fid(ct, pinfo, 0xCC, TRUE, private_data);
if (data) {
result = &data->content.rowsin;
}
return result;
}
static gboolean is_64bit_mode(struct mswsp_ct *ct, packet_info *pinfo, gboolean *result, void *private_data)
{
guint32 client_ver = 0;
guint32 server_ver = 0;
struct message_data *data = find_matching_request_by_fid(ct, pinfo, 0xC8,
TRUE, private_data);
if (data) {
client_ver = data->content.version;
data = find_matching_request_by_fid(ct, pinfo, 0xC8, FALSE, private_data);
if (data) {
server_ver = data->content.version;
*result = (server_ver & 0xffff0000) && (client_ver & 0xffff0000);
return TRUE;
}
}
return FALSE;
}
static struct GuidPropertySet *GuidPropertySet_find_guid(const e_guid_t *guid)
{
unsigned i;
for (i=0; i<array_length(GuidPropertySet); i++) {
if (guid_cmp(&GuidPropertySet[i].guid, guid) == 0) {
return &GuidPropertySet[i];
}
}
return NULL;
}
static void get_name_from_fullpropspec(struct CFullPropSpec *v, char *out, int bufsize)
{
struct GuidPropertySet *pset = GuidPropertySet_find_guid(&v->guid);
const char *id_str, *guid_str;
char *dest = out;
id_str = pset ? try_val_to_str(v->u.propid, pset->id_map) : NULL;
if (id_str) {
g_snprintf(dest, bufsize, "%s", id_str);
} else {
guid_str = guids_get_guid_name(&v->guid);
if (guid_str) {
g_snprintf(dest, bufsize, "\"%s\"", guid_str);
} else {
guid_str = guid_to_str(wmem_packet_scope(), &v->guid);
g_snprintf(dest, bufsize, "{%s}", guid_str);
}
if (v->kind == PRSPEC_LPWSTR) {
g_snprintf(dest, bufsize, "%s \"%s\"", guid_str, v->u.name);
} else if (v->kind == PRSPEC_PROPID) {
g_snprintf(dest, bufsize, "%s 0x%08x", guid_str, v->u.propid);
} else {
g_snprintf(dest, bufsize, "%s <INVALID>", dest);
}
}
}
static int parse_uin32_array(tvbuff_t *tvb, int offset, proto_tree *tree, guint32 count, const char *fmt, ...)
{
guint32 v, i;
proto_item *item;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
proto_tree_add_subtree(tree, tvb, offset, count * 4, ett_mswsp_uin32_array, &item, txt);
proto_item_append_text(item, " count %u [", count);
for (i=0; i<count; i++) {
v = tvb_get_letohl(tvb, offset);
offset += 4;
if (i>0) {
proto_item_append_text(item, ",%u", v);
} else {
proto_item_append_text(item, "%u", v);
}
}
proto_item_append_text(item, "]");
return offset;
}
static int parse_padding(tvbuff_t *tvb, int offset, int alignment, proto_tree *pad_tree, const char *fmt, ...)
{
if (offset % alignment) {
const int padding = alignment - (offset % alignment);
const char *txt;
va_list ap;
proto_item *ti;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
proto_tree_add_subtree(pad_tree, tvb, offset, padding, ett_mswsp_msg_padding, &ti, txt);
va_end(ap);
proto_item_append_text(ti, " (%d)", padding);
offset += padding;
}
DISSECTOR_ASSERT((offset % alignment) == 0);
return offset;
}
static int parse_guid(tvbuff_t *tvb, int offset, proto_tree *tree, e_guid_t *guid, const char *text)
{
const char *guid_str, *name, *bytes;
proto_tree *tr;
tvb_get_letohguid(tvb, offset, guid);
guid_str = guid_to_str(wmem_packet_scope(), guid);
name = guids_get_guid_name(guid);
tr = proto_tree_add_subtree_format(tree, tvb, offset, 16, ett_GUID, NULL, "%s: %s {%s}", text, name ? name : "", guid_str);
proto_tree_add_item(tr, hf_mswsp_guid_time_low, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tr, hf_mswsp_guid_time_mid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tr, hf_mswsp_guid_time_high, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tr, hf_mswsp_guid_time_clock_hi, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tr, hf_mswsp_guid_time_clock_low, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
bytes = bytestring_to_str(wmem_packet_scope(), &guid->data4[2], 6, ':');
proto_tree_add_string(tr, hf_mswsp_guid_node, tvb, offset, 6, bytes);
offset += 6;
return offset;
}
static int parse_lcid(tvbuff_t *tvb, int offset, proto_tree *parent_tree, const char *text)
{
proto_item *item;
proto_tree *tree;
guint32 lcid;
lcid = tvb_get_letohl(tvb, offset);
item = proto_tree_add_uint_format(parent_tree, hf_mswsp_lcid, tvb, offset, 4, lcid, "%s: 0x%x", text, lcid);
tree = proto_item_add_subtree(item, ett_LCID);
proto_tree_add_uint(tree, hf_mswsp_lcid_langid, tvb, offset + 2, 2, lcid);
proto_tree_add_uint(tree, hf_mswsp_lcid_sortid, tvb, offset + 1, 1, (lcid >> 16) & 0xF);
offset += 4;
return offset;
}
static int parse_CSort(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree _U_, const char *fmt, ...)
{
guint32 col, ord, ind;
proto_item *item;
proto_tree *tree;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CSort, &item, txt);
col = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_cscort_column, tvb, offset, 4, col);
offset += 4;
ord = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_cscort_order, tvb, offset, 4, ord);
offset += 4;
ind = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_cscort_individual, tvb, offset, 4, ind);
offset += 4;
offset = parse_lcid(tvb, offset, tree, "lcid");
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CSortSet(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
guint32 count, i;
proto_item *item;
proto_tree *tree;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CSortSet, &item, txt);
count = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_cscortset_count, tvb, offset, 4, count);
offset += 4;
for (i=0; i<count; i++) {
offset = parse_padding(tvb, offset, 4, tree, "padding_sortArray[%u]", i);
offset = parse_CSort(tvb, offset, tree, pad_tree, "sortArray[%u]", i);
}
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CTableColumn(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, struct CTableColumn *col, const char *fmt, ...)
{
static const value_string DBAGGTTYPE[] = {
{0x0, "DBAGGTTYPE_BYNONE"},
{0x1, "DBAGGTTYPE_SUM"},
{0x2, "DBAGGTTYPE_MAX"},
{0x3, "DBAGGTTYPE_MIN"},
{0x4, "DBAGGTTYPE_AVG"},
{0x5, "DBAGGTTYPE_COUNT"},
{0x6, "DBAGGTTYPE_CHILDCOUNT"},
{0x7, "DBAGGTTYPE_BYFREQ"},
{0x8, "DBAGGTTYPE_FIRST"},
{0x9, "DBAGGTTYPE_DATERANGE"},
{0xA, "DBAGGTTYPE_REPRESENTATIVEOF"},
{0xB, "DBAGGTTYPE_EDITDISTANCE"},
{0, NULL}
};
proto_item *item;
proto_tree *tree;
va_list ap;
struct vtype_data *type;
enum vType vtype_val = VT_EMPTY;
enum vType vtype_valhi = VT_EMPTY;
struct CFullPropSpec v;
const char *txt;
guint8 used;
const char *modifier = "";
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CTableColumn, &item, txt);
offset = parse_CFullPropSpec(tvb, offset, tree, pad_tree, &v, "PropSpec");
get_name_from_fullpropspec(&v, col->name, PROP_LENGTH);
col->vtype = tvb_get_letohl(tvb, offset);
vtype_val = (enum vType)col->vtype;
vtype_valhi = (enum vType)(col->vtype & 0xFF00);
if (vtype_valhi) {
if (vtype_valhi == VT_VECTOR) {
modifier = "|VT_VECTOR";
} else if (vtype_valhi == VT_ARRAY) {
modifier = "|VT_ARRAY";
} else {
modifier = "|(Unknown, possibly error)";
}
}
type = vType_get_type(vtype_val);
DISSECTOR_ASSERT(type != NULL);
proto_tree_add_string_format_value(tree, hf_mswsp_ctablecolumn_vtype, tvb, offset, 4, type->str, "%s%s", type->str, modifier);
offset += 4;
used = tvb_get_guint8(tvb, offset);
col->aggregateused = used;
proto_tree_add_uint(tree, hf_mswsp_ctablecolumn_aggused, tvb, offset, 1, used);
offset += 1;
if (used) {
col->aggregatetype = tvb_get_guint8(tvb, offset);
proto_tree_add_string(tree, hf_mswsp_ctablecolumn_aggtype, tvb, offset, 1, val_to_str(col->aggregatetype, DBAGGTTYPE, "(Unknown: 0x%x)"));
offset += 1;
}
col->valueused = tvb_get_guint8(tvb, offset);
used = col->valueused;
proto_tree_add_uint(tree, hf_mswsp_ctablecolumn_valused, tvb, offset, 1, used);
offset += 1;
if (used) {
offset = parse_padding(tvb, offset, 2, pad_tree, "padding_Value");
col->valueoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_ctablecolumn_valoffset, tvb, offset, 2, col->valueoffset);
offset += 2;
col->valuesize = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_ctablecolumn_valsize, tvb, offset, 2, col->valuesize);
offset += 2;
}
used = tvb_get_guint8(tvb, offset);
col->statusused = used;
proto_tree_add_uint(tree, hf_mswsp_ctablecolumn_statused, tvb, offset, 2, used);
offset += 1;
if (used) {
offset = parse_padding(tvb, offset, 2, pad_tree, "padding_Status");
col->statusoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_ctablecolumn_statoffset, tvb, offset, 2, col->statusoffset);
offset += 2;
}
used = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_ctablecolumn_lenused, tvb, offset, 2, used);
col->lengthused = used;
offset += 1;
if (used) {
offset = parse_padding(tvb, offset, 2, pad_tree, "padding_Lenght");
col->lengthoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_ctablecolumn_lenoffset, tvb, offset, 2, col->lengthoffset);
offset += 2;
}
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_PRSPEC_Kind(tvbuff_t *tvb, int offset, proto_tree *tree, enum PRSPEC_Kind *prspec)
{
static const value_string KIND[] = {
{0, "PRSPEC_LPWSTR"},
{1, "PRSPEC_PROPID"},
{0, NULL}
};
gint32 kind = tvb_get_letohl(tvb, offset);
DISSECTOR_ASSERT(kind < (PRSPEC_PROPID + 1));
if (kind) {
*prspec = PRSPEC_PROPID;
} else {
*prspec = PRSPEC_LPWSTR;
}
proto_tree_add_string(tree, hf_mswsp_cfullpropspec_kind, tvb, offset, 4, val_to_str(*prspec, KIND, "(Unknown: 0x%x)"));
offset += 4;
return offset;
}
static int parse_CFullPropSpec(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, struct CFullPropSpec *v, const char *fmt, ...)
{
struct GuidPropertySet *pset;
const char *id_str, *guid_str, *txt;
proto_item *item;
proto_tree *tree;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CFullPropSpec, &item, txt);
offset = parse_padding(tvb, offset, 8, pad_tree, "paddingPropSet");
offset = parse_guid(tvb, offset, tree, &v->guid, "GUID");
pset = GuidPropertySet_find_guid(&v->guid);
offset = parse_PRSPEC_Kind(tvb, offset, tree, &v->kind);
v->u.propid = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_cfullpropspec_propid, tvb, offset, 4, v->u.propid);
offset += 4;
if (v->kind == PRSPEC_LPWSTR) {
int len = 2*v->u.propid;
v->u.name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_LITTLE_ENDIAN | ENC_UCS_2);
proto_tree_add_string(tree, hf_mswsp_cfullpropspec_propname, tvb, offset, len, v->u.name);
offset += len;
}
id_str = pset ? try_val_to_str(v->u.propid, pset->id_map) : NULL;
if (id_str) {
proto_item_append_text(item, ": %s", id_str);
} else {
guid_str = guids_get_guid_name(&v->guid);
if (guid_str) {
proto_item_append_text(item, ": \"%s\"", guid_str);
} else {
guid_str = guid_to_str(wmem_packet_scope(), &v->guid);
proto_item_append_text(item, ": {%s}", guid_str);
}
if (v->kind == PRSPEC_LPWSTR) {
proto_item_append_text(item, " \"%s\"", v->u.name);
} else if (v->kind == PRSPEC_PROPID) {
proto_item_append_text(item, " 0x%08x", v->u.propid);
} else {
proto_item_append_text(item, " <INVALID>");
}
}
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_relop(tvbuff_t *tvb, int offset, proto_tree *tree, guint32 *relop, const char **str)
{
const char *str1 = NULL, *str2 = NULL;
guint32 tmp = tvb_get_letohl(tvb, offset);
guint32 modifier = (tmp & 0xF00);
DISSECTOR_ASSERT((tmp & 0xf) < PRSomeBits +1);
switch(tmp & 0xf) {
case PRLT:
*relop = PRLT;
break;
case PRLE:
*relop = PRLE;
break;
case PRGT:
*relop = PRGT;
break;
case PRGE:
*relop = PRGE;
break;
case PREQ:
*relop = PREQ;
break;
case PRNE:
*relop = PRNE;
break;
case PRRE:
*relop = PRRE;
break;
case PRAllBits:
*relop = PRAllBits;
break;
case PRSomeBits:
*relop = PRSomeBits;
break;
default:
break;
}
str2 = val_to_str(*relop, PR_VALS, "0x%04x");
if (modifier) {
switch (modifier) {
case PRAll:
*relop = *relop | PRAll;
break;
case PRAny:
*relop |= PRAny;
break;
default:
DISSECTOR_ASSERT(FALSE);
break;
}
str1 = try_val_to_str((modifier), PR_VALS);
if (str1) {
str1 = wmem_strdup_printf(wmem_packet_scope(), "%s | ", str1);
str2 = wmem_strdup_printf(wmem_packet_scope(), "%s%s", str1, str2);
}
}
proto_tree_add_string_format_value(tree, hf_mswsp_cproprestrict_relop, tvb, offset, 4, str2, "%s (0x%04x)", str2[0]=='\0' ? "" : str2, *relop);
if (str) {
*str = str2;
}
return offset + 4;
}
static int parse_CPropertyRestriction(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, struct CPropertyRestriction *v, const char *fmt, ...)
{
proto_tree *tree;
proto_item *item;
const char *txt, *str = NULL;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CPropertyRestriction, &item, txt);
offset = parse_relop(tvb, offset, tree, &v->relop, &str);
proto_item_append_text(item, " Op: %s", str);
offset = parse_CFullPropSpec(tvb, offset, tree, pad_tree, &v->property, "Property");
offset = parse_CBaseStorageVariant(tvb, offset, tree, pad_tree, &v->prval, "prval");
offset = parse_padding(tvb, offset, 4, pad_tree, "padding_lcid");
v->lcid = tvb_get_letohl(tvb, offset);
offset = parse_lcid(tvb, offset, tree, "lcid");
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CCoercionRestriction(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, struct CCoercionRestriction *v, const char *fmt, ...)
{
proto_tree *tree;
proto_item *item;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CCoercionRestriction, &item, txt);
v->value = tvb_get_letohieee_float(tvb, offset);
proto_tree_add_float(tree, hf_mswsp_ccoercerestrict_value, tvb, offset, 4, v->value);
offset += 4;
offset = parse_CRestriction(tvb, offset, tree, pad_tree, &v->child, "child");
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CContentRestriction(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, struct CContentRestriction *v, const char *fmt, ...)
{
proto_tree *tree;
proto_item *item;
va_list ap;
guint32 cc;
const char *str, *txt;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CContentRestriction, &item, txt);
offset = parse_CFullPropSpec(tvb, offset, tree, pad_tree, &v->property, "Property");
offset = parse_padding(tvb, offset, 4, pad_tree, "Padding1");
cc = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_ccontentrestrict_cc, tvb, offset, 4, cc);
offset += 4;
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 2*cc, ENC_LITTLE_ENDIAN | ENC_UCS_2);
v->phrase = str;
proto_tree_add_string(tree, hf_mswsp_ccontentrestrict_phrase, tvb, offset, 2*cc, str);
offset += 2*cc;
offset = parse_padding(tvb, offset, 4, pad_tree, "Padding2");
v->lcid = tvb_get_letohl(tvb, offset);
offset = parse_lcid(tvb, offset, tree, "lcid");
v->method = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_ccontentrestrict_method, tvb, offset, 4, v->method);
offset += 4;
proto_item_set_end(item, tvb, offset);
return offset;
}
int parse_CNatLanguageRestriction(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, struct CNatLanguageRestriction *v, const char *fmt, ...)
{
proto_tree *tree;
proto_item *item;
va_list ap;
guint32 cc;
const char *str, *txt;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CNatLanguageRestriction, &item, txt);
offset = parse_CFullPropSpec(tvb, offset, tree, pad_tree, &v->property, "Property");
offset = parse_padding(tvb, offset, 4, pad_tree, "padding_cc");
cc = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_natlangrestrict_cc, tvb, offset, 4, cc);
offset += 4;
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 2*cc, ENC_LITTLE_ENDIAN | ENC_UCS_2);
v->phrase = str;
proto_tree_add_string(tree, hf_mswsp_natlangrestrict_phrase, tvb, offset, 2*cc, str);
offset += 2*cc;
offset = parse_padding(tvb, offset, 4, pad_tree, "padding_lcid");
v->lcid = tvb_get_letohl(tvb, offset);
offset = parse_lcid(tvb, offset, tree, "lcid");
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CReuseWhere(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree _U_, struct CReuseWhere *v, const char *fmt, ...)
{
proto_item *item;
va_list ap;
const char *txt;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_mswsp_msg_creusewhere, &item, txt);
v->whereId = tvb_get_letohl(tvb, offset);
offset += 4;
proto_item_append_text(item, " Id: %u", v->whereId);
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_rType(tvbuff_t *tvb, int offset, proto_tree *tree, enum rType *rtype, const char **str)
{
const char *txt = NULL;
guint32 type = tvb_get_letohl(tvb, offset);
switch(type) {
case RTNone:
*rtype = RTNone;
break;
case RTAnd:
*rtype = RTAnd;
break;
case RTOr:
*rtype = RTOr;
break;
case RTNot:
*rtype = RTNot;
break;
case RTContent:
*rtype = RTContent;
break;
case RTProperty:
*rtype = RTProperty;
break;
case RTProximity:
*rtype = RTProximity;
break;
case RTVector:
*rtype = RTVector;
break;
case RTNatLanguage:
*rtype = RTNatLanguage;
break;
case RTScope:
*rtype = RTScope;
break;
case RTCoerce_Add:
*rtype = RTCoerce_Add;
break;
case RTCoerce_Multiply:
*rtype = RTCoerce_Multiply;
break;
case RTCoerce_Absolute:
*rtype = RTCoerce_Absolute;
break;
case RTProb:
*rtype = RTProb;
break;
case RTFeedback:
*rtype = RTFeedback;
break;
case RTReldoc:
*rtype = RTReldoc;
break;
case RTReuseWhere:
*rtype = RTReuseWhere;
break;
case RTInternalProp:
*rtype = RTInternalProp;
break;
default:
DISSECTOR_ASSERT(FALSE);
break;
}
txt = val_to_str(*rtype, RT_VALS, "0x%.8x");
proto_tree_add_string_format_value(tree, hf_mswsp_crestrict_ultype, tvb, offset, 4, txt, "%s (0x%.8x)", txt[0] == '0' ? "" : txt, *rtype);
if (str) {
*str = txt;
}
return offset + 4;
}
static int parse_CRestriction(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, struct CRestriction *v, const char *fmt, ...)
{
proto_tree *tree;
proto_item *item;
const char *str, *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CRestriction, &item, txt);
offset = parse_rType(tvb, offset, tree, &v->ulType, &str);
proto_item_append_text(item, " Type: %s", str);
v->Weight = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_crestrict_weight, tvb, offset, 4, v->Weight);
offset += 4;
switch(v->ulType) {
case RTNone:
break;
case RTAnd:
case RTOr:
case RTProximity:
case RTPhrase: {
v->u.RTAnd = EP_ALLOC(struct CNodeRestriction);
offset = parse_CNodeRestriction(tvb, offset, tree, pad_tree, v->u.RTAnd, "CNodeRestriction");
break;
}
case RTNot: {
v->u.RTNot = EP_ALLOC(struct CRestriction);
offset = parse_CRestriction(tvb, offset, tree, pad_tree,
v->u.RTNot, "CRestriction");
break;
}
case RTProperty: {
v->u.RTProperty = EP_ALLOC(struct CPropertyRestriction);
offset = parse_CPropertyRestriction(tvb, offset, tree, pad_tree,
v->u.RTProperty, "CPropertyRestriction");
break;
}
case RTCoerce_Add:
case RTCoerce_Multiply:
case RTCoerce_Absolute: {
v->u.RTCoerce_Add = EP_ALLOC(struct CCoercionRestriction);
offset = parse_CCoercionRestriction(tvb, offset, tree, pad_tree,
v->u.RTCoerce_Add, "CCoercionRestriction");
break;
}
case RTContent: {
v->u.RTContent = EP_ALLOC(struct CContentRestriction);
offset = parse_CContentRestriction(tvb, offset, tree, pad_tree,
v->u.RTContent, "CContentRestriction");
break;
}
case RTReuseWhere: {
v->u.RTReuseWhere = EP_ALLOC(struct CReuseWhere);
offset = parse_CReuseWhere(tvb, offset, tree, pad_tree,
v->u.RTReuseWhere, "CReuseWhere");
break;
}
case RTNatLanguage: {
v->u.RTNatLanguage = EP_ALLOC(struct CNatLanguageRestriction);
offset = parse_CNatLanguageRestriction(tvb, offset, tree, pad_tree,
v->u.RTNatLanguage, "CNatLanguageRestriction");
break;
}
default:
proto_item_append_text(item, " Not supported!");
}
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CRestrictionArray(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
guint8 present, count;
proto_tree *tree;
proto_item *item;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CRestrictionArray, &item, txt);
pad_tree = tree;
count = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_crestrictarray_count, tvb, offset, 1, count);
offset += 1;
present = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_crestrictarray_present, tvb, offset, 1, present);
offset += 1;
if (present) {
unsigned i;
offset = parse_padding(tvb, offset, 4, pad_tree, "paddingCRestrictionPresent");
for (i=0; i<count; i++) {
struct CRestriction r;
offset = parse_CRestriction(tvb, offset, tree, pad_tree, &r, "Restriction[%d]", i);
}
}
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CNodeRestriction(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, struct CNodeRestriction *v, const char *fmt, ...)
{
proto_tree *tree;
proto_item *item;
unsigned i;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CNodeRestriction, &item, txt);
v->cNode = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_cnoderestrict_cnode, tvb, offset, 4, v->cNode);
offset += 4;
for (i=0; i<v->cNode; i++) {
struct CRestriction r;
ZERO_STRUCT(r);
offset = parse_CRestriction(tvb, offset, tree, pad_tree, &r, "paNode[%u]", i);
offset = parse_padding(tvb, offset, 4, tree, "padding_paNode[%u]", i);
}
proto_item_set_end(item, tvb, offset);
return offset;
}
static int vvalue_tvb_get0(tvbuff_t *tvb _U_, int offset _U_, void *val _U_)
{
return 0;
}
static int vvalue_tvb_get1(tvbuff_t *tvb, int offset, void *val)
{
guint8 *ui1 = (guint8*)val;
*ui1 = tvb_get_guint8(tvb, offset);
return 1;
}
static int vvalue_tvb_get2(tvbuff_t *tvb, int offset, void *val)
{
guint16 *ui2 = (guint16*)val;
*ui2 = tvb_get_letohs(tvb, offset);
return 2;
}
static int vvalue_tvb_get4(tvbuff_t *tvb, int offset, void *val)
{
guint32 *ui4 = (guint32*)val;
*ui4 = tvb_get_letohl(tvb, offset);
return 4;
}
static int vvalue_tvb_get8(tvbuff_t *tvb, int offset, void *val)
{
guint64 *ui8 = (guint64*)val;
*ui8 = tvb_get_letoh64(tvb, offset);
return 8;
}
static int vvalue_tvb_blob(tvbuff_t *tvb, int offset, void *val)
{
struct data_blob *blob = (struct data_blob*)val;
guint32 len = tvb_get_letohl(tvb, offset);
blob->size = len;
blob->data = (guint8*)tvb_memdup(wmem_packet_scope(), tvb, offset + 4, len);
return 4 + len;
}
static int vvalue_tvb_lpstr(tvbuff_t *tvb, int offset, void *val)
{
struct data_str *str = (struct data_str*)val;
gint len;
str->len = tvb_get_letohl(tvb, offset);
str->str = tvb_get_stringz_enc(wmem_packet_scope(), tvb, offset + 4, &len,
ENC_ASCII|ENC_LITTLE_ENDIAN);
return 4 + len;
}
static int vvalue_tvb_lpwstr_len(tvbuff_t *tvb, int offset, int length, void *val)
{
struct data_str *str = (struct data_str*)val;
const gchar *ptr;
int len;
if (length == 0) {
ptr = tvb_get_stringz_enc(wmem_packet_scope(), tvb, offset, &len,
ENC_UTF_16|ENC_LITTLE_ENDIAN);
} else {
ptr = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, length,
ENC_UTF_16|ENC_LITTLE_ENDIAN);
len = length;
}
str->str = ptr;
return len;
}
static int vvalue_tvb_lpwstr(tvbuff_t *tvb, int offset, void *val)
{
struct data_str *str = (struct data_str*)val;
str->len = tvb_get_letohl(tvb, offset);
return 4 + vvalue_tvb_lpwstr_len(tvb, offset + 4, 0, val);
}
static int vvalue_tvb_vector_internal(tvbuff_t *tvb, int offset, struct vt_vector *val, struct vtype_data *type, guint num)
{
const int offset_in = offset;
const gboolean varsize = (type->size == -1);
const guint elsize = varsize ? (guint)sizeof(struct data_blob) : (guint)type->size;
guint8 *data;
int len;
guint i;
if ((guint64)elsize * (guint64)num > G_MAXUINT) {
THROW(ReportedBoundsError);
}
tvb_ensure_bytes_exist(tvb, offset, elsize * num);
data = (guint8*)wmem_alloc(wmem_packet_scope(), elsize * num);
val->len = num;
val->u.vt_ui1 = data;
DISSECTOR_ASSERT((void*)&val->u == ((void*)&val->u.vt_ui1));
for (i=0; i<num; i++) {
DISSECTOR_ASSERT_HINT(type->tvb_get != 0,
"type that we don't know yet how to handle, please submit a bug with trace");
len = type->tvb_get(tvb, offset, data);
data += elsize;
offset += len;
if (varsize && (offset % 4) ) {
int padding = 4 - (offset % 4);
offset += padding;
}
}
return offset - offset_in;
}
static int vvalue_tvb_vector(tvbuff_t *tvb, int offset, struct vt_vector *val, struct vtype_data *type)
{
const guint num = tvb_get_letohl(tvb, offset);
return 4 + vvalue_tvb_vector_internal(tvb, offset+4, val, type, num);
}
static void vvalue_strbuf_append_null(wmem_strbuf_t *strbuf _U_, void *ptr _U_)
{}
static void vvalue_strbuf_append_i1(wmem_strbuf_t *strbuf, void *ptr)
{
gint8 i1 = *(gint8*)ptr;
wmem_strbuf_append_printf(strbuf, "%d", (int)i1);
}
static void vvalue_strbuf_append_i2(wmem_strbuf_t *strbuf, void *ptr)
{
gint16 i2 = *(gint16*)ptr;
wmem_strbuf_append_printf(strbuf, "%d", (int)i2);
}
static void vvalue_strbuf_append_i4(wmem_strbuf_t *strbuf, void *ptr)
{
gint32 i4 = *(gint32*)ptr;
wmem_strbuf_append_printf(strbuf, "%d", i4);
}
static void vvalue_strbuf_append_i8(wmem_strbuf_t *strbuf, void *ptr)
{
gint64 i8 = *(gint64*)ptr;
wmem_strbuf_append_printf(strbuf, "%" G_GINT64_MODIFIER "d", i8);
}
static void vvalue_strbuf_append_ui1(wmem_strbuf_t *strbuf, void *ptr)
{
guint8 ui1 = *(guint8*)ptr;
wmem_strbuf_append_printf(strbuf, "%u", (unsigned)ui1);
}
static void vvalue_strbuf_append_ui2(wmem_strbuf_t *strbuf, void *ptr)
{
guint16 ui2 = *(guint16*)ptr;
wmem_strbuf_append_printf(strbuf, "%u", (unsigned)ui2);
}
static void vvalue_strbuf_append_ui4(wmem_strbuf_t *strbuf, void *ptr)
{
guint32 ui4 = *(guint32*)ptr;
wmem_strbuf_append_printf(strbuf, "%d", ui4);
}
static void vvalue_strbuf_append_ui8(wmem_strbuf_t *strbuf, void *ptr)
{
guint64 ui8 = *(guint64*)ptr;
wmem_strbuf_append_printf(strbuf, "%" G_GINT64_MODIFIER "u", ui8);
}
static void vvalue_strbuf_append_r4(wmem_strbuf_t *strbuf, void *ptr)
{
float r4 = *(float*)ptr;
wmem_strbuf_append_printf(strbuf, "%g", (double)r4);
}
static void vvalue_strbuf_append_r8(wmem_strbuf_t *strbuf, void *ptr)
{
double r8 = *(double*)ptr;
wmem_strbuf_append_printf(strbuf, "%g", r8);
}
static void vvalue_strbuf_append_str(wmem_strbuf_t *strbuf, void *ptr)
{
struct data_str *str = (struct data_str*)ptr;
wmem_strbuf_append_printf(strbuf, "\"%s\"", str->str);
}
static void vvalue_strbuf_append_blob(wmem_strbuf_t *strbuf, void *ptr)
{
struct data_blob *blob = (struct data_blob*)ptr;
wmem_strbuf_append_printf(strbuf, "size: %d", (int)blob->size);
}
static void vvalue_strbuf_append_bool(wmem_strbuf_t *strbuf, void *ptr)
{
guint16 val = *(guint*)ptr;
switch (val) {
case 0:
wmem_strbuf_append(strbuf, "False");
break;
case 0xffff:
wmem_strbuf_append(strbuf, "True");
break;
default:
wmem_strbuf_append_printf(strbuf, "Invalid (0x%4x)", val);
}
}
static void vvalue_strbuf_append_vector(wmem_strbuf_t *strbuf, struct vt_vector val, struct vtype_data *type)
{
const int elsize = (type->size == -1) ? (int)sizeof(struct data_blob) : type->size;
unsigned i;
guint8 *data = val.u.vt_ui1;
wmem_strbuf_append_c(strbuf, '[');
for (i=0; i<val.len; i++) {
if (i>0) {
wmem_strbuf_append_c(strbuf, ',');
}
type->strbuf_append(strbuf, data);
data += elsize;
}
wmem_strbuf_append_c(strbuf, ']');
}
static struct vtype_data *vType_get_type(guint16 t)
{
unsigned i;
t = (t & 0xFF);
for (i=0; i<array_length(VT_TYPE); i++) {
if (t == VT_TYPE[i].tag) {
return &VT_TYPE[i];
}
}
return NULL;
}
static const char *str_CBaseStorageVariant(struct CBaseStorageVariant *value, gboolean print_type)
{
wmem_strbuf_t *strbuf = wmem_strbuf_new(wmem_packet_scope(), "");
if (value == NULL) {
return "<NULL>";
}
if (value->type == NULL) {
return "<??""?>";
}
if (print_type) {
wmem_strbuf_append(strbuf, value->type->str);
if (value->vType & 0xFF00) {
wmem_strbuf_append_printf(strbuf, "[%d]", value->vValue.vt_vector.len);
}
wmem_strbuf_append(strbuf, ": ");
}
switch (value->vType & 0xFF00) {
case 0:
value->type->strbuf_append(strbuf, &value->vValue);
break;
case VT_ARRAY:
vvalue_strbuf_append_vector(strbuf, value->vValue.vt_array.vData, value->type);
break;
case VT_VECTOR:
vvalue_strbuf_append_vector(strbuf, value->vValue.vt_vector, value->type);
break;
default:
wmem_strbuf_append(strbuf, "Invalid");
}
return wmem_strbuf_get_str(strbuf);
}
static int parse_vType(tvbuff_t *tvb, int offset, guint16 *vtype)
{
guint16 tmp_vtype = tvb_get_letohs(tvb, offset);
guint16 modifier = tmp_vtype & 0xFF00;
switch (tmp_vtype & 0xFF) {
case VT_EMPTY:
*vtype = VT_EMPTY;
break;
case VT_NULL:
*vtype = VT_NULL;
break;
case VT_I2:
*vtype = VT_I2;
break;
case VT_I4:
*vtype = VT_I4;
break;
case VT_R4:
*vtype = VT_R4;
break;
case VT_R8:
*vtype = VT_R8;
break;
case VT_CY:
*vtype = VT_CY;
break;
case VT_DATE:
*vtype = VT_DATE;
break;
case VT_BSTR:
*vtype = VT_BSTR;
break;
case VT_ERROR:
*vtype = VT_ERROR;
break;
case VT_BOOL:
*vtype = VT_BOOL;
break;
case VT_VARIANT:
*vtype = VT_VARIANT;
break;
case VT_DECIMAL:
*vtype = VT_DECIMAL;
break;
case VT_I1:
*vtype = VT_I1;
break;
case VT_UI1:
*vtype = VT_UI1;
break;
case VT_UI2:
*vtype = VT_UI2;
break;
case VT_UI4:
*vtype = VT_UI4;
break;
case VT_I8:
*vtype = VT_I8;
break;
case VT_UI8:
*vtype = VT_UI8;
break;
case VT_INT:
*vtype = VT_INT;
break;
case VT_UINT:
*vtype = VT_UINT;
break;
case VT_LPSTR:
*vtype = VT_LPSTR;
break;
case VT_LPWSTR:
*vtype = VT_LPWSTR;
break;
case VT_COMPRESSED_LPWSTR:
*vtype = VT_COMPRESSED_LPWSTR;
break;
case VT_FILETIME:
*vtype = VT_FILETIME;
break;
case VT_BLOB:
*vtype = VT_BLOB;
break;
case VT_BLOB_OBJECT:
*vtype = VT_BLOB_OBJECT;
break;
case VT_CLSID:
*vtype = VT_CLSID;
break;
default:
DISSECTOR_ASSERT(FALSE);
break;
}
if (modifier) {
switch (modifier) {
case VT_VECTOR:
*vtype |= VT_VECTOR;
break;
case VT_ARRAY:
*vtype |= VT_ARRAY;
break;
default:
DISSECTOR_ASSERT(FALSE);
break;
}
}
return offset + 2;
}
static int parse_CBaseStorageVariant(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree _U_, struct CBaseStorageVariant *value, const char *text)
{
int i, len;
proto_item *ti, *ti_type, *ti_val;
proto_tree *tree, *tr;
enum vType highType;
ZERO_STRUCT(*value);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CBaseStorageVariant, &ti, text);
parse_vType(tvb, offset, &value->vType);
value->type = vType_get_type(value->vType);
DISSECTOR_ASSERT(value->type != NULL);
ti_type = proto_tree_add_string(tree, hf_mswsp_cbasestorvariant_vtype, tvb, offset, 2, value->type->str);
offset += 2;
value->vData1 = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_cbasestorvariant_vdata1, tvb, offset, 1, value->vData1);
offset += 1;
value->vData2 = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_cbasestorvariant_vdata2, tvb, offset, 1, value->vData2);
offset += 1;
highType = (enum vType)(value->vType & 0xFF00);
if (value->type == NULL) {
goto not_supported;
}
ti_val = proto_tree_add_string(tree, hf_mswsp_cbasestorvariant_vvalue, tvb, offset, 0, "");
switch (highType) {
case VT_EMPTY:
DISSECTOR_ASSERT_HINT(value->type->tvb_get != 0,
"type that we don't know yet how to handle, please submit a bug with trace");
len = value->type->tvb_get(tvb, offset, &value->vValue.vt_single);
offset += len;
break;
case VT_VECTOR:
proto_item_append_text(ti_type, "|VT_VECTOR");
tr = proto_item_add_subtree(ti_val, ett_CBaseStorageVariant_Vector);
len = vvalue_tvb_vector(tvb, offset, &value->vValue.vt_vector, value->type);
proto_tree_add_uint(tr, hf_mswsp_cbasestorvariant_num, tvb, offset, 4, value->vValue.vt_vector.len);
offset += len;
break;
case VT_ARRAY: {
guint16 cDims, fFeatures;
guint32 cbElements, cElements, lLbound;
int num = 1;
proto_item_append_text(ti_type, "|VT_ARRAY");
tr = proto_item_add_subtree(ti_val, ett_CBaseStorageVariant_Array);
cDims = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tr, hf_mswsp_cbasestorvariant_cdims, tvb, offset, 2, cDims);
offset += 2;
fFeatures = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tr, hf_mswsp_cbasestorvariant_ffeatures, tvb, offset, 2, fFeatures);
offset += 2;
cbElements = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tr, hf_mswsp_cbasestorvariant_cbelements, tvb, offset, 4, cbElements);
offset += 4;
for (i=0; i<cDims; i++) {
cElements = tvb_get_letohl(tvb, offset);
lLbound = tvb_get_letohl(tvb, offset + 4);
proto_tree_add_string_format(tr, hf_mswsp_cbasestorvariant_rgsabound, tvb, offset, 8, "", "Rgsabound[%d]: (%d:%d)", i, cElements, lLbound);
offset += 8;
num *= cElements;
}
len = vvalue_tvb_vector_internal(tvb, offset, &value->vValue.vt_array.vData, value->type, num);
offset += len;
break;
}
default:
proto_item_append_text(ti_type, "|0x%x", highType);
}
proto_item_set_end(ti, tvb, offset);
proto_item_set_end(ti_val, tvb, offset);
proto_item_append_text(ti_val, " %s", str_CBaseStorageVariant(value, FALSE));
proto_item_append_text(ti, " %s", str_CBaseStorageVariant(value, TRUE));
goto done;
not_supported:
proto_item_append_text(ti, ": sorry, vType %02x not handled yet!", (unsigned)value->vType);
done:
return offset;
}
static int parse_CDbColId(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *text)
{
guint32 eKind, ulId;
e_guid_t guid;
const char *str;
static const char *KIND[] = {"DBKIND_GUID_NAME", "DBKIND_GUID_PROPID"};
proto_item *tree_item;
proto_tree *tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CDbColId, &tree_item, text);
eKind = tvb_get_letohl(tvb, offset);
str = (eKind < 2 ? KIND[eKind] : "???");
proto_tree_add_string_format_value(tree, hf_mswsp_cdbcolid_ekind, tvb, offset, 4, str, "%s (%u)", str, eKind);
offset += 4;
offset = parse_padding(tvb, offset, 8, pad_tree, "paddingGuidAlign");
offset = parse_guid(tvb, offset, tree, &guid, "GUID");
ulId = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_cdbcolid_ulid, tvb, offset, 4, ulId);
offset += 4;
if (eKind == DBKIND_GUID_NAME) {
char *name;
int len = ulId;
name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_LITTLE_ENDIAN | ENC_UCS_2);
proto_item_append_text(tree_item, " \"%s\"", name);
proto_tree_add_string_format_value(tree, hf_mswsp_cdbcolid_vstring, tvb, offset, len, name, "\"%s\"", name);
offset += len;
} else if (eKind == DBKIND_GUID_PROPID) {
proto_item_append_text(tree_item, " %08x", ulId);
} else {
proto_item_append_text(tree_item, "<INVALID>");
}
proto_item_set_end(tree_item, tvb, offset);
return offset;
}
static int parse_CDbProp(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, struct GuidPropertySet *propset, const char *fmt, ...)
{
static const value_string EMPTY_VS[] = {{0, NULL}};
const value_string *vs = (propset && propset->id_map) ? propset->id_map : EMPTY_VS;
guint32 id, opt, status;
struct CBaseStorageVariant value;
proto_item *item;
proto_tree *tree;
const char *str, *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CDbProp, &item, txt);
id = tvb_get_letohl(tvb, offset);
str = val_to_str(id, vs, "0x%08x");
proto_tree_add_string_format_value(tree, hf_mswsp_cdbprop_id, tvb, offset, 4, str, "%s (0x%08x)", (str[0] == '0' ? "" : str), id);
offset += 4;
proto_item_append_text(item, " Id: %s", str);
opt = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_cdbprop_options, tvb, offset, 4, opt);
offset += 4;
status = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_cdbprop_status, tvb, offset, 4, status);
offset += 4;
offset = parse_CDbColId(tvb, offset, tree, pad_tree, "colid");
offset = parse_CBaseStorageVariant(tvb, offset, tree, pad_tree, &value, "vValue");
str = str_CBaseStorageVariant(&value, TRUE);
proto_item_append_text(item, " %s", str);
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CDbPropSet(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
int i, num;
e_guid_t guid;
struct GuidPropertySet *pset;
proto_item *item;
proto_tree *tree;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CDbPropSet, &item, txt);
offset = parse_guid(tvb, offset, tree, &guid, "guidPropertySet");
pset = GuidPropertySet_find_guid(&guid);
if (pset) {
proto_item_append_text(item, " \"%s\" (%s)", pset->desc, pset->def);
} else {
const char *guid_str = guid_to_str(wmem_packet_scope(), &guid);
proto_item_append_text(item, " {%s}", guid_str);
}
offset = parse_padding(tvb, offset, 4, pad_tree, "guidPropertySet");
num = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_cdbpropset_cprops, tvb, offset, 4, num);
offset += 4;
proto_item_append_text(item, " Num: %d", num);
for (i = 0; i<num; i++) {
offset = parse_padding(tvb, offset, 4, pad_tree, "aProp[%d]", i);
offset = parse_CDbProp(tvb, offset, tree, pad_tree, pset, "aProp[%d]", i);
}
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_PropertySetArray(tvbuff_t *tvb, int offset, int size_offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
const int offset_in = offset;
guint32 size, num;
int i;
proto_tree *tree;
proto_item *item;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CDbPropSet_Array, &item, txt);
size = tvb_get_letohl(tvb, size_offset);
proto_tree_add_item(tree, hf_mswsp_msg_ConnectIn_Blob1, tvb,
size_offset, 4, ENC_LITTLE_ENDIAN);
num = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_mswsp_msg_ConnectIn_PropSets_num, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
for (i = 0; i < (int)num; i++) {
offset = parse_CDbPropSet(tvb, offset, tree, pad_tree, "PropertySet[%d]", i);
}
proto_item_set_end(item, tvb, offset);
DISSECTOR_ASSERT(offset - offset_in == (int)size);
return offset;
}
int parse_CColumnSet(tvbuff_t *tvb, int offset, proto_tree *tree, const char *fmt, ...)
{
guint32 count, v, i;
proto_item *item;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
count = tvb_get_letohl(tvb, offset);
offset += 4;
proto_tree_add_subtree(tree, tvb, offset, count * 4, ett_mswsp_uin32_array, &item, txt);
proto_item_append_text(item, " Count %u [", count);
for (i=0; i<count; i++) {
v = tvb_get_letohl(tvb, offset);
offset += 4;
if (i>0) {
proto_item_append_text(item, ",%u", v);
} else {
proto_item_append_text(item, "%u", v);
}
}
proto_item_append_text(item, "]");
return offset;
}
int parse_RANGEBOUNDARY(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
guint32 ulType;
guint8 labelPresent;
proto_item *item;
proto_tree *tree;
const char *txt;
struct CBaseStorageVariant prval;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree =proto_tree_add_subtree (parent_tree, tvb, offset, 0, ett_RANGEBOUNDARY, &item, txt);
ulType = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_mswsp_rangeboundry_ultype, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, ": Type 0x%08x", ulType);
offset += 4;
ZERO_STRUCT(prval);
offset = parse_CBaseStorageVariant(tvb, offset, tree, pad_tree, &prval, "prVal");
labelPresent = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mswsp_rangeboundry_labelpresent, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (labelPresent) {
guint32 ccLabel;
offset = parse_padding(tvb, offset, 4, pad_tree, "paddingLabelPresent");
ccLabel = tvb_get_letohl(tvb, offset);
proto_tree_add_item_ret_uint(tree, hf_mswsp_rangeboundry_cclabel, tvb, offset, 4, ENC_LITTLE_ENDIAN, &ccLabel);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_rangeboundry_label, tvb, offset, 2*ccLabel, ENC_LITTLE_ENDIAN | ENC_UCS_2);
proto_item_append_text(item, " Label: \"%s\"", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 2*ccLabel, ENC_LITTLE_ENDIAN | ENC_UCS_2));
offset += 2*ccLabel;
}
proto_item_append_text(item, " Val: %s", str_CBaseStorageVariant(&prval, TRUE));
proto_item_set_end(item, tvb, offset);
return offset;
}
int parse_CRangeCategSpec(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
proto_item *item;
proto_tree *tree;
va_list ap;
unsigned i;
const char *txt;
guint32 cRange;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CRangeCategSpec, &item, txt);
offset = parse_lcid(tvb, offset, tree, "lcid");
cRange = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_crangecategspec_crange, tvb, offset, 4, cRange);
offset += 4;
for (i=0; i<cRange; i++) {
offset = parse_RANGEBOUNDARY(tvb, offset, tree, pad_tree, "aRangeBegin[%u]", i);
}
proto_item_set_end(item, tvb, offset);
return offset;
}
int parse_CCategSpec(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
proto_item *item;
proto_tree *tree;
va_list ap;
guint32 type;
const char *txt;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CCategSpec, &item, txt);
type = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_ccategspec_type, tvb, offset, 4, type);
proto_item_append_text(item, " Type %u", type);
offset += 4;
offset = parse_CSort(tvb, offset, tree, pad_tree, "CSort");
offset = parse_CRangeCategSpec(tvb, offset, tree, pad_tree, "CRangeCategSpec");
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CAggregSpec(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
proto_item *item;
proto_tree *tree;
va_list ap;
guint8 type;
guint32 ccAlias, idColumn;
const char *alias, *txt;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CAggregSpec, &item, txt);
type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_caggregspec_type, tvb, offset, 1, type);
proto_item_append_text(item, "type: %u", type);
offset += 1;
offset = parse_padding(tvb, offset, 4, pad_tree, "padding");
ccAlias = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_caggregspec_ccalias, tvb, offset, 1, ccAlias);
offset += 4;
alias = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 2*ccAlias, ENC_LITTLE_ENDIAN | ENC_UCS_2);
proto_tree_add_string(tree, hf_mswsp_caggregspec_alias, tvb, offset, 2*ccAlias, alias);
offset += 2*ccAlias;
idColumn = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_caggregspec_idcolumn, tvb, offset, 1, idColumn);
offset += 4;
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CAggregSet(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
guint32 cCount, i;
proto_item *item;
proto_tree *tree;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CAggregSet, &item, txt);
cCount = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_caggregset_count, tvb, offset, 4, cCount);
offset += 4;
for (i=0; i<cCount; i++) {
offset = parse_CAggregSpec(tvb, offset, tree, pad_tree, "AggregSpecs[%u]", i);
}
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CAggregSortKey(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
guint32 order;
proto_item *item;
proto_tree *tree;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CAggregSortKey, &item, txt);
order = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_caggregsortkey_order, tvb, offset, 4, order);
offset += 4;
offset = parse_CAggregSpec(tvb, offset, tree, pad_tree, "ColumnSpec");
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CSortAggregSet(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
guint32 cCount, i;
proto_item *item;
proto_tree *tree;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CSortAggregSet, &item, txt);
cCount = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_csortaggregset_count, tvb, offset, 4, cCount);
offset += 4;
for (i=0; i<cCount; i++) {
offset = parse_CAggregSortKey(tvb, offset, tree, pad_tree, "SortKeys[%u]", i);
}
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CInGroupSortAggregSet_type(tvbuff_t *tvb, int offset, proto_tree *tree, enum CInGroupSortAggregSet_type *type)
{
guint8 tmp = tvb_get_guint8(tvb, offset);
switch(tmp) {
case GroupIdDefault:
*type = GroupIdDefault;
break;
case GroupIdMinValue:
*type = GroupIdMinValue;
break;
case GroupIdNull:
*type = GroupIdNull;
break;
case GroupIdValue:
*type = GroupIdValue;
break;
default:
DISSECTOR_ASSERT(FALSE);
break;
}
proto_tree_add_uint(tree, hf_mswsp_cingroupsortaggregset_type, tvb, offset, 1, *type);
return offset + 1;
}
static int parse_CInGroupSortAggregSet(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
proto_item *item;
proto_tree *tree;
va_list ap;
enum CInGroupSortAggregSet_type type;
const char *txt;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CInGroupSortAggregSet, &item, txt);
offset = parse_CInGroupSortAggregSet_type(tvb, offset, tree, &type);
offset = parse_padding(tvb, offset, 4, pad_tree, "CInGroupSortAggregSet");
if (type == GroupIdValue) {
struct CBaseStorageVariant id;
offset = parse_CBaseStorageVariant(tvb, offset, tree, pad_tree, &id, "inGroupId");
}
offset = parse_CSortAggregSet(tvb, offset, tree, pad_tree, "SortAggregSet");
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CInGroupSortAggregSets(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
guint32 cCount, i;
proto_item *item;
proto_tree *tree;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CInGroupSortAggregSets, &item, txt);
cCount = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_cingroupsortaggregsets_count, tvb, offset, 4, cCount);
offset += 4;
for (i=0; i<cCount; i++) {
offset = parse_CInGroupSortAggregSet(tvb, offset, tree, pad_tree, "SortSets[%u]", i);
}
proto_item_set_end(item, tvb, offset);
return offset;
}
int parse_CCategorizationSpec(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
proto_item *item;
proto_tree *tree;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CCategorizationSpec, &item, txt);
offset = parse_CColumnSet(tvb, offset, tree, "csColumns");
offset = parse_CCategSpec(tvb, offset, tree, pad_tree, "Spec");
offset = parse_CAggregSet(tvb, offset, tree, pad_tree, "AggregSet");
offset = parse_CSortAggregSet(tvb, offset, tree, pad_tree, "SortAggregSet");
offset = parse_CInGroupSortAggregSets(tvb, offset, tree, pad_tree, "InGroupSortAggregSets");
proto_tree_add_item(tree, hf_mswsp_categorizationspec_cmaxres, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_item_set_end(item, tvb, offset);
return offset;
}
int parse_CRowsetProperties(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree _U_, const char *fmt, ...)
{
proto_item *item;
proto_tree *tree;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CRowsetProperties, &item, txt);
proto_tree_add_bitmask_with_flags(tree, tvb, offset,
hf_mswsp_bool_options, ett_mswsp_bool_options, mswsp_bool_options, ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_crowsetprops_ulmaxopenrows, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_crowsetprops_ulmemusage, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_crowsetprops_cmaxresults, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_crowsetprops_ccmdtimeout, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_item_set_end(item, tvb, offset);
return offset;
}
int parse_CPidMapper(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
proto_item *item;
proto_tree *tree;
va_list ap;
guint32 count, i;
const char *txt;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CPidMapper, &item, txt);
count = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_cpidmapper_count, tvb, offset, 4, count);
offset += 4;
offset = parse_padding(tvb, offset, 8, pad_tree, "CPidMapper_PropSpec");
for (i=0; i<count; i++) {
struct CFullPropSpec v;
ZERO_STRUCT(v);
offset = parse_padding(tvb, offset, 4, pad_tree,
"CPidMapper_PropSpec[%u]", i);
offset = parse_CFullPropSpec(tvb, offset, tree, pad_tree, &v, "PropSpec[%u]", i);
}
proto_item_set_end(item, tvb, offset);
return offset;
}
int parse_CColumnGroup(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree _U_, const char *fmt, ...)
{
proto_tree *tree;
proto_item *item, *ti;
va_list ap;
const char *txt;
guint32 count, groupPid, i;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CColumnGroup, &item, txt);
count = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_ccolumngroup_count, tvb, offset, 4, count);
offset += 4;
groupPid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_uint(tree, hf_mswsp_ccolumngroup_grouppid, tvb, offset, 4, groupPid);
if ((0xFFFF0000 & groupPid) == 0x7FFF0000) {
proto_item_append_text(ti, " Idx: %u", groupPid & 0xFFFF);
} else {
proto_item_append_text(ti, "<Invalid>");
}
offset += 4;
for (i=0; i<count; i++) {
guint32 pid, weight;
pid = tvb_get_letohl(tvb, offset);
weight = tvb_get_letohl(tvb, offset + 4);
proto_tree_add_uint_format(tree, hf_mswsp_ccolumngroup_pid, tvb, offset, 8, pid, "Props[%u]: pid: %u weight: %u", i, pid, weight);
offset += 8;
}
proto_item_set_end(item, tvb, offset);
return offset;
}
int parse_CColumnGroupArray(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, const char *fmt, ...)
{
proto_tree *tree;
proto_item *item;
va_list ap;
const char *txt;
guint32 count, i;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CColumnGroupArray, &item, txt);
count = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_ccolumngrouparray_count, tvb, offset, 4, count);
offset += 4;
for (i=0; i<count; i++) {
offset = parse_padding(tvb, offset, 4, pad_tree, "aGroupArray[%u]", i);
offset = parse_CColumnGroup(tvb, offset, tree, pad_tree, "aGroupArray[%u]", i);
}
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_UInt32Array(tvbuff_t *tvb, int offset, proto_tree *parent_tree, guint32 count, const char *item_name, const char *fmt, ...)
{
guint32 v, i;
proto_tree *tree;
proto_item *item;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_Array, &item, txt);
for (i=0; i<count; i++) {
v = tvb_get_letohl(tvb, offset);
proto_tree_add_uint_format(tree, hf_mswsp_int32array_value, tvb, offset, 4, v, "%s[%u] = %u", item_name,i, v);
offset += 4;
}
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CRowSeekNext(tvbuff_t *tvb, int offset, proto_tree *parent_tree, const char *fmt, ...)
{
proto_tree *tree;
proto_item *item;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CRowsSeekNext, &item, txt);
proto_tree_add_item(tree, hf_mswsp_crowseeknext_cskip, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CRowSeekAt(tvbuff_t *tvb, int offset, proto_tree *parent_tree, const char *fmt, ...)
{
proto_tree *tree;
proto_item *item;
va_list ap;
const char *txt;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CRowsSeekAt, &item, txt);
proto_tree_add_item(tree, hf_mswsp_crowseekat_bmkoffset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_crowseekat_skip, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_crowseekat_hregion, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CRowSeekAtRatio(tvbuff_t *tvb, int offset, proto_tree *parent_tree, const char *fmt, ...)
{
proto_tree *tree;
proto_item *item;
va_list ap;
const char *txt;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CRowsSeekAtRatio, &item, txt);
proto_tree_add_item(tree, hf_mswsp_crowseekatratio_ulnumerator, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_crowseekatratio_uldenominator, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_crowseekatratio_hregion, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_item_set_end(item, tvb, offset);
return offset;
}
static int parse_CRowSeekByBookmark(tvbuff_t *tvb, int offset, proto_tree *parent_tree, const char *fmt, ...)
{
proto_tree *tree;
proto_item *item;
guint32 num;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CRowsSeekByBookmark, &item, txt);
num = tvb_get_letohl(tvb,offset);
proto_tree_add_item(tree, hf_mswsp_crowseekbybookmark_cbookmarks, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = parse_UInt32Array(tvb, offset, tree, num, "abookmark", "abookmarks");
num = tvb_get_letohl(tvb,offset);
proto_tree_add_item(tree, hf_mswsp_crowseekbybookmark_maxret, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = parse_UInt32Array(tvb, offset, tree, num, "ascret", "ascret");
proto_item_set_end(item, tvb, offset);
return offset;
}
static int get_fixed_vtype_dataize(enum vType vtype)
{
struct vtype_data *vt_type = vType_get_type(vtype);
if (vt_type) {
return vt_type->size;
}
return -1;
}
static int parse_CRowVariantArrayInfo(tvbuff_t *tvb, int offset, proto_tree *tree, gboolean is_64bit, struct CRowVariant *variant)
{
if (is_64bit) {
variant->content.array_vector.i64.count =
tvb_get_letoh64(tvb, offset);
proto_tree_add_uint64(tree, hf_mswsp_crowvariantinfo_count64, tvb, offset, 8, variant->content.array_vector.i64.count);
offset += 8;
variant->content.array_vector.i64.array_address = tvb_get_letoh64(tvb, offset);
proto_tree_add_uint64(tree, hf_mswsp_arrayvector_address64, tvb, offset, 8, variant->content.array_vector.i64.array_address);
offset += 8;
} else {
variant->content.array_vector.i32.count =
tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_crowvariantinfo_count32, tvb, offset, 4, variant->content.array_vector.i32.count );
offset += 4;
variant->content.array_vector.i32.array_address = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_arrayvector_address32, tvb, offset, 4, variant->content.array_vector.i32.array_address);
offset += 4;
}
return offset;
}
static int parse_VariantColVector(tvbuff_t *tvb, int offset, proto_tree *tree, guint64 base_address, gboolean is_64bit, struct CRowVariant *variant)
{
guint32 i = 0;
guint64 count = 0;
int buf_offset = 0;
proto_tree *sub_tree;
struct vtype_data *vt_list_type =
vType_get_type((enum vType)(variant->vtype & 0x00FF));
wmem_strbuf_t *strbuf;
DISSECTOR_ASSERT(vt_list_type != NULL);
offset = parse_CRowVariantArrayInfo(tvb, offset, tree, is_64bit, variant);
if (is_64bit) {
buf_offset =
(int)(variant->content.array_vector.i64.array_address - base_address);
count = variant->content.array_vector.i64.count;
} else {
buf_offset =
(int)(variant->content.array_vector.i32.array_address - base_address);
count = variant->content.array_vector.i32.count;
}
sub_tree = proto_tree_add_subtree(tree, tvb, buf_offset, 0, ett_CRowVariant_Vector, NULL, "values");
for (i = 0; i < count; i++) {
guint64 item_address = 0;
int size;
union vt_single value;
int len;
if (is_64bit) {
size = 8;
item_address = tvb_get_letoh64(tvb, buf_offset + (i * size));
proto_tree_add_uint64_format(sub_tree, hf_mswsp_rowvariant_item_address64, tvb, buf_offset, size, item_address, "address[%d] 0x%" G_GINT64_MODIFIER "x", i, item_address);
} else {
size = 4;
item_address = tvb_get_letohl(tvb, buf_offset + (i * size));
proto_tree_add_uint_format(sub_tree, hf_mswsp_rowvariant_item_address32, tvb, buf_offset, size, (guint32)item_address, "address[%d] 0x%x", i, (guint32)item_address);
}
strbuf = wmem_strbuf_new(wmem_packet_scope(), "");
if (vt_list_type->size == -1) {
DISSECTOR_ASSERT_HINT(vt_list_type->tvb_get_value_only != 0,
"appears this is a vector of dynamic types that we don't know yet how to handle, please submit a bug with trace");
len = vt_list_type->tvb_get_value_only(tvb, (int)(item_address - base_address), 0, &value);
vt_list_type->strbuf_append(strbuf, &value);
} else {
len = vt_list_type->size;
DISSECTOR_ASSERT_HINT(vt_list_type->tvb_get != 0,
"appears this is a vector of fixed types that we don't know yet how to handle, please submit a bug with trace");
vt_list_type->tvb_get(tvb, (int)(item_address - base_address), &value);
vt_list_type->strbuf_append(strbuf, &value);
}
proto_tree_add_string(sub_tree, hf_mswsp_rowvariant_item_value, tvb, (gint)(item_address - base_address), len, wmem_strbuf_get_str(strbuf));
}
return offset;
}
static int parse_VariantCol(tvbuff_t *tvb, int offset, proto_tree *parent_tree, guint64 base_address, guint32 length _U_, gboolean is_64bit, struct CRowVariant *variant, const char *fmt, ...)
{
proto_tree *tree;
proto_item *item;
va_list ap;
struct vtype_data *vt_type;
const char *modifier = "", *txt;
int size;
guint16 vtype_high;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CRowVariant, &item, txt);
variant->vtype = tvb_get_letohs(tvb, offset);
vt_type = vType_get_type((enum vType)variant->vtype);
DISSECTOR_ASSERT(vt_type != NULL);
vtype_high = (variant->vtype & 0xFF00);
if (vtype_high) {
if (vtype_high == VT_VECTOR) {
modifier = "|VT_VECTOR";
} else if (vtype_high == VT_ARRAY) {
modifier = "|VT_ARRAY";
} else {
modifier = "|Unknown, possibly error";
}
}
proto_tree_add_string_format_value(tree, hf_mswsp_rowvariant_vtype, tvb, offset, 2, vt_type->str, "%s%s", vt_type->str, modifier);
offset += 2;
proto_tree_add_item(tree, hf_mswsp_rowvariant_reserved1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
variant->reserved1 = tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(tree, hf_mswsp_rowvariant_reserved2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
variant->reserved2 = tvb_get_letohl(tvb, offset);
offset += 4;
size = get_fixed_vtype_dataize((enum vType)(variant->vtype & 0x00FF));
if (vtype_high == VT_VECTOR || vtype_high == VT_ARRAY) {
offset = parse_VariantColVector(tvb, offset, tree, base_address,
is_64bit, variant);
} else {
wmem_strbuf_t *strbuf = wmem_strbuf_new(wmem_packet_scope(), "");
if (size != -1) {
const char* desc = vt_type->str;
DISSECTOR_ASSERT_HINT(vt_type->tvb_get != 0,
"appears fixed type that we don't know yet how to handle, please submit a bug with trace");
vt_type->tvb_get(tvb, offset, &variant->content);
vt_type->strbuf_append(strbuf, &variant->content);
proto_tree_add_string_format_value(tree, hf_mswsp_rowvariant_item_value, tvb, offset, size, desc, "%s: %s", desc, wmem_strbuf_get_str(strbuf));
} else {
gint64 value_address;
int buf_offset = offset;
int len;
union vt_single non_fixed_size_val;
DISSECTOR_ASSERT_HINT(vt_type->tvb_get_value_only != 0, "appears this is a dynamic type that we don't know yet how to handle, please submit a bug with network trace");
if (is_64bit) {
variant->content.hyperw = tvb_get_letoh64(tvb, offset);
offset += 8;
value_address = variant->content.hyperw;
proto_tree_add_uint64(tree, hf_mswsp_rowvariant_item_address64, tvb, buf_offset, 8, value_address);
} else {
variant->content.longw = tvb_get_letohl(tvb, offset);
offset += 4;
value_address = variant->content.longw;
proto_tree_add_uint(tree, hf_mswsp_rowvariant_item_address32, tvb, buf_offset, 4, (guint32)value_address);
}
len = vt_type->tvb_get_value_only(tvb, (int)(value_address - base_address), 0, &non_fixed_size_val);
vt_type->strbuf_append(strbuf, &non_fixed_size_val);
proto_tree_add_string(tree, hf_mswsp_rowvariant_item_value, tvb, (gint)(value_address - base_address), len, wmem_strbuf_get_str(strbuf));
}
}
return offset;
}
static int parse_RowsBufferCol(tvbuff_t *tvb, int offset, guint32 row, guint32 col, struct CPMSetBindingsIn *bindingsin, struct rows_data *rowsin, gboolean b_is_64bit, proto_tree *parent_tree, const char *fmt, ...)
{
proto_tree *tree;
proto_item *item;
guint32 buf_start = offset;
guint32 buf_offset = buf_start + (row * bindingsin->brow);
struct CTableColumn *pcol = &bindingsin->acolumns[col];
static const value_string STATUS[] = {
{0, "StoreStatusOk"},
{1, "StoreStatusDeferred"},
{2, "StoreStatusNull"},
{0, NULL}
};
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_GetRowsColumn, &item, txt);
proto_item_append_text(item, " (%s)", pcol->name);
if (pcol->statusused) {
int tmp_offset = buf_offset + pcol->statusoffset;
proto_tree_add_string(tree, hf_mswsp_ctablecolumn_status, tvb, tmp_offset, 1, val_to_str(tvb_get_guint8(tvb, tmp_offset), STATUS, "(Invalid: 0x%x)"));
}
if (pcol->lengthused) {
int tmp_offset = buf_offset + pcol->lengthoffset;
proto_tree_add_item(tree, hf_mswsp_ctablecolumn_length, tvb, tmp_offset, 1, ENC_LITTLE_ENDIAN);
}
if (pcol->valueused) {
int tmp_offset = buf_offset + pcol->valueoffset;
struct CRowVariant variant;
guint32 len = pcol->valuesize;
guint64 base_address = rowsin->ulclientbase;
ZERO_STRUCT(variant);
if (pcol->lengthused) {
len = tvb_get_letohs(tvb, buf_offset + pcol->lengthoffset) - pcol->valuesize;
}
if (pcol->vtype == VT_VARIANT) {
parse_VariantCol(tvb, tmp_offset, tree, base_address, len, b_is_64bit, &variant, "CRowVariant");
}
}
return offset;
}
static int parse_RowsBuffer(tvbuff_t *tvb, int offset, guint32 num_rows, struct CPMSetBindingsIn *bindingsin, struct rows_data *rowsin, gboolean is64bit, proto_tree *parent_tree, const char *fmt, ...)
{
proto_tree *tree;
proto_item *item;
guint32 num;
const char *txt;
va_list ap;
va_start(ap, fmt);
txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
va_end(ap);
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_GetRowsRow, &item, txt);
for (num = 0; num < num_rows; ++num) {
guint32 col;
proto_tree *row_tree;
row_tree = proto_tree_add_subtree_format(tree, tvb, offset, 0, ett_GetRowsRow, NULL, "Row[%d]", num);
for (col = 0; col < bindingsin->ccolumns; col++) {
parse_RowsBufferCol(tvb, offset, num, col, bindingsin, rowsin, is64bit, row_tree, "Col[%d]", col);
}
}
return offset;
}
static int dissect_CPMConnect(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *private_data)
{
proto_item *ti;
proto_tree *tree;
gint offset = 16;
guint len;
guint32 version;
struct message_data *data = NULL;
struct mswsp_ct *ct = NULL;
ti = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_mswsp_msg);
proto_item_set_text(ti, "CPMConnect%s", in ? "In" : "Out");
col_append_str(pinfo->cinfo, COL_INFO, "Connect");
ti = proto_tree_add_item_ret_uint(tree, hf_mswsp_msg_Connect_Version, tvb,
offset, 4, ENC_LITTLE_ENDIAN, &version);
ct = get_create_converstation_data(pinfo);
if (ct) {
data = find_or_create_message_data(ct, pinfo, 0xC8, in, private_data);
if (data) {
data->content.version = version;
}
}
offset += 4;
if (in) {
guint32 blob_size1_off, blob_size2_off;
proto_tree *pad_tree;
pad_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_mswsp_pad, &ti, "Padding");
proto_tree_add_item(tree, hf_mswsp_msg_ConnectIn_ClientIsRemote, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
blob_size1_off = offset;
offset += 4;
offset = parse_padding(tvb, offset, 8, pad_tree, "_paddingcbBlob2");
blob_size2_off = offset;
offset += 4;
offset = parse_padding(tvb, offset, 16, pad_tree, "_padding");
len = tvb_unicode_strsize(tvb, offset);
proto_tree_add_item(tree, hf_mswsp_msg_ConnectIn_MachineName, tvb,
offset, len, ENC_LITTLE_ENDIAN | ENC_UCS_2);
offset += len;
len = tvb_unicode_strsize(tvb, offset);
ti = proto_tree_add_item(tree, hf_mswsp_msg_ConnectIn_UserName, tvb,
offset, len, ENC_LITTLE_ENDIAN | ENC_UCS_2);
offset += len;
offset = parse_padding(tvb, offset, 8, pad_tree, "_paddingcPropSets");
offset = parse_PropertySetArray(tvb, offset, blob_size1_off, tree, pad_tree, "PropSets");
offset = parse_padding(tvb, offset, 8, pad_tree, "paddingExtPropset");
offset = parse_PropertySetArray(tvb, offset, blob_size2_off, tree, pad_tree, "ExtPropset");
offset = parse_padding(tvb, offset, 8, pad_tree, "???");
DISSECTOR_ASSERT(offset == (int)tvb_reported_length(tvb));
proto_tree_move_item(tree, ti, proto_tree_get_parent(pad_tree));
} else {
}
return tvb_reported_length(tvb);
}
static int dissect_CPMDisconnect(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, gboolean in _U_, void *data _U_)
{
col_append_str(pinfo->cinfo, COL_INFO, "Disconnect");
return tvb_reported_length(tvb);
}
static int dissect_CPMCreateQuery(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *data _U_)
{
gint offset = 16;
proto_item *item;
proto_tree *tree;
item = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mswsp_msg);
proto_item_set_text(item, "CPMCreateQuery%s", in ? "In" : "Out");
col_append_str(pinfo->cinfo, COL_INFO, "CreateQuery");
if (in) {
proto_item *ti;
proto_tree *pad_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_mswsp_pad, &ti, "Padding");
guint8 CColumnSetPresent, CRestrictionPresent, CSortSetPresent, CCategorizationSetPresent;
guint32 size = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_msg_cpmcreatequery_size, tvb, offset, 4, size);
offset += 4;
CColumnSetPresent = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mswsp_msg_cpmcreatequery_ccolumnsetpresent, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (CColumnSetPresent) {
offset = parse_padding(tvb, offset, 4, pad_tree, "paddingCColumnSetPresent");
offset = parse_padding(tvb, offset, 4, pad_tree, "paddingCColumnSetPresent");
offset = parse_CColumnSet(tvb, offset, tree, "CColumnSet");
}
CRestrictionPresent = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mswsp_msg_cpmcreatequery_crestrictionpresent, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (CRestrictionPresent) {
offset = parse_CRestrictionArray(tvb, offset, tree, pad_tree, "RestrictionArray");
}
CSortSetPresent = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mswsp_msg_cpmcreatequery_csortpresent, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (CSortSetPresent) {
offset = parse_padding(tvb, offset, 4, tree, "paddingCSortSetPresent");
proto_tree_add_item(tree, hf_mswsp_msg_cpmcreatequery_csortset_xxx, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
offset = parse_CSortSet(tvb, offset, tree, pad_tree, "SortSet");
}
CCategorizationSetPresent = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mswsp_msg_cpmcreatequery_ccategpresent, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (CCategorizationSetPresent) {
guint32 count, i;
offset = parse_padding(tvb, offset, 4, pad_tree, "paddingCCategorizationSetPresent");
count = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_msg_cpmcreatequery_ccateg_count, tvb, offset, 4, count);
offset += 4;
for (i=0; i<count; i++) {
offset = parse_CCategorizationSpec(tvb, offset, tree, pad_tree, "categories[%u]", i);
}
}
offset = parse_padding(tvb, offset, 4, tree, "XXXX");
offset = parse_CRowsetProperties(tvb, offset, tree, pad_tree, "RowSetProperties");
offset = parse_CPidMapper(tvb, offset, tree, pad_tree, "PidMapper");
parse_CColumnGroupArray(tvb, offset, tree, pad_tree, "GroupArray");
} else {
proto_tree_add_item(tree, hf_mswsp_msg_cpmcreatequery_trueseq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcreatequery_workid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcreatequery_cursors, tvb, offset, -1, ENC_NA);
}
return tvb_reported_length(tvb);
}
static int dissect_CPMFreeCursor(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, gboolean in _U_, void *data _U_)
{
col_append_str(pinfo->cinfo, COL_INFO, "FreeCursor");
return tvb_reported_length(tvb);
}
static int dissect_CPMGetRows(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *private_data)
{
struct mswsp_ct *ct = NULL;
gint offset = 16;
proto_item *item;
proto_tree *tree;
proto_tree *seek_tree;
guint32 eType = 0;
item = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, in ? 0 : -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mswsp_msg);
proto_item_set_text(item, "GetRows%s", in ? "In" : "Out");
col_append_str(pinfo->cinfo, COL_INFO, "GetRows");
ct = get_create_converstation_data(pinfo);
if (in) {
struct message_data *data = NULL;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrows_hcursor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrows_rowstotransfer, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrows_rowwidth, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrows_cbseek, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
data = find_or_create_message_data(ct, pinfo, 0xCC, in, private_data);
if (data) {
data->content.rowsin.cbreserved = tvb_get_letohl(tvb, offset);
}
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrows_cbreserved, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrows_cbreadbuffer, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (data) {
data->content.rowsin.ulclientbase = tvb_get_letohl(tvb, offset);
}
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrows_ulclientbase, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrows_fbwdfetch, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
eType = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrows_etype, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrows_chapt, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
seek_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_SeekDescription, NULL, "SeekDescription");
switch (eType) {
case 0:
break;
case 1:
parse_CRowSeekNext(tvb, offset, seek_tree, "CRowSeekNext");
break;
case 2:
parse_CRowSeekAt(tvb, offset, seek_tree, "CRowSeekAt");
break;
case 3:
parse_CRowSeekAtRatio(tvb, offset, seek_tree, "CRowSeekAtRatio");
break;
case 4:
parse_CRowSeekByBookmark(tvb, offset, seek_tree, "CRowSeekByRatio");
break;
default:
break;
}
} else {
guint32 num_rows = 0;
proto_item *ti;
proto_tree *pad_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_mswsp_pad, &ti, "Padding");
struct CPMSetBindingsIn *bindingsin = find_binding_msg_data(ct, pinfo,
private_data);
struct rows_data *rowsin = find_rowsin_msg_data(ct, pinfo, private_data);
gboolean b_64bit_mode = FALSE;
gboolean b_has_arch = is_64bit_mode(ct, pinfo, &b_64bit_mode, private_data);
num_rows = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrows_crowsreturned, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
eType = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrows_etype, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrows_chapt, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
seek_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_SeekDescription, NULL, "SeekDescription");
switch (eType) {
case 0:
break;
case 1:
parse_CRowSeekNext(tvb, offset, seek_tree, "CRowSeekNext");
break;
case 2:
parse_CRowSeekAt(tvb, offset, seek_tree, "CRowSeekAt");
break;
case 3:
parse_CRowSeekAtRatio(tvb, offset, seek_tree, "CRowSeekAtRatio");
break;
case 4:
parse_CRowSeekByBookmark(tvb, offset, seek_tree, "CRowSeekByRatio");
break;
default:
break;
}
if (b_has_arch && bindingsin && rowsin) {
offset = parse_padding(tvb, offset, rowsin->cbreserved, pad_tree,
"paddingRows");
parse_RowsBuffer(tvb, offset, num_rows, bindingsin, rowsin, b_64bit_mode, tree, "Rows");
} else {
gint nbytes = tvb_reported_length_remaining(tvb, offset);
proto_tree_add_expert_format(tree, pinfo, &ei_missing_msg_context, tvb, offset, nbytes, "Undissected %d bytes (due to missing preceding msg(s))", nbytes);
}
}
return tvb_reported_length(tvb);
}
static int dissect_CPMRatioFinished(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *data _U_)
{
gint offset = 16;
proto_item *item;
proto_tree *tree;
col_append_str(pinfo->cinfo, COL_INFO, "RatioFinished");
item = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mswsp_msg);
proto_item_set_text(item, "RationFinised%s", in ? "In" : "Out");
if (in) {
proto_tree_add_item(tree, hf_mswsp_msg_cpmratiofinished_hcursor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmratiofinished_fquick, tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(tree, hf_mswsp_msg_cpmratiofinished_ulnumerator, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmratiofinished_uldenominator, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmratiofinished_crows, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmratiofinished_fnewrows, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
return tvb_reported_length(tvb);
}
static int dissect_CPMCompareBmk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *data _U_)
{
gint offset = 16;
proto_item *item;
proto_tree *tree;
item = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, in ? 0 : -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mswsp_msg);
proto_item_set_text(item, "CompareBmk%s", in ? "In" : "Out");
col_append_str(pinfo->cinfo, COL_INFO, "CompareBmk");
if (in) {
proto_tree_add_item(tree, hf_mswsp_msg_cpmcomparebmk_hcursor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcomparebmk_chapt, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcomparebmk_bmkfirst, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcomparebmk_bmksecond, tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(tree, hf_mswsp_msg_cpmcomparebmk_dwcomparison, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
return tvb_reported_length(tvb);
}
static int dissect_CPMGetApproximatePosition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *data _U_)
{
gint offset = 16;
proto_item *item;
proto_tree *tree;
item = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, in ? 0 : -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mswsp_msg);
proto_item_set_text(item, "GetApproximatePosition%s", in ? "In" : "Out");
col_append_str(pinfo->cinfo, COL_INFO, "GetApproximatePosition");
if (in) {
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetapproxpos_hcursor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetapproxpos_chapt, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetapproxpos_bmk, tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetapproxpos_numerator, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetapproxpos_denominator, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
return tvb_reported_length(tvb);
}
static int dissect_CPMSetBindings(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *private_data)
{
gint offset = 16;
struct CPMSetBindingsIn request;
col_append_str(pinfo->cinfo, COL_INFO, "SetBindings");
if (in) {
struct mswsp_ct *ct = NULL;
struct message_data *data = NULL;
proto_item *ti;
proto_tree *tree, *pad_tree;
guint32 size, num, n;
gint64 column_size;
ti = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_mswsp_msg);
proto_item_set_text(ti, "SetBindingsIn");
pad_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_mswsp_pad, &ti, "Padding");
proto_tree_add_item(tree, hf_mswsp_msg_cpmsetbinding_hcursor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
request.hcursor = tvb_get_letohl(tvb, offset);
offset += 4;
request.brow = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_mswsp_msg_cpmsetbinding_cbrow, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
size = tvb_get_letohl(tvb, offset);
request.bbindingdesc = size;
proto_tree_add_item(tree, hf_mswsp_msg_cpmsetbinding_desc, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
request.dummy = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_mswsp_msg_cpmsetbinding_dummy, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
num = tvb_get_letohl(tvb, offset);
request.ccolumns = num;
ti = proto_tree_add_item(tree, hf_mswsp_msg_cpmsetbinding_ccolumns, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmsetbinding_acolumns, tvb, offset, size-4, ENC_NA);
column_size = num*sizeof(struct CTableColumn);
if (column_size > tvb_reported_length_remaining(tvb, offset))
{
expert_add_info(pinfo, ti, &ei_mswsp_msg_cpmsetbinding_ccolumns);
return tvb_reported_length(tvb);
}
ct = get_create_converstation_data(pinfo);
request.acolumns = (struct CTableColumn*)wmem_alloc(wmem_file_scope(),
sizeof(struct CTableColumn) * num);
for (n=0; n<num; n++) {
offset = parse_padding(tvb, offset, 4, pad_tree, "padding_aColumns[%u]", n);
offset = parse_CTableColumn(tvb, offset, tree, pad_tree, &request.acolumns[n],"aColumns[%u]", n);
}
data = find_or_create_message_data(ct, pinfo,0xD0,in, private_data);
if (data) {
data->content.bindingsin = request;
}
} else {
}
return tvb_reported_length(tvb);
}
static int dissect_CPMGetNotify(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, gboolean in _U_, void *data _U_)
{
col_append_str(pinfo->cinfo, COL_INFO, "GetNotify");
return tvb_reported_length(tvb);
}
static int dissect_CPMSendNotifyOut(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in _U_, void *data _U_)
{
gint offset = 16;
proto_item *item;
proto_tree *tree;
col_append_str(pinfo->cinfo, COL_INFO, "SendNotify");
item = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mswsp_msg);
proto_item_set_text(item, "GetSendNotifyOut");
proto_tree_add_item(tree, hf_mswsp_msg_cpmsendnotify_watchnotify, tvb, offset, 4, ENC_LITTLE_ENDIAN);
return tvb_reported_length(tvb);
}
static int dissect_CPMGetQueryStatus(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *data _U_)
{
gint offset = 16;
proto_item *item;
proto_tree *tree;
item = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mswsp_msg);
proto_item_set_text(item, "GetQueryStatus%s", in ? "In" : "Out");
col_append_str(pinfo->cinfo, COL_INFO, "GetQueryStatus");
if (in) {
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetquerystatus_hcursor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetquerystatus_qstatus, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
return tvb_reported_length(tvb);
}
static int dissect_CPMCiState(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *data _U_)
{
gint offset = 16;
proto_item *item;
proto_tree *tree;
col_append_str(pinfo->cinfo, COL_INFO, "CiState");
if (!in) {
item = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mswsp_msg);
proto_item_set_text(item, "CiStateOut");
proto_tree_add_item(tree, hf_mswsp_msg_cpmcistate_cbstruct, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcistate_cwordlist, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcistate_cpersistindex, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcistate_cqueries, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcistate_cfreshtest, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcistate_cfreshtest, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcistate_dwmergeprogress, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcistate_estate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcistate_cfiltereddocs, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcistate_ctotaldocs, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcistate_cpendingscans, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcistate_dwindexsize, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcistate_cuniquekeys, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcistate_csecqdocuments, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmcistate_dwpropcachesize, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
return tvb_reported_length(tvb);
}
static int dissect_CPMFetchValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *data _U_)
{
gint offset = 16;
proto_item *item;
proto_tree *tree, *pad_tree;
col_append_str(pinfo->cinfo, COL_INFO, "FetchValue");
item = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, -1, ENC_NA);
tree = proto_tree_add_subtree_format(parent_tree, tvb, offset, 0, ett_mswsp_msg, &item, "FetchValue%s", in ? "In" : "Out");
pad_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_mswsp_pad, NULL, "Padding");
if (in) {
struct CFullPropSpec prop;
proto_tree_add_item(tree, hf_mswsp_msg_cpmfetchvalue_wid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmfetchvalue_cbsofar, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmfetchvalue_cbpropspec, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmfetchvalue_cbchunk, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = parse_CFullPropSpec(tvb, offset, tree, pad_tree, &prop,
"PropSpec");
parse_padding(tvb, offset, 4, pad_tree,"_padding");
} else {
guint32 cbValue = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_mswsp_msg_cpmfetchvalue_cbvalue, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmfetchvalue_fmoreexists, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmfetchvalue_fvalueexists, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmfetchvalue_vvalue, tvb, offset, cbValue, ENC_NA);
}
return tvb_reported_length(tvb);
}
static int dissect_CPMGetQueryStatusEx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *data _U_)
{
gint offset = 16;
proto_item *item;
proto_tree *tree;
item = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mswsp_msg);
proto_item_set_text(item, "GetQueryStatusEx%s", in ? "In" : "Out");
col_append_str(pinfo->cinfo, COL_INFO, "GetQueryStatusEx");
if (in) {
proto_tree_add_item(tree, hf_mswsp_msg_cpmquerystatusex_hcursor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmquerystatusex_bmk, tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(tree, hf_mswsp_msg_cpmquerystatusex_qstatus, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmquerystatusex_cfiltereddocs, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmquerystatusex_cdocstofilter, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmquerystatusex_dwratiodenom, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmquerystatusex_dwrationumer, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmquerystatusex_irowbmk, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmquerystatusex_crowstotal, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmquerystatusex_maxrank, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmquerystatusex_cresultsfound, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmquerystatusex_whereid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
return tvb_reported_length(tvb);
}
static int dissect_CPMRestartPosition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *data _U_)
{
gint offset = 16;
proto_item *item;
proto_tree *tree;
col_append_str(pinfo->cinfo, COL_INFO, "CPMRestartPosition");
if (in) {
item = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mswsp_msg);
proto_item_set_text(item, "CPMRestartPosition");
proto_tree_add_item(tree, hf_mswsp_msg_cpmrestartposition_hcursor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmrestartposition_chapt, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
col_append_str(pinfo->cinfo, COL_INFO, "RestartPosition");
return tvb_reported_length(tvb);
}
static int dissect_CPMSetCatState(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, gboolean in _U_, void *data _U_)
{
col_append_str(pinfo->cinfo, COL_INFO, "SetCatState");
return tvb_reported_length(tvb);
}
static int dissect_CPMGetRowsetNotify(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *data _U_)
{
gint offset = 16;
proto_item *item;
proto_tree *tree;
col_append_str(pinfo->cinfo, COL_INFO, "GetRowsetNotify");
if (!in) {
item = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mswsp_msg);
proto_item_set_text(item, "GetRowsetNotifyOut");
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrowsetnotify_wid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrowsetnotify_moreevents, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrowsetnotify_eventtype, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrowsetnotify_rowsetitemstate, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrowsetnotify_changeditemstate, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrowsetnotify_rowsetevent, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrowsetnotify_rowseteventdata1, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_mswsp_msg_cpmgetrowsetnotify_rowseteventdata2, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
return tvb_reported_length(tvb);
}
static int dissect_CPMFindIndices(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *data _U_)
{
gint offset = 16;
proto_item *item;
proto_tree *tree;
col_append_str(pinfo->cinfo, COL_INFO, "FindIndices");
item = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mswsp_msg);
proto_item_set_text(item, "FindIndices%s", in ? "In" : "Out");
if (in) {
guint32 cWids;
guint32 cDepthPrev;
cWids = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_msg_cpmfindindices_cwids, tvb, offset, 4, cWids);
offset += 4;
cDepthPrev = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_msg_cpmfindindices_cdepthprev, tvb, offset, 4, cDepthPrev);
offset += 4;
offset = parse_uin32_array(tvb, offset, tree, cWids, "pwids");
parse_uin32_array(tvb, offset, tree, cDepthPrev, "prgiRowPrev");
} else {
guint32 cDepthNext;
cDepthNext = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_mswsp_msg_cpmfindindices_cdepthnext, tvb, offset, 4, cDepthNext);
offset += 4;
parse_uin32_array(tvb, offset, tree, cDepthNext, "prgiRowNext");
}
return tvb_reported_length(tvb);
}
static int dissect_CPMSetScopePrioritization(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *data _U_)
{
gint offset = 16;
proto_item *item;
proto_tree *tree;
col_append_str(pinfo->cinfo, COL_INFO, "SetScopePrioritization");
if (in) {
item = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mswsp_msg);
proto_item_set_text(item, "SetScopePrioritizationIn");
proto_tree_add_item(tree, hf_mswsp_msg_cpmsetscopeprioritization_priority, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmsetscopeprioritization_eventfreq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
return tvb_reported_length(tvb);
}
static int dissect_CPMGetScopeStatistics(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean in, void *data _U_)
{
gint offset = 16;
proto_item *item;
proto_tree *tree;
item = proto_tree_add_item(parent_tree, hf_mswsp_msg, tvb, offset, in ? 0 : -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mswsp_msg);
proto_item_set_text(item, "GetScopeStatistics%s", in ? "In" : "Out");
col_append_str(pinfo->cinfo, COL_INFO, "GetScopeStatistics");
if (in) {
} else {
proto_tree_add_item(tree, hf_mswsp_msg_cpmsetscopestatisics_dwindexitems, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmsetscopestatisics_dwoutstandingadds, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mswsp_msg_cpmsetscopestatisics_dwoutstandingmodifies, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
return tvb_reported_length(tvb);
}
static int
dissect_mswsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean in, void *data)
{
proto_tree *mswsp_tree = NULL;
proto_tree *hdr_tree;
proto_item *ti, *hti;
guint32 msg;
guint32 status;
if (tvb_reported_length(tvb) < 16) {
return 0;
}
col_append_str(pinfo->cinfo, COL_PROTOCOL, " WSP");
col_set_str(pinfo->cinfo, COL_INFO, "WSP ");
col_append_str(pinfo->cinfo, COL_INFO, in ? "Request: " : "Response: ");
ti = proto_tree_add_item(tree, proto_mswsp, tvb, 0, -1, ENC_NA);
mswsp_tree = proto_item_add_subtree(ti, ett_mswsp);
hti = proto_tree_add_item(mswsp_tree, hf_mswsp_hdr, tvb, 0, 16, ENC_NA);
hdr_tree = proto_item_add_subtree(hti, ett_mswsp_hdr);
proto_tree_add_item_ret_uint(hdr_tree, hf_mswsp_hdr_msg, tvb,
0, 4, ENC_LITTLE_ENDIAN, &msg);
proto_item_append_text(hti, " %s", val_to_str(msg, VALS(msg_ids),
"(Unknown: 0x%x)"));
proto_tree_add_item_ret_uint(hdr_tree, hf_mswsp_hdr_status, tvb,
4, 4, ENC_LITTLE_ENDIAN, &status);
if (!in || status != 0) {
proto_item_append_text(hti, " %s",
val_to_str(status, VALS(dcom_hresult_vals),
"(Unknown: 0x%x)"));
}
proto_tree_add_item(hdr_tree, hf_mswsp_hdr_checksum, tvb,
8, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(hdr_tree, hf_mswsp_hdr_reserved, tvb,
12, 4, ENC_LITTLE_ENDIAN);
switch(msg) {
case 0xC8:
dissect_CPMConnect(tvb, pinfo, tree, in, data);
break;
case 0xC9:
dissect_CPMDisconnect(tvb, pinfo, tree, in, data);
break;
case 0xCA:
dissect_CPMCreateQuery(tvb, pinfo, tree, in, data);
break;
case 0xCB:
dissect_CPMFreeCursor(tvb, pinfo, tree, in, data);
break;
case 0xCC:
dissect_CPMGetRows(tvb, pinfo, tree, in, data);
break;
case 0xCD:
dissect_CPMRatioFinished(tvb, pinfo, tree, in, data);
break;
case 0xCE:
dissect_CPMCompareBmk(tvb, pinfo, tree, in, data);
break;
case 0xCF:
dissect_CPMGetApproximatePosition(tvb, pinfo, tree, in, data);
break;
case 0xD0:
dissect_CPMSetBindings(tvb, pinfo, tree, in, data);
break;
case 0xD1:
dissect_CPMGetNotify(tvb, pinfo, tree, in, data);
break;
case 0xD2:
dissect_CPMSendNotifyOut(tvb, pinfo, tree, in, data);
break;
case 0xD7:
dissect_CPMGetQueryStatus(tvb, pinfo, tree, in, data);
break;
case 0xD9:
dissect_CPMCiState(tvb, pinfo, tree, in, data);
break;
case 0xE4:
dissect_CPMFetchValue(tvb, pinfo, tree, in, data);
break;
case 0xE7:
dissect_CPMGetQueryStatusEx(tvb, pinfo, tree, in, data);
break;
case 0xE8:
dissect_CPMRestartPosition(tvb, pinfo, tree, in, data);
break;
case 0xEC:
dissect_CPMSetCatState(tvb, pinfo, tree, in, data);
break;
case 0xF1:
dissect_CPMGetRowsetNotify(tvb, pinfo, tree, in, data);
break;
case 0xF2:
dissect_CPMFindIndices(tvb, pinfo, tree, in, data);
break;
case 0xF3:
dissect_CPMSetScopePrioritization(tvb, pinfo, tree, in, data);
break;
case 0xF4:
dissect_CPMGetScopeStatistics(tvb, pinfo, tree, in, data);
break;
default:
return 0;
}
return tvb_reported_length(tvb);
}
void
proto_register_mswsp(void)
{
expert_module_t* expert_mswsp = NULL;
static hf_register_info hf[] = {
{
&hf_mswsp_hdr,
{
"Header", "mswsp.hdr",
FT_NONE, BASE_NONE, NULL, 0,
"Message header", HFILL
}
},
{
&hf_mswsp_hdr_msg,
{
"Msg id", "mswsp.hdr.id",
FT_UINT32, BASE_HEX, VALS(msg_ids), 0,
"Message id", HFILL
}
},
{
&hf_mswsp_hdr_status,
{
"Status", "mswsp.hdr.status",
FT_UINT32, BASE_HEX, VALS(dcom_hresult_vals), 0,
"Message Status", HFILL
}
},
{
&hf_mswsp_hdr_checksum,
{
"checksum", "mswsp.hdr.checksum",
FT_UINT32, BASE_HEX, NULL, 0,
"Message Checksum", HFILL
}
},
{
&hf_mswsp_hdr_reserved,
{
"Reserved", "mswsp.hdr.reserved",
FT_UINT32, BASE_HEX, NULL, 0,
"Reserved bytes", HFILL
}
},
{
&hf_mswsp_msg,
{
"msg", "mswsp.msg",
FT_NONE, BASE_NONE, NULL, 0,
"Message", HFILL
}
},
{
&hf_mswsp_msg_Connect_Version,
{
"Version", "mswsp.Connect.version",
FT_UINT32, BASE_HEX, VALS(version_vals), 0,
"OS Version", HFILL
}
},
{
&hf_mswsp_msg_ConnectIn_ClientIsRemote,
{
"Remote", "mswsp.ConnectIn.isRemote",
FT_BOOLEAN, BASE_HEX, NULL, 0,
"Client is remote",HFILL
}
},
{
&hf_mswsp_msg_ConnectIn_Blob1,
{
"Size", "mswsp.ConnectIn.propset.size",
FT_UINT32, BASE_DEC, NULL, 0,
"Size of PropSet fields",HFILL
}
},
{
&hf_mswsp_msg_ConnectIn_MachineName,
{
"Remote machine", "mswsp.ConnectIn.machine",
FT_STRINGZ, BASE_NONE, NULL, 0,
"Name of remote machine",HFILL
}
},
{
&hf_mswsp_msg_ConnectIn_UserName,
{
"User", "mswsp.ConnectIn.user",
FT_STRINGZ, BASE_NONE, NULL, 0,
"Name of remote user",HFILL
}
},
{
&hf_mswsp_msg_ConnectIn_PropSets_num,
{
"Num", "mswsp.ConnectIn.propset.num",
FT_UINT32, BASE_DEC, NULL, 0,
"Number of Property Sets", HFILL
}
},
{
&hf_mswsp_bool_options,
{
"uBooleanOptions", "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions",
FT_UINT32, BASE_HEX, NULL, 0, "Boolean options", HFILL
}
},
{
&hf_mswsp_bool_options_cursor,
{
"Cursor", "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions", FT_UINT32,
BASE_HEX, VALS(cursor_vals), 0x0000000007, "Cursor Type", HFILL
}
},
{
&hf_mswsp_bool_options_async,
{
"eAsynchronous", "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions.eAsyncronous",
FT_BOOLEAN, 32, NULL, eAsynchronous, "The client will not wait for execution completion", HFILL
}
},
{
&hf_mswsp_bool_options_firstrows,
{
"eFirstRows", "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions.eFirstRows",
FT_BOOLEAN, 32, NULL, eFirstRows, "Return the first rows encountered, not the best matches.", HFILL
}
},
{
&hf_mswsp_bool_options_holdrows,
{
"eHoldRows", "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions.eHoldRows",
FT_BOOLEAN, 32, NULL, eHoldRows, "The server MUST NOT discard rows until the client is done with a query.", HFILL
}
},
{
&hf_mswsp_bool_options_chaptered,
{
"eChaptered", "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions.eChaptered",
FT_BOOLEAN, 32, NULL, eChaptered, "The rowset supports chapters.", HFILL
}
},
{
&hf_mswsp_bool_options_useci,
{
"eUseCI", "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions.eUseCI",
FT_BOOLEAN, 32, NULL, eUseCI, "Use the inverted index to evaluate content restrictions even if it is out of date.", HFILL
}
},
{
&hf_mswsp_bool_options_defertrim,
{
"eDeferTrimming", "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions.eDeferTrimming",
FT_BOOLEAN, 32, NULL, eDeferTrimming, "Defer Non-indexed trimming operations like scoping or security checking which can be expensive.", HFILL
}
},
{
&hf_mswsp_bool_options_rowsetevents,
{
"eEnableRowsetEvents", "mswsp.RowSetProperties.CPMCreateQuery.uBooleanOptions.eEnableRowsetEvents",
FT_BOOLEAN, 32, NULL, eEnableRowsetEvents, "Enables storage of rowset events on the server side.", HFILL
}
},
{
&hf_mswsp_bool_options_dontcomputeexpensive,
{
"eDoNotComputeExpensiveProps", "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions.eDoNotComputeExpensiveProps",
FT_BOOLEAN, 32, NULL, eDoNotComputeExpensiveProps, "Prevents computation of expensive properties.", HFILL
}
},
{
&hf_mswsp_guid_time_low,
{
"time-low", "mswsp.guid.time_low",
FT_UINT32, BASE_HEX, NULL, 0, "time low value", HFILL
}
},
{
&hf_mswsp_guid_time_mid,
{
"time-mid", "mswsp.guid.time_mid",
FT_UINT16, BASE_HEX, NULL, 0, "time mid value", HFILL
}
},
{
&hf_mswsp_guid_time_high,
{
"time-high", "mswsp.guid.time_high",
FT_UINT16, BASE_HEX, NULL, 0, "time high value", HFILL
}
},
{
&hf_mswsp_guid_time_clock_hi,
{
"clock_seq_hi_and_reserved", "mswsp.guid.time_clock_high",
FT_UINT8, BASE_HEX, NULL, 0, "time clock high value", HFILL
}
},
{
&hf_mswsp_guid_time_clock_low,
{
"clock_seq_low", "mswsp.guid.time_clock_low",
FT_UINT8, BASE_HEX, NULL, 0, "time clock high low", HFILL
}
},
{
&hf_mswsp_guid_node,
{
"node", "mswsp.guid.node",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_lcid,
{
"lcid", "mswsp.lcid",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_lcid_sortid,
{
"Sort ID", "mswsp.lcid.sortid",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_lcid_langid,
{
"Language ID", "mswsp.lcid.langid",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cscort_column,
{
"column", "mswsp.csort.column",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cscort_order,
{
"order", "mswsp.csort.order",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cscort_individual,
{
"inidvidual", "mswsp.csort.individual",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cscortset_count,
{
"count", "mswsp.csortset.count",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ctablecolumn_vtype,
{
"vType", "mswsp.ctablecolumn.vtype",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ctablecolumn_aggused,
{
"AggreagateUsed", "mswsp.ctablecolumn.aggused",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ctablecolumn_aggtype,
{
"AggreagateType", "mswsp.ctablecolumn.aggtype",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ctablecolumn_valused,
{
"ValueUsed", "mswsp.ctablecolumn.valused",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ctablecolumn_valoffset,
{
"ValueOffset", "mswsp.ctablecolumn.valused",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ctablecolumn_valsize,
{
"ValueSize", "mswsp.ctablecolumn.valsize",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ctablecolumn_statused,
{
"StatusUsed", "mswsp.ctablecolumn.statused",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ctablecolumn_statoffset,
{
"StatusOffset", "mswsp.ctablecolumn.statoffset",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ctablecolumn_lenused,
{
"LengthUsed", "mswsp.ctablecolumn.lenused",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ctablecolumn_lenoffset,
{
"LengthOffset", "mswsp.ctablecolumn.lenoffset",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cfullpropspec_kind,
{
"ulKind", "mswsp.cfullpropspec.kind",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cfullpropspec_propid,
{
"propid", "mswsp.cfullpropspec.propid",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cfullpropspec_propname,
{
"propname", "mswsp.cfullpropspec.propname",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cproprestrict_relop,
{
"relop", "mswsp.cproprestrict.relop",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ccoercerestrict_value,
{
"value", "mswsp.ccoercerestrict.value",
FT_FLOAT, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ccontentrestrict_cc,
{
"cc", "mswsp.ccontentrestrict.cc",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ccontentrestrict_phrase,
{
"phrase", "mswsp.ccontentrestrict.phrase",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ccontentrestrict_method,
{
"method", "mswsp.ccontentrestrict.method",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_natlangrestrict_cc,
{
"cc", "mswsp.ccontentrestrict.cc",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_natlangrestrict_phrase,
{
"phrase", "mswsp.ccontentrestrict.phrase",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crestrict_ultype,
{
"ulType", "mswsp.crestrict.ultype",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crestrict_weight,
{
"Weight", "mswsp.crestrict.weight",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crestrictarray_count,
{
"count", "mswsp.crestrictarray.count",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crestrictarray_present,
{
"present", "mswsp.crestrictarray.present",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cnoderestrict_cnode,
{
"Weight", "mswsp.cnoderestrict.cnode",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cbasestorvariant_vtype,
{
"vType", "mswsp.cbasestorvariant.vtype",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cbasestorvariant_vvalue,
{
"vValue", "mswsp.cbasestorvariant.vvalue",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cbasestorvariant_vdata1,
{
"vData1", "mswsp.cbasestorvariant.vdata1",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cbasestorvariant_vdata2,
{
"vData2", "mswsp.cbasestorvariant.vdata2",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cbasestorvariant_num,
{
"num", "mswsp.cbasestorvariant.num",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cbasestorvariant_cdims,
{
"cDims", "mswsp.cbasestorvariant.cdims",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cbasestorvariant_ffeatures,
{
"fFeatures", "mswsp.cbasestorvariant.ffeatures",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cbasestorvariant_cbelements,
{
"cbElements", "mswsp.cbasestorvariant.cbelements",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cbasestorvariant_rgsabound,
{
"Rgsabound", "mswsp.cbasestorvariant.rgsabound",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cdbcolid_ekind,
{
"eKind", "mswsp.cdbcolid.ekind",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cdbcolid_ulid,
{
"ulId", "mswsp.cdbcolid.ulid",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cdbcolid_vstring,
{
"vString", "mswsp.cdbcolid.vstring",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cdbprop_id,
{
"Id", "mswsp.cdbprop.id",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cdbprop_options,
{
"Options", "mswsp.cdbprop.options",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cdbprop_status,
{
"Status", "mswsp.cdbprop.status",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cdbpropset_cprops,
{
"cProperties", "mswsp.cdbpropset.cprops",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_rangeboundry_ultype,
{
"ulType", "mswsp.rangeboundry.ultype",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_rangeboundry_labelpresent,
{
"labelPresent", "mswsp.rangeboundry.labelpresent",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL
}
},
{
&hf_mswsp_rangeboundry_cclabel,
{
"ccLabel", "mswsp.rangeboundry.cclabel",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_rangeboundry_label,
{
"Label", "mswsp.rangeboundry.label",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crangecategspec_crange,
{
"cRange", "mswsp.crangecategspec.crange",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ccategspec_type,
{
"type", "mswsp.ccategspec.type",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_caggregspec_type,
{
"type", "mswsp.caggregspec.type",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_caggregspec_ccalias,
{
"ccAlias", "mswsp.caggregspec.ccalias",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_caggregspec_alias,
{
"Alias", "mswsp.caggregspec.alias",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_caggregspec_idcolumn,
{
"idColumn", "mswsp.caggregspec.idcolumn",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_caggregset_count,
{
"count", "mswsp.caggregset.count",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_caggregsortkey_order,
{
"order", "mswsp.caggregsortkey.order",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_csortaggregset_count,
{
"count", "mswsp.csortaggregset.count",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cingroupsortaggregset_type,
{
"Type", "mswsp.cingroupsortaggregset.type",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cingroupsortaggregsets_count,
{
"count", "mswsp.cingroupsortaggregsets.count",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_categorizationspec_cmaxres,
{
"cMaxResults", "mswsp.categorizationspec.cmaxres",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crowsetprops_ulmaxopenrows,
{
"ulMaxOpenRows (ignored)", "mswsp.crowsetprops.ulmaxopenrows",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crowsetprops_ulmemusage,
{
"ulMemUsage (ignored)", "mswsp.crowsetprops.ulmemusage",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crowsetprops_cmaxresults,
{
"cMaxResults", "mswsp.crowsetprops.cmaxresults",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crowsetprops_ccmdtimeout,
{
"cCmdTimeout", "mswsp.crowsetprops.ccmdtimeout",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_cpidmapper_count,
{
"count", "mswsp.cpidmapper.count",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ccolumngroup_count,
{
"count", "mswsp.ccolumngroup.count",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ccolumngroup_grouppid,
{
"groupPid", "mswsp.ccolumngroup.grouppid",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ccolumngroup_pid,
{
"pid", "mswsp.ccolumngroup.pid",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ccolumngrouparray_count,
{
"count", "mswsp.ccolumngrouparray.count",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_int32array_value,
{
"value", "mswsp.int32array.value",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crowseeknext_cskip,
{
"cskip", "mswsp.crowseeknext.cskip",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crowseekat_bmkoffset,
{
"bmkoffset", "mswsp.crowseekat.bmkoffset",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crowseekat_skip,
{
"skip", "mswsp.crowseekat.skip",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crowseekat_hregion,
{
"hregion", "mswsp.crowseekat.hregion",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crowseekatratio_ulnumerator,
{
"ulnumerator", "mswsp.crowseekatratio.ulnumerator",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crowseekatratio_uldenominator,
{
"uldenominator", "mswsp.crowseekatratio.uldenominator",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crowseekatratio_hregion,
{
"hregion", "mswsp.crowseekatratio.hregion",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crowseekbybookmark_cbookmarks,
{
"cbookmarks", "mswsp.crowseekbybookmark.cbookmarks",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crowseekbybookmark_maxret,
{
"maxret", "mswsp.crowseekbybookmark.maxret",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crowvariantinfo_count64,
{
"count", "mswsp.crowvariantinfo.count64",
FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_arrayvector_address64,
{
"address of array", "mswsp.arrayvector.address64",
FT_UINT64, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_crowvariantinfo_count32,
{
"count", "mswsp.crowvariantinfo.count32",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_arrayvector_address32,
{
"address of array", "mswsp.arrayvector.address",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_rowvariant_item_address64,
{
"address", "mswsp.rowvariant.item.address64",
FT_UINT64, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_rowvariant_item_address32,
{
"address", "mswsp.rowvariant.item.address32",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_rowvariant_item_value,
{
"value", "mswsp.rowvariant.item.value",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_rowvariant_vtype,
{
"vtype", "mswsp.rowvariant.vtype",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_rowvariant_reserved1,
{
"reserved1", "mswsp.rowvariant.reserved1",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_rowvariant_reserved2,
{
"reserved2", "mswsp.rowvariant.reserved2",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ctablecolumn_status,
{
"status", "mswsp.ctablecolumn.name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_ctablecolumn_length,
{
"length", "mswsp.ctablecolumn.length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcreatequery_size,
{
"size", "mswsp.cpmcreatequery.size",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcreatequery_ccolumnsetpresent,
{
"CColumnSetPresent", "mswsp.cpmcreatequery.ccolumnsetpresent",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcreatequery_crestrictionpresent,
{
"CRestrictionPresent", "mswsp.cpmcreatequery.crestrictionpresent",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcreatequery_csortpresent,
{
"CSortPresent", "mswsp.cpmcreatequery.csortpresent",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcreatequery_csortset_xxx,
{
"XXX - (undocumented bytes)", "mswsp.cpmcreatequery.csortset.xxx",
FT_UINT64, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcreatequery_ccategpresent,
{
"CCategorizationSetPresent", "mswsp.cpmcreatequery.ccategpresent",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcreatequery_ccateg_count,
{
"count", "mswsp.cpmcreatequery.ccateg.count",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcreatequery_trueseq,
{
"TrueSequential", "mswsp.cpmcreatequery.trueseq",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcreatequery_workid,
{
"WorkId", "mswsp.cpmcreatequery.trueseq",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcreatequery_cursors,
{
"Cursors", "mswsp.cpmcreatequery.cursors",
FT_BYTES, SEP_SPACE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrows_hcursor,
{
"hCursor", "mswsp.msg.cpmgetrows.hcursor",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrows_rowstotransfer,
{
"cRowsToTransfer", "mswsp.msg.cpmgetrows.rowstotransfer",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrows_rowwidth,
{
"cbRowWidth", "mswsp.msg.cpmgetrows.rowswidth",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrows_cbseek,
{
"cbSeek", "mswsp.msg.cpmgetrows.cbseek",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrows_cbreserved,
{
"cbReserved", "mswsp.msg.cpmgetrows.cbreserved",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrows_cbreadbuffer,
{
"cbReadBuffer", "mswsp.msg.cpmgetrows.cbreadbuffer",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrows_ulclientbase,
{
"ulClientBase", "mswsp.msg.cpmgetrows.ulclientbase",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrows_fbwdfetch,
{
"fBwdFetch", "mswsp.msg.cpmgetrows.fbwdfetch",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrows_etype,
{
"eType", "mswsp.msg.cpmgetrows.etype",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrows_chapt,
{
"chapt", "mswsp.msg.cpmgetrows.chapt",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrows_crowsreturned,
{
"cRowsReturned", "mswsp.msg.cpmgetrows.crowsreturned",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmratiofinished_hcursor,
{
"hCursor", "mswsp.msg.cpmratiofinished_hcursor",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmratiofinished_fquick,
{
"fQuick", "mswsp.msg.cpmratiofinished_fquick",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmratiofinished_ulnumerator,
{
"ulNumerator", "mswsp.msg.cpmratiofinished_ulnumerator",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmratiofinished_uldenominator,
{
"ulDenominator", "mswsp.msg.cpmratiofinished_uldenominator",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmratiofinished_crows,
{
"cRows", "mswsp.msg.cpmratiofinished_crows",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmratiofinished_fnewrows,
{
"fNewRows", "mswsp.msg.cpmratiofinished_fnewrows",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcomparebmk_hcursor,
{
"hCursor", "mswsp.msg.cpmcomparebmk.hcursor",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcomparebmk_chapt,
{
"chapt", "mswsp.msg.cpmcomparebmk.chapt",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcomparebmk_bmkfirst,
{
"bmkFirst", "mswsp.msg.cpmcomparebmk.bmkfirst",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcomparebmk_bmksecond,
{
"bmkSecond", "mswsp.msg.cpmcomparebmk.bmksecond",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcomparebmk_dwcomparison,
{
"dwComparison", "mswsp.msg.cpmcomparebmk.dwcomparison",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetapproxpos_hcursor,
{
"hCursor", "mswsp.msg.cpmgetapproxpos.hcursor",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetapproxpos_chapt,
{
"chapt", "mswsp.msg.cpmgetapproxpos.chapt",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetapproxpos_bmk,
{
"bmk", "mswsp.msg.cpmgetapproxpos.bmk",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetapproxpos_numerator,
{
"numerator", "mswsp.msg.cpmgetapproxpos.numerator",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetapproxpos_denominator,
{
"denominator", "mswsp.msg.cpmgetapproxpos.denominator",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmsetbinding_hcursor,
{
"hCursor", "mswsp.msg.cpmsetbinding.hcursor",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmsetbinding_cbrow,
{
"cBrow", "mswsp.msg.cpmsetbinding.cbrow",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmsetbinding_desc,
{
"cbBindingDesc", "mswsp.msg.cpmsetbinding.desc",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmsetbinding_dummy,
{
"dummy", "mswsp.msg.cpmsetbinding.dummy",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmsetbinding_ccolumns,
{
"cColumns", "mswsp.msg.cpmsetbinding.ccolumns",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmsetbinding_acolumns,
{
"aColumns", "mswsp.msg.cpmsetbinding.acolumns",
FT_BYTES, SEP_DOT, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmsendnotify_watchnotify,
{
"watchNotify", "mswsp.msg.cpmsendnotify.watchnotify",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetquerystatus_hcursor,
{
"hCursor", "mswsp.msg.cpmquerystatus.hcursor",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetquerystatus_qstatus,
{
"QStatus", "mswsp.msg.cpmquerystatus.qstatus",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcistate_cbstruct,
{
"cbStruct", "mswsp.msg.cpmcistate.cbstruct",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcistate_cwordlist,
{
"cbWordList", "mswsp.msg.cpmcistate.cbwordlist",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcistate_cpersistindex,
{
"cbPersistentIndex", "mswsp.msg.cpmcistate.cbpersistindex",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcistate_cqueries,
{
"cQueries", "mswsp.msg.cpmcistate.cqueries",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcistate_cfreshtest,
{
"cFreshTest", "mswsp.msg.cpmcistate.cfreshtest",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcistate_dwmergeprogress,
{
"dwMergeProgress", "mswsp.msg.cpmcistate.dwmergeprogress",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcistate_estate,
{
"eState", "mswsp.msg.cpmcistate.estate",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcistate_cfiltereddocs,
{
"cFilteredDocuments", "mswsp.msg.cpmcistate.cfiltereddocs",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcistate_ctotaldocs,
{
"cTotalDocuments", "mswsp.msg.cpmcistate.ctotaldocs",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcistate_cpendingscans,
{
"cPendingScans", "mswsp.msg.cpmcistate.cpendingscans",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcistate_dwindexsize,
{
"dwIndexSize", "mswsp.msg.cpmcistate.dwindexsize",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcistate_cuniquekeys,
{
"cUniqueKeys", "mswsp.msg.cpmcistate.cuniquekeys",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcistate_csecqdocuments,
{
"cSecQDocuments", "mswsp.msg.cpmcistate.csecqdocuments",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmcistate_dwpropcachesize,
{
"dwPropCacheSize", "mswsp.msg.cpmcistate.dwpropcachesize",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmfetchvalue_wid,
{
"wid", "mswsp.msg.cpmfetchvalue.wid",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmfetchvalue_cbsofar,
{
"cbSoFar", "mswsp.msg.cpmfetchvalue.cbsofar",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmfetchvalue_cbpropspec,
{
"cbPropSpec", "mswsp.msg.cpmfetchvalue.cbpropspec",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmfetchvalue_cbchunk,
{
"cbChunk", "mswsp.msg.cpmfetchvalue.chunk",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmfetchvalue_cbvalue,
{
"cbValue", "mswsp.msg.cpmfetchvalue.cbvalue",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmfetchvalue_fmoreexists,
{
"fMoreExists", "mswsp.msg.cpmfetchvalue.fmoreexists",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmfetchvalue_fvalueexists,
{
"fValueExists", "mswsp.msg.cpmfetchvalue.fvalueexists",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmfetchvalue_vvalue,
{
"vvalue", "mswsp.msg.cpmfetchvalue.vvalue",
FT_BYTES, SEP_SPACE, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmquerystatusex_qstatus,
{
"qStatus", "mswsp.msg.cpmquerystatusex.qstatus",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmquerystatusex_hcursor,
{
"hCursor", "mswsp.msg.cpmquerystatusex.hcursor",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmquerystatusex_bmk,
{
"bmk", "mswsp.msg.cpmquerystatusex.bmk",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmquerystatusex_cfiltereddocs,
{
"cFilteredDocuments", "mswsp.msg.cpmquerystatusex.cfiltereddocs",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmquerystatusex_cdocstofilter,
{
"cDocumentsToFilter", "mswsp.msg.cpmquerystatusex.cdocstofilter",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmquerystatusex_dwratiodenom,
{
"dwRatioFinishedDenomenator", "mswsp.msg.cpmquerystatusex.dwratiodenom",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmquerystatusex_dwrationumer,
{
"dwRatioFinishedNumerator", "mswsp.msg.cpmquerystatusex.dwrationumer",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmquerystatusex_irowbmk,
{
"iRowBmk", "mswsp.msg.cpmquerystatusex.irowbmk",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmquerystatusex_crowstotal,
{
"cRowsTotal", "mswsp.msg.cpmquerystatusex.crowstotal",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmquerystatusex_maxrank,
{
"maxRank", "mswsp.msg.cpmquerystatusex.maxrank",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmquerystatusex_cresultsfound,
{
"cResultsFound", "mswsp.msg.cpmquerystatusex.cresultsfound",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmquerystatusex_whereid,
{
"whereId", "mswsp.msg.cpmquerystatusex.whereid",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmrestartposition_hcursor,
{
"hCursor", "mswsp.msg.cpmrestartposition.hcursor",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmrestartposition_chapt,
{
"chapt", "mswsp.msg.cpmrestartposition.chapt",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrowsetnotify_wid,
{
"wid", "mswsp.msg.cpmgetrowsetnotify.wid",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrowsetnotify_moreevents,
{
"moreEvents", "mswsp.msg.cpmgetrowsetnotify.moreevents",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrowsetnotify_eventtype,
{
"eventType", "mswsp.msg.cpmgetrowsetnotify.eventType",
FT_UINT8, BASE_DEC, NULL, 0xFE, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrowsetnotify_rowsetitemstate,
{
"rowSetItemState", "mswsp.msg.cpmgetrowsetnotify.rowsetitemstate",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrowsetnotify_changeditemstate,
{
"changedItemState", "mswsp.msg.cpmgetrowsetnotify.changeditemState",
FT_UINT8, BASE_DEC, NULL, 0, 0, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrowsetnotify_rowsetevent,
{
"rowSetEvent", "mswsp.msg.cpmgetrowsetnotify.rowsetevent",
FT_UINT8, BASE_DEC, NULL, 0, 0, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrowsetnotify_rowseteventdata1,
{
"rowSetEventdata1", "mswsp.msg.cpmgetrowsetnotify.rowseteventdata1",
FT_UINT64, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmgetrowsetnotify_rowseteventdata2,
{
"rowSetEventdata2", "mswsp.msg.cpmgetrowsetnotify.rowseteventdata2",
FT_UINT64, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmfindindices_cwids,
{
"cWids", "mswsp.msg.cpmfindindices.cwids",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmfindindices_cdepthprev,
{
"cDepthPrev", "mswsp.msg.cpmfindindices.cdepthprev",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmfindindices_cdepthnext,
{
"cDepthNext", "mswsp.msg.cpmfindindices.cdepthnext",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmsetscopeprioritization_priority,
{
"priority", "mswsp.msg.cpmsetscopeprioritization.priority",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmsetscopeprioritization_eventfreq,
{
"eventFrequency", "mswsp.msg.cpmsetscopeprioritization.eventfreq",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmsetscopestatisics_dwindexitems,
{
"dwIndexedItems", "mswsp.msg.cpmsetscopestatistics.dwindexitems",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmsetscopestatisics_dwoutstandingadds,
{
"dwOutstandingAdds", "mswsp.msg.cpmsetscopestatistics.dwoutstandingadds",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_mswsp_msg_cpmsetscopestatisics_dwoutstandingmodifies,
{
"dwOutstandingModifies", "mswsp.msg.cpmsetscopestatistics.dwoutstandingmodifies",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
}
};
static gint *ett[] = {
&ett_mswsp,
&ett_mswsp_hdr,
&ett_mswsp_msg,
&ett_mswsp_pad,
&ett_mswsp_property_restriction,
&ett_CRestrictionArray,
&ett_CBaseStorageVariant,
&ett_CBaseStorageVariant_Vector,
&ett_CBaseStorageVariant_Array,
&ett_CDbColId,
&ett_GUID,
&ett_CDbProp,
&ett_CDbPropSet,
&ett_CDbPropSet_Array,
&ett_CRestriction,
&ett_CNodeRestriction,
&ett_CPropertyRestriction,
&ett_CCoercionRestriction,
&ett_CContentRestriction,
&ett_RANGEBOUNDARY,
&ett_CRangeCategSpec,
&ett_CCategSpec,
&ett_CAggregSpec,
&ett_CAggregSet,
&ett_CCategorizationSpec,
&ett_CAggregSortKey,
&ett_CSortAggregSet,
&ett_CInGroupSortAggregSet,
&ett_CInGroupSortAggregSets,
&ett_CRowsetProperties,
&ett_CFullPropSpec,
&ett_CPidMapper,
&ett_CSort,
&ett_CSortSet,
&ett_CNatLanguageRestriction,
&ett_CColumnGroup,
&ett_CColumnGroupArray,
&ett_LCID,
&ett_CTableColumn,
&ett_Array,
&ett_SeekDescription,
&ett_CRowsSeekNext,
&ett_CRowsSeekAt,
&ett_CRowsSeekAtRatio,
&ett_CRowsSeekByBookmark,
&ett_GetRowsRow,
&ett_GetRowsColumn,
&ett_CRowVariant,
&ett_CRowVariant_Vector,
&ett_mswsp_bool_options,
&ett_mswsp_uin32_array,
&ett_mswsp_msg_padding,
&ett_mswsp_msg_creusewhere
};
static ei_register_info ei[] = {
{ &ei_missing_msg_context, { "mswsp.msg.cpmgetrows.missing_msg_context", PI_SEQUENCE, PI_WARN, "previous messages needed for context not captured", EXPFILL }},
{ &ei_mswsp_msg_cpmsetbinding_ccolumns, { "mswsp.msg.cpmsetbinding.ccolumns.invalude", PI_PROTOCOL, PI_WARN, "Invalid number of cColumns for packet", EXPFILL }}
};
int i;
proto_mswsp = proto_register_protocol("Windows Search Protocol",
"MS-WSP", "mswsp");
proto_register_field_array(proto_mswsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_mswsp = expert_register_protocol(proto_mswsp);
expert_register_field_array(expert_mswsp, ei, array_length(ei));
for (i=0; i<(int)array_length(GuidPropertySet); i++) {
guids_add_guid(&GuidPropertySet[i].guid, GuidPropertySet[i].def);
}
register_init_routine(&mswsp_init_protocol);
}
static int dissect_mswsp_smb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
smb_info_t *si = (smb_info_t*)data;
gboolean in = si->request;
smb_fid_info_t *fid_info = NULL;
fid_info = find_fid_info(si);
if (!fid_info || !fid_info->fsi || !fid_info->fsi->filename) {
return 0;
}
if (g_ascii_strcasecmp(fid_info->fsi->filename, "\\MsFteWds") != 0) {
return 0;
}
p_add_proto_data(wmem_file_scope(), pinfo, proto_mswsp, 0, (void*)&SMB1);
return dissect_mswsp(tvb, pinfo, tree, in, data);
}
static int dissect_mswsp_smb2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
smb2_info_t *si = (smb2_info_t*)data;
gboolean in;
char* fid_name = NULL;
guint32 open_frame = 0, close_frame = 0;
if (!si) {
return 0;
}
if (si->saved) {
dcerpc_fetch_polhnd_data(&si->saved->policy_hnd, &fid_name, NULL, &open_frame, &close_frame, pinfo->num);
}
if (!fid_name || strcmp(fid_name, "File: MsFteWds") != 0) {
return 0;
}
in = !(si->flags & SMB2_FLAGS_RESPONSE);
p_add_proto_data(wmem_file_scope(), pinfo, proto_mswsp, 0, (void*)&SMB2);
return dissect_mswsp(tvb, pinfo, tree, in, data);
}
void
proto_reg_handoff_mswsp(void)
{
heur_dissector_add("smb_transact", dissect_mswsp_smb, "WSP over SMB1", "smb1_wsp", proto_mswsp, HEURISTIC_ENABLE);
heur_dissector_add("smb2_pipe_subdissectors", dissect_mswsp_smb2, "WSP over SMB2", "smb2_wsp", proto_mswsp, HEURISTIC_ENABLE);
}
