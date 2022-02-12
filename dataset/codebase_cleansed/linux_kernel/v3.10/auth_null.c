static struct rpc_auth *
nul_create(struct rpc_clnt *clnt, rpc_authflavor_t flavor)
{
atomic_inc(&null_auth.au_count);
return &null_auth;
}
static void
nul_destroy(struct rpc_auth *auth)
{
}
static struct rpc_cred *
nul_lookup_cred(struct rpc_auth *auth, struct auth_cred *acred, int flags)
{
return get_rpccred(&null_cred);
}
static void
nul_destroy_cred(struct rpc_cred *cred)
{
}
static int
nul_match(struct auth_cred *acred, struct rpc_cred *cred, int taskflags)
{
return 1;
}
static __be32 *
nul_marshal(struct rpc_task *task, __be32 *p)
{
*p++ = htonl(RPC_AUTH_NULL);
*p++ = 0;
*p++ = htonl(RPC_AUTH_NULL);
*p++ = 0;
return p;
}
static int
nul_refresh(struct rpc_task *task)
{
set_bit(RPCAUTH_CRED_UPTODATE, &task->tk_rqstp->rq_cred->cr_flags);
return 0;
}
static __be32 *
nul_validate(struct rpc_task *task, __be32 *p)
{
rpc_authflavor_t flavor;
u32 size;
flavor = ntohl(*p++);
if (flavor != RPC_AUTH_NULL) {
printk("RPC: bad verf flavor: %u\n", flavor);
return NULL;
}
size = ntohl(*p++);
if (size != 0) {
printk("RPC: bad verf size: %u\n", size);
return NULL;
}
return p;
}
