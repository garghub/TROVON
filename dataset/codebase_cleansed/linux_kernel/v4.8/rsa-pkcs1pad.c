static const struct rsa_asn1_template *rsa_lookup_asn1(const char *name)
{
const struct rsa_asn1_template *p;
for (p = rsa_asn1_templates; p->name; p++)
if (strcmp(name, p->name) == 0)
return p;
return NULL;
}
static int pkcs1pad_set_pub_key(struct crypto_akcipher *tfm, const void *key,
unsigned int keylen)
{
struct pkcs1pad_ctx *ctx = akcipher_tfm_ctx(tfm);
int err;
ctx->key_size = 0;
err = crypto_akcipher_set_pub_key(ctx->child, key, keylen);
if (err)
return err;
err = crypto_akcipher_maxsize(ctx->child);
if (err < 0)
return err;
if (err > PAGE_SIZE)
return -ENOTSUPP;
ctx->key_size = err;
return 0;
}
static int pkcs1pad_set_priv_key(struct crypto_akcipher *tfm, const void *key,
unsigned int keylen)
{
struct pkcs1pad_ctx *ctx = akcipher_tfm_ctx(tfm);
int err;
ctx->key_size = 0;
err = crypto_akcipher_set_priv_key(ctx->child, key, keylen);
if (err)
return err;
err = crypto_akcipher_maxsize(ctx->child);
if (err < 0)
return err;
if (err > PAGE_SIZE)
return -ENOTSUPP;
ctx->key_size = err;
return 0;
}
static int pkcs1pad_get_max_size(struct crypto_akcipher *tfm)
{
struct pkcs1pad_ctx *ctx = akcipher_tfm_ctx(tfm);
return ctx->key_size ?: -EINVAL;
}
static void pkcs1pad_sg_set_buf(struct scatterlist *sg, void *buf, size_t len,
struct scatterlist *next)
{
int nsegs = next ? 2 : 1;
sg_init_table(sg, nsegs);
sg_set_buf(sg, buf, len);
if (next)
sg_chain(sg, nsegs, next);
}
static int pkcs1pad_encrypt_sign_complete(struct akcipher_request *req, int err)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
struct pkcs1pad_ctx *ctx = akcipher_tfm_ctx(tfm);
struct pkcs1pad_request *req_ctx = akcipher_request_ctx(req);
unsigned int pad_len;
unsigned int len;
u8 *out_buf;
if (err)
goto out;
len = req_ctx->child_req.dst_len;
pad_len = ctx->key_size - len;
if (likely(!pad_len))
goto out;
out_buf = kzalloc(ctx->key_size, GFP_ATOMIC);
err = -ENOMEM;
if (!out_buf)
goto out;
sg_copy_to_buffer(req->dst, sg_nents_for_len(req->dst, len),
out_buf + pad_len, len);
sg_copy_from_buffer(req->dst,
sg_nents_for_len(req->dst, ctx->key_size),
out_buf, ctx->key_size);
kzfree(out_buf);
out:
req->dst_len = ctx->key_size;
kfree(req_ctx->in_buf);
return err;
}
static void pkcs1pad_encrypt_sign_complete_cb(
struct crypto_async_request *child_async_req, int err)
{
struct akcipher_request *req = child_async_req->data;
struct crypto_async_request async_req;
if (err == -EINPROGRESS)
return;
async_req.data = req->base.data;
async_req.tfm = crypto_akcipher_tfm(crypto_akcipher_reqtfm(req));
async_req.flags = child_async_req->flags;
req->base.complete(&async_req,
pkcs1pad_encrypt_sign_complete(req, err));
}
static int pkcs1pad_encrypt(struct akcipher_request *req)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
struct pkcs1pad_ctx *ctx = akcipher_tfm_ctx(tfm);
struct pkcs1pad_request *req_ctx = akcipher_request_ctx(req);
int err;
unsigned int i, ps_end;
if (!ctx->key_size)
return -EINVAL;
if (req->src_len > ctx->key_size - 11)
return -EOVERFLOW;
if (req->dst_len < ctx->key_size) {
req->dst_len = ctx->key_size;
return -EOVERFLOW;
}
req_ctx->in_buf = kmalloc(ctx->key_size - 1 - req->src_len,
GFP_KERNEL);
if (!req_ctx->in_buf)
return -ENOMEM;
ps_end = ctx->key_size - req->src_len - 2;
req_ctx->in_buf[0] = 0x02;
for (i = 1; i < ps_end; i++)
req_ctx->in_buf[i] = 1 + prandom_u32_max(255);
req_ctx->in_buf[ps_end] = 0x00;
pkcs1pad_sg_set_buf(req_ctx->in_sg, req_ctx->in_buf,
ctx->key_size - 1 - req->src_len, req->src);
req_ctx->out_buf = kmalloc(ctx->key_size, GFP_KERNEL);
if (!req_ctx->out_buf) {
kfree(req_ctx->in_buf);
return -ENOMEM;
}
pkcs1pad_sg_set_buf(req_ctx->out_sg, req_ctx->out_buf,
ctx->key_size, NULL);
akcipher_request_set_tfm(&req_ctx->child_req, ctx->child);
akcipher_request_set_callback(&req_ctx->child_req, req->base.flags,
pkcs1pad_encrypt_sign_complete_cb, req);
akcipher_request_set_crypt(&req_ctx->child_req, req_ctx->in_sg,
req->dst, ctx->key_size - 1, req->dst_len);
err = crypto_akcipher_encrypt(&req_ctx->child_req);
if (err != -EINPROGRESS &&
(err != -EBUSY ||
!(req->base.flags & CRYPTO_TFM_REQ_MAY_BACKLOG)))
return pkcs1pad_encrypt_sign_complete(req, err);
return err;
}
static int pkcs1pad_decrypt_complete(struct akcipher_request *req, int err)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
struct pkcs1pad_ctx *ctx = akcipher_tfm_ctx(tfm);
struct pkcs1pad_request *req_ctx = akcipher_request_ctx(req);
unsigned int dst_len;
unsigned int pos;
u8 *out_buf;
if (err)
goto done;
err = -EINVAL;
dst_len = req_ctx->child_req.dst_len;
if (dst_len < ctx->key_size - 1)
goto done;
out_buf = req_ctx->out_buf;
if (dst_len == ctx->key_size) {
if (out_buf[0] != 0x00)
goto done;
dst_len--;
out_buf++;
}
if (out_buf[0] != 0x02)
goto done;
for (pos = 1; pos < dst_len; pos++)
if (out_buf[pos] == 0x00)
break;
if (pos < 9 || pos == dst_len)
goto done;
pos++;
err = 0;
if (req->dst_len < dst_len - pos)
err = -EOVERFLOW;
req->dst_len = dst_len - pos;
if (!err)
sg_copy_from_buffer(req->dst,
sg_nents_for_len(req->dst, req->dst_len),
out_buf + pos, req->dst_len);
done:
kzfree(req_ctx->out_buf);
return err;
}
static void pkcs1pad_decrypt_complete_cb(
struct crypto_async_request *child_async_req, int err)
{
struct akcipher_request *req = child_async_req->data;
struct crypto_async_request async_req;
if (err == -EINPROGRESS)
return;
async_req.data = req->base.data;
async_req.tfm = crypto_akcipher_tfm(crypto_akcipher_reqtfm(req));
async_req.flags = child_async_req->flags;
req->base.complete(&async_req, pkcs1pad_decrypt_complete(req, err));
}
static int pkcs1pad_decrypt(struct akcipher_request *req)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
struct pkcs1pad_ctx *ctx = akcipher_tfm_ctx(tfm);
struct pkcs1pad_request *req_ctx = akcipher_request_ctx(req);
int err;
if (!ctx->key_size || req->src_len != ctx->key_size)
return -EINVAL;
req_ctx->out_buf = kmalloc(ctx->key_size, GFP_KERNEL);
if (!req_ctx->out_buf)
return -ENOMEM;
pkcs1pad_sg_set_buf(req_ctx->out_sg, req_ctx->out_buf,
ctx->key_size, NULL);
akcipher_request_set_tfm(&req_ctx->child_req, ctx->child);
akcipher_request_set_callback(&req_ctx->child_req, req->base.flags,
pkcs1pad_decrypt_complete_cb, req);
akcipher_request_set_crypt(&req_ctx->child_req, req->src,
req_ctx->out_sg, req->src_len,
ctx->key_size);
err = crypto_akcipher_decrypt(&req_ctx->child_req);
if (err != -EINPROGRESS &&
(err != -EBUSY ||
!(req->base.flags & CRYPTO_TFM_REQ_MAY_BACKLOG)))
return pkcs1pad_decrypt_complete(req, err);
return err;
}
static int pkcs1pad_sign(struct akcipher_request *req)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
struct pkcs1pad_ctx *ctx = akcipher_tfm_ctx(tfm);
struct pkcs1pad_request *req_ctx = akcipher_request_ctx(req);
struct akcipher_instance *inst = akcipher_alg_instance(tfm);
struct pkcs1pad_inst_ctx *ictx = akcipher_instance_ctx(inst);
const struct rsa_asn1_template *digest_info = ictx->digest_info;
int err;
unsigned int ps_end, digest_size = 0;
if (!ctx->key_size)
return -EINVAL;
digest_size = digest_info->size;
if (req->src_len + digest_size > ctx->key_size - 11)
return -EOVERFLOW;
if (req->dst_len < ctx->key_size) {
req->dst_len = ctx->key_size;
return -EOVERFLOW;
}
req_ctx->in_buf = kmalloc(ctx->key_size - 1 - req->src_len,
GFP_KERNEL);
if (!req_ctx->in_buf)
return -ENOMEM;
ps_end = ctx->key_size - digest_size - req->src_len - 2;
req_ctx->in_buf[0] = 0x01;
memset(req_ctx->in_buf + 1, 0xff, ps_end - 1);
req_ctx->in_buf[ps_end] = 0x00;
memcpy(req_ctx->in_buf + ps_end + 1, digest_info->data,
digest_info->size);
pkcs1pad_sg_set_buf(req_ctx->in_sg, req_ctx->in_buf,
ctx->key_size - 1 - req->src_len, req->src);
akcipher_request_set_tfm(&req_ctx->child_req, ctx->child);
akcipher_request_set_callback(&req_ctx->child_req, req->base.flags,
pkcs1pad_encrypt_sign_complete_cb, req);
akcipher_request_set_crypt(&req_ctx->child_req, req_ctx->in_sg,
req->dst, ctx->key_size - 1, req->dst_len);
err = crypto_akcipher_sign(&req_ctx->child_req);
if (err != -EINPROGRESS &&
(err != -EBUSY ||
!(req->base.flags & CRYPTO_TFM_REQ_MAY_BACKLOG)))
return pkcs1pad_encrypt_sign_complete(req, err);
return err;
}
static int pkcs1pad_verify_complete(struct akcipher_request *req, int err)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
struct pkcs1pad_ctx *ctx = akcipher_tfm_ctx(tfm);
struct pkcs1pad_request *req_ctx = akcipher_request_ctx(req);
struct akcipher_instance *inst = akcipher_alg_instance(tfm);
struct pkcs1pad_inst_ctx *ictx = akcipher_instance_ctx(inst);
const struct rsa_asn1_template *digest_info = ictx->digest_info;
unsigned int dst_len;
unsigned int pos;
u8 *out_buf;
if (err)
goto done;
err = -EINVAL;
dst_len = req_ctx->child_req.dst_len;
if (dst_len < ctx->key_size - 1)
goto done;
out_buf = req_ctx->out_buf;
if (dst_len == ctx->key_size) {
if (out_buf[0] != 0x00)
goto done;
dst_len--;
out_buf++;
}
err = -EBADMSG;
if (out_buf[0] != 0x01)
goto done;
for (pos = 1; pos < dst_len; pos++)
if (out_buf[pos] != 0xff)
break;
if (pos < 9 || pos == dst_len || out_buf[pos] != 0x00)
goto done;
pos++;
if (memcmp(out_buf + pos, digest_info->data, digest_info->size))
goto done;
pos += digest_info->size;
err = 0;
if (req->dst_len < dst_len - pos)
err = -EOVERFLOW;
req->dst_len = dst_len - pos;
if (!err)
sg_copy_from_buffer(req->dst,
sg_nents_for_len(req->dst, req->dst_len),
out_buf + pos, req->dst_len);
done:
kzfree(req_ctx->out_buf);
return err;
}
static void pkcs1pad_verify_complete_cb(
struct crypto_async_request *child_async_req, int err)
{
struct akcipher_request *req = child_async_req->data;
struct crypto_async_request async_req;
if (err == -EINPROGRESS)
return;
async_req.data = req->base.data;
async_req.tfm = crypto_akcipher_tfm(crypto_akcipher_reqtfm(req));
async_req.flags = child_async_req->flags;
req->base.complete(&async_req, pkcs1pad_verify_complete(req, err));
}
static int pkcs1pad_verify(struct akcipher_request *req)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
struct pkcs1pad_ctx *ctx = akcipher_tfm_ctx(tfm);
struct pkcs1pad_request *req_ctx = akcipher_request_ctx(req);
int err;
if (!ctx->key_size || req->src_len < ctx->key_size)
return -EINVAL;
req_ctx->out_buf = kmalloc(ctx->key_size, GFP_KERNEL);
if (!req_ctx->out_buf)
return -ENOMEM;
pkcs1pad_sg_set_buf(req_ctx->out_sg, req_ctx->out_buf,
ctx->key_size, NULL);
akcipher_request_set_tfm(&req_ctx->child_req, ctx->child);
akcipher_request_set_callback(&req_ctx->child_req, req->base.flags,
pkcs1pad_verify_complete_cb, req);
akcipher_request_set_crypt(&req_ctx->child_req, req->src,
req_ctx->out_sg, req->src_len,
ctx->key_size);
err = crypto_akcipher_verify(&req_ctx->child_req);
if (err != -EINPROGRESS &&
(err != -EBUSY ||
!(req->base.flags & CRYPTO_TFM_REQ_MAY_BACKLOG)))
return pkcs1pad_verify_complete(req, err);
return err;
}
static int pkcs1pad_init_tfm(struct crypto_akcipher *tfm)
{
struct akcipher_instance *inst = akcipher_alg_instance(tfm);
struct pkcs1pad_inst_ctx *ictx = akcipher_instance_ctx(inst);
struct pkcs1pad_ctx *ctx = akcipher_tfm_ctx(tfm);
struct crypto_akcipher *child_tfm;
child_tfm = crypto_spawn_akcipher(&ictx->spawn);
if (IS_ERR(child_tfm))
return PTR_ERR(child_tfm);
ctx->child = child_tfm;
return 0;
}
static void pkcs1pad_exit_tfm(struct crypto_akcipher *tfm)
{
struct pkcs1pad_ctx *ctx = akcipher_tfm_ctx(tfm);
crypto_free_akcipher(ctx->child);
}
static void pkcs1pad_free(struct akcipher_instance *inst)
{
struct pkcs1pad_inst_ctx *ctx = akcipher_instance_ctx(inst);
struct crypto_akcipher_spawn *spawn = &ctx->spawn;
crypto_drop_akcipher(spawn);
kfree(inst);
}
static int pkcs1pad_create(struct crypto_template *tmpl, struct rtattr **tb)
{
const struct rsa_asn1_template *digest_info;
struct crypto_attr_type *algt;
struct akcipher_instance *inst;
struct pkcs1pad_inst_ctx *ctx;
struct crypto_akcipher_spawn *spawn;
struct akcipher_alg *rsa_alg;
const char *rsa_alg_name;
const char *hash_name;
int err;
algt = crypto_get_attr_type(tb);
if (IS_ERR(algt))
return PTR_ERR(algt);
if ((algt->type ^ CRYPTO_ALG_TYPE_AKCIPHER) & algt->mask)
return -EINVAL;
rsa_alg_name = crypto_attr_alg_name(tb[1]);
if (IS_ERR(rsa_alg_name))
return PTR_ERR(rsa_alg_name);
hash_name = crypto_attr_alg_name(tb[2]);
if (IS_ERR(hash_name))
return PTR_ERR(hash_name);
digest_info = rsa_lookup_asn1(hash_name);
if (!digest_info)
return -EINVAL;
inst = kzalloc(sizeof(*inst) + sizeof(*ctx), GFP_KERNEL);
if (!inst)
return -ENOMEM;
ctx = akcipher_instance_ctx(inst);
spawn = &ctx->spawn;
ctx->digest_info = digest_info;
crypto_set_spawn(&spawn->base, akcipher_crypto_instance(inst));
err = crypto_grab_akcipher(spawn, rsa_alg_name, 0,
crypto_requires_sync(algt->type, algt->mask));
if (err)
goto out_free_inst;
rsa_alg = crypto_spawn_akcipher_alg(spawn);
err = -ENAMETOOLONG;
if (snprintf(inst->alg.base.cra_name, CRYPTO_MAX_ALG_NAME,
"pkcs1pad(%s,%s)", rsa_alg->base.cra_name, hash_name) >=
CRYPTO_MAX_ALG_NAME ||
snprintf(inst->alg.base.cra_driver_name, CRYPTO_MAX_ALG_NAME,
"pkcs1pad(%s,%s)",
rsa_alg->base.cra_driver_name, hash_name) >=
CRYPTO_MAX_ALG_NAME)
goto out_drop_alg;
inst->alg.base.cra_flags = rsa_alg->base.cra_flags & CRYPTO_ALG_ASYNC;
inst->alg.base.cra_priority = rsa_alg->base.cra_priority;
inst->alg.base.cra_ctxsize = sizeof(struct pkcs1pad_ctx);
inst->alg.init = pkcs1pad_init_tfm;
inst->alg.exit = pkcs1pad_exit_tfm;
inst->alg.encrypt = pkcs1pad_encrypt;
inst->alg.decrypt = pkcs1pad_decrypt;
inst->alg.sign = pkcs1pad_sign;
inst->alg.verify = pkcs1pad_verify;
inst->alg.set_pub_key = pkcs1pad_set_pub_key;
inst->alg.set_priv_key = pkcs1pad_set_priv_key;
inst->alg.max_size = pkcs1pad_get_max_size;
inst->alg.reqsize = sizeof(struct pkcs1pad_request) + rsa_alg->reqsize;
inst->free = pkcs1pad_free;
err = akcipher_register_instance(tmpl, inst);
if (err)
goto out_drop_alg;
return 0;
out_drop_alg:
crypto_drop_akcipher(spawn);
out_free_inst:
kfree(inst);
return err;
}
