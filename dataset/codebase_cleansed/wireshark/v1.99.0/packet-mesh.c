static int
dissect_mesh(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *mesh_tree;
guint8 mesh_ttl;
guint16 mesh_e2eseq;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Mesh");
if (tree) {
ti = proto_tree_add_item(tree, proto_mesh, tvb, 0, 5, ENC_NA);
mesh_tree = proto_item_add_subtree(ti, ett_mesh);
mesh_ttl = tvb_get_guint8(tvb, 2);
proto_tree_add_uint(mesh_tree, hf_mesh_ttl, tvb, 2, 1, mesh_ttl);
mesh_e2eseq = tvb_get_ntohs(tvb, 3);
proto_tree_add_uint(mesh_tree, hf_mesh_e2eseq, tvb, 3, 2, mesh_e2eseq);
}
return 5;
}
void
proto_register_mesh(void)
{
static hf_register_info hf[] = {
{ &hf_mesh_ttl,
{ "Mesh TTL", "mesh.ttl", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_mesh_e2eseq,
{ "Mesh End-to-end Seq", "mesh.e2eseq", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_mesh
};
proto_mesh = proto_register_protocol("Mesh Header", "Mesh", "mesh");
proto_register_field_array(proto_mesh, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("mesh", dissect_mesh, proto_mesh);
}
