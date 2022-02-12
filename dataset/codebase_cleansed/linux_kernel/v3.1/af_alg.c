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
static int alg_bind(struct socket *sock, struct sockaddr *uaddr, int addr_len)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct sockaddr_alg *sa = (void *)uaddr;
const struct af_alg_type *type;
void *private;
if (sock->state == SS_CONNECTED)
return -EINVAL;
if (addr_len != sizeof(*sa))
return -EINVAL;
sa->salg_type[sizeof(sa->salg_type) - 1] = 0;
sa->salg_name[sizeof(sa->salg_name) - 1] = 0;
type = alg_get_type(sa->salg_type);
if (IS_ERR(type) && PTR_ERR(type) == -ENOENT) {
request_module("algif-%s", sa->salg_type);
type = alg_get_type(sa->salg_type);
}
if (IS_ERR(type))
return PTR_ERR(type);
private = type->bind(sa->salg_name, sa->salg_feat, sa->salg_mask);
if (IS_ERR(private)) {
module_put(type->owner);
return PTR_ERR(private);
}
lock_sock(sk);
swap(ask->type, type);
swap(ask->private, private);
release_sock(sk);
alg_do_release(type, private);
return 0;
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
sock_kfree_s(sk, key, keylen);
return err;
}
static int alg_setsockopt(struct socket *sock, int level, int optname,
char __user *optval, unsigned int optlen)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
const struct af_alg_type *type;
int err = -ENOPROTOOPT;
lock_sock(sk);
type = ask->type;
if (level != SOL_ALG || !type)
goto unlock;
switch (optname) {
case ALG_SET_KEY:
if (sock->state == SS_CONNECTED)
goto unlock;
if (!type->setkey)
goto unlock;
err = alg_setkey(sk, optval, optlen);
}
unlock:
release_sock(sk);
return err;
}
int af_alg_accept(struct sock *sk, struct socket *newsock)
{
struct alg_sock *ask = alg_sk(sk);
const struct af_alg_type *type;
struct sock *sk2;
int err;
lock_sock(sk);
type = ask->type;
err = -EINVAL;
if (!type)
goto unlock;
sk2 = sk_alloc(sock_net(sk), PF_ALG, GFP_KERNEL, &alg_proto);
err = -ENOMEM;
if (!sk2)
goto unlock;
sock_init_data(newsock, sk2);
sock_graft(sk2, newsock);
err = type->accept(ask->private, sk2);
if (err) {
sk_free(sk2);
goto unlock;
}
sk2->sk_family = PF_ALG;
sock_hold(sk);
alg_sk(sk2)->parent = sk;
alg_sk(sk2)->type = type;
newsock->ops = type->ops;
newsock->state = SS_CONNECTED;
err = 0;
unlock:
release_sock(sk);
return err;
}
static int alg_accept(struct socket *sock, struct socket *newsock, int flags)
{
return af_alg_accept(sock->sk, newsock);
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
sk = sk_alloc(net, PF_ALG, GFP_KERNEL, &alg_proto);
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
int af_alg_make_sg(struct af_alg_sgl *sgl, void __user *addr, int len,
int write)
{
unsigned long from = (unsigned long)addr;
unsigned long npages;
unsigned off;
int err;
int i;
err = -EFAULT;
if (!access_ok(write ? VERIFY_READ : VERIFY_WRITE, addr, len))
goto out;
off = from & ~PAGE_MASK;
npages = (off + len + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (npages > ALG_MAX_PAGES)
npages = ALG_MAX_PAGES;
err = get_user_pages_fast(from, npages, write, sgl->pages);
if (err < 0)
goto out;
npages = err;
err = -EINVAL;
if (WARN_ON(npages == 0))
goto out;
err = 0;
sg_init_table(sgl->sg, npages);
for (i = 0; i < npages; i++) {
int plen = min_t(int, len, PAGE_SIZE - off);
sg_set_page(sgl->sg + i, sgl->pages[i], plen, off);
off = 0;
len -= plen;
err += plen;
}
out:
return err;
}
void af_alg_free_sg(struct af_alg_sgl *sgl)
{
int i;
i = 0;
do {
put_page(sgl->pages[i]);
} while (!sg_is_last(sgl->sg + (i++)));
}
int af_alg_cmsg_send(struct msghdr *msg, struct af_alg_control *con)
{
struct cmsghdr *cmsg;
for (cmsg = CMSG_FIRSTHDR(msg); cmsg; cmsg = CMSG_NXTHDR(msg, cmsg)) {
if (!CMSG_OK(msg, cmsg))
return -EINVAL;
if (cmsg->cmsg_level != SOL_ALG)
continue;
switch(cmsg->cmsg_type) {
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
INIT_COMPLETION(completion->completion);
err = completion->err;
break;
};
return err;
}
void af_alg_complete(struct crypto_async_request *req, int err)
{
struct af_alg_completion *completion = req->data;
completion->err = err;
complete(&completion->completion);
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
