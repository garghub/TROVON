static ikev2_encr_alg_spec_t* ikev2_decrypt_find_encr_spec(guint num) {
ikev2_encr_alg_spec_t *e;
for (e = ikev2_encr_algs; e->number != 0; e++) {
if (e->number == num) {
return e;
}
}
return NULL;
}
static ikev2_auth_alg_spec_t* ikev2_decrypt_find_auth_spec(guint num) {
ikev2_auth_alg_spec_t *a;
for (a = ikev2_auth_algs; a->number != 0; a++) {
if (a->number == num) {
return a;
}
}
return NULL;
}
static gint ikev1_find_gcry_cipher_algo(guint ike_cipher, guint ike_keylen) {
switch(ike_cipher) {
case ENC_3DES_CBC:
return GCRY_CIPHER_3DES;
case ENC_DES_CBC:
return GCRY_CIPHER_DES;
case ENC_AES_CBC:
switch (ike_keylen) {
case 128:
return GCRY_CIPHER_AES128;
case 192:
return GCRY_CIPHER_AES192;
case 256:
return GCRY_CIPHER_AES256;
}
return GCRY_CIPHER_NONE;
}
return GCRY_CIPHER_NONE;
}
static gint ikev1_find_gcry_md_algo(guint ike_hash) {
switch(ike_hash) {
case HMAC_MD5:
return GCRY_MD_MD5;
case HMAC_SHA:
return GCRY_MD_SHA1;
case HMAC_SHA2_256:
return GCRY_MD_SHA256;
case HMAC_SHA2_384:
return GCRY_MD_SHA384;
case HMAC_SHA2_512:
return GCRY_MD_SHA512;
}
return GCRY_MD_NONE;
}
static gpointer
generate_iv(const gpointer b1, gsize b1_len,
const gpointer b2, gsize b2_len,
gint md_algo, gsize iv_len) {
gcry_md_hd_t md_ctx;
gpointer iv;
if (gcry_md_open(&md_ctx, md_algo, 0) != GPG_ERR_NO_ERROR)
return NULL;
gcry_md_write(md_ctx, b1, b1_len);
gcry_md_write(md_ctx, b2, b2_len);
iv = wmem_alloc(wmem_file_scope(), iv_len);
memcpy(iv, gcry_md_read(md_ctx, md_algo), iv_len);
gcry_md_close(md_ctx);
return iv;
}
static gpointer
get_iv(guint32 message_id, decrypt_data_t *decr) {
gpointer iv, iv1;
gsize cipher_blklen;
gpointer msgid_key;
guint32 msgid_net;
gboolean found;
cipher_blklen = decr->cipher_blklen;
msgid_key = GINT_TO_POINTER(message_id);
found = g_hash_table_lookup_extended(decr->iv_hash, msgid_key, NULL, &iv);
if (found) {
g_hash_table_steal(decr->iv_hash, msgid_key);
return iv;
}
iv1 = g_hash_table_lookup(decr->iv_hash, GINT_TO_POINTER(0));
msgid_net = g_htonl(message_id);
iv = generate_iv(iv1, cipher_blklen,
&msgid_net, sizeof(msgid_net),
decr->digest_algo, cipher_blklen);
return iv;
}
static void
set_next_iv(const guint8 *buf, guint buf_len, guint32 message_id, decrypt_data_t *decr) {
gpointer iv;
gsize cipher_blklen;
gpointer msgid_key;
cipher_blklen = decr->cipher_blklen;
if (buf_len < cipher_blklen) {
iv = NULL;
} else {
iv = wmem_alloc(wmem_file_scope(), cipher_blklen);
memcpy(iv, buf + buf_len - cipher_blklen, cipher_blklen);
}
msgid_key = GINT_TO_POINTER(message_id);
g_hash_table_insert(decr->iv_hash, msgid_key, iv);
}
static void
update_ivs(packet_info *pinfo, const guint8 *buf, guint buf_len, guint32 message_id, decrypt_data_t *decr) {
gpointer iv;
iv = get_iv(message_id, decr);
p_add_proto_data(wmem_file_scope(), pinfo, proto_isakmp, PINFO_CBC_IV, iv);
set_next_iv(buf, buf_len, message_id, decr);
}
static gboolean
prepare_decrypt_params(decrypt_data_t *decr) {
decr->cipher_algo = ikev1_find_gcry_cipher_algo(decr->ike_encr_alg,
decr->ike_encr_keylen);
decr->digest_algo = ikev1_find_gcry_md_algo(decr->ike_hash_alg);
if (decr->cipher_algo == GCRY_CIPHER_NONE ||
decr->digest_algo == GCRY_MD_NONE)
return FALSE;
decr->cipher_keylen = gcry_cipher_get_algo_keylen(decr->cipher_algo);
decr->cipher_blklen = gcry_cipher_get_algo_blklen(decr->cipher_algo);
decr->digest_len = gcry_md_get_algo_dlen(decr->digest_algo);
if (decr->secret_len < decr->cipher_keylen ||
decr->digest_len < decr->cipher_blklen)
return FALSE;
if (decr->gi_len == 0 || decr->gr_len == 0)
return FALSE;
return TRUE;
}
static gboolean
prepare_phase1_iv(decrypt_data_t *decr) {
gpointer iv;
iv = generate_iv(decr->gi, decr->gi_len,
decr->gr, decr->gr_len,
decr->digest_algo, decr->cipher_blklen);
if (!iv)
return FALSE;
g_hash_table_insert(decr->iv_hash, GINT_TO_POINTER(0), iv);
return TRUE;
}
static gboolean
prepare_decrypt(decrypt_data_t *decr) {
gboolean result;
if (!decr)
return FALSE;
if (decr->state == DECR_PARAMS_INIT) {
result = prepare_decrypt_params(decr) &&
prepare_phase1_iv(decr);
decr->state = result ? DECR_PARAMS_READY : DECR_PARAMS_FAIL;
}
return (decr->state == DECR_PARAMS_READY);
}
static decrypt_data_t *
create_decrypt_data(void) {
decrypt_data_t *decr;
decr = (decrypt_data_t *)g_slice_alloc(sizeof(decrypt_data_t));
memset(decr, 0, sizeof(decrypt_data_t));
decr->iv_hash = g_hash_table_new(NULL, NULL);
clear_address(&decr->initiator);
return decr;
}
static tvbuff_t *
decrypt_payload(tvbuff_t *tvb, packet_info *pinfo, const guint8 *buf, guint buf_len, decrypt_data_t *decr) {
guint8 *decrypted_data;
gcry_cipher_hd_t decr_ctx;
tvbuff_t *encr_tvb;
gpointer iv;
gboolean error;
if (buf_len < decr->cipher_blklen)
return NULL;
iv = p_get_proto_data(wmem_file_scope(), pinfo, proto_isakmp, PINFO_CBC_IV);
if (!iv)
return NULL;
if (gcry_cipher_open(&decr_ctx, decr->cipher_algo, GCRY_CIPHER_MODE_CBC, 0) != GPG_ERR_NO_ERROR)
return NULL;
decrypted_data = (guint8 *)wmem_alloc(pinfo->pool, buf_len);
error = gcry_cipher_setiv(decr_ctx, iv, decr->cipher_blklen) ||
gcry_cipher_setkey(decr_ctx, decr->secret, decr->secret_len) ||
gcry_cipher_decrypt(decr_ctx, decrypted_data, buf_len, buf, buf_len);
gcry_cipher_close(decr_ctx);
if (error)
return NULL;
encr_tvb = tvb_new_child_real_data(tvb, decrypted_data, buf_len, buf_len);
add_new_data_source(pinfo, encr_tvb, "Decrypted IKE");
return encr_tvb;
}
static void
dissect_payloads(tvbuff_t *tvb, proto_tree *tree,
int isakmp_version, guint8 initial_payload, int offset, int length,
packet_info *pinfo, guint32 message_id, gboolean is_request, void* decr_data)
{
guint8 payload, next_payload;
guint16 payload_length;
proto_tree * ntree;
for (payload = initial_payload; length > 0; payload = next_payload) {
if (payload == PLOAD_IKE_NONE) {
proto_tree_add_item(tree, hf_isakmp_extradata, tvb, offset, length, ENC_NA);
break;
}
ntree = dissect_payload_header(tvb, pinfo, offset, length, isakmp_version, payload, &next_payload, &payload_length, tree);
if (payload_length >= 4) {
tvb_ensure_bytes_exist(tvb, offset + 4, payload_length - 4);
switch(payload){
case PLOAD_IKE_SA:
case PLOAD_IKE2_SA:
dissect_sa(tvb, offset + 4, payload_length - 4, ntree, isakmp_version, pinfo, is_request, decr_data);
break;
case PLOAD_IKE_P:
dissect_proposal(tvb, pinfo, offset + 4, payload_length - 4, ntree, isakmp_version, decr_data );
break;
case PLOAD_IKE_KE:
case PLOAD_IKE2_KE:
dissect_key_exch(tvb, offset + 4, payload_length - 4, ntree, isakmp_version, pinfo, decr_data );
break;
case PLOAD_IKE_ID:
case PLOAD_IKE2_IDI:
case PLOAD_IKE2_IDR:
dissect_id(tvb, offset + 4, payload_length - 4, ntree, isakmp_version, pinfo );
break;
case PLOAD_IKE_CERT:
case PLOAD_IKE2_CERT:
dissect_cert(tvb, offset + 4, payload_length - 4, ntree, isakmp_version, pinfo );
break;
case PLOAD_IKE_CR:
case PLOAD_IKE2_CERTREQ:
dissect_certreq(tvb, offset + 4, payload_length - 4, ntree, isakmp_version, pinfo );
break;
case PLOAD_IKE_HASH:
dissect_hash(tvb, offset + 4, payload_length - 4, ntree);
break;
case PLOAD_IKE_SIG:
dissect_sig(tvb, offset + 4, payload_length - 4, ntree);
break;
case PLOAD_IKE_NONCE:
case PLOAD_IKE2_NONCE:
dissect_nonce(tvb, offset + 4, payload_length - 4, ntree);
break;
case PLOAD_IKE_N:
case PLOAD_IKE2_N:
dissect_notif(tvb, pinfo, offset + 4, payload_length - 4, ntree, isakmp_version);
break;
case PLOAD_IKE_D:
case PLOAD_IKE2_D:
dissect_delete(tvb, offset + 4, payload_length - 4, ntree, isakmp_version);
break;
case PLOAD_IKE_VID:
case PLOAD_IKE2_V:
dissect_vid(tvb, offset + 4, payload_length - 4, ntree);
break;
case PLOAD_IKE_A:
case PLOAD_IKE2_CP:
dissect_config(tvb, pinfo, offset + 4, payload_length - 4, ntree, isakmp_version, is_request);
break;
case PLOAD_IKE2_AUTH:
dissect_auth(tvb, offset + 4, payload_length - 4, ntree);
break;
case PLOAD_IKE2_TSI:
case PLOAD_IKE2_TSR:
dissect_ts_payload(tvb, offset + 4, payload_length - 4, ntree);
break;
case PLOAD_IKE2_SK:
if(isakmp_version == 2)
dissect_enc(tvb, offset + 4, payload_length - 4, ntree, pinfo, next_payload, is_request, decr_data, TRUE);
break;
case PLOAD_IKE2_EAP:
dissect_eap(tvb, offset + 4, payload_length - 4, ntree, pinfo );
break;
case PLOAD_IKE2_GSPM:
dissect_gspm(tvb, offset + 4, payload_length - 4, ntree);
break;
case PLOAD_IKE_NAT_D:
case PLOAD_IKE_NAT_D13:
case PLOAD_IKE_NAT_D48:
dissect_nat_discovery(tvb, offset + 4, payload_length - 4, ntree );
break;
case PLOAD_IKE_NAT_OA:
case PLOAD_IKE_NAT_OA14:
case PLOAD_IKE_NAT_OA58:
dissect_nat_original_address(tvb, offset + 4, payload_length - 4, ntree, isakmp_version );
break;
case PLOAD_IKE_CISCO_FRAG:
dissect_cisco_fragmentation(tvb, offset + 4, payload_length - 4, ntree, pinfo );
break;
case PLOAD_IKE2_SKF:
if (isakmp_version == 2) {
dissect_ikev2_fragmentation(tvb, offset + 4, ntree, pinfo, message_id, next_payload, is_request, decr_data );
}
break;
default:
proto_tree_add_item(ntree, hf_isakmp_datapayload, tvb, offset + 4, payload_length-4, ENC_NA);
break;
}
}
else if (payload_length > length) {
proto_tree_add_expert_format(ntree, pinfo, &ei_isakmp_payload_bad_length, tvb, 0, 0,
"Payload (bogus, length is %u, greater than remaining length %d",
payload_length, length);
return;
}
else {
proto_tree_add_expert_format(ntree, pinfo, &ei_isakmp_payload_bad_length, tvb, 0, 0,
"Payload (bogus, length is %u, must be at least 4)",
payload_length);
payload_length = 4;
}
offset += payload_length;
length -= payload_length;
}
}
void
isakmp_dissect_payloads(tvbuff_t *tvb, proto_tree *tree, int isakmp_version,
guint8 initial_payload, int offset, int length,
packet_info *pinfo)
{
dissect_payloads(tvb, tree, isakmp_version, initial_payload, offset, length,
pinfo, 0, FALSE, NULL);
}
static int
dissect_isakmp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int offset = 0, len;
isakmp_hdr_t hdr;
proto_item *ti, *vers_item;
proto_tree *isakmp_tree = NULL, *vers_tree;
int isakmp_version;
void* decr_data = NULL;
guint8 flags;
guint8 i_cookie[COOKIE_SIZE], *ic_key;
decrypt_data_t *decr = NULL;
tvbuff_t *decr_tvb;
proto_tree *decr_tree;
address null_addr;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISAKMP");
col_clear(pinfo->cinfo, COL_INFO);
if (tvb_reported_length(tvb)== 1 && tvb_get_guint8(tvb, offset) !=0xff)
return 0;
else if (tvb_reported_length(tvb) < ISAKMP_HDR_SIZE)
return 0;
else if (tvb_get_ntohl(tvb, ISAKMP_HDR_SIZE-4) < ISAKMP_HDR_SIZE)
return 0;
ti = proto_tree_add_item(tree, proto_isakmp, tvb, offset, -1, ENC_NA);
isakmp_tree = proto_item_add_subtree(ti, ett_isakmp);
if ( (tvb_reported_length(tvb)== 1) && (tvb_get_guint8(tvb, offset) == 0xff) ){
col_set_str(pinfo->cinfo, COL_INFO, "NAT Keepalive");
proto_tree_add_item(isakmp_tree, hf_isakmp_nat_keepalive, tvb, offset, 1, ENC_NA);
return 1;
}
hdr.length = tvb_get_ntohl(tvb, offset + ISAKMP_HDR_SIZE - 4);
hdr.exch_type = tvb_get_guint8(tvb, COOKIE_SIZE + COOKIE_SIZE + 1 + 1);
hdr.version = tvb_get_guint8(tvb, COOKIE_SIZE + COOKIE_SIZE + 1);
isakmp_version = hi_nibble(hdr.version);
hdr.flags = tvb_get_guint8(tvb, COOKIE_SIZE + COOKIE_SIZE + 1 + 1 + 1);
if (isakmp_version == 1) {
clear_address(&null_addr);
tvb_memcpy(tvb, i_cookie, offset, COOKIE_SIZE);
decr = (decrypt_data_t*) g_hash_table_lookup(isakmp_hash, i_cookie);
if (! decr) {
ic_key = (guint8 *)g_slice_alloc(COOKIE_SIZE);
memcpy(ic_key, i_cookie, COOKIE_SIZE);
decr = create_decrypt_data();
g_hash_table_insert(isakmp_hash, ic_key, decr);
}
if (addresses_equal(&decr->initiator, &null_addr)) {
copy_address_wmem(wmem_file_scope(), &decr->initiator, &pinfo->src);
}
decr_data = decr;
} else if (isakmp_version == 2) {
ikev2_uat_data_key_t hash_key;
ikev2_uat_data_t *ike_sa_data;
ikev2_decrypt_data_t *ikev2_dec_data;
guchar spii[COOKIE_SIZE], spir[COOKIE_SIZE];
tvb_memcpy(tvb, spii, offset, COOKIE_SIZE);
tvb_memcpy(tvb, spir, offset + COOKIE_SIZE, COOKIE_SIZE);
hash_key.spii = spii;
hash_key.spir = spir;
hash_key.spii_len = COOKIE_SIZE;
hash_key.spir_len = COOKIE_SIZE;
ike_sa_data = (ikev2_uat_data_t *)g_hash_table_lookup(ikev2_key_hash, &hash_key);
if (ike_sa_data) {
guint8 initiator_flag;
initiator_flag = hdr.flags & I_FLAG;
ikev2_dec_data = wmem_new(wmem_packet_scope(), ikev2_decrypt_data_t);
ikev2_dec_data->encr_key = initiator_flag ? ike_sa_data->sk_ei : ike_sa_data->sk_er;
ikev2_dec_data->auth_key = initiator_flag ? ike_sa_data->sk_ai : ike_sa_data->sk_ar;
ikev2_dec_data->encr_spec = ike_sa_data->encr_spec;
ikev2_dec_data->auth_spec = ike_sa_data->auth_spec;
decr_data = ikev2_dec_data;
}
}
{
proto_tree_add_item(isakmp_tree, hf_isakmp_ispi, tvb, offset, COOKIE_SIZE, ENC_NA);
offset += COOKIE_SIZE;
proto_tree_add_item(isakmp_tree, hf_isakmp_rspi, tvb, offset, COOKIE_SIZE, ENC_NA);
offset += COOKIE_SIZE;
hdr.next_payload = tvb_get_guint8(tvb, offset);
proto_tree_add_item(isakmp_tree, hf_isakmp_nextpayload, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
vers_item = proto_tree_add_uint_format_value(isakmp_tree, hf_isakmp_version, tvb, offset,
1, hdr.version, "%u.%u",
hi_nibble(hdr.version), lo_nibble(hdr.version));
vers_tree = proto_item_add_subtree(vers_item, ett_isakmp_version);
proto_tree_add_item(vers_tree, hf_isakmp_mjver, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(vers_tree, hf_isakmp_mnver, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if(isakmp_version == 1) {
proto_tree_add_item(isakmp_tree, hf_isakmp_exchangetype_v1, tvb, offset, 1, ENC_BIG_ENDIAN);
col_add_str(pinfo->cinfo, COL_INFO,val_to_str(hdr.exch_type, exchange_v1_type, "Unknown %d"));
} else if (isakmp_version == 2){
proto_tree_add_item(isakmp_tree, hf_isakmp_exchangetype_v2, tvb, offset, 1, ENC_BIG_ENDIAN);
col_add_str(pinfo->cinfo, COL_INFO,val_to_str(hdr.exch_type, exchange_v2_type, "Unknown %d"));
}
offset += 1;
{
proto_item * fti;
proto_tree * ftree;
fti = proto_tree_add_item(isakmp_tree, hf_isakmp_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
ftree = proto_item_add_subtree(fti, ett_isakmp_flags);
flags = tvb_get_guint8(tvb, offset);
if (isakmp_version == 1) {
proto_tree_add_item(ftree, hf_isakmp_flag_e, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ftree, hf_isakmp_flag_c, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ftree, hf_isakmp_flag_a, tvb, offset, 1, ENC_BIG_ENDIAN);
} else if (isakmp_version == 2) {
proto_tree_add_item(ftree, hf_isakmp_flag_i, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ftree, hf_isakmp_flag_v, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ftree, hf_isakmp_flag_r, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(fti, " (%s, %s, %s)",
(flags & I_FLAG) ? flag_i.true_string : flag_i.false_string,
(flags & V_FLAG) ? flag_v.true_string : flag_v.false_string,
(flags & R_FLAG) ? flag_r.true_string : flag_r.false_string);
}
offset += 1;
}
hdr.message_id = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(isakmp_tree, hf_isakmp_messageid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (isakmp_version == 2) {
col_append_fstr(pinfo->cinfo, COL_INFO, " MID=%02u %s %s",
hdr.message_id,
(flags & I_FLAG) ? flag_i.true_string : flag_i.false_string,
(flags & R_FLAG) ? flag_r.true_string : flag_r.false_string);
}
if (hdr.length < ISAKMP_HDR_SIZE) {
proto_tree_add_uint_format_value(isakmp_tree, hf_isakmp_length, tvb, offset, 4,
hdr.length, "(bogus, length is %u, should be at least %lu)",
hdr.length, (unsigned long)ISAKMP_HDR_SIZE);
return tvb_captured_length(tvb);
}
len = hdr.length - ISAKMP_HDR_SIZE;
if (len < 0) {
proto_tree_add_uint_format_value(isakmp_tree, hf_isakmp_length, tvb, offset, 4,
hdr.length, "(bogus, length is %u, which is too large)",
hdr.length);
return tvb_captured_length(tvb);
}
tvb_ensure_bytes_exist(tvb, offset, len);
proto_tree_add_item(isakmp_tree, hf_isakmp_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (isakmp_version == 1 && (hdr.flags & E_FLAG)) {
if (len) {
ti = proto_tree_add_item(isakmp_tree, hf_isakmp_enc_data, tvb, offset, len, ENC_NA);
proto_item_append_text(ti, " (%d byte%s)", len, plurality(len, "", "s"));
if (!PINFO_FD_VISITED(pinfo))
if (prepare_decrypt(decr))
update_ivs(pinfo, tvb_get_ptr(tvb, offset, len), len, hdr.message_id, decr);
decr_tvb = decrypt_payload(tvb, pinfo, tvb_get_ptr(tvb, offset, len), len, decr);
if (decr_tvb) {
decr_tree = proto_item_add_subtree(ti, ett_isakmp);
dissect_payloads(decr_tvb, decr_tree, isakmp_version,
hdr.next_payload, 0, tvb_reported_length(decr_tvb), pinfo, hdr.message_id, !(flags & R_FLAG), decr_data);
}
}
} else {
dissect_payloads(tvb, isakmp_tree, isakmp_version, hdr.next_payload,
offset, len, pinfo, hdr.message_id, !(flags & R_FLAG), decr_data);
}
}
return tvb_captured_length(tvb);
}
static proto_tree *
dissect_payload_header(tvbuff_t *tvb, packet_info *pinfo, int offset, int length,
int isakmp_version, guint8 payload, guint8 *next_payload_p,
guint16 *payload_length_p, proto_tree *tree)
{
guint8 next_payload;
guint16 payload_length;
proto_item * ti;
proto_tree * ntree;
if (length < 4) {
proto_tree_add_expert_format(tree, pinfo, &ei_isakmp_payload_bad_length, tvb, offset, length,
"Not enough room in payload for all transforms");
*next_payload_p = 0;
*payload_length_p = 0;
return NULL;
}
next_payload = tvb_get_guint8(tvb, offset);
payload_length = tvb_get_ntohs(tvb, offset + 2);
ti = proto_tree_add_uint(tree, hf_isakmp_typepayload, tvb, offset, payload_length, payload);
ntree = proto_item_add_subtree(ti, ett_isakmp_payload);
proto_tree_add_item(ntree, hf_isakmp_nextpayload, tvb, offset, 1, ENC_BIG_ENDIAN);
if (isakmp_version == 1) {
proto_tree_add_item(ntree, hf_isakmp_reserved, tvb, offset + 1, 1, ENC_NA);
} else if (isakmp_version == 2) {
proto_tree_add_item(ntree, hf_isakmp_criticalpayload, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ntree, hf_isakmp_reserved7, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(ntree, hf_isakmp_payloadlen, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
*next_payload_p = next_payload;
*payload_length_p = payload_length;
return ntree;
}
static void
dissect_sa(tvbuff_t *tvb, int offset, int length, proto_tree *tree, int isakmp_version, packet_info *pinfo, gboolean is_request, void* decr_data)
{
guint32 doi;
proto_item *sti;
proto_tree *stree;
if (isakmp_version == 1) {
doi = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_isakmp_sa_doi, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
if (doi == 1) {
if (length < 4) {
proto_tree_add_bytes_format_value(tree, hf_isakmp_sa_situation, tvb, offset, length,
NULL,
"%s (length is %u, should be >= 4)",
tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, length), length);
return;
}
sti = proto_tree_add_item(tree, hf_isakmp_sa_situation, tvb, offset, 4, ENC_NA);
stree = proto_item_add_subtree(sti, ett_isakmp_sa);
proto_tree_add_item(stree, hf_isakmp_sa_situation_identity_only, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(stree, hf_isakmp_sa_situation_secrecy, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(stree, hf_isakmp_sa_situation_integrity, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
dissect_payloads(tvb, tree, isakmp_version, PLOAD_IKE_P, offset,
length, pinfo, 0, is_request, decr_data);
} else {
proto_tree_add_item(tree, hf_isakmp_sa_situation, tvb, offset, length, ENC_NA);
}
} else if (isakmp_version == 2) {
dissect_payloads(tvb, tree, isakmp_version, PLOAD_IKE_P, offset,
length, pinfo, 0, is_request, decr_data);
}
}
static void
dissect_proposal(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree, int isakmp_version, void* decr_data)
{
guint8 protocol_id;
guint8 spi_size;
guint8 num_transforms;
guint8 next_payload;
guint16 payload_length;
proto_tree * ntree;
guint8 proposal_num;
proposal_num = tvb_get_guint8(tvb, offset);
proto_item_append_text(tree, " # %d", proposal_num);
proto_tree_add_item(tree, hf_isakmp_prop_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
protocol_id = tvb_get_guint8(tvb, offset);
if (isakmp_version == 1)
{
proto_tree_add_item(tree, hf_isakmp_prop_protoid_v1, tvb, offset, 1, ENC_BIG_ENDIAN);
}else if (isakmp_version == 2)
{
proto_tree_add_item(tree, hf_isakmp_prop_protoid_v2, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
length -= 1;
spi_size = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_isakmp_spisize, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
num_transforms = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_isakmp_prop_transforms, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
if (spi_size) {
proto_tree_add_item(tree, hf_isakmp_spi, tvb, offset, spi_size, ENC_NA);
offset += spi_size;
length -= spi_size;
}
while (num_transforms > 0) {
ntree = dissect_payload_header(tvb, pinfo, offset, length, isakmp_version,
PLOAD_IKE_T, &next_payload, &payload_length, tree);
if (length < payload_length) {
proto_tree_add_expert_format(tree, pinfo, &ei_isakmp_payload_bad_length, tvb, offset + 4, length,
"Payload (bogus, length is %u, greater than remaining length %d", payload_length, length);
break;
} else if (payload_length < 4) {
proto_tree_add_expert_format(tree, pinfo, &ei_isakmp_payload_bad_length, tvb, offset + 4, length,
"Payload (bogus, length is %u, must be at least 4)", payload_length);
break;
}
dissect_transform(tvb, pinfo, offset + 4, payload_length - 4, ntree, isakmp_version, protocol_id, decr_data);
offset += payload_length;
length -= payload_length;
num_transforms--;
}
}
static void
dissect_attribute_header(tvbuff_t *tvb, proto_tree *tree, int offset,
attribute_common_fields hf_attr, const range_string *attr_typenames,
guint *headerlen, guint *value_len, guint *attr_type,
proto_item **attr_item, proto_tree **subtree)
{
guint attr_type_format;
gboolean has_len;
const gchar *attr_typename;
attr_type_format = tvb_get_ntohs(tvb, offset);
has_len = !(attr_type_format & 0x8000);
*attr_type = attr_type_format & 0x7fff;
if (has_len) {
*headerlen = 4;
*value_len = tvb_get_ntohs(tvb, offset + 2);
} else {
*headerlen = 2;
*value_len = 2;
}
*attr_item = proto_tree_add_item(tree, hf_attr.all, tvb, offset, *headerlen + *value_len, ENC_NA);
attr_typename = rval_to_str(*attr_type, attr_typenames, "Unknown Attribute Type (%02d)");
proto_item_append_text(*attr_item, " (t=%d,l=%d): %s", *attr_type, *value_len, attr_typename);
*subtree = proto_item_add_subtree(*attr_item, ett_isakmp_attr);
proto_tree_add_item(*subtree, hf_attr.format, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint(*subtree, hf_attr.type, tvb, offset, 2, *attr_type);
if (has_len)
proto_tree_add_item(*subtree, hf_attr.length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (*value_len > 0)
proto_tree_add_item(*subtree, hf_attr.value, tvb, offset + *headerlen, *value_len, ENC_NA);
}
static int
dissect_rohc_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint headerlen, value_len, attr_type;
proto_item *attr_item;
proto_tree *attr_tree;
dissect_attribute_header(tvb, tree, offset,
hf_isakmp_notify_data_rohc_attr, rohc_attr_type,
&headerlen, &value_len, &attr_type,
&attr_item, &attr_tree);
offset += headerlen;
if (value_len == 0)
{
expert_add_info(pinfo, attr_item, &ei_isakmp_attribute_value_empty);
return headerlen;
}
switch(attr_type) {
case ROHC_MAX_CID:
proto_tree_add_item(attr_tree, hf_isakmp_notify_data_rohc_attr_max_cid, tvb, offset, value_len, ENC_BIG_ENDIAN);
break;
case ROHC_PROFILE:
proto_tree_add_item(attr_tree, hf_isakmp_notify_data_rohc_attr_profile, tvb, offset, value_len, ENC_BIG_ENDIAN);
break;
case ROHC_INTEG:
proto_tree_add_item(attr_tree, hf_isakmp_notify_data_rohc_attr_integ, tvb, offset, value_len, ENC_BIG_ENDIAN);
break;
case ROHC_ICV_LEN:
proto_tree_add_item(attr_tree, hf_isakmp_notify_data_rohc_attr_icv_len, tvb, offset, value_len, ENC_BIG_ENDIAN);
break;
case ROHC_MRRU:
proto_tree_add_item(attr_tree, hf_isakmp_notify_data_rohc_attr_mrru, tvb, offset, value_len, ENC_BIG_ENDIAN);
break;
default:
break;
}
return headerlen + value_len;
}
static void
dissect_life_duration(tvbuff_t *tvb, proto_tree *tree, proto_item *ti, int hf_uint32, int hf_uint64, int hf_bytes, int offset, guint len)
{
switch (len) {
case 0:
break;
case 1: {
guint8 val;
val = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_uint32, tvb, offset, len, val);
proto_item_append_text(ti, ": %u", val);
break;
}
case 2: {
guint16 val;
val = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_uint32, tvb, offset, len, val);
proto_item_append_text(ti, ": %u", val);
break;
}
case 3: {
guint32 val;
val = tvb_get_ntoh24(tvb, offset);
proto_tree_add_uint(tree, hf_uint32, tvb, offset, len, val);
proto_item_append_text(ti, ": %u", val);
break;
}
case 4: {
guint32 val;
val = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_uint32, tvb, offset, len, val);
proto_item_append_text(ti, ": %u", val);
break;
}
case 5: {
guint64 val;
val = tvb_get_ntoh40(tvb, offset);
proto_tree_add_uint64_format_value(tree, hf_uint64, tvb, offset, len, val, "%" G_GINT64_MODIFIER "u", val);
proto_item_append_text(ti, ": %" G_GINT64_MODIFIER "u", val);
break;
}
case 6: {
guint64 val;
val = tvb_get_ntoh48(tvb, offset);
proto_tree_add_uint64_format_value(tree, hf_uint64, tvb, offset, len, val, "%" G_GINT64_MODIFIER "u", val);
proto_item_append_text(ti, ": %" G_GINT64_MODIFIER "u", val);
break;
}
case 7: {
guint64 val;
val = tvb_get_ntoh56(tvb, offset);
proto_tree_add_uint64_format_value(tree, hf_uint64, tvb, offset, len, val, "%" G_GINT64_MODIFIER "u", val);
proto_item_append_text(ti, ": %" G_GINT64_MODIFIER "u", val);
break;
}
case 8: {
guint64 val;
val = tvb_get_ntoh64(tvb, offset);
proto_tree_add_uint64_format_value(tree, hf_uint64, tvb, offset, len, val, "%" G_GINT64_MODIFIER "u", val);
proto_item_append_text(ti, ": %" G_GINT64_MODIFIER "u", val);
break;
}
default:
proto_tree_add_item(tree, hf_bytes, tvb, offset, len, ENC_NA);
proto_item_append_text(ti, ": %" G_GINT64_MODIFIER "x ...", tvb_get_ntoh64(tvb, offset));
break;
}
}
static int
dissect_ipsec_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint headerlen, value_len, attr_type;
proto_item *attr_item;
proto_tree *attr_tree;
dissect_attribute_header(tvb, tree, offset,
hf_isakmp_ipsec_attr, ipsec_attr_type,
&headerlen, &value_len, &attr_type,
&attr_item, &attr_tree);
offset += headerlen;
if (value_len == 0)
{
expert_add_info(pinfo, attr_item, &ei_isakmp_attribute_value_empty);
return headerlen;
}
switch(attr_type) {
case IPSEC_ATTR_LIFE_TYPE:
proto_tree_add_item(attr_tree, hf_isakmp_ipsec_attr_life_type, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), attr_life_type, "Unknown %d"));
break;
case IPSEC_ATTR_LIFE_DURATION:
dissect_life_duration(tvb, attr_tree, attr_item, hf_isakmp_ipsec_attr_life_duration_uint32, hf_isakmp_ipsec_attr_life_duration_uint64, hf_isakmp_ipsec_attr_life_duration_bytes, offset, value_len);
break;
case IPSEC_ATTR_GROUP_DESC:
proto_tree_add_item(attr_tree, hf_isakmp_ipsec_attr_group_description, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), dh_group, "Unknown %d"));
break;
case IPSEC_ATTR_ENCAP_MODE:
proto_tree_add_item(attr_tree, hf_isakmp_ipsec_attr_encap_mode, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), ipsec_attr_encap_mode, "Unknown %d"));
break;
case IPSEC_ATTR_AUTH_ALGORITHM:
proto_tree_add_item(attr_tree, hf_isakmp_ipsec_attr_auth_algorithm, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), ipsec_attr_auth_algo, "Unknown %d"));
break;
case IPSEC_ATTR_KEY_LENGTH:
proto_tree_add_item(attr_tree, hf_isakmp_ipsec_attr_key_length, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %d", tvb_get_ntohs(tvb, offset));
break;
case IPSEC_ATTR_KEY_ROUNDS:
proto_tree_add_item(attr_tree, hf_isakmp_ipsec_attr_key_rounds, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %d", tvb_get_ntohs(tvb, offset));
break;
case IPSEC_ATTR_CMPR_DICT_SIZE:
proto_tree_add_item(attr_tree, hf_isakmp_ipsec_attr_cmpr_dict_size, tvb, offset, value_len, ENC_BIG_ENDIAN);
break;
case IPSEC_ATTR_CMPR_ALGORITHM:
proto_tree_add_item(attr_tree, hf_isakmp_ipsec_attr_cmpr_algorithm, tvb, offset, value_len, ENC_NA);
break;
case IPSEC_ATTR_ECN_TUNNEL:
proto_tree_add_item(attr_tree, hf_isakmp_ipsec_attr_ecn_tunnel, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), ipsec_attr_ecn_tunnel, "Unknown %d"));
break;
case IPSEC_ATTR_EXT_SEQ_NBR:
proto_tree_add_item(attr_tree, hf_isakmp_ipsec_attr_ext_seq_nbr, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), ipsec_attr_ext_seq_nbr, "Unknown %d"));
break;
case IPSEC_ATTR_AUTH_KEY_LENGTH:
proto_tree_add_item(attr_tree, hf_isakmp_ipsec_attr_auth_key_length, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %d", tvb_get_ntohs(tvb, offset));
break;
case IPSEC_ATTR_SIG_ENCO_ALGORITHM:
proto_tree_add_item(attr_tree, hf_isakmp_ipsec_attr_sig_enco_algorithm, tvb, offset, value_len, ENC_NA);
break;
case IPSEC_ATTR_ADDR_PRESERVATION:
proto_tree_add_item(attr_tree, hf_isakmp_ipsec_attr_addr_preservation, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), ipsec_attr_addr_preservation, "Unknown %d"));
break;
case IPSEC_ATTR_SA_DIRECTION:
proto_tree_add_item(attr_tree, hf_isakmp_ipsec_attr_sa_direction, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), ipsec_attr_sa_direction, "Unknown %d"));
default:
break;
}
return headerlen + value_len;
}
static int
dissect_resp_lifetime_ipsec_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint headerlen, value_len, attr_type;
proto_item *attr_item;
proto_tree *attr_tree;
dissect_attribute_header(tvb, tree, offset,
hf_isakmp_resp_lifetime_ipsec_attr, ipsec_attr_type,
&headerlen, &value_len, &attr_type,
&attr_item, &attr_tree);
offset += headerlen;
if (value_len == 0)
{
expert_add_info(pinfo, attr_item, &ei_isakmp_attribute_value_empty);
return headerlen;
}
switch(attr_type) {
case IPSEC_ATTR_LIFE_TYPE:
proto_tree_add_item(attr_tree, hf_isakmp_resp_lifetime_ipsec_attr_life_type, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), attr_life_type, "Unknown %d"));
break;
case IPSEC_ATTR_LIFE_DURATION:
dissect_life_duration(tvb, attr_tree, attr_item, hf_isakmp_resp_lifetime_ipsec_attr_life_duration_uint32, hf_isakmp_resp_lifetime_ipsec_attr_life_duration_uint64, hf_isakmp_resp_lifetime_ipsec_attr_life_duration_bytes, offset, value_len);
break;
default:
break;
}
return headerlen + value_len;
}
static int
dissect_ike_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, decrypt_data_t *decr
)
{
guint headerlen, value_len, attr_type;
proto_item *attr_item;
proto_tree *attr_tree;
dissect_attribute_header(tvb, tree, offset,
hf_isakmp_ike_attr, ike_attr_type,
&headerlen, &value_len, &attr_type,
&attr_item, &attr_tree);
offset += headerlen;
if (value_len == 0)
{
expert_add_info(pinfo, attr_item, &ei_isakmp_attribute_value_empty);
return headerlen;
}
switch(attr_type) {
case IKE_ATTR_ENCRYPTION_ALGORITHM:
proto_tree_add_item(attr_tree, hf_isakmp_ike_attr_encryption_algorithm, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), ike_attr_enc_algo, "Unknown %d"));
decr->ike_encr_alg = tvb_get_ntohs(tvb, offset);
break;
case IKE_ATTR_HASH_ALGORITHM:
proto_tree_add_item(attr_tree, hf_isakmp_ike_attr_hash_algorithm, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), ike_attr_hash_algo, "Unknown %d"));
decr->ike_hash_alg = tvb_get_ntohs(tvb, offset);
break;
case IKE_ATTR_AUTHENTICATION_METHOD:
proto_tree_add_item(attr_tree, hf_isakmp_ike_attr_authentication_method, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), ike_attr_authmeth, "Unknown %d"));
decr->is_psk = tvb_get_ntohs(tvb, offset) == 0x01 ? TRUE : FALSE;
break;
case IKE_ATTR_GROUP_DESCRIPTION:
proto_tree_add_item(attr_tree, hf_isakmp_ike_attr_group_description, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), dh_group, "Unknown %d"));
decr->group = tvb_get_ntohs(tvb, offset);
break;
case IKE_ATTR_GROUP_TYPE:
proto_tree_add_item(attr_tree, hf_isakmp_ike_attr_group_type, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), ike_attr_grp_type, "Unknown %d"));
break;
case IKE_ATTR_GROUP_PRIME:
proto_tree_add_item(attr_tree, hf_isakmp_ike_attr_group_prime, tvb, offset, value_len, ENC_NA);
break;
case IKE_ATTR_GROUP_GENERATOR_ONE:
proto_tree_add_item(attr_tree, hf_isakmp_ike_attr_group_generator_one, tvb, offset, value_len, ENC_NA);
break;
case IKE_ATTR_GROUP_GENERATOR_TWO:
proto_tree_add_item(attr_tree, hf_isakmp_ike_attr_group_generator_two, tvb, offset, value_len, ENC_NA);
break;
case IKE_ATTR_GROUP_CURVE_A:
proto_tree_add_item(attr_tree, hf_isakmp_ike_attr_group_curve_a, tvb, offset, value_len, ENC_NA);
break;
case IKE_ATTR_GROUP_CURVE_B:
proto_tree_add_item(attr_tree, hf_isakmp_ike_attr_group_curve_b, tvb, offset, value_len, ENC_NA);
break;
case IKE_ATTR_LIFE_TYPE:
proto_tree_add_item(attr_tree, hf_isakmp_ike_attr_life_type, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), attr_life_type, "Unknown %d"));
break;
case IKE_ATTR_LIFE_DURATION:
dissect_life_duration(tvb, attr_tree, attr_item, hf_isakmp_ike_attr_life_duration_uint32, hf_isakmp_ike_attr_life_duration_uint64, hf_isakmp_ike_attr_life_duration_bytes, offset, value_len);
break;
case IKE_ATTR_PRF:
proto_tree_add_item(attr_tree, hf_isakmp_ike_attr_prf, tvb, offset, value_len, ENC_NA);
break;
case IKE_ATTR_KEY_LENGTH:
proto_tree_add_item(attr_tree, hf_isakmp_ike_attr_key_length, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %d", tvb_get_ntohs(tvb, offset));
decr->ike_encr_keylen = tvb_get_ntohs(tvb, offset);
break;
case IKE_ATTR_FIELD_SIZE:
proto_tree_add_item(attr_tree, hf_isakmp_ike_attr_field_size, tvb, offset, value_len, ENC_NA);
break;
case IKE_ATTR_GROUP_ORDER:
proto_tree_add_item(attr_tree, hf_isakmp_ike_attr_group_order, tvb, offset, value_len, ENC_NA);
break;
default:
break;
}
return headerlen + value_len;
}
static int
dissect_resp_lifetime_ike_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint headerlen, value_len, attr_type;
proto_item *attr_item;
proto_tree *attr_tree;
dissect_attribute_header(tvb, tree, offset,
hf_isakmp_resp_lifetime_ike_attr, ike_attr_type,
&headerlen, &value_len, &attr_type,
&attr_item, &attr_tree);
offset += headerlen;
if (value_len == 0)
{
expert_add_info(pinfo, attr_item, &ei_isakmp_attribute_value_empty);
return headerlen;
}
switch(attr_type) {
case IKE_ATTR_LIFE_TYPE:
proto_tree_add_item(attr_tree, hf_isakmp_resp_lifetime_ike_attr_life_type, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), attr_life_type, "Unknown %d"));
break;
case IKE_ATTR_LIFE_DURATION:
dissect_life_duration(tvb, attr_tree, attr_item, hf_isakmp_resp_lifetime_ike_attr_life_duration_uint32, hf_isakmp_resp_lifetime_ike_attr_life_duration_uint64, hf_isakmp_resp_lifetime_ike_attr_life_duration_bytes, offset, value_len);
break;
default:
break;
}
return headerlen + value_len;
}
static int
dissect_ike2_transform_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint headerlen, value_len, attr_type;
proto_item *attr_item;
proto_tree *attr_tree;
dissect_attribute_header(tvb, tree, offset,
hf_isakmp_ike2_attr, transform_ike2_attr_type,
&headerlen, &value_len, &attr_type,
&attr_item, &attr_tree);
offset += headerlen;
if (value_len == 0)
{
expert_add_info(pinfo, attr_item, &ei_isakmp_attribute_value_empty);
return headerlen;
}
switch(attr_type) {
case IKE2_ATTR_KEY_LENGTH:
proto_tree_add_item(attr_tree, hf_isakmp_ike2_attr_key_length, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %d", tvb_get_ntohs(tvb, offset));
break;
default:
break;
}
return headerlen + value_len;
}
static void
dissect_transform(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree, int isakmp_version, int protocol_id, void* decr_data)
{
if (isakmp_version == 1)
{
guint8 transform_id;
guint8 transform_num;
decrypt_data_t *decr = (decrypt_data_t *)decr_data;
int offset_end = 0;
offset_end = offset + length;
transform_num = tvb_get_guint8(tvb, offset);
proto_item_append_text(tree," # %d",transform_num);
proto_tree_add_item(tree, hf_isakmp_trans_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
transform_id = tvb_get_guint8(tvb, offset);
switch (protocol_id) {
case 1:
proto_tree_add_uint_format_value(tree, hf_isakmp_trans_id, tvb, offset, 1,
transform_id, "%s (%u)",
val_to_str_const(transform_id, vs_v1_trans_isakmp, "UNKNOWN-TRANS-TYPE"), transform_id);
break;
case 2:
proto_tree_add_uint_format_value(tree, hf_isakmp_trans_id, tvb, offset, 1,
transform_id, "%s (%u)",
val_to_str_const(transform_id, vs_v1_trans_ah, "UNKNOWN-AH-TRANS-TYPE"), transform_id);
break;
case 3:
proto_tree_add_uint_format_value(tree, hf_isakmp_trans_id, tvb, offset, 1,
transform_id, "%s (%u)",
val_to_str_const(transform_id, vs_v1_trans_esp, "UNKNOWN-ESP-TRANS-TYPE"), transform_id);
break;
case 4:
proto_tree_add_uint_format_value(tree, hf_isakmp_trans_id, tvb, offset, 1,
transform_id, "%s (%u)",
val_to_str_const(transform_id, transform_id_ipcomp, "UNKNOWN-IPCOMP-TRANS-TYPE"), transform_id);
break;
default:
proto_tree_add_item(tree, hf_isakmp_trans_id, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
offset += 1;
proto_tree_add_item(tree, hf_isakmp_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
if (protocol_id == 1 && transform_id == 1) {
decr->ike_encr_alg = 0;
decr->ike_encr_keylen = 0;
decr->ike_hash_alg = 0;
while (offset < offset_end) {
offset += dissect_ike_attribute(tvb, pinfo, tree, offset, decr);
}
}
else {
while (offset < offset_end) {
offset += dissect_ipsec_attribute(tvb, pinfo, tree, offset);
}
}
}
else if(isakmp_version == 2)
{
guint8 transform_type;
int offset_end = 0;
offset_end = offset + length;
transform_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_isakmp_trans_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_isakmp_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
switch(transform_type){
case TF_IKE2_ENCR:
proto_tree_add_item(tree, hf_isakmp_trans_encr, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case TF_IKE2_PRF:
proto_tree_add_item(tree, hf_isakmp_trans_prf, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case TF_IKE2_INTEG:
proto_tree_add_item(tree, hf_isakmp_trans_integ, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case TF_IKE2_DH:
proto_tree_add_item(tree, hf_isakmp_trans_dh, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case TF_IKE2_ESN:
proto_tree_add_item(tree, hf_isakmp_trans_esn, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(tree, hf_isakmp_trans_id_v2, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
}
offset += 2;
while (offset < offset_end) {
offset += dissect_ike2_transform_attribute(tvb, pinfo, tree, offset);
}
}
}
static void
dissect_key_exch(tvbuff_t *tvb, int offset, int length, proto_tree *tree, int isakmp_version,
packet_info* pinfo, void* decr_data)
{
if (isakmp_version == 2) {
proto_tree_add_item(tree, hf_isakmp_key_exch_dh_group, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
proto_tree_add_item(tree, hf_isakmp_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
length -= 2;
}
proto_tree_add_item(tree, hf_isakmp_key_exch_data, tvb, offset, length, ENC_NA);
if (isakmp_version == 1 && decr_data) {
decrypt_data_t *decr = (decrypt_data_t *)decr_data;
if (decr->gi_len == 0 && addresses_equal(&decr->initiator, &pinfo->src)) {
decr->gi = (gchar *)g_malloc(length);
tvb_memcpy(tvb, decr->gi, offset, length);
decr->gi_len = length;
} else if (decr->gr_len == 0 && !addresses_equal(&decr->initiator, &pinfo->src)) {
decr->gr = (gchar *)g_malloc(length);
tvb_memcpy(tvb, decr->gr, offset, length);
decr->gr_len = length;
}
}
}
static void
dissect_id(tvbuff_t *tvb, int offset, int length, proto_tree *tree, int isakmp_version, packet_info *pinfo )
{
guint8 id_type;
guint8 protocol_id;
guint16 port;
proto_item *idit;
proto_tree *idtree;
const guint8 *str;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
id_type = tvb_get_guint8(tvb, offset);
if (isakmp_version == 1)
{
proto_tree_add_item(tree, hf_isakmp_id_type_v1, tvb, offset, 1, ENC_BIG_ENDIAN);
}else if (isakmp_version == 2)
{
proto_tree_add_item(tree, hf_isakmp_id_type_v2, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
length -= 1;
if (isakmp_version == 1) {
protocol_id = tvb_get_guint8(tvb, offset);
if (protocol_id == 0)
proto_tree_add_uint_format_value(tree, hf_isakmp_id_protoid, tvb, offset, 1,
protocol_id, "Unused");
else
proto_tree_add_item(tree, hf_isakmp_id_protoid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
port = tvb_get_ntohs(tvb, offset);
if (port == 0)
proto_tree_add_uint_format_value(tree, hf_isakmp_id_port, tvb, offset, 2,
port, "Unused");
else
proto_tree_add_item(tree, hf_isakmp_id_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
} else if (isakmp_version == 2) {
proto_tree_add_item(tree, hf_isakmp_reserved, tvb, offset, 3, ENC_NA);
offset += 3;
length -= 3;
}
idit = proto_tree_add_item(tree, hf_isakmp_id_data, tvb, offset, length, ENC_NA);
idtree = proto_item_add_subtree(idit, ett_isakmp_id);
switch (id_type) {
case IKE_ID_IPV4_ADDR:
proto_tree_add_item(idtree, hf_isakmp_id_data_ipv4_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(idit, "%s", tvb_ip_to_str(tvb, offset));
break;
case IKE_ID_FQDN:
proto_tree_add_item_ret_string(idtree, hf_isakmp_id_data_fqdn, tvb, offset, length, ENC_ASCII|ENC_NA, wmem_packet_scope(), &str);
proto_item_append_text(idit, "%s", str);
break;
case IKE_ID_USER_FQDN:
proto_tree_add_item_ret_string(idtree, hf_isakmp_id_data_user_fqdn, tvb, offset, length, ENC_ASCII|ENC_NA, wmem_packet_scope(), &str);
proto_item_append_text(idit, "%s", str);
break;
case IKE_ID_IPV4_ADDR_SUBNET:
proto_tree_add_item(idtree, hf_isakmp_id_data_ipv4_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(idtree, hf_isakmp_id_data_ipv4_subnet, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(idit, "%s/%s", tvb_ip_to_str(tvb, offset), tvb_ip_to_str(tvb, offset+4));
break;
case IKE_ID_IPV4_ADDR_RANGE:
proto_tree_add_item(idtree, hf_isakmp_id_data_ipv4_range_start, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(idtree, hf_isakmp_id_data_ipv4_range_end, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(idit, "%s/%s", tvb_ip_to_str(tvb, offset), tvb_ip_to_str(tvb, offset+4));
break;
case IKE_ID_IPV6_ADDR:
proto_tree_add_item(idtree, hf_isakmp_id_data_ipv6_addr, tvb, offset, 16, ENC_NA);
proto_item_append_text(idit, "%s", tvb_ip6_to_str(tvb, offset));
break;
case IKE_ID_IPV6_ADDR_SUBNET:
proto_tree_add_item(idtree, hf_isakmp_id_data_ipv6_addr, tvb, offset, 16, ENC_NA);
proto_tree_add_item(idtree, hf_isakmp_id_data_ipv6_subnet, tvb, offset+16, 16, ENC_NA);
proto_item_append_text(idit, "%s/%s", tvb_ip6_to_str(tvb, offset), tvb_ip6_to_str(tvb, offset+16));
break;
case IKE_ID_IPV6_ADDR_RANGE:
proto_tree_add_item(idtree, hf_isakmp_id_data_ipv6_range_start, tvb, offset, 16, ENC_NA);
proto_tree_add_item(idtree, hf_isakmp_id_data_ipv6_range_end, tvb, offset+16, 16, ENC_NA);
proto_item_append_text(idit, "%s/%s", tvb_ip6_to_str(tvb, offset), tvb_ip6_to_str(tvb, offset+16));
break;
case IKE_ID_KEY_ID:
proto_tree_add_item(idtree, hf_isakmp_id_data_key_id, tvb, offset, length, ENC_NA);
break;
case IKE_ID_DER_ASN1_DN:
dissect_x509if_Name(FALSE, tvb, offset, &asn1_ctx, tree, hf_isakmp_id_data_cert);
break;
default:
proto_item_append_text(idit, "%s", tvb_bytes_to_str(wmem_packet_scope(), tvb,offset,length));
break;
}
}
static void
dissect_cert(tvbuff_t *tvb, int offset, int length, proto_tree *tree, int isakmp_version, packet_info *pinfo )
{
guint8 cert_type;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
cert_type = tvb_get_guint8(tvb, offset);
if (isakmp_version == 1)
{
proto_tree_add_item(tree, hf_isakmp_cert_encoding_v1, tvb, offset, 1, ENC_BIG_ENDIAN);
}else if (isakmp_version == 2)
{
proto_tree_add_item(tree, hf_isakmp_cert_encoding_v2, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
length -= 1;
if (isakmp_version == 1)
{
dissect_x509af_Certificate(FALSE, tvb, offset, &asn1_ctx, tree, hf_isakmp_cert_data);
}else if (isakmp_version == 2)
{
switch(cert_type){
case 12:{
proto_item *ti_url;
proto_tree_add_item(tree, hf_isakmp_cert_x509_hash, tvb, offset, 20, ENC_NA);
offset += 20;
length -= 20;
ti_url = proto_tree_add_item(tree, hf_isakmp_cert_x509_url, tvb, offset, length, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_URL(ti_url);
}
break;
default:
dissect_x509af_Certificate(FALSE, tvb, offset, &asn1_ctx, tree, hf_isakmp_cert_data);
break;
}
}
}
static void
dissect_certreq(tvbuff_t *tvb, int offset, int length, proto_tree *tree, int isakmp_version, packet_info *pinfo )
{
guint8 cert_type;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
cert_type = tvb_get_guint8(tvb, offset);
if (isakmp_version == 1)
{
proto_tree_add_item(tree, hf_isakmp_certreq_type_v1, tvb, offset, 1, ENC_BIG_ENDIAN);
}else if (isakmp_version == 2)
{
proto_tree_add_item(tree, hf_isakmp_certreq_type_v2, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
length -= 1;
if (isakmp_version == 1)
{
if (length == 0)
return;
switch(cert_type){
case 4:
dissect_x509if_Name(FALSE, tvb, offset, &asn1_ctx, tree, hf_isakmp_certreq_authority_sig);
break;
default:
proto_tree_add_item(tree, hf_isakmp_certreq_authority_v1, tvb, offset, length, ENC_NA);
break;
}
}else if (isakmp_version == 2)
{
while (length > 0) {
proto_tree_add_item(tree, hf_isakmp_certreq_authority_v2, tvb, offset, 20, ENC_NA);
offset+=20;
length-=20;
}
}
}
static void
dissect_auth(tvbuff_t *tvb, int offset, int length, proto_tree *tree)
{
proto_tree_add_item(tree, hf_isakmp_auth_meth, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
proto_tree_add_item(tree, hf_isakmp_reserved, tvb, offset, 3, ENC_NA);
offset += 3;
length -= 3;
proto_tree_add_item(tree, hf_isakmp_auth_data, tvb, offset, length, ENC_NA);
}
static void
dissect_hash(tvbuff_t *tvb, int offset, int length, proto_tree *ntree)
{
proto_tree_add_item(ntree, hf_isakmp_hash, tvb, offset, length, ENC_NA);
}
static void
dissect_sig(tvbuff_t *tvb, int offset, int length, proto_tree *ntree)
{
proto_tree_add_item(ntree, hf_isakmp_sig, tvb, offset, length, ENC_NA);
}
static void
dissect_nonce(tvbuff_t *tvb, int offset, int length, proto_tree *ntree)
{
proto_tree_add_item(ntree, hf_isakmp_nonce, tvb, offset, length, ENC_NA);
}
static void
dissect_cisco_fragmentation(tvbuff_t *tvb, int offset, int length, proto_tree *tree, packet_info *pinfo)
{
guint8 seq;
guint8 last;
proto_tree *ptree;
ptree = proto_tree_get_parent(tree);
if (length < 4)
return;
proto_tree_add_item(tree, hf_isakmp_cisco_frag_packetid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
seq = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_isakmp_cisco_frag_seq, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
last = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_isakmp_cisco_frag_last, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
{
gboolean save_fragmented;
tvbuff_t *defrag_isakmp_tvb;
fragment_head *frag_msg;
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_check(&isakmp_cisco_reassembly_table, tvb, offset,
pinfo,
12345,
NULL,
seq-1,
tvb_reported_length_remaining(tvb, offset),
!last);
defrag_isakmp_tvb = process_reassembled_data(tvb, offset, pinfo,
"Reassembled ISAKMP", frag_msg,
&isakmp_frag_items,
NULL, ptree);
if (last && defrag_isakmp_tvb) {
dissect_isakmp(defrag_isakmp_tvb, pinfo, ptree, NULL);
}
col_append_fstr(pinfo->cinfo, COL_INFO,
" (%sMessage fragment %u%s)",
(last && frag_msg ? "Reassembled + " : ""),
seq, (last ? " - last" : ""));
pinfo->fragmented = save_fragmented;
}
}
static void
dissect_ikev2_fragmentation(tvbuff_t *tvb, int offset, proto_tree *tree,
packet_info *pinfo, guint message_id, guint8 next_payload, gboolean is_request, void* decr_info)
{
guint16 fragment_number, total_fragments;
gboolean message_next_payload_set = FALSE;
guint8 message_next_payload = 0;
gint iv_len, icd_len;
gint iv_offset;
gint icd_offset;
ikev2_decrypt_data_t *key_info;
fragment_number = tvb_get_ntohs(tvb, offset);
total_fragments = tvb_get_ntohs(tvb, offset+2);
proto_tree_add_item(tree, hf_isakmp_ike2_fragment_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (fragment_number == 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_isakmp_bad_fragment_number, tvb, 0, 0,
"Fragment number must not be zero");
}
else if (fragment_number > total_fragments) {
proto_tree_add_expert_format(tree, pinfo, &ei_isakmp_bad_fragment_number, tvb, 0, 0,
"Fragment number (%u) must not be greater than total fragments (%u)",
fragment_number, total_fragments);
}
if (!pinfo->fd->flags.visited && (fragment_number == 1)) {
conversation_t* p_conv = find_or_create_conversation(pinfo);
ikev2_fragmentation_state_t *p_state = wmem_new0(wmem_file_scope(), ikev2_fragmentation_state_t);
p_state->message_id = message_id;
p_state->next_payload = next_payload;
conversation_add_proto_data(p_conv, proto_isakmp, (void*)p_state);
}
proto_tree_add_item(tree, hf_isakmp_ike2_total_fragments, tvb, offset, 2, ENC_BIG_ENDIAN);
if (total_fragments == 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_isakmp_bad_fragment_number, tvb, 0, 0,
"Total fragments must not be zero");
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (fragment %u/%u)", fragment_number, total_fragments);
offset += 2;
if (fragment_number == total_fragments) {
if (!pinfo->fd->flags.visited) {
conversation_t *p_conv = find_conversation(pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (p_conv != NULL) {
ikev2_fragmentation_state_t *p_state = (ikev2_fragmentation_state_t*)conversation_get_proto_data(p_conv, proto_isakmp);
if (p_state != NULL) {
if (p_state->message_id == message_id) {
message_next_payload = p_state->next_payload;
message_next_payload_set = TRUE;
g_hash_table_insert(defrag_next_payload_hash, GUINT_TO_POINTER(pinfo->num), GUINT_TO_POINTER((guint)message_next_payload));
}
}
}
}
else {
message_next_payload = (guint8)GPOINTER_TO_UINT(g_hash_table_lookup(defrag_next_payload_hash, GUINT_TO_POINTER(pinfo->num)));
if (message_next_payload != 0) {
message_next_payload_set = TRUE;
}
}
}
if (decr_info) {
key_info = (ikev2_decrypt_data_t*)(decr_info);
iv_len = key_info->encr_spec->iv_len;
icd_len = key_info->auth_spec->trunc_len;
}
else {
return;
}
iv_offset = offset;
proto_tree_add_item(tree, hf_isakmp_enc_iv, tvb, offset, iv_len, ENC_NA);
offset += iv_len;
icd_offset = offset + tvb_reported_length_remaining(tvb, offset) - icd_len;
proto_tree_add_item(tree, hf_isakmp_enc_data, tvb, offset, icd_offset-offset, ENC_NA);
{
gboolean save_fragmented;
tvbuff_t *defrag_decrypted_isakmp_tvb;
tvbuff_t *isakmp_decrypted_fragment_tvb;
fragment_head *frag_msg;
guint8 padding_length;
guint16 fragment_length;
isakmp_decrypted_fragment_tvb = dissect_enc(tvb, iv_offset, tvb_reported_length_remaining(tvb, iv_offset), tree, pinfo,
0,
is_request,
decr_info,
FALSE
);
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
padding_length = tvb_get_guint8(isakmp_decrypted_fragment_tvb, tvb_reported_length(isakmp_decrypted_fragment_tvb)-1);
fragment_length = tvb_reported_length(isakmp_decrypted_fragment_tvb) - 1 - padding_length;
frag_msg = fragment_add_seq_check(&isakmp_ike2_reassembly_table,
isakmp_decrypted_fragment_tvb,
0,
pinfo,
message_id,
NULL,
fragment_number-1,
fragment_length,
fragment_number < total_fragments);
defrag_decrypted_isakmp_tvb = process_reassembled_data(tvb, offset, pinfo,
"Reassembled IKE2 ISAKMP",
frag_msg,
&isakmp_frag_items,
NULL, tree);
if (defrag_decrypted_isakmp_tvb && key_info && message_next_payload_set) {
col_append_fstr(pinfo->cinfo, COL_INFO, " (reassembled)");
dissect_payloads(defrag_decrypted_isakmp_tvb, tree,
2,
message_next_payload,
0, tvb_reported_length(defrag_decrypted_isakmp_tvb),
pinfo, message_id, is_request, decr_info);
}
pinfo->fragmented = save_fragmented;
}
}
static void
dissect_notif(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree, int isakmp_version)
{
guint32 doi = 0;
guint8 protocol_id;
guint8 spi_size;
guint16 msgtype;
proto_item *data_item;
proto_tree *data_tree;
int offset_end = 0;
offset_end = offset + length;
if (isakmp_version == 1) {
doi = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_isakmp_notify_doi, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
}
protocol_id = tvb_get_guint8(tvb, offset);
if (isakmp_version == 1)
{
proto_tree_add_item(tree, hf_isakmp_notify_protoid_v1, tvb, offset, 1, ENC_BIG_ENDIAN);
}else if (isakmp_version == 2)
{
proto_tree_add_item(tree, hf_isakmp_notify_protoid_v2, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
length -= 1;
spi_size = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_isakmp_spisize, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
msgtype = tvb_get_ntohs(tvb, offset);
if (isakmp_version == 1)
{
proto_tree_add_item(tree, hf_isakmp_notify_msgtype_v1, tvb, offset, 2, ENC_BIG_ENDIAN);
}else if (isakmp_version == 2)
{
if ((msgtype < 8192) || (msgtype > 16383 && msgtype < 40959 )) {
proto_tree_add_uint_format_value(tree, hf_isakmp_notify_msgtype_v2, tvb, offset, 2, msgtype, "%s (%u)",
rval_to_str_const(msgtype, notifmsg_v2_type, "Unknown"), msgtype);
proto_item_append_text(tree, " - %s",
rval_to_str_const(msgtype,
notifmsg_v2_type,
"Unknown"));
} else {
proto_tree_add_uint_format_value(tree, hf_isakmp_notify_msgtype_v2, tvb, offset, 2, msgtype, "%s (%u)",
rval_to_str_const(msgtype, notifmsg_v2_3gpp_type, "Unknown"), msgtype);
proto_item_append_text(tree, " - %s",
rval_to_str_const(msgtype,
notifmsg_v2_3gpp_type,
"Unknown"));
}
}
offset += 2;
length -= 2;
if (spi_size) {
proto_tree_add_item(tree, hf_isakmp_spi, tvb, offset, spi_size, ENC_NA);
offset += spi_size;
length -= spi_size;
}
data_item = proto_tree_add_item(tree, hf_isakmp_notify_data, tvb, offset, length, ENC_NA);
data_tree = proto_item_add_subtree(data_item, ett_isakmp_notify_data);
if (isakmp_version == 1)
{
switch (msgtype) {
case 24576:
if (protocol_id == 1) {
while (offset < offset_end) {
offset += dissect_resp_lifetime_ike_attribute(tvb, pinfo, data_tree, offset);
}
} else if (protocol_id > 1 && doi == 1) {
while (offset < offset_end) {
offset += dissect_resp_lifetime_ipsec_attribute(tvb, pinfo, data_tree, offset);
}
}
break;
case 36136:
proto_tree_add_item(tree, hf_isakmp_notify_data_dpd_are_you_there, tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 36137:
proto_tree_add_item(tree, hf_isakmp_notify_data_dpd_are_you_there_ack, tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 40501:
proto_tree_add_item(tree, hf_isakmp_notify_data_unity_load_balance, tvb, offset, length, ENC_BIG_ENDIAN);
break;
default:
break;
}
} else if (isakmp_version == 2)
{
switch(msgtype){
case 16387:
proto_tree_add_item(tree, hf_isakmp_notify_data_ipcomp_cpi, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isakmp_notify_data_ipcomp_transform_id, tvb, offset+2, 1, ENC_BIG_ENDIAN);
break;
case 16407:
proto_tree_add_item(tree, hf_isakmp_notify_data_redirect_gw_ident_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isakmp_notify_data_redirect_gw_ident_len, tvb, offset+1, 1, ENC_BIG_ENDIAN);
switch(tvb_get_guint8(tvb, offset)){
case 1:
proto_tree_add_item(tree, hf_isakmp_notify_data_redirect_new_resp_gw_ident_ipv4, tvb, offset+2, 4, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(tree, hf_isakmp_notify_data_redirect_new_resp_gw_ident_ipv6, tvb, offset+2, 16, ENC_NA);
break;
case 3:
proto_tree_add_item(tree, hf_isakmp_notify_data_redirect_new_resp_gw_ident_fqdn, tvb, offset+2, tvb_get_guint8(tvb,offset+1), ENC_ASCII|ENC_NA);
break;
default :
proto_tree_add_item(tree, hf_isakmp_notify_data_redirect_new_resp_gw_ident, tvb, offset+2, tvb_get_guint8(tvb,offset+1), ENC_NA);
break;
}
length -= tvb_get_guint8(tvb, offset+1) + 2;
offset += tvb_get_guint8(tvb, offset+1) + 2;
if(length)
{
proto_tree_add_item(tree, hf_isakmp_notify_data_redirect_nonce_data, tvb, offset, length, ENC_NA);
}
break;
case 16408:
proto_tree_add_item(tree, hf_isakmp_notify_data_redirect_gw_ident_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isakmp_notify_data_redirect_gw_ident_len, tvb, offset+1, 1, ENC_BIG_ENDIAN);
switch(tvb_get_guint8(tvb, offset)){
case 1:
proto_tree_add_item(tree, hf_isakmp_notify_data_redirect_org_resp_gw_ident_ipv4, tvb, offset+2, 4, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(tree, hf_isakmp_notify_data_redirect_org_resp_gw_ident_ipv6, tvb, offset+2, 16, ENC_NA);
break;
default :
proto_tree_add_item(tree, hf_isakmp_notify_data_redirect_org_resp_gw_ident, tvb, offset+2, tvb_get_guint8(tvb,offset+1), ENC_NA);
break;
}
break;
case 16409:
proto_tree_add_item(tree, hf_isakmp_notify_data_ticket_lifetime, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
proto_tree_add_item(tree, hf_isakmp_notify_data_ticket_data, tvb, offset, length, ENC_NA);
break;
case 16413:
proto_tree_add_item(tree, hf_isakmp_notify_data_ticket_data, tvb, offset, length, ENC_NA);
break;
case 16416:
while (offset < offset_end) {
offset += dissect_rohc_attribute(tvb, pinfo, tree, offset);
}
break;
case 16419:
proto_tree_add_item(tree, hf_isakmp_notify_data_qcd_token_secret_data, tvb, offset, length, ENC_NA);
break;
case 16422:
proto_tree_add_item(tree, hf_isakmp_notify_data_ha_nonce_data, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_isakmp_notify_data_ha_expected_send_req_msg_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_isakmp_notify_data_ha_expected_recv_req_msg_id, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 16423:
proto_tree_add_item(tree, hf_isakmp_notify_data_ha_incoming_ipsec_sa_delta_value, tvb, offset, length, ENC_NA);
break;
case 16424:
proto_tree_add_item(tree, hf_isakmp_notify_data_secure_password_methods, tvb, offset, length, ENC_NA);
break;
case 41041:
proto_tree_add_item(tree, hf_isakmp_notify_data_3gpp_backoff_timer_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
de_gc_timer3(tvb, tree, pinfo, offset, 1, NULL, 0);
default:
break;
}
}
}
static void
dissect_delete(tvbuff_t *tvb, int offset, int length, proto_tree *tree, int isakmp_version)
{
guint8 spi_size;
if (isakmp_version == 1) {
proto_tree_add_item(tree, hf_isakmp_delete_doi, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
}
if (isakmp_version == 1)
{
proto_tree_add_item(tree, hf_isakmp_delete_protoid_v1, tvb, offset, 1, ENC_BIG_ENDIAN);
}else if (isakmp_version == 2)
{
proto_tree_add_item(tree, hf_isakmp_delete_protoid_v2, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
length -= 1;
spi_size = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_isakmp_spisize, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
proto_tree_add_item(tree, hf_isakmp_num_spis, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
if (spi_size > 0) {
while (length > 0) {
proto_tree_add_item(tree, hf_isakmp_delete_spi, tvb, offset, spi_size, ENC_NA);
offset+=spi_size;
length-=spi_size;
}
}
}
static int
dissect_vid(tvbuff_t *tvb, int offset, int length, proto_tree *tree)
{
const guint8 * pVID;
const char * vendorstring;
pVID = tvb_get_ptr(tvb, offset, length);
vendorstring = bytesprefix_to_str(pVID, (size_t)length, vendor_id, "Unknown Vendor ID");
proto_tree_add_item(tree, hf_isakmp_vid_bytes, tvb, offset, length, ENC_NA);
proto_tree_add_string(tree, hf_isakmp_vid_string, tvb, offset, length, vendorstring);
proto_item_append_text(tree," : %s", vendorstring);
if (length >= 24 && memcmp(pVID, VID_CP_01_R65, 20) == 0)
{
offset += 20;
proto_tree_add_item(tree, hf_isakmp_vid_cp_product, tvb, offset, 4, ENC_BIG_ENDIAN);
offset +=4;
proto_tree_add_item(tree, hf_isakmp_vid_cp_version, tvb, offset, 4, ENC_BIG_ENDIAN);
offset +=4;
proto_tree_add_item(tree, hf_isakmp_vid_cp_timestamp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset +=4;
proto_tree_add_item(tree, hf_isakmp_vid_cp_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
offset +=4;
proto_tree_add_item(tree, hf_isakmp_vid_cp_features, tvb, offset, 4, ENC_BIG_ENDIAN);
offset +=4;
}
if (length >= 14 && memcmp(pVID, VID_CISCO_UNITY, 14) == 0)
{
offset += 14;
proto_tree_add_item(tree, hf_isakmp_vid_cisco_unity_major, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(tree, " %u", tvb_get_guint8(tvb,offset));
offset += 1;
proto_tree_add_item(tree, hf_isakmp_vid_cisco_unity_minor, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(tree, ".%u", tvb_get_guint8(tvb,offset));
offset += 1;
}
if (length >= 16 && memcmp(pVID, VID_MS_NT5_ISAKMPOAKLEY, 16) == 0)
{
offset += 16;
proto_tree_add_item(tree, hf_isakmp_vid_ms_nt5_isakmpoakley, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if (length >= 19 && memcmp(pVID, VID_ARUBA_VIA_AUTH_PROFILE, 19) == 0)
{
offset += 19;
proto_tree_add_item(tree, hf_isakmp_vid_aruba_via_auth_profile, tvb, offset, length-19, ENC_ASCII|ENC_NA);
offset += 4;
}
if (length >= 12 && memcmp(pVID, VID_FORTINET_FORTIGATE, 12) == 0)
{
offset += 12;
proto_tree_add_item(tree, hf_isakmp_vid_fortinet_fortigate_release, tvb, offset, 2, ENC_ASCII|ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_isakmp_vid_fortinet_fortigate_build, tvb, offset, 2, ENC_ASCII|ENC_NA);
offset += 2;
}
return offset;
}
static int
dissect_config_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int isakmp_version, gboolean is_request)
{
const range_string *vs_cfgattr;
guint headerlen, value_len, attr_type;
proto_item *attr_item;
proto_tree *attr_tree;
guint i;
const guint8* str;
if (isakmp_version == 1) {
vs_cfgattr = vs_v1_cfgattr;
hf_isakmp_cfg_attr.type = hf_isakmp_cfg_attr_type_v1;
} else if (isakmp_version == 2) {
vs_cfgattr = vs_v2_cfgattr;
hf_isakmp_cfg_attr.type = hf_isakmp_cfg_attr_type_v2;
} else {
return 4;
}
dissect_attribute_header(tvb, tree, offset,
hf_isakmp_cfg_attr, vs_cfgattr,
&headerlen, &value_len, &attr_type,
&attr_item, &attr_tree);
offset += headerlen;
if (value_len == 0)
{
if (!is_request) {
expert_add_info(pinfo, attr_item, &ei_isakmp_attribute_value_empty);
}
return headerlen;
}
switch (attr_type) {
case INTERNAL_IP4_ADDRESS:
if (value_len % 4 == 0)
{
for (i = 0; i < value_len / 4; i++)
{
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip4_address, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
break;
case INTERNAL_IP4_NETMASK:
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip4_netmask, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case INTERNAL_IP4_DNS:
if (value_len % 4 == 0)
{
for (i = 0; i < value_len / 4; i++)
{
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip4_dns, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
break;
case INTERNAL_IP4_NBNS:
if (value_len % 4 == 0)
{
for (i = 0; i < value_len / 4; i++)
{
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip4_nbns, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
break;
case INTERNAL_ADDRESS_EXPIRY:
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_address_expiry, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case INTERNAL_IP4_DHCP:
if (value_len % 4 == 0)
{
for (i = 0; i < value_len / 4; i++)
{
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip4_dhcp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
break;
case APPLICATION_VERSION:
proto_tree_add_item_ret_string(attr_tree, hf_isakmp_cfg_attr_application_version, tvb, offset, value_len, ENC_ASCII|ENC_NA, wmem_packet_scope(), &str);
proto_item_append_text(attr_item, ": %s", str);
break;
case INTERNAL_IP6_ADDRESS:
if (value_len % 17 == 0)
{
for (i = 0; i < value_len / 17; i++)
{
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip6_address_ip, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip6_address_prefix, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
break;
case INTERNAL_IP6_NETMASK:
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip6_netmask, tvb, offset, 18, ENC_NA);
break;
case INTERNAL_IP6_DNS:
if (value_len % 16 == 0)
{
for (i = 0; i < value_len / 16; i++)
{
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip6_dns, tvb, offset, 16, ENC_NA);
offset += 16;
}
}
break;
case INTERNAL_IP6_NBNS:
if (value_len % 16 == 0)
{
for (i = 0; i < value_len / 16; i++)
{
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip6_nbns, tvb, offset, 16, ENC_NA);
offset += 16;
}
}
break;
case INTERNAL_IP6_DHCP:
if (value_len % 16 == 0)
{
for (i = 0; i < value_len / 16; i++)
{
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip6_dhcp, tvb, offset, 16, ENC_NA);
offset += 16;
}
}
break;
case INTERNAL_IP4_SUBNET:
if (value_len % 8 == 0)
{
for (i = 0; i < value_len / 8; i++)
{
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip4_subnet_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip4_subnet_netmask, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 8;
}
}
break;
case SUPPORTED_ATTRIBUTES:
if (value_len % 2 == 0)
{
for (i = 0; i < value_len / 2; i++)
{
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_supported_attributes, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
break;
case INTERNAL_IP6_SUBNET:
if (value_len % 17 == 0)
{
for (i = 0; i < value_len / 17; i++)
{
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip6_subnet_ip, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip6_subnet_prefix, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
break;
case INTERNAL_IP6_LINK:
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip6_link_interface, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip6_link_id, tvb, offset, value_len - 8, ENC_NA);
break;
case INTERNAL_IP6_PREFIX:
if (value_len % 17 == 0)
{
for (i = 0; i < value_len / 17; i++)
{
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip6_prefix_ip, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_internal_ip6_prefix_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
break;
case P_CSCF_IP4_ADDRESS:
if (value_len % 4 == 0)
{
for (i = 0; i < value_len / 4; i++)
{
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_p_cscf_ip4_address, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
break;
case P_CSCF_IP6_ADDRESS:
if (value_len % 16 == 0)
{
for (i = 0; i < value_len / 16; i++)
{
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_p_cscf_ip6_address, tvb, offset, 16, ENC_NA);
offset += 16;
}
}
break;
case XAUTH_TYPE:
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_xauth_type, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", rval_to_str(tvb_get_ntohs(tvb, offset), cfgattr_xauth_type, "Unknown %d"));
break;
case XAUTH_USER_NAME:
proto_tree_add_item_ret_string(attr_tree, hf_isakmp_cfg_attr_xauth_user_name, tvb, offset, value_len, ENC_ASCII|ENC_NA, wmem_packet_scope(), &str);
proto_item_append_text(attr_item, ": %s", str);
break;
case XAUTH_USER_PASSWORD:
proto_tree_add_item_ret_string(attr_tree, hf_isakmp_cfg_attr_xauth_user_password, tvb, offset, value_len, ENC_ASCII|ENC_NA, wmem_packet_scope(), &str);
proto_item_append_text(attr_item, ": %s", str);
break;
case XAUTH_PASSCODE:
proto_tree_add_item_ret_string(attr_tree, hf_isakmp_cfg_attr_xauth_passcode, tvb, offset, value_len, ENC_ASCII|ENC_NA, wmem_packet_scope(), &str);
proto_item_append_text(attr_item, ": %s", str);
break;
case XAUTH_MESSAGE:
proto_tree_add_item_ret_string(attr_tree, hf_isakmp_cfg_attr_xauth_message, tvb, offset, value_len, ENC_ASCII|ENC_NA, wmem_packet_scope(), &str);
proto_item_append_text(attr_item, ": %s", str);
break;
case XAUTH_CHALLENGE:
proto_tree_add_item_ret_string(attr_tree, hf_isakmp_cfg_attr_xauth_challenge, tvb, offset, value_len, ENC_ASCII|ENC_NA, wmem_packet_scope(), &str);
proto_item_append_text(attr_item, ": %s", str);
break;
case XAUTH_DOMAIN:
proto_tree_add_item_ret_string(attr_tree, hf_isakmp_cfg_attr_xauth_domain, tvb, offset, value_len, ENC_ASCII|ENC_NA, wmem_packet_scope(), &str);
proto_item_append_text(attr_item, ": %s", str);
break;
case XAUTH_STATUS:
proto_tree_add_item(attr_tree, hf_isakmp_cfg_attr_xauth_status, tvb, offset, value_len, ENC_BIG_ENDIAN);
proto_item_append_text(attr_item, ": %s", val_to_str(tvb_get_ntohs(tvb, offset), cfgattr_xauth_status, "Unknown %d"));
break;
case XAUTH_NEXT_PIN:
proto_tree_add_item_ret_string(attr_tree, hf_isakmp_cfg_attr_xauth_next_pin, tvb, offset, value_len, ENC_ASCII|ENC_NA, wmem_packet_scope(), &str);
proto_item_append_text(attr_item, ": %s", str);
break;
case XAUTH_ANSWER:
proto_tree_add_item_ret_string(attr_tree, hf_isakmp_cfg_attr_xauth_answer, tvb, offset, value_len, ENC_ASCII|ENC_NA, wmem_packet_scope(), &str);
proto_item_append_text(attr_item, ": %s", str);
break;
case UNITY_BANNER:
proto_tree_add_item_ret_string(attr_tree, hf_isakmp_cfg_attr_unity_banner, tvb, offset, value_len, ENC_ASCII|ENC_NA, wmem_packet_scope(), &str);
proto_item_append_text(attr_item, ": %s", str);
break;
case UNITY_DEF_DOMAIN:
proto_tree_add_item_ret_string(attr_tree, hf_isakmp_cfg_attr_unity_def_domain, tvb, offset, value_len, ENC_ASCII|ENC_NA, wmem_packet_scope(), &str);
proto_item_append_text(attr_item, ": %s", str);
break;
default:
break;
}
return headerlen + value_len;
}
static void
dissect_config(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree, int isakmp_version, gboolean is_request)
{
int offset_end = 0;
offset_end = offset + length;
if (isakmp_version == 1) {
proto_tree_add_item(tree, hf_isakmp_cfg_type_v1,tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_isakmp_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_isakmp_cfg_identifier, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
} else if (isakmp_version == 2) {
proto_tree_add_item(tree, hf_isakmp_cfg_type_v2,tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_isakmp_reserved, tvb, offset, 3, ENC_NA);
offset += 3;
} else {
return;
}
while (offset < offset_end) {
offset += dissect_config_attribute(tvb, pinfo, tree, offset, isakmp_version, is_request);
}
}
static void
dissect_nat_discovery(tvbuff_t *tvb, int offset, int length, proto_tree *tree )
{
proto_tree_add_item(tree, hf_isakmp_nat_hash, tvb, offset, length, ENC_NA);
}
static void
dissect_nat_original_address(tvbuff_t *tvb, int offset, int length _U_, proto_tree *tree, int isakmp_version)
{
guint8 id_type;
id_type = tvb_get_guint8(tvb, offset);
if (isakmp_version == 1)
{
proto_tree_add_item(tree, hf_isakmp_id_type_v1, tvb, offset, 1, ENC_BIG_ENDIAN);
}else if (isakmp_version == 2)
{
proto_tree_add_item(tree, hf_isakmp_id_type_v2, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
offset += 3;
switch (id_type) {
case IKE_ID_IPV4_ADDR:
proto_tree_add_item(tree, hf_isakmp_nat_original_address_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case IKE_ID_IPV6_ADDR:
proto_tree_add_item(tree, hf_isakmp_nat_original_address_ipv6, tvb, offset, 16, ENC_NA);
break;
default:
break;
}
}
static int
dissect_ts(tvbuff_t *tvb, int offset, proto_tree *payload_tree)
{
guint8 tstype, protocol_id;
guint16 len;
proto_item *ts_item;
proto_tree *tree;
const gchar *ts_typename;
len = tvb_get_guint16(tvb, offset + 2, ENC_BIG_ENDIAN);
if (len < 4)
return 4;
ts_item = proto_tree_add_item(payload_tree, hf_isakmp_ts_data, tvb, offset, len, ENC_NA);
tree = proto_item_add_subtree(ts_item, ett_isakmp_ts);
tstype = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_isakmp_ts_type, tvb, offset, 1, ENC_BIG_ENDIAN);
ts_typename = rval_to_str(tstype, traffic_selector_type, "Unknown Type (%d)");
proto_item_append_text(ts_item, ": %s", ts_typename);
offset += 1;
switch (tstype) {
case IKEV2_TS_IPV4_ADDR_RANGE:
protocol_id = tvb_get_guint8(tvb, offset);
if (protocol_id == 0)
proto_tree_add_uint_format_value(tree, hf_isakmp_ts_protoid, tvb, offset,1,
protocol_id, "Unused");
else
proto_tree_add_item(tree, hf_isakmp_ts_protoid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_isakmp_ts_selector_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_isakmp_ts_start_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_isakmp_ts_end_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_isakmp_ts_start_addr_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_isakmp_ts_end_addr_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case IKEV2_TS_IPV6_ADDR_RANGE:
protocol_id = tvb_get_guint8(tvb, offset);
if (protocol_id == 0)
proto_tree_add_uint_format_value(tree, hf_isakmp_ts_protoid, tvb, offset,1,
protocol_id, "Unused");
else
proto_tree_add_item(tree, hf_isakmp_ts_protoid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_isakmp_ts_selector_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_isakmp_ts_start_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_isakmp_ts_end_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_isakmp_ts_start_addr_ipv6, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_isakmp_ts_end_addr_ipv6, tvb, offset, 16, ENC_NA);
break;
case IKEV2_TS_FC_ADDR_RANGE:
proto_tree_add_item(tree, hf_isakmp_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_isakmp_ts_selector_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_isakmp_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_isakmp_ts_start_addr_fc, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_isakmp_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_isakmp_ts_end_addr_fc, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_isakmp_ts_start_r_ctl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_isakmp_ts_end_r_ctl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_isakmp_ts_start_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_isakmp_ts_end_type, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
return len;
}
static void
dissect_ts_payload(tvbuff_t *tvb, int offset, int length, proto_tree *tree)
{
guint8 num;
int offset_end = offset + length;
num = tvb_get_guint8(tvb, offset);
proto_item_append_text(tree," # %d", num);
proto_tree_add_item(tree, hf_isakmp_ts_number_of_ts, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_isakmp_reserved, tvb, offset, 3, ENC_NA);
offset += 3;
while (offset < offset_end) {
offset += dissect_ts(tvb, offset, tree);
}
}
static tvbuff_t*
dissect_enc(tvbuff_t *tvb,
int offset,
int length,
proto_tree *tree,
packet_info *pinfo,
guint8 inner_payload,
gboolean is_request,
void* decr_info,
gboolean dissect_payload_now)
{
ikev2_decrypt_data_t *key_info = NULL;
gint iv_len, encr_data_len, icd_len, decr_data_len, md_len, icv_len, encr_key_len, encr_iv_len;
guint8 pad_len;
guchar *iv = NULL, *encr_data = NULL, *decr_data = NULL, *entire_message = NULL, *md = NULL, *encr_iv = NULL;
gcry_cipher_hd_t cipher_hd;
gcry_md_hd_t md_hd;
gcry_error_t err = 0;
proto_item *item = NULL, *icd_item = NULL, *encr_data_item = NULL, *padlen_item = NULL, *iv_item = NULL;
tvbuff_t *decr_tvb = NULL;
gint payloads_len;
proto_tree *decr_tree = NULL, *decr_payloads_tree = NULL;
#ifdef HAVE_LIBGCRYPT_AEAD
guchar *aa_data = NULL, *icv_data = NULL;
gint aad_len = 0;
#endif
if (decr_info) {
key_info = (ikev2_decrypt_data_t*)(decr_info);
if (!key_info->encr_spec || !key_info->auth_spec) {
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"IKEv2: decryption/integrity specs not set-up properly: encr_spec: %p, auth_spec: %p",
(void *)key_info->auth_spec, (void*)key_info->auth_spec));
}
iv_len = key_info->encr_spec->iv_len;
icv_len = key_info->encr_spec->icv_len;
icd_len = icv_len ? icv_len : (gint)key_info->auth_spec->trunc_len;
encr_data_len = length - iv_len - icd_len;
encr_key_len = key_info->encr_spec->key_len;
encr_iv_len = iv_len;
if (encr_data_len <= 0) {
proto_tree_add_expert(tree, pinfo, &ei_isakmp_enc_iv, tvb, offset, length);
return NULL;
}
if (iv_len) {
if (dissect_payload_now) {
iv_item = proto_tree_add_item(tree, hf_isakmp_enc_iv, tvb, offset, iv_len, ENC_NA);
proto_item_append_text(iv_item, " (%d bytes)", iv_len);
}
iv = (guchar *)tvb_memdup(wmem_packet_scope(), tvb, offset, iv_len);
encr_iv = iv;
offset += iv_len;
}
if (dissect_payload_now) {
encr_data_item = proto_tree_add_item(tree, hf_isakmp_enc_data, tvb, offset, encr_data_len, ENC_NA);
proto_item_append_text(encr_data_item, " (%d bytes)",encr_data_len);
proto_item_append_text(encr_data_item, " <%s>", val_to_str(key_info->encr_spec->number, vs_ikev2_encr_algs, "Unknown cipher: %d"));
}
encr_data = (guchar *)tvb_memdup(wmem_packet_scope(), tvb, offset, encr_data_len);
offset += encr_data_len;
if (icd_len) {
icd_item = proto_tree_add_item(tree, hf_isakmp_enc_icd, tvb, offset, icd_len, ENC_NA);
proto_item_append_text(icd_item, " (%d bytes)",icd_len);
#ifdef HAVE_LIBGCRYPT_AEAD
if (icv_len) {
aad_len = offset - iv_len - encr_data_len;
aa_data = (guchar *)tvb_memdup(wmem_packet_scope(), tvb, 0, aad_len);
icv_data = (guchar *)tvb_memdup(wmem_packet_scope(), tvb, offset, icv_len);
} else
#endif
if (key_info->auth_spec->gcry_alg) {
proto_item_append_text(icd_item, " <%s>", val_to_str(key_info->auth_spec->number, vs_ikev2_auth_algs, "Unknown mac algo: %d"));
err = gcry_md_open(&md_hd, key_info->auth_spec->gcry_alg, key_info->auth_spec->gcry_flag);
if (err) {
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"IKEv2 hashing error: algorithm %d: gcry_md_open failed: %s",
key_info->auth_spec->gcry_alg, gcry_strerror(err)));
}
err = gcry_md_setkey(md_hd, key_info->auth_key, key_info->auth_spec->key_len);
if (err) {
gcry_md_close(md_hd);
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"IKEv2 hashing error: algorithm %s, key length %u: gcry_md_setkey failed: %s",
gcry_md_algo_name(key_info->auth_spec->gcry_alg), key_info->auth_spec->key_len, gcry_strerror(err)));
}
entire_message = (guchar *)tvb_memdup(wmem_packet_scope(), tvb, 0, offset);
gcry_md_write(md_hd, entire_message, offset);
md = gcry_md_read(md_hd, 0);
md_len = gcry_md_get_algo_dlen(key_info->auth_spec->gcry_alg);
if (md_len < icd_len) {
gcry_md_close(md_hd);
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"IKEv2 hashing error: algorithm %s: gcry_md_get_algo_dlen returned %d which is smaller than icd length %d",
gcry_md_algo_name(key_info->auth_spec->gcry_alg), md_len, icd_len));
}
if (tvb_memeql(tvb, offset, md, icd_len) == 0) {
proto_item_append_text(icd_item, "[correct]");
} else {
proto_item_append_text(icd_item, "[incorrect, should be %s]", bytes_to_str(wmem_packet_scope(), md, icd_len));
expert_add_info(pinfo, icd_item, &ei_isakmp_ikev2_integrity_checksum);
}
gcry_md_close(md_hd);
} else {
proto_item_append_text(icd_item, "[not validated]");
}
}
if (encr_data_len % key_info->encr_spec->block_len != 0) {
proto_item_append_text(encr_data_item, "[Invalid length, should be a multiple of block size (%u)]",
key_info->encr_spec->block_len);
expert_add_info(pinfo, encr_data_item, &ei_isakmp_enc_data_length_mult_block_size);
return NULL;
}
decr_data = (guchar*)wmem_alloc(pinfo->pool, encr_data_len);
decr_data_len = encr_data_len;
if (key_info->encr_spec->number == IKEV2_ENCR_NULL) {
memcpy(decr_data, encr_data, decr_data_len);
} else {
err = gcry_cipher_open(&cipher_hd, key_info->encr_spec->gcry_alg, key_info->encr_spec->gcry_mode, 0);
if (err) {
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"IKEv2 decryption error: algorithm %d, mode %d: gcry_cipher_open failed: %s",
key_info->encr_spec->gcry_alg, key_info->encr_spec->gcry_mode, gcry_strerror(err)));
}
if( key_info->encr_spec->salt_len ) {
int encr_iv_offset = 0;
encr_key_len = key_info->encr_spec->key_len - key_info->encr_spec->salt_len;
encr_iv_len = key_info->encr_spec->salt_len + iv_len;
if (key_info->encr_spec->gcry_mode == GCRY_CIPHER_MODE_CTR) {
encr_iv_len = (int)gcry_cipher_get_algo_blklen(key_info->encr_spec->gcry_alg);
if ((key_info->encr_spec->number >= IKEV2_ENCR_AES_CCM_128_16 && key_info->encr_spec->number <= IKEV2_ENCR_AES_CCM_256_12))
encr_iv_offset = 1;
}
if (encr_key_len < 0 || encr_iv_len < encr_iv_offset + (int)key_info->encr_spec->salt_len + iv_len) {
gcry_cipher_close(cipher_hd);
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"IKEv2 decryption error: algorithm %d, key length %d, salt length %d, input iv length %d, cipher iv length: %d: invalid length(s) of cipher parameters",
key_info->encr_spec->gcry_alg, encr_key_len, key_info->encr_spec->salt_len, iv_len, encr_iv_len));
}
encr_iv = (guchar *)wmem_alloc0(wmem_packet_scope(), encr_iv_len);
memcpy( encr_iv + encr_iv_offset, key_info->encr_key + encr_key_len, key_info->encr_spec->salt_len );
if(iv) {
memcpy( encr_iv + encr_iv_offset + key_info->encr_spec->salt_len, iv, iv_len );
}
if (key_info->encr_spec->gcry_mode == GCRY_CIPHER_MODE_CTR) {
encr_iv[encr_iv_len-1] = 1;
if ((key_info->encr_spec->number >= IKEV2_ENCR_AES_GCM_128_16 && key_info->encr_spec->number <= IKEV2_ENCR_AES_GCM_256_12))
encr_iv[encr_iv_len-1]++;
if ((key_info->encr_spec->number >= IKEV2_ENCR_AES_CCM_128_16 && key_info->encr_spec->number <= IKEV2_ENCR_AES_CCM_256_12))
encr_iv[0] = (guchar)(encr_iv_len - 2 - key_info->encr_spec->salt_len - iv_len);
}
}
err = gcry_cipher_setkey(cipher_hd, key_info->encr_key, encr_key_len);
if (err) {
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"IKEv2 decryption error: algorithm %d, key length %d: gcry_cipher_setkey failed: %s",
key_info->encr_spec->gcry_alg, encr_key_len, gcry_strerror(err)));
}
if (key_info->encr_spec->gcry_mode == GCRY_CIPHER_MODE_CTR)
err = gcry_cipher_setctr(cipher_hd, encr_iv, encr_iv_len);
else
err = gcry_cipher_setiv(cipher_hd, encr_iv, encr_iv_len);
if (err) {
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"IKEv2 decryption error: algorithm %d, iv length %d: gcry_cipher_setiv/gcry_cipher_setctr failed: %s",
key_info->encr_spec->gcry_alg, encr_iv_len, gcry_strerror(err)));
}
#ifdef HAVE_LIBGCRYPT_AEAD
if (key_info->encr_spec->gcry_mode == GCRY_CIPHER_MODE_CCM) {
guint64 ccm_lengths[3];
ccm_lengths[0] = encr_data_len;
ccm_lengths[1] = aad_len;
ccm_lengths[2] = icv_len;
err = gcry_cipher_ctl(cipher_hd, GCRYCTL_SET_CCM_LENGTHS, ccm_lengths, sizeof(ccm_lengths));
if (err) {
gcry_cipher_close(cipher_hd);
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"IKEv2 decryption error: algorithm %d: gcry_cipher_ctl(GCRYCTL_SET_CCM_LENGTHS) failed: %s",
key_info->encr_spec->gcry_alg, gcry_strerror(err)));
}
}
if (aad_len) {
err = gcry_cipher_authenticate(cipher_hd, aa_data, aad_len);
if (err) {
gcry_cipher_close(cipher_hd);
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"IKEv2 decryption error: algorithm %d: gcry_cipher_authenticate failed: %s",
key_info->encr_spec->gcry_alg, gcry_strerror(err)));
}
}
#endif
err = gcry_cipher_decrypt(cipher_hd, decr_data, decr_data_len, encr_data, encr_data_len);
if (err) {
gcry_cipher_close(cipher_hd);
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"IKEv2 decryption error: algorithm %d: gcry_cipher_decrypt failed: %s",
key_info->encr_spec->gcry_alg, gcry_strerror(err)));
}
#ifdef HAVE_LIBGCRYPT_AEAD
if (icv_len) {
guchar *tag;
gint tag_len = icv_len;
if (key_info->encr_spec->gcry_mode == GCRY_CIPHER_MODE_GCM)
tag_len = (int)gcry_cipher_get_algo_blklen(key_info->encr_spec->gcry_alg);
if (tag_len < icv_len) {
gcry_cipher_close(cipher_hd);
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"IKEv2 decryption error: algorithm %d: gcry_cipher_get_algo_blklen returned %d which is smaller than icv length %d",
key_info->encr_spec->gcry_alg, tag_len, icv_len));
}
tag = (guchar *)wmem_alloc(wmem_packet_scope(), tag_len);
err = gcry_cipher_gettag(cipher_hd, tag, tag_len);
if (err) {
gcry_cipher_close(cipher_hd);
REPORT_DISSECTOR_BUG(wmem_strdup_printf(wmem_packet_scope(),
"IKEv2 decryption error: algorithm %d: gcry_cipher_gettag failed: %s",
key_info->encr_spec->gcry_alg, gcry_strerror(err)));
}
else if (memcmp(tag, icv_data, icv_len) == 0)
proto_item_append_text(icd_item, "[correct]");
else {
proto_item_append_text(icd_item, "[incorrect, should be %s]", bytes_to_str(wmem_packet_scope(), tag, icv_len));
expert_add_info(pinfo, icd_item, &ei_isakmp_ikev2_integrity_checksum);
}
}
#endif
gcry_cipher_close(cipher_hd);
}
decr_tvb = tvb_new_child_real_data(tvb, decr_data, decr_data_len, decr_data_len);
add_new_data_source(pinfo, decr_tvb, "Decrypted Data");
item = proto_tree_add_item(tree, hf_isakmp_enc_decrypted_data, decr_tvb, 0, decr_data_len, ENC_NA);
proto_item_append_text(item, " (%d byte%s)", decr_data_len, plurality(decr_data_len, "", "s"));
if (icd_item) {
proto_tree_move_item(tree, item, icd_item);
}
decr_tree = proto_item_add_subtree(item, ett_isakmp_decrypted_data);
pad_len = tvb_get_guint8(decr_tvb, decr_data_len - 1);
payloads_len = decr_data_len - 1 - pad_len;
if (payloads_len > 0) {
item = proto_tree_add_item(decr_tree, hf_isakmp_enc_contained_data, decr_tvb, 0, payloads_len, ENC_NA);
proto_item_append_text(item, " (%d byte%s)", payloads_len, plurality(payloads_len, "", "s"));
decr_payloads_tree = proto_item_add_subtree(item, ett_isakmp_decrypted_payloads);
}
padlen_item = proto_tree_add_item(decr_tree, hf_isakmp_enc_pad_length, decr_tvb, payloads_len + pad_len, 1, ENC_BIG_ENDIAN);
if (pad_len > 0) {
if (payloads_len < 0) {
proto_item_append_text(padlen_item, " [too long]");
expert_add_info(pinfo, padlen_item, &ei_isakmp_enc_pad_length_big);
} else {
item = proto_tree_add_item(decr_tree, hf_isakmp_enc_padding, decr_tvb, payloads_len, pad_len, ENC_NA);
proto_item_append_text(item, " (%d byte%s)", pad_len, plurality(pad_len, "", "s"));
proto_tree_move_item(decr_tree, item, padlen_item);
}
}
if (dissect_payload_now) {
dissect_payloads(decr_tvb, decr_payloads_tree, 2, inner_payload, 0, payloads_len, pinfo, 0, is_request, decr_info);
}
}else{
proto_tree_add_item(tree, hf_isakmp_enc_iv, tvb, offset, 4, ENC_NA);
proto_tree_add_item(tree, hf_isakmp_enc_data, tvb, offset+4 , length, ENC_NA);
}
return decr_tvb;
}
static void
dissect_eap(tvbuff_t *tvb, int offset, int length, proto_tree *tree, packet_info *pinfo)
{
tvbuff_t *eap_tvb;
eap_tvb = tvb_new_subset_length(tvb, offset, length);
if ((eap_tvb != NULL)&& eap_handle != NULL){
call_dissector(eap_handle, eap_tvb, pinfo, tree);
}else{
proto_tree_add_item(tree, hf_isakmp_eap_data, tvb, offset, length, ENC_NA);
}
}
static void
dissect_gspm(tvbuff_t *tvb, int offset, int length, proto_tree *tree)
{
proto_tree_add_item(tree, hf_isakmp_gspm_data, tvb, offset, length, ENC_NA);
}
static guint
isakmp_hash_func(gconstpointer c) {
const guint8 *i_cookie = (const guint8 *) c;
guint val = 0, keychunk, i;
for (i = 0; i < COOKIE_SIZE - (COOKIE_SIZE % (guint)sizeof(keychunk)); i += (guint)sizeof(keychunk)) {
memcpy(&keychunk, &i_cookie[i], sizeof(keychunk));
val ^= keychunk;
}
return val;
}
static gint
isakmp_equal_func(gconstpointer ic1, gconstpointer ic2) {
if (memcmp(ic1, ic2, COOKIE_SIZE) == 0)
return 1;
return 0;
}
static guint ikev2_key_hash_func(gconstpointer k) {
const ikev2_uat_data_key_t *key = (const ikev2_uat_data_key_t*)k;
guint hash, *key_segs;
size_t key_segcount, i;
hash = 0;
key_segcount = key->spii_len / (guint)sizeof(guint);
key_segs = (guint *)key->spii;
for (i = 0; i < key_segcount; i++) {
hash ^= key_segs[i];
}
key_segcount = key->spir_len / (guint)sizeof(guint);
key_segs = (guint *)key->spir;
for (i = 0; i < key_segcount; i++) {
hash ^= key_segs[i];
}
return hash;
}
static gint ikev2_key_equal_func(gconstpointer k1, gconstpointer k2) {
const ikev2_uat_data_key_t *key1 = (const ikev2_uat_data_key_t *)k1;
const ikev2_uat_data_key_t *key2 = (const ikev2_uat_data_key_t *)k2;
if (key1->spii_len != key2->spii_len) return 0;
if (key1->spir_len != key2->spir_len) return 0;
if (memcmp(key1->spii, key2->spii, key1->spii_len) != 0) return 0;
if (memcmp(key1->spir, key2->spir, key1->spir_len) != 0) return 0;
return 1;
}
static void
free_cookie_key(gpointer key_arg)
{
guint8 *ic_key = (guint8 *)key_arg;
g_slice_free1(COOKIE_SIZE, ic_key);
}
static void
free_cookie_value(gpointer value)
{
decrypt_data_t *decr = (decrypt_data_t *)value;
g_hash_table_destroy(decr->iv_hash);
g_slice_free1(sizeof(decrypt_data_t), decr);
}
static void
isakmp_init_protocol(void) {
guint i;
decrypt_data_t *decr;
guint8 *ic_key;
isakmp_hash = g_hash_table_new_full(isakmp_hash_func, isakmp_equal_func,
free_cookie_key, free_cookie_value);
for (i = 0; i < num_ikev1_uat_data; i++) {
ic_key = (guint8 *)g_slice_alloc(COOKIE_SIZE);
memcpy(ic_key, ikev1_uat_data[i].icookie, COOKIE_SIZE);
decr = create_decrypt_data();
memcpy(decr->secret, ikev1_uat_data[i].key, ikev1_uat_data[i].key_len);
decr->secret_len = ikev1_uat_data[i].key_len;
g_hash_table_insert(isakmp_hash, ic_key, decr);
}
ikev2_key_hash = g_hash_table_new(ikev2_key_hash_func, ikev2_key_equal_func);
for (i = 0; i < num_ikev2_uat_data; i++) {
g_hash_table_insert(ikev2_key_hash, &(ikev2_uat_data[i].key), &(ikev2_uat_data[i]));
ikev2_uat_data[i].encr_spec = ikev2_decrypt_find_encr_spec(ikev2_uat_data[i].encr_alg);
ikev2_uat_data[i].auth_spec = ikev2_decrypt_find_auth_spec(ikev2_uat_data[i].auth_alg);
}
defrag_next_payload_hash = g_hash_table_new(g_direct_hash, g_direct_equal);
}
static void
isakmp_cleanup_protocol(void) {
g_hash_table_destroy(isakmp_hash);
g_hash_table_destroy(ikev2_key_hash);
g_hash_table_destroy(defrag_next_payload_hash);
}
static gboolean ikev1_uat_data_update_cb(void* p, char** err) {
ikev1_uat_data_key_t *ud = (ikev1_uat_data_key_t *)p;
if (ud->icookie_len != COOKIE_SIZE) {
*err = g_strdup_printf("Length of Initiator's COOKIE must be %d octets (%d hex characters).", COOKIE_SIZE, COOKIE_SIZE * 2);
return FALSE;
}
if (ud->key_len == 0) {
*err = g_strdup("Must have Encryption key.");
return FALSE;
}
if (ud->key_len > MAX_KEY_SIZE) {
*err = g_strdup_printf("Length of Encryption key limited to %d octets (%d hex characters).", MAX_KEY_SIZE, MAX_KEY_SIZE * 2);
return FALSE;
}
return TRUE;
}
static gboolean ikev2_uat_data_update_cb(void* p, char** err) {
ikev2_uat_data_t *ud = (ikev2_uat_data_t *)p;
if (ud->key.spii_len != COOKIE_SIZE) {
*err = g_strdup_printf("Length of Initiator's SPI must be %d octets (%d hex characters).", COOKIE_SIZE, COOKIE_SIZE * 2);
return FALSE;
}
if (ud->key.spir_len != COOKIE_SIZE) {
*err = g_strdup_printf("Length of Responder's SPI must be %d octets (%d hex characters).", COOKIE_SIZE, COOKIE_SIZE * 2);
return FALSE;
}
if ((ud->encr_spec = ikev2_decrypt_find_encr_spec(ud->encr_alg)) == NULL) {
REPORT_DISSECTOR_BUG("Couldn't get IKEv2 encryption algorithm spec.");
}
if ((ud->auth_spec = ikev2_decrypt_find_auth_spec(ud->auth_alg)) == NULL) {
REPORT_DISSECTOR_BUG("Couldn't get IKEv2 authentication algorithm spec.");
}
if (ud->encr_spec->icv_len && ud->auth_spec->number != IKEV2_AUTH_NONE) {
*err = g_strdup_printf("Selected encryption_algorithm %s requires selecting NONE integrity algorithm.",
val_to_str(ud->encr_spec->number, vs_ikev2_encr_algs, "other-%d"));
return FALSE;
}
if (ud->sk_ei_len != ud->encr_spec->key_len) {
*err = g_strdup_printf("Length of SK_ei (%u octets) does not match the key length (%u octets) of the selected encryption algorithm.",
ud->sk_ei_len, ud->encr_spec->key_len);
return FALSE;
}
if (ud->sk_er_len != ud->encr_spec->key_len) {
*err = g_strdup_printf("Length of SK_er (%u octets) does not match the key length (%u octets) of the selected encryption algorithm.",
ud->sk_er_len, ud->encr_spec->key_len);
return FALSE;
}
if (ud->sk_ai_len != ud->auth_spec->key_len) {
*err = g_strdup_printf("Length of SK_ai (%u octets) does not match the key length (%u octets) of the selected integrity algorithm.",
ud->sk_ai_len, ud->auth_spec->key_len);
return FALSE;
}
if (ud->sk_ar_len != ud->auth_spec->key_len) {
*err = g_strdup_printf("Length of SK_ar (%u octets) does not match the key length (%u octets) of the selected integrity algorithm.",
ud->sk_ar_len, ud->auth_spec->key_len);
return FALSE;
}
return TRUE;
}
void
proto_register_isakmp(void)
{
module_t *isakmp_module;
static hf_register_info hf[] = {
{ &hf_isakmp_ispi,
{ "Initiator SPI", "isakmp.ispi",
FT_BYTES, BASE_NONE, NULL, 0x0,
"ISAKMP Initiator SPI", HFILL }},
{ &hf_isakmp_rspi,
{ "Responder SPI", "isakmp.rspi",
FT_BYTES, BASE_NONE, NULL, 0x0,
"ISAKMP Responder SPI", HFILL }},
{ &hf_isakmp_typepayload,
{ "Payload", "isakmp.typepayload",
FT_UINT8,BASE_RANGE_STRING | BASE_DEC, RVALS(payload_type), 0x0,
"ISAKMP Payload Type", HFILL }},
{ &hf_isakmp_nextpayload,
{ "Next payload", "isakmp.nextpayload",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(payload_type), 0x0,
"ISAKMP Next Payload", HFILL }},
{ &hf_isakmp_criticalpayload,
{ "Critical Bit", "isakmp.criticalpayload",
FT_BOOLEAN, 8,TFS(&criticalpayload), 0x80,
"IKEv2 Critical Payload", HFILL }},
{ &hf_isakmp_reserved7,
{ "Reserved", "isakmp.reserved7",
FT_UINT8, BASE_HEX, NULL, 0x7F,
NULL, HFILL }},
{ &hf_isakmp_reserved,
{ "Reserved", "isakmp.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_extradata,
{ "Extra data", "isakmp.extradata",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Extra data ??????", HFILL }},
{ &hf_isakmp_datapayload,
{ "Data Payload", "isakmp.datapayload",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Data Payload (not dissect)", HFILL }},
{ &hf_isakmp_version,
{ "Version", "isakmp.version",
FT_UINT8, BASE_HEX, NULL, 0x0,
"ISAKMP Version (major + minor)", HFILL }},
{ &hf_isakmp_mjver,
{ "MjVer", "isakmp.mjver",
FT_UINT8, BASE_HEX, NULL, 0xF0,
"ISAKMP MjVer", HFILL }},
{ &hf_isakmp_mnver,
{ "MnVer", "isakmp.mnver",
FT_UINT8, BASE_HEX, NULL, 0x0F,
"ISAKMP MnVer", HFILL }},
{ &hf_isakmp_exchangetype_v1,
{ "Exchange type", "isakmp.exchangetype",
FT_UINT8, BASE_DEC, VALS(exchange_v1_type), 0x0,
"ISAKMP Exchange Type", HFILL }},
{ &hf_isakmp_exchangetype_v2,
{ "Exchange type", "isakmp.exchangetype",
FT_UINT8, BASE_DEC, VALS(exchange_v2_type), 0x0,
"ISAKMP Exchange Type", HFILL }},
{ &hf_isakmp_flags,
{ "Flags", "isakmp.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"ISAKMP Flags", HFILL }},
{ &hf_isakmp_flag_e,
{ "Encryption", "isakmp.flag_e",
FT_BOOLEAN, 8, TFS(&flag_e), E_FLAG,
"Encryption Bit", HFILL }},
{ &hf_isakmp_flag_c,
{ "Commit", "isakmp.flag_c",
FT_BOOLEAN, 8, TFS(&flag_c), C_FLAG,
"Commit Bit", HFILL }},
{ &hf_isakmp_flag_a,
{ "Authentication", "isakmp.flag_a",
FT_BOOLEAN, 8, TFS(&flag_a), A_FLAG,
"Authentication Bit", HFILL }},
{ &hf_isakmp_flag_i,
{ "Initiator", "isakmp.flag_i",
FT_BOOLEAN, 8, TFS(&flag_i), I_FLAG,
"Initiator Bit", HFILL }},
{ &hf_isakmp_flag_v,
{ "Version", "isakmp.flag_v",
FT_BOOLEAN, 8, TFS(&flag_v), V_FLAG,
"Version Bit", HFILL }},
{ &hf_isakmp_flag_r,
{ "Response", "isakmp.flag_r",
FT_BOOLEAN, 8, TFS(&flag_r), R_FLAG,
"Response Bit", HFILL }},
{ &hf_isakmp_messageid,
{ "Message ID", "isakmp.messageid",
FT_UINT32, BASE_HEX, NULL, 0x0,
"ISAKMP Message ID", HFILL }},
{ &hf_isakmp_length,
{ "Length", "isakmp.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"ISAKMP Length", HFILL }},
{ &hf_isakmp_payloadlen,
{ "Payload length", "isakmp.payloadlength",
FT_UINT16, BASE_DEC, NULL, 0x0,
"ISAKMP Payload Length", HFILL }},
{ &hf_isakmp_sa_doi,
{ "Domain of interpretation", "isakmp.sa.doi",
FT_UINT32, BASE_DEC, VALS(doi_type), 0x0,
"ISAKMP Domain of Interpretation", HFILL }},
{ &hf_isakmp_sa_situation,
{ "Situation", "isakmp.sa.situation",
FT_BYTES, BASE_NONE, NULL, 0x0,
"ISAKMP SA Situation", HFILL }},
{ &hf_isakmp_sa_situation_identity_only,
{ "Identity Only", "isakmp.sa.situation.identity_only",
FT_BOOLEAN, 32, NULL, SIT_IDENTITY_ONLY,
"The type specifies that the SA will be identified by source identity information present in an associated Identification Payload", HFILL }},
{ &hf_isakmp_sa_situation_secrecy,
{ "Secrecy", "isakmp.sa.situation.secrecy",
FT_BOOLEAN, 32, NULL, SIT_SECRECY,
"The type specifies that the SA is being negotiated in an environment that requires labeled secrecy.", HFILL }},
{ &hf_isakmp_sa_situation_integrity,
{ "Integrity", "isakmp.sa.situation.integrity",
FT_BOOLEAN, 32, NULL, SIT_INTEGRITY,
"The type specifies that the SA is being negotiated in an environment that requires labeled integrity", HFILL }},
{ &hf_isakmp_prop_protoid_v1,
{ "Protocol ID", "isakmp.prop.protoid",
FT_UINT32, BASE_DEC, VALS(protoid_v1_type), 0x0,
"ISAKMP Proposal Protocol ID", HFILL }},
{ &hf_isakmp_prop_protoid_v2,
{ "Protocol ID", "isakmp.prop.protoid",
FT_UINT32, BASE_DEC, VALS(protoid_v2_type), 0x0,
"IKEv2 Proposal Protocol ID", HFILL }},
{ &hf_isakmp_prop_number,
{ "Proposal number", "isakmp.prop.number",
FT_UINT8, BASE_DEC, NULL, 0x0,
"ISAKMP Proposal Number", HFILL }},
{ &hf_isakmp_spisize,
{ "SPI Size", "isakmp.spisize",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_spi,
{ "SPI", "isakmp.spi",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_prop_transforms,
{ "Proposal transforms", "isakmp.prop.transforms",
FT_UINT8, BASE_DEC, NULL, 0x0,
"ISAKMP Proposal Transforms", HFILL }},
{ &hf_isakmp_trans_number,
{ "Transform number", "isakmp.trans.number",
FT_UINT8, BASE_DEC, NULL, 0x0,
"ISAKMP Transform Number", HFILL }},
{ &hf_isakmp_trans_id,
{ "Transform ID", "isakmp.trans.id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"ISAKMP Transform ID", HFILL }},
{ &hf_isakmp_id_type_v1,
{ "ID type", "isakmp.id.type",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(vs_v1_id_type), 0x0,
"IKEv1 ID Type", HFILL }},
{ &hf_isakmp_id_type_v2,
{ "ID type", "isakmp.id.type",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(vs_v2_id_type), 0x0,
"IKEv2 ID Type", HFILL }},
{ &hf_isakmp_id_protoid,
{ "Protocol ID", "isakmp.id.protoid",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &ipproto_val_ext, 0x0,
"ISAKMP ID Protocol ID", HFILL }},
{ &hf_isakmp_id_port,
{ "Port", "isakmp.id.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
"ISAKMP ID Port", HFILL }},
{ &hf_isakmp_id_data,
{ "Identification Data:", "isakmp.id.data",
FT_NONE, BASE_NONE, NULL, 0x0,
"ISAKMP ID Data", HFILL }},
{ &hf_isakmp_id_data_ipv4_addr,
{ "ID_IPV4_ADDR", "isakmp.id.data.ipv4_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
"The type specifies a single four (4) octet IPv4 address", HFILL }},
{ &hf_isakmp_id_data_fqdn,
{ "ID_FQDN", "isakmp.id.data.fqdn",
FT_STRING, BASE_NONE, NULL, 0x0,
"The type specifies a fully-qualified domain name string", HFILL }},
{ &hf_isakmp_id_data_user_fqdn,
{ "ID_FQDN", "isakmp.id.data.user_fqdn",
FT_STRING, BASE_NONE, NULL, 0x0,
"The type specifies a fully-qualified username string", HFILL }},
{ &hf_isakmp_id_data_ipv4_subnet,
{ "ID_IPV4_SUBNET", "isakmp.id.data.ipv4_subnet",
FT_IPv4, BASE_NONE, NULL, 0x0,
"The second is an IPv4 network mask", HFILL }},
{ &hf_isakmp_id_data_ipv4_range_start,
{ "ID_IPV4_SUBNET", "isakmp.id.data.ipv4_range_start",
FT_IPv4, BASE_NONE, NULL, 0x0,
"The first value is the beginning IPv4 address (inclusive)", HFILL }},
{ &hf_isakmp_id_data_ipv4_range_end,
{ "ID_IPV4_RANGE (End)", "isakmp.id.data.ipv4_range_end",
FT_IPv4, BASE_NONE, NULL, 0x0,
"The second value is the ending IPv4 address (inclusive)", HFILL }},
{ &hf_isakmp_id_data_ipv6_addr,
{ "ID_IPV6_ADDR", "isakmp.id.data.ipv6_addr",
FT_IPv6, BASE_NONE, NULL, 0x0,
"The type specifies a single sixteen (16) octet IPv6 address", HFILL }},
{ &hf_isakmp_id_data_ipv6_subnet,
{ "ID_IPV6A_ADDR_SUBNET", "isakmp.id.data.ipv6_subnet",
FT_IPv6, BASE_NONE, NULL, 0x0,
"The type specifies a range of IPv6 addresses represented by two sixteen (16) octet values", HFILL }},
{ &hf_isakmp_id_data_ipv6_range_start,
{ "ID_IPV6_ADDR_RANGE (Start)", "isakmp.id.data.ipv6_range_start",
FT_IPv6, BASE_NONE, NULL, 0x0,
"The first value is the beginning IPv6 address (inclusive)", HFILL }},
{ &hf_isakmp_id_data_ipv6_range_end,
{ "ID_IPV6_ADDR_RANGE (End)", "isakmp.id.data.ipv6_range_end",
FT_IPv6, BASE_NONE, NULL, 0x0,
"the second value is the ending IPv6 address (inclusive)", HFILL }},
{ &hf_isakmp_id_data_key_id,
{ "ID_KEY_ID", "isakmp.id.data.key_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
"The type specifies an opaque byte stream which may be used to pass vendor-specific information necessary to identify which pre-shared key should be used to authenticate Aggressive mode negotiations", HFILL }},
{ &hf_isakmp_id_data_cert,
{ "ID_DER_ASN1_DN", "isakmp.id.data.der_asn1_dn",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_isakmp_cert_encoding_v1,
{ "Certificate Encoding", "isakmp.cert.encoding",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(cert_v1_type), 0x0,
"ISAKMP Certificate Encoding", HFILL }},
{ &hf_isakmp_cert_encoding_v2,
{ "Certificate Encoding", "isakmp.cert.encoding",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(cert_v2_type), 0x0,
"IKEv2 Certificate Encoding", HFILL }},
{ &hf_isakmp_cert_data,
{ "Certificate Data", "isakmp.cert.data",
FT_NONE, BASE_NONE, NULL, 0x0,
"ISAKMP Certificate Data", HFILL }},
{ &hf_isakmp_cert_x509_hash,
{ "Hash", "isakmp.cert.x509.hash",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_cert_x509_url,
{ "URL", "isakmp.cert.x509.url",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_certreq_type_v1,
{ "Certificate Type", "isakmp.certreq.type",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(cert_v1_type), 0x0,
"ISAKMP Certificate Type", HFILL }},
{ &hf_isakmp_certreq_type_v2,
{ "Certificate Type", "isakmp.certreq.type",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(cert_v2_type), 0x0,
"IKEv2 Certificate Type", HFILL }},
{ &hf_isakmp_auth_meth,
{ "Authentication Method", "isakmp.auth.method",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(authmeth_v2_type), 0x0,
"IKEv2 Authentication Method", HFILL }},
{ &hf_isakmp_auth_data,
{ "Authentication Data", "isakmp.auth.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"IKEv2 Authentication Data", HFILL }},
{ &hf_isakmp_notify_doi,
{ "Domain of interpretation", "isakmp.notify.doi",
FT_UINT32, BASE_DEC, VALS(doi_type), 0x0,
"ISAKMP Notify Domain of Interpretation", HFILL }},
{ &hf_isakmp_notify_protoid_v1,
{ "Protocol ID", "isakmp.notify.protoid",
FT_UINT32, BASE_DEC, VALS(protoid_v1_type), 0x0,
"ISAKMP Notify Protocol ID", HFILL }},
{ &hf_isakmp_notify_protoid_v2,
{ "Protocol ID", "isakmp.notify.protoid",
FT_UINT32, BASE_DEC, VALS(protoid_v2_type), 0x0,
"IKEv2 Notify Protocol ID", HFILL }},
{ &hf_isakmp_notify_msgtype_v1,
{ "Notify Message Type", "isakmp.notify.msgtype",
FT_UINT16, BASE_RANGE_STRING | BASE_DEC, RVALS(notifmsg_v1_type), 0x0,
"ISAKMP Notify Message Type", HFILL }},
{ &hf_isakmp_notify_msgtype_v2,
{ "Notify Message Type", "isakmp.notify.msgtype",
FT_UINT16, BASE_RANGE_STRING | BASE_DEC, RVALS(notifmsg_v2_type), 0x0,
"ISAKMP Notify Message Type", HFILL }},
{ &hf_isakmp_notify_data,
{ "Notification DATA", "isakmp.notify.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_dpd_are_you_there,
{ "DPD ARE-YOU-THERE sequence", "isakmp.notify.data.dpd.are_you_there",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_dpd_are_you_there_ack,
{ "DPD ARE-YOU-THERE-ACK sequence", "isakmp.notify.data.dpd.are_you_there_ack",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_unity_load_balance,
{ "UNITY LOAD BALANCE", "isakmp.notify.data.unity.load_balance",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_ipcomp_cpi,
{ "IPCOMP CPI", "isakmp.notify.data.ipcomp.cpi",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_ipcomp_transform_id,
{ "IPCOMP Transform ID", "isakmp.notify.data.ipcomp.transform_id",
FT_UINT8, BASE_DEC, VALS(transform_id_ipcomp), 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_redirect_gw_ident_type,
{ "Gateway Identity Type", "isakmp.notify.data.redirect.gw_ident.type",
FT_UINT8, BASE_DEC, VALS(redirect_gateway_identity_type), 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_redirect_gw_ident_len,
{ "Gateway Identity Length", "isakmp.notify.data.redirect.gw_ident.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_redirect_new_resp_gw_ident_ipv4,
{ "New Responder Gateway Identity (IPv4)", "isakmp.notify.data.redirect.new_resp_gw_ident.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_redirect_new_resp_gw_ident_ipv6,
{ "New Responder Gateway Identity (IPv6)", "isakmp.notify.data.redirect.new_resp_gw_ident.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_redirect_new_resp_gw_ident_fqdn,
{ "New Responder Gateway Identity (FQDN)", "isakmp.notify.data.redirect.new_resp_gw_ident.fqdn",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_redirect_new_resp_gw_ident,
{ "New Responder Gateway Identity (DATA)", "isakmp.notify.data.redirect.new_resp_gw_ident.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_redirect_nonce_data,
{ "Redirect Nonce Data", "isakmp.notify.data.redirect.nonce_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_redirect_org_resp_gw_ident_ipv4,
{ "Original Responder Gateway Identity (IPv4)", "isakmp.notify.data.redirect.org_resp_gw_ident.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_redirect_org_resp_gw_ident_ipv6,
{ "Original Responder Gateway Identity (IPv6)", "isakmp.notify.data.redirect.org_resp_gw_ident.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_redirect_org_resp_gw_ident,
{ "Original Responder Gateway Identity (DATA)", "isakmp.notify.data.redirect.org_resp_gw_ident.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_ticket_lifetime,
{ "TICKET OPAQUE Lifetime", "isakmp.notify.data.ticket_opaque.lifetime",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The Lifetime field contains a relative time value, the number of seconds until the ticket expires (encoded as an unsigned integer).", HFILL }},
{ &hf_isakmp_notify_data_ticket_data,
{ "TICKET OPAQUE Data", "isakmp.notify.data.ticket_opaque.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_rohc_attr.all,
{ "ROHC Attribute Type", "isakmp.notify.data.rohc.attr",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_notify_data_rohc_attr.type,
{ "ROHC Attribute Type", "isakmp.notify.data.rohc.attr.type",
FT_UINT16, BASE_RANGE_STRING | BASE_DEC, VALS(rohc_attr_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_notify_data_rohc_attr.format,
{ "ROHC Format", "isakmp.notify.data.rohc.attr.format",
FT_BOOLEAN, 16, TFS(&attribute_format), 0x8000,
NULL, HFILL }},
{ &hf_isakmp_notify_data_rohc_attr.length,
{ "Length", "isakmp.notify.data.rohc.attr.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_notify_data_rohc_attr.value,
{ "Value", "isakmp.notify.data.rohc.attr.value",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_notify_data_rohc_attr_max_cid,
{ "Maximum Context Identifier", "isakmp.notify.data.rohc.attr.max_cid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_notify_data_rohc_attr_profile,
{ "ROHC Profile", "isakmp.notify.data.rohc.attr.profile",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_notify_data_rohc_attr_integ,
{ "ROHC Integrity Algorithm", "isakmp.notify.data.rohc.attr.integ",
FT_UINT16, BASE_DEC, VALS(transform_ike2_integ_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_notify_data_rohc_attr_icv_len,
{ "ROHC ICV Length in bytes", "isakmp.notify.data.rohc.attr.icv_len",
FT_UINT16, BASE_DEC, NULL, 0x00,
"In bytes", HFILL }},
{ &hf_isakmp_notify_data_rohc_attr_mrru,
{ "MRRU", "isakmp.notify.data.rohc.attr.mrru",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_notify_data_qcd_token_secret_data,
{ "Token Secret Data", "isakmp.notify.data.qcd.token_secret_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_ha_nonce_data,
{ "Nonce Data", "isakmp.notify.data.ha.nonce_data",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Random nonce data, the data should be identical in the synchronization request and response", HFILL }},
{ &hf_isakmp_notify_data_ha_expected_send_req_msg_id,
{ "EXPECTED SEND REQ MESSAGE ID", "isakmp.notify.data.ha.expected_send_req_message_id",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Indicate the Message ID it will use in the next request that it will send to the other protocol peer", HFILL }},
{ &hf_isakmp_notify_data_ha_expected_recv_req_msg_id,
{ "EXPECTED RECV REQ MESSAGE ID", "isakmp.notify.data.ha.expected_recv_req_message_id",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Indicate the Message ID it is expecting in the next request to be received from the other protocol peer", HFILL }},
{ &hf_isakmp_notify_data_ha_incoming_ipsec_sa_delta_value,
{ "Incoming IPsec SA delta value", "isakmp.notify.data.ha.incoming_ipsec_sa_delta_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
"The sender requests that the peer should increment all the Child SA Replay Counters for the sender's incomingtraffic by this value", HFILL }},
{ &hf_isakmp_notify_data_secure_password_methods,
{ "Secure Password Methods", "isakmp.notify.data.secure_password_methods",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_delete_doi,
{ "Domain of interpretation", "isakmp.delete.doi",
FT_UINT32, BASE_DEC, VALS(doi_type), 0x0,
"ISAKMP Delete Domain of Interpretation", HFILL }},
{ &hf_isakmp_delete_protoid_v1,
{ "Protocol ID", "isakmp.delete.protoid",
FT_UINT32, BASE_DEC, VALS(protoid_v1_type), 0x0,
"ISAKMP Delete Protocol ID", HFILL }},
{ &hf_isakmp_delete_protoid_v2,
{ "Protocol ID", "isakmp.delete.protoid",
FT_UINT32, BASE_DEC, VALS(protoid_v2_type), 0x0,
"IKEv2 Delete Protocol ID", HFILL }},
{ &hf_isakmp_delete_spi,
{ "Delete SPI", "isakmp.delete.spi",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Identifies the specific security association(s) to delete", HFILL }},
{ &hf_isakmp_vid_bytes,
{ "Vendor ID", "isakmp.vid_bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_vid_string,
{ "Vendor ID", "isakmp.vid_string",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_vid_cp_product,
{ "Checkpoint Product", "isakmp.vid.cp.product",
FT_UINT32, BASE_DEC, VALS(cp_product), 0x0,
NULL, HFILL }},
{ &hf_isakmp_vid_cp_version,
{ "Checkpoint Version", "isakmp.vid.cp.version",
FT_UINT32, BASE_DEC, VALS(cp_version), 0x0,
"Encoded Version number", HFILL }},
{ &hf_isakmp_vid_cp_timestamp,
{ "Checkpoint Timestamp", "isakmp.vid.cp.timestamp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Timestamp (NGX only; always zero in 4.1 or NG)", HFILL }},
{ &hf_isakmp_vid_cp_reserved,
{ "Checkpoint Reserved", "isakmp.vid.cp.reserved",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_vid_cp_features,
{ "Checkpoint Features", "isakmp.vid.cp.features",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_vid_cisco_unity_major,
{ "CISCO-UNITY Major version", "isakmp.vid.cisco_unity.major",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_vid_cisco_unity_minor,
{ "CISCO-UNITY Minor version", "isakmp.vid.cisco_unity.minor",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_vid_ms_nt5_isakmpoakley,
{ "MS NT5 ISAKMPOAKLEY", "isakmp.vid.ms_nt5_isakmpoakley",
FT_UINT32, BASE_DEC, VALS(ms_nt5_isakmpoakley_type), 0x0,
NULL, HFILL }},
{ &hf_isakmp_vid_aruba_via_auth_profile,
{ "Auth Profile", "isakmp.vid.aruba_via_auth_profile",
FT_STRING, BASE_NONE, NULL, 0x0,
"Aruba Networks Auth Profile for VIA Client", HFILL }},
{ &hf_isakmp_vid_fortinet_fortigate_release,
{ "Release", "isakmp.vid.fortinet.fortigate.release",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Release of Fortigate", HFILL }},
{ &hf_isakmp_vid_fortinet_fortigate_build,
{ "Build", "isakmp.vid.fortinet.fortigate.build",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Build of Fortigate", HFILL }},
{ &hf_isakmp_ts_number_of_ts,
{ "Number of Traffic Selectors", "isakmp.ts.number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_type,
{ "Traffic Selector Type", "isakmp.ts.type",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(traffic_selector_type), 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_protoid,
{ "Protocol ID", "isakmp.ts.protoid",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &ipproto_val_ext, 0x0,
"IKEv2 Traffic Selector Protocol ID", HFILL }},
{ &hf_isakmp_ts_selector_length,
{ "Selector Length", "isakmp.ts.selector_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_start_port,
{ "Start Port", "isakmp.ts.start_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_end_port,
{ "End Port", "isakmp.ts.end_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_start_addr_ipv4,
{ "Starting Addr", "isakmp.ts.start_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_end_addr_ipv4,
{ "Ending Addr", "isakmp.ts.end_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_start_addr_ipv6,
{ "Starting Addr", "isakmp.ts.start_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_end_addr_ipv6,
{ "Ending Addr", "isakmp.ts.end_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_start_addr_fc,
{ "Starting Addr", "isakmp.ts.start_fc",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_end_addr_fc,
{ "Ending Addr", "isakmp.ts.end_fc",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_start_r_ctl,
{ "Starting R_CTL", "isakmp.ts.start_r_ctl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_end_r_ctl,
{ "Ending R_CTL", "isakmp.ts.end_r_ctl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_start_type,
{ "Starting Type", "isakmp.ts.start_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_end_type,
{ "Ending Type", "isakmp.ts.end_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_data,
{ "Traffic Selector", "isakmp.ts.data",
FT_NONE, BASE_NONE, NULL, 0x0,
"An individual traffic selector", HFILL }},
{ &hf_isakmp_num_spis,
{ "Number of SPIs", "isakmp.spinum",
FT_UINT16, BASE_DEC, NULL, 0x0,
"ISAKMP Number of SPIs", HFILL }},
{ &hf_isakmp_hash,
{ "Hash DATA", "isakmp.hash",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_sig,
{ "Signature DATA", "isakmp.sig",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_nonce,
{ "Nonce DATA", "isakmp.nonce",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ike2_fragment_number,
{ "Fragment Number", "isakmp.frag.number",
FT_UINT16, BASE_DEC, NULL, 0x0,
"ISAKMP fragment number", HFILL }},
{ &hf_isakmp_ike2_total_fragments,
{ "Total Fragments", "isakmp.frag.total",
FT_UINT16, BASE_DEC, NULL, 0x0,
"ISAKMP total number of fragments", HFILL }},
{ &hf_isakmp_cisco_frag_packetid,
{ "Frag ID", "isakmp.frag.packetid",
FT_UINT16, BASE_HEX, NULL, 0x0,
"ISAKMP fragment packet-id", HFILL }},
{ &hf_isakmp_cisco_frag_seq,
{ "Frag seq", "isakmp.frag.seq",
FT_UINT8, BASE_DEC, NULL, 0x0,
"ISAKMP fragment number", HFILL }},
{ &hf_isakmp_cisco_frag_last,
{ "Frag last", "isakmp.frag.last",
FT_UINT8, BASE_DEC, VALS(frag_last_vals), 0x0,
"ISAKMP last fragment", HFILL }},
{ &hf_isakmp_fragments,
{"Message fragments", "isakmp.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_isakmp_fragment,
{"Message fragment", "isakmp.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_isakmp_fragment_overlap,
{"Message fragment overlap", "isakmp.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_isakmp_fragment_overlap_conflicts,
{"Message fragment overlapping with conflicting data",
"isakmp.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_isakmp_fragment_multiple_tails,
{"Message has multiple tail fragments",
"isakmp.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_isakmp_fragment_too_long_fragment,
{"Message fragment too long", "isakmp.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_isakmp_fragment_error,
{"Message defragmentation error", "isakmp.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_isakmp_fragment_count,
{"Message fragment count", "isakmp.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_isakmp_reassembled_in,
{"Reassembled in", "isakmp.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_isakmp_reassembled_length,
{"Reassembled ISAKMP length", "isakmp.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_isakmp_certreq_authority_sig,
{ "Certificate Authority Signature", "isakmp.ike.certreq.authority.sig",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_isakmp_certreq_authority_v1,
{ "Certificate Authority Data", "isakmp.ike.certreq.authority",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_isakmp_certreq_authority_v2,
{ "Certificate Authority Data", "isakmp.ike.certreq.authority",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SHA-1 hash of the Certificate Authority", HFILL } },
{ &hf_isakmp_nat_keepalive,
{ "NAT Keepalive", "isakmp.ike.nat_keepalive",
FT_NONE, BASE_NONE, NULL, 0x0, "NAT Keepalive packet", HFILL } },
{ &hf_isakmp_nat_hash,
{ "HASH of the address and port", "isakmp.ike.nat_hash",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_nat_original_address_ipv4,
{ "NAT Original IPv4 Address", "isakmp.ike.nat_original_address_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_nat_original_address_ipv6,
{ "NAT Original IPv6 Address", "isakmp.ike.nat_original_address_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr.all,
{ "IPsec Attribute", "isakmp.ipsec.attr",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr.type,
{ "Type", "isakmp.ipsec.attr.type",
FT_UINT16, BASE_RANGE_STRING | BASE_DEC, VALS(ipsec_attr_type), 0x00,
"IPsec Attribute type", HFILL }},
{ &hf_isakmp_ipsec_attr.format,
{ "Format", "isakmp.ipsec.attr.format",
FT_BOOLEAN, 16, TFS(&attribute_format), 0x8000,
"IPsec Attribute format", HFILL }},
{ &hf_isakmp_ipsec_attr.length,
{ "Length", "isakmp.ipsec.attr.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
"IPsec Attribute length", HFILL }},
{ &hf_isakmp_ipsec_attr.value,
{ "Value", "isakmp.ipsec.attr.value",
FT_BYTES, BASE_NONE, NULL, 0x00,
"IPsec Attribute value", HFILL }},
{ &hf_isakmp_ipsec_attr_life_type,
{ "Life Type", "isakmp.ipsec.attr.life_type",
FT_UINT16, BASE_DEC, VALS(attr_life_type), 0x00,
"The unit (seconds or kilobytes) of the associated Life Duration attribute.", HFILL }},
{ &hf_isakmp_ipsec_attr_life_duration_uint32,
{ "Life Duration", "isakmp.ipsec.attr.life_duration",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr_life_duration_uint64,
{ "Life Duration", "isakmp.ipsec.attr.life_duration64",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr_life_duration_bytes,
{ "Life Duration", "isakmp.ipsec.attr.life_duration_bytes",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr_group_description,
{ "Group Description", "isakmp.ipsec.attr.group_description",
FT_UINT16, BASE_DEC, VALS(dh_group), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr_encap_mode,
{ "Encapsulation Mode", "isakmp.ipsec.attr.encap_mode",
FT_UINT16, BASE_DEC, VALS(ipsec_attr_encap_mode), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr_auth_algorithm,
{ "Authentication Algorithm", "isakmp.ipsec.attr.auth_algorithm",
FT_UINT16, BASE_DEC, VALS(ipsec_attr_auth_algo), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr_key_length,
{ "Key Length", "isakmp.ipsec.attr.key_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr_key_rounds,
{ "Key Rounds", "isakmp.ipsec.attr.key_rounds",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr_cmpr_dict_size,
{ "Compress Dictionary Size", "isakmp.ipsec.attr.cmpr_dict_size",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr_cmpr_algorithm,
{ "Compress Private Algorithm", "isakmp.ipsec.attr.cmpr_algorithm",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr_ecn_tunnel,
{ "ECN Tunnel", "isakmp.ipsec.attr.ecn_tunnel",
FT_UINT16, BASE_DEC, VALS(ipsec_attr_ecn_tunnel), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr_ext_seq_nbr,
{ "Extended (64-bit) Sequence Number", "isakmp.ipsec.attr.ext_seq_nbr",
FT_UINT16, BASE_DEC, VALS(ipsec_attr_ext_seq_nbr), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr_auth_key_length,
{ "Authentication Key Length", "isakmp.ipsec.attr.auth_key_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr_sig_enco_algorithm,
{ "Signature Encoding Algorithm", "isakmp.ipsec.attr.sig_enco_algorithm",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr_addr_preservation,
{ "Address Preservation", "isakmp.ipsec.attr.addr_preservation",
FT_UINT16, BASE_DEC, VALS(ipsec_attr_addr_preservation), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ipsec_attr_sa_direction,
{ "SA Direction", "isakmp.ipsec.attr.sa_direction",
FT_UINT16, BASE_DEC, VALS(ipsec_attr_sa_direction), 0x00,
NULL, HFILL }},
{ &hf_isakmp_resp_lifetime_ipsec_attr.all,
{ "IPsec Attribute", "isakmp.notify.data.resp_lifetime.ipsec.attr",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_resp_lifetime_ipsec_attr.type,
{ "Type", "isakmp.notify.data.resp_lifetime.ipsec.attr.type",
FT_UINT16, BASE_RANGE_STRING | BASE_DEC, VALS(ipsec_attr_type), 0x00,
"IPsec Attribute type", HFILL }},
{ &hf_isakmp_resp_lifetime_ipsec_attr.format,
{ "Format", "isakmp.notify.data.resp_lifetime.ipsec.attr.format",
FT_BOOLEAN, 16, TFS(&attribute_format), 0x8000,
"IPsec Attribute format", HFILL }},
{ &hf_isakmp_resp_lifetime_ipsec_attr.length,
{ "Length", "isakmp.notify.data.resp_lifetime.ipsec.attr.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
"IPsec Attribute length", HFILL }},
{ &hf_isakmp_resp_lifetime_ipsec_attr.value,
{ "Value", "isakmp.notify.data.resp_lifetime.ipsec.attr.value",
FT_BYTES, BASE_NONE, NULL, 0x00,
"IPsec Attribute value", HFILL }},
{ &hf_isakmp_resp_lifetime_ipsec_attr_life_type,
{ "Life Type", "isakmp.notify.data.resp_lifetime.ipsec.attr.life_type",
FT_UINT16, BASE_DEC, VALS(attr_life_type), 0x00,
"The unit (seconds or kilobytes) of the associated Life Duration attribute.", HFILL }},
{ &hf_isakmp_resp_lifetime_ipsec_attr_life_duration_uint32,
{ "Life Duration", "isakmp.notify.data.resp_lifetime.ipsec.attr.life_duration",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_resp_lifetime_ipsec_attr_life_duration_uint64,
{ "Life Duration", "isakmp.notify.data.resp_lifetime.ipsec.attr.life_duration64",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_resp_lifetime_ipsec_attr_life_duration_bytes,
{ "Life Duration", "isakmp.notify.data.resp_lifetime.ipsec.attr.life_duration_bytes",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr.all,
{ "IKE Attribute", "isakmp.ike.attr",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr.type,
{ "Type", "isakmp.ike.attr.type",
FT_UINT16, BASE_RANGE_STRING | BASE_DEC, VALS(ike_attr_type), 0x00,
"IKEv1 Attribute type", HFILL }},
{ &hf_isakmp_ike_attr.format,
{ "Format", "isakmp.ike.attr.format",
FT_BOOLEAN, 16, TFS(&attribute_format), 0x8000,
"IKEv1 Attribute format", HFILL }},
{ &hf_isakmp_ike_attr.length,
{ "Length", "isakmp.ike.attr.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
"IKEv1 Attribute length", HFILL }},
{ &hf_isakmp_ike_attr.value,
{ "Value", "isakmp.ike.attr.value",
FT_BYTES, BASE_NONE, NULL, 0x00,
"IKEv1 Attribute value", HFILL }},
{ &hf_isakmp_ike_attr_encryption_algorithm,
{ "Encryption Algorithm", "isakmp.ike.attr.encryption_algorithm",
FT_UINT16, BASE_DEC, VALS(ike_attr_enc_algo), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_hash_algorithm,
{ "HASH Algorithm", "isakmp.ike.attr.hash_algorithm",
FT_UINT16, BASE_DEC, VALS(ike_attr_hash_algo), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_authentication_method,
{ "Authentication Method", "isakmp.ike.attr.authentication_method",
FT_UINT16, BASE_DEC, VALS(ike_attr_authmeth), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_group_description,
{ "Group Description", "isakmp.ike.attr.group_description",
FT_UINT16, BASE_DEC, VALS(dh_group), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_group_type,
{ "Group Type", "isakmp.ike.attr.group_type",
FT_UINT16, BASE_DEC, VALS(ike_attr_grp_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_group_prime,
{ "Group Prime", "isakmp.ike.attr.group_prime",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_group_generator_one,
{ "Group Generator One", "isakmp.ike.attr.group_generator_one",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_group_generator_two,
{ "Group Generator Two", "isakmp.ike.attr.group_generator_two",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_group_curve_a,
{ "Group Curve A", "isakmp.ike.attr.group_curve_a",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_group_curve_b,
{ "Group Curve B", "isakmp.ike.attr.group_curve_b",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_life_type,
{ "Life Type", "isakmp.ike.attr.life_type",
FT_UINT16, BASE_DEC, VALS(attr_life_type), 0x00,
"The unit (seconds or kilobytes) of the associated Life Duration attribute.", HFILL }},
{ &hf_isakmp_ike_attr_life_duration_uint32,
{ "Life Duration", "isakmp.ike.attr.life_duration",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_life_duration_uint64,
{ "Life Duration", "isakmp.ike.attr.life_duration64",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_life_duration_bytes,
{ "Life Duration", "isakmp.ike.attr.life_duration_bytes",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_prf,
{ "PRF", "isakmp.ike.attr.prf",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_key_length,
{ "Key Length", "isakmp.ike.attr.key_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_field_size,
{ "Field Size", "isakmp.ike.attr.field_size",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_group_order,
{ "Group Order", "isakmp.ike.attr.group_order",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_resp_lifetime_ike_attr.all,
{ "IKE Attribute", "isakmp.notify.data.resp_lifetime.ike.attr",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_resp_lifetime_ike_attr.type,
{ "Type", "isakmp.notify.data.resp_lifetime.ike.attr.type",
FT_UINT16, BASE_RANGE_STRING | BASE_DEC, VALS(ike_attr_type), 0x00,
"IKEv1 Attribute type", HFILL }},
{ &hf_isakmp_resp_lifetime_ike_attr.format,
{ "Format", "isakmp.notify.data.resp_lifetime.ike.attr.format",
FT_BOOLEAN, 16, TFS(&attribute_format), 0x8000,
"IKEv1 Attribute format", HFILL }},
{ &hf_isakmp_resp_lifetime_ike_attr.length,
{ "Length", "isakmp.notify.data.resp_lifetime.ike.attr.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
"IKEv1 Attribute length", HFILL }},
{ &hf_isakmp_resp_lifetime_ike_attr.value,
{ "Value", "isakmp.notify.data.resp_lifetime.ike.attr.value",
FT_BYTES, BASE_NONE, NULL, 0x00,
"IKEv1 Attribute value", HFILL }},
{ &hf_isakmp_resp_lifetime_ike_attr_life_type,
{ "Life Type", "isakmp.notify.data.resp_lifetime.ike.attr.life_type",
FT_UINT16, BASE_DEC, VALS(attr_life_type), 0x00,
"The unit (seconds or kilobytes) of the associated Life Duration attribute.", HFILL }},
{ &hf_isakmp_resp_lifetime_ike_attr_life_duration_uint32,
{ "Life Duration", "isakmp.notify.data.resp_lifetime.ike.attr.life_duration",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_resp_lifetime_ike_attr_life_duration_uint64,
{ "Life Duration", "isakmp.notify.data.resp_lifetime.ike.attr.life_duration64",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_resp_lifetime_ike_attr_life_duration_bytes,
{ "Life Duration", "isakmp.notify.data.resp_lifetime.ike.attr.life_duration_bytes",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_trans_type,
{ "Transform Type", "isakmp.tf.type",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(transform_ike2_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_trans_encr,
{ "Transform ID (ENCR)", "isakmp.tf.id.encr",
FT_UINT16, BASE_DEC, VALS(transform_ike2_encr_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_trans_prf,
{ "Transform ID (PRF)", "isakmp.tf.id.prf",
FT_UINT16, BASE_DEC, VALS(transform_ike2_prf_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_trans_integ,
{ "Transform ID (INTEG)", "isakmp.tf.id.integ",
FT_UINT16, BASE_DEC, VALS(transform_ike2_integ_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_trans_dh,
{ "Transform ID (D-H)", "isakmp.tf.id.dh",
FT_UINT16, BASE_DEC, VALS(dh_group), 0x00,
NULL, HFILL }},
{ &hf_isakmp_trans_esn,
{ "Transform ID (ESN)", "isakmp.tf.id.esn",
FT_UINT16, BASE_DEC, VALS(transform_ike2_esn_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_trans_id_v2,
{ "Transform ID", "isakmp.tf.id",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike2_attr.all,
{ "Transform Attribute", "isakmp.ike2.attr",
FT_NONE, BASE_NONE, NULL, 0x00,
"IKEv2 Transform Attribute", HFILL }},
{ &hf_isakmp_ike2_attr.type,
{ "Type", "isakmp.ike2.attr.type",
FT_UINT16, BASE_RANGE_STRING | BASE_DEC, VALS(transform_ike2_attr_type), 0x00,
"IKEv2 Transform Attribute type", HFILL }},
{ &hf_isakmp_ike2_attr.format,
{ "Format", "isakmp.ike2.attr.format",
FT_BOOLEAN, 16, TFS(&attribute_format), 0x8000,
"IKEv2 Transform Attribute format", HFILL }},
{ &hf_isakmp_ike2_attr.length,
{ "Length", "isakmp.ike2.attr.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
"IKEv2 Transform Attribute length", HFILL }},
{ &hf_isakmp_ike2_attr.value,
{ "Value", "isakmp.ike2.attr.value",
FT_BYTES, BASE_NONE, NULL, 0x00,
"IKEv2 Transform Attribute value", HFILL }},
{ &hf_isakmp_ike2_attr_key_length,
{ "Key Length", "isakmp.ike2.attr.key_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_key_exch_dh_group,
{ "DH Group #", "isakmp.key_exchange.dh_group",
FT_UINT16, BASE_DEC, VALS(dh_group), 0x00,
NULL, HFILL }},
{ &hf_isakmp_key_exch_data,
{ "Key Exchange Data", "isakmp.key_exchange.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_eap_data,
{ "EAP Message", "isakmp.eap.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_gspm_data,
{ "GSPM", "isakmp.gspm.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Generic Secure Password Method", HFILL }},
{ &hf_isakmp_cfg_type_v1,
{ "Type", "isakmp.cfg.type",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(vs_v1_cfgtype), 0x0,
"IKEv1 Config Type", HFILL }},
{ &hf_isakmp_cfg_identifier,
{ "Identifier", "isakmp.cfg.identifier",
FT_UINT16, BASE_DEC, NULL, 0x0,
"IKEv1 Config Identifier", HFILL }},
{ &hf_isakmp_cfg_type_v2,
{ "Type", "isakmp.cfg.type",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(vs_v2_cfgtype), 0x0,
"IKEv2 Config Type", HFILL }},
{ &hf_isakmp_cfg_attr.all,
{ "Config Attribute", "isakmp.cfg.attr",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_cfg_attr_type_v1,
{ "Type", "isakmp.cfg.attr.type",
FT_UINT16, BASE_RANGE_STRING | BASE_DEC, RVALS(vs_v1_cfgattr), 0x00,
"IKEv1 Config Attribute type", HFILL }},
{ &hf_isakmp_cfg_attr_type_v2,
{ "Type", "isakmp.cfg.attr.type",
FT_UINT16, BASE_RANGE_STRING | BASE_DEC, RVALS(vs_v2_cfgattr), 0x00,
"IKEv2 Config Attribute type", HFILL }},
{ &hf_isakmp_cfg_attr.format,
{ "Format", "isakmp.cfg.attr.format",
FT_BOOLEAN, 16, TFS(&attribute_format), 0x8000,
"Config Attribute format", HFILL }},
{ &hf_isakmp_cfg_attr.length,
{ "Length", "isakmp.cfg.attr.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Config Attribute length", HFILL }},
{ &hf_isakmp_cfg_attr.value,
{ "Value", "isakmp.cfg.attr.value",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Config Attribute value", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip4_address,
{ "INTERNAL IP4 ADDRESS", "isakmp.cfg.attr.internal_ip4_address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"An IPv4 address on the internal network", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip4_netmask,
{ "INTERNAL IP4 NETMASK", "isakmp.cfg.attr.internal_ip4_netmask",
FT_IPv4, BASE_NETMASK, NULL, 0x00,
"The internal network's netmask", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip4_dns,
{ "INTERNAL IP4 DNS", "isakmp.cfg.attr.internal_ip4_dns",
FT_IPv4, BASE_NONE, NULL, 0x00,
"An IPv4 address of a DNS server within the network", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip4_nbns,
{ "INTERNAL IP4 NBNS", "isakmp.cfg.attr.internal_ip4_nbns",
FT_IPv4, BASE_NONE, NULL, 0x00,
"An IPv4 address of a NetBios Name Server (WINS) within the network", HFILL }},
{ &hf_isakmp_cfg_attr_internal_address_expiry,
{ "INTERNAL ADDRESS EXPIRY (Secs)", "isakmp.cfg.attr.internal_address_expiry",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Specifies the number of seconds that the host can use the internal IP address", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip4_dhcp,
{ "INTERNAL IP4 DHCP", "isakmp.cfg.attr.internal_ip4_dhcp",
FT_IPv4, BASE_NONE, NULL, 0x00,
"the host to send any internal DHCP requests to the address", HFILL }},
{ &hf_isakmp_cfg_attr_application_version,
{ "APPLICATION VERSION", "isakmp.cfg.attr.application_version",
FT_STRING, BASE_NONE, NULL, 0x00,
"The version or application information of the IPsec host", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip6_address_ip,
{ "INTERNAL IP6 ADDRESS", "isakmp.cfg.attr.internal_ip6_address",
FT_IPv6, BASE_NONE, NULL, 0x00,
"An IPv6 address on the internal network", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip6_address_prefix,
{ "INTERNAL IP6 ADDRESS (PREFIX)", "isakmp.cfg.attr.internal_ip6_address.prefix",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip6_netmask,
{ "INTERNAL IP4 NETMASK", "isakmp.cfg.attr.internal_ip6_netmask",
FT_IPv6, BASE_NONE, NULL, 0x00,
"The internal network's netmask", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip6_dns,
{ "INTERNAL IP6 DNS", "isakmp.cfg.attr.internal_ip6_dns",
FT_IPv6, BASE_NONE, NULL, 0x00,
"An IPv6 address of a DNS server within the network", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip6_nbns,
{ "INTERNAL IP6 NBNS", "isakmp.cfg.attr.internal_ip6_nbns",
FT_IPv6, BASE_NONE, NULL, 0x00,
"An IPv6 address of a NetBios Name Server (WINS) within the network", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip6_dhcp,
{ "INTERNAL IP6 DHCP", "isakmp.cfg.attr.internal_ip6_dhcp",
FT_IPv6, BASE_NONE, NULL, 0x00,
"The host to send any internal DHCP requests to the address", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip4_subnet_ip,
{ "INTERNAL IP4 SUBNET (IP)", "isakmp.cfg.attr.internal_ip4_subnet_ip",
FT_IPv4, BASE_NONE, NULL, 0x00,
"The protected sub-networks that this edge-device protects (IP)", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip4_subnet_netmask,
{ "INTERNAL IP4 SUBNET (NETMASK)", "isakmp.cfg.attr.internal_ip4_subnet_netmask",
FT_IPv4, BASE_NETMASK, NULL, 0x00,
"The protected sub-networks that this edge-device protects (IP)", HFILL }},
{ &hf_isakmp_cfg_attr_supported_attributes,
{ "SUPPORTED ATTRIBUTES", "isakmp.cfg.attr.supported_attributes",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip6_subnet_ip,
{ "INTERNAL_IP6_SUBNET (IP)", "isakmp.cfg.attr.internal_ip6_subnet_ip",
FT_IPv6, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip6_subnet_prefix,
{ "INTERNAL_IP6_SUBNET (PREFIX)", "isakmp.cfg.attr.internal_ip6_subnet_prefix",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip6_link_interface,
{ "INTERNAL_IP6_LINK (Link-Local Interface ID)", "isakmp.cfg.attr.internal_ip6_link_interface",
FT_UINT64, BASE_DEC, NULL, 0x00,
"The Interface ID used for link-local address (by the party that sent this attribute)", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip6_link_id,
{ "INTERNAL_IP6_LINK (IKEv2 Link ID)", "isakmp.cfg.attr.internal_ip6_link_id",
FT_BYTES, BASE_NONE, NULL, 0x00,
"The Link ID is selected by the VPN gateway and is treated as an opaque octet string by the client.", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip6_prefix_ip,
{ "INTERNAL_IP6_PREFIX (IP)", "isakmp.cfg.attr.internal_ip6_prefix_ip",
FT_IPv6, BASE_NONE, NULL, 0x00,
"An IPv6 prefix assigned to the virtual link", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip6_prefix_length,
{ "INTERNAL_IP6_PREFIX (Length)", "isakmp.cfg.attr.internal_ip6_prefix_length",
FT_UINT8, BASE_DEC, NULL, 0x00,
"The length of the prefix in bits (usually 64)", HFILL }},
{ &hf_isakmp_cfg_attr_p_cscf_ip4_address,
{ "P_CSCF_IP4_ADDRESS (IP)", "isakmp.cfg.attr.p_cscf_ip4_address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"An IPv4 address of the P-CSCF server", HFILL }},
{ &hf_isakmp_cfg_attr_p_cscf_ip6_address,
{ "P_CSCF_IP6_ADDRESS (IP)", "isakmp.cfg.attr.p_cscf_ip6_address",
FT_IPv6, BASE_NONE, NULL, 0x00,
"An IPv6 address of the P-CSCF server", HFILL }},
{ &hf_isakmp_cfg_attr_xauth_type,
{ "XAUTH TYPE", "isakmp.cfg.attr.xauth.type",
FT_UINT16, BASE_RANGE_STRING | BASE_DEC, RVALS(cfgattr_xauth_type), 0x00,
"The type of extended authentication requested", HFILL }},
{ &hf_isakmp_cfg_attr_xauth_user_name,
{ "XAUTH USER NAME", "isakmp.cfg.attr.xauth.user_name",
FT_STRING, BASE_NONE, NULL, 0x00,
"The user name", HFILL }},
{ &hf_isakmp_cfg_attr_xauth_user_password,
{ "XAUTH USER PASSWORD", "isakmp.cfg.attr.xauth.user_password",
FT_STRING, BASE_NONE, NULL, 0x00,
"The user's password", HFILL }},
{ &hf_isakmp_cfg_attr_xauth_passcode,
{ "XAUTH PASSCODE", "isakmp.cfg.attr.xauth.passcode",
FT_STRING, BASE_NONE, NULL, 0x00,
"A token card's passcode", HFILL }},
{ &hf_isakmp_cfg_attr_xauth_message,
{ "XAUTH MESSAGE", "isakmp.cfg.attr.xauth.message",
FT_STRING, BASE_NONE, NULL, 0x00,
"A textual message from an edge device to an IPSec host", HFILL }},
{ &hf_isakmp_cfg_attr_xauth_challenge,
{ "XAUTH CHALLENGE", "isakmp.cfg.attr.xauth.challenge",
FT_STRING, BASE_NONE, NULL, 0x00,
"A challenge string sent from the edge device to the IPSec host for it to include in its calculation of a password", HFILL }},
{ &hf_isakmp_cfg_attr_xauth_domain,
{ "XAUTH DOMAIN", "isakmp.cfg.attr.xauth.domain",
FT_STRING, BASE_NONE, NULL, 0x00,
"The domain to be authenticated in", HFILL }},
{ &hf_isakmp_cfg_attr_xauth_status,
{ "XAUTH STATUS", "isakmp.cfg.attr.xauth.status",
FT_UINT16, BASE_DEC, VALS(cfgattr_xauth_status), 0x00,
"A variable that is used to denote authentication success or failure", HFILL }},
{ &hf_isakmp_cfg_attr_xauth_next_pin,
{ "XAUTH TYPE", "isakmp.cfg.attr.xauth.next_pin",
FT_STRING, BASE_NONE, NULL, 0x00,
"A variable which is used when the edge device is requesting that the user choose a new pin number", HFILL }},
{ &hf_isakmp_cfg_attr_xauth_answer,
{ "XAUTH ANSWER", "isakmp.cfg.attr.xauth.answer",
FT_STRING, BASE_NONE, NULL, 0x00,
"A variable length ASCII string used to send input to the edge device", HFILL }},
{ &hf_isakmp_cfg_attr_unity_banner,
{ "UNITY BANNER", "isakmp.cfg.attr.unity.banner",
FT_STRING, BASE_NONE, NULL, 0x00,
"Banner", HFILL }},
{ &hf_isakmp_cfg_attr_unity_def_domain,
{ "UNITY DEF DOMAIN", "isakmp.cfg.attr.unity.def_domain",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_enc_decrypted_data,
{ "Decrypted Data", "isakmp.enc.decrypted",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_enc_contained_data,
{ "Contained Data", "isakmp.enc.contained",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_enc_padding,
{ "Padding", "isakmp.enc.padding",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_enc_pad_length,
{ "Pad Length", "isakmp.enc.pad_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_enc_data,
{ "Encrypted Data", "isakmp.enc.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_enc_iv,
{ "Initialization Vector", "isakmp.enc.iv",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_enc_icd,
{ "Integrity Checksum Data", "isakmp.enc.icd",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_notify_data_3gpp_backoff_timer_len,
{ "Length", "isakmp.notyfy.priv.3gpp.backoff_timer_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_isakmp,
&ett_isakmp_version,
&ett_isakmp_flags,
&ett_isakmp_payload,
&ett_isakmp_fragment,
&ett_isakmp_fragments,
&ett_isakmp_sa,
&ett_isakmp_attr,
&ett_isakmp_id,
&ett_isakmp_notify_data,
&ett_isakmp_ts,
&ett_isakmp_decrypted_data,
&ett_isakmp_decrypted_payloads
};
static ei_register_info ei[] = {
{ &ei_isakmp_enc_iv, { "isakmp.enc.iv.not_enough_data", PI_MALFORMED, PI_WARN, "Not enough data in IKEv2 Encrypted payload", EXPFILL }},
{ &ei_isakmp_ikev2_integrity_checksum, { "isakmp.ikev2.integrity_checksum", PI_CHECKSUM, PI_WARN, "IKEv2 Integrity Checksum Data is incorrect", EXPFILL }},
{ &ei_isakmp_enc_data_length_mult_block_size, { "isakmp.enc_data_length_mult_block_size", PI_MALFORMED, PI_WARN, "Encrypted data length isn't a multiple of block size", EXPFILL }},
{ &ei_isakmp_enc_pad_length_big, { "isakmp.enc.pad_length.big", PI_MALFORMED, PI_WARN, "Pad length is too big", EXPFILL }},
{ &ei_isakmp_attribute_value_empty, { "isakmp.attribute_value_empty", PI_PROTOCOL, PI_NOTE, "Attribute value is empty", EXPFILL }},
{ &ei_isakmp_payload_bad_length, { "isakmp.payloadlength.invalid", PI_MALFORMED, PI_ERROR, "Invalid payload length", EXPFILL }},
{ &ei_isakmp_bad_fragment_number, { "isakmp.fragment_number.invalid", PI_MALFORMED, PI_ERROR, "Invalid fragment numbering", EXPFILL }},
};
expert_module_t* expert_isakmp;
static uat_field_t ikev1_uat_flds[] = {
UAT_FLD_BUFFER(ikev1_users, icookie, "Initiator's COOKIE", "Initiator's COOKIE"),
UAT_FLD_BUFFER(ikev1_users, key, "Encryption Key", "Encryption Key"),
UAT_END_FIELDS
};
static uat_field_t ikev2_uat_flds[] = {
UAT_FLD_BUFFER(ikev2_users, spii, "Initiator's SPI", "Initiator's SPI value of the IKE_SA"),
UAT_FLD_BUFFER(ikev2_users, spir, "Responder's SPI", "Responder's SPI value of the IKE_SA"),
UAT_FLD_BUFFER(ikev2_users, sk_ei, "SK_ei", "Key used to encrypt/decrypt IKEv2 packets from initiator to responder"),
UAT_FLD_BUFFER(ikev2_users, sk_er, "SK_er", "Key used to encrypt/decrypt IKEv2 packets from responder to initiator"),
UAT_FLD_VS(ikev2_users, encr_alg, "Encryption algorithm", vs_ikev2_encr_algs, "Encryption algorithm of IKE_SA"),
UAT_FLD_BUFFER(ikev2_users, sk_ai, "SK_ai", "Key used to calculate Integrity Checksum Data for IKEv2 packets from initiator to responder"),
UAT_FLD_BUFFER(ikev2_users, sk_ar, "SK_ar", "Key used to calculate Integrity Checksum Data for IKEv2 packets from responder to initiator"),
UAT_FLD_VS(ikev2_users, auth_alg, "Integrity algorithm", vs_ikev2_auth_algs, "Integrity algorithm of IKE_SA"),
UAT_END_FIELDS
};
proto_isakmp = proto_register_protocol("Internet Security Association and Key Management Protocol",
"ISAKMP", "isakmp");
proto_register_field_array(proto_isakmp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_isakmp = expert_register_protocol(proto_isakmp);
expert_register_field_array(expert_isakmp, ei, array_length(ei));
register_init_routine(&isakmp_init_protocol);
register_cleanup_routine(&isakmp_cleanup_protocol);
reassembly_table_register(&isakmp_cisco_reassembly_table,
&addresses_reassembly_table_functions);
reassembly_table_register(&isakmp_ike2_reassembly_table,
&addresses_reassembly_table_functions);
isakmp_handle = register_dissector("isakmp", dissect_isakmp, proto_isakmp);
isakmp_module = prefs_register_protocol(proto_isakmp, NULL);
ikev1_uat = uat_new("IKEv1 Decryption Table",
sizeof(ikev1_uat_data_key_t),
"ikev1_decryption_table",
TRUE,
&ikev1_uat_data,
&num_ikev1_uat_data,
UAT_AFFECTS_DISSECTION,
"ChIKEv1DecryptionSection",
NULL,
ikev1_uat_data_update_cb,
NULL,
NULL,
NULL,
ikev1_uat_flds);
prefs_register_uat_preference(isakmp_module,
"ikev1_decryption_table",
"IKEv1 Decryption Table",
"Table of IKE_SA security parameters for decryption of IKEv1 packets",
ikev1_uat);
ikev2_uat = uat_new("IKEv2 Decryption Table",
sizeof(ikev2_uat_data_t),
"ikev2_decryption_table",
TRUE,
&ikev2_uat_data,
&num_ikev2_uat_data,
UAT_AFFECTS_DISSECTION,
"ChIKEv2DecryptionSection",
NULL,
ikev2_uat_data_update_cb,
NULL,
NULL,
NULL,
ikev2_uat_flds);
prefs_register_uat_preference(isakmp_module,
"ikev2_decryption_table",
"IKEv2 Decryption Table",
"Table of IKE_SA security parameters for decryption of IKEv2 packets",
ikev2_uat);
}
void
proto_reg_handoff_isakmp(void)
{
eap_handle = find_dissector_add_dependency("eap", proto_isakmp);
dissector_add_uint_with_preference("udp.port", UDP_PORT_ISAKMP, isakmp_handle);
dissector_add_uint_with_preference("tcp.port", TCP_PORT_ISAKMP, isakmp_handle);
}
