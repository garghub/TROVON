static int dissect_control_get_recmaster_reply(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint32 status, int endianess _U_)
{
proto_tree_add_uint(tree, hf_ctdb_recmaster, tvb, 0, 0, status);
col_append_fstr(pinfo->cinfo, COL_INFO, " RecMaster:%d", status);
return offset;
}
static int dissect_control_get_recmode_reply(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint32 status, int endianess _U_)
{
proto_tree_add_uint(tree, hf_ctdb_recmode, tvb, 0, 0, status);
col_append_fstr(pinfo->cinfo, COL_INFO, " RecMode:%s",
val_to_str(status, recmode_vals, "Unknown:%d"));
return offset;
}
static int dissect_control_get_nodemap_reply(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint32 status _U_, int endianess)
{
guint32 num_nodes;
proto_item *item;
item = proto_tree_add_item(tree, hf_ctdb_num_nodes, tvb, offset, 4, endianess);
if(endianess){
num_nodes=tvb_get_letohl(tvb, offset);
} else {
num_nodes=tvb_get_ntohl(tvb, offset);
}
offset+=4;
if (num_nodes > CTDB_MAX_NODES) {
expert_add_info_format(pinfo, item, &ei_ctdb_too_many_nodes, "Too many nodes (%u). Stopping dissection.", num_nodes);
return offset;
}
while(num_nodes--){
proto_tree_add_item(tree, hf_ctdb_vnn, tvb, offset, 4, endianess);
offset+=4;
proto_tree_add_item(tree, hf_ctdb_node_flags, tvb, offset, 4, endianess);
offset+=4;
proto_tree_add_item(tree, hf_ctdb_node_ip, tvb, offset+4, 4, ENC_BIG_ENDIAN);
offset+=16;
}
return offset;
}
static int dissect_control_process_exist_request(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint32 status _U_, int endianess)
{
guint32 pid;
proto_tree_add_item(tree, hf_ctdb_pid, tvb, offset, 4, endianess);
if(endianess){
pid=tvb_get_letohl(tvb, offset);
} else {
pid=tvb_get_ntohl(tvb, offset);
}
offset+=4;
col_append_fstr(pinfo->cinfo, COL_INFO, " pid:%d", pid);
return offset;
}
static int dissect_control_process_exist_reply(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, guint32 status, int endianess _U_)
{
proto_tree_add_boolean(tree, hf_ctdb_process_exists, tvb, offset, 4, status);
return offset;
}
static control_dissector find_control_dissector(guint32 opcode, gboolean is_request)
{
control_dissector_array_t *cd=control_dissectors;
while(cd){
if((!cd->opcode)&&(!cd->request_dissector)&&(!cd->reply_dissector)){
break;
}
if(opcode==cd->opcode){
if(is_request){
return cd->request_dissector;
} else {
return cd->reply_dissector;
}
}
cd++;
}
return NULL;
}
static void
ctdb_display_trans(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, ctdb_trans_t *ctdb_trans)
{
proto_item *item;
if(ctdb_trans->request_in!=pinfo->fd->num){
item=proto_tree_add_uint(tree, hf_ctdb_request_in, tvb, 0, 0, ctdb_trans->request_in);
PROTO_ITEM_SET_GENERATED(item);
}
if( (ctdb_trans->response_in!=0)
&&(ctdb_trans->response_in!=pinfo->fd->num) ){
item=proto_tree_add_uint(tree, hf_ctdb_response_in, tvb, 0, 0, ctdb_trans->response_in);
PROTO_ITEM_SET_GENERATED(item);
}
if(pinfo->fd->num==ctdb_trans->response_in){
nstime_t ns;
nstime_delta(&ns, &pinfo->fd->abs_ts, &ctdb_trans->req_time);
item=proto_tree_add_time(tree, hf_ctdb_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(item);
}
}
static void
ctdb_display_control(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, ctdb_control_t *ctdb_control)
{
proto_item *item;
if(ctdb_control->request_in!=pinfo->fd->num){
item=proto_tree_add_uint(tree, hf_ctdb_request_in, tvb, 0, 0, ctdb_control->request_in);
PROTO_ITEM_SET_GENERATED(item);
}
if( (ctdb_control->response_in!=0)
&&(ctdb_control->response_in!=pinfo->fd->num) ){
item=proto_tree_add_uint(tree, hf_ctdb_response_in, tvb, 0, 0, ctdb_control->response_in);
PROTO_ITEM_SET_GENERATED(item);
}
if(pinfo->fd->num==ctdb_control->response_in){
nstime_t ns;
nstime_delta(&ns, &pinfo->fd->abs_ts, &ctdb_control->req_time);
item=proto_tree_add_time(tree, hf_ctdb_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(item);
}
}
static guint32
ctdb_hash(tvbuff_t *tvb, int offset, guint32 len)
{
guint32 value;
guint32 i;
for(value=0x238F13AF*len, i=0; i < len; i++)
value=(value+(tvb_get_guint8(tvb, offset+i) << (i*5 % 24)));
return (1103515243 * value + 12345);
}
static int
dissect_ctdb_key(proto_tree *tree, tvbuff_t *tvb, int offset, guint32 keylen, guint32 *key_hash, int endianess)
{
guint32 keyhash;
proto_item *key_item=NULL;
proto_item *key_tree=NULL;
if(tree){
key_item=proto_tree_add_item(tree, hf_ctdb_key, tvb, offset, keylen, endianess);
key_tree=proto_item_add_subtree(key_item, ett_ctdb_key);
}
keyhash=ctdb_hash(tvb, offset, keylen);
proto_item_append_text(key_item, " (Hash:0x%08x)", keyhash);
key_item=proto_tree_add_uint(key_tree, hf_ctdb_keyhash, tvb, 0, 0, keyhash);
PROTO_ITEM_SET_GENERATED(key_item);
offset+=keylen;
if(key_hash){
*key_hash=keyhash;
}
return offset;
}
static int
dissect_ctdb_reply_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, int endianess)
{
guint32 datalen;
proto_tree_add_item(tree, hf_ctdb_status, tvb, offset, 4, endianess);
offset+=4;
proto_tree_add_item(tree, hf_ctdb_datalen, tvb, offset, 4, endianess);
if(endianess){
datalen=tvb_get_letohl(tvb, offset);
} else {
datalen=tvb_get_ntohl(tvb, offset);
}
offset+=4;
proto_tree_add_item(tree, hf_ctdb_data, tvb, offset, datalen, endianess);
offset+=datalen;
return offset;
}
static int
dissect_ctdb_reply_dmaster(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, guint32 reqid, guint32 dst, int endianess)
{
guint32 datalen, keylen;
wmem_tree_key_t tkey[3];
ctdb_trans_t *ctdb_trans;
proto_tree_add_item(tree, hf_ctdb_dbid, tvb, offset, 4, endianess);
offset+=4;
offset=(offset+7)&0xfffff8;
proto_tree_add_item(tree, hf_ctdb_rsn, tvb, offset, 8, endianess);
offset+=8;
proto_tree_add_item(tree, hf_ctdb_keylen, tvb, offset, 4, endianess);
if(endianess){
keylen=tvb_get_letohl(tvb, offset);
} else {
keylen=tvb_get_ntohl(tvb, offset);
}
offset+=4;
proto_tree_add_item(tree, hf_ctdb_datalen, tvb, offset, 4, endianess);
if(endianess){
datalen=tvb_get_letohl(tvb, offset);
} else {
datalen=tvb_get_ntohl(tvb, offset);
}
offset+=4;
offset=dissect_ctdb_key(tree, tvb, offset, keylen, NULL, endianess);
proto_tree_add_item(tree, hf_ctdb_data, tvb, offset, datalen, endianess);
offset+=datalen;
tkey[0].length=1;
tkey[0].key=&reqid;
tkey[1].length=1;
tkey[1].key=&dst;
tkey[2].length=0;
ctdb_trans=(ctdb_trans_t *)wmem_tree_lookup32_array(ctdb_transactions, &tkey[0]);
if(ctdb_trans){
ctdb_trans->response_in=pinfo->fd->num;
ctdb_display_trans(pinfo, tree, tvb, ctdb_trans);
}
return offset;
}
static int
dissect_ctdb_req_dmaster(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, guint32 reqid, int endianess)
{
guint32 keylen, datalen, dmaster;
wmem_tree_key_t tkey[3];
ctdb_trans_t *ctdb_trans;
proto_tree_add_item(tree, hf_ctdb_dbid, tvb, offset, 4, endianess);
offset+=4;
offset=(offset+7)&0xfffff8;
proto_tree_add_item(tree, hf_ctdb_rsn, tvb, offset, 8, endianess);
offset+=8;
proto_tree_add_item(tree, hf_ctdb_dmaster, tvb, offset, 4, endianess);
if(endianess){
dmaster=tvb_get_letohl(tvb, offset);
} else {
dmaster=tvb_get_ntohl(tvb, offset);
}
offset += 4;
proto_tree_add_item(tree, hf_ctdb_keylen, tvb, offset, 4, endianess);
if(endianess){
keylen=tvb_get_letohl(tvb, offset);
} else {
keylen=tvb_get_ntohl(tvb, offset);
}
offset+=4;
proto_tree_add_item(tree, hf_ctdb_datalen, tvb, offset, 4, endianess);
if(endianess){
datalen=tvb_get_letohl(tvb, offset);
} else {
datalen=tvb_get_ntohl(tvb, offset);
}
offset+=4;
offset=dissect_ctdb_key(tree, tvb, offset, keylen, NULL, endianess);
proto_tree_add_item(tree, hf_ctdb_data, tvb, offset, datalen, endianess);
offset+=datalen;
tkey[0].length=1;
tkey[0].key=&reqid;
tkey[1].length=1;
tkey[1].key=&dmaster;
tkey[2].length=0;
ctdb_trans=(ctdb_trans_t *)wmem_tree_lookup32_array(ctdb_transactions, &tkey[0]);
if(ctdb_trans){
ctdb_display_trans(pinfo, tree, tvb, ctdb_trans);
}
return offset;
}
static int
dissect_ctdb_req_control(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, guint32 reqid, guint32 src, guint32 dst, int endianess)
{
guint32 datalen;
guint32 opcode;
ctdb_control_t *ctdb_control;
control_dissector cd;
int data_offset;
proto_tree_add_item(tree, hf_ctdb_ctrl_opcode, tvb, offset, 4, endianess);
if(endianess){
opcode=tvb_get_letohl(tvb, offset);
} else {
opcode=tvb_get_ntohl(tvb, offset);
}
offset+=4;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s Request %d->%d",
val_to_str(opcode, ctrl_opcode_vals, "Unknown:%d"),
src, dst);
offset=(offset+7)&0xfffff8;
proto_tree_add_item(tree, hf_ctdb_srvid, tvb, offset, 8, endianess);
offset+=8;
proto_tree_add_item(tree, hf_ctdb_clientid, tvb, offset, 4, endianess);
offset+=4;
proto_tree_add_item(tree, hf_ctdb_ctrl_flags, tvb, offset, 4, endianess);
offset+=4;
proto_tree_add_item(tree, hf_ctdb_datalen, tvb, offset, 4, endianess);
if(endianess){
datalen=tvb_get_letohl(tvb, offset);
} else {
datalen=tvb_get_ntohl(tvb, offset);
}
offset+=4;
data_offset=offset;
if (datalen) {
proto_tree_add_item(tree, hf_ctdb_data, tvb, offset, datalen, endianess);
offset+=datalen;
}
if(!pinfo->fd->flags.visited){
wmem_tree_key_t tkey[4];
ctdb_control=wmem_new(wmem_file_scope(), ctdb_control_t);
ctdb_control->opcode=opcode;
ctdb_control->request_in=pinfo->fd->num;
ctdb_control->response_in=0;
ctdb_control->req_time=pinfo->fd->abs_ts;
tkey[0].length=1;
tkey[0].key=&reqid;
tkey[1].length=1;
tkey[1].key=&src;
tkey[2].length=1;
tkey[2].key=&dst;
tkey[3].length=0;
wmem_tree_insert32_array(ctdb_controls, &tkey[0], ctdb_control);
} else {
wmem_tree_key_t tkey[4];
tkey[0].length=1;
tkey[0].key=&reqid;
tkey[1].length=1;
tkey[1].key=&src;
tkey[2].length=1;
tkey[2].key=&dst;
tkey[3].length=0;
ctdb_control=(ctdb_control_t *)wmem_tree_lookup32_array(ctdb_controls, &tkey[0]);
}
cd=find_control_dissector(ctdb_control->opcode, TRUE);
if (cd) {
cd(pinfo, tree, tvb, data_offset, 0, endianess);
}
ctdb_display_control(pinfo, tree, tvb, ctdb_control);
return offset;
}
static int
dissect_ctdb_reply_control(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, guint32 reqid, guint32 src, guint32 dst, int endianess)
{
ctdb_control_t *ctdb_control;
wmem_tree_key_t tkey[4];
proto_item *item;
guint32 datalen, errorlen, status;
int data_offset;
control_dissector cd;
tkey[0].length=1;
tkey[0].key=&reqid;
tkey[1].length=1;
tkey[1].key=&dst;
tkey[2].length=1;
tkey[2].key=&src;
tkey[3].length=0;
ctdb_control=(ctdb_control_t *)wmem_tree_lookup32_array(ctdb_controls, &tkey[0]);
if(!ctdb_control){
return offset;
}
if(!pinfo->fd->flags.visited){
ctdb_control->response_in = pinfo->fd->num;
}
item=proto_tree_add_uint(tree, hf_ctdb_ctrl_opcode, tvb, 0, 0, ctdb_control->opcode);
PROTO_ITEM_SET_GENERATED(item);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s Reply %d->%d",
val_to_str(ctdb_control->opcode, ctrl_opcode_vals, "Unknown:%d"),
src, dst);
proto_tree_add_item(tree, hf_ctdb_status, tvb, offset, 4, endianess);
if(endianess){
status=tvb_get_letohl(tvb, offset);
} else {
status=tvb_get_ntohl(tvb, offset);
}
offset+=4;
proto_tree_add_item(tree, hf_ctdb_datalen, tvb, offset, 4, endianess);
if(endianess){
datalen=tvb_get_letohl(tvb, offset);
} else {
datalen=tvb_get_ntohl(tvb, offset);
}
offset+=4;
proto_tree_add_item(tree, hf_ctdb_errorlen, tvb, offset, 4, endianess);
if(endianess){
errorlen=tvb_get_letohl(tvb, offset);
} else {
errorlen=tvb_get_ntohl(tvb, offset);
}
offset+=4;
data_offset=offset;
if (datalen) {
proto_tree_add_item(tree, hf_ctdb_data, tvb, offset, datalen, endianess);
offset+=datalen;
}
if (errorlen) {
proto_tree_add_item(tree, hf_ctdb_error, tvb, offset, errorlen, endianess);
offset+=errorlen;
}
cd=find_control_dissector(ctdb_control->opcode, FALSE);
if (cd) {
cd(pinfo, tree, tvb, data_offset, status, endianess);
}
ctdb_display_control(pinfo, tree, tvb, ctdb_control);
return offset;
}
static int
dissect_ctdb_req_call(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint32 reqid, guint32 caller, int endianess)
{
guint32 flags, keyhash;
guint32 keylen, datalen;
ctdb_trans_t *ctdb_trans=NULL;
proto_tree_add_item(tree, hf_ctdb_flags_immediate, tvb, offset, 4, endianess);
if(endianess){
flags=tvb_get_letohl(tvb, offset);
} else {
flags=tvb_get_ntohl(tvb, offset);
}
if(flags&0x00000001){
col_append_str(pinfo->cinfo, COL_INFO, " IMMEDIATE");
}
offset+=4;
proto_tree_add_item(tree, hf_ctdb_dbid, tvb, offset, 4, endianess);
offset+=4;
proto_tree_add_item(tree, hf_ctdb_callid, tvb, offset, 4, endianess);
offset+=4;
proto_tree_add_item(tree, hf_ctdb_hopcount, tvb, offset, 4, endianess);
offset+=4;
proto_tree_add_item(tree, hf_ctdb_keylen, tvb, offset, 4, endianess);
if(endianess){
keylen=tvb_get_letohl(tvb, offset);
} else {
keylen=tvb_get_ntohl(tvb, offset);
}
offset+=4;
proto_tree_add_item(tree, hf_ctdb_datalen, tvb, offset, 4, endianess);
if(endianess){
datalen=tvb_get_letohl(tvb, offset);
} else {
datalen=tvb_get_ntohl(tvb, offset);
}
offset+=4;
offset=dissect_ctdb_key(tree, tvb, offset, keylen, &keyhash, endianess);
proto_tree_add_item(tree, hf_ctdb_data, tvb, offset, datalen, endianess);
offset+=datalen;
if(!pinfo->fd->flags.visited){
wmem_tree_key_t tkey[3];
ctdb_trans=wmem_new(wmem_file_scope(), ctdb_trans_t);
ctdb_trans->key_hash=keyhash;
ctdb_trans->request_in=pinfo->fd->num;
ctdb_trans->response_in=0;
ctdb_trans->req_time=pinfo->fd->abs_ts;
tkey[0].length=1;
tkey[0].key=&reqid;
tkey[1].length=1;
tkey[1].key=&caller;
tkey[2].length=0;
wmem_tree_insert32_array(ctdb_transactions, &tkey[0], ctdb_trans);
} else {
wmem_tree_key_t tkey[3];
tkey[0].length=1;
tkey[0].key=&reqid;
tkey[1].length=1;
tkey[1].key=&caller;
tkey[2].length=0;
ctdb_trans=(ctdb_trans_t *)wmem_tree_lookup32_array(ctdb_transactions, &tkey[0]);
}
if(ctdb_trans){
ctdb_display_trans(pinfo, tree, tvb, ctdb_trans);
}
return offset;
}
static gboolean
dissect_ctdb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_tree *tree=NULL;
proto_item *item=NULL;
int offset=0;
guint32 opcode, src, dst, reqid;
int endianess;
if(tvb_captured_length(tvb)<8){
return FALSE;
}
switch(tvb_get_letohl(tvb, offset+4)){
case 0x42445443:
endianess=FALSE;
break;
case 0x43544442:
endianess=TRUE;
break;
default:
return FALSE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CTDB");
col_clear(pinfo->cinfo, COL_INFO);
if(parent_tree){
item=proto_tree_add_item(parent_tree, proto_ctdb, tvb, offset,
-1, endianess);
tree=proto_item_add_subtree(item, ett_ctdb);
}
proto_tree_add_item(tree, hf_ctdb_length, tvb, offset, 4, endianess);
offset+=4;
proto_tree_add_item(tree, hf_ctdb_magic, tvb, offset, 4, endianess);
offset+=4;
proto_tree_add_item(tree, hf_ctdb_version, tvb, offset, 4, endianess);
offset+=4;
proto_tree_add_item(tree, hf_ctdb_generation, tvb, offset, 4, endianess);
offset+=4;
proto_tree_add_item(tree, hf_ctdb_opcode, tvb, offset, 4, endianess);
if(endianess){
opcode=tvb_get_letohl(tvb, offset);
} else {
opcode=tvb_get_ntohl(tvb, offset);
}
offset+=4;
proto_tree_add_item(tree, hf_ctdb_dst, tvb, offset, 4, endianess);
if(endianess){
dst=tvb_get_letohl(tvb, offset);
} else {
dst=tvb_get_ntohl(tvb, offset);
}
offset+=4;
proto_tree_add_item(tree, hf_ctdb_src, tvb, offset, 4, endianess);
if(endianess){
src=tvb_get_letohl(tvb, offset);
} else {
src=tvb_get_ntohl(tvb, offset);
}
offset+=4;
proto_tree_add_item(tree, hf_ctdb_id, tvb, offset, 4, endianess);
if(endianess){
reqid=tvb_get_letohl(tvb, offset);
} else {
reqid=tvb_get_ntohl(tvb, offset);
}
offset+=4;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s %d->%d",
val_to_str(opcode, ctdb_opcodes, "Unknown:%d"),
src, dst);
switch(opcode){
case CTDB_REQ_CALL:
dissect_ctdb_req_call(tvb, offset, pinfo, tree, reqid, src, endianess);
break;
case CTDB_REPLY_CALL:
dissect_ctdb_reply_call(tvb, offset, pinfo, tree, endianess);
break;
case CTDB_REPLY_DMASTER:
dissect_ctdb_reply_dmaster(tvb, offset, pinfo, tree, reqid, dst, endianess);
break;
case CTDB_REQ_DMASTER:
dissect_ctdb_req_dmaster(tvb, offset, pinfo, tree, reqid, endianess);
break;
case CTDB_REPLY_ERROR:
break;
case CTDB_REQ_MESSAGE:
break;
case CTDB_REQ_CONTROL:
dissect_ctdb_req_control(tvb, offset, pinfo, tree, reqid, src, dst, endianess);
break;
case CTDB_REPLY_CONTROL:
dissect_ctdb_reply_control(tvb, offset, pinfo, tree, reqid, src, dst, endianess);
break;
};
return TRUE;
}
void
proto_register_ctdb(void)
{
static hf_register_info hf[] = {
{ &hf_ctdb_length, {
"Length", "ctdb.len", FT_UINT32, BASE_DEC,
NULL, 0x0, "Size of CTDB PDU", HFILL }},
{ &hf_ctdb_dst, {
"Destination", "ctdb.dst", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_src, {
"Source", "ctdb.src", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_id, {
"Id", "ctdb.id", FT_UINT32, BASE_DEC,
NULL, 0x0, "Transaction ID", HFILL }},
{ &hf_ctdb_opcode, {
"Opcode", "ctdb.opcode", FT_UINT32, BASE_DEC,
VALS(ctdb_opcodes), 0x0, "CTDB command opcode", HFILL }},
{ &hf_ctdb_flags_immediate, {
"Immediate", "ctdb.immediate", FT_BOOLEAN, 32,
TFS(&flags_immediate_tfs), 0x00000001, "Force migration of DMASTER?", HFILL }},
{ &hf_ctdb_dbid, {
"DB Id", "ctdb.dbid", FT_UINT32, BASE_HEX,
VALS(ctdb_dbid_vals), 0x0, "Database ID", HFILL }},
{ &hf_ctdb_callid, {
"Call Id", "ctdb.callid", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_status, {
"Status", "ctdb.status", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_datalen, {
"Data Length", "ctdb.datalen", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_errorlen, {
"Error Length", "ctdb.errorlen", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_keylen, {
"Key Length", "ctdb.keylen", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_magic, {
"Magic", "ctdb.magic", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_version, {
"Version", "ctdb.version", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_dmaster, {
"Dmaster", "ctdb.dmaster", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_generation, {
"Generation", "ctdb.generation", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_key, {
"Key", "ctdb.key", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_keyhash, {
"KeyHash", "ctdb.keyhash", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_data, {
"Data", "ctdb.data", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_error, {
"Error", "ctdb.error", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_request_in, {
"Request In", "ctdb.request_in", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_response_in, {
"Response In", "ctdb.response_in", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_time, {
"Time since request", "ctdb.time", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_hopcount, {
"Hopcount", "ctdb.hopcount", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_rsn, {
"RSN", "ctdb.rsn", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_ctrl_opcode, {
"CTRL Opcode", "ctdb.ctrl_opcode", FT_UINT32, BASE_DEC,
VALS(ctrl_opcode_vals), 0x0, NULL, HFILL }},
{ &hf_ctdb_srvid, {
"SrvId", "ctdb.srvid", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_clientid, {
"ClientId", "ctdb.clientid", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_ctrl_flags, {
"CTRL Flags", "ctdb.ctrl_flags", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_recmaster, {
"Recovery Master", "ctdb.recmaster", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_recmode, {
"Recovery Mode", "ctdb.recmode", FT_UINT32, BASE_DEC,
VALS(recmode_vals), 0x0, NULL, HFILL }},
{ &hf_ctdb_num_nodes, {
"Num Nodes", "ctdb.num_nodes", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_vnn, {
"VNN", "ctdb.vnn", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_node_flags, {
"Node Flags", "ctdb.node_flags", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_node_ip, {
"Node IP", "ctdb.node_ip", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_pid, {
"PID", "ctdb.pid", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ctdb_process_exists, {
"Process Exists", "ctdb.process_exists", FT_BOOLEAN, 32,
TFS(&process_exists_tfs), 0x01, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ctdb,
&ett_ctdb_key,
};
static ei_register_info ei[] = {
{ &ei_ctdb_too_many_nodes, { "ctdb.too_many_nodes", PI_UNDECODED, PI_WARN, "Too many nodes", EXPFILL }},
};
expert_module_t* expert_ctdb;
proto_ctdb = proto_register_protocol("Cluster TDB", "CTDB", "ctdb");
proto_register_field_array(proto_ctdb, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ctdb = expert_register_protocol(proto_ctdb);
expert_register_field_array(expert_ctdb, ei, array_length(ei));
ctdb_transactions = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
ctdb_controls = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
}
void
proto_reg_handoff_ctdb(void)
{
dissector_handle_t ctdb_handle;
ctdb_handle = new_create_dissector_handle(dissect_ctdb, proto_ctdb);
dissector_add_for_decode_as("tcp.port", ctdb_handle);
heur_dissector_add("tcp", dissect_ctdb, "Cluster TDB over TCP", "ctdb_tcp", proto_ctdb, HEURISTIC_ENABLE);
}
