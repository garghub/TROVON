static int
dissect_wlancertextn_SSID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_wlancertextn_SSIDList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SSIDList_sequence_of, hf_index, ett_wlancertextn_SSIDList);
return offset;
}
static void dissect_SSIDList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_wlancertextn_SSIDList(FALSE, tvb, 0, &asn1_ctx, tree, hf_wlancertextn_SSIDList_PDU);
}
void proto_register_wlancertextn(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/wlancertextn/packet-wlancertextn-hfarr.c"
{ &hf_wlancertextn_SSIDList_PDU,
{ "SSIDList", "wlancertextn.SSIDList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_wlancertextn_SSIDList_item,
{ "SSID", "wlancertextn.SSID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 60 "../../asn1/wlancertextn/packet-wlancertextn-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/wlancertextn/packet-wlancertextn-ettarr.c"
&ett_wlancertextn_SSIDList,
#line 65 "../../asn1/wlancertextn/packet-wlancertextn-template.c"
};
proto_wlancertextn = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_wlancertextn, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_wlancertextn(void) {
#line 1 "../../asn1/wlancertextn/packet-wlancertextn-dis-tab.c"
register_ber_oid_dissector("1.3.6.1.5.5.7.1.13", dissect_SSIDList_PDU, proto_wlancertextn, "id-pe-wlanSSID");
register_ber_oid_dissector("1.3.6.1.5.5.7.10.6", dissect_SSIDList_PDU, proto_wlancertextn, "id-aca-wlanSSID");
#line 80 "../../asn1/wlancertextn/packet-wlancertextn-template.c"
oid_add_from_string("id-kp-eapOverPPP","1.3.6.1.5.5.7.3.13");
oid_add_from_string("id-kp-eapOverLAN","1.3.6.1.5.5.7.3.14");
}
