static gint
rpc_proc_equal(gconstpointer k1, gconstpointer k2)
{
const rpc_proc_info_key* key1 = (const rpc_proc_info_key*) k1;
const rpc_proc_info_key* key2 = (const rpc_proc_info_key*) k2;
return ((key1->prog == key2->prog &&
key1->vers == key2->vers &&
key1->proc == key2->proc) ?
TRUE : FALSE);
}
static guint
rpc_proc_hash(gconstpointer k)
{
const rpc_proc_info_key* key = (const rpc_proc_info_key*) k;
return (key->prog ^ (key->vers<<16) ^ (key->proc<<24));
}
void
rpc_init_proc_table(guint prog, guint vers, const vsff *proc_table,
int procedure_hf)
{
rpc_prog_info_key rpc_prog_key;
rpc_prog_info_value *rpc_prog;
const vsff *proc;
rpc_prog_key.prog = prog;
rpc_prog = (rpc_prog_info_value *)g_hash_table_lookup(rpc_progs, &rpc_prog_key);
DISSECTOR_ASSERT(rpc_prog != NULL);
rpc_prog->procedure_hfs = g_array_set_size(rpc_prog->procedure_hfs,
vers);
g_array_insert_val(rpc_prog->procedure_hfs, vers, procedure_hf);
for (proc = proc_table ; proc->strptr!=NULL; proc++) {
rpc_proc_info_key *key;
rpc_proc_info_value *value;
key = (rpc_proc_info_key *) g_malloc(sizeof(rpc_proc_info_key));
key->prog = prog;
key->vers = vers;
key->proc = proc->value;
value = (rpc_proc_info_value *) g_malloc(sizeof(rpc_proc_info_value));
value->name = proc->strptr;
value->dissect_call = proc->dissect_call;
value->dissect_reply = proc->dissect_reply;
g_hash_table_insert(rpc_procs,key,value);
}
}
const char *
rpc_proc_name(guint32 prog, guint32 vers, guint32 proc)
{
rpc_proc_info_key key;
rpc_proc_info_value *value;
const char *procname;
key.prog = prog;
key.vers = vers;
key.proc = proc;
if ((value = (rpc_proc_info_value *)g_hash_table_lookup(rpc_procs,&key)) != NULL)
procname = value->name;
else {
procname = wmem_strdup_printf(wmem_packet_scope(), "proc-%u", key.proc);
}
return procname;
}
static gint
rpc_prog_equal(gconstpointer k1, gconstpointer k2)
{
const rpc_prog_info_key* key1 = (const rpc_prog_info_key*) k1;
const rpc_prog_info_key* key2 = (const rpc_prog_info_key*) k2;
return ((key1->prog == key2->prog) ?
TRUE : FALSE);
}
static guint
rpc_prog_hash(gconstpointer k)
{
const rpc_prog_info_key* key = (const rpc_prog_info_key*) k;
return (key->prog);
}
static void
rpc_prog_free_val(gpointer v)
{
rpc_prog_info_value *value = (rpc_prog_info_value*)v;
g_array_free(value->procedure_hfs, TRUE);
g_free(value);
}
void
rpc_init_prog(int proto, guint32 prog, int ett)
{
rpc_prog_info_key *key;
rpc_prog_info_value *value;
key = (rpc_prog_info_key *) g_malloc(sizeof(rpc_prog_info_key));
key->prog = prog;
value = (rpc_prog_info_value *) g_malloc(sizeof(rpc_prog_info_value));
value->proto = find_protocol_by_id(proto);
value->proto_id = proto;
value->ett = ett;
value->progname = proto_get_protocol_short_name(value->proto);
value->procedure_hfs = g_array_new(FALSE, TRUE, sizeof (int));
g_hash_table_insert(rpc_progs,key,value);
}
int
rpc_prog_hf(guint32 prog, guint32 vers)
{
rpc_prog_info_key rpc_prog_key;
rpc_prog_info_value *rpc_prog;
rpc_prog_key.prog = prog;
if ((rpc_prog = (rpc_prog_info_value *)g_hash_table_lookup(rpc_progs,&rpc_prog_key))) {
return g_array_index(rpc_prog->procedure_hfs, int, vers);
}
return -1;
}
const char *
rpc_prog_name(guint32 prog)
{
const char *progname = NULL;
rpc_prog_info_key rpc_prog_key;
rpc_prog_info_value *rpc_prog;
rpc_prog_key.prog = prog;
if ((rpc_prog = (rpc_prog_info_value *)g_hash_table_lookup(rpc_progs,&rpc_prog_key)) == NULL) {
progname = "Unknown";
}
else {
progname = rpc_prog->progname;
}
return progname;
}
unsigned int
rpc_roundup(unsigned int a)
{
unsigned int mod = a % 4;
unsigned int ret;
ret = a + ((mod)? 4-mod : 0);
if (ret < a)
THROW(ReportedBoundsError);
return ret;
}
int
dissect_rpc_bool(tvbuff_t *tvb, proto_tree *tree,
int hfindex, int offset)
{
proto_tree_add_item(tree, hfindex, tvb, offset, 4, ENC_BIG_ENDIAN);
return offset + 4;
}
int
dissect_rpc_uint32(tvbuff_t *tvb, proto_tree *tree,
int hfindex, int offset)
{
proto_tree_add_item(tree, hfindex, tvb, offset, 4, ENC_BIG_ENDIAN);
return offset + 4;
}
int
dissect_rpc_uint64(tvbuff_t *tvb, proto_tree *tree,
int hfindex, int offset)
{
header_field_info *hfinfo;
hfinfo = proto_registrar_get_nth(hfindex);
DISSECTOR_ASSERT(hfinfo->type == FT_UINT64);
proto_tree_add_item(tree, hfindex, tvb, offset, 8, ENC_BIG_ENDIAN);
return offset + 8;
}
int
dissect_rpc_opaque_data(tvbuff_t *tvb, int offset,
proto_tree *tree,
packet_info *pinfo,
int hfindex,
gboolean fixed_length, guint32 length,
gboolean string_data, const char **string_buffer_ret,
dissect_function_t *dissect_it)
{
int data_offset;
proto_item *string_item = NULL;
proto_tree *string_tree = NULL;
guint32 string_length;
guint32 string_length_full;
guint32 string_length_packet;
guint32 string_length_captured;
guint32 string_length_copy;
int fill_truncated;
guint32 fill_length;
guint32 fill_length_packet;
guint32 fill_length_captured;
guint32 fill_length_copy;
int exception = 0;
char *string_buffer = NULL;
const char *string_buffer_print = NULL;
if (fixed_length) {
string_length = length;
data_offset = offset;
}
else {
string_length = tvb_get_ntohl(tvb,offset);
data_offset = offset + 4;
}
string_length_captured = tvb_length_remaining(tvb, data_offset);
string_length_packet = tvb_reported_length_remaining(tvb, data_offset);
string_length_full = rpc_roundup(string_length);
if (string_length_captured < string_length) {
string_length_copy = string_length_captured;
fill_truncated = 2;
fill_length = 0;
fill_length_copy = 0;
if (string_length_packet < string_length)
exception = ReportedBoundsError;
else
exception = BoundsError;
}
else {
string_length_copy = string_length;
fill_length = string_length_full - string_length;
fill_length_captured = tvb_length_remaining(tvb,
data_offset + string_length);
fill_length_packet = tvb_reported_length_remaining(tvb,
data_offset + string_length);
if (fill_length_captured < fill_length) {
fill_length_copy = fill_length_packet;
fill_truncated = 1;
if (fill_length_packet < fill_length)
exception = ReportedBoundsError;
else
exception = BoundsError;
}
else {
fill_length_copy = fill_length;
fill_truncated = 0;
}
}
if (dissect_it) {
tvbuff_t *opaque_tvb;
opaque_tvb = tvb_new_subset(tvb, data_offset, string_length_copy,
string_length);
return (*dissect_it)(opaque_tvb, offset, pinfo, tree, NULL);
}
if (string_data) {
string_buffer = tvb_get_string_enc(wmem_packet_scope(), tvb, data_offset, string_length_copy, ENC_ASCII);
} else {
string_buffer = (char *)tvb_memcpy(tvb, wmem_alloc(wmem_packet_scope(), string_length_copy+1), data_offset, string_length_copy);
}
string_buffer[string_length_copy] = '\0';
if (string_length) {
if (string_length != string_length_copy) {
if (string_data) {
char *formatted;
formatted = format_text(string_buffer, strlen(string_buffer));
string_buffer_print=wmem_strdup_printf(wmem_packet_scope(), "%s%s", formatted, RPC_STRING_TRUNCATED);
} else {
string_buffer_print=RPC_STRING_DATA RPC_STRING_TRUNCATED;
}
} else {
if (string_data) {
string_buffer_print =
wmem_strdup(wmem_packet_scope(), format_text(string_buffer, strlen(string_buffer)));
} else {
string_buffer_print=RPC_STRING_DATA;
}
}
} else {
string_buffer_print=RPC_STRING_EMPTY;
}
if (tree) {
string_tree = proto_tree_add_subtree_format(tree, tvb,offset, -1,
ett_rpc_string, &string_item, "%s: %s", proto_registrar_get_name(hfindex),
string_buffer_print);
}
if (!fixed_length) {
proto_tree_add_text(string_tree, tvb,offset,4,
"length: %u", string_length);
offset += 4;
}
if (string_tree) {
if (string_data) {
proto_tree_add_string_format(string_tree,
hfindex, tvb, offset, string_length_copy,
string_buffer,
"contents: %s", string_buffer_print);
} else {
proto_tree_add_bytes_format(string_tree,
hfindex, tvb, offset, string_length_copy,
string_buffer,
"contents: %s", string_buffer_print);
}
}
offset += string_length_copy;
if (fill_length) {
if (string_tree) {
if (fill_truncated) {
proto_tree_add_text(string_tree, tvb,
offset,fill_length_copy,
"fill bytes: opaque data<TRUNCATED>");
}
else {
proto_tree_add_text(string_tree, tvb,
offset,fill_length_copy,
"fill bytes: opaque data");
}
}
offset += fill_length_copy;
}
if (string_item)
proto_item_set_end(string_item, tvb, offset);
if (string_buffer_ret != NULL)
*string_buffer_ret = string_buffer_print;
if (exception != 0)
THROW(exception);
return offset;
}
int
dissect_rpc_string(tvbuff_t *tvb, proto_tree *tree,
int hfindex, int offset, const char **string_buffer_ret)
{
offset = dissect_rpc_opaque_data(tvb, offset, tree, NULL,
hfindex, FALSE, 0, TRUE, string_buffer_ret, NULL);
return offset;
}
int
dissect_rpc_data(tvbuff_t *tvb, proto_tree *tree,
int hfindex, int offset)
{
offset = dissect_rpc_opaque_data(tvb, offset, tree, NULL,
hfindex, FALSE, 0, FALSE, NULL, NULL);
return offset;
}
int
dissect_rpc_bytes(tvbuff_t *tvb, proto_tree *tree,
int hfindex, int offset, guint32 length,
gboolean string_data, const char **string_buffer_ret)
{
offset = dissect_rpc_opaque_data(tvb, offset, tree, NULL,
hfindex, TRUE, length, string_data, string_buffer_ret, NULL);
return offset;
}
int
dissect_rpc_list(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, dissect_function_t *rpc_list_dissector, void *data)
{
guint32 value_follows;
while (1) {
value_follows = tvb_get_ntohl(tvb, offset);
proto_tree_add_boolean(tree,hf_rpc_value_follows, tvb,
offset, 4, value_follows);
offset += 4;
if (value_follows == 1) {
offset = rpc_list_dissector(tvb, offset, pinfo, tree,
data);
}
else {
break;
}
}
return offset;
}
int
dissect_rpc_array(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, dissect_function_t *rpc_array_dissector,
int hfindex)
{
proto_item* lock_item;
proto_tree* lock_tree;
guint32 num;
num = tvb_get_ntohl(tvb, offset);
lock_item = proto_tree_add_item(tree, hfindex, tvb, offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_rpc_array);
if(num == 0) {
proto_tree_add_text(lock_tree, tvb, offset, 4, "no values");
offset += 4;
proto_item_set_end(lock_item, tvb, offset);
return offset;
}
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_rpc_array_len, offset);
while (num--) {
offset = rpc_array_dissector(tvb, offset, pinfo, lock_tree, NULL);
}
proto_item_set_end(lock_item, tvb, offset);
return offset;
}
static int
dissect_rpc_authunix_groups(tvbuff_t* tvb, proto_tree* tree, int offset)
{
guint gids_count;
guint gids_i;
guint gids_entry;
proto_item *gitem = NULL;
proto_tree *gtree = NULL;
gids_count = tvb_get_ntohl(tvb,offset);
gtree = proto_tree_add_subtree_format(tree, tvb, offset,
4+gids_count*4, ett_rpc_gids, &gitem, "Auxiliary GIDs (%d)", gids_count);
offset += 4;
if (tree && gids_count > 0)
proto_item_append_text(gitem, " [");
for (gids_i = 0 ; gids_i < gids_count; gids_i++) {
gids_entry = tvb_get_ntohl(tvb,offset);
if (gtree) {
proto_tree_add_uint(gtree, hf_rpc_auth_gid, tvb,
offset, 4, gids_entry);
}
if (tree && gids_i < 16) {
if (gids_i > 0)
proto_item_append_text(gitem, ", ");
proto_item_append_text(gitem, "%d", gids_entry);
} else if (tree && gids_i == 16) {
proto_item_append_text(gitem, "...");
}
offset += 4;
}
if (tree && gids_count > 0)
proto_item_append_text(gitem, "]");
return offset;
}
static int
dissect_rpc_authunix_cred(tvbuff_t* tvb, proto_tree* tree, int offset)
{
guint stamp;
guint uid;
guint gid;
stamp = tvb_get_ntohl(tvb,offset);
proto_tree_add_uint(tree, hf_rpc_auth_stamp, tvb,
offset, 4, stamp);
offset += 4;
offset = dissect_rpc_string(tvb, tree,
hf_rpc_auth_machinename, offset, NULL);
uid = tvb_get_ntohl(tvb,offset);
proto_tree_add_uint(tree, hf_rpc_auth_uid, tvb,
offset, 4, uid);
offset += 4;
gid = tvb_get_ntohl(tvb,offset);
proto_tree_add_uint(tree, hf_rpc_auth_gid, tvb,
offset, 4, gid);
offset += 4;
offset = dissect_rpc_authunix_groups(tvb, tree, offset);
return offset;
}
static int
dissect_rpc_authgss_context(proto_tree *tree, tvbuff_t *tvb, int offset,
packet_info *pinfo, rpc_conv_info_t *rpc_conv_info _U_,
gboolean is_create, gboolean is_destroy)
{
proto_item *context_item;
proto_tree *context_tree;
int old_offset = offset;
int context_offset;
guint32 context_length;
gssauth_context_info_t *context_info;
wmem_tree_key_t tkey[2];
guint32 key[4] = {0,0,0,0};
context_tree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_gss_context, &context_item, "GSS Context");
context_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(context_tree, hf_rpc_authgss_ctx_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
context_offset = offset;
proto_tree_add_item(context_tree, hf_rpc_authgss_ctx, tvb, offset, context_length, ENC_NA);
offset += context_length;
offset = (offset + 3) & 0xffffffc;
if (context_length > 16) {
return offset;
}
tvb_memcpy(tvb, key, context_offset, context_length);
tkey[0].length = 4;
tkey[0].key = &key[0];
tkey[1].length = 0;
tkey[1].key = NULL;
context_info = (gssauth_context_info_t *)wmem_tree_lookup32_array(authgss_contexts, &tkey[0]);
if(context_info == NULL) {
tvb_memcpy(tvb, key, context_offset, context_length);
tkey[0].length = 4;
tkey[0].key = &key[0];
tkey[1].length = 0;
tkey[1].key = NULL;
context_info = wmem_new(wmem_file_scope(), gssauth_context_info_t);
context_info->create_frame = 0;
context_info->destroy_frame = 0;
wmem_tree_insert32_array(authgss_contexts, &tkey[0], context_info);
}
if (is_create) {
context_info->create_frame = pinfo->fd->num;
}
if (is_destroy) {
context_info->destroy_frame = pinfo->fd->num;
}
if (context_info->create_frame) {
proto_item *it;
it = proto_tree_add_uint(context_tree, hf_rpc_authgss_ctx_create_frame, tvb, 0, 0, context_info->create_frame);
PROTO_ITEM_SET_GENERATED(it);
}
if (context_info->destroy_frame) {
proto_item *it;
it = proto_tree_add_uint(context_tree, hf_rpc_authgss_ctx_destroy_frame, tvb, 0, 0, context_info->destroy_frame);
PROTO_ITEM_SET_GENERATED(it);
}
proto_item_set_len(context_item, offset - old_offset);
return offset;
}
static int
dissect_rpc_authgss_cred(tvbuff_t* tvb, proto_tree* tree, int offset,
packet_info *pinfo, rpc_conv_info_t *rpc_conv_info)
{
guint agc_v;
guint agc_proc;
guint agc_seq;
guint agc_svc;
agc_v = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_rpc_authgss_v,
tvb, offset, 4, agc_v);
offset += 4;
agc_proc = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_rpc_authgss_proc,
tvb, offset, 4, agc_proc);
offset += 4;
agc_seq = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_rpc_authgss_seq,
tvb, offset, 4, agc_seq);
offset += 4;
agc_svc = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_rpc_authgss_svc,
tvb, offset, 4, agc_svc);
offset += 4;
offset = dissect_rpc_authgss_context(tree, tvb, offset, pinfo, rpc_conv_info, FALSE, agc_proc == RPCSEC_GSS_DESTROY ? TRUE : FALSE);
return offset;
}
static int
dissect_rpc_authdes_desblock(tvbuff_t *tvb, proto_tree *tree,
int hfindex, int offset)
{
guint32 value_low;
guint32 value_high;
value_high = tvb_get_ntohl(tvb, offset);
value_low = tvb_get_ntohl(tvb, offset + 4);
if (tree) {
proto_tree_add_text(tree, tvb, offset, 8,
"%s: 0x%x%08x", proto_registrar_get_name(hfindex), value_high,
value_low);
}
return offset + 8;
}
static int
dissect_rpc_authdes_cred(tvbuff_t* tvb, proto_tree* tree, int offset)
{
guint adc_namekind;
guint window = 0;
guint nickname = 0;
adc_namekind = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_rpc_authdes_namekind,
tvb, offset, 4, adc_namekind);
offset += 4;
switch(adc_namekind)
{
case AUTHDES_NAMEKIND_FULLNAME:
offset = dissect_rpc_string(tvb, tree,
hf_rpc_authdes_netname, offset, NULL);
offset = dissect_rpc_authdes_desblock(tvb, tree,
hf_rpc_authdes_convkey, offset);
window = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_rpc_authdes_window, tvb, offset, 4,
window);
offset += 4;
break;
case AUTHDES_NAMEKIND_NICKNAME:
nickname = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_rpc_authdes_nickname, tvb, offset, 4,
nickname);
offset += 4;
break;
}
return offset;
}
static int
dissect_rpc_authgluster_cred(tvbuff_t* tvb, proto_tree* tree, int offset)
{
proto_tree_add_item(tree, hf_rpc_auth_lk_owner, tvb, offset,
8, ENC_NA);
offset += 8;
offset = dissect_rpc_uint32(tvb, tree, hf_rpc_auth_pid, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_rpc_auth_uid, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_rpc_auth_gid, offset);
offset = dissect_rpc_authunix_groups(tvb, tree, offset);
return offset;
}
static int
dissect_rpc_authglusterfs_v2_cred(tvbuff_t* tvb, proto_tree* tree, int offset)
{
int len;
offset = dissect_rpc_uint32(tvb, tree, hf_rpc_auth_pid, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_rpc_auth_uid, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_rpc_auth_gid, offset);
offset = dissect_rpc_authunix_groups(tvb, tree, offset);
len = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_item(tree, hf_rpc_auth_lk_owner, tvb, offset,
len, ENC_NA);
offset += len;
return offset;
}
static int
dissect_rpc_authgssapi_cred(tvbuff_t* tvb, proto_tree* tree, int offset)
{
guint agc_v;
guint agc_msg;
agc_v = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_rpc_authgssapi_v,
tvb, offset, 4, agc_v);
offset += 4;
agc_msg = tvb_get_ntohl(tvb, offset);
proto_tree_add_boolean(tree, hf_rpc_authgssapi_msg,
tvb, offset, 4, agc_msg);
offset += 4;
offset = dissect_rpc_data(tvb, tree, hf_rpc_authgssapi_handle,
offset);
return offset;
}
static int
dissect_rpc_cred(tvbuff_t* tvb, proto_tree* tree, int offset,
packet_info *pinfo, rpc_conv_info_t *rpc_conv_info)
{
guint flavor;
guint length;
proto_tree *ctree;
flavor = tvb_get_ntohl(tvb,offset);
length = tvb_get_ntohl(tvb,offset+4);
length = rpc_roundup(length);
if (tree) {
ctree = proto_tree_add_subtree(tree, tvb, offset,
8+length, ett_rpc_cred, NULL, "Credentials");
proto_tree_add_uint(ctree, hf_rpc_auth_flavor, tvb,
offset, 4, flavor);
proto_tree_add_uint(ctree, hf_rpc_auth_length, tvb,
offset+4, 4, length);
switch (flavor) {
case AUTH_UNIX:
dissect_rpc_authunix_cred(tvb, ctree, offset+8);
break;
case AUTH_DES:
dissect_rpc_authdes_cred(tvb, ctree, offset+8);
break;
case AUTH_RSA:
dissect_rpc_authgluster_cred(tvb, ctree, offset+8);
break;
case RPCSEC_GSS:
dissect_rpc_authgss_cred(tvb, ctree, offset+8, pinfo, rpc_conv_info);
break;
case AUTH_GLUSTERFS:
dissect_rpc_authglusterfs_v2_cred(tvb, ctree, offset+8);
break;
case AUTH_GSSAPI:
dissect_rpc_authgssapi_cred(tvb, ctree, offset+8);
break;
default:
if (length)
proto_tree_add_text(ctree, tvb, offset+8,
length,"opaque data");
break;
}
}
offset += 8 + length;
return offset;
}
static int
dissect_rpc_authgss_token(tvbuff_t* tvb, proto_tree* tree, int offset,
packet_info *pinfo, int hfindex)
{
guint32 opaque_length, rounded_length;
gint len_consumed, length, reported_length;
tvbuff_t *new_tvb;
proto_item *gitem;
proto_tree *gtree = NULL;
opaque_length = tvb_get_ntohl(tvb, offset);
rounded_length = rpc_roundup(opaque_length);
gitem = proto_tree_add_item(tree, hfindex, tvb, offset, 4+rounded_length, ENC_NA);
gtree = proto_item_add_subtree(gitem, ett_rpc_gss_token);
proto_tree_add_uint(gtree, hf_rpc_authgss_token_length,
tvb, offset, 4, opaque_length);
offset += 4;
if (opaque_length != 0) {
length = tvb_length_remaining(tvb, offset);
reported_length = tvb_reported_length_remaining(tvb, offset);
DISSECTOR_ASSERT(length >= 0);
DISSECTOR_ASSERT(reported_length >= 0);
if (length > reported_length)
length = reported_length;
if ((guint32)length > opaque_length)
length = opaque_length;
if ((guint32)reported_length > opaque_length)
reported_length = opaque_length;
new_tvb = tvb_new_subset(tvb, offset, length, reported_length);
len_consumed = call_dissector(gssapi_handle, new_tvb, pinfo, gtree);
offset += len_consumed;
}
offset = rpc_roundup(offset);
return offset;
}
static int
dissect_rpc_verf(tvbuff_t* tvb, proto_tree* tree, int offset, int msg_type,
packet_info *pinfo)
{
guint flavor;
guint length;
proto_tree *vtree;
flavor = tvb_get_ntohl(tvb,offset);
length = tvb_get_ntohl(tvb,offset+4);
length = rpc_roundup(length);
if (tree) {
vtree = proto_tree_add_subtree(tree, tvb, offset,
8+length, ett_rpc_verf, NULL, "Verifier");
proto_tree_add_uint(vtree, hf_rpc_auth_flavor, tvb,
offset, 4, flavor);
switch (flavor) {
case AUTH_UNIX:
proto_tree_add_uint(vtree, hf_rpc_auth_length, tvb,
offset+4, 4, length);
dissect_rpc_authunix_cred(tvb, vtree, offset+8);
break;
case AUTH_DES:
proto_tree_add_uint(vtree, hf_rpc_auth_length, tvb,
offset+4, 4, length);
if (msg_type == RPC_CALL)
{
guint window;
dissect_rpc_authdes_desblock(tvb, vtree,
hf_rpc_authdes_timestamp, offset+8);
window = tvb_get_ntohl(tvb, offset+16);
proto_tree_add_uint(vtree, hf_rpc_authdes_windowverf, tvb,
offset+16, 4, window);
}
else
{
guint nickname;
dissect_rpc_authdes_desblock(tvb, vtree,
hf_rpc_authdes_timeverf, offset+8);
nickname = tvb_get_ntohl(tvb, offset+16);
proto_tree_add_uint(vtree, hf_rpc_authdes_nickname, tvb,
offset+16, 4, nickname);
}
break;
case RPCSEC_GSS:
dissect_rpc_authgss_token(tvb, vtree, offset+4, pinfo, hf_rpc_authgss_token);
break;
default:
proto_tree_add_uint(vtree, hf_rpc_auth_length, tvb,
offset+4, 4, length);
if (length)
proto_tree_add_text(vtree, tvb, offset+8,
length, "opaque data");
break;
}
}
offset += 8 + length;
return offset;
}
static int
dissect_rpc_authgss_initarg(tvbuff_t* tvb, proto_tree* tree, int offset,
packet_info *pinfo)
{
return dissect_rpc_authgss_token(tvb, tree, offset, pinfo, hf_rpc_authgss_token);
}
static int
dissect_rpc_authgss_initres(tvbuff_t* tvb, proto_tree* tree, int offset,
packet_info *pinfo, rpc_conv_info_t *rpc_conv_info)
{
int major, minor, window;
offset = dissect_rpc_authgss_context(tree, tvb, offset, pinfo, rpc_conv_info, TRUE, FALSE);
major = tvb_get_ntohl(tvb,offset);
proto_tree_add_uint(tree, hf_rpc_authgss_major, tvb,
offset, 4, major);
offset += 4;
minor = tvb_get_ntohl(tvb,offset);
proto_tree_add_uint(tree, hf_rpc_authgss_minor, tvb,
offset, 4, minor);
offset += 4;
window = tvb_get_ntohl(tvb,offset);
proto_tree_add_uint(tree, hf_rpc_authgss_window, tvb,
offset, 4, window);
offset += 4;
offset = dissect_rpc_authgss_token(tvb, tree, offset, pinfo, hf_rpc_authgss_token);
return offset;
}
static int
dissect_rpc_authgssapi_initarg(tvbuff_t* tvb, proto_tree* tree, int offset,
packet_info *pinfo)
{
guint version;
proto_tree *mtree;
mtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_rpc_authgssapi_msg, NULL, "AUTH_GSSAPI Msg");
version = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(mtree, hf_rpc_authgssapi_msgv, tvb, offset, 4, version);
offset += 4;
offset = dissect_rpc_authgss_token(tvb, mtree, offset, pinfo, hf_rpc_authgss_token);
return offset;
}
static int
dissect_rpc_authgssapi_initres(tvbuff_t* tvb, proto_tree* tree, int offset,
packet_info *pinfo)
{
guint version;
guint major, minor;
proto_tree *mtree;
mtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_rpc_authgssapi_msg, NULL, "AUTH_GSSAPI Msg");
version = tvb_get_ntohl(tvb,offset);
proto_tree_add_uint(mtree, hf_rpc_authgssapi_msgv, tvb,
offset, 4, version);
offset += 4;
offset = dissect_rpc_data(tvb, mtree, hf_rpc_authgssapi_handle,
offset);
major = tvb_get_ntohl(tvb,offset);
proto_tree_add_uint(mtree, hf_rpc_authgss_major, tvb,
offset, 4, major);
offset += 4;
minor = tvb_get_ntohl(tvb,offset);
proto_tree_add_uint(mtree, hf_rpc_authgss_minor, tvb,
offset, 4, minor);
offset += 4;
offset = dissect_rpc_authgss_token(tvb, mtree, offset, pinfo, hf_rpc_authgss_token);
offset = dissect_rpc_data(tvb, mtree, hf_rpc_authgssapi_isn, offset);
return offset;
}
static int
dissect_auth_gssapi_data(tvbuff_t *tvb, proto_tree *tree, int offset)
{
offset = dissect_rpc_data(tvb, tree, hf_rpc_authgss_data,
offset);
return offset;
}
static int
call_dissect_function(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, dissect_function_t* dissect_function, const char *progname,
rpc_call_info_value *rpc_call)
{
const char *saved_proto;
tvb_ensure_length_remaining(tvb, offset);
if (dissect_function != NULL) {
saved_proto = pinfo->current_proto;
if (progname != NULL)
pinfo->current_proto = progname;
offset = dissect_function(tvb, offset, pinfo, tree, rpc_call);
pinfo->current_proto = saved_proto;
}
return offset;
}
static int
dissect_rpc_authgss_integ_data(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset,
dissect_function_t* dissect_function,
const char *progname, rpc_call_info_value *rpc_call)
{
guint32 length, rounded_length, seq;
proto_tree *gtree;
length = tvb_get_ntohl(tvb, offset);
rounded_length = rpc_roundup(length);
seq = tvb_get_ntohl(tvb, offset+4);
gtree = proto_tree_add_subtree(tree, tvb, offset,
4+rounded_length, ett_rpc_gss_data, NULL, "GSS Data");
proto_tree_add_uint(gtree, hf_rpc_authgss_data_length,
tvb, offset, 4, length);
proto_tree_add_uint(gtree, hf_rpc_authgss_seq,
tvb, offset+4, 4, seq);
offset += 8;
if (dissect_function != NULL) {
call_dissect_function(tvb, pinfo, gtree, offset,
dissect_function, progname, rpc_call);
}
offset += rounded_length - 4;
offset = dissect_rpc_authgss_token(tvb, tree, offset, pinfo, hf_rpc_authgss_checksum);
return offset;
}
static int
dissect_rpc_authgss_priv_data(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo _U_)
{
int length;
length = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_rpc_authgss_data_length,
tvb, offset, 4, length);
offset += 4;
proto_tree_add_item(tree, hf_rpc_authgss_data, tvb, offset, length,
ENC_NA);
if (!spnego_krb5_wrap_handle) {
offset += length;
return offset;
}
call_dissector(spnego_krb5_wrap_handle,
tvb_new_subset_remaining(tvb, offset),
pinfo, tree);
if (!pinfo->gssapi_decrypted_tvb) {
offset += length;
return offset;
}
offset += length;
return offset;
}
int
dissect_rpc_indir_call(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, int args_id, guint32 prog, guint32 vers, guint32 proc)
{
conversation_t* conversation;
static address null_address = { AT_NONE, -1, 0, NULL };
rpc_proc_info_key key;
rpc_proc_info_value *value;
rpc_call_info_value *rpc_call;
dissect_function_t *dissect_function = NULL;
rpc_conv_info_t *rpc_conv_info=NULL;
guint32 xid;
key.prog = prog;
key.vers = vers;
key.proc = proc;
if ((value = (rpc_proc_info_value *)g_hash_table_lookup(rpc_procs,&key)) != NULL) {
dissect_function = value->dissect_call;
if (pinfo->ptype == PT_TCP) {
conversation = find_conversation(pinfo->fd->num, &pinfo->src,
&pinfo->dst, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
} else {
conversation = find_conversation(pinfo->fd->num, &pinfo->src,
&null_address, pinfo->ptype, pinfo->destport,
0, NO_ADDR_B|NO_PORT_B);
}
if (conversation == NULL) {
if (pinfo->ptype == PT_TCP) {
conversation = conversation_new(pinfo->fd->num, &pinfo->src,
&pinfo->dst, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
} else {
conversation = conversation_new(pinfo->fd->num, &pinfo->src,
&null_address, pinfo->ptype, pinfo->destport,
0, NO_ADDR2|NO_PORT2);
}
}
rpc_conv_info = (rpc_conv_info_t *)conversation_get_proto_data(conversation, proto_rpc);
if (!rpc_conv_info) {
rpc_conv_info = wmem_new(wmem_file_scope(), rpc_conv_info_t);
rpc_conv_info->xids=wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_rpc, rpc_conv_info);
}
conversation_set_dissector(conversation,
(pinfo->ptype == PT_TCP) ? rpc_tcp_handle : rpc_handle);
xid = tvb_get_ntohl(tvb, offset);
rpc_call = (rpc_call_info_value *)wmem_tree_lookup32(rpc_conv_info->xids, xid);
if (rpc_call == NULL) {
rpc_call = wmem_new(wmem_file_scope(), rpc_call_info_value);
rpc_call->req_num = 0;
rpc_call->rep_num = 0;
rpc_call->prog = prog;
rpc_call->vers = vers;
rpc_call->proc = proc;
rpc_call->private_data = NULL;
rpc_call->flavor = FLAVOR_NOT_GSSAPI;
rpc_call->gss_proc = 0;
rpc_call->gss_svc = 0;
rpc_call->proc_info = value;
wmem_tree_insert32(rpc_conv_info->xids, xid, (void *)rpc_call);
}
}
else {
offset = dissect_rpc_data(tvb, tree, args_id,
offset);
return offset;
}
if ( tree )
{
proto_tree_add_text(tree, tvb, offset, 4,
"Argument length: %u",
tvb_get_ntohl(tvb, offset));
}
offset += 4;
offset = call_dissect_function(tvb, pinfo, tree, offset,
dissect_function, NULL, rpc_call);
return offset;
}
int
dissect_rpc_indir_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, int result_id, int prog_id, int vers_id, int proc_id)
{
conversation_t* conversation;
static address null_address = { AT_NONE, -1, 0, NULL };
rpc_call_info_value *rpc_call;
const char *procname=NULL;
dissect_function_t *dissect_function = NULL;
rpc_conv_info_t *rpc_conv_info=NULL;
guint32 xid;
if (pinfo->ptype == PT_TCP) {
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
} else {
conversation = find_conversation(pinfo->fd->num, &pinfo->dst, &null_address,
pinfo->ptype, pinfo->srcport, 0, NO_ADDR_B|NO_PORT_B);
}
if (conversation == NULL) {
offset = dissect_rpc_data(tvb, tree, result_id,
offset);
return offset;
}
rpc_conv_info = (rpc_conv_info_t *)conversation_get_proto_data(conversation, proto_rpc);
if (!rpc_conv_info) {
rpc_conv_info = wmem_new(wmem_file_scope(), rpc_conv_info_t);
rpc_conv_info->xids=wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_rpc, rpc_conv_info);
}
xid = tvb_get_ntohl(tvb, 0);
rpc_call = (rpc_call_info_value *)wmem_tree_lookup32(rpc_conv_info->xids, xid);
if (rpc_call == NULL) {
offset = dissect_rpc_data(tvb, tree, result_id,
offset);
return offset;
}
if (rpc_call->proc_info != NULL) {
dissect_function = rpc_call->proc_info->dissect_reply;
if (rpc_call->proc_info->name != NULL) {
procname = rpc_call->proc_info->name;
}
else {
procname=wmem_strdup_printf(wmem_packet_scope(), "proc-%u", rpc_call->proc);
}
}
else {
#if 0
dissect_function = NULL;
#endif
procname=wmem_strdup_printf(wmem_packet_scope(), "proc-%u", rpc_call->proc);
}
if ( tree )
{
proto_item *tmp_item;
tmp_item=proto_tree_add_uint_format(tree, prog_id, tvb,
0, 0, rpc_call->prog, "Program: %s (%u)",
rpc_prog_name(rpc_call->prog), rpc_call->prog);
PROTO_ITEM_SET_GENERATED(tmp_item);
tmp_item=proto_tree_add_uint(tree, vers_id, tvb, 0, 0, rpc_call->vers);
PROTO_ITEM_SET_GENERATED(tmp_item);
tmp_item=proto_tree_add_uint_format(tree, proc_id, tvb,
0, 0, rpc_call->proc, "Procedure: %s (%u)",
procname, rpc_call->proc);
PROTO_ITEM_SET_GENERATED(tmp_item);
}
if (dissect_function == NULL) {
offset = dissect_rpc_data(tvb, tree, result_id,
offset);
return offset;
}
proto_tree_add_text(tree, tvb, offset, 4, "Argument length: %u",
tvb_get_ntohl(tvb, offset));
offset += 4;
offset = call_dissect_function(tvb, pinfo, tree, offset,
dissect_function, NULL, rpc_call);
return offset;
}
static void
dissect_rpc_continuation(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *rpc_item;
proto_tree *rpc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RPC");
col_set_str(pinfo->cinfo, COL_INFO, "Continuation");
if (tree) {
rpc_item = proto_tree_add_item(tree, proto_rpc, tvb, 0, -1, ENC_NA);
rpc_tree = proto_item_add_subtree(rpc_item, ett_rpc);
proto_tree_add_text(rpc_tree, tvb, 0, -1, "Continuation data");
}
}
static void
make_fake_rpc_prog_if_needed (rpc_prog_info_key *prpc_prog_key, guint prog_ver)
{
if(prog_ver>10){
return;
}
if(g_hash_table_lookup(rpc_progs, prpc_prog_key) == NULL) {
int proto_rpc_unknown_program;
char *NAME, *Name, *name;
static const vsff unknown_proc[] = {
{ 0,"NULL",NULL,NULL },
{ 0,NULL,NULL,NULL }
};
NAME = g_strdup_printf("Unknown RPC Program:%d",prpc_prog_key->prog);
Name = g_strdup_printf("RPC:%d",prpc_prog_key->prog);
name = g_strdup_printf("rpc%d",prpc_prog_key->prog);
proto_rpc_unknown_program = proto_register_protocol(NAME, Name, name);
rpc_init_prog(proto_rpc_unknown_program, prpc_prog_key->prog, ett_rpc_unknown_program);
rpc_init_proc_table(prpc_prog_key->prog, prog_ver, unknown_proc, hf_rpc_procedure);
}
}
static gboolean
dissect_rpc_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
tvbuff_t *frag_tvb, fragment_head *ipfd_head, gboolean is_tcp,
guint32 rpc_rm, gboolean first_pdu)
{
guint32 msg_type;
rpc_call_info_value *rpc_call = NULL;
rpc_prog_info_value *rpc_prog = NULL;
rpc_prog_info_key rpc_prog_key;
unsigned int xid;
unsigned int rpcvers;
unsigned int prog = 0;
unsigned int vers = 0;
unsigned int proc = 0;
flavor_t flavor = FLAVOR_UNKNOWN;
unsigned int gss_proc = 0;
unsigned int gss_svc = 0;
protocol_t *proto = NULL;
int proto_id = 0;
int ett = 0;
int procedure_hf;
unsigned int reply_state;
unsigned int accept_state;
unsigned int reject_state;
const char *msg_type_name = NULL;
const char *progname = NULL;
const char *procname = NULL;
unsigned int vers_low;
unsigned int vers_high;
unsigned int auth_state;
proto_item *rpc_item = NULL;
proto_tree *rpc_tree = NULL;
proto_item *pitem = NULL;
proto_tree *ptree = NULL;
int offset = (is_tcp && tvb == frag_tvb) ? 4 : 0;
rpc_proc_info_key key;
rpc_proc_info_value *value = NULL;
conversation_t* conversation;
static address null_address = { AT_NONE, -1, 0, NULL };
nstime_t ns;
dissect_function_t *dissect_function = NULL;
gboolean dissect_rpc_flag = TRUE;
rpc_conv_info_t *rpc_conv_info=NULL;
if (!tvb_bytes_exist(tvb, offset, 8)) {
return FALSE;
}
msg_type = tvb_get_ntohl(tvb, offset + 4);
switch (msg_type) {
case RPC_CALL:
if (!tvb_bytes_exist(tvb, offset, 16)) {
return FALSE;
}
rpc_prog_key.prog = tvb_get_ntohl(tvb, offset + 12);
if (tvb_get_ntohl(tvb, offset + 8) != 2 ){
return FALSE;
}
if(rpc_dissect_unknown_programs){
guint32 version;
if(rpc_prog_key.prog==0 || rpc_prog_key.prog==0xffffffff){
return FALSE;
}
version=tvb_get_ntohl(tvb, offset+16);
make_fake_rpc_prog_if_needed (&rpc_prog_key, version);
}
if( (rpc_prog = (rpc_prog_info_value *)g_hash_table_lookup(rpc_progs, &rpc_prog_key)) == NULL) {
return FALSE;
}
break;
case RPC_REPLY:
if (pinfo->ptype == PT_TCP) {
conversation = find_conversation(pinfo->fd->num, &pinfo->src,
&pinfo->dst, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
} else {
conversation = find_conversation(pinfo->fd->num, &pinfo->dst,
&null_address, pinfo->ptype, pinfo->srcport,
0, NO_ADDR_B|NO_PORT_B);
}
if (conversation == NULL) {
return FALSE;
}
rpc_conv_info = (rpc_conv_info_t *)conversation_get_proto_data(conversation, proto_rpc);
if (!rpc_conv_info) {
rpc_conv_info = wmem_new(wmem_file_scope(), rpc_conv_info_t);
rpc_conv_info->xids=wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_rpc, rpc_conv_info);
}
xid = tvb_get_ntohl(tvb, offset);
rpc_call = (rpc_call_info_value *)wmem_tree_lookup32(rpc_conv_info->xids, xid);
if (rpc_call == NULL) {
if ((! rpc_find_fragment_start) || (pinfo->ptype != PT_TCP)) {
return FALSE;
}
rpc_call = wmem_new(wmem_file_scope(), rpc_call_info_value);
rpc_call->req_num = 0;
rpc_call->rep_num = pinfo->fd->num;
rpc_call->prog = 0;
rpc_call->vers = 0;
rpc_call->proc = 0;
rpc_call->private_data = NULL;
rpc_call->xid = xid;
rpc_call->flavor = FLAVOR_NOT_GSSAPI;
rpc_call->gss_proc = 0;
rpc_call->gss_svc = 0;
rpc_call->proc_info = value;
rpc_call->req_time = pinfo->fd->abs_ts;
wmem_tree_insert32(rpc_conv_info->xids, xid, (void *)rpc_call);
rpc_prog_key.prog = rpc_call->prog;
}
rpc_call->request=FALSE;
break;
default:
return FALSE;
}
if (is_tcp) {
if (!(rpc_rm & RPC_RM_LASTFRAG)) {
if (rpc_defragment)
return TRUE;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RPC");
rpc_item = proto_tree_add_item(tree, proto_rpc, tvb, 0, -1,
ENC_NA);
rpc_tree = proto_item_add_subtree(rpc_item, ett_rpc);
if (is_tcp) {
show_rpc_fraginfo(tvb, frag_tvb, rpc_tree, rpc_rm,
ipfd_head, pinfo);
}
xid = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(rpc_tree,hf_rpc_xid, tvb,
offset, 4, ENC_BIG_ENDIAN);
msg_type_name = val_to_str(msg_type,rpc_msg_type,"%u");
if (rpc_tree) {
proto_tree_add_uint(rpc_tree, hf_rpc_msgtype, tvb,
offset+4, 4, msg_type);
proto_item_append_text(rpc_item, ", Type:%s XID:0x%08x", msg_type_name, xid);
}
offset += 8;
switch (msg_type) {
case RPC_CALL:
proto = rpc_prog->proto;
proto_id = rpc_prog->proto_id;
ett = rpc_prog->ett;
progname = rpc_prog->progname;
rpcvers = tvb_get_ntohl(tvb, offset);
if (rpc_tree) {
proto_tree_add_uint(rpc_tree,
hf_rpc_version, tvb, offset, 4, rpcvers);
}
prog = tvb_get_ntohl(tvb, offset + 4);
if (rpc_tree) {
proto_tree_add_uint_format_value(rpc_tree,
hf_rpc_program, tvb, offset+4, 4, prog,
"%s (%u)", progname, prog);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, progname);
vers = tvb_get_ntohl(tvb, offset+8);
if (rpc_tree) {
proto_tree_add_uint(rpc_tree,
hf_rpc_programversion, tvb, offset+8, 4, vers);
}
proc = tvb_get_ntohl(tvb, offset+12);
key.prog = prog;
key.vers = vers;
key.proc = proc;
if ((value = (rpc_proc_info_value *)g_hash_table_lookup(rpc_procs,&key)) != NULL) {
dissect_function = value->dissect_call;
procname = value->name;
}
else {
#if 0
dissect_function = NULL;
#endif
procname=wmem_strdup_printf(wmem_packet_scope(), "proc-%u", proc);
}
if (tvb_bytes_exist(tvb, offset+16, 4)) {
switch (tvb_get_ntohl(tvb, offset+16)) {
case RPCSEC_GSS:
if (tvb_bytes_exist(tvb, offset+28, 8)) {
flavor = FLAVOR_GSSAPI;
gss_proc = tvb_get_ntohl(tvb, offset+28);
gss_svc = tvb_get_ntohl(tvb, offset+36);
} else {
flavor = FLAVOR_GSSAPI_NO_INFO;
}
break;
case AUTH_GSSAPI:
if (tvb_bytes_exist(tvb, offset+28, 4)) {
if (tvb_get_ntohl(tvb, offset+28)) {
flavor = FLAVOR_AUTHGSSAPI_MSG;
gss_proc = proc;
procname = val_to_str(gss_proc,
rpc_authgssapi_proc, "Unknown (%d)");
} else {
flavor = FLAVOR_AUTHGSSAPI;
}
}
break;
default:
flavor = FLAVOR_NOT_GSSAPI;
break;
}
}
if (rpc_tree) {
proto_tree_add_uint_format_value(rpc_tree,
hf_rpc_procedure, tvb, offset+12, 4, proc,
"%s (%u)", procname, proc);
}
if (first_pdu)
col_clear(pinfo->cinfo, COL_INFO);
else
col_append_str(pinfo->cinfo, COL_INFO, " ; ");
if (vers==4 && prog==NFS_PROGRAM && !strcmp(procname, "COMPOUND"))
col_append_fstr(pinfo->cinfo, COL_INFO,"V%u %s", vers,
msg_type_name);
else
col_append_fstr(pinfo->cinfo, COL_INFO,"V%u %s %s",
vers, procname, msg_type_name);
if (pinfo->ptype == PT_TCP) {
conversation = find_conversation(pinfo->fd->num, &pinfo->src,
&pinfo->dst, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
} else {
conversation = find_conversation(pinfo->fd->num, &pinfo->src,
&null_address, pinfo->ptype, pinfo->destport,
0, NO_ADDR_B|NO_PORT_B);
}
if (conversation == NULL) {
if (pinfo->ptype == PT_TCP) {
conversation = conversation_new(pinfo->fd->num, &pinfo->src,
&pinfo->dst, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
} else {
conversation = conversation_new(pinfo->fd->num, &pinfo->src,
&null_address, pinfo->ptype, pinfo->destport,
0, NO_ADDR2|NO_PORT2);
}
}
rpc_conv_info = (rpc_conv_info_t *)conversation_get_proto_data(conversation, proto_rpc);
if (!rpc_conv_info) {
rpc_conv_info = wmem_new(wmem_file_scope(), rpc_conv_info_t);
rpc_conv_info->xids=wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_rpc, rpc_conv_info);
}
conversation_set_dissector(conversation,
(pinfo->ptype == PT_TCP) ? rpc_tcp_handle : rpc_handle);
rpc_call = (rpc_call_info_value *)wmem_tree_lookup32(rpc_conv_info->xids, xid);
if (rpc_call) {
if (pinfo->fd->num != rpc_call->req_num) {
col_prepend_fstr(pinfo->cinfo, COL_INFO,
"[RPC retransmission of #%d]",
rpc_call->req_num);
proto_tree_add_item(rpc_tree, hf_rpc_dup, tvb,
0, 0, ENC_NA);
proto_tree_add_uint(rpc_tree, hf_rpc_call_dup,
tvb, 0,0, rpc_call->req_num);
}
if(rpc_call->rep_num){
col_append_fstr(pinfo->cinfo, COL_INFO," (Reply In %d)", rpc_call->rep_num);
}
} else {
rpc_call = wmem_new(wmem_file_scope(), rpc_call_info_value);
rpc_call->req_num = pinfo->fd->num;
rpc_call->rep_num = 0;
rpc_call->prog = prog;
rpc_call->vers = vers;
rpc_call->proc = proc;
rpc_call->private_data = NULL;
rpc_call->xid = xid;
rpc_call->flavor = flavor;
rpc_call->gss_proc = gss_proc;
rpc_call->gss_svc = gss_svc;
rpc_call->proc_info = value;
rpc_call->req_time = pinfo->fd->abs_ts;
wmem_tree_insert32(rpc_conv_info->xids, xid, (void *)rpc_call);
}
if(rpc_call->rep_num){
proto_item *tmp_item;
tmp_item=proto_tree_add_uint_format(rpc_tree, hf_rpc_reqframe,
tvb, 0, 0, rpc_call->rep_num,
"The reply to this request is in frame %u",
rpc_call->rep_num);
PROTO_ITEM_SET_GENERATED(tmp_item);
}
offset += 16;
offset = dissect_rpc_cred(tvb, rpc_tree, offset, pinfo, rpc_conv_info);
rpc_call->request=TRUE;
if (gss_proc == RPCSEC_GSS_DESTROY) {
break;
}
offset = dissect_rpc_verf(tvb, rpc_tree, offset, msg_type, pinfo);
break;
case RPC_REPLY:
prog = rpc_call->prog;
vers = rpc_call->vers;
proc = rpc_call->proc;
flavor = rpc_call->flavor;
gss_proc = rpc_call->gss_proc;
gss_svc = rpc_call->gss_svc;
if (rpc_call->proc_info != NULL) {
dissect_function = rpc_call->proc_info->dissect_reply;
if (rpc_call->proc_info->name != NULL) {
procname = rpc_call->proc_info->name;
}
else {
procname=wmem_strdup_printf(wmem_packet_scope(), "proc-%u", proc);
}
}
else {
#if 0
dissect_function = NULL;
#endif
procname=wmem_strdup_printf(wmem_packet_scope(), "proc-%u", proc);
}
if (flavor == FLAVOR_AUTHGSSAPI_MSG) {
procname = val_to_str_const(gss_proc, rpc_authgssapi_proc, "(null)");
}
rpc_prog_key.prog = prog;
if ((rpc_prog = (rpc_prog_info_value *)g_hash_table_lookup(rpc_progs,&rpc_prog_key)) == NULL) {
proto = NULL;
proto_id = 0;
ett = 0;
progname = "Unknown";
}
else {
proto = rpc_prog->proto;
proto_id = rpc_prog->proto_id;
ett = rpc_prog->ett;
progname = rpc_prog->progname;
col_set_str(pinfo->cinfo, COL_PROTOCOL, progname);
}
if (first_pdu)
col_clear(pinfo->cinfo, COL_INFO);
else
col_append_str(pinfo->cinfo, COL_INFO, " ; ");
if (vers==4 && prog==NFS_PROGRAM && !strcmp(procname, "COMPOUND"))
col_append_fstr(pinfo->cinfo, COL_INFO,"V%u %s",
vers, msg_type_name);
else
col_append_fstr(pinfo->cinfo, COL_INFO,"V%u %s %s",
vers, procname, msg_type_name);
if (rpc_tree) {
proto_item *tmp_item;
tmp_item=proto_tree_add_uint_format_value(rpc_tree,
hf_rpc_program, tvb, 0, 0, prog,
"%s (%u)", progname, prog);
PROTO_ITEM_SET_GENERATED(tmp_item);
tmp_item=proto_tree_add_uint(rpc_tree,
hf_rpc_programversion, tvb, 0, 0, vers);
PROTO_ITEM_SET_GENERATED(tmp_item);
tmp_item=proto_tree_add_uint_format_value(rpc_tree,
hf_rpc_procedure, tvb, 0, 0, proc,
"%s (%u)", procname, proc);
PROTO_ITEM_SET_GENERATED(tmp_item);
}
reply_state = tvb_get_ntohl(tvb,offset);
if (rpc_tree) {
proto_tree_add_uint(rpc_tree, hf_rpc_state_reply, tvb,
offset, 4, reply_state);
}
offset += 4;
if(rpc_call && rpc_call->req_num){
proto_item *tmp_item;
tmp_item=proto_tree_add_uint_format(rpc_tree, hf_rpc_repframe,
tvb, 0, 0, rpc_call->req_num,
"This is a reply to a request in frame %u",
rpc_call->req_num);
PROTO_ITEM_SET_GENERATED(tmp_item);
nstime_delta(&ns, &pinfo->fd->abs_ts, &rpc_call->req_time);
tmp_item=proto_tree_add_time(rpc_tree, hf_rpc_time, tvb, offset, 0,
&ns);
PROTO_ITEM_SET_GENERATED(tmp_item);
col_append_fstr(pinfo->cinfo, COL_INFO," (Call In %d)", rpc_call->req_num);
}
if ((!rpc_call) || (rpc_call->rep_num == 0)) {
rpc_call->rep_num = pinfo->fd->num;
} else {
if (rpc_call->rep_num != pinfo->fd->num) {
proto_item *tmp_item;
col_prepend_fstr(pinfo->cinfo, COL_INFO,
"[RPC duplicate of #%d]", rpc_call->rep_num);
tmp_item=proto_tree_add_item(rpc_tree,
hf_rpc_dup, tvb, 0,0, ENC_NA);
PROTO_ITEM_SET_GENERATED(tmp_item);
tmp_item=proto_tree_add_uint(rpc_tree,
hf_rpc_reply_dup, tvb, 0,0, rpc_call->rep_num);
PROTO_ITEM_SET_GENERATED(tmp_item);
}
}
switch (reply_state) {
case MSG_ACCEPTED:
offset = dissect_rpc_verf(tvb, rpc_tree, offset, msg_type, pinfo);
accept_state = tvb_get_ntohl(tvb,offset);
if (rpc_tree) {
proto_tree_add_uint(rpc_tree, hf_rpc_state_accept, tvb,
offset, 4, accept_state);
}
offset += 4;
switch (accept_state) {
case SUCCESS:
break;
case PROG_MISMATCH:
vers_low = tvb_get_ntohl(tvb,offset);
vers_high = tvb_get_ntohl(tvb,offset+4);
if (rpc_tree) {
proto_tree_add_uint(rpc_tree,
hf_rpc_programversion_min,
tvb, offset, 4, vers_low);
proto_tree_add_uint(rpc_tree,
hf_rpc_programversion_max,
tvb, offset+4, 4, vers_high);
}
offset += 8;
dissect_rpc_flag = FALSE;
break;
default:
dissect_rpc_flag = FALSE;
break;
}
break;
case MSG_DENIED:
reject_state = tvb_get_ntohl(tvb,offset);
if (rpc_tree) {
proto_tree_add_uint(rpc_tree,
hf_rpc_state_reject, tvb, offset, 4,
reject_state);
}
offset += 4;
if (reject_state==RPC_MISMATCH) {
vers_low = tvb_get_ntohl(tvb,offset);
vers_high = tvb_get_ntohl(tvb,offset+4);
if (rpc_tree) {
proto_tree_add_uint(rpc_tree,
hf_rpc_version_min,
tvb, offset, 4, vers_low);
proto_tree_add_uint(rpc_tree,
hf_rpc_version_max,
tvb, offset+4, 4, vers_high);
}
offset += 8;
} else if (reject_state==AUTH_ERROR) {
auth_state = tvb_get_ntohl(tvb,offset);
if (rpc_tree) {
proto_tree_add_uint(rpc_tree,
hf_rpc_state_auth, tvb, offset, 4,
auth_state);
}
offset += 4;
}
dissect_rpc_flag = FALSE;
break;
default:
dissect_rpc_flag = FALSE;
break;
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
if (rpc_item) {
if (offset < 0)
THROW(ReportedBoundsError);
tvb_ensure_bytes_exist(tvb, offset, 0);
proto_item_set_end(rpc_item, tvb, offset);
}
if (!dissect_rpc_flag) {
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset), pinfo, rpc_tree);
return TRUE;
}
tap_queue_packet(rpc_tap, pinfo, rpc_call);
pinfo->decrypt_gssapi_tvb=DECRYPT_GSSAPI_NORMAL;
pinfo->gssapi_wrap_tvb=NULL;
pinfo->gssapi_encrypted_tvb=NULL;
pinfo->gssapi_decrypted_tvb=NULL;
if (flavor == FLAVOR_GSSAPI && gss_proc == RPCSEC_GSS_DATA && gss_svc == RPCSEC_GSS_SVC_PRIVACY) {
proto_tree *gss_tree;
gss_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_gss_wrap, NULL, "GSS-Wrap");
offset = dissect_rpc_authgss_priv_data(tvb, gss_tree, offset, pinfo);
if (pinfo->gssapi_decrypted_tvb) {
proto_tree_add_item(gss_tree, hf_rpc_authgss_seq, pinfo->gssapi_decrypted_tvb, 0, 4, ENC_BIG_ENDIAN);
tvb = pinfo->gssapi_decrypted_tvb;
offset = 4;
}
}
if (tree && (flavor != FLAVOR_AUTHGSSAPI_MSG)) {
proto_item *tmp_item;
pitem = proto_tree_add_item(tree, proto_id, tvb, offset, -1, ENC_NA);
ptree = proto_item_add_subtree(pitem, ett);
tmp_item=proto_tree_add_uint(ptree,
hf_rpc_programversion, tvb, 0, 0, vers);
PROTO_ITEM_SET_GENERATED(tmp_item);
if (rpc_prog && (rpc_prog->procedure_hfs->len > vers) )
procedure_hf = g_array_index(rpc_prog->procedure_hfs, int, vers);
else {
procedure_hf = 0;
}
if (procedure_hf != 0 && procedure_hf != -1) {
tmp_item=proto_tree_add_uint(ptree,
procedure_hf, tvb, 0, 0, proc);
PROTO_ITEM_SET_GENERATED(tmp_item);
} else {
tmp_item=proto_tree_add_uint_format_value(ptree,
hf_rpc_procedure, tvb, 0, 0, proc,
"%s (%u)", procname, proc);
PROTO_ITEM_SET_GENERATED(tmp_item);
}
}
if( (proto==0) || !proto_is_protocol_enabled(proto)){
dissect_function = NULL;
}
if (tvb_length_remaining(tvb, offset) == 0) {
return TRUE;
}
switch (flavor) {
case FLAVOR_UNKNOWN:
proto_tree_add_text(ptree, tvb, offset, -1,
"Unknown authentication flavor - cannot dissect");
return TRUE;
case FLAVOR_NOT_GSSAPI:
offset = call_dissect_function(tvb, pinfo, ptree, offset,
dissect_function, progname, rpc_call);
break;
case FLAVOR_GSSAPI_NO_INFO:
proto_tree_add_text(ptree, tvb, offset, -1,
"GSS-API authentication, but procedure and service unknown - cannot dissect");
return TRUE;
case FLAVOR_GSSAPI:
switch (gss_proc) {
case RPCSEC_GSS_INIT:
case RPCSEC_GSS_CONTINUE_INIT:
if (msg_type == RPC_CALL) {
offset = dissect_rpc_authgss_initarg(tvb,
ptree, offset, pinfo);
}
else {
offset = dissect_rpc_authgss_initres(tvb,
ptree, offset, pinfo, rpc_conv_info);
}
break;
case RPCSEC_GSS_DATA:
if (gss_svc == RPCSEC_GSS_SVC_NONE) {
offset = call_dissect_function(tvb,
pinfo, ptree, offset,
dissect_function,
progname, rpc_call);
}
else if (gss_svc == RPCSEC_GSS_SVC_INTEGRITY) {
offset = dissect_rpc_authgss_integ_data(tvb,
pinfo, ptree, offset,
dissect_function,
progname, rpc_call);
}
else if (gss_svc == RPCSEC_GSS_SVC_PRIVACY) {
if (pinfo->gssapi_decrypted_tvb) {
call_dissect_function(
pinfo->gssapi_decrypted_tvb,
pinfo, ptree, 4,
dissect_function,
progname, rpc_call);
offset = tvb_length(pinfo->gssapi_decrypted_tvb);
}
}
break;
default:
break;
}
break;
case FLAVOR_AUTHGSSAPI_MSG:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RPC");
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s %s XID 0x%x",
val_to_str(gss_proc, rpc_authgssapi_proc, "Unknown (%d)"),
msg_type_name, xid);
switch (gss_proc) {
case AUTH_GSSAPI_INIT:
case AUTH_GSSAPI_CONTINUE_INIT:
case AUTH_GSSAPI_MSG:
if (msg_type == RPC_CALL) {
offset = dissect_rpc_authgssapi_initarg(tvb,
rpc_tree, offset, pinfo);
} else {
offset = dissect_rpc_authgssapi_initres(tvb,
rpc_tree, offset, pinfo);
}
break;
case AUTH_GSSAPI_DESTROY:
offset = dissect_rpc_data(tvb, rpc_tree,
hf_rpc_authgss_data, offset);
break;
case AUTH_GSSAPI_EXIT:
break;
}
if (rpc_item) {
proto_item_set_end(rpc_item, tvb, offset);
}
break;
case FLAVOR_AUTHGSSAPI:
offset = dissect_auth_gssapi_data(tvb, ptree, offset);
break;
}
if (tvb_length_remaining(tvb, offset) > 0) {
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset), pinfo, ptree);
}
if(nfs_fhandle_reqrep_matching){
switch (msg_type) {
case RPC_CALL:
if(rpc_call && rpc_call->rep_num){
dissect_fhandle_hidden(pinfo,
ptree, rpc_call->rep_num);
}
break;
case RPC_REPLY:
if(rpc_call && rpc_call->req_num){
dissect_fhandle_hidden(pinfo,
ptree, rpc_call->req_num);
}
break;
}
}
return TRUE;
}
static gboolean
dissect_rpc_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_rpc_message(tvb, pinfo, tree, NULL, NULL, FALSE, 0,
TRUE);
}
static void
dissect_rpc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (!dissect_rpc_message(tvb, pinfo, tree, NULL, NULL, FALSE, 0,
TRUE)) {
if (tvb_length(tvb) != 0)
dissect_rpc_continuation(tvb, pinfo, tree);
}
}
static guint
rpc_fragment_hash(gconstpointer k)
{
const rpc_fragment_key *key = (const rpc_fragment_key *)k;
return key->conv_id + key->seq;
}
static gint
rpc_fragment_equal(gconstpointer k1, gconstpointer k2)
{
const rpc_fragment_key *key1 = (const rpc_fragment_key *)k1;
const rpc_fragment_key *key2 = (const rpc_fragment_key *)k2;
return key1->conv_id == key2->conv_id &&
key1->seq == key2->seq && key1->port == key2->port;
}
static void
show_rpc_fragheader(tvbuff_t *tvb, proto_tree *tree, guint32 rpc_rm)
{
proto_tree *hdr_tree;
guint32 fraglen;
if (tree) {
fraglen = rpc_rm & RPC_RM_FRAGLEN;
hdr_tree = proto_tree_add_subtree_format(tree, tvb, 0, 4,
ett_rpc_fraghdr, NULL, "Fragment header: %s%u %s",
(rpc_rm & RPC_RM_LASTFRAG) ? "Last fragment, " : "",
fraglen, plurality(fraglen, "byte", "bytes"));
proto_tree_add_boolean(hdr_tree, hf_rpc_lastfrag, tvb, 0, 4,
rpc_rm);
proto_tree_add_uint(hdr_tree, hf_rpc_fraglen, tvb, 0, 4,
rpc_rm);
}
}
static void
show_rpc_fragment(tvbuff_t *tvb, proto_tree *tree, guint32 rpc_rm)
{
if (tree) {
show_rpc_fragheader(tvb, tree, rpc_rm);
proto_tree_add_text(tree, tvb, 4, -1, "Fragment Data");
}
}
static void
make_frag_tree(tvbuff_t *tvb, proto_tree *tree, int proto, gint ett,
guint32 rpc_rm)
{
proto_item *frag_item;
proto_tree *frag_tree;
if (tree == NULL)
return;
frag_item = proto_tree_add_protocol_format(tree, proto, tvb, 0, -1,
"%s Fragment", proto_get_protocol_name(proto));
frag_tree = proto_item_add_subtree(frag_item, ett);
show_rpc_fragment(tvb, frag_tree, rpc_rm);
}
void
show_rpc_fraginfo(tvbuff_t *tvb, tvbuff_t *frag_tvb, proto_tree *tree,
guint32 rpc_rm, fragment_head *ipfd_head, packet_info *pinfo)
{
proto_item *frag_tree_item;
if (tree == NULL)
return;
if (tvb != frag_tvb) {
show_rpc_fragment(frag_tvb, tree, rpc_rm);
show_fragment_tree(ipfd_head, &rpc_frag_items, tree, pinfo, tvb, &frag_tree_item);
} else {
show_rpc_fragheader(tvb, tree, rpc_rm);
}
}
static gboolean
call_message_dissector(tvbuff_t *tvb, tvbuff_t *rec_tvb, packet_info *pinfo,
proto_tree *tree, tvbuff_t *frag_tvb, rec_dissector_t dissector,
fragment_head *ipfd_head, guint32 rpc_rm, gboolean first_pdu)
{
const char *saved_proto;
volatile gboolean rpc_succeeded;
void *pd_save;
saved_proto = pinfo->current_proto;
rpc_succeeded = FALSE;
pd_save = pinfo->private_data;
TRY {
rpc_succeeded = (*dissector)(rec_tvb, pinfo, tree,
frag_tvb, ipfd_head, TRUE, rpc_rm, first_pdu);
}
CATCH_NONFATAL_ERRORS {
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
pinfo->current_proto = saved_proto;
pinfo->private_data = pd_save;
rpc_succeeded = TRUE;
}
ENDTRY;
return rpc_succeeded;
}
static int
dissect_rpc_fragment(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, rec_dissector_t dissector, gboolean is_heur,
int proto, int ett, gboolean defragment, gboolean first_pdu, struct tcpinfo *tcpinfo)
{
guint32 seq;
guint32 rpc_rm;
volatile guint32 len;
gint32 seglen;
gint tvb_len, tvb_reported_len;
tvbuff_t *frag_tvb;
gboolean rpc_succeeded;
gboolean save_fragmented;
rpc_fragment_key old_rfk, *rfk, *new_rfk;
conversation_t *conversation;
fragment_head *ipfd_head;
tvbuff_t *rec_tvb;
if (pinfo == NULL || tcpinfo == NULL) {
return 0;
}
seq = tcpinfo->seq + offset;
if (!tvb_bytes_exist(tvb, offset, 4)) {
return 0;
}
rpc_rm = tvb_get_ntohl(tvb, offset);
len = rpc_rm & RPC_RM_FRAGLEN;
if (len > max_rpc_tcp_pdu_size)
return 0;
if (rpc_desegment) {
seglen = tvb_length_remaining(tvb, offset + 4);
if ((gint)len > seglen && pinfo->can_desegment) {
if (is_heur)
return 0;
else {
pinfo->desegment_offset = offset;
pinfo->desegment_len = len - seglen;
return -((gint32) pinfo->desegment_len);
}
}
}
len += 4;
tvb_len = tvb_length_remaining(tvb, offset);
tvb_reported_len = tvb_reported_length_remaining(tvb, offset);
if (tvb_len > (gint)len)
tvb_len = len;
if (tvb_reported_len > (gint)len)
tvb_reported_len = len;
frag_tvb = tvb_new_subset(tvb, offset, tvb_len,
tvb_reported_len);
if (!defragment) {
rec_tvb = frag_tvb;
ipfd_head = NULL;
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
rpc_succeeded = call_message_dissector(tvb, rec_tvb, pinfo,
tree, frag_tvb, dissector, ipfd_head, rpc_rm, first_pdu);
pinfo->fragmented = save_fragmented;
if (!rpc_succeeded)
return 0;
return len;
}
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
if (conversation == NULL) {
conversation = conversation_new(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
}
old_rfk.conv_id = conversation->index;
old_rfk.seq = seq;
old_rfk.port = pinfo->srcport;
rfk = (rpc_fragment_key *)g_hash_table_lookup(rpc_reassembly_table, &old_rfk);
if (rfk == NULL) {
if (!(rpc_rm & RPC_RM_LASTFRAG)) {
if (!(*dissector)(frag_tvb, pinfo, tree, frag_tvb,
NULL, TRUE, rpc_rm, first_pdu))
return 0;
rfk = wmem_new(wmem_file_scope(), rpc_fragment_key);
rfk->conv_id = conversation->index;
rfk->seq = seq;
rfk->port = pinfo->srcport;
rfk->offset = 0;
rfk->start_seq = seq;
g_hash_table_insert(rpc_reassembly_table, rfk, rfk);
ipfd_head = fragment_add_multiple_ok(&rpc_fragment_table,
tvb, offset + 4,
pinfo, rfk->start_seq, NULL,
rfk->offset, len - 4, TRUE);
if (ipfd_head == NULL) {
new_rfk = wmem_new(wmem_file_scope(), rpc_fragment_key);
new_rfk->conv_id = rfk->conv_id;
new_rfk->seq = seq + len;
new_rfk->port = pinfo->srcport;
new_rfk->offset = rfk->offset + len - 4;
new_rfk->start_seq = rfk->start_seq;
g_hash_table_insert(rpc_reassembly_table, new_rfk,
new_rfk);
make_frag_tree(frag_tvb, tree, proto, ett,rpc_rm);
return len;
} else {
}
}
rec_tvb = frag_tvb;
ipfd_head = NULL;
} else {
ipfd_head = fragment_add_multiple_ok(&rpc_fragment_table,
tvb, offset + 4, pinfo, rfk->start_seq, NULL,
rfk->offset, len - 4, !(rpc_rm & RPC_RM_LASTFRAG));
if (ipfd_head == NULL) {
new_rfk = wmem_new(wmem_file_scope(), rpc_fragment_key);
new_rfk->conv_id = rfk->conv_id;
new_rfk->seq = seq + len;
new_rfk->port = pinfo->srcport;
new_rfk->offset = rfk->offset + len - 4;
new_rfk->start_seq = rfk->start_seq;
g_hash_table_insert(rpc_reassembly_table, new_rfk,
new_rfk);
make_frag_tree(frag_tvb, tree, proto, ett, rpc_rm);
return len;
}
if (!(rpc_rm & RPC_RM_LASTFRAG)) {
make_frag_tree(frag_tvb, tree, proto, ett, rpc_rm);
return len;
}
rec_tvb = tvb_new_chain(tvb, ipfd_head->tvb_data);
add_new_data_source(pinfo, rec_tvb, "Defragmented");
}
if (!call_message_dissector(tvb, rec_tvb, pinfo, tree,
frag_tvb, dissector, ipfd_head, rpc_rm, first_pdu))
return 0;
return len;
}
static int
find_rpc_over_tcp_reply_start(tvbuff_t *tvb, int offset)
{
const gint cbZeroTail = 4 * 4;
const gint ibPatternStart = 3 * 4;
const guint8 * pbWholeBuf;
const int NoMatch = -1;
gint ibSearchStart;
const guint8 * pbBuf;
gint cbInBuf;
guint32 ulMsgType;
guint32 ulRecMark;
int i;
cbInBuf = tvb_reported_length_remaining(tvb, offset);
ibSearchStart = ibPatternStart;
if (cbInBuf < (cbZeroTail + ibSearchStart)) {
return (NoMatch);
}
pbWholeBuf = tvb_get_ptr(tvb, offset, cbInBuf);
if (pbWholeBuf == NULL) {
return (NoMatch);
}
while ((cbInBuf - ibSearchStart) > cbZeroTail) {
pbBuf = pbWholeBuf + ibSearchStart + cbZeroTail - 1;
for (i = cbZeroTail; i > 0; i --)
{
if (*pbBuf != 0)
{
ibSearchStart += i;
pbBuf = NULL;
break;
}
pbBuf --;
}
if (pbBuf == NULL) {
continue;
}
ulMsgType = pntoh32 (pbWholeBuf + ibSearchStart - 4);
ulRecMark = pntoh32 (pbWholeBuf + ibSearchStart - ibPatternStart);
if ((ulMsgType == RPC_REPLY) &&
((ulRecMark & ~0x80000000) <= (unsigned) max_rpc_tcp_pdu_size)) {
return (offset + ibSearchStart - ibPatternStart);
}
ibSearchStart ++;
}
return (NoMatch);
}
static int
find_and_dissect_rpc_fragment(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, rec_dissector_t dissector,
gboolean is_heur,
int proto, int ett, gboolean defragment, struct tcpinfo* tcpinfo)
{
int offReply;
int len;
offReply = find_rpc_over_tcp_reply_start(tvb, offset);
if (offReply < 0) {
return (0);
}
len = dissect_rpc_fragment(tvb, offReply,
pinfo, tree,
dissector, is_heur, proto, ett,
defragment,
TRUE , tcpinfo);
if (len == 0)
{
return (0);
}
if (len > 0) {
len += offReply - offset;
}
else {
}
return (len);
}
static rpc_tcp_return_t
dissect_rpc_tcp_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean is_heur, struct tcpinfo* tcpinfo)
{
int offset = 0;
gboolean saw_rpc = FALSE;
gboolean first_pdu = TRUE;
int len;
while (tvb_reported_length_remaining(tvb, offset) != 0) {
len = dissect_rpc_fragment(tvb, offset, pinfo, tree,
dissect_rpc_message, is_heur, proto_rpc, ett_rpc,
rpc_defragment, first_pdu, tcpinfo);
if ((len == 0) && first_pdu && rpc_find_fragment_start) {
len = find_and_dissect_rpc_fragment(tvb, offset, pinfo, tree,
dissect_rpc_message, is_heur, proto_rpc, ett_rpc,
rpc_defragment, tcpinfo);
}
first_pdu = FALSE;
if (len < 0) {
return NEED_MORE_DATA;
}
if (len == 0) {
break;
}
col_set_fence(pinfo->cinfo, COL_INFO);
if(!pinfo->fd->flags.visited){
if(len>tvb_reported_length_remaining(tvb, offset)){
pinfo->want_pdu_tracking=2;
pinfo->bytes_until_next_pdu=len-tvb_reported_length_remaining(tvb, offset);
}
}
offset += len;
saw_rpc = TRUE;
}
return saw_rpc ? IS_RPC : IS_NOT_RPC;
}
static gboolean
dissect_rpc_tcp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
struct tcpinfo* tcpinfo = (struct tcpinfo *)data;
switch (dissect_rpc_tcp_common(tvb, pinfo, tree, TRUE, tcpinfo)) {
case IS_RPC:
return TRUE;
case IS_NOT_RPC:
return FALSE;
default:
DISSECTOR_ASSERT_NOT_REACHED();
return FALSE;
}
}
static int
dissect_rpc_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
struct tcpinfo* tcpinfo = (struct tcpinfo *)data;
if (dissect_rpc_tcp_common(tvb, pinfo, tree, FALSE, tcpinfo) == IS_NOT_RPC)
dissect_rpc_continuation(tvb, pinfo, tree);
return tvb_length(tvb);
}
static void
rpc_init_protocol(void)
{
if (rpc_reassembly_table != NULL) {
g_hash_table_destroy(rpc_reassembly_table);
rpc_reassembly_table = NULL;
}
rpc_reassembly_table = g_hash_table_new(rpc_fragment_hash,
rpc_fragment_equal);
reassembly_table_init(&rpc_fragment_table,
&addresses_ports_reassembly_table_functions);
}
void
proto_register_rpc(void)
{
static hf_register_info hf[] = {
{ &hf_rpc_reqframe, {
"Request Frame", "rpc.reqframe", FT_FRAMENUM, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_rpc_repframe, {
"Reply Frame", "rpc.repframe", FT_FRAMENUM, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_rpc_lastfrag, {
"Last Fragment", "rpc.lastfrag", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), RPC_RM_LASTFRAG, NULL, HFILL }},
{ &hf_rpc_fraglen, {
"Fragment Length", "rpc.fraglen", FT_UINT32, BASE_DEC,
NULL, RPC_RM_FRAGLEN, NULL, HFILL }},
{ &hf_rpc_xid, {
"XID", "rpc.xid", FT_UINT32, BASE_HEX_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rpc_msgtype, {
"Message Type", "rpc.msgtyp", FT_UINT32, BASE_DEC,
VALS(rpc_msg_type), 0, NULL, HFILL }},
{ &hf_rpc_state_reply, {
"Reply State", "rpc.replystat", FT_UINT32, BASE_DEC,
VALS(rpc_reply_state), 0, NULL, HFILL }},
{ &hf_rpc_state_accept, {
"Accept State", "rpc.state_accept", FT_UINT32, BASE_DEC,
VALS(rpc_accept_state), 0, NULL, HFILL }},
{ &hf_rpc_state_reject, {
"Reject State", "rpc.state_reject", FT_UINT32, BASE_DEC,
VALS(rpc_reject_state), 0, NULL, HFILL }},
{ &hf_rpc_state_auth, {
"Auth State", "rpc.state_auth", FT_UINT32, BASE_DEC,
VALS(rpc_auth_state), 0, NULL, HFILL }},
{ &hf_rpc_version, {
"RPC Version", "rpc.version", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rpc_version_min, {
"RPC Version (Minimum)", "rpc.version.min", FT_UINT32,
BASE_DEC, NULL, 0, "Program Version (Minimum)", HFILL }},
{ &hf_rpc_version_max, {
"RPC Version (Maximum)", "rpc.version.max", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rpc_program, {
"Program", "rpc.program", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rpc_programversion, {
"Program Version", "rpc.programversion", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rpc_programversion_min, {
"Program Version (Minimum)", "rpc.programversion.min", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rpc_programversion_max, {
"Program Version (Maximum)", "rpc.programversion.max", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rpc_procedure, {
"Procedure", "rpc.procedure", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rpc_auth_flavor, {
"Flavor", "rpc.auth.flavor", FT_UINT32, BASE_DEC,
VALS(rpc_auth_flavor), 0, NULL, HFILL }},
{ &hf_rpc_auth_length, {
"Length", "rpc.auth.length", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rpc_auth_stamp, {
"Stamp", "rpc.auth.stamp", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_rpc_auth_lk_owner, {
"Lock Owner", "rpc.auth.lk_owner", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_rpc_auth_pid, {
"PID", "rpc.auth.pid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rpc_auth_uid, {
"UID", "rpc.auth.uid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rpc_auth_gid, {
"GID", "rpc.auth.gid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgss_v, {
"GSS Version", "rpc.authgss.version", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgss_proc, {
"GSS Procedure", "rpc.authgss.procedure", FT_UINT32,
BASE_DEC, VALS(rpc_authgss_proc), 0, NULL, HFILL }},
{ &hf_rpc_authgss_seq, {
"GSS Sequence Number", "rpc.authgss.seqnum", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgss_svc, {
"GSS Service", "rpc.authgss.service", FT_UINT32,
BASE_DEC, VALS(rpc_authgss_svc), 0, NULL, HFILL }},
{ &hf_rpc_authgss_ctx, {
"GSS Context", "rpc.authgss.context", FT_BYTES,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgss_ctx_create_frame, {
"Created in frame", "rpc.authgss.context.created_frame", FT_FRAMENUM,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgss_ctx_destroy_frame, {
"Destroyed in frame", "rpc.authgss.context.destroyed_frame", FT_FRAMENUM,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgss_ctx_len, {
"GSS Context Length", "rpc.authgss.context.length", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgss_major, {
"GSS Major Status", "rpc.authgss.major", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgss_minor, {
"GSS Minor Status", "rpc.authgss.minor", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgss_window, {
"GSS Sequence Window", "rpc.authgss.window", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgss_token_length, {
"GSS Token Length", "rpc.authgss.token_length", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgss_data_length, {
"Length", "rpc.authgss.data.length", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgss_data, {
"GSS Data", "rpc.authgss.data", FT_BYTES,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgss_checksum, {
"GSS Checksum", "rpc.authgss.checksum", FT_BYTES,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgss_token, {
"GSS Token", "rpc.authgss.token", FT_BYTES,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgssapi_v, {
"AUTH_GSSAPI Version", "rpc.authgssapi.version",
FT_UINT32, BASE_DEC, NULL, 0, NULL,
HFILL }},
{ &hf_rpc_authgssapi_msg, {
"AUTH_GSSAPI Message", "rpc.authgssapi.message",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_yes_no), 0x0, NULL,
HFILL }},
{ &hf_rpc_authgssapi_msgv, {
"Msg Version", "rpc.authgssapi.msgversion",
FT_UINT32, BASE_DEC, NULL, 0, NULL,
HFILL }},
{ &hf_rpc_authgssapi_handle, {
"Client Handle", "rpc.authgssapi.handle",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authgssapi_isn, {
"Signed ISN", "rpc.authgssapi.isn",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authdes_namekind, {
"Namekind", "rpc.authdes.namekind", FT_UINT32, BASE_DEC,
VALS(rpc_authdes_namekind), 0, NULL, HFILL }},
{ &hf_rpc_authdes_netname, {
"Netname", "rpc.authdes.netname", FT_STRING,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authdes_convkey, {
"Conversation Key (encrypted)", "rpc.authdes.convkey", FT_UINT32,
BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authdes_window, {
"Window (encrypted)", "rpc.authdes.window", FT_UINT32,
BASE_HEX, NULL, 0, "Windows (encrypted)", HFILL }},
{ &hf_rpc_authdes_nickname, {
"Nickname", "rpc.authdes.nickname", FT_UINT32,
BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authdes_timestamp, {
"Timestamp (encrypted)", "rpc.authdes.timestamp", FT_UINT32,
BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authdes_windowverf, {
"Window verifier (encrypted)", "rpc.authdes.windowverf", FT_UINT32,
BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_rpc_authdes_timeverf, {
"Timestamp verifier (encrypted)", "rpc.authdes.timeverf", FT_UINT32,
BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_rpc_auth_machinename, {
"Machine Name", "rpc.auth.machinename", FT_STRING,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_rpc_dup, {
"Duplicate Call/Reply", "rpc.dup", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_rpc_call_dup, {
"Duplicate to the call in", "rpc.call.dup", FT_FRAMENUM, BASE_NONE,
NULL, 0, "This is a duplicate to the call in frame", HFILL }},
{ &hf_rpc_reply_dup, {
"Duplicate to the reply in", "rpc.reply.dup", FT_FRAMENUM, BASE_NONE,
NULL, 0, "This is a duplicate to the reply in frame", HFILL }},
{ &hf_rpc_value_follows, {
"Value Follows", "rpc.value_follows", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_yes_no), 0x0, NULL, HFILL }},
{ &hf_rpc_array_len, {
"num", "rpc.array.len", FT_UINT32, BASE_DEC,
NULL, 0, "Length of RPC array", HFILL }},
{ &hf_rpc_time, {
"Time from request", "rpc.time", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0, "Time between Request and Reply for ONC-RPC calls", HFILL }},
{ &hf_rpc_fragment_overlap,
{ "Fragment overlap", "rpc.fragment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }},
{ &hf_rpc_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "rpc.fragment.overlap.conflict", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }},
{ &hf_rpc_fragment_multiple_tails,
{ "Multiple tail fragments found", "rpc.fragment.multipletails", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }},
{ &hf_rpc_fragment_too_long_fragment,
{ "Fragment too long", "rpc.fragment.toolongfragment", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }},
{ &hf_rpc_fragment_error,
{ "Defragmentation error", "rpc.fragment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }},
{ &hf_rpc_fragment_count,
{ "Fragment count", "rpc.fragment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rpc_fragment,
{ "RPC Fragment", "rpc.fragment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rpc_fragments,
{ "RPC Fragments", "rpc.fragments", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rpc_reassembled_length,
{ "Reassembled RPC length", "rpc.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }},
};
static gint *ett[] = {
&ett_rpc,
&ett_rpc_fragments,
&ett_rpc_fragment,
&ett_rpc_fraghdr,
&ett_rpc_string,
&ett_rpc_cred,
&ett_rpc_verf,
&ett_rpc_gids,
&ett_rpc_gss_token,
&ett_rpc_gss_data,
&ett_rpc_array,
&ett_rpc_authgssapi_msg,
&ett_rpc_unknown_program,
&ett_gss_context,
&ett_gss_wrap,
};
module_t *rpc_module;
proto_rpc = proto_register_protocol("Remote Procedure Call",
"RPC", "rpc");
proto_register_field_array(proto_rpc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine(&rpc_init_protocol);
rpc_module = prefs_register_protocol(proto_rpc, NULL);
prefs_register_bool_preference(rpc_module, "desegment_rpc_over_tcp",
"Reassemble RPC over TCP messages\nspanning multiple TCP segments",
"Whether the RPC dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&rpc_desegment);
prefs_register_bool_preference(rpc_module, "defragment_rpc_over_tcp",
"Reassemble fragmented RPC-over-TCP messages",
"Whether the RPC dissector should defragment RPC-over-TCP messages.",
&rpc_defragment);
prefs_register_uint_preference(rpc_module, "max_tcp_pdu_size", "Maximum size of a RPC-over-TCP PDU",
"Set the maximum size of RPCoverTCP PDUs. "
" If the size field of the record marker is larger "
"than this value it will not be considered a valid RPC PDU.",
10, &max_rpc_tcp_pdu_size);
prefs_register_bool_preference(rpc_module, "dissect_unknown_programs",
"Dissect unknown RPC program numbers",
"Whether the RPC dissector should attempt to dissect RPC PDUs containing programs that are not known to Wireshark. This will make the heuristics significantly weaker and elevate the risk for falsely identifying and misdissecting packets significantly.",
&rpc_dissect_unknown_programs);
prefs_register_bool_preference(rpc_module, "find_fragment_start",
"Attempt to locate start-of-fragment in partial RPC-over-TCP captures",
"Whether the RPC dissector should attempt to locate RPC PDU boundaries when initial fragment alignment is not known. This may cause false positives, or slow operation.",
&rpc_find_fragment_start);
register_dissector("rpc", dissect_rpc, proto_rpc);
new_register_dissector("rpc-tcp", dissect_rpc_tcp, proto_rpc);
rpc_tap = register_tap("rpc");
rpc_progs = g_hash_table_new_full(rpc_prog_hash, rpc_prog_equal,
g_free, rpc_prog_free_val);
rpc_procs = g_hash_table_new_full(rpc_proc_hash, rpc_proc_equal,
g_free, g_free);
authgss_contexts=wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
}
void
proto_reg_handoff_rpc(void)
{
rpc_tcp_handle = find_dissector("rpc-tcp");
dissector_add_uint("tcp.port", 111, rpc_tcp_handle);
rpc_handle = find_dissector("rpc");
dissector_add_uint("udp.port", 111, rpc_handle);
heur_dissector_add("tcp", dissect_rpc_tcp_heur, proto_rpc);
heur_dissector_add("udp", dissect_rpc_heur, proto_rpc);
gssapi_handle = find_dissector("gssapi");
spnego_krb5_wrap_handle = find_dissector("spnego-krb5-wrap");
data_handle = find_dissector("data");
}
