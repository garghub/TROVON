static int
dissect_goose_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_goose_VisibleString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_goose_T_getReferenceRequestPDU_offset(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_getReferenceRequestPDU_offset_sequence_of, hf_index, ett_goose_T_getReferenceRequestPDU_offset);
return offset;
}
static int
dissect_goose_GetReferenceRequestPdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetReferenceRequestPdu_sequence, hf_index, ett_goose_GetReferenceRequestPdu);
return offset;
}
static int
dissect_goose_T_references(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_references_sequence_of, hf_index, ett_goose_T_references);
return offset;
}
static int
dissect_goose_GetElementRequestPdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetElementRequestPdu_sequence, hf_index, ett_goose_GetElementRequestPdu);
return offset;
}
static int
dissect_goose_GSEMngtRequests(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
GSEMngtRequests_choice, hf_index, ett_goose_GSEMngtRequests,
NULL);
return offset;
}
static int
dissect_goose_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_goose_IA5String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_goose_ErrorReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_goose_RequestResults(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RequestResults_choice, hf_index, ett_goose_RequestResults,
NULL);
return offset;
}
static int
dissect_goose_SEQUENCE_OF_RequestResults(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_RequestResults_sequence_of, hf_index, ett_goose_SEQUENCE_OF_RequestResults);
return offset;
}
static int
dissect_goose_T_responsePositive(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_responsePositive_sequence, hf_index, ett_goose_T_responsePositive);
return offset;
}
static int
dissect_goose_GlbErrors(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_goose_PositiveNegative(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PositiveNegative_choice, hf_index, ett_goose_PositiveNegative,
NULL);
return offset;
}
static int
dissect_goose_GSEMngtResponsePdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GSEMngtResponsePdu_sequence, hf_index, ett_goose_GSEMngtResponsePdu);
return offset;
}
static int
dissect_goose_GSEMngtResponses(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
GSEMngtResponses_choice, hf_index, ett_goose_GSEMngtResponses,
NULL);
return offset;
}
static int
dissect_goose_RequestResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RequestResponse_choice, hf_index, ett_goose_RequestResponse,
NULL);
return offset;
}
static int
dissect_goose_GSEMngtPdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GSEMngtPdu_sequence, hf_index, ett_goose_GSEMngtPdu);
return offset;
}
static int
dissect_goose_UtcTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 17 "./asn1/goose/goose.cnf"
guint32 len;
guint32 seconds;
guint32 fraction;
guint32 nanoseconds;
nstime_t ts;
gchar * ptime;
len = tvb_reported_length_remaining(tvb, offset);
if(len != 8)
{
proto_tree_add_expert(tree, actx->pinfo, &ei_goose_mal_utctime, tvb, offset, len);
if(hf_index >= 0)
{
proto_tree_add_string(tree, hf_index, tvb, offset, len, "????");
}
return offset;
}
seconds = tvb_get_ntohl(tvb, offset);
fraction = tvb_get_ntoh24(tvb, offset+4) * 0x100;
nanoseconds = (guint32)( ((guint64)fraction * G_GUINT64_CONSTANT(1000000000)) / G_GUINT64_CONSTANT(0x100000000) ) ;
ts.secs = seconds;
ts.nsecs = nanoseconds;
ptime = abs_time_to_str(wmem_packet_scope(), &ts, ABSOLUTE_TIME_UTC, TRUE);
if(hf_index >= 0)
{
proto_tree_add_string(tree, hf_index, tvb, offset, len, ptime);
}
return offset;
return offset;
}
static int
dissect_goose_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_goose_SEQUENCE_OF_Data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Data_sequence_of, hf_index, ett_goose_SEQUENCE_OF_Data);
return offset;
}
static int
dissect_goose_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_goose_FloatingPoint(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_goose_REAL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_real(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_goose_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_goose_TimeOfDay(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_goose_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_goose_MMSString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UTF8String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_goose_Data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Data_choice, hf_index, ett_goose_Data,
NULL);
return offset;
}
static int
dissect_goose_IECGoosePdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IECGoosePdu_sequence, hf_index, ett_goose_IECGoosePdu);
return offset;
}
static int
dissect_goose_GOOSEpdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
GOOSEpdu_choice, hf_index, ett_goose_GOOSEpdu,
NULL);
return offset;
}
static int
dissect_goose(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
int offset = 0;
int old_offset;
guint16 length;
proto_item *item = NULL;
proto_tree *tree = NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, PNAME);
col_clear(pinfo->cinfo, COL_INFO);
item = proto_tree_add_item(parent_tree, proto_goose, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_goose);
proto_tree_add_item(tree, hf_goose_appid, tvb, offset, 2, ENC_BIG_ENDIAN);
length = tvb_get_ntohs(tvb, offset + 2);
proto_tree_add_item(tree, hf_goose_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_goose_reserve1, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_goose_reserve2, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
offset = 8;
while (offset < length){
old_offset = offset;
offset = dissect_goose_GOOSEpdu(FALSE, tvb, offset, &asn1_ctx , tree, -1);
if (offset == old_offset) {
proto_tree_add_expert(tree, pinfo, &ei_goose_zero_pdu, tvb, offset, -1);
break;
}
}
return tvb_captured_length(tvb);
}
void proto_register_goose(void) {
static hf_register_info hf[] =
{
{ &hf_goose_appid,
{ "APPID", "goose.appid", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_goose_length,
{ "Length", "goose.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_goose_reserve1,
{ "Reserved 1", "goose.reserve1", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_goose_reserve2,
{ "Reserved 2", "goose.reserve2", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
#line 1 "./asn1/goose/packet-goose-hfarr.c"
{ &hf_goose_gseMngtPdu,
{ "gseMngtPdu", "goose.gseMngtPdu_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_goose_goosePdu,
{ "goosePdu", "goose.goosePdu_element",
FT_NONE, BASE_NONE, NULL, 0,
"IECGoosePdu", HFILL }},
{ &hf_goose_stateID,
{ "stateID", "goose.stateID",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_goose_requestResp,
{ "requestResp", "goose.requestResp",
FT_UINT32, BASE_DEC, VALS(goose_RequestResponse_vals), 0,
"RequestResponse", HFILL }},
{ &hf_goose_requests,
{ "requests", "goose.requests",
FT_UINT32, BASE_DEC, VALS(goose_GSEMngtRequests_vals), 0,
"GSEMngtRequests", HFILL }},
{ &hf_goose_responses,
{ "responses", "goose.responses",
FT_UINT32, BASE_DEC, VALS(goose_GSEMngtResponses_vals), 0,
"GSEMngtResponses", HFILL }},
{ &hf_goose_getGoReference,
{ "getGoReference", "goose.getGoReference_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetReferenceRequestPdu", HFILL }},
{ &hf_goose_getGOOSEElementNumber,
{ "getGOOSEElementNumber", "goose.getGOOSEElementNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetElementRequestPdu", HFILL }},
{ &hf_goose_getGsReference,
{ "getGsReference", "goose.getGsReference_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetReferenceRequestPdu", HFILL }},
{ &hf_goose_getGSSEDataOffset,
{ "getGSSEDataOffset", "goose.getGSSEDataOffset_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetElementRequestPdu", HFILL }},
{ &hf_goose_gseMngtNotSupported,
{ "gseMngtNotSupported", "goose.gseMngtNotSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_goose_gseMngtResponses_GetGOReference,
{ "getGoReference", "goose.getGoReference_element",
FT_NONE, BASE_NONE, NULL, 0,
"GSEMngtResponsePdu", HFILL }},
{ &hf_goose_gseMngtResponses_GetGOOSEElementNumber,
{ "getGOOSEElementNumber", "goose.getGOOSEElementNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
"GSEMngtResponsePdu", HFILL }},
{ &hf_goose_gseMngtResponses_GetGSReference,
{ "getGsReference", "goose.getGsReference_element",
FT_NONE, BASE_NONE, NULL, 0,
"GSEMngtResponsePdu", HFILL }},
{ &hf_goose_gseMngtResponses_GetGSSEDataOffset,
{ "getGSSEDataOffset", "goose.getGSSEDataOffset_element",
FT_NONE, BASE_NONE, NULL, 0,
"GSEMngtResponsePdu", HFILL }},
{ &hf_goose_ident,
{ "ident", "goose.ident",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_goose_getReferenceRequestPDU_offset,
{ "offset", "goose.offset",
FT_UINT32, BASE_DEC, NULL, 0,
"T_getReferenceRequestPDU_offset", HFILL }},
{ &hf_goose_getReferenceRequestPDU_offset_item,
{ "offset item", "goose.offset_item",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_goose_references,
{ "references", "goose.references",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_goose_references_item,
{ "references item", "goose.references_item",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_goose_confRev,
{ "confRev", "goose.confRev",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_goose_posNeg,
{ "posNeg", "goose.posNeg",
FT_UINT32, BASE_DEC, VALS(goose_PositiveNegative_vals), 0,
"PositiveNegative", HFILL }},
{ &hf_goose_responsePositive,
{ "responsePositive", "goose.responsePositive_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_goose_datSet,
{ "datSet", "goose.datSet",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_goose_result,
{ "result", "goose.result",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_RequestResults", HFILL }},
{ &hf_goose_result_item,
{ "RequestResults", "goose.RequestResults",
FT_UINT32, BASE_DEC, VALS(goose_RequestResults_vals), 0,
NULL, HFILL }},
{ &hf_goose_responseNegative,
{ "responseNegative", "goose.responseNegative",
FT_INT32, BASE_DEC, VALS(goose_GlbErrors_vals), 0,
"GlbErrors", HFILL }},
{ &hf_goose_offset,
{ "offset", "goose.offset",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_goose_reference,
{ "reference", "goose.reference",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String", HFILL }},
{ &hf_goose_error,
{ "error", "goose.error",
FT_INT32, BASE_DEC, VALS(goose_ErrorReason_vals), 0,
"ErrorReason", HFILL }},
{ &hf_goose_gocbRef,
{ "gocbRef", "goose.gocbRef",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_goose_timeAllowedtoLive,
{ "timeAllowedtoLive", "goose.timeAllowedtoLive",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_goose_goID,
{ "goID", "goose.goID",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_goose_t,
{ "t", "goose.t",
FT_STRING, BASE_NONE, NULL, 0,
"UtcTime", HFILL }},
{ &hf_goose_stNum,
{ "stNum", "goose.stNum",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_goose_sqNum,
{ "sqNum", "goose.sqNum",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_goose_test,
{ "test", "goose.test",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_goose_ndsCom,
{ "ndsCom", "goose.ndsCom",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_goose_numDatSetEntries,
{ "numDatSetEntries", "goose.numDatSetEntries",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_goose_allData,
{ "allData", "goose.allData",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Data", HFILL }},
{ &hf_goose_allData_item,
{ "Data", "goose.Data",
FT_UINT32, BASE_DEC, VALS(goose_Data_vals), 0,
NULL, HFILL }},
{ &hf_goose_array,
{ "array", "goose.array",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Data", HFILL }},
{ &hf_goose_array_item,
{ "Data", "goose.Data",
FT_UINT32, BASE_DEC, VALS(goose_Data_vals), 0,
NULL, HFILL }},
{ &hf_goose_structure,
{ "structure", "goose.structure",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Data", HFILL }},
{ &hf_goose_structure_item,
{ "Data", "goose.Data",
FT_UINT32, BASE_DEC, VALS(goose_Data_vals), 0,
NULL, HFILL }},
{ &hf_goose_boolean,
{ "boolean", "goose.boolean",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_goose_bit_string,
{ "bit-string", "goose.bit_string",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_goose_integer,
{ "integer", "goose.integer",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_goose_unsigned,
{ "unsigned", "goose.unsigned",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_goose_floating_point,
{ "floating-point", "goose.floating_point",
FT_BYTES, BASE_NONE, NULL, 0,
"FloatingPoint", HFILL }},
{ &hf_goose_real,
{ "real", "goose.real",
FT_DOUBLE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_goose_octet_string,
{ "octet-string", "goose.octet_string",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_goose_visible_string,
{ "visible-string", "goose.visible_string",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_goose_binary_time,
{ "binary-time", "goose.binary_time",
FT_BYTES, BASE_NONE, NULL, 0,
"TimeOfDay", HFILL }},
{ &hf_goose_bcd,
{ "bcd", "goose.bcd",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_goose_booleanArray,
{ "booleanArray", "goose.booleanArray",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_goose_objId,
{ "objId", "goose.objId",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_goose_mMSString,
{ "mMSString", "goose.mMSString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_goose_utc_time,
{ "utc-time", "goose.utc_time",
FT_STRING, BASE_NONE, NULL, 0,
"UtcTime", HFILL }},
#line 129 "./asn1/goose/packet-goose-template.c"
};
static gint *ett[] = {
&ett_goose,
#line 1 "./asn1/goose/packet-goose-ettarr.c"
&ett_goose_GOOSEpdu,
&ett_goose_GSEMngtPdu,
&ett_goose_RequestResponse,
&ett_goose_GSEMngtRequests,
&ett_goose_GSEMngtResponses,
&ett_goose_GetReferenceRequestPdu,
&ett_goose_T_getReferenceRequestPDU_offset,
&ett_goose_GetElementRequestPdu,
&ett_goose_T_references,
&ett_goose_GSEMngtResponsePdu,
&ett_goose_PositiveNegative,
&ett_goose_T_responsePositive,
&ett_goose_SEQUENCE_OF_RequestResults,
&ett_goose_RequestResults,
&ett_goose_IECGoosePdu,
&ett_goose_SEQUENCE_OF_Data,
&ett_goose_Data,
#line 135 "./asn1/goose/packet-goose-template.c"
};
static ei_register_info ei[] = {
{ &ei_goose_mal_utctime, { "goose.malformed.utctime", PI_MALFORMED, PI_WARN, "BER Error: malformed UTCTime encoding", EXPFILL }},
{ &ei_goose_zero_pdu, { "goose.zero_pdu", PI_PROTOCOL, PI_ERROR, "Internal error, zero-byte GOOSE PDU", EXPFILL }},
};
expert_module_t* expert_goose;
proto_goose = proto_register_protocol(PNAME, PSNAME, PFNAME);
goose_handle = register_dissector("goose", dissect_goose, proto_goose);
proto_register_field_array(proto_goose, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_goose = expert_register_protocol(proto_goose);
expert_register_field_array(expert_goose, ei, array_length(ei));
}
void proto_reg_handoff_goose(void) {
dissector_add_uint("ethertype", ETHERTYPE_IEC61850_GOOSE, goose_handle);
}
