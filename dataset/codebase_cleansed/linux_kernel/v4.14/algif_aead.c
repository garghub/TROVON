static inline bool aead_sufficient_data(struct sock *sk)
{
struct alg_sock *ask = alg_sk(sk);
struct sock *psk = ask->parent;
struct alg_sock *pask = alg_sk(psk);
struct af_alg_ctx *ctx = ask->private;
struct aead_tfm *aeadc = pask->private;
struct crypto_aead *tfm = aeadc->aead;
unsigned int as = crypto_aead_authsize(tfm);
return ctx->used >= ctx->aead_assoclen + (ctx->enc ? 0 : as);
}
static int aead_sendmsg(struct socket *sock, struct msghdr *msg, size_t size)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct sock *psk = ask->parent;
struct alg_sock *pask = alg_sk(psk);
struct aead_tfm *aeadc = pask->private;
struct crypto_aead *tfm = aeadc->aead;
unsigned int ivsize = crypto_aead_ivsize(tfm);
return af_alg_sendmsg(sock, msg, size, ivsize);
}
static int crypto_aead_copy_sgl(struct crypto_skcipher *null_tfm,
struct scatterlist *src,
struct scatterlist *dst, unsigned int len)
{
SKCIPHER_REQUEST_ON_STACK(skreq, null_tfm);
skcipher_request_set_tfm(skreq, null_tfm);
skcipher_request_set_callback(skreq, CRYPTO_TFM_REQ_MAY_BACKLOG,
NULL, NULL);
skcipher_request_set_crypt(skreq, src, dst, len, NULL);
return crypto_skcipher_encrypt(skreq);
}
static int _aead_recvmsg(struct socket *sock, struct msghdr *msg,
size_t ignored, int flags)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct sock *psk = ask->parent;
struct alg_sock *pask = alg_sk(psk);
struct af_alg_ctx *ctx = ask->private;
struct aead_tfm *aeadc = pask->private;
struct crypto_aead *tfm = aeadc->aead;
struct crypto_skcipher *null_tfm = aeadc->null_tfm;
unsigned int as = crypto_aead_authsize(tfm);
struct af_alg_async_req *areq;
struct af_alg_tsgl *tsgl;
struct scatterlist *src;
int err = 0;
size_t used = 0;
size_t outlen = 0;
size_t usedpages = 0;
size_t processed = 0;
used = ctx->used;
if (!aead_sufficient_data(sk))
return -EINVAL;
if (ctx->enc)
outlen = used + as;
else
outlen = used - as;
used -= ctx->aead_assoclen;
areq = af_alg_alloc_areq(sk, sizeof(struct af_alg_async_req) +
crypto_aead_reqsize(tfm));
if (IS_ERR(areq))
return PTR_ERR(areq);
err = af_alg_get_rsgl(sk, msg, flags, areq, outlen, &usedpages);
if (err)
goto free;
if (usedpages < outlen) {
size_t less = outlen - usedpages;
if (used < less) {
err = -EINVAL;
goto free;
}
used -= less;
outlen -= less;
}
processed = used + ctx->aead_assoclen;
tsgl = list_first_entry(&ctx->tsgl_list, struct af_alg_tsgl, list);
src = areq->first_rsgl.sgl.sg;
if (ctx->enc) {
err = crypto_aead_copy_sgl(null_tfm, tsgl->sg,
areq->first_rsgl.sgl.sg, processed);
if (err)
goto free;
af_alg_pull_tsgl(sk, processed, NULL, 0);
} else {
err = crypto_aead_copy_sgl(null_tfm, tsgl->sg,
areq->first_rsgl.sgl.sg, outlen);
if (err)
goto free;
areq->tsgl_entries = af_alg_count_tsgl(sk, processed,
processed - as);
if (!areq->tsgl_entries)
areq->tsgl_entries = 1;
areq->tsgl = sock_kmalloc(sk, sizeof(*areq->tsgl) *
areq->tsgl_entries,
GFP_KERNEL);
if (!areq->tsgl) {
err = -ENOMEM;
goto free;
}
sg_init_table(areq->tsgl, areq->tsgl_entries);
af_alg_pull_tsgl(sk, processed, areq->tsgl, processed - as);
if (usedpages) {
struct af_alg_sgl *sgl_prev = &areq->last_rsgl->sgl;
sg_unmark_end(sgl_prev->sg + sgl_prev->npages - 1);
sg_chain(sgl_prev->sg, sgl_prev->npages + 1,
areq->tsgl);
} else
src = areq->tsgl;
}
aead_request_set_crypt(&areq->cra_u.aead_req, src,
areq->first_rsgl.sgl.sg, used, ctx->iv);
aead_request_set_ad(&areq->cra_u.aead_req, ctx->aead_assoclen);
aead_request_set_tfm(&areq->cra_u.aead_req, tfm);
if (msg->msg_iocb && !is_sync_kiocb(msg->msg_iocb)) {
areq->iocb = msg->msg_iocb;
aead_request_set_callback(&areq->cra_u.aead_req,
CRYPTO_TFM_REQ_MAY_BACKLOG,
af_alg_async_cb, areq);
err = ctx->enc ? crypto_aead_encrypt(&areq->cra_u.aead_req) :
crypto_aead_decrypt(&areq->cra_u.aead_req);
} else {
aead_request_set_callback(&areq->cra_u.aead_req,
CRYPTO_TFM_REQ_MAY_BACKLOG,
af_alg_complete, &ctx->completion);
err = af_alg_wait_for_completion(ctx->enc ?
crypto_aead_encrypt(&areq->cra_u.aead_req) :
crypto_aead_decrypt(&areq->cra_u.aead_req),
&ctx->completion);
}
if (err == -EINPROGRESS) {
sock_hold(sk);
areq->outlen = outlen;
return -EIOCBQUEUED;
}
free:
af_alg_free_areq_sgls(areq);
sock_kfree_s(sk, areq, areq->areqlen);
return err ? err : outlen;
}
static int aead_recvmsg(struct socket *sock, struct msghdr *msg,
size_t ignored, int flags)
{
struct sock *sk = sock->sk;
int ret = 0;
lock_sock(sk);
while (msg_data_left(msg)) {
int err = _aead_recvmsg(sock, msg, ignored, flags);
if (err <= 0) {
if (err == -EIOCBQUEUED || err == -EBADMSG || !ret)
ret = err;
goto out;
}
ret += err;
}
out:
af_alg_wmem_wakeup(sk);
release_sock(sk);
return ret;
}
static int aead_check_key(struct socket *sock)
{
int err = 0;
struct sock *psk;
struct alg_sock *pask;
struct aead_tfm *tfm;
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
lock_sock(sk);
if (ask->refcnt)
goto unlock_child;
psk = ask->parent;
pask = alg_sk(ask->parent);
tfm = pask->private;
err = -ENOKEY;
lock_sock_nested(psk, SINGLE_DEPTH_NESTING);
if (!tfm->has_key)
goto unlock;
if (!pask->refcnt++)
sock_hold(psk);
ask->refcnt = 1;
sock_put(psk);
err = 0;
unlock:
release_sock(psk);
unlock_child:
release_sock(sk);
return err;
}
static int aead_sendmsg_nokey(struct socket *sock, struct msghdr *msg,
size_t size)
{
int err;
err = aead_check_key(sock);
if (err)
return err;
return aead_sendmsg(sock, msg, size);
}
static ssize_t aead_sendpage_nokey(struct socket *sock, struct page *page,
int offset, size_t size, int flags)
{
int err;
err = aead_check_key(sock);
if (err)
return err;
return af_alg_sendpage(sock, page, offset, size, flags);
}
static int aead_recvmsg_nokey(struct socket *sock, struct msghdr *msg,
size_t ignored, int flags)
{
int err;
err = aead_check_key(sock);
if (err)
return err;
return aead_recvmsg(sock, msg, ignored, flags);
}
static void *aead_bind(const char *name, u32 type, u32 mask)
{
struct aead_tfm *tfm;
struct crypto_aead *aead;
struct crypto_skcipher *null_tfm;
tfm = kzalloc(sizeof(*tfm), GFP_KERNEL);
if (!tfm)
return ERR_PTR(-ENOMEM);
aead = crypto_alloc_aead(name, type, mask);
if (IS_ERR(aead)) {
kfree(tfm);
return ERR_CAST(aead);
}
null_tfm = crypto_get_default_null_skcipher2();
if (IS_ERR(null_tfm)) {
crypto_free_aead(aead);
kfree(tfm);
return ERR_CAST(null_tfm);
}
tfm->aead = aead;
tfm->null_tfm = null_tfm;
return tfm;
}
static void aead_release(void *private)
{
struct aead_tfm *tfm = private;
crypto_free_aead(tfm->aead);
kfree(tfm);
}
static int aead_setauthsize(void *private, unsigned int authsize)
{
struct aead_tfm *tfm = private;
return crypto_aead_setauthsize(tfm->aead, authsize);
}
static int aead_setkey(void *private, const u8 *key, unsigned int keylen)
{
struct aead_tfm *tfm = private;
int err;
err = crypto_aead_setkey(tfm->aead, key, keylen);
tfm->has_key = !err;
return err;
}
static void aead_sock_destruct(struct sock *sk)
{
struct alg_sock *ask = alg_sk(sk);
struct af_alg_ctx *ctx = ask->private;
struct sock *psk = ask->parent;
struct alg_sock *pask = alg_sk(psk);
struct aead_tfm *aeadc = pask->private;
struct crypto_aead *tfm = aeadc->aead;
unsigned int ivlen = crypto_aead_ivsize(tfm);
af_alg_pull_tsgl(sk, ctx->used, NULL, 0);
crypto_put_default_null_skcipher2();
sock_kzfree_s(sk, ctx->iv, ivlen);
sock_kfree_s(sk, ctx, ctx->len);
af_alg_release_parent(sk);
}
static int aead_accept_parent_nokey(void *private, struct sock *sk)
{
struct af_alg_ctx *ctx;
struct alg_sock *ask = alg_sk(sk);
struct aead_tfm *tfm = private;
struct crypto_aead *aead = tfm->aead;
unsigned int len = sizeof(*ctx);
unsigned int ivlen = crypto_aead_ivsize(aead);
ctx = sock_kmalloc(sk, len, GFP_KERNEL);
if (!ctx)
return -ENOMEM;
memset(ctx, 0, len);
ctx->iv = sock_kmalloc(sk, ivlen, GFP_KERNEL);
if (!ctx->iv) {
sock_kfree_s(sk, ctx, len);
return -ENOMEM;
}
memset(ctx->iv, 0, ivlen);
INIT_LIST_HEAD(&ctx->tsgl_list);
ctx->len = len;
ctx->used = 0;
ctx->rcvused = 0;
ctx->more = 0;
ctx->merge = 0;
ctx->enc = 0;
ctx->aead_assoclen = 0;
af_alg_init_completion(&ctx->completion);
ask->private = ctx;
sk->sk_destruct = aead_sock_destruct;
return 0;
}
static int aead_accept_parent(void *private, struct sock *sk)
{
struct aead_tfm *tfm = private;
if (!tfm->has_key)
return -ENOKEY;
return aead_accept_parent_nokey(private, sk);
}
static int __init algif_aead_init(void)
{
return af_alg_register_type(&algif_type_aead);
}
static void __exit algif_aead_exit(void)
{
int err = af_alg_unregister_type(&algif_type_aead);
BUG_ON(err);
}
