static int
dissect_atn_ulcs_Transfer_syntax_name(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_atn_ulcs_Presentation_context_identifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(
tvb,
offset,
actx,
tree,
hf_index,
1U,
127U,
&ulcs_context_value,
TRUE);
return offset;
}
static int
dissect_atn_ulcs_T_pdv_list_presentation_data_values_single_asn1_type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_atn_ulcs_OCTET_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_atn_ulcs_T_pdv_list_presentation_data_values_arbitrary(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
packet_info * pinfo = actx->pinfo;
tvbuff_t *tvb_usr = NULL;
proto_item *ti = NULL;
proto_tree *atn_ulcs_tree = NULL;
atn_conversation_t *atn_cv = NULL;
heur_dtbl_entry_t *hdtbl_entry;
offset = dissect_per_bit_string(
tvb,
offset,
actx,
tree,
hf_index,
NO_BOUND,
NO_BOUND,
FALSE,
&tvb_usr,
NULL);
if (tvb_usr) {
switch(ulcs_context_value){
case 1:
ti = proto_tree_add_text(
root_tree,
tvb,
offset,
0,
ATN_ACSE_PROTO );
atn_ulcs_tree = proto_item_add_subtree(ti, ett_atn_acse);
dissect_ACSE_apdu_PDU(
tvb_new_subset_remaining(tvb_usr, 0),
pinfo,
atn_ulcs_tree);
break;
case 3:
atn_cv = find_atn_conversation(
&pinfo->dst,
pinfo->clnp_dstref,
&pinfo->src);
if(atn_cv) {
switch(atn_cv->ae_qualifier){
case cma:
call_dissector_with_data(
atn_cm_handle,
tvb_new_subset_remaining(tvb_usr, 0),
pinfo,
root_tree,
NULL);
break;
case cpdlc:
case pmcpdlc:
call_dissector_with_data(
atn_cpdlc_handle,
tvb_new_subset_remaining(tvb_usr, 0),
pinfo,
root_tree,
NULL);
break;
default:
dissector_try_heuristic(
atn_ulcs_heur_subdissector_list,
tvb_new_subset_remaining(tvb_usr,0),
actx->pinfo,
root_tree,
&hdtbl_entry,
NULL);
break;
}
}
else{
dissector_try_heuristic(
atn_ulcs_heur_subdissector_list,
tvb_new_subset_remaining(tvb_usr,0),
actx->pinfo,
root_tree,
&hdtbl_entry,
NULL);
}
break;
default:
break;
}
}
return offset;
}
static int
dissect_atn_ulcs_T_presentation_data_values(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_T_presentation_data_values, T_presentation_data_values_choice,
NULL);
return offset;
}
static int
dissect_atn_ulcs_PDV_list(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_PDV_list, PDV_list_sequence);
return offset;
}
static int
dissect_atn_ulcs_Fully_encoded_data(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_Fully_encoded_data, Fully_encoded_data_sequence_of,
1, 1, TRUE);
return offset;
}
static int
dissect_atn_ulcs_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_atn_ulcs_INTEGER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_integer(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_atn_ulcs_T_data_value_descriptor(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(
tvb,
offset,
actx,
tree,
hf_index,
-1,
-1,
FALSE,
&actx->external.data_value_descriptor);
actx->external.data_value_descr_present = TRUE;
return offset;
}
static int
dissect_atn_ulcs_T_externalt_encoding_single_asn1_type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_atn_ulcs_T_externalt_encoding_octet_aligned(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_atn_ulcs_T_externalt_encoding_arbitrary(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *tvb_usr = NULL;
packet_info * pinfo = actx->pinfo;
atn_conversation_t *atn_cv = NULL;
heur_dtbl_entry_t *hdtbl_entry;
offset = dissect_per_bit_string(
tvb,
offset,
actx,
tree, hf_index,
NO_BOUND,
NO_BOUND,
FALSE,
&tvb_usr,
NULL);
if (tvb_usr) {
if((pinfo->clnp_dstref) && (!pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(
&pinfo->dst,
pinfo->clnp_dstref,
&pinfo->src);
}
if((pinfo->clnp_srcref) && (!pinfo->clnp_dstref)){
atn_cv = find_atn_conversation(
&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst);
}
if((pinfo->clnp_srcref) && (pinfo->clnp_dstref)){
atn_cv = find_atn_conversation(
&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst);
}
if(atn_cv) {
switch(atn_cv->ae_qualifier){
case cma:
call_dissector_with_data(
atn_cm_handle,
tvb_new_subset_remaining(tvb_usr, 0),
pinfo,
root_tree,
NULL);
break;
case cpdlc:
case pmcpdlc:
call_dissector_with_data(
atn_cpdlc_handle,
tvb_new_subset_remaining(tvb_usr, 0),
pinfo,
root_tree,
NULL);
break;
default:
dissector_try_heuristic(
atn_ulcs_heur_subdissector_list,
tvb_new_subset_remaining(tvb_usr,0),
actx->pinfo,
root_tree,
&hdtbl_entry,
NULL);
break;
}
}else {
dissector_try_heuristic(
atn_ulcs_heur_subdissector_list,
tvb_new_subset_remaining(tvb_usr,0),
actx->pinfo,
root_tree,
&hdtbl_entry,
NULL);
}
}
offset += tvb_reported_length_remaining(tvb, offset);
return offset;
}
static int
dissect_atn_ulcs_T_encoding(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_T_encoding, T_encoding_choice,
NULL);
return offset;
}
static int
dissect_atn_ulcs_EXTERNALt(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_EXTERNALt, EXTERNALt_sequence);
return offset;
}
static int
dissect_atn_ulcs_T_aarq_apdu_protocol_version(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL, NULL);
return offset;
}
static int
dissect_atn_ulcs_Application_context_name(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_atn_ulcs_AP_title_form2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_atn_ulcs_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_atn_ulcs_AttributeTypeAndValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_AttributeTypeAndValue, AttributeTypeAndValue_sequence);
return offset;
}
static int
dissect_atn_ulcs_RelativeDistinguishedName(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_RelativeDistinguishedName, RelativeDistinguishedName_set_of,
1, NO_BOUND, FALSE);
return offset;
}
static int
dissect_atn_ulcs_RDNSequence(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_RDNSequence, RDNSequence_sequence_of);
return offset;
}
static int
dissect_atn_ulcs_Name(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_Name, Name_choice,
NULL);
return offset;
}
static int
dissect_atn_ulcs_AP_title_form1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_atn_ulcs_Name(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_atn_ulcs_AP_title(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_AP_title, AP_title_choice,
NULL);
return offset;
}
static int
dissect_atn_ulcs_AE_qualifier_form2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
packet_info * pinfo = actx->pinfo;
atn_conversation_t *atn_cv = NULL;
guint32 ae_qualifier = 0;
offset = dissect_per_integer(
tvb,
offset,
actx,
tree,
hf_index,
&ae_qualifier);
if((pinfo->clnp_dstref) && (!pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(&pinfo->dst,
pinfo->clnp_dstref,
&pinfo->src );
}
if((!pinfo->clnp_dstref) && (pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst );
}
if(atn_cv){
atn_cv->ae_qualifier = ae_qualifier;
}
return offset;
}
static int
dissect_atn_ulcs_AE_qualifier_form1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_atn_ulcs_RelativeDistinguishedName(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_atn_ulcs_AE_qualifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_AE_qualifier, AE_qualifier_choice,
NULL);
return offset;
}
static int
dissect_atn_ulcs_AP_invocation_identifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_integer(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_atn_ulcs_AE_invocation_identifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_integer(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_atn_ulcs_ACSE_requirements(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL, NULL);
return offset;
}
static int
dissect_atn_ulcs_Mechanism_name(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(
tvb,
offset,
actx,
tree,
hf_index,
NULL);
offset = dissect_per_object_identifier(
tvb,
offset,
actx,
tree,
hf_index,
NULL);
return offset;
}
static int
dissect_atn_ulcs_BIT_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL, NULL);
return offset;
}
static int
dissect_atn_ulcs_EXTERNAL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_external_type(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_atn_ulcs_T_other_mechanism_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset=call_ber_oid_callback(
object_identifier_id,
tvb,
offset,
actx->pinfo,
tree, NULL);
offset=call_ber_oid_callback(
object_identifier_id,
tvb,
offset,
actx->pinfo,
tree, NULL);
return offset;
}
static int
dissect_atn_ulcs_T_other(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_T_other, T_other_sequence);
return offset;
}
static int
dissect_atn_ulcs_Authentication_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_Authentication_value, Authentication_value_choice,
NULL);
return offset;
}
static int
dissect_atn_ulcs_Application_context_name_list(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_Application_context_name_list, Application_context_name_list_sequence_of);
return offset;
}
static int
dissect_atn_ulcs_Implementation_data(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_atn_ulcs_Association_information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_Association_information, Association_information_sequence_of,
1, 1, TRUE);
return offset;
}
static int
dissect_atn_ulcs_AARQ_apdu(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
packet_info * pinfo = actx->pinfo;
aarq_data_t *aarq_data = NULL;
atn_conversation_t *atn_cv = NULL;
guint32 aircraft_24_bit_address = 0;
if((pinfo->clnp_dstref) && (!pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(
&pinfo->dst,
pinfo->clnp_dstref,
&pinfo->src );
if(!atn_cv){
atn_cv = wmem_new(wmem_file_scope(), atn_conversation_t);
atn_cv->ae_qualifier = unknown;
create_atn_conversation(&pinfo->dst,
pinfo->clnp_dstref,
&pinfo->src ,
atn_cv);
}
}
if((!pinfo->clnp_dstref) && (pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst );
if(!atn_cv){
atn_cv = wmem_new(wmem_file_scope(), atn_conversation_t);
atn_cv->ae_qualifier = unknown;
create_atn_conversation(&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst ,
atn_cv);
}
}
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_AARQ_apdu, AARQ_apdu_sequence);
aircraft_24_bit_address =
get_aircraft_24_bit_address_from_nsap(pinfo);
aarq_data = (aarq_data_t *) wmem_tree_lookup32(
aarq_data_tree,
aircraft_24_bit_address);
if(!aarq_data){
aarq_data = wmem_new(wmem_file_scope(), aarq_data_t);
aarq_data-> aarq_pending = FALSE;
wmem_tree_insert32(aarq_data_tree ,aircraft_24_bit_address,(void*)aarq_data);
}
if (aarq_data-> aarq_pending == FALSE ) {
memset(aarq_data,0,sizeof(aarq_data_t));
aarq_data->cv = atn_cv;
aarq_data-> aarq_pending = TRUE;
}
return offset;
}
static int
dissect_atn_ulcs_T_aare_apdu_protocol_version(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL, NULL);
return offset;
}
static int
dissect_atn_ulcs_Associate_result(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2U, NULL, TRUE);
return offset;
}
static int
dissect_atn_ulcs_T_acse_service_user(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 14U, NULL, TRUE);
return offset;
}
static int
dissect_atn_ulcs_T_acse_service_provider(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2U, NULL, TRUE);
return offset;
}
static int
dissect_atn_ulcs_Associate_source_diagnostic(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_Associate_source_diagnostic, Associate_source_diagnostic_choice,
NULL);
return offset;
}
static int
dissect_atn_ulcs_AARE_apdu(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
packet_info * pinfo = actx->pinfo;
guint32 aircraft_24_bit_address = 0 ;
atn_conversation_t *atn_cv = NULL;
aarq_data_t *aarq_data = NULL;
aircraft_24_bit_address = get_aircraft_24_bit_address_from_nsap(pinfo);
aarq_data = (aarq_data_t *) wmem_tree_lookup32(
aarq_data_tree,
aircraft_24_bit_address);
if(!aarq_data) {
return offset;
}
if((pinfo->clnp_dstref) && (!pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(&pinfo->dst,
pinfo->clnp_dstref,
&pinfo->src );
if(!atn_cv){
create_atn_conversation(&pinfo->dst,
pinfo->clnp_dstref,
&pinfo->src ,
aarq_data->cv);
}
}
if((pinfo->clnp_dstref) && (pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(
&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst);
if(atn_cv){
create_atn_conversation(&pinfo->dst,
pinfo->clnp_dstref,
&pinfo->src ,
aarq_data->cv);
}else {
create_atn_conversation(&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst ,
aarq_data->cv);
create_atn_conversation(&pinfo->dst,
pinfo->clnp_dstref,
&pinfo->src ,
aarq_data->cv);
}
}
memset(aarq_data,0,sizeof(aarq_data_t));
aarq_data-> aarq_pending = FALSE;
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_AARE_apdu, AARE_apdu_sequence);
return offset;
}
static int
dissect_atn_ulcs_Release_request_reason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 30U, NULL, TRUE);
return offset;
}
static int
dissect_atn_ulcs_RLRQ_apdu(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_RLRQ_apdu, RLRQ_apdu_sequence);
return offset;
}
static int
dissect_atn_ulcs_Release_response_reason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(
tvb,
offset,
actx,
tree,
hf_index,
0U,
30U,
NULL,
TRUE);
return offset;
}
static int
dissect_atn_ulcs_RLRE_apdu(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_RLRE_apdu, RLRE_apdu_sequence);
return offset;
}
static int
dissect_atn_ulcs_ABRT_source(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1U, NULL, TRUE);
return offset;
}
static int
dissect_atn_ulcs_ABRT_diagnostic(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, ABRT_diagnostic_value_map);
return offset;
}
static int
dissect_atn_ulcs_ABRT_apdu(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_ABRT_apdu, ABRT_apdu_sequence);
return offset;
}
static int
dissect_atn_ulcs_ACSE_apdu(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_ulcs_ACSE_apdu, ACSE_apdu_choice,
NULL);
return offset;
}
static void dissect_Fully_encoded_data_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_atn_ulcs_Fully_encoded_data(tvb, 0, &asn1_ctx, tree, hf_atn_ulcs_Fully_encoded_data_PDU);
}
static void dissect_ACSE_apdu_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_atn_ulcs_ACSE_apdu(tvb, 0, &asn1_ctx, tree, hf_atn_ulcs_ACSE_apdu_PDU);
}
guint32 get_aircraft_24_bit_address_from_nsap(
packet_info *pinfo)
{
const guint8* addr = NULL;
guint32 ars =0;
guint32 adr_prefix =0;
if( (pinfo->src.type != AT_OSI) ||
(pinfo->dst.type != AT_OSI)) {
return ars; }
if( (pinfo->src.len != 20) ||
(pinfo->dst.len != 20)) {
return ars; }
addr = (const guint8 *)pinfo->src.data;
adr_prefix =
((addr[0]<<24) |
(addr[1]<<16) |
(addr[2]<<8) |
addr[3] );
if((adr_prefix == 0x470027c1) ||
(adr_prefix == 0x47002741)) {
ars = ((addr[8])<<16) |
((addr[9])<<8) |
(addr[10]);
}
addr = (const guint8 *)pinfo->dst.data;
adr_prefix = ((addr[0]<<24) |
(addr[1]<<16) |
(addr[2]<<8) |
addr[3] );
if((adr_prefix == 0x470027c1) ||
(adr_prefix == 0x47002741)) {
ars = ((addr[8])<<16) |
((addr[9])<<8) |
(addr[10]);
}
return ars;
}
int check_heur_msg_type(packet_info *pinfo _U_)
{
int t = no_msg;
const guint8* addr = NULL;
guint32 adr_prefix =0;
if( (pinfo->src.type != AT_OSI) || (pinfo->dst.type != AT_OSI)) {
return t; }
if( (pinfo->src.len != 20) || (pinfo->dst.len != 20)) {
return t; }
addr = (const guint8 *)pinfo->src.data;
adr_prefix = ((addr[0]<<24) | (addr[1]<<16) | (addr[2]<<8) | addr[3] );
if((adr_prefix == 0x470027c1) || (adr_prefix == 0x47002741)) {
t = dm;
}
addr = (const guint8 *)pinfo->dst.data;
adr_prefix = ((addr[0]<<24) | (addr[1]<<16) | (addr[2]<<8) | addr[3] );
if((adr_prefix == 0x470027c1) || (adr_prefix == 0x47002741)) {
t = um;
}
return t;
}
wmem_tree_t *get_atn_conversation_tree(void){
return atn_conversation_tree;
}
atn_conversation_t * find_atn_conversation(
address *address1,
guint16 clnp_ref1,
address *address2 )
{
atn_conversation_t *cv = NULL;
guint32 key = 0;
guint32 tmp = 0;
ADD_ADDRESS_TO_HASH( tmp, address1);
key = (tmp << 16) | clnp_ref1 ;
ADD_ADDRESS_TO_HASH( tmp, address2);
key = (tmp << 24) | key ;
cv = (atn_conversation_t *)
wmem_tree_lookup32(get_atn_conversation_tree(),key);
return cv;
}
atn_conversation_t * create_atn_conversation(
address *address1,
guint16 clnp_ref1,
address *address2,
atn_conversation_t *conversation)
{
atn_conversation_t *cv = NULL;
guint32 key = 0;
guint32 tmp = 0;
ADD_ADDRESS_TO_HASH( tmp, address1);
key = (tmp << 16) | clnp_ref1 ;
ADD_ADDRESS_TO_HASH( tmp, address2);
key = (tmp << 24) | key ;
cv = (atn_conversation_t *)
wmem_tree_lookup32(
get_atn_conversation_tree(),
key);
if(cv) {
return NULL; }
wmem_tree_insert32(
get_atn_conversation_tree(),
key,
(void*)conversation);
return conversation;
}
static int
dissect_atn_ulcs(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
int offset = 0;
proto_item *ti = NULL;
proto_tree *atn_ulcs_tree = NULL;
guint8 value_pres = 0;
guint8 value_ses = 0;
guint16 value_ses_pres = 0;
root_tree = tree;
if ( (int)(intptr_t) data == FALSE )
{
ti = proto_tree_add_item(
tree,
proto_atn_ulcs,
tvb,
0,
0 ,
ENC_NA);
atn_ulcs_tree = proto_item_add_subtree(
ti,
ett_atn_ulcs);
dissect_Fully_encoded_data_PDU(
tvb,
pinfo,
atn_ulcs_tree);
return offset +
tvb_reported_length_remaining(tvb, offset ) ;
}
if ( (int)(intptr_t) data == TRUE )
{
value_ses_pres = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_text(
tree,
tvb,
offset,
0,
ATN_SES_PROTO );
atn_ulcs_tree = proto_item_add_subtree(
ti,
ett_atn_ses);
value_ses = tvb_get_guint8(tvb, offset);
proto_tree_add_item(atn_ulcs_tree,
hf_atn_ses_type,
tvb,
offset,
1,
ENC_BIG_ENDIAN );
switch(value_ses & SES_PDU_TYPE_MASK){
case SES_ATN_SRF:
case SES_ATN_SRFC:
proto_tree_add_item(atn_ulcs_tree,
hf_atn_ses_param_ind,
tvb,
offset,
1,
ENC_BIG_ENDIAN );
proto_tree_add_item(atn_ulcs_tree,
hf_atn_ses_param_b2,
tvb,
offset,
1,
ENC_BIG_ENDIAN );
proto_tree_add_item(atn_ulcs_tree,
hf_atn_ses_param_b1,
tvb,
offset,
1,
ENC_BIG_ENDIAN );
break;
default:
break;
}
offset++;
ti = proto_tree_add_text(
tree,
tvb,
offset,
0,
ATN_PRES_PROTO );
atn_ulcs_tree = proto_item_add_subtree(ti, ett_atn_pres);
value_pres = tvb_get_guint8(tvb, offset);
proto_tree_add_text(atn_ulcs_tree,
tvb,
offset,
1,
"%s (0x%02x)",
val_to_str( value_ses_pres & ATN_SES_PRES_MASK , atn_pres_vals, "?"),
value_pres);
switch(value_ses & SES_PDU_TYPE_MASK){
case SES_ATN_SRF:
case SES_ATN_SRFC:
proto_tree_add_item(
atn_ulcs_tree,
hf_atn_pres_err,
tvb,
offset,
1,
ENC_BIG_ENDIAN );
break;
default:
break;
}
offset++;
ti = proto_tree_add_text(
tree,
tvb,
offset,
0,
ATN_ACSE_PROTO );
atn_ulcs_tree = proto_item_add_subtree(
ti,
ett_atn_acse);
dissect_ACSE_apdu_PDU(
tvb_new_subset_remaining(tvb, offset),
pinfo,
atn_ulcs_tree);
return offset +
tvb_reported_length_remaining(tvb, offset );
}
return offset;
}
static gboolean dissect_atn_ulcs_heur(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
if (tvb_captured_length(tvb) < 2){
return FALSE; }
switch( tvb_get_ntohs(tvb, 0) & 0xf8ff ){
case 0xe802:
case 0xf802:
case 0xf002:
case 0xd802:
case 0xe002:
case 0xe012:
case 0xe022:
case 0xe032:
case 0xe042:
case 0xe052:
case 0xe062:
case 0xe072:
case 0xa002:
case 0xa012:
case 0xa022:
case 0xa032:
case 0xa042:
case 0xa052:
case 0xa062:
case 0xa072:
dissect_atn_ulcs(
tvb,
pinfo,
tree,
(void*) TRUE);
return TRUE;
default:
break;
}
switch( tvb_get_ntohs(tvb, 0) & 0xfff0 ){
case 0x0020:
case 0x00a0:
dissect_atn_ulcs(tvb, pinfo, tree, (void*) FALSE);
return TRUE;
break;
default:
break;
}
return FALSE;
}
void proto_register_atn_ulcs (void)
{
static hf_register_info hf_atn_ulcs[] = {
#line 1 "../../asn1/atn-ulcs/packet-atn-ulcs-hfarr.c"
{ &hf_atn_ulcs_Fully_encoded_data_PDU,
{ "Fully-encoded-data", "atn-ulcs.Fully_encoded_data",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_ACSE_apdu_PDU,
{ "ACSE-apdu", "atn-ulcs.ACSE_apdu",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_ACSE_apdu_vals), 0,
NULL, HFILL }},
{ &hf_atn_ulcs_Fully_encoded_data_item,
{ "PDV-list", "atn-ulcs.PDV_list_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_transfer_syntax_name,
{ "transfer-syntax-name", "atn-ulcs.transfer_syntax_name",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_presentation_context_identifier,
{ "presentation-context-identifier", "atn-ulcs.presentation_context_identifier",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_Presentation_context_identifier_vals), 0,
NULL, HFILL }},
{ &hf_atn_ulcs_presentation_data_values,
{ "presentation-data-values", "atn-ulcs.presentation_data_values",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_T_presentation_data_values_vals), 0,
NULL, HFILL }},
{ &hf_atn_ulcs_pdv_list_presentation_data_values_single_asn1_type,
{ "single-ASN1-type", "atn-ulcs.single_ASN1_type_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_pdv_list_presentation_data_values_single_asn1_type", HFILL }},
{ &hf_atn_ulcs_octet_aligned,
{ "octet-aligned", "atn-ulcs.octet_aligned",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_atn_ulcs_pdv_list_presentation_data_values_arbitrary,
{ "arbitrary", "atn-ulcs.arbitrary",
FT_BYTES, BASE_NONE, NULL, 0,
"T_pdv_list_presentation_data_values_arbitrary", HFILL }},
{ &hf_atn_ulcs_direct_reference,
{ "direct-reference", "atn-ulcs.direct_reference",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_atn_ulcs_indirect_reference,
{ "indirect-reference", "atn-ulcs.indirect_reference",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_atn_ulcs_data_value_descriptor,
{ "data-value-descriptor", "atn-ulcs.data_value_descriptor",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_encoding,
{ "encoding", "atn-ulcs.encoding",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_T_encoding_vals), 0,
NULL, HFILL }},
{ &hf_atn_ulcs_externalt_encoding_single_asn1_type,
{ "single-ASN1-type", "atn-ulcs.single_ASN1_type_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_externalt_encoding_single_asn1_type", HFILL }},
{ &hf_atn_ulcs_externalt_encoding_octet_aligned,
{ "octet-aligned", "atn-ulcs.octet_aligned",
FT_BYTES, BASE_NONE, NULL, 0,
"T_externalt_encoding_octet_aligned", HFILL }},
{ &hf_atn_ulcs_externalt_encoding_arbitrary,
{ "arbitrary", "atn-ulcs.arbitrary",
FT_BYTES, BASE_NONE, NULL, 0,
"T_externalt_encoding_arbitrary", HFILL }},
{ &hf_atn_ulcs_aarq,
{ "aarq", "atn-ulcs.aarq_element",
FT_NONE, BASE_NONE, NULL, 0,
"AARQ_apdu", HFILL }},
{ &hf_atn_ulcs_aare,
{ "aare", "atn-ulcs.aare_element",
FT_NONE, BASE_NONE, NULL, 0,
"AARE_apdu", HFILL }},
{ &hf_atn_ulcs_rlrq,
{ "rlrq", "atn-ulcs.rlrq_element",
FT_NONE, BASE_NONE, NULL, 0,
"RLRQ_apdu", HFILL }},
{ &hf_atn_ulcs_rlre,
{ "rlre", "atn-ulcs.rlre_element",
FT_NONE, BASE_NONE, NULL, 0,
"RLRE_apdu", HFILL }},
{ &hf_atn_ulcs_abrt,
{ "abrt", "atn-ulcs.abrt_element",
FT_NONE, BASE_NONE, NULL, 0,
"ABRT_apdu", HFILL }},
{ &hf_atn_ulcs_aarq_apdu_protocol_version,
{ "protocol-version", "atn-ulcs.protocol_version",
FT_BYTES, BASE_NONE, NULL, 0,
"T_aarq_apdu_protocol_version", HFILL }},
{ &hf_atn_ulcs_application_context_name,
{ "application-context-name", "atn-ulcs.application_context_name",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_called_AP_title,
{ "called-AP-title", "atn-ulcs.called_AP_title",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_AP_title_vals), 0,
"AP_title", HFILL }},
{ &hf_atn_ulcs_called_AE_qualifier,
{ "called-AE-qualifier", "atn-ulcs.called_AE_qualifier",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_AE_qualifier_vals), 0,
"AE_qualifier", HFILL }},
{ &hf_atn_ulcs_called_AP_invocation_identifier,
{ "called-AP-invocation-identifier", "atn-ulcs.called_AP_invocation_identifier",
FT_INT32, BASE_DEC, NULL, 0,
"AP_invocation_identifier", HFILL }},
{ &hf_atn_ulcs_called_AE_invocation_identifier,
{ "called-AE-invocation-identifier", "atn-ulcs.called_AE_invocation_identifier",
FT_INT32, BASE_DEC, NULL, 0,
"AE_invocation_identifier", HFILL }},
{ &hf_atn_ulcs_calling_AP_title,
{ "calling-AP-title", "atn-ulcs.calling_AP_title",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_AP_title_vals), 0,
"AP_title", HFILL }},
{ &hf_atn_ulcs_calling_AE_qualifier,
{ "calling-AE-qualifier", "atn-ulcs.calling_AE_qualifier",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_AE_qualifier_vals), 0,
"AE_qualifier", HFILL }},
{ &hf_atn_ulcs_calling_AP_invocation_identifier,
{ "calling-AP-invocation-identifier", "atn-ulcs.calling_AP_invocation_identifier",
FT_INT32, BASE_DEC, NULL, 0,
"AP_invocation_identifier", HFILL }},
{ &hf_atn_ulcs_calling_AE_invocation_identifier,
{ "calling-AE-invocation-identifier", "atn-ulcs.calling_AE_invocation_identifier",
FT_INT32, BASE_DEC, NULL, 0,
"AE_invocation_identifier", HFILL }},
{ &hf_atn_ulcs_sender_acse_requirements,
{ "sender-acse-requirements", "atn-ulcs.sender_acse_requirements",
FT_BYTES, BASE_NONE, NULL, 0,
"ACSE_requirements", HFILL }},
{ &hf_atn_ulcs_mechanism_name,
{ "mechanism-name", "atn-ulcs.mechanism_name",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_calling_authentication_value,
{ "calling-authentication-value", "atn-ulcs.calling_authentication_value",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_Authentication_value_vals), 0,
"Authentication_value", HFILL }},
{ &hf_atn_ulcs_application_context_name_list,
{ "application-context-name-list", "atn-ulcs.application_context_name_list",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_implementation_information,
{ "implementation-information", "atn-ulcs.implementation_information",
FT_BYTES, BASE_NONE, NULL, 0,
"Implementation_data", HFILL }},
{ &hf_atn_ulcs_user_information,
{ "user-information", "atn-ulcs.user_information",
FT_UINT32, BASE_DEC, NULL, 0,
"Association_information", HFILL }},
{ &hf_atn_ulcs_aare_apdu_protocol_version,
{ "protocol-version", "atn-ulcs.protocol_version",
FT_BYTES, BASE_NONE, NULL, 0,
"T_aare_apdu_protocol_version", HFILL }},
{ &hf_atn_ulcs_result,
{ "result", "atn-ulcs.result",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_Associate_result_vals), 0,
"Associate_result", HFILL }},
{ &hf_atn_ulcs_result_source_diagnostic,
{ "result-source-diagnostic", "atn-ulcs.result_source_diagnostic",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_Associate_source_diagnostic_vals), 0,
"Associate_source_diagnostic", HFILL }},
{ &hf_atn_ulcs_responding_AP_title,
{ "responding-AP-title", "atn-ulcs.responding_AP_title",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_AP_title_vals), 0,
"AP_title", HFILL }},
{ &hf_atn_ulcs_responding_AE_qualifier,
{ "responding-AE-qualifier", "atn-ulcs.responding_AE_qualifier",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_AE_qualifier_vals), 0,
"AE_qualifier", HFILL }},
{ &hf_atn_ulcs_responding_AP_invocation_identifier,
{ "responding-AP-invocation-identifier", "atn-ulcs.responding_AP_invocation_identifier",
FT_INT32, BASE_DEC, NULL, 0,
"AP_invocation_identifier", HFILL }},
{ &hf_atn_ulcs_responding_AE_invocation_identifier,
{ "responding-AE-invocation-identifier", "atn-ulcs.responding_AE_invocation_identifier",
FT_INT32, BASE_DEC, NULL, 0,
"AE_invocation_identifier", HFILL }},
{ &hf_atn_ulcs_responder_acse_requirements,
{ "responder-acse-requirements", "atn-ulcs.responder_acse_requirements",
FT_BYTES, BASE_NONE, NULL, 0,
"ACSE_requirements", HFILL }},
{ &hf_atn_ulcs_responding_authentication_value,
{ "responding-authentication-value", "atn-ulcs.responding_authentication_value",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_Authentication_value_vals), 0,
"Authentication_value", HFILL }},
{ &hf_atn_ulcs_rlrq_apdu_request_reason,
{ "reason", "atn-ulcs.reason",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_Release_request_reason_vals), 0,
"Release_request_reason", HFILL }},
{ &hf_atn_ulcs_rlre_apdu_response_reason,
{ "reason", "atn-ulcs.reason",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_Release_response_reason_vals), 0,
"Release_response_reason", HFILL }},
{ &hf_atn_ulcs_abort_source,
{ "abort-source", "atn-ulcs.abort_source",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_ABRT_source_vals), 0,
"ABRT_source", HFILL }},
{ &hf_atn_ulcs_abort_diagnostic,
{ "abort-diagnostic", "atn-ulcs.abort_diagnostic",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_ABRT_diagnostic_vals), 0,
"ABRT_diagnostic", HFILL }},
{ &hf_atn_ulcs_Application_context_name_list_item,
{ "Application-context-name", "atn-ulcs.Application_context_name",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_ap_title_form2,
{ "ap-title-form2", "atn-ulcs.ap_title_form2",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_ap_title_form1,
{ "ap-title-form1", "atn-ulcs.ap_title_form1",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_Name_vals), 0,
NULL, HFILL }},
{ &hf_atn_ulcs_ae_qualifier_form2,
{ "ae-qualifier-form2", "atn-ulcs.ae_qualifier_form2",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_ae_qualifier_form1,
{ "ae-qualifier-form1", "atn-ulcs.ae_qualifier_form1",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_acse_service_user,
{ "acse-service-user", "atn-ulcs.acse_service_user",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_T_acse_service_user_vals), 0,
NULL, HFILL }},
{ &hf_atn_ulcs_acse_service_provider,
{ "acse-service-provider", "atn-ulcs.acse_service_provider",
FT_UINT32, BASE_DEC, VALS(atn_ulcs_T_acse_service_provider_vals), 0,
NULL, HFILL }},
{ &hf_atn_ulcs_Association_information_item,
{ "EXTERNALt", "atn-ulcs.EXTERNALt_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_charstring,
{ "charstring", "atn-ulcs.charstring",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_atn_ulcs_bitstring,
{ "bitstring", "atn-ulcs.bitstring",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_atn_ulcs_external,
{ "external", "atn-ulcs.external_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_other,
{ "other", "atn-ulcs.other_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_other_mechanism_name,
{ "other-mechanism-name", "atn-ulcs.other_mechanism_name",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_atn_ulcs_other_mechanism_value,
{ "other-mechanism-value", "atn-ulcs.other_mechanism_value_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_rdnSequence,
{ "rdnSequence", "atn-ulcs.rdnSequence",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_RDNSequence_item,
{ "RelativeDistinguishedName", "atn-ulcs.RelativeDistinguishedName",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_RelativeDistinguishedName_item,
{ "AttributeTypeAndValue", "atn-ulcs.AttributeTypeAndValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_null,
{ "null", "atn-ulcs.null_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_ulcs_T_aarq_apdu_protocol_version_version1,
{ "version1", "atn-ulcs.version1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_atn_ulcs_T_aare_apdu_protocol_version_version1,
{ "version1", "atn-ulcs.version1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_atn_ulcs_ACSE_requirements_authentication,
{ "authentication", "atn-ulcs.authentication",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_atn_ulcs_ACSE_requirements_application_context_negotiation,
{ "application-context-negotiation", "atn-ulcs.application-context-negotiation",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
#line 813 "../../asn1/atn-ulcs/packet-atn-ulcs-template.c"
{&hf_atn_ses_type,
{ "SPDU Type",
"atn-ulcs.ses.type",
FT_UINT8,
BASE_HEX,
VALS(atn_ses_type),
0xf8,
"Indicates presence of session parameters",
HFILL}},
{&hf_atn_ses_param_ind,
{ "SPDU Parameter Indication",
"atn-ulcs.ses.parameter-indication",
FT_UINT8,
BASE_HEX,
VALS(atn_ses_param_ind),
SES_PARAM_IND_MASK,
"Indicates presence of session parameters",
HFILL}},
{&hf_atn_ses_param_b1,
{ "SRF Parameter B1",
"atn-ulcs.ses.srf-b1",
FT_UINT8,
BASE_HEX,
VALS(srf_b1),
0x01,
"Determines if transport connection reject is \
transient or persistent",
HFILL}},
{&hf_atn_ses_param_b2,
{ "SRF Parameter B2",
"atn-ulcs.ses.srf-b2",
FT_UINT8,
BASE_HEX,
VALS(srf_b2),
0x02,
"Determines if transport connection is \
retained or released",
HFILL}},
{ &hf_atn_pres_err,
{ "Error Code", "atn-ulcs.pres.cpr-error",
FT_UINT8,
BASE_HEX,
VALS(atn_pres_err),
PRES_CPR_ER_MASK,
NULL,
HFILL}},
};
static gint *ett[] = {
#line 1 "../../asn1/atn-ulcs/packet-atn-ulcs-ettarr.c"
&ett_atn_ulcs_Fully_encoded_data,
&ett_atn_ulcs_PDV_list,
&ett_atn_ulcs_T_presentation_data_values,
&ett_atn_ulcs_EXTERNALt,
&ett_atn_ulcs_T_encoding,
&ett_atn_ulcs_ACSE_apdu,
&ett_atn_ulcs_AARQ_apdu,
&ett_atn_ulcs_T_aarq_apdu_protocol_version,
&ett_atn_ulcs_AARE_apdu,
&ett_atn_ulcs_T_aare_apdu_protocol_version,
&ett_atn_ulcs_RLRQ_apdu,
&ett_atn_ulcs_RLRE_apdu,
&ett_atn_ulcs_ABRT_apdu,
&ett_atn_ulcs_ACSE_requirements,
&ett_atn_ulcs_Application_context_name_list,
&ett_atn_ulcs_AP_title,
&ett_atn_ulcs_AE_qualifier,
&ett_atn_ulcs_Associate_source_diagnostic,
&ett_atn_ulcs_Association_information,
&ett_atn_ulcs_Authentication_value,
&ett_atn_ulcs_T_other,
&ett_atn_ulcs_Name,
&ett_atn_ulcs_RDNSequence,
&ett_atn_ulcs_RelativeDistinguishedName,
&ett_atn_ulcs_AttributeTypeAndValue,
#line 863 "../../asn1/atn-ulcs/packet-atn-ulcs-template.c"
&ett_atn_ses,
&ett_atn_pres,
&ett_atn_acse,
&ett_atn_ulcs
};
proto_atn_ulcs = proto_register_protocol (
ATN_ULCS_PROTO ,
"ATN-ULCS",
"atn-ulcs");
proto_register_field_array (
proto_atn_ulcs,
hf_atn_ulcs,
array_length(hf_atn_ulcs));
proto_register_subtree_array (
ett,
array_length (ett));
new_register_dissector(
"atn-ulcs",
dissect_atn_ulcs,
proto_atn_ulcs);
atn_cm_handle = find_dissector("atn-cm");
atn_cpdlc_handle = find_dissector("atn-cpdlc");
register_heur_dissector_list(
"atn-ulcs",
&atn_ulcs_heur_subdissector_list);
aarq_data_tree = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
atn_conversation_tree = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
}
void proto_reg_handoff_atn_ulcs(void)
{
heur_dissector_add(
"cotp",
dissect_atn_ulcs_heur,
proto_atn_ulcs);
}
