void proto_register_pkixqualified(void) {
static hf_register_info hf[] = {
#include "packet-pkixqualified-hfarr.c"
};
static gint *ett[] = {
#include "packet-pkixqualified-ettarr.c"
};
proto_pkixqualified = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkixqualified, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_pkixqualified(void) {
#include "packet-pkixqualified-dis-tab.c"
}
