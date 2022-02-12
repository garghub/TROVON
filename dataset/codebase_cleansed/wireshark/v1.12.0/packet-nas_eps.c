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
new_tvb = tvb_new_subset(tvb, offset, len, len);
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
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
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
static char *
unpack_eps_mid_digits(tvbuff_t *tvb) {
int length;
guint8 octet;
int i = 0;
int offset = 0;
char *digit_str;
length = tvb_length(tvb);
digit_str = (char *)wmem_alloc(wmem_packet_scope(), length*2);
octet = tvb_get_guint8(tvb,offset);
digit_str[i++] = (((octet>>4) & 0x0f) + '0');
offset++;
while ( offset < length ) {
octet = tvb_get_guint8(tvb,offset);
digit_str[i] = ((octet & 0x0f) + '0');
i++;
octet = octet >> 4;
if (octet == 0x0f)
break;
digit_str[i] = ((octet & 0x0f) + '0');
i++;
offset++;
}
digit_str[i]= '\0';
return digit_str;
}
static guint16
de_emm_eps_mid(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo,
guint32 offset, guint len _U_,
gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 octet;
char *digit_str;
tvbuff_t *new_tvb;
curr_offset = offset;
octet = tvb_get_guint8(tvb,offset);
proto_tree_add_item(tree, hf_nas_eps_emm_odd_even, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_type_of_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
switch (octet&0x7) {
case 1:
new_tvb = tvb_new_subset(tvb, curr_offset, len, len );
digit_str = unpack_eps_mid_digits(new_tvb);
proto_tree_add_string(tree, hf_nas_eps_emm_imsi, new_tvb, 0, -1, digit_str);
break;
case 3:
new_tvb = tvb_new_subset(tvb, curr_offset, len, len );
digit_str = unpack_eps_mid_digits(new_tvb);
proto_tree_add_string(tree, hf_nas_eps_emm_imei, new_tvb, 0, -1, digit_str);
break;
case 6:
curr_offset++;
curr_offset = dissect_e212_mcc_mnc(tvb, pinfo, tree, curr_offset, TRUE);
proto_tree_add_item(tree, hf_nas_eps_emm_mme_grp_id, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
proto_tree_add_item(tree, hf_nas_eps_emm_mme_code, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_nas_eps_emm_m_tmsi, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_text(tree, tvb, curr_offset, len - 1, "Type of identity not known");
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
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_esr_ps, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_cs_lcs, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_epc_lcs, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_emc_bs, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_ims_vops, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
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
curr_offset = offset;
item = proto_tree_add_item(tree, hf_nas_eps_esm_msg_cont, tvb, curr_offset, len, ENC_NA);
sub_tree = proto_item_add_subtree(item, ett_nas_eps_esm_msg_cont);
new_tvb = tvb_new_subset(tvb, curr_offset, len, len );
disect_nas_eps_esm_msg(new_tvb, pinfo, sub_tree, 0);
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
new_tvb = tvb_new_subset(tvb, curr_offset, len, len );
if (gsm_a_dtap_handle)
call_dissector(gsm_a_dtap_handle, new_tvb, pinfo, sub_tree);
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
curr_offset = dissect_e212_mcc_mnc(tvb, pinfo, tree, curr_offset, TRUE);
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
guint32 curr_offset;
guint8 octet, tol, n_elem;
int i;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, curr_offset<<3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_tai_tol, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb,curr_offset)& 0x7f;
tol = octet >> 5;
n_elem = (octet & 0x1f)+1;
item = proto_tree_add_item(tree, hf_nas_eps_emm_tai_n_elem, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
if (n_elem<16)
proto_item_append_text(item, " [+1 = %u element(s)]", n_elem);
curr_offset++;
if (tol>2) {
proto_tree_add_text(tree, tvb, curr_offset, len-(curr_offset-offset) , "Unknown type of list ( Not in 3GPP TS 24.301 version 8.1.0 Release 8 )");
return len;
}
switch (tol) {
case 0:
curr_offset = dissect_e212_mcc_mnc(tvb, pinfo, tree, curr_offset, TRUE);
if (len < (guint)(4+(n_elem*2))) {
proto_tree_add_text(tree, tvb, curr_offset, len-1 , "[Wrong number of elements?]");
return len;
}
for (i=0; i < n_elem; i++, curr_offset+=2)
proto_tree_add_item(tree, hf_nas_eps_emm_tai_tac, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
break;
case 1:
curr_offset = dissect_e212_mcc_mnc(tvb, pinfo, tree, curr_offset, TRUE);
proto_tree_add_item(tree, hf_nas_eps_emm_tai_tac, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
break;
case 2:
if (len< (guint)(1+(n_elem*5))) {
proto_tree_add_text(tree, tvb, curr_offset, len-1 , "[Wrong number of elements?]");
return len;
}
for (i=0; i < n_elem; i++) {
curr_offset = dissect_e212_mcc_mnc(tvb, pinfo, tree, curr_offset, TRUE);
proto_tree_add_item(tree, hf_nas_eps_emm_tai_tac, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
}
break;
default:
break;
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
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
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, (curr_offset<<3), 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_h245_ash_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_acc_csfb_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_lpp_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_lcs_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_1xsrvcc_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nas_eps_emm_nf_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
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
new_tvb = tvb_new_subset(tvb, curr_offset, len, len );
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
new_tvb = tvb_new_subset(tvb, offset, len, len);
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
dl_total += bitrate;
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
ul_total += bitrate;
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
dl_total += (octet > 0x4a) ? bitrate*1000 : bitrate;
proto_tree_add_uint_format_value(tree, hf_nas_eps_emm_apn_ambr_dl_ext, tvb, curr_offset, 1, octet,
"%u %s", bitrate, (octet > 0x4a) ? "Mbps" : "kbps");
}
if (len < 5) {
if (octet != 0) {
dl_total = (octet > 0x4a) ? bitrate*1000 : bitrate;
}
if (dl_total >= 1000) {
proto_tree_add_text(tree, tvb, curr_offset, 1,"Total APN-AMBR for downlink : %.3f Mbps", (gfloat)dl_total / 1000);
} else {
proto_tree_add_text(tree, tvb, curr_offset, 1,"Total APN-AMBR for downlink : %u kbps", dl_total);
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
ul_total += (octet > 0x4a) ? bitrate*1000 : bitrate;
proto_tree_add_uint_format_value(tree, hf_nas_eps_emm_apn_ambr_ul_ext, tvb, curr_offset, 1, octet,
"%u %s", bitrate, (octet > 0x4a) ? "Mbps" : "kbps");
}
if (len < 6) {
if (octet != 0) {
ul_total = (octet > 0x4a) ? bitrate*1000 : bitrate;
}
if (ul_total >= 1000) {
proto_tree_add_text(tree, tvb, curr_offset, 1,"Total APN-AMBR for uplink : %.3f Mbps", (gfloat)ul_total / 1000);
} else {
proto_tree_add_text(tree, tvb, curr_offset, 1,"Total APN-AMBR for uplink : %u kbps", ul_total);
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
proto_tree_add_text(tree, tvb, curr_offset, 1,"Total APN-AMBR for downlink : %.3f Mbps", (gfloat)dl_total / 1000);
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
proto_tree_add_text(tree, tvb, curr_offset, 1,"Total APN-AMBR for uplink : %.3f Mbps", (gfloat)ul_total / 1000);
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
"Use the value indicated by the guaranted bit rate for uplink in octet 6 and octet 10");
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
default:
break;
}
return(curr_offset-offset);
}
static void
nas_emm_attach_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_attach_comp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV_E(NAS_PDU_TYPE_EMM, DE_EMM_ESM_MSG_CONT, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_attach_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_CAUSE, NULL);
ELEM_OPT_TLV_E(0x78, NAS_PDU_TYPE_EMM, DE_EMM_ESM_MSG_CONT, NULL);
ELEM_OPT_TLV(0x5F, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3346 value");
ELEM_OPT_TLV(0x16, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3402 value");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_auth_fail(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_CAUSE, NULL);
ELEM_OPT_TLV(0x30, GSM_A_PDU_TYPE_DTAP, DE_AUTH_FAIL_PARAM, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_auth_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_spare_half_octet, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
de_emm_nas_key_set_id_bits(tvb, tree, bit_offset, " ASME");
curr_len--;
curr_offset++;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_AUTH_PARAM_RAND, " - EPS challenge");
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_AUTH_PARAM_AUTN, " - EPS challenge");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_auth_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(NAS_PDU_TYPE_EMM, DE_EMM_AUTH_RESP_PAR, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_cs_serv_not(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_PAGING_ID, NULL);
ELEM_OPT_TLV(0x60, GSM_A_PDU_TYPE_DTAP, DE_CLG_PARTY_BCD_NUM, " - CLI");
ELEM_OPT_TV(0x61, NAS_PDU_TYPE_EMM, DE_EMM_SS_CODE, NULL);
ELEM_OPT_TV(0x62, NAS_PDU_TYPE_EMM, DE_EMM_LCS_IND, NULL);
ELEM_OPT_TLV(0x63, NAS_PDU_TYPE_EMM, DE_EMM_LCS_CLIENT_ID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
proto_tree_add_text(tree, tvb, curr_offset, len, "Uplink");
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
proto_tree_add_text(tree, tvb, curr_offset, len, "Downlink");
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
if (curr_len == 0)
return;
ELEM_OPT_TV(0x53, NAS_PDU_TYPE_EMM, DE_EMM_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_emm_inf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(0x43, GSM_A_PDU_TYPE_DTAP, DE_NETWORK_NAME, " - Full name for network");
ELEM_OPT_TLV(0x45, GSM_A_PDU_TYPE_DTAP, DE_NETWORK_NAME, " - Short Name");
ELEM_OPT_TV(0x46, GSM_A_PDU_TYPE_DTAP, DE_TIME_ZONE, " - Local");
ELEM_OPT_TV(0x47, GSM_A_PDU_TYPE_DTAP, DE_TIME_ZONE_TIME, " - Universal Time and Local Time Zone");
ELEM_OPT_TLV(0x49, GSM_A_PDU_TYPE_DTAP, DE_DAY_SAVING_TIME, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
de_emm_nas_key_set_id_bits(tvb, tree, bit_offset, NULL);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_service_type, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
curr_len--;
curr_offset++;
ELEM_MAND_LV(NAS_PDU_TYPE_COMMON, DE_EPS_CMN_MOB_ID, " - M-TMSI");
ELEM_OPT_TV_SHORT(0xb0, NAS_PDU_TYPE_EMM, DE_EMM_CSFB_RESP, NULL);
ELEM_OPT_TLV(0x57, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_EPS_BE_CTX_STATUS, NULL);
ELEM_OPT_TV_SHORT(0xD0 , GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_guti_realloc_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(NAS_PDU_TYPE_EMM, DE_EMM_EPS_MID, " - GUTI");
ELEM_OPT_TLV(0x54, NAS_PDU_TYPE_EMM, DE_EMM_TRAC_AREA_ID_LST, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_id_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
bit_offset=curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_spare_half_octet, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_id_type2, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
curr_len--;
curr_offset++;
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_id_res(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(NAS_PDU_TYPE_COMMON, DE_EPS_CMN_MOB_ID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_sec_mode_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_sec_mode_comp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
if (curr_len == 0)
return;
ELEM_OPT_TLV(0x23, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_MOB_ID, " - IMEISV");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_sec_mode_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_serv_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_CAUSE, NULL);
ELEM_OPT_TV(0x5b, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER, " - T3442 value");
ELEM_OPT_TLV(0x5F, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3346 value");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_service_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_KSI_AND_SEQ_NO, NULL);
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_SHORT_MAC, " - Message authentication code (short)");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_trac_area_upd_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset, bit_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_nas_eps_emm_spare_half_octet, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
proto_tree_add_bits_item(tree, hf_nas_eps_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_nas_eps_eps_update_result_value, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
curr_len--;
curr_offset++;
if (curr_len == 0)
return;
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_emm_trac_area_upd_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(NAS_PDU_TYPE_EMM, DE_EMM_CAUSE, NULL);
ELEM_OPT_TLV(0x5F, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3346 value");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
ELEM_OPT_TV_SHORT( 0xA0 , NAS_PDU_TYPE_EMM, DE_EMM_UE_RA_CAP_INF_UPD_NEED , NULL );
ELEM_OPT_TLV(0x57, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_EPS_BE_CTX_STATUS, NULL);
ELEM_OPT_TLV( 0x31 , GSM_A_PDU_TYPE_GM, DE_MS_NET_CAP , NULL );
ELEM_OPT_TV(0x13, NAS_PDU_TYPE_COMMON, DE_EPS_CMN_LOC_AREA_ID, " - Old location area identification");
ELEM_OPT_TV_SHORT( 0x90 , GSM_A_PDU_TYPE_GM, DE_TMSI_STAT , NULL );
ELEM_OPT_TLV( 0x11, NAS_PDU_TYPE_COMMON, DE_EPS_MS_CM_2 , NULL );
ELEM_OPT_TLV( 0x20, NAS_PDU_TYPE_COMMON, DE_EPS_MS_CM_3 , NULL );
ELEM_OPT_TLV(0x40, GSM_A_PDU_TYPE_DTAP, DE_SUP_CODEC_LIST, " - Supported Codecs");
ELEM_OPT_TV_SHORT( 0xF0 , NAS_PDU_TYPE_EMM, DE_EMM_ADD_UPD_TYPE, NULL );
ELEM_OPT_TLV(0x5D, GSM_A_PDU_TYPE_GM, DE_VOICE_DOMAIN_PREF, NULL);
ELEM_OPT_TV_SHORT(0xE0 , NAS_PDU_TYPE_EMM, DE_EMM_GUTI_TYPE, " - Old GUTI type");
ELEM_OPT_TV_SHORT(0xD0 , GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_COMMON, DE_MS_NET_FEAT_SUP, NULL);
ELEM_OPT_TLV(0x10, GSM_A_PDU_TYPE_GM, DE_NET_RES_ID_CONT, " - TMSI based NRI container");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
eps_nas_gen_msg_cont_type = 0;
}
static void
nas_esm_act_ded_eps_bearer_ctx_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
if (len == 0)
return;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_esm_act_def_eps_bearer_ctx_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
if (len == 0)
return;
pinfo->link_dir = P2P_DIR_UL;
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
ELEM_OPT_TLV(0x37, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - T3396 value");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
ELEM_OPT_TLV(0x37, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - T3396 value");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_esm_deact_eps_bearer_ctx_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
if (len == 0)
return;
pinfo->link_dir = P2P_DIR_UL;
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_esm_inf_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_esm_inf_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
if (len == 0)
return;
pinfo->link_dir = P2P_DIR_UL;
ELEM_OPT_TLV( 0x28 , GSM_A_PDU_TYPE_GM, DE_ACC_POINT_NAME , NULL );
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_esm_mod_eps_bearer_ctx_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
if (len == 0)
return;
pinfo->link_dir = P2P_DIR_UL;
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_esm_mod_eps_bearer_ctx_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
if (len == 0)
return;
pinfo->link_dir = P2P_DIR_DL;
ELEM_OPT_TLV( 0x5B , NAS_PDU_TYPE_ESM, DE_ESM_EPS_QOS , " - New EPS QoS" );
ELEM_OPT_TLV( 0x36 , GSM_A_PDU_TYPE_GM, DE_TRAFFIC_FLOW_TEMPLATE , NULL );
ELEM_OPT_TLV( 0x30 , GSM_A_PDU_TYPE_GM, DE_QOS , " - New QoS" );
ELEM_OPT_TV( 0x32 , GSM_A_PDU_TYPE_GM, DE_LLC_SAPI , " - Negotiated LLC SAPI" );
ELEM_OPT_TV_SHORT ( 0x80 , GSM_A_PDU_TYPE_GM , DE_RAD_PRIO , NULL );
ELEM_OPT_TLV( 0x34 , GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID , NULL );
ELEM_OPT_TLV( 0x5E , NAS_PDU_TYPE_ESM, DE_ESM_APN_AGR_MAX_BR , NULL );
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_esm_notification(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(NAS_PDU_TYPE_ESM, DE_ESM_NOTIF_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
ELEM_OPT_TLV(0x37, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - T3396 value");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
if (curr_len == 0)
return;
ELEM_OPT_TV_SHORT( 0xd0 , NAS_PDU_TYPE_ESM, DE_ESM_INF_TRF_FLG , NULL );
ELEM_OPT_TLV( 0x28 , GSM_A_PDU_TYPE_GM, DE_ACC_POINT_NAME , NULL );
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_esm_pdn_disc_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_V(NAS_PDU_TYPE_ESM, DE_ESM_CAUSE, NULL);
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
nas_esm_pdn_disc_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
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
if (curr_len == 0)
return;
ELEM_OPT_TLV( 0x27 , GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT , NULL );
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
len = tvb_length(tvb);
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
proto_tree_add_text(tree, tvb, offset, 1,"Unknown message 0x%x",oct);
return;
}
proto_tree_add_item(tree, hf_idx, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (msg_fcn_p == NULL)
{
proto_tree_add_text(tree, tvb, offset, len - offset,
"Message Elements");
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
len = tvb_length(tvb);
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
proto_tree_add_text(tree, tvb, offset, 1,"Unknown message 0x%x",oct);
return;
}
proto_tree_add_item(tree, hf_idx, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (msg_fcn_p == NULL)
{
proto_tree_add_text(tree, tvb, offset, len - offset,
"Message Elements");
}
else
{
(*msg_fcn_p)(tvb, tree, pinfo, offset, len - offset);
}
}
static void
dissect_nas_eps_plain(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
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
nas_emm_service_req(tvb, nas_eps_tree, pinfo, offset, tvb_length(tvb)-offset);
return;
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
proto_tree_add_text(nas_eps_tree, tvb, offset, -1, "Not a NAS EPS PD %u(%s)",
pd,
val_to_str_const(pd, protocol_discriminator_vals, "unknown"));
break;
}
}
static void
dissect_nas_eps(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *item;
proto_tree *nas_eps_tree;
guint8 pd, security_header_type;
int offset = 0;
guint32 len;
guint32 msg_auth_code;
len = tvb_length(tvb);
if (len < 8) {
dissect_nas_eps_plain(tvb, pinfo, tree);
return;
}
if (g_nas_eps_dissect_plain) {
dissect_nas_eps_plain(tvb, pinfo, tree);
return;
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
return;
} else {
proto_tree_add_text(nas_eps_tree, tvb, offset, len, "All ESM / Test Procedures messages should be integrity protected");
return;
}
} else {
if (security_header_type >= 12) {
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Service request");
nas_emm_service_req(tvb, nas_eps_tree, pinfo, offset, len-offset);
return;
}
proto_tree_add_item(nas_eps_tree, hf_nas_eps_msg_auth_code, tvb, offset, 4, ENC_BIG_ENDIAN);
msg_auth_code = tvb_get_ntohl(tvb, offset);
offset+=4;
if ((security_header_type == 2)||(security_header_type == 4)) {
if (msg_auth_code != 0) {
proto_tree_add_item(nas_eps_tree, hf_nas_eps_seq_no, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
pd = tvb_get_guint8(tvb,offset);
if ((pd != 7) && (pd != 15) &&
(((pd&0x0f) != 2) || (((pd&0x0f) == 2) && ((pd&0xf0) > 0) && ((pd&0xf0) < 0x50)))) {
proto_tree_add_text(nas_eps_tree, tvb, offset, len-6,"Ciphered message");
return;
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
proto_tree_add_text(nas_eps_tree, tvb, offset, -1, "Not a NAS EPS PD %u(%s)",
pd,
val_to_str_const(pd, protocol_discriminator_vals, "unknown"));
break;
}
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
{ &hf_nas_eps_emm_eps_att_type,
{ "EPS attach type","nas_eps.emm.eps_att_type",
FT_UINT8,BASE_DEC, VALS(nas_eps_emm_eps_att_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_esr_ps,
{ "ESRPS","nas_eps.emm.esr_ps",
FT_BOOLEAN ,BASE_NONE, TFS(&nas_eps_emm_esr_ps_value), 0x0,
"Support of EXTENDED SERVICE REQUEST for packet services", HFILL }
},
{ &hf_nas_eps_emm_cs_lcs,
{ "CS-LCS","nas_eps.emm.cs_lcs",
FT_UINT8, BASE_DEC, VALS(nas_eps_emm_cs_lcs_vals), 0x0,
"Location services indicator in CS", HFILL }
},
{ &hf_nas_eps_emm_epc_lcs,
{ "EPC-LCS","nas_eps.emm.epc_lcs",
FT_BOOLEAN ,BASE_NONE, TFS(&nas_eps_emm_epc_lcs_value), 0x0,
"Location services indicator in EPC", HFILL }
},
{ &hf_nas_eps_emm_emc_bs,
{ "EMC BS","nas_eps.emm.emc_bs",
FT_BOOLEAN, BASE_NONE, TFS(&nas_eps_emm_emc_bs_value), 0x0,
"Emergency bearer services indicator", HFILL }
},
{ &hf_nas_eps_emm_ims_vops,
{ "IMS VoPS","nas_eps.emm.ims_vops",
FT_BOOLEAN, BASE_NONE, TFS(&nas_eps_emm_ims_vops_value), 0x0,
"IMS voice over PS session indicator", HFILL }
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
{ "odd/even indic","nas_eps.emm.odd_even",
FT_UINT8,BASE_DEC, NULL, 0x8,
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
{ &hf_nas_eps_emm_imsi,
{ "IMSI", "nas_eps.emm.imsi",
FT_STRING, BASE_NONE, NULL, 0,
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
{ &hf_nas_eps_emm_add_upd_type,
{ "AUTV","nas_eps.emm.add_upd_type",
FT_UINT8, BASE_DEC, VALS(nas_eps_emm_add_upd_type_vals), 0x0,
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
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eea0,
{ "EEA0","nas_eps.emm.eea0",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x80,
NULL, HFILL }
},
{ &hf_nas_eps_emm_128eea1,
{ "128-EEA1","nas_eps.emm.128eea1",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x40,
NULL, HFILL }
},
{ &hf_nas_eps_emm_128eea2,
{ "128-EEA2","nas_eps.emm.128eea2",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x20,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eea3,
{ "128-EEA3","nas_eps.emm.eea3",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x10,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eea4,
{ "EEA4","nas_eps.emm.eea4",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eea5,
{ "EEA5","nas_eps.emm.eea5",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x04,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eea6,
{ "EEA6","nas_eps.emm.eea6",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eea7,
{ "EEA7","nas_eps.emm.eea7",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eia0,
{ "EIA0","nas_eps.emm.eia0",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x80,
NULL, HFILL }
},
{ &hf_nas_eps_emm_128eia1,
{ "128-EIA1","nas_eps.emm.128eia1",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x40,
NULL, HFILL }
},
{ &hf_nas_eps_emm_128eia2,
{ "128-EIA2","nas_eps.emm.128eia2",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x20,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eia3,
{ "128-EIA3","nas_eps.emm.eia3",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x10,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eia4,
{ "EIA4","nas_eps.emm.eia4",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eia5,
{ "EIA5","nas_eps.emm.eia5",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x04,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eia6,
{ "EIA6","nas_eps.emm.eia6",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_emm_eia7,
{ "EIA7","nas_eps.emm.eia7",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea0,
{ "UEA0","nas_eps.emm.uea0",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x80,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea1,
{ "UEA1","nas_eps.emm.uea1",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x40,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea2,
{ "UEA2","nas_eps.emm.uea2",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x20,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea3,
{ "UEA3","nas_eps.emm.uea3",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x10,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea4,
{ "UEA4","nas_eps.emm.uea4",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea5,
{ "UEA5","nas_eps.emm.uea5",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x04,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea6,
{ "UEA6","nas_eps.emm.uea6",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uea7,
{ "UEA7","nas_eps.emm.uea7",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_emm_ucs2_supp,
{ "UCS2 support (UCS2)","nas_eps.emm.emm_ucs2_supp",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_ucs2_supp_flg_value), 0x80,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uia1,
{ "UMTS integrity algorithm UIA1","nas_eps.emm.uia1",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x40,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uia2,
{ "UMTS integrity algorithm UIA2","nas_eps.emm.uia2",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x20,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uia3,
{ "UMTS integrity algorithm UIA3","nas_eps.emm.uia3",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x10,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uia4,
{ "UMTS integrity algorithm UIA4","nas_eps.emm.uia4",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uia5,
{ "UMTS integrity algorithm UIA5","nas_eps.emm.uia5",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x04,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uia6,
{ "UMTS integrity algorithm UIA6","nas_eps.emm.uia6",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_emm_uia7,
{ "UMTS integrity algorithm UIA7","nas_eps.emm.uia7",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_emm_gea1,
{ "GPRS encryption algorithm GEA1","nas_eps.emm.gea1",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x40,
NULL, HFILL }
},
{ &hf_nas_eps_emm_gea2,
{ "GPRS encryption algorithm GEA2","nas_eps.emm.gea2",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x20,
NULL, HFILL }
},
{ &hf_nas_eps_emm_gea3,
{ "GPRS encryption algorithm GEA3","nas_eps.emm.gea3",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x10,
NULL, HFILL }
},
{ &hf_nas_eps_emm_gea4,
{ "GPRS encryption algorithm GEA4","nas_eps.emm.gea4",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x08,
NULL, HFILL }
},
{ &hf_nas_eps_emm_gea5,
{ "GPRS encryption algorithm GEA5","nas_eps.emm.gea5",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x04,
NULL, HFILL }
},
{ &hf_nas_eps_emm_gea6,
{ "GPRS encryption algorithm GEA6","nas_eps.emm.gea6",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_emm_gea7,
{ "GPRS encryption algorithm GEA7","nas_eps.emm.gea7",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_supported_flg_value), 0x01,
NULL, HFILL }
},
{ &hf_nas_eps_emm_h245_ash_cap,
{ "H.245-ASH capability","nas_eps.emm.h245_ash_cap",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_h245_ash_cap_flg), 0x20,
"H.245 after SRVCC handover capability", HFILL }
},
{ &hf_nas_eps_emm_acc_csfb_cap,
{ "ACC-CSFB capability","nas_eps.emm.acc_csfb_cap",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_acc_csfb_cap_flg), 0x10,
"Access class control for CSFB capability", HFILL }
},
{ &hf_nas_eps_emm_lpp_cap,
{ "LPP capability","nas_eps.emm.lpp_cap",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_lpp_cap_flg), 0x08,
"LTE Positioning Protocol capability", HFILL }
},
{ &hf_nas_eps_emm_lcs_cap,
{ "LCS capability","nas_eps.emm.lcs_cap",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_lcs_cap_flg), 0x04,
"Location services notification mechanisms capability", HFILL }
},
{ &hf_nas_eps_emm_1xsrvcc_cap,
{ "1xSRVCC capability","nas_eps.emm.1xsrvcc_cap",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_1xsrvcc_cap_flg), 0x02,
NULL, HFILL }
},
{ &hf_nas_eps_emm_nf_cap,
{ "NF capability","nas_eps.emm.nf_cap",
FT_BOOLEAN, 8, TFS(&nas_eps_emm_nf_cap_flg), 0x01,
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
{ &hf_nas_eps_emm_guti_type,
{ "GUTI type", "nas_eps.emm.guti_type",
FT_BOOLEAN, BASE_NONE, TFS(&nas_eps_emm_guti_type_value), 0x0,
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
{ &hf_nas_eps_esm_linked_bearer_id,
{ "Linked EPS bearer identity","nas_eps.esm.linked_bearer_id",
FT_UINT8,BASE_DEC, VALS(nas_eps_esm_linked_bearer_id_vals), 0x0,
NULL, HFILL }
},
{ &hf_nas_eps_active_flg,
{ "Active flag", "nas_eps.emm.active_flg",
FT_BOOLEAN, BASE_NONE, TFS(&nas_eps_emm_active_flg_value), 0x0,
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
#define NUM_INDIVIDUAL_ELEMS 5
gint *ett[NUM_INDIVIDUAL_ELEMS +
NUM_NAS_EPS_COMMON_ELEM +
NUM_NAS_MSG_EMM + NUM_NAS_EMM_ELEM+
NUM_NAS_MSG_ESM + NUM_NAS_ESM_ELEM];
ett[0] = &ett_nas_eps;
ett[1] = &ett_nas_eps_esm_msg_cont;
ett[2] = &ett_nas_eps_nas_msg_cont;
ett[3] = &ett_nas_eps_gen_msg_cont;
ett[4] = &ett_nas_eps_cmn_add_info;
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
register_dissector(PFNAME, dissect_nas_eps, proto_nas_eps);
register_dissector("nas-eps_plain", dissect_nas_eps_plain, proto_nas_eps);
nas_eps_module = prefs_register_protocol(proto_nas_eps, NULL);
prefs_register_bool_preference(nas_eps_module,
"dissect_plain",
"Force dissect as plain NAS EPS",
"Always dissect NAS EPS messages as plain",
&g_nas_eps_dissect_plain);
}
void
proto_reg_handoff_nas_eps(void)
{
gsm_a_dtap_handle = find_dissector("gsm_a_dtap");
lpp_handle = find_dissector("lpp");
}
