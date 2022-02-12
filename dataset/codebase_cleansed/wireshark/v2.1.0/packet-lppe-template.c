void proto_register_lppe(void) {
static hf_register_info hf[] = {
#include "packet-lppe-hfarr.c"
};
static gint *ett[] = {
&ett_lppe,
#include "packet-lppe-ettarr.c"
};
proto_lppe = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("lppe", dissect_OMA_LPPe_MessageExtension_PDU, proto_lppe);
proto_register_field_array(proto_lppe, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_lppe(void)
{
}
