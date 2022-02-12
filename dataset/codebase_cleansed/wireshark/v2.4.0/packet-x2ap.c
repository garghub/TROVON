static void
x2ap_Time_UE_StayedInCell_EnhancedGranularity_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%.1fs", ((float)v)/10);
}
static void
x2ap_handoverTriggerChange_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%.1fdB (%d)", ((float)v)/2, (gint32)v);
}
static void
x2ap_Threshold_RSRP_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%ddBm (%u)", (gint32)v-140, v);
}
static void
x2ap_Threshold_RSRQ_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%.1fdB (%u)", ((float)v/2)-20, v);
}
static struct x2ap_private_data*
x2ap_get_private_data(packet_info *pinfo)
{
struct x2ap_private_data *x2ap_data = (struct x2ap_private_data*)p_get_proto_data(pinfo->pool, pinfo, proto_x2ap, 0);
if (!x2ap_data) {
x2ap_data = wmem_new0(pinfo->pool, struct x2ap_private_data);
p_add_proto_data(pinfo->pool, pinfo, proto_x2ap, 0, x2ap_data);
}
return x2ap_data;
}
static int
dissect_x2ap_Criticality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_x2ap_INTEGER_0_maxPrivateIEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxPrivateIEs, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_x2ap_PrivateIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_PrivateIE_ID, PrivateIE_ID_choice,
NULL);
return offset;
}
static int
dissect_x2ap_ProcedureCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 65 "./asn1/x2ap/x2ap.cnf"
struct x2ap_private_data *x2ap_data = x2ap_get_private_data(actx->pinfo);
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &x2ap_data->procedure_code, FALSE);
return offset;
}
static int
dissect_x2ap_ProtocolIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 52 "./asn1/x2ap/x2ap.cnf"
struct x2ap_private_data *x2ap_data = x2ap_get_private_data(actx->pinfo);
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxProtocolIEs, &x2ap_data->protocol_ie_id, FALSE);
#line 55 "./asn1/x2ap/x2ap.cnf"
if (tree) {
proto_item_append_text(proto_item_get_parent_nth(actx->created_item, 2), ": %s", val_to_str_ext(x2ap_data->protocol_ie_id, &x2ap_ProtocolIE_ID_vals_ext, "unknown (%d)"));
}
return offset;
}
static int
dissect_x2ap_TriggeringMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ProtocolIE_Field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolIEFieldValue);
return offset;
}
static int
dissect_x2ap_ProtocolIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ProtocolIE_Field, ProtocolIE_Field_sequence);
return offset;
}
static int
dissect_x2ap_ProtocolIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ProtocolIE_Container, ProtocolIE_Container_sequence_of,
0, maxProtocolIEs, FALSE);
return offset;
}
static int
dissect_x2ap_ProtocolIE_Single_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x2ap_ProtocolIE_Field(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_x2ap_T_extensionValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolExtensionFieldExtensionValue);
return offset;
}
static int
dissect_x2ap_ProtocolExtensionField(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ProtocolExtensionField, ProtocolExtensionField_sequence);
return offset;
}
static int
dissect_x2ap_ProtocolExtensionContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ProtocolExtensionContainer, ProtocolExtensionContainer_sequence_of,
1, maxProtocolExtensions, FALSE);
return offset;
}
static int
dissect_x2ap_PrivateIE_Field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_x2ap_PrivateIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_PrivateIE_Field, PrivateIE_Field_sequence);
return offset;
}
static int
dissect_x2ap_PrivateIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_PrivateIE_Container, PrivateIE_Container_sequence_of,
1, maxPrivateIEs, FALSE);
return offset;
}
static int
dissect_x2ap_BIT_STRING_SIZE_40(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
40, 40, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_T_numberOfCellSpecificAntennaPorts(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ABSInformationFDD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ABSInformationFDD, ABSInformationFDD_sequence);
return offset;
}
static int
dissect_x2ap_BIT_STRING_SIZE_1_70_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 70, TRUE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_T_numberOfCellSpecificAntennaPorts_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ABSInformationTDD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ABSInformationTDD, ABSInformationTDD_sequence);
return offset;
}
static int
dissect_x2ap_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_x2ap_ABSInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_ABSInformation, ABSInformation_choice,
NULL);
return offset;
}
static int
dissect_x2ap_DL_ABS_status(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_UsableABSInformationFDD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UsableABSInformationFDD, UsableABSInformationFDD_sequence);
return offset;
}
static int
dissect_x2ap_UsableABSInformationTDD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UsableABSInformationTDD, UsableABSInformationTDD_sequence);
return offset;
}
static int
dissect_x2ap_UsableABSInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_UsableABSInformation, UsableABSInformation_choice,
NULL);
return offset;
}
static int
dissect_x2ap_ABS_Status(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ABS_Status, ABS_Status_sequence);
return offset;
}
static int
dissect_x2ap_AdditionalSpecialSubframePatterns(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
10, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_CyclicPrefixDL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_CyclicPrefixUL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_AdditionalSpecialSubframe_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_AdditionalSpecialSubframe_Info, AdditionalSpecialSubframe_Info_sequence);
return offset;
}
static int
dissect_x2ap_PriorityLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_Pre_emptionCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_x2ap_Pre_emptionVulnerability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_x2ap_AllocationAndRetentionPriority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_AllocationAndRetentionPriority, AllocationAndRetentionPriority_sequence);
return offset;
}
static int
dissect_x2ap_PLMN_Identity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 299 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, &parameter_tvb);
if(tvb_reported_length(tvb)==0)
return offset;
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_PLMN_Identity);
dissect_e212_mcc_mnc(parameter_tvb, actx->pinfo, subtree, 0, E212_NONE, FALSE);
return offset;
}
static int
dissect_x2ap_EUTRANCellIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_ECGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ECGI, ECGI_sequence);
return offset;
}
static int
dissect_x2ap_CellIdListforMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellIdListforMDT, CellIdListforMDT_sequence_of,
1, maxnoofCellIDforMDT, FALSE);
return offset;
}
static int
dissect_x2ap_CellBasedMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellBasedMDT, CellBasedMDT_sequence);
return offset;
}
static int
dissect_x2ap_TAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 283 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
2, 2, FALSE, &parameter_tvb);
if (parameter_tvb) {
actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_x2ap_TAListforMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_TAListforMDT, TAListforMDT_sequence_of,
1, maxnoofTAforMDT, FALSE);
return offset;
}
static int
dissect_x2ap_TABasedMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_TABasedMDT, TABasedMDT_sequence);
return offset;
}
static int
dissect_x2ap_TAI_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_TAI_Item, TAI_Item_sequence);
return offset;
}
static int
dissect_x2ap_TAIListforMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_TAIListforMDT, TAIListforMDT_sequence_of,
1, maxnoofTAforMDT, FALSE);
return offset;
}
static int
dissect_x2ap_TAIBasedMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_TAIBasedMDT, TAIBasedMDT_sequence);
return offset;
}
static int
dissect_x2ap_AreaScopeOfMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_AreaScopeOfMDT, AreaScopeOfMDT_choice,
NULL);
return offset;
}
static int
dissect_x2ap_Key_eNodeB_Star(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
256, 256, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_NextHopChainingCount(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_AS_SecurityInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_AS_SecurityInformation, AS_SecurityInformation_sequence);
return offset;
}
static int
dissect_x2ap_BearerType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_BenefitMetric(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-101, 100U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_BitRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer_64b(tvb, offset, actx, tree, hf_index,
0U, G_GUINT64_CONSTANT(10000000000), NULL, FALSE);
return offset;
}
static int
dissect_x2ap_BroadcastPLMNs_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_BroadcastPLMNs_Item, BroadcastPLMNs_Item_sequence_of,
1, maxnoofBPLMNs, FALSE);
return offset;
}
static int
dissect_x2ap_CapacityValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_CauseRadioNetwork(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
22, NULL, TRUE, 24, NULL);
return offset;
}
static int
dissect_x2ap_CauseTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_CauseProtocol(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_CauseMisc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_Cause, Cause_choice,
NULL);
return offset;
}
static int
dissect_x2ap_CellCapacityClassValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 100U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_CellDeploymentStatusIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ReplacingCellsList_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ReplacingCellsList_Item, ReplacingCellsList_Item_sequence);
return offset;
}
static int
dissect_x2ap_ReplacingCellsList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ReplacingCellsList, ReplacingCellsList_sequence_of,
0, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_CellReplacingInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellReplacingInfo, CellReplacingInfo_sequence);
return offset;
}
static int
dissect_x2ap_CellReportingIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_Cell_Size(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_CellType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellType, CellType_sequence);
return offset;
}
static int
dissect_x2ap_BIT_STRING_SIZE_6_4400_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
6, 4400, TRUE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_CoMPHypothesisSetItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CoMPHypothesisSetItem, CoMPHypothesisSetItem_sequence);
return offset;
}
static int
dissect_x2ap_CoMPHypothesisSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CoMPHypothesisSet, CoMPHypothesisSet_sequence_of,
1, maxnoofCoMPCells, FALSE);
return offset;
}
static int
dissect_x2ap_CoMPInformationItem_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CoMPInformationItem_item, CoMPInformationItem_item_sequence);
return offset;
}
static int
dissect_x2ap_CoMPInformationItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CoMPInformationItem, CoMPInformationItem_sequence_of,
1, maxnoofCoMPHypothesisSet, FALSE);
return offset;
}
static int
dissect_x2ap_INTEGER_0_1023_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1023U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_INTEGER_0_9_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 9U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_CoMPInformationStartTime_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CoMPInformationStartTime_item, CoMPInformationStartTime_item_sequence);
return offset;
}
static int
dissect_x2ap_CoMPInformationStartTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CoMPInformationStartTime, CoMPInformationStartTime_sequence_of,
0, 1, FALSE);
return offset;
}
static int
dissect_x2ap_CoMPInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CoMPInformation, CoMPInformation_sequence);
return offset;
}
static int
dissect_x2ap_CompositeAvailableCapacity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CompositeAvailableCapacity, CompositeAvailableCapacity_sequence);
return offset;
}
static int
dissect_x2ap_CompositeAvailableCapacityGroup(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CompositeAvailableCapacityGroup, CompositeAvailableCapacityGroup_sequence);
return offset;
}
static int
dissect_x2ap_Correlation_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_PDCP_SN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_HFN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1048575U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_COUNTvalue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_COUNTvalue, COUNTvalue_sequence);
return offset;
}
static int
dissect_x2ap_PDCP_SNExtended(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 32767U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_HFNModified(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 131071U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_COUNTValueExtended(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_COUNTValueExtended, COUNTValueExtended_sequence);
return offset;
}
static int
dissect_x2ap_PDCP_SNlength18(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 262143U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_HFNforPDCP_SNlength18(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16383U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_COUNTvaluePDCP_SNlength18(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_COUNTvaluePDCP_SNlength18, COUNTvaluePDCP_SNlength18_sequence);
return offset;
}
static int
dissect_x2ap_INTEGER_0_15_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_CoverageModification_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CoverageModification_Item, CoverageModification_Item_sequence);
return offset;
}
static int
dissect_x2ap_CoverageModificationList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CoverageModificationList, CoverageModificationList_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_TypeOfError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_CriticalityDiagnostics_IE_List_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CriticalityDiagnostics_IE_List_item, CriticalityDiagnostics_IE_List_item_sequence);
return offset;
}
static int
dissect_x2ap_CriticalityDiagnostics_IE_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CriticalityDiagnostics_IE_List, CriticalityDiagnostics_IE_List_sequence_of,
1, maxNrOfErrors, FALSE);
return offset;
}
static int
dissect_x2ap_CriticalityDiagnostics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CriticalityDiagnostics, CriticalityDiagnostics_sequence);
return offset;
}
static int
dissect_x2ap_CRNTI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_CSGMembershipStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_x2ap_CSG_Id(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
27, 27, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_UEID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_INTEGER_1_7_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 7U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_INTEGER_1_8_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 8U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_INTEGER_0_7_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_WidebandCQICodeword1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_WidebandCQICodeword1, WidebandCQICodeword1_choice,
NULL);
return offset;
}
static int
dissect_x2ap_WidebandCQI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_WidebandCQI, WidebandCQI_sequence);
return offset;
}
static int
dissect_x2ap_SubbandSize(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_INTEGER_0_3_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_SubbandCQICodeword0(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_SubbandCQICodeword0, SubbandCQICodeword0_choice,
NULL);
return offset;
}
static int
dissect_x2ap_SubbandCQICodeword1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_SubbandCQICodeword1, SubbandCQICodeword1_choice,
NULL);
return offset;
}
static int
dissect_x2ap_SubbandCQI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SubbandCQI, SubbandCQI_sequence);
return offset;
}
static int
dissect_x2ap_INTEGER_0_27_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 27U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_SubbandCQIItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SubbandCQIItem, SubbandCQIItem_sequence);
return offset;
}
static int
dissect_x2ap_SubbandCQIList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_SubbandCQIList, SubbandCQIList_sequence_of,
1, maxSubband, FALSE);
return offset;
}
static int
dissect_x2ap_CSIReportPerCSIProcessItem_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CSIReportPerCSIProcessItem_item, CSIReportPerCSIProcessItem_item_sequence);
return offset;
}
static int
dissect_x2ap_CSIReportPerCSIProcessItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CSIReportPerCSIProcessItem, CSIReportPerCSIProcessItem_sequence_of,
1, maxCSIReport, FALSE);
return offset;
}
static int
dissect_x2ap_CSIReportPerCSIProcess_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CSIReportPerCSIProcess_item, CSIReportPerCSIProcess_item_sequence);
return offset;
}
static int
dissect_x2ap_CSIReportPerCSIProcess(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CSIReportPerCSIProcess, CSIReportPerCSIProcess_sequence_of,
1, maxCSIProcess, FALSE);
return offset;
}
static int
dissect_x2ap_CSIReportList_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CSIReportList_item, CSIReportList_item_sequence);
return offset;
}
static int
dissect_x2ap_CSIReportList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CSIReportList, CSIReportList_sequence_of,
1, maxUEReport, FALSE);
return offset;
}
static int
dissect_x2ap_DeactivationIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_DL_Forwarding(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_DL_GBR_PRB_usage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_DL_non_GBR_PRB_usage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_DL_Total_PRB_usage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_T_transmissionModes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 428 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, &parameter_tvb, NULL);
if(parameter_tvb){
const gint *fields[] = {
&hf_x2ap_MDT_transmissionModes_tm1,
&hf_x2ap_MDT_transmissionModes_tm2,
&hf_x2ap_MDT_transmissionModes_tm3,
&hf_x2ap_MDT_transmissionModes_tm4,
&hf_x2ap_MDT_transmissionModes_tm6,
&hf_x2ap_MDT_transmissionModes_tm8,
&hf_x2ap_MDT_transmissionModes_tm9,
&hf_x2ap_MDT_transmissionModes_tm10,
NULL
};
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_transmissionModes);
proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 1, fields, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_x2ap_INTEGER_0_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_PA_Values(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_SEQUENCE_SIZE_0_maxnoofPA_OF_PA_Values(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_SEQUENCE_SIZE_0_maxnoofPA_OF_PA_Values, SEQUENCE_SIZE_0_maxnoofPA_OF_PA_Values_sequence_of,
0, maxnoofPA, FALSE);
return offset;
}
static int
dissect_x2ap_DynamicNAICSInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_DynamicNAICSInformation, DynamicNAICSInformation_sequence);
return offset;
}
static int
dissect_x2ap_DynamicDLTransmissionInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_DynamicDLTransmissionInformation, DynamicDLTransmissionInformation_choice,
NULL);
return offset;
}
static int
dissect_x2ap_EARFCN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxEARFCN, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_EARFCNExtension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
maxEARFCNPlusOne, newmaxEARFCN, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_BIT_STRING_SIZE_12_8800_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
12, 8800, TRUE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_RNTP_Threshold(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_EnhancedRNTPStartTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_EnhancedRNTPStartTime, EnhancedRNTPStartTime_sequence);
return offset;
}
static int
dissect_x2ap_EnhancedRNTP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_EnhancedRNTP, EnhancedRNTP_sequence);
return offset;
}
static int
dissect_x2ap_BIT_STRING_SIZE_20(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
20, 20, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_BIT_STRING_SIZE_28(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_ENB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_ENB_ID, ENB_ID_choice,
NULL);
return offset;
}
static int
dissect_x2ap_EncryptionAlgorithms(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 335 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, TRUE, &parameter_tvb, NULL);
if(parameter_tvb){
const gint *fields[] = {
&hf_x2ap_encryptionAlgorithms_EEA1,
&hf_x2ap_encryptionAlgorithms_EEA2,
&hf_x2ap_encryptionAlgorithms_EEA3,
&hf_x2ap_encryptionAlgorithms_Reserved,
NULL
};
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_EncryptionAlgorithms);
proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 2, fields, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_x2ap_EPLMNs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_EPLMNs, EPLMNs_sequence_of,
1, maxnoofEPLMNs, FALSE);
return offset;
}
static int
dissect_x2ap_E_RAB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_QCI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_GBR_QosInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_GBR_QosInformation, GBR_QosInformation_sequence);
return offset;
}
static int
dissect_x2ap_E_RAB_Level_QoS_Parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RAB_Level_QoS_Parameters, E_RAB_Level_QoS_Parameters_sequence);
return offset;
}
static int
dissect_x2ap_E_RAB_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RAB_List, E_RAB_List_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RAB_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RAB_Item, E_RAB_Item_sequence);
return offset;
}
static int
dissect_x2ap_Transmission_Bandwidth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 1, NULL);
return offset;
}
static int
dissect_x2ap_FDD_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_FDD_Info, FDD_Info_sequence);
return offset;
}
static int
dissect_x2ap_SubframeAssignment(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_SpecialSubframePatterns(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
9, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_SpecialSubframe_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SpecialSubframe_Info, SpecialSubframe_Info_sequence);
return offset;
}
static int
dissect_x2ap_TDD_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_TDD_Info, TDD_Info_sequence);
return offset;
}
static int
dissect_x2ap_EUTRA_Mode_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_EUTRA_Mode_Info, EUTRA_Mode_Info_choice,
NULL);
return offset;
}
static int
dissect_x2ap_EUTRANTraceID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 232 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_EUTRANTraceID);
dissect_e212_mcc_mnc(parameter_tvb, actx->pinfo, subtree, 0, E212_NONE, FALSE);
proto_tree_add_item(subtree, hf_x2ap_eUTRANTraceID_TraceID, parameter_tvb, 3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_x2ap_eUTRANTraceID_TraceRecordingSessionReference, parameter_tvb, 6, 2, ENC_BIG_ENDIAN);
return offset;
}
static int
dissect_x2ap_EventType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ExpectedActivityPeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 181U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_ExpectedIdlePeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 181U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_SourceOfUEActivityBehaviourInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ExpectedUEActivityBehaviour(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ExpectedUEActivityBehaviour, ExpectedUEActivityBehaviour_sequence);
return offset;
}
static int
dissect_x2ap_ExpectedHOInterval(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ExpectedUEBehaviour(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ExpectedUEBehaviour, ExpectedUEBehaviour_sequence);
return offset;
}
static int
dissect_x2ap_BIT_STRING_SIZE_5(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
5, 5, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_UL_InterferenceOverloadIndication_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_UL_InterferenceOverloadIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_UL_InterferenceOverloadIndication, UL_InterferenceOverloadIndication_sequence_of,
1, maxnoofPRBs, FALSE);
return offset;
}
static int
dissect_x2ap_ExtendedULInterferenceOverloadInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ExtendedULInterferenceOverloadInfo, ExtendedULInterferenceOverloadInfo_sequence);
return offset;
}
static int
dissect_x2ap_ForbiddenInterRATs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 2, NULL);
return offset;
}
static int
dissect_x2ap_ForbiddenTACs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ForbiddenTACs, ForbiddenTACs_sequence_of,
1, maxnoofForbTACs, FALSE);
return offset;
}
static int
dissect_x2ap_ForbiddenTAs_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ForbiddenTAs_Item, ForbiddenTAs_Item_sequence);
return offset;
}
static int
dissect_x2ap_ForbiddenTAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ForbiddenTAs, ForbiddenTAs_sequence_of,
1, maxnoofEPLMNsPlusOne, FALSE);
return offset;
}
static int
dissect_x2ap_LAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 292 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
2, 2, FALSE, &parameter_tvb);
if (parameter_tvb) {
actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_x2ap_ForbiddenLACs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ForbiddenLACs, ForbiddenLACs_sequence_of,
1, maxnoofForbLACs, FALSE);
return offset;
}
static int
dissect_x2ap_ForbiddenLAs_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ForbiddenLAs_Item, ForbiddenLAs_Item_sequence);
return offset;
}
static int
dissect_x2ap_ForbiddenLAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ForbiddenLAs, ForbiddenLAs_sequence_of,
1, maxnoofEPLMNsPlusOne, FALSE);
return offset;
}
static int
dissect_x2ap_Fourframes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
24, 24, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_FreqBandIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 256U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_FreqBandIndicatorPriority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_GlobalENB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_GlobalENB_ID, GlobalENB_ID_sequence);
return offset;
}
static int
dissect_x2ap_TransportLayerAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 95 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
proto_tree *subtree;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 160, TRUE, &parameter_tvb, &len);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_TransportLayerAddress);
if (len == 32) {
proto_tree_add_item(subtree, hf_x2ap_transportLayerAddressIPv4, parameter_tvb, 0, 4, ENC_BIG_ENDIAN);
} else if (len == 128) {
proto_tree_add_item(subtree, hf_x2ap_transportLayerAddressIPv6, parameter_tvb, 0, 16, ENC_NA);
} else if (len == 160) {
proto_tree_add_item(subtree, hf_x2ap_transportLayerAddressIPv4, parameter_tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_x2ap_transportLayerAddressIPv6, parameter_tvb, 4, 16, ENC_NA);
}
return offset;
}
static int
dissect_x2ap_GTP_TEI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_GTPtunnelEndpoint(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_GTPtunnelEndpoint, GTPtunnelEndpoint_sequence);
return offset;
}
static int
dissect_x2ap_MME_Group_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 328 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
2, 2, FALSE, &parameter_tvb);
if (parameter_tvb) {
actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_x2ap_GU_Group_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_GU_Group_ID, GU_Group_ID_sequence);
return offset;
}
static int
dissect_x2ap_GUGroupIDList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_GUGroupIDList, GUGroupIDList_sequence_of,
1, maxPools, FALSE);
return offset;
}
static int
dissect_x2ap_MME_Code(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 319 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
1, 1, FALSE, &parameter_tvb);
if (parameter_tvb) {
actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_x2ap_GUMMEI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_GUMMEI, GUMMEI_sequence);
return offset;
}
static int
dissect_x2ap_HandoverReportType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 1, NULL);
return offset;
}
static int
dissect_x2ap_HandoverRestrictionList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_HandoverRestrictionList, HandoverRestrictionList_sequence);
return offset;
}
static int
dissect_x2ap_LoadIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_HWLoadIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_HWLoadIndicator, HWLoadIndicator_sequence);
return offset;
}
static int
dissect_x2ap_IntegrityProtectionAlgorithms(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 350 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, TRUE, &parameter_tvb, NULL);
if(parameter_tvb){
const gint *fields[] = {
&hf_x2ap_integrityProtectionAlgorithms_EIA1,
&hf_x2ap_integrityProtectionAlgorithms_EIA2,
&hf_x2ap_integrityProtectionAlgorithms_EIA3,
&hf_x2ap_integrityProtectionAlgorithms_Reserved,
NULL
};
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_IntegrityProtectionAlgorithms);
proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 2, fields, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_x2ap_InterfacesToTrace(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 243 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, &parameter_tvb, NULL);
if(parameter_tvb){
const gint *fields[] = {
&hf_x2ap_interfacesToTrace_S1_MME,
&hf_x2ap_interfacesToTrace_X2,
&hf_x2ap_interfacesToTrace_Uu,
&hf_x2ap_interfacesToTrace_Reserved,
NULL
};
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_InterfacesToTrace);
proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 1, fields, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_x2ap_InvokeIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 2, NULL);
return offset;
}
static int
dissect_x2ap_Time_UE_StayedInCell(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_LastVisitedEUTRANCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_LastVisitedEUTRANCellInformation, LastVisitedEUTRANCellInformation_sequence);
return offset;
}
static int
dissect_x2ap_LastVisitedUTRANCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_LastVisitedGERANCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_LastVisitedGERANCellInformation, LastVisitedGERANCellInformation_choice,
NULL);
return offset;
}
static int
dissect_x2ap_LastVisitedCell_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_LastVisitedCell_Item, LastVisitedCell_Item_choice,
NULL);
return offset;
}
static int
dissect_x2ap_LHN_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 449 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
32, 256, FALSE, &parameter_tvb);
actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, -1, ENC_UTF_8|ENC_NA);
return offset;
}
static int
dissect_x2ap_Links_to_log(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ReportArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_LocationReportingInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_LocationReportingInformation, LocationReportingInformation_sequence);
return offset;
}
static int
dissect_x2ap_ReportIntervalMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
13, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ReportAmountMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_x2ap_M1PeriodicReporting(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_M1PeriodicReporting, M1PeriodicReporting_sequence);
return offset;
}
static int
dissect_x2ap_M1ReportingTrigger(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 1, NULL);
return offset;
}
static int
dissect_x2ap_Threshold_RSRP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 97U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_Threshold_RSRQ(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 34U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_MeasurementThresholdA2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_MeasurementThresholdA2, MeasurementThresholdA2_choice,
NULL);
return offset;
}
static int
dissect_x2ap_M1ThresholdEventA2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_M1ThresholdEventA2, M1ThresholdEventA2_sequence);
return offset;
}
static int
dissect_x2ap_M3period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_M3Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_M3Configuration, M3Configuration_sequence);
return offset;
}
static int
dissect_x2ap_M4period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_M4Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_M4Configuration, M4Configuration_sequence);
return offset;
}
static int
dissect_x2ap_M5period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_M5Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_M5Configuration, M5Configuration_sequence);
return offset;
}
static int
dissect_x2ap_M6report_interval(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_M6delay_threshold(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
12, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_M6Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_M6Configuration, M6Configuration_sequence);
return offset;
}
static int
dissect_x2ap_M7period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 60U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_M7Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_M7Configuration, M7Configuration_sequence);
return offset;
}
static int
dissect_x2ap_ManagementBasedMDTallowed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_Masked_IMEISV(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
64, 64, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_MDT_Activation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_MeasurementsToActivate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 380 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, &parameter_tvb, NULL);
if(parameter_tvb){
const gint *fields[] = {
&hf_x2ap_measurementsToActivate_M1,
&hf_x2ap_measurementsToActivate_M2,
&hf_x2ap_measurementsToActivate_M3,
&hf_x2ap_measurementsToActivate_M4,
&hf_x2ap_measurementsToActivate_M5,
&hf_x2ap_measurementsToActivate_LoggingM1FromEventTriggered,
&hf_x2ap_measurementsToActivate_M6,
&hf_x2ap_measurementsToActivate_M7,
NULL
};
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_MeasurementsToActivate);
proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 1, fields, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_x2ap_MDT_Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MDT_Configuration, MDT_Configuration_sequence);
return offset;
}
static int
dissect_x2ap_MDTPLMNList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_MDTPLMNList, MDTPLMNList_sequence_of,
1, maxnoofMDTPLMNs, FALSE);
return offset;
}
static int
dissect_x2ap_MDT_Location_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 405 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, &parameter_tvb, NULL);
if(parameter_tvb){
const gint *fields[] = {
&hf_x2ap_MDT_Location_Info_GNSS,
&hf_x2ap_MDT_Location_Info_E_CID,
&hf_x2ap_MDT_Location_Info_Reserved,
NULL
};
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_MDT_Location_Info);
proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 1, fields, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_x2ap_Measurement_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 4095U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_MeNBtoSeNBContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 214 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_MeNBtoSeNBContainer);
dissect_lte_rrc_SCG_ConfigInfo_r12_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
return offset;
}
static int
dissect_x2ap_MBMS_Service_Area_Identity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_MBMS_Service_Area_Identity_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_MBMS_Service_Area_Identity_List, MBMS_Service_Area_Identity_List_sequence_of,
1, maxnoofMBMSServiceAreaIdentities, FALSE);
return offset;
}
static int
dissect_x2ap_RadioframeAllocationPeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_RadioframeAllocationOffset(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_Oneframe(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
6, 6, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_SubframeAllocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_SubframeAllocation, SubframeAllocation_choice,
NULL);
return offset;
}
static int
dissect_x2ap_MBSFN_Subframe_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MBSFN_Subframe_Info, MBSFN_Subframe_Info_sequence);
return offset;
}
static int
dissect_x2ap_MBSFN_Subframe_Infolist(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_MBSFN_Subframe_Infolist, MBSFN_Subframe_Infolist_sequence_of,
1, maxnoofMBSFN, FALSE);
return offset;
}
static int
dissect_x2ap_INTEGER_M20_20(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-20, 20U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_MobilityParametersModificationRange(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MobilityParametersModificationRange, MobilityParametersModificationRange_sequence);
return offset;
}
static int
dissect_x2ap_MobilityParametersInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MobilityParametersInformation, MobilityParametersInformation_sequence);
return offset;
}
static int
dissect_x2ap_BandInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_BandInfo, BandInfo_sequence);
return offset;
}
static int
dissect_x2ap_MultibandInfoList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_MultibandInfoList, MultibandInfoList_sequence_of,
1, maxnoofBands, FALSE);
return offset;
}
static int
dissect_x2ap_PCI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 503U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_Neighbour_Information_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_Neighbour_Information_item, Neighbour_Information_item_sequence);
return offset;
}
static int
dissect_x2ap_Neighbour_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_Neighbour_Information, Neighbour_Information_sequence_of,
0, maxnoofNeighbours, FALSE);
return offset;
}
static int
dissect_x2ap_Number_of_Antennaports(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_OffsetOfNbiotChannelNumberToEARFCN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
21, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_Port_Number(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 120 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
2, 2, FALSE, &parameter_tvb);
if (parameter_tvb) {
actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_x2ap_INTEGER_0_837(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 837U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_INTEGER_0_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_x2ap_INTEGER_0_94(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 94U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_INTEGER_0_63(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_PRACH_Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_PRACH_Configuration, PRACH_Configuration_sequence);
return offset;
}
static int
dissect_x2ap_ProSeDirectDiscovery(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ProSeDirectCommunication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ProSeAuthorized(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ProSeAuthorized, ProSeAuthorized_sequence);
return offset;
}
static int
dissect_x2ap_ProSeUEtoNetworkRelaying(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_UL_GBR_PRB_usage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_UL_non_GBR_PRB_usage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_UL_Total_PRB_usage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_RadioResourceStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_RadioResourceStatus, RadioResourceStatus_sequence);
return offset;
}
static int
dissect_x2ap_ReceiveStatusofULPDCPSDUs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
4096, 4096, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_ReceiveStatusOfULPDCPSDUsExtended(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16384, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 131072, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_Registration_Request(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 2, NULL);
return offset;
}
static int
dissect_x2ap_BIT_STRING_SIZE_6_110_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
6, 110, TRUE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_T_numberOfCellSpecificAntennaPorts_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_INTEGER_0_4_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_RelativeNarrowbandTxPower(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_RelativeNarrowbandTxPower, RelativeNarrowbandTxPower_sequence);
return offset;
}
static int
dissect_x2ap_ReportCharacteristics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 155 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
32, 32, FALSE, &parameter_tvb, NULL);
if(parameter_tvb){
const gint *fields[] = {
&hf_x2ap_ReportCharacteristics_PRBPeriodic,
&hf_x2ap_ReportCharacteristics_TNLLoadIndPeriodic,
&hf_x2ap_ReportCharacteristics_HWLoadIndPeriodic,
&hf_x2ap_ReportCharacteristics_CompositeAvailableCapacityPeriodic,
&hf_x2ap_ReportCharacteristics_ABSStatusPeriodic,
&hf_x2ap_ReportCharacteristics_RSRPMeasurementReportPeriodic,
&hf_x2ap_ReportCharacteristics_CSIReportPeriodic,
&hf_x2ap_ReportCharacteristics_Reserved,
NULL
};
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_ReportCharacteristics);
proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 4, fields, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_x2ap_ReportingPeriodicityCSIR(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ReportingPeriodicityRSRPMR(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_BIT_STRING_SIZE_24(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
24, 24, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_ResumeID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResumeID, ResumeID_choice,
NULL);
return offset;
}
static int
dissect_x2ap_RRC_Context(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 131 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_RRC_Context);
if (g_x2ap_dissect_rrc_context_as == X2AP_RRC_CONTEXT_NBIOT) {
dissect_lte_rrc_HandoverPreparationInformation_NB_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
} else {
dissect_lte_rrc_HandoverPreparationInformation_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
}
return offset;
}
static int
dissect_x2ap_RRCConnReestabIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_RRCConnSetupIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_INTEGER_0_97_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 97U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_RSRPMeasurementResult_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_RSRPMeasurementResult_item, RSRPMeasurementResult_item_sequence);
return offset;
}
static int
dissect_x2ap_RSRPMeasurementResult(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_RSRPMeasurementResult, RSRPMeasurementResult_sequence_of,
1, maxCellReport, FALSE);
return offset;
}
static int
dissect_x2ap_RSRPMRList_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_RSRPMRList_item, RSRPMRList_item_sequence);
return offset;
}
static int
dissect_x2ap_RSRPMRList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_RSRPMRList, RSRPMRList_sequence_of,
1, maxUEReport, FALSE);
return offset;
}
static int
dissect_x2ap_S1TNLLoadIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_S1TNLLoadIndicator, S1TNLLoadIndicator_sequence);
return offset;
}
static int
dissect_x2ap_SCGChangeIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_SeNBSecurityKey(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
256, 256, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_SeNBtoMeNBContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 223 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_SeNBtoMeNBContainer);
dissect_lte_rrc_SCG_ConfigInfo_r12_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
return offset;
}
static int
dissect_x2ap_ServedCell_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ServedCell_Information, ServedCell_Information_sequence);
return offset;
}
static int
dissect_x2ap_ServedCells_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ServedCells_item, ServedCells_item_sequence);
return offset;
}
static int
dissect_x2ap_ServedCells(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ServedCells, ServedCells_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_SIPTOBearerDeactivationIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ShortMAC_I(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_SRVCCOperationPossible(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_SubscriberProfileIDforRFP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 256U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_TargetCellInUTRAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_x2ap_TargeteNBtoSource_eNBTransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 76 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_TargeteNBtoSource_eNBTransparentContainer);
dissect_lte_rrc_HandoverCommand_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
return offset;
}
static int
dissect_x2ap_TimeToWait(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_Time_UE_StayedInCell_EnhancedGranularity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 40950U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_TraceDepth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_TraceCollectionEntityIPAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 258 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
proto_tree *subtree;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 160, TRUE, &parameter_tvb, &len);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_TraceCollectionEntityIPAddress);
if (len == 32) {
proto_tree_add_item(subtree, hf_x2ap_traceCollectionEntityIPAddress_IPv4, parameter_tvb, 0, 4, ENC_BIG_ENDIAN);
} else if (len == 128) {
proto_tree_add_item(subtree, hf_x2ap_traceCollectionEntityIPAddress_IPv6, parameter_tvb, 0, 16, ENC_NA);
} else if (len == 160) {
proto_tree_add_item(subtree, hf_x2ap_traceCollectionEntityIPAddress_IPv4, parameter_tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_x2ap_traceCollectionEntityIPAddress_IPv6, parameter_tvb, 4, 16, ENC_NA);
}
return offset;
}
static int
dissect_x2ap_TraceActivation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_TraceActivation, TraceActivation_sequence);
return offset;
}
static int
dissect_x2ap_TunnelInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_TunnelInformation, TunnelInformation_sequence);
return offset;
}
static int
dissect_x2ap_UEAggregateMaximumBitRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UEAggregateMaximumBitRate, UEAggregateMaximumBitRate_sequence);
return offset;
}
static int
dissect_x2ap_UE_ContextKeptIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_UE_HistoryInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_UE_HistoryInformation, UE_HistoryInformation_sequence_of,
1, maxnoofCells, FALSE);
return offset;
}
static int
dissect_x2ap_UE_HistoryInformationFromTheUE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 146 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_UE_HistoryInformationFromTheUE);
dissect_lte_rrc_VisitedCellInfoList_r12_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
return offset;
}
static int
dissect_x2ap_UE_S1AP_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_UE_X2AP_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_UE_X2AP_ID_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_UE_RLF_Report_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 196 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_UE_RLF_Report_Container);
dissect_lte_rrc_RLF_Report_r9_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
return offset;
}
static int
dissect_x2ap_UE_RLF_Report_Container_for_extended_bands(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 205 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_UE_RLF_Report_Container_for_extended_bands);
dissect_lte_rrc_RLF_Report_v9e0_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
return offset;
}
static int
dissect_x2ap_UESecurityCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UESecurityCapabilities, UESecurityCapabilities_sequence);
return offset;
}
static int
dissect_x2ap_UL_HighInterferenceIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 110, TRUE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_UL_HighInterferenceIndicationInfo_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UL_HighInterferenceIndicationInfo_Item, UL_HighInterferenceIndicationInfo_Item_sequence);
return offset;
}
static int
dissect_x2ap_UL_HighInterferenceIndicationInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_UL_HighInterferenceIndicationInfo, UL_HighInterferenceIndicationInfo_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_X2BenefitValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 8U, NULL, TRUE);
return offset;
}
static int
dissect_x2ap_HandoverRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 463 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_HandoverRequest, HandoverRequest_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeSetup_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeSetup_List, E_RABs_ToBeSetup_List_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_UE_ContextInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UE_ContextInformation, UE_ContextInformation_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeSetup_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeSetup_Item, E_RABs_ToBeSetup_Item_sequence);
return offset;
}
static int
dissect_x2ap_MobilityInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
32, 32, FALSE, NULL, NULL);
return offset;
}
static int
dissect_x2ap_UE_ContextReferenceAtSeNB(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UE_ContextReferenceAtSeNB, UE_ContextReferenceAtSeNB_sequence);
return offset;
}
static int
dissect_x2ap_HandoverRequestAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 465 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverRequestAcknowledge");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_HandoverRequestAcknowledge, HandoverRequestAcknowledge_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_List, E_RABs_Admitted_List_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_Item, E_RABs_Admitted_Item_sequence);
return offset;
}
static int
dissect_x2ap_HandoverPreparationFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 467 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverPreparationFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_HandoverPreparationFailure, HandoverPreparationFailure_sequence);
return offset;
}
static int
dissect_x2ap_HandoverReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 505 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverReport");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_HandoverReport, HandoverReport_sequence);
return offset;
}
static int
dissect_x2ap_SNStatusTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 469 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SNStatusTransfer");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SNStatusTransfer, SNStatusTransfer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_SubjectToStatusTransfer_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_SubjectToStatusTransfer_List, E_RABs_SubjectToStatusTransfer_List_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RABs_SubjectToStatusTransfer_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_SubjectToStatusTransfer_Item, E_RABs_SubjectToStatusTransfer_Item_sequence);
return offset;
}
static int
dissect_x2ap_UEContextRelease(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 471 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextRelease");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UEContextRelease, UEContextRelease_sequence);
return offset;
}
static int
dissect_x2ap_HandoverCancel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 473 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverCancel");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_HandoverCancel, HandoverCancel_sequence);
return offset;
}
static int
dissect_x2ap_ErrorIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 475 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ErrorIndication");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ErrorIndication, ErrorIndication_sequence);
return offset;
}
static int
dissect_x2ap_ResetRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 477 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ResetRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResetRequest, ResetRequest_sequence);
return offset;
}
static int
dissect_x2ap_ResetResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 479 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ResetResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResetResponse, ResetResponse_sequence);
return offset;
}
static int
dissect_x2ap_X2SetupRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 481 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "X2SetupRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_X2SetupRequest, X2SetupRequest_sequence);
return offset;
}
static int
dissect_x2ap_X2SetupResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 483 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "X2SetupResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_X2SetupResponse, X2SetupResponse_sequence);
return offset;
}
static int
dissect_x2ap_X2SetupFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 485 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "X2SetupFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_X2SetupFailure, X2SetupFailure_sequence);
return offset;
}
static int
dissect_x2ap_LoadInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 487 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "LoadInformation");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_LoadInformation, LoadInformation_sequence);
return offset;
}
static int
dissect_x2ap_CellInformation_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellInformation_List, CellInformation_List_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_CellInformation_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellInformation_Item, CellInformation_Item_sequence);
return offset;
}
static int
dissect_x2ap_ENBConfigurationUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 489 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBConfigurationUpdate");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ENBConfigurationUpdate, ENBConfigurationUpdate_sequence);
return offset;
}
static int
dissect_x2ap_ServedCellsToModify_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ServedCellsToModify_Item, ServedCellsToModify_Item_sequence);
return offset;
}
static int
dissect_x2ap_ServedCellsToModify(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ServedCellsToModify, ServedCellsToModify_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_Old_ECGIs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_Old_ECGIs, Old_ECGIs_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_ENBConfigurationUpdateAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 491 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBConfigurationUpdateAcknowledge");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ENBConfigurationUpdateAcknowledge, ENBConfigurationUpdateAcknowledge_sequence);
return offset;
}
static int
dissect_x2ap_ENBConfigurationUpdateFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 493 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBConfigurationUpdateFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ENBConfigurationUpdateFailure, ENBConfigurationUpdateFailure_sequence);
return offset;
}
static int
dissect_x2ap_ResourceStatusRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 495 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ResourceStatusRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResourceStatusRequest, ResourceStatusRequest_sequence);
return offset;
}
static int
dissect_x2ap_CellToReport_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellToReport_List, CellToReport_List_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_CellToReport_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellToReport_Item, CellToReport_Item_sequence);
return offset;
}
static int
dissect_x2ap_ReportingPeriodicity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_PartialSuccessIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_x2ap_ResourceStatusResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 497 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ResourceStatusResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResourceStatusResponse, ResourceStatusResponse_sequence);
return offset;
}
static int
dissect_x2ap_MeasurementInitiationResult_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_MeasurementInitiationResult_List, MeasurementInitiationResult_List_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_MeasurementFailureCause_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_MeasurementFailureCause_List, MeasurementFailureCause_List_sequence_of,
1, maxFailedMeasObjects, FALSE);
return offset;
}
static int
dissect_x2ap_MeasurementInitiationResult_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MeasurementInitiationResult_Item, MeasurementInitiationResult_Item_sequence);
return offset;
}
static int
dissect_x2ap_T_measurementFailedReportCharacteristics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 174 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
32, 32, FALSE, &parameter_tvb, NULL);
if(parameter_tvb){
const gint *fields[] = {
&hf_x2ap_measurementFailedReportCharacteristics_PRBPeriodic,
&hf_x2ap_measurementFailedReportCharacteristics_TNLLoadIndPeriodic,
&hf_x2ap_measurementFailedReportCharacteristics_HWLoadIndPeriodic,
&hf_x2ap_measurementFailedReportCharacteristics_CompositeAvailableCapacityPeriodic,
&hf_x2ap_measurementFailedReportCharacteristics_ABSStatusPeriodic,
&hf_x2ap_measurementFailedReportCharacteristics_RSRPMeasurementReportPeriodic,
&hf_x2ap_measurementFailedReportCharacteristics_CSIReportPeriodic,
&hf_x2ap_measurementFailedReportCharacteristics_Reserved,
NULL
};
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_measurementFailedReportCharacteristics);
proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 4, fields, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_x2ap_MeasurementFailureCause_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MeasurementFailureCause_Item, MeasurementFailureCause_Item_sequence);
return offset;
}
static int
dissect_x2ap_ResourceStatusFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 499 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ResourceStatusFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResourceStatusFailure, ResourceStatusFailure_sequence);
return offset;
}
static int
dissect_x2ap_CompleteFailureCauseInformation_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CompleteFailureCauseInformation_List, CompleteFailureCauseInformation_List_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_CompleteFailureCauseInformation_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CompleteFailureCauseInformation_Item, CompleteFailureCauseInformation_Item_sequence);
return offset;
}
static int
dissect_x2ap_ResourceStatusUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 501 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ResourceStatusUpdate");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResourceStatusUpdate, ResourceStatusUpdate_sequence);
return offset;
}
static int
dissect_x2ap_CellMeasurementResult_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellMeasurementResult_List, CellMeasurementResult_List_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_CellMeasurementResult_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellMeasurementResult_Item, CellMeasurementResult_Item_sequence);
return offset;
}
static int
dissect_x2ap_PrivateMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 503 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "PrivateMessage");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_PrivateMessage, PrivateMessage_sequence);
return offset;
}
static int
dissect_x2ap_MobilityChangeRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 509 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MobilityChangeRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MobilityChangeRequest, MobilityChangeRequest_sequence);
return offset;
}
static int
dissect_x2ap_MobilityChangeAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 511 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MobilityChangeAcknowledge");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MobilityChangeAcknowledge, MobilityChangeAcknowledge_sequence);
return offset;
}
static int
dissect_x2ap_MobilityChangeFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 513 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MobilityChangeFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_MobilityChangeFailure, MobilityChangeFailure_sequence);
return offset;
}
static int
dissect_x2ap_RLFIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 507 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "RLFIndication");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_RLFIndication, RLFIndication_sequence);
return offset;
}
static int
dissect_x2ap_CellActivationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 515 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "CellActivationRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellActivationRequest, CellActivationRequest_sequence);
return offset;
}
static int
dissect_x2ap_ServedCellsToActivate_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ServedCellsToActivate_Item, ServedCellsToActivate_Item_sequence);
return offset;
}
static int
dissect_x2ap_ServedCellsToActivate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ServedCellsToActivate, ServedCellsToActivate_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_CellActivationResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 517 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "CellActivationResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellActivationResponse, CellActivationResponse_sequence);
return offset;
}
static int
dissect_x2ap_ActivatedCellList_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ActivatedCellList_Item, ActivatedCellList_Item_sequence);
return offset;
}
static int
dissect_x2ap_ActivatedCellList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_ActivatedCellList, ActivatedCellList_sequence_of,
1, maxCellineNB, FALSE);
return offset;
}
static int
dissect_x2ap_CellActivationFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 519 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "CellActivationFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_CellActivationFailure, CellActivationFailure_sequence);
return offset;
}
static int
dissect_x2ap_X2Release(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 521 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "X2Release");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_X2Release, X2Release_sequence);
return offset;
}
static int
dissect_x2ap_X2APMessageTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 523 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "X2APMessageTransfer");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_X2APMessageTransfer, X2APMessageTransfer_sequence);
return offset;
}
static int
dissect_x2ap_RNL_Header(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_RNL_Header, RNL_Header_sequence);
return offset;
}
static int
dissect_x2ap_X2AP_Message(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 454 "./asn1/x2ap/x2ap.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (parameter_tvb) {
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_x2ap_X2AP_Message);
dissect_X2AP_PDU_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
}
return offset;
}
static int
dissect_x2ap_SeNBAdditionRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 531 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SeNBAdditionRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SeNBAdditionRequest, SeNBAdditionRequest_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeAdded_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeAdded_List, E_RABs_ToBeAdded_List_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeAdded_Item_SCG_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeAdded_Item_SCG_Bearer, E_RABs_ToBeAdded_Item_SCG_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeAdded_Item_Split_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeAdded_Item_Split_Bearer, E_RABs_ToBeAdded_Item_Split_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeAdded_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeAdded_Item, E_RABs_ToBeAdded_Item_choice,
NULL);
return offset;
}
static int
dissect_x2ap_SeNBAdditionRequestAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 533 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SeNBAdditionRequestAcknowledge");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SeNBAdditionRequestAcknowledge, SeNBAdditionRequestAcknowledge_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToBeAdded_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToBeAdded_List, E_RABs_Admitted_ToBeAdded_List_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToBeAdded_Item_SCG_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToBeAdded_Item_SCG_Bearer, E_RABs_Admitted_ToBeAdded_Item_SCG_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToBeAdded_Item_Split_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToBeAdded_Item_Split_Bearer, E_RABs_Admitted_ToBeAdded_Item_Split_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToBeAdded_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToBeAdded_Item, E_RABs_Admitted_ToBeAdded_Item_choice,
NULL);
return offset;
}
static int
dissect_x2ap_SeNBAdditionRequestReject(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 535 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SeNBAdditionRequestReject");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SeNBAdditionRequestReject, SeNBAdditionRequestReject_sequence);
return offset;
}
static int
dissect_x2ap_SeNBReconfigurationComplete(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 537 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SeNBReconfigurationComplete");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SeNBReconfigurationComplete, SeNBReconfigurationComplete_sequence);
return offset;
}
static int
dissect_x2ap_ResponseInformationSeNBReconfComp_SuccessItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResponseInformationSeNBReconfComp_SuccessItem, ResponseInformationSeNBReconfComp_SuccessItem_sequence);
return offset;
}
static int
dissect_x2ap_ResponseInformationSeNBReconfComp_RejectByMeNBItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResponseInformationSeNBReconfComp_RejectByMeNBItem, ResponseInformationSeNBReconfComp_RejectByMeNBItem_sequence);
return offset;
}
static int
dissect_x2ap_ResponseInformationSeNBReconfComp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_ResponseInformationSeNBReconfComp, ResponseInformationSeNBReconfComp_choice,
NULL);
return offset;
}
static int
dissect_x2ap_SeNBModificationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 539 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SeNBModificationRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SeNBModificationRequest, SeNBModificationRequest_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeAdded_List_ModReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeAdded_List_ModReq, E_RABs_ToBeAdded_List_ModReq_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeModified_List_ModReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeModified_List_ModReq, E_RABs_ToBeModified_List_ModReq_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeReleased_List_ModReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeReleased_List_ModReq, E_RABs_ToBeReleased_List_ModReq_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_UE_ContextInformationSeNBModReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UE_ContextInformationSeNBModReq, UE_ContextInformationSeNBModReq_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeAdded_ModReqItem_SCG_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeAdded_ModReqItem_SCG_Bearer, E_RABs_ToBeAdded_ModReqItem_SCG_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeAdded_ModReqItem_Split_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeAdded_ModReqItem_Split_Bearer, E_RABs_ToBeAdded_ModReqItem_Split_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeAdded_ModReqItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeAdded_ModReqItem, E_RABs_ToBeAdded_ModReqItem_choice,
NULL);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeModified_ModReqItem_SCG_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeModified_ModReqItem_SCG_Bearer, E_RABs_ToBeModified_ModReqItem_SCG_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeModified_ModReqItem_Split_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeModified_ModReqItem_Split_Bearer, E_RABs_ToBeModified_ModReqItem_Split_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeModified_ModReqItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeModified_ModReqItem, E_RABs_ToBeModified_ModReqItem_choice,
NULL);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeReleased_ModReqItem_SCG_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeReleased_ModReqItem_SCG_Bearer, E_RABs_ToBeReleased_ModReqItem_SCG_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeReleased_ModReqItem_Split_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeReleased_ModReqItem_Split_Bearer, E_RABs_ToBeReleased_ModReqItem_Split_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeReleased_ModReqItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeReleased_ModReqItem, E_RABs_ToBeReleased_ModReqItem_choice,
NULL);
return offset;
}
static int
dissect_x2ap_SeNBModificationRequestAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 541 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SeNBModificationRequestAcknowledge");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SeNBModificationRequestAcknowledge, SeNBModificationRequestAcknowledge_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToBeAdded_ModAckList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToBeAdded_ModAckList, E_RABs_Admitted_ToBeAdded_ModAckList_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToBeAdded_ModAckItem_SCG_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToBeAdded_ModAckItem_SCG_Bearer, E_RABs_Admitted_ToBeAdded_ModAckItem_SCG_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToBeAdded_ModAckItem_Split_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToBeAdded_ModAckItem_Split_Bearer, E_RABs_Admitted_ToBeAdded_ModAckItem_Split_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToBeAdded_ModAckItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToBeAdded_ModAckItem, E_RABs_Admitted_ToBeAdded_ModAckItem_choice,
NULL);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToBeModified_ModAckList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToBeModified_ModAckList, E_RABs_Admitted_ToBeModified_ModAckList_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToBeModified_ModAckItem_SCG_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToBeModified_ModAckItem_SCG_Bearer, E_RABs_Admitted_ToBeModified_ModAckItem_SCG_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToBeModified_ModAckItem_Split_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToBeModified_ModAckItem_Split_Bearer, E_RABs_Admitted_ToBeModified_ModAckItem_Split_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToBeModified_ModAckItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToBeModified_ModAckItem, E_RABs_Admitted_ToBeModified_ModAckItem_choice,
NULL);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToBeReleased_ModAckList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToBeReleased_ModAckList, E_RABs_Admitted_ToBeReleased_ModAckList_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToBeReleased_ModAckItem_SCG_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToBeReleased_ModAckItem_SCG_Bearer, E_RABs_Admitted_ToBeReleased_ModAckItem_SCG_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToBeReleased_ModAckItem_Split_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToBeReleased_ModAckItem_Split_Bearer, E_RABs_Admitted_ToBeReleased_ModAckItem_Split_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_Admitted_ToReleased_ModAckItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_Admitted_ToReleased_ModAckItem, E_RABs_Admitted_ToReleased_ModAckItem_choice,
NULL);
return offset;
}
static int
dissect_x2ap_SeNBModificationRequestReject(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 543 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SeNBModificationRequestReject");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SeNBModificationRequestReject, SeNBModificationRequestReject_sequence);
return offset;
}
static int
dissect_x2ap_SeNBModificationRequired(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 545 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SeNBModificationRequired");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SeNBModificationRequired, SeNBModificationRequired_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeReleased_ModReqd(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeReleased_ModReqd, E_RABs_ToBeReleased_ModReqd_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeReleased_ModReqdItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeReleased_ModReqdItem, E_RABs_ToBeReleased_ModReqdItem_sequence);
return offset;
}
static int
dissect_x2ap_SeNBModificationConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 547 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SeNBModificationConfirm");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SeNBModificationConfirm, SeNBModificationConfirm_sequence);
return offset;
}
static int
dissect_x2ap_SeNBModificationRefuse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 549 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SeNBModificationRefuse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SeNBModificationRefuse, SeNBModificationRefuse_sequence);
return offset;
}
static int
dissect_x2ap_SeNBReleaseRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 551 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SeNBReleaseRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SeNBReleaseRequest, SeNBReleaseRequest_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeReleased_List_RelReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeReleased_List_RelReq, E_RABs_ToBeReleased_List_RelReq_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeReleased_RelReqItem_SCG_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeReleased_RelReqItem_SCG_Bearer, E_RABs_ToBeReleased_RelReqItem_SCG_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeReleased_RelReqItem_Split_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeReleased_RelReqItem_Split_Bearer, E_RABs_ToBeReleased_RelReqItem_Split_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeReleased_RelReqItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeReleased_RelReqItem, E_RABs_ToBeReleased_RelReqItem_choice,
NULL);
return offset;
}
static int
dissect_x2ap_SeNBReleaseRequired(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 553 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SeNBReleaseRequired");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SeNBReleaseRequired, SeNBReleaseRequired_sequence);
return offset;
}
static int
dissect_x2ap_SeNBReleaseConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 555 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SeNBReleaseConfirm");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SeNBReleaseConfirm, SeNBReleaseConfirm_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeReleased_List_RelConf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeReleased_List_RelConf, E_RABs_ToBeReleased_List_RelConf_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeReleased_RelConfItem_SCG_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeReleased_RelConfItem_SCG_Bearer, E_RABs_ToBeReleased_RelConfItem_SCG_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeReleased_RelConfItem_Split_Bearer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeReleased_RelConfItem_Split_Bearer, E_RABs_ToBeReleased_RelConfItem_Split_Bearer_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeReleased_RelConfItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeReleased_RelConfItem, E_RABs_ToBeReleased_RelConfItem_choice,
NULL);
return offset;
}
static int
dissect_x2ap_SeNBCounterCheckRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 557 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SeNBCounterCheckRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SeNBCounterCheckRequest, SeNBCounterCheckRequest_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_SubjectToCounterCheck_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_SubjectToCounterCheck_List, E_RABs_SubjectToCounterCheck_List_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_INTEGER_0_4294967295(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_x2ap_E_RABs_SubjectToCounterCheckItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_SubjectToCounterCheckItem, E_RABs_SubjectToCounterCheckItem_sequence);
return offset;
}
static int
dissect_x2ap_X2RemovalRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 525 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "X2RemovalRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_X2RemovalRequest, X2RemovalRequest_sequence);
return offset;
}
static int
dissect_x2ap_X2RemovalResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 527 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "X2RemovalResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_X2RemovalResponse, X2RemovalResponse_sequence);
return offset;
}
static int
dissect_x2ap_X2RemovalFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 529 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "X2RemovalFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_X2RemovalFailure, X2RemovalFailure_sequence);
return offset;
}
static int
dissect_x2ap_RetrieveUEContextRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 559 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "RetrieveUEContextRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_RetrieveUEContextRequest, RetrieveUEContextRequest_sequence);
return offset;
}
static int
dissect_x2ap_RetrieveUEContextResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 561 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "RetrieveUEContextResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_RetrieveUEContextResponse, RetrieveUEContextResponse_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeSetup_ListRetrieve(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeSetup_ListRetrieve, E_RABs_ToBeSetup_ListRetrieve_sequence_of,
1, maxnoofBearers, FALSE);
return offset;
}
static int
dissect_x2ap_UE_ContextInformationRetrieve(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UE_ContextInformationRetrieve, UE_ContextInformationRetrieve_sequence);
return offset;
}
static int
dissect_x2ap_E_RABs_ToBeSetupRetrieve_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_E_RABs_ToBeSetupRetrieve_Item, E_RABs_ToBeSetupRetrieve_Item_sequence);
return offset;
}
static int
dissect_x2ap_RetrieveUEContextFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 563 "./asn1/x2ap/x2ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "RetrieveUEContextFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_RetrieveUEContextFailure, RetrieveUEContextFailure_sequence);
return offset;
}
static int
dissect_x2ap_InitiatingMessage_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_InitiatingMessageValue);
return offset;
}
static int
dissect_x2ap_InitiatingMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_InitiatingMessage, InitiatingMessage_sequence);
return offset;
}
static int
dissect_x2ap_SuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_SuccessfulOutcomeValue);
return offset;
}
static int
dissect_x2ap_SuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_SuccessfulOutcome, SuccessfulOutcome_sequence);
return offset;
}
static int
dissect_x2ap_UnsuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_UnsuccessfulOutcomeValue);
return offset;
}
static int
dissect_x2ap_UnsuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_x2ap_UnsuccessfulOutcome, UnsuccessfulOutcome_sequence);
return offset;
}
static int
dissect_x2ap_X2AP_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_x2ap_X2AP_PDU, X2AP_PDU_choice,
NULL);
return offset;
}
static int dissect_ABSInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ABSInformation(tvb, offset, &asn1_ctx, tree, hf_x2ap_ABSInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ABS_Status_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ABS_Status(tvb, offset, &asn1_ctx, tree, hf_x2ap_ABS_Status_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_AdditionalSpecialSubframe_Info_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_AdditionalSpecialSubframe_Info(tvb, offset, &asn1_ctx, tree, hf_x2ap_AdditionalSpecialSubframe_Info_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_BearerType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_BearerType(tvb, offset, &asn1_ctx, tree, hf_x2ap_BearerType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_Cause(tvb, offset, &asn1_ctx, tree, hf_x2ap_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellReportingIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellReportingIndicator(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellReportingIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CoMPInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CoMPInformation(tvb, offset, &asn1_ctx, tree, hf_x2ap_CoMPInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CompositeAvailableCapacityGroup_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CompositeAvailableCapacityGroup(tvb, offset, &asn1_ctx, tree, hf_x2ap_CompositeAvailableCapacityGroup_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Correlation_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_Correlation_ID(tvb, offset, &asn1_ctx, tree, hf_x2ap_Correlation_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_COUNTValueExtended_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_COUNTValueExtended(tvb, offset, &asn1_ctx, tree, hf_x2ap_COUNTValueExtended_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_COUNTvaluePDCP_SNlength18_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_COUNTvaluePDCP_SNlength18(tvb, offset, &asn1_ctx, tree, hf_x2ap_COUNTvaluePDCP_SNlength18_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CoverageModificationList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CoverageModificationList(tvb, offset, &asn1_ctx, tree, hf_x2ap_CoverageModificationList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CriticalityDiagnostics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CriticalityDiagnostics(tvb, offset, &asn1_ctx, tree, hf_x2ap_CriticalityDiagnostics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CRNTI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CRNTI(tvb, offset, &asn1_ctx, tree, hf_x2ap_CRNTI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSGMembershipStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CSGMembershipStatus(tvb, offset, &asn1_ctx, tree, hf_x2ap_CSGMembershipStatus_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSG_Id_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CSG_Id(tvb, offset, &asn1_ctx, tree, hf_x2ap_CSG_Id_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSIReportList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CSIReportList(tvb, offset, &asn1_ctx, tree, hf_x2ap_CSIReportList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DeactivationIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_DeactivationIndication(tvb, offset, &asn1_ctx, tree, hf_x2ap_DeactivationIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DynamicDLTransmissionInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_DynamicDLTransmissionInformation(tvb, offset, &asn1_ctx, tree, hf_x2ap_DynamicDLTransmissionInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_EARFCNExtension_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_EARFCNExtension(tvb, offset, &asn1_ctx, tree, hf_x2ap_EARFCNExtension_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ECGI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ECGI(tvb, offset, &asn1_ctx, tree, hf_x2ap_ECGI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_EnhancedRNTP_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_EnhancedRNTP(tvb, offset, &asn1_ctx, tree, hf_x2ap_EnhancedRNTP_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RAB_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RAB_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RAB_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RAB_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RAB_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RAB_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_EUTRANCellIdentifier_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_EUTRANCellIdentifier(tvb, offset, &asn1_ctx, tree, hf_x2ap_EUTRANCellIdentifier_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ExpectedUEBehaviour_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ExpectedUEBehaviour(tvb, offset, &asn1_ctx, tree, hf_x2ap_ExpectedUEBehaviour_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ExtendedULInterferenceOverloadInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ExtendedULInterferenceOverloadInfo(tvb, offset, &asn1_ctx, tree, hf_x2ap_ExtendedULInterferenceOverloadInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_FreqBandIndicatorPriority_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_FreqBandIndicatorPriority(tvb, offset, &asn1_ctx, tree, hf_x2ap_FreqBandIndicatorPriority_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GlobalENB_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_GlobalENB_ID(tvb, offset, &asn1_ctx, tree, hf_x2ap_GlobalENB_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GUGroupIDList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_GUGroupIDList(tvb, offset, &asn1_ctx, tree, hf_x2ap_GUGroupIDList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GUMMEI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_GUMMEI(tvb, offset, &asn1_ctx, tree, hf_x2ap_GUMMEI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverReportType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_HandoverReportType(tvb, offset, &asn1_ctx, tree, hf_x2ap_HandoverReportType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InvokeIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_InvokeIndication(tvb, offset, &asn1_ctx, tree, hf_x2ap_InvokeIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LHN_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_LHN_ID(tvb, offset, &asn1_ctx, tree, hf_x2ap_LHN_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M3Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_M3Configuration(tvb, offset, &asn1_ctx, tree, hf_x2ap_M3Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M4Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_M4Configuration(tvb, offset, &asn1_ctx, tree, hf_x2ap_M4Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M5Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_M5Configuration(tvb, offset, &asn1_ctx, tree, hf_x2ap_M5Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M6Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_M6Configuration(tvb, offset, &asn1_ctx, tree, hf_x2ap_M6Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M7Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_M7Configuration(tvb, offset, &asn1_ctx, tree, hf_x2ap_M7Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ManagementBasedMDTallowed_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ManagementBasedMDTallowed(tvb, offset, &asn1_ctx, tree, hf_x2ap_ManagementBasedMDTallowed_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Masked_IMEISV_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_Masked_IMEISV(tvb, offset, &asn1_ctx, tree, hf_x2ap_Masked_IMEISV_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MDT_Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MDT_Configuration(tvb, offset, &asn1_ctx, tree, hf_x2ap_MDT_Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MDTPLMNList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MDTPLMNList(tvb, offset, &asn1_ctx, tree, hf_x2ap_MDTPLMNList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MDT_Location_Info_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MDT_Location_Info(tvb, offset, &asn1_ctx, tree, hf_x2ap_MDT_Location_Info_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Measurement_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_Measurement_ID(tvb, offset, &asn1_ctx, tree, hf_x2ap_Measurement_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MeNBtoSeNBContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MeNBtoSeNBContainer(tvb, offset, &asn1_ctx, tree, hf_x2ap_MeNBtoSeNBContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBMS_Service_Area_Identity_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MBMS_Service_Area_Identity_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_MBMS_Service_Area_Identity_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MBSFN_Subframe_Infolist_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MBSFN_Subframe_Infolist(tvb, offset, &asn1_ctx, tree, hf_x2ap_MBSFN_Subframe_Infolist_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MobilityParametersModificationRange_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MobilityParametersModificationRange(tvb, offset, &asn1_ctx, tree, hf_x2ap_MobilityParametersModificationRange_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MobilityParametersInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MobilityParametersInformation(tvb, offset, &asn1_ctx, tree, hf_x2ap_MobilityParametersInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MultibandInfoList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MultibandInfoList(tvb, offset, &asn1_ctx, tree, hf_x2ap_MultibandInfoList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Number_of_Antennaports_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_Number_of_Antennaports(tvb, offset, &asn1_ctx, tree, hf_x2ap_Number_of_Antennaports_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_OffsetOfNbiotChannelNumberToEARFCN_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_OffsetOfNbiotChannelNumberToEARFCN(tvb, offset, &asn1_ctx, tree, hf_x2ap_OffsetOfNbiotChannelNumberToEARFCN_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PCI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_PCI(tvb, offset, &asn1_ctx, tree, hf_x2ap_PCI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PLMN_Identity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_PLMN_Identity(tvb, offset, &asn1_ctx, tree, hf_x2ap_PLMN_Identity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PRACH_Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_PRACH_Configuration(tvb, offset, &asn1_ctx, tree, hf_x2ap_PRACH_Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ProSeAuthorized_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ProSeAuthorized(tvb, offset, &asn1_ctx, tree, hf_x2ap_ProSeAuthorized_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ProSeUEtoNetworkRelaying_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ProSeUEtoNetworkRelaying(tvb, offset, &asn1_ctx, tree, hf_x2ap_ProSeUEtoNetworkRelaying_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ReceiveStatusOfULPDCPSDUsExtended_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ReceiveStatusOfULPDCPSDUsExtended(tvb, offset, &asn1_ctx, tree, hf_x2ap_ReceiveStatusOfULPDCPSDUsExtended_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18(tvb, offset, &asn1_ctx, tree, hf_x2ap_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Registration_Request_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_Registration_Request(tvb, offset, &asn1_ctx, tree, hf_x2ap_Registration_Request_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ReportCharacteristics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ReportCharacteristics(tvb, offset, &asn1_ctx, tree, hf_x2ap_ReportCharacteristics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ReportingPeriodicityCSIR_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ReportingPeriodicityCSIR(tvb, offset, &asn1_ctx, tree, hf_x2ap_ReportingPeriodicityCSIR_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ReportingPeriodicityRSRPMR_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ReportingPeriodicityRSRPMR(tvb, offset, &asn1_ctx, tree, hf_x2ap_ReportingPeriodicityRSRPMR_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResumeID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ResumeID(tvb, offset, &asn1_ctx, tree, hf_x2ap_ResumeID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RRCConnReestabIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_RRCConnReestabIndicator(tvb, offset, &asn1_ctx, tree, hf_x2ap_RRCConnReestabIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RRCConnSetupIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_RRCConnSetupIndicator(tvb, offset, &asn1_ctx, tree, hf_x2ap_RRCConnSetupIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RSRPMRList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_RSRPMRList(tvb, offset, &asn1_ctx, tree, hf_x2ap_RSRPMRList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SCGChangeIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SCGChangeIndication(tvb, offset, &asn1_ctx, tree, hf_x2ap_SCGChangeIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBSecurityKey_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBSecurityKey(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBSecurityKey_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBtoMeNBContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBtoMeNBContainer(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBtoMeNBContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ServedCells_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ServedCells(tvb, offset, &asn1_ctx, tree, hf_x2ap_ServedCells_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SIPTOBearerDeactivationIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SIPTOBearerDeactivationIndication(tvb, offset, &asn1_ctx, tree, hf_x2ap_SIPTOBearerDeactivationIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ShortMAC_I_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ShortMAC_I(tvb, offset, &asn1_ctx, tree, hf_x2ap_ShortMAC_I_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRVCCOperationPossible_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SRVCCOperationPossible(tvb, offset, &asn1_ctx, tree, hf_x2ap_SRVCCOperationPossible_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SubframeAssignment_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SubframeAssignment(tvb, offset, &asn1_ctx, tree, hf_x2ap_SubframeAssignment_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TAC_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_TAC(tvb, offset, &asn1_ctx, tree, hf_x2ap_TAC_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TargetCellInUTRAN_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_TargetCellInUTRAN(tvb, offset, &asn1_ctx, tree, hf_x2ap_TargetCellInUTRAN_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TargeteNBtoSource_eNBTransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_TargeteNBtoSource_eNBTransparentContainer(tvb, offset, &asn1_ctx, tree, hf_x2ap_TargeteNBtoSource_eNBTransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TimeToWait_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_TimeToWait(tvb, offset, &asn1_ctx, tree, hf_x2ap_TimeToWait_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Time_UE_StayedInCell_EnhancedGranularity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_Time_UE_StayedInCell_EnhancedGranularity(tvb, offset, &asn1_ctx, tree, hf_x2ap_Time_UE_StayedInCell_EnhancedGranularity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TraceActivation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_TraceActivation(tvb, offset, &asn1_ctx, tree, hf_x2ap_TraceActivation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TransportLayerAddress_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_TransportLayerAddress(tvb, offset, &asn1_ctx, tree, hf_x2ap_TransportLayerAddress_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TunnelInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_TunnelInformation(tvb, offset, &asn1_ctx, tree, hf_x2ap_TunnelInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEAggregateMaximumBitRate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UEAggregateMaximumBitRate(tvb, offset, &asn1_ctx, tree, hf_x2ap_UEAggregateMaximumBitRate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_ContextKeptIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UE_ContextKeptIndicator(tvb, offset, &asn1_ctx, tree, hf_x2ap_UE_ContextKeptIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UEID(tvb, offset, &asn1_ctx, tree, hf_x2ap_UEID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_HistoryInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UE_HistoryInformation(tvb, offset, &asn1_ctx, tree, hf_x2ap_UE_HistoryInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_HistoryInformationFromTheUE_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UE_HistoryInformationFromTheUE(tvb, offset, &asn1_ctx, tree, hf_x2ap_UE_HistoryInformationFromTheUE_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_X2AP_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UE_X2AP_ID(tvb, offset, &asn1_ctx, tree, hf_x2ap_UE_X2AP_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_X2AP_ID_Extension_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UE_X2AP_ID_Extension(tvb, offset, &asn1_ctx, tree, hf_x2ap_UE_X2AP_ID_Extension_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_RLF_Report_Container_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UE_RLF_Report_Container(tvb, offset, &asn1_ctx, tree, hf_x2ap_UE_RLF_Report_Container_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_RLF_Report_Container_for_extended_bands_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UE_RLF_Report_Container_for_extended_bands(tvb, offset, &asn1_ctx, tree, hf_x2ap_UE_RLF_Report_Container_for_extended_bands_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UESecurityCapabilities_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UESecurityCapabilities(tvb, offset, &asn1_ctx, tree, hf_x2ap_UESecurityCapabilities_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2BenefitValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_X2BenefitValue(tvb, offset, &asn1_ctx, tree, hf_x2ap_X2BenefitValue_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_HandoverRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_HandoverRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_ContextInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UE_ContextInformation(tvb, offset, &asn1_ctx, tree, hf_x2ap_UE_ContextInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_ToBeSetup_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_ToBeSetup_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_ToBeSetup_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MobilityInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MobilityInformation(tvb, offset, &asn1_ctx, tree, hf_x2ap_MobilityInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_ContextReferenceAtSeNB_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UE_ContextReferenceAtSeNB(tvb, offset, &asn1_ctx, tree, hf_x2ap_UE_ContextReferenceAtSeNB_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverRequestAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_HandoverRequestAcknowledge(tvb, offset, &asn1_ctx, tree, hf_x2ap_HandoverRequestAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_Admitted_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_Admitted_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_Admitted_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_Admitted_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_Admitted_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_Admitted_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverPreparationFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_HandoverPreparationFailure(tvb, offset, &asn1_ctx, tree, hf_x2ap_HandoverPreparationFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverReport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_HandoverReport(tvb, offset, &asn1_ctx, tree, hf_x2ap_HandoverReport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SNStatusTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SNStatusTransfer(tvb, offset, &asn1_ctx, tree, hf_x2ap_SNStatusTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_SubjectToStatusTransfer_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_SubjectToStatusTransfer_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_SubjectToStatusTransfer_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_SubjectToStatusTransfer_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_SubjectToStatusTransfer_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_SubjectToStatusTransfer_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextRelease_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UEContextRelease(tvb, offset, &asn1_ctx, tree, hf_x2ap_UEContextRelease_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverCancel_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_HandoverCancel(tvb, offset, &asn1_ctx, tree, hf_x2ap_HandoverCancel_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ErrorIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ErrorIndication(tvb, offset, &asn1_ctx, tree, hf_x2ap_ErrorIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ResetRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_ResetRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ResetResponse(tvb, offset, &asn1_ctx, tree, hf_x2ap_ResetResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2SetupRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_X2SetupRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_X2SetupRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2SetupResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_X2SetupResponse(tvb, offset, &asn1_ctx, tree, hf_x2ap_X2SetupResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2SetupFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_X2SetupFailure(tvb, offset, &asn1_ctx, tree, hf_x2ap_X2SetupFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LoadInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_LoadInformation(tvb, offset, &asn1_ctx, tree, hf_x2ap_LoadInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellInformation_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellInformation_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellInformation_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellInformation_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellInformation_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellInformation_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationUpdate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ENBConfigurationUpdate(tvb, offset, &asn1_ctx, tree, hf_x2ap_ENBConfigurationUpdate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ServedCellsToModify_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ServedCellsToModify(tvb, offset, &asn1_ctx, tree, hf_x2ap_ServedCellsToModify_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Old_ECGIs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_Old_ECGIs(tvb, offset, &asn1_ctx, tree, hf_x2ap_Old_ECGIs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationUpdateAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ENBConfigurationUpdateAcknowledge(tvb, offset, &asn1_ctx, tree, hf_x2ap_ENBConfigurationUpdateAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationUpdateFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ENBConfigurationUpdateFailure(tvb, offset, &asn1_ctx, tree, hf_x2ap_ENBConfigurationUpdateFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResourceStatusRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ResourceStatusRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_ResourceStatusRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellToReport_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellToReport_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellToReport_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellToReport_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellToReport_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellToReport_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ReportingPeriodicity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ReportingPeriodicity(tvb, offset, &asn1_ctx, tree, hf_x2ap_ReportingPeriodicity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PartialSuccessIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_PartialSuccessIndicator(tvb, offset, &asn1_ctx, tree, hf_x2ap_PartialSuccessIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResourceStatusResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ResourceStatusResponse(tvb, offset, &asn1_ctx, tree, hf_x2ap_ResourceStatusResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MeasurementInitiationResult_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MeasurementInitiationResult_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_MeasurementInitiationResult_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MeasurementInitiationResult_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MeasurementInitiationResult_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_MeasurementInitiationResult_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MeasurementFailureCause_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MeasurementFailureCause_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_MeasurementFailureCause_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResourceStatusFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ResourceStatusFailure(tvb, offset, &asn1_ctx, tree, hf_x2ap_ResourceStatusFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CompleteFailureCauseInformation_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CompleteFailureCauseInformation_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_CompleteFailureCauseInformation_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CompleteFailureCauseInformation_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CompleteFailureCauseInformation_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_CompleteFailureCauseInformation_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResourceStatusUpdate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ResourceStatusUpdate(tvb, offset, &asn1_ctx, tree, hf_x2ap_ResourceStatusUpdate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellMeasurementResult_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellMeasurementResult_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellMeasurementResult_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellMeasurementResult_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellMeasurementResult_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellMeasurementResult_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PrivateMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_PrivateMessage(tvb, offset, &asn1_ctx, tree, hf_x2ap_PrivateMessage_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MobilityChangeRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MobilityChangeRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_MobilityChangeRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MobilityChangeAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MobilityChangeAcknowledge(tvb, offset, &asn1_ctx, tree, hf_x2ap_MobilityChangeAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MobilityChangeFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_MobilityChangeFailure(tvb, offset, &asn1_ctx, tree, hf_x2ap_MobilityChangeFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RLFIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_RLFIndication(tvb, offset, &asn1_ctx, tree, hf_x2ap_RLFIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellActivationRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellActivationRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellActivationRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ServedCellsToActivate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ServedCellsToActivate(tvb, offset, &asn1_ctx, tree, hf_x2ap_ServedCellsToActivate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellActivationResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellActivationResponse(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellActivationResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ActivatedCellList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ActivatedCellList(tvb, offset, &asn1_ctx, tree, hf_x2ap_ActivatedCellList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellActivationFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_CellActivationFailure(tvb, offset, &asn1_ctx, tree, hf_x2ap_CellActivationFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2Release_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_X2Release(tvb, offset, &asn1_ctx, tree, hf_x2ap_X2Release_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2APMessageTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_X2APMessageTransfer(tvb, offset, &asn1_ctx, tree, hf_x2ap_X2APMessageTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RNL_Header_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_RNL_Header(tvb, offset, &asn1_ctx, tree, hf_x2ap_RNL_Header_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2AP_Message_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_X2AP_Message(tvb, offset, &asn1_ctx, tree, hf_x2ap_X2AP_Message_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBAdditionRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBAdditionRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBAdditionRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_ToBeAdded_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_ToBeAdded_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_ToBeAdded_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_ToBeAdded_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_ToBeAdded_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_ToBeAdded_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBAdditionRequestAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBAdditionRequestAcknowledge(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBAdditionRequestAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_Admitted_ToBeAdded_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_Admitted_ToBeAdded_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_Admitted_ToBeAdded_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_Admitted_ToBeAdded_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_Admitted_ToBeAdded_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_Admitted_ToBeAdded_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBAdditionRequestReject_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBAdditionRequestReject(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBAdditionRequestReject_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBReconfigurationComplete_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBReconfigurationComplete(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBReconfigurationComplete_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResponseInformationSeNBReconfComp_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_ResponseInformationSeNBReconfComp(tvb, offset, &asn1_ctx, tree, hf_x2ap_ResponseInformationSeNBReconfComp_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBModificationRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBModificationRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBModificationRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_ContextInformationSeNBModReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UE_ContextInformationSeNBModReq(tvb, offset, &asn1_ctx, tree, hf_x2ap_UE_ContextInformationSeNBModReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_ToBeAdded_ModReqItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_ToBeAdded_ModReqItem(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_ToBeAdded_ModReqItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_ToBeModified_ModReqItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_ToBeModified_ModReqItem(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_ToBeModified_ModReqItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_ToBeReleased_ModReqItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_ToBeReleased_ModReqItem(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_ToBeReleased_ModReqItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBModificationRequestAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBModificationRequestAcknowledge(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBModificationRequestAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_Admitted_ToBeAdded_ModAckList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_Admitted_ToBeAdded_ModAckList(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_Admitted_ToBeAdded_ModAckList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_Admitted_ToBeAdded_ModAckItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_Admitted_ToBeAdded_ModAckItem(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_Admitted_ToBeAdded_ModAckItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_Admitted_ToBeModified_ModAckList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_Admitted_ToBeModified_ModAckList(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_Admitted_ToBeModified_ModAckList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_Admitted_ToBeModified_ModAckItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_Admitted_ToBeModified_ModAckItem(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_Admitted_ToBeModified_ModAckItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_Admitted_ToBeReleased_ModAckList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_Admitted_ToBeReleased_ModAckList(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_Admitted_ToBeReleased_ModAckList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_Admitted_ToReleased_ModAckItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_Admitted_ToReleased_ModAckItem(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_Admitted_ToReleased_ModAckItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBModificationRequestReject_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBModificationRequestReject(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBModificationRequestReject_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBModificationRequired_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBModificationRequired(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBModificationRequired_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_ToBeReleased_ModReqd_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_ToBeReleased_ModReqd(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_ToBeReleased_ModReqd_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_ToBeReleased_ModReqdItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_ToBeReleased_ModReqdItem(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_ToBeReleased_ModReqdItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBModificationConfirm_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBModificationConfirm(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBModificationConfirm_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBModificationRefuse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBModificationRefuse(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBModificationRefuse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBReleaseRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBReleaseRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBReleaseRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_ToBeReleased_List_RelReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_ToBeReleased_List_RelReq(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_ToBeReleased_List_RelReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_ToBeReleased_RelReqItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_ToBeReleased_RelReqItem(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_ToBeReleased_RelReqItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBReleaseRequired_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBReleaseRequired(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBReleaseRequired_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBReleaseConfirm_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBReleaseConfirm(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBReleaseConfirm_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_ToBeReleased_List_RelConf_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_ToBeReleased_List_RelConf(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_ToBeReleased_List_RelConf_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_ToBeReleased_RelConfItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_ToBeReleased_RelConfItem(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_ToBeReleased_RelConfItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SeNBCounterCheckRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_SeNBCounterCheckRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_SeNBCounterCheckRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_SubjectToCounterCheck_List_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_SubjectToCounterCheck_List(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_SubjectToCounterCheck_List_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_SubjectToCounterCheckItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_SubjectToCounterCheckItem(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_SubjectToCounterCheckItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2RemovalRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_X2RemovalRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_X2RemovalRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2RemovalResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_X2RemovalResponse(tvb, offset, &asn1_ctx, tree, hf_x2ap_X2RemovalResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2RemovalFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_X2RemovalFailure(tvb, offset, &asn1_ctx, tree, hf_x2ap_X2RemovalFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RetrieveUEContextRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_RetrieveUEContextRequest(tvb, offset, &asn1_ctx, tree, hf_x2ap_RetrieveUEContextRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RetrieveUEContextResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_RetrieveUEContextResponse(tvb, offset, &asn1_ctx, tree, hf_x2ap_RetrieveUEContextResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_ContextInformationRetrieve_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_UE_ContextInformationRetrieve(tvb, offset, &asn1_ctx, tree, hf_x2ap_UE_ContextInformationRetrieve_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABs_ToBeSetupRetrieve_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_E_RABs_ToBeSetupRetrieve_Item(tvb, offset, &asn1_ctx, tree, hf_x2ap_E_RABs_ToBeSetupRetrieve_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RetrieveUEContextFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_RetrieveUEContextFailure(tvb, offset, &asn1_ctx, tree, hf_x2ap_RetrieveUEContextFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2AP_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_x2ap_X2AP_PDU(tvb, offset, &asn1_ctx, tree, hf_x2ap_X2AP_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
struct x2ap_private_data *x2ap_data = x2ap_get_private_data(pinfo);
return (dissector_try_uint(x2ap_ies_dissector_table, x2ap_data->protocol_ie_id, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
struct x2ap_private_data *x2ap_data = x2ap_get_private_data(pinfo);
return (dissector_try_uint(x2ap_extension_dissector_table, x2ap_data->protocol_ie_id, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
struct x2ap_private_data *x2ap_data = x2ap_get_private_data(pinfo);
return (dissector_try_uint(x2ap_proc_imsg_dissector_table, x2ap_data->procedure_code, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
struct x2ap_private_data *x2ap_data = x2ap_get_private_data(pinfo);
return (dissector_try_uint(x2ap_proc_sout_dissector_table, x2ap_data->procedure_code, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
struct x2ap_private_data *x2ap_data = x2ap_get_private_data(pinfo);
return (dissector_try_uint(x2ap_proc_uout_dissector_table, x2ap_data->procedure_code, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_x2ap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *x2ap_item;
proto_tree *x2ap_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "X2AP");
col_clear_fence(pinfo->cinfo, COL_INFO);
col_clear(pinfo->cinfo, COL_INFO);
x2ap_item = proto_tree_add_item(tree, proto_x2ap, tvb, 0, -1, ENC_NA);
x2ap_tree = proto_item_add_subtree(x2ap_item, ett_x2ap);
return dissect_X2AP_PDU_PDU(tvb, pinfo, x2ap_tree, data);
}
void proto_register_x2ap(void) {
static hf_register_info hf[] = {
{ &hf_x2ap_transportLayerAddressIPv4,
{ "transportLayerAddress(IPv4)", "x2ap.transportLayerAddressIPv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_transportLayerAddressIPv6,
{ "transportLayerAddress(IPv6)", "x2ap.transportLayerAddressIPv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ReportCharacteristics_PRBPeriodic,
{ "PRBPeriodic", "x2ap.ReportCharacteristics.PRBPeriodic",
FT_BOOLEAN, 32, TFS(&tfs_requested_not_requested), 0x80000000,
NULL, HFILL }},
{ &hf_x2ap_ReportCharacteristics_TNLLoadIndPeriodic,
{ "TNLLoadIndPeriodic", "x2ap.ReportCharacteristics.TNLLoadIndPeriodic",
FT_BOOLEAN, 32, TFS(&tfs_requested_not_requested), 0x40000000,
NULL, HFILL }},
{ &hf_x2ap_ReportCharacteristics_HWLoadIndPeriodic,
{ "HWLoadIndPeriodic", "x2ap.ReportCharacteristics.HWLoadIndPeriodic",
FT_BOOLEAN, 32, TFS(&tfs_requested_not_requested), 0x20000000,
NULL, HFILL }},
{ &hf_x2ap_ReportCharacteristics_CompositeAvailableCapacityPeriodic,
{ "CompositeAvailableCapacityPeriodic", "x2ap.ReportCharacteristics.CompositeAvailableCapacityPeriodic",
FT_BOOLEAN, 32, TFS(&tfs_requested_not_requested), 0x10000000,
NULL, HFILL }},
{ &hf_x2ap_ReportCharacteristics_ABSStatusPeriodic,
{ "ABSStatusPeriodic", "x2ap.ReportCharacteristics.ABSStatusPeriodic",
FT_BOOLEAN, 32, TFS(&tfs_requested_not_requested), 0x08000000,
NULL, HFILL }},
{ &hf_x2ap_ReportCharacteristics_RSRPMeasurementReportPeriodic,
{ "RSRPMeasurementReportPeriodic", "x2ap.ReportCharacteristics.RSRPMeasurementReportPeriodic",
FT_BOOLEAN, 32, TFS(&tfs_requested_not_requested), 0x04000000,
NULL, HFILL }},
{ &hf_x2ap_ReportCharacteristics_CSIReportPeriodic,
{ "CSIReportPeriodic", "x2ap.ReportCharacteristics.CSIReportPeriodic",
FT_BOOLEAN, 32, TFS(&tfs_requested_not_requested), 0x02000000,
NULL, HFILL }},
{ &hf_x2ap_ReportCharacteristics_Reserved,
{ "Reserved", "x2ap.ReportCharacteristics.Reserved",
FT_UINT32, BASE_HEX, NULL, 0x01ffffff,
NULL, HFILL }},
{ &hf_x2ap_measurementFailedReportCharacteristics_PRBPeriodic,
{ "PRBPeriodic", "x2ap.measurementFailedReportCharacteristics.PRBPeriodic",
FT_BOOLEAN, 32, TFS(&x2ap_tfs_failed_succeeded), 0x80000000,
NULL, HFILL }},
{ &hf_x2ap_measurementFailedReportCharacteristics_TNLLoadIndPeriodic,
{ "TNLLoadIndPeriodic", "x2ap.measurementFailedReportCharacteristics.TNLLoadIndPeriodic",
FT_BOOLEAN, 32, TFS(&x2ap_tfs_failed_succeeded), 0x40000000,
NULL, HFILL }},
{ &hf_x2ap_measurementFailedReportCharacteristics_HWLoadIndPeriodic,
{ "HWLoadIndPeriodic", "x2ap.measurementFailedReportCharacteristics.HWLoadIndPeriodic",
FT_BOOLEAN, 32, TFS(&x2ap_tfs_failed_succeeded), 0x20000000,
NULL, HFILL }},
{ &hf_x2ap_measurementFailedReportCharacteristics_CompositeAvailableCapacityPeriodic,
{ "CompositeAvailableCapacityPeriodic", "x2ap.measurementFailedReportCharacteristics.CompositeAvailableCapacityPeriodic",
FT_BOOLEAN, 32, TFS(&x2ap_tfs_failed_succeeded), 0x10000000,
NULL, HFILL }},
{ &hf_x2ap_measurementFailedReportCharacteristics_ABSStatusPeriodic,
{ "ABSStatusPeriodic", "x2ap.measurementFailedReportCharacteristics.ABSStatusPeriodic",
FT_BOOLEAN, 32, TFS(&x2ap_tfs_failed_succeeded), 0x08000000,
NULL, HFILL }},
{ &hf_x2ap_measurementFailedReportCharacteristics_RSRPMeasurementReportPeriodic,
{ "RSRPMeasurementReportPeriodic", "x2ap.measurementFailedReportCharacteristics.RSRPMeasurementReportPeriodic",
FT_BOOLEAN, 32, TFS(&x2ap_tfs_failed_succeeded), 0x04000000,
NULL, HFILL }},
{ &hf_x2ap_measurementFailedReportCharacteristics_CSIReportPeriodic,
{ "CSIReportPeriodic", "x2ap.measurementFailedReportCharacteristics.CSIReportPeriodic",
FT_BOOLEAN, 32, TFS(&x2ap_tfs_failed_succeeded), 0x02000000,
NULL, HFILL }},
{ &hf_x2ap_measurementFailedReportCharacteristics_Reserved,
{ "Reserved", "x2ap.measurementFailedReportCharacteristics.Reserved",
FT_UINT32, BASE_HEX, NULL, 0x01ffffff,
NULL, HFILL }},
{ &hf_x2ap_eUTRANTraceID_TraceID,
{ "TraceID", "x2ap.eUTRANTraceID.TraceID",
FT_UINT24, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_eUTRANTraceID_TraceRecordingSessionReference,
{ "TraceRecordingSessionReference", "x2ap.eUTRANTraceID.TraceRecordingSessionReference",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_interfacesToTrace_S1_MME,
{ "S1-MME", "x2ap.interfacesToTrace.S1_MME",
FT_BOOLEAN, 8, TFS(&x2ap_tfs_interfacesToTrace), 0x80,
NULL, HFILL }},
{ &hf_x2ap_interfacesToTrace_X2,
{ "X2", "x2ap.interfacesToTrace.X2",
FT_BOOLEAN, 8, TFS(&x2ap_tfs_interfacesToTrace), 0x40,
NULL, HFILL }},
{ &hf_x2ap_interfacesToTrace_Uu,
{ "Uu", "x2ap.interfacesToTrace.Uu",
FT_BOOLEAN, 8, TFS(&x2ap_tfs_interfacesToTrace), 0x20,
NULL, HFILL }},
{ &hf_x2ap_interfacesToTrace_Reserved,
{ "Reserved", "x2ap.interfacesToTrace.Reserved",
FT_UINT8, BASE_HEX, NULL, 0x1f,
NULL, HFILL }},
{ &hf_x2ap_traceCollectionEntityIPAddress_IPv4,
{ "IPv4", "x2ap.traceCollectionEntityIPAddress.IPv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_traceCollectionEntityIPAddress_IPv6,
{ "IPv6", "x2ap.traceCollectionEntityIPAddress.IPv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_encryptionAlgorithms_EEA1,
{ "128-EEA1", "x2ap.encryptionAlgorithms.EEA1",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x8000,
NULL, HFILL }},
{ &hf_x2ap_encryptionAlgorithms_EEA2,
{ "128-EEA2", "x2ap.encryptionAlgorithms.EEA2",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x4000,
NULL, HFILL }},
{ &hf_x2ap_encryptionAlgorithms_EEA3,
{ "128-EEA3", "x2ap.encryptionAlgorithms.EEA3",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x2000,
NULL, HFILL }},
{ &hf_x2ap_encryptionAlgorithms_Reserved,
{ "Reserved", "x2ap.encryptionAlgorithms.Reserved",
FT_UINT16, BASE_HEX, NULL, 0x1fff,
NULL, HFILL }},
{ &hf_x2ap_integrityProtectionAlgorithms_EIA1,
{ "128-EIA1", "x2ap.integrityProtectionAlgorithms.EIA1",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x8000,
NULL, HFILL }},
{ &hf_x2ap_integrityProtectionAlgorithms_EIA2,
{ "128-EIA2", "x2ap.integrityProtectionAlgorithms.EIA2",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x4000,
NULL, HFILL }},
{ &hf_x2ap_integrityProtectionAlgorithms_EIA3,
{ "128-EIA3", "x2ap.integrityProtectionAlgorithms.EIA3",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x2000,
NULL, HFILL }},
{ &hf_x2ap_integrityProtectionAlgorithms_Reserved,
{ "Reserved", "x2ap.integrityProtectionAlgorithms.Reserved",
FT_UINT16, BASE_HEX, NULL, 0x1fff,
NULL, HFILL }},
{ &hf_x2ap_measurementsToActivate_M1,
{ "M1", "x2ap.measurementsToActivate.M1",
FT_BOOLEAN, 8, TFS(&x2ap_tfs_activate_do_not_activate), 0x80,
NULL, HFILL }},
{ &hf_x2ap_measurementsToActivate_M2,
{ "M2", "x2ap.measurementsToActivate.M2",
FT_BOOLEAN, 8, TFS(&x2ap_tfs_activate_do_not_activate), 0x40,
NULL, HFILL }},
{ &hf_x2ap_measurementsToActivate_M3,
{ "M3", "x2ap.measurementsToActivate.M3",
FT_BOOLEAN, 8, TFS(&x2ap_tfs_activate_do_not_activate), 0x20,
NULL, HFILL }},
{ &hf_x2ap_measurementsToActivate_M4,
{ "M4", "x2ap.measurementsToActivate.M4",
FT_BOOLEAN, 8, TFS(&x2ap_tfs_activate_do_not_activate), 0x10,
NULL, HFILL }},
{ &hf_x2ap_measurementsToActivate_M5,
{ "M5", "x2ap.measurementsToActivate.M5",
FT_BOOLEAN, 8, TFS(&x2ap_tfs_activate_do_not_activate), 0x08,
NULL, HFILL }},
{ &hf_x2ap_measurementsToActivate_LoggingM1FromEventTriggered,
{ "LoggingOfM1FromEventTriggeredMeasurementReports", "x2ap.measurementsToActivate.LoggingM1FromEventTriggered",
FT_BOOLEAN, 8, TFS(&x2ap_tfs_activate_do_not_activate), 0x04,
NULL, HFILL }},
{ &hf_x2ap_measurementsToActivate_M6,
{ "M6", "x2ap.measurementsToActivate.M6",
FT_BOOLEAN, 8, TFS(&x2ap_tfs_activate_do_not_activate), 0x02,
NULL, HFILL }},
{ &hf_x2ap_measurementsToActivate_M7,
{ "M7", "x2ap.measurementsToActivate.M7",
FT_BOOLEAN, 8, TFS(&x2ap_tfs_activate_do_not_activate), 0x01,
NULL, HFILL }},
{ &hf_x2ap_MDT_Location_Info_GNSS,
{ "GNSS", "x2ap.MDT_Location_Info.GNSS",
FT_BOOLEAN, 8, TFS(&x2ap_tfs_activate_do_not_activate), 0x80,
NULL, HFILL }},
{ &hf_x2ap_MDT_Location_Info_E_CID,
{ "E-CID", "x2ap.MDT_Location_Info.E_CID",
FT_BOOLEAN, 8, TFS(&x2ap_tfs_activate_do_not_activate), 0x40,
NULL, HFILL }},
{ &hf_x2ap_MDT_Location_Info_Reserved,
{ "Reserved", "x2ap.MDT_Location_Info.Reserved",
FT_UINT8, BASE_HEX, NULL, 0x3f,
NULL, HFILL }},
{ &hf_x2ap_MDT_transmissionModes_tm1,
{ "TM1", "x2ap.MDT_Location_Info.transmissionModes.tm1",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_x2ap_MDT_transmissionModes_tm2,
{ "TM2", "x2ap.MDT_Location_Info.transmissionModes.tm2",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL }},
{ &hf_x2ap_MDT_transmissionModes_tm3,
{ "TM3", "x2ap.MDT_Location_Info.transmissionModes.tm3",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20,
NULL, HFILL }},
{ &hf_x2ap_MDT_transmissionModes_tm4,
{ "TM4", "x2ap.MDT_Location_Info.transmissionModes.tm4",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
NULL, HFILL }},
{ &hf_x2ap_MDT_transmissionModes_tm6,
{ "TM6", "x2ap.MDT_Location_Info.transmissionModes.tm6",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x08,
NULL, HFILL }},
{ &hf_x2ap_MDT_transmissionModes_tm8,
{ "TM8", "x2ap.MDT_Location_Info.transmissionModes.tm8",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x04,
NULL, HFILL }},
{ &hf_x2ap_MDT_transmissionModes_tm9,
{ "TM9", "x2ap.MDT_Location_Info.transmissionModes.tm9",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }},
{ &hf_x2ap_MDT_transmissionModes_tm10,
{ "TM10", "x2ap.MDT_Location_Info.transmissionModes.tm10",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }},
#line 1 "./asn1/x2ap/packet-x2ap-hfarr.c"
{ &hf_x2ap_ABSInformation_PDU,
{ "ABSInformation", "x2ap.ABSInformation",
FT_UINT32, BASE_DEC, VALS(x2ap_ABSInformation_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_ABS_Status_PDU,
{ "ABS-Status", "x2ap.ABS_Status_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_AdditionalSpecialSubframe_Info_PDU,
{ "AdditionalSpecialSubframe-Info", "x2ap.AdditionalSpecialSubframe_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_BearerType_PDU,
{ "BearerType", "x2ap.BearerType",
FT_UINT32, BASE_DEC, VALS(x2ap_BearerType_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_Cause_PDU,
{ "Cause", "x2ap.Cause",
FT_UINT32, BASE_DEC, VALS(x2ap_Cause_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_CellReportingIndicator_PDU,
{ "CellReportingIndicator", "x2ap.CellReportingIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_CellReportingIndicator_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_CoMPInformation_PDU,
{ "CoMPInformation", "x2ap.CoMPInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CompositeAvailableCapacityGroup_PDU,
{ "CompositeAvailableCapacityGroup", "x2ap.CompositeAvailableCapacityGroup_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_Correlation_ID_PDU,
{ "Correlation-ID", "x2ap.Correlation_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_COUNTValueExtended_PDU,
{ "COUNTValueExtended", "x2ap.COUNTValueExtended_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_COUNTvaluePDCP_SNlength18_PDU,
{ "COUNTvaluePDCP-SNlength18", "x2ap.COUNTvaluePDCP_SNlength18_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CoverageModificationList_PDU,
{ "CoverageModificationList", "x2ap.CoverageModificationList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CriticalityDiagnostics_PDU,
{ "CriticalityDiagnostics", "x2ap.CriticalityDiagnostics_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CRNTI_PDU,
{ "CRNTI", "x2ap.CRNTI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CSGMembershipStatus_PDU,
{ "CSGMembershipStatus", "x2ap.CSGMembershipStatus",
FT_UINT32, BASE_DEC, VALS(x2ap_CSGMembershipStatus_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_CSG_Id_PDU,
{ "CSG-Id", "x2ap.CSG_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CSIReportList_PDU,
{ "CSIReportList", "x2ap.CSIReportList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_DeactivationIndication_PDU,
{ "DeactivationIndication", "x2ap.DeactivationIndication",
FT_UINT32, BASE_DEC, VALS(x2ap_DeactivationIndication_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_DynamicDLTransmissionInformation_PDU,
{ "DynamicDLTransmissionInformation", "x2ap.DynamicDLTransmissionInformation",
FT_UINT32, BASE_DEC, VALS(x2ap_DynamicDLTransmissionInformation_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_EARFCNExtension_PDU,
{ "EARFCNExtension", "x2ap.EARFCNExtension",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ECGI_PDU,
{ "ECGI", "x2ap.ECGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_EnhancedRNTP_PDU,
{ "EnhancedRNTP", "x2ap.EnhancedRNTP_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RAB_List_PDU,
{ "E-RAB-List", "x2ap.E_RAB_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RAB_Item_PDU,
{ "E-RAB-Item", "x2ap.E_RAB_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_EUTRANCellIdentifier_PDU,
{ "EUTRANCellIdentifier", "x2ap.EUTRANCellIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ExpectedUEBehaviour_PDU,
{ "ExpectedUEBehaviour", "x2ap.ExpectedUEBehaviour_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ExtendedULInterferenceOverloadInfo_PDU,
{ "ExtendedULInterferenceOverloadInfo", "x2ap.ExtendedULInterferenceOverloadInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_FreqBandIndicatorPriority_PDU,
{ "FreqBandIndicatorPriority", "x2ap.FreqBandIndicatorPriority",
FT_UINT32, BASE_DEC, VALS(x2ap_FreqBandIndicatorPriority_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_GlobalENB_ID_PDU,
{ "GlobalENB-ID", "x2ap.GlobalENB_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_GUGroupIDList_PDU,
{ "GUGroupIDList", "x2ap.GUGroupIDList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_GUMMEI_PDU,
{ "GUMMEI", "x2ap.GUMMEI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_HandoverReportType_PDU,
{ "HandoverReportType", "x2ap.HandoverReportType",
FT_UINT32, BASE_DEC, VALS(x2ap_HandoverReportType_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_InvokeIndication_PDU,
{ "InvokeIndication", "x2ap.InvokeIndication",
FT_UINT32, BASE_DEC, VALS(x2ap_InvokeIndication_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_LHN_ID_PDU,
{ "LHN-ID", "x2ap.LHN_ID",
FT_STRING, STR_UNICODE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_M3Configuration_PDU,
{ "M3Configuration", "x2ap.M3Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_M4Configuration_PDU,
{ "M4Configuration", "x2ap.M4Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_M5Configuration_PDU,
{ "M5Configuration", "x2ap.M5Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_M6Configuration_PDU,
{ "M6Configuration", "x2ap.M6Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_M7Configuration_PDU,
{ "M7Configuration", "x2ap.M7Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ManagementBasedMDTallowed_PDU,
{ "ManagementBasedMDTallowed", "x2ap.ManagementBasedMDTallowed",
FT_UINT32, BASE_DEC, VALS(x2ap_ManagementBasedMDTallowed_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_Masked_IMEISV_PDU,
{ "Masked-IMEISV", "x2ap.Masked_IMEISV",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MDT_Configuration_PDU,
{ "MDT-Configuration", "x2ap.MDT_Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MDTPLMNList_PDU,
{ "MDTPLMNList", "x2ap.MDTPLMNList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MDT_Location_Info_PDU,
{ "MDT-Location-Info", "x2ap.MDT_Location_Info",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_Measurement_ID_PDU,
{ "Measurement-ID", "x2ap.Measurement_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MeNBtoSeNBContainer_PDU,
{ "MeNBtoSeNBContainer", "x2ap.MeNBtoSeNBContainer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MBMS_Service_Area_Identity_List_PDU,
{ "MBMS-Service-Area-Identity-List", "x2ap.MBMS_Service_Area_Identity_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MBSFN_Subframe_Infolist_PDU,
{ "MBSFN-Subframe-Infolist", "x2ap.MBSFN_Subframe_Infolist",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MobilityParametersModificationRange_PDU,
{ "MobilityParametersModificationRange", "x2ap.MobilityParametersModificationRange_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MobilityParametersInformation_PDU,
{ "MobilityParametersInformation", "x2ap.MobilityParametersInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MultibandInfoList_PDU,
{ "MultibandInfoList", "x2ap.MultibandInfoList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_Number_of_Antennaports_PDU,
{ "Number-of-Antennaports", "x2ap.Number_of_Antennaports",
FT_UINT32, BASE_DEC, VALS(x2ap_Number_of_Antennaports_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_OffsetOfNbiotChannelNumberToEARFCN_PDU,
{ "OffsetOfNbiotChannelNumberToEARFCN", "x2ap.OffsetOfNbiotChannelNumberToEARFCN",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &x2ap_OffsetOfNbiotChannelNumberToEARFCN_vals_ext, 0,
NULL, HFILL }},
{ &hf_x2ap_PCI_PDU,
{ "PCI", "x2ap.PCI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_PLMN_Identity_PDU,
{ "PLMN-Identity", "x2ap.PLMN_Identity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_PRACH_Configuration_PDU,
{ "PRACH-Configuration", "x2ap.PRACH_Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ProSeAuthorized_PDU,
{ "ProSeAuthorized", "x2ap.ProSeAuthorized_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ProSeUEtoNetworkRelaying_PDU,
{ "ProSeUEtoNetworkRelaying", "x2ap.ProSeUEtoNetworkRelaying",
FT_UINT32, BASE_DEC, VALS(x2ap_ProSeUEtoNetworkRelaying_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_ReceiveStatusOfULPDCPSDUsExtended_PDU,
{ "ReceiveStatusOfULPDCPSDUsExtended", "x2ap.ReceiveStatusOfULPDCPSDUsExtended",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18_PDU,
{ "ReceiveStatusOfULPDCPSDUsPDCP-SNlength18", "x2ap.ReceiveStatusOfULPDCPSDUsPDCP_SNlength18",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_Registration_Request_PDU,
{ "Registration-Request", "x2ap.Registration_Request",
FT_UINT32, BASE_DEC, VALS(x2ap_Registration_Request_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_ReportCharacteristics_PDU,
{ "ReportCharacteristics", "x2ap.ReportCharacteristics",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ReportingPeriodicityCSIR_PDU,
{ "ReportingPeriodicityCSIR", "x2ap.ReportingPeriodicityCSIR",
FT_UINT32, BASE_DEC, VALS(x2ap_ReportingPeriodicityCSIR_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_ReportingPeriodicityRSRPMR_PDU,
{ "ReportingPeriodicityRSRPMR", "x2ap.ReportingPeriodicityRSRPMR",
FT_UINT32, BASE_DEC, VALS(x2ap_ReportingPeriodicityRSRPMR_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_ResumeID_PDU,
{ "ResumeID", "x2ap.ResumeID",
FT_UINT32, BASE_DEC, VALS(x2ap_ResumeID_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_RRCConnReestabIndicator_PDU,
{ "RRCConnReestabIndicator", "x2ap.RRCConnReestabIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_RRCConnReestabIndicator_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_RRCConnSetupIndicator_PDU,
{ "RRCConnSetupIndicator", "x2ap.RRCConnSetupIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_RRCConnSetupIndicator_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_RSRPMRList_PDU,
{ "RSRPMRList", "x2ap.RSRPMRList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_SCGChangeIndication_PDU,
{ "SCGChangeIndication", "x2ap.SCGChangeIndication",
FT_UINT32, BASE_DEC, VALS(x2ap_SCGChangeIndication_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBSecurityKey_PDU,
{ "SeNBSecurityKey", "x2ap.SeNBSecurityKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBtoMeNBContainer_PDU,
{ "SeNBtoMeNBContainer", "x2ap.SeNBtoMeNBContainer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ServedCells_PDU,
{ "ServedCells", "x2ap.ServedCells",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_SIPTOBearerDeactivationIndication_PDU,
{ "SIPTOBearerDeactivationIndication", "x2ap.SIPTOBearerDeactivationIndication",
FT_UINT32, BASE_DEC, VALS(x2ap_SIPTOBearerDeactivationIndication_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_ShortMAC_I_PDU,
{ "ShortMAC-I", "x2ap.ShortMAC_I",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_SRVCCOperationPossible_PDU,
{ "SRVCCOperationPossible", "x2ap.SRVCCOperationPossible",
FT_UINT32, BASE_DEC, VALS(x2ap_SRVCCOperationPossible_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_SubframeAssignment_PDU,
{ "SubframeAssignment", "x2ap.SubframeAssignment",
FT_UINT32, BASE_DEC, VALS(x2ap_SubframeAssignment_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_TAC_PDU,
{ "TAC", "x2ap.TAC",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_TargetCellInUTRAN_PDU,
{ "TargetCellInUTRAN", "x2ap.TargetCellInUTRAN",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_TargeteNBtoSource_eNBTransparentContainer_PDU,
{ "TargeteNBtoSource-eNBTransparentContainer", "x2ap.TargeteNBtoSource_eNBTransparentContainer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_TimeToWait_PDU,
{ "TimeToWait", "x2ap.TimeToWait",
FT_UINT32, BASE_DEC, VALS(x2ap_TimeToWait_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_Time_UE_StayedInCell_EnhancedGranularity_PDU,
{ "Time-UE-StayedInCell-EnhancedGranularity", "x2ap.Time_UE_StayedInCell_EnhancedGranularity",
FT_UINT32, BASE_CUSTOM, CF_FUNC(x2ap_Time_UE_StayedInCell_EnhancedGranularity_fmt), 0,
NULL, HFILL }},
{ &hf_x2ap_TraceActivation_PDU,
{ "TraceActivation", "x2ap.TraceActivation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_TransportLayerAddress_PDU,
{ "TransportLayerAddress", "x2ap.TransportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_TunnelInformation_PDU,
{ "TunnelInformation", "x2ap.TunnelInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UEAggregateMaximumBitRate_PDU,
{ "UEAggregateMaximumBitRate", "x2ap.UEAggregateMaximumBitRate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_ContextKeptIndicator_PDU,
{ "UE-ContextKeptIndicator", "x2ap.UE_ContextKeptIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_UE_ContextKeptIndicator_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_UEID_PDU,
{ "UEID", "x2ap.UEID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_HistoryInformation_PDU,
{ "UE-HistoryInformation", "x2ap.UE_HistoryInformation",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_HistoryInformationFromTheUE_PDU,
{ "UE-HistoryInformationFromTheUE", "x2ap.UE_HistoryInformationFromTheUE",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_X2AP_ID_PDU,
{ "UE-X2AP-ID", "x2ap.UE_X2AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_X2AP_ID_Extension_PDU,
{ "UE-X2AP-ID-Extension", "x2ap.UE_X2AP_ID_Extension",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_RLF_Report_Container_PDU,
{ "UE-RLF-Report-Container", "x2ap.UE_RLF_Report_Container",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_RLF_Report_Container_for_extended_bands_PDU,
{ "UE-RLF-Report-Container-for-extended-bands", "x2ap.UE_RLF_Report_Container_for_extended_bands",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UESecurityCapabilities_PDU,
{ "UESecurityCapabilities", "x2ap.UESecurityCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_X2BenefitValue_PDU,
{ "X2BenefitValue", "x2ap.X2BenefitValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_HandoverRequest_PDU,
{ "HandoverRequest", "x2ap.HandoverRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_ContextInformation_PDU,
{ "UE-ContextInformation", "x2ap.UE_ContextInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeSetup_Item_PDU,
{ "E-RABs-ToBeSetup-Item", "x2ap.E_RABs_ToBeSetup_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MobilityInformation_PDU,
{ "MobilityInformation", "x2ap.MobilityInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_ContextReferenceAtSeNB_PDU,
{ "UE-ContextReferenceAtSeNB", "x2ap.UE_ContextReferenceAtSeNB_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_HandoverRequestAcknowledge_PDU,
{ "HandoverRequestAcknowledge", "x2ap.HandoverRequestAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_Admitted_List_PDU,
{ "E-RABs-Admitted-List", "x2ap.E_RABs_Admitted_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_Admitted_Item_PDU,
{ "E-RABs-Admitted-Item", "x2ap.E_RABs_Admitted_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_HandoverPreparationFailure_PDU,
{ "HandoverPreparationFailure", "x2ap.HandoverPreparationFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_HandoverReport_PDU,
{ "HandoverReport", "x2ap.HandoverReport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_SNStatusTransfer_PDU,
{ "SNStatusTransfer", "x2ap.SNStatusTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_SubjectToStatusTransfer_List_PDU,
{ "E-RABs-SubjectToStatusTransfer-List", "x2ap.E_RABs_SubjectToStatusTransfer_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_SubjectToStatusTransfer_Item_PDU,
{ "E-RABs-SubjectToStatusTransfer-Item", "x2ap.E_RABs_SubjectToStatusTransfer_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UEContextRelease_PDU,
{ "UEContextRelease", "x2ap.UEContextRelease_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_HandoverCancel_PDU,
{ "HandoverCancel", "x2ap.HandoverCancel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ErrorIndication_PDU,
{ "ErrorIndication", "x2ap.ErrorIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ResetRequest_PDU,
{ "ResetRequest", "x2ap.ResetRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ResetResponse_PDU,
{ "ResetResponse", "x2ap.ResetResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_X2SetupRequest_PDU,
{ "X2SetupRequest", "x2ap.X2SetupRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_X2SetupResponse_PDU,
{ "X2SetupResponse", "x2ap.X2SetupResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_X2SetupFailure_PDU,
{ "X2SetupFailure", "x2ap.X2SetupFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_LoadInformation_PDU,
{ "LoadInformation", "x2ap.LoadInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellInformation_List_PDU,
{ "CellInformation-List", "x2ap.CellInformation_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellInformation_Item_PDU,
{ "CellInformation-Item", "x2ap.CellInformation_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ENBConfigurationUpdate_PDU,
{ "ENBConfigurationUpdate", "x2ap.ENBConfigurationUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ServedCellsToModify_PDU,
{ "ServedCellsToModify", "x2ap.ServedCellsToModify",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_Old_ECGIs_PDU,
{ "Old-ECGIs", "x2ap.Old_ECGIs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ENBConfigurationUpdateAcknowledge_PDU,
{ "ENBConfigurationUpdateAcknowledge", "x2ap.ENBConfigurationUpdateAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ENBConfigurationUpdateFailure_PDU,
{ "ENBConfigurationUpdateFailure", "x2ap.ENBConfigurationUpdateFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ResourceStatusRequest_PDU,
{ "ResourceStatusRequest", "x2ap.ResourceStatusRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellToReport_List_PDU,
{ "CellToReport-List", "x2ap.CellToReport_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellToReport_Item_PDU,
{ "CellToReport-Item", "x2ap.CellToReport_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ReportingPeriodicity_PDU,
{ "ReportingPeriodicity", "x2ap.ReportingPeriodicity",
FT_UINT32, BASE_DEC, VALS(x2ap_ReportingPeriodicity_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_PartialSuccessIndicator_PDU,
{ "PartialSuccessIndicator", "x2ap.PartialSuccessIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_PartialSuccessIndicator_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_ResourceStatusResponse_PDU,
{ "ResourceStatusResponse", "x2ap.ResourceStatusResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MeasurementInitiationResult_List_PDU,
{ "MeasurementInitiationResult-List", "x2ap.MeasurementInitiationResult_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MeasurementInitiationResult_Item_PDU,
{ "MeasurementInitiationResult-Item", "x2ap.MeasurementInitiationResult_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MeasurementFailureCause_Item_PDU,
{ "MeasurementFailureCause-Item", "x2ap.MeasurementFailureCause_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ResourceStatusFailure_PDU,
{ "ResourceStatusFailure", "x2ap.ResourceStatusFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CompleteFailureCauseInformation_List_PDU,
{ "CompleteFailureCauseInformation-List", "x2ap.CompleteFailureCauseInformation_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CompleteFailureCauseInformation_Item_PDU,
{ "CompleteFailureCauseInformation-Item", "x2ap.CompleteFailureCauseInformation_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ResourceStatusUpdate_PDU,
{ "ResourceStatusUpdate", "x2ap.ResourceStatusUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellMeasurementResult_List_PDU,
{ "CellMeasurementResult-List", "x2ap.CellMeasurementResult_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellMeasurementResult_Item_PDU,
{ "CellMeasurementResult-Item", "x2ap.CellMeasurementResult_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_PrivateMessage_PDU,
{ "PrivateMessage", "x2ap.PrivateMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MobilityChangeRequest_PDU,
{ "MobilityChangeRequest", "x2ap.MobilityChangeRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MobilityChangeAcknowledge_PDU,
{ "MobilityChangeAcknowledge", "x2ap.MobilityChangeAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MobilityChangeFailure_PDU,
{ "MobilityChangeFailure", "x2ap.MobilityChangeFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_RLFIndication_PDU,
{ "RLFIndication", "x2ap.RLFIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellActivationRequest_PDU,
{ "CellActivationRequest", "x2ap.CellActivationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ServedCellsToActivate_PDU,
{ "ServedCellsToActivate", "x2ap.ServedCellsToActivate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellActivationResponse_PDU,
{ "CellActivationResponse", "x2ap.CellActivationResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ActivatedCellList_PDU,
{ "ActivatedCellList", "x2ap.ActivatedCellList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellActivationFailure_PDU,
{ "CellActivationFailure", "x2ap.CellActivationFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_X2Release_PDU,
{ "X2Release", "x2ap.X2Release_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_X2APMessageTransfer_PDU,
{ "X2APMessageTransfer", "x2ap.X2APMessageTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_RNL_Header_PDU,
{ "RNL-Header", "x2ap.RNL_Header_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_X2AP_Message_PDU,
{ "X2AP-Message", "x2ap.X2AP_Message",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBAdditionRequest_PDU,
{ "SeNBAdditionRequest", "x2ap.SeNBAdditionRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeAdded_List_PDU,
{ "E-RABs-ToBeAdded-List", "x2ap.E_RABs_ToBeAdded_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeAdded_Item_PDU,
{ "E-RABs-ToBeAdded-Item", "x2ap.E_RABs_ToBeAdded_Item",
FT_UINT32, BASE_DEC, VALS(x2ap_E_RABs_ToBeAdded_Item_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBAdditionRequestAcknowledge_PDU,
{ "SeNBAdditionRequestAcknowledge", "x2ap.SeNBAdditionRequestAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_Admitted_ToBeAdded_List_PDU,
{ "E-RABs-Admitted-ToBeAdded-List", "x2ap.E_RABs_Admitted_ToBeAdded_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_Admitted_ToBeAdded_Item_PDU,
{ "E-RABs-Admitted-ToBeAdded-Item", "x2ap.E_RABs_Admitted_ToBeAdded_Item",
FT_UINT32, BASE_DEC, VALS(x2ap_E_RABs_Admitted_ToBeAdded_Item_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBAdditionRequestReject_PDU,
{ "SeNBAdditionRequestReject", "x2ap.SeNBAdditionRequestReject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBReconfigurationComplete_PDU,
{ "SeNBReconfigurationComplete", "x2ap.SeNBReconfigurationComplete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ResponseInformationSeNBReconfComp_PDU,
{ "ResponseInformationSeNBReconfComp", "x2ap.ResponseInformationSeNBReconfComp",
FT_UINT32, BASE_DEC, VALS(x2ap_ResponseInformationSeNBReconfComp_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBModificationRequest_PDU,
{ "SeNBModificationRequest", "x2ap.SeNBModificationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_ContextInformationSeNBModReq_PDU,
{ "UE-ContextInformationSeNBModReq", "x2ap.UE_ContextInformationSeNBModReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeAdded_ModReqItem_PDU,
{ "E-RABs-ToBeAdded-ModReqItem", "x2ap.E_RABs_ToBeAdded_ModReqItem",
FT_UINT32, BASE_DEC, VALS(x2ap_E_RABs_ToBeAdded_ModReqItem_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeModified_ModReqItem_PDU,
{ "E-RABs-ToBeModified-ModReqItem", "x2ap.E_RABs_ToBeModified_ModReqItem",
FT_UINT32, BASE_DEC, VALS(x2ap_E_RABs_ToBeModified_ModReqItem_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeReleased_ModReqItem_PDU,
{ "E-RABs-ToBeReleased-ModReqItem", "x2ap.E_RABs_ToBeReleased_ModReqItem",
FT_UINT32, BASE_DEC, VALS(x2ap_E_RABs_ToBeReleased_ModReqItem_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBModificationRequestAcknowledge_PDU,
{ "SeNBModificationRequestAcknowledge", "x2ap.SeNBModificationRequestAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_Admitted_ToBeAdded_ModAckList_PDU,
{ "E-RABs-Admitted-ToBeAdded-ModAckList", "x2ap.E_RABs_Admitted_ToBeAdded_ModAckList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_Admitted_ToBeAdded_ModAckItem_PDU,
{ "E-RABs-Admitted-ToBeAdded-ModAckItem", "x2ap.E_RABs_Admitted_ToBeAdded_ModAckItem",
FT_UINT32, BASE_DEC, VALS(x2ap_E_RABs_Admitted_ToBeAdded_ModAckItem_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_Admitted_ToBeModified_ModAckList_PDU,
{ "E-RABs-Admitted-ToBeModified-ModAckList", "x2ap.E_RABs_Admitted_ToBeModified_ModAckList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_Admitted_ToBeModified_ModAckItem_PDU,
{ "E-RABs-Admitted-ToBeModified-ModAckItem", "x2ap.E_RABs_Admitted_ToBeModified_ModAckItem",
FT_UINT32, BASE_DEC, VALS(x2ap_E_RABs_Admitted_ToBeModified_ModAckItem_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_Admitted_ToBeReleased_ModAckList_PDU,
{ "E-RABs-Admitted-ToBeReleased-ModAckList", "x2ap.E_RABs_Admitted_ToBeReleased_ModAckList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_Admitted_ToReleased_ModAckItem_PDU,
{ "E-RABs-Admitted-ToReleased-ModAckItem", "x2ap.E_RABs_Admitted_ToReleased_ModAckItem",
FT_UINT32, BASE_DEC, VALS(x2ap_E_RABs_Admitted_ToReleased_ModAckItem_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBModificationRequestReject_PDU,
{ "SeNBModificationRequestReject", "x2ap.SeNBModificationRequestReject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBModificationRequired_PDU,
{ "SeNBModificationRequired", "x2ap.SeNBModificationRequired_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeReleased_ModReqd_PDU,
{ "E-RABs-ToBeReleased-ModReqd", "x2ap.E_RABs_ToBeReleased_ModReqd",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeReleased_ModReqdItem_PDU,
{ "E-RABs-ToBeReleased-ModReqdItem", "x2ap.E_RABs_ToBeReleased_ModReqdItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBModificationConfirm_PDU,
{ "SeNBModificationConfirm", "x2ap.SeNBModificationConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBModificationRefuse_PDU,
{ "SeNBModificationRefuse", "x2ap.SeNBModificationRefuse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBReleaseRequest_PDU,
{ "SeNBReleaseRequest", "x2ap.SeNBReleaseRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeReleased_List_RelReq_PDU,
{ "E-RABs-ToBeReleased-List-RelReq", "x2ap.E_RABs_ToBeReleased_List_RelReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeReleased_RelReqItem_PDU,
{ "E-RABs-ToBeReleased-RelReqItem", "x2ap.E_RABs_ToBeReleased_RelReqItem",
FT_UINT32, BASE_DEC, VALS(x2ap_E_RABs_ToBeReleased_RelReqItem_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBReleaseRequired_PDU,
{ "SeNBReleaseRequired", "x2ap.SeNBReleaseRequired_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBReleaseConfirm_PDU,
{ "SeNBReleaseConfirm", "x2ap.SeNBReleaseConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeReleased_List_RelConf_PDU,
{ "E-RABs-ToBeReleased-List-RelConf", "x2ap.E_RABs_ToBeReleased_List_RelConf",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeReleased_RelConfItem_PDU,
{ "E-RABs-ToBeReleased-RelConfItem", "x2ap.E_RABs_ToBeReleased_RelConfItem",
FT_UINT32, BASE_DEC, VALS(x2ap_E_RABs_ToBeReleased_RelConfItem_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_SeNBCounterCheckRequest_PDU,
{ "SeNBCounterCheckRequest", "x2ap.SeNBCounterCheckRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_SubjectToCounterCheck_List_PDU,
{ "E-RABs-SubjectToCounterCheck-List", "x2ap.E_RABs_SubjectToCounterCheck_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_SubjectToCounterCheckItem_PDU,
{ "E-RABs-SubjectToCounterCheckItem", "x2ap.E_RABs_SubjectToCounterCheckItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_X2RemovalRequest_PDU,
{ "X2RemovalRequest", "x2ap.X2RemovalRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_X2RemovalResponse_PDU,
{ "X2RemovalResponse", "x2ap.X2RemovalResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_X2RemovalFailure_PDU,
{ "X2RemovalFailure", "x2ap.X2RemovalFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_RetrieveUEContextRequest_PDU,
{ "RetrieveUEContextRequest", "x2ap.RetrieveUEContextRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_RetrieveUEContextResponse_PDU,
{ "RetrieveUEContextResponse", "x2ap.RetrieveUEContextResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UE_ContextInformationRetrieve_PDU,
{ "UE-ContextInformationRetrieve", "x2ap.UE_ContextInformationRetrieve_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeSetupRetrieve_Item_PDU,
{ "E-RABs-ToBeSetupRetrieve-Item", "x2ap.E_RABs_ToBeSetupRetrieve_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_RetrieveUEContextFailure_PDU,
{ "RetrieveUEContextFailure", "x2ap.RetrieveUEContextFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_X2AP_PDU_PDU,
{ "X2AP-PDU", "x2ap.X2AP_PDU",
FT_UINT32, BASE_DEC, VALS(x2ap_X2AP_PDU_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_local,
{ "local", "x2ap.local",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_maxPrivateIEs", HFILL }},
{ &hf_x2ap_global,
{ "global", "x2ap.global",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x2ap_ProtocolIE_Container_item,
{ "ProtocolIE-Field", "x2ap.ProtocolIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_id,
{ "id", "x2ap.id",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &x2ap_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_x2ap_criticality,
{ "criticality", "x2ap.criticality",
FT_UINT32, BASE_DEC, VALS(x2ap_Criticality_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_protocolIE_Field_value,
{ "value", "x2ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProtocolIE_Field_value", HFILL }},
{ &hf_x2ap_ProtocolExtensionContainer_item,
{ "ProtocolExtensionField", "x2ap.ProtocolExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_extension_id,
{ "id", "x2ap.id",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &x2ap_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_x2ap_extensionValue,
{ "extensionValue", "x2ap.extensionValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_PrivateIE_Container_item,
{ "PrivateIE-Field", "x2ap.PrivateIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_private_id,
{ "id", "x2ap.id",
FT_UINT32, BASE_DEC, VALS(x2ap_PrivateIE_ID_vals), 0,
"PrivateIE_ID", HFILL }},
{ &hf_x2ap_privateIE_Field_value,
{ "value", "x2ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"PrivateIE_Field_value", HFILL }},
{ &hf_x2ap_fdd,
{ "fdd", "x2ap.fdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"ABSInformationFDD", HFILL }},
{ &hf_x2ap_tdd,
{ "tdd", "x2ap.tdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"ABSInformationTDD", HFILL }},
{ &hf_x2ap_abs_inactive,
{ "abs-inactive", "x2ap.abs_inactive_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_abs_pattern_info,
{ "abs-pattern-info", "x2ap.abs_pattern_info",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_40", HFILL }},
{ &hf_x2ap_numberOfCellSpecificAntennaPorts,
{ "numberOfCellSpecificAntennaPorts", "x2ap.numberOfCellSpecificAntennaPorts",
FT_UINT32, BASE_DEC, VALS(x2ap_T_numberOfCellSpecificAntennaPorts_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_measurement_subset,
{ "measurement-subset", "x2ap.measurement_subset",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_40", HFILL }},
{ &hf_x2ap_iE_Extensions,
{ "iE-Extensions", "x2ap.iE_Extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_x2ap_abs_pattern_info_01,
{ "abs-pattern-info", "x2ap.abs_pattern_info",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_1_70_", HFILL }},
{ &hf_x2ap_numberOfCellSpecificAntennaPorts_01,
{ "numberOfCellSpecificAntennaPorts", "x2ap.numberOfCellSpecificAntennaPorts",
FT_UINT32, BASE_DEC, VALS(x2ap_T_numberOfCellSpecificAntennaPorts_01_vals), 0,
"T_numberOfCellSpecificAntennaPorts_01", HFILL }},
{ &hf_x2ap_measurement_subset_01,
{ "measurement-subset", "x2ap.measurement_subset",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_1_70_", HFILL }},
{ &hf_x2ap_dL_ABS_status,
{ "dL-ABS-status", "x2ap.dL_ABS_status",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_usableABSInformation,
{ "usableABSInformation", "x2ap.usableABSInformation",
FT_UINT32, BASE_DEC, VALS(x2ap_UsableABSInformation_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_additionalspecialSubframePatterns,
{ "additionalspecialSubframePatterns", "x2ap.additionalspecialSubframePatterns",
FT_UINT32, BASE_DEC, VALS(x2ap_AdditionalSpecialSubframePatterns_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_cyclicPrefixDL,
{ "cyclicPrefixDL", "x2ap.cyclicPrefixDL",
FT_UINT32, BASE_DEC, VALS(x2ap_CyclicPrefixDL_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_cyclicPrefixUL,
{ "cyclicPrefixUL", "x2ap.cyclicPrefixUL",
FT_UINT32, BASE_DEC, VALS(x2ap_CyclicPrefixUL_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_priorityLevel,
{ "priorityLevel", "x2ap.priorityLevel",
FT_UINT32, BASE_DEC, VALS(x2ap_PriorityLevel_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_pre_emptionCapability,
{ "pre-emptionCapability", "x2ap.pre_emptionCapability",
FT_UINT32, BASE_DEC, VALS(x2ap_Pre_emptionCapability_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_pre_emptionVulnerability,
{ "pre-emptionVulnerability", "x2ap.pre_emptionVulnerability",
FT_UINT32, BASE_DEC, VALS(x2ap_Pre_emptionVulnerability_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_cellBased,
{ "cellBased", "x2ap.cellBased_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellBasedMDT", HFILL }},
{ &hf_x2ap_tABased,
{ "tABased", "x2ap.tABased_element",
FT_NONE, BASE_NONE, NULL, 0,
"TABasedMDT", HFILL }},
{ &hf_x2ap_pLMNWide,
{ "pLMNWide", "x2ap.pLMNWide_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_tAIBased,
{ "tAIBased", "x2ap.tAIBased_element",
FT_NONE, BASE_NONE, NULL, 0,
"TAIBasedMDT", HFILL }},
{ &hf_x2ap_key_eNodeB_star,
{ "key-eNodeB-star", "x2ap.key_eNodeB_star",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_nextHopChainingCount,
{ "nextHopChainingCount", "x2ap.nextHopChainingCount",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_BroadcastPLMNs_Item_item,
{ "PLMN-Identity", "x2ap.PLMN_Identity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_radioNetwork,
{ "radioNetwork", "x2ap.radioNetwork",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &x2ap_CauseRadioNetwork_vals_ext, 0,
"CauseRadioNetwork", HFILL }},
{ &hf_x2ap_transport,
{ "transport", "x2ap.transport",
FT_UINT32, BASE_DEC, VALS(x2ap_CauseTransport_vals), 0,
"CauseTransport", HFILL }},
{ &hf_x2ap_protocol,
{ "protocol", "x2ap.protocol",
FT_UINT32, BASE_DEC, VALS(x2ap_CauseProtocol_vals), 0,
"CauseProtocol", HFILL }},
{ &hf_x2ap_misc,
{ "misc", "x2ap.misc",
FT_UINT32, BASE_DEC, VALS(x2ap_CauseMisc_vals), 0,
"CauseMisc", HFILL }},
{ &hf_x2ap_cellIdListforMDT,
{ "cellIdListforMDT", "x2ap.cellIdListforMDT",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellIdListforMDT_item,
{ "ECGI", "x2ap.ECGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_replacingCellsList,
{ "replacingCellsList", "x2ap.replacingCellsList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_cell_Size,
{ "cell-Size", "x2ap.cell_Size",
FT_UINT32, BASE_DEC, VALS(x2ap_Cell_Size_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_CoMPHypothesisSet_item,
{ "CoMPHypothesisSetItem", "x2ap.CoMPHypothesisSetItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_coMPCellID,
{ "coMPCellID", "x2ap.coMPCellID_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_x2ap_coMPHypothesis,
{ "coMPHypothesis", "x2ap.coMPHypothesis",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_6_4400_", HFILL }},
{ &hf_x2ap_coMPInformationItem,
{ "coMPInformationItem", "x2ap.coMPInformationItem",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_coMPInformationStartTime,
{ "coMPInformationStartTime", "x2ap.coMPInformationStartTime",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CoMPInformationItem_item,
{ "CoMPInformationItem item", "x2ap.CoMPInformationItem_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_coMPHypothesisSet,
{ "coMPHypothesisSet", "x2ap.coMPHypothesisSet",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_benefitMetric,
{ "benefitMetric", "x2ap.benefitMetric",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CoMPInformationStartTime_item,
{ "CoMPInformationStartTime item", "x2ap.CoMPInformationStartTime_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_startSFN,
{ "startSFN", "x2ap.startSFN",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023_", HFILL }},
{ &hf_x2ap_startSubframeNumber,
{ "startSubframeNumber", "x2ap.startSubframeNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_9_", HFILL }},
{ &hf_x2ap_cellCapacityClassValue,
{ "cellCapacityClassValue", "x2ap.cellCapacityClassValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_capacityValue,
{ "capacityValue", "x2ap.capacityValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_dL_CompositeAvailableCapacity,
{ "dL-CompositeAvailableCapacity", "x2ap.dL_CompositeAvailableCapacity_element",
FT_NONE, BASE_NONE, NULL, 0,
"CompositeAvailableCapacity", HFILL }},
{ &hf_x2ap_uL_CompositeAvailableCapacity,
{ "uL-CompositeAvailableCapacity", "x2ap.uL_CompositeAvailableCapacity_element",
FT_NONE, BASE_NONE, NULL, 0,
"CompositeAvailableCapacity", HFILL }},
{ &hf_x2ap_pDCP_SN,
{ "pDCP-SN", "x2ap.pDCP_SN",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_hFN,
{ "hFN", "x2ap.hFN",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_pDCP_SNExtended,
{ "pDCP-SNExtended", "x2ap.pDCP_SNExtended",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_hFNModified,
{ "hFNModified", "x2ap.hFNModified",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_pDCP_SNlength18,
{ "pDCP-SNlength18", "x2ap.pDCP_SNlength18",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_hFNforPDCP_SNlength18,
{ "hFNforPDCP-SNlength18", "x2ap.hFNforPDCP_SNlength18",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CoverageModificationList_item,
{ "CoverageModification-Item", "x2ap.CoverageModification_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_eCGI,
{ "eCGI", "x2ap.eCGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_coverageState,
{ "coverageState", "x2ap.coverageState",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15_", HFILL }},
{ &hf_x2ap_cellDeploymentStatusIndicator,
{ "cellDeploymentStatusIndicator", "x2ap.cellDeploymentStatusIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_CellDeploymentStatusIndicator_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_cellReplacingInfo,
{ "cellReplacingInfo", "x2ap.cellReplacingInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_procedureCode,
{ "procedureCode", "x2ap.procedureCode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &x2ap_ProcedureCode_vals_ext, 0,
NULL, HFILL }},
{ &hf_x2ap_triggeringMessage,
{ "triggeringMessage", "x2ap.triggeringMessage",
FT_UINT32, BASE_DEC, VALS(x2ap_TriggeringMessage_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_procedureCriticality,
{ "procedureCriticality", "x2ap.procedureCriticality",
FT_UINT32, BASE_DEC, VALS(x2ap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_x2ap_iEsCriticalityDiagnostics,
{ "iEsCriticalityDiagnostics", "x2ap.iEsCriticalityDiagnostics",
FT_UINT32, BASE_DEC, NULL, 0,
"CriticalityDiagnostics_IE_List", HFILL }},
{ &hf_x2ap_CriticalityDiagnostics_IE_List_item,
{ "CriticalityDiagnostics-IE-List item", "x2ap.CriticalityDiagnostics_IE_List_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_iECriticality,
{ "iECriticality", "x2ap.iECriticality",
FT_UINT32, BASE_DEC, VALS(x2ap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_x2ap_iE_ID,
{ "iE-ID", "x2ap.iE_ID",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &x2ap_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_x2ap_typeOfError,
{ "typeOfError", "x2ap.typeOfError",
FT_UINT32, BASE_DEC, VALS(x2ap_TypeOfError_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_CSIReportList_item,
{ "CSIReportList item", "x2ap.CSIReportList_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uEID,
{ "uEID", "x2ap.uEID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_cSIReportPerCSIProcess,
{ "cSIReportPerCSIProcess", "x2ap.cSIReportPerCSIProcess",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CSIReportPerCSIProcess_item,
{ "CSIReportPerCSIProcess item", "x2ap.CSIReportPerCSIProcess_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_cSIProcessConfigurationIndex,
{ "cSIProcessConfigurationIndex", "x2ap.cSIProcessConfigurationIndex",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_7_", HFILL }},
{ &hf_x2ap_cSIReportPerCSIProcessItem,
{ "cSIReportPerCSIProcessItem", "x2ap.cSIReportPerCSIProcessItem",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CSIReportPerCSIProcessItem_item,
{ "CSIReportPerCSIProcessItem item", "x2ap.CSIReportPerCSIProcessItem_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_rI,
{ "rI", "x2ap.rI",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_8_", HFILL }},
{ &hf_x2ap_widebandCQI,
{ "widebandCQI", "x2ap.widebandCQI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_subbandSize,
{ "subbandSize", "x2ap.subbandSize",
FT_UINT32, BASE_DEC, VALS(x2ap_SubbandSize_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_subbandCQIList,
{ "subbandCQIList", "x2ap.subbandCQIList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_naics_active,
{ "naics-active", "x2ap.naics_active_element",
FT_NONE, BASE_NONE, NULL, 0,
"DynamicNAICSInformation", HFILL }},
{ &hf_x2ap_naics_inactive,
{ "naics-inactive", "x2ap.naics_inactive_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_transmissionModes,
{ "transmissionModes", "x2ap.transmissionModes",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_pB_information,
{ "pB-information", "x2ap.pB_information",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_x2ap_pA_list,
{ "pA-list", "x2ap.pA_list",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_0_maxnoofPA_OF_PA_Values", HFILL }},
{ &hf_x2ap_pA_list_item,
{ "PA-Values", "x2ap.PA_Values",
FT_UINT32, BASE_DEC, VALS(x2ap_PA_Values_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_pLMN_Identity,
{ "pLMN-Identity", "x2ap.pLMN_Identity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_eUTRANcellIdentifier,
{ "eUTRANcellIdentifier", "x2ap.eUTRANcellIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_enhancedRNTPBitmap,
{ "enhancedRNTPBitmap", "x2ap.enhancedRNTPBitmap",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_12_8800_", HFILL }},
{ &hf_x2ap_rNTP_High_Power_Threshold,
{ "rNTP-High-Power-Threshold", "x2ap.rNTP_High_Power_Threshold",
FT_UINT32, BASE_DEC, VALS(x2ap_RNTP_Threshold_vals), 0,
"RNTP_Threshold", HFILL }},
{ &hf_x2ap_enhancedRNTPStartTime,
{ "enhancedRNTPStartTime", "x2ap.enhancedRNTPStartTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_macro_eNB_ID,
{ "macro-eNB-ID", "x2ap.macro_eNB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_20", HFILL }},
{ &hf_x2ap_home_eNB_ID,
{ "home-eNB-ID", "x2ap.home_eNB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_28", HFILL }},
{ &hf_x2ap_EPLMNs_item,
{ "PLMN-Identity", "x2ap.PLMN_Identity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_qCI,
{ "qCI", "x2ap.qCI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_allocationAndRetentionPriority,
{ "allocationAndRetentionPriority", "x2ap.allocationAndRetentionPriority_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_gbrQosInformation,
{ "gbrQosInformation", "x2ap.gbrQosInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
"GBR_QosInformation", HFILL }},
{ &hf_x2ap_E_RAB_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_e_RAB_ID,
{ "e-RAB-ID", "x2ap.e_RAB_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_cause,
{ "cause", "x2ap.cause",
FT_UINT32, BASE_DEC, VALS(x2ap_Cause_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_fDD,
{ "fDD", "x2ap.fDD_element",
FT_NONE, BASE_NONE, NULL, 0,
"FDD_Info", HFILL }},
{ &hf_x2ap_tDD,
{ "tDD", "x2ap.tDD_element",
FT_NONE, BASE_NONE, NULL, 0,
"TDD_Info", HFILL }},
{ &hf_x2ap_expectedActivity,
{ "expectedActivity", "x2ap.expectedActivity_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExpectedUEActivityBehaviour", HFILL }},
{ &hf_x2ap_expectedHOInterval,
{ "expectedHOInterval", "x2ap.expectedHOInterval",
FT_UINT32, BASE_DEC, VALS(x2ap_ExpectedHOInterval_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_expectedActivityPeriod,
{ "expectedActivityPeriod", "x2ap.expectedActivityPeriod",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
NULL, HFILL }},
{ &hf_x2ap_expectedIdlePeriod,
{ "expectedIdlePeriod", "x2ap.expectedIdlePeriod",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
NULL, HFILL }},
{ &hf_x2ap_sourceofUEActivityBehaviourInformation,
{ "sourceofUEActivityBehaviourInformation", "x2ap.sourceofUEActivityBehaviourInformation",
FT_UINT32, BASE_DEC, VALS(x2ap_SourceOfUEActivityBehaviourInformation_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_associatedSubframes,
{ "associatedSubframes", "x2ap.associatedSubframes",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_5", HFILL }},
{ &hf_x2ap_extended_ul_InterferenceOverloadIndication,
{ "extended-ul-InterferenceOverloadIndication", "x2ap.extended_ul_InterferenceOverloadIndication",
FT_UINT32, BASE_DEC, NULL, 0,
"UL_InterferenceOverloadIndication", HFILL }},
{ &hf_x2ap_uL_EARFCN,
{ "uL-EARFCN", "x2ap.uL_EARFCN",
FT_UINT32, BASE_DEC, NULL, 0,
"EARFCN", HFILL }},
{ &hf_x2ap_dL_EARFCN,
{ "dL-EARFCN", "x2ap.dL_EARFCN",
FT_UINT32, BASE_DEC, NULL, 0,
"EARFCN", HFILL }},
{ &hf_x2ap_uL_Transmission_Bandwidth,
{ "uL-Transmission-Bandwidth", "x2ap.uL_Transmission_Bandwidth",
FT_UINT32, BASE_DEC, VALS(x2ap_Transmission_Bandwidth_vals), 0,
"Transmission_Bandwidth", HFILL }},
{ &hf_x2ap_dL_Transmission_Bandwidth,
{ "dL-Transmission-Bandwidth", "x2ap.dL_Transmission_Bandwidth",
FT_UINT32, BASE_DEC, VALS(x2ap_Transmission_Bandwidth_vals), 0,
"Transmission_Bandwidth", HFILL }},
{ &hf_x2ap_ForbiddenTAs_item,
{ "ForbiddenTAs-Item", "x2ap.ForbiddenTAs_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_forbiddenTACs,
{ "forbiddenTACs", "x2ap.forbiddenTACs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ForbiddenTACs_item,
{ "TAC", "x2ap.TAC",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ForbiddenLAs_item,
{ "ForbiddenLAs-Item", "x2ap.ForbiddenLAs_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_forbiddenLACs,
{ "forbiddenLACs", "x2ap.forbiddenLACs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ForbiddenLACs_item,
{ "LAC", "x2ap.LAC",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_e_RAB_MaximumBitrateDL,
{ "e-RAB-MaximumBitrateDL", "x2ap.e_RAB_MaximumBitrateDL",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
"BitRate", HFILL }},
{ &hf_x2ap_e_RAB_MaximumBitrateUL,
{ "e-RAB-MaximumBitrateUL", "x2ap.e_RAB_MaximumBitrateUL",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
"BitRate", HFILL }},
{ &hf_x2ap_e_RAB_GuaranteedBitrateDL,
{ "e-RAB-GuaranteedBitrateDL", "x2ap.e_RAB_GuaranteedBitrateDL",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
"BitRate", HFILL }},
{ &hf_x2ap_e_RAB_GuaranteedBitrateUL,
{ "e-RAB-GuaranteedBitrateUL", "x2ap.e_RAB_GuaranteedBitrateUL",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
"BitRate", HFILL }},
{ &hf_x2ap_eNB_ID,
{ "eNB-ID", "x2ap.eNB_ID",
FT_UINT32, BASE_DEC, VALS(x2ap_ENB_ID_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_transportLayerAddress,
{ "transportLayerAddress", "x2ap.transportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_gTP_TEID,
{ "gTP-TEID", "x2ap.gTP_TEID",
FT_BYTES, BASE_NONE, NULL, 0,
"GTP_TEI", HFILL }},
{ &hf_x2ap_GUGroupIDList_item,
{ "GU-Group-ID", "x2ap.GU_Group_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_mME_Group_ID,
{ "mME-Group-ID", "x2ap.mME_Group_ID",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_gU_Group_ID,
{ "gU-Group-ID", "x2ap.gU_Group_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_mME_Code,
{ "mME-Code", "x2ap.mME_Code",
FT_UINT8, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_servingPLMN,
{ "servingPLMN", "x2ap.servingPLMN",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMN_Identity", HFILL }},
{ &hf_x2ap_equivalentPLMNs,
{ "equivalentPLMNs", "x2ap.equivalentPLMNs",
FT_UINT32, BASE_DEC, NULL, 0,
"EPLMNs", HFILL }},
{ &hf_x2ap_forbiddenTAs,
{ "forbiddenTAs", "x2ap.forbiddenTAs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_forbiddenLAs,
{ "forbiddenLAs", "x2ap.forbiddenLAs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_forbiddenInterRATs,
{ "forbiddenInterRATs", "x2ap.forbiddenInterRATs",
FT_UINT32, BASE_DEC, VALS(x2ap_ForbiddenInterRATs_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_dLHWLoadIndicator,
{ "dLHWLoadIndicator", "x2ap.dLHWLoadIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_LoadIndicator_vals), 0,
"LoadIndicator", HFILL }},
{ &hf_x2ap_uLHWLoadIndicator,
{ "uLHWLoadIndicator", "x2ap.uLHWLoadIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_LoadIndicator_vals), 0,
"LoadIndicator", HFILL }},
{ &hf_x2ap_e_UTRAN_Cell,
{ "e-UTRAN-Cell", "x2ap.e_UTRAN_Cell_element",
FT_NONE, BASE_NONE, NULL, 0,
"LastVisitedEUTRANCellInformation", HFILL }},
{ &hf_x2ap_uTRAN_Cell,
{ "uTRAN-Cell", "x2ap.uTRAN_Cell",
FT_BYTES, BASE_NONE, NULL, 0,
"LastVisitedUTRANCellInformation", HFILL }},
{ &hf_x2ap_gERAN_Cell,
{ "gERAN-Cell", "x2ap.gERAN_Cell",
FT_UINT32, BASE_DEC, VALS(x2ap_LastVisitedGERANCellInformation_vals), 0,
"LastVisitedGERANCellInformation", HFILL }},
{ &hf_x2ap_global_Cell_ID,
{ "global-Cell-ID", "x2ap.global_Cell_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_x2ap_cellType,
{ "cellType", "x2ap.cellType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_time_UE_StayedInCell,
{ "time-UE-StayedInCell", "x2ap.time_UE_StayedInCell",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
NULL, HFILL }},
{ &hf_x2ap_undefined,
{ "undefined", "x2ap.undefined_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_eventType,
{ "eventType", "x2ap.eventType",
FT_UINT32, BASE_DEC, VALS(x2ap_EventType_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_reportArea,
{ "reportArea", "x2ap.reportArea",
FT_UINT32, BASE_DEC, VALS(x2ap_ReportArea_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_reportInterval,
{ "reportInterval", "x2ap.reportInterval",
FT_UINT32, BASE_DEC, VALS(x2ap_ReportIntervalMDT_vals), 0,
"ReportIntervalMDT", HFILL }},
{ &hf_x2ap_reportAmount,
{ "reportAmount", "x2ap.reportAmount",
FT_UINT32, BASE_DEC, VALS(x2ap_ReportAmountMDT_vals), 0,
"ReportAmountMDT", HFILL }},
{ &hf_x2ap_measurementThreshold,
{ "measurementThreshold", "x2ap.measurementThreshold",
FT_UINT32, BASE_DEC, VALS(x2ap_MeasurementThresholdA2_vals), 0,
"MeasurementThresholdA2", HFILL }},
{ &hf_x2ap_m3period,
{ "m3period", "x2ap.m3period",
FT_UINT32, BASE_DEC, VALS(x2ap_M3period_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_m4period,
{ "m4period", "x2ap.m4period",
FT_UINT32, BASE_DEC, VALS(x2ap_M4period_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_m4_links_to_log,
{ "m4-links-to-log", "x2ap.m4_links_to_log",
FT_UINT32, BASE_DEC, VALS(x2ap_Links_to_log_vals), 0,
"Links_to_log", HFILL }},
{ &hf_x2ap_m5period,
{ "m5period", "x2ap.m5period",
FT_UINT32, BASE_DEC, VALS(x2ap_M5period_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_m5_links_to_log,
{ "m5-links-to-log", "x2ap.m5_links_to_log",
FT_UINT32, BASE_DEC, VALS(x2ap_Links_to_log_vals), 0,
"Links_to_log", HFILL }},
{ &hf_x2ap_m6report_interval,
{ "m6report-interval", "x2ap.m6report_interval",
FT_UINT32, BASE_DEC, VALS(x2ap_M6report_interval_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_m6delay_threshold,
{ "m6delay-threshold", "x2ap.m6delay_threshold",
FT_UINT32, BASE_DEC, VALS(x2ap_M6delay_threshold_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_m6_links_to_log,
{ "m6-links-to-log", "x2ap.m6_links_to_log",
FT_UINT32, BASE_DEC, VALS(x2ap_Links_to_log_vals), 0,
"Links_to_log", HFILL }},
{ &hf_x2ap_m7period,
{ "m7period", "x2ap.m7period",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_m7_links_to_log,
{ "m7-links-to-log", "x2ap.m7_links_to_log",
FT_UINT32, BASE_DEC, VALS(x2ap_Links_to_log_vals), 0,
"Links_to_log", HFILL }},
{ &hf_x2ap_mdt_Activation,
{ "mdt-Activation", "x2ap.mdt_Activation",
FT_UINT32, BASE_DEC, VALS(x2ap_MDT_Activation_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_areaScopeOfMDT,
{ "areaScopeOfMDT", "x2ap.areaScopeOfMDT",
FT_UINT32, BASE_DEC, VALS(x2ap_AreaScopeOfMDT_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_measurementsToActivate,
{ "measurementsToActivate", "x2ap.measurementsToActivate",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_m1reportingTrigger,
{ "m1reportingTrigger", "x2ap.m1reportingTrigger",
FT_UINT32, BASE_DEC, VALS(x2ap_M1ReportingTrigger_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_m1thresholdeventA2,
{ "m1thresholdeventA2", "x2ap.m1thresholdeventA2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_m1periodicReporting,
{ "m1periodicReporting", "x2ap.m1periodicReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MDTPLMNList_item,
{ "PLMN-Identity", "x2ap.PLMN_Identity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_threshold_RSRP,
{ "threshold-RSRP", "x2ap.threshold_RSRP",
FT_UINT32, BASE_CUSTOM, CF_FUNC(x2ap_Threshold_RSRP_fmt), 0,
NULL, HFILL }},
{ &hf_x2ap_threshold_RSRQ,
{ "threshold-RSRQ", "x2ap.threshold_RSRQ",
FT_UINT32, BASE_CUSTOM, CF_FUNC(x2ap_Threshold_RSRQ_fmt), 0,
NULL, HFILL }},
{ &hf_x2ap_MBMS_Service_Area_Identity_List_item,
{ "MBMS-Service-Area-Identity", "x2ap.MBMS_Service_Area_Identity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MBSFN_Subframe_Infolist_item,
{ "MBSFN-Subframe-Info", "x2ap.MBSFN_Subframe_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_radioframeAllocationPeriod,
{ "radioframeAllocationPeriod", "x2ap.radioframeAllocationPeriod",
FT_UINT32, BASE_DEC, VALS(x2ap_RadioframeAllocationPeriod_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_radioframeAllocationOffset,
{ "radioframeAllocationOffset", "x2ap.radioframeAllocationOffset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_subframeAllocation,
{ "subframeAllocation", "x2ap.subframeAllocation",
FT_UINT32, BASE_DEC, VALS(x2ap_SubframeAllocation_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_handoverTriggerChangeLowerLimit,
{ "handoverTriggerChangeLowerLimit", "x2ap.handoverTriggerChangeLowerLimit",
FT_INT32, BASE_CUSTOM, CF_FUNC(x2ap_handoverTriggerChange_fmt), 0,
"INTEGER_M20_20", HFILL }},
{ &hf_x2ap_handoverTriggerChangeUpperLimit,
{ "handoverTriggerChangeUpperLimit", "x2ap.handoverTriggerChangeUpperLimit",
FT_INT32, BASE_CUSTOM, CF_FUNC(x2ap_handoverTriggerChange_fmt), 0,
"INTEGER_M20_20", HFILL }},
{ &hf_x2ap_handoverTriggerChange,
{ "handoverTriggerChange", "x2ap.handoverTriggerChange",
FT_INT32, BASE_CUSTOM, CF_FUNC(x2ap_handoverTriggerChange_fmt), 0,
"INTEGER_M20_20", HFILL }},
{ &hf_x2ap_MultibandInfoList_item,
{ "BandInfo", "x2ap.BandInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_freqBandIndicator,
{ "freqBandIndicator", "x2ap.freqBandIndicator",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_Neighbour_Information_item,
{ "Neighbour-Information item", "x2ap.Neighbour_Information_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_pCI,
{ "pCI", "x2ap.pCI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_eARFCN,
{ "eARFCN", "x2ap.eARFCN",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_rootSequenceIndex,
{ "rootSequenceIndex", "x2ap.rootSequenceIndex",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_837", HFILL }},
{ &hf_x2ap_zeroCorrelationIndex,
{ "zeroCorrelationIndex", "x2ap.zeroCorrelationIndex",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_x2ap_highSpeedFlag,
{ "highSpeedFlag", "x2ap.highSpeedFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_x2ap_prach_FreqOffset,
{ "prach-FreqOffset", "x2ap.prach_FreqOffset",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_94", HFILL }},
{ &hf_x2ap_prach_ConfigIndex,
{ "prach-ConfigIndex", "x2ap.prach_ConfigIndex",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_x2ap_proSeDirectDiscovery,
{ "proSeDirectDiscovery", "x2ap.proSeDirectDiscovery",
FT_UINT32, BASE_DEC, VALS(x2ap_ProSeDirectDiscovery_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_proSeDirectCommunication,
{ "proSeDirectCommunication", "x2ap.proSeDirectCommunication",
FT_UINT32, BASE_DEC, VALS(x2ap_ProSeDirectCommunication_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_dL_GBR_PRB_usage,
{ "dL-GBR-PRB-usage", "x2ap.dL_GBR_PRB_usage",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uL_GBR_PRB_usage,
{ "uL-GBR-PRB-usage", "x2ap.uL_GBR_PRB_usage",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_dL_non_GBR_PRB_usage,
{ "dL-non-GBR-PRB-usage", "x2ap.dL_non_GBR_PRB_usage",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uL_non_GBR_PRB_usage,
{ "uL-non-GBR-PRB-usage", "x2ap.uL_non_GBR_PRB_usage",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_dL_Total_PRB_usage,
{ "dL-Total-PRB-usage", "x2ap.dL_Total_PRB_usage",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uL_Total_PRB_usage,
{ "uL-Total-PRB-usage", "x2ap.uL_Total_PRB_usage",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_rNTP_PerPRB,
{ "rNTP-PerPRB", "x2ap.rNTP_PerPRB",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_6_110_", HFILL }},
{ &hf_x2ap_rNTP_Threshold,
{ "rNTP-Threshold", "x2ap.rNTP_Threshold",
FT_UINT32, BASE_DEC, VALS(x2ap_RNTP_Threshold_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_numberOfCellSpecificAntennaPorts_02,
{ "numberOfCellSpecificAntennaPorts", "x2ap.numberOfCellSpecificAntennaPorts",
FT_UINT32, BASE_DEC, VALS(x2ap_T_numberOfCellSpecificAntennaPorts_02_vals), 0,
"T_numberOfCellSpecificAntennaPorts_02", HFILL }},
{ &hf_x2ap_p_B,
{ "p-B", "x2ap.p_B",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3_", HFILL }},
{ &hf_x2ap_pDCCH_InterferenceImpact,
{ "pDCCH-InterferenceImpact", "x2ap.pDCCH_InterferenceImpact",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4_", HFILL }},
{ &hf_x2ap_ReplacingCellsList_item,
{ "ReplacingCellsList-Item", "x2ap.ReplacingCellsList_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_non_truncated,
{ "non-truncated", "x2ap.non_truncated",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_40", HFILL }},
{ &hf_x2ap_truncated,
{ "truncated", "x2ap.truncated",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_24", HFILL }},
{ &hf_x2ap_RSRPMeasurementResult_item,
{ "RSRPMeasurementResult item", "x2ap.RSRPMeasurementResult_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_rSRPCellID,
{ "rSRPCellID", "x2ap.rSRPCellID_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_x2ap_rSRPMeasured,
{ "rSRPMeasured", "x2ap.rSRPMeasured",
FT_UINT32, BASE_CUSTOM, CF_FUNC(x2ap_Threshold_RSRP_fmt), 0,
"INTEGER_0_97_", HFILL }},
{ &hf_x2ap_RSRPMRList_item,
{ "RSRPMRList item", "x2ap.RSRPMRList_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_rSRPMeasurementResult,
{ "rSRPMeasurementResult", "x2ap.rSRPMeasurementResult",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_dLS1TNLLoadIndicator,
{ "dLS1TNLLoadIndicator", "x2ap.dLS1TNLLoadIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_LoadIndicator_vals), 0,
"LoadIndicator", HFILL }},
{ &hf_x2ap_uLS1TNLLoadIndicator,
{ "uLS1TNLLoadIndicator", "x2ap.uLS1TNLLoadIndicator",
FT_UINT32, BASE_DEC, VALS(x2ap_LoadIndicator_vals), 0,
"LoadIndicator", HFILL }},
{ &hf_x2ap_ServedCells_item,
{ "ServedCells item", "x2ap.ServedCells_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_servedCellInfo,
{ "servedCellInfo", "x2ap.servedCellInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"ServedCell_Information", HFILL }},
{ &hf_x2ap_neighbour_Info,
{ "neighbour-Info", "x2ap.neighbour_Info",
FT_UINT32, BASE_DEC, NULL, 0,
"Neighbour_Information", HFILL }},
{ &hf_x2ap_cellId,
{ "cellId", "x2ap.cellId_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_x2ap_tAC,
{ "tAC", "x2ap.tAC",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_broadcastPLMNs,
{ "broadcastPLMNs", "x2ap.broadcastPLMNs",
FT_UINT32, BASE_DEC, NULL, 0,
"BroadcastPLMNs_Item", HFILL }},
{ &hf_x2ap_eUTRA_Mode_Info,
{ "eUTRA-Mode-Info", "x2ap.eUTRA_Mode_Info",
FT_UINT32, BASE_DEC, VALS(x2ap_EUTRA_Mode_Info_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_specialSubframePatterns,
{ "specialSubframePatterns", "x2ap.specialSubframePatterns",
FT_UINT32, BASE_DEC, VALS(x2ap_SpecialSubframePatterns_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_subbandCQICodeword0,
{ "subbandCQICodeword0", "x2ap.subbandCQICodeword0",
FT_UINT32, BASE_DEC, VALS(x2ap_SubbandCQICodeword0_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_subbandCQICodeword1,
{ "subbandCQICodeword1", "x2ap.subbandCQICodeword1",
FT_UINT32, BASE_DEC, VALS(x2ap_SubbandCQICodeword1_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_four_bitCQI,
{ "four-bitCQI", "x2ap.four_bitCQI",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15_", HFILL }},
{ &hf_x2ap_two_bitSubbandDifferentialCQI,
{ "two-bitSubbandDifferentialCQI", "x2ap.two_bitSubbandDifferentialCQI",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3_", HFILL }},
{ &hf_x2ap_two_bitDifferentialCQI,
{ "two-bitDifferentialCQI", "x2ap.two_bitDifferentialCQI",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3_", HFILL }},
{ &hf_x2ap_three_bitSpatialDifferentialCQI,
{ "three-bitSpatialDifferentialCQI", "x2ap.three_bitSpatialDifferentialCQI",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7_", HFILL }},
{ &hf_x2ap_SubbandCQIList_item,
{ "SubbandCQIItem", "x2ap.SubbandCQIItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_subbandCQI,
{ "subbandCQI", "x2ap.subbandCQI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_subbandIndex,
{ "subbandIndex", "x2ap.subbandIndex",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_27_", HFILL }},
{ &hf_x2ap_oneframe,
{ "oneframe", "x2ap.oneframe",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_fourframes,
{ "fourframes", "x2ap.fourframes",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_tAListforMDT,
{ "tAListforMDT", "x2ap.tAListforMDT",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_tAIListforMDT,
{ "tAIListforMDT", "x2ap.tAIListforMDT",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_TAIListforMDT_item,
{ "TAI-Item", "x2ap.TAI_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_TAListforMDT_item,
{ "TAC", "x2ap.TAC",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_transmission_Bandwidth,
{ "transmission-Bandwidth", "x2ap.transmission_Bandwidth",
FT_UINT32, BASE_DEC, VALS(x2ap_Transmission_Bandwidth_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_subframeAssignment,
{ "subframeAssignment", "x2ap.subframeAssignment",
FT_UINT32, BASE_DEC, VALS(x2ap_SubframeAssignment_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_specialSubframe_Info,
{ "specialSubframe-Info", "x2ap.specialSubframe_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_eUTRANTraceID,
{ "eUTRANTraceID", "x2ap.eUTRANTraceID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_interfacesToTrace,
{ "interfacesToTrace", "x2ap.interfacesToTrace",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_traceDepth,
{ "traceDepth", "x2ap.traceDepth",
FT_UINT32, BASE_DEC, VALS(x2ap_TraceDepth_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_traceCollectionEntityIPAddress,
{ "traceCollectionEntityIPAddress", "x2ap.traceCollectionEntityIPAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uDP_Port_Number,
{ "uDP-Port-Number", "x2ap.uDP_Port_Number",
FT_UINT16, BASE_DEC, NULL, 0,
"Port_Number", HFILL }},
{ &hf_x2ap_uEaggregateMaximumBitRateDownlink,
{ "uEaggregateMaximumBitRateDownlink", "x2ap.uEaggregateMaximumBitRateDownlink",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
"BitRate", HFILL }},
{ &hf_x2ap_uEaggregateMaximumBitRateUplink,
{ "uEaggregateMaximumBitRateUplink", "x2ap.uEaggregateMaximumBitRateUplink",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
"BitRate", HFILL }},
{ &hf_x2ap_UE_HistoryInformation_item,
{ "LastVisitedCell-Item", "x2ap.LastVisitedCell_Item",
FT_UINT32, BASE_DEC, VALS(x2ap_LastVisitedCell_Item_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_encryptionAlgorithms,
{ "encryptionAlgorithms", "x2ap.encryptionAlgorithms",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_integrityProtectionAlgorithms,
{ "integrityProtectionAlgorithms", "x2ap.integrityProtectionAlgorithms",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_UL_HighInterferenceIndicationInfo_item,
{ "UL-HighInterferenceIndicationInfo-Item", "x2ap.UL_HighInterferenceIndicationInfo_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_target_Cell_ID,
{ "target-Cell-ID", "x2ap.target_Cell_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_x2ap_ul_interferenceindication,
{ "ul-interferenceindication", "x2ap.ul_interferenceindication",
FT_BYTES, BASE_NONE, NULL, 0,
"UL_HighInterferenceIndication", HFILL }},
{ &hf_x2ap_UL_InterferenceOverloadIndication_item,
{ "UL-InterferenceOverloadIndication-Item", "x2ap.UL_InterferenceOverloadIndication_Item",
FT_UINT32, BASE_DEC, VALS(x2ap_UL_InterferenceOverloadIndication_Item_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_fdd_01,
{ "fdd", "x2ap.fdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"UsableABSInformationFDD", HFILL }},
{ &hf_x2ap_tdd_01,
{ "tdd", "x2ap.tdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"UsableABSInformationTDD", HFILL }},
{ &hf_x2ap_usable_abs_pattern_info,
{ "usable-abs-pattern-info", "x2ap.usable_abs_pattern_info",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_40", HFILL }},
{ &hf_x2ap_usaable_abs_pattern_info,
{ "usaable-abs-pattern-info", "x2ap.usaable_abs_pattern_info",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_1_70_", HFILL }},
{ &hf_x2ap_widebandCQICodeword0,
{ "widebandCQICodeword0", "x2ap.widebandCQICodeword0",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15_", HFILL }},
{ &hf_x2ap_widebandCQICodeword1,
{ "widebandCQICodeword1", "x2ap.widebandCQICodeword1",
FT_UINT32, BASE_DEC, VALS(x2ap_WidebandCQICodeword1_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_protocolIEs,
{ "protocolIEs", "x2ap.protocolIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolIE_Container", HFILL }},
{ &hf_x2ap_mME_UE_S1AP_ID,
{ "mME-UE-S1AP-ID", "x2ap.mME_UE_S1AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
"UE_S1AP_ID", HFILL }},
{ &hf_x2ap_uESecurityCapabilities,
{ "uESecurityCapabilities", "x2ap.uESecurityCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_aS_SecurityInformation,
{ "aS-SecurityInformation", "x2ap.aS_SecurityInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uEaggregateMaximumBitRate,
{ "uEaggregateMaximumBitRate", "x2ap.uEaggregateMaximumBitRate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_subscriberProfileIDforRFP,
{ "subscriberProfileIDforRFP", "x2ap.subscriberProfileIDforRFP",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_e_RABs_ToBeSetup_List,
{ "e-RABs-ToBeSetup-List", "x2ap.e_RABs_ToBeSetup_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_rRC_Context,
{ "rRC-Context", "x2ap.rRC_Context",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_handoverRestrictionList,
{ "handoverRestrictionList", "x2ap.handoverRestrictionList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_locationReportingInformation,
{ "locationReportingInformation", "x2ap.locationReportingInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeSetup_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_e_RAB_Level_QoS_Parameters,
{ "e-RAB-Level-QoS-Parameters", "x2ap.e_RAB_Level_QoS_Parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_dL_Forwarding,
{ "dL-Forwarding", "x2ap.dL_Forwarding",
FT_UINT32, BASE_DEC, VALS(x2ap_DL_Forwarding_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_uL_GTPtunnelEndpoint,
{ "uL-GTPtunnelEndpoint", "x2ap.uL_GTPtunnelEndpoint_element",
FT_NONE, BASE_NONE, NULL, 0,
"GTPtunnelEndpoint", HFILL }},
{ &hf_x2ap_source_GlobalSeNB_ID,
{ "source-GlobalSeNB-ID", "x2ap.source_GlobalSeNB_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
"GlobalENB_ID", HFILL }},
{ &hf_x2ap_seNB_UE_X2AP_ID,
{ "seNB-UE-X2AP-ID", "x2ap.seNB_UE_X2AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
"UE_X2AP_ID", HFILL }},
{ &hf_x2ap_seNB_UE_X2AP_ID_Extension,
{ "seNB-UE-X2AP-ID-Extension", "x2ap.seNB_UE_X2AP_ID_Extension",
FT_UINT32, BASE_DEC, NULL, 0,
"UE_X2AP_ID_Extension", HFILL }},
{ &hf_x2ap_E_RABs_Admitted_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uL_GTP_TunnelEndpoint,
{ "uL-GTP-TunnelEndpoint", "x2ap.uL_GTP_TunnelEndpoint_element",
FT_NONE, BASE_NONE, NULL, 0,
"GTPtunnelEndpoint", HFILL }},
{ &hf_x2ap_dL_GTP_TunnelEndpoint,
{ "dL-GTP-TunnelEndpoint", "x2ap.dL_GTP_TunnelEndpoint_element",
FT_NONE, BASE_NONE, NULL, 0,
"GTPtunnelEndpoint", HFILL }},
{ &hf_x2ap_E_RABs_SubjectToStatusTransfer_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_receiveStatusofULPDCPSDUs,
{ "receiveStatusofULPDCPSDUs", "x2ap.receiveStatusofULPDCPSDUs",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uL_COUNTvalue,
{ "uL-COUNTvalue", "x2ap.uL_COUNTvalue_element",
FT_NONE, BASE_NONE, NULL, 0,
"COUNTvalue", HFILL }},
{ &hf_x2ap_dL_COUNTvalue,
{ "dL-COUNTvalue", "x2ap.dL_COUNTvalue_element",
FT_NONE, BASE_NONE, NULL, 0,
"COUNTvalue", HFILL }},
{ &hf_x2ap_CellInformation_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_cell_ID,
{ "cell-ID", "x2ap.cell_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_x2ap_ul_InterferenceOverloadIndication,
{ "ul-InterferenceOverloadIndication", "x2ap.ul_InterferenceOverloadIndication",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ul_HighInterferenceIndicationInfo,
{ "ul-HighInterferenceIndicationInfo", "x2ap.ul_HighInterferenceIndicationInfo",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_relativeNarrowbandTxPower,
{ "relativeNarrowbandTxPower", "x2ap.relativeNarrowbandTxPower_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ServedCellsToModify_item,
{ "ServedCellsToModify-Item", "x2ap.ServedCellsToModify_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_old_ecgi,
{ "old-ecgi", "x2ap.old_ecgi_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_x2ap_Old_ECGIs_item,
{ "ECGI", "x2ap.ECGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellToReport_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MeasurementInitiationResult_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_measurementFailureCause_List,
{ "measurementFailureCause-List", "x2ap.measurementFailureCause_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_MeasurementFailureCause_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_measurementFailedReportCharacteristics,
{ "measurementFailedReportCharacteristics", "x2ap.measurementFailedReportCharacteristics",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CompleteFailureCauseInformation_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_CellMeasurementResult_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_hWLoadIndicator,
{ "hWLoadIndicator", "x2ap.hWLoadIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_s1TNLLoadIndicator,
{ "s1TNLLoadIndicator", "x2ap.s1TNLLoadIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_radioResourceStatus,
{ "radioResourceStatus", "x2ap.radioResourceStatus_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_privateIEs,
{ "privateIEs", "x2ap.privateIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"PrivateIE_Container", HFILL }},
{ &hf_x2ap_ServedCellsToActivate_item,
{ "ServedCellsToActivate-Item", "x2ap.ServedCellsToActivate_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ecgi,
{ "ecgi", "x2ap.ecgi_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_ActivatedCellList_item,
{ "ActivatedCellList-Item", "x2ap.ActivatedCellList_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_source_GlobalENB_ID,
{ "source-GlobalENB-ID", "x2ap.source_GlobalENB_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
"GlobalENB_ID", HFILL }},
{ &hf_x2ap_target_GlobalENB_ID,
{ "target-GlobalENB-ID", "x2ap.target_GlobalENB_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
"GlobalENB_ID", HFILL }},
{ &hf_x2ap_E_RABs_ToBeAdded_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_sCG_Bearer,
{ "sCG-Bearer", "x2ap.sCG_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_ToBeAdded_Item_SCG_Bearer", HFILL }},
{ &hf_x2ap_split_Bearer,
{ "split-Bearer", "x2ap.split_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_ToBeAdded_Item_Split_Bearer", HFILL }},
{ &hf_x2ap_s1_UL_GTPtunnelEndpoint,
{ "s1-UL-GTPtunnelEndpoint", "x2ap.s1_UL_GTPtunnelEndpoint_element",
FT_NONE, BASE_NONE, NULL, 0,
"GTPtunnelEndpoint", HFILL }},
{ &hf_x2ap_meNB_GTPtunnelEndpoint,
{ "meNB-GTPtunnelEndpoint", "x2ap.meNB_GTPtunnelEndpoint_element",
FT_NONE, BASE_NONE, NULL, 0,
"GTPtunnelEndpoint", HFILL }},
{ &hf_x2ap_E_RABs_Admitted_ToBeAdded_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_sCG_Bearer_01,
{ "sCG-Bearer", "x2ap.sCG_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_Admitted_ToBeAdded_Item_SCG_Bearer", HFILL }},
{ &hf_x2ap_split_Bearer_01,
{ "split-Bearer", "x2ap.split_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_Admitted_ToBeAdded_Item_Split_Bearer", HFILL }},
{ &hf_x2ap_s1_DL_GTPtunnelEndpoint,
{ "s1-DL-GTPtunnelEndpoint", "x2ap.s1_DL_GTPtunnelEndpoint_element",
FT_NONE, BASE_NONE, NULL, 0,
"GTPtunnelEndpoint", HFILL }},
{ &hf_x2ap_dL_Forwarding_GTPtunnelEndpoint,
{ "dL-Forwarding-GTPtunnelEndpoint", "x2ap.dL_Forwarding_GTPtunnelEndpoint_element",
FT_NONE, BASE_NONE, NULL, 0,
"GTPtunnelEndpoint", HFILL }},
{ &hf_x2ap_uL_Forwarding_GTPtunnelEndpoint,
{ "uL-Forwarding-GTPtunnelEndpoint", "x2ap.uL_Forwarding_GTPtunnelEndpoint_element",
FT_NONE, BASE_NONE, NULL, 0,
"GTPtunnelEndpoint", HFILL }},
{ &hf_x2ap_seNB_GTPtunnelEndpoint,
{ "seNB-GTPtunnelEndpoint", "x2ap.seNB_GTPtunnelEndpoint_element",
FT_NONE, BASE_NONE, NULL, 0,
"GTPtunnelEndpoint", HFILL }},
{ &hf_x2ap_success,
{ "success", "x2ap.success_element",
FT_NONE, BASE_NONE, NULL, 0,
"ResponseInformationSeNBReconfComp_SuccessItem", HFILL }},
{ &hf_x2ap_reject_by_MeNB,
{ "reject-by-MeNB", "x2ap.reject_by_MeNB_element",
FT_NONE, BASE_NONE, NULL, 0,
"ResponseInformationSeNBReconfComp_RejectByMeNBItem", HFILL }},
{ &hf_x2ap_meNBtoSeNBContainer,
{ "meNBtoSeNBContainer", "x2ap.meNBtoSeNBContainer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uE_SecurityCapabilities,
{ "uE-SecurityCapabilities", "x2ap.uE_SecurityCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
"UESecurityCapabilities", HFILL }},
{ &hf_x2ap_seNB_SecurityKey,
{ "seNB-SecurityKey", "x2ap.seNB_SecurityKey",
FT_BYTES, BASE_NONE, NULL, 0,
"SeNBSecurityKey", HFILL }},
{ &hf_x2ap_seNBUEAggregateMaximumBitRate,
{ "seNBUEAggregateMaximumBitRate", "x2ap.seNBUEAggregateMaximumBitRate_element",
FT_NONE, BASE_NONE, NULL, 0,
"UEAggregateMaximumBitRate", HFILL }},
{ &hf_x2ap_e_RABs_ToBeAdded,
{ "e-RABs-ToBeAdded", "x2ap.e_RABs_ToBeAdded",
FT_UINT32, BASE_DEC, NULL, 0,
"E_RABs_ToBeAdded_List_ModReq", HFILL }},
{ &hf_x2ap_e_RABs_ToBeModified,
{ "e-RABs-ToBeModified", "x2ap.e_RABs_ToBeModified",
FT_UINT32, BASE_DEC, NULL, 0,
"E_RABs_ToBeModified_List_ModReq", HFILL }},
{ &hf_x2ap_e_RABs_ToBeReleased,
{ "e-RABs-ToBeReleased", "x2ap.e_RABs_ToBeReleased",
FT_UINT32, BASE_DEC, NULL, 0,
"E_RABs_ToBeReleased_List_ModReq", HFILL }},
{ &hf_x2ap_E_RABs_ToBeAdded_List_ModReq_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_sCG_Bearer_02,
{ "sCG-Bearer", "x2ap.sCG_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_ToBeAdded_ModReqItem_SCG_Bearer", HFILL }},
{ &hf_x2ap_split_Bearer_02,
{ "split-Bearer", "x2ap.split_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_ToBeAdded_ModReqItem_Split_Bearer", HFILL }},
{ &hf_x2ap_E_RABs_ToBeModified_List_ModReq_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_sCG_Bearer_03,
{ "sCG-Bearer", "x2ap.sCG_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_ToBeModified_ModReqItem_SCG_Bearer", HFILL }},
{ &hf_x2ap_split_Bearer_03,
{ "split-Bearer", "x2ap.split_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_ToBeModified_ModReqItem_Split_Bearer", HFILL }},
{ &hf_x2ap_E_RABs_ToBeReleased_List_ModReq_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_sCG_Bearer_04,
{ "sCG-Bearer", "x2ap.sCG_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_ToBeReleased_ModReqItem_SCG_Bearer", HFILL }},
{ &hf_x2ap_split_Bearer_04,
{ "split-Bearer", "x2ap.split_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_ToBeReleased_ModReqItem_Split_Bearer", HFILL }},
{ &hf_x2ap_dL_GTPtunnelEndpoint,
{ "dL-GTPtunnelEndpoint", "x2ap.dL_GTPtunnelEndpoint_element",
FT_NONE, BASE_NONE, NULL, 0,
"GTPtunnelEndpoint", HFILL }},
{ &hf_x2ap_E_RABs_Admitted_ToBeAdded_ModAckList_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_sCG_Bearer_05,
{ "sCG-Bearer", "x2ap.sCG_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_Admitted_ToBeAdded_ModAckItem_SCG_Bearer", HFILL }},
{ &hf_x2ap_split_Bearer_05,
{ "split-Bearer", "x2ap.split_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_Admitted_ToBeAdded_ModAckItem_Split_Bearer", HFILL }},
{ &hf_x2ap_E_RABs_Admitted_ToBeModified_ModAckList_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_sCG_Bearer_06,
{ "sCG-Bearer", "x2ap.sCG_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_Admitted_ToBeModified_ModAckItem_SCG_Bearer", HFILL }},
{ &hf_x2ap_split_Bearer_06,
{ "split-Bearer", "x2ap.split_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_Admitted_ToBeModified_ModAckItem_Split_Bearer", HFILL }},
{ &hf_x2ap_E_RABs_Admitted_ToBeReleased_ModAckList_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_sCG_Bearer_07,
{ "sCG-Bearer", "x2ap.sCG_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_Admitted_ToBeReleased_ModAckItem_SCG_Bearer", HFILL }},
{ &hf_x2ap_split_Bearer_07,
{ "split-Bearer", "x2ap.split_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_Admitted_ToBeReleased_ModAckItem_Split_Bearer", HFILL }},
{ &hf_x2ap_E_RABs_ToBeReleased_ModReqd_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_E_RABs_ToBeReleased_List_RelReq_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_sCG_Bearer_08,
{ "sCG-Bearer", "x2ap.sCG_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_ToBeReleased_RelReqItem_SCG_Bearer", HFILL }},
{ &hf_x2ap_split_Bearer_08,
{ "split-Bearer", "x2ap.split_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_ToBeReleased_RelReqItem_Split_Bearer", HFILL }},
{ &hf_x2ap_E_RABs_ToBeReleased_List_RelConf_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_sCG_Bearer_09,
{ "sCG-Bearer", "x2ap.sCG_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_ToBeReleased_RelConfItem_SCG_Bearer", HFILL }},
{ &hf_x2ap_split_Bearer_09,
{ "split-Bearer", "x2ap.split_Bearer_element",
FT_NONE, BASE_NONE, NULL, 0,
"E_RABs_ToBeReleased_RelConfItem_Split_Bearer", HFILL }},
{ &hf_x2ap_E_RABs_SubjectToCounterCheck_List_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_uL_Count,
{ "uL-Count", "x2ap.uL_Count",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_x2ap_dL_Count,
{ "dL-Count", "x2ap.dL_Count",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_x2ap_e_RABs_ToBeSetup_ListRetrieve,
{ "e-RABs-ToBeSetup-ListRetrieve", "x2ap.e_RABs_ToBeSetup_ListRetrieve",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_managBasedMDTallowed,
{ "managBasedMDTallowed", "x2ap.managBasedMDTallowed",
FT_UINT32, BASE_DEC, VALS(x2ap_ManagementBasedMDTallowed_vals), 0,
"ManagementBasedMDTallowed", HFILL }},
{ &hf_x2ap_managBasedMDTPLMNList,
{ "managBasedMDTPLMNList", "x2ap.managBasedMDTPLMNList",
FT_UINT32, BASE_DEC, NULL, 0,
"MDTPLMNList", HFILL }},
{ &hf_x2ap_E_RABs_ToBeSetup_ListRetrieve_item,
{ "ProtocolIE-Single-Container", "x2ap.ProtocolIE_Single_Container_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_bearerType,
{ "bearerType", "x2ap.bearerType",
FT_UINT32, BASE_DEC, VALS(x2ap_BearerType_vals), 0,
NULL, HFILL }},
{ &hf_x2ap_initiatingMessage,
{ "initiatingMessage", "x2ap.initiatingMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_successfulOutcome,
{ "successfulOutcome", "x2ap.successfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_unsuccessfulOutcome,
{ "unsuccessfulOutcome", "x2ap.unsuccessfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_initiatingMessage_value,
{ "value", "x2ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitiatingMessage_value", HFILL }},
{ &hf_x2ap_successfulOutcome_value,
{ "value", "x2ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"SuccessfulOutcome_value", HFILL }},
{ &hf_x2ap_value,
{ "value", "x2ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnsuccessfulOutcome_value", HFILL }},
#line 501 "./asn1/x2ap/packet-x2ap-template.c"
};
static gint *ett[] = {
&ett_x2ap,
&ett_x2ap_TransportLayerAddress,
&ett_x2ap_PLMN_Identity,
&ett_x2ap_TargeteNBtoSource_eNBTransparentContainer,
&ett_x2ap_RRC_Context,
&ett_x2ap_UE_HistoryInformationFromTheUE,
&ett_x2ap_ReportCharacteristics,
&ett_x2ap_measurementFailedReportCharacteristics,
&ett_x2ap_UE_RLF_Report_Container,
&ett_x2ap_UE_RLF_Report_Container_for_extended_bands,
&ett_x2ap_MeNBtoSeNBContainer,
&ett_x2ap_SeNBtoMeNBContainer,
&ett_x2ap_EUTRANTraceID,
&ett_x2ap_InterfacesToTrace,
&ett_x2ap_TraceCollectionEntityIPAddress,
&ett_x2ap_EncryptionAlgorithms,
&ett_x2ap_IntegrityProtectionAlgorithms,
&ett_x2ap_MeasurementsToActivate,
&ett_x2ap_MDT_Location_Info,
&ett_x2ap_transmissionModes,
&ett_x2ap_X2AP_Message,
#line 1 "./asn1/x2ap/packet-x2ap-ettarr.c"
&ett_x2ap_PrivateIE_ID,
&ett_x2ap_ProtocolIE_Container,
&ett_x2ap_ProtocolIE_Field,
&ett_x2ap_ProtocolExtensionContainer,
&ett_x2ap_ProtocolExtensionField,
&ett_x2ap_PrivateIE_Container,
&ett_x2ap_PrivateIE_Field,
&ett_x2ap_ABSInformation,
&ett_x2ap_ABSInformationFDD,
&ett_x2ap_ABSInformationTDD,
&ett_x2ap_ABS_Status,
&ett_x2ap_AdditionalSpecialSubframe_Info,
&ett_x2ap_AllocationAndRetentionPriority,
&ett_x2ap_AreaScopeOfMDT,
&ett_x2ap_AS_SecurityInformation,
&ett_x2ap_BroadcastPLMNs_Item,
&ett_x2ap_Cause,
&ett_x2ap_CellBasedMDT,
&ett_x2ap_CellIdListforMDT,
&ett_x2ap_CellReplacingInfo,
&ett_x2ap_CellType,
&ett_x2ap_CoMPHypothesisSet,
&ett_x2ap_CoMPHypothesisSetItem,
&ett_x2ap_CoMPInformation,
&ett_x2ap_CoMPInformationItem,
&ett_x2ap_CoMPInformationItem_item,
&ett_x2ap_CoMPInformationStartTime,
&ett_x2ap_CoMPInformationStartTime_item,
&ett_x2ap_CompositeAvailableCapacity,
&ett_x2ap_CompositeAvailableCapacityGroup,
&ett_x2ap_COUNTvalue,
&ett_x2ap_COUNTValueExtended,
&ett_x2ap_COUNTvaluePDCP_SNlength18,
&ett_x2ap_CoverageModificationList,
&ett_x2ap_CoverageModification_Item,
&ett_x2ap_CriticalityDiagnostics,
&ett_x2ap_CriticalityDiagnostics_IE_List,
&ett_x2ap_CriticalityDiagnostics_IE_List_item,
&ett_x2ap_CSIReportList,
&ett_x2ap_CSIReportList_item,
&ett_x2ap_CSIReportPerCSIProcess,
&ett_x2ap_CSIReportPerCSIProcess_item,
&ett_x2ap_CSIReportPerCSIProcessItem,
&ett_x2ap_CSIReportPerCSIProcessItem_item,
&ett_x2ap_DynamicDLTransmissionInformation,
&ett_x2ap_DynamicNAICSInformation,
&ett_x2ap_SEQUENCE_SIZE_0_maxnoofPA_OF_PA_Values,
&ett_x2ap_ECGI,
&ett_x2ap_EnhancedRNTP,
&ett_x2ap_EnhancedRNTPStartTime,
&ett_x2ap_ENB_ID,
&ett_x2ap_EPLMNs,
&ett_x2ap_E_RAB_Level_QoS_Parameters,
&ett_x2ap_E_RAB_List,
&ett_x2ap_E_RAB_Item,
&ett_x2ap_EUTRA_Mode_Info,
&ett_x2ap_ExpectedUEBehaviour,
&ett_x2ap_ExpectedUEActivityBehaviour,
&ett_x2ap_ExtendedULInterferenceOverloadInfo,
&ett_x2ap_FDD_Info,
&ett_x2ap_ForbiddenTAs,
&ett_x2ap_ForbiddenTAs_Item,
&ett_x2ap_ForbiddenTACs,
&ett_x2ap_ForbiddenLAs,
&ett_x2ap_ForbiddenLAs_Item,
&ett_x2ap_ForbiddenLACs,
&ett_x2ap_GBR_QosInformation,
&ett_x2ap_GlobalENB_ID,
&ett_x2ap_GTPtunnelEndpoint,
&ett_x2ap_GUGroupIDList,
&ett_x2ap_GU_Group_ID,
&ett_x2ap_GUMMEI,
&ett_x2ap_HandoverRestrictionList,
&ett_x2ap_HWLoadIndicator,
&ett_x2ap_LastVisitedCell_Item,
&ett_x2ap_LastVisitedEUTRANCellInformation,
&ett_x2ap_LastVisitedGERANCellInformation,
&ett_x2ap_LocationReportingInformation,
&ett_x2ap_M1PeriodicReporting,
&ett_x2ap_M1ThresholdEventA2,
&ett_x2ap_M3Configuration,
&ett_x2ap_M4Configuration,
&ett_x2ap_M5Configuration,
&ett_x2ap_M6Configuration,
&ett_x2ap_M7Configuration,
&ett_x2ap_MDT_Configuration,
&ett_x2ap_MDTPLMNList,
&ett_x2ap_MeasurementThresholdA2,
&ett_x2ap_MBMS_Service_Area_Identity_List,
&ett_x2ap_MBSFN_Subframe_Infolist,
&ett_x2ap_MBSFN_Subframe_Info,
&ett_x2ap_MobilityParametersModificationRange,
&ett_x2ap_MobilityParametersInformation,
&ett_x2ap_MultibandInfoList,
&ett_x2ap_BandInfo,
&ett_x2ap_Neighbour_Information,
&ett_x2ap_Neighbour_Information_item,
&ett_x2ap_PRACH_Configuration,
&ett_x2ap_ProSeAuthorized,
&ett_x2ap_RadioResourceStatus,
&ett_x2ap_RelativeNarrowbandTxPower,
&ett_x2ap_ReplacingCellsList,
&ett_x2ap_ReplacingCellsList_Item,
&ett_x2ap_ResumeID,
&ett_x2ap_RSRPMeasurementResult,
&ett_x2ap_RSRPMeasurementResult_item,
&ett_x2ap_RSRPMRList,
&ett_x2ap_RSRPMRList_item,
&ett_x2ap_S1TNLLoadIndicator,
&ett_x2ap_ServedCells,
&ett_x2ap_ServedCells_item,
&ett_x2ap_ServedCell_Information,
&ett_x2ap_SpecialSubframe_Info,
&ett_x2ap_SubbandCQI,
&ett_x2ap_SubbandCQICodeword0,
&ett_x2ap_SubbandCQICodeword1,
&ett_x2ap_SubbandCQIList,
&ett_x2ap_SubbandCQIItem,
&ett_x2ap_SubframeAllocation,
&ett_x2ap_TABasedMDT,
&ett_x2ap_TAIBasedMDT,
&ett_x2ap_TAIListforMDT,
&ett_x2ap_TAI_Item,
&ett_x2ap_TAListforMDT,
&ett_x2ap_TDD_Info,
&ett_x2ap_TraceActivation,
&ett_x2ap_TunnelInformation,
&ett_x2ap_UEAggregateMaximumBitRate,
&ett_x2ap_UE_HistoryInformation,
&ett_x2ap_UESecurityCapabilities,
&ett_x2ap_UL_HighInterferenceIndicationInfo,
&ett_x2ap_UL_HighInterferenceIndicationInfo_Item,
&ett_x2ap_UL_InterferenceOverloadIndication,
&ett_x2ap_UsableABSInformation,
&ett_x2ap_UsableABSInformationFDD,
&ett_x2ap_UsableABSInformationTDD,
&ett_x2ap_WidebandCQI,
&ett_x2ap_WidebandCQICodeword1,
&ett_x2ap_HandoverRequest,
&ett_x2ap_UE_ContextInformation,
&ett_x2ap_E_RABs_ToBeSetup_List,
&ett_x2ap_E_RABs_ToBeSetup_Item,
&ett_x2ap_UE_ContextReferenceAtSeNB,
&ett_x2ap_HandoverRequestAcknowledge,
&ett_x2ap_E_RABs_Admitted_List,
&ett_x2ap_E_RABs_Admitted_Item,
&ett_x2ap_HandoverPreparationFailure,
&ett_x2ap_HandoverReport,
&ett_x2ap_SNStatusTransfer,
&ett_x2ap_E_RABs_SubjectToStatusTransfer_List,
&ett_x2ap_E_RABs_SubjectToStatusTransfer_Item,
&ett_x2ap_UEContextRelease,
&ett_x2ap_HandoverCancel,
&ett_x2ap_ErrorIndication,
&ett_x2ap_ResetRequest,
&ett_x2ap_ResetResponse,
&ett_x2ap_X2SetupRequest,
&ett_x2ap_X2SetupResponse,
&ett_x2ap_X2SetupFailure,
&ett_x2ap_LoadInformation,
&ett_x2ap_CellInformation_List,
&ett_x2ap_CellInformation_Item,
&ett_x2ap_ENBConfigurationUpdate,
&ett_x2ap_ServedCellsToModify,
&ett_x2ap_ServedCellsToModify_Item,
&ett_x2ap_Old_ECGIs,
&ett_x2ap_ENBConfigurationUpdateAcknowledge,
&ett_x2ap_ENBConfigurationUpdateFailure,
&ett_x2ap_ResourceStatusRequest,
&ett_x2ap_CellToReport_List,
&ett_x2ap_CellToReport_Item,
&ett_x2ap_ResourceStatusResponse,
&ett_x2ap_MeasurementInitiationResult_List,
&ett_x2ap_MeasurementInitiationResult_Item,
&ett_x2ap_MeasurementFailureCause_List,
&ett_x2ap_MeasurementFailureCause_Item,
&ett_x2ap_ResourceStatusFailure,
&ett_x2ap_CompleteFailureCauseInformation_List,
&ett_x2ap_CompleteFailureCauseInformation_Item,
&ett_x2ap_ResourceStatusUpdate,
&ett_x2ap_CellMeasurementResult_List,
&ett_x2ap_CellMeasurementResult_Item,
&ett_x2ap_PrivateMessage,
&ett_x2ap_MobilityChangeRequest,
&ett_x2ap_MobilityChangeAcknowledge,
&ett_x2ap_MobilityChangeFailure,
&ett_x2ap_RLFIndication,
&ett_x2ap_CellActivationRequest,
&ett_x2ap_ServedCellsToActivate,
&ett_x2ap_ServedCellsToActivate_Item,
&ett_x2ap_CellActivationResponse,
&ett_x2ap_ActivatedCellList,
&ett_x2ap_ActivatedCellList_Item,
&ett_x2ap_CellActivationFailure,
&ett_x2ap_X2Release,
&ett_x2ap_X2APMessageTransfer,
&ett_x2ap_RNL_Header,
&ett_x2ap_SeNBAdditionRequest,
&ett_x2ap_E_RABs_ToBeAdded_List,
&ett_x2ap_E_RABs_ToBeAdded_Item,
&ett_x2ap_E_RABs_ToBeAdded_Item_SCG_Bearer,
&ett_x2ap_E_RABs_ToBeAdded_Item_Split_Bearer,
&ett_x2ap_SeNBAdditionRequestAcknowledge,
&ett_x2ap_E_RABs_Admitted_ToBeAdded_List,
&ett_x2ap_E_RABs_Admitted_ToBeAdded_Item,
&ett_x2ap_E_RABs_Admitted_ToBeAdded_Item_SCG_Bearer,
&ett_x2ap_E_RABs_Admitted_ToBeAdded_Item_Split_Bearer,
&ett_x2ap_SeNBAdditionRequestReject,
&ett_x2ap_SeNBReconfigurationComplete,
&ett_x2ap_ResponseInformationSeNBReconfComp,
&ett_x2ap_ResponseInformationSeNBReconfComp_SuccessItem,
&ett_x2ap_ResponseInformationSeNBReconfComp_RejectByMeNBItem,
&ett_x2ap_SeNBModificationRequest,
&ett_x2ap_UE_ContextInformationSeNBModReq,
&ett_x2ap_E_RABs_ToBeAdded_List_ModReq,
&ett_x2ap_E_RABs_ToBeAdded_ModReqItem,
&ett_x2ap_E_RABs_ToBeAdded_ModReqItem_SCG_Bearer,
&ett_x2ap_E_RABs_ToBeAdded_ModReqItem_Split_Bearer,
&ett_x2ap_E_RABs_ToBeModified_List_ModReq,
&ett_x2ap_E_RABs_ToBeModified_ModReqItem,
&ett_x2ap_E_RABs_ToBeModified_ModReqItem_SCG_Bearer,
&ett_x2ap_E_RABs_ToBeModified_ModReqItem_Split_Bearer,
&ett_x2ap_E_RABs_ToBeReleased_List_ModReq,
&ett_x2ap_E_RABs_ToBeReleased_ModReqItem,
&ett_x2ap_E_RABs_ToBeReleased_ModReqItem_SCG_Bearer,
&ett_x2ap_E_RABs_ToBeReleased_ModReqItem_Split_Bearer,
&ett_x2ap_SeNBModificationRequestAcknowledge,
&ett_x2ap_E_RABs_Admitted_ToBeAdded_ModAckList,
&ett_x2ap_E_RABs_Admitted_ToBeAdded_ModAckItem,
&ett_x2ap_E_RABs_Admitted_ToBeAdded_ModAckItem_SCG_Bearer,
&ett_x2ap_E_RABs_Admitted_ToBeAdded_ModAckItem_Split_Bearer,
&ett_x2ap_E_RABs_Admitted_ToBeModified_ModAckList,
&ett_x2ap_E_RABs_Admitted_ToBeModified_ModAckItem,
&ett_x2ap_E_RABs_Admitted_ToBeModified_ModAckItem_SCG_Bearer,
&ett_x2ap_E_RABs_Admitted_ToBeModified_ModAckItem_Split_Bearer,
&ett_x2ap_E_RABs_Admitted_ToBeReleased_ModAckList,
&ett_x2ap_E_RABs_Admitted_ToReleased_ModAckItem,
&ett_x2ap_E_RABs_Admitted_ToBeReleased_ModAckItem_SCG_Bearer,
&ett_x2ap_E_RABs_Admitted_ToBeReleased_ModAckItem_Split_Bearer,
&ett_x2ap_SeNBModificationRequestReject,
&ett_x2ap_SeNBModificationRequired,
&ett_x2ap_E_RABs_ToBeReleased_ModReqd,
&ett_x2ap_E_RABs_ToBeReleased_ModReqdItem,
&ett_x2ap_SeNBModificationConfirm,
&ett_x2ap_SeNBModificationRefuse,
&ett_x2ap_SeNBReleaseRequest,
&ett_x2ap_E_RABs_ToBeReleased_List_RelReq,
&ett_x2ap_E_RABs_ToBeReleased_RelReqItem,
&ett_x2ap_E_RABs_ToBeReleased_RelReqItem_SCG_Bearer,
&ett_x2ap_E_RABs_ToBeReleased_RelReqItem_Split_Bearer,
&ett_x2ap_SeNBReleaseRequired,
&ett_x2ap_SeNBReleaseConfirm,
&ett_x2ap_E_RABs_ToBeReleased_List_RelConf,
&ett_x2ap_E_RABs_ToBeReleased_RelConfItem,
&ett_x2ap_E_RABs_ToBeReleased_RelConfItem_SCG_Bearer,
&ett_x2ap_E_RABs_ToBeReleased_RelConfItem_Split_Bearer,
&ett_x2ap_SeNBCounterCheckRequest,
&ett_x2ap_E_RABs_SubjectToCounterCheck_List,
&ett_x2ap_E_RABs_SubjectToCounterCheckItem,
&ett_x2ap_X2RemovalRequest,
&ett_x2ap_X2RemovalResponse,
&ett_x2ap_X2RemovalFailure,
&ett_x2ap_RetrieveUEContextRequest,
&ett_x2ap_RetrieveUEContextResponse,
&ett_x2ap_UE_ContextInformationRetrieve,
&ett_x2ap_E_RABs_ToBeSetup_ListRetrieve,
&ett_x2ap_E_RABs_ToBeSetupRetrieve_Item,
&ett_x2ap_RetrieveUEContextFailure,
&ett_x2ap_X2AP_PDU,
&ett_x2ap_InitiatingMessage,
&ett_x2ap_SuccessfulOutcome,
&ett_x2ap_UnsuccessfulOutcome,
#line 527 "./asn1/x2ap/packet-x2ap-template.c"
};
module_t *x2ap_module;
proto_x2ap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_x2ap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
x2ap_handle = register_dissector("x2ap", dissect_x2ap, proto_x2ap);
x2ap_ies_dissector_table = register_dissector_table("x2ap.ies", "X2AP-PROTOCOL-IES", proto_x2ap, FT_UINT32, BASE_DEC);
x2ap_extension_dissector_table = register_dissector_table("x2ap.extension", "X2AP-PROTOCOL-EXTENSION", proto_x2ap, FT_UINT32, BASE_DEC);
x2ap_proc_imsg_dissector_table = register_dissector_table("x2ap.proc.imsg", "X2AP-ELEMENTARY-PROCEDURE InitiatingMessage", proto_x2ap, FT_UINT32, BASE_DEC);
x2ap_proc_sout_dissector_table = register_dissector_table("x2ap.proc.sout", "X2AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", proto_x2ap, FT_UINT32, BASE_DEC);
x2ap_proc_uout_dissector_table = register_dissector_table("x2ap.proc.uout", "X2AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", proto_x2ap, FT_UINT32, BASE_DEC);
x2ap_module = prefs_register_protocol(proto_x2ap, proto_reg_handoff_x2ap);
prefs_register_uint_preference(x2ap_module, "sctp.port",
"X2AP SCTP Port",
"Set the SCTP port for X2AP messages",
10,
&gbl_x2apSctpPort);
prefs_register_enum_preference(x2ap_module, "dissect_rrc_context_as", "Dissect RRC Context as",
"Select whether RRC Context should be dissected as legacy LTE or NB-IOT",
&g_x2ap_dissect_rrc_context_as, x2ap_rrc_context_vals, FALSE);
}
void
proto_reg_handoff_x2ap(void)
{
static gboolean Initialized=FALSE;
static guint SctpPort;
if (!Initialized) {
dissector_add_for_decode_as("sctp.port", x2ap_handle);
dissector_add_uint("sctp.ppi", X2AP_PAYLOAD_PROTOCOL_ID, x2ap_handle);
Initialized=TRUE;
#line 1 "./asn1/x2ap/packet-x2ap-dis-tab.c"
dissector_add_uint("x2ap.ies", id_E_RABs_Admitted_Item, create_dissector_handle(dissect_E_RABs_Admitted_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_Admitted_List, create_dissector_handle(dissect_E_RABs_Admitted_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RAB_Item, create_dissector_handle(dissect_E_RAB_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_NotAdmitted_List, create_dissector_handle(dissect_E_RAB_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_ToBeSetup_Item, create_dissector_handle(dissect_E_RABs_ToBeSetup_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_Cause, create_dissector_handle(dissect_Cause_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CellInformation, create_dissector_handle(dissect_CellInformation_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CellInformation_Item, create_dissector_handle(dissect_CellInformation_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_New_eNB_UE_X2AP_ID, create_dissector_handle(dissect_UE_X2AP_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_Old_eNB_UE_X2AP_ID, create_dissector_handle(dissect_UE_X2AP_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_TargetCell_ID, create_dissector_handle(dissect_ECGI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_TargeteNBtoSource_eNBTransparentContainer, create_dissector_handle(dissect_TargeteNBtoSource_eNBTransparentContainer_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_TraceActivation, create_dissector_handle(dissect_TraceActivation_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_UE_ContextInformation, create_dissector_handle(dissect_UE_ContextInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_UE_HistoryInformation, create_dissector_handle(dissect_UE_HistoryInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_UE_X2AP_ID, create_dissector_handle(dissect_UE_X2AP_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CriticalityDiagnostics, create_dissector_handle(dissect_CriticalityDiagnostics_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_SubjectToStatusTransfer_List, create_dissector_handle(dissect_E_RABs_SubjectToStatusTransfer_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_SubjectToStatusTransfer_Item, create_dissector_handle(dissect_E_RABs_SubjectToStatusTransfer_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ServedCells, create_dissector_handle(dissect_ServedCells_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_GlobalENB_ID, create_dissector_handle(dissect_GlobalENB_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_TimeToWait, create_dissector_handle(dissect_TimeToWait_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_GUMMEI_ID, create_dissector_handle(dissect_GUMMEI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_GUGroupIDList, create_dissector_handle(dissect_GUGroupIDList_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ServedCellsToAdd, create_dissector_handle(dissect_ServedCells_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ServedCellsToModify, create_dissector_handle(dissect_ServedCellsToModify_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ServedCellsToDelete, create_dissector_handle(dissect_Old_ECGIs_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_Registration_Request, create_dissector_handle(dissect_Registration_Request_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CellToReport, create_dissector_handle(dissect_CellToReport_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ReportingPeriodicity, create_dissector_handle(dissect_ReportingPeriodicity_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CellToReport_Item, create_dissector_handle(dissect_CellToReport_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CellMeasurementResult, create_dissector_handle(dissect_CellMeasurementResult_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CellMeasurementResult_Item, create_dissector_handle(dissect_CellMeasurementResult_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_GUGroupIDToAddList, create_dissector_handle(dissect_GUGroupIDList_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_GUGroupIDToDeleteList, create_dissector_handle(dissect_GUGroupIDList_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_SRVCCOperationPossible, create_dissector_handle(dissect_SRVCCOperationPossible_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ReportCharacteristics, create_dissector_handle(dissect_ReportCharacteristics_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ENB1_Measurement_ID, create_dissector_handle(dissect_Measurement_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ENB2_Measurement_ID, create_dissector_handle(dissect_Measurement_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ENB1_Cell_ID, create_dissector_handle(dissect_ECGI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ENB2_Cell_ID, create_dissector_handle(dissect_ECGI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ENB2_Proposed_Mobility_Parameters, create_dissector_handle(dissect_MobilityParametersInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ENB1_Mobility_Parameters, create_dissector_handle(dissect_MobilityParametersInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ENB2_Mobility_Parameters_Modification_Range, create_dissector_handle(dissect_MobilityParametersModificationRange_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_FailureCellPCI, create_dissector_handle(dissect_PCI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_Re_establishmentCellECGI, create_dissector_handle(dissect_ECGI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_FailureCellCRNTI, create_dissector_handle(dissect_CRNTI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ShortMAC_I, create_dissector_handle(dissect_ShortMAC_I_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_SourceCellECGI, create_dissector_handle(dissect_ECGI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_FailureCellECGI, create_dissector_handle(dissect_ECGI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_HandoverReportType, create_dissector_handle(dissect_HandoverReportType_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_UE_RLF_Report_Container, create_dissector_handle(dissect_UE_RLF_Report_Container_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ServedCellsToActivate, create_dissector_handle(dissect_ServedCellsToActivate_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ActivatedCellList, create_dissector_handle(dissect_ActivatedCellList_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_PartialSuccessIndicator, create_dissector_handle(dissect_PartialSuccessIndicator_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_MeasurementInitiationResult_List, create_dissector_handle(dissect_MeasurementInitiationResult_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_MeasurementInitiationResult_Item, create_dissector_handle(dissect_MeasurementInitiationResult_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_MeasurementFailureCause_Item, create_dissector_handle(dissect_MeasurementFailureCause_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CompleteFailureCauseInformation_List, create_dissector_handle(dissect_CompleteFailureCauseInformation_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CompleteFailureCauseInformation_Item, create_dissector_handle(dissect_CompleteFailureCauseInformation_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CSGMembershipStatus, create_dissector_handle(dissect_CSGMembershipStatus_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_RRCConnSetupIndicator, create_dissector_handle(dissect_RRCConnSetupIndicator_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_RRCConnReestabIndicator, create_dissector_handle(dissect_RRCConnReestabIndicator_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_TargetCellInUTRAN, create_dissector_handle(dissect_TargetCellInUTRAN_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_MobilityInformation, create_dissector_handle(dissect_MobilityInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_SourceCellCRNTI, create_dissector_handle(dissect_CRNTI_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_Masked_IMEISV, create_dissector_handle(dissect_Masked_IMEISV_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_RNL_Header, create_dissector_handle(dissect_RNL_Header_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_x2APMessage, create_dissector_handle(dissect_X2AP_Message_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ProSeAuthorized, create_dissector_handle(dissect_ProSeAuthorized_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ExpectedUEBehaviour, create_dissector_handle(dissect_ExpectedUEBehaviour_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_UE_HistoryInformationFromTheUE, create_dissector_handle(dissect_UE_HistoryInformationFromTheUE_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_UE_RLF_Report_Container_for_extended_bands, create_dissector_handle(dissect_UE_RLF_Report_Container_for_extended_bands_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ReportingPeriodicityRSRPMR, create_dissector_handle(dissect_ReportingPeriodicityRSRPMR_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_MeNB_UE_X2AP_ID, create_dissector_handle(dissect_UE_X2AP_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_SeNB_UE_X2AP_ID, create_dissector_handle(dissect_UE_X2AP_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_UE_SecurityCapabilities, create_dissector_handle(dissect_UESecurityCapabilities_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_SeNBSecurityKey, create_dissector_handle(dissect_SeNBSecurityKey_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_SeNBUEAggregateMaximumBitRate, create_dissector_handle(dissect_UEAggregateMaximumBitRate_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ServingPLMN, create_dissector_handle(dissect_PLMN_Identity_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_ToBeAdded_List, create_dissector_handle(dissect_E_RABs_ToBeAdded_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_ToBeAdded_Item, create_dissector_handle(dissect_E_RABs_ToBeAdded_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_MeNBtoSeNBContainer, create_dissector_handle(dissect_MeNBtoSeNBContainer_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_Admitted_ToBeAdded_List, create_dissector_handle(dissect_E_RABs_Admitted_ToBeAdded_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_Admitted_ToBeAdded_Item, create_dissector_handle(dissect_E_RABs_Admitted_ToBeAdded_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_SeNBtoMeNBContainer, create_dissector_handle(dissect_SeNBtoMeNBContainer_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ResponseInformationSeNBReconfComp, create_dissector_handle(dissect_ResponseInformationSeNBReconfComp_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_UE_ContextInformationSeNBModReq, create_dissector_handle(dissect_UE_ContextInformationSeNBModReq_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_ToBeAdded_ModReqItem, create_dissector_handle(dissect_E_RABs_ToBeAdded_ModReqItem_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_ToBeModified_ModReqItem, create_dissector_handle(dissect_E_RABs_ToBeModified_ModReqItem_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_ToBeReleased_ModReqItem, create_dissector_handle(dissect_E_RABs_ToBeReleased_ModReqItem_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_Admitted_ToBeAdded_ModAckList, create_dissector_handle(dissect_E_RABs_Admitted_ToBeAdded_ModAckList_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_Admitted_ToBeModified_ModAckList, create_dissector_handle(dissect_E_RABs_Admitted_ToBeModified_ModAckList_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_Admitted_ToBeReleased_ModAckList, create_dissector_handle(dissect_E_RABs_Admitted_ToBeReleased_ModAckList_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_Admitted_ToBeAdded_ModAckItem, create_dissector_handle(dissect_E_RABs_Admitted_ToBeAdded_ModAckItem_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_Admitted_ToBeModified_ModAckItem, create_dissector_handle(dissect_E_RABs_Admitted_ToBeModified_ModAckItem_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_Admitted_ToBeReleased_ModAckItem, create_dissector_handle(dissect_E_RABs_Admitted_ToReleased_ModAckItem_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_ToBeReleased_ModReqd, create_dissector_handle(dissect_E_RABs_ToBeReleased_ModReqd_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_ToBeReleased_ModReqdItem, create_dissector_handle(dissect_E_RABs_ToBeReleased_ModReqdItem_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_SCGChangeIndication, create_dissector_handle(dissect_SCGChangeIndication_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_ToBeReleased_List_RelReq, create_dissector_handle(dissect_E_RABs_ToBeReleased_List_RelReq_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_ToBeReleased_RelReqItem, create_dissector_handle(dissect_E_RABs_ToBeReleased_RelReqItem_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_ToBeReleased_List_RelConf, create_dissector_handle(dissect_E_RABs_ToBeReleased_List_RelConf_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_ToBeReleased_RelConfItem, create_dissector_handle(dissect_E_RABs_ToBeReleased_RelConfItem_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_SubjectToCounterCheck_List, create_dissector_handle(dissect_E_RABs_SubjectToCounterCheck_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_SubjectToCounterCheckItem, create_dissector_handle(dissect_E_RABs_SubjectToCounterCheckItem_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_CoverageModificationList, create_dissector_handle(dissect_CoverageModificationList_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_ReportingPeriodicityCSIR, create_dissector_handle(dissect_ReportingPeriodicityCSIR_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_UE_ContextReferenceAtSeNB, create_dissector_handle(dissect_UE_ContextReferenceAtSeNB_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_UE_ContextKeptIndicator, create_dissector_handle(dissect_UE_ContextKeptIndicator_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_New_eNB_UE_X2AP_ID_Extension, create_dissector_handle(dissect_UE_X2AP_ID_Extension_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_Old_eNB_UE_X2AP_ID_Extension, create_dissector_handle(dissect_UE_X2AP_ID_Extension_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_MeNB_UE_X2AP_ID_Extension, create_dissector_handle(dissect_UE_X2AP_ID_Extension_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_SeNB_UE_X2AP_ID_Extension, create_dissector_handle(dissect_UE_X2AP_ID_Extension_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_LHN_ID, create_dissector_handle(dissect_LHN_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_Tunnel_Information_for_BBF, create_dissector_handle(dissect_TunnelInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_SIPTO_BearerDeactivationIndication, create_dissector_handle(dissect_SIPTOBearerDeactivationIndication_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_GW_TransportLayerAddress, create_dissector_handle(dissect_TransportLayerAddress_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_SIPTO_L_GW_TransportLayerAddress, create_dissector_handle(dissect_TransportLayerAddress_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_X2RemovalThreshold, create_dissector_handle(dissect_X2BenefitValue_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_resumeID, create_dissector_handle(dissect_ResumeID_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_UE_ContextInformationRetrieve, create_dissector_handle(dissect_UE_ContextInformationRetrieve_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_E_RABs_ToBeSetupRetrieve_Item, create_dissector_handle(dissect_E_RABs_ToBeSetupRetrieve_Item_PDU, proto_x2ap));
dissector_add_uint("x2ap.ies", id_NewEUTRANCellIdentifier, create_dissector_handle(dissect_EUTRANCellIdentifier_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_Number_of_Antennaports, create_dissector_handle(dissect_Number_of_Antennaports_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_CompositeAvailableCapacityGroup, create_dissector_handle(dissect_CompositeAvailableCapacityGroup_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_PRACH_Configuration, create_dissector_handle(dissect_PRACH_Configuration_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_MBSFN_Subframe_Info, create_dissector_handle(dissect_MBSFN_Subframe_Infolist_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_DeactivationIndication, create_dissector_handle(dissect_DeactivationIndication_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_ABSInformation, create_dissector_handle(dissect_ABSInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_InvokeIndication, create_dissector_handle(dissect_InvokeIndication_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_ABS_Status, create_dissector_handle(dissect_ABS_Status_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_CSG_Id, create_dissector_handle(dissect_CSG_Id_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_MDTConfiguration, create_dissector_handle(dissect_MDT_Configuration_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_ManagementBasedMDTallowed, create_dissector_handle(dissect_ManagementBasedMDTallowed_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_NeighbourTAC, create_dissector_handle(dissect_TAC_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_Time_UE_StayedInCell_EnhancedGranularity, create_dissector_handle(dissect_Time_UE_StayedInCell_EnhancedGranularity_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_MBMS_Service_Area_List, create_dissector_handle(dissect_MBMS_Service_Area_Identity_List_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_HO_cause, create_dissector_handle(dissect_Cause_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_MultibandInfoList, create_dissector_handle(dissect_MultibandInfoList_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_M3Configuration, create_dissector_handle(dissect_M3Configuration_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_M4Configuration, create_dissector_handle(dissect_M4Configuration_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_M5Configuration, create_dissector_handle(dissect_M5Configuration_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_MDT_Location_Info, create_dissector_handle(dissect_MDT_Location_Info_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_ManagementBasedMDTPLMNList, create_dissector_handle(dissect_MDTPLMNList_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_SignallingBasedMDTPLMNList, create_dissector_handle(dissect_MDTPLMNList_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_ReceiveStatusOfULPDCPSDUsExtended, create_dissector_handle(dissect_ReceiveStatusOfULPDCPSDUsExtended_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_ULCOUNTValueExtended, create_dissector_handle(dissect_COUNTValueExtended_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_DLCOUNTValueExtended, create_dissector_handle(dissect_COUNTValueExtended_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_eARFCNExtension, create_dissector_handle(dissect_EARFCNExtension_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_UL_EARFCNExtension, create_dissector_handle(dissect_EARFCNExtension_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_DL_EARFCNExtension, create_dissector_handle(dissect_EARFCNExtension_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_AdditionalSpecialSubframe_Info, create_dissector_handle(dissect_AdditionalSpecialSubframe_Info_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_IntendedULDLConfiguration, create_dissector_handle(dissect_SubframeAssignment_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_ExtendedULInterferenceOverloadInfo, create_dissector_handle(dissect_ExtendedULInterferenceOverloadInfo_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_DynamicDLTransmissionInformation, create_dissector_handle(dissect_DynamicDLTransmissionInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_CoMPInformation, create_dissector_handle(dissect_CoMPInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_RSRPMRList, create_dissector_handle(dissect_RSRPMRList_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_CSIReportList, create_dissector_handle(dissect_CSIReportList_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_UEID, create_dissector_handle(dissect_UEID_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_enhancedRNTP, create_dissector_handle(dissect_EnhancedRNTP_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_ProSeUEtoNetworkRelaying, create_dissector_handle(dissect_ProSeUEtoNetworkRelaying_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18, create_dissector_handle(dissect_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_ULCOUNTValuePDCP_SNlength18, create_dissector_handle(dissect_COUNTvaluePDCP_SNlength18_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_DLCOUNTValuePDCP_SNlength18, create_dissector_handle(dissect_COUNTvaluePDCP_SNlength18_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_FreqBandIndicatorPriority, create_dissector_handle(dissect_FreqBandIndicatorPriority_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_M6Configuration, create_dissector_handle(dissect_M6Configuration_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_M7Configuration, create_dissector_handle(dissect_M7Configuration_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_Correlation_ID, create_dissector_handle(dissect_Correlation_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_SIPTO_Correlation_ID, create_dissector_handle(dissect_Correlation_ID_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_CellReportingIndicator, create_dissector_handle(dissect_CellReportingIndicator_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_BearerType, create_dissector_handle(dissect_BearerType_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_OffsetOfNbiotChannelNumberToDL_EARFCN, create_dissector_handle(dissect_OffsetOfNbiotChannelNumberToEARFCN_PDU, proto_x2ap));
dissector_add_uint("x2ap.extension", id_OffsetOfNbiotChannelNumberToUL_EARFCN, create_dissector_handle(dissect_OffsetOfNbiotChannelNumberToEARFCN_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_handoverPreparation, create_dissector_handle(dissect_HandoverRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_handoverPreparation, create_dissector_handle(dissect_HandoverRequestAcknowledge_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_handoverPreparation, create_dissector_handle(dissect_HandoverPreparationFailure_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_snStatusTransfer, create_dissector_handle(dissect_SNStatusTransfer_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_uEContextRelease, create_dissector_handle(dissect_UEContextRelease_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_handoverCancel, create_dissector_handle(dissect_HandoverCancel_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_errorIndication, create_dissector_handle(dissect_ErrorIndication_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_reset, create_dissector_handle(dissect_ResetRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_reset, create_dissector_handle(dissect_ResetResponse_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_x2Setup, create_dissector_handle(dissect_X2SetupRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_x2Setup, create_dissector_handle(dissect_X2SetupResponse_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_x2Setup, create_dissector_handle(dissect_X2SetupFailure_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_loadIndication, create_dissector_handle(dissect_LoadInformation_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_eNBConfigurationUpdate, create_dissector_handle(dissect_ENBConfigurationUpdate_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_eNBConfigurationUpdate, create_dissector_handle(dissect_ENBConfigurationUpdateAcknowledge_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_eNBConfigurationUpdate, create_dissector_handle(dissect_ENBConfigurationUpdateFailure_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_resourceStatusReportingInitiation, create_dissector_handle(dissect_ResourceStatusRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_resourceStatusReportingInitiation, create_dissector_handle(dissect_ResourceStatusResponse_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_resourceStatusReportingInitiation, create_dissector_handle(dissect_ResourceStatusFailure_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_resourceStatusReporting, create_dissector_handle(dissect_ResourceStatusUpdate_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_privateMessage, create_dissector_handle(dissect_PrivateMessage_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_handoverReport, create_dissector_handle(dissect_HandoverReport_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_rLFIndication, create_dissector_handle(dissect_RLFIndication_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_mobilitySettingsChange, create_dissector_handle(dissect_MobilityChangeRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_mobilitySettingsChange, create_dissector_handle(dissect_MobilityChangeAcknowledge_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_mobilitySettingsChange, create_dissector_handle(dissect_MobilityChangeFailure_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_cellActivation, create_dissector_handle(dissect_CellActivationRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_cellActivation, create_dissector_handle(dissect_CellActivationResponse_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_cellActivation, create_dissector_handle(dissect_CellActivationFailure_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_x2Release, create_dissector_handle(dissect_X2Release_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_x2APMessageTransfer, create_dissector_handle(dissect_X2APMessageTransfer_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_x2Removal, create_dissector_handle(dissect_X2RemovalRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_x2Removal, create_dissector_handle(dissect_X2RemovalResponse_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_x2Removal, create_dissector_handle(dissect_X2RemovalFailure_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_seNBAdditionPreparation, create_dissector_handle(dissect_SeNBAdditionRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_seNBAdditionPreparation, create_dissector_handle(dissect_SeNBAdditionRequestAcknowledge_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_seNBAdditionPreparation, create_dissector_handle(dissect_SeNBAdditionRequestReject_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_seNBReconfigurationCompletion, create_dissector_handle(dissect_SeNBReconfigurationComplete_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_meNBinitiatedSeNBModificationPreparation, create_dissector_handle(dissect_SeNBModificationRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_meNBinitiatedSeNBModificationPreparation, create_dissector_handle(dissect_SeNBModificationRequestAcknowledge_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_meNBinitiatedSeNBModificationPreparation, create_dissector_handle(dissect_SeNBModificationRequestReject_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_seNBinitiatedSeNBModification, create_dissector_handle(dissect_SeNBModificationRequired_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_seNBinitiatedSeNBModification, create_dissector_handle(dissect_SeNBModificationConfirm_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_seNBinitiatedSeNBModification, create_dissector_handle(dissect_SeNBModificationRefuse_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_meNBinitiatedSeNBRelease, create_dissector_handle(dissect_SeNBReleaseRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_seNBinitiatedSeNBRelease, create_dissector_handle(dissect_SeNBReleaseRequired_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_seNBinitiatedSeNBRelease, create_dissector_handle(dissect_SeNBReleaseConfirm_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_seNBCounterCheck, create_dissector_handle(dissect_SeNBCounterCheckRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.imsg", id_retrieveUEContext, create_dissector_handle(dissect_RetrieveUEContextRequest_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.sout", id_retrieveUEContext, create_dissector_handle(dissect_RetrieveUEContextResponse_PDU, proto_x2ap));
dissector_add_uint("x2ap.proc.uout", id_retrieveUEContext, create_dissector_handle(dissect_RetrieveUEContextFailure_PDU, proto_x2ap));
#line 573 "./asn1/x2ap/packet-x2ap-template.c"
} else {
if (SctpPort != 0) {
dissector_delete_uint("sctp.port", SctpPort, x2ap_handle);
}
}
SctpPort=gbl_x2apSctpPort;
if (SctpPort != 0) {
dissector_add_uint("sctp.port", SctpPort, x2ap_handle);
}
}
