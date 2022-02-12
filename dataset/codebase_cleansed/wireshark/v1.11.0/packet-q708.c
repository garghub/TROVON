void
analyze_q708_ispc(tvbuff_t *tvb, proto_tree *tree, int offset, int length, guint16 ispc)
{
guint16 sanc;
sanc = ispc >> 3;
proto_tree_add_uint_format_value(tree, hf_q708_sanc, tvb, offset, length, sanc,
"%s (%u-%03u)",
val_to_str_ext_const(sanc, &q708_sanc_areas_ext, "Unknown"),
sanc >> 8, sanc & 0xff);
proto_tree_add_string(tree, hf_q708_ispc_name, tvb, offset, length,
val_to_str_ext_const(ispc, &q708_ispc_point_name_ext, "Unknown"));
proto_tree_add_string(tree, hf_q708_ispc_operator_name, tvb, offset, length,
val_to_str_ext_const(ispc, &q708_ispc_operator_name_ext, "Unknown"));
}
void
proto_register_q708(void)
{
static hf_register_info hf[] = {
{ &hf_q708_sanc,
{ "Signalling Area Network Code (SANC)","q708.sanc",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &q708_sanc_areas_ext, 0x0,
NULL, HFILL }
},
{ &hf_q708_ispc_name,
{ "Unique Signalling Point Name","q708.ispc_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q708_ispc_operator_name,
{ "Signalling Point Operator Name", "q708.ispc_operator_name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
};
proto_q708 = proto_register_protocol(
"ITU-T Q.708 ISPC Analysis",
"Q.708",
"q708");
proto_register_field_array(proto_q708, hf, array_length(hf));
}
