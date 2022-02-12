void dissect_cdt (tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_tree *tree = NULL;
top_tree = parent_tree;
if (parent_tree) {
cdt_item = proto_tree_add_item (parent_tree, proto_cdt, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree (cdt_item, ett_cdt_CompressedData);
} else {
cdt_item = NULL;
}
col_set_str (pinfo->cinfo, COL_PROTOCOL, "CDT");
col_clear (pinfo->cinfo, COL_INFO);
dissect_CompressedData_PDU (tvb, pinfo, tree, NULL);
}
void proto_register_cdt (void) {
static hf_register_info hf[] = {
#include "packet-cdt-hfarr.c"
};
static gint *ett[] = {
#include "packet-cdt-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_cdt_unable_compress_content, { "cdt.unable_compress_content", PI_UNDECODED, PI_ERROR, "Unable to get compressed content", EXPFILL }},
{ &ei_cdt_unable_uncompress_content, { "cdt.unable_uncompress_content", PI_UNDECODED, PI_ERROR, "Unable to get uncompressed content", EXPFILL }},
};
expert_module_t* expert_cdt;
proto_cdt = proto_register_protocol (PNAME, PSNAME, PFNAME);
proto_register_field_array (proto_cdt, hf, array_length(hf));
proto_register_subtree_array (ett, array_length(ett));
expert_cdt = expert_register_protocol(proto_cdt);
expert_register_field_array(expert_cdt, ei, array_length(ei));
}
void proto_reg_handoff_cdt (void) {
#include "packet-cdt-dis-tab.c"
}
