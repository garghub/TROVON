static int
dissect_mip6_brr(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo)
{
col_set_str(pinfo->cinfo, COL_INFO, "Binding Refresh Request");
if (mip6_tree) {
proto_tree_add_text(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_BRR_LEN, "Binding Refresh Request");
}
return MIP6_DATA_OFF + MIP6_BRR_LEN;
}
static int
dissect_mip6_hoti(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo)
{
proto_tree *data_tree = NULL;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_INFO, "Home Test Init");
if (mip6_tree) {
ti = proto_tree_add_text(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_HOTI_LEN, "Home Test Init");
data_tree = proto_item_add_subtree(ti, ett_mip6);
proto_tree_add_item(data_tree, hf_mip6_hoti_cookie, tvb,
MIP6_HOTI_COOKIE_OFF, MIP6_HOTI_COOKIE_LEN, ENC_BIG_ENDIAN);
}
return MIP6_DATA_OFF + MIP6_HOTI_LEN;
}
static int
dissect_mip6_coti(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo)
{
proto_tree *data_tree = NULL;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_INFO, "Care-of Test Init");
if (mip6_tree) {
ti = proto_tree_add_text(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_COTI_LEN, "Care-of Test Init");
data_tree = proto_item_add_subtree(ti, ett_mip6);
proto_tree_add_item(data_tree, hf_mip6_coti_cookie, tvb,
MIP6_COTI_COOKIE_OFF, MIP6_COTI_COOKIE_LEN, ENC_BIG_ENDIAN);
}
return MIP6_DATA_OFF + MIP6_COTI_LEN;
}
static int
dissect_mip6_hot(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo)
{
proto_tree *data_tree = NULL;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_INFO, "Home Test");
if (mip6_tree) {
ti = proto_tree_add_text(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_HOT_LEN, "Home Test");
data_tree = proto_item_add_subtree(ti, ett_mip6);
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
dissect_mip6_cot(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo)
{
proto_tree *data_tree = NULL;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_INFO, "Care-of Test");
if (mip6_tree) {
ti = proto_tree_add_text(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_COT_LEN, "Care-of Test");
data_tree = proto_item_add_subtree(ti, ett_mip6);
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
dissect_mip6_bu(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo)
{
proto_tree *data_tree = NULL;
proto_item *ti;
int lifetime;
col_set_str(pinfo->cinfo, COL_INFO, "Binding Update");
if (mip6_tree) {
ti = proto_tree_add_text(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_BU_LEN, "Binding Update");
data_tree = proto_item_add_subtree(ti, ett_mip6);
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
if ((tvb_get_guint8(tvb, MIP6_BU_FLAGS_OFF) & 0x0004 ) == 0x0004)
proto_nemo = 1;
lifetime = tvb_get_ntohs(tvb, MIP6_BU_LIFETIME_OFF);
proto_tree_add_uint_format(data_tree, hf_mip6_bu_lifetime, tvb,
MIP6_BU_LIFETIME_OFF,
MIP6_BU_LIFETIME_LEN, lifetime,
"Lifetime: %d (%ld seconds)",
lifetime, (long)lifetime * 4);
}
return MIP6_DATA_OFF + MIP6_BU_LEN;
}
static int
dissect_mip6_ba(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo)
{
proto_tree *data_tree = NULL;
proto_item *ti;
int lifetime;
col_set_str(pinfo->cinfo, COL_INFO, "Binding Acknowledgement");
if (mip6_tree) {
ti = proto_tree_add_text(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_BA_LEN, "Binding Acknowledgement");
data_tree = proto_item_add_subtree(ti, ett_mip6);
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
if ((tvb_get_guint8(tvb, MIP6_BA_FLAGS_OFF) & 0x0040 ) == 0x0040)
proto_nemo = 1;
proto_tree_add_item(data_tree, hf_mip6_ba_seqnr, tvb,
MIP6_BA_SEQNR_OFF, MIP6_BA_SEQNR_LEN, ENC_BIG_ENDIAN);
lifetime = tvb_get_ntohs(tvb, MIP6_BA_LIFETIME_OFF);
proto_tree_add_uint_format(data_tree, hf_mip6_ba_lifetime, tvb,
MIP6_BA_LIFETIME_OFF,
MIP6_BA_LIFETIME_LEN, lifetime,
"Lifetime: %d (%ld seconds)",
lifetime, (long)lifetime * 4);
}
return MIP6_DATA_OFF + MIP6_BA_LEN;
}
static int
dissect_mip6_be(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo)
{
proto_tree *data_tree = NULL;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_INFO, "Binding Error");
if (mip6_tree) {
ti = proto_tree_add_text(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_BE_LEN, "Binding Error");
data_tree = proto_item_add_subtree(ti, ett_mip6);
proto_tree_add_item(data_tree, hf_mip6_be_status, tvb,
MIP6_BE_STATUS_OFF, MIP6_BE_STATUS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_mip6_be_haddr, tvb,
MIP6_BE_HOA_OFF, MIP6_BE_HOA_LEN, ENC_NA);
}
return MIP6_DATA_OFF + MIP6_BE_LEN;
}
static int
dissect_mip6_hb(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo)
{
proto_tree *data_tree = NULL;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_INFO, "Heartbeat");
if (mip6_tree) {
ti = proto_tree_add_text(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_HB_LEN, "Heartbeat");
data_tree = proto_item_add_subtree(ti, ett_mip6);
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
dissect_mip6_unknown(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo)
{
col_set_str(pinfo->cinfo, COL_INFO, "Unknown MH Type");
if (mip6_tree) {
proto_tree_add_text(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_DATA_OFF + 1, "Unknown MH Type");
}
return MIP6_DATA_OFF + 1;
}
static int
dissect_fmip6_fbu(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo)
{
proto_tree *data_tree = NULL;
proto_item *ti;
int lifetime;
col_set_str(pinfo->cinfo, COL_INFO, "Fast Binding Update");
if (mip6_tree) {
ti = proto_tree_add_text(mip6_tree, tvb, MIP6_DATA_OFF,
MIP6_BU_LEN, "Fast Binding Update");
data_tree = proto_item_add_subtree(ti, ett_mip6);
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
proto_tree_add_uint_format(data_tree, hf_fmip6_fbu_lifetime, tvb,
FMIP6_FBU_LIFETIME_OFF,
FMIP6_FBU_LIFETIME_LEN, lifetime,
"Lifetime: %d (%ld seconds)",
lifetime, (long)lifetime * 4);
}
return MIP6_DATA_OFF + FMIP6_FBU_LEN;
}
static int
dissect_fmip6_fback(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo)
{
proto_tree *data_tree = NULL;
proto_item *ti;
int lifetime;
col_set_str(pinfo->cinfo, COL_INFO, "Fast Binding Acknowledgement");
if (mip6_tree) {
ti = proto_tree_add_text(mip6_tree, tvb, MIP6_DATA_OFF,
FMIP6_FBACK_LEN, "Fast Binding Acknowledgement");
data_tree = proto_item_add_subtree(ti, ett_mip6);
proto_tree_add_item(data_tree, hf_fmip6_fback_status, tvb,
FMIP6_FBACK_STATUS_OFF, FMIP6_FBACK_STATUS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_fmip6_fback_k_flag, tvb,
FMIP6_FBACK_FLAGS_OFF, FMIP6_FBACK_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(data_tree, hf_fmip6_fback_seqnr, tvb,
FMIP6_FBACK_SEQNR_OFF, FMIP6_FBACK_SEQNR_LEN, ENC_BIG_ENDIAN);
lifetime = tvb_get_ntohs(tvb, FMIP6_FBACK_LIFETIME_OFF);
proto_tree_add_uint_format(data_tree, hf_fmip6_fback_lifetime, tvb,
FMIP6_FBACK_LIFETIME_OFF,
FMIP6_FBACK_LIFETIME_LEN, lifetime,
"Lifetime: %d (%ld seconds)",
lifetime, (long)lifetime * 4);
}
return MIP6_DATA_OFF + FMIP6_FBACK_LEN;
}
static int
dissect_fmip6_fna(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo)
{
col_set_str(pinfo->cinfo, COL_INFO, "Fast Neighbor Advertisement");
if (mip6_tree) {
proto_tree_add_text(mip6_tree, tvb, MIP6_DATA_OFF,
FMIP6_FNA_LEN, "Fast Neighbor Advertisement");
}
return MIP6_DATA_OFF + FMIP6_FNA_LEN;
}
static int
dissect_pmip6_bri(tvbuff_t *tvb, proto_tree *mip6_tree, packet_info *pinfo)
{
#define INDICATION 1
#define ACKNOWLEDGE 2
proto_item *ti;
proto_tree *field_tree;
guint8 br_type;
br_type = tvb_get_guint8(tvb, PMIP6_BRI_BRTYPE_OFF);
if ( br_type == INDICATION )
{
col_set_str(pinfo->cinfo, COL_INFO, "Binding Revocation Indication");
if (mip6_tree)
{
ti = proto_tree_add_text(mip6_tree, tvb, MIP6_DATA_OFF,
PMIP6_BRI_LEN, "Binding Revocation Indication");
field_tree = proto_item_add_subtree(ti, ett_mip6);
proto_tree_add_item(field_tree, hf_pmip6_bri_brtype, tvb,
PMIP6_BRI_BRTYPE_OFF, PMIP6_BRI_BRTYPE_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_rtrigger, tvb,
PMIP6_BRI_RTRIGGER_OFF, PMIP6_BRI_RTRIGGER_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_seqnr, tvb,
PMIP6_BRI_SEQNR_OFF, PMIP6_BRI_SEQNR_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_ip_flag, tvb,
PMIP6_BRI_FLAGS_OFF, PMIP6_BRI_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_ia_flag, tvb,
PMIP6_BRI_FLAGS_OFF, PMIP6_BRI_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_ig_flag, tvb,
PMIP6_BRI_FLAGS_OFF, PMIP6_BRI_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_res, tvb,
PMIP6_BRI_RES_OFF, PMIP6_BRI_RES_LEN, ENC_BIG_ENDIAN);
}
} else if ( br_type == ACKNOWLEDGE ) {
if (check_col(pinfo->cinfo, COL_INFO))
col_set_str(pinfo->cinfo, COL_INFO, "Binding Revocation Acknowledge");
if (mip6_tree)
{
ti = proto_tree_add_text(mip6_tree, tvb, MIP6_DATA_OFF,
PMIP6_BRI_LEN, "Binding Revocation Acknowledge");
field_tree = proto_item_add_subtree(ti, ett_mip6);
proto_tree_add_item(field_tree, hf_pmip6_bri_brtype, tvb,
PMIP6_BRI_BRTYPE_OFF, PMIP6_BRI_BRTYPE_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_status, tvb,
PMIP6_BRI_STATUS_OFF, PMIP6_BRI_STATUS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_seqnr, tvb,
PMIP6_BRI_SEQNR_OFF, PMIP6_BRI_SEQNR_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_ap_flag, tvb,
PMIP6_BRI_FLAGS_OFF, PMIP6_BRI_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_ag_flag, tvb,
PMIP6_BRI_FLAGS_OFF, PMIP6_BRI_FLAGS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_pmip6_bri_res, tvb,
PMIP6_BRI_RES_OFF, PMIP6_BRI_RES_LEN, ENC_BIG_ENDIAN);
}
}
return MIP6_DATA_OFF + PMIP6_BRI_LEN;
}
static void
dissect_mip6_opt_padn(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_,
proto_tree *opt_tree)
{
proto_tree_add_text(opt_tree, tvb, offset, optlen,
"%s: %u bytes", optp->name, optlen);
}
static void
dissect_mip6_opt_bra(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_,
proto_tree *opt_tree)
{
int ri;
ri = tvb_get_ntohs(tvb, offset + MIP6_BRA_RI_OFF);
proto_tree_add_uint_format(opt_tree, hf_mip6_bra_interval, tvb,
offset, optlen,
ri, "Refresh interval: %d (%ld seconds)",
ri, (long)ri * 4);
}
static void
dissect_mip6_opt_acoa(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_,
proto_tree *opt_tree)
{
proto_tree_add_ipv6(opt_tree, hf_mip6_acoa_acoa, tvb, offset, optlen,
tvb_get_ptr(tvb, offset + MIP6_ACOA_ACOA_OFF, MIP6_ACOA_ACOA_LEN));
}
static void
dissect_mip6_nemo_opt_mnp(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_,
proto_tree *opt_tree)
{
proto_tree *field_tree = NULL;
proto_item *tf;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s", optp->name);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
proto_tree_add_item(field_tree, hf_mip6_nemo_mnp_pfl, tvb,
offset + MIP6_NEMO_MNP_PL_OFF, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mip6_nemo_mnp_mnp, tvb,
offset + MIP6_NEMO_MNP_MNP_OFF, MIP6_NEMO_MNP_MNP_LEN, ENC_NA);
}
static void
dissect_mip6_opt_ni(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_,
proto_tree *opt_tree)
{
proto_tree *field_tree = NULL;
proto_item *tf;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s", optp->name);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
proto_tree_add_item(field_tree, hf_mip6_ni_hni, tvb,
offset + MIP6_NI_HNI_OFF, MIP6_NI_HNI_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mip6_ni_cni, tvb,
offset + MIP6_NI_CNI_OFF, MIP6_NI_CNI_LEN, ENC_BIG_ENDIAN);
}
static void
dissect_mip6_opt_bad(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_,
proto_tree *opt_tree)
{
proto_tree *field_tree = NULL;
proto_item *tf;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s", optp->name);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
proto_tree_add_item(field_tree, hf_mip6_bad_auth, tvb,
offset + MIP6_BAD_AUTH_OFF,
optlen - MIP6_BAD_AUTH_OFF, ENC_NA);
}
static void
dissect_fmip6_opt_lla(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_,
proto_tree *opt_tree)
{
proto_tree *field_tree = NULL;
proto_item *tf;
int len, p;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s", optp->name);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
proto_tree_add_item(field_tree, hf_fmip6_lla_optcode, tvb,
offset + FMIP6_LLA_OPTCODE_OFF, FMIP6_LLA_OPTCODE_LEN, ENC_BIG_ENDIAN);
p = offset + FMIP6_LLA_LLA_OFF;
len = optlen - FMIP6_LLA_LLA_OFF;
if (len > 0) {
if (len > 1) {
p += 1;
len -= 1;
proto_tree_add_text(field_tree, tvb,
p, len, "Link-layer address: %s",
tvb_bytes_to_str_punct(tvb, p, len, ':'));
}
}
}
static void
dissect_mip6_opt_mnid(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree)
{
proto_tree *field_tree = NULL;
proto_item *tf;
int len, p;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s", optp->name);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
proto_tree_add_item(field_tree, hf_mip6_mnid_subtype, tvb,
offset + MIP6_MNID_SUBTYPE_OFF, MIP6_MNID_SUBTYPE_LEN, ENC_BIG_ENDIAN);
p = offset + MIP6_MNID_MNID_OFF;
len = optlen - MIP6_MNID_MNID_OFF;
if (len > 0)
proto_tree_add_text(field_tree, tvb, p, len, "Identifier: %s", tvb_format_text(tvb, p, len));
}
static void
dissect_mip6_opt_vsm(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree)
{
proto_tree *field_tree = NULL;
proto_item *tf;
int len, p;
guint32 vendorid;
int hf_mip6_vsm_subtype_local;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s", optp->name);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
proto_tree_add_item(field_tree, hf_mip6_vsm_vid, tvb,
offset + MIP6_VSM_VID_OFF, MIP6_VSM_VID_LEN, ENC_BIG_ENDIAN);
vendorid = tvb_get_ntohl(tvb, offset+MIP6_VSM_VID_OFF);
switch (vendorid) {
case VENDOR_THE3GPP:
hf_mip6_vsm_subtype_local = hf_mip6_vsm_subtype_3gpp;
break;
default:
hf_mip6_vsm_subtype_local = hf_mip6_vsm_subtype;
break;
}
proto_tree_add_item(field_tree, hf_mip6_vsm_subtype_local, tvb,
offset + MIP6_VSM_SUBTYPE_OFF, MIP6_VSM_SUBTYPE_LEN, ENC_BIG_ENDIAN);
p = offset + MIP6_VSM_DATA_OFF;
len = optlen - MIP6_VSM_DATA_OFF;
if (len > 0)
proto_tree_add_text(field_tree, tvb, p, len, "Data");
}
static void
dissect_mip6_opt_ssm(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree)
{
int len, p;
p = offset + MIP6_SSM_SSM_OFF;
len = optlen - MIP6_SSM_SSM_OFF;
if (len > 0)
proto_tree_add_text(opt_tree, tvb, p, len, "Identifier: %s", tvb_format_text(tvb, p, len));
}
static void
dissect_pmip6_opt_hi(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree)
{
proto_tree_add_item(opt_tree, hf_pmip6_hi_opttype, tvb,
offset + PMIP6_HI_HI_OFF, PMIP6_HI_HI_LEN, ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_att(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree)
{
proto_tree_add_item(opt_tree, hf_pmip6_att_opttype, tvb,
offset + PMIP6_ATT_ATT_OFF, PMIP6_ATT_ATT_LEN, ENC_BIG_ENDIAN);
}
static void dissect_pmip6_opt_lla(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree)
{
proto_item *ti;
proto_tree *field_tree;
if (opt_tree){
ti = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s", optp->name);
field_tree = proto_item_add_subtree(ti, *optp->subtree_index);
proto_tree_add_item(field_tree, hf_pmip6_opt_lila_lla, tvb, offset + 2, 16, ENC_NA);
}
}
static void
dissect_pmip6_opt_ts(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree)
{
proto_tree_add_item(opt_tree, hf_pmip6_timestamp, tvb, offset+2, 8,
ENC_TIME_NTP|ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_rc(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree)
{
proto_tree_add_item(opt_tree, hf_pmip6_rc, tvb,
offset + PMIP6_RC_RC_OFF, PMIP6_RC_RC_LEN, ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_ipv4ha(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree)
{
proto_tree *field_tree = NULL;
proto_item *tf;
int len, p;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s", optp->name);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
p = offset + MIP6_IPV4HA_PREFIXL_OFF;
len = MIP6_IPV4HA_PREFIXL_LEN;
proto_tree_add_item(field_tree, hf_mip6_ipv4ha_preflen, tvb, p, len, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mip6_ipv4ha_p_flag, tvb, p, len+1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mip6_ipv4ha_ha, tvb,
offset + MIP6_IPV4HA_HA_OFF, MIP6_IPV4HA_HA_LEN, ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_ipv4aa(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree)
{
proto_tree *field_tree = NULL;
proto_item *tf;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s", optp->name);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
proto_tree_add_item(field_tree, hf_mip6_ipv4aa_status, tvb,
offset + MIP6_IPV4AA_STATUS_OFF, MIP6_IPV4AA_STATUS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mip6_ipv4ha_preflen, tvb,
offset + MIP6_IPV4AA_PREFIXL_OFF, MIP6_IPV4AA_PREFIXL_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mip6_ipv4ha_ha, tvb,
offset + MIP6_IPV4AA_HA_OFF, MIP6_IPV4AA_HA_LEN, ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_grek(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_, proto_tree *opt_tree)
{
proto_tree_add_item(opt_tree, hf_pmip6_gre_key, tvb,
offset + PMIP6_GREK_ID_OFF, PMIP6_GREK_ID_LEN, ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_ipv4hareq(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree)
{
proto_tree *field_tree = NULL;
proto_item *tf;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s", optp->name);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
proto_tree_add_item(field_tree, hf_mip6_ipv4ha_preflen, tvb,
offset + MIP6_IPV4HAREQ_PREFIXL_OFF, MIP6_IPV4HAREQ_PREFIXL_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mip6_ipv4ha_ha, tvb,
offset + MIP6_IPV4HAREQ_HA_OFF, MIP6_IPV4HAREQ_HA_LEN, ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_ipv4harep(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree)
{
proto_tree *field_tree = NULL;
proto_item *tf;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s", optp->name);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
proto_tree_add_item(field_tree, hf_mip6_ipv4aa_status, tvb,
offset + MIP6_IPV4HAREP_STATUS_OFF, MIP6_IPV4HAREP_STATUS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mip6_ipv4ha_preflen, tvb,
offset + MIP6_IPV4HAREP_PREFIXL_OFF, MIP6_IPV4HAREP_PREFIXL_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mip6_ipv4ha_ha, tvb,
offset + MIP6_IPV4HAREP_HA_OFF, MIP6_IPV4HAREP_HA_LEN, ENC_BIG_ENDIAN);
}
static void
dissect_pmip6_opt_ipv4dra(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree)
{
proto_tree *field_tree = NULL;
proto_item *tf;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s", optp->name);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
proto_tree_add_item(field_tree, hf_mip6_ipv4dra_dra, tvb,
offset + MIP6_IPV4DRA_DRA_OFF, MIP6_IPV4DRA_DRA_LEN, ENC_BIG_ENDIAN);
}
static void
dissect_mipv6_options(tvbuff_t *tvb, int offset, guint length,
const ip_tcp_opt *opttab, int nopts, int eol,
packet_info *pinfo, proto_tree *opt_tree)
{
proto_item *ti;
guchar opt;
const ip_tcp_opt *optp;
opt_len_type len_type;
unsigned int optlen;
const char *name;
char name_str[7+1+1+2+2+1+1];
void (*dissect)(const struct ip_tcp_opt *, tvbuff_t *,
int, guint, packet_info *, proto_tree *);
guint len;
while (length > 0) {
opt = tvb_get_guint8(tvb, offset);
for (optp = &opttab[0]; optp < &opttab[nopts]; optp++) {
if (optp->optcode == opt)
break;
}
if (optp == &opttab[nopts]) {
optp = NULL;
len_type = VARIABLE_LENGTH;
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
if (len_type != NO_LENGTH) {
if (length == 0) {
proto_tree_add_text(opt_tree, tvb, offset, 1,
"%s (length byte past end of options)", name);
return;
}
len = tvb_get_guint8(tvb, offset + 1);
--length;
if (len > length) {
proto_tree_add_text(opt_tree, tvb, offset, length,
"%s (option length = %u byte%s says option goes past end of options)",
name, len, plurality(len, "", "s"));
return;
} else if (len_type == FIXED_LENGTH && len != optlen) {
proto_tree_add_text(opt_tree, tvb, offset, len + 2,
"%s (with option length = %u byte%s; should be %u)", name,
len, plurality(len, "", "s"), optlen);
return;
} else if (len_type == VARIABLE_LENGTH && len < optlen) {
proto_tree_add_text(opt_tree, tvb, offset, len + 2,
"%s (with option length = %u byte%s; should be >= %u)", name,
len, plurality(len, "", "s"), optlen);
return;
} else {
ti = proto_tree_add_item(opt_tree, hf_mip6_mobility_opt, tvb, offset, 1, ENC_BIG_ENDIAN);
if (optp == NULL) {
proto_item *expert_item;
proto_item_append_text(ti, "(%u byte%s)",len, plurality(len, "", "s"));
expert_item = proto_tree_add_text(opt_tree, tvb, offset+2, len, "IE data not dissected yet");
expert_add_info_format(pinfo, expert_item, PI_PROTOCOL, PI_NOTE, "IE data not dissected yet");
PROTO_ITEM_SET_GENERATED(expert_item);
} else {
if (dissect != NULL) {
if (opt == MIP6_MHLLA)
(*dissect)(optp, tvb, offset,
len + 2 + FMIP6_LLA_OPTCODE_LEN, pinfo, opt_tree);
else
(*dissect)(optp, tvb, offset, len + 2, pinfo, opt_tree);
}
}
if (opt == MIP6_MHLLA)
offset += len + 2 + FMIP6_LLA_OPTCODE_LEN;
else
offset += len + 2;
}
if (opt == MIP6_MHLLA)
length -= (len + FMIP6_LLA_OPTCODE_LEN);
else
length -= len;
} else {
proto_tree_add_text(opt_tree, tvb, offset, 1, "%s", name);
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
proto_tree *opts_tree = NULL;
proto_item *ti;
if (!mip6_tree)
return len;
ti = proto_tree_add_text(mip6_tree, tvb, offset, len, "Mobility Options");
opts_tree = proto_item_add_subtree(ti, ett_mip6);
dissect_mipv6_options(tvb, offset, len, mip6_opts, N_MIP6_OPTS, -1, pinfo, opts_tree);
return len;
}
static void
dissect_mip6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *mip6_tree = NULL;
proto_item *ti;
guint8 type, pproto;
guint len, offset = 0, start_offset = offset;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MIPv6");
col_clear(pinfo->cinfo, COL_INFO);
len = (tvb_get_guint8(tvb, MIP6_HLEN_OFF) + 1) * 8;
pproto = tvb_get_guint8(tvb, MIP6_PROTO_OFF);
if (tree) {
ti = proto_tree_add_item(tree, proto_mip6, tvb, 0, len, ENC_NA);
mip6_tree = proto_item_add_subtree(ti, ett_mip6);
proto_tree_add_uint_format(mip6_tree, hf_mip6_proto, tvb,
MIP6_PROTO_OFF, 1,
tvb_get_guint8(tvb, MIP6_PROTO_OFF),
"Payload protocol: %s (0x%02x)",
ipprotostr(
tvb_get_guint8(tvb, MIP6_PROTO_OFF)),
tvb_get_guint8(tvb, MIP6_PROTO_OFF));
proto_tree_add_uint_format(mip6_tree, hf_mip6_hlen, tvb,
MIP6_HLEN_OFF, 1,
tvb_get_guint8(tvb, MIP6_HLEN_OFF),
"Header length: %u (%u bytes)",
tvb_get_guint8(tvb, MIP6_HLEN_OFF),
len);
proto_tree_add_item(mip6_tree, hf_mip6_mhtype, tvb,
MIP6_TYPE_OFF, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mip6_tree, hf_mip6_reserved, tvb,
MIP6_RES_OFF, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mip6_tree, hf_mip6_csum, tvb,
MIP6_CSUM_OFF, 2, ENC_BIG_ENDIAN);
}
type = tvb_get_guint8(tvb, MIP6_TYPE_OFF);
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
offset = dissect_mip6_bu(tvb, mip6_tree, pinfo);
if (proto_nemo == 1) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NEMO");
}
break;
case MIP6_BA:
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
case MIP6_HB:
offset = dissect_mip6_hb(tvb, mip6_tree, pinfo);
break;
case MIP6_BR:
offset = dissect_pmip6_bri(tvb, mip6_tree, pinfo);
break;
default:
dissect_mip6_unknown(tvb, mip6_tree, pinfo);
offset = len;
break;
}
if (offset < len) {
if (len < (offset - start_offset)) {
proto_tree_add_text(tree, tvb, 0, 0, "Bogus header length");
return;
}
len -= (offset - start_offset);
dissect_mip6_options(tvb, mip6_tree, offset, len, pinfo);
}
if (type == MIP6_FNA && pproto == IP_PROTO_IPV6) {
tvbuff_t *ipv6_tvb;
ipv6_tvb = tvb_new_subset_remaining(tvb, len + 8);
dissector_try_uint(ip_dissector_table, pproto, ipv6_tvb, pinfo, tree);
col_set_str(pinfo->cinfo, COL_INFO, "Fast Neighbor Advertisement[Fast Binding Update]");
}
}
void
proto_register_mip6(void)
{
static hf_register_info hf[] = {
{ &hf_mip6_proto, { "Payload protocol", "mip6.proto",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_hlen, { "Header length", "mip6.hlen",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_mhtype, { "Mobility Header Type", "mip6.mhtype",
FT_UINT8, BASE_DEC, VALS(mip6_mh_types), 0,
NULL, HFILL }},
{ &hf_mip6_reserved, { "Reserved", "mip6.reserved",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_csum, { "Checksum", "mip6.csum",
FT_UINT16, BASE_HEX, NULL, 0,
"Header Checksum", HFILL }},
{ &hf_mip6_hoti_cookie, { "Home Init Cookie", "mip6.hoti.cookie",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_coti_cookie, { "Care-of Init Cookie", "mip6.coti.cookie",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_hot_nindex, { "Home Nonce Index", "mip6.hot.nindex",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_hot_cookie, { "Home Init Cookie", "mip6.hot.cookie",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_hot_token, { "Home Keygen Token", "mip6.hot.token",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_cot_nindex, { "Care-of Nonce Index", "mip6.cot.nindex",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_cot_cookie, { "Care-of Init Cookie", "mip6.cot.cookie",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_cot_token, { "Care-of Keygen Token", "mip6.cot.token",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_bu_seqnr, { "Sequence number", "mip6.bu.seqnr",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_bu_a_flag, { "Acknowledge (A) flag", "mip6.bu.a_flag",
FT_BOOLEAN, 16, TFS(&mip6_bu_a_flag_value),
0x8000, NULL, HFILL }},
{ &hf_mip6_bu_h_flag, { "Home Registration (H) flag",
"mip6.bu.h_flag",
FT_BOOLEAN, 16, TFS(&mip6_bu_h_flag_value),
0x4000, NULL, HFILL }},
{ &hf_mip6_bu_l_flag, { "Link-Local Compatibility (L) flag",
"mip6.bu.l_flag",
FT_BOOLEAN, 16, TFS(&mip6_bu_l_flag_value),
0x2000, "Home Registration (H) flag", HFILL }},
{ &hf_mip6_bu_k_flag, { "Key Management Compatibility (K) flag",
"mip6.bu.k_flag",
FT_BOOLEAN, 16, TFS(&mip6_bu_k_flag_value),
0x1000, NULL,
HFILL }},
{ &hf_mip6_bu_m_flag, { "MAP Registration Compatibility (M) flag",
"mip6.bu.m_flag",
FT_BOOLEAN, 16, TFS(&mip6_bu_m_flag_value),
0x0800, NULL,
HFILL }},
{ &hf_mip6_nemo_bu_r_flag, { "Mobile Router (R) flag",
"mip6.nemo.bu.r_flag",
FT_BOOLEAN, 16, TFS(&mip6_nemo_bu_r_flag_value),
0x0400, NULL,
HFILL }},
{ &hf_pmip6_bu_p_flag, { "Proxy Registration (P) flag",
"mip6.bu.p_flag",
FT_BOOLEAN, 16, TFS(&pmip6_bu_p_flag_value),
0x0200, NULL,
HFILL }},
{ &hf_mip6_bu_f_flag, { "Forcing UDP encapsulation (F) flag",
"mip6.bu.f_flag",
FT_BOOLEAN, 16, TFS(&mip6_bu_f_flag_value),
0x0100, NULL,
HFILL }},
{ &hf_pmip6_bu_t_flag, { "TLV-header format (T) flag",
"mip6.bu.t_flag",
FT_BOOLEAN, 16, TFS(&pmip6_bu_t_flag_value),
0x0080, NULL,
HFILL }},
{ &hf_mip6_bu_lifetime, { "Lifetime", "mip6.bu.lifetime",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_ba_status, { "Status", "mip6.ba.status",
FT_UINT8, BASE_DEC,
VALS(mip6_ba_status_value), 0,
"Binding Acknowledgement status", HFILL }},
{ &hf_mip6_ba_k_flag, { "Key Management Compatibility (K) flag",
"mip6.ba.k_flag",
FT_BOOLEAN, 8, TFS(&mip6_bu_k_flag_value),
0x80, NULL,
HFILL }},
{ &hf_mip6_nemo_ba_r_flag, { "Mobile Router (R) flag",
"mip6.nemo.ba.r_flag",
FT_BOOLEAN, 8, TFS(&mip6_nemo_bu_r_flag_value),
0x40, NULL,
HFILL }},
{ &hf_pmip6_ba_p_flag, { "Proxy Registration (P) flag",
"mip6.ba.p_flag",
FT_BOOLEAN, 8, TFS(&pmip6_bu_p_flag_value),
0x20, NULL,
HFILL }},
{ &hf_pmip6_ba_t_flag, { "TLV-header format (T) flag",
"mip6.ba.t_flag",
FT_BOOLEAN, 8, TFS(&pmip6_bu_t_flag_value),
0x10, NULL,
HFILL }},
{ &hf_mip6_ba_seqnr, { "Sequence number", "mip6.ba.seqnr",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_ba_lifetime, { "Lifetime", "mip6.ba.lifetime",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_be_status, { "Status", "mip6.be.status",
FT_UINT8, BASE_DEC,
VALS(mip6_be_status_value), 0,
"Binding Error status", HFILL }},
{ &hf_mip6_be_haddr, { "Home Address", "mip6.be.haddr",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_fmip6_fbu_seqnr, { "Sequence number", "fmip6.fbu.seqnr",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_fmip6_fbu_a_flag, { "Acknowledge (A) flag", "fmip6.fbu.a_flag",
FT_BOOLEAN, 8, TFS(&fmip6_fbu_a_flag_value),
0x80, NULL, HFILL }},
{ &hf_fmip6_fbu_h_flag, { "Home Registration (H) flag",
"fmip6.fbu.h_flag",
FT_BOOLEAN, 8, TFS(&fmip6_fbu_h_flag_value),
0x40, NULL, HFILL }},
{ &hf_fmip6_fbu_l_flag, { "Link-Local Compatibility (L) flag",
"fmip6.fbu.l_flag",
FT_BOOLEAN, 8, TFS(&fmip6_fbu_l_flag_value),
0x20, "Home Registration (H) flag", HFILL }},
{ &hf_fmip6_fbu_k_flag, { "Key Management Compatibility (K) flag",
"fmip6.fbu.k_flag",
FT_BOOLEAN, 8, TFS(&fmip6_fbu_k_flag_value),
0x10, NULL,
HFILL }},
{ &hf_fmip6_fbu_lifetime, { "Lifetime", "fmip6.fbu.lifetime",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_fmip6_fback_status, { "Status", "fmip6.fback.status",
FT_UINT8, BASE_DEC,
VALS(fmip6_fback_status_value), 0,
"Fast Binding Acknowledgement status", HFILL }},
{ &hf_fmip6_fback_k_flag, { "Key Management Compatibility (K) flag",
"fmip6.fback.k_flag",
FT_BOOLEAN, 8, TFS(&fmip6_fbu_k_flag_value),
0x80, NULL,
HFILL }},
{ &hf_fmip6_fback_seqnr, { "Sequence number", "fmip6.fback.seqnr",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_fmip6_fback_lifetime, { "Lifetime", "fmip6.fback.lifetime",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_hb_u_flag, { "Unsolicited (U) flag", "mip6.hb.u_flag",
FT_BOOLEAN, 8, TFS(&mip6_hb_u_flag_value),
0x02, NULL, HFILL }},
{ &hf_mip6_hb_r_flag, { "Response (R) flag", "mip6.hb.r_flag",
FT_BOOLEAN, 8, TFS(&mip6_hb_r_flag_value),
0x01, NULL, HFILL }},
{ &hf_mip6_hb_seqnr, { "Sequence number", "mip6.hb.seqnr",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_bra_interval, { "Refresh interval", "mip6.bra.interval",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_acoa_acoa, { "Alternate care-of address", "mip6.acoa.acoa",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_ni_hni, { "Home nonce index", "mip6.ni.hni",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_ni_cni, { "Care-of nonce index", "mip6.ni.cni",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_bad_auth, { "Authenticator", "mip6.bad.auth",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_fmip6_lla_optcode, { "Option-Code", "mip6.lla.optcode",
FT_UINT8, BASE_DEC, VALS(fmip6_lla_optcode_value), 0,
NULL, HFILL }},
{ &hf_mip6_nemo_mnp_pfl, { "Mobile Network Prefix Length", "mip6.nemo.mnp.pfl",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_nemo_mnp_mnp, { "Mobile Network Prefix", "mip6.nemo.mnp.mnp",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mip6_mnid_subtype, { "Subtype", "mip6.mnid.subtype",
FT_UINT8, BASE_DEC, VALS(mip6_mnid_subtype_value), 0,
NULL, HFILL }},
{ &hf_mip6_vsm_vid, { "VendorId", "mip6.vsm.vendorId",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0x0,
NULL, HFILL }},
{ &hf_mip6_vsm_subtype, { "Subtype", "mip6.vsm.subtype",
FT_UINT8, BASE_DEC, VALS(mip6_vsm_subtype_value), 0,
NULL, HFILL }},
{ &hf_mip6_vsm_subtype_3gpp, { "Subtype", "mip6.vsm.subtype",
FT_UINT8, BASE_DEC, VALS(mip6_vsm_subtype_3gpp_value), 0,
NULL, HFILL }},
{ &hf_pmip6_hi_opttype, { "Handoff Indicator Option type", "mip6.hi",
FT_UINT8, BASE_DEC, VALS(pmip6_hi_opttype_value), 0,
NULL, HFILL }},
{ &hf_pmip6_att_opttype, { "Access Technology Type Option type", "mip6.att",
FT_UINT8, BASE_DEC, VALS(pmip6_att_opttype_value), 0,
NULL, HFILL }},
{ &hf_pmip6_timestamp, { "Timestamp", "mip6.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }},
{ &hf_pmip6_opt_lila_lla, { "Link-local Address", "mip6.lila_lla",
FT_IPv6, BASE_NONE, NULL, 0x0, "", HFILL }},
{ &hf_pmip6_rc, { "Restart Counter", "mip6.rc",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_mip6_ipv4ha_preflen, { "Prefix-len", "mip6.ipv4ha.preflen",
FT_UINT8, BASE_DEC, NULL, 0xfc,
NULL, HFILL}},
{ &hf_mip6_ipv4ha_p_flag, { "mobile network prefix (P) flag", "mip6.ipv4ha.p_flag",
FT_BOOLEAN, 16, TFS(&mip6_ipv4ha_p_flag_value), 0x0200,
NULL, HFILL }},
{ &hf_mip6_ipv4ha_ha, { "IPv4 Home Address", "mip6.ipv4ha.ha",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mip6_ipv4aa_status, { "Status", "mip6.ipv4aa.sts",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_pmip6_gre_key, { "GRE Key", "mip6.gre_key",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_mip6_ipv4dra_dra, { "IPv4 Default-Router Address", "mip6.ipv4dra.dra",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mip6_mobility_opt, { "Mobility Options", "mip6.mobility_opt",
FT_UINT8, BASE_DEC, VALS(mip6_mobility_options), 0,
NULL, HFILL }},
{ &hf_pmip6_bri_brtype, { "B.R. Type", "mip6.bri_br.type",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pmip6_bri_rtrigger, { "R. Trigger", "mip6.bri_r.trigger",
FT_UINT8, BASE_DEC, VALS(pmip6_bri_rtrigger), 0x0, NULL, HFILL }},
{ &hf_pmip6_bri_status, { "Status", "mip6.bri_status",
FT_UINT8, BASE_DEC, VALS(pmip6_bri_status), 0x0, NULL, HFILL }},
{ &hf_pmip6_bri_seqnr, { "Sequence Number", "mip6._bri_seqnr",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pmip6_bri_ip_flag, { "Proxy Binding (P) Flag", "mip6.bri_ip",
FT_BOOLEAN, 8, TFS(&tfs_set_notset),
0x80, NULL, HFILL }},
{ &hf_pmip6_bri_ia_flag, { "Acknowledge (A) Flag", "mip6.bri_ia",
FT_BOOLEAN, 8, TFS(&tfs_set_notset),
0x40, NULL, HFILL }},
{ &hf_pmip6_bri_ig_flag, { "Global (G) Flag", "mip6.bri_ig",
FT_BOOLEAN, 8, TFS(&tfs_set_notset),
0x20, NULL, HFILL }},
{ &hf_pmip6_bri_ap_flag, { "Proxy Binding (P) Flag", "mip6.bri_ap",
FT_BOOLEAN, 8, TFS(&tfs_set_notset),
0x80, NULL, HFILL }},
{ &hf_pmip6_bri_ag_flag, { "Global (G) Flag", "mip6.bri_ag",
FT_BOOLEAN, 8, TFS(&tfs_set_notset),
0x40, NULL, HFILL }},
{ &hf_pmip6_bri_res, { "Reserved: 1 byte", "mip6.bri_res",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_mip6,
&ett_mip6_opt_padn,
&ett_mip6_opt_bra,
&ett_mip6_opt_acoa,
&ett_mip6_opt_ni,
&ett_mip6_opt_bad,
&ett_fmip6_opt_lla,
&ett_mip6_nemo_opt_mnp,
&ett_mip6_opt_mnid,
&ett_mip6_opt_vsm,
&ett_mip6_opt_ssm,
&ett_pmip6_opt_hnp,
&ett_pmip6_opt_hi,
&ett_pmip6_opt_att,
&ett_pmip6_opt_lla,
&ett_pmip6_opt_ts,
&ett_pmip6_opt_rc,
&ett_mip6_opt_ipv4ha,
&ett_mip6_opt_ipv4aa,
&ett_pmip6_opt_grek,
&ett_mip6_opt_ipv4hareq,
&ett_mip6_opt_ipv4harep,
&ett_mip6_opt_ipv4dra,
};
proto_mip6 = proto_register_protocol("Mobile IPv6 / Network Mobility", "MIPv6", "mipv6");
proto_register_field_array(proto_mip6, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mip6(void)
{
dissector_handle_t mip6_handle;
mip6_handle = create_dissector_handle(dissect_mip6, proto_mip6);
dissector_add_uint("ip.proto", IP_PROTO_MIPV6_OLD, mip6_handle);
dissector_add_uint("ip.proto", IP_PROTO_MIPV6, mip6_handle);
ip_dissector_table = find_dissector_table("ip.proto");
}
