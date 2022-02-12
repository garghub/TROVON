ETH_HF
ETH_ETT
static int
budb_dissect_NameString_t(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep, int hf_index, guint32 param _U_)
{
offset=dissect_ndr_vstring(tvb, offset, pinfo, tree, di, drep, 1, hf_index, FALSE, NULL);
return offset;
}
ETH_CODE
void
proto_register_budb(void)
{
static hf_register_info hf[] = {
ETH_HFARR
};
static gint *ett[] = {
ETH_ETTARR
};
proto_budb = proto_register_protocol(
"DCE/DFS BUDB",
"BUDB", "budb");
proto_register_field_array(proto_budb, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_budb(void)
{
ETH_HANDOFF
}
