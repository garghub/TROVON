static int
dissect_h282(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti = NULL;
proto_tree *h282_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
ti = proto_tree_add_item(tree, proto_h282, tvb, 0, -1, ENC_NA);
h282_tree = proto_item_add_subtree(ti, ett_h282);
return dissect_RDCPDU_PDU(tvb, pinfo, h282_tree, NULL);
}
void proto_register_h282(void) {
static hf_register_info hf[] = {
#include "packet-h282-hfarr.c"
};
static gint *ett[] = {
&ett_h282,
#include "packet-h282-ettarr.c"
};
proto_h282 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h282, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(PFNAME, dissect_h282, proto_h282);
register_dissector(PFNAME".device_list", dissect_NonCollapsingCapabilities_PDU, proto_h282);
}
void proto_reg_handoff_h282(void)
{
}
