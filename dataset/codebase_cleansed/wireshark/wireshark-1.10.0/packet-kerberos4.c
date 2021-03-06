static int
dissect_krb4_string(packet_info *pinfo _U_, int hf_index, proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_index, tvb, offset, -1, ENC_ASCII|ENC_NA);
while(tvb_get_guint8(tvb, offset)!=0){
offset++;
}
offset++;
return offset;
}
static int
dissect_krb4_kdc_request(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean little_endian, int version)
{
nstime_t time_sec;
guint8 lifetime;
if(version==TRANSARC_SPECIAL_VERSION){
proto_tree_add_item(tree, hf_krb4_unknown_transarc_blob, tvb, offset, 8, ENC_NA);
offset+=8;
}
offset=dissect_krb4_string(pinfo, hf_krb4_name, tree, tvb, offset);
offset=dissect_krb4_string(pinfo, hf_krb4_instance, tree, tvb, offset);
offset=dissect_krb4_string(pinfo, hf_krb4_realm, tree, tvb, offset);
time_sec.secs=little_endian?tvb_get_letohl(tvb, offset):tvb_get_ntohl(tvb, offset);
time_sec.nsecs=0;
proto_tree_add_time(tree, hf_krb4_time_sec, tvb, offset, 4, &time_sec);
offset+=4;
lifetime=tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_krb4_lifetime, tvb, offset, 1, lifetime, "Lifetime: %d (%d minutes)", lifetime, lifetime*5);
offset++;
offset=dissect_krb4_string(pinfo, hf_krb4_s_name, tree, tvb, offset);
offset=dissect_krb4_string(pinfo, hf_krb4_s_instance, tree, tvb, offset);
return offset;
}
static int
dissect_krb4_kdc_reply(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean little_endian)
{
nstime_t time_sec;
guint32 length;
offset=dissect_krb4_string(pinfo, hf_krb4_name, tree, tvb, offset);
offset=dissect_krb4_string(pinfo, hf_krb4_instance, tree, tvb, offset);
offset=dissect_krb4_string(pinfo, hf_krb4_realm, tree, tvb, offset);
time_sec.secs=little_endian?tvb_get_letohl(tvb, offset):tvb_get_ntohl(tvb, offset);
time_sec.nsecs=0;
proto_tree_add_time(tree, hf_krb4_time_sec, tvb, offset, 4, &time_sec);
offset+=4;
offset++;
time_sec.secs=little_endian?tvb_get_letohl(tvb, offset):tvb_get_ntohl(tvb, offset);
time_sec.nsecs=0;
proto_tree_add_time(tree, hf_krb4_exp_date, tvb, offset, 4, &time_sec);
offset+=4;
proto_tree_add_item(tree, hf_krb4_kvno, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length=little_endian?tvb_get_letohs(tvb, offset):tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(tree, hf_krb4_length, tvb, offset, 2, length, "Length: %d", length);
offset+=2;
proto_tree_add_item(tree, hf_krb4_encrypted_blob, tvb, offset, length, ENC_NA);
offset+=length;
return offset;
}
static int
dissect_krb4_appl_request(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean little_endian)
{
guint8 tlen, rlen;
nstime_t time_sec;
guint8 lifetime;
proto_tree_add_item(tree, hf_krb4_kvno, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset=dissect_krb4_string(pinfo, hf_krb4_realm, tree, tvb, offset);
tlen=tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_krb4_ticket_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
rlen=tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_krb4_request_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_krb4_ticket_blob, tvb, offset, tlen, ENC_NA);
offset+=tlen;
proto_tree_add_item(tree, hf_krb4_request_blob, tvb, offset, rlen, ENC_NA);
offset+=rlen;
time_sec.secs=little_endian?tvb_get_letohl(tvb, offset):tvb_get_ntohl(tvb, offset);
time_sec.nsecs=0;
proto_tree_add_time(tree, hf_krb4_req_date, tvb, offset, 4, &time_sec);
offset+=4;
lifetime=tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_krb4_lifetime, tvb, offset, 1, lifetime, "Lifetime: %d (%d minutes)", lifetime, lifetime*5);
offset++;
offset=dissect_krb4_string(pinfo, hf_krb4_s_name, tree, tvb, offset);
offset=dissect_krb4_string(pinfo, hf_krb4_s_instance, tree, tvb, offset);
return offset;
}
static int
dissect_krb4_auth_msg_type(packet_info *pinfo, proto_tree *parent_tree, tvbuff_t *tvb, int offset, int version)
{
proto_tree *tree;
proto_item *item;
guint8 auth_msg_type;
auth_msg_type=tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(parent_tree, hf_krb4_auth_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_krb4_auth_msg_type);
proto_tree_add_item(tree, hf_krb4_m_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, "%s%s",
(version==TRANSARC_SPECIAL_VERSION)?"TRANSARC-":"",
val_to_str(auth_msg_type>>1, m_type_vals, "Unknown (0x%04x)"));
proto_item_append_text(item, " %s%s",
(version==TRANSARC_SPECIAL_VERSION)?"TRANSARC-":"",
val_to_str(auth_msg_type>>1, m_type_vals, "Unknown (0x%04x)"));
proto_tree_add_item(tree, hf_krb4_byte_order, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, " (%s)", val_to_str(auth_msg_type&0x01, byte_order_vals, "Unknown (0x%04x)"));
offset++;
return offset;
}
static gboolean
dissect_krb4(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_tree *tree;
proto_item *item;
guint8 version, opcode;
int offset=0;
version=tvb_get_guint8(tvb, offset);
if((version!=4)&&(version!=TRANSARC_SPECIAL_VERSION)){
return FALSE;
}
opcode=tvb_get_guint8(tvb, offset+1);
switch(opcode>>1){
case AUTH_MSG_KDC_REQUEST:
case AUTH_MSG_KDC_REPLY:
case AUTH_MSG_APPL_REQUEST:
case AUTH_MSG_APPL_REQUEST_MUTUAL:
case AUTH_MSG_ERR_REPLY:
case AUTH_MSG_PRIVATE:
case AUTH_MSG_SAFE:
case AUTH_MSG_APPL_ERR:
case AUTH_MSG_DIE:
break;
default:
return FALSE;
}
item = proto_tree_add_item(parent_tree, proto_krb4, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_krb4);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "KRB4");
col_clear(pinfo->cinfo, COL_INFO);
proto_tree_add_item(tree, hf_krb4_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset = dissect_krb4_auth_msg_type(pinfo, tree, tvb, offset, version);
switch(opcode>>1){
case AUTH_MSG_KDC_REQUEST:
offset = dissect_krb4_kdc_request(pinfo, tree, tvb, offset, opcode&0x01, version);
break;
case AUTH_MSG_KDC_REPLY:
offset = dissect_krb4_kdc_reply(pinfo, tree, tvb, offset, opcode&0x01);
break;
case AUTH_MSG_APPL_REQUEST:
offset = dissect_krb4_appl_request(pinfo, tree, tvb, offset, opcode&0x01);
break;
case AUTH_MSG_APPL_REQUEST_MUTUAL:
case AUTH_MSG_ERR_REPLY:
case AUTH_MSG_PRIVATE:
case AUTH_MSG_SAFE:
case AUTH_MSG_APPL_ERR:
case AUTH_MSG_DIE:
break;
}
return TRUE;
}
void
proto_register_krb4(void)
{
static hf_register_info hf[] = {
{ &hf_krb4_version,
{ "Version", "krb4.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Kerberos(v4) version number", HFILL }},
{ &hf_krb4_auth_msg_type,
{ "Msg Type", "krb4.auth_msg_type",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Message Type/Byte Order", HFILL }},
{ &hf_krb4_m_type,
{ "M Type", "krb4.m_type",
FT_UINT8, BASE_HEX, VALS(m_type_vals), 0xfe,
"Message Type", HFILL }},
{ &hf_krb4_byte_order,
{ "Byte Order", "krb4.byte_order",
FT_UINT8, BASE_HEX, VALS(byte_order_vals), 0x01,
NULL, HFILL }},
{ &hf_krb4_name,
{ "Name", "krb4.name",
FT_STRINGZ, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_krb4_instance,
{ "Instance", "krb4.instance",
FT_STRINGZ, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_krb4_realm,
{ "Realm", "krb4.realm",
FT_STRINGZ, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_krb4_time_sec,
{ "Time Sec", "krb4.time_sec",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
NULL, HFILL }},
{ &hf_krb4_exp_date,
{ "Exp Date", "krb4.exp_date",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
NULL, HFILL }},
{ &hf_krb4_req_date,
{ "Req Date", "krb4.req_date",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
NULL, HFILL }},
{ &hf_krb4_lifetime,
{ "Lifetime", "krb4.lifetime",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Lifetime (in 5 min units)", HFILL }},
{ &hf_krb4_s_name,
{ "Service Name", "krb4.s_name",
FT_STRINGZ, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_krb4_s_instance,
{ "Service Instance", "krb4.s_instance",
FT_STRINGZ, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_krb4_kvno,
{ "Kvno", "krb4.kvno",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Key Version No", HFILL }},
{ &hf_krb4_length,
{ "Length", "krb4.length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Length of encrypted blob", HFILL }},
{ &hf_krb4_ticket_length,
{ "Ticket Length", "krb4.ticket.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Length of ticket", HFILL }},
{ &hf_krb4_request_length,
{ "Request Length", "krb4.request.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Length of request", HFILL }},
{ &hf_krb4_ticket_blob,
{ "Ticket Blob", "krb4.ticket.blob",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_krb4_request_blob,
{ "Request Blob", "krb4.request.blob",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_krb4_encrypted_blob,
{ "Encrypted Blob", "krb4.encrypted_blob",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_krb4_unknown_transarc_blob,
{ "Unknown Transarc Blob", "krb4.unknown_transarc_blob",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Unknown blob only present in Transarc packets", HFILL }},
};
static gint *ett[] = {
&ett_krb4,
&ett_krb4_auth_msg_type,
};
proto_krb4 = proto_register_protocol("Kerberos v4",
"KRB4", "krb4");
new_register_dissector("krb4", dissect_krb4, proto_krb4);
proto_register_field_array(proto_krb4, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_krb4(void)
{
dissector_handle_t krb4_handle;
krb4_handle = find_dissector("krb4");
dissector_add_uint("udp.port", UDP_PORT_KRB4, krb4_handle);
}
