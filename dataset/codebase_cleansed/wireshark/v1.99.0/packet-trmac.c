static int
sv_text(tvbuff_t *tvb, int svoff, packet_info *pinfo, proto_tree *tree)
{
guint sv_length, sv_id;
guint16 beacon_type, ring;
guint32 error_report_timer_value;
proto_tree *sv_tree, *sv_subtree;
proto_item *sv_item, *len_item, *ti;
guchar errors[6];
sv_tree = proto_tree_add_subtree(tree, tvb, svoff+0, 1, ett_tr_sv, &sv_item, "Subvector");
sv_length = tvb_get_guint8(tvb, svoff+0);
len_item = proto_tree_add_item(sv_tree, hf_trmac_sv_len, tvb, svoff+0, 1, ENC_NA);
if (sv_length < 2) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Invalid subvector: length < 2");
return 0;
}
sv_id = tvb_get_guint8(tvb, svoff+1);
proto_tree_add_item(sv_tree, hf_trmac_sv_id, tvb, svoff+1, 1, ENC_NA);
proto_item_append_text(sv_item, " (%s)", val_to_str_ext(sv_id, &subvector_vs_ext, "Unknown subvector ID 0x%02X"));
switch(sv_id) {
case 0x01:
if (sv_length != 4) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 4");
break;
}
beacon_type = tvb_get_ntohs(tvb, svoff+2);
proto_tree_add_item(sv_tree, hf_trmac_beacon_type, tvb, svoff+2, sv_length-2, ENC_BIG_ENDIAN);
proto_item_append_text(sv_item,
": %s", val_to_str(beacon_type, beacon_vs, "Illegal value: %d"));
break;
case 0x02:
if (sv_length != 8) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 8");
break;
}
proto_tree_add_item(sv_tree, hf_trmac_naun, tvb, svoff+2, sv_length-2, ENC_NA);
proto_item_append_text(sv_item, ": %s",
tvb_ether_to_str(tvb, svoff+2));
break;
case 0x03:
if (sv_length != 4) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 4");
break;
}
ring = tvb_get_ntohs(tvb, svoff+2);
proto_tree_add_item(sv_tree, hf_trmac_local_ring_number, tvb, svoff+2, sv_length-2, ENC_BIG_ENDIAN);
proto_item_append_text(sv_item,
": 0x%04X (%d)", ring, ring);
break;
case 0x04:
if (sv_length != 6) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 6");
break;
}
proto_tree_add_item(sv_tree, hf_trmac_assign_physical_drop_number, tvb, svoff+2, sv_length-2, ENC_BIG_ENDIAN);
proto_item_append_text(sv_item,
": 0x%08X", tvb_get_ntohl(tvb, svoff+2) );
break;
case 0x05:
if (sv_length != 4) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 4");
break;
}
error_report_timer_value = 10 * tvb_get_ntohs(tvb, svoff+2);
proto_tree_add_uint_format_value(sv_tree, hf_trmac_error_report_timer_value, tvb, svoff+2, sv_length-2,
error_report_timer_value, "%u ms", error_report_timer_value );
proto_item_append_text(sv_item,
": %u ms", error_report_timer_value );
break;
case 0x06:
if (sv_length != 4) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 4");
break;
}
proto_tree_add_item(sv_tree, hf_trmac_authorized_function_classes, tvb, svoff+2, sv_length-2, ENC_BIG_ENDIAN);
proto_item_append_text(sv_item,
": %04X", tvb_get_ntohs(tvb, svoff+2) );
break;
case 0x07:
if (sv_length != 4) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 4");
break;
}
proto_tree_add_item(sv_tree, hf_trmac_authorized_access_priority, tvb, svoff+2, sv_length-2, ENC_BIG_ENDIAN);
proto_item_append_text(sv_item,
": %04X", tvb_get_ntohs(tvb, svoff+2) );
break;
case 0x09:
if (sv_length != 4) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 4");
break;
}
proto_tree_add_item(sv_tree, hf_trmac_correlator, tvb, svoff+2, sv_length-2, ENC_BIG_ENDIAN);
proto_item_append_text(sv_item,
": %04X", tvb_get_ntohs(tvb, svoff+2) );
break;
case 0x0A:
if (sv_length != 8) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 8");
break;
}
proto_tree_add_item(sv_tree, hf_trmac_sa_of_last_amp_or_smp_frame, tvb, svoff+2, sv_length-2, ENC_NA);
proto_item_append_text(sv_item,
": %s",
tvb_ether_to_str(tvb, svoff+2));
break;
case 0x0B:
if (sv_length != 6) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 6");
break;
}
proto_tree_add_item(sv_tree, hf_trmac_physical_drop_number, tvb, svoff+2, sv_length-2, ENC_BIG_ENDIAN);
proto_item_append_text(sv_item,
": 0x%08X", tvb_get_ntohl(tvb, svoff+2) );
break;
case 0x20:
if (sv_length != 4 && sv_length != 6) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 4 and != 6");
break;
}
if (sv_length == 4) {
proto_tree_add_text(sv_tree, tvb, svoff+2, sv_length-2,
"Response Code: 0x%04X 0x%02X 0x%02x",
tvb_get_ntohs(tvb, svoff+2),
tvb_get_guint8(tvb, svoff+4),
tvb_get_guint8(tvb, svoff+5));
proto_item_append_text(sv_item,
": 0x%04X 0x%02X 0x%02x",
tvb_get_ntohs(tvb, svoff+2),
tvb_get_guint8(tvb, svoff+4),
tvb_get_guint8(tvb, svoff+5));
} else {
proto_tree_add_text(sv_tree, tvb, svoff+2, sv_length-2,
"Response Code: 0x%04X 0x%02X 0x%06X",
tvb_get_ntohs(tvb, svoff+2),
tvb_get_guint8(tvb, svoff+4),
tvb_get_ntoh24(tvb, svoff+5));
proto_item_append_text(sv_item,
": 0x%04X 0x%02X 0x%06X",
tvb_get_ntohs(tvb, svoff+2),
tvb_get_guint8(tvb, svoff+4),
tvb_get_ntoh24(tvb, svoff+5));
}
break;
case 0x21:
if (sv_length != 4) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 4");
break;
}
proto_tree_add_item(sv_tree, hf_trmac_individual_address_count, tvb, svoff+2, sv_length-2, ENC_BIG_ENDIAN);
proto_item_append_text(sv_item,
": %u", tvb_get_ntohs(tvb, svoff+2) );
break;
case 0x22:
proto_tree_add_text(sv_tree, tvb, svoff+2, sv_length-2,
"Product Instance ID: ...");
break;
case 0x23:
proto_tree_add_text(sv_tree, tvb, svoff+2, sv_length-2,
"Ring Station Version Number: ...");
break;
case 0x26:
proto_tree_add_text(sv_tree, tvb, svoff+2, sv_length-2,
"Wrap Data: ... (%u bytes)", sv_length - 2);
break;
case 0x27:
proto_tree_add_text(sv_tree, tvb, svoff+2, sv_length-2,
"Frame Forward: ... (%d bytes)", sv_length - 2);
break;
case 0x28:
if (sv_length != 8) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 8");
break;
}
proto_tree_add_item(sv_tree, hf_trmac_station_identifier, tvb, svoff+2, sv_length-2, ENC_NA);
proto_item_append_text(sv_item,
": %s",
tvb_ether_to_str(tvb, svoff+2));
break;
case 0x29:
proto_tree_add_text(sv_tree, tvb, svoff+2, sv_length-2,
"Ring Station Status: ...");
break;
case 0x2A:
if (sv_length != 4) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 4");
break;
}
proto_tree_add_item(sv_tree, hf_trmac_transmit_status_code, tvb, svoff+2, sv_length-2, ENC_BIG_ENDIAN);
proto_item_append_text(sv_item,
": %04X", tvb_get_ntohs(tvb, svoff+2) );
break;
case 0x2B:
if (sv_length != 6 && sv_length != 8) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 6 and != 8");
break;
}
if (sv_length == 6) {
proto_tree_add_item(sv_tree, hf_trmac_group_address32, tvb, svoff+2, sv_length-2, ENC_BIG_ENDIAN);
proto_item_append_text(sv_item,
": %08X", tvb_get_ntohl(tvb, svoff+2) );
} else {
proto_tree_add_item(sv_tree, hf_trmac_group_address_ether, tvb, svoff+2, sv_length-2, ENC_NA);
proto_item_append_text(sv_item,
": %s",
tvb_ether_to_str(tvb, svoff+2));
}
break;
case 0x2C:
if (sv_length != 6) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 6");
break;
}
proto_tree_add_item(sv_tree, hf_trmac_functional_addresses, tvb, svoff+2, sv_length-2, ENC_BIG_ENDIAN);
proto_item_append_text(sv_item,
": %08X", tvb_get_ntohl(tvb, svoff+2) );
break;
case 0x2D:
if (sv_length != 8) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 8");
break;
}
tvb_memcpy(tvb, errors, svoff+2, 6);
ti = proto_tree_add_uint(sv_tree, hf_trmac_errors_iso, tvb, svoff+2, sv_length-2,
errors[0] + errors[1] + errors[2] + errors[3] + errors[4]);
sv_subtree = proto_item_add_subtree(ti, ett_tr_ierr_cnt);
proto_tree_add_uint(sv_subtree, hf_trmac_errors_line, tvb, svoff+2, 1, errors[0]);
proto_tree_add_uint(sv_subtree, hf_trmac_errors_internal, tvb, svoff+3, 1, errors[1]);
proto_tree_add_uint(sv_subtree, hf_trmac_errors_burst, tvb, svoff+4, 1, errors[2]);
proto_tree_add_uint(sv_subtree, hf_trmac_errors_ac, tvb, svoff+5, 1, errors[3]);
proto_tree_add_uint(sv_subtree, hf_trmac_errors_abort, tvb, svoff+6, 1, errors[4]);
break;
case 0x2E:
if (sv_length != 8) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 8");
break;
}
tvb_memcpy(tvb, errors, svoff+2, 6);
ti = proto_tree_add_uint(sv_tree, hf_trmac_errors_noniso, tvb, svoff+2, sv_length-2,
errors[0] + errors[1] + errors[2] + errors[3] + errors[4]);
sv_subtree = proto_item_add_subtree(ti, ett_tr_nerr_cnt);
proto_tree_add_uint(sv_subtree, hf_trmac_errors_lost, tvb, svoff+2, 1, errors[0]);
proto_tree_add_uint(sv_subtree, hf_trmac_errors_congestion, tvb, svoff+3, 1, errors[1]);
proto_tree_add_uint(sv_subtree, hf_trmac_errors_fc, tvb, svoff+4, 1, errors[2]);
proto_tree_add_uint(sv_subtree, hf_trmac_errors_freq, tvb, svoff+5, 1, errors[3]);
proto_tree_add_uint(sv_subtree, hf_trmac_errors_token, tvb, svoff+6, 1, errors[4]);
break;
case 0x30:
if (sv_length != 4) {
expert_add_info_format(pinfo, len_item, &ei_trmac_sv_len,
"Subvector length is != 4");
break;
}
proto_tree_add_item(sv_tree, hf_trmac_error_code, tvb, svoff+2, sv_length-2, ENC_BIG_ENDIAN);
proto_item_append_text(sv_item,
": %04X", tvb_get_ntohs(tvb, svoff+2) );
break;
default:
proto_tree_add_text(sv_tree, tvb, svoff+2, sv_length-2,
"Unknown Subvector");
break;
}
return sv_length;
}
static void
dissect_trmac(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *mac_tree = NULL;
proto_item *ti;
int mv_length, sv_offset, sv_additional;
guint8 mv_val;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TR MAC");
col_clear(pinfo->cinfo, COL_INFO);
mv_val = tvb_get_guint8(tvb, 3);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str_ext(mv_val, &major_vector_vs_ext, "Unknown Major Vector: %u"));
if (tree) {
mv_length = tvb_get_ntohs(tvb, 0);
ti = proto_tree_add_item(tree, proto_trmac, tvb, 0, mv_length, ENC_NA);
mac_tree = proto_item_add_subtree(ti, ett_tr_mac);
proto_tree_add_uint(mac_tree, hf_trmac_mv, tvb, 3, 1, mv_val);
proto_tree_add_uint_format_value(mac_tree, hf_trmac_length, tvb, 0, 2, mv_length,
"%d bytes", mv_length);
proto_tree_add_uint(mac_tree, hf_trmac_srcclass, tvb, 2, 1, tvb_get_guint8(tvb, 2) & 0x0f);
proto_tree_add_uint(mac_tree, hf_trmac_dstclass, tvb, 2, 1, tvb_get_guint8(tvb, 2) >> 4 );
sv_offset = 4;
while (sv_offset < mv_length) {
sv_additional = sv_text(tvb, sv_offset, pinfo, mac_tree);
if (sv_additional > 0)
sv_offset += sv_additional;
else
break;
}
}
}
void
proto_register_trmac(void)
{
static hf_register_info hf[] = {
{ &hf_trmac_mv,
{ "Major Vector", "trmac.mvec", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &major_vector_vs_ext, 0x0,
NULL, HFILL }},
{ &hf_trmac_length,
{ "Total Length", "trmac.length", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_srcclass,
{ "Source Class", "trmac.srcclass", FT_UINT8, BASE_HEX, VALS(classes_vs), 0x0,
NULL, HFILL }},
{ &hf_trmac_dstclass,
{ "Destination Class", "trmac.dstclass", FT_UINT8, BASE_HEX, VALS(classes_vs), 0x0,
NULL, HFILL }},
{ &hf_trmac_sv_len,
{ "Subvector Length", "trmac.svec.len", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_sv_id,
{ "Subvector Identifier", "trmac.svec.id", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &subvector_vs_ext, 0x0,
NULL, HFILL }},
{ &hf_trmac_errors_iso,
{ "Isolating Errors", "trmac.errors.iso", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_errors_line,
{ "Line Errors", "trmac.errors.line", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_errors_internal,
{ "Internal Errors", "trmac.errors.internal", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_errors_burst,
{ "Burst Errors", "trmac.errors.burst", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_errors_ac,
{ "A/C Errors", "trmac.errors.ac", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_errors_abort,
{ "Abort Delimiter Transmitted Errors", "trmac.errors.abort", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_errors_noniso,
{ "Non-Isolating Errors", "trmac.errors.noniso", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_errors_lost,
{ "Lost Frame Errors", "trmac.errors.lost", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_errors_congestion,
{ "Receiver Congestion Errors", "trmac.errors.congestion", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_errors_fc,
{ "Frame-Copied Errors", "trmac.errors.fc", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_errors_freq,
{ "Frequency Errors", "trmac.errors.freq", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_errors_token,
{ "Token Errors", "trmac.errors.token", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_naun,
{ "Upstream Neighbor's Address", "trmac.naun", FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_beacon_type,
{ "Beacon Type", "trmac.beacon_type", FT_UINT16, BASE_DEC, VALS(beacon_vs), 0x0,
NULL, HFILL }},
{ &hf_trmac_local_ring_number,
{ "Local Ring Number", "trmac.local_ring_number", FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_assign_physical_drop_number,
{ "Assign Physical Drop Number", "trmac.assign_physical_drop_number", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_error_report_timer_value,
{ "Error Report Timer Value", "trmac.error_report_timer_value", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_authorized_function_classes,
{ "Authorized Function Classes", "trmac.authorized_function_classes", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_authorized_access_priority,
{ "Authorized Access Priority", "trmac.authorized_access_priority", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_correlator,
{ "Correlator", "trmac.correlator", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_sa_of_last_amp_or_smp_frame,
{ "SA of Last AMP or SMP Frame", "trmac.sa_of_last_amp_or_smp_frame", FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_physical_drop_number,
{ "Physical Drop Number", "trmac.physical_drop_number", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_individual_address_count,
{ "Individual Address Count", "trmac.individual_address_count", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_station_identifier,
{ "Station Identifier", "trmac.station_identifier", FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_transmit_status_code,
{ "Transmit Status Code", "trmac.transmit_status_code", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_group_address32,
{ "Group Address", "trmac.group_address", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_group_address_ether,
{ "Group Address", "trmac.group_address", FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_functional_addresses,
{ "Functional Addresses", "trmac.functional_addresses", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_error_code,
{ "Error Code", "trmac.error_code", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_tr_mac,
&ett_tr_sv,
&ett_tr_ierr_cnt,
&ett_tr_nerr_cnt,
};
static ei_register_info ei[] = {
{ &ei_trmac_sv_len, { "trmac.svec.len.invalid", PI_MALFORMED, PI_ERROR, "Invalid length", EXPFILL }},
};
expert_module_t* expert_trmac;
proto_trmac = proto_register_protocol("Token-Ring Media Access Control", "TR MAC", "trmac");
proto_register_field_array(proto_trmac, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_trmac = expert_register_protocol(proto_trmac);
expert_register_field_array(expert_trmac, ei, array_length(ei));
register_dissector("trmac", dissect_trmac, proto_trmac);
}
