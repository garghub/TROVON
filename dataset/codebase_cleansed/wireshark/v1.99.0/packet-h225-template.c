static int
dissect_h225_H323UserInformation(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *it;
proto_tree *tr;
int offset = 0;
pi_current++;
if(pi_current==5){
pi_current=0;
}
h225_pi=&pi_arr[pi_current];
reset_h225_packet_info(h225_pi);
h225_pi->msg_type = H225_CS;
next_tvb_init(&h245_list);
next_tvb_init(&tp_list);
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
col_clear(pinfo->cinfo, COL_INFO);
it=proto_tree_add_protocol_format(tree, proto_h225, tvb, 0, -1, PSNAME" CS");
tr=proto_item_add_subtree(it, ett_h225);
offset = dissect_H323_UserInformation_PDU(tvb, pinfo, tr, NULL);
if (h245_list.count){
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/");
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
}
next_tvb_call(&h245_list, pinfo, tree, h245dg_handle, data_handle);
next_tvb_call(&tp_list, pinfo, tree, NULL, data_handle);
tap_queue_packet(h225_tap, pinfo, h225_pi);
return offset;
}
static int
dissect_h225_h225_RasMessage(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_){
proto_item *it;
proto_tree *tr;
guint32 offset=0;
pi_current++;
if(pi_current==5){
pi_current=0;
}
h225_pi=&pi_arr[pi_current];
reset_h225_packet_info(h225_pi);
h225_pi->msg_type = H225_RAS;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
it=proto_tree_add_protocol_format(tree, proto_h225, tvb, offset, -1, PSNAME" RAS");
tr=proto_item_add_subtree(it, ett_h225);
offset = dissect_RasMessage_PDU(tvb, pinfo, tr, NULL);
ras_call_matching(tvb, pinfo, tr, h225_pi);
tap_queue_packet(h225_tap, pinfo, h225_pi);
return offset;
}
void proto_register_h225(void) {
static hf_register_info hf[] = {
{ &hf_h221Manufacturer,
{ "H.221 Manufacturer", "h221.Manufacturer", FT_UINT32, BASE_HEX,
VALS(H221ManufacturerCode_vals), 0, NULL, HFILL }},
{ &hf_h225_ras_req_frame,
{ "RAS Request Frame", "h225.ras.reqframe", FT_FRAMENUM, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_h225_ras_rsp_frame,
{ "RAS Response Frame", "h225.ras.rspframe", FT_FRAMENUM, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_h225_ras_dup,
{ "Duplicate RAS Message", "h225.ras.dup", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_h225_ras_deltatime,
{ "RAS Service Response Time", "h225.ras.timedelta", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0, "Timedelta between RAS-Request and RAS-Response", HFILL }},
{ &hf_h225_debug_dissector_try_string,
{ "*** DEBUG dissector_try_string", "h225.debug.dissector_try_string", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
#include "packet-h225-hfarr.c"
};
static gint *ett[] = {
&ett_h225,
#include "packet-h225-ettarr.c"
};
module_t *h225_module;
proto_h225 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h225, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
h225_module = prefs_register_protocol(proto_h225, proto_reg_handoff_h225);
prefs_register_uint_preference(h225_module, "tls.port",
"H.225 TLS Port",
"H.225 Server TLS Port",
10, &h225_tls_port);
prefs_register_bool_preference(h225_module, "reassembly",
"Reassemble H.225 messages spanning multiple TCP segments",
"Whether the H.225 dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&h225_reassembly);
prefs_register_bool_preference(h225_module, "h245_in_tree",
"Display tunnelled H.245 inside H.225.0 tree",
"ON - display tunnelled H.245 inside H.225.0 tree, OFF - display tunnelled H.245 in root tree after H.225.0",
&h225_h245_in_tree);
prefs_register_bool_preference(h225_module, "tp_in_tree",
"Display tunnelled protocols inside H.225.0 tree",
"ON - display tunnelled protocols inside H.225.0 tree, OFF - display tunnelled protocols in root tree after H.225.0",
&h225_tp_in_tree);
new_register_dissector("h225", dissect_h225_H323UserInformation, proto_h225);
new_register_dissector("h323ui",dissect_h225_H323UserInformation, proto_h225);
new_register_dissector("h225.ras", dissect_h225_h225_RasMessage, proto_h225);
nsp_object_dissector_table = register_dissector_table("h225.nsp.object", "H.225 NonStandardParameter (object)", FT_STRING, BASE_NONE);
nsp_h221_dissector_table = register_dissector_table("h225.nsp.h221", "H.225 NonStandardParameter (h221)", FT_UINT32, BASE_HEX);
tp_dissector_table = register_dissector_table("h225.tp", "H.225 TunnelledProtocol", FT_STRING, BASE_NONE);
gef_name_dissector_table = register_dissector_table("h225.gef.name", "H.225 Generic Extensible Framework (names)", FT_STRING, BASE_NONE);
gef_content_dissector_table = register_dissector_table("h225.gef.content", "H.225 Generic Extensible Framework", FT_STRING, BASE_NONE);
register_init_routine(&h225_init_routine);
h225_tap = register_tap("h225");
oid_add_from_string("Version 1","0.0.8.2250.0.1");
oid_add_from_string("Version 2","0.0.8.2250.0.2");
oid_add_from_string("Version 3","0.0.8.2250.0.3");
oid_add_from_string("Version 4","0.0.8.2250.0.4");
oid_add_from_string("Version 5","0.0.8.2250.0.5");
oid_add_from_string("Version 6","0.0.8.2250.0.6");
}
void
proto_reg_handoff_h225(void)
{
static gboolean h225_prefs_initialized = FALSE;
static dissector_handle_t h225ras_handle;
static guint saved_h225_tls_port;
if (!h225_prefs_initialized) {
h225ras_handle=find_dissector("h225.ras");
dissector_add_uint("udp.port", UDP_PORT_RAS1, h225ras_handle);
dissector_add_uint("udp.port", UDP_PORT_RAS2, h225ras_handle);
h245_handle = find_dissector("h245");
h245dg_handle = find_dissector("h245dg");
h4501_handle = find_dissector("h4501");
data_handle = find_dissector("data");
h225_prefs_initialized = TRUE;
} else {
ssl_dissector_delete(saved_h225_tls_port, "q931.tpkt", TRUE);
}
saved_h225_tls_port = h225_tls_port;
ssl_dissector_add(saved_h225_tls_port, "q931.tpkt", TRUE);
}
static void reset_h225_packet_info(h225_packet_info *pi)
{
if(pi == NULL) {
return;
}
pi->msg_type = H225_OTHERS;
pi->cs_type = H225_OTHER;
pi->msg_tag = -1;
pi->reason = -1;
pi->requestSeqNum = 0;
memset(&pi->guid,0,sizeof pi->guid);
pi->is_duplicate = FALSE;
pi->request_available = FALSE;
pi->is_faststart = FALSE;
pi->is_h245 = FALSE;
pi->is_h245Tunneling = FALSE;
pi->h245_address = 0;
pi->h245_port = 0;
pi->frame_label[0] = '\0';
pi->dialedDigits[0] = '\0';
pi->is_destinationInfo = FALSE;
}
static void ras_call_matching(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, h225_packet_info *pi)
{
proto_item *hidden_item;
conversation_t* conversation = NULL;
h225ras_call_info_key h225ras_call_key;
h225ras_call_t *h225ras_call = NULL;
nstime_t delta;
guint msg_category;
if(pi->msg_type == H225_RAS && pi->msg_tag < 21) {
msg_category = pi->msg_tag / 3;
if(pi->msg_tag % 3 == 0) {
conversation = find_or_create_conversation(pinfo);
h225ras_call_key.reqSeqNum = pi->requestSeqNum;
h225ras_call_key.conversation = conversation;
h225ras_call = find_h225ras_call(&h225ras_call_key ,msg_category);
if (h225ras_call != NULL) {
do {
if (pinfo->fd->num == h225ras_call->req_num) {
break;
}
if (h225ras_call->next_call == NULL) {
if ( (pinfo->fd->num > h225ras_call->rsp_num && h225ras_call->rsp_num != 0
&& pinfo->fd->abs_ts.secs > (h225ras_call->req_time.secs + THRESHOLD_REPEATED_RESPONDED_CALL) )
||(pinfo->fd->num > h225ras_call->req_num && h225ras_call->rsp_num == 0
&& pinfo->fd->abs_ts.secs > (h225ras_call->req_time.secs + THRESHOLD_REPEATED_NOT_RESPONDED_CALL) ) )
{
h225ras_call = append_h225ras_call(h225ras_call, pinfo, &pi->guid, msg_category);
} else {
pi->is_duplicate = TRUE;
hidden_item = proto_tree_add_uint(tree, hf_h225_ras_dup, tvb, 0,0, pi->requestSeqNum);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
break;
}
h225ras_call = h225ras_call->next_call;
} while (h225ras_call != NULL );
}
else {
h225ras_call = new_h225ras_call(&h225ras_call_key, pinfo, &pi->guid, msg_category);
}
if(h225ras_call && h225ras_call->rsp_num != 0){
proto_item *ti =
proto_tree_add_uint_format(tree, hf_h225_ras_rsp_frame, tvb, 0, 0, h225ras_call->rsp_num,
"The response to this request is in frame %u",
h225ras_call->rsp_num);
PROTO_ITEM_SET_GENERATED(ti);
}
}
else {
conversation = find_conversation(pinfo->fd->num, &pinfo->src,
&pinfo->dst, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (conversation != NULL) {
h225ras_call_key.reqSeqNum = pi->requestSeqNum;
h225ras_call_key.conversation = conversation;
h225ras_call = find_h225ras_call(&h225ras_call_key ,msg_category);
if(h225ras_call) {
do {
if (pinfo->fd->num == h225ras_call->rsp_num) {
break;
}
if(h225ras_call->next_call == NULL) {
break;
}
h225ras_call = h225ras_call->next_call;
} while (h225ras_call != NULL) ;
if (!h225ras_call) {
return;
}
if (msg_category == 3 || msg_category == 5) {
pi->guid = h225ras_call->guid;
hidden_item = proto_tree_add_guid(tree, hf_h225_guid, tvb, 0, GUID_LEN, &pi->guid);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if (h225ras_call->rsp_num == 0) {
h225ras_call->rsp_num = pinfo->fd->num;
}
else {
if (h225ras_call->rsp_num != pinfo->fd->num) {
pi->is_duplicate = TRUE;
hidden_item = proto_tree_add_uint(tree, hf_h225_ras_dup, tvb, 0,0, pi->requestSeqNum);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
if(h225ras_call->req_num != 0){
proto_item *ti;
h225ras_call->responded = TRUE;
pi->request_available = TRUE;
ti = proto_tree_add_uint_format(tree, hf_h225_ras_req_frame, tvb, 0, 0, h225ras_call->req_num,
"This is a response to a request in frame %u", h225ras_call->req_num);
PROTO_ITEM_SET_GENERATED(ti);
nstime_delta(&delta, &pinfo->fd->abs_ts, &h225ras_call->req_time);
pi->delta_time = delta;
ti = proto_tree_add_time(tree, hf_h225_ras_deltatime, tvb, 0, 0, &(pi->delta_time));
PROTO_ITEM_SET_GENERATED(ti);
}
}
}
}
}
}
