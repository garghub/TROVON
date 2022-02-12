void proto_register_crmf(void) {
static hf_register_info hf[] = {
{ &hf_crmf_type_oid,
{ "Type", "crmf.type.oid",
FT_STRING, BASE_NONE, NULL, 0,
"Type of AttributeTypeAndValue", HFILL }},
#include "packet-crmf-hfarr.c"
};
static gint *ett[] = {
#include "packet-crmf-ettarr.c"
};
proto_crmf = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_crmf, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_crmf(void) {
oid_add_from_string("id-pkip","1.3.6.1.5.5.7.5");
oid_add_from_string("id-regCtrl","1.3.6.1.5.5.7.5.1");
oid_add_from_string("id-regInfo","1.3.6.1.5.5.7.5.2");
#include "packet-crmf-dis-tab.c"
}
