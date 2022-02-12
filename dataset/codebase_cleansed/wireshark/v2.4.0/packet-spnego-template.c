static int
dissect_spnego_krb5(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_item *item;
proto_tree *subtree;
int offset = 0;
guint16 token_id;
const char *oid;
tvbuff_t *krb5_tvb;
gint8 ber_class;
gboolean pc, ind = 0;
gint32 tag;
guint32 len;
gssapi_encrypt_info_t* encrypt_info = (gssapi_encrypt_info_t*)data;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
item = proto_tree_add_item(tree, hf_spnego_krb5, tvb, offset, -1, ENC_NA);
subtree = proto_item_add_subtree(item, ett_spnego_krb5);
get_ber_identifier(tvb, offset, &ber_class, &pc, &tag);
if (ber_class == BER_CLASS_APP && pc) {
offset = dissect_ber_identifier(pinfo, subtree, tvb, offset, &ber_class, &pc, &tag);
offset = dissect_ber_length(pinfo, subtree, tvb, offset, &len, &ind);
switch (tag) {
case 0:
offset=dissect_ber_object_identifier_str(FALSE, &asn1_ctx, subtree, tvb, offset, hf_spnego_krb5_oid, &oid);
token_id = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(subtree, hf_spnego_krb5_tok_id, tvb, offset, 2, token_id);
offset += 2;
break;
case 14:
case 15:
dissect_kerberos_main(tvb, pinfo, subtree, FALSE, NULL);
return tvb_captured_length(tvb);
default:
proto_tree_add_expert_format(subtree, pinfo, &ei_spnego_unknown_header, tvb, offset, 0,
"Unknown header (class=%d, pc=%d, tag=%d)", ber_class, pc, tag);
goto done;
}
} else {
token_id = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(subtree, hf_spnego_krb5_tok_id, tvb, offset, 2, token_id);
offset += 2;
}
switch (token_id) {
case KRB_TOKEN_AP_REQ:
case KRB_TOKEN_AP_REP:
case KRB_TOKEN_AP_ERR:
krb5_tvb = tvb_new_subset_remaining(tvb, offset);
offset = dissect_kerberos_main(krb5_tvb, pinfo, subtree, FALSE, NULL);
break;
case KRB_TOKEN_GETMIC:
offset = dissect_spnego_krb5_getmic_base(tvb, offset, pinfo, subtree);
break;
case KRB_TOKEN_WRAP:
offset = dissect_spnego_krb5_wrap_base(tvb, offset, pinfo, subtree, token_id, encrypt_info);
break;
case KRB_TOKEN_DELETE_SEC_CONTEXT:
break;
case KRB_TOKEN_CFX_GETMIC:
offset = dissect_spnego_krb5_cfx_getmic_base(tvb, offset, pinfo, subtree);
break;
case KRB_TOKEN_CFX_WRAP:
offset = dissect_spnego_krb5_cfx_wrap_base(tvb, offset, pinfo, subtree, token_id, encrypt_info);
break;
default:
break;
}
done:
proto_item_set_len(item, offset);
return tvb_captured_length(tvb);
}
static int
arcfour_mic_key(const guint8 *key_data, size_t key_size, int key_type,
const guint8 *cksum_data, size_t cksum_size,
guint8 *key6_data)
{
guint8 k5_data[HASH_MD5_LENGTH];
guint8 T[4] = { 0 };
if (key_type == KEYTYPE_ARCFOUR_56) {
guint8 L40[14] = "fortybits";
memcpy(L40 + 10, T, sizeof(T));
if (ws_hmac_buffer(GCRY_MD_MD5, k5_data, L40, 14, key_data, key_size)) {
return 0;
}
memset(&k5_data[7], 0xAB, 9);
} else {
if (ws_hmac_buffer(GCRY_MD_MD5, k5_data, T, 4, key_data, key_size)) {
return 0;
}
}
if (ws_hmac_buffer(GCRY_MD_MD5, key6_data, cksum_data, cksum_size, k5_data, HASH_MD5_LENGTH)) {
return 0;
}
return 0;
}
static int
usage2arcfour(int usage)
{
switch (usage) {
case 3:
case 9:
return 8;
case 22:
return 13;
case 23:
return 15;
case 24:
return 0;
default :
return 0;
}
}
static int
arcfour_mic_cksum(guint8 *key_data, int key_length,
unsigned int usage,
guint8 sgn_cksum[8],
const guint8 *v1, size_t l1,
const guint8 *v2, size_t l2,
const guint8 *v3, size_t l3)
{
static const guint8 signature[] = "signaturekey";
guint8 ksign_c[HASH_MD5_LENGTH];
guint8 t[4];
guint8 digest[HASH_MD5_LENGTH];
int rc4_usage;
guint8 cksum[HASH_MD5_LENGTH];
gcry_md_hd_t md5_handle;
rc4_usage=usage2arcfour(usage);
if (ws_hmac_buffer(GCRY_MD_MD5, ksign_c, signature, sizeof(signature), key_data, key_length)) {
return 0;
}
if (gcry_md_open(&md5_handle, GCRY_MD_MD5, 0)) {
return 0;
}
t[0] = (rc4_usage >> 0) & 0xFF;
t[1] = (rc4_usage >> 8) & 0xFF;
t[2] = (rc4_usage >> 16) & 0xFF;
t[3] = (rc4_usage >> 24) & 0xFF;
gcry_md_write(md5_handle, t, 4);
gcry_md_write(md5_handle, v1, l1);
gcry_md_write(md5_handle, v2, l2);
gcry_md_write(md5_handle, v3, l3);
memcpy(digest, gcry_md_read(md5_handle, 0), HASH_MD5_LENGTH);
gcry_md_close(md5_handle);
if (ws_hmac_buffer(GCRY_MD_MD5, cksum, digest, HASH_MD5_LENGTH, ksign_c, HASH_MD5_LENGTH)) {
return 0;
}
memcpy(sgn_cksum, cksum, 8);
return 0;
}
static int
gssapi_verify_pad(guint8 *wrapped_data, int wrapped_length,
int datalen,
int *padlen)
{
guint8 *pad;
int padlength;
int i;
pad = wrapped_data + wrapped_length - 1;
padlength = *pad;
if (padlength > datalen)
return 1;
for (i = padlength; i > 0 && *pad == padlength; i--, pad--);
if (i != 0)
return 2;
*padlen = padlength;
return 0;
}
static int
decrypt_arcfour(gssapi_encrypt_info_t* gssapi_encrypt, guint8 *input_message_buffer, guint8 *output_message_buffer,
guint8 *key_value, int key_size, int key_type)
{
guint8 Klocaldata[16];
int ret;
int datalen;
guint8 k6_data[16];
guint32 SND_SEQ[2];
guint8 Confounder[8];
guint8 cksum_data[8];
int cmp;
int conf_flag;
int padlen = 0;
gcry_cipher_hd_t rc4_handle;
int i;
datalen = tvb_captured_length(gssapi_encrypt->gssapi_encrypted_tvb);
if(tvb_get_ntohs(gssapi_encrypt->gssapi_wrap_tvb, 4)==0x1000){
conf_flag=1;
} else if (tvb_get_ntohs(gssapi_encrypt->gssapi_wrap_tvb, 4)==0xffff){
conf_flag=0;
} else {
return -3;
}
if(tvb_get_ntohs(gssapi_encrypt->gssapi_wrap_tvb, 6)!=0xffff){
return -4;
}
ret = arcfour_mic_key(key_value, key_size, key_type,
tvb_get_ptr(gssapi_encrypt->gssapi_wrap_tvb, 16, 8),
8,
k6_data);
if (ret) {
return -5;
}
tvb_memcpy(gssapi_encrypt->gssapi_wrap_tvb, SND_SEQ, 8, 8);
if (gcry_cipher_open (&rc4_handle, GCRY_CIPHER_ARCFOUR, GCRY_CIPHER_MODE_STREAM, 0)) {
return -12;
}
if (gcry_cipher_setkey(rc4_handle, k6_data, sizeof(k6_data))) {
gcry_cipher_close(rc4_handle);
return -13;
}
gcry_cipher_decrypt(rc4_handle, (guint8 *)SND_SEQ, 8, NULL, 0);
gcry_cipher_close(rc4_handle);
memset(k6_data, 0, sizeof(k6_data));
if (SND_SEQ[1] != 0xFFFFFFFF && SND_SEQ[1] != 0x00000000) {
return -6;
}
for (i = 0; i < 16; i++)
Klocaldata[i] = ((guint8 *)key_value)[i] ^ 0xF0;
ret = arcfour_mic_key(Klocaldata,sizeof(Klocaldata),key_type,
(const guint8 *)SND_SEQ, 4,
k6_data);
memset(Klocaldata, 0, sizeof(Klocaldata));
if (ret) {
return -7;
}
if(conf_flag) {
tvb_memcpy(gssapi_encrypt->gssapi_wrap_tvb, Confounder, 24, 8);
if (gcry_cipher_open (&rc4_handle, GCRY_CIPHER_ARCFOUR, GCRY_CIPHER_MODE_STREAM, 0)) {
return -14;
}
if (gcry_cipher_setkey(rc4_handle, k6_data, sizeof(k6_data))) {
gcry_cipher_close(rc4_handle);
return -15;
}
gcry_cipher_decrypt(rc4_handle, Confounder, 8, NULL, 0);
gcry_cipher_decrypt(rc4_handle, output_message_buffer, datalen, input_message_buffer, datalen);
gcry_cipher_close(rc4_handle);
} else {
tvb_memcpy(gssapi_encrypt->gssapi_wrap_tvb, Confounder, 24, 8);
memcpy(output_message_buffer, input_message_buffer, datalen);
}
memset(k6_data, 0, sizeof(k6_data));
if(gssapi_encrypt->decrypt_gssapi_tvb==DECRYPT_GSSAPI_NORMAL){
ret = gssapi_verify_pad(output_message_buffer,datalen,datalen, &padlen);
if (ret) {
return -9;
}
datalen -= padlen;
}
if(gssapi_encrypt->decrypt_gssapi_tvb==DECRYPT_GSSAPI_NORMAL){
ret = arcfour_mic_cksum(key_value, key_size, KRB5_KU_USAGE_SEAL,
cksum_data,
tvb_get_ptr(gssapi_encrypt->gssapi_wrap_tvb, 0, 8), 8,
Confounder, sizeof(Confounder), output_message_buffer,
datalen + padlen);
if (ret) {
return -10;
}
cmp = tvb_memeql(gssapi_encrypt->gssapi_wrap_tvb, 16, cksum_data, 8);
if (cmp) {
return -11;
}
}
return datalen;
}
static void
decrypt_gssapi_krb_arcfour_wrap(proto_tree *tree _U_, packet_info *pinfo, tvbuff_t *tvb, int keytype, gssapi_encrypt_info_t* gssapi_encrypt)
{
int ret;
enc_key_t *ek;
int length;
const guint8 *original_data;
guint8 *cryptocopy=NULL;
guint8 *output_message_buffer;
length=tvb_captured_length(gssapi_encrypt->gssapi_encrypted_tvb);
original_data=tvb_get_ptr(gssapi_encrypt->gssapi_encrypted_tvb, 0, length);
cryptocopy=(guint8 *)wmem_alloc(wmem_packet_scope(), length);
output_message_buffer=(guint8 *)wmem_alloc(pinfo->pool, length);
for(ek=enc_key_list;ek;ek=ek->next){
if(ek->keytype!=keytype){
continue;
}
memcpy(cryptocopy, original_data, length);
ret=decrypt_arcfour(gssapi_encrypt,
cryptocopy,
output_message_buffer,
ek->keyvalue,
ek->keylength,
ek->keytype);
if (ret >= 0) {
expert_add_info_format(pinfo, NULL, &ei_spnego_decrypted_keytype,
"Decrypted keytype %d in frame %u using %s",
ek->keytype, pinfo->num, ek->key_origin);
gssapi_encrypt->gssapi_decrypted_tvb=tvb_new_child_real_data(tvb, output_message_buffer, ret, ret);
add_new_data_source(pinfo, gssapi_encrypt->gssapi_decrypted_tvb, "Decrypted GSS-Krb5");
return;
}
}
}
static int
rrc_rotate(guint8 *data, int len, guint16 rrc, int unrotate)
{
guint8 *tmp, buf[256];
size_t left;
if (len == 0)
return 0;
rrc %= len;
if (rrc == 0)
return 0;
left = len - rrc;
if (rrc <= sizeof(buf)) {
tmp = buf;
} else {
tmp = (guint8 *)g_malloc(rrc);
if (tmp == NULL)
return -1;
}
if (unrotate) {
memcpy(tmp, data, rrc);
memmove(data, data + rrc, left);
memcpy(data + left, tmp, rrc);
} else {
memcpy(tmp, data + left, rrc);
memmove(data + rrc, data, left);
memcpy(data, tmp, rrc);
}
if (rrc > sizeof(buf))
g_free(tmp);
return 0;
}
static void
decrypt_gssapi_krb_cfx_wrap(proto_tree *tree,
packet_info *pinfo,
tvbuff_t *checksum_tvb,
gssapi_encrypt_info_t* gssapi_encrypt,
guint16 ec,
guint16 rrc,
int keytype,
unsigned int usage)
{
guint8 *rotated;
guint8 *output;
int datalen;
tvbuff_t *next_tvb;
if(!krb_decrypt){
return;
}
datalen = tvb_captured_length(checksum_tvb) + tvb_captured_length(gssapi_encrypt->gssapi_encrypted_tvb);
rotated = (guint8 *)wmem_alloc(pinfo->pool, datalen);
tvb_memcpy(checksum_tvb, rotated, 0, tvb_captured_length(checksum_tvb));
tvb_memcpy(gssapi_encrypt->gssapi_encrypted_tvb, rotated + tvb_captured_length(checksum_tvb),
0, tvb_captured_length(gssapi_encrypt->gssapi_encrypted_tvb));
if (gssapi_encrypt->decrypt_gssapi_tvb==DECRYPT_GSSAPI_DCE) {
rrc += ec;
}
rrc_rotate(rotated, datalen, rrc, TRUE);
next_tvb=tvb_new_child_real_data(gssapi_encrypt->gssapi_encrypted_tvb, rotated,
datalen, datalen);
add_new_data_source(pinfo, next_tvb, "GSSAPI CFX");
output = decrypt_krb5_data(tree, pinfo, usage, next_tvb, keytype, &datalen);
if (output) {
guint8 *outdata;
outdata = (guint8 *)wmem_memdup(pinfo->pool, output, tvb_captured_length(gssapi_encrypt->gssapi_encrypted_tvb));
gssapi_encrypt->gssapi_decrypted_tvb=tvb_new_child_real_data(gssapi_encrypt->gssapi_encrypted_tvb,
outdata,
tvb_captured_length(gssapi_encrypt->gssapi_encrypted_tvb),
tvb_captured_length(gssapi_encrypt->gssapi_encrypted_tvb));
add_new_data_source(pinfo, gssapi_encrypt->gssapi_decrypted_tvb, "Decrypted GSS-Krb5");
}
}
static int
dissect_spnego_krb5_wrap_base(tvbuff_t *tvb, int offset, packet_info *pinfo
#ifndef HAVE_KERBEROS
_U_
#endif
, proto_tree *tree, guint16 token_id
#ifndef HAVE_KERBEROS
_U_
#endif
, gssapi_encrypt_info_t* gssapi_encrypt
)
{
guint16 sgn_alg, seal_alg;
#ifdef HAVE_KERBEROS
int start_offset=offset;
#endif
sgn_alg = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_spnego_krb5_sgn_alg, tvb, offset, 2, sgn_alg);
offset += 2;
seal_alg = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_spnego_krb5_seal_alg, tvb, offset, 2, seal_alg);
offset += 2;
offset += 2;
proto_tree_add_item(tree, hf_spnego_krb5_snd_seq, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(tree, hf_spnego_krb5_sgn_cksum, tvb, offset, 8, ENC_NA);
offset += 8;
if ((sgn_alg == KRB_SGN_ALG_HMAC) ||
(sgn_alg == KRB_SGN_ALG_DES_MAC_MD5)) {
proto_tree_add_item(tree, hf_spnego_krb5_confounder, tvb, offset, 8, ENC_NA);
offset += 8;
}
if (gssapi_encrypt != NULL)
gssapi_encrypt->gssapi_data_encrypted=(seal_alg!=KRB_SEAL_ALG_NONE);
#ifdef HAVE_KERBEROS
#define GSS_ARCFOUR_WRAP_TOKEN_SIZE 32
if(gssapi_encrypt && gssapi_encrypt->decrypt_gssapi_tvb){
if(!gssapi_encrypt->gssapi_encrypted_tvb){
int len;
len=tvb_reported_length_remaining(tvb,offset);
if(len>tvb_captured_length_remaining(tvb, offset)){
return offset;
}
gssapi_encrypt->gssapi_encrypted_tvb = tvb_new_subset_length(
tvb, offset, len);
}
if((token_id==KRB_TOKEN_WRAP)
&&(sgn_alg==KRB_SGN_ALG_HMAC)
&&(seal_alg==KRB_SEAL_ALG_RC4)){
if(!gssapi_encrypt->gssapi_wrap_tvb){
gssapi_encrypt->gssapi_wrap_tvb = tvb_new_subset_length(
tvb, start_offset-2,
GSS_ARCFOUR_WRAP_TOKEN_SIZE);
}
#if defined(HAVE_HEIMDAL_KERBEROS) || defined(HAVE_MIT_KERBEROS)
decrypt_gssapi_krb_arcfour_wrap(tree,
pinfo,
tvb,
KEYTYPE_ARCFOUR_HMAC,
gssapi_encrypt);
#endif
}
}
#endif
return offset;
}
static int
dissect_spnego_krb5_getmic_base(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint16 sgn_alg;
sgn_alg = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_spnego_krb5_sgn_alg, tvb, offset, 2, sgn_alg);
offset += 2;
offset += 4;
proto_tree_add_item(tree, hf_spnego_krb5_snd_seq, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(tree, hf_spnego_krb5_sgn_cksum, tvb, offset, 8, ENC_NA);
offset += 8;
if (tvb_reported_length_remaining(tvb, offset)) {
if (sgn_alg == KRB_SGN_ALG_HMAC) {
proto_tree_add_item(tree, hf_spnego_krb5_confounder, tvb, offset, 8, ENC_NA);
offset += 8;
}
}
return offset;
}
static int
dissect_spnego_krb5_cfx_flags(tvbuff_t *tvb, int offset,
proto_tree *spnego_krb5_tree,
guint8 cfx_flags _U_)
{
static const int * flags[] = {
&hf_spnego_krb5_cfx_flags_04,
&hf_spnego_krb5_cfx_flags_02,
&hf_spnego_krb5_cfx_flags_01,
NULL
};
proto_tree_add_bitmask(spnego_krb5_tree, tvb, offset, hf_spnego_krb5_cfx_flags, ett_spnego_krb5_cfx_flags, flags, ENC_NA);
return (offset + 1);
}
static int
dissect_spnego_krb5_cfx_wrap_base(tvbuff_t *tvb, int offset, packet_info *pinfo
#ifndef HAVE_KERBEROS
_U_
#endif
, proto_tree *tree, guint16 token_id _U_
, gssapi_encrypt_info_t* gssapi_encrypt
)
{
guint8 flags;
guint16 ec;
#if defined(HAVE_HEIMDAL_KERBEROS) || defined(HAVE_MIT_KERBEROS)
guint16 rrc;
#endif
int checksum_size;
int start_offset=offset;
flags = tvb_get_guint8(tvb, offset);
offset = dissect_spnego_krb5_cfx_flags(tvb, offset, tree, flags);
if (gssapi_encrypt != NULL)
gssapi_encrypt->gssapi_data_encrypted=(flags & 2);
proto_tree_add_item(tree, hf_spnego_krb5_filler, tvb, offset, 1, ENC_NA);
offset += 1;
ec = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_spnego_krb5_cfx_ec, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
#if defined(HAVE_HEIMDAL_KERBEROS) || defined(HAVE_MIT_KERBEROS)
rrc = tvb_get_ntohs(tvb, offset);
#endif
proto_tree_add_item(tree, hf_spnego_krb5_cfx_rrc, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_spnego_krb5_cfx_seq, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
if (gssapi_encrypt == NULL)
return offset;
if (gssapi_encrypt->gssapi_data_encrypted) {
checksum_size = 44 + ec;
proto_tree_add_item(tree, hf_spnego_krb5_sgn_cksum, tvb, offset, checksum_size, ENC_NA);
offset += checksum_size;
} else {
int returned_offset;
int inner_token_len = 0;
checksum_size = ec;
inner_token_len = tvb_reported_length_remaining(tvb, offset);
if (inner_token_len > ec) {
inner_token_len -= ec;
}
#if defined(HAVE_HEIMDAL_KERBEROS) || defined(HAVE_MIT_KERBEROS)
if (rrc == ec) {
proto_tree_add_item(tree, hf_spnego_krb5_sgn_cksum, tvb, offset, checksum_size, ENC_NA);
offset += checksum_size;
}
#endif
returned_offset = offset;
gssapi_encrypt->gssapi_wrap_tvb = tvb_new_subset_length(tvb, offset,
inner_token_len);
offset += inner_token_len;
#if defined(HAVE_HEIMDAL_KERBEROS) || defined(HAVE_MIT_KERBEROS)
if (rrc == 0)
#endif
{
proto_tree_add_item(tree, hf_spnego_krb5_sgn_cksum, tvb, offset, checksum_size, ENC_NA);
}
return returned_offset;
}
if(gssapi_encrypt->decrypt_gssapi_tvb){
if(!gssapi_encrypt->gssapi_encrypted_tvb){
int len;
len=tvb_reported_length_remaining(tvb,offset);
if(len>tvb_captured_length_remaining(tvb, offset)){
return offset;
}
gssapi_encrypt->gssapi_encrypted_tvb = tvb_new_subset_length_caplen(
tvb, offset, len, len);
}
if (gssapi_encrypt->gssapi_data_encrypted) {
if(!gssapi_encrypt->gssapi_wrap_tvb){
gssapi_encrypt->gssapi_wrap_tvb = tvb_new_subset_length(
tvb, start_offset-2,
offset - (start_offset-2));
}
}
}
#if defined(HAVE_HEIMDAL_KERBEROS) || defined(HAVE_MIT_KERBEROS)
{
tvbuff_t *checksum_tvb = tvb_new_subset_length(tvb, 16, checksum_size);
if (gssapi_encrypt->gssapi_data_encrypted) {
if(gssapi_encrypt->gssapi_encrypted_tvb){
decrypt_gssapi_krb_cfx_wrap(tree,
pinfo,
checksum_tvb,
gssapi_encrypt,
ec,
rrc,
-1,
(flags & 0x0001)?
KRB5_KU_USAGE_ACCEPTOR_SEAL:
KRB5_KU_USAGE_INITIATOR_SEAL);
}
}
}
#endif
return offset;
}
static int
dissect_spnego_krb5_cfx_getmic_base(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 flags;
int checksum_size;
flags = tvb_get_guint8(tvb, offset);
offset = dissect_spnego_krb5_cfx_flags(tvb, offset, tree, flags);
proto_tree_add_item(tree, hf_spnego_krb5_filler, tvb, offset, 5, ENC_NA);
offset += 5;
proto_tree_add_item(tree, hf_spnego_krb5_cfx_seq, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
checksum_size = tvb_captured_length_remaining(tvb, offset);
proto_tree_add_item(tree, hf_spnego_krb5_sgn_cksum, tvb, offset, checksum_size, ENC_NA);
offset += checksum_size;
return offset;
}
static int
dissect_spnego_krb5_wrap(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data)
{
proto_item *item;
proto_tree *subtree;
int offset = 0;
guint16 token_id;
gssapi_encrypt_info_t* encrypt_info = (gssapi_encrypt_info_t*)data;
item = proto_tree_add_item(tree, hf_spnego_krb5, tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(item, ett_spnego_krb5);
token_id = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(subtree, hf_spnego_krb5_tok_id, tvb, offset, 2, token_id);
offset += 2;
switch (token_id) {
case KRB_TOKEN_GETMIC:
offset = dissect_spnego_krb5_getmic_base(tvb, offset, pinfo, subtree);
break;
case KRB_TOKEN_WRAP:
offset = dissect_spnego_krb5_wrap_base(tvb, offset, pinfo, subtree, token_id, encrypt_info);
break;
case KRB_TOKEN_CFX_GETMIC:
offset = dissect_spnego_krb5_cfx_getmic_base(tvb, offset, pinfo, subtree);
break;
case KRB_TOKEN_CFX_WRAP:
offset = dissect_spnego_krb5_cfx_wrap_base(tvb, offset, pinfo, subtree, token_id, encrypt_info);
break;
default:
break;
}
proto_item_set_len(item, offset);
return offset;
}
static int
dissect_spnego_wrap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *item;
proto_tree *subtree;
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
MechType_oid = NULL;
item = proto_tree_add_item(tree, proto_spnego, tvb, offset, -1, ENC_NA);
subtree = proto_item_add_subtree(item, ett_spnego);
offset = dissect_spnego_InitialContextToken(FALSE, tvb, offset, &asn1_ctx , subtree, -1);
return offset;
}
static int
dissect_spnego(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_item *item;
proto_tree *subtree;
int offset = 0;
conversation_t *conversation;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
next_level_value = (gssapi_oid_value *)p_get_proto_data(wmem_file_scope(), pinfo, proto_spnego, 0);
if (!next_level_value && !pinfo->fd->flags.visited) {
conversation = find_conversation(pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (conversation) {
next_level_value = (gssapi_oid_value *)conversation_get_proto_data(conversation, proto_spnego);
if (next_level_value)
p_add_proto_data(wmem_file_scope(), pinfo, proto_spnego, 0, next_level_value);
}
}
item = proto_tree_add_item(parent_tree, proto_spnego, tvb, offset, -1, ENC_NA);
subtree = proto_item_add_subtree(item, ett_spnego);
dissect_spnego_NegotiationToken(FALSE, tvb, offset, &asn1_ctx, subtree, -1);
return tvb_captured_length(tvb);
}
void proto_register_spnego(void) {
static hf_register_info hf[] = {
{ &hf_spnego_wraptoken,
{ "wrapToken", "spnego.wraptoken",
FT_NONE, BASE_NONE, NULL, 0x0, "SPNEGO wrapToken",
HFILL}},
{ &hf_spnego_krb5,
{ "krb5_blob", "spnego.krb5.blob", FT_BYTES,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_spnego_krb5_oid,
{ "KRB5 OID", "spnego.krb5_oid", FT_STRING,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_spnego_krb5_tok_id,
{ "krb5_tok_id", "spnego.krb5.tok_id", FT_UINT16, BASE_HEX,
VALS(spnego_krb5_tok_id_vals), 0, "KRB5 Token Id", HFILL}},
{ &hf_spnego_krb5_sgn_alg,
{ "krb5_sgn_alg", "spnego.krb5.sgn_alg", FT_UINT16, BASE_HEX,
VALS(spnego_krb5_sgn_alg_vals), 0, "KRB5 Signing Algorithm", HFILL}},
{ &hf_spnego_krb5_seal_alg,
{ "krb5_seal_alg", "spnego.krb5.seal_alg", FT_UINT16, BASE_HEX,
VALS(spnego_krb5_seal_alg_vals), 0, "KRB5 Sealing Algorithm", HFILL}},
{ &hf_spnego_krb5_snd_seq,
{ "krb5_snd_seq", "spnego.krb5.snd_seq", FT_BYTES, BASE_NONE,
NULL, 0, "KRB5 Encrypted Sequence Number", HFILL}},
{ &hf_spnego_krb5_sgn_cksum,
{ "krb5_sgn_cksum", "spnego.krb5.sgn_cksum", FT_BYTES, BASE_NONE,
NULL, 0, "KRB5 Data Checksum", HFILL}},
{ &hf_spnego_krb5_confounder,
{ "krb5_confounder", "spnego.krb5.confounder", FT_BYTES, BASE_NONE,
NULL, 0, "KRB5 Confounder", HFILL}},
{ &hf_spnego_krb5_filler,
{ "krb5_filler", "spnego.krb5.filler", FT_BYTES, BASE_NONE,
NULL, 0, "KRB5 Filler", HFILL}},
{ &hf_spnego_krb5_cfx_flags,
{ "krb5_cfx_flags", "spnego.krb5.cfx_flags", FT_UINT8, BASE_HEX,
NULL, 0, "KRB5 CFX Flags", HFILL}},
{ &hf_spnego_krb5_cfx_flags_01,
{ "SendByAcceptor", "spnego.krb5.send_by_acceptor", FT_BOOLEAN, 8,
TFS (&tfs_set_notset), 0x01, NULL, HFILL}},
{ &hf_spnego_krb5_cfx_flags_02,
{ "Sealed", "spnego.krb5.sealed", FT_BOOLEAN, 8,
TFS (&tfs_set_notset), 0x02, NULL, HFILL}},
{ &hf_spnego_krb5_cfx_flags_04,
{ "AcceptorSubkey", "spnego.krb5.acceptor_subkey", FT_BOOLEAN, 8,
TFS (&tfs_set_notset), 0x04, NULL, HFILL}},
{ &hf_spnego_krb5_cfx_ec,
{ "krb5_cfx_ec", "spnego.krb5.cfx_ec", FT_UINT16, BASE_DEC,
NULL, 0, "KRB5 CFX Extra Count", HFILL}},
{ &hf_spnego_krb5_cfx_rrc,
{ "krb5_cfx_rrc", "spnego.krb5.cfx_rrc", FT_UINT16, BASE_DEC,
NULL, 0, "KRB5 CFX Right Rotation Count", HFILL}},
{ &hf_spnego_krb5_cfx_seq,
{ "krb5_cfx_seq", "spnego.krb5.cfx_seq", FT_UINT64, BASE_DEC,
NULL, 0, "KRB5 Sequence Number", HFILL}},
#include "packet-spnego-hfarr.c"
};
static gint *ett[] = {
&ett_spnego,
&ett_spnego_wraptoken,
&ett_spnego_krb5,
&ett_spnego_krb5_cfx_flags,
#include "packet-spnego-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_spnego_decrypted_keytype, { "spnego.decrypted_keytype", PI_SECURITY, PI_CHAT, "Decryted keytype", EXPFILL }},
{ &ei_spnego_unknown_header, { "spnego.unknown_header", PI_PROTOCOL, PI_WARN, "Unknown header", EXPFILL }},
};
expert_module_t* expert_spnego;
proto_spnego = proto_register_protocol(PNAME, PSNAME, PFNAME);
spnego_handle = register_dissector("spnego", dissect_spnego, proto_spnego);
proto_spnego_krb5 = proto_register_protocol("SPNEGO-KRB5", "SPNEGO-KRB5", "spnego-krb5");
spnego_krb5_handle = register_dissector("spnego-krb5", dissect_spnego_krb5, proto_spnego_krb5);
spnego_krb5_wrap_handle = register_dissector("spnego-krb5-wrap", dissect_spnego_krb5_wrap, proto_spnego_krb5);
proto_register_field_array(proto_spnego, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_spnego = expert_register_protocol(proto_spnego);
expert_register_field_array(expert_spnego, ei, array_length(ei));
}
void proto_reg_handoff_spnego(void) {
dissector_handle_t spnego_wrap_handle;
spnego_wrap_handle = create_dissector_handle(dissect_spnego_wrap, proto_spnego);
gssapi_init_oid("1.3.6.1.5.5.2", proto_spnego, ett_spnego,
spnego_handle, spnego_wrap_handle,
"SPNEGO - Simple Protected Negotiation");
gssapi_init_oid("1.2.840.48018.1.2.2", proto_spnego_krb5, ett_spnego_krb5,
spnego_krb5_handle, spnego_krb5_wrap_handle,
"MS KRB5 - Microsoft Kerberos 5");
gssapi_init_oid("1.2.840.113554.1.2.2", proto_spnego_krb5, ett_spnego_krb5,
spnego_krb5_handle, spnego_krb5_wrap_handle,
"KRB5 - Kerberos 5");
gssapi_init_oid("1.2.840.113554.1.2.2.3", proto_spnego_krb5, ett_spnego_krb5,
spnego_krb5_handle, spnego_krb5_wrap_handle,
"KRB5 - Kerberos 5 - User to User");
}
