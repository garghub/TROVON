void proto_register_HI2Operations(void) {
static hf_register_info hf[] = {
#include "packet-HI2Operations-hfarr.c"
};
static gint *ett[] = {
#include "packet-HI2Operations-ettarr.c"
};
proto_HI2Operations = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_HI2Operations, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("HI2Operations", dissect_IRIsContent_PDU, proto_HI2Operations);
}
void proto_reg_handoff_HI2Operations(void) {
}
