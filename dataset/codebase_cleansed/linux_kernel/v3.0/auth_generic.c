struct rpc_cred *rpc_lookup_cred(void)
{
return rpcauth_lookupcred(&generic_auth, 0);
}
struct rpc_cred *rpc_lookup_machine_cred(void)
{
struct auth_cred acred = {
.uid = RPC_MACHINE_CRED_USERID,
.gid = RPC_MACHINE_CRED_GROUPID,
.machine_cred = 1,
};
dprintk("RPC: looking up machine cred\n");
return generic_auth.au_ops->lookup_cred(&generic_auth, &acred, 0);
}
static struct rpc_cred *generic_bind_cred(struct rpc_task *task,
struct rpc_cred *cred, int lookupflags)
{
struct rpc_auth *auth = task->tk_client->cl_auth;
struct auth_cred *acred = &container_of(cred, struct generic_cred, gc_base)->acred;
return auth->au_ops->lookup_cred(auth, acred, lookupflags);
}
static struct rpc_cred *
generic_lookup_cred(struct rpc_auth *auth, struct auth_cred *acred, int flags)
{
return rpcauth_lookup_credcache(&generic_auth, acred, flags);
}
static struct rpc_cred *
generic_create_cred(struct rpc_auth *auth, struct auth_cred *acred, int flags)
{
struct generic_cred *gcred;
gcred = kmalloc(sizeof(*gcred), GFP_KERNEL);
if (gcred == NULL)
return ERR_PTR(-ENOMEM);
rpcauth_init_cred(&gcred->gc_base, acred, &generic_auth, &generic_credops);
gcred->gc_base.cr_flags = 1UL << RPCAUTH_CRED_UPTODATE;
gcred->acred.uid = acred->uid;
gcred->acred.gid = acred->gid;
gcred->acred.group_info = acred->group_info;
if (gcred->acred.group_info != NULL)
get_group_info(gcred->acred.group_info);
gcred->acred.machine_cred = acred->machine_cred;
dprintk("RPC: allocated %s cred %p for uid %d gid %d\n",
gcred->acred.machine_cred ? "machine" : "generic",
gcred, acred->uid, acred->gid);
return &gcred->gc_base;
}
static void
generic_free_cred(struct rpc_cred *cred)
{
struct generic_cred *gcred = container_of(cred, struct generic_cred, gc_base);
dprintk("RPC: generic_free_cred %p\n", gcred);
if (gcred->acred.group_info != NULL)
put_group_info(gcred->acred.group_info);
kfree(gcred);
}
static void
generic_free_cred_callback(struct rcu_head *head)
{
struct rpc_cred *cred = container_of(head, struct rpc_cred, cr_rcu);
generic_free_cred(cred);
}
static void
generic_destroy_cred(struct rpc_cred *cred)
{
call_rcu(&cred->cr_rcu, generic_free_cred_callback);
}
static int
generic_match(struct auth_cred *acred, struct rpc_cred *cred, int flags)
{
struct generic_cred *gcred = container_of(cred, struct generic_cred, gc_base);
int i;
if (gcred->acred.uid != acred->uid ||
gcred->acred.gid != acred->gid ||
gcred->acred.machine_cred != acred->machine_cred)
goto out_nomatch;
if (gcred->acred.group_info == acred->group_info)
goto out_match;
if (gcred->acred.group_info->ngroups != acred->group_info->ngroups)
goto out_nomatch;
for (i = 0; i < gcred->acred.group_info->ngroups; i++) {
if (GROUP_AT(gcred->acred.group_info, i) !=
GROUP_AT(acred->group_info, i))
goto out_nomatch;
}
out_match:
return 1;
out_nomatch:
return 0;
}
int __init rpc_init_generic_auth(void)
{
return rpcauth_init_credcache(&generic_auth);
}
void rpc_destroy_generic_auth(void)
{
rpcauth_destroy_credcache(&generic_auth);
}
