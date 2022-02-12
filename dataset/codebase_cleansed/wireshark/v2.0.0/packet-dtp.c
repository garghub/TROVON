static void
dissect_dtp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *dtp_tree;
proto_tree *tlv_tree;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DTP");
col_set_str(pinfo->cinfo, COL_INFO, "Dynamic Trunk Protocol");
ti = proto_tree_add_item(tree, proto_dtp, tvb, offset, -1, ENC_NA);
dtp_tree = proto_item_add_subtree(ti, ett_dtp);
proto_tree_add_item(dtp_tree, hf_dtp_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
int type, length, valuelength;
proto_item * tlv_length_item;
if (tvb_reported_length_remaining(tvb, offset) < 4) {
expert_add_info(pinfo, dtp_tree, &ei_dtp_truncated);
break;
}
type = tvb_get_ntohs(tvb, offset);
length = tvb_get_ntohs(tvb, offset + 2);
tlv_tree = proto_tree_add_subtree(dtp_tree, tvb, offset, length, ett_dtp_tlv, NULL,
val_to_str(type, dtp_tlv_type_vals, "Unknown TLV type: 0x%02x"));
proto_tree_add_uint(tlv_tree, hf_dtp_tlvtype, tvb, offset, 2, type);
offset+=2;
tlv_length_item = proto_tree_add_uint(tlv_tree, hf_dtp_tlvlength, tvb, offset, 2, length);
offset+=2;
if (length <= 4) {
expert_add_info(pinfo, tlv_length_item, &ei_dtp_tlv_length_too_short);
break;
}
valuelength = (length-4);
dissect_dtp_tlv(pinfo, tvb, offset, valuelength, tlv_tree, ti, tlv_length_item, (guint8) type);
offset += valuelength;
}
}
static void
dissect_dtp_tlv(packet_info *pinfo, tvbuff_t *tvb, int offset, int length,
proto_tree *tree, proto_item *ti, proto_item *tlv_length_item, guint8 type)
{
switch (type) {
case DTP_TLV_DOMAIN:
if (length <= 33) {
proto_item_append_text(ti, ": %s", tvb_format_text(tvb, offset, length - 1));
proto_tree_add_item(tree, hf_dtp_domain, tvb, offset, length, ENC_ASCII|ENC_NA);
}
else
expert_add_info(pinfo, tlv_length_item, &ei_dtp_tlv_length_invalid);
break;
case DTP_TLV_TRSTATUS:
if (length == 1) {
proto_tree * field_tree = NULL;
guint8 trunk_status = tvb_get_guint8(tvb, offset);
proto_item_append_text(ti,
" (Operating/Administrative): %s/%s (0x%02x)",
val_to_str_const(DTP_TOSVALUE(trunk_status), dtp_tos_vals, "Unknown operating status"),
val_to_str_const(DTP_TASVALUE(trunk_status), dtp_tas_vals, "Unknown administrative status"),
trunk_status);
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length, ett_dtp_status, NULL, "Value: %s/%s (0x%02x)",
val_to_str_const(DTP_TOSVALUE(trunk_status), dtp_tos_vals, "Unknown operating status"),
val_to_str_const(DTP_TASVALUE(trunk_status), dtp_tas_vals, "Unknown administrative status"),
trunk_status);
proto_tree_add_item(field_tree, hf_dtp_tos, tvb, offset, length, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_dtp_tas, tvb, offset, length, ENC_BIG_ENDIAN);
}
else
expert_add_info(pinfo, tlv_length_item, &ei_dtp_tlv_length_invalid);
break;
case DTP_TLV_TRTYPE:
if (length == 1) {
proto_tree * field_tree;
guint8 trunk_type = tvb_get_guint8(tvb, offset);
proto_item_append_text(ti,
" (Operating/Administrative): %s/%s (0x%02x)",
val_to_str_const(DTP_TOTVALUE(trunk_type), dtp_tot_vals, "Unknown operating type"),
val_to_str_const(DTP_TATVALUE(trunk_type), dtp_tat_vals, "Unknown administrative type"),
trunk_type);
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length, ett_dtp_type, NULL, "Value: %s/%s (0x%02x)",
val_to_str_const(DTP_TOTVALUE(trunk_type), dtp_tot_vals, "Unknown operating type"),
val_to_str_const(DTP_TATVALUE(trunk_type), dtp_tat_vals, "Unknown administrative type"),
trunk_type);
proto_tree_add_item(field_tree, hf_dtp_tot, tvb, offset, length, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_dtp_tat, tvb, offset, length, ENC_BIG_ENDIAN);
}
else
expert_add_info(pinfo, tlv_length_item, &ei_dtp_tlv_length_invalid);
break;
case DTP_TLV_SENDERID:
if (length == 6) {
proto_item_append_text(ti, ": %s",
tvb_ether_to_str(tvb, offset));
proto_tree_add_item(tree, hf_dtp_senderid, tvb, offset, length, ENC_NA);
}
else
expert_add_info(pinfo, tlv_length_item, &ei_dtp_tlv_length_invalid);
break;
default:
proto_tree_add_item(tree, hf_dtp_data, tvb, offset, length, ENC_NA);
break;
}
}
void
proto_register_dtp(void)
{
static hf_register_info hf[] = {
{ &hf_dtp_version,
{ "Version", "dtp.version", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_dtp_domain,
{ "Domain", "dtp.domain", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_dtp_tlvtype,
{ "Type", "dtp.tlv_type", FT_UINT16, BASE_HEX,
VALS(dtp_tlv_type_vals), 0x0, NULL, HFILL }},
{ &hf_dtp_tlvlength,
{ "Length", "dtp.tlv_len", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_dtp_tos,
{ "Trunk Operating Status", "dtp.tos", FT_UINT8, BASE_HEX,
VALS(dtp_tos_vals), DTP_TOS_MASK, NULL, HFILL }},
{ &hf_dtp_tas,
{ "Trunk Administrative Status", "dtp.tas", FT_UINT8, BASE_HEX,
VALS(dtp_tas_vals), DTP_TAS_MASK, NULL, HFILL }},
{ &hf_dtp_tot,
{ "Trunk Operating Type", "dtp.tot", FT_UINT8, BASE_HEX,
VALS(dtp_tot_vals), DTP_TOT_MASK, NULL, HFILL }},
{ &hf_dtp_tat,
{ "Trunk Administrative Type", "dtp.tat", FT_UINT8, BASE_HEX,
VALS(dtp_tat_vals), DTP_TAT_MASK, NULL, HFILL }},
{ &hf_dtp_senderid,
{ "Sender ID", "dtp.senderid", FT_ETHER, BASE_NONE,
NULL, 0x0, "MAC Address of neighbor", HFILL }},
{ &hf_dtp_data,
{ "Data", "dtp.data", FT_ETHER, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dtp,
&ett_dtp_tlv,
&ett_dtp_status,
&ett_dtp_type,
};
static ei_register_info ei[] = {
{ &ei_dtp_tlv_length_too_short,
{ "dtp.tlv_len.too_short", PI_MALFORMED, PI_ERROR,
"Indicated length is less than the minimum length", EXPFILL }},
{ &ei_dtp_tlv_length_invalid,
{ "dtp.tlv_len.invalid", PI_MALFORMED, PI_ERROR,
"Indicated length does not correspond to this record type", EXPFILL }},
{ &ei_dtp_truncated,
{ "dtp.truncated", PI_MALFORMED, PI_ERROR,
"DTP message is truncated prematurely", EXPFILL }}
};
expert_module_t *expert_dtp;
proto_dtp = proto_register_protocol("Dynamic Trunk Protocol", "DTP", "dtp");
proto_register_field_array(proto_dtp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dtp = expert_register_protocol(proto_dtp);
expert_register_field_array(expert_dtp, ei, array_length(ei));
}
void
proto_reg_handoff_dtp(void)
{
dissector_handle_t dtp_handle;
dtp_handle = create_dissector_handle(dissect_dtp, proto_dtp);
dissector_add_uint("llc.cisco_pid", 0x2004, dtp_handle);
}
