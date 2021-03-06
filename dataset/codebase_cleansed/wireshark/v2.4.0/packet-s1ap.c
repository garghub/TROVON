static void
s1ap_Threshold_RSRP_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%ddBm (%u)", (gint32)v-140, v);
}
static void
s1ap_Threshold_RSRQ_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%.1fdB (%u)", ((float)v/2)-20, v);
}
static void
s1ap_Time_UE_StayedInCell_EnhancedGranularity_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%.1fs", ((float)v)/10);
}
static void
dissect_s1ap_warningMessageContents(tvbuff_t *warning_msg_tvb, proto_tree *tree, packet_info *pinfo, guint8 dcs)
{
guint32 offset;
guint8 nb_of_pages, length, *str;
proto_item *ti;
tvbuff_t *cb_data_page_tvb, *cb_data_tvb;
int i;
nb_of_pages = tvb_get_guint8(warning_msg_tvb, 0);
ti = proto_tree_add_uint(tree, hf_s1ap_WarningMessageContents_nb_pages, warning_msg_tvb, 0, 1, nb_of_pages);
if (nb_of_pages > 15) {
expert_add_info_format(pinfo, ti, &ei_s1ap_number_pages_le15,
"Number of pages should be <=15 (found %u)", nb_of_pages);
nb_of_pages = 15;
}
for (i = 0, offset = 1; i < nb_of_pages; i++) {
length = tvb_get_guint8(warning_msg_tvb, offset+82);
cb_data_page_tvb = tvb_new_subset_length(warning_msg_tvb, offset, length);
cb_data_tvb = dissect_cbs_data(dcs, cb_data_page_tvb, tree, pinfo, 0);
if (cb_data_tvb) {
str = tvb_get_string_enc(wmem_packet_scope(), cb_data_tvb, 0, tvb_reported_length(cb_data_tvb), ENC_UTF_8|ENC_NA);
proto_tree_add_string_format(tree, hf_s1ap_WarningMessageContents_decoded_page, warning_msg_tvb, offset, 83,
str, "Decoded Page %u: %s", i+1, str);
}
offset += 83;
}
}
static void
s1ap_EUTRANRoundTripDelayEstimationInfo_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%uTs (%u)", 16*v, v);
}
static struct s1ap_private_data*
s1ap_get_private_data(packet_info *pinfo)
{
struct s1ap_private_data *s1ap_data = (struct s1ap_private_data*)p_get_proto_data(pinfo->pool, pinfo, proto_s1ap, 0);
if (!s1ap_data) {
s1ap_data = wmem_new0(pinfo->pool, struct s1ap_private_data);
p_add_proto_data(pinfo->pool, pinfo, proto_s1ap, 0, s1ap_data);
}
return s1ap_data;
}
static gboolean
s1ap_is_nbiot_ue(packet_info *pinfo)
{
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(pinfo);
if (s1ap_data->s1ap_conv) {
wmem_tree_key_t tree_key[3];
guint32 *id;
guint32 enb_ue_s1ap_id = s1ap_data->enb_ue_s1ap_id;
tree_key[0].length = 1;
tree_key[0].key = &enb_ue_s1ap_id;
tree_key[1].length = 1;
tree_key[1].key = &pinfo->num;
tree_key[2].length = 0;
tree_key[2].key = NULL;
id = (guint32*)wmem_tree_lookup32_array_le(s1ap_data->s1ap_conv->nbiot_enb_ue_s1ap_id, tree_key);
if (id && (*id == enb_ue_s1ap_id)) {
return TRUE;
}
}
return FALSE;
}
static int
dissect_s1ap_Criticality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_T_global(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 202 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
offset = dissect_per_object_identifier_str(tvb, offset, actx, tree, hf_index, &s1ap_data->obj_id);
return offset;
}
static int
dissect_s1ap_PrivateIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 198 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
s1ap_data->obj_id = NULL;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_PrivateIE_ID, PrivateIE_ID_choice,
NULL);
return offset;
}
static int
dissect_s1ap_ProcedureCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 116 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &s1ap_data->procedure_code, FALSE);
return offset;
}
static int
dissect_s1ap_ProtocolExtensionID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 110 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &s1ap_data->protocol_extension_id, FALSE);
return offset;
}
static int
dissect_s1ap_ProtocolIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 92 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &s1ap_data->protocol_ie_id, FALSE);
#line 96 "./asn1/s1ap/s1ap.cnf"
if (tree) {
proto_item_append_text(proto_item_get_parent_nth(actx->created_item, 2), ": %s",
val_to_str_ext(s1ap_data->protocol_ie_id, &s1ap_ProtocolIE_ID_vals_ext, "unknown (%d)"));
}
return offset;
}
static int
dissect_s1ap_TriggeringMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_T_ie_field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolIEFieldValue);
return offset;
}
static int
dissect_s1ap_ProtocolIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ProtocolIE_Field, ProtocolIE_Field_sequence);
return offset;
}
static int
dissect_s1ap_ProtocolIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ProtocolIE_Container, ProtocolIE_Container_sequence_of,
0, maxProtocolIEs, FALSE);
return offset;
}
static int
dissect_s1ap_ProtocolIE_SingleContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_ProtocolIE_Field(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_ProtocolIE_ContainerList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 143 "./asn1/s1ap/s1ap.cnf"
static const asn1_par_def_t ProtocolIE_ContainerList_pars[] = {
{ "lowerBound", ASN1_PAR_INTEGER },
{ "upperBound", ASN1_PAR_INTEGER },
{ NULL, (asn1_par_type)0 }
};
asn1_stack_frame_check(actx, "ProtocolIE-ContainerList", ProtocolIE_ContainerList_pars);
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ProtocolIE_ContainerList, ProtocolIE_ContainerList_sequence_of,
asn1_param_get_integer(actx,"lowerBound"), asn1_param_get_integer(actx,"upperBound"), FALSE);
return offset;
}
static int
dissect_s1ap_T_extensionValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolExtensionFieldExtensionValue);
return offset;
}
static int
dissect_s1ap_ProtocolExtensionField(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ProtocolExtensionField, ProtocolExtensionField_sequence);
return offset;
}
static int
dissect_s1ap_ProtocolExtensionContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ProtocolExtensionContainer, ProtocolExtensionContainer_sequence_of,
1, maxProtocolExtensions, FALSE);
return offset;
}
static int
dissect_s1ap_T_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 206 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
if (s1ap_data->obj_id) {
offset = call_per_oid_callback(s1ap_data->obj_id, tvb, actx->pinfo, tree, offset, actx, hf_index);
} else {
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, NULL);
}
return offset;
}
static int
dissect_s1ap_PrivateIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_PrivateIE_Field, PrivateIE_Field_sequence);
return offset;
}
static int
dissect_s1ap_PrivateIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_PrivateIE_Container, PrivateIE_Container_sequence_of,
1, maxPrivateIEs, FALSE);
return offset;
}
static int
dissect_s1ap_PLMNidentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 219 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb=NULL;
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, &parameter_tvb);
if(tvb_reported_length(tvb)==0)
return offset;
if (!parameter_tvb)
return offset;
dissect_e212_mcc_mnc(parameter_tvb, actx->pinfo, tree, 0, E212_NONE, FALSE);
if (s1ap_data->supported_ta) {
guint32 plmn = tvb_get_ntoh24(parameter_tvb, 0);
wmem_array_append_one(s1ap_data->supported_ta->plmn, plmn);
} else if (s1ap_data->tai) {
s1ap_data->tai->plmn = tvb_get_ntoh24(parameter_tvb, 0);
}
return offset;
}
static int
dissect_s1ap_MME_Group_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 785 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
2, 2, FALSE, &parameter_tvb);
if (parameter_tvb) {
actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_s1ap_MME_Code(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 776 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
1, 1, FALSE, &parameter_tvb);
if (parameter_tvb) {
actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_s1ap_GUMMEI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_GUMMEI, GUMMEI_sequence);
return offset;
}
static int
dissect_s1ap_M_TMSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 997 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
4, 4, FALSE, &parameter_tvb);
if (parameter_tvb) {
actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 4, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_s1ap_Additional_GUTI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_Additional_GUTI, Additional_GUTI_sequence);
return offset;
}
static int
dissect_s1ap_CellIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_EUTRAN_CGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EUTRAN_CGI, EUTRAN_CGI_sequence);
return offset;
}
static int
dissect_s1ap_CellIdListforMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellIdListforMDT, CellIdListforMDT_sequence_of,
1, maxnoofCellIDforMDT, FALSE);
return offset;
}
static int
dissect_s1ap_CellBasedMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellBasedMDT, CellBasedMDT_sequence);
return offset;
}
static int
dissect_s1ap_TAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 964 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
2, 2, FALSE, &parameter_tvb);
if (parameter_tvb) {
actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
if (s1ap_data->supported_ta) {
s1ap_data->supported_ta->tac = tvb_get_ntohs(parameter_tvb, 0);
} else if (s1ap_data->tai) {
s1ap_data->tai->tac = tvb_get_ntohs(parameter_tvb, 0);
}
}
return offset;
}
static int
dissect_s1ap_TAListforMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAListforMDT, TAListforMDT_sequence_of,
1, maxnoofTAforMDT, FALSE);
return offset;
}
static int
dissect_s1ap_TABasedMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TABasedMDT, TABasedMDT_sequence);
return offset;
}
static int
dissect_s1ap_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_TAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1063 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
s1ap_data->tai = wmem_new0(wmem_packet_scope(), struct s1ap_tai);
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAI, TAI_sequence);
if (!PINFO_FD_VISITED(actx->pinfo) && s1ap_data->s1ap_conv &&
(s1ap_data->message_type == INITIATING_MESSAGE) &&
(s1ap_data->procedure_code == id_initialUEMessage)) {
guint64 key = (s1ap_data->tai->plmn << 16) | s1ap_data->tai->tac;
if (wmem_map_lookup(s1ap_data->s1ap_conv->nbiot_ta, &key)) {
wmem_tree_key_t tree_key[3];
guint32 *id = wmem_new(wmem_file_scope(), guint32);
*id = s1ap_data->enb_ue_s1ap_id;
tree_key[0].length = 1;
tree_key[0].key = id;
tree_key[1].length = 1;
tree_key[1].key = &actx->pinfo->num;
tree_key[2].length = 0;
tree_key[2].key = NULL;
wmem_tree_insert32_array(s1ap_data->s1ap_conv->nbiot_enb_ue_s1ap_id, tree_key, id);
}
}
return offset;
}
static int
dissect_s1ap_TAIListforMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAIListforMDT, TAIListforMDT_sequence_of,
1, maxnoofTAforMDT, FALSE);
return offset;
}
static int
dissect_s1ap_TAIBasedMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAIBasedMDT, TAIBasedMDT_sequence);
return offset;
}
static int
dissect_s1ap_AreaScopeOfMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_AreaScopeOfMDT, AreaScopeOfMDT_choice,
NULL);
return offset;
}
static int
dissect_s1ap_PriorityLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_Pre_emptionCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Pre_emptionVulnerability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_AllocationAndRetentionPriority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_AllocationAndRetentionPriority, AllocationAndRetentionPriority_sequence);
return offset;
}
static int
dissect_s1ap_CELevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 672 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
if (g_s1ap_dissect_container) {
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_CELevel);
if ((s1ap_is_nbiot_ue(actx->pinfo) && (g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_AUTOMATIC)) ||
(g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_NBIOT)) {
dissect_lte_rrc_UEPagingCoverageInformation_NB_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
} else {
dissect_lte_rrc_UEPagingCoverageInformation_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
}
}
return offset;
}
static int
dissect_s1ap_CellIdentifierAndCELevelForCECapableUEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellIdentifierAndCELevelForCECapableUEs, CellIdentifierAndCELevelForCECapableUEs_sequence);
return offset;
}
static int
dissect_s1ap_AssistanceDataForCECapableUEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_AssistanceDataForCECapableUEs, AssistanceDataForCECapableUEs_sequence);
return offset;
}
static int
dissect_s1ap_RecommendedCellList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_RecommendedCellList, RecommendedCellList_sequence_of,
1, maxnoofRecommendedCells, FALSE);
return offset;
}
static int
dissect_s1ap_RecommendedCellsForPaging(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_RecommendedCellsForPaging, RecommendedCellsForPaging_sequence);
return offset;
}
static int
dissect_s1ap_AssistanceDataForRecommendedCells(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_AssistanceDataForRecommendedCells, AssistanceDataForRecommendedCells_sequence);
return offset;
}
static int
dissect_s1ap_PagingAttemptCount(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 16U, NULL, TRUE);
return offset;
}
static int
dissect_s1ap_IntendedNumberOfPagingAttempts(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 16U, NULL, TRUE);
return offset;
}
static int
dissect_s1ap_NextPagingAreaScope(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_PagingAttemptInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_PagingAttemptInformation, PagingAttemptInformation_sequence);
return offset;
}
static int
dissect_s1ap_AssistanceDataForPaging(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_AssistanceDataForPaging, AssistanceDataForPaging_sequence);
return offset;
}
static int
dissect_s1ap_Bearers_SubjectToStatusTransferList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_Bearers_SubjectToStatusTransferList, Bearers_SubjectToStatusTransferList_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RAB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, TRUE);
return offset;
}
static int
dissect_s1ap_PDCP_SN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_HFN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1048575U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_COUNTvalue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_COUNTvalue, COUNTvalue_sequence);
return offset;
}
static int
dissect_s1ap_ReceiveStatusofULPDCPSDUs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
4096, 4096, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_Bearers_SubjectToStatusTransfer_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_Bearers_SubjectToStatusTransfer_Item, Bearers_SubjectToStatusTransfer_Item_sequence);
return offset;
}
static int
dissect_s1ap_BearerType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_BitRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer_64b(tvb, offset, actx, tree, hf_index,
0U, G_GUINT64_CONSTANT(10000000000), NULL, FALSE);
return offset;
}
static int
dissect_s1ap_BPLMNs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_BPLMNs, BPLMNs_sequence_of,
1, maxnoofBPLMNs, FALSE);
return offset;
}
static int
dissect_s1ap_NumberOfBroadcasts(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_CellID_Cancelled_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellID_Cancelled_Item, CellID_Cancelled_Item_sequence);
return offset;
}
static int
dissect_s1ap_CellID_Cancelled(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellID_Cancelled, CellID_Cancelled_sequence_of,
1, maxnoofCellID, FALSE);
return offset;
}
static int
dissect_s1ap_CancelledCellinTAI_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CancelledCellinTAI_Item, CancelledCellinTAI_Item_sequence);
return offset;
}
static int
dissect_s1ap_CancelledCellinTAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CancelledCellinTAI, CancelledCellinTAI_sequence_of,
1, maxnoofCellinTAI, FALSE);
return offset;
}
static int
dissect_s1ap_TAI_Cancelled_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAI_Cancelled_Item, TAI_Cancelled_Item_sequence);
return offset;
}
static int
dissect_s1ap_TAI_Cancelled(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAI_Cancelled, TAI_Cancelled_sequence_of,
1, maxnoofTAIforWarning, FALSE);
return offset;
}
static int
dissect_s1ap_EmergencyAreaID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_CancelledCellinEAI_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CancelledCellinEAI_Item, CancelledCellinEAI_Item_sequence);
return offset;
}
static int
dissect_s1ap_CancelledCellinEAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CancelledCellinEAI, CancelledCellinEAI_sequence_of,
1, maxnoofCellinEAI, FALSE);
return offset;
}
static int
dissect_s1ap_EmergencyAreaID_Cancelled_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EmergencyAreaID_Cancelled_Item, EmergencyAreaID_Cancelled_Item_sequence);
return offset;
}
static int
dissect_s1ap_EmergencyAreaID_Cancelled(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_EmergencyAreaID_Cancelled, EmergencyAreaID_Cancelled_sequence_of,
1, maxnoofEmergencyAreaID, FALSE);
return offset;
}
static int
dissect_s1ap_BroadcastCancelledAreaList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_BroadcastCancelledAreaList, BroadcastCancelledAreaList_choice,
NULL);
return offset;
}
static int
dissect_s1ap_CellID_Broadcast_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellID_Broadcast_Item, CellID_Broadcast_Item_sequence);
return offset;
}
static int
dissect_s1ap_CellID_Broadcast(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellID_Broadcast, CellID_Broadcast_sequence_of,
1, maxnoofCellID, FALSE);
return offset;
}
static int
dissect_s1ap_CompletedCellinTAI_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CompletedCellinTAI_Item, CompletedCellinTAI_Item_sequence);
return offset;
}
static int
dissect_s1ap_CompletedCellinTAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CompletedCellinTAI, CompletedCellinTAI_sequence_of,
1, maxnoofCellinTAI, FALSE);
return offset;
}
static int
dissect_s1ap_TAI_Broadcast_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAI_Broadcast_Item, TAI_Broadcast_Item_sequence);
return offset;
}
static int
dissect_s1ap_TAI_Broadcast(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAI_Broadcast, TAI_Broadcast_sequence_of,
1, maxnoofTAIforWarning, FALSE);
return offset;
}
static int
dissect_s1ap_CompletedCellinEAI_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CompletedCellinEAI_Item, CompletedCellinEAI_Item_sequence);
return offset;
}
static int
dissect_s1ap_CompletedCellinEAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CompletedCellinEAI, CompletedCellinEAI_sequence_of,
1, maxnoofCellinEAI, FALSE);
return offset;
}
static int
dissect_s1ap_EmergencyAreaID_Broadcast_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EmergencyAreaID_Broadcast_Item, EmergencyAreaID_Broadcast_Item_sequence);
return offset;
}
static int
dissect_s1ap_EmergencyAreaID_Broadcast(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_EmergencyAreaID_Broadcast, EmergencyAreaID_Broadcast_sequence_of,
1, maxnoofEmergencyAreaID, FALSE);
return offset;
}
static int
dissect_s1ap_BroadcastCompletedAreaList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_BroadcastCompletedAreaList, BroadcastCompletedAreaList_choice,
NULL);
return offset;
}
static int
dissect_s1ap_CauseRadioNetwork(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1939 "./asn1/s1ap/s1ap.cnf"
guint32 value;
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
36, &value, TRUE, 3, NULL);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [RadioNetwork-cause=%s]", val_to_str_const(value, s1ap_CauseRadioNetwork_vals, "Unknown"));
return offset;
}
static int
dissect_s1ap_CauseTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1944 "./asn1/s1ap/s1ap.cnf"
guint32 value;
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, &value, TRUE, 0, NULL);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [Transport-cause=%s]", val_to_str_const(value, s1ap_CauseTransport_vals, "Unknown"));
return offset;
}
static int
dissect_s1ap_CauseNas(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1949 "./asn1/s1ap/s1ap.cnf"
guint32 value;
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, &value, TRUE, 1, NULL);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [NAS-cause=%s]", val_to_str_const(value, s1ap_CauseNas_vals, "Unknown"));
return offset;
}
static int
dissect_s1ap_CauseProtocol(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1954 "./asn1/s1ap/s1ap.cnf"
guint32 value;
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, &value, TRUE, 0, NULL);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [Protocol-cause=%s]", val_to_str_const(value, s1ap_CauseProtocol_vals, "Unknown"));
return offset;
}
static int
dissect_s1ap_CauseMisc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1959 "./asn1/s1ap/s1ap.cnf"
guint32 value;
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, &value, TRUE, 0, NULL);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [Misc-cause=%s]", val_to_str_const(value, s1ap_CauseMisc_vals, "Unknown"));
return offset;
}
static int
dissect_s1ap_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_Cause, Cause_choice,
NULL);
return offset;
}
static int
dissect_s1ap_CellAccessMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_CE_mode_B_SupportIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 616 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
if (gcsna_handle) {
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_Cdma2000PDU);
call_dissector(gcsna_handle, parameter_tvb, actx->pinfo, subtree);
}
return offset;
}
static int
dissect_s1ap_Cdma2000RATType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000SectorID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 631 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_Cdma2000SectorID);
dissect_a21_ie_common(parameter_tvb, actx->pinfo, NULL, subtree, 0, 0 );
return offset;
}
static int
dissect_s1ap_Cdma2000HOStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000HORequiredIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000OneXMEID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000OneXMSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000OneXPilot(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_Cdma2000OneXSRVCCInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_Cdma2000OneXSRVCCInfo, Cdma2000OneXSRVCCInfo_sequence);
return offset;
}
static int
dissect_s1ap_Cdma2000OneXRAND(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_Cell_Size(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_CellType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellType, CellType_sequence);
return offset;
}
static int
dissect_s1ap_LAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 979 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
2, 2, FALSE, &parameter_tvb);
if (parameter_tvb) {
actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_s1ap_CI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_RAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 988 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
1, 1, FALSE, &parameter_tvb);
if (parameter_tvb) {
actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_s1ap_CGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CGI, CGI_sequence);
return offset;
}
static int
dissect_s1ap_CNDomain(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_ConcurrentWarningMessageIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Correlation_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_CSFallbackIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 1, NULL);
return offset;
}
static int
dissect_s1ap_AdditionalCSFallbackIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_CSG_Id(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
27, 27, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_CSG_IdList_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CSG_IdList_Item, CSG_IdList_Item_sequence);
return offset;
}
static int
dissect_s1ap_CSG_IdList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CSG_IdList, CSG_IdList_sequence_of,
1, maxnoofCSGs, FALSE);
return offset;
}
static int
dissect_s1ap_CSGMembershipStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_PDCP_SNExtended(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 32767U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_HFNModified(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 131071U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_COUNTValueExtended(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_COUNTValueExtended, COUNTValueExtended_sequence);
return offset;
}
static int
dissect_s1ap_PDCP_SNlength18(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 262143U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_HFNforPDCP_SNlength18(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16383U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_COUNTvaluePDCP_SNlength18(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_COUNTvaluePDCP_SNlength18, COUNTvaluePDCP_SNlength18_sequence);
return offset;
}
static int
dissect_s1ap_TypeOfError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_CriticalityDiagnostics_IE_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CriticalityDiagnostics_IE_Item, CriticalityDiagnostics_IE_Item_sequence);
return offset;
}
static int
dissect_s1ap_CriticalityDiagnostics_IE_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CriticalityDiagnostics_IE_List, CriticalityDiagnostics_IE_List_sequence_of,
1, maxnoofErrors, FALSE);
return offset;
}
static int
dissect_s1ap_CriticalityDiagnostics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CriticalityDiagnostics, CriticalityDiagnostics_sequence);
return offset;
}
static int
dissect_s1ap_DataCodingScheme(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 873 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, &parameter_tvb, NULL);
if (parameter_tvb) {
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_DataCodingScheme);
s1ap_data->data_coding_scheme = dissect_cbs_data_coding_scheme(parameter_tvb, actx->pinfo, subtree, 0);
}
return offset;
}
static int
dissect_s1ap_DL_Forwarding(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Direct_Forwarding_Path_Availability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Data_Forwarding_Not_Possible(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_EARFCN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxEARFCN, NULL, TRUE);
return offset;
}
static int
dissect_s1ap_ECGIList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ECGIList, ECGIList_sequence_of,
1, maxnoofCellID, FALSE);
return offset;
}
static int
dissect_s1ap_PWSfailedECGIList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_PWSfailedECGIList, PWSfailedECGIList_sequence_of,
1, maxnoofCellsineNB, FALSE);
return offset;
}
static int
dissect_s1ap_EmergencyAreaIDList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_EmergencyAreaIDList, EmergencyAreaIDList_sequence_of,
1, maxnoofEmergencyAreaID, FALSE);
return offset;
}
static int
dissect_s1ap_ECGI_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ECGI_List, ECGI_List_sequence_of,
1, maxnoofCellsineNB, FALSE);
return offset;
}
static int
dissect_s1ap_EmergencyAreaIDListForRestart(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_EmergencyAreaIDListForRestart, EmergencyAreaIDListForRestart_sequence_of,
1, maxnoofRestartEmergencyAreaIDs, FALSE);
return offset;
}
static int
dissect_s1ap_BIT_STRING_SIZE_20(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
20, 20, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_BIT_STRING_SIZE_28(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_ENB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENB_ID, ENB_ID_choice,
NULL);
return offset;
}
static int
dissect_s1ap_LAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_LAI, LAI_sequence);
return offset;
}
static int
dissect_s1ap_GERAN_Cell_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_GERAN_Cell_ID, GERAN_Cell_ID_sequence);
return offset;
}
int
dissect_s1ap_Global_ENB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_Global_ENB_ID, Global_ENB_ID_sequence);
return offset;
}
static int
dissect_s1ap_GUMMEIList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_GUMMEIList, GUMMEIList_sequence_of,
1, maxnoofMMECs, FALSE);
return offset;
}
static int
dissect_s1ap_ENB_StatusTransfer_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENB_StatusTransfer_TransparentContainer, ENB_StatusTransfer_TransparentContainer_sequence);
return offset;
}
static int
dissect_s1ap_ENB_UE_S1AP_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1057 "./asn1/s1ap/s1ap.cnf"
guint32 enb_ue_s1ap_id;
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16777215U, &enb_ue_s1ap_id, FALSE);
s1ap_data->enb_ue_s1ap_id = (guint16)enb_ue_s1ap_id;
return offset;
}
static int
dissect_s1ap_ENBname(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 239 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb=NULL;
int length;
int p_offset;
gboolean is_ascii;
offset = dissect_per_PrintableString(tvb, offset, actx, tree, hf_index,
1, 150, TRUE);
if (!parameter_tvb)
return offset;
length = tvb_reported_length(parameter_tvb);
is_ascii = TRUE;
for (p_offset=0; p_offset < length; p_offset++){
if(!g_ascii_isprint(tvb_get_guint8(parameter_tvb, p_offset ))){
is_ascii = FALSE;
break;
}
}
if (is_ascii)
proto_item_append_text(actx->created_item," (%s)",tvb_format_text(parameter_tvb, 0, length));
return offset;
}
static int
dissect_s1ap_TransportLayerAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 306 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb=NULL;
proto_tree *subtree;
gint tvb_len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 160, TRUE, &parameter_tvb, NULL);
if (!parameter_tvb)
return offset;
tvb_len = tvb_reported_length(parameter_tvb);
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_TransportLayerAddress);
if (tvb_len==4) {
proto_tree_add_item(subtree, hf_s1ap_transportLayerAddressIPv4, parameter_tvb, 0, 4, ENC_BIG_ENDIAN);
} else if (tvb_len==16) {
proto_tree_add_item(subtree, hf_s1ap_transportLayerAddressIPv6, parameter_tvb, 0, 16, ENC_NA);
} else if (tvb_len==20) {
proto_tree_add_item(subtree, hf_s1ap_transportLayerAddressIPv4, parameter_tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_s1ap_transportLayerAddressIPv6, parameter_tvb, 4, 16, ENC_NA);
}
return offset;
}
static int
dissect_s1ap_ENBX2TLAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBX2TLAs, ENBX2TLAs_sequence_of,
1, maxnoofeNBX2TLAs, FALSE);
return offset;
}
static int
dissect_s1ap_EncryptionAlgorithms(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 792 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, TRUE, &parameter_tvb, NULL);
if(parameter_tvb){
const gint *fields[] = {
&hf_s1ap_encryptionAlgorithms_EEA1,
&hf_s1ap_encryptionAlgorithms_EEA2,
&hf_s1ap_encryptionAlgorithms_EEA3,
&hf_s1ap_encryptionAlgorithms_Reserved,
NULL
};
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_EncryptionAlgorithms);
proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 2, fields, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_s1ap_EPLMNs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_EPLMNs, EPLMNs_sequence_of,
1, maxnoofEPLMNs, FALSE);
return offset;
}
static int
dissect_s1ap_EventType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_E_RABInformationList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABInformationList, E_RABInformationList_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABInformationListItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABInformationListItem, E_RABInformationListItem_sequence);
return offset;
}
static int
dissect_s1ap_E_RABList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABList, E_RABList_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABItem, E_RABItem_sequence);
return offset;
}
static int
dissect_s1ap_QCI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_GBR_QosInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_GBR_QosInformation, GBR_QosInformation_sequence);
return offset;
}
static int
dissect_s1ap_E_RABLevelQoSParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABLevelQoSParameters, E_RABLevelQoSParameters_sequence);
return offset;
}
static int
dissect_s1ap_EUTRANRoundTripDelayEstimationInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2047U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_ExpectedActivityPeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 181U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_ExpectedIdlePeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 181U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_SourceOfUEActivityBehaviourInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_ExpectedUEActivityBehaviour(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ExpectedUEActivityBehaviour, ExpectedUEActivityBehaviour_sequence);
return offset;
}
static int
dissect_s1ap_ExpectedHOInterval(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_ExpectedUEBehaviour(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ExpectedUEBehaviour, ExpectedUEBehaviour_sequence);
return offset;
}
static int
dissect_s1ap_ExtendedRNC_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
4096U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_ExtendedRepetitionPeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
4096U, 131071U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_Extended_UEIdentityIndexValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
14, 14, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_ForbiddenInterRATs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 2, NULL);
return offset;
}
static int
dissect_s1ap_ForbiddenTACs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ForbiddenTACs, ForbiddenTACs_sequence_of,
1, maxnoofForbTACs, FALSE);
return offset;
}
static int
dissect_s1ap_ForbiddenTAs_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ForbiddenTAs_Item, ForbiddenTAs_Item_sequence);
return offset;
}
static int
dissect_s1ap_ForbiddenTAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ForbiddenTAs, ForbiddenTAs_sequence_of,
1, maxnoofEPLMNsPlusOne, FALSE);
return offset;
}
static int
dissect_s1ap_ForbiddenLACs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ForbiddenLACs, ForbiddenLACs_sequence_of,
1, maxnoofForbLACs, FALSE);
return offset;
}
static int
dissect_s1ap_ForbiddenLAs_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ForbiddenLAs_Item, ForbiddenLAs_Item_sequence);
return offset;
}
static int
dissect_s1ap_ForbiddenLAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ForbiddenLAs, ForbiddenLAs_sequence_of,
1, maxnoofEPLMNsPlusOne, FALSE);
return offset;
}
static int
dissect_s1ap_GTP_TEID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_GUMMEIType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_GWContextReleaseIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_HandoverRestrictionList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverRestrictionList, HandoverRestrictionList_sequence);
return offset;
}
static int
dissect_s1ap_HandoverType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 356 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, &s1ap_data->handover_type_value, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Masked_IMEISV(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
64, 64, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_MeasurementsToActivate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 915 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, &parameter_tvb, NULL);
if(parameter_tvb){
const gint *fields[] = {
&hf_s1ap_measurementsToActivate_M1,
&hf_s1ap_measurementsToActivate_M2,
&hf_s1ap_measurementsToActivate_M3,
&hf_s1ap_measurementsToActivate_M4,
&hf_s1ap_measurementsToActivate_M5,
&hf_s1ap_measurementsToActivate_LoggingM1FromEventTriggered,
&hf_s1ap_measurementsToActivate_M6,
&hf_s1ap_measurementsToActivate_M7,
NULL
};
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_MeasurementsToActivate);
proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 1, fields, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_s1ap_M1ReportingTrigger(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 1, NULL);
return offset;
}
static int
dissect_s1ap_Threshold_RSRP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 97U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_Threshold_RSRQ(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 34U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_MeasurementThresholdA2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_MeasurementThresholdA2, MeasurementThresholdA2_choice,
NULL);
return offset;
}
static int
dissect_s1ap_M1ThresholdEventA2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_M1ThresholdEventA2, M1ThresholdEventA2_sequence);
return offset;
}
static int
dissect_s1ap_ReportIntervalMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
13, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_ReportAmountMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_M1PeriodicReporting(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_M1PeriodicReporting, M1PeriodicReporting_sequence);
return offset;
}
static int
dissect_s1ap_ImmediateMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ImmediateMDT, ImmediateMDT_sequence);
return offset;
}
static int
dissect_s1ap_IMSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1004 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 8, FALSE, &parameter_tvb);
if (parameter_tvb) {
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_IMSI);
dissect_e212_imsi(parameter_tvb, actx->pinfo, subtree, 0, tvb_reported_length(parameter_tvb), FALSE);
}
return offset;
}
static int
dissect_s1ap_RecommendedENBList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_RecommendedENBList, RecommendedENBList_sequence_of,
1, maxnoofRecommendedENBs, FALSE);
return offset;
}
static int
dissect_s1ap_RecommendedENBsForPaging(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_RecommendedENBsForPaging, RecommendedENBsForPaging_sequence);
return offset;
}
static int
dissect_s1ap_InformationOnRecommendedCellsAndENBsForPaging(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_InformationOnRecommendedCellsAndENBsForPaging, InformationOnRecommendedCellsAndENBsForPaging_sequence);
return offset;
}
static int
dissect_s1ap_IntegrityProtectionAlgorithms(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 807 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, TRUE, &parameter_tvb, NULL);
if(parameter_tvb){
const gint *fields[] = {
&hf_s1ap_integrityProtectionAlgorithms_EIA1,
&hf_s1ap_integrityProtectionAlgorithms_EIA2,
&hf_s1ap_integrityProtectionAlgorithms_EIA3,
&hf_s1ap_integrityProtectionAlgorithms_Reserved,
NULL
};
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_IntegrityProtectionAlgorithms);
proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 2, fields, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_s1ap_InterfacesToTrace(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 756 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, &parameter_tvb, NULL);
if(parameter_tvb){
const gint *fields[] = {
&hf_s1ap_interfacesToTrace_S1_MME,
&hf_s1ap_interfacesToTrace_X2,
&hf_s1ap_interfacesToTrace_Uu,
&hf_s1ap_interfacesToTrace_Reserved,
NULL
};
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_InterfacesToTrace);
proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 1, fields, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_s1ap_KillAllWarningMessages(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Time_UE_StayedInCell(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_LastVisitedEUTRANCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_LastVisitedEUTRANCellInformation, LastVisitedEUTRANCellInformation_sequence);
return offset;
}
static int
dissect_s1ap_LastVisitedUTRANCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 828 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
if (g_s1ap_dissect_container) {
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_LastVisitedUTRANCellInformation);
dissect_ranap_LastVisitedUTRANCell_Item_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
}
return offset;
}
static int
dissect_s1ap_LastVisitedGERANCellInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_LastVisitedGERANCellInformation, LastVisitedGERANCellInformation_choice,
NULL);
return offset;
}
static int
dissect_s1ap_LastVisitedCell_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_LastVisitedCell_Item, LastVisitedCell_Item_choice,
NULL);
return offset;
}
static int
dissect_s1ap_LPPa_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 297 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if ((tvb_reported_length(parameter_tvb)>0)&&(lppa_handle))
call_dissector(lppa_handle, parameter_tvb, actx->pinfo, tree);
return offset;
}
static int
dissect_s1ap_LHN_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 950 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
32, 256, FALSE, &parameter_tvb);
actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, -1, ENC_UTF_8|ENC_NA);
return offset;
}
static int
dissect_s1ap_Links_to_log(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_T_pattern_period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_INTEGER_0_10239_(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 10239U, NULL, TRUE);
return offset;
}
static int
dissect_s1ap_ListeningSubframePattern(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ListeningSubframePattern, ListeningSubframePattern_sequence);
return offset;
}
static int
dissect_s1ap_LoggingInterval(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_LoggingDuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_s1ap_LoggedMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_LoggedMDT, LoggedMDT_sequence);
return offset;
}
static int
dissect_s1ap_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_MBSFN_ResultToLogInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MBSFN_ResultToLogInfo, MBSFN_ResultToLogInfo_sequence);
return offset;
}
static int
dissect_s1ap_MBSFN_ResultToLog(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_MBSFN_ResultToLog, MBSFN_ResultToLog_sequence_of,
1, maxnoofMBSFNAreaMDT, FALSE);
return offset;
}
static int
dissect_s1ap_LoggedMBSFNMDT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_LoggedMBSFNMDT, LoggedMBSFNMDT_sequence);
return offset;
}
static int
dissect_s1ap_M3period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_M3Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_M3Configuration, M3Configuration_sequence);
return offset;
}
static int
dissect_s1ap_M4period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_M4Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_M4Configuration, M4Configuration_sequence);
return offset;
}
static int
dissect_s1ap_M5period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_M5Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_M5Configuration, M5Configuration_sequence);
return offset;
}
static int
dissect_s1ap_M6report_Interval(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_M6delay_threshold(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
12, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_M6Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_M6Configuration, M6Configuration_sequence);
return offset;
}
static int
dissect_s1ap_M7period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 60U, NULL, TRUE);
return offset;
}
static int
dissect_s1ap_M7Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_M7Configuration, M7Configuration_sequence);
return offset;
}
static int
dissect_s1ap_MDT_Activation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 1, NULL);
return offset;
}
static int
dissect_s1ap_MDT_Location_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 934 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, &parameter_tvb, NULL);
if(parameter_tvb){
const gint *fields[] = {
&hf_s1ap_MDT_Location_Info_GNSS,
&hf_s1ap_MDT_Location_Info_E_CID,
&hf_s1ap_MDT_Location_Info_Reserved,
NULL
};
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_MDT_Location_Info);
proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 1, fields, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_s1ap_MDTMode_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_ProtocolIE_SingleContainer(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_MDTMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_MDTMode, MDTMode_choice,
NULL);
return offset;
}
static int
dissect_s1ap_MDT_Configuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MDT_Configuration, MDT_Configuration_sequence);
return offset;
}
static int
dissect_s1ap_ManagementBasedMDTAllowed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_MDTPLMNList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_MDTPLMNList, MDTPLMNList_sequence_of,
1, maxnoofMDTPLMNs, FALSE);
return offset;
}
static int
dissect_s1ap_PrivacyIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_MessageIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 843 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, -1,
16, 16, FALSE, &parameter_tvb, NULL);
if (parameter_tvb) {
actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_s1ap_MobilityInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
32, 32, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_MMEname(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 262 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb=NULL;
int length;
int p_offset;
gboolean is_ascii;
offset = dissect_per_PrintableString(tvb, offset, actx, tree, hf_index,
1, 150, TRUE);
if (!parameter_tvb)
return offset;
length = tvb_reported_length(parameter_tvb);
is_ascii = TRUE;
for (p_offset=0; p_offset < length; p_offset++){
if(!g_ascii_isprint(tvb_get_guint8(parameter_tvb, p_offset ))){
is_ascii = FALSE;
break;
}
}
if (is_ascii)
proto_item_append_text(actx->created_item," (%s)",tvb_format_text(parameter_tvb, 0, length));
return offset;
}
static int
dissect_s1ap_MMEPagingTarget(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_MMEPagingTarget, MMEPagingTarget_choice,
NULL);
return offset;
}
static int
dissect_s1ap_MMERelaySupportIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_MME_UE_S1AP_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_MSClassmark2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 893 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (parameter_tvb) {
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_MSClassmark);
de_ms_cm_2(parameter_tvb, subtree, actx->pinfo, 0, tvb_reported_length(parameter_tvb), NULL, 0);
}
return offset;
}
static int
dissect_s1ap_MSClassmark3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 901 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (parameter_tvb) {
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_MSClassmark);
de_ms_cm_3(parameter_tvb, subtree, actx->pinfo, 0, tvb_reported_length(parameter_tvb), NULL, 0);
}
return offset;
}
static int
dissect_s1ap_MutingAvailabilityIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_T_muting_pattern_period(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_MutingPatternInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MutingPatternInformation, MutingPatternInformation_sequence);
return offset;
}
static int
dissect_s1ap_NAS_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 288 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if ((tvb_reported_length(parameter_tvb)>0)&&(nas_eps_handle))
call_dissector(nas_eps_handle,parameter_tvb,actx->pinfo, tree);
return offset;
}
static int
dissect_s1ap_NASSecurityParametersfromE_UTRAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1012 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (parameter_tvb) {
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_NASSecurityParameters);
de_emm_sec_par_from_eutra(parameter_tvb, subtree, actx->pinfo, 0, tvb_reported_length(parameter_tvb), NULL, 0);
}
return offset;
}
static int
dissect_s1ap_NASSecurityParameterstoE_UTRAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1020 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (parameter_tvb) {
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_NASSecurityParameters);
de_emm_sec_par_to_eutra(parameter_tvb, subtree, actx->pinfo, 0, tvb_reported_length(parameter_tvb), NULL, 0);
}
return offset;
}
static int
dissect_s1ap_NB_IoT_DefaultPagingDRX(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_NB_IoT_Paging_eDRX_Cycle(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
14, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_NB_IoT_PagingTimeWindow(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_NB_IoT_Paging_eDRXInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_NB_IoT_Paging_eDRXInformation, NB_IoT_Paging_eDRXInformation_sequence);
return offset;
}
static int
dissect_s1ap_NB_IoT_UEIdentityIndexValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
12, 12, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_NumberofBroadcastRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_OverloadAction(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 2, NULL);
return offset;
}
static int
dissect_s1ap_OverloadResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_OverloadResponse, OverloadResponse_choice,
NULL);
return offset;
}
static int
dissect_s1ap_Paging_eDRX_Cycle(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
14, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_PagingTimeWindow(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Paging_eDRXInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_Paging_eDRXInformation, Paging_eDRXInformation_sequence);
return offset;
}
static int
dissect_s1ap_PagingDRX(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_PagingPriority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Port_Number(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 337 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
2, 2, FALSE, &parameter_tvb);
if (parameter_tvb) {
actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_s1ap_ProSeDirectDiscovery(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_ProSeDirectCommunication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_ProSeAuthorized(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ProSeAuthorized, ProSeAuthorized_sequence);
return offset;
}
static int
dissect_s1ap_ProSeUEtoNetworkRelaying(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_PS_ServiceNotAvailable(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_ReceiveStatusOfULPDCPSDUsExtended(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16384, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 131072, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_INTEGER_0_4095(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_RecommendedCellItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_RecommendedCellItem, RecommendedCellItem_sequence);
return offset;
}
static int
dissect_s1ap_RecommendedENBItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_RecommendedENBItem, RecommendedENBItem_sequence);
return offset;
}
static int
dissect_s1ap_RelativeMMECapacity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_RelayNode_Indicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_RAT_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1042 "./asn1/s1ap/s1ap.cnf"
guint32 rat_type = 0xffffffff;
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, &rat_type, TRUE, 0, NULL);
if (s1ap_data->s1ap_conv && s1ap_data->supported_ta && (rat_type == nbiot)) {
guint64 *key;
guint i;
for (i = 0; i < wmem_array_get_count(s1ap_data->supported_ta->plmn); i++) {
key = wmem_new(wmem_file_scope(), guint64);
*key = ((*(guint32*)wmem_array_index(s1ap_data->supported_ta->plmn, i)) << 16) | s1ap_data->supported_ta->tac;
wmem_map_insert(s1ap_data->s1ap_conv->nbiot_ta, key, GUINT_TO_POINTER(1));
}
}
return offset;
}
static int
dissect_s1ap_ReportArea(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_RequestType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_RequestType, RequestType_sequence);
return offset;
}
static int
dissect_s1ap_RIMInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 600 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_RIMInformation);
if ((tvb_reported_length(parameter_tvb)>0)&&(bssgp_handle)){
col_set_fence(actx->pinfo->cinfo, COL_INFO);
call_dissector(bssgp_handle,parameter_tvb,actx->pinfo, subtree);
}
return offset;
}
static int
dissect_s1ap_RNC_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_TargetRNC_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TargetRNC_ID, TargetRNC_ID_sequence);
return offset;
}
static int
dissect_s1ap_OCTET_STRING_SIZE_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_RIMRoutingAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_RIMRoutingAddress, RIMRoutingAddress_choice,
NULL);
return offset;
}
static int
dissect_s1ap_RIMTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_RIMTransfer, RIMTransfer_sequence);
return offset;
}
static int
dissect_s1ap_RepetitionPeriod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_UE_RLF_Report_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 691 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
if (g_s1ap_dissect_container) {
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_UE_RLF_Report_Container);
dissect_lte_rrc_RLF_Report_r9_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
}
return offset;
}
static int
dissect_s1ap_UE_RLF_Report_Container_for_extended_bands(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 705 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
if (g_s1ap_dissect_container) {
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_UE_RLF_Report_Container_for_extended_bands);
dissect_lte_rrc_RLF_Report_v9e0_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
}
return offset;
}
static int
dissect_s1ap_RLFReportInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_RLFReportInformation, RLFReportInformation_sequence);
return offset;
}
static int
dissect_s1ap_RRC_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 498 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
if (g_s1ap_dissect_container) {
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_RRCContainer);
switch(s1ap_data->message_type){
case INITIATING_MESSAGE:
if ((s1ap_is_nbiot_ue(actx->pinfo) && (g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_AUTOMATIC)) ||
(g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_NBIOT)) {
dissect_lte_rrc_HandoverPreparationInformation_NB_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
} else {
dissect_lte_rrc_HandoverPreparationInformation_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
}
break;
case SUCCESSFUL_OUTCOME:
dissect_lte_rrc_HandoverCommand_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
break;
default:
break;
}
}
return offset;
}
static int
dissect_s1ap_RRC_Establishment_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 3, NULL);
return offset;
}
static int
dissect_s1ap_ECGIListForRestart(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ECGIListForRestart, ECGIListForRestart_sequence_of,
1, maxnoofCellsforRestart, FALSE);
return offset;
}
static int
dissect_s1ap_Routing_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_SecurityKey(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
256, 256, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_INTEGER_0_7(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_SecurityContext(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_SecurityContext, SecurityContext_sequence);
return offset;
}
static int
dissect_s1ap_SerialNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 850 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, &parameter_tvb, NULL);
if (parameter_tvb) {
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_SerialNumber);
proto_tree_add_item(subtree, hf_s1ap_SerialNumber_gs, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_s1ap_SerialNumber_msg_code, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_s1ap_SerialNumber_upd_nb, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_s1ap_SONInformationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 3, NULL);
return offset;
}
static int
dissect_s1ap_X2TNLConfigurationInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_X2TNLConfigurationInfo, X2TNLConfigurationInfo_sequence);
return offset;
}
static int
dissect_s1ap_SONInformationReply(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_SONInformationReply, SONInformationReply_sequence);
return offset;
}
static int
dissect_s1ap_SONInformation_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_ProtocolIE_SingleContainer(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_SONInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_SONInformation, SONInformation_choice,
NULL);
return offset;
}
static int
dissect_s1ap_SONInformationReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_SONInformationReport, SONInformationReport_choice,
NULL);
return offset;
}
static int
dissect_s1ap_TargeteNB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TargeteNB_ID, TargeteNB_ID_sequence);
return offset;
}
static int
dissect_s1ap_SourceeNB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_SourceeNB_ID, SourceeNB_ID_sequence);
return offset;
}
static int
dissect_s1ap_SONConfigurationTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_SONConfigurationTransfer, SONConfigurationTransfer_sequence);
return offset;
}
static int
dissect_s1ap_StratumLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, TRUE);
return offset;
}
static int
dissect_s1ap_SynchronisationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_SynchronisationInformation, SynchronisationInformation_sequence);
return offset;
}
static int
dissect_s1ap_Source_ToTarget_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 381 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if ((g_s1ap_dissect_container)&&(parameter_tvb) && (tvb_reported_length(parameter_tvb) > 0)) {
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
col_set_writable(actx->pinfo->cinfo, COL_INFO, FALSE);
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_ToTargetTransparentContainer);
switch(s1ap_data->handover_type_value){
case 0:
dissect_SourceeNB_ToTargeteNB_TransparentContainer_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
break;
case 1:
dissect_ranap_SourceRNC_ToTargetRNC_TransparentContainer_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
break;
case 2:
de_bssgp_source_BSS_to_target_BSS_transp_cont(parameter_tvb, subtree, actx->pinfo, 0, tvb_reported_length(parameter_tvb), NULL, 0);
break;
case 3:
break;
case 4:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
col_set_writable(actx->pinfo->cinfo, COL_INFO, TRUE);
}
return offset;
}
static int
dissect_s1ap_SRVCCOperationNotPossible(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_SRVCCOperationPossible(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_SRVCCHOIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_SubscriberProfileIDforRFP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 256U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_UE_HistoryInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_UE_HistoryInformation, UE_HistoryInformation_sequence_of,
1, maxnoofCells, FALSE);
return offset;
}
static int
dissect_s1ap_SourceeNB_ToTargeteNB_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_SourceeNB_ToTargeteNB_TransparentContainer, SourceeNB_ToTargeteNB_TransparentContainer_sequence);
return offset;
}
static int
dissect_s1ap_ServedPLMNs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ServedPLMNs, ServedPLMNs_sequence_of,
1, maxnoofPLMNsPerMME, FALSE);
return offset;
}
static int
dissect_s1ap_ServedGroupIDs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ServedGroupIDs, ServedGroupIDs_sequence_of,
1, maxnoofGroupIDs, FALSE);
return offset;
}
static int
dissect_s1ap_ServedMMECs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ServedMMECs, ServedMMECs_sequence_of,
1, maxnoofMMECs, FALSE);
return offset;
}
static int
dissect_s1ap_ServedGUMMEIsItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ServedGUMMEIsItem, ServedGUMMEIsItem_sequence);
return offset;
}
static int
dissect_s1ap_ServedGUMMEIs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ServedGUMMEIs, ServedGUMMEIs_sequence_of,
1, maxnoofRATs, FALSE);
return offset;
}
static int
dissect_s1ap_SupportedTAs_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1028 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
if (!PINFO_FD_VISITED(actx->pinfo) &&
(s1ap_data->message_type == INITIATING_MESSAGE) &&
((s1ap_data->procedure_code == id_S1Setup) ||
(s1ap_data->procedure_code == id_ENBConfigurationUpdate))) {
s1ap_data->supported_ta = wmem_new0(wmem_packet_scope(), struct s1ap_supported_ta);
s1ap_data->supported_ta->plmn = wmem_array_new(wmem_packet_scope(), sizeof(guint32));
}
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_SupportedTAs_Item, SupportedTAs_Item_sequence);
#line 1039 "./asn1/s1ap/s1ap.cnf"
s1ap_data->supported_ta = NULL;
return offset;
}
static int
dissect_s1ap_SupportedTAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_SupportedTAs, SupportedTAs_sequence_of,
1, maxnoofTACs, FALSE);
return offset;
}
static int
dissect_s1ap_SynchronisationStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_TimeSynchronisationInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TimeSynchronisationInfo, TimeSynchronisationInfo_sequence);
return offset;
}
static int
dissect_s1ap_S_TMSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_S_TMSI, S_TMSI_sequence);
return offset;
}
static int
dissect_s1ap_TAIListforWarning(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAIListforWarning, TAIListforWarning_sequence_of,
1, maxnoofTAIforWarning, FALSE);
return offset;
}
static int
dissect_s1ap_TargetID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_TargetID, TargetID_choice,
NULL);
return offset;
}
static int
dissect_s1ap_TargeteNB_ToSourceeNB_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TargeteNB_ToSourceeNB_TransparentContainer, TargeteNB_ToSourceeNB_TransparentContainer_sequence);
return offset;
}
static int
dissect_s1ap_Target_ToSource_TransparentContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 439 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if ((g_s1ap_dissect_container)&&(parameter_tvb) && (tvb_reported_length(parameter_tvb) > 0)) {
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_ToSourceTransparentContainer);
switch(s1ap_data->handover_type_value){
case 0:
dissect_TargeteNB_ToSourceeNB_TransparentContainer_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
break;
case 1:
dissect_ranap_TargetRNC_ToSourceRNC_TransparentContainer_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
break;
case 2:
de_bssgp_target_BSS_to_source_BSS_transp_cont(parameter_tvb, subtree, actx->pinfo, 0, tvb_reported_length(parameter_tvb), NULL, 0);
break;
case 3:
break;
case 4:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
return offset;
}
static int
dissect_s1ap_TimeToWait(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_Time_UE_StayedInCell_EnhancedGranularity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 40950U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_TransportInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TransportInformation, TransportInformation_sequence);
return offset;
}
static int
dissect_s1ap_E_UTRAN_Trace_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 745 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_E_UTRAN_Trace_ID);
dissect_e212_mcc_mnc(parameter_tvb, actx->pinfo, subtree, 0, E212_NONE, FALSE);
proto_tree_add_item(subtree, hf_s1ap_E_UTRAN_Trace_ID_TraceID, parameter_tvb, 3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_s1ap_E_UTRAN_Trace_ID_TraceRecordingSessionReference, parameter_tvb, 6, 2, ENC_BIG_ENDIAN);
return offset;
}
static int
dissect_s1ap_TraceDepth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_TraceActivation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TraceActivation, TraceActivation_sequence);
return offset;
}
static int
dissect_s1ap_TrafficLoadReductionIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 99U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_TunnelInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TunnelInformation, TunnelInformation_sequence);
return offset;
}
static int
dissect_s1ap_TAIListForRestart(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAIListForRestart, TAIListForRestart_sequence_of,
1, maxnoofRestartTAIs, FALSE);
return offset;
}
static int
dissect_s1ap_UEAggregateMaximumBitrate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEAggregateMaximumBitrate, UEAggregateMaximumBitrate_sequence);
return offset;
}
static int
dissect_s1ap_UE_RetentionInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_UE_S1AP_ID_pair(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UE_S1AP_ID_pair, UE_S1AP_ID_pair_sequence);
return offset;
}
static int
dissect_s1ap_UE_S1AP_IDs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_UE_S1AP_IDs, UE_S1AP_IDs_choice,
NULL);
return offset;
}
static int
dissect_s1ap_UE_associatedLogicalS1_ConnectionItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UE_associatedLogicalS1_ConnectionItem, UE_associatedLogicalS1_ConnectionItem_sequence);
return offset;
}
static int
dissect_s1ap_UEIdentityIndexValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
10, 10, FALSE, NULL, NULL);
return offset;
}
static int
dissect_s1ap_UE_HistoryInformationFromTheUE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 561 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
if (g_s1ap_dissect_container) {
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_UE_HistoryInformationFromTheUE);
dissect_lte_rrc_VisitedCellInfoList_r12_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
}
return offset;
}
static int
dissect_s1ap_UEPagingID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEPagingID, UEPagingID_choice,
NULL);
return offset;
}
static int
dissect_s1ap_UERadioCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 574 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
if (g_s1ap_dissect_container) {
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_UERadioCapability);
if ((s1ap_is_nbiot_ue(actx->pinfo) && (g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_AUTOMATIC)) ||
(g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_NBIOT)) {
dissect_lte_rrc_UERadioAccessCapabilityInformation_NB_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
} else {
dissect_lte_rrc_UERadioAccessCapabilityInformation_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
}
}
return offset;
}
static int
dissect_s1ap_UERadioCapabilityForPaging(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 651 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
if (g_s1ap_dissect_container) {
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_UERadioPagingInformation);
if ((s1ap_is_nbiot_ue(actx->pinfo) && (g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_AUTOMATIC)) ||
(g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_NBIOT)) {
dissect_lte_rrc_UERadioPagingInformation_NB_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
} else {
dissect_lte_rrc_UERadioPagingInformation_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
}
}
return offset;
}
static int
dissect_s1ap_UESecurityCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UESecurityCapabilities, UESecurityCapabilities_sequence);
return offset;
}
static int
dissect_s1ap_UE_Usage_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_UserLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UserLocationInformation, UserLocationInformation_sequence);
return offset;
}
static int
dissect_s1ap_UEUserPlaneCIoTSupportIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_VoiceSupportMatchIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_WarningAreaList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_WarningAreaList, WarningAreaList_choice,
NULL);
return offset;
}
static int
dissect_s1ap_WarningType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 863 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, &parameter_tvb);
if (parameter_tvb) {
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_WarningType);
proto_tree_add_item(subtree, hf_s1ap_WarningType_value, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_s1ap_WarningType_emergency_user_alert, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_s1ap_WarningType_popup, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_s1ap_WarningSecurityInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
50, 50, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_WarningMessageContents(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 884 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 9600, FALSE, &parameter_tvb);
if (parameter_tvb) {
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_WarningMessageContents);
dissect_s1ap_warningMessageContents(parameter_tvb, subtree, actx->pinfo, s1ap_data->data_coding_scheme);
}
return offset;
}
static int
dissect_s1ap_ENBX2GTPTLAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBX2GTPTLAs, ENBX2GTPTLAs_sequence_of,
1, maxnoofeNBX2GTPTLAs, FALSE);
return offset;
}
static int
dissect_s1ap_ENBX2ExtTLA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBX2ExtTLA, ENBX2ExtTLA_sequence);
return offset;
}
static int
dissect_s1ap_ENBX2ExtTLAs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBX2ExtTLAs, ENBX2ExtTLAs_sequence_of,
1, maxnoofeNBX2ExtTLAs, FALSE);
return offset;
}
static int
dissect_s1ap_ENBIndirectX2TransportLayerAddresses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBIndirectX2TransportLayerAddresses, ENBIndirectX2TransportLayerAddresses_sequence_of,
1, maxnoofeNBX2TLAs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RAB_IE_ContainerList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 170 "./asn1/s1ap/s1ap.cnf"
asn1_stack_frame_push(actx, "ProtocolIE-ContainerList");
asn1_param_push_integer(actx, 1);
asn1_param_push_integer(actx, maxnoofE_RABs);
offset = dissect_s1ap_ProtocolIE_ContainerList(tvb, offset, actx, tree, hf_index);
asn1_stack_frame_pop(actx, "ProtocolIE-ContainerList");
return offset;
}
static int
dissect_s1ap_HandoverRequired(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 361 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
s1ap_data->handover_type_value = 0;
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverRequired");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverRequired, HandoverRequired_sequence);
return offset;
}
static int
dissect_s1ap_HandoverCommand(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 364 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
s1ap_data->handover_type_value = 0;
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverCommand");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverCommand, HandoverCommand_sequence);
return offset;
}
static int
dissect_s1ap_E_RABSubjecttoDataForwardingList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABDataForwardingItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABDataForwardingItem, E_RABDataForwardingItem_sequence);
return offset;
}
static int
dissect_s1ap_HandoverPreparationFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1765 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverPreparationFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverPreparationFailure, HandoverPreparationFailure_sequence);
return offset;
}
static int
dissect_s1ap_HandoverRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 367 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
s1ap_data->handover_type_value = 0;
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverRequest, HandoverRequest_sequence);
return offset;
}
static int
dissect_s1ap_E_RABToBeSetupListHOReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABToBeSetupItemHOReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeSetupItemHOReq, E_RABToBeSetupItemHOReq_sequence);
return offset;
}
static int
dissect_s1ap_HandoverRequestAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 370 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
s1ap_data->handover_type_value = 0;
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverRequestAcknowledge");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverRequestAcknowledge, HandoverRequestAcknowledge_sequence);
return offset;
}
static int
dissect_s1ap_E_RABAdmittedList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABAdmittedItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABAdmittedItem, E_RABAdmittedItem_sequence);
return offset;
}
static int
dissect_s1ap_E_RABFailedtoSetupListHOReqAck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABFailedToSetupItemHOReqAck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABFailedToSetupItemHOReqAck, E_RABFailedToSetupItemHOReqAck_sequence);
return offset;
}
static int
dissect_s1ap_HandoverFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1771 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverFailure, HandoverFailure_sequence);
return offset;
}
static int
dissect_s1ap_HandoverNotify(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1773 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverNotify");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverNotify, HandoverNotify_sequence);
return offset;
}
static int
dissect_s1ap_PathSwitchRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1775 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "PathSwitchRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_PathSwitchRequest, PathSwitchRequest_sequence);
return offset;
}
static int
dissect_s1ap_E_RABToBeSwitchedDLList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABToBeSwitchedDLItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeSwitchedDLItem, E_RABToBeSwitchedDLItem_sequence);
return offset;
}
static int
dissect_s1ap_PathSwitchRequestAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1777 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "PathSwitchRequestAcknowledge");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_PathSwitchRequestAcknowledge, PathSwitchRequestAcknowledge_sequence);
return offset;
}
static int
dissect_s1ap_E_RABToBeSwitchedULList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABToBeSwitchedULItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeSwitchedULItem, E_RABToBeSwitchedULItem_sequence);
return offset;
}
static int
dissect_s1ap_PathSwitchRequestFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1779 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "PathSwitchRequestFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_PathSwitchRequestFailure, PathSwitchRequestFailure_sequence);
return offset;
}
static int
dissect_s1ap_HandoverCancel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1781 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverCancel");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverCancel, HandoverCancel_sequence);
return offset;
}
static int
dissect_s1ap_HandoverCancelAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1783 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverCancelAcknowledge");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HandoverCancelAcknowledge, HandoverCancelAcknowledge_sequence);
return offset;
}
static int
dissect_s1ap_E_RABSetupRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1785 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABSetupRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABSetupRequest, E_RABSetupRequest_sequence);
return offset;
}
static int
dissect_s1ap_E_RABToBeSetupListBearerSUReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeSetupListBearerSUReq, E_RABToBeSetupListBearerSUReq_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABToBeSetupItemBearerSUReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeSetupItemBearerSUReq, E_RABToBeSetupItemBearerSUReq_sequence);
return offset;
}
static int
dissect_s1ap_E_RABSetupResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1787 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABSetupResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABSetupResponse, E_RABSetupResponse_sequence);
return offset;
}
static int
dissect_s1ap_E_RABSetupListBearerSURes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABSetupListBearerSURes, E_RABSetupListBearerSURes_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABSetupItemBearerSURes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABSetupItemBearerSURes, E_RABSetupItemBearerSURes_sequence);
return offset;
}
static int
dissect_s1ap_E_RABModifyRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1789 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABModifyRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABModifyRequest, E_RABModifyRequest_sequence);
return offset;
}
static int
dissect_s1ap_E_RABToBeModifiedListBearerModReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeModifiedListBearerModReq, E_RABToBeModifiedListBearerModReq_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABToBeModifiedItemBearerModReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeModifiedItemBearerModReq, E_RABToBeModifiedItemBearerModReq_sequence);
return offset;
}
static int
dissect_s1ap_E_RABModifyResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1791 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABModifyResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABModifyResponse, E_RABModifyResponse_sequence);
return offset;
}
static int
dissect_s1ap_E_RABModifyListBearerModRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABModifyListBearerModRes, E_RABModifyListBearerModRes_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABModifyItemBearerModRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABModifyItemBearerModRes, E_RABModifyItemBearerModRes_sequence);
return offset;
}
static int
dissect_s1ap_E_RABReleaseCommand(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1793 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABReleaseCommand");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABReleaseCommand, E_RABReleaseCommand_sequence);
return offset;
}
static int
dissect_s1ap_E_RABReleaseResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1795 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABReleaseResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABReleaseResponse, E_RABReleaseResponse_sequence);
return offset;
}
static int
dissect_s1ap_E_RABReleaseListBearerRelComp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABReleaseListBearerRelComp, E_RABReleaseListBearerRelComp_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABReleaseItemBearerRelComp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABReleaseItemBearerRelComp, E_RABReleaseItemBearerRelComp_sequence);
return offset;
}
static int
dissect_s1ap_E_RABReleaseIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1797 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABReleaseIndication");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABReleaseIndication, E_RABReleaseIndication_sequence);
return offset;
}
static int
dissect_s1ap_InitialContextSetupRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1799 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "InitialContextSetupRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_InitialContextSetupRequest, InitialContextSetupRequest_sequence);
return offset;
}
static int
dissect_s1ap_E_RABToBeSetupListCtxtSUReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeSetupListCtxtSUReq, E_RABToBeSetupListCtxtSUReq_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABToBeSetupItemCtxtSUReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeSetupItemCtxtSUReq, E_RABToBeSetupItemCtxtSUReq_sequence);
return offset;
}
static int
dissect_s1ap_InitialContextSetupResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1801 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "InitialContextSetupResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_InitialContextSetupResponse, InitialContextSetupResponse_sequence);
return offset;
}
static int
dissect_s1ap_E_RABSetupListCtxtSURes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABSetupListCtxtSURes, E_RABSetupListCtxtSURes_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABSetupItemCtxtSURes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABSetupItemCtxtSURes, E_RABSetupItemCtxtSURes_sequence);
return offset;
}
static int
dissect_s1ap_InitialContextSetupFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1803 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "InitialContextSetupFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_InitialContextSetupFailure, InitialContextSetupFailure_sequence);
return offset;
}
static int
dissect_s1ap_Paging(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1805 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "Paging");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_Paging, Paging_sequence);
return offset;
}
static int
dissect_s1ap_TAIList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAIList, TAIList_sequence_of,
1, maxnoofTAIs, FALSE);
return offset;
}
static int
dissect_s1ap_TAIItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TAIItem, TAIItem_sequence);
return offset;
}
static int
dissect_s1ap_UEContextReleaseRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1807 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextReleaseRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextReleaseRequest, UEContextReleaseRequest_sequence);
return offset;
}
static int
dissect_s1ap_UEContextReleaseCommand(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1809 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextReleaseCommand");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextReleaseCommand, UEContextReleaseCommand_sequence);
return offset;
}
static int
dissect_s1ap_UEContextReleaseComplete(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1811 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextReleaseComplete");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextReleaseComplete, UEContextReleaseComplete_sequence);
return offset;
}
static int
dissect_s1ap_UEContextModificationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1813 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextModificationRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextModificationRequest, UEContextModificationRequest_sequence);
return offset;
}
static int
dissect_s1ap_UEContextModificationResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1815 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextModificationResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextModificationResponse, UEContextModificationResponse_sequence);
return offset;
}
static int
dissect_s1ap_UEContextModificationFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1817 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextModificationFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextModificationFailure, UEContextModificationFailure_sequence);
return offset;
}
static int
dissect_s1ap_UERadioCapabilityMatchRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1819 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UERadioCapabilityMatchRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UERadioCapabilityMatchRequest, UERadioCapabilityMatchRequest_sequence);
return offset;
}
static int
dissect_s1ap_UERadioCapabilityMatchResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1821 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UERadioCapabilityMatchResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UERadioCapabilityMatchResponse, UERadioCapabilityMatchResponse_sequence);
return offset;
}
static int
dissect_s1ap_DownlinkNASTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 348 "./asn1/s1ap/s1ap.cnf"
actx->pinfo->link_dir=P2P_DIR_DL;
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "DownlinkNASTransport");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_DownlinkNASTransport, DownlinkNASTransport_sequence);
return offset;
}
static int
dissect_s1ap_InitialUEMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 344 "./asn1/s1ap/s1ap.cnf"
actx->pinfo->link_dir=P2P_DIR_UL;
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "InitialUEMessage");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_InitialUEMessage, InitialUEMessage_sequence);
return offset;
}
static int
dissect_s1ap_UplinkNASTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 352 "./asn1/s1ap/s1ap.cnf"
actx->pinfo->link_dir=P2P_DIR_UL;
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UplinkNASTransport");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UplinkNASTransport, UplinkNASTransport_sequence);
return offset;
}
static int
dissect_s1ap_NASNonDeliveryIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1829 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "NASNonDeliveryIndication");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_NASNonDeliveryIndication, NASNonDeliveryIndication_sequence);
return offset;
}
static int
dissect_s1ap_RerouteNASRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1831 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "RerouteNASRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_RerouteNASRequest, RerouteNASRequest_sequence);
return offset;
}
static int
dissect_s1ap_S1_Message(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 734 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_S1_Message);
col_set_fence(actx->pinfo->cinfo, COL_INFO);
call_dissector(s1ap_handle, parameter_tvb, actx->pinfo, subtree);
return offset;
}
static int
dissect_s1ap_Reset(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1833 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "Reset");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_Reset, Reset_sequence);
return offset;
}
static int
dissect_s1ap_ResetAll(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_UE_associatedLogicalS1_ConnectionListRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_UE_associatedLogicalS1_ConnectionListRes, UE_associatedLogicalS1_ConnectionListRes_sequence_of,
1, maxnoofIndividualS1ConnectionsToReset, FALSE);
return offset;
}
static int
dissect_s1ap_ResetType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_ResetType, ResetType_choice,
NULL);
return offset;
}
static int
dissect_s1ap_ResetAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1835 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ResetAcknowledge");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ResetAcknowledge, ResetAcknowledge_sequence);
return offset;
}
static int
dissect_s1ap_UE_associatedLogicalS1_ConnectionListResAck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_UE_associatedLogicalS1_ConnectionListResAck, UE_associatedLogicalS1_ConnectionListResAck_sequence_of,
1, maxnoofIndividualS1ConnectionsToReset, FALSE);
return offset;
}
static int
dissect_s1ap_ErrorIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ErrorIndication, ErrorIndication_sequence);
return offset;
}
static int
dissect_s1ap_S1SetupRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1839 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "S1SetupRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_S1SetupRequest, S1SetupRequest_sequence);
return offset;
}
static int
dissect_s1ap_S1SetupResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1841 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "S1SetupResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_S1SetupResponse, S1SetupResponse_sequence);
return offset;
}
static int
dissect_s1ap_S1SetupFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1843 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "S1SetupFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_S1SetupFailure, S1SetupFailure_sequence);
return offset;
}
static int
dissect_s1ap_ENBConfigurationUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1845 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBConfigurationUpdate");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBConfigurationUpdate, ENBConfigurationUpdate_sequence);
return offset;
}
static int
dissect_s1ap_ENBConfigurationUpdateAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1847 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBConfigurationUpdateAcknowledge");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBConfigurationUpdateAcknowledge, ENBConfigurationUpdateAcknowledge_sequence);
return offset;
}
static int
dissect_s1ap_ENBConfigurationUpdateFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1849 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBConfigurationUpdateFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBConfigurationUpdateFailure, ENBConfigurationUpdateFailure_sequence);
return offset;
}
static int
dissect_s1ap_MMEConfigurationUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1851 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MMEConfigurationUpdate");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MMEConfigurationUpdate, MMEConfigurationUpdate_sequence);
return offset;
}
static int
dissect_s1ap_MMEConfigurationUpdateAcknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1853 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MMEConfigurationUpdateAcknowledge");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MMEConfigurationUpdateAcknowledge, MMEConfigurationUpdateAcknowledge_sequence);
return offset;
}
static int
dissect_s1ap_MMEConfigurationUpdateFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1855 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MMEConfigurationUpdateFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MMEConfigurationUpdateFailure, MMEConfigurationUpdateFailure_sequence);
return offset;
}
static int
dissect_s1ap_DownlinkS1cdma2000tunnelling(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1857 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "DownlinkS1cdma2000tunnelling");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_DownlinkS1cdma2000tunnelling, DownlinkS1cdma2000tunnelling_sequence);
return offset;
}
static int
dissect_s1ap_UplinkS1cdma2000tunnelling(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1859 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UplinkS1cdma2000tunnelling");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UplinkS1cdma2000tunnelling, UplinkS1cdma2000tunnelling_sequence);
return offset;
}
static int
dissect_s1ap_UECapabilityInfoIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1861 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UECapabilityInfoIndication");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UECapabilityInfoIndication, UECapabilityInfoIndication_sequence);
return offset;
}
static int
dissect_s1ap_ENBStatusTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1863 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBStatusTransfer");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBStatusTransfer, ENBStatusTransfer_sequence);
return offset;
}
static int
dissect_s1ap_MMEStatusTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1865 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MMEStatusTransfer");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MMEStatusTransfer, MMEStatusTransfer_sequence);
return offset;
}
static int
dissect_s1ap_TraceStart(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1867 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "TraceStart");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TraceStart, TraceStart_sequence);
return offset;
}
static int
dissect_s1ap_TraceFailureIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1869 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "TraceFailureIndication");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TraceFailureIndication, TraceFailureIndication_sequence);
return offset;
}
static int
dissect_s1ap_DeactivateTrace(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1871 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "DeactivateTrace");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_DeactivateTrace, DeactivateTrace_sequence);
return offset;
}
static int
dissect_s1ap_CellTrafficTrace(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1873 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "CellTrafficTrace");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellTrafficTrace, CellTrafficTrace_sequence);
return offset;
}
static int
dissect_s1ap_LocationReportingControl(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1875 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "LocationReportingControl");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_LocationReportingControl, LocationReportingControl_sequence);
return offset;
}
static int
dissect_s1ap_LocationReportingFailureIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1877 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "LocationReportingFailureIndication");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_LocationReportingFailureIndication, LocationReportingFailureIndication_sequence);
return offset;
}
static int
dissect_s1ap_LocationReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1879 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "LocationReport");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_LocationReport, LocationReport_sequence);
return offset;
}
static int
dissect_s1ap_OverloadStart(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1881 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "OverloadStart");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_OverloadStart, OverloadStart_sequence);
return offset;
}
static int
dissect_s1ap_OverloadStop(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1883 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "OverloadStop");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_OverloadStop, OverloadStop_sequence);
return offset;
}
static int
dissect_s1ap_WriteReplaceWarningRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1885 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "WriteReplaceWarningRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_WriteReplaceWarningRequest, WriteReplaceWarningRequest_sequence);
return offset;
}
static int
dissect_s1ap_WriteReplaceWarningResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1887 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "WriteReplaceWarningResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_WriteReplaceWarningResponse, WriteReplaceWarningResponse_sequence);
return offset;
}
static int
dissect_s1ap_ENBDirectInformationTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1889 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBDirectInformationTransfer");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBDirectInformationTransfer, ENBDirectInformationTransfer_sequence);
return offset;
}
static int
dissect_s1ap_Inter_SystemInformationTransferType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_Inter_SystemInformationTransferType, Inter_SystemInformationTransferType_choice,
NULL);
return offset;
}
static int
dissect_s1ap_MMEDirectInformationTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1891 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MMEDirectInformationTransfer");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MMEDirectInformationTransfer, MMEDirectInformationTransfer_sequence);
return offset;
}
static int
dissect_s1ap_ENBConfigurationTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1893 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBConfigurationTransfer");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ENBConfigurationTransfer, ENBConfigurationTransfer_sequence);
return offset;
}
static int
dissect_s1ap_MMEConfigurationTransfer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1895 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MMEConfigurationTransfer");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MMEConfigurationTransfer, MMEConfigurationTransfer_sequence);
return offset;
}
static int
dissect_s1ap_PrivateMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1897 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "PrivateMessage");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_PrivateMessage, PrivateMessage_sequence);
return offset;
}
static int
dissect_s1ap_KillRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1899 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "KillRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_KillRequest, KillRequest_sequence);
return offset;
}
static int
dissect_s1ap_KillResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1901 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "KillResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_KillResponse, KillResponse_sequence);
return offset;
}
static int
dissect_s1ap_PWSRestartIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1903 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "PWSRestartIndication");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_PWSRestartIndication, PWSRestartIndication_sequence);
return offset;
}
static int
dissect_s1ap_PWSFailureIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1905 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "PWSFailureIndication");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_PWSFailureIndication, PWSFailureIndication_sequence);
return offset;
}
static int
dissect_s1ap_DownlinkUEAssociatedLPPaTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1907 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "DownlinkUEAssociatedLPPaTransport");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_DownlinkUEAssociatedLPPaTransport, DownlinkUEAssociatedLPPaTransport_sequence);
return offset;
}
static int
dissect_s1ap_UplinkUEAssociatedLPPaTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1909 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UplinkUEAssociatedLPPaTransport");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UplinkUEAssociatedLPPaTransport, UplinkUEAssociatedLPPaTransport_sequence);
return offset;
}
static int
dissect_s1ap_DownlinkNonUEAssociatedLPPaTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1911 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "DownlinkNonUEAssociatedLPPaTransport");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_DownlinkNonUEAssociatedLPPaTransport, DownlinkNonUEAssociatedLPPaTransport_sequence);
return offset;
}
static int
dissect_s1ap_UplinkNonUEAssociatedLPPaTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1913 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UplinkNonUEAssociatedLPPaTransport");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UplinkNonUEAssociatedLPPaTransport, UplinkNonUEAssociatedLPPaTransport_sequence);
return offset;
}
static int
dissect_s1ap_E_RABModificationIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1915 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABModificationIndication");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABModificationIndication, E_RABModificationIndication_sequence);
return offset;
}
static int
dissect_s1ap_E_RABToBeModifiedListBearerModInd(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABToBeModifiedItemBearerModInd(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABToBeModifiedItemBearerModInd, E_RABToBeModifiedItemBearerModInd_sequence);
return offset;
}
static int
dissect_s1ap_E_RABNotToBeModifiedListBearerModInd(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABNotToBeModifiedItemBearerModInd(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABNotToBeModifiedItemBearerModInd, E_RABNotToBeModifiedItemBearerModInd_sequence);
return offset;
}
static int
dissect_s1ap_CSGMembershipInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CSGMembershipInfo, CSGMembershipInfo_sequence);
return offset;
}
static int
dissect_s1ap_E_RABModificationConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1917 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABModificationConfirm");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABModificationConfirm, E_RABModificationConfirm_sequence);
return offset;
}
static int
dissect_s1ap_E_RABModifyListBearerModConf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABModifyListBearerModConf, E_RABModifyListBearerModConf_sequence_of,
1, maxnoofE_RABs, FALSE);
return offset;
}
static int
dissect_s1ap_E_RABModifyItemBearerModConf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABModifyItemBearerModConf, E_RABModifyItemBearerModConf_sequence);
return offset;
}
static int
dissect_s1ap_UEContextModificationIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1919 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextModificationIndication");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextModificationIndication, UEContextModificationIndication_sequence);
return offset;
}
static int
dissect_s1ap_UEContextModificationConfirm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1921 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextModificationConfirm");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextModificationConfirm, UEContextModificationConfirm_sequence);
return offset;
}
static int
dissect_s1ap_UEContextSuspendRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1923 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextSuspendRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextSuspendRequest, UEContextSuspendRequest_sequence);
return offset;
}
static int
dissect_s1ap_UEContextSuspendResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1925 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextSuspendResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextSuspendResponse, UEContextSuspendResponse_sequence);
return offset;
}
static int
dissect_s1ap_UEContextResumeRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1927 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextResumeRequest");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextResumeRequest, UEContextResumeRequest_sequence);
return offset;
}
static int
dissect_s1ap_E_RABFailedToResumeListResumeReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABFailedToResumeItemResumeReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABFailedToResumeItemResumeReq, E_RABFailedToResumeItemResumeReq_sequence);
return offset;
}
static int
dissect_s1ap_UEContextResumeResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1929 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextResumeResponse");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextResumeResponse, UEContextResumeResponse_sequence);
return offset;
}
static int
dissect_s1ap_E_RABFailedToResumeListResumeRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_s1ap_E_RABFailedToResumeItemResumeRes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_E_RABFailedToResumeItemResumeRes, E_RABFailedToResumeItemResumeRes_sequence);
return offset;
}
static int
dissect_s1ap_UEContextResumeFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1931 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextResumeFailure");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UEContextResumeFailure, UEContextResumeFailure_sequence);
return offset;
}
static int
dissect_s1ap_ConnectionEstablishmentIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1933 "./asn1/s1ap/s1ap.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ConnectionEstablishmentIndication");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ConnectionEstablishmentIndication, ConnectionEstablishmentIndication_sequence);
return offset;
}
static int
dissect_s1ap_InitiatingMessage_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 122 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
s1ap_data->message_type = INITIATING_MESSAGE;
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_InitiatingMessageValue);
return offset;
}
static int
dissect_s1ap_InitiatingMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_InitiatingMessage, InitiatingMessage_sequence);
return offset;
}
static int
dissect_s1ap_SuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 126 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
s1ap_data->message_type = SUCCESSFUL_OUTCOME;
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_SuccessfulOutcomeValue);
return offset;
}
static int
dissect_s1ap_SuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_SuccessfulOutcome, SuccessfulOutcome_sequence);
return offset;
}
static int
dissect_s1ap_UnsuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 130 "./asn1/s1ap/s1ap.cnf"
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(actx->pinfo);
s1ap_data->message_type = UNSUCCESSFUL_OUTCOME;
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_UnsuccessfulOutcomeValue);
return offset;
}
static int
dissect_s1ap_UnsuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_UnsuccessfulOutcome, UnsuccessfulOutcome_sequence);
return offset;
}
static int
dissect_s1ap_S1AP_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_S1AP_PDU, S1AP_PDU_choice,
NULL);
return offset;
}
static int
dissect_s1ap_SONtransferApplicationIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 6, NULL);
return offset;
}
static int
dissect_s1ap_OCTET_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_EHRPD_Sector_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_IRAT_Cell_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_IRAT_Cell_ID, IRAT_Cell_ID_choice,
NULL);
return offset;
}
static int
dissect_s1ap_RequestedCellList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_RequestedCellList, RequestedCellList_sequence_of,
1, maxnoofIRATReportingCells, FALSE);
return offset;
}
static int
dissect_s1ap_MultiCellLoadReportingRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_MultiCellLoadReportingRequest, MultiCellLoadReportingRequest_sequence);
return offset;
}
static int
dissect_s1ap_NumberOfMeasurementReportingLevels(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_EventTriggeredCellLoadReportingRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EventTriggeredCellLoadReportingRequest, EventTriggeredCellLoadReportingRequest_sequence);
return offset;
}
static int
dissect_s1ap_HoType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_HoReportType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 1, NULL);
return offset;
}
static int
dissect_s1ap_CandidateCellList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CandidateCellList, CandidateCellList_sequence_of,
1, maxnoofcandidateCells, FALSE);
return offset;
}
static int
dissect_s1ap_INTEGER_0_503(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 503U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_CandidatePCI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CandidatePCI, CandidatePCI_sequence);
return offset;
}
static int
dissect_s1ap_CandidatePCIList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CandidatePCIList, CandidatePCIList_sequence_of,
1, maxnoofcandidateCells, FALSE);
return offset;
}
static int
dissect_s1ap_HOReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_HOReport, HOReport_sequence);
return offset;
}
static int
dissect_s1ap_CellsToActivateList_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellsToActivateList_Item, CellsToActivateList_Item_sequence);
return offset;
}
static int
dissect_s1ap_CellsToActivateList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellsToActivateList, CellsToActivateList_sequence_of,
1, maxnoofCellineNB, FALSE);
return offset;
}
static int
dissect_s1ap_INTEGER_1_60(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 60U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_CellActivationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellActivationRequest, CellActivationRequest_sequence);
return offset;
}
static int
dissect_s1ap_NotifyFlag(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_NotificationCellList_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_NotificationCellList_Item, NotificationCellList_Item_sequence);
return offset;
}
static int
dissect_s1ap_NotificationCellList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_NotificationCellList, NotificationCellList_sequence_of,
1, maxnoofCellineNB, FALSE);
return offset;
}
static int
dissect_s1ap_CellStateIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellStateIndication, CellStateIndication_sequence);
return offset;
}
static int
dissect_s1ap_T_uERLFReportContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 719 "./asn1/s1ap/s1ap.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
if (g_s1ap_dissect_container) {
subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_UE_RLF_Report_Container);
dissect_lte_rrc_RLF_Report_r9_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
}
return offset;
}
static int
dissect_s1ap_TooEarlyInterRATHOReportReportFromEUTRAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_TooEarlyInterRATHOReportReportFromEUTRAN, TooEarlyInterRATHOReportReportFromEUTRAN_sequence);
return offset;
}
static int
dissect_s1ap_FailureEventReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_FailureEventReport, FailureEventReport_choice,
NULL);
return offset;
}
int
dissect_s1ap_SONtransferRequestContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_SONtransferRequestContainer, SONtransferRequestContainer_choice,
NULL);
return offset;
}
static int
dissect_s1ap_CompositeAvailableCapacityGroup(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_s1ap_EUTRANcellLoadReportingResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EUTRANcellLoadReportingResponse, EUTRANcellLoadReportingResponse_sequence);
return offset;
}
static int
dissect_s1ap_EHRPDSectorCapacityClassValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 100U, NULL, TRUE);
return offset;
}
static int
dissect_s1ap_EHRPDCapacityValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_s1ap_EHRPDCompositeAvailableCapacity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EHRPDCompositeAvailableCapacity, EHRPDCompositeAvailableCapacity_sequence);
return offset;
}
static int
dissect_s1ap_EHRPDSectorLoadReportingResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EHRPDSectorLoadReportingResponse, EHRPDSectorLoadReportingResponse_sequence);
return offset;
}
static int
dissect_s1ap_CellLoadReportingResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellLoadReportingResponse, CellLoadReportingResponse_choice,
NULL);
return offset;
}
static int
dissect_s1ap_EUTRANResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EUTRANResponse, EUTRANResponse_sequence);
return offset;
}
static int
dissect_s1ap_EHRPDMultiSectorLoadReportingResponseItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EHRPDMultiSectorLoadReportingResponseItem, EHRPDMultiSectorLoadReportingResponseItem_sequence);
return offset;
}
static int
dissect_s1ap_MultiCellLoadReportingResponse_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_MultiCellLoadReportingResponse_Item, MultiCellLoadReportingResponse_Item_choice,
NULL);
return offset;
}
static int
dissect_s1ap_MultiCellLoadReportingResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_MultiCellLoadReportingResponse, MultiCellLoadReportingResponse_sequence_of,
1, maxnoofIRATReportingCells, FALSE);
return offset;
}
static int
dissect_s1ap_OverloadFlag(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_EventTriggeredCellLoadReportingResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_EventTriggeredCellLoadReportingResponse, EventTriggeredCellLoadReportingResponse_sequence);
return offset;
}
static int
dissect_s1ap_ActivatedCellsList_Item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_ActivatedCellsList_Item, ActivatedCellsList_Item_sequence);
return offset;
}
static int
dissect_s1ap_ActivatedCellsList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_s1ap_ActivatedCellsList, ActivatedCellsList_sequence_of,
0, maxnoofCellineNB, FALSE);
return offset;
}
static int
dissect_s1ap_CellActivationResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_s1ap_CellActivationResponse, CellActivationResponse_sequence);
return offset;
}
int
dissect_s1ap_SONtransferResponseContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_SONtransferResponseContainer, SONtransferResponseContainer_choice,
NULL);
return offset;
}
static int
dissect_s1ap_CellLoadReportingCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_HOReportingCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_CellActivationCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_CellStateIndicationCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_FailureEventReportingCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_s1ap_SONtransferCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_s1ap_SONtransferCause, SONtransferCause_choice,
NULL);
return offset;
}
static int dissect_Additional_GUTI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Additional_GUTI(tvb, offset, &asn1_ctx, tree, hf_s1ap_Additional_GUTI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_AssistanceDataForPaging_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_AssistanceDataForPaging(tvb, offset, &asn1_ctx, tree, hf_s1ap_AssistanceDataForPaging_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Bearers_SubjectToStatusTransfer_Item_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Bearers_SubjectToStatusTransfer_Item(tvb, offset, &asn1_ctx, tree, hf_s1ap_Bearers_SubjectToStatusTransfer_Item_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_BearerType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_BearerType(tvb, offset, &asn1_ctx, tree, hf_s1ap_BearerType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_BroadcastCancelledAreaList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_BroadcastCancelledAreaList(tvb, offset, &asn1_ctx, tree, hf_s1ap_BroadcastCancelledAreaList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_BroadcastCompletedAreaList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_BroadcastCompletedAreaList(tvb, offset, &asn1_ctx, tree, hf_s1ap_BroadcastCompletedAreaList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cause(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellAccessMode_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CellAccessMode(tvb, offset, &asn1_ctx, tree, hf_s1ap_CellAccessMode_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellIdentifierAndCELevelForCECapableUEs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CellIdentifierAndCELevelForCECapableUEs(tvb, offset, &asn1_ctx, tree, hf_s1ap_CellIdentifierAndCELevelForCECapableUEs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CE_mode_B_SupportIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CE_mode_B_SupportIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_CE_mode_B_SupportIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cdma2000PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cdma2000PDU(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cdma2000RATType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cdma2000RATType(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000RATType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cdma2000SectorID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cdma2000SectorID(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000SectorID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cdma2000HOStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cdma2000HOStatus(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000HOStatus_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cdma2000HORequiredIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cdma2000HORequiredIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000HORequiredIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cdma2000OneXSRVCCInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cdma2000OneXSRVCCInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000OneXSRVCCInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cdma2000OneXRAND_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Cdma2000OneXRAND(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000OneXRAND_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CNDomain_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CNDomain(tvb, offset, &asn1_ctx, tree, hf_s1ap_CNDomain_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ConcurrentWarningMessageIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ConcurrentWarningMessageIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_ConcurrentWarningMessageIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Correlation_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Correlation_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_Correlation_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSFallbackIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CSFallbackIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_CSFallbackIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_AdditionalCSFallbackIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_AdditionalCSFallbackIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_AdditionalCSFallbackIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSG_Id_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CSG_Id(tvb, offset, &asn1_ctx, tree, hf_s1ap_CSG_Id_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSG_IdList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CSG_IdList(tvb, offset, &asn1_ctx, tree, hf_s1ap_CSG_IdList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSGMembershipStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CSGMembershipStatus(tvb, offset, &asn1_ctx, tree, hf_s1ap_CSGMembershipStatus_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_COUNTValueExtended_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_COUNTValueExtended(tvb, offset, &asn1_ctx, tree, hf_s1ap_COUNTValueExtended_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_COUNTvaluePDCP_SNlength18_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_COUNTvaluePDCP_SNlength18(tvb, offset, &asn1_ctx, tree, hf_s1ap_COUNTvaluePDCP_SNlength18_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CriticalityDiagnostics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CriticalityDiagnostics(tvb, offset, &asn1_ctx, tree, hf_s1ap_CriticalityDiagnostics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DataCodingScheme_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_DataCodingScheme(tvb, offset, &asn1_ctx, tree, hf_s1ap_DataCodingScheme_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Direct_Forwarding_Path_Availability_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Direct_Forwarding_Path_Availability(tvb, offset, &asn1_ctx, tree, hf_s1ap_Direct_Forwarding_Path_Availability_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Data_Forwarding_Not_Possible_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Data_Forwarding_Not_Possible(tvb, offset, &asn1_ctx, tree, hf_s1ap_Data_Forwarding_Not_Possible_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PWSfailedECGIList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PWSfailedECGIList(tvb, offset, &asn1_ctx, tree, hf_s1ap_PWSfailedECGIList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_EmergencyAreaIDListForRestart_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_EmergencyAreaIDListForRestart(tvb, offset, &asn1_ctx, tree, hf_s1ap_EmergencyAreaIDListForRestart_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_s1ap_Global_ENB_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Global_ENB_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_Global_ENB_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GUMMEIList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_GUMMEIList(tvb, offset, &asn1_ctx, tree, hf_s1ap_GUMMEIList_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_s1ap_ENB_StatusTransfer_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENB_StatusTransfer_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_ENB_StatusTransfer_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENB_UE_S1AP_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENB_UE_S1AP_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENB_UE_S1AP_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBname_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBname(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBname_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABInformationListItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABInformationListItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABInformationListItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABList(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_EUTRAN_CGI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_EUTRAN_CGI(tvb, offset, &asn1_ctx, tree, hf_s1ap_EUTRAN_CGI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_EUTRANRoundTripDelayEstimationInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_EUTRANRoundTripDelayEstimationInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_EUTRANRoundTripDelayEstimationInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ExpectedUEBehaviour_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ExpectedUEBehaviour(tvb, offset, &asn1_ctx, tree, hf_s1ap_ExpectedUEBehaviour_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ExtendedRepetitionPeriod_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ExtendedRepetitionPeriod(tvb, offset, &asn1_ctx, tree, hf_s1ap_ExtendedRepetitionPeriod_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Extended_UEIdentityIndexValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Extended_UEIdentityIndexValue(tvb, offset, &asn1_ctx, tree, hf_s1ap_Extended_UEIdentityIndexValue_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GUMMEI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_GUMMEI(tvb, offset, &asn1_ctx, tree, hf_s1ap_GUMMEI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GUMMEIType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_GUMMEIType(tvb, offset, &asn1_ctx, tree, hf_s1ap_GUMMEIType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_GWContextReleaseIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_GWContextReleaseIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_GWContextReleaseIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverRestrictionList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverRestrictionList(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverRestrictionList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverType(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Masked_IMEISV_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Masked_IMEISV(tvb, offset, &asn1_ctx, tree, hf_s1ap_Masked_IMEISV_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InformationOnRecommendedCellsAndENBsForPaging_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_InformationOnRecommendedCellsAndENBsForPaging(tvb, offset, &asn1_ctx, tree, hf_s1ap_InformationOnRecommendedCellsAndENBsForPaging_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_KillAllWarningMessages_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_KillAllWarningMessages(tvb, offset, &asn1_ctx, tree, hf_s1ap_KillAllWarningMessages_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LAI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_LAI(tvb, offset, &asn1_ctx, tree, hf_s1ap_LAI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LPPa_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_LPPa_PDU(tvb, offset, &asn1_ctx, tree, hf_s1ap_LPPa_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LHN_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_LHN_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_LHN_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LoggedMBSFNMDT_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_LoggedMBSFNMDT(tvb, offset, &asn1_ctx, tree, hf_s1ap_LoggedMBSFNMDT_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M3Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_M3Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_M3Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M4Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_M4Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_M4Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M5Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_M5Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_M5Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M6Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_M6Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_M6Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_M7Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_M7Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_M7Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MDT_Location_Info_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MDT_Location_Info(tvb, offset, &asn1_ctx, tree, hf_s1ap_MDT_Location_Info_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MDT_Configuration_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MDT_Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_MDT_Configuration_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ManagementBasedMDTAllowed_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ManagementBasedMDTAllowed(tvb, offset, &asn1_ctx, tree, hf_s1ap_ManagementBasedMDTAllowed_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MDTPLMNList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MDTPLMNList(tvb, offset, &asn1_ctx, tree, hf_s1ap_MDTPLMNList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PrivacyIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PrivacyIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_PrivacyIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MessageIdentifier_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MessageIdentifier(tvb, offset, &asn1_ctx, tree, hf_s1ap_MessageIdentifier_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MobilityInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MobilityInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_MobilityInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMEname_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMEname(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEname_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMERelaySupportIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMERelaySupportIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMERelaySupportIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MME_Group_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MME_Group_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_MME_Group_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MME_UE_S1AP_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MME_UE_S1AP_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_MME_UE_S1AP_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MSClassmark2_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MSClassmark2(tvb, offset, &asn1_ctx, tree, hf_s1ap_MSClassmark2_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MSClassmark3_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MSClassmark3(tvb, offset, &asn1_ctx, tree, hf_s1ap_MSClassmark3_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MutingAvailabilityIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MutingAvailabilityIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_MutingAvailabilityIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MutingPatternInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MutingPatternInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_MutingPatternInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NAS_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_NAS_PDU(tvb, offset, &asn1_ctx, tree, hf_s1ap_NAS_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NASSecurityParametersfromE_UTRAN_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_NASSecurityParametersfromE_UTRAN(tvb, offset, &asn1_ctx, tree, hf_s1ap_NASSecurityParametersfromE_UTRAN_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NASSecurityParameterstoE_UTRAN_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_NASSecurityParameterstoE_UTRAN(tvb, offset, &asn1_ctx, tree, hf_s1ap_NASSecurityParameterstoE_UTRAN_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NB_IoT_DefaultPagingDRX_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_NB_IoT_DefaultPagingDRX(tvb, offset, &asn1_ctx, tree, hf_s1ap_NB_IoT_DefaultPagingDRX_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NB_IoT_Paging_eDRXInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_NB_IoT_Paging_eDRXInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_NB_IoT_Paging_eDRXInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NB_IoT_UEIdentityIndexValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_NB_IoT_UEIdentityIndexValue(tvb, offset, &asn1_ctx, tree, hf_s1ap_NB_IoT_UEIdentityIndexValue_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NumberofBroadcastRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_NumberofBroadcastRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_NumberofBroadcastRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_OverloadResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_OverloadResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_OverloadResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Paging_eDRXInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Paging_eDRXInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_Paging_eDRXInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PagingDRX_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PagingDRX(tvb, offset, &asn1_ctx, tree, hf_s1ap_PagingDRX_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PagingPriority_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PagingPriority(tvb, offset, &asn1_ctx, tree, hf_s1ap_PagingPriority_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ProSeAuthorized_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ProSeAuthorized(tvb, offset, &asn1_ctx, tree, hf_s1ap_ProSeAuthorized_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ProSeUEtoNetworkRelaying_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ProSeUEtoNetworkRelaying(tvb, offset, &asn1_ctx, tree, hf_s1ap_ProSeUEtoNetworkRelaying_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PS_ServiceNotAvailable_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PS_ServiceNotAvailable(tvb, offset, &asn1_ctx, tree, hf_s1ap_PS_ServiceNotAvailable_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ReceiveStatusOfULPDCPSDUsExtended_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ReceiveStatusOfULPDCPSDUsExtended(tvb, offset, &asn1_ctx, tree, hf_s1ap_ReceiveStatusOfULPDCPSDUsExtended_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18(tvb, offset, &asn1_ctx, tree, hf_s1ap_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RecommendedCellItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_RecommendedCellItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_RecommendedCellItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RecommendedENBItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_RecommendedENBItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_RecommendedENBItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelativeMMECapacity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_RelativeMMECapacity(tvb, offset, &asn1_ctx, tree, hf_s1ap_RelativeMMECapacity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelayNode_Indicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_RelayNode_Indicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_RelayNode_Indicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAT_Type_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_RAT_Type(tvb, offset, &asn1_ctx, tree, hf_s1ap_RAT_Type_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RequestType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_RequestType(tvb, offset, &asn1_ctx, tree, hf_s1ap_RequestType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RepetitionPeriod_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_RepetitionPeriod(tvb, offset, &asn1_ctx, tree, hf_s1ap_RepetitionPeriod_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RRC_Establishment_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_RRC_Establishment_Cause(tvb, offset, &asn1_ctx, tree, hf_s1ap_RRC_Establishment_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ECGIListForRestart_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ECGIListForRestart(tvb, offset, &asn1_ctx, tree, hf_s1ap_ECGIListForRestart_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Routing_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Routing_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_Routing_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SecurityKey_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SecurityKey(tvb, offset, &asn1_ctx, tree, hf_s1ap_SecurityKey_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SecurityContext_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SecurityContext(tvb, offset, &asn1_ctx, tree, hf_s1ap_SecurityContext_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SerialNumber_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SerialNumber(tvb, offset, &asn1_ctx, tree, hf_s1ap_SerialNumber_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SONInformationReport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SONInformationReport(tvb, offset, &asn1_ctx, tree, hf_s1ap_SONInformationReport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SONConfigurationTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SONConfigurationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_SONConfigurationTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SynchronisationInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SynchronisationInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_SynchronisationInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Source_ToTarget_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Source_ToTarget_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_Source_ToTarget_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRVCCOperationNotPossible_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SRVCCOperationNotPossible(tvb, offset, &asn1_ctx, tree, hf_s1ap_SRVCCOperationNotPossible_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRVCCOperationPossible_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SRVCCOperationPossible(tvb, offset, &asn1_ctx, tree, hf_s1ap_SRVCCOperationPossible_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SRVCCHOIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SRVCCHOIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_SRVCCHOIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SourceeNB_ToTargeteNB_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SourceeNB_ToTargeteNB_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_SourceeNB_ToTargeteNB_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ServedGUMMEIs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ServedGUMMEIs(tvb, offset, &asn1_ctx, tree, hf_s1ap_ServedGUMMEIs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ServedPLMNs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ServedPLMNs(tvb, offset, &asn1_ctx, tree, hf_s1ap_ServedPLMNs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SubscriberProfileIDforRFP_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SubscriberProfileIDforRFP(tvb, offset, &asn1_ctx, tree, hf_s1ap_SubscriberProfileIDforRFP_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SupportedTAs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SupportedTAs(tvb, offset, &asn1_ctx, tree, hf_s1ap_SupportedTAs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TimeSynchronisationInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TimeSynchronisationInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_TimeSynchronisationInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_S_TMSI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_S_TMSI(tvb, offset, &asn1_ctx, tree, hf_s1ap_S_TMSI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TAI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TAI(tvb, offset, &asn1_ctx, tree, hf_s1ap_TAI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TargetID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TargetID(tvb, offset, &asn1_ctx, tree, hf_s1ap_TargetID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TargeteNB_ToSourceeNB_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TargeteNB_ToSourceeNB_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_TargeteNB_ToSourceeNB_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Target_ToSource_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Target_ToSource_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_Target_ToSource_TransparentContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TimeToWait_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TimeToWait(tvb, offset, &asn1_ctx, tree, hf_s1ap_TimeToWait_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Time_UE_StayedInCell_EnhancedGranularity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Time_UE_StayedInCell_EnhancedGranularity(tvb, offset, &asn1_ctx, tree, hf_s1ap_Time_UE_StayedInCell_EnhancedGranularity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TransportInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TransportInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_TransportInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TransportLayerAddress_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TransportLayerAddress(tvb, offset, &asn1_ctx, tree, hf_s1ap_TransportLayerAddress_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TraceActivation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TraceActivation(tvb, offset, &asn1_ctx, tree, hf_s1ap_TraceActivation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_UTRAN_Trace_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_UTRAN_Trace_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_UTRAN_Trace_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TrafficLoadReductionIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TrafficLoadReductionIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_TrafficLoadReductionIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TunnelInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TunnelInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_TunnelInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TAIListForRestart_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TAIListForRestart(tvb, offset, &asn1_ctx, tree, hf_s1ap_TAIListForRestart_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEAggregateMaximumBitrate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEAggregateMaximumBitrate(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEAggregateMaximumBitrate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_RetentionInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UE_RetentionInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_RetentionInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_S1AP_IDs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UE_S1AP_IDs(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_S1AP_IDs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_associatedLogicalS1_ConnectionItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UE_associatedLogicalS1_ConnectionItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_associatedLogicalS1_ConnectionItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEIdentityIndexValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEIdentityIndexValue(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEIdentityIndexValue_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_s1ap_UE_HistoryInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UE_HistoryInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_UE_HistoryInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_HistoryInformationFromTheUE_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UE_HistoryInformationFromTheUE(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_HistoryInformationFromTheUE_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEPagingID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEPagingID(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEPagingID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UERadioCapability_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UERadioCapability(tvb, offset, &asn1_ctx, tree, hf_s1ap_UERadioCapability_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UERadioCapabilityForPaging_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UERadioCapabilityForPaging(tvb, offset, &asn1_ctx, tree, hf_s1ap_UERadioCapabilityForPaging_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UESecurityCapabilities_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UESecurityCapabilities(tvb, offset, &asn1_ctx, tree, hf_s1ap_UESecurityCapabilities_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_Usage_Type_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UE_Usage_Type(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_Usage_Type_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UserLocationInformation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UserLocationInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_UserLocationInformation_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEUserPlaneCIoTSupportIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEUserPlaneCIoTSupportIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEUserPlaneCIoTSupportIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_VoiceSupportMatchIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_VoiceSupportMatchIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_VoiceSupportMatchIndicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_WarningAreaList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_WarningAreaList(tvb, offset, &asn1_ctx, tree, hf_s1ap_WarningAreaList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_WarningType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_WarningType(tvb, offset, &asn1_ctx, tree, hf_s1ap_WarningType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_WarningSecurityInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_WarningSecurityInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_WarningSecurityInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_WarningMessageContents_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_WarningMessageContents(tvb, offset, &asn1_ctx, tree, hf_s1ap_WarningMessageContents_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_X2TNLConfigurationInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_X2TNLConfigurationInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_X2TNLConfigurationInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBX2ExtTLAs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBX2ExtTLAs(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBX2ExtTLAs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBIndirectX2TransportLayerAddresses_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBIndirectX2TransportLayerAddresses(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBIndirectX2TransportLayerAddresses_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverRequired_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverRequired(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverRequired_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverCommand_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverCommand(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverCommand_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABSubjecttoDataForwardingList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABSubjecttoDataForwardingList(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSubjecttoDataForwardingList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABDataForwardingItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABDataForwardingItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABDataForwardingItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverPreparationFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverPreparationFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverPreparationFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSetupListHOReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSetupListHOReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupListHOReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSetupItemHOReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSetupItemHOReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupItemHOReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverRequestAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverRequestAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverRequestAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABAdmittedList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABAdmittedList(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABAdmittedList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABAdmittedItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABAdmittedItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABAdmittedItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABFailedtoSetupListHOReqAck_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABFailedtoSetupListHOReqAck(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABFailedtoSetupListHOReqAck_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABFailedToSetupItemHOReqAck_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABFailedToSetupItemHOReqAck(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABFailedToSetupItemHOReqAck_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverNotify_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverNotify(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverNotify_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PathSwitchRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PathSwitchRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_PathSwitchRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSwitchedDLList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSwitchedDLList(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSwitchedDLList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSwitchedDLItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSwitchedDLItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSwitchedDLItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PathSwitchRequestAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PathSwitchRequestAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_PathSwitchRequestAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSwitchedULList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSwitchedULList(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSwitchedULList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSwitchedULItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSwitchedULItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSwitchedULItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PathSwitchRequestFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PathSwitchRequestFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_PathSwitchRequestFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverCancel_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverCancel(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverCancel_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HandoverCancelAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_HandoverCancelAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverCancelAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABSetupRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABSetupRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSetupListBearerSUReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSetupListBearerSUReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupListBearerSUReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSetupItemBearerSUReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSetupItemBearerSUReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupItemBearerSUReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABSetupResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABSetupResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABSetupListBearerSURes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABSetupListBearerSURes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupListBearerSURes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABSetupItemBearerSURes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABSetupItemBearerSURes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupItemBearerSURes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABModifyRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABModifyRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeModifiedListBearerModReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeModifiedListBearerModReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeModifiedListBearerModReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeModifiedItemBearerModReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeModifiedItemBearerModReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeModifiedItemBearerModReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABModifyResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABModifyResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABModifyListBearerModRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABModifyListBearerModRes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyListBearerModRes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABModifyItemBearerModRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABModifyItemBearerModRes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyItemBearerModRes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABReleaseCommand_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABReleaseCommand(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABReleaseCommand_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABReleaseResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABReleaseResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABReleaseResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABReleaseListBearerRelComp_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABReleaseListBearerRelComp(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABReleaseListBearerRelComp_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABReleaseItemBearerRelComp_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABReleaseItemBearerRelComp(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABReleaseItemBearerRelComp_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABReleaseIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABReleaseIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABReleaseIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InitialContextSetupRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_InitialContextSetupRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_InitialContextSetupRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSetupListCtxtSUReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSetupListCtxtSUReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupListCtxtSUReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeSetupItemCtxtSUReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeSetupItemCtxtSUReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupItemCtxtSUReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InitialContextSetupResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_InitialContextSetupResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_InitialContextSetupResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABSetupListCtxtSURes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABSetupListCtxtSURes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupListCtxtSURes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABSetupItemCtxtSURes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABSetupItemCtxtSURes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupItemCtxtSURes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InitialContextSetupFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_InitialContextSetupFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_InitialContextSetupFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Paging_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Paging(tvb, offset, &asn1_ctx, tree, hf_s1ap_Paging_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TAIList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TAIList(tvb, offset, &asn1_ctx, tree, hf_s1ap_TAIList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TAIItem_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TAIItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_TAIItem_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextReleaseRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextReleaseRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextReleaseRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextReleaseCommand_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextReleaseCommand(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextReleaseCommand_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextReleaseComplete_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextReleaseComplete(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextReleaseComplete_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextModificationRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextModificationRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextModificationRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextModificationResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextModificationResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextModificationResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextModificationFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextModificationFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextModificationFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UERadioCapabilityMatchRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UERadioCapabilityMatchRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_UERadioCapabilityMatchRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UERadioCapabilityMatchResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UERadioCapabilityMatchResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_UERadioCapabilityMatchResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DownlinkNASTransport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_DownlinkNASTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_DownlinkNASTransport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_InitialUEMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_InitialUEMessage(tvb, offset, &asn1_ctx, tree, hf_s1ap_InitialUEMessage_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UplinkNASTransport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UplinkNASTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_UplinkNASTransport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NASNonDeliveryIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_NASNonDeliveryIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_NASNonDeliveryIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RerouteNASRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_RerouteNASRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_RerouteNASRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_S1_Message_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_S1_Message(tvb, offset, &asn1_ctx, tree, hf_s1ap_S1_Message_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Reset_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Reset(tvb, offset, &asn1_ctx, tree, hf_s1ap_Reset_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ResetType(tvb, offset, &asn1_ctx, tree, hf_s1ap_ResetType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ResetAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ResetAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_ResetAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_associatedLogicalS1_ConnectionListResAck_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UE_associatedLogicalS1_ConnectionListResAck(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_associatedLogicalS1_ConnectionListResAck_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ErrorIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ErrorIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_ErrorIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_S1SetupRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_S1SetupRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_S1SetupRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_S1SetupResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_S1SetupResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_S1SetupResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_S1SetupFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_S1SetupFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_S1SetupFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationUpdate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBConfigurationUpdate(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBConfigurationUpdate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationUpdateAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBConfigurationUpdateAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBConfigurationUpdateAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationUpdateFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBConfigurationUpdateFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBConfigurationUpdateFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMEConfigurationUpdate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMEConfigurationUpdate(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEConfigurationUpdate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMEConfigurationUpdateAcknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMEConfigurationUpdateAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEConfigurationUpdateAcknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMEConfigurationUpdateFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMEConfigurationUpdateFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEConfigurationUpdateFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DownlinkS1cdma2000tunnelling_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_DownlinkS1cdma2000tunnelling(tvb, offset, &asn1_ctx, tree, hf_s1ap_DownlinkS1cdma2000tunnelling_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UplinkS1cdma2000tunnelling_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UplinkS1cdma2000tunnelling(tvb, offset, &asn1_ctx, tree, hf_s1ap_UplinkS1cdma2000tunnelling_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UECapabilityInfoIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UECapabilityInfoIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_UECapabilityInfoIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBStatusTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBStatusTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBStatusTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMEStatusTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMEStatusTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEStatusTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TraceStart_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TraceStart(tvb, offset, &asn1_ctx, tree, hf_s1ap_TraceStart_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TraceFailureIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_TraceFailureIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_TraceFailureIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DeactivateTrace_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_DeactivateTrace(tvb, offset, &asn1_ctx, tree, hf_s1ap_DeactivateTrace_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellTrafficTrace_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CellTrafficTrace(tvb, offset, &asn1_ctx, tree, hf_s1ap_CellTrafficTrace_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LocationReportingControl_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_LocationReportingControl(tvb, offset, &asn1_ctx, tree, hf_s1ap_LocationReportingControl_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LocationReportingFailureIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_LocationReportingFailureIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_LocationReportingFailureIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LocationReport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_LocationReport(tvb, offset, &asn1_ctx, tree, hf_s1ap_LocationReport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_OverloadStart_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_OverloadStart(tvb, offset, &asn1_ctx, tree, hf_s1ap_OverloadStart_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_OverloadStop_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_OverloadStop(tvb, offset, &asn1_ctx, tree, hf_s1ap_OverloadStop_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_WriteReplaceWarningRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_WriteReplaceWarningRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_WriteReplaceWarningRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_WriteReplaceWarningResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_WriteReplaceWarningResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_WriteReplaceWarningResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBDirectInformationTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBDirectInformationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBDirectInformationTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Inter_SystemInformationTransferType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_Inter_SystemInformationTransferType(tvb, offset, &asn1_ctx, tree, hf_s1ap_Inter_SystemInformationTransferType_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMEDirectInformationTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMEDirectInformationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEDirectInformationTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ENBConfigurationTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ENBConfigurationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBConfigurationTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MMEConfigurationTransfer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_MMEConfigurationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEConfigurationTransfer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PrivateMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PrivateMessage(tvb, offset, &asn1_ctx, tree, hf_s1ap_PrivateMessage_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_KillRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_KillRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_KillRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_KillResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_KillResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_KillResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PWSRestartIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PWSRestartIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_PWSRestartIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PWSFailureIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_PWSFailureIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_PWSFailureIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DownlinkUEAssociatedLPPaTransport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_DownlinkUEAssociatedLPPaTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_DownlinkUEAssociatedLPPaTransport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UplinkUEAssociatedLPPaTransport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UplinkUEAssociatedLPPaTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_UplinkUEAssociatedLPPaTransport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_DownlinkNonUEAssociatedLPPaTransport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_DownlinkNonUEAssociatedLPPaTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_DownlinkNonUEAssociatedLPPaTransport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UplinkNonUEAssociatedLPPaTransport_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UplinkNonUEAssociatedLPPaTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_UplinkNonUEAssociatedLPPaTransport_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABModificationIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABModificationIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModificationIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeModifiedListBearerModInd_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeModifiedListBearerModInd(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeModifiedListBearerModInd_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABToBeModifiedItemBearerModInd_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABToBeModifiedItemBearerModInd(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeModifiedItemBearerModInd_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABNotToBeModifiedListBearerModInd_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABNotToBeModifiedListBearerModInd(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABNotToBeModifiedListBearerModInd_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABNotToBeModifiedItemBearerModInd_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABNotToBeModifiedItemBearerModInd(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABNotToBeModifiedItemBearerModInd_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSGMembershipInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_CSGMembershipInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_CSGMembershipInfo_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABModificationConfirm_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABModificationConfirm(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModificationConfirm_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABModifyListBearerModConf_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABModifyListBearerModConf(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyListBearerModConf_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABModifyItemBearerModConf_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABModifyItemBearerModConf(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyItemBearerModConf_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextModificationIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextModificationIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextModificationIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextModificationConfirm_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextModificationConfirm(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextModificationConfirm_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextSuspendRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextSuspendRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextSuspendRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextSuspendResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextSuspendResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextSuspendResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextResumeRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextResumeRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextResumeRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABFailedToResumeListResumeReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABFailedToResumeListResumeReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABFailedToResumeListResumeReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABFailedToResumeItemResumeReq_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABFailedToResumeItemResumeReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABFailedToResumeItemResumeReq_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextResumeResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextResumeResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextResumeResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABFailedToResumeListResumeRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABFailedToResumeListResumeRes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABFailedToResumeListResumeRes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_RABFailedToResumeItemResumeRes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_E_RABFailedToResumeItemResumeRes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABFailedToResumeItemResumeRes_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEContextResumeFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_UEContextResumeFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextResumeFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ConnectionEstablishmentIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_ConnectionEstablishmentIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_ConnectionEstablishmentIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_S1AP_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_S1AP_PDU(tvb, offset, &asn1_ctx, tree, hf_s1ap_S1AP_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_s1ap_SONtransferApplicationIdentity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SONtransferApplicationIdentity(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_SONtransferApplicationIdentity_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_s1ap_SONtransferRequestContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SONtransferRequestContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_SONtransferRequestContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_s1ap_SONtransferResponseContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SONtransferResponseContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_SONtransferResponseContainer_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_s1ap_SONtransferCause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_s1ap_SONtransferCause(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_SONtransferCause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
s1ap_ctx_t s1ap_ctx;
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(pinfo);
s1ap_ctx.message_type = s1ap_data->message_type;
s1ap_ctx.ProcedureCode = s1ap_data->procedure_code;
s1ap_ctx.ProtocolIE_ID = s1ap_data->protocol_ie_id;
s1ap_ctx.ProtocolExtensionID = s1ap_data->protocol_extension_id;
return (dissector_try_uint_new(s1ap_ies_dissector_table, s1ap_data->protocol_ie_id, tvb, pinfo, tree, TRUE, &s1ap_ctx)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
s1ap_ctx_t s1ap_ctx;
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(pinfo);
s1ap_ctx.message_type = s1ap_data->message_type;
s1ap_ctx.ProcedureCode = s1ap_data->procedure_code;
s1ap_ctx.ProtocolIE_ID = s1ap_data->protocol_ie_id;
s1ap_ctx.ProtocolExtensionID = s1ap_data->protocol_extension_id;
return (dissector_try_uint_new(s1ap_extension_dissector_table, s1ap_data->protocol_extension_id, tvb, pinfo, tree, TRUE, &s1ap_ctx)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(pinfo);
return (dissector_try_uint_new(s1ap_proc_imsg_dissector_table, s1ap_data->procedure_code, tvb, pinfo, tree, TRUE, data)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(pinfo);
return (dissector_try_uint_new(s1ap_proc_sout_dissector_table, s1ap_data->procedure_code, tvb, pinfo, tree, TRUE, data)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(pinfo);
return (dissector_try_uint_new(s1ap_proc_uout_dissector_table, s1ap_data->procedure_code, tvb, pinfo, tree, TRUE, data)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_s1ap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *s1ap_item = NULL;
proto_tree *s1ap_tree = NULL;
conversation_t *conversation;
struct s1ap_private_data* s1ap_data;
wmem_list_frame_t *prev_layer;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "S1AP");
prev_layer = wmem_list_frame_prev(wmem_list_tail(pinfo->layers));
if (prev_layer && GPOINTER_TO_INT(wmem_list_frame_data(prev_layer)) != proto_s1ap)
col_clear_fence(pinfo->cinfo, COL_INFO);
col_clear(pinfo->cinfo, COL_INFO);
s1ap_item = proto_tree_add_item(tree, proto_s1ap, tvb, 0, -1, ENC_NA);
s1ap_tree = proto_item_add_subtree(s1ap_item, ett_s1ap);
s1ap_data = s1ap_get_private_data(pinfo);
conversation = find_or_create_conversation(pinfo);
s1ap_data->s1ap_conv = (struct s1ap_conv_info *)conversation_get_proto_data(conversation, proto_s1ap);
if (!s1ap_data->s1ap_conv) {
s1ap_data->s1ap_conv = wmem_new(wmem_file_scope(), struct s1ap_conv_info);
s1ap_data->s1ap_conv->nbiot_ta = wmem_map_new(wmem_file_scope(), wmem_int64_hash, g_int64_equal);
s1ap_data->s1ap_conv->nbiot_enb_ue_s1ap_id = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_s1ap, s1ap_data->s1ap_conv);
}
dissect_S1AP_PDU_PDU(tvb, pinfo, s1ap_tree, NULL);
return tvb_captured_length(tvb);
}
void
proto_reg_handoff_s1ap(void)
{
static gboolean Initialized=FALSE;
static guint SctpPort;
gcsna_handle = find_dissector_add_dependency("gcsna", proto_s1ap);
if (!Initialized) {
nas_eps_handle = find_dissector_add_dependency("nas-eps", proto_s1ap);
lppa_handle = find_dissector_add_dependency("lppa", proto_s1ap);
bssgp_handle = find_dissector_add_dependency("bssgp", proto_s1ap);
dissector_add_for_decode_as("sctp.port", s1ap_handle);
dissector_add_uint("sctp.ppi", S1AP_PAYLOAD_PROTOCOL_ID, s1ap_handle);
Initialized=TRUE;
#line 1 "./asn1/s1ap/packet-s1ap-dis-tab.c"
dissector_add_uint("s1ap.ies", id_MME_UE_S1AP_ID, create_dissector_handle(dissect_MME_UE_S1AP_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_HandoverType, create_dissector_handle(dissect_HandoverType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Cause, create_dissector_handle(dissect_Cause_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TargetID, create_dissector_handle(dissect_TargetID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_eNB_UE_S1AP_ID, create_dissector_handle(dissect_ENB_UE_S1AP_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABSubjecttoDataForwardingList, create_dissector_handle(dissect_E_RABSubjecttoDataForwardingList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABtoReleaseListHOCmd, create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABDataForwardingItem, create_dissector_handle(dissect_E_RABDataForwardingItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABReleaseItemBearerRelComp, create_dissector_handle(dissect_E_RABReleaseItemBearerRelComp_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSetupListBearerSUReq, create_dissector_handle(dissect_E_RABToBeSetupListBearerSUReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSetupItemBearerSUReq, create_dissector_handle(dissect_E_RABToBeSetupItemBearerSUReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABAdmittedList, create_dissector_handle(dissect_E_RABAdmittedList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedToSetupListHOReqAck, create_dissector_handle(dissect_E_RABFailedtoSetupListHOReqAck_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABAdmittedItem, create_dissector_handle(dissect_E_RABAdmittedItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedtoSetupItemHOReqAck, create_dissector_handle(dissect_E_RABFailedToSetupItemHOReqAck_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSwitchedDLList, create_dissector_handle(dissect_E_RABToBeSwitchedDLList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSwitchedDLItem, create_dissector_handle(dissect_E_RABToBeSwitchedDLItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSetupListCtxtSUReq, create_dissector_handle(dissect_E_RABToBeSetupListCtxtSUReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TraceActivation, create_dissector_handle(dissect_TraceActivation_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_UTRAN_Trace_ID, create_dissector_handle(dissect_E_UTRAN_Trace_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_NAS_PDU, create_dissector_handle(dissect_NAS_PDU_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSetupItemHOReq, create_dissector_handle(dissect_E_RABToBeSetupItemHOReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABSetupListBearerSURes, create_dissector_handle(dissect_E_RABSetupListBearerSURes_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedToSetupListBearerSURes, create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeModifiedListBearerModReq, create_dissector_handle(dissect_E_RABToBeModifiedListBearerModReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABModifyListBearerModRes, create_dissector_handle(dissect_E_RABModifyListBearerModRes_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedToModifyList, create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeReleasedList, create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedToReleaseList, create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABItem, create_dissector_handle(dissect_E_RABItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeModifiedItemBearerModReq, create_dissector_handle(dissect_E_RABToBeModifiedItemBearerModReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABModifyItemBearerModRes, create_dissector_handle(dissect_E_RABModifyItemBearerModRes_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABSetupItemBearerSURes, create_dissector_handle(dissect_E_RABSetupItemBearerSURes_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SecurityContext, create_dissector_handle(dissect_SecurityContext_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_HandoverRestrictionList, create_dissector_handle(dissect_HandoverRestrictionList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UEPagingID, create_dissector_handle(dissect_UEPagingID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_pagingDRX, create_dissector_handle(dissect_PagingDRX_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TAIList, create_dissector_handle(dissect_TAIList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TAIItem, create_dissector_handle(dissect_TAIItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedToSetupListCtxtSURes, create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABSetupItemCtxtSURes, create_dissector_handle(dissect_E_RABSetupItemCtxtSURes_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABSetupListCtxtSURes, create_dissector_handle(dissect_E_RABSetupListCtxtSURes_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSetupItemCtxtSUReq, create_dissector_handle(dissect_E_RABToBeSetupItemCtxtSUReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSetupListHOReq, create_dissector_handle(dissect_E_RABToBeSetupListHOReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CriticalityDiagnostics, create_dissector_handle(dissect_CriticalityDiagnostics_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Global_ENB_ID, create_dissector_handle(dissect_s1ap_Global_ENB_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_eNBname, create_dissector_handle(dissect_ENBname_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_MMEname, create_dissector_handle(dissect_MMEname_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ServedPLMNs, create_dissector_handle(dissect_ServedPLMNs_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SupportedTAs, create_dissector_handle(dissect_SupportedTAs_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TimeToWait, create_dissector_handle(dissect_TimeToWait_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_uEaggregateMaximumBitrate, create_dissector_handle(dissect_UEAggregateMaximumBitrate_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TAI, create_dissector_handle(dissect_TAI_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABReleaseListBearerRelComp, create_dissector_handle(dissect_E_RABReleaseListBearerRelComp_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_cdma2000PDU, create_dissector_handle(dissect_Cdma2000PDU_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_cdma2000RATType, create_dissector_handle(dissect_Cdma2000RATType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_cdma2000SectorID, create_dissector_handle(dissect_Cdma2000SectorID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SecurityKey, create_dissector_handle(dissect_SecurityKey_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UERadioCapability, create_dissector_handle(dissect_UERadioCapability_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_GUMMEI_ID, create_dissector_handle(dissect_GUMMEI_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABInformationListItem, create_dissector_handle(dissect_E_RABInformationListItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Direct_Forwarding_Path_Availability, create_dissector_handle(dissect_Direct_Forwarding_Path_Availability_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UEIdentityIndexValue, create_dissector_handle(dissect_UEIdentityIndexValue_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_cdma2000HOStatus, create_dissector_handle(dissect_Cdma2000HOStatus_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_cdma2000HORequiredIndication, create_dissector_handle(dissect_Cdma2000HORequiredIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_RelativeMMECapacity, create_dissector_handle(dissect_RelativeMMECapacity_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SourceMME_UE_S1AP_ID, create_dissector_handle(dissect_MME_UE_S1AP_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Bearers_SubjectToStatusTransfer_Item, create_dissector_handle(dissect_Bearers_SubjectToStatusTransfer_Item_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_eNB_StatusTransfer_TransparentContainer, create_dissector_handle(dissect_s1ap_ENB_StatusTransfer_TransparentContainer_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UE_associatedLogicalS1_ConnectionItem, create_dissector_handle(dissect_UE_associatedLogicalS1_ConnectionItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ResetType, create_dissector_handle(dissect_ResetType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UE_associatedLogicalS1_ConnectionListResAck, create_dissector_handle(dissect_UE_associatedLogicalS1_ConnectionListResAck_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSwitchedULItem, create_dissector_handle(dissect_E_RABToBeSwitchedULItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeSwitchedULList, create_dissector_handle(dissect_E_RABToBeSwitchedULList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_S_TMSI, create_dissector_handle(dissect_S_TMSI_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_cdma2000OneXRAND, create_dissector_handle(dissect_Cdma2000OneXRAND_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_RequestType, create_dissector_handle(dissect_RequestType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UE_S1AP_IDs, create_dissector_handle(dissect_UE_S1AP_IDs_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_EUTRAN_CGI, create_dissector_handle(dissect_EUTRAN_CGI_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_OverloadResponse, create_dissector_handle(dissect_OverloadResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_cdma2000OneXSRVCCInfo, create_dissector_handle(dissect_Cdma2000OneXSRVCCInfo_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Source_ToTarget_TransparentContainer, create_dissector_handle(dissect_Source_ToTarget_TransparentContainer_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ServedGUMMEIs, create_dissector_handle(dissect_ServedGUMMEIs_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SubscriberProfileIDforRFP, create_dissector_handle(dissect_SubscriberProfileIDforRFP_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UESecurityCapabilities, create_dissector_handle(dissect_UESecurityCapabilities_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CSFallbackIndicator, create_dissector_handle(dissect_CSFallbackIndicator_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CNDomain, create_dissector_handle(dissect_CNDomain_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABReleasedList, create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_MessageIdentifier, create_dissector_handle(dissect_MessageIdentifier_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SerialNumber, create_dissector_handle(dissect_SerialNumber_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_WarningAreaList, create_dissector_handle(dissect_WarningAreaList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_RepetitionPeriod, create_dissector_handle(dissect_RepetitionPeriod_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_NumberofBroadcastRequest, create_dissector_handle(dissect_NumberofBroadcastRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_WarningType, create_dissector_handle(dissect_WarningType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_WarningSecurityInfo, create_dissector_handle(dissect_WarningSecurityInfo_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_DataCodingScheme, create_dissector_handle(dissect_DataCodingScheme_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_WarningMessageContents, create_dissector_handle(dissect_WarningMessageContents_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_BroadcastCompletedAreaList, create_dissector_handle(dissect_BroadcastCompletedAreaList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Inter_SystemInformationTransferTypeEDT, create_dissector_handle(dissect_Inter_SystemInformationTransferType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Inter_SystemInformationTransferTypeMDT, create_dissector_handle(dissect_Inter_SystemInformationTransferType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Target_ToSource_TransparentContainer, create_dissector_handle(dissect_Target_ToSource_TransparentContainer_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SRVCCOperationPossible, create_dissector_handle(dissect_SRVCCOperationPossible_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SRVCCHOIndication, create_dissector_handle(dissect_SRVCCHOIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CSG_Id, create_dissector_handle(dissect_CSG_Id_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CSG_IdList, create_dissector_handle(dissect_CSG_IdList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SONConfigurationTransferECT, create_dissector_handle(dissect_SONConfigurationTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SONConfigurationTransferMCT, create_dissector_handle(dissect_SONConfigurationTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TraceCollectionEntityIPAddress, create_dissector_handle(dissect_TransportLayerAddress_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_MSClassmark2, create_dissector_handle(dissect_MSClassmark2_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_MSClassmark3, create_dissector_handle(dissect_MSClassmark3_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_RRC_Establishment_Cause, create_dissector_handle(dissect_RRC_Establishment_Cause_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_NASSecurityParametersfromE_UTRAN, create_dissector_handle(dissect_NASSecurityParametersfromE_UTRAN_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_NASSecurityParameterstoE_UTRAN, create_dissector_handle(dissect_NASSecurityParameterstoE_UTRAN_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_DefaultPagingDRX, create_dissector_handle(dissect_PagingDRX_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Source_ToTarget_TransparentContainer_Secondary, create_dissector_handle(dissect_Source_ToTarget_TransparentContainer_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Target_ToSource_TransparentContainer_Secondary, create_dissector_handle(dissect_Target_ToSource_TransparentContainer_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_EUTRANRoundTripDelayEstimationInfo, create_dissector_handle(dissect_EUTRANRoundTripDelayEstimationInfo_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_BroadcastCancelledAreaList, create_dissector_handle(dissect_BroadcastCancelledAreaList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ConcurrentWarningMessageIndicator, create_dissector_handle(dissect_ConcurrentWarningMessageIndicator_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ExtendedRepetitionPeriod, create_dissector_handle(dissect_ExtendedRepetitionPeriod_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CellAccessMode, create_dissector_handle(dissect_CellAccessMode_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CSGMembershipStatus, create_dissector_handle(dissect_CSGMembershipStatus_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_LPPa_PDU, create_dissector_handle(dissect_LPPa_PDU_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Routing_ID, create_dissector_handle(dissect_Routing_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_PS_ServiceNotAvailable, create_dissector_handle(dissect_PS_ServiceNotAvailable_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_PagingPriority, create_dissector_handle(dissect_PagingPriority_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_GUMMEIList, create_dissector_handle(dissect_GUMMEIList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_GW_TransportLayerAddress, create_dissector_handle(dissect_TransportLayerAddress_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SourceMME_GUMMEI, create_dissector_handle(dissect_GUMMEI_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_MME_UE_S1AP_ID_2, create_dissector_handle(dissect_MME_UE_S1AP_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_RegisteredLAI, create_dissector_handle(dissect_LAI_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_RelayNode_Indicator, create_dissector_handle(dissect_RelayNode_Indicator_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TrafficLoadReductionIndication, create_dissector_handle(dissect_TrafficLoadReductionIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_MMERelaySupportIndicator, create_dissector_handle(dissect_MMERelaySupportIndicator_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_GWContextReleaseIndication, create_dissector_handle(dissect_GWContextReleaseIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ManagementBasedMDTAllowed, create_dissector_handle(dissect_ManagementBasedMDTAllowed_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_PrivacyIndicator, create_dissector_handle(dissect_PrivacyIndicator_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_VoiceSupportMatchIndicator, create_dissector_handle(dissect_VoiceSupportMatchIndicator_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_GUMMEIType, create_dissector_handle(dissect_GUMMEIType_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Tunnel_Information_for_BBF, create_dissector_handle(dissect_TunnelInformation_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ManagementBasedMDTPLMNList, create_dissector_handle(dissect_MDTPLMNList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ECGIListForRestart, create_dissector_handle(dissect_ECGIListForRestart_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SIPTO_L_GW_TransportLayerAddress, create_dissector_handle(dissect_TransportLayerAddress_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_LHN_ID, create_dissector_handle(dissect_LHN_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_AdditionalCSFallbackIndicator, create_dissector_handle(dissect_AdditionalCSFallbackIndicator_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_TAIListForRestart, create_dissector_handle(dissect_TAIListForRestart_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UserLocationInformation, create_dissector_handle(dissect_UserLocationInformation_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_KillAllWarningMessages, create_dissector_handle(dissect_KillAllWarningMessages_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Masked_IMEISV, create_dissector_handle(dissect_Masked_IMEISV_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ProSeAuthorized, create_dissector_handle(dissect_ProSeAuthorized_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_ExpectedUEBehaviour, create_dissector_handle(dissect_ExpectedUEBehaviour_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UERadioCapabilityForPaging, create_dissector_handle(dissect_UERadioCapabilityForPaging_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeModifiedListBearerModInd, create_dissector_handle(dissect_E_RABToBeModifiedListBearerModInd_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeModifiedItemBearerModInd, create_dissector_handle(dissect_E_RABToBeModifiedItemBearerModInd_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABNotToBeModifiedListBearerModInd, create_dissector_handle(dissect_E_RABNotToBeModifiedListBearerModInd_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABNotToBeModifiedItemBearerModInd, create_dissector_handle(dissect_E_RABNotToBeModifiedItemBearerModInd_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABModifyListBearerModConf, create_dissector_handle(dissect_E_RABModifyListBearerModConf_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABModifyItemBearerModConf, create_dissector_handle(dissect_E_RABModifyItemBearerModConf_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedToModifyListBearerModConf, create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SON_Information_Report, create_dissector_handle(dissect_SONInformationReport_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABToBeReleasedListBearerModConf, create_dissector_handle(dissect_E_RABList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_AssistanceDataForPaging, create_dissector_handle(dissect_AssistanceDataForPaging_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CellIdentifierAndCELevelForCECapableUEs, create_dissector_handle(dissect_CellIdentifierAndCELevelForCECapableUEs_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_InformationOnRecommendedCellsAndENBsForPaging, create_dissector_handle(dissect_InformationOnRecommendedCellsAndENBsForPaging_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_RecommendedCellItem, create_dissector_handle(dissect_RecommendedCellItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_RecommendedENBItem, create_dissector_handle(dissect_RecommendedENBItem_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_PWSfailedECGIList, create_dissector_handle(dissect_PWSfailedECGIList_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_MME_Group_ID, create_dissector_handle(dissect_MME_Group_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Additional_GUTI, create_dissector_handle(dissect_Additional_GUTI_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_S1_Message, create_dissector_handle(dissect_S1_Message_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CSGMembershipInfo, create_dissector_handle(dissect_CSGMembershipInfo_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_Paging_eDRXInformation, create_dissector_handle(dissect_Paging_eDRXInformation_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UE_RetentionInformation, create_dissector_handle(dissect_UE_RetentionInformation_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UE_Usage_Type, create_dissector_handle(dissect_UE_Usage_Type_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_extended_UEIdentityIndexValue, create_dissector_handle(dissect_Extended_UEIdentityIndexValue_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_NB_IoT_DefaultPagingDRX, create_dissector_handle(dissect_NB_IoT_DefaultPagingDRX_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedToResumeListResumeReq, create_dissector_handle(dissect_E_RABFailedToResumeListResumeReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedToResumeItemResumeReq, create_dissector_handle(dissect_E_RABFailedToResumeItemResumeReq_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedToResumeListResumeRes, create_dissector_handle(dissect_E_RABFailedToResumeListResumeRes_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_E_RABFailedToResumeItemResumeRes, create_dissector_handle(dissect_E_RABFailedToResumeItemResumeRes_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_NB_IoT_Paging_eDRXInformation, create_dissector_handle(dissect_NB_IoT_Paging_eDRXInformation_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_UEUserPlaneCIoTSupportIndicator, create_dissector_handle(dissect_UEUserPlaneCIoTSupportIndicator_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_CE_mode_B_SupportIndicator, create_dissector_handle(dissect_CE_mode_B_SupportIndicator_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_SRVCCOperationNotPossible, create_dissector_handle(dissect_SRVCCOperationNotPossible_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_NB_IoT_UEIdentityIndexValue, create_dissector_handle(dissect_NB_IoT_UEIdentityIndexValue_PDU, proto_s1ap));
dissector_add_uint("s1ap.ies", id_RRC_Resume_Cause, create_dissector_handle(dissect_RRC_Establishment_Cause_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_Data_Forwarding_Not_Possible, create_dissector_handle(dissect_Data_Forwarding_Not_Possible_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_Time_Synchronisation_Info, create_dissector_handle(dissect_TimeSynchronisationInfo_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_x2TNLConfigurationInfo, create_dissector_handle(dissect_X2TNLConfigurationInfo_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_eNBX2ExtendedTransportLayerAddresses, create_dissector_handle(dissect_ENBX2ExtTLAs_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_Correlation_ID, create_dissector_handle(dissect_Correlation_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_MDTConfiguration, create_dissector_handle(dissect_MDT_Configuration_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_Time_UE_StayedInCell_EnhancedGranularity, create_dissector_handle(dissect_Time_UE_StayedInCell_EnhancedGranularity_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_HO_Cause, create_dissector_handle(dissect_Cause_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_M3Configuration, create_dissector_handle(dissect_M3Configuration_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_M4Configuration, create_dissector_handle(dissect_M4Configuration_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_M5Configuration, create_dissector_handle(dissect_M5Configuration_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_MDT_Location_Info, create_dissector_handle(dissect_MDT_Location_Info_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_MobilityInformation, create_dissector_handle(dissect_MobilityInformation_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_SignallingBasedMDTPLMNList, create_dissector_handle(dissect_MDTPLMNList_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_ULCOUNTValueExtended, create_dissector_handle(dissect_COUNTValueExtended_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_DLCOUNTValueExtended, create_dissector_handle(dissect_COUNTValueExtended_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_ReceiveStatusOfULPDCPSDUsExtended, create_dissector_handle(dissect_ReceiveStatusOfULPDCPSDUsExtended_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_SIPTO_Correlation_ID, create_dissector_handle(dissect_Correlation_ID_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_TransportInformation, create_dissector_handle(dissect_TransportInformation_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_EmergencyAreaIDListForRestart, create_dissector_handle(dissect_EmergencyAreaIDListForRestart_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_eNBIndirectX2TransportLayerAddresses, create_dissector_handle(dissect_ENBIndirectX2TransportLayerAddresses_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_LoggedMBSFNMDT, create_dissector_handle(dissect_LoggedMBSFNMDT_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_uE_HistoryInformationFromTheUE, create_dissector_handle(dissect_UE_HistoryInformationFromTheUE_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_Muting_Availability_Indication, create_dissector_handle(dissect_MutingAvailabilityIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_Muting_Pattern_Information, create_dissector_handle(dissect_MutingPatternInformation_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_Synchronisation_Information, create_dissector_handle(dissect_SynchronisationInformation_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_ProSeUEtoNetworkRelaying, create_dissector_handle(dissect_ProSeUEtoNetworkRelaying_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_ULCOUNTValuePDCP_SNlength18, create_dissector_handle(dissect_COUNTvaluePDCP_SNlength18_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_DLCOUNTValuePDCP_SNlength18, create_dissector_handle(dissect_COUNTvaluePDCP_SNlength18_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18, create_dissector_handle(dissect_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_M6Configuration, create_dissector_handle(dissect_M6Configuration_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_M7Configuration, create_dissector_handle(dissect_M7Configuration_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_RAT_Type, create_dissector_handle(dissect_RAT_Type_PDU, proto_s1ap));
dissector_add_uint("s1ap.extension", id_BearerType, create_dissector_handle(dissect_BearerType_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_HandoverPreparation, create_dissector_handle(dissect_HandoverRequired_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_HandoverPreparation, create_dissector_handle(dissect_HandoverCommand_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_HandoverPreparation, create_dissector_handle(dissect_HandoverPreparationFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_HandoverResourceAllocation, create_dissector_handle(dissect_HandoverRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_HandoverResourceAllocation, create_dissector_handle(dissect_HandoverRequestAcknowledge_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_HandoverResourceAllocation, create_dissector_handle(dissect_HandoverFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_HandoverNotification, create_dissector_handle(dissect_HandoverNotify_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_PathSwitchRequest, create_dissector_handle(dissect_PathSwitchRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_PathSwitchRequest, create_dissector_handle(dissect_PathSwitchRequestAcknowledge_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_PathSwitchRequest, create_dissector_handle(dissect_PathSwitchRequestFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_E_RABSetup, create_dissector_handle(dissect_E_RABSetupRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_E_RABSetup, create_dissector_handle(dissect_E_RABSetupResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_E_RABModify, create_dissector_handle(dissect_E_RABModifyRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_E_RABModify, create_dissector_handle(dissect_E_RABModifyResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_E_RABRelease, create_dissector_handle(dissect_E_RABReleaseCommand_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_E_RABRelease, create_dissector_handle(dissect_E_RABReleaseResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_E_RABReleaseIndication, create_dissector_handle(dissect_E_RABReleaseIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_InitialContextSetup, create_dissector_handle(dissect_InitialContextSetupRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_InitialContextSetup, create_dissector_handle(dissect_InitialContextSetupResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_InitialContextSetup, create_dissector_handle(dissect_InitialContextSetupFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_UEContextReleaseRequest, create_dissector_handle(dissect_UEContextReleaseRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_Paging, create_dissector_handle(dissect_Paging_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_downlinkNASTransport, create_dissector_handle(dissect_DownlinkNASTransport_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_initialUEMessage, create_dissector_handle(dissect_InitialUEMessage_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_uplinkNASTransport, create_dissector_handle(dissect_UplinkNASTransport_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_NASNonDeliveryIndication, create_dissector_handle(dissect_NASNonDeliveryIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_HandoverCancel, create_dissector_handle(dissect_HandoverCancel_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_HandoverCancel, create_dissector_handle(dissect_HandoverCancelAcknowledge_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_Reset, create_dissector_handle(dissect_Reset_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_Reset, create_dissector_handle(dissect_ResetAcknowledge_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_ErrorIndication, create_dissector_handle(dissect_ErrorIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_S1Setup, create_dissector_handle(dissect_S1SetupRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_S1Setup, create_dissector_handle(dissect_S1SetupResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_S1Setup, create_dissector_handle(dissect_S1SetupFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_DownlinkS1cdma2000tunnelling, create_dissector_handle(dissect_DownlinkS1cdma2000tunnelling_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_ENBConfigurationUpdate, create_dissector_handle(dissect_ENBConfigurationUpdate_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_ENBConfigurationUpdate, create_dissector_handle(dissect_ENBConfigurationUpdateAcknowledge_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_ENBConfigurationUpdate, create_dissector_handle(dissect_ENBConfigurationUpdateFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_MMEConfigurationUpdate, create_dissector_handle(dissect_MMEConfigurationUpdate_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_MMEConfigurationUpdate, create_dissector_handle(dissect_MMEConfigurationUpdateAcknowledge_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_MMEConfigurationUpdate, create_dissector_handle(dissect_MMEConfigurationUpdateFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_UplinkS1cdma2000tunnelling, create_dissector_handle(dissect_UplinkS1cdma2000tunnelling_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_UEContextModification, create_dissector_handle(dissect_UEContextModificationRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_UEContextModification, create_dissector_handle(dissect_UEContextModificationResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_UEContextModification, create_dissector_handle(dissect_UEContextModificationFailure_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_UECapabilityInfoIndication, create_dissector_handle(dissect_UECapabilityInfoIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_UEContextRelease, create_dissector_handle(dissect_UEContextReleaseCommand_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_UEContextRelease, create_dissector_handle(dissect_UEContextReleaseComplete_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_eNBStatusTransfer, create_dissector_handle(dissect_ENBStatusTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_MMEStatusTransfer, create_dissector_handle(dissect_MMEStatusTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_DeactivateTrace, create_dissector_handle(dissect_DeactivateTrace_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_TraceStart, create_dissector_handle(dissect_TraceStart_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_TraceFailureIndication, create_dissector_handle(dissect_TraceFailureIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_LocationReportingControl, create_dissector_handle(dissect_LocationReportingControl_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_LocationReportingFailureIndication, create_dissector_handle(dissect_LocationReportingFailureIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_LocationReport, create_dissector_handle(dissect_LocationReport_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_OverloadStart, create_dissector_handle(dissect_OverloadStart_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_OverloadStop, create_dissector_handle(dissect_OverloadStop_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_WriteReplaceWarning, create_dissector_handle(dissect_WriteReplaceWarningRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_WriteReplaceWarning, create_dissector_handle(dissect_WriteReplaceWarningResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_eNBDirectInformationTransfer, create_dissector_handle(dissect_ENBDirectInformationTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_MMEDirectInformationTransfer, create_dissector_handle(dissect_MMEDirectInformationTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_eNBConfigurationTransfer, create_dissector_handle(dissect_ENBConfigurationTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_MMEConfigurationTransfer, create_dissector_handle(dissect_MMEConfigurationTransfer_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_CellTrafficTrace, create_dissector_handle(dissect_CellTrafficTrace_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_PrivateMessage, create_dissector_handle(dissect_PrivateMessage_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_PWSRestartIndication, create_dissector_handle(dissect_PWSRestartIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_Kill, create_dissector_handle(dissect_KillRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_Kill, create_dissector_handle(dissect_KillResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_downlinkUEAssociatedLPPaTransport, create_dissector_handle(dissect_DownlinkUEAssociatedLPPaTransport_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_uplinkUEAssociatedLPPaTransport, create_dissector_handle(dissect_UplinkUEAssociatedLPPaTransport_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_downlinkNonUEAssociatedLPPaTransport, create_dissector_handle(dissect_DownlinkNonUEAssociatedLPPaTransport_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_uplinkNonUEAssociatedLPPaTransport, create_dissector_handle(dissect_UplinkNonUEAssociatedLPPaTransport_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_UERadioCapabilityMatch, create_dissector_handle(dissect_UERadioCapabilityMatchRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_UERadioCapabilityMatch, create_dissector_handle(dissect_UERadioCapabilityMatchResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_E_RABModificationIndication, create_dissector_handle(dissect_E_RABModificationIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_E_RABModificationIndication, create_dissector_handle(dissect_E_RABModificationConfirm_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_UEContextModificationIndication, create_dissector_handle(dissect_UEContextModificationIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_UEContextModificationIndication, create_dissector_handle(dissect_UEContextModificationConfirm_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_RerouteNASRequest, create_dissector_handle(dissect_RerouteNASRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_PWSFailureIndication, create_dissector_handle(dissect_PWSFailureIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_ConnectionEstablishmentIndication, create_dissector_handle(dissect_ConnectionEstablishmentIndication_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_UEContextSuspend, create_dissector_handle(dissect_UEContextSuspendRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_UEContextSuspend, create_dissector_handle(dissect_UEContextSuspendResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.imsg", id_UEContextResume, create_dissector_handle(dissect_UEContextResumeRequest_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.sout", id_UEContextResume, create_dissector_handle(dissect_UEContextResumeResponse_PDU, proto_s1ap));
dissector_add_uint("s1ap.proc.uout", id_UEContextResume, create_dissector_handle(dissect_UEContextResumeFailure_PDU, proto_s1ap));
#line 460 "./asn1/s1ap/packet-s1ap-template.c"
} else {
if (SctpPort != 0) {
dissector_delete_uint("sctp.port", SctpPort, s1ap_handle);
}
}
SctpPort=gbl_s1apSctpPort;
if (SctpPort != 0) {
dissector_add_uint("sctp.port", SctpPort, s1ap_handle);
}
}
void proto_register_s1ap(void) {
static hf_register_info hf[] = {
{ &hf_s1ap_transportLayerAddressIPv4,
{ "transportLayerAddress(IPv4)", "s1ap.transportLayerAddressIPv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_transportLayerAddressIPv6,
{ "transportLayerAddress(IPv6)", "s1ap.transportLayerAddressIPv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_UTRAN_Trace_ID_TraceID,
{ "TraceID", "s1ap.E_UTRAN_Trace_ID.TraceID",
FT_UINT24, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_UTRAN_Trace_ID_TraceRecordingSessionReference,
{ "TraceRecordingSessionReference", "s1ap.E_UTRAN_Trace_ID.TraceRecordingSessionReference",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_interfacesToTrace_S1_MME,
{ "S1-MME", "s1ap.interfacesToTrace.S1_MME",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_interfacesToTrace), 0x80,
NULL, HFILL }},
{ &hf_s1ap_interfacesToTrace_X2,
{ "X2", "s1ap.interfacesToTrace.X2",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_interfacesToTrace), 0x40,
NULL, HFILL }},
{ &hf_s1ap_interfacesToTrace_Uu,
{ "Uu", "s1ap.interfacesToTrace.Uu",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_interfacesToTrace), 0x20,
NULL, HFILL }},
{ &hf_s1ap_interfacesToTrace_Reserved,
{ "Reserved", "s1ap.interfacesToTrace.Reserved",
FT_UINT8, BASE_HEX, NULL, 0x1f,
NULL, HFILL }},
{ &hf_s1ap_encryptionAlgorithms_EEA1,
{ "128-EEA1", "s1ap.encryptionAlgorithms.EEA1",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x8000,
NULL, HFILL }},
{ &hf_s1ap_encryptionAlgorithms_EEA2,
{ "128-EEA2", "s1ap.encryptionAlgorithms.EEA2",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x4000,
NULL, HFILL }},
{ &hf_s1ap_encryptionAlgorithms_EEA3,
{ "128-EEA3", "s1ap.encryptionAlgorithms.EEA3",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x2000,
NULL, HFILL }},
{ &hf_s1ap_encryptionAlgorithms_Reserved,
{ "Reserved", "s1ap.encryptionAlgorithms.Reserved",
FT_UINT16, BASE_HEX, NULL, 0x1fff,
NULL, HFILL }},
{ &hf_s1ap_integrityProtectionAlgorithms_EIA1,
{ "128-EIA1", "s1ap.integrityProtectionAlgorithms.EIA1",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x8000,
NULL, HFILL }},
{ &hf_s1ap_integrityProtectionAlgorithms_EIA2,
{ "128-EIA2", "s1ap.integrityProtectionAlgorithms.EIA2",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x4000,
NULL, HFILL }},
{ &hf_s1ap_integrityProtectionAlgorithms_EIA3,
{ "128-EIA3", "s1ap.integrityProtectionAlgorithms.EIA3",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x2000,
NULL, HFILL }},
{ &hf_s1ap_integrityProtectionAlgorithms_Reserved,
{ "Reserved", "s1ap.integrityProtectionAlgorithms.Reserved",
FT_UINT16, BASE_HEX, NULL, 0x1fff,
NULL, HFILL }},
{ &hf_s1ap_SerialNumber_gs,
{ "Geographical Scope", "s1ap.SerialNumber.gs",
FT_UINT16, BASE_DEC, VALS(s1ap_serialNumber_gs_vals), 0xc000,
NULL, HFILL }},
{ &hf_s1ap_SerialNumber_msg_code,
{ "Message Code", "s1ap.SerialNumber.msg_code",
FT_UINT16, BASE_DEC, NULL, 0x3ff0,
NULL, HFILL }},
{ &hf_s1ap_SerialNumber_upd_nb,
{ "Update Number", "s1ap.SerialNumber.upd_nb",
FT_UINT16, BASE_DEC, NULL, 0x000f,
NULL, HFILL }},
{ &hf_s1ap_WarningType_value,
{ "Warning Type Value", "s1ap.WarningType.value",
FT_UINT16, BASE_DEC, VALS(s1ap_warningType_vals), 0xfe00,
NULL, HFILL }},
{ &hf_s1ap_WarningType_emergency_user_alert,
{ "Emergency User Alert", "s1ap.WarningType.emergency_user_alert",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0100,
NULL, HFILL }},
{ &hf_s1ap_WarningType_popup,
{ "Popup", "s1ap.WarningType.popup",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0080,
NULL, HFILL }},
{ &hf_s1ap_WarningMessageContents_nb_pages,
{ "Number of Pages", "s1ap.WarningMessageContents.nb_pages",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_WarningMessageContents_decoded_page,
{ "Decoded Page", "lte-rrc.WarningMessageContents.decoded_page",
FT_STRING, STR_UNICODE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_M1,
{ "M1", "s1ap.measurementsToActivate.M1",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x80,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_M2,
{ "M2", "s1ap.measurementsToActivate.M2",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x40,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_M3,
{ "M3", "s1ap.measurementsToActivate.M3",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x20,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_M4,
{ "M4", "s1ap.measurementsToActivate.M4",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x10,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_M5,
{ "M5", "s1ap.measurementsToActivate.M5",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x08,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_LoggingM1FromEventTriggered,
{ "LoggingOfM1FromEventTriggeredMeasurementReports", "s1ap.measurementsToActivate.LoggingM1FromEventTriggered",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x04,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_M6,
{ "M6", "s1ap.measurementsToActivate.M6",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x02,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_M7,
{ "M7", "s1ap.measurementsToActivate.M7",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x01,
NULL, HFILL }},
{ &hf_s1ap_MDT_Location_Info_GNSS,
{ "GNSS", "s1ap.MDT_Location_Info.GNSS",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x80,
NULL, HFILL }},
{ &hf_s1ap_MDT_Location_Info_E_CID,
{ "E-CID", "s1ap.MDT_Location_Info.E_CID",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x40,
NULL, HFILL }},
{ &hf_s1ap_MDT_Location_Info_Reserved,
{ "Reserved", "s1ap.MDT_Location_Info.Reserved",
FT_UINT8, BASE_HEX, NULL, 0x3f,
NULL, HFILL }},
#line 1 "./asn1/s1ap/packet-s1ap-hfarr.c"
{ &hf_s1ap_Additional_GUTI_PDU,
{ "Additional-GUTI", "s1ap.Additional_GUTI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_AssistanceDataForPaging_PDU,
{ "AssistanceDataForPaging", "s1ap.AssistanceDataForPaging_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Bearers_SubjectToStatusTransfer_Item_PDU,
{ "Bearers-SubjectToStatusTransfer-Item", "s1ap.Bearers_SubjectToStatusTransfer_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_BearerType_PDU,
{ "BearerType", "s1ap.BearerType",
FT_UINT32, BASE_DEC, VALS(s1ap_BearerType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_BroadcastCancelledAreaList_PDU,
{ "BroadcastCancelledAreaList", "s1ap.BroadcastCancelledAreaList",
FT_UINT32, BASE_DEC, VALS(s1ap_BroadcastCancelledAreaList_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_BroadcastCompletedAreaList_PDU,
{ "BroadcastCompletedAreaList", "s1ap.BroadcastCompletedAreaList",
FT_UINT32, BASE_DEC, VALS(s1ap_BroadcastCompletedAreaList_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Cause_PDU,
{ "Cause", "s1ap.Cause",
FT_UINT32, BASE_DEC, VALS(s1ap_Cause_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_CellAccessMode_PDU,
{ "CellAccessMode", "s1ap.CellAccessMode",
FT_UINT32, BASE_DEC, VALS(s1ap_CellAccessMode_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_CellIdentifierAndCELevelForCECapableUEs_PDU,
{ "CellIdentifierAndCELevelForCECapableUEs", "s1ap.CellIdentifierAndCELevelForCECapableUEs_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CE_mode_B_SupportIndicator_PDU,
{ "CE-mode-B-SupportIndicator", "s1ap.CE_mode_B_SupportIndicator",
FT_UINT32, BASE_DEC, VALS(s1ap_CE_mode_B_SupportIndicator_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Cdma2000PDU_PDU,
{ "Cdma2000PDU", "s1ap.Cdma2000PDU",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Cdma2000RATType_PDU,
{ "Cdma2000RATType", "s1ap.Cdma2000RATType",
FT_UINT32, BASE_DEC, VALS(s1ap_Cdma2000RATType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Cdma2000SectorID_PDU,
{ "Cdma2000SectorID", "s1ap.Cdma2000SectorID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Cdma2000HOStatus_PDU,
{ "Cdma2000HOStatus", "s1ap.Cdma2000HOStatus",
FT_UINT32, BASE_DEC, VALS(s1ap_Cdma2000HOStatus_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Cdma2000HORequiredIndication_PDU,
{ "Cdma2000HORequiredIndication", "s1ap.Cdma2000HORequiredIndication",
FT_UINT32, BASE_DEC, VALS(s1ap_Cdma2000HORequiredIndication_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Cdma2000OneXSRVCCInfo_PDU,
{ "Cdma2000OneXSRVCCInfo", "s1ap.Cdma2000OneXSRVCCInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Cdma2000OneXRAND_PDU,
{ "Cdma2000OneXRAND", "s1ap.Cdma2000OneXRAND",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CNDomain_PDU,
{ "CNDomain", "s1ap.CNDomain",
FT_UINT32, BASE_DEC, VALS(s1ap_CNDomain_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_ConcurrentWarningMessageIndicator_PDU,
{ "ConcurrentWarningMessageIndicator", "s1ap.ConcurrentWarningMessageIndicator",
FT_UINT32, BASE_DEC, VALS(s1ap_ConcurrentWarningMessageIndicator_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Correlation_ID_PDU,
{ "Correlation-ID", "s1ap.Correlation_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CSFallbackIndicator_PDU,
{ "CSFallbackIndicator", "s1ap.CSFallbackIndicator",
FT_UINT32, BASE_DEC, VALS(s1ap_CSFallbackIndicator_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_AdditionalCSFallbackIndicator_PDU,
{ "AdditionalCSFallbackIndicator", "s1ap.AdditionalCSFallbackIndicator",
FT_UINT32, BASE_DEC, VALS(s1ap_AdditionalCSFallbackIndicator_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_CSG_Id_PDU,
{ "CSG-Id", "s1ap.CSG_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CSG_IdList_PDU,
{ "CSG-IdList", "s1ap.CSG_IdList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CSGMembershipStatus_PDU,
{ "CSGMembershipStatus", "s1ap.CSGMembershipStatus",
FT_UINT32, BASE_DEC, VALS(s1ap_CSGMembershipStatus_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_COUNTValueExtended_PDU,
{ "COUNTValueExtended", "s1ap.COUNTValueExtended_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_COUNTvaluePDCP_SNlength18_PDU,
{ "COUNTvaluePDCP-SNlength18", "s1ap.COUNTvaluePDCP_SNlength18_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CriticalityDiagnostics_PDU,
{ "CriticalityDiagnostics", "s1ap.CriticalityDiagnostics_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_DataCodingScheme_PDU,
{ "DataCodingScheme", "s1ap.DataCodingScheme",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Direct_Forwarding_Path_Availability_PDU,
{ "Direct-Forwarding-Path-Availability", "s1ap.Direct_Forwarding_Path_Availability",
FT_UINT32, BASE_DEC, VALS(s1ap_Direct_Forwarding_Path_Availability_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Data_Forwarding_Not_Possible_PDU,
{ "Data-Forwarding-Not-Possible", "s1ap.Data_Forwarding_Not_Possible",
FT_UINT32, BASE_DEC, VALS(s1ap_Data_Forwarding_Not_Possible_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_PWSfailedECGIList_PDU,
{ "PWSfailedECGIList", "s1ap.PWSfailedECGIList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_EmergencyAreaIDListForRestart_PDU,
{ "EmergencyAreaIDListForRestart", "s1ap.EmergencyAreaIDListForRestart",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_s1ap_Global_ENB_ID_PDU,
{ "Global-ENB-ID", "s1ap.Global_ENB_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_GUMMEIList_PDU,
{ "GUMMEIList", "s1ap.GUMMEIList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_s1ap_ENB_StatusTransfer_TransparentContainer_PDU,
{ "ENB-StatusTransfer-TransparentContainer", "s1ap.ENB_StatusTransfer_TransparentContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENB_UE_S1AP_ID_PDU,
{ "ENB-UE-S1AP-ID", "s1ap.ENB_UE_S1AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBname_PDU,
{ "ENBname", "s1ap.ENBname",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABInformationListItem_PDU,
{ "E-RABInformationListItem", "s1ap.E_RABInformationListItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABList_PDU,
{ "E-RABList", "s1ap.E_RABList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABItem_PDU,
{ "E-RABItem", "s1ap.E_RABItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_EUTRAN_CGI_PDU,
{ "EUTRAN-CGI", "s1ap.EUTRAN_CGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_EUTRANRoundTripDelayEstimationInfo_PDU,
{ "EUTRANRoundTripDelayEstimationInfo", "s1ap.EUTRANRoundTripDelayEstimationInfo",
FT_UINT32, BASE_CUSTOM, CF_FUNC(s1ap_EUTRANRoundTripDelayEstimationInfo_fmt), 0,
NULL, HFILL }},
{ &hf_s1ap_ExpectedUEBehaviour_PDU,
{ "ExpectedUEBehaviour", "s1ap.ExpectedUEBehaviour_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ExtendedRepetitionPeriod_PDU,
{ "ExtendedRepetitionPeriod", "s1ap.ExtendedRepetitionPeriod",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
NULL, HFILL }},
{ &hf_s1ap_Extended_UEIdentityIndexValue_PDU,
{ "Extended-UEIdentityIndexValue", "s1ap.Extended_UEIdentityIndexValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_GUMMEI_PDU,
{ "GUMMEI", "s1ap.GUMMEI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_GUMMEIType_PDU,
{ "GUMMEIType", "s1ap.GUMMEIType",
FT_UINT32, BASE_DEC, VALS(s1ap_GUMMEIType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_GWContextReleaseIndication_PDU,
{ "GWContextReleaseIndication", "s1ap.GWContextReleaseIndication",
FT_UINT32, BASE_DEC, VALS(s1ap_GWContextReleaseIndication_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverRestrictionList_PDU,
{ "HandoverRestrictionList", "s1ap.HandoverRestrictionList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverType_PDU,
{ "HandoverType", "s1ap.HandoverType",
FT_UINT32, BASE_DEC, VALS(s1ap_HandoverType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Masked_IMEISV_PDU,
{ "Masked-IMEISV", "s1ap.Masked_IMEISV",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_InformationOnRecommendedCellsAndENBsForPaging_PDU,
{ "InformationOnRecommendedCellsAndENBsForPaging", "s1ap.InformationOnRecommendedCellsAndENBsForPaging_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_KillAllWarningMessages_PDU,
{ "KillAllWarningMessages", "s1ap.KillAllWarningMessages",
FT_UINT32, BASE_DEC, VALS(s1ap_KillAllWarningMessages_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_LAI_PDU,
{ "LAI", "s1ap.LAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_LPPa_PDU_PDU,
{ "LPPa-PDU", "s1ap.LPPa_PDU",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_LHN_ID_PDU,
{ "LHN-ID", "s1ap.LHN_ID",
FT_STRING, STR_UNICODE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_LoggedMBSFNMDT_PDU,
{ "LoggedMBSFNMDT", "s1ap.LoggedMBSFNMDT_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_M3Configuration_PDU,
{ "M3Configuration", "s1ap.M3Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_M4Configuration_PDU,
{ "M4Configuration", "s1ap.M4Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_M5Configuration_PDU,
{ "M5Configuration", "s1ap.M5Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_M6Configuration_PDU,
{ "M6Configuration", "s1ap.M6Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_M7Configuration_PDU,
{ "M7Configuration", "s1ap.M7Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MDT_Location_Info_PDU,
{ "MDT-Location-Info", "s1ap.MDT_Location_Info",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MDT_Configuration_PDU,
{ "MDT-Configuration", "s1ap.MDT_Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ManagementBasedMDTAllowed_PDU,
{ "ManagementBasedMDTAllowed", "s1ap.ManagementBasedMDTAllowed",
FT_UINT32, BASE_DEC, VALS(s1ap_ManagementBasedMDTAllowed_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_MDTPLMNList_PDU,
{ "MDTPLMNList", "s1ap.MDTPLMNList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PrivacyIndicator_PDU,
{ "PrivacyIndicator", "s1ap.PrivacyIndicator",
FT_UINT32, BASE_DEC, VALS(s1ap_PrivacyIndicator_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_MessageIdentifier_PDU,
{ "MessageIdentifier", "s1ap.MessageIdentifier",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &lte_rrc_messageIdentifier_vals_ext, 0,
NULL, HFILL }},
{ &hf_s1ap_MobilityInformation_PDU,
{ "MobilityInformation", "s1ap.MobilityInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MMEname_PDU,
{ "MMEname", "s1ap.MMEname",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MMERelaySupportIndicator_PDU,
{ "MMERelaySupportIndicator", "s1ap.MMERelaySupportIndicator",
FT_UINT32, BASE_DEC, VALS(s1ap_MMERelaySupportIndicator_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_MME_Group_ID_PDU,
{ "MME-Group-ID", "s1ap.MME_Group_ID",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MME_UE_S1AP_ID_PDU,
{ "MME-UE-S1AP-ID", "s1ap.MME_UE_S1AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MSClassmark2_PDU,
{ "MSClassmark2", "s1ap.MSClassmark2",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MSClassmark3_PDU,
{ "MSClassmark3", "s1ap.MSClassmark3",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MutingAvailabilityIndication_PDU,
{ "MutingAvailabilityIndication", "s1ap.MutingAvailabilityIndication",
FT_UINT32, BASE_DEC, VALS(s1ap_MutingAvailabilityIndication_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_MutingPatternInformation_PDU,
{ "MutingPatternInformation", "s1ap.MutingPatternInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_NAS_PDU_PDU,
{ "NAS-PDU", "s1ap.NAS_PDU",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_NASSecurityParametersfromE_UTRAN_PDU,
{ "NASSecurityParametersfromE-UTRAN", "s1ap.NASSecurityParametersfromE_UTRAN",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_NASSecurityParameterstoE_UTRAN_PDU,
{ "NASSecurityParameterstoE-UTRAN", "s1ap.NASSecurityParameterstoE_UTRAN",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_NB_IoT_DefaultPagingDRX_PDU,
{ "NB-IoT-DefaultPagingDRX", "s1ap.NB_IoT_DefaultPagingDRX",
FT_UINT32, BASE_DEC, VALS(s1ap_NB_IoT_DefaultPagingDRX_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_NB_IoT_Paging_eDRXInformation_PDU,
{ "NB-IoT-Paging-eDRXInformation", "s1ap.NB_IoT_Paging_eDRXInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_NB_IoT_UEIdentityIndexValue_PDU,
{ "NB-IoT-UEIdentityIndexValue", "s1ap.NB_IoT_UEIdentityIndexValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_NumberofBroadcastRequest_PDU,
{ "NumberofBroadcastRequest", "s1ap.NumberofBroadcastRequest",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_OverloadResponse_PDU,
{ "OverloadResponse", "s1ap.OverloadResponse",
FT_UINT32, BASE_DEC, VALS(s1ap_OverloadResponse_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Paging_eDRXInformation_PDU,
{ "Paging-eDRXInformation", "s1ap.Paging_eDRXInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PagingDRX_PDU,
{ "PagingDRX", "s1ap.PagingDRX",
FT_UINT32, BASE_DEC, VALS(s1ap_PagingDRX_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_PagingPriority_PDU,
{ "PagingPriority", "s1ap.PagingPriority",
FT_UINT32, BASE_DEC, VALS(s1ap_PagingPriority_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_ProSeAuthorized_PDU,
{ "ProSeAuthorized", "s1ap.ProSeAuthorized_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ProSeUEtoNetworkRelaying_PDU,
{ "ProSeUEtoNetworkRelaying", "s1ap.ProSeUEtoNetworkRelaying",
FT_UINT32, BASE_DEC, VALS(s1ap_ProSeUEtoNetworkRelaying_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_PS_ServiceNotAvailable_PDU,
{ "PS-ServiceNotAvailable", "s1ap.PS_ServiceNotAvailable",
FT_UINT32, BASE_DEC, VALS(s1ap_PS_ServiceNotAvailable_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_ReceiveStatusOfULPDCPSDUsExtended_PDU,
{ "ReceiveStatusOfULPDCPSDUsExtended", "s1ap.ReceiveStatusOfULPDCPSDUsExtended",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18_PDU,
{ "ReceiveStatusOfULPDCPSDUsPDCP-SNlength18", "s1ap.ReceiveStatusOfULPDCPSDUsPDCP_SNlength18",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_RecommendedCellItem_PDU,
{ "RecommendedCellItem", "s1ap.RecommendedCellItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_RecommendedENBItem_PDU,
{ "RecommendedENBItem", "s1ap.RecommendedENBItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_RelativeMMECapacity_PDU,
{ "RelativeMMECapacity", "s1ap.RelativeMMECapacity",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_RelayNode_Indicator_PDU,
{ "RelayNode-Indicator", "s1ap.RelayNode_Indicator",
FT_UINT32, BASE_DEC, VALS(s1ap_RelayNode_Indicator_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_RAT_Type_PDU,
{ "RAT-Type", "s1ap.RAT_Type",
FT_UINT32, BASE_DEC, VALS(s1ap_RAT_Type_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_RequestType_PDU,
{ "RequestType", "s1ap.RequestType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_RepetitionPeriod_PDU,
{ "RepetitionPeriod", "s1ap.RepetitionPeriod",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
NULL, HFILL }},
{ &hf_s1ap_RRC_Establishment_Cause_PDU,
{ "RRC-Establishment-Cause", "s1ap.RRC_Establishment_Cause",
FT_UINT32, BASE_DEC, VALS(s1ap_RRC_Establishment_Cause_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_ECGIListForRestart_PDU,
{ "ECGIListForRestart", "s1ap.ECGIListForRestart",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Routing_ID_PDU,
{ "Routing-ID", "s1ap.Routing_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SecurityKey_PDU,
{ "SecurityKey", "s1ap.SecurityKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SecurityContext_PDU,
{ "SecurityContext", "s1ap.SecurityContext_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SerialNumber_PDU,
{ "SerialNumber", "s1ap.SerialNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SONInformationReport_PDU,
{ "SONInformationReport", "s1ap.SONInformationReport",
FT_UINT32, BASE_DEC, VALS(s1ap_SONInformationReport_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_SONConfigurationTransfer_PDU,
{ "SONConfigurationTransfer", "s1ap.SONConfigurationTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SynchronisationInformation_PDU,
{ "SynchronisationInformation", "s1ap.SynchronisationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Source_ToTarget_TransparentContainer_PDU,
{ "Source-ToTarget-TransparentContainer", "s1ap.Source_ToTarget_TransparentContainer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SRVCCOperationNotPossible_PDU,
{ "SRVCCOperationNotPossible", "s1ap.SRVCCOperationNotPossible",
FT_UINT32, BASE_DEC, VALS(s1ap_SRVCCOperationNotPossible_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_SRVCCOperationPossible_PDU,
{ "SRVCCOperationPossible", "s1ap.SRVCCOperationPossible",
FT_UINT32, BASE_DEC, VALS(s1ap_SRVCCOperationPossible_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_SRVCCHOIndication_PDU,
{ "SRVCCHOIndication", "s1ap.SRVCCHOIndication",
FT_UINT32, BASE_DEC, VALS(s1ap_SRVCCHOIndication_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_SourceeNB_ToTargeteNB_TransparentContainer_PDU,
{ "SourceeNB-ToTargeteNB-TransparentContainer", "s1ap.SourceeNB_ToTargeteNB_TransparentContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ServedGUMMEIs_PDU,
{ "ServedGUMMEIs", "s1ap.ServedGUMMEIs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ServedPLMNs_PDU,
{ "ServedPLMNs", "s1ap.ServedPLMNs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SubscriberProfileIDforRFP_PDU,
{ "SubscriberProfileIDforRFP", "s1ap.SubscriberProfileIDforRFP",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SupportedTAs_PDU,
{ "SupportedTAs", "s1ap.SupportedTAs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TimeSynchronisationInfo_PDU,
{ "TimeSynchronisationInfo", "s1ap.TimeSynchronisationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_S_TMSI_PDU,
{ "S-TMSI", "s1ap.S_TMSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAI_PDU,
{ "TAI", "s1ap.TAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TargetID_PDU,
{ "TargetID", "s1ap.TargetID",
FT_UINT32, BASE_DEC, VALS(s1ap_TargetID_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_TargeteNB_ToSourceeNB_TransparentContainer_PDU,
{ "TargeteNB-ToSourceeNB-TransparentContainer", "s1ap.TargeteNB_ToSourceeNB_TransparentContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Target_ToSource_TransparentContainer_PDU,
{ "Target-ToSource-TransparentContainer", "s1ap.Target_ToSource_TransparentContainer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TimeToWait_PDU,
{ "TimeToWait", "s1ap.TimeToWait",
FT_UINT32, BASE_DEC, VALS(s1ap_TimeToWait_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_Time_UE_StayedInCell_EnhancedGranularity_PDU,
{ "Time-UE-StayedInCell-EnhancedGranularity", "s1ap.Time_UE_StayedInCell_EnhancedGranularity",
FT_UINT32, BASE_CUSTOM, CF_FUNC(s1ap_Time_UE_StayedInCell_EnhancedGranularity_fmt), 0,
NULL, HFILL }},
{ &hf_s1ap_TransportInformation_PDU,
{ "TransportInformation", "s1ap.TransportInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TransportLayerAddress_PDU,
{ "TransportLayerAddress", "s1ap.TransportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TraceActivation_PDU,
{ "TraceActivation", "s1ap.TraceActivation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_UTRAN_Trace_ID_PDU,
{ "E-UTRAN-Trace-ID", "s1ap.E_UTRAN_Trace_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TrafficLoadReductionIndication_PDU,
{ "TrafficLoadReductionIndication", "s1ap.TrafficLoadReductionIndication",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TunnelInformation_PDU,
{ "TunnelInformation", "s1ap.TunnelInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAIListForRestart_PDU,
{ "TAIListForRestart", "s1ap.TAIListForRestart",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEAggregateMaximumBitrate_PDU,
{ "UEAggregateMaximumBitrate", "s1ap.UEAggregateMaximumBitrate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UE_RetentionInformation_PDU,
{ "UE-RetentionInformation", "s1ap.UE_RetentionInformation",
FT_UINT32, BASE_DEC, VALS(s1ap_UE_RetentionInformation_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_UE_S1AP_IDs_PDU,
{ "UE-S1AP-IDs", "s1ap.UE_S1AP_IDs",
FT_UINT32, BASE_DEC, VALS(s1ap_UE_S1AP_IDs_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_UE_associatedLogicalS1_ConnectionItem_PDU,
{ "UE-associatedLogicalS1-ConnectionItem", "s1ap.UE_associatedLogicalS1_ConnectionItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEIdentityIndexValue_PDU,
{ "UEIdentityIndexValue", "s1ap.UEIdentityIndexValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_s1ap_UE_HistoryInformation_PDU,
{ "UE-HistoryInformation", "s1ap.UE_HistoryInformation",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UE_HistoryInformationFromTheUE_PDU,
{ "UE-HistoryInformationFromTheUE", "s1ap.UE_HistoryInformationFromTheUE",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEPagingID_PDU,
{ "UEPagingID", "s1ap.UEPagingID",
FT_UINT32, BASE_DEC, VALS(s1ap_UEPagingID_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_UERadioCapability_PDU,
{ "UERadioCapability", "s1ap.UERadioCapability",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UERadioCapabilityForPaging_PDU,
{ "UERadioCapabilityForPaging", "s1ap.UERadioCapabilityForPaging",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UESecurityCapabilities_PDU,
{ "UESecurityCapabilities", "s1ap.UESecurityCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UE_Usage_Type_PDU,
{ "UE-Usage-Type", "s1ap.UE_Usage_Type",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UserLocationInformation_PDU,
{ "UserLocationInformation", "s1ap.UserLocationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEUserPlaneCIoTSupportIndicator_PDU,
{ "UEUserPlaneCIoTSupportIndicator", "s1ap.UEUserPlaneCIoTSupportIndicator",
FT_UINT32, BASE_DEC, VALS(s1ap_UEUserPlaneCIoTSupportIndicator_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_VoiceSupportMatchIndicator_PDU,
{ "VoiceSupportMatchIndicator", "s1ap.VoiceSupportMatchIndicator",
FT_UINT32, BASE_DEC, VALS(s1ap_VoiceSupportMatchIndicator_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_WarningAreaList_PDU,
{ "WarningAreaList", "s1ap.WarningAreaList",
FT_UINT32, BASE_DEC, VALS(s1ap_WarningAreaList_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_WarningType_PDU,
{ "WarningType", "s1ap.WarningType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_WarningSecurityInfo_PDU,
{ "WarningSecurityInfo", "s1ap.WarningSecurityInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_WarningMessageContents_PDU,
{ "WarningMessageContents", "s1ap.WarningMessageContents",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_X2TNLConfigurationInfo_PDU,
{ "X2TNLConfigurationInfo", "s1ap.X2TNLConfigurationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBX2ExtTLAs_PDU,
{ "ENBX2ExtTLAs", "s1ap.ENBX2ExtTLAs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBIndirectX2TransportLayerAddresses_PDU,
{ "ENBIndirectX2TransportLayerAddresses", "s1ap.ENBIndirectX2TransportLayerAddresses",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverRequired_PDU,
{ "HandoverRequired", "s1ap.HandoverRequired_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverCommand_PDU,
{ "HandoverCommand", "s1ap.HandoverCommand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSubjecttoDataForwardingList_PDU,
{ "E-RABSubjecttoDataForwardingList", "s1ap.E_RABSubjecttoDataForwardingList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABDataForwardingItem_PDU,
{ "E-RABDataForwardingItem", "s1ap.E_RABDataForwardingItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverPreparationFailure_PDU,
{ "HandoverPreparationFailure", "s1ap.HandoverPreparationFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverRequest_PDU,
{ "HandoverRequest", "s1ap.HandoverRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupListHOReq_PDU,
{ "E-RABToBeSetupListHOReq", "s1ap.E_RABToBeSetupListHOReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupItemHOReq_PDU,
{ "E-RABToBeSetupItemHOReq", "s1ap.E_RABToBeSetupItemHOReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverRequestAcknowledge_PDU,
{ "HandoverRequestAcknowledge", "s1ap.HandoverRequestAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABAdmittedList_PDU,
{ "E-RABAdmittedList", "s1ap.E_RABAdmittedList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABAdmittedItem_PDU,
{ "E-RABAdmittedItem", "s1ap.E_RABAdmittedItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABFailedtoSetupListHOReqAck_PDU,
{ "E-RABFailedtoSetupListHOReqAck", "s1ap.E_RABFailedtoSetupListHOReqAck",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABFailedToSetupItemHOReqAck_PDU,
{ "E-RABFailedToSetupItemHOReqAck", "s1ap.E_RABFailedToSetupItemHOReqAck_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverFailure_PDU,
{ "HandoverFailure", "s1ap.HandoverFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverNotify_PDU,
{ "HandoverNotify", "s1ap.HandoverNotify_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PathSwitchRequest_PDU,
{ "PathSwitchRequest", "s1ap.PathSwitchRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSwitchedDLList_PDU,
{ "E-RABToBeSwitchedDLList", "s1ap.E_RABToBeSwitchedDLList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSwitchedDLItem_PDU,
{ "E-RABToBeSwitchedDLItem", "s1ap.E_RABToBeSwitchedDLItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PathSwitchRequestAcknowledge_PDU,
{ "PathSwitchRequestAcknowledge", "s1ap.PathSwitchRequestAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSwitchedULList_PDU,
{ "E-RABToBeSwitchedULList", "s1ap.E_RABToBeSwitchedULList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSwitchedULItem_PDU,
{ "E-RABToBeSwitchedULItem", "s1ap.E_RABToBeSwitchedULItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PathSwitchRequestFailure_PDU,
{ "PathSwitchRequestFailure", "s1ap.PathSwitchRequestFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverCancel_PDU,
{ "HandoverCancel", "s1ap.HandoverCancel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_HandoverCancelAcknowledge_PDU,
{ "HandoverCancelAcknowledge", "s1ap.HandoverCancelAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupRequest_PDU,
{ "E-RABSetupRequest", "s1ap.E_RABSetupRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupListBearerSUReq_PDU,
{ "E-RABToBeSetupListBearerSUReq", "s1ap.E_RABToBeSetupListBearerSUReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupItemBearerSUReq_PDU,
{ "E-RABToBeSetupItemBearerSUReq", "s1ap.E_RABToBeSetupItemBearerSUReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupResponse_PDU,
{ "E-RABSetupResponse", "s1ap.E_RABSetupResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupListBearerSURes_PDU,
{ "E-RABSetupListBearerSURes", "s1ap.E_RABSetupListBearerSURes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupItemBearerSURes_PDU,
{ "E-RABSetupItemBearerSURes", "s1ap.E_RABSetupItemBearerSURes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABModifyRequest_PDU,
{ "E-RABModifyRequest", "s1ap.E_RABModifyRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeModifiedListBearerModReq_PDU,
{ "E-RABToBeModifiedListBearerModReq", "s1ap.E_RABToBeModifiedListBearerModReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeModifiedItemBearerModReq_PDU,
{ "E-RABToBeModifiedItemBearerModReq", "s1ap.E_RABToBeModifiedItemBearerModReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABModifyResponse_PDU,
{ "E-RABModifyResponse", "s1ap.E_RABModifyResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABModifyListBearerModRes_PDU,
{ "E-RABModifyListBearerModRes", "s1ap.E_RABModifyListBearerModRes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABModifyItemBearerModRes_PDU,
{ "E-RABModifyItemBearerModRes", "s1ap.E_RABModifyItemBearerModRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABReleaseCommand_PDU,
{ "E-RABReleaseCommand", "s1ap.E_RABReleaseCommand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABReleaseResponse_PDU,
{ "E-RABReleaseResponse", "s1ap.E_RABReleaseResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABReleaseListBearerRelComp_PDU,
{ "E-RABReleaseListBearerRelComp", "s1ap.E_RABReleaseListBearerRelComp",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABReleaseItemBearerRelComp_PDU,
{ "E-RABReleaseItemBearerRelComp", "s1ap.E_RABReleaseItemBearerRelComp_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABReleaseIndication_PDU,
{ "E-RABReleaseIndication", "s1ap.E_RABReleaseIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_InitialContextSetupRequest_PDU,
{ "InitialContextSetupRequest", "s1ap.InitialContextSetupRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupListCtxtSUReq_PDU,
{ "E-RABToBeSetupListCtxtSUReq", "s1ap.E_RABToBeSetupListCtxtSUReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupItemCtxtSUReq_PDU,
{ "E-RABToBeSetupItemCtxtSUReq", "s1ap.E_RABToBeSetupItemCtxtSUReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_InitialContextSetupResponse_PDU,
{ "InitialContextSetupResponse", "s1ap.InitialContextSetupResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupListCtxtSURes_PDU,
{ "E-RABSetupListCtxtSURes", "s1ap.E_RABSetupListCtxtSURes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupItemCtxtSURes_PDU,
{ "E-RABSetupItemCtxtSURes", "s1ap.E_RABSetupItemCtxtSURes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_InitialContextSetupFailure_PDU,
{ "InitialContextSetupFailure", "s1ap.InitialContextSetupFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Paging_PDU,
{ "Paging", "s1ap.Paging_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAIList_PDU,
{ "TAIList", "s1ap.TAIList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAIItem_PDU,
{ "TAIItem", "s1ap.TAIItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextReleaseRequest_PDU,
{ "UEContextReleaseRequest", "s1ap.UEContextReleaseRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextReleaseCommand_PDU,
{ "UEContextReleaseCommand", "s1ap.UEContextReleaseCommand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextReleaseComplete_PDU,
{ "UEContextReleaseComplete", "s1ap.UEContextReleaseComplete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextModificationRequest_PDU,
{ "UEContextModificationRequest", "s1ap.UEContextModificationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextModificationResponse_PDU,
{ "UEContextModificationResponse", "s1ap.UEContextModificationResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextModificationFailure_PDU,
{ "UEContextModificationFailure", "s1ap.UEContextModificationFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UERadioCapabilityMatchRequest_PDU,
{ "UERadioCapabilityMatchRequest", "s1ap.UERadioCapabilityMatchRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UERadioCapabilityMatchResponse_PDU,
{ "UERadioCapabilityMatchResponse", "s1ap.UERadioCapabilityMatchResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_DownlinkNASTransport_PDU,
{ "DownlinkNASTransport", "s1ap.DownlinkNASTransport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_InitialUEMessage_PDU,
{ "InitialUEMessage", "s1ap.InitialUEMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UplinkNASTransport_PDU,
{ "UplinkNASTransport", "s1ap.UplinkNASTransport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_NASNonDeliveryIndication_PDU,
{ "NASNonDeliveryIndication", "s1ap.NASNonDeliveryIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_RerouteNASRequest_PDU,
{ "RerouteNASRequest", "s1ap.RerouteNASRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_S1_Message_PDU,
{ "S1-Message", "s1ap.S1_Message",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Reset_PDU,
{ "Reset", "s1ap.Reset_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ResetType_PDU,
{ "ResetType", "s1ap.ResetType",
FT_UINT32, BASE_DEC, VALS(s1ap_ResetType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_ResetAcknowledge_PDU,
{ "ResetAcknowledge", "s1ap.ResetAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UE_associatedLogicalS1_ConnectionListResAck_PDU,
{ "UE-associatedLogicalS1-ConnectionListResAck", "s1ap.UE_associatedLogicalS1_ConnectionListResAck",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ErrorIndication_PDU,
{ "ErrorIndication", "s1ap.ErrorIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_S1SetupRequest_PDU,
{ "S1SetupRequest", "s1ap.S1SetupRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_S1SetupResponse_PDU,
{ "S1SetupResponse", "s1ap.S1SetupResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_S1SetupFailure_PDU,
{ "S1SetupFailure", "s1ap.S1SetupFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBConfigurationUpdate_PDU,
{ "ENBConfigurationUpdate", "s1ap.ENBConfigurationUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBConfigurationUpdateAcknowledge_PDU,
{ "ENBConfigurationUpdateAcknowledge", "s1ap.ENBConfigurationUpdateAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBConfigurationUpdateFailure_PDU,
{ "ENBConfigurationUpdateFailure", "s1ap.ENBConfigurationUpdateFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MMEConfigurationUpdate_PDU,
{ "MMEConfigurationUpdate", "s1ap.MMEConfigurationUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MMEConfigurationUpdateAcknowledge_PDU,
{ "MMEConfigurationUpdateAcknowledge", "s1ap.MMEConfigurationUpdateAcknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MMEConfigurationUpdateFailure_PDU,
{ "MMEConfigurationUpdateFailure", "s1ap.MMEConfigurationUpdateFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_DownlinkS1cdma2000tunnelling_PDU,
{ "DownlinkS1cdma2000tunnelling", "s1ap.DownlinkS1cdma2000tunnelling_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UplinkS1cdma2000tunnelling_PDU,
{ "UplinkS1cdma2000tunnelling", "s1ap.UplinkS1cdma2000tunnelling_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UECapabilityInfoIndication_PDU,
{ "UECapabilityInfoIndication", "s1ap.UECapabilityInfoIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBStatusTransfer_PDU,
{ "ENBStatusTransfer", "s1ap.ENBStatusTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MMEStatusTransfer_PDU,
{ "MMEStatusTransfer", "s1ap.MMEStatusTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TraceStart_PDU,
{ "TraceStart", "s1ap.TraceStart_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TraceFailureIndication_PDU,
{ "TraceFailureIndication", "s1ap.TraceFailureIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_DeactivateTrace_PDU,
{ "DeactivateTrace", "s1ap.DeactivateTrace_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CellTrafficTrace_PDU,
{ "CellTrafficTrace", "s1ap.CellTrafficTrace_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_LocationReportingControl_PDU,
{ "LocationReportingControl", "s1ap.LocationReportingControl_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_LocationReportingFailureIndication_PDU,
{ "LocationReportingFailureIndication", "s1ap.LocationReportingFailureIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_LocationReport_PDU,
{ "LocationReport", "s1ap.LocationReport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_OverloadStart_PDU,
{ "OverloadStart", "s1ap.OverloadStart_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_OverloadStop_PDU,
{ "OverloadStop", "s1ap.OverloadStop_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_WriteReplaceWarningRequest_PDU,
{ "WriteReplaceWarningRequest", "s1ap.WriteReplaceWarningRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_WriteReplaceWarningResponse_PDU,
{ "WriteReplaceWarningResponse", "s1ap.WriteReplaceWarningResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBDirectInformationTransfer_PDU,
{ "ENBDirectInformationTransfer", "s1ap.ENBDirectInformationTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Inter_SystemInformationTransferType_PDU,
{ "Inter-SystemInformationTransferType", "s1ap.Inter_SystemInformationTransferType",
FT_UINT32, BASE_DEC, VALS(s1ap_Inter_SystemInformationTransferType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_MMEDirectInformationTransfer_PDU,
{ "MMEDirectInformationTransfer", "s1ap.MMEDirectInformationTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBConfigurationTransfer_PDU,
{ "ENBConfigurationTransfer", "s1ap.ENBConfigurationTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MMEConfigurationTransfer_PDU,
{ "MMEConfigurationTransfer", "s1ap.MMEConfigurationTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PrivateMessage_PDU,
{ "PrivateMessage", "s1ap.PrivateMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_KillRequest_PDU,
{ "KillRequest", "s1ap.KillRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_KillResponse_PDU,
{ "KillResponse", "s1ap.KillResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PWSRestartIndication_PDU,
{ "PWSRestartIndication", "s1ap.PWSRestartIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PWSFailureIndication_PDU,
{ "PWSFailureIndication", "s1ap.PWSFailureIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_DownlinkUEAssociatedLPPaTransport_PDU,
{ "DownlinkUEAssociatedLPPaTransport", "s1ap.DownlinkUEAssociatedLPPaTransport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UplinkUEAssociatedLPPaTransport_PDU,
{ "UplinkUEAssociatedLPPaTransport", "s1ap.UplinkUEAssociatedLPPaTransport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_DownlinkNonUEAssociatedLPPaTransport_PDU,
{ "DownlinkNonUEAssociatedLPPaTransport", "s1ap.DownlinkNonUEAssociatedLPPaTransport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UplinkNonUEAssociatedLPPaTransport_PDU,
{ "UplinkNonUEAssociatedLPPaTransport", "s1ap.UplinkNonUEAssociatedLPPaTransport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABModificationIndication_PDU,
{ "E-RABModificationIndication", "s1ap.E_RABModificationIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeModifiedListBearerModInd_PDU,
{ "E-RABToBeModifiedListBearerModInd", "s1ap.E_RABToBeModifiedListBearerModInd",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeModifiedItemBearerModInd_PDU,
{ "E-RABToBeModifiedItemBearerModInd", "s1ap.E_RABToBeModifiedItemBearerModInd_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABNotToBeModifiedListBearerModInd_PDU,
{ "E-RABNotToBeModifiedListBearerModInd", "s1ap.E_RABNotToBeModifiedListBearerModInd",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABNotToBeModifiedItemBearerModInd_PDU,
{ "E-RABNotToBeModifiedItemBearerModInd", "s1ap.E_RABNotToBeModifiedItemBearerModInd_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CSGMembershipInfo_PDU,
{ "CSGMembershipInfo", "s1ap.CSGMembershipInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABModificationConfirm_PDU,
{ "E-RABModificationConfirm", "s1ap.E_RABModificationConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABModifyListBearerModConf_PDU,
{ "E-RABModifyListBearerModConf", "s1ap.E_RABModifyListBearerModConf",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABModifyItemBearerModConf_PDU,
{ "E-RABModifyItemBearerModConf", "s1ap.E_RABModifyItemBearerModConf_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextModificationIndication_PDU,
{ "UEContextModificationIndication", "s1ap.UEContextModificationIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextModificationConfirm_PDU,
{ "UEContextModificationConfirm", "s1ap.UEContextModificationConfirm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextSuspendRequest_PDU,
{ "UEContextSuspendRequest", "s1ap.UEContextSuspendRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextSuspendResponse_PDU,
{ "UEContextSuspendResponse", "s1ap.UEContextSuspendResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextResumeRequest_PDU,
{ "UEContextResumeRequest", "s1ap.UEContextResumeRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABFailedToResumeListResumeReq_PDU,
{ "E-RABFailedToResumeListResumeReq", "s1ap.E_RABFailedToResumeListResumeReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABFailedToResumeItemResumeReq_PDU,
{ "E-RABFailedToResumeItemResumeReq", "s1ap.E_RABFailedToResumeItemResumeReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextResumeResponse_PDU,
{ "UEContextResumeResponse", "s1ap.UEContextResumeResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABFailedToResumeListResumeRes_PDU,
{ "E-RABFailedToResumeListResumeRes", "s1ap.E_RABFailedToResumeListResumeRes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABFailedToResumeItemResumeRes_PDU,
{ "E-RABFailedToResumeItemResumeRes", "s1ap.E_RABFailedToResumeItemResumeRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UEContextResumeFailure_PDU,
{ "UEContextResumeFailure", "s1ap.UEContextResumeFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ConnectionEstablishmentIndication_PDU,
{ "ConnectionEstablishmentIndication", "s1ap.ConnectionEstablishmentIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_S1AP_PDU_PDU,
{ "S1AP-PDU", "s1ap.S1AP_PDU",
FT_UINT32, BASE_DEC, VALS(s1ap_S1AP_PDU_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_s1ap_SONtransferApplicationIdentity_PDU,
{ "SONtransferApplicationIdentity", "s1ap.SONtransferApplicationIdentity",
FT_UINT32, BASE_DEC, VALS(s1ap_SONtransferApplicationIdentity_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_s1ap_SONtransferRequestContainer_PDU,
{ "SONtransferRequestContainer", "s1ap.SONtransferRequestContainer",
FT_UINT32, BASE_DEC, VALS(s1ap_SONtransferRequestContainer_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_s1ap_SONtransferResponseContainer_PDU,
{ "SONtransferResponseContainer", "s1ap.SONtransferResponseContainer",
FT_UINT32, BASE_DEC, VALS(s1ap_SONtransferResponseContainer_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_s1ap_SONtransferCause_PDU,
{ "SONtransferCause", "s1ap.SONtransferCause",
FT_UINT32, BASE_DEC, VALS(s1ap_SONtransferCause_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_local,
{ "local", "s1ap.local",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_s1ap_global,
{ "global", "s1ap.global",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ProtocolIE_Container_item,
{ "ProtocolIE-Field", "s1ap.ProtocolIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_id,
{ "id", "s1ap.id",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &s1ap_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_s1ap_criticality,
{ "criticality", "s1ap.criticality",
FT_UINT32, BASE_DEC, VALS(s1ap_Criticality_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_ie_field_value,
{ "value", "s1ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_ie_field_value", HFILL }},
{ &hf_s1ap_ProtocolIE_ContainerList_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ProtocolExtensionContainer_item,
{ "ProtocolExtensionField", "s1ap.ProtocolExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ext_id,
{ "id", "s1ap.id",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &s1ap_ProtocolIE_ID_vals_ext, 0,
"ProtocolExtensionID", HFILL }},
{ &hf_s1ap_extensionValue,
{ "extensionValue", "s1ap.extensionValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PrivateIE_Container_item,
{ "PrivateIE-Field", "s1ap.PrivateIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_private_id,
{ "id", "s1ap.id",
FT_UINT32, BASE_DEC, VALS(s1ap_PrivateIE_ID_vals), 0,
"PrivateIE_ID", HFILL }},
{ &hf_s1ap_value,
{ "value", "s1ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_gUMMEI,
{ "gUMMEI", "s1ap.gUMMEI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_m_TMSI,
{ "m-TMSI", "s1ap.m_TMSI",
FT_UINT32, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_iE_Extensions,
{ "iE-Extensions", "s1ap.iE_Extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_s1ap_cellBased,
{ "cellBased", "s1ap.cellBased_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellBasedMDT", HFILL }},
{ &hf_s1ap_tABased,
{ "tABased", "s1ap.tABased_element",
FT_NONE, BASE_NONE, NULL, 0,
"TABasedMDT", HFILL }},
{ &hf_s1ap_pLMNWide,
{ "pLMNWide", "s1ap.pLMNWide_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_tAIBased,
{ "tAIBased", "s1ap.tAIBased_element",
FT_NONE, BASE_NONE, NULL, 0,
"TAIBasedMDT", HFILL }},
{ &hf_s1ap_priorityLevel,
{ "priorityLevel", "s1ap.priorityLevel",
FT_UINT32, BASE_DEC, VALS(s1ap_PriorityLevel_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_pre_emptionCapability,
{ "pre-emptionCapability", "s1ap.pre_emptionCapability",
FT_UINT32, BASE_DEC, VALS(s1ap_Pre_emptionCapability_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_pre_emptionVulnerability,
{ "pre-emptionVulnerability", "s1ap.pre_emptionVulnerability",
FT_UINT32, BASE_DEC, VALS(s1ap_Pre_emptionVulnerability_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_cellIdentifierAndCELevelForCECapableUEs,
{ "cellIdentifierAndCELevelForCECapableUEs", "s1ap.cellIdentifierAndCELevelForCECapableUEs_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_assistanceDataForRecommendedCells,
{ "assistanceDataForRecommendedCells", "s1ap.assistanceDataForRecommendedCells_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_assistanceDataForCECapableUEs,
{ "assistanceDataForCECapableUEs", "s1ap.assistanceDataForCECapableUEs_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_pagingAttemptInformation,
{ "pagingAttemptInformation", "s1ap.pagingAttemptInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_recommendedCellsForPaging,
{ "recommendedCellsForPaging", "s1ap.recommendedCellsForPaging_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_Bearers_SubjectToStatusTransferList_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_e_RAB_ID,
{ "e-RAB-ID", "s1ap.e_RAB_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_uL_COUNTvalue,
{ "uL-COUNTvalue", "s1ap.uL_COUNTvalue_element",
FT_NONE, BASE_NONE, NULL, 0,
"COUNTvalue", HFILL }},
{ &hf_s1ap_dL_COUNTvalue,
{ "dL-COUNTvalue", "s1ap.dL_COUNTvalue_element",
FT_NONE, BASE_NONE, NULL, 0,
"COUNTvalue", HFILL }},
{ &hf_s1ap_receiveStatusofULPDCPSDUs,
{ "receiveStatusofULPDCPSDUs", "s1ap.receiveStatusofULPDCPSDUs",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_BPLMNs_item,
{ "PLMNidentity", "s1ap.PLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cellID_Cancelled,
{ "cellID-Cancelled", "s1ap.cellID_Cancelled",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_tAI_Cancelled,
{ "tAI-Cancelled", "s1ap.tAI_Cancelled",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_emergencyAreaID_Cancelled,
{ "emergencyAreaID-Cancelled", "s1ap.emergencyAreaID_Cancelled",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cellID_Broadcast,
{ "cellID-Broadcast", "s1ap.cellID_Broadcast",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_tAI_Broadcast,
{ "tAI-Broadcast", "s1ap.tAI_Broadcast",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_emergencyAreaID_Broadcast,
{ "emergencyAreaID-Broadcast", "s1ap.emergencyAreaID_Broadcast",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CancelledCellinEAI_item,
{ "CancelledCellinEAI-Item", "s1ap.CancelledCellinEAI_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eCGI,
{ "eCGI", "s1ap.eCGI_element",
FT_NONE, BASE_NONE, NULL, 0,
"EUTRAN_CGI", HFILL }},
{ &hf_s1ap_numberOfBroadcasts,
{ "numberOfBroadcasts", "s1ap.numberOfBroadcasts",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CancelledCellinTAI_item,
{ "CancelledCellinTAI-Item", "s1ap.CancelledCellinTAI_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_radioNetwork,
{ "radioNetwork", "s1ap.radioNetwork",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &s1ap_CauseRadioNetwork_vals_ext, 0,
"CauseRadioNetwork", HFILL }},
{ &hf_s1ap_transport,
{ "transport", "s1ap.transport",
FT_UINT32, BASE_DEC, VALS(s1ap_CauseTransport_vals), 0,
"CauseTransport", HFILL }},
{ &hf_s1ap_nas,
{ "nas", "s1ap.nas",
FT_UINT32, BASE_DEC, VALS(s1ap_CauseNas_vals), 0,
"CauseNas", HFILL }},
{ &hf_s1ap_protocol,
{ "protocol", "s1ap.protocol",
FT_UINT32, BASE_DEC, VALS(s1ap_CauseProtocol_vals), 0,
"CauseProtocol", HFILL }},
{ &hf_s1ap_misc,
{ "misc", "s1ap.misc",
FT_UINT32, BASE_DEC, VALS(s1ap_CauseMisc_vals), 0,
"CauseMisc", HFILL }},
{ &hf_s1ap_global_Cell_ID,
{ "global-Cell-ID", "s1ap.global_Cell_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
"EUTRAN_CGI", HFILL }},
{ &hf_s1ap_cELevel,
{ "cELevel", "s1ap.cELevel",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CellID_Broadcast_item,
{ "CellID-Broadcast-Item", "s1ap.CellID_Broadcast_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CellID_Cancelled_item,
{ "CellID-Cancelled-Item", "s1ap.CellID_Cancelled_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cellIdListforMDT,
{ "cellIdListforMDT", "s1ap.cellIdListforMDT",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CellIdListforMDT_item,
{ "EUTRAN-CGI", "s1ap.EUTRAN_CGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cdma2000OneXMEID,
{ "cdma2000OneXMEID", "s1ap.cdma2000OneXMEID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cdma2000OneXMSI,
{ "cdma2000OneXMSI", "s1ap.cdma2000OneXMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cdma2000OneXPilot,
{ "cdma2000OneXPilot", "s1ap.cdma2000OneXPilot",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cell_Size,
{ "cell-Size", "s1ap.cell_Size",
FT_UINT32, BASE_DEC, VALS(s1ap_Cell_Size_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_pLMNidentity,
{ "pLMNidentity", "s1ap.pLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_lAC,
{ "lAC", "s1ap.lAC",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cI,
{ "cI", "s1ap.cI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_rAC,
{ "rAC", "s1ap.rAC",
FT_UINT8, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CSG_IdList_item,
{ "CSG-IdList-Item", "s1ap.CSG_IdList_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cSG_Id,
{ "cSG-Id", "s1ap.cSG_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_pDCP_SN,
{ "pDCP-SN", "s1ap.pDCP_SN",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_hFN,
{ "hFN", "s1ap.hFN",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_pDCP_SNExtended,
{ "pDCP-SNExtended", "s1ap.pDCP_SNExtended",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_hFNModified,
{ "hFNModified", "s1ap.hFNModified",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_pDCP_SNlength18,
{ "pDCP-SNlength18", "s1ap.pDCP_SNlength18",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_hFNforPDCP_SNlength18,
{ "hFNforPDCP-SNlength18", "s1ap.hFNforPDCP_SNlength18",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_procedureCode,
{ "procedureCode", "s1ap.procedureCode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &s1ap_ProcedureCode_vals_ext, 0,
NULL, HFILL }},
{ &hf_s1ap_triggeringMessage,
{ "triggeringMessage", "s1ap.triggeringMessage",
FT_UINT32, BASE_DEC, VALS(s1ap_TriggeringMessage_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_procedureCriticality,
{ "procedureCriticality", "s1ap.procedureCriticality",
FT_UINT32, BASE_DEC, VALS(s1ap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_s1ap_iEsCriticalityDiagnostics,
{ "iEsCriticalityDiagnostics", "s1ap.iEsCriticalityDiagnostics",
FT_UINT32, BASE_DEC, NULL, 0,
"CriticalityDiagnostics_IE_List", HFILL }},
{ &hf_s1ap_CriticalityDiagnostics_IE_List_item,
{ "CriticalityDiagnostics-IE-Item", "s1ap.CriticalityDiagnostics_IE_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_iECriticality,
{ "iECriticality", "s1ap.iECriticality",
FT_UINT32, BASE_DEC, VALS(s1ap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_s1ap_iE_ID,
{ "iE-ID", "s1ap.iE_ID",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &s1ap_ProtocolIE_ID_vals_ext, 0,
"ProtocolIE_ID", HFILL }},
{ &hf_s1ap_typeOfError,
{ "typeOfError", "s1ap.typeOfError",
FT_UINT32, BASE_DEC, VALS(s1ap_TypeOfError_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_ECGIList_item,
{ "EUTRAN-CGI", "s1ap.EUTRAN_CGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_PWSfailedECGIList_item,
{ "EUTRAN-CGI", "s1ap.EUTRAN_CGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_EmergencyAreaIDList_item,
{ "EmergencyAreaID", "s1ap.EmergencyAreaID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_EmergencyAreaID_Broadcast_item,
{ "EmergencyAreaID-Broadcast-Item", "s1ap.EmergencyAreaID_Broadcast_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_emergencyAreaID,
{ "emergencyAreaID", "s1ap.emergencyAreaID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_completedCellinEAI,
{ "completedCellinEAI", "s1ap.completedCellinEAI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_EmergencyAreaID_Cancelled_item,
{ "EmergencyAreaID-Cancelled-Item", "s1ap.EmergencyAreaID_Cancelled_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cancelledCellinEAI,
{ "cancelledCellinEAI", "s1ap.cancelledCellinEAI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CompletedCellinEAI_item,
{ "CompletedCellinEAI-Item", "s1ap.CompletedCellinEAI_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ECGI_List_item,
{ "EUTRAN-CGI", "s1ap.EUTRAN_CGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_EmergencyAreaIDListForRestart_item,
{ "EmergencyAreaID", "s1ap.EmergencyAreaID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_macroENB_ID,
{ "macroENB-ID", "s1ap.macroENB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_20", HFILL }},
{ &hf_s1ap_homeENB_ID,
{ "homeENB-ID", "s1ap.homeENB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_28", HFILL }},
{ &hf_s1ap_lAI,
{ "lAI", "s1ap.lAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eNB_ID,
{ "eNB-ID", "s1ap.eNB_ID",
FT_UINT32, BASE_DEC, VALS(s1ap_ENB_ID_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_GUMMEIList_item,
{ "GUMMEI", "s1ap.GUMMEI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_bearers_SubjectToStatusTransferList,
{ "bearers-SubjectToStatusTransferList", "s1ap.bearers_SubjectToStatusTransferList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBX2TLAs_item,
{ "TransportLayerAddress", "s1ap.TransportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_EPLMNs_item,
{ "PLMNidentity", "s1ap.PLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABInformationList_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_dL_Forwarding,
{ "dL-Forwarding", "s1ap.dL_Forwarding",
FT_UINT32, BASE_DEC, VALS(s1ap_DL_Forwarding_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABList_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cause,
{ "cause", "s1ap.cause",
FT_UINT32, BASE_DEC, VALS(s1ap_Cause_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_qCI,
{ "qCI", "s1ap.qCI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_allocationRetentionPriority,
{ "allocationRetentionPriority", "s1ap.allocationRetentionPriority_element",
FT_NONE, BASE_NONE, NULL, 0,
"AllocationAndRetentionPriority", HFILL }},
{ &hf_s1ap_gbrQosInformation,
{ "gbrQosInformation", "s1ap.gbrQosInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
"GBR_QosInformation", HFILL }},
{ &hf_s1ap_cell_ID,
{ "cell-ID", "s1ap.cell_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"CellIdentity", HFILL }},
{ &hf_s1ap_expectedActivity,
{ "expectedActivity", "s1ap.expectedActivity_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExpectedUEActivityBehaviour", HFILL }},
{ &hf_s1ap_expectedHOInterval,
{ "expectedHOInterval", "s1ap.expectedHOInterval",
FT_UINT32, BASE_DEC, VALS(s1ap_ExpectedHOInterval_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_expectedActivityPeriod,
{ "expectedActivityPeriod", "s1ap.expectedActivityPeriod",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
NULL, HFILL }},
{ &hf_s1ap_expectedIdlePeriod,
{ "expectedIdlePeriod", "s1ap.expectedIdlePeriod",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
NULL, HFILL }},
{ &hf_s1ap_sourceofUEActivityBehaviourInformation,
{ "sourceofUEActivityBehaviourInformation", "s1ap.sourceofUEActivityBehaviourInformation",
FT_UINT32, BASE_DEC, VALS(s1ap_SourceOfUEActivityBehaviourInformation_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_ForbiddenTAs_item,
{ "ForbiddenTAs-Item", "s1ap.ForbiddenTAs_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_pLMN_Identity,
{ "pLMN-Identity", "s1ap.pLMN_Identity",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMNidentity", HFILL }},
{ &hf_s1ap_forbiddenTACs,
{ "forbiddenTACs", "s1ap.forbiddenTACs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ForbiddenTACs_item,
{ "TAC", "s1ap.TAC",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ForbiddenLAs_item,
{ "ForbiddenLAs-Item", "s1ap.ForbiddenLAs_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_forbiddenLACs,
{ "forbiddenLACs", "s1ap.forbiddenLACs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ForbiddenLACs_item,
{ "LAC", "s1ap.LAC",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_e_RAB_MaximumBitrateDL,
{ "e-RAB-MaximumBitrateDL", "s1ap.e_RAB_MaximumBitrateDL",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
"BitRate", HFILL }},
{ &hf_s1ap_e_RAB_MaximumBitrateUL,
{ "e-RAB-MaximumBitrateUL", "s1ap.e_RAB_MaximumBitrateUL",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
"BitRate", HFILL }},
{ &hf_s1ap_e_RAB_GuaranteedBitrateDL,
{ "e-RAB-GuaranteedBitrateDL", "s1ap.e_RAB_GuaranteedBitrateDL",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
"BitRate", HFILL }},
{ &hf_s1ap_e_RAB_GuaranteedBitrateUL,
{ "e-RAB-GuaranteedBitrateUL", "s1ap.e_RAB_GuaranteedBitrateUL",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
"BitRate", HFILL }},
{ &hf_s1ap_mME_Group_ID,
{ "mME-Group-ID", "s1ap.mME_Group_ID",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_mME_Code,
{ "mME-Code", "s1ap.mME_Code",
FT_UINT8, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_servingPLMN,
{ "servingPLMN", "s1ap.servingPLMN",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMNidentity", HFILL }},
{ &hf_s1ap_equivalentPLMNs,
{ "equivalentPLMNs", "s1ap.equivalentPLMNs",
FT_UINT32, BASE_DEC, NULL, 0,
"EPLMNs", HFILL }},
{ &hf_s1ap_forbiddenTAs,
{ "forbiddenTAs", "s1ap.forbiddenTAs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_forbiddenLAs,
{ "forbiddenLAs", "s1ap.forbiddenLAs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_forbiddenInterRATs,
{ "forbiddenInterRATs", "s1ap.forbiddenInterRATs",
FT_UINT32, BASE_DEC, VALS(s1ap_ForbiddenInterRATs_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate,
{ "measurementsToActivate", "s1ap.measurementsToActivate",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_m1reportingTrigger,
{ "m1reportingTrigger", "s1ap.m1reportingTrigger",
FT_UINT32, BASE_DEC, VALS(s1ap_M1ReportingTrigger_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_m1thresholdeventA2,
{ "m1thresholdeventA2", "s1ap.m1thresholdeventA2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_m1periodicReporting,
{ "m1periodicReporting", "s1ap.m1periodicReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_recommendENBsForPaging,
{ "recommendENBsForPaging", "s1ap.recommendENBsForPaging_element",
FT_NONE, BASE_NONE, NULL, 0,
"RecommendedENBsForPaging", HFILL }},
{ &hf_s1ap_e_UTRAN_Cell,
{ "e-UTRAN-Cell", "s1ap.e_UTRAN_Cell_element",
FT_NONE, BASE_NONE, NULL, 0,
"LastVisitedEUTRANCellInformation", HFILL }},
{ &hf_s1ap_uTRAN_Cell,
{ "uTRAN-Cell", "s1ap.uTRAN_Cell",
FT_BYTES, BASE_NONE, NULL, 0,
"LastVisitedUTRANCellInformation", HFILL }},
{ &hf_s1ap_gERAN_Cell,
{ "gERAN-Cell", "s1ap.gERAN_Cell",
FT_UINT32, BASE_DEC, VALS(s1ap_LastVisitedGERANCellInformation_vals), 0,
"LastVisitedGERANCellInformation", HFILL }},
{ &hf_s1ap_cellType,
{ "cellType", "s1ap.cellType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_time_UE_StayedInCell,
{ "time-UE-StayedInCell", "s1ap.time_UE_StayedInCell",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
NULL, HFILL }},
{ &hf_s1ap_undefined,
{ "undefined", "s1ap.undefined_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_pattern_period,
{ "pattern-period", "s1ap.pattern_period",
FT_UINT32, BASE_DEC, VALS(s1ap_T_pattern_period_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_pattern_offset,
{ "pattern-offset", "s1ap.pattern_offset",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_10239_", HFILL }},
{ &hf_s1ap_loggingInterval,
{ "loggingInterval", "s1ap.loggingInterval",
FT_UINT32, BASE_DEC, VALS(s1ap_LoggingInterval_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_loggingDuration,
{ "loggingDuration", "s1ap.loggingDuration",
FT_UINT32, BASE_DEC, VALS(s1ap_LoggingDuration_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_mBSFN_ResultToLog,
{ "mBSFN-ResultToLog", "s1ap.mBSFN_ResultToLog",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_m3period,
{ "m3period", "s1ap.m3period",
FT_UINT32, BASE_DEC, VALS(s1ap_M3period_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_m4period,
{ "m4period", "s1ap.m4period",
FT_UINT32, BASE_DEC, VALS(s1ap_M4period_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_m4_links_to_log,
{ "m4-links-to-log", "s1ap.m4_links_to_log",
FT_UINT32, BASE_DEC, VALS(s1ap_Links_to_log_vals), 0,
"Links_to_log", HFILL }},
{ &hf_s1ap_m5period,
{ "m5period", "s1ap.m5period",
FT_UINT32, BASE_DEC, VALS(s1ap_M5period_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_m5_links_to_log,
{ "m5-links-to-log", "s1ap.m5_links_to_log",
FT_UINT32, BASE_DEC, VALS(s1ap_Links_to_log_vals), 0,
"Links_to_log", HFILL }},
{ &hf_s1ap_m6report_Interval,
{ "m6report-Interval", "s1ap.m6report_Interval",
FT_UINT32, BASE_DEC, VALS(s1ap_M6report_Interval_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_m6delay_threshold,
{ "m6delay-threshold", "s1ap.m6delay_threshold",
FT_UINT32, BASE_DEC, VALS(s1ap_M6delay_threshold_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_m6_links_to_log,
{ "m6-links-to-log", "s1ap.m6_links_to_log",
FT_UINT32, BASE_DEC, VALS(s1ap_Links_to_log_vals), 0,
"Links_to_log", HFILL }},
{ &hf_s1ap_m7period,
{ "m7period", "s1ap.m7period",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_m7_links_to_log,
{ "m7-links-to-log", "s1ap.m7_links_to_log",
FT_UINT32, BASE_DEC, VALS(s1ap_Links_to_log_vals), 0,
"Links_to_log", HFILL }},
{ &hf_s1ap_mdt_Activation,
{ "mdt-Activation", "s1ap.mdt_Activation",
FT_UINT32, BASE_DEC, VALS(s1ap_MDT_Activation_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_areaScopeOfMDT,
{ "areaScopeOfMDT", "s1ap.areaScopeOfMDT",
FT_UINT32, BASE_DEC, VALS(s1ap_AreaScopeOfMDT_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_mDTMode,
{ "mDTMode", "s1ap.mDTMode",
FT_UINT32, BASE_DEC, VALS(s1ap_MDTMode_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_MBSFN_ResultToLog_item,
{ "MBSFN-ResultToLogInfo", "s1ap.MBSFN_ResultToLogInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_mBSFN_AreaId,
{ "mBSFN-AreaId", "s1ap.mBSFN_AreaId",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_s1ap_carrierFreq,
{ "carrierFreq", "s1ap.carrierFreq",
FT_UINT32, BASE_DEC, NULL, 0,
"EARFCN", HFILL }},
{ &hf_s1ap_MDTPLMNList_item,
{ "PLMNidentity", "s1ap.PLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_immediateMDT,
{ "immediateMDT", "s1ap.immediateMDT_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_loggedMDT,
{ "loggedMDT", "s1ap.loggedMDT_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_mDTMode_Extension,
{ "mDTMode-Extension", "s1ap.mDTMode_Extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_threshold_RSRP,
{ "threshold-RSRP", "s1ap.threshold_RSRP",
FT_UINT32, BASE_CUSTOM, CF_FUNC(s1ap_Threshold_RSRP_fmt), 0,
NULL, HFILL }},
{ &hf_s1ap_threshold_RSRQ,
{ "threshold-RSRQ", "s1ap.threshold_RSRQ",
FT_UINT32, BASE_CUSTOM, CF_FUNC(s1ap_Threshold_RSRQ_fmt), 0,
NULL, HFILL }},
{ &hf_s1ap_global_ENB_ID,
{ "global-ENB-ID", "s1ap.global_ENB_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_tAI,
{ "tAI", "s1ap.tAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_muting_pattern_period,
{ "muting-pattern-period", "s1ap.muting_pattern_period",
FT_UINT32, BASE_DEC, VALS(s1ap_T_muting_pattern_period_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_muting_pattern_offset,
{ "muting-pattern-offset", "s1ap.muting_pattern_offset",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_10239_", HFILL }},
{ &hf_s1ap_nB_IoT_paging_eDRX_Cycle,
{ "nB-IoT-paging-eDRX-Cycle", "s1ap.nB_IoT_paging_eDRX_Cycle",
FT_UINT32, BASE_DEC, VALS(s1ap_NB_IoT_Paging_eDRX_Cycle_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_nB_IoT_pagingTimeWindow,
{ "nB-IoT-pagingTimeWindow", "s1ap.nB_IoT_pagingTimeWindow",
FT_UINT32, BASE_DEC, VALS(s1ap_NB_IoT_PagingTimeWindow_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_overloadAction,
{ "overloadAction", "s1ap.overloadAction",
FT_UINT32, BASE_DEC, VALS(s1ap_OverloadAction_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_pagingAttemptCount,
{ "pagingAttemptCount", "s1ap.pagingAttemptCount",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_intendedNumberOfPagingAttempts,
{ "intendedNumberOfPagingAttempts", "s1ap.intendedNumberOfPagingAttempts",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_nextPagingAreaScope,
{ "nextPagingAreaScope", "s1ap.nextPagingAreaScope",
FT_UINT32, BASE_DEC, VALS(s1ap_NextPagingAreaScope_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_paging_eDRX_Cycle,
{ "paging-eDRX-Cycle", "s1ap.paging_eDRX_Cycle",
FT_UINT32, BASE_DEC, VALS(s1ap_Paging_eDRX_Cycle_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_pagingTimeWindow,
{ "pagingTimeWindow", "s1ap.pagingTimeWindow",
FT_UINT32, BASE_DEC, VALS(s1ap_PagingTimeWindow_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_reportInterval,
{ "reportInterval", "s1ap.reportInterval",
FT_UINT32, BASE_DEC, VALS(s1ap_ReportIntervalMDT_vals), 0,
"ReportIntervalMDT", HFILL }},
{ &hf_s1ap_reportAmount,
{ "reportAmount", "s1ap.reportAmount",
FT_UINT32, BASE_DEC, VALS(s1ap_ReportAmountMDT_vals), 0,
"ReportAmountMDT", HFILL }},
{ &hf_s1ap_proSeDirectDiscovery,
{ "proSeDirectDiscovery", "s1ap.proSeDirectDiscovery",
FT_UINT32, BASE_DEC, VALS(s1ap_ProSeDirectDiscovery_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_proSeDirectCommunication,
{ "proSeDirectCommunication", "s1ap.proSeDirectCommunication",
FT_UINT32, BASE_DEC, VALS(s1ap_ProSeDirectCommunication_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_recommendedCellList,
{ "recommendedCellList", "s1ap.recommendedCellList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_RecommendedCellList_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eUTRAN_CGI,
{ "eUTRAN-CGI", "s1ap.eUTRAN_CGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_timeStayedInCell,
{ "timeStayedInCell", "s1ap.timeStayedInCell",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_s1ap_recommendedENBList,
{ "recommendedENBList", "s1ap.recommendedENBList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_RecommendedENBList_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_mMEPagingTarget,
{ "mMEPagingTarget", "s1ap.mMEPagingTarget",
FT_UINT32, BASE_DEC, VALS(s1ap_MMEPagingTarget_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_eventType,
{ "eventType", "s1ap.eventType",
FT_UINT32, BASE_DEC, VALS(s1ap_EventType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_reportArea,
{ "reportArea", "s1ap.reportArea",
FT_UINT32, BASE_DEC, VALS(s1ap_ReportArea_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_rIMInformation,
{ "rIMInformation", "s1ap.rIMInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_rIMRoutingAddress,
{ "rIMRoutingAddress", "s1ap.rIMRoutingAddress",
FT_UINT32, BASE_DEC, VALS(s1ap_RIMRoutingAddress_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_gERAN_Cell_ID,
{ "gERAN-Cell-ID", "s1ap.gERAN_Cell_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_targetRNC_ID,
{ "targetRNC-ID", "s1ap.targetRNC_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eHRPD_Sector_ID,
{ "eHRPD-Sector-ID", "s1ap.eHRPD_Sector_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_16", HFILL }},
{ &hf_s1ap_uE_RLF_Report_Container,
{ "uE-RLF-Report-Container", "s1ap.uE_RLF_Report_Container",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_uE_RLF_Report_Container_for_extended_bands,
{ "uE-RLF-Report-Container-for-extended-bands", "s1ap.uE_RLF_Report_Container_for_extended_bands",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ECGIListForRestart_item,
{ "EUTRAN-CGI", "s1ap.EUTRAN_CGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_nextHopChainingCount,
{ "nextHopChainingCount", "s1ap.nextHopChainingCount",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_s1ap_nextHopParameter,
{ "nextHopParameter", "s1ap.nextHopParameter",
FT_BYTES, BASE_NONE, NULL, 0,
"SecurityKey", HFILL }},
{ &hf_s1ap_sONInformationRequest,
{ "sONInformationRequest", "s1ap.sONInformationRequest",
FT_UINT32, BASE_DEC, VALS(s1ap_SONInformationRequest_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_sONInformationReply,
{ "sONInformationReply", "s1ap.sONInformationReply_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_sONInformation_Extension,
{ "sONInformation-Extension", "s1ap.sONInformation_Extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_x2TNLConfigurationInfo,
{ "x2TNLConfigurationInfo", "s1ap.x2TNLConfigurationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_rLFReportInformation,
{ "rLFReportInformation", "s1ap.rLFReportInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_targeteNB_ID,
{ "targeteNB-ID", "s1ap.targeteNB_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_sourceeNB_ID,
{ "sourceeNB-ID", "s1ap.sourceeNB_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_sONInformation,
{ "sONInformation", "s1ap.sONInformation",
FT_UINT32, BASE_DEC, VALS(s1ap_SONInformation_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_sourceStratumLevel,
{ "sourceStratumLevel", "s1ap.sourceStratumLevel",
FT_UINT32, BASE_DEC, NULL, 0,
"StratumLevel", HFILL }},
{ &hf_s1ap_listeningSubframePattern,
{ "listeningSubframePattern", "s1ap.listeningSubframePattern_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_aggressoreCGI_List,
{ "aggressoreCGI-List", "s1ap.aggressoreCGI_List",
FT_UINT32, BASE_DEC, NULL, 0,
"ECGI_List", HFILL }},
{ &hf_s1ap_selected_TAI,
{ "selected-TAI", "s1ap.selected_TAI_element",
FT_NONE, BASE_NONE, NULL, 0,
"TAI", HFILL }},
{ &hf_s1ap_rRC_Container,
{ "rRC-Container", "s1ap.rRC_Container",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_e_RABInformationList,
{ "e-RABInformationList", "s1ap.e_RABInformationList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_targetCell_ID,
{ "targetCell-ID", "s1ap.targetCell_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
"EUTRAN_CGI", HFILL }},
{ &hf_s1ap_subscriberProfileIDforRFP,
{ "subscriberProfileIDforRFP", "s1ap.subscriberProfileIDforRFP",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_uE_HistoryInformation,
{ "uE-HistoryInformation", "s1ap.uE_HistoryInformation",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ServedGUMMEIs_item,
{ "ServedGUMMEIsItem", "s1ap.ServedGUMMEIsItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_servedPLMNs,
{ "servedPLMNs", "s1ap.servedPLMNs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_servedGroupIDs,
{ "servedGroupIDs", "s1ap.servedGroupIDs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_servedMMECs,
{ "servedMMECs", "s1ap.servedMMECs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ServedGroupIDs_item,
{ "MME-Group-ID", "s1ap.MME_Group_ID",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ServedMMECs_item,
{ "MME-Code", "s1ap.MME_Code",
FT_UINT8, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ServedPLMNs_item,
{ "PLMNidentity", "s1ap.PLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_SupportedTAs_item,
{ "SupportedTAs-Item", "s1ap.SupportedTAs_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_tAC,
{ "tAC", "s1ap.tAC",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_broadcastPLMNs,
{ "broadcastPLMNs", "s1ap.broadcastPLMNs",
FT_UINT32, BASE_DEC, NULL, 0,
"BPLMNs", HFILL }},
{ &hf_s1ap_stratumLevel,
{ "stratumLevel", "s1ap.stratumLevel",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_synchronisationStatus,
{ "synchronisationStatus", "s1ap.synchronisationStatus",
FT_UINT32, BASE_DEC, VALS(s1ap_SynchronisationStatus_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_mMEC,
{ "mMEC", "s1ap.mMEC",
FT_UINT8, BASE_DEC_HEX, NULL, 0,
"MME_Code", HFILL }},
{ &hf_s1ap_tAIListforMDT,
{ "tAIListforMDT", "s1ap.tAIListforMDT",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAIListforMDT_item,
{ "TAI", "s1ap.TAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAIListforWarning_item,
{ "TAI", "s1ap.TAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAI_Broadcast_item,
{ "TAI-Broadcast-Item", "s1ap.TAI_Broadcast_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_completedCellinTAI,
{ "completedCellinTAI", "s1ap.completedCellinTAI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAI_Cancelled_item,
{ "TAI-Cancelled-Item", "s1ap.TAI_Cancelled_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cancelledCellinTAI,
{ "cancelledCellinTAI", "s1ap.cancelledCellinTAI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_tAListforMDT,
{ "tAListforMDT", "s1ap.tAListforMDT",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAListforMDT_item,
{ "TAC", "s1ap.TAC",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CompletedCellinTAI_item,
{ "CompletedCellinTAI-Item", "s1ap.CompletedCellinTAI_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cGI,
{ "cGI", "s1ap.cGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_rNC_ID,
{ "rNC-ID", "s1ap.rNC_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_extendedRNC_ID,
{ "extendedRNC-ID", "s1ap.extendedRNC_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_measurementThreshold,
{ "measurementThreshold", "s1ap.measurementThreshold",
FT_UINT32, BASE_DEC, VALS(s1ap_MeasurementThresholdA2_vals), 0,
"MeasurementThresholdA2", HFILL }},
{ &hf_s1ap_transportLayerAddress,
{ "transportLayerAddress", "s1ap.transportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_uL_GTP_TEID,
{ "uL-GTP-TEID", "s1ap.uL_GTP_TEID",
FT_BYTES, BASE_NONE, NULL, 0,
"GTP_TEID", HFILL }},
{ &hf_s1ap_e_UTRAN_Trace_ID,
{ "e-UTRAN-Trace-ID", "s1ap.e_UTRAN_Trace_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_interfacesToTrace,
{ "interfacesToTrace", "s1ap.interfacesToTrace",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_traceDepth,
{ "traceDepth", "s1ap.traceDepth",
FT_UINT32, BASE_DEC, VALS(s1ap_TraceDepth_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_traceCollectionEntityIPAddress,
{ "traceCollectionEntityIPAddress", "s1ap.traceCollectionEntityIPAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"TransportLayerAddress", HFILL }},
{ &hf_s1ap_uDP_Port_Number,
{ "uDP-Port-Number", "s1ap.uDP_Port_Number",
FT_UINT16, BASE_DEC, NULL, 0,
"Port_Number", HFILL }},
{ &hf_s1ap_TAIListForRestart_item,
{ "TAI", "s1ap.TAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_uEaggregateMaximumBitRateDL,
{ "uEaggregateMaximumBitRateDL", "s1ap.uEaggregateMaximumBitRateDL",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
"BitRate", HFILL }},
{ &hf_s1ap_uEaggregateMaximumBitRateUL,
{ "uEaggregateMaximumBitRateUL", "s1ap.uEaggregateMaximumBitRateUL",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
"BitRate", HFILL }},
{ &hf_s1ap_uE_S1AP_ID_pair,
{ "uE-S1AP-ID-pair", "s1ap.uE_S1AP_ID_pair_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_mME_UE_S1AP_ID,
{ "mME-UE-S1AP-ID", "s1ap.mME_UE_S1AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eNB_UE_S1AP_ID,
{ "eNB-UE-S1AP-ID", "s1ap.eNB_UE_S1AP_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UE_HistoryInformation_item,
{ "LastVisitedCell-Item", "s1ap.LastVisitedCell_Item",
FT_UINT32, BASE_DEC, VALS(s1ap_LastVisitedCell_Item_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_s_TMSI,
{ "s-TMSI", "s1ap.s_TMSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_iMSI,
{ "iMSI", "s1ap.iMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_encryptionAlgorithms,
{ "encryptionAlgorithms", "s1ap.encryptionAlgorithms",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_integrityProtectionAlgorithms,
{ "integrityProtectionAlgorithms", "s1ap.integrityProtectionAlgorithms",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eutran_cgi,
{ "eutran-cgi", "s1ap.eutran_cgi_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_tai,
{ "tai", "s1ap.tai_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cellIDList,
{ "cellIDList", "s1ap.cellIDList",
FT_UINT32, BASE_DEC, NULL, 0,
"ECGIList", HFILL }},
{ &hf_s1ap_trackingAreaListforWarning,
{ "trackingAreaListforWarning", "s1ap.trackingAreaListforWarning",
FT_UINT32, BASE_DEC, NULL, 0,
"TAIListforWarning", HFILL }},
{ &hf_s1ap_emergencyAreaIDList,
{ "emergencyAreaIDList", "s1ap.emergencyAreaIDList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eNBX2TransportLayerAddresses,
{ "eNBX2TransportLayerAddresses", "s1ap.eNBX2TransportLayerAddresses",
FT_UINT32, BASE_DEC, NULL, 0,
"ENBX2TLAs", HFILL }},
{ &hf_s1ap_ENBX2ExtTLAs_item,
{ "ENBX2ExtTLA", "s1ap.ENBX2ExtTLA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_iPsecTLA,
{ "iPsecTLA", "s1ap.iPsecTLA",
FT_BYTES, BASE_NONE, NULL, 0,
"TransportLayerAddress", HFILL }},
{ &hf_s1ap_gTPTLAa,
{ "gTPTLAa", "s1ap.gTPTLAa",
FT_UINT32, BASE_DEC, NULL, 0,
"ENBX2GTPTLAs", HFILL }},
{ &hf_s1ap_ENBX2GTPTLAs_item,
{ "TransportLayerAddress", "s1ap.TransportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ENBIndirectX2TransportLayerAddresses_item,
{ "TransportLayerAddress", "s1ap.TransportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_protocolIEs,
{ "protocolIEs", "s1ap.protocolIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolIE_Container", HFILL }},
{ &hf_s1ap_dL_transportLayerAddress,
{ "dL-transportLayerAddress", "s1ap.dL_transportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"TransportLayerAddress", HFILL }},
{ &hf_s1ap_dL_gTP_TEID,
{ "dL-gTP-TEID", "s1ap.dL_gTP_TEID",
FT_BYTES, BASE_NONE, NULL, 0,
"GTP_TEID", HFILL }},
{ &hf_s1ap_uL_TransportLayerAddress,
{ "uL-TransportLayerAddress", "s1ap.uL_TransportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"TransportLayerAddress", HFILL }},
{ &hf_s1ap_gTP_TEID,
{ "gTP-TEID", "s1ap.gTP_TEID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_e_RABlevelQosParameters,
{ "e-RABlevelQosParameters", "s1ap.e_RABlevelQosParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupListBearerSUReq_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_e_RABlevelQoSParameters,
{ "e-RABlevelQoSParameters", "s1ap.e_RABlevelQoSParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_nAS_PDU,
{ "nAS-PDU", "s1ap.nAS_PDU",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupListBearerSURes_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeModifiedListBearerModReq_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_e_RABLevelQoSParameters,
{ "e-RABLevelQoSParameters", "s1ap.e_RABLevelQoSParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABModifyListBearerModRes_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABReleaseListBearerRelComp_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABToBeSetupListCtxtSUReq_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABSetupListCtxtSURes_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_TAIList_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_s1_Interface,
{ "s1-Interface", "s1ap.s1_Interface",
FT_UINT32, BASE_DEC, VALS(s1ap_ResetAll_vals), 0,
"ResetAll", HFILL }},
{ &hf_s1ap_partOfS1_Interface,
{ "partOfS1-Interface", "s1ap.partOfS1_Interface",
FT_UINT32, BASE_DEC, NULL, 0,
"UE_associatedLogicalS1_ConnectionListRes", HFILL }},
{ &hf_s1ap_UE_associatedLogicalS1_ConnectionListRes_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_UE_associatedLogicalS1_ConnectionListResAck_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_rIMTransfer,
{ "rIMTransfer", "s1ap.rIMTransfer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_privateIEs,
{ "privateIEs", "s1ap.privateIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"PrivateIE_Container", HFILL }},
{ &hf_s1ap_dL_GTP_TEID,
{ "dL-GTP-TEID", "s1ap.dL_GTP_TEID",
FT_BYTES, BASE_NONE, NULL, 0,
"GTP_TEID", HFILL }},
{ &hf_s1ap_cSGMembershipStatus,
{ "cSGMembershipStatus", "s1ap.cSGMembershipStatus",
FT_UINT32, BASE_DEC, VALS(s1ap_CSGMembershipStatus_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_cellAccessMode,
{ "cellAccessMode", "s1ap.cellAccessMode",
FT_UINT32, BASE_DEC, VALS(s1ap_CellAccessMode_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_E_RABModifyListBearerModConf_item,
{ "ProtocolIE-SingleContainer", "s1ap.ProtocolIE_SingleContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_initiatingMessage,
{ "initiatingMessage", "s1ap.initiatingMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_successfulOutcome,
{ "successfulOutcome", "s1ap.successfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_unsuccessfulOutcome,
{ "unsuccessfulOutcome", "s1ap.unsuccessfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_initiatingMessagevalue,
{ "value", "s1ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitiatingMessage_value", HFILL }},
{ &hf_s1ap_successfulOutcome_value,
{ "value", "s1ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"SuccessfulOutcome_value", HFILL }},
{ &hf_s1ap_unsuccessfulOutcome_value,
{ "value", "s1ap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnsuccessfulOutcome_value", HFILL }},
{ &hf_s1ap_cellLoadReporting,
{ "cellLoadReporting", "s1ap.cellLoadReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_multiCellLoadReporting,
{ "multiCellLoadReporting", "s1ap.multiCellLoadReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
"MultiCellLoadReportingRequest", HFILL }},
{ &hf_s1ap_eventTriggeredCellLoadReporting,
{ "eventTriggeredCellLoadReporting", "s1ap.eventTriggeredCellLoadReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
"EventTriggeredCellLoadReportingRequest", HFILL }},
{ &hf_s1ap_hOReporting,
{ "hOReporting", "s1ap.hOReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
"HOReport", HFILL }},
{ &hf_s1ap_eutranCellActivation,
{ "eutranCellActivation", "s1ap.eutranCellActivation_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellActivationRequest", HFILL }},
{ &hf_s1ap_energySavingsIndication,
{ "energySavingsIndication", "s1ap.energySavingsIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellStateIndication", HFILL }},
{ &hf_s1ap_failureEventReporting,
{ "failureEventReporting", "s1ap.failureEventReporting",
FT_UINT32, BASE_DEC, VALS(s1ap_FailureEventReport_vals), 0,
"FailureEventReport", HFILL }},
{ &hf_s1ap_cellLoadReporting_01,
{ "cellLoadReporting", "s1ap.cellLoadReporting",
FT_UINT32, BASE_DEC, VALS(s1ap_CellLoadReportingResponse_vals), 0,
"CellLoadReportingResponse", HFILL }},
{ &hf_s1ap_multiCellLoadReporting_01,
{ "multiCellLoadReporting", "s1ap.multiCellLoadReporting",
FT_UINT32, BASE_DEC, NULL, 0,
"MultiCellLoadReportingResponse", HFILL }},
{ &hf_s1ap_eventTriggeredCellLoadReporting_01,
{ "eventTriggeredCellLoadReporting", "s1ap.eventTriggeredCellLoadReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
"EventTriggeredCellLoadReportingResponse", HFILL }},
{ &hf_s1ap_hOReporting_01,
{ "hOReporting", "s1ap.hOReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eutranCellActivation_01,
{ "eutranCellActivation", "s1ap.eutranCellActivation_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellActivationResponse", HFILL }},
{ &hf_s1ap_energySavingsIndication_01,
{ "energySavingsIndication", "s1ap.energySavingsIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_failureEventReporting_01,
{ "failureEventReporting", "s1ap.failureEventReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cellLoadReporting_02,
{ "cellLoadReporting", "s1ap.cellLoadReporting",
FT_UINT32, BASE_DEC, VALS(s1ap_CellLoadReportingCause_vals), 0,
"CellLoadReportingCause", HFILL }},
{ &hf_s1ap_multiCellLoadReporting_02,
{ "multiCellLoadReporting", "s1ap.multiCellLoadReporting",
FT_UINT32, BASE_DEC, VALS(s1ap_CellLoadReportingCause_vals), 0,
"CellLoadReportingCause", HFILL }},
{ &hf_s1ap_eventTriggeredCellLoadReporting_02,
{ "eventTriggeredCellLoadReporting", "s1ap.eventTriggeredCellLoadReporting",
FT_UINT32, BASE_DEC, VALS(s1ap_CellLoadReportingCause_vals), 0,
"CellLoadReportingCause", HFILL }},
{ &hf_s1ap_hOReporting_02,
{ "hOReporting", "s1ap.hOReporting",
FT_UINT32, BASE_DEC, VALS(s1ap_HOReportingCause_vals), 0,
"HOReportingCause", HFILL }},
{ &hf_s1ap_eutranCellActivation_02,
{ "eutranCellActivation", "s1ap.eutranCellActivation",
FT_UINT32, BASE_DEC, VALS(s1ap_CellActivationCause_vals), 0,
"CellActivationCause", HFILL }},
{ &hf_s1ap_energySavingsIndication_02,
{ "energySavingsIndication", "s1ap.energySavingsIndication",
FT_UINT32, BASE_DEC, VALS(s1ap_CellStateIndicationCause_vals), 0,
"CellStateIndicationCause", HFILL }},
{ &hf_s1ap_failureEventReporting_02,
{ "failureEventReporting", "s1ap.failureEventReporting",
FT_UINT32, BASE_DEC, VALS(s1ap_FailureEventReportingCause_vals), 0,
"FailureEventReportingCause", HFILL }},
{ &hf_s1ap_eUTRAN,
{ "eUTRAN", "s1ap.eUTRAN_element",
FT_NONE, BASE_NONE, NULL, 0,
"EUTRANcellLoadReportingResponse", HFILL }},
{ &hf_s1ap_uTRAN,
{ "uTRAN", "s1ap.uTRAN",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_s1ap_gERAN,
{ "gERAN", "s1ap.gERAN",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_s1ap_eHRPD,
{ "eHRPD", "s1ap.eHRPD_element",
FT_NONE, BASE_NONE, NULL, 0,
"EHRPDSectorLoadReportingResponse", HFILL }},
{ &hf_s1ap_compositeAvailableCapacityGroup,
{ "compositeAvailableCapacityGroup", "s1ap.compositeAvailableCapacityGroup",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cell_ID_01,
{ "cell-ID", "s1ap.cell_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_s1ap_eUTRANcellLoadReportingResponse,
{ "eUTRANcellLoadReportingResponse", "s1ap.eUTRANcellLoadReportingResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eUTRAN_01,
{ "eUTRAN", "s1ap.eUTRAN",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_s1ap_eHRPD_01,
{ "eHRPD", "s1ap.eHRPD",
FT_BYTES, BASE_NONE, NULL, 0,
"EHRPD_Sector_ID", HFILL }},
{ &hf_s1ap_RequestedCellList_item,
{ "IRAT-Cell-ID", "s1ap.IRAT_Cell_ID",
FT_UINT32, BASE_DEC, VALS(s1ap_IRAT_Cell_ID_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_requestedCellList,
{ "requestedCellList", "s1ap.requestedCellList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_cell_ID_02,
{ "cell-ID", "s1ap.cell_ID",
FT_UINT32, BASE_DEC, VALS(s1ap_IRAT_Cell_ID_vals), 0,
"IRAT_Cell_ID", HFILL }},
{ &hf_s1ap_ReportingCellList_item,
{ "ReportingCellList-Item", "s1ap.ReportingCellList_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_MultiCellLoadReportingResponse_item,
{ "MultiCellLoadReportingResponse-Item", "s1ap.MultiCellLoadReportingResponse_Item",
FT_UINT32, BASE_DEC, VALS(s1ap_MultiCellLoadReportingResponse_Item_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_eUTRANResponse,
{ "eUTRANResponse", "s1ap.eUTRANResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_uTRANResponse,
{ "uTRANResponse", "s1ap.uTRANResponse",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_s1ap_gERANResponse,
{ "gERANResponse", "s1ap.gERANResponse",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_s1ap_eHRPD_02,
{ "eHRPD", "s1ap.eHRPD_element",
FT_NONE, BASE_NONE, NULL, 0,
"EHRPDMultiSectorLoadReportingResponseItem", HFILL }},
{ &hf_s1ap_numberOfMeasurementReportingLevels,
{ "numberOfMeasurementReportingLevels", "s1ap.numberOfMeasurementReportingLevels",
FT_UINT32, BASE_DEC, VALS(s1ap_NumberOfMeasurementReportingLevels_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_cellLoadReportingResponse,
{ "cellLoadReportingResponse", "s1ap.cellLoadReportingResponse",
FT_UINT32, BASE_DEC, VALS(s1ap_CellLoadReportingResponse_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_overloadFlag,
{ "overloadFlag", "s1ap.overloadFlag",
FT_UINT32, BASE_DEC, VALS(s1ap_OverloadFlag_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_hoType,
{ "hoType", "s1ap.hoType",
FT_UINT32, BASE_DEC, VALS(s1ap_HoType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_hoReportType,
{ "hoReportType", "s1ap.hoReportType",
FT_UINT32, BASE_DEC, VALS(s1ap_HoReportType_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_hosourceID,
{ "hosourceID", "s1ap.hosourceID",
FT_UINT32, BASE_DEC, VALS(s1ap_IRAT_Cell_ID_vals), 0,
"IRAT_Cell_ID", HFILL }},
{ &hf_s1ap_hoTargetID,
{ "hoTargetID", "s1ap.hoTargetID",
FT_UINT32, BASE_DEC, VALS(s1ap_IRAT_Cell_ID_vals), 0,
"IRAT_Cell_ID", HFILL }},
{ &hf_s1ap_candidateCellList,
{ "candidateCellList", "s1ap.candidateCellList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_candidatePCIList,
{ "candidatePCIList", "s1ap.candidatePCIList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_CandidateCellList_item,
{ "IRAT-Cell-ID", "s1ap.IRAT_Cell_ID",
FT_UINT32, BASE_DEC, VALS(s1ap_IRAT_Cell_ID_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_CandidatePCIList_item,
{ "CandidatePCI", "s1ap.CandidatePCI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_pCI,
{ "pCI", "s1ap.pCI",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_503", HFILL }},
{ &hf_s1ap_eARFCN,
{ "eARFCN", "s1ap.eARFCN",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_s1ap_cellsToActivateList,
{ "cellsToActivateList", "s1ap.cellsToActivateList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_minimumActivationTime,
{ "minimumActivationTime", "s1ap.minimumActivationTime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_60", HFILL }},
{ &hf_s1ap_CellsToActivateList_item,
{ "CellsToActivateList-Item", "s1ap.CellsToActivateList_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_activatedCellsList,
{ "activatedCellsList", "s1ap.activatedCellsList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_ActivatedCellsList_item,
{ "ActivatedCellsList-Item", "s1ap.ActivatedCellsList_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_notificationCellList,
{ "notificationCellList", "s1ap.notificationCellList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_NotificationCellList_item,
{ "NotificationCellList-Item", "s1ap.NotificationCellList_Item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_notifyFlag,
{ "notifyFlag", "s1ap.notifyFlag",
FT_UINT32, BASE_DEC, VALS(s1ap_NotifyFlag_vals), 0,
NULL, HFILL }},
{ &hf_s1ap_tooEarlyInterRATHOReportFromEUTRAN,
{ "tooEarlyInterRATHOReportFromEUTRAN", "s1ap.tooEarlyInterRATHOReportFromEUTRAN_element",
FT_NONE, BASE_NONE, NULL, 0,
"TooEarlyInterRATHOReportReportFromEUTRAN", HFILL }},
{ &hf_s1ap_uERLFReportContainer,
{ "uERLFReportContainer", "s1ap.uERLFReportContainer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_mobilityInformation,
{ "mobilityInformation", "s1ap.mobilityInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_dL_EHRPD_CompositeAvailableCapacity,
{ "dL-EHRPD-CompositeAvailableCapacity", "s1ap.dL_EHRPD_CompositeAvailableCapacity_element",
FT_NONE, BASE_NONE, NULL, 0,
"EHRPDCompositeAvailableCapacity", HFILL }},
{ &hf_s1ap_uL_EHRPD_CompositeAvailableCapacity,
{ "uL-EHRPD-CompositeAvailableCapacity", "s1ap.uL_EHRPD_CompositeAvailableCapacity_element",
FT_NONE, BASE_NONE, NULL, 0,
"EHRPDCompositeAvailableCapacity", HFILL }},
{ &hf_s1ap_eHRPDSectorCapacityClassValue,
{ "eHRPDSectorCapacityClassValue", "s1ap.eHRPDSectorCapacityClassValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eHRPDCapacityValue,
{ "eHRPDCapacityValue", "s1ap.eHRPDCapacityValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eHRPD_Sector_ID_01,
{ "eHRPD-Sector-ID", "s1ap.eHRPD_Sector_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_eHRPDSectorLoadReportingResponse,
{ "eHRPDSectorLoadReportingResponse", "s1ap.eHRPDSectorLoadReportingResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 619 "./asn1/s1ap/packet-s1ap-template.c"
};
static gint *ett[] = {
&ett_s1ap,
&ett_s1ap_TransportLayerAddress,
&ett_s1ap_ToTargetTransparentContainer,
&ett_s1ap_ToSourceTransparentContainer,
&ett_s1ap_RRCContainer,
&ett_s1ap_UERadioCapability,
&ett_s1ap_RIMInformation,
&ett_s1ap_Cdma2000PDU,
&ett_s1ap_Cdma2000SectorID,
&ett_s1ap_UERadioPagingInformation,
&ett_s1ap_UE_HistoryInformationFromTheUE,
&ett_s1ap_CELevel,
&ett_s1ap_UE_RLF_Report_Container,
&ett_s1ap_UE_RLF_Report_Container_for_extended_bands,
&ett_s1ap_S1_Message,
&ett_s1ap_E_UTRAN_Trace_ID,
&ett_s1ap_InterfacesToTrace,
&ett_s1ap_EncryptionAlgorithms,
&ett_s1ap_IntegrityProtectionAlgorithms,
&ett_s1ap_LastVisitedUTRANCellInformation,
&ett_s1ap_SerialNumber,
&ett_s1ap_WarningType,
&ett_s1ap_DataCodingScheme,
&ett_s1ap_WarningMessageContents,
&ett_s1ap_MSClassmark,
&ett_s1ap_MeasurementsToActivate,
&ett_s1ap_MDT_Location_Info,
&ett_s1ap_IMSI,
&ett_s1ap_NASSecurityParameters,
#line 1 "./asn1/s1ap/packet-s1ap-ettarr.c"
&ett_s1ap_PrivateIE_ID,
&ett_s1ap_ProtocolIE_Container,
&ett_s1ap_ProtocolIE_Field,
&ett_s1ap_ProtocolIE_ContainerList,
&ett_s1ap_ProtocolExtensionContainer,
&ett_s1ap_ProtocolExtensionField,
&ett_s1ap_PrivateIE_Container,
&ett_s1ap_PrivateIE_Field,
&ett_s1ap_Additional_GUTI,
&ett_s1ap_AreaScopeOfMDT,
&ett_s1ap_AllocationAndRetentionPriority,
&ett_s1ap_AssistanceDataForCECapableUEs,
&ett_s1ap_AssistanceDataForPaging,
&ett_s1ap_AssistanceDataForRecommendedCells,
&ett_s1ap_Bearers_SubjectToStatusTransferList,
&ett_s1ap_Bearers_SubjectToStatusTransfer_Item,
&ett_s1ap_BPLMNs,
&ett_s1ap_BroadcastCancelledAreaList,
&ett_s1ap_BroadcastCompletedAreaList,
&ett_s1ap_CancelledCellinEAI,
&ett_s1ap_CancelledCellinEAI_Item,
&ett_s1ap_CancelledCellinTAI,
&ett_s1ap_CancelledCellinTAI_Item,
&ett_s1ap_Cause,
&ett_s1ap_CellIdentifierAndCELevelForCECapableUEs,
&ett_s1ap_CellID_Broadcast,
&ett_s1ap_CellID_Broadcast_Item,
&ett_s1ap_CellID_Cancelled,
&ett_s1ap_CellID_Cancelled_Item,
&ett_s1ap_CellBasedMDT,
&ett_s1ap_CellIdListforMDT,
&ett_s1ap_Cdma2000OneXSRVCCInfo,
&ett_s1ap_CellType,
&ett_s1ap_CGI,
&ett_s1ap_CSG_IdList,
&ett_s1ap_CSG_IdList_Item,
&ett_s1ap_COUNTvalue,
&ett_s1ap_COUNTValueExtended,
&ett_s1ap_COUNTvaluePDCP_SNlength18,
&ett_s1ap_CriticalityDiagnostics,
&ett_s1ap_CriticalityDiagnostics_IE_List,
&ett_s1ap_CriticalityDiagnostics_IE_Item,
&ett_s1ap_ECGIList,
&ett_s1ap_PWSfailedECGIList,
&ett_s1ap_EmergencyAreaIDList,
&ett_s1ap_EmergencyAreaID_Broadcast,
&ett_s1ap_EmergencyAreaID_Broadcast_Item,
&ett_s1ap_EmergencyAreaID_Cancelled,
&ett_s1ap_EmergencyAreaID_Cancelled_Item,
&ett_s1ap_CompletedCellinEAI,
&ett_s1ap_CompletedCellinEAI_Item,
&ett_s1ap_ECGI_List,
&ett_s1ap_EmergencyAreaIDListForRestart,
&ett_s1ap_ENB_ID,
&ett_s1ap_GERAN_Cell_ID,
&ett_s1ap_Global_ENB_ID,
&ett_s1ap_GUMMEIList,
&ett_s1ap_ENB_StatusTransfer_TransparentContainer,
&ett_s1ap_ENBX2TLAs,
&ett_s1ap_EPLMNs,
&ett_s1ap_E_RABInformationList,
&ett_s1ap_E_RABInformationListItem,
&ett_s1ap_E_RABList,
&ett_s1ap_E_RABItem,
&ett_s1ap_E_RABLevelQoSParameters,
&ett_s1ap_EUTRAN_CGI,
&ett_s1ap_ExpectedUEBehaviour,
&ett_s1ap_ExpectedUEActivityBehaviour,
&ett_s1ap_ForbiddenTAs,
&ett_s1ap_ForbiddenTAs_Item,
&ett_s1ap_ForbiddenTACs,
&ett_s1ap_ForbiddenLAs,
&ett_s1ap_ForbiddenLAs_Item,
&ett_s1ap_ForbiddenLACs,
&ett_s1ap_GBR_QosInformation,
&ett_s1ap_GUMMEI,
&ett_s1ap_HandoverRestrictionList,
&ett_s1ap_ImmediateMDT,
&ett_s1ap_InformationOnRecommendedCellsAndENBsForPaging,
&ett_s1ap_LAI,
&ett_s1ap_LastVisitedCell_Item,
&ett_s1ap_LastVisitedEUTRANCellInformation,
&ett_s1ap_LastVisitedGERANCellInformation,
&ett_s1ap_ListeningSubframePattern,
&ett_s1ap_LoggedMDT,
&ett_s1ap_LoggedMBSFNMDT,
&ett_s1ap_M3Configuration,
&ett_s1ap_M4Configuration,
&ett_s1ap_M5Configuration,
&ett_s1ap_M6Configuration,
&ett_s1ap_M7Configuration,
&ett_s1ap_MDT_Configuration,
&ett_s1ap_MBSFN_ResultToLog,
&ett_s1ap_MBSFN_ResultToLogInfo,
&ett_s1ap_MDTPLMNList,
&ett_s1ap_MDTMode,
&ett_s1ap_MeasurementThresholdA2,
&ett_s1ap_MMEPagingTarget,
&ett_s1ap_MutingPatternInformation,
&ett_s1ap_NB_IoT_Paging_eDRXInformation,
&ett_s1ap_OverloadResponse,
&ett_s1ap_PagingAttemptInformation,
&ett_s1ap_Paging_eDRXInformation,
&ett_s1ap_M1PeriodicReporting,
&ett_s1ap_ProSeAuthorized,
&ett_s1ap_RecommendedCellsForPaging,
&ett_s1ap_RecommendedCellList,
&ett_s1ap_RecommendedCellItem,
&ett_s1ap_RecommendedENBsForPaging,
&ett_s1ap_RecommendedENBList,
&ett_s1ap_RecommendedENBItem,
&ett_s1ap_RequestType,
&ett_s1ap_RIMTransfer,
&ett_s1ap_RIMRoutingAddress,
&ett_s1ap_RLFReportInformation,
&ett_s1ap_ECGIListForRestart,
&ett_s1ap_SecurityContext,
&ett_s1ap_SONInformation,
&ett_s1ap_SONInformationReply,
&ett_s1ap_SONInformationReport,
&ett_s1ap_SONConfigurationTransfer,
&ett_s1ap_SynchronisationInformation,
&ett_s1ap_SourceeNB_ID,
&ett_s1ap_SourceeNB_ToTargeteNB_TransparentContainer,
&ett_s1ap_ServedGUMMEIs,
&ett_s1ap_ServedGUMMEIsItem,
&ett_s1ap_ServedGroupIDs,
&ett_s1ap_ServedMMECs,
&ett_s1ap_ServedPLMNs,
&ett_s1ap_SupportedTAs,
&ett_s1ap_SupportedTAs_Item,
&ett_s1ap_TimeSynchronisationInfo,
&ett_s1ap_S_TMSI,
&ett_s1ap_TAIBasedMDT,
&ett_s1ap_TAIListforMDT,
&ett_s1ap_TAIListforWarning,
&ett_s1ap_TAI,
&ett_s1ap_TAI_Broadcast,
&ett_s1ap_TAI_Broadcast_Item,
&ett_s1ap_TAI_Cancelled,
&ett_s1ap_TAI_Cancelled_Item,
&ett_s1ap_TABasedMDT,
&ett_s1ap_TAListforMDT,
&ett_s1ap_CompletedCellinTAI,
&ett_s1ap_CompletedCellinTAI_Item,
&ett_s1ap_TargetID,
&ett_s1ap_TargeteNB_ID,
&ett_s1ap_TargetRNC_ID,
&ett_s1ap_TargeteNB_ToSourceeNB_TransparentContainer,
&ett_s1ap_M1ThresholdEventA2,
&ett_s1ap_TransportInformation,
&ett_s1ap_TraceActivation,
&ett_s1ap_TunnelInformation,
&ett_s1ap_TAIListForRestart,
&ett_s1ap_UEAggregateMaximumBitrate,
&ett_s1ap_UE_S1AP_IDs,
&ett_s1ap_UE_S1AP_ID_pair,
&ett_s1ap_UE_associatedLogicalS1_ConnectionItem,
&ett_s1ap_UE_HistoryInformation,
&ett_s1ap_UEPagingID,
&ett_s1ap_UESecurityCapabilities,
&ett_s1ap_UserLocationInformation,
&ett_s1ap_WarningAreaList,
&ett_s1ap_X2TNLConfigurationInfo,
&ett_s1ap_ENBX2ExtTLAs,
&ett_s1ap_ENBX2ExtTLA,
&ett_s1ap_ENBX2GTPTLAs,
&ett_s1ap_ENBIndirectX2TransportLayerAddresses,
&ett_s1ap_HandoverRequired,
&ett_s1ap_HandoverCommand,
&ett_s1ap_E_RABDataForwardingItem,
&ett_s1ap_HandoverPreparationFailure,
&ett_s1ap_HandoverRequest,
&ett_s1ap_E_RABToBeSetupItemHOReq,
&ett_s1ap_HandoverRequestAcknowledge,
&ett_s1ap_E_RABAdmittedItem,
&ett_s1ap_E_RABFailedToSetupItemHOReqAck,
&ett_s1ap_HandoverFailure,
&ett_s1ap_HandoverNotify,
&ett_s1ap_PathSwitchRequest,
&ett_s1ap_E_RABToBeSwitchedDLItem,
&ett_s1ap_PathSwitchRequestAcknowledge,
&ett_s1ap_E_RABToBeSwitchedULItem,
&ett_s1ap_PathSwitchRequestFailure,
&ett_s1ap_HandoverCancel,
&ett_s1ap_HandoverCancelAcknowledge,
&ett_s1ap_E_RABSetupRequest,
&ett_s1ap_E_RABToBeSetupListBearerSUReq,
&ett_s1ap_E_RABToBeSetupItemBearerSUReq,
&ett_s1ap_E_RABSetupResponse,
&ett_s1ap_E_RABSetupListBearerSURes,
&ett_s1ap_E_RABSetupItemBearerSURes,
&ett_s1ap_E_RABModifyRequest,
&ett_s1ap_E_RABToBeModifiedListBearerModReq,
&ett_s1ap_E_RABToBeModifiedItemBearerModReq,
&ett_s1ap_E_RABModifyResponse,
&ett_s1ap_E_RABModifyListBearerModRes,
&ett_s1ap_E_RABModifyItemBearerModRes,
&ett_s1ap_E_RABReleaseCommand,
&ett_s1ap_E_RABReleaseResponse,
&ett_s1ap_E_RABReleaseListBearerRelComp,
&ett_s1ap_E_RABReleaseItemBearerRelComp,
&ett_s1ap_E_RABReleaseIndication,
&ett_s1ap_InitialContextSetupRequest,
&ett_s1ap_E_RABToBeSetupListCtxtSUReq,
&ett_s1ap_E_RABToBeSetupItemCtxtSUReq,
&ett_s1ap_InitialContextSetupResponse,
&ett_s1ap_E_RABSetupListCtxtSURes,
&ett_s1ap_E_RABSetupItemCtxtSURes,
&ett_s1ap_InitialContextSetupFailure,
&ett_s1ap_Paging,
&ett_s1ap_TAIList,
&ett_s1ap_TAIItem,
&ett_s1ap_UEContextReleaseRequest,
&ett_s1ap_UEContextReleaseCommand,
&ett_s1ap_UEContextReleaseComplete,
&ett_s1ap_UEContextModificationRequest,
&ett_s1ap_UEContextModificationResponse,
&ett_s1ap_UEContextModificationFailure,
&ett_s1ap_UERadioCapabilityMatchRequest,
&ett_s1ap_UERadioCapabilityMatchResponse,
&ett_s1ap_DownlinkNASTransport,
&ett_s1ap_InitialUEMessage,
&ett_s1ap_UplinkNASTransport,
&ett_s1ap_NASNonDeliveryIndication,
&ett_s1ap_RerouteNASRequest,
&ett_s1ap_Reset,
&ett_s1ap_ResetType,
&ett_s1ap_UE_associatedLogicalS1_ConnectionListRes,
&ett_s1ap_ResetAcknowledge,
&ett_s1ap_UE_associatedLogicalS1_ConnectionListResAck,
&ett_s1ap_ErrorIndication,
&ett_s1ap_S1SetupRequest,
&ett_s1ap_S1SetupResponse,
&ett_s1ap_S1SetupFailure,
&ett_s1ap_ENBConfigurationUpdate,
&ett_s1ap_ENBConfigurationUpdateAcknowledge,
&ett_s1ap_ENBConfigurationUpdateFailure,
&ett_s1ap_MMEConfigurationUpdate,
&ett_s1ap_MMEConfigurationUpdateAcknowledge,
&ett_s1ap_MMEConfigurationUpdateFailure,
&ett_s1ap_DownlinkS1cdma2000tunnelling,
&ett_s1ap_UplinkS1cdma2000tunnelling,
&ett_s1ap_UECapabilityInfoIndication,
&ett_s1ap_ENBStatusTransfer,
&ett_s1ap_MMEStatusTransfer,
&ett_s1ap_TraceStart,
&ett_s1ap_TraceFailureIndication,
&ett_s1ap_DeactivateTrace,
&ett_s1ap_CellTrafficTrace,
&ett_s1ap_LocationReportingControl,
&ett_s1ap_LocationReportingFailureIndication,
&ett_s1ap_LocationReport,
&ett_s1ap_OverloadStart,
&ett_s1ap_OverloadStop,
&ett_s1ap_WriteReplaceWarningRequest,
&ett_s1ap_WriteReplaceWarningResponse,
&ett_s1ap_ENBDirectInformationTransfer,
&ett_s1ap_Inter_SystemInformationTransferType,
&ett_s1ap_MMEDirectInformationTransfer,
&ett_s1ap_ENBConfigurationTransfer,
&ett_s1ap_MMEConfigurationTransfer,
&ett_s1ap_PrivateMessage,
&ett_s1ap_KillRequest,
&ett_s1ap_KillResponse,
&ett_s1ap_PWSRestartIndication,
&ett_s1ap_PWSFailureIndication,
&ett_s1ap_DownlinkUEAssociatedLPPaTransport,
&ett_s1ap_UplinkUEAssociatedLPPaTransport,
&ett_s1ap_DownlinkNonUEAssociatedLPPaTransport,
&ett_s1ap_UplinkNonUEAssociatedLPPaTransport,
&ett_s1ap_E_RABModificationIndication,
&ett_s1ap_E_RABToBeModifiedItemBearerModInd,
&ett_s1ap_E_RABNotToBeModifiedItemBearerModInd,
&ett_s1ap_CSGMembershipInfo,
&ett_s1ap_E_RABModificationConfirm,
&ett_s1ap_E_RABModifyListBearerModConf,
&ett_s1ap_E_RABModifyItemBearerModConf,
&ett_s1ap_UEContextModificationIndication,
&ett_s1ap_UEContextModificationConfirm,
&ett_s1ap_UEContextSuspendRequest,
&ett_s1ap_UEContextSuspendResponse,
&ett_s1ap_UEContextResumeRequest,
&ett_s1ap_E_RABFailedToResumeItemResumeReq,
&ett_s1ap_UEContextResumeResponse,
&ett_s1ap_E_RABFailedToResumeItemResumeRes,
&ett_s1ap_UEContextResumeFailure,
&ett_s1ap_ConnectionEstablishmentIndication,
&ett_s1ap_S1AP_PDU,
&ett_s1ap_InitiatingMessage,
&ett_s1ap_SuccessfulOutcome,
&ett_s1ap_UnsuccessfulOutcome,
&ett_s1ap_SONtransferRequestContainer,
&ett_s1ap_SONtransferResponseContainer,
&ett_s1ap_SONtransferCause,
&ett_s1ap_CellLoadReportingResponse,
&ett_s1ap_EUTRANcellLoadReportingResponse,
&ett_s1ap_EUTRANResponse,
&ett_s1ap_IRAT_Cell_ID,
&ett_s1ap_RequestedCellList,
&ett_s1ap_MultiCellLoadReportingRequest,
&ett_s1ap_ReportingCellList_Item,
&ett_s1ap_ReportingCellList,
&ett_s1ap_MultiCellLoadReportingResponse,
&ett_s1ap_MultiCellLoadReportingResponse_Item,
&ett_s1ap_EventTriggeredCellLoadReportingRequest,
&ett_s1ap_EventTriggeredCellLoadReportingResponse,
&ett_s1ap_HOReport,
&ett_s1ap_CandidateCellList,
&ett_s1ap_CandidatePCIList,
&ett_s1ap_CandidatePCI,
&ett_s1ap_CellActivationRequest,
&ett_s1ap_CellsToActivateList,
&ett_s1ap_CellsToActivateList_Item,
&ett_s1ap_CellActivationResponse,
&ett_s1ap_ActivatedCellsList,
&ett_s1ap_ActivatedCellsList_Item,
&ett_s1ap_CellStateIndication,
&ett_s1ap_NotificationCellList,
&ett_s1ap_NotificationCellList_Item,
&ett_s1ap_FailureEventReport,
&ett_s1ap_TooEarlyInterRATHOReportReportFromEUTRAN,
&ett_s1ap_EHRPDSectorLoadReportingResponse,
&ett_s1ap_EHRPDCompositeAvailableCapacity,
&ett_s1ap_EHRPDMultiSectorLoadReportingResponseItem,
#line 653 "./asn1/s1ap/packet-s1ap-template.c"
};
static ei_register_info ei[] = {
{ &ei_s1ap_number_pages_le15, { "s1ap.number_pages_le15", PI_MALFORMED, PI_ERROR, "Number of pages should be <=15", EXPFILL }}
};
module_t *s1ap_module;
expert_module_t* expert_s1ap;
proto_s1ap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_s1ap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_s1ap = expert_register_protocol(proto_s1ap);
expert_register_field_array(expert_s1ap, ei, array_length(ei));
s1ap_handle = register_dissector("s1ap", dissect_s1ap, proto_s1ap);
s1ap_ies_dissector_table = register_dissector_table("s1ap.ies", "S1AP-PROTOCOL-IES", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_ies_p1_dissector_table = register_dissector_table("s1ap.ies.pair.first", "S1AP-PROTOCOL-IES-PAIR FirstValue", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_ies_p2_dissector_table = register_dissector_table("s1ap.ies.pair.second", "S1AP-PROTOCOL-IES-PAIR SecondValue", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_extension_dissector_table = register_dissector_table("s1ap.extension", "S1AP-PROTOCOL-EXTENSION", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_proc_imsg_dissector_table = register_dissector_table("s1ap.proc.imsg", "S1AP-ELEMENTARY-PROCEDURE InitiatingMessage", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_proc_sout_dissector_table = register_dissector_table("s1ap.proc.sout", "S1AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_proc_uout_dissector_table = register_dissector_table("s1ap.proc.uout", "S1AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_module = prefs_register_protocol(proto_s1ap, proto_reg_handoff_s1ap);
prefs_register_uint_preference(s1ap_module, "sctp.port",
"S1AP SCTP Port",
"Set the SCTP port for S1AP messages",
10,
&gbl_s1apSctpPort);
prefs_register_bool_preference(s1ap_module, "dissect_container", "Dissect TransparentContainer", "Dissect TransparentContainers that are opaque to S1AP", &g_s1ap_dissect_container);
prefs_register_enum_preference(s1ap_module, "dissect_lte_container_as", "Dissect LTE TransparentContainer as",
"Select whether LTE TransparentContainer should be dissected as NB-IOT or legacy LTE",
&g_s1ap_dissect_lte_container_as, s1ap_lte_container_vals, FALSE);
}
