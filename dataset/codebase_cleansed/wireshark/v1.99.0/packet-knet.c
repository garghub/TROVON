static int
count_vle_bytes(tvbuff_t *tvb, int offset)
{
int byte_count = 1;
if(tvb_get_guint8(tvb, offset) & 0x80)
byte_count = 2;
if(tvb_get_guint8(tvb, offset+1) & 0x80)
byte_count = 4;
return byte_count;
}
static guint32
dissect_packetid(tvbuff_t *buffer, int offset, proto_tree *tree)
{
guint32 packetid;
packetid = tvb_get_guint8(buffer, offset+2) << 14;
packetid += tvb_get_guint8(buffer, offset+1) << 6;
packetid += tvb_get_guint8(buffer, offset) & 63;
proto_tree_add_uint(tree, hf_knet_packetid, buffer, 0, 3, packetid);
return packetid;
}
static int
dissect_reliable_message_index_base(tvbuff_t *buffer, int offset, proto_tree *tree)
{
int byte_count = 2;
if(tvb_get_guint8(buffer, offset+1) & 0x80)
byte_count = 4;
proto_tree_add_item(tree, hf_knet_rmib, buffer, offset, byte_count, ENC_LITTLE_ENDIAN);
return byte_count;
}
static int
dissect_content_length_vle(tvbuff_t *buffer, int *offset, proto_tree *tree)
{
int byte_count;
guint32 length;
length = 0;
byte_count = count_vle_bytes(buffer, *offset);
switch(byte_count)
{
case 4:
length = tvb_get_guint8(buffer, (*offset) + 3) << 23;
length += (tvb_get_guint8(buffer, (*offset) + 2) << 15);
case 2:
length += (tvb_get_guint8(buffer, (*offset) + 1) << 7);
case 1:
length += (tvb_get_guint8(buffer, (*offset)) & 0x7F);
break;
default:
REPORT_DISSECTOR_BUG("Error in Content Length calculation");
break;
}
proto_tree_add_uint(tree, hf_knet_content_length_vle, buffer, (*offset), byte_count, length);
(*offset) += byte_count;
return length;
}
static int
dissect_content_length(tvbuff_t *buffer, int offset, proto_tree *tree)
{
proto_item *msgflags_ti;
proto_tree *msgflags_tree;
guint32 length;
length = tvb_get_bits8(buffer, offset * 8 + 12, 4) << 8;
length += tvb_get_bits8(buffer, offset * 8, 8);
if(tree != NULL)
{
msgflags_ti = proto_tree_add_item(tree, hf_knet_msg_flags, buffer, offset + 1, 1, ENC_NA);
msgflags_tree = proto_item_add_subtree(msgflags_ti, ett_knet_message_flags);
proto_tree_add_item(msgflags_tree, hf_knet_msg_fs, buffer, offset+1, 1, ENC_NA);
proto_tree_add_item(msgflags_tree, hf_knet_msg_ff, buffer, offset+1, 1, ENC_NA);
proto_tree_add_item(msgflags_tree, hf_knet_msg_inorder, buffer, offset+1, 1, ENC_NA);
proto_tree_add_item(msgflags_tree, hf_knet_msg_reliable, buffer, offset+1, 1, ENC_NA);
proto_tree_add_uint(tree, hf_knet_content_length, buffer, offset, 2, length);
}
return length;
}
static int
dissect_reliable_message_number(tvbuff_t *buffer, int offset, proto_tree *tree)
{
int byte_count = 1;
if(tvb_get_guint8(buffer, offset) & 0x80)
byte_count = 2;
proto_tree_add_item(tree, hf_knet_msg_reliable_message_number, buffer, offset, byte_count, ENC_LITTLE_ENDIAN);
return byte_count;
}
static int
dissect_messageid(tvbuff_t *buffer, int *offset, proto_tree *tree, packet_info *pinfo, gboolean separator)
{
gint messageid_length;
guint8 messageid;
gboolean col_write;
messageid = tvb_get_guint8(buffer, (*offset));
switch(messageid)
{
case DISCONNECT:
case DISCONNECTACK:
case CONNECTSYN:
case CONNECTSYNACK:
case CONNECTACK:
messageid_length = 4;
break;
default:
messageid_length = 1;
break;
}
proto_tree_add_uint_format_value(tree, hf_knet_messageid, buffer, *offset, messageid_length, messageid,
"%s (%d)", val_to_str_const(messageid, packettypenames, "AppData or Malformed Message ID"), messageid);
if (separator)
{
col_write = col_get_writable(pinfo->cinfo);
col_set_writable(pinfo->cinfo, TRUE);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ", ", "%s (%d)", val_to_str_const(messageid, packettypenames, "AppData"), messageid);
col_set_writable(pinfo->cinfo, col_write);
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, "%s (%d)", val_to_str_const(messageid, packettypenames, "AppData"), messageid);
}
*offset += messageid_length;
return messageid;
}
static int
dissect_payload(tvbuff_t *buffer, int offset, int messageid, proto_tree *tree, int content_length)
{
proto_item *payload_ti;
proto_tree *payload_tree;
payload_ti = proto_tree_add_item(tree, hf_knet_payload_tree, buffer, offset, content_length - 1, ENC_NA);
payload_tree = proto_item_add_subtree(payload_ti, ett_knet_payload);
switch(messageid)
{
case PINGREQUEST:
case PINGREPLY:
proto_tree_add_item(payload_tree, hf_knet_pingid, buffer, offset, 1, ENC_LITTLE_ENDIAN);
break;
case FLOWCONTROLREQUEST:
proto_tree_add_item(payload_tree, hf_knet_flowctrlreq, buffer, offset, 3, ENC_LITTLE_ENDIAN);
break;
case PACKETACK:
proto_tree_add_item(payload_tree, hf_knet_packetack, buffer, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
proto_tree_add_item(payload_tree, hf_knet_seqnumber, buffer, offset, 4, ENC_LITTLE_ENDIAN);
break;
case DISCONNECT:
case DISCONNECTACK:
proto_tree_add_bytes_format(payload_tree, hf_knet_payload, buffer, offset, 0, NULL, "No Payload");
break;
case CONNECTSYN:
case CONNECTSYNACK:
case CONNECTACK:
proto_tree_add_item(payload_tree, hf_knet_payload, buffer, offset, content_length-1, ENC_NA);
break;
default:
proto_tree_add_item(payload_tree, hf_knet_payload, buffer, offset, content_length-1, ENC_NA);
break;
}
return 0;
}
static int
dissect_knet_message(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, int messageindex)
{
int content_length, total_length, messageid;
int start_offset = offset;
proto_item *msgblock_ti;
proto_tree *msgblock_tree;
msgblock_ti = proto_tree_add_item(tree, hf_knet_message_tree, tvb, offset, -1, ENC_NA);
msgblock_tree = proto_item_add_subtree(msgblock_ti, ett_knet_message);
content_length = dissect_content_length(tvb, offset, msgblock_tree);
if(tvb_get_guint8(tvb, offset+1) & UDP_MSG_BLOCK_RELIABLE_FLAG)
offset += dissect_reliable_message_number(tvb, offset+2, msgblock_tree);
offset += 2;
total_length = (offset-start_offset)+content_length;
proto_item_set_len(msgblock_ti, total_length);
messageid = dissect_messageid(tvb, &offset, msgblock_tree, pinfo, messageindex != 0);
dissect_payload(tvb, offset, messageid, msgblock_tree, content_length);
return total_length;
}
static void
dissect_knet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int current_protocol)
{
proto_item *knet_ti, *message_ti;
proto_tree *knet_tree, *message_tree;
int offset = 0, content_length, messageid;
knet_ti = proto_tree_add_item(tree, proto_knet, tvb, 0, -1, ENC_NA);
knet_tree = proto_item_add_subtree(knet_ti, ett_knet_main);
message_ti = proto_tree_add_item(knet_tree, hf_knet_message_tree, tvb, offset, -1, ENC_NA);
message_tree = proto_item_add_subtree(message_ti, ett_knet_message);
content_length = dissect_content_length_vle(tvb, &offset, message_tree);
proto_item_set_len(message_ti, (current_protocol == KNET_SCTP_PACKET ? content_length + 1 : content_length + 2));
messageid = dissect_messageid(tvb, &offset, message_tree, pinfo, TRUE);
dissect_payload(tvb, offset, messageid, message_tree, content_length);
col_set_fence(pinfo->cinfo, COL_INFO);
}
static guint
get_knet_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return count_vle_bytes(tvb, offset) + dissect_content_length_vle(tvb, &offset, NULL);
}
static int
dissect_knet_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_knet(tvb, pinfo, tree, KNET_TCP_PACKET);
return tvb_length(tvb);
}
static int
dissect_knet_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
col_clear(pinfo->cinfo, COL_INFO);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "KNET");
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 2, get_knet_pdu_len, dissect_knet_tcp_pdu, data);
return tvb_length(tvb);
}
static void
dissect_knet_sctp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_clear(pinfo->cinfo, COL_INFO);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "KNET");
dissect_knet(tvb, pinfo, tree, KNET_SCTP_PACKET);
}
static void
dissect_knet_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *knet_ti;
proto_tree *knet_tree;
proto_item *datagram_ti, *udpflags_ti;
proto_tree *datagram_tree,
*udpflags_tree;
int offset = 0;
guint32 packetid;
int messageindex = 0;
col_clear(pinfo->cinfo, COL_INFO);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "KNET");
knet_ti = proto_tree_add_item(tree, proto_knet, tvb, 0, -1, ENC_NA);
knet_tree = proto_item_add_subtree(knet_ti, ett_knet_main);
datagram_ti = proto_tree_add_item(knet_ti, hf_knet_datagram_tree, tvb, 0, 3, ENC_NA);
datagram_tree = proto_item_add_subtree(datagram_ti, ett_knet_datagram);
packetid = dissect_packetid(tvb, 0, datagram_tree);
col_add_fstr(pinfo->cinfo, COL_INFO, "Packet ID %d: ", packetid);
udpflags_ti = proto_tree_add_item(datagram_ti, hf_knet_flags, tvb, 0, 1, ENC_NA);
udpflags_tree = proto_item_add_subtree(udpflags_ti, ett_knet_flags);
proto_tree_add_item(udpflags_tree, hf_knet_inorder, tvb, 0, 1, ENC_NA);
proto_tree_add_item(udpflags_tree, hf_knet_reliable, tvb, 0, 1, ENC_NA);
offset += 3;
if(tvb_get_guint8(tvb, 0) & UDP_DATAGRAM_RELIABLE_FLAG)
offset += dissect_reliable_message_index_base(tvb, 3, datagram_tree);
while ((tvb_length_remaining(tvb, offset) > 2) &&
(dissect_content_length(tvb, offset, NULL) > 0))
{
offset += dissect_knet_message(tvb, pinfo, knet_tree, offset, messageindex);
messageindex++;
}
}
void
proto_register_knet(void)
{
module_t *knet_module;
static hf_register_info hf_knet[] =
{
{&hf_knet_content_length_vle,
{"Content Length", "knet.length",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_knet_message_tree,
{"Message Block", "knet.msg",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_knet_datagram_tree,
{"Datagram Header", "knet.datagram",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_knet_flags,
{"Flags", "knet.datagram.flags",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_knet_inorder,
{"Inorder Flag", "knet.datagram.inorder",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL}},
{&hf_knet_reliable,
{"Reliable Flag", "knet.datagram.reliable",
FT_BOOLEAN, 8, NULL, UDP_DATAGRAM_RELIABLE_FLAG, NULL, HFILL}},
{&hf_knet_packetid,
{"Packet ID", "knet.datagram.packetid",
FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_knet_rmib,
{"Reliable Message Index Base", "knet.datagram.rmib",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_knet_msg_flags,
{"Flags", "knet.msg.flags",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_knet_msg_fs,
{"Fragment Start", "knet.msg.flags.fs",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL}},
{&hf_knet_msg_ff,
{"Fragment Flag", "knet.msg.flags.ff",
FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL}},
{&hf_knet_msg_inorder,
{"Inorder Flag", "knet.msg.flags.inorder",
FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL}},
{&hf_knet_msg_reliable,
{"Reliable Flag", "knet.msg.flags.reliable",
FT_BOOLEAN, 8, NULL, UDP_MSG_BLOCK_RELIABLE_FLAG, NULL, HFILL}},
{&hf_knet_content_length,
{"Content Length", "knet.length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_knet_msg_reliable_message_number,
{"Reliable Message Number", "knet.msg.reliable_number",
FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_knet_payload_tree,
{"Payload", "knet.payload.tree",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_knet_payload,
{"Payload", "knet.payload.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_knet_messageid,
{"Message ID", "knet.payload.messageid",
FT_UINT32, BASE_DEC, VALS(packettypenames), 0x0, NULL, HFILL}},
{&hf_knet_pingid,
{"Ping ID", "knet.payload.pingid",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_knet_flowctrlreq,
{"Flowcontrol Request", "knet.payload.flowctrlreq",
FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_knet_packetack,
{"Packet Ack", "knet.payload.packetack",
FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_knet_seqnumber,
{"Sequence Number", "knet.payload.seqnumber",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}}
};
static gint *ett_knet[] =
{
&ett_knet_main,
&ett_knet_datagram,
&ett_knet_flags,
&ett_knet_message,
&ett_knet_message_flags,
&ett_knet_payload
};
proto_register_field_array(proto_knet, hf_knet, array_length(hf_knet));
proto_register_subtree_array(ett_knet, array_length(ett_knet));
proto_knet = proto_register_protocol ("kNet Protocol", "KNET", "knet");
knet_handle_sctp = register_dissector("knetsctp", dissect_knet_sctp, proto_knet);
knet_handle_tcp = new_register_dissector("knettcp", dissect_knet_tcp, proto_knet);
knet_handle_udp = register_dissector("knetudp", dissect_knet_udp, proto_knet);
knet_module = prefs_register_protocol(proto_knet, proto_reg_handoff_knet);
prefs_register_uint_preference(knet_module, "sctp.port", "kNet SCTP Port",
"Set the SCTP port for kNet messages",
10, &knet_sctp_port);
prefs_register_uint_preference(knet_module, "tcp.port", "kNet TCP Port",
"Set the TCP port for kNet messages",
10, &knet_tcp_port);
prefs_register_uint_preference(knet_module, "udp.port", "kNet UDP Port",
"Set the UDP port for kNet messages",
10, &knet_udp_port);
}
void
proto_reg_handoff_knet(void)
{
static gboolean initialized = FALSE;
static guint current_sctp_port;
static guint current_tcp_port;
static guint current_udp_port;
if(!initialized)
{
initialized = TRUE;
}
else
{
dissector_delete_uint("sctp.port", current_sctp_port, knet_handle_sctp);
dissector_delete_uint("tcp.port", current_tcp_port, knet_handle_tcp);
dissector_delete_uint("udp.port", current_udp_port, knet_handle_udp);
}
current_sctp_port = knet_sctp_port;
dissector_add_uint("sctp.port", current_sctp_port, knet_handle_sctp);
current_tcp_port = knet_tcp_port;
dissector_add_uint("tcp.port", current_tcp_port, knet_handle_tcp);
current_udp_port = knet_udp_port;
dissector_add_uint("udp.port", current_udp_port, knet_handle_udp);
}
