gint
dvbci_set_addrs(guint8 event, packet_info *pinfo)
{
if (!IS_DATA_TRANSFER(event))
return -1;
if (event == DVBCI_EVT_DATA_HOST_TO_CAM) {
SET_ADDRESS(&pinfo->src, AT_STRINGZ,
(int)strlen(ADDR_HOST)+1, ADDR_HOST);
SET_ADDRESS(&pinfo->dst, AT_STRINGZ,
(int)strlen(ADDR_CAM)+1 , ADDR_CAM);
}
else {
SET_ADDRESS(&pinfo->src, AT_STRINGZ,
(int)strlen(ADDR_CAM)+1 , ADDR_CAM);
SET_ADDRESS(&pinfo->dst, AT_STRINGZ,
(int)strlen(ADDR_HOST)+1, ADDR_HOST);
}
return 1;
}
guint8
dvbci_get_evt_from_addrs(packet_info *pinfo)
{
static const address a_cam = { AT_STRINGZ, -1, sizeof(ADDR_CAM), ADDR_CAM };
static const address a_host = { AT_STRINGZ, -1, sizeof(ADDR_HOST), ADDR_HOST };
if ( ADDRESSES_EQUAL(&(pinfo->src), &a_cam) &&
ADDRESSES_EQUAL(&(pinfo->dst), &a_host) ) {
return DVBCI_EVT_DATA_CAM_TO_HOST;
}
else if ( ADDRESSES_EQUAL(&(pinfo->src), &a_host) &&
ADDRESSES_EQUAL(&(pinfo->dst), &a_cam) ) {
return DVBCI_EVT_DATA_HOST_TO_CAM;
}
else
return DVBCI_EVT_INVALID_EVT;
}
static inline gint16 two_comp_to_int16(guint16 x)
{
return (x&0x8000) ? -~(x-1) : x;
}
static void
dvbci_init(void)
{
buf_size_cam = 0;
buf_size_host = 0;
reassembly_table_init(&tpdu_reassembly_table,
&addresses_reassembly_table_functions);
reassembly_table_init(&spdu_reassembly_table,
&addresses_reassembly_table_functions);
}
static gint
dissect_desc_loop(int len_hf,
tvbuff_t *tvb, gint offset, packet_info *pinfo _U_, proto_tree *tree)
{
gint offset_start;
guint16 desc_loop_len;
guint desc_len;
offset_start = offset;
desc_loop_len = tvb_get_ntohs(tvb, offset) & 0x0FFF;
proto_tree_add_item(tree, len_hf, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (offset-offset_start < 2+desc_loop_len) {
desc_len = proto_mpeg_descriptor_dissect(tvb, offset, tree);
if (desc_len==0)
break;
offset += desc_len;
}
return offset-offset_start;
}
static gint
dissect_opp_status_body(tvbuff_t *tvb, gint offset,
packet_info *pinfo _U_, proto_tree *tree)
{
gint offset_start;
offset_start = offset;
proto_tree_add_item(tree, hf_dvbci_info_ver_op_status,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_nit_ver,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dvbci_pro_typ,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_init_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_ent_chg_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_ent_val_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_ref_req_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dvbci_err_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_dlv_sys_hint,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dvbci_refr_req_date,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dvbci_refr_req_time,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset-offset_start;
}
static gint
dissect_opp_cap_loop(guint8 cap_loop_len, const gchar *title,
int item_hf, guint item_len,
tvbuff_t *tvb, gint offset,
packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *loop_tree = NULL;
guint i;
if (!title)
return -1;
if (item_len==0 || cap_loop_len%item_len != 0)
return -1;
if (tree && cap_loop_len>0) {
ti = proto_tree_add_text(tree, tvb, offset, cap_loop_len, "%s", title);
loop_tree = proto_item_add_subtree(ti, ett_dvbci_opp_cap_loop);
}
for (i=0; i<cap_loop_len; i+=item_len) {
proto_tree_add_item(loop_tree, item_hf,
tvb, offset+i, item_len, ENC_BIG_ENDIAN);
}
return cap_loop_len;
}
static gint
read_utc_time(tvbuff_t *tvb, gint offset, nstime_t *utc_time)
{
gint bcd_time_offset;
guint8 hour, min, sec;
if (!utc_time)
return -1;
nstime_set_zero(utc_time);
utc_time->secs = (tvb_get_ntohs(tvb, offset) - 40587) * 86400;
bcd_time_offset = offset+2;
hour = BCD44_TO_DEC(tvb_get_guint8(tvb, bcd_time_offset));
min = BCD44_TO_DEC(tvb_get_guint8(tvb, bcd_time_offset+1));
sec = BCD44_TO_DEC(tvb_get_guint8(tvb, bcd_time_offset+2));
if (hour>23 || min>59 || sec>59)
return -1;
utc_time->secs += hour*3600 + min*60 + sec;
return 5;
}
static gint
dissect_rating(tvbuff_t *tvb, gint offset,
packet_info *pinfo _U_, proto_tree *tree)
{
guint8 rating;
rating = tvb_get_guint8(tvb, offset);
if (1<=rating && rating<=0x0F) {
proto_tree_add_uint_format(tree, hf_dvbci_rating,
tvb, offset, 1, rating,
"Rating is %d years (%d+3)", rating+3, rating);
} else {
proto_tree_add_uint_format(tree, hf_dvbci_rating,
tvb, offset, 1, rating,
"Rating is unknown/undefined (%d)", rating);
}
return 1;
}
static void
store_lsc_msg_dissector(circuit_t *circuit, guint8 ip_proto, guint16 port)
{
dissector_handle_t msg_handle = NULL;
if (!circuit)
return;
if (ip_proto==LSC_TCP)
msg_handle = dissector_get_uint_handle(tcp_dissector_table, port);
else if (ip_proto==LSC_UDP)
msg_handle = dissector_get_uint_handle(udp_dissector_table, port);
circuit_set_dissector(circuit, msg_handle);
}
static gint
dissect_conn_desc(tvbuff_t *tvb, gint offset, circuit_t *circuit,
packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *conn_desc_tree = NULL;
guint32 tag;
gint offset_start, offset_body;
gint len_field;
guint8 conn_desc_type;
guint8 ip_ver, ip_proto;
guint16 port;
proto_item *port_item = NULL;
gint hostname_len;
offset_start = offset;
tag = tvb_get_ntoh24(tvb, offset);
if (tag!= T_CONNECTION_DESCRIPTOR)
return 0;
ti = proto_tree_add_text(tree, tvb,
offset_start, -1, "Connection descriptor");
conn_desc_tree = proto_item_add_subtree(ti, ett_dvbci_lsc_conn_desc);
proto_tree_add_item(conn_desc_tree, hf_dvbci_apdu_tag,
tvb, offset, APDU_TAG_SIZE, ENC_BIG_ENDIAN);
offset += APDU_TAG_SIZE;
offset = dissect_ber_length(pinfo, conn_desc_tree,
tvb, offset, &len_field, NULL);
offset_body = offset;
conn_desc_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(conn_desc_tree, hf_dvbci_conn_desc_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (conn_desc_type == CONN_DESC_IP) {
proto_tree_add_item(conn_desc_tree, hf_dvbci_lsc_media_tag,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(conn_desc_tree, hf_dvbci_lsc_media_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ip_ver = tvb_get_guint8(tvb, offset);
proto_tree_add_item(conn_desc_tree, hf_dvbci_lsc_ip_ver,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (ip_ver == LSC_IPV4) {
offset += FT_IPv6_LEN-FT_IPv4_LEN;
proto_tree_add_item(conn_desc_tree, hf_dvbci_lsc_ipv4_addr,
tvb, offset, FT_IPv4_LEN, ENC_BIG_ENDIAN);
offset += FT_IPv4_LEN;
}
else if (ip_ver == LSC_IPV6) {
proto_tree_add_item(conn_desc_tree, hf_dvbci_lsc_ipv6_addr,
tvb, offset, FT_IPv6_LEN, ENC_NA);
offset += FT_IPv6_LEN;
}
else
offset += FT_IPv6_LEN;
port = tvb_get_ntohs(tvb, offset);
port_item = proto_tree_add_item(conn_desc_tree,
hf_dvbci_lsc_dst_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
ip_proto = tvb_get_guint8(tvb, offset);
proto_tree_add_item(conn_desc_tree, hf_dvbci_lsc_proto,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
if (port_item) {
if (ip_proto==LSC_TCP && get_tcp_port(port)) {
proto_item_append_text(port_item, " (%s)",
get_tcp_port(port));
}
else if (ip_proto==LSC_UDP && get_udp_port(port)) {
proto_item_append_text(port_item, " (%s)",
get_udp_port(port));
}
}
store_lsc_msg_dissector(circuit, ip_proto, port);
} else if (conn_desc_type == CONN_DESC_HOSTNAME) {
proto_tree_add_item(conn_desc_tree, hf_dvbci_lsc_media_tag,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(conn_desc_tree, hf_dvbci_lsc_media_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ip_proto = tvb_get_guint8(tvb, offset);
proto_tree_add_item(conn_desc_tree, hf_dvbci_lsc_proto,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
port = tvb_get_ntohs(tvb, offset);
port_item = proto_tree_add_item(conn_desc_tree,
hf_dvbci_lsc_dst_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
if (port_item) {
if (ip_proto==LSC_TCP && get_tcp_port(port)) {
proto_item_append_text(port_item, " (%s)",
get_tcp_port(port));
}
else if (ip_proto==LSC_UDP && get_udp_port(port)) {
proto_item_append_text(port_item, " (%s)",
get_udp_port(port));
}
}
store_lsc_msg_dissector(circuit, ip_proto, port);
hostname_len = (offset_body+len_field)-offset;
proto_tree_add_item(conn_desc_tree, hf_dvbci_lsc_hostname,
tvb, offset, hostname_len, ENC_ASCII|ENC_NA);
offset += hostname_len;
} else {
proto_tree_add_text(conn_desc_tree, tvb,
offset, len_field-1, "media specific data");
offset += len_field-1;
}
proto_item_set_len(ti, offset-offset_start);
return offset-offset_start;
}
static inline gboolean
is_cc_item_exportable(guint8 dat_id)
{
if (dat_id == CC_ID_KP)
return FALSE;
return TRUE;
}
static gint
dissect_cc_item(tvbuff_t *tvb, gint offset,
packet_info *pinfo, proto_tree *tree, guint8 *dat_id_ptr)
{
proto_item *ti = NULL;
proto_tree *cc_item_tree = NULL;
gint offset_start;
guint16 dat_len;
guint8 dat_id;
asn1_ctx_t asn1_ctx;
int hf_cert_index;
guint8 emi;
guint16 prog_num;
guint8 status;
offset_start = offset;
dat_id = tvb_get_guint8(tvb, offset);
if (dat_id_ptr)
*dat_id_ptr = dat_id;
ti = proto_tree_add_text(tree, tvb, offset_start, -1, "CC data item: %s",
val_to_str_const(dat_id, dvbci_cc_dat_id, "unknown"));
cc_item_tree = proto_item_add_subtree(ti, ett_dvbci_cc_item);
proto_tree_add_item(cc_item_tree, hf_dvbci_cc_dat_id,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
dat_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(cc_item_tree, tvb, offset, 2, "Length: %d", dat_len);
offset += 2;
switch (dat_id) {
case CC_ID_HOST_BRAND_CERT:
case CC_ID_CICAM_BRAND_CERT:
case CC_ID_HOST_DEV_CERT:
case CC_ID_CICAM_DEV_CERT:
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
hf_cert_index = (dat_id==CC_ID_HOST_BRAND_CERT ||
dat_id==CC_ID_CICAM_BRAND_CERT) ?
hf_dvbci_brand_cert : hf_dvbci_dev_cert;
x509ce_enable_ciplus();
dissect_x509af_Certificate(FALSE, tvb, offset,
&asn1_ctx, cc_item_tree, hf_cert_index);
x509ce_disable_ciplus();
break;
case CC_ID_URI:
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "URI");
proto_tree_add_item(cc_item_tree, hf_dvbci_uri_ver,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cc_item_tree, hf_dvbci_uri_aps,
tvb, offset+1, 1, ENC_BIG_ENDIAN);
emi = (tvb_get_guint8(tvb, offset+1) & 0x30) >> 4;
proto_tree_add_item(cc_item_tree, hf_dvbci_uri_emi,
tvb, offset+1, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "EMI 0x%x", emi);
proto_tree_add_item(cc_item_tree, hf_dvbci_uri_ict,
tvb, offset+1, 1, ENC_BIG_ENDIAN);
if (emi==0) {
proto_tree_add_item(cc_item_tree, hf_dvbci_uri_rct,
tvb, offset+1, 1, ENC_BIG_ENDIAN);
}
break;
case CC_ID_PROG_NUM:
prog_num = tvb_get_ntohs(tvb, offset);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL,
"Program number 0x%x", prog_num);
proto_tree_add_item(cc_item_tree, hf_dvbci_cc_prog_num,
tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case CC_ID_KEY_REGISTER:
proto_tree_add_item(cc_item_tree, hf_dvbci_cc_key_register,
tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case CC_ID_STATUS_FIELD:
case CC_ID_REC_START_STATUS:
case CC_ID_MODE_CHG_STATUS:
case CC_ID_REC_STOP_STATUS:
status = tvb_get_guint8(tvb, offset);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Status: %s",
val_to_str_const(status, dvbci_cc_status, "unknown"));
proto_tree_add_item(cc_item_tree, hf_dvbci_cc_status_field,
tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case CC_ID_OPERATING_MODE:
proto_tree_add_item(cc_item_tree, hf_dvbci_cc_op_mode,
tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(cc_item_tree, hf_dvbci_cc_data,
tvb, offset, dat_len, ENC_NA);
break;
}
offset += dat_len;
proto_item_set_len(ti, offset-offset_start);
return offset-offset_start;
}
static gint
dissect_cc_data_payload(guint32 tag, tvbuff_t *tvb, gint offset,
packet_info *pinfo, proto_tree *tree, gboolean *exportable_flag)
{
gint offset_start;
guint8 i, snd_dat_nbr, req_dat_nbr;
guint8 dat_id;
gint item_len;
if (exportable_flag)
*exportable_flag = (tag==T_CC_SAC_DATA_REQ || tag==T_CC_SAC_DATA_CNF);
offset_start = offset;
proto_tree_add_item(
tree, hf_dvbci_cc_sys_id_bitmask, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
snd_dat_nbr = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Number of sent data items: %d", snd_dat_nbr);
offset++;
for(i=0; i<snd_dat_nbr &&
tvb_reported_length_remaining(tvb, offset)>0; i++) {
item_len = dissect_cc_item(tvb, offset, pinfo, tree, &dat_id);
if (item_len < 0)
return -1;
offset += item_len;
if (!exportable_flag || *exportable_flag==FALSE)
continue;
if (!is_cc_item_exportable(dat_id))
*exportable_flag = FALSE;
}
if (tag==T_CC_DATA_REQ || tag==T_CC_SAC_DATA_REQ) {
req_dat_nbr = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Number of requested data items: %d", req_dat_nbr);
offset++;
for(i=0; i<req_dat_nbr &&
tvb_reported_length_remaining(tvb, offset)>0; i++) {
proto_tree_add_item(
tree, hf_dvbci_cc_dat_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
}
return offset-offset_start;
}
static gint
pref_key_string_to_bin(const gchar *key_string, unsigned char **key_bin)
{
int key_string_len;
int i, j;
char input[2];
if (!key_string || !key_bin)
return -1;
key_string_len = (int)strlen(key_string);
if (key_string_len != 2*AES_KEY_LEN)
return -1;
*key_bin = (unsigned char*)g_malloc(key_string_len/2);
j=0;
for (i=0; i<key_string_len-1; i+=2) {
input[0] = key_string[0+i];
input[1] = key_string[1+i];
(*key_bin)[j++] = (unsigned char)strtoul((const char*)&input, NULL, 16);
}
return key_string_len/2;
}
static tvbuff_t *
decrypt_sac_msg_body(
guint8 enc_cip, tvbuff_t *encrypted_tvb, gint offset, gint len)
{
gint ret;
gboolean opened = FALSE;
gcry_cipher_hd_t cipher;
gcry_error_t err;
gint clear_len;
unsigned char *clear_data = NULL;
tvbuff_t *clear_tvb = NULL;
unsigned char *sek = NULL, *siv = NULL;
if (enc_cip != CC_SAC_ENC_AES128_CBC)
goto end;
if (len%AES_BLOCK_LEN != 0)
goto end;
ret = pref_key_string_to_bin(dvbci_sek, &sek);
if (ret==-1)
goto end;
ret = pref_key_string_to_bin(dvbci_siv, &siv);
if (ret==-1)
goto end;
err = gcry_cipher_open(&cipher, GCRY_CIPHER_AES, GCRY_CIPHER_MODE_CBC, 0);
if (gcry_err_code (err))
goto end;
opened = TRUE;
err = gcry_cipher_setkey (cipher, sek, AES_KEY_LEN);
if (gcry_err_code (err))
goto end;
err = gcry_cipher_setiv (cipher, siv, AES_BLOCK_LEN);
if (gcry_err_code (err))
goto end;
clear_len = len;
clear_data = (unsigned char *)g_malloc(clear_len);
err = gcry_cipher_decrypt (cipher, clear_data, clear_len,
tvb_get_string(wmem_packet_scope(), encrypted_tvb, offset, len), len);
if (gcry_err_code (err))
goto end;
clear_tvb = tvb_new_child_real_data(encrypted_tvb,
(const guint8 *)clear_data, clear_len, clear_len);
tvb_set_free_cb(clear_tvb, g_free);
end:
if (opened)
gcry_cipher_close (cipher);
if (sek)
g_free(sek);
if (siv)
g_free(siv);
if (!clear_tvb && clear_data)
g_free(clear_data);
return clear_tvb;
}
static tvbuff_t *
decrypt_sac_msg_body(guint8 enc_cip _U_,
tvbuff_t *encrypted_tvb _U_, gint offset _U_, gint len _U_)
{
return NULL;
}
static void
dissect_si_string(tvbuff_t *tvb, gint offset, gint str_len,
packet_info *pinfo, proto_tree *tree, const gchar *title,
gboolean show_col_info)
{
guint8 byte0;
guint8 *si_str = NULL;
if (!title)
return;
if (str_len<=0)
return;
byte0 = tvb_get_guint8(tvb, offset);
if (byte0>=0x01 && byte0<=0x0F) {
proto_tree_add_item(tree, hf_dvbci_char_tbl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
str_len--;
}
else if (byte0>=0x10 && byte0 <= 0x1F) {
proto_tree_add_expert(tree, pinfo, &ei_dvbci_dvbci_char_tbl, tvb, offset, 1);
offset++;
str_len--;
proto_tree_add_text(tree, tvb, offset, str_len, "encoded text");
return;
}
else if (byte0>=0x80 && byte0<=0x9F) {
proto_tree_add_item(tree, hf_dvbci_text_ctrl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
str_len--;
}
si_str = tvb_get_string(wmem_packet_scope(), tvb, offset, str_len);
if (!si_str)
return;
proto_tree_add_text(tree, tvb, offset, str_len, "%s: %s", title, si_str);
if (show_col_info)
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "%s", si_str);
}
static gboolean
dissect_ca_enable(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree)
{
gboolean desc_ok = FALSE;
guint8 byte, ca_enab;
byte = tvb_get_guint8(tvb,offset);
proto_tree_add_item(tree, hf_dvbci_ca_enable_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
if (byte&0x80) {
ca_enab = byte & ~0x80;
proto_tree_add_item(tree, hf_dvbci_ca_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
if (ca_enab==CA_ENAB_DESC_OK ||
ca_enab==CA_ENAB_DESC_OK_PURCHASE ||
ca_enab==CA_ENAB_DESC_OK_TECH) {
desc_ok = TRUE;
}
}
return desc_ok;
}
static gint
dissect_ca_desc(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree)
{
gint offset_start;
guint8 tag, len_byte;
proto_item *ti = NULL;
proto_tree *ca_desc_tree = NULL;
offset_start = offset;
tag = tvb_get_guint8(tvb,offset);
if (tag != CA_DESC_TAG) {
proto_tree_add_expert(tree, pinfo, &ei_dvbci_ca_pmt_cmd_id, tvb, offset, 1);
return 0;
}
ti = proto_tree_add_text(
tree, tvb, offset_start, -1, "Conditional Access descriptor");
ca_desc_tree = proto_item_add_subtree(ti, ett_dvbci_ca_desc);
offset++;
len_byte = tvb_get_guint8(tvb,offset);
proto_tree_add_item(
ca_desc_tree, hf_dvbci_descr_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(
ca_desc_tree, hf_dvbci_ca_sys_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(
ca_desc_tree, hf_dvbci_ca_pid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if ((len_byte-4) != 0) {
proto_tree_add_text(
ca_desc_tree, tvb, offset, len_byte-4, "private data");
offset += (len_byte-4);
}
proto_item_set_len(ti, offset-offset_start);
return offset-offset_start;
}
static gint
dissect_es(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *es_tree = NULL;
gint offset_start, ca_desc_len;
gint es_info_len, all_len;
offset_start = offset;
ti = proto_tree_add_text(tree, tvb, offset_start, -1, "Elementary Stream");
es_tree = proto_item_add_subtree(ti, ett_dvbci_application);
proto_tree_add_item(
es_tree, hf_dvbci_stream_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(
es_tree, hf_dvbci_es_pid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
es_info_len = tvb_get_ntohs(tvb, offset) & 0x0FFF;
proto_tree_add_item(
es_tree, hf_dvbci_es_info_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (es_info_len != 0) {
all_len = offset + es_info_len;
proto_tree_add_item(
es_tree, hf_dvbci_ca_pmt_cmd_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
while (offset < all_len) {
ca_desc_len = dissect_ca_desc(tvb, offset, pinfo, es_tree);
if (ca_desc_len <= 0)
return -1;
offset += ca_desc_len;
}
}
else {
proto_tree_add_text(
es_tree, tvb, 0, 0,
"No CA descriptors for this elementary stream");
}
proto_item_set_len(ti, offset-offset_start);
return offset-offset_start;
}
static gint
dissect_dvbci_text(const gchar *title, tvbuff_t *tvb, gint offset,
packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *text_tree;
guint32 tag;
gint offset_start;
gint len_field;
offset_start = offset;
if (!title)
return 0;
tag = tvb_get_ntoh24(tvb, offset);
if (tag!=T_TEXT_LAST && tag!=T_TEXT_MORE)
return 0;
ti = proto_tree_add_text(tree, tvb, offset_start, -1, "%s", title);
text_tree = proto_item_add_subtree(ti, ett_dvbci_text);
proto_tree_add_item(text_tree, hf_dvbci_apdu_tag,
tvb, offset, APDU_TAG_SIZE, ENC_BIG_ENDIAN);
offset += APDU_TAG_SIZE;
offset = dissect_ber_length(pinfo, text_tree, tvb, offset, &len_field, NULL);
dissect_si_string(tvb, offset, len_field, pinfo, text_tree, "Text", FALSE);
offset += len_field;
proto_item_set_len(ti, offset-offset_start);
return (offset-offset_start);
}
static proto_item *
dissect_res_id(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, guint32 res_id, gboolean show_col_info)
{
proto_item *ti = NULL;
proto_tree *res_tree = NULL;
gint tvb_data_len;
if (tvb) {
if (res_id!=0)
return NULL;
res_id = tvb_get_ntohl(tvb, offset);
tvb_data_len = RES_ID_LEN;
}
else {
if (res_id==0)
return NULL;
offset = 0;
tvb_data_len = 0;
}
if (show_col_info) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s Version %d",
val_to_str_const(RES_CLASS(res_id), dvbci_res_class,
"Invalid Resource class"),
RES_VER(res_id));
}
ti = proto_tree_add_text(tree, tvb, offset, tvb_data_len,
"Resource ID: 0x%04x", res_id);
res_tree = proto_item_add_subtree(ti, ett_dvbci_res);
proto_tree_add_uint(res_tree, hf_dvbci_res_id_type,
tvb, offset, tvb_data_len, res_id);
proto_tree_add_uint(res_tree, hf_dvbci_res_class,
tvb, offset, tvb_data_len, res_id);
proto_tree_add_uint(res_tree, hf_dvbci_res_type,
tvb, offset, tvb_data_len, res_id);
proto_tree_add_uint(res_tree, hf_dvbci_res_ver,
tvb, offset, tvb_data_len, res_id);
return ti;
}
static void
dissect_dvbci_payload_rm(guint32 tag, gint len_field,
tvbuff_t *tvb, gint offset, circuit_t *circuit _U_,
packet_info *pinfo, proto_tree *tree)
{
const gchar *tag_str;
if (tag==T_PROFILE) {
if (len_field % RES_ID_LEN) {
tag_str = val_to_str(tag, dvbci_apdu_tag, "Unknown: %d");
proto_tree_add_expert_format(tree, pinfo, &ei_dvbci_bad_length, tvb, 0, APDU_TAG_SIZE,
"Invalid APDU length field, %s must be a multiple of 4 bytes",
tag_str);
return;
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
dissect_res_id(tvb, offset, pinfo, tree, 0, FALSE);
offset += RES_ID_LEN;
}
}
}
static void
dissect_dvbci_payload_ap(guint32 tag, gint len_field _U_,
tvbuff_t *tvb, gint offset, circuit_t *circuit _U_,
packet_info *pinfo, proto_tree *tree)
{
guint8 menu_str_len;
guint8 *menu_string;
guint8 data_rate;
if (tag==T_APP_INFO) {
proto_tree_add_item(tree, hf_dvbci_app_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(
tree, hf_dvbci_app_manf, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(
tree, hf_dvbci_manf_code, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
menu_str_len = tvb_get_guint8(tvb,offset);
proto_tree_add_item(
tree, hf_dvbci_menu_str_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
menu_string = tvb_get_string(wmem_packet_scope(), tvb, offset, menu_str_len);
if (menu_string) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL,
"Module name %s", menu_string);
proto_tree_add_text(tree, tvb, offset, menu_str_len,
"Menu string: %s", menu_string);
}
}
else if (tag== T_DATARATE_INFO) {
data_rate = tvb_get_guint8(tvb, offset);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "%s",
val_to_str(data_rate, dvbci_data_rate, "unknown (0x%x)"));
proto_tree_add_item(tree, hf_dvbci_data_rate, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
static void
dissect_dvbci_payload_ca(guint32 tag, gint len_field,
tvbuff_t *tvb, gint offset, circuit_t *circuit _U_,
packet_info *pinfo, proto_tree *tree)
{
const gchar *tag_str;
proto_item *pi;
guint16 prog_num;
guint8 byte;
guint prog_info_len;
gint es_info_len, all_len;
gint ca_desc_len;
proto_tree *es_tree = NULL;
gboolean desc_ok = FALSE;
if (tag==T_CA_INFO) {
if (len_field % 2) {
tag_str = val_to_str(tag, dvbci_apdu_tag, "Unknown: %d");
proto_tree_add_expert_format(tree, pinfo, &ei_dvbci_bad_length, tvb, 0, APDU_TAG_SIZE,
"Invalid APDU length field, %s must be a multiple of 2 bytes",
tag_str);
return;
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(
tree, hf_dvbci_ca_sys_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
else if (tag==T_CA_PMT) {
proto_tree_add_item(
tree, hf_dvbci_ca_pmt_list_mgmt, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
prog_num = tvb_get_ntohs(tvb, offset);
col_append_sep_fstr(
pinfo->cinfo, COL_INFO, NULL, "Program number %x", prog_num);
proto_tree_add_item(
tree, hf_dvbci_prog_num, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
byte = tvb_get_guint8(tvb,offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Version number: 0x%x, Current-next indicator: 0x%x",
(byte&0x3E) >> 1, byte&0x01);
offset++;
prog_info_len = tvb_get_ntohs(tvb, offset) & 0x0FFF;
proto_tree_add_item(
tree, hf_dvbci_prog_info_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (prog_info_len != 0) {
all_len = offset + prog_info_len;
proto_tree_add_item(
tree, hf_dvbci_ca_pmt_cmd_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
while (offset < all_len) {
ca_desc_len = dissect_ca_desc(tvb, offset, pinfo, tree);
if (ca_desc_len <= 0)
return;
offset += ca_desc_len;
}
}
else {
proto_tree_add_text(
tree, tvb, 0, 0, "No CA descriptors at program level");
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
es_info_len = dissect_es(tvb, offset, pinfo, tree);
if (es_info_len <= 0)
return;
offset += es_info_len;
}
}
else if (tag==T_CA_PMT_REPLY) {
prog_num = tvb_get_ntohs(tvb, offset);
col_append_sep_fstr(
pinfo->cinfo, COL_INFO, NULL, "Program number %x", prog_num);
proto_tree_add_item(
tree, hf_dvbci_prog_num, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
byte = tvb_get_guint8(tvb,offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Version number: 0x%x, Current-next indicator: 0x%x",
(byte&0x3E) >> 1, byte&0x01);
offset++;
desc_ok |= dissect_ca_enable(tvb, offset, pinfo, tree);
offset++;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
pi = proto_tree_add_text(tree, tvb, offset, 3, "Elementary Stream");
es_tree = proto_item_add_subtree(pi, ett_dvbci_application);
proto_tree_add_item(es_tree, hf_dvbci_es_pid,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
desc_ok |= dissect_ca_enable(tvb, offset, pinfo, es_tree);
offset++;
}
if (desc_ok) {
col_append_sep_fstr(
pinfo->cinfo, COL_INFO, NULL, "descrambling possible");
}
}
}
static void
dissect_dvbci_payload_aut(guint32 tag, gint len_field _U_,
tvbuff_t *tvb, gint offset, circuit_t *circuit _U_,
packet_info *pinfo _U_, proto_tree *tree)
{
gint bytes_len;
proto_tree_add_item(tree, hf_dvbci_auth_proto_id,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
bytes_len = tvb_reported_length_remaining(tvb, offset);
if (bytes_len <= 0)
return;
if (tag==T_AUTH_REQ) {
proto_tree_add_item(tree, hf_dvbci_auth_req_bytes,
tvb, offset, bytes_len, ENC_NA);
}
else if (tag==T_AUTH_RESP) {
proto_tree_add_item(tree, hf_dvbci_auth_resp_bytes,
tvb, offset, bytes_len, ENC_NA);
}
}
static void
dissect_dvbci_payload_hc(guint32 tag, gint len_field _U_,
tvbuff_t *tvb, gint offset, circuit_t *circuit _U_,
packet_info *pinfo, proto_tree *tree)
{
proto_item *pi;
guint16 nid, onid, tsid, svcid;
guint8 ref;
guint16 old_pid, new_pid;
gboolean pmt_flag;
gint desc_loop_len;
tvbuff_t *pmt_tvb = NULL;
guint8 status;
switch (tag) {
case T_TUNE:
nid = tvb_get_ntohs(tvb, offset);
pi = proto_tree_add_item(
tree, hf_dvbci_network_id, tvb, offset, 2, ENC_BIG_ENDIAN);
if (nid) {
expert_add_info(pinfo, pi, &ei_dvbci_network_id);
}
offset += 2;
onid = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_dvbci_original_network_id,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tsid = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_dvbci_transport_stream_id,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
svcid = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(
tree, hf_dvbci_service_id, tvb, offset, 2, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ",
"nid 0x%x, onid 0x%x, tsid 0x%x, svcid 0x%x",
nid, onid, tsid, svcid);
break;
case T_REPLACE:
ref = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dvbci_replacement_ref,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
old_pid = tvb_get_ntohs(tvb, offset) & 0x1FFF;
proto_tree_add_item(tree, hf_dvbci_replaced_pid,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
new_pid = tvb_get_ntohs(tvb, offset) & 0x1FFF;
proto_tree_add_item( tree, hf_dvbci_replacement_pid,
tvb, offset, 2, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ",
"ref 0x%x, 0x%x -> 0x%x", ref, old_pid, new_pid);
break;
case T_CLEAR_REPLACE:
ref = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dvbci_replacement_ref,
tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "ref 0x%x", ref);
break;
case T_TUNE_BROADCAST_REQ:
pmt_flag = ((tvb_get_guint8(tvb, offset) & 0x01) == 0x01);
proto_tree_add_item(tree, hf_dvbci_pmt_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(
tree, hf_dvbci_service_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
desc_loop_len = dissect_desc_loop(hf_dvbci_hc_desc_loop_len,
tvb, offset, pinfo, tree);
if (desc_loop_len<0)
break;
offset += desc_loop_len;
if (pmt_flag) {
pmt_tvb = tvb_new_subset_remaining(tvb, offset);
if (mpeg_pmt_handle) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", ");
col_set_fence(pinfo->cinfo, COL_INFO);
call_dissector(mpeg_pmt_handle, pmt_tvb, pinfo, tree);
}
else
call_dissector(data_handle, pmt_tvb, pinfo, tree);
}
break;
case T_TUNE_REPLY:
status = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dvbci_hc_status,
tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ",
(status == HC_STAT_OK ? "ok" : "error"));
break;
case T_ASK_RELEASE_REPLY:
proto_tree_add_item(tree, hf_dvbci_hc_release_reply,
tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
break;
}
}
static void
dissect_dvbci_payload_dt(guint32 tag, gint len_field,
tvbuff_t *tvb, gint offset, circuit_t *circuit _U_,
packet_info *pinfo, proto_tree *tree)
{
nstime_t resp_intv;
proto_item *pi = NULL;
const gchar *tag_str;
gint time_field_len;
nstime_t utc_time;
gint16 local_offset;
if (tag==T_DATE_TIME_ENQ) {
nstime_set_zero(&resp_intv);
resp_intv.secs = tvb_get_guint8(tvb, offset);
pi = proto_tree_add_time(tree, hf_dvbci_resp_intv,
tvb, offset, 1, &resp_intv);
if (resp_intv.secs==0) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "individual query");
if (pi)
proto_item_append_text(pi, " (individual query)");
}
else {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL,
"update every %s", rel_time_to_str(&resp_intv));
}
}
else if (tag==T_DATE_TIME) {
if (len_field!=5 && len_field!=7) {
tag_str = val_to_str_const(tag, dvbci_apdu_tag, "unknown");
proto_tree_add_expert_format(tree, pinfo, &ei_dvbci_bad_length, tvb, APDU_TAG_SIZE, offset-APDU_TAG_SIZE,
"Invalid APDU length field, %s must be 5 or 7 bytes", tag_str);
return;
}
time_field_len = read_utc_time(tvb, offset, &utc_time);
if (time_field_len<0) {
proto_tree_add_expert_format(tree, pinfo, &ei_dvbci_bad_length, tvb, offset, 5,
"Invalid UTC time field, 2 bytes MJD, 3 bytes BCD time hhmmss");
return;
}
proto_tree_add_time(tree, hf_dvbci_utc_time,
tvb, offset, time_field_len, &utc_time);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "%s UTC",
abs_time_to_str(&utc_time, ABSOLUTE_TIME_UTC, FALSE));
offset += time_field_len;
if (len_field==7) {
local_offset = two_comp_to_int16(tvb_get_ntohs(tvb, offset));
proto_tree_add_int_format(tree, hf_dvbci_local_offset,
tvb, offset, 2, local_offset,
"offset between UTC and local time is %d minutes",
local_offset);
}
else {
proto_tree_add_text(tree, tvb, 0, 0,
"Offset between UTC and local time is unknown");
}
}
}
static void
dissect_dvbci_payload_mmi(guint32 tag, gint len_field,
tvbuff_t *tvb, gint offset, circuit_t *circuit _U_,
packet_info *pinfo, proto_tree *tree)
{
gint offset_start;
guint8 close_mmi_cmd_id;
guint8 disp_ctl_cmd, disp_rep_id;
const gchar *disp_ctl_cmd_str = NULL, *disp_rep_id_str = NULL;
guint8 ans_txt_len;
guint8 ans_id;
guint8 choice_or_item_nb;
gint text_len;
guint8 choice_ref;
offset_start = offset;
switch(tag) {
case T_CLOSE_MMI:
close_mmi_cmd_id = tvb_get_guint8(tvb,offset);
proto_tree_add_item(tree, hf_dvbci_close_mmi_cmd_id,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (close_mmi_cmd_id == CLOSE_MMI_CMD_ID_DELAY) {
if (len_field != 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_dvbci_bad_length, tvb,
APDU_TAG_SIZE, offset_start-APDU_TAG_SIZE,
"Length field must be 2");
return;
}
proto_tree_add_item(tree, hf_dvbci_close_mmi_delay, tvb,
offset, 1, ENC_BIG_ENDIAN);
}
break;
case T_DISPLAY_CONTROL:
disp_ctl_cmd = tvb_get_guint8(tvb,offset);
disp_ctl_cmd_str = val_to_str_const(disp_ctl_cmd,
dvbci_disp_ctl_cmd, "unknown command");
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ",
"%s", disp_ctl_cmd_str);
proto_tree_add_item(tree, hf_dvbci_disp_ctl_cmd, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
if (disp_ctl_cmd == DISP_CMD_SET_MMI_MODE)
{
proto_tree_add_item(tree, hf_dvbci_mmi_mode, tvb,
offset, 1, ENC_BIG_ENDIAN);
if (len_field != 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_dvbci_bad_length, tvb,
APDU_TAG_SIZE, offset_start-APDU_TAG_SIZE,
"Length field must be 2");
return;
}
}
break;
case T_DISPLAY_REPLY:
disp_rep_id = tvb_get_guint8(tvb,offset);
disp_rep_id_str = val_to_str_const(disp_rep_id,
dvbci_disp_rep_id, "unknown command");
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ",
"%s", disp_rep_id_str);
proto_tree_add_item(tree, hf_dvbci_disp_rep_id,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (disp_rep_id == DISP_REP_ID_MMI_MODE_ACK) {
proto_tree_add_item(tree, hf_dvbci_mmi_mode,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
else if (disp_rep_id == DISP_REP_ID_DISP_CHAR_TBL ||
disp_rep_id == DISP_REP_ID_INP_CHAR_TBL) {
while (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(tree, hf_dvbci_char_tbl,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
}
break;
case T_ENQ:
proto_tree_add_item(tree, hf_dvbci_blind_ans,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ans_txt_len = tvb_get_guint8(tvb,offset);
if (ans_txt_len == NB_UNKNOWN) {
proto_tree_add_text(tree, tvb, offset, 1,
"Length of expected answer is unknown");
}
else
proto_tree_add_item(tree, hf_dvbci_ans_txt_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
dissect_si_string(tvb, offset,
tvb_reported_length_remaining(tvb, offset),
pinfo, tree, "Enquiry string", FALSE);
break;
case T_ANSW:
ans_id = tvb_get_guint8(tvb,offset);
proto_tree_add_item(tree, hf_dvbci_ans_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (ans_id == ANSW_ID_ANSWER) {
dissect_si_string(tvb, offset,
tvb_reported_length_remaining(tvb, offset),
pinfo, tree, "Answer", TRUE);
}
break;
case T_MENU_LAST:
case T_MENU_MORE:
case T_LIST_LAST:
case T_LIST_MORE:
choice_or_item_nb = tvb_get_guint8(tvb,offset);
if (choice_or_item_nb == NB_UNKNOWN)
{
proto_tree_add_text(tree, tvb, offset, 1,
"Number of items is unknown");
}
else
{
if (IS_MENU_APDU(tag)) {
proto_tree_add_item(
tree, hf_dvbci_choice_nb, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(
tree, hf_dvbci_item_nb, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
offset++;
text_len = dissect_dvbci_text("Title", tvb, offset, pinfo, tree);
offset += text_len;
text_len = dissect_dvbci_text("Sub-title", tvb, offset, pinfo, tree);
offset += text_len;
text_len = dissect_dvbci_text("Bottom line", tvb, offset, pinfo, tree);
offset += text_len;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
text_len = dissect_dvbci_text("Item", tvb, offset, pinfo, tree);
if (text_len<APDU_TAG_SIZE+1) {
proto_tree_add_expert(tree, pinfo, &ei_dvbci_not_text_more_or_text_last, tvb, offset, -1);
return;
}
offset += text_len;
}
break;
case T_MENU_ANSW:
choice_ref = tvb_get_guint8(tvb,offset);
if (choice_ref == 0x0) {
proto_tree_add_text(tree, tvb, offset, 1,
"Selection was cancelled.");
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ",
"cancelled");
}
else {
proto_tree_add_item(
tree, hf_dvbci_choice_ref, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ",
"Item %d", choice_ref);
}
break;
default:
break;
}
}
static void
dissect_dvbci_payload_hlc(guint32 tag, gint len_field _U_,
tvbuff_t *tvb, gint offset, circuit_t *circuit _U_,
packet_info *pinfo, proto_tree *tree)
{
guint8 *str;
if (tag==T_HOST_COUNTRY) {
proto_tree_add_item(tree, hf_dvbci_host_country,
tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_ASCII|ENC_NA);
}
else if (tag==T_HOST_LANGUAGE) {
proto_tree_add_item(tree, hf_dvbci_host_language,
tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_ASCII|ENC_NA);
}
str = tvb_get_string(wmem_packet_scope(), tvb, offset,
tvb_reported_length_remaining(tvb, offset));
if (str)
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "%s", str);
}
static void
dissect_dvbci_payload_cup(guint32 tag, gint len_field _U_,
tvbuff_t *tvb, gint offset, circuit_t *circuit _U_,
packet_info *pinfo, proto_tree *tree)
{
guint8 upgrade_type;
guint16 download_time;
guint8 answer, progress;
switch(tag) {
case T_CAM_FIRMWARE_UPGRADE:
upgrade_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dvbci_cup_type, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "(%s)",
val_to_str_const(upgrade_type, dvbci_cup_type, "unknown"));
offset++;
download_time = tvb_get_ntohs(tvb, offset);
if (download_time == 0) {
proto_tree_add_uint_format(tree, hf_dvbci_cup_download_time,
tvb, offset, 2, download_time,
"estimated download time is unknown");
}
else {
proto_tree_add_uint_format(tree, hf_dvbci_cup_download_time,
tvb, offset, 2, download_time,
"estimated download time is %d seconds",
download_time);
}
break;
case T_CAM_FIRMWARE_UPGRADE_REPLY:
answer = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dvbci_cup_answer, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "%s",
val_to_str_const(answer, dvbci_cup_answer, "unknown"));
break;
case T_CAM_FIRMWARE_UPGRADE_PROGRESS:
progress = tvb_get_guint8(tvb, offset);
if (progress > 100) {
proto_tree_add_expert(tree, pinfo, &ei_dvbci_cup_progress, tvb, offset, 1);
}
else {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "%d%%", progress);
proto_tree_add_uint_format(tree, hf_dvbci_cup_progress,
tvb, offset, 1, progress,
"download progress %d%%", progress);
}
break;
case T_CAM_FIRMWARE_UPGRADE_COMPLETE:
proto_tree_add_item(tree, hf_dvbci_cup_reset, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
break;
}
}
static void
dissect_sac_msg(guint32 tag, tvbuff_t *tvb, gint offset,
packet_info *pinfo, proto_tree *tree, gboolean exported)
{
gint offset_start;
guint32 msg_ctr;
guint8 enc_flag, enc_cip;
proto_item *enc_flag_pi, *ti;
guint16 sac_payload_len;
gint sac_payload_data_len = 0;
tvbuff_t *clear_sac_body_tvb;
proto_tree *sac_tree = NULL;
gboolean is_exportable = FALSE;
offset_start = offset;
msg_ctr = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dvbci_sac_msg_ctr,
tvb, offset, 4, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL,
"message #%d", msg_ctr);
offset += 4;
proto_tree_add_item(tree, hf_dvbci_sac_proto_ver,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_sac_auth_cip,
tvb, offset, 1, ENC_BIG_ENDIAN);
enc_flag = tvb_get_guint8(tvb, offset) & 0x1;
enc_flag_pi = proto_tree_add_item(tree, hf_dvbci_sac_payload_enc,
tvb, offset, 1, ENC_BIG_ENDIAN);
if (exported && enc_flag) {
expert_add_info(pinfo, enc_flag_pi, &ei_dvbci_sac_payload_enc);
enc_flag = 0;
}
offset++;
enc_cip = (tvb_get_guint8(tvb, offset)&0xE0) >> 5;
proto_tree_add_item(tree, hf_dvbci_sac_enc_cip,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
sac_payload_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_dvbci_sac_payload_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (tvb_reported_length_remaining(tvb, offset) < 0)
return;
if (enc_flag) {
clear_sac_body_tvb = decrypt_sac_msg_body(enc_cip,
tvb, offset, tvb_reported_length_remaining(tvb, offset));
}
else {
clear_sac_body_tvb = tvb_new_subset_remaining(tvb, offset);
}
if (!clear_sac_body_tvb) {
proto_tree_add_item(tree, hf_dvbci_sac_enc_body, tvb, offset,
tvb_reported_length_remaining(tvb, offset), ENC_NA);
return;
}
if (enc_flag)
add_new_data_source(pinfo, clear_sac_body_tvb, "Clear SAC message body");
if (sac_payload_len>0) {
ti = proto_tree_add_text(tree, clear_sac_body_tvb, 0, sac_payload_len,
"SAC message payload");
sac_tree = proto_item_add_subtree(ti, ett_dvbci_sac_msg_body);
if (tag==T_CC_SAC_DATA_REQ || tag==T_CC_SAC_DATA_CNF) {
sac_payload_data_len = dissect_cc_data_payload(tag,
clear_sac_body_tvb, 0, pinfo, sac_tree, &is_exportable);
}
else if (tag==T_CC_SAC_SYNC_REQ) {
sac_payload_data_len = 0;
}
else if (tag==T_CC_SAC_SYNC_CNF) {
proto_tree_add_item(sac_tree, hf_dvbci_cc_status_field,
clear_sac_body_tvb, 0, 1, ENC_BIG_ENDIAN);
sac_payload_data_len = 1;
}
if (sac_payload_data_len < 0)
return;
if (sac_payload_len > sac_payload_data_len) {
proto_tree_add_text(sac_tree, clear_sac_body_tvb,
sac_payload_data_len,
sac_payload_len-sac_payload_data_len,
"padding");
}
}
proto_tree_add_item(tree, hf_dvbci_sac_signature,
clear_sac_body_tvb, sac_payload_len,
tvb_reported_length_remaining(clear_sac_body_tvb,
sac_payload_len), ENC_NA);
if (!exported && is_exportable && have_tap_listener(exported_pdu_tap)) {
tvbuff_t *clear_sac_msg_tvb;
exp_pdu_data_t *exp_pdu_data;
clear_sac_msg_tvb = tvb_new_composite();
tvb_composite_append(clear_sac_msg_tvb,
tvb_clone_offset_len(tvb, offset_start, SAC_MSG_HDR_LEN));
tvb_composite_append(clear_sac_msg_tvb, clear_sac_body_tvb);
tvb_composite_finalize(clear_sac_msg_tvb);
exp_pdu_data = load_export_pdu_tags(
pinfo, EXPORTED_SAC_MSG_PROTO, -1, EXP_PDU_TAG_DVBCI_EVT_BIT);
exp_pdu_data->tvb_length = tvb_length(clear_sac_msg_tvb);
exp_pdu_data->pdu_tvb = clear_sac_msg_tvb;
tap_queue_packet(exported_pdu_tap, pinfo, exp_pdu_data);
}
}
static int
dissect_dvbci_exported_sac_msg(
tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint8 evt;
guint32 tag;
evt = dvbci_get_evt_from_addrs(pinfo);
if (!IS_DATA_TRANSFER(evt))
return 0;
col_append_sep_fstr(pinfo->cinfo, COL_PROTOCOL, NULL, EXPORTED_SAC_MSG_PROTO);
col_clear(pinfo->cinfo, COL_INFO);
if (evt== DVBCI_EVT_DATA_CAM_TO_HOST)
tag = T_CC_SAC_DATA_REQ;
else
tag = T_CC_SAC_DATA_CNF;
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s",
val_to_str_const(tag, dvbci_apdu_tag, "unknown"));
dissect_sac_msg(tag, tvb, 0, pinfo, tree, TRUE);
return tvb_reported_length(tvb);
}
static void
dissect_dvbci_payload_cc(guint32 tag, gint len_field _U_,
tvbuff_t *tvb, gint offset, circuit_t *circuit _U_,
packet_info *pinfo, proto_tree *tree)
{
guint8 status;
proto_item *pi;
nstime_t utc_time;
guint8 pin_stat;
guint8 evt_cent;
switch(tag) {
case T_CC_OPEN_CNF:
proto_tree_add_item(tree, hf_dvbci_cc_sys_id_bitmask,
tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case T_CC_DATA_REQ:
case T_CC_DATA_CNF:
dissect_cc_data_payload(tag, tvb, offset, pinfo, tree, NULL);
break;
case T_CC_SYNC_CNF:
status = tvb_get_guint8(tvb, offset);
proto_tree_add_item(
tree, hf_dvbci_cc_status_field, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "%s",
val_to_str_const(status, dvbci_cc_status, "unknown"));
break;
case T_CC_SAC_DATA_REQ:
case T_CC_SAC_DATA_CNF:
case T_CC_SAC_SYNC_REQ:
case T_CC_SAC_SYNC_CNF:
dissect_sac_msg(tag, tvb, offset, pinfo, tree, FALSE);
break;
case T_CC_PIN_CAPABILITIES_REPLY:
proto_tree_add_item(tree, hf_dvbci_capability_field,
tvb, offset, 1 , ENC_BIG_ENDIAN);
offset++;
if (tvb_get_ntoh40(tvb, offset) == 0) {
proto_tree_add_text(tree, tvb, offset, UTC_TIME_LEN,
"CICAM PIN has never been changed");
}
else {
if (read_utc_time(tvb, offset, &utc_time) < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_dvbci_bad_length, tvb, offset, UTC_TIME_LEN,
"Invalid UTC time field, 2 bytes MJD, 3 bytes BCD time hhmmss");
break;
}
else {
proto_tree_add_time(tree, hf_dvbci_pin_chg_time,
tvb, offset, UTC_TIME_LEN, &utc_time);
}
}
offset += UTC_TIME_LEN;
dissect_rating(tvb, offset, pinfo, tree);
break;
case T_CC_PIN_REPLY:
pin_stat = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dvbci_pincode_status,
tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "%s",
val_to_str_const(pin_stat, dvbci_pincode_status, "unknown"));
break;
case T_CC_PIN_EVENT:
proto_tree_add_item(tree, hf_dvbci_cc_prog_num,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dvbci_pincode_status,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
dissect_rating(tvb, offset, pinfo, tree);
offset++;
if (read_utc_time(tvb, offset, &utc_time) < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_dvbci_bad_length, tvb, offset, UTC_TIME_LEN,
"Invalid UTC time field, 2 bytes MJD, 3 bytes BCD time hhmmss");
break;
}
else {
proto_tree_add_time(tree, hf_dvbci_pin_evt_time,
tvb, offset, UTC_TIME_LEN, &utc_time);
}
offset += UTC_TIME_LEN;
evt_cent = tvb_get_guint8(tvb, offset);
pi = proto_tree_add_item(tree, hf_dvbci_pin_evt_cent,
tvb, offset, 1, ENC_BIG_ENDIAN);
if (evt_cent > 100) {
expert_add_info(pinfo, pi, &ei_dvbci_pin_evt_cent);
}
offset++;
proto_tree_add_item(tree, hf_dvbci_cc_priv_data, tvb, offset,
tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case T_CC_PIN_PLAYBACK:
dissect_rating(tvb, offset, pinfo, tree);
offset++;
proto_tree_add_item(tree, hf_dvbci_cc_priv_data, tvb, offset,
tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case T_CC_PIN_CMD:
case T_CC_PIN_MMI_REQ:
proto_tree_add_item(tree, hf_dvbci_pincode, tvb, offset,
tvb_reported_length_remaining(tvb, offset),
ENC_ASCII|ENC_NA);
break;
default:
break;
}
}
static void
dissect_dvbci_payload_ami(guint32 tag, gint len_field _U_,
tvbuff_t *tvb, gint offset, circuit_t *circuit _U_,
packet_info *pinfo, proto_tree *tree)
{
guint8 app_dom_id_len, init_obj_len;
guint8 *app_dom_id;
guint8 ack_code;
gboolean req_ok = FALSE, file_ok;
guint8 req_type;
guint8 *req_str;
guint8 file_name_len;
guint8 *file_name_str;
guint32 file_data_len;
proto_item *ti = NULL;
proto_tree *req_tree = NULL;
switch(tag) {
case T_REQUEST_START:
app_dom_id_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Application Domain Identifier length %d", app_dom_id_len);
offset++;
init_obj_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Initial Object length %d", init_obj_len);
offset++;
proto_tree_add_item(tree, hf_dvbci_app_dom_id,
tvb, offset, app_dom_id_len, ENC_ASCII|ENC_NA);
app_dom_id = tvb_get_string(wmem_packet_scope(), tvb, offset, app_dom_id_len);
if (app_dom_id) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ",
"for %s", app_dom_id);
}
offset += app_dom_id_len;
proto_tree_add_item(tree, hf_dvbci_init_obj,
tvb, offset, init_obj_len, ENC_ASCII|ENC_NA);
break;
case T_REQUEST_START_ACK:
ack_code = tvb_get_guint8(tvb, offset);
proto_tree_add_item(
tree, hf_dvbci_ack_code, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "%s",
val_to_str_const(ack_code, dvbci_ack_code, "unknown"));
break;
case T_FILE_REQUEST:
req_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dvbci_req_type, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "%s",
val_to_str_const(req_type, dvbci_req_type, "unknown"));
offset++;
if (req_type==REQ_TYPE_FILE_HASH) {
proto_tree_add_item(tree, hf_dvbci_file_hash,
tvb, offset, 16, ENC_NA);
offset += 16;
}
if (tvb_reported_length_remaining(tvb, offset) <= 0)
break;
if (req_type==REQ_TYPE_FILE || req_type==REQ_TYPE_FILE_HASH) {
req_str = tvb_get_string(wmem_packet_scope(), tvb, offset,
tvb_reported_length_remaining(tvb, offset));
if (!req_str)
break;
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "%s", req_str);
proto_tree_add_string_format_value(tree, hf_dvbci_file_name,
tvb, offset, tvb_reported_length_remaining(tvb, offset),
req_str, "%s", req_str);
}
else if (req_type==REQ_TYPE_DATA) {
proto_tree_add_item(tree, hf_dvbci_ami_priv_data, tvb, offset,
tvb_reported_length_remaining(tvb, offset), ENC_NA);
}
break;
case T_FILE_ACKNOWLEDGE:
req_type = tvb_get_guint8(tvb, offset+1);
if (req_type==REQ_TYPE_FILE_HASH) {
req_ok = ((tvb_get_guint8(tvb, offset) & 0x02) == 0x02);
proto_tree_add_item(tree, hf_dvbci_req_ok,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
file_ok = ((tvb_get_guint8(tvb, offset) & 0x01) == 0x01);
proto_tree_add_item(tree, hf_dvbci_file_ok, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dvbci_req_type, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "%s",
val_to_str_const(req_type, dvbci_req_type, "unknown"));
offset++;
if (req_type==REQ_TYPE_FILE || req_type==REQ_TYPE_FILE_HASH) {
file_name_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"File name length %d", file_name_len);
offset++;
file_name_str = tvb_get_string(wmem_packet_scope(),
tvb, offset, file_name_len);
if (!file_name_str)
break;
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ",
"%s", file_name_str);
proto_tree_add_string_format_value(tree, hf_dvbci_file_name,
tvb, offset, file_name_len, file_name_str,
"%s", file_name_str);
offset += file_name_len;
file_data_len = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4,
"File data length %d", file_data_len);
offset += 4;
if (file_data_len > 0) {
proto_tree_add_item(tree, hf_dvbci_file_data,
tvb, offset, file_data_len, ENC_NA);
}
}
else if (req_type==REQ_TYPE_DATA) {
if (tvb_reported_length_remaining(tvb, offset) <= 0)
break;
proto_tree_add_item(tree, hf_dvbci_ami_priv_data, tvb, offset,
tvb_reported_length_remaining(tvb, offset), ENC_NA);
}
else if (req_type==REQ_TYPE_REQ) {
if (tree) {
ti = proto_tree_add_text(tree, tvb,
offset, tvb_reported_length_remaining(tvb, offset),
"Supported request types");
req_tree = proto_item_add_subtree(
ti, ett_dvbci_ami_req_types);
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(req_tree, hf_dvbci_req_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
}
if (req_type==REQ_TYPE_FILE_HASH && req_ok && !file_ok) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL,
"cached copy is valid");
}
break;
case T_APP_ABORT_REQUEST:
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(tree, hf_dvbci_abort_req_code, tvb, offset,
tvb_reported_length_remaining(tvb, offset), ENC_NA);
}
break;
case T_APP_ABORT_ACK:
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(tree, hf_dvbci_abort_ack_code, tvb, offset,
tvb_reported_length_remaining(tvb, offset), ENC_NA);
}
break;
default:
break;
}
}
static void
dissect_dvbci_payload_lsc(guint32 tag, gint len_field,
tvbuff_t *tvb, gint offset, circuit_t *circuit,
packet_info *pinfo, proto_tree *tree)
{
gint offset_start;
guint8 id, timeout, ret_val, phase_id;
gint conn_desc_len, param_len;
guint16 buf_size;
proto_item *pi = NULL;
const gchar *ret_val_str = NULL;
gint msg_len;
tvbuff_t *msg_tvb;
dissector_handle_t msg_handle;
offset_start = offset;
switch(tag) {
case T_COMMS_CMD:
proto_tree_add_item(tree, hf_dvbci_comms_cmd_id,
tvb, offset, 1, ENC_BIG_ENDIAN);
id = tvb_get_guint8(tvb, offset);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "%s",
val_to_str(id, dvbci_comms_cmd_id, "Unknown: %d"));
offset++;
switch(id) {
case COMMS_CMD_ID_CONNECT_ON_CHANNEL:
conn_desc_len = dissect_conn_desc(tvb, offset,
circuit, pinfo, tree);
if (conn_desc_len < 0)
break;
offset += conn_desc_len;
proto_tree_add_item(tree, hf_dvbci_lsc_retry_count,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
timeout = tvb_get_guint8(tvb, offset);
if (timeout==0) {
proto_tree_add_uint_format(tree, hf_dvbci_lsc_timeout,
tvb, offset, 1, timeout, "Infinite timeout");
} else {
proto_tree_add_uint_format(tree, hf_dvbci_lsc_timeout,
tvb, offset, 1, timeout,
"Timeout is %d seconds", timeout);
}
break;
case COMMS_CMD_ID_DISCONNECT_ON_CHANNEL:
case COMMS_CMD_ID_ENQUIRE_STATUS:
if (len_field != 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_dvbci_bad_length, tvb,
APDU_TAG_SIZE, offset_start-APDU_TAG_SIZE,
"Length field must be 1");
}
break;
case COMMS_CMD_ID_SET_PARAMS:
param_len = tvb_reported_length_remaining(tvb, offset);
if (param_len == 2)
buf_size = (guint16)tvb_get_guint8(tvb, offset);
else if (param_len == 3)
buf_size = tvb_get_ntohs(tvb, offset);
else {
proto_tree_add_expert_format(tree, pinfo, &ei_dvbci_bad_length, tvb,
APDU_TAG_SIZE, offset_start-APDU_TAG_SIZE,
"Length field must be 3 or 4");
break;
}
proto_tree_add_uint_format(tree, hf_dvbci_lsc_buf_size,
tvb, offset, param_len-1, buf_size,
"buffer size %d bytes", buf_size);
offset += param_len-1;
timeout = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_dvbci_lsc_timeout,
tvb, offset, 1, timeout,
"timeout is %d milliseconds", timeout*10);
break;
case COMMS_CMD_ID_GET_NEXT_BUFFER:
phase_id = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_dvbci_phase_id,
tvb, offset, 1, phase_id, "Phase ID %d", phase_id);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL,
"received #%d", phase_id);
break;
default:
break;
}
break;
case T_COMMS_REPLY:
proto_tree_add_item(tree, hf_dvbci_comms_rep_id,
tvb, offset, 1, ENC_BIG_ENDIAN);
id = tvb_get_guint8(tvb,offset);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s",
val_to_str(id, dvbci_comms_rep_id, "Unknown: %d"));
offset++;
ret_val = tvb_get_guint8(tvb,offset);
pi = proto_tree_add_item(tree, hf_dvbci_lsc_ret_val,
tvb, offset, 1, ENC_BIG_ENDIAN);
switch (id) {
case COMMS_REP_ID_SEND_ACK:
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ",
"sent #%d", ret_val);
if (pi)
proto_item_append_text(pi, " (sent #%d)", ret_val);
break;
case COMMS_REP_ID_SET_PARAMS_ACK:
ret_val_str = val_to_str_const(ret_val,
dvbci_lsc_ret_val_params, "unknown/error");
break;
case COMMS_REP_ID_STATUS_REPLY:
ret_val_str = val_to_str_const(ret_val,
dvbci_lsc_ret_val_connect, "unknown/error");
break;
default:
ret_val_str = val_to_str_const(ret_val,
dvbci_lsc_ret_val, "unknown/error");
break;
}
if (ret_val_str) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ",
"%s", ret_val_str);
if (pi)
proto_item_append_text(pi, " (%s)", ret_val_str);
}
break;
case T_COMMS_SEND_LAST:
case T_COMMS_SEND_MORE:
case T_COMMS_RCV_LAST:
case T_COMMS_RCV_MORE:
phase_id = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_dvbci_phase_id,
tvb, offset, 1, phase_id, "Phase ID %d", phase_id);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ",
"Phase ID %d", phase_id);
offset++;
msg_len = tvb_reported_length_remaining(tvb, offset);
if (msg_len<=0)
break;
msg_tvb = tvb_new_subset(tvb, offset, msg_len, msg_len);
if (!msg_tvb)
break;
if (dvbci_dissect_lsc_msg && circuit && circuit->dissector_handle) {
msg_handle = circuit->dissector_handle;
col_append_fstr(pinfo->cinfo, COL_INFO, ", ");
col_set_fence(pinfo->cinfo, COL_INFO);
col_append_fstr(pinfo->cinfo, COL_PROTOCOL, ", ");
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
}
else {
msg_handle = data_handle;
}
if (msg_handle)
call_dissector(msg_handle, msg_tvb, pinfo, tree);
break;
default:
break;
}
}
static void
dissect_dvbci_payload_opp(guint32 tag, gint len_field _U_,
tvbuff_t *tvb, gint offset, circuit_t *circuit _U_,
packet_info *pinfo, proto_tree *tree)
{
guint16 nit_loop_len, nit_loop_offset;
tvbuff_t *nit_loop_tvb, *nit_loop_partial_tvb;
guint dvb_nit_bytes;
guint8 table_id;
guint8 cap_loop_len;
gboolean info_valid;
guint8 char_tbl;
guint8 sig_strength, sig_qual;
proto_item *pi;
switch(tag) {
case T_OPERATOR_STATUS:
case T_OPERATOR_SEARCH_STATUS:
dissect_opp_status_body(tvb, offset, pinfo, tree);
break;
case T_OPERATOR_NIT:
nit_loop_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_dvbci_nit_loop_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
if (nit_loop_len==0)
break;
offset += 2;
nit_loop_tvb = tvb_new_subset(
tvb, offset, nit_loop_len, nit_loop_len);
nit_loop_offset = 0;
if (!dvb_nit_handle) {
call_dissector(data_handle, nit_loop_tvb, pinfo, tree);
break;
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", ");
col_set_fence(pinfo->cinfo, COL_INFO);
do {
table_id = tvb_get_guint8(nit_loop_tvb, nit_loop_offset);
if (table_id != TABLE_ID_CICAM_NIT) {
proto_tree_add_expert(tree, pinfo, &ei_dvbci_cicam_nit_table_id,
nit_loop_tvb, nit_loop_offset, 1);
}
nit_loop_partial_tvb =
tvb_new_subset_remaining(nit_loop_tvb, nit_loop_offset);
dvb_nit_bytes = call_dissector(
dvb_nit_handle, nit_loop_partial_tvb, pinfo, tree);
nit_loop_offset += dvb_nit_bytes;
} while (dvb_nit_bytes>0 && nit_loop_offset<nit_loop_len-1);
break;
case T_OPERATOR_INFO:
info_valid = ((tvb_get_guint8(tvb, offset) & 0x08) == 0x08);
proto_tree_add_item(tree, hf_dvbci_info_valid,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_info_ver_op_info,
tvb, offset, 1, ENC_BIG_ENDIAN);
if (!info_valid)
break;
offset++;
proto_tree_add_item(tree, hf_dvbci_cicam_onid,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dvbci_cicam_id,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
char_tbl = tvb_get_guint8(tvb, offset);
if (char_tbl==CHAR_TBL_MULTI_BYTE) {
proto_tree_add_item(tree, hf_dvbci_opp_char_tbl_multi,
tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
}
else {
proto_tree_add_item(tree, hf_dvbci_opp_char_tbl,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (char_tbl==CHAR_TBL_ENC_TYPE_ID) {
proto_tree_add_item(tree, hf_dvbci_enc_type_id,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
}
proto_tree_add_item(tree, hf_dvbci_sdt_rst_trusted,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_eit_rst_trusted,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_eit_pf_usage,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_eit_sch_usage,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_ext_evt_usage,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dvbci_sdt_oth_trusted,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_eit_evt_trigger,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dvbci_opp_lang_code,
tvb, offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
proto_tree_add_item(tree, hf_dvbci_prof_name,
tvb, offset, 1, ENC_ASCII|ENC_NA);
break;
case T_OPERATOR_SEARCH_START:
proto_tree_add_item(tree, hf_dvbci_unattended,
tvb, offset, 1, ENC_BIG_ENDIAN);
cap_loop_len = tvb_get_guint8(tvb, offset) & 0x7F;
proto_tree_add_text(tree, tvb, offset, 1,
"Service type loop length: %d", cap_loop_len);
offset++;
dissect_opp_cap_loop(cap_loop_len, "Service type loop",
hf_dvbci_opp_srv_type, 1, tvb, offset, pinfo, tree);
offset += cap_loop_len;
cap_loop_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Delivery system capabilities loop length: %d",
cap_loop_len);
offset++;
dissect_opp_cap_loop(cap_loop_len,
"Delivery system capabilities loop",
hf_dvbci_dlv_cap_byte, 1,
tvb, offset, pinfo, tree);
offset += cap_loop_len;
cap_loop_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Application capabilities loop length: %d", cap_loop_len);
dissect_opp_cap_loop(cap_loop_len,
"Application capabilities loop",
hf_dvbci_app_cap_bytes, 2,
tvb, offset, pinfo, tree);
break;
case T_OPERATOR_TUNE_STATUS:
proto_tree_add_item(tree, hf_dvbci_desc_num,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
sig_strength = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dvbci_sig_strength,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
sig_qual = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dvbci_sig_qual,
tvb, offset, 1, ENC_BIG_ENDIAN);
if (sig_strength>100 || sig_qual>100) {
pi = proto_tree_add_text(tree, tvb, offset, 1,
"Invalid value for signal strength / signal quality");
expert_add_info(pinfo, pi, &ei_dvbci_sig_qual);
}
offset++;
proto_tree_add_item(tree, hf_dvbci_opp_tune_status,
tvb, offset, 1, ENC_BIG_ENDIAN);
dissect_desc_loop(hf_dvbci_opp_desc_loop_len,
tvb, offset, pinfo, tree);
break;
case T_OPERATOR_TUNE:
dissect_desc_loop(hf_dvbci_opp_desc_loop_len,
tvb, offset, pinfo, tree);
break;
default:
break;
}
}
static void
dissect_dvbci_payload_sas(guint32 tag, gint len_field _U_,
tvbuff_t *tvb, gint offset, circuit_t *circuit,
packet_info *pinfo, proto_tree *tree)
{
gchar app_id_str[2+16+1];
guint8 sas_status;
dissector_handle_t msg_handle;
guint8 msg_nb;
guint16 msg_len;
tvbuff_t *msg_tvb;
switch(tag) {
case T_SAS_CONNECT_RQST:
case T_SAS_CONNECT_CNF:
g_snprintf(app_id_str, sizeof(app_id_str),
"0x%016" G_GINT64_MODIFIER "x", tvb_get_ntoh64(tvb, offset));
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "%s", app_id_str);
proto_tree_add_item(tree, hf_dvbci_sas_app_id,
tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
if (tag == T_SAS_CONNECT_CNF) {
sas_status = tvb_get_guint8(tvb, offset);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL,
(sas_status == SAS_SESS_STATE_CONNECTED ?
"Ok" : "Error"));
proto_tree_add_item(tree, hf_dvbci_sas_sess_state,
tvb, offset, 1, ENC_BIG_ENDIAN);
if (!circuit)
break;
if (sas_status == SAS_SESS_STATE_CONNECTED) {
msg_handle = dissector_get_string_handle(
sas_msg_dissector_table, app_id_str);
circuit_set_dissector(circuit, msg_handle);
}
else
circuit_set_dissector(circuit, NULL);
}
break;
case T_SAS_ASYNC_MSG:
msg_nb = tvb_get_guint8(tvb, offset);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ",
"Message #%d ", msg_nb);
proto_tree_add_item(tree, hf_dvbci_sas_msg_nb,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
msg_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_dvbci_sas_msg_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
msg_tvb = tvb_new_subset(tvb, offset, msg_len, msg_len);
msg_handle = (circuit && circuit->dissector_handle) ?
circuit->dissector_handle : data_handle;
call_dissector(msg_handle, msg_tvb, pinfo, tree);
break;
default:
break;
}
}
static void
dissect_dvbci_apdu(tvbuff_t *tvb, circuit_t *circuit,
packet_info *pinfo, proto_tree *tree, guint8 direction)
{
proto_item *ti;
proto_tree *app_tree = NULL;
guint32 apdu_len, tag, len_field;
const gchar *tag_str;
gint offset;
proto_item *pi;
apdu_info_t *ai;
guint32 apdu_res_id;
const gchar *ai_res_class_str;
apdu_len = tvb_reported_length(tvb);
ti = proto_tree_add_text(tree, tvb, 0, apdu_len, "Application Layer");
app_tree = proto_item_add_subtree(ti, ett_dvbci_application);
tag = tvb_get_ntoh24(tvb, 0);
tag_str = try_val_to_str(tag, dvbci_apdu_tag);
offset = APDU_TAG_SIZE;
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_const(tag, dvbci_apdu_tag, "Unknown/invalid APDU"));
pi = proto_tree_add_item(
app_tree, hf_dvbci_apdu_tag, tvb, 0, APDU_TAG_SIZE, ENC_BIG_ENDIAN);
if (tag_str == NULL) {
expert_add_info(pinfo, pi, &ei_dvbci_apdu_tag);
return;
}
offset = dissect_ber_length(pinfo, app_tree, tvb, offset, &len_field, NULL);
if ((offset+len_field) != apdu_len) {
proto_tree_add_expert_format(app_tree, pinfo, &ei_dvbci_bad_length, tvb,
APDU_TAG_SIZE, offset-APDU_TAG_SIZE,
"Length field is different from the number of apdu payload bytes");
if (apdu_len < offset+len_field)
return;
}
ai = (apdu_info_t *)g_hash_table_lookup(apdu_table,
GUINT_TO_POINTER((guint)tag));
if (!ai) {
proto_tree_add_expert(app_tree, pinfo, &ei_dvbci_apdu_not_supported, tvb, 0, APDU_TAG_SIZE);
return;
}
if (ai->direction!=DIRECTION_ANY && ai->direction!=direction) {
if (ai->direction==DATA_HOST_TO_CAM) {
proto_tree_add_expert(app_tree, pinfo, &ei_dvbci_apu_host_to_cam, tvb, 0, APDU_TAG_SIZE);
}
else {
proto_tree_add_expert(app_tree, pinfo, &ei_dvbci_apu_cam_to_host, tvb, 0, APDU_TAG_SIZE);
}
}
if (ai->min_len_field!=LEN_FIELD_ANY && len_field<ai->min_len_field) {
proto_tree_add_expert_format(app_tree, pinfo, &ei_dvbci_bad_length, tvb, 0, APDU_TAG_SIZE,
"Invalid APDU length field, minimum length field for %s is %d", tag_str, ai->min_len_field);
return;
}
if (ai->len_field!=LEN_FIELD_ANY && len_field!=ai->len_field) {
proto_tree_add_expert_format(app_tree, pinfo, &ei_dvbci_bad_length, tvb, 0, APDU_TAG_SIZE,
"Invalid APDU length field, length field for %s must be %d", tag_str, ai->len_field);
return;
}
if (circuit) {
apdu_res_id = GPOINTER_TO_UINT(
(gpointer)circuit_get_proto_data(circuit, proto_dvbci));
ai_res_class_str = val_to_str_const(ai->res_class, dvbci_res_class, "Unknown");
if(RES_CLASS(apdu_res_id) != ai->res_class) {
proto_tree_add_expert_format(app_tree, pinfo, &ei_dvbci_res_class, tvb, 0, APDU_TAG_SIZE,
"Invalid resource class for this apdu, %s can only be sent on a %s session",
tag_str, ai_res_class_str);
}
if(RES_VER(apdu_res_id) < ai->res_min_ver) {
proto_tree_add_expert_format(app_tree, pinfo, &ei_dvbci_res_ver, tvb, 0, APDU_TAG_SIZE,
"Invalid resource version for this apdu, %s apdu requires at least %s version %d",
tag_str, ai_res_class_str, ai->res_min_ver);
}
}
if (ai->len_field!=0) {
if (!ai->dissect_payload) {
return;
}
ai->dissect_payload(
tag, len_field, tvb, offset, circuit, pinfo, app_tree);
}
}
static void
dissect_dvbci_spdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 direction, guint8 tcid)
{
guint32 spdu_len;
proto_item *ti = NULL;
proto_tree *sess_tree = NULL;
guint8 tag;
const gchar *tag_str;
circuit_t *circuit = NULL;
proto_item *pi;
gint offset;
guint32 len_field;
const spdu_info_t *si;
proto_item *res_id_it = NULL;
guint32 res_id;
guint16 ssnb = 0;
guint8 sess_stat;
tvbuff_t *payload_tvb = NULL;
gint payload_len;
spdu_len = tvb_reported_length(tvb);
ti = proto_tree_add_text(tree, tvb, 0, -1, "Session Layer");
sess_tree = proto_item_add_subtree(ti, ett_dvbci_session);
tag = tvb_get_guint8(tvb,0);
tag_str = try_val_to_str(tag, dvbci_spdu_tag);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str_const(tag, dvbci_spdu_tag, "Invalid SPDU"));
pi = proto_tree_add_item(sess_tree, hf_dvbci_spdu_tag, tvb, 0, 1, ENC_BIG_ENDIAN);
if (tag_str == NULL) {
expert_add_info(pinfo, pi, &ei_dvbci_spdu_tag);
return;
}
offset = dissect_ber_length(pinfo, sess_tree, tvb, 1, &len_field, NULL);
si = (spdu_info_t *)g_hash_table_lookup(spdu_table,
GUINT_TO_POINTER((guint)tag));
if (!si)
return;
if (si->direction!=0 && si->direction!=direction) {
if (si->direction==DATA_HOST_TO_CAM) {
proto_tree_add_expert(sess_tree, pinfo, &ei_dvbci_spdu_host_to_cam, tvb, 0, 1);
}
else {
proto_tree_add_expert(sess_tree, pinfo, &ei_dvbci_spdu_cam_to_host, tvb, 0, 1);
}
}
if (si->len_field != len_field) {
proto_tree_add_expert_format(sess_tree, pinfo, &ei_dvbci_bad_length, tvb, 1, offset-1,
"Invalid SPDU length field, correct length field for %s is %d", tag_str, si->len_field);
return;
}
switch(tag)
{
case T_OPEN_SESSION_REQUEST:
res_id_it = dissect_res_id(tvb, offset, pinfo, sess_tree, 0, TRUE);
break;
case T_CREATE_SESSION:
res_id_it = dissect_res_id(tvb, offset, pinfo, sess_tree, 0, TRUE);
ssnb = tvb_get_ntohs(tvb, offset+RES_ID_LEN);
proto_tree_add_item(sess_tree, hf_dvbci_sess_nb,
tvb, offset+RES_ID_LEN, 2, ENC_BIG_ENDIAN);
break;
case T_OPEN_SESSION_RESPONSE:
case T_CREATE_SESSION_RESPONSE:
sess_stat = tvb_get_guint8(tvb, offset);
proto_tree_add_item(sess_tree, hf_dvbci_sess_status,
tvb, offset, 1, ENC_BIG_ENDIAN);
res_id = tvb_get_ntohl(tvb, offset+1);
res_id_it = dissect_res_id(tvb, offset+1, pinfo, sess_tree, 0, TRUE);
ssnb = tvb_get_ntohs(tvb, offset+1+RES_ID_LEN);
proto_tree_add_item(sess_tree, hf_dvbci_sess_nb, tvb,
offset+1+RES_ID_LEN, 2, ENC_BIG_ENDIAN);
if (sess_stat != SESS_OPENED) {
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Error");
break;
}
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Session opened");
circuit = circuit_new(CT_DVBCI, CT_ID(ssnb, tcid), pinfo->fd->num);
if (circuit) {
circuit_add_proto_data(
circuit, proto_dvbci, GUINT_TO_POINTER(res_id));
}
break;
case T_CLOSE_SESSION_REQUEST:
ssnb = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(
sess_tree, hf_dvbci_sess_nb, tvb,
offset, 2, ENC_BIG_ENDIAN);
break;
case T_CLOSE_SESSION_RESPONSE:
sess_stat = tvb_get_guint8(tvb, offset);
proto_tree_add_item(
sess_tree, hf_dvbci_close_sess_status, tvb,
offset, 1, ENC_BIG_ENDIAN);
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL,
sess_stat==SESS_CLOSED ? "Session closed" : "Error");
ssnb = tvb_get_ntohs(tvb, offset+1);
proto_tree_add_item(sess_tree, hf_dvbci_sess_nb,
tvb, offset+1, 2, ENC_BIG_ENDIAN);
circuit = find_circuit(CT_DVBCI, CT_ID(ssnb, tcid), pinfo->fd->num);
if (circuit)
close_circuit(circuit, pinfo->fd->num);
break;
case T_SESSION_NUMBER:
ssnb = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(
sess_tree, hf_dvbci_sess_nb, tvb,
offset, 2, ENC_BIG_ENDIAN);
payload_len = tvb_reported_length_remaining(tvb, offset+2);
payload_tvb =
tvb_new_subset(tvb, offset+2, payload_len, payload_len);
break;
default:
break;
}
if (ssnb && !circuit)
circuit = find_circuit(CT_DVBCI, CT_ID(ssnb, tcid), pinfo->fd->num);
if (circuit && !res_id_it) {
res_id = GPOINTER_TO_UINT(
(gpointer)circuit_get_proto_data(circuit, proto_dvbci));
res_id_it = dissect_res_id(NULL, 0, pinfo, sess_tree, res_id, TRUE);
PROTO_ITEM_SET_GENERATED(res_id_it);
}
if (payload_tvb) {
proto_item_set_len(ti, spdu_len-tvb_reported_length(payload_tvb));
dissect_dvbci_apdu(payload_tvb, circuit, pinfo, tree, direction);
}
else {
proto_item_set_len(ti, spdu_len);
}
}
static gint
dissect_dvbci_tpdu_status(tvbuff_t *tvb, gint offset,
packet_info *pinfo, proto_tree *tree,
guint8 lpdu_tcid, guint8 r_tpdu_tag)
{
gint offset_new, len_start_offset;
guint8 tag;
guint32 len_field;
guint8 t_c_id, sb_value;
const gchar *sb_str;
proto_item *pi;
offset_new = offset;
tag = tvb_get_guint8(tvb, offset_new);
if (tag!=T_SB) {
proto_tree_add_expert(tree, pinfo, &ei_dvbci_tpdu_status_tag, tvb, offset_new, 1);
return -1;
}
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "T_SB");
proto_tree_add_text(tree, tvb, offset_new, 1, "Response TPDU status");
offset_new++;
len_start_offset = offset_new;
offset_new = dissect_ber_length(
pinfo, tree, tvb, offset_new, &len_field, NULL);
if (len_field != 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_dvbci_bad_length, tvb, len_start_offset, offset_new-len_start_offset,
"Invalid status length field, this must always be 2");
return -1;
}
t_c_id = tvb_get_guint8(tvb, offset_new);
proto_tree_add_item(tree, hf_dvbci_t_c_id, tvb, offset_new, 1, ENC_BIG_ENDIAN);
if (t_c_id!=lpdu_tcid) {
if (r_tpdu_tag==NO_TAG ||
r_tpdu_tag==T_DATA_MORE || r_tpdu_tag==T_DATA_LAST) {
pi = proto_tree_add_text(tree, tvb, offset_new, 1,
"Transport Connection ID mismatch");
expert_add_info_format(pinfo, pi, &ei_dvbci_t_c_id, "Transport Connection ID mismatch, tcid is %d in the transport layer and %d in the link layer", t_c_id, lpdu_tcid);
return -1;
}
}
offset_new++;
sb_value = tvb_get_guint8(tvb, offset_new);
sb_str = try_val_to_str(sb_value, dvbci_sb_value);
pi = proto_tree_add_item(tree, hf_dvbci_sb_value, tvb,
offset_new, 1, ENC_BIG_ENDIAN);
if (sb_str) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "%s", sb_str);
}
else {
proto_tree_add_text(tree, tvb, offset_new, 1,
"Invalid SB_value");
expert_add_info(pinfo, pi, &ei_dvbci_sb_value);
}
offset_new++;
return offset_new-offset;
}
static gint
dissect_dvbci_tpdu_hdr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 direction, guint8 lpdu_tcid, guint32 tpdu_len,
guint8 *hdr_tag, guint32 *body_len)
{
guint8 c_tpdu_tag, r_tpdu_tag, *tag = NULL;
const gchar *c_tpdu_str, *r_tpdu_str;
proto_item *pi;
gint offset;
guint32 len_field;
guint8 t_c_id;
if (direction==DATA_HOST_TO_CAM) {
c_tpdu_tag = tvb_get_guint8(tvb, 0);
tag = &c_tpdu_tag;
c_tpdu_str = try_val_to_str(c_tpdu_tag, dvbci_c_tpdu);
pi = proto_tree_add_item(tree, hf_dvbci_c_tpdu_tag, tvb, 0, 1, ENC_BIG_ENDIAN);
if (c_tpdu_str) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s", c_tpdu_str);
}
else {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL,
"Invalid Command-TPDU tag");
expert_add_info(pinfo, pi, &ei_dvbci_c_tpdu_tag);
return -1;
}
}
else {
r_tpdu_tag = tvb_get_guint8(tvb, 0);
tag = &r_tpdu_tag;
r_tpdu_str = try_val_to_str(r_tpdu_tag, dvbci_r_tpdu);
pi = proto_tree_add_item(tree, hf_dvbci_r_tpdu_tag, tvb, 0, 1, ENC_BIG_ENDIAN);
if (r_tpdu_str) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s", r_tpdu_str);
}
else {
if (r_tpdu_tag == T_SB) {
if (hdr_tag)
*hdr_tag = NO_TAG;
if (body_len)
*body_len = 0;
return 0;
}
else {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL,
"Invalid Response-TPDU tag");
expert_add_info(pinfo, pi, &ei_dvbci_r_tpdu_tag);
return -1;
}
}
}
offset = dissect_ber_length(pinfo, tree, tvb, 1, &len_field, NULL);
if (len_field==0 ||
((direction==DATA_HOST_TO_CAM) && ((offset+len_field)!=tpdu_len)) ||
((direction==DATA_CAM_TO_HOST) && ((offset+len_field)>tpdu_len))) {
proto_tree_add_expert_format(tree, pinfo, &ei_dvbci_bad_length, tvb, 1, offset-1,
len_field==0 ? "Invalid length field, length field must be at least 1" :
"Invalid length field, length field mismatch");
return -1;
}
t_c_id = tvb_get_guint8(tvb, offset);
pi = proto_tree_add_item(tree, hf_dvbci_t_c_id, tvb, offset, 1, ENC_BIG_ENDIAN);
if (t_c_id!=lpdu_tcid) {
if (tag && (*tag==T_RCV || *tag==T_DATA_MORE || *tag==T_DATA_LAST)) {
expert_add_info_format(pinfo, pi, &ei_dvbci_t_c_id, "Transport Connection ID mismatch, tcid is %d in the transport layer and %d in the link layer",
t_c_id, lpdu_tcid);
}
}
else {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "tcid %d", t_c_id);
}
offset++;
if (hdr_tag && tag)
*hdr_tag = *tag;
if (body_len)
*body_len = len_field-1;
return offset;
}
static void
dissect_dvbci_tpdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 direction, guint8 lpdu_tcid)
{
guint32 tpdu_len, body_len;
proto_item *ti = NULL;
proto_tree *trans_tree = NULL;
gint offset, status_len;
guint8 hdr_tag = NO_TAG;
tvbuff_t *body_tvb, *payload_tvb = NULL;
fragment_head *frag_msg = NULL;
tpdu_len = tvb_reported_length(tvb);
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_text(tree, tvb, 0, -1, "Transport Layer");
trans_tree = proto_item_add_subtree(ti, ett_dvbci_transport);
offset = dissect_dvbci_tpdu_hdr(tvb, pinfo, trans_tree, direction,
lpdu_tcid, tpdu_len, &hdr_tag, &body_len);
if (offset==-1)
return;
proto_item_set_len(ti, offset);
if ((offset>0) && (body_len!=0)) {
body_tvb = tvb_new_subset(tvb, offset, body_len, body_len);
frag_msg = fragment_add_seq_next(&spdu_reassembly_table,
body_tvb, 0, pinfo, SPDU_SEQ_ID_BASE+lpdu_tcid, NULL,
body_len,
hdr_tag == T_DATA_MORE ? 1 : 0);
payload_tvb = process_reassembled_data(body_tvb, 0, pinfo,
"Reassembled SPDU", frag_msg, &spdu_frag_items,
NULL, trans_tree);
if (!payload_tvb) {
if (hdr_tag == T_DATA_MORE) {
pinfo->fragmented = TRUE;
col_append_fstr(pinfo->cinfo, COL_INFO, " (Message fragment)");
} else {
payload_tvb = body_tvb;
}
}
offset += body_len;
}
if (direction==DATA_CAM_TO_HOST) {
if (tpdu_len-offset < 4) {
proto_tree_add_expert(trans_tree, pinfo, &ei_dvbci_r_tpdu_status_mandatory, tvb, 0, 0);
return;
}
status_len = dissect_dvbci_tpdu_status(
tvb, offset, pinfo, trans_tree, lpdu_tcid, hdr_tag);
if (status_len<0)
return;
proto_tree_set_appendix(trans_tree, tvb, offset, status_len);
}
if (payload_tvb)
dissect_dvbci_spdu(payload_tvb, pinfo, tree, direction, lpdu_tcid);
}
static void
dissect_dvbci_lpdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 direction)
{
proto_item *ti;
proto_tree *link_tree = NULL;
guint32 payload_len;
guint8 tcid, more_last;
proto_item *pi;
tvbuff_t *payload_tvb = NULL;
fragment_head *frag_msg = NULL;
payload_len = tvb_reported_length(tvb);
col_add_str(pinfo->cinfo, COL_INFO, "LPDU");
ti = proto_tree_add_text(tree, tvb, 0, 2, "Link Layer");
link_tree = proto_item_add_subtree(ti, ett_dvbci_link);
tcid = tvb_get_guint8(tvb, 0);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ", "tcid %d", tcid);
proto_tree_add_item(link_tree, hf_dvbci_tcid, tvb, 0, 1, ENC_BIG_ENDIAN);
more_last = tvb_get_guint8(tvb, 1);
pi = proto_tree_add_item(link_tree, hf_dvbci_ml, tvb, 1, 1, ENC_BIG_ENDIAN);
if (try_val_to_str(more_last, dvbci_ml) == NULL) {
expert_add_info(pinfo, pi, &ei_dvbci_ml);
}
if (buf_size_host!=0 && payload_len>buf_size_host) {
proto_tree_add_expert_format(link_tree, pinfo, &ei_dvbci_bad_length, tvb, 2, payload_len,
"Payload too large, maximum payload length is the negotiated buffer size (%d bytes)", buf_size_host);
}
frag_msg = fragment_add_seq_next(&tpdu_reassembly_table,
tvb, 2, pinfo, TPDU_SEQ_ID_BASE+tcid, NULL,
tvb_reported_length_remaining(tvb, 2),
more_last == ML_MORE ? 1 : 0);
payload_tvb = process_reassembled_data(tvb, 2, pinfo,
"Reassembled TPDU", frag_msg, &tpdu_frag_items,
NULL, link_tree);
if (!payload_tvb) {
if (more_last == ML_MORE) {
pinfo->fragmented = TRUE;
col_append_fstr(pinfo->cinfo, COL_INFO, " (Message fragment)");
} else
payload_tvb = tvb_new_subset_remaining(tvb, 2);
}
if (payload_tvb)
dissect_dvbci_tpdu(payload_tvb, pinfo, tree, direction, tcid);
}
static void
dissect_dvbci_buf_neg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 direction)
{
guint16 buf_size;
proto_item *pi;
buf_size = tvb_get_ntohs(tvb, 0);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %u bytes",
direction == DATA_HOST_TO_CAM ?
"negotiated buffer size" : "buffer size proposal",
buf_size);
if (direction == DATA_HOST_TO_CAM) {
buf_size_host = buf_size;
pi = proto_tree_add_uint_format(tree, hf_dvbci_buf_size, tvb,
0, 2, buf_size,
"Negotiated buffer size: %u bytes", buf_size);
if (buf_size_host > buf_size_cam) {
expert_add_info_format(pinfo, pi, &ei_dvbci_buf_size, "Illegal buffer size command. Host shall not request a buffer size larger than the CAM proposal");
}
}
else if (direction == DATA_CAM_TO_HOST) {
buf_size_cam = buf_size;
proto_tree_add_uint_format(tree, hf_dvbci_buf_size, tvb,
0, 2, buf_size,
"Buffer size proposal by the CAM: %u bytes", buf_size);
}
if (buf_size < 16) {
proto_tree_add_expert_format(tree, pinfo, &ei_dvbci_buf_size, tvb, 0, 2,
"Illegal buffer size, minimum buffer size is 16 bytes");
}
}
static gint
dissect_dvbci_cis_payload_tpll_v1(tvbuff_t *data_tvb,
packet_info *pinfo _U_, proto_tree *tree)
{
gint offset=0, offset_str_end;
proto_tree_add_item(tree, hf_dvbci_cis_tpll_v1_major,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dvbci_cis_tpll_v1_minor,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
offset_str_end = tvb_find_guint8(data_tvb, offset, -1, 0x0);
if (offset_str_end<offset)
return offset;
proto_tree_add_item(tree, hf_dvbci_cis_tpll_v1_info_manuf,
data_tvb, offset, offset_str_end-offset, ENC_ASCII|ENC_NA);
offset = offset_str_end+1;
offset_str_end = tvb_find_guint8(data_tvb, offset, -1, 0x0);
if (offset_str_end<offset)
return offset;
proto_tree_add_item(tree, hf_dvbci_cis_tpll_v1_info_name,
data_tvb, offset, offset_str_end-offset, ENC_ASCII|ENC_NA);
offset = offset_str_end+1;
while (tvb_reported_length_remaining(data_tvb, offset)>1) {
offset_str_end = tvb_find_guint8(data_tvb, offset, -1, 0x0);
if (offset_str_end<offset)
break;
proto_tree_add_item(tree, hf_dvbci_cis_tpll_v1_info_additional,
data_tvb, offset, offset_str_end-offset, ENC_ASCII|ENC_NA);
offset = offset_str_end+1;
}
proto_tree_add_item(tree, hf_dvbci_cis_tpll_v1_end,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static gint
dissect_dvbci_cis_payload_config(tvbuff_t *data_tvb,
packet_info *pinfo _U_, proto_tree *tree)
{
gint offset = 0;
guint8 rfsz, rmsz, rasz;
guint8 st_code, st_len;
const gchar *st_code_str;
proto_item *st_item = NULL;
proto_tree *st_tree = NULL;
guint8 stci_ifn_size;
rfsz = (tvb_get_guint8(data_tvb, offset)&0xC0) >> 6;
proto_tree_add_item(tree, hf_dvbci_cis_tpcc_rfsz,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
rmsz = ((tvb_get_guint8(data_tvb, offset)&0x3C) >> 2) + 1;
proto_tree_add_item(tree, hf_dvbci_cis_tpcc_rmsz,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
rasz = (tvb_get_guint8(data_tvb, offset)&0x03) + 1;
proto_tree_add_item(tree, hf_dvbci_cis_tpcc_rasz,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dvbci_cis_tpcc_last,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dvbci_cis_tpcc_radr,
data_tvb, offset, rasz, ENC_LITTLE_ENDIAN);
offset += rasz;
proto_tree_add_item(tree, hf_dvbci_cis_tpcc_rmsk,
data_tvb, offset, rmsz, ENC_NA);
offset += rmsz;
offset += rfsz;
while (tvb_reported_length_remaining(data_tvb, offset) > 0) {
st_code = tvb_get_guint8(data_tvb, offset);
st_code_str = val_to_str_const(st_code, dvbci_cis_subtpl_code, "unknown");
st_item = proto_tree_add_text(tree, data_tvb, offset, -1,
"Subtuple: %s (0x%x)", st_code_str, st_code);
st_tree = proto_item_add_subtree(st_item, ett_dvbci_cis_subtpl);
proto_tree_add_item(st_tree, hf_dvbci_cis_st_code,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
st_len = tvb_get_guint8(data_tvb, offset);
proto_item_set_len(st_item, 2+st_len);
proto_tree_add_item(st_tree, hf_dvbci_cis_st_len,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (st_code == CCSTPL_CIF) {
stci_ifn_size = ((tvb_get_guint8(data_tvb, offset) & 0xC0)>>6)+1;
proto_tree_add_item(st_tree, hf_dvbci_cis_stci_ifn_size,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(st_tree, hf_dvbci_cis_stci_ifn,
data_tvb, offset, stci_ifn_size, ENC_LITTLE_ENDIAN);
offset += stci_ifn_size;
proto_tree_add_item(st_tree, hf_dvbci_cis_stci_str,
data_tvb, offset, st_len-stci_ifn_size, ENC_ASCII|ENC_NA);
offset += st_len-stci_ifn_size;
}
else {
offset += st_len;
}
}
return offset;
}
static gint
dissect_dvbci_cis_payload_cftable_entry(tvbuff_t *data_tvb,
packet_info *pinfo _U_, proto_tree *tree)
{
gint offset = 0;
gboolean intface_flag;
intface_flag = ((tvb_get_guint8(data_tvb, offset) & 0x80) == 0x80);
proto_tree_add_item(tree, hf_dvbci_cis_tpce_indx_intface,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_cis_tpce_indx_default,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_cis_tpce_indx_cnf_entry,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (intface_flag) {
proto_tree_add_item(tree, hf_dvbci_cis_tpce_if_type,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
}
proto_tree_add_item(tree, hf_dvbci_cis_tpce_fs_mem_space,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_cis_tpce_fs_irq,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_dvbci_cis_tpce_fs_io,
data_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static void
dissect_dvbci_cis(tvbuff_t *tvb, gint offset,
packet_info *pinfo, proto_tree *tree)
{
gint offset_start;
proto_tree *cis_tree = NULL, *tpl_tree = NULL;
proto_item *ti_main = NULL, *ti_tpl;
guint8 tpl_code;
const gchar *tpl_code_str = NULL;
guint8 len_field;
tvbuff_t *tpl_data_tvb;
offset_start = offset;
ti_main = proto_tree_add_text(tree, tvb, offset, -1,
"Card Information Structure (CIS)");
cis_tree = proto_item_add_subtree(ti_main, ett_dvbci_cis);
do {
tpl_code = tvb_get_guint8(tvb, offset);
tpl_code_str = val_to_str_const(tpl_code, dvbci_cis_tpl_code, "unknown");
ti_tpl = proto_tree_add_text(cis_tree,
tvb, offset, -1, "CIS tuple: %s", tpl_code_str);
tpl_tree = proto_item_add_subtree(ti_tpl, ett_dvbci_cis_tpl);
proto_tree_add_uint_format(tpl_tree, hf_dvbci_cis_tpl_code,
tvb, offset, 1, tpl_code, "Tuple code: %s (0x%x)",
tpl_code_str, tpl_code);
offset++;
if (tpl_code == CISTPL_END) {
proto_item_set_len(ti_tpl, 1);
break;
}
len_field = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tpl_tree, hf_dvbci_cis_tpl_len,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
tpl_data_tvb = tvb_new_subset(tvb, offset, len_field, len_field);
switch (tpl_code) {
case CISTPL_VERS_1:
dissect_dvbci_cis_payload_tpll_v1(
tpl_data_tvb, pinfo, tpl_tree);
offset += len_field;
break;
case CISTPL_CONFIG:
dissect_dvbci_cis_payload_config(tpl_data_tvb, pinfo, tpl_tree);
offset += len_field;
break;
case CISTPL_CFTABLE_ENTRY:
dissect_dvbci_cis_payload_cftable_entry(
tpl_data_tvb, pinfo, tpl_tree);
offset += len_field;
break;
case CISTPL_MANFID:
proto_tree_add_item(tpl_tree, hf_dvbci_cis_tplmid_manf,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tpl_tree, hf_dvbci_cis_tplmid_card,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
default:
if (len_field>0) {
proto_tree_add_item(tpl_tree, hf_dvbci_cis_tpl_data,
tvb, offset, len_field, ENC_NA);
}
offset += len_field;
break;
}
proto_item_set_len(ti_tpl, 2+len_field);
} while (tvb_reported_length_remaining(tvb, offset) > 0);
proto_item_set_len(ti_main, offset-offset_start);
}
static int
dissect_dvbci(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint packet_len, offset = 0, offset_ver, offset_evt, offset_len_field;
guint8 version, event;
const gchar *event_str;
guint16 len_field;
proto_item *ti, *ti_hdr;
proto_tree *dvbci_tree = NULL, *hdr_tree = NULL;
tvbuff_t *payload_tvb;
guint16 cor_addr;
guint8 cor_value;
proto_item *pi;
guint8 hw_event;
if (tvb_length(tvb) < 4)
return 0;
offset_ver = offset;
version = tvb_get_guint8(tvb, offset++);
if (version != 0)
return 0;
offset_evt = offset;
event = tvb_get_guint8(tvb, offset++);
event_str = try_val_to_str(event, dvbci_event);
if (!event_str)
return 0;
packet_len = tvb_reported_length(tvb);
offset_len_field = offset;
len_field = tvb_get_ntohs(tvb, offset);
if (len_field != (packet_len-4))
return 0;
offset += 2;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DVB-CI");
col_set_str(pinfo->cinfo, COL_INFO, event_str);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_dvbci,
tvb, 0, packet_len, "DVB Common Interface: %s", event_str);
dvbci_tree = proto_item_add_subtree(ti, ett_dvbci);
ti_hdr = proto_tree_add_text(dvbci_tree, tvb, 0, offset, "Pseudo header");
hdr_tree = proto_item_add_subtree(ti_hdr, ett_dvbci_hdr);
proto_tree_add_text(hdr_tree, tvb, offset_ver, 1, "Version: %d", version);
proto_tree_add_item(hdr_tree, hf_dvbci_event, tvb, offset_evt, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(hdr_tree, tvb, offset_len_field, 2,
"Length field: %d", len_field);
}
if (IS_DATA_TRANSFER(event)) {
dvbci_set_addrs(event, pinfo);
payload_tvb = tvb_new_subset_remaining( tvb, offset);
if (len_field == 2) {
dissect_dvbci_buf_neg(payload_tvb, pinfo, dvbci_tree, event);
}
else {
dissect_dvbci_lpdu(payload_tvb, pinfo, dvbci_tree, event);
}
}
else if (event==DVBCI_EVT_COR_WRITE) {
pi = proto_tree_add_item(dvbci_tree, hf_dvbci_cor_addr,
tvb, offset, 2, ENC_BIG_ENDIAN);
cor_addr = tvb_get_ntohs(tvb, offset);
if (cor_addr == 0xFFFF) {
proto_item_append_text(pi, " (COR address is unknown)");
col_append_sep_str(pinfo->cinfo, COL_INFO, ": ", "unknown address");
}
else if (cor_addr > 0xFFE) {
expert_add_info(pinfo, pi, &ei_dvbci_cor_addr);
}
else {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ": ",
"address 0x%x", cor_addr);
}
offset += 2;
cor_value = tvb_get_guint8(tvb, offset);
proto_tree_add_item(dvbci_tree, hf_dvbci_cor_val,
tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL,
"value 0x%x", cor_value);
}
else if (event==DVBCI_EVT_CIS_READ) {
dissect_dvbci_cis(tvb, offset, pinfo, dvbci_tree);
}
else if (event==DVBCI_EVT_HW_EVT) {
hw_event = tvb_get_guint8(tvb, offset);
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_const(hw_event, dvbci_hw_event, "Invalid hardware event"));
proto_tree_add_item(dvbci_tree, hf_dvbci_hw_event,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
return packet_len;
}
void
proto_register_dvbci(void)
{
guint i;
module_t *dvbci_module;
expert_module_t* expert_dvbci;
static gint *ett[] = {
&ett_dvbci,
&ett_dvbci_hdr,
&ett_dvbci_cis,
&ett_dvbci_cis_tpl,
&ett_dvbci_cis_subtpl,
&ett_dvbci_link,
&ett_dvbci_link_frag,
&ett_dvbci_link_frags,
&ett_dvbci_transport,
&ett_dvbci_transport_frag,
&ett_dvbci_transport_frags,
&ett_dvbci_session,
&ett_dvbci_res,
&ett_dvbci_application,
&ett_dvbci_es,
&ett_dvbci_ca_desc,
&ett_dvbci_text,
&ett_dvbci_cc_item,
&ett_dvbci_sac_msg_body,
&ett_dvbci_ami_req_types,
&ett_dvbci_lsc_conn_desc,
&ett_dvbci_opp_cap_loop
};
static hf_register_info hf[] = {
{ &hf_dvbci_event,
{ "Event", "dvb-ci.event",
FT_UINT8, BASE_HEX, VALS(dvbci_event), 0, NULL, HFILL }
},
{ &hf_dvbci_hw_event,
{ "Hardware event", "dvb-ci.hw_event",
FT_UINT8, BASE_HEX, VALS(dvbci_hw_event), 0, NULL, HFILL }
},
{ &hf_dvbci_cor_addr,
{ "COR address", "dvb-ci.cor_address",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cor_val,
{ "COR value", "dvb-ci.cor_value",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cis_tpl_code,
{ "CIS tuple code", "dvb-ci.cis.tpl_code",
FT_UINT8, BASE_HEX, VALS(dvbci_cis_tpl_code), 0, NULL, HFILL }
},
{ &hf_dvbci_cis_tpl_len,
{ "Length field", "dvb-ci.cis.tpl_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cis_tpl_data,
{ "Tuple data", "dvb-ci.cis.tpl_data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cis_tpll_v1_major,
{ "Major version number", "dvb-ci.cis.tpll_v1_major",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cis_tpll_v1_minor,
{ "Minor version number", "dvb-ci.cis.tpll_v1_minor",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cis_tpll_v1_info_manuf,
{ "Manufacturer", "dvb-ci.cis.tpll_v1_info.manufacturer",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cis_tpll_v1_info_name,
{ "Name", "dvb-ci.cis.tpll_v1_info.name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cis_tpll_v1_info_additional,
{ "Additional info", "dvb-ci.cis.tpll_v1_info.additional",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cis_tpll_v1_end,
{ "End of chain", "dvb-ci.cis.tpll_v1_end",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cis_tpcc_rfsz,
{ "Size of reserved area", "dvb-ci.cis.tpcc_rfsz",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL }
},
{ &hf_dvbci_cis_tpcc_rmsz,
{ "Size of TPCC_RMSK field - 1", "dvb-ci.cis.tpcc_rmsz",
FT_UINT8, BASE_HEX, NULL, 0x3C, NULL, HFILL }
},
{ &hf_dvbci_cis_tpcc_rasz,
{ "Size of TPCC_RADR - 1", "dvb-ci.cis.tpcc_rasz",
FT_UINT8, BASE_HEX, NULL, 0x03, NULL, HFILL }
},
{ &hf_dvbci_cis_tpcc_last,
{ "Index of the last cftable entry", "dvb-ci.cis.tpcc_last",
FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL }
},
{ &hf_dvbci_cis_tpcc_radr,
{ "COR base address", "dvb-ci.cis.tpcc_radr",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cis_tpcc_rmsk,
{ "Configuration register presence mask", "dvb-ci.cis.tpcc_rmsk",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cis_st_code,
{ "Subtuple tag", "dvb-ci.cis.st_code",
FT_UINT8, BASE_HEX, VALS(dvbci_cis_subtpl_code), 0, NULL, HFILL }
},
{ &hf_dvbci_cis_st_len,
{ "Subtuple length", "dvb-ci.cis.st_len",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cis_stci_ifn_size,
{ "Size of interface ID number - 1", "dvb-ci.cis.stci_ifn_size",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL }
},
{ &hf_dvbci_cis_stci_ifn,
{ "Interface ID number", "dvb-ci.cis.stci_ifn",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cis_stci_str,
{ "Interface description strings", "dvb-ci.cis.stci_str",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cis_tpce_indx_intface,
{ "Intface", "dvb-ci.cis.tpce_indx.intface",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL }
},
{ &hf_dvbci_cis_tpce_indx_default,
{ "Default", "dvb-ci.cis.tpce_indx.default",
FT_UINT8, BASE_HEX, NULL, 0x40, NULL, HFILL }
},
{ &hf_dvbci_cis_tpce_indx_cnf_entry,
{ "Configuration entry number", "dvb-ci.cis.tpce_indx.cnf_entry",
FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL }
},
{ &hf_dvbci_cis_tpce_if_type,
{ "Interface type", "dvb-ci.cis.tpce_if.type", FT_UINT8, BASE_HEX,
VALS(dvbci_cis_tpce_if_type), 0x0F, NULL, HFILL }
},
{ &hf_dvbci_cis_tpce_fs_mem_space,
{ "Mem space", "dvb-ci.cis.tpce_fs.mem_space",
FT_UINT8, BASE_HEX, NULL, 0x60, NULL, HFILL }
},
{ &hf_dvbci_cis_tpce_fs_irq,
{ "IRQ", "dvb-ci.cis.tpce_fs.irq",
FT_UINT8, BASE_HEX, NULL, 0x10, NULL, HFILL }
},
{ &hf_dvbci_cis_tpce_fs_io,
{ "IO Space", "dvb-ci.cis.tpce_fs.io",
FT_UINT8, BASE_HEX, NULL, 0x08, NULL, HFILL }
},
{ &hf_dvbci_cis_tplmid_manf,
{ "PC Card manufacturer code", "dvb-ci.cis.tplmid_manf",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cis_tplmid_card,
{ "Manufacturer info", "dvb-ci.cis.tplmid_card",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_buf_size,
{ "Buffer Size", "dvb-ci.buf_size",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_tcid,
{ "Transport Connection ID", "dvb-ci.tcid",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_ml,
{ "More/Last indicator", "dvb-ci.more_last",
FT_UINT8, BASE_HEX, VALS(dvbci_ml), 0, NULL, HFILL }
},
{ &hf_dvbci_l_frags,
{ "Tpdu fragments", "dvb-ci.tpdu_fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_l_frag,
{ "Tpdu fragment", "dvb-ci.tpdu_fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_l_frag_overlap,
{ "Tpdu fragment overlap", "dvb-ci.tpdu_fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_l_frag_overlap_conflicts,
{ "Tpdu fragment overlapping with conflicting data",
"dvb-ci.tpdu_fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_l_frag_multiple_tails,
{ "Tpdu has multiple tail fragments",
"dvb-ci.tpdu_fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_l_frag_too_long_frag,
{ "Tpdu fragment too long", "dvb-ci.tpdu_fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_l_frag_err,
{ "Tpdu defragmentation error", "dvb-ci.tpdu_fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_l_frag_cnt,
{ "Tpdu fragment count", "dvb-ci.tpdu_fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_l_reass_in,
{ "Tpdu reassembled in", "dvb-ci.tpdu_reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_l_reass_len,
{ "Reassembled tpdu length", "dvb-ci.tpdu_reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_c_tpdu_tag,
{ "Command TPDU Tag", "dvb-ci.c_tpdu_tag",
FT_UINT8, BASE_HEX, VALS(dvbci_c_tpdu), 0, NULL, HFILL }
},
{ &hf_dvbci_r_tpdu_tag,
{ "Response TPDU Tag", "dvb-ci.r_tpdu_tag",
FT_UINT8, BASE_HEX, VALS(dvbci_r_tpdu), 0, NULL, HFILL }
},
{ &hf_dvbci_t_c_id,
{ "Transport Connection ID", "dvb-ci.t_c_id",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_sb_value,
{ "SB Value", "dvb-ci.sb_value", FT_UINT8, BASE_HEX,
VALS(dvbci_sb_value), 0, NULL, HFILL } },
{ &hf_dvbci_t_frags,
{ "Spdu fragments", "dvb-ci.spdu_fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_t_frag,
{ "Spdu fragment", "dvb-ci.spdu_fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_t_frag_overlap,
{ "Spdu fragment overlap", "dvb-ci.spdu_fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_t_frag_overlap_conflicts,
{ "Spdu fragment overlapping with conflicting data",
"dvb-ci.tpdu_fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_t_frag_multiple_tails,
{ "Spdu has multiple tail fragments",
"dvb-ci.spdu_fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_t_frag_too_long_frag,
{ "Spdu fragment too long", "dvb-ci.spdu_fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_t_frag_err,
{ "Spdu defragmentation error", "dvb-ci.spdu_fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_t_frag_cnt,
{ "Spdu fragment count", "dvb-ci.spdu_fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_t_reass_in,
{ "Spdu reassembled in", "dvb-ci.spdu_reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_t_reass_len,
{ "Reassembled spdu length", "dvb-ci.spdu_reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_dvbci_spdu_tag,
{ "SPDU Tag", "dvb-ci.spdu_tag",
FT_UINT8, BASE_HEX, VALS(dvbci_spdu_tag), 0, NULL, HFILL }
},
{ &hf_dvbci_sess_status,
{ "Session Status", "dvb-ci.session_status",
FT_UINT8, BASE_HEX, VALS(dvbci_sess_status), 0, NULL, HFILL }
},
{ &hf_dvbci_sess_nb,
{ "Session Number", "dvb-ci.session_nb",
FT_UINT16, BASE_DEC, NULL , 0, NULL, HFILL }
},
{ &hf_dvbci_close_sess_status,
{ "Session Status", "dvb-ci.close_session_status",
FT_UINT8, BASE_HEX, VALS(dvbci_close_sess_status), 0, NULL, HFILL }
},
{ &hf_dvbci_res_id_type,
{ "Resource ID Type", "dvb-ci.res.id_type",
FT_UINT32, BASE_HEX, NULL, RES_ID_TYPE_MASK, NULL, HFILL }
},
{ &hf_dvbci_res_class,
{ "Resource Class", "dvb-ci.res.class",
FT_UINT32, BASE_HEX, VALS(dvbci_res_class), RES_CLASS_MASK, NULL, HFILL }
},
{ &hf_dvbci_res_type,
{ "Resource Type", "dvb-ci.res.type",
FT_UINT32, BASE_HEX, NULL, RES_TYPE_MASK, NULL, HFILL }
},
{ &hf_dvbci_res_ver,
{ "Resource Version", "dvb-ci.res.version",
FT_UINT32, BASE_HEX, NULL, RES_VER_MASK, NULL, HFILL }
},
{ &hf_dvbci_apdu_tag,
{ "APDU Tag", "dvb-ci.apdu_tag",
FT_UINT24, BASE_HEX, VALS(dvbci_apdu_tag), 0, NULL, HFILL }
},
{ &hf_dvbci_app_type,
{ "Application type", "dvb-ci.ap.type",
FT_UINT8, BASE_HEX, VALS(dvbci_app_type), 0, NULL, HFILL }
},
{ &hf_dvbci_app_manf,
{ "Application manufacturer", "dvb-ci.ap.manufacturer",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_manf_code,
{ "Manufacturer code", "dvb-ci.ap.manufacturer_code",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_menu_str_len,
{ "Menu string length", "dvb-ci.ap.menu_string_length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_data_rate,
{ "Transport stream data rate supported by the host",
"dvb-ci.ap.data_rate",
FT_UINT8, BASE_HEX, VALS(dvbci_data_rate), 0, NULL, HFILL }
},
{ &hf_dvbci_ca_sys_id,
{ "CA system ID", "dvb-ci.ca.ca_system_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_ca_pmt_list_mgmt,
{ "CA PMT list management", "dvb-ci.ca.ca_pmt_list_management",
FT_UINT8, BASE_HEX, VALS(dvbci_ca_pmt_list_mgmt), 0, NULL,
HFILL }
},
{ &hf_dvbci_prog_num,
{ "Program number", "dvb-ci.ca.program_number",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_prog_info_len,
{ "Program info length", "dvb-ci.ca.program_info_length",
FT_UINT16, BASE_HEX, NULL, 0x0FFF, NULL, HFILL }
},
{ &hf_dvbci_stream_type,
{ "Stream type", "dvb-ci.ca.stream_type",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_es_pid,
{ "Elementary stream PID", "dvb-ci.ca.elementary_pid",
FT_UINT16, BASE_HEX, NULL, 0x1FFF, NULL, HFILL }
},
{ &hf_dvbci_es_info_len,
{ "Elementary stream info length", "dvb-ci.ca.es_info_length",
FT_UINT16, BASE_HEX, NULL, 0x0FFF, NULL, HFILL }
},
{ &hf_dvbci_ca_pmt_cmd_id,
{ "CA PMT command ID", "dvb-ci.ca.ca_pmt_cmd_id",
FT_UINT8, BASE_HEX, VALS(dvbci_ca_pmt_cmd_id), 0, NULL, HFILL }
},
{ &hf_dvbci_descr_len,
{ "CA descriptor length", "dvb-ci.ca.ca_desc_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_ca_pid,
{ "CA PID", "dvb-ci.ca.ca_pid",
FT_UINT16, BASE_HEX, NULL, 0x1FFF, NULL, HFILL }
},
{ &hf_dvbci_ca_enable_flag,
{ "CA enable flag", "dvb-ci.ca.ca_enable_flag",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL }
},
{ &hf_dvbci_ca_enable,
{ "CA enable", "dvb-ci.ca.ca_enable",
FT_UINT8, BASE_HEX, VALS(dvbci_ca_enable), 0x7F, NULL, HFILL }
},
{ &hf_dvbci_auth_proto_id,
{ "Authentication protocol ID", "dvb-ci.aut.proto_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_auth_req_bytes,
{ "Authentication request data", "dvb-ci.aut.req",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_auth_resp_bytes,
{ "Authentication response data", "dvb-ci.aut.resp",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_network_id,
{ "Network ID", "dvb-ci.hc.nid",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_original_network_id,
{ "Original network ID", "dvb-ci.hc.onid",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_transport_stream_id,
{ "Transport stream ID", "dvb-ci.hc.tsid",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_service_id,
{ "Service ID", "dvb-ci.hc.svcid",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_replacement_ref,
{ "Replacement reference", "dvb-ci.hc.replacement_ref",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_replaced_pid,
{ "Replaced PID", "dvb-ci.hc.replaced_pid",
FT_UINT16, BASE_HEX, NULL, 0x1FFF, NULL, HFILL }
},
{ &hf_dvbci_replacement_pid,
{ "Replacement PID", "dvb-ci.hc.replacement_pid",
FT_UINT16, BASE_HEX, NULL, 0x1FFF, NULL, HFILL }
},
{ &hf_dvbci_pmt_flag,
{ "PMT flag", "dvb-ci.hc.pmt_flag",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL }
},
{ &hf_dvbci_hc_desc_loop_len,
{ "Descriptor loop length", "dvb-ci.hc.desc_loop_len",
FT_UINT16, BASE_DEC, NULL, 0x0FFF, NULL, HFILL }
},
{ &hf_dvbci_hc_status,
{ "Status field", "dvb-ci.hc.status_field",
FT_UINT8, BASE_HEX, VALS(dvbci_hc_status), 0, NULL, HFILL }
},
{ &hf_dvbci_hc_release_reply,
{ "Release reply", "dvb-ci.hc.release_reply",
FT_UINT8, BASE_HEX, VALS(dvbci_hc_release_reply), 0, NULL, HFILL }
},
{ &hf_dvbci_resp_intv,
{ "Response interval", "dvb-ci.dt.resp_interval",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_utc_time,
{ "UTC time", "dvb-ci.dt.utc_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_local_offset,
{ "Local time offset", "dvb-ci.dt.local_offset",
FT_INT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_close_mmi_cmd_id,
{ "Command ID", "dvb-ci.mmi.close_mmi_cmd_id",
FT_UINT8, BASE_HEX, VALS(dvbci_close_mmi_cmd_id), 0, NULL, HFILL }
},
{ &hf_dvbci_close_mmi_delay,
{ "Delay (in sec)", "dvb-ci.mmi.delay",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_disp_ctl_cmd,
{ "Command", "dvb-ci.mmi.disp_ctl_cmd",
FT_UINT8, BASE_HEX, VALS(dvbci_disp_ctl_cmd), 0, NULL, HFILL }
},
{ &hf_dvbci_mmi_mode,
{ "MMI mode", "dvb-ci.mmi.mode",
FT_UINT8, BASE_HEX, VALS(dvbci_mmi_mode), 0, NULL, HFILL }
},
{ &hf_dvbci_disp_rep_id,
{ "Reply ID", "dvb-ci.mmi.disp_rep_id",
FT_UINT8, BASE_HEX, VALS(dvbci_disp_rep_id), 0, NULL, HFILL }
},
{ &hf_dvbci_char_tbl,
{ "Character table", "dvb-ci.mmi.char_tbl",
FT_UINT8, BASE_HEX, VALS(dvbci_char_tbl), 0, NULL, HFILL }
},
{ &hf_dvbci_blind_ans,
{ "Blind answer flag", "dvb-ci.mmi.blind_ans",
FT_UINT8, BASE_HEX, VALS(dvbci_blind_ans), 0x01, NULL, HFILL }
},
{ &hf_dvbci_ans_txt_len,
{ "Answer text length", "dvb-ci.mmi.ans_txt_len",
FT_UINT8, BASE_DEC, NULL , 0, NULL, HFILL }
},
{ &hf_dvbci_text_ctrl,
{ "Text control code", "dvb-ci.mmi.text_ctrl",
FT_UINT8, BASE_HEX, VALS(dvbci_text_ctrl), 0, NULL, HFILL }
},
{ &hf_dvbci_ans_id,
{ "Answer ID", "dvb-ci.mmi.ans_id",
FT_UINT8, BASE_HEX, VALS(dvbci_ans_id) , 0, NULL, HFILL }
},
{ &hf_dvbci_choice_nb,
{ "Number of menu items", "dvb-ci.mmi.choice_nb",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_choice_ref,
{ "Selected item", "dvb-ci.mmi.choice_ref",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_item_nb,
{ "Number of list items", "dvb-ci.mmi.item_nb",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_host_country,
{ "Host country", "dvb-ci.hlc.country",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_host_language,
{ "Host language", "dvb-ci.hlc.language",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cup_type,
{ "CAM upgrade type", "dvb-ci.cup.type",
FT_UINT8, BASE_HEX, VALS(dvbci_cup_type), 0, NULL, HFILL }
},
{ &hf_dvbci_cup_download_time,
{ "Download time", "dvb-ci.cup.download_time",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cup_answer,
{ "CAM upgrade answer", "dvb-ci.cup.answer",
FT_UINT8, BASE_HEX, VALS(dvbci_cup_answer), 0, NULL, HFILL }
},
{ &hf_dvbci_cup_progress,
{ "CAM upgrade progress", "dvb-ci.cup.progress",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cup_reset,
{ "requested CAM reset", "dvb-ci.cup.reset",
FT_UINT8, BASE_HEX, VALS(dvbci_cup_reset), 0, NULL, HFILL }
},
{ &hf_dvbci_cc_sys_id_bitmask,
{ "CC system id bitmask", "dvb-ci.cc.sys_id_bitmask",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cc_dat_id,
{ "CC datatype id", "dvb-ci.cc.datatype_id",
FT_UINT8, BASE_HEX, VALS(dvbci_cc_dat_id), 0, NULL, HFILL }
},
{ &hf_dvbci_brand_cert,
{ "Brand certificate", "dvb-ci.cc.brand_cert",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_dvbci_dev_cert,
{ "Device certificate", "dvb-ci.cc.dev_cert",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_dvbci_uri_ver,
{ "URI version", "dvb-ci.cc.uri.version",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_uri_aps,
{ "APS", "dvb-ci.cc.uri.aps",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL }
},
{ &hf_dvbci_uri_emi,
{ "EMI", "dvb-ci.cc.uri.emi",
FT_UINT8, BASE_HEX, NULL, 0x30, NULL, HFILL }
},
{ &hf_dvbci_uri_ict,
{ "Image constraint token", "dvb-ci.cc.uri.ict",
FT_UINT8, BASE_HEX, NULL, 0x08, NULL, HFILL }
},
{ &hf_dvbci_uri_rct,
{ "Redistribution control trigger (RCT)", "dvb-ci.cc.uri.ict",
FT_UINT8, BASE_HEX, NULL, 0x04, NULL, HFILL }
},
{ &hf_dvbci_cc_key_register,
{ "Key register", "dvb-ci.cc.key_register",
FT_UINT8, BASE_HEX, VALS(dvbci_cc_key_register), 0, NULL, HFILL }
},
{ &hf_dvbci_cc_status_field,
{ "Status field", "dvb-ci.cc.status_field",
FT_UINT8, BASE_HEX, VALS(dvbci_cc_status), 0, NULL, HFILL }
},
{ &hf_dvbci_cc_op_mode,
{ "Operating mode", "dvb-ci.cc.op_mode",
FT_UINT8, BASE_HEX, VALS(dvbci_cc_op_mode), 0, NULL, HFILL }
},
{ &hf_dvbci_cc_data,
{ "Data", "dvb-ci.cc.data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_sac_msg_ctr,
{ "Message counter", "dvb-ci.cc.sac.msg_ctr",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_sac_proto_ver,
{ "Protocol version", "dvb-ci.cc.sac.proto_ver",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL }
},
{ &hf_dvbci_sac_auth_cip,
{ "Authentication cipher", "dvb-ci.cc.sac.auth_cip",
FT_UINT8, BASE_HEX, VALS(dvbci_cc_sac_auth), 0x0E, NULL, HFILL }
},
{ &hf_dvbci_sac_payload_enc,
{ "Payload encryption flag", "dvb-ci.cc.sac.payload_enc",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL }
},
{ &hf_dvbci_sac_enc_cip,
{ "Encryption cipher", "dvb-ci.cc.sac.enc_cip",
FT_UINT8, BASE_HEX, VALS(dvbci_cc_sac_enc), 0xE0, NULL, HFILL }
},
{ &hf_dvbci_sac_payload_len,
{ "Payload length", "dvb-ci.cc.sac.payload_len",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_sac_enc_body,
{ "Encrypted SAC body", "dvb-ci.cc.sac.enc_body",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_sac_signature,
{ "Signature", "dvb-ci.cc.sac.signature",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_rating,
{ "Rating", "dvb-ci.cc.rating",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_capability_field,
{ "Capability field", "dvb-ci.cc.capability_field",
FT_UINT8, BASE_HEX, VALS(dvbci_cc_cap), 0, NULL, HFILL }
},
{ &hf_dvbci_pin_chg_time,
{ "PIN change time (UTC)", "dvb-ci.cc.pin_change_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_pincode_status,
{ "Pincode status field", "dvb-ci.cc.pincode_status_field",
FT_UINT8, BASE_HEX, VALS(dvbci_pincode_status), 0, NULL, HFILL }
},
{ &hf_dvbci_cc_prog_num,
{ "Program number", "dvb-ci.cc.program_number",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_pin_evt_time,
{ "PIN event time (UTC)", "dvb-ci.cc.pin_event_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_pin_evt_cent,
{ "PIN event time centiseconds", "dvb-ci.cc.pin_event_time_centi",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cc_priv_data,
{ "Private data", "dvb-ci.cc.private_data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_pincode,
{ "PIN code", "dvb-ci.cc.pincode",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_app_dom_id,
{ "Application Domain Identifier", "dvb-ci.ami.app_dom_id",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_init_obj,
{ "Initial Object", "dvb-ci.ami.init_obj",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_ack_code,
{ "Acknowledgement", "dvb-ci.ami.ack_code",
FT_UINT8, BASE_HEX, VALS(dvbci_ack_code), 0, NULL, HFILL }
},
{ &hf_dvbci_req_type,
{ "Request type", "dvb-ci.ami.req_type",
FT_UINT8, BASE_HEX, VALS(dvbci_req_type), 0, NULL, HFILL }
},
{ &hf_dvbci_file_hash,
{ "File hash", "dvb-ci.ami.file_hash",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_file_name,
{ "File name", "dvb-ci.ami.file_name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_ami_priv_data,
{ "Private data", "dvb-ci.ami.private_data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_req_ok,
{ "RequestOK", "dvb-ci.ami.request_ok",
FT_UINT8, BASE_HEX, NULL, 0x02, NULL, HFILL }
},
{ &hf_dvbci_file_ok,
{ "FileOK", "dvb-ci.ami.file_ok",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL }
},
{ &hf_dvbci_file_data,
{ "File data", "dvb-ci.ami.file_data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_abort_req_code,
{ "Abort request code", "dvb-ci.ami.abort_req_code",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_abort_ack_code,
{ "Abort acknowledgement code", "dvb-ci.ami.abort_ack_code",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_phase_id,
{ "Phase ID", "dvb-ci.lsc.comms_phase_id",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_comms_rep_id,
{ "Comms reply ID", "dvb-ci.lsc.comms_reply_id",
FT_UINT8, BASE_HEX, VALS(dvbci_comms_rep_id), 0, NULL, HFILL }
},
{ &hf_dvbci_lsc_buf_size,
{ "Buffer size", "dvb-ci.lsc.buf_size",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_lsc_ret_val,
{ "Return value", "dvb-ci.lsc.return_value",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_comms_cmd_id,
{ "Comms command ID", "dvb-ci.lsc.comms_cmd_id",
FT_UINT8, BASE_HEX, VALS(dvbci_comms_cmd_id), 0, NULL, HFILL }
},
{ &hf_dvbci_conn_desc_type,
{ "Type", "dvb-ci.lsc.conn_desc_type",
FT_UINT8, BASE_HEX, VALS(dvbci_conn_desc_type), 0, NULL, HFILL }
},
{ &hf_dvbci_lsc_media_tag,
{ "Tag", "dvb-ci.lsc.media_tag",
FT_UINT8, BASE_HEX, VALS(dvbci_lsc_desc_tag), 0, NULL, HFILL }
},
{ &hf_dvbci_lsc_media_len,
{ "Length", "dvb-ci.lsc.media_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_lsc_ip_ver,
{ "IP version", "dvb-ci.lsc.ip_version",
FT_UINT8, BASE_DEC, VALS(dvbci_lsc_ip_ver), 0, NULL, HFILL }
},
{ &hf_dvbci_lsc_ipv4_addr,
{ "IP address", "dvb-ci.lsc.ipv4_addr",
FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_lsc_ipv6_addr,
{ "IPv6 address", "dvb-ci.lsc.ipv6_addr",
FT_IPv6, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_lsc_dst_port,
{ "Destination port", "dvb-ci.lsc.dst_port",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_lsc_proto,
{ "Protocol", "dvb-ci.lsc.protocol",
FT_UINT8, BASE_HEX, VALS(dvbci_lsc_proto), 0, NULL, HFILL }
},
{ &hf_dvbci_lsc_hostname,
{ "Hostname", "dvb-ci.lsc.hostname",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_lsc_retry_count,
{ "Retry count", "dvb-ci.lsc.retry_count",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_lsc_timeout,
{ "Timeout", "dvb-ci.lsc.timeout",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_info_ver_op_status,
{ "Info version", "dvb-ci.opp.info_ver",
FT_UINT8, BASE_HEX, NULL, 0xE0, NULL, HFILL }
},
{ &hf_dvbci_nit_ver,
{ "NIT version", "dvb-ci.opp.nit_ver",
FT_UINT8, BASE_HEX, NULL, 0x1F, NULL, HFILL }
},
{ &hf_dvbci_pro_typ,
{ "Profile type", "dvb-ci.opp.profile_type",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL }
},
{ &hf_dvbci_init_flag,
{ "Initialized flag", "dvb-ci.opp.init_flag",
FT_UINT8, BASE_HEX, NULL, 0x20, NULL, HFILL }
},
{ &hf_dvbci_ent_chg_flag,
{ "Entitlement change flag", "dvb-ci.opp.ent_chg_flag",
FT_UINT8, BASE_HEX, NULL, 0x10, NULL, HFILL }
},
{ &hf_dvbci_ent_val_flag,
{ "Entitlement valid flag", "dvb-ci.opp.ent_val_flag",
FT_UINT8, BASE_HEX, NULL, 0x08, NULL, HFILL }
},
{ &hf_dvbci_ref_req_flag,
{ "Refresh request flag", "dvb-ci.opp.refresh_req_flag",
FT_UINT8, BASE_HEX, NULL, 0x03, NULL, HFILL }
},
{ &hf_dvbci_err_flag,
{ "Error flag", "dvb-ci.opp.err_flag",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL }
},
{ &hf_dvbci_dlv_sys_hint,
{ "Delivery system hint", "dvb-ci.opp.dlv_sys_hint",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL }
},
{ &hf_dvbci_refr_req_date,
{ "Refresh request date", "dvb-ci.opp.refresh_req_date",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_refr_req_time,
{ "Refresh request time", "dvb-ci.opp.refresh_req_time",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_nit_loop_len,
{ "NIT loop length", "dvb-ci.opp.nit_loop_len",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_info_valid,
{ "Info valid", "dvb-ci.opp.info_valid",
FT_UINT8, BASE_HEX, NULL, 0x08, NULL, HFILL }
},
{ &hf_dvbci_info_ver_op_info,
{ "Info version", "dvb-ci.opp.info_ver",
FT_UINT8, BASE_HEX, NULL, 0x07, NULL, HFILL }
},
{ &hf_dvbci_cicam_onid,
{ "CICAM original network id", "dvb-ci.opp.cicam_onid",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_cicam_id,
{ "CICAM ID", "dvb-ci.opp.cicam_id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_opp_char_tbl_multi,
{ "Multi-byte character table", "dvb-ci.opp.char_tbl_multi",
FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_opp_char_tbl,
{ "Character code table", "dvb-ci.opp.char_tbl",
FT_UINT8, BASE_HEX, VALS(dvbci_char_tbl), 0, NULL, HFILL }
},
{ &hf_dvbci_enc_type_id,
{ "Encoding type ID", "dvb-ci.opp.enc_type_id",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_sdt_rst_trusted,
{ "SDT running status trusted", "dvb-ci.opp.sdt_rst_trusted",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL }
},
{ &hf_dvbci_eit_rst_trusted,
{ "EIT running status trusted", "dvb-ci.opp.eit_rst_trusted",
FT_UINT8, BASE_HEX, NULL, 0x40, NULL, HFILL }
},
{ &hf_dvbci_eit_pf_usage,
{ "EIT present/following usage", "dvb-ci.opp.eit_pf_usage",
FT_UINT8, BASE_HEX, NULL, 0x30, NULL, HFILL }
},
{ &hf_dvbci_eit_sch_usage,
{ "EIT schedule usage", "dvb-ci.opp.eit_sch_usage",
FT_UINT8, BASE_HEX, NULL, 0x0E, NULL, HFILL }
},
{ &hf_dvbci_ext_evt_usage,
{ "Extended event usage", "dvb-ci.opp.ext_evt_usage",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL }
},
{ &hf_dvbci_sdt_oth_trusted,
{ "SDT_other trusted", "dvb-ci.opp.sdt_oth_trusted",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL }
},
{ &hf_dvbci_eit_evt_trigger,
{ "EIT event trigger", "dvb-ci.opp.eit_evt_trigger",
FT_UINT8, BASE_HEX, NULL, 0x40, NULL, HFILL }
},
{ &hf_dvbci_opp_lang_code,
{ "Language code", "dvb-ci.opp.lang_code",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_prof_name,
{ "Profile name", "dvb-ci.opp.profile_name",
FT_UINT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_unattended,
{ "Unattended flag", "dvb-ci.opp.unattended_flag",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL }
},
{ &hf_dvbci_opp_srv_type,
{ "Service type", "dvb-ci.opp.service_type",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_dlv_cap_byte,
{ "Delivery capability byte", "dvb-ci.opp.dlv_cap_byte",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_app_cap_bytes,
{ "Application capability bytes", "dvb-ci.opp.app_cap_bytes",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_desc_num,
{ "Next unprocessed descriptor number", "dvb-ci.opp.desc_num",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_sig_strength,
{ "Signal strength", "dvb-ci.opp.sig_strength",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_sig_qual,
{ "Signal quality", "dvb-ci.opp.sig_qual",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_opp_tune_status,
{ "Tuning status", "dvb-ci.opp.tune_status",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL }
},
{ &hf_dvbci_opp_desc_loop_len,
{ "Descriptor loop length", "dvb-ci.opp.desc_loop_len",
FT_UINT16, BASE_DEC, NULL, 0x0FFF, NULL, HFILL }
},
{ &hf_dvbci_sas_app_id,
{ "Application ID", "dvb-ci.sas.app_id",
FT_UINT64, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_sas_sess_state,
{ "Connection state", "dvb-ci.sas.sess_state",
FT_UINT8, BASE_DEC, VALS(dvbci_sas_sess_state), 0, NULL, HFILL }
},
{ &hf_dvbci_sas_msg_nb,
{ "Message number", "dvb-ci.sas.msg_nb",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_dvbci_sas_msg_len,
{ "Message length", "dvb-ci.sas.msg_len",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
}
};
static ei_register_info ei[] = {
{ &ei_dvbci_dvbci_char_tbl, { "dvb-ci.mmi.char_tbl.not_supported", PI_PROTOCOL, PI_WARN, "Character tables with multi-byte encoding are not supported", EXPFILL }},
{ &ei_dvbci_ca_pmt_cmd_id, { "dvb-ci.ca.ca_pmt_cmd_id.ca_pmt", PI_MALFORMED, PI_ERROR, "The ca_pmt shall only contain ca descriptors (tag 0x9)", EXPFILL }},
{ &ei_dvbci_bad_length, { "dvb-ci.bad_length", PI_MALFORMED, PI_ERROR, "Invalid APDU length field, %s must be a multiple of 4 bytes", EXPFILL }},
{ &ei_dvbci_network_id, { "dvb-ci.hc.nid.ignored", PI_PROTOCOL, PI_NOTE, "Network ID is usually ignored by hosts", EXPFILL }},
{ &ei_dvbci_not_text_more_or_text_last, { "dvb-ci.not_text_more_or_text_last", PI_MALFORMED, PI_ERROR, "Items must be text_more() or text_last() objects", EXPFILL }},
{ &ei_dvbci_cup_progress, { "dvb-ci.cup.progress.invalid", PI_PROTOCOL, PI_WARN, "progress is in percent, value must be between 0 and 100", EXPFILL }},
{ &ei_dvbci_sac_payload_enc, { "dvb-ci.cc.sac.payload_enc.clear", PI_PROTOCOL, PI_NOTE, "The original PDU was encrypted, this exported PDU is in the clear", EXPFILL }},
{ &ei_dvbci_pin_evt_cent, { "dvb-ci.cc.pin_event_time_centi.invalid", PI_PROTOCOL, PI_WARN, "Invalid value for event time centiseconds, Value must be between 0 and 100", EXPFILL }},
{ &ei_dvbci_cicam_nit_table_id, { "dvb-ci.cicam_nit.table_id.invalid", PI_PROTOCOL, PI_WARN, "CICAM NIT must have table id 0x40 (NIT actual)", EXPFILL }},
{ &ei_dvbci_sig_qual, { "dvb-ci.opp.sig_qual.invalid", PI_PROTOCOL, PI_WARN, "Invalid value for signal strength / signal quality, values are in percent (0 to 100)", EXPFILL }},
{ &ei_dvbci_apdu_tag, { "dvb-ci.apdu_tag.invalid", PI_MALFORMED, PI_ERROR, "Invalid or unsupported APDU tag", EXPFILL }},
{ &ei_dvbci_apdu_not_supported, { "dvb-ci.apdu_not_supported", PI_PROTOCOL, PI_WARN, "Dissection of this APDU is not supported", EXPFILL }},
{ &ei_dvbci_apu_host_to_cam, { "dvb-ci.apu.host_to_cam", PI_PROTOCOL, PI_WARN, "Invalid APDU direction, this APDU must be sent from host to CAM", EXPFILL }},
{ &ei_dvbci_apu_cam_to_host, { "dvb-ci.apu.cam_to_host", PI_PROTOCOL, PI_WARN, "Invalid APDU direction, this APDU must be sent from CAM to host", EXPFILL }},
{ &ei_dvbci_res_class, { "dvb-ci.res.class.invalid", PI_PROTOCOL, PI_WARN, "Invalid resource class for this apdu", EXPFILL }},
{ &ei_dvbci_res_ver, { "dvb-ci.res.version.old", PI_PROTOCOL, PI_WARN, "Invalid resource version for this apdu", EXPFILL }},
{ &ei_dvbci_spdu_tag, { "dvb-ci.spdu_tag.invalid", PI_MALFORMED, PI_ERROR, "Invalid SPDU tag, See table 14 in the DVB-CI specification", EXPFILL }},
{ &ei_dvbci_spdu_host_to_cam, { "dvb-ci.spdu.host_to_cam", PI_PROTOCOL, PI_WARN, "Invalid SPDU direction, this SPDU must be sent from host to CAM", EXPFILL }},
{ &ei_dvbci_spdu_cam_to_host, { "dvb-ci.spdu.cam_to_host", PI_PROTOCOL, PI_WARN, "Invalid SPDU direction, this SPDU must be sent from CAM to host", EXPFILL }},
{ &ei_dvbci_tpdu_status_tag, { "dvb-ci.tpdu.status_tag.invalid", PI_MALFORMED, PI_ERROR, "Invalid status tag, this must always be T_SB (0x80)", EXPFILL }},
{ &ei_dvbci_t_c_id, { "dvb-ci.t_c_id.invalid", PI_PROTOCOL, PI_WARN, "Transport Connection ID mismatch, tcid is %d in the transport layer and %d in the link layer", EXPFILL }},
{ &ei_dvbci_sb_value, { "dvb-ci.sb_value.invalid", PI_PROTOCOL, PI_WARN, "Invalid SB_value, must be 0x00 or 0x80", EXPFILL }},
{ &ei_dvbci_c_tpdu_tag, { "dvb-ci.c_tpdu_tag.invalid", PI_MALFORMED, PI_ERROR, "Invalid Command-TPDU tag, see DVB-CI specification, table A.16 for valid values", EXPFILL }},
{ &ei_dvbci_r_tpdu_tag, { "dvb-ci.r_tpdu_tag.invalid", PI_MALFORMED, PI_ERROR, "Invalid Response-TPDU tag, see DVB-CI specification, table A.16 for valid values", EXPFILL }},
{ &ei_dvbci_r_tpdu_status_mandatory, { "dvb-ci.r_tpdu_status.mandatory", PI_MALFORMED, PI_ERROR, "Response TPDU's status part is missing, RTPDU status is mandatory", EXPFILL }},
{ &ei_dvbci_ml, { "dvb-ci.more_last.invalid", PI_PROTOCOL, PI_WARN, "Invalid More/Last indicator, second byte of an LPDU must be 0x80 or 0x00", EXPFILL }},
{ &ei_dvbci_buf_size, { "dvb-ci.buf_size.invalid", PI_PROTOCOL, PI_WARN, "Illegal buffer size command", EXPFILL }},
{ &ei_dvbci_cor_addr, { "dvb-ci.cor_address.invalid", PI_PROTOCOL, PI_WARN, "COR address must not be greater than 0xFFE (DVB-CI spec, A.5.6)", EXPFILL }},
};
spdu_table = g_hash_table_new(g_direct_hash, g_direct_equal);
for(i=0; i<array_length(spdu_info); i++) {
g_hash_table_insert(spdu_table,
GUINT_TO_POINTER((guint)spdu_info[i].tag),
(const gpointer)(&spdu_info[i]));
}
apdu_table = g_hash_table_new(g_direct_hash, g_direct_equal);
for(i=0; i<array_length(apdu_info); i++) {
g_hash_table_insert(apdu_table,
GUINT_TO_POINTER((guint)apdu_info[i].tag),
(const gpointer)(&apdu_info[i]));
}
proto_dvbci = proto_register_protocol("DVB Common Interface", "DVB-CI", "dvb-ci");
proto_register_field_array(proto_dvbci, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dvbci = expert_register_protocol(proto_dvbci);
expert_register_field_array(expert_dvbci, ei, array_length(ei));
dvbci_module = prefs_register_protocol(
proto_dvbci, proto_reg_handoff_dvbci);
prefs_register_string_preference(dvbci_module,
"sek", "SAC Encryption Key", "SAC Encryption Key (16 hex bytes)",
&dvbci_sek);
prefs_register_string_preference(dvbci_module,
"siv", "SAC Init Vector", "SAC Init Vector (16 hex bytes)",
&dvbci_siv);
prefs_register_bool_preference(dvbci_module,
"dissect_lsc_msg",
"Dissect LSC messages",
"Dissect the content of messages transmitted "
"on the Low-Speed Communication resource. "
"This requires a dissector for the protocol and target port "
"contained in the connection descriptor.",
&dvbci_dissect_lsc_msg);
sas_msg_dissector_table = register_dissector_table("dvb-ci.sas.app_id_str",
"SAS application id", FT_STRING, BASE_NONE);
register_init_routine(dvbci_init);
new_register_dissector(EXPORTED_SAC_MSG_PROTO,
dissect_dvbci_exported_sac_msg, proto_dvbci);
}
void
proto_reg_handoff_dvbci(void)
{
dissector_handle_t dvbci_handle;
dvbci_handle = new_create_dissector_handle(dissect_dvbci, proto_dvbci);
dissector_add_uint("wtap_encap", WTAP_ENCAP_DVBCI, dvbci_handle);
data_handle = find_dissector("data");
mpeg_pmt_handle = find_dissector("mpeg_pmt");
dvb_nit_handle = find_dissector("dvb_nit");
tcp_dissector_table = find_dissector_table("tcp.port");
udp_dissector_table = find_dissector_table("udp.port");
exported_pdu_tap = find_tap_id(EXPORT_PDU_TAP_NAME_DVB_CI);
}
