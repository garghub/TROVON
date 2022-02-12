static int
count_vle_bytes(tvbuff_t *tvb, int offset)
{
int byte_count;
byte_count = 1;
if((tvb_get_bits8(tvb, (offset) * 8, 8) & 128) > 0)
byte_count = 2;
if((tvb_get_bits8(tvb, (offset) * 8 + 8, 8) & 128) > 0)
byte_count = 4;
return byte_count;
}
static int
dissect_packetid(tvbuff_t *buffer, int offset, proto_tree *tree)
{
guint32 packetid;
packetid = tvb_get_bits8(buffer, offset * 8 + 16, 8) << 14;
packetid += tvb_get_bits8(buffer, offset * 8 + 8, 8) << 6;
packetid += tvb_get_bits8(buffer, offset * 8, 8) & 63;
if(offset == 0 && tree != NULL)
proto_tree_add_uint(tree, hf_knet_packetid, buffer, 0, 3, packetid);
return packetid;
}
static int
dissect_reliable_message_index_base(tvbuff_t *buffer, int offset, proto_tree *tree)
{
int byte_count;
byte_count = 2;
if((tvb_get_bits8(buffer, offset * 8 + 8, 8) & 128) > 0)
byte_count = 4;
if(tree != NULL)
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
length = tvb_get_bits8(buffer, ((*offset) + 3) * 8, 8) <<23;
length += tvb_get_bits8(buffer, ((*offset) + 2) * 8, 8) <<15;
case 2:
length +=(tvb_get_bits8(buffer, ((*offset) + 1) * 8, 8) & 127) <<7;
case 1:
length +=(tvb_get_bits8(buffer, (*offset) * 8, 8) & 127);
break;
default:
REPORT_DISSECTOR_BUG("Error in Content Length calculation");
break;
}
if(tree != NULL)
{
proto_tree_add_uint(tree, hf_knet_content_length, buffer, (*offset), byte_count, length);
(*offset) += byte_count;
}
return length;
}
static int
dissect_content_length(tvbuff_t *buffer, int offset, proto_tree *tree)
{
proto_item *msgflags_ti;
proto_tree *msgflags_tree;
guint32 length;
msgflags_tree = NULL;
length = tvb_get_bits8(buffer, offset * 8 + 12, 4) << 8;
length += tvb_get_bits8(buffer, offset * 8, 8);
if(tree != NULL)
{
msgflags_ti = proto_tree_add_item(tree, hf_knet_msg_flags, buffer, offset + 1, 1, ENC_NA);
msgflags_tree = proto_item_add_subtree(msgflags_ti, ett_knet_message_flags);
}
proto_tree_add_bits_item(msgflags_tree, hf_knet_msg_fs, buffer, offset * 8 + 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bits_item(msgflags_tree, hf_knet_msg_ff, buffer, offset * 8 + 9, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bits_item(msgflags_tree, hf_knet_msg_inorder, buffer, offset * 8 + 10, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bits_item(msgflags_tree, hf_knet_msg_reliable, buffer, offset * 8 + 11, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_uint(tree, hf_knet_content_length, buffer, offset, 2, length);
return length;
}
static int
dissect_reliable_message_number(tvbuff_t *buffer, int offset, proto_tree *tree)
{
int byte_count;
byte_count = 1;
if((tvb_get_bits8(buffer, offset * 8, 8) & 128) > 0)
byte_count = 2;
if(tree != NULL)
proto_tree_add_item(tree, hf_knet_msg_reliable_message_number, buffer, offset, byte_count, ENC_LITTLE_ENDIAN);
return byte_count;
}
static int
dissect_messageid(tvbuff_t *buffer, int *offset, proto_tree *tree, packet_info *pinfo, emem_strbuf_t* info_field)
{
gint messageid_length;
guint8 messageid;
messageid = tvb_get_bits8(buffer, (*offset) * 8, 8);
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
proto_tree_add_bytes_format(tree, hf_knet_messageid, buffer, *offset, messageid_length, NULL,
"Message ID: %s (%d)", val_to_str_const(messageid, packettypenames, "AppData or Malformed Message ID"), messageid);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_const(messageid, packettypenames, "AppData "));
*offset += messageid_length;
ep_strbuf_append_printf(info_field, "Msg ID (%d) ", messageid);
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
proto_tree_add_text(payload_tree, buffer, offset, 0, "No Payload");
break;
case CONNECTSYN:
case CONNECTSYNACK:
case CONNECTACK:
proto_tree_add_item(payload_tree, hf_knet_payload, buffer, offset, 0, ENC_NA);
break;
default:
proto_tree_add_item(payload_tree, hf_knet_payload, buffer, offset, 0, ENC_NA);
break;
}
return 0;
}
static void
dissect_knet_message(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, emem_strbuf_t* info_field)
{
int offset;
int content_length;
int total_length;
int messageid;
proto_item *msgblock_ti;
proto_tree *msgblock_tree;
offset = 0;
total_length = dissect_content_length(tvb, offset, NULL) + 2;
if(tvb_get_bits8(tvb, 11, 1) > 0)
total_length += dissect_reliable_message_number(tvb, offset + 2, NULL);
msgblock_ti = proto_tree_add_item(tree, hf_knet_message_tree, tvb, offset, total_length, ENC_NA);
msgblock_tree = proto_item_add_subtree(msgblock_ti, ett_knet_message);
content_length = dissect_content_length(tvb, offset, msgblock_tree);
ep_strbuf_append_printf(info_field, "%d: ", messageindex + 1);
offset += 2;
if(tvb_get_bits8(tvb, 11, 1) > 0)
offset += dissect_reliable_message_number(tvb, offset, msgblock_tree);
messageid = dissect_messageid(tvb, &offset, msgblock_tree, pinfo, info_field);
dissect_payload(tvb, offset, messageid, msgblock_tree, content_length);
messageindex++;
}
static void
dissect_knet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *knet_ti;
proto_tree *knet_tree;
proto_item *datagram_ti;
proto_tree *datagram_tree;
proto_item *udpflags_ti;
proto_tree *udpflags_tree;
proto_item *message_ti;
proto_tree *message_tree;
tvbuff_t *next_tvb;
gboolean bytes_left;
emem_strbuf_t *info_field = ep_strbuf_new("");
int offset;
int length;
int content_length;
int messageid;
int packetid;
offset = 0;
messageindex = 0;
bytes_left = TRUE;
col_clear(pinfo->cinfo, COL_INFO);
col_add_str(pinfo->cinfo, COL_PROTOCOL, "KNET");
if((current_protocol == KNET_SCTP_PACKET) || (current_protocol == KNET_TCP_PACKET))
{
knet_ti = proto_tree_add_item(tree, proto_knet, tvb, 0, -1, ENC_NA);
knet_tree = proto_item_add_subtree(knet_ti, ett_knet_main);
next_tvb = tvb_new_subset_remaining(tvb, offset);
if((tvb_length_remaining(next_tvb, offset)) > 0)
{
length = dissect_content_length_vle(next_tvb, &offset, NULL);
message_ti = proto_tree_add_item(knet_tree, hf_knet_message_tree, next_tvb, offset,
(current_protocol == KNET_SCTP_PACKET ? length + 1 : length + 2), ENC_NA);
message_tree = proto_item_add_subtree(message_ti, ett_knet_message);
content_length = dissect_content_length_vle(next_tvb, &offset, message_tree);
if(tree == NULL)
offset += count_vle_bytes(next_tvb, offset);
ep_strbuf_append_printf(info_field, "%d: ", messageindex + 1);
messageid = dissect_messageid(next_tvb, &offset, message_tree, pinfo, info_field);
dissect_payload(next_tvb, offset, messageid, message_tree, content_length);
offset += content_length - 1;
}
}
else
{
knet_ti = proto_tree_add_item(tree, proto_knet, tvb, 0, -1, ENC_NA);
knet_tree = proto_item_add_subtree(knet_ti, ett_knet_main);
datagram_ti = proto_tree_add_item(knet_ti, hf_knet_datagram_tree, tvb, 0, 3, ENC_NA);
datagram_tree = proto_item_add_subtree(datagram_ti, ett_knet_datagram);
udpflags_ti = proto_tree_add_item(datagram_ti, hf_knet_flags, tvb, 0, 1, ENC_NA);
udpflags_tree = proto_item_add_subtree(udpflags_ti, ett_knet_flags);
proto_tree_add_bits_item(udpflags_tree, hf_knet_inorder, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bits_item(udpflags_tree, hf_knet_reliable, tvb, 1, 1, ENC_LITTLE_ENDIAN);
packetid = dissect_packetid(tvb, 0, datagram_tree);
ep_strbuf_append_printf(info_field, "Packet ID: %d ", packetid);
offset += 3;
if(tvb_get_bits8(tvb, 1, 1) == 1)
offset += dissect_reliable_message_index_base(tvb, 3, datagram_tree);
next_tvb = tvb_new_subset_remaining(tvb, offset);
while(bytes_left)
{
offset = 0;
if((tvb_length_remaining(next_tvb, offset)) > 2)
{
length = dissect_content_length(next_tvb, offset, NULL);
if(length == 0)
{
break;
}
else length += 2;
if(tvb_get_bits8(next_tvb, 11, 1) == 1)
length += dissect_reliable_message_number(next_tvb, offset + 2, NULL);
dissect_knet_message(next_tvb, pinfo, knet_tree, info_field);
offset += length;
next_tvb = tvb_new_subset_remaining(next_tvb, offset);
}
else bytes_left = FALSE;
}
}
if(current_protocol == KNET_TCP_PACKET && ((struct tcpinfo*)(pinfo->private_data))->is_reassembled)
col_add_str(pinfo->cinfo, COL_INFO, "REASSEMBLED PACKET");
else
col_add_fstr(pinfo->cinfo, COL_INFO, "Messages: %d %s", messageindex + 1, info_field->str);
messageindex++;
}
static guint
get_knet_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return dissect_content_length_vle(tvb, &offset, NULL) + count_vle_bytes(tvb, offset);
}
static void
dissect_knet_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
current_protocol = KNET_TCP_PACKET;
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 2, get_knet_pdu_len, dissect_knet);
}
static void
dissect_knet_sctp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
current_protocol = KNET_SCTP_PACKET;
dissect_knet(tvb, pinfo, tree);
}
static void
dissect_knet_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
current_protocol = KNET_UDP_PACKET;
dissect_knet(tvb, pinfo, tree);
}
void
proto_register_knet(void)
{
module_t *knet_module;
static hf_register_info hf_knet[] =
{
{&hf_knet_content_length,
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
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_knet_reliable,
{"Reliable Flag", "knet.datagram.reliable",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
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
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_knet_msg_ff,
{"Fragment Flag", "knet.msg.flags.ff",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_knet_msg_inorder,
{"Inorder Flag", "knet.msg.flags.inorder",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_knet_msg_reliable,
{"Reliable Flag", "knet.msg.flags.reliable",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
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
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}},
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
register_dissector("knetsctp", dissect_knet_sctp, proto_knet);
register_dissector("knettcp", dissect_knet_tcp, proto_knet);
register_dissector("knetudp", dissect_knet_udp, proto_knet);
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
static dissector_handle_t knet_handle_sctp = 0;
static dissector_handle_t knet_handle_tcp = 0;
static dissector_handle_t knet_handle_udp = 0;
static guint current_sctp_port;
static guint current_tcp_port;
static guint current_udp_port;
if(!initialized)
{
knet_handle_sctp = create_dissector_handle(dissect_knet_sctp, proto_knet);
knet_handle_tcp = create_dissector_handle(dissect_knet_tcp, proto_knet);
knet_handle_udp = create_dissector_handle(dissect_knet_udp, proto_knet);
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
