static void
dissect_gnm_attribute_ObjectInstance(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cmip_ObjectInstance(FALSE, tvb, 0, &asn1_ctx, parent_tree, -1);
}
static void
dissect_gnm(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_)
{
}
void proto_register_gnm(void) {
static hf_register_info hf[] = {
#include "packet-gnm-hfarr.c"
};
static gint *ett[] = {
#include "packet-gnm-ettarr.c"
};
proto_gnm = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("gnm", dissect_gnm, proto_gnm);
proto_register_field_array(proto_gnm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_gnm(void) {
#include "packet-gnm-dis-tab.c"
register_ber_oid_dissector("0.0.13.3100.0.7.9", dissect_gnm_attribute_ObjectInstance, proto_gnm, "clientConnection(9)");
register_ber_oid_dissector("0.0.13.3100.0.7.10", dissect_gnm_attribute_ObjectInstance, proto_gnm, "clientTrail(10)");
register_ber_oid_dissector("0.0.13.3100.0.7.31", dissect_gnm_attribute_ObjectInstance, proto_gnm, "networkLevelPointer(31)");
register_ber_oid_dissector("0.0.13.3100.0.7.46", dissect_gnm_attribute_ObjectInstance, proto_gnm, "networkLevelPointer(31)");
}
