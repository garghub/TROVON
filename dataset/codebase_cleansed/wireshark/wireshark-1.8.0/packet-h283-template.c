static int
dissect_h283_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *h283_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
info_is_set = FALSE;
ti = proto_tree_add_item(tree, proto_h283, tvb, 0, -1, ENC_NA);
h283_tree = proto_item_add_subtree(ti, ett_h283);
return dissect_LCTPDU_PDU(tvb, pinfo, h283_tree);
}
void proto_register_h283(void) {
static hf_register_info hf[] = {
#include "packet-h283-hfarr.c"
};
static gint *ett[] = {
&ett_h283,
#include "packet-h283-ettarr.c"
};
proto_h283 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h283, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector(PFNAME, dissect_h283_udp, proto_h283);
}
void proto_reg_handoff_h283(void)
{
dissector_handle_t h283_udp_handle;
h283_udp_handle = find_dissector(PFNAME);
dissector_add_handle("udp.port", h283_udp_handle);
rdc_pdu_handle = find_dissector("rdc");
rdc_device_list_handle = find_dissector("rdc.device_list");
data_handle = find_dissector("data");
}
