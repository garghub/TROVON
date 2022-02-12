static dcerpc_info *
get_next_di(void)
{
static dcerpc_info di[20];
static int di_counter = 0;
di_counter++;
if (di_counter >= 20) {
di_counter = 0;
}
memset(&di[di_counter], 0, sizeof(dcerpc_info));
return &di[di_counter];
}
static guint
dcerpc_fragment_hash(gconstpointer k)
{
const dcerpc_fragment_key* key = (const dcerpc_fragment_key*) k;
guint hash_val;
hash_val = 0;
hash_val += key->id;
hash_val += key->act_id.Data1;
hash_val += key->act_id.Data2 << 16;
hash_val += key->act_id.Data3;
return hash_val;
}
static gint
dcerpc_fragment_equal(gconstpointer k1, gconstpointer k2)
{
const dcerpc_fragment_key* key1 = (const dcerpc_fragment_key*) k1;
const dcerpc_fragment_key* key2 = (const dcerpc_fragment_key*) k2;
return (((key1->id == key2->id)
&& (ADDRESSES_EQUAL(&key1->src, &key2->src))
&& (ADDRESSES_EQUAL(&key1->dst, &key2->dst))
&& (memcmp (&key1->act_id, &key2->act_id, sizeof (e_uuid_t)) == 0))
? TRUE : FALSE);
}
static void *
dcerpc_fragment_temporary_key(const packet_info *pinfo, const guint32 id,
const void *data)
{
dcerpc_fragment_key *key = g_slice_new(dcerpc_fragment_key);
e_dce_dg_common_hdr_t *hdr = (e_dce_dg_common_hdr_t *)data;
key->src = pinfo->src;
key->dst = pinfo->dst;
key->id = id;
key->act_id = hdr->act_id;
return key;
}
static void *
dcerpc_fragment_persistent_key(const packet_info *pinfo, const guint32 id,
const void *data)
{
dcerpc_fragment_key *key = g_slice_new(dcerpc_fragment_key);
e_dce_dg_common_hdr_t *hdr = (e_dce_dg_common_hdr_t *)data;
COPY_ADDRESS(&key->src, &pinfo->src);
COPY_ADDRESS(&key->dst, &pinfo->dst);
key->id = id;
key->act_id = hdr->act_id;
return key;
}
static void
dcerpc_fragment_free_temporary_key(gpointer ptr)
{
dcerpc_fragment_key *key = (dcerpc_fragment_key *)ptr;
if(key)
g_slice_free(dcerpc_fragment_key, key);
}
static void
dcerpc_fragment_free_persistent_key(gpointer ptr)
{
dcerpc_fragment_key *key = (dcerpc_fragment_key *)ptr;
if(key){
g_free((gpointer)key->src.data);
g_free((gpointer)key->dst.data);
g_slice_free(dcerpc_fragment_key, key);
}
}
static void
dcerpc_reassemble_init(void)
{
reassembly_table_init(&dcerpc_co_reassembly_table,
&addresses_reassembly_table_functions);
reassembly_table_init(&dcerpc_cl_reassembly_table,
&dcerpc_cl_reassembly_table_functions);
}
static dcerpc_auth_subdissector_fns *get_auth_subdissector_fns(
guint8 auth_level, guint8 auth_type)
{
gpointer data;
int i;
for (i = 0; (data = g_slist_nth_data(dcerpc_auth_subdissector_list, i)); i++) {
dcerpc_auth_subdissector *asd = (dcerpc_auth_subdissector *)data;
if ((asd->auth_level == auth_level) &&
(asd->auth_type == auth_type))
return &asd->auth_fns;
}
return NULL;
}
void register_dcerpc_auth_subdissector(guint8 auth_level, guint8 auth_type,
dcerpc_auth_subdissector_fns *fns)
{
dcerpc_auth_subdissector *d;
if (get_auth_subdissector_fns(auth_level, auth_type))
return;
d = (dcerpc_auth_subdissector *)g_malloc(sizeof(dcerpc_auth_subdissector));
d->auth_level = auth_level;
d->auth_type = auth_type;
memcpy(&d->auth_fns, fns, sizeof(dcerpc_auth_subdissector_fns));
dcerpc_auth_subdissector_list = g_slist_append(dcerpc_auth_subdissector_list, d);
}
static void dissect_auth_verf(tvbuff_t *auth_tvb, packet_info *pinfo,
proto_tree *tree,
dcerpc_auth_subdissector_fns *auth_fns,
e_dce_cn_common_hdr_t *hdr,
dcerpc_auth_info *auth_info)
{
dcerpc_dissect_fnct_t *volatile fn = NULL;
switch (hdr->ptype) {
case PDU_BIND:
case PDU_ALTER:
fn = auth_fns->bind_fn;
break;
case PDU_BIND_ACK:
case PDU_ALTER_ACK:
fn = auth_fns->bind_ack_fn;
break;
case PDU_AUTH3:
fn = auth_fns->auth3_fn;
break;
case PDU_REQ:
fn = auth_fns->req_verf_fn;
break;
case PDU_RESP:
fn = auth_fns->resp_verf_fn;
break;
default:
g_warning("attempt to dissect %s pdu authentication data",
val_to_str(hdr->ptype, pckt_vals, "Unknown (%u)"));
break;
}
if (fn)
fn(auth_tvb, 0, pinfo, tree, hdr->drep);
else {
tvb_ensure_bytes_exist(auth_tvb, 0, hdr->auth_len);
proto_tree_add_text(tree, auth_tvb, 0, hdr->auth_len,
"%s Verifier",
val_to_str(auth_info->auth_type,
authn_protocol_vals,
"Unknown (%u)"));
}
}
static tvbuff_t *decode_encrypted_data(tvbuff_t *data_tvb,
tvbuff_t *auth_tvb,
packet_info *pinfo,
dcerpc_auth_subdissector_fns *auth_fns,
gboolean is_request,
dcerpc_auth_info *auth_info)
{
dcerpc_decode_data_fnct_t *fn;
if (is_request)
fn = auth_fns->req_data_fn;
else
fn = auth_fns->resp_data_fn;
if (fn)
return fn(data_tvb, auth_tvb, 0, pinfo, auth_info);
return NULL;
}
static gint
dcerpc_uuid_equal(gconstpointer k1, gconstpointer k2)
{
const dcerpc_uuid_key *key1 = (const dcerpc_uuid_key *)k1;
const dcerpc_uuid_key *key2 = (const dcerpc_uuid_key *)k2;
return ((memcmp(&key1->uuid, &key2->uuid, sizeof (e_uuid_t)) == 0)
&& (key1->ver == key2->ver));
}
static guint
dcerpc_uuid_hash(gconstpointer k)
{
const dcerpc_uuid_key *key = (const dcerpc_uuid_key *)k;
return key->uuid.Data1;
}
void
dcerpc_init_uuid(int proto, int ett, e_uuid_t *uuid, guint16 ver,
dcerpc_sub_dissector *procs, int opnum_hf)
{
dcerpc_uuid_key *key = (dcerpc_uuid_key *)g_malloc(sizeof (*key));
dcerpc_uuid_value *value = (dcerpc_uuid_value *)g_malloc(sizeof (*value));
header_field_info *hf_info;
module_t *samr_module;
const char *filter_name = proto_get_protocol_filter_name(proto);
key->uuid = *uuid;
key->ver = ver;
value->proto = find_protocol_by_id(proto);
value->proto_id = proto;
value->ett = ett;
value->name = proto_get_protocol_short_name(value->proto);
value->procs = procs;
value->opnum_hf = opnum_hf;
g_hash_table_insert(dcerpc_uuids, key, value);
hf_info = proto_registrar_get_nth(opnum_hf);
hf_info->strings = value_string_from_subdissectors(procs);
guids_add_uuid(uuid, proto_get_protocol_short_name(value->proto));
if (strcmp(filter_name, "samr") == 0) {
samr_module = prefs_register_protocol(proto, NULL);
prefs_register_obsolete_preference(samr_module, "nt_password");
}
}
const char *
dcerpc_get_proto_name(e_uuid_t *uuid, guint16 ver)
{
dcerpc_uuid_key key;
dcerpc_uuid_value *sub_proto;
key.uuid = *uuid;
key.ver = ver;
if (!(sub_proto = (dcerpc_uuid_value *)g_hash_table_lookup(dcerpc_uuids, &key))) {
return NULL;
}
return sub_proto->name;
}
int
dcerpc_get_proto_hf_opnum(e_uuid_t *uuid, guint16 ver)
{
dcerpc_uuid_key key;
dcerpc_uuid_value *sub_proto;
key.uuid = *uuid;
key.ver = ver;
if (!(sub_proto = (dcerpc_uuid_value *)g_hash_table_lookup(dcerpc_uuids, &key))) {
return -1;
}
return sub_proto->opnum_hf;
}
value_string *value_string_from_subdissectors(dcerpc_sub_dissector *sd)
{
value_string *vs = NULL;
int i;
int num_sd = 0;
again:
for (i = 0; sd[i].name; i++) {
if (vs) {
vs[i].value = sd[i].num;
vs[i].strptr = sd[i].name;
} else
num_sd++;
}
if (!vs) {
vs = (value_string *)wmem_alloc(wmem_epan_scope(), (num_sd + 1) * sizeof(value_string));
goto again;
}
vs[num_sd].value = 0;
vs[num_sd].strptr = NULL;
return vs;
}
dcerpc_sub_dissector *
dcerpc_get_proto_sub_dissector(e_uuid_t *uuid, guint16 ver)
{
dcerpc_uuid_key key;
dcerpc_uuid_value *sub_proto;
key.uuid = *uuid;
key.ver = ver;
if (!(sub_proto = (dcerpc_uuid_value *)g_hash_table_lookup(dcerpc_uuids, &key))) {
return NULL;
}
return sub_proto->procs;
}
static gint
dcerpc_bind_equal(gconstpointer k1, gconstpointer k2)
{
const dcerpc_bind_key *key1 = (const dcerpc_bind_key *)k1;
const dcerpc_bind_key *key2 = (const dcerpc_bind_key *)k2;
return ((key1->conv == key2->conv)
&& (key1->ctx_id == key2->ctx_id)
&& (key1->smb_fid == key2->smb_fid));
}
static guint
dcerpc_bind_hash(gconstpointer k)
{
const dcerpc_bind_key *key = (const dcerpc_bind_key *)k;
guint hash;
hash = GPOINTER_TO_UINT(key->conv) + key->ctx_id + key->smb_fid;
return hash;
}
static gint
dcerpc_cn_call_equal(gconstpointer k1, gconstpointer k2)
{
const dcerpc_cn_call_key *key1 = (const dcerpc_cn_call_key *)k1;
const dcerpc_cn_call_key *key2 = (const dcerpc_cn_call_key *)k2;
return ((key1->conv == key2->conv)
&& (key1->call_id == key2->call_id)
&& (key1->smb_fid == key2->smb_fid));
}
static gint
dcerpc_dg_call_equal(gconstpointer k1, gconstpointer k2)
{
const dcerpc_dg_call_key *key1 = (const dcerpc_dg_call_key *)k1;
const dcerpc_dg_call_key *key2 = (const dcerpc_dg_call_key *)k2;
return ((key1->conv == key2->conv)
&& (key1->seqnum == key2->seqnum)
&& ((memcmp(&key1->act_id, &key2->act_id, sizeof (e_uuid_t)) == 0)));
}
static guint
dcerpc_cn_call_hash(gconstpointer k)
{
const dcerpc_cn_call_key *key = (const dcerpc_cn_call_key *)k;
return GPOINTER_TO_UINT(key->conv) + key->call_id + key->smb_fid;
}
static guint
dcerpc_dg_call_hash(gconstpointer k)
{
const dcerpc_dg_call_key *key = (const dcerpc_dg_call_key *)k;
return (GPOINTER_TO_UINT(key->conv) + key->seqnum + key->act_id.Data1
+ (key->act_id.Data2 << 16) + key->act_id.Data3
+ (key->act_id.Data4[0] << 24) + (key->act_id.Data4[1] << 16)
+ (key->act_id.Data4[2] << 8) + (key->act_id.Data4[3] << 0)
+ (key->act_id.Data4[4] << 24) + (key->act_id.Data4[5] << 16)
+ (key->act_id.Data4[6] << 8) + (key->act_id.Data4[7] << 0));
}
static gint
dcerpc_matched_equal(gconstpointer k1, gconstpointer k2)
{
const dcerpc_matched_key *key1 = (const dcerpc_matched_key *)k1;
const dcerpc_matched_key *key2 = (const dcerpc_matched_key *)k2;
return ((key1->frame == key2->frame)
&& (key1->call_id == key2->call_id));
}
static guint
dcerpc_matched_hash(gconstpointer k)
{
const dcerpc_matched_key *key = (const dcerpc_matched_key *)k;
return key->frame;
}
int
dissect_dcerpc_uint8(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, guint8 *drep,
int hfindex, guint8 *pdata)
{
guint8 data;
data = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_item(tree, hfindex, tvb, offset, 1, DREP_ENC_INTEGER(drep));
}
if (pdata)
*pdata = data;
return offset + 1;
}
int
dissect_dcerpc_uint16(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, guint8 *drep,
int hfindex, guint16 *pdata)
{
guint16 data;
data = ((drep[0] & DREP_LITTLE_ENDIAN)
? tvb_get_letohs(tvb, offset)
: tvb_get_ntohs(tvb, offset));
if (tree) {
proto_tree_add_item(tree, hfindex, tvb, offset, 2, DREP_ENC_INTEGER(drep));
}
if (pdata)
*pdata = data;
return offset + 2;
}
int
dissect_dcerpc_uint32(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, guint8 *drep,
int hfindex, guint32 *pdata)
{
guint32 data;
data = ((drep[0] & DREP_LITTLE_ENDIAN)
? tvb_get_letohl(tvb, offset)
: tvb_get_ntohl(tvb, offset));
if (tree) {
proto_tree_add_item(tree, hfindex, tvb, offset, 4, DREP_ENC_INTEGER(drep));
}
if (pdata)
*pdata = data;
return offset+4;
}
int
dissect_dcerpc_time_t(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, guint8 *drep,
int hfindex, guint32 *pdata)
{
guint32 data;
nstime_t tv;
data = ((drep[0] & DREP_LITTLE_ENDIAN)
? tvb_get_letohl(tvb, offset)
: tvb_get_ntohl(tvb, offset));
tv.secs = data;
tv.nsecs = 0;
if (tree) {
if (data == 0xffffffff) {
proto_tree_add_time_format_value(tree, hfindex, tvb, offset, 4, &tv, "No time specified");
} else {
proto_tree_add_time(tree, hfindex, tvb, offset, 4, &tv);
}
}
if (pdata)
*pdata = data;
return offset+4;
}
int
dissect_dcerpc_uint64(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, guint8 *drep,
int hfindex, guint64 *pdata)
{
guint64 data;
data = ((drep[0] & DREP_LITTLE_ENDIAN)
? tvb_get_letoh64(tvb, offset)
: tvb_get_ntoh64(tvb, offset));
if (tree) {
header_field_info *hfinfo;
hfinfo = proto_registrar_get_nth(hfindex);
switch (hfinfo->type) {
case FT_UINT64:
proto_tree_add_uint64(tree, hfindex, tvb, offset, 8, data);
break;
case FT_INT64:
proto_tree_add_int64(tree, hfindex, tvb, offset, 8, data);
break;
default:
DISSECTOR_ASSERT(data <= G_MAXUINT32);
proto_tree_add_uint(tree, hfindex, tvb, offset, 8, (guint32)data);
}
}
if (pdata)
*pdata = data;
return offset+8;
}
int
dissect_dcerpc_float(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, guint8 *drep,
int hfindex, gfloat *pdata)
{
gfloat data;
switch (drep[1]) {
case(DCE_RPC_DREP_FP_IEEE):
data = ((drep[0] & DREP_LITTLE_ENDIAN)
? tvb_get_letohieee_float(tvb, offset)
: tvb_get_ntohieee_float(tvb, offset));
if (tree) {
proto_tree_add_float(tree, hfindex, tvb, offset, 4, data);
}
break;
case(DCE_RPC_DREP_FP_VAX):
case(DCE_RPC_DREP_FP_CRAY):
case(DCE_RPC_DREP_FP_IBM):
default:
data = -G_MAXFLOAT;
if (tree) {
proto_tree_add_debug_text(tree, "DCE RPC: dissection of non IEEE floating formats currently not implemented (drep=%u)!", drep[1]);
}
}
if (pdata)
*pdata = data;
return offset + 4;
}
int
dissect_dcerpc_double(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, guint8 *drep,
int hfindex, gdouble *pdata)
{
gdouble data;
switch (drep[1]) {
case(DCE_RPC_DREP_FP_IEEE):
data = ((drep[0] & DREP_LITTLE_ENDIAN)
? tvb_get_letohieee_double(tvb, offset)
: tvb_get_ntohieee_double(tvb, offset));
if (tree) {
proto_tree_add_double(tree, hfindex, tvb, offset, 8, data);
}
break;
case(DCE_RPC_DREP_FP_VAX):
case(DCE_RPC_DREP_FP_CRAY):
case(DCE_RPC_DREP_FP_IBM):
default:
data = -G_MAXDOUBLE;
if (tree) {
proto_tree_add_debug_text(tree, "DCE RPC: dissection of non IEEE double formats currently not implemented (drep=%u)!", drep[1]);
}
}
if (pdata)
*pdata = data;
return offset + 8;
}
int
dissect_dcerpc_uuid_t(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, guint8 *drep,
int hfindex, e_uuid_t *pdata)
{
e_uuid_t uuid;
if (drep[0] & DREP_LITTLE_ENDIAN) {
tvb_get_letohguid(tvb, offset, (e_guid_t *) &uuid);
} else {
tvb_get_ntohguid(tvb, offset, (e_guid_t *) &uuid);
}
if (tree) {
proto_tree_add_guid(tree, hfindex, tvb, offset, 16, (e_guid_t *) &uuid);
}
if (pdata) {
*pdata = uuid;
}
return offset + 16;
}
guint16
dcerpc_tvb_get_ntohs(tvbuff_t *tvb, gint offset, guint8 *drep)
{
if (drep[0] & DREP_LITTLE_ENDIAN) {
return tvb_get_letohs(tvb, offset);
} else {
return tvb_get_ntohs(tvb, offset);
}
}
guint32
dcerpc_tvb_get_ntohl(tvbuff_t *tvb, gint offset, guint8 *drep)
{
if (drep[0] & DREP_LITTLE_ENDIAN) {
return tvb_get_letohl(tvb, offset);
} else {
return tvb_get_ntohl(tvb, offset);
}
}
void
dcerpc_tvb_get_uuid(tvbuff_t *tvb, gint offset, guint8 *drep, e_uuid_t *uuid)
{
if (drep[0] & DREP_LITTLE_ENDIAN) {
tvb_get_letohguid(tvb, offset, (e_guid_t *) uuid);
} else {
tvb_get_ntohguid(tvb, offset, (e_guid_t *) uuid);
}
}
int
dissect_ndr_ucarray(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep,
dcerpc_dissect_fnct_t *fnct)
{
guint32 i;
dcerpc_info *di;
int old_offset;
int conformance_size = 4;
di = (dcerpc_info *)pinfo->private_data;
if (di->call_data->flags & DCERPC_IS_NDR64) {
conformance_size = 8;
}
if (di->conformant_run) {
guint64 val;
old_offset = offset;
di->conformant_run = 0;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, drep,
hf_dcerpc_array_max_count, &val);
di->array_max_count = (gint32)val;
di->array_max_count_offset = offset-conformance_size;
di->conformant_run = 1;
di->conformant_eaten = offset-old_offset;
} else {
proto_tree_add_uint(tree, hf_dcerpc_array_max_count, tvb, di->array_max_count_offset, conformance_size, di->array_max_count);
for(i=0; i<di->array_max_count; i++) {
offset = (*fnct)(tvb, offset, pinfo, tree, drep);
}
}
return offset;
}
int
dissect_ndr_ucvarray(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep,
dcerpc_dissect_fnct_t *fnct)
{
guint32 i;
dcerpc_info *di;
int old_offset;
int conformance_size = 4;
di = (dcerpc_info *)pinfo->private_data;
if (di->call_data->flags & DCERPC_IS_NDR64) {
conformance_size = 8;
}
if (di->conformant_run) {
guint64 val;
old_offset = offset;
di->conformant_run = 0;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, drep,
hf_dcerpc_array_max_count, &val);
DISSECTOR_ASSERT(val <= G_MAXUINT32);
di->array_max_count = (guint32)val;
di->array_max_count_offset = offset-conformance_size;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, drep,
hf_dcerpc_array_offset, &val);
DISSECTOR_ASSERT(val <= G_MAXUINT32);
di->array_offset = (guint32)val;
di->array_offset_offset = offset-conformance_size;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, drep,
hf_dcerpc_array_actual_count, &val);
DISSECTOR_ASSERT(val <= G_MAXUINT32);
di->array_actual_count = (guint32)val;
di->array_actual_count_offset = offset-conformance_size;
di->conformant_run = 1;
di->conformant_eaten = offset-old_offset;
} else {
proto_tree_add_uint(tree, hf_dcerpc_array_max_count, tvb, di->array_max_count_offset, conformance_size, di->array_max_count);
proto_tree_add_uint(tree, hf_dcerpc_array_offset, tvb, di->array_offset_offset, conformance_size, di->array_offset);
proto_tree_add_uint(tree, hf_dcerpc_array_actual_count, tvb, di->array_actual_count_offset, conformance_size, di->array_actual_count);
for(i=0 ;i<di->array_actual_count; i++) {
old_offset = offset;
offset = (*fnct)(tvb, offset, pinfo, tree, drep);
if (offset <= old_offset)
THROW(ReportedBoundsError);
}
}
return offset;
}
int
dissect_ndr_uvarray(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep,
dcerpc_dissect_fnct_t *fnct)
{
guint32 i;
dcerpc_info *di;
int old_offset;
int conformance_size = 4;
di = (dcerpc_info *)pinfo->private_data;
if (di->call_data->flags & DCERPC_IS_NDR64) {
conformance_size = 8;
}
if (di->conformant_run) {
guint64 val;
old_offset = offset;
di->conformant_run = 0;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, drep,
hf_dcerpc_array_offset, &val);
DISSECTOR_ASSERT(val <= G_MAXUINT32);
di->array_offset = (guint32)val;
di->array_offset_offset = offset-conformance_size;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, drep,
hf_dcerpc_array_actual_count, &val);
DISSECTOR_ASSERT(val <= G_MAXUINT32);
di->array_actual_count = (guint32)val;
di->array_actual_count_offset = offset-conformance_size;
di->conformant_run = 1;
di->conformant_eaten = offset-old_offset;
} else {
proto_tree_add_uint(tree, hf_dcerpc_array_offset, tvb, di->array_offset_offset, conformance_size, di->array_offset);
proto_tree_add_uint(tree, hf_dcerpc_array_actual_count, tvb, di->array_actual_count_offset, conformance_size, di->array_actual_count);
for(i=0; i<di->array_actual_count; i++) {
offset = (*fnct)(tvb, offset, pinfo, tree, drep);
}
}
return offset;
}
int
dissect_ndr_byte_array(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep)
{
dcerpc_info *di;
guint64 len;
di = (dcerpc_info *)pinfo->private_data;
if (di->conformant_run) {
return offset;
}
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, drep,
hf_dcerpc_array_max_count, NULL);
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, drep,
hf_dcerpc_array_offset, NULL);
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, drep,
hf_dcerpc_array_actual_count, &len);
DISSECTOR_ASSERT(len <= G_MAXUINT32);
if (tree && len) {
tvb_ensure_bytes_exist(tvb, offset, (guint32)len);
proto_tree_add_item(tree, hf_dcerpc_array_buffer,
tvb, offset, (guint32)len, ENC_NA);
}
offset += (guint32)len;
return offset;
}
int
dissect_ndr_cvstring(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep, int size_is,
int hfindex, gboolean add_subtree, char **data)
{
dcerpc_info *di;
proto_item *string_item;
proto_tree *string_tree;
guint64 len;
guint32 buffer_len;
char *s;
header_field_info *hfinfo;
di = (dcerpc_info *)pinfo->private_data;
if (di->conformant_run) {
return offset;
}
if (add_subtree) {
string_item = proto_tree_add_text(tree, tvb, offset, -1, "%s",
proto_registrar_get_name(hfindex));
string_tree = proto_item_add_subtree(string_item, ett_dcerpc_string);
} else {
string_item = NULL;
string_tree = tree;
}
offset = dissect_ndr_uint3264(tvb, offset, pinfo, string_tree, drep,
hf_dcerpc_array_max_count, NULL);
offset = dissect_ndr_uint3264(tvb, offset, pinfo, string_tree, drep,
hf_dcerpc_array_offset, NULL);
offset = dissect_ndr_uint3264(tvb, offset, pinfo, string_tree, drep,
hf_dcerpc_array_actual_count, &len);
DISSECTOR_ASSERT(len <= G_MAXUINT32);
buffer_len = size_is * (guint32)len;
if (!di->no_align && (offset % size_is))
offset += size_is - (offset % size_is);
if (size_is == sizeof(guint16)) {
s = tvb_get_ephemeral_unicode_string(tvb, offset, buffer_len, ENC_LITTLE_ENDIAN);
if (tree && buffer_len) {
hfinfo = proto_registrar_get_nth(hfindex);
tvb_ensure_bytes_exist(tvb, offset, buffer_len);
if (hfinfo->type == FT_STRING) {
proto_tree_add_string(string_tree, hfindex, tvb, offset,
buffer_len, s);
} else {
proto_tree_add_item(string_tree, hfindex, tvb, offset,
buffer_len, DREP_ENC_INTEGER(drep));
}
}
} else {
tvb_ensure_bytes_exist(tvb, offset, buffer_len);
s = tvb_get_ephemeral_string(tvb, offset, buffer_len);
if (tree && buffer_len)
proto_tree_add_item(string_tree, hfindex, tvb, offset,
buffer_len, DREP_ENC_INTEGER(drep));
}
if (string_item != NULL)
proto_item_append_text(string_item, ": %s", s);
if (data)
*data = s;
offset += buffer_len;
proto_item_set_end(string_item, tvb, offset);
return offset;
}
int
dissect_ndr_char_cvstring(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep)
{
dcerpc_info *di;
di = (dcerpc_info *)pinfo->private_data;
return dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep,
sizeof(guint8), di->hf_index,
FALSE, NULL);
}
int
dissect_ndr_wchar_cvstring(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep)
{
dcerpc_info *di;
di = (dcerpc_info *)pinfo->private_data;
return dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep,
sizeof(guint16), di->hf_index,
FALSE, NULL);
}
int
PIDL_dissect_cvstring(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, int chsize, int hfindex, guint32 param)
{
dcerpc_info *di;
char *s = NULL;
gint levels = CB_STR_ITEM_LEVELS(param);
di = (dcerpc_info *)pinfo->private_data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep,
chsize, hfindex,
FALSE, &s);
if (!di->conformant_run) {
if (param & PIDL_SET_COL_INFO) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", s);
}
if ((param & PIDL_STR_SAVE)
&& (!pinfo->fd->flags.visited)) {
dcerpc_call_value *dcv = (dcerpc_call_value *)di->call_data;
dcv->private_data = se_strdup(s);
}
if ((levels > 0) && tree && s && s[0]) {
proto_item_append_text(tree, ": %s", s);
tree = tree->parent;
levels--;
if (levels > 0) {
proto_item_append_text(tree, ": %s", s);
tree = tree->parent;
levels--;
while (levels > 0) {
proto_item_append_text(tree, " %s", s);
tree = tree->parent;
levels--;
}
}
}
}
return offset;
}
int
dissect_ndr_vstring(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep, int size_is,
int hfindex, gboolean add_subtree, char **data)
{
dcerpc_info *di;
proto_item *string_item;
proto_tree *string_tree;
guint64 len;
guint32 buffer_len;
char *s;
header_field_info *hfinfo;
di = (dcerpc_info *)pinfo->private_data;
if (di->conformant_run) {
return offset;
}
if (add_subtree) {
string_item = proto_tree_add_text(tree, tvb, offset, -1, "%s",
proto_registrar_get_name(hfindex));
string_tree = proto_item_add_subtree(string_item, ett_dcerpc_string);
} else {
string_item = NULL;
string_tree = tree;
}
offset = dissect_ndr_uint3264(tvb, offset, pinfo, string_tree, drep,
hf_dcerpc_array_offset, NULL);
offset = dissect_ndr_uint3264(tvb, offset, pinfo, string_tree, drep,
hf_dcerpc_array_actual_count, &len);
DISSECTOR_ASSERT(len <= G_MAXUINT32);
buffer_len = size_is * (guint32)len;
if (!di->no_align && (offset % size_is))
offset += size_is - (offset % size_is);
if (size_is == sizeof(guint16)) {
s = tvb_get_ephemeral_unicode_string(tvb, offset, buffer_len, ENC_LITTLE_ENDIAN);
if (tree && buffer_len) {
hfinfo = proto_registrar_get_nth(hfindex);
tvb_ensure_bytes_exist(tvb, offset, buffer_len);
if (hfinfo->type == FT_STRING) {
proto_tree_add_string(string_tree, hfindex, tvb, offset,
buffer_len, s);
} else {
proto_tree_add_item(string_tree, hfindex, tvb, offset,
buffer_len, DREP_ENC_INTEGER(drep));
}
}
} else {
tvb_ensure_bytes_exist(tvb, offset, buffer_len);
s = tvb_get_ephemeral_string(tvb, offset, buffer_len);
if (tree && buffer_len)
proto_tree_add_item(string_tree, hfindex, tvb, offset,
buffer_len, DREP_ENC_INTEGER(drep));
}
if (string_item != NULL)
proto_item_append_text(string_item, ": %s", s);
if (data)
*data = s;
offset += buffer_len;
proto_item_set_end(string_item, tvb, offset);
return offset;
}
int
dissect_ndr_char_vstring(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep)
{
dcerpc_info *di;
di = (dcerpc_info *)pinfo->private_data;
return dissect_ndr_vstring(tvb, offset, pinfo, tree, drep,
sizeof(guint8), di->hf_index,
FALSE, NULL);
}
int
dissect_ndr_wchar_vstring(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep)
{
dcerpc_info *di;
di = (dcerpc_info *)pinfo->private_data;
return dissect_ndr_vstring(tvb, offset, pinfo, tree, drep,
sizeof(guint16), di->hf_index,
FALSE, NULL);
}
void
init_ndr_pointer_list(packet_info *pinfo)
{
dcerpc_info *di;
di = (dcerpc_info *)pinfo->private_data;
di->conformant_run = 0;
while (ndr_pointer_list) {
ndr_pointer_data_t *npd = (ndr_pointer_data_t *)g_slist_nth_data(ndr_pointer_list, 0);
ndr_pointer_list = g_slist_remove(ndr_pointer_list, npd);
g_free(npd);
}
ndr_pointer_list = NULL;
ndr_pointer_list_pos = 0;
pointers_are_top_level = TRUE;
}
int
dissect_deferred_pointers(packet_info *pinfo, tvbuff_t *tvb, int offset, guint8 *drep)
{
int found_new_pointer;
dcerpc_info *di;
int old_offset;
int next_pointer;
next_pointer = 0;
di = (dcerpc_info *)pinfo->private_data;
do{
int i, len;
found_new_pointer = 0;
len = g_slist_length(ndr_pointer_list);
for(i=next_pointer; i<len; i++) {
ndr_pointer_data_t *tnpd = (ndr_pointer_data_t *)g_slist_nth_data(ndr_pointer_list, i);
if (tnpd->fnct) {
dcerpc_dissect_fnct_t *fnct;
next_pointer = i+1;
found_new_pointer = 1;
fnct = tnpd->fnct;
tnpd->fnct = NULL;
ndr_pointer_list_pos = i+1;
di->hf_index = tnpd->hf_index;
di->conformant_run = 1;
di->conformant_eaten = 0;
old_offset = offset;
offset = (*(fnct))(tvb, offset, pinfo, NULL, drep);
DISSECTOR_ASSERT((offset-old_offset) == di->conformant_eaten);
di->conformant_run = 0;
old_offset = offset;
offset = (*(fnct))(tvb, offset, pinfo, tnpd->tree, drep);
if (tnpd->callback)
tnpd->callback(pinfo, tnpd->tree, tnpd->item, tvb, old_offset, offset, tnpd->callback_args);
proto_item_set_len(tnpd->item, offset - old_offset);
break;
}
}
} while (found_new_pointer);
return offset;
}
static void
add_pointer_to_list(packet_info *pinfo, proto_tree *tree, proto_item *item,
dcerpc_dissect_fnct_t *fnct, guint32 id, int hf_index,
dcerpc_callback_fnct_t *callback, void *callback_args)
{
ndr_pointer_data_t *npd;
if (id != 0xffffffff) {
dcerpc_info *di;
dcerpc_call_value *value;
di = (dcerpc_info *)pinfo->private_data;
value = di->call_data;
if (di->ptype == PDU_REQ) {
if (!(pinfo->fd->flags.visited)) {
if (id > value->max_ptr) {
value->max_ptr = id;
}
}
} else {
if (value->req_frame == 0) {
}
if (id <= value->max_ptr) {
return;
}
}
}
npd = (ndr_pointer_data_t *)g_malloc(sizeof(ndr_pointer_data_t));
npd->id = id;
npd->tree = tree;
npd->item = item;
npd->fnct = fnct;
npd->hf_index = hf_index;
npd->callback = callback;
npd->callback_args = callback_args;
ndr_pointer_list = g_slist_insert(ndr_pointer_list, npd,
ndr_pointer_list_pos);
ndr_pointer_list_pos++;
}
static int
find_pointer_index(guint32 id)
{
ndr_pointer_data_t *npd;
int i,len;
len = g_slist_length(ndr_pointer_list);
for(i=0; i<len; i++) {
npd = (ndr_pointer_data_t *)g_slist_nth_data(ndr_pointer_list, i);
if (npd) {
if (npd->id == id) {
return i;
}
}
}
return -1;
}
int
dissect_ndr_pointer_cb(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep, dcerpc_dissect_fnct_t *fnct,
int type, const char *text, int hf_index,
dcerpc_callback_fnct_t *callback, void *callback_args)
{
dcerpc_info *di;
proto_tree *tr = NULL;
gint start_offset = offset;
int pointer_size = 4;
di = (dcerpc_info *)pinfo->private_data;
if (di->conformant_run) {
return offset;
}
if (di->call_data->flags & DCERPC_IS_NDR64) {
pointer_size = 8;
}
if ( pointers_are_top_level
&& (type == NDR_POINTER_REF) ) {
proto_item *item;
item = proto_tree_add_text(tree, tvb, offset, 0,
"%s", text);
tr = proto_item_add_subtree(item,ett_dcerpc_pointer_data);
add_pointer_to_list(pinfo, tr, item, fnct, 0xffffffff,
hf_index, callback, callback_args);
goto after_ref_id;
}
if ( pointers_are_top_level
&& (type == NDR_POINTER_PTR) ) {
int idx;
guint64 id;
proto_item *item;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, NULL, drep, -1, &id);
tvb_ensure_bytes_exist(tvb, offset-pointer_size, pointer_size);
if (id == 0) {
proto_tree_add_text(tree, tvb, offset-pointer_size,
pointer_size,
"(NULL pointer) %s",text);
goto after_ref_id;
}
DISSECTOR_ASSERT(id <= G_MAXUINT32);
idx = find_pointer_index((guint32)id);
if (idx >= 0) {
proto_tree_add_text(tree, tvb, offset-pointer_size,
pointer_size,
"(duplicate PTR) %s",text);
goto after_ref_id;
}
item = proto_tree_add_text(tree, tvb, offset-pointer_size,
pointer_size,
"%s", text);
tr = proto_item_add_subtree(item,ett_dcerpc_pointer_data);
proto_tree_add_uint(tr, hf_dcerpc_referent_id, tvb,
offset-pointer_size, pointer_size, (guint32)id);
add_pointer_to_list(pinfo, tr, item, fnct, (guint32)id, hf_index,
callback, callback_args);
goto after_ref_id;
}
if ( pointers_are_top_level
&& (type == NDR_POINTER_UNIQUE) ) {
guint64 id;
proto_item *item;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, NULL, drep, -1, &id);
tvb_ensure_bytes_exist(tvb, offset-pointer_size, pointer_size);
if (id == 0) {
proto_tree_add_text(tree, tvb, offset-pointer_size,
pointer_size,
"(NULL pointer) %s",text);
goto after_ref_id;
}
DISSECTOR_ASSERT(id <= G_MAXUINT32);
item = proto_tree_add_text(tree, tvb, offset-pointer_size,
pointer_size,
"%s", text);
tr = proto_item_add_subtree(item,ett_dcerpc_pointer_data);
proto_tree_add_uint(tr, hf_dcerpc_referent_id, tvb,
offset-pointer_size, pointer_size, (guint32)id);
add_pointer_to_list(pinfo, tr, item, fnct, 0xffffffff,
hf_index, callback, callback_args);
goto after_ref_id;
}
if ( (!pointers_are_top_level)
&& (type == NDR_POINTER_REF) ) {
guint64 id;
proto_item *item;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, NULL, drep, -1, &id);
tvb_ensure_bytes_exist(tvb, offset-pointer_size, pointer_size);
item = proto_tree_add_text(tree, tvb, offset-pointer_size,
pointer_size,
"%s",text);
tr = proto_item_add_subtree(item,ett_dcerpc_pointer_data);
DISSECTOR_ASSERT(id <= G_MAXUINT32);
proto_tree_add_uint(tr, hf_dcerpc_referent_id, tvb,
offset-pointer_size, pointer_size, (guint32)id);
add_pointer_to_list(pinfo, tr, item, fnct, 0xffffffff,
hf_index, callback, callback_args);
goto after_ref_id;
}
if ( (!pointers_are_top_level)
&& (type == NDR_POINTER_UNIQUE) ) {
guint64 id;
proto_item *item;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, NULL, drep, -1, &id);
tvb_ensure_bytes_exist(tvb, offset-pointer_size, pointer_size);
if (id == 0) {
proto_tree_add_text(tree, tvb, offset-pointer_size,
pointer_size,
"(NULL pointer) %s", text);
goto after_ref_id;
}
item = proto_tree_add_text(tree, tvb, offset-pointer_size,
pointer_size,
"%s",text);
tr = proto_item_add_subtree(item,ett_dcerpc_pointer_data);
DISSECTOR_ASSERT(id <= G_MAXUINT32);
proto_tree_add_uint(tr, hf_dcerpc_referent_id, tvb,
offset-pointer_size, pointer_size, (guint32)id);
add_pointer_to_list(pinfo, tr, item, fnct, 0xffffffff,
hf_index, callback, callback_args);
goto after_ref_id;
}
if ( (!pointers_are_top_level)
&& (type == NDR_POINTER_PTR) ) {
int idx;
guint64 id;
proto_item *item;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, NULL, drep, -1, &id);
tvb_ensure_bytes_exist(tvb, offset-pointer_size, pointer_size);
if (id == 0) {
proto_tree_add_text(tree, tvb, offset-pointer_size,
pointer_size,
"(NULL pointer) %s",text);
goto after_ref_id;
}
DISSECTOR_ASSERT(id <= G_MAXUINT32);
idx = find_pointer_index((guint32)id);
if (idx >= 0) {
proto_tree_add_text(tree, tvb, offset-pointer_size,
pointer_size,
"(duplicate PTR) %s",text);
goto after_ref_id;
}
item = proto_tree_add_text(tree, tvb, offset-pointer_size,
pointer_size,
"%s", text);
tr = proto_item_add_subtree(item,ett_dcerpc_pointer_data);
proto_tree_add_uint(tr, hf_dcerpc_referent_id, tvb,
offset-pointer_size, pointer_size, (guint32)id);
add_pointer_to_list(pinfo, tr, item, fnct, (guint32)id, hf_index,
callback, callback_args);
goto after_ref_id;
}
after_ref_id:
if (pointers_are_top_level == TRUE) {
pointers_are_top_level = FALSE;
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
pointers_are_top_level = TRUE;
}
if (tr) {
proto_item_set_len(tr, offset-start_offset);
}
return offset;
}
int
dissect_ndr_pointer(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep, dcerpc_dissect_fnct_t *fnct,
int type, const char *text, int hf_index)
{
return dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, drep, fnct, type, text, hf_index,
NULL, NULL);
}
int
dissect_ndr_toplevel_pointer(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep, dcerpc_dissect_fnct_t *fnct,
int type, const char *text, int hf_index)
{
int ret;
pointers_are_top_level = TRUE;
ret = dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, drep, fnct, type, text, hf_index,
NULL, NULL);
return ret;
}
int
dissect_ndr_embedded_pointer(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep, dcerpc_dissect_fnct_t *fnct,
int type, const char *text, int hf_index)
{
int ret;
pointers_are_top_level = FALSE;
ret = dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, drep, fnct, type, text, hf_index,
NULL, NULL);
return ret;
}
static void
show_stub_data(tvbuff_t *tvb, gint offset, proto_tree *dcerpc_tree,
dcerpc_auth_info *auth_info, gboolean is_encrypted)
{
int length, plain_length, auth_pad_len;
guint auth_pad_offset;
if (tvb_length_remaining(tvb, offset) > 0) {
auth_pad_len = auth_info?auth_info->auth_pad_len:0;
length = tvb_reported_length_remaining(tvb, offset);
plain_length = length - auth_pad_len;
if (plain_length < 1) {
plain_length = length;
auth_pad_len = 0;
}
auth_pad_offset = offset + plain_length;
if ((auth_info != NULL) &&
(auth_info->auth_level == DCE_C_AUTHN_LEVEL_PKT_PRIVACY)) {
if (is_encrypted) {
tvb_ensure_bytes_exist(tvb, offset, length);
proto_tree_add_text(dcerpc_tree, tvb, offset, length,
"Encrypted stub data (%d byte%s)",
length, plurality(length, "", "s"));
auth_pad_len = 0;
} else {
tvb_ensure_bytes_exist(tvb, offset, plain_length);
proto_tree_add_text(dcerpc_tree, tvb, offset, plain_length,
"Decrypted stub data (%d byte%s)",
plain_length, plurality(plain_length, "", "s"));
}
} else {
tvb_ensure_bytes_exist(tvb, offset, plain_length);
proto_tree_add_text(dcerpc_tree, tvb, offset, plain_length,
"Stub data (%d byte%s)", plain_length,
plurality(plain_length, "", "s"));
}
if (auth_pad_len != 0) {
tvb_ensure_bytes_exist(tvb, auth_pad_offset, auth_pad_len);
proto_tree_add_text(dcerpc_tree, tvb, auth_pad_offset,
auth_pad_len,
"Auth Padding (%u byte%s)",
auth_pad_len,
plurality(auth_pad_len, "", "s"));
}
}
}
static int
dcerpc_try_handoff(packet_info *pinfo, proto_tree *tree,
proto_tree *dcerpc_tree,
tvbuff_t *volatile tvb, tvbuff_t *decrypted_tvb,
guint8 *drep, dcerpc_info *info,
dcerpc_auth_info *auth_info)
{
volatile gint offset = 0;
dcerpc_uuid_key key;
dcerpc_uuid_value *sub_proto;
proto_tree *volatile sub_tree = NULL;
dcerpc_sub_dissector *proc;
const gchar *name = NULL;
const char *volatile saved_proto;
void *volatile saved_private_data;
guint length = 0, reported_length = 0;
tvbuff_t *volatile stub_tvb;
volatile guint auth_pad_len;
volatile int auth_pad_offset;
proto_item *sub_item = NULL;
proto_item *pi, *hidden_item;
dcerpc_dissect_fnct_t *volatile sub_dissect;
key.uuid = info->call_data->uuid;
key.ver = info->call_data->ver;
if ((sub_proto = (dcerpc_uuid_value *)g_hash_table_lookup(dcerpc_uuids, &key)) == NULL
|| !proto_is_protocol_enabled(sub_proto->proto)) {
hidden_item = proto_tree_add_boolean(dcerpc_tree, hf_dcerpc_unknown_if_id,
tvb, offset, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s V%u",
guids_resolve_uuid_to_str(&info->call_data->uuid), info->call_data->ver);
if (decrypted_tvb != NULL) {
show_stub_data(decrypted_tvb, 0, dcerpc_tree, auth_info,
FALSE);
} else
show_stub_data(tvb, 0, dcerpc_tree, auth_info, TRUE);
return -1;
}
for (proc = sub_proto->procs; proc->name; proc++) {
if (proc->num == info->call_data->opnum) {
name = proc->name;
break;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, sub_proto->name);
if (!name)
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown operation %u %s",
info->call_data->opnum,
(info->ptype == PDU_REQ) ? "request" : "response");
else
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s",
name, (info->ptype == PDU_REQ) ? "request" : "response");
sub_dissect = (info->ptype == PDU_REQ) ?
proc->dissect_rqst : proc->dissect_resp;
if (tree) {
sub_item = proto_tree_add_item(tree, sub_proto->proto_id,
(decrypted_tvb != NULL)?decrypted_tvb:tvb,
0, -1, ENC_NA);
if (sub_item) {
sub_tree = proto_item_add_subtree(sub_item, sub_proto->ett);
if (!name)
proto_item_append_text(sub_item, ", unknown operation %u",
info->call_data->opnum);
else
proto_item_append_text(sub_item, ", %s", name);
}
if (sub_proto->opnum_hf != -1)
proto_tree_add_uint_format(sub_tree, sub_proto->opnum_hf,
tvb, 0, 0, info->call_data->opnum,
"Operation: %s (%u)",
name ? name : "Unknown operation",
info->call_data->opnum);
else
proto_tree_add_uint_format(sub_tree, hf_dcerpc_op, tvb,
0, 0, info->call_data->opnum,
"Operation: %s (%u)",
name ? name : "Unknown operation",
info->call_data->opnum);
if ((info->ptype == PDU_REQ) && (info->call_data->rep_frame != 0)) {
pi = proto_tree_add_uint(sub_tree, hf_dcerpc_response_in,
tvb, 0, 0, info->call_data->rep_frame);
PROTO_ITEM_SET_GENERATED(pi);
}
if ((info->ptype == PDU_RESP) && (info->call_data->req_frame != 0)) {
pi = proto_tree_add_uint(sub_tree, hf_dcerpc_request_in,
tvb, 0, 0, info->call_data->req_frame);
PROTO_ITEM_SET_GENERATED(pi);
}
}
if (decrypted_tvb != NULL) {
if (sub_dissect) {
saved_proto = pinfo->current_proto;
saved_private_data = pinfo->private_data;
pinfo->current_proto = sub_proto->name;
pinfo->private_data = (void *)info;
init_ndr_pointer_list(pinfo);
length = tvb_length(decrypted_tvb);
reported_length = tvb_reported_length(decrypted_tvb);
if ((auth_info != NULL) && (auth_info->auth_pad_len != 0)) {
if (reported_length >= auth_info->auth_pad_len) {
reported_length -= auth_info->auth_pad_len;
if (length > reported_length)
length = reported_length;
stub_tvb = tvb_new_subset(decrypted_tvb, 0, length, reported_length);
auth_pad_len = auth_info->auth_pad_len;
auth_pad_offset = reported_length;
} else {
stub_tvb = NULL;
auth_pad_len = reported_length;
auth_pad_offset = 0;
length = 0;
}
} else {
stub_tvb = decrypted_tvb;
auth_pad_len = 0;
auth_pad_offset = 0;
}
if (sub_item) {
proto_item_set_len(sub_item, length);
}
if (stub_tvb != NULL) {
TRY {
int remaining;
offset = sub_dissect(stub_tvb, 0, pinfo, sub_tree,
drep);
remaining = tvb_reported_length_remaining(stub_tvb, offset);
if (remaining > 0) {
proto_tree_add_text(sub_tree, stub_tvb, offset,
remaining,
"[Long frame (%d byte%s)]",
remaining,
plurality(remaining, "", "s"));
col_append_fstr(pinfo->cinfo, COL_INFO,
"[Long frame (%d byte%s)]",
remaining,
plurality(remaining, "", "s"));
}
} CATCH_NONFATAL_ERRORS {
show_exception(stub_tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
} ENDTRY;
}
if (auth_pad_len != 0) {
tvb_ensure_bytes_exist(tvb, auth_pad_offset, auth_pad_len);
proto_tree_add_text(sub_tree, decrypted_tvb, auth_pad_offset,
auth_pad_len,
"Auth Padding (%u byte%s)",
auth_pad_len,
plurality(auth_pad_len, "", "s"));
}
pinfo->current_proto = saved_proto;
pinfo->private_data = saved_private_data;
} else {
if (decrypted_tvb) {
show_stub_data(decrypted_tvb, 0, sub_tree, auth_info, FALSE);
} else {
show_stub_data(tvb, 0, sub_tree, auth_info, TRUE);
}
}
} else
show_stub_data(tvb, 0, sub_tree, auth_info, TRUE);
tap_queue_packet(dcerpc_tap, pinfo, info);
return 0;
}
static int
dissect_dcerpc_verifier(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *dcerpc_tree, e_dce_cn_common_hdr_t *hdr,
dcerpc_auth_info *auth_info)
{
int auth_offset;
auth_info->auth_data = NULL;
if (auth_info->auth_size != 0) {
dcerpc_auth_subdissector_fns *auth_fns;
tvbuff_t *auth_tvb;
auth_offset = hdr->frag_len - hdr->auth_len;
auth_tvb = tvb_new_subset(tvb, auth_offset, hdr->auth_len,
hdr->auth_len);
auth_info->auth_data = auth_tvb;
if ((auth_fns = get_auth_subdissector_fns(auth_info->auth_level,
auth_info->auth_type))) {
TRY {
dissect_auth_verf(auth_tvb, pinfo, dcerpc_tree, auth_fns,
hdr, auth_info);
} CATCH_BOUNDS_ERRORS {
show_exception(auth_tvb, pinfo, dcerpc_tree, EXCEPT_CODE, GET_MESSAGE);
} ENDTRY;
} else {
tvb_ensure_bytes_exist(tvb, 0, hdr->auth_len);
proto_tree_add_text(dcerpc_tree, auth_tvb, 0, hdr->auth_len,
"Auth Verifier");
}
}
return hdr->auth_len;
}
static void
dissect_dcerpc_cn_auth(tvbuff_t *tvb, int stub_offset, packet_info *pinfo,
proto_tree *dcerpc_tree, e_dce_cn_common_hdr_t *hdr,
gboolean are_credentials, dcerpc_auth_info *auth_info)
{
volatile int offset;
auth_info->auth_level = 0;
auth_info->auth_type = 0;
auth_info->auth_size = 0;
auth_info->auth_pad_len = 0;
if (hdr->auth_len
&& ((hdr->auth_len + 8) <= (hdr->frag_len - stub_offset))) {
offset = hdr->frag_len - (hdr->auth_len + 8);
if (offset == 0 || tvb_offset_exists(tvb, offset - 1)) {
TRY {
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_auth_type,
&auth_info->auth_type);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_auth_level,
&auth_info->auth_level);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_auth_pad_len,
&auth_info->auth_pad_len);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_auth_rsrvd, NULL);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_auth_ctx_id, NULL);
if (are_credentials) {
tvbuff_t *auth_tvb;
dcerpc_auth_subdissector_fns *auth_fns;
auth_tvb = tvb_new_subset(tvb, offset,
MIN(hdr->auth_len,tvb_length_remaining(tvb, offset)),
hdr->auth_len);
if ((auth_fns = get_auth_subdissector_fns(auth_info->auth_level,
auth_info->auth_type)))
dissect_auth_verf(auth_tvb, pinfo, dcerpc_tree, auth_fns,
hdr, auth_info);
else
proto_tree_add_text(dcerpc_tree, tvb, offset, hdr->auth_len,
"Auth Credentials");
}
auth_info->auth_size = hdr->auth_len + 8;
} CATCH_BOUNDS_ERRORS {
show_exception(tvb, pinfo, dcerpc_tree, EXCEPT_CODE, GET_MESSAGE);
} ENDTRY;
}
}
}
guint16 dcerpc_get_transport_salt(packet_info *pinfo)
{
switch (pinfo->dcetransporttype) {
case DCE_CN_TRANSPORT_SMBPIPE:
return pinfo->dcetransportsalt;
}
return 0;
}
static void
dissect_dcerpc_cn_bind(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *dcerpc_tree, e_dce_cn_common_hdr_t *hdr)
{
conversation_t *conv = find_or_create_conversation(pinfo);
guint8 num_ctx_items = 0;
guint i;
guint16 ctx_id;
guint8 num_trans_items;
guint j;
e_uuid_t if_id;
e_uuid_t trans_id;
guint32 trans_ver;
guint16 if_ver, if_ver_minor;
dcerpc_auth_info auth_info;
char *uuid_str;
const char *uuid_name = NULL;
proto_item *iface_item = NULL;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_max_xmit, NULL);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_max_recv, NULL);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_assoc_group, NULL);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_num_ctx_items, &num_ctx_items);
offset += 3;
col_append_fstr(pinfo->cinfo, COL_INFO, ", %u context items:", num_ctx_items);
for (i = 0; i < num_ctx_items; i++) {
proto_item *ctx_item = NULL;
proto_tree *ctx_tree = NULL, *iface_tree = NULL;
gint ctx_offset = offset;
dissect_dcerpc_uint16(tvb, offset, pinfo, NULL, hdr->drep,
hf_dcerpc_cn_ctx_id, &ctx_id);
pinfo->dcectxid = ctx_id;
if (dcerpc_tree) {
ctx_item = proto_tree_add_item(dcerpc_tree, hf_dcerpc_cn_ctx_item,
tvb, offset, 0,
ENC_NA);
ctx_tree = proto_item_add_subtree(ctx_item, ett_dcerpc_cn_ctx);
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ctx_tree, hdr->drep,
hf_dcerpc_cn_ctx_id, &ctx_id);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, ctx_tree, hdr->drep,
hf_dcerpc_cn_num_trans_items, &num_trans_items);
if (dcerpc_tree) {
proto_item_append_text(ctx_item, "[%u]: Context ID:%u", i+1, ctx_id);
}
offset += 1;
dcerpc_tvb_get_uuid(tvb, offset, hdr->drep, &if_id);
if (ctx_tree) {
iface_item = proto_tree_add_item(ctx_tree, hf_dcerpc_cn_bind_abstract_syntax, tvb, offset, 0, ENC_NA);
iface_tree = proto_item_add_subtree(iface_item, ett_dcerpc_cn_iface);
uuid_str = guid_to_str((e_guid_t*)&if_id);
uuid_name = guids_get_uuid_name(&if_id);
if (uuid_name) {
proto_tree_add_guid_format(iface_tree, hf_dcerpc_cn_bind_if_id, tvb,
offset, 16, (e_guid_t *) &if_id, "Interface: %s UUID: %s", uuid_name, uuid_str);
proto_item_append_text(iface_item, ": %s", uuid_name);
proto_item_append_text(ctx_item, ", %s", uuid_name);
} else {
proto_tree_add_guid_format(iface_tree, hf_dcerpc_cn_bind_if_id, tvb,
offset, 16, (e_guid_t *) &if_id, "Interface UUID: %s", uuid_str);
proto_item_append_text(iface_item, ": %s", uuid_str);
proto_item_append_text(ctx_item, ", %s", uuid_str);
}
}
offset += 16;
if (hdr->drep[0] & DREP_LITTLE_ENDIAN) {
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, iface_tree, hdr->drep,
hf_dcerpc_cn_bind_if_ver, &if_ver);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, iface_tree, hdr->drep,
hf_dcerpc_cn_bind_if_ver_minor, &if_ver_minor);
} else {
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, iface_tree, hdr->drep,
hf_dcerpc_cn_bind_if_ver_minor, &if_ver_minor);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, iface_tree, hdr->drep,
hf_dcerpc_cn_bind_if_ver, &if_ver);
}
if (ctx_tree) {
proto_item_append_text(iface_item, " V%u.%u", if_ver, if_ver_minor);
proto_item_set_len(iface_item, 20);
}
memset(&trans_id, 0, sizeof(trans_id));
for (j = 0; j < num_trans_items; j++) {
proto_tree *trans_tree = NULL;
proto_item *trans_item = NULL;
dcerpc_tvb_get_uuid(tvb, offset, hdr->drep, &trans_id);
if (ctx_tree) {
trans_item = proto_tree_add_item(ctx_tree, hf_dcerpc_cn_bind_trans_syntax, tvb, offset, 0, ENC_NA);
trans_tree = proto_item_add_subtree(trans_item, ett_dcerpc_cn_trans_syntax);
uuid_str = guid_to_str((e_guid_t *) &trans_id);
uuid_name = guids_get_uuid_name(&trans_id);
if (uuid_name) {
proto_tree_add_guid_format(trans_tree, hf_dcerpc_cn_bind_trans_id, tvb,
offset, 16, (e_guid_t *) &trans_id,
"Transport Syntax: %s UUID:%s", uuid_name, uuid_str);
proto_item_append_text(trans_item, "[%u]: %s", j+1, uuid_name);
proto_item_append_text(ctx_item, ", %s", uuid_name);
} else {
proto_tree_add_guid_format(trans_tree, hf_dcerpc_cn_bind_trans_id, tvb,
offset, 16, (e_guid_t *) &trans_id, "Transport Syntax: %s", uuid_str);
proto_item_append_text(trans_item, "[%u]: %s", j+1, uuid_str);
proto_item_append_text(ctx_item, ", %s", uuid_str);
}
}
offset += 16;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, trans_tree, hdr->drep,
hf_dcerpc_cn_bind_trans_ver, &trans_ver);
if (ctx_tree) {
proto_item_set_len(trans_item, 20);
proto_item_append_text(trans_item, " V%u", trans_ver);
}
}
if (!(pinfo->fd->flags.visited)) {
dcerpc_bind_key *key;
dcerpc_bind_value *value;
key = (dcerpc_bind_key *)se_alloc(sizeof (dcerpc_bind_key));
key->conv = conv;
key->ctx_id = ctx_id;
key->smb_fid = dcerpc_get_transport_salt(pinfo);
value = (dcerpc_bind_value *)se_alloc(sizeof (dcerpc_bind_value));
value->uuid = if_id;
value->ver = if_ver;
value->transport = trans_id;
g_hash_table_insert(dcerpc_binds, key, value);
}
if (i > 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ",");
col_append_fstr(pinfo->cinfo, COL_INFO, " %s V%u.%u (%s)",
guids_resolve_uuid_to_str(&if_id), if_ver, if_ver_minor,
guids_resolve_uuid_to_str(&trans_id));
if (ctx_tree) {
proto_item_set_len(ctx_item, offset - ctx_offset);
}
}
dissect_dcerpc_cn_auth(tvb, offset, pinfo, dcerpc_tree, hdr, TRUE, &auth_info);
}
static void
dissect_dcerpc_cn_bind_ack(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *dcerpc_tree, e_dce_cn_common_hdr_t *hdr)
{
guint16 max_xmit, max_recv;
guint16 sec_addr_len;
guint8 num_results;
guint i;
guint16 result = 0;
guint16 reason = 0;
e_uuid_t trans_id;
guint32 trans_ver;
dcerpc_auth_info auth_info;
const char *uuid_name = NULL;
const char *result_str = NULL;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_max_xmit, &max_xmit);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_max_recv, &max_recv);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_assoc_group, NULL);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_sec_addr_len, &sec_addr_len);
if (sec_addr_len != 0) {
tvb_ensure_bytes_exist(tvb, offset, sec_addr_len);
proto_tree_add_item(dcerpc_tree, hf_dcerpc_cn_sec_addr, tvb, offset,
sec_addr_len, ENC_ASCII|ENC_NA);
offset += sec_addr_len;
}
if (offset % 4) {
offset += 4 - offset % 4;
}
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_num_results, &num_results);
offset += 3;
col_append_fstr(pinfo->cinfo, COL_INFO, ", max_xmit: %u max_recv: %u, %u results:",
max_xmit, max_recv, num_results);
for (i = 0; i < num_results; i++) {
proto_tree *ctx_tree = NULL;
proto_item *ctx_item = NULL;
if (dcerpc_tree) {
ctx_item = proto_tree_add_text(dcerpc_tree, tvb, offset, 24, "Ctx Item[%u]:", i+1);
ctx_tree = proto_item_add_subtree(ctx_item, ett_dcerpc_cn_ctx);
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ctx_tree,
hdr->drep, hf_dcerpc_cn_ack_result,
&result);
if (result != 0) {
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ctx_tree,
hdr->drep, hf_dcerpc_cn_ack_reason,
&reason);
} else {
offset += 2;
}
result_str = val_to_str(result, p_cont_result_vals, "Unknown result (%u)");
if (ctx_tree) {
dcerpc_tvb_get_uuid(tvb, offset, hdr->drep, &trans_id);
uuid_name = guids_get_uuid_name(&trans_id);
if (! uuid_name) {
uuid_name = guid_to_str((e_guid_t *) &trans_id);
}
proto_tree_add_guid_format(ctx_tree, hf_dcerpc_cn_ack_trans_id, tvb,
offset, 16, (e_guid_t *) &trans_id, "Transfer Syntax: %s",
uuid_name);
proto_item_append_text(ctx_item, " %s, %s", result_str, uuid_name);
}
offset += 16;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, ctx_tree, hdr->drep,
hf_dcerpc_cn_ack_trans_ver, &trans_ver);
if (i > 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ",");
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", result_str);
}
dissect_dcerpc_cn_auth(tvb, offset, pinfo, dcerpc_tree, hdr, TRUE, &auth_info);
}
static void
dissect_dcerpc_cn_bind_nak(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *dcerpc_tree, e_dce_cn_common_hdr_t *hdr)
{
guint16 reason;
guint8 num_protocols;
guint i;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_cn_reject_reason,
&reason);
col_append_fstr(pinfo->cinfo, COL_INFO, " reason: %s",
val_to_str(reason, reject_reason_vals, "Unknown (%u)"));
if (reason == PROTOCOL_VERSION_NOT_SUPPORTED) {
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_num_protocols,
&num_protocols);
for (i = 0; i < num_protocols; i++) {
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_cn_protocol_ver_major,
NULL);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_cn_protocol_ver_minor,
NULL);
}
}
}
static const char *
fragment_type(guint8 flags)
{
static const char* t[4] = {
"Mid",
"1st",
"Last",
"Single"
};
return t[flags & PFC_FRAG_MASK];
}
static void
dissect_dcerpc_cn_stub(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *dcerpc_tree, proto_tree *tree,
e_dce_cn_common_hdr_t *hdr, dcerpc_info *di,
dcerpc_auth_info *auth_info, guint32 alloc_hint _U_,
guint32 frame)
{
gint length, reported_length;
gboolean save_fragmented;
fragment_data *fd_head = NULL;
tvbuff_t *auth_tvb, *payload_tvb, *decrypted_tvb;
proto_item *pi;
proto_item *parent_pi;
proto_item *dcerpc_tree_item;
save_fragmented = pinfo->fragmented;
length = tvb_length_remaining(tvb, offset);
reported_length = tvb_reported_length_remaining(tvb, offset);
if (reported_length < 0 ||
(guint32)reported_length < auth_info->auth_size) {
return;
}
reported_length -= auth_info->auth_size;
if (length > reported_length)
length = reported_length;
payload_tvb = tvb_new_subset(tvb, offset, length, reported_length);
auth_tvb = NULL;
if (tvb_length(tvb) == tvb_reported_length(tvb)) {
if (tvb_length_remaining(tvb, offset+length) > 8) {
auth_tvb = tvb_new_subset_remaining(tvb, offset+length+8);
}
}
if (auth_info->auth_type &&
(auth_info->auth_level == DCE_C_AUTHN_LEVEL_PKT_PRIVACY)) {
dcerpc_auth_subdissector_fns *auth_fns;
decrypted_tvb = NULL;
if (DCE_C_RPC_AUTHN_PROTOCOL_SEC_CHAN == auth_info->auth_type) {
dissect_dcerpc_cn_auth(tvb, offset, pinfo, dcerpc_tree, hdr, TRUE, auth_info);
}
if ((auth_fns = get_auth_subdissector_fns(
auth_info->auth_level, auth_info->auth_type))) {
tvbuff_t *result;
result = decode_encrypted_data(
payload_tvb, auth_tvb, pinfo, auth_fns,
hdr->ptype == PDU_REQ, auth_info);
if (result) {
if (dcerpc_tree)
proto_tree_add_text(
dcerpc_tree, payload_tvb, 0, -1,
"Encrypted stub data (%d byte%s)",
tvb_reported_length(payload_tvb),
plurality(tvb_length(payload_tvb), "", "s"));
add_new_data_source(
pinfo, result, "Decrypted stub data");
decrypted_tvb = result;
}
}
} else
decrypted_tvb = payload_tvb;
if (PFC_NOT_FRAGMENTED(hdr)) {
pinfo->fragmented = FALSE;
dcerpc_try_handoff(
pinfo, tree, dcerpc_tree, payload_tvb, decrypted_tvb,
hdr->drep, di, auth_info);
pinfo->fragmented = save_fragmented;
return;
}
pinfo->fragmented = TRUE;
if ( (!dcerpc_reassemble) && (hdr->flags & PFC_FIRST_FRAG) ) {
dcerpc_try_handoff(
pinfo, tree, dcerpc_tree, payload_tvb, decrypted_tvb,
hdr->drep, di, auth_info);
expert_add_info_format(pinfo, NULL, PI_REASSEMBLE, PI_CHAT,
"%s fragment", fragment_type(hdr->flags));
pinfo->fragmented = save_fragmented;
return;
}
if (pinfo->fd->flags.visited) {
fd_head = fragment_get_reassembled(&dcerpc_co_reassembly_table, frame);
goto end_cn_stub;
}
if ( !dcerpc_reassemble || (tvb_length(tvb) != tvb_reported_length(tvb)) )
goto end_cn_stub;
if (!frame)
goto end_cn_stub;
if (decrypted_tvb == NULL) {
goto end_cn_stub;
}
fd_head = fragment_add_seq_next(&dcerpc_co_reassembly_table,
decrypted_tvb, 0, pinfo, frame, NULL,
tvb_length(decrypted_tvb),
hdr->flags&PFC_LAST_FRAG ? FALSE : TRUE );
end_cn_stub:
if (fd_head && (fd_head->flags & FD_DEFRAGMENTED) ) {
if ((pinfo->fd->num == fd_head->reassembled_in) && (hdr->flags & PFC_LAST_FRAG) ) {
tvbuff_t *next_tvb;
proto_item *frag_tree_item;
next_tvb = tvb_new_child_real_data((decrypted_tvb)?decrypted_tvb:payload_tvb,
fd_head->data, fd_head->len, fd_head->len);
add_new_data_source(pinfo, next_tvb, "Reassembled DCE/RPC");
show_fragment_tree(fd_head, &dcerpc_frag_items,
tree, pinfo, next_tvb, &frag_tree_item);
dcerpc_tree_item = proto_tree_get_parent(dcerpc_tree);
if (frag_tree_item && dcerpc_tree_item) {
proto_tree_move_item(tree, dcerpc_tree_item, frag_tree_item);
}
pinfo->fragmented = FALSE;
expert_add_info_format(pinfo, frag_tree_item, PI_REASSEMBLE, PI_CHAT,
"%s fragment, reassembled",
fragment_type(hdr->flags));
dcerpc_try_handoff(pinfo, tree, dcerpc_tree, next_tvb,
next_tvb, hdr->drep, di, auth_info);
} else {
if (decrypted_tvb) {
pi = proto_tree_add_uint(dcerpc_tree, hf_dcerpc_reassembled_in,
decrypted_tvb, 0, 0, fd_head->reassembled_in);
} else {
pi = proto_tree_add_uint(dcerpc_tree, hf_dcerpc_reassembled_in,
payload_tvb, 0, 0, fd_head->reassembled_in);
}
PROTO_ITEM_SET_GENERATED(pi);
parent_pi = proto_tree_get_parent(dcerpc_tree);
if (parent_pi != NULL) {
proto_item_append_text(parent_pi, ", [Reas: #%u]", fd_head->reassembled_in);
}
col_append_fstr(pinfo->cinfo, COL_INFO,
" [DCE/RPC %s fragment, reas: #%u]", fragment_type(hdr->flags), fd_head->reassembled_in);
expert_add_info_format(pinfo, NULL, PI_REASSEMBLE, PI_CHAT,
"%s fragment, reassembled in #%u", fragment_type(hdr->flags), fd_head->reassembled_in);
}
} else {
expert_add_info_format(pinfo, NULL, PI_REASSEMBLE, PI_CHAT,
"%s fragment", fragment_type(hdr->flags));
if (decrypted_tvb) {
show_stub_data(decrypted_tvb, 0, tree, auth_info, FALSE);
} else {
show_stub_data(payload_tvb, 0, tree, auth_info, TRUE);
}
}
pinfo->fragmented = save_fragmented;
}
struct _dcerpc_bind_value *
dcerpc_add_conv_to_bind_table(decode_dcerpc_bind_values_t *binding)
{
dcerpc_bind_value *bind_value;
dcerpc_bind_key *key;
conversation_t *conv;
conv = find_conversation(
0,
&binding->addr_a,
&binding->addr_b,
binding->ptype,
binding->port_a,
binding->port_b,
0);
if (!conv) {
conv = conversation_new(
0,
&binding->addr_a,
&binding->addr_b,
binding->ptype,
binding->port_a,
binding->port_b,
0);
}
bind_value = (dcerpc_bind_value *)se_alloc(sizeof (dcerpc_bind_value));
bind_value->uuid = binding->uuid;
bind_value->ver = binding->ver;
bind_value->transport = uuid_data_repr_proto;
key = (dcerpc_bind_key *)se_alloc(sizeof (dcerpc_bind_key));
key->conv = conv;
key->ctx_id = binding->ctx_id;
key->smb_fid = binding->smb_fid;
g_hash_table_insert(dcerpc_binds, key, bind_value);
return bind_value;
}
static void
dissect_dcerpc_cn_rqst(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *dcerpc_tree, proto_tree *tree,
e_dce_cn_common_hdr_t *hdr)
{
conversation_t *conv;
guint16 ctx_id;
guint16 opnum;
e_uuid_t obj_id = DCERPC_UUID_NULL;
dcerpc_auth_info auth_info;
guint32 alloc_hint;
proto_item *pi;
proto_item *parent_pi;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_alloc_hint, &alloc_hint);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_ctx_id, &ctx_id);
parent_pi = proto_tree_get_parent(dcerpc_tree);
if (parent_pi != NULL) {
proto_item_append_text(parent_pi, ", Ctx: %u", ctx_id);
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_opnum, &opnum);
pinfo->dcectxid = ctx_id;
col_append_fstr(pinfo->cinfo, COL_INFO, ", opnum: %u, Ctx: %u",
opnum, ctx_id);
if (hdr->flags & PFC_OBJECT_UUID) {
dcerpc_tvb_get_uuid(tvb, offset, hdr->drep, &obj_id);
if (dcerpc_tree) {
proto_tree_add_guid_format(dcerpc_tree, hf_dcerpc_obj_id, tvb,
offset, 16, (e_guid_t *) &obj_id, "Object UUID: %s",
guid_to_str((e_guid_t *) &obj_id));
}
offset += 16;
}
dissect_dcerpc_cn_auth(tvb, offset, pinfo, dcerpc_tree, hdr, FALSE, &auth_info);
conv = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
if (!conv)
show_stub_data(tvb, offset, dcerpc_tree, &auth_info, TRUE);
else {
dcerpc_matched_key matched_key, *new_matched_key;
dcerpc_call_value *value;
matched_key.frame = pinfo->fd->num;
matched_key.call_id = hdr->call_id;
value = (dcerpc_call_value *)g_hash_table_lookup(dcerpc_matched, &matched_key);
if (!value) {
dcerpc_bind_key bind_key;
dcerpc_bind_value *bind_value;
bind_key.conv = conv;
bind_key.ctx_id = ctx_id;
bind_key.smb_fid = dcerpc_get_transport_salt(pinfo);
if ((bind_value = (dcerpc_bind_value *)g_hash_table_lookup(dcerpc_binds, &bind_key)) ) {
if (!(hdr->flags&PFC_FIRST_FRAG)) {
dcerpc_cn_call_key call_key;
dcerpc_call_value *call_value;
call_key.conv = conv;
call_key.call_id = hdr->call_id;
call_key.smb_fid = dcerpc_get_transport_salt(pinfo);
if ((call_value = (dcerpc_call_value *)g_hash_table_lookup(dcerpc_cn_calls, &call_key))) {
new_matched_key = (dcerpc_matched_key *)se_alloc(sizeof (dcerpc_matched_key));
*new_matched_key = matched_key;
g_hash_table_insert(dcerpc_matched, new_matched_key, call_value);
value = call_value;
}
} else {
dcerpc_cn_call_key *call_key;
dcerpc_call_value *call_value;
call_key = (dcerpc_cn_call_key *)se_alloc(sizeof (dcerpc_cn_call_key));
call_key->conv = conv;
call_key->call_id = hdr->call_id;
call_key->smb_fid = dcerpc_get_transport_salt(pinfo);
if (g_hash_table_lookup(dcerpc_cn_calls, call_key)) {
g_hash_table_remove(dcerpc_cn_calls, call_key);
}
call_value = (dcerpc_call_value *)se_alloc(sizeof (dcerpc_call_value));
call_value->uuid = bind_value->uuid;
call_value->ver = bind_value->ver;
call_value->object_uuid = obj_id;
call_value->opnum = opnum;
call_value->req_frame = pinfo->fd->num;
call_value->req_time = pinfo->fd->abs_ts;
call_value->rep_frame = 0;
call_value->max_ptr = 0;
call_value->se_data = NULL;
call_value->private_data = NULL;
call_value->pol = NULL;
call_value->flags = 0;
if (!memcmp(&bind_value->transport, &uuid_ndr64, sizeof(uuid_ndr64))) {
call_value->flags |= DCERPC_IS_NDR64;
}
g_hash_table_insert(dcerpc_cn_calls, call_key, call_value);
new_matched_key = (dcerpc_matched_key *)se_alloc(sizeof (dcerpc_matched_key));
*new_matched_key = matched_key;
g_hash_table_insert(dcerpc_matched, new_matched_key, call_value);
value = call_value;
}
}
}
if (value) {
dcerpc_info *di;
di = get_next_di();
di->conv = conv;
di->call_id = hdr->call_id;
di->smb_fid = dcerpc_get_transport_salt(pinfo);
di->ptype = PDU_REQ;
di->call_data = value;
di->hf_index = -1;
if (value->rep_frame != 0) {
pi = proto_tree_add_uint(dcerpc_tree, hf_dcerpc_response_in,
tvb, 0, 0, value->rep_frame);
PROTO_ITEM_SET_GENERATED(pi);
if (parent_pi != NULL) {
proto_item_append_text(parent_pi, ", [Resp: #%u]", value->rep_frame);
}
}
dissect_dcerpc_cn_stub(tvb, offset, pinfo, dcerpc_tree, tree,
hdr, di, &auth_info, alloc_hint,
value->req_frame);
} else {
pi = proto_tree_add_text(dcerpc_tree, tvb, offset, 0, "No bind info for this interface Context ID - capture start too late?");
PROTO_ITEM_SET_GENERATED(pi);
expert_add_info_format(pinfo, pi, PI_UNDECODED, PI_NOTE, "No bind info for interface Context ID:%u",
ctx_id);
show_stub_data(tvb, offset, dcerpc_tree, &auth_info, TRUE);
}
}
dissect_dcerpc_verifier(tvb, pinfo, dcerpc_tree, hdr, &auth_info);
}
static void
dissect_dcerpc_cn_resp(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *dcerpc_tree, proto_tree *tree,
e_dce_cn_common_hdr_t *hdr)
{
dcerpc_call_value *value = NULL;
conversation_t *conv;
guint16 ctx_id;
dcerpc_auth_info auth_info;
guint32 alloc_hint;
proto_item *pi;
proto_item *parent_pi;
e_uuid_t obj_id_null = DCERPC_UUID_NULL;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_alloc_hint, &alloc_hint);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_ctx_id, &ctx_id);
parent_pi = proto_tree_get_parent(dcerpc_tree);
if (parent_pi != NULL) {
proto_item_append_text(parent_pi, ", Ctx: %u", ctx_id);
}
pinfo->dcectxid = ctx_id;
col_append_fstr(pinfo->cinfo, COL_INFO, ", Ctx: %u", ctx_id);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_cancel_count, NULL);
offset++;
dissect_dcerpc_cn_auth(tvb, offset, pinfo, dcerpc_tree, hdr, FALSE, &auth_info);
conv = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
if (!conv) {
show_stub_data(tvb, offset, dcerpc_tree, &auth_info, TRUE);
} else {
dcerpc_matched_key matched_key, *new_matched_key;
matched_key.frame = pinfo->fd->num;
matched_key.call_id = hdr->call_id;
value = (dcerpc_call_value *)g_hash_table_lookup(dcerpc_matched, &matched_key);
if (!value) {
dcerpc_cn_call_key call_key;
dcerpc_call_value *call_value;
call_key.conv = conv;
call_key.call_id = hdr->call_id;
call_key.smb_fid = dcerpc_get_transport_salt(pinfo);
if ((call_value = (dcerpc_call_value *)g_hash_table_lookup(dcerpc_cn_calls, &call_key))) {
if (call_value->req_frame<pinfo->fd->num) {
new_matched_key = (dcerpc_matched_key *)se_alloc(sizeof (dcerpc_matched_key));
*new_matched_key = matched_key;
g_hash_table_insert(dcerpc_matched, new_matched_key, call_value);
value = call_value;
if (call_value->rep_frame == 0) {
call_value->rep_frame = pinfo->fd->num;
}
}
}
}
if (value) {
dcerpc_info *di;
di = get_next_di();
di->conv = conv;
di->call_id = hdr->call_id;
di->smb_fid = dcerpc_get_transport_salt(pinfo);
di->ptype = PDU_RESP;
di->call_data = value;
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_opnum, tvb, 0, 0, value->opnum);
if (dcerpc_tree && (memcmp(&value->object_uuid, &obj_id_null, sizeof(obj_id_null)) != 0)) {
pi = proto_tree_add_guid_format(dcerpc_tree, hf_dcerpc_obj_id, tvb,
offset, 0, (e_guid_t *) &value->object_uuid, "Object UUID: %s",
guid_to_str((e_guid_t *) &value->object_uuid));
PROTO_ITEM_SET_GENERATED(pi);
}
if (value->req_frame != 0) {
nstime_t delta_ts;
pi = proto_tree_add_uint(dcerpc_tree, hf_dcerpc_request_in,
tvb, 0, 0, value->req_frame);
PROTO_ITEM_SET_GENERATED(pi);
if (parent_pi != NULL) {
proto_item_append_text(parent_pi, ", [Req: #%u]", value->req_frame);
}
nstime_delta(&delta_ts, &pinfo->fd->abs_ts, &value->req_time);
pi = proto_tree_add_time(dcerpc_tree, hf_dcerpc_time, tvb, offset, 0, &delta_ts);
PROTO_ITEM_SET_GENERATED(pi);
} else {
pi = proto_tree_add_text(dcerpc_tree,
tvb, 0, 0, "No request to this DCE/RPC call found");
expert_add_info_format(pinfo, pi, PI_SEQUENCE, PI_NOTE,
"No request to this DCE/RPC call found");
}
dissect_dcerpc_cn_stub(tvb, offset, pinfo, dcerpc_tree, tree,
hdr, di, &auth_info, alloc_hint,
value->rep_frame);
} else {
pi = proto_tree_add_text(dcerpc_tree, tvb, offset, 0, "No bind info for this interface Context ID - capture start too late?");
PROTO_ITEM_SET_GENERATED(pi);
expert_add_info_format(pinfo, pi, PI_UNDECODED, PI_NOTE, "No bind info for interface Context ID:%u",
ctx_id);
show_stub_data(tvb, offset, dcerpc_tree, &auth_info, TRUE);
}
}
dissect_dcerpc_verifier(tvb, pinfo, dcerpc_tree, hdr, &auth_info);
}
static void
dissect_dcerpc_cn_fault(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *dcerpc_tree, e_dce_cn_common_hdr_t *hdr)
{
dcerpc_call_value *value = NULL;
conversation_t *conv;
guint16 ctx_id;
guint32 status;
guint32 alloc_hint;
dcerpc_auth_info auth_info;
proto_item *pi = NULL;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_alloc_hint, &alloc_hint);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_ctx_id, &ctx_id);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_cancel_count, NULL);
offset++;
#if 0
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_status, &status);
#endif
status = ((hdr->drep[0] & DREP_LITTLE_ENDIAN)
? tvb_get_letohl(tvb, offset)
: tvb_get_ntohl(tvb, offset));
if (dcerpc_tree) {
pi = proto_tree_add_item(dcerpc_tree, hf_dcerpc_cn_status, tvb, offset, 4, DREP_ENC_INTEGER(hdr->drep));
}
offset+=4;
expert_add_info_format(pinfo, pi, PI_RESPONSE_CODE, PI_NOTE, "Fault: %s",
val_to_str(status, reject_status_vals, "Unknown (0x%08x)"));
pinfo->dcectxid = ctx_id;
col_append_fstr(pinfo->cinfo, COL_INFO,
", Ctx: %u, status: %s", ctx_id,
val_to_str(status, reject_status_vals,
"Unknown (0x%08x)"));
offset += 4;
dissect_dcerpc_cn_auth(tvb, offset, pinfo, dcerpc_tree, hdr, FALSE, &auth_info);
conv = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
if (!conv) {
} else {
dcerpc_matched_key matched_key, *new_matched_key;
matched_key.frame = pinfo->fd->num;
matched_key.call_id = hdr->call_id;
value = (dcerpc_call_value *)g_hash_table_lookup(dcerpc_matched, &matched_key);
if (!value) {
dcerpc_cn_call_key call_key;
dcerpc_call_value *call_value;
call_key.conv = conv;
call_key.call_id = hdr->call_id;
call_key.smb_fid = dcerpc_get_transport_salt(pinfo);
if ((call_value = (dcerpc_call_value *)g_hash_table_lookup(dcerpc_cn_calls, &call_key))) {
new_matched_key = (dcerpc_matched_key *)se_alloc(sizeof (dcerpc_matched_key));
*new_matched_key = matched_key;
g_hash_table_insert(dcerpc_matched, new_matched_key, call_value);
value = call_value;
if (call_value->rep_frame == 0) {
call_value->rep_frame = pinfo->fd->num;
}
}
}
if (value) {
int length, stub_length;
dcerpc_info *di;
proto_item *parent_pi;
di = get_next_di();
di->conv = conv;
di->call_id = hdr->call_id;
di->smb_fid = dcerpc_get_transport_salt(pinfo);
di->ptype = PDU_FAULT;
di->call_data = value;
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_opnum, tvb, 0, 0, value->opnum);
if (value->req_frame != 0) {
nstime_t delta_ts;
pi = proto_tree_add_uint(dcerpc_tree, hf_dcerpc_request_in,
tvb, 0, 0, value->req_frame);
PROTO_ITEM_SET_GENERATED(pi);
parent_pi = proto_tree_get_parent(dcerpc_tree);
if (parent_pi != NULL) {
proto_item_append_text(parent_pi, ", [Req: #%u]", value->req_frame);
}
nstime_delta(&delta_ts, &pinfo->fd->abs_ts, &value->req_time);
pi = proto_tree_add_time(dcerpc_tree, hf_dcerpc_time, tvb, offset, 0, &delta_ts);
PROTO_ITEM_SET_GENERATED(pi);
} else {
pi = proto_tree_add_text(dcerpc_tree,
tvb, 0, 0, "No request to this DCE/RPC call found");
expert_add_info_format(pinfo, pi, PI_SEQUENCE, PI_NOTE,
"No request to this DCE/RPC call found");
}
length = tvb_length_remaining(tvb, offset);
stub_length = length;
if (length > stub_length)
length = stub_length;
if ( (!dcerpc_reassemble) || PFC_NOT_FRAGMENTED(hdr) ||
!tvb_bytes_exist(tvb, offset, stub_length) ) {
if (hdr->flags&PFC_FIRST_FRAG) {
if (dcerpc_tree) {
if (stub_length > 0) {
tvb_ensure_bytes_exist(tvb, offset, stub_length);
proto_tree_add_text(dcerpc_tree, tvb, offset, stub_length,
"Fault stub data (%d byte%s)",
stub_length,
plurality(stub_length, "", "s"));
}
}
} else {
if (dcerpc_tree) {
if (stub_length > 0) {
tvb_ensure_bytes_exist(tvb, offset, stub_length);
proto_tree_add_text(dcerpc_tree, tvb, offset, stub_length,
"Fragment data (%d byte%s)",
stub_length,
plurality(stub_length, "", "s"));
}
}
}
} else {
if (dcerpc_tree) {
if (length > 0) {
tvb_ensure_bytes_exist(tvb, offset, stub_length);
proto_tree_add_text(dcerpc_tree, tvb, offset, stub_length,
"Fragment data (%d byte%s)",
stub_length,
plurality(stub_length, "", "s"));
}
}
if (hdr->flags&PFC_FIRST_FRAG) {
if ( (!pinfo->fd->flags.visited) && value->rep_frame ) {
fragment_add_seq_next(&dcerpc_co_reassembly_table,
tvb, offset,
pinfo, value->rep_frame, NULL,
stub_length,
TRUE);
}
} else if (hdr->flags&PFC_LAST_FRAG) {
if ( value->rep_frame ) {
fragment_data *fd_head;
fd_head = fragment_add_seq_next(&dcerpc_co_reassembly_table,
tvb, offset,
pinfo, value->rep_frame, NULL,
stub_length,
TRUE);
if (fd_head) {
tvbuff_t *next_tvb;
proto_item *frag_tree_item;
next_tvb = tvb_new_child_real_data(tvb, fd_head->data, fd_head->len, fd_head->len);
add_new_data_source(pinfo, next_tvb, "Reassembled DCE/RPC");
show_fragment_tree(fd_head, &dcerpc_frag_items,
dcerpc_tree, pinfo, next_tvb, &frag_tree_item);
if (dcerpc_tree) {
if (length > 0) {
tvb_ensure_bytes_exist(tvb, offset, stub_length);
proto_tree_add_text(dcerpc_tree, tvb, offset, stub_length,
"Fault stub data (%d byte%s)",
stub_length,
plurality(stub_length, "", "s"));
}
}
}
}
} else {
if ( (!pinfo->fd->flags.visited) && value->rep_frame ) {
fragment_add_seq_next(&dcerpc_co_reassembly_table,
tvb, offset,
pinfo, value->rep_frame, NULL,
stub_length,
TRUE);
}
}
}
}
}
}
static void
dissect_dcerpc_cn_rts(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *dcerpc_tree, e_dce_cn_common_hdr_t *hdr)
{
proto_item *tf = NULL;
proto_item *parent_pi = NULL;
proto_tree *cn_rts_pdu_tree = NULL;
guint16 rts_flags;
guint16 commands_nb = 0;
guint32 *cmd;
guint32 i;
const char *info_str = NULL;
rts_flags = dcerpc_tvb_get_ntohs(tvb, offset, hdr->drep);
if (dcerpc_tree) {
proto_tree *cn_rts_flags_tree;
tf = proto_tree_add_uint(dcerpc_tree, hf_dcerpc_cn_rts_flags, tvb, offset, 2, rts_flags);
cn_rts_flags_tree = proto_item_add_subtree(tf, ett_dcerpc_cn_rts_flags);
proto_tree_add_boolean(cn_rts_flags_tree, hf_dcerpc_cn_rts_flags_none, tvb, offset, 1, rts_flags);
proto_tree_add_boolean(cn_rts_flags_tree, hf_dcerpc_cn_rts_flags_ping, tvb, offset, 1, rts_flags);
proto_tree_add_boolean(cn_rts_flags_tree, hf_dcerpc_cn_rts_flags_other_cmd, tvb, offset, 1, rts_flags);
proto_tree_add_boolean(cn_rts_flags_tree, hf_dcerpc_cn_rts_flags_recycle_channel, tvb, offset, 1, rts_flags);
proto_tree_add_boolean(cn_rts_flags_tree, hf_dcerpc_cn_rts_flags_in_channel, tvb, offset, 1, rts_flags);
proto_tree_add_boolean(cn_rts_flags_tree, hf_dcerpc_cn_rts_flags_out_channel, tvb, offset, 1, rts_flags);
proto_tree_add_boolean(cn_rts_flags_tree, hf_dcerpc_cn_rts_flags_eof, tvb, offset, 1, rts_flags);
}
offset += 2;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_rts_commands_nb, &commands_nb);
tf = proto_tree_add_text(dcerpc_tree, tvb, offset, tvb_length_remaining(tvb, offset), "RTS PDU: %u commands", commands_nb);
cn_rts_pdu_tree = proto_item_add_subtree(tf, ett_dcerpc_cn_rts_pdu);
cmd = (guint32 *)ep_alloc(sizeof (guint32) * (commands_nb + 1));
for (i = 0; i < commands_nb; ++i) {
proto_tree *cn_rts_command_tree = NULL;
const guint32 command = dcerpc_tvb_get_ntohl(tvb, offset, hdr->drep);
cmd[i] = command;
tf = proto_tree_add_uint(cn_rts_pdu_tree, hf_dcerpc_cn_rts_command, tvb, offset, 4, command);
cn_rts_command_tree = proto_item_add_subtree(tf, ett_dcerpc_cn_rts_command);
offset += 4;
switch (command) {
case RTS_CMD_RECEIVEWINDOWSIZE:
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, cn_rts_command_tree, hdr->drep, hf_dcerpc_cn_rts_command_receivewindowsize, NULL);
break;
case RTS_CMD_FLOWCONTROLACK:
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, cn_rts_command_tree, hdr->drep, hf_dcerpc_cn_rts_command_fack_bytesreceived, NULL);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, cn_rts_command_tree, hdr->drep, hf_dcerpc_cn_rts_command_fack_availablewindow, NULL);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, cn_rts_command_tree, hdr->drep, hf_dcerpc_cn_rts_command_fack_channelcookie, NULL);
break;
case RTS_CMD_CONNECTIONTIMEOUT:
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, cn_rts_command_tree, hdr->drep, hf_dcerpc_cn_rts_command_connectiontimeout, NULL);
break;
case RTS_CMD_COOKIE:
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, cn_rts_command_tree, hdr->drep, hf_dcerpc_cn_rts_command_cookie, NULL);
break;
case RTS_CMD_CHANNELLIFETIME:
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, cn_rts_command_tree, hdr->drep, hf_dcerpc_cn_rts_command_channellifetime, NULL);
break;
case RTS_CMD_CLIENTKEEPALIVE:
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, cn_rts_command_tree, hdr->drep, hf_dcerpc_cn_rts_command_clientkeepalive, NULL);
break;
case RTS_CMD_VERSION:
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, cn_rts_command_tree, hdr->drep, hf_dcerpc_cn_rts_command_version, NULL);
break;
case RTS_CMD_EMPTY:
break;
case RTS_CMD_PADDING: {
guint8 *padding;
const guint32 conformance_count = dcerpc_tvb_get_ntohl(tvb, offset, hdr->drep);
proto_tree_add_uint(cn_rts_command_tree, hf_dcerpc_cn_rts_command_conformancecount, tvb, offset, 4, conformance_count);
offset += 4;
padding = (guint8 *)tvb_memdup(tvb, offset, conformance_count);
proto_tree_add_bytes(cn_rts_command_tree, hf_dcerpc_cn_rts_command_padding, tvb, offset, conformance_count, padding);
offset += conformance_count;
} break;
case RTS_CMD_NEGATIVEANCE:
break;
case RTS_CMD_ANCE:
break;
case RTS_CMD_CLIENTADDRESS: {
guint8 *padding;
const guint32 addrtype = dcerpc_tvb_get_ntohl(tvb, offset, hdr->drep);
proto_tree_add_uint(cn_rts_command_tree, hf_dcerpc_cn_rts_command_addrtype, tvb, offset, 4, addrtype);
offset += 4;
switch (addrtype) {
case RTS_IPV4: {
const guint32 addr4 = tvb_get_ipv4(tvb, offset);
proto_tree_add_text(cn_rts_command_tree, tvb, offset, 4, "%s", get_hostname(addr4));
offset += 4;
} break;
case RTS_IPV6: {
struct e_in6_addr addr6;
tvb_get_ipv6(tvb, offset, &addr6);
proto_tree_add_text(cn_rts_command_tree, tvb, offset, 16, "%s", get_hostname6(&addr6));
offset += 16;
} break;
}
padding = (guint8 *)tvb_memdup(tvb, offset, 12);
proto_tree_add_bytes(cn_rts_command_tree, hf_dcerpc_cn_rts_command_padding, tvb, offset, 12, padding);
offset += 12;
} break;
case RTS_CMD_ASSOCIATIONGROUPID:
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, cn_rts_command_tree, hdr->drep, hf_dcerpc_cn_rts_command_associationgroupid, NULL);
break;
case RTS_CMD_DESTINATION:
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, cn_rts_command_tree, hdr->drep, hf_dcerpc_cn_rts_command_forwarddestination, NULL);
break;
case RTS_CMD_PINGTRAFFICSENTNOTIFY:
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, cn_rts_command_tree, hdr->drep, hf_dcerpc_cn_rts_command_pingtrafficsentnotify, NULL);
break;
default:
proto_tree_add_text(cn_rts_command_tree, tvb, offset, 0, "unknown RTS command number");
break;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RPCH");
info_str = "unknown RTS PDU";
switch (rts_flags) {
case RTS_FLAG_NONE:
switch (commands_nb) {
case 1:
if (cmd[0] == 0x2) {
info_str = "CONN/A3";
} else if (cmd[0] == 0x3) {
info_str = "IN_R1/A5,IN_R1/A6,IN_R2/A2,IN_R2/A5,OUT_R2/A4";
} else if (cmd[0] == 0x7) {
info_str = "IN_R1/B1";
} else if (cmd[0] == 0x0) {
info_str = "IN_R1/B2";
} else if (cmd[0] == 0xD) {
info_str = "IN_R2/A3,IN_R2/A4";
} else if (cmd[0] == 0xA) {
info_str = "OUT_R1/A9,OUT_R1/A10,OUT_R1/A11,OUT_R2/B1,OUT_R2/B2";
}
break;
case 2:
if ((cmd[0] == 0x0) && (cmd[1] == 0x6)) {
info_str = "CONN/B3";
} else if ((cmd[0] == 0xD) && (cmd[1] == 0xA)) {
info_str = "OUT_R2/A5,OUT_R2/A6";
}
break;
case 3:
if ((cmd[0] == 0x6) && (cmd[1] == 0x0) && (cmd[2] == 0x2)) {
info_str = "CONN/C1,CONN/C2";
}
break;
case 4:
if ((cmd[0] == 0x6) && (cmd[1] == 0x3) && (cmd[2] == 0x3) && (cmd[3] == 0x0)) {
info_str = "CONN/A1";
} else if ((cmd[0] == 0xD) && (cmd[1] == 0x6) && (cmd[2] == 0x0) && (cmd[3] == 0x2)) {
info_str = "IN_R1/A3,IN_R1/A4";
}
break;
case 6:
if ((cmd[0] == 0x6) && (cmd[1] == 0x3) && (cmd[2] == 0x3) && (cmd[3] == 0x4) && (cmd[4] == 0x5) && (cmd[5] == 0xC)) {
info_str = "CONN/B1";
}
break;
default:
break;
}
break;
case RTS_FLAG_PING:
switch (commands_nb) {
case 0:
info_str = "Ping";
break;
case 1:
if ((cmd[0] == 0x7) || (cmd[0] == 0x8)) {
info_str = "OUT_R2/C1";
}
break;
default:
break;
}
break;
case RTS_FLAG_OTHER_CMD:
switch (commands_nb) {
case 1:
if (cmd[0] == 0x5) {
info_str = "Keep-Alive";
} else if (cmd[0] == 0xE) {
info_str = "PingTrafficSentNotify";
} else if (cmd[0] == 0x1) {
info_str = "FlowControlAck";
}
break;
case 2:
if ((cmd[0] == 0xD) && (cmd[1] == 0x1)) {
info_str = "FlowControlAckWithDestination";
}
break;
default:
break;
}
break;
case RTS_FLAG_RECYCLE_CHANNEL:
switch (commands_nb) {
case 1:
if (cmd[0] == 0xD) {
info_str = "OUT_R1/A1,OUT_R1/A2,OUT_R2/A1,OUT_R2/A2";
}
break;
case 4:
if ((cmd[0] == 0x6) && (cmd[1] == 0x3) && (cmd[2] == 0x3) && (cmd[3] == 0x3)) {
info_str = "IN_R1/A1,IN_R2/A1";
}
break;
case 5:
if ((cmd[0] == 0x6) && (cmd[1] == 0x3) && (cmd[2] == 0x3) && (cmd[3] == 0x3) && (cmd[4] == 0x0)) {
info_str = "OUT_R1/A3,OUT_R2/A3";
}
break;
default:
break;
}
break;
case RTS_FLAG_IN_CHANNEL|RTS_FLAG_RECYCLE_CHANNEL:
switch (commands_nb) {
case 6:
if ((cmd[0] == 0x6) && (cmd[1] == 0x3) && (cmd[2] == 0x3) && (cmd[3] == 0x3) && (cmd[4] == 0x0) && (cmd[5] == 0x2)) {
info_str = "IN_R1/A2";
}
break;
default:
break;
}
case RTS_FLAG_IN_CHANNEL:
switch (commands_nb) {
case 7:
if ((cmd[0] == 0x6) && (cmd[1] == 0x3) && (cmd[2] == 0x3) && (cmd[3] == 0x0) && (cmd[4] == 0x2) && (cmd[5] == 0xC) && (cmd[6] == 0xB)) {
info_str = "CONN/B2";
}
break;
default:
break;
}
case RTS_FLAG_OUT_CHANNEL|RTS_FLAG_RECYCLE_CHANNEL:
switch (commands_nb) {
case 7:
if ((cmd[0] == 0x6) && (cmd[1] == 0x3) && (cmd[2] == 0x3) && (cmd[3] == 0x3) && (cmd[4] == 0x4) && (cmd[5] == 0) && (cmd[6] == 0x2)) {
info_str = "OUT_R1/A4";
}
break;
default:
break;
}
break;
case RTS_FLAG_OUT_CHANNEL:
switch (commands_nb) {
case 2:
if ((cmd[0] == 0xD) && (cmd[1] == 0x3)) {
info_str = "OUT_R1/A7,OUT_R1/A8,OUT_R2/A8";
}
break;
case 3:
if ((cmd[0] == 0xD) && (cmd[1] == 0x6) && (cmd[2] == 0x2)) {
info_str = "OUT_R1/A5,OUT_R1/A6";
} else if ((cmd[0] == 0xD) && (cmd[1] == 0x3) && (cmd[2] == 0x6)) {
info_str = "OUT_R2/A7";
}
break;
case 5:
if ((cmd[0] == 0x6) && (cmd[1] == 0x3) && (cmd[2] == 0x3) && (cmd[3] == 0x4) && (cmd[4] == 0x0)) {
info_str = "CONN/A2";
}
break;
default:
break;
}
case RTS_FLAG_EOF:
switch (commands_nb) {
case 1:
if (cmd[0] == 0xA) {
info_str = "OUT_R2/B3";
}
break;
default:
break;
}
break;
case RTS_FLAG_ECHO:
switch (commands_nb) {
case 0:
info_str = "Echo";
break;
default:
break;
}
break;
default:
break;
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s, ", info_str);
col_set_fence(pinfo->cinfo,COL_INFO);
parent_pi = proto_tree_get_parent(dcerpc_tree);
if (parent_pi != NULL) {
proto_item_append_text(parent_pi, ", %s", info_str);
}
}
static gboolean
dissect_dcerpc_cn(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, gboolean can_desegment, int *pkt_len)
{
static const guint8 nulls[4] = { 0 };
int start_offset;
int padding = 0;
proto_item *ti = NULL;
proto_item *tf = NULL;
proto_tree *dcerpc_tree = NULL;
proto_tree *cn_flags_tree = NULL;
proto_tree *drep_tree = NULL;
e_dce_cn_common_hdr_t hdr;
dcerpc_auth_info auth_info;
tvbuff_t *fragment_tvb;
if (tvb_memeql(tvb, offset, nulls, 4) == 0) {
offset += 4;
padding += 4;
}
if (!tvb_bytes_exist(tvb, offset, sizeof (hdr))) {
return FALSE;
}
start_offset = offset;
hdr.rpc_ver = tvb_get_guint8(tvb, offset++);
if (hdr.rpc_ver != 5)
return FALSE;
hdr.rpc_ver_minor = tvb_get_guint8(tvb, offset++);
if ((hdr.rpc_ver_minor != 0) && (hdr.rpc_ver_minor != 1))
return FALSE;
hdr.ptype = tvb_get_guint8(tvb, offset++);
if (hdr.ptype > PDU_RTS)
return FALSE;
hdr.flags = tvb_get_guint8(tvb, offset++);
tvb_memcpy(tvb, (guint8 *)hdr.drep, offset, sizeof (hdr.drep));
offset += (int)sizeof (hdr.drep);
hdr.frag_len = dcerpc_tvb_get_ntohs(tvb, offset, hdr.drep);
offset += 2;
hdr.auth_len = dcerpc_tvb_get_ntohs(tvb, offset, hdr.drep);
offset += 2;
hdr.call_id = dcerpc_tvb_get_ntohl(tvb, offset, hdr.drep);
if (pinfo->dcectxid == 0) {
col_append_fstr(pinfo->cinfo, COL_DCE_CALL, "%u", hdr.call_id);
} else {
col_append_fstr(pinfo->cinfo, COL_DCE_CALL, "#%u", hdr.call_id);
}
if (can_desegment && pinfo->can_desegment
&& !tvb_bytes_exist(tvb, start_offset, hdr.frag_len)) {
pinfo->desegment_offset = start_offset;
pinfo->desegment_len = hdr.frag_len - tvb_length_remaining(tvb, start_offset);
*pkt_len = 0;
return TRUE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DCERPC");
if (pinfo->dcectxid != 0) {
col_append_str(pinfo->cinfo, COL_INFO, " # ");
col_set_fence(pinfo->cinfo,COL_INFO);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: call_id: %u",
pckt_vals[hdr.ptype].strptr, hdr.call_id);
if (pinfo->dcectxid != 0) {
expert_add_info_format(pinfo, NULL, PI_SEQUENCE, PI_CHAT, "Multiple DCE/RPC fragments/PDU's in one packet");
}
offset = start_offset;
tvb_ensure_bytes_exist(tvb, offset, 16);
if (tree) {
ti = proto_tree_add_item(tree, proto_dcerpc, tvb, offset, hdr.frag_len, ENC_NA);
dcerpc_tree = proto_item_add_subtree(ti, ett_dcerpc);
}
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_ver, tvb, offset, 1, hdr.rpc_ver);
offset++;
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_ver_minor, tvb, offset, 1, hdr.rpc_ver_minor);
offset++;
tf = proto_tree_add_uint(dcerpc_tree, hf_dcerpc_packet_type, tvb, offset, 1, hdr.ptype);
offset++;
#if 0
if (hdr.ptype == PDU_BIND || hdr.ptype == PDU_ALTER ||
hdr.ptype == PDU_BIND_ACK || hdr.ptype == PDU_ALTER_ACK)
expert_add_info_format(pinfo, tf, PI_SEQUENCE, PI_CHAT, "Context change: %s",
val_to_str(hdr.ptype, pckt_vals, "(0x%x)"));
#endif
if (hdr.ptype == PDU_BIND_NAK)
expert_add_info_format(pinfo, tf, PI_SEQUENCE, PI_WARN, "Bind not acknowledged");
if (tree) {
proto_item_append_text(ti, " %s, Fragment: %s",
val_to_str(hdr.ptype, pckt_vals, "Unknown (0x%02x)"),
fragment_type(hdr.flags));
tf = proto_tree_add_uint(dcerpc_tree, hf_dcerpc_cn_flags, tvb, offset, 1, hdr.flags);
cn_flags_tree = proto_item_add_subtree(tf, ett_dcerpc_cn_flags);
}
proto_tree_add_boolean(cn_flags_tree, hf_dcerpc_cn_flags_object, tvb, offset, 1, hdr.flags);
proto_tree_add_boolean(cn_flags_tree, hf_dcerpc_cn_flags_maybe, tvb, offset, 1, hdr.flags);
proto_tree_add_boolean(cn_flags_tree, hf_dcerpc_cn_flags_dne, tvb, offset, 1, hdr.flags);
proto_tree_add_boolean(cn_flags_tree, hf_dcerpc_cn_flags_mpx, tvb, offset, 1, hdr.flags);
proto_tree_add_boolean(cn_flags_tree, hf_dcerpc_cn_flags_reserved, tvb, offset, 1, hdr.flags);
proto_tree_add_boolean(cn_flags_tree, hf_dcerpc_cn_flags_cancel_pending, tvb, offset, 1, hdr.flags);
proto_tree_add_boolean(cn_flags_tree, hf_dcerpc_cn_flags_last_frag, tvb, offset, 1, hdr.flags);
proto_tree_add_boolean(cn_flags_tree, hf_dcerpc_cn_flags_first_frag, tvb, offset, 1, hdr.flags);
offset++;
col_append_fstr(pinfo->cinfo, COL_INFO, ", Fragment: %s", fragment_type(hdr.flags));
if (dcerpc_tree) {
tf = proto_tree_add_bytes(dcerpc_tree, hf_dcerpc_drep, tvb, offset, 4, hdr.drep);
drep_tree = proto_item_add_subtree(tf, ett_dcerpc_drep);
}
proto_tree_add_uint(drep_tree, hf_dcerpc_drep_byteorder, tvb, offset, 1, hdr.drep[0] >> 4);
proto_tree_add_uint(drep_tree, hf_dcerpc_drep_character, tvb, offset, 1, hdr.drep[0] & 0x0f);
proto_tree_add_uint(drep_tree, hf_dcerpc_drep_fp, tvb, offset+1, 1, hdr.drep[1]);
offset += (int)sizeof (hdr.drep);
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_cn_frag_len, tvb, offset, 2, hdr.frag_len);
offset += 2;
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_cn_auth_len, tvb, offset, 2, hdr.auth_len);
offset += 2;
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_cn_call_id, tvb, offset, 4, hdr.call_id);
offset += 4;
if (ti) {
proto_item_append_text(ti, ", FragLen: %u, Call: %u", hdr.frag_len, hdr.call_id);
}
if (pkt_len != NULL)
*pkt_len = hdr.frag_len + padding;
fragment_tvb = tvb_new_subset(tvb, 0,
MIN((hdr.frag_len + (guint) start_offset), tvb_length(tvb)) ,
hdr.frag_len + start_offset );
switch (hdr.ptype) {
case PDU_BIND:
case PDU_ALTER:
dissect_dcerpc_cn_bind(fragment_tvb, offset, pinfo, dcerpc_tree, &hdr);
break;
case PDU_BIND_ACK:
case PDU_ALTER_ACK:
dissect_dcerpc_cn_bind_ack(fragment_tvb, offset, pinfo, dcerpc_tree, &hdr);
break;
case PDU_AUTH3:
dissect_dcerpc_cn_auth(fragment_tvb, offset, pinfo, dcerpc_tree, &hdr, TRUE,
&auth_info);
break;
case PDU_REQ:
dissect_dcerpc_cn_rqst(fragment_tvb, offset, pinfo, dcerpc_tree, tree, &hdr);
break;
case PDU_RESP:
dissect_dcerpc_cn_resp(fragment_tvb, offset, pinfo, dcerpc_tree, tree, &hdr);
break;
case PDU_FAULT:
dissect_dcerpc_cn_fault(fragment_tvb, offset, pinfo, dcerpc_tree, &hdr);
break;
case PDU_BIND_NAK:
dissect_dcerpc_cn_bind_nak(fragment_tvb, offset, pinfo, dcerpc_tree, &hdr);
break;
case PDU_CO_CANCEL:
case PDU_ORPHANED:
dissect_dcerpc_cn_auth(fragment_tvb, offset, pinfo, dcerpc_tree, &hdr, FALSE,
&auth_info);
break;
case PDU_SHUTDOWN:
break;
case PDU_RTS:
dissect_dcerpc_cn_rts(fragment_tvb, offset, pinfo, dcerpc_tree, &hdr);
break;
default:
dissect_dcerpc_cn_auth(fragment_tvb, offset, pinfo, dcerpc_tree, &hdr, FALSE,
&auth_info);
break;
}
return TRUE;
}
static gboolean
dissect_dcerpc_cn_pk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
pinfo->dcetransporttype = DCE_TRANSPORT_UNKNOWN;
if (!dissect_dcerpc_cn(tvb, 0, pinfo, tree, FALSE, NULL)) {
return FALSE;
} else {
return TRUE;
}
}
static gboolean
dissect_dcerpc_cn_bs_body(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
volatile int offset = 0;
int pdu_len = 0;
volatile gboolean dcerpc_pdus = 0;
volatile gboolean ret = FALSE;
while (tvb_reported_length_remaining(tvb, offset) != 0) {
TRY {
pdu_len = 0;
if (dissect_dcerpc_cn(tvb, offset, pinfo, tree,
dcerpc_cn_desegment, &pdu_len)) {
dcerpc_pdus++;
}
} CATCH_NONFATAL_ERRORS {
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
dcerpc_pdus++;
} ENDTRY;
if (!dcerpc_pdus) {
break;
}
ret = TRUE;
if (dcerpc_pdus >= 2)
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "%u*DCERPC", dcerpc_pdus);
if (pdu_len == 0) {
proto_tree_add_uint_format(tree, hf_dcerpc_cn_deseg_req, tvb, offset,
0,
tvb_reported_length_remaining(tvb, offset),
"[DCE RPC: %u byte%s left, desegmentation might follow]",
tvb_reported_length_remaining(tvb, offset),
plurality(tvb_reported_length_remaining(tvb, offset), "", "s"));
break;
}
offset += pdu_len;
}
return ret;
}
static gboolean
dissect_dcerpc_cn_bs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
pinfo->dcetransporttype = DCE_TRANSPORT_UNKNOWN;
return dissect_dcerpc_cn_bs_body(tvb, pinfo, tree);
}
static gboolean
dissect_dcerpc_cn_smbpipe(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
pinfo->dcetransporttype = DCE_CN_TRANSPORT_SMBPIPE;
return dissect_dcerpc_cn_bs_body(tvb, pinfo, tree);
}
static gboolean
dissect_dcerpc_cn_smb2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
pinfo->dcetransporttype = DCE_TRANSPORT_UNKNOWN;
return dissect_dcerpc_cn_bs_body(tvb, pinfo, tree);
}
static void
dissect_dcerpc_dg_auth(tvbuff_t *tvb, int offset, proto_tree *dcerpc_tree,
e_dce_dg_common_hdr_t *hdr, int *auth_level_p)
{
proto_item *ti = NULL;
proto_tree *auth_tree = NULL;
guint8 protection_level;
if (auth_level_p != NULL)
*auth_level_p = -1;
offset += hdr->frag_len;
if (tvb_length_remaining(tvb, offset) > 0) {
switch (hdr->auth_proto) {
case DCE_C_RPC_AUTHN_PROTOCOL_KRB5:
ti = proto_tree_add_text(dcerpc_tree, tvb, offset, -1, "Kerberos authentication verifier");
auth_tree = proto_item_add_subtree(ti, ett_dcerpc_krb5_auth_verf);
protection_level = tvb_get_guint8(tvb, offset);
if (auth_level_p != NULL)
*auth_level_p = protection_level;
proto_tree_add_uint(auth_tree, hf_dcerpc_krb5_av_prot_level, tvb, offset, 1, protection_level);
offset++;
proto_tree_add_item(auth_tree, hf_dcerpc_krb5_av_key_vers_num, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (protection_level == DCE_C_AUTHN_LEVEL_PKT_PRIVACY)
offset += 6;
else
offset += 2;
proto_tree_add_item(auth_tree, hf_dcerpc_krb5_av_key_auth_verifier, tvb, offset, 16, ENC_NA);
break;
default:
proto_tree_add_text(dcerpc_tree, tvb, offset, -1, "Authentication verifier");
break;
}
}
}
static void
dissect_dcerpc_dg_cancel_ack(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *dcerpc_tree,
e_dce_dg_common_hdr_t *hdr)
{
guint32 version;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_dg_cancel_vers,
&version);
switch (version) {
case 0:
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_dg_cancel_id,
NULL);
dissect_dcerpc_uint8(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_dg_server_accepting_cancels,
NULL);
break;
}
}
static void
dissect_dcerpc_dg_cancel(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *dcerpc_tree,
e_dce_dg_common_hdr_t *hdr)
{
guint32 version;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_dg_cancel_vers,
&version);
switch (version) {
case 0:
dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_dg_cancel_id,
NULL);
break;
}
}
static void
dissect_dcerpc_dg_fack(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *dcerpc_tree,
e_dce_dg_common_hdr_t *hdr)
{
guint8 version;
guint16 serial_num;
guint16 selack_len;
guint i;
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_dg_fack_vers,
&version);
offset++;
switch (version) {
case 0:
case 1:
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_dg_fack_window_size,
NULL);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_dg_fack_max_tsdu,
NULL);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_dg_fack_max_frag_size,
NULL);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_dg_fack_serial_num,
&serial_num);
col_append_fstr(pinfo->cinfo, COL_INFO, " serial: %u",
serial_num);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_dg_fack_selack_len,
&selack_len);
for (i = 0; i < selack_len; i++) {
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_dg_fack_selack,
NULL);
}
break;
}
}
static void
dissect_dcerpc_dg_reject_fault(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *dcerpc_tree,
e_dce_dg_common_hdr_t *hdr)
{
guint32 status;
dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree,
hdr->drep, hf_dcerpc_dg_status,
&status);
col_append_fstr (pinfo->cinfo, COL_INFO,
": status: %s",
val_to_str(status, reject_status_vals, "Unknown (0x%08x)"));
}
static void
dissect_dcerpc_dg_stub(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *dcerpc_tree, proto_tree *tree,
e_dce_dg_common_hdr_t *hdr, dcerpc_info *di)
{
int length, reported_length, stub_length;
gboolean save_fragmented;
fragment_data *fd_head;
tvbuff_t *next_tvb;
proto_item *pi;
proto_item *parent_pi;
col_append_fstr(pinfo->cinfo, COL_INFO, " opnum: %u len: %u",
di->call_data->opnum, hdr->frag_len );
length = tvb_length_remaining(tvb, offset);
reported_length = tvb_reported_length_remaining(tvb, offset);
stub_length = hdr->frag_len;
if (length > stub_length)
length = stub_length;
if (reported_length > stub_length)
reported_length = stub_length;
save_fragmented = pinfo->fragmented;
if ( (!dcerpc_reassemble) || !(hdr->flags1 & PFCL1_FRAG) ||
!tvb_bytes_exist(tvb, offset, stub_length) ) {
if (hdr->frag_num == 0) {
pinfo->fragmented = (hdr->flags1 & PFCL1_FRAG);
next_tvb = tvb_new_subset(tvb, offset, length,
reported_length);
dcerpc_try_handoff(pinfo, tree, dcerpc_tree, next_tvb,
next_tvb, hdr->drep, di, NULL);
} else {
if (dcerpc_tree) {
if (length > 0) {
tvb_ensure_bytes_exist(tvb, offset, stub_length);
proto_tree_add_text(dcerpc_tree, tvb, offset, stub_length,
"Fragment data (%d byte%s)",
stub_length,
plurality(stub_length, "", "s"));
}
}
}
} else {
if (dcerpc_tree) {
if (length > 0) {
tvb_ensure_bytes_exist(tvb, offset, stub_length);
proto_tree_add_text(dcerpc_tree, tvb, offset, stub_length,
"Fragment data (%d byte%s)", stub_length,
plurality(stub_length, "", "s"));
}
}
fd_head = fragment_add_seq(&dcerpc_cl_reassembly_table,
tvb, offset,
pinfo, hdr->seqnum, (void *)hdr,
hdr->frag_num, stub_length,
!(hdr->flags1 & PFCL1_LASTFRAG), 0);
if (fd_head != NULL) {
if (pinfo->fd->num == fd_head->reassembled_in) {
next_tvb = tvb_new_child_real_data(tvb, fd_head->data, fd_head->len, fd_head->len);
add_new_data_source(pinfo, next_tvb, "Reassembled DCE/RPC");
show_fragment_seq_tree(fd_head, &dcerpc_frag_items,
tree, pinfo, next_tvb, &pi);
pinfo->fragmented = FALSE;
dcerpc_try_handoff(pinfo, tree, dcerpc_tree, next_tvb,
next_tvb, hdr->drep, di, NULL);
} else {
pi = proto_tree_add_uint(dcerpc_tree, hf_dcerpc_reassembled_in,
tvb, 0, 0, fd_head->reassembled_in);
PROTO_ITEM_SET_GENERATED(pi);
parent_pi = proto_tree_get_parent(dcerpc_tree);
if (parent_pi != NULL) {
proto_item_append_text(parent_pi, ", [Reas: #%u]", fd_head->reassembled_in);
}
col_append_fstr(pinfo->cinfo, COL_INFO,
" [DCE/RPC fragment, reas: #%u]", fd_head->reassembled_in);
}
}
}
pinfo->fragmented = save_fragmented;
}
static void
dissect_dcerpc_dg_rqst(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *dcerpc_tree, proto_tree *tree,
e_dce_dg_common_hdr_t *hdr, conversation_t *conv)
{
dcerpc_info *di;
dcerpc_call_value *value, v;
dcerpc_matched_key matched_key, *new_matched_key;
proto_item *pi;
proto_item *parent_pi;
di = get_next_di();
if (!(pinfo->fd->flags.visited)) {
dcerpc_call_value *call_value;
dcerpc_dg_call_key *call_key;
call_key = (dcerpc_dg_call_key *)se_alloc(sizeof (dcerpc_dg_call_key));
call_key->conv = conv;
call_key->seqnum = hdr->seqnum;
call_key->act_id = hdr->act_id;
call_value = (dcerpc_call_value *)se_alloc(sizeof (dcerpc_call_value));
call_value->uuid = hdr->if_id;
call_value->ver = hdr->if_ver;
call_value->object_uuid = hdr->obj_id;
call_value->opnum = hdr->opnum;
call_value->req_frame = pinfo->fd->num;
call_value->req_time = pinfo->fd->abs_ts;
call_value->rep_frame = 0;
call_value->max_ptr = 0;
call_value->se_data = NULL;
call_value->private_data = NULL;
call_value->pol = NULL;
call_value->flags = 0;
g_hash_table_insert(dcerpc_dg_calls, call_key, call_value);
new_matched_key = (dcerpc_matched_key *)se_alloc(sizeof(dcerpc_matched_key));
new_matched_key->frame = pinfo->fd->num;
new_matched_key->call_id = hdr->seqnum;
g_hash_table_insert(dcerpc_matched, new_matched_key, call_value);
}
matched_key.frame = pinfo->fd->num;
matched_key.call_id = hdr->seqnum;
value = (dcerpc_call_value *)g_hash_table_lookup(dcerpc_matched, &matched_key);
if (!value) {
v.uuid = hdr->if_id;
v.ver = hdr->if_ver;
v.object_uuid = hdr->obj_id;
v.opnum = hdr->opnum;
v.req_frame = pinfo->fd->num;
v.rep_frame = 0;
v.max_ptr = 0;
v.se_data = NULL;
v.private_data = NULL;
value = &v;
}
di->conv = conv;
di->call_id = hdr->seqnum;
di->smb_fid = -1;
di->ptype = PDU_REQ;
di->call_data = value;
if (value->rep_frame != 0) {
pi = proto_tree_add_uint(dcerpc_tree, hf_dcerpc_response_in,
tvb, 0, 0, value->rep_frame);
PROTO_ITEM_SET_GENERATED(pi);
parent_pi = proto_tree_get_parent(dcerpc_tree);
if (parent_pi != NULL) {
proto_item_append_text(parent_pi, ", [Resp: #%u]", value->rep_frame);
}
}
dissect_dcerpc_dg_stub(tvb, offset, pinfo, dcerpc_tree, tree, hdr, di);
}
static void
dissect_dcerpc_dg_resp(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *dcerpc_tree, proto_tree *tree,
e_dce_dg_common_hdr_t *hdr, conversation_t *conv)
{
dcerpc_info *di;
dcerpc_call_value *value, v;
dcerpc_matched_key matched_key, *new_matched_key;
proto_item *pi;
proto_item *parent_pi;
di = get_next_di();
if (!(pinfo->fd->flags.visited)) {
dcerpc_call_value *call_value;
dcerpc_dg_call_key call_key;
call_key.conv = conv;
call_key.seqnum = hdr->seqnum;
call_key.act_id = hdr->act_id;
if ((call_value = (dcerpc_call_value *)g_hash_table_lookup(dcerpc_dg_calls, &call_key))) {
new_matched_key = (dcerpc_matched_key *)se_alloc(sizeof (dcerpc_matched_key));
new_matched_key->frame = pinfo->fd->num;
new_matched_key->call_id = hdr->seqnum;
g_hash_table_insert(dcerpc_matched, new_matched_key, call_value);
if (call_value->rep_frame == 0) {
call_value->rep_frame = pinfo->fd->num;
}
}
}
matched_key.frame = pinfo->fd->num;
matched_key.call_id = hdr->seqnum;
value = (dcerpc_call_value *)g_hash_table_lookup(dcerpc_matched, &matched_key);
if (!value) {
v.uuid = hdr->if_id;
v.ver = hdr->if_ver;
v.object_uuid = hdr->obj_id;
v.opnum = hdr->opnum;
v.req_frame = 0;
v.rep_frame = pinfo->fd->num;
v.se_data = NULL;
v.private_data = NULL;
value = &v;
}
di->conv = conv;
di->call_id = 0;
di->smb_fid = -1;
di->ptype = PDU_RESP;
di->call_data = value;
if (value->req_frame != 0) {
nstime_t delta_ts;
pi = proto_tree_add_uint(dcerpc_tree, hf_dcerpc_request_in,
tvb, 0, 0, value->req_frame);
PROTO_ITEM_SET_GENERATED(pi);
parent_pi = proto_tree_get_parent(dcerpc_tree);
if (parent_pi != NULL) {
proto_item_append_text(parent_pi, ", [Req: #%u]", value->req_frame);
}
nstime_delta(&delta_ts, &pinfo->fd->abs_ts, &value->req_time);
pi = proto_tree_add_time(dcerpc_tree, hf_dcerpc_time, tvb, offset, 0, &delta_ts);
PROTO_ITEM_SET_GENERATED(pi);
} else {
pi = proto_tree_add_text(dcerpc_tree,
tvb, 0, 0, "No request to this DCE/RPC call found");
expert_add_info_format(pinfo, pi, PI_SEQUENCE, PI_NOTE,
"No request to this DCE/RPC call found");
}
dissect_dcerpc_dg_stub(tvb, offset, pinfo, dcerpc_tree, tree, hdr, di);
}
static void
dissect_dcerpc_dg_ping_ack(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *dcerpc_tree,
e_dce_dg_common_hdr_t *hdr, conversation_t *conv)
{
proto_item *parent_pi;
dcerpc_call_value *call_value;
dcerpc_dg_call_key call_key;
call_key.conv = conv;
call_key.seqnum = hdr->seqnum;
call_key.act_id = hdr->act_id;
if ((call_value = (dcerpc_call_value *)g_hash_table_lookup(dcerpc_dg_calls, &call_key))) {
proto_item *pi;
nstime_t delta_ts;
pi = proto_tree_add_uint(dcerpc_tree, hf_dcerpc_request_in,
tvb, 0, 0, call_value->req_frame);
PROTO_ITEM_SET_GENERATED(pi);
parent_pi = proto_tree_get_parent(dcerpc_tree);
if (parent_pi != NULL) {
proto_item_append_text(parent_pi, ", [Req: #%u]", call_value->req_frame);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " [req: #%u]", call_value->req_frame);
nstime_delta(&delta_ts, &pinfo->fd->abs_ts, &call_value->req_time);
pi = proto_tree_add_time(dcerpc_tree, hf_dcerpc_time, tvb, offset, 0, &delta_ts);
PROTO_ITEM_SET_GENERATED(pi);
}
}
static gboolean
dissect_dcerpc_dg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti = NULL;
proto_item *tf = NULL;
proto_tree *dcerpc_tree = NULL;
proto_tree *dg_flags1_tree = NULL;
proto_tree *dg_flags2_tree = NULL;
proto_tree *drep_tree = NULL;
e_dce_dg_common_hdr_t hdr;
int offset = 0;
conversation_t *conv;
int auth_level;
char *uuid_str;
const char *uuid_name = NULL;
if (tvb_length(tvb) < sizeof (hdr)) {
return FALSE;
}
hdr.rpc_ver = tvb_get_guint8(tvb, offset++);
if (hdr.rpc_ver != 4)
return FALSE;
hdr.ptype = tvb_get_guint8(tvb, offset++);
if (hdr.ptype > 19)
return FALSE;
hdr.flags1 = tvb_get_guint8(tvb, offset++);
if (hdr.flags1&0x81)
return FALSE;
hdr.flags2 = tvb_get_guint8(tvb, offset++);
if (hdr.flags2&0xfd)
return FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DCERPC");
col_add_str(pinfo->cinfo, COL_INFO, pckt_vals[hdr.ptype].strptr);
tvb_memcpy(tvb, (guint8 *)hdr.drep, offset, sizeof (hdr.drep));
offset += (int)sizeof (hdr.drep);
hdr.serial_hi = tvb_get_guint8(tvb, offset++);
dcerpc_tvb_get_uuid(tvb, offset, hdr.drep, &hdr.obj_id);
offset += 16;
dcerpc_tvb_get_uuid(tvb, offset, hdr.drep, &hdr.if_id);
offset += 16;
dcerpc_tvb_get_uuid(tvb, offset, hdr.drep, &hdr.act_id);
offset += 16;
hdr.server_boot = dcerpc_tvb_get_ntohl(tvb, offset, hdr.drep);
offset += 4;
hdr.if_ver = dcerpc_tvb_get_ntohl(tvb, offset, hdr.drep);
offset += 4;
hdr.seqnum = dcerpc_tvb_get_ntohl(tvb, offset, hdr.drep);
offset += 4;
hdr.opnum = dcerpc_tvb_get_ntohs(tvb, offset, hdr.drep);
offset += 2;
hdr.ihint = dcerpc_tvb_get_ntohs(tvb, offset, hdr.drep);
offset += 2;
hdr.ahint = dcerpc_tvb_get_ntohs(tvb, offset, hdr.drep);
offset += 2;
hdr.frag_len = dcerpc_tvb_get_ntohs(tvb, offset, hdr.drep);
offset += 2;
hdr.frag_num = dcerpc_tvb_get_ntohs(tvb, offset, hdr.drep);
offset += 2;
hdr.auth_proto = tvb_get_guint8(tvb, offset++);
hdr.serial_lo = tvb_get_guint8(tvb, offset++);
if (tree) {
ti = proto_tree_add_item(tree, proto_dcerpc, tvb, 0, -1, ENC_NA);
if (ti) {
dcerpc_tree = proto_item_add_subtree(ti, ett_dcerpc);
proto_item_append_text(ti, " %s, Seq: %u, Serial: %u, Frag: %u, FragLen: %u",
val_to_str(hdr.ptype, pckt_vals, "Unknown (0x%02x)"),
hdr.seqnum, hdr.serial_hi*256+hdr.serial_lo,
hdr.frag_num, hdr.frag_len);
}
}
offset = 0;
if (tree)
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_ver, tvb, offset, 1, hdr.rpc_ver);
offset++;
if (tree)
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_packet_type, tvb, offset, 1, hdr.ptype);
offset++;
if (tree) {
tf = proto_tree_add_uint(dcerpc_tree, hf_dcerpc_dg_flags1, tvb, offset, 1, hdr.flags1);
dg_flags1_tree = proto_item_add_subtree(tf, ett_dcerpc_dg_flags1);
if (dg_flags1_tree) {
proto_tree_add_boolean(dg_flags1_tree, hf_dcerpc_dg_flags1_rsrvd_80, tvb, offset, 1, hdr.flags1);
proto_tree_add_boolean(dg_flags1_tree, hf_dcerpc_dg_flags1_broadcast, tvb, offset, 1, hdr.flags1);
proto_tree_add_boolean(dg_flags1_tree, hf_dcerpc_dg_flags1_idempotent, tvb, offset, 1, hdr.flags1);
proto_tree_add_boolean(dg_flags1_tree, hf_dcerpc_dg_flags1_maybe, tvb, offset, 1, hdr.flags1);
proto_tree_add_boolean(dg_flags1_tree, hf_dcerpc_dg_flags1_nofack, tvb, offset, 1, hdr.flags1);
proto_tree_add_boolean(dg_flags1_tree, hf_dcerpc_dg_flags1_frag, tvb, offset, 1, hdr.flags1);
proto_tree_add_boolean(dg_flags1_tree, hf_dcerpc_dg_flags1_last_frag, tvb, offset, 1, hdr.flags1);
proto_tree_add_boolean(dg_flags1_tree, hf_dcerpc_dg_flags1_rsrvd_01, tvb, offset, 1, hdr.flags1);
if (hdr.flags1) {
proto_item_append_text(tf, " %s%s%s%s%s%s",
(hdr.flags1 & PFCL1_BROADCAST) ? "\"Broadcast\" " : "",
(hdr.flags1 & PFCL1_IDEMPOTENT) ? "\"Idempotent\" " : "",
(hdr.flags1 & PFCL1_MAYBE) ? "\"Maybe\" " : "",
(hdr.flags1 & PFCL1_NOFACK) ? "\"No Fack\" " : "",
(hdr.flags1 & PFCL1_FRAG) ? "\"Fragment\" " : "",
(hdr.flags1 & PFCL1_LASTFRAG) ? "\"Last Fragment\" " : "");
}
}
}
offset++;
if (tree) {
tf = proto_tree_add_uint(dcerpc_tree, hf_dcerpc_dg_flags2, tvb, offset, 1, hdr.flags2);
dg_flags2_tree = proto_item_add_subtree(tf, ett_dcerpc_dg_flags2);
if (dg_flags2_tree) {
proto_tree_add_boolean(dg_flags2_tree, hf_dcerpc_dg_flags2_rsrvd_80, tvb, offset, 1, hdr.flags2);
proto_tree_add_boolean(dg_flags2_tree, hf_dcerpc_dg_flags2_rsrvd_40, tvb, offset, 1, hdr.flags2);
proto_tree_add_boolean(dg_flags2_tree, hf_dcerpc_dg_flags2_rsrvd_20, tvb, offset, 1, hdr.flags2);
proto_tree_add_boolean(dg_flags2_tree, hf_dcerpc_dg_flags2_rsrvd_10, tvb, offset, 1, hdr.flags2);
proto_tree_add_boolean(dg_flags2_tree, hf_dcerpc_dg_flags2_rsrvd_08, tvb, offset, 1, hdr.flags2);
proto_tree_add_boolean(dg_flags2_tree, hf_dcerpc_dg_flags2_rsrvd_04, tvb, offset, 1, hdr.flags2);
proto_tree_add_boolean(dg_flags2_tree, hf_dcerpc_dg_flags2_cancel_pending, tvb, offset, 1, hdr.flags2);
proto_tree_add_boolean(dg_flags2_tree, hf_dcerpc_dg_flags2_rsrvd_01, tvb, offset, 1, hdr.flags2);
if (hdr.flags2) {
proto_item_append_text(tf, " %s",
(hdr.flags2 & PFCL2_CANCEL_PENDING) ? "\"Cancel Pending\" " : "");
}
}
}
offset++;
if (tree) {
tf = proto_tree_add_bytes(dcerpc_tree, hf_dcerpc_drep, tvb, offset, sizeof (hdr.drep), hdr.drep);
drep_tree = proto_item_add_subtree(tf, ett_dcerpc_drep);
if (drep_tree) {
proto_tree_add_uint(drep_tree, hf_dcerpc_drep_byteorder, tvb, offset, 1, hdr.drep[0] >> 4);
proto_tree_add_uint(drep_tree, hf_dcerpc_drep_character, tvb, offset, 1, hdr.drep[0] & 0x0f);
proto_tree_add_uint(drep_tree, hf_dcerpc_drep_fp, tvb, offset+1, 1, hdr.drep[1]);
proto_item_append_text(tf, " (Order: %s, Char: %s, Float: %s)",
val_to_str_const(hdr.drep[0] >> 4, drep_byteorder_vals, "Unknown"),
val_to_str_const(hdr.drep[0] & 0x0f, drep_character_vals, "Unknown"),
val_to_str_const(hdr.drep[1], drep_fp_vals, "Unknown"));
}
}
offset += (int)sizeof (hdr.drep);
if (tree)
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_dg_serial_hi, tvb, offset, 1, hdr.serial_hi);
offset++;
if (tree) {
proto_tree_add_guid_format(dcerpc_tree, hf_dcerpc_obj_id, tvb,
offset, 16, (e_guid_t *) &hdr.obj_id, "Object UUID: %s",
guid_to_str((e_guid_t *) &hdr.obj_id));
}
offset += 16;
if (tree) {
uuid_str = guid_to_str((e_guid_t*)&hdr.if_id);
uuid_name = guids_get_uuid_name(&hdr.if_id);
if (uuid_name) {
proto_tree_add_guid_format(dcerpc_tree, hf_dcerpc_dg_if_id, tvb,
offset, 16, (e_guid_t *) &hdr.if_id, "Interface: %s UUID: %s", uuid_name, uuid_str);
} else {
proto_tree_add_guid_format(dcerpc_tree, hf_dcerpc_dg_if_id, tvb,
offset, 16, (e_guid_t *) &hdr.if_id, "Interface UUID: %s", uuid_str);
}
}
offset += 16;
if (tree) {
proto_tree_add_guid_format(dcerpc_tree, hf_dcerpc_dg_act_id, tvb,
offset, 16, (e_guid_t *) &hdr.act_id, "Activity: %s",
guid_to_str((e_guid_t *) &hdr.act_id));
}
offset += 16;
if (tree) {
nstime_t server_boot;
server_boot.secs = hdr.server_boot;
server_boot.nsecs = 0;
if (hdr.server_boot == 0)
proto_tree_add_time_format(dcerpc_tree, hf_dcerpc_dg_server_boot,
tvb, offset, 4, &server_boot,
"Server boot time: Unknown (0)");
else
proto_tree_add_time(dcerpc_tree, hf_dcerpc_dg_server_boot,
tvb, offset, 4, &server_boot);
}
offset += 4;
if (tree)
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_dg_if_ver, tvb, offset, 4, hdr.if_ver);
offset += 4;
if (tree)
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_dg_seqnum, tvb, offset, 4, hdr.seqnum);
col_append_fstr(pinfo->cinfo, COL_INFO, ": seq: %u", hdr.seqnum);
col_append_fstr(pinfo->cinfo, COL_DCE_CALL, "%u", hdr.seqnum);
offset += 4;
if (tree)
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_opnum, tvb, offset, 2, hdr.opnum);
offset += 2;
if (tree)
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_dg_ihint, tvb, offset, 2, hdr.ihint);
offset += 2;
if (tree)
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_dg_ahint, tvb, offset, 2, hdr.ahint);
offset += 2;
if (tree)
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_dg_frag_len, tvb, offset, 2, hdr.frag_len);
offset += 2;
if (tree)
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_dg_frag_num, tvb, offset, 2, hdr.frag_num);
if (hdr.flags1 & PFCL1_FRAG) {
col_append_fstr(pinfo->cinfo, COL_INFO, " frag: %u",
hdr.frag_num);
}
offset += 2;
if (tree)
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_dg_auth_proto, tvb, offset, 1, hdr.auth_proto);
offset++;
if (tree)
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_dg_serial_lo, tvb, offset, 1, hdr.serial_lo);
if (hdr.flags1 & PFCL1_FRAG) {
col_append_fstr(pinfo->cinfo, COL_INFO, " serial: %u",
(hdr.serial_hi << 8) | hdr.serial_lo);
}
offset++;
if (tree) {
dissect_dcerpc_dg_auth(tvb, offset, dcerpc_tree, &hdr,
&auth_level);
}
conv = find_or_create_conversation(pinfo);
switch (hdr.ptype) {
case PDU_CANCEL_ACK:
if (hdr.frag_len != 0)
dissect_dcerpc_dg_cancel_ack(tvb, offset, pinfo, dcerpc_tree, &hdr);
break;
case PDU_CL_CANCEL:
if (hdr.frag_len != 0)
dissect_dcerpc_dg_cancel(tvb, offset, pinfo, dcerpc_tree, &hdr);
break;
case PDU_NOCALL:
if (hdr.frag_len != 0)
dissect_dcerpc_dg_fack(tvb, offset, pinfo, dcerpc_tree, &hdr);
break;
case PDU_FACK:
if (hdr.frag_len != 0)
dissect_dcerpc_dg_fack(tvb, offset, pinfo, dcerpc_tree, &hdr);
break;
case PDU_REJECT:
case PDU_FAULT:
dissect_dcerpc_dg_reject_fault(tvb, offset, pinfo, dcerpc_tree, &hdr);
break;
case PDU_REQ:
dissect_dcerpc_dg_rqst(tvb, offset, pinfo, dcerpc_tree, tree, &hdr, conv);
break;
case PDU_RESP:
dissect_dcerpc_dg_resp(tvb, offset, pinfo, dcerpc_tree, tree, &hdr, conv);
break;
case PDU_ACK:
case PDU_PING:
dissect_dcerpc_dg_ping_ack(tvb, offset, pinfo, dcerpc_tree, &hdr, conv);
break;
case PDU_WORKING:
default:
break;
}
return TRUE;
}
static void
dcerpc_init_protocol(void)
{
if (dcerpc_binds) {
g_hash_table_destroy(dcerpc_binds);
dcerpc_binds = NULL;
}
if (!dcerpc_binds) {
dcerpc_binds = g_hash_table_new(dcerpc_bind_hash, dcerpc_bind_equal);
}
if (dcerpc_cn_calls) {
g_hash_table_destroy(dcerpc_cn_calls);
}
dcerpc_cn_calls = g_hash_table_new(dcerpc_cn_call_hash, dcerpc_cn_call_equal);
if (dcerpc_dg_calls) {
g_hash_table_destroy(dcerpc_dg_calls);
}
dcerpc_dg_calls = g_hash_table_new(dcerpc_dg_call_hash, dcerpc_dg_call_equal);
if (dcerpc_matched) {
g_hash_table_destroy(dcerpc_matched);
}
dcerpc_matched = g_hash_table_new(dcerpc_matched_hash, dcerpc_matched_equal);
g_hook_list_invoke(&dcerpc_hooks_init_protos, FALSE );
}
void
proto_register_dcerpc(void)
{
static hf_register_info hf[] = {
{ &hf_dcerpc_request_in,
{ "Request in frame", "dcerpc.request_in", FT_FRAMENUM, BASE_NONE,
NULL, 0, "This packet is a response to the packet with this number", HFILL }},
{ &hf_dcerpc_response_in,
{ "Response in frame", "dcerpc.response_in", FT_FRAMENUM, BASE_NONE,
NULL, 0, "This packet will be responded in the packet with this number", HFILL }},
{ &hf_dcerpc_referent_id,
{ "Referent ID", "dcerpc.referent_id", FT_UINT32, BASE_HEX,
NULL, 0, "Referent ID for this NDR encoded pointer", HFILL }},
{ &hf_dcerpc_ver,
{ "Version", "dcerpc.ver", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_ver_minor,
{ "Version (minor)", "dcerpc.ver_minor", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_packet_type,
{ "Packet type", "dcerpc.pkt_type", FT_UINT8, BASE_DEC, VALS(pckt_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_flags,
{ "Packet Flags", "dcerpc.cn_flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_flags_first_frag,
{ "First Frag", "dcerpc.cn_flags.first_frag", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFC_FIRST_FRAG, NULL, HFILL }},
{ &hf_dcerpc_cn_flags_last_frag,
{ "Last Frag", "dcerpc.cn_flags.last_frag", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFC_LAST_FRAG, NULL, HFILL }},
{ &hf_dcerpc_cn_flags_cancel_pending,
{ "Cancel Pending", "dcerpc.cn_flags.cancel_pending", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFC_PENDING_CANCEL, NULL, HFILL }},
{ &hf_dcerpc_cn_flags_reserved,
{ "Reserved", "dcerpc.cn_flags.reserved", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFC_RESERVED_1, NULL, HFILL }},
{ &hf_dcerpc_cn_flags_mpx,
{ "Multiplex", "dcerpc.cn_flags.mpx", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFC_CONC_MPX, NULL, HFILL }},
{ &hf_dcerpc_cn_flags_dne,
{ "Did Not Execute", "dcerpc.cn_flags.dne", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFC_DID_NOT_EXECUTE, NULL, HFILL }},
{ &hf_dcerpc_cn_flags_maybe,
{ "Maybe", "dcerpc.cn_flags.maybe", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFC_MAYBE, NULL, HFILL }},
{ &hf_dcerpc_cn_flags_object,
{ "Object", "dcerpc.cn_flags.object", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFC_OBJECT_UUID, NULL, HFILL }},
{ &hf_dcerpc_drep,
{ "Data Representation", "dcerpc.drep", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_drep_byteorder,
{ "Byte order", "dcerpc.drep.byteorder", FT_UINT8, BASE_DEC, VALS(drep_byteorder_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_drep_character,
{ "Character", "dcerpc.drep.character", FT_UINT8, BASE_DEC, VALS(drep_character_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_drep_fp,
{ "Floating-point", "dcerpc.drep.fp", FT_UINT8, BASE_DEC, VALS(drep_fp_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_frag_len,
{ "Frag Length", "dcerpc.cn_frag_len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_auth_len,
{ "Auth Length", "dcerpc.cn_auth_len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_call_id,
{ "Call ID", "dcerpc.cn_call_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_max_xmit,
{ "Max Xmit Frag", "dcerpc.cn_max_xmit", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_max_recv,
{ "Max Recv Frag", "dcerpc.cn_max_recv", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_assoc_group,
{ "Assoc Group", "dcerpc.cn_assoc_group", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_num_ctx_items,
{ "Num Ctx Items", "dcerpc.cn_num_ctx_items", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_ctx_item,
{ "Ctx Item", "dcerpc.cn_ctx_item", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_ctx_id,
{ "Context ID", "dcerpc.cn_ctx_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_num_trans_items,
{ "Num Trans Items", "dcerpc.cn_num_trans_items", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_bind_abstract_syntax,
{ "Abstract Syntax", "dcerpc.cn_bind_abstract_syntax", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_bind_if_id,
{ "Interface UUID", "dcerpc.cn_bind_to_uuid", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_bind_if_ver,
{ "Interface Ver", "dcerpc.cn_bind_if_ver", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_bind_if_ver_minor,
{ "Interface Ver Minor", "dcerpc.cn_bind_if_ver_minor", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_bind_trans_syntax,
{ "Transfer Syntax", "dcerpc.cn_bind_trans", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_bind_trans_id,
{ "ID", "dcerpc.cn_bind_trans_id", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_bind_trans_ver,
{ "ver", "dcerpc.cn_bind_trans_ver", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_alloc_hint,
{ "Alloc hint", "dcerpc.cn_alloc_hint", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_sec_addr_len,
{ "Scndry Addr len", "dcerpc.cn_sec_addr_len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_sec_addr,
{ "Scndry Addr", "dcerpc.cn_sec_addr", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_num_results,
{ "Num results", "dcerpc.cn_num_results", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_ack_result,
{ "Ack result", "dcerpc.cn_ack_result", FT_UINT16, BASE_DEC, VALS(p_cont_result_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_ack_reason,
{ "Ack reason", "dcerpc.cn_ack_reason", FT_UINT16, BASE_DEC, VALS(p_provider_reason_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_ack_trans_id,
{ "Transfer Syntax", "dcerpc.cn_ack_trans_id", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_ack_trans_ver,
{ "Syntax ver", "dcerpc.cn_ack_trans_ver", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_reject_reason,
{ "Reject reason", "dcerpc.cn_reject_reason", FT_UINT16, BASE_DEC, VALS(reject_reason_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_num_protocols,
{ "Number of protocols", "dcerpc.cn_num_protocols", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_protocol_ver_major,
{ "Protocol major version", "dcerpc.cn_protocol_ver_major", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_protocol_ver_minor,
{ "Protocol minor version", "dcerpc.cn_protocol_ver_minor", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_cancel_count,
{ "Cancel count", "dcerpc.cn_cancel_count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_status,
{ "Status", "dcerpc.cn_status", FT_UINT32, BASE_HEX, VALS(reject_status_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_deseg_req,
{ "Desegmentation Required", "dcerpc.cn_deseg_req", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_auth_type,
{ "Auth type", "dcerpc.auth_type", FT_UINT8, BASE_DEC, VALS(authn_protocol_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_auth_level,
{ "Auth level", "dcerpc.auth_level", FT_UINT8, BASE_DEC, VALS(authn_level_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_auth_pad_len,
{ "Auth pad len", "dcerpc.auth_pad_len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_auth_rsrvd,
{ "Auth Rsrvd", "dcerpc.auth_rsrvd", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_auth_ctx_id,
{ "Auth Context ID", "dcerpc.auth_ctx_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_flags1,
{ "Flags1", "dcerpc.dg_flags1", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_flags1_rsrvd_01,
{ "Reserved", "dcerpc.dg_flags1_rsrvd_01", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL1_RESERVED_01, NULL, HFILL }},
{ &hf_dcerpc_dg_flags1_last_frag,
{ "Last Fragment", "dcerpc.dg_flags1_last_frag", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL1_LASTFRAG, NULL, HFILL }},
{ &hf_dcerpc_dg_flags1_frag,
{ "Fragment", "dcerpc.dg_flags1_frag", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL1_FRAG, NULL, HFILL }},
{ &hf_dcerpc_dg_flags1_nofack,
{ "No Fack", "dcerpc.dg_flags1_nofack", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL1_NOFACK, NULL, HFILL }},
{ &hf_dcerpc_dg_flags1_maybe,
{ "Maybe", "dcerpc.dg_flags1_maybe", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL1_MAYBE, NULL, HFILL }},
{ &hf_dcerpc_dg_flags1_idempotent,
{ "Idempotent", "dcerpc.dg_flags1_idempotent", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL1_IDEMPOTENT, NULL, HFILL }},
{ &hf_dcerpc_dg_flags1_broadcast,
{ "Broadcast", "dcerpc.dg_flags1_broadcast", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL1_BROADCAST, NULL, HFILL }},
{ &hf_dcerpc_dg_flags1_rsrvd_80,
{ "Reserved", "dcerpc.dg_flags1_rsrvd_80", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL1_RESERVED_80, NULL, HFILL }},
{ &hf_dcerpc_dg_flags2,
{ "Flags2", "dcerpc.dg_flags2", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_flags2_rsrvd_01,
{ "Reserved", "dcerpc.dg_flags2_rsrvd_01", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL2_RESERVED_01, NULL, HFILL }},
{ &hf_dcerpc_dg_flags2_cancel_pending,
{ "Cancel Pending", "dcerpc.dg_flags2_cancel_pending", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL2_CANCEL_PENDING, NULL, HFILL }},
{ &hf_dcerpc_dg_flags2_rsrvd_04,
{ "Reserved", "dcerpc.dg_flags2_rsrvd_04", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL2_RESERVED_04, NULL, HFILL }},
{ &hf_dcerpc_dg_flags2_rsrvd_08,
{ "Reserved", "dcerpc.dg_flags2_rsrvd_08", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL2_RESERVED_08, NULL, HFILL }},
{ &hf_dcerpc_dg_flags2_rsrvd_10,
{ "Reserved", "dcerpc.dg_flags2_rsrvd_10", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL2_RESERVED_10, NULL, HFILL }},
{ &hf_dcerpc_dg_flags2_rsrvd_20,
{ "Reserved", "dcerpc.dg_flags2_rsrvd_20", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL2_RESERVED_20, NULL, HFILL }},
{ &hf_dcerpc_dg_flags2_rsrvd_40,
{ "Reserved", "dcerpc.dg_flags2_rsrvd_40", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL2_RESERVED_40, NULL, HFILL }},
{ &hf_dcerpc_dg_flags2_rsrvd_80,
{ "Reserved", "dcerpc.dg_flags2_rsrvd_80", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PFCL2_RESERVED_80, NULL, HFILL }},
{ &hf_dcerpc_dg_serial_lo,
{ "Serial Low", "dcerpc.dg_serial_lo", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_serial_hi,
{ "Serial High", "dcerpc.dg_serial_hi", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_ahint,
{ "Activity Hint", "dcerpc.dg_ahint", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_ihint,
{ "Interface Hint", "dcerpc.dg_ihint", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_frag_len,
{ "Fragment len", "dcerpc.dg_frag_len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_frag_num,
{ "Fragment num", "dcerpc.dg_frag_num", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_auth_proto,
{ "Auth proto", "dcerpc.dg_auth_proto", FT_UINT8, BASE_DEC, VALS(authn_protocol_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_seqnum,
{ "Sequence num", "dcerpc.dg_seqnum", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_server_boot,
{ "Server boot time", "dcerpc.dg_server_boot", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_if_ver,
{ "Interface Ver", "dcerpc.dg_if_ver", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_krb5_av_prot_level,
{ "Protection Level", "dcerpc.krb5_av.prot_level", FT_UINT8, BASE_DEC, VALS(authn_level_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_krb5_av_key_vers_num,
{ "Key Version Number", "dcerpc.krb5_av.key_vers_num", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_krb5_av_key_auth_verifier,
{ "Authentication Verifier", "dcerpc.krb5_av.auth_verifier", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_obj_id,
{ "Object", "dcerpc.obj_id", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_if_id,
{ "Interface", "dcerpc.dg_if_id", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_act_id,
{ "Activity", "dcerpc.dg_act_id", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_opnum,
{ "Opnum", "dcerpc.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_cancel_vers,
{ "Cancel Version", "dcerpc.dg_cancel_vers", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_cancel_id,
{ "Cancel ID", "dcerpc.dg_cancel_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_server_accepting_cancels,
{ "Server accepting cancels", "dcerpc.server_accepting_cancels", FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_fack_vers,
{ "FACK Version", "dcerpc.fack_vers", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_fack_window_size,
{ "Window Size", "dcerpc.fack_window_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_fack_max_tsdu,
{ "Max TSDU", "dcerpc.fack_max_tsdu", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_fack_max_frag_size,
{ "Max Frag Size", "dcerpc.fack_max_frag_size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_fack_serial_num,
{ "Serial Num", "dcerpc.fack_serial_num", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_fack_selack_len,
{ "Selective ACK Len", "dcerpc.fack_selack_len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_fack_selack,
{ "Selective ACK", "dcerpc.fack_selack", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_dg_status,
{ "Status", "dcerpc.dg_status", FT_UINT32, BASE_HEX, VALS(reject_status_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_array_max_count,
{ "Max Count", "dcerpc.array.max_count", FT_UINT32, BASE_DEC, NULL, 0x0, "Maximum Count: Number of elements in the array", HFILL }},
{ &hf_dcerpc_array_offset,
{ "Offset", "dcerpc.array.offset", FT_UINT32, BASE_DEC, NULL, 0x0, "Offset for first element in array", HFILL }},
{ &hf_dcerpc_array_actual_count,
{ "Actual Count", "dcerpc.array.actual_count", FT_UINT32, BASE_DEC, NULL, 0x0, "Actual Count: Actual number of elements in the array", HFILL }},
{ &hf_dcerpc_array_buffer,
{ "Buffer", "dcerpc.array.buffer", FT_BYTES, BASE_NONE, NULL, 0x0, "Buffer: Buffer containing elements of the array", HFILL }},
{ &hf_dcerpc_op,
{ "Operation", "dcerpc.op", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_fragments,
{ "Reassembled DCE/RPC Fragments", "dcerpc.fragments", FT_NONE, BASE_NONE,
NULL, 0x0, "DCE/RPC Fragments", HFILL }},
{ &hf_dcerpc_fragment,
{ "DCE/RPC Fragment", "dcerpc.fragment", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_fragment_overlap,
{ "Fragment overlap", "dcerpc.fragment.overlap", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Fragment overlaps with other fragments", HFILL }},
{ &hf_dcerpc_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "dcerpc.fragment.overlap.conflict", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Overlapping fragments contained conflicting data", HFILL }},
{ &hf_dcerpc_fragment_multiple_tails,
{ "Multiple tail fragments found", "dcerpc.fragment.multipletails", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Several tails were found when defragmenting the packet", HFILL }},
{ &hf_dcerpc_fragment_too_long_fragment,
{ "Fragment too long", "dcerpc.fragment.toolongfragment", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Fragment contained data past end of packet", HFILL }},
{ &hf_dcerpc_fragment_error,
{ "Defragmentation error", "dcerpc.fragment.error", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, "Defragmentation error due to illegal fragments", HFILL }},
{ &hf_dcerpc_fragment_count,
{ "Fragment count", "dcerpc.fragment.count", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_time,
{ "Time from request", "dcerpc.time", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0, "Time between Request and Response for DCE-RPC calls", HFILL }},
{ &hf_dcerpc_reassembled_in,
{ "Reassembled PDU in frame", "dcerpc.reassembled_in", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, "The DCE/RPC PDU is completely reassembled in the packet with this number", HFILL }},
{ &hf_dcerpc_reassembled_length,
{ "Reassembled DCE/RPC length", "dcerpc.reassembled.length", FT_UINT32, BASE_DEC,
NULL, 0x0, "The total length of the reassembled payload", HFILL }},
{ &hf_dcerpc_unknown_if_id,
{ "Unknown DCERPC interface id", "dcerpc.unknown_if_id", FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_flags,
{ "RTS Flags", "dcerpc.cn_rts_flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_flags_none,
{"None", "dcerpc.cn_rts_flags.none", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RTS_FLAG_NONE, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_flags_ping,
{ "Ping", "dcerpc.cn_rts.flags.ping", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RTS_FLAG_PING, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_flags_other_cmd,
{ "Other Cmd", "dcerpc.cn_rts_flags.other_cmd", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RTS_FLAG_OTHER_CMD, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_flags_recycle_channel,
{ "Recycle Channel", "dcerpc.cn_rts_flags.recycle_channel", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RTS_FLAG_RECYCLE_CHANNEL, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_flags_in_channel,
{ "In Channel", "dcerpc.cn_rts_flags.in_channel", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RTS_FLAG_IN_CHANNEL, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_flags_out_channel,
{ "Out Channel", "dcerpc.cn_rts_flags.out_channel", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RTS_FLAG_OUT_CHANNEL, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_flags_eof,
{ "EOF", "dcerpc.cn_rts_flags.eof", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RTS_FLAG_EOF, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_commands_nb,
{ "RTS Number of Commands", "dcerpc.cn_rts_commands_nb", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_command,
{ "RTS Command", "dcerpc.cn_rts_command", FT_UINT32, BASE_HEX, VALS(rts_command_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_command_receivewindowsize,
{"Receive Window Size", "dcerpc.cn_rts_command.receivewindowsize", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_command_fack_bytesreceived,
{"Bytes Received", "dcerpc.cn_rts_command.fack.bytesreceived", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_command_fack_availablewindow,
{"Available Window", "dcerpc.cn_rts_command.fack.availablewindow", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_command_fack_channelcookie,
{"Channel Cookie", "dcerpc.cn_rts_command.fack.channelcookie", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_command_connectiontimeout,
{"Connection Timeout", "dcerpc.cn_rts_command.connectiontimeout", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_command_cookie,
{"Cookie", "dcerpc.cn_rts_command.cookie", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_command_channellifetime,
{"Channel Lifetime", "dcerpc.cn_rts_command.channellifetime", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_command_clientkeepalive,
{"Client Keepalive", "dcerpc.cn_rts_command.clientkeepalive", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_command_version,
{"Version", "dcerpc.cn_rts_command.version", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_command_conformancecount,
{"Conformance Count", "dcerpc.cn_rts_command.padding.conformancecount", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_command_padding,
{ "Padding", "dcerpc.cn_rts_command.padding.padding", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_dcerpc_cn_rts_command_addrtype,
{ "Address Type", "dcerpc.cn_rts_command.addrtype", FT_UINT32, BASE_DEC, VALS(rts_addresstype_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_command_associationgroupid,
{"Association Group ID", "dcerpc.cn_rts_command.associationgroupid", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_command_forwarddestination,
{"Forward Destination", "dcerpc.cn_rts_command.forwarddestination", FT_UINT32, BASE_DEC, VALS(rts_forward_destination_vals), 0x0, NULL, HFILL }},
{ &hf_dcerpc_cn_rts_command_pingtrafficsentnotify,
{"Ping Traffic Sent Notify", "dcerpc.cn_rts_command.pingtrafficsentnotify", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc,
&ett_dcerpc_cn_flags,
&ett_dcerpc_cn_ctx,
&ett_dcerpc_cn_iface,
&ett_dcerpc_cn_trans_syntax,
&ett_dcerpc_cn_rts_flags,
&ett_dcerpc_cn_rts_command,
&ett_dcerpc_cn_rts_pdu,
&ett_dcerpc_drep,
&ett_dcerpc_dg_flags1,
&ett_dcerpc_dg_flags2,
&ett_dcerpc_pointer_data,
&ett_dcerpc_string,
&ett_dcerpc_fragments,
&ett_dcerpc_fragment,
&ett_dcerpc_krb5_auth_verf,
};
module_t *dcerpc_module;
proto_dcerpc = proto_register_protocol("Distributed Computing Environment / Remote Procedure Call (DCE/RPC)", "DCERPC", "dcerpc");
proto_register_field_array(proto_dcerpc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine(dcerpc_init_protocol);
dcerpc_module = prefs_register_protocol(proto_dcerpc, NULL);
prefs_register_bool_preference(dcerpc_module,
"desegment_dcerpc",
"Reassemble DCE/RPC messages spanning multiple TCP segments",
"Whether the DCE/RPC dissector should reassemble messages"
" spanning multiple TCP segments."
" To use this option, you must also enable"
" \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&dcerpc_cn_desegment);
prefs_register_bool_preference(dcerpc_module,
"reassemble_dcerpc",
"Reassemble DCE/RPC fragments",
"Whether the DCE/RPC dissector should reassemble fragmented DCE/RPC PDUs",
&dcerpc_reassemble);
register_init_routine(dcerpc_reassemble_init);
dcerpc_uuids = g_hash_table_new(dcerpc_uuid_hash, dcerpc_uuid_equal);
dcerpc_tap = register_tap("dcerpc");
g_hook_list_init(&dcerpc_hooks_init_protos, sizeof(GHook));
}
void
proto_reg_handoff_dcerpc(void)
{
heur_dissector_add("tcp", dissect_dcerpc_cn_bs, proto_dcerpc);
heur_dissector_add("netbios", dissect_dcerpc_cn_pk, proto_dcerpc);
heur_dissector_add("udp", dissect_dcerpc_dg, proto_dcerpc);
heur_dissector_add("smb_transact", dissect_dcerpc_cn_smbpipe, proto_dcerpc);
heur_dissector_add("smb2_heur_subdissectors", dissect_dcerpc_cn_smb2, proto_dcerpc);
heur_dissector_add("http", dissect_dcerpc_cn_bs, proto_dcerpc);
dcerpc_smb_init(proto_dcerpc);
guids_add_uuid(&uuid_data_repr_proto, "32bit NDR");
guids_add_uuid(&uuid_ndr64, "64bit NDR");
guids_add_uuid(&uuid_bind_time_feature_nego, "bind time feature negotiation");
guids_add_uuid(&uuid_asyncemsmdb, "async MAPI");
}
