static int
dissect_ixiatrailer(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *ti;
guint tvblen, trailer_length, time_length;
proto_tree *ixiatrailer_tree = NULL;
guint offset = 0;
guint16 cksum, comp_cksum;
vec_t vec;
guint8 source;
tvblen = tvb_length(tvb);
if (tvblen < 5) {
return 0;
}
if (tvblen == 19) {
tvblen = 15;
}
if (tvb_get_ntohs(tvb, tvblen-4) != IXIA_PATTERN) {
return 0;
}
trailer_length = tvb_get_guint8(tvb, tvblen-5);
if ((tvblen-5) != trailer_length) {
return 0;
}
cksum = tvb_get_ntohs(tvb, tvblen-2);
vec.len = trailer_length + 3;
vec.ptr = tvb_get_ptr(tvb, offset, vec.len);
comp_cksum = in_cksum(&vec, 1);
if (pntoh16(&comp_cksum) != cksum) {
return 0;
}
ti = proto_tree_add_item(tree, proto_ixiatrailer, tvb, offset, trailer_length + 5, ENC_NA);
if (ixiatrailer_summary_in_tree) {
proto_item_append_text(ti, ", Length: %u, Checksum: 0x%x", trailer_length, cksum);
}
ixiatrailer_tree = proto_item_add_subtree(ti, ett_ixiatrailer);
source = tvb_get_guint8(tvb, offset++);
time_length = tvb_get_guint8(tvb, offset++);
switch (source) {
case IXIATRAILER_FTYPE_TIMESTAMP_LOCAL:
case IXIATRAILER_FTYPE_TIMESTAMP_NTP:
case IXIATRAILER_FTYPE_TIMESTAMP_GPS:
case IXIATRAILER_FTYPE_TIMESTAMP_1588:
case IXIATRAILER_FTYPE_TIMESTAMP_HOLDOVER:
if (time_length != 8) {
expert_add_info_format(pinfo, ti, &ei_ixiatrailer_field_length_invalid, "Field length %u invalid", time_length);
break;
}
ti = proto_tree_add_item(ixiatrailer_tree, hf_ixiatrailer_timestamp, tvb, offset, time_length, ENC_TIME_TIMESPEC|ENC_BIG_ENDIAN);
proto_item_append_text(ti, "; Source: %s", val_to_str_const(source, ixiatrailer_ftype_timestamp, "Unknown"));
break;
default:
ti = proto_tree_add_item(ixiatrailer_tree, hf_ixiatrailer_generic, tvb, offset, time_length, ENC_NA);
proto_item_append_text(ti, " [Id: %u, Length: %u]", source, time_length);
break;
}
return tvblen;
}
void
proto_register_ixiatrailer(void)
{
static hf_register_info hf[] = {
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
heur_dissector_add("eth.trailer", dissect_ixiatrailer, proto_ixiatrailer);
}
