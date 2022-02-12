static int
dissect_dvb_data_mpe(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0, tot_len = 0;
guint8 llc_snap_flag;
int i;
proto_item *ti;
proto_tree *dvb_data_mpe_tree;
tvbuff_t *mac_tvb;
tvbuff_t *mac_bytes_tvb[6];
tvbuff_t *data_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DVB-DATA");
col_set_str(pinfo->cinfo, COL_INFO, "MultiProtocol Encapsulation");
ti = proto_tree_add_item(tree, proto_dvb_data_mpe, tvb, offset, -1, ENC_NA);
dvb_data_mpe_tree = proto_item_add_subtree(ti, ett_dvb_data_mpe);
offset += packet_mpeg_sect_header(tvb, offset, dvb_data_mpe_tree, &tot_len, NULL);
mac_bytes_tvb[5] = tvb_new_subset_length(tvb, offset, 1);
offset += 1;
mac_bytes_tvb[4] = tvb_new_subset_length(tvb, offset, 1);
offset += 1;
proto_tree_add_item(dvb_data_mpe_tree, hf_dvb_data_mpe_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_data_mpe_tree, hf_dvb_data_mpe_payload_scrambling_control, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_data_mpe_tree, hf_dvb_data_mpe_address_scrambling_control, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_data_mpe_tree, hf_dvb_data_mpe_llc_snap_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_data_mpe_tree, hf_dvb_data_mpe_current_next_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
llc_snap_flag = tvb_get_guint8(tvb, offset) & DVB_DATA_MPE_LLC_SNAP_FLAG_MASK;
offset += 1;
proto_tree_add_item(dvb_data_mpe_tree, hf_dvb_data_mpe_section_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(dvb_data_mpe_tree, hf_dvb_data_mpe_last_section_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
for (i = 3; i >= 0; i--) {
mac_bytes_tvb[i] = tvb_new_subset_length(tvb, offset, 1);
offset += 1;
}
mac_tvb = tvb_new_composite();
for (i = 0; i < 6; i++)
tvb_composite_append(mac_tvb, mac_bytes_tvb[i]);
tvb_composite_finalize(mac_tvb);
proto_tree_add_item(dvb_data_mpe_tree, hf_dvb_data_mpe_dst_mac, mac_tvb, 0 , 6, ENC_NA);
col_add_str(pinfo->cinfo, COL_RES_DL_DST, tvb_ether_to_str(mac_tvb, 0));
data_tvb = tvb_new_subset_remaining(tvb, offset);
if (llc_snap_flag) {
call_dissector(llc_handle, data_tvb, pinfo, tree);
} else {
call_dissector(ip_handle, data_tvb, pinfo, tree);
}
packet_mpeg_sect_crc(tvb, pinfo, dvb_data_mpe_tree, 0, tot_len - 1);
return tvb_captured_length(tvb);
}
void
proto_register_dvb_data_mpe(void)
{
static hf_register_info hf[] = {
{ &hf_dvb_data_mpe_reserved, {
"Reserved", "dvb_data_mpe.reserved",
FT_UINT8, BASE_HEX, NULL, DVB_DATA_MPE_RESERVED_MASK, NULL, HFILL
} },
{ &hf_dvb_data_mpe_payload_scrambling_control, {
"Payload Scrambling Control", "dvb_data_mpe.pload_scrambling",
FT_UINT8, BASE_HEX, NULL, DVB_DATA_MPE_PAYLOAD_SCRAMBLING_MASK, NULL, HFILL
} },
{ &hf_dvb_data_mpe_address_scrambling_control, {
"Address Scrambling Control", "dvb_data_mpe.addr_scrambling",
FT_UINT8, BASE_HEX, NULL, DVB_DATA_MPE_ADDRESS_SCRAMBLING_MASK, NULL, HFILL
} },
{ &hf_dvb_data_mpe_llc_snap_flag, {
"LLC SNAP Flag", "dvb_data_mpe.llc_snap_flag",
FT_UINT8, BASE_HEX, NULL, DVB_DATA_MPE_LLC_SNAP_FLAG_MASK, NULL, HFILL
} },
{ &hf_dvb_data_mpe_current_next_indicator, {
"Current/Next Indicator", "mpeg_sect.cur_next_ind",
FT_UINT8, BASE_HEX, VALS(dvb_rcs_cur_next_vals), DVB_DATA_MPE_CURRENT_NEXT_INDICATOR_MASK, NULL, HFILL
} },
{ &hf_dvb_data_mpe_section_number, {
"Section Number", "dvb_data_mpe.sect_num",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_data_mpe_last_section_number, {
"Last Section Number", "dvb_data_mpe.last_sect_num",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_data_mpe_dst_mac, {
"Destination MAC address", "dvb_data_mpe.dst_mac",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
};
static gint *ett[] = {
&ett_dvb_data_mpe,
};
proto_dvb_data_mpe = proto_register_protocol("DVB-DATA MultiProtocol Encapsulation", "DVB-DATA MPE", "dvb_data_mpe");
proto_register_field_array(proto_dvb_data_mpe, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dvb_data_mpe(void)
{
dissector_handle_t dvb_data_mpe_handle;
dvb_data_mpe_handle = create_dissector_handle(dissect_dvb_data_mpe, proto_dvb_data_mpe);
dissector_add_uint("mpeg_sect.tid", DVB_DATA_MPE_TID, dvb_data_mpe_handle);
ip_handle = find_dissector_add_dependency("ip", proto_dvb_data_mpe);
llc_handle = find_dissector_add_dependency("llc", proto_dvb_data_mpe);
}
