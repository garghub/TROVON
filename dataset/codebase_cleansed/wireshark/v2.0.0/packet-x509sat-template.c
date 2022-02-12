void proto_register_x509sat(void) {
static hf_register_info hf[] = {
#include "packet-x509sat-hfarr.c"
};
static gint *ett[] = {
#include "packet-x509sat-ettarr.c"
};
proto_x509sat = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_x509sat, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
#include "packet-x509sat-syn-reg.c"
}
void proto_reg_handoff_x509sat(void) {
#include "packet-x509sat-dis-tab.c"
oid_add_from_string("top","2.5.6.0");
oid_add_from_string("alias","2.5.6.1");
oid_add_from_string("country","2.5.6.2");
oid_add_from_string("locality","2.5.6.3");
oid_add_from_string("organization","2.5.6.4");
oid_add_from_string("organizationalUnit","2.5.6.5");
oid_add_from_string("person","2.5.6.6");
oid_add_from_string("organizationalPerson","2.5.6.7");
oid_add_from_string("organizationalRole","2.5.6.8");
oid_add_from_string("groupOfNames","2.5.6.9");
oid_add_from_string("residentialPerson","2.5.6.10");
oid_add_from_string("applicationProcess","2.5.6.11");
oid_add_from_string("applicationEntity","2.5.6.12");
oid_add_from_string("dSA","2.5.6.13");
oid_add_from_string("device","2.5.6.14");
oid_add_from_string("strongAuthenticationUser","2.5.6.15");
oid_add_from_string("certificationAuthority","2.5.6.16");
oid_add_from_string("certificationAuthorityV2","2.5.6.16.2");
oid_add_from_string("groupOfUniqueNames","2.5.6.17");
oid_add_from_string("userSecurityInformation","2.5.6.18");
oid_add_from_string("cRLDistributionPoint","2.5.6.19");
oid_add_from_string("dmd","2.5.6.20");
oid_add_from_string("pkiUser","2.5.6.21");
oid_add_from_string("pkiCA","2.5.6.22");
oid_add_from_string("parent","2.5.6.28");
oid_add_from_string("child","2.5.6.29");
oid_add_from_string("dcObject","1.3.6.1.4.1.1446.344");
oid_add_from_string("domain","0.9.2342.19200300.100.4.13");
oid_add_from_string("inetOrgPerson","2.16.840.1.113730.3.2.2");
}
