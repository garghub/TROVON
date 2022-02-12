void proto_register_pkcs1(void) {
static hf_register_info hf[] = {
#include "packet-pkcs1-hfarr.c"
};
static gint *ett[] = {
#include "packet-pkcs1-ettarr.c"
};
proto_pkcs1 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkcs1, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_pkcs1(void) {
#include "packet-pkcs1-dis-tab.c"
register_ber_oid_dissector("1.2.840.113549.2.2", dissect_ber_oid_NULL_callback, proto_pkcs1, "md2");
register_ber_oid_dissector("1.2.840.113549.2.4", dissect_ber_oid_NULL_callback, proto_pkcs1, "md4");
register_ber_oid_dissector("1.2.840.113549.2.5", dissect_ber_oid_NULL_callback, proto_pkcs1, "md5");
register_ber_oid_dissector("1.2.840.113549.1.1.1", dissect_ber_oid_NULL_callback, proto_pkcs1, "rsaEncryption");
register_ber_oid_dissector("1.2.840.113549.1.1.2", dissect_ber_oid_NULL_callback, proto_pkcs1, "md2WithRSAEncryption");
register_ber_oid_dissector("1.2.840.113549.1.1.3", dissect_ber_oid_NULL_callback, proto_pkcs1, "md4WithRSAEncryption");
register_ber_oid_dissector("1.2.840.113549.1.1.4", dissect_ber_oid_NULL_callback, proto_pkcs1, "md5WithRSAEncryption");
register_ber_oid_dissector("1.2.840.113549.1.1.5", dissect_ber_oid_NULL_callback, proto_pkcs1, "shaWithRSAEncryption");
register_ber_oid_dissector("1.2.840.113549.1.1.6", dissect_ber_oid_NULL_callback, proto_pkcs1, "rsaOAEPEncryptionSET");
oid_add_from_string("secp192r1","1.2.840.10045.3.1.1");
oid_add_from_string("sect163k1","1.3.132.0.1");
oid_add_from_string("sect163r2","1.3.132.0.15");
oid_add_from_string("secp224r1","1.3.132.0.33");
oid_add_from_string("sect233k1","1.3.132.0.26");
oid_add_from_string("sect233r1","1.3.132.0.27");
oid_add_from_string("secp256r1","1.2.840.10045.3.1.7");
oid_add_from_string("sect283k1","1.3.132.0.16");
oid_add_from_string("sect283r1","1.3.132.0.17");
oid_add_from_string("secp384r1","1.3.132.0.34");
oid_add_from_string("sect409k1","1.3.132.0.36");
oid_add_from_string("sect409r1","1.3.132.0.37");
oid_add_from_string("sect521r1","1.3.132.0.35")
; oid_add_from_string("sect571k1","1.3.132.0.38");
oid_add_from_string("sect571r1","1.3.132.0.39");
}
