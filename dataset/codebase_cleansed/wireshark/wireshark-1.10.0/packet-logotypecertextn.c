static int
dissect_logotypecertextn_IA5String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_logotypecertextn_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_logotypecertextn_HashAlgAndValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
HashAlgAndValue_sequence, hf_index, ett_logotypecertextn_HashAlgAndValue);
return offset;
}
static int
dissect_logotypecertextn_SEQUENCE_SIZE_1_MAX_OF_HashAlgAndValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_HashAlgAndValue_sequence_of, hf_index, ett_logotypecertextn_SEQUENCE_SIZE_1_MAX_OF_HashAlgAndValue);
return offset;
}
static int
dissect_logotypecertextn_T_logotypeURI_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
#line 18 "../../asn1/logotypecertextn/logotypecertextn.cnf"
PROTO_ITEM_SET_URL(actx->created_item);
return offset;
}
static int
dissect_logotypecertextn_T_logotypeURI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_logotypeURI_sequence_of, hf_index, ett_logotypecertextn_T_logotypeURI);
return offset;
}
static int
dissect_logotypecertextn_LogotypeDetails(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LogotypeDetails_sequence, hf_index, ett_logotypecertextn_LogotypeDetails);
return offset;
}
static int
dissect_logotypecertextn_LogotypeImageType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_logotypecertextn_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_logotypecertextn_LogotypeImageResolution(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
LogotypeImageResolution_choice, hf_index, ett_logotypecertextn_LogotypeImageResolution,
NULL);
return offset;
}
static int
dissect_logotypecertextn_LogotypeImageInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LogotypeImageInfo_sequence, hf_index, ett_logotypecertextn_LogotypeImageInfo);
return offset;
}
static int
dissect_logotypecertextn_LogotypeImage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LogotypeImage_sequence, hf_index, ett_logotypecertextn_LogotypeImage);
return offset;
}
static int
dissect_logotypecertextn_SEQUENCE_OF_LogotypeImage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_LogotypeImage_sequence_of, hf_index, ett_logotypecertextn_SEQUENCE_OF_LogotypeImage);
return offset;
}
static int
dissect_logotypecertextn_LogotypeAudioInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LogotypeAudioInfo_sequence, hf_index, ett_logotypecertextn_LogotypeAudioInfo);
return offset;
}
static int
dissect_logotypecertextn_LogotypeAudio(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LogotypeAudio_sequence, hf_index, ett_logotypecertextn_LogotypeAudio);
return offset;
}
static int
dissect_logotypecertextn_SEQUENCE_OF_LogotypeAudio(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_LogotypeAudio_sequence_of, hf_index, ett_logotypecertextn_SEQUENCE_OF_LogotypeAudio);
return offset;
}
static int
dissect_logotypecertextn_LogotypeData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LogotypeData_sequence, hf_index, ett_logotypecertextn_LogotypeData);
return offset;
}
static int
dissect_logotypecertextn_T_refStructURI_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
#line 21 "../../asn1/logotypecertextn/logotypecertextn.cnf"
PROTO_ITEM_SET_URL(actx->created_item);
return offset;
}
static int
dissect_logotypecertextn_T_refStructURI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_refStructURI_sequence_of, hf_index, ett_logotypecertextn_T_refStructURI);
return offset;
}
static int
dissect_logotypecertextn_LogotypeReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LogotypeReference_sequence, hf_index, ett_logotypecertextn_LogotypeReference);
return offset;
}
static int
dissect_logotypecertextn_LogotypeInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
LogotypeInfo_choice, hf_index, ett_logotypecertextn_LogotypeInfo,
NULL);
return offset;
}
static int
dissect_logotypecertextn_SEQUENCE_OF_LogotypeInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_LogotypeInfo_sequence_of, hf_index, ett_logotypecertextn_SEQUENCE_OF_LogotypeInfo);
return offset;
}
static int
dissect_logotypecertextn_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_logotypecertextn_OtherLogotypeInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OtherLogotypeInfo_sequence, hf_index, ett_logotypecertextn_OtherLogotypeInfo);
return offset;
}
static int
dissect_logotypecertextn_SEQUENCE_OF_OtherLogotypeInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_OtherLogotypeInfo_sequence_of, hf_index, ett_logotypecertextn_SEQUENCE_OF_OtherLogotypeInfo);
return offset;
}
static int
dissect_logotypecertextn_LogotypeExtn(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LogotypeExtn_sequence, hf_index, ett_logotypecertextn_LogotypeExtn);
return offset;
}
static void dissect_LogotypeExtn_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_logotypecertextn_LogotypeExtn(FALSE, tvb, 0, &asn1_ctx, tree, hf_logotypecertextn_LogotypeExtn_PDU);
}
void proto_register_logotypecertextn(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/logotypecertextn/packet-logotypecertextn-hfarr.c"
{ &hf_logotypecertextn_LogotypeExtn_PDU,
{ "LogotypeExtn", "logotypecertextn.LogotypeExtn",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_logotypecertextn_communityLogos,
{ "communityLogos", "logotypecertextn.communityLogos",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_LogotypeInfo", HFILL }},
{ &hf_logotypecertextn_communityLogos_item,
{ "LogotypeInfo", "logotypecertextn.LogotypeInfo",
FT_UINT32, BASE_DEC, VALS(logotypecertextn_LogotypeInfo_vals), 0,
NULL, HFILL }},
{ &hf_logotypecertextn_issuerLogo,
{ "issuerLogo", "logotypecertextn.issuerLogo",
FT_UINT32, BASE_DEC, VALS(logotypecertextn_LogotypeInfo_vals), 0,
"LogotypeInfo", HFILL }},
{ &hf_logotypecertextn_subjectLogo,
{ "subjectLogo", "logotypecertextn.subjectLogo",
FT_UINT32, BASE_DEC, VALS(logotypecertextn_LogotypeInfo_vals), 0,
"LogotypeInfo", HFILL }},
{ &hf_logotypecertextn_otherLogos,
{ "otherLogos", "logotypecertextn.otherLogos",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_OtherLogotypeInfo", HFILL }},
{ &hf_logotypecertextn_otherLogos_item,
{ "OtherLogotypeInfo", "logotypecertextn.OtherLogotypeInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_logotypecertextn_direct,
{ "direct", "logotypecertextn.direct",
FT_NONE, BASE_NONE, NULL, 0,
"LogotypeData", HFILL }},
{ &hf_logotypecertextn_indirect,
{ "indirect", "logotypecertextn.indirect",
FT_NONE, BASE_NONE, NULL, 0,
"LogotypeReference", HFILL }},
{ &hf_logotypecertextn_image,
{ "image", "logotypecertextn.image",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_LogotypeImage", HFILL }},
{ &hf_logotypecertextn_image_item,
{ "LogotypeImage", "logotypecertextn.LogotypeImage",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_logotypecertextn_audio,
{ "audio", "logotypecertextn.audio",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_LogotypeAudio", HFILL }},
{ &hf_logotypecertextn_audio_item,
{ "LogotypeAudio", "logotypecertextn.LogotypeAudio",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_logotypecertextn_imageDetails,
{ "imageDetails", "logotypecertextn.imageDetails",
FT_NONE, BASE_NONE, NULL, 0,
"LogotypeDetails", HFILL }},
{ &hf_logotypecertextn_imageInfo,
{ "imageInfo", "logotypecertextn.imageInfo",
FT_NONE, BASE_NONE, NULL, 0,
"LogotypeImageInfo", HFILL }},
{ &hf_logotypecertextn_audioDetails,
{ "audioDetails", "logotypecertextn.audioDetails",
FT_NONE, BASE_NONE, NULL, 0,
"LogotypeDetails", HFILL }},
{ &hf_logotypecertextn_audioInfo,
{ "audioInfo", "logotypecertextn.audioInfo",
FT_NONE, BASE_NONE, NULL, 0,
"LogotypeAudioInfo", HFILL }},
{ &hf_logotypecertextn_mediaType,
{ "mediaType", "logotypecertextn.mediaType",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String", HFILL }},
{ &hf_logotypecertextn_logotypeHash,
{ "logotypeHash", "logotypecertextn.logotypeHash",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_HashAlgAndValue", HFILL }},
{ &hf_logotypecertextn_logotypeHash_item,
{ "HashAlgAndValue", "logotypecertextn.HashAlgAndValue",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_logotypecertextn_logotypeURI,
{ "logotypeURI", "logotypecertextn.logotypeURI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_logotypecertextn_logotypeURI_item,
{ "logotypeURI item", "logotypecertextn.logotypeURI_item",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_logotypecertextn_type,
{ "type", "logotypecertextn.type",
FT_INT32, BASE_DEC, VALS(logotypecertextn_LogotypeImageType_vals), 0,
"LogotypeImageType", HFILL }},
{ &hf_logotypecertextn_fileSize,
{ "fileSize", "logotypecertextn.fileSize",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_logotypecertextn_xSize,
{ "xSize", "logotypecertextn.xSize",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_logotypecertextn_ySize,
{ "ySize", "logotypecertextn.ySize",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_logotypecertextn_resolution,
{ "resolution", "logotypecertextn.resolution",
FT_UINT32, BASE_DEC, VALS(logotypecertextn_LogotypeImageResolution_vals), 0,
"LogotypeImageResolution", HFILL }},
{ &hf_logotypecertextn_language,
{ "language", "logotypecertextn.language",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String", HFILL }},
{ &hf_logotypecertextn_numBits,
{ "numBits", "logotypecertextn.numBits",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_logotypecertextn_tableSize,
{ "tableSize", "logotypecertextn.tableSize",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_logotypecertextn_playTime,
{ "playTime", "logotypecertextn.playTime",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_logotypecertextn_channels,
{ "channels", "logotypecertextn.channels",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_logotypecertextn_sampleRate,
{ "sampleRate", "logotypecertextn.sampleRate",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_logotypecertextn_logotypeType,
{ "logotypeType", "logotypecertextn.logotypeType",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_logotypecertextn_info,
{ "info", "logotypecertextn.info",
FT_UINT32, BASE_DEC, VALS(logotypecertextn_LogotypeInfo_vals), 0,
"LogotypeInfo", HFILL }},
{ &hf_logotypecertextn_refStructHash,
{ "refStructHash", "logotypecertextn.refStructHash",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_HashAlgAndValue", HFILL }},
{ &hf_logotypecertextn_refStructHash_item,
{ "HashAlgAndValue", "logotypecertextn.HashAlgAndValue",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_logotypecertextn_refStructURI,
{ "refStructURI", "logotypecertextn.refStructURI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_logotypecertextn_refStructURI_item,
{ "refStructURI item", "logotypecertextn.refStructURI_item",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_logotypecertextn_hashAlg,
{ "hashAlg", "logotypecertextn.hashAlg",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_logotypecertextn_hashValue,
{ "hashValue", "logotypecertextn.hashValue",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
#line 56 "../../asn1/logotypecertextn/packet-logotypecertextn-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/logotypecertextn/packet-logotypecertextn-ettarr.c"
&ett_logotypecertextn_LogotypeExtn,
&ett_logotypecertextn_SEQUENCE_OF_LogotypeInfo,
&ett_logotypecertextn_SEQUENCE_OF_OtherLogotypeInfo,
&ett_logotypecertextn_LogotypeInfo,
&ett_logotypecertextn_LogotypeData,
&ett_logotypecertextn_SEQUENCE_OF_LogotypeImage,
&ett_logotypecertextn_SEQUENCE_OF_LogotypeAudio,
&ett_logotypecertextn_LogotypeImage,
&ett_logotypecertextn_LogotypeAudio,
&ett_logotypecertextn_LogotypeDetails,
&ett_logotypecertextn_SEQUENCE_SIZE_1_MAX_OF_HashAlgAndValue,
&ett_logotypecertextn_T_logotypeURI,
&ett_logotypecertextn_LogotypeImageInfo,
&ett_logotypecertextn_LogotypeImageResolution,
&ett_logotypecertextn_LogotypeAudioInfo,
&ett_logotypecertextn_OtherLogotypeInfo,
&ett_logotypecertextn_LogotypeReference,
&ett_logotypecertextn_T_refStructURI,
&ett_logotypecertextn_HashAlgAndValue,
#line 61 "../../asn1/logotypecertextn/packet-logotypecertextn-template.c"
};
proto_logotypecertextn = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_logotypecertextn, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_logotypecertextn(void) {
#line 1 "../../asn1/logotypecertextn/packet-logotypecertextn-dis-tab.c"
register_ber_oid_dissector("1.3.6.1.5.5.7.1.12", dissect_LogotypeExtn_PDU, proto_logotypecertextn, "id-pe-logotype");
register_ber_oid_dissector("1.3.6.1.5.5.7.20.1", dissect_LogotypeExtn_PDU, proto_logotypecertextn, "id-pe-logo-loyalty");
register_ber_oid_dissector("1.3.6.1.5.5.7.20.2", dissect_LogotypeExtn_PDU, proto_logotypecertextn, "id-pe-logo-background");
#line 76 "../../asn1/logotypecertextn/packet-logotypecertextn-template.c"
}
