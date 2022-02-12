static int
dissect_ixiatrailer(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *ti;
guint tvblen, trailer_length, field_length;
gboolean matched_without_fcs, matched_with_fcs;
proto_tree *ixiatrailer_tree = NULL;
guint offset = 0;
guint16 cksum, comp_cksum;
vec_t vec;
guint8 field_type;
tvblen = tvb_reported_length(tvb);
if (tvblen != tvb_captured_length(tvb)) {
return 0;
}
if (tvblen < 9) {
return 0;
}
if (tvblen == 23) {
tvblen = 19;
}
matched_without_fcs = (tvb_get_ntohs(tvb, tvblen-4) == IXIA_PATTERN);
if (!matched_without_fcs && tvblen >= 13)
matched_with_fcs = (tvb_get_ntohs(tvb, tvblen-(4+4)) == IXIA_PATTERN);
else
matched_with_fcs = FALSE;
if (!matched_without_fcs) {
if (!matched_with_fcs) {
return 0;
}
tvblen -= 4;
}
trailer_length = tvb_get_guint8(tvb, tvblen-5);
if ((tvblen-5) != trailer_length) {
return 0;
}
cksum = tvb_get_ntohs(tvb, tvblen-2);
SET_CKSUM_VEC_TVB(vec, tvb, offset, trailer_length + 3);
comp_cksum = in_cksum(&vec, 1);
if (pntoh16(&comp_cksum) != cksum) {
return 0;
}
ti = proto_tree_add_item(tree, proto_ixiatrailer, tvb, offset, trailer_length + 5, ENC_NA);
if (ixiatrailer_summary_in_tree) {
proto_item_append_text(ti, ", Length: %u, Checksum: 0x%x", trailer_length, cksum);
}
ixiatrailer_tree = proto_item_add_subtree(ti, ett_ixiatrailer);
while (offset < trailer_length - 2)
{
field_type = tvb_get_guint8(tvb, offset++);
field_length = tvb_get_guint8(tvb, offset++);
switch (field_type) {
case IXIATRAILER_FTYPE_ORIGINAL_PACKET_SIZE:
if (field_length != 2){
expert_add_info_format(pinfo, ti, &ei_ixiatrailer_field_length_invalid, "Field length %u invalid", field_length);
break;
}
ti = proto_tree_add_item(ixiatrailer_tree, hf_ixiatrailer_packetlen, tvb, offset, field_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " bytes");
break;
case IXIATRAILER_FTYPE_TIMESTAMP_LOCAL:
case IXIATRAILER_FTYPE_TIMESTAMP_NTP:
case IXIATRAILER_FTYPE_TIMESTAMP_GPS:
case IXIATRAILER_FTYPE_TIMESTAMP_1588:
case IXIATRAILER_FTYPE_TIMESTAMP_HOLDOVER:
if (field_length != 8) {
expert_add_info_format(pinfo, ti, &ei_ixiatrailer_field_length_invalid, "Field length %u invalid", field_length);
break;
}
ti = proto_tree_add_item(ixiatrailer_tree, hf_ixiatrailer_timestamp, tvb, offset, field_length, ENC_TIME_TIMESPEC|ENC_BIG_ENDIAN);
proto_item_append_text(ti, "; Source: %s", val_to_str_const(field_type, ixiatrailer_ftype_timestamp, "Unknown"));
break;
default:
ti = proto_tree_add_item(ixiatrailer_tree, hf_ixiatrailer_generic, tvb, offset, field_length, ENC_NA);
proto_item_append_text(ti, " [Id: %u, Length: %u bytes]", field_type, field_length);
break;
};
offset += field_length;
}
return tvblen;
}
void
proto_register_ixiatrailer(void)
{
static hf_register_info hf[] = {
{ &hf_ixiatrailer_packetlen, {
"Original packet length", "ixiatrailer.packetlen", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ixiatrailer_timestamp, {
"Time Stamp", "ixiatrailer.timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0x0, NULL, HFILL }},
{ &hf_ixiatrailer_generic, {
"Generic Field", "ixiatrailer.generic", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
};
static gint *ixiatrailer_ett[] = {
&ett_ixiatrailer
};
static ei_register_info ei[] = {
{ &ei_ixiatrailer_field_length_invalid, { "ixiatrailer.field_length_invalid", PI_MALFORMED, PI_ERROR, "Field length invalid", EXPFILL }},
};
module_t *ixiatrailer_module;
expert_module_t* expert_ixiatrailer;
proto_ixiatrailer = proto_register_protocol("Ixia Trailer", "IXIATRAILER", "ixiatrailer");
proto_register_field_array(proto_ixiatrailer, hf, array_length(hf));
proto_register_subtree_array(ixiatrailer_ett, array_length(ixiatrailer_ett));
expert_ixiatrailer = expert_register_protocol(proto_ixiatrailer);
expert_register_field_array(expert_ixiatrailer, ei, array_length(ei));
ixiatrailer_module = prefs_register_protocol(proto_ixiatrailer, NULL);
prefs_register_bool_preference(ixiatrailer_module, "summary_in_tree",
"Show trailer summary in protocol tree",
"Whether the trailer summary line should be shown in the protocol tree",
&ixiatrailer_summary_in_tree);
}
void
proto_reg_handoff_ixiatrailer(void)
{
heur_dissector_add("eth.trailer", dissect_ixiatrailer, "Ixia Trailer", "ixiatrailer_eth", proto_ixiatrailer, HEURISTIC_ENABLE);
}
