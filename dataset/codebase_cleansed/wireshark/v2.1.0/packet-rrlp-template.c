void proto_register_rrlp(void) {
static hf_register_info hf[] = {
#include "packet-rrlp-hfarr.c"
};
static gint *ett[] = {
&ett_rrlp,
#include "packet-rrlp-ettarr.c"
};
proto_rrlp = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("rrlp", dissect_PDU_PDU, proto_rrlp);
proto_register_field_array(proto_rrlp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_rrlp(void)
{
}
