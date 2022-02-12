static int
dissect_classicstun(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_item *ta;
proto_tree *classicstun_tree;
proto_tree *att_type_tree;
proto_tree *att_tree;
guint16 msg_type;
guint16 msg_length;
const char *msg_type_str;
guint16 att_type;
guint16 att_length;
guint16 offset;
guint len;
guint i;
conversation_t *conversation;
classicstun_conv_info_t *classicstun_info;
classicstun_transaction_t *classicstun_trans;
wmem_tree_key_t transaction_id_key[2];
guint32 transaction_id[4];
len = tvb_captured_length(tvb);
if (len < CLASSICSTUN_HDR_LEN)
return 0;
msg_type = tvb_get_ntohs(tvb, 0);
if (msg_type & 0xC000 || tvb_get_ntohl(tvb, 4) == 0x2112a442
|| tvb_get_ntohl(tvb, 4) == 0x7f5a9bc7)
return 0;
msg_type_str = try_val_to_str(msg_type, messages);
if (msg_type_str == NULL)
return 0;
msg_length = tvb_get_ntohs(tvb, 2);
if (len != CLASSICSTUN_HDR_LEN+msg_length)
return 0;
transaction_id[0] = tvb_get_ntohl(tvb, 4);
transaction_id[1] = tvb_get_ntohl(tvb, 8);
transaction_id[2] = tvb_get_ntohl(tvb, 12);
transaction_id[3] = tvb_get_ntohl(tvb, 16);
transaction_id_key[0].length = 4;
transaction_id_key[0].key = transaction_id;
transaction_id_key[1].length = 0;
transaction_id_key[1].key = NULL;
conversation = find_or_create_conversation(pinfo);
classicstun_info = (classicstun_conv_info_t *)conversation_get_proto_data(conversation, proto_classicstun);
if (!classicstun_info) {
classicstun_info = wmem_new(wmem_file_scope(), classicstun_conv_info_t);
classicstun_info->pdus=wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_classicstun, classicstun_info);
}
if(!pinfo->fd->flags.visited){
if (((msg_type & CLASS_MASK) >> 4) == REQUEST) {
classicstun_trans=wmem_new(wmem_file_scope(), classicstun_transaction_t);
classicstun_trans->req_frame=pinfo->fd->num;
classicstun_trans->rep_frame=0;
classicstun_trans->req_time=pinfo->fd->abs_ts;
wmem_tree_insert32_array(classicstun_info->pdus, transaction_id_key,
(void *)classicstun_trans);
} else {
classicstun_trans=(classicstun_transaction_t *)wmem_tree_lookup32_array(classicstun_info->pdus,
transaction_id_key);
if(classicstun_trans){
classicstun_trans->rep_frame=pinfo->fd->num;
}
}
} else {
classicstun_trans=(classicstun_transaction_t *)wmem_tree_lookup32_array(classicstun_info->pdus, transaction_id_key);
}
if(!classicstun_trans){
classicstun_trans=wmem_new(wmem_packet_scope(), classicstun_transaction_t);
classicstun_trans->req_frame=0;
classicstun_trans->rep_frame=0;
classicstun_trans->req_time=pinfo->fd->abs_ts;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CLASSIC-STUN");
col_add_fstr(pinfo->cinfo, COL_INFO, "Message: %s",
msg_type_str);
if (tree) {
guint transaction_id_first_word;
ti = proto_tree_add_item(tree, proto_classicstun, tvb, 0, -1, ENC_NA);
classicstun_tree = proto_item_add_subtree(ti, ett_classicstun);
if (((msg_type & CLASS_MASK) >> 4) == REQUEST) {
if (classicstun_trans->rep_frame) {
proto_item *it;
it=proto_tree_add_uint(classicstun_tree, hf_classicstun_response_in,
tvb, 0, 0,
classicstun_trans->rep_frame);
PROTO_ITEM_SET_GENERATED(it);
}
}
else if ((((msg_type & CLASS_MASK) >> 4) == RESPONSE) ||
(((msg_type & CLASS_MASK) >> 4) == ERROR_RESPONSE)) {
if(classicstun_trans->req_frame){
proto_item *it;
nstime_t ns;
it=proto_tree_add_uint(classicstun_tree, hf_classicstun_response_to, tvb, 0, 0, classicstun_trans->req_frame);
PROTO_ITEM_SET_GENERATED(it);
nstime_delta(&ns, &pinfo->fd->abs_ts, &classicstun_trans->req_time);
it=proto_tree_add_time(classicstun_tree, hf_classicstun_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(it);
}
}
proto_tree_add_uint(classicstun_tree, hf_classicstun_type, tvb, 0, 2, msg_type);
proto_tree_add_uint(classicstun_tree, hf_classicstun_length, tvb, 2, 2, msg_length);
proto_tree_add_item(classicstun_tree, hf_classicstun_id, tvb, 4, 16, ENC_NA);
transaction_id_first_word = tvb_get_ntohl(tvb, 4);
if (msg_length > 0) {
ta = proto_tree_add_item(classicstun_tree, hf_classicstun_att, tvb, CLASSICSTUN_HDR_LEN, msg_length, ENC_NA);
att_type_tree = proto_item_add_subtree(ta, ett_classicstun_att_type);
offset = CLASSICSTUN_HDR_LEN;
while( msg_length > 0) {
att_type = tvb_get_ntohs(tvb, offset);
att_length = tvb_get_ntohs(tvb, offset+2);
att_tree = proto_tree_add_subtree_format(att_type_tree, tvb, offset,
ATTR_HDR_LEN+att_length, ett_classicstun_att, NULL,
"Attribute: %s",
val_to_str(att_type, attributes, "Unknown (0x%04x)"));
proto_tree_add_uint(att_tree, classicstun_att_type, tvb,
offset, 2, att_type);
offset += 2;
if (ATTR_HDR_LEN+att_length > msg_length) {
proto_tree_add_uint_format_value(att_tree,
classicstun_att_length, tvb, offset, 2,
att_length,
"%u (bogus, goes past the end of the message)",
att_length);
break;
}
proto_tree_add_uint(att_tree, classicstun_att_length, tvb,
offset, 2, att_length);
offset += 2;
switch( att_type ){
case MAPPED_ADDRESS:
case RESPONSE_ADDRESS:
case SOURCE_ADDRESS:
case CHANGED_ADDRESS:
case REFLECTED_FROM:
case ALTERNATE_SERVER:
case DESTINATION_ADDRESS:
case REMOTE_ADDRESS:
if (att_length < 2)
break;
proto_tree_add_item(att_tree, classicstun_att_family, tvb, offset+1, 1, ENC_BIG_ENDIAN);
if (att_length < 4)
break;
proto_tree_add_item(att_tree, classicstun_att_port, tvb, offset+2, 2, ENC_BIG_ENDIAN);
switch( tvb_get_guint8(tvb, offset+1) ){
case 1:
if (att_length < 8)
break;
proto_tree_add_item(att_tree, classicstun_att_ipv4, tvb, offset+4, 4, ENC_BIG_ENDIAN);
break;
case 2:
if (att_length < 20)
break;
proto_tree_add_item(att_tree, classicstun_att_ipv6, tvb, offset+4, 16, ENC_NA);
break;
}
break;
case CHANGE_REQUEST:
if (att_length < 4)
break;
proto_tree_add_item(att_tree, classicstun_att_change_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(att_tree, classicstun_att_change_port, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case USERNAME:
case PASSWORD:
case MESSAGE_INTEGRITY:
case NONCE:
case REALM:
if (att_length < 1)
break;
proto_tree_add_item(att_tree, classicstun_att_value, tvb, offset, att_length, ENC_NA);
break;
case ERROR_CODE:
if (att_length < 3)
break;
proto_tree_add_item(att_tree, classicstun_att_error_class, tvb, offset+2, 1, ENC_BIG_ENDIAN);
if (att_length < 4)
break;
proto_tree_add_item(att_tree, classicstun_att_error_number, tvb, offset+3, 1, ENC_BIG_ENDIAN);
if (att_length < 5)
break;
proto_tree_add_item(att_tree, classicstun_att_error_reason, tvb, offset+4, (att_length-4), ENC_UTF_8|ENC_NA);
break;
case LIFETIME:
if (att_length < 4)
break;
proto_tree_add_item(att_tree, classicstun_att_lifetime, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case MAGIC_COOKIE:
if (att_length < 4)
break;
proto_tree_add_item(att_tree, classicstun_att_magic_cookie, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case BANDWIDTH:
if (att_length < 4)
break;
proto_tree_add_item(att_tree, classicstun_att_bandwidth, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case DATA:
proto_tree_add_item(att_tree, classicstun_att_data, tvb, offset, att_length, ENC_NA);
break;
case UNKNOWN_ATTRIBUTES:
for (i = 0; i < att_length; i += 4) {
proto_tree_add_item(att_tree, classicstun_att_unknown, tvb, offset+i, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(att_tree, classicstun_att_unknown, tvb, offset+i+2, 2, ENC_BIG_ENDIAN);
}
break;
case SERVER:
proto_tree_add_item(att_tree, classicstun_att_server_string, tvb, offset, att_length, ENC_UTF_8|ENC_NA);
break;
case XOR_MAPPED_ADDRESS:
if (att_length < 2)
break;
proto_tree_add_item(att_tree, classicstun_att_family, tvb, offset+1, 1, ENC_BIG_ENDIAN);
if (att_length < 4)
break;
proto_tree_add_item(att_tree, classicstun_att_xor_port, tvb, offset+2, 2, ENC_BIG_ENDIAN);
ti = proto_tree_add_uint(att_tree, classicstun_att_port, tvb, offset+2, 2,
tvb_get_ntohs(tvb, offset+2) ^
(transaction_id_first_word >> 16));
PROTO_ITEM_SET_GENERATED(ti);
if (att_length < 8)
break;
switch( tvb_get_guint8(tvb, offset+1) ){
case 1:
if (att_length < 8)
break;
proto_tree_add_item(att_tree, classicstun_att_xor_ipv4, tvb, offset+4, 4, ENC_BIG_ENDIAN);
ti = proto_tree_add_ipv4(att_tree, classicstun_att_ipv4, tvb, offset+4, 4,
tvb_get_ipv4(tvb, offset+4) ^ g_htonl(transaction_id_first_word));
PROTO_ITEM_SET_GENERATED(ti);
break;
case 2:
if (att_length < 20)
break;
proto_tree_add_item(att_tree, classicstun_att_xor_ipv6, tvb, offset+4, 16, ENC_NA);
break;
}
break;
case REQUESTED_ADDRESS_TYPE:
if (att_length < 2)
break;
proto_tree_add_item(att_tree, classicstun_att_family, tvb, offset+1, 1, ENC_BIG_ENDIAN);
break;
case CONNECTION_REQUEST_BINDING:
proto_tree_add_item(att_tree, classicstun_att_connection_request_binding, tvb, offset, att_length, ENC_UTF_8|ENC_NA);
break;
default:
break;
}
offset += att_length;
msg_length -= ATTR_HDR_LEN+att_length;
}
}
}
return tvb_reported_length(tvb);
}
static gboolean
dissect_classicstun_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (dissect_classicstun(tvb, pinfo, tree, NULL) == 0)
return FALSE;
return TRUE;
}
void
proto_register_classicstun(void)
{
static hf_register_info hf[] = {
{ &hf_classicstun_type,
{ "Message Type", "classicstun.type", FT_UINT16,
BASE_HEX, VALS(messages), 0x0, NULL, HFILL }
},
{ &hf_classicstun_length,
{ "Message Length", "classicstun.length", FT_UINT16,
BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_classicstun_id,
{ "Message Transaction ID", "classicstun.id", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_classicstun_att,
{ "Attributes", "classicstun.att", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_classicstun_response_in,
{ "Response In", "classicstun.response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The response to this CLASSICSTUN query is in this frame", HFILL }},
{ &hf_classicstun_response_to,
{ "Request In", "classicstun.response_to",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a response to the CLASSICSTUN Request in this frame", HFILL }},
{ &hf_classicstun_time,
{ "Time", "classicstun.time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The time between the Request and the Response", HFILL }},
{ &classicstun_att_type,
{ "Attribute Type", "classicstun.att.type", FT_UINT16,
BASE_HEX, VALS(attributes), 0x0, NULL, HFILL }
},
{ &classicstun_att_length,
{ "Attribute Length", "classicstun.att.length", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &classicstun_att_value,
{ "Value", "classicstun.att.value", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &classicstun_att_family,
{ "Protocol Family", "classicstun.att.family", FT_UINT16,
BASE_HEX, VALS(attributes_family), 0x0, NULL, HFILL }
},
{ &classicstun_att_ipv4,
{ "IP", "classicstun.att.ipv4", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &classicstun_att_ipv6,
{ "IP", "classicstun.att.ipv6", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &classicstun_att_port,
{ "Port", "classicstun.att.port", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &classicstun_att_change_ip,
{ "Change IP","classicstun.att.change.ip", FT_BOOLEAN,
16, TFS(&tfs_set_notset), 0x0004, NULL, HFILL}
},
{ &classicstun_att_change_port,
{ "Change Port","classicstun.att.change.port", FT_BOOLEAN,
16, TFS(&tfs_set_notset), 0x0002, NULL, HFILL}
},
{ &classicstun_att_unknown,
{ "Unknown Attribute","classicstun.att.unknown", FT_UINT16,
BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &classicstun_att_error_class,
{ "Error Class","classicstun.att.error.class", FT_UINT8,
BASE_DEC, NULL, 0x07, NULL, HFILL}
},
{ &classicstun_att_error_number,
{ "Error Code","classicstun.att.error", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &classicstun_att_error_reason,
{ "Error Reason Phase","classicstun.att.error.reason", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &classicstun_att_xor_ipv4,
{ "IP (XOR-d)", "classicstun.att.ipv4-xord", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &classicstun_att_xor_ipv6,
{ "IP (XOR-d)", "classicstun.att.ipv6-xord", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &classicstun_att_xor_port,
{ "Port (XOR-d)", "classicstun.att.port-xord", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &classicstun_att_server_string,
{ "Server version","classicstun.att.server", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &classicstun_att_lifetime,
{ "Lifetime", "classicstun.att.lifetime", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &classicstun_att_magic_cookie,
{ "Magic Cookie", "classicstun.att.magic.cookie", FT_UINT32,
BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &classicstun_att_bandwidth,
{ "Bandwidth", "classicstun.att.bandwidth", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &classicstun_att_data,
{ "Data", "classicstun.att.data", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &classicstun_att_connection_request_binding,
{ "Connection Request Binding", "classicstun.att.connection_request_binding", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_classicstun,
&ett_classicstun_att_type,
&ett_classicstun_att,
};
proto_classicstun = proto_register_protocol("Simple Traversal of UDP Through NAT",
"CLASSICSTUN", "classicstun");
proto_register_field_array(proto_classicstun, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("classicstun", dissect_classicstun, proto_classicstun);
new_register_dissector("classicstun-heur", dissect_classicstun_heur, proto_classicstun);
}
void
proto_reg_handoff_classicstun(void)
{
#if 0
dissector_handle_t classicstun_handle;
classicstun_handle = find_dissector("classicstun");
dissector_add_uint("tcp.port", TCP_PORT_STUN, classicstun_handle);
dissector_add_uint("udp.port", UDP_PORT_STUN, classicstun_handle);
#endif
heur_dissector_add("udp", dissect_classicstun_heur, "Classic STUN over UDP", "classicstun_udp", proto_classicstun, HEURISTIC_ENABLE);
heur_dissector_add("tcp", dissect_classicstun_heur, "Classic STUN over TCP", "classicstun_tcp", proto_classicstun, HEURISTIC_ENABLE);
}
