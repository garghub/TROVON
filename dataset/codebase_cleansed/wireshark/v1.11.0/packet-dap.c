int
dissect_dap_FamilyGrouping(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_dap_ServiceControlOptions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
ServiceControlOptions_bits, hf_index, ett_dap_ServiceControlOptions,
NULL);
return offset;
}
static int
dissect_dap_T_priority(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dap_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dap_T_scopeOfReferral(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dap_Name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
const char *dn;
offset = dissect_ber_choice(actx, tree, tvb, offset,
Name_choice, hf_index, ett_dap_Name,
NULL);
dn = x509if_get_last_dn();
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", (dn && *dn) ? dn : "(root)");
return offset;
}
static int
dissect_dap_T_manageDSAITPlaneRef(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_manageDSAITPlaneRef_sequence, hf_index, ett_dap_T_manageDSAITPlaneRef);
return offset;
}
static int
dissect_dap_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_dap_ServiceControls(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ServiceControls_set, hf_index, ett_dap_ServiceControls);
return offset;
}
static int
dissect_dap_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_dap_SET_OF_AttributeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_AttributeType_set_of, hf_index, ett_dap_SET_OF_AttributeType);
return offset;
}
static int
dissect_dap_T_attributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_attributes_choice, hf_index, ett_dap_T_attributes,
NULL);
return offset;
}
static int
dissect_dap_T_infoTypes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dap_SET_SIZE_1_MAX_OF_AttributeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_SIZE_1_MAX_OF_AttributeType_set_of, hf_index, ett_dap_SET_SIZE_1_MAX_OF_AttributeType);
return offset;
}
static int
dissect_dap_T_extraAttributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_extraAttributes_choice, hf_index, ett_dap_T_extraAttributes,
NULL);
return offset;
}
static int
dissect_dap_SEQUENCE_OF_ContextAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ContextAssertion_sequence_of, hf_index, ett_dap_SEQUENCE_OF_ContextAssertion);
return offset;
}
static int
dissect_dap_SET_OF_ContextAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_ContextAssertion_set_of, hf_index, ett_dap_SET_OF_ContextAssertion);
return offset;
}
static int
dissect_dap_T_contextAssertions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_contextAssertions_choice, hf_index, ett_dap_T_contextAssertions,
NULL);
return offset;
}
static int
dissect_dap_TypeAndContextAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TypeAndContextAssertion_sequence, hf_index, ett_dap_TypeAndContextAssertion);
return offset;
}
static int
dissect_dap_SET_SIZE_1_MAX_OF_TypeAndContextAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_SIZE_1_MAX_OF_TypeAndContextAssertion_set_of, hf_index, ett_dap_SET_SIZE_1_MAX_OF_TypeAndContextAssertion);
return offset;
}
int
dissect_dap_ContextSelection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ContextSelection_choice, hf_index, ett_dap_ContextSelection,
NULL);
return offset;
}
static int
dissect_dap_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_dap_T_memberSelect(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dap_T_familySelect(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_familySelect_sequence_of, hf_index, ett_dap_T_familySelect);
return offset;
}
int
dissect_dap_FamilyReturn(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FamilyReturn_sequence, hf_index, ett_dap_FamilyReturn);
return offset;
}
static int
dissect_dap_EntryInformationSelection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
EntryInformationSelection_set, hf_index, ett_dap_EntryInformationSelection);
return offset;
}
static int
dissect_dap_EntryInformationItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
EntryInformationItem_choice, hf_index, ett_dap_EntryInformationItem,
NULL);
return offset;
}
static int
dissect_dap_T_entry_information(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_entry_information_set_of, hf_index, ett_dap_T_entry_information);
return offset;
}
static int
dissect_dap_EntryInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EntryInformation_sequence, hf_index, ett_dap_EntryInformation);
return offset;
}
static int
dissect_dap_T_family_information_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_family_information_item_choice, hf_index, ett_dap_T_family_information_item,
NULL);
return offset;
}
static int
dissect_dap_FamilyInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
FamilyInformation_sequence_of, hf_index, ett_dap_FamilyInformation);
return offset;
}
static int
dissect_dap_SEQUENCE_SIZE_1_MAX_OF_FamilyEntries(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_FamilyEntries_sequence_of, hf_index, ett_dap_SEQUENCE_SIZE_1_MAX_OF_FamilyEntries);
return offset;
}
static int
dissect_dap_FamilyEntry(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FamilyEntry_sequence, hf_index, ett_dap_FamilyEntry);
return offset;
}
static int
dissect_dap_SEQUENCE_OF_FamilyEntry(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_FamilyEntry_sequence_of, hf_index, ett_dap_SEQUENCE_OF_FamilyEntry);
return offset;
}
static int
dissect_dap_FamilyEntries(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FamilyEntries_sequence, hf_index, ett_dap_FamilyEntries);
return offset;
}
static int
dissect_dap_T_initial(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
proto_item *it;
it = proto_tree_add_item(tree, hf_index, tvb, offset, -1, ENC_BIG_ENDIAN);
proto_item_append_text(it," XXX: Not yet implemented!");
return offset;
}
static int
dissect_dap_T_any(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
return offset;
}
static int
dissect_dap_T_final(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
return offset;
}
static int
dissect_dap_T_strings_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_strings_item_choice, hf_index, ett_dap_T_strings_item,
NULL);
return offset;
}
static int
dissect_dap_T_strings(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_strings_sequence_of, hf_index, ett_dap_T_strings);
return offset;
}
static int
dissect_dap_T_substrings(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_substrings_sequence, hf_index, ett_dap_T_substrings);
return offset;
}
static int
dissect_dap_T_matchingRule(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_matchingRule_set_of, hf_index, ett_dap_T_matchingRule);
return offset;
}
static int
dissect_dap_T_matchValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
return offset;
}
static int
dissect_dap_MatchingRuleAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MatchingRuleAssertion_sequence, hf_index, ett_dap_MatchingRuleAssertion);
return offset;
}
static int
dissect_dap_FilterItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
FilterItem_choice, hf_index, ett_dap_FilterItem,
NULL);
return offset;
}
static int
dissect_dap_SetOfFilter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SetOfFilter_set_of, hf_index, ett_dap_SetOfFilter);
return offset;
}
int
dissect_dap_Filter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Filter_choice, hf_index, ett_dap_Filter,
NULL);
return offset;
}
static int
dissect_dap_SortKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SortKey_sequence, hf_index, ett_dap_SortKey);
return offset;
}
static int
dissect_dap_SEQUENCE_SIZE_1_MAX_OF_SortKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_SortKey_sequence_of, hf_index, ett_dap_SEQUENCE_SIZE_1_MAX_OF_SortKey);
return offset;
}
static int
dissect_dap_T_newRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_newRequest_sequence, hf_index, ett_dap_T_newRequest);
return offset;
}
static int
dissect_dap_T_pagedResultsQueryReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *out_tvb;
int i;
int len;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&out_tvb);
if(out_tvb) {
len = tvb_length(out_tvb);
for(i=0; i<len; i++)
if(!g_ascii_isprint(tvb_get_guint8(out_tvb, i)))
break;
if(i == len) {
if(actx->created_item) {
proto_item_append_text(actx->created_item," (");
for(i=0; i<len; i++)
proto_item_append_text(actx->created_item,"%c",tvb_get_guint8(out_tvb,i));
proto_item_append_text(actx->created_item,")");
}
}
}
return offset;
}
static int
dissect_dap_PagedResultsRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PagedResultsRequest_choice, hf_index, ett_dap_PagedResultsRequest,
NULL);
return offset;
}
static int
dissect_dap_UTCTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_dap_GeneralizedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_dap_Time(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Time_choice, hf_index, ett_dap_Time,
NULL);
return offset;
}
static int
dissect_dap_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_dap_ProtectionRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dap_ErrorProtectionRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_dap_SecurityParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SecurityParameters_set, hf_index, ett_dap_SecurityParameters);
return offset;
}
static int
dissect_dap_T_time1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_time1_choice, hf_index, ett_dap_T_time1,
NULL);
return offset;
}
static int
dissect_dap_T_time2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_time2_choice, hf_index, ett_dap_T_time2,
NULL);
return offset;
}
static int
dissect_dap_T_validity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
T_validity_set, hf_index, ett_dap_T_validity);
return offset;
}
static int
dissect_dap_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dap_T_protected(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_protected_sequence, hf_index, ett_dap_T_protected);
return offset;
}
static int
dissect_dap_T_password(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_password_choice, hf_index, ett_dap_T_password,
NULL);
return offset;
}
static int
dissect_dap_SimpleCredentials(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SimpleCredentials_sequence, hf_index, ett_dap_SimpleCredentials);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", x509if_get_last_dn());
return offset;
}
static int
dissect_dap_SEQUENCE_SIZE_1_MAX_OF_AlgorithmIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_AlgorithmIdentifier_sequence_of, hf_index, ett_dap_SEQUENCE_SIZE_1_MAX_OF_AlgorithmIdentifier);
return offset;
}
static int
dissect_dap_BindKeyInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_dap_TokenData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TokenData_sequence, hf_index, ett_dap_TokenData);
return offset;
}
static int
dissect_dap_Token(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Token_sequence, hf_index, ett_dap_Token);
return offset;
}
static int
dissect_dap_StrongCredentials(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
StrongCredentials_set, hf_index, ett_dap_StrongCredentials);
return offset;
}
static int
dissect_dap_EXTERNAL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_external_type(implicit_tag, tree, tvb, offset, actx, hf_index, NULL);
return offset;
}
static int
dissect_dap_T_req(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
return offset;
}
static int
dissect_dap_T_rep(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
return offset;
}
static int
dissect_dap_SpkmCredentials(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SpkmCredentials_choice, hf_index, ett_dap_SpkmCredentials,
NULL);
return offset;
}
static int
dissect_dap_SaslCredentials(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SaslCredentials_sequence, hf_index, ett_dap_SaslCredentials);
return offset;
}
static int
dissect_dap_Credentials(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Credentials_choice, hf_index, ett_dap_Credentials,
NULL);
return offset;
}
static int
dissect_dap_Versions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Versions_bits, hf_index, ett_dap_Versions,
NULL);
return offset;
}
int
dissect_dap_DirectoryBindArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
guint32 len;
dissect_ber_length(actx->pinfo, tree, tvb, offset+1, &len, NULL);
if(len == 0) {
proto_tree_add_text(tree, tvb, offset, -1,"Anonymous");
col_append_str(actx->pinfo->cinfo, COL_INFO, " anonymous");
}
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
DirectoryBindArgument_set, hf_index, ett_dap_DirectoryBindArgument);
return offset;
}
static int
dissect_dap_DirectoryBindResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_dap_DirectoryBindArgument(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_dap_ServiceProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
guint32 problem;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&problem);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(problem, dap_ServiceProblem_vals, "ServiceProblem(%d)"));
return offset;
}
int
dissect_dap_SecurityProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
guint32 problem;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&problem);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(problem, dap_SecurityProblem_vals, "SecurityProblem(%d)"));
return offset;
}
static int
dissect_dap_T_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_error_choice, hf_index, ett_dap_T_error,
NULL);
return offset;
}
static int
dissect_dap_DirectoryBindErrorData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
DirectoryBindErrorData_set, hf_index, ett_dap_DirectoryBindErrorData);
return offset;
}
static int
dissect_dap_T_signedDirectoryBindError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedDirectoryBindError_sequence, hf_index, ett_dap_T_signedDirectoryBindError);
return offset;
}
int
dissect_dap_DirectoryBindError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DirectoryBindError_choice, hf_index, ett_dap_DirectoryBindError,
NULL);
return offset;
}
static int
dissect_dap_ReadArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ReadArgumentData_set, hf_index, ett_dap_ReadArgumentData);
return offset;
}
static int
dissect_dap_T_signedReadArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedReadArgument_sequence, hf_index, ett_dap_T_signedReadArgument);
return offset;
}
int
dissect_dap_ReadArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ReadArgument_choice, hf_index, ett_dap_ReadArgument,
NULL);
return offset;
}
static int
dissect_dap_T_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_item_choice, hf_index, ett_dap_T_item,
NULL);
return offset;
}
static int
dissect_dap_T_permission(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
T_permission_bits, hf_index, ett_dap_T_permission,
NULL);
return offset;
}
static int
dissect_dap_ModifyRights_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ModifyRights_item_sequence, hf_index, ett_dap_ModifyRights_item);
return offset;
}
static int
dissect_dap_ModifyRights(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
ModifyRights_set_of, hf_index, ett_dap_ModifyRights);
return offset;
}
static int
dissect_dap_SEQUENCE_SIZE_1_MAX_OF_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_Attribute_sequence_of, hf_index, ett_dap_SEQUENCE_SIZE_1_MAX_OF_Attribute);
return offset;
}
static int
dissect_dap_ReadResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ReadResultData_set, hf_index, ett_dap_ReadResultData);
return offset;
}
static int
dissect_dap_T_signedReadResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedReadResult_sequence, hf_index, ett_dap_T_signedReadResult);
return offset;
}
int
dissect_dap_ReadResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ReadResult_choice, hf_index, ett_dap_ReadResult,
NULL);
return offset;
}
static int
dissect_dap_CompareArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CompareArgumentData_set, hf_index, ett_dap_CompareArgumentData);
return offset;
}
static int
dissect_dap_T_signedCompareArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedCompareArgument_sequence, hf_index, ett_dap_T_signedCompareArgument);
return offset;
}
int
dissect_dap_CompareArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CompareArgument_choice, hf_index, ett_dap_CompareArgument,
NULL);
return offset;
}
static int
dissect_dap_CompareResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CompareResultData_set, hf_index, ett_dap_CompareResultData);
return offset;
}
static int
dissect_dap_T_signedCompareResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedCompareResult_sequence, hf_index, ett_dap_T_signedCompareResult);
return offset;
}
int
dissect_dap_CompareResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CompareResult_choice, hf_index, ett_dap_CompareResult,
NULL);
return offset;
}
static int
dissect_dap_AbandonArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AbandonArgumentData_sequence, hf_index, ett_dap_AbandonArgumentData);
return offset;
}
static int
dissect_dap_T_signedAbandonArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedAbandonArgument_sequence, hf_index, ett_dap_T_signedAbandonArgument);
return offset;
}
int
dissect_dap_AbandonArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AbandonArgument_choice, hf_index, ett_dap_AbandonArgument,
NULL);
return offset;
}
static int
dissect_dap_AbandonResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AbandonResultData_sequence, hf_index, ett_dap_AbandonResultData);
return offset;
}
static int
dissect_dap_T_signedAbandonResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedAbandonResult_sequence, hf_index, ett_dap_T_signedAbandonResult);
return offset;
}
static int
dissect_dap_AbandonInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AbandonInformation_choice, hf_index, ett_dap_AbandonInformation,
NULL);
return offset;
}
int
dissect_dap_AbandonResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AbandonResult_choice, hf_index, ett_dap_AbandonResult,
NULL);
return offset;
}
static int
dissect_dap_ListArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ListArgumentData_set, hf_index, ett_dap_ListArgumentData);
return offset;
}
static int
dissect_dap_T_signedListArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedListArgument_sequence, hf_index, ett_dap_T_signedListArgument);
return offset;
}
int
dissect_dap_ListArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ListArgument_choice, hf_index, ett_dap_ListArgument,
NULL);
return offset;
}
static int
dissect_dap_T_subordinates_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_subordinates_item_sequence, hf_index, ett_dap_T_subordinates_item);
return offset;
}
static int
dissect_dap_T_subordinates(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_subordinates_set_of, hf_index, ett_dap_T_subordinates);
return offset;
}
static int
dissect_dap_LimitProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
guint32 problem;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&problem);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(problem, dap_LimitProblem_vals, "LimitProblem(%d)"));
return offset;
}
static int
dissect_dap_SET_SIZE_1_MAX_OF_ContinuationReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_SIZE_1_MAX_OF_ContinuationReference_set_of, hf_index, ett_dap_SET_SIZE_1_MAX_OF_ContinuationReference);
return offset;
}
static int
dissect_dap_T_unknownErrors(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_unknownErrors_set_of, hf_index, ett_dap_T_unknownErrors);
return offset;
}
static int
dissect_dap_T_entryCount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_entryCount_choice, hf_index, ett_dap_T_entryCount,
NULL);
return offset;
}
static int
dissect_dap_PartialOutcomeQualifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
PartialOutcomeQualifier_set, hf_index, ett_dap_PartialOutcomeQualifier);
return offset;
}
static int
dissect_dap_T_listInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
T_listInfo_set, hf_index, ett_dap_T_listInfo);
return offset;
}
static int
dissect_dap_T_signedListResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedListResult_sequence, hf_index, ett_dap_T_signedListResult);
return offset;
}
int
dissect_dap_ListResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ListResult_choice, hf_index, ett_dap_ListResult,
NULL);
return offset;
}
static int
dissect_dap_SET_OF_ListResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_ListResult_set_of, hf_index, ett_dap_SET_OF_ListResult);
return offset;
}
static int
dissect_dap_ListResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ListResultData_choice, hf_index, ett_dap_ListResultData,
NULL);
return offset;
}
static int
dissect_dap_T_subset(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
guint32 subset;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&subset);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(subset, dap_T_subset_vals, "Subset(%d)"));
return offset;
}
int
dissect_dap_HierarchySelections(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
HierarchySelections_bits, hf_index, ett_dap_HierarchySelections,
NULL);
return offset;
}
int
dissect_dap_SearchControlOptions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
SearchControlOptions_bits, hf_index, ett_dap_SearchControlOptions,
NULL);
return offset;
}
static int
dissect_dap_DomainLocalID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509sat_DirectoryString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_dap_T_joinSubset(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dap_JoinContextType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_dap_SEQUENCE_SIZE_1_MAX_OF_JoinContextType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_JoinContextType_sequence_of, hf_index, ett_dap_SEQUENCE_SIZE_1_MAX_OF_JoinContextType);
return offset;
}
static int
dissect_dap_JoinAttPair(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
JoinAttPair_sequence, hf_index, ett_dap_JoinAttPair);
return offset;
}
static int
dissect_dap_SEQUENCE_SIZE_1_MAX_OF_JoinAttPair(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_JoinAttPair_sequence_of, hf_index, ett_dap_SEQUENCE_SIZE_1_MAX_OF_JoinAttPair);
return offset;
}
static int
dissect_dap_JoinArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
JoinArgument_sequence, hf_index, ett_dap_JoinArgument);
return offset;
}
static int
dissect_dap_SEQUENCE_SIZE_1_MAX_OF_JoinArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_JoinArgument_sequence_of, hf_index, ett_dap_SEQUENCE_SIZE_1_MAX_OF_JoinArgument);
return offset;
}
static int
dissect_dap_T_joinType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dap_SearchArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SearchArgumentData_set, hf_index, ett_dap_SearchArgumentData);
return offset;
}
static int
dissect_dap_T_signedSearchArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedSearchArgument_sequence, hf_index, ett_dap_T_signedSearchArgument);
return offset;
}
int
dissect_dap_SearchArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SearchArgument_choice, hf_index, ett_dap_SearchArgument,
NULL);
return offset;
}
static int
dissect_dap_SET_OF_EntryInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_EntryInformation_set_of, hf_index, ett_dap_SET_OF_EntryInformation);
return offset;
}
static int
dissect_dap_T_searchInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
T_searchInfo_set, hf_index, ett_dap_T_searchInfo);
return offset;
}
static int
dissect_dap_T_signedSearchResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedSearchResult_sequence, hf_index, ett_dap_T_signedSearchResult);
return offset;
}
int
dissect_dap_SearchResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SearchResult_choice, hf_index, ett_dap_SearchResult,
NULL);
return offset;
}
static int
dissect_dap_SET_OF_SearchResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_SearchResult_set_of, hf_index, ett_dap_SET_OF_SearchResult);
return offset;
}
static int
dissect_dap_SearchResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SearchResultData_choice, hf_index, ett_dap_SearchResultData,
NULL);
return offset;
}
static int
dissect_dap_SET_OF_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_Attribute_set_of, hf_index, ett_dap_SET_OF_Attribute);
return offset;
}
static int
dissect_dap_AddEntryArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AddEntryArgumentData_set, hf_index, ett_dap_AddEntryArgumentData);
return offset;
}
static int
dissect_dap_T_signedAddEntryArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedAddEntryArgument_sequence, hf_index, ett_dap_T_signedAddEntryArgument);
return offset;
}
int
dissect_dap_AddEntryArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AddEntryArgument_choice, hf_index, ett_dap_AddEntryArgument,
NULL);
return offset;
}
static int
dissect_dap_AddEntryResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AddEntryResultData_sequence, hf_index, ett_dap_AddEntryResultData);
return offset;
}
static int
dissect_dap_T_signedAddEntryResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedAddEntryResult_sequence, hf_index, ett_dap_T_signedAddEntryResult);
return offset;
}
static int
dissect_dap_AddEntryInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AddEntryInformation_choice, hf_index, ett_dap_AddEntryInformation,
NULL);
return offset;
}
int
dissect_dap_AddEntryResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AddEntryResult_choice, hf_index, ett_dap_AddEntryResult,
NULL);
return offset;
}
static int
dissect_dap_RemoveEntryArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RemoveEntryArgumentData_set, hf_index, ett_dap_RemoveEntryArgumentData);
return offset;
}
static int
dissect_dap_T_signedRemoveEntryArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedRemoveEntryArgument_sequence, hf_index, ett_dap_T_signedRemoveEntryArgument);
return offset;
}
int
dissect_dap_RemoveEntryArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RemoveEntryArgument_choice, hf_index, ett_dap_RemoveEntryArgument,
NULL);
return offset;
}
static int
dissect_dap_RemoveEntryResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RemoveEntryResultData_sequence, hf_index, ett_dap_RemoveEntryResultData);
return offset;
}
static int
dissect_dap_T_signedRemoveEntryResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedRemoveEntryResult_sequence, hf_index, ett_dap_T_signedRemoveEntryResult);
return offset;
}
static int
dissect_dap_RemoveEntryInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RemoveEntryInformation_choice, hf_index, ett_dap_RemoveEntryInformation,
NULL);
return offset;
}
int
dissect_dap_RemoveEntryResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RemoveEntryResult_choice, hf_index, ett_dap_RemoveEntryResult,
NULL);
return offset;
}
int
dissect_dap_EntryModification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
EntryModification_choice, hf_index, ett_dap_EntryModification,
NULL);
return offset;
}
static int
dissect_dap_SEQUENCE_OF_EntryModification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_EntryModification_sequence_of, hf_index, ett_dap_SEQUENCE_OF_EntryModification);
return offset;
}
static int
dissect_dap_ModifyEntryArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ModifyEntryArgumentData_set, hf_index, ett_dap_ModifyEntryArgumentData);
return offset;
}
static int
dissect_dap_T_signedModifyEntryArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedModifyEntryArgument_sequence, hf_index, ett_dap_T_signedModifyEntryArgument);
return offset;
}
int
dissect_dap_ModifyEntryArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ModifyEntryArgument_choice, hf_index, ett_dap_ModifyEntryArgument,
NULL);
return offset;
}
static int
dissect_dap_ModifyEntryResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ModifyEntryResultData_sequence, hf_index, ett_dap_ModifyEntryResultData);
return offset;
}
static int
dissect_dap_T_signedModifyEntryResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedModifyEntryResult_sequence, hf_index, ett_dap_T_signedModifyEntryResult);
return offset;
}
static int
dissect_dap_ModifyEntryInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ModifyEntryInformation_choice, hf_index, ett_dap_ModifyEntryInformation,
NULL);
return offset;
}
int
dissect_dap_ModifyEntryResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ModifyEntryResult_choice, hf_index, ett_dap_ModifyEntryResult,
NULL);
return offset;
}
int
dissect_dap_ModifyDNArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ModifyDNArgument_set, hf_index, ett_dap_ModifyDNArgument);
return offset;
}
static int
dissect_dap_ModifyDNResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ModifyDNResultData_sequence, hf_index, ett_dap_ModifyDNResultData);
return offset;
}
static int
dissect_dap_T_signedModifyDNResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedModifyDNResult_sequence, hf_index, ett_dap_T_signedModifyDNResult);
return offset;
}
static int
dissect_dap_ModifyDNInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ModifyDNInformation_choice, hf_index, ett_dap_ModifyDNInformation,
NULL);
return offset;
}
int
dissect_dap_ModifyDNResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ModifyDNResult_choice, hf_index, ett_dap_ModifyDNResult,
NULL);
return offset;
}
static int
dissect_dap_AbandonedData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AbandonedData_set, hf_index, ett_dap_AbandonedData);
return offset;
}
static int
dissect_dap_T_signedAbandoned(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedAbandoned_sequence, hf_index, ett_dap_T_signedAbandoned);
return offset;
}
int
dissect_dap_Abandoned(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Abandoned_choice, hf_index, ett_dap_Abandoned,
NULL);
return offset;
}
static int
dissect_dap_AbandonProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dap_AbandonFailedErrorData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AbandonFailedErrorData_set, hf_index, ett_dap_AbandonFailedErrorData);
return offset;
}
static int
dissect_dap_T_signedAbandonFailedError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedAbandonFailedError_sequence, hf_index, ett_dap_T_signedAbandonFailedError);
return offset;
}
int
dissect_dap_AbandonFailedError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AbandonFailedError_choice, hf_index, ett_dap_AbandonFailedError,
NULL);
return offset;
}
static int
dissect_dap_AttributeProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dap_T_problems_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_problems_item_sequence, hf_index, ett_dap_T_problems_item);
return offset;
}
static int
dissect_dap_T_problems(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_problems_set_of, hf_index, ett_dap_T_problems);
return offset;
}
static int
dissect_dap_AttributeErrorData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AttributeErrorData_set, hf_index, ett_dap_AttributeErrorData);
return offset;
}
static int
dissect_dap_T_signedAttributeError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedAttributeError_sequence, hf_index, ett_dap_T_signedAttributeError);
return offset;
}
int
dissect_dap_AttributeError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AttributeError_choice, hf_index, ett_dap_AttributeError,
NULL);
return offset;
}
static int
dissect_dap_NameProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dap_NameErrorData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
NameErrorData_set, hf_index, ett_dap_NameErrorData);
return offset;
}
static int
dissect_dap_T_signedNameError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedNameError_sequence, hf_index, ett_dap_T_signedNameError);
return offset;
}
int
dissect_dap_NameError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
NameError_choice, hf_index, ett_dap_NameError,
NULL);
return offset;
}
static int
dissect_dap_ReferralData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ReferralData_set, hf_index, ett_dap_ReferralData);
return offset;
}
static int
dissect_dap_T_signedReferral(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedReferral_sequence, hf_index, ett_dap_T_signedReferral);
return offset;
}
int
dissect_dap_Referral(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Referral_choice, hf_index, ett_dap_Referral,
NULL);
return offset;
}
static int
dissect_dap_T_spkmInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
return offset;
}
static int
dissect_dap_SecurityErrorData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SecurityErrorData_set, hf_index, ett_dap_SecurityErrorData);
return offset;
}
static int
dissect_dap_T_signedSecurityError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedSecurityError_sequence, hf_index, ett_dap_T_signedSecurityError);
return offset;
}
int
dissect_dap_SecurityError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SecurityError_choice, hf_index, ett_dap_SecurityError,
NULL);
return offset;
}
static int
dissect_dap_ServiceErrorData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ServiceErrorData_set, hf_index, ett_dap_ServiceErrorData);
return offset;
}
static int
dissect_dap_T_signedServiceError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedServiceError_sequence, hf_index, ett_dap_T_signedServiceError);
return offset;
}
int
dissect_dap_ServiceError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ServiceError_choice, hf_index, ett_dap_ServiceError,
NULL);
return offset;
}
static int
dissect_dap_UpdateProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
guint32 problem;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&problem);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", val_to_str(problem, dap_UpdateProblem_vals, "UpdateProblem(%d)"));
return offset;
}
static int
dissect_dap_T_attributeInfo_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_attributeInfo_item_choice, hf_index, ett_dap_T_attributeInfo_item,
NULL);
return offset;
}
static int
dissect_dap_T_attributeInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_attributeInfo_set_of, hf_index, ett_dap_T_attributeInfo);
return offset;
}
static int
dissect_dap_UpdateErrorData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
UpdateErrorData_set, hf_index, ett_dap_UpdateErrorData);
return offset;
}
static int
dissect_dap_T_signedUpdateError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedUpdateError_sequence, hf_index, ett_dap_T_signedUpdateError);
return offset;
}
int
dissect_dap_UpdateError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
UpdateError_choice, hf_index, ett_dap_UpdateError,
NULL);
return offset;
}
static int dissect_DirectoryBindArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_DirectoryBindArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_DirectoryBindArgument_PDU);
return offset;
}
static int dissect_DirectoryBindResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_DirectoryBindResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_DirectoryBindResult_PDU);
return offset;
}
static int dissect_DirectoryBindError_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_DirectoryBindError(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_DirectoryBindError_PDU);
return offset;
}
static int dissect_ReadArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_ReadArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_ReadArgument_PDU);
return offset;
}
static int dissect_ReadResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_ReadResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_ReadResult_PDU);
return offset;
}
static int dissect_CompareArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_CompareArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_CompareArgument_PDU);
return offset;
}
static int dissect_CompareResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_CompareResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_CompareResult_PDU);
return offset;
}
static int dissect_AbandonArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_AbandonArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_AbandonArgument_PDU);
return offset;
}
static int dissect_AbandonResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_AbandonResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_AbandonResult_PDU);
return offset;
}
static int dissect_ListArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_ListArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_ListArgument_PDU);
return offset;
}
static int dissect_ListResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_ListResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_ListResult_PDU);
return offset;
}
static int dissect_SearchArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_SearchArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_SearchArgument_PDU);
return offset;
}
static int dissect_SearchResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_SearchResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_SearchResult_PDU);
return offset;
}
static int dissect_AddEntryArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_AddEntryArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_AddEntryArgument_PDU);
return offset;
}
static int dissect_AddEntryResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_AddEntryResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_AddEntryResult_PDU);
return offset;
}
static int dissect_RemoveEntryArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_RemoveEntryArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_RemoveEntryArgument_PDU);
return offset;
}
static int dissect_RemoveEntryResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_RemoveEntryResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_RemoveEntryResult_PDU);
return offset;
}
static int dissect_ModifyEntryArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_ModifyEntryArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_ModifyEntryArgument_PDU);
return offset;
}
static int dissect_ModifyEntryResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_ModifyEntryResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_ModifyEntryResult_PDU);
return offset;
}
static int dissect_ModifyDNArgument_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_ModifyDNArgument(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_ModifyDNArgument_PDU);
return offset;
}
static int dissect_ModifyDNResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_ModifyDNResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_ModifyDNResult_PDU);
return offset;
}
static int dissect_Abandoned_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_Abandoned(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_Abandoned_PDU);
return offset;
}
static int dissect_AbandonFailedError_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_AbandonFailedError(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_AbandonFailedError_PDU);
return offset;
}
static int dissect_AttributeError_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_AttributeError(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_AttributeError_PDU);
return offset;
}
static int dissect_NameError_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_NameError(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_NameError_PDU);
return offset;
}
static int dissect_Referral_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_Referral(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_Referral_PDU);
return offset;
}
static int dissect_SecurityError_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_SecurityError(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_SecurityError_PDU);
return offset;
}
static int dissect_ServiceError_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_ServiceError(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_ServiceError_PDU);
return offset;
}
static int dissect_UpdateError_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_dap_UpdateError(FALSE, tvb, offset, &asn1_ctx, tree, hf_dap_UpdateError_PDU);
return offset;
}
void proto_register_dap(void) {
static hf_register_info hf[] =
{
#line 1 "../../asn1/dap/packet-dap-hfarr.c"
{ &hf_dap_DirectoryBindArgument_PDU,
{ "DirectoryBindArgument", "dap.DirectoryBindArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_DirectoryBindResult_PDU,
{ "DirectoryBindResult", "dap.DirectoryBindResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_DirectoryBindError_PDU,
{ "DirectoryBindError", "dap.DirectoryBindError",
FT_UINT32, BASE_DEC, VALS(dap_DirectoryBindError_vals), 0,
NULL, HFILL }},
{ &hf_dap_ReadArgument_PDU,
{ "ReadArgument", "dap.ReadArgument",
FT_UINT32, BASE_DEC, VALS(dap_ReadArgument_vals), 0,
NULL, HFILL }},
{ &hf_dap_ReadResult_PDU,
{ "ReadResult", "dap.ReadResult",
FT_UINT32, BASE_DEC, VALS(dap_ReadResult_vals), 0,
NULL, HFILL }},
{ &hf_dap_CompareArgument_PDU,
{ "CompareArgument", "dap.CompareArgument",
FT_UINT32, BASE_DEC, VALS(dap_CompareArgument_vals), 0,
NULL, HFILL }},
{ &hf_dap_CompareResult_PDU,
{ "CompareResult", "dap.CompareResult",
FT_UINT32, BASE_DEC, VALS(dap_CompareResult_vals), 0,
NULL, HFILL }},
{ &hf_dap_AbandonArgument_PDU,
{ "AbandonArgument", "dap.AbandonArgument",
FT_UINT32, BASE_DEC, VALS(dap_AbandonArgument_vals), 0,
NULL, HFILL }},
{ &hf_dap_AbandonResult_PDU,
{ "AbandonResult", "dap.AbandonResult",
FT_UINT32, BASE_DEC, VALS(dap_AbandonResult_vals), 0,
NULL, HFILL }},
{ &hf_dap_ListArgument_PDU,
{ "ListArgument", "dap.ListArgument",
FT_UINT32, BASE_DEC, VALS(dap_ListArgument_vals), 0,
NULL, HFILL }},
{ &hf_dap_ListResult_PDU,
{ "ListResult", "dap.ListResult",
FT_UINT32, BASE_DEC, VALS(dap_ListResult_vals), 0,
NULL, HFILL }},
{ &hf_dap_SearchArgument_PDU,
{ "SearchArgument", "dap.SearchArgument",
FT_UINT32, BASE_DEC, VALS(dap_SearchArgument_vals), 0,
NULL, HFILL }},
{ &hf_dap_SearchResult_PDU,
{ "SearchResult", "dap.SearchResult",
FT_UINT32, BASE_DEC, VALS(dap_SearchResult_vals), 0,
NULL, HFILL }},
{ &hf_dap_AddEntryArgument_PDU,
{ "AddEntryArgument", "dap.AddEntryArgument",
FT_UINT32, BASE_DEC, VALS(dap_AddEntryArgument_vals), 0,
NULL, HFILL }},
{ &hf_dap_AddEntryResult_PDU,
{ "AddEntryResult", "dap.AddEntryResult",
FT_UINT32, BASE_DEC, VALS(dap_AddEntryResult_vals), 0,
NULL, HFILL }},
{ &hf_dap_RemoveEntryArgument_PDU,
{ "RemoveEntryArgument", "dap.RemoveEntryArgument",
FT_UINT32, BASE_DEC, VALS(dap_RemoveEntryArgument_vals), 0,
NULL, HFILL }},
{ &hf_dap_RemoveEntryResult_PDU,
{ "RemoveEntryResult", "dap.RemoveEntryResult",
FT_UINT32, BASE_DEC, VALS(dap_RemoveEntryResult_vals), 0,
NULL, HFILL }},
{ &hf_dap_ModifyEntryArgument_PDU,
{ "ModifyEntryArgument", "dap.ModifyEntryArgument",
FT_UINT32, BASE_DEC, VALS(dap_ModifyEntryArgument_vals), 0,
NULL, HFILL }},
{ &hf_dap_ModifyEntryResult_PDU,
{ "ModifyEntryResult", "dap.ModifyEntryResult",
FT_UINT32, BASE_DEC, VALS(dap_ModifyEntryResult_vals), 0,
NULL, HFILL }},
{ &hf_dap_ModifyDNArgument_PDU,
{ "ModifyDNArgument", "dap.ModifyDNArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_ModifyDNResult_PDU,
{ "ModifyDNResult", "dap.ModifyDNResult",
FT_UINT32, BASE_DEC, VALS(dap_ModifyDNResult_vals), 0,
NULL, HFILL }},
{ &hf_dap_Abandoned_PDU,
{ "Abandoned", "dap.Abandoned",
FT_UINT32, BASE_DEC, VALS(dap_Abandoned_vals), 0,
NULL, HFILL }},
{ &hf_dap_AbandonFailedError_PDU,
{ "AbandonFailedError", "dap.AbandonFailedError",
FT_UINT32, BASE_DEC, VALS(dap_AbandonFailedError_vals), 0,
NULL, HFILL }},
{ &hf_dap_AttributeError_PDU,
{ "AttributeError", "dap.AttributeError",
FT_UINT32, BASE_DEC, VALS(dap_AttributeError_vals), 0,
NULL, HFILL }},
{ &hf_dap_NameError_PDU,
{ "NameError", "dap.NameError",
FT_UINT32, BASE_DEC, VALS(dap_NameError_vals), 0,
NULL, HFILL }},
{ &hf_dap_Referral_PDU,
{ "Referral", "dap.Referral",
FT_UINT32, BASE_DEC, VALS(dap_Referral_vals), 0,
NULL, HFILL }},
{ &hf_dap_SecurityError_PDU,
{ "SecurityError", "dap.SecurityError",
FT_UINT32, BASE_DEC, VALS(dap_SecurityError_vals), 0,
NULL, HFILL }},
{ &hf_dap_ServiceError_PDU,
{ "ServiceError", "dap.ServiceError",
FT_UINT32, BASE_DEC, VALS(dap_ServiceError_vals), 0,
NULL, HFILL }},
{ &hf_dap_UpdateError_PDU,
{ "UpdateError", "dap.UpdateError",
FT_UINT32, BASE_DEC, VALS(dap_UpdateError_vals), 0,
NULL, HFILL }},
{ &hf_dap_options,
{ "options", "dap.options",
FT_BYTES, BASE_NONE, NULL, 0,
"ServiceControlOptions", HFILL }},
{ &hf_dap_priority,
{ "priority", "dap.priority",
FT_INT32, BASE_DEC, VALS(dap_T_priority_vals), 0,
NULL, HFILL }},
{ &hf_dap_timeLimit,
{ "timeLimit", "dap.timeLimit",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dap_sizeLimit,
{ "sizeLimit", "dap.sizeLimit",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dap_scopeOfReferral,
{ "scopeOfReferral", "dap.scopeOfReferral",
FT_INT32, BASE_DEC, VALS(dap_T_scopeOfReferral_vals), 0,
NULL, HFILL }},
{ &hf_dap_attributeSizeLimit,
{ "attributeSizeLimit", "dap.attributeSizeLimit",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dap_manageDSAITPlaneRef,
{ "manageDSAITPlaneRef", "dap.manageDSAITPlaneRef_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_dsaName,
{ "dsaName", "dap.dsaName",
FT_UINT32, BASE_DEC, VALS(x509if_Name_vals), 0,
"Name", HFILL }},
{ &hf_dap_agreementID,
{ "agreementID", "dap.agreementID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_serviceType,
{ "serviceType", "dap.serviceType",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_dap_userClass,
{ "userClass", "dap.userClass",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dap_attributes,
{ "attributes", "dap.attributes",
FT_UINT32, BASE_DEC, VALS(dap_T_attributes_vals), 0,
NULL, HFILL }},
{ &hf_dap_allUserAttributes,
{ "allUserAttributes", "dap.allUserAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_select,
{ "select", "dap.select",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_AttributeType", HFILL }},
{ &hf_dap_select_item,
{ "AttributeType", "dap.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_infoTypes,
{ "infoTypes", "dap.infoTypes",
FT_INT32, BASE_DEC, VALS(dap_T_infoTypes_vals), 0,
NULL, HFILL }},
{ &hf_dap_extraAttributes,
{ "extraAttributes", "dap.extraAttributes",
FT_UINT32, BASE_DEC, VALS(dap_T_extraAttributes_vals), 0,
NULL, HFILL }},
{ &hf_dap_allOperationalAttributes,
{ "allOperationalAttributes", "dap.allOperationalAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_extraSelect,
{ "select", "dap.select",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_MAX_OF_AttributeType", HFILL }},
{ &hf_dap_extraSelect_item,
{ "AttributeType", "dap.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_contextSelection,
{ "contextSelection", "dap.contextSelection",
FT_UINT32, BASE_DEC, VALS(dap_ContextSelection_vals), 0,
NULL, HFILL }},
{ &hf_dap_returnContexts,
{ "returnContexts", "dap.returnContexts",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_familyReturn,
{ "familyReturn", "dap.familyReturn_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_allContexts,
{ "allContexts", "dap.allContexts_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_selectedContexts,
{ "selectedContexts", "dap.selectedContexts",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_MAX_OF_TypeAndContextAssertion", HFILL }},
{ &hf_dap_selectedContexts_item,
{ "TypeAndContextAssertion", "dap.TypeAndContextAssertion_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_type,
{ "type", "dap.type",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_dap_contextAssertions,
{ "contextAssertions", "dap.contextAssertions",
FT_UINT32, BASE_DEC, VALS(dap_T_contextAssertions_vals), 0,
NULL, HFILL }},
{ &hf_dap_preference,
{ "preference", "dap.preference",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ContextAssertion", HFILL }},
{ &hf_dap_preference_item,
{ "ContextAssertion", "dap.ContextAssertion_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_all,
{ "all", "dap.all",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ContextAssertion", HFILL }},
{ &hf_dap_all_item,
{ "ContextAssertion", "dap.ContextAssertion_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_memberSelect,
{ "memberSelect", "dap.memberSelect",
FT_UINT32, BASE_DEC, VALS(dap_T_memberSelect_vals), 0,
NULL, HFILL }},
{ &hf_dap_familySelect,
{ "familySelect", "dap.familySelect",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dap_familySelect_item,
{ "familySelect item", "dap.familySelect_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_dap_name,
{ "name", "dap.name",
FT_UINT32, BASE_DEC, VALS(x509if_Name_vals), 0,
NULL, HFILL }},
{ &hf_dap_fromEntry,
{ "fromEntry", "dap.fromEntry",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_entry_information,
{ "information", "dap.information",
FT_UINT32, BASE_DEC, NULL, 0,
"T_entry_information", HFILL }},
{ &hf_dap_entry_information_item,
{ "information item", "dap.information_item",
FT_UINT32, BASE_DEC, VALS(dap_EntryInformationItem_vals), 0,
"EntryInformationItem", HFILL }},
{ &hf_dap_attributeType,
{ "attributeType", "dap.attributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_attribute,
{ "attribute", "dap.attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_incompleteEntry,
{ "incompleteEntry", "dap.incompleteEntry",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_partialName,
{ "partialName", "dap.partialName",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_derivedEntry,
{ "derivedEntry", "dap.derivedEntry",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_family_class,
{ "family-class", "dap.family_class",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_dap_familyEntries,
{ "familyEntries", "dap.familyEntries",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_FamilyEntry", HFILL }},
{ &hf_dap_familyEntries_item,
{ "FamilyEntry", "dap.FamilyEntry_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_rdn,
{ "rdn", "dap.rdn",
FT_UINT32, BASE_DEC, NULL, 0,
"RelativeDistinguishedName", HFILL }},
{ &hf_dap_family_information,
{ "information", "dap.information",
FT_UINT32, BASE_DEC, NULL, 0,
"FamilyInformation", HFILL }},
{ &hf_dap_family_information_item,
{ "information item", "dap.information_item",
FT_UINT32, BASE_DEC, VALS(dap_T_family_information_item_vals), 0,
"T_family_information_item", HFILL }},
{ &hf_dap_family_info,
{ "family-info", "dap.family_info",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_FamilyEntries", HFILL }},
{ &hf_dap_family_info_item,
{ "FamilyEntries", "dap.FamilyEntries_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_filter_item,
{ "item", "dap.item",
FT_UINT32, BASE_DEC, VALS(dap_FilterItem_vals), 0,
"FilterItem", HFILL }},
{ &hf_dap_and,
{ "and", "dap.and",
FT_UINT32, BASE_DEC, NULL, 0,
"SetOfFilter", HFILL }},
{ &hf_dap_or,
{ "or", "dap.or",
FT_UINT32, BASE_DEC, NULL, 0,
"SetOfFilter", HFILL }},
{ &hf_dap_not,
{ "not", "dap.not",
FT_UINT32, BASE_DEC, VALS(dap_Filter_vals), 0,
"Filter", HFILL }},
{ &hf_dap_SetOfFilter_item,
{ "Filter", "dap.Filter",
FT_UINT32, BASE_DEC, VALS(dap_Filter_vals), 0,
NULL, HFILL }},
{ &hf_dap_equality,
{ "equality", "dap.equality_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeValueAssertion", HFILL }},
{ &hf_dap_substrings,
{ "substrings", "dap.substrings_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_sunstringType,
{ "type", "dap.type",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_dap_strings,
{ "strings", "dap.strings",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dap_strings_item,
{ "strings item", "dap.strings_item",
FT_UINT32, BASE_DEC, VALS(dap_T_strings_item_vals), 0,
NULL, HFILL }},
{ &hf_dap_initial,
{ "initial", "dap.initial_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_any,
{ "any", "dap.any_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_final,
{ "final", "dap.final_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_control,
{ "control", "dap.control_element",
FT_NONE, BASE_NONE, NULL, 0,
"Attribute", HFILL }},
{ &hf_dap_greaterOrEqual,
{ "greaterOrEqual", "dap.greaterOrEqual_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeValueAssertion", HFILL }},
{ &hf_dap_lessOrEqual,
{ "lessOrEqual", "dap.lessOrEqual_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeValueAssertion", HFILL }},
{ &hf_dap_present,
{ "present", "dap.present",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_dap_approximateMatch,
{ "approximateMatch", "dap.approximateMatch_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeValueAssertion", HFILL }},
{ &hf_dap_extensibleMatch,
{ "extensibleMatch", "dap.extensibleMatch_element",
FT_NONE, BASE_NONE, NULL, 0,
"MatchingRuleAssertion", HFILL }},
{ &hf_dap_contextPresent,
{ "contextPresent", "dap.contextPresent_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeTypeAssertion", HFILL }},
{ &hf_dap_matchingRule,
{ "matchingRule", "dap.matchingRule",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dap_matchingRule_item,
{ "matchingRule item", "dap.matchingRule_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_dap_matchValue,
{ "matchValue", "dap.matchValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_dnAttributes,
{ "dnAttributes", "dap.dnAttributes",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_newRequest,
{ "newRequest", "dap.newRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_pageSize,
{ "pageSize", "dap.pageSize",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dap_sortKeys,
{ "sortKeys", "dap.sortKeys",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_SortKey", HFILL }},
{ &hf_dap_sortKeys_item,
{ "SortKey", "dap.SortKey_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_reverse,
{ "reverse", "dap.reverse",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_unmerged,
{ "unmerged", "dap.unmerged",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_pagedResultsQueryReference,
{ "queryReference", "dap.queryReference",
FT_BYTES, BASE_NONE, NULL, 0,
"T_pagedResultsQueryReference", HFILL }},
{ &hf_dap_orderingRule,
{ "orderingRule", "dap.orderingRule",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_dap_certification_path,
{ "certification-path", "dap.certification_path_element",
FT_NONE, BASE_NONE, NULL, 0,
"CertificationPath", HFILL }},
{ &hf_dap_distinguished_name,
{ "name", "dap.name",
FT_UINT32, BASE_DEC, NULL, 0,
"DistinguishedName", HFILL }},
{ &hf_dap_time,
{ "time", "dap.time",
FT_UINT32, BASE_DEC, VALS(dap_Time_vals), 0,
NULL, HFILL }},
{ &hf_dap_random,
{ "random", "dap.random",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_dap_target,
{ "target", "dap.target",
FT_INT32, BASE_DEC, VALS(dap_ProtectionRequest_vals), 0,
"ProtectionRequest", HFILL }},
{ &hf_dap_response,
{ "response", "dap.response",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_dap_operationCode,
{ "operationCode", "dap.operationCode",
FT_UINT32, BASE_DEC, VALS(ros_Code_vals), 0,
"Code", HFILL }},
{ &hf_dap_attributeCertificationPath,
{ "attributeCertificationPath", "dap.attributeCertificationPath_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_errorProtection,
{ "errorProtection", "dap.errorProtection",
FT_INT32, BASE_DEC, VALS(dap_ErrorProtectionRequest_vals), 0,
"ErrorProtectionRequest", HFILL }},
{ &hf_dap_errorCode,
{ "errorCode", "dap.errorCode",
FT_UINT32, BASE_DEC, VALS(ros_Code_vals), 0,
"Code", HFILL }},
{ &hf_dap_utcTime,
{ "utcTime", "dap.utcTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_generalizedTime,
{ "generalizedTime", "dap.generalizedTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_credentials,
{ "credentials", "dap.credentials",
FT_UINT32, BASE_DEC, VALS(dap_Credentials_vals), 0,
NULL, HFILL }},
{ &hf_dap_versions,
{ "versions", "dap.versions",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_simple,
{ "simple", "dap.simple_element",
FT_NONE, BASE_NONE, NULL, 0,
"SimpleCredentials", HFILL }},
{ &hf_dap_strong,
{ "strong", "dap.strong_element",
FT_NONE, BASE_NONE, NULL, 0,
"StrongCredentials", HFILL }},
{ &hf_dap_externalProcedure,
{ "externalProcedure", "dap.externalProcedure_element",
FT_NONE, BASE_NONE, NULL, 0,
"EXTERNAL", HFILL }},
{ &hf_dap_spkm,
{ "spkm", "dap.spkm",
FT_UINT32, BASE_DEC, VALS(dap_SpkmCredentials_vals), 0,
"SpkmCredentials", HFILL }},
{ &hf_dap_sasl,
{ "sasl", "dap.sasl_element",
FT_NONE, BASE_NONE, NULL, 0,
"SaslCredentials", HFILL }},
{ &hf_dap_validity,
{ "validity", "dap.validity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_time1,
{ "time1", "dap.time1",
FT_UINT32, BASE_DEC, VALS(dap_T_time1_vals), 0,
NULL, HFILL }},
{ &hf_dap_utc,
{ "utc", "dap.utc",
FT_STRING, BASE_NONE, NULL, 0,
"UTCTime", HFILL }},
{ &hf_dap_gt,
{ "gt", "dap.gt",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_dap_time2,
{ "time2", "dap.time2",
FT_UINT32, BASE_DEC, VALS(dap_T_time2_vals), 0,
NULL, HFILL }},
{ &hf_dap_random1,
{ "random1", "dap.random1",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_dap_random2,
{ "random2", "dap.random2",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_dap_password,
{ "password", "dap.password",
FT_UINT32, BASE_DEC, VALS(dap_T_password_vals), 0,
NULL, HFILL }},
{ &hf_dap_unprotected,
{ "unprotected", "dap.unprotected",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_dap_protected,
{ "protected", "dap.protected_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_protectedPassword,
{ "protectedPassword", "dap.protectedPassword",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_dap_algorithmIdentifier,
{ "algorithmIdentifier", "dap.algorithmIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_encrypted,
{ "encrypted", "dap.encrypted",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_dap_bind_token,
{ "bind-token", "dap.bind_token_element",
FT_NONE, BASE_NONE, NULL, 0,
"Token", HFILL }},
{ &hf_dap_req,
{ "req", "dap.req_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_rep,
{ "rep", "dap.rep_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_mechanism,
{ "mechanism", "dap.mechanism",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
"DirectoryString", HFILL }},
{ &hf_dap_saslCredentials,
{ "credentials", "dap.credentials",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_dap_saslAbort,
{ "saslAbort", "dap.saslAbort",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_algorithm,
{ "algorithm", "dap.algorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_dap_utctime,
{ "time", "dap.time",
FT_STRING, BASE_NONE, NULL, 0,
"UTCTime", HFILL }},
{ &hf_dap_bindIntAlgorithm,
{ "bindIntAlgorithm", "dap.bindIntAlgorithm",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_AlgorithmIdentifier", HFILL }},
{ &hf_dap_bindIntAlgorithm_item,
{ "AlgorithmIdentifier", "dap.AlgorithmIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_bindIntKeyInfo,
{ "bindIntKeyInfo", "dap.bindIntKeyInfo",
FT_BYTES, BASE_NONE, NULL, 0,
"BindKeyInfo", HFILL }},
{ &hf_dap_bindConfAlgorithm,
{ "bindConfAlgorithm", "dap.bindConfAlgorithm",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_AlgorithmIdentifier", HFILL }},
{ &hf_dap_bindConfAlgorithm_item,
{ "AlgorithmIdentifier", "dap.AlgorithmIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_bindConfKeyInfo,
{ "bindConfKeyInfo", "dap.bindConfKeyInfo",
FT_BYTES, BASE_NONE, NULL, 0,
"BindKeyInfo", HFILL }},
{ &hf_dap_token_data,
{ "token-data", "dap.token_data_element",
FT_NONE, BASE_NONE, NULL, 0,
"TokenData", HFILL }},
{ &hf_dap_algorithm_identifier,
{ "algorithm-identifier", "dap.algorithm_identifier_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_dap_unsignedDirectoryBindError,
{ "unsignedDirectoryBindError", "dap.unsignedDirectoryBindError_element",
FT_NONE, BASE_NONE, NULL, 0,
"DirectoryBindErrorData", HFILL }},
{ &hf_dap_signedDirectoryBindError,
{ "signedDirectoryBindError", "dap.signedDirectoryBindError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_directoryBindError,
{ "directoryBindError", "dap.directoryBindError_element",
FT_NONE, BASE_NONE, NULL, 0,
"DirectoryBindErrorData", HFILL }},
{ &hf_dap_error,
{ "error", "dap.error",
FT_UINT32, BASE_DEC, VALS(dap_T_error_vals), 0,
NULL, HFILL }},
{ &hf_dap_serviceProblem,
{ "serviceError", "dap.serviceError",
FT_INT32, BASE_DEC, VALS(dap_ServiceProblem_vals), 0,
"ServiceProblem", HFILL }},
{ &hf_dap_securityProblem,
{ "securityError", "dap.securityError",
FT_INT32, BASE_DEC, VALS(dap_SecurityProblem_vals), 0,
"SecurityProblem", HFILL }},
{ &hf_dap_securityParameters,
{ "securityParameters", "dap.securityParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_object,
{ "object", "dap.object",
FT_UINT32, BASE_DEC, VALS(x509if_Name_vals), 0,
"Name", HFILL }},
{ &hf_dap_selection,
{ "selection", "dap.selection_element",
FT_NONE, BASE_NONE, NULL, 0,
"EntryInformationSelection", HFILL }},
{ &hf_dap_modifyRightsRequest,
{ "modifyRightsRequest", "dap.modifyRightsRequest",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_serviceControls,
{ "serviceControls", "dap.serviceControls_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_requestor,
{ "requestor", "dap.requestor",
FT_UINT32, BASE_DEC, NULL, 0,
"DistinguishedName", HFILL }},
{ &hf_dap_operationProgress,
{ "operationProgress", "dap.operationProgress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_aliasedRDNs,
{ "aliasedRDNs", "dap.aliasedRDNs",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dap_criticalExtensions,
{ "criticalExtensions", "dap.criticalExtensions",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_dap_referenceType,
{ "referenceType", "dap.referenceType",
FT_UINT32, BASE_DEC, VALS(dsp_ReferenceType_vals), 0,
NULL, HFILL }},
{ &hf_dap_entryOnly,
{ "entryOnly", "dap.entryOnly",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_exclusions,
{ "exclusions", "dap.exclusions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dap_nameResolveOnMaster,
{ "nameResolveOnMaster", "dap.nameResolveOnMaster",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_operationContexts,
{ "operationContexts", "dap.operationContexts",
FT_UINT32, BASE_DEC, VALS(dap_ContextSelection_vals), 0,
"ContextSelection", HFILL }},
{ &hf_dap_familyGrouping,
{ "familyGrouping", "dap.familyGrouping",
FT_UINT32, BASE_DEC, VALS(dap_FamilyGrouping_vals), 0,
NULL, HFILL }},
{ &hf_dap_rdnSequence,
{ "rdnSequence", "dap.rdnSequence",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dap_unsignedReadArgument,
{ "unsignedReadArgument", "dap.unsignedReadArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReadArgumentData", HFILL }},
{ &hf_dap_signedReadArgument,
{ "signedReadArgument", "dap.signedReadArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_readArgument,
{ "readArgument", "dap.readArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReadArgumentData", HFILL }},
{ &hf_dap_entry,
{ "entry", "dap.entry_element",
FT_NONE, BASE_NONE, NULL, 0,
"EntryInformation", HFILL }},
{ &hf_dap_modifyRights,
{ "modifyRights", "dap.modifyRights",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dap_performer,
{ "performer", "dap.performer",
FT_UINT32, BASE_DEC, NULL, 0,
"DistinguishedName", HFILL }},
{ &hf_dap_aliasDereferenced,
{ "aliasDereferenced", "dap.aliasDereferenced",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_notification,
{ "notification", "dap.notification",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_Attribute", HFILL }},
{ &hf_dap_notification_item,
{ "Attribute", "dap.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_unsignedReadResult,
{ "unsignedReadResult", "dap.unsignedReadResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReadResultData", HFILL }},
{ &hf_dap_signedReadResult,
{ "signedReadResult", "dap.signedReadResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_readResult,
{ "readResult", "dap.readResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReadResultData", HFILL }},
{ &hf_dap_ModifyRights_item,
{ "ModifyRights item", "dap.ModifyRights_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_item,
{ "item", "dap.item",
FT_UINT32, BASE_DEC, VALS(dap_T_item_vals), 0,
NULL, HFILL }},
{ &hf_dap_item_entry,
{ "entry", "dap.entry_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_attribute_type,
{ "attribute", "dap.attribute",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_dap_value_assertion,
{ "value", "dap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeValueAssertion", HFILL }},
{ &hf_dap_permission,
{ "permission", "dap.permission",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_purported,
{ "purported", "dap.purported_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeValueAssertion", HFILL }},
{ &hf_dap_unsignedCompareArgument,
{ "unsignedCompareArgument", "dap.unsignedCompareArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"CompareArgumentData", HFILL }},
{ &hf_dap_signedCompareArgument,
{ "signedCompareArgument", "dap.signedCompareArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_compareArgument,
{ "compareArgument", "dap.compareArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"CompareArgumentData", HFILL }},
{ &hf_dap_matched,
{ "matched", "dap.matched",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_matchedSubtype,
{ "matchedSubtype", "dap.matchedSubtype",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_dap_unsignedCompareResult,
{ "unsignedCompareResult", "dap.unsignedCompareResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"CompareResultData", HFILL }},
{ &hf_dap_signedCompareResult,
{ "signedCompareResult", "dap.signedCompareResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_compareResult,
{ "compareResult", "dap.compareResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"CompareResultData", HFILL }},
{ &hf_dap_invokeID,
{ "invokeID", "dap.invokeID",
FT_UINT32, BASE_DEC, VALS(ros_InvokeId_vals), 0,
NULL, HFILL }},
{ &hf_dap_unsignedAbandonArgument,
{ "unsignedAbandonArgument", "dap.unsignedAbandonArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"AbandonArgumentData", HFILL }},
{ &hf_dap_signedAbandonArgument,
{ "signedAbandonArgument", "dap.signedAbandonArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_abandonArgument,
{ "abandonArgument", "dap.abandonArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"AbandonArgumentData", HFILL }},
{ &hf_dap_null,
{ "null", "dap.null_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_abandon_information,
{ "information", "dap.information",
FT_UINT32, BASE_DEC, VALS(dap_AbandonInformation_vals), 0,
"AbandonInformation", HFILL }},
{ &hf_dap_unsignedAbandonResult,
{ "unsignedAbandonResult", "dap.unsignedAbandonResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"AbandonResultData", HFILL }},
{ &hf_dap_signedAbandonResult,
{ "signedAbandonResult", "dap.signedAbandonResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_abandonResult,
{ "abandonResult", "dap.abandonResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"AbandonResultData", HFILL }},
{ &hf_dap_pagedResults,
{ "pagedResults", "dap.pagedResults",
FT_UINT32, BASE_DEC, VALS(dap_PagedResultsRequest_vals), 0,
"PagedResultsRequest", HFILL }},
{ &hf_dap_listFamily,
{ "listFamily", "dap.listFamily",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_unsignedListArgument,
{ "unsignedListArgument", "dap.unsignedListArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ListArgumentData", HFILL }},
{ &hf_dap_signedListArgument,
{ "signedListArgument", "dap.signedListArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_listArgument,
{ "listArgument", "dap.listArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ListArgumentData", HFILL }},
{ &hf_dap_listInfo,
{ "listInfo", "dap.listInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_subordinates,
{ "subordinates", "dap.subordinates",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dap_subordinates_item,
{ "subordinates item", "dap.subordinates_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_aliasEntry,
{ "aliasEntry", "dap.aliasEntry",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_partialOutcomeQualifier,
{ "partialOutcomeQualifier", "dap.partialOutcomeQualifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_uncorrelatedListInfo,
{ "uncorrelatedListInfo", "dap.uncorrelatedListInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ListResult", HFILL }},
{ &hf_dap_uncorrelatedListInfo_item,
{ "ListResult", "dap.ListResult",
FT_UINT32, BASE_DEC, VALS(dap_ListResult_vals), 0,
NULL, HFILL }},
{ &hf_dap_unsignedListResult,
{ "unsignedListResult", "dap.unsignedListResult",
FT_UINT32, BASE_DEC, VALS(dap_ListResultData_vals), 0,
"ListResultData", HFILL }},
{ &hf_dap_signedListResult,
{ "signedListResult", "dap.signedListResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_listResult,
{ "listResult", "dap.listResult",
FT_UINT32, BASE_DEC, VALS(dap_ListResultData_vals), 0,
"ListResultData", HFILL }},
{ &hf_dap_limitProblem,
{ "limitProblem", "dap.limitProblem",
FT_INT32, BASE_DEC, VALS(dap_LimitProblem_vals), 0,
NULL, HFILL }},
{ &hf_dap_unexplored,
{ "unexplored", "dap.unexplored",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_MAX_OF_ContinuationReference", HFILL }},
{ &hf_dap_unexplored_item,
{ "ContinuationReference", "dap.ContinuationReference_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_unavailableCriticalExtensions,
{ "unavailableCriticalExtensions", "dap.unavailableCriticalExtensions",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_unknownErrors,
{ "unknownErrors", "dap.unknownErrors",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dap_unknownErrors_item,
{ "unknownErrors item", "dap.unknownErrors_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_dap_queryReference,
{ "queryReference", "dap.queryReference",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_dap_overspecFilter,
{ "overspecFilter", "dap.overspecFilter",
FT_UINT32, BASE_DEC, VALS(dap_Filter_vals), 0,
"Filter", HFILL }},
{ &hf_dap_entryCount,
{ "entryCount", "dap.entryCount",
FT_UINT32, BASE_DEC, VALS(dap_T_entryCount_vals), 0,
NULL, HFILL }},
{ &hf_dap_bestEstimate,
{ "bestEstimate", "dap.bestEstimate",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dap_lowEstimate,
{ "lowEstimate", "dap.lowEstimate",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dap_exact,
{ "exact", "dap.exact",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dap_streamedResult,
{ "streamedResult", "dap.streamedResult",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_baseObject,
{ "baseObject", "dap.baseObject",
FT_UINT32, BASE_DEC, VALS(x509if_Name_vals), 0,
"Name", HFILL }},
{ &hf_dap_subset,
{ "subset", "dap.subset",
FT_INT32, BASE_DEC, VALS(dap_T_subset_vals), 0,
NULL, HFILL }},
{ &hf_dap_filter,
{ "filter", "dap.filter",
FT_UINT32, BASE_DEC, VALS(dap_Filter_vals), 0,
NULL, HFILL }},
{ &hf_dap_searchAliases,
{ "searchAliases", "dap.searchAliases",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_matchedValuesOnly,
{ "matchedValuesOnly", "dap.matchedValuesOnly",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_extendedFilter,
{ "extendedFilter", "dap.extendedFilter",
FT_UINT32, BASE_DEC, VALS(dap_Filter_vals), 0,
"Filter", HFILL }},
{ &hf_dap_checkOverspecified,
{ "checkOverspecified", "dap.checkOverspecified",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_relaxation,
{ "relaxation", "dap.relaxation_element",
FT_NONE, BASE_NONE, NULL, 0,
"RelaxationPolicy", HFILL }},
{ &hf_dap_extendedArea,
{ "extendedArea", "dap.extendedArea",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dap_hierarchySelections,
{ "hierarchySelections", "dap.hierarchySelections",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_searchControlOptions,
{ "searchControlOptions", "dap.searchControlOptions",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_joinArguments,
{ "joinArguments", "dap.joinArguments",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_JoinArgument", HFILL }},
{ &hf_dap_joinArguments_item,
{ "JoinArgument", "dap.JoinArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_joinType,
{ "joinType", "dap.joinType",
FT_UINT32, BASE_DEC, VALS(dap_T_joinType_vals), 0,
NULL, HFILL }},
{ &hf_dap_unsignedSearchArgument,
{ "unsignedSearchArgument", "dap.unsignedSearchArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"SearchArgumentData", HFILL }},
{ &hf_dap_signedSearchArgument,
{ "signedSearchArgument", "dap.signedSearchArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_searchArgument,
{ "searchArgument", "dap.searchArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"SearchArgumentData", HFILL }},
{ &hf_dap_joinBaseObject,
{ "joinBaseObject", "dap.joinBaseObject",
FT_UINT32, BASE_DEC, VALS(x509if_Name_vals), 0,
"Name", HFILL }},
{ &hf_dap_domainLocalID,
{ "domainLocalID", "dap.domainLocalID",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
NULL, HFILL }},
{ &hf_dap_joinSubset,
{ "joinSubset", "dap.joinSubset",
FT_UINT32, BASE_DEC, VALS(dap_T_joinSubset_vals), 0,
NULL, HFILL }},
{ &hf_dap_joinFilter,
{ "joinFilter", "dap.joinFilter",
FT_UINT32, BASE_DEC, VALS(dap_Filter_vals), 0,
"Filter", HFILL }},
{ &hf_dap_joinAttributes,
{ "joinAttributes", "dap.joinAttributes",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_JoinAttPair", HFILL }},
{ &hf_dap_joinAttributes_item,
{ "JoinAttPair", "dap.JoinAttPair_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_joinSelection,
{ "joinSelection", "dap.joinSelection_element",
FT_NONE, BASE_NONE, NULL, 0,
"EntryInformationSelection", HFILL }},
{ &hf_dap_baseAtt,
{ "baseAtt", "dap.baseAtt",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_dap_joinAtt,
{ "joinAtt", "dap.joinAtt",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_dap_joinContext,
{ "joinContext", "dap.joinContext",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_JoinContextType", HFILL }},
{ &hf_dap_joinContext_item,
{ "JoinContextType", "dap.JoinContextType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_searchInfo,
{ "searchInfo", "dap.searchInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_entries,
{ "entries", "dap.entries",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_EntryInformation", HFILL }},
{ &hf_dap_entries_item,
{ "EntryInformation", "dap.EntryInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_altMatching,
{ "altMatching", "dap.altMatching",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_uncorrelatedSearchInfo,
{ "uncorrelatedSearchInfo", "dap.uncorrelatedSearchInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_SearchResult", HFILL }},
{ &hf_dap_uncorrelatedSearchInfo_item,
{ "SearchResult", "dap.SearchResult",
FT_UINT32, BASE_DEC, VALS(dap_SearchResult_vals), 0,
NULL, HFILL }},
{ &hf_dap_unsignedSearchResult,
{ "unsignedSearchResult", "dap.unsignedSearchResult",
FT_UINT32, BASE_DEC, VALS(dap_SearchResultData_vals), 0,
"SearchResultData", HFILL }},
{ &hf_dap_signedSearchResult,
{ "signedSearchResult", "dap.signedSearchResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_searchResult,
{ "searchResult", "dap.searchResult",
FT_UINT32, BASE_DEC, VALS(dap_SearchResultData_vals), 0,
"SearchResultData", HFILL }},
{ &hf_dap_add_entry,
{ "entry", "dap.entry",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Attribute", HFILL }},
{ &hf_dap_add_entry_item,
{ "Attribute", "dap.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_targetSystem,
{ "targetSystem", "dap.targetSystem_element",
FT_NONE, BASE_NONE, NULL, 0,
"AccessPoint", HFILL }},
{ &hf_dap_unsignedAddEntryArgument,
{ "unsignedAddEntryArgument", "dap.unsignedAddEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"AddEntryArgumentData", HFILL }},
{ &hf_dap_signedAddEntryArgument,
{ "signedAddEntryArgument", "dap.signedAddEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_addEntryArgument,
{ "addEntryArgument", "dap.addEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"AddEntryArgumentData", HFILL }},
{ &hf_dap_add_entry_information,
{ "information", "dap.information",
FT_UINT32, BASE_DEC, VALS(dap_AddEntryInformation_vals), 0,
"AddEntryInformation", HFILL }},
{ &hf_dap_unsignedAddEntryResult,
{ "unsignedAddEntryResult", "dap.unsignedAddEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"AddEntryResultData", HFILL }},
{ &hf_dap_signedAddEntryResult,
{ "signedAddEntryResult", "dap.signedAddEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_addEntryResult,
{ "addEntryResult", "dap.addEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"AddEntryResultData", HFILL }},
{ &hf_dap_unsignedRemoveEntryArgument,
{ "unsignedRemoveEntryArgument", "dap.unsignedRemoveEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"RemoveEntryArgumentData", HFILL }},
{ &hf_dap_signedRemoveEntryArgument,
{ "signedRemoveEntryArgument", "dap.signedRemoveEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_removeEntryArgument,
{ "removeEntryArgument", "dap.removeEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"RemoveEntryArgumentData", HFILL }},
{ &hf_dap_remove_entry_information,
{ "information", "dap.information",
FT_UINT32, BASE_DEC, VALS(dap_RemoveEntryInformation_vals), 0,
"RemoveEntryInformation", HFILL }},
{ &hf_dap_unsignedRemoveEntryResult,
{ "unsignedRemoveEntryResult", "dap.unsignedRemoveEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"RemoveEntryResultData", HFILL }},
{ &hf_dap_signedRemoveEntryResult,
{ "signedRemoveEntryResult", "dap.signedRemoveEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_removeEntryResult,
{ "removeEntryResult", "dap.removeEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"RemoveEntryResultData", HFILL }},
{ &hf_dap_changes,
{ "changes", "dap.changes",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_EntryModification", HFILL }},
{ &hf_dap_changes_item,
{ "EntryModification", "dap.EntryModification",
FT_UINT32, BASE_DEC, VALS(dap_EntryModification_vals), 0,
NULL, HFILL }},
{ &hf_dap_unsignedModifyEntryArgument,
{ "unsignedModifyEntryArgument", "dap.unsignedModifyEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModifyEntryArgumentData", HFILL }},
{ &hf_dap_signedModifyEntryArgument,
{ "signedModifyEntryArgument", "dap.signedModifyEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_modifyEntryArgument,
{ "modifyEntryArgument", "dap.modifyEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModifyEntryArgumentData", HFILL }},
{ &hf_dap_modify_entry_information,
{ "information", "dap.information",
FT_UINT32, BASE_DEC, VALS(dap_ModifyEntryInformation_vals), 0,
"ModifyEntryInformation", HFILL }},
{ &hf_dap_unsignedModifyEntryResult,
{ "unsignedModifyEntryResult", "dap.unsignedModifyEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModifyEntryResultData", HFILL }},
{ &hf_dap_signedModifyEntryResult,
{ "signedModifyEntryResult", "dap.signedModifyEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_modifyEntryResult,
{ "modifyEntryResult", "dap.modifyEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModifyEntryResultData", HFILL }},
{ &hf_dap_addAttribute,
{ "addAttribute", "dap.addAttribute_element",
FT_NONE, BASE_NONE, NULL, 0,
"Attribute", HFILL }},
{ &hf_dap_removeAttribute,
{ "removeAttribute", "dap.removeAttribute",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_dap_addValues,
{ "addValues", "dap.addValues_element",
FT_NONE, BASE_NONE, NULL, 0,
"Attribute", HFILL }},
{ &hf_dap_removeValues,
{ "removeValues", "dap.removeValues_element",
FT_NONE, BASE_NONE, NULL, 0,
"Attribute", HFILL }},
{ &hf_dap_alterValues,
{ "alterValues", "dap.alterValues_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeTypeAndValue", HFILL }},
{ &hf_dap_resetValue,
{ "resetValue", "dap.resetValue",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_dap_newRDN,
{ "newRDN", "dap.newRDN",
FT_UINT32, BASE_DEC, NULL, 0,
"RelativeDistinguishedName", HFILL }},
{ &hf_dap_deleteOldRDN,
{ "deleteOldRDN", "dap.deleteOldRDN",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dap_newSuperior,
{ "newSuperior", "dap.newSuperior",
FT_UINT32, BASE_DEC, NULL, 0,
"DistinguishedName", HFILL }},
{ &hf_dap_modify_dn_information,
{ "information", "dap.information",
FT_UINT32, BASE_DEC, VALS(dap_ModifyDNInformation_vals), 0,
"ModifyDNInformation", HFILL }},
{ &hf_dap_unsignedModifyDNResult,
{ "unsignedModifyDNResult", "dap.unsignedModifyDNResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModifyDNResultData", HFILL }},
{ &hf_dap_signedModifyDNResult,
{ "signedModifyDNResult", "dap.signedModifyDNResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_modifyDNResult,
{ "modifyDNResult", "dap.modifyDNResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModifyDNResultData", HFILL }},
{ &hf_dap_unsignedAbandoned,
{ "unsignedAbandoned", "dap.unsignedAbandoned_element",
FT_NONE, BASE_NONE, NULL, 0,
"AbandonedData", HFILL }},
{ &hf_dap_signedAbandoned,
{ "signedAbandoned", "dap.signedAbandoned_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_abandoned,
{ "abandoned", "dap.abandoned_element",
FT_NONE, BASE_NONE, NULL, 0,
"AbandonedData", HFILL }},
{ &hf_dap_abandon_failed_problem,
{ "problem", "dap.problem",
FT_INT32, BASE_DEC, VALS(dap_AbandonProblem_vals), 0,
"AbandonProblem", HFILL }},
{ &hf_dap_operation,
{ "operation", "dap.operation",
FT_UINT32, BASE_DEC, VALS(ros_InvokeId_vals), 0,
"InvokeId", HFILL }},
{ &hf_dap_unsignedAbandonFailedError,
{ "unsignedAbandonFailedError", "dap.unsignedAbandonFailedError_element",
FT_NONE, BASE_NONE, NULL, 0,
"AbandonFailedErrorData", HFILL }},
{ &hf_dap_signedAbandonFailedError,
{ "signedAbandonFailedError", "dap.signedAbandonFailedError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_abandonFailedError,
{ "abandonFailedError", "dap.abandonFailedError_element",
FT_NONE, BASE_NONE, NULL, 0,
"AbandonFailedErrorData", HFILL }},
{ &hf_dap_problems,
{ "problems", "dap.problems",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dap_problems_item,
{ "problems item", "dap.problems_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_attribute_error_problem,
{ "problem", "dap.problem",
FT_INT32, BASE_DEC, VALS(dap_AttributeProblem_vals), 0,
"AttributeProblem", HFILL }},
{ &hf_dap_value,
{ "value", "dap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeValue", HFILL }},
{ &hf_dap_unsignedAttributeError,
{ "unsignedAttributeError", "dap.unsignedAttributeError_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeErrorData", HFILL }},
{ &hf_dap_signedAttributeError,
{ "signedAttributeError", "dap.signedAttributeError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_attributeError,
{ "attributeError", "dap.attributeError_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeErrorData", HFILL }},
{ &hf_dap_name_error_problem,
{ "problem", "dap.problem",
FT_INT32, BASE_DEC, VALS(dap_NameProblem_vals), 0,
"NameProblem", HFILL }},
{ &hf_dap_matched_name,
{ "matched", "dap.matched",
FT_UINT32, BASE_DEC, VALS(x509if_Name_vals), 0,
"Name", HFILL }},
{ &hf_dap_unsignedNameError,
{ "unsignedNameError", "dap.unsignedNameError_element",
FT_NONE, BASE_NONE, NULL, 0,
"NameErrorData", HFILL }},
{ &hf_dap_signedNameError,
{ "signedNameError", "dap.signedNameError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_nameError,
{ "nameError", "dap.nameError_element",
FT_NONE, BASE_NONE, NULL, 0,
"NameErrorData", HFILL }},
{ &hf_dap_candidate,
{ "candidate", "dap.candidate_element",
FT_NONE, BASE_NONE, NULL, 0,
"ContinuationReference", HFILL }},
{ &hf_dap_unsignedReferral,
{ "unsignedReferral", "dap.unsignedReferral_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReferralData", HFILL }},
{ &hf_dap_signedReferral,
{ "signedReferral", "dap.signedReferral_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_referral,
{ "referral", "dap.referral_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReferralData", HFILL }},
{ &hf_dap_security_error_problem,
{ "problem", "dap.problem",
FT_INT32, BASE_DEC, VALS(dap_SecurityProblem_vals), 0,
"SecurityProblem", HFILL }},
{ &hf_dap_spkmInfo,
{ "spkmInfo", "dap.spkmInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_unsignedSecurityError,
{ "unsignedSecurityError", "dap.unsignedSecurityError_element",
FT_NONE, BASE_NONE, NULL, 0,
"SecurityErrorData", HFILL }},
{ &hf_dap_signedSecurityError,
{ "signedSecurityError", "dap.signedSecurityError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_securityErrorData,
{ "securityError", "dap.securityError_element",
FT_NONE, BASE_NONE, NULL, 0,
"SecurityErrorData", HFILL }},
{ &hf_dap_service_error_problem,
{ "problem", "dap.problem",
FT_INT32, BASE_DEC, VALS(dap_ServiceProblem_vals), 0,
"ServiceProblem", HFILL }},
{ &hf_dap_unsignedServiceError,
{ "unsignedServiceError", "dap.unsignedServiceError_element",
FT_NONE, BASE_NONE, NULL, 0,
"ServiceErrorData", HFILL }},
{ &hf_dap_signedServiceError,
{ "signedServiceError", "dap.signedServiceError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_serviceError,
{ "serviceError", "dap.serviceError_element",
FT_NONE, BASE_NONE, NULL, 0,
"ServiceErrorData", HFILL }},
{ &hf_dap_update_error_problem,
{ "problem", "dap.problem",
FT_INT32, BASE_DEC, VALS(dap_UpdateProblem_vals), 0,
"UpdateProblem", HFILL }},
{ &hf_dap_attributeInfo,
{ "attributeInfo", "dap.attributeInfo",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dap_attributeInfo_item,
{ "attributeInfo item", "dap.attributeInfo_item",
FT_UINT32, BASE_DEC, VALS(dap_T_attributeInfo_item_vals), 0,
NULL, HFILL }},
{ &hf_dap_unsignedUpdateError,
{ "unsignedUpdateError", "dap.unsignedUpdateError_element",
FT_NONE, BASE_NONE, NULL, 0,
"UpdateErrorData", HFILL }},
{ &hf_dap_signedUpdateError,
{ "signedUpdateError", "dap.signedUpdateError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dap_updateError,
{ "updateError", "dap.updateError_element",
FT_NONE, BASE_NONE, NULL, 0,
"UpdateErrorData", HFILL }},
{ &hf_dap_ServiceControlOptions_preferChaining,
{ "preferChaining", "dap.preferChaining",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_dap_ServiceControlOptions_chainingProhibited,
{ "chainingProhibited", "dap.chainingProhibited",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_dap_ServiceControlOptions_localScope,
{ "localScope", "dap.localScope",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_dap_ServiceControlOptions_dontUseCopy,
{ "dontUseCopy", "dap.dontUseCopy",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_dap_ServiceControlOptions_dontDereferenceAliases,
{ "dontDereferenceAliases", "dap.dontDereferenceAliases",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_dap_ServiceControlOptions_subentries,
{ "subentries", "dap.subentries",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_dap_ServiceControlOptions_copyShallDo,
{ "copyShallDo", "dap.copyShallDo",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_dap_ServiceControlOptions_partialNameResolution,
{ "partialNameResolution", "dap.partialNameResolution",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_dap_ServiceControlOptions_manageDSAIT,
{ "manageDSAIT", "dap.manageDSAIT",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_dap_ServiceControlOptions_noSubtypeMatch,
{ "noSubtypeMatch", "dap.noSubtypeMatch",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_dap_ServiceControlOptions_noSubtypeSelection,
{ "noSubtypeSelection", "dap.noSubtypeSelection",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_dap_ServiceControlOptions_countFamily,
{ "countFamily", "dap.countFamily",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_dap_ServiceControlOptions_dontSelectFriends,
{ "dontSelectFriends", "dap.dontSelectFriends",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_dap_ServiceControlOptions_dontMatchFriends,
{ "dontMatchFriends", "dap.dontMatchFriends",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_dap_Versions_v1,
{ "v1", "dap.v1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_dap_Versions_v2,
{ "v2", "dap.v2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_dap_T_permission_add,
{ "add", "dap.add",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_dap_T_permission_remove,
{ "remove", "dap.remove",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_dap_T_permission_rename,
{ "rename", "dap.rename",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_dap_T_permission_move,
{ "move", "dap.move",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_dap_HierarchySelections_self,
{ "self", "dap.self",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_dap_HierarchySelections_children,
{ "children", "dap.children",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_dap_HierarchySelections_parent,
{ "parent", "dap.parent",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_dap_HierarchySelections_hierarchy,
{ "hierarchy", "dap.hierarchy",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_dap_HierarchySelections_top,
{ "top", "dap.top",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_dap_HierarchySelections_subtree,
{ "subtree", "dap.subtree",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_dap_HierarchySelections_siblings,
{ "siblings", "dap.siblings",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_dap_HierarchySelections_siblingChildren,
{ "siblingChildren", "dap.siblingChildren",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_dap_HierarchySelections_siblingSubtree,
{ "siblingSubtree", "dap.siblingSubtree",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_dap_HierarchySelections_all,
{ "all", "dap.all",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_dap_SearchControlOptions_searchAliases,
{ "searchAliases", "dap.searchAliases",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_dap_SearchControlOptions_matchedValuesOnly,
{ "matchedValuesOnly", "dap.matchedValuesOnly",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_dap_SearchControlOptions_checkOverspecified,
{ "checkOverspecified", "dap.checkOverspecified",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_dap_SearchControlOptions_performExactly,
{ "performExactly", "dap.performExactly",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_dap_SearchControlOptions_includeAllAreas,
{ "includeAllAreas", "dap.includeAllAreas",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_dap_SearchControlOptions_noSystemRelaxation,
{ "noSystemRelaxation", "dap.noSystemRelaxation",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_dap_SearchControlOptions_dnAttribute,
{ "dnAttribute", "dap.dnAttribute",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_dap_SearchControlOptions_matchOnResidualName,
{ "matchOnResidualName", "dap.matchOnResidualName",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_dap_SearchControlOptions_entryCount,
{ "entryCount", "dap.entryCount",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_dap_SearchControlOptions_useSubset,
{ "useSubset", "dap.useSubset",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_dap_SearchControlOptions_separateFamilyMembers,
{ "separateFamilyMembers", "dap.separateFamilyMembers",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_dap_SearchControlOptions_searchFamily,
{ "searchFamily", "dap.searchFamily",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
#line 97 "../../asn1/dap/packet-dap-template.c"
};
static gint *ett[] = {
&ett_dap,
#line 1 "../../asn1/dap/packet-dap-ettarr.c"
&ett_dap_ServiceControls,
&ett_dap_T_manageDSAITPlaneRef,
&ett_dap_ServiceControlOptions,
&ett_dap_EntryInformationSelection,
&ett_dap_T_attributes,
&ett_dap_SET_OF_AttributeType,
&ett_dap_T_extraAttributes,
&ett_dap_SET_SIZE_1_MAX_OF_AttributeType,
&ett_dap_ContextSelection,
&ett_dap_SET_SIZE_1_MAX_OF_TypeAndContextAssertion,
&ett_dap_TypeAndContextAssertion,
&ett_dap_T_contextAssertions,
&ett_dap_SEQUENCE_OF_ContextAssertion,
&ett_dap_SET_OF_ContextAssertion,
&ett_dap_FamilyReturn,
&ett_dap_T_familySelect,
&ett_dap_EntryInformation,
&ett_dap_T_entry_information,
&ett_dap_EntryInformationItem,
&ett_dap_FamilyEntries,
&ett_dap_SEQUENCE_OF_FamilyEntry,
&ett_dap_FamilyEntry,
&ett_dap_FamilyInformation,
&ett_dap_T_family_information_item,
&ett_dap_SEQUENCE_SIZE_1_MAX_OF_FamilyEntries,
&ett_dap_Filter,
&ett_dap_SetOfFilter,
&ett_dap_FilterItem,
&ett_dap_T_substrings,
&ett_dap_T_strings,
&ett_dap_T_strings_item,
&ett_dap_MatchingRuleAssertion,
&ett_dap_T_matchingRule,
&ett_dap_PagedResultsRequest,
&ett_dap_T_newRequest,
&ett_dap_SEQUENCE_SIZE_1_MAX_OF_SortKey,
&ett_dap_SortKey,
&ett_dap_SecurityParameters,
&ett_dap_Time,
&ett_dap_DirectoryBindArgument,
&ett_dap_Credentials,
&ett_dap_SimpleCredentials,
&ett_dap_T_validity,
&ett_dap_T_time1,
&ett_dap_T_time2,
&ett_dap_T_password,
&ett_dap_T_protected,
&ett_dap_StrongCredentials,
&ett_dap_SpkmCredentials,
&ett_dap_SaslCredentials,
&ett_dap_TokenData,
&ett_dap_SEQUENCE_SIZE_1_MAX_OF_AlgorithmIdentifier,
&ett_dap_Token,
&ett_dap_Versions,
&ett_dap_DirectoryBindError,
&ett_dap_T_signedDirectoryBindError,
&ett_dap_DirectoryBindErrorData,
&ett_dap_T_error,
&ett_dap_ReadArgumentData,
&ett_dap_Name,
&ett_dap_ReadArgument,
&ett_dap_T_signedReadArgument,
&ett_dap_ReadResultData,
&ett_dap_SEQUENCE_SIZE_1_MAX_OF_Attribute,
&ett_dap_ReadResult,
&ett_dap_T_signedReadResult,
&ett_dap_ModifyRights,
&ett_dap_ModifyRights_item,
&ett_dap_T_item,
&ett_dap_T_permission,
&ett_dap_CompareArgumentData,
&ett_dap_CompareArgument,
&ett_dap_T_signedCompareArgument,
&ett_dap_CompareResultData,
&ett_dap_CompareResult,
&ett_dap_T_signedCompareResult,
&ett_dap_AbandonArgumentData,
&ett_dap_AbandonArgument,
&ett_dap_T_signedAbandonArgument,
&ett_dap_AbandonResultData,
&ett_dap_AbandonResult,
&ett_dap_AbandonInformation,
&ett_dap_T_signedAbandonResult,
&ett_dap_ListArgumentData,
&ett_dap_ListArgument,
&ett_dap_T_signedListArgument,
&ett_dap_ListResultData,
&ett_dap_T_listInfo,
&ett_dap_T_subordinates,
&ett_dap_T_subordinates_item,
&ett_dap_SET_OF_ListResult,
&ett_dap_ListResult,
&ett_dap_T_signedListResult,
&ett_dap_PartialOutcomeQualifier,
&ett_dap_SET_SIZE_1_MAX_OF_ContinuationReference,
&ett_dap_T_unknownErrors,
&ett_dap_T_entryCount,
&ett_dap_SearchArgumentData,
&ett_dap_SEQUENCE_SIZE_1_MAX_OF_JoinArgument,
&ett_dap_SearchArgument,
&ett_dap_T_signedSearchArgument,
&ett_dap_HierarchySelections,
&ett_dap_SearchControlOptions,
&ett_dap_JoinArgument,
&ett_dap_SEQUENCE_SIZE_1_MAX_OF_JoinAttPair,
&ett_dap_JoinAttPair,
&ett_dap_SEQUENCE_SIZE_1_MAX_OF_JoinContextType,
&ett_dap_SearchResultData,
&ett_dap_T_searchInfo,
&ett_dap_SET_OF_EntryInformation,
&ett_dap_SET_OF_SearchResult,
&ett_dap_SearchResult,
&ett_dap_T_signedSearchResult,
&ett_dap_AddEntryArgumentData,
&ett_dap_SET_OF_Attribute,
&ett_dap_AddEntryArgument,
&ett_dap_T_signedAddEntryArgument,
&ett_dap_AddEntryResultData,
&ett_dap_AddEntryResult,
&ett_dap_AddEntryInformation,
&ett_dap_T_signedAddEntryResult,
&ett_dap_RemoveEntryArgumentData,
&ett_dap_RemoveEntryArgument,
&ett_dap_T_signedRemoveEntryArgument,
&ett_dap_RemoveEntryResultData,
&ett_dap_RemoveEntryResult,
&ett_dap_RemoveEntryInformation,
&ett_dap_T_signedRemoveEntryResult,
&ett_dap_ModifyEntryArgumentData,
&ett_dap_SEQUENCE_OF_EntryModification,
&ett_dap_ModifyEntryArgument,
&ett_dap_T_signedModifyEntryArgument,
&ett_dap_ModifyEntryResultData,
&ett_dap_ModifyEntryResult,
&ett_dap_ModifyEntryInformation,
&ett_dap_T_signedModifyEntryResult,
&ett_dap_EntryModification,
&ett_dap_ModifyDNArgument,
&ett_dap_ModifyDNResultData,
&ett_dap_ModifyDNResult,
&ett_dap_ModifyDNInformation,
&ett_dap_T_signedModifyDNResult,
&ett_dap_AbandonedData,
&ett_dap_Abandoned,
&ett_dap_T_signedAbandoned,
&ett_dap_AbandonFailedErrorData,
&ett_dap_AbandonFailedError,
&ett_dap_T_signedAbandonFailedError,
&ett_dap_AttributeErrorData,
&ett_dap_T_problems,
&ett_dap_T_problems_item,
&ett_dap_AttributeError,
&ett_dap_T_signedAttributeError,
&ett_dap_NameErrorData,
&ett_dap_NameError,
&ett_dap_T_signedNameError,
&ett_dap_ReferralData,
&ett_dap_Referral,
&ett_dap_T_signedReferral,
&ett_dap_SecurityErrorData,
&ett_dap_SecurityError,
&ett_dap_T_signedSecurityError,
&ett_dap_ServiceErrorData,
&ett_dap_ServiceError,
&ett_dap_T_signedServiceError,
&ett_dap_UpdateErrorData,
&ett_dap_T_attributeInfo,
&ett_dap_T_attributeInfo_item,
&ett_dap_UpdateError,
&ett_dap_T_signedUpdateError,
#line 103 "../../asn1/dap/packet-dap-template.c"
};
module_t *dap_module;
proto_dap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_dap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
dap_module = prefs_register_protocol_subtree("OSI/X.500", proto_dap, prefs_register_dap);
prefs_register_uint_preference(dap_module, "tcp.port", "DAP TCP Port",
"Set the port for DAP operations (if other"
" than the default of 102)",
10, &global_dap_tcp_port);
}
void proto_reg_handoff_dap(void) {
oid_add_from_string("id-ac-directory-access","2.5.3.1");
register_ros_protocol_info("2.5.9.1", &dap_ros_info, 0, "id-as-directory-access", FALSE);
register_idmp_protocol_info("2.5.33.0", &dap_ros_info, 0, "dap-ip");
tpkt_handle = find_dissector("tpkt");
x509if_register_fmt(hf_dap_equality, "=");
x509if_register_fmt(hf_dap_greaterOrEqual, ">=");
x509if_register_fmt(hf_dap_lessOrEqual, "<=");
x509if_register_fmt(hf_dap_approximateMatch, "=~");
x509if_register_fmt(hf_dap_present, "= *");
}
static void
prefs_register_dap(void)
{
static guint tcp_port = 0;
if((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_delete_uint("tcp.port", tcp_port, tpkt_handle);
tcp_port = global_dap_tcp_port;
if((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_add_uint("tcp.port", global_dap_tcp_port, tpkt_handle);
}
