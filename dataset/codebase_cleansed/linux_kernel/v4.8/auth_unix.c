static struct rpc_auth *
unx_create(struct rpc_auth_create_args *args, struct rpc_clnt *clnt)
{
dprintk("RPC: creating UNIX authenticator for client %p\n",
clnt);
atomic_inc(&unix_auth.au_count);
return &unix_auth;
}
static void
unx_destroy(struct rpc_auth *auth)
{
dprintk("RPC: destroying UNIX authenticator %p\n", auth);
rpcauth_clear_credcache(auth->au_credcache);
}
static struct rpc_cred *
unx_lookup_cred(struct rpc_auth *auth, struct auth_cred *acred, int flags)
{
return rpcauth_lookup_credcache(auth, acred, flags, GFP_NOFS);
}
static struct rpc_cred *
unx_create_cred(struct rpc_auth *auth, struct auth_cred *acred, int flags, gfp_t gfp)
{
struct unx_cred *cred;
unsigned int groups = 0;
unsigned int i;
dprintk("RPC: allocating UNIX cred for uid %d gid %d\n",
from_kuid(&init_user_ns, acred->uid),
from_kgid(&init_user_ns, acred->gid));
if (!(cred = kmalloc(sizeof(*cred), gfp)))
return ERR_PTR(-ENOMEM);
rpcauth_init_cred(&cred->uc_base, acred, auth, &unix_credops);
cred->uc_base.cr_flags = 1UL << RPCAUTH_CRED_UPTODATE;
if (acred->group_info != NULL)
groups = acred->group_info->ngroups;
if (groups > NFS_NGROUPS)
groups = NFS_NGROUPS;
cred->uc_gid = acred->gid;
for (i = 0; i < groups; i++)
cred->uc_gids[i] = GROUP_AT(acred->group_info, i);
if (i < NFS_NGROUPS)
cred->uc_gids[i] = INVALID_GID;
return &cred->uc_base;
}
static void
unx_free_cred(struct unx_cred *unx_cred)
{
dprintk("RPC: unx_free_cred %p\n", unx_cred);
kfree(unx_cred);
}
static void
unx_free_cred_callback(struct rcu_head *head)
{
struct unx_cred *unx_cred = container_of(head, struct unx_cred, uc_base.cr_rcu);
unx_free_cred(unx_cred);
}
static void
unx_destroy_cred(struct rpc_cred *cred)
{
call_rcu(&cred->cr_rcu, unx_free_cred_callback);
}
static int
unx_match(struct auth_cred *acred, struct rpc_cred *rcred, int flags)
{
struct unx_cred *cred = container_of(rcred, struct unx_cred, uc_base);
unsigned int groups = 0;
unsigned int i;
if (!uid_eq(cred->uc_uid, acred->uid) || !gid_eq(cred->uc_gid, acred->gid))
return 0;
if (acred->group_info != NULL)
groups = acred->group_info->ngroups;
if (groups > NFS_NGROUPS)
groups = NFS_NGROUPS;
for (i = 0; i < groups ; i++)
if (!gid_eq(cred->uc_gids[i], GROUP_AT(acred->group_info, i)))
return 0;
if (groups < NFS_NGROUPS && gid_valid(cred->uc_gids[groups]))
return 0;
return 1;
}
static __be32 *
unx_marshal(struct rpc_task *task, __be32 *p)
{
struct rpc_clnt *clnt = task->tk_client;
struct unx_cred *cred = container_of(task->tk_rqstp->rq_cred, struct unx_cred, uc_base);
__be32 *base, *hold;
int i;
*p++ = htonl(RPC_AUTH_UNIX);
base = p++;
*p++ = htonl(jiffies/HZ);
p = xdr_encode_array(p, clnt->cl_nodename, clnt->cl_nodelen);
*p++ = htonl((u32) from_kuid(&init_user_ns, cred->uc_uid));
*p++ = htonl((u32) from_kgid(&init_user_ns, cred->uc_gid));
hold = p++;
for (i = 0; i < 16 && gid_valid(cred->uc_gids[i]); i++)
*p++ = htonl((u32) from_kgid(&init_user_ns, cred->uc_gids[i]));
*hold = htonl(p - hold - 1);
*base = htonl((p - base - 1) << 2);
*p++ = htonl(RPC_AUTH_NULL);
*p++ = htonl(0);
return p;
}
static int
unx_refresh(struct rpc_task *task)
{
set_bit(RPCAUTH_CRED_UPTODATE, &task->tk_rqstp->rq_cred->cr_flags);
return 0;
}
static __be32 *
unx_validate(struct rpc_task *task, __be32 *p)
{
rpc_authflavor_t flavor;
u32 size;
flavor = ntohl(*p++);
if (flavor != RPC_AUTH_NULL &&
flavor != RPC_AUTH_UNIX &&
flavor != RPC_AUTH_SHORT) {
printk("RPC: bad verf flavor: %u\n", flavor);
return ERR_PTR(-EIO);
}
size = ntohl(*p++);
if (size > RPC_MAX_AUTH_SIZE) {
printk("RPC: giant verf size: %u\n", size);
return ERR_PTR(-EIO);
}
task->tk_rqstp->rq_cred->cr_auth->au_rslack = (size >> 2) + 2;
p += (size >> 2);
return p;
}
int __init rpc_init_authunix(void)
{
return rpcauth_init_credcache(&unix_auth);
}
void rpc_destroy_authunix(void)
{
rpcauth_destroy_credcache(&unix_auth);
}
