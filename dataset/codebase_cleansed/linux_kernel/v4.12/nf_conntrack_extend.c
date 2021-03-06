void nf_ct_ext_destroy(struct nf_conn *ct)
{
unsigned int i;
struct nf_ct_ext_type *t;
for (i = 0; i < NF_CT_EXT_NUM; i++) {
rcu_read_lock();
t = rcu_dereference(nf_ct_ext_types[i]);
if (t && t->destroy)
t->destroy(ct);
rcu_read_unlock();
}
}
void *nf_ct_ext_add(struct nf_conn *ct, enum nf_ct_ext_id id, gfp_t gfp)
{
unsigned int newlen, newoff, oldlen, alloc;
struct nf_ct_ext *old, *new;
struct nf_ct_ext_type *t;
NF_CT_ASSERT(!nf_ct_is_confirmed(ct));
old = ct->ext;
if (old) {
if (__nf_ct_ext_exist(old, id))
return NULL;
oldlen = old->len;
} else {
oldlen = sizeof(*new);
}
rcu_read_lock();
t = rcu_dereference(nf_ct_ext_types[id]);
if (!t) {
rcu_read_unlock();
return NULL;
}
newoff = ALIGN(oldlen, t->align);
newlen = newoff + t->len;
rcu_read_unlock();
alloc = max(newlen, NF_CT_EXT_PREALLOC);
new = __krealloc(old, alloc, gfp);
if (!new)
return NULL;
if (!old) {
memset(new->offset, 0, sizeof(new->offset));
ct->ext = new;
} else if (new != old) {
kfree_rcu(old, rcu);
rcu_assign_pointer(ct->ext, new);
}
new->offset[id] = newoff;
new->len = newlen;
memset((void *)new + newoff, 0, newlen - newoff);
return (void *)new + newoff;
}
int nf_ct_extend_register(const struct nf_ct_ext_type *type)
{
int ret = 0;
mutex_lock(&nf_ct_ext_type_mutex);
if (nf_ct_ext_types[type->id]) {
ret = -EBUSY;
goto out;
}
rcu_assign_pointer(nf_ct_ext_types[type->id], type);
out:
mutex_unlock(&nf_ct_ext_type_mutex);
return ret;
}
void nf_ct_extend_unregister(const struct nf_ct_ext_type *type)
{
mutex_lock(&nf_ct_ext_type_mutex);
RCU_INIT_POINTER(nf_ct_ext_types[type->id], NULL);
mutex_unlock(&nf_ct_ext_type_mutex);
synchronize_rcu();
}
