static const struct af_alg_type *alg_get_type(const char *name)
{
const struct af_alg_type *type = ERR_PTR(-ENOENT);
struct alg_type_list *node;
down_read(&alg_types_sem);
list_for_each_entry(node, &alg_types, list) {
if (strcmp(node->type->name, name))
continue;
if (try_module_get(node->type->owner))
type = node->type;
break;
}
up_read(&alg_types_sem);
return type;
}
int af_alg_register_type(const struct af_alg_type *type)
{
struct alg_type_list *node;
int err = -EEXIST;
down_write(&alg_types_sem);
list_for_each_entry(node, &alg_types, list) {
if (!strcmp(node->type->name, type->name))
goto unlock;
}
node = kmalloc(sizeof(*node), GFP_KERNEL);
err = -ENOMEM;
if (!node)
goto unlock;
type->ops->owner = THIS_MODULE;
if (type->ops_nokey)
type->ops_nokey->owner = THIS_MODULE;
node->type = type;
list_add(&node->list, &alg_types);
err = 0;
unlock:
up_write(&alg_types_sem);
return err;
}
int af_alg_unregister_type(const struct af_alg_type *type)
{
struct alg_type_list *node;
int err = -ENOENT;
down_write(&alg_types_sem);
list_for_each_entry(node, &alg_types, list) {
if (strcmp(node->type->name, type->name))
continue;
list_del(&node->list);
kfree(node);
err = 0;
break;
}
up_write(&alg_types_sem);
return err;
}
static void alg_do_release(const struct af_alg_type *type, void *private)
{
if (!type)
return;
type->release(private);
module_put(type->owner);
}
int af_alg_release(struct socket *sock)
{
if (sock->sk)
sock_put(sock->sk);
return 0;
}
void af_alg_release_parent(struct sock *sk)
{
struct alg_sock *ask = alg_sk(sk);
unsigned int nokey = ask->nokey_refcnt;
bool last = nokey && !ask->refcnt;
sk = ask->parent;
ask = alg_sk(sk);
lock_sock(sk);
ask->nokey_refcnt -= nokey;
if (!last)
last = !--ask->refcnt;
release_sock(sk);
if (last)
sock_put(sk);
}
static int alg_bind(struct socket *sock, struct sockaddr *uaddr, int addr_len)
{
const u32 forbidden = CRYPTO_ALG_INTERNAL;
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct sockaddr_alg *sa = (void *)uaddr;
const struct af_alg_type *type;
void *private;
int err;
if (sock->state == SS_CONNECTED)
return -EINVAL;
if (addr_len < sizeof(*sa))
return -EINVAL;
sa->salg_type[sizeof(sa->salg_type) - 1] = 0;
sa->salg_name[sizeof(sa->salg_name) + addr_len - sizeof(*sa) - 1] = 0;
type = alg_get_type(sa->salg_type);
if (IS_ERR(type) && PTR_ERR(type) == -ENOENT) {
request_module("algif-%s", sa->salg_type);
type = alg_get_type(sa->salg_type);
}
if (IS_ERR(type))
return PTR_ERR(type);
private = type->bind(sa->salg_name,
sa->salg_feat & ~forbidden,
sa->salg_mask & ~forbidden);
if (IS_ERR(private)) {
module_put(type->owner);
return PTR_ERR(private);
}
err = -EBUSY;
lock_sock(sk);
if (ask->refcnt | ask->nokey_refcnt)
goto unlock;
swap(ask->type, type);
swap(ask->private, private);
err = 0;
unlock:
release_sock(sk);
alg_do_release(type, private);
return err;
}
static int alg_setkey(struct sock *sk, char __user *ukey,
unsigned int keylen)
{
struct alg_sock *ask = alg_sk(sk);
const struct af_alg_type *type = ask->type;
u8 *key;
int err;
key = sock_kmalloc(sk, keylen, GFP_KERNEL);
if (!key)
return -ENOMEM;
err = -EFAULT;
if (copy_from_user(key, ukey, keylen))
goto out;
err = type->setkey(ask->private, key, keylen);
out:
sock_kzfree_s(sk, key, keylen);
return err;
}
static int alg_setsockopt(struct socket *sock, int level, int optname,
char __user *optval, unsigned int optlen)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
const struct af_alg_type *type;
int err = -EBUSY;
lock_sock(sk);
if (ask->refcnt)
goto unlock;
type = ask->type;
err = -ENOPROTOOPT;
if (level != SOL_ALG || !type)
goto unlock;
switch (optname) {
case ALG_SET_KEY:
if (sock->state == SS_CONNECTED)
goto unlock;
if (!type->setkey)
goto unlock;
err = alg_setkey(sk, optval, optlen);
break;
case ALG_SET_AEAD_AUTHSIZE:
if (sock->state == SS_CONNECTED)
goto unlock;
if (!type->setauthsize)
goto unlock;
err = type->setauthsize(ask->private, optlen);
}
unlock:
release_sock(sk);
return err;
}
int af_alg_accept(struct sock *sk, struct socket *newsock, bool kern)
{
struct alg_sock *ask = alg_sk(sk);
const struct af_alg_type *type;
struct sock *sk2;
unsigned int nokey;
int err;
lock_sock(sk);
type = ask->type;
err = -EINVAL;
if (!type)
goto unlock;
sk2 = sk_alloc(sock_net(sk), PF_ALG, GFP_KERNEL, &alg_proto, kern);
err = -ENOMEM;
if (!sk2)
goto unlock;
sock_init_data(newsock, sk2);
security_sock_graft(sk2, newsock);
security_sk_clone(sk, sk2);
err = type->accept(ask->private, sk2);
nokey = err == -ENOKEY;
if (nokey && type->accept_nokey)
err = type->accept_nokey(ask->private, sk2);
if (err)
goto unlock;
sk2->sk_family = PF_ALG;
if (nokey || !ask->refcnt++)
sock_hold(sk);
ask->nokey_refcnt += nokey;
alg_sk(sk2)->parent = sk;
alg_sk(sk2)->type = type;
alg_sk(sk2)->nokey_refcnt = nokey;
newsock->ops = type->ops;
newsock->state = SS_CONNECTED;
if (nokey)
newsock->ops = type->ops_nokey;
err = 0;
unlock:
release_sock(sk);
return err;
}
static int alg_accept(struct socket *sock, struct socket *newsock, int flags,
bool kern)
{
return af_alg_accept(sock->sk, newsock, kern);
}
static void alg_sock_destruct(struct sock *sk)
{
struct alg_sock *ask = alg_sk(sk);
alg_do_release(ask->type, ask->private);
}
static int alg_create(struct net *net, struct socket *sock, int protocol,
int kern)
{
struct sock *sk;
int err;
if (sock->type != SOCK_SEQPACKET)
return -ESOCKTNOSUPPORT;
if (protocol != 0)
return -EPROTONOSUPPORT;
err = -ENOMEM;
sk = sk_alloc(net, PF_ALG, GFP_KERNEL, &alg_proto, kern);
if (!sk)
goto out;
sock->ops = &alg_proto_ops;
sock_init_data(sock, sk);
sk->sk_family = PF_ALG;
sk->sk_destruct = alg_sock_destruct;
return 0;
out:
return err;
}
int af_alg_make_sg(struct af_alg_sgl *sgl, struct iov_iter *iter, int len)
{
size_t off;
ssize_t n;
int npages, i;
n = iov_iter_get_pages(iter, sgl->pages, len, ALG_MAX_PAGES, &off);
if (n < 0)
return n;
npages = (off + n + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (WARN_ON(npages == 0))
return -EINVAL;
sg_init_table(sgl->sg, npages + 1);
for (i = 0, len = n; i < npages; i++) {
int plen = min_t(int, len, PAGE_SIZE - off);
sg_set_page(sgl->sg + i, sgl->pages[i], plen, off);
off = 0;
len -= plen;
}
sg_mark_end(sgl->sg + npages - 1);
sgl->npages = npages;
return n;
}
void af_alg_link_sg(struct af_alg_sgl *sgl_prev, struct af_alg_sgl *sgl_new)
{
sg_unmark_end(sgl_prev->sg + sgl_prev->npages - 1);
sg_chain(sgl_prev->sg, sgl_prev->npages + 1, sgl_new->sg);
}
void af_alg_free_sg(struct af_alg_sgl *sgl)
{
int i;
for (i = 0; i < sgl->npages; i++)
put_page(sgl->pages[i]);
}
int af_alg_cmsg_send(struct msghdr *msg, struct af_alg_control *con)
{
struct cmsghdr *cmsg;
for_each_cmsghdr(cmsg, msg) {
if (!CMSG_OK(msg, cmsg))
return -EINVAL;
if (cmsg->cmsg_level != SOL_ALG)
continue;
switch (cmsg->cmsg_type) {
case ALG_SET_IV:
if (cmsg->cmsg_len < CMSG_LEN(sizeof(*con->iv)))
return -EINVAL;
con->iv = (void *)CMSG_DATA(cmsg);
if (cmsg->cmsg_len < CMSG_LEN(con->iv->ivlen +
sizeof(*con->iv)))
return -EINVAL;
break;
case ALG_SET_OP:
if (cmsg->cmsg_len < CMSG_LEN(sizeof(u32)))
return -EINVAL;
con->op = *(u32 *)CMSG_DATA(cmsg);
break;
case ALG_SET_AEAD_ASSOCLEN:
if (cmsg->cmsg_len < CMSG_LEN(sizeof(u32)))
return -EINVAL;
con->aead_assoclen = *(u32 *)CMSG_DATA(cmsg);
break;
default:
return -EINVAL;
}
}
return 0;
}
int af_alg_wait_for_completion(int err, struct af_alg_completion *completion)
{
switch (err) {
case -EINPROGRESS:
case -EBUSY:
wait_for_completion(&completion->completion);
reinit_completion(&completion->completion);
err = completion->err;
break;
};
return err;
}
void af_alg_complete(struct crypto_async_request *req, int err)
{
struct af_alg_completion *completion = req->data;
if (err == -EINPROGRESS)
return;
completion->err = err;
complete(&completion->completion);
}
int af_alg_alloc_tsgl(struct sock *sk)
{
struct alg_sock *ask = alg_sk(sk);
struct af_alg_ctx *ctx = ask->private;
struct af_alg_tsgl *sgl;
struct scatterlist *sg = NULL;
sgl = list_entry(ctx->tsgl_list.prev, struct af_alg_tsgl, list);
if (!list_empty(&ctx->tsgl_list))
sg = sgl->sg;
if (!sg || sgl->cur >= MAX_SGL_ENTS) {
sgl = sock_kmalloc(sk, sizeof(*sgl) +
sizeof(sgl->sg[0]) * (MAX_SGL_ENTS + 1),
GFP_KERNEL);
if (!sgl)
return -ENOMEM;
sg_init_table(sgl->sg, MAX_SGL_ENTS + 1);
sgl->cur = 0;
if (sg)
sg_chain(sg, MAX_SGL_ENTS + 1, sgl->sg);
list_add_tail(&sgl->list, &ctx->tsgl_list);
}
return 0;
}
unsigned int af_alg_count_tsgl(struct sock *sk, size_t bytes, size_t offset)
{
struct alg_sock *ask = alg_sk(sk);
struct af_alg_ctx *ctx = ask->private;
struct af_alg_tsgl *sgl, *tmp;
unsigned int i;
unsigned int sgl_count = 0;
if (!bytes)
return 0;
list_for_each_entry_safe(sgl, tmp, &ctx->tsgl_list, list) {
struct scatterlist *sg = sgl->sg;
for (i = 0; i < sgl->cur; i++) {
size_t bytes_count;
if (offset >= sg[i].length) {
offset -= sg[i].length;
bytes -= sg[i].length;
continue;
}
bytes_count = sg[i].length - offset;
offset = 0;
sgl_count++;
if (bytes_count >= bytes)
return sgl_count;
bytes -= bytes_count;
}
}
return sgl_count;
}
void af_alg_pull_tsgl(struct sock *sk, size_t used, struct scatterlist *dst,
size_t dst_offset)
{
struct alg_sock *ask = alg_sk(sk);
struct af_alg_ctx *ctx = ask->private;
struct af_alg_tsgl *sgl;
struct scatterlist *sg;
unsigned int i, j = 0;
while (!list_empty(&ctx->tsgl_list)) {
sgl = list_first_entry(&ctx->tsgl_list, struct af_alg_tsgl,
list);
sg = sgl->sg;
for (i = 0; i < sgl->cur; i++) {
size_t plen = min_t(size_t, used, sg[i].length);
struct page *page = sg_page(sg + i);
if (!page)
continue;
if (dst) {
if (dst_offset >= plen) {
dst_offset -= plen;
} else {
get_page(page);
sg_set_page(dst + j, page,
plen - dst_offset,
sg[i].offset + dst_offset);
dst_offset = 0;
j++;
}
}
sg[i].length -= plen;
sg[i].offset += plen;
used -= plen;
ctx->used -= plen;
if (sg[i].length)
return;
put_page(page);
sg_assign_page(sg + i, NULL);
}
list_del(&sgl->list);
sock_kfree_s(sk, sgl, sizeof(*sgl) + sizeof(sgl->sg[0]) *
(MAX_SGL_ENTS + 1));
}
if (!ctx->used)
ctx->merge = 0;
}
void af_alg_free_areq_sgls(struct af_alg_async_req *areq)
{
struct sock *sk = areq->sk;
struct alg_sock *ask = alg_sk(sk);
struct af_alg_ctx *ctx = ask->private;
struct af_alg_rsgl *rsgl, *tmp;
struct scatterlist *tsgl;
struct scatterlist *sg;
unsigned int i;
list_for_each_entry_safe(rsgl, tmp, &areq->rsgl_list, list) {
ctx->rcvused -= rsgl->sg_num_bytes;
af_alg_free_sg(&rsgl->sgl);
list_del(&rsgl->list);
if (rsgl != &areq->first_rsgl)
sock_kfree_s(sk, rsgl, sizeof(*rsgl));
}
tsgl = areq->tsgl;
for_each_sg(tsgl, sg, areq->tsgl_entries, i) {
if (!sg_page(sg))
continue;
put_page(sg_page(sg));
}
if (areq->tsgl && areq->tsgl_entries)
sock_kfree_s(sk, tsgl, areq->tsgl_entries * sizeof(*tsgl));
}
int af_alg_wait_for_wmem(struct sock *sk, unsigned int flags)
{
DEFINE_WAIT_FUNC(wait, woken_wake_function);
int err = -ERESTARTSYS;
long timeout;
if (flags & MSG_DONTWAIT)
return -EAGAIN;
sk_set_bit(SOCKWQ_ASYNC_NOSPACE, sk);
add_wait_queue(sk_sleep(sk), &wait);
for (;;) {
if (signal_pending(current))
break;
timeout = MAX_SCHEDULE_TIMEOUT;
if (sk_wait_event(sk, &timeout, af_alg_writable(sk), &wait)) {
err = 0;
break;
}
}
remove_wait_queue(sk_sleep(sk), &wait);
return err;
}
void af_alg_wmem_wakeup(struct sock *sk)
{
struct socket_wq *wq;
if (!af_alg_writable(sk))
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
int af_alg_wait_for_data(struct sock *sk, unsigned flags)
{
DEFINE_WAIT_FUNC(wait, woken_wake_function);
struct alg_sock *ask = alg_sk(sk);
struct af_alg_ctx *ctx = ask->private;
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
if (sk_wait_event(sk, &timeout, (ctx->used || !ctx->more),
&wait)) {
err = 0;
break;
}
}
remove_wait_queue(sk_sleep(sk), &wait);
sk_clear_bit(SOCKWQ_ASYNC_WAITDATA, sk);
return err;
}
void af_alg_data_wakeup(struct sock *sk)
{
struct alg_sock *ask = alg_sk(sk);
struct af_alg_ctx *ctx = ask->private;
struct socket_wq *wq;
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
int af_alg_sendmsg(struct socket *sock, struct msghdr *msg, size_t size,
unsigned int ivsize)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct af_alg_ctx *ctx = ask->private;
struct af_alg_tsgl *sgl;
struct af_alg_control con = {};
long copied = 0;
bool enc = 0;
bool init = 0;
int err = 0;
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
if (!ctx->more && ctx->used) {
err = -EINVAL;
goto unlock;
}
if (init) {
ctx->enc = enc;
if (con.iv)
memcpy(ctx->iv, con.iv->iv, ivsize);
ctx->aead_assoclen = con.aead_assoclen;
}
while (size) {
struct scatterlist *sg;
size_t len = size;
size_t plen;
if (ctx->merge) {
sgl = list_entry(ctx->tsgl_list.prev,
struct af_alg_tsgl, list);
sg = sgl->sg + sgl->cur - 1;
len = min_t(size_t, len,
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
if (!af_alg_writable(sk)) {
err = af_alg_wait_for_wmem(sk, msg->msg_flags);
if (err)
goto unlock;
}
len = min_t(unsigned long, len, af_alg_sndbuf(sk));
err = af_alg_alloc_tsgl(sk);
if (err)
goto unlock;
sgl = list_entry(ctx->tsgl_list.prev, struct af_alg_tsgl,
list);
sg = sgl->sg;
if (sgl->cur)
sg_unmark_end(sg + sgl->cur - 1);
do {
unsigned int i = sgl->cur;
plen = min_t(size_t, len, PAGE_SIZE);
sg_assign_page(sg + i, alloc_page(GFP_KERNEL));
if (!sg_page(sg + i)) {
err = -ENOMEM;
goto unlock;
}
err = memcpy_from_msg(page_address(sg_page(sg + i)),
msg, plen);
if (err) {
__free_page(sg_page(sg + i));
sg_assign_page(sg + i, NULL);
goto unlock;
}
sg[i].length = plen;
len -= plen;
ctx->used += plen;
copied += plen;
size -= plen;
sgl->cur++;
} while (len && sgl->cur < MAX_SGL_ENTS);
if (!size)
sg_mark_end(sg + sgl->cur - 1);
ctx->merge = plen & (PAGE_SIZE - 1);
}
err = 0;
ctx->more = msg->msg_flags & MSG_MORE;
unlock:
af_alg_data_wakeup(sk);
release_sock(sk);
return copied ?: err;
}
ssize_t af_alg_sendpage(struct socket *sock, struct page *page,
int offset, size_t size, int flags)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct af_alg_ctx *ctx = ask->private;
struct af_alg_tsgl *sgl;
int err = -EINVAL;
if (flags & MSG_SENDPAGE_NOTLAST)
flags |= MSG_MORE;
lock_sock(sk);
if (!ctx->more && ctx->used)
goto unlock;
if (!size)
goto done;
if (!af_alg_writable(sk)) {
err = af_alg_wait_for_wmem(sk, flags);
if (err)
goto unlock;
}
err = af_alg_alloc_tsgl(sk);
if (err)
goto unlock;
ctx->merge = 0;
sgl = list_entry(ctx->tsgl_list.prev, struct af_alg_tsgl, list);
if (sgl->cur)
sg_unmark_end(sgl->sg + sgl->cur - 1);
sg_mark_end(sgl->sg + sgl->cur);
get_page(page);
sg_set_page(sgl->sg + sgl->cur, page, size, offset);
sgl->cur++;
ctx->used += size;
done:
ctx->more = flags & MSG_MORE;
unlock:
af_alg_data_wakeup(sk);
release_sock(sk);
return err ?: size;
}
void af_alg_async_cb(struct crypto_async_request *_req, int err)
{
struct af_alg_async_req *areq = _req->data;
struct sock *sk = areq->sk;
struct kiocb *iocb = areq->iocb;
unsigned int resultlen;
lock_sock(sk);
resultlen = areq->outlen;
af_alg_free_areq_sgls(areq);
sock_kfree_s(sk, areq, areq->areqlen);
__sock_put(sk);
iocb->ki_complete(iocb, err ? err : resultlen, 0);
release_sock(sk);
}
unsigned int af_alg_poll(struct file *file, struct socket *sock,
poll_table *wait)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct af_alg_ctx *ctx = ask->private;
unsigned int mask;
sock_poll_wait(file, sk_sleep(sk), wait);
mask = 0;
if (!ctx->more || ctx->used)
mask |= POLLIN | POLLRDNORM;
if (af_alg_writable(sk))
mask |= POLLOUT | POLLWRNORM | POLLWRBAND;
return mask;
}
struct af_alg_async_req *af_alg_alloc_areq(struct sock *sk,
unsigned int areqlen)
{
struct af_alg_async_req *areq = sock_kmalloc(sk, areqlen, GFP_KERNEL);
if (unlikely(!areq))
return ERR_PTR(-ENOMEM);
areq->areqlen = areqlen;
areq->sk = sk;
areq->last_rsgl = NULL;
INIT_LIST_HEAD(&areq->rsgl_list);
areq->tsgl = NULL;
areq->tsgl_entries = 0;
return areq;
}
int af_alg_get_rsgl(struct sock *sk, struct msghdr *msg, int flags,
struct af_alg_async_req *areq, size_t maxsize,
size_t *outlen)
{
struct alg_sock *ask = alg_sk(sk);
struct af_alg_ctx *ctx = ask->private;
size_t len = 0;
while (maxsize > len && msg_data_left(msg)) {
struct af_alg_rsgl *rsgl;
size_t seglen;
int err;
if (!af_alg_readable(sk))
break;
if (!ctx->used) {
err = af_alg_wait_for_data(sk, flags);
if (err)
return err;
}
seglen = min_t(size_t, (maxsize - len),
msg_data_left(msg));
if (list_empty(&areq->rsgl_list)) {
rsgl = &areq->first_rsgl;
} else {
rsgl = sock_kmalloc(sk, sizeof(*rsgl), GFP_KERNEL);
if (unlikely(!rsgl))
return -ENOMEM;
}
rsgl->sgl.npages = 0;
list_add_tail(&rsgl->list, &areq->rsgl_list);
err = af_alg_make_sg(&rsgl->sgl, &msg->msg_iter, seglen);
if (err < 0)
return err;
if (areq->last_rsgl)
af_alg_link_sg(&areq->last_rsgl->sgl, &rsgl->sgl);
areq->last_rsgl = rsgl;
len += err;
ctx->rcvused += err;
rsgl->sg_num_bytes = err;
iov_iter_advance(&msg->msg_iter, err);
}
*outlen = len;
return 0;
}
static int __init af_alg_init(void)
{
int err = proto_register(&alg_proto, 0);
if (err)
goto out;
err = sock_register(&alg_family);
if (err != 0)
goto out_unregister_proto;
out:
return err;
out_unregister_proto:
proto_unregister(&alg_proto);
goto out;
}
static void __exit af_alg_exit(void)
{
sock_unregister(PF_ALG);
proto_unregister(&alg_proto);
}
