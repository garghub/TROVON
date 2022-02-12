static int rng_recvmsg(struct kiocb *unused, struct socket *sock,
struct msghdr *msg, size_t len, int flags)
{
struct sock *sk = sock->sk;
struct alg_sock *ask = alg_sk(sk);
struct rng_ctx *ctx = ask->private;
int err = -EFAULT;
int genlen = 0;
u8 result[MAXSIZE];
if (len == 0)
return 0;
if (len > MAXSIZE)
len = MAXSIZE;
memset(result, 0, len);
genlen = crypto_rng_get_bytes(ctx->drng, result, len);
if (genlen < 0)
return genlen;
err = memcpy_to_msg(msg, result, len);
memzero_explicit(result, genlen);
return err ? err : len;
}
static void *rng_bind(const char *name, u32 type, u32 mask)
{
return crypto_alloc_rng(name, type, mask);
}
static void rng_release(void *private)
{
crypto_free_rng(private);
}
static void rng_sock_destruct(struct sock *sk)
{
struct alg_sock *ask = alg_sk(sk);
struct rng_ctx *ctx = ask->private;
sock_kfree_s(sk, ctx, ctx->len);
af_alg_release_parent(sk);
}
static int rng_accept_parent(void *private, struct sock *sk)
{
struct rng_ctx *ctx;
struct alg_sock *ask = alg_sk(sk);
unsigned int len = sizeof(*ctx);
ctx = sock_kmalloc(sk, len, GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->len = len;
ctx->drng = private;
ask->private = ctx;
sk->sk_destruct = rng_sock_destruct;
return 0;
}
static int rng_setkey(void *private, const u8 *seed, unsigned int seedlen)
{
return crypto_rng_reset(private, (u8 *)seed, seedlen);
}
static int __init rng_init(void)
{
return af_alg_register_type(&algif_type_rng);
}
static void __exit rng_exit(void)
{
int err = af_alg_unregister_type(&algif_type_rng);
BUG_ON(err);
}
