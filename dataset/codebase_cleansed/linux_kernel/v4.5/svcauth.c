int
svc_authenticate(struct svc_rqst *rqstp, __be32 *authp)
{
rpc_authflavor_t flavor;
struct auth_ops *aops;
*authp = rpc_auth_ok;
flavor = svc_getnl(&rqstp->rq_arg.head[0]);
dprintk("svc: svc_authenticate (%d)\n", flavor);
spin_lock(&authtab_lock);
if (flavor >= RPC_AUTH_MAXFLAVOR || !(aops = authtab[flavor]) ||
!try_module_get(aops->owner)) {
spin_unlock(&authtab_lock);
*authp = rpc_autherr_badcred;
return SVC_DENIED;
}
spin_unlock(&authtab_lock);
rqstp->rq_auth_slack = 0;
init_svc_cred(&rqstp->rq_cred);
rqstp->rq_authop = aops;
return aops->accept(rqstp, authp);
}
int svc_set_client(struct svc_rqst *rqstp)
{
rqstp->rq_client = NULL;
return rqstp->rq_authop->set_client(rqstp);
}
int svc_authorise(struct svc_rqst *rqstp)
{
struct auth_ops *aops = rqstp->rq_authop;
int rv = 0;
rqstp->rq_authop = NULL;
if (aops) {
rv = aops->release(rqstp);
module_put(aops->owner);
}
return rv;
}
int
svc_auth_register(rpc_authflavor_t flavor, struct auth_ops *aops)
{
int rv = -EINVAL;
spin_lock(&authtab_lock);
if (flavor < RPC_AUTH_MAXFLAVOR && authtab[flavor] == NULL) {
authtab[flavor] = aops;
rv = 0;
}
spin_unlock(&authtab_lock);
return rv;
}
void
svc_auth_unregister(rpc_authflavor_t flavor)
{
spin_lock(&authtab_lock);
if (flavor < RPC_AUTH_MAXFLAVOR)
authtab[flavor] = NULL;
spin_unlock(&authtab_lock);
}
void auth_domain_put(struct auth_domain *dom)
{
if (atomic_dec_and_lock(&dom->ref.refcount, &auth_domain_lock)) {
hlist_del(&dom->hash);
dom->flavour->domain_release(dom);
spin_unlock(&auth_domain_lock);
}
}
struct auth_domain *
auth_domain_lookup(char *name, struct auth_domain *new)
{
struct auth_domain *hp;
struct hlist_head *head;
head = &auth_domain_table[hash_str(name, DN_HASHBITS)];
spin_lock(&auth_domain_lock);
hlist_for_each_entry(hp, head, hash) {
if (strcmp(hp->name, name)==0) {
kref_get(&hp->ref);
spin_unlock(&auth_domain_lock);
return hp;
}
}
if (new)
hlist_add_head(&new->hash, head);
spin_unlock(&auth_domain_lock);
return new;
}
struct auth_domain *auth_domain_find(char *name)
{
return auth_domain_lookup(name, NULL);
}
