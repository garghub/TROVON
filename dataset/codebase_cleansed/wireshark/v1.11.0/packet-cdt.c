static int
dissect_cdt_AlgorithmID_ShortForm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 21 "../../asn1/cdt/cdt.cnf"
guint32 value;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&value);
proto_item_append_text (cdt_item, ", %s",
val_to_str (value, cdt_AlgorithmID_ShortForm_vals,
"unknown"));
col_append_fstr (actx->pinfo->cinfo, COL_INFO, "%s ",
val_to_str (value, cdt_AlgorithmID_ShortForm_vals,
"unknown"));
return offset;
}
static int
dissect_cdt_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_cdt_CompressionAlgorithmIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CompressionAlgorithmIdentifier_choice, hf_index, ett_cdt_CompressionAlgorithmIdentifier,
NULL);
return offset;
}
static int
dissect_cdt_ContentType_ShortForm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 36 "../../asn1/cdt/cdt.cnf"
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&content_type);
proto_item_append_text (cdt_item, ", %s",
val_to_str (content_type, cdt_ContentType_ShortForm_vals,
"unknown"));
col_append_fstr (actx->pinfo->cinfo, COL_INFO, "%s ",
val_to_str (content_type, cdt_ContentType_ShortForm_vals,
"unknown"));
return offset;
}
static int
dissect_cdt_T_contentType_OID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 50 "../../asn1/cdt/cdt.cnf"
const char *obj_id = NULL;
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &obj_id);
if (obj_id) {
const char *name = oid_resolved_from_string (obj_id);
if (!name) {
name = obj_id;
}
proto_item_append_text (cdt_item, ", %s", name);
col_append_fstr (actx->pinfo->cinfo, COL_INFO, "%s ", name);
}
return offset;
}
static int
dissect_cdt_T_contentType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_contentType_choice, hf_index, ett_cdt_T_contentType,
NULL);
return offset;
}
static int
dissect_cdt_CompressedContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 69 "../../asn1/cdt/cdt.cnf"
tvbuff_t *next_tvb = NULL, *compr_tvb = NULL;
int save_offset = offset;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&compr_tvb);
if (compr_tvb == NULL) {
proto_tree_add_expert(top_tree, actx->pinfo, &ei_cdt_unable_compress_content,
tvb, save_offset, -1);
col_append_str (actx->pinfo->cinfo, COL_INFO,
"[Error: Unable to get compressed content]");
return offset;
}
next_tvb = tvb_child_uncompress (tvb, compr_tvb, 0, tvb_length (compr_tvb));
if (next_tvb == NULL) {
proto_tree_add_expert(top_tree, actx->pinfo, &ei_cdt_unable_uncompress_content,
tvb, save_offset, -1);
col_append_str (actx->pinfo->cinfo, COL_INFO,
"[Error: Unable to uncompress content]");
return offset;
}
add_new_data_source (actx->pinfo, next_tvb, "Uncompressed Content");
switch (content_type) {
case CDT_UNDEFINED:
call_dissector (data_handle, next_tvb, actx->pinfo, top_tree);
break;
case CDT_EXTERNAL:
dissect_unknown_ber (actx->pinfo, next_tvb, 0, top_tree);
break;
case CDT_P1:
dissect_p1_mts_apdu (next_tvb, actx->pinfo, top_tree);
break;
default:
call_dissector (data_handle, next_tvb, actx->pinfo, top_tree);
break;
}
return offset;
}
static int
dissect_cdt_CompressedContentInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CompressedContentInfo_sequence, hf_index, ett_cdt_CompressedContentInfo);
return offset;
}
int
dissect_cdt_CompressedData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 13 "../../asn1/cdt/cdt.cnf"
content_type = 0;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CompressedData_sequence, hf_index, ett_cdt_CompressedData);
return offset;
}
static void dissect_CompressedData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cdt_CompressedData(FALSE, tvb, 0, &asn1_ctx, tree, hf_cdt_CompressedData_PDU);
}
void dissect_cdt (tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_tree *tree = NULL;
top_tree = parent_tree;
if (parent_tree) {
cdt_item = proto_tree_add_item (parent_tree, proto_cdt, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree (cdt_item, ett_cdt_CompressedData);
}
col_set_str (pinfo->cinfo, COL_PROTOCOL, "CDT");
col_clear (pinfo->cinfo, COL_INFO);
dissect_CompressedData_PDU (tvb, pinfo, tree);
}
void proto_register_cdt (void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/cdt/packet-cdt-hfarr.c"
{ &hf_cdt_CompressedData_PDU,
{ "CompressedData", "cdt.CompressedData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cdt_compressionAlgorithm,
{ "compressionAlgorithm", "cdt.compressionAlgorithm",
FT_UINT32, BASE_DEC, VALS(cdt_CompressionAlgorithmIdentifier_vals), 0,
"CompressionAlgorithmIdentifier", HFILL }},
{ &hf_cdt_compressedContentInfo,
{ "compressedContentInfo", "cdt.compressedContentInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cdt_algorithmID_ShortForm,
{ "algorithmID-ShortForm", "cdt.algorithmID_ShortForm",
FT_INT32, BASE_DEC, VALS(cdt_AlgorithmID_ShortForm_vals), 0,
NULL, HFILL }},
{ &hf_cdt_algorithmID_OID,
{ "algorithmID-OID", "cdt.algorithmID_OID",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_cdt_contentType,
{ "contentType", "cdt.contentType",
FT_UINT32, BASE_DEC, VALS(cdt_T_contentType_vals), 0,
NULL, HFILL }},
{ &hf_cdt_contentType_ShortForm,
{ "contentType-ShortForm", "cdt.contentType_ShortForm",
FT_INT32, BASE_DEC, VALS(cdt_ContentType_ShortForm_vals), 0,
NULL, HFILL }},
{ &hf_cdt_contentType_OID,
{ "contentType-OID", "cdt.contentType_OID",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cdt_compressedContent,
{ "compressedContent", "cdt.compressedContent",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 100 "../../asn1/cdt/packet-cdt-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/cdt/packet-cdt-ettarr.c"
&ett_cdt_CompressedData,
&ett_cdt_CompressionAlgorithmIdentifier,
&ett_cdt_CompressedContentInfo,
&ett_cdt_T_contentType,
#line 105 "../../asn1/cdt/packet-cdt-template.c"
};
static ei_register_info ei[] = {
{ &ei_cdt_unable_compress_content, { "cdt.unable_compress_content", PI_UNDECODED, PI_ERROR, "Unable to get compressed content", EXPFILL }},
{ &ei_cdt_unable_uncompress_content, { "cdt.unable_uncompress_content", PI_UNDECODED, PI_ERROR, "Unable to get uncompressed content", EXPFILL }},
};
expert_module_t* expert_cdt;
proto_cdt = proto_register_protocol (PNAME, PSNAME, PFNAME);
proto_register_field_array (proto_cdt, hf, array_length(hf));
proto_register_subtree_array (ett, array_length(ett));
expert_cdt = expert_register_protocol(proto_cdt);
expert_register_field_array(expert_cdt, ei, array_length(ei));
}
void proto_reg_handoff_cdt (void) {
#line 1 "../../asn1/cdt/packet-cdt-dis-tab.c"
register_ber_oid_dissector("1.3.26.0.4406.0.4.2", dissect_CompressedData_PDU, proto_cdt, "cdt");
#line 128 "../../asn1/cdt/packet-cdt-template.c"
data_handle = find_dissector ("data");
}
