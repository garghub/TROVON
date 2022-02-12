void proto_register_logotypecertextn(void) {
static hf_register_info hf[] = {
#include "packet-logotypecertextn-hfarr.c"
};
static gint *ett[] = {
#include "packet-logotypecertextn-ettarr.c"
};
proto_logotypecertextn = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_logotypecertextn, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_logotypecertextn(void) {
#include "packet-logotypecertextn-dis-tab.c"
}
