static void
dissect_x509ce_invalidityDate_callback(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_x509ce_GeneralizedTime(FALSE, tvb, 0, &asn1_ctx, tree, hf_x509ce_id_ce_invalidityDate);
}
static void
dissect_x509ce_baseUpdateTime_callback(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_x509ce_GeneralizedTime(FALSE, tvb, 0, &asn1_ctx, tree, hf_x509ce_id_ce_baseUpdateTime);
}
void proto_register_x509ce(void) {
static hf_register_info hf[] = {
{ &hf_x509ce_id_ce_baseUpdateTime,
{ "baseUpdateTime", "x509ce.id_ce_baseUpdateTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509ce_id_ce_invalidityDate,
{ "invalidityDate", "x509ce.id_ce_invalidityDate",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509ce_object_identifier_id,
{ "Id", "x509ce.id", FT_OID, BASE_NONE, NULL, 0,
"Object identifier Id", HFILL }},
{ &hf_x509ce_IPAddress,
{ "iPAddress", "x509ce.IPAddress", FT_IPv4, BASE_NONE, NULL, 0,
"IP Address", HFILL }},
#include "packet-x509ce-hfarr.c"
};
static gint *ett[] = {
#include "packet-x509ce-ettarr.c"
};
proto_x509ce = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_x509ce, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_x509ce(void) {
#include "packet-x509ce-dis-tab.c"
register_ber_oid_dissector("2.5.29.24", dissect_x509ce_invalidityDate_callback, proto_x509ce, "id-ce-invalidityDate");
register_ber_oid_dissector("2.5.29.51", dissect_x509ce_baseUpdateTime_callback, proto_x509ce, "id-ce-baseUpdateTime");
}
