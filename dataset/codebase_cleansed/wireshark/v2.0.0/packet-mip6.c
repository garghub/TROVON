static int
dissect_mip6_brr(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_)
{
proto_tree_add_item(mip6_tree, hf_mip6_binding_refresh_request, tvb, MIP6_DATA_OFF, MIP6_BRR_LEN, ENC_NA);
return MIP6_DATA_OFF + MIP6_BRR_LEN;
}
static int
dissect_mip6_hoti(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_)
{
if (mip6_tree) {
proto_tree *data_tree;
data_tree = proto_tree_add_subtree(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_HOTI_LEN, ett_mip6, NULL, "Home Test Init");
proto_tree_add_item(data_tree, hf_mip6_hoti_cookie, tvb,
MIP6_HOTI_COOKIE_OFF, MIP6_HOTI_COOKIE_LEN, ENC_BIG_ENDIAN);
}
return MIP6_DATA_OFF + MIP6_HOTI_LEN;
}
static int
dissect_mip6_coti(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_)
{
if (mip6_tree) {
proto_tree *data_tree;
data_tree = proto_tree_add_subtree(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_COTI_LEN, ett_mip6, NULL, "Care-of Test Init");
proto_tree_add_item(data_tree, hf_mip6_coti_cookie, tvb,
MIP6_COTI_COOKIE_OFF, MIP6_COTI_COOKIE_LEN, ENC_BIG_ENDIAN);
}
return MIP6_DATA_OFF + MIP6_COTI_LEN;
}
static int
dissect_mip6_hot(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_)
{
if (mip6_tree) {
proto_tree *data_tree;
data_tree = proto_tree_add_subtree(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_HOT_LEN, ett_mip6, NULL, "Home Test");
proto_tree_add_item(data_tree, hf_mip6_hot_nindex, tvb,
MIP6_HOT_INDEX_OFF, MIP6_HOT_INDEX_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_hot_cookie, tvb,
MIP6_HOT_COOKIE_OFF, MIP6_HOT_COOKIE_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_hot_token, tvb,
MIP6_HOT_TOKEN_OFF, MIP6_HOT_TOKEN_LEN, ENC_BIG_ENDIAN);
}
return MIP6_DATA_OFF + MIP6_HOT_LEN;
}
static int
dissect_mip6_cot(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_)
{
if (mip6_tree) {
proto_tree *data_tree;
data_tree = proto_tree_add_subtree(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_COT_LEN, ett_mip6, NULL, "Care-of Test");
proto_tree_add_item(data_tree, hf_mip6_cot_nindex, tvb,
MIP6_COT_INDEX_OFF, MIP6_COT_INDEX_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_cot_cookie, tvb,
MIP6_COT_COOKIE_OFF, MIP6_COT_COOKIE_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_hot_token, tvb,
MIP6_COT_TOKEN_OFF, MIP6_COT_TOKEN_LEN, ENC_BIG_ENDIAN);
}
return MIP6_DATA_OFF + MIP6_COT_LEN;
}
static int
dissect_mip6_bu(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_)
{
if (mip6_tree) {
proto_tree *data_tree;
int lifetime;
data_tree = proto_tree_add_subtree(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_BU_LEN, ett_mip6, NULL, "Binding Update");
proto_tree_add_item(data_tree, hf_mip6_bu_seqnr, tvb,
MIP6_BU_SEQNR_OFF, MIP6_BU_SEQNR_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_bu_a_flag, tvb,
MIP6_BU_FLAGS_OFF, MIP6_BU_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_bu_h_flag, tvb,
MIP6_BU_FLAGS_OFF, MIP6_BU_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_bu_l_flag, tvb,
MIP6_BU_FLAGS_OFF, MIP6_BU_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_bu_k_flag, tvb,
MIP6_BU_FLAGS_OFF, MIP6_BU_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_bu_m_flag, tvb,
MIP6_BU_FLAGS_OFF, MIP6_BU_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_nemo_bu_r_flag, tvb,
MIP6_BU_FLAGS_OFF, MIP6_BU_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_pmip6_bu_p_flag, tvb,
MIP6_BU_FLAGS_OFF, MIP6_BU_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_bu_f_flag, tvb,
MIP6_BU_FLAGS_OFF, MIP6_BU_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_pmip6_bu_t_flag, tvb,
MIP6_BU_FLAGS_OFF, MIP6_BU_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_pmip6_bu_b_flag, tvb,
MIP6_BU_FLAGS_OFF, MIP6_BU_FLAGS_LEN, ENC_BIG_ENDIAN);
if ((tvb_get_guint8(tvb, MIP6_BU_FLAGS_OFF) & 0x0004 ) == 0x0004)
proto_nemo = 1;
lifetime = tvb_get_ntohs(tvb, MIP6_BU_LIFETIME_OFF);
proto_tree_add_uint_format_value(data_tree, hf_mip6_bu_lifetime, tvb,
MIP6_BU_LIFETIME_OFF,
MIP6_BU_LIFETIME_LEN, lifetime,
"%d (%ld seconds)",
lifetime, (long)lifetime * 4);
}
return MIP6_DATA_OFF + MIP6_BU_LEN;
}
static int
dissect_mip6_ba(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_)
{
if (mip6_tree) {
proto_tree *data_tree;
int lifetime;
data_tree = proto_tree_add_subtree(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_BA_LEN, ett_mip6, NULL, "Binding Acknowledgement");
proto_tree_add_item(data_tree, hf_mip6_ba_status, tvb,
MIP6_BA_STATUS_OFF, MIP6_BA_STATUS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_ba_k_flag, tvb,
MIP6_BA_FLAGS_OFF, MIP6_BA_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_nemo_ba_r_flag, tvb,
MIP6_BA_FLAGS_OFF, MIP6_BA_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_pmip6_ba_p_flag, tvb,
MIP6_BA_FLAGS_OFF, MIP6_BA_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_pmip6_ba_t_flag, tvb,
MIP6_BA_FLAGS_OFF, MIP6_BA_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_pmip6_ba_b_flag, tvb,
MIP6_BA_FLAGS_OFF, MIP6_BA_FLAGS_LEN, ENC_BIG_ENDIAN);
if ((tvb_get_guint8(tvb, MIP6_BA_FLAGS_OFF) & 0x0040 ) == 0x0040)
proto_nemo = 1;
proto_tree_add_item(data_tree, hf_mip6_ba_seqnr, tvb,
MIP6_BA_SEQNR_OFF, MIP6_BA_SEQNR_LEN, ENC_BIG_ENDIAN);
lifetime = tvb_get_ntohs(tvb, MIP6_BA_LIFETIME_OFF);
proto_tree_add_uint_format_value(data_tree, hf_mip6_ba_lifetime, tvb,
MIP6_BA_LIFETIME_OFF,
MIP6_BA_LIFETIME_LEN, lifetime,
"%d (%ld seconds)",
lifetime, (long)lifetime * 4);
}
return MIP6_DATA_OFF + MIP6_BA_LEN;
}
static int
dissect_mip6_be(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_)
{
if (mip6_tree) {
proto_tree *data_tree;
data_tree = proto_tree_add_subtree(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_BE_LEN, ett_mip6, NULL, "Binding Error");
proto_tree_add_item(data_tree, hf_mip6_be_status, tvb,
MIP6_BE_STATUS_OFF, MIP6_BE_STATUS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_be_haddr, tvb,
MIP6_BE_HOA_OFF, MIP6_BE_HOA_LEN, ENC_NA);
}
return MIP6_DATA_OFF + MIP6_BE_LEN;
}
static int
dissect_mip6_hb(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_)
{
if (mip6_tree) {
proto_tree *data_tree;
data_tree = proto_tree_add_subtree(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_HB_LEN, ett_mip6, NULL, "Heartbeat");
proto_tree_add_item(data_tree, hf_mip6_hb_u_flag, tvb,
MIP6_HB_FLAGS_OFF, MIP6_HB_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_hb_r_flag, tvb,
MIP6_HB_FLAGS_OFF, MIP6_HB_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_hb_seqnr, tvb,
MIP6_HB_SEQNR_OFF, MIP6_HB_SEQNR_LEN, ENC_BIG_ENDIAN);
}
return MIP6_DATA_OFF + MIP6_HB_LEN;
}
static int
dissect_mip6_hi(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_)
{
if (mip6_tree) {
proto_tree *data_tree;
data_tree = proto_tree_add_subtree(mip6_tree, tvb, MIP6_DATA_OFF, 4, ett_mip6, NULL, "Handover Initiate");
proto_tree_add_item(data_tree, hf_mip6_hi_seqnr, tvb,
MIP6_DATA_OFF, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_hi_s_flag, tvb,
MIP6_DATA_OFF+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_hi_u_flag, tvb,
MIP6_DATA_OFF+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_hi_code, tvb,
MIP6_DATA_OFF+3, 1, ENC_BIG_ENDIAN);
}
return MIP6_DATA_OFF + 4;
}
static int
dissect_mip6_hack(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_)
{
if (mip6_tree) {
proto_tree *data_tree;
data_tree = proto_tree_add_subtree(mip6_tree, tvb, MIP6_DATA_OFF, 4, ett_mip6, NULL, "Handover Acknowledge ");
proto_tree_add_item(data_tree, hf_mip6_hack_seqnr, tvb,
MIP6_DATA_OFF, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_hack_code, tvb,
MIP6_DATA_OFF+3, 1, ENC_BIG_ENDIAN);
}
return MIP6_DATA_OFF + 4;
}
static int
dissect_mip6_unknown(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_)
{
proto_tree_add_item(mip6_tree, hf_mip6_unknown_mh_type, tvb, MIP6_DATA_OFF, MIP6_DATA_OFF + 1, ENC_NA);
return MIP6_DATA_OFF + 1;
}
static int
dissect_fmip6_fbu(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_)
{
if (mip6_tree) {
proto_tree *data_tree;
int lifetime;
data_tree = proto_tree_add_subtree(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_BU_LEN, ett_mip6, NULL, "Fast Binding Update");
proto_tree_add_item(data_tree, hf_fmip6_fbu_seqnr, tvb,
FMIP6_FBU_SEQNR_OFF, FMIP6_FBU_SEQNR_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_fmip6_fbu_a_flag, tvb,
FMIP6_FBU_FLAGS_OFF, FMIP6_FBU_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_fmip6_fbu_h_flag, tvb,
FMIP6_FBU_FLAGS_OFF, FMIP6_FBU_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_fmip6_fbu_l_flag, tvb,
FMIP6_FBU_FLAGS_OFF, FMIP6_FBU_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_fmip6_fbu_k_flag, tvb,
FMIP6_FBU_FLAGS_OFF, FMIP6_FBU_FLAGS_LEN, ENC_BIG_ENDIAN);
lifetime = tvb_get_ntohs(tvb, FMIP6_FBU_LIFETIME_OFF);
proto_tree_add_uint_format_value(data_tree, hf_fmip6_fbu_lifetime, tvb,
FMIP6_FBU_LIFETIME_OFF,
FMIP6_FBU_LIFETIME_LEN, lifetime,
"%d (%ld seconds)",
lifetime, (long)lifetime * 4);
}
return MIP6_DATA_OFF + FMIP6_FBU_LEN;
}
static int
dissect_fmip6_fback(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_)
{
if (mip6_tree) {
proto_tree *data_tree;
int lifetime;
data_tree = proto_tree_add_subtree(mip6_tree, tvb, MIP6_DATA_OFF,
FMIP6_FBACK_LEN, ett_mip6, NULL, "Fast Binding Acknowledgement");
proto_tree_add_item(data_tree, hf_fmip6_fback_status, tvb,
FMIP6_FBACK_STATUS_OFF, FMIP6_FBACK_STATUS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_fmip6_fback_k_flag, tvb,
FMIP6_FBACK_FLAGS_OFF, FMIP6_FBACK_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_fmip6_fback_seqnr, tvb,
FMIP6_FBACK_SEQNR_OFF, FMIP6_FBACK_SEQNR_LEN, ENC_BIG_ENDIAN);
lifetime = tvb_get_ntohs(tvb, FMIP6_FBACK_LIFETIME_OFF);
proto_tree_add_uint_format_value(data_tree, hf_fmip6_fback_lifetime, tvb,
FMIP6_FBACK_LIFETIME_OFF,
FMIP6_FBACK_LIFETIME_LEN, lifetime,
"%d (%ld seconds)",
lifetime, (long)lifetime * 4);
}
return MIP6_DATA_OFF + FMIP6_FBACK_LEN;
}
static int
dissect_fmip6_fna(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_)
{
proto_tree_add_item(mip6_tree, hf_mip6_fast_neighbor_advertisement, tvb, MIP6_DATA_OFF, FMIP6_FNA_LEN, ENC_NA);
return MIP6_DATA_OFF + FMIP6_FNA_LEN;
}
static int
dissect_pmip6_bri(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo)
{
#define INDICATION 1
#define ACKNOWLEDGE 2
proto_tree *field_tree;
guint8 br_type;
br_type = tvb_get_guint8(tvb, PMIP6_BRI_BRTYPE_OFF);
if ( br_type == INDICATION )
{
col_append_str(pinfo->cinfo, COL_INFO, " Indication");
if (mip6_tree)
{
field_tree = proto_tree_add_subtree(mip6_tree, tvb, MIP6_DATA_OFF,
PMIP6_BRI_LEN, ett_mip6, NULL, "Binding Revocation Indication");
proto_tree_add_item(field_tree, hf_pmip6_bri_brtype, tvb,
PMIP6_BRI_BRTYPE_OFF, PMIP6_BRI_BRTYPE_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_rtrigger, tvb,
PMIP6_BRI_RTRIGGER_OFF, PMIP6_BRI_RTRIGGER_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_seqnr, tvb,
PMIP6_BRI_SEQNR_OFF, PMIP6_BRI_SEQNR_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_ip_flag, tvb,
PMIP6_BRI_FLAGS_OFF, PMIP6_BRI_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_iv_flag, tvb,
PMIP6_BRI_FLAGS_OFF, PMIP6_BRI_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_ig_flag, tvb,
PMIP6_BRI_FLAGS_OFF, PMIP6_BRI_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_res, tvb,
PMIP6_BRI_FLAGS_OFF, PMIP6_BRI_FLAGS_LEN, ENC_BIG_ENDIAN);
}
} else if ( br_type == ACKNOWLEDGE ) {
col_append_str(pinfo->cinfo, COL_INFO, " Acknowledge");
if (mip6_tree)
{
field_tree = proto_tree_add_subtree(mip6_tree, tvb, MIP6_DATA_OFF,
PMIP6_BRI_LEN, ett_mip6, NULL, "Binding Revocation Acknowledge");
proto_tree_add_item(field_tree, hf_pmip6_bri_brtype, tvb,
PMIP6_BRI_BRTYPE_OFF, PMIP6_BRI_BRTYPE_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_status, tvb,
PMIP6_BRI_STATUS_OFF, PMIP6_BRI_STATUS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_seqnr, tvb,
PMIP6_BRI_SEQNR_OFF, PMIP6_BRI_SEQNR_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_ap_flag, tvb,
PMIP6_BRI_FLAGS_OFF, PMIP6_BRI_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_av_flag, tvb,
PMIP6_BRI_FLAGS_OFF, PMIP6_BRI_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_ag_flag, tvb,
PMIP6_BRI_FLAGS_OFF, PMIP6_BRI_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_res, tvb,
PMIP6_BRI_FLAGS_OFF, PMIP6_BRI_FLAGS_LEN, ENC_BIG_ENDIAN);
}
}
return MIP6_DATA_OFF + PMIP6_BRI_LEN;
}
static int
dissect_pmip6_lri(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_item(mip6_tree, hf_pmip6_lri_sequence, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mip6_tree, hf_pmip6_lri_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mip6_tree, hf_pmip6_lri_lifetime, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_pmip6_lra(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_item(mip6_tree, hf_pmip6_lra_sequence, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mip6_tree, hf_pmip6_lra_u, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mip6_tree, hf_pmip6_lra_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(mip6_tree, hf_pmip6_lra_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(mip6_tree, hf_pmip6_lra_lifetime, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_mip6_opt_vsm_3gpp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *hdr_item = tree;
int len = tvb_reported_length(tvb);
int offset = 0;
guint8 sub_type, m_flag;
tvbuff_t *next_tvb;
const gchar *mei_str;
const char *digit_str;
gchar *mcc_mnc_str;
const gchar *imsi_str;
sub_type = tvb_get_guint8(tvb,offset);
proto_tree_add_item(tree, hf_mip6_vsm_subtype_3gpp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(hdr_item, " %s", val_to_str_ext_const(sub_type, &mip6_vsm_subtype_3gpp_value_ext, "<unknown>"));
offset++;
m_flag = tvb_get_guint8(tvb,offset) & 0x01;
proto_tree_add_item(tree, hf_mip6_opt_3gpp_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mip6_opt_3gpp_flag_m, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
len = len - 2;
if(m_flag){
proto_tree_add_expert_format(tree, pinfo, &ei_mip6_vsm_data_not_dissected, tvb, offset, len, "Data fragment, handling not implemented yet");
return len;
}
switch (sub_type) {
case 1:
de_sm_pco(tvb, tree, pinfo, offset, len, NULL, 0);
break;
case 2:
proto_tree_add_item(tree, hf_mip6_opt_3gpp_spec_pmipv6_err_code, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 3:
if(len == 4){
proto_tree_add_item(tree, hf_mip6_opt_3gpp_pdn_gw_ipv4_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
}else if(len == 16){
proto_tree_add_item(tree, hf_mip6_opt_3gpp_pdn_gw_ipv6_addr, tvb, offset, 16, ENC_NA);
}
break;
case 4:
proto_tree_add_item(tree, hf_mip6_opt_3gpp_dhcpv4_addr_all_proc_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 5:
next_tvb = tvb_new_subset_length(tvb, offset, len);
dissect_gtpv2_fq_csid(next_tvb, pinfo, tree, hdr_item, len, 0, 0);
break;
case 6:
proto_tree_add_item(tree, hf_mip6_opt_3gpp_pdn_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_mip6_opt_3gpp_pdn_ind_cause, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 7:
proto_tree_add_item(tree, hf_mip6_opt_3gpp_chg_id, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(hdr_item, " %u", tvb_get_ntohl(tvb, offset));
break;
case 8:
next_tvb = tvb_new_subset_length(tvb, offset, len);
dissect_gtpv2_selec_mode(next_tvb, pinfo, tree, hdr_item, len, 0, 0);
break;
case 10:
proto_tree_add_item(tree, hf_mip6_opt_3gpp_charging_characteristic, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 11:
mei_str = tvb_bcd_dig_to_wmem_packet_str( tvb, offset, len, NULL, FALSE);
proto_tree_add_string(tree, hf_mip6_opt_3gpp_mei, tvb, offset, len, mei_str);
proto_item_append_text(hdr_item, " %s", mei_str);
break;
case 12:
dissect_e164_cc(tvb, tree, offset, E164_ENC_BCD);
digit_str = tvb_bcd_dig_to_wmem_packet_str( tvb, offset, len, NULL, FALSE);
proto_tree_add_string(tree, hf_mip6_opt_3gpp_msisdn, tvb, offset, len, digit_str);
proto_item_append_text(hdr_item, " %s", digit_str);
break;
case 13:
mcc_mnc_str = dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, offset, E212_NONE, TRUE);
proto_item_append_text(hdr_item," %s", mcc_mnc_str);
break;
case 14:
proto_tree_add_item(tree, hf_mip6_opt_3gpp_apn_rest, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 15:
proto_tree_add_item(tree, hf_mip6_opt_3gpp_max_apn_rest, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 16:
imsi_str = tvb_bcd_dig_to_wmem_packet_str( tvb, offset, len, NULL, FALSE);
proto_tree_add_string(tree, hf_mip6_opt_3gpp_imsi, tvb, offset, len, imsi_str);
proto_item_append_text(hdr_item," %s", imsi_str);
break;
case 17:
proto_tree_add_item(tree, hf_mip6_opt_3gpp_pdn_conn_id, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 18:
next_tvb = tvb_new_subset_length(tvb, offset, len);
dissect_gtpv2_epc_timer(next_tvb, pinfo, tree, hdr_item, len, 0, 0);
break;
case 19:
proto_tree_add_item(tree, hf_hf_mip6_opt_3gpp_lapi, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_mip6_vsm_data_not_dissected, tvb, offset, len);
break;
}
return len;
}
static void
dissect_mip6_opt_padn(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_,
proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
guint8 len;
offset++;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (len > 0) {
proto_tree_add_item(opt_tree, hf_mip6_opt_padn, tvb, offset, len, ENC_NA);
}
}
static void
dissect_mip6_opt_bra(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_,
proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
int ri;
ri = tvb_get_ntohs(tvb, offset + MIP6_BRA_RI_OFF);
proto_tree_add_uint_format_value(opt_tree, hf_mip6_bra_interval, tvb,
offset, optlen,
ri, "%d (%ld seconds)",
ri, (long)ri * 4);
}
static void
dissect_mip6_opt_acoa(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_,
proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
proto_tree_add_item(opt_tree, hf_mip6_acoa_acoa, tvb,
offset + MIP6_ACOA_ACOA_OFF, MIP6_ACOA_ACOA_LEN, ENC_NA);
}
static void
dissect_mip6_opt_ni(const mip6_opt *optp, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_,
proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(opt_tree, tvb, offset, optlen, *optp->subtree_index, NULL, optp->name);
proto_tree_add_item(field_tree, hf_mip6_ni_hni, tvb,
offset + MIP6_NI_HNI_OFF, MIP6_NI_HNI_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mip6_ni_cni, tvb,
offset + MIP6_NI_CNI_OFF, MIP6_NI_CNI_LEN, ENC_BIG_ENDIAN);
}
static void
dissect_mip6_opt_bad(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_,
proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(opt_tree, tvb, offset, optlen, *optp->subtree_index, NULL, optp->name);
proto_tree_add_item(field_tree, hf_mip6_bad_auth, tvb,
offset + MIP6_BAD_AUTH_OFF,
optlen - MIP6_BAD_AUTH_OFF, ENC_NA);
}
static void
dissect_mip6_nemo_opt_mnp(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_,
proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
proto_tree *field_tree;
guint8 prefix_len;
field_tree = proto_tree_add_subtree(opt_tree, tvb, offset, optlen, *optp->subtree_index, NULL, optp->name);
proto_tree_add_item(opt_tree, hf_mip6_nemo_mnp_pfl, tvb,
offset + MIP6_NEMO_MNP_PL_OFF, 1, ENC_BIG_ENDIAN);
prefix_len = tvb_get_guint8(tvb, offset + MIP6_NEMO_MNP_PL_OFF);
proto_tree_add_item(field_tree, hf_mip6_nemo_mnp_mnp, tvb,
offset + MIP6_NEMO_MNP_MNP_OFF, MIP6_NEMO_MNP_MNP_LEN, ENC_NA);
proto_item_append_text(hdr_item, ": %s/%u",
tvb_ip6_to_str(tvb, offset + MIP6_NEMO_MNP_MNP_OFF), prefix_len);
}
static void
dissect_fmip6_opt_lla(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_,
proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
proto_tree *field_tree;
int len;
field_tree = proto_tree_add_subtree(opt_tree, tvb, offset, optlen, *optp->subtree_index, NULL, optp->name);
proto_tree_add_item(field_tree, hf_mip6_opt_len, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_fmip6_lla_optcode, tvb,
offset + FMIP6_LLA_OPTCODE_OFF, FMIP6_LLA_OPTCODE_LEN, ENC_BIG_ENDIAN);
len = optlen - FMIP6_LLA_LLA_OFF;
if (len > 0) {
proto_tree_add_item(field_tree, hf_fmip6_lla, tvb, offset + FMIP6_LLA_LLA_OFF, len, ENC_NA);
}
}
static void
dissect_mip6_opt_mnid(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item)
{
int len;
gchar *str;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_mnid_subtype, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
len = optlen - MIP6_MNID_MNID_OFF;
if (len > 0) {
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_UTF_8|ENC_NA);
proto_tree_add_string(opt_tree, hf_mip6_mnid_identifier, tvb, offset, len, str);
proto_item_append_text(hdr_item, ": %s", str);
}
}
static void
dissect_mip6_opt_auth(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_auth_sub_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_auth_mobility_spi, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(opt_tree, hf_mip6_opt_auth_auth_data, tvb, offset, optlen-4-3, ENC_NA);
}
static void
dissect_mip6_opt_mseg_id(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_mseg_id_timestamp, tvb, offset, 8, ENC_BIG_ENDIAN);
}
static void
dissect_mip6_opt_cgar(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_cgar_cga_par, tvb, offset, optlen-2, ENC_NA);
}
static void
dissect_mip6_opt_sign(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_sign_sign, tvb, offset, optlen-2, ENC_NA);
}
static void
dissect_mip6_opt_phkt(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_phkt_phkt, tvb, offset, optlen-2, ENC_NA);
}
static void
dissect_mip6_opt_mocot(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_mocot_co_keygen_tok, tvb, offset, optlen-2, ENC_NA);
}
static void
dissect_mip6_opt_dnsu(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_dnsu_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_dnsu_flag_r, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_dnsu_mn_id, tvb, offset, optlen-2-2, ENC_NA);
}
static void
dissect_mip6_opt_em(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_em_data, tvb, offset, optlen-2, ENC_NA);
}
static void
dissect_mip6_opt_vsm(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
tvbuff_t *next_tvb;
int len;
guint32 vendorid;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_vsm_vid, tvb,
offset, MIP6_VSM_VID_LEN, ENC_BIG_ENDIAN);
vendorid = tvb_get_ntohl(tvb, offset);
proto_item_append_text(hdr_item, ": %s", val_to_str_ext_const(vendorid, &sminmpec_values_ext, "<unknown>"));
offset += 4;
next_tvb = tvb_new_subset_length(tvb, offset, optlen-MIP6_VSM_SUBTYPE_OFF);
if (!dissector_try_uint(mip6_vsm_dissector_table, vendorid, next_tvb, pinfo, opt_tree)){
proto_tree_add_item(opt_tree, hf_mip6_vsm_subtype, tvb,
offset, MIP6_VSM_SUBTYPE_LEN, ENC_BIG_ENDIAN);
offset++;
len = optlen - MIP6_VSM_DATA_OFF;
if (len > 0){
proto_tree_add_item(opt_tree, hf_mip6_vsm_data, tvb, offset, len, ENC_NA);
}
}
}
static void
dissect_mip6_opt_ssm(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
int len;
guint8 *str;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
len = optlen - MIP6_SSM_SSM_OFF;
if (len > 0) {
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_UTF_8|ENC_NA);
proto_tree_add_string(opt_tree, hf_mip6_opt_ss_identifier, tvb, offset, len, str);
proto_item_append_text(hdr_item, ": %s", str);
}
}
static void
dissect_mip6_opt_badff(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_badff_spi, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(opt_tree, hf_mip6_opt_badff_auth, tvb, offset, optlen-4-2, ENC_NA);
}
static void
dissect_pmip6_opt_hi(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
guint8 hi;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_pmip6_hi_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
hi = tvb_get_guint8(tvb,offset);
proto_tree_add_item(opt_tree, hf_pmip6_hi_hi, tvb,
offset, PMIP6_HI_HI_LEN, ENC_BIG_ENDIAN);
proto_item_append_text(hdr_item, ": %s", val_to_str_const(hi, pmip6_hi_opttype_value, "<unknown>"));
}
static void
dissect_pmip6_opt_att(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
guint8 att;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_pmip6_att_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
att = tvb_get_guint8(tvb,offset);
proto_tree_add_item(opt_tree, hf_pmip6_att_att, tvb,
offset, PMIP6_ATT_ATT_LEN, ENC_BIG_ENDIAN);
proto_item_append_text(hdr_item, ": %s", val_to_str_ext_const(att, &pmip6_att_att_value_ext, "<unknown>"));
}
static void
dissect_pmip6_opt_mnlli(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_mnlli_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(opt_tree, hf_mip6_opt_mnlli_lli, tvb, offset, optlen-2-2, ENC_NA);
}
static void dissect_pmip6_opt_lla(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
proto_tree *field_tree;
if (opt_tree) {
field_tree = proto_tree_add_subtree(opt_tree, tvb, offset, optlen, *optp->subtree_index, NULL, optp->name);
proto_tree_add_item(field_tree, hf_pmip6_opt_lila_lla, tvb, offset + 2, 16, ENC_NA);
}
}
static void
dissect_pmip6_opt_ts(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
const gchar *str;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
str = tvb_mip6_fmt_ts(tvb,offset);
proto_tree_add_string(opt_tree, hf_pmip6_timestamp, tvb, offset, 8, str);
proto_item_append_text(hdr_item, ": %s", str);
}
static void
dissect_pmip6_opt_rc(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
proto_tree_add_item(opt_tree, hf_pmip6_rc, tvb,
offset + PMIP6_RC_RC_OFF, PMIP6_RC_RC_LEN, ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_ipv4ha(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
proto_tree *field_tree;
int len, p;
field_tree = proto_tree_add_subtree(opt_tree, tvb, offset, optlen, *optp->subtree_index, NULL, optp->name);
p = offset + MIP6_IPV4HA_PREFIXL_OFF;
len = MIP6_IPV4HA_PREFIXL_LEN;
proto_tree_add_item(field_tree, hf_mip6_ipv4ha_preflen, tvb, p, len, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mip6_ipv4ha_p_flag, tvb, p, len+1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mip6_ipv4ha_ha, tvb,
offset + MIP6_IPV4HA_HA_OFF, MIP6_IPV4HA_HA_LEN, ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_ipv4aa(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(opt_tree, tvb, offset, optlen, *optp->subtree_index, NULL, optp->name);
proto_tree_add_item(field_tree, hf_mip6_ipv4aa_status, tvb,
offset + MIP6_IPV4AA_STATUS_OFF, MIP6_IPV4AA_STATUS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mip6_ipv4ha_preflen, tvb,
offset + MIP6_IPV4AA_PREFIXL_OFF, MIP6_IPV4AA_PREFIXL_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mip6_ipv4ha_ha, tvb,
offset + MIP6_IPV4AA_HA_OFF, MIP6_IPV4AA_HA_LEN, ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_natd(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
proto_item *item;
guint32 refresh_time;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_natd_f_flag, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_mip6_opt_natd_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
refresh_time = tvb_get_ntohl(tvb, offset);
item = proto_tree_add_item(opt_tree, hf_mip6_opt_natd_refresh_t, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(item, " seconds");
if (refresh_time == 0) {
proto_item_append_text(item, " (Ignore)");
}
if (refresh_time == 0xffffffff) {
proto_item_append_text(item, " (keepalives are not needed, no NAT detected)");
}
}
static void
dissect_pmip6_opt_ipv4coa(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_ipv4coa_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(opt_tree, hf_mip6_opt_ipv4coa_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_grek(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_ipv4dra_reserved, tvb,
offset, 2, ENC_BIG_ENDIAN);
if (optlen == 8) {
offset += 2;
proto_tree_add_item(opt_tree, hf_pmip6_gre_key, tvb,
offset, PMIP6_GREK_ID_LEN, ENC_BIG_ENDIAN);
proto_item_append_text(hdr_item, ": %u", tvb_get_ntohl(tvb,offset));
}
}
static void
dissect_pmip6_opt_mhipv6ap(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
guint8 prefix_l;
proto_item *ti;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_mhipv6ap_opt_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
prefix_l = tvb_get_guint8(tvb,offset);
proto_tree_add_item(opt_tree, hf_mip6_opt_mhipv6ap_prefix_l, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_mhipv6ap_ipv6_address, tvb, offset, 16, ENC_NA);
ti = proto_tree_add_string(opt_tree, hf_mip6_opt_mhipv6ap_ipv6_address_prefix, tvb, offset -1, 16+1, tvb_ip6_to_str(tvb, offset));
proto_item_append_text(ti, "/%u", prefix_l);
PROTO_ITEM_SET_GENERATED(ti);
}
static void
dissect_pmip6_opt_bi(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_bi_bid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(opt_tree, hf_mip6_opt_bi_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_bi_h_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (optlen == 8) {
proto_tree_add_item(opt_tree, hf_mip6_bi_coa_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
}else if (optlen == 20) {
proto_tree_add_item(opt_tree, hf_mip6_bi_coa_ipv6, tvb, offset, 16, ENC_NA);
}
}
static void
dissect_pmip6_opt_ipv4hareq(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
proto_item *item;
guint32 dword;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_ipv4ha_preflen, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
offset++;
dword = tvb_get_ntohl(tvb,offset);
item = proto_tree_add_item(opt_tree, hf_mip6_ipv4ha_ha, tvb,
offset, MIP6_IPV4HAREQ_HA_LEN, ENC_BIG_ENDIAN);
if (dword == 0) {
proto_item_append_text(item, " - Request that the local mobility anchor perform the address allocation");
}
proto_item_append_text(hdr_item, ": %s", tvb_ip_to_str(tvb,offset));
}
static void
dissect_pmip6_opt_ipv4harep(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
guint8 status;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
status = tvb_get_guint8(tvb,offset);
proto_tree_add_item(opt_tree, hf_mip6_ipv4aa_status, tvb,
offset, MIP6_IPV4HAREP_STATUS_LEN, ENC_BIG_ENDIAN);
proto_item_append_text(hdr_item, ": %s ", val_to_str_const(status, pmip6_ipv4aa_status_values, "<unknown>"));
offset++;
proto_tree_add_item(opt_tree, hf_mip6_ipv4ha_preflen, tvb,
offset, MIP6_IPV4HAREP_PREFIXL_LEN, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_ipv4ha_ha, tvb,
offset, MIP6_IPV4HAREP_HA_LEN, ENC_BIG_ENDIAN);
proto_item_append_text(hdr_item, ": %s", tvb_ip_to_str(tvb,offset));
}
static void
dissect_pmip6_opt_ipv4dra(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_ipv4dra_reserved, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(opt_tree, hf_mip6_ipv4dra_dra, tvb,
offset, MIP6_IPV4DRA_DRA_LEN, ENC_BIG_ENDIAN);
proto_item_append_text(hdr_item, ": %s", tvb_ip_to_str(tvb,offset));
}
static void
dissect_pmip6_opt_ipv4dsm(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_ipv4dsm_reserved, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_mip6_ipv4dsm_s_flag, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_cr(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
gint offset_start;
guint8 req_type, req_length;
guint32 vendorid;
offset_start = offset;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_cr_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while ((guint)(offset-offset_start) < optlen) {
req_type = tvb_get_guint8(tvb,offset);
proto_tree_add_item(opt_tree, hf_mip6_cr_req_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
req_length = tvb_get_guint8(tvb,offset);
proto_tree_add_item(opt_tree, hf_mip6_cr_req_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (req_length == 0)
continue;
if (req_type == MIP6_VSM) {
vendorid = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(opt_tree, hf_mip6_vsm_vid, tvb, offset, 4, ENC_BIG_ENDIAN);
if (vendorid == VENDOR_THE3GPP) {
proto_tree_add_item(opt_tree, hf_mip6_vsm_subtype_3gpp, tvb, offset+4, 1, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(opt_tree, hf_mip6_vsm_subtype, tvb, offset+4, 1, ENC_BIG_ENDIAN);
}
}
else {
proto_tree_add_item(opt_tree, hf_mip6_vsm_req_data, tvb, offset, req_length, ENC_NA);
}
offset += req_length;
}
}
static void
dissect_pmip6_opt_lmaa(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
guint8 opt_code;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
opt_code = tvb_get_guint8(tvb,offset);
proto_tree_add_item(opt_tree, hf_mip6_lmaa_opt_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(opt_tree, hf_mip6_lmaa_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (opt_code == 1) {
proto_tree_add_item(opt_tree, hf_mip6_lmaa_ipv6, tvb, offset, 16, ENC_NA);
proto_item_append_text(hdr_item, ": %s", tvb_ip6_to_str(tvb,offset));
}else if (opt_code == 2) {
proto_tree_add_item(opt_tree, hf_mip6_lmaa_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(hdr_item, ": %s", tvb_ip_to_str(tvb,offset));
}
}
static void
dissect_pmip6_opt_recap(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_recap_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_redir(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
guint16 flag;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_redir_k, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_mip6_opt_redir_n, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_mip6_opt_redir_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
flag = tvb_get_ntohs(tvb ,offset);
offset +=2;
if (flag & MIP6_REDIR_FLAG_K) {
proto_tree_add_item(opt_tree, hf_mip6_opt_redir_addr_r2LMA_ipv6, tvb, offset, 16, ENC_NA);
offset +=16;
}
if (flag & MIP6_REDIR_FLAG_N) {
proto_tree_add_item(opt_tree, hf_mip6_opt_redir_addr_r2LMA_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
}
}
static void
dissect_pmip6_opt_load_inf(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_load_inf_priority, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
proto_tree_add_item(opt_tree, hf_mip6_opt_load_inf_sessions_in_use, tvb, offset, 4, ENC_BIG_ENDIAN);
offset +=4;
proto_tree_add_item(opt_tree, hf_mip6_opt_load_inf_maximum_sessions, tvb, offset, 4, ENC_BIG_ENDIAN);
offset +=4;
proto_tree_add_item(opt_tree, hf_mip6_opt_load_inf_used_capacity, tvb, offset, 4, ENC_BIG_ENDIAN);
offset +=4;
proto_tree_add_item(opt_tree, hf_mip6_opt_load_inf_maximum_capacity, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_alt_ip4(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_alt_ip4, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_mng(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
proto_item *item;
guint32 mng_id;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_mng_sub_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_mng_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
mng_id = tvb_get_ntohl(tvb, offset);
item = proto_tree_add_item(opt_tree, hf_mip6_opt_mng_mng_id, tvb, offset, 4, ENC_BIG_ENDIAN);
if (mng_id == 1) {
proto_item_append_text(item, " - ALL-SESSIONS");
}
}
static void
dissect_pmip6_opt_mag_ipv6(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_mag_ipv6_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_mag_ipv6_address_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_mag_ipv6_address, tvb, offset, 16, ENC_NA);
}
static float
degrees_convert_fixed_to_float(guint value)
{
if (!value)
return 0;
if (value & 0x800000) {
value |= 0xFF000000;
}
return ((float)(gint)value) / 32768.0f;
}
static void
degrees_base_custom(gchar *str, guint degrees)
{
g_snprintf(str, ITEM_LABEL_LENGTH, "%f", degrees_convert_fixed_to_float(degrees) );
}
static void
dissect_pmip6_opt_acc_net_id(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
proto_item *ti;
proto_tree *subopt_tree;
gint16 length, sub_opt_len;
guint8 sub_opt, e_bit, net_name_len, ap_name_len;
gint offset_end;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
length = tvb_get_guint8(tvb,offset);
offset_end = offset + length;
offset++;
while(offset < offset_end) {
ti = proto_tree_add_item(opt_tree, hf_mip6_opt_acc_net_id_sub, tvb, offset, 2, ENC_NA);
subopt_tree = proto_item_add_subtree(ti, ett_mip6_sub_opt_acc_net_id);
proto_tree_add_item(subopt_tree, hf_mip6_opt_acc_net_id_sub_opt, tvb, offset, 1, ENC_BIG_ENDIAN);
sub_opt = tvb_get_guint8(tvb,offset);
offset++;
proto_tree_add_item(subopt_tree, hf_mip6_opt_acc_net_id_sub_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
sub_opt_len = tvb_get_guint8(tvb,offset);
offset++;
proto_item_append_text(ti, ": %s (t=%d,l=%d)", val_to_str(sub_opt, mmip6_opt_acc_net_id_sub_opt_vals, "Unknown ANI Type (%02d)"), sub_opt, sub_opt_len);
proto_item_set_len(ti, sub_opt_len+2);
switch(sub_opt){
case 1:
e_bit = tvb_get_guint8(tvb,offset);
proto_tree_add_item(subopt_tree, hf_mip6_opt_acc_net_id_sub_opt_e_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
net_name_len = tvb_get_guint8(tvb,offset);
proto_tree_add_item(subopt_tree, hf_mip6_opt_acc_net_id_sub_opt_net_name_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if(e_bit == 0x80){
proto_tree_add_item(subopt_tree, hf_mip6_opt_acc_net_id_sub_opt_net_name, tvb, offset, net_name_len, ENC_BIG_ENDIAN|ENC_UTF_8);
proto_item_append_text(ti, " Network Name: %s", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, net_name_len, ENC_UTF_8));
}else{
proto_tree_add_item(subopt_tree, hf_mip6_opt_acc_net_id_sub_opt_net_name_data, tvb, offset, net_name_len, ENC_BIG_ENDIAN|ENC_UTF_8);
};
offset = offset+net_name_len;
ap_name_len = tvb_get_guint8(tvb,offset);
proto_tree_add_item(subopt_tree, hf_mip6_opt_acc_net_id_sub_opt_ap_name_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subopt_tree, hf_mip6_opt_acc_net_id_sub_opt_ap_name, tvb, offset, ap_name_len, ENC_BIG_ENDIAN|ENC_UTF_8);
proto_item_append_text(ti, " AP Name: %s", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, ap_name_len, ENC_UTF_8));
offset = offset+ap_name_len;
break;
case 2:
proto_tree_add_item(subopt_tree, hf_mip6_opt_acc_net_id_sub_opt_geo_latitude_degrees, tvb, offset, 3, ENC_BIG_ENDIAN);
offset +=3;
proto_tree_add_item(subopt_tree, hf_mip6_opt_acc_net_id_sub_opt_geo_longitude_degrees, tvb, offset, 3, ENC_BIG_ENDIAN);
offset +=3;
break;
case 3:
proto_tree_add_item(subopt_tree, hf_mip6_opt_acc_net_id_sub_opt_op_id_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(subopt_tree, hf_mip6_opt_acc_net_id_sub_opt_op_id, tvb, offset, sub_opt_len - 1, ENC_NA);
offset = offset + sub_opt_len - 1;
break;
default:
proto_tree_add_expert(subopt_tree, pinfo, &ei_mip6_ani_type_not_dissected, tvb, offset, sub_opt_len);
offset = offset + sub_opt_len;
break;
}
}
}
static void
dissect_mip6_opt_dmnp(const mip6_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_,
proto_tree *opt_tree, proto_item *hdr_item _U_ )
{
int len = tvb_reported_length(tvb);
guint8 prefix_len;
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_len, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_dmnp_v_flag, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_mip6_opt_dmnp_reserved, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(opt_tree, hf_mip6_opt_dmnp_prefix_len, tvb,
offset, 1, ENC_BIG_ENDIAN);
prefix_len = tvb_get_guint8(tvb, offset);
offset++;
switch (optlen) {
case 8:
proto_tree_add_item(opt_tree, hf_mip6_opt_dmnp_dmnp_ipv4, tvb,
offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(hdr_item, ": %s/%u",
tvb_ip_to_str(tvb, offset), prefix_len);
break;
case 20:
proto_tree_add_item(opt_tree, hf_mip6_opt_dmnp_dmnp_ipv6, tvb,
offset, 16, ENC_NA);
proto_item_append_text(hdr_item, ": %s/%u",
tvb_ip6_to_str(tvb, offset), prefix_len);
break;
default:
proto_tree_add_expert(opt_tree, pinfo, &ei_mip6_opt_len_invalid,
tvb, offset, len);
break;
}
}
static void
dissect_mipv6_options(tvbuff_t *tvb, int offset, guint length,
const mip6_opt *opttab, int nopts, int eol,
packet_info *pinfo, proto_tree *opt_tree)
{
proto_item *ti;
proto_tree *opt_data_tree = NULL;
guchar opt;
const mip6_opt *optp;
opt_len_type len_type;
unsigned int optlen;
const char *name;
char name_str[7+1+1+2+2+1+1];
void (*dissect)(const struct mip6_opt *, tvbuff_t *,
int, guint, packet_info *, proto_tree *, proto_item *);
guint len;
while ((gint)length > 0) {
opt = tvb_get_guint8(tvb, offset);
for (optp = &opttab[0]; optp < &opttab[nopts]; optp++) {
if (optp->optcode == opt)
break;
}
if (optp == &opttab[nopts]) {
optp = NULL;
len_type = OPT_LEN_VARIABLE_LENGTH;
optlen = 0;
g_snprintf(name_str, sizeof name_str, "Unknown (0x%02x)", opt);
name = name_str;
dissect = NULL;
} else {
len_type = optp->len_type;
optlen = optp->optlen;
name = optp->name;
dissect = optp->dissect;
}
--length;
if (len_type != OPT_LEN_NO_LENGTH) {
if (length == 0) {
proto_tree_add_expert_format(opt_tree, pinfo, &ei_mip6_opt_len_invalid, tvb, offset, 1,
"%s (length byte past end of options)", name);
return;
}
len = tvb_get_guint8(tvb, offset + 1);
--length;
if (len > length) {
proto_tree_add_expert_format(opt_tree, pinfo, &ei_mip6_opt_len_invalid, tvb, offset, length,
"%s (option length = %u byte%s says option goes past end of options)",
name, len, plurality(len, "", "s"));
return;
} else if (len_type == OPT_LEN_FIXED_LENGTH && len != optlen) {
proto_tree_add_expert_format(opt_tree, pinfo, &ei_mip6_opt_len_invalid, tvb, offset, len + 2,
"%s (with option length = %u byte%s; should be %u)", name,
len, plurality(len, "", "s"), optlen);
return;
} else if (len_type == OPT_LEN_VARIABLE_LENGTH && len < optlen) {
proto_tree_add_expert_format(opt_tree, pinfo, &ei_mip6_opt_len_invalid, tvb, offset, len + 2,
"%s (with option length = %u byte%s; should be >= %u)", name,
len, plurality(len, "", "s"), optlen);
return;
} else {
ti = proto_tree_add_string(opt_tree, hf_mip6_mobility, tvb, offset, len + 2,
val_to_str_ext_const(opt, &mip6_mobility_options_ext, "<unknown>"));
if (optp && *optp->subtree_index) {
opt_data_tree = proto_item_add_subtree(ti, *optp->subtree_index);
} else {
opt_data_tree = proto_item_add_subtree(ti, ett_mip6_opt_unknown);
}
proto_tree_add_item(opt_data_tree, hf_mip6_mobility_opt, tvb, offset, 1, ENC_BIG_ENDIAN);
if (optp == NULL) {
proto_item_append_text(ti, "(%u byte%s)",len, plurality(len, "", "s"));
expert_add_info(pinfo, ti, &ei_mip6_ie_not_dissected);
} else {
if (dissect != NULL) {
(*dissect)(optp, tvb, offset, len + 2, pinfo, opt_data_tree, ti);
}
}
offset += len + 2;
}
length -= len;
} else {
proto_tree_add_uint_format(opt_tree, hf_mip6_option_unknown, tvb, offset, 1, opt, "%s", name);
offset += 1;
}
if (opt == eol)
break;
}
}
static int
dissect_mip6_options(tvbuff_t *tvb, proto_tree *mip6_tree, int offset, int len,
packet_info *pinfo)
{
proto_tree *opts_tree;
opts_tree = proto_tree_add_subtree(mip6_tree, tvb, offset, len, ett_mip6, NULL, "Mobility Options");
dissect_mipv6_options(tvb, offset, len, mip6_opts, N_MIP6_OPTS, -1, pinfo, opts_tree);
return len;
}
static void
dissect_mip6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *mip6_tree = NULL;
guint8 type, pproto;
guint len, offset = 0, start_offset = offset;
proto_item *ti, *header_item;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MIPv6");
col_clear(pinfo->cinfo, COL_INFO);
len = (tvb_get_guint8(tvb, MIP6_HLEN_OFF) + 1) * 8;
pproto = tvb_get_guint8(tvb, MIP6_PROTO_OFF);
ti = proto_tree_add_item(tree, proto_mip6, tvb, 0, len, ENC_NA);
mip6_tree = proto_item_add_subtree(ti, ett_mip6);
proto_tree_add_item(mip6_tree, hf_mip6_proto, tvb,
MIP6_PROTO_OFF, 1, ENC_BIG_ENDIAN);
header_item = proto_tree_add_uint_format_value(mip6_tree, hf_mip6_hlen, tvb,
MIP6_HLEN_OFF, 1,
tvb_get_guint8(tvb, MIP6_HLEN_OFF),
"%u (%u bytes)",
tvb_get_guint8(tvb, MIP6_HLEN_OFF),
len);
proto_tree_add_item(mip6_tree, hf_mip6_mhtype, tvb,
MIP6_TYPE_OFF, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mip6_tree, hf_mip6_reserved, tvb,
MIP6_RES_OFF, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mip6_tree, hf_mip6_csum, tvb,
MIP6_CSUM_OFF, 2, ENC_BIG_ENDIAN);
type = tvb_get_guint8(tvb, MIP6_TYPE_OFF);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_ext_const(type, &mip6_mh_types_ext, "<unknown>"));
switch (type) {
case MIP6_BRR:
offset = dissect_mip6_brr(tvb, mip6_tree, pinfo);
break;
case MIP6_HOTI:
offset = dissect_mip6_hoti(tvb, mip6_tree, pinfo);
break;
case MIP6_MHCOTI:
offset = dissect_mip6_coti(tvb, mip6_tree, pinfo);
break;
case MIP6_HOT:
offset = dissect_mip6_hot(tvb, mip6_tree, pinfo);
break;
case MIP6_MHCOT:
offset = dissect_mip6_cot(tvb, mip6_tree, pinfo);
break;
case MIP6_BU:
pinfo->link_dir = P2P_DIR_UL;
offset = dissect_mip6_bu(tvb, mip6_tree, pinfo);
if (proto_nemo == 1) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NEMO");
}
break;
case MIP6_BA:
pinfo->link_dir = P2P_DIR_DL;
offset = dissect_mip6_ba(tvb, mip6_tree, pinfo);
if (proto_nemo == 1) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NEMO");
}
break;
case MIP6_BE:
offset = dissect_mip6_be(tvb, mip6_tree, pinfo);
break;
case MIP6_FBU:
offset = dissect_fmip6_fbu(tvb, mip6_tree, pinfo);
break;
case MIP6_FBACK:
offset = dissect_fmip6_fback(tvb, mip6_tree, pinfo);
break;
case MIP6_FNA:
offset = dissect_fmip6_fna(tvb, mip6_tree, pinfo);
break;
case MIP6_EMH:
if (len > 8) {
proto_tree_add_item(mip6_tree, hf_mip6_opt_em_data, tvb, offset+MIP6_DATA_OFF, len-MIP6_DATA_OFF, ENC_NA);
}
offset = len;
break;
case MIP6_HAS:
dissect_mip6_unknown(tvb, mip6_tree, pinfo);
offset = len;
break;
case MIP6_HB:
offset = dissect_mip6_hb(tvb, mip6_tree, pinfo);
break;
case MIP6_HI:
offset = dissect_mip6_hi(tvb, mip6_tree, pinfo);
break;
case MIP6_HAck:
offset = dissect_mip6_hack(tvb, mip6_tree, pinfo);
break;
case MIP6_BR:
offset = dissect_pmip6_bri(tvb, mip6_tree, pinfo);
break;
case MIP6_LRI:
offset = dissect_pmip6_lri(tvb, mip6_tree, pinfo, offset);
break;
case MIP6_LRA:
offset = dissect_pmip6_lra(tvb, mip6_tree, pinfo, offset);
break;
default:
dissect_mip6_unknown(tvb, mip6_tree, pinfo);
offset = len;
break;
}
if (offset < len) {
if (len < (offset - start_offset)) {
expert_add_info(pinfo, header_item, &ei_mip6_bogus_header_length);
return;
}
len -= (offset - start_offset);
dissect_mip6_options(tvb, mip6_tree, offset, len, pinfo);
}
if ((type == MIP6_FNA) && (pproto == IP_PROTO_IPV6)) {
tvbuff_t *ipv6_tvb;
ipv6_tvb = tvb_new_subset_remaining(tvb, len + 8);
dissector_try_uint(ip_dissector_table, pproto, ipv6_tvb, pinfo, tree);
col_set_str(pinfo->cinfo, COL_INFO, "Fast Neighbor Advertisement[Fast Binding Update]");
}
if ((type == MIP6_FBACK) && (pproto == IP_PROTO_AH)) {
tvbuff_t *ipv6_tvb;
ipv6_tvb = tvb_new_subset_remaining(tvb, len + offset);
dissector_try_uint(ip_dissector_table, pproto, ipv6_tvb, pinfo, tree);
col_set_str(pinfo->cinfo, COL_INFO, "Fast Binding Acknowledgment");
}
}
void
proto_register_mip6(void)
{
static hf_register_info hf[] = {
{ &hf_mip6_proto,
{ "Payload protocol", "mip6.proto",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ipproto_val_ext, 0,
NULL, HFILL }
},
{ &hf_mip6_hlen,
{ "Header length", "mip6.hlen",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_mhtype,
{ "Mobility Header Type", "mip6.mhtype",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &mip6_mh_types_ext, 0,
NULL, HFILL }
},
{ &hf_mip6_reserved,
{ "Reserved", "mip6.reserved",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_csum,
{ "Checksum", "mip6.csum",
FT_UINT16, BASE_HEX, NULL, 0,
"Header Checksum", HFILL }
},
{ &hf_mip6_hoti_cookie,
{ "Home Init Cookie", "mip6.hoti.cookie",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_coti_cookie,
{ "Care-of Init Cookie", "mip6.coti.cookie",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_hot_nindex,
{ "Home Nonce Index", "mip6.hot.nindex",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_hot_cookie,
{ "Home Init Cookie", "mip6.hot.cookie",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_hot_token,
{ "Home Keygen Token", "mip6.hot.token",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_cot_nindex,
{ "Care-of Nonce Index", "mip6.cot.nindex",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_cot_cookie,
{ "Care-of Init Cookie", "mip6.cot.cookie",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
#if 0
{ &hf_mip6_cot_token,
{ "Care-of Keygen Token", "mip6.cot.token",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
#endif
{ &hf_mip6_bu_seqnr,
{ "Sequence number", "mip6.bu.seqnr",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_bu_a_flag,
{ "Acknowledge (A) flag", "mip6.bu.a_flag",
FT_BOOLEAN, 16, TFS(&mip6_bu_a_flag_value), 0x8000,
NULL, HFILL }
},
{ &hf_mip6_bu_h_flag,
{ "Home Registration (H) flag", "mip6.bu.h_flag",
FT_BOOLEAN, 16, TFS(&mip6_bu_h_flag_value), 0x4000,
NULL, HFILL }
},
{ &hf_mip6_bu_l_flag,
{ "Link-Local Compatibility (L) flag", "mip6.bu.l_flag",
FT_BOOLEAN, 16, TFS(&mip6_bu_l_flag_value), 0x2000,
"Home Registration (H) flag", HFILL }
},
{ &hf_mip6_bu_k_flag,
{ "Key Management Compatibility (K) flag", "mip6.bu.k_flag",
FT_BOOLEAN, 16, TFS(&mip6_bu_k_flag_value), 0x1000,
NULL, HFILL }
},
{ &hf_mip6_bu_m_flag,
{ "MAP Registration Compatibility (M) flag", "mip6.bu.m_flag",
FT_BOOLEAN, 16, TFS(&mip6_bu_m_flag_value), 0x0800,
NULL, HFILL }
},
{ &hf_mip6_nemo_bu_r_flag,
{ "Mobile Router (R) flag", "mip6.nemo.bu.r_flag",
FT_BOOLEAN, 16, TFS(&mip6_nemo_bu_r_flag_value), 0x0400,
NULL, HFILL }
},
{ &hf_pmip6_bu_p_flag,
{ "Proxy Registration (P) flag", "mip6.bu.p_flag",
FT_BOOLEAN, 16, TFS(&pmip6_bu_p_flag_value), 0x0200,
NULL, HFILL }
},
{ &hf_mip6_bu_f_flag,
{ "Forcing UDP encapsulation (F) flag", "mip6.bu.f_flag",
FT_BOOLEAN, 16, TFS(&mip6_bu_f_flag_value), 0x0100,
NULL, HFILL }
},
{ &hf_pmip6_bu_t_flag,
{ "TLV-header format (T) flag", "mip6.bu.t_flag",
FT_BOOLEAN, 16, TFS(&pmip6_bu_t_flag_value), 0x0080,
NULL, HFILL }
},
{ &hf_pmip6_bu_b_flag,
{ "Bulk-Binding-Update flag (B)", "mip6.bu.b_flag",
FT_BOOLEAN, 16, TFS(&pmip6_bu_b_flag_value), 0x0040,
NULL, HFILL }
},
{ &hf_mip6_bu_lifetime,
{ "Lifetime", "mip6.bu.lifetime",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_ba_status,
{ "Status", "mip6.ba.status",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &mip6_ba_status_value_ext, 0,
"Binding Acknowledgement status", HFILL }
},
{ &hf_mip6_ba_k_flag,
{ "Key Management Compatibility (K) flag", "mip6.ba.k_flag",
FT_BOOLEAN, 8, TFS(&mip6_bu_k_flag_value), 0x80,
NULL, HFILL }
},
{ &hf_mip6_nemo_ba_r_flag,
{ "Mobile Router (R) flag", "mip6.nemo.ba.r_flag",
FT_BOOLEAN, 8, TFS(&mip6_nemo_bu_r_flag_value), 0x40,
NULL, HFILL }
},
{ &hf_pmip6_ba_p_flag,
{ "Proxy Registration (P) flag", "mip6.ba.p_flag",
FT_BOOLEAN, 8, TFS(&pmip6_bu_p_flag_value), 0x20,
NULL, HFILL }
},
{ &hf_pmip6_ba_t_flag,
{ "TLV-header format (T) flag", "mip6.ba.t_flag",
FT_BOOLEAN, 8, TFS(&pmip6_bu_t_flag_value), 0x10,
NULL, HFILL }
},
{ &hf_pmip6_ba_b_flag,
{ "Bulk-Binding-Update flag (B)", "mip6.ba.b_flag",
FT_BOOLEAN, 8, TFS(&pmip6_ba_b_flag_value), 0x08,
NULL, HFILL }
},
{ &hf_mip6_ba_seqnr,
{ "Sequence number", "mip6.ba.seqnr",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_ba_lifetime,
{ "Lifetime", "mip6.ba.lifetime",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_be_status,
{ "Status", "mip6.be.status",
FT_UINT8, BASE_DEC, VALS(mip6_be_status_value), 0,
"Binding Error status", HFILL }
},
{ &hf_mip6_be_haddr,
{ "Home Address", "mip6.be.haddr",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_fmip6_fbu_seqnr,
{ "Sequence number", "mip6.fbu.seqnr",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_fmip6_fbu_a_flag,
{ "Acknowledge (A) flag", "mip6.fbu.a_flag",
FT_BOOLEAN, 8, TFS(&fmip6_fbu_a_flag_value), 0x80,
NULL, HFILL }
},
{ &hf_fmip6_fbu_h_flag,
{ "Home Registration (H) flag", "mip6.fbu.h_flag",
FT_BOOLEAN, 8, TFS(&fmip6_fbu_h_flag_value), 0x40,
NULL, HFILL }
},
{ &hf_fmip6_fbu_l_flag,
{ "Link-Local Compatibility (L) flag", "mip6.fbu.l_flag",
FT_BOOLEAN, 8, TFS(&fmip6_fbu_l_flag_value), 0x20,
"Home Registration (H) flag", HFILL }
},
{ &hf_fmip6_fbu_k_flag,
{ "Key Management Compatibility (K) flag", "mip6.fbu.k_flag",
FT_BOOLEAN, 8, TFS(&fmip6_fbu_k_flag_value), 0x10,
NULL, HFILL }
},
{ &hf_fmip6_fbu_lifetime,
{ "Lifetime", "mip6.fbu.lifetime",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_fmip6_fback_status,
{ "Status", "mip6.fback.status",
FT_UINT8, BASE_DEC, VALS(fmip6_fback_status_value), 0,
"Fast Binding Acknowledgement status", HFILL }
},
{ &hf_fmip6_fback_k_flag,
{ "Key Management Compatibility (K) flag", "mip6.fback.k_flag",
FT_BOOLEAN, 8, TFS(&fmip6_fbu_k_flag_value), 0x80,
NULL, HFILL }
},
{ &hf_fmip6_fback_seqnr,
{ "Sequence number", "mip6.fback.seqnr",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_fmip6_fback_lifetime,
{ "Lifetime", "mip6.fback.lifetime",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_hb_u_flag,
{ "Unsolicited (U) flag", "mip6.hb.u_flag",
FT_BOOLEAN, 8, TFS(&mip6_hb_u_flag_value), 0x02,
NULL, HFILL }
},
{ &hf_mip6_hb_r_flag,
{ "Response (R) flag", "mip6.hb.r_flag",
FT_BOOLEAN, 8, TFS(&mip6_hb_r_flag_value), 0x01,
NULL, HFILL }
},
{ &hf_mip6_hb_seqnr,
{ "Sequence number", "mip6.hb.seqnr",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_hi_seqnr,
{ "Sequence number", "mip6.hi.seqnr",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_hi_s_flag,
{ "Assigned address configuration flag (S) flag", "mip6.hi.s_flag",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_mip6_hi_u_flag,
{ "Buffer flag (U) flag", "mip6.hi.u_flag",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_mip6_hi_code,
{ "Code", "mip6.hi.code",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_hack_seqnr,
{ "Sequence number", "mip6.hack.seqnr",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_hack_code,
{ "Code", "mip6.hack.code",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_3gpp_reserved,
{ "Reserved", "mip6.3gpp.reserved",
FT_UINT8, BASE_DEC, NULL, 0xfe,
NULL, HFILL }
},
{ &hf_mip6_opt_3gpp_flag_m,
{ "M flag", "mip6.3gpp.flag.m",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_mip6_opt_3gpp_spec_pmipv6_err_code,
{ "3GPP Specific PMIPv6 Error Code", "mip6.3gpp.spec_pmipv6_err_code",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gtpv2_cause_vals_ext, 0x0,
"GTPv2 Cause values", HFILL }
},
{ &hf_mip6_opt_3gpp_pdn_gw_ipv4_addr,
{ "PDN GW IPv4 address", "mip6.3gpp.pdn_gw_ipv4_addr",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_3gpp_pdn_gw_ipv6_addr,
{ "PDN GW IPv6 address", "mip6.3gpp.pdn_gw_ipv6_addr",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_3gpp_dhcpv4_addr_all_proc_ind,
{ "DHCPv4 Address Allocation Procedure Indication", "mip6.3gpp.dhcpv4_addr_all_proc_ind",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_3gpp_pdn_type,
{ "PDN type", "mip6.3gpp.pdn_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_3gpp_pdn_ind_cause,
{ "Cause", "mip6.3gpp.pdn_ind_cause",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gtpv2_cause_vals_ext, 0x0,
"GTPv2 Cause values", HFILL }
},
{ &hf_mip6_opt_3gpp_chg_id,
{ "Charging ID", "mip6.3gpp.chg_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_3gpp_charging_characteristic,
{"Charging Characteristic", "mip6.3gpp.charging_characteristic",
FT_UINT16, BASE_HEX, NULL, 0xffff,
NULL, HFILL}
},
{ &hf_mip6_opt_3gpp_mei,
{"Mobile Equipment Identity (MEI)", "mip6.3gpp.mei",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_mip6_opt_3gpp_msisdn,
{"MSISDN", "mip6.3gpp.msisdn",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_mip6_opt_3gpp_apn_rest,
{ "APN Restriction", "mip6.3gpp.apn_rest",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_3gpp_max_apn_rest,
{ "Maximum APN Restriction", "mip6.3gpp.max_apn_rest",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_3gpp_imsi,
{"Unauthenticated IMSI", "mip6.3gpp.imsi",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_mip6_opt_3gpp_pdn_conn_id,
{ "PDN Connection ID", "mip6.3gpp.pdn_conn_id",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_hf_mip6_opt_3gpp_lapi,
{"LAPI (Low Access Priority Indication)", "mip6.3gpp.lapi",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_mip6_bra_interval,
{ "Refresh interval", "mip6.bra.interval",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_acoa_acoa,
{ "Alternate care-of address", "mip6.acoa.acoa",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_ni_hni,
{ "Home nonce index", "mip6.ni.hni",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_ni_cni,
{ "Care-of nonce index", "mip6.ni.cni",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_bad_auth,
{ "Authenticator", "mip6.bad.auth",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_fmip6_lla,
{ "Link-layer address", "mip6.lla",
FT_BYTES, SEP_COLON, NULL, 0,
NULL, HFILL }
},
{ &hf_fmip6_lla_optcode,
{ "Option-Code", "mip6.lla.optcode",
FT_UINT8, BASE_DEC, VALS(fmip6_lla_optcode_value), 0,
NULL, HFILL }
},
{ &hf_mip6_nemo_mnp_pfl,
{ "Mobile Network Prefix Length", "mip6.nemo.mnp.pfl",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_nemo_mnp_mnp,
{ "Mobile Network Prefix", "mip6.nemo.mnp.mnp",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_mnid_subtype,
{ "Subtype", "mip6.mnid.subtype",
FT_UINT8, BASE_DEC, VALS(mip6_mnid_subtype_value), 0,
NULL, HFILL }
},
{ &hf_mip6_mnid_identifier,
{ "Identifier", "mip6.mnid.identifier",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_auth_sub_type,
{ "Subtype", "mip6.auth.subtype",
FT_UINT8, BASE_DEC, VALS(mip6_auth_subtype_value), 0,
NULL, HFILL }
},
{ &hf_mip6_opt_auth_mobility_spi,
{ "Mobility SPI", "mip6.auth.mobility_spi",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_auth_auth_data,
{ "Authentication Data", "mip6.auth.auth_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_mseg_id_timestamp,
{ "Timestamp", "mip6.mseg_id.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_cgar_cga_par,
{ "CGA Parameters", "mip6.cgar.cga_par",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_sign_sign,
{ "CGA Parameters", "mip6.sign.sign",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_phkt_phkt,
{ "Permanent Home Keygen Token", "mip6.phkt.phkt",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_mocot_co_keygen_tok,
{ "Care-of Keygen Token", "mip6.mocot.co_keygen_tok",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_dnsu_status,
{ "Status", "mip6.dnsu.status",
FT_UINT8, BASE_DEC, VALS(mip6_dnsu_status_values), 0,
NULL, HFILL }
},
{ &hf_mip6_opt_dnsu_flag_r,
{ "R flag", "mip6.dnsu.flag.r",
FT_BOOLEAN, 8, TFS(&mip6_dnsu_r_flag_value), 0x80,
NULL, HFILL }
},
{ &hf_mip6_opt_dnsu_mn_id,
{ "MN identity (FQDN)", "mip6.dnsu.mn_id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_em_data,
{ "Data", "mip6.em.data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_vsm_vid,
{ "Vendor Id", "mip6.vsm.vendorId",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0x0,
NULL, HFILL }
},
{ &hf_mip6_vsm_subtype,
{ "Subtype", "mip6.vsm.subtype",
FT_UINT8, BASE_DEC, VALS(mip6_vsm_subtype_value), 0,
NULL, HFILL }
},
{ &hf_mip6_vsm_subtype_3gpp,
{ "Subtype", "mip6.vsm.subtype",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &mip6_vsm_subtype_3gpp_value_ext, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_ss_identifier,
{ "Identifier", "mip6.ss.identifier",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_badff_spi,
{ "SPI", "mip6.badff.spi",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_badff_auth,
{ "Authenticator", "mip6.badff.auth",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pmip6_hi_hi,
{ "Handoff Indicator", "mip6.hi",
FT_UINT8, BASE_DEC, VALS(pmip6_hi_opttype_value), 0,
NULL, HFILL }
},
{ &hf_pmip6_hi_reserved,
{ "Reserved", "mip6.hi.reserved",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_pmip6_att_reserved,
{ "Reserved", "mip6.att.reserved",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_pmip6_att_att,
{ "Access Technology Type", "mip6.att",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &pmip6_att_att_value_ext, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_mnlli_reserved,
{ "Reserved", "mip6.mnlli.reserved",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_mip6_opt_mnlli_lli,
{ "Link-layer Identifier", "mip6.mnlli.lli",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pmip6_timestamp,
{ "Timestamp", "mip6.timestamp_tmp",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pmip6_opt_lila_lla,
{ "Link-local Address", "mip6.lila_lla",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pmip6_rc,
{ "Restart Counter", "mip6.rc",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_mip6_ipv4ha_preflen,
{ "Prefix-len", "mip6.ipv4ha.preflen",
FT_UINT8, BASE_DEC, NULL, 0xfc,
NULL, HFILL}
},
{ &hf_mip6_ipv4ha_p_flag,
{ "mobile network prefix (P) flag", "mip6.ipv4ha.p_flag",
FT_BOOLEAN, 16, TFS(&mip6_ipv4ha_p_flag_value), 0x0200,
NULL, HFILL }
},
{ &hf_mip6_ipv4ha_ha,
{ "IPv4 Home Address", "mip6.ipv4ha.ha",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_ipv4aa_status,
{ "Status", "mip6.ipv4aa.sts",
FT_UINT8, BASE_DEC, VALS(pmip6_ipv4aa_status_values), 0x0,
NULL, HFILL}
},
{ &hf_mip6_opt_natd_f_flag,
{ "(F) flag", "mip6.natd.f_flag",
FT_BOOLEAN, 16, TFS(&mip6_natd_f_flag_value), 0x8000,
NULL, HFILL }
},
{ &hf_mip6_opt_natd_reserved,
{ "Reserved", "mip6.natd.reserved",
FT_UINT16, BASE_DEC, NULL, 0x7fff,
NULL, HFILL }
},
{ &hf_mip6_opt_natd_refresh_t,
{ "Refresh time", "mip6.natd.refresh_t",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_ipv4coa_reserved,
{ "Reserved", "mip6.ipv4coa.reserved",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_mip6_opt_ipv4coa_addr,
{ "IPv4 Care-of address", "mip6.ipv4coa.addr",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pmip6_gre_key,
{ "GRE Key", "mip6.gre_key",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_mip6_opt_mhipv6ap_opt_code,
{ "Option-Code", "mip6.mhipv6ap.opt_code",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_mhipv6ap_prefix_l,
{ "Prefix Length", "mip6.mhipv6ap.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_mhipv6ap_ipv6_address,
{ "IPv6 Address", "mip6.mhipv6ap.ipv6_address",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_mhipv6ap_ipv6_address_prefix,
{ "IPv6 Address/Prefix", "mip6.mhipv6ap.ipv6_address_prefix",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_bi_bid,
{ "Binding ID (BID)", "mip6.bi.bid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_bi_status,
{ "Status", "mip6.bi.status",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_bi_h_flag,
{ "Simultaneous Home and Foreign Binding (H)", "mip6.bi.h_flag",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x80,
NULL, HFILL }
},
{ &hf_mip6_bi_coa_ipv4,
{ "IPv4 care-of address (CoA)", "mip6.bi.coa_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_bi_coa_ipv6,
{ "IPv6 care-of address (CoA)", "mip6.bi.coa_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_binding_refresh_request,
{ "Binding Refresh Request", "mip6.binding_refresh_request",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_unknown_mh_type,
{ "Unknown MH Type", "mip6.unknown_mh_type",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_fast_neighbor_advertisement,
{ "Fast Neighbor Advertisement", "mip6.fast_neighbor_advertisement",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_vsm_data,
{ "Data", "mip6.vsm.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_vsm_req_data,
{ "Req-Data", "mip6.vsm.req_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_padn,
{ "PadN", "mip6.padn",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_option_unknown,
{ "Option", "mip6.option_unknown",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_ipv4dra_reserved,
{ "Reserved", "mip6.ipv4dra.reserved",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_ipv4dra_dra,
{ "IPv4 Default-Router Address", "mip6.ipv4dra.dra",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_ipv4dsm_reserved,
{ "Reserved", "mip6.ipv4dsm.reserved",
FT_UINT16, BASE_DEC, NULL, 0xfffe,
NULL, HFILL }
},
{ &hf_mip6_ipv4dsm_s_flag,
{ "DHCP Support Mode (S)", "mip6.ipv4dsm.s_flag",
FT_BOOLEAN, 16, TFS(&mip6_ipv4dsm_s_flag_value), 0x0001,
NULL, HFILL }
},
{ &hf_mip6_cr_reserved,
{ "Reserved", "mip6.cr.reserved",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_cr_req_type,
{ "Req-type", "mip6.cr.req_type",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &mip6_mobility_options_ext, 0,
NULL, HFILL }
},
{ &hf_mip6_cr_req_length,
{ "Req-length", "mip6.cr.req_length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_lmaa_opt_code,
{ "Option-Code", "mip6.lmaa.opt_code",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_lmaa_reserved,
{ "Reserved", "mip6.lmaa.reserved",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_lmaa_ipv4,
{ "Local Mobility Anchor Address", "mip6.lmaa.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_lmaa_ipv6,
{ "Local Mobility Anchor Address", "mip6.lmaa.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_mobility,
{ "Mobility", "mip6.mobility",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_mobility_opt,
{ "Mobility Option", "mip6.mobility_opt",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &mip6_mobility_options_ext, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_len,
{ "Length", "mip6.mobility_opt.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_pmip6_bri_brtype,
{ "B.R. Type", "mip6.bri_br.type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pmip6_bri_rtrigger,
{ "R. Trigger", "mip6.bri_r.trigger",
FT_UINT8, BASE_DEC, VALS(pmip6_bri_rtrigger), 0x0,
NULL, HFILL }
},
{ &hf_pmip6_bri_status,
{ "Status", "mip6.bri_status",
FT_UINT8, BASE_DEC, VALS(pmip6_bri_status), 0x0,
NULL, HFILL }
},
{ &hf_pmip6_bri_seqnr,
{ "Sequence Number", "mip6.bri_seqnr",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pmip6_bri_ip_flag,
{ "Proxy Binding (P) Flag", "mip6.bri_ip",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x8000,
NULL, HFILL }
},
{ &hf_pmip6_bri_iv_flag,
{ "IPv4 HoA Binding Only (V) Flag", "mip6.bri_iv",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x4000,
NULL, HFILL }
},
{ &hf_pmip6_bri_ig_flag,
{ "Global (G) Flag", "mip6.bri_ig",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x2000,
NULL, HFILL }
},
{ &hf_pmip6_bri_ap_flag,
{ "Proxy Binding (P) Flag", "mip6.bri_ap",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x8000,
NULL, HFILL }
},
{ &hf_pmip6_bri_av_flag,
{ "IPv4 HoA Binding Only (V) Flag", "mip6.bri_av",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x4000,
NULL, HFILL }
},
{ &hf_pmip6_bri_ag_flag,
{ "Global (G) Flag", "mip6.bri_ag",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x2000,
NULL, HFILL }
},
{ &hf_pmip6_bri_res,
{ "Reserved", "mip6.bri_res",
FT_UINT16, BASE_HEX, NULL, 0x1FFF,
"Must be zero", HFILL }
},
{ &hf_pmip6_lri_sequence,
{ "Sequence", "mip6.lri.sequence",
FT_UINT16, BASE_DEC, NULL, 0x0,
"A monotonically increasing integer", HFILL }
},
{ &hf_pmip6_lri_reserved,
{ "Reserved", "mip6.lri.reserved",
FT_UINT16, BASE_HEX, NULL, 0x0,
"This field is unused and MUST be set to zero", HFILL }
},
{ &hf_pmip6_lri_lifetime,
{ "Lifetime", "mip6.lri.lifetime",
FT_UINT16, BASE_HEX, NULL, 0x0,
"The requested time, in seconds", HFILL }
},
{ &hf_pmip6_lra_sequence,
{ "Sequence", "mip6.lra.sequence",
FT_UINT16, BASE_DEC, NULL, 0x0,
"A monotonically increasing integer", HFILL }
},
{ &hf_pmip6_lra_u,
{ "unsolicited", "mip6.lri.reserved",
FT_BOOLEAN, 8, NULL, 0x80,
"This field is unused and MUST be set to zero", HFILL }
},
{ &hf_pmip6_lra_reserved,
{ "Reserved", "mip6.lra.reserved",
FT_UINT8, BASE_HEX, NULL, 0x7F,
"This field is unused and MUST be set to zero", HFILL }
},
{ &hf_pmip6_lra_status,
{ "Status", "mip6.lra.status",
FT_UINT8, BASE_DEC, VALS(pmip6_lra_status_vals), 0x0,
"Indicating the result ofprocessing the Localized Routing Acknowledgment message.", HFILL }
},
{ &hf_pmip6_lra_lifetime,
{ "Lifetime", "mip6.lra.lifetime",
FT_UINT16, BASE_HEX, NULL, 0x0,
"The requested time, in seconds", HFILL }
},
{ &hf_mip6_opt_recap_reserved,
{ "Reserved", "mip6.recap.reserved",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Must be zero", HFILL }
},
{ &hf_mip6_opt_redir_k,
{ "K", "mip6.redir.k",
FT_BOOLEAN, 16, NULL, MIP6_REDIR_FLAG_K,
"bit is set (1) if the Optional IPv6 r2LMA Address is included in the mobility option", HFILL }
},
{ &hf_mip6_opt_redir_n,
{ "N", "mip6.redir.n",
FT_BOOLEAN, 16, NULL, MIP6_REDIR_FLAG_N,
"bit is set (1) if the Optional IPv4 r2LMA Address is included in the mobility option", HFILL }
},
{ &hf_mip6_opt_redir_reserved,
{ "Reserved", "mip6.redir.reserved",
FT_UINT16, BASE_HEX, NULL, MIP6_REDIR_FLAG_RSV,
"Must be zero", HFILL }
},
{ &hf_mip6_opt_redir_addr_r2LMA_ipv6,
{ "IPv6 r2LMA Address", "mip6.redir.addr_r2lma_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_redir_addr_r2LMA_ipv4,
{ "IPv4 r2LMA Address", "mip6.redir.addr_r2lma_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_load_inf_priority,
{ "Priority", "mip6.load_inf.priority",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_load_inf_sessions_in_use,
{ "Sessions in Use", "mip6.load_inf.sessions_in_use",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_load_inf_maximum_sessions,
{ "Maximum Sessions", "mip6.load_inf.maximum_sessions",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_load_inf_used_capacity,
{ "Used Capacity", "mip6.load_inf.used_capacity",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_load_inf_maximum_capacity,
{ "Maximum Capacity", "mip6.load_inf.maximum_capacity",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_alt_ip4,
{ "Alternate IPv4 Care-of Address", "mip6.alt_ip4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_mng_sub_type,
{ "Sub Type", "mip6.mng.sub_type",
FT_UINT8, BASE_DEC, VALS(mip6_mng_id_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_mng_reserved,
{ "Reserved", "mip6.mng.reserved",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_mng_mng_id,
{ "Mobile Node Group Identifier", "mip6.mng.mng_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_mag_ipv6_reserved,
{ "Reserved", "mip6.mag_ipv6.reserved",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_mag_ipv6_address_length,
{ "Address Length", "mip6.mag_ipv6.address_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"This field MUST be set to 128", HFILL }
},
{ &hf_mip6_opt_mag_ipv6_address,
{ "Address", "mip6.mag_ipv6.address",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_acc_net_id_sub,
{ "ANI", "mip6.acc_net_id",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_acc_net_id_sub_opt,
{ "ANI Type", "mip6.acc_net_id.ani",
FT_UINT8, BASE_DEC, VALS(mmip6_opt_acc_net_id_sub_opt_vals), 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_acc_net_id_sub_opt_len,
{ "Length", "mip6.acc_net_id.sub_opt_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_acc_net_id_sub_opt_e_bit,
{ "E(Encoding)", "mip6.acc_net_id.e_bit",
FT_BOOLEAN, 8, TFS(&mip6_opt_acc_net_id_sub_opt_e_bit_value), 0x80,
NULL, HFILL }
},
{ &hf_mip6_opt_acc_net_id_sub_opt_net_name_len,
{ "Net-Name Length", "mip6.acc_net_id.net_name_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_acc_net_id_sub_opt_net_name,
{ "Network Name", "mip6.acc_net_id.net_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_acc_net_id_sub_opt_net_name_data,
{ "Network Name", "mip6.acc_net_id.net_name_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Network Name with undefined format", HFILL }
},
{ &hf_mip6_opt_acc_net_id_sub_opt_ap_name_len,
{ "AP-Name Length", "mip6.acc_net_id.ap_name_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_acc_net_id_sub_opt_ap_name,
{ "Access-Point Name", "mip6.acc_net_id.ap_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_acc_net_id_sub_opt_geo_latitude_degrees,
{ "Latitude Degrees", "mip6.acc_net_id.geo.latitude_degrees",
FT_INT24, BASE_CUSTOM, CF_FUNC(degrees_base_custom), 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_acc_net_id_sub_opt_geo_longitude_degrees,
{ "Longitude Degrees", "mip6.acc_net_id.geo.longitude_degrees",
FT_INT24, BASE_CUSTOM, CF_FUNC(degrees_base_custom), 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_acc_net_id_sub_opt_op_id_type,
{ "Op-ID Type", "mip6.acc_net_id.op_id.type",
FT_UINT8, BASE_DEC, VALS(mip6_opt_acc_net_id_sub_opt_op_id_type), 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_acc_net_id_sub_opt_op_id,
{ "Op-ID", "mip6.acc_net_id.op_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip6_opt_dmnp_v_flag,
{ "IPv4 Prefix (V) flag", "mip6.dmnp.v_flag",
FT_BOOLEAN, 8, TFS(&mip6_dmnp_v_flag_value), 0x80,
NULL, HFILL }
},
{ &hf_mip6_opt_dmnp_reserved,
{ "Reserved", "mip6.dmnp.reserved",
FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }
},
{ &hf_mip6_opt_dmnp_prefix_len,
{ "Prefix Length", "mip6.dmnp.prefix_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_dmnp_dmnp_ipv4,
{ "IPv4 Delegated Mobile Network Prefix", "mip6.dmnp.dmnp_ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip6_opt_dmnp_dmnp_ipv6,
{ "IPv6 Delegated Mobile Network Prefix", "mip6.dmnp.dmnp_ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_mip6,
&ett_mip6_opts,
&ett_mip6_opt_pad1,
&ett_mip6_opt_padn,
&ett_mip6_opt_bra,
&ett_mip6_opt_acoa,
&ett_mip6_opt_ni,
&ett_mip6_opt_bad,
&ett_fmip6_opt_lla,
&ett_mip6_nemo_opt_mnp,
&ett_mip6_opt_mnid,
&ett_mip6_opt_auth,
&ett_mip6_opt_mesgid,
&ett_mip6_opt_cgapr,
&ett_mip6_opt_cgar,
&ett_mip6_opt_sign,
&ett_mip6_opt_phkt,
&ett_mip6_opt_mocoti,
&ett_mip6_opt_mocot,
&ett_mip6_opt_dnsu,
&ett_mip6_opt_em,
&ett_mip6_opt_vsm,
&ett_mip6_opt_ssm,
&ett_mip6_opt_badff,
&ett_mip6_opt_unknown,
&ett_pmip6_opt_hnp,
&ett_pmip6_opt_hi,
&ett_pmip6_opt_att,
&ett_pmip6_opt_mnlli,
&ett_pmip6_opt_lla,
&ett_pmip6_opt_ts,
&ett_pmip6_opt_rc,
&ett_mip6_opt_ipv4ha,
&ett_mip6_opt_ipv4aa,
&ett_mip6_opt_natd,
&ett_mip6_opt_ipv4coa,
&ett_pmip6_opt_grek,
&ett_pmip6_opt_mhipv6ap,
&ett_pmip6_opt_bi,
&ett_mip6_opt_ipv4hareq,
&ett_mip6_opt_ipv4harep,
&ett_mip6_opt_ipv4dra,
&ett_mip6_opt_ipv4dsm,
&ett_mip6_opt_cr,
&ett_mip6_opt_lmaa,
&ett_mip6_opt_recap,
&ett_mip6_opt_redir,
&ett_mip6_opt_load_inf,
&ett_mip6_opt_alt_ip4,
&ett_mip6_opt_mng,
&ett_mip6_opt_mag_ipv6,
&ett_mip6_opt_acc_net_id,
&ett_mip6_sub_opt_acc_net_id,
&ett_mip6_opt_dmnp,
};
static ei_register_info ei[] = {
{ &ei_mip6_ie_not_dissected, { "mip6.ie_not_dissected", PI_UNDECODED, PI_NOTE, "IE data not dissected yet", EXPFILL }},
{ &ei_mip6_ani_type_not_dissected, { "mip6.acc_net_id.ani.unknown", PI_UNDECODED, PI_NOTE, "ANI Type not dissect yet", EXPFILL }},
{ &ei_mip6_opt_len_invalid, { "mip6.opt.len.invalid", PI_PROTOCOL, PI_WARN, "Invalid length for option", EXPFILL }},
{ &ei_mip6_vsm_data_not_dissected, { "mip6.vsm.data_not_dissected", PI_UNDECODED, PI_NOTE, "Data (Not dissected yet)", EXPFILL }},
{ &ei_mip6_bogus_header_length, { "mip6.bogus_header_length", PI_PROTOCOL, PI_WARN, "Bogus header length", EXPFILL }},
};
expert_module_t* expert_mip6;
proto_mip6 = proto_register_protocol("Mobile IPv6 / Network Mobility", "MIPv6", "mipv6");
proto_register_field_array(proto_mip6, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_mip6 = expert_register_protocol(proto_mip6);
expert_register_field_array(expert_mip6, ei, array_length(ei));
mip6_vsm_dissector_table = register_dissector_table("mip6.vsm", "Mobile IPv6 vendor specific option", FT_UINT32, BASE_DEC);
}
void
proto_reg_handoff_mip6(void)
{
dissector_handle_t mip6_handle;
mip6_handle = create_dissector_handle(dissect_mip6, proto_mip6);
dissector_add_uint("ip.proto", IP_PROTO_MIPV6_OLD, mip6_handle);
dissector_add_uint("ip.proto", IP_PROTO_MIPV6, mip6_handle);
dissector_add_uint("udp.port", UDP_PORT_PMIP6_CNTL, mip6_handle);
ip_dissector_table = find_dissector_table("ip.proto");
dissector_add_uint("mip6.vsm", VENDOR_THE3GPP, new_create_dissector_handle(dissect_mip6_opt_vsm_3gpp, proto_mip6));
}
