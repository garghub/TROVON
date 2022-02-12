void proto_register_pkixac(void) {
static hf_register_info hf[] = {
#include "packet-pkixac-hfarr.c"
};
static gint *ett[] = {
&ett_pkixac,
#include "packet-pkixac-ettarr.c"
};
proto_pkixac = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkixac, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
#include "packet-pkixac-syn-reg.c"
}
void proto_reg_handoff_pkixac(void) {
#include "packet-pkixac-dis-tab.c"
}
