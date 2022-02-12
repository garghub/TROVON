void proto_register_ns_cert_exts(void) {
static hf_register_info hf[] = {
#include "packet-ns_cert_exts-hfarr.c"
};
static gint *ett[] = {
#include "packet-ns_cert_exts-ettarr.c"
};
proto_ns_cert_exts = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_ns_cert_exts, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_ns_cert_exts(void) {
#include "packet-ns_cert_exts-dis-tab.c"
}
