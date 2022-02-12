int
dissect_ndr_datablob(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hf_index,
int use_remaining_space)
{
proto_item *item;
guint3264 len;
proto_tree *subtree;
subtree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_nt_data_blob, &item,
proto_registrar_get_name(hf_index));
if (use_remaining_space) {
len = tvb_captured_length_remaining (tvb, offset);
} else {
offset = dissect_ndr_uint3264(tvb, offset, pinfo, subtree, di, drep,
hf_nt_data_blob_len, &len);
}
proto_tree_add_item(subtree, hf_nt_data_blob_data, tvb, offset, (int)len, ENC_NA);
offset += (int)len;
return offset;
}
int
dissect_null_term_string(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree,
guint8 *drep _U_, int hf_index, int levels _U_)
{
guint len;
len = tvb_strsize(tvb, offset);
proto_tree_add_item(tree, hf_index, tvb, offset, len, ENC_ASCII|ENC_NA);
return offset + len;
}
int
dissect_null_term_wstring(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree,
guint8 *drep _U_, int hf_index, int levels _U_)
{
guint len;
len = tvb_unicode_strsize(tvb, offset);
proto_tree_add_item(tree, hf_index, tvb, offset, len, ENC_UTF_16|ENC_LITTLE_ENDIAN);
return offset + len;
}
int
dissect_ndr_counted_string_cb(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep, int hf_index,
dcerpc_callback_fnct_t *callback,
void *callback_args)
{
guint16 len, size;
ALIGN_TO_5_BYTES;
if (di->conformant_run)
return offset;
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep,
hf_nt_cs_len, &len);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep,
hf_nt_cs_size, &size);
offset = dissect_ndr_pointer_cb(tvb, offset, pinfo, tree, di, drep,
dissect_ndr_wchar_cvstring, NDR_POINTER_UNIQUE,
"Character Array", hf_index, callback, callback_args);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
dissect_ndr_counted_string_helper(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep, int hf_index, int levels,
gboolean add_subtree)
{
proto_item *item;
proto_tree *subtree = tree;
if (add_subtree) {
subtree = proto_tree_add_subtree(
tree, tvb, offset, 0, ett_nt_counted_string, &item,
proto_registrar_get_name(hf_index));
}
return dissect_ndr_counted_string_cb(
tvb, offset, pinfo, subtree, di, drep, hf_index,
cb_wstr_postprocess, GINT_TO_POINTER(2 + levels));
}
int
dissect_ndr_counted_string(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep, int hf_index, int levels)
{
return dissect_ndr_counted_string_helper(
tvb, offset, pinfo, tree, di, drep, hf_index, levels, TRUE);
}
int
dissect_ndr_counted_string_ptr(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
return dissect_ndr_counted_string_helper(
tvb, offset, pinfo, tree, di, drep, di->hf_index, 0, FALSE);
}
int
dissect_ndr_counted_byte_array_cb(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep, int hf_index,
dcerpc_callback_fnct_t *callback,
void *callback_args)
{
proto_item *item;
proto_tree *subtree;
guint16 len, size;
ALIGN_TO_5_BYTES;
if (di->conformant_run)
return offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_nt_counted_byte_array, &item,
proto_registrar_get_name(hf_index));
offset = dissect_ndr_uint16(tvb, offset, pinfo, subtree, di, drep,
hf_nt_cs_len, &len);
offset = dissect_ndr_uint16(tvb, offset, pinfo, subtree, di, drep,
hf_nt_cs_size, &size);
offset = dissect_ndr_pointer_cb(tvb, offset, pinfo, subtree, di, drep,
dissect_ndr_char_cvstring, NDR_POINTER_UNIQUE,
"Byte Array", hf_index, callback, callback_args);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static void cb_byte_array_postprocess(packet_info *pinfo, proto_tree *tree _U_,
proto_item *item, dcerpc_info *di _U_, tvbuff_t *tvb,
int start_offset, int end_offset,
void *callback_args)
{
gint options = GPOINTER_TO_INT(callback_args);
gint levels = CB_STR_ITEM_LEVELS(options);
char *s;
if (start_offset % 4)
start_offset += 4 - (start_offset % 4);
if ((end_offset - start_offset) <= 12)
return;
s = tvb_bytes_to_str(wmem_packet_scope(), tvb, start_offset + 12, (end_offset - start_offset - 12) );
if (options & CB_STR_COL_INFO) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", s);
}
if (levels > 0 && item && s && s[0]) {
proto_item_append_text(item, ": %s", s);
item = GET_ITEM_PARENT(item);
levels--;
if (levels > 0) {
proto_item_append_text(item, ": %s", s);
item = GET_ITEM_PARENT(item);
levels--;
while (levels > 0) {
proto_item_append_text(item, " %s", s);
item = GET_ITEM_PARENT(item);
levels--;
}
}
}
}
int
dissect_ndr_counted_byte_array(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep, int hf_index, int levels)
{
return dissect_ndr_counted_byte_array_cb(
tvb, offset, pinfo, tree, di, drep, hf_index, cb_byte_array_postprocess, GINT_TO_POINTER(2 + levels));
}
int
dissect_ndr_counted_ascii_string_cb(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep, int hf_index,
dcerpc_callback_fnct_t *callback,
void *callback_args)
{
proto_item *item;
proto_tree *subtree;
guint16 len, size;
ALIGN_TO_5_BYTES;
if (di->conformant_run)
return offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_nt_counted_ascii_string, &item,
proto_registrar_get_name(hf_index));
offset = dissect_ndr_uint16(tvb, offset, pinfo, subtree, di, drep,
hf_nt_cs_len, &len);
offset = dissect_ndr_uint16(tvb, offset, pinfo, subtree, di, drep,
hf_nt_cs_size, &size);
offset = dissect_ndr_pointer_cb(tvb, offset, pinfo, subtree, di, drep,
dissect_ndr_char_cvstring, NDR_POINTER_UNIQUE,
"Ascii String", hf_index, callback, callback_args);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
dissect_ndr_counted_ascii_string(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep, int hf_index, int levels)
{
return dissect_ndr_counted_ascii_string_cb(
tvb, offset, pinfo, tree, di, drep, hf_index, cb_str_postprocess, GINT_TO_POINTER(2 + levels));
}
int
dissect_nt_GUID(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset=dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_nt_guid, NULL);
return offset;
}
int
dissect_ndr_lsa_String(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, dcerpc_info *di, guint8 *drep, guint32 param, int hfindex)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
header_field_info *hf_info;
ALIGN_TO_5_BYTES;
old_offset = offset;
hf_info=proto_registrar_get_nth(hfindex);
if (parent_tree) {
tree = proto_tree_add_subtree_format(parent_tree, tvb, offset, 0, ett_lsa_String, &item, "%s: ", hf_info->name);
}
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_lsa_String_name_len, 0);
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_lsa_String_name_size, 0);
offset = dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, di, drep,
dissect_ndr_wchar_cvstring, NDR_POINTER_UNIQUE,
hf_info->name, hfindex, cb_wstr_postprocess,
GINT_TO_POINTER(param));
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
dissect_ndr_nt_NTTIME (tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree,
dcerpc_info *di, guint8 *drep _U_, int hf_index)
{
if(di->conformant_run){
return offset;
}
ALIGN_TO_4_BYTES;
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_index);
return offset;
}
int
dissect_ndr_nt_NTTIME_hyper (tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree,
dcerpc_info *di, guint8 *drep _U_, int hf_index, gboolean onesec_resolution)
{
if(di->conformant_run){
return offset;
}
ALIGN_TO_8_BYTES;
offset = dissect_nt_64bit_time_opt(tvb, tree, offset, hf_index, onesec_resolution);
return offset;
}
static guint pol_hash_fn(gconstpointer k)
{
const pol_hash_key *key = (const pol_hash_key *)k;
return key->policy_hnd[4] + (key->policy_hnd[5] << 8) +
(key->policy_hnd[6] << 16) + (key->policy_hnd[7] << 24);
}
static gboolean is_null_pol(e_ctx_hnd *policy_hnd)
{
static guint8 null_policy_hnd[20];
return memcmp(policy_hnd, null_policy_hnd, 20) == 0;
}
static gint pol_hash_compare(gconstpointer k1, gconstpointer k2)
{
const pol_hash_key *key1 = (const pol_hash_key *)k1;
const pol_hash_key *key2 = (const pol_hash_key *)k2;
return memcmp(key1->policy_hnd, key2->policy_hnd,
sizeof(key1->policy_hnd)) == 0;
}
static pol_value *find_pol_handle(e_ctx_hnd *policy_hnd, guint32 frame,
pol_hash_value **valuep)
{
pol_hash_key key;
pol_value *pol;
memcpy(&key.policy_hnd, policy_hnd, sizeof(key.policy_hnd));
if ((*valuep = (pol_hash_value *)wmem_map_lookup(pol_hash, &key))) {
for (pol = (*valuep)->list; pol != NULL; pol = pol->next) {
if (pol->first_frame <= frame &&
(pol->last_frame == 0 ||
pol->last_frame >= frame))
break;
}
return pol;
} else {
return NULL;
}
}
static void add_pol_handle(e_ctx_hnd *policy_hnd, guint32 frame,
pol_value *pol, pol_hash_value *value)
{
pol_hash_key *key;
pol_value *polprev, *polnext;
if (value == NULL) {
value = (pol_hash_value *)wmem_alloc(wmem_file_scope(), sizeof(pol_hash_value));
value->list = pol;
pol->next = NULL;
key = (pol_hash_key *)wmem_alloc(wmem_file_scope(), sizeof(pol_hash_key));
memcpy(&key->policy_hnd, policy_hnd, sizeof(key->policy_hnd));
wmem_map_insert(pol_hash, key, value);
} else {
for (polnext = value->list, polprev = NULL;
polnext != NULL && polnext->first_frame <= frame;
polprev = polnext, polnext = polnext->next)
;
if (polprev == NULL)
value->list = pol;
else
polprev->next = pol;
pol->next = polnext;
}
}
void dcerpc_smb_store_pol_pkts(e_ctx_hnd *policy_hnd, packet_info *pinfo,
gboolean is_open, gboolean is_close)
{
pol_hash_value *value;
pol_value *pol;
if (pinfo->fd->flags.visited)
return;
if (is_null_pol(policy_hnd))
return;
pol = find_pol_handle(policy_hnd, pinfo->num, &value);
if (pol != NULL) {
if (is_open) {
if (pol->first_frame == pinfo->num &&
pol->last_frame == 0)
return;
pol->last_frame = pinfo->num;
pol = NULL;
} else {
if (is_close) {
pol->close_frame = pinfo->num;
pol->last_frame = pinfo->num;
}
return;
}
}
pol = (pol_value *)wmem_alloc(wmem_file_scope(), sizeof(pol_value));
pol->open_frame = is_open ? pinfo->num : 0;
pol->close_frame = is_close ? pinfo->num : 0;
pol->first_frame = pinfo->num;
pol->last_frame = pol->close_frame;
pol->type=0;
pol->name = NULL;
add_pol_handle(policy_hnd, pinfo->num, pol, value);
}
static void dcerpc_store_polhnd_type(e_ctx_hnd *policy_hnd, packet_info *pinfo,
guint32 type)
{
pol_hash_value *value;
pol_value *pol;
if (pinfo->fd->flags.visited)
return;
if (is_null_pol(policy_hnd))
return;
pol = find_pol_handle(policy_hnd, pinfo->num, &value);
if (pol != NULL) {
pol->type=type;
}
}
void dcerpc_store_polhnd_name(e_ctx_hnd *policy_hnd, packet_info *pinfo,
const char *name)
{
pol_hash_value *value;
pol_value *pol;
if (pinfo->fd->flags.visited)
return;
if (is_null_pol(policy_hnd))
return;
pol = find_pol_handle(policy_hnd, pinfo->num, &value);
if (pol != NULL) {
if (pol->name && name) {
#ifdef DEBUG_HASH_COLL
if (strcmp(pol->name, name) != 0)
ws_g_warning("dcerpc_smb: pol_hash name collision %s/%s\n", value->name, name);
#endif
}
pol->name = wmem_strdup(wmem_file_scope(), name);
return;
}
pol = (pol_value *)wmem_alloc(wmem_file_scope(), sizeof(pol_value));
pol->open_frame = 0;
pol->close_frame = 0;
pol->first_frame = pinfo->num;
pol->last_frame = 0;
pol->type = 0;
if (name)
pol->name = wmem_strdup(wmem_file_scope(), name);
else
pol->name = wmem_strdup(wmem_file_scope(), "<UNKNOWN>");
add_pol_handle(policy_hnd, pinfo->num, pol, value);
}
gboolean dcerpc_fetch_polhnd_data(e_ctx_hnd *policy_hnd,
char **name, guint32 *type,
guint32 *open_frame, guint32 *close_frame,
guint32 cur_frame)
{
pol_hash_value *value;
pol_value *pol;
if (name)
*name = NULL;
if (type)
*type = 0;
if (open_frame)
*open_frame = 0;
if (close_frame)
*close_frame = 0;
pol = find_pol_handle(policy_hnd, cur_frame, &value);
if (pol) {
if (name)
*name = pol->name;
if (type)
*type = pol->type;
if (open_frame)
*open_frame = pol->open_frame;
if (close_frame)
*close_frame = pol->close_frame;
}
return pol != NULL;
}
int
dissect_ntstatus(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint32 *pdata)
{
guint32 status;
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hfindex, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str_ext(status, &NT_errors_ext,
"Unknown error 0x%08x"));
if (pdata)
*pdata = status;
return offset;
}
int
dissect_doserror(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint32 *pdata)
{
guint32 status;
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hfindex, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str_ext(status, &DOS_errors_ext,
"Unknown error 0x%08x"));
if (pdata)
*pdata = status;
return offset;
}
static int
dissect_nt_hnd(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex,
e_ctx_hnd *pdata, proto_item **pitem,
gboolean is_open, gboolean is_close, e_hnd_type type)
{
proto_item *item=NULL;
proto_tree *subtree;
e_ctx_hnd hnd;
guint32 open_frame = 0, close_frame = 0;
char *name;
int old_offset = offset;
if(di->conformant_run){
return offset;
}
switch(type){
case HND_TYPE_CTX_HANDLE:
if (!di->no_align && (offset % 4)) {
offset += 4 - (offset % 4);
}
subtree = proto_tree_add_subtree(tree, tvb, offset, sizeof(e_ctx_hnd),
ett_nt_policy_hnd, &item, "Policy Handle");
offset = dissect_ndr_ctx_hnd(tvb, offset, pinfo, subtree, di, drep,
hfindex, &hnd);
break;
case HND_TYPE_GUID:
subtree = proto_tree_add_subtree(tree, tvb, offset, 16,
ett_nt_policy_hnd, &item, "GUID handle");
hnd.attributes=0;
offset=dissect_ndr_uuid_t(tvb, offset, pinfo, subtree, di, drep, hfindex, &hnd.uuid);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
return offset;
}
dcerpc_smb_store_pol_pkts(&hnd, pinfo, is_open, is_close);
if (dcerpc_fetch_polhnd_data(&hnd, &name, NULL, &open_frame,
&close_frame, pinfo->num)) {
if (open_frame) {
proto_item *item_local;
item_local=proto_tree_add_uint(
subtree, hf_nt_policy_open_frame, tvb,
old_offset, sizeof(e_ctx_hnd), open_frame);
PROTO_ITEM_SET_GENERATED(item_local);
}
if (close_frame) {
proto_item *item_local;
item_local=proto_tree_add_uint(
subtree, hf_nt_policy_close_frame, tvb,
old_offset, sizeof(e_ctx_hnd), close_frame);
PROTO_ITEM_SET_GENERATED(item_local);
}
if (name != NULL && pitem == NULL)
proto_item_append_text(item, ": %s", name);
}
if (pdata)
*pdata = hnd;
if (pitem)
*pitem = item;
return offset;
}
int
dissect_nt_policy_hnd(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex,
e_ctx_hnd *pdata, proto_item **pitem,
gboolean is_open, gboolean is_close)
{
offset=dissect_nt_hnd(tvb, offset, pinfo,
tree, di, drep, hfindex,
pdata, pitem,
is_open, is_close, HND_TYPE_CTX_HANDLE);
return offset;
}
int
PIDL_dissect_policy_hnd(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info* di, guint8 *drep, int hfindex,
guint32 param)
{
e_ctx_hnd policy_hnd;
offset=dissect_nt_hnd(tvb, offset, pinfo,
tree, di, drep, hfindex,
&policy_hnd, NULL,
param&PIDL_POLHND_OPEN, param&PIDL_POLHND_CLOSE,
HND_TYPE_CTX_HANDLE);
if((param&PIDL_POLHND_OPEN)
&& !pinfo->fd->flags.visited
&& !di->conformant_run){
char *pol_string=NULL;
const char *pol_name=NULL;
dcerpc_call_value *dcv;
dcv = (dcerpc_call_value *)di->call_data;
pol_name = (const char *)dcv->private_data;
if(!pol_name){
pol_name="<...>";
}
pol_string=wmem_strdup_printf(wmem_packet_scope(), "%s(%s)", di->dcerpc_procedure_name, pol_name);
dcerpc_store_polhnd_name(&policy_hnd, pinfo, pol_string);
dcerpc_store_polhnd_type(&policy_hnd, pinfo, param&PIDL_POLHND_TYPE_MASK);
}
if(!pinfo->fd->flags.visited
&& !di->conformant_run){
dcerpc_call_value *dcv;
dcv = (dcerpc_call_value *)di->call_data;
if(!dcv->pol){
dcv->pol=(e_ctx_hnd *)wmem_memdup(wmem_file_scope(), &policy_hnd, sizeof(e_ctx_hnd));
}
}
return offset;
}
int
dissect_nt_guid_hnd(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex,
e_ctx_hnd *pdata, proto_item **pitem,
gboolean is_open, gboolean is_close)
{
offset=dissect_nt_hnd(tvb, offset, pinfo,
tree, di, drep, hfindex,
pdata, pitem,
is_open, is_close, HND_TYPE_GUID);
return offset;
}
int
dissect_dcerpc_uint8s(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, dcerpc_info *di _U_, guint8 *drep _U_, int hfindex,
int length, const guint8 **pdata)
{
const guint8 *data;
data = (const guint8 *)tvb_get_ptr(tvb, offset, length);
if (tree) {
proto_tree_add_item (tree, hfindex, tvb, offset, length, ENC_NA);
}
if (pdata)
*pdata = data;
return offset + length;
}
int
dissect_ndr_uint8s(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, int length, const guint8 **pdata)
{
if(di->conformant_run){
return offset;
}
return dissect_dcerpc_uint8s(tvb, offset, pinfo,
tree, di, drep, hfindex, length, pdata);
}
int
dissect_dcerpc_uint16s(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, guint8 *drep, int hfindex,
int length)
{
if (tree) {
proto_tree_add_item (tree, hfindex, tvb, offset, length * 2, DREP_ENC_INTEGER(drep));
}
return offset + length * 2;
}
int
dissect_ndr_uint16s(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, int length)
{
if(di->conformant_run){
return offset;
}
if (offset % 2)
offset++;
return dissect_dcerpc_uint16s(tvb, offset, pinfo,
tree, drep, hfindex, length);
}
void cb_wstr_postprocess(packet_info *pinfo, proto_tree *tree _U_,
proto_item *item, dcerpc_info *di, tvbuff_t *tvb,
int start_offset, int end_offset,
void *callback_args)
{
gint options = GPOINTER_TO_INT(callback_args);
gint levels = CB_STR_ITEM_LEVELS(options);
char *s;
if (start_offset % 4)
start_offset += 4 - (start_offset % 4);
if ((end_offset - start_offset) <= 12)
return;
s = tvb_get_string_enc(wmem_packet_scope(),
tvb, start_offset + 12, end_offset - start_offset - 12,
ENC_UTF_16|ENC_LITTLE_ENDIAN);
if (options & CB_STR_COL_INFO) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", s);
}
if (levels > 0 && item && s && s[0]) {
proto_item_append_text(item, ": %s", s);
item = GET_ITEM_PARENT(item);
levels--;
if (item && levels > 0) {
proto_item_append_text(item, ": %s", s);
item = GET_ITEM_PARENT(item);
levels--;
while (item && levels > 0) {
proto_item_append_text(item, " %s", s);
item = GET_ITEM_PARENT(item);
levels--;
}
}
}
if (options & CB_STR_SAVE) {
dcerpc_call_value *dcv = (dcerpc_call_value *)di->call_data;
dcv->private_data = wmem_strdup(wmem_file_scope(), s);
}
}
void cb_str_postprocess(packet_info *pinfo, proto_tree *tree _U_,
proto_item *item, dcerpc_info *di, tvbuff_t *tvb,
int start_offset, int end_offset,
void *callback_args)
{
gint options = GPOINTER_TO_INT(callback_args);
gint levels = CB_STR_ITEM_LEVELS(options);
guint8 *s;
if (start_offset % 4)
start_offset += 4 - (start_offset % 4);
if ((end_offset - start_offset) <= 12)
return;
s = tvb_get_string_enc(wmem_packet_scope(),
tvb, start_offset + 12, (end_offset - start_offset - 12), ENC_ASCII);
if (options & CB_STR_COL_INFO) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", s);
}
if (levels > 0 && item && s && s[0]) {
proto_item_append_text(item, ": %s", s);
item = GET_ITEM_PARENT(item);
levels--;
if (levels > 0) {
proto_item_append_text(item, ": %s", s);
item = GET_ITEM_PARENT(item);
levels--;
while (levels > 0) {
proto_item_append_text(item, " %s", s);
item = GET_ITEM_PARENT(item);
levels--;
}
}
}
if (options & CB_STR_SAVE) {
dcerpc_call_value *dcv = (dcerpc_call_value *)di->call_data;
dcv->private_data = wmem_strdup(wmem_file_scope(), s);
}
}
int dissect_ndr_str_pointer_item(tvbuff_t *tvb, gint offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep, int type, const char *text,
int hf_index, int levels)
{
return dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, di, drep,
dissect_ndr_wchar_cvstring, type, text, hf_index,
cb_wstr_postprocess, GINT_TO_POINTER(levels + 1));
}
int
dissect_ndr_nt_SID28(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep _U_)
{
proto_item *item;
dcerpc_call_value *dcv = (dcerpc_call_value *)di->call_data;
char *sid_str=NULL;
const char *name;
int newoffset;
if(di->hf_index!=-1){
name=proto_registrar_get_name(di->hf_index);
} else {
name="Domain";
}
if(di->conformant_run){
return offset;
}
newoffset = dissect_nt_sid(tvb, offset, tree, name, &sid_str,
hf_nt_domain_sid);
if ((newoffset - offset) > 28) {
item = proto_tree_get_parent(tree? tree->last_child : NULL);
expert_add_info(pinfo, item, &ei_dcerpc_nt_badsid);
return newoffset;
}
if (tree) {
item = proto_tree_get_parent(tree->last_child);
proto_item_set_len(item, 28);
}
offset += 28;
if(dcv){
dcv->private_data = wmem_strdup(wmem_file_scope(), sid_str);
}
return offset;
}
int
dissect_ndr_nt_SID(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
dcerpc_call_value *dcv = (dcerpc_call_value *)di->call_data;
char *sid_str=NULL;
const char *name;
if(di->hf_index!=-1){
name=proto_registrar_get_name(di->hf_index);
} else {
name="Domain";
}
if(di->conformant_run){
return offset;
}
offset = dissect_ndr_uint3264 (tvb, offset, pinfo, tree, di, drep,
hf_nt_count, NULL);
offset = dissect_nt_sid(tvb, offset, tree, name, &sid_str,
hf_nt_domain_sid);
if(dcv){
dcv->private_data = wmem_strdup(wmem_file_scope(), sid_str);
}
return offset;
}
int
dissect_ndr_nt_SID_with_options(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep, guint32 options)
{
dcerpc_call_value *dcv = (dcerpc_call_value *)di->call_data;
gint levels = CB_STR_ITEM_LEVELS(options);
offset=dissect_ndr_nt_SID(tvb, offset, pinfo, tree, di, drep);
if(dcv && dcv->private_data){
char *s=(char *)dcv->private_data;
proto_item *item=(proto_item *)tree;
if ((options & CB_STR_COL_INFO)&&(!di->conformant_run)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", s);
}
if (levels > 0 && item && s && s[0]) {
proto_item_append_text(item, ": %s", s);
item = GET_ITEM_PARENT(item);
levels--;
if (levels > 0) {
proto_item_append_text(item, ": %s", s);
item = GET_ITEM_PARENT(item);
levels--;
while (levels > 0) {
proto_item_append_text(item, " %s", s);
item = GET_ITEM_PARENT(item);
levels--;
}
}
}
}
return offset;
}
static int
dissect_ndr_nt_SID_hf_through_ptr(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_nt_SID(tvb, offset, pinfo, tree, di, drep);
return offset;
}
int
dissect_ndr_nt_PSID(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
dcerpc_info *di, guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
if(parent_tree){
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1,
ett_nt_sid_pointer, &item, "SID pointer:");
}
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_ndr_nt_SID_hf_through_ptr, NDR_POINTER_UNIQUE,
"SID pointer", hf_nt_domain_sid);
proto_item_set_len(item, offset-old_offset);
return offset;
}
int
dissect_ndr_nt_acct_ctrl(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *parent_tree, dcerpc_info *di, guint8 *drep)
{
guint32 mask;
static const int * flags[] = {
&hf_nt_acb_autolock,
&hf_nt_acb_pwnoexp,
&hf_nt_acb_svrtrust,
&hf_nt_acb_wstrust,
&hf_nt_acb_domtrust,
&hf_nt_acb_mns,
&hf_nt_acb_normal,
&hf_nt_acb_tempdup,
&hf_nt_acb_pwnotreq,
&hf_nt_acb_homedirreq,
&hf_nt_acb_disabled,
NULL
};
offset=dissect_ndr_uint32(tvb, offset, pinfo, NULL, di, drep, -1, &mask);
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset-4, hf_nt_acct_ctrl,
ett_nt_acct_ctrl, flags, mask, BMT_NO_APPEND);
return offset;
}
static int
dissect_LOGON_HOURS_entry(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, di, drep,
hf_logonhours_unknown_char, NULL);
return offset;
}
static int
dissect_LOGON_HOURS_hours(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
dcerpc_info *di, guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
if(parent_tree){
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1,
ett_nt_logon_hours_hours, &item, "LOGON_HOURS:");
}
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep,
dissect_LOGON_HOURS_entry);
proto_item_set_len(item, offset-old_offset);
return offset;
}
int
dissect_ndr_nt_LOGON_HOURS(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
dcerpc_info *di, guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
ALIGN_TO_4_BYTES;
if(parent_tree){
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1,
ett_nt_logon_hours, &item, "LOGON_HOURS:");
}
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep,
hf_logonhours_divisions, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_LOGON_HOURS_hours, NDR_POINTER_UNIQUE,
"LOGON_HOURS", -1);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_ndr_nt_PSID_no_hf(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
dcerpc_info *di, guint8 *drep)
{
offset=dissect_ndr_nt_PSID(tvb, offset, pinfo, parent_tree, di, drep);
return offset;
}
static int
dissect_ndr_nt_PSID_ARRAY_sids (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep,
dissect_ndr_nt_PSID_no_hf);
return offset;
}
int
dissect_ndr_nt_PSID_ARRAY(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
dcerpc_info *di, guint8 *drep)
{
guint32 count;
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
if(parent_tree){
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1,
ett_nt_sid_array, &item, "SID array:");
}
ALIGN_TO_5_BYTES;
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, di, drep,
hf_nt_count, &count);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_ndr_nt_PSID_ARRAY_sids, NDR_POINTER_UNIQUE,
"PSID_ARRAY", -1);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
dissect_ndr_nt_SID_AND_ATTRIBUTES(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
dcerpc_info *di, guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
if(parent_tree){
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0,
ett_nt_sid_and_attributes, &item, "SID_AND_ATTRIBUTES:");
}
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, di, drep);
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, di, drep,
hf_nt_attrib, NULL);
return offset;
}
int
dissect_ndr_nt_SID_AND_ATTRIBUTES_ARRAY(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
dcerpc_info *di, guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
if(parent_tree){
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0,
ett_nt_sid_and_attributes_array, &item, "SID_AND_ATTRIBUTES array:");
}
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep,
dissect_ndr_nt_SID_AND_ATTRIBUTES);
proto_item_set_len(item, offset-old_offset);
return offset;
}
int
nt_dissect_MIDL_NDRHEADERBLOB(proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint8 *drep)
{
proto_tree *tree;
guint8 val;
tree=proto_tree_add_subtree(parent_tree, tvb, offset, 16, ett_nt_MIDL_BLOB, NULL, "MES header");
proto_tree_add_item(tree, hf_nt_midl_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
val = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_dcerpc_drep_byteorder, tvb, offset, 1, val>>4);
offset++;
if (drep) {
*drep = val;
}
proto_tree_add_item(tree, hf_nt_midl_hdr_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_nt_midl_fill_bytes, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_nt_midl_blob_len, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
return offset;
}
void dcerpc_smb_init(int proto_dcerpc)
{
expert_module_t* expert_dcerpc_nt;
static hf_register_info hf[] = {
{ &hf_nt_cs_size,
{ "Size", "dcerpc.nt.str.size", FT_UINT16, BASE_DEC,
NULL, 0x0, "Size of string in short integers",
HFILL }},
{ &hf_nt_cs_len,
{ "Length", "dcerpc.nt.str.len", FT_UINT16, BASE_DEC,
NULL, 0x0, "Length of string in short integers",
HFILL }},
{ &hf_nt_guid,
{ "GUID", "dcerpc.nt.guid", FT_GUID, BASE_NONE,
NULL, 0x0, "GUID (uuid for groups?)", HFILL }},
{ &hf_nt_policy_open_frame,
{ "Frame handle opened", "dcerpc.nt.open_frame",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nt_policy_close_frame,
{ "Frame handle closed", "dcerpc.nt.close_frame",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nt_acct_ctrl,
{ "Acct Ctrl", "dcerpc.nt.acct_ctrl", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_nt_acb_disabled,
{ "Account disabled", "dcerpc.nt.acb.disabled", FT_BOOLEAN, 32,
TFS(&tfs_nt_acb_disabled), 0x0001,
"If this account is enabled or disabled", HFILL }},
{ &hf_nt_acb_homedirreq,
{ "Home dir required", "dcerpc.nt.acb.homedirreq", FT_BOOLEAN, 32,
TFS(&tfs_nt_acb_homedirreq), 0x0002,
"Is homedirs required for this account?", HFILL }},
{ &hf_nt_acb_pwnotreq,
{ "Password required", "dcerpc.nt.acb.pwnotreq", FT_BOOLEAN, 32,
TFS(&tfs_nt_acb_pwnotreq), 0x0004,
"If a password is required for this account?", HFILL }},
{ &hf_nt_acb_tempdup,
{ "Temporary duplicate account", "dcerpc.nt.acb.tempdup", FT_BOOLEAN, 32,
TFS(&tfs_nt_acb_tempdup), 0x0008,
"If this is a temporary duplicate account", HFILL }},
{ &hf_nt_acb_normal,
{ "Normal user account", "dcerpc.nt.acb.normal", FT_BOOLEAN, 32,
TFS(&tfs_nt_acb_normal), 0x0010,
"If this is a normal user account", HFILL }},
{ &hf_nt_acb_mns,
{ "MNS logon user account", "dcerpc.nt.acb.mns", FT_BOOLEAN, 32,
TFS(&tfs_nt_acb_mns), 0x0020,
NULL, HFILL }},
{ &hf_nt_acb_domtrust,
{ "Interdomain trust account", "dcerpc.nt.acb.domtrust", FT_BOOLEAN, 32,
TFS(&tfs_nt_acb_domtrust), 0x0040,
NULL, HFILL }},
{ &hf_nt_acb_wstrust,
{ "Workstation trust account", "dcerpc.nt.acb.wstrust", FT_BOOLEAN, 32,
TFS(&tfs_nt_acb_wstrust), 0x0080,
NULL, HFILL }},
{ &hf_nt_acb_svrtrust,
{ "Server trust account", "dcerpc.nt.acb.svrtrust", FT_BOOLEAN, 32,
TFS(&tfs_nt_acb_svrtrust), 0x0100,
NULL, HFILL }},
{ &hf_nt_acb_pwnoexp,
{ "Password expires", "dcerpc.nt.acb.pwnoexp", FT_BOOLEAN, 32,
TFS(&tfs_nt_acb_pwnoexp), 0x0200,
"If this account expires or not", HFILL }},
{ &hf_nt_acb_autolock,
{ "Account is autolocked", "dcerpc.nt.acb.autolock", FT_BOOLEAN, 32,
TFS(&tfs_nt_acb_autolock), 0x0400,
"If this account has been autolocked", HFILL }},
{ &hf_nt_error,
{ "Wrong string type", "dcerpc.nt.sting_error",
FT_STRING, BASE_NONE, NULL, 0x0,
"Non terminated string", HFILL }},
{ &hf_nt_domain_sid,
{ "Domain SID", "dcerpc.nt.domain_sid",
FT_STRING, BASE_NONE, NULL, 0x0,
"The Domain SID", HFILL }},
{ &hf_nt_count,
{ "Count", "dcerpc.nt.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of elements in following array", HFILL }},
{ &hf_logonhours_divisions,
{ "Divisions", "dcerpc.nt.logonhours.divisions",
FT_UINT16, BASE_DEC, NULL, 0,
"Number of divisions for LOGON_HOURS", HFILL }},
{ &hf_logonhours_unknown_char,
{ "Unknown char", "dcerpc.nt.unknown.char",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Unknown char. If you know what this is, contact wireshark developers.", HFILL }},
{ &hf_nt_attrib,
{ "Attributes", "dcerpc.nt.attr",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_lsa_String_name_len,
{ "Name Len", "dcerpc.lsa_String.name_len",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_lsa_String_name_size,
{ "Name Size", "dcerpc.lsa_String.name_size",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nt_data_blob_len,
{ "Blob size", "dcerpc.nt.blob.size",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nt_data_blob_data,
{ "Blob data", "dcerpc.nt.blob.data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nt_midl_blob_len, {
"Blob Length", "nt.midl_blob_len", FT_UINT64, BASE_DEC,
NULL, 0, "Length of NDR encoded data that follows", HFILL }},
{ &hf_nt_midl_fill_bytes, {
"Fill bytes", "nt.midl.fill_bytes", FT_UINT32, BASE_HEX,
NULL, 0, "Just some fill bytes", HFILL }},
{ &hf_nt_midl_version, {
"Version", "nt.midl.version", FT_UINT8, BASE_DEC,
NULL, 0, "Version of pickling", HFILL }},
{ &hf_nt_midl_hdr_len, {
"HDR Length", "nt.midl.hdr_len", FT_UINT16, BASE_DEC,
NULL, 0, "Length of header", HFILL }},
};
static gint *ett[] = {
&ett_nt_data_blob,
&ett_nt_counted_string,
&ett_nt_counted_byte_array,
&ett_nt_policy_hnd,
&ett_nt_sid_pointer,
&ett_nt_acct_ctrl,
&ett_nt_logon_hours,
&ett_nt_logon_hours_hours,
&ett_nt_sid_array,
&ett_nt_sid_and_attributes_array,
&ett_nt_sid_and_attributes,
&ett_nt_counted_ascii_string,
&ett_lsa_String,
&ett_nt_MIDL_BLOB,
};
static ei_register_info ei[] = {
{ &ei_dcerpc_nt_badsid, { "dcerpc.nt.badsid", PI_MALFORMED, PI_ERROR, "Association rejected", EXPFILL }},
};
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_dcerpc, hf, array_length(hf));
expert_dcerpc_nt = expert_register_protocol(proto_dcerpc);
expert_register_field_array(expert_dcerpc_nt, ei, array_length(ei));
pol_hash = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), pol_hash_fn, pol_hash_compare);
}
