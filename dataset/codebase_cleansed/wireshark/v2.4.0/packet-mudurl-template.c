void proto_register_mudurl(void) {
static hf_register_info hf[] = {
#include "packet-mudurl-hfarr.c"
};
proto_mudurl = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_mudurl, hf, array_length(hf));
}
void proto_reg_handoff_mudurl(void) {
#include "packet-mudurl-dis-tab.c"
}
