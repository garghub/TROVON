static guint16
calc_bitrate(guint8 value) {
guint16 return_value = value;
if ((value > 63) && (value <= 127)) {
return_value = 64 + (value - 64) * 8;
}
else if ((value > 127) && (value <= 254)) {
return_value = 576 + (value - 128) * 64;
}
else if (value == 0xff) {
return_value = 0;
}
return return_value;
}
static guint32
calc_bitrate_ext(guint8 value) {
guint32 return_value = 0;
if ((value > 0) && (value <= 0x4a)) {
return_value = 8600 + value * 100;
}
else if ((value > 0x4a) && (value <= 0xba)) {
return_value = 16 + (value-0x4a);
}
else if ((value > 0xba) && (value <= 0xfa)) {
return_value = 128 + (value-0xba)*2;
}
else {
return_value = 256;
}
return return_value;
}
static guint32
calc_bitrate_ext2(guint8 value) {
guint32 return_value = 0;
if ((value > 0) && (value <= 0x3d)) {
return_value = 256 + value * 4;
}
else if ((value > 0x3d) && (value <= 0xa1)) {
return_value = 500 + (value-0x3d) * 10;
}
else if ((value > 0xa1) && (value <= 0xf6)) {
return_value = 1500 + (value-0xa1) * 100;
}
else {
return_value = 10000;
}
return return_value;
}
static guint16
de_eps_cmn_add_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo,
guint32 offset, guint len,
gchar *add_string _U_, int string_len _U_)
{
proto_item *item;
proto_tree *sub_tree;
tvbuff_t *new_tvb;
item = proto_tree_add_item(tree, hf_nas_eps_cmn_add_info, tvb, offset, len, ENC_NA);
sub_tree = proto_item_add_subtree(item, ett_nas_eps_cmn_add_info);
new_tvb = tvb_new_subset_length(tvb, offset, len);
switch (eps_nas_gen_msg_cont_type) {
case 1:
dissect_lcsap_Correlation_ID_PDU(new_tvb, pinfo, sub_tree, NULL);
break;
default:
break;
}
return(len);
}
static guint16
de_eps_cmn_eps_be_ctx_status(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_nas_eps_emm_ebi7, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_ebi6, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_ebi5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_ebi4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_ebi3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_ebi2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_ebi1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_ebi0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_nas_eps_emm_ebi15, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_ebi14, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_ebi13, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_ebi12, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_ebi11, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_ebi10, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_ebi9, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_ebi8, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
return len;
}
guint16
de_emm_sec_par_from_eutra(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_dl_nas_cnt, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
return len;
}
guint16
de_emm_sec_par_to_eutra(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_nas_eps_emm_nonce_mme, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, curr_offset<<3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_toc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, (curr_offset<<3)+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_toi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_nas_eps_tsc, tvb, (curr_offset<<3)+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_nas_eps_emm_nas_key_set_id, tvb, (curr_offset<<3)+5, 3, ENC_BIG_ENDIAN);
curr_offset++;
return len;
}
static guint16
de_emm_add_upd_res(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, bit_offset;
curr_offset = offset;
bit_offset = (curr_offset<<3)+4;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_add_upd_res, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_emm_add_upd_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, bit_offset;
curr_offset = offset;
bit_offset = (curr_offset<<3)+4;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_pnb_ciot, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_saf, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_add_upd_type, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_emm_auth_resp_par(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_nas_eps_emm_res, tvb, curr_offset, len, ENC_NA);
return len;
}
static guint16
de_emm_csfb_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, bit_offset;
curr_offset = offset;
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_csfb_resp, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_emm_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 cause;
curr_offset = offset;
cause = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_nas_eps_emm_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
val_to_str_ext_const(cause, &nas_eps_emm_cause_values_ext, "Unknown"));
curr_offset++;
return curr_offset-offset;
}
static guint16
de_emm_eps_mid(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 octet;
const char *digit_str;
tvbuff_t *new_tvb;
curr_offset = offset;
octet = tvb_get_guint8(tvb,offset);
proto_tree_add_item(tree, hf_nas_eps_emm_odd_even, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_type_of_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
switch (octet&0x7) {
case 1:
new_tvb = tvb_new_subset_length(tvb, curr_offset, len);
dissect_e212_imsi(new_tvb, pinfo, tree, 0, len, TRUE);
break;
case 3:
new_tvb = tvb_new_subset_length(tvb, curr_offset, len);
digit_str = tvb_bcd_dig_to_wmem_packet_str(new_tvb, 0, len, NULL, TRUE);
proto_tree_add_string(tree, hf_nas_eps_emm_imei, new_tvb, 0, -1, digit_str);
break;
case 6:
curr_offset++;
curr_offset = dissect_e212_mcc_mnc(tvb, pinfo, tree, curr_offset, E212_NONE, TRUE);
proto_tree_add_item(tree, hf_nas_eps_emm_mme_grp_id, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
proto_tree_add_item(tree, hf_nas_eps_emm_mme_code, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_nas_eps_emm_m_tmsi, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_nas_eps_unknown_identity, tvb, curr_offset, len - 1);
break;
}
return(len);
}
static guint16
de_emm_eps_net_feature_sup(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, bit_offset;
curr_offset = offset;
bit_offset = curr_offset << 3;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_cp_ciot, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_er_wo_pdn, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_esr_ps, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_cs_lcs, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_epc_lcs, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_emc_bs, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_ims_vops, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
if (len >= 2) {
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_epco, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_hc_cp_ciot, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_s1_u_data, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_up_ciot, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
}
return len;
}
static guint16
de_emm_esm_msg_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo,
guint32 offset, guint len,
gchar *add_string _U_, int string_len _U_)
{
proto_item *item;
proto_tree *sub_tree;
tvbuff_t *new_tvb;
guint32 curr_offset;
guint8 init_sec_hdr_type = tvb_get_bits8(tvb, 0, 4);
curr_offset = offset;
item = proto_tree_add_item(tree, hf_nas_eps_esm_msg_cont, tvb, curr_offset, len, ENC_NA);
sub_tree = proto_item_add_subtree(item, ett_nas_eps_esm_msg_cont);
new_tvb = tvb_new_subset_length(tvb, curr_offset, len);
if (init_sec_hdr_type == 5) {
guint8 pd = tvb_get_guint8(new_tvb, 0);
if (((pd&0x0f) != 2) || (((pd&0x0f) == 2) && ((pd&0xf0) > 0) && ((pd&0xf0) < 0x50))) {
proto_tree_add_item(sub_tree, hf_nas_eps_ciphered_msg, new_tvb, 0, len, ENC_NA);
} else {
TRY {
disect_nas_eps_esm_msg(new_tvb, pinfo, sub_tree, 0);
} CATCH_BOUNDS_ERRORS {
show_exception(new_tvb, pinfo, sub_tree, EXCEPT_CODE, GET_MESSAGE);
} ENDTRY
}
} else {
disect_nas_eps_esm_msg(new_tvb, pinfo, sub_tree, 0);
}
return(len);
}
static guint16
de_emm_nas_imeisv_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
int bit_offset;
curr_offset = offset;
bit_offset = curr_offset<<3;
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_esm_imeisv_req, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_emm_nas_ksi_and_seq_no(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
int bit_offset;
curr_offset = offset;
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_nas_key_set_id, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(tree, hf_nas_eps_seq_no_short, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static void
de_emm_nas_key_set_id_bits(tvbuff_t *tvb, proto_tree *tree, guint32 bit_offset, const gchar *add_string)
{
proto_item *item;
proto_tree_add_bits_item(tree, hf_nas_eps_tsc, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
item = proto_tree_add_bits_item(tree, hf_nas_eps_emm_nas_key_set_id, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
if (add_string) {
proto_item_append_text(item, "%s", add_string);
}
}
static guint16
de_emm_nas_key_set_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, bit_offset;
curr_offset = offset;
bit_offset = curr_offset<<3;
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_tsc, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_nas_key_set_id, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_emm_nas_msg_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
proto_item *item;
proto_tree *sub_tree;
tvbuff_t *new_tvb;
guint32 curr_offset;
curr_offset = offset;
item = proto_tree_add_item(tree, hf_nas_eps_nas_msg_cont, tvb, curr_offset, len, ENC_NA);
sub_tree = proto_item_add_subtree(item, ett_nas_eps_nas_msg_cont);
new_tvb = tvb_new_subset_length(tvb, curr_offset, len);
if (gsm_a_dtap_handle) {
if (tvb_get_bits8(tvb, 0, 4) == 5) {
if (tvb_get_bits8(new_tvb, 4, 4) != 9) {
proto_tree_add_item(sub_tree, hf_nas_eps_ciphered_msg, new_tvb, 0, len, ENC_NA);
} else {
TRY {
call_dissector(gsm_a_dtap_handle, new_tvb, pinfo, sub_tree);
} CATCH_BOUNDS_ERRORS {
show_exception(new_tvb, pinfo, sub_tree, EXCEPT_CODE, GET_MESSAGE);
} ENDTRY
}
} else {
call_dissector(gsm_a_dtap_handle, new_tvb, pinfo, sub_tree);
}
}
return(len);
}
static guint16
de_emm_nas_sec_alsgs(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
int bit_offset;
guint32 curr_offset;
curr_offset = offset;
bit_offset = offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_toc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_toi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_emm_nonce(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_nas_eps_emm_nonce, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset+=4;
return(curr_offset-offset);
}
static guint16
de_emm_paging_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, curr_offset<<3, 7, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_nas_eps_emm_paging_id, tvb, (curr_offset<<3)+7, 1, ENC_BIG_ENDIAN);
return(1);
}
static guint16
de_emm_ext_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, bit_offset;
curr_offset = offset;
bit_offset = (curr_offset<<3)+4;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_eps_optim_info, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_eutran_allowed_value, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_emm_nas_short_mac(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_nas_eps_emm_short_mac, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
return(curr_offset-offset);
}
guint16
de_emm_trac_area_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
curr_offset = dissect_e212_mcc_mnc(tvb, pinfo, tree, curr_offset, E212_TAI, TRUE);
proto_tree_add_item(tree, hf_nas_eps_emm_tai_tac, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
return(curr_offset-offset);
}
static guint16
de_emm_trac_area_id_lst(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
proto_item *item;
guint32 curr_offset, tac;
guint8 octet, tol, n_elem;
int i;
proto_item *it;
curr_offset = offset;
while ((curr_offset - offset) < len) {
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, curr_offset<<3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_tai_tol, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb,curr_offset)& 0x7f;
tol = octet >> 5;
n_elem = (octet & 0x1f)+1;
item = proto_tree_add_item(tree, hf_nas_eps_emm_tai_n_elem, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
if (n_elem<16) {
proto_item_append_text(item, " [+1 = %u element(s)]", n_elem);
} else {
n_elem = 16;
}
curr_offset++;
if (tol>2) {
proto_tree_add_expert(tree, pinfo, &ei_nas_eps_unknown_type_of_list, tvb, curr_offset, len-(curr_offset-offset));
return len;
}
switch (tol) {
case 0:
curr_offset = dissect_e212_mcc_mnc(tvb, pinfo, tree, curr_offset, E212_TAI, TRUE);
if (len < (guint)(4+(n_elem*2))) {
proto_tree_add_expert(tree, pinfo, &ei_nas_eps_wrong_nb_of_elems, tvb, curr_offset, len-(curr_offset-offset));
return len;
}
for (i=0; i < n_elem; i++, curr_offset+=2)
proto_tree_add_item(tree, hf_nas_eps_emm_tai_tac, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
break;
case 1:
curr_offset = dissect_e212_mcc_mnc(tvb, pinfo, tree, curr_offset, E212_TAI, TRUE);
proto_tree_add_item_ret_uint(tree, hf_nas_eps_emm_tai_tac, tvb, curr_offset, 2, ENC_BIG_ENDIAN, &tac);
curr_offset+=2;
for (i = 1; i < n_elem; i++) {
it = proto_tree_add_uint(tree, hf_nas_eps_emm_tai_tac, tvb, curr_offset, 0, tac+i);
PROTO_ITEM_SET_GENERATED(it);
}
break;
case 2:
if (len< (guint)(1+(n_elem*5))) {
proto_tree_add_expert(tree, pinfo, &ei_nas_eps_wrong_nb_of_elems, tvb, curr_offset, len-(curr_offset-offset));
return len;
}
for (i=0; i < n_elem; i++) {
curr_offset = dissect_e212_mcc_mnc(tvb, pinfo, tree, curr_offset, E212_TAI, TRUE);
proto_tree_add_item(tree, hf_nas_eps_emm_tai_tac, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
}
break;
default:
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_nas_eps_extraneous_data);
curr_offset = offset + len;
break;
}
}
return(curr_offset-offset);
}
guint16
de_emm_ue_net_cap(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_nas_eps_emm_eea0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_128eea1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_128eea2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eea3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eea4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eea5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eea6, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eea7, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_nas_eps_emm_eia0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_128eia1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_128eia2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eia3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eia4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eia5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eia6, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eia7, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if ((curr_offset - offset) >= len)
return (len);
proto_tree_add_item(tree, hf_nas_eps_emm_uea0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uea1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uea2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uea3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uea4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uea5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uea6, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uea7, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if ((curr_offset - offset) >= len)
return (len);
proto_tree_add_item(tree, hf_nas_eps_emm_ucs2_supp, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uia1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uia2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uia3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uia4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uia5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uia6, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uia7, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if ((curr_offset - offset) >= len)
return (len);
proto_tree_add_item(tree, hf_nas_eps_emm_prose_dd_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_prose_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_h245_ash_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_acc_csfb_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_lpp_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_lcs_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_1xsrvcc_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_nf_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if ((curr_offset - offset) >= len)
return (len);
proto_tree_add_item(tree, hf_nas_eps_emm_epco_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_hc_cp_ciot_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_er_wo_pdn_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_s1u_data_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_up_ciot_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_cp_ciot_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_prose_relay_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_prose_dc_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if ((curr_offset - offset) >= len)
return (len);
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, (curr_offset<<3), 7, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_multiple_drb_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
while ((curr_offset - offset) < len) {
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, (curr_offset<<3), 8, ENC_BIG_ENDIAN);
curr_offset++;
}
return(len);
}
static guint16
de_emm_ue_ra_cap_inf_upd_need(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, (curr_offset<<3)+4, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_ue_ra_cap_inf_upd_need_flg, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
return(len);
}
static guint16
de_emm_ue_sec_cap(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_nas_eps_emm_eea0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_128eea1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_128eea2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eea3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eea4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eea5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eea6, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eea7, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_nas_eps_emm_eia0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_128eia1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_128eia2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eia3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eia4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eia5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eia6, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_eia7, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if (len == 2)
return(len);
proto_tree_add_item(tree, hf_nas_eps_emm_uea0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uea1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uea2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uea3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uea4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uea5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uea6, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uea7, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, (curr_offset<<3), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uia1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uia2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uia3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uia4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uia5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uia6, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_uia7, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if (len == 4)
return(len);
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, (curr_offset<<3), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_gea1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_gea2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_gea3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_gea4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_gea5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_gea6, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_gea7, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(len);
}
static guint16
de_emm_ss_code(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_nas_eps_emm_ss_code, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
return(len);
}
static guint16
de_emm_lcs_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_nas_eps_emm_lcs_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
return(len);
}
static guint16
de_emm_lcs_client_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
tvbuff_t *new_tvb;
curr_offset = offset;
new_tvb = tvb_new_subset_length(tvb, curr_offset, len);
dissect_gsm_map_lcs_LCS_ClientID_PDU( new_tvb, pinfo, tree, NULL );
return(len);
}
static guint16
de_emm_gen_msg_cont_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
eps_nas_gen_msg_cont_type = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_nas_eps_emm_gen_msg_cont_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_emm_gen_msg_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo,
guint32 offset, guint len,
gchar *add_string _U_, int string_len _U_)
{
proto_item *item;
proto_tree *sub_tree;
tvbuff_t *new_tvb;
item = proto_tree_add_item(tree, hf_nas_eps_gen_msg_cont, tvb, offset, len, ENC_NA);
sub_tree = proto_item_add_subtree(item, ett_nas_eps_gen_msg_cont);
new_tvb = tvb_new_subset_length(tvb, offset, len);
switch (eps_nas_gen_msg_cont_type) {
case 1:
if (lpp_handle) {
call_dissector(lpp_handle, new_tvb, pinfo, sub_tree);
}
break;
case 2:
if (gsm_a_dtap_handle) {
call_dissector(gsm_a_dtap_handle, new_tvb, pinfo, sub_tree);
}
break;
default:
break;
}
return(len);
}
static guint16
de_emm_guti_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, bit_offset;
curr_offset = offset;
bit_offset = (curr_offset<<3)+4;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_guti_type, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_esm_apn_aggr_max_br(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 octet;
guint32 dl_total = 0;
guint32 ul_total = 0;
guint32 bitrate = 0;
curr_offset = offset;
octet = tvb_get_guint8(tvb,curr_offset);
if (octet == 0) {
proto_tree_add_uint_format(tree, hf_nas_eps_emm_apn_ambr_dl, tvb, curr_offset, 1, octet,
"Reserved");
} else {
bitrate = calc_bitrate(octet);
dl_total = bitrate;
proto_tree_add_uint_format_value(tree, hf_nas_eps_emm_apn_ambr_dl, tvb, curr_offset, 1, octet,
"%u kbps", bitrate);
}
curr_offset++;
octet = tvb_get_guint8(tvb,curr_offset);
if (octet == 0) {
proto_tree_add_uint_format(tree, hf_nas_eps_emm_apn_ambr_ul, tvb, curr_offset, 1, octet,
"Reserved");
} else {
bitrate = calc_bitrate(octet);
ul_total = bitrate;
proto_tree_add_uint_format_value(tree, hf_nas_eps_emm_apn_ambr_ul, tvb, curr_offset, 1, octet,
"%u kbps", bitrate);
}
curr_offset++;
if ((curr_offset - offset) >= len)
return(len);
octet = tvb_get_guint8(tvb,curr_offset);
if (octet == 0) {
proto_tree_add_uint_format(tree, hf_nas_eps_emm_apn_ambr_dl_ext, tvb, curr_offset, 1, octet,
"Use the value indicated by the APN-AMBR for downlink");
} else {
bitrate = calc_bitrate_ext(octet);
dl_total = (octet > 0x4a) ? bitrate*1000 : bitrate;
proto_tree_add_uint_format_value(tree, hf_nas_eps_emm_apn_ambr_dl_ext, tvb, curr_offset, 1, octet,
"%u %s", bitrate, (octet > 0x4a) ? "Mbps" : "kbps");
}
if (len < 5) {
if (dl_total >= 1000) {
proto_tree_add_uint_format_value(tree, hf_nas_eps_emm_apn_ambr_dl_total, tvb, curr_offset, 1, dl_total, "%.3f Mbps", (gfloat)dl_total / 1000);
} else {
proto_tree_add_uint_format_value(tree, hf_nas_eps_emm_apn_ambr_dl_total, tvb, curr_offset, 1, dl_total, "%u kbps", dl_total);
}
}
curr_offset++;
if ((curr_offset - offset) >= len)
return(len);
octet = tvb_get_guint8(tvb,curr_offset);
if (octet == 0) {
proto_tree_add_uint_format(tree, hf_nas_eps_emm_apn_ambr_ul_ext, tvb, curr_offset, 1, octet,
"Use the value indicated by the APN-AMBR for uplink");
} else {
bitrate = calc_bitrate_ext(octet);
ul_total = (octet > 0x4a) ? bitrate*1000 : bitrate;
proto_tree_add_uint_format_value(tree, hf_nas_eps_emm_apn_ambr_ul_ext, tvb, curr_offset, 1, octet,
"%u %s", bitrate, (octet > 0x4a) ? "Mbps" : "kbps");
}
if (len < 6) {
if (ul_total >= 1000) {
proto_tree_add_uint_format_value(tree, hf_nas_eps_emm_apn_ambr_ul_total, tvb, curr_offset, 1, ul_total, "%.3f Mbps", (gfloat)ul_total / 1000);
} else {
proto_tree_add_uint_format_value(tree, hf_nas_eps_emm_apn_ambr_ul_total, tvb, curr_offset, 1, ul_total, "%u kbps", ul_total);
}
}
curr_offset++;
if ((curr_offset - offset) >= len)
return(len);
octet = tvb_get_guint8(tvb,curr_offset);
if ((octet == 0)||(octet == 0xff)) {
proto_tree_add_uint_format(tree, hf_nas_eps_emm_apn_ambr_dl_ext2, tvb, curr_offset, 1, octet,
"Use the value indicated by the APN-AMBR for downlink and APN-AMBR for downlink (extended)");
} else {
dl_total += octet*256*1000;
proto_tree_add_uint_format_value(tree, hf_nas_eps_emm_apn_ambr_dl_ext2, tvb, curr_offset, 1, octet,
"%u Mbps", (octet* 256));
}
proto_tree_add_uint_format_value(tree, hf_nas_eps_emm_apn_ambr_dl_total, tvb, curr_offset, 1, dl_total, "%.3f Mbps", (gfloat)dl_total / 1000);
curr_offset++;
if ((curr_offset - offset) >= len)
return(len);
octet = tvb_get_guint8(tvb,curr_offset);
if ((octet == 0)||(octet == 0xff)) {
proto_tree_add_uint_format(tree, hf_nas_eps_emm_apn_ambr_ul_ext2, tvb, curr_offset, 1, octet,
"Use the value indicated by the APN-AMBR for uplink and APN-AMBR for uplink (extended)");
} else {
ul_total += octet*256*1000;
proto_tree_add_uint_format_value(tree, hf_nas_eps_emm_apn_ambr_ul_ext2, tvb, curr_offset, 1, octet,
"%u Mbps", (octet* 256));
}
proto_tree_add_uint_format_value(tree, hf_nas_eps_emm_apn_ambr_ul_total, tvb, curr_offset, 1, ul_total, "%.3f Mbps", (gfloat)ul_total / 1000);
curr_offset++;
return(len);
}
guint16
de_esm_qos(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 octet;
curr_offset = offset;
proto_tree_add_item(tree, hf_nas_eps_qci, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if ((curr_offset - offset) >= len)
return(len);
octet = tvb_get_guint8(tvb,curr_offset);
if (octet == 0) {
proto_tree_add_uint_format(tree, hf_nas_eps_mbr_ul, tvb, curr_offset, 1, octet,
"UE->NW Subscribed maximum bit rate for uplink/ NW->UE Reserved");
} else {
proto_tree_add_uint_format_value(tree, hf_nas_eps_mbr_ul, tvb, curr_offset, 1, octet,
"%u kbps", calc_bitrate(octet));
}
curr_offset++;
if ((curr_offset - offset) >= len)
return(len);
octet = tvb_get_guint8(tvb,curr_offset);
if (octet == 0) {
proto_tree_add_uint_format(tree, hf_nas_eps_mbr_dl, tvb, curr_offset, 1, octet,
"UE->NW Subscribed maximum bit rate for downlink/ NW->UE Reserved");
} else {
proto_tree_add_uint_format_value(tree, hf_nas_eps_mbr_dl, tvb, curr_offset, 1, octet,
"%u kbps", calc_bitrate(octet));
}
curr_offset++;
if ((curr_offset - offset) >= len)
return(len);
octet = tvb_get_guint8(tvb,curr_offset);
proto_tree_add_uint_format_value(tree, hf_nas_eps_gbr_ul, tvb, curr_offset, 1, octet,
"%u kbps", calc_bitrate(octet));
curr_offset++;
if ((curr_offset - offset) >= len)
return(len);
octet = tvb_get_guint8(tvb,curr_offset);
proto_tree_add_uint_format_value(tree, hf_nas_eps_gbr_dl, tvb, curr_offset, 1, octet,
"%u kbps", calc_bitrate(octet));
curr_offset++;
if ((curr_offset - offset) >= len)
return(len);
octet = tvb_get_guint8(tvb,curr_offset);
if (octet == 0) {
proto_tree_add_uint_format(tree, hf_nas_eps_embr_ul, tvb, curr_offset, 1, octet,
"Use the value indicated by the maximum bit rate for uplink in octet 4");
} else {
proto_tree_add_uint_format(tree, hf_nas_eps_embr_ul, tvb, curr_offset, 1, octet,
"Maximum bit rate for uplink (extended) : %u %s",
calc_bitrate_ext(octet),
(octet > 0x4a) ? "Mbps" : "kbps");
}
curr_offset++;
if ((curr_offset - offset) >= len)
return(len);
octet = tvb_get_guint8(tvb,curr_offset);
if (octet == 0) {
proto_tree_add_uint_format(tree, hf_nas_eps_embr_dl, tvb, curr_offset, 1, octet,
"Use the value indicated by the maximum bit rate for downlink in octet 5");
} else {
proto_tree_add_uint_format(tree, hf_nas_eps_embr_dl, tvb, curr_offset, 1, octet,
"Maximum bit rate for downlink (extended) : %u %s",
calc_bitrate_ext(octet),
(octet > 0x4a) ? "Mbps" : "kbps");
}
curr_offset++;
if ((curr_offset - offset) >= len)
return(len);
octet = tvb_get_guint8(tvb,curr_offset);
if (octet == 0) {
proto_tree_add_uint_format(tree, hf_nas_eps_egbr_ul, tvb, curr_offset, 1, octet,
"Use the value indicated by the guaranteed bit rate for uplink in octet 6");
} else {
proto_tree_add_uint_format(tree, hf_nas_eps_egbr_ul, tvb, curr_offset, 1, octet,
"Guaranteed bit rate for uplink (extended) : %u %s",
calc_bitrate_ext(octet),
(octet > 0x4a) ? "Mbps" : "kbps");
}
curr_offset++;
if ((curr_offset - offset) >= len)
return(len);
octet = tvb_get_guint8(tvb,curr_offset);
if (octet == 0) {
proto_tree_add_uint_format(tree, hf_nas_eps_egbr_dl, tvb, curr_offset, 1, octet,
"Use the value indicated by the guaranteed bit rate for downlink in octet 7");
} else {
proto_tree_add_uint_format(tree, hf_nas_eps_egbr_dl, tvb, curr_offset, 1, octet,
"Guaranteed bit rate for downlink (extended) : %u %s",
calc_bitrate_ext(octet),
(octet > 0x4a) ? "Mbps" : "kbps");
}
curr_offset++;
if ((curr_offset - offset) >= len)
return(len);
octet = tvb_get_guint8(tvb,curr_offset);
if (octet == 0) {
proto_tree_add_uint_format(tree, hf_nas_eps_embr_ul, tvb, curr_offset, 1, octet,
"Use the value indicated by the maximum bit rate for uplink in octet 4 and octet 8");
} else {
proto_tree_add_uint_format(tree, hf_nas_eps_embr_ul, tvb, curr_offset, 1, octet,
"Maximum bit rate for uplink (extended-2) : %u Mbps",
calc_bitrate_ext2(octet));
}
curr_offset++;
octet = tvb_get_guint8(tvb,curr_offset);
if (octet == 0) {
proto_tree_add_uint_format(tree, hf_nas_eps_embr_dl, tvb, curr_offset, 1, octet,
"Use the value indicated by the maximum bit rate for downlink in octet 5 and octet 9");
} else {
proto_tree_add_uint_format(tree, hf_nas_eps_embr_dl, tvb, curr_offset, 1, octet,
"Maximum bit rate for downlink (extended-2) : %u Mbps",
calc_bitrate_ext2(octet));
}
curr_offset++;
octet = tvb_get_guint8(tvb,curr_offset);
if (octet == 0) {
proto_tree_add_uint_format(tree, hf_nas_eps_egbr_ul, tvb, curr_offset, 1, octet,
"Use the value indicated by the guaranteed bit rate for uplink in octet 6 and octet 10");
} else {
proto_tree_add_uint_format(tree, hf_nas_eps_egbr_ul, tvb, curr_offset, 1, octet,
"Guaranteed bit rate for uplink (extended-2) : %u Mbps",
calc_bitrate_ext2(octet));
}
curr_offset++;
octet = tvb_get_guint8(tvb,curr_offset);
if (octet == 0) {
proto_tree_add_uint_format(tree, hf_nas_eps_egbr_dl, tvb, curr_offset, 1, octet,
"Use the value indicated by the guaranteed bit rate for downlink in octet 7 and octet 11");
} else {
proto_tree_add_uint_format(tree, hf_nas_eps_egbr_dl, tvb, curr_offset, 1, octet,
"Guaranteed bit rate for downlink (extended-2) : %u Mbps",
calc_bitrate_ext2(octet));
}
return(len);
}
static guint16
de_esm_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 cause;
curr_offset = offset;
cause = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_nas_eps_esm_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
val_to_str_ext_const(cause, &nas_eps_esm_cause_vals_ext, "Unknown"));
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_esm_inf_trf_flg(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, (curr_offset<<3)+4, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_esm_eit, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
de_esm_notif_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_nas_eps_esm_notif_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
return(len);
}
static guint16
de_esm_pdn_addr(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 pdn_type;
curr_offset = offset;
pdn_type = tvb_get_guint8(tvb, offset) & 0x7;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, curr_offset<<3, 5, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_esm_pdn_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
switch (pdn_type) {
case 1:
proto_tree_add_item(tree, hf_nas_eps_esm_pdn_ipv4, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset+=4;
break;
case 2:
proto_tree_add_item(tree, hf_nas_eps_esm_pdn_ipv6_if_id, tvb, curr_offset, 8, ENC_NA);
curr_offset+=8;
break;
case 3:
proto_tree_add_item(tree, hf_nas_eps_esm_pdn_ipv6_if_id, tvb, curr_offset, 8, ENC_NA);
curr_offset+=8;
proto_tree_add_item(tree, hf_nas_eps_esm_pdn_ipv4, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset+=4;
break;
case 5:
curr_offset+=4;
break;
default:
break;
}
return(curr_offset-offset);
}
static guint16
de_esm_re_attempt_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset,
guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, offset << 3, 6, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_esm_eplmnc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_esm_ratc, tvb, offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_nas_eps_extraneous_data);
return len;
}
static guint16
de_esm_nbifom_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
if (nbifom_handle) {
tvbuff_t *nbifom_tvb = tvb_new_subset_length(tvb, offset, len);
call_dissector(nbifom_handle, nbifom_tvb, pinfo, tree);
} else {
proto_tree_add_item(tree, hf_nas_eps_esm_nbifom_cont, tvb, offset, len, ENC_NA);
}
return len;
}
static guint16
de_esm_remote_ue_context_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo,
guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset = offset;
guint32 nb_ue_contexts, ue_context_len, nb_user_id, user_id_len, user_id_type, remote_address_type, i, j;
proto_tree *subtree;
proto_item *subtree_item;
proto_tree_add_item_ret_uint(tree, hf_nas_eps_esm_remote_ue_context_list_nb_ue_contexts, tvb, curr_offset, 1, ENC_BIG_ENDIAN, &nb_ue_contexts);
curr_offset ++;
for (i = 1; i <= nb_ue_contexts; i++) {
subtree = proto_tree_add_subtree_format(tree, tvb, curr_offset, len - (curr_offset - offset), ett_nas_eps_remote_ue_context,
&subtree_item, "Remote UE context %u", i);
proto_tree_add_item_ret_uint(subtree, hf_nas_eps_esm_remote_ue_context_list_ue_context_len, tvb, curr_offset, 1, ENC_BIG_ENDIAN, &ue_context_len);
proto_item_set_len(subtree_item, ue_context_len+1);
curr_offset ++;
proto_tree_add_item_ret_uint(subtree, hf_nas_eps_esm_remote_ue_context_list_ue_context_nb_user_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN, &nb_user_id);
curr_offset ++;
for (j = 0; j < nb_user_id; j++) {
proto_tree_add_item_ret_uint(subtree, hf_nas_eps_esm_remote_ue_context_list_ue_context_user_id_len, tvb, curr_offset, 1, ENC_BIG_ENDIAN, &user_id_len);
curr_offset ++;
proto_tree_add_item(subtree, hf_nas_eps_esm_remote_ue_context_list_ue_context_odd_even_indic, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item_ret_uint(subtree, hf_nas_eps_esm_remote_ue_context_list_ue_context_user_id_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN, &user_id_type);
switch (user_id_type) {
case 1:
proto_tree_add_bits_item(subtree, hf_nas_eps_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(subtree, hf_nas_eps_esm_remote_ue_context_list_ue_context_encr_imsi, tvb, curr_offset, 16, ENC_NA);
curr_offset += 16;
break;
case 2:
dissect_e212_imsi(tvb, pinfo, subtree, curr_offset, user_id_len, TRUE);
curr_offset += user_id_len;
break;
case 3:
{
const gchar *msisdn_str = tvb_bcd_dig_to_wmem_packet_str(tvb, curr_offset, user_id_len, NULL, TRUE);
proto_tree_add_string(subtree, hf_nas_eps_esm_remote_ue_context_list_ue_context_msisdn, tvb, curr_offset, user_id_len, msisdn_str);
curr_offset += user_id_len;
}
break;
case 4:
{
const gchar *imei_str = tvb_bcd_dig_to_wmem_packet_str(tvb, curr_offset, user_id_len, NULL, TRUE);
proto_tree_add_string(subtree, hf_nas_eps_esm_remote_ue_context_list_ue_context_imei, tvb, curr_offset, user_id_len, imei_str);
curr_offset += user_id_len;
}
break;
case 5:
{
const gchar *imeisv_str = tvb_bcd_dig_to_wmem_packet_str(tvb, curr_offset, user_id_len, NULL, TRUE);
proto_tree_add_string(subtree, hf_nas_eps_esm_remote_ue_context_list_ue_context_imeisv, tvb, curr_offset, user_id_len, imeisv_str);
curr_offset += user_id_len;
}
break;
default:
curr_offset += user_id_len;
break;
}
}
proto_tree_add_bits_item(subtree, hf_nas_eps_spare_bits, tvb, curr_offset<<3, 5, ENC_BIG_ENDIAN);
proto_tree_add_item_ret_uint(subtree, hf_nas_eps_esm_remote_ue_context_list_ue_context_address_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN, &remote_address_type);
curr_offset++;
switch (remote_address_type) {
case 1:
proto_tree_add_item(subtree, hf_nas_eps_esm_remote_ue_context_list_ue_context_ipv4, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset += 4;
proto_tree_add_item(subtree, hf_nas_eps_esm_remote_ue_context_list_ue_context_port_number, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
break;
case 2:
proto_tree_add_item(subtree, hf_nas_eps_esm_remote_ue_context_list_ue_context_ipv6_prefix, tvb, curr_offset, 8, ENC_NA);
curr_offset += 8;
break;
case 0:
default:
break;
}
}
return len;
}
static guint16
de_esm_pkmf_address(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset = offset;
guint32 pkmf_address_type;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, curr_offset<<3, 5, ENC_BIG_ENDIAN);
proto_tree_add_item_ret_uint(tree, hf_nas_eps_esm_pkmf_address_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN, &pkmf_address_type);
curr_offset++;
switch (pkmf_address_type) {
case 1:
proto_tree_add_item(tree, hf_nas_eps_esm_pkmf_ipv4, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(tree, hf_nas_eps_esm_pkmf_ipv6, tvb, curr_offset, 16, ENC_NA);
break;
default:
break;
}
return len;
}
static guint16
de_esm_hdr_compr_config(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset = offset;
static const int * flags[] = {
&hf_nas_eps_esm_spare_bit0x80,
&hf_nas_eps_esm_hdr_comp_config_prof_0104,
&hf_nas_eps_esm_hdr_comp_config_prof_0103,
&hf_nas_eps_esm_hdr_comp_config_prof_0102,
&hf_nas_eps_esm_hdr_comp_config_prof_0006,
&hf_nas_eps_esm_hdr_comp_config_prof_0004,
&hf_nas_eps_esm_hdr_comp_config_prof_0003,
&hf_nas_eps_esm_hdr_comp_config_prof_0002,
NULL
};
proto_tree_add_bitmask_list(tree, tvb, curr_offset, 1, flags, ENC_NA);
curr_offset++;
proto_tree_add_item(tree, hf_nas_eps_esm_hdr_compr_config_max_cid, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
if ((curr_offset - offset) >= len) {
return len;
}
proto_tree_add_item(tree, hf_nas_eps_esm_hdr_compr_config_add_hdr_compr_cxt_setup_params_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_nas_eps_esm_hdr_compr_config_add_hdr_compr_cxt_setup_params_cont, tvb, curr_offset, len - (curr_offset - offset), ENC_NA);
return len;
}
static guint16
de_esm_ctrl_plane_only_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, (offset<<3)+4, 3, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_nas_eps_esm_ctrl_plane_only_ind_cpoi, tvb, (offset<<3)+7, 1, ENC_BIG_ENDIAN);
return 1;
}
static guint16
de_esm_user_data_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
proto_item *it;
proto_tree *subtree;
tvbuff_t *user_data_cont_tvb;
it = proto_tree_add_item(tree, hf_nas_eps_esm_user_data_cont, tvb, offset, len, ENC_NA);
if (g_nas_eps_user_data_container_as_ip) {
subtree = proto_item_add_subtree(it, ett_nas_eps_esm_user_data_cont);
user_data_cont_tvb = tvb_new_subset_length_caplen(tvb, offset, len, len);
switch (tvb_get_guint8(user_data_cont_tvb, 0) & 0xf0) {
case 0x40:
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/");
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_set_fence(pinfo->cinfo, COL_INFO);
call_dissector_only(ipv4_handle, user_data_cont_tvb, pinfo, subtree, NULL);
break;
case 0x60:
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/");
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_set_fence(pinfo->cinfo, COL_INFO);
call_dissector_only(ipv6_handle, user_data_cont_tvb, pinfo, subtree, NULL);
break;
default:
break;
}
}
return len;
}
static guint16
de_esm_rel_assist_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, (offset<<3)+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_nas_eps_esm_rel_assist_ind_ddx, tvb, (offset<<3)+6, 2, ENC_BIG_ENDIAN);
return 1;
}
static guint16
de_esm_ext_pco(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo,
guint32 offset, guint len, gchar *add_string, int string_len)
{
return de_sm_pco(tvb, tree, pinfo, offset, len, add_string, string_len);
}
static guint16
de_esm_hdr_compr_config_status(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
static const int * flags[] = {
&hf_nas_eps_esm_hdr_compr_config_status_ebi7,
&hf_nas_eps_esm_hdr_compr_config_status_ebi6,
&hf_nas_eps_esm_hdr_compr_config_status_ebi5,
&hf_nas_eps_esm_spare_bits0x1f00,
&hf_nas_eps_esm_hdr_compr_config_status_ebi15,
&hf_nas_eps_esm_hdr_compr_config_status_ebi14,
&hf_nas_eps_esm_hdr_compr_config_status_ebi13,
&hf_nas_eps_esm_hdr_compr_config_status_ebi12,
&hf_nas_eps_esm_hdr_compr_config_status_ebi11,
&hf_nas_eps_esm_hdr_compr_config_status_ebi10,
&hf_nas_eps_esm_hdr_compr_config_status_ebi9,
&hf_nas_eps_esm_hdr_compr_config_status_ebi8,
NULL
};
proto_tree_add_bitmask_list(tree, tvb, offset, 2, flags, ENC_BIG_ENDIAN);
return len;
}
static guint16
de_esm_serv_plmn_rate_ctrl(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_,
guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
proto_item *pi;
pi = proto_tree_add_item(tree, hf_nas_eps_esm_serv_plmn_rate_ctrl_val, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(pi, " message(s)");
return len;
}
static void
nas_emm_attach_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_spare_half_octet, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_EPS_attach_result, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
curr_len--;
curr_offset++;
ELEM_MAND_V(GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER, " - T3412 value");
ELEM_MAND_LV(NAS_PDU_TYPE_EMM, DE_EMM_TRAC_AREA_ID_LST, " - TAI list");
ELEM_MAND_LV_E(NAS_PDU_TYPE_EMM, DE_EMM_ESM_MSG_CONT, NULL);
ELEM_OPT_TLV(0x50, NAS_PDU_TYPE_EMM, DE_EMM_EPS_MID, " - GUTI");
ELEM_OPT_TV(0x13, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_LOC_AREA_ID, NULL);
ELEM_OPT_TLV(0x23, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_MOB_ID, " - MS identity");
ELEM_OPT_TV(0x53, NAS_PDU_TYPE_EMM, DE_EMM_CAUSE, NULL);
ELEM_OPT_TV(0x17, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER, " - T3402 value");
ELEM_OPT_TV(0x59, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER, " - T3423 value");
ELEM_OPT_TLV(0x4a, GSM_A_PDU_TYPE_COMMON, DE_PLMN_LIST, " - Equivalent PLMNs");
ELEM_OPT_TLV(0x34, GSM_A_PDU_TYPE_DTAP, DE_EMERGENCY_NUM_LIST, NULL);
ELEM_OPT_TLV(0x64, NAS_PDU_TYPE_EMM, DE_EMM_EPS_NET_FEATURE_SUP, NULL);
ELEM_OPT_TV_SHORT( 0xF0 , NAS_PDU_TYPE_EMM, DE_EMM_ADD_UPD_RES, NULL );
ELEM_OPT_TLV(0x5E, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - T3412 extended value");
ELEM_OPT_TLV(0x6A, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3324");
ELEM_OPT_TLV(0x6E, GSM_A_PDU_TYPE_GM, DE_EXT_DRX_PARAMS, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_attach_comp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_LV_E(NAS_PDU_TYPE_EMM, DE_EMM_ESM_MSG_CONT, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_attach_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_CAUSE, NULL);
ELEM_OPT_TLV_E(0x78, NAS_PDU_TYPE_EMM, DE_EMM_ESM_MSG_CONT, NULL);
ELEM_OPT_TLV(0x5F, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3346 value");
ELEM_OPT_TLV(0x16, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3402 value");
ELEM_OPT_TV_SHORT( 0xA0, NAS_PDU_TYPE_EMM, DE_EMM_EXT_CAUSE, NULL );
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_attach_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
bit_offset = curr_offset<<3;
pinfo->link_dir = P2P_DIR_UL;
de_emm_nas_key_set_id_bits(tvb, tree, bit_offset, NULL);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_eps_att_type, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
curr_len--;
curr_offset++;
ELEM_MAND_LV(NAS_PDU_TYPE_EMM, DE_EMM_EPS_MID, NULL);
ELEM_MAND_LV(NAS_PDU_TYPE_EMM, DE_EMM_UE_NET_CAP, NULL);
ELEM_MAND_LV_E(NAS_PDU_TYPE_EMM, DE_EMM_ESM_MSG_CONT, NULL);
ELEM_OPT_TV( 0x19 , GSM_A_PDU_TYPE_GM, DE_P_TMSI_SIG, " - Old P-TMSI Signature");
ELEM_OPT_TLV( 0x50 , NAS_PDU_TYPE_EMM, DE_EMM_EPS_MID, " - Additional GUTI");
ELEM_OPT_TV(0x52, NAS_PDU_TYPE_EMM, DE_EMM_TRAC_AREA_ID, " - Last visited registered TAI");
ELEM_OPT_TV(0x5c, GSM_A_PDU_TYPE_GM, DE_DRX_PARAM, NULL );
ELEM_OPT_TLV( 0x31, GSM_A_PDU_TYPE_GM, DE_MS_NET_CAP , NULL );
ELEM_OPT_TV(0x13, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_LOC_AREA_ID, " - Old location area identification");
ELEM_OPT_TV_SHORT( 0x90 , GSM_A_PDU_TYPE_GM, DE_TMSI_STAT , NULL );
ELEM_OPT_TLV( 0x11, NAS_PDU_TYPE_COMMON, DE_EPS_MS_CM_2 , NULL );
ELEM_OPT_TLV( 0x20, NAS_PDU_TYPE_COMMON, DE_EPS_MS_CM_3 , NULL );
ELEM_OPT_TLV(0x40, GSM_A_PDU_TYPE_DTAP, DE_SUP_CODEC_LIST, " - Supported Codecs");
ELEM_OPT_TV_SHORT( 0xF0 , NAS_PDU_TYPE_EMM, DE_EMM_ADD_UPD_TYPE, NULL );
ELEM_OPT_TLV(0x5D, GSM_A_PDU_TYPE_GM, DE_VOICE_DOMAIN_PREF, NULL);
ELEM_OPT_TV_SHORT(0xD0 , GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
ELEM_OPT_TV_SHORT(0xE0 , NAS_PDU_TYPE_EMM, DE_EMM_GUTI_TYPE, " - Old GUTI type");
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_COMMON, DE_MS_NET_FEAT_SUP, NULL);
ELEM_OPT_TLV(0x10, GSM_A_PDU_TYPE_GM, DE_NET_RES_ID_CONT, " - TMSI based NRI container");
ELEM_OPT_TLV(0x6A, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3324 value");
ELEM_OPT_TLV(0x5E, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - T3412 extended value");
ELEM_OPT_TLV(0x6E, GSM_A_PDU_TYPE_GM, DE_EXT_DRX_PARAMS, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_auth_fail(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_CAUSE, NULL);
ELEM_OPT_TLV(0x30, GSM_A_PDU_TYPE_DTAP, DE_AUTH_FAIL_PARAM, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_auth_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_spare_half_octet, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
de_emm_nas_key_set_id_bits(tvb, tree, bit_offset, " ASME");
curr_len--;
curr_offset++;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_AUTH_PARAM_RAND, " - EPS challenge");
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_AUTH_PARAM_AUTN, " - EPS challenge");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_auth_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_LV(NAS_PDU_TYPE_EMM, DE_EMM_AUTH_RESP_PAR, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_cs_serv_not(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_PAGING_ID, NULL);
ELEM_OPT_TLV(0x60, GSM_A_PDU_TYPE_DTAP, DE_CLG_PARTY_BCD_NUM, " - CLI");
ELEM_OPT_TV(0x61, NAS_PDU_TYPE_EMM, DE_EMM_SS_CODE, NULL);
ELEM_OPT_TV(0x62, NAS_PDU_TYPE_EMM, DE_EMM_LCS_IND, NULL);
ELEM_OPT_TLV(0x63, NAS_PDU_TYPE_EMM, DE_EMM_LCS_CLIENT_ID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_detach_req_UL(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset,bit_offset;
guint32 consumed;
guint curr_len;
guint64 switch_off;
guint64 detach_type;
curr_offset = offset;
curr_len = len;
proto_tree_add_item(tree, hf_nas_eps_emm_detach_req_UL, tvb, curr_offset, len, ENC_NA);
bit_offset = curr_offset<<3;
de_emm_nas_key_set_id_bits(tvb, tree, bit_offset, NULL);
bit_offset+=4;
proto_tree_add_bits_ret_val(tree, hf_nas_eps_emm_switch_off, tvb, bit_offset, 1, &switch_off, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_ret_val(tree, hf_nas_eps_emm_detach_type_UL, tvb, bit_offset, 3, &detach_type, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s%s)",
val_to_str_const((guint32)detach_type, nas_eps_emm_type_of_detach_UL_vals, "Unknown"),
(switch_off==0) ? "" : " / switch-off");
curr_len--;
curr_offset++;
ELEM_MAND_LV(NAS_PDU_TYPE_EMM, DE_EMM_EPS_MID, NULL);
}
static void
nas_emm_detach_req_DL(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
guint64 detach_type;
curr_offset = offset;
curr_len = len;
proto_tree_add_item(tree, hf_nas_eps_emm_detach_req_DL, tvb, curr_offset, len, ENC_NA);
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_ret_val(tree, hf_nas_eps_emm_detach_type_DL, tvb, bit_offset, 3, &detach_type, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
val_to_str_const((guint32)detach_type, nas_eps_emm_type_of_detach_DL_vals, "Unknown"));
curr_len--;
curr_offset++;
ELEM_OPT_TV(0x53, NAS_PDU_TYPE_EMM, DE_EMM_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_detach_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
if (pinfo->link_dir == P2P_DIR_UL) {
nas_emm_detach_req_UL(tvb, tree, pinfo, offset, len);
return;
}else if (pinfo->link_dir == P2P_DIR_DL) {
nas_emm_detach_req_DL(tvb, tree, pinfo, offset, len);
return;
}
if (len >= 8) {
nas_emm_detach_req_UL(tvb, tree, pinfo, offset, len);
} else {
nas_emm_detach_req_DL(tvb, tree, pinfo, offset, len);
}
}
static void
nas_emm_dl_nas_trans(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_LV(NAS_PDU_TYPE_EMM, DE_EMM_NAS_MSG_CONT, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_emm_inf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_OPT_TLV(0x43, GSM_A_PDU_TYPE_DTAP, DE_NETWORK_NAME, " - Full name for network");
ELEM_OPT_TLV(0x45, GSM_A_PDU_TYPE_DTAP, DE_NETWORK_NAME, " - Short Name");
ELEM_OPT_TV(0x46, GSM_A_PDU_TYPE_DTAP, DE_TIME_ZONE, " - Local");
ELEM_OPT_TV(0x47, GSM_A_PDU_TYPE_DTAP, DE_TIME_ZONE_TIME, " - Universal Time and Local Time Zone");
ELEM_OPT_TLV(0x49, GSM_A_PDU_TYPE_DTAP, DE_DAY_SAVING_TIME, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_emm_status(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_ext_serv_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset,bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
bit_offset = curr_offset<<3;
pinfo->link_dir = P2P_DIR_UL;
de_emm_nas_key_set_id_bits(tvb, tree, bit_offset, NULL);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_service_type, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
curr_len--;
curr_offset++;
ELEM_MAND_LV(NAS_PDU_TYPE_COMMON, DE_EPS_CMN_MOB_ID, " - M-TMSI");
ELEM_OPT_TV_SHORT(0xb0, NAS_PDU_TYPE_EMM, DE_EMM_CSFB_RESP, NULL);
ELEM_OPT_TLV(0x57, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_EPS_BE_CTX_STATUS, NULL);
ELEM_OPT_TV_SHORT(0xD0 , GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_guti_realloc_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_LV(NAS_PDU_TYPE_EMM, DE_EMM_EPS_MID, " - GUTI");
ELEM_OPT_TLV(0x54, NAS_PDU_TYPE_EMM, DE_EMM_TRAC_AREA_ID_LST, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_id_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
bit_offset=curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_spare_half_octet, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_id_type2, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
curr_len--;
curr_offset++;
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_id_res(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_LV(NAS_PDU_TYPE_COMMON, DE_EPS_CMN_MOB_ID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_sec_mode_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_NAS_SEC_ALGS, " - Selected NAS security algorithms");
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_spare_half_octet, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
de_emm_nas_key_set_id_bits(tvb, tree, bit_offset, " ASME");
curr_len--;
curr_offset++;
ELEM_MAND_LV(NAS_PDU_TYPE_EMM, DE_EMM_UE_SEC_CAP, " - Replayed UE security capabilities");
ELEM_OPT_TV_SHORT( 0xC0 , NAS_PDU_TYPE_EMM, DE_EMM_IMEISV_REQ , NULL );
ELEM_OPT_TV(0x55, NAS_PDU_TYPE_EMM, DE_EMM_NONCE, " - Replayed NonceUE");
ELEM_OPT_TV(0x56, NAS_PDU_TYPE_EMM, DE_EMM_NONCE, " - NonceMME");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_sec_mode_comp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_OPT_TLV(0x23, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_MOB_ID, " - IMEISV");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_sec_mode_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_serv_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_CAUSE, NULL);
ELEM_OPT_TV(0x5b, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER, " - T3442 value");
ELEM_OPT_TLV(0x5F, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3346 value");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_service_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_KSI_AND_SEQ_NO, NULL);
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_SHORT_MAC, " - Message authentication code (short)");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_trac_area_upd_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_spare_half_octet, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_nas_eps_eps_update_result_value, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
curr_len--;
curr_offset++;
ELEM_OPT_TV(0x5a, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER, " - T3412 value");
ELEM_OPT_TLV(0x50, NAS_PDU_TYPE_EMM, DE_EMM_EPS_MID, " - GUTI");
ELEM_OPT_TLV(0x54, NAS_PDU_TYPE_EMM, DE_EMM_TRAC_AREA_ID_LST, NULL);
ELEM_OPT_TLV(0x57, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_EPS_BE_CTX_STATUS, NULL);
ELEM_OPT_TV(0x13, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_LOC_AREA_ID, NULL);
ELEM_OPT_TLV(0x23, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_MOB_ID, " - MS identity");
ELEM_OPT_TV(0x53, NAS_PDU_TYPE_EMM, DE_EMM_CAUSE, NULL);
ELEM_OPT_TV(0x17, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER, " - T3402 value");
ELEM_OPT_TV(0x59, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER, " - T3423 value");
ELEM_OPT_TLV(0x4a, GSM_A_PDU_TYPE_COMMON, DE_PLMN_LIST, " - PLMN list");
ELEM_OPT_TLV(0x34, GSM_A_PDU_TYPE_DTAP, DE_EMERGENCY_NUM_LIST, NULL);
ELEM_OPT_TLV(0x64, NAS_PDU_TYPE_EMM, DE_EMM_EPS_NET_FEATURE_SUP, NULL);
ELEM_OPT_TV_SHORT( 0xF0 , NAS_PDU_TYPE_EMM, DE_EMM_ADD_UPD_RES, NULL );
ELEM_OPT_TLV(0x5E, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - T3412 extended value");
ELEM_OPT_TLV(0x6A, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3324");
ELEM_OPT_TLV(0x6E, GSM_A_PDU_TYPE_GM, DE_EXT_DRX_PARAMS, NULL);
ELEM_OPT_TLV(0x68, NAS_PDU_TYPE_ESM, DE_ESM_HDR_COMPR_CONFIG_STATUS, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_trac_area_upd_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_CAUSE, NULL);
ELEM_OPT_TLV(0x5F, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3346 value");
ELEM_OPT_TV_SHORT( 0xA0, NAS_PDU_TYPE_EMM, DE_EMM_EXT_CAUSE, NULL );
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_trac_area_upd_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
bit_offset = curr_offset<<3;
pinfo->link_dir = P2P_DIR_UL;
de_emm_nas_key_set_id_bits(tvb, tree, bit_offset, " ASME");
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_active_flg, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_nas_eps_eps_update_type_value, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
curr_len--;
curr_offset++;
ELEM_MAND_LV(NAS_PDU_TYPE_EMM, DE_EMM_EPS_MID, " - Old GUTI");
ELEM_OPT_TV_SHORT( 0xb0 , NAS_PDU_TYPE_EMM, DE_EMM_NAS_KEY_SET_ID , " - Non-current native NAS key set identifier" );
ELEM_OPT_TV_SHORT(0x80, GSM_A_PDU_TYPE_COMMON, DE_CIPH_KEY_SEQ_NUM, " - GPRS ciphering key sequence number");
ELEM_OPT_TV( 0x19 , GSM_A_PDU_TYPE_GM, DE_P_TMSI_SIG, " - Old P-TMSI Signature");
ELEM_OPT_TLV(0x50, NAS_PDU_TYPE_EMM, DE_EMM_EPS_MID, " - Additional GUTI");
ELEM_OPT_TV(0x55, NAS_PDU_TYPE_EMM, DE_EMM_NONCE, " - NonceUE");
ELEM_OPT_TLV(0x58, NAS_PDU_TYPE_EMM, DE_EMM_UE_NET_CAP, NULL);
ELEM_OPT_TV(0x52, NAS_PDU_TYPE_EMM, DE_EMM_TRAC_AREA_ID, " - Last visited registered TAI");
ELEM_OPT_TV(0x5c, GSM_A_PDU_TYPE_GM, DE_DRX_PARAM, NULL );
ELEM_OPT_TV_SHORT( 0xA0, NAS_PDU_TYPE_EMM, DE_EMM_UE_RA_CAP_INF_UPD_NEED, NULL );
ELEM_OPT_TLV(0x57, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_EPS_BE_CTX_STATUS, NULL);
ELEM_OPT_TLV( 0x31, GSM_A_PDU_TYPE_GM, DE_MS_NET_CAP, NULL );
ELEM_OPT_TV(0x13, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_LOC_AREA_ID, " - Old location area identification");
ELEM_OPT_TV_SHORT( 0x90, GSM_A_PDU_TYPE_GM, DE_TMSI_STAT, NULL );
ELEM_OPT_TLV( 0x11, NAS_PDU_TYPE_COMMON, DE_EPS_MS_CM_2 , NULL );
ELEM_OPT_TLV( 0x20, NAS_PDU_TYPE_COMMON, DE_EPS_MS_CM_3 , NULL );
ELEM_OPT_TLV(0x40, GSM_A_PDU_TYPE_DTAP, DE_SUP_CODEC_LIST, " - Supported Codecs");
ELEM_OPT_TV_SHORT( 0xF0, NAS_PDU_TYPE_EMM, DE_EMM_ADD_UPD_TYPE, NULL );
ELEM_OPT_TLV(0x5D, GSM_A_PDU_TYPE_GM, DE_VOICE_DOMAIN_PREF, NULL);
ELEM_OPT_TV_SHORT(0xE0, NAS_PDU_TYPE_EMM, DE_EMM_GUTI_TYPE, " - Old GUTI type");
ELEM_OPT_TV_SHORT(0xD0, GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
ELEM_OPT_TV_SHORT(0xC0, GSM_A_PDU_TYPE_COMMON, DE_MS_NET_FEAT_SUP, NULL);
ELEM_OPT_TLV(0x10, GSM_A_PDU_TYPE_GM, DE_NET_RES_ID_CONT, " - TMSI based NRI container");
ELEM_OPT_TLV(0x6A, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3324 value");
ELEM_OPT_TLV(0x5E, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - T3412 extended value");
ELEM_OPT_TLV(0x6E, GSM_A_PDU_TYPE_GM, DE_EXT_DRX_PARAMS, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_ul_nas_trans(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_LV(NAS_PDU_TYPE_EMM, DE_EMM_NAS_MSG_CONT, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_dl_gen_nas_trans(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_GEN_MSG_CONT_TYPE, NULL);
ELEM_MAND_LV_E(NAS_PDU_TYPE_EMM, DE_EMM_GEN_MSG_CONT, NULL)
ELEM_OPT_TLV(0x65, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_ADD_INFO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
eps_nas_gen_msg_cont_type = 0;
}
static void
nas_emm_ul_gen_nas_trans(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_GEN_MSG_CONT_TYPE, NULL);
ELEM_MAND_LV_E(NAS_PDU_TYPE_EMM, DE_EMM_GEN_MSG_CONT, NULL)
ELEM_OPT_TLV(0x65, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_ADD_INFO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
eps_nas_gen_msg_cont_type = 0;
}
static void
nas_emm_ctrl_plane_serv_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
bit_offset = curr_offset<<3;
pinfo->link_dir = P2P_DIR_UL;
de_emm_nas_key_set_id_bits(tvb, tree, bit_offset, NULL);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_active_flg, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_nas_eps_ctrl_plane_serv_type, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
curr_len--;
curr_offset++;
ELEM_OPT_TLV_E(0x78, NAS_PDU_TYPE_EMM, DE_EMM_ESM_MSG_CONT, NULL);
ELEM_OPT_TLV(0x67, NAS_PDU_TYPE_EMM, DE_EMM_NAS_MSG_CONT, NULL);
ELEM_OPT_TLV(0x57, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_EPS_BE_CTX_STATUS, NULL);
ELEM_OPT_TV_SHORT(0xD0, GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_emm_serv_accept(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_OPT_TLV(0x57, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_EPS_BE_CTX_STATUS, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_act_ded_eps_bearer_ctx_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TLV(0x33, NAS_PDU_TYPE_ESM, DE_ESM_NBIFOM_CONT, NULL);
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_act_ded_eps_bearer_ctx_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_V(NAS_PDU_TYPE_ESM, DE_ESM_CAUSE, NULL);
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TLV(0x33, NAS_PDU_TYPE_ESM, DE_ESM_NBIFOM_CONT, NULL);
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_act_ded_eps_bearer_ctx_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_spare_half_octet, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_esm_linked_bearer_id, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
curr_len--;
curr_offset++;
ELEM_MAND_LV(NAS_PDU_TYPE_ESM, DE_ESM_EPS_QOS, NULL);
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_TRAFFIC_FLOW_TEMPLATE , NULL );
ELEM_OPT_TLV( 0x5d , GSM_A_PDU_TYPE_GM, DE_LINKED_TI , " - Transaction identifier" );
ELEM_OPT_TLV( 0x30 , GSM_A_PDU_TYPE_GM, DE_QOS , " - Negotiated QoS" );
ELEM_OPT_TV( 0x32 , GSM_A_PDU_TYPE_GM, DE_LLC_SAPI , " - Negotiated LLC SAPI" );
ELEM_OPT_TV_SHORT ( 0x80 , GSM_A_PDU_TYPE_GM , DE_RAD_PRIO , NULL );
ELEM_OPT_TLV( 0x34 , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL );
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_GM, DE_SM_WLAN_OFFLOAD_ACCEPT, " - WLAN offload indication");
ELEM_OPT_TLV(0x33, NAS_PDU_TYPE_ESM, DE_ESM_NBIFOM_CONT, NULL);
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_act_def_eps_bearer_ctx_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_act_def_eps_bearer_ctx_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_V(NAS_PDU_TYPE_ESM, DE_ESM_CAUSE, NULL);
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_act_def_eps_bearer_ctx_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_LV(NAS_PDU_TYPE_ESM, DE_ESM_EPS_QOS, NULL);
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_ACC_POINT_NAME , NULL );
ELEM_MAND_LV( NAS_PDU_TYPE_ESM, DE_ESM_PDN_ADDR , NULL );
ELEM_OPT_TLV( 0x5d , GSM_A_PDU_TYPE_GM, DE_LINKED_TI , " - Transaction identifier" );
ELEM_OPT_TLV( 0x30 , GSM_A_PDU_TYPE_GM, DE_QOS , " - Negotiated QoS" );
ELEM_OPT_TV( 0x32 , GSM_A_PDU_TYPE_GM, DE_LLC_SAPI , " - Negotiated LLC SAPI" );
ELEM_OPT_TV_SHORT ( 0x80 , GSM_A_PDU_TYPE_GM , DE_RAD_PRIO , NULL );
ELEM_OPT_TLV( 0x34 , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL );
ELEM_OPT_TLV( 0x5e , NAS_PDU_TYPE_ESM, DE_ESM_APN_AGR_MAX_BR , NULL );
ELEM_OPT_TV( 0x58 , NAS_PDU_TYPE_ESM, DE_ESM_CAUSE , NULL );
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TV_SHORT(0xB0 , GSM_A_PDU_TYPE_GM, DE_SM_CONNECTIVITY_TYPE, NULL);
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_GM, DE_SM_WLAN_OFFLOAD_ACCEPT, " - WLAN offload indication");
ELEM_OPT_TLV(0x33, NAS_PDU_TYPE_ESM, DE_ESM_NBIFOM_CONT, NULL);
ELEM_OPT_TLV(0x66, NAS_PDU_TYPE_ESM, DE_ESM_HDR_COMPR_CONFIG, NULL);
ELEM_OPT_TV_SHORT(0x90, NAS_PDU_TYPE_ESM, DE_ESM_CTRL_PLANE_ONLY_IND, NULL);
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
ELEM_OPT_TLV(0x6E, NAS_PDU_TYPE_ESM, DE_ESM_SERV_PLMN_RATE_CTRL, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_bearer_res_all_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V(NAS_PDU_TYPE_ESM, DE_ESM_CAUSE, NULL);
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TLV(0x37, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - Back-off timer value");
ELEM_OPT_TLV(0x6B, NAS_PDU_TYPE_ESM, DE_ESM_RE_ATTEMPT_IND, NULL);
ELEM_OPT_TLV(0x33, NAS_PDU_TYPE_ESM, DE_ESM_NBIFOM_CONT, NULL);
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_bearer_res_all_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_spare_half_octet, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_esm_linked_bearer_id, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
curr_len--;
curr_offset++;
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_TRAFFIC_FLOW_TEMPLATE , " - Traffic flow aggregate" );
ELEM_MAND_LV(NAS_PDU_TYPE_ESM, DE_ESM_EPS_QOS, " - Required traffic flow QoS");
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
ELEM_OPT_TLV(0x33, NAS_PDU_TYPE_ESM, DE_ESM_NBIFOM_CONT, NULL);
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_bearer_res_mod_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V(NAS_PDU_TYPE_ESM, DE_ESM_CAUSE, NULL);
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TLV(0x37, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - Back-off timer value");
ELEM_OPT_TLV(0x6B, NAS_PDU_TYPE_ESM, DE_ESM_RE_ATTEMPT_IND, NULL);
ELEM_OPT_TLV(0x33, NAS_PDU_TYPE_ESM, DE_ESM_NBIFOM_CONT, NULL);
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_bearer_res_mod_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_spare_half_octet, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_esm_linked_bearer_id, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
curr_len--;
curr_offset++;
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_TRAFFIC_FLOW_TEMPLATE , " - Traffic flow aggregate" );
ELEM_OPT_TLV( 0x5B , NAS_PDU_TYPE_ESM, DE_ESM_EPS_QOS , " - Required traffic flow QoS" );
ELEM_OPT_TV( 0x58 , NAS_PDU_TYPE_ESM, DE_ESM_CAUSE , NULL );
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
ELEM_OPT_TLV(0x33, NAS_PDU_TYPE_ESM, DE_ESM_NBIFOM_CONT, NULL);
ELEM_OPT_TLV(0x66, NAS_PDU_TYPE_ESM, DE_ESM_HDR_COMPR_CONFIG, NULL);
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_deact_eps_bearer_ctx_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_deact_eps_bearer_ctx_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V(NAS_PDU_TYPE_ESM, DE_ESM_CAUSE, NULL);
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TLV(0x37, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - T3396 value");
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_GM, DE_SM_WLAN_OFFLOAD_ACCEPT, " - WLAN offload indication");
ELEM_OPT_TLV(0x33, NAS_PDU_TYPE_ESM, DE_ESM_NBIFOM_CONT, NULL);
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_dummy_msg(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_inf_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_inf_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_OPT_TLV( 0x28 , GSM_A_PDU_TYPE_GM, DE_ACC_POINT_NAME , NULL );
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_status(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(NAS_PDU_TYPE_ESM, DE_ESM_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_mod_eps_bearer_ctx_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TLV(0x33, NAS_PDU_TYPE_ESM, DE_ESM_NBIFOM_CONT, NULL);
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_mod_eps_bearer_ctx_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_V(NAS_PDU_TYPE_ESM, DE_ESM_CAUSE, NULL);
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TLV(0x33, NAS_PDU_TYPE_ESM, DE_ESM_NBIFOM_CONT, NULL);
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_mod_eps_bearer_ctx_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_OPT_TLV( 0x5B , NAS_PDU_TYPE_ESM, DE_ESM_EPS_QOS , " - New EPS QoS" );
ELEM_OPT_TLV( 0x36 , GSM_A_PDU_TYPE_GM, DE_TRAFFIC_FLOW_TEMPLATE , NULL );
ELEM_OPT_TLV( 0x30 , GSM_A_PDU_TYPE_GM, DE_QOS , " - New QoS" );
ELEM_OPT_TV( 0x32 , GSM_A_PDU_TYPE_GM, DE_LLC_SAPI , " - Negotiated LLC SAPI" );
ELEM_OPT_TV_SHORT ( 0x80 , GSM_A_PDU_TYPE_GM , DE_RAD_PRIO , NULL );
ELEM_OPT_TLV( 0x34 , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL );
ELEM_OPT_TLV( 0x5E , NAS_PDU_TYPE_ESM, DE_ESM_APN_AGR_MAX_BR , NULL );
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_GM, DE_SM_WLAN_OFFLOAD_ACCEPT, " - WLAN offload indication");
ELEM_OPT_TLV(0x33, NAS_PDU_TYPE_ESM, DE_ESM_NBIFOM_CONT, NULL);
ELEM_OPT_TLV(0x66, NAS_PDU_TYPE_ESM, DE_ESM_HDR_COMPR_CONFIG, NULL);
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_notification(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_LV(NAS_PDU_TYPE_ESM, DE_ESM_NOTIF_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_pdn_con_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V(NAS_PDU_TYPE_ESM, DE_ESM_CAUSE, NULL);
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TLV(0x37, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - Back-off timer value");
ELEM_OPT_TLV(0x6B, NAS_PDU_TYPE_ESM, DE_ESM_RE_ATTEMPT_IND, NULL);
ELEM_OPT_TLV(0x33, NAS_PDU_TYPE_ESM, DE_ESM_NBIFOM_CONT, NULL);
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
void
nas_esm_pdn_con_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
int bit_offset;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_esm_pdn_type, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_esm_request_type, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
curr_len--;
curr_offset++;
ELEM_OPT_TV_SHORT( 0xd0 , NAS_PDU_TYPE_ESM, DE_ESM_INF_TRF_FLG , NULL );
ELEM_OPT_TLV( 0x28 , GSM_A_PDU_TYPE_GM, DE_ACC_POINT_NAME , NULL );
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
ELEM_OPT_TLV(0x33, NAS_PDU_TYPE_ESM, DE_ESM_NBIFOM_CONT, NULL);
ELEM_OPT_TLV(0x66, NAS_PDU_TYPE_ESM, DE_ESM_HDR_COMPR_CONFIG, NULL);
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_pdn_disc_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V(NAS_PDU_TYPE_ESM, DE_ESM_CAUSE, NULL);
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_pdn_disc_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_spare_half_octet, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_esm_linked_bearer_id, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
curr_len--;
curr_offset++;
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_remote_ue_report(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_OPT_TLV_E(0x79, NAS_PDU_TYPE_ESM, DE_ESM_REMOTE_UE_CONTEXT_LIST, " - Remote UE Context Connected");
ELEM_OPT_TLV_E(0x7A, NAS_PDU_TYPE_ESM, DE_ESM_REMOTE_UE_CONTEXT_LIST, " - Remote UE Context Disconnected");
ELEM_OPT_TLV(0x6F, NAS_PDU_TYPE_ESM, DE_ESM_PKMF_ADDRESS, " - ProSe Key Management Function address");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_remote_ue_report_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_DL;
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
nas_esm_data_transport(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV_E(NAS_PDU_TYPE_ESM, DE_ESM_USER_DATA_CONT, NULL);
ELEM_OPT_TV_SHORT(0xF0, NAS_PDU_TYPE_ESM, DE_ESM_REL_ASSIST_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_nas_eps_extraneous_data);
}
static void
get_nas_esm_msg_params(guint8 oct, const gchar **msg_str, int *ett_tree, int *hf_idx, msg_fcn *msg_fcn_p)
{
gint idx;
*msg_str = try_val_to_str_idx_ext((guint32) (oct & 0xff), &nas_msg_esm_strings_ext, &idx);
*hf_idx = hf_nas_eps_msg_esm_type;
if (*msg_str != NULL) {
*ett_tree = ett_nas_msg_esm[idx];
*msg_fcn_p = nas_msg_esm_fcn[idx];
}
return;
}
static void
get_nas_emm_msg_params(guint8 oct, const gchar **msg_str, int *ett_tree, int *hf_idx, msg_fcn *msg_fcn_p)
{
gint idx;
*msg_str = try_val_to_str_idx_ext((guint32) (oct & 0xff), &nas_msg_emm_strings_ext, &idx);
*hf_idx = hf_nas_eps_msg_emm_type;
if (*msg_str != NULL) {
*ett_tree = ett_nas_msg_emm[idx];
*msg_fcn_p = nas_msg_emm_fcn[idx];
}
return;
}
static void
disect_nas_eps_esm_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
const gchar *msg_str;
guint32 len;
gint ett_tree;
int hf_idx;
void (*msg_fcn_p)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len);
guint8 oct;
len = tvb_reported_length(tvb);
proto_tree_add_item(tree, hf_nas_eps_bearer_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_L3_protocol_discriminator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_nas_eps_esm_proc_trans_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
oct = tvb_get_guint8(tvb,offset);
msg_fcn_p = NULL;
ett_tree = -1;
hf_idx = -1;
msg_str = NULL;
get_nas_esm_msg_params(oct, &msg_str, &ett_tree, &hf_idx, &msg_fcn_p);
if (msg_str) {
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, msg_str);
} else {
proto_tree_add_expert_format(tree, pinfo, &ei_nas_eps_unknown_msg_type, tvb, offset, 1, "Unknown Message Type 0x%02x", oct);
return;
}
proto_tree_add_item(tree, hf_idx, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (msg_fcn_p == NULL)
{
if (tvb_reported_length_remaining(tvb, offset)) {
proto_tree_add_item(tree, hf_nas_eps_msg_elems, tvb, offset, len - offset, ENC_NA);
}
}
else
{
(*msg_fcn_p)(tvb, tree, pinfo, offset, len - offset);
}
}
static void
dissect_nas_eps_emm_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, gboolean second_header)
{
const gchar *msg_str;
guint32 len;
gint ett_tree;
int hf_idx;
void (*msg_fcn_p)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len);
guint8 security_header_type, oct;
len = tvb_reported_length(tvb);
if (second_header) {
security_header_type = tvb_get_guint8(tvb,offset)>>4;
proto_tree_add_item(tree, hf_nas_eps_security_header_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_L3_protocol_discriminator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (security_header_type != 0) {
proto_tree_add_item(tree, hf_nas_eps_msg_auth_code, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_nas_eps_seq_no, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if ((security_header_type == 2)||(security_header_type == 4))
return;
proto_tree_add_item(tree, hf_nas_eps_security_header_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_L3_protocol_discriminator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
}
oct = tvb_get_guint8(tvb,offset);
msg_fcn_p = NULL;
ett_tree = -1;
hf_idx = -1;
msg_str = NULL;
get_nas_emm_msg_params(oct, &msg_str, &ett_tree, &hf_idx, &msg_fcn_p);
if (msg_str) {
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, msg_str);
} else {
proto_tree_add_expert_format(tree, pinfo, &ei_nas_eps_unknown_msg_type, tvb, offset, 1, "Unknown Message Type 0x%02x", oct);
return;
}
proto_tree_add_item(tree, hf_idx, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (msg_fcn_p == NULL)
{
if (tvb_reported_length_remaining(tvb, offset)) {
proto_tree_add_item(tree, hf_nas_eps_msg_elems, tvb, offset, len - offset, ENC_NA);
}
}
else
{
(*msg_fcn_p)(tvb, tree, pinfo, offset, len - offset);
}
}
static int
dissect_nas_eps_plain(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *item;
proto_tree *nas_eps_tree;
guint8 pd;
int offset = 0;
col_append_sep_str(pinfo->cinfo, COL_PROTOCOL, "/", "NAS-EPS");
item = proto_tree_add_item(tree, proto_nas_eps, tvb, 0, -1, ENC_NA);
nas_eps_tree = proto_item_add_subtree(item, ett_nas_eps);
pd = tvb_get_guint8(tvb,offset);
if (((pd&0x0f) == 0x07) && ((pd&0xf0) >= 0xc0)) {
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Service request");
proto_tree_add_item(nas_eps_tree, hf_nas_eps_security_header_type, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(nas_eps_tree, hf_gsm_a_L3_protocol_discriminator, tvb, 0, 1, ENC_BIG_ENDIAN);
offset++;
nas_emm_service_req(tvb, nas_eps_tree, pinfo, offset, tvb_reported_length(tvb)-offset);
return tvb_captured_length(tvb);
}
pd &= 0x0f;
switch (pd) {
case 2:
disect_nas_eps_esm_msg(tvb, pinfo, nas_eps_tree, offset);
break;
case 7:
dissect_nas_eps_emm_msg(tvb, pinfo, nas_eps_tree, offset, TRUE);
break;
case 15:
if (gsm_a_dtap_handle) {
tvbuff_t *new_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(gsm_a_dtap_handle, new_tvb,pinfo, nas_eps_tree);
break;
}
default:
proto_tree_add_expert_format(nas_eps_tree, pinfo, &ei_nas_eps_unknown_pd, tvb, offset, -1, "Not a NAS EPS PD %u (%s)",
pd, val_to_str_const(pd, protocol_discriminator_vals, "Unknown"));
break;
}
return tvb_captured_length(tvb);
}
static int
dissect_nas_eps(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *item;
proto_tree *nas_eps_tree;
guint8 pd, security_header_type;
int offset = 0;
guint32 len;
guint32 msg_auth_code;
len = tvb_reported_length(tvb);
if (len < 8) {
dissect_nas_eps_plain(tvb, pinfo, tree, data);
return tvb_captured_length(tvb);
}
if (g_nas_eps_dissect_plain) {
dissect_nas_eps_plain(tvb, pinfo, tree, data);
return tvb_captured_length(tvb);
}
col_append_sep_str(pinfo->cinfo, COL_PROTOCOL, "/", "NAS-EPS");
item = proto_tree_add_item(tree, proto_nas_eps, tvb, 0, -1, ENC_NA);
nas_eps_tree = proto_item_add_subtree(item, ett_nas_eps);
security_header_type = tvb_get_guint8(tvb,offset)>>4;
proto_tree_add_item(nas_eps_tree, hf_nas_eps_security_header_type, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(nas_eps_tree, hf_gsm_a_L3_protocol_discriminator, tvb, 0, 1, ENC_BIG_ENDIAN);
pd = tvb_get_guint8(tvb,offset)&0x0f;
offset++;
if (security_header_type == 0) {
if (pd == 7) {
dissect_nas_eps_emm_msg(tvb, pinfo, nas_eps_tree, offset, FALSE);
return tvb_captured_length(tvb);
} else {
proto_tree_add_expert(nas_eps_tree, pinfo, &ei_nas_eps_esm_tp_not_integ_prot, tvb, offset, len);
return tvb_captured_length(tvb);
}
} else {
if (security_header_type >= 12) {
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Service request");
nas_emm_service_req(tvb, nas_eps_tree, pinfo, offset, len-offset);
return tvb_captured_length(tvb);
}
proto_tree_add_item(nas_eps_tree, hf_nas_eps_msg_auth_code, tvb, offset, 4, ENC_BIG_ENDIAN);
msg_auth_code = tvb_get_ntohl(tvb, offset);
offset+=4;
if ((security_header_type == 2)||(security_header_type == 4)) {
if (msg_auth_code != 0) {
proto_tree_add_item(nas_eps_tree, hf_nas_eps_seq_no, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
pd = tvb_get_guint8(tvb,offset);
if (!g_nas_eps_null_decipher ||
((pd != 7) && (pd != 15) &&
(((pd&0x0f) != 2) || (((pd&0x0f) == 2) && ((pd&0xf0) > 0) && ((pd&0xf0) < 0x50))))) {
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Ciphered message");
proto_tree_add_item(nas_eps_tree, hf_nas_eps_ciphered_msg, tvb, offset, len-6, ENC_NA);
return tvb_captured_length(tvb);
}
} else {
proto_tree_add_item(nas_eps_tree, hf_nas_eps_seq_no, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
} else {
proto_tree_add_item(nas_eps_tree, hf_nas_eps_seq_no, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
}
pd = tvb_get_guint8(tvb,offset)&0x0f;
switch (pd) {
case 2:
disect_nas_eps_esm_msg(tvb, pinfo, nas_eps_tree, offset);
break;
case 7:
dissect_nas_eps_emm_msg(tvb, pinfo, nas_eps_tree, offset, TRUE);
break;
case 15:
if (gsm_a_dtap_handle) {
tvbuff_t *new_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(gsm_a_dtap_handle, new_tvb, pinfo, nas_eps_tree);
break;
}
default:
proto_tree_add_expert_format(nas_eps_tree, pinfo, &ei_nas_eps_unknown_pd, tvb, offset, -1, "Not a NAS EPS PD %u (%s)",
pd, val_to_str_const(pd, protocol_discriminator_vals, "Unknown"));
break;
}
return tvb_captured_length(tvb);
}
void
proto_register_nas_eps(void)
{
guint i;
guint last_offset;
module_t *nas_eps_module;
static hf_register_info hf[] = {
{ &hf_nas_eps_msg_emm_type,
{ "NAS EPS Mobility Management Message Type", "nas_eps.nas_msg_emm_type",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &nas_msg_emm_strings_ext, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_common_elem_id,
{ "Element ID", "nas_eps.common.elem_id",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_elem_id,
{ "Element ID", "nas_eps.emm.elem_id",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_nas_eps_bearer_id,
{ "EPS bearer identity", "nas_eps.bearer_id",
FT_UINT8, BASE_DEC, VALS(nas_eps_esm_bearer_id_vals), 0xf0,
NULL, HFILL }
},
{ &hf_nas_eps_spare_bits,
{ "Spare bit(s)", "nas_eps.spare_bits",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_security_header_type,
{ "Security header type","nas_eps.security_header_type",
FT_UINT8,BASE_DEC|BASE_EXT_STRING, &security_header_type_vals_ext, 0xf0,
NULL, HFILL }
},
{ &hf_nas_eps_msg_auth_code,
{ "Message authentication code","nas_eps.msg_auth_code",
FT_UINT32,BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_seq_no,
{ "Sequence number","nas_eps.seq_no",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_ciphered_msg,
{ "Ciphered message","nas_eps.ciphered_msg",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_msg_elems,
{ "Message Elements", "nas_eps.message_elements",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_seq_no_short,
{ "Sequence number (short)","nas_eps.seq_no_short",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi0,
{ "EBI(0) spare","nas_eps.emm.ebi0",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi1,
{ "EBI(1) spare","nas_eps.emm.ebi1",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi2,
{ "EBI(2) spare","nas_eps.emm.ebi2",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi3,
{ "EBI(3) spare","nas_eps.emm.ebi3",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi4,
{ "EBI(4) spare","nas_eps.emm.ebi4",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi5,
{ "EBI(5)","nas_eps.emm.ebi5",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_ebi_vals), 0x20,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi6,
{ "EBI(6)","nas_eps.emm.ebi6",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_ebi_vals), 0x40,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi7,
{ "EBI(7)","nas_eps.emm.ebi7",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_ebi_vals), 0x80,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi8,
{ "EBI(8)","nas_eps.emm.ebi8",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_ebi_vals), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi9,
{ "EBI(9)","nas_eps.emm.ebi9",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_ebi_vals), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi10,
{ "EBI(10)","nas_eps.emm.ebi10",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_ebi_vals), 0x04,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi11,
{ "EBI(11)","nas_eps.emm.ebi11",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_ebi_vals), 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi12,
{ "EBI(12)","nas_eps.emm.ebi12",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_ebi_vals), 0x10,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi13,
{ "EBI(13)","nas_eps.emm.ebi13",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_ebi_vals), 0x20,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi14,
{ "EBI(14)","nas_eps.emm.ebi14",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_ebi_vals), 0x40,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ebi15,
{ "EBI(15)","nas_eps.emm.ebi15",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_ebi_vals), 0x80,
NULL, HFILL }
},
{ &hf_nas_eps_emm_dl_nas_cnt,
{ "DL NAS COUNT value","nas_eps.emm.dl_nas_cnt",
FT_UINT8,BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{&hf_nas_eps_emm_nonce_mme,
{ "NonceMME","nas_eps.emm.nonce_mme",
FT_UINT32,BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{&hf_nas_eps_emm_nonce,
{ "Nonce","nas_eps.emm.nonce",
FT_UINT32,BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_paging_id,
{ "Paging identity value","nas_eps.emm.paging_id",
FT_BOOLEAN, BASE_NONE, TFS(&nas_eps_emm_paging_id_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eps_optim_info,
{ "EPS optimization info","nas_eps.emm.eps_optim_info",
FT_BOOLEAN, BASE_NONE, TFS(&nas_eps_emm_eps_optim_info), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eutran_allowed_value,
{ "E-UTRAN allowed value","nas_eps.emm.eutran_allowed_value",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_not_allowed_allowed), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eps_att_type,
{ "EPS attach type","nas_eps.emm.eps_att_type",
FT_UINT8,BASE_DEC, VALS(nas_eps_emm_eps_att_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_cp_ciot,
{ "Control plane CIoT EPS optimization","nas_eps.emm.cp_ciot",
FT_BOOLEAN ,BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_er_wo_pdn,
{ "EMM-REGISTERED w/o PDN connectivity","nas_eps.emm.er_wo_pdn",
FT_BOOLEAN ,BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_esr_ps,
{ "Support of EXTENDED SERVICE REQUEST for packet services","nas_eps.emm.esr_ps",
FT_BOOLEAN ,BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_cs_lcs,
{ "CS-LCS","nas_eps.emm.cs_lcs",
FT_UINT8, BASE_DEC, VALS(nas_eps_emm_cs_lcs_vals), 0x0,
"Location services indicator in CS", HFILL }
},
{ &hf_nas_eps_emm_epc_lcs,
{ "Location services via EPC","nas_eps.emm.epc_lcs",
FT_BOOLEAN ,BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_emc_bs,
{ "Emergency bearer services in S1 mode","nas_eps.emm.emc_bs",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ims_vops,
{ "IMS voice over PS session in S1 mode","nas_eps.emm.ims_vops",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_epco,
{ "Extended protocol configuration options IE","nas_eps.emm.epco",
FT_BOOLEAN ,BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_hc_cp_ciot,
{ "Header compression for control plane CIoT EPS optimization","nas_eps.emm.hc_cp_ciot",
FT_BOOLEAN ,BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_s1_u_data,
{ "S1-u data transfer","nas_eps.emm.s1_u_data",
FT_BOOLEAN ,BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_up_ciot,
{ "User plane CIoT EPS optimization","nas_eps.emm.up_ciot",
FT_BOOLEAN ,BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_tsc,
{ "Type of security context flag (TSC)","nas_eps.emm.tsc",
FT_BOOLEAN,BASE_DEC, TFS(&nas_eps_tsc_value), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_nas_key_set_id,
{ "NAS key set identifier","nas_eps.emm.nas_key_set_id",
FT_UINT8,BASE_DEC, VALS(nas_eps_emm_NAS_key_set_identifier_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_odd_even,
{ "Odd/even indication","nas_eps.emm.odd_even",
FT_BOOLEAN, 8, TFS(&nas_eps_odd_even_value), 0x8,
NULL, HFILL }
},
{ &hf_nas_eps_emm_type_of_id,
{ "Type of identity","nas_eps.emm.type_of_id",
FT_UINT8,BASE_DEC, VALS(nas_eps_emm_type_of_id_vals), 0x07,
NULL, HFILL }
},
{ &hf_nas_eps_emm_mme_grp_id,
{ "MME Group ID","nas_eps.emm.mme_grp_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_imei,
{ "IMEI", "nas_eps.emm.imei",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_mme_code,
{ "MME Code","nas_eps.emm.mme_code",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_m_tmsi,
{ "M-TMSI","nas_eps.emm.m_tmsi",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_msg_cont,
{ "ESM message container contents","nas_eps.emm.esm_msg_cont",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_imeisv_req,
{ "IMEISV request","nas_eps.emm.imeisv_req",
FT_UINT8, BASE_DEC, VALS(nas_eps_emm_imeisv_req_vals), 0x07,
NULL, HFILL }
},
{ &hf_nas_eps_emm_toi,
{ "Type of integrity protection algorithm","nas_eps.emm.toi",
FT_UINT8, BASE_DEC, VALS(nas_eps_emm_toi_vals), 0x07,
NULL, HFILL }
},
{ &hf_nas_eps_emm_toc,
{ "Type of ciphering algorithm","nas_eps.emm.toc",
FT_UINT8, BASE_DEC, VALS(nas_eps_emm_toc_vals), 0x70,
NULL, HFILL }
},
{ &hf_nas_eps_emm_EPS_attach_result,
{ "Attach result","nas_eps.emm.EPS_attach_result",
FT_UINT8,BASE_DEC, VALS(nas_eps_emm_EPS_attach_result_values), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_spare_half_octet,
{ "Spare half octet","nas_eps.emm.spare_half_octet",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_add_upd_res,
{ "AURV","nas_eps.emm.add_upd_res",
FT_UINT8, BASE_DEC, VALS(nas_eps_emm_add_upd_res_vals), 0x0,
"Additional update result value", HFILL }
},
{ &hf_nas_eps_emm_pnb_ciot,
{ "Preferred CIoT network behaviour","nas_eps.emm.pnb_ciot",
FT_UINT8, BASE_DEC, VALS(nas_eps_emm_pnb_ciot_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_saf,
{ "SAF","nas_eps.emm.saf",
FT_BOOLEAN, BASE_NONE, TFS(&nas_eps_emm_saf_value), 0x0,
"Signalling active flag", HFILL }
},
{ &hf_nas_eps_emm_add_upd_type,
{ "AUTV","nas_eps.emm.add_upd_type",
FT_BOOLEAN, BASE_NONE, TFS(&nas_eps_emm_add_upd_type_value), 0x0,
"Additional update type value", HFILL }
},
{ &hf_nas_eps_emm_res,
{ "RES","nas_eps.emm.res",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_csfb_resp,
{ "CSFB response","nas_eps.emm.csfb_resp",
FT_UINT8, BASE_DEC, VALS(nas_eps_emm_csfb_resp_vals), 0x03,
NULL, HFILL }
},
{ &hf_nas_eps_emm_cause,
{ "Cause","nas_eps.emm.cause",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &nas_eps_emm_cause_values_ext, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_id_type2,
{ "Identity type 2","nas_eps.emm.id_type2",
FT_UINT8, BASE_DEC, VALS(nas_eps_emm_id_type2_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_short_mac,
{ "Message authentication code (short)","nas_eps.emm.short_mac",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_tai_tol,
{ "Type of list","nas_eps.emm.tai_tol",
FT_UINT8, BASE_DEC, VALS(nas_eps_emm_tai_tol_vals), 0x60,
NULL, HFILL }
},
{ &hf_nas_eps_emm_tai_n_elem,
{ "Number of elements","nas_eps.emm.tai_n_elem",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_nas_eps_emm_tai_tac,
{ "Tracking area code(TAC)","nas_eps.emm.tai_tac",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eea0,
{ "EEA0","nas_eps.emm.eea0",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_nas_eps_emm_128eea1,
{ "128-EEA1","nas_eps.emm.128eea1",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_nas_eps_emm_128eea2,
{ "128-EEA2","nas_eps.emm.128eea2",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eea3,
{ "128-EEA3","nas_eps.emm.eea3",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eea4,
{ "EEA4","nas_eps.emm.eea4",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eea5,
{ "EEA5","nas_eps.emm.eea5",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eea6,
{ "EEA6","nas_eps.emm.eea6",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eea7,
{ "EEA7","nas_eps.emm.eea7",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eia0,
{ "EIA0","nas_eps.emm.eia0",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_nas_eps_emm_128eia1,
{ "128-EIA1","nas_eps.emm.128eia1",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_nas_eps_emm_128eia2,
{ "128-EIA2","nas_eps.emm.128eia2",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eia3,
{ "128-EIA3","nas_eps.emm.eia3",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eia4,
{ "EIA4","nas_eps.emm.eia4",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eia5,
{ "EIA5","nas_eps.emm.eia5",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eia6,
{ "EIA6","nas_eps.emm.eia6",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eia7,
{ "EIA7","nas_eps.emm.eia7",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea0,
{ "UEA0","nas_eps.emm.uea0",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea1,
{ "UEA1","nas_eps.emm.uea1",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea2,
{ "UEA2","nas_eps.emm.uea2",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea3,
{ "UEA3","nas_eps.emm.uea3",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea4,
{ "UEA4","nas_eps.emm.uea4",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea5,
{ "UEA5","nas_eps.emm.uea5",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea6,
{ "UEA6","nas_eps.emm.uea6",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea7,
{ "UEA7","nas_eps.emm.uea7",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ucs2_supp,
{ "UCS2 support (UCS2)","nas_eps.emm.emm_ucs2_supp",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_ucs2_supp_flg_value), 0x80,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uia1,
{ "UMTS integrity algorithm UIA1","nas_eps.emm.uia1",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uia2,
{ "UMTS integrity algorithm UIA2","nas_eps.emm.uia2",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uia3,
{ "UMTS integrity algorithm UIA3","nas_eps.emm.uia3",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uia4,
{ "UMTS integrity algorithm UIA4","nas_eps.emm.uia4",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uia5,
{ "UMTS integrity algorithm UIA5","nas_eps.emm.uia5",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uia6,
{ "UMTS integrity algorithm UIA6","nas_eps.emm.uia6",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uia7,
{ "UMTS integrity algorithm UIA7","nas_eps.emm.uia7",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_emm_gea1,
{ "GPRS encryption algorithm GEA1","nas_eps.emm.gea1",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_nas_eps_emm_gea2,
{ "GPRS encryption algorithm GEA2","nas_eps.emm.gea2",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_nas_eps_emm_gea3,
{ "GPRS encryption algorithm GEA3","nas_eps.emm.gea3",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_nas_eps_emm_gea4,
{ "GPRS encryption algorithm GEA4","nas_eps.emm.gea4",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_emm_gea5,
{ "GPRS encryption algorithm GEA5","nas_eps.emm.gea5",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_nas_eps_emm_gea6,
{ "GPRS encryption algorithm GEA6","nas_eps.emm.gea6",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_emm_gea7,
{ "GPRS encryption algorithm GEA7","nas_eps.emm.gea7",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_emm_prose_dd_cap,
{ "ProSe direct discovery","nas_eps.emm.prose_dd_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_nas_eps_emm_prose_cap,
{ "ProSe","nas_eps.emm.prose_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_nas_eps_emm_h245_ash_cap,
{ "H.245 After SRVCC Handover","nas_eps.emm.h245_ash_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_nas_eps_emm_acc_csfb_cap,
{ "Access class control for CSFB","nas_eps.emm.acc_csfb_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_nas_eps_emm_lpp_cap,
{ "LTE Positioning Protocol","nas_eps.emm.lpp_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_emm_lcs_cap,
{ "Location services (LCS) notification mechanisms","nas_eps.emm.lcs_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_nas_eps_emm_1xsrvcc_cap,
{ "SRVCC from E-UTRAN to cdma2000 1xCS","nas_eps.emm.1xsrvcc_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_emm_nf_cap,
{ "Notification procedure","nas_eps.emm.nf_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_emm_epco_cap,
{ "Extended protocol configuration options","nas_eps.emm.epco_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_nas_eps_emm_hc_cp_ciot_cap,
{ "Header compression for control plane CIoT EPS optimization","nas_eps.emm.hc_cp_ciot_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_nas_eps_emm_er_wo_pdn_cap,
{ "EMM-REGISTERED w/o PDN connectivity","nas_eps.emm.er_wo_pdn_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_nas_eps_emm_s1u_data_cap,
{ "S1-U data transfer","nas_eps.emm.s1u_data_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_nas_eps_emm_up_ciot_cap,
{ "User plane CIoT EPS optimization","nas_eps.emm.up_ciot_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_emm_cp_ciot_cap,
{ "Control plane CIoT EPS optimization","nas_eps.emm.cp_ciot_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_nas_eps_emm_prose_relay_cap,
{ "ProSe UE-to-network relay","nas_eps.emm.prose_relay_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_emm_prose_dc_cap,
{ "ProSe direct communication","nas_eps.emm.prose_dc_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_multiple_drb_cap,
{ "Multiple DRB","nas_eps.emm.multiple_drb_cap",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ue_ra_cap_inf_upd_need_flg,
{ "URC upd","nas_eps.emm.ue_ra_cap_inf_upd_need_flg",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_ue_ra_cap_inf_upd_need_flg), 0x01,
"UE radio capability information update needed flag", HFILL }
},
{ &hf_nas_eps_emm_ss_code,
{ "SS Code","nas_eps.emm.ss_code",
FT_UINT8,BASE_DEC, VALS(ssCode_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_lcs_ind,
{ "LCS indicator","nas_eps.emm.emm_lcs_ind",
FT_UINT8,BASE_DEC, VALS(nas_eps_emm_lcs_ind_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_gen_msg_cont_type,
{ "Container type","nas_eps.emm.gen_msg_cont_type",
FT_UINT8,BASE_DEC|BASE_RANGE_STRING, RVALS(nas_eps_emm_gen_msg_cont_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_apn_ambr_ul,
{ "APN-AMBR for uplink","nas_eps.emm.apn_ambr_ul",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_apn_ambr_dl,
{ "APN-AMBR for downlink","nas_eps.emm.apn_ambr_dl",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_apn_ambr_ul_ext,
{ "APN-AMBR for uplink (extended)","nas_eps.emm.apn_ambr_ul_ext",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_apn_ambr_dl_ext,
{ "APN-AMBR for downlink (extended)","nas_eps.emm.apn_ambr_dl_ext",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_apn_ambr_ul_ext2,
{ "APN-AMBR for uplink (extended-2)","nas_eps.emm.apn_ambr_ul_ext2",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_apn_ambr_dl_ext2,
{ "APN-AMBR for downlink (extended-2)","nas_eps.emm.apn_ambr_dl_ext2",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_apn_ambr_ul_total,
{ "Total APN-AMBR for uplink","nas_eps.emm.apn_ambr_ul_total",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_apn_ambr_dl_total,
{ "Total APN-AMBR for downlink","nas_eps.emm.apn_ambr_dl_total",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_guti_type,
{ "GUTI type", "nas_eps.emm.guti_type",
FT_BOOLEAN, BASE_NONE, TFS(&nas_eps_emm_guti_type_value), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_detach_req_UL,
{ "Uplink","nas_eps.emm.detach_req_ul",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_detach_req_DL,
{ "Downlink","nas_eps.emm.detach_req_dl",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_switch_off,
{ "Switch off","nas_eps.emm.switch_off",
FT_UINT8,BASE_DEC, VALS(nas_eps_emm_switch_off_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_detach_type_UL,
{ "Detach Type","nas_eps.emm.detach_type_ul",
FT_UINT8,BASE_DEC, VALS(nas_eps_emm_type_of_detach_UL_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_detach_type_DL,
{ "Detach Type","nas_eps.emm.detach_type_dl",
FT_UINT8,BASE_DEC, VALS(nas_eps_emm_type_of_detach_DL_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_qci,
{ "Quality of Service Class Identifier (QCI)","nas_eps.emm.qci",
FT_UINT8,(BASE_DEC|BASE_RANGE_STRING), RVALS(nas_eps_qci_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_mbr_ul,
{ "Maximum bit rate for uplink","nas_eps.emm.mbr_ul",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_mbr_dl,
{ "Maximum bit rate for downlink","nas_eps.emm.mbr_dl",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_gbr_ul,
{ "Guaranteed bit rate for uplink","nas_eps.emm.gbr_ul",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_gbr_dl,
{ "Guaranteed bit rate for downlink","nas_eps.emm.gbr_dl",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_embr_ul,
{ "Maximum bit rate for uplink(ext)","nas_eps.emm.embr_ul",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_embr_dl,
{ "Maximum bit rate for downlink(ext)","nas_eps.emm.embr_dl",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_egbr_ul,
{ "Guaranteed bit rate for uplink(ext)","nas_eps.emm.egbr_ul",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_egbr_dl,
{ "Guaranteed bit rate for downlink(ext)","nas_eps.emm.egbr_dl",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_cause,
{ "Cause","nas_eps.esm.cause",
FT_UINT8,BASE_DEC|BASE_EXT_STRING, &nas_eps_esm_cause_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_eit,
{ "EIT (ESM information transfer)", "nas_eps.emm.eit",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_eit_vals), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_esm_notif_ind,
{ "Notification indicator value","nas_eps.esm.notif_ind",
FT_UINT8,BASE_DEC, VALS(nas_eps_esm_notif_ind_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_pdn_ipv4,
{"PDN IPv4", "nas_eps.esm.pdn_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_nas_eps_esm_pdn_ipv6_if_id,
{"PDN IPv6 if id", "nas_eps.esm.pdn_ipv6_if_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_nas_eps_esm_eplmnc,
{ "EPLMNC", "nas_eps.esm.eplmnc",
FT_BOOLEAN, 8, TFS(&nas_eps_esm_eplmnc_value), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_esm_ratc,
{ "RATC", "nas_eps.esm.ratc",
FT_BOOLEAN, 8, TFS(&nas_eps_esm_ratc_value), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_esm_linked_bearer_id,
{ "Linked EPS bearer identity","nas_eps.esm.linked_bearer_id",
FT_UINT8,BASE_DEC, VALS(nas_eps_esm_linked_bearer_id_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_nbifom_cont,
{ "NBIFOM container content","nas_eps.esm.nbifom_cont",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_remote_ue_context_list_nb_ue_contexts,
{ "Number of remote UE contexts","nas_eps.esm.remote_ue_context_list.nb_ue_contexts",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_remote_ue_context_list_ue_context_len,
{ "Length of remote UE context","nas_eps.esm.remote_ue_context_list.ue_context.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_remote_ue_context_list_ue_context_nb_user_id,
{ "Number of user identities","nas_eps.esm.remote_ue_context_list.ue_context.nb_user_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_remote_ue_context_list_ue_context_user_id_len,
{ "Length of user identity","nas_eps.esm.remote_ue_context_list.ue_context.user_id_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_remote_ue_context_list_ue_context_odd_even_indic,
{ "Odd/even indication","nas_eps.esm.remote_ue_context_list.ue_context.odd_even_indic",
FT_BOOLEAN, 8, TFS(&nas_eps_odd_even_value), 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_esm_remote_ue_context_list_ue_context_user_id_type,
{ "Type of user identity","nas_eps.esm.remote_ue_context_list.ue_context.user_id_type",
FT_UINT8, BASE_DEC, VALS(nas_eps_esm_user_info_type_values), 0x07,
NULL, HFILL }
},
{ &hf_nas_eps_esm_remote_ue_context_list_ue_context_encr_imsi,
{ "Encrypted IMSI", "nas_eps.esm.remote_ue_context_list.ue_context.encr_imsi",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_remote_ue_context_list_ue_context_msisdn,
{ "MSISDN", "nas_eps.esm.remote_ue_context_list.ue_context.msisdn",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_remote_ue_context_list_ue_context_imei,
{ "IMEI", "nas_eps.esm.remote_ue_context_list.ue_context.imei",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_remote_ue_context_list_ue_context_imeisv,
{ "IMEISV", "nas_eps.esm.remote_ue_context_list.ue_context.imeisv",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_remote_ue_context_list_ue_context_address_type,
{ "Address type","nas_eps.esm.remote_ue_context_list.ue_context.address_type",
FT_UINT8, BASE_DEC, VALS(nas_eps_esm_address_type_values), 0x07,
NULL, HFILL }
},
{ &hf_nas_eps_esm_remote_ue_context_list_ue_context_ipv4,
{ "IPv4 address","nas_eps.esm.remote_ue_context_list.ue_context.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_remote_ue_context_list_ue_context_port_number,
{ "Port number","nas_eps.esm.remote_ue_context_list.ue_context.port_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_remote_ue_context_list_ue_context_ipv6_prefix,
{ "IPv6 prefix","nas_eps.esm.remote_ue_context_list.ue_context.ipv6_prefix",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_pkmf_address_type,
{ "Address type","nas_eps.esm.pkmf.address_type",
FT_UINT8, BASE_DEC, VALS(nas_eps_esm_pkmf_address_type_values), 0x07,
NULL, HFILL }
},
{ &hf_nas_eps_esm_pkmf_ipv4,
{ "IPv4 address","nas_eps.esm.pkmf.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_pkmf_ipv6,
{ "IPv6 address","nas_eps.esm.pkmf.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_spare_bit0x80,
{ "Spare bit(s)", "nas_eps.spare_bits",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_comp_config_prof_0104,
{ "RoHC profile 0x0104 (IP)", "nas_eps.esm.hdr_comp_config.prof_0104",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_comp_config_prof_0103,
{ "RoHC profile 0x0103 (ESP/IP)", "nas_eps.esm.hdr_comp_config.prof_0103",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_comp_config_prof_0102,
{ "RoHC profile 0x0102 (UDP/IP)", "nas_eps.esm.hdr_comp_config.prof_0102",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_comp_config_prof_0006,
{ "RoHC profile 0x0006 (TCP/IP)", "nas_eps.esm.hdr_comp_config.prof_0006",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_comp_config_prof_0004,
{ "RoHC profile 0x0004 (IP)", "nas_eps.esm.hdr_comp_config.prof_0004",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_comp_config_prof_0003,
{ "RoHC profile 0x0003 (ESP/IP)", "nas_eps.esm.hdr_comp_config.prof_0003",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_comp_config_prof_0002,
{ "RoHC profile 0x0002 (UDP/IP)", "nas_eps.esm.hdr_comp_config.prof_0002",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_compr_config_max_cid,
{ "MAX_CID", "nas_eps.esm.hdr_comp_config.max_cid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_compr_config_add_hdr_compr_cxt_setup_params_type,
{ "Additional header compression context setup parameters type", "nas_eps.esm.hdr_comp_config.add_hdr_compr_cxt_setup_params_type",
FT_UINT8, BASE_HEX, VALS(nas_eps_esm_add_hdr_compr_cxt_setup_params_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_compr_config_add_hdr_compr_cxt_setup_params_cont,
{ "Additional header compression context setup parameters container", "nas_eps.esm.hdr_comp_config.add_hdr_compr_cxt_setup_params_cont",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_ctrl_plane_only_ind_cpoi,
{ "CPOI", "nas_eps.esm.ctrl_plane_only_ind.cpoi",
FT_BOOLEAN, BASE_NONE, TFS(&nas_eps_ctrl_plane_only_ind_cpoi_value), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_user_data_cont,
{ "User data contents", "nas_eps.esm.user_data_cont",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_rel_assist_ind_ddx,
{ "Downlink data expected","nas_eps.esm.rel_assist_ind.ddx",
FT_UINT8, BASE_DEC, VALS(nas_eps_esm_rel_assist_ind_ddx_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_compr_config_status_ebi7,
{ "EBI(7)", "nas_eps.esm.hdr_compr_config_status.ebi7",
FT_BOOLEAN, 16, TFS(&nas_eps_esm_hdr_compr_config_status_ebi_value), 0x8000,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_compr_config_status_ebi6,
{ "EBI(6)", "nas_eps.esm.hdr_compr_config_status.ebi6",
FT_BOOLEAN, 16, TFS(&nas_eps_esm_hdr_compr_config_status_ebi_value), 0x4000,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_compr_config_status_ebi5,
{ "EBI(5)", "nas_eps.esm.hdr_compr_config_status.ebi5",
FT_BOOLEAN, 16, TFS(&nas_eps_esm_hdr_compr_config_status_ebi_value), 0x2000,
NULL, HFILL }
},
{ &hf_nas_eps_esm_spare_bits0x1f00,
{ "Spare bit(s)", "nas_eps.spare_bits",
FT_UINT16, BASE_HEX, NULL, 0x1f00,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_compr_config_status_ebi15,
{ "EBI(15)", "nas_eps.esm.hdr_compr_config_status.ebi15",
FT_BOOLEAN, 16, TFS(&nas_eps_esm_hdr_compr_config_status_ebi_value), 0x0080,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_compr_config_status_ebi14,
{ "EBI(14)", "nas_eps.esm.hdr_compr_config_status.ebi14",
FT_BOOLEAN, 16, TFS(&nas_eps_esm_hdr_compr_config_status_ebi_value), 0x0040,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_compr_config_status_ebi13,
{ "EBI(13)", "nas_eps.esm.hdr_compr_config_status.ebi13",
FT_BOOLEAN, 16, TFS(&nas_eps_esm_hdr_compr_config_status_ebi_value), 0x0020,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_compr_config_status_ebi12,
{ "EBI(12)", "nas_eps.esm.hdr_compr_config_status.ebi12",
FT_BOOLEAN, 16, TFS(&nas_eps_esm_hdr_compr_config_status_ebi_value), 0x0010,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_compr_config_status_ebi11,
{ "EBI(11)", "nas_eps.esm.hdr_compr_config_status.ebi11",
FT_BOOLEAN, 16, TFS(&nas_eps_esm_hdr_compr_config_status_ebi_value), 0x0008,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_compr_config_status_ebi10,
{ "EBI(10)", "nas_eps.esm.hdr_compr_config_status.ebi10",
FT_BOOLEAN, 16, TFS(&nas_eps_esm_hdr_compr_config_status_ebi_value), 0x0004,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_compr_config_status_ebi9,
{ "EBI(9)", "nas_eps.esm.hdr_compr_config_status.ebi9",
FT_BOOLEAN, 16, TFS(&nas_eps_esm_hdr_compr_config_status_ebi_value), 0x0002,
NULL, HFILL }
},
{ &hf_nas_eps_esm_hdr_compr_config_status_ebi8,
{ "EBI(8)", "nas_eps.esm.hdr_compr_config_status.ebi8",
FT_BOOLEAN, 16, TFS(&nas_eps_esm_hdr_compr_config_status_ebi_value), 0x0001,
NULL, HFILL }
},
{ &hf_nas_eps_esm_serv_plmn_rate_ctrl_val,
{ "Serving PLMN rate control value", "nas_eps.esm.serv_plmn_rate_ctrl_val",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_active_flg,
{ "Active flag", "nas_eps.emm.active_flg",
FT_BOOLEAN, BASE_NONE, TFS(&nas_eps_emm_active_flg_value), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_ctrl_plane_serv_type,
{ "Control plane service type", "nas_eps.emm.ctrl_plane_serv_type",
FT_UINT8, BASE_DEC, VALS(nas_eps_emm_data_serv_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_eps_update_result_value,
{ "EPS update result value","nas_eps.emm.eps_update_result_value",
FT_UINT8,BASE_DEC, VALS(nas_eps_emm_eps_update_result_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_eps_update_type_value,
{ "EPS update type value", "nas_eps.emm.update_type_value",
FT_UINT8,BASE_DEC, VALS(nas_eps_emm_eps_update_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_service_type,
{ "Service type", "nas_eps.emm.service_type",
FT_UINT8,BASE_DEC|BASE_RANGE_STRING, RVALS(nas_eps_service_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_nas_msg_cont,
{ "NAS message container content", "nas_eps.emm.nas_msg_cont",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_gen_msg_cont,
{ "Generic message container content", "nas_eps.emm.gen_msg_cont",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_cmn_add_info,
{ "Additional information content", "nas_eps.cmn.add_info",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_msg_esm_type,
{ "NAS EPS session management messages", "nas_eps.nas_msg_esm_type",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &nas_msg_esm_strings_ext, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_elem_id,
{ "Element ID", "nas_eps.esm.elem_id",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_proc_trans_id,
{ "Procedure transaction identity", "nas_eps.esm.proc_trans_id",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_pdn_type,
{ "PDN type", "nas_eps.esm_pdn_type",
FT_UINT8, BASE_DEC, VALS(nas_eps_esm_pdn_type_values), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_esm_request_type,
{ "Request type", "nas_eps.esm_request_type",
FT_UINT8, BASE_DEC, VALS(nas_eps_esm_request_type_values), 0x0,
NULL, HFILL }
},
};
static ei_register_info ei[] = {
{ &ei_nas_eps_extraneous_data, { "nas_eps.extraneous_data", PI_PROTOCOL, PI_NOTE, "Extraneous Data, dissector bug or later version spec(report to wireshark.org)", EXPFILL }},
{ &ei_nas_eps_unknown_identity, { "nas_eps.emm.unknown_identity", PI_PROTOCOL, PI_WARN, "Type of identity not known", EXPFILL }},
{ &ei_nas_eps_unknown_type_of_list, { "nas_eps.emm.tai_unknown_list_type", PI_PROTOCOL, PI_WARN, "Unknown type of list", EXPFILL }},
{ &ei_nas_eps_wrong_nb_of_elems, { "nas_eps.emm.tai_wrong_number_of_elems", PI_PROTOCOL, PI_ERROR, "[Wrong number of elements?]", EXPFILL }},
{ &ei_nas_eps_unknown_msg_type, { "nas_eps.unknown_msg_type", PI_PROTOCOL, PI_WARN, "Unknown Message Type", EXPFILL }},
{ &ei_nas_eps_unknown_pd, { "nas_eps.unknown_pd", PI_PROTOCOL, PI_ERROR, "Unknown protocol discriminator", EXPFILL }},
{ &ei_nas_eps_esm_tp_not_integ_prot, { "nas_eps.esm_tp_not_integrity_protected", PI_PROTOCOL, PI_ERROR, "All ESM / Test Procedures messages should be integrity protected", EXPFILL }}
};
expert_module_t* expert_nas_eps;
#define NUM_INDIVIDUAL_ELEMS 7
gint *ett[NUM_INDIVIDUAL_ELEMS +
NUM_NAS_EPS_COMMON_ELEM +
NUM_NAS_MSG_EMM + NUM_NAS_EMM_ELEM+
NUM_NAS_MSG_ESM + NUM_NAS_ESM_ELEM];
ett[0] = &ett_nas_eps;
ett[1] = &ett_nas_eps_esm_msg_cont;
ett[2] = &ett_nas_eps_nas_msg_cont;
ett[3] = &ett_nas_eps_gen_msg_cont;
ett[4] = &ett_nas_eps_cmn_add_info;
ett[5] = &ett_nas_eps_remote_ue_context;
ett[6] = &ett_nas_eps_esm_user_data_cont;
last_offset = NUM_INDIVIDUAL_ELEMS;
for (i=0; i < NUM_NAS_EPS_COMMON_ELEM; i++, last_offset++)
{
ett_nas_eps_common_elem[i] = -1;
ett[last_offset] = &ett_nas_eps_common_elem[i];
}
for (i=0; i < NUM_NAS_MSG_EMM; i++, last_offset++)
{
ett_nas_msg_emm[i] = -1;
ett[last_offset] = &ett_nas_msg_emm[i];
}
for (i=0; i < NUM_NAS_EMM_ELEM; i++, last_offset++)
{
ett_nas_eps_emm_elem[i] = -1;
ett[last_offset] = &ett_nas_eps_emm_elem[i];
}
for (i=0; i < NUM_NAS_MSG_ESM; i++, last_offset++)
{
ett_nas_msg_esm[i] = -1;
ett[last_offset] = &ett_nas_msg_esm[i];
}
for (i=0; i < NUM_NAS_ESM_ELEM; i++, last_offset++)
{
ett_nas_eps_esm_elem[i] = -1;
ett[last_offset] = &ett_nas_eps_esm_elem[i];
}
proto_nas_eps = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_nas_eps, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_nas_eps = expert_register_protocol(proto_nas_eps);
expert_register_field_array(expert_nas_eps, ei, array_length(ei));
register_dissector(PFNAME, dissect_nas_eps, proto_nas_eps);
register_dissector("nas-eps_plain", dissect_nas_eps_plain, proto_nas_eps);
nas_eps_module = prefs_register_protocol(proto_nas_eps, NULL);
prefs_register_bool_preference(nas_eps_module,
"dissect_plain",
"Force dissect as plain NAS EPS",
"Always dissect NAS EPS messages as plain",
&g_nas_eps_dissect_plain);
prefs_register_bool_preference(nas_eps_module,
"null_decipher",
"Try to detect and decode EEA0 ciphered messages",
"This should work when the NAS ciphering algorithm is NULL (128-EEA0)",
&g_nas_eps_null_decipher);
prefs_register_bool_preference(nas_eps_module,
"user_data_container_as_ip",
"Try to decode User Data Container content as IP",
NULL,
&g_nas_eps_user_data_container_as_ip);
}
void
proto_reg_handoff_nas_eps(void)
{
gsm_a_dtap_handle = find_dissector_add_dependency("gsm_a_dtap", proto_nas_eps);
lpp_handle = find_dissector_add_dependency("lpp", proto_nas_eps);
nbifom_handle = find_dissector_add_dependency("nbifom", proto_nas_eps);
ipv4_handle = find_dissector_add_dependency("ip", proto_nas_eps);
ipv6_handle = find_dissector_add_dependency("ipv6", proto_nas_eps);
}
