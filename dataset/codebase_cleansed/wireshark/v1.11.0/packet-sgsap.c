static guint16
de_sgsap_eps_loc_upd_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 oct;
curr_offset = offset;
proto_tree_add_item(tree, hf_sgsap_eps_location_update_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if (add_string) {
oct = tvb_get_guint8(tvb, curr_offset);
g_snprintf(add_string, string_len, " - %s", val_to_str_const(oct, sgsap_eps_location_update_type_values, "Reserved"));
}
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_sgsap_err_msg(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_item(tree, hf_sgsap_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
return(len);
}
static guint16
de_sgsap_ecgi(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
dissect_e212_mcc_mnc(tvb, pinfo, tree, offset, TRUE);
curr_offset += 3;
proto_tree_add_item(tree, hf_sgsap_eci, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset += 4;
return(curr_offset-offset);
}
static guint16
de_sgsap_g_cn_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
dissect_e212_mcc_mnc(tvb, pinfo, tree, offset, TRUE);
curr_offset += 3;
proto_tree_add_item(tree, hf_sgsap_cn_id, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
return(curr_offset-offset);
}
static guint16
de_sgsap_imeisv(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
const char *imeisv_str;
guint32 curr_offset;
curr_offset = offset;
imeisv_str = tvb_bcd_dig_to_wmem_packet_str( tvb, curr_offset, len, NULL, FALSE);
proto_tree_add_string(tree, hf_sgsap_imeisv, tvb, curr_offset, len, imeisv_str);
if (add_string) {
g_snprintf(add_string, (len<<2)+4, " - %s", imeisv_str);
}
return(len);
}
static guint16
de_sgsap_imsi_det_eps(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_sgsap_imsi_det_eps, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
return(curr_offset-offset);
}
static guint16
de_sgsap_imsi_det_non_eps(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_sgsap_imsi_det_non_eps, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
return(curr_offset-offset);
}
static guint16
de_sgsap_lcs_indic(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_sgsap_lcs_indic, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
return(curr_offset-offset);
}
static guint16
de_sgsap_mm_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
dtap_mm_mm_info(tvb, tree, pinfo, curr_offset, len);
return(len);
}
static guint16
de_sgsap_mme_name(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint name_len, tmp;
guint8 *fqdn = NULL;
if (len > 0) {
name_len = tvb_get_guint8(tvb, offset);
if (name_len < 0x20) {
fqdn = tvb_get_string(wmem_packet_scope(), tvb, offset + 1, len - 1);
for (;;) {
if (name_len >= len - 1)
break;
tmp = name_len;
name_len = name_len + fqdn[tmp] + 1;
fqdn[tmp] = '.';
}
} else{
fqdn = tvb_get_string(wmem_packet_scope(), tvb, offset, len);
}
proto_tree_add_string(tree, hf_sgsap_mme_name, tvb, offset, len, fqdn);
if (add_string)
g_snprintf(add_string, string_len, " - %s", fqdn);
}
return(len);
}
static guint16
de_sgsap_nas_msg_container(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *new_tvb;
guint32 curr_offset;
curr_offset = offset;
new_tvb = tvb_new_subset(tvb, curr_offset, len, len);
if (gsm_a_dtap_handle) {
call_dissector(gsm_a_dtap_handle, new_tvb, pinfo, tree);
}
return(len);
}
static guint16
de_sgsap_serv_indic(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 oct;
curr_offset = offset;
proto_tree_add_item(tree, hf_sgsap_service_indicator_value, tvb, offset, 1, ENC_BIG_ENDIAN);
if (add_string) {
oct = tvb_get_guint8(tvb, curr_offset);
g_snprintf(add_string, string_len, " - %s", val_to_str_const(oct, sgsap_service_indicator_values, "Reserved"));
}
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_sgsap_sgs_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 oct;
curr_offset = offset;
proto_tree_add_item(tree, hf_sgsap_sgs_cause, tvb, offset, 1, ENC_BIG_ENDIAN);
if (add_string) {
oct = tvb_get_guint8(tvb, curr_offset);
g_snprintf(add_string, string_len, " - %s", val_to_str_ext_const(oct, &sgsap_sgs_cause_values_ext, "Reserved"));
}
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_sgsap_ue_emm_mode(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_sgsap_ue_emm_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
return(curr_offset - offset);
}
static guint16
de_sgsap_vlr_name(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint name_len, tmp;
guint8 *fqdn = NULL;
if (len > 0) {
name_len = tvb_get_guint8(tvb, offset);
if (name_len < 0x20) {
fqdn = tvb_get_string(wmem_packet_scope(), tvb, offset + 1, len - 1);
for (;;) {
if (name_len >= len - 1)
break;
tmp = name_len;
name_len = name_len + fqdn[tmp] + 1;
fqdn[tmp] = '.';
}
} else{
fqdn = tvb_get_string(wmem_packet_scope(), tvb, offset, len);
}
proto_tree_add_string(tree, hf_sgsap_vlr_name, tvb, offset, len, fqdn);
if (add_string)
g_snprintf(add_string, string_len, " - %s", fqdn);
}
return(len);
}
static void
sgsap_alert_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_alert_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_MAND_TLV(0x08, SGSAP_PDU_TYPE, DE_SGSAP_SGS_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_alert_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_dl_unitdata(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_MAND_TLV(0x16, SGSAP_PDU_TYPE, DE_SGSAP_NAS_MSG_CONTAINER, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_eps_det_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_eps_det_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_MAND_TLV(0x09, SGSAP_PDU_TYPE, DE_SGSAP_MME_NAME, NULL);
ELEM_MAND_TLV(0x10, SGSAP_PDU_TYPE, DE_SGSAP_IMSI_DET_EPS, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_imsi_det_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_imsi_det_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_MAND_TLV(0x09, SGSAP_PDU_TYPE, DE_SGSAP_MME_NAME, NULL);
ELEM_MAND_TLV(0x11, SGSAP_PDU_TYPE, DE_SGSAP_IMSI_DET_NON_EPS, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_imsi_loc_update_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_MAND_TLV(0x04, GSM_A_PDU_TYPE_COMMON, DE_LAI, NULL);
ELEM_OPT_TLV(0x0e, GSM_A_PDU_TYPE_COMMON, DE_MID, " - New TMSI, or IMSI");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_imsi_loc_update_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_MAND_TLV(0x0f, GSM_A_PDU_TYPE_DTAP, DE_REJ_CAUSE, NULL);
ELEM_OPT_TLV(0x04, GSM_A_PDU_TYPE_COMMON, DE_LAI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_imsi_loc_update_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_MAND_TLV(0x09, SGSAP_PDU_TYPE, DE_SGSAP_MME_NAME, NULL);
ELEM_MAND_TLV(0x0a, SGSAP_PDU_TYPE, DE_SGSAP_EPS_LOC_UPD_TYPE, NULL);
ELEM_MAND_TLV(0x04, GSM_A_PDU_TYPE_COMMON, DE_LAI, NULL);
ELEM_OPT_TLV(0x04, GSM_A_PDU_TYPE_COMMON, DE_LAI, " - Old location area identifier");
ELEM_OPT_TLV( 0x07 , GSM_A_PDU_TYPE_GM, DE_TMSI_STAT , NULL );
ELEM_OPT_TLV(0x15, SGSAP_PDU_TYPE, DE_SGSAP_IMEISV, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_mm_info_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_MAND_TLV(0x17, SGSAP_PDU_TYPE, DE_SGSAP_MM_INFO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_paging_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_MAND_TLV(0x08, SGSAP_PDU_TYPE, DE_SGSAP_SGS_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_paging_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_MAND_TLV(0x02, SGSAP_PDU_TYPE, DE_SGSAP_VLR_NAME, NULL);
ELEM_MAND_TLV(0x20, SGSAP_PDU_TYPE, DE_SGSAP_SERV_INDIC, NULL);
ELEM_OPT_TLV(0x03, GSM_A_PDU_TYPE_BSSMAP, BE_TMSI, NULL);
ELEM_OPT_TLV(0x1c, GSM_A_PDU_TYPE_DTAP, DE_CLG_PARTY_BCD_NUM, " - CLI");
ELEM_OPT_TLV(0x04, GSM_A_PDU_TYPE_COMMON, DE_LAI, NULL);
ELEM_OPT_TLV(0x0b, SGSAP_PDU_TYPE, DE_SGSAP_GLOBAL_CN_ID, NULL);
ELEM_OPT_TLV(0x1f, NAS_PDU_TYPE_EMM, DE_EMM_SS_CODE, NULL);
ELEM_OPT_TLV(0x1e, SGSAP_PDU_TYPE, DE_SGSAP_LCS_INDIC, NULL);
ELEM_OPT_TLV(0x1d, NAS_PDU_TYPE_EMM, DE_EMM_LCS_CLIENT_ID, NULL);
ELEM_OPT_TLV(0x05, GSM_A_PDU_TYPE_BSSMAP, BE_CHAN_NEEDED, NULL);
ELEM_OPT_TLV(0x06, GSM_A_PDU_TYPE_BSSMAP, BE_EMLPP_PRIO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_reset_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(0x09, SGSAP_PDU_TYPE, DE_SGSAP_MME_NAME, NULL);
ELEM_OPT_TLV(0x02, SGSAP_PDU_TYPE, DE_SGSAP_VLR_NAME, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_reset_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(0x09, SGSAP_PDU_TYPE, DE_SGSAP_MME_NAME, NULL);
ELEM_OPT_TLV(0x02, SGSAP_PDU_TYPE, DE_SGSAP_VLR_NAME, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_service_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_MAND_TLV(0x20, SGSAP_PDU_TYPE, DE_SGSAP_SERV_INDIC, NULL);
ELEM_OPT_TLV(0x15, SGSAP_PDU_TYPE, DE_SGSAP_IMEISV, NULL);
ELEM_OPT_TLV(0x21, GSM_A_PDU_TYPE_DTAP, DE_TIME_ZONE, " - UE Time Zone");
ELEM_OPT_TLV(0x22 , GSM_A_PDU_TYPE_COMMON, DE_MS_CM_2, NULL);
ELEM_OPT_TLV(0x23, NAS_PDU_TYPE_EMM, DE_EMM_TRAC_AREA_ID, NULL);
ELEM_OPT_TLV(0x24, SGSAP_PDU_TYPE, DE_SGSAP_ECGI, NULL);
ELEM_OPT_TLV(0x25, SGSAP_PDU_TYPE, DE_SGSAP_UE_EMM_MODE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_status(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_MAND_TLV(0x08, SGSAP_PDU_TYPE, DE_SGSAP_SGS_CAUSE, NULL);
ELEM_OPT_TLV(0x1e, SGSAP_PDU_TYPE, DE_SGSAP_ERR_MSG, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_tmsi_realloc_comp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_ue_act_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_ue_unreachable(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_MAND_TLV(0x08, SGSAP_PDU_TYPE, DE_SGSAP_SGS_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_ue_ul_unitdata(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_MAND_TLV(0x16, SGSAP_PDU_TYPE, DE_SGSAP_NAS_MSG_CONTAINER, NULL);
ELEM_OPT_TLV(0x15, SGSAP_PDU_TYPE, DE_SGSAP_IMEISV, NULL);
ELEM_OPT_TLV(0x21, GSM_A_PDU_TYPE_DTAP, DE_TIME_ZONE, " - UE Time Zone");
ELEM_OPT_TLV(0x22 , GSM_A_PDU_TYPE_COMMON, DE_MS_CM_2, NULL);
ELEM_OPT_TLV(0x23, NAS_PDU_TYPE_EMM, DE_EMM_TRAC_AREA_ID, NULL);
ELEM_OPT_TLV(0x24, SGSAP_PDU_TYPE, DE_SGSAP_ECGI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
sgsap_release_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(0x01, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_MAND_TLV(0x08, SGSAP_PDU_TYPE, DE_SGSAP_SGS_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void get_sgsap_msg_params(guint8 oct, const gchar **msg_str, int *ett_tree, int *hf_idx, msg_fcn *msg_fcn_p)
{
gint idx;
*msg_str = try_val_to_str_idx_ext((guint32) (oct & 0xff), &sgsap_msg_strings_ext, &idx);
*hf_idx = hf_sgsap_msg_type;
if (*msg_str != NULL) {
*ett_tree = ett_sgsap_msg[idx];
*msg_fcn_p = sgsap_msg_fcn[idx];
}
return;
}
static void
dissect_sgsap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *item;
proto_tree *sgsap_tree;
int offset = 0;
guint32 len;
const gchar *msg_str;
gint ett_tree;
int hf_idx;
void (*msg_fcn_p)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len);
guint8 oct;
len = tvb_length(tvb);
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
item = proto_tree_add_item(tree, proto_sgsap, tvb, 0, -1, ENC_NA);
sgsap_tree = proto_item_add_subtree(item, ett_sgsap);
oct = tvb_get_guint8(tvb, offset);
msg_fcn_p = NULL;
ett_tree = -1;
hf_idx = -1;
msg_str = NULL;
get_sgsap_msg_params(oct, &msg_str, &ett_tree, &hf_idx, &msg_fcn_p);
if (msg_str) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", msg_str);
}else{
proto_tree_add_text(tree, tvb, offset, 1, "Unknown message 0x%x", oct);
return;
}
proto_tree_add_item(sgsap_tree, hf_idx, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (msg_fcn_p == NULL)
{
proto_tree_add_text(sgsap_tree, tvb, offset, len - offset,
"Message Elements");
}
else
{
(*msg_fcn_p)(tvb, sgsap_tree, pinfo, offset, len - offset);
}
}
void proto_register_sgsap(void) {
guint i;
guint last_offset;
static hf_register_info hf[] = {
{ &hf_sgsap_msg_type,
{ "SGSAP Message Type", "sgsap.msg_type",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &sgsap_msg_strings_ext, 0x0,
NULL, HFILL }
},
{ &hf_sgsap_elem_id,
{ "Element ID", "sgsap.elem_id",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sgsap_eps_location_update_type,
{ "EPS location update type", "sgsap.eps_location_update_type",
FT_UINT8, BASE_DEC, VALS(sgsap_eps_location_update_type_values), 0x0,
NULL, HFILL }
},
{ &hf_sgsap_service_indicator_value,
{ "Service indicator", "sgsap.service_indicator",
FT_UINT8, BASE_DEC, VALS(sgsap_service_indicator_values), 0x0,
NULL, HFILL }
},
{ &hf_sgsap_sgs_cause,
{ "SGs cause", "sgsap.sgs_cause",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &sgsap_sgs_cause_values_ext, 0x0,
NULL, HFILL }
},
{ &hf_sgsap_ue_emm_mode,
{ "UE EMM mode", "sgsap.ue_emm_mode",
FT_UINT8, BASE_DEC, VALS(sgsap_ue_emm_mode_values), 0x0,
NULL, HFILL }
},
{ &hf_sgsap_eci,
{"ECI (E-UTRAN Cell Identifier)", "sgsap.eci",
FT_UINT32, BASE_DEC, NULL, 0x0fffffff,
NULL, HFILL}
},
{ &hf_sgsap_cn_id,
{"CN_ID", "sgsap.cn_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sgsap_imsi_det_eps,
{ "IMSI detach from EPS service type", "sgsap.imsi_det_eps",
FT_UINT8, BASE_DEC, VALS(sgsap_imsi_det_from_eps_serv_type_values), 0x0,
NULL, HFILL }
},
{ &hf_sgsap_imsi_det_non_eps,
{ "IMSI detach from non-EPS service type", "sgsap.imsi_det_non_eps",
FT_UINT8, BASE_DEC, VALS(sgsap_imsi_det_from_non_eps_serv_type_values), 0x0,
NULL, HFILL }
},
{ &hf_sgsap_lcs_indic,
{ "LCS indicator", "sgsap.lcs_indicator",
FT_UINT8, BASE_DEC, VALS(sgsap_lcs_indic_values), 0x0,
NULL, HFILL }
},
{ &hf_sgsap_mme_name,
{"MME name", "sgsap.mme_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sgsap_vlr_name,
{"VLR name", "sgsap.vlr_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sgsap_imeisv,
{"IMEISV", "sgsap.imeisv",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
};
#define NUM_INDIVIDUAL_ELEMS 1
gint *ett[NUM_INDIVIDUAL_ELEMS +
NUM_SGSAP_ELEM +
NUM_SGSAP_MSG];
ett[0] = &ett_sgsap;
last_offset = NUM_INDIVIDUAL_ELEMS;
for (i=0; i < NUM_SGSAP_ELEM; i++, last_offset++)
{
ett_sgsap_elem[i] = -1;
ett[last_offset] = &ett_sgsap_elem[i];
}
for (i=0; i < NUM_SGSAP_MSG; i++, last_offset++)
{
ett_sgsap_msg[i] = -1;
ett[last_offset] = &ett_sgsap_msg[i];
}
proto_sgsap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_sgsap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(PFNAME, dissect_sgsap, proto_sgsap);
}
void
proto_reg_handoff_sgsap(void)
{
static gboolean Initialized = FALSE;
static dissector_handle_t sgsap_handle;
static guint SctpPort;
sgsap_handle = find_dissector("sgsap");
gsm_a_dtap_handle = find_dissector("gsm_a_dtap");
if (!Initialized) {
dissector_add_handle("sctp.port", sgsap_handle);
Initialized=TRUE;
} else {
if (SctpPort != 0) {
dissector_delete_uint("sctp.port", SctpPort, sgsap_handle);
}
}
SctpPort = gbl_sgsapSctpPort;
if (SctpPort != 0) {
dissector_add_uint("sctp.port", SctpPort, sgsap_handle);
}
}
