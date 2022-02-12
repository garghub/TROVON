static guint16
de_bssgp_aligment_octets(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len, "%u Spare octet(s)",len);
return(len);
}
static guint16
de_bssgp_bmax_default_ms(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_bmax, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
return(curr_offset-offset);
}
static guint16
de_bssgp_bss_area_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_bss_area_ind, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_bucket_leak_rate(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_r, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
return(curr_offset-offset);
}
static guint16
de_bssgp_bvc_bucket_size(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_bucket_size, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
return(curr_offset-offset);
}
static guint16
de_bssgp_bvci(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint16 bvci;
curr_offset = offset;
bvci = tvb_get_ntohs(tvb,curr_offset);
proto_tree_add_item(tree, hf_bssgp_bvci, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
if (add_string)
g_snprintf(add_string, string_len, " - 0x%x", bvci);
return(curr_offset-offset);
}
static guint16
de_bssgp_bvc_meas(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_delay_val, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
return(curr_offset-offset);
}
static guint16
de_bssgp_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset+=1;
return(curr_offset-offset);
}
guint16
de_bssgp_cell_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string, int string_len)
{
guint32 curr_offset;
guint16 ci;
curr_offset = offset;
curr_offset = curr_offset + de_gmm_rai(tvb, tree, pinfo, curr_offset, 6, add_string, string_len);
ci = tvb_get_ntohs(tvb, curr_offset);
proto_tree_add_item(tree, hf_bssgp_ci, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
if (add_string)
g_snprintf(add_string, string_len, "%s, CI %u", add_string, ci);
return(curr_offset-offset);
}
static guint16
de_bssgp_chnl_needed(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
curr_offset = de_rr_chnl_needed(tvb, tree, pinfo, curr_offset, len , NULL, 0);
return(curr_offset-offset);
}
static guint16
de_bssgp_flush_action(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 oct;
curr_offset = offset;
oct = tvb_get_guint8(tvb,curr_offset);
proto_tree_add_item(tree, hf_bssgp_flush_action, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset+=1;
if (add_string)
g_snprintf(add_string, string_len, " - %s", val_to_str_const(oct, bssgp_flush_action_vals, "Reserved"));
return(curr_offset-offset);
}
static guint16
de_bssgp_llc_pdu(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *next_tvb=NULL;
guint32 curr_offset;
curr_offset = offset;
if(len > 0){
next_tvb = tvb_new_subset_length(tvb, curr_offset, len);
proto_tree_add_text(tree, tvb, curr_offset, len, "LLC Data");
}
if(next_tvb){
if (llc_handle) {
call_dissector(llc_handle, next_tvb, pinfo, gparent_tree);
}
else if (data_handle) {
call_dissector(data_handle, next_tvb, pinfo, gparent_tree);
}
}
return(len);
}
static guint16
de_bssgp_llc_frames_disc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 oct;
curr_offset = offset;
oct = tvb_get_guint8(tvb,curr_offset);
proto_tree_add_item(tree, hf_bssgp_llc_frames_disc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset+=1;
if (add_string)
g_snprintf(add_string, string_len, " - %u Frames", oct);
return(curr_offset-offset);
}
static guint16
de_bssgp_ms_bucket_size(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_bucket_size, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
return(curr_offset-offset);
}
static guint16
de_bssgp_omc_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_omc_id, tvb, curr_offset, len, ENC_NA);
return len;
}
static guint16
de_bssgp_pdu_in_error(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_msg_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_text(tree, tvb, curr_offset, len-1, "PDU Data");
return len;
}
static guint16
de_bssgp_pdu_lifetime(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_delay_val, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
return(curr_offset-offset);
}
static guint16
de_bssgp_qos_profile(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_item *pi, *pre_item;
guint32 curr_offset;
guint16 peak_bit_rate;
guint8 rate_gran, precedence;
int link_dir;
curr_offset = offset;
link_dir = pinfo->link_dir;
peak_bit_rate = tvb_get_ntohs(tvb, curr_offset);
pi = proto_tree_add_text(tree, tvb, curr_offset, 1, "Peak bit rate: ");
if (peak_bit_rate == 0) {
proto_item_append_text(pi, "Best effort");
}else{
rate_gran = tvb_get_guint8(tvb, curr_offset+2)&0xc0;
switch(rate_gran){
case 0:
proto_item_append_text(pi, "%u bits/s", peak_bit_rate * 100);
break;
case 1:
proto_item_append_text(pi, "%u kbits/s", peak_bit_rate);
break;
case 2:
proto_item_append_text(pi, "%u kbits/s", peak_bit_rate * 10);
break;
case 3:
proto_item_append_text(pi, "%u kbits/s", peak_bit_rate * 100);
break;
default:
break;
}
}
curr_offset+=2;
proto_tree_add_item(tree, hf_bssgp_peak_rate_gran, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bssgp_cr_bit, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bssgp_t_bit, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bssgp_a_bit, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
precedence = tvb_get_guint8(tvb, curr_offset) & 0x7;
pre_item = proto_tree_add_item(tree, hf_bssgp_precedence, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
if(link_dir == P2P_DIR_DL){
proto_item_append_text(pre_item, " %s", val_to_str_const((guint32)precedence, bssgp_precedence_dl, "Radio Priority Unknown(Radio priority 3)"));
}else{
proto_item_append_text(pre_item, " %s", val_to_str_const((guint32)precedence, bssgp_precedence_ul, "Priority Unknown(Low priority)"));
}
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_ra_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_ra_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_ra_cap_upd_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_ra_cap_upd_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_r_default_ms(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_r_default_ms, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
return(curr_offset-offset);
}
static guint16
de_bssgp_suspend_ref_no(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_suspend_ref_no, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_tag(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_tag, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_trace_ref(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_trace_ref, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
return(curr_offset-offset);
}
static guint16
de_bssgp_trace_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len, "Trace Type data ( Coding unknown (Specification withdrawn) 3GPP TS 32.008)");
return(len);
}
static guint16
de_bssgp_transaction_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_transaction_id, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
return(curr_offset-offset);
}
static guint16
de_bssgp_trigger_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_trigger_id, tvb, curr_offset, len, ENC_NA);
return(len);
}
static guint16
de_bssgp_no_of_oct_affected(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 no_of_oct;
curr_offset = offset;
no_of_oct = tvb_get_ntoh24(tvb,curr_offset);
proto_tree_add_item(tree, hf_bssgp_no_of_oct, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
curr_offset+=3;
if (add_string)
g_snprintf(add_string, string_len, " - %u", no_of_oct);
return(curr_offset-offset);
}
static guint16
de_bssgp_gprs_timer(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_unit_val, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bssgp_gprs_timer, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_feature_bitmap(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_mbms, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bssgp_EnhancedRadioStatus, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bssgp_pfcfc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bssgp_rim, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bssgp_lcs, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bssgp_inr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bssgp_cbl, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bssgp_pfc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_bucket_full_ratio(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_bucket_full_ratio, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_serv_utran_cco(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_serv_eutran_cco, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bssgp_serv_utran_cco, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_nsei(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint16 nsei;
curr_offset = offset;
nsei = tvb_get_ntohs(tvb, curr_offset);
proto_tree_add_item(tree, hf_bssgp_nsei, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
col_append_sep_fstr(pinfo->cinfo, COL_INFO, BSSGP_SEP, "NSEI %u", nsei);
return(curr_offset-offset);
}
static guint16
de_bssgp_rrlp_apdu(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *next_tvb=NULL;
guint32 curr_offset;
curr_offset = offset;
if(len > 0){
next_tvb = tvb_new_subset_remaining(tvb, curr_offset);
proto_tree_add_text(tree, tvb, curr_offset, len, "RRLP APDU");
}
if(next_tvb){
if (rrlp_handle) {
call_dissector(rrlp_handle, next_tvb, pinfo, gparent_tree);
}else if (data_handle) {
call_dissector(data_handle, next_tvb, pinfo, gparent_tree);
}
}
return(len);
}
static guint16
de_bssgp_rrlp_flags(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_rrlp_flag1, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
return(curr_offset-offset);
}
static guint16
de_bssgp_rim_app_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
g_rim_application_identity = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_bssgp_rim_app_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_rim_seq_no(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_rim_seq_no, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset+=4;
return(curr_offset-offset);
}
static guint16
de_bssgp_ran_information_request_app_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *new_tvb = NULL;
int curr_offset, bit_offset;
curr_offset = offset;
switch(g_rim_application_identity){
case 1:
curr_offset = curr_offset + de_bssgp_cell_id(tvb, tree, pinfo,curr_offset, len, add_string, string_len);
break;
case 2:
curr_offset = curr_offset + de_bssgp_cell_id(tvb, tree, pinfo, curr_offset, len, add_string, string_len);
break;
case 3:
curr_offset = curr_offset + de_bssgp_cell_id(tvb, tree, pinfo, curr_offset, len, add_string, string_len);
break;
case 4:
{
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
bit_offset = curr_offset<<3;
bit_offset = dissect_s1ap_Global_ENB_ID(tvb, bit_offset, &asn1_ctx, tree, hf_bssgp_Global_ENB_ID_PDU);
dissect_s1ap_SONtransferRequestContainer(tvb, bit_offset, &asn1_ctx, tree, hf_bssgp_SONtransferRequestContainer_PDU);
curr_offset += 7; curr_offset >>= 3;
}
break;
case 5:
new_tvb = tvb_new_subset_remaining(tvb, curr_offset);
curr_offset = curr_offset + dissect_ranap_SourceCellID_PDU(new_tvb, pinfo, tree, NULL);
break;
default :
proto_tree_add_text(tree, tvb, curr_offset, len, "Unknown RIM Application Identity");
curr_offset+=len;
break;
}
return(curr_offset-offset);
}
static guint16
de_bssgp_ran_information_app_cont_unit(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *new_tvb = NULL;
guint32 curr_offset;
guint8 type, num_items, rat_type, oct;
int i;
curr_offset = offset;
switch(g_rim_application_identity){
case 1:
curr_offset = curr_offset + de_bssgp_cell_id(tvb, tree, pinfo, curr_offset, len, add_string, string_len);
num_items = tvb_get_guint8(tvb,curr_offset)>>1;
proto_tree_add_item(tree, hf_bssgp_num_si_psi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
type = tvb_get_guint8(tvb,curr_offset)&0x01;
proto_tree_add_item(tree, hf_bssgp_si_psi_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if(type==1){
for (i=0; i < num_items; i++){
proto_tree_add_text(tree, tvb, curr_offset, 22, "PSI item %u - not dissected yet",i+1);
curr_offset+=22;
}
}else{
void (*msg_fcn_p)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len);
gint ett_tree;
int hf_idx;
const gchar *msg_str;
proto_item *si_item;
proto_tree *si_tree;
for (i=0; i < num_items; i++){
oct = tvb_get_guint8(tvb,curr_offset);
get_rr_msg_params(oct, &msg_str, &ett_tree, &hf_idx, &msg_fcn_p);
proto_tree_add_text(tree, tvb, curr_offset, 21, "SI item %u ",i+1);
si_item = proto_tree_add_item(tree, hf_idx, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
si_tree = proto_item_add_subtree(si_item, ett_tree);
if (msg_fcn_p == NULL){
proto_tree_add_text(si_tree, tvb, curr_offset, 21, "Unknown SI message");
}else{
(*msg_fcn_p)(tvb, si_tree, pinfo, curr_offset+1, 20);
}
curr_offset+=21;
}
}
break;
case 2:
curr_offset = curr_offset + de_bssgp_cell_id(tvb, tree, pinfo, curr_offset, len, add_string, string_len);
proto_tree_add_text(tree, tvb, curr_offset, 1, "SYSTEM INFORMATION type 3 message");
curr_offset++;
break;
case 3:
curr_offset = curr_offset + de_bssgp_cell_id(tvb, tree, pinfo, curr_offset, len, add_string, string_len);
proto_tree_add_text(tree, tvb, curr_offset, len-6, "MBMS data channel report - not dissected yet");
break;
case 4:
rat_type = tvb_get_guint8(tvb,curr_offset) & 0x0f;
proto_tree_add_item(tree, hf_bssgp_rat_discriminator, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
switch(rat_type){
case 0:
curr_offset = curr_offset + de_bssgp_cell_id(tvb, tree, pinfo, curr_offset, len, add_string, string_len);
break;
case 1:
new_tvb = tvb_new_subset_remaining(tvb, curr_offset);
curr_offset = curr_offset + dissect_ranap_SourceCellID_PDU(new_tvb, pinfo, tree, NULL);
break;
case 2:
new_tvb = tvb_new_subset_remaining(tvb, curr_offset);
curr_offset = curr_offset + dissect_s1ap_Global_ENB_ID_PDU(new_tvb, pinfo, tree, NULL);
break;
default:
break;
}
break;
case 5:
new_tvb = tvb_new_subset_remaining(tvb, curr_offset);
curr_offset = curr_offset + dissect_ranap_SourceCellID_PDU(new_tvb, pinfo, tree, NULL);
proto_tree_add_text(tree, tvb, curr_offset, len-(curr_offset-offset), "UTRA SI Container - not dissected yet");
break;
default :
proto_tree_add_text(tree, tvb, curr_offset, len, "Unknown RIM Application Identitys Data");
curr_offset+=len;
break;
}
return(curr_offset-offset);
}
static guint16
de_bssgp_ran_app_error_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *new_tvb = NULL;
guint32 curr_offset;
curr_offset = offset;
switch(g_rim_application_identity){
case 1:
proto_tree_add_item(tree, hf_bssgp_nacc_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_text(tree, tvb, curr_offset, len-(curr_offset-offset), "Erroneous Application Container including IEI and LI");
break;
case 2:
proto_tree_add_item(tree, hf_bssgp_s13_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_text(tree, tvb, curr_offset, len-(curr_offset-offset), "Erroneous Application Container including IEI and LI");
break;
case 3:
proto_tree_add_item(tree, hf_bssgp_mbms_data_ch_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_text(tree, tvb, curr_offset, len-(curr_offset-offset), "Erroneous Application Container including IEI and LI");
break;
case 4:
new_tvb = tvb_new_subset_remaining(tvb, curr_offset);
curr_offset = curr_offset + dissect_s1ap_SONtransferCause_PDU(new_tvb, pinfo, tree, NULL);
proto_tree_add_text(tree, tvb, curr_offset, len-(curr_offset-offset), "Erroneous Application Container including IEI and LI");
break;
case 5:
proto_tree_add_item(tree, hf_bssgp_utra_si_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
break;
default :
proto_tree_add_text(tree, tvb, curr_offset, len, "Unknown Application Error Container");
break;
}
return(len);
}
static guint16
de_bssgp_rim_pdu_indications(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
switch(g_pdu_type){
case BSSGP_PDU_RAN_INFORMATION_REQUEST:
proto_tree_add_item(tree, hf_bssgp_ran_inf_req_pdu_t_ext_c, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
break;
case BSSGP_PDU_RAN_INFORMATION:
proto_tree_add_item(tree, hf_bssgp_ran_inf_pdu_t_ext_c, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bssgp_rim_pdu_ind_ack, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
break;
case BSSGP_PDU_RAN_INFORMATION_APP_ERROR:
proto_tree_add_item(tree, hf_bssgp_rim_pdu_ind_ack, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
break;
default:
break;
}
return(curr_offset-offset);
}
static guint16
de_bssgp_rim_proto_ver_no(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_rim_proto_ver_no, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_pfc_flow_ctrl(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree *pfc_tree;
proto_item *pi;
guint32 curr_offset;
guint8 num_pfc, i, pfc_len;
gboolean b_pfc_included;
curr_offset = offset;
num_pfc = tvb_get_guint8(tvb, curr_offset);
pi = proto_tree_add_text(tree, tvb, curr_offset, 1,
"Number of PFCs: ");
if (num_pfc < 12) {
proto_item_append_text(pi, "%u", num_pfc);
}else {
proto_item_append_text(pi, "Reserved");
return (curr_offset-offset);
}
curr_offset++;
if (num_pfc == 0)
return (curr_offset-offset);
pfc_len = (len - 1) / num_pfc;
b_pfc_included = (pfc_len == 6);
for (i = 0; i < num_pfc; i++) {
pfc_tree = proto_tree_add_subtree_format(tree, tvb, curr_offset, pfc_len,
ett_bssgp_pfc_flow_control_parameters_pfc, NULL, "PFC (%u)", i + 1);
de_sm_pflow_id(tvb, pfc_tree, pinfo, curr_offset, 1, NULL, 0);
curr_offset++;
proto_tree_add_item(tree, hf_bssgp_bmax_pfc, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
proto_tree_add_item(tree, hf_bssgp_r_pfc, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
if (b_pfc_included) {
proto_tree_add_item(tree, hf_bssgp_b_pfc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
}
}
return(curr_offset-offset);
}
static guint16
de_bssgp_rim_routing_inf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint16 rnc_id;
tvbuff_t *new_tvb = NULL;
guint32 curr_offset;
curr_offset = offset;
oct = tvb_get_guint8(tvb,curr_offset);
proto_tree_add_item(tree, hf_bssgp_ra_discriminator, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
switch(oct){
case 0:
de_bssgp_cell_id(tvb, tree, pinfo, curr_offset, len, add_string, string_len);
break;
case 1:
curr_offset = curr_offset + de_gmm_rai(tvb, tree, pinfo, curr_offset , 6, add_string, string_len);
rnc_id = tvb_get_ntohs(tvb, curr_offset);
proto_tree_add_item(tree, hf_bssgp_rnc_id, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
if (add_string)
g_snprintf(add_string, string_len, " %s, RNC-ID %u", add_string, rnc_id);
break;
case 2:
curr_offset = curr_offset+ de_emm_trac_area_id(tvb, tree, pinfo, curr_offset, 5, add_string, string_len);
new_tvb = tvb_new_subset_remaining(tvb, curr_offset);
dissect_s1ap_Global_ENB_ID_PDU(new_tvb, pinfo, tree, NULL);
break;
default:
proto_tree_add_text(tree, tvb, curr_offset, 3, "Unknown RIM Routing Address discriminator");
return len;
}
return len;
}
static guint16
de_bssgp_mbms_session_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_mbms_session_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_mbms_session_dur(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *new_tvb;
guint32 curr_offset;
curr_offset = offset;
new_tvb =tvb_new_subset_length(tvb, offset, len);
dissector_try_uint(diameter_3gpp_avp_dissector_table, 904, new_tvb, pinfo, tree);
return(curr_offset-offset);
}
static guint16
de_bssgp_mbms_sai_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *new_tvb;
guint32 curr_offset;
curr_offset = offset;
new_tvb =tvb_new_subset_length(tvb, offset, len);
dissector_try_uint(diameter_3gpp_avp_dissector_table, 903, new_tvb, pinfo, tree);
return(curr_offset-offset);
}
static guint16
de_bssgp_mbms_response(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_mbms_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_mbms_ra_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree *rai_tree;
guint32 curr_offset;
guint8 num_ra_ids;
int i;
curr_offset = offset;
num_ra_ids = tvb_get_guint8(tvb,curr_offset) >> 4;
proto_tree_add_item(tree, hf_bssgp_mbms_num_ra_ids, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
for (i = 0; i < num_ra_ids; i++) {
rai_tree = proto_tree_add_subtree_format(tree, tvb, curr_offset, 8,
ett_bssgp_ra_id, NULL, "Routing Area Identification (%u)", i + 1);
de_gmm_rai(tvb, rai_tree, pinfo, curr_offset , 6, NULL, 0);
curr_offset+=8;
}
return(curr_offset-offset);
}
static guint16
de_bssgp_mbms_session_inf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_session_inf, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_mbms_stop_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_mbms_stop_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_pfcs_to_be_set_up_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree *pfc_tree, *pft_tree, *abqp_tree, *arp_tree, *t10_tree;
proto_item *pi;
guint32 curr_offset;
guint8 num_pfc, i, pfc_len;
curr_offset = offset;
num_pfc = tvb_get_guint8(tvb, curr_offset);
pi = proto_tree_add_text(tree, tvb, curr_offset, 1,
"Number of PFCs: ");
if (num_pfc < 12) {
proto_item_append_text(pi, "%u", num_pfc);
}else {
proto_item_append_text(pi, "Reserved");
return (len);
}
curr_offset++;
if (num_pfc == 0)
return (curr_offset-offset);
pfc_len = (len - 1) / num_pfc;
for (i = 0; i < num_pfc; i++) {
pfc_tree = proto_tree_add_subtree_format(tree, tvb, curr_offset, pfc_len,
ett_bssgp_pfcs_to_be_set_up_list, NULL, "PFC (%u)", i + 1);
de_sm_pflow_id(tvb, pfc_tree, pinfo, curr_offset, 1, NULL, 0);
curr_offset++;
pft_tree = proto_tree_add_subtree(pfc_tree, tvb, curr_offset, 3,
ett_bssgp_pfcs_to_be_set_up_list_pft, NULL, "Packet Flow Timer(PFT)");
proto_tree_add_item(pft_tree, hf_bssgp_unit_val, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(pft_tree, hf_bssgp_gprs_timer, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
curr_offset += 3;
abqp_tree = proto_tree_add_subtree(pfc_tree, tvb, curr_offset, 3,
ett_bssgp_pfcs_to_be_set_up_list_abqp, NULL, "Aggregate BSS QoS Profile(ABQP)");
curr_offset = curr_offset + de_sm_qos(tvb, abqp_tree, pinfo, curr_offset, 16, NULL, 0);
if(pfc_len>17){
arp_tree = proto_tree_add_subtree(pfc_tree, tvb, curr_offset, 3,
ett_bssgp_pfcs_to_be_set_up_list_arp, NULL, "Allocation/Retention Priority");
curr_offset = curr_offset + be_prio(tvb, arp_tree, pinfo, curr_offset, 1, NULL, 0);
}
if(pfc_len>18){
t10_tree = proto_tree_add_subtree(pfc_tree, tvb, curr_offset, 3,
ett_bssgp_pfcs_to_be_set_up_list_t10, NULL, "T10");
proto_tree_add_item(t10_tree, hf_bssgp_unit_val, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(t10_tree, hf_bssgp_gprs_timer, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
curr_offset += 3;
}
}
return(curr_offset-offset);
}
static guint16
de_bssgp_list_of_setup_pfcs(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree *pfc_tree;
proto_item *pi;
guint32 curr_offset;
guint8 num_pfc, i;
curr_offset = offset;
num_pfc = tvb_get_guint8(tvb, curr_offset);
pi = proto_tree_add_text(tree, tvb, curr_offset, 1,
"Number of PFCs: ");
if (num_pfc < 12) {
proto_item_append_text(pi, "%u", num_pfc);
}else {
proto_item_append_text(pi, "Reserved");
return (curr_offset-offset);
}
curr_offset++;
if (num_pfc == 0)
return (curr_offset-offset);
for (i = 0; i < num_pfc; i++) {
pfc_tree = proto_tree_add_subtree_format(tree, tvb, curr_offset, 1,
ett_bssgp_list_of_setup_pfcs, NULL, "PFC (%u)", i + 1);
de_sm_pflow_id(tvb, pfc_tree, pinfo, curr_offset, 1, NULL, 0);
curr_offset++;
}
return(curr_offset-offset);
}
static guint16
de_bssgp_ext_feature_bitmap(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_gb_if, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bssgp_ps_ho, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_src_to_trg_transp_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_src_to_trg_transp_cont, tvb, curr_offset, len, ENC_NA);
return(len);
}
static guint16
de_bssgp_trg_to_src_transp_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_trg_to_src_transp_cont, tvb, curr_offset, len, ENC_NA);
return(len);
}
static guint16
de_bssgp_rnc_identifier(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint16 rnc_id;
curr_offset = offset;
curr_offset = curr_offset + de_gmm_rai(tvb, tree, pinfo, curr_offset, 6, add_string, string_len);
rnc_id = tvb_get_ntohs(tvb, curr_offset);
proto_tree_add_item(tree, hf_bssgp_rnc_id, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
if (add_string)
g_snprintf(add_string, string_len, " %s, RNC-ID %u", add_string, rnc_id);
return(curr_offset-offset);
}
static guint16
de_bssgp_page_mode(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_page_mode, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_container_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_container_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_global_tfi(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 bit_offset;
guint8 gtfi;
curr_offset = offset;
bit_offset = (curr_offset << 3) +3;
gtfi = tvb_get_bits8(tvb,bit_offset,1);
proto_tree_add_bits_item(tree, hf_bssgp_global_tfi, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if(gtfi == 0){
proto_tree_add_bits_item(tree, hf_bssgp_ul_tfi, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
}else{
proto_tree_add_bits_item(tree, hf_bssgp_dl_tfi, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
}
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_time_to_MBMS_data_tran(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 value;
curr_offset = offset;
value = tvb_get_guint8(tvb,curr_offset) + 1;
proto_tree_add_uint(tree, hf_bssgp_time_to_MBMS_data_tran, tvb, curr_offset, 1, value);
return(len);
}
static guint16
de_bssgp_mbms_session_rep_no(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_mbms_session_rep_no, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(len);
}
static guint16
de_bssgp_inter_rat_ho_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *new_tvb;
guint32 curr_offset;
curr_offset = offset;
new_tvb = tvb_new_subset_remaining(tvb, curr_offset);
dissect_rrc_InterRATHandoverInfo_PDU(new_tvb, pinfo, tree, NULL);
return(len);
}
static guint16
de_bssgp_ps_ho_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_ps_ho_cmd, tvb, curr_offset, len, ENC_NA);
return(len);
}
static guint16
de_bssgp_ps_ho_indications(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_sipsi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_sipsi_container(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 oct,num, type, i;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
num = oct >>1;
type = oct & 1;
proto_tree_add_text(tree, tvb, curr_offset, 1,
"Number of SI/PSI: %u",num);
proto_tree_add_item(tree, hf_bssgp_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if (type==0){
for (i = 0; i < num; i++) {
proto_tree_add_text(tree, tvb, curr_offset, 21, "SI (%u)", i + 1);
curr_offset+=21;
}
}else{
for (i = 0; i < num; i++) {
proto_tree_add_text(tree, tvb, curr_offset, 22, "PSI (%u)", i + 1);
curr_offset+=22;
}
}
return(curr_offset-offset);
}
static guint16
de_bssgp_active_pfcs_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree *pfc_tree;
proto_item *pi;
guint32 curr_offset;
guint8 num_pfc, i;
curr_offset = offset;
num_pfc = tvb_get_guint8(tvb, curr_offset);
pi = proto_tree_add_text(tree, tvb, curr_offset, 1,
"Number of PFCs: ");
if (num_pfc < 12) {
proto_item_append_text(pi, "%u", num_pfc);
}else {
proto_item_append_text(pi, "Reserved");
return (curr_offset-offset);
}
curr_offset++;
if (num_pfc == 0)
return (curr_offset-offset);
for (i = 0; i < num_pfc; i++) {
pfc_tree = proto_tree_add_subtree_format(tree, tvb, curr_offset, 1,
ett_bssgp_pfc_flow_control_parameters_pfc, NULL, "PFC (%u)", i + 1);
de_sm_pflow_id(tvb, pfc_tree, pinfo, curr_offset, 1, NULL, 0);
curr_offset++;
}
return(curr_offset-offset);
}
static guint16
de_bssgp_velocity_data(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string, int string_len)
{
guint32 curr_offset;
curr_offset = offset;
curr_offset = dissect_description_of_velocity(tvb, tree, pinfo, curr_offset, len, add_string, string_len);
return(curr_offset-offset);
}
static guint16
de_bssgp_dtm_ho_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len, "DTM Handover Command data");
return(len);
}
static guint16
de_bssgp_cs_indication(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_cs_indication, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_flow_control_gran(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_flow_control_gran, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_enb_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string, int string_len)
{
tvbuff_t *new_tvb;
guint32 curr_offset;
curr_offset = offset;
curr_offset = curr_offset+ de_emm_trac_area_id(tvb, tree, pinfo, curr_offset, 5, add_string, string_len);
new_tvb = tvb_new_subset_remaining(tvb, curr_offset);
dissect_s1ap_Global_ENB_ID_PDU(new_tvb, pinfo, tree, NULL);
return(len);
}
static guint16
de_bssgp_e_utran_inter_rat_ho_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *new_tvb;
guint32 curr_offset;
curr_offset = offset;
new_tvb = tvb_new_subset_remaining(tvb, curr_offset);
dissect_lte_rrc_UE_EUTRA_Capability_PDU(new_tvb, pinfo, tree, NULL);
return(len);
}
static guint16
de_bssgp_sub_prof_id_f_rat_freq_prio(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 value;
curr_offset = offset;
value = tvb_get_guint8(tvb,curr_offset) + 1;
proto_tree_add_uint(tree, hf_bssgp_sub_prof_id_f_rat_freq_prio, tvb, curr_offset, 1, value);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_req_for_inter_rat_ho_inf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_eutran_irat_ho_inf_req, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bssgp_irat_ho_inf_req, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_reliable_inter_rat_ho_inf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_rel_int_rat_ho_inf_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_son_transfer_app_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset _U_, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *next_tvb;
if(len > 0){
next_tvb = tvb_new_subset_length(tvb, offset, len);
dissect_s1ap_SONtransferApplicationIdentity_PDU(next_tvb, pinfo, tree, NULL);
}
return(len);
}
static guint16
de_bssgp_csg_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_csg_id, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset+=4;
proto_tree_add_item(tree, hf_bssgp_cell_acc_mode, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_bssgp_redir_attempt_flg(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, 1,"Spare");
curr_offset += 1;
return(curr_offset-offset);
}
static guint16
de_bssgp_redir_indication(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_redir_indiction_reroute_reject_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
return(curr_offset-offset);
}
static guint16
de_bssgp_redir_complete(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_bssgp_redir_complete_outcome, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
return(curr_offset-offset);
}
static guint16
de_bssgp_unconfim_send_state_var(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_item(tree, hf_bssgp_unconfim_send_state_var, tvb, offset, 2, ENC_BIG_ENDIAN);
return 2;
}
static guint16
de_bssgp_selected_plmn_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_string(tree, hf_bssgp_selected_plmn_id, tvb, offset, 3, dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, offset, TRUE));
return 3;
}
static guint16
de_bssgp_ran_inf_request_rim_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_RIM_APP_ID, BSSGP_PDU_TYPE, DE_BSSGP_RIM_APP_ID, NULL);
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_RIM_SEQUENCE_NUMBER, BSSGP_PDU_TYPE, DE_BSSGP_RIM_SEQ_NO, NULL);
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_RIM_PDU_INDICATIONS, BSSGP_PDU_TYPE, DE_BSSGP_RIM_PDU_INDICATIONS, NULL);
ELEM_IN_ELEM_OPT_TELV(BSSGP_IEI_RIM_PROTOCOL_VERSION, BSSGP_PDU_TYPE, DE_BSSGP_RIM_PROTO_VER_NO, NULL);
ELEM_IN_ELEM_OPT_TELV(BSSGP_IEI_RAN_INF_REQUEST_APP_CONTAINER, BSSGP_PDU_TYPE, DE_BSSGP_RAN_INFORMATION_REQUEST_APP_CONT, NULL);
ELEM_IN_ELEM_OPT_TELV(0x84, BSSGP_PDU_TYPE, DE_BSSGP_SON_TRANSFER_APP_ID, NULL);
return(curr_offset-offset);
}
static guint16
de_bssgp_ran_inf_rim_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_RIM_APP_ID, BSSGP_PDU_TYPE, DE_BSSGP_RIM_APP_ID, NULL);
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_RIM_SEQUENCE_NUMBER, BSSGP_PDU_TYPE, DE_BSSGP_RIM_SEQ_NO, NULL);
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_RIM_PDU_INDICATIONS, BSSGP_PDU_TYPE, DE_BSSGP_RIM_PDU_INDICATIONS, NULL);
ELEM_IN_ELEM_OPT_TELV(BSSGP_IEI_RIM_PROTOCOL_VERSION, BSSGP_PDU_TYPE, DE_BSSGP_RIM_PROTO_VER_NO, NULL);
ELEM_IN_ELEM_OPT_TELV(BSSGP_IEI_RAN_INF_APP_CONTAINER, BSSGP_PDU_TYPE, DE_BSSGP_RAN_INFORMATION_APP_CONT_UNIT, NULL);
ELEM_IN_ELEM_OPT_TELV(BSSGP_IEI_APPLICATION_ERROR_CONTAINER, BSSGP_PDU_TYPE, DE_BSSGP_RAN_APP_ERROR_CONT, NULL);
ELEM_IN_ELEM_OPT_TELV(0x84, BSSGP_PDU_TYPE, DE_BSSGP_SON_TRANSFER_APP_ID, NULL);
return(curr_offset-offset);
}
static guint16
de_bssgp_ran_inf_ack_rim_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_RIM_APP_ID, BSSGP_PDU_TYPE, DE_BSSGP_RIM_APP_ID, NULL);
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_RIM_SEQUENCE_NUMBER, BSSGP_PDU_TYPE, DE_BSSGP_RIM_SEQ_NO, NULL);
ELEM_IN_ELEM_OPT_TELV(BSSGP_IEI_RIM_PROTOCOL_VERSION, BSSGP_PDU_TYPE, DE_BSSGP_RIM_PROTO_VER_NO, NULL);
ELEM_IN_ELEM_OPT_TELV(0x84, BSSGP_PDU_TYPE, DE_BSSGP_SON_TRANSFER_APP_ID, NULL);
return(curr_offset-offset);
}
static guint16
de_bssgp_ran_inf_error_rim_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_RIM_APP_ID, BSSGP_PDU_TYPE, DE_BSSGP_RIM_APP_ID, NULL);
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_CAUSE,BSSGP_PDU_TYPE, DE_BSSGP_CAUSE, " - RIM");
ELEM_IN_ELEM_OPT_TELV(BSSGP_IEI_RIM_PROTOCOL_VERSION, BSSGP_PDU_TYPE, DE_BSSGP_RIM_PROTO_VER_NO, NULL);
ELEM_IN_ELEM_MAND_TELV(0x15, BSSGP_PDU_TYPE, DE_BSSGP_PDU_IN_ERROR , NULL);
ELEM_IN_ELEM_OPT_TELV(0x84, BSSGP_PDU_TYPE, DE_BSSGP_SON_TRANSFER_APP_ID, NULL);
return(curr_offset-offset);
}
static guint16
de_bssgp_ran_inf_app_error_rim_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_RIM_APP_ID, BSSGP_PDU_TYPE, DE_BSSGP_RIM_APP_ID, NULL);
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_RIM_SEQUENCE_NUMBER, BSSGP_PDU_TYPE, DE_BSSGP_RIM_SEQ_NO, NULL);
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_RIM_PDU_INDICATIONS, BSSGP_PDU_TYPE, DE_BSSGP_RIM_PDU_INDICATIONS, NULL);
ELEM_IN_ELEM_OPT_TELV(BSSGP_IEI_RIM_PROTOCOL_VERSION, BSSGP_PDU_TYPE, DE_BSSGP_RIM_PROTO_VER_NO, NULL);
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_APPLICATION_ERROR_CONTAINER, BSSGP_PDU_TYPE, DE_BSSGP_RAN_APP_ERROR_CONT, NULL);
ELEM_IN_ELEM_OPT_TELV(0x84, BSSGP_PDU_TYPE, DE_BSSGP_SON_TRANSFER_APP_ID, NULL);
return(curr_offset-offset);
}
guint16
de_bssgp_source_BSS_to_target_BSS_transp_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_MS_RADIO_ACCESS_CAPABILITY, GSM_A_PDU_TYPE_GM, DE_MS_RAD_ACC_CAP , NULL);
ELEM_IN_ELEM_OPT_TELV(0x73, BSSGP_PDU_TYPE, DE_BSSGP_INTER_RAT_HO_INFO, NULL);
ELEM_IN_ELEM_OPT_TELV(0x6d, BSSGP_PDU_TYPE, DE_BSSGP_PAGE_MODE, NULL);
ELEM_IN_ELEM_OPT_TELV(0x6e, BSSGP_PDU_TYPE, DE_BSSGP_CONTAINER_ID, NULL);
ELEM_IN_ELEM_OPT_TELV(0x6f, BSSGP_PDU_TYPE, DE_BSSGP_GLOBAL_TFI, NULL);
ELEM_IN_ELEM_OPT_TELV(0x75, BSSGP_PDU_TYPE, DE_BSSGP_PS_HO_INDICATIONS, NULL);
ELEM_IN_ELEM_OPT_TELV(0x7a, BSSGP_PDU_TYPE, DE_BSSGP_CS_INDICATION, NULL);
ELEM_IN_ELEM_OPT_TELV(0x80, BSSGP_PDU_TYPE, DE_BSSGP_E_UTRAN_INTER_RAT_HO_INFO, NULL);
return(curr_offset-offset);
}
guint16
de_bssgp_target_BSS_to_source_BSS_transp_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_IN_ELEM_OPT_TELV(0x74, BSSGP_PDU_TYPE, DE_BSSGP_PS_HO_CMD, NULL);
ELEM_IN_ELEM_OPT_TELV(0x76, BSSGP_PDU_TYPE, DE_BSSGP_SIPSI_CONTAINER, NULL);
ELEM_IN_ELEM_OPT_TELV(0x79, BSSGP_PDU_TYPE, DE_BBSGP_DTM_HO_CMD, NULL);
return(curr_offset-offset);
}
static void
bssgp_dl_unitdata(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_TLLI, " - current");
ELEM_MAND_V(BSSGP_PDU_TYPE, DE_BSSGP_QOS_PROFILE, NULL);
ELEM_MAND_TELV(0x16, BSSGP_PDU_TYPE, DE_BSSGP_PDU_LIFETIME, NULL);
ELEM_OPT_TELV(BSSGP_IEI_MS_RADIO_ACCESS_CAPABILITY, GSM_A_PDU_TYPE_GM, DE_MS_RAD_ACC_CAP , NULL);
ELEM_OPT_TELV(0x17, GSM_A_PDU_TYPE_BSSMAP, BE_PRIO, NULL);
ELEM_OPT_TELV(0x0a , GSM_A_PDU_TYPE_GM, DE_DRX_PARAM , NULL);
ELEM_OPT_TELV(BSSGP_IEI_IMSI, BSSGP_PDU_TYPE, DE_BSSGP_IMSI , NULL);
ELEM_OPT_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , " - old");
ELEM_OPT_TELV( BSSGP_IEI_PFI , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL);
ELEM_OPT_TELV(0x27, GSM_A_PDU_TYPE_BSSMAP, BE_LSA_INFO, NULL);
ELEM_OPT_TELV(BSSGP_IEI_SERVICE_UTRAN_CCO, BSSGP_PDU_TYPE, DE_BSSGP_SERV_UTRAN_CCO, NULL);
ELEM_OPT_TELV(0x81, BSSGP_PDU_TYPE, DE_BSSGP_SUB_PROF_ID_F_RAT_FRQ_PRIO, NULL);
ELEM_OPT_TELV(BSSGP_IEI_REDIR_INDICATION, BSSGP_PDU_TYPE, DE_BSSGP_REDIR_INDICATION, NULL);
ELEM_OPT_TELV(BSSGP_IEI_REDIR_COMPLETE, BSSGP_PDU_TYPE, DE_BSSGP_REDIR_COMPLETE, NULL);
ELEM_OPT_TELV(BSSGP_IEI_UNCONFIRM_SEND_STATE_VAR, BSSGP_PDU_TYPE, DE_BSSGP_UNCONFIRM_SEND_STATE_VAR, NULL);
ELEM_OPT_TELV(0x00, BSSGP_PDU_TYPE, DE_BSSGP_ALIGNMENT_OCTETS, NULL);
ELEM_MAND_TELV(0x0e, BSSGP_PDU_TYPE, DE_BSSGP_LLC_PDU, NULL);
ELEM_OPT_TELV(0x0e, BSSGP_PDU_TYPE, DE_BSSGP_LLC_PDU, " - initial");
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ul_unitdata(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_TLLI, NULL);
ELEM_MAND_V(BSSGP_PDU_TYPE, DE_BSSGP_QOS_PROFILE, NULL);
ELEM_OPT_TELV(BSSGP_IEI_CELL_IDENTIFIER, BSSGP_PDU_TYPE, DE_BSSGP_CELL_ID , NULL);
ELEM_OPT_TELV(BSSGP_IEI_PFI , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL);
ELEM_OPT_TELV(0x26, GSM_A_PDU_TYPE_BSSMAP, BE_LSA_ID_LIST, NULL);
ELEM_OPT_TELV(BSSGP_IEI_REDIR_ATTEMP_FLG, BSSGP_PDU_TYPE, DE_BSSGP_REDIR_ATTEMPT_FLG, NULL);
ELEM_OPT_TELV(BSSGP_IEI_IMSI, BSSGP_PDU_TYPE, DE_BSSGP_IMSI , NULL);
ELEM_OPT_TELV(BSSGP_IEI_UNCONFIRM_SEND_STATE_VAR, BSSGP_PDU_TYPE, DE_BSSGP_UNCONFIRM_SEND_STATE_VAR, NULL);
ELEM_OPT_TELV(BSSGP_IEI_SELECTED_PLMN_ID, BSSGP_PDU_TYPE, DE_BSSGP_SELECTED_PLMN_ID, NULL);
ELEM_OPT_TELV(0x00, BSSGP_PDU_TYPE, DE_BSSGP_ALIGNMENT_OCTETS, NULL);
ELEM_MAND_TELV(0x0e, BSSGP_PDU_TYPE, DE_BSSGP_LLC_PDU, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ra_cap(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_MS_RADIO_ACCESS_CAPABILITY, GSM_A_PDU_TYPE_GM, DE_MS_RAD_ACC_CAP , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_dl_mbms_unitdata(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(0x16, BSSGP_PDU_TYPE, DE_BSSGP_PDU_LIFETIME, NULL);
ELEM_MAND_TELV(0x5c, GSM_A_PDU_TYPE_GM, DE_TMGI, NULL);
ELEM_OPT_TELV(0x5d, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SESSION_ID, NULL);
ELEM_OPT_TELV(0x00, BSSGP_PDU_TYPE, DE_BSSGP_ALIGNMENT_OCTETS, NULL);
ELEM_MAND_TELV(0x0e, BSSGP_PDU_TYPE, DE_BSSGP_LLC_PDU, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ul_mbms_unitdata(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(0x5c, GSM_A_PDU_TYPE_GM, DE_TMGI, NULL);
ELEM_OPT_TELV(0x5d, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SESSION_ID, NULL);
ELEM_OPT_TELV(0x00, BSSGP_PDU_TYPE, DE_BSSGP_ALIGNMENT_OCTETS, NULL);
ELEM_MAND_TELV(0x0e, BSSGP_PDU_TYPE, DE_BSSGP_LLC_PDU, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_paging_ps(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_IMSI, BSSGP_PDU_TYPE, DE_BSSGP_IMSI , NULL);
ELEM_OPT_TELV(0x0a , GSM_A_PDU_TYPE_GM, DE_DRX_PARAM , NULL);
ELEM_OPT_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , NULL);
ELEM_OPT_TELV(0x10,GSM_A_PDU_TYPE_COMMON, DE_LAI, NULL);
ELEM_OPT_TELV(0x1b,GSM_A_PDU_TYPE_GM, DE_RAI, NULL);
ELEM_OPT_TELV(0x02,BSSGP_PDU_TYPE, DE_BSSGP_BSS_AREA_IND, NULL);
ELEM_OPT_TELV(BSSGP_IEI_PFI , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL);
ELEM_OPT_TELV(0x3a , GSM_A_PDU_TYPE_GM, DE_QOS , NULL);
ELEM_MAND_TELV(0x18,BSSGP_PDU_TYPE, DE_BSSGP_QOS_PROFILE, NULL);
ELEM_OPT_TELV(BSSGP_IEI_TMSI,GSM_A_PDU_TYPE_RR, DE_RR_TMSI_PTMSI, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_paging_cs(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_IMSI, BSSGP_PDU_TYPE, DE_BSSGP_IMSI , NULL);
ELEM_MAND_TELV(0x0a , GSM_A_PDU_TYPE_GM, DE_DRX_PARAM , NULL);
ELEM_OPT_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , NULL);
ELEM_OPT_TELV(0x10,GSM_A_PDU_TYPE_COMMON, DE_LAI, NULL);
ELEM_OPT_TELV(0x1b,GSM_A_PDU_TYPE_GM, DE_RAI, NULL);
ELEM_OPT_TELV(0x02,BSSGP_PDU_TYPE, DE_BSSGP_BSS_AREA_IND, NULL);
ELEM_OPT_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_OPT_TELV(0x09, BSSGP_PDU_TYPE, DE_BSSGP_CHLN_NEEDED , NULL);
ELEM_OPT_TELV(0x0b, GSM_A_PDU_TYPE_BSSMAP, BE_EMLPP_PRIO, NULL);
ELEM_OPT_TELV(BSSGP_IEI_TMSI,GSM_A_PDU_TYPE_RR, DE_RR_TMSI_PTMSI, NULL);
ELEM_OPT_TELV(0x53, SGSAP_PDU_TYPE, DE_SGSAP_GLOBAL_CN_ID, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ra_cap_upd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_TAG, BSSGP_PDU_TYPE, DE_BSSGP_TAG , NULL);
ELEM_OPT_TELV(BSSGP_IEI_IMSI, BSSGP_PDU_TYPE, DE_BSSGP_IMSI , NULL);
ELEM_OPT_TELV(BSSGP_IEI_RA_CAP_UPD_CAUSE, BSSGP_PDU_TYPE, DE_BSSGP_RA_CAP_UPD_CAUSE , NULL);
ELEM_OPT_TELV(BSSGP_IEI_MS_RADIO_ACCESS_CAPABILITY, GSM_A_PDU_TYPE_GM, DE_MS_RAD_ACC_CAP , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ra_cap_upd_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_TAG, BSSGP_PDU_TYPE, DE_BSSGP_TAG , NULL);
ELEM_OPT_TELV(BSSGP_IEI_IMSI, BSSGP_PDU_TYPE, DE_BSSGP_IMSI , NULL);
ELEM_OPT_TELV(BSSGP_IEI_RA_CAP_UPD_CAUSE, BSSGP_PDU_TYPE, DE_BSSGP_RA_CAP_UPD_CAUSE , NULL);
ELEM_OPT_TELV(BSSGP_IEI_MS_RADIO_ACCESS_CAPABILITY, GSM_A_PDU_TYPE_GM, DE_MS_RAD_ACC_CAP , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ra_status(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_OPT_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_OPT_TELV(BSSGP_IEI_TMSI,GSM_A_PDU_TYPE_RR, DE_RR_TMSI_PTMSI, NULL);
ELEM_OPT_TELV(BSSGP_IEI_IMSI, BSSGP_PDU_TYPE, DE_BSSGP_IMSI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_RADIO_CAUSE, BSSGP_PDU_TYPE, DE_BSSGP_RA_CAUSE , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_suspend(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(0x1b,GSM_A_PDU_TYPE_GM, DE_RAI, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
void
bssgp_suspend_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(0x1b,GSM_A_PDU_TYPE_GM, DE_RAI, NULL);
ELEM_MAND_TELV(0x1d,BSSGP_PDU_TYPE, DE_BBSGP_SUSPEND_REF_NO, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_suspend_nack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(0x1b,GSM_A_PDU_TYPE_GM, DE_RAI, NULL);
ELEM_MAND_TELV(BSSGP_IEI_CAUSE,BSSGP_PDU_TYPE, DE_BSSGP_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_resume(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(0x1b,GSM_A_PDU_TYPE_GM, DE_RAI, NULL);
ELEM_MAND_TELV(0x1d,BSSGP_PDU_TYPE, DE_BBSGP_SUSPEND_REF_NO, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_resume_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(0x1b,GSM_A_PDU_TYPE_GM, DE_RAI, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_resume_nack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(0x1b,GSM_A_PDU_TYPE_GM, DE_RAI, NULL);
ELEM_OPT_TELV(BSSGP_IEI_CAUSE,BSSGP_PDU_TYPE, DE_BSSGP_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_flush_ll(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , " - Old");
ELEM_OPT_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , " - New");
ELEM_OPT_TELV(0x3e, GSM_A_PDU_TYPE_RR, DE_BSSGP_NSEI , " - New");
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_flush_ll_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(0x0c, BSSGP_PDU_TYPE, DE_BSSGP_FLUSH_ACTION , NULL);
ELEM_OPT_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , " - New");
ELEM_MAND_TELV(BSSGP_IEI_NUMBER_OF_OCTETS_AFFECTED, BSSGP_PDU_TYPE, DE_BSSGP_NO_OF_OCT_AFFECTED , NULL);
ELEM_OPT_TELV(0x3e, GSM_A_PDU_TYPE_RR, DE_BSSGP_NSEI , " - New");
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_llc_discarded(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_LLC_FRAMES_DISCARDED, BSSGP_PDU_TYPE, DE_BSSGP_LLC_FRAMES_DISC , NULL);
ELEM_MAND_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_NUMBER_OF_OCTETS_AFFECTED, BSSGP_PDU_TYPE, DE_BSSGP_NO_OF_OCT_AFFECTED , NULL);
ELEM_OPT_TELV(BSSGP_IEI_PFI , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_flow_control_bvc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TAG, BSSGP_PDU_TYPE, DE_BSSGP_TAG , NULL);
ELEM_MAND_TELV(0x05, BSSGP_PDU_TYPE, DE_BSSGP_BVC_BUCKET_SIZE , NULL);
ELEM_MAND_TELV(BSSGP_IEI_BUCKET_LEAK_RATE, BSSGP_PDU_TYPE, DE_BSSGP_BUCKET_LEAK_RATE , NULL);
ELEM_MAND_TELV(0x01, BSSGP_PDU_TYPE, DE_BSSGP_BMAX_DEFAULT_MS , NULL);
ELEM_MAND_TELV(0x1c, BSSGP_PDU_TYPE, DE_BSSGP_R_DEFAULT_MS , NULL);
ELEM_OPT_TELV(BSSGP_IEI_BUCKET_FULL_RATIO, BSSGP_PDU_TYPE, DE_BSSGP_BUCKET_FULL_RATIO , NULL);
ELEM_OPT_TELV(0x06, BSSGP_PDU_TYPE, DE_BSSGP_BVC_MEAS , NULL);
ELEM_OPT_TELV(0x7e, BSSGP_PDU_TYPE, DE_BSSGP_FLOW_CONTROL_GRAN , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_flow_control_bvc_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TAG, BSSGP_PDU_TYPE, DE_BSSGP_TAG , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_flow_control_ms(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_TAG, BSSGP_PDU_TYPE, DE_BSSGP_TAG , NULL);
ELEM_MAND_TELV(BSSGP_IEI_MS_BUCKET_SIZE, BSSGP_PDU_TYPE, DE_BSSGP_MS_BUCKET_SIZE , NULL);
ELEM_MAND_TELV(BSSGP_IEI_BUCKET_LEAK_RATE, BSSGP_PDU_TYPE, DE_BSSGP_BUCKET_LEAK_RATE , NULL);
ELEM_OPT_TELV(BSSGP_IEI_BUCKET_FULL_RATIO, BSSGP_PDU_TYPE, DE_BSSGP_BUCKET_FULL_RATIO , NULL);
ELEM_OPT_TELV(0x7e, BSSGP_PDU_TYPE, DE_BSSGP_FLOW_CONTROL_GRAN , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_flow_control_ms_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_TAG, BSSGP_PDU_TYPE, DE_BSSGP_TAG , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_bvc_block(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_CAUSE,BSSGP_PDU_TYPE, DE_BSSGP_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_bvc_block_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_bvc_un_block(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_bvc_un_block_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_bvc_reset(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_CAUSE,BSSGP_PDU_TYPE, DE_BSSGP_CAUSE, NULL);
ELEM_OPT_TELV(BSSGP_IEI_CELL_IDENTIFIER, BSSGP_PDU_TYPE, DE_BSSGP_CELL_ID , NULL);
ELEM_OPT_TELV(0x3b, BSSGP_PDU_TYPE, DE_BSSGP_FEATURE_BITMAP , NULL);
ELEM_OPT_TELV(0x69, BSSGP_PDU_TYPE, DE_BSSGP_EXT_FEATURE_BITMAP , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_bvc_reset_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , NULL);
ELEM_OPT_TELV(BSSGP_IEI_CELL_IDENTIFIER, BSSGP_PDU_TYPE, DE_BSSGP_CELL_ID , NULL);
ELEM_OPT_TELV(0x3b, BSSGP_PDU_TYPE, DE_BSSGP_FEATURE_BITMAP , NULL);
ELEM_OPT_TELV(0x69, BSSGP_PDU_TYPE, DE_BSSGP_EXT_FEATURE_BITMAP , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_status(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TELV(BSSGP_IEI_CAUSE,BSSGP_PDU_TYPE, DE_BSSGP_CAUSE, NULL);
ELEM_MAND_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , NULL);
ELEM_MAND_TELV(0x15, BSSGP_PDU_TYPE, DE_BSSGP_PDU_IN_ERROR , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_sgsn_invoke_trace(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(0x22, BSSGP_PDU_TYPE, DE_BSSGP_TRACE_TYPE , NULL);
ELEM_MAND_TELV(0x21, BSSGP_PDU_TYPE, DE_BSSGP_TRACE_REF , NULL);
ELEM_OPT_TELV(0x24, BSSGP_PDU_TYPE, DE_BSSGP_TRIGGER_ID , NULL);
ELEM_OPT_TELV(0x11,GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
ELEM_OPT_TELV(0x14,GSM_A_PDU_TYPE_COMMON, DE_BSSGP_OMC_ID, NULL);
ELEM_OPT_TELV(0x23, BSSGP_PDU_TYPE, DE_BSSGP_TRANSACTION_ID , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_download_bss_pfc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_PFI , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_create_bss_pfc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_OPT_TELV(BSSGP_IEI_IMSI, BSSGP_PDU_TYPE, DE_BSSGP_IMSI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_PFI , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL);
ELEM_MAND_TELV(0x29, BSSGP_PDU_TYPE, DE_BSSGP_GPRS_TIMER , " - PFT");
ELEM_MAND_TELV(0x3a , GSM_A_PDU_TYPE_GM, DE_QOS , NULL);
ELEM_OPT_TELV(BSSGP_IEI_SERVICE_UTRAN_CCO, BSSGP_PDU_TYPE, DE_BSSGP_SERV_UTRAN_CCO, NULL);
ELEM_OPT_TELV(BSSGP_IEI_MS_RADIO_ACCESS_CAPABILITY, GSM_A_PDU_TYPE_GM, DE_MS_RAD_ACC_CAP , NULL);
ELEM_OPT_TELV(0x17, GSM_A_PDU_TYPE_BSSMAP, BE_PRIO, NULL);
ELEM_MAND_TELV(BSSGP_IEI_GPRS_TIMER, BSSGP_PDU_TYPE, DE_BSSGP_GPRS_TIMER , " - T10");
ELEM_OPT_TELV(0x73, BSSGP_PDU_TYPE, DE_BSSGP_INTER_RAT_HO_INFO, NULL);
ELEM_OPT_TELV(0x80, BSSGP_PDU_TYPE, DE_BSSGP_E_UTRAN_INTER_RAT_HO_INFO, NULL);
ELEM_OPT_TELV(0x81, BSSGP_PDU_TYPE, DE_BSSGP_SUB_PROF_ID_F_RAT_FRQ_PRIO, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_create_bss_pfc_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_PFI , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL);
ELEM_MAND_TELV(0x3a , GSM_A_PDU_TYPE_GM, DE_QOS , NULL);
ELEM_OPT_TELV(BSSGP_IEI_CAUSE,BSSGP_PDU_TYPE, DE_BSSGP_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_create_bss_pfc_nack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_PFI , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL);
ELEM_MAND_TELV(BSSGP_IEI_CAUSE,BSSGP_PDU_TYPE, DE_BSSGP_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_modify_bss_pfc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_PFI , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL);
ELEM_MAND_TELV(0x3a , GSM_A_PDU_TYPE_GM, DE_QOS , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_modify_bss_pfc_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_PFI , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL);
ELEM_MAND_TELV(BSSGP_IEI_GPRS_TIMER, BSSGP_PDU_TYPE, DE_BSSGP_GPRS_TIMER , " - PFT");
ELEM_MAND_TELV(0x3a , GSM_A_PDU_TYPE_GM, DE_QOS , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_delete_bss_pfc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_PFI , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_delete_bss_pfc_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_PFI , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_flow_cntrl_pfc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_TAG, BSSGP_PDU_TYPE, DE_BSSGP_TAG , NULL);
ELEM_OPT_TELV(BSSGP_IEI_MS_BUCKET_SIZE, BSSGP_PDU_TYPE, DE_BSSGP_MS_BUCKET_SIZE , NULL);
ELEM_OPT_TELV(0x3b, BSSGP_PDU_TYPE, DE_BSSGP_FEATURE_BITMAP , NULL);
ELEM_OPT_TELV(BSSGP_IEI_BUCKET_FULL_RATIO, BSSGP_PDU_TYPE, DE_BSSGP_BUCKET_FULL_RATIO , NULL);
ELEM_MAND_TELV(0x52, BSSGP_PDU_TYPE, DE_BSSGP_PFC_FLOW_CTRL , NULL);
ELEM_OPT_TELV(0x7e, BSSGP_PDU_TYPE, DE_BSSGP_FLOW_CONTROL_GRAN , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_flow_cntrl_pfc_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_TAG, BSSGP_PDU_TYPE, DE_BSSGP_TAG , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_delete_bss_pfc_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_PFI , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL);
ELEM_MAND_TELV(BSSGP_IEI_CAUSE,BSSGP_PDU_TYPE, DE_BSSGP_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ps_ho_required(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_CAUSE,BSSGP_PDU_TYPE, DE_BSSGP_CAUSE, NULL);
ELEM_MAND_TELV(BSSGP_IEI_CELL_IDENTIFIER, BSSGP_PDU_TYPE, DE_BSSGP_CELL_ID , " - Source");
ELEM_OPT_TELV(BSSGP_IEI_CELL_IDENTIFIER, BSSGP_PDU_TYPE, DE_BSSGP_CELL_ID , " - Target");
ELEM_OPT_TELV(0x64,BSSGP_PDU_TYPE, DE_BSSGP_SOURCE_BSS_TO_TARGET_BSS_TRANSP_CONT, NULL);
ELEM_OPT_TELV(0x6c,BSSGP_PDU_TYPE, BE_BSSGP_RNC_ID, " - Target");
ELEM_OPT_TELV(0x6a,BSSGP_PDU_TYPE, DE_BSSGP_SRC_TO_TRG_TRANSP_CONT, NULL);
ELEM_OPT_TELV(0x77,BSSGP_PDU_TYPE, DE_BSSGP_ACTIVE_PFCS_LIST, NULL);
ELEM_OPT_TELV(0x7f,BSSGP_PDU_TYPE, DE_BSSGP_ENB_ID, " - Target");
ELEM_OPT_TELV(0x83,BSSGP_PDU_TYPE, DE_BSSGP_RELIABLE_INTER_RAT_HO_INF, NULL);
ELEM_OPT_TELV(0x85,BSSGP_PDU_TYPE, DE_BSSGP_CSG_ID, NULL);
ELEM_OPT_TELV(0x86, NAS_PDU_TYPE_EMM, DE_EMM_TRAC_AREA_ID, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ps_ho_required_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(0x68,BSSGP_PDU_TYPE, DE_BSSGP_LIST_OF_SETUP_PFCS, NULL);
ELEM_MAND_TELV(0x65,BSSGP_PDU_TYPE, DE_BSSGP_TARGET_BSS_TO_SOURCE_BSS_TRANSP_CONT, NULL);
ELEM_MAND_TELV(0x6b,BSSGP_PDU_TYPE, DE_BSSGP_TRG_TO_SRC_TRANSP_CONT, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ps_ho_required_nack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_CAUSE,BSSGP_PDU_TYPE, DE_BSSGP_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ps_ho_request(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_IMSI, BSSGP_PDU_TYPE, DE_BSSGP_IMSI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_CAUSE,BSSGP_PDU_TYPE, DE_BSSGP_CAUSE, NULL);
ELEM_OPT_TELV(BSSGP_IEI_CELL_IDENTIFIER, BSSGP_PDU_TYPE, DE_BSSGP_CELL_ID , " - Source");
ELEM_OPT_TELV(0x6c,BSSGP_PDU_TYPE, BE_BSSGP_RNC_ID, " - Source");
ELEM_OPT_TELV(BSSGP_IEI_CELL_IDENTIFIER, BSSGP_PDU_TYPE, DE_BSSGP_CELL_ID , " - Target");
ELEM_OPT_TELV(0x64,BSSGP_PDU_TYPE, DE_BSSGP_SOURCE_BSS_TO_TARGET_BSS_TRANSP_CONT, NULL);
ELEM_OPT_TELV(0x67,BSSGP_PDU_TYPE, DE_BSSGP_PFCS_TO_BE_SET_UP_LIST, NULL);
ELEM_OPT_TELV(0x66,GSM_A_PDU_TYPE_COMMON, DE_NAS_CONT_FOR_PS_HO, NULL);
ELEM_OPT_TELV(BSSGP_IEI_SERVICE_UTRAN_CCO, BSSGP_PDU_TYPE, DE_BSSGP_SERV_UTRAN_CCO, NULL);
ELEM_OPT_TELV(0x81, BSSGP_PDU_TYPE, DE_BSSGP_SUB_PROF_ID_F_RAT_FRQ_PRIO, NULL);
ELEM_OPT_TELV(0x83,BSSGP_PDU_TYPE, DE_BSSGP_RELIABLE_INTER_RAT_HO_INF, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ps_ho_request_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(0x68,BSSGP_PDU_TYPE, DE_BSSGP_LIST_OF_SETUP_PFCS, NULL);
ELEM_MAND_TELV(0x65,BSSGP_PDU_TYPE, DE_BSSGP_TARGET_BSS_TO_SOURCE_BSS_TRANSP_CONT, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ps_ho_request_nack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_CAUSE,BSSGP_PDU_TYPE, DE_BSSGP_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ps_ho_complete(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_IMSI, BSSGP_PDU_TYPE, DE_BSSGP_IMSI , NULL);
ELEM_OPT_TELV(BSSGP_IEI_CELL_IDENTIFIER, BSSGP_PDU_TYPE, DE_BSSGP_CELL_ID , " - Target");
ELEM_OPT_TELV(0x82, BSSGP_PDU_TYPE, DE_BSSGP_REQ_FOR_INTER_RAT_HO_INFO , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ps_ho_cancel(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_IN_ELEM_MAND_TELV(BSSGP_IEI_CAUSE,BSSGP_PDU_TYPE, DE_BSSGP_CAUSE, NULL);
ELEM_OPT_TELV(BSSGP_IEI_CELL_IDENTIFIER, BSSGP_PDU_TYPE, DE_BSSGP_CELL_ID , " - Source");
ELEM_OPT_TELV(BSSGP_IEI_CELL_IDENTIFIER, BSSGP_PDU_TYPE, DE_BSSGP_CELL_ID , " - Target");
ELEM_OPT_TELV(0x6c,BSSGP_PDU_TYPE, BE_BSSGP_RNC_ID, " - Target");
ELEM_OPT_TELV(0x7f,BSSGP_PDU_TYPE, DE_BSSGP_ENB_ID, " - Target");
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ps_ho_complete_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_OPT_TELV(0x73, BSSGP_PDU_TYPE, DE_BSSGP_INTER_RAT_HO_INFO, NULL);
ELEM_OPT_TELV(0x80, BSSGP_PDU_TYPE, DE_BSSGP_E_UTRAN_INTER_RAT_HO_INFO, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_perform_loc_request(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_IMSI, BSSGP_PDU_TYPE, DE_BSSGP_IMSI , NULL);
ELEM_OPT_TELV(0x86, NAS_PDU_TYPE_EMM, DE_EMM_TRAC_AREA_ID, NULL);
ELEM_MAND_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , " - (PCU-PTP)");
ELEM_OPT_TELV(0x3e, GSM_A_PDU_TYPE_RR, DE_BSSGP_NSEI , " - (PCU-PTP)");
ELEM_OPT_TELV(0x7c, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_GANSS_LOC_TYPE, NULL);
ELEM_OPT_TELV(BSSGP_IEI_CELL_IDENTIFIER, BSSGP_PDU_TYPE, DE_BSSGP_CELL_ID , NULL);
ELEM_OPT_TELV( BSSGP_IEI_LCS_CAPABILITY , GSM_A_PDU_TYPE_GM, DE_PS_LCS_CAP , NULL);
ELEM_OPT_TELV(BSSGP_IEI_LCS_PRIORITY, GSM_A_PDU_TYPE_BSSMAP, BE_LCS_PRIO, NULL);
ELEM_OPT_TELV(BSSGP_IEI_LCS_QOS, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_LCSQOS, NULL);
ELEM_OPT_TELV(BSSGP_IEI_LCS_CLIENT_TYPE, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_LCS_CLIENT_TYPE, NULL);
ELEM_OPT_TELV(BSSGP_IEI_REQUESTED_GPS_ASSISTANCE_DATA, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_REQ_GPS_ASSIST_D, NULL);
ELEM_OPT_TELV(0x70,GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
ELEM_OPT_TELV(0x7c, GSM_A_PDU_TYPE_BSSMAP, BE_GANSS_LOC_TYP, NULL);
ELEM_OPT_TLV(0x7b, GSM_A_PDU_TYPE_BSSMAP, BE_GANSS_ASS_DTA, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_perform_loc_response(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , " - (PCU-PTP)");
ELEM_OPT_TELV(BSSGP_IEI_LOCATION_ESTIMATE, GSM_A_PDU_TYPE_BSSMAP, BE_LOC_EST, NULL);
ELEM_OPT_TELV(0x7d, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_POS_DATA, NULL);
ELEM_OPT_TELV(BSSGP_IEI_DECIPHERING_KEYS, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_DECIPH_KEYS, NULL);
ELEM_OPT_TELV(BSSGP_IEI_LCS_CAUSE, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_LCS_CAUSE, NULL);
ELEM_MAND_TELV(0x78, BSSGP_PDU_TYPE, DE_BSSGP_VELOCITY_DATA , NULL);
ELEM_OPT_TELV(0x7d, GSM_A_PDU_TYPE_BSSMAP, BE_GANSS_POS_DTA, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_perform_loc_response_abort(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , " - (PCU-PTP)");
ELEM_MAND_TELV(BSSGP_IEI_LCS_CAUSE, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_LCS_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_pos_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , " - (PCU-PTP)");
ELEM_MAND_TELV(BSSGP_IEI_RRLP_FLAGS, BSSGP_PDU_TYPE, DE_BSSGP_RRLP_FLAGS , NULL);
ELEM_MAND_TELV(BSSGP_IEI_RRLP_APDU, BSSGP_PDU_TYPE, DE_BSSGP_RRLP_APDU , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_pos_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(BSSGP_IEI_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI , NULL);
ELEM_MAND_TELV(BSSGP_IEI_BVCI, BSSGP_PDU_TYPE, DE_BSSGP_BVCI , " - (PCU-PTP)");
ELEM_OPT_TELV(BSSGP_IEI_RRLP_FLAGS, BSSGP_PDU_TYPE, DE_BSSGP_RRLP_FLAGS , NULL);
ELEM_OPT_TELV(BSSGP_IEI_RRLP_APDU, BSSGP_PDU_TYPE, DE_BSSGP_RRLP_APDU , NULL);
ELEM_OPT_TELV(BSSGP_IEI_LCS_CAUSE, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_LCS_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ran_inf_request(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TELV(BSSGP_IEI_RIM_ROUTING_INFORMATION, BSSGP_PDU_TYPE, DE_BSSGP_RIM_ROUTING_INF , " - Destination Cell Identifier");
ELEM_MAND_TELV(BSSGP_IEI_RIM_ROUTING_INFORMATION, BSSGP_PDU_TYPE, DE_BSSGP_RIM_ROUTING_INF , " - Source Cell Identifier");
ELEM_OPT_TELV(BSSGP_IEI_RAN_INF_REQUEST_RIM_CONTAINER, BSSGP_PDU_TYPE, DE_BSSGP_RAN_INF_REQUEST_RIM_CONT, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ran_inf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TELV(BSSGP_IEI_RIM_ROUTING_INFORMATION, BSSGP_PDU_TYPE, DE_BSSGP_RIM_ROUTING_INF , " - Destination Cell Identifier");
ELEM_MAND_TELV(BSSGP_IEI_RIM_ROUTING_INFORMATION, BSSGP_PDU_TYPE, DE_BSSGP_RIM_ROUTING_INF , " - Source Cell Identifier");
ELEM_MAND_TELV(BSSGP_IEI_RAN_INF_RIM_CONTAINER, BSSGP_PDU_TYPE, DE_BSSGP_RAN_INF_RIM_CONT , " - Source Cell Identifier");
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ran_inf_request_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TELV(BSSGP_IEI_RIM_ROUTING_INFORMATION, BSSGP_PDU_TYPE, DE_BSSGP_RIM_ROUTING_INF , " - Destination Cell Identifier");
ELEM_MAND_TELV(BSSGP_IEI_RIM_ROUTING_INFORMATION, BSSGP_PDU_TYPE, DE_BSSGP_RIM_ROUTING_INF , " - Source Cell Identifier");
ELEM_MAND_TELV(BSSGP_IEI_RAN_INF_ACK_RIM_CONTAINER, BSSGP_PDU_TYPE, DE_BSSGP_RAN_INFORMATION_ACK_RIM_CONT , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ran_inf_err(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TELV(BSSGP_IEI_RIM_ROUTING_INFORMATION, BSSGP_PDU_TYPE, DE_BSSGP_RIM_ROUTING_INF , " - Destination Cell Identifier");
ELEM_MAND_TELV(BSSGP_IEI_RIM_ROUTING_INFORMATION, BSSGP_PDU_TYPE, DE_BSSGP_RIM_ROUTING_INF , " - Source Cell Identifier");
ELEM_MAND_TELV(BSSGP_IEI_RAN_INF_ERROR_RIM_CONTAINER, BSSGP_PDU_TYPE, DE_BSSGP_RAN_INFORMATION_ERROR_RIM_CONT , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_ran_inf_app_err(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TELV(BSSGP_IEI_RIM_ROUTING_INFORMATION, BSSGP_PDU_TYPE, DE_BSSGP_RIM_ROUTING_INF , " - Destination Cell Identifier");
ELEM_MAND_TELV(BSSGP_IEI_RIM_ROUTING_INFORMATION, BSSGP_PDU_TYPE, DE_BSSGP_RIM_ROUTING_INF , " - Source Cell Identifier");
ELEM_MAND_TELV(BSSGP_IEI_RAN_INF_APP_ERROR_RIM_CONTAINER, BSSGP_PDU_TYPE, DE_BSSGP_RAN_INF_APP_ERROR_RIM_CONT , NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_mbms_session_start_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(0x5c, GSM_A_PDU_TYPE_GM, DE_TMGI, NULL);
ELEM_OPT_TELV(0x5d, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SESSION_ID, NULL);
ELEM_MAND_TELV(0x3a , GSM_A_PDU_TYPE_GM, DE_QOS , NULL);
ELEM_MAND_TELV(0x5f, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SAI_LIST, NULL);
ELEM_MAND_TELV(0x61, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_RA_LIST, NULL);
ELEM_MAND_TELV(0x5e, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SESSION_DUR, NULL);
ELEM_MAND_TELV(0x62, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SESSION_INF, NULL);
ELEM_MAND_TELV(0x71, BSSGP_PDU_TYPE, DE_BSSGP_TIME_TO_MBMS_DATA_TRAN, NULL);
ELEM_OPT_TELV(0x17, GSM_A_PDU_TYPE_BSSMAP, BE_PRIO, NULL);
ELEM_MAND_TELV(0x72, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SESSION_REP_NO, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_mbms_session_start_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(0x5c, GSM_A_PDU_TYPE_GM, DE_TMGI, NULL);
ELEM_OPT_TELV(0x5d, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SESSION_ID, NULL);
ELEM_OPT_TELV(0x60, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_RESPONSE, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_mbms_session_stop_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_TELV(0x5c, GSM_A_PDU_TYPE_GM, DE_TMGI, NULL);
ELEM_OPT_TELV(0x5d, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SESSION_ID, NULL);
ELEM_OPT_TELV(0x63, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_STOP_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_mbms_session_stop_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(0x5c, GSM_A_PDU_TYPE_GM, DE_TMGI, NULL);
ELEM_OPT_TELV(0x5d, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SESSION_ID, NULL);
ELEM_OPT_TELV(0x60, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_RESPONSE, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_mbms_session_update_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(0x5c, GSM_A_PDU_TYPE_GM, DE_TMGI, NULL);
ELEM_OPT_TELV(0x5d, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SESSION_ID, NULL);
ELEM_MAND_TELV(0x3a , GSM_A_PDU_TYPE_GM, DE_QOS , NULL);
ELEM_MAND_TELV(0x5f, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SAI_LIST, NULL);
ELEM_MAND_TELV(0x61, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_RA_LIST, NULL);
ELEM_MAND_TELV(0x5e, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SESSION_DUR, NULL);
ELEM_MAND_TELV(0x62, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SESSION_INF, NULL);
ELEM_MAND_TELV(0x71, BSSGP_PDU_TYPE, DE_BSSGP_TIME_TO_MBMS_DATA_TRAN, NULL);
ELEM_OPT_TELV(0x17, GSM_A_PDU_TYPE_BSSMAP, BE_PRIO, NULL);
ELEM_MAND_TELV(0x72, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SESSION_REP_NO, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void
bssgp_mbms_session_uptate_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_TELV(0x5c, GSM_A_PDU_TYPE_GM, DE_TMGI, NULL);
ELEM_OPT_TELV(0x5d, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_SESSION_ID, NULL);
ELEM_OPT_TELV(0x60, BSSGP_PDU_TYPE, DE_BSSGP_MBMS_RESPONSE, NULL);
EXTRANEOUS_DATA_CHECK_EXPERT(curr_len, 0, pinfo, &ei_bssgp_extraneous_data);
}
static void get_bssgp_msg_params(guint8 oct, const gchar **msg_str, int *ett_tree, int *hf_idx, msg_fcn *msg_fcn_p)
{
gint idx;
*msg_str = try_val_to_str_idx_ext((guint32) (oct & 0xff), &bssgp_msg_strings_ext, &idx);
*hf_idx = hf_bssgp_msg_type;
if (*msg_str != NULL) {
*ett_tree = ett_bssgp_msg[idx];
*msg_fcn_p = bssgp_msg_fcn[idx];
}
return;
}
static void
dissect_bssgp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *bssgp_tree = NULL;
int offset = 0;
guint32 len;
const gchar *msg_str = NULL;
gint ett_tree;
int hf_idx;
void (*msg_fcn_p)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len);
g_rim_application_identity = 0;
gparent_tree = tree;
len = tvb_length(tvb);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BSSGP");
col_clear(pinfo->cinfo, COL_INFO);
g_pdu_type = tvb_get_guint8(tvb,offset);
if (tree) {
ti = proto_tree_add_item(tree, proto_bssgp, tvb, 0, -1, ENC_NA);
bssgp_tree = proto_item_add_subtree(ti, ett_bssgp);
}
msg_fcn_p = NULL;
ett_tree = -1;
hf_idx = -1;
msg_str = NULL;
get_bssgp_msg_params(g_pdu_type, &msg_str, &ett_tree, &hf_idx, &msg_fcn_p);
if(msg_str){
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", msg_str);
}else{
proto_tree_add_text(bssgp_tree, tvb, offset, 1,"Unknown message 0x%x",g_pdu_type);
return;
}
proto_tree_add_item(bssgp_tree, hf_idx, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (msg_fcn_p == NULL)
{
proto_tree_add_text(bssgp_tree, tvb, offset, len - offset, "Message Elements");
}
else
{
(*msg_fcn_p)(tvb, bssgp_tree, pinfo, offset, len - offset);
}
}
void
proto_register_bssgp(void)
{
guint i;
guint last_offset;
static hf_register_info hf[] = {
{ &hf_bssgp_msg_type,
{ "PDU Type", "bssgp.pdu_type",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bssgp_msg_strings_ext, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_elem_id,
{ "Element ID", "bssgp.elem_id",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_bssgp_bss_area_ind,
{ "BSS indicator", "bssgp.bss_ind",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_bvci,
{ "BVCI", "bssgp.bvci",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_bmax,
{ "Bmax(x 100 or in increments as defined by the Flow Control Granularity IE)", "bssgp.bmax",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_r,
{ "R(x 100 or in increments as defined by the Flow Control Granularity IE)", "bssgp.r",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_r_pfc,
{ "R_PFC(x 100 or in increments as defined by the Flow Control Granularity IE)", "bssgp.r_pfc",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_bucket_size,
{ "Bmax(x 100 or in increments as defined by the Flow Control Granularity IE)", "bssgp.bucket_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_bmax_pfc,
{ "Bmax_PFC(x 100 or in increments as defined by the Flow Control Granularity IE)", "bssgp.bmax_pfc",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_omc_id,
{ "OMC identity", "bssgp.omc_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_nsei,
{ "NSEI", "bssgp.nsei",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_rrlp_flag1,
{ "Flag 1", "bssgp.rrlp_flag1",
FT_BOOLEAN, 8, TFS(&bssgp_rrlp_flg1_vals), 0x01,
NULL, HFILL }
},
{ &hf_bssgp_ci,
{ "CI", "bssgp.ci",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Cell Identity", HFILL }
},
{ &hf_bssgp_flush_action,
{ "Action", "bssgp.flush_action",
FT_UINT8, BASE_DEC, VALS(bssgp_flush_action_vals), 0x0,
NULL, HFILL }
},
{ &hf_bssgp_llc_frames_disc,
{ "Number of frames discarded", "bssgp.llc_frames_disc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_ra_discriminator,
{ "Routing Address Discriminator", "bssgp.rad",
FT_UINT8, BASE_DEC, VALS(bssgp_ra_discriminator_vals), 0x0f,
NULL, HFILL }
},
{ &hf_bssgp_rim_app_id,
{ "RIM Application Identity", "bssgp.rim_app_id",
FT_UINT8, BASE_DEC, VALS(bssgp_rim_appid_vals), 0x0,
NULL, HFILL }
},
{ &hf_bssgp_rim_seq_no,
{ "RIM Sequence Number", "bssgp.rim_seq_no",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_rat_discriminator,
{ "RAT discriminator", "bssgp.rat_discriminator",
FT_UINT8, BASE_DEC, VALS(bssgp_rat_discriminator_vals), 0x0f,
NULL, HFILL }
},
{ &hf_bssgp_nacc_cause,
{ "NACC Cause", "bssgp.nacc_cause",
FT_UINT8, BASE_DEC, VALS(bssgp_nacc_cause_vals), 0x0,
NULL, HFILL }
},
{ &hf_bssgp_s13_cause,
{ "SI3 Cause", "bssgp.s13_cause",
FT_UINT8, BASE_DEC, VALS(bssgp_s13_cause_vals), 0x0,
NULL, HFILL }
},
{ &hf_bssgp_mbms_data_ch_cause,
{ "MBMS data channel Cause", "bssgp.mbms_data_ch_cause",
FT_UINT8, BASE_DEC, VALS(bssgp_mbms_data_ch_cause_vals), 0x0,
NULL, HFILL }
},
{ &hf_bssgp_utra_si_cause,
{ "UTRA SI Cause", "bssgp.utra_si_cause",
FT_UINT8, BASE_DEC, VALS(bssgp_utra_si_cause_vals), 0x0,
NULL, HFILL }
},
{ &hf_bssgp_num_si_psi,
{ "Number of SI/PSI", "bssgp.num_si_psi",
FT_UINT8, BASE_DEC, NULL, 0xfe,
NULL, HFILL }
},
{&hf_bssgp_si_psi_type,
{ "Type", "bssgp.si_psi_type",
FT_BOOLEAN, 8, TFS(&bssgp_si_psi_type_vals), 0x01,
NULL, HFILL }
},
{ &hf_bssgp_ran_inf_req_pdu_t_ext_c,
{ "PDU Type Extension", "bssgp.ran_inf_req_pdu_t_ext_c",
FT_UINT8, BASE_DEC, VALS(bssgp_ran_inf_req_pdu_t_ext_c_vals), 0x0e,
NULL, HFILL }
},
{ &hf_bssgp_ran_inf_pdu_t_ext_c,
{ "PDU Type Extension", "bssgp.ran_inf_pdu_t_ext_c",
FT_UINT8, BASE_DEC, VALS(bssgp_ran_inf_pdu_t_ext_c_vals), 0x0e,
NULL, HFILL }
},
{&hf_bssgp_rim_pdu_ind_ack,
{ "ACK", "bssgp.rim_pdu_ind_ack",
FT_BOOLEAN, 8, TFS(&bssgp_rim_pdu_ind_ack_vals), 0x01,
NULL, HFILL }
},
{ &hf_bssgp_rim_proto_ver_no,
{ "RIM Protocol Version Number", "bssgp.rim_proto_ver_no",
FT_UINT8, BASE_DEC, VALS(bssgp_rim_proto_ver_no_vals), 0x0,
NULL, HFILL }
},
{ &hf_bssgp_delay_val,
{ "Delay Value (in centi-seconds)", "bssgp.delay_val",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_cause,
{ "Cause", "bssgp.cause",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &bssgp_cause_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_peak_rate_gran,
{ "Peak Bit Rate Granularity", "bssgp.peak_rate_gran",
FT_UINT8, BASE_DEC, NULL, 0xc0,
NULL, HFILL }
},
{ &hf_bssgp_cr_bit,
{ "C/R", "bssgp.cr_bit",
FT_BOOLEAN, 8, TFS(&bssgp_cr_bit_vals), 0x20,
NULL, HFILL }
},
{ &hf_bssgp_t_bit,
{ "T", "bssgp.t_bit",
FT_BOOLEAN, 8, TFS(&bssgp_t_bit_vals), 0x10,
NULL, HFILL }
},
{ &hf_bssgp_a_bit,
{ "A", "bssgp.a_bit",
FT_BOOLEAN, 8, TFS(&bssgp_a_bit_vals), 0x08,
NULL, HFILL }
},
{ &hf_bssgp_ra_cause,
{ "Radio Cause", "bssgp.ra_cause",
FT_UINT8, BASE_DEC, VALS(bssgp_radio_cause_vals), 0x00,
NULL, HFILL }
},
{ &hf_bssgp_ra_cap_upd_cause,
{ "RA-Cap-UPD Cause", "bssgp.ra_cap_upd_cause",
FT_UINT8, BASE_DEC, VALS(bssgp_ra_cap_upd_cause_vals), 0x00,
NULL, HFILL }
},
{ &hf_bssgp_r_default_ms,
{ "R_default_MS(x 100 or in increments as defined by the Flow Control Granularity IE)", "bssgp.r_default_ms",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_suspend_ref_no,
{ "Suspend Reference Number", "bssgp.suspend_ref_no",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bssgp_tag,
{ "Tag", "bssgp.tag",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bssgp_trace_ref,
{ "Trace Reference", "bssgp.trace_ref",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bssgp_trigger_id,
{ "Entity Identity", "bssgp.entity_id",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bssgp_transaction_id,
{ "Transaction Id", "bssgp.transaction_id",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bssgp_no_of_oct,
{ "Number of octets transferred or deleted", "bssgp.no_of_oct",
FT_UINT24, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bssgp_unit_val,
{ "Unit Value", "bssgp.unit_val",
FT_UINT8, BASE_DEC, VALS(bssgp_unit_vals), 0xe0,
NULL, HFILL }
},
{ &hf_bssgp_gprs_timer,
{ "Unit Value", "bssgp.gprs_timer",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_bssgp_mbms,
{ "MBMS Procedures", "bssgp.mbms",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_bssgp_EnhancedRadioStatus,
{ "Enhanced Radio Status Procedures", "bssgp.enhancedradiostatus",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_bssgp_pfcfc,
{ "PFC Flow Control Procedures", "bssgp.pfcfc",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_bssgp_rim,
{ "RAN Information Management (RIM) procedures", "bssgp.rim",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_bssgp_lcs,
{ "LCS Procedures", "bssgp.lcs",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_bssgp_inr,
{ "Inter-NSE re-routing(INR)", "bssgp.inr",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_bssgp_cbl,
{ "Current Bucket Level(CBL) Procedures", "bssgp.cbl",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_bssgp_pfc,
{ "Packet Flow Context(PFC) Procedures", "bssgp.pfc",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_bssgp_bucket_full_ratio,
{ "Ratio of the bucket that is filled up with data", "bssgp.bucket_full_ratio",
FT_UINT8, BASE_DEC, NULL, 0x0,
"B current x (100 / Bmax)", HFILL }
},
{ &hf_bssgp_b_pfc,
{ "B_PFC: Bucket Full Ratio of the PFC", "bssgp.b_pfc",
FT_UINT8, BASE_DEC, NULL, 0x0,
"B current x (100 / Bmax)", HFILL }
},
{ &hf_bssgp_precedence,
{ "Precedence", "bssgp.precedence",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_bssgp_serv_utran_cco,
{ "Service UTRAN CCO", "bssgp.serv_utran_cco",
FT_UINT8, BASE_DEC, VALS(bssgp_service_utran_cco_vals), 0x07,
NULL, HFILL }
},
{ &hf_bssgp_mbms_session_id,
{ "MBMS Session ID", "bssgp.mbms_session_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_mbms_cause,
{ "Cause", "bssgp.mbms_cause",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &bssgp_mbms_cause_vals_ext, 0x0f,
NULL, HFILL }
},
{ &hf_bssgp_mbms_stop_cause,
{ "Stop Cause", "bssgp.mbms_stop_cause",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &bssgp_mbms_stop_cause_vals_ext, 0x0f,
NULL, HFILL }
},
{ &hf_bssgp_session_inf,
{ "BC/MC", "bssgp.session_inf",
FT_BOOLEAN, 8, TFS(&tfs_bssgp_bc_mc), 0x01,
NULL, HFILL }
},
{ &hf_bssgp_mbms_num_ra_ids,
{ "Number of Routing Area Identifications", "bssgp.mbms_num_ra_ids",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &bssgp_mbms_num_ra_ids_vals_ext, 0xf0,
NULL, HFILL }
},
{ &hf_bssgp_gb_if,
{ "Gigabit Interface", "bssgp.gb_if",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_bssgp_ps_ho,
{ "PS Handover", "bssgp.ps_ho",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_bssgp_src_to_trg_transp_cont,
{ "Source to Target Transparent Container", "bssgp.src_to_trg_transp_cont",
FT_BYTES, FT_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_trg_to_src_transp_cont,
{ "Target to Source Transparent Container", "bssgp.trg_to_src_transp_cont",
FT_BYTES, FT_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_rnc_id,
{ "RNC ID", "bssgp.rnc_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_page_mode,
{ "PAGE_MODE", "bssgp.page_mode",
FT_UINT8, BASE_DEC, VALS(bssgp_page_mode_vals), 0x03,
NULL, HFILL }
},
{ &hf_bssgp_container_id,
{ "Container ID", "bssgp.container_id",
FT_UINT8, BASE_DEC, NULL, 0x03,
NULL, HFILL }
},
{ &hf_bssgp_global_tfi,
{ "Global TFI", "bssgp.global_tfi",
FT_UINT8, BASE_DEC, VALS(bssgp_global_tfi_vals), 0x0,
NULL, HFILL }
},
{ &hf_bssgp_ul_tfi,
{ "UPLINK_TFI", "bssgp.ul_tfi",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_dl_tfi,
{ "DOWNLINK_TFI", "bssgp.dl_tfi",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_time_to_MBMS_data_tran,
{ "Time to MBMS Data Transfer", "bssgp.time_to_mbms_data_tran",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_mbms_session_rep_no,
{ "MBMS-Session-Repetition-Number", "bssgp.mbms_session_rep_no",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_ps_ho_cmd,
{ "PS Handover Command", "bssgp.ps_ho_cmd",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_sipsi,
{ "SI/PSI", "bssgp.sipsi",
FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), 0x01,
NULL, HFILL }
},
{ &hf_bssgp_type,
{ "Type", "bssgp.type",
FT_UINT8, BASE_DEC, VALS(type_vals), 0x01,
NULL, HFILL }
},
{ &hf_bssgp_cs_indication,
{ "CS Indication Contents", "bssgp.cs_indication",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_flow_control_gran,
{ "Granularity", "bssgp.flow_control_gran",
FT_UINT8, BASE_DEC, VALS(bssgp_flow_control_gran_vals), 0x03,
NULL, HFILL }
},
{ &hf_bssgp_serv_eutran_cco,
{ "Service EUTRAN CCO", "bssgp.serv_eutran_cco",
FT_UINT8, BASE_DEC, VALS(bssgp_service_eutran_cco_vals), 0x18,
NULL, HFILL }
},
{ &hf_bssgp_sub_prof_id_f_rat_freq_prio,
{ "Subscriber Profile ID for RAT/Frequency priority", "bssgp.sub_prof_id_f_rat_freq_prio",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bssgp_eutran_irat_ho_inf_req,
{ "E-UTRAN Inter RAT Handover Info", "bssgp.eutran_irat_ho_inf_req",
FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), 0x02,
NULL, HFILL }
},
{ &hf_bssgp_irat_ho_inf_req,
{ "Inter RAT Handover Info", "bssgp.irat_ho_inf_req",
FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), 0x01,
NULL, HFILL }
},
{ &hf_bssgp_rel_int_rat_ho_inf_ind,
{ "Inter RAT Handover Info", "bssgp.rel_int_rat_ho_inf_ind",
FT_BOOLEAN, 8, TFS(&tfs_reliable_not_reliable), 0x01,
NULL, HFILL }
},
{ &hf_bssgp_csg_id,
{ "CSG Identity (CSG-ID)", "bssgp.csg_id",
FT_UINT32, BASE_HEX, NULL, 0xffffff0f,
NULL, HFILL }
},
{ &hf_bssgp_cell_acc_mode,
{ "Cell Access Mode", "bssgp.cell_acc_mode",
FT_UINT8, BASE_DEC, VALS(bssgp_cell_access_mode_vals), 0x01,
NULL, HFILL }
},
{ &hf_bssgp_redir_complete_outcome,
{ "Outcome Value", "bssgp.redir_complete_outcome",
FT_UINT8, BASE_HEX, VALS(bssgp_redir_complete_outcome_vals), 0x0,
NULL, HFILL }
},
{ &hf_bssgp_redir_indiction_reroute_reject_cause,
{ "Reroute Reject Cause Value", "bssgp.redir_indiction_reroute_reject_cause",
FT_UINT8, BASE_HEX, VALS(bssgp_redir_indiction_reroute_reject_cause_vals), 0x0,
NULL, HFILL }
},
{ &hf_bssgp_unconfim_send_state_var,
{ "Unconfirmed Send State Variable V(U)", "bssgp.unconfim_send_state_var",
FT_UINT16, BASE_DEC, NULL, 0x01ff,
NULL, HFILL }
},
{ &hf_bssgp_Global_ENB_ID_PDU,
{ "Global-ENB-ID", "bssgp.Global_ENB_ID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_bssgp_SONtransferRequestContainer_PDU,
{ "SONtransferRequestContainer", "bssgp.SONtransferRequestContainer",
FT_UINT32, BASE_DEC, VALS(s1ap_SONtransferRequestContainer_vals), 0,
NULL, HFILL }},
{ &hf_bssgp_selected_plmn_id,
{ "Selected PLMN ID", "bssgp.selected_plmn_id",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
};
#define NUM_INDIVIDUAL_ELEMS 10
gint *ett[NUM_INDIVIDUAL_ELEMS +
NUM_BSSGP_ELEM +
NUM_BSSGP_MSG];
static ei_register_info ei[] = {
{ &ei_bssgp_extraneous_data, { "bssgp.extraneous_data", PI_PROTOCOL, PI_NOTE, "Extraneous Data, dissector bug or later version spec(report to wireshark.org)", EXPFILL }},
};
expert_module_t* expert_bssgp;
ett[0] = &ett_bssgp;
ett[1] = &ett_bssgp_list_of_setup_pfcs;
ett[2] = &ett_bssgp_pfcs_to_be_set_up_list_t10;
ett[3] = &ett_bssgp_pfcs_to_be_set_up_list_arp;
ett[4] = &ett_bssgp_pfcs_to_be_set_up_list_abqp;
ett[5] = &ett_bssgp_pfcs_to_be_set_up_list_pft;
ett[6] = &ett_bssgp_pfcs_to_be_set_up_list;
ett[7] = &ett_bssgp_new;
ett[8] = &ett_bssgp_pfc_flow_control_parameters_pfc;
ett[9] = &ett_bssgp_ra_id,
last_offset = NUM_INDIVIDUAL_ELEMS;
for (i=0; i < NUM_BSSGP_ELEM; i++, last_offset++)
{
ett_bssgp_elem[i] = -1;
ett[last_offset] = &ett_bssgp_elem[i];
}
for (i=0; i < NUM_BSSGP_MSG; i++, last_offset++)
{
ett_bssgp_msg[i] = -1;
ett[last_offset] = &ett_bssgp_msg[i];
}
proto_bssgp = proto_register_protocol("Base Station Subsystem GPRS Protocol", "BSSGP", "bssgp");
proto_register_field_array(proto_bssgp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_bssgp = expert_register_protocol(proto_bssgp);
expert_register_field_array(expert_bssgp, ei, array_length(ei));
register_dissector("bssgp", dissect_bssgp, proto_bssgp);
bssgp_module = prefs_register_protocol(proto_bssgp, NULL);
prefs_register_bool_preference(bssgp_module, "decode_nri",
"Decode NRI",
"Decode NRI (for use with SGSN in Pool)",
&bssgp_decode_nri);
prefs_register_uint_preference(bssgp_module, "nri_length", "NRI length",
"NRI length, in bits",
10, &bssgp_nri_length);
}
void
proto_reg_handoff_bssgp(void)
{
llc_handle = find_dissector("llcgprs");
rrlp_handle = find_dissector("rrlp");
data_handle = find_dissector("data");
diameter_3gpp_avp_dissector_table = find_dissector_table("diameter.3gpp");
}
