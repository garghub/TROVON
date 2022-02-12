static int
dissect_dlsw_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint version,hlen = 0,mlen = 0,mtype,dlchlen = 0,flags;
proto_tree *dlsw_tree, *dlsw_header_tree = NULL;
proto_item *ti,*ti2;
proto_tree *dlsw_flags_tree,*dlsw_data_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DLSw");
version=tvb_get_guint8(tvb,0);
col_add_fstr(pinfo->cinfo, COL_INFO, "DLSw %s",val_to_str_const(version , dlsw_version_vals, "Unknown Version"));
ti = proto_tree_add_item(tree, proto_dlsw, tvb, 0, -1, ENC_NA);
dlsw_tree = proto_item_add_subtree(ti, ett_dlsw);
hlen=tvb_get_guint8(tvb,1);
dlsw_header_tree = proto_tree_add_subtree_format(dlsw_tree, tvb, 0, hlen, ett_dlsw_header, NULL,
"DLSw header, %s",
val_to_str_const(version , dlsw_version_vals, "Unknown Version"));
proto_tree_add_item(dlsw_header_tree, hf_dlsw_version, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_header_length, tvb, 1, 1, ENC_BIG_ENDIAN);
mlen=tvb_get_ntohs(tvb,2);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_message_length, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_remote_dlc, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_remote_dlc_pid, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_reserved, tvb, 12, 2, ENC_NA) ;
mtype=tvb_get_guint8(tvb,14);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",val_to_str_const(mtype , dlsw_type_vals, "Unknown message Type"));
proto_tree_add_item(dlsw_header_tree, hf_dlsw_message_type, tvb, 14, 1, ENC_BIG_ENDIAN);
if (mtype==CAP_EXCHANGE)
{
proto_tree_add_expert(dlsw_header_tree, pinfo, &ei_dlsw_not_used_for_capex, tvb, 15, 1);
}
else
{
flags = tvb_get_guint8(tvb,15);
ti2 = proto_tree_add_item(dlsw_header_tree, hf_dlsw_flow_ctrl_byte, tvb, 15, 1, ENC_BIG_ENDIAN);
dlsw_flags_tree = proto_item_add_subtree(ti2, ett_dlsw_fc);
proto_tree_add_item(dlsw_flags_tree, hf_dlsw_flow_control_indication, tvb, 15, 1, ENC_BIG_ENDIAN);
if (flags & 0x80)
{
proto_tree_add_item(dlsw_flags_tree, hf_dlsw_flow_control_ack, tvb, 15, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_flags_tree, hf_dlsw_flow_control_operator, tvb, 15, 1, ENC_BIG_ENDIAN);
}
}
if (hlen != DLSW_INFO_HEADER)
{
if (mtype==CAP_EXCHANGE)
{
proto_tree_add_item(dlsw_header_tree, hf_dlsw_protocol_id, tvb, 16, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_header_number, tvb, 17, 1, ENC_BIG_ENDIAN);
proto_tree_add_expert(dlsw_header_tree, pinfo, &ei_dlsw_not_used_for_capex, tvb, 18, 5);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_old_message_type, tvb, 23, 1, ENC_BIG_ENDIAN);
proto_tree_add_expert(dlsw_header_tree, pinfo, &ei_dlsw_not_used_for_capex, tvb, 24, 14);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_capex_type, tvb, 38, 1, ENC_BIG_ENDIAN);
proto_tree_add_expert(dlsw_header_tree, pinfo, &ei_dlsw_not_used_for_capex, tvb, 39, 33);
}
else
{
proto_tree_add_item(dlsw_header_tree, hf_dlsw_protocol_id, tvb, 16, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_header_number, tvb, 17, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_reserved, tvb, 18, 2, ENC_NA) ;
proto_tree_add_item(dlsw_header_tree, hf_dlsw_largest_frame_size, tvb, 20, 1, ENC_BIG_ENDIAN);
ti2 = proto_tree_add_item(dlsw_header_tree, hf_dlsw_ssp_flags, tvb, 21, 1, ENC_BIG_ENDIAN);
dlsw_flags_tree = proto_item_add_subtree(ti2, ett_dlsw_sspflags);
proto_tree_add_item (dlsw_flags_tree, hf_dlsw_flags_explorer_msg, tvb, 21, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_circuit_priority, tvb, 22, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_old_message_type, tvb, 23, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_target_mac_address, tvb, 24, 6, ENC_NA);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_origin_mac_address, tvb, 30, 6, ENC_NA);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_origin_link_sap, tvb, 36, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_target_link_sap, tvb, 37, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_frame_direction, tvb, 38, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_reserved, tvb, 39, 3, ENC_NA) ;
dlchlen=tvb_get_ntohs(tvb,42);
ti = proto_tree_add_item(dlsw_header_tree, hf_dlsw_dlc_header_length, tvb, 42, 2, ENC_BIG_ENDIAN);
if ( dlchlen > mlen )
{
expert_add_info_format(pinfo, ti, &ei_dlsw_dlc_header_length,
"DLC Header Length = %u (bogus, must be <= message length %u)",dlchlen, mlen) ;
return 44;
}
proto_tree_add_item(dlsw_header_tree, hf_dlsw_origin_dlc_port_id, tvb, 44, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_origin_dlc, tvb, 48, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_origin_transport_id, tvb, 52, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_target_dlc_port_id, tvb, 56, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_target_dlc, tvb, 60, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_target_transport_id, tvb, 64, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_header_tree, hf_dlsw_reserved, tvb, 68, 4, ENC_NA) ;
}
}
dlsw_data_tree = proto_tree_add_subtree(dlsw_tree, tvb, hlen, mlen, ett_dlsw_data, &ti2, "DLSw data");
switch (mtype)
{
case CAP_EXCHANGE:
dissect_dlsw_capex(tvb_new_subset(tvb, hlen, mlen, -1), pinfo, dlsw_data_tree, ti2);
break;
case IFCM:
case INFOFRAME:
case KEEPALIVE:
proto_tree_add_item(dlsw_data_tree, hf_dlsw_data, tvb, hlen, mlen, ENC_NA);
break;
default:
if (dlchlen!=0)
{
proto_tree_add_item(dlsw_data_tree, hf_dlsw_dlc_header_ac_byte, tvb, hlen, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_data_tree, hf_dlsw_dlc_header_fc_byte, tvb, hlen+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_data_tree, hf_dlsw_dlc_header_da, tvb, hlen+2, 6, ENC_NA|ENC_ASCII);
proto_tree_add_item(dlsw_data_tree, hf_dlsw_dlc_header_sa, tvb, hlen+8, 6, ENC_NA|ENC_ASCII);
proto_tree_add_item(dlsw_data_tree, hf_dlsw_dlc_header_rif, tvb, hlen+14, 18, ENC_NA|ENC_ASCII);
proto_tree_add_item(dlsw_data_tree, hf_dlsw_dlc_header_dsap, tvb, hlen+32, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_data_tree, hf_dlsw_dlc_header_ssap, tvb, hlen+33, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_data_tree, hf_dlsw_dlc_header_ctrl, tvb, hlen+34, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(dlsw_data_tree, hf_dlsw_data, tvb, hlen+dlchlen, mlen-dlchlen, ENC_NA);
}
return tvb_captured_length(tvb);
}
static void
dlsw_fmt_version( gchar *result, guint32 revision )
{
g_snprintf( result, ITEM_LABEL_LENGTH, "%d.%02d", (guint8)(( revision & 0xFF00 ) >> 8), (guint8)(revision & 0xFF) );
}
static void
dissect_dlsw_capex(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_tree *ti2)
{
int vlen,vtype,i=0;
guint8 tmp8;
guint32 gdsid, mlen,offset=4;
proto_tree *dlsw_vector_tree;
proto_tree_add_item_ret_uint(tree, hf_dlsw_capabilities_length, tvb, 0, 2, ENC_BIG_ENDIAN, &mlen);
proto_tree_add_item_ret_uint(tree, hf_dlsw_gds_id, tvb, 2, 2, ENC_BIG_ENDIAN, &gdsid);
proto_item_append_text(ti2," - %s",val_to_str_const( gdsid, dlsw_gds_vals, "Invalid GDS ID"));
switch (gdsid) {
case DLSW_GDSID_ACK:
break;
case DLSW_GDSID_REF:
proto_tree_add_item(tree, hf_dlsw_error_pointer, tvb, 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dlsw_error_cause, tvb, 6, 2, ENC_BIG_ENDIAN);
break;
case DLSW_GDSID_SEND:
while (offset < mlen){
vlen=tvb_get_guint8(tvb,offset);
if (vlen < 3) {
proto_tree_add_expert(tree, pinfo, &ei_dlsw_vec_len_invalid, tvb, offset, 1);
return;
}
vtype=tvb_get_guint8(tvb,offset+1);
dlsw_vector_tree=proto_tree_add_subtree (tree,tvb,offset,vlen,ett_dlsw_vector,NULL,
val_to_str_const(vtype,dlsw_vector_vals,"Unknown vector type"));
proto_tree_add_item(dlsw_vector_tree, hf_dlsw_vector_length, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dlsw_vector_tree, hf_dlsw_vector_type, tvb, offset+1, 1, ENC_BIG_ENDIAN);
switch (vtype){
case 0x81:
proto_tree_add_item(dlsw_vector_tree, hf_dlsw_oui, tvb, offset+2, vlen-2, ENC_BIG_ENDIAN);
break;
case 0x82:
proto_tree_add_item(dlsw_vector_tree, hf_dlsw_dlsw_version, tvb, offset+2, 2, ENC_BIG_ENDIAN);
break;
case 0x83:
proto_tree_add_item(dlsw_vector_tree, hf_dlsw_initial_pacing_window, tvb, offset+2, vlen-2, ENC_BIG_ENDIAN);
break;
case 0x84:
proto_tree_add_item(dlsw_vector_tree, hf_dlsw_version_string, tvb, offset+2, vlen-2, ENC_NA|ENC_ASCII);
break;
case 0x85:
tmp8 = tvb_get_guint8(tvb,offset+2);
proto_tree_add_uint_format_value(dlsw_vector_tree, hf_dlsw_mac_address_exclusivity, tvb,offset+2, 1,
tmp8, "%s",tmp8==1?"On":"Off");
break;
case 0x86:
while (i<vlen-2)
{
static const int * flags[] = {
&hf_dlsw_sap_list_support_x0,
&hf_dlsw_sap_list_support_x2,
&hf_dlsw_sap_list_support_x4,
&hf_dlsw_sap_list_support_x6,
&hf_dlsw_sap_list_support_x8,
&hf_dlsw_sap_list_support_xA,
&hf_dlsw_sap_list_support_xC,
&hf_dlsw_sap_list_support_xE,
NULL
};
proto_tree_add_bitmask_with_flags(dlsw_vector_tree, tvb, offset+2+i, hf_dlsw_sap_list_support, ett_dlsw_sap_list_support, flags, ENC_NA, BMT_NO_FALSE);
i++;
}
break;
case 0x87:
proto_tree_add_item(dlsw_vector_tree, hf_dlsw_tcp_connections, tvb, offset+2, vlen-2, ENC_BIG_ENDIAN);
break;
case 0x88:
tmp8 = tvb_get_guint8(tvb,offset+2);
proto_tree_add_uint_format_value(dlsw_vector_tree, hf_dlsw_netbios_name_exclusivity, tvb,offset+2,1,
tmp8, "%s", tmp8==1?"On":"Off");
break;
case 0x89:
proto_tree_add_item(dlsw_vector_tree, hf_dlsw_mac_address_list, tvb, offset+2, 6, ENC_NA);
proto_tree_add_item(dlsw_vector_tree, hf_dlsw_mac_address_list, tvb, offset+8, 6, ENC_NA);
break;
case 0x8a:
proto_tree_add_item(dlsw_vector_tree, hf_dlsw_netbios_name, tvb, offset+2, vlen-2, ENC_NA|ENC_ASCII);
break;
case 0x8b:
proto_tree_add_item(dlsw_vector_tree, hf_dlsw_vendor_oui, tvb, offset+2, vlen-2, ENC_BIG_ENDIAN);
break;
case 0x8c:
proto_tree_add_item(dlsw_vector_tree, hf_dlsw_multicast_version_number, tvb, offset+2, vlen-2, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(dlsw_vector_tree, hf_dlsw_vector_data, tvb, offset+2, vlen-2, ENC_NA);
}
offset+=vlen;
};
break;
default:
proto_tree_add_item(tree, hf_dlsw_unknown_data, tvb, 4, mlen - 4, ENC_NA);
}
}
static int
dissect_dlsw_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if (try_val_to_str(tvb_get_guint8(tvb, 0), dlsw_version_vals) == NULL)
{
return 0;
}
return dissect_dlsw_pdu(tvb, pinfo, tree, data);
}
static guint
get_dlsw_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint hlen, mlen;
hlen=tvb_get_guint8(tvb,offset+1);
mlen = tvb_get_ntohs(tvb,offset+2);
return hlen + mlen;
}
static int
dissect_dlsw_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if (try_val_to_str(tvb_get_guint8(tvb, 0), dlsw_version_vals) == NULL)
{
return 0;
}
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 4, get_dlsw_pdu_len, dissect_dlsw_pdu, data);
return tvb_captured_length(tvb);
}
void
proto_register_dlsw(void)
{
static hf_register_info hf[] = {
{&hf_dlsw_flow_control_indication,
{"Flow Control Indication", "dlsw.flow_control_indication", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL}},
{&hf_dlsw_flow_control_ack,
{"Flow Control Acknowledgment", "dlsw.flow_control_ack", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL}},
{&hf_dlsw_flow_control_operator,
{"Flow Control Operator", "dlsw.flow_control_operator", FT_UINT8, BASE_DEC, VALS(dlsw_fc_cmd_vals), 0x07,
NULL, HFILL}},
{&hf_dlsw_flags_explorer_msg,
{"Explorer message", "dlsw.flags.explorer_msg", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL}},
{ &hf_dlsw_version, { "Version", "dlsw.version", FT_UINT8, BASE_DEC, VALS(dlsw_version_vals), 0x0, NULL, HFILL }},
{ &hf_dlsw_header_length, { "Header Length", "dlsw.header_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_message_length, { "Message Length", "dlsw.message_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_remote_dlc, { "Remote DLC", "dlsw.remote_dlc", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_remote_dlc_pid, { "Remote DLC PID", "dlsw.remote_dlc_pid", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_message_type, { "Message Type", "dlsw.message_type", FT_UINT8, BASE_HEX, VALS(dlsw_type_vals), 0x0, NULL, HFILL }},
{ &hf_dlsw_flow_ctrl_byte, { "Flow ctrl byte", "dlsw.flow_ctrl_byte", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_protocol_id, { "Protocol ID", "dlsw.protocol_id", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_header_number, { "Header Number", "dlsw.header_number", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_old_message_type, { "Old message type", "dlsw.old_message_type", FT_UINT8, BASE_HEX, VALS(dlsw_type_vals), 0x0, NULL, HFILL }},
{ &hf_dlsw_capex_type, { "Capability exchange type", "dlsw.capex_type", FT_UINT8, BASE_HEX, VALS(dlsw_capex_type_vals), 0x0, NULL, HFILL }},
{ &hf_dlsw_largest_frame_size, { "Largest Frame size", "dlsw.largest_frame_size", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_ssp_flags, { "SSP Flags", "dlsw.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_circuit_priority, { "Circuit priority", "dlsw.circuit_priority", FT_UINT8, BASE_DEC, VALS(dlsw_pri_vals), 0x7, NULL, HFILL }},
{ &hf_dlsw_target_mac_address, { "Target MAC Address", "dlsw.target_mac_address", FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_origin_mac_address, { "Origin MAC Address", "dlsw.origin_mac_address", FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_origin_link_sap, { "Origin Link SAP", "dlsw.origin_link_sap", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_target_link_sap, { "Target Link SAP", "dlsw.target_link_sap", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_frame_direction, { "Frame direction", "dlsw.frame_direction", FT_UINT8, BASE_HEX, VALS(dlsw_frame_direction_vals), 0x0, NULL, HFILL }},
{ &hf_dlsw_dlc_header_length, { "DLC Header Length", "dlsw.dlc_header_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_origin_dlc_port_id, { "Origin DLC Port ID", "dlsw.origin_dlc_port_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_origin_dlc, { "Origin DLC", "dlsw.origin_dlc", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_origin_transport_id, { "Origin Transport ID", "dlsw.origin_transport_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_target_dlc_port_id, { "Target DLC Port ID", "dlsw.target_dlc_port_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_target_dlc, { "Target DLC", "dlsw.target_dlc", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_target_transport_id, { "Target Transport ID", "dlsw.target_transport_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_dlc_header_ac_byte, { "DLC Header - AC byte", "dlsw.dlc_header.ac_byte", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_dlc_header_fc_byte, { "DLC Header - FC byte", "dlsw.dlc_header.fc_byte", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_dlc_header_da, { "DLC Header - DA", "dlsw.dlc_header.da", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_dlc_header_sa, { "DLC Header - SA", "dlsw.dlc_header.sa", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_dlc_header_rif, { "DLC Header - RIF", "dlsw.dlc_header.rif", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_dlc_header_dsap, { "DLC Header - DSAP", "dlsw.dlc_header.dsap", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_dlc_header_ssap, { "DLC Header - SSAP", "dlsw.dlc_header.ssap", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_dlc_header_ctrl, { "DLC Header - Ctrl", "dlsw.dlc_header.ctrl", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_capabilities_length, { "Capabilities Length", "dlsw.capabilities_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_error_pointer, { "Error pointer", "dlsw.error_pointer", FT_INT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_error_cause, { "Error cause", "dlsw.error_cause", FT_UINT16, BASE_HEX, VALS(dlsw_refuse_vals), 0x0, NULL, HFILL }},
{ &hf_dlsw_vector_length, { "Vector Length", "dlsw.vector_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_vector_type, { "Vector Type", "dlsw.vector_type", FT_UINT8, BASE_HEX, VALS(dlsw_vector_vals), 0x0, NULL, HFILL }},
{ &hf_dlsw_oui, { "OUI", "dlsw.oui", FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_initial_pacing_window, { "Initial Pacing Window", "dlsw.initial_pacing_window", FT_INT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_dlsw_version, { "DLSw Version", "dlsw.dlsw_version", FT_UINT16, BASE_CUSTOM, CF_FUNC(dlsw_fmt_version), 0x0, NULL, HFILL }},
{ &hf_dlsw_version_string, { "Version String", "dlsw.version_string", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_tcp_connections, { "TCP connections", "dlsw.tcp_connections", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_mac_address_list, { "MAC Address List", "dlsw.mac_address_list", FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_netbios_name, { "NetBIOS name", "dlsw.netbios_name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_vendor_oui, { "Vendor OUI", "dlsw.vendor_oui", FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_multicast_version_number, { "Multicast Version Number", "dlsw.multicast_version_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_reserved, { "Reserved", "dlsw.reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_data, { "Data", "dlsw.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_vector_data, { "Data", "dlsw.vector_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_unknown_data, { "Data", "dlsw.unknown_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_mac_address_exclusivity, { "MAC Address Exclusivity", "dlsw.mac_address_exclusivity", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_netbios_name_exclusivity, { "NetBIOS Name Exclusivity", "dlsw.netbios_name_exclusivity", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_gds_id, { "GDS ID", "dlsw.gds_id", FT_UINT16, BASE_DEC, VALS(dlsw_gds_vals), 0x0, NULL, HFILL }},
{ &hf_dlsw_sap_list_support, { "SAP List Support", "dlsw.sap_list_support", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dlsw_sap_list_support_x0, { "x0", "dlsw.sap_list_support.x0", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x80, NULL, HFILL }},
{ &hf_dlsw_sap_list_support_x2, { "x0", "dlsw.sap_list_support.x2", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x40, NULL, HFILL }},
{ &hf_dlsw_sap_list_support_x4, { "x0", "dlsw.sap_list_support.x4", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x20, NULL, HFILL }},
{ &hf_dlsw_sap_list_support_x6, { "x0", "dlsw.sap_list_support.x6", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x10, NULL, HFILL }},
{ &hf_dlsw_sap_list_support_x8, { "x0", "dlsw.sap_list_support.x8", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x08, NULL, HFILL }},
{ &hf_dlsw_sap_list_support_xA, { "x0", "dlsw.sap_list_support.xA", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x04, NULL, HFILL }},
{ &hf_dlsw_sap_list_support_xC, { "x0", "dlsw.sap_list_support.xC", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x02, NULL, HFILL }},
{ &hf_dlsw_sap_list_support_xE, { "x0", "dlsw.sap_list_support.xE", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x01, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dlsw,
&ett_dlsw_header,
&ett_dlsw_fc,
&ett_dlsw_sspflags,
&ett_dlsw_data,
&ett_dlsw_vector,
&ett_dlsw_sap_list_support,
};
static ei_register_info ei[] = {
{ &ei_dlsw_dlc_header_length, { "dlsw.dlc_header_length.bogus", PI_PROTOCOL, PI_WARN, "DLC Header Length bogus", EXPFILL }},
{ &ei_dlsw_not_used_for_capex, { "dlsw.not_used_for_capex", PI_PROTOCOL, PI_NOTE, "Not used for CapEx", EXPFILL }},
{ &ei_dlsw_vec_len_invalid, { "dlsw.vec_len_invalid", PI_MALFORMED, PI_ERROR, "Invalid vector length (must be >=3)", EXPFILL }}
};
expert_module_t* expert_dlsw;
proto_dlsw = proto_register_protocol("Data Link SWitching", "DLSw", "dlsw");
proto_register_field_array(proto_dlsw, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dlsw = expert_register_protocol(proto_dlsw);
expert_register_field_array(expert_dlsw, ei, array_length(ei));
}
void
proto_reg_handoff_dlsw(void)
{
dissector_handle_t dlsw_udp_handle, dlsw_tcp_handle;
dlsw_udp_handle = new_create_dissector_handle(dissect_dlsw_udp, proto_dlsw);
dissector_add_uint("udp.port", UDP_PORT_DLSW, dlsw_udp_handle);
dlsw_tcp_handle = new_create_dissector_handle(dissect_dlsw_tcp, proto_dlsw);
dissector_add_uint("tcp.port", TCP_PORT_DLSW, dlsw_tcp_handle);
}
