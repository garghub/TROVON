static void
dissect_llrp_parameters(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset)
{
guint8 has_length;
guint16 len, type;
guint real_len;
proto_item *ti;
proto_tree *param_tree;
while (tvb_reported_length_remaining(tvb, offset) > 0)
{
has_length = !(tvb_get_guint8(tvb, offset) & 0x80);
if (has_length)
{
len = tvb_get_ntohs(tvb, offset + 2);
if (len < LLRP_TLV_LEN_MIN)
real_len = LLRP_TLV_LEN_MIN;
else if (len > tvb_reported_length_remaining(tvb, offset))
real_len = tvb_reported_length_remaining(tvb, offset);
else
real_len = len;
ti = proto_tree_add_none_format(tree, hf_llrp_param, tvb,
offset, real_len, "TLV Parameter");
param_tree = proto_item_add_subtree(ti, ett_llrp_param);
proto_tree_add_item(param_tree, hf_llrp_tlv_type, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_item(param_tree, hf_llrp_tlv_len, tvb,
offset, 2, ENC_BIG_ENDIAN);
if (len != real_len)
expert_add_info_format(pinfo, ti, PI_MALFORMED, PI_ERROR,
"Invalid length field: claimed %u, should be %u.",
len, real_len);
offset += 2;
offset += real_len - 4;
}
else
{
type = tvb_get_guint8(tvb, offset) & 0x7F;
switch (type)
{
case LLRP_TV_ANTENNA_ID:
real_len = LLRP_TV_LEN_ANTENNA_ID; break;
case LLRP_TV_FIRST_SEEN_TIME_UTC:
real_len = LLRP_TV_LEN_FIRST_SEEN_TIME_UTC; break;
case LLRP_TV_FIRST_SEEN_TIME_UPTIME:
real_len = LLRP_TV_LEN_FIRST_SEEN_TIME_UPTIME; break;
case LLRP_TV_LAST_SEEN_TIME_UTC:
real_len = LLRP_TV_LEN_LAST_SEEN_TIME_UTC; break;
case LLRP_TV_LAST_SEEN_TIME_UPTIME:
real_len = LLRP_TV_LEN_LAST_SEEN_TIME_UPTIME; break;
case LLRP_TV_PEAK_RSSI:
real_len = LLRP_TV_LEN_PEAK_RSSI; break;
case LLRP_TV_CHANNEL_INDEX:
real_len = LLRP_TV_LEN_CHANNEL_INDEX; break;
case LLRP_TV_TAG_SEEN_COUNT:
real_len = LLRP_TV_LEN_TAG_SEEN_COUNT; break;
case LLRP_TV_RO_SPEC_ID:
real_len = LLRP_TV_LEN_RO_SPEC_ID; break;
case LLRP_TV_INVENTORY_PARAM_SPEC_ID:
real_len = LLRP_TV_LEN_INVENTORY_PARAM_SPEC_ID; break;
case LLRP_TV_C1G2_CRC:
real_len = LLRP_TV_LEN_C1G2_CRC; break;
case LLRP_TV_C1G2_PC:
real_len = LLRP_TV_LEN_C1G2_PC; break;
case LLRP_TV_EPC96:
real_len = LLRP_TV_LEN_EPC96; break;
case LLRP_TV_SPEC_INDEX:
real_len = LLRP_TV_LEN_SPEC_INDEX; break;
case LLRP_TV_CLIENT_REQ_OP_SPEC_RES:
real_len = LLRP_TV_LEN_CLIENT_REQ_OP_SPEC_RES; break;
case LLRP_TV_ACCESS_SPEC_ID:
real_len = LLRP_TV_LEN_ACCESS_SPEC_ID; break;
case LLRP_TV_OP_SPEC_ID:
real_len = LLRP_TV_LEN_OP_SPEC_ID; break;
case LLRP_TV_C1G2_SINGULATION_DET:
real_len = LLRP_TV_LEN_C1G2_SINGULATION_DET; break;
case LLRP_TV_C1G2_XPC_W1:
real_len = LLRP_TV_LEN_C1G2_XPC_W1; break;
case LLRP_TV_C1G2_XPC_W2:
real_len = LLRP_TV_LEN_C1G2_XPC_W2; break;
default:
real_len = 0;
break;
};
ti = proto_tree_add_none_format(tree, hf_llrp_param, tvb,
offset, real_len + 1, "TV Parameter");
param_tree = proto_item_add_subtree(ti, ett_llrp_param);
proto_tree_add_item(param_tree, hf_llrp_tv_type, tvb,
offset, 1, ENC_NA);
offset++;
offset += real_len;
}
}
}
static void
dissect_llrp_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint16 type, guint offset)
{
guint8 requested_data;
guint16 antenna_id, gpi_port, gpo_port;
guint32 spec_id;
proto_item *ti;
switch (type)
{
case LLRP_TYPE_CLOSE_CONNECTION_RESPONSE:
case LLRP_TYPE_GET_READER_CAPABILITES_RESPONSE:
case LLRP_TYPE_ADD_ROSPEC:
case LLRP_TYPE_ADD_ROSPEC_RESPONSE:
case LLRP_TYPE_DELETE_ROSPEC_RESPONSE:
case LLRP_TYPE_START_ROSPEC_RESPONSE:
case LLRP_TYPE_STOP_ROSPEC_RESPONSE:
case LLRP_TYPE_ENABLE_ROSPEC_RESPONSE:
case LLRP_TYPE_DISABLE_ROSPEC_RESPONSE:
case LLRP_TYPE_GET_ROSPECS_RESPONSE:
case LLRP_TYPE_ADD_ACCESSSPEC:
case LLRP_TYPE_ADD_ACCESSSPEC_RESPONSE:
case LLRP_TYPE_DELETE_ACCESSSPEC_RESPONSE:
case LLRP_TYPE_ENABLE_ACCESSSPEC_RESPONSE:
case LLRP_TYPE_DISABLE_ACCESSSPEC_RESPONSE:
case LLRP_TYPE_GET_ACCESSSPECS:
case LLRP_TYPE_CLIENT_REQUEST_OP:
case LLRP_TYPE_CLIENT_RESQUEST_OP_RESPONSE:
case LLRP_TYPE_RO_ACCESS_REPORT:
case LLRP_TYPE_READER_EVENT_NOTIFICATION:
case LLRP_TYPE_ERROR_MESSAGE:
case LLRP_TYPE_GET_READER_CONFIG_RESPONSE:
case LLRP_TYPE_SET_READER_CONFIG_RESPONSE:
case LLRP_TYPE_SET_PROTOCOL_VERSION_RESPONSE:
case LLRP_TYPE_GET_ACCESSSPECS_RESPONSE:
case LLRP_TYPE_GET_REPORT:
case LLRP_TYPE_ENABLE_EVENTS_AND_REPORTS:
dissect_llrp_parameters(tvb, pinfo, tree, offset);
break;
case LLRP_TYPE_START_ROSPEC:
case LLRP_TYPE_STOP_ROSPEC:
case LLRP_TYPE_ENABLE_ROSPEC:
case LLRP_TYPE_DISABLE_ROSPEC:
case LLRP_TYPE_DELETE_ROSPEC:
spec_id = tvb_get_ntohl(tvb, offset);
if (spec_id == LLRP_ROSPEC_ALL)
proto_tree_add_uint_format(tree, hf_llrp_rospec, tvb,
offset, 4, spec_id, "All ROSpecs (%u)", spec_id);
else
proto_tree_add_item(tree, hf_llrp_rospec, tvb,
offset, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TYPE_ENABLE_ACCESSSPEC:
case LLRP_TYPE_DELETE_ACCESSSPEC:
case LLRP_TYPE_DISABLE_ACCESSSPEC:
spec_id = tvb_get_ntohl(tvb, offset);
if (spec_id == LLRP_ACCESSSPEC_ALL)
proto_tree_add_uint_format(tree, hf_llrp_accessspec, tvb,
offset, 4, spec_id, "All Access Specs (%u)", spec_id);
else
proto_tree_add_item(tree, hf_llrp_accessspec, tvb,
offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_llrp_accessspec, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TYPE_GET_READER_CAPABILITES:
proto_tree_add_item(tree, hf_llrp_req_cap, tvb, offset, 1, ENC_NA);
offset++;
dissect_llrp_parameters(tvb, pinfo, tree, offset);
break;
case LLRP_TYPE_GET_READER_CONFIG:
requested_data = tvb_get_guint8(tvb, offset + 2);
switch (requested_data)
{
case LLRP_CONF_ALL:
antenna_id = tvb_get_ntohs(tvb, offset);
if (antenna_id == LLRP_ANTENNA_ALL)
proto_tree_add_uint_format(tree, hf_llrp_antenna_id, tvb,
offset, 2, antenna_id, "All Antennas (%u)", antenna_id);
else
proto_tree_add_item(tree, hf_llrp_antenna_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_llrp_req_conf, tvb,
offset, 1, ENC_NA);
offset++;
gpi_port = tvb_get_ntohs(tvb, offset);
if (gpi_port == LLRP_GPI_PORT_ALL)
proto_tree_add_uint_format(tree, hf_llrp_gpi_port, tvb,
offset, 2, gpi_port, "All GPI Ports (%u)", gpi_port);
else
proto_tree_add_item(tree, hf_llrp_gpi_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
gpo_port = tvb_get_ntohs(tvb, offset);
if (gpo_port == LLRP_GPO_PORT_ALL)
proto_tree_add_uint_format(tree, hf_llrp_gpo_port, tvb,
offset, 2, gpo_port, "All GPO Ports (%u)", gpo_port);
else
proto_tree_add_item(tree, hf_llrp_gpo_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case LLRP_CONF_ANTENNA_PROPERTIES:
case LLRP_CONF_ANTENNA_CONFIGURATION:
antenna_id = tvb_get_ntohs(tvb, offset);
if (antenna_id == LLRP_ANTENNA_ALL)
proto_tree_add_uint_format(tree, hf_llrp_antenna_id, tvb,
offset, 2, antenna_id, "All Antennas (%u)", antenna_id);
else
proto_tree_add_item(tree, hf_llrp_antenna_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_llrp_req_conf, tvb,
offset, 1, ENC_NA);
offset++;
offset += 4;
break;
case LLRP_CONF_IDENTIFICATION:
case LLRP_CONF_RO_REPORT_SPEC:
case LLRP_CONF_READER_EVENT_NOTIFICATION_SPEC:
case LLRP_CONF_ACCESS_REPORT_SPEC:
case LLRP_CONF_LLRP_CONFIGURATION_STATE:
case LLRP_CONF_KEEPALIVE_SPEC:
case LLRP_CONF_EVENTS_AND_REPORTS:
offset += 2;
proto_tree_add_item(tree, hf_llrp_req_conf, tvb,
offset, 1, ENC_NA);
offset++;
offset += 4;
break;
case LLRP_CONF_GPI_PORT_CURRENT_STATE:
offset += 2;
proto_tree_add_item(tree, hf_llrp_req_conf, tvb,
offset, 1, ENC_NA);
offset++;
gpi_port = tvb_get_ntohs(tvb, offset);
if (gpi_port == LLRP_GPI_PORT_ALL)
proto_tree_add_uint_format(tree, hf_llrp_gpi_port, tvb,
offset, 2, gpi_port, "All GPI Ports (%u)", gpi_port);
else
proto_tree_add_item(tree, hf_llrp_gpi_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += 2;
break;
case LLRP_CONF_GPO_WRITE_DATA:
offset += 2;
proto_tree_add_item(tree, hf_llrp_req_conf, tvb,
offset, 1, ENC_NA);
offset++;
offset += 2;
gpo_port = tvb_get_ntohs(tvb, offset);
if (gpo_port == LLRP_GPO_PORT_ALL)
proto_tree_add_uint_format(tree, hf_llrp_gpo_port, tvb,
offset, 2, gpo_port, "All GPO Ports (%u)", gpo_port);
else
proto_tree_add_item(tree, hf_llrp_gpo_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
default:
offset += 2;
ti = proto_tree_add_item(tree, hf_llrp_req_conf, tvb,
offset, 1, ENC_NA);
expert_add_info_format(pinfo, ti, PI_MALFORMED, PI_ERROR,
"Unrecognized configuration request: %u",
requested_data);
offset++;
offset += 4;
break;
};
dissect_llrp_parameters(tvb, pinfo, tree, offset);
break;
case LLRP_TYPE_SET_READER_CONFIG:
proto_tree_add_item(tree, hf_llrp_rest_fact, tvb, offset, 1, ENC_NA);
offset++;
dissect_llrp_parameters(tvb, pinfo, tree, offset);
break;
case LLRP_TYPE_SET_PROTOCOL_VERSION:
proto_tree_add_item(tree, hf_llrp_version, tvb, offset, 1, ENC_NA);
break;
case LLRP_TYPE_GET_SUPPORTED_VERSION_RESPONSE:
proto_tree_add_item(tree, hf_llrp_cur_ver, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_llrp_sup_ver, tvb, offset, 1, ENC_NA);
offset++;
dissect_llrp_parameters(tvb, pinfo, tree, offset);
break;
case LLRP_TYPE_CUSTOM_MESSAGE:
proto_tree_add_item(tree, hf_llrp_vendor, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TYPE_KEEPALIVE:
case LLRP_TYPE_KEEPALIVE_ACK:
case LLRP_TYPE_CLOSE_CONNECTION:
case LLRP_TYPE_GET_ROSPECS:
case LLRP_TYPE_GET_SUPPORTED_VERSION:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
};
}
static int
dissect_llrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *llrp_tree;
guint16 type;
guint32 len;
guint offset = 0;
if (tvb_reported_length(tvb) < LLRP_LEN_MIN)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LLRP");
col_set_str(pinfo->cinfo, COL_INFO, "LLRP Message");
type = tvb_get_ntohs(tvb, offset) & 0x03FF;
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
val_to_str(type, message_types, "Unknown Type: %d"));
ti = proto_tree_add_item(tree, proto_llrp, tvb, offset, -1, ENC_NA);
llrp_tree = proto_item_add_subtree(ti, ett_llrp);
proto_tree_add_item(llrp_tree, hf_llrp_version, tvb, offset, 1, ENC_NA);
proto_tree_add_item(llrp_tree, hf_llrp_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_item(llrp_tree, hf_llrp_length, tvb, offset, 4, ENC_BIG_ENDIAN);
len = tvb_get_ntohl(tvb, offset);
if (len > tvb_reported_length(tvb))
{
expert_add_info_format(pinfo, ti, PI_MALFORMED, PI_ERROR,
"Incorrect length field: claimed %u, but only have %u.",
len, tvb_reported_length(tvb));
}
offset += 4;
proto_tree_add_item(llrp_tree, hf_llrp_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (match_strval(type, message_types))
dissect_llrp_message(tvb, pinfo, llrp_tree, type, offset);
return tvb_length(tvb);
}
void
proto_register_llrp(void)
{
static hf_register_info hf[] = {
{ &hf_llrp_version,
{ "Version", "llrp.version", FT_UINT8, BASE_DEC, VALS(llrp_versions), 0x1C,
NULL, HFILL }},
{ &hf_llrp_type,
{ "Type", "llrp.type", FT_UINT16, BASE_DEC, VALS(message_types), 0x03FF,
NULL, HFILL }},
{ &hf_llrp_length,
{ "Length", "llrp.length", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_id,
{ "ID", "llrp.id", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_cur_ver,
{ "Current Version", "llrp.cur_ver", FT_UINT8, BASE_DEC, VALS(llrp_versions), 0,
NULL, HFILL }},
{ &hf_llrp_sup_ver,
{ "Supported Version", "llrp.sup_ver", FT_UINT8, BASE_DEC, VALS(llrp_versions), 0,
"The max supported protocol version.", HFILL }},
{ &hf_llrp_req_cap,
{ "Requested Capabilities", "llrp.req_cap", FT_UINT8, BASE_DEC, VALS(capabilities_request), 0,
NULL, HFILL }},
{ &hf_llrp_req_conf,
{ "Requested Configuration", "llrp.req_conf", FT_UINT8, BASE_DEC, VALS(config_request), 0,
NULL, HFILL }},
{ &hf_llrp_rospec,
{ "ROSpec ID", "llrp.rospec", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_antenna_id,
{ "Antenna ID", "llrp.antenna_id", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_gpi_port,
{ "GPI Port Number", "llrp.gpi_port", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_gpo_port,
{ "GPO Port Number", "llrp.gpo_port", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_rest_fact,
{ "Restore Factory Settings", "llrp.rest_fact", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_accessspec,
{ "Access Spec ID", "llrp.accessspec", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_vendor,
{ "Vendor ID", "llrp.vendor", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_tlv_type,
{ "Type", "llrp.tlv_type", FT_UINT16, BASE_DEC, VALS(tlv_type), 0x03FF,
"The type of TLV.", HFILL }},
{ &hf_llrp_tv_type,
{ "Type", "llrp.tv_type", FT_UINT8, BASE_DEC, VALS(tv_type), 0x7F,
"The type of TV.", HFILL }},
{ &hf_llrp_tlv_len,
{ "Length", "llrp.tlv_len", FT_UINT16, BASE_DEC, NULL, 0,
"The length of this TLV.", HFILL }},
{ &hf_llrp_param,
{ "Parameter", "llrp.param", FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_llrp,
&ett_llrp_param
};
proto_llrp = proto_register_protocol("Low Level Reader Protocol",
"LLRP", "llrp");
proto_register_field_array(proto_llrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_llrp(void)
{
dissector_handle_t llrp_handle;
llrp_handle = new_create_dissector_handle(dissect_llrp, proto_llrp);
dissector_add_uint("tcp.port", LLRP_PORT, llrp_handle);
}
