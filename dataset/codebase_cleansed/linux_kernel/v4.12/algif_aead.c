static inline int aead_sndbuf(struct sock *sk)
{
struct alg_sock *ask = alg_sk(sk);
struct aead_ctx *ctx = ask->private;
return max_t(int, max_t(int, sk->sk_sndbuf & PAGE_MASK, PAGE_SIZE) -
ctx->used, 0);
}
static inline bool aead_writable(struct sock *sk)
{
return PAGE_SIZE <= aead_sndbuf(sk);
}
static inline bool aead_sufficient_data(struct aead_ctx *ctx)
{
unsigned as = crypto_aead_authsize(crypto_aead_reqtfm(&ctx->aead_req));
return ctx->used >= ctx->aead_assoclen + (ctx->enc ? 0 : as);
}
static void aead_reset_ctx(struct aead_ctx *ctx)
{
struct aead_sg_list *sgl = &ctx->tsgl;
sg_init_table(sgl->sg, ALG_MAX_PAGES);
sgl->cur = 0;
ctx->used = 0;
ctx->more = 0;
ctx->merge = 0;
}
static void aead_put_sgl(struct sock *sk)
{
struct alg_sock *ask = alg_sk(sk);
struct aead_ctx *ctx = ask->private;
struct aead_sg_list *sgl = &ctx->tsgl;
struct scatterlist *sg = sgl->sg;
unsigned int i;
for (i = 0; i < sgl->cur; i++) {
if (!sg_page(sg + i))
continue;
put_page(sg_page(sg + i));
sg_assign_page(sg + i, NULL);
}
aead_reset_ctx(ctx);
}
static void aead_wmem_wakeup(struct sock *sk)
{
struct socket_wq *wq;
if (!aead_writable(sk))
return;
rcu_read_lock();
wq = rcu_dereference(sk->sk_wq);
if (skwq_has_sleeper(wq))
wake_up_interruptible_sync_poll(&wq->wait, POLLIN |
POLLRDNORM |
POLLRDBAND);
sk_wake_async(sk, SOCK_WAKE_WAITD, POLL_IN);
rcu_read_unlock();
}
static int aead_wait_for_data(struct sock *sk, unsigned flags)
{
DEFINE_WAIT_FUNC(wait, woken_wake_function);
struct alg_sock *ask = alg_sk(sk);
struct aead_ctx *ctx = ask->private;
long timeout;
int err = -ERESTARTSYS;
if (flags & MSG_DONTWAIT)
return -EAGAIN;
sk_set_bit(SOCKWQ_ASYNC_WAITDATA, sk);
add_wait_queue(sk_sleep(sk), &wait);
for (;;) {
if (signal_pending(current))
break;
timeout = MAX_SCHEDULE_TIMEOUT;
if (sk_wait_event(sk, &timeout, !ctx->more, &wait)) {
err = 0;
break;
}
}
remove_wait_queue(sk_sleep(sk), &wait);
sk_clear_bit(SOCKWQ_ASYNC_WAITDATA, sk);
return err;
}
static void aead_data_wakeup(struct sock *sk)
{
struct alg_sock *ask = alg_sk(sk);
struct aead_ctx *ctx = ask->private;
struct socket_wq *wq;
if (ctx->more)
return;
if (!ctx->used)
return;
rcu_read_lock();
wq = rcu_dereference(sk->sk_wq);
if (skwq_has_sleeper(wq))
wake_up_interruptible_sync_poll(&wq->wait, POLLOUT |
POLLRDNORM |
POLLRDBAND);
sk_wake_async(sk, SOCK_WAKE_SPACE, POLL_OUT);
rcu_read_unlock();
}
static int aead_sendmsg(struct socket *sock, struct msghdr *msg, size_t size)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct aead_ctx *ctx = ask->private;
unsigned ivsize =
crypto_aead_ivsize(crypto_aead_reqtfm(&ctx->aead_req));
struct aead_sg_list *sgl = &ctx->tsgl;
struct af_alg_control con = {};
long copied = 0;
bool enc = 0;
bool init = 0;
int err = -EINVAL;
if (msg->msg_controllen) {
err = af_alg_cmsg_send(msg, &con);
if (err)
return err;
init = 1;
switch (con.op) {
case ALG_OP_ENCRYPT:
enc = 1;
break;
case ALG_OP_DECRYPT:
enc = 0;
break;
default:
return -EINVAL;
}
if (con.iv && con.iv->ivlen != ivsize)
return -EINVAL;
}
lock_sock(sk);
if (!ctx->more && ctx->used)
goto unlock;
if (init) {
ctx->enc = enc;
if (con.iv)
memcpy(ctx->iv, con.iv->iv, ivsize);
ctx->aead_assoclen = con.aead_assoclen;
}
while (size) {
size_t len = size;
struct scatterlist *sg = NULL;
if (ctx->merge) {
sg = sgl->sg + sgl->cur - 1;
len = min_t(unsigned long, len,
PAGE_SIZE - sg->offset - sg->length);
err = memcpy_from_msg(page_address(sg_page(sg)) +
sg->offset + sg->length,
msg, len);
if (err)
goto unlock;
sg->length += len;
ctx->merge = (sg->offset + sg->length) &
(PAGE_SIZE - 1);
ctx->used += len;
copied += len;
size -= len;
continue;
}
if (!aead_writable(sk)) {
aead_put_sgl(sk);
err = -EMSGSIZE;
goto unlock;
}
len = min_t(unsigned long, size, aead_sndbuf(sk));
while (len) {
size_t plen = 0;
if (sgl->cur >= ALG_MAX_PAGES) {
aead_put_sgl(sk);
err = -E2BIG;
goto unlock;
}
sg = sgl->sg + sgl->cur;
plen = min_t(size_t, len, PAGE_SIZE);
sg_assign_page(sg, alloc_page(GFP_KERNEL));
err = -ENOMEM;
if (!sg_page(sg))
goto unlock;
err = memcpy_from_msg(page_address(sg_page(sg)),
msg, plen);
if (err) {
__free_page(sg_page(sg));
sg_assign_page(sg, NULL);
goto unlock;
}
sg->offset = 0;
sg->length = plen;
len -= plen;
ctx->used += plen;
copied += plen;
sgl->cur++;
size -= plen;
ctx->merge = plen & (PAGE_SIZE - 1);
}
}
err = 0;
ctx->more = msg->msg_flags & MSG_MORE;
if (!ctx->more && !aead_sufficient_data(ctx)) {
aead_put_sgl(sk);
err = -EMSGSIZE;
}
unlock:
aead_data_wakeup(sk);
release_sock(sk);
return err ?: copied;
}
static ssize_t aead_sendpage(struct socket *sock, struct page *page,
int offset, size_t size, int flags)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct aead_ctx *ctx = ask->private;
struct aead_sg_list *sgl = &ctx->tsgl;
int err = -EINVAL;
if (flags & MSG_SENDPAGE_NOTLAST)
flags |= MSG_MORE;
if (sgl->cur >= ALG_MAX_PAGES)
return -E2BIG;
lock_sock(sk);
if (!ctx->more && ctx->used)
goto unlock;
if (!size)
goto done;
if (!aead_writable(sk)) {
aead_put_sgl(sk);
err = -EMSGSIZE;
goto unlock;
}
ctx->merge = 0;
get_page(page);
sg_set_page(sgl->sg + sgl->cur, page, size, offset);
sgl->cur++;
ctx->used += size;
err = 0;
done:
ctx->more = flags & MSG_MORE;
if (!ctx->more && !aead_sufficient_data(ctx)) {
aead_put_sgl(sk);
err = -EMSGSIZE;
}
unlock:
aead_data_wakeup(sk);
release_sock(sk);
return err ?: size;
}
static void aead_async_cb(struct crypto_async_request *_req, int err)
{
struct aead_request *req = _req->data;
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct aead_async_req *areq = GET_ASYM_REQ(req, tfm);
struct sock *sk = areq->sk;
struct scatterlist *sg = areq->tsgl;
struct aead_async_rsgl *rsgl;
struct kiocb *iocb = areq->iocb;
unsigned int i, reqlen = GET_REQ_SIZE(tfm);
list_for_each_entry(rsgl, &areq->list, list) {
af_alg_free_sg(&rsgl->sgl);
if (rsgl != &areq->first_rsgl)
sock_kfree_s(sk, rsgl, sizeof(*rsgl));
}
for (i = 0; i < areq->tsgls; i++)
put_page(sg_page(sg + i));
sock_kfree_s(sk, areq->tsgl, sizeof(*areq->tsgl) * areq->tsgls);
sock_kfree_s(sk, req, reqlen);
__sock_put(sk);
iocb->ki_complete(iocb, err, err);
}
static int aead_recvmsg_async(struct socket *sock, struct msghdr *msg,
int flags)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct aead_ctx *ctx = ask->private;
struct crypto_aead *tfm = crypto_aead_reqtfm(&ctx->aead_req);
struct aead_async_req *areq;
struct aead_request *req = NULL;
struct aead_sg_list *sgl = &ctx->tsgl;
struct aead_async_rsgl *last_rsgl = NULL, *rsgl;
unsigned int as = crypto_aead_authsize(tfm);
unsigned int i, reqlen = GET_REQ_SIZE(tfm);
int err = -ENOMEM;
unsigned long used;
size_t outlen = 0;
size_t usedpages = 0;
lock_sock(sk);
if (ctx->more) {
err = aead_wait_for_data(sk, flags);
if (err)
goto unlock;
}
if (!aead_sufficient_data(ctx))
goto unlock;
used = ctx->used;
if (ctx->enc)
outlen = used + as;
else
outlen = used - as;
req = sock_kmalloc(sk, reqlen, GFP_KERNEL);
if (unlikely(!req))
goto unlock;
areq = GET_ASYM_REQ(req, tfm);
memset(&areq->first_rsgl, '\0', sizeof(areq->first_rsgl));
INIT_LIST_HEAD(&areq->list);
areq->iocb = msg->msg_iocb;
areq->sk = sk;
memcpy(areq->iv, ctx->iv, crypto_aead_ivsize(tfm));
aead_request_set_tfm(req, tfm);
aead_request_set_ad(req, ctx->aead_assoclen);
aead_request_set_callback(req, CRYPTO_TFM_REQ_MAY_BACKLOG,
aead_async_cb, req);
used -= ctx->aead_assoclen;
areq->tsgl = sock_kmalloc(sk,
sizeof(*areq->tsgl) * max_t(u32, sgl->cur, 1),
GFP_KERNEL);
if (unlikely(!areq->tsgl))
goto free;
sg_init_table(areq->tsgl, max_t(u32, sgl->cur, 1));
for (i = 0; i < sgl->cur; i++)
sg_set_page(&areq->tsgl[i], sg_page(&sgl->sg[i]),
sgl->sg[i].length, sgl->sg[i].offset);
areq->tsgls = sgl->cur;
while (outlen > usedpages && iov_iter_count(&msg->msg_iter)) {
size_t seglen = min_t(size_t, iov_iter_count(&msg->msg_iter),
(outlen - usedpages));
if (list_empty(&areq->list)) {
rsgl = &areq->first_rsgl;
} else {
rsgl = sock_kmalloc(sk, sizeof(*rsgl), GFP_KERNEL);
if (unlikely(!rsgl)) {
err = -ENOMEM;
goto free;
}
}
rsgl->sgl.npages = 0;
list_add_tail(&rsgl->list, &areq->list);
err = af_alg_make_sg(&rsgl->sgl, &msg->msg_iter, seglen);
if (err < 0)
goto free;
usedpages += err;
if (last_rsgl)
af_alg_link_sg(&last_rsgl->sgl, &rsgl->sgl);
last_rsgl = rsgl;
iov_iter_advance(&msg->msg_iter, err);
}
if (usedpages < outlen) {
err = -EINVAL;
goto unlock;
}
aead_request_set_crypt(req, areq->tsgl, areq->first_rsgl.sgl.sg, used,
areq->iv);
err = ctx->enc ? crypto_aead_encrypt(req) : crypto_aead_decrypt(req);
if (err) {
if (err == -EINPROGRESS) {
sock_hold(sk);
err = -EIOCBQUEUED;
aead_reset_ctx(ctx);
goto unlock;
} else if (err == -EBADMSG) {
aead_put_sgl(sk);
}
goto free;
}
aead_put_sgl(sk);
free:
list_for_each_entry(rsgl, &areq->list, list) {
af_alg_free_sg(&rsgl->sgl);
if (rsgl != &areq->first_rsgl)
sock_kfree_s(sk, rsgl, sizeof(*rsgl));
}
if (areq->tsgl)
sock_kfree_s(sk, areq->tsgl, sizeof(*areq->tsgl) * areq->tsgls);
if (req)
sock_kfree_s(sk, req, reqlen);
unlock:
aead_wmem_wakeup(sk);
release_sock(sk);
return err ? err : outlen;
}
static int aead_recvmsg_sync(struct socket *sock, struct msghdr *msg, int flags)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct aead_ctx *ctx = ask->private;
unsigned as = crypto_aead_authsize(crypto_aead_reqtfm(&ctx->aead_req));
struct aead_sg_list *sgl = &ctx->tsgl;
struct aead_async_rsgl *last_rsgl = NULL;
struct aead_async_rsgl *rsgl, *tmp;
int err = -EINVAL;
unsigned long used = 0;
size_t outlen = 0;
size_t usedpages = 0;
lock_sock(sk);
if (ctx->more) {
err = aead_wait_for_data(sk, flags);
if (err)
goto unlock;
}
used = ctx->used;
if (!aead_sufficient_data(ctx))
goto unlock;
if (ctx->enc)
outlen = used + as;
else
outlen = used - as;
used -= ctx->aead_assoclen;
while (outlen > usedpages && iov_iter_count(&msg->msg_iter)) {
size_t seglen = min_t(size_t, iov_iter_count(&msg->msg_iter),
(outlen - usedpages));
if (list_empty(&ctx->list)) {
rsgl = &ctx->first_rsgl;
} else {
rsgl = sock_kmalloc(sk, sizeof(*rsgl), GFP_KERNEL);
if (unlikely(!rsgl)) {
err = -ENOMEM;
goto unlock;
}
}
rsgl->sgl.npages = 0;
list_add_tail(&rsgl->list, &ctx->list);
err = af_alg_make_sg(&rsgl->sgl, &msg->msg_iter, seglen);
if (err < 0)
goto unlock;
usedpages += err;
if (last_rsgl)
af_alg_link_sg(&last_rsgl->sgl, &rsgl->sgl);
last_rsgl = rsgl;
iov_iter_advance(&msg->msg_iter, err);
}
if (usedpages < outlen) {
err = -EINVAL;
goto unlock;
}
sg_mark_end(sgl->sg + sgl->cur - 1);
aead_request_set_crypt(&ctx->aead_req, sgl->sg, ctx->first_rsgl.sgl.sg,
used, ctx->iv);
aead_request_set_ad(&ctx->aead_req, ctx->aead_assoclen);
err = af_alg_wait_for_completion(ctx->enc ?
crypto_aead_encrypt(&ctx->aead_req) :
crypto_aead_decrypt(&ctx->aead_req),
&ctx->completion);
if (err) {
if (err == -EBADMSG)
aead_put_sgl(sk);
goto unlock;
}
aead_put_sgl(sk);
err = 0;
unlock:
list_for_each_entry_safe(rsgl, tmp, &ctx->list, list) {
af_alg_free_sg(&rsgl->sgl);
list_del(&rsgl->list);
if (rsgl != &ctx->first_rsgl)
sock_kfree_s(sk, rsgl, sizeof(*rsgl));
}
INIT_LIST_HEAD(&ctx->list);
aead_wmem_wakeup(sk);
release_sock(sk);
return err ? err : outlen;
}
static int aead_recvmsg(struct socket *sock, struct msghdr *msg, size_t ignored,
int flags)
{
return (msg->msg_iocb && !is_sync_kiocb(msg->msg_iocb)) ?
aead_recvmsg_async(sock, msg, flags) :
aead_recvmsg_sync(sock, msg, flags);
}
static unsigned int aead_poll(struct file *file, struct socket *sock,
poll_table *wait)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct aead_ctx *ctx = ask->private;
unsigned int mask;
sock_poll_wait(file, sk_sleep(sk), wait);
mask = 0;
if (!ctx->more)
mask |= POLLIN | POLLRDNORM;
if (aead_writable(sk))
mask |= POLLOUT | POLLWRNORM | POLLWRBAND;
return mask;
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
return aead_sendpage(sock, page, offset, size, flags);
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
tfm = kzalloc(sizeof(*tfm), GFP_KERNEL);
if (!tfm)
return ERR_PTR(-ENOMEM);
aead = crypto_alloc_aead(name, type, mask);
if (IS_ERR(aead)) {
kfree(tfm);
return ERR_CAST(aead);
}
tfm->aead = aead;
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
struct aead_ctx *ctx = ask->private;
unsigned int ivlen = crypto_aead_ivsize(
crypto_aead_reqtfm(&ctx->aead_req));
WARN_ON(atomic_read(&sk->sk_refcnt) != 0);
aead_put_sgl(sk);
sock_kzfree_s(sk, ctx->iv, ivlen);
sock_kfree_s(sk, ctx, ctx->len);
af_alg_release_parent(sk);
}
static int aead_accept_parent_nokey(void *private, struct sock *sk)
{
struct aead_ctx *ctx;
struct alg_sock *ask = alg_sk(sk);
struct aead_tfm *tfm = private;
struct crypto_aead *aead = tfm->aead;
unsigned int len = sizeof(*ctx) + crypto_aead_reqsize(aead);
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
ctx->len = len;
ctx->used = 0;
ctx->more = 0;
ctx->merge = 0;
ctx->enc = 0;
ctx->tsgl.cur = 0;
ctx->aead_assoclen = 0;
af_alg_init_completion(&ctx->completion);
sg_init_table(ctx->tsgl.sg, ALG_MAX_PAGES);
INIT_LIST_HEAD(&ctx->list);
ask->private = ctx;
aead_request_set_tfm(&ctx->aead_req, aead);
aead_request_set_callback(&ctx->aead_req, CRYPTO_TFM_REQ_MAY_BACKLOG,
af_alg_complete, &ctx->completion);
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
