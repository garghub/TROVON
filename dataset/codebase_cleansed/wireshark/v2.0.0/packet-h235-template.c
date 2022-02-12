static int
dissect_xxx_ToBeSigned(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_) {
dissect_per_not_decoded_yet(tree, actx->pinfo, tvb, "ToBeSigned");
return offset;
}
void proto_register_h235(void) {
static hf_register_info hf[] = {
#include "packet-h235-hfarr.c"
};
static gint *ett[] = {
#include "packet-h235-ettarr.c"
};
proto_h235 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h235, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
oid_add_from_string("all fields in RAS/CS","0.0.8.235.0.1.1");
oid_add_from_string("all fields in RAS/CS","0.0.8.235.0.2.1");
oid_add_from_string("ClearToken","0.0.8.235.0.1.5");
oid_add_from_string("ClearToken","0.0.8.235.0.2.5");
oid_add_from_string("HMAC-SHA1-96","0.0.8.235.0.1.6");
oid_add_from_string("HMAC-SHA1-96","0.0.8.235.0.2.6");
oid_add_from_string("MIKEY", OID_MIKEY);
oid_add_from_string("MIKEY-PS", OID_MIKEY_PS);
oid_add_from_string("MIKEY-DHHMAC", OID_MIKEY_DHHMAC);
oid_add_from_string("MIKEY-PK-SIGN", OID_MIKEY_PK_SIGN);
oid_add_from_string("MIKEY-DH-SIGN", OID_MIKEY_DH_SIGN);
oid_add_from_string("TG",OID_TG);
oid_add_from_string("SG",OID_SG);
oid_add_from_string("AES_CM_128_HMAC_SHA1_80","0.0.8.235.0.4.91");
oid_add_from_string("AES_CM_128_HMAC_SHA1_32","0.0.8.235.0.4.92");
oid_add_from_string("F8_128_HMAC_SHA1_80","0.0.8.235.0.4.93");
}
void proto_reg_handoff_h235(void) {
dissector_handle_t mikey_handle;
mikey_handle = find_dissector("mikey");
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY "/nonCollapsing/0", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_PS "/nonCollapsing/0", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_DHHMAC "/nonCollapsing/0", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_PK_SIGN "/nonCollapsing/0", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_DH_SIGN "/nonCollapsing/0", mikey_handle);
dissector_add_string("h245.gef.content", "EncryptionSync/0", mikey_handle);
dissector_add_string("h245.gef.content", "EncryptionSync/76", mikey_handle);
dissector_add_string("h245.gef.content", "EncryptionSync/72", mikey_handle);
dissector_add_string("h245.gef.content", "EncryptionSync/73", mikey_handle);
dissector_add_string("h245.gef.content", "EncryptionSync/74", mikey_handle);
dissector_add_string("h245.gef.content", "EncryptionSync/75", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY "/nonCollapsing/76", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_PS "/nonCollapsing/72", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_DHHMAC "/nonCollapsing/73", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_PK_SIGN "/nonCollapsing/74", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/" OID_MIKEY_DH_SIGN "/nonCollapsing/75", mikey_handle);
dissector_add_string("h245.gef.content", "GenericCapability/0.0.8.235.0.4.90/nonCollapsingRaw",
new_create_dissector_handle(dissect_SrtpCryptoCapability_PDU, proto_h235));
}
