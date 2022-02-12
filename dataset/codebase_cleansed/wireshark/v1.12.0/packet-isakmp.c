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
static tvbuff_t *
decrypt_payload(tvbuff_t *tvb, packet_info *pinfo, const guint8 *buf, guint buf_len, isakmp_hdr_t *hdr, decrypt_data_t *decr) {
guint8 *decrypted_data = NULL;
gint gcry_md_algo, gcry_cipher_algo;
gcry_md_hd_t md_ctx;
gcry_cipher_hd_t decr_ctx;
tvbuff_t *encr_tvb;
iv_data_t *ivd = NULL;
GList *ivl;
guchar iv[MAX_DIGEST_SIZE];
guint iv_len = 0;
guint32 message_id, cbc_block_size, digest_size;
if (!decr ||
decr->gi_len == 0 ||
decr->gr_len == 0)
return NULL;
switch(decr->encr_alg) {
case ENC_3DES_CBC:
gcry_cipher_algo = GCRY_CIPHER_3DES;
break;
case ENC_DES_CBC:
gcry_cipher_algo = GCRY_CIPHER_DES;
break;
case ENC_AES_CBC:
switch (decr->secret_len) {
case 16:
gcry_cipher_algo = GCRY_CIPHER_AES128;
break;
case 24:
gcry_cipher_algo = GCRY_CIPHER_AES192;
break;
case 32:
gcry_cipher_algo = GCRY_CIPHER_AES256;
break;
default:
return NULL;
}
break;
default:
return NULL;
break;
}
if (decr->secret_len < gcry_cipher_get_algo_keylen(gcry_cipher_algo))
return NULL;
cbc_block_size = (guint32) gcry_cipher_get_algo_blklen(gcry_cipher_algo);
if (cbc_block_size > MAX_DIGEST_SIZE) {
return NULL;
}
switch(decr->hash_alg) {
case HMAC_MD5:
gcry_md_algo = GCRY_MD_MD5;
break;
case HMAC_SHA:
gcry_md_algo = GCRY_MD_SHA1;
break;
case HMAC_SHA2_256:
gcry_md_algo = GCRY_MD_SHA256;
break;
case HMAC_SHA2_384:
gcry_md_algo = GCRY_MD_SHA384;
break;
case HMAC_SHA2_512:
gcry_md_algo = GCRY_MD_SHA512;
break;
default:
return NULL;
break;
}
digest_size = gcry_md_get_algo_dlen(gcry_md_algo);
for (ivl = g_list_first(decr->iv_list); ivl != NULL; ivl = g_list_next(ivl)) {
ivd = (iv_data_t *) ivl->data;
if (ivd->frame_num == pinfo->fd->num) {
iv_len = ivd->iv_len;
memcpy(iv, ivd->iv, iv_len);
}
}
if (iv_len == 0) {
if (gcry_md_open(&md_ctx, gcry_md_algo, 0) != GPG_ERR_NO_ERROR)
return NULL;
if (decr->iv_list == NULL) {
ivd = (iv_data_t *)g_malloc(sizeof(iv_data_t));
ivd->frame_num = pinfo->fd->num;
ivd->iv_len = digest_size;
decr->last_message_id = hdr->message_id;
gcry_md_reset(md_ctx);
gcry_md_write(md_ctx, decr->gi, decr->gi_len);
gcry_md_write(md_ctx, decr->gr, decr->gr_len);
gcry_md_final(md_ctx);
memcpy(ivd->iv, gcry_md_read(md_ctx, gcry_md_algo), digest_size);
decr->iv_list = g_list_append(decr->iv_list, ivd);
iv_len = ivd->iv_len;
memcpy(iv, ivd->iv, iv_len);
} else if (decr->last_cbc_len >= cbc_block_size) {
ivd = (iv_data_t *)g_malloc(sizeof(iv_data_t));
ivd->frame_num = pinfo->fd->num;
if (hdr->message_id != decr->last_message_id) {
if (decr->last_p1_cbc_len == 0) {
memcpy(decr->last_p1_cbc, decr->last_cbc, cbc_block_size);
decr->last_p1_cbc_len = cbc_block_size;
}
ivd->iv_len = digest_size;
decr->last_message_id = hdr->message_id;
message_id = g_htonl(decr->last_message_id);
gcry_md_reset(md_ctx);
gcry_md_write(md_ctx, decr->last_p1_cbc, cbc_block_size);
gcry_md_write(md_ctx, &message_id, sizeof(message_id));
memcpy(ivd->iv, gcry_md_read(md_ctx, gcry_md_algo), digest_size);
} else {
ivd->iv_len = cbc_block_size;
memcpy(ivd->iv, decr->last_cbc, ivd->iv_len);
}
decr->iv_list = g_list_append(decr->iv_list, ivd);
iv_len = ivd->iv_len;
memcpy(iv, ivd->iv, iv_len);
}
gcry_md_close(md_ctx);
}
if (ivd == NULL) return NULL;
if (gcry_cipher_open(&decr_ctx, gcry_cipher_algo, GCRY_CIPHER_MODE_CBC, 0) != GPG_ERR_NO_ERROR)
return NULL;
if (iv_len > cbc_block_size)
iv_len = cbc_block_size;
if (gcry_cipher_setiv(decr_ctx, iv, iv_len))
return NULL;
if (gcry_cipher_setkey(decr_ctx, decr->secret, decr->secret_len))
return NULL;
decrypted_data = (guint8 *)g_malloc(buf_len);
if (gcry_cipher_decrypt(decr_ctx, decrypted_data, buf_len, buf, buf_len) != GPG_ERR_NO_ERROR) {
g_free(decrypted_data);
return NULL;
}
gcry_cipher_close(decr_ctx);
encr_tvb = tvb_new_child_real_data(tvb, decrypted_data, buf_len, buf_len);
tvb_set_free_cb(encr_tvb, g_free);
add_new_data_source(pinfo, encr_tvb, "Decrypted IKE");
if (tvb_length(tvb) > cbc_block_size) {
decr->last_cbc_len = cbc_block_size;
memcpy(decr->last_cbc, buf + buf_len - cbc_block_size, cbc_block_size);
} else {
decr->last_cbc_len = 0;
}
return encr_tvb;
}
static const gchar*
match_strbyte_idx(const guint8 *val, const gint val_len, const byte_string *vs, gint *idx) {
gint i = 0;
if (vs) {
while (vs[i].strptr) {
if (val_len >= vs[i].len && !memcmp(vs[i].value, val, vs[i].len)) {
*idx = i;
return(vs[i].strptr);
}
i++;
}
}
*idx = -1;
return NULL;
}
static const gchar*
match_strbyte(const guint8 *val,const gint val_len, const byte_string *vs) {
gint ignore_me;
return match_strbyte_idx(val, val_len, vs, &ignore_me);
}
static const gchar*
byte_to_str(const guint8 *val,const gint val_len, const byte_string *vs, const char *fmt) {
const gchar *ret;
DISSECTOR_ASSERT(fmt != NULL);
ret = match_strbyte(val, val_len, vs);
if (ret != NULL)
return ret;
return wmem_strdup_printf(wmem_packet_scope(), fmt, val);
}
static void
dissect_payloads(tvbuff_t *tvb, proto_tree *tree, proto_tree *parent_tree _U_,
int isakmp_version, guint8 initial_payload, int offset, int length,
packet_info *pinfo, void* decr_data)
{
guint8 payload, next_payload;
guint16 payload_length;
proto_tree * ntree;
for (payload = initial_payload; length > 0; payload = next_payload) {
if (payload == PLOAD_IKE_NONE) {
proto_tree_add_item(tree, hf_isakmp_extradata, tvb, offset, length, ENC_NA);
break;
}
ntree = dissect_payload_header(tvb, offset, length, isakmp_version, payload, &next_payload, &payload_length, tree);
if (ntree == NULL)
break;
if (payload_length >= 4) {
tvb_ensure_bytes_exist(tvb, offset + 4, payload_length - 4);
switch(payload){
case PLOAD_IKE_SA:
case PLOAD_IKE2_SA:
dissect_sa(tvb, offset + 4, payload_length - 4, ntree, isakmp_version, pinfo, decr_data);
break;
case PLOAD_IKE_P:
dissect_proposal(tvb, offset + 4, payload_length - 4, ntree, isakmp_version, decr_data );
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
dissect_notif(tvb, offset + 4, payload_length - 4, ntree, isakmp_version);
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
dissect_config(tvb, offset + 4, payload_length - 4, ntree, isakmp_version);
break;
case PLOAD_IKE2_AUTH:
dissect_auth(tvb, offset + 4, payload_length - 4, ntree);
break;
case PLOAD_IKE2_TSI:
case PLOAD_IKE2_TSR:
dissect_ts(tvb, offset + 4, payload_length - 4, ntree);
break;
case PLOAD_IKE2_SK:
if(isakmp_version == 2)
dissect_enc(tvb, offset + 4, payload_length - 4, ntree, pinfo, next_payload, decr_data);
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
default:
proto_tree_add_item(ntree, hf_isakmp_datapayload, tvb, offset + 4, payload_length-4, ENC_NA);
break;
}
}
else if (payload_length > length) {
proto_tree_add_text(ntree, tvb, 0, 0,
"Payload (bogus, length is %u, greater than remaining length %d",
payload_length, length);
return;
}
else {
proto_tree_add_text(ntree, tvb, 0, 0,
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
dissect_payloads(tvb, tree, tree, isakmp_version, initial_payload, offset, length,
pinfo, NULL);
}
static int
dissect_isakmp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int offset = 0, len;
isakmp_hdr_t hdr;
proto_item * ti, *vers_item;
proto_tree * isakmp_tree = NULL, *vers_tree;
int isakmp_version;
void* decr_data = NULL;
guint8 flags;
#ifdef HAVE_LIBGCRYPT
guint8 i_cookie[COOKIE_SIZE], *ic_key;
decrypt_data_t *decr = NULL;
tvbuff_t *decr_tvb;
proto_tree *decr_tree;
address null_addr;
#endif
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISAKMP");
col_clear(pinfo->cinfo, COL_INFO);
if (tvb_reported_length(tvb)==1 && tvb_get_guint8(tvb, offset) !=0xff)
return 0;
else if (tvb_reported_length(tvb) < ISAKMP_HDR_SIZE)
return 0;
else if (tvb_get_ntohl(tvb, ISAKMP_HDR_SIZE-4) < ISAKMP_HDR_SIZE)
return 0;
if (tree) {
ti = proto_tree_add_item(tree, proto_isakmp, tvb, offset, -1, ENC_NA);
isakmp_tree = proto_item_add_subtree(ti, ett_isakmp);
}
if ( (tvb_reported_length(tvb)==1) && (tvb_get_guint8(tvb, offset)==0xff) ){
col_set_str(pinfo->cinfo, COL_INFO, "NAT Keepalive");
proto_tree_add_item(isakmp_tree, hf_isakmp_nat_keepalive, tvb, offset, 1, ENC_NA);
return 1;
}
hdr.length = tvb_get_ntohl(tvb, offset + ISAKMP_HDR_SIZE - 4);
hdr.exch_type = tvb_get_guint8(tvb, COOKIE_SIZE + COOKIE_SIZE + 1 + 1);
hdr.version = tvb_get_guint8(tvb, COOKIE_SIZE + COOKIE_SIZE + 1);
isakmp_version = hi_nibble(hdr.version);
hdr.flags = tvb_get_guint8(tvb, COOKIE_SIZE + COOKIE_SIZE + 1 + 1 + 1);
#ifdef HAVE_LIBGCRYPT
if (isakmp_version == 1) {
SET_ADDRESS(&null_addr, AT_NONE, 0, NULL);
tvb_memcpy(tvb, i_cookie, offset, COOKIE_SIZE);
decr = (decrypt_data_t*) g_hash_table_lookup(isakmp_hash, i_cookie);
if (! decr) {
ic_key = (guint8 *)g_slice_alloc(COOKIE_SIZE);
decr = (decrypt_data_t *)g_slice_alloc(sizeof(decrypt_data_t));
memcpy(ic_key, i_cookie, COOKIE_SIZE);
memset(decr, 0, sizeof(decrypt_data_t));
SET_ADDRESS(&decr->initiator, AT_NONE, 0, NULL);
g_hash_table_insert(isakmp_hash, ic_key, decr);
}
if (ADDRESSES_EQUAL(&decr->initiator, &null_addr)) {
SE_COPY_ADDRESS(&decr->initiator, &pinfo->src);
}
decr_data = decr;
} else if (isakmp_version == 2) {
ikev2_uat_data_key_t hash_key;
ikev2_uat_data_t *ike_sa_data = NULL;
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
#endif
if (tree) {
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
if (hdr.flags & E_FLAG) {
if (len && isakmp_tree) {
ti = proto_tree_add_item(isakmp_tree, hf_isakmp_enc_data, tvb, offset, len, ENC_NA);
proto_item_append_text(ti, " (%d byte%s)", len, plurality(len, "", "s"));
#ifdef HAVE_LIBGCRYPT
if (decr) {
decr_tvb = decrypt_payload(tvb, pinfo, tvb_get_ptr(tvb, offset, len), len, &hdr, decr);
if (decr_tvb) {
decr_tree = proto_item_add_subtree(ti, ett_isakmp);
dissect_payloads(decr_tvb, decr_tree, tree, isakmp_version,
hdr.next_payload, 0, tvb_length(decr_tvb), pinfo, decr_data);
}
}
#endif
}
} else {
dissect_payloads(tvb, isakmp_tree, tree, isakmp_version, hdr.next_payload,
offset, len, pinfo, decr_data);
}
}
return tvb_captured_length(tvb);
}
static proto_tree *
dissect_payload_header(tvbuff_t *tvb, int offset, int length,
int isakmp_version, guint8 payload _U_, guint8 *next_payload_p,
guint16 *payload_length_p, proto_tree *tree)
{
guint8 next_payload;
guint16 payload_length;
proto_item * ti;
proto_tree * ntree;
if (length < 4) {
proto_tree_add_text(tree, tvb, offset, length,
"Not enough room in payload for all transforms");
return NULL;
}
next_payload = tvb_get_guint8(tvb, offset);
payload_length = tvb_get_ntohs(tvb, offset + 2);
ti = proto_tree_add_uint(tree, hf_isakmp_typepayload, tvb, offset, payload_length, payload);
ntree = proto_item_add_subtree(ti, ett_isakmp_payload);
proto_tree_add_item(ntree, hf_isakmp_nextpayload, tvb, offset, 1, ENC_BIG_ENDIAN);
if (isakmp_version == 2) {
proto_tree_add_item(ntree, hf_isakmp_criticalpayload, tvb, offset+1, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(ntree, hf_isakmp_payloadlen, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
*next_payload_p = next_payload;
*payload_length_p = payload_length;
return ntree;
}
static void
dissect_sa(tvbuff_t *tvb, int offset, int length, proto_tree *tree, int isakmp_version, packet_info *pinfo, void* decr_data)
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
tvb_bytes_to_ep_str(tvb, offset, length), length);
return;
}
sti = proto_tree_add_item(tree, hf_isakmp_sa_situation, tvb, offset, 4, ENC_NA);
stree = proto_item_add_subtree(sti, ett_isakmp_sa);
proto_tree_add_item(stree, hf_isakmp_sa_situation_identity_only, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(stree, hf_isakmp_sa_situation_secrecy, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(stree, hf_isakmp_sa_situation_integrity, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
dissect_payloads(tvb, tree, tree, isakmp_version, PLOAD_IKE_P, offset,
length, pinfo, decr_data);
} else {
proto_tree_add_item(tree, hf_isakmp_sa_situation, tvb, offset, length, ENC_NA);
}
} else if (isakmp_version == 2) {
dissect_payloads(tvb, tree, tree, isakmp_version, PLOAD_IKE_P, offset,
length, pinfo, decr_data);
}
}
static void
dissect_proposal(tvbuff_t *tvb, int offset, int length, proto_tree *tree, int isakmp_version, void* decr_data)
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
ntree = dissect_payload_header(tvb, offset, length, isakmp_version,
PLOAD_IKE_T, &next_payload, &payload_length, tree);
if (ntree == NULL)
break;
if (length < payload_length) {
proto_tree_add_text(tree, tvb, offset + 4, length,
"Not enough room in payload for all transforms");
break;
}
dissect_transform(tvb, offset + 4, payload_length - 4, ntree, isakmp_version, protocol_id, decr_data);
offset += payload_length;
length -= payload_length;
num_transforms--;
}
}
static int
dissect_rohc_supported(tvbuff_t *tvb, proto_tree *rohc_tree, int offset )
{
guint optlen, rohc, len = 0;
proto_item *rohc_item = NULL;
proto_tree *sub_rohc_tree = NULL;
rohc = tvb_get_ntohs(tvb, offset);
optlen = tvb_get_ntohs(tvb, offset+2);
len = 2;
if (rohc & 0x8000) {
rohc = rohc & 0x7fff;
len = 0;
optlen = 2;
}
rohc_item = proto_tree_add_item(rohc_tree, hf_isakmp_notify_data_rohc_attr, tvb, offset, 2+len+optlen, ENC_NA);
proto_item_append_text(rohc_item," (t=%d,l=%d) %s",rohc, optlen, val_to_str(rohc, rohc_attr_type, "Unknown Attribute Type (%02d)") );
sub_rohc_tree = proto_item_add_subtree(rohc_item, ett_isakmp_rohc_attr);
proto_tree_add_item(sub_rohc_tree, hf_isakmp_notify_data_rohc_attr_format, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint(sub_rohc_tree, hf_isakmp_notify_data_rohc_attr_type, tvb, offset, 2, rohc);
offset += 2;
if (len)
{
proto_tree_add_item(sub_rohc_tree, hf_isakmp_notify_data_rohc_attr_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (optlen==0)
{
proto_tree_add_text(sub_rohc_tree, tvb, offset, 0,"Attribut value is empty");
return 2+len;
}
proto_tree_add_item(sub_rohc_tree, hf_isakmp_notify_data_rohc_attr_value, tvb, offset, optlen, ENC_NA);
switch(rohc) {
case ROHC_MAX_CID:
proto_tree_add_item(sub_rohc_tree, hf_isakmp_notify_data_rohc_attr_max_cid, tvb, offset, optlen, ENC_BIG_ENDIAN);
break;
case ROHC_PROFILE:
proto_tree_add_item(sub_rohc_tree, hf_isakmp_notify_data_rohc_attr_profile, tvb, offset, optlen, ENC_BIG_ENDIAN);
break;
case ROHC_INTEG:
proto_tree_add_item(sub_rohc_tree, hf_isakmp_notify_data_rohc_attr_integ, tvb, offset, optlen, ENC_BIG_ENDIAN);
break;
case ROHC_ICV_LEN:
proto_tree_add_item(sub_rohc_tree, hf_isakmp_notify_data_rohc_attr_icv_len, tvb, offset, optlen, ENC_BIG_ENDIAN);
break;
case ROHC_MRRU:
proto_tree_add_item(sub_rohc_tree, hf_isakmp_notify_data_rohc_attr_mrru, tvb, offset, optlen, ENC_BIG_ENDIAN);
break;
default:
break;
}
return 2+len+optlen;
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
proto_tree_add_uint_format_value(tree, hf_uint32, tvb, offset, len, val, "%u", val);
proto_item_append_text(ti, " : %u", val);
break;
}
case 2: {
guint16 val;
val = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_uint32, tvb, offset, len, val, "%u", val);
proto_item_append_text(ti, " : %u", val);
break;
}
case 3: {
guint32 val;
val = tvb_get_ntoh24(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_uint32, tvb, offset, len, val, "%u", val);
proto_item_append_text(ti, " : %u", val);
break;
}
case 4: {
guint32 val;
val = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_uint32, tvb, offset, len, val, "%u", val);
proto_item_append_text(ti, " : %u", val);
break;
}
case 5: {
guint64 val;
val = tvb_get_ntoh40(tvb, offset);
proto_tree_add_uint64_format_value(tree, hf_uint64, tvb, offset, len, val, "%" G_GINT64_MODIFIER "u", val);
proto_item_append_text(ti, " : %" G_GINT64_MODIFIER "u", val);
break;
}
case 6: {
guint64 val;
val = tvb_get_ntoh48(tvb, offset);
proto_tree_add_uint64_format_value(tree, hf_uint64, tvb, offset, len, val, "%" G_GINT64_MODIFIER "u", val);
proto_item_append_text(ti, " : %" G_GINT64_MODIFIER "u", val);
break;
}
case 7: {
guint64 val;
val = tvb_get_ntoh56(tvb, offset);
proto_tree_add_uint64_format_value(tree, hf_uint64, tvb, offset, len, val, "%" G_GINT64_MODIFIER "u", val);
proto_item_append_text(ti, " : %" G_GINT64_MODIFIER "u", val);
break;
}
case 8: {
guint64 val;
val = tvb_get_ntoh64(tvb, offset);
proto_tree_add_uint64_format_value(tree, hf_uint64, tvb, offset, len, val, "%" G_GINT64_MODIFIER "u", val);
proto_item_append_text(ti, " : %" G_GINT64_MODIFIER "u", val);
break;
}
default:
proto_tree_add_item(tree, hf_bytes, tvb, offset, len, ENC_NA);
proto_item_append_text(ti, " : %" G_GINT64_MODIFIER "x ...", tvb_get_ntoh64(tvb, offset));
break;
}
}
static int
dissect_transform_attribute(tvbuff_t *tvb, proto_tree *transform_attr_type_tree, int offset )
{
guint optlen, transform_attr_type, len = 0;
proto_item *transform_attr_type_item = NULL;
proto_tree *sub_transform_attr_type_tree = NULL;
transform_attr_type = tvb_get_ntohs(tvb, offset);
optlen = tvb_get_ntohs(tvb, offset+2);
len = 2;
if (transform_attr_type & 0x8000) {
transform_attr_type = transform_attr_type & 0x7fff;
len = 0;
optlen = 2;
}
transform_attr_type_item = proto_tree_add_item(transform_attr_type_tree, hf_isakmp_tf_attr, tvb, offset, 2+len+optlen, ENC_NA);
proto_item_append_text(transform_attr_type_item, " (t=%d,l=%d) %s",transform_attr_type, optlen, val_to_str(transform_attr_type, transform_isakmp_attr_type, "Unknown Attribute Type (%02d)") );
sub_transform_attr_type_tree = proto_item_add_subtree(transform_attr_type_item, ett_isakmp_tf_attr);
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_format, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint(sub_transform_attr_type_tree, hf_isakmp_tf_attr_type_v1, tvb, offset, 2, transform_attr_type);
offset += 2;
if (len)
{
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (optlen==0)
{
proto_tree_add_text(sub_transform_attr_type_tree, tvb, offset, 0,"Attribute value is empty");
return 2+len;
}
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_value, tvb, offset, optlen, ENC_NA);
switch(transform_attr_type) {
case ISAKMP_ATTR_LIFE_TYPE:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_life_type, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %s", val_to_str(tvb_get_ntohs(tvb, offset), transform_attr_sa_life_type, "Unknown %d"));
break;
case ISAKMP_ATTR_LIFE_DURATION:
dissect_life_duration(tvb, sub_transform_attr_type_tree, transform_attr_type_item, hf_isakmp_tf_attr_life_duration_uint32, hf_isakmp_tf_attr_life_duration_uint64, hf_isakmp_tf_attr_life_duration_bytes , offset, optlen);
break;
case ISAKMP_ATTR_GROUP_DESC:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_group_description, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %s", val_to_str(tvb_get_ntohs(tvb, offset), transform_dh_group_type, "Unknown %d"));
break;
case ISAKMP_ATTR_ENCAP_MODE:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_encap_mode, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %s", val_to_str(tvb_get_ntohs(tvb, offset), transform_attr_encap_type, "Unknown %d"));
break;
case ISAKMP_ATTR_AUTH_ALGORITHM:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_auth_algorithm, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %s", val_to_str(tvb_get_ntohs(tvb, offset), transform_attr_auth_type, "Unknown %d"));
break;
case ISAKMP_ATTR_KEY_LENGTH:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_key_length, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %d", tvb_get_ntohs(tvb, offset));
break;
case ISAKMP_ATTR_KEY_ROUNDS:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_key_rounds, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %d", tvb_get_ntohs(tvb, offset));
break;
case ISAKMP_ATTR_CMPR_DICT_SIZE:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_cmpr_dict_size, tvb, offset, optlen, ENC_BIG_ENDIAN);
break;
case ISAKMP_ATTR_CMPR_ALGORITHM:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_cmpr_algorithm, tvb, offset, optlen, ENC_NA);
break;
case ISAKMP_ATTR_ECN_TUNNEL:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_ecn_tunnel, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %s", val_to_str(tvb_get_ntohs(tvb, offset), transform_attr_ecn_type, "Unknown %d"));
break;
case ISAKMP_ATTR_EXT_SEQ_NBR:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_ext_seq_nbr, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %s", val_to_str(tvb_get_ntohs(tvb, offset), transform_attr_ext_seq_nbr_type, "Unknown %d"));
case ISAKMP_ATTR_AUTH_KEY_LENGTH:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_auth_key_length, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %d", tvb_get_ntohs(tvb, offset));
break;
case ISAKMP_ATTR_SIG_ENCO_ALGORITHM:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_sig_enco_algorithm, tvb, offset, optlen, ENC_NA);
break;
case ISAKMP_ATTR_ADDR_PRESERVATION:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_addr_preservation, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %s", val_to_str(tvb_get_ntohs(tvb, offset), transform_attr_addr_preservation_type, "Unknown %d"));
break;
case ISAKMP_ATTR_SA_DIRECTION:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_tf_attr_sa_direction, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %s", val_to_str(tvb_get_ntohs(tvb, offset), transform_attr_sa_direction_type, "Unknown %d"));
default:
break;
}
return 2+len+optlen;
}
static int
dissect_transform_ike_attribute(tvbuff_t *tvb, proto_tree *transform_attr_type_tree, int offset
#ifdef HAVE_LIBGCRYPT
, decrypt_data_t *decr
#endif
)
{
guint optlen, transform_attr_type, len = 0;
proto_item *transform_attr_type_item = NULL;
proto_tree *sub_transform_attr_type_tree = NULL;
transform_attr_type = tvb_get_ntohs(tvb, offset);
optlen = tvb_get_ntohs(tvb, offset+2);
len = 2;
if (transform_attr_type & 0x8000) {
transform_attr_type = transform_attr_type & 0x7fff;
len = 0;
optlen = 2;
}
transform_attr_type_item = proto_tree_add_item(transform_attr_type_tree, hf_isakmp_ike_attr, tvb, offset, 2+len+optlen, ENC_NA);
proto_item_append_text(transform_attr_type_item," (t=%d,l=%d) %s",transform_attr_type, optlen, val_to_str(transform_attr_type,transform_ike_attr_type,"Unknown Attribute Type (%02d)") );
sub_transform_attr_type_tree = proto_item_add_subtree(transform_attr_type_item, ett_isakmp_tf_ike_attr);
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_format, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint(sub_transform_attr_type_tree, hf_isakmp_ike_attr_type, tvb, offset, 2, transform_attr_type);
offset += 2;
if (len)
{
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (optlen==0)
{
proto_tree_add_text(sub_transform_attr_type_tree, tvb, offset, 0,"Attribut value is empty");
return 2+len;
}
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_value, tvb, offset, optlen, ENC_NA);
switch(transform_attr_type) {
case IKE_ATTR_ENCRYPTION_ALGORITHM:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_encryption_algorithm, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %s", val_to_str(tvb_get_ntohs(tvb, offset), transform_attr_enc_type, "Unknown %d"));
#ifdef HAVE_LIBGCRYPT
decr->encr_alg = tvb_get_ntohs(tvb, offset);
#endif
break;
case IKE_ATTR_HASH_ALGORITHM:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_hash_algorithm, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %s", val_to_str(tvb_get_ntohs(tvb, offset), transform_attr_hash_type, "Unknown %d"));
#ifdef HAVE_LIBGCRYPT
decr->hash_alg = tvb_get_ntohs(tvb, offset);
#endif
break;
case IKE_ATTR_AUTHENTICATION_METHOD:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_authentication_method, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %s", val_to_str(tvb_get_ntohs(tvb, offset), transform_attr_authmeth_type, "Unknown %d"));
#ifdef HAVE_LIBGCRYPT
decr->is_psk = tvb_get_ntohs(tvb, offset) == 0x01 ? TRUE : FALSE;
#endif
break;
case IKE_ATTR_GROUP_DESCRIPTION:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_group_description, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %s", val_to_str(tvb_get_ntohs(tvb, offset), transform_dh_group_type, "Unknown %d"));
#ifdef HAVE_LIBGCRYPT
decr->group = tvb_get_ntohs(tvb, offset);
#endif
break;
case IKE_ATTR_GROUP_TYPE:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_group_type, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %s", val_to_str(tvb_get_ntohs(tvb, offset), transform_attr_grp_type, "Unknown %d"));
break;
case IKE_ATTR_GROUP_PRIME:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_group_prime, tvb, offset, optlen, ENC_NA);
break;
case IKE_ATTR_GROUP_GENERATOR_ONE:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_group_generator_one, tvb, offset, optlen, ENC_NA);
break;
case IKE_ATTR_GROUP_GENERATOR_TWO:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_group_generator_two, tvb, offset, optlen, ENC_NA);
break;
case IKE_ATTR_GROUP_CURVE_A:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_group_curve_a, tvb, offset, optlen, ENC_NA);
break;
case IKE_ATTR_GROUP_CURVE_B:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_group_curve_b, tvb, offset, optlen, ENC_NA);
break;
case IKE_ATTR_LIFE_TYPE:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_life_type, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %s", val_to_str(tvb_get_ntohs(tvb, offset), transform_attr_sa_life_type, "Unknown %d"));
break;
case IKE_ATTR_LIFE_DURATION:
dissect_life_duration(tvb, sub_transform_attr_type_tree, transform_attr_type_item, hf_isakmp_ike_attr_life_duration_uint32, hf_isakmp_ike_attr_life_duration_uint64, hf_isakmp_ike_attr_life_duration_bytes, offset, optlen);
break;
case IKE_ATTR_PRF:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_prf, tvb, offset, optlen, ENC_NA);
break;
case IKE_ATTR_KEY_LENGTH:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_key_length, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %d", tvb_get_ntohs(tvb, offset));
break;
case IKE_ATTR_FIELD_SIZE:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_field_size, tvb, offset, optlen, ENC_NA);
break;
case IKE_ATTR_GROUP_ORDER:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike_attr_group_order, tvb, offset, optlen, ENC_NA);
break;
default:
break;
}
return 2+len+optlen;
}
static int
dissect_transform_ike2_attribute(tvbuff_t *tvb, proto_tree *transform_attr_type_tree, int offset )
{
guint optlen, transform_attr_type, len = 0;
proto_item *transform_attr_type_item = NULL;
proto_tree *sub_transform_attr_type_tree = NULL;
transform_attr_type = tvb_get_ntohs(tvb, offset);
optlen = tvb_get_ntohs(tvb, offset+2);
len = 2;
if (transform_attr_type & 0x8000) {
transform_attr_type = transform_attr_type & 0x7fff;
len = 0;
optlen = 2;
}
transform_attr_type_item = proto_tree_add_item(transform_attr_type_tree, hf_isakmp_ike2_attr, tvb, offset, 2+len+optlen, ENC_NA);
proto_item_append_text(transform_attr_type_item," (t=%d,l=%d) %s",transform_attr_type, optlen, val_to_str(transform_attr_type,transform_ike2_attr_type,"Unknown Attribute Type (%02d)") );
sub_transform_attr_type_tree = proto_item_add_subtree(transform_attr_type_item, ett_isakmp_tf_ike2_attr);
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike2_attr_format, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint(sub_transform_attr_type_tree, hf_isakmp_ike2_attr_type, tvb, offset, 2, transform_attr_type);
offset += 2;
if (len)
{
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike2_attr_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (optlen==0)
{
proto_tree_add_text(sub_transform_attr_type_tree, tvb, offset, 0,"Attribut value is empty");
return 2+len;
}
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike2_attr_value, tvb, offset, optlen, ENC_NA);
switch(transform_attr_type) {
case IKE2_ATTR_KEY_LENGTH:
proto_tree_add_item(sub_transform_attr_type_tree, hf_isakmp_ike2_attr_key_length, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(transform_attr_type_item," : %d", tvb_get_ntohs(tvb, offset));
break;
default:
break;
}
return 2+len+optlen;
}
static void
dissect_transform(tvbuff_t *tvb, int offset, int length, proto_tree *tree, int isakmp_version, int protocol_id, void* decr_data
#ifndef HAVE_LIBGCRYPT
_U_
#endif
)
{
if (isakmp_version == 1)
{
guint8 transform_id;
guint8 transform_num;
#ifdef HAVE_LIBGCRYPT
decrypt_data_t *decr = (decrypt_data_t *)decr_data;
#endif
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
offset += 3;
if (protocol_id == 1 && transform_id == 1) {
while (offset < offset_end) {
offset += dissect_transform_ike_attribute(tvb, tree, offset
#ifdef HAVE_LIBGCRYPT
, decr
#endif
);
}
}
else {
while (offset < offset_end) {
offset += dissect_transform_attribute(tvb, tree, offset);
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
offset += dissect_transform_ike2_attribute(tvb, tree, offset);
}
}
}
static void
dissect_key_exch(tvbuff_t *tvb, int offset, int length, proto_tree *tree, int isakmp_version,
#ifdef HAVE_LIBGCRYPT
packet_info* pinfo,
void* decr_data
#else
packet_info* pinfo _U_,
void* decr_data _U_
#endif
)
{
#ifdef HAVE_LIBGCRYPT
decrypt_data_t *decr = (decrypt_data_t *)decr_data;
#endif
if (isakmp_version == 2) {
proto_tree_add_item(tree, hf_isakmp_key_exch_dh_group, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
}
proto_tree_add_item(tree, hf_isakmp_key_exch_data, tvb, offset, length, ENC_NA);
#ifdef HAVE_LIBGCRYPT
if (decr && decr->gi_len == 0 && ADDRESSES_EQUAL(&decr->initiator, &pinfo->src)) {
decr->gi = (gchar *)g_malloc(length);
tvb_memcpy(tvb, decr->gi, offset, length);
decr->gi_len = length;
} else if (decr && decr->gr_len == 0 && !ADDRESSES_EQUAL(&decr->initiator, &pinfo->src)) {
decr->gr = (gchar *)g_malloc(length);
tvb_memcpy(tvb, decr->gr, offset, length);
decr->gr_len = length;
}
#endif
}
static void
dissect_id(tvbuff_t *tvb, int offset, int length, proto_tree *tree, int isakmp_version, packet_info *pinfo )
{
guint8 id_type;
guint8 protocol_id;
guint16 port;
proto_item *idit;
proto_tree *idtree;
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
protocol_id= tvb_get_guint8(tvb, offset);
if (protocol_id == 0)
proto_tree_add_uint_format_value(tree, hf_isakmp_id_protoid, tvb, offset,1,
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
idit = proto_tree_add_item(tree, hf_isakmp_id_data, tvb, offset, length, ENC_NA);
idtree = proto_item_add_subtree(idit, ett_isakmp_id);
switch (id_type) {
case IKE_ID_IPV4_ADDR:
proto_tree_add_item(idtree, hf_isakmp_id_data_ipv4_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(idit, "%s", tvb_ip_to_str(tvb, offset));
break;
case IKE_ID_FQDN:
proto_tree_add_item(idtree, hf_isakmp_id_data_fqdn, tvb, offset, length, ENC_ASCII|ENC_NA);
proto_item_append_text(idit, "%s", tvb_get_string(wmem_packet_scope(), tvb, offset,length));
break;
case IKE_ID_USER_FQDN:
proto_tree_add_item(idtree, hf_isakmp_id_data_user_fqdn, tvb, offset, length, ENC_ASCII|ENC_NA);
proto_item_append_text(idit, "%s", tvb_get_string(wmem_packet_scope(), tvb, offset,length));
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
proto_item_append_text(idit, "%s", tvb_bytes_to_ep_str(tvb,offset,length));
break;
}
}
static void
dissect_cert(tvbuff_t *tvb, int offset, int length _U_, proto_tree *tree, int isakmp_version, packet_info *pinfo )
{
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
if (isakmp_version == 1)
{
proto_tree_add_item(tree, hf_isakmp_cert_encoding_v1, tvb, offset, 1, ENC_BIG_ENDIAN);
}else if (isakmp_version == 2)
{
proto_tree_add_item(tree, hf_isakmp_cert_encoding_v2, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
dissect_x509af_Certificate(FALSE, tvb, offset, &asn1_ctx, tree, hf_isakmp_cert_data);
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
offset += 4;
length -= 4;
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
proto_tree *ptree = NULL;
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
tvbuff_t *defrag_isakmp_tvb = NULL;
fragment_head *frag_msg = NULL;
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_check(&isakmp_reassembly_table, tvb, offset,
pinfo,
12345,
NULL,
seq-1,
tvb_length_remaining(tvb, offset),
last);
defrag_isakmp_tvb = process_reassembled_data(tvb, offset, pinfo,
"Reassembled ISAKMP", frag_msg, &isakmp_frag_items,
NULL, ptree);
if (defrag_isakmp_tvb) {
dissect_isakmp(defrag_isakmp_tvb, pinfo, ptree, NULL);
}
col_append_fstr(pinfo->cinfo, COL_INFO,
" (%sMessage fragment %u%s)",
(frag_msg ? "Reassembled + " : ""),
seq, (last ? " - last" : ""));
pinfo->fragmented = save_fragmented;
}
}
static void
dissect_notif(tvbuff_t *tvb, int offset, int length, proto_tree *tree, int isakmp_version)
{
guint8 spi_size;
guint16 msgtype;
int offset_end = 0;
offset_end = offset + length;
if (isakmp_version == 1) {
proto_tree_add_item(tree, hf_isakmp_notify_doi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
}
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
proto_tree_add_item(tree, hf_isakmp_notify_msgtype_v2, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
length -= 2;
if (spi_size) {
proto_tree_add_item(tree, hf_isakmp_spi, tvb, offset, spi_size, ENC_NA);
offset += spi_size;
length -= spi_size;
}
proto_tree_add_item(tree, hf_isakmp_notify_data, tvb, offset, length, ENC_NA);
if (isakmp_version == 1)
{
switch (msgtype) {
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
length -= tvb_get_guint8(tvb, offset+1) - 2;
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
offset += dissect_rohc_supported(tvb, tree, offset);
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
proto_tree_add_item(tree, hf_isakmp_delete_doi, tvb, offset, 1, ENC_BIG_ENDIAN);
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
vendorstring = byte_to_str(pVID, (gint)length, vendor_id, "Unknown Vendor ID");
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
return offset;
}
static int
dissect_config_attribute(tvbuff_t *tvb, proto_tree *cfg_attr_type_tree, int offset, int isakmp_version)
{
guint optlen, cfg_attr_type, len = 0;
int offset_end = 0;
proto_item *cfg_attr_type_item = NULL;
proto_tree *sub_cfg_attr_type_tree = NULL;
cfg_attr_type = tvb_get_ntohs(tvb, offset);
optlen = tvb_get_ntohs(tvb, offset+2);
len = 2;
if (cfg_attr_type & 0x8000) {
cfg_attr_type = cfg_attr_type & 0x7fff;
len = 0;
optlen = 2;
}
if (isakmp_version == 1) {
cfg_attr_type_item = proto_tree_add_none_format(cfg_attr_type_tree, hf_isakmp_cfg_attr, tvb, offset, 2+len+optlen, "Attribute Type: (t=%d,l=%d) %s", cfg_attr_type, optlen, rval_to_str(cfg_attr_type,vs_v1_cfgattr,"Unknown Attribute Type (%02d)") );
sub_cfg_attr_type_tree = proto_item_add_subtree(cfg_attr_type_item, ett_isakmp_cfg_attr);
proto_tree_add_uint(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_type_v1, tvb, offset, 2, cfg_attr_type);
} else if (isakmp_version == 2) {
cfg_attr_type_item = proto_tree_add_none_format(cfg_attr_type_tree, hf_isakmp_cfg_attr, tvb, offset, 2+len+optlen, "Attribute Type: (t=%d,l=%d) %s", cfg_attr_type, optlen, rval_to_str(cfg_attr_type,vs_v2_cfgattr,"Unknown Attribute Type (%02d)") );
sub_cfg_attr_type_tree = proto_item_add_subtree(cfg_attr_type_item, ett_isakmp_cfg_attr);
proto_tree_add_uint(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_type_v2, tvb, offset, 2, cfg_attr_type);
}
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_format, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (len)
{
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (optlen==0)
{
proto_tree_add_text(sub_cfg_attr_type_tree, tvb, offset, 0,"Attribut value is empty");
return 2+len;
}
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_value, tvb, offset, optlen, ENC_NA);
switch (cfg_attr_type) {
case INTERNAL_IP4_ADDRESS:
offset_end = offset + optlen;
if (optlen%4 == 0)
{
while (offset_end-offset > 0)
{
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip4_address, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
break;
case INTERNAL_IP4_NETMASK:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip4_netmask, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case INTERNAL_IP4_DNS:
offset_end = offset + optlen;
if (optlen%4 == 0)
{
while (offset_end-offset > 0)
{
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip4_dns, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
break;
case INTERNAL_IP4_NBNS:
offset_end = offset + optlen;
if (optlen%4 == 0)
{
while (offset_end-offset > 0)
{
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip4_nbns, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
break;
case INTERNAL_ADDRESS_EXPIRY:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_address_expiry, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case INTERNAL_IP4_DHCP:
offset_end = offset + optlen;
if (optlen%4 == 0)
{
while (offset_end-offset > 0)
{
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip4_dhcp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
break;
case APPLICATION_VERSION:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_application_version, tvb, offset, optlen, ENC_ASCII|ENC_NA);
proto_item_append_text(cfg_attr_type_item," : %s", tvb_get_string(wmem_packet_scope(), tvb, offset,optlen));
break;
case INTERNAL_IP6_ADDRESS:
offset_end = offset + optlen;
if (optlen%16 == 0)
{
while (offset_end-offset > 0)
{
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip6_address, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
}
}
break;
case INTERNAL_IP6_NETMASK:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip6_netmask, tvb, offset, 18, ENC_NA);
break;
case INTERNAL_IP6_DNS:
offset_end = offset + optlen;
if (optlen%16 == 0)
{
while (offset_end-offset > 0)
{
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip6_dns, tvb, offset, 16, ENC_NA);
offset += 16;
}
}
break;
case INTERNAL_IP6_NBNS:
offset_end = offset + optlen;
if (optlen%16 == 0)
{
while (offset_end-offset > 0)
{
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip6_nbns, tvb, offset, 16, ENC_NA);
offset += 16;
}
}
break;
case INTERNAL_IP6_DHCP:
offset_end = offset + optlen;
if (optlen%16 == 0)
{
while (offset_end-offset > 0)
{
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip6_dhcp, tvb, offset, 16, ENC_NA);
offset += 16;
}
}
break;
case INTERNAL_IP4_SUBNET:
offset_end = offset + optlen;
if (optlen%8 == 0)
{
while (offset_end-offset > 0)
{
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip4_subnet_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip4_subnet_netmask, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 8;
}
}
break;
case SUPPORTED_ATTRIBUTES:
offset_end = offset + optlen;
if (optlen%2 == 0)
{
while (offset_end-offset > 0)
{
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_supported_attributes, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
break;
case INTERNAL_IP6_SUBNET:
offset_end = offset + optlen;
if (optlen%17 == 0)
{
while (offset_end-offset > 0)
{
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip6_subnet_ip, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip6_subnet_prefix, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
break;
case INTERNAL_IP6_LINK:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip6_link_interface, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip6_link_id, tvb, offset, optlen-8, ENC_NA);
break;
case INTERNAL_IP6_PREFIX:
offset_end = offset + optlen;
if (optlen%17 == 0)
{
while (offset_end-offset > 0)
{
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip6_prefix_ip, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_internal_ip6_prefix_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
break;
case XAUTH_TYPE:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_xauth_type, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(cfg_attr_type_item," : %s", rval_to_str(tvb_get_ntohs(tvb, offset), cfgattr_xauth_type, "Unknown %d"));
break;
case XAUTH_USER_NAME:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_xauth_user_name, tvb, offset, optlen, ENC_ASCII|ENC_NA);
proto_item_append_text(cfg_attr_type_item," : %s", tvb_get_string(wmem_packet_scope(), tvb, offset,optlen));
break;
case XAUTH_USER_PASSWORD:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_xauth_user_password, tvb, offset, optlen, ENC_ASCII|ENC_NA);
proto_item_append_text(cfg_attr_type_item," : %s", tvb_get_string(wmem_packet_scope(), tvb, offset,optlen));
break;
case XAUTH_PASSCODE:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_xauth_passcode, tvb, offset, optlen, ENC_ASCII|ENC_NA);
proto_item_append_text(cfg_attr_type_item," : %s", tvb_get_string(wmem_packet_scope(), tvb, offset,optlen));
break;
case XAUTH_MESSAGE:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_xauth_message, tvb, offset, optlen, ENC_ASCII|ENC_NA);
proto_item_append_text(cfg_attr_type_item," : %s", tvb_get_string(wmem_packet_scope(), tvb, offset,optlen));
break;
case XAUTH_CHALLENGE:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_xauth_challenge, tvb, offset, optlen, ENC_ASCII|ENC_NA);
proto_item_append_text(cfg_attr_type_item," : %s", tvb_get_string(wmem_packet_scope(), tvb, offset,optlen));
break;
case XAUTH_DOMAIN:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_xauth_domain, tvb, offset, optlen, ENC_ASCII|ENC_NA);
proto_item_append_text(cfg_attr_type_item," : %s", tvb_get_string(wmem_packet_scope(), tvb, offset,optlen));
break;
case XAUTH_STATUS:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_xauth_status, tvb, offset, optlen, ENC_BIG_ENDIAN);
proto_item_append_text(cfg_attr_type_item," : %s", val_to_str(tvb_get_ntohs(tvb, offset), cfgattr_xauth_status, "Unknown %d"));
break;
case XAUTH_NEXT_PIN:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_xauth_next_pin, tvb, offset, optlen, ENC_ASCII|ENC_NA);
proto_item_append_text(cfg_attr_type_item," : %s", tvb_get_string(wmem_packet_scope(), tvb, offset,optlen));
break;
case XAUTH_ANSWER:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_xauth_answer, tvb, offset, optlen, ENC_ASCII|ENC_NA);
proto_item_append_text(cfg_attr_type_item," : %s", tvb_get_string(wmem_packet_scope(), tvb, offset,optlen));
break;
case UNITY_BANNER:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_unity_banner, tvb, offset, optlen, ENC_ASCII|ENC_NA);
proto_item_append_text(cfg_attr_type_item," : %s", tvb_get_string(wmem_packet_scope(), tvb, offset,optlen));
break;
case UNITY_DEF_DOMAIN:
proto_tree_add_item(sub_cfg_attr_type_tree, hf_isakmp_cfg_attr_unity_def_domain, tvb, offset, optlen, ENC_ASCII|ENC_NA);
proto_item_append_text(cfg_attr_type_item," : %s", tvb_get_string(wmem_packet_scope(), tvb, offset,optlen));
break;
default:
break;
}
return 2+len+optlen;
}
static void
dissect_config(tvbuff_t *tvb, int offset, int length, proto_tree *tree, int isakmp_version)
{
int offset_end = 0;
offset_end = offset + length;
if (isakmp_version == 1) {
proto_tree_add_item(tree, hf_isakmp_cfg_type_v1,tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_isakmp_cfg_identifier,tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 2;
} else if (isakmp_version == 2) {
proto_tree_add_item(tree, hf_isakmp_cfg_type_v2,tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 4;
}
while (offset < offset_end) {
offset += dissect_config_attribute(tvb, tree, offset, isakmp_version);
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
static void
dissect_ts(tvbuff_t *tvb, int offset, int length, proto_tree *tree)
{
guint8 num, tstype, protocol_id;
num = tvb_get_guint8(tvb, offset);
proto_item_append_text(tree," # %d", num);
proto_tree_add_item(tree, hf_isakmp_ts_number_of_ts, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
offset += 3;
length -= 3;
while (length > 0) {
tstype = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_isakmp_ts_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
switch (tstype) {
case IKEV2_TS_IPV4_ADDR_RANGE:
protocol_id = tvb_get_guint8(tvb, offset);
if (protocol_id == 0)
proto_tree_add_uint_format_value(tree, hf_isakmp_ts_protoid, tvb, offset,1,
protocol_id, "Unused");
else
proto_tree_add_item(tree, hf_isakmp_ts_protoid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
proto_tree_add_item(tree, hf_isakmp_ts_selector_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
proto_tree_add_item(tree, hf_isakmp_ts_start_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
proto_tree_add_item(tree, hf_isakmp_ts_end_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
proto_tree_add_item(tree, hf_isakmp_ts_start_addr_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
proto_tree_add_item(tree, hf_isakmp_ts_end_addr_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
break;
case IKEV2_TS_IPV6_ADDR_RANGE:
protocol_id = tvb_get_guint8(tvb, offset);
if (protocol_id == 0)
proto_tree_add_uint_format_value(tree, hf_isakmp_ts_protoid, tvb, offset,1,
protocol_id, "Unused");
else
proto_tree_add_item(tree, hf_isakmp_ts_protoid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
proto_tree_add_item(tree, hf_isakmp_ts_selector_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
proto_tree_add_item(tree, hf_isakmp_ts_start_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
proto_tree_add_item(tree, hf_isakmp_ts_end_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
proto_tree_add_item(tree, hf_isakmp_ts_start_addr_ipv6, tvb, offset, 16, ENC_NA);
offset += 16;
length -= 16;
proto_tree_add_item(tree, hf_isakmp_ts_end_addr_ipv6, tvb, offset, 16, ENC_NA);
offset += 16;
length -= 16;
break;
case IKEV2_TS_FC_ADDR_RANGE:
offset += 1;
length -= 1;
proto_tree_add_item(tree, hf_isakmp_ts_selector_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
offset += 1;
length -= 1;
proto_tree_add_item(tree, hf_isakmp_ts_start_addr_fc, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
length -= 3;
offset += 1;
length -= 1;
proto_tree_add_item(tree, hf_isakmp_ts_end_addr_fc, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
length -= 3;
proto_tree_add_item(tree, hf_isakmp_ts_start_r_ctl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
proto_tree_add_item(tree, hf_isakmp_ts_end_r_ctl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
proto_tree_add_item(tree, hf_isakmp_ts_start_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
proto_tree_add_item(tree, hf_isakmp_ts_end_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
break;
default:
proto_tree_add_item(tree, hf_isakmp_ts_data, tvb, offset, length, ENC_NA);
offset += length;
length -= length;
break;
}
}
}
static void
dissect_eap(tvbuff_t *tvb, int offset, int length, proto_tree *tree, packet_info *pinfo)
{
tvbuff_t *eap_tvb = NULL;
eap_tvb = tvb_new_subset(tvb, offset,length, length );
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
guint hash = 0, keychunk, i;
for (i = 0; i < key->spii_len - (key->spii_len % (guint)sizeof(keychunk)); i += (guint)sizeof(keychunk)) {
memcpy(&keychunk, &key->spii[i], sizeof(keychunk));
hash ^= keychunk;
}
for (i = 0; i < key->spir_len - (key->spir_len % (guint)sizeof(keychunk)); i += (guint)sizeof(keychunk)) {
memcpy(&keychunk, &key->spir[i], sizeof(keychunk));
hash ^= keychunk;
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
static gboolean
free_cookie(gpointer key_arg, gpointer value, gpointer user_data _U_)
{
guint8 *ic_key = (guint8 *)key_arg;
decrypt_data_t *decr = (decrypt_data_t *)value;
g_slice_free1(COOKIE_SIZE, ic_key);
g_slice_free1(sizeof(decrypt_data_t), decr);
return TRUE;
}
static void
isakmp_init_protocol(void) {
#ifdef HAVE_LIBGCRYPT
guint i;
decrypt_data_t *decr;
guint8 *ic_key;
#endif
reassembly_table_init(&isakmp_reassembly_table,
&addresses_reassembly_table_functions);
#ifdef HAVE_LIBGCRYPT
if (isakmp_hash) {
g_hash_table_foreach_remove(isakmp_hash, free_cookie, NULL);
g_hash_table_destroy(isakmp_hash);
}
isakmp_hash = g_hash_table_new(isakmp_hash_func, isakmp_equal_func);
for (i = 0; i < num_ikev1_uat_data; i++) {
ic_key = (guint8 *)g_slice_alloc(COOKIE_SIZE);
decr = (decrypt_data_t *)g_slice_alloc(sizeof(decrypt_data_t));
memcpy(ic_key, ikev1_uat_data[i].icookie, COOKIE_SIZE);
memset(decr, 0, sizeof(decrypt_data_t));
memcpy(decr->secret, ikev1_uat_data[i].key, ikev1_uat_data[i].key_len);
decr->secret_len = ikev1_uat_data[i].key_len;
g_hash_table_insert(isakmp_hash, ic_key, decr);
}
if (ikev2_key_hash) {
g_hash_table_destroy(ikev2_key_hash);
}
ikev2_key_hash = g_hash_table_new(ikev2_key_hash_func, ikev2_key_equal_func);
for (i = 0; i < num_ikev2_uat_data; i++) {
g_hash_table_insert(ikev2_key_hash, &(ikev2_uat_data[i].key), &(ikev2_uat_data[i]));
}
#endif
}
static void
isakmp_prefs_apply_cb(void) {
isakmp_init_protocol();
}
static void ikev1_uat_data_update_cb(void* p, const char** err) {
ikev1_uat_data_key_t *ud = (ikev1_uat_data_key_t *)p;
if (ud->icookie_len != COOKIE_SIZE) {
*err = g_strdup_printf("Length of Initiator's COOKIE must be %d octets (%d hex characters).", COOKIE_SIZE, COOKIE_SIZE * 2);
return;
}
if (ud->key_len == 0) {
*err = g_strdup_printf("Must have Encryption key.");
return;
}
if (ud->key_len > MAX_KEY_SIZE) {
*err = g_strdup_printf("Length of Encryption key limited to %d octets (%d hex characters).", MAX_KEY_SIZE, MAX_KEY_SIZE * 2);
return;
}
}
static void ikev2_uat_data_update_cb(void* p, const char** err) {
ikev2_uat_data_t *ud = (ikev2_uat_data_t *)p;
if (ud->key.spii_len != COOKIE_SIZE) {
*err = g_strdup_printf("Length of Initiator's SPI must be %d octets (%d hex characters).", COOKIE_SIZE, COOKIE_SIZE * 2);
return;
}
if (ud->key.spir_len != COOKIE_SIZE) {
*err = g_strdup_printf("Length of Responder's SPI must be %d octets (%d hex characters).", COOKIE_SIZE, COOKIE_SIZE * 2);
return;
}
if ((ud->encr_spec = ikev2_decrypt_find_encr_spec(ud->encr_alg)) == NULL) {
REPORT_DISSECTOR_BUG("Couldn't get IKEv2 encryption algorithm spec.");
}
if ((ud->auth_spec = ikev2_decrypt_find_auth_spec(ud->auth_alg)) == NULL) {
REPORT_DISSECTOR_BUG("Couldn't get IKEv2 authentication algorithm spec.");
}
if (ud->sk_ei_len != ud->encr_spec->key_len) {
*err = g_strdup_printf("Length of SK_ei (%u octets) does not match the key length (%u octets) of the selected encryption algorithm.",
ud->sk_ei_len, ud->encr_spec->key_len);
return;
}
if (ud->sk_er_len != ud->encr_spec->key_len) {
*err = g_strdup_printf("Length of SK_er (%u octets) does not match the key length (%u octets) of the selected encryption algorithm.",
ud->sk_er_len, ud->encr_spec->key_len);
return;
}
if (ud->sk_ai_len != ud->auth_spec->key_len) {
*err = g_strdup_printf("Length of SK_ai (%u octets) does not match the key length (%u octets) of the selected integrity algorithm.",
ud->sk_ai_len, ud->auth_spec->key_len);
return;
}
if (ud->sk_ar_len != ud->auth_spec->key_len) {
*err = g_strdup_printf("Length of SK_ar (%u octets) does not match the key length (%u octets) of the selected integrity algorithm.",
ud->sk_ar_len, ud->auth_spec->key_len);
return;
}
}
void
proto_register_isakmp(void)
{
#ifdef HAVE_LIBGCRYPT
module_t *isakmp_module;
#endif
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
{ "Type Payload", "isakmp.typepayload",
FT_UINT8,BASE_RANGE_STRING | BASE_DEC, RVALS(payload_type), 0x0,
"ISAKMP Type Payload", HFILL }},
{ &hf_isakmp_nextpayload,
{ "Next payload", "isakmp.nextpayload",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(payload_type), 0x0,
"ISAKMP Next Payload", HFILL }},
{ &hf_isakmp_criticalpayload,
{ "Critical Bit", "isakmp.criticalpayload",
FT_BOOLEAN, 8,TFS(&criticalpayload), 0x80,
"ISAKMP (v2) Critical Payload", HFILL }},
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
"ISAKMP (v1) ID Type", HFILL }},
{ &hf_isakmp_id_type_v2,
{ "ID type", "isakmp.id.type",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(vs_v2_id_type), 0x0,
"ISAKMP (v2) ID Type", HFILL }},
{ &hf_isakmp_id_protoid,
{ "Protocol ID", "isakmp.id.protoid",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, (&ipproto_val_ext), 0x0,
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
"The type specifies an opaque byte stream which may be used to pass vendor-specific information necessary to identify which pre-hared key should be used to authenticate Aggressive mode negotiations", HFILL }},
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
{ &hf_isakmp_notify_data_rohc_attr,
{ "ROHC Attribute Type", "isakmp.notify.data.rohc.attr",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_notify_data_rohc_attr_type,
{ "ROHC Attribute Type", "isakmp.notify.data.rohc.attr.type",
FT_UINT16, BASE_DEC, VALS(rohc_attr_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_notify_data_rohc_attr_format,
{ "ROHC Format", "isakmp.notify.data.rohc.attr.format",
FT_BOOLEAN, 16, TFS(&attribute_format), 0x8000,
NULL, HFILL }},
{ &hf_isakmp_notify_data_rohc_attr_length,
{ "Length", "isakmp.notify.data.rohc.attr.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_notify_data_rohc_attr_value,
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
{ &hf_isakmp_ts_number_of_ts,
{ "Number of Traffic Selector", "isakmp.ts.number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_type,
{ "Traffic Selector Type", "isakmp.ts.type",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(traffic_selector_type), 0x0,
NULL, HFILL }},
{ &hf_isakmp_ts_protoid,
{ "Protocol ID", "isakmp.ts.protoid",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, (&ipproto_val_ext), 0x0,
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
{ "Traffic Selector Data", "isakmp.ts.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isakmp_num_spis,
{ "Port", "isakmp.spinum",
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
{ "Certificate Authority Signature", "ike.certreq.authority.sig",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_isakmp_certreq_authority_v1,
{ "Certificate Authority Data", "ike.certreq.authority",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_isakmp_certreq_authority_v2,
{ "Certificate Authority Data", "ike.certreq.authority",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SHA-1 hash of the Certificate Authority", HFILL } },
{ &hf_isakmp_nat_keepalive,
{ "NAT Keepalive", "ike.nat_keepalive",
FT_NONE, BASE_NONE, NULL, 0x0, "NAT Keepalive packet", HFILL } },
{ &hf_isakmp_nat_hash,
{ "HASH of the address and port", "ike.nat_hash",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_nat_original_address_ipv4,
{ "NAT Original IPv4 Address", "ike.nat_original_address_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_nat_original_address_ipv6,
{ "NAT Original IPv6 Address", "ike.nat_original_address_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr,
{ "Transform Attribute Type", "isakmp.tf.attr",
FT_NONE, BASE_NONE, NULL, 0x00,
"ISAKMP Transform Attribute", HFILL }},
{ &hf_isakmp_tf_attr_type_v1,
{ "Transform Attribute Type", "isakmp.tf.attr.type_v1",
FT_UINT16, BASE_DEC, VALS(transform_isakmp_attr_type), 0x00,
"ISAKMP (v1) Transform Attribute type", HFILL }},
{ &hf_isakmp_tf_attr_format,
{ "Transform Format", "isakmp.tf.attr.format",
FT_BOOLEAN, 16, TFS(&attribute_format), 0x8000,
"ISAKMP Transform Attribute Format", HFILL }},
{ &hf_isakmp_tf_attr_length,
{ "Length", "isakmp.tf.attr.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
"ISAKMP Tranform Attribute length", HFILL }},
{ &hf_isakmp_tf_attr_value,
{ "Value", "isakmp.tf.attr.value",
FT_BYTES, BASE_NONE, NULL, 0x00,
"ISAKMP Transform Attribute value", HFILL }},
{ &hf_isakmp_tf_attr_life_type,
{ "Life Type", "isakmp.tf.attr.life_type",
FT_UINT16, BASE_DEC, VALS(transform_attr_sa_life_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_life_duration_uint32,
{ "Life Duration", "isakmp.tf.attr.life_duration",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_life_duration_uint64,
{ "Life Duration", "isakmp.tf.attr.life_duration",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_life_duration_bytes,
{ "Life Duration", "isakmp.tf.attr.life_duration",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_group_description,
{ "Group Description", "isakmp.tf.attr.group_description",
FT_UINT16, BASE_DEC, VALS(transform_dh_group_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_encap_mode,
{ "Encapsulation Mode", "isakmp.tf.attr.encap_mode",
FT_UINT16, BASE_DEC, VALS(transform_attr_encap_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_auth_algorithm,
{ "Authentication Algorithm", "isakmp.tf.attr.auth_algorithm",
FT_UINT16, BASE_DEC, VALS(transform_attr_auth_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_key_length,
{ "Key Length", "isakmp.tf.attr.key_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_key_rounds,
{ "Key Rounds", "isakmp.tf.attr.key_rounds",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_cmpr_dict_size,
{ "Compress Dictionary Size", "isakmp.tf.attr.cmpr_dict_size",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_cmpr_algorithm,
{ "Compress Private Algorithm", "isakmp.tf.attr.cmpr_algorithm",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_ecn_tunnel,
{ "ECN Tunnel", "isakmp.tf.attr.ecn_tunnel",
FT_UINT16, BASE_DEC, VALS(transform_attr_ecn_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_ext_seq_nbr,
{ "Extended (64-bit) Sequence Number", "isakmp.tf.attr.ext_seq_nbr",
FT_UINT16, BASE_DEC, VALS(transform_attr_ext_seq_nbr_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_auth_key_length,
{ "Authentication Key Length", "isakmp.tf.attr.auth_key_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_sig_enco_algorithm,
{ "Signature Encoding Algorithm", "isakmp.tf.attr.sig_enco_algorithm",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_addr_preservation,
{ "Address Preservation", "isakmp.tf.attr.addr_preservation",
FT_UINT16, BASE_DEC, VALS(transform_attr_addr_preservation_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_tf_attr_sa_direction,
{ "SA Direction", "isakmp.tf.attr.sa_direction",
FT_UINT16, BASE_DEC, VALS(transform_attr_sa_direction_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr,
{ "Transform IKE Attribute Type", "isakmp.ike.attr",
FT_NONE, BASE_NONE, NULL, 0x00,
"IKE Transform Attribute", HFILL }},
{ &hf_isakmp_ike_attr_type,
{ "Transform IKE Attribute Type", "isakmp.ike.attr.type",
FT_UINT16, BASE_DEC, VALS(transform_ike_attr_type), 0x00,
"IKE Transform Attribute type", HFILL }},
{ &hf_isakmp_ike_attr_format,
{ "Transform IKE Format", "isakmp.ike.attr.format",
FT_BOOLEAN, 16, TFS(&attribute_format), 0x8000,
"IKE Transform Attribute Format", HFILL }},
{ &hf_isakmp_ike_attr_length,
{ "Length", "isakmp.ike.attr.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
"IKE Tranform Attribute length", HFILL }},
{ &hf_isakmp_ike_attr_value,
{ "Value", "isakmp.ike.attr.value",
FT_BYTES, BASE_NONE, NULL, 0x00,
"IKE Transform Attribute value", HFILL }},
{ &hf_isakmp_ike_attr_encryption_algorithm,
{ "Encryption Algorithm", "isakmp.ike.attr.encryption_algorithm",
FT_UINT16, BASE_DEC, VALS(transform_attr_enc_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_hash_algorithm,
{ "HASH Algorithm", "isakmp.ike.attr.hash_algorithm",
FT_UINT16, BASE_DEC, VALS(transform_attr_hash_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_authentication_method,
{ "Authentication Method", "isakmp.ike.attr.authentication_method",
FT_UINT16, BASE_DEC, VALS(transform_attr_authmeth_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_group_description,
{ "Group Description", "isakmp.ike.attr.group_description",
FT_UINT16, BASE_DEC, VALS(transform_dh_group_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_group_type,
{ "Groupe Type", "isakmp.ike.attr.group_type",
FT_UINT16, BASE_DEC, VALS(transform_attr_grp_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_group_prime,
{ "Groupe Prime", "isakmp.ike.attr.group_prime",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_group_generator_one,
{ "Groupe Generator One", "isakmp.ike.attr.group_generator_one",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_group_generator_two,
{ "Groupe Generator Two", "isakmp.ike.attr.group_generator_two",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_group_curve_a,
{ "Groupe Curve A", "isakmp.ike.attr.group_curve_a",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_group_curve_b,
{ "Groupe Curve B", "isakmp.ike.attr.group_curve_b",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_life_type,
{ "Life Type", "isakmp.ike.attr.life_type",
FT_UINT16, BASE_DEC, VALS(transform_attr_sa_life_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_life_duration_uint32,
{ "Life Duration", "isakmp.ike.attr.life_duration",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_life_duration_uint64,
{ "Life Duration", "isakmp.ike.attr.life_duration",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike_attr_life_duration_bytes,
{ "Life Duration", "isakmp.ike.attr.life_duration",
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
{ "Key Length", "isakmp.ike.attr.group_order",
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
FT_UINT16, BASE_DEC, VALS(transform_dh_group_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_trans_esn,
{ "Transform ID (ESN)", "isakmp.tf.id.esn",
FT_UINT16, BASE_DEC, VALS(transform_ike2_esn_type), 0x00,
NULL, HFILL }},
{ &hf_isakmp_trans_id_v2,
{ "Transform ID", "isakmp.tf.id",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_ike2_attr,
{ "Transform IKE2 Attribute Type", "isakmp.ike2.attr",
FT_NONE, BASE_NONE, NULL, 0x00,
"IKE2 Transform Attribute", HFILL }},
{ &hf_isakmp_ike2_attr_type,
{ "Transform IKE2 Attribute Type", "isakmp.ike2.attr.type",
FT_UINT16, BASE_DEC, VALS(transform_ike2_attr_type), 0x00,
"IKE2 Transform Attribute type", HFILL }},
{ &hf_isakmp_ike2_attr_format,
{ "Transform IKE2 Format", "isakmp.ike2.attr.format",
FT_BOOLEAN, 16, TFS(&attribute_format), 0x8000,
"IKE2 Transform Attribute Format", HFILL }},
{ &hf_isakmp_ike2_attr_length,
{ "Length", "isakmp.ike2.attr.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
"IKE2 Tranform Attribute length", HFILL }},
{ &hf_isakmp_ike2_attr_value,
{ "Value", "isakmp.ike2.attr.value",
FT_BYTES, BASE_NONE, NULL, 0x00,
"IKE2 Transform Attribute value", HFILL }},
{ &hf_isakmp_ike2_attr_key_length,
{ "Key Length", "isakmp.ike2.attr.key_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isakmp_key_exch_dh_group,
{ "DH Group #", "isakmp.key_exchange.dh_group",
FT_UINT16, BASE_DEC, VALS(transform_dh_group_type), 0x00,
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
"ISAKMP (v1) Config Type", HFILL }},
{ &hf_isakmp_cfg_identifier,
{ "Identifier", "isakmp.cfg.identifier",
FT_UINT16, BASE_DEC, NULL, 0x0,
"ISAKMP (v1) Config Identifier", HFILL }},
{ &hf_isakmp_cfg_type_v2,
{ "Type", "isakmp.cfg.type",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(vs_v2_cfgtype), 0x0,
"ISAKMP (v2) Config Type", HFILL }},
{ &hf_isakmp_cfg_attr,
{ "Config Attribute Type", "isakmp.cfg.attr",
FT_NONE, BASE_NONE, NULL, 0x00,
"ISAKMP Config Attribute", HFILL }},
{ &hf_isakmp_cfg_attr_type_v1,
{ "Type", "isakmp.cfg.attr.type",
FT_UINT16, BASE_RANGE_STRING | BASE_DEC, RVALS(vs_v1_cfgattr), 0x00,
"ISAKMP (v1) Config Attribute type", HFILL }},
{ &hf_isakmp_cfg_attr_type_v2,
{ "Type", "isakmp.cfg.attr.type",
FT_UINT16, BASE_RANGE_STRING | BASE_DEC, RVALS(vs_v2_cfgattr), 0x00,
"ISAKMP (v2) Config Attribute type", HFILL }},
{ &hf_isakmp_cfg_attr_format,
{ "Config Attribute Format", "isakmp.cfg.attr.format",
FT_BOOLEAN, 16, TFS(&attribute_format), 0x8000,
"ISAKMP Config Attribute Format", HFILL }},
{ &hf_isakmp_cfg_attr_length,
{ "Length", "isakmp.cfg.attr.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
"ISAKMP Config Attribute length", HFILL }},
{ &hf_isakmp_cfg_attr_value,
{ "Value", "isakmp.cfg.attr.value",
FT_BYTES, BASE_NONE, NULL, 0x00,
"ISAKMP Config Attribute value", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip4_address,
{ "INTERNAL IP4 ADDRESS", "isakmp.cfg.attr.internal_ip4_address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"An IPv4 address on the internal network", HFILL }},
{ &hf_isakmp_cfg_attr_internal_ip4_netmask,
{ "INTERNAL IP4 NETMASK", "isakmp.cfg.attr.internal_ip4_netmask",
FT_IPv4, BASE_NONE, NULL, 0x00,
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
{ &hf_isakmp_cfg_attr_internal_ip6_address,
{ "INTERNAL IP6 ADDRESS", "isakmp.cfg.attr.internal_ip6_address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"An IPv6 address on the internal network", HFILL }},
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
FT_IPv4, BASE_NONE, NULL, 0x00,
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
};
static gint *ett[] = {
&ett_isakmp,
&ett_isakmp_version,
&ett_isakmp_flags,
&ett_isakmp_payload,
&ett_isakmp_fragment,
&ett_isakmp_fragments,
&ett_isakmp_sa,
&ett_isakmp_tf_attr,
&ett_isakmp_tf_ike_attr,
&ett_isakmp_tf_ike2_attr,
&ett_isakmp_id,
&ett_isakmp_cfg_attr,
&ett_isakmp_rohc_attr,
#ifdef HAVE_LIBGCRYPT
&ett_isakmp_decrypted_data,
&ett_isakmp_decrypted_payloads
#endif
};
static ei_register_info ei[] = {
{ &ei_isakmp_enc_iv, { "isakmp.enc.iv.not_enough_data", PI_MALFORMED, PI_WARN, "Not enough data in IKEv2 Encrypted payload", EXPFILL }},
{ &ei_isakmp_ikev2_integrity_checksum, { "isakmp.ikev2.integrity_checksum", PI_CHECKSUM, PI_WARN, "IKEv2 Integrity Checksum Data is incorrect", EXPFILL }},
{ &ei_isakmp_enc_data_length_mult_block_size, { "isakmp.enc_data_length_mult_block_size", PI_MALFORMED, PI_WARN, "Encrypted data length isn't a multiple of block size", EXPFILL }},
{ &ei_isakmp_enc_pad_length_big, { "isakmp.enc.pad_length.big", PI_MALFORMED, PI_WARN, "Pad length is too big", EXPFILL }},
};
expert_module_t* expert_isakmp;
#ifdef HAVE_LIBGCRYPT
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
#endif
proto_isakmp = proto_register_protocol("Internet Security Association and Key Management Protocol",
"ISAKMP", "isakmp");
proto_register_field_array(proto_isakmp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_isakmp = expert_register_protocol(proto_isakmp);
expert_register_field_array(expert_isakmp, ei, array_length(ei));
register_init_routine(&isakmp_init_protocol);
new_register_dissector("isakmp", dissect_isakmp, proto_isakmp);
#ifdef HAVE_LIBGCRYPT
isakmp_module = prefs_register_protocol(proto_isakmp, isakmp_prefs_apply_cb);
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
ikev2_uat_flds);
prefs_register_uat_preference(isakmp_module,
"ikev2_decryption_table",
"IKEv2 Decryption Table",
"Table of IKE_SA security parameters for decryption of IKEv2 packets",
ikev2_uat);
#endif
}
void
proto_reg_handoff_isakmp(void)
{
dissector_handle_t isakmp_handle;
isakmp_handle = find_dissector("isakmp");
eap_handle = find_dissector("eap");
dissector_add_uint("udp.port", UDP_PORT_ISAKMP, isakmp_handle);
dissector_add_uint("tcp.port", TCP_PORT_ISAKMP, isakmp_handle);
}
