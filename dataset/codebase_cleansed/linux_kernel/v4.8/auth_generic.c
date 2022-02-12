struct rpc_cred *rpc_lookup_cred(void)
{
return rpcauth_lookupcred(&generic_auth, 0);
}
struct rpc_cred *
rpc_lookup_generic_cred(struct auth_cred *acred, int flags, gfp_t gfp)
{
return rpcauth_lookup_credcache(&generic_auth, acred, flags, gfp);
}
struct rpc_cred *rpc_lookup_cred_nonblock(void)
{
return rpcauth_lookupcred(&generic_auth, RPCAUTH_LOOKUP_RCU);
}
struct rpc_cred *rpc_lookup_machine_cred(const char *service_name)
{
struct auth_cred acred = {
.uid = RPC_MACHINE_CRED_USERID,
.gid = RPC_MACHINE_CRED_GROUPID,
.principal = service_name,
.machine_cred = 1,
};
dprintk("RPC: looking up machine cred for service %s\n",
service_name);
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
return rpcauth_lookup_credcache(&generic_auth, acred, flags, GFP_KERNEL);
}
static struct rpc_cred *
generic_create_cred(struct rpc_auth *auth, struct auth_cred *acred, int flags, gfp_t gfp)
{
struct generic_cred *gcred;
gcred = kmalloc(sizeof(*gcred), gfp);
if (gcred == NULL)
return ERR_PTR(-ENOMEM);
rpcauth_init_cred(&gcred->gc_base, acred, &generic_auth, &generic_credops);
gcred->gc_base.cr_flags = 1UL << RPCAUTH_CRED_UPTODATE;
gcred->acred.uid = acred->uid;
gcred->acred.gid = acred->gid;
gcred->acred.group_info = acred->group_info;
gcred->acred.ac_flags = 0;
if (gcred->acred.group_info != NULL)
get_group_info(gcred->acred.group_info);
gcred->acred.machine_cred = acred->machine_cred;
gcred->acred.principal = acred->principal;
dprintk("RPC: allocated %s cred %p for uid %d gid %d\n",
gcred->acred.machine_cred ? "machine" : "generic",
gcred,
from_kuid(&init_user_ns, acred->uid),
from_kgid(&init_user_ns, acred->gid));
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
machine_cred_match(struct auth_cred *acred, struct generic_cred *gcred, int flags)
{
if (!gcred->acred.machine_cred ||
gcred->acred.principal != acred->principal ||
!uid_eq(gcred->acred.uid, acred->uid) ||
!gid_eq(gcred->acred.gid, acred->gid))
return 0;
return 1;
}
static int
generic_match(struct auth_cred *acred, struct rpc_cred *cred, int flags)
{
struct generic_cred *gcred = container_of(cred, struct generic_cred, gc_base);
int i;
if (acred->machine_cred)
return machine_cred_match(acred, gcred, flags);
if (!uid_eq(gcred->acred.uid, acred->uid) ||
!gid_eq(gcred->acred.gid, acred->gid) ||
gcred->acred.machine_cred != 0)
goto out_nomatch;
if (gcred->acred.group_info == acred->group_info)
goto out_match;
if (gcred->acred.group_info->ngroups != acred->group_info->ngroups)
goto out_nomatch;
for (i = 0; i < gcred->acred.group_info->ngroups; i++) {
if (!gid_eq(GROUP_AT(gcred->acred.group_info, i),
GROUP_AT(acred->group_info, i)))
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
static int
generic_key_timeout(struct rpc_auth *auth, struct rpc_cred *cred)
{
struct auth_cred *acred = &container_of(cred, struct generic_cred,
gc_base)->acred;
struct rpc_cred *tcred;
int ret = 0;
if (auth->au_flags & RPCAUTH_AUTH_NO_CRKEY_TIMEOUT)
return 0;
if (test_bit(RPC_CRED_NOTIFY_TIMEOUT, &acred->ac_flags))
return 0;
tcred = auth->au_ops->lookup_cred(auth, acred, 0);
if (IS_ERR(tcred))
return -EACCES;
ret = tcred->cr_ops->crkey_timeout(tcred);
if (ret != 0) {
set_bit(RPC_CRED_KEY_EXPIRE_SOON, &acred->ac_flags);
ret = 0;
} else {
if (test_and_clear_bit(RPC_CRED_KEY_EXPIRE_SOON,
&acred->ac_flags))
dprintk("RPC: UID %d Credential key reset\n",
from_kuid(&init_user_ns, tcred->cr_uid));
set_bit(RPC_CRED_NOTIFY_TIMEOUT, &acred->ac_flags);
}
put_rpccred(tcred);
return ret;
}
static bool generic_key_to_expire(struct rpc_cred *cred)
{
struct auth_cred *acred = &container_of(cred, struct generic_cred,
gc_base)->acred;
bool ret;
get_rpccred(cred);
ret = test_bit(RPC_CRED_KEY_EXPIRE_SOON, &acred->ac_flags);
put_rpccred(cred);
return ret;
}
