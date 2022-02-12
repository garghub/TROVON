static dcerpc_decode_as_data*
dcerpc_get_decode_data(packet_info* pinfo)
{
dcerpc_decode_as_data* data = (dcerpc_decode_as_data*)p_get_proto_data(pinfo->pool, pinfo, proto_dcerpc, 0);
if (data == NULL)
{
data = wmem_new0(pinfo->pool, dcerpc_decode_as_data);
data->dcetransporttype = -1;
p_add_proto_data(pinfo->pool, pinfo, proto_dcerpc, 0, data);
}
return data;
}
static struct _dcerpc_bind_value *
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
bind_value = (dcerpc_bind_value *)wmem_alloc(wmem_file_scope(), sizeof (dcerpc_bind_value));
bind_value->uuid = binding->uuid;
bind_value->ver = binding->ver;
bind_value->transport = uuid_data_repr_proto;
key = (dcerpc_bind_key *)wmem_alloc(wmem_file_scope(), sizeof (dcerpc_bind_key));
key->conv = conv;
key->ctx_id = binding->ctx_id;
key->transport_salt = binding->transport_salt;
g_hash_table_insert(dcerpc_binds, key, bind_value);
return bind_value;
}
static void
decode_dcerpc_inject_binding(gpointer data, gpointer user_data _U_)
{
dcerpc_add_conv_to_bind_table((decode_dcerpc_bind_values_t *) data);
}
static void
decode_dcerpc_inject_bindings(void) {
g_slist_foreach(decode_dcerpc_bindings, decode_dcerpc_inject_binding, NULL );
}
static void
decode_dcerpc_binding_free(void *binding_in)
{
decode_dcerpc_bind_values_t *binding = (decode_dcerpc_bind_values_t *)binding_in;
g_free((void *) binding->addr_a.data);
g_free((void *) binding->addr_b.data);
if (binding->ifname)
g_string_free(binding->ifname, TRUE);
g_free(binding);
}
static void
dcerpc_decode_as_free(gpointer value)
{
decode_dcerpc_bind_values_t *binding = (decode_dcerpc_bind_values_t *)value;
if (binding != NULL)
decode_dcerpc_binding_free(binding);
}
void
decode_dcerpc_reset_all(void)
{
decode_dcerpc_bind_values_t *binding;
while (decode_dcerpc_bindings) {
binding = (decode_dcerpc_bind_values_t *)decode_dcerpc_bindings->data;
decode_dcerpc_binding_free(binding);
decode_dcerpc_bindings = g_slist_remove(
decode_dcerpc_bindings,
decode_dcerpc_bindings->data);
}
}
void
decode_dcerpc_add_show_list(decode_add_show_list_func func, gpointer user_data)
{
g_slist_foreach(decode_dcerpc_bindings, func, user_data);
}
static void
dcerpc_prompt(packet_info *pinfo, gchar* result)
{
GString *str = g_string_new("Replace binding between:\r\n"),
*address_str = g_string_new("");
dcerpc_decode_as_data* decode_data = dcerpc_get_decode_data(pinfo);
switch (pinfo->ptype) {
case(PT_TCP):
g_string_append(address_str, "Address: ToBeDone TCP port");
break;
case(PT_UDP):
g_string_append(address_str, "Address: ToBeDone UDP port");
break;
default:
g_string_append(address_str, "Address: ToBeDone Unknown port type");
}
g_string_append_printf(str, "%s: %u\r\n", address_str->str, pinfo->srcport);
g_string_append(str, "&\r\n");
g_string_append_printf(str, "%s: %u\r\n", address_str->str, pinfo->destport);
g_string_append_printf(str, "&\r\nContext ID: %u\r\n", decode_data->dcectxid);
g_string_append_printf(str, "&\r\nSMB FID: %"G_GINT64_MODIFIER"u\r\n",
dcerpc_get_transport_salt(pinfo));
g_string_append(str, "with:\r\n");
g_strlcpy(result, str->str, MAX_DECODE_AS_PROMPT_LEN);
g_string_free(str, TRUE);
g_string_free(address_str, TRUE);
}
static gpointer
dcerpc_value(packet_info *pinfo)
{
decode_dcerpc_bind_values_t *binding;
dcerpc_decode_as_data* decode_data = dcerpc_get_decode_data(pinfo);
binding = g_new(decode_dcerpc_bind_values_t,1);
COPY_ADDRESS(&binding->addr_a, &pinfo->src);
COPY_ADDRESS(&binding->addr_b, &pinfo->dst);
binding->ptype = pinfo->ptype;
binding->port_a = pinfo->srcport;
binding->port_b = pinfo->destport;
binding->ctx_id = decode_data->dcectxid;
binding->transport_salt = dcerpc_get_transport_salt(pinfo);
binding->ifname = NULL;
binding->ver = 0;
return binding;
}
static void
decode_dcerpc_add_to_list(gpointer key, gpointer value, gpointer user_data)
{
struct dcerpc_decode_as_populate* populate = (struct dcerpc_decode_as_populate*)user_data;
dcerpc_uuid_value *v = (dcerpc_uuid_value *)value;
if (strcmp(v->name, "(none)"))
populate->add_to_list("DCE-RPC", v->name, key, populate->ui_element);
}
static void
dcerpc_populate_list(const gchar *table_name _U_, decode_as_add_to_list_func add_to_list, gpointer ui_element)
{
struct dcerpc_decode_as_populate populate;
populate.add_to_list = add_to_list;
populate.ui_element = ui_element;
g_hash_table_foreach(dcerpc_uuids, decode_dcerpc_add_to_list, &populate);
}
static gint
decode_dcerpc_binding_cmp(gconstpointer a, gconstpointer b)
{
const decode_dcerpc_bind_values_t *binding_a = (const decode_dcerpc_bind_values_t *)a;
const decode_dcerpc_bind_values_t *binding_b = (const decode_dcerpc_bind_values_t *)b;
if (
ADDRESSES_EQUAL(&binding_a->addr_a, &binding_b->addr_a) &&
ADDRESSES_EQUAL(&binding_a->addr_b, &binding_b->addr_b) &&
binding_a->ptype == binding_b->ptype &&
binding_a->port_a == binding_b->port_a &&
binding_a->port_b == binding_b->port_b &&
binding_a->ctx_id == binding_b->ctx_id &&
binding_a->transport_salt == binding_b->transport_salt)
{
return 0;
}
return 1;
}
static gboolean
decode_dcerpc_binding_reset(const char *name _U_, const gpointer pattern)
{
decode_dcerpc_bind_values_t *binding = (decode_dcerpc_bind_values_t*)pattern;
GSList *le;
decode_dcerpc_bind_values_t *old_binding;
le = g_slist_find_custom(decode_dcerpc_bindings,
binding,
decode_dcerpc_binding_cmp);
if (le == NULL)
return FALSE;
old_binding = (decode_dcerpc_bind_values_t *)le->data;
decode_dcerpc_bindings = g_slist_remove(decode_dcerpc_bindings, le->data);
g_free((void *) old_binding->addr_a.data);
g_free((void *) old_binding->addr_b.data);
g_string_free(old_binding->ifname, TRUE);
g_free(old_binding);
return FALSE;
}
static gboolean
dcerpc_decode_as_change(const char *name, const gpointer pattern, gpointer handle, gchar* list_name)
{
decode_dcerpc_bind_values_t *binding = (decode_dcerpc_bind_values_t*)pattern;
decode_dcerpc_bind_values_t *stored_binding;
dcerpc_uuid_key *key = *((dcerpc_uuid_key**)handle);
binding->ifname = g_string_new(list_name);
binding->uuid = key->uuid;
binding->ver = key->ver;
decode_dcerpc_binding_reset(name, binding);
stored_binding = g_new(decode_dcerpc_bind_values_t,1);
*stored_binding = *binding;
COPY_ADDRESS(&stored_binding->addr_a, &binding->addr_a);
COPY_ADDRESS(&stored_binding->addr_b, &binding->addr_b);
stored_binding->ifname = g_string_new(binding->ifname->str);
decode_dcerpc_bindings = g_slist_append (decode_dcerpc_bindings, stored_binding);
return FALSE;
}
static guint
dcerpc_fragment_hash(gconstpointer k)
{
const dcerpc_fragment_key* key = (const dcerpc_fragment_key*) k;
guint hash_val;
hash_val = 0;
hash_val += key->id;
hash_val += key->act_id.data1;
hash_val += key->act_id.data2 << 16;
hash_val += key->act_id.data3;
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
&& (memcmp (&key1->act_id, &key2->act_id, sizeof (e_guid_t)) == 0))
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
if (key)
g_slice_free(dcerpc_fragment_key, key);
}
static void
dcerpc_fragment_free_persistent_key(gpointer ptr)
{
dcerpc_fragment_key *key = (dcerpc_fragment_key *)ptr;
if (key) {
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
FAKE_DCERPC_INFO_STRUCTURE
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
proto_tree_add_expert_format(tree, pinfo, &ei_dcerpc_invalid_pdu_authentication_attempt,
auth_tvb, 0, 0,
"Don't know how to dissect authentication data for %s pdu type",
val_to_str(hdr->ptype, pckt_vals, "Unknown (%u)"));
return;
break;
}
if (fn)
fn(auth_tvb, 0, pinfo, tree, &di, hdr->drep);
else {
proto_tree_add_expert_format(tree, pinfo, &ei_dcerpc_verifier_unavailable,
auth_tvb, 0, hdr->auth_len,
"%s Verifier unavailable",
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
return ((memcmp(&key1->uuid, &key2->uuid, sizeof (e_guid_t)) == 0)
&& (key1->ver == key2->ver));
}
static guint
dcerpc_uuid_hash(gconstpointer k)
{
const dcerpc_uuid_key *key = (const dcerpc_uuid_key *)k;
return key->uuid.data1;
}
void
dcerpc_init_uuid(int proto, int ett, e_guid_t *uuid, guint16 ver,
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
dcerpc_get_proto_name(e_guid_t *uuid, guint16 ver)
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
dcerpc_get_proto_hf_opnum(e_guid_t *uuid, guint16 ver)
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
dcerpc_get_proto_sub_dissector(e_guid_t *uuid, guint16 ver)
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
&& (key1->transport_salt == key2->transport_salt));
}
static guint
dcerpc_bind_hash(gconstpointer k)
{
const dcerpc_bind_key *key = (const dcerpc_bind_key *)k;
guint hash;
hash = GPOINTER_TO_UINT(key->conv);
hash += key->ctx_id;
hash += (guint)key->transport_salt;
hash += (guint)(key->transport_salt << sizeof(guint));
return hash;
}
static gint
dcerpc_cn_call_equal(gconstpointer k1, gconstpointer k2)
{
const dcerpc_cn_call_key *key1 = (const dcerpc_cn_call_key *)k1;
const dcerpc_cn_call_key *key2 = (const dcerpc_cn_call_key *)k2;
return ((key1->conv == key2->conv)
&& (key1->call_id == key2->call_id)
&& (key1->transport_salt == key2->transport_salt));
}
static gint
dcerpc_dg_call_equal(gconstpointer k1, gconstpointer k2)
{
const dcerpc_dg_call_key *key1 = (const dcerpc_dg_call_key *)k1;
const dcerpc_dg_call_key *key2 = (const dcerpc_dg_call_key *)k2;
return ((key1->conv == key2->conv)
&& (key1->seqnum == key2->seqnum)
&& ((memcmp(&key1->act_id, &key2->act_id, sizeof (e_guid_t)) == 0)));
}
static guint
dcerpc_cn_call_hash(gconstpointer k)
{
const dcerpc_cn_call_key *key = (const dcerpc_cn_call_key *)k;
guint hash;
hash = GPOINTER_TO_UINT(key->conv);
hash += key->call_id;
hash += (guint)key->transport_salt;
hash += (guint)(key->transport_salt << sizeof(guint));
return hash;
}
static guint
dcerpc_dg_call_hash(gconstpointer k)
{
const dcerpc_dg_call_key *key = (const dcerpc_dg_call_key *)k;
return (GPOINTER_TO_UINT(key->conv) + key->seqnum + key->act_id.data1
+ (key->act_id.data2 << 16) + key->act_id.data3
+ (key->act_id.data4[0] << 24) + (key->act_id.data4[1] << 16)
+ (key->act_id.data4[2] << 8) + (key->act_id.data4[3] << 0)
+ (key->act_id.data4[4] << 24) + (key->act_id.data4[5] << 16)
+ (key->act_id.data4[6] << 8) + (key->act_id.data4[7] << 0));
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
static gboolean
uuid_equal(e_guid_t *uuid1, e_guid_t *uuid2)
{
if( (uuid1->data1 != uuid2->data1)
||(uuid1->data2 != uuid2->data2)
||(uuid1->data3 != uuid2->data3)
||(uuid1->data4[0] != uuid2->data4[0])
||(uuid1->data4[1] != uuid2->data4[1])
||(uuid1->data4[2] != uuid2->data4[2])
||(uuid1->data4[3] != uuid2->data4[3])
||(uuid1->data4[4] != uuid2->data4[4])
||(uuid1->data4[5] != uuid2->data4[5])
||(uuid1->data4[6] != uuid2->data4[6])
||(uuid1->data4[7] != uuid2->data4[7]) ){
return FALSE;
}
return TRUE;
}
static void
dcerpcstat_init(struct register_srt* srt, GArray* srt_array, srt_gui_init_cb gui_callback, void* gui_data)
{
dcerpcstat_tap_data_t* tap_data = (dcerpcstat_tap_data_t*)get_srt_table_param_data(srt);
srt_stat_table *dcerpc_srt_table;
int i, hf_opnum;
dcerpc_sub_dissector *procs;
DISSECTOR_ASSERT(tap_data);
hf_opnum = dcerpc_get_proto_hf_opnum(&tap_data->uuid, tap_data->ver);
procs = dcerpc_get_proto_sub_dissector(&tap_data->uuid, tap_data->ver);
if(hf_opnum != -1){
dcerpc_srt_table = init_srt_table(tap_data->prog, NULL, srt_array, tap_data->num_procedures, NULL, proto_registrar_get_nth(hf_opnum)->abbrev, gui_callback, gui_data, tap_data);
} else {
dcerpc_srt_table = init_srt_table(tap_data->prog, NULL, srt_array, tap_data->num_procedures, NULL, NULL, gui_callback, gui_data, tap_data);
}
for(i=0;i<tap_data->num_procedures;i++){
int j;
const char *proc_name;
proc_name = "unknown";
for(j=0;procs[j].name;j++)
{
if (procs[j].num == i)
{
proc_name = procs[j].name;
}
}
init_srt_table_row(dcerpc_srt_table, i, proc_name);
}
}
static int
dcerpcstat_packet(void *pss, packet_info *pinfo, epan_dissect_t *edt _U_, const void *prv)
{
guint i = 0;
srt_stat_table *dcerpc_srt_table;
srt_data_t *data = (srt_data_t *)pss;
const dcerpc_info *ri = (dcerpc_info *)prv;
dcerpcstat_tap_data_t* tap_data;
dcerpc_srt_table = g_array_index(data->srt_array, srt_stat_table*, i);
tap_data = (dcerpcstat_tap_data_t*)dcerpc_srt_table->table_specific_data;
if(!ri->call_data){
return 0;
}
if(!ri->call_data->req_frame){
return 0;
}
if(ri->call_data->opnum >= tap_data->num_procedures){
return 0;
}
if(ri->ptype != PDU_RESP){
return 0;
}
if( (!uuid_equal( (&ri->call_data->uuid), (&tap_data->uuid)))
||(ri->call_data->ver != tap_data->ver)){
return 0;
}
add_srt_table_data(dcerpc_srt_table, ri->call_data->opnum, &ri->call_data->req_time, pinfo);
return 1;
}
static guint
dcerpcstat_param(register_srt_t* srt, const char* opt_arg, char** err)
{
guint pos = 0;
guint32 i, max_procs;
dcerpcstat_tap_data_t* tap_data;
guint d1,d2,d3,d40,d41,d42,d43,d44,d45,d46,d47;
int major, minor;
guint16 ver;
dcerpc_sub_dissector *procs;
if (sscanf(opt_arg, ",%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x,%d.%d%n",
&d1,&d2,&d3,&d40,&d41,&d42,&d43,&d44,&d45,&d46,&d47,&major,&minor,&pos) == 13)
{
if ((major < 0) || (major > 65535)) {
*err = g_strdup_printf("dcerpcstat_init() Major version number %d is invalid - must be positive and <= 65535", major);
return pos;
}
if ((minor < 0) || (minor > 65535)) {
*err = g_strdup_printf("dcerpcstat_init() Minor version number %d is invalid - must be positive and <= 65535", minor);
return pos;
}
ver = major;
tap_data = g_new0(dcerpcstat_tap_data_t, 1);
tap_data->uuid.data1 = d1;
tap_data->uuid.data2 = d2;
tap_data->uuid.data3 = d3;
tap_data->uuid.data4[0] = d40;
tap_data->uuid.data4[1] = d41;
tap_data->uuid.data4[2] = d42;
tap_data->uuid.data4[3] = d43;
tap_data->uuid.data4[4] = d44;
tap_data->uuid.data4[5] = d45;
tap_data->uuid.data4[6] = d46;
tap_data->uuid.data4[7] = d47;
procs = dcerpc_get_proto_sub_dissector(&tap_data->uuid, ver);
tap_data->prog = dcerpc_get_proto_name(&tap_data->uuid, ver);
tap_data->ver = ver;
for(i=0,max_procs=0;procs[i].name;i++)
{
if(procs[i].num>max_procs)
{
max_procs = procs[i].num;
}
}
tap_data->num_procedures = max_procs+1;
set_srt_table_param_data(srt, tap_data);
}
else
{
*err = g_strdup_printf("<uuid>,<major version>.<minor version>[,<filter>]");
}
return pos;
}
int
dissect_dcerpc_uint8(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, guint8 *drep,
int hfindex, guint8 *pdata)
{
guint8 data;
data = tvb_get_guint8(tvb, offset);
if (tree && hfindex != -1) {
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
if (tree && hfindex != -1) {
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
if (tree && hfindex != -1) {
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
if (tree && hfindex != -1) {
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
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint64 *pdata)
{
guint64 data;
data = ((drep[0] & DREP_LITTLE_ENDIAN)
? tvb_get_letoh64(tvb, offset)
: tvb_get_ntoh64(tvb, offset));
if (tree && hfindex != -1) {
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
DISSECTOR_ASSERT((di->call_data->flags & DCERPC_IS_NDR64) || (data <= G_MAXUINT32));
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
if (tree && hfindex != -1) {
proto_tree_add_float(tree, hfindex, tvb, offset, 4, data);
}
break;
case(DCE_RPC_DREP_FP_VAX):
case(DCE_RPC_DREP_FP_CRAY):
case(DCE_RPC_DREP_FP_IBM):
default:
data = -G_MAXFLOAT;
if (tree && hfindex != -1) {
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
if (tree && hfindex != -1) {
proto_tree_add_double(tree, hfindex, tvb, offset, 8, data);
}
break;
case(DCE_RPC_DREP_FP_VAX):
case(DCE_RPC_DREP_FP_CRAY):
case(DCE_RPC_DREP_FP_IBM):
default:
data = -G_MAXDOUBLE;
if (tree && hfindex != -1) {
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
int hfindex, e_guid_t *pdata)
{
e_guid_t uuid;
if (drep[0] & DREP_LITTLE_ENDIAN) {
tvb_get_letohguid(tvb, offset, (e_guid_t *) &uuid);
} else {
tvb_get_ntohguid(tvb, offset, (e_guid_t *) &uuid);
}
if (tree && hfindex != -1) {
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
dcerpc_tvb_get_uuid(tvbuff_t *tvb, gint offset, guint8 *drep, e_guid_t *uuid)
{
if (drep[0] & DREP_LITTLE_ENDIAN) {
tvb_get_letohguid(tvb, offset, (e_guid_t *) uuid);
} else {
tvb_get_ntohguid(tvb, offset, (e_guid_t *) uuid);
}
}
int
dissect_ndr_ucarray(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
dcerpc_dissect_fnct_t *fnct)
{
guint32 i;
int old_offset;
int conformance_size = 4;
if (di->call_data->flags & DCERPC_IS_NDR64) {
conformance_size = 8;
}
if (di->conformant_run) {
guint64 val;
old_offset = offset;
di->conformant_run = 0;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep,
hf_dcerpc_array_max_count, &val);
di->array_max_count = (gint32)val;
di->array_max_count_offset = offset-conformance_size;
di->conformant_run = 1;
di->conformant_eaten = offset-old_offset;
} else {
proto_tree_add_uint(tree, hf_dcerpc_array_max_count, tvb, di->array_max_count_offset, conformance_size, di->array_max_count);
for (i=0; i<di->array_max_count; i++) {
offset = (*fnct)(tvb, offset, pinfo, tree, di, drep);
}
}
return offset;
}
static int
dissect_ndr_ucvarray_core(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
dcerpc_dissect_fnct_t *fnct_bytes,
dcerpc_dissect_fnct_blk_t *fnct_block)
{
guint32 i;
int old_offset;
int conformance_size = 4;
if (di->call_data->flags & DCERPC_IS_NDR64) {
conformance_size = 8;
}
if (di->conformant_run) {
guint64 val;
old_offset = offset;
di->conformant_run = 0;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep,
hf_dcerpc_array_max_count, &val);
DISSECTOR_ASSERT(val <= G_MAXUINT32);
di->array_max_count = (guint32)val;
di->array_max_count_offset = offset-conformance_size;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep,
hf_dcerpc_array_offset, &val);
DISSECTOR_ASSERT(val <= G_MAXUINT32);
di->array_offset = (guint32)val;
di->array_offset_offset = offset-conformance_size;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep,
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
if (fnct_block) {
offset = (*fnct_block)(tvb, offset, di->array_actual_count, pinfo, tree, drep);
} else {
for (i=0 ;i<di->array_actual_count; i++) {
old_offset = offset;
offset = (*fnct_bytes)(tvb, offset, pinfo, tree, di, drep);
if (offset <= old_offset)
THROW(ReportedBoundsError);
}
}
}
return offset;
}
int
dissect_ndr_ucvarray_block(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
dcerpc_dissect_fnct_blk_t *fnct)
{
return dissect_ndr_ucvarray_core(tvb, offset, pinfo, tree, di, drep, NULL, fnct);
}
int
dissect_ndr_ucvarray(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
dcerpc_dissect_fnct_t *fnct)
{
return dissect_ndr_ucvarray_core(tvb, offset, pinfo, tree, di, drep, fnct, NULL);
}
int
dissect_ndr_uvarray(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
dcerpc_dissect_fnct_t *fnct)
{
guint32 i;
int old_offset;
int conformance_size = 4;
if (di->call_data->flags & DCERPC_IS_NDR64) {
conformance_size = 8;
}
if (di->conformant_run) {
guint64 val;
old_offset = offset;
di->conformant_run = 0;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep,
hf_dcerpc_array_offset, &val);
DISSECTOR_ASSERT(val <= G_MAXUINT32);
di->array_offset = (guint32)val;
di->array_offset_offset = offset-conformance_size;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep,
hf_dcerpc_array_actual_count, &val);
DISSECTOR_ASSERT(val <= G_MAXUINT32);
di->array_actual_count = (guint32)val;
di->array_actual_count_offset = offset-conformance_size;
di->conformant_run = 1;
di->conformant_eaten = offset-old_offset;
} else {
proto_tree_add_uint(tree, hf_dcerpc_array_offset, tvb, di->array_offset_offset, conformance_size, di->array_offset);
proto_tree_add_uint(tree, hf_dcerpc_array_actual_count, tvb, di->array_actual_count_offset, conformance_size, di->array_actual_count);
for (i=0; i<di->array_actual_count; i++) {
offset = (*fnct)(tvb, offset, pinfo, tree, di, drep);
}
}
return offset;
}
int
dissect_ndr_byte_array(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
guint64 len;
if (di->conformant_run) {
return offset;
}
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep,
hf_dcerpc_array_max_count, NULL);
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep,
hf_dcerpc_array_offset, NULL);
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep,
hf_dcerpc_array_actual_count, &len);
DISSECTOR_ASSERT(len <= G_MAXUINT32);
if (len) {
proto_tree_add_item(tree, di->hf_index, tvb, offset, (guint32)len,
ENC_NA);
}
offset += (guint32)len;
return offset;
}
int
dissect_ndr_cvstring(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int size_is,
int hfindex, gboolean add_subtree, char **data)
{
header_field_info *hfinfo;
proto_item *string_item;
proto_tree *string_tree;
guint64 len;
guint32 buffer_len;
char *s;
hfinfo = proto_registrar_get_nth(hfindex);
DISSECTOR_ASSERT(hfinfo->type == FT_STRING);
if (di->conformant_run) {
return offset;
}
if (add_subtree) {
string_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_dcerpc_string, &string_item,
proto_registrar_get_name(hfindex));
} else {
string_item = NULL;
string_tree = tree;
}
offset = dissect_ndr_uint3264(tvb, offset, pinfo, string_tree, di, drep,
hf_dcerpc_array_max_count, NULL);
offset = dissect_ndr_uint3264(tvb, offset, pinfo, string_tree, di, drep,
hf_dcerpc_array_offset, NULL);
offset = dissect_ndr_uint3264(tvb, offset, pinfo, string_tree, di, drep,
hf_dcerpc_array_actual_count, &len);
buffer_len = size_is * (guint32)len;
if (!di->no_align && (offset % size_is))
offset += size_is - (offset % size_is);
tvb_ensure_bytes_exist(tvb, offset, buffer_len);
if (size_is == sizeof(guint16)) {
s = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, buffer_len,
ENC_UTF_16|ENC_LITTLE_ENDIAN);
} else {
s = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, buffer_len,
DREP_ENC_CHAR(drep));
}
if (tree && buffer_len)
proto_tree_add_string(string_tree, hfindex, tvb, offset,
buffer_len, s);
if (string_item != NULL)
proto_item_append_text(string_item, ": %s", s);
if (data)
*data = s;
offset += buffer_len;
proto_item_set_end(string_item, tvb, offset);
return offset;
}
int
dissect_ndr_cstring(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int size_is,
int hfindex, gboolean add_subtree, char **data)
{
return dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, size_is, hfindex, add_subtree, data);
}
int
dissect_ndr_char_cvstring(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
return dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep,
sizeof(guint8), di->hf_index,
FALSE, NULL);
}
int
dissect_ndr_wchar_cvstring(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
return dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep,
sizeof(guint16), di->hf_index,
FALSE, NULL);
}
int
PIDL_dissect_cvstring(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep, int chsize, int hfindex, guint32 param)
{
char *s = NULL;
gint levels = CB_STR_ITEM_LEVELS(param);
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep,
chsize, hfindex,
FALSE, &s);
if (!di->conformant_run) {
if (param & PIDL_SET_COL_INFO) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", s);
}
if ((param & PIDL_STR_SAVE)
&& (!pinfo->fd->flags.visited)) {
dcerpc_call_value *dcv = (dcerpc_call_value *)di->call_data;
dcv->private_data = wmem_strdup(wmem_file_scope(), s);
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
proto_tree *tree, dcerpc_info *di, guint8 *drep, int size_is,
int hfindex, gboolean add_subtree, char **data)
{
header_field_info *hfinfo;
proto_item *string_item;
proto_tree *string_tree;
guint64 len;
guint32 buffer_len;
char *s;
hfinfo = proto_registrar_get_nth(hfindex);
DISSECTOR_ASSERT(hfinfo->type == FT_STRING);
if (di->conformant_run) {
return offset;
}
if (add_subtree) {
string_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_dcerpc_string, &string_item,
proto_registrar_get_name(hfindex));
} else {
string_item = NULL;
string_tree = tree;
}
offset = dissect_ndr_uint3264(tvb, offset, pinfo, string_tree, di, drep,
hf_dcerpc_array_offset, NULL);
offset = dissect_ndr_uint3264(tvb, offset, pinfo, string_tree, di, drep,
hf_dcerpc_array_actual_count, &len);
DISSECTOR_ASSERT(len <= G_MAXUINT32);
buffer_len = size_is * (guint32)len;
if (!di->no_align && (offset % size_is))
offset += size_is - (offset % size_is);
tvb_ensure_bytes_exist(tvb, offset, buffer_len);
if (size_is == sizeof(guint16)) {
s = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, buffer_len,
ENC_UTF_16|ENC_LITTLE_ENDIAN);
} else {
s = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, buffer_len,
DREP_ENC_CHAR(drep));
}
if (tree && buffer_len)
proto_tree_add_string(string_tree, hfindex, tvb, offset,
buffer_len, s);
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
proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
return dissect_ndr_vstring(tvb, offset, pinfo, tree, di, drep,
sizeof(guint8), di->hf_index,
FALSE, NULL);
}
int
dissect_ndr_wchar_vstring(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
return dissect_ndr_vstring(tvb, offset, pinfo, tree, di, drep,
sizeof(guint16), di->hf_index,
FALSE, NULL);
}
void
init_ndr_pointer_list(dcerpc_info *di)
{
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
dissect_deferred_pointers(packet_info *pinfo, tvbuff_t *tvb, int offset, dcerpc_info *di, guint8 *drep)
{
int found_new_pointer;
int old_offset;
int next_pointer;
next_pointer = 0;
do{
int i, len;
found_new_pointer = 0;
len = g_slist_length(ndr_pointer_list);
for (i=next_pointer; i<len; i++) {
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
offset = (*(fnct))(tvb, offset, pinfo, NULL, di, drep);
DISSECTOR_ASSERT((offset-old_offset) == di->conformant_eaten);
di->conformant_run = 0;
old_offset = offset;
offset = (*(fnct))(tvb, offset, pinfo, tnpd->tree, di, drep);
if (tnpd->callback)
tnpd->callback(pinfo, tnpd->tree, tnpd->item, di, tvb, old_offset, offset, tnpd->callback_args);
proto_item_set_len(tnpd->item, offset - old_offset);
break;
}
}
} while (found_new_pointer);
return offset;
}
static void
add_pointer_to_list(packet_info *pinfo, proto_tree *tree, proto_item *item,
dcerpc_info *di, dcerpc_dissect_fnct_t *fnct, guint32 id, int hf_index,
dcerpc_callback_fnct_t *callback, void *callback_args)
{
ndr_pointer_data_t *npd;
if (id != 0xffffffff) {
dcerpc_call_value *value;
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
for (i=0; i<len; i++) {
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
proto_tree *tree, dcerpc_info *di, guint8 *drep, dcerpc_dissect_fnct_t *fnct,
int type, const char *text, int hf_index,
dcerpc_callback_fnct_t *callback, void *callback_args)
{
proto_tree *tr = NULL;
gint start_offset = offset;
int pointer_size = 4;
if (di->conformant_run) {
return offset;
}
if (di->call_data->flags & DCERPC_IS_NDR64) {
pointer_size = 8;
}
if ( pointers_are_top_level
&& (type == NDR_POINTER_REF) ) {
proto_item *item;
tr = proto_tree_add_subtree(tree, tvb, offset, 0,
ett_dcerpc_pointer_data, &item, text);
add_pointer_to_list(pinfo, tr, item, di, fnct, 0xffffffff,
hf_index, callback, callback_args);
goto after_ref_id;
}
if ( pointers_are_top_level
&& (type == NDR_POINTER_PTR) ) {
int idx;
guint64 id;
proto_item *item;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, NULL, di, drep, -1, &id);
if (id == 0) {
proto_tree_add_bytes_format_value(tree, hf_dcerpc_null_pointer, tvb, offset-pointer_size,
pointer_size, NULL, "%s", text);
goto after_ref_id;
}
idx = find_pointer_index((guint32)id);
if (idx >= 0) {
proto_tree_add_string(tree, hf_dcerpc_duplicate_ptr, tvb, offset-pointer_size, pointer_size, text);
goto after_ref_id;
}
tr = proto_tree_add_subtree(tree, tvb, offset-pointer_size,
pointer_size, ett_dcerpc_pointer_data, &item, text);
if (di->call_data->flags & DCERPC_IS_NDR64) {
proto_tree_add_uint64(tr, hf_dcerpc_referent_id64, tvb,
offset-pointer_size, pointer_size, id);
} else {
proto_tree_add_uint(tr, hf_dcerpc_referent_id32, tvb,
offset-pointer_size, pointer_size, (guint32)id);
}
add_pointer_to_list(pinfo, tr, item, di, fnct, (guint32)id, hf_index,
callback, callback_args);
goto after_ref_id;
}
if ( pointers_are_top_level
&& (type == NDR_POINTER_UNIQUE) ) {
guint64 id;
proto_item *item;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, NULL, di, drep, -1, &id);
if (id == 0) {
proto_tree_add_bytes_format_value(tree, hf_dcerpc_null_pointer, tvb, offset-pointer_size,
pointer_size, NULL, "%s",text);
goto after_ref_id;
}
tr = proto_tree_add_subtree(tree, tvb, offset-pointer_size,
pointer_size,
ett_dcerpc_pointer_data, &item, text);
if (di->call_data->flags & DCERPC_IS_NDR64) {
proto_tree_add_uint64(tr, hf_dcerpc_referent_id64, tvb,
offset-pointer_size, pointer_size, id);
} else {
proto_tree_add_uint(tr, hf_dcerpc_referent_id32, tvb,
offset-pointer_size, pointer_size, (guint32)id);
}
add_pointer_to_list(pinfo, tr, item, di, fnct, 0xffffffff,
hf_index, callback, callback_args);
goto after_ref_id;
}
if ( (!pointers_are_top_level)
&& (type == NDR_POINTER_REF) ) {
guint64 id;
proto_item *item;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, NULL, di, drep, -1, &id);
tr = proto_tree_add_subtree(tree, tvb, offset-pointer_size,
pointer_size,
ett_dcerpc_pointer_data,&item,text);
if (di->call_data->flags & DCERPC_IS_NDR64) {
proto_tree_add_uint64(tr, hf_dcerpc_referent_id64, tvb,
offset-pointer_size, pointer_size, id);
} else {
proto_tree_add_uint(tr, hf_dcerpc_referent_id32, tvb,
offset-pointer_size, pointer_size, (guint32)id);
}
add_pointer_to_list(pinfo, tr, item, di, fnct, 0xffffffff,
hf_index, callback, callback_args);
goto after_ref_id;
}
if ( (!pointers_are_top_level)
&& (type == NDR_POINTER_UNIQUE) ) {
guint64 id;
proto_item *item;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, NULL, di, drep, -1, &id);
if (id == 0) {
proto_tree_add_bytes_format_value(tree, hf_dcerpc_null_pointer, tvb, offset-pointer_size,
pointer_size, NULL, "%s",text);
goto after_ref_id;
}
tr = proto_tree_add_subtree(tree, tvb, offset-pointer_size,
pointer_size,
ett_dcerpc_pointer_data,&item,text);
if (di->call_data->flags & DCERPC_IS_NDR64) {
proto_tree_add_uint64(tr, hf_dcerpc_referent_id64, tvb,
offset-pointer_size, pointer_size, id);
} else {
proto_tree_add_uint(tr, hf_dcerpc_referent_id32, tvb,
offset-pointer_size, pointer_size, (guint32)id);
}
add_pointer_to_list(pinfo, tr, item, di, fnct, 0xffffffff,
hf_index, callback, callback_args);
goto after_ref_id;
}
if ( (!pointers_are_top_level)
&& (type == NDR_POINTER_PTR) ) {
int idx;
guint64 id;
proto_item *item;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, NULL, di, drep, -1, &id);
if (id == 0) {
proto_tree_add_bytes_format_value(tree, hf_dcerpc_null_pointer, tvb, offset-pointer_size,
pointer_size, NULL, "%s",text);
goto after_ref_id;
}
idx = find_pointer_index((guint32)id);
if (idx >= 0) {
proto_tree_add_string(tree, hf_dcerpc_duplicate_ptr, tvb, offset-pointer_size, pointer_size, text);
goto after_ref_id;
}
tr = proto_tree_add_subtree(tree, tvb, offset-pointer_size,
pointer_size,
ett_dcerpc_pointer_data, &item, text);
if (di->call_data->flags & DCERPC_IS_NDR64) {
proto_tree_add_uint64(tr, hf_dcerpc_referent_id64, tvb,
offset-pointer_size, pointer_size, id);
} else {
proto_tree_add_uint(tr, hf_dcerpc_referent_id32, tvb,
offset-pointer_size, pointer_size, (guint32)id);
}
add_pointer_to_list(pinfo, tr, item, di, fnct, (guint32)id, hf_index,
callback, callback_args);
goto after_ref_id;
}
after_ref_id:
if (pointers_are_top_level == TRUE) {
pointers_are_top_level = FALSE;
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
pointers_are_top_level = TRUE;
}
if (tr) {
proto_item_set_len(tr, offset-start_offset);
}
return offset;
}
int
dissect_ndr_pointer(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, dcerpc_dissect_fnct_t *fnct,
int type, const char *text, int hf_index)
{
return dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, di, drep, fnct, type, text, hf_index,
NULL, NULL);
}
int
dissect_ndr_toplevel_pointer(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, dcerpc_dissect_fnct_t *fnct,
int type, const char *text, int hf_index)
{
int ret;
pointers_are_top_level = TRUE;
ret = dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, di, drep, fnct, type, text, hf_index,
NULL, NULL);
return ret;
}
int
dissect_ndr_embedded_pointer(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, dcerpc_dissect_fnct_t *fnct,
int type, const char *text, int hf_index)
{
int ret;
pointers_are_top_level = FALSE;
ret = dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, di, drep, fnct, type, text, hf_index,
NULL, NULL);
return ret;
}
static void
show_stub_data(tvbuff_t *tvb, gint offset, proto_tree *dcerpc_tree,
dcerpc_auth_info *auth_info, gboolean is_encrypted)
{
int length, plain_length, auth_pad_len;
guint auth_pad_offset;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
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
proto_tree_add_item(dcerpc_tree, hf_dcerpc_encrypted_stub_data, tvb, offset, length, ENC_NA);
auth_pad_len = 0;
} else {
proto_tree_add_item(dcerpc_tree, hf_dcerpc_decrypted_stub_data, tvb, offset, plain_length, ENC_NA);
}
} else {
proto_tree_add_item(dcerpc_tree, hf_dcerpc_stub_data, tvb, offset, plain_length, ENC_NA);
}
if (auth_pad_len != 0) {
proto_tree_add_item(dcerpc_tree, hf_dcerpc_auth_padding, tvb, auth_pad_offset, auth_pad_len, ENC_NA);
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
guids_resolve_guid_to_str(&info->call_data->uuid), info->call_data->ver);
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
proto_tree_add_uint_format_value(sub_tree, hf_dcerpc_op, tvb,
0, 0, info->call_data->opnum,
"%s (%u)",
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
pinfo->current_proto = sub_proto->name;
init_ndr_pointer_list(info);
length = tvb_captured_length(decrypted_tvb);
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
info, drep);
remaining = tvb_reported_length_remaining(stub_tvb, offset);
if (remaining > 0) {
proto_tree_add_expert(sub_tree, pinfo, &ei_dcerpc_long_frame, stub_tvb, offset, remaining);
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
proto_tree_add_item(dcerpc_tree, hf_dcerpc_auth_padding, decrypted_tvb, auth_pad_offset, auth_pad_len, ENC_NA);
}
pinfo->current_proto = saved_proto;
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
proto_tree_add_item(dcerpc_tree, hf_dcerpc_auth_verifier, auth_tvb, 0, hdr->auth_len, ENC_NA);
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
MIN(hdr->auth_len,tvb_reported_length_remaining(tvb, offset)),
hdr->auth_len);
if ((auth_fns = get_auth_subdissector_fns(auth_info->auth_level,
auth_info->auth_type)))
dissect_auth_verf(auth_tvb, pinfo, dcerpc_tree, auth_fns,
hdr, auth_info);
else
proto_tree_add_item(dcerpc_tree, hf_dcerpc_auth_credentials, tvb, offset, hdr->auth_len, ENC_NA);
}
auth_info->auth_size = hdr->auth_len + 8;
} CATCH_BOUNDS_ERRORS {
show_exception(tvb, pinfo, dcerpc_tree, EXCEPT_CODE, GET_MESSAGE);
} ENDTRY;
}
}
}
guint64
dcerpc_get_transport_salt(packet_info *pinfo)
{
dcerpc_decode_as_data* decode_data = dcerpc_get_decode_data(pinfo);
switch (decode_data->dcetransporttype) {
case DCE_CN_TRANSPORT_SMBPIPE:
return decode_data->dcetransportsalt;
}
return 0;
}
void
dcerpc_set_transport_salt(guint64 dcetransportsalt, packet_info *pinfo)
{
dcerpc_decode_as_data* decode_data = dcerpc_get_decode_data(pinfo);
decode_data->dcetransportsalt = dcetransportsalt;
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
e_guid_t if_id;
e_guid_t trans_id;
guint32 trans_ver;
guint16 if_ver, if_ver_minor;
dcerpc_auth_info auth_info;
char *uuid_str;
const char *uuid_name = NULL;
proto_item *iface_item = NULL;
dcerpc_decode_as_data* decode_data = dcerpc_get_decode_data(pinfo);
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
decode_data->dcectxid = ctx_id;
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
uuid_str = guid_to_str(wmem_packet_scope(), (e_guid_t*)&if_id);
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
proto_item *uuid_item = NULL;
dcerpc_tvb_get_uuid(tvb, offset, hdr->drep, &trans_id);
if (ctx_tree) {
trans_item = proto_tree_add_item(ctx_tree, hf_dcerpc_cn_bind_trans_syntax, tvb, offset, 0, ENC_NA);
trans_tree = proto_item_add_subtree(trans_item, ett_dcerpc_cn_trans_syntax);
uuid_str = guid_to_str(wmem_packet_scope(), (e_guid_t *) &trans_id);
uuid_name = guids_get_uuid_name(&trans_id);
if (uuid_name) {
uuid_item = proto_tree_add_guid_format(trans_tree, hf_dcerpc_cn_bind_trans_id, tvb, offset, 16, (e_guid_t *) &trans_id, "Transfer Syntax: %s UUID:%s", uuid_name, uuid_str);
proto_item_append_text(trans_item, "[%u]: %s", j+1, uuid_name);
proto_item_append_text(ctx_item, ", %s", uuid_name);
} else {
uuid_item = proto_tree_add_guid_format(trans_tree, hf_dcerpc_cn_bind_trans_id, tvb, offset, 16, (e_guid_t *) &trans_id, "Transfer Syntax: %s", uuid_str);
proto_item_append_text(trans_item, "[%u]: %s", j+1, uuid_str);
proto_item_append_text(ctx_item, ", %s", uuid_str);
}
if (trans_id.data1 == 0x6cb71c2c && trans_id.data2 == 0x9812 && trans_id.data3 == 0x4540) {
proto_tree *uuid_tree = proto_item_add_subtree(uuid_item, ett_dcerpc_cn_trans_btfn);
proto_tree_add_boolean(uuid_tree, hf_dcerpc_cn_bind_trans_btfn_01, tvb, offset+8, 1, trans_id.data4[0]);
proto_tree_add_boolean(uuid_tree, hf_dcerpc_cn_bind_trans_btfn_02, tvb, offset+8, 1, trans_id.data4[0]);
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
key = (dcerpc_bind_key *)wmem_alloc(wmem_file_scope(), sizeof (dcerpc_bind_key));
key->conv = conv;
key->ctx_id = ctx_id;
key->transport_salt = dcerpc_get_transport_salt(pinfo);
value = (dcerpc_bind_value *)wmem_alloc(wmem_file_scope(), sizeof (dcerpc_bind_value));
value->uuid = if_id;
value->ver = if_ver;
value->transport = trans_id;
g_hash_table_insert(dcerpc_binds, key, value);
}
if (i > 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ",");
col_append_fstr(pinfo->cinfo, COL_INFO, " %s V%u.%u (%s)",
guids_resolve_guid_to_str(&if_id), if_ver, if_ver_minor,
guids_resolve_guid_to_str(&trans_id));
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
e_guid_t trans_id;
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
ctx_tree = proto_tree_add_subtree_format(dcerpc_tree, tvb, offset, 24, ett_dcerpc_cn_ctx, &ctx_item, "Ctx Item[%u]:", i+1);
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ctx_tree,
hdr->drep, hf_dcerpc_cn_ack_result,
&result);
if (result == 3) {
const int old_offset = offset;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ctx_tree, hdr->drep, hf_dcerpc_cn_ack_btfn, &reason);
proto_tree_add_boolean(ctx_tree, hf_dcerpc_cn_bind_trans_btfn_01, tvb, old_offset, 1, reason);
proto_tree_add_boolean(ctx_tree, hf_dcerpc_cn_bind_trans_btfn_02, tvb, old_offset, 1, reason);
} else if (result != 0) {
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
uuid_name = guid_to_str(wmem_packet_scope(), (e_guid_t *) &trans_id);
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
fragment_head *fd_head = NULL;
tvbuff_t *auth_tvb, *payload_tvb, *decrypted_tvb;
proto_item *pi;
proto_item *parent_pi;
proto_item *dcerpc_tree_item;
save_fragmented = pinfo->fragmented;
length = tvb_reported_length_remaining(tvb, offset);
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
if (tvb_captured_length(tvb) == tvb_reported_length(tvb)) {
if (tvb_reported_length_remaining(tvb, offset+length) > 8) {
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
proto_tree_add_item(dcerpc_tree, hf_dcerpc_encrypted_stub_data, payload_tvb, 0, -1, ENC_NA);
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
expert_add_info_format(pinfo, NULL, &ei_dcerpc_fragment, "%s fragment", fragment_type(hdr->flags));
pinfo->fragmented = save_fragmented;
return;
}
if (pinfo->fd->flags.visited) {
fd_head = fragment_get_reassembled(&dcerpc_co_reassembly_table, frame);
goto end_cn_stub;
}
if ( !dcerpc_reassemble || (tvb_captured_length(tvb) != tvb_reported_length(tvb)) )
goto end_cn_stub;
if (!frame)
goto end_cn_stub;
if (decrypted_tvb == NULL) {
goto end_cn_stub;
}
fd_head = fragment_add_seq_next(&dcerpc_co_reassembly_table,
decrypted_tvb, 0, pinfo, frame, NULL,
tvb_reported_length(decrypted_tvb),
hdr->flags&PFC_LAST_FRAG ? FALSE : TRUE );
end_cn_stub:
if (fd_head && (fd_head->flags & FD_DEFRAGMENTED) ) {
if ((pinfo->fd->num == fd_head->reassembled_in) && (hdr->flags & PFC_LAST_FRAG) ) {
tvbuff_t *next_tvb;
proto_item *frag_tree_item;
next_tvb = tvb_new_chain((decrypted_tvb)?decrypted_tvb:payload_tvb,
fd_head->tvb_data);
add_new_data_source(pinfo, next_tvb, "Reassembled DCE/RPC");
show_fragment_tree(fd_head, &dcerpc_frag_items,
tree, pinfo, next_tvb, &frag_tree_item);
dcerpc_tree_item = proto_tree_get_parent(dcerpc_tree);
if (frag_tree_item && dcerpc_tree_item) {
proto_tree_move_item(tree, dcerpc_tree_item, frag_tree_item);
}
pinfo->fragmented = FALSE;
expert_add_info_format(pinfo, frag_tree_item, &ei_dcerpc_fragment_reassembled, "%s fragment, reassembled", fragment_type(hdr->flags));
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
expert_add_info_format(pinfo, NULL, &ei_dcerpc_fragment_reassembled, "%s fragment, reassembled in #%u", fragment_type(hdr->flags), fd_head->reassembled_in);
}
} else {
expert_add_info_format(pinfo, NULL, &ei_dcerpc_fragment, "%s fragment", fragment_type(hdr->flags));
if (decrypted_tvb) {
show_stub_data(decrypted_tvb, 0, tree, auth_info, FALSE);
} else {
show_stub_data(payload_tvb, 0, tree, auth_info, TRUE);
}
}
pinfo->fragmented = save_fragmented;
}
static void
dissect_dcerpc_cn_rqst(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *dcerpc_tree, proto_tree *tree,
e_dce_cn_common_hdr_t *hdr)
{
conversation_t *conv;
guint16 ctx_id;
guint16 opnum;
e_guid_t obj_id = DCERPC_UUID_NULL;
dcerpc_auth_info auth_info;
guint32 alloc_hint;
proto_item *pi;
proto_item *parent_pi;
dcerpc_decode_as_data* decode_data = dcerpc_get_decode_data(pinfo);
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
decode_data->dcectxid = ctx_id;
col_append_fstr(pinfo->cinfo, COL_INFO, ", opnum: %u, Ctx: %u",
opnum, ctx_id);
if (hdr->flags & PFC_OBJECT_UUID) {
dcerpc_tvb_get_uuid(tvb, offset, hdr->drep, &obj_id);
if (dcerpc_tree) {
proto_tree_add_guid_format(dcerpc_tree, hf_dcerpc_obj_id, tvb,
offset, 16, (e_guid_t *) &obj_id, "Object UUID: %s",
guid_to_str(wmem_packet_scope(), (e_guid_t *) &obj_id));
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
bind_key.transport_salt = dcerpc_get_transport_salt(pinfo);
if ((bind_value = (dcerpc_bind_value *)g_hash_table_lookup(dcerpc_binds, &bind_key)) ) {
if (!(hdr->flags&PFC_FIRST_FRAG)) {
dcerpc_cn_call_key call_key;
dcerpc_call_value *call_value;
call_key.conv = conv;
call_key.call_id = hdr->call_id;
call_key.transport_salt = dcerpc_get_transport_salt(pinfo);
if ((call_value = (dcerpc_call_value *)g_hash_table_lookup(dcerpc_cn_calls, &call_key))) {
new_matched_key = (dcerpc_matched_key *)wmem_alloc(wmem_file_scope(), sizeof (dcerpc_matched_key));
*new_matched_key = matched_key;
g_hash_table_insert(dcerpc_matched, new_matched_key, call_value);
value = call_value;
}
} else {
dcerpc_cn_call_key *call_key;
dcerpc_call_value *call_value;
call_key = (dcerpc_cn_call_key *)wmem_alloc(wmem_file_scope(), sizeof (dcerpc_cn_call_key));
call_key->conv = conv;
call_key->call_id = hdr->call_id;
call_key->transport_salt = dcerpc_get_transport_salt(pinfo);
if (g_hash_table_lookup(dcerpc_cn_calls, call_key)) {
g_hash_table_remove(dcerpc_cn_calls, call_key);
}
call_value = (dcerpc_call_value *)wmem_alloc(wmem_file_scope(), sizeof (dcerpc_call_value));
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
new_matched_key = (dcerpc_matched_key *)wmem_alloc(wmem_file_scope(), sizeof (dcerpc_matched_key));
*new_matched_key = matched_key;
g_hash_table_insert(dcerpc_matched, new_matched_key, call_value);
value = call_value;
}
}
}
if (value) {
dcerpc_info *di;
di = wmem_new0(wmem_packet_scope(), dcerpc_info);
di->dcerpc_procedure_name = "";
di->conv = conv;
di->call_id = hdr->call_id;
di->transport_salt = dcerpc_get_transport_salt(pinfo);
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
proto_tree_add_expert_format(dcerpc_tree, pinfo, &ei_dcerpc_cn_ctx_id_no_bind, tvb, offset, 0, "No bind info for interface Context ID %u - capture start too late?", ctx_id);
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
e_guid_t obj_id_null = DCERPC_UUID_NULL;
dcerpc_decode_as_data* decode_data = dcerpc_get_decode_data(pinfo);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_alloc_hint, &alloc_hint);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_ctx_id, &ctx_id);
parent_pi = proto_tree_get_parent(dcerpc_tree);
if (parent_pi != NULL) {
proto_item_append_text(parent_pi, ", Ctx: %u", ctx_id);
}
decode_data->dcectxid = ctx_id;
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
call_key.transport_salt = dcerpc_get_transport_salt(pinfo);
if ((call_value = (dcerpc_call_value *)g_hash_table_lookup(dcerpc_cn_calls, &call_key))) {
if (call_value->req_frame<pinfo->fd->num) {
new_matched_key = (dcerpc_matched_key *)wmem_alloc(wmem_file_scope(), sizeof (dcerpc_matched_key));
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
di = wmem_new0(wmem_packet_scope(), dcerpc_info);
di->dcerpc_procedure_name = "";
di->conv = conv;
di->call_id = hdr->call_id;
di->transport_salt = dcerpc_get_transport_salt(pinfo);
di->ptype = PDU_RESP;
di->call_data = value;
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_opnum, tvb, 0, 0, value->opnum);
if (dcerpc_tree && (memcmp(&value->object_uuid, &obj_id_null, sizeof(obj_id_null)) != 0)) {
pi = proto_tree_add_guid_format(dcerpc_tree, hf_dcerpc_obj_id, tvb,
offset, 0, (e_guid_t *) &value->object_uuid, "Object UUID: %s",
guid_to_str(wmem_packet_scope(), (e_guid_t *) &value->object_uuid));
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
proto_tree_add_expert(dcerpc_tree, pinfo, &ei_dcerpc_no_request_found, tvb, 0, 0);
}
dissect_dcerpc_cn_stub(tvb, offset, pinfo, dcerpc_tree, tree,
hdr, di, &auth_info, alloc_hint,
value->rep_frame);
} else {
proto_tree_add_expert_format(dcerpc_tree, pinfo, &ei_dcerpc_cn_ctx_id_no_bind, tvb, offset, 0, "No bind info for interface Context ID %u - capture start too late?", ctx_id);
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
dcerpc_decode_as_data* decode_data = dcerpc_get_decode_data(pinfo);
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
pi = proto_tree_add_item(dcerpc_tree, hf_dcerpc_cn_status, tvb, offset, 4, DREP_ENC_INTEGER(hdr->drep));
offset+=4;
expert_add_info_format(pinfo, pi, &ei_dcerpc_cn_status, "Fault: %s", val_to_str(status, reject_status_vals, "Unknown (0x%08x)"));
decode_data->dcectxid = ctx_id;
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
call_key.transport_salt = dcerpc_get_transport_salt(pinfo);
if ((call_value = (dcerpc_call_value *)g_hash_table_lookup(dcerpc_cn_calls, &call_key))) {
new_matched_key = (dcerpc_matched_key *)wmem_alloc(wmem_file_scope(), sizeof (dcerpc_matched_key));
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
di = wmem_new0(wmem_packet_scope(), dcerpc_info);
di->dcerpc_procedure_name = "";
di->conv = conv;
di->call_id = hdr->call_id;
di->transport_salt = dcerpc_get_transport_salt(pinfo);
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
proto_tree_add_expert(dcerpc_tree, pinfo, &ei_dcerpc_no_request_found, tvb, 0, 0);
}
length = tvb_reported_length_remaining(tvb, offset);
stub_length = length;
if (length > stub_length)
length = stub_length;
if ( (!dcerpc_reassemble) || PFC_NOT_FRAGMENTED(hdr) ||
!tvb_bytes_exist(tvb, offset, stub_length) ) {
if (hdr->flags&PFC_FIRST_FRAG) {
if (stub_length > 0) {
proto_tree_add_item(dcerpc_tree, hf_dcerpc_fault_stub_data, tvb, offset, stub_length, ENC_NA);
}
} else {
if (stub_length > 0) {
proto_tree_add_item(dcerpc_tree, hf_dcerpc_fragment_data, tvb, offset, stub_length, ENC_NA);
}
}
} else {
if (dcerpc_tree) {
if (length > 0) {
proto_tree_add_item(dcerpc_tree, hf_dcerpc_fragment_data, tvb, offset, stub_length, ENC_NA);
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
fragment_head *fd_head;
fd_head = fragment_add_seq_next(&dcerpc_co_reassembly_table,
tvb, offset,
pinfo, value->rep_frame, NULL,
stub_length,
TRUE);
if (fd_head) {
tvbuff_t *next_tvb;
proto_item *frag_tree_item;
next_tvb = tvb_new_chain(tvb, fd_head->tvb_data);
add_new_data_source(pinfo, next_tvb, "Reassembled DCE/RPC");
show_fragment_tree(fd_head, &dcerpc_frag_items,
dcerpc_tree, pinfo, next_tvb, &frag_tree_item);
if (dcerpc_tree) {
if (length > 0) {
proto_tree_add_item(dcerpc_tree, hf_dcerpc_stub_data, tvb, offset, stub_length, ENC_NA);
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
static const int * flags[] = {
&hf_dcerpc_cn_rts_flags_none,
&hf_dcerpc_cn_rts_flags_ping,
&hf_dcerpc_cn_rts_flags_other_cmd,
&hf_dcerpc_cn_rts_flags_recycle_channel,
&hf_dcerpc_cn_rts_flags_in_channel,
&hf_dcerpc_cn_rts_flags_out_channel,
&hf_dcerpc_cn_rts_flags_eof,
NULL
};
rts_flags = dcerpc_tvb_get_ntohs(tvb, offset, hdr->drep);
proto_tree_add_bitmask_value_with_flags(dcerpc_tree, tvb, offset, hf_dcerpc_cn_rts_flags,
ett_dcerpc_cn_rts_flags, flags, rts_flags, BMT_NO_APPEND);
offset += 2;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, dcerpc_tree, hdr->drep,
hf_dcerpc_cn_rts_commands_nb, &commands_nb);
cn_rts_pdu_tree = proto_tree_add_subtree_format(dcerpc_tree, tvb, offset, -1, ett_dcerpc_cn_rts_pdu, &tf, "RTS PDU: %u commands", commands_nb);
cmd = (guint32 *)wmem_alloc(wmem_packet_scope(), sizeof (guint32) * (commands_nb + 1));
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
padding = (guint8 *)tvb_memdup(NULL, tvb, offset, conformance_count);
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
proto_tree_add_ipv4_format_value(cn_rts_command_tree, hf_dcerpc_cmd_client_ipv4, tvb, offset, 4, addr4, "%s", get_hostname(addr4));
offset += 4;
} break;
case RTS_IPV6: {
struct e_in6_addr addr6;
tvb_get_ipv6(tvb, offset, &addr6);
proto_tree_add_ipv6_format_value(cn_rts_command_tree, hf_dcerpc_cmd_client_ipv6, tvb, offset, 16, &addr6, "%s", get_hostname6(&addr6));
offset += 16;
} break;
}
padding = (guint8 *)tvb_memdup(NULL, tvb, offset, 12);
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
expert_add_info(pinfo, tf, &ei_dcerpc_cn_rts_command);
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
break;
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
break;
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
break;
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
is_dcerpc(tvbuff_t *tvb, int offset, packet_info *pinfo _U_)
{
guint8 rpc_ver;
guint8 rpc_ver_minor;
guint8 ptype;
if (!tvb_bytes_exist(tvb, offset, sizeof(e_dce_cn_common_hdr_t)))
return FALSE;
rpc_ver = tvb_get_guint8(tvb, offset++);
if (rpc_ver != 5)
return FALSE;
rpc_ver_minor = tvb_get_guint8(tvb, offset++);
if ((rpc_ver_minor != 0) && (rpc_ver_minor != 1))
return FALSE;
ptype = tvb_get_guint8(tvb, offset++);
if (ptype > PDU_RTS)
return FALSE;
return TRUE;
}
static gboolean
dissect_dcerpc_cn(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, gboolean can_desegment, int *pkt_len)
{
static const guint8 nulls[4] = { 0 };
int start_offset;
int padding = 0;
int subtvb_len = 0;
proto_item *ti = NULL;
proto_item *tf = NULL;
proto_tree *dcerpc_tree = NULL;
proto_tree *drep_tree = NULL;
e_dce_cn_common_hdr_t hdr;
dcerpc_auth_info auth_info;
tvbuff_t *fragment_tvb;
dcerpc_decode_as_data* decode_data = dcerpc_get_decode_data(pinfo);
static const int * hdr_flags[] = {
&hf_dcerpc_cn_flags_object,
&hf_dcerpc_cn_flags_maybe,
&hf_dcerpc_cn_flags_dne,
&hf_dcerpc_cn_flags_mpx,
&hf_dcerpc_cn_flags_reserved,
&hf_dcerpc_cn_flags_cancel_pending,
&hf_dcerpc_cn_flags_last_frag,
&hf_dcerpc_cn_flags_first_frag,
NULL
};
if (tvb_memeql(tvb, offset, nulls, 4) == 0) {
offset += 4;
padding += 4;
}
if (!is_dcerpc(tvb, offset, pinfo))
return FALSE;
start_offset = offset;
hdr.rpc_ver = tvb_get_guint8(tvb, offset++);
hdr.rpc_ver_minor = tvb_get_guint8(tvb, offset++);
hdr.ptype = tvb_get_guint8(tvb, offset++);
hdr.flags = tvb_get_guint8(tvb, offset++);
tvb_memcpy(tvb, (guint8 *)hdr.drep, offset, sizeof (hdr.drep));
offset += (int)sizeof (hdr.drep);
hdr.frag_len = dcerpc_tvb_get_ntohs(tvb, offset, hdr.drep);
offset += 2;
hdr.auth_len = dcerpc_tvb_get_ntohs(tvb, offset, hdr.drep);
offset += 2;
hdr.call_id = dcerpc_tvb_get_ntohl(tvb, offset, hdr.drep);
if (decode_data->dcectxid == 0) {
col_append_fstr(pinfo->cinfo, COL_DCE_CALL, "%u", hdr.call_id);
} else {
col_append_fstr(pinfo->cinfo, COL_DCE_CALL, "#%u", hdr.call_id);
}
if (can_desegment && pinfo->can_desegment
&& !tvb_bytes_exist(tvb, start_offset, hdr.frag_len)) {
pinfo->desegment_offset = start_offset;
pinfo->desegment_len = hdr.frag_len - tvb_reported_length_remaining(tvb, start_offset);
*pkt_len = 0;
return TRUE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DCERPC");
if (decode_data->dcectxid != 0) {
col_append_str(pinfo->cinfo, COL_INFO, " # ");
col_set_fence(pinfo->cinfo,COL_INFO);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: call_id: %u",
pckt_vals[hdr.ptype].strptr, hdr.call_id);
if (decode_data->dcectxid != 0) {
expert_add_info(pinfo, NULL, &ei_dcerpc_fragment_multiple);
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
expert_add_info_format(pinfo, tf, &ei_dcerpc_context_change, "Context change: %s", val_to_str(hdr.ptype, pckt_vals, "(0x%x)"));
#endif
if (hdr.ptype == PDU_BIND_NAK)
expert_add_info(pinfo, tf, &ei_dcerpc_bind_not_acknowledged);
if (tree) {
proto_item_append_text(ti, " %s, Fragment: %s",
val_to_str(hdr.ptype, pckt_vals, "Unknown (0x%02x)"),
fragment_type(hdr.flags));
}
proto_tree_add_bitmask_value_with_flags(dcerpc_tree, tvb, offset, hf_dcerpc_cn_flags,
ett_dcerpc_cn_flags, hdr_flags, hdr.flags, BMT_NO_APPEND);
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
subtvb_len = MIN(hdr.frag_len, tvb_reported_length(tvb));
fragment_tvb = tvb_new_subset(tvb, start_offset,
subtvb_len ,
hdr.frag_len );
switch (hdr.ptype) {
case PDU_BIND:
case PDU_ALTER:
dissect_dcerpc_cn_bind(fragment_tvb, MIN(offset - start_offset, subtvb_len), pinfo, dcerpc_tree, &hdr);
break;
case PDU_BIND_ACK:
case PDU_ALTER_ACK:
dissect_dcerpc_cn_bind_ack(fragment_tvb, MIN(offset - start_offset, subtvb_len), pinfo, dcerpc_tree, &hdr);
break;
case PDU_AUTH3:
dissect_dcerpc_cn_auth(fragment_tvb, MIN(offset - start_offset, subtvb_len), pinfo, dcerpc_tree, &hdr, TRUE,
&auth_info);
break;
case PDU_REQ:
dissect_dcerpc_cn_rqst(fragment_tvb, MIN(offset - start_offset, subtvb_len), pinfo, dcerpc_tree, tree, &hdr);
break;
case PDU_RESP:
dissect_dcerpc_cn_resp(fragment_tvb, MIN(offset - start_offset, subtvb_len), pinfo, dcerpc_tree, tree, &hdr);
break;
case PDU_FAULT:
dissect_dcerpc_cn_fault(fragment_tvb, MIN(offset - start_offset, subtvb_len), pinfo, dcerpc_tree, &hdr);
break;
case PDU_BIND_NAK:
dissect_dcerpc_cn_bind_nak(fragment_tvb, MIN(offset - start_offset, subtvb_len), pinfo, dcerpc_tree, &hdr);
break;
case PDU_CO_CANCEL:
case PDU_ORPHANED:
dissect_dcerpc_cn_auth(fragment_tvb, MIN(offset - start_offset, subtvb_len), pinfo, dcerpc_tree, &hdr, FALSE,
&auth_info);
break;
case PDU_SHUTDOWN:
break;
case PDU_RTS:
dissect_dcerpc_cn_rts(fragment_tvb, MIN(offset - start_offset, subtvb_len), pinfo, dcerpc_tree, &hdr);
break;
default:
dissect_dcerpc_cn_auth(fragment_tvb, MIN(offset - start_offset, subtvb_len), pinfo, dcerpc_tree, &hdr, FALSE,
&auth_info);
break;
}
return TRUE;
}
static gboolean
dissect_dcerpc_cn_pk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
dcerpc_decode_as_data* decode_data = dcerpc_get_decode_data(pinfo);
decode_data->dcetransporttype = DCE_TRANSPORT_UNKNOWN;
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
volatile int dcerpc_pdus = 0;
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
if (dcerpc_pdus == 0) {
gboolean try_desegment = FALSE;
if (dcerpc_cn_desegment && pinfo->can_desegment &&
!tvb_bytes_exist(tvb, offset, sizeof(e_dce_cn_common_hdr_t))) {
wmem_list_frame_t *cur;
cur = wmem_list_frame_prev(wmem_list_tail(pinfo->layers));
while (cur != NULL) {
if (proto_dcerpc == (gint)GPOINTER_TO_UINT(wmem_list_frame_data(cur))) {
try_desegment = TRUE;
break;
}
cur = wmem_list_frame_prev(cur);
}
}
if (try_desegment) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = (guint32)(sizeof(e_dce_cn_common_hdr_t) - tvb_reported_length_remaining(tvb, offset));
} else {
break;
}
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
dcerpc_decode_as_data* decode_data = dcerpc_get_decode_data(pinfo);
decode_data->dcetransporttype = DCE_TRANSPORT_UNKNOWN;
return dissect_dcerpc_cn_bs_body(tvb, pinfo, tree);
}
static guint
get_dcerpc_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset _U_, void *data _U_)
{
guint8 drep[4];
guint16 frag_len;
tvb_memcpy(tvb, (guint8 *)drep, 4, sizeof(drep));
frag_len = dcerpc_tvb_get_ntohs(tvb, 8, drep);
return frag_len;
}
static int
dissect_dcerpc_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int pdu_len = 0;
dissect_dcerpc_cn(tvb, 0, pinfo, tree,
FALSE,
&pdu_len);
return pdu_len;
}
static gboolean
dissect_dcerpc_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
dcerpc_decode_as_data* decode_data;
if (!is_dcerpc(tvb, 0, pinfo))
return 0;
decode_data = dcerpc_get_decode_data(pinfo);
decode_data->dcetransporttype = DCE_TRANSPORT_UNKNOWN;
tcp_dissect_pdus(tvb, pinfo, tree, dcerpc_cn_desegment, 10, get_dcerpc_pdu_len, dissect_dcerpc_pdu, data);
return TRUE;
}
static gboolean
dissect_dcerpc_cn_smbpipe(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
dcerpc_decode_as_data* decode_data = dcerpc_get_decode_data(pinfo);
decode_data->dcetransporttype = DCE_CN_TRANSPORT_SMBPIPE;
return dissect_dcerpc_cn_bs_body(tvb, pinfo, tree);
}
static gboolean
dissect_dcerpc_cn_smb2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
dcerpc_decode_as_data* decode_data = dcerpc_get_decode_data(pinfo);
decode_data->dcetransporttype = DCE_CN_TRANSPORT_SMBPIPE;
return dissect_dcerpc_cn_bs_body(tvb, pinfo, tree);
}
static void
dissect_dcerpc_dg_auth(tvbuff_t *tvb, int offset, proto_tree *dcerpc_tree,
e_dce_dg_common_hdr_t *hdr, int *auth_level_p)
{
proto_tree *auth_tree = NULL;
guint8 protection_level;
if (auth_level_p != NULL)
*auth_level_p = -1;
offset += hdr->frag_len;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
switch (hdr->auth_proto) {
case DCE_C_RPC_AUTHN_PROTOCOL_KRB5:
auth_tree = proto_tree_add_subtree(dcerpc_tree, tvb, offset, -1, ett_dcerpc_krb5_auth_verf, NULL, "Kerberos authentication verifier");
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
proto_tree_add_item(dcerpc_tree, hf_dcerpc_authentication_verifier, tvb, offset, -1, ENC_NA);
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
fragment_head *fd_head;
tvbuff_t *next_tvb;
proto_item *pi;
proto_item *parent_pi;
col_append_fstr(pinfo->cinfo, COL_INFO, " opnum: %u len: %u",
di->call_data->opnum, hdr->frag_len );
length = tvb_reported_length_remaining(tvb, offset);
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
if (length > 0) {
proto_tree_add_item(dcerpc_tree, hf_dcerpc_fragment_data, tvb, offset, stub_length, ENC_NA);
}
}
} else {
if (length > 0) {
proto_tree_add_item(dcerpc_tree, hf_dcerpc_fragment_data, tvb, offset, stub_length, ENC_NA);
}
fd_head = fragment_add_seq(&dcerpc_cl_reassembly_table,
tvb, offset,
pinfo, hdr->seqnum, (void *)hdr,
hdr->frag_num, stub_length,
!(hdr->flags1 & PFCL1_LASTFRAG), 0);
if (fd_head != NULL) {
if (pinfo->fd->num == fd_head->reassembled_in) {
next_tvb = tvb_new_chain(tvb, fd_head->tvb_data);
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
dcerpc_call_value *value;
dcerpc_matched_key matched_key, *new_matched_key;
proto_item *pi;
proto_item *parent_pi;
if (!(pinfo->fd->flags.visited)) {
dcerpc_call_value *call_value;
dcerpc_dg_call_key *call_key;
call_key = (dcerpc_dg_call_key *)wmem_alloc(wmem_file_scope(), sizeof (dcerpc_dg_call_key));
call_key->conv = conv;
call_key->seqnum = hdr->seqnum;
call_key->act_id = hdr->act_id;
call_value = (dcerpc_call_value *)wmem_alloc(wmem_file_scope(), sizeof (dcerpc_call_value));
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
new_matched_key = (dcerpc_matched_key *)wmem_alloc(wmem_file_scope(), sizeof(dcerpc_matched_key));
new_matched_key->frame = pinfo->fd->num;
new_matched_key->call_id = hdr->seqnum;
g_hash_table_insert(dcerpc_matched, new_matched_key, call_value);
}
matched_key.frame = pinfo->fd->num;
matched_key.call_id = hdr->seqnum;
value = (dcerpc_call_value *)g_hash_table_lookup(dcerpc_matched, &matched_key);
if (!value) {
value = wmem_new(wmem_packet_scope(), dcerpc_call_value);
value->uuid = hdr->if_id;
value->ver = hdr->if_ver;
value->object_uuid = hdr->obj_id;
value->opnum = hdr->opnum;
value->req_frame = pinfo->fd->num;
value->rep_frame = 0;
value->max_ptr = 0;
value->se_data = NULL;
value->private_data = NULL;
}
di = wmem_new0(wmem_packet_scope(), dcerpc_info);
di->dcerpc_procedure_name = "";
di->conv = conv;
di->call_id = hdr->seqnum;
di->transport_salt = -1;
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
dcerpc_call_value *value;
dcerpc_matched_key matched_key, *new_matched_key;
proto_item *pi;
proto_item *parent_pi;
if (!(pinfo->fd->flags.visited)) {
dcerpc_call_value *call_value;
dcerpc_dg_call_key call_key;
call_key.conv = conv;
call_key.seqnum = hdr->seqnum;
call_key.act_id = hdr->act_id;
if ((call_value = (dcerpc_call_value *)g_hash_table_lookup(dcerpc_dg_calls, &call_key))) {
new_matched_key = (dcerpc_matched_key *)wmem_alloc(wmem_file_scope(), sizeof (dcerpc_matched_key));
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
value = wmem_new0(wmem_packet_scope(), dcerpc_call_value);
value->uuid = hdr->if_id;
value->ver = hdr->if_ver;
value->object_uuid = hdr->obj_id;
value->opnum = hdr->opnum;
value->rep_frame = pinfo->fd->num;
}
di = wmem_new0(wmem_packet_scope(), dcerpc_info);
di->dcerpc_procedure_name = "";
di->conv = conv;
di->transport_salt = -1;
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
proto_tree_add_expert(dcerpc_tree, pinfo, &ei_dcerpc_no_request_found, tvb, 0, 0);
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
proto_tree *drep_tree = NULL;
e_dce_dg_common_hdr_t hdr;
int offset = 0;
conversation_t *conv;
int auth_level;
char *uuid_str;
const char *uuid_name = NULL;
static const int * hdr_flags1[] = {
&hf_dcerpc_dg_flags1_rsrvd_80,
&hf_dcerpc_dg_flags1_broadcast,
&hf_dcerpc_dg_flags1_idempotent,
&hf_dcerpc_dg_flags1_maybe,
&hf_dcerpc_dg_flags1_nofack,
&hf_dcerpc_dg_flags1_frag,
&hf_dcerpc_dg_flags1_last_frag,
&hf_dcerpc_dg_flags1_rsrvd_01,
NULL
};
static const int * hdr_flags2[] = {
&hf_dcerpc_dg_flags2_rsrvd_80,
&hf_dcerpc_dg_flags2_rsrvd_40,
&hf_dcerpc_dg_flags2_rsrvd_20,
&hf_dcerpc_dg_flags2_rsrvd_10,
&hf_dcerpc_dg_flags2_rsrvd_08,
&hf_dcerpc_dg_flags2_rsrvd_04,
&hf_dcerpc_dg_flags2_cancel_pending,
&hf_dcerpc_dg_flags2_rsrvd_01,
NULL
};
if (tvb_reported_length(tvb) < sizeof (hdr)) {
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
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_ver, tvb, offset, 1, hdr.rpc_ver);
offset++;
proto_tree_add_uint(dcerpc_tree, hf_dcerpc_packet_type, tvb, offset, 1, hdr.ptype);
offset++;
proto_tree_add_bitmask_value(dcerpc_tree, tvb, offset, hf_dcerpc_dg_flags1,
ett_dcerpc_dg_flags1, hdr_flags1, hdr.flags1);
offset++;
proto_tree_add_bitmask_value(dcerpc_tree, tvb, offset, hf_dcerpc_dg_flags2,
ett_dcerpc_dg_flags2, hdr_flags2, hdr.flags2);
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
guid_to_str(wmem_packet_scope(), (e_guid_t *) &hdr.obj_id));
}
offset += 16;
if (tree) {
uuid_str = guid_to_str(wmem_packet_scope(), (e_guid_t*)&hdr.if_id);
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
guid_to_str(wmem_packet_scope(), (e_guid_t *) &hdr.act_id));
}
offset += 16;
if (tree) {
nstime_t server_boot;
server_boot.secs = hdr.server_boot;
server_boot.nsecs = 0;
if (hdr.server_boot == 0)
proto_tree_add_time_format_value(dcerpc_tree, hf_dcerpc_dg_server_boot,
tvb, offset, 4, &server_boot,
"Unknown (0)");
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
dcerpc_binds = g_hash_table_new(dcerpc_bind_hash, dcerpc_bind_equal);
dcerpc_cn_calls = g_hash_table_new(dcerpc_cn_call_hash, dcerpc_cn_call_equal);
dcerpc_dg_calls = g_hash_table_new(dcerpc_dg_call_hash, dcerpc_dg_call_equal);
dcerpc_matched = g_hash_table_new(dcerpc_matched_hash, dcerpc_matched_equal);
decode_dcerpc_inject_bindings();
}
static void
dcerpc_cleanup_protocol(void)
{
g_hash_table_destroy(dcerpc_binds);
g_hash_table_destroy(dcerpc_cn_calls);
g_hash_table_destroy(dcerpc_dg_calls);
g_hash_table_destroy(dcerpc_matched);
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
{ &hf_dcerpc_referent_id32,
{ "Referent ID", "dcerpc.referent_id", FT_UINT32, BASE_HEX,
NULL, 0, "Referent ID for this NDR encoded pointer", HFILL }},
{ &hf_dcerpc_referent_id64,
{ "Referent ID", "dcerpc.referent_id", FT_UINT64, BASE_HEX,
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
{ &hf_dcerpc_ndr_padding,
{ "NDR-Padding", "dcerpc.ndr_padding", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
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
{ &hf_dcerpc_cn_bind_trans_btfn_01,
{ "Security Context Multiplexing Supported", "dcerpc.cn_bind_trans_btfn.01", FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x01, NULL, HFILL }},
{ &hf_dcerpc_cn_bind_trans_btfn_02,
{ "Keep Connection On Orphan Supported", "dcerpc.cn_bind_trans_btfn.02", FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x02, NULL, HFILL }},
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
{ &hf_dcerpc_cn_ack_btfn,
{ "Bind Time Feature Negotiation Bitmask", "dcerpc.cn_ack_btfn", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
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
{ &hf_dcerpc_op,
{ "Operation", "dcerpc.op", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_null_pointer,
{ "NULL Pointer", "dcerpc.null_pointer", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
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
{ &hf_dcerpc_duplicate_ptr, { "duplicate PTR", "dcerpc.duplicate_ptr", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_encrypted_stub_data, { "Encrypted stub data", "dcerpc.encrypted_stub_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_decrypted_stub_data, { "Decrypted stub data", "dcerpc.decrypted_stub_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_stub_data, { "Stub data", "dcerpc.stub_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_auth_padding, { "Auth Padding", "dcerpc.auth_padding", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_auth_verifier, { "Auth Verifier", "dcerpc.auth_verifier", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_auth_credentials, { "Auth Credentials", "dcerpc.auth_credentials", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_fault_stub_data, { "Fault stub data", "dcerpc.fault_stub_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_fragment_data, { "Fragment data", "dcerpc.fragment_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cmd_client_ipv4, { "RTS Client address", "dcerpc.cmd_client_ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_cmd_client_ipv6, { "RTS Client address", "dcerpc.cmd_client_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcerpc_authentication_verifier, { "Authentication verifier", "dcerpc.authentication_verifier", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc,
&ett_dcerpc_cn_flags,
&ett_dcerpc_cn_ctx,
&ett_dcerpc_cn_iface,
&ett_dcerpc_cn_trans_syntax,
&ett_dcerpc_cn_trans_btfn,
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
static ei_register_info ei[] = {
{ &ei_dcerpc_fragment, { "dcerpc.fragment", PI_REASSEMBLE, PI_CHAT, "%s fragment", EXPFILL }},
{ &ei_dcerpc_fragment_reassembled, { "dcerpc.fragment_reassembled", PI_REASSEMBLE, PI_CHAT, "%s fragment, reassembled", EXPFILL }},
{ &ei_dcerpc_cn_ctx_id_no_bind, { "dcerpc.cn_ctx_id.no_bind", PI_UNDECODED, PI_NOTE, "No bind info for interface Context ID %u - capture start too late?", EXPFILL }},
{ &ei_dcerpc_no_request_found, { "dcerpc.no_request_found", PI_SEQUENCE, PI_NOTE, "No request to this DCE/RPC call found", EXPFILL }},
{ &ei_dcerpc_cn_status, { "dcerpc.cn_status.expert", PI_RESPONSE_CODE, PI_NOTE, "Fault: %s", EXPFILL }},
{ &ei_dcerpc_fragment_multiple, { "dcerpc.fragment_multiple", PI_SEQUENCE, PI_CHAT, "Multiple DCE/RPC fragments/PDU's in one packet", EXPFILL }},
{ &ei_dcerpc_context_change, { "dcerpc.context_change", PI_SEQUENCE, PI_CHAT, "Context change: %s", EXPFILL }},
{ &ei_dcerpc_bind_not_acknowledged, { "dcerpc.bind_not_acknowledged", PI_SEQUENCE, PI_WARN, "Bind not acknowledged", EXPFILL }},
{ &ei_dcerpc_verifier_unavailable, { "dcerpc.verifier_unavailable", PI_UNDECODED, PI_WARN, NULL, EXPFILL }},
{ &ei_dcerpc_invalid_pdu_authentication_attempt, { "dcerpc.invalid_pdu_authentication_attempt", PI_UNDECODED, PI_WARN, NULL, EXPFILL }},
{ &ei_dcerpc_long_frame, { "dcerpc.long_frame", PI_PROTOCOL, PI_WARN, "Long frame", EXPFILL }},
{ &ei_dcerpc_cn_rts_command, { "dcerpc.cn_rts_command.unknown", PI_PROTOCOL, PI_WARN, "unknown RTS command number", EXPFILL }},
};
static build_valid_func dcerpc_da_build_value[1] = {dcerpc_value};
static decode_as_value_t dcerpc_da_values = {dcerpc_prompt, 1, dcerpc_da_build_value};
static decode_as_t dcerpc_da = {"dcerpc", "DCE-RPC",
"dcerpc.fake",
1, 0, &dcerpc_da_values, NULL, NULL,
dcerpc_populate_list, decode_dcerpc_binding_reset, dcerpc_decode_as_change, dcerpc_decode_as_free};
module_t *dcerpc_module;
expert_module_t* expert_dcerpc;
proto_dcerpc = proto_register_protocol("Distributed Computing Environment / Remote Procedure Call (DCE/RPC)", "DCERPC", "dcerpc");
proto_register_field_array(proto_dcerpc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dcerpc = expert_register_protocol(proto_dcerpc);
expert_register_field_array(expert_dcerpc, ei, array_length(ei));
register_init_routine(dcerpc_init_protocol);
register_cleanup_routine(dcerpc_cleanup_protocol);
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
register_decode_as(&dcerpc_da);
register_srt_table(proto_dcerpc, NULL, 1, dcerpcstat_packet, dcerpcstat_init, dcerpcstat_param);
}
void
proto_reg_handoff_dcerpc(void)
{
heur_dissector_add("tcp", dissect_dcerpc_tcp, "DCE/RPC over TCP", "dcerpc_tcp", proto_dcerpc, HEURISTIC_ENABLE);
heur_dissector_add("netbios", dissect_dcerpc_cn_pk, "DCE/RPC over NetBios", "dcerpc_netbios", proto_dcerpc, HEURISTIC_ENABLE);
heur_dissector_add("udp", dissect_dcerpc_dg, "DCE/RPC over UDP", "dcerpc_udp", proto_dcerpc, HEURISTIC_ENABLE);
heur_dissector_add("smb_transact", dissect_dcerpc_cn_smbpipe, "DCE/RPC over SMB", "dcerpc_smb_transact", proto_dcerpc, HEURISTIC_ENABLE);
heur_dissector_add("smb2_heur_subdissectors", dissect_dcerpc_cn_smb2, "DCE/RPC over SMB2", "dcerpc_smb2", proto_dcerpc, HEURISTIC_ENABLE);
heur_dissector_add("http", dissect_dcerpc_cn_bs, "DCE/RPC over HTTP", "dcerpc_http", proto_dcerpc, HEURISTIC_ENABLE);
dcerpc_smb_init(proto_dcerpc);
guids_add_uuid(&uuid_data_repr_proto, "32bit NDR");
guids_add_uuid(&uuid_ndr64, "64bit NDR");
guids_add_uuid(&uuid_bind_time_feature_nego_00, "bind time feature negotiation");
guids_add_uuid(&uuid_bind_time_feature_nego_01, "bind time feature negotiation");
guids_add_uuid(&uuid_bind_time_feature_nego_02, "bind time feature negotiation");
guids_add_uuid(&uuid_bind_time_feature_nego_03, "bind time feature negotiation");
guids_add_uuid(&uuid_asyncemsmdb, "async MAPI");
}
