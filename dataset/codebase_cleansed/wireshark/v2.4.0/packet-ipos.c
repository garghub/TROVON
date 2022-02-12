static int
dissect_ipos(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti = NULL;
proto_tree *ipos_tree = NULL;
tvbuff_t *next_tvb;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPOS");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_ipos, tvb, 0, -1, ENC_NA);
ipos_tree = proto_item_add_subtree(ti, ett_ipos);
proto_tree_add_item(ipos_tree, hf_ipos_protocol, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ipos_tree, hf_ipos_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ipos_tree, hf_ipos_ppe, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ipos_tree, hf_ipos_slot, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (redback_handle) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(redback_handle, next_tvb, pinfo, tree);
}
return tvb_reported_length(tvb);
}
void
proto_register_ipos(void)
{
static hf_register_info hf[] = {
{ &hf_ipos_protocol,
{ "Protocol", "ipos.proto", FT_UINT8, BASE_DEC, VALS(prototypenames), 0xF0,
NULL, HFILL }},
{ &hf_ipos_priority,
{ "Priority", "ipos.priority", FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }},
{ &hf_ipos_ppe,
{ "Packet Processing Engine", "ipos.ppe", FT_UINT8, BASE_HEX, VALS(ppetypenames), 0x0,
NULL, HFILL }},
{ &hf_ipos_slot,
{ "Destination (source) Slot", "ipos.slot", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_ipos
};
#if 0
static ei_register_info ei[] = {
{ &ei_ipos_protocol,
{ "ipos.protocol.unknown", PI_PROTOCOL, PI_WARN,
"Unknown Protocol Data", EXPFILL }}
};
expert_module_t* expert_ipos;
#endif
proto_ipos = proto_register_protocol("IPOS Kernel Packet Protocol", "IPOS", "ipos");
proto_register_field_array(proto_ipos, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
#if 0
expert_ipos = expert_register_protocol(proto_ipos);
expert_register_field_array(expert_ipos, ei, array_length(ei));
#endif
ipos_handle = register_dissector("ipos", dissect_ipos, proto_ipos);
}
void
proto_reg_handoff_ipos(void)
{
redback_handle = find_dissector_add_dependency("redback", proto_ipos);
dissector_add_uint("sll.ltype", LINUX_SLL_P_IPOS_NETIPC, ipos_handle);
dissector_add_uint("sll.ltype", LINUX_SLL_P_IPOS_RBN, ipos_handle);
dissector_add_uint("sll.ltype", LINUX_SLL_P_IPOS_NETLINK, ipos_handle);
dissector_add_uint("sll.ltype", LINUX_SLL_P_IPOS_XCRP, ipos_handle);
dissector_add_uint("sll.ltype", LINUX_SLL_P_IPOS_ISIS, ipos_handle);
dissector_add_uint("sll.ltype", LINUX_SLL_P_IPOS_PAKIO, ipos_handle);
}
