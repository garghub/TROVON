static void
dissect_kink(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree){
proto_item *ti = NULL;
proto_tree *kink_tree = NULL;
guint8 type;
guint32 doi;
guint chsumlen;
guint8 next_payload;
guint8 value_a_and_front_reserved;
guint8 value_a;
int offset=0;
type = tvb_get_guint8(tvb,offset);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "KINK");
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(type, kink_type_vals, "unknown"));
ti = proto_tree_add_item(tree, proto_kink, tvb, offset, -1, ENC_NA);
kink_tree = proto_item_add_subtree(ti, ett_kink);
proto_tree_add_uint(kink_tree, hf_kink_type, tvb, offset, 1, type);
offset++;
proto_tree_add_item(kink_tree, hf_kink_version, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(kink_tree, hf_kink_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
doi = tvb_get_ntohl(tvb, offset);
if(doi == IPSEC){
proto_tree_add_uint_format_value(kink_tree, hf_kink_domain_of_interpretation, tvb, offset, 4, doi, "IPsec (%u)", doi);
}
else{
proto_tree_add_uint_format_value(kink_tree, hf_kink_domain_of_interpretation, tvb, offset, 4, doi, "Not IPsec (%u)", doi);
}
offset += 4;
proto_tree_add_item(kink_tree, hf_kink_transactionId, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
chsumlen = tvb_get_guint8(tvb, offset);
proto_tree_add_item(kink_tree, hf_kink_checkSumLength, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
next_payload = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(kink_tree, hf_kink_next_payload, tvb, offset, 1, next_payload);
offset ++;
value_a_and_front_reserved = tvb_get_guint8(tvb, offset);
value_a = (value_a_and_front_reserved & FRONT_ONE_BIT) >> A_BIT_SHIFT;
proto_tree_add_uint(kink_tree, hf_kink_A, tvb, offset, 1, value_a);
proto_tree_add_item(kink_tree, hf_kink_reserved15, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(kink_tree, hf_kink_checkSum, tvb, offset, chsumlen, ENC_NA);
if((chsumlen % PADDING) != 0){
chsumlen += (PADDING - (chsumlen % PADDING));
offset += chsumlen;
}
else{
offset += chsumlen;
}
control_payload(pinfo, tvb, offset, next_payload, kink_tree);
}
static void
control_payload(packet_info *pinfo, tvbuff_t *tvb, int offset, guint8 next_payload, proto_tree *kink_tree){
switch(next_payload){
case KINK_DONE:
break;
case KINK_AP_REQ:
dissect_payload_kink_ap_req(pinfo, tvb, offset, kink_tree);
break;
case KINK_AP_REP:
dissect_payload_kink_ap_rep(pinfo, tvb, offset, kink_tree);
break;
case KINK_KRB_ERROR:
dissect_payload_kink_krb_error(pinfo, tvb, offset, kink_tree);
break;
case KINK_TGT_REQ:
dissect_payload_kink_tgt_req(pinfo, tvb, offset, kink_tree);
break;
case KINK_TGT_REP:
dissect_payload_kink_tgt_rep(pinfo, tvb, offset, kink_tree);
break;
case KINK_ISAKMP:
dissect_payload_kink_isakmp(pinfo, tvb, offset, kink_tree);
break;
case KINK_ENCRYPT:
dissect_payload_kink_encrypt(pinfo, tvb, offset, kink_tree);
break;
case KINK_ERROR:
dissect_payload_kink_error(pinfo, tvb, offset, kink_tree);
break;
default:
dissect_payload_kink_not_defined(pinfo, tvb, offset, kink_tree);
break;
}
}
static void
dissect_payload_kink_ap_req(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree){
proto_tree *payload_kink_ap_req_tree;
proto_item *ti;
guint8 next_payload;
guint payload_length;
guint16 krb_ap_req_length;
int start_payload_offset = 0;
start_payload_offset = offset;
payload_length = tvb_get_ntohs(tvb, offset + TO_PAYLOAD_LENGTH);
payload_kink_ap_req_tree = proto_tree_add_subtree(tree, tvb, offset, payload_length,
ett_payload_kink_ap_req, NULL, "KINK_AP_REQ");
next_payload = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(payload_kink_ap_req_tree, hf_kink_next_payload, tvb, offset, 1, next_payload);
offset ++;
proto_tree_add_item(payload_kink_ap_req_tree, hf_kink_reserved8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
ti = proto_tree_add_uint(payload_kink_ap_req_tree, hf_kink_payload_length, tvb, offset, 2, payload_length);
if(payload_length <= PAYLOAD_HEADER){
expert_add_info(pinfo, ti, &ei_kink_payload_length_small);
}
offset += 2;
proto_tree_add_item(payload_kink_ap_req_tree, hf_kink_epoch, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if(payload_length > PAYLOAD_HEADER){
tvbuff_t *krb_tvb;
krb_ap_req_length = payload_length - PAYLOAD_HEADER;
krb_tvb=tvb_new_subset(tvb, offset, (krb_ap_req_length>tvb_length_remaining(tvb, offset))?tvb_length_remaining(tvb, offset):krb_ap_req_length, krb_ap_req_length);
keytype=kerberos_output_keytype();
dissect_kerberos_main(krb_tvb, pinfo, payload_kink_ap_req_tree, FALSE, NULL);
}
if(payload_length % PADDING != 0){
payload_length += (PADDING - (payload_length % PADDING));
}
offset = start_payload_offset + payload_length;
if(payload_length > 0) {
control_payload(pinfo, tvb, offset, next_payload, tree);
}
}
static void
dissect_payload_kink_ap_rep(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree){
proto_tree *payload_kink_ap_rep_tree;
proto_item *ti;
guint8 next_payload;
guint payload_length;
guint16 krb_ap_rep_length;
int start_payload_offset = 0;
payload_length = tvb_get_ntohs(tvb, offset + TO_PAYLOAD_LENGTH);
start_payload_offset = offset;
payload_kink_ap_rep_tree = proto_tree_add_subtree(tree, tvb, offset, payload_length,
ett_payload_kink_ap_rep, NULL, "KINK_AP_REP");
next_payload = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(payload_kink_ap_rep_tree, hf_kink_next_payload, tvb, offset, 1, next_payload);
offset ++;
proto_tree_add_item(payload_kink_ap_rep_tree, hf_kink_reserved8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
ti = proto_tree_add_uint(payload_kink_ap_rep_tree, hf_kink_payload_length, tvb, offset, 2, payload_length);
if(payload_length <= PAYLOAD_HEADER){
expert_add_info(pinfo, ti, &ei_kink_payload_length_small);
}
offset += 2;
proto_tree_add_item(payload_kink_ap_rep_tree, hf_kink_epoch, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if(payload_length > PAYLOAD_HEADER){
tvbuff_t *krb_tvb;
krb_ap_rep_length = payload_length - PAYLOAD_HEADER;
krb_tvb=tvb_new_subset(tvb, offset, (krb_ap_rep_length>tvb_length_remaining(tvb, offset))?tvb_length_remaining(tvb, offset):krb_ap_rep_length, krb_ap_rep_length);
keytype=kerberos_output_keytype();
dissect_kerberos_main(krb_tvb, pinfo, payload_kink_ap_rep_tree, FALSE, NULL);
}
if(payload_length % PADDING != 0){
payload_length += (PADDING - (payload_length % PADDING));
}
offset = start_payload_offset + payload_length;
if(payload_length > 0) {
control_payload(pinfo, tvb, offset, next_payload, tree);
}
}
static void
dissect_payload_kink_krb_error(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree){
proto_tree *payload_kink_krb_error_tree;
proto_item *ti;
guint8 next_payload;
guint payload_length;
guint16 krb_error_length;
int start_payload_offset = 0;
payload_length = tvb_get_ntohs(tvb, offset + TO_PAYLOAD_LENGTH);
start_payload_offset = offset;
payload_kink_krb_error_tree = proto_tree_add_subtree(tree, tvb, offset, payload_length,
ett_payload_kink_krb_error, NULL, "KINK_KRB_ERROR");
next_payload = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(payload_kink_krb_error_tree, hf_kink_next_payload, tvb, offset, 1, next_payload);
offset ++;
proto_tree_add_item(payload_kink_krb_error_tree, hf_kink_reserved8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
ti = proto_tree_add_uint(payload_kink_krb_error_tree, hf_kink_payload_length, tvb, offset, 2, payload_length);
if(payload_length <= KINK_KRB_ERROR_HEADER){
expert_add_info(pinfo, ti, &ei_kink_payload_length_small);
}
else {
offset += 2;
}
if(payload_length > KINK_KRB_ERROR_HEADER){
tvbuff_t *krb_tvb;
krb_error_length = payload_length - KINK_KRB_ERROR_HEADER;
krb_tvb=tvb_new_subset(tvb, offset, (krb_error_length>tvb_length_remaining(tvb, offset))?tvb_length_remaining(tvb, offset):krb_error_length, krb_error_length);
dissect_kerberos_main(krb_tvb, pinfo, payload_kink_krb_error_tree, FALSE, NULL);
}
if(payload_length % PADDING != 0){
payload_length += (PADDING - (payload_length % PADDING));
}
offset = start_payload_offset + payload_length;
if(payload_length > 0) {
control_payload(pinfo, tvb, offset, next_payload, tree);
}
}
static void
dissect_payload_kink_tgt_req(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree){
proto_tree *payload_kink_tgt_req_tree;
guint8 next_payload;
guint payload_length;
guint16 realm_name_length;
int start_payload_offset = 0;
payload_length = tvb_get_ntohs(tvb, offset + TO_PAYLOAD_LENGTH);
realm_name_length = tvb_get_ntohs(tvb, offset + TO_REALM_NAME_LENGTH);
start_payload_offset = offset;
payload_kink_tgt_req_tree = proto_tree_add_subtree(tree, tvb, offset, payload_length,
ett_payload_kink_tgt_req, NULL, "KINK_TGT_REQ");
next_payload = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(payload_kink_tgt_req_tree, hf_kink_next_payload, tvb, offset, 1, next_payload);
offset ++;
proto_tree_add_item(payload_kink_tgt_req_tree, hf_kink_reserved8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_uint(payload_kink_tgt_req_tree, hf_kink_payload_length, tvb, offset, 2, payload_length);
offset += 2;
proto_tree_add_uint(payload_kink_tgt_req_tree, hf_kink_realm_name_length, tvb, offset, 2, realm_name_length);
offset += 2;
proto_tree_add_item(payload_kink_tgt_req_tree, hf_kink_realm_name, tvb, offset, realm_name_length, ENC_NA|ENC_ASCII);
if(payload_length % PADDING != 0){
payload_length += (PADDING - (payload_length % PADDING));
}
offset = start_payload_offset + payload_length;
if(payload_length > 0) {
control_payload(pinfo, tvb, offset, next_payload, tree);
}
}
static void
dissect_payload_kink_tgt_rep(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree){
proto_tree *payload_kink_tgt_rep_tree;
guint8 next_payload;
guint payload_length;
guint princ_name_length;
guint16 tgt_length;
int start_payload_offset = 0;
payload_length = tvb_get_ntohs(tvb, offset + TO_PAYLOAD_LENGTH);
start_payload_offset = offset;
payload_kink_tgt_rep_tree = proto_tree_add_subtree(tree, tvb, offset, payload_length,
ett_payload_kink_tgt_rep, NULL, "KINK_TGT_REP");
next_payload = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(payload_kink_tgt_rep_tree, hf_kink_next_payload, tvb, offset, 1, next_payload);
offset ++;
proto_tree_add_item(payload_kink_tgt_rep_tree, hf_kink_reserved8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_uint(payload_kink_tgt_rep_tree, hf_kink_payload_length, tvb, offset, 2, payload_length);
offset += 2;
princ_name_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(payload_kink_tgt_rep_tree, hf_kink_princ_name_length, tvb, offset, 2, princ_name_length);
offset += 2;
proto_tree_add_item(payload_kink_tgt_rep_tree, hf_kink_princ_name, tvb, offset, princ_name_length, ENC_NA|ENC_ASCII);
if((princ_name_length + FRONT_TGT_REP_HEADER) % PADDING != 0){
offset += (princ_name_length + PADDING - ((princ_name_length + FRONT_TGT_REP_HEADER) % PADDING));
}
else{
offset += princ_name_length;
}
tgt_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(payload_kink_tgt_rep_tree, hf_kink_tgt_length, tvb, offset, 2, tgt_length);
offset += 2;
proto_tree_add_item(payload_kink_tgt_rep_tree, hf_kink_tgt, tvb, offset, tgt_length, ENC_NA|ENC_ASCII);
if(payload_length % PADDING!=0){
payload_length += (PADDING - (payload_length % PADDING));
}
offset = start_payload_offset + payload_length;
if(payload_length > 0) {
control_payload(pinfo, tvb, offset, next_payload, tree);
}
}
static void
dissect_payload_kink_isakmp(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree){
proto_tree *payload_kink_isakmp_tree;
proto_item *ti;
guint8 next_payload;
guint payload_length,isakmp_length;
int length, reported_length;
guint8 inner_next_pload;
int start_payload_offset = 0;
tvbuff_t *isakmp_tvb;
payload_length = tvb_get_ntohs(tvb, offset + TO_PAYLOAD_LENGTH);
start_payload_offset = offset;
payload_kink_isakmp_tree = proto_tree_add_subtree(tree, tvb, offset, payload_length,
ett_payload_kink_isakmp, NULL, "KINK_ISAKMP");
next_payload = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(payload_kink_isakmp_tree, hf_kink_next_payload, tvb, offset, 1, next_payload);
offset ++;
proto_tree_add_item(payload_kink_isakmp_tree, hf_kink_reserved8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
ti = proto_tree_add_uint(payload_kink_isakmp_tree, hf_kink_payload_length, tvb, offset, 2, payload_length);
if(payload_length <= PAYLOAD_HEADER){
expert_add_info(pinfo, ti, &ei_kink_payload_length_small);
}
offset += 2;
inner_next_pload = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(payload_kink_isakmp_tree, hf_kink_inner_next_pload, tvb, offset, 1, inner_next_pload);
offset += 1;
proto_tree_add_item(payload_kink_isakmp_tree, hf_kink_qmversion, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(payload_kink_isakmp_tree, hf_kink_reserved16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if(payload_length > PAYLOAD_HEADER){
isakmp_length = payload_length - PAYLOAD_HEADER;
length = tvb_length_remaining(tvb, offset);
if (length > (int)isakmp_length)
length = isakmp_length;
reported_length = tvb_reported_length_remaining(tvb, offset);
if (reported_length > (int)isakmp_length)
reported_length = isakmp_length;
isakmp_tvb = tvb_new_subset(tvb, offset, length, reported_length);
isakmp_dissect_payloads(isakmp_tvb, payload_kink_isakmp_tree, 1, inner_next_pload, 0, isakmp_length, pinfo);
}
if(payload_length % PADDING != 0){
payload_length += (PADDING - (payload_length % PADDING));
}
offset = start_payload_offset + payload_length;
if(payload_length > 0) {
control_payload(pinfo, tvb, offset, next_payload, tree);
}
}
static void
dissect_payload_kink_encrypt(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree){
proto_tree *payload_kink_encrypt_tree;
proto_item *ti;
guint8 next_payload;
guint payload_length;
#ifdef HAVE_KERBEROS
gint encrypt_length;
#endif
guint8 inner_next_pload;
guint16 inner_payload_length;
int start_payload_offset = 0;
payload_length = tvb_get_ntohs(tvb,offset + TO_PAYLOAD_LENGTH);
start_payload_offset = offset;
#ifdef HAVE_KERBEROS
encrypt_length = payload_length - FROM_NP_TO_PL;
#endif
payload_kink_encrypt_tree = proto_tree_add_subtree(tree, tvb, offset, payload_length,
ett_payload_kink_encrypt, NULL, "KINK_ENCRYPT");
next_payload = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(payload_kink_encrypt_tree, hf_kink_next_payload, tvb, offset, 1, next_payload);
offset ++;
proto_tree_add_item(payload_kink_encrypt_tree, hf_kink_reserved8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
ti = proto_tree_add_uint(payload_kink_encrypt_tree, hf_kink_payload_length, tvb, offset, 2, payload_length);
if(payload_length <= PAYLOAD_HEADER){
expert_add_info(pinfo, ti, &ei_kink_payload_length_small);
}
offset += 2;
if(keytype != 0){
#ifdef HAVE_KERBEROS
tvbuff_t *next_tvb;
guint8 *plaintext=NULL;
next_tvb=tvb_new_subset(tvb, offset, MIN(tvb_length_remaining(tvb, offset), encrypt_length), encrypt_length);
plaintext=decrypt_krb5_data(tree, pinfo, 0, next_tvb, keytype, NULL);
if(plaintext){
next_tvb=tvb_new_child_real_data(tvb, plaintext, encrypt_length, encrypt_length);
tvb_set_free_cb(next_tvb, g_free);
add_new_data_source(pinfo, next_tvb, "decrypted kink encrypt");
dissect_decrypt_kink_encrypt(pinfo, next_tvb, tree, encrypt_length);
}
#endif
}
else{
inner_next_pload = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(payload_kink_encrypt_tree, hf_kink_inner_next_pload, tvb, offset, 1, inner_next_pload);
offset += 1;
proto_tree_add_item(payload_kink_encrypt_tree, hf_kink_reserved24, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
if(payload_length > PAYLOAD_HEADER){
inner_payload_length = payload_length - PAYLOAD_HEADER;
proto_tree_add_item(payload_kink_encrypt_tree, hf_kink_payload, tvb, offset, inner_payload_length, ENC_NA);
}
}
if(payload_length % PADDING !=0){
payload_length += (PADDING - (payload_length % PADDING));
}
offset = start_payload_offset + payload_length;
if(payload_length > 0) {
control_payload(pinfo, tvb, offset, next_payload, tree);
}
}
static void
dissect_decrypt_kink_encrypt(packet_info *pinfo, tvbuff_t *tvb, proto_tree *tree, int payload_length){
proto_tree *decrypt_kink_encrypt_tree;
int offset=0;
guint8 next_payload;
decrypt_kink_encrypt_tree = proto_tree_add_subtree(tree, tvb, offset, payload_length,
ett_decrypt_kink_encrypt, NULL, "decrypted data");
next_payload = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(decrypt_kink_encrypt_tree, hf_kink_next_payload, tvb, offset, 1, next_payload);
offset ++;
proto_tree_add_item(decrypt_kink_encrypt_tree, hf_kink_reserved24, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
control_payload(pinfo, tvb, offset, next_payload, decrypt_kink_encrypt_tree);
}
static void
dissect_payload_kink_error(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree){
proto_tree *payload_kink_error_tree;
proto_item *ti;
guint8 next_payload;
guint16 payload_length;
int start_payload_offset = 0;
payload_length = tvb_get_ntohs(tvb,offset + TO_PAYLOAD_LENGTH);
start_payload_offset = offset;
payload_kink_error_tree = proto_tree_add_subtree(tree, tvb, offset, payload_length,
ett_payload_kink_error, NULL, "KINK_ERROR");
next_payload = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(payload_kink_error_tree, hf_kink_next_payload, tvb, offset, 1, next_payload);
offset ++;
proto_tree_add_item(payload_kink_error_tree, hf_kink_reserved8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
ti = proto_tree_add_uint(payload_kink_error_tree, hf_kink_payload_length, tvb, offset, 2, payload_length);
if(payload_length != KINK_ERROR_LENGTH){
expert_add_info(pinfo, ti, &ei_kink_payload_length_mismatch);
}
offset += 2;
proto_tree_add_item(payload_kink_error_tree, hf_kink_error_code, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = start_payload_offset + KINK_ERROR_LENGTH;
control_payload(pinfo, tvb, offset, next_payload, tree);
}
static void
dissect_payload_kink_not_defined(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree){
proto_tree *payload_kink_not_defined_tree;
guint8 next_payload;
guint payload_length;
int start_payload_offset = 0;
start_payload_offset = offset;
payload_length = tvb_get_ntohs(tvb, offset + TO_PAYLOAD_LENGTH);
payload_kink_not_defined_tree = proto_tree_add_subtree(tree, tvb, offset, payload_length,
ett_payload_not_defined, NULL, "UNKNOWN PAYLOAD");
next_payload = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(payload_kink_not_defined_tree, hf_kink_next_payload, tvb, offset, 1, next_payload);
offset ++;
proto_tree_add_item(payload_kink_not_defined_tree, hf_kink_reserved8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_uint(payload_kink_not_defined_tree, hf_kink_payload_length, tvb, offset, 2, payload_length);
if(payload_length % PADDING != 0){
payload_length += (PADDING - (payload_length % PADDING));
}
offset = start_payload_offset + payload_length;
if(payload_length > 0) {
control_payload(pinfo, tvb, offset, next_payload, tree);
}
}
static void
kink_fmt_version( gchar *result, guint32 version )
{
guint8 major_version, minor_version;
major_version = (guint8)((version & FRONT_FOUR_BIT) >> VERSION_BIT_SHIFT);
minor_version = (guint8)(version & SECOND_FOUR_BIT);
g_snprintf( result, ITEM_LABEL_LENGTH, "%d.%02d", major_version, minor_version);
}
void
proto_register_kink(void) {
static hf_register_info hf[] = {
{ &hf_kink_type,
{ "Type", "kink.type",
FT_UINT8, BASE_DEC, VALS(kink_type_vals), 0x0,
NULL, HFILL }},
{ &hf_kink_length,
{ "Length", "kink.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_kink_transactionId,
{ "Transaction ID", "kink.transactionId",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_kink_checkSumLength,
{ "Checksum Length", "kink.checkSumLength",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_kink_A,
{ "A", "kink.A",
FT_UINT8, BASE_DEC, VALS(kink_A_vals), 0x0,
NULL, HFILL }},
{ &hf_kink_version,
{ "Version", "kink.version",
FT_UINT8, BASE_CUSTOM, kink_fmt_version, 0x0,
NULL, HFILL }},
{ &hf_kink_domain_of_interpretation,
{ "Domain Of Interpretation", "kink.domain_of_interpretation",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_kink_qmversion,
{ "QMVersion", "kink.qmversion",
FT_UINT8, BASE_CUSTOM, kink_fmt_version, 0x0,
NULL, HFILL }},
{ &hf_kink_error_code,
{ "ErrorCode", "kink.error_code",
FT_UINT32, BASE_DEC|BASE_RANGE_STRING, RVALS(kink_error_rvals), 0x0,
NULL, HFILL }},
{ &hf_kink_reserved8,
{ "Reserved", "kink.reserved",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_kink_reserved15,
{ "Reserved", "kink.reserved",
FT_UINT16, BASE_DEC, NULL, SECOND_FIFTEEN_BIT,
NULL, HFILL }},
{ &hf_kink_reserved16,
{ "Reserved", "kink.reserved",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_kink_reserved24,
{ "Reserved", "kink.reserved",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_kink_checkSum,
{ "Checksum", "kink.checkSum",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_kink_next_payload,
{ "Next Payload", "kink.nextPayload",
FT_UINT8, BASE_DEC, VALS(kink_next_payload), 0x0,
NULL, HFILL }},
{ &hf_kink_payload_length,
{ "Payload Length", "kink.payloadLength",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_kink_epoch,
{ "EPOCH", "kink.epoch",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0,
NULL, HFILL }},
{ &hf_kink_inner_next_pload,
{ "InnerNextPload", "kink.innerNextPload",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_kink_realm_name_length,
{ "RealmNameLength", "kink.realmNameLength",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_kink_realm_name,
{ "RealmName", "kink.realmName",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kink_princ_name_length,
{ "PrincNameLength", "kink.princNameLength",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_kink_princ_name,
{ "PrincName", "kink.princName",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kink_tgt_length,
{ "TGT Length", "kink.tgtLength",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_kink_tgt,
{ "TGT", "kink.tgt",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kink_payload,
{ "Payload", "kink.payload",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_kink,
&ett_kink_payload,
&ett_payload_kink_ap_req,
&ett_payload_kink_ap_rep,
&ett_payload_kink_krb_error,
&ett_payload_kink_tgt_req,
&ett_payload_kink_tgt_rep,
&ett_payload_kink_isakmp,
&ett_payload_kink_encrypt,
&ett_payload_kink_error,
&ett_payload_not_defined,
&ett_decrypt_kink_encrypt,
};
static ei_register_info ei[] = {
{ &ei_kink_payload_length_small, { "kink.payload_length_small", PI_PROTOCOL, PI_WARN, "This Payload Length is too small", EXPFILL }},
{ &ei_kink_payload_length_mismatch, { "kink.payload_length_mismatch", PI_PROTOCOL, PI_WARN, "This Payload Length is mismatch", EXPFILL }},
};
expert_module_t* expert_kink;
proto_kink = proto_register_protocol("Kerberized Internet Negotiation of Key", "KINK", "kink");
proto_register_field_array(proto_kink, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_kink = expert_register_protocol(proto_kink);
expert_register_field_array(expert_kink, ei, array_length(ei));
}
void proto_reg_handoff_kink(void) {
dissector_handle_t kink_handle = NULL;
kink_handle = create_dissector_handle(dissect_kink, proto_kink);
dissector_add_uint("udp.port", KINK_PORT, kink_handle);
}
