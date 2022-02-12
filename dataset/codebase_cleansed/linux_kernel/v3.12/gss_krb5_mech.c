static const char * enctype2str(__u32 enctype)
{
if (enctype < MAX_ENCTYPES && enctypes[enctype].ke_dispname)
return enctypes[enctype].ke_dispname;
return "unknown";
}
static
int keyblock_init(struct krb5_keyblock *kb, char *alg_name, int alg_mode)
{
kb->kb_tfm = crypto_alloc_blkcipher(alg_name, alg_mode, 0);
if (IS_ERR(kb->kb_tfm)) {
CERROR("failed to alloc tfm: %s, mode %d\n",
alg_name, alg_mode);
return -1;
}
if (crypto_blkcipher_setkey(kb->kb_tfm, kb->kb_key.data, kb->kb_key.len)) {
CERROR("failed to set %s key, len %d\n",
alg_name, kb->kb_key.len);
return -1;
}
return 0;
}
static
int krb5_init_keys(struct krb5_ctx *kctx)
{
struct krb5_enctype *ke;
if (kctx->kc_enctype >= MAX_ENCTYPES ||
enctypes[kctx->kc_enctype].ke_hash_size == 0) {
CERROR("unsupported enctype %x\n", kctx->kc_enctype);
return -1;
}
ke = &enctypes[kctx->kc_enctype];
if (kctx->kc_enctype != ENCTYPE_ARCFOUR_HMAC &&
keyblock_init(&kctx->kc_keye, ke->ke_enc_name, ke->ke_enc_mode))
return -1;
if (ke->ke_hash_hmac == 0 &&
keyblock_init(&kctx->kc_keyi, ke->ke_enc_name, ke->ke_enc_mode))
return -1;
if (ke->ke_hash_hmac == 0 &&
keyblock_init(&kctx->kc_keyc, ke->ke_enc_name, ke->ke_enc_mode))
return -1;
return 0;
}
static
void keyblock_free(struct krb5_keyblock *kb)
{
rawobj_free(&kb->kb_key);
if (kb->kb_tfm)
crypto_free_blkcipher(kb->kb_tfm);
}
static
int keyblock_dup(struct krb5_keyblock *new, struct krb5_keyblock *kb)
{
return rawobj_dup(&new->kb_key, &kb->kb_key);
}
static
int get_bytes(char **ptr, const char *end, void *res, int len)
{
char *p, *q;
p = *ptr;
q = p + len;
if (q > end || q < p)
return -1;
memcpy(res, p, len);
*ptr = q;
return 0;
}
static
int get_rawobj(char **ptr, const char *end, rawobj_t *res)
{
char *p, *q;
__u32 len;
p = *ptr;
if (get_bytes(&p, end, &len, sizeof(len)))
return -1;
q = p + len;
if (q > end || q < p)
return -1;
OBD_ALLOC_LARGE(res->data, len);
if (!res->data)
return -1;
res->len = len;
memcpy(res->data, p, len);
*ptr = q;
return 0;
}
static
int get_keyblock(char **ptr, const char *end,
struct krb5_keyblock *kb, __u32 keysize)
{
char *buf;
OBD_ALLOC_LARGE(buf, keysize);
if (buf == NULL)
return -1;
if (get_bytes(ptr, end, buf, keysize)) {
OBD_FREE_LARGE(buf, keysize);
return -1;
}
kb->kb_key.len = keysize;
kb->kb_key.data = buf;
return 0;
}
static
void delete_context_kerberos(struct krb5_ctx *kctx)
{
rawobj_free(&kctx->kc_mech_used);
keyblock_free(&kctx->kc_keye);
keyblock_free(&kctx->kc_keyi);
keyblock_free(&kctx->kc_keyc);
}
static
__u32 import_context_rfc1964(struct krb5_ctx *kctx, char *p, char *end)
{
unsigned int tmp_uint, keysize;
if (get_bytes(&p, end, &tmp_uint, sizeof(tmp_uint)))
goto out_err;
kctx->kc_seed_init = (tmp_uint != 0);
if (get_bytes(&p, end, kctx->kc_seed, sizeof(kctx->kc_seed)))
goto out_err;
if (get_bytes(&p, end, &tmp_uint, sizeof(tmp_uint)) ||
get_bytes(&p, end, &tmp_uint, sizeof(tmp_uint)))
goto out_err;
if (get_bytes(&p, end, &kctx->kc_endtime, sizeof(kctx->kc_endtime)))
goto out_err;
if (get_bytes(&p, end, &tmp_uint, sizeof(tmp_uint)))
goto out_err;
kctx->kc_seq_send = tmp_uint;
if (get_rawobj(&p, end, &kctx->kc_mech_used))
goto out_err;
if (get_bytes(&p, end, &kctx->kc_enctype, sizeof(kctx->kc_enctype)))
goto out_err;
if (get_bytes(&p, end, &keysize, sizeof(keysize)))
goto out_err;
if (get_keyblock(&p, end, &kctx->kc_keye, keysize))
goto out_err;
if (get_bytes(&p, end, &tmp_uint, sizeof(tmp_uint)) ||
tmp_uint != kctx->kc_enctype)
goto out_err;
if (get_bytes(&p, end, &tmp_uint, sizeof(tmp_uint)) ||
tmp_uint != keysize)
goto out_err;
if (get_keyblock(&p, end, &kctx->kc_keyc, keysize))
goto out_err;
if (keyblock_dup(&kctx->kc_keyi, &kctx->kc_keyc))
goto out_err;
if (p != end)
goto out_err;
CDEBUG(D_SEC, "successfully imported rfc1964 context\n");
return 0;
out_err:
return GSS_S_FAILURE;
}
static
__u32 import_context_rfc4121(struct krb5_ctx *kctx, char *p, char *end)
{
unsigned int tmp_uint, keysize;
if (get_bytes(&p, end, &kctx->kc_endtime, sizeof(kctx->kc_endtime)))
goto out_err;
if (get_bytes(&p, end, &tmp_uint, sizeof(tmp_uint)))
goto out_err;
if (tmp_uint & KRB5_CTX_FLAG_INITIATOR)
kctx->kc_initiate = 1;
if (tmp_uint & KRB5_CTX_FLAG_CFX)
kctx->kc_cfx = 1;
if (tmp_uint & KRB5_CTX_FLAG_ACCEPTOR_SUBKEY)
kctx->kc_have_acceptor_subkey = 1;
if (get_bytes(&p, end, &kctx->kc_seq_send, sizeof(kctx->kc_seq_send)))
goto out_err;
if (get_bytes(&p, end, &kctx->kc_enctype, sizeof(kctx->kc_enctype)))
goto out_err;
if (get_bytes(&p, end, &keysize, sizeof(keysize)))
goto out_err;
if (get_bytes(&p, end, &tmp_uint, sizeof(tmp_uint)))
goto out_err;
if (tmp_uint != 3) {
CERROR("Invalid number of keys: %u\n", tmp_uint);
goto out_err;
}
if (get_keyblock(&p, end, &kctx->kc_keye, keysize))
goto out_err;
if (get_keyblock(&p, end, &kctx->kc_keyi, keysize))
goto out_err;
if (get_keyblock(&p, end, &kctx->kc_keyc, keysize))
goto out_err;
CDEBUG(D_SEC, "successfully imported v2 context\n");
return 0;
out_err:
return GSS_S_FAILURE;
}
static
__u32 gss_import_sec_context_kerberos(rawobj_t *inbuf,
struct gss_ctx *gctx)
{
struct krb5_ctx *kctx;
char *p = (char *) inbuf->data;
char *end = (char *) (inbuf->data + inbuf->len);
unsigned int tmp_uint, rc;
if (get_bytes(&p, end, &tmp_uint, sizeof(tmp_uint))) {
CERROR("Fail to read version\n");
return GSS_S_FAILURE;
}
if (tmp_uint > 2) {
CERROR("Invalid version %u\n", tmp_uint);
return GSS_S_FAILURE;
}
OBD_ALLOC_PTR(kctx);
if (!kctx)
return GSS_S_FAILURE;
if (tmp_uint == 0 || tmp_uint == 1) {
kctx->kc_initiate = tmp_uint;
rc = import_context_rfc1964(kctx, p, end);
} else {
rc = import_context_rfc4121(kctx, p, end);
}
if (rc == 0)
rc = krb5_init_keys(kctx);
if (rc) {
delete_context_kerberos(kctx);
OBD_FREE_PTR(kctx);
return GSS_S_FAILURE;
}
gctx->internal_ctx_id = kctx;
return GSS_S_COMPLETE;
}
static
__u32 gss_copy_reverse_context_kerberos(struct gss_ctx *gctx,
struct gss_ctx *gctx_new)
{
struct krb5_ctx *kctx = gctx->internal_ctx_id;
struct krb5_ctx *knew;
OBD_ALLOC_PTR(knew);
if (!knew)
return GSS_S_FAILURE;
knew->kc_initiate = kctx->kc_initiate ? 0 : 1;
knew->kc_cfx = kctx->kc_cfx;
knew->kc_seed_init = kctx->kc_seed_init;
knew->kc_have_acceptor_subkey = kctx->kc_have_acceptor_subkey;
knew->kc_endtime = kctx->kc_endtime;
memcpy(knew->kc_seed, kctx->kc_seed, sizeof(kctx->kc_seed));
knew->kc_seq_send = kctx->kc_seq_recv;
knew->kc_seq_recv = kctx->kc_seq_send;
knew->kc_enctype = kctx->kc_enctype;
if (rawobj_dup(&knew->kc_mech_used, &kctx->kc_mech_used))
goto out_err;
if (keyblock_dup(&knew->kc_keye, &kctx->kc_keye))
goto out_err;
if (keyblock_dup(&knew->kc_keyi, &kctx->kc_keyi))
goto out_err;
if (keyblock_dup(&knew->kc_keyc, &kctx->kc_keyc))
goto out_err;
if (krb5_init_keys(knew))
goto out_err;
gctx_new->internal_ctx_id = knew;
CDEBUG(D_SEC, "successfully copied reverse context\n");
return GSS_S_COMPLETE;
out_err:
delete_context_kerberos(knew);
OBD_FREE_PTR(knew);
return GSS_S_FAILURE;
}
static
__u32 gss_inquire_context_kerberos(struct gss_ctx *gctx,
unsigned long *endtime)
{
struct krb5_ctx *kctx = gctx->internal_ctx_id;
*endtime = (unsigned long) ((__u32) kctx->kc_endtime);
return GSS_S_COMPLETE;
}
static
void gss_delete_sec_context_kerberos(void *internal_ctx)
{
struct krb5_ctx *kctx = internal_ctx;
delete_context_kerberos(kctx);
OBD_FREE_PTR(kctx);
}
static
void buf_to_sg(struct scatterlist *sg, void *ptr, int len)
{
sg_set_buf(sg, ptr, len);
}
static
__u32 krb5_encrypt(struct crypto_blkcipher *tfm,
int decrypt,
void * iv,
void * in,
void * out,
int length)
{
struct blkcipher_desc desc;
struct scatterlist sg;
__u8 local_iv[16] = {0};
__u32 ret = -EINVAL;
LASSERT(tfm);
desc.tfm = tfm;
desc.info = local_iv;
desc.flags= 0;
if (length % crypto_blkcipher_blocksize(tfm) != 0) {
CERROR("output length %d mismatch blocksize %d\n",
length, crypto_blkcipher_blocksize(tfm));
goto out;
}
if (crypto_blkcipher_ivsize(tfm) > 16) {
CERROR("iv size too large %d\n", crypto_blkcipher_ivsize(tfm));
goto out;
}
if (iv)
memcpy(local_iv, iv, crypto_blkcipher_ivsize(tfm));
memcpy(out, in, length);
buf_to_sg(&sg, out, length);
if (decrypt)
ret = crypto_blkcipher_decrypt_iv(&desc, &sg, &sg, length);
else
ret = crypto_blkcipher_encrypt_iv(&desc, &sg, &sg, length);
out:
return(ret);
}
static inline
int krb5_digest_hmac(struct crypto_hash *tfm,
rawobj_t *key,
struct krb5_header *khdr,
int msgcnt, rawobj_t *msgs,
int iovcnt, lnet_kiov_t *iovs,
rawobj_t *cksum)
{
struct hash_desc desc;
struct scatterlist sg[1];
int i;
crypto_hash_setkey(tfm, key->data, key->len);
desc.tfm = tfm;
desc.flags= 0;
crypto_hash_init(&desc);
for (i = 0; i < msgcnt; i++) {
if (msgs[i].len == 0)
continue;
buf_to_sg(sg, (char *) msgs[i].data, msgs[i].len);
crypto_hash_update(&desc, sg, msgs[i].len);
}
for (i = 0; i < iovcnt; i++) {
if (iovs[i].kiov_len == 0)
continue;
sg_set_page(&sg[0], iovs[i].kiov_page, iovs[i].kiov_len,
iovs[i].kiov_offset);
crypto_hash_update(&desc, sg, iovs[i].kiov_len);
}
if (khdr) {
buf_to_sg(sg, (char *) khdr, sizeof(*khdr));
crypto_hash_update(&desc, sg, sizeof(*khdr));
}
return crypto_hash_final(&desc, cksum->data);
}
static inline
int krb5_digest_norm(struct crypto_hash *tfm,
struct krb5_keyblock *kb,
struct krb5_header *khdr,
int msgcnt, rawobj_t *msgs,
int iovcnt, lnet_kiov_t *iovs,
rawobj_t *cksum)
{
struct hash_desc desc;
struct scatterlist sg[1];
int i;
LASSERT(kb->kb_tfm);
desc.tfm = tfm;
desc.flags= 0;
crypto_hash_init(&desc);
for (i = 0; i < msgcnt; i++) {
if (msgs[i].len == 0)
continue;
buf_to_sg(sg, (char *) msgs[i].data, msgs[i].len);
crypto_hash_update(&desc, sg, msgs[i].len);
}
for (i = 0; i < iovcnt; i++) {
if (iovs[i].kiov_len == 0)
continue;
sg_set_page(&sg[0], iovs[i].kiov_page, iovs[i].kiov_len,
iovs[i].kiov_offset);
crypto_hash_update(&desc, sg, iovs[i].kiov_len);
}
if (khdr) {
buf_to_sg(sg, (char *) khdr, sizeof(*khdr));
crypto_hash_update(&desc, sg, sizeof(*khdr));
}
crypto_hash_final(&desc, cksum->data);
return krb5_encrypt(kb->kb_tfm, 0, NULL, cksum->data,
cksum->data, cksum->len);
}
static
__s32 krb5_make_checksum(__u32 enctype,
struct krb5_keyblock *kb,
struct krb5_header *khdr,
int msgcnt, rawobj_t *msgs,
int iovcnt, lnet_kiov_t *iovs,
rawobj_t *cksum)
{
struct krb5_enctype *ke = &enctypes[enctype];
struct crypto_hash *tfm;
__u32 code = GSS_S_FAILURE;
int rc;
if (!(tfm = ll_crypto_alloc_hash(ke->ke_hash_name, 0, 0))) {
CERROR("failed to alloc TFM: %s\n", ke->ke_hash_name);
return GSS_S_FAILURE;
}
cksum->len = crypto_hash_digestsize(tfm);
OBD_ALLOC_LARGE(cksum->data, cksum->len);
if (!cksum->data) {
cksum->len = 0;
goto out_tfm;
}
if (ke->ke_hash_hmac)
rc = krb5_digest_hmac(tfm, &kb->kb_key,
khdr, msgcnt, msgs, iovcnt, iovs, cksum);
else
rc = krb5_digest_norm(tfm, kb,
khdr, msgcnt, msgs, iovcnt, iovs, cksum);
if (rc == 0)
code = GSS_S_COMPLETE;
out_tfm:
crypto_free_hash(tfm);
return code;
}
static void fill_krb5_header(struct krb5_ctx *kctx,
struct krb5_header *khdr,
int privacy)
{
unsigned char acceptor_flag;
acceptor_flag = kctx->kc_initiate ? 0 : FLAG_SENDER_IS_ACCEPTOR;
if (privacy) {
khdr->kh_tok_id = cpu_to_be16(KG_TOK_WRAP_MSG);
khdr->kh_flags = acceptor_flag | FLAG_WRAP_CONFIDENTIAL;
khdr->kh_ec = cpu_to_be16(0);
khdr->kh_rrc = cpu_to_be16(0);
} else {
khdr->kh_tok_id = cpu_to_be16(KG_TOK_MIC_MSG);
khdr->kh_flags = acceptor_flag;
khdr->kh_ec = cpu_to_be16(0xffff);
khdr->kh_rrc = cpu_to_be16(0xffff);
}
khdr->kh_filler = 0xff;
spin_lock(&krb5_seq_lock);
khdr->kh_seq = cpu_to_be64(kctx->kc_seq_send++);
spin_unlock(&krb5_seq_lock);
}
static __u32 verify_krb5_header(struct krb5_ctx *kctx,
struct krb5_header *khdr,
int privacy)
{
unsigned char acceptor_flag;
__u16 tok_id, ec_rrc;
acceptor_flag = kctx->kc_initiate ? FLAG_SENDER_IS_ACCEPTOR : 0;
if (privacy) {
tok_id = KG_TOK_WRAP_MSG;
ec_rrc = 0x0;
} else {
tok_id = KG_TOK_MIC_MSG;
ec_rrc = 0xffff;
}
if (be16_to_cpu(khdr->kh_tok_id) != tok_id) {
CERROR("bad token id\n");
return GSS_S_DEFECTIVE_TOKEN;
}
if ((khdr->kh_flags & FLAG_SENDER_IS_ACCEPTOR) != acceptor_flag) {
CERROR("bad direction flag\n");
return GSS_S_BAD_SIG;
}
if (privacy && (khdr->kh_flags & FLAG_WRAP_CONFIDENTIAL) == 0) {
CERROR("missing confidential flag\n");
return GSS_S_BAD_SIG;
}
if (khdr->kh_filler != 0xff) {
CERROR("bad filler\n");
return GSS_S_DEFECTIVE_TOKEN;
}
if (be16_to_cpu(khdr->kh_ec) != ec_rrc ||
be16_to_cpu(khdr->kh_rrc) != ec_rrc) {
CERROR("bad EC or RRC\n");
return GSS_S_DEFECTIVE_TOKEN;
}
return GSS_S_COMPLETE;
}
static
__u32 gss_get_mic_kerberos(struct gss_ctx *gctx,
int msgcnt,
rawobj_t *msgs,
int iovcnt,
lnet_kiov_t *iovs,
rawobj_t *token)
{
struct krb5_ctx *kctx = gctx->internal_ctx_id;
struct krb5_enctype *ke = &enctypes[kctx->kc_enctype];
struct krb5_header *khdr;
rawobj_t cksum = RAWOBJ_EMPTY;
LASSERT(token->len >= sizeof(*khdr));
khdr = (struct krb5_header *) token->data;
fill_krb5_header(kctx, khdr, 0);
if (krb5_make_checksum(kctx->kc_enctype, &kctx->kc_keyc,
khdr, msgcnt, msgs, iovcnt, iovs, &cksum))
return GSS_S_FAILURE;
LASSERT(cksum.len >= ke->ke_hash_size);
LASSERT(token->len >= sizeof(*khdr) + ke->ke_hash_size);
memcpy(khdr + 1, cksum.data + cksum.len - ke->ke_hash_size,
ke->ke_hash_size);
token->len = sizeof(*khdr) + ke->ke_hash_size;
rawobj_free(&cksum);
return GSS_S_COMPLETE;
}
static
__u32 gss_verify_mic_kerberos(struct gss_ctx *gctx,
int msgcnt,
rawobj_t *msgs,
int iovcnt,
lnet_kiov_t *iovs,
rawobj_t *token)
{
struct krb5_ctx *kctx = gctx->internal_ctx_id;
struct krb5_enctype *ke = &enctypes[kctx->kc_enctype];
struct krb5_header *khdr;
rawobj_t cksum = RAWOBJ_EMPTY;
__u32 major;
if (token->len < sizeof(*khdr)) {
CERROR("short signature: %u\n", token->len);
return GSS_S_DEFECTIVE_TOKEN;
}
khdr = (struct krb5_header *) token->data;
major = verify_krb5_header(kctx, khdr, 0);
if (major != GSS_S_COMPLETE) {
CERROR("bad krb5 header\n");
return major;
}
if (token->len < sizeof(*khdr) + ke->ke_hash_size) {
CERROR("short signature: %u, require %d\n",
token->len, (int) sizeof(*khdr) + ke->ke_hash_size);
return GSS_S_FAILURE;
}
if (krb5_make_checksum(kctx->kc_enctype, &kctx->kc_keyc,
khdr, msgcnt, msgs, iovcnt, iovs, &cksum)) {
CERROR("failed to make checksum\n");
return GSS_S_FAILURE;
}
LASSERT(cksum.len >= ke->ke_hash_size);
if (memcmp(khdr + 1, cksum.data + cksum.len - ke->ke_hash_size,
ke->ke_hash_size)) {
CERROR("checksum mismatch\n");
rawobj_free(&cksum);
return GSS_S_BAD_SIG;
}
rawobj_free(&cksum);
return GSS_S_COMPLETE;
}
static
int add_padding(rawobj_t *msg, int msg_buflen, int blocksize)
{
int padding;
padding = (blocksize - (msg->len & (blocksize - 1))) &
(blocksize - 1);
if (!padding)
return 0;
if (msg->len + padding > msg_buflen) {
CERROR("bufsize %u too small: datalen %u, padding %u\n",
msg_buflen, msg->len, padding);
return -EINVAL;
}
memset(msg->data + msg->len, padding, padding);
msg->len += padding;
return 0;
}
static
int krb5_encrypt_rawobjs(struct crypto_blkcipher *tfm,
int mode_ecb,
int inobj_cnt,
rawobj_t *inobjs,
rawobj_t *outobj,
int enc)
{
struct blkcipher_desc desc;
struct scatterlist src, dst;
__u8 local_iv[16] = {0}, *buf;
__u32 datalen = 0;
int i, rc;
buf = outobj->data;
desc.tfm = tfm;
desc.info = local_iv;
desc.flags = 0;
for (i = 0; i < inobj_cnt; i++) {
LASSERT(buf + inobjs[i].len <= outobj->data + outobj->len);
buf_to_sg(&src, inobjs[i].data, inobjs[i].len);
buf_to_sg(&dst, buf, outobj->len - datalen);
if (mode_ecb) {
if (enc)
rc = crypto_blkcipher_encrypt(
&desc, &dst, &src, src.length);
else
rc = crypto_blkcipher_decrypt(
&desc, &dst, &src, src.length);
} else {
if (enc)
rc = crypto_blkcipher_encrypt_iv(
&desc, &dst, &src, src.length);
else
rc = crypto_blkcipher_decrypt_iv(
&desc, &dst, &src, src.length);
}
if (rc) {
CERROR("encrypt error %d\n", rc);
return rc;
}
datalen += inobjs[i].len;
buf += inobjs[i].len;
}
outobj->len = datalen;
return 0;
}
static
int krb5_encrypt_bulk(struct crypto_blkcipher *tfm,
struct krb5_header *khdr,
char *confounder,
struct ptlrpc_bulk_desc *desc,
rawobj_t *cipher,
int adj_nob)
{
struct blkcipher_desc ciph_desc;
__u8 local_iv[16] = {0};
struct scatterlist src, dst;
int blocksize, i, rc, nob = 0;
LASSERT(desc->bd_iov_count);
LASSERT(desc->bd_enc_iov);
blocksize = crypto_blkcipher_blocksize(tfm);
LASSERT(blocksize > 1);
LASSERT(cipher->len == blocksize + sizeof(*khdr));
ciph_desc.tfm = tfm;
ciph_desc.info = local_iv;
ciph_desc.flags = 0;
buf_to_sg(&src, confounder, blocksize);
buf_to_sg(&dst, cipher->data, blocksize);
rc = crypto_blkcipher_encrypt_iv(&ciph_desc, &dst, &src, blocksize);
if (rc) {
CERROR("error to encrypt confounder: %d\n", rc);
return rc;
}
for (i = 0; i < desc->bd_iov_count; i++) {
sg_set_page(&src, desc->bd_iov[i].kiov_page,
(desc->bd_iov[i].kiov_len + blocksize - 1) &
(~(blocksize - 1)),
desc->bd_iov[i].kiov_offset);
if (adj_nob)
nob += src.length;
sg_set_page(&dst, desc->bd_enc_iov[i].kiov_page, src.length,
src.offset);
desc->bd_enc_iov[i].kiov_offset = dst.offset;
desc->bd_enc_iov[i].kiov_len = dst.length;
rc = crypto_blkcipher_encrypt_iv(&ciph_desc, &dst, &src,
src.length);
if (rc) {
CERROR("error to encrypt page: %d\n", rc);
return rc;
}
}
buf_to_sg(&src, khdr, sizeof(*khdr));
buf_to_sg(&dst, cipher->data + blocksize, sizeof(*khdr));
rc = crypto_blkcipher_encrypt_iv(&ciph_desc,
&dst, &src, sizeof(*khdr));
if (rc) {
CERROR("error to encrypt krb5 header: %d\n", rc);
return rc;
}
if (adj_nob)
desc->bd_nob = nob;
return 0;
}
static
int krb5_decrypt_bulk(struct crypto_blkcipher *tfm,
struct krb5_header *khdr,
struct ptlrpc_bulk_desc *desc,
rawobj_t *cipher,
rawobj_t *plain,
int adj_nob)
{
struct blkcipher_desc ciph_desc;
__u8 local_iv[16] = {0};
struct scatterlist src, dst;
int ct_nob = 0, pt_nob = 0;
int blocksize, i, rc;
LASSERT(desc->bd_iov_count);
LASSERT(desc->bd_enc_iov);
LASSERT(desc->bd_nob_transferred);
blocksize = crypto_blkcipher_blocksize(tfm);
LASSERT(blocksize > 1);
LASSERT(cipher->len == blocksize + sizeof(*khdr));
ciph_desc.tfm = tfm;
ciph_desc.info = local_iv;
ciph_desc.flags = 0;
if (desc->bd_nob_transferred % blocksize) {
CERROR("odd transferred nob: %d\n", desc->bd_nob_transferred);
return -EPROTO;
}
buf_to_sg(&src, cipher->data, blocksize);
buf_to_sg(&dst, plain->data, blocksize);
rc = crypto_blkcipher_decrypt_iv(&ciph_desc, &dst, &src, blocksize);
if (rc) {
CERROR("error to decrypt confounder: %d\n", rc);
return rc;
}
for (i = 0; i < desc->bd_iov_count && ct_nob < desc->bd_nob_transferred;
i++) {
if (desc->bd_enc_iov[i].kiov_offset % blocksize != 0 ||
desc->bd_enc_iov[i].kiov_len % blocksize != 0) {
CERROR("page %d: odd offset %u len %u, blocksize %d\n",
i, desc->bd_enc_iov[i].kiov_offset,
desc->bd_enc_iov[i].kiov_len, blocksize);
return -EFAULT;
}
if (adj_nob) {
if (ct_nob + desc->bd_enc_iov[i].kiov_len >
desc->bd_nob_transferred)
desc->bd_enc_iov[i].kiov_len =
desc->bd_nob_transferred - ct_nob;
desc->bd_iov[i].kiov_len = desc->bd_enc_iov[i].kiov_len;
if (pt_nob + desc->bd_enc_iov[i].kiov_len >desc->bd_nob)
desc->bd_iov[i].kiov_len = desc->bd_nob -pt_nob;
} else {
LASSERT(ct_nob + desc->bd_enc_iov[i].kiov_len <=
desc->bd_nob_transferred);
LASSERT(desc->bd_iov[i].kiov_len <=
desc->bd_enc_iov[i].kiov_len);
}
if (desc->bd_enc_iov[i].kiov_len == 0)
continue;
sg_set_page(&src, desc->bd_enc_iov[i].kiov_page,
desc->bd_enc_iov[i].kiov_len,
desc->bd_enc_iov[i].kiov_offset);
dst = src;
if (desc->bd_iov[i].kiov_len % blocksize == 0)
sg_assign_page(&dst, desc->bd_iov[i].kiov_page);
rc = crypto_blkcipher_decrypt_iv(&ciph_desc, &dst, &src,
src.length);
if (rc) {
CERROR("error to decrypt page: %d\n", rc);
return rc;
}
if (desc->bd_iov[i].kiov_len % blocksize != 0) {
memcpy(page_address(desc->bd_iov[i].kiov_page) +
desc->bd_iov[i].kiov_offset,
page_address(desc->bd_enc_iov[i].kiov_page) +
desc->bd_iov[i].kiov_offset,
desc->bd_iov[i].kiov_len);
}
ct_nob += desc->bd_enc_iov[i].kiov_len;
pt_nob += desc->bd_iov[i].kiov_len;
}
if (unlikely(ct_nob != desc->bd_nob_transferred)) {
CERROR("%d cipher text transferred but only %d decrypted\n",
desc->bd_nob_transferred, ct_nob);
return -EFAULT;
}
if (unlikely(!adj_nob && pt_nob != desc->bd_nob)) {
CERROR("%d plain text expected but only %d received\n",
desc->bd_nob, pt_nob);
return -EFAULT;
}
if (adj_nob)
while (i < desc->bd_iov_count)
desc->bd_iov[i++].kiov_len = 0;
buf_to_sg(&src, cipher->data + blocksize, sizeof(*khdr));
buf_to_sg(&dst, cipher->data + blocksize, sizeof(*khdr));
rc = crypto_blkcipher_decrypt_iv(&ciph_desc,
&dst, &src, sizeof(*khdr));
if (rc) {
CERROR("error to decrypt tail: %d\n", rc);
return rc;
}
if (memcmp(cipher->data + blocksize, khdr, sizeof(*khdr))) {
CERROR("krb5 header doesn't match\n");
return -EACCES;
}
return 0;
}
static
__u32 gss_wrap_kerberos(struct gss_ctx *gctx,
rawobj_t *gsshdr,
rawobj_t *msg,
int msg_buflen,
rawobj_t *token)
{
struct krb5_ctx *kctx = gctx->internal_ctx_id;
struct krb5_enctype *ke = &enctypes[kctx->kc_enctype];
struct krb5_header *khdr;
int blocksize;
rawobj_t cksum = RAWOBJ_EMPTY;
rawobj_t data_desc[3], cipher;
__u8 conf[GSS_MAX_CIPHER_BLOCK];
int rc = 0;
LASSERT(ke);
LASSERT(ke->ke_conf_size <= GSS_MAX_CIPHER_BLOCK);
LASSERT(kctx->kc_keye.kb_tfm == NULL ||
ke->ke_conf_size >=
crypto_blkcipher_blocksize(kctx->kc_keye.kb_tfm));
LASSERT(token->len >= sizeof(*khdr));
khdr = (struct krb5_header *) token->data;
fill_krb5_header(kctx, khdr, 1);
cfs_get_random_bytes(conf, ke->ke_conf_size);
if (kctx->kc_enctype == ENCTYPE_ARCFOUR_HMAC) {
LASSERT(kctx->kc_keye.kb_tfm == NULL);
blocksize = 1;
} else {
LASSERT(kctx->kc_keye.kb_tfm);
blocksize = crypto_blkcipher_blocksize(kctx->kc_keye.kb_tfm);
}
LASSERT(blocksize <= ke->ke_conf_size);
if (add_padding(msg, msg_buflen, blocksize))
return GSS_S_FAILURE;
data_desc[0].data = conf;
data_desc[0].len = ke->ke_conf_size;
data_desc[1].data = gsshdr->data;
data_desc[1].len = gsshdr->len;
data_desc[2].data = msg->data;
data_desc[2].len = msg->len;
if (krb5_make_checksum(kctx->kc_enctype, &kctx->kc_keyi,
khdr, 3, data_desc, 0, NULL, &cksum))
return GSS_S_FAILURE;
LASSERT(cksum.len >= ke->ke_hash_size);
data_desc[0].data = conf;
data_desc[0].len = ke->ke_conf_size;
data_desc[1].data = msg->data;
data_desc[1].len = msg->len;
data_desc[2].data = (__u8 *) khdr;
data_desc[2].len = sizeof(*khdr);
cipher.data = (__u8 *) (khdr + 1);
cipher.len = token->len - sizeof(*khdr);
LASSERT(cipher.len >= ke->ke_conf_size + msg->len + sizeof(*khdr));
if (kctx->kc_enctype == ENCTYPE_ARCFOUR_HMAC) {
rawobj_t arc4_keye;
struct crypto_blkcipher *arc4_tfm;
if (krb5_make_checksum(ENCTYPE_ARCFOUR_HMAC, &kctx->kc_keyi,
NULL, 1, &cksum, 0, NULL, &arc4_keye)) {
CERROR("failed to obtain arc4 enc key\n");
GOTO(arc4_out, rc = -EACCES);
}
arc4_tfm = crypto_alloc_blkcipher("ecb(arc4)", 0, 0);
if (IS_ERR(arc4_tfm)) {
CERROR("failed to alloc tfm arc4 in ECB mode\n");
GOTO(arc4_out_key, rc = -EACCES);
}
if (crypto_blkcipher_setkey(arc4_tfm, arc4_keye.data,
arc4_keye.len)) {
CERROR("failed to set arc4 key, len %d\n",
arc4_keye.len);
GOTO(arc4_out_tfm, rc = -EACCES);
}
rc = krb5_encrypt_rawobjs(arc4_tfm, 1,
3, data_desc, &cipher, 1);
arc4_out_tfm:
crypto_free_blkcipher(arc4_tfm);
arc4_out_key:
rawobj_free(&arc4_keye);
arc4_out:
do {} while(0);
} else {
rc = krb5_encrypt_rawobjs(kctx->kc_keye.kb_tfm, 0,
3, data_desc, &cipher, 1);
}
if (rc != 0) {
rawobj_free(&cksum);
return GSS_S_FAILURE;
}
LASSERT(token->len >= sizeof(*khdr) + cipher.len + ke->ke_hash_size);
memcpy((char *)(khdr + 1) + cipher.len,
cksum.data + cksum.len - ke->ke_hash_size,
ke->ke_hash_size);
rawobj_free(&cksum);
token->len = sizeof(*khdr) + cipher.len + ke->ke_hash_size;
return GSS_S_COMPLETE;
}
static
__u32 gss_prep_bulk_kerberos(struct gss_ctx *gctx,
struct ptlrpc_bulk_desc *desc)
{
struct krb5_ctx *kctx = gctx->internal_ctx_id;
int blocksize, i;
LASSERT(desc->bd_iov_count);
LASSERT(desc->bd_enc_iov);
LASSERT(kctx->kc_keye.kb_tfm);
blocksize = crypto_blkcipher_blocksize(kctx->kc_keye.kb_tfm);
for (i = 0; i < desc->bd_iov_count; i++) {
LASSERT(desc->bd_enc_iov[i].kiov_page);
if (desc->bd_iov[i].kiov_offset & blocksize) {
CERROR("odd offset %d in page %d\n",
desc->bd_iov[i].kiov_offset, i);
return GSS_S_FAILURE;
}
desc->bd_enc_iov[i].kiov_offset = desc->bd_iov[i].kiov_offset;
desc->bd_enc_iov[i].kiov_len = (desc->bd_iov[i].kiov_len +
blocksize - 1) & (~(blocksize - 1));
}
return GSS_S_COMPLETE;
}
static
__u32 gss_wrap_bulk_kerberos(struct gss_ctx *gctx,
struct ptlrpc_bulk_desc *desc,
rawobj_t *token, int adj_nob)
{
struct krb5_ctx *kctx = gctx->internal_ctx_id;
struct krb5_enctype *ke = &enctypes[kctx->kc_enctype];
struct krb5_header *khdr;
int blocksize;
rawobj_t cksum = RAWOBJ_EMPTY;
rawobj_t data_desc[1], cipher;
__u8 conf[GSS_MAX_CIPHER_BLOCK];
int rc = 0;
LASSERT(ke);
LASSERT(ke->ke_conf_size <= GSS_MAX_CIPHER_BLOCK);
LASSERT(token->len >= sizeof(*khdr));
khdr = (struct krb5_header *) token->data;
fill_krb5_header(kctx, khdr, 1);
cfs_get_random_bytes(conf, ke->ke_conf_size);
if (kctx->kc_enctype == ENCTYPE_ARCFOUR_HMAC) {
LASSERT(kctx->kc_keye.kb_tfm == NULL);
blocksize = 1;
} else {
LASSERT(kctx->kc_keye.kb_tfm);
blocksize = crypto_blkcipher_blocksize(kctx->kc_keye.kb_tfm);
}
LASSERT(blocksize <= ke->ke_conf_size);
LASSERT(sizeof(*khdr) >= blocksize && sizeof(*khdr) % blocksize == 0);
LASSERT(token->len >= sizeof(*khdr) + blocksize + sizeof(*khdr) + 16);
data_desc[0].data = conf;
data_desc[0].len = ke->ke_conf_size;
if (krb5_make_checksum(kctx->kc_enctype, &kctx->kc_keyi,
khdr, 1, data_desc,
desc->bd_iov_count, desc->bd_iov,
&cksum))
return GSS_S_FAILURE;
LASSERT(cksum.len >= ke->ke_hash_size);
data_desc[0].data = conf;
data_desc[0].len = ke->ke_conf_size;
cipher.data = (__u8 *) (khdr + 1);
cipher.len = blocksize + sizeof(*khdr);
if (kctx->kc_enctype == ENCTYPE_ARCFOUR_HMAC) {
LBUG();
rc = 0;
} else {
rc = krb5_encrypt_bulk(kctx->kc_keye.kb_tfm, khdr,
conf, desc, &cipher, adj_nob);
}
if (rc != 0) {
rawobj_free(&cksum);
return GSS_S_FAILURE;
}
LASSERT(token->len >= sizeof(*khdr) + cipher.len + ke->ke_hash_size);
memcpy((char *)(khdr + 1) + cipher.len,
cksum.data + cksum.len - ke->ke_hash_size,
ke->ke_hash_size);
rawobj_free(&cksum);
token->len = sizeof(*khdr) + cipher.len + ke->ke_hash_size;
return GSS_S_COMPLETE;
}
static
__u32 gss_unwrap_kerberos(struct gss_ctx *gctx,
rawobj_t *gsshdr,
rawobj_t *token,
rawobj_t *msg)
{
struct krb5_ctx *kctx = gctx->internal_ctx_id;
struct krb5_enctype *ke = &enctypes[kctx->kc_enctype];
struct krb5_header *khdr;
unsigned char *tmpbuf;
int blocksize, bodysize;
rawobj_t cksum = RAWOBJ_EMPTY;
rawobj_t cipher_in, plain_out;
rawobj_t hash_objs[3];
int rc = 0;
__u32 major;
LASSERT(ke);
if (token->len < sizeof(*khdr)) {
CERROR("short signature: %u\n", token->len);
return GSS_S_DEFECTIVE_TOKEN;
}
khdr = (struct krb5_header *) token->data;
major = verify_krb5_header(kctx, khdr, 1);
if (major != GSS_S_COMPLETE) {
CERROR("bad krb5 header\n");
return major;
}
if (kctx->kc_enctype == ENCTYPE_ARCFOUR_HMAC) {
LASSERT(kctx->kc_keye.kb_tfm == NULL);
blocksize = 1;
} else {
LASSERT(kctx->kc_keye.kb_tfm);
blocksize = crypto_blkcipher_blocksize(kctx->kc_keye.kb_tfm);
}
bodysize = token->len - sizeof(*khdr) - ke->ke_hash_size;
if (bodysize % blocksize) {
CERROR("odd bodysize %d\n", bodysize);
return GSS_S_DEFECTIVE_TOKEN;
}
if (bodysize <= ke->ke_conf_size + sizeof(*khdr)) {
CERROR("incomplete token: bodysize %d\n", bodysize);
return GSS_S_DEFECTIVE_TOKEN;
}
if (msg->len < bodysize - ke->ke_conf_size - sizeof(*khdr)) {
CERROR("buffer too small: %u, require %d\n",
msg->len, bodysize - ke->ke_conf_size);
return GSS_S_FAILURE;
}
OBD_ALLOC_LARGE(tmpbuf, bodysize);
if (!tmpbuf)
return GSS_S_FAILURE;
major = GSS_S_FAILURE;
cipher_in.data = (__u8 *) (khdr + 1);
cipher_in.len = bodysize;
plain_out.data = tmpbuf;
plain_out.len = bodysize;
if (kctx->kc_enctype == ENCTYPE_ARCFOUR_HMAC) {
rawobj_t arc4_keye;
struct crypto_blkcipher *arc4_tfm;
cksum.data = token->data + token->len - ke->ke_hash_size;
cksum.len = ke->ke_hash_size;
if (krb5_make_checksum(ENCTYPE_ARCFOUR_HMAC, &kctx->kc_keyi,
NULL, 1, &cksum, 0, NULL, &arc4_keye)) {
CERROR("failed to obtain arc4 enc key\n");
GOTO(arc4_out, rc = -EACCES);
}
arc4_tfm = crypto_alloc_blkcipher("ecb(arc4)", 0, 0);
if (IS_ERR(arc4_tfm)) {
CERROR("failed to alloc tfm arc4 in ECB mode\n");
GOTO(arc4_out_key, rc = -EACCES);
}
if (crypto_blkcipher_setkey(arc4_tfm,
arc4_keye.data, arc4_keye.len)) {
CERROR("failed to set arc4 key, len %d\n",
arc4_keye.len);
GOTO(arc4_out_tfm, rc = -EACCES);
}
rc = krb5_encrypt_rawobjs(arc4_tfm, 1,
1, &cipher_in, &plain_out, 0);
arc4_out_tfm:
crypto_free_blkcipher(arc4_tfm);
arc4_out_key:
rawobj_free(&arc4_keye);
arc4_out:
cksum = RAWOBJ_EMPTY;
} else {
rc = krb5_encrypt_rawobjs(kctx->kc_keye.kb_tfm, 0,
1, &cipher_in, &plain_out, 0);
}
if (rc != 0) {
CERROR("error decrypt\n");
goto out_free;
}
LASSERT(plain_out.len == bodysize);
if (memcmp(khdr, plain_out.data + plain_out.len - sizeof(*khdr),
sizeof(*khdr))) {
CERROR("decrypted krb5 header mismatch\n");
goto out_free;
}
hash_objs[0].len = ke->ke_conf_size;
hash_objs[0].data = plain_out.data;
hash_objs[1].len = gsshdr->len;
hash_objs[1].data = gsshdr->data;
hash_objs[2].len = plain_out.len - ke->ke_conf_size - sizeof(*khdr);
hash_objs[2].data = plain_out.data + ke->ke_conf_size;
if (krb5_make_checksum(kctx->kc_enctype, &kctx->kc_keyi,
khdr, 3, hash_objs, 0, NULL, &cksum))
goto out_free;
LASSERT(cksum.len >= ke->ke_hash_size);
if (memcmp((char *)(khdr + 1) + bodysize,
cksum.data + cksum.len - ke->ke_hash_size,
ke->ke_hash_size)) {
CERROR("checksum mismatch\n");
goto out_free;
}
msg->len = bodysize - ke->ke_conf_size - sizeof(*khdr);
memcpy(msg->data, tmpbuf + ke->ke_conf_size, msg->len);
major = GSS_S_COMPLETE;
out_free:
OBD_FREE_LARGE(tmpbuf, bodysize);
rawobj_free(&cksum);
return major;
}
static
__u32 gss_unwrap_bulk_kerberos(struct gss_ctx *gctx,
struct ptlrpc_bulk_desc *desc,
rawobj_t *token, int adj_nob)
{
struct krb5_ctx *kctx = gctx->internal_ctx_id;
struct krb5_enctype *ke = &enctypes[kctx->kc_enctype];
struct krb5_header *khdr;
int blocksize;
rawobj_t cksum = RAWOBJ_EMPTY;
rawobj_t cipher, plain;
rawobj_t data_desc[1];
int rc;
__u32 major;
LASSERT(ke);
if (token->len < sizeof(*khdr)) {
CERROR("short signature: %u\n", token->len);
return GSS_S_DEFECTIVE_TOKEN;
}
khdr = (struct krb5_header *) token->data;
major = verify_krb5_header(kctx, khdr, 1);
if (major != GSS_S_COMPLETE) {
CERROR("bad krb5 header\n");
return major;
}
if (kctx->kc_enctype == ENCTYPE_ARCFOUR_HMAC) {
LASSERT(kctx->kc_keye.kb_tfm == NULL);
blocksize = 1;
LBUG();
} else {
LASSERT(kctx->kc_keye.kb_tfm);
blocksize = crypto_blkcipher_blocksize(kctx->kc_keye.kb_tfm);
}
LASSERT(sizeof(*khdr) >= blocksize && sizeof(*khdr) % blocksize == 0);
if (token->len < sizeof(*khdr) + blocksize + sizeof(*khdr) +
ke->ke_hash_size) {
CERROR("short token size: %u\n", token->len);
return GSS_S_DEFECTIVE_TOKEN;
}
cipher.data = (__u8 *) (khdr + 1);
cipher.len = blocksize + sizeof(*khdr);
plain.data = cipher.data;
plain.len = cipher.len;
rc = krb5_decrypt_bulk(kctx->kc_keye.kb_tfm, khdr,
desc, &cipher, &plain, adj_nob);
if (rc)
return GSS_S_DEFECTIVE_TOKEN;
data_desc[0].data = plain.data;
data_desc[0].len = blocksize;
if (krb5_make_checksum(kctx->kc_enctype, &kctx->kc_keyi,
khdr, 1, data_desc,
desc->bd_iov_count, desc->bd_iov,
&cksum))
return GSS_S_FAILURE;
LASSERT(cksum.len >= ke->ke_hash_size);
if (memcmp(plain.data + blocksize + sizeof(*khdr),
cksum.data + cksum.len - ke->ke_hash_size,
ke->ke_hash_size)) {
CERROR("checksum mismatch\n");
rawobj_free(&cksum);
return GSS_S_BAD_SIG;
}
rawobj_free(&cksum);
return GSS_S_COMPLETE;
}
int gss_display_kerberos(struct gss_ctx *ctx,
char *buf,
int bufsize)
{
struct krb5_ctx *kctx = ctx->internal_ctx_id;
int written;
written = snprintf(buf, bufsize, "krb5 (%s)",
enctype2str(kctx->kc_enctype));
return written;
}
int __init init_kerberos_module(void)
{
int status;
spin_lock_init(&krb5_seq_lock);
status = lgss_mech_register(&gss_kerberos_mech);
if (status)
CERROR("Failed to register kerberos gss mechanism!\n");
return status;
}
void __exit cleanup_kerberos_module(void)
{
lgss_mech_unregister(&gss_kerberos_mech);
}
