void proto_register_lpp(void) {
static hf_register_info hf[] = {
#include "packet-lpp-hfarr.c"
};
static gint *ett[] = {
&ett_lpp,
#include "packet-lpp-ettarr.c"
};
proto_lpp = proto_register_protocol(PNAME, PSNAME, PFNAME);
new_register_dissector("lpp", dissect_LPP_Message_PDU, proto_lpp);
proto_register_field_array(proto_lpp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_lpp(void)
{
}
