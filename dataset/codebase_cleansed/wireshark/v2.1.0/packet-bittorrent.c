static guint
get_bittorrent_pdu_length(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
guint8 type;
guint32 length;
if (tvb_get_guint8(tvb, offset) == 19 &&
tvb_memeql(tvb, offset + 1, "BitTorrent protocol", 19) == 0) {
return 1 +
19 +
8 +
20 +
20;
} else {
length = tvb_get_ntohl(tvb, offset);
if(length == 0) {
return BITTORRENT_HEADER_LENGTH;
}
if(tvb_offset_exists(tvb, offset + BITTORRENT_HEADER_LENGTH)) {
type = tvb_get_guint8(tvb, offset + BITTORRENT_HEADER_LENGTH);
if((type <= BITTORRENT_MESSAGE_PORT || type == BITTORRENT_MESSAGE_EXTENDED) && length<0x1000000) {
return BITTORRENT_HEADER_LENGTH + length;
} else {
return tvb_reported_length_remaining(tvb, offset);
}
} else {
return tvb_reported_length_remaining(tvb, offset);
}
}
}
static void
dissect_bittorrent_message (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
int i;
int isamp = 0;
proto_tree *mtree;
guint16 type = 0;
guint32 typelen = 0;
guint8 prio = 0;
guint32 length;
const char *msgtype = NULL;
proto_item *ti;
guint32 piece_index, piece_begin, piece_length;
guint32 stringlen;
tvbuff_t *subtvb;
if (tvb_bytes_exist(tvb, offset + BITTORRENT_HEADER_LENGTH, 1)) {
length = tvb_get_ntohl(tvb, offset);
type = tvb_get_guint8(tvb, offset + BITTORRENT_HEADER_LENGTH);
if (type==BITTORRENT_MESSAGE_CHOKE && length>4) {
if (!tvb_bytes_exist(tvb, offset + BITTORRENT_HEADER_LENGTH, 4))
return;
typelen = tvb_get_ntohl(tvb, offset + BITTORRENT_HEADER_LENGTH);
if (4+typelen+1<=length) {
if (!tvb_bytes_exist(tvb, offset + BITTORRENT_HEADER_LENGTH + 4, typelen+1))
return;
for ( i=0 ; amp_messages[i].name ; i++ ) {
if (strlen(amp_messages[i].name)==typelen &&
tvb_memeql(tvb, offset + BITTORRENT_HEADER_LENGTH + 4,
amp_messages[i].name, (int)strlen(amp_messages[i].name))==0) {
prio = tvb_get_guint8(tvb, offset + BITTORRENT_HEADER_LENGTH + 4 + typelen);
if (prio==0 || prio==1 || prio==2) {
type = amp_messages[i].value;
isamp = 1;
}
break;
}
}
}
}
msgtype = try_val_to_str(type, bittorrent_messages);
#if 0
if (msgtype == NULL && isamp) {
msgtype = try_val_to_str(type, azureus_messages);
}
#endif
if (msgtype == NULL) {
proto_tree_add_item(tree, hf_bittorrent_continuous_data, tvb, offset, -1, ENC_NA);
col_set_str(pinfo->cinfo, COL_INFO, "Continuation data");
return;
}
} else {
return;
}
if (isamp) {
ti = proto_tree_add_item(tree, hf_azureus_msg, tvb, offset, length + BITTORRENT_HEADER_LENGTH, ENC_NA);
} else {
ti = proto_tree_add_item(tree, hf_bittorrent_msg, tvb, offset, length + BITTORRENT_HEADER_LENGTH, ENC_NA);
}
mtree = proto_item_add_subtree(ti, ett_bittorrent_msg);
if (length == 0) {
proto_tree_add_item(mtree, hf_bittorrent_msg_len, tvb, offset, BITTORRENT_HEADER_LENGTH, ENC_BIG_ENDIAN);
col_set_str(pinfo->cinfo, COL_INFO, "KeepAlive");
return;
}
proto_tree_add_item(mtree, hf_bittorrent_msg_len, tvb, offset, BITTORRENT_HEADER_LENGTH, ENC_BIG_ENDIAN);
offset += BITTORRENT_HEADER_LENGTH;
if (isamp) {
proto_tree_add_item(mtree, hf_azureus_msg_type_len, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mtree, hf_azureus_msg_type, tvb, offset+4, typelen, ENC_ASCII|ENC_NA);
proto_item_append_text(ti, ": Len %u, %s", length, msgtype);
proto_tree_add_item(mtree, hf_azureus_msg_prio, tvb, offset+4+typelen, 1, ENC_BIG_ENDIAN);
offset += 4+typelen+1;
length -= 4+typelen+1;
} else {
proto_tree_add_item(mtree, hf_bittorrent_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ": Len:%u, %s", length, msgtype);
offset += 1;
length -= 1;
}
col_set_str(pinfo->cinfo, COL_INFO, msgtype);
switch (type) {
case BITTORRENT_MESSAGE_CHOKE:
case BITTORRENT_MESSAGE_UNCHOKE:
case BITTORRENT_MESSAGE_INTERESTED:
case BITTORRENT_MESSAGE_NOT_INTERESTED:
break;
case BITTORRENT_MESSAGE_REQUEST:
case BITTORRENT_MESSAGE_CANCEL:
piece_index = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(mtree, hf_bittorrent_piece_index, tvb, offset, 4, piece_index); offset += 4;
piece_begin = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(mtree, hf_bittorrent_piece_begin, tvb, offset, 4, piece_begin); offset += 4;
piece_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(mtree, hf_bittorrent_piece_length, tvb, offset, 4, piece_length);
proto_item_append_text(ti, ", Piece (Idx:0x%x,Begin:0x%x,Len:0x%x)", piece_index, piece_begin, piece_length);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Piece (Idx:0x%x,Begin:0x%x,Len:0x%x)", piece_index, piece_begin, piece_length);
break;
case BITTORRENT_MESSAGE_PORT:
proto_tree_add_item(mtree, hf_bittorrent_port, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case BITTORRENT_MESSAGE_EXTENDED:
proto_tree_add_item(mtree, hf_bittorrent_extended, tvb, offset, length, ENC_NA);
break;
case BITTORRENT_MESSAGE_HAVE:
piece_index = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(mtree, hf_bittorrent_piece_index, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", Piece (Idx:0x%x)", piece_index);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Piece (Idx:0x%x)", piece_index);
break;
case BITTORRENT_MESSAGE_BITFIELD:
proto_tree_add_item(mtree, hf_bittorrent_bitfield_data, tvb, offset, length, ENC_NA);
proto_item_append_text(ti, ", Len:0x%x", length);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Len:0x%x", length);
break;
case BITTORRENT_MESSAGE_PIECE:
piece_index = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(mtree, hf_bittorrent_piece_index, tvb, offset, 4, piece_index);
offset += 4;
length -= 4;
piece_begin = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(mtree, hf_bittorrent_piece_begin, tvb, offset, 4, piece_begin);
offset += 4;
length -= 4;
proto_tree_add_item(mtree, hf_bittorrent_piece_data, tvb, offset, length, ENC_NA);
proto_item_append_text(ti, ", Idx:0x%x,Begin:0x%x,Len:0x%x", piece_index, piece_begin, length);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Idx:0x%x,Begin:0x%x,Len:0x%x", piece_index, piece_begin, length);
break;
case AZUREUS_MESSAGE_HANDSHAKE:
case AZUREUS_MESSAGE_PEER_EXCHANGE:
subtvb = tvb_new_subset_length(tvb, offset, length);
call_dissector(bencode_handle, subtvb, pinfo, mtree);
break;
case AZUREUS_MESSAGE_JPC_HELLO:
stringlen = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(mtree, hf_azureus_jpc_addrlen, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mtree, hf_azureus_jpc_addr, tvb, offset+4, stringlen, ENC_ASCII|ENC_NA);
proto_tree_add_item(mtree, hf_azureus_jpc_port, tvb, offset+4+stringlen, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mtree, hf_azureus_jpc_session, tvb, offset+4+stringlen+4, 4, ENC_BIG_ENDIAN);
break;
case AZUREUS_MESSAGE_JPC_REPLY:
proto_tree_add_item(mtree, hf_azureus_jpc_session, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
break;
}
}
static int
dissect_bittorrent_welcome (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
int i;
char *version;
col_set_str(pinfo->cinfo, COL_INFO, "Handshake");
proto_tree_add_item(tree, hf_bittorrent_prot_name_len, tvb, offset, 1, ENC_BIG_ENDIAN); offset+=1;
proto_tree_add_item(tree, hf_bittorrent_prot_name, tvb, offset, 19, ENC_ASCII|ENC_NA); offset += 19;
proto_tree_add_item(tree, hf_bittorrent_reserved, tvb, offset, 8, ENC_NA); offset += 8;
proto_tree_add_item(tree, hf_bittorrent_sha1_hash, tvb, offset, 20, ENC_NA);
offset += 20;
proto_tree_add_item(tree, hf_bittorrent_peer_id, tvb, offset, 20, ENC_NA);
if(decode_client_information) {
for(i = 0; peer_id[i].name != NULL; ++i)
{
if(tvb_memeql(tvb, offset, peer_id[i].id, (int)strlen(peer_id[i].id)) == 0) {
version = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + (int)strlen(peer_id[i].id),
peer_id[i].ver_len, ENC_ASCII);
proto_tree_add_string_format(tree, hf_bittorrent_version, tvb, offset, 20, version, "Client is %s v%s",
peer_id[i].name, format_text((guchar*)version, peer_id[i].ver_len));
break;
}
}
}
offset += 20;
return offset;
}
static
int dissect_bittorrent_tcp_pdu (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BitTorrent");
col_set_str(pinfo->cinfo, COL_INFO, "BitTorrent ");
ti = proto_tree_add_item (tree, proto_bittorrent, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bittorrent);
if (tvb_get_guint8(tvb, 0) == 19 &&
tvb_memeql(tvb, 1, "BitTorrent protocol", 19) == 0) {
dissect_bittorrent_welcome(tvb, pinfo, tree);
} else {
dissect_bittorrent_message(tvb, pinfo, tree);
}
col_append_str(pinfo->cinfo, COL_INFO, " ");
col_set_fence(pinfo->cinfo, COL_INFO);
return tvb_reported_length(tvb);
}
static
int dissect_bittorrent (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, bittorrent_desegment, BITTORRENT_HEADER_LENGTH,
get_bittorrent_pdu_length, dissect_bittorrent_tcp_pdu, data);
return tvb_reported_length(tvb);
}
static
gboolean test_bittorrent_packet (tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void *data)
{
conversation_t *conversation;
if (tvb_captured_length(tvb) >= 20 &&
tvb_get_guint8(tvb, 0) == 19 &&
tvb_memeql(tvb, 1, "BitTorrent protocol", 19) == 0) {
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, dissector_handle);
dissect_bittorrent(tvb, pinfo, tree, data);
return TRUE;
}
return FALSE;
}
void
proto_register_bittorrent(void)
{
static hf_register_info hf[] = {
#if 0
{ &hf_bittorrent_field_length,
{ "Field Length", "bittorrent.length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
#endif
{ &hf_bittorrent_prot_name_len,
{ "Protocol Name Length", "bittorrent.protocol.name.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_bittorrent_prot_name,
{ "Protocol Name", "bittorrent.protocol.name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_bittorrent_reserved,
{ "Reserved Extension Bytes", "bittorrent.reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_bittorrent_sha1_hash,
{ "SHA1 Hash of info dictionary", "bittorrent.info_hash", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_bittorrent_peer_id,
{ "Peer ID", "bittorrent.peer_id", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_bittorrent_msg,
{ "Message", "bittorrent.msg", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_bittorrent_msg_len,
{ "Message Length", "bittorrent.msg.length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_bittorrent_msg_type,
{ "Message Type", "bittorrent.msg.type", FT_UINT8, BASE_DEC, VALS(bittorrent_messages), 0x0, NULL, HFILL }
},
{ &hf_azureus_msg,
{ "Azureus Message", "bittorrent.azureus_msg", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_azureus_msg_type_len,
{ "Message Type Length", "bittorrent.msg.typelen", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_azureus_msg_type,
{ "Message Type", "bittorrent.msg.aztype", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_azureus_msg_prio,
{ "Message Priority", "bittorrent.msg.prio", FT_UINT8, BASE_DEC, VALS(azureus_priorities), 0x0, NULL, HFILL }
},
{ &hf_bittorrent_bitfield_data,
{ "Bitfield data", "bittorrent.msg.bitfield", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_bittorrent_piece_index,
{ "Piece index", "bittorrent.piece.index", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_bittorrent_piece_begin,
{ "Begin offset of piece", "bittorrent.piece.begin", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_bittorrent_piece_data,
{ "Data in a piece", "bittorrent.piece.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_bittorrent_piece_length,
{ "Piece Length", "bittorrent.piece.length", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_azureus_jpc_addrlen,
{ "Cache Address Length", "bittorrent.jpc.addr.length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_azureus_jpc_addr,
{ "Cache Address", "bittorrent.jpc.addr", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_azureus_jpc_port,
{ "Port", "bittorrent.jpc.port", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_azureus_jpc_session,
{ "Session ID", "bittorrent.jpc.session", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_bittorrent_port,
{ "Port", "bittorrent.port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_bittorrent_extended,
{ "Extended Message", "bittorrent.extended", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_bittorrent_continuous_data,
{ "Extended Message", "bittorrent.continuous_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_bittorrent_version,
{ "Client version", "bittorrent.version", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_bittorrent,
&ett_bittorrent_msg,
&ett_peer_id,
};
module_t *bittorrent_module;
proto_bittorrent = proto_register_protocol("BitTorrent", "BitTorrent", "bittorrent");
proto_register_field_array(proto_bittorrent, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("bittorrent.tcp", dissect_bittorrent, proto_bittorrent);
bittorrent_module = prefs_register_protocol(proto_bittorrent, NULL);
prefs_register_bool_preference(bittorrent_module, "desegment",
"Reassemble BitTorrent messages spanning multiple TCP segments",
"Whether the BitTorrent dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&bittorrent_desegment);
prefs_register_bool_preference(bittorrent_module, "decode_client",
"Decode the peer_id of the handshake messages",
"Enabling this will tell which BitTorrent client that produced the handshake message",
&decode_client_information);
}
void
proto_reg_handoff_bittorrent(void)
{
bencode_handle = find_dissector_add_dependency("bencode", proto_bittorrent);
dissector_handle = find_dissector("bittorrent.tcp");
#if 0
dissector_add_uint("tcp.port", 6881, dissector_handle);
dissector_add_uint("tcp.port", 6882, dissector_handle);
dissector_add_uint("tcp.port", 6883, dissector_handle);
dissector_add_uint("tcp.port", 6884, dissector_handle);
dissector_add_uint("tcp.port", 6885, dissector_handle);
dissector_add_uint("tcp.port", 6886, dissector_handle);
dissector_add_uint("tcp.port", 6887, dissector_handle);
dissector_add_uint("tcp.port", 6888, dissector_handle);
dissector_add_uint("tcp.port", 6889, dissector_handle);
#endif
heur_dissector_add("tcp", test_bittorrent_packet, "BitTorrent over TCP", "bittorrent_tcp", proto_bittorrent, HEURISTIC_ENABLE);
}
