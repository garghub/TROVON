static int
dissect_dsp_DSASystemBindArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_dap_DirectoryBindArgument(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_dsp_DSASystemBindResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_dap_DirectoryBindArgument(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_dsp_DSASystemBindError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_dap_DirectoryBindError(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_dsp_T_nameResolutionPhase(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dsp_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_dsp_OperationProgress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
OperationProgress_set, hf_index, ett_dsp_OperationProgress);
return offset;
}
static int
dissect_dsp_TraceItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TraceItem_set, hf_index, ett_dsp_TraceItem);
return offset;
}
static int
dissect_dsp_TraceInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
TraceInformation_sequence_of, hf_index, ett_dsp_TraceInformation);
return offset;
}
static int
dissect_dsp_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
int
dissect_dsp_ReferenceType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dsp_DomainInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_dsp_UTCTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_dsp_GeneralizedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_dsp_Time(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Time_choice, hf_index, ett_dsp_Time,
NULL);
return offset;
}
static int
dissect_dsp_T_level(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dsp_T_basicLevels(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_basicLevels_sequence, hf_index, ett_dsp_T_basicLevels);
return offset;
}
static int
dissect_dsp_EXTERNAL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_external_type(implicit_tag, tree, tvb, offset, actx, hf_index, NULL);
return offset;
}
static int
dissect_dsp_AuthenticationLevel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AuthenticationLevel_choice, hf_index, ett_dsp_AuthenticationLevel,
NULL);
return offset;
}
int
dissect_dsp_Exclusions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
Exclusions_set_of, hf_index, ett_dsp_Exclusions);
return offset;
}
static int
dissect_dsp_T_nonDapPdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dsp_ChainingArguments(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainingArguments_set, hf_index, ett_dsp_ChainingArguments);
return offset;
}
static int
dissect_dsp_ChainedReadArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedReadArgumentData_set, hf_index, ett_dsp_ChainedReadArgumentData);
return offset;
}
static int
dissect_dsp_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_dsp_T_signedChainedReadArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedReadArgument_sequence, hf_index, ett_dsp_T_signedChainedReadArgument);
return offset;
}
static int
dissect_dsp_ChainedReadArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedReadArgument_choice, hf_index, ett_dsp_ChainedReadArgument,
NULL);
return offset;
}
static int
dissect_dsp_SET_OF_ProtocolInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_ProtocolInformation_set_of, hf_index, ett_dsp_SET_OF_ProtocolInformation);
return offset;
}
static int
dissect_dsp_T_category(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dsp_APCategory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_dsp_MasterOrShadowAccessPoint(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MasterOrShadowAccessPoint_set, hf_index, ett_dsp_MasterOrShadowAccessPoint);
return offset;
}
int
dissect_dsp_MasterAndShadowAccessPoints(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
MasterAndShadowAccessPoints_set_of, hf_index, ett_dsp_MasterAndShadowAccessPoints);
return offset;
}
int
dissect_dsp_AccessPointInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AccessPointInformation_set, hf_index, ett_dsp_AccessPointInformation);
return offset;
}
static int
dissect_dsp_CrossReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CrossReference_set, hf_index, ett_dsp_CrossReference);
return offset;
}
static int
dissect_dsp_SEQUENCE_OF_CrossReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_CrossReference_sequence_of, hf_index, ett_dsp_SEQUENCE_OF_CrossReference);
return offset;
}
static int
dissect_dsp_ChainingResults(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainingResults_set, hf_index, ett_dsp_ChainingResults);
return offset;
}
static int
dissect_dsp_ChainedReadResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedReadResultData_set, hf_index, ett_dsp_ChainedReadResultData);
return offset;
}
static int
dissect_dsp_T_signedChainedReadResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedReadResult_sequence, hf_index, ett_dsp_T_signedChainedReadResult);
return offset;
}
static int
dissect_dsp_ChainedReadResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedReadResult_choice, hf_index, ett_dsp_ChainedReadResult,
NULL);
return offset;
}
static int
dissect_dsp_ChainedCompareArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedCompareArgumentData_set, hf_index, ett_dsp_ChainedCompareArgumentData);
return offset;
}
static int
dissect_dsp_T_signedChainedCompareArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedCompareArgument_sequence, hf_index, ett_dsp_T_signedChainedCompareArgument);
return offset;
}
static int
dissect_dsp_ChainedCompareArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedCompareArgument_choice, hf_index, ett_dsp_ChainedCompareArgument,
NULL);
return offset;
}
static int
dissect_dsp_ChainedCompareResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedCompareResultData_set, hf_index, ett_dsp_ChainedCompareResultData);
return offset;
}
static int
dissect_dsp_T_signedChainedCompareResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedCompareResult_sequence, hf_index, ett_dsp_T_signedChainedCompareResult);
return offset;
}
static int
dissect_dsp_ChainedCompareResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedCompareResult_choice, hf_index, ett_dsp_ChainedCompareResult,
NULL);
return offset;
}
static int
dissect_dsp_ChainedAbandonArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_dap_AbandonArgument(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_dsp_ChainedAbandonResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_dap_AbandonResult(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_dsp_ChainedListArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedListArgumentData_set, hf_index, ett_dsp_ChainedListArgumentData);
return offset;
}
static int
dissect_dsp_T_signedChainedListArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedListArgument_sequence, hf_index, ett_dsp_T_signedChainedListArgument);
return offset;
}
static int
dissect_dsp_ChainedListArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedListArgument_choice, hf_index, ett_dsp_ChainedListArgument,
NULL);
return offset;
}
static int
dissect_dsp_ChainedListResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedListResultData_set, hf_index, ett_dsp_ChainedListResultData);
return offset;
}
static int
dissect_dsp_T_signedChainedListResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedListResult_sequence, hf_index, ett_dsp_T_signedChainedListResult);
return offset;
}
static int
dissect_dsp_ChainedListResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedListResult_choice, hf_index, ett_dsp_ChainedListResult,
NULL);
return offset;
}
static int
dissect_dsp_ChainedSearchArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedSearchArgumentData_set, hf_index, ett_dsp_ChainedSearchArgumentData);
return offset;
}
static int
dissect_dsp_T_signedChainedSearchArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedSearchArgument_sequence, hf_index, ett_dsp_T_signedChainedSearchArgument);
return offset;
}
static int
dissect_dsp_ChainedSearchArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedSearchArgument_choice, hf_index, ett_dsp_ChainedSearchArgument,
NULL);
return offset;
}
static int
dissect_dsp_ChainedSearchResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedSearchResultData_set, hf_index, ett_dsp_ChainedSearchResultData);
return offset;
}
static int
dissect_dsp_T_signedChainedSearchResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedSearchResult_sequence, hf_index, ett_dsp_T_signedChainedSearchResult);
return offset;
}
static int
dissect_dsp_ChainedSearchResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedSearchResult_choice, hf_index, ett_dsp_ChainedSearchResult,
NULL);
return offset;
}
static int
dissect_dsp_ChainedAddEntryArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedAddEntryArgumentData_set, hf_index, ett_dsp_ChainedAddEntryArgumentData);
return offset;
}
static int
dissect_dsp_T_signedChainedAddEntryArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedAddEntryArgument_sequence, hf_index, ett_dsp_T_signedChainedAddEntryArgument);
return offset;
}
static int
dissect_dsp_ChainedAddEntryArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedAddEntryArgument_choice, hf_index, ett_dsp_ChainedAddEntryArgument,
NULL);
return offset;
}
static int
dissect_dsp_ChainedAddEntryResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedAddEntryResultData_set, hf_index, ett_dsp_ChainedAddEntryResultData);
return offset;
}
static int
dissect_dsp_T_signedChainedAddEntryResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedAddEntryResult_sequence, hf_index, ett_dsp_T_signedChainedAddEntryResult);
return offset;
}
static int
dissect_dsp_ChainedAddEntryResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedAddEntryResult_choice, hf_index, ett_dsp_ChainedAddEntryResult,
NULL);
return offset;
}
static int
dissect_dsp_ChainedRemoveEntryArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedRemoveEntryArgumentData_set, hf_index, ett_dsp_ChainedRemoveEntryArgumentData);
return offset;
}
static int
dissect_dsp_T_signedChainedRemoveEntryArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedRemoveEntryArgument_sequence, hf_index, ett_dsp_T_signedChainedRemoveEntryArgument);
return offset;
}
static int
dissect_dsp_ChainedRemoveEntryArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedRemoveEntryArgument_choice, hf_index, ett_dsp_ChainedRemoveEntryArgument,
NULL);
return offset;
}
static int
dissect_dsp_ChainedRemoveEntryResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedRemoveEntryResultData_set, hf_index, ett_dsp_ChainedRemoveEntryResultData);
return offset;
}
static int
dissect_dsp_T_signedChainedRemoveEntryResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedRemoveEntryResult_sequence, hf_index, ett_dsp_T_signedChainedRemoveEntryResult);
return offset;
}
static int
dissect_dsp_ChainedRemoveEntryResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedRemoveEntryResult_choice, hf_index, ett_dsp_ChainedRemoveEntryResult,
NULL);
return offset;
}
static int
dissect_dsp_ChainedModifyEntryArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedModifyEntryArgumentData_set, hf_index, ett_dsp_ChainedModifyEntryArgumentData);
return offset;
}
static int
dissect_dsp_T_signedChainedModifyEntryArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedModifyEntryArgument_sequence, hf_index, ett_dsp_T_signedChainedModifyEntryArgument);
return offset;
}
static int
dissect_dsp_ChainedModifyEntryArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedModifyEntryArgument_choice, hf_index, ett_dsp_ChainedModifyEntryArgument,
NULL);
return offset;
}
static int
dissect_dsp_ChainedModifyEntryResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedModifyEntryResultData_set, hf_index, ett_dsp_ChainedModifyEntryResultData);
return offset;
}
static int
dissect_dsp_T_signedChainedModifyEntryResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedModifyEntryResult_sequence, hf_index, ett_dsp_T_signedChainedModifyEntryResult);
return offset;
}
static int
dissect_dsp_ChainedModifyEntryResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedModifyEntryResult_choice, hf_index, ett_dsp_ChainedModifyEntryResult,
NULL);
return offset;
}
static int
dissect_dsp_ChainedModifyDNArgumentData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedModifyDNArgumentData_set, hf_index, ett_dsp_ChainedModifyDNArgumentData);
return offset;
}
static int
dissect_dsp_T_signedChainedModifyDNArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedModifyDNArgument_sequence, hf_index, ett_dsp_T_signedChainedModifyDNArgument);
return offset;
}
static int
dissect_dsp_ChainedModifyDNArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedModifyDNArgument_choice, hf_index, ett_dsp_ChainedModifyDNArgument,
NULL);
return offset;
}
static int
dissect_dsp_ChainedModifyDNResultData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChainedModifyDNResultData_set, hf_index, ett_dsp_ChainedModifyDNResultData);
return offset;
}
static int
dissect_dsp_T_signedChainedModifyDNResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedChainedModifyDNResult_sequence, hf_index, ett_dsp_T_signedChainedModifyDNResult);
return offset;
}
static int
dissect_dsp_ChainedModifyDNResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ChainedModifyDNResult_choice, hf_index, ett_dsp_ChainedModifyDNResult,
NULL);
return offset;
}
static int
dissect_dsp_SET_OF_AccessPointInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_AccessPointInformation_set_of, hf_index, ett_dsp_SET_OF_AccessPointInformation);
return offset;
}
int
dissect_dsp_ContinuationReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ContinuationReference_set, hf_index, ett_dsp_ContinuationReference);
return offset;
}
static int
dissect_dsp_SEQUENCE_OF_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Attribute_sequence_of, hf_index, ett_dsp_SEQUENCE_OF_Attribute);
return offset;
}
static int
dissect_dsp_DSAReferralData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
DSAReferralData_set, hf_index, ett_dsp_DSAReferralData);
return offset;
}
static int
dissect_dsp_T_signedDSAReferral(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_signedDSAReferral_sequence, hf_index, ett_dsp_T_signedDSAReferral);
return offset;
}
static int
dissect_dsp_DSAReferral(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DSAReferral_choice, hf_index, ett_dsp_DSAReferral,
NULL);
return offset;
}
static int
dissect_dsp_LabeledURI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509sat_DirectoryString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_dsp_AccessPoint(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AccessPoint_set, hf_index, ett_dsp_AccessPoint);
return offset;
}
static int
dissect_dsp_DitBridgeKnowledge(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DitBridgeKnowledge_sequence, hf_index, ett_dsp_DitBridgeKnowledge);
return offset;
}
static void dissect_AccessPoint_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_dsp_AccessPoint(FALSE, tvb, 0, &asn1_ctx, tree, hf_dsp_AccessPoint_PDU);
}
static void dissect_MasterAndShadowAccessPoints_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_dsp_MasterAndShadowAccessPoints(FALSE, tvb, 0, &asn1_ctx, tree, hf_dsp_MasterAndShadowAccessPoints_PDU);
}
static void dissect_DitBridgeKnowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_dsp_DitBridgeKnowledge(FALSE, tvb, 0, &asn1_ctx, tree, hf_dsp_DitBridgeKnowledge_PDU);
}
static void
dissect_dsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0;
int old_offset;
proto_item *item=NULL;
proto_tree *tree=NULL;
int (*dsp_dissector)(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_) = NULL;
const char *dsp_op_name;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if( !pinfo->private_data ){
if(parent_tree){
proto_tree_add_text(parent_tree, tvb, offset, -1,
"Internal error: can't get operation information from ROS dissector.");
}
return ;
} else {
session = ( (struct SESSION_DATA_STRUCTURE*)(pinfo->private_data) );
}
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_dsp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_dsp);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DAP");
col_clear(pinfo->cinfo, COL_INFO);
switch(session->ros_op & ROS_OP_MASK) {
case (ROS_OP_BIND | ROS_OP_ARGUMENT):
dsp_dissector = dissect_dsp_DSASystemBindArgument;
dsp_op_name = "System-Bind-Argument";
break;
case (ROS_OP_BIND | ROS_OP_RESULT):
dsp_dissector = dissect_dsp_DSASystemBindResult;
dsp_op_name = "System-Bind-Result";
break;
case (ROS_OP_BIND | ROS_OP_ERROR):
dsp_dissector = dissect_dsp_DSASystemBindError;
dsp_op_name = "System-Bind-Error";
break;
case (ROS_OP_INVOKE | ROS_OP_ARGUMENT):
switch(session->ros_op & ROS_OP_OPCODE_MASK) {
case 1:
dsp_dissector = dissect_dsp_ChainedReadArgument;
dsp_op_name = "Chained-Read-Argument";
break;
case 2:
dsp_dissector = dissect_dsp_ChainedCompareArgument;
dsp_op_name = "Chained-Compare-Argument";
break;
case 3:
dsp_dissector = dissect_dsp_ChainedAbandonArgument;
dsp_op_name = "Chained-Abandon-Argument";
break;
case 4:
dsp_dissector = dissect_dsp_ChainedListArgument;
dsp_op_name = "Chained-List-Argument";
break;
case 5:
dsp_dissector = dissect_dsp_ChainedSearchArgument;
dsp_op_name = "Chained-Search-Argument";
break;
case 6:
dsp_dissector = dissect_dsp_ChainedAddEntryArgument;
dsp_op_name = "Chained-Add-Entry-Argument";
break;
case 7:
dsp_dissector = dissect_dsp_ChainedRemoveEntryArgument;
dsp_op_name = "Chained-Remove-Entry-Argument";
break;
case 8:
dsp_dissector = dissect_dsp_ChainedModifyEntryArgument;
dsp_op_name = "ChainedModify-Entry-Argument";
break;
case 9:
dsp_dissector = dissect_dsp_ChainedModifyDNArgument;
dsp_op_name = "ChainedModify-DN-Argument";
break;
default:
proto_tree_add_text(tree, tvb, offset, -1,"Unsupported DSP opcode (%d)",
session->ros_op & ROS_OP_OPCODE_MASK);
break;
}
break;
case (ROS_OP_INVOKE | ROS_OP_RESULT):
switch(session->ros_op & ROS_OP_OPCODE_MASK) {
case 1:
dsp_dissector = dissect_dsp_ChainedReadResult;
dsp_op_name = "Chained-Read-Result";
break;
case 2:
dsp_dissector = dissect_dsp_ChainedCompareResult;
dsp_op_name = "Chained-Compare-Result";
break;
case 3:
dsp_dissector = dissect_dsp_ChainedAbandonResult;
dsp_op_name = "Chained-Abandon-Result";
break;
case 4:
dsp_dissector = dissect_dsp_ChainedListResult;
dsp_op_name = "Chained-List-Result";
break;
case 5:
dsp_dissector = dissect_dsp_ChainedSearchResult;
dsp_op_name = "Chained-Search-Result";
break;
case 6:
dsp_dissector = dissect_dsp_ChainedAddEntryResult;
dsp_op_name = "Chained-Add-Entry-Result";
break;
case 7:
dsp_dissector = dissect_dsp_ChainedRemoveEntryResult;
dsp_op_name = "Chained-Remove-Entry-Result";
break;
case 8:
dsp_dissector = dissect_dsp_ChainedModifyEntryResult;
dsp_op_name = "Chained-Modify-Entry-Result";
break;
case 9:
dsp_dissector = dissect_dsp_ChainedModifyDNResult;
dsp_op_name = "ChainedModify-DN-Result";
break;
default:
proto_tree_add_text(tree, tvb, offset, -1,"Unsupported DSP opcode");
break;
}
break;
case (ROS_OP_INVOKE | ROS_OP_ERROR):
switch(session->ros_op & ROS_OP_OPCODE_MASK) {
case 1:
dsp_dissector = dissect_dap_AttributeError;
dsp_op_name = "Attribute-Error";
break;
case 2:
dsp_dissector = dissect_dap_NameError;
dsp_op_name = "Name-Error";
break;
case 3:
dsp_dissector = dissect_dap_ServiceError;
dsp_op_name = "Service-Error";
break;
case 4:
dsp_dissector = dissect_dap_Referral;
dsp_op_name = "Referral";
break;
case 5:
dsp_dissector = dissect_dap_Abandoned;
dsp_op_name = "Abandoned";
break;
case 6:
dsp_dissector = dissect_dap_SecurityError;
dsp_op_name = "Security-Error";
break;
case 7:
dsp_dissector = dissect_dap_AbandonFailedError;
dsp_op_name = "Abandon-Failed-Error";
break;
case 8:
dsp_dissector = dissect_dap_UpdateError;
dsp_op_name = "Update-Error";
break;
case 9:
dsp_dissector = dissect_dsp_DSAReferral;
dsp_op_name = "DSA-Referral";
break;
default:
proto_tree_add_text(tree, tvb, offset, -1,"Unsupported DSP errcode");
break;
}
break;
default:
proto_tree_add_text(tree, tvb, offset, -1,"Unsupported DSP PDU");
return;
}
if(dsp_dissector) {
col_set_str(pinfo->cinfo, COL_INFO, dsp_op_name);
while (tvb_reported_length_remaining(tvb, offset) > 0){
old_offset=offset;
offset=(*dsp_dissector)(FALSE, tvb, offset, &asn1_ctx, tree, -1);
if(offset == old_offset){
proto_tree_add_text(tree, tvb, offset, -1,"Internal error, zero-byte DSP PDU");
break;
}
}
}
}
void proto_register_dsp(void) {
static hf_register_info hf[] =
{
#line 1 "../../asn1/dsp/packet-dsp-hfarr.c"
{ &hf_dsp_AccessPoint_PDU,
{ "AccessPoint", "dsp.AccessPoint_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_MasterAndShadowAccessPoints_PDU,
{ "MasterAndShadowAccessPoints", "dsp.MasterAndShadowAccessPoints",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_DitBridgeKnowledge_PDU,
{ "DitBridgeKnowledge", "dsp.DitBridgeKnowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedArgument,
{ "chainedArgument", "dsp.chainedArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainingArguments", HFILL }},
{ &hf_dsp_readArgument,
{ "readArgument", "dsp.readArgument",
FT_UINT32, BASE_DEC, VALS(dap_ReadArgument_vals), 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedReadArgument,
{ "unsignedChainedReadArgument", "dsp.unsignedChainedReadArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedReadArgumentData", HFILL }},
{ &hf_dsp_signedChainedReadArgument,
{ "signedChainedReadArgument", "dsp.signedChainedReadArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedReadArgument,
{ "chainedReadArgument", "dsp.chainedReadArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedReadArgumentData", HFILL }},
{ &hf_dsp_algorithmIdentifier,
{ "algorithmIdentifier", "dsp.algorithmIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_encrypted,
{ "encrypted", "dsp.encrypted",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_dsp_chainedResults,
{ "chainedResults", "dsp.chainedResults_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainingResults", HFILL }},
{ &hf_dsp_readResult,
{ "readResult", "dsp.readResult",
FT_UINT32, BASE_DEC, VALS(dap_ReadResult_vals), 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedReadResult,
{ "unsignedChainedReadResult", "dsp.unsignedChainedReadResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedReadResultData", HFILL }},
{ &hf_dsp_signedChainedReadResult,
{ "signedChainedReadResult", "dsp.signedChainedReadResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedReadResult,
{ "chainedReadResult", "dsp.chainedReadResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedReadResultData", HFILL }},
{ &hf_dsp_compareArgument,
{ "compareArgument", "dsp.compareArgument",
FT_UINT32, BASE_DEC, VALS(dap_CompareArgument_vals), 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedCompareArgument,
{ "unsignedChainedCompareArgument", "dsp.unsignedChainedCompareArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedCompareArgumentData", HFILL }},
{ &hf_dsp_signedChainedCompareArgument,
{ "signedChainedCompareArgument", "dsp.signedChainedCompareArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedCompareArgument,
{ "chainedCompareArgument", "dsp.chainedCompareArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedCompareArgumentData", HFILL }},
{ &hf_dsp_compareResult,
{ "compareResult", "dsp.compareResult",
FT_UINT32, BASE_DEC, VALS(dap_CompareResult_vals), 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedCompareResult,
{ "unsignedChainedCompareResult", "dsp.unsignedChainedCompareResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedCompareResultData", HFILL }},
{ &hf_dsp_signedChainedCompareResult,
{ "signedChainedCompareResult", "dsp.signedChainedCompareResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedCompareResult,
{ "chainedCompareResult", "dsp.chainedCompareResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedCompareResultData", HFILL }},
{ &hf_dsp_listArgument,
{ "listArgument", "dsp.listArgument",
FT_UINT32, BASE_DEC, VALS(dap_ListArgument_vals), 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedListArgument,
{ "unsignedChainedListArgument", "dsp.unsignedChainedListArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedListArgumentData", HFILL }},
{ &hf_dsp_signedChainedListArgument,
{ "signedChainedListArgument", "dsp.signedChainedListArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedListArgument,
{ "chainedListArgument", "dsp.chainedListArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedListArgumentData", HFILL }},
{ &hf_dsp_listResult,
{ "listResult", "dsp.listResult",
FT_UINT32, BASE_DEC, VALS(dap_ListResult_vals), 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedListResult,
{ "unsignedChainedListResult", "dsp.unsignedChainedListResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedListResultData", HFILL }},
{ &hf_dsp_signedChainedListResult,
{ "signedChainedListResult", "dsp.signedChainedListResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedListResult,
{ "chainedListResult", "dsp.chainedListResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedListResultData", HFILL }},
{ &hf_dsp_searchArgument,
{ "searchArgument", "dsp.searchArgument",
FT_UINT32, BASE_DEC, VALS(dap_SearchArgument_vals), 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedSearchArgument,
{ "unsignedChainedSearchArgument", "dsp.unsignedChainedSearchArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedSearchArgumentData", HFILL }},
{ &hf_dsp_signedChainedSearchArgument,
{ "signedChainedSearchArgument", "dsp.signedChainedSearchArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedSearchArgument,
{ "chainedSearchArgument", "dsp.chainedSearchArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedSearchArgumentData", HFILL }},
{ &hf_dsp_searchResult,
{ "searchResult", "dsp.searchResult",
FT_UINT32, BASE_DEC, VALS(dap_SearchResult_vals), 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedSearchResult,
{ "unsignedChainedSearchResult", "dsp.unsignedChainedSearchResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedSearchResultData", HFILL }},
{ &hf_dsp_signedChainedSearchResult,
{ "signedChainedSearchResult", "dsp.signedChainedSearchResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedSearchResult,
{ "chainedSearchResult", "dsp.chainedSearchResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedSearchResultData", HFILL }},
{ &hf_dsp_addEntryArgument,
{ "addEntryArgument", "dsp.addEntryArgument",
FT_UINT32, BASE_DEC, VALS(dap_AddEntryArgument_vals), 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedAddEntryArgument,
{ "unsignedChainedAddEntryArgument", "dsp.unsignedChainedAddEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedAddEntryArgumentData", HFILL }},
{ &hf_dsp_signedChainedAddEntryArgument,
{ "signedChainedAddEntryArgument", "dsp.signedChainedAddEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedAddEntryArgument,
{ "chainedAddEntryArgument", "dsp.chainedAddEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedAddEntryArgumentData", HFILL }},
{ &hf_dsp_addEntryResult,
{ "addEntryResult", "dsp.addEntryResult",
FT_UINT32, BASE_DEC, VALS(dap_AddEntryResult_vals), 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedAddEntryResult,
{ "unsignedChainedAddEntryResult", "dsp.unsignedChainedAddEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedAddEntryResultData", HFILL }},
{ &hf_dsp_signedChainedAddEntryResult,
{ "signedChainedAddEntryResult", "dsp.signedChainedAddEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedAddEntryResult,
{ "chainedAddEntryResult", "dsp.chainedAddEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedAddEntryResultData", HFILL }},
{ &hf_dsp_removeEntryArgument,
{ "removeEntryArgument", "dsp.removeEntryArgument",
FT_UINT32, BASE_DEC, VALS(dap_RemoveEntryArgument_vals), 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedRemoveEntryArgument,
{ "unsignedChainedRemoveEntryArgument", "dsp.unsignedChainedRemoveEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedRemoveEntryArgumentData", HFILL }},
{ &hf_dsp_signedChainedRemoveEntryArgument,
{ "signedChainedRemoveEntryArgument", "dsp.signedChainedRemoveEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedRemoveEntryArgument,
{ "chainedRemoveEntryArgument", "dsp.chainedRemoveEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedRemoveEntryArgumentData", HFILL }},
{ &hf_dsp_removeEntryResult,
{ "removeEntryResult", "dsp.removeEntryResult",
FT_UINT32, BASE_DEC, VALS(dap_RemoveEntryResult_vals), 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedRemoveEntryResult,
{ "unsignedChainedRemoveEntryResult", "dsp.unsignedChainedRemoveEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedRemoveEntryResultData", HFILL }},
{ &hf_dsp_signedChainedRemoveEntryResult,
{ "signedChainedRemoveEntryResult", "dsp.signedChainedRemoveEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedRemoveEntryResult,
{ "chainedRemoveEntryResult", "dsp.chainedRemoveEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedRemoveEntryResultData", HFILL }},
{ &hf_dsp_modifyEntryArgument,
{ "modifyEntryArgument", "dsp.modifyEntryArgument",
FT_UINT32, BASE_DEC, VALS(dap_ModifyEntryArgument_vals), 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedModifyEntryArgument,
{ "unsignedChainedModifyEntryArgument", "dsp.unsignedChainedModifyEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedModifyEntryArgumentData", HFILL }},
{ &hf_dsp_signedChainedModifyEntryArgument,
{ "signedChainedModifyEntryArgument", "dsp.signedChainedModifyEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedModifyEntryArgument,
{ "chainedModifyEntryArgument", "dsp.chainedModifyEntryArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedModifyEntryArgumentData", HFILL }},
{ &hf_dsp_modifyEntryResult,
{ "modifyEntryResult", "dsp.modifyEntryResult",
FT_UINT32, BASE_DEC, VALS(dap_ModifyEntryResult_vals), 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedModifyEntryResult,
{ "unsignedChainedModifyEntryResult", "dsp.unsignedChainedModifyEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedModifyEntryResultData", HFILL }},
{ &hf_dsp_signedChainedModifyEntryResult,
{ "signedChainedModifyEntryResult", "dsp.signedChainedModifyEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedModifyEntryResult,
{ "chainedModifyEntryResult", "dsp.chainedModifyEntryResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedModifyEntryResultData", HFILL }},
{ &hf_dsp_modifyDNArgument,
{ "modifyDNArgument", "dsp.modifyDNArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedModifyDNArgument,
{ "unsignedChainedModifyDNArgument", "dsp.unsignedChainedModifyDNArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedModifyDNArgumentData", HFILL }},
{ &hf_dsp_signedChainedModifyDNArgument,
{ "signedChainedModifyDNArgument", "dsp.signedChainedModifyDNArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedModifyDNArgument,
{ "chainedModifyDNArgument", "dsp.chainedModifyDNArgument_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedModifyDNArgumentData", HFILL }},
{ &hf_dsp_modifyDNResult,
{ "modifyDNResult", "dsp.modifyDNResult",
FT_UINT32, BASE_DEC, VALS(dap_ModifyDNResult_vals), 0,
NULL, HFILL }},
{ &hf_dsp_unsignedChainedModifyDNResult,
{ "unsignedChainedModifyDNResult", "dsp.unsignedChainedModifyDNResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedModifyDNResultData", HFILL }},
{ &hf_dsp_signedChainedModifyDNResult,
{ "signedChainedModifyDNResult", "dsp.signedChainedModifyDNResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedModifyDNResult,
{ "chainedModifyDNResult", "dsp.chainedModifyDNResult_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChainedModifyDNResultData", HFILL }},
{ &hf_dsp_reference,
{ "reference", "dsp.reference_element",
FT_NONE, BASE_NONE, NULL, 0,
"ContinuationReference", HFILL }},
{ &hf_dsp_contextPrefix,
{ "contextPrefix", "dsp.contextPrefix",
FT_UINT32, BASE_DEC, NULL, 0,
"DistinguishedName", HFILL }},
{ &hf_dsp_securityParameters,
{ "securityParameters", "dsp.securityParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_performer,
{ "performer", "dsp.performer",
FT_UINT32, BASE_DEC, NULL, 0,
"DistinguishedName", HFILL }},
{ &hf_dsp_aliasDereferenced,
{ "aliasDereferenced", "dsp.aliasDereferenced",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dsp_notification,
{ "notification", "dsp.notification",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Attribute", HFILL }},
{ &hf_dsp_notification_item,
{ "Attribute", "dsp.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_unsignedDSAReferral,
{ "unsignedDSAReferral", "dsp.unsignedDSAReferral_element",
FT_NONE, BASE_NONE, NULL, 0,
"DSAReferralData", HFILL }},
{ &hf_dsp_signedDSAReferral,
{ "signedDSAReferral", "dsp.signedDSAReferral_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_dsaReferral,
{ "dsaReferral", "dsp.dsaReferral_element",
FT_NONE, BASE_NONE, NULL, 0,
"DSAReferralData", HFILL }},
{ &hf_dsp_originator,
{ "originator", "dsp.originator",
FT_UINT32, BASE_DEC, NULL, 0,
"DistinguishedName", HFILL }},
{ &hf_dsp_targetObjectDN,
{ "targetObject", "dsp.targetObject",
FT_UINT32, BASE_DEC, NULL, 0,
"DistinguishedName", HFILL }},
{ &hf_dsp_operationProgress,
{ "operationProgress", "dsp.operationProgress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_traceInformation,
{ "traceInformation", "dsp.traceInformation",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_aliasedRDNs,
{ "aliasedRDNs", "dsp.aliasedRDNs",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dsp_returnCrossRefs,
{ "returnCrossRefs", "dsp.returnCrossRefs",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dsp_referenceType,
{ "referenceType", "dsp.referenceType",
FT_UINT32, BASE_DEC, VALS(dsp_ReferenceType_vals), 0,
NULL, HFILL }},
{ &hf_dsp_info,
{ "info", "dsp.info",
FT_OID, BASE_NONE, NULL, 0,
"DomainInfo", HFILL }},
{ &hf_dsp_timeLimit,
{ "timeLimit", "dsp.timeLimit",
FT_UINT32, BASE_DEC, VALS(dsp_Time_vals), 0,
"Time", HFILL }},
{ &hf_dsp_entryOnly,
{ "entryOnly", "dsp.entryOnly",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dsp_uniqueIdentifier,
{ "uniqueIdentifier", "dsp.uniqueIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_authenticationLevel,
{ "authenticationLevel", "dsp.authenticationLevel",
FT_UINT32, BASE_DEC, VALS(dsp_AuthenticationLevel_vals), 0,
NULL, HFILL }},
{ &hf_dsp_exclusions,
{ "exclusions", "dsp.exclusions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_excludeShadows,
{ "excludeShadows", "dsp.excludeShadows",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dsp_nameResolveOnMaster,
{ "nameResolveOnMaster", "dsp.nameResolveOnMaster",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dsp_operationIdentifier,
{ "operationIdentifier", "dsp.operationIdentifier",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dsp_searchRuleId,
{ "searchRuleId", "dsp.searchRuleId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_chainedRelaxation,
{ "chainedRelaxation", "dsp.chainedRelaxation_element",
FT_NONE, BASE_NONE, NULL, 0,
"MRMapping", HFILL }},
{ &hf_dsp_relatedEntry,
{ "relatedEntry", "dsp.relatedEntry",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dsp_dspPaging,
{ "dspPaging", "dsp.dspPaging",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dsp_nonDapPdu,
{ "nonDapPdu", "dsp.nonDapPdu",
FT_UINT32, BASE_DEC, VALS(dsp_T_nonDapPdu_vals), 0,
NULL, HFILL }},
{ &hf_dsp_streamedResults,
{ "streamedResults", "dsp.streamedResults",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dsp_excludeWriteableCopies,
{ "excludeWriteableCopies", "dsp.excludeWriteableCopies",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dsp_utcTime,
{ "utcTime", "dsp.utcTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_generalizedTime,
{ "generalizedTime", "dsp.generalizedTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_crossReferences,
{ "crossReferences", "dsp.crossReferences",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CrossReference", HFILL }},
{ &hf_dsp_crossReferences_item,
{ "CrossReference", "dsp.CrossReference_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_alreadySearched,
{ "alreadySearched", "dsp.alreadySearched",
FT_UINT32, BASE_DEC, NULL, 0,
"Exclusions", HFILL }},
{ &hf_dsp_accessPoint,
{ "accessPoint", "dsp.accessPoint_element",
FT_NONE, BASE_NONE, NULL, 0,
"AccessPointInformation", HFILL }},
{ &hf_dsp_nameResolutionPhase,
{ "nameResolutionPhase", "dsp.nameResolutionPhase",
FT_UINT32, BASE_DEC, VALS(dsp_T_nameResolutionPhase_vals), 0,
NULL, HFILL }},
{ &hf_dsp_nextRDNToBeResolved,
{ "nextRDNToBeResolved", "dsp.nextRDNToBeResolved",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dsp_TraceInformation_item,
{ "TraceItem", "dsp.TraceItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_dsa,
{ "dsa", "dsp.dsa",
FT_UINT32, BASE_DEC, VALS(x509if_Name_vals), 0,
"Name", HFILL }},
{ &hf_dsp_targetObject,
{ "targetObject", "dsp.targetObject",
FT_UINT32, BASE_DEC, VALS(x509if_Name_vals), 0,
"Name", HFILL }},
{ &hf_dsp_ae_title,
{ "ae-title", "dsp.ae_title",
FT_UINT32, BASE_DEC, VALS(x509if_Name_vals), 0,
"Name", HFILL }},
{ &hf_dsp_address,
{ "address", "dsp.address_element",
FT_NONE, BASE_NONE, NULL, 0,
"PresentationAddress", HFILL }},
{ &hf_dsp_protocolInformation,
{ "protocolInformation", "dsp.protocolInformation",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ProtocolInformation", HFILL }},
{ &hf_dsp_protocolInformation_item,
{ "ProtocolInformation", "dsp.ProtocolInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_labeledURI,
{ "labeledURI", "dsp.labeledURI",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
NULL, HFILL }},
{ &hf_dsp_access_point_category,
{ "category", "dsp.category",
FT_UINT32, BASE_DEC, VALS(dsp_APCategory_vals), 0,
"APCategory", HFILL }},
{ &hf_dsp_chainingRequired,
{ "chainingRequired", "dsp.chainingRequired",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dsp_MasterAndShadowAccessPoints_item,
{ "MasterOrShadowAccessPoint", "dsp.MasterOrShadowAccessPoint_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_category,
{ "category", "dsp.category",
FT_UINT32, BASE_DEC, VALS(dsp_T_category_vals), 0,
NULL, HFILL }},
{ &hf_dsp_additionalPoints,
{ "additionalPoints", "dsp.additionalPoints",
FT_UINT32, BASE_DEC, NULL, 0,
"MasterAndShadowAccessPoints", HFILL }},
{ &hf_dsp_domainLocalID,
{ "domainLocalID", "dsp.domainLocalID",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
"DirectoryString", HFILL }},
{ &hf_dsp_accessPoints,
{ "accessPoints", "dsp.accessPoints",
FT_UINT32, BASE_DEC, NULL, 0,
"MasterAndShadowAccessPoints", HFILL }},
{ &hf_dsp_Exclusions_item,
{ "RDNSequence", "dsp.RDNSequence",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_rdnsResolved,
{ "rdnsResolved", "dsp.rdnsResolved",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dsp_accessPoints_01,
{ "accessPoints", "dsp.accessPoints",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_AccessPointInformation", HFILL }},
{ &hf_dsp_accessPoints_item,
{ "AccessPointInformation", "dsp.AccessPointInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_returnToDUA,
{ "returnToDUA", "dsp.returnToDUA",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dsp_basicLevels,
{ "basicLevels", "dsp.basicLevels_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dsp_level,
{ "level", "dsp.level",
FT_UINT32, BASE_DEC, VALS(dsp_T_level_vals), 0,
NULL, HFILL }},
{ &hf_dsp_localQualifier,
{ "localQualifier", "dsp.localQualifier",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_dsp_signed,
{ "signed", "dsp.signed",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_dsp_other,
{ "other", "dsp.other_element",
FT_NONE, BASE_NONE, NULL, 0,
"EXTERNAL", HFILL }},
#line 272 "../../asn1/dsp/packet-dsp-template.c"
};
static gint *ett[] = {
&ett_dsp,
#line 1 "../../asn1/dsp/packet-dsp-ettarr.c"
&ett_dsp_ChainedReadArgumentData,
&ett_dsp_ChainedReadArgument,
&ett_dsp_T_signedChainedReadArgument,
&ett_dsp_ChainedReadResultData,
&ett_dsp_ChainedReadResult,
&ett_dsp_T_signedChainedReadResult,
&ett_dsp_ChainedCompareArgumentData,
&ett_dsp_ChainedCompareArgument,
&ett_dsp_T_signedChainedCompareArgument,
&ett_dsp_ChainedCompareResultData,
&ett_dsp_ChainedCompareResult,
&ett_dsp_T_signedChainedCompareResult,
&ett_dsp_ChainedListArgumentData,
&ett_dsp_ChainedListArgument,
&ett_dsp_T_signedChainedListArgument,
&ett_dsp_ChainedListResultData,
&ett_dsp_ChainedListResult,
&ett_dsp_T_signedChainedListResult,
&ett_dsp_ChainedSearchArgumentData,
&ett_dsp_ChainedSearchArgument,
&ett_dsp_T_signedChainedSearchArgument,
&ett_dsp_ChainedSearchResultData,
&ett_dsp_ChainedSearchResult,
&ett_dsp_T_signedChainedSearchResult,
&ett_dsp_ChainedAddEntryArgumentData,
&ett_dsp_ChainedAddEntryArgument,
&ett_dsp_T_signedChainedAddEntryArgument,
&ett_dsp_ChainedAddEntryResultData,
&ett_dsp_ChainedAddEntryResult,
&ett_dsp_T_signedChainedAddEntryResult,
&ett_dsp_ChainedRemoveEntryArgumentData,
&ett_dsp_ChainedRemoveEntryArgument,
&ett_dsp_T_signedChainedRemoveEntryArgument,
&ett_dsp_ChainedRemoveEntryResultData,
&ett_dsp_ChainedRemoveEntryResult,
&ett_dsp_T_signedChainedRemoveEntryResult,
&ett_dsp_ChainedModifyEntryArgumentData,
&ett_dsp_ChainedModifyEntryArgument,
&ett_dsp_T_signedChainedModifyEntryArgument,
&ett_dsp_ChainedModifyEntryResultData,
&ett_dsp_ChainedModifyEntryResult,
&ett_dsp_T_signedChainedModifyEntryResult,
&ett_dsp_ChainedModifyDNArgumentData,
&ett_dsp_ChainedModifyDNArgument,
&ett_dsp_T_signedChainedModifyDNArgument,
&ett_dsp_ChainedModifyDNResultData,
&ett_dsp_ChainedModifyDNResult,
&ett_dsp_T_signedChainedModifyDNResult,
&ett_dsp_DSAReferralData,
&ett_dsp_SEQUENCE_OF_Attribute,
&ett_dsp_DSAReferral,
&ett_dsp_T_signedDSAReferral,
&ett_dsp_ChainingArguments,
&ett_dsp_Time,
&ett_dsp_ChainingResults,
&ett_dsp_SEQUENCE_OF_CrossReference,
&ett_dsp_CrossReference,
&ett_dsp_OperationProgress,
&ett_dsp_TraceInformation,
&ett_dsp_TraceItem,
&ett_dsp_AccessPoint,
&ett_dsp_SET_OF_ProtocolInformation,
&ett_dsp_MasterOrShadowAccessPoint,
&ett_dsp_MasterAndShadowAccessPoints,
&ett_dsp_AccessPointInformation,
&ett_dsp_DitBridgeKnowledge,
&ett_dsp_Exclusions,
&ett_dsp_ContinuationReference,
&ett_dsp_SET_OF_AccessPointInformation,
&ett_dsp_AuthenticationLevel,
&ett_dsp_T_basicLevels,
#line 278 "../../asn1/dsp/packet-dsp-template.c"
};
module_t *dsp_module;
proto_dsp = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("dsp", dissect_dsp, proto_dsp);
proto_register_field_array(proto_dsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
dsp_module = prefs_register_protocol_subtree("OSI/X.500", proto_dsp, prefs_register_dsp);
prefs_register_uint_preference(dsp_module, "tcp.port", "DSP TCP Port",
"Set the port for DSP operations (if other"
" than the default of 102)",
10, &global_dsp_tcp_port);
}
void proto_reg_handoff_dsp(void) {
dissector_handle_t dsp_handle;
#line 1 "../../asn1/dsp/packet-dsp-dis-tab.c"
register_ber_oid_dissector("2.5.12.1", dissect_AccessPoint_PDU, proto_dsp, "id-doa-myAccessPoint");
register_ber_oid_dissector("2.5.12.2", dissect_AccessPoint_PDU, proto_dsp, "id-doa-superiorKnowledge");
register_ber_oid_dissector("2.5.12.3", dissect_MasterAndShadowAccessPoints_PDU, proto_dsp, "id-doa-specificKnowledge");
register_ber_oid_dissector("2.5.12.4", dissect_MasterAndShadowAccessPoints_PDU, proto_dsp, "id-doa-nonSpecificKnowledge");
register_ber_oid_dissector("2.5.12.8", dissect_DitBridgeKnowledge_PDU, proto_dsp, "id-doa-ditBridgeKnowledge");
#line 308 "../../asn1/dsp/packet-dsp-template.c"
oid_add_from_string("id-ac-directory-system","2.5.3.2");
tpkt_handle = find_dissector("tpkt");
dsp_handle = find_dissector("dsp");
register_ros_oid_dissector_handle("2.5.9.2", dsp_handle, 0, "id-as-directory-system", FALSE);
}
static void
prefs_register_dsp(void)
{
static guint tcp_port = 0;
if((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_delete_uint("tcp.port", tcp_port, tpkt_handle);
tcp_port = global_dsp_tcp_port;
if((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_add_uint("tcp.port", global_dsp_tcp_port, tpkt_handle);
}
