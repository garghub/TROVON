static int
dissect_rsl_ie_ch_no(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_CH_NO)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,2,"Channel number IE ");
ie_tree = proto_item_add_subtree(ti, ett_ie_ch_no);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_ch_no_Cbits, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_ch_no_TN, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_link_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 octet;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_LINK_ID)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,2, "Link Identifier IE ");
ie_tree = proto_item_add_subtree(ti, ett_ie_link_id);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
octet = tvb_get_guint8(tvb,offset);
if ((octet & 0x20) == 0x20) {
proto_tree_add_item(ie_tree, hf_rsl_na, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
proto_tree_add_item(ie_tree, hf_rsl_ch_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_na, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_prio, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_sapi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_act_type(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
guint octet;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_ACT_TYPE)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,2,"Activation Type IE ");
ie_tree = proto_item_add_subtree(ti, ett_ie_act_type);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_rbit, tvb, offset, 1, ENC_BIG_ENDIAN);
octet = (tvb_get_guint8(tvb,offset) & 0x06) >> 1;
proto_tree_add_item(ie_tree, hf_rsl_a3a2, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (octet) {
case 0:
proto_tree_add_item(ie_tree, hf_rsl_a1_0, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 1:
proto_tree_add_item(ie_tree, hf_rsl_a1_1, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(ie_tree, hf_rsl_a1_2, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
break;
}
offset++;
return offset;
}
static int
dissect_rsl_ie_bs_power(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_BS_POW)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,2,"BS Power IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_bs_power);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_epc_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_bs_fpc_epc_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_bs_power, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_ch_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 length;
int ie_offset;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_CH_ID)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Channel Identification IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_ch_id);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb, offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ie_offset = offset;
proto_tree_add_text(ie_tree, tvb,offset, 1, "Channel Description Tag");
de_rr_ch_dsc(tvb, ie_tree, pinfo, offset+1, length, NULL, 0);
offset += 4;
proto_tree_add_text(ie_tree, tvb,offset,2,"Mobile Allocation Tag+Length(0)");
return ie_offset + length;
}
static int
dissect_rsl_ie_ch_mode(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 length;
int ie_offset;
guint8 ie_id;
guint8 octet;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_CH_MODE)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Channel Mode IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_ch_mode);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb, offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ie_offset = offset;
proto_tree_add_item(ie_tree, hf_rsl_cm_dtxd, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_cm_dtxu, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_speech_or_data, tvb, offset, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb,offset);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_ch_rate_and_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (octet) {
case 1:
proto_tree_add_item(ie_tree, hf_rsl_speech_coding_alg, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(ie_tree, hf_rsl_extension_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_t_nt_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb,offset);
if ((octet & 0x40) == 0x40) {
proto_tree_add_item(ie_tree, hf_rsl_ra_if_data_rte, tvb, offset, 1, ENC_BIG_ENDIAN);
}else{
proto_tree_add_item(ie_tree, hf_rsl_data_rte, tvb, offset, 1, ENC_BIG_ENDIAN);
}
break;
case 3:
proto_tree_add_text(ie_tree, tvb,offset,1,"0 No resources required(All other values are reserved)");
break;
default:
proto_tree_add_text(ie_tree, tvb,offset,1,"Speech or data indicator != 1,2 or 3");
break;
}
offset++;
return ie_offset + length;
}
static int
dissect_rsl_ie_enc_inf(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 length;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_ENC_INF)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Encryption information IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_enc_inf);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb, offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_alg_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_key, tvb, offset+1, length -1, ENC_NA);
return offset + length;
}
static int
dissect_rsl_ie_frame_no(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_FRAME_NO)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,3,"Frame Number IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_frame_no);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_req_ref_T1prim, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_req_ref_T3, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_req_ref_T2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_ho_ref(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_HO_REF)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,2,"Handover reference IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_ho_ref);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_ho_ref, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_l1_inf(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_L1_INF)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset, 3,"L1 Information IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_l1_inf);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_l1inf_power_lev, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_l1inf_fpc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_act_timing_adv, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_L3_inf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, gboolean is_mandatory, l3_inf_t type)
{
proto_item *ti;
proto_tree *ie_tree;
tvbuff_t *next_tvb;
guint16 length;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_L3_INF)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"L3 Information IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_L3_inf);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_ntohs(tvb, offset);
proto_item_set_len(ti, length+3);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset= offset+2;
if (type == L3_INF_CCCH)
{
proto_tree_add_text(ie_tree, tvb,offset,length,"Link Layer Service Data Unit ( L3 Message)(SACCH)");
next_tvb = tvb_new_subset(tvb, offset, length, length);
call_dissector(gsm_a_ccch_handle, next_tvb, pinfo, top_tree);
}
else if (type == L3_INF_SACCH)
{
proto_tree_add_text(ie_tree, tvb,offset,length,"Link Layer Service Data Unit ( L3 Message)(SACCH)");
next_tvb = tvb_new_subset(tvb, offset, length, length);
call_dissector(gsm_a_sacch_handle, next_tvb, pinfo, top_tree);
}
else
{
proto_tree_add_text(ie_tree, tvb,offset,length,"Link Layer Service Data Unit ( L3 Message)");
next_tvb = tvb_new_subset(tvb, offset, length, length);
call_dissector(gsm_a_dtap_handle, next_tvb, pinfo, top_tree);
}
offset = offset + length;
return offset;
}
static int
dissect_rsl_ie_ms_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint length;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_MS_ID)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"MS Identity IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_ms_id);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
de_mid(tvb, ie_tree, pinfo, offset, length, NULL, 0);
offset = offset + length;
return offset;
}
static int
dissect_rsl_ie_ms_pow(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_MS_POW)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset, 2,"MS Power IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_ms_pow);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_ms_power_lev, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_ms_fpc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_paging_grp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_PAGING_GRP)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,2,"Paging Group IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_paging_grp);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_paging_grp, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_paging_load(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_PAGING_LOAD)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,3,"Paging Load IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_paging_load);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_paging_load, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
return offset;
}
static int
dissect_rsl_ie_phy_ctx(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint length;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_PHY_CTX)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Physical Context IE ");
ie_tree = proto_item_add_subtree(ti, ett_ie_phy_ctx);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_phy_ctx, tvb, offset, length, ENC_NA);
offset = offset + length;
return offset;
}
static int
dissect_rsl_ie_access_delay(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_ACCESS_DELAY)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,2,"Access Delay IE ");
ie_tree = proto_item_add_subtree(ti, ett_ie_access_delay);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_acc_delay, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_rach_load(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint length;
guint8 ie_id;
int ie_offset;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_RACH_LOAD)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"RACH Load IE ");
ie_tree = proto_item_add_subtree(ti, ett_ie_rach_load);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ie_offset = offset;
proto_tree_add_item(ie_tree, hf_rsl_rach_slot_cnt, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset +2;
length = length -2;
proto_tree_add_item(ie_tree, hf_rsl_rach_busy_cnt, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset +2;
length = length -2;
proto_tree_add_item(ie_tree, hf_rsl_rach_acc_cnt, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset +2;
length = length -2;
if ( length > 0) {
proto_tree_add_text(ie_tree, tvb, offset,length ,"Supplementary Information");
}
offset = ie_offset + length;
return offset;
}
static int
dissect_rsl_ie_req_ref(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_REQ_REF)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,4,"Request Reference IE ");
ie_tree = proto_item_add_subtree(ti, ett_ie_req_ref);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_req_ref_ra, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_req_ref_T1prim, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_req_ref_T3, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_req_ref_T2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_rel_mode(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_REL_MODE)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,4,"Release Mode IE ");
ie_tree = proto_item_add_subtree(ti, ett_ie_rel_mode);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_rel_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_resource_inf(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
guint length;
int ie_offset;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_RESOURCE_INF)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Resource Information IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_resource_inf);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ie_offset = offset;
while (length > 0) {
proto_tree_add_item(ie_tree, hf_rsl_ch_no_Cbits, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_ch_no_TN, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_interf_band, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_interf_band_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = length - 2;
}
return ie_offset + length;
}
static int
dissect_rsl_ie_rlm_cause(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint length;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_RLM_CAUSE)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"RLM Cause IE ");
ie_tree = proto_item_add_subtree(ti, ett_ie_rlm_cause);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_rsl_extension_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_cause, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_starting_time(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_STARTING_TIME)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,3,"Starting Time IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_staring_time);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_req_ref_T1prim, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_req_ref_T3, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_req_ref_T2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_timing_adv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_TIMING_ADV)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,2,"Timing Advance IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_timing_adv);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_timing_adv, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_uplik_meas(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint length;
int ie_offset;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_UPLINK_MEAS)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Uplink Measurements IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_uplink_meas);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ie_offset = offset;
proto_tree_add_item(ie_tree, hf_rsl_dtxd, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_rxlev_full_up, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_rxlev_sub_up, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_rxqual_full_up, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_rxqual_sub_up, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return ie_offset+length;
}
static int
dissect_rsl_ie_cause(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint length;
guint8 octet;
int ie_offset;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_CAUSE)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Cause IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_cause);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ie_offset = offset;
octet = tvb_get_guint8(tvb,offset);
proto_tree_add_item(tree, hf_rsl_extension_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rsl_class, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((octet & 0x80) == 0x80)
offset++;
return ie_offset+length;
}
static int
dissect_rsl_ie_meas_res_no(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_MEAS_RES_NO)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,2,"Measurement result number IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_meas_res_no);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_meas_res_no, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_message_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_MESSAGE_ID)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Message Identifier IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_message_id);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_rsl_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_sys_info_type(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_SYS_INFO_TYPE)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,2,"System Info Type IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_sys_info_type);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_rsl_sys_info_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_full_imm_ass_inf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint length;
tvbuff_t *next_tvb;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_FULL_IMM_ASS_INF)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Full Immediate Assign Info IE ");
ie_tree = proto_item_add_subtree(ti, ett_ie_full_imm_ass_inf);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_text(ie_tree, tvb,offset,length,"Full Immediate Assign Info field");
next_tvb = tvb_new_subset(tvb, offset, length, length);
call_dissector(gsm_a_ccch_handle, next_tvb, pinfo, top_tree);
offset = offset + length;
return offset;
}
static int
dissect_rsl_ie_smscb_inf(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
tvbuff_t *next_tvb;
guint length;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_SMSCB_INF)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"SMSCB Information IE ");
ie_tree = proto_item_add_subtree(ti, ett_ie_smscb_inf);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
next_tvb = tvb_new_subset(tvb, offset, length, length);
call_dissector(gsm_cbch_handle, next_tvb, pinfo, top_tree);
offset = offset + length;
return offset;
}
static int
dissect_rsl_ie_ms_timing_offset(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_FULL_MS_TIMING_OFFSET)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"MS Timing Offset IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_ms_timing_offset);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_timing_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_err_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint length;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_ERR_MSG)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Erroneous Message IE ");
ie_tree = proto_item_add_subtree(ti, ett_ie_err_msg);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset = dissct_rsl_msg(tvb, pinfo, ie_tree, offset);
return offset;
}
static int
dissect_rsl_ie_full_bcch_inf(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
tvbuff_t *next_tvb;
guint16 length;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_FULL_BCCH_INF)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Full BCCH Information IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_full_bcch_inf);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb, offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_text(ie_tree, tvb,offset,length,"Layer 3 message");
next_tvb = tvb_new_subset(tvb, offset, length, length);
call_dissector(gsm_a_ccch_handle, next_tvb, pinfo, top_tree);
offset = offset + length;
return offset;
}
static int
dissect_rsl_ie_ch_needed(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_CH_NEEDED)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Channel Needed IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_ch_needed);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_ch_needed, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_cb_cmd_type(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_CB_CMD_TYPE)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"CB Command type IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_cb_cmd_type);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_ch_needed, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_smscb_mess(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
tvbuff_t *next_tvb;
guint length;
guint8 ie_id;
int ie_offset;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_SMSCB_MESS)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"SMSCB Message IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_smscb_mess);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ie_offset = offset;
next_tvb = tvb_new_subset(tvb, offset, length, length);
call_dissector(gsm_cbs_handle, next_tvb, pinfo, top_tree);
offset = ie_offset + length;
return offset;
}
static int
dissect_rsl_ie_cbch_load_inf(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti, *item;
proto_tree *ie_tree;
guint8 ie_id;
guint8 octet;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_CBCH_LOAD_INF)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"CBCH Load Information IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_cbch_load_inf);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
octet = tvb_get_guint8(tvb,offset);
proto_tree_add_item(ie_tree, hf_rsl_cbch_load_type, tvb, offset, 1, ENC_BIG_ENDIAN);
item = proto_tree_add_item(ie_tree, hf_rsl_msg_slt_cnt, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((octet & 0x80) == 0x80) {
proto_item_append_text(item,"The amount of SMSCB messages (1 to 15) that are needed immediately by BTS");
}else{
proto_item_append_text(item,"The amount of delay in message slots (1 to 15) that is needed immediately by BTS");
}
offset++;
return offset;
}
static int
dissect_rsl_ie_smscb_ch_ind(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_SMSCB_CH_IND)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"SMSCB Channel Indicator IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_smscb_ch_ind);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_ch_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_grp_call_ref(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint length;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_GRP_CALL_REF)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Group call reference IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_grp_call_ref);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_text(ie_tree, tvb,offset,length,"Descriptive group or broadcast call reference");
de_d_gb_call_ref(tvb, ie_tree, pinfo, offset, length, NULL, 0);
offset = offset + length;
return offset;
}
static int
dissect_rsl_ie_ch_desc(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint length;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_CH_DESC)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Channel description IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_ch_desc);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_text(ie_tree, tvb,offset,length,"Group Channel Description");
offset = offset + length;
return offset;
}
static int
dissect_rsl_ie_nch_drx(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_NCH_DRX_INF)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,2,"NCH DRX information IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_nch_drx);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset++;
return offset;
}
static int
dissect_rsl_ie_cmd_ind(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
guint8 octet;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_CMD_IND)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,2,"Command indicator IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_cmd_ind);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_extension_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb,offset);
if ((octet & 0x80) == 0x80) {
proto_tree_add_item(ie_tree, hf_rsl_command, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset+2;
}else{
proto_tree_add_item(ie_tree, hf_rsl_command, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
return offset;
}
static int
dissect_rsl_ie_emlpp_prio(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_EMLPP_PRIO)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,2,"eMLPP Priority IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_emlpp_prio);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_emlpp_prio, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_uic(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_UIC)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"UIC IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_uic);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_text(ie_tree, tvb,offset,1,"UIC");
offset++;
return offset;
}
static int
dissect_rsl_ie_main_ch_ref(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_MAIN_CH_REF)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Main channel reference IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_main_ch_ref);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_ch_no_TN, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_multirate_conf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint length;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_MULTIRATE_CONF)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"MultiRate configuration IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_multirate_conf);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
de_rr_multirate_conf(tvb, ie_tree, pinfo, offset, length, NULL, 0);
offset = offset + length;
return offset;
}
static int
dissect_rsl_ie_multirate_cntrl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_MULTIRATE_CNTRL)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,2,"MultiRate Control IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_multirate_cntrl);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset++;
return offset;
}
static int
dissect_rsl_ie_sup_codec_types(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint length;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_SUP_CODEC_TYPES)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Supported Codec Types IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_sup_codec_types);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_text(tree, tvb,offset,length,"Codec List");
return offset + length;
}
static int
dissect_rsl_ie_codec_conf(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint length;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_CODEC_CONF)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Codec Configuration IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_codec_conf);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb,offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset + length;
}
static int
dissect_rsl_ie_rtd(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti, *rtd_item;
proto_tree *ie_tree;
guint8 ie_id;
guint8 rtd;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_RTD)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"Round Trip Delay IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_rtd);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
rtd = (tvb_get_guint8(tvb,offset)>>1)*20;
rtd_item = proto_tree_add_uint(tree, hf_rsl_rtd, tvb,offset,1,rtd);
proto_item_append_text(rtd_item," ms");
proto_tree_add_item(ie_tree, hf_rsl_delay_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_tfo_status(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_TFO_STATUS)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"TFO Status IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_tfo_status);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_rsl_tfo, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_rsl_ie_llp_apdu(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 length;
int ie_offset;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_LLP_APDU)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"LLP APDU IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_llp_apdu);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb, offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ie_offset = offset;
proto_tree_add_text(tree, tvb,offset,length,
"Facility Information Element as defined in 3GPP TS 44.071");
return ie_offset + length;
}
static int
dissect_rsl_ie_tfo_transp_cont(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean is_mandatory)
{
proto_item *ti;
proto_tree *ie_tree;
guint8 length;
int ie_offset;
guint8 ie_id;
if (is_mandatory == FALSE) {
ie_id = tvb_get_guint8(tvb,offset);
if (ie_id != RSL_IE_TFO_TRANSP_CONT)
return offset;
}
ti = proto_tree_add_text(tree, tvb,offset,0,"TFO transparent container IE");
ie_tree = proto_item_add_subtree(ti, ett_ie_tfo_transp_cont);
proto_tree_add_item(ie_tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb, offset);
proto_item_set_len(ti, length+2);
proto_tree_add_item(ie_tree, hf_rsl_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ie_offset = offset;
proto_tree_add_text(tree, tvb,offset,length,
"Embedded message that contains the TFO configuration");
return ie_offset + length;
}
static int
dissct_rsl_ipaccess_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint8 msg_type;
guint32 local_addr = 0;
guint16 local_port = 0;
address src_addr;
msg_type = tvb_get_guint8(tvb, offset) & 0x7f;
offset++;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
guint8 tag;
unsigned int len, hlen;
const struct tlv_def *tdef;
proto_item *ti;
proto_tree *ie_tree;
tag = tvb_get_guint8(tvb, offset);
tdef = &rsl_att_tlvdef.def[tag];
switch (tdef->type) {
case TLV_TYPE_FIXED:
hlen = 1;
len = tdef->fixed_len;
break;
case TLV_TYPE_T:
hlen = 1;
len = 0;
break;
case TLV_TYPE_TV:
hlen = 1;
len = 1;
break;
case TLV_TYPE_TLV:
hlen = 2;
len = tvb_get_guint8(tvb, offset+1);
break;
case TLV_TYPE_TL16V:
hlen = 3;
len = tvb_get_guint8(tvb, offset+1) << 8 |
tvb_get_guint8(tvb, offset+2);
break;
case TLV_TYPE_UNKNOWN:
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
ti = proto_tree_add_item(tree, hf_rsl_ie_id, tvb, offset, 1, ENC_BIG_ENDIAN);
ie_tree = proto_item_add_subtree(ti, ett_ie_local_port);
offset += hlen;
switch (tag) {
case RSL_IE_CH_NO:
dissect_rsl_ie_ch_no(tvb, pinfo, ie_tree, offset, FALSE);
break;
case RSL_IE_FRAME_NO:
dissect_rsl_ie_frame_no(tvb, pinfo, ie_tree, offset, FALSE);
break;
case RSL_IE_MS_POW:
dissect_rsl_ie_ms_pow(tvb, pinfo, ie_tree, offset, FALSE);
break;
case RSL_IE_IPAC_REMOTE_IP:
proto_tree_add_item(ie_tree, hf_rsl_remote_ip, tvb,
offset, len, ENC_BIG_ENDIAN);
break;
case RSL_IE_IPAC_REMOTE_PORT:
proto_tree_add_item(ie_tree, hf_rsl_remote_port, tvb,
offset, len, ENC_BIG_ENDIAN);
break;
case RSL_IE_IPAC_LOCAL_IP:
proto_tree_add_item(ie_tree, hf_rsl_local_ip, tvb,
offset, len, ENC_BIG_ENDIAN);
local_addr = tvb_get_ipv4(tvb, offset);
break;
case RSL_IE_IPAC_LOCAL_PORT:
proto_tree_add_item(ie_tree, hf_rsl_local_port, tvb,
offset, len, ENC_BIG_ENDIAN);
local_port = tvb_get_ntohs(tvb, offset);
break;
case RSL_IE_IPAC_SPEECH_MODE:
proto_tree_add_item(ie_tree, hf_rsl_speech_mode_s, tvb,
offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_speech_mode_m, tvb,
offset, len, ENC_BIG_ENDIAN);
break;
case RSL_IE_IPAC_RTP_PAYLOAD:
case RSL_IE_IPAC_RTP_PAYLOAD2:
proto_tree_add_item(ie_tree, hf_rsl_rtp_payload, tvb,
offset, len, ENC_BIG_ENDIAN);
break;
case RSL_IE_IPAC_RTP_CSD_FMT:
proto_tree_add_item(ie_tree, hf_rsl_rtp_csd_fmt_d, tvb,
offset, len, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_rtp_csd_fmt_ir, tvb,
offset, len, ENC_BIG_ENDIAN);
break;
case RSL_IE_IPAC_CONN_ID:
proto_tree_add_item(ie_tree, hf_rsl_conn_id, tvb,
offset, len, ENC_BIG_ENDIAN);
break;
case RSL_IE_IPAC_CONN_STAT:
proto_tree_add_item(ie_tree, hf_rsl_cstat_tx_pkts, tvb,
offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_cstat_tx_octs, tvb,
offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_cstat_rx_pkts, tvb,
offset+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_cstat_rx_octs, tvb,
offset+12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_cstat_lost_pkts, tvb,
offset+16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_cstat_ia_jitter, tvb,
offset+20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_rsl_cstat_avg_tx_dly, tvb,
offset+24, 4, ENC_BIG_ENDIAN);
break;
}
offset += len;
}
switch (msg_type) {
case RSL_MSG_TYPE_IPAC_CRCX_ACK:
src_addr.type = AT_IPv4;
src_addr.len = 4;
src_addr.data = (guint8 *)&local_addr;
rtp_add_address(pinfo, &src_addr, local_port, 0,
"GSM A-bis/IP", pinfo->fd->num, 0, NULL);
rtcp_add_address(pinfo, &src_addr, local_port+1, 0,
"GSM A-bis/IP", pinfo->fd->num);
break;
}
return offset;
}
static int
dissct_rsl_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint8 msg_disc, msg_type;
msg_disc = tvb_get_guint8(tvb, offset++) >> 1;
msg_type = tvb_get_guint8(tvb,offset) & 0x7f;
proto_tree_add_item(tree, hf_rsl_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if (msg_disc == RSL_MSGDISC_IPACCESS) {
offset = dissct_rsl_ipaccess_msg(tvb, pinfo, tree, offset);
return offset;
}
offset++;
switch (msg_type) {
case RSL_MSG_TYPE_DATA_REQ:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_link_id(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_L3_inf(tvb, pinfo, tree, offset, TRUE, L3_INF_OTHER);
break;
case RSL_MSG_TYPE_DATA_IND:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_link_id(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_L3_inf(tvb, pinfo, tree, offset, TRUE, L3_INF_OTHER);
break;
case RSL_MSG_TYPE_ERROR_IND:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_link_id(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_rlm_cause(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_TYPE_EST_REQ:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_link_id(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_TYPE_EST_CONF:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_link_id(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_EST_IND:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_link_id(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) >1)
offset = dissect_rsl_ie_L3_inf(tvb, pinfo, tree, offset, FALSE, L3_INF_OTHER);
break;
case RSL_MSG_REL_REQ:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_link_id(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_rel_mode(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_REL_CONF:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_link_id(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_REL_IND:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_link_id(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_UNIT_DATA_REQ:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_link_id(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_L3_inf(tvb, pinfo, tree, offset, FALSE, L3_INF_OTHER);
break;
case RSL_MSG_BCCH_INFO:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_sys_info_type(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_full_bcch_inf(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_starting_time(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_CCCH_LOAD_IND:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_rach_load(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_paging_load(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_CHANRQD:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_req_ref(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_access_delay(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_phy_ctx(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_DELETE_IND:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_full_imm_ass_inf(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_PAGING_CMD:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_paging_grp(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_ms_id(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_ch_needed(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_emlpp_prio(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_IMM_ASS_CMD:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_full_imm_ass_inf(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_SMS_BC_REQ:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_smscb_inf(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_smscb_ch_ind(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_RF_RES_IND:
offset = dissect_rsl_ie_resource_inf(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_SACCH_FILL:
offset = dissect_rsl_ie_sys_info_type(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_L3_inf(tvb, pinfo, tree, offset, FALSE, L3_INF_CCCH);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_starting_time(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_OVERLOAD:
offset = dissect_rsl_ie_cause(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_ERROR_REPORT:
offset = dissect_rsl_ie_cause(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_message_id(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_link_id(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_err_msg(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_SMS_BC_CMD:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_cb_cmd_type(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_smscb_mess(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_smscb_ch_ind(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_CBCH_LOAD_IND:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_cbch_load_inf(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_smscb_ch_ind(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_NOT_CMD:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_cmd_ind(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_grp_call_ref(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_ch_desc(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_nch_drx(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_CHAN_ACTIV:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_act_type(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_ch_mode(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_ch_id(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_enc_inf(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_ho_ref(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_bs_power(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_ms_pow(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_timing_adv(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_phy_ctx(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_uic(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_main_ch_ref(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_multirate_conf(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_multirate_cntrl(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_sup_codec_types(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_tfo_transp_cont(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_CHAN_ACTIV_ACK:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_frame_no(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_CHAN_ACTIV_N_ACK:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_cause(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_CONN_FAIL:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_cause(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_DEACTIVATE_SACCH:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_ENCR_CMD:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_enc_inf(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_link_id(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_L3_inf(tvb, pinfo, tree, offset, TRUE, L3_INF_OTHER);
break;
case RSL_MSG_HANDODET:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_access_delay(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_MEAS_RES:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_meas_res_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_uplik_meas(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_bs_power(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_l1_inf(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_L3_inf(tvb, pinfo, tree, offset, FALSE, L3_INF_SACCH);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_ms_timing_offset(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_MODE_MODIFY_REQ:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_ch_mode(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_enc_inf(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_main_ch_ref(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_multirate_conf(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_multirate_cntrl(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_sup_codec_types(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_tfo_transp_cont(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_MODE_MODIFY_ACK:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_MODE_MODIFY_NACK:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_cause(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_PHY_CONTEXT_REQ:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_PHY_CONTEXT_CONF:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_bs_power(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_ms_pow(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_timing_adv(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_phy_ctx(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_RF_CHAN_REL:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_MS_POWER_CONTROL:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_ms_pow(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_BS_POWER_CONTROL:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_bs_power(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_PREPROC_CONFIG:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_PREPROC_MEAS_RES:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_RF_CHAN_REL_ACK:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_SACCH_INFO_MODIFY:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_sys_info_type(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_L3_inf(tvb, pinfo, tree, offset, FALSE, L3_INF_SACCH);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_starting_time(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_TALKER_DET:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_LISTENER_DET:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_REMOTE_CODEC_CONF_REP:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_codec_conf(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_sup_codec_types(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_tfo_transp_cont(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_R_T_D_REP:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_rtd(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_PRE_HANDO_NOTIF:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_multirate_cntrl(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_codec_conf(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_tfo_transp_cont(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_MR_CODEC_MOD_REQ:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_multirate_conf(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_MR_CODEC_MOD_ACK:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_multirate_conf(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_MR_CODEC_MOD_NACK:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_cause(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_MR_CODEC_MOD_PER:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_multirate_conf(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_TFO_REP:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_tfo_status(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_TFO_MOD_REQ:
offset = dissect_rsl_ie_ch_no(tvb, pinfo, tree, offset, TRUE);
offset = dissect_rsl_ie_multirate_cntrl(tvb, pinfo, tree, offset, TRUE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_sup_codec_types(tvb, pinfo, tree, offset, FALSE);
if (tvb_length_remaining(tvb,offset) > 0)
offset = dissect_rsl_ie_tfo_transp_cont(tvb, pinfo, tree, offset, FALSE);
break;
case RSL_MSG_LOC_INF:
offset = dissect_rsl_ie_llp_apdu(tvb, pinfo, tree, offset, TRUE);
break;
case RSL_MSG_TYPE_IPAC_MEAS_PP_DEF:
case RSL_MSG_TYPE_IPAC_HO_CAND_INQ:
case RSL_MSG_TYPE_IPAC_HO_CAND_RESP:
case RSL_MSG_TYPE_IPAC_PDCH_ACT:
case RSL_MSG_TYPE_IPAC_PDCH_ACT_ACK:
case RSL_MSG_TYPE_IPAC_PDCH_ACT_NACK:
case RSL_MSG_TYPE_IPAC_PDCH_DEACT:
case RSL_MSG_TYPE_IPAC_PDCH_DEACT_ACK:
case RSL_MSG_TYPE_IPAC_PDCH_DEACT_NACK:
if (global_rsl_use_nano_bts)
offset = dissct_rsl_ipaccess_msg(tvb, pinfo, tree, offset-1);
default:
break;
}
return offset;
}
static int
dissect_rsl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *rsl_tree;
guint8 msg_type;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RSL");
col_clear(pinfo->cinfo, COL_INFO);
msg_type = tvb_get_guint8(tvb,offset+1) & 0x7f;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",val_to_str_ext(msg_type, &rsl_msg_type_vals_ext,"unknown %u"));
top_tree = tree;
if (tree) {
ti = proto_tree_add_item(tree, proto_rsl, tvb, 0, -1, ENC_NA);
if (!global_rsl_use_nano_bts) {
guint8 msg_disc = tvb_get_guint8(tvb, offset) >> 1;
if (msg_disc == RSL_MSGDISC_IPACCESS)
return 0;
}
rsl_tree = proto_item_add_subtree(ti, ett_rsl);
proto_tree_add_item(rsl_tree, hf_rsl_msg_dsc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsl_tree, hf_rsl_T_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
offset = dissct_rsl_msg(tvb, pinfo, rsl_tree, offset);
}
return offset;
}
void proto_register_rsl(void)
{
void proto_reg_handoff_rsl(void);
static hf_register_info hf[] = {
{ &hf_rsl_msg_dsc,
{ "Message discriminator", "rsl.msg_dsc",
FT_UINT8, BASE_DEC, VALS(rsl_msg_disc_vals), 0xfe,
NULL, HFILL }
},
{ &hf_rsl_T_bit,
{ "T bit", "rsl.T_bit",
FT_BOOLEAN, 8, TFS(&rsl_t_bit_vals), 0x01,
NULL, HFILL }
},
{ &hf_rsl_msg_type,
{ "Message type", "rsl.msg_type",
FT_UINT8, BASE_HEX_DEC|BASE_EXT_STRING, &rsl_msg_type_vals_ext, 0x7f,
NULL, HFILL }
},
{ &hf_rsl_ie_id,
{ "Element identifier", "rsl.ie_id",
FT_UINT8, BASE_HEX_DEC|BASE_EXT_STRING, &rsl_ie_type_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_rsl_ie_length,
{ "Length", "rsl.ie_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_ch_no_Cbits,
{ "C-bits", "rsl.ch_no_Cbits",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &rsl_ch_no_Cbits_vals_ext, 0xf8,
NULL, HFILL }
},
{ &hf_rsl_ch_no_TN,
{ "Time slot number (TN)", "rsl.ch_no_TN",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_rsl_rtd,
{ "Round Trip Delay (RTD)", "rsl.rtd",
FT_UINT8, BASE_DEC, NULL, 0xfe,
NULL, HFILL }
},
{ &hf_rsl_delay_ind,
{ "Delay IND", "rsl.delay_ind",
FT_UINT8, BASE_DEC, rsl_delay_ind_vals, 0x01,
NULL, HFILL }
},
{ &hf_rsl_tfo,
{ "TFO", "rsl.tfo",
FT_BOOLEAN, 8, TFS(&rsl_tfo_vals), 0x01,
NULL, HFILL }
},
{ &hf_rsl_req_ref_ra,
{ "Random Access Information (RA)", "rsl.req_ref_ra",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_req_ref_T1prim,
{ "T1'", "rsl.req_ref_T1prim",
FT_UINT8, BASE_DEC, NULL, 0xf8,
NULL, HFILL }
},
{ &hf_rsl_req_ref_T3,
{ "T3", "rsl.req_ref_T3",
FT_UINT16, BASE_DEC, NULL, 0x07e0,
NULL, HFILL }
},
{ &hf_rsl_req_ref_T2,
{ "T2", "rsl.req_ref_T2",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_rsl_timing_adv,
{ "Timing Advance", "rsl.timing_adv",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_ho_ref,
{ "Hand-over reference", "rsl.ho_ref",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_l1inf_power_lev,
{ "MS power level", "rsl.ms_power_lev",
FT_UINT8, BASE_DEC, NULL, 0xf8,
NULL, HFILL }
},
{ &hf_rsl_l1inf_fpc,
{ "FPC/EPC", "rsl.ms_fpc",
FT_BOOLEAN, 8, TFS(&rsl_ms_fpc_epc_mode_vals), 0x04,
NULL, HFILL }
},
{ &hf_rsl_ms_power_lev,
{ "MS power level", "rsl.ms_power_lev",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_rsl_ms_fpc,
{ "FPC/EPC", "rsl.ms_fpc",
FT_BOOLEAN, 8, TFS(&rsl_ms_fpc_epc_mode_vals), 0x20,
NULL, HFILL }
},
{ &hf_rsl_act_timing_adv,
{ "Actual Timing Advance", "rsl.act_timing_adv",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_dtxd,
{ "DTXd", "rsl.dtxd",
FT_BOOLEAN, 8, TFS(&rsl_dtxd_vals), 0x40,
NULL, HFILL }
},
{ &hf_rsl_rxlev_full_up,
{ "RXLEV.FULL.up", "rsl.rxlev_full_up",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_rsl_rxlev_sub_up,
{ "RXLEV.SUB.up", "rsl.rxlev_sub_up",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_rsl_rxqual_full_up,
{ "RXQUAL.FULL.up", "rsl.rxqual_full_up",
FT_UINT8, BASE_DEC, NULL, 0x38,
NULL, HFILL }
},
{ &hf_rsl_rxqual_sub_up,
{ "RXQUAL.SUB.up", "rsl.rxqual_sub_up",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_rsl_acc_delay,
{ "Access Delay", "rsl.acc_del",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_rach_slot_cnt,
{ "RACH Slot Count", "rsl.rach_slot_cnt",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_rach_busy_cnt,
{ "RACH Busy Count", "rsl.rach_busy_cnt",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_rach_acc_cnt,
{ "RACH Access Count", "rsl.rach_acc_cnt",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_phy_ctx,
{ "Physical Context", "rsl.phy_ctx",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_na,
{ "Not applicable (NA)", "rsl.na",
FT_BOOLEAN, 8, TFS(&rsl_na_vals), 0x20,
NULL, HFILL }
},
{ &hf_rsl_ch_type,
{ "channel type", "rsl.ch_type",
FT_UINT8, BASE_DEC, VALS(rsl_ch_type_vals), 0xc0,
NULL, HFILL }
},
{ &hf_rsl_prio,
{ "Priority", "rsl.prio",
FT_UINT8, BASE_DEC, VALS(rsl_prio_vals), 0x18,
NULL, HFILL }
},
{ &hf_rsl_sapi,
{ "SAPI", "rsl.sapi",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_rsl_rbit,
{ "R", "rsl.rbit",
FT_BOOLEAN, 8, TFS(&rsl_rbit_vals), 0x80,
NULL, HFILL }
},
{ &hf_rsl_a3a2,
{ "A3A2", "rsl.a3a2",
FT_UINT8, BASE_DEC, VALS(rsl_a3a2_vals), 0x06,
NULL, HFILL }
},
{ &hf_rsl_a1_0,
{ "A1", "rsl.a1_0",
FT_BOOLEAN, 8, TFS(&rsl_a1_0_vals), 0x01,
NULL, HFILL }
},
{ &hf_rsl_a1_1,
{ "A1", "rsl.a1_1",
FT_BOOLEAN, 8, TFS(&rsl_a1_1_vals), 0x01,
NULL, HFILL }
},
{ &hf_rsl_a1_2,
{ "A1", "rsl.a2_0",
FT_BOOLEAN, 8, TFS(&rsl_a1_2_vals), 0x01,
NULL, HFILL }
},
{ &hf_rsl_epc_mode,
{ "EPC mode", "rsl.epc_mode",
FT_BOOLEAN, 8, TFS(&rsl_epc_mode_vals), 0x20,
NULL, HFILL }
},
{ &hf_rsl_bs_fpc_epc_mode,
{ "FPC-EPC mode", "rsl.fpc_epc_mode",
FT_BOOLEAN, 8, TFS(&rsl_fpc_epc_mode_vals), 0x10,
NULL, HFILL }
},
{ &hf_rsl_bs_power,
{ "Power Level", "rsl.bs_power",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &rsl_rlm_bs_power_vals_ext, 0x0f,
NULL, HFILL }
},
{ &hf_rsl_cm_dtxd,
{ "DTXd", "rsl.cm_dtxd",
FT_BOOLEAN, 8, TFS(&rsl_dtx_vals), 0x02,
NULL, HFILL }
},
{ &hf_rsl_cm_dtxu,
{ "DTXu", "rsl.cm_dtxu",
FT_BOOLEAN, 8, TFS(&rsl_dtx_vals), 0x01,
NULL, HFILL }
},
{ &hf_rsl_speech_or_data,
{ "Speech or data indicator", "rsl.speech_or_data",
FT_UINT8, BASE_DEC, VALS(rsl_speech_or_data_vals), 0x0,
NULL, HFILL }
},
{ &hf_rsl_ch_rate_and_type,
{ "Channel rate and type", "rsl.ch_rate_and_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &rsl_ch_rate_and_type_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_rsl_speech_coding_alg,
{ "Speech coding algorithm", "rsl.speech_coding_alg",
FT_UINT8, BASE_DEC, VALS(rsl_speech_coding_alg_vals), 0x0,
NULL, HFILL }
},
{ &hf_rsl_t_nt_bit,
{ "Transparent indication", "rsl.t_nt_bit",
FT_BOOLEAN, 8, TFS(&t_nt_bit_vals), 0x40,
NULL, HFILL }
},
{ &hf_rsl_ra_if_data_rte,
{ "Radio interface data rate", "rsl.ra_if_data_rte",
FT_UINT8, BASE_DEC, VALS(rsl_ra_if_data_rte_vals), 0x3f,
NULL, HFILL }
},
{ &hf_rsl_data_rte,
{ "Data rate", "rsl.data_rte",
FT_UINT8, BASE_DEC, VALS(rsl_ra_if_data_rte_vals), 0x3f,
NULL, HFILL }
},
{ &hf_rsl_alg_id,
{ "Algorithm Identifier", "rsl.alg_id",
FT_UINT8, BASE_DEC, VALS(rsl_algorithm_id_vals), 0x0,
NULL, HFILL }
},
{ &hf_rsl_key,
{ "KEY", "rsl.key",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_cause,
{ "Cause", "rsl.cause",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &rsl_rlm_cause_vals_ext, 0x7f,
NULL, HFILL }
},
{ &hf_rsl_rel_mode,
{ "Release Mode", "rsl.rel_mode",
FT_UINT8, BASE_DEC, VALS(rel_mode_vals), 0x01,
NULL, HFILL }
},
{ &hf_rsl_interf_band,
{ "Interf Band", "rsl.interf_band",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL }
},
{ &hf_rsl_interf_band_reserved,
{ "Interf Band reserved bits", "rsl.interf_band_reserved",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_rsl_meas_res_no,
{ "Measurement result number", "rsl.meas_res_no",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_extension_bit,
{ "Extension", "rsl.extension_bit",
FT_BOOLEAN, 8, TFS(&rsl_extension_bit_value), 0x80,
NULL, HFILL }},
{ &hf_rsl_class,
{ "Class", "rsl.class",
FT_UINT8, BASE_DEC, VALS(rsl_class_vals), 0x70,
NULL, HFILL }
},
{ &hf_rsl_paging_grp,
{ "Paging Group", "rsl.paging_grp",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_paging_load,
{ "Paging Buffer Space", "rsl.paging_load",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_sys_info_type,
{ "System Info Type", "rsl.sys_info_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &rsl_sys_info_type_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_rsl_timing_offset,
{ "Timing Offset", "rsl.timing_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_ch_needed,
{ "Channel Needed", "rsl.ch_needed",
FT_UINT8, BASE_DEC, VALS(rsl_ch_needed_vals), 0x03,
NULL, HFILL }
},
{ &hf_rsl_cbch_load_type,
{ "CBCH Load Type", "rsl.cbch_load_type",
FT_BOOLEAN, 8, TFS(&rsl_cbch_load_type_vals), 0x80,
NULL, HFILL }
},
{ &hf_rsl_msg_slt_cnt,
{ "Message Slot Count", "rsl.sg_slt_cnt",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_rsl_ch_ind,
{ "Channel Ind", "rsl.ch_ind",
FT_UINT8, BASE_DEC, VALS(rsl_ch_ind_vals), 0x0f,
NULL, HFILL }
},
{ &hf_rsl_command,
{ "Command", "rsl.cmd",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsl_emlpp_prio,
{ "eMLPP Priority", "rsl.emlpp_prio",
FT_UINT8, BASE_DEC, VALS(rsl_emlpp_prio_vals), 0x03,
NULL, HFILL }
},
{ &hf_rsl_speech_mode_s,
{ "ip.access Speech Mode S", "rsl.ipacc.speech_mode_s",
FT_UINT8, BASE_HEX, VALS(rsl_ipacc_spm_s_vals),
0xf, NULL, HFILL }
},
{ &hf_rsl_speech_mode_m,
{ "ip.access Speech Mode M", "rsl.ipacc.speech_mode_m",
FT_UINT8, BASE_HEX, VALS(rsl_ipacc_spm_m_vals),
0xf0, NULL, HFILL }
},
{ &hf_rsl_conn_id,
{ "ip.access Connection ID", "rsl.ipacc.conn_id",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_rsl_rtp_payload,
{ "ip.access RTP Payload Type", "rsl.ipacc.rtp_payload",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_rsl_rtp_csd_fmt_d,
{ "ip.access RTP CSD Format D", "rsl.ipacc.rtp_csd_fmt_d",
FT_UINT8, BASE_HEX, VALS(rsl_ipacc_rtp_csd_fmt_d_vals),
0x0f, NULL, HFILL },
},
{ &hf_rsl_rtp_csd_fmt_ir,
{ "ip.access RTP CSD Format IR", "rsl.ipacc.rtp_csd_fmt_ir",
FT_UINT8, BASE_HEX, VALS(rsl_ipacc_rtp_csd_fmt_ir_vals),
0xf0, NULL, HFILL },
},
{ &hf_rsl_local_port,
{ "ip.access Local RTP Port", "rsl.ipacc.local_port",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_rsl_remote_port,
{ "ip.access Remote RTP Port", "rsl.ipacc.remote_port",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_rsl_local_ip,
{ "ip.access Local IP Address", "rsl.ipacc.local_ip",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_rsl_remote_ip,
{ "ip.access Remote IP Address", "rsl.ipacc.remote_ip",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_rsl_cstat_tx_pkts,
{ "Packets Sent", "rsl.ipacc.cstat.tx_pkts",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rsl_cstat_tx_octs,
{ "Octets Sent", "rsl.ipacc.cstat.tx_octets",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rsl_cstat_rx_pkts,
{ "Packets Received", "rsl.ipacc.cstat.rx_pkts",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rsl_cstat_rx_octs,
{ "Octets Received", "rsl.ipacc.cstat.rx_octets",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rsl_cstat_lost_pkts,
{ "Packets Lost", "rsl.ipacc.cstat.lost_pkts",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rsl_cstat_ia_jitter,
{ "Inter-arrival Jitter", "rsl.ipacc.cstat.ia_jitter",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rsl_cstat_avg_tx_dly,
{ "Average Tx Delay", "rsl.ipacc.cstat.avg_tx_delay",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_rsl,
&ett_ie_link_id,
&ett_ie_act_type,
&ett_ie_bs_power,
&ett_ie_ch_id,
&ett_ie_ch_mode,
&ett_ie_enc_inf,
&ett_ie_ch_no,
&ett_ie_frame_no,
&ett_ie_ho_ref,
&ett_ie_l1_inf,
&ett_ie_L3_inf,
&ett_ie_ms_id,
&ett_ie_ms_pow,
&ett_ie_phy_ctx,
&ett_ie_paging_grp,
&ett_ie_paging_load,
&ett_ie_access_delay,
&ett_ie_rach_load,
&ett_ie_req_ref,
&ett_ie_rel_mode,
&ett_ie_resource_inf,
&ett_ie_rlm_cause,
&ett_ie_staring_time,
&ett_ie_timing_adv,
&ett_ie_uplink_meas,
&ett_ie_full_imm_ass_inf,
&ett_ie_smscb_inf,
&ett_ie_ms_timing_offset,
&ett_ie_err_msg,
&ett_ie_full_bcch_inf,
&ett_ie_ch_needed,
&ett_ie_cb_cmd_type,
&ett_ie_smscb_mess,
&ett_ie_cbch_load_inf,
&ett_ie_smscb_ch_ind,
&ett_ie_grp_call_ref,
&ett_ie_ch_desc,
&ett_ie_nch_drx,
&ett_ie_cmd_ind,
&ett_ie_emlpp_prio,
&ett_ie_uic,
&ett_ie_main_ch_ref,
&ett_ie_multirate_conf,
&ett_ie_multirate_cntrl,
&ett_ie_sup_codec_types,
&ett_ie_codec_conf,
&ett_ie_rtd,
&ett_ie_tfo_status,
&ett_ie_llp_apdu,
&ett_ie_tfo_transp_cont,
&ett_ie_cause,
&ett_ie_meas_res_no,
&ett_ie_message_id,
&ett_ie_sys_info_type,
&ett_ie_speech_mode,
&ett_ie_conn_id,
&ett_ie_remote_ip,
&ett_ie_remote_port,
&ett_ie_local_port,
&ett_ie_local_ip,
&ett_ie_rtp_payload,
};
module_t *rsl_module;
#define RSL_ATT_TLVDEF(_attr, _type, _fixed_len) \
rsl_att_tlvdef.def[_attr].type = _type; \
rsl_att_tlvdef.def[_attr].fixed_len = _fixed_len; \
RSL_ATT_TLVDEF(RSL_IE_CH_NO, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_LINK_ID, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_ACT_TYPE, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_BS_POW, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_CH_ID, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_CH_MODE, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_ENC_INF, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_FRAME_NO, TLV_TYPE_FIXED, 2);
RSL_ATT_TLVDEF(RSL_IE_HO_REF, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_L1_INF, TLV_TYPE_FIXED, 2);
RSL_ATT_TLVDEF(RSL_IE_L3_INF, TLV_TYPE_TL16V, 0);
RSL_ATT_TLVDEF(RSL_IE_MS_ID, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_MS_POW, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_PAGING_GRP, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_PAGING_LOAD, TLV_TYPE_FIXED, 2);
RSL_ATT_TLVDEF(RSL_IE_PHY_CTX, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_ACCESS_DELAY, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_RACH_LOAD, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_REQ_REF, TLV_TYPE_FIXED, 3);
RSL_ATT_TLVDEF(RSL_IE_REL_MODE, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_RESOURCE_INF, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_RLM_CAUSE, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_STARTING_TIME, TLV_TYPE_FIXED, 2);
RSL_ATT_TLVDEF(RSL_IE_TIMING_ADV, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_UPLINK_MEAS, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_CAUSE, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_MEAS_RES_NO, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_MESSAGE_ID, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_SYS_INFO_TYPE, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_MS_POWER_PARAM, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_BS_POWER_PARAM, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_PREPROC_PARAM, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_PREPROC_MEAS, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_ERR_MSG, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_FULL_BCCH_INF, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_CH_NEEDED, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_CB_CMD_TYPE, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_SMSCB_MESS, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_FULL_IMM_ASS_INF, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_CBCH_LOAD_INF, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_SMSCB_CH_IND, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_GRP_CALL_REF, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_CH_DESC, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_NCH_DRX_INF, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_CMD_IND, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_EMLPP_PRIO, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_UIC, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_MAIN_CH_REF, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_MULTIRATE_CONF, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_MULTIRATE_CNTRL, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_SUP_CODEC_TYPES, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_CODEC_CONF, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_RTD, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_TFO_STATUS, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_LLP_APDU, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_IPAC_REMOTE_IP, TLV_TYPE_FIXED, 4);
RSL_ATT_TLVDEF(RSL_IE_IPAC_REMOTE_PORT, TLV_TYPE_FIXED, 2);
RSL_ATT_TLVDEF(RSL_IE_IPAC_LOCAL_IP, TLV_TYPE_FIXED, 4);
RSL_ATT_TLVDEF(RSL_IE_IPAC_CONN_STAT, TLV_TYPE_TLV, 0);
RSL_ATT_TLVDEF(RSL_IE_IPAC_LOCAL_PORT, TLV_TYPE_FIXED, 2);
RSL_ATT_TLVDEF(RSL_IE_IPAC_SPEECH_MODE, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_IPAC_CONN_ID, TLV_TYPE_FIXED, 2);
RSL_ATT_TLVDEF(RSL_IE_IPAC_RTP_PAYLOAD2,TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_IPAC_RTP_PAYLOAD, TLV_TYPE_TV, 0);
RSL_ATT_TLVDEF(RSL_IE_IPAC_RTP_CSD_FMT, TLV_TYPE_TV, 0);
proto_rsl = proto_register_protocol("Radio Signalling Link (RSL)", "RSL", "rsl");
proto_register_field_array(proto_rsl, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("gsm_abis_rsl", dissect_rsl, proto_rsl);
rsl_module = prefs_register_protocol(proto_rsl, proto_reg_handoff_rsl);
prefs_register_bool_preference(rsl_module, "use_ipaccess_rsl",
"Use nanoBTS definitions",
"Use ipaccess nanoBTS specific definitions for RSL",
&global_rsl_use_nano_bts);
}
void
proto_reg_handoff_rsl(void)
{
dissector_handle_t rsl_handle;
rsl_handle = new_create_dissector_handle(dissect_rsl, proto_rsl);
dissector_add_uint("lapd.gsm.sapi", LAPD_GSM_SAPI_RA_SIG_PROC, rsl_handle);
gsm_cbch_handle = find_dissector("gsm_cbch");
gsm_cbs_handle = find_dissector("gsm_cell_broadcast");
gsm_a_ccch_handle = find_dissector("gsm_a_ccch");
gsm_a_dtap_handle = find_dissector("gsm_a_dtap");
gsm_a_sacch_handle = find_dissector("gsm_a_sacch");
}
