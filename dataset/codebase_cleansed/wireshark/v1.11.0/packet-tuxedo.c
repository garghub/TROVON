static void
dissect_tuxedo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *tuxedoroot_tree = NULL;
proto_item *ti;
guint32 magic;
guint32 opcode;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TUXEDO");
if (tvb_length(tvb) >= 8)
{
magic = tvb_get_ntohl(tvb, 0);
if (magic == TUXEDO_MAGIC || magic == TUXEDO_SMAGIC)
{
opcode = tvb_get_ntohl(tvb, 4);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(opcode, tuxedo_opcode_vals, "Unknown (0x%02x)"));
if (tree)
{
ti = proto_tree_add_item(tree, proto_tuxedo, tvb, 0, -1, ENC_NA);
tuxedoroot_tree = proto_item_add_subtree(ti, ett_tuxedo);
proto_tree_add_item(tuxedoroot_tree, hf_tuxedo_magic, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tuxedoroot_tree, hf_tuxedo_opcode, tvb, 4, 4, ENC_BIG_ENDIAN);
}
}
else
{
col_set_str(pinfo->cinfo, COL_INFO, "Continuation");
if (tree)
{
proto_tree_add_item(tree, proto_tuxedo, tvb, 0, -1, ENC_NA);
}
}
}
}
static gboolean
dissect_tuxedo_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (tvb_length(tvb) >= 8)
{
guint32 magic;
magic = tvb_get_ntohl(tvb, 0);
if (magic == TUXEDO_MAGIC || magic == TUXEDO_SMAGIC)
{
conversation_t *conversation = NULL;
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, tuxedo_handle);
dissect_tuxedo(tvb, pinfo, tree);
return TRUE;
}
}
return FALSE;
}
void
proto_register_tuxedo(void)
{
static hf_register_info hf[] = {
{ &hf_tuxedo_magic,
{ "Magic", "tuxedo.magic", FT_UINT32, BASE_HEX, NULL, 0x0, "TUXEDO magic", HFILL }},
{ &hf_tuxedo_opcode,
{ "Opcode", "tuxedo.opcode", FT_UINT32, BASE_HEX, VALS(tuxedo_opcode_vals), 0x0, "TUXEDO opcode", HFILL }}
};
static gint *ett[] = {
&ett_tuxedo,
};
proto_tuxedo = proto_register_protocol("BEA Tuxedo", "TUXEDO", "tuxedo");
proto_register_field_array(proto_tuxedo, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_tuxedo(void)
{
tuxedo_handle = create_dissector_handle(dissect_tuxedo, proto_tuxedo);
dissector_add_handle("tcp.port", tuxedo_handle);
heur_dissector_add("tcp", dissect_tuxedo_heur, proto_tuxedo);
}
