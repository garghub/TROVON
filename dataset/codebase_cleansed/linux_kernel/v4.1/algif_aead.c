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
return (ctx->used >= (ctx->aead_assoclen + (ctx->enc ? 0 : as)));
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
sgl->cur = 0;
ctx->used = 0;
ctx->more = 0;
ctx->merge = 0;
}
static void aead_wmem_wakeup(struct sock *sk)
{
struct socket_wq *wq;
if (!aead_writable(sk))
return;
rcu_read_lock();
wq = rcu_dereference(sk->sk_wq);
if (wq_has_sleeper(wq))
wake_up_interruptible_sync_poll(&wq->wait, POLLIN |
POLLRDNORM |
POLLRDBAND);
sk_wake_async(sk, SOCK_WAKE_WAITD, POLL_IN);
rcu_read_unlock();
}
static int aead_wait_for_data(struct sock *sk, unsigned flags)
{
struct alg_sock *ask = alg_sk(sk);
struct aead_ctx *ctx = ask->private;
long timeout;
DEFINE_WAIT(wait);
int err = -ERESTARTSYS;
if (flags & MSG_DONTWAIT)
return -EAGAIN;
set_bit(SOCK_ASYNC_WAITDATA, &sk->sk_socket->flags);
for (;;) {
if (signal_pending(current))
break;
prepare_to_wait(sk_sleep(sk), &wait, TASK_INTERRUPTIBLE);
timeout = MAX_SCHEDULE_TIMEOUT;
if (sk_wait_event(sk, &timeout, !ctx->more)) {
err = 0;
break;
}
}
finish_wait(sk_sleep(sk), &wait);
clear_bit(SOCK_ASYNC_WAITDATA, &sk->sk_socket->flags);
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
if (wq_has_sleeper(wq))
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
unsigned long len = size;
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
int plen = 0;
if (sgl->cur >= ALG_MAX_PAGES) {
aead_put_sgl(sk);
err = -E2BIG;
goto unlock;
}
sg = sgl->sg + sgl->cur;
plen = min_t(int, len, PAGE_SIZE);
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
static int aead_recvmsg(struct socket *sock, struct msghdr *msg, size_t ignored, int flags)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct aead_ctx *ctx = ask->private;
unsigned bs = crypto_aead_blocksize(crypto_aead_reqtfm(&ctx->aead_req));
unsigned as = crypto_aead_authsize(crypto_aead_reqtfm(&ctx->aead_req));
struct aead_sg_list *sgl = &ctx->tsgl;
struct scatterlist *sg = NULL;
struct scatterlist assoc[ALG_MAX_PAGES];
size_t assoclen = 0;
unsigned int i = 0;
int err = -EINVAL;
unsigned long used = 0;
size_t outlen = 0;
size_t usedpages = 0;
unsigned int cnt = 0;
if (msg->msg_iter.nr_segs > RSGL_MAX_ENTRIES)
return -ENOMSG;
lock_sock(sk);
if (ctx->more) {
err = aead_wait_for_data(sk, flags);
if (err)
goto unlock;
}
used = ctx->used;
if (!aead_sufficient_data(ctx))
goto unlock;
used -= ctx->aead_assoclen;
if (ctx->enc) {
outlen = ((used + bs - 1) / bs * bs);
outlen += as;
} else {
outlen = used - as;
outlen = ((outlen + bs - 1) / bs * bs);
}
while (iov_iter_count(&msg->msg_iter)) {
size_t seglen = min_t(size_t, iov_iter_count(&msg->msg_iter),
(outlen - usedpages));
err = af_alg_make_sg(&ctx->rsgl[cnt], &msg->msg_iter,
seglen);
if (err < 0)
goto unlock;
usedpages += err;
if (cnt)
af_alg_link_sg(&ctx->rsgl[cnt-1], &ctx->rsgl[cnt]);
if (outlen <= usedpages)
break;
iov_iter_advance(&msg->msg_iter, err);
cnt++;
}
err = -EINVAL;
if (usedpages < outlen)
goto unlock;
sg_init_table(assoc, ALG_MAX_PAGES);
assoclen = ctx->aead_assoclen;
for (i = 0; i < ctx->tsgl.cur; i++) {
sg = sgl->sg + i;
if (sg->length <= assoclen) {
sg_set_page(assoc + i, sg_page(sg),
sg->length, sg->offset);
assoclen -= sg->length;
if (i >= ctx->tsgl.cur)
goto unlock;
} else if (!assoclen) {
if (i)
sg_mark_end(assoc + i - 1);
else
sg_mark_end(assoc);
break;
} else {
sg_set_page(assoc + i, sg_page(sg),
assoclen, sg->offset);
sg_mark_end(assoc + i);
sg->length -= assoclen;
sg->offset += assoclen;
break;
}
}
aead_request_set_assoc(&ctx->aead_req, assoc, ctx->aead_assoclen);
aead_request_set_crypt(&ctx->aead_req, sg, ctx->rsgl[0].sg, used,
ctx->iv);
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
for (i = 0; i < cnt; i++)
af_alg_free_sg(&ctx->rsgl[i]);
aead_wmem_wakeup(sk);
release_sock(sk);
return err ? err : outlen;
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
static void *aead_bind(const char *name, u32 type, u32 mask)
{
return crypto_alloc_aead(name, type, mask);
}
static void aead_release(void *private)
{
crypto_free_aead(private);
}
static int aead_setauthsize(void *private, unsigned int authsize)
{
return crypto_aead_setauthsize(private, authsize);
}
static int aead_setkey(void *private, const u8 *key, unsigned int keylen)
{
return crypto_aead_setkey(private, key, keylen);
}
static void aead_sock_destruct(struct sock *sk)
{
struct alg_sock *ask = alg_sk(sk);
struct aead_ctx *ctx = ask->private;
unsigned int ivlen = crypto_aead_ivsize(
crypto_aead_reqtfm(&ctx->aead_req));
aead_put_sgl(sk);
sock_kzfree_s(sk, ctx->iv, ivlen);
sock_kfree_s(sk, ctx, ctx->len);
af_alg_release_parent(sk);
}
static int aead_accept_parent(void *private, struct sock *sk)
{
struct aead_ctx *ctx;
struct alg_sock *ask = alg_sk(sk);
unsigned int len = sizeof(*ctx) + crypto_aead_reqsize(private);
unsigned int ivlen = crypto_aead_ivsize(private);
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
ask->private = ctx;
aead_request_set_tfm(&ctx->aead_req, private);
aead_request_set_callback(&ctx->aead_req, CRYPTO_TFM_REQ_MAY_BACKLOG,
af_alg_complete, &ctx->completion);
sk->sk_destruct = aead_sock_destruct;
return 0;
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
