void proto_register_pkixproxy(void) {
static hf_register_info hf[] = {
#include "packet-pkixproxy-hfarr.c"
};
static gint *ett[] = {
#include "packet-pkixproxy-ettarr.c"
};
proto_pkixproxy = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkixproxy, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_pkixproxy(void) {
#include "packet-pkixproxy-dis-tab.c"
oid_add_from_string("id-ppl-anyLanguage","1.3.6.1.5.5.7.21.0");
oid_add_from_string("id-ppl-inheritAll","1.3.6.1.5.5.7.21.1");
oid_add_from_string("id-ppl-independent","1.3.6.1.5.5.7.21.2");
}
