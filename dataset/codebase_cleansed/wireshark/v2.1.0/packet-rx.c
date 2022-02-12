static int
dissect_rx_response_encrypted(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
proto_tree *tree;
proto_item *item;
int old_offset=offset;
int i;
guint32 callnumber;
item = proto_tree_add_item(parent_tree, hf_rx_encrypted, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_rx_encrypted);
{
nstime_t ts;
ts.secs = tvb_get_ntohl(tvb, offset);
ts.nsecs = 0;
proto_tree_add_time(tree, hf_rx_epoch, tvb,
offset, 4, &ts);
offset += 4;
}
proto_tree_add_item(tree, hf_rx_cid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset += 4;
proto_tree_add_item(tree, hf_rx_securityindex, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 4;
for (i=0; i<RX_MAXCALLS; i++) {
callnumber = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_rx_callnumber, tvb,
offset, 4, callnumber);
offset += 4;
}
proto_tree_add_item(tree, hf_rx_inc_nonce, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_rx_level, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_rx_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, int offset, guint32 seq, guint32 callnumber)
{
proto_tree *tree;
proto_item *item;
guint32 version, tl;
int old_offset=offset;
col_add_fstr(pinfo->cinfo, COL_INFO,
"RESPONSE "
"Seq: %lu "
"Call: %lu "
"Source Port: %s "
"Destination Port: %s ",
(unsigned long)seq,
(unsigned long)callnumber,
udp_port_to_display(wmem_packet_scope(), pinfo->srcport),
udp_port_to_display(wmem_packet_scope(), pinfo->destport)
);
item = proto_tree_add_item(parent_tree, hf_rx_response, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_rx_response);
version = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_rx_version, tvb,
offset, 4, version);
offset += 4;
if (version==2) {
offset += 4;
offset = dissect_rx_response_encrypted(tvb, tree, offset);
proto_tree_add_item(tree, hf_rx_kvno, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
tl = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_rx_ticket_len, tvb,
offset, 4, tl);
offset += 4;
proto_tree_add_item(tree, hf_rx_ticket, tvb, offset, tl, ENC_NA);
offset += tl;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_rx_abort(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, int offset, guint32 seq, guint32 callnumber)
{
proto_tree *tree;
proto_item *item;
int old_offset=offset;
col_add_fstr(pinfo->cinfo, COL_INFO,
"ABORT "
"Seq: %lu "
"Call: %lu "
"Source Port: %s "
"Destination Port: %s ",
(unsigned long)seq,
(unsigned long)callnumber,
udp_port_to_display(wmem_packet_scope(), pinfo->srcport),
udp_port_to_display(wmem_packet_scope(), pinfo->destport)
);
item = proto_tree_add_item(parent_tree, hf_rx_abort, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_rx_abort);
proto_tree_add_item(tree, hf_rx_abortcode, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_rx_challenge(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, int offset, guint32 seq, guint32 callnumber)
{
proto_tree *tree;
proto_item *item;
guint32 version;
int old_offset=offset;
col_add_fstr(pinfo->cinfo, COL_INFO,
"CHALLENGE "
"Seq: %lu "
"Call: %lu "
"Source Port: %s "
"Destination Port: %s ",
(unsigned long)seq,
(unsigned long)callnumber,
udp_port_to_display(wmem_packet_scope(), pinfo->srcport),
udp_port_to_display(wmem_packet_scope(), pinfo->destport)
);
item = proto_tree_add_item(parent_tree, hf_rx_challenge, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_rx_challenge);
version = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_rx_version, tvb,
offset, 4, version);
offset += 4;
if (version==2) {
proto_tree_add_item(tree, hf_rx_nonce, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_rx_min_level, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_rx_acks(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, int offset, guint32 seq, guint32 callnumber)
{
proto_tree *tree;
proto_item *item;
guint8 num;
int old_offset = offset;
col_add_fstr(pinfo->cinfo, COL_INFO,
"ACK "
"Seq: %lu "
"Call: %lu "
"Source Port: %s "
"Destination Port: %s ",
(unsigned long)seq,
(unsigned long)callnumber,
udp_port_to_display(wmem_packet_scope(), pinfo->srcport),
udp_port_to_display(wmem_packet_scope(), pinfo->destport)
);
item = proto_tree_add_item(parent_tree, hf_rx_ack, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_rx_ack);
proto_tree_add_item(tree, hf_rx_bufferspace, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rx_maxskew, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rx_first_packet, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_rx_prev_packet, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_rx_serial, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_rx_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
num = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_rx_numacks, tvb, offset, 1, num);
offset += 1;
while(num--){
proto_tree_add_item(tree, hf_rx_ack_type, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
}
if (tvb_reported_length_remaining(tvb, offset)>3) {
offset += 3;
if (tvb_reported_length_remaining(tvb, offset) >= 4){
proto_tree_add_item(tree, hf_rx_maxmtu, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
}
if (tvb_reported_length_remaining(tvb, offset) >= 4){
proto_tree_add_item(tree, hf_rx_ifmtu, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
}
if (tvb_reported_length_remaining(tvb, offset) >= 4){
proto_tree_add_item(tree, hf_rx_rwind, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
}
if (tvb_reported_length_remaining(tvb, offset) >= 4){
proto_tree_add_item(tree, hf_rx_maxpackets, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
}
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_rx_flags(tvbuff_t *tvb, struct rxinfo *rxinfo, proto_tree *parent_tree, int offset)
{
static const int * flags[] = {
&hf_rx_flags_free_packet,
&hf_rx_flags_more_packets,
&hf_rx_flags_last_packet,
&hf_rx_flags_request_ack,
&hf_rx_flags_clientinit,
NULL
};
rxinfo->flags = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(parent_tree, tvb, offset, hf_rx_flags, ett_rx_flags, flags, ENC_NA);
offset += 1;
return offset;
}
static int
dissect_rx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_tree *tree;
proto_item *item;
int offset = 0;
struct rxinfo rxinfo;
guint8 type;
nstime_t ts;
guint32 seq, callnumber;
guint16 serviceid;
if (tvb_captured_length(tvb) < 28)
return 0;
type = tvb_get_guint8(tvb, 20);
if (type == 0 || type == 10 || type == 11 || type == 12 || type > 13)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RX");
col_clear(pinfo->cinfo, COL_INFO);
item = proto_tree_add_protocol_format(parent_tree, proto_rx, tvb,
offset, 28, "RX Protocol");
tree = proto_item_add_subtree(item, ett_rx);
rxinfo.epoch = tvb_get_ntohl(tvb, offset);
ts.secs = rxinfo.epoch;
ts.nsecs = 0;
proto_tree_add_time(tree, hf_rx_epoch, tvb, offset, 4, &ts);
offset += 4;
rxinfo.cid = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_rx_cid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
callnumber = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_rx_callnumber, tvb,
offset, 4, callnumber);
offset += 4;
rxinfo.callnumber = callnumber;
seq = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_rx_seq, tvb,
offset, 4, seq);
offset += 4;
rxinfo.seq = seq;
proto_tree_add_item(tree, hf_rx_serial, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_rx_type, tvb,
offset, 1, type);
offset += 1;
rxinfo.type = type;
offset = dissect_rx_flags(tvb, &rxinfo, tree, offset);
proto_tree_add_item(tree, hf_rx_userstatus, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rx_securityindex, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_rx_spare, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
serviceid = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_rx_serviceid, tvb,
offset, 2, serviceid);
offset += 2;
rxinfo.serviceid = serviceid;
switch (type) {
case RX_PACKET_TYPE_ACK:
dissect_rx_acks(tvb, pinfo, tree, offset,
seq, callnumber);
break;
case RX_PACKET_TYPE_ACKALL:
col_add_fstr(pinfo->cinfo, COL_INFO,
"ACKALL "
"Seq: %lu "
"Call: %lu "
"Source Port: %s "
"Destination Port: %s ",
(unsigned long)seq,
(unsigned long)callnumber,
udp_port_to_display(wmem_packet_scope(), pinfo->srcport),
udp_port_to_display(wmem_packet_scope(), pinfo->destport)
);
break;
case RX_PACKET_TYPE_CHALLENGE:
dissect_rx_challenge(tvb, pinfo, tree, offset, seq, callnumber);
break;
case RX_PACKET_TYPE_RESPONSE:
dissect_rx_response(tvb, pinfo, tree, offset, seq, callnumber);
break;
case RX_PACKET_TYPE_DATA: {
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector_with_data(afs_handle, next_tvb, pinfo, parent_tree, &rxinfo);
};
break;
case RX_PACKET_TYPE_ABORT:
dissect_rx_abort(tvb, pinfo, tree, offset, seq, callnumber);
break;
}
return(tvb_captured_length(tvb));
}
void
proto_register_rx(void)
{
static hf_register_info hf[] = {
{ &hf_rx_epoch, {
"Epoch", "rx.epoch", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, NULL, HFILL }},
{ &hf_rx_cid, {
"CID", "rx.cid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_callnumber, {
"Call Number", "rx.callnumber", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_seq, {
"Sequence Number", "rx.seq", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_serial, {
"Serial", "rx.serial", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_type, {
"Type", "rx.type", FT_UINT8, BASE_DEC,
VALS(rx_types), 0, NULL, HFILL }},
{ &hf_rx_flags, {
"Flags", "rx.flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_rx_flags_clientinit, {
"Client Initiated", "rx.flags.client_init", FT_BOOLEAN, 8,
NULL, RX_CLIENT_INITIATED, NULL, HFILL }},
{ &hf_rx_flags_request_ack, {
"Request Ack", "rx.flags.request_ack", FT_BOOLEAN, 8,
NULL, RX_REQUEST_ACK, NULL, HFILL }},
{ &hf_rx_flags_last_packet, {
"Last Packet", "rx.flags.last_packet", FT_BOOLEAN, 8,
NULL, RX_LAST_PACKET, NULL, HFILL }},
{ &hf_rx_flags_more_packets, {
"More Packets", "rx.flags.more_packets", FT_BOOLEAN, 8,
NULL, RX_MORE_PACKETS, NULL, HFILL }},
{ &hf_rx_flags_free_packet, {
"Free Packet", "rx.flags.free_packet", FT_BOOLEAN, 8,
NULL, RX_FREE_PACKET, NULL, HFILL }},
{ &hf_rx_userstatus, {
"User Status", "rx.userstatus", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_securityindex, {
"Security Index", "rx.securityindex", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_spare, {
"Spare/Checksum", "rx.spare", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_serviceid, {
"Service ID", "rx.serviceid", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_bufferspace, {
"Bufferspace", "rx.bufferspace", FT_UINT16, BASE_DEC,
NULL, 0, "Number Of Packets Available", HFILL }},
{ &hf_rx_maxskew, {
"Max Skew", "rx.maxskew", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_first_packet, {
"First Packet", "rx.first", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_prev_packet, {
"Prev Packet", "rx.prev", FT_UINT32, BASE_DEC,
NULL, 0, "Previous Packet", HFILL }},
{ &hf_rx_reason, {
"Reason", "rx.reason", FT_UINT8, BASE_DEC,
VALS(rx_reason), 0, "Reason For This ACK", HFILL }},
{ &hf_rx_numacks, {
"Num ACKs", "rx.num_acks", FT_UINT8, BASE_DEC,
NULL, 0, "Number Of ACKs", HFILL }},
{ &hf_rx_ack_type, {
"ACK Type", "rx.ack_type", FT_UINT8, BASE_DEC,
VALS(rx_ack_type), 0, "Type Of ACKs", HFILL }},
{ &hf_rx_ack, {
"ACK Packet", "rx.ack", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_rx_challenge, {
"CHALLENGE Packet", "rx.challenge", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_rx_version, {
"Version", "rx.version", FT_UINT32, BASE_DEC,
NULL, 0, "Version Of Challenge/Response", HFILL }},
{ &hf_rx_nonce, {
"Nonce", "rx.nonce", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_rx_inc_nonce, {
"Inc Nonce", "rx.inc_nonce", FT_UINT32, BASE_HEX,
NULL, 0, "Incremented Nonce", HFILL }},
{ &hf_rx_min_level, {
"Min Level", "rx.min_level", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_level, {
"Level", "rx.level", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_response, {
"RESPONSE Packet", "rx.response", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_rx_abort, {
"ABORT Packet", "rx.abort", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_rx_encrypted, {
"Encrypted", "rx.encrypted", FT_NONE, BASE_NONE,
NULL, 0, "Encrypted part of response packet", HFILL }},
{ &hf_rx_kvno, {
"kvno", "rx.kvno", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_ticket_len, {
"Ticket len", "rx.ticket_len", FT_UINT32, BASE_DEC,
NULL, 0, "Ticket Length", HFILL }},
{ &hf_rx_ticket, {
"ticket", "rx.ticket", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_rx_ifmtu, {
"Interface MTU", "rx.if_mtu", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_maxmtu, {
"Max MTU", "rx.max_mtu", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_rwind, {
"rwind", "rx.rwind", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_maxpackets, {
"Max Packets", "rx.max_packets", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rx_abortcode, {
"Abort Code", "rx.abort_code", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_rx,
&ett_rx_flags,
&ett_rx_ack,
&ett_rx_challenge,
&ett_rx_response,
&ett_rx_encrypted,
&ett_rx_abort
};
proto_rx = proto_register_protocol("RX Protocol", "RX", "rx");
proto_register_field_array(proto_rx, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_rx(void)
{
dissector_handle_t rx_handle;
int port;
afs_handle = find_dissector_add_dependency("afs", proto_rx);
rx_handle = create_dissector_handle(dissect_rx, proto_rx);
for (port = UDP_PORT_RX_LOW; port <= UDP_PORT_RX_HIGH; port++)
dissector_add_uint("udp.port", port, rx_handle);
dissector_add_uint("udp.port", UDP_PORT_RX_AFS_BACKUPS, rx_handle);
}
