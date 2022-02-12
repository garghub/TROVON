static int
sv_text(tvbuff_t *tvb, int svoff, proto_tree *tree)
{
int sv_length = tvb_get_guint8(tvb, svoff+0);
guint16 beacon_type, ring;
const char *beacon[] = {
"Recovery mode set", "Signal loss error",
"Streaming signal not Claim Token MAC frame",
"Streaming signal, Claim Token MAC frame"
};
proto_tree *sv_tree;
proto_item *ti, *hidden_item;
guchar errors[6];
if (sv_length < 1) {
proto_tree_add_protocol_format(tree, proto_malformed, tvb, svoff+0, 1,
"Invalid subvector length: %d bytes", sv_length);
return sv_length;
}
hidden_item = proto_tree_add_uint(tree, hf_trmac_sv, tvb, svoff+1, 1, tvb_get_guint8(tvb, svoff+1));
PROTO_ITEM_SET_HIDDEN(hidden_item);
switch(tvb_get_guint8(tvb, svoff+1)) {
case 0x01:
beacon_type = tvb_get_ntohs(tvb, svoff+2);
if (beacon_type < array_length(beacon)) {
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Beacon Type: %s", beacon[beacon_type] );
} else {
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Beacon Type: Illegal value: %d", beacon_type );
}
break;
case 0x02:
proto_tree_add_ether(tree, hf_trmac_naun, tvb, svoff+1, sv_length-1,
tvb_get_ptr(tvb, svoff+2, 6));
break;
case 0x03:
ring = tvb_get_ntohs(tvb, svoff+2);
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Local Ring Number: 0x%04X (%d)", ring, ring);
break;
case 0x04:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Assign Physical Location: 0x%08X", tvb_get_ntohl(tvb, svoff+2) );
break;
case 0x05:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Soft Error Report Value: %d ms", 10 * tvb_get_ntohs(tvb, svoff+2) );
break;
case 0x06:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Enabled Function Classes: %04X", tvb_get_ntohs(tvb, svoff+2) );
break;
case 0x07:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Allowed Access Priority: %04X", tvb_get_ntohs(tvb, svoff+2) );
break;
case 0x09:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Correlator: %04X", tvb_get_ntohs(tvb, svoff+2) );
break;
case 0x0A:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Address of Last Neighbor Notification: %s",
tvb_ether_to_str(tvb, svoff+2));
break;
case 0x0B:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Physical Location: 0x%08X", tvb_get_ntohl(tvb, svoff+2) );
break;
case 0x20:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Response Code: 0x%04X 0x%04X", tvb_get_ntohl(tvb, svoff+2),
tvb_get_ntohl(tvb, svoff+4) );
break;
case 0x21:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Reserved: 0x%04X", tvb_get_ntohs(tvb, svoff+2) );
break;
case 0x22:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Product Instance ID: ...");
break;
case 0x23:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Ring Station Microcode Level: ...");
break;
case 0x26:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Wrap Data: ... (%d bytes)", sv_length - 2);
break;
case 0x27:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Frame Forward: ... (%d bytes)", sv_length - 2);
break;
case 0x29:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Ring Station Status Subvector: ...");
break;
case 0x2A:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Transmit Status Code: %04X", tvb_get_ntohs(tvb, svoff+2) );
break;
case 0x2B:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Group Address: %08X", tvb_get_ntohl(tvb, svoff+2) );
break;
case 0x2C:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Functional Address: %08X", tvb_get_ntohl(tvb, svoff+2) );
break;
case 0x2D:
tvb_memcpy(tvb, errors, svoff+2, 6);
ti = proto_tree_add_uint(tree, hf_trmac_errors_iso, tvb, svoff+1, sv_length-1,
errors[0] + errors[1] + errors[2] + errors[3] + errors[4]);
sv_tree = proto_item_add_subtree(ti, ett_tr_ierr_cnt);
proto_tree_add_uint(sv_tree, hf_trmac_errors_line, tvb, svoff+2, 1, errors[0]);
proto_tree_add_uint(sv_tree, hf_trmac_errors_internal, tvb, svoff+3, 1, errors[1]);
proto_tree_add_uint(sv_tree, hf_trmac_errors_burst, tvb, svoff+4, 1, errors[2]);
proto_tree_add_uint(sv_tree, hf_trmac_errors_ac, tvb, svoff+5, 1, errors[3]);
proto_tree_add_uint(sv_tree, hf_trmac_errors_abort, tvb, svoff+6, 1, errors[4]);
break;
case 0x2E:
tvb_memcpy(tvb, errors, svoff+2, 6);
ti = proto_tree_add_uint(tree, hf_trmac_errors_noniso, tvb, svoff+1, sv_length-1,
errors[0] + errors[1] + errors[2] + errors[3] + errors[4]);
sv_tree = proto_item_add_subtree(ti, ett_tr_nerr_cnt);
proto_tree_add_uint(sv_tree, hf_trmac_errors_lost, tvb, svoff+2, 1, errors[0]);
proto_tree_add_uint(sv_tree, hf_trmac_errors_congestion, tvb, svoff+3, 1, errors[1]);
proto_tree_add_uint(sv_tree, hf_trmac_errors_fc, tvb, svoff+4, 1, errors[2]);
proto_tree_add_uint(sv_tree, hf_trmac_errors_freq, tvb, svoff+5, 1, errors[3]);
proto_tree_add_uint(sv_tree, hf_trmac_errors_token, tvb, svoff+6, 1, errors[4]);
break;
case 0x30:
proto_tree_add_text(tree, tvb, svoff+1, sv_length-1,
"Error Code: %04X", tvb_get_ntohs(tvb, svoff+2) );
break;
default:
proto_tree_add_text(tree, tvb, svoff+1, 1,
"Unknown Sub-Vector: 0x%02X", tvb_get_guint8(tvb, svoff+1));
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
if (check_col(pinfo->cinfo, COL_INFO))
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(mv_val, major_vector_vs, "Unknown Major Vector: %u"));
if (tree) {
mv_length = tvb_get_ntohs(tvb, 0);
ti = proto_tree_add_item(tree, proto_trmac, tvb, 0, mv_length, ENC_NA);
mac_tree = proto_item_add_subtree(ti, ett_tr_mac);
proto_tree_add_uint(mac_tree, hf_trmac_mv, tvb, 3, 1, mv_val);
proto_tree_add_uint_format(mac_tree, hf_trmac_length, tvb, 0, 2, mv_length,
"Total Length: %d bytes", mv_length);
proto_tree_add_uint(mac_tree, hf_trmac_srcclass, tvb, 2, 1, tvb_get_guint8(tvb, 2) & 0x0f);
proto_tree_add_uint(mac_tree, hf_trmac_dstclass, tvb, 2, 1, tvb_get_guint8(tvb, 2) >> 4 );
sv_offset = 4;
while (sv_offset < mv_length) {
sv_additional = sv_text(tvb, sv_offset, mac_tree);
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
{ "Major Vector", "trmac.mvec", FT_UINT8, BASE_HEX, major_vector_vs, 0x0,
NULL, HFILL }},
{ &hf_trmac_length,
{ "Total Length", "trmac.length", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_trmac_srcclass,
{ "Source Class", "trmac.srcclass", FT_UINT8, BASE_HEX, classes_vs, 0x0,
NULL, HFILL }},
{ &hf_trmac_dstclass,
{ "Destination Class", "trmac.dstclass", FT_UINT8, BASE_HEX, classes_vs, 0x0,
NULL, HFILL }},
{ &hf_trmac_sv,
{ "Sub-Vector", "trmac.svec", FT_UINT8, BASE_HEX, NULL, 0x0,
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
{ "NAUN", "trmac.naun", FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_tr_mac,
&ett_tr_ierr_cnt,
&ett_tr_nerr_cnt,
};
proto_trmac = proto_register_protocol("Token-Ring Media Access Control",
"TR MAC", "trmac");
proto_register_field_array(proto_trmac, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("trmac", dissect_trmac, proto_trmac);
}
