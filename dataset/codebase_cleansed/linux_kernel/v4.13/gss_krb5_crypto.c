u32
krb5_encrypt(
struct crypto_skcipher *tfm,
void * iv,
void * in,
void * out,
int length)
{
u32 ret = -EINVAL;
struct scatterlist sg[1];
u8 local_iv[GSS_KRB5_MAX_BLOCKSIZE] = {0};
SKCIPHER_REQUEST_ON_STACK(req, tfm);
if (length % crypto_skcipher_blocksize(tfm) != 0)
goto out;
if (crypto_skcipher_ivsize(tfm) > GSS_KRB5_MAX_BLOCKSIZE) {
dprintk("RPC: gss_k5encrypt: tfm iv size too large %d\n",
crypto_skcipher_ivsize(tfm));
goto out;
}
if (iv)
memcpy(local_iv, iv, crypto_skcipher_ivsize(tfm));
memcpy(out, in, length);
sg_init_one(sg, out, length);
skcipher_request_set_tfm(req, tfm);
skcipher_request_set_callback(req, 0, NULL, NULL);
skcipher_request_set_crypt(req, sg, sg, length, local_iv);
ret = crypto_skcipher_encrypt(req);
skcipher_request_zero(req);
out:
dprintk("RPC: krb5_encrypt returns %d\n", ret);
return ret;
}
u32
krb5_decrypt(
struct crypto_skcipher *tfm,
void * iv,
void * in,
void * out,
int length)
{
u32 ret = -EINVAL;
struct scatterlist sg[1];
u8 local_iv[GSS_KRB5_MAX_BLOCKSIZE] = {0};
SKCIPHER_REQUEST_ON_STACK(req, tfm);
if (length % crypto_skcipher_blocksize(tfm) != 0)
goto out;
if (crypto_skcipher_ivsize(tfm) > GSS_KRB5_MAX_BLOCKSIZE) {
dprintk("RPC: gss_k5decrypt: tfm iv size too large %d\n",
crypto_skcipher_ivsize(tfm));
goto out;
}
if (iv)
memcpy(local_iv,iv, crypto_skcipher_ivsize(tfm));
memcpy(out, in, length);
sg_init_one(sg, out, length);
skcipher_request_set_tfm(req, tfm);
skcipher_request_set_callback(req, 0, NULL, NULL);
skcipher_request_set_crypt(req, sg, sg, length, local_iv);
ret = crypto_skcipher_decrypt(req);
skcipher_request_zero(req);
out:
dprintk("RPC: gss_k5decrypt returns %d\n",ret);
return ret;
}
static int
checksummer(struct scatterlist *sg, void *data)
{
struct ahash_request *req = data;
ahash_request_set_crypt(req, sg, NULL, sg->length);
return crypto_ahash_update(req);
}
static int
arcfour_hmac_md5_usage_to_salt(unsigned int usage, u8 salt[4])
{
unsigned int ms_usage;
switch (usage) {
case KG_USAGE_SIGN:
ms_usage = 15;
break;
case KG_USAGE_SEAL:
ms_usage = 13;
break;
default:
return -EINVAL;
}
salt[0] = (ms_usage >> 0) & 0xff;
salt[1] = (ms_usage >> 8) & 0xff;
salt[2] = (ms_usage >> 16) & 0xff;
salt[3] = (ms_usage >> 24) & 0xff;
return 0;
}
static u32
make_checksum_hmac_md5(struct krb5_ctx *kctx, char *header, int hdrlen,
struct xdr_buf *body, int body_offset, u8 *cksumkey,
unsigned int usage, struct xdr_netobj *cksumout)
{
struct scatterlist sg[1];
int err = -1;
u8 *checksumdata;
u8 rc4salt[4];
struct crypto_ahash *md5;
struct crypto_ahash *hmac_md5;
struct ahash_request *req;
if (cksumkey == NULL)
return GSS_S_FAILURE;
if (cksumout->len < kctx->gk5e->cksumlength) {
dprintk("%s: checksum buffer length, %u, too small for %s\n",
__func__, cksumout->len, kctx->gk5e->name);
return GSS_S_FAILURE;
}
if (arcfour_hmac_md5_usage_to_salt(usage, rc4salt)) {
dprintk("%s: invalid usage value %u\n", __func__, usage);
return GSS_S_FAILURE;
}
checksumdata = kmalloc(GSS_KRB5_MAX_CKSUM_LEN, GFP_NOFS);
if (!checksumdata)
return GSS_S_FAILURE;
md5 = crypto_alloc_ahash("md5", 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(md5))
goto out_free_cksum;
hmac_md5 = crypto_alloc_ahash(kctx->gk5e->cksum_name, 0,
CRYPTO_ALG_ASYNC);
if (IS_ERR(hmac_md5))
goto out_free_md5;
req = ahash_request_alloc(md5, GFP_NOFS);
if (!req)
goto out_free_hmac_md5;
ahash_request_set_callback(req, CRYPTO_TFM_REQ_MAY_SLEEP, NULL, NULL);
err = crypto_ahash_init(req);
if (err)
goto out;
sg_init_one(sg, rc4salt, 4);
ahash_request_set_crypt(req, sg, NULL, 4);
err = crypto_ahash_update(req);
if (err)
goto out;
sg_init_one(sg, header, hdrlen);
ahash_request_set_crypt(req, sg, NULL, hdrlen);
err = crypto_ahash_update(req);
if (err)
goto out;
err = xdr_process_buf(body, body_offset, body->len - body_offset,
checksummer, req);
if (err)
goto out;
ahash_request_set_crypt(req, NULL, checksumdata, 0);
err = crypto_ahash_final(req);
if (err)
goto out;
ahash_request_free(req);
req = ahash_request_alloc(hmac_md5, GFP_NOFS);
if (!req)
goto out_free_hmac_md5;
ahash_request_set_callback(req, CRYPTO_TFM_REQ_MAY_SLEEP, NULL, NULL);
err = crypto_ahash_init(req);
if (err)
goto out;
err = crypto_ahash_setkey(hmac_md5, cksumkey, kctx->gk5e->keylength);
if (err)
goto out;
sg_init_one(sg, checksumdata, crypto_ahash_digestsize(md5));
ahash_request_set_crypt(req, sg, checksumdata,
crypto_ahash_digestsize(md5));
err = crypto_ahash_digest(req);
if (err)
goto out;
memcpy(cksumout->data, checksumdata, kctx->gk5e->cksumlength);
cksumout->len = kctx->gk5e->cksumlength;
out:
ahash_request_free(req);
out_free_hmac_md5:
crypto_free_ahash(hmac_md5);
out_free_md5:
crypto_free_ahash(md5);
out_free_cksum:
kfree(checksumdata);
return err ? GSS_S_FAILURE : 0;
}
u32
make_checksum(struct krb5_ctx *kctx, char *header, int hdrlen,
struct xdr_buf *body, int body_offset, u8 *cksumkey,
unsigned int usage, struct xdr_netobj *cksumout)
{
struct crypto_ahash *tfm;
struct ahash_request *req;
struct scatterlist sg[1];
int err = -1;
u8 *checksumdata;
unsigned int checksumlen;
if (kctx->gk5e->ctype == CKSUMTYPE_HMAC_MD5_ARCFOUR)
return make_checksum_hmac_md5(kctx, header, hdrlen,
body, body_offset,
cksumkey, usage, cksumout);
if (cksumout->len < kctx->gk5e->cksumlength) {
dprintk("%s: checksum buffer length, %u, too small for %s\n",
__func__, cksumout->len, kctx->gk5e->name);
return GSS_S_FAILURE;
}
checksumdata = kmalloc(GSS_KRB5_MAX_CKSUM_LEN, GFP_NOFS);
if (checksumdata == NULL)
return GSS_S_FAILURE;
tfm = crypto_alloc_ahash(kctx->gk5e->cksum_name, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(tfm))
goto out_free_cksum;
req = ahash_request_alloc(tfm, GFP_NOFS);
if (!req)
goto out_free_ahash;
ahash_request_set_callback(req, CRYPTO_TFM_REQ_MAY_SLEEP, NULL, NULL);
checksumlen = crypto_ahash_digestsize(tfm);
if (cksumkey != NULL) {
err = crypto_ahash_setkey(tfm, cksumkey,
kctx->gk5e->keylength);
if (err)
goto out;
}
err = crypto_ahash_init(req);
if (err)
goto out;
sg_init_one(sg, header, hdrlen);
ahash_request_set_crypt(req, sg, NULL, hdrlen);
err = crypto_ahash_update(req);
if (err)
goto out;
err = xdr_process_buf(body, body_offset, body->len - body_offset,
checksummer, req);
if (err)
goto out;
ahash_request_set_crypt(req, NULL, checksumdata, 0);
err = crypto_ahash_final(req);
if (err)
goto out;
switch (kctx->gk5e->ctype) {
case CKSUMTYPE_RSA_MD5:
err = kctx->gk5e->encrypt(kctx->seq, NULL, checksumdata,
checksumdata, checksumlen);
if (err)
goto out;
memcpy(cksumout->data,
checksumdata + checksumlen - kctx->gk5e->cksumlength,
kctx->gk5e->cksumlength);
break;
case CKSUMTYPE_HMAC_SHA1_DES3:
memcpy(cksumout->data, checksumdata, kctx->gk5e->cksumlength);
break;
default:
BUG();
break;
}
cksumout->len = kctx->gk5e->cksumlength;
out:
ahash_request_free(req);
out_free_ahash:
crypto_free_ahash(tfm);
out_free_cksum:
kfree(checksumdata);
return err ? GSS_S_FAILURE : 0;
}
u32
make_checksum_v2(struct krb5_ctx *kctx, char *header, int hdrlen,
struct xdr_buf *body, int body_offset, u8 *cksumkey,
unsigned int usage, struct xdr_netobj *cksumout)
{
struct crypto_ahash *tfm;
struct ahash_request *req;
struct scatterlist sg[1];
int err = -1;
u8 *checksumdata;
unsigned int checksumlen;
if (kctx->gk5e->keyed_cksum == 0) {
dprintk("%s: expected keyed hash for %s\n",
__func__, kctx->gk5e->name);
return GSS_S_FAILURE;
}
if (cksumkey == NULL) {
dprintk("%s: no key supplied for %s\n",
__func__, kctx->gk5e->name);
return GSS_S_FAILURE;
}
checksumdata = kmalloc(GSS_KRB5_MAX_CKSUM_LEN, GFP_NOFS);
if (!checksumdata)
return GSS_S_FAILURE;
tfm = crypto_alloc_ahash(kctx->gk5e->cksum_name, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(tfm))
goto out_free_cksum;
checksumlen = crypto_ahash_digestsize(tfm);
req = ahash_request_alloc(tfm, GFP_NOFS);
if (!req)
goto out_free_ahash;
ahash_request_set_callback(req, CRYPTO_TFM_REQ_MAY_SLEEP, NULL, NULL);
err = crypto_ahash_setkey(tfm, cksumkey, kctx->gk5e->keylength);
if (err)
goto out;
err = crypto_ahash_init(req);
if (err)
goto out;
err = xdr_process_buf(body, body_offset, body->len - body_offset,
checksummer, req);
if (err)
goto out;
if (header != NULL) {
sg_init_one(sg, header, hdrlen);
ahash_request_set_crypt(req, sg, NULL, hdrlen);
err = crypto_ahash_update(req);
if (err)
goto out;
}
ahash_request_set_crypt(req, NULL, checksumdata, 0);
err = crypto_ahash_final(req);
if (err)
goto out;
cksumout->len = kctx->gk5e->cksumlength;
switch (kctx->gk5e->ctype) {
case CKSUMTYPE_HMAC_SHA1_96_AES128:
case CKSUMTYPE_HMAC_SHA1_96_AES256:
memcpy(cksumout->data, checksumdata, kctx->gk5e->cksumlength);
break;
default:
BUG();
break;
}
out:
ahash_request_free(req);
out_free_ahash:
crypto_free_ahash(tfm);
out_free_cksum:
kfree(checksumdata);
return err ? GSS_S_FAILURE : 0;
}
static int
encryptor(struct scatterlist *sg, void *data)
{
struct encryptor_desc *desc = data;
struct xdr_buf *outbuf = desc->outbuf;
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(desc->req);
struct page *in_page;
int thislen = desc->fraglen + sg->length;
int fraglen, ret;
int page_pos;
BUG_ON(desc->fragno > 3);
page_pos = desc->pos - outbuf->head[0].iov_len;
if (page_pos >= 0 && page_pos < outbuf->page_len) {
int i = (page_pos + outbuf->page_base) >> PAGE_SHIFT;
in_page = desc->pages[i];
} else {
in_page = sg_page(sg);
}
sg_set_page(&desc->infrags[desc->fragno], in_page, sg->length,
sg->offset);
sg_set_page(&desc->outfrags[desc->fragno], sg_page(sg), sg->length,
sg->offset);
desc->fragno++;
desc->fraglen += sg->length;
desc->pos += sg->length;
fraglen = thislen & (crypto_skcipher_blocksize(tfm) - 1);
thislen -= fraglen;
if (thislen == 0)
return 0;
sg_mark_end(&desc->infrags[desc->fragno - 1]);
sg_mark_end(&desc->outfrags[desc->fragno - 1]);
skcipher_request_set_crypt(desc->req, desc->infrags, desc->outfrags,
thislen, desc->iv);
ret = crypto_skcipher_encrypt(desc->req);
if (ret)
return ret;
sg_init_table(desc->infrags, 4);
sg_init_table(desc->outfrags, 4);
if (fraglen) {
sg_set_page(&desc->outfrags[0], sg_page(sg), fraglen,
sg->offset + sg->length - fraglen);
desc->infrags[0] = desc->outfrags[0];
sg_assign_page(&desc->infrags[0], in_page);
desc->fragno = 1;
desc->fraglen = fraglen;
} else {
desc->fragno = 0;
desc->fraglen = 0;
}
return 0;
}
int
gss_encrypt_xdr_buf(struct crypto_skcipher *tfm, struct xdr_buf *buf,
int offset, struct page **pages)
{
int ret;
struct encryptor_desc desc;
SKCIPHER_REQUEST_ON_STACK(req, tfm);
BUG_ON((buf->len - offset) % crypto_skcipher_blocksize(tfm) != 0);
skcipher_request_set_tfm(req, tfm);
skcipher_request_set_callback(req, 0, NULL, NULL);
memset(desc.iv, 0, sizeof(desc.iv));
desc.req = req;
desc.pos = offset;
desc.outbuf = buf;
desc.pages = pages;
desc.fragno = 0;
desc.fraglen = 0;
sg_init_table(desc.infrags, 4);
sg_init_table(desc.outfrags, 4);
ret = xdr_process_buf(buf, offset, buf->len - offset, encryptor, &desc);
skcipher_request_zero(req);
return ret;
}
static int
decryptor(struct scatterlist *sg, void *data)
{
struct decryptor_desc *desc = data;
int thislen = desc->fraglen + sg->length;
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(desc->req);
int fraglen, ret;
BUG_ON(desc->fragno > 3);
sg_set_page(&desc->frags[desc->fragno], sg_page(sg), sg->length,
sg->offset);
desc->fragno++;
desc->fraglen += sg->length;
fraglen = thislen & (crypto_skcipher_blocksize(tfm) - 1);
thislen -= fraglen;
if (thislen == 0)
return 0;
sg_mark_end(&desc->frags[desc->fragno - 1]);
skcipher_request_set_crypt(desc->req, desc->frags, desc->frags,
thislen, desc->iv);
ret = crypto_skcipher_decrypt(desc->req);
if (ret)
return ret;
sg_init_table(desc->frags, 4);
if (fraglen) {
sg_set_page(&desc->frags[0], sg_page(sg), fraglen,
sg->offset + sg->length - fraglen);
desc->fragno = 1;
desc->fraglen = fraglen;
} else {
desc->fragno = 0;
desc->fraglen = 0;
}
return 0;
}
int
gss_decrypt_xdr_buf(struct crypto_skcipher *tfm, struct xdr_buf *buf,
int offset)
{
int ret;
struct decryptor_desc desc;
SKCIPHER_REQUEST_ON_STACK(req, tfm);
BUG_ON((buf->len - offset) % crypto_skcipher_blocksize(tfm) != 0);
skcipher_request_set_tfm(req, tfm);
skcipher_request_set_callback(req, 0, NULL, NULL);
memset(desc.iv, 0, sizeof(desc.iv));
desc.req = req;
desc.fragno = 0;
desc.fraglen = 0;
sg_init_table(desc.frags, 4);
ret = xdr_process_buf(buf, offset, buf->len - offset, decryptor, &desc);
skcipher_request_zero(req);
return ret;
}
int
xdr_extend_head(struct xdr_buf *buf, unsigned int base, unsigned int shiftlen)
{
u8 *p;
if (shiftlen == 0)
return 0;
BUILD_BUG_ON(GSS_KRB5_MAX_SLACK_NEEDED > RPC_MAX_AUTH_SIZE);
BUG_ON(shiftlen > RPC_MAX_AUTH_SIZE);
p = buf->head[0].iov_base + base;
memmove(p + shiftlen, p, buf->head[0].iov_len - base);
buf->head[0].iov_len += shiftlen;
buf->len += shiftlen;
return 0;
}
static u32
gss_krb5_cts_crypt(struct crypto_skcipher *cipher, struct xdr_buf *buf,
u32 offset, u8 *iv, struct page **pages, int encrypt)
{
u32 ret;
struct scatterlist sg[1];
SKCIPHER_REQUEST_ON_STACK(req, cipher);
u8 *data;
struct page **save_pages;
u32 len = buf->len - offset;
if (len > GSS_KRB5_MAX_BLOCKSIZE * 2) {
WARN_ON(0);
return -ENOMEM;
}
data = kmalloc(GSS_KRB5_MAX_BLOCKSIZE * 2, GFP_NOFS);
if (!data)
return -ENOMEM;
save_pages = buf->pages;
if (encrypt)
buf->pages = pages;
ret = read_bytes_from_xdr_buf(buf, offset, data, len);
buf->pages = save_pages;
if (ret)
goto out;
sg_init_one(sg, data, len);
skcipher_request_set_tfm(req, cipher);
skcipher_request_set_callback(req, 0, NULL, NULL);
skcipher_request_set_crypt(req, sg, sg, len, iv);
if (encrypt)
ret = crypto_skcipher_encrypt(req);
else
ret = crypto_skcipher_decrypt(req);
skcipher_request_zero(req);
if (ret)
goto out;
ret = write_bytes_to_xdr_buf(buf, offset, data, len);
out:
kfree(data);
return ret;
}
u32
gss_krb5_aes_encrypt(struct krb5_ctx *kctx, u32 offset,
struct xdr_buf *buf, struct page **pages)
{
u32 err;
struct xdr_netobj hmac;
u8 *cksumkey;
u8 *ecptr;
struct crypto_skcipher *cipher, *aux_cipher;
int blocksize;
struct page **save_pages;
int nblocks, nbytes;
struct encryptor_desc desc;
u32 cbcbytes;
unsigned int usage;
if (kctx->initiate) {
cipher = kctx->initiator_enc;
aux_cipher = kctx->initiator_enc_aux;
cksumkey = kctx->initiator_integ;
usage = KG_USAGE_INITIATOR_SEAL;
} else {
cipher = kctx->acceptor_enc;
aux_cipher = kctx->acceptor_enc_aux;
cksumkey = kctx->acceptor_integ;
usage = KG_USAGE_ACCEPTOR_SEAL;
}
blocksize = crypto_skcipher_blocksize(cipher);
offset += GSS_KRB5_TOK_HDR_LEN;
if (xdr_extend_head(buf, offset, kctx->gk5e->conflen))
return GSS_S_FAILURE;
gss_krb5_make_confounder(buf->head[0].iov_base + offset, kctx->gk5e->conflen);
offset -= GSS_KRB5_TOK_HDR_LEN;
if (buf->tail[0].iov_base != NULL) {
ecptr = buf->tail[0].iov_base + buf->tail[0].iov_len;
} else {
buf->tail[0].iov_base = buf->head[0].iov_base
+ buf->head[0].iov_len;
buf->tail[0].iov_len = 0;
ecptr = buf->tail[0].iov_base;
}
memcpy(ecptr, buf->head[0].iov_base + offset, GSS_KRB5_TOK_HDR_LEN);
buf->tail[0].iov_len += GSS_KRB5_TOK_HDR_LEN;
buf->len += GSS_KRB5_TOK_HDR_LEN;
hmac.len = GSS_KRB5_MAX_CKSUM_LEN;
hmac.data = buf->tail[0].iov_base + buf->tail[0].iov_len;
save_pages = buf->pages;
buf->pages = pages;
err = make_checksum_v2(kctx, NULL, 0, buf,
offset + GSS_KRB5_TOK_HDR_LEN,
cksumkey, usage, &hmac);
buf->pages = save_pages;
if (err)
return GSS_S_FAILURE;
nbytes = buf->len - offset - GSS_KRB5_TOK_HDR_LEN;
nblocks = (nbytes + blocksize - 1) / blocksize;
cbcbytes = 0;
if (nblocks > 2)
cbcbytes = (nblocks - 2) * blocksize;
memset(desc.iv, 0, sizeof(desc.iv));
if (cbcbytes) {
SKCIPHER_REQUEST_ON_STACK(req, aux_cipher);
desc.pos = offset + GSS_KRB5_TOK_HDR_LEN;
desc.fragno = 0;
desc.fraglen = 0;
desc.pages = pages;
desc.outbuf = buf;
desc.req = req;
skcipher_request_set_tfm(req, aux_cipher);
skcipher_request_set_callback(req, 0, NULL, NULL);
sg_init_table(desc.infrags, 4);
sg_init_table(desc.outfrags, 4);
err = xdr_process_buf(buf, offset + GSS_KRB5_TOK_HDR_LEN,
cbcbytes, encryptor, &desc);
skcipher_request_zero(req);
if (err)
goto out_err;
}
err = gss_krb5_cts_crypt(cipher, buf,
offset + GSS_KRB5_TOK_HDR_LEN + cbcbytes,
desc.iv, pages, 1);
if (err) {
err = GSS_S_FAILURE;
goto out_err;
}
buf->tail[0].iov_len += kctx->gk5e->cksumlength;
buf->len += kctx->gk5e->cksumlength;
out_err:
if (err)
err = GSS_S_FAILURE;
return err;
}
u32
gss_krb5_aes_decrypt(struct krb5_ctx *kctx, u32 offset, struct xdr_buf *buf,
u32 *headskip, u32 *tailskip)
{
struct xdr_buf subbuf;
u32 ret = 0;
u8 *cksum_key;
struct crypto_skcipher *cipher, *aux_cipher;
struct xdr_netobj our_hmac_obj;
u8 our_hmac[GSS_KRB5_MAX_CKSUM_LEN];
u8 pkt_hmac[GSS_KRB5_MAX_CKSUM_LEN];
int nblocks, blocksize, cbcbytes;
struct decryptor_desc desc;
unsigned int usage;
if (kctx->initiate) {
cipher = kctx->acceptor_enc;
aux_cipher = kctx->acceptor_enc_aux;
cksum_key = kctx->acceptor_integ;
usage = KG_USAGE_ACCEPTOR_SEAL;
} else {
cipher = kctx->initiator_enc;
aux_cipher = kctx->initiator_enc_aux;
cksum_key = kctx->initiator_integ;
usage = KG_USAGE_INITIATOR_SEAL;
}
blocksize = crypto_skcipher_blocksize(cipher);
xdr_buf_subsegment(buf, &subbuf, offset + GSS_KRB5_TOK_HDR_LEN,
(buf->len - offset - GSS_KRB5_TOK_HDR_LEN -
kctx->gk5e->cksumlength));
nblocks = (subbuf.len + blocksize - 1) / blocksize;
cbcbytes = 0;
if (nblocks > 2)
cbcbytes = (nblocks - 2) * blocksize;
memset(desc.iv, 0, sizeof(desc.iv));
if (cbcbytes) {
SKCIPHER_REQUEST_ON_STACK(req, aux_cipher);
desc.fragno = 0;
desc.fraglen = 0;
desc.req = req;
skcipher_request_set_tfm(req, aux_cipher);
skcipher_request_set_callback(req, 0, NULL, NULL);
sg_init_table(desc.frags, 4);
ret = xdr_process_buf(&subbuf, 0, cbcbytes, decryptor, &desc);
skcipher_request_zero(req);
if (ret)
goto out_err;
}
ret = gss_krb5_cts_crypt(cipher, &subbuf, cbcbytes, desc.iv, NULL, 0);
if (ret)
goto out_err;
our_hmac_obj.len = sizeof(our_hmac);
our_hmac_obj.data = our_hmac;
ret = make_checksum_v2(kctx, NULL, 0, &subbuf, 0,
cksum_key, usage, &our_hmac_obj);
if (ret)
goto out_err;
ret = read_bytes_from_xdr_buf(buf, buf->len - kctx->gk5e->cksumlength,
pkt_hmac, kctx->gk5e->cksumlength);
if (ret)
goto out_err;
if (crypto_memneq(pkt_hmac, our_hmac, kctx->gk5e->cksumlength) != 0) {
ret = GSS_S_BAD_SIG;
goto out_err;
}
*headskip = kctx->gk5e->conflen;
*tailskip = kctx->gk5e->cksumlength;
out_err:
if (ret && ret != GSS_S_BAD_SIG)
ret = GSS_S_FAILURE;
return ret;
}
int
krb5_rc4_setup_seq_key(struct krb5_ctx *kctx, struct crypto_skcipher *cipher,
unsigned char *cksum)
{
struct crypto_shash *hmac;
struct shash_desc *desc;
u8 Kseq[GSS_KRB5_MAX_KEYLEN];
u32 zeroconstant = 0;
int err;
dprintk("%s: entered\n", __func__);
hmac = crypto_alloc_shash(kctx->gk5e->cksum_name, 0, 0);
if (IS_ERR(hmac)) {
dprintk("%s: error %ld, allocating hash '%s'\n",
__func__, PTR_ERR(hmac), kctx->gk5e->cksum_name);
return PTR_ERR(hmac);
}
desc = kmalloc(sizeof(*desc) + crypto_shash_descsize(hmac),
GFP_NOFS);
if (!desc) {
dprintk("%s: failed to allocate shash descriptor for '%s'\n",
__func__, kctx->gk5e->cksum_name);
crypto_free_shash(hmac);
return -ENOMEM;
}
desc->tfm = hmac;
desc->flags = 0;
err = crypto_shash_setkey(hmac, kctx->Ksess, kctx->gk5e->keylength);
if (err)
goto out_err;
err = crypto_shash_digest(desc, (u8 *)&zeroconstant, 4, Kseq);
if (err)
goto out_err;
err = crypto_shash_setkey(hmac, Kseq, kctx->gk5e->keylength);
if (err)
goto out_err;
err = crypto_shash_digest(desc, cksum, 8, Kseq);
if (err)
goto out_err;
err = crypto_skcipher_setkey(cipher, Kseq, kctx->gk5e->keylength);
if (err)
goto out_err;
err = 0;
out_err:
kzfree(desc);
crypto_free_shash(hmac);
dprintk("%s: returning %d\n", __func__, err);
return err;
}
int
krb5_rc4_setup_enc_key(struct krb5_ctx *kctx, struct crypto_skcipher *cipher,
s32 seqnum)
{
struct crypto_shash *hmac;
struct shash_desc *desc;
u8 Kcrypt[GSS_KRB5_MAX_KEYLEN];
u8 zeroconstant[4] = {0};
u8 seqnumarray[4];
int err, i;
dprintk("%s: entered, seqnum %u\n", __func__, seqnum);
hmac = crypto_alloc_shash(kctx->gk5e->cksum_name, 0, 0);
if (IS_ERR(hmac)) {
dprintk("%s: error %ld, allocating hash '%s'\n",
__func__, PTR_ERR(hmac), kctx->gk5e->cksum_name);
return PTR_ERR(hmac);
}
desc = kmalloc(sizeof(*desc) + crypto_shash_descsize(hmac),
GFP_NOFS);
if (!desc) {
dprintk("%s: failed to allocate shash descriptor for '%s'\n",
__func__, kctx->gk5e->cksum_name);
crypto_free_shash(hmac);
return -ENOMEM;
}
desc->tfm = hmac;
desc->flags = 0;
for (i = 0; i < kctx->gk5e->keylength; i++)
Kcrypt[i] = kctx->Ksess[i] ^ 0xf0;
err = crypto_shash_setkey(hmac, Kcrypt, kctx->gk5e->keylength);
if (err)
goto out_err;
err = crypto_shash_digest(desc, zeroconstant, 4, Kcrypt);
if (err)
goto out_err;
err = crypto_shash_setkey(hmac, Kcrypt, kctx->gk5e->keylength);
if (err)
goto out_err;
seqnumarray[0] = (unsigned char) ((seqnum >> 24) & 0xff);
seqnumarray[1] = (unsigned char) ((seqnum >> 16) & 0xff);
seqnumarray[2] = (unsigned char) ((seqnum >> 8) & 0xff);
seqnumarray[3] = (unsigned char) ((seqnum >> 0) & 0xff);
err = crypto_shash_digest(desc, seqnumarray, 4, Kcrypt);
if (err)
goto out_err;
err = crypto_skcipher_setkey(cipher, Kcrypt, kctx->gk5e->keylength);
if (err)
goto out_err;
err = 0;
out_err:
kzfree(desc);
crypto_free_shash(hmac);
dprintk("%s: returning %d\n", __func__, err);
return err;
}
