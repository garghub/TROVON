static int
dissect_ddtp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *ddtp_tree;
proto_item *ti;
if (tvb_reported_length(tvb) < 4)
return 0;
if (try_val_to_str(tvb_get_ntohl(tvb, 0), vals_ddtp_version) == NULL)
return 0;
col_set_str (pinfo->cinfo, COL_PROTOCOL, "DDTP");
col_clear (pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_ddtp, tvb, 0, -1, ENC_NA);
ddtp_tree = proto_item_add_subtree(ti, ett_ddtp);
proto_tree_add_item(ddtp_tree, hf_ddtp_version, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ddtp_tree, hf_ddtp_encrypt, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ddtp_tree, hf_ddtp_hostid, tvb, 8, 4, ENC_BIG_ENDIAN);
if (tvb_get_ntohl(tvb, 4) == DDTP_ENCRYPT_PLAINTEXT) {
ti = proto_tree_add_item(ddtp_tree, hf_ddtp_msgtype, tvb, 12, 4, ENC_BIG_ENDIAN);
switch (tvb_get_ntohl(tvb, 12)) {
case DDTP_MESSAGE_ERROR :
col_set_str(pinfo->cinfo, COL_INFO, "Message Error");
break;
case DDTP_UPDATE_QUERY :
col_set_str(pinfo->cinfo, COL_INFO, "Update Query");
proto_tree_add_item(ddtp_tree, hf_ddtp_opcode, tvb, 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ddtp_tree, hf_ddtp_ipaddr, tvb, 20, 4, ENC_BIG_ENDIAN);
break;
case DDTP_UPDATE_REPLY :
col_set_str(pinfo->cinfo, COL_INFO, "Update Reply");
proto_tree_add_item(ddtp_tree, hf_ddtp_status, tvb, 16, 4, ENC_BIG_ENDIAN);
break;
case DDTP_ALIVE_QUERY :
col_set_str(pinfo->cinfo, COL_INFO, "Alive Query");
proto_tree_add_item(ddtp_tree, hf_ddtp_alive, tvb, 16, 4, ENC_BIG_ENDIAN);
break;
case DDTP_ALIVE_REPLY :
col_set_str(pinfo->cinfo, COL_INFO, "Alive Reply");
proto_tree_add_item(ddtp_tree, hf_ddtp_alive, tvb, 16, 4, ENC_BIG_ENDIAN);
break;
default :
col_set_str(pinfo->cinfo, COL_INFO, "Unknown type");
expert_add_info(pinfo, ti, &ei_ddtp_msgtype);
}
} else {
col_set_str(pinfo->cinfo, COL_INFO, "Encrypted payload");
}
return tvb_length(tvb);
}
void
proto_register_ddtp(void)
{
static hf_register_info hf_ddtp[] = {
{ &hf_ddtp_version,
{ "Version", "ddtp.version", FT_UINT32, BASE_DEC, VALS(vals_ddtp_version), 0x0,
NULL, HFILL }},
{ &hf_ddtp_encrypt,
{ "Encryption", "ddtp.encrypt", FT_UINT32, BASE_DEC, VALS(vals_ddtp_encrypt), 0x0,
"Encryption type", HFILL }},
{ &hf_ddtp_hostid,
{ "Hostid", "ddtp.hostid", FT_UINT32, BASE_DEC, NULL, 0x0,
"Host ID", HFILL }},
{ &hf_ddtp_msgtype,
{ "Message type", "ddtp.msgtype", FT_UINT32, BASE_DEC, VALS(vals_ddtp_msgtype), 0x0,
NULL, HFILL }},
{ &hf_ddtp_opcode,
{ "Opcode", "ddtp.opcode", FT_UINT32, BASE_DEC, VALS(vals_ddtp_opcode), 0x0,
"Update query opcode", HFILL }},
{ &hf_ddtp_ipaddr,
{ "IP address", "ddtp.ipaddr", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ddtp_status,
{ "Status", "ddtp.status", FT_UINT32, BASE_DEC, VALS(vals_ddtp_status), 0x0,
"Update reply status", HFILL }},
{ &hf_ddtp_alive,
{ "Dummy", "ddtp.alive", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = { &ett_ddtp };
static ei_register_info ei[] = {
{ &ei_ddtp_msgtype, { "ddtp.msgtype.unknown", PI_PROTOCOL, PI_WARN, "Unknown type", EXPFILL }},
};
expert_module_t* expert_ddtp;
proto_ddtp = proto_register_protocol("Dynamic DNS Tools Protocol",
"DDTP", "ddtp");
proto_register_field_array(proto_ddtp, hf_ddtp, array_length(hf_ddtp));
proto_register_subtree_array(ett, array_length(ett));
expert_ddtp = expert_register_protocol(proto_ddtp);
expert_register_field_array(expert_ddtp, ei, array_length(ei));
}
void
proto_reg_handoff_ddtp(void)
{
dissector_handle_t ddtp_handle;
ddtp_handle = new_create_dissector_handle(dissect_ddtp, proto_ddtp);
dissector_add_uint("udp.port", UDP_PORT_DDTP, ddtp_handle);
}
