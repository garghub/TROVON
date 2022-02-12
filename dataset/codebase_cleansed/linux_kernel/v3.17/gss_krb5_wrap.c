static inline int
gss_krb5_padding(int blocksize, int length)
{
return blocksize - (length % blocksize);
}
static inline void
gss_krb5_add_padding(struct xdr_buf *buf, int offset, int blocksize)
{
int padding = gss_krb5_padding(blocksize, buf->len - offset);
char *p;
struct kvec *iov;
if (buf->page_len || buf->tail[0].iov_len)
iov = &buf->tail[0];
else
iov = &buf->head[0];
p = iov->iov_base + iov->iov_len;
iov->iov_len += padding;
buf->len += padding;
memset(p, padding, padding);
}
static inline int
gss_krb5_remove_padding(struct xdr_buf *buf, int blocksize)
{
u8 *ptr;
u8 pad;
size_t len = buf->len;
if (len <= buf->head[0].iov_len) {
pad = *(u8 *)(buf->head[0].iov_base + len - 1);
if (pad > buf->head[0].iov_len)
return -EINVAL;
buf->head[0].iov_len -= pad;
goto out;
} else
len -= buf->head[0].iov_len;
if (len <= buf->page_len) {
unsigned int last = (buf->page_base + len - 1)
>>PAGE_CACHE_SHIFT;
unsigned int offset = (buf->page_base + len - 1)
& (PAGE_CACHE_SIZE - 1);
ptr = kmap_atomic(buf->pages[last]);
pad = *(ptr + offset);
kunmap_atomic(ptr);
goto out;
} else
len -= buf->page_len;
BUG_ON(len > buf->tail[0].iov_len);
pad = *(u8 *)(buf->tail[0].iov_base + len - 1);
out:
if (pad > blocksize)
return -EINVAL;
if (buf->len > pad)
buf->len -= pad;
else
return -EINVAL;
return 0;
}
void
gss_krb5_make_confounder(char *p, u32 conflen)
{
static u64 i = 0;
u64 *q = (u64 *)p;
if (i == 0) {
i = prandom_u32();
i = (i << 32) | prandom_u32();
}
switch (conflen) {
case 16:
*q++ = i++;
case 8:
*q++ = i++;
break;
default:
BUG();
}
}
static u32
gss_wrap_kerberos_v1(struct krb5_ctx *kctx, int offset,
struct xdr_buf *buf, struct page **pages)
{
char cksumdata[GSS_KRB5_MAX_CKSUM_LEN];
struct xdr_netobj md5cksum = {.len = sizeof(cksumdata),
.data = cksumdata};
int blocksize = 0, plainlen;
unsigned char *ptr, *msg_start;
s32 now;
int headlen;
struct page **tmp_pages;
u32 seq_send;
u8 *cksumkey;
u32 conflen = kctx->gk5e->conflen;
dprintk("RPC: %s\n", __func__);
now = get_seconds();
blocksize = crypto_blkcipher_blocksize(kctx->enc);
gss_krb5_add_padding(buf, offset, blocksize);
BUG_ON((buf->len - offset) % blocksize);
plainlen = conflen + buf->len - offset;
headlen = g_token_size(&kctx->mech_used,
GSS_KRB5_TOK_HDR_LEN + kctx->gk5e->cksumlength + plainlen) -
(buf->len - offset);
ptr = buf->head[0].iov_base + offset;
xdr_extend_head(buf, offset, headlen);
BUG_ON((buf->len - offset - headlen) % blocksize);
g_make_token_header(&kctx->mech_used,
GSS_KRB5_TOK_HDR_LEN +
kctx->gk5e->cksumlength + plainlen, &ptr);
ptr[0] = (unsigned char) ((KG_TOK_WRAP_MSG >> 8) & 0xff);
ptr[1] = (unsigned char) (KG_TOK_WRAP_MSG & 0xff);
msg_start = ptr + GSS_KRB5_TOK_HDR_LEN + kctx->gk5e->cksumlength;
*(__le16 *)(ptr + 2) = cpu_to_le16(kctx->gk5e->signalg);
*(__le16 *)(ptr + 4) = cpu_to_le16(kctx->gk5e->sealalg);
ptr[6] = 0xff;
ptr[7] = 0xff;
gss_krb5_make_confounder(msg_start, conflen);
if (kctx->gk5e->keyed_cksum)
cksumkey = kctx->cksum;
else
cksumkey = NULL;
tmp_pages = buf->pages;
buf->pages = pages;
if (make_checksum(kctx, ptr, 8, buf, offset + headlen - conflen,
cksumkey, KG_USAGE_SEAL, &md5cksum))
return GSS_S_FAILURE;
buf->pages = tmp_pages;
memcpy(ptr + GSS_KRB5_TOK_HDR_LEN, md5cksum.data, md5cksum.len);
spin_lock(&krb5_seq_lock);
seq_send = kctx->seq_send++;
spin_unlock(&krb5_seq_lock);
if ((krb5_make_seq_num(kctx, kctx->seq, kctx->initiate ? 0 : 0xff,
seq_send, ptr + GSS_KRB5_TOK_HDR_LEN, ptr + 8)))
return GSS_S_FAILURE;
if (kctx->enctype == ENCTYPE_ARCFOUR_HMAC) {
struct crypto_blkcipher *cipher;
int err;
cipher = crypto_alloc_blkcipher(kctx->gk5e->encrypt_name, 0,
CRYPTO_ALG_ASYNC);
if (IS_ERR(cipher))
return GSS_S_FAILURE;
krb5_rc4_setup_enc_key(kctx, cipher, seq_send);
err = gss_encrypt_xdr_buf(cipher, buf,
offset + headlen - conflen, pages);
crypto_free_blkcipher(cipher);
if (err)
return GSS_S_FAILURE;
} else {
if (gss_encrypt_xdr_buf(kctx->enc, buf,
offset + headlen - conflen, pages))
return GSS_S_FAILURE;
}
return (kctx->endtime < now) ? GSS_S_CONTEXT_EXPIRED : GSS_S_COMPLETE;
}
static u32
gss_unwrap_kerberos_v1(struct krb5_ctx *kctx, int offset, struct xdr_buf *buf)
{
int signalg;
int sealalg;
char cksumdata[GSS_KRB5_MAX_CKSUM_LEN];
struct xdr_netobj md5cksum = {.len = sizeof(cksumdata),
.data = cksumdata};
s32 now;
int direction;
s32 seqnum;
unsigned char *ptr;
int bodysize;
void *data_start, *orig_start;
int data_len;
int blocksize;
u32 conflen = kctx->gk5e->conflen;
int crypt_offset;
u8 *cksumkey;
dprintk("RPC: gss_unwrap_kerberos\n");
ptr = (u8 *)buf->head[0].iov_base + offset;
if (g_verify_token_header(&kctx->mech_used, &bodysize, &ptr,
buf->len - offset))
return GSS_S_DEFECTIVE_TOKEN;
if ((ptr[0] != ((KG_TOK_WRAP_MSG >> 8) & 0xff)) ||
(ptr[1] != (KG_TOK_WRAP_MSG & 0xff)))
return GSS_S_DEFECTIVE_TOKEN;
signalg = ptr[2] + (ptr[3] << 8);
if (signalg != kctx->gk5e->signalg)
return GSS_S_DEFECTIVE_TOKEN;
sealalg = ptr[4] + (ptr[5] << 8);
if (sealalg != kctx->gk5e->sealalg)
return GSS_S_DEFECTIVE_TOKEN;
if ((ptr[6] != 0xff) || (ptr[7] != 0xff))
return GSS_S_DEFECTIVE_TOKEN;
crypt_offset = ptr + (GSS_KRB5_TOK_HDR_LEN + kctx->gk5e->cksumlength) -
(unsigned char *)buf->head[0].iov_base;
if (krb5_get_seq_num(kctx, ptr + GSS_KRB5_TOK_HDR_LEN,
ptr + 8, &direction, &seqnum))
return GSS_S_BAD_SIG;
if ((kctx->initiate && direction != 0xff) ||
(!kctx->initiate && direction != 0))
return GSS_S_BAD_SIG;
if (kctx->enctype == ENCTYPE_ARCFOUR_HMAC) {
struct crypto_blkcipher *cipher;
int err;
cipher = crypto_alloc_blkcipher(kctx->gk5e->encrypt_name, 0,
CRYPTO_ALG_ASYNC);
if (IS_ERR(cipher))
return GSS_S_FAILURE;
krb5_rc4_setup_enc_key(kctx, cipher, seqnum);
err = gss_decrypt_xdr_buf(cipher, buf, crypt_offset);
crypto_free_blkcipher(cipher);
if (err)
return GSS_S_DEFECTIVE_TOKEN;
} else {
if (gss_decrypt_xdr_buf(kctx->enc, buf, crypt_offset))
return GSS_S_DEFECTIVE_TOKEN;
}
if (kctx->gk5e->keyed_cksum)
cksumkey = kctx->cksum;
else
cksumkey = NULL;
if (make_checksum(kctx, ptr, 8, buf, crypt_offset,
cksumkey, KG_USAGE_SEAL, &md5cksum))
return GSS_S_FAILURE;
if (memcmp(md5cksum.data, ptr + GSS_KRB5_TOK_HDR_LEN,
kctx->gk5e->cksumlength))
return GSS_S_BAD_SIG;
now = get_seconds();
if (now > kctx->endtime)
return GSS_S_CONTEXT_EXPIRED;
blocksize = crypto_blkcipher_blocksize(kctx->enc);
data_start = ptr + (GSS_KRB5_TOK_HDR_LEN + kctx->gk5e->cksumlength) +
conflen;
orig_start = buf->head[0].iov_base + offset;
data_len = (buf->head[0].iov_base + buf->head[0].iov_len) - data_start;
memmove(orig_start, data_start, data_len);
buf->head[0].iov_len -= (data_start - orig_start);
buf->len -= (data_start - orig_start);
if (gss_krb5_remove_padding(buf, blocksize))
return GSS_S_DEFECTIVE_TOKEN;
return GSS_S_COMPLETE;
}
static void rotate_buf_a_little(struct xdr_buf *buf, unsigned int shift)
{
char head[LOCAL_BUF_LEN];
char tmp[LOCAL_BUF_LEN];
unsigned int this_len, i;
BUG_ON(shift > LOCAL_BUF_LEN);
read_bytes_from_xdr_buf(buf, 0, head, shift);
for (i = 0; i + shift < buf->len; i += LOCAL_BUF_LEN) {
this_len = min(LOCAL_BUF_LEN, buf->len - (i + shift));
read_bytes_from_xdr_buf(buf, i+shift, tmp, this_len);
write_bytes_to_xdr_buf(buf, i, tmp, this_len);
}
write_bytes_to_xdr_buf(buf, buf->len - shift, head, shift);
}
static void _rotate_left(struct xdr_buf *buf, unsigned int shift)
{
int shifted = 0;
int this_shift;
shift %= buf->len;
while (shifted < shift) {
this_shift = min(shift - shifted, LOCAL_BUF_LEN);
rotate_buf_a_little(buf, this_shift);
shifted += this_shift;
}
}
static void rotate_left(u32 base, struct xdr_buf *buf, unsigned int shift)
{
struct xdr_buf subbuf;
xdr_buf_subsegment(buf, &subbuf, base, buf->len - base);
_rotate_left(&subbuf, shift);
}
static u32
gss_wrap_kerberos_v2(struct krb5_ctx *kctx, u32 offset,
struct xdr_buf *buf, struct page **pages)
{
int blocksize;
u8 *ptr, *plainhdr;
s32 now;
u8 flags = 0x00;
__be16 *be16ptr;
__be64 *be64ptr;
u32 err;
dprintk("RPC: %s\n", __func__);
if (kctx->gk5e->encrypt_v2 == NULL)
return GSS_S_FAILURE;
if (xdr_extend_head(buf, offset, GSS_KRB5_TOK_HDR_LEN))
return GSS_S_FAILURE;
ptr = plainhdr = buf->head[0].iov_base + offset;
*ptr++ = (unsigned char) ((KG2_TOK_WRAP>>8) & 0xff);
*ptr++ = (unsigned char) (KG2_TOK_WRAP & 0xff);
if ((kctx->flags & KRB5_CTX_FLAG_INITIATOR) == 0)
flags |= KG2_TOKEN_FLAG_SENTBYACCEPTOR;
if ((kctx->flags & KRB5_CTX_FLAG_ACCEPTOR_SUBKEY) != 0)
flags |= KG2_TOKEN_FLAG_ACCEPTORSUBKEY;
flags |= KG2_TOKEN_FLAG_SEALED;
*ptr++ = flags;
*ptr++ = 0xff;
be16ptr = (__be16 *)ptr;
blocksize = crypto_blkcipher_blocksize(kctx->acceptor_enc);
*be16ptr++ = 0;
*be16ptr++ = 0;
be64ptr = (__be64 *)be16ptr;
spin_lock(&krb5_seq_lock);
*be64ptr = cpu_to_be64(kctx->seq_send64++);
spin_unlock(&krb5_seq_lock);
err = (*kctx->gk5e->encrypt_v2)(kctx, offset, buf, pages);
if (err)
return err;
now = get_seconds();
return (kctx->endtime < now) ? GSS_S_CONTEXT_EXPIRED : GSS_S_COMPLETE;
}
static u32
gss_unwrap_kerberos_v2(struct krb5_ctx *kctx, int offset, struct xdr_buf *buf)
{
s32 now;
u8 *ptr;
u8 flags = 0x00;
u16 ec, rrc;
int err;
u32 headskip, tailskip;
u8 decrypted_hdr[GSS_KRB5_TOK_HDR_LEN];
unsigned int movelen;
dprintk("RPC: %s\n", __func__);
if (kctx->gk5e->decrypt_v2 == NULL)
return GSS_S_FAILURE;
ptr = buf->head[0].iov_base + offset;
if (be16_to_cpu(*((__be16 *)ptr)) != KG2_TOK_WRAP)
return GSS_S_DEFECTIVE_TOKEN;
flags = ptr[2];
if ((!kctx->initiate && (flags & KG2_TOKEN_FLAG_SENTBYACCEPTOR)) ||
(kctx->initiate && !(flags & KG2_TOKEN_FLAG_SENTBYACCEPTOR)))
return GSS_S_BAD_SIG;
if ((flags & KG2_TOKEN_FLAG_SEALED) == 0) {
dprintk("%s: token missing expected sealed flag\n", __func__);
return GSS_S_DEFECTIVE_TOKEN;
}
if (ptr[3] != 0xff)
return GSS_S_DEFECTIVE_TOKEN;
ec = be16_to_cpup((__be16 *)(ptr + 4));
rrc = be16_to_cpup((__be16 *)(ptr + 6));
if (rrc != 0)
rotate_left(offset + 16, buf, rrc);
err = (*kctx->gk5e->decrypt_v2)(kctx, offset, buf,
&headskip, &tailskip);
if (err)
return GSS_S_FAILURE;
err = read_bytes_from_xdr_buf(buf,
buf->len - GSS_KRB5_TOK_HDR_LEN - tailskip,
decrypted_hdr, GSS_KRB5_TOK_HDR_LEN);
if (err) {
dprintk("%s: error %u getting decrypted_hdr\n", __func__, err);
return GSS_S_FAILURE;
}
if (memcmp(ptr, decrypted_hdr, 6)
|| memcmp(ptr + 8, decrypted_hdr + 8, 8)) {
dprintk("%s: token hdr, plaintext hdr mismatch!\n", __func__);
return GSS_S_FAILURE;
}
now = get_seconds();
if (now > kctx->endtime)
return GSS_S_CONTEXT_EXPIRED;
movelen = min_t(unsigned int, buf->head[0].iov_len, buf->len);
movelen -= offset + GSS_KRB5_TOK_HDR_LEN + headskip;
BUG_ON(offset + GSS_KRB5_TOK_HDR_LEN + headskip + movelen >
buf->head[0].iov_len);
memmove(ptr, ptr + GSS_KRB5_TOK_HDR_LEN + headskip, movelen);
buf->head[0].iov_len -= GSS_KRB5_TOK_HDR_LEN + headskip;
buf->len -= GSS_KRB5_TOK_HDR_LEN + headskip;
xdr_buf_trim(buf, ec + GSS_KRB5_TOK_HDR_LEN + tailskip);
return GSS_S_COMPLETE;
}
u32
gss_wrap_kerberos(struct gss_ctx *gctx, int offset,
struct xdr_buf *buf, struct page **pages)
{
struct krb5_ctx *kctx = gctx->internal_ctx_id;
switch (kctx->enctype) {
default:
BUG();
case ENCTYPE_DES_CBC_RAW:
case ENCTYPE_DES3_CBC_RAW:
case ENCTYPE_ARCFOUR_HMAC:
return gss_wrap_kerberos_v1(kctx, offset, buf, pages);
case ENCTYPE_AES128_CTS_HMAC_SHA1_96:
case ENCTYPE_AES256_CTS_HMAC_SHA1_96:
return gss_wrap_kerberos_v2(kctx, offset, buf, pages);
}
}
u32
gss_unwrap_kerberos(struct gss_ctx *gctx, int offset, struct xdr_buf *buf)
{
struct krb5_ctx *kctx = gctx->internal_ctx_id;
switch (kctx->enctype) {
default:
BUG();
case ENCTYPE_DES_CBC_RAW:
case ENCTYPE_DES3_CBC_RAW:
case ENCTYPE_ARCFOUR_HMAC:
return gss_unwrap_kerberos_v1(kctx, offset, buf);
case ENCTYPE_AES128_CTS_HMAC_SHA1_96:
case ENCTYPE_AES256_CTS_HMAC_SHA1_96:
return gss_unwrap_kerberos_v2(kctx, offset, buf);
}
}
