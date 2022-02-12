static int
dissect_sv_INTEGER_0_65535(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_sv_VisibleString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_sv_T_smpCnt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 19 "../../asn1/sv/sv.cnf"
guint32 value;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&value);
sv_data.smpCnt = value;
return offset;
}
static int
dissect_sv_INTEGER_0_4294967295(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_sv_UtcTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 25 "../../asn1/sv/sv.cnf"
guint32 len;
guint32 seconds;
guint32 fraction;
guint32 nanoseconds;
nstime_t ts;
gchar * ptime;
len = tvb_length_remaining(tvb, offset);
if(len != 8)
{
proto_tree_add_expert_format(tree, actx->pinfo, &ei_sv_mal_utctime, tvb, offset, len,
"BER Error: malformed UTCTime encoding, length must be 8 bytes");
if(hf_index >= 0)
{
proto_tree_add_string(tree, hf_index, tvb, offset, len, "????");
}
return offset;
}
seconds = tvb_get_ntohl(tvb, offset);
fraction = tvb_get_ntoh24(tvb, offset+4) * 0x100;
nanoseconds = (guint32)( ((guint64)fraction * G_GINT64_CONSTANT(1000000000U)) / G_GINT64_CONSTANT(0x100000000U) ) ;
ts.secs = seconds;
ts.nsecs = nanoseconds;
ptime = abs_time_to_str(&ts, ABSOLUTE_TIME_UTC, TRUE);
if(hf_index >= 0)
{
proto_tree_add_string(tree, hf_index, tvb, offset, len, ptime);
}
offset += 8;
return offset;
return offset;
}
static int
dissect_sv_T_smpSynch(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 66 "../../asn1/sv/sv.cnf"
guint32 value;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&value);
sv_data.smpSynch = value;
return offset;
}
static int
dissect_sv_Data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_sv_T_smpMod(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 72 "../../asn1/sv/sv.cnf"
guint32 value;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&value);
sv_data.smpMod = value;
return offset;
}
static int
dissect_sv_ASDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ASDU_sequence, hf_index, ett_sv_ASDU);
return offset;
}
static int
dissect_sv_SEQUENCE_OF_ASDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ASDU_sequence_of, hf_index, ett_sv_SEQUENCE_OF_ASDU);
return offset;
}
static int
dissect_sv_SavPdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SavPdu_sequence, hf_index, ett_sv_SavPdu);
return offset;
}
static int
dissect_sv_SampledValues(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SampledValues_choice, hf_index, ett_sv_SampledValues,
NULL);
return offset;
}
static void
dissect_sv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0;
int old_offset;
proto_item *item = NULL;
proto_tree *tree = NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if (parent_tree){
item = proto_tree_add_item(parent_tree, proto_sv, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_sv);
}
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
proto_tree_add_text(tree, tvb, offset, -1, "Internal error, zero-byte SV PDU");
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
#line 1 "../../asn1/sv/packet-sv-hfarr.c"
{ &hf_sv_savPdu,
{ "savPdu", "sv.savPdu_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sv_noASDU,
{ "noASDU", "sv.noASDU",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_sv_seqASDU,
{ "seqASDU", "sv.seqASDU",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ASDU", HFILL }},
{ &hf_sv_seqASDU_item,
{ "ASDU", "sv.ASDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sv_svID,
{ "svID", "sv.svID",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_sv_datSet,
{ "datSet", "sv.datSet",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_sv_smpCnt,
{ "smpCnt", "sv.smpCnt",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sv_confRef,
{ "confRef", "sv.confRef",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_sv_refrTm,
{ "refrTm", "sv.refrTm",
FT_STRING, BASE_NONE, NULL, 0,
"UtcTime", HFILL }},
{ &hf_sv_smpSynch,
{ "smpSynch", "sv.smpSynch",
FT_INT32, BASE_DEC, VALS(sv_T_smpSynch_vals), 0,
NULL, HFILL }},
{ &hf_sv_smpRate,
{ "smpRate", "sv.smpRate",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_sv_seqData,
{ "seqData", "sv.seqData",
FT_BYTES, BASE_NONE, NULL, 0,
"Data", HFILL }},
{ &hf_sv_smpMod,
{ "smpMod", "sv.smpMod",
FT_INT32, BASE_DEC, VALS(sv_T_smpMod_vals), 0,
NULL, HFILL }},
#line 311 "../../asn1/sv/packet-sv-template.c"
};
static gint *ett[] = {
&ett_sv,
&ett_phsmeas,
&ett_phsmeas_q,
#line 1 "../../asn1/sv/packet-sv-ettarr.c"
&ett_sv_SampledValues,
&ett_sv_SavPdu,
&ett_sv_SEQUENCE_OF_ASDU,
&ett_sv_ASDU,
#line 319 "../../asn1/sv/packet-sv-template.c"
};
static ei_register_info ei[] = {
{ &ei_sv_mal_utctime, { "sv.malformed.utctime", PI_MALFORMED, PI_WARN, "BER Error: malformed UTCTime encoding", EXPFILL }},
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
