static int
dissect_pulse(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_item *item;
proto_tree *tree;
guint32 magic;
const char* magic_str;
guint little_endian;
if (tvb_captured_length(tvb) < 4)
return 0;
little_endian = ENC_LITTLE_ENDIAN;
magic = tvb_get_letohl(tvb, 0);
magic_str = try_val_to_str(magic, pulse_magic_type);
if (magic_str == NULL) {
magic = tvb_get_ntohl(tvb, 0);
magic_str = try_val_to_str(magic, pulse_magic_type);
if (magic_str == NULL) {
return 0;
}
little_endian = ENC_BIG_ENDIAN;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PULSE");
col_set_str(pinfo->cinfo, COL_INFO, magic_str);
if (parent_tree) {
item = proto_tree_add_item(parent_tree, proto_pulse, tvb, 0,
-1, little_endian);
tree = proto_item_add_subtree(item, ett_pulse);
proto_tree_add_item(tree, hf_pulse_magic, tvb, 0, 4, little_endian);
}
return 4;
}
void
proto_register_pulse(void)
{
static hf_register_info hf[] = {
{ &hf_pulse_magic,
{ "Magic", "pulse.magic",
FT_UINT32, BASE_HEX, VALS(pulse_magic_type), 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_pulse,
};
proto_pulse = proto_register_protocol("PULSE protocol for Linux Virtual Server redundancy", "PULSE", "pulse");
proto_register_field_array(proto_pulse, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_pulse(void)
{
dissector_handle_t pulse_handle;
pulse_handle = create_dissector_handle(dissect_pulse, proto_pulse);
dissector_add_uint_with_preference("udp.port", PORT_PULSE, pulse_handle);
}
