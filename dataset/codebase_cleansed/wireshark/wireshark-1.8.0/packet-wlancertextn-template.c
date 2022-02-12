void proto_register_wlancertextn(void) {
static hf_register_info hf[] = {
#include "packet-wlancertextn-hfarr.c"
};
static gint *ett[] = {
#include "packet-wlancertextn-ettarr.c"
};
proto_wlancertextn = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_wlancertextn, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_wlancertextn(void) {
#include "packet-wlancertextn-dis-tab.c"
oid_add_from_string("id-kp-eapOverPPP","1.3.6.1.5.5.7.3.13");
oid_add_from_string("id-kp-eapOverLAN","1.3.6.1.5.5.7.3.14");
}
