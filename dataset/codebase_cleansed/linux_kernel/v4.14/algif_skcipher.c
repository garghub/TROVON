static int skcipher_sendmsg(struct socket *sock, struct msghdr *msg,
size_t size)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct sock *psk = ask->parent;
struct alg_sock *pask = alg_sk(psk);
struct skcipher_tfm *skc = pask->private;
struct crypto_skcipher *tfm = skc->skcipher;
unsigned ivsize = crypto_skcipher_ivsize(tfm);
return af_alg_sendmsg(sock, msg, size, ivsize);
}
static int _skcipher_recvmsg(struct socket *sock, struct msghdr *msg,
size_t ignored, int flags)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct sock *psk = ask->parent;
struct alg_sock *pask = alg_sk(psk);
struct af_alg_ctx *ctx = ask->private;
struct skcipher_tfm *skc = pask->private;
struct crypto_skcipher *tfm = skc->skcipher;
unsigned int bs = crypto_skcipher_blocksize(tfm);
struct af_alg_async_req *areq;
int err = 0;
size_t len = 0;
areq = af_alg_alloc_areq(sk, sizeof(struct af_alg_async_req) +
crypto_skcipher_reqsize(tfm));
if (IS_ERR(areq))
return PTR_ERR(areq);
err = af_alg_get_rsgl(sk, msg, flags, areq, -1, &len);
if (err)
goto free;
if (len > ctx->used)
len = ctx->used;
if (ctx->more || len < ctx->used)
len -= len % bs;
areq->tsgl_entries = af_alg_count_tsgl(sk, len, 0);
if (!areq->tsgl_entries)
areq->tsgl_entries = 1;
areq->tsgl = sock_kmalloc(sk, sizeof(*areq->tsgl) * areq->tsgl_entries,
GFP_KERNEL);
if (!areq->tsgl) {
err = -ENOMEM;
goto free;
}
sg_init_table(areq->tsgl, areq->tsgl_entries);
af_alg_pull_tsgl(sk, len, areq->tsgl, 0);
skcipher_request_set_tfm(&areq->cra_u.skcipher_req, tfm);
skcipher_request_set_crypt(&areq->cra_u.skcipher_req, areq->tsgl,
areq->first_rsgl.sgl.sg, len, ctx->iv);
if (msg->msg_iocb && !is_sync_kiocb(msg->msg_iocb)) {
areq->iocb = msg->msg_iocb;
skcipher_request_set_callback(&areq->cra_u.skcipher_req,
CRYPTO_TFM_REQ_MAY_SLEEP,
af_alg_async_cb, areq);
err = ctx->enc ?
crypto_skcipher_encrypt(&areq->cra_u.skcipher_req) :
crypto_skcipher_decrypt(&areq->cra_u.skcipher_req);
} else {
skcipher_request_set_callback(&areq->cra_u.skcipher_req,
CRYPTO_TFM_REQ_MAY_SLEEP |
CRYPTO_TFM_REQ_MAY_BACKLOG,
af_alg_complete,
&ctx->completion);
err = af_alg_wait_for_completion(ctx->enc ?
crypto_skcipher_encrypt(&areq->cra_u.skcipher_req) :
crypto_skcipher_decrypt(&areq->cra_u.skcipher_req),
&ctx->completion);
}
if (err == -EINPROGRESS) {
sock_hold(sk);
areq->outlen = len;
return -EIOCBQUEUED;
}
free:
af_alg_free_areq_sgls(areq);
sock_kfree_s(sk, areq, areq->areqlen);
return err ? err : len;
}
static int skcipher_recvmsg(struct socket *sock, struct msghdr *msg,
size_t ignored, int flags)
{
struct sock *sk = sock->sk;
int ret = 0;
lock_sock(sk);
while (msg_data_left(msg)) {
int err = _skcipher_recvmsg(sock, msg, ignored, flags);
if (err <= 0) {
if (err == -EIOCBQUEUED || !ret)
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
static int skcipher_check_key(struct socket *sock)
{
int err = 0;
struct sock *psk;
struct alg_sock *pask;
struct skcipher_tfm *tfm;
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
static int skcipher_sendmsg_nokey(struct socket *sock, struct msghdr *msg,
size_t size)
{
int err;
err = skcipher_check_key(sock);
if (err)
return err;
return skcipher_sendmsg(sock, msg, size);
}
static ssize_t skcipher_sendpage_nokey(struct socket *sock, struct page *page,
int offset, size_t size, int flags)
{
int err;
err = skcipher_check_key(sock);
if (err)
return err;
return af_alg_sendpage(sock, page, offset, size, flags);
}
static int skcipher_recvmsg_nokey(struct socket *sock, struct msghdr *msg,
size_t ignored, int flags)
{
int err;
err = skcipher_check_key(sock);
if (err)
return err;
return skcipher_recvmsg(sock, msg, ignored, flags);
}
static void *skcipher_bind(const char *name, u32 type, u32 mask)
{
struct skcipher_tfm *tfm;
struct crypto_skcipher *skcipher;
tfm = kzalloc(sizeof(*tfm), GFP_KERNEL);
if (!tfm)
return ERR_PTR(-ENOMEM);
skcipher = crypto_alloc_skcipher(name, type, mask);
if (IS_ERR(skcipher)) {
kfree(tfm);
return ERR_CAST(skcipher);
}
tfm->skcipher = skcipher;
return tfm;
}
static void skcipher_release(void *private)
{
struct skcipher_tfm *tfm = private;
crypto_free_skcipher(tfm->skcipher);
kfree(tfm);
}
static int skcipher_setkey(void *private, const u8 *key, unsigned int keylen)
{
struct skcipher_tfm *tfm = private;
int err;
err = crypto_skcipher_setkey(tfm->skcipher, key, keylen);
tfm->has_key = !err;
return err;
}
static void skcipher_sock_destruct(struct sock *sk)
{
struct alg_sock *ask = alg_sk(sk);
struct af_alg_ctx *ctx = ask->private;
struct sock *psk = ask->parent;
struct alg_sock *pask = alg_sk(psk);
struct skcipher_tfm *skc = pask->private;
struct crypto_skcipher *tfm = skc->skcipher;
af_alg_pull_tsgl(sk, ctx->used, NULL, 0);
sock_kzfree_s(sk, ctx->iv, crypto_skcipher_ivsize(tfm));
sock_kfree_s(sk, ctx, ctx->len);
af_alg_release_parent(sk);
}
static int skcipher_accept_parent_nokey(void *private, struct sock *sk)
{
struct af_alg_ctx *ctx;
struct alg_sock *ask = alg_sk(sk);
struct skcipher_tfm *tfm = private;
struct crypto_skcipher *skcipher = tfm->skcipher;
unsigned int len = sizeof(*ctx);
ctx = sock_kmalloc(sk, len, GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->iv = sock_kmalloc(sk, crypto_skcipher_ivsize(skcipher),
GFP_KERNEL);
if (!ctx->iv) {
sock_kfree_s(sk, ctx, len);
return -ENOMEM;
}
memset(ctx->iv, 0, crypto_skcipher_ivsize(skcipher));
INIT_LIST_HEAD(&ctx->tsgl_list);
ctx->len = len;
ctx->used = 0;
ctx->rcvused = 0;
ctx->more = 0;
ctx->merge = 0;
ctx->enc = 0;
af_alg_init_completion(&ctx->completion);
ask->private = ctx;
sk->sk_destruct = skcipher_sock_destruct;
return 0;
}
static int skcipher_accept_parent(void *private, struct sock *sk)
{
struct skcipher_tfm *tfm = private;
if (!tfm->has_key && crypto_skcipher_has_setkey(tfm->skcipher))
return -ENOKEY;
return skcipher_accept_parent_nokey(private, sk);
}
static int __init algif_skcipher_init(void)
{
return af_alg_register_type(&algif_type_skcipher);
}
static void __exit algif_skcipher_exit(void)
{
int err = af_alg_unregister_type(&algif_type_skcipher);
BUG_ON(err);
}
