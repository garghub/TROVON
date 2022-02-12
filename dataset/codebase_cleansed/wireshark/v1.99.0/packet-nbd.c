static guint
get_nbd_tcp_pdu_len(packet_info *pinfo, tvbuff_t *tvb, int offset)
{
guint32 magic, type, packet;
conversation_t *conversation;
nbd_conv_info_t *nbd_info;
nbd_transaction_t *nbd_trans=NULL;
wmem_tree_key_t hkey[3];
guint32 handle[2];
magic=tvb_get_ntohl(tvb, offset);
switch(magic){
case NBD_REQUEST_MAGIC:
type=tvb_get_ntohl(tvb, offset+4);
switch(type){
case NBD_CMD_WRITE:
return tvb_get_ntohl(tvb, offset+24)+28;
default:
return 28;
}
case NBD_RESPONSE_MAGIC:
conversation = find_conversation(pinfo->fd->num,
&pinfo->src, &pinfo->dst,
pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
if (conversation == NULL) {
return tvb_length(tvb);
}
nbd_info = (nbd_conv_info_t *)conversation_get_proto_data(conversation, proto_nbd);
if (!nbd_info) {
return tvb_length(tvb);
}
if(!pinfo->fd->flags.visited){
handle[0]=tvb_get_ntohl(tvb, offset+8);
handle[1]=tvb_get_ntohl(tvb, offset+12);
hkey[0].length=2;
hkey[0].key=handle;
hkey[1].length=0;
nbd_trans=(nbd_transaction_t *)wmem_tree_lookup32_array(nbd_info->unacked_pdus, hkey);
if(!nbd_trans){
return tvb_length(tvb);
}
} else {
handle[0]=tvb_get_ntohl(tvb, offset+8);
handle[1]=tvb_get_ntohl(tvb, offset+12);
packet=pinfo->fd->num;
hkey[0].length=1;
hkey[0].key=&packet;
hkey[1].length=2;
hkey[1].key=handle;
hkey[2].length=0;
nbd_trans=(nbd_transaction_t *)wmem_tree_lookup32_array(nbd_info->acked_pdus, hkey);
if(!nbd_trans){
return tvb_length(tvb);
}
}
if(nbd_trans->type==NBD_CMD_READ){
return 16+nbd_trans->datalen;
} else {
return 16;
}
default:
break;
}
return 0;
}
static int
dissect_nbd_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
guint32 magic, error, packet;
guint32 handle[2];
guint64 from;
int offset=0;
proto_tree *tree=NULL;
proto_item *item=NULL;
conversation_t *conversation;
nbd_conv_info_t *nbd_info;
nbd_transaction_t *nbd_trans=NULL;
wmem_tree_key_t hkey[3];
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NBD");
col_clear(pinfo->cinfo, COL_INFO);
item = proto_tree_add_item(parent_tree, proto_nbd, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_nbd);
magic=tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_nbd_magic, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
switch(magic){
case NBD_REQUEST_MAGIC:
case NBD_RESPONSE_MAGIC:
handle[0]=tvb_get_ntohl(tvb, offset+4);
handle[1]=tvb_get_ntohl(tvb, offset+8);
break;
default:
return 4;
}
conversation = find_or_create_conversation(pinfo);
nbd_info = (nbd_conv_info_t *)conversation_get_proto_data(conversation, proto_nbd);
if (!nbd_info) {
nbd_info = wmem_new(wmem_file_scope(), nbd_conv_info_t);
nbd_info->unacked_pdus = wmem_tree_new(wmem_file_scope());
nbd_info->acked_pdus = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_nbd, nbd_info);
}
if(!pinfo->fd->flags.visited){
if(magic==NBD_REQUEST_MAGIC){
nbd_trans=wmem_new(wmem_file_scope(), nbd_transaction_t);
nbd_trans->req_frame=pinfo->fd->num;
nbd_trans->rep_frame=0;
nbd_trans->req_time=pinfo->fd->abs_ts;
nbd_trans->type=tvb_get_ntohl(tvb, offset);
nbd_trans->datalen=tvb_get_ntohl(tvb, offset+20);
hkey[0].length=2;
hkey[0].key=handle;
hkey[1].length=0;
wmem_tree_insert32_array(nbd_info->unacked_pdus, hkey, (void *)nbd_trans);
} else if(magic==NBD_RESPONSE_MAGIC){
hkey[0].length=2;
hkey[0].key=handle;
hkey[1].length=0;
nbd_trans=(nbd_transaction_t *)wmem_tree_lookup32_array(nbd_info->unacked_pdus, hkey);
if(nbd_trans){
nbd_trans->rep_frame=pinfo->fd->num;
hkey[0].length=1;
hkey[0].key=&nbd_trans->rep_frame;
hkey[1].length=2;
hkey[1].key=handle;
hkey[2].length=0;
wmem_tree_insert32_array(nbd_info->acked_pdus, hkey, (void *)nbd_trans);
hkey[0].length=1;
hkey[0].key=&nbd_trans->req_frame;
hkey[1].length=2;
hkey[1].key=handle;
hkey[2].length=0;
wmem_tree_insert32_array(nbd_info->acked_pdus, hkey, (void *)nbd_trans);
}
}
} else {
packet=pinfo->fd->num;
hkey[0].length=1;
hkey[0].key=&packet;
hkey[1].length=2;
hkey[1].key=handle;
hkey[2].length=0;
nbd_trans=(nbd_transaction_t *)wmem_tree_lookup32_array(nbd_info->acked_pdus, hkey);
}
if( (magic==NBD_RESPONSE_MAGIC)
&& (nbd_trans)
&& (pinfo->fd->num<nbd_trans->req_frame) ){
nbd_trans=NULL;
}
if(!nbd_trans){
nbd_trans=wmem_new(wmem_packet_scope(), nbd_transaction_t);
nbd_trans->req_frame=0;
nbd_trans->rep_frame=0;
nbd_trans->req_time=pinfo->fd->abs_ts;
nbd_trans->type=0xff;
nbd_trans->datalen=0;
}
if(magic==NBD_REQUEST_MAGIC){
if(nbd_trans->rep_frame){
proto_item *it;
it=proto_tree_add_uint(tree, hf_nbd_response_in, tvb, 0, 0, nbd_trans->rep_frame);
PROTO_ITEM_SET_GENERATED(it);
}
} else if(magic==NBD_RESPONSE_MAGIC){
if(nbd_trans->req_frame){
proto_item *it;
nstime_t ns;
it=proto_tree_add_uint(tree, hf_nbd_response_to, tvb, 0, 0, nbd_trans->req_frame);
PROTO_ITEM_SET_GENERATED(it);
nstime_delta(&ns, &pinfo->fd->abs_ts, &nbd_trans->req_time);
it=proto_tree_add_time(tree, hf_nbd_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(it);
}
}
switch(magic){
case NBD_REQUEST_MAGIC:
proto_tree_add_item(tree, hf_nbd_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_nbd_handle, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
from=tvb_get_ntoh64(tvb, offset);
proto_tree_add_item(tree, hf_nbd_from, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(tree, hf_nbd_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
switch(nbd_trans->type){
case NBD_CMD_WRITE:
col_add_fstr(pinfo->cinfo, COL_INFO, "Write Request Offset:0x%" G_GINT64_MODIFIER "x Length:%d", from, nbd_trans->datalen);
break;
case NBD_CMD_READ:
col_add_fstr(pinfo->cinfo, COL_INFO, "Read Request Offset:0x%" G_GINT64_MODIFIER "x Length:%d", from, nbd_trans->datalen);
break;
case NBD_CMD_DISC:
col_set_str(pinfo->cinfo, COL_INFO, "Disconnect Request");
break;
}
if(nbd_trans->type==NBD_CMD_WRITE){
proto_tree_add_item(tree, hf_nbd_data, tvb, offset, nbd_trans->datalen, ENC_NA);
}
break;
case NBD_RESPONSE_MAGIC:
item=proto_tree_add_uint(tree, hf_nbd_type, tvb, 0, 0, nbd_trans->type);
PROTO_ITEM_SET_GENERATED(item);
error=tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_nbd_error, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_nbd_handle, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s Response Error:%d", (nbd_trans->type==NBD_CMD_WRITE)?"Write":"Read", error);
if(nbd_trans->type==NBD_CMD_READ){
proto_tree_add_item(tree, hf_nbd_data, tvb, offset, nbd_trans->datalen, ENC_NA);
}
break;
}
return tvb_length(tvb);
}
static gboolean
dissect_nbd_tcp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint32 magic, type;
if(tvb_length(tvb)<4){
return FALSE;
}
magic=tvb_get_ntohl(tvb, 0);
switch(magic){
case NBD_REQUEST_MAGIC:
if(tvb_length(tvb)<28){
return FALSE;
}
type=tvb_get_ntohl(tvb, 4);
switch(type){
case NBD_CMD_READ:
case NBD_CMD_WRITE:
case NBD_CMD_DISC:
break;
default:
return FALSE;
}
tcp_dissect_pdus(tvb, pinfo, tree, nbd_desegment, 28, get_nbd_tcp_pdu_len, dissect_nbd_tcp_pdu, data);
return TRUE;
case NBD_RESPONSE_MAGIC:
if(tvb_length(tvb)<16){
return FALSE;
}
tcp_dissect_pdus(tvb, pinfo, tree, nbd_desegment, 16, get_nbd_tcp_pdu_len, dissect_nbd_tcp_pdu, data);
return TRUE;
default:
break;
}
return FALSE;
}
void proto_register_nbd(void)
{
static hf_register_info hf[] = {
{ &hf_nbd_magic,
{ "Magic", "nbd.magic", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_nbd_type,
{ "Type", "nbd.type", FT_UINT32, BASE_DEC,
VALS(nbd_type_vals), 0x0, NULL, HFILL }},
{ &hf_nbd_error,
{ "Error", "nbd.error", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_nbd_len,
{ "Length", "nbd.len", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_nbd_handle,
{ "Handle", "nbd.handle", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_nbd_from,
{ "From", "nbd.from", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_nbd_response_in,
{ "Response In", "nbd.response_in", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, "The response to this NBD request is in this frame", HFILL }},
{ &hf_nbd_response_to,
{ "Request In", "nbd.response_to", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, "This is a response to the NBD request in this frame", HFILL }},
{ &hf_nbd_time,
{ "Time", "nbd.time", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0x0, "The time between the Call and the Reply", HFILL }},
{ &hf_nbd_data,
{ "Data", "nbd.data", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_nbd,
};
module_t *nbd_module;
proto_nbd = proto_register_protocol("Network Block Device",
"NBD", "nbd");
proto_register_field_array(proto_nbd, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
nbd_module = prefs_register_protocol(proto_nbd, NULL);
prefs_register_bool_preference(nbd_module, "desegment_nbd_messages",
"Reassemble NBD messages spanning multiple TCP segments",
"Whether the NBD dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings",
&nbd_desegment);
}
void
proto_reg_handoff_nbd(void)
{
heur_dissector_add("tcp", dissect_nbd_tcp_heur, proto_nbd);
}
