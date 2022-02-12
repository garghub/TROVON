static void
dissect_sv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0;
int old_offset;
proto_item *item;
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
item = proto_tree_add_item(parent_tree, proto_sv, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_sv);
col_set_str(pinfo->cinfo, COL_PROTOCOL, PNAME);
col_clear(pinfo->cinfo, COL_INFO);
if (tree && tvb_reported_length_remaining(tvb, offset) >= 2)
proto_tree_add_item(tree, hf_sv_appid, tvb, offset, 2, ENC_BIG_ENDIAN);
if (tree && tvb_reported_length_remaining(tvb, offset) >= 4)
proto_tree_add_item(tree, hf_sv_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (tree && tvb_reported_length_remaining(tvb, offset) >= 6)
proto_tree_add_item(tree, hf_sv_reserve1, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
if (tree && tvb_reported_length_remaining(tvb, offset) >= 8)
proto_tree_add_item(tree, hf_sv_reserve2, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
offset = 8;
while (tree && tvb_reported_length_remaining(tvb, offset) > 0){
old_offset = offset;
offset = dissect_sv_SampledValues(FALSE, tvb, offset, &asn1_ctx , tree, -1);
if (offset == old_offset) {
proto_tree_add_expert(tree, pinfo, &ei_sv_zero_pdu, tvb, offset, -1);
break;
}
}
if(tree)
tap_queue_packet(sv_tap, pinfo, &sv_data);
}
void proto_register_sv(void) {
static hf_register_info hf[] = {
{ &hf_sv_appid,
{ "APPID", "sv.appid", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sv_length,
{ "Length", "sv.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sv_reserve1,
{ "Reserved 1", "sv.reserve1", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sv_reserve2,
{ "Reserved 2", "sv.reserve2", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
#if 0
{ &hf_sv_phmeas_instmag_i,
{ "value", "sv.meas_value", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_sv_phsmeas_q,
{ "quality", "sv.meas_quality", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_sv_phsmeas_q_validity,
{ "validity", "sv.meas_quality.validity", FT_UINT32, BASE_HEX, VALS(sv_q_validity_vals), Q_VALIDITY_MASK, NULL, HFILL}},
{ &hf_sv_phsmeas_q_overflow,
{ "overflow", "sv.meas_quality.overflow", FT_BOOLEAN, 32, NULL, Q_OVERFLOW, NULL, HFILL}},
{ &hf_sv_phsmeas_q_outofrange,
{ "out of range", "sv.meas_quality.outofrange", FT_BOOLEAN, 32, NULL, Q_OUTOFRANGE, NULL, HFILL}},
{ &hf_sv_phsmeas_q_badreference,
{ "bad reference", "sv.meas_quality.badreference", FT_BOOLEAN, 32, NULL, Q_BADREFERENCE, NULL, HFILL}},
{ &hf_sv_phsmeas_q_oscillatory,
{ "oscillatory", "sv.meas_quality.oscillatory", FT_BOOLEAN, 32, NULL, Q_OSCILLATORY, NULL, HFILL}},
{ &hf_sv_phsmeas_q_failure,
{ "failure", "sv.meas_quality.failure", FT_BOOLEAN, 32, NULL, Q_FAILURE, NULL, HFILL}},
{ &hf_sv_phsmeas_q_olddata,
{ "old data", "sv.meas_quality.olddata", FT_BOOLEAN, 32, NULL, Q_OLDDATA, NULL, HFILL}},
{ &hf_sv_phsmeas_q_inconsistent,
{ "inconsistent", "sv.meas_quality.inconsistent", FT_BOOLEAN, 32, NULL, Q_INCONSISTENT, NULL, HFILL}},
{ &hf_sv_phsmeas_q_inaccurate,
{ "inaccurate", "sv.meas_quality.inaccurate", FT_BOOLEAN, 32, NULL, Q_INACCURATE, NULL, HFILL}},
{ &hf_sv_phsmeas_q_source,
{ "source", "sv.meas_quality.source", FT_UINT32, BASE_HEX, VALS(sv_q_source_vals), Q_SOURCE_MASK, NULL, HFILL}},
{ &hf_sv_phsmeas_q_test,
{ "test", "sv.meas_quality.teset", FT_BOOLEAN, 32, NULL, Q_TEST, NULL, HFILL}},
{ &hf_sv_phsmeas_q_operatorblocked,
{ "operator blocked", "sv.meas_quality.operatorblocked", FT_BOOLEAN, 32, NULL, Q_OPERATORBLOCKED, NULL, HFILL}},
{ &hf_sv_phsmeas_q_derived,
{ "derived", "sv.meas_quality.derived", FT_BOOLEAN, 32, NULL, Q_DERIVED, NULL, HFILL}},
#endif
#include "packet-sv-hfarr.c"
};
static gint *ett[] = {
&ett_sv,
&ett_phsmeas,
&ett_phsmeas_q,
#include "packet-sv-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_sv_mal_utctime, { "sv.malformed.utctime", PI_MALFORMED, PI_WARN, "BER Error: malformed UTCTime encoding", EXPFILL }},
{ &ei_sv_zero_pdu, { "sv.zero_pdu", PI_PROTOCOL, PI_ERROR, "Internal error, zero-byte SV PDU", EXPFILL }},
};
expert_module_t* expert_sv;
proto_sv = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("sv", dissect_sv, proto_sv);
proto_register_field_array(proto_sv, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_sv = expert_register_protocol(proto_sv);
expert_register_field_array(expert_sv, ei, array_length(ei));
sv_tap = register_tap("sv");
}
void proto_reg_handoff_sv(void) {
dissector_handle_t sv_handle;
sv_handle = find_dissector("sv");
dissector_add_uint("ethertype", ETHERTYPE_IEC61850_SV, sv_handle);
}
