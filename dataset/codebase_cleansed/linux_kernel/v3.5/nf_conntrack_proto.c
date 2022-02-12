static int
nf_ct_register_sysctl(struct ctl_table_header **header, const char *path,
struct ctl_table *table, unsigned int *users)
{
if (*header == NULL) {
*header = register_net_sysctl(&init_net, path, table);
if (*header == NULL)
return -ENOMEM;
}
if (users != NULL)
(*users)++;
return 0;
}
static void
nf_ct_unregister_sysctl(struct ctl_table_header **header,
struct ctl_table *table, unsigned int *users)
{
if (users != NULL && --*users > 0)
return;
unregister_net_sysctl_table(*header);
*header = NULL;
}
struct nf_conntrack_l4proto *
__nf_ct_l4proto_find(u_int16_t l3proto, u_int8_t l4proto)
{
if (unlikely(l3proto >= AF_MAX || nf_ct_protos[l3proto] == NULL))
return &nf_conntrack_l4proto_generic;
return rcu_dereference(nf_ct_protos[l3proto][l4proto]);
}
struct nf_conntrack_l3proto *
nf_ct_l3proto_find_get(u_int16_t l3proto)
{
struct nf_conntrack_l3proto *p;
rcu_read_lock();
p = __nf_ct_l3proto_find(l3proto);
if (!try_module_get(p->me))
p = &nf_conntrack_l3proto_generic;
rcu_read_unlock();
return p;
}
void nf_ct_l3proto_put(struct nf_conntrack_l3proto *p)
{
module_put(p->me);
}
int
nf_ct_l3proto_try_module_get(unsigned short l3proto)
{
int ret;
struct nf_conntrack_l3proto *p;
retry: p = nf_ct_l3proto_find_get(l3proto);
if (p == &nf_conntrack_l3proto_generic) {
ret = request_module("nf_conntrack-%d", l3proto);
if (!ret)
goto retry;
return -EPROTOTYPE;
}
return 0;
}
void nf_ct_l3proto_module_put(unsigned short l3proto)
{
struct nf_conntrack_l3proto *p;
rcu_read_lock();
p = __nf_ct_l3proto_find(l3proto);
module_put(p->me);
rcu_read_unlock();
}
struct nf_conntrack_l4proto *
nf_ct_l4proto_find_get(u_int16_t l3num, u_int8_t l4num)
{
struct nf_conntrack_l4proto *p;
rcu_read_lock();
p = __nf_ct_l4proto_find(l3num, l4num);
if (!try_module_get(p->me))
p = &nf_conntrack_l4proto_generic;
rcu_read_unlock();
return p;
}
void nf_ct_l4proto_put(struct nf_conntrack_l4proto *p)
{
module_put(p->me);
}
static int kill_l3proto(struct nf_conn *i, void *data)
{
return nf_ct_l3num(i) == ((struct nf_conntrack_l3proto *)data)->l3proto;
}
static int kill_l4proto(struct nf_conn *i, void *data)
{
struct nf_conntrack_l4proto *l4proto;
l4proto = (struct nf_conntrack_l4proto *)data;
return nf_ct_protonum(i) == l4proto->l4proto &&
nf_ct_l3num(i) == l4proto->l3proto;
}
static int nf_ct_l3proto_register_sysctl(struct nf_conntrack_l3proto *l3proto)
{
int err = 0;
#ifdef CONFIG_SYSCTL
if (l3proto->ctl_table != NULL) {
err = nf_ct_register_sysctl(&l3proto->ctl_table_header,
l3proto->ctl_table_path,
l3proto->ctl_table, NULL);
}
#endif
return err;
}
static void nf_ct_l3proto_unregister_sysctl(struct nf_conntrack_l3proto *l3proto)
{
#ifdef CONFIG_SYSCTL
if (l3proto->ctl_table_header != NULL)
nf_ct_unregister_sysctl(&l3proto->ctl_table_header,
l3proto->ctl_table, NULL);
#endif
}
int nf_conntrack_l3proto_register(struct nf_conntrack_l3proto *proto)
{
int ret = 0;
struct nf_conntrack_l3proto *old;
if (proto->l3proto >= AF_MAX)
return -EBUSY;
if (proto->tuple_to_nlattr && !proto->nlattr_tuple_size)
return -EINVAL;
mutex_lock(&nf_ct_proto_mutex);
old = rcu_dereference_protected(nf_ct_l3protos[proto->l3proto],
lockdep_is_held(&nf_ct_proto_mutex));
if (old != &nf_conntrack_l3proto_generic) {
ret = -EBUSY;
goto out_unlock;
}
ret = nf_ct_l3proto_register_sysctl(proto);
if (ret < 0)
goto out_unlock;
if (proto->nlattr_tuple_size)
proto->nla_size = 3 * proto->nlattr_tuple_size();
rcu_assign_pointer(nf_ct_l3protos[proto->l3proto], proto);
out_unlock:
mutex_unlock(&nf_ct_proto_mutex);
return ret;
}
void nf_conntrack_l3proto_unregister(struct nf_conntrack_l3proto *proto)
{
struct net *net;
BUG_ON(proto->l3proto >= AF_MAX);
mutex_lock(&nf_ct_proto_mutex);
BUG_ON(rcu_dereference_protected(nf_ct_l3protos[proto->l3proto],
lockdep_is_held(&nf_ct_proto_mutex)
) != proto);
rcu_assign_pointer(nf_ct_l3protos[proto->l3proto],
&nf_conntrack_l3proto_generic);
nf_ct_l3proto_unregister_sysctl(proto);
mutex_unlock(&nf_ct_proto_mutex);
synchronize_rcu();
rtnl_lock();
for_each_net(net)
nf_ct_iterate_cleanup(net, kill_l3proto, proto);
rtnl_unlock();
}
static int nf_ct_l4proto_register_sysctl(struct nf_conntrack_l4proto *l4proto)
{
int err = 0;
#ifdef CONFIG_SYSCTL
if (l4proto->ctl_table != NULL) {
err = nf_ct_register_sysctl(l4proto->ctl_table_header,
"net/netfilter",
l4proto->ctl_table,
l4proto->ctl_table_users);
if (err < 0)
goto out;
}
#ifdef CONFIG_NF_CONNTRACK_PROC_COMPAT
if (l4proto->ctl_compat_table != NULL) {
err = nf_ct_register_sysctl(&l4proto->ctl_compat_table_header,
"net/ipv4/netfilter",
l4proto->ctl_compat_table, NULL);
if (err == 0)
goto out;
nf_ct_unregister_sysctl(l4proto->ctl_table_header,
l4proto->ctl_table,
l4proto->ctl_table_users);
}
#endif
out:
#endif
return err;
}
static void nf_ct_l4proto_unregister_sysctl(struct nf_conntrack_l4proto *l4proto)
{
#ifdef CONFIG_SYSCTL
if (l4proto->ctl_table_header != NULL &&
*l4proto->ctl_table_header != NULL)
nf_ct_unregister_sysctl(l4proto->ctl_table_header,
l4proto->ctl_table,
l4proto->ctl_table_users);
#ifdef CONFIG_NF_CONNTRACK_PROC_COMPAT
if (l4proto->ctl_compat_table_header != NULL)
nf_ct_unregister_sysctl(&l4proto->ctl_compat_table_header,
l4proto->ctl_compat_table, NULL);
#endif
#endif
}
int nf_conntrack_l4proto_register(struct nf_conntrack_l4proto *l4proto)
{
int ret = 0;
if (l4proto->l3proto >= PF_MAX)
return -EBUSY;
if ((l4proto->to_nlattr && !l4proto->nlattr_size)
|| (l4proto->tuple_to_nlattr && !l4proto->nlattr_tuple_size))
return -EINVAL;
mutex_lock(&nf_ct_proto_mutex);
if (!nf_ct_protos[l4proto->l3proto]) {
struct nf_conntrack_l4proto __rcu **proto_array;
int i;
proto_array = kmalloc(MAX_NF_CT_PROTO *
sizeof(struct nf_conntrack_l4proto *),
GFP_KERNEL);
if (proto_array == NULL) {
ret = -ENOMEM;
goto out_unlock;
}
for (i = 0; i < MAX_NF_CT_PROTO; i++)
RCU_INIT_POINTER(proto_array[i], &nf_conntrack_l4proto_generic);
smp_wmb();
nf_ct_protos[l4proto->l3proto] = proto_array;
} else if (rcu_dereference_protected(
nf_ct_protos[l4proto->l3proto][l4proto->l4proto],
lockdep_is_held(&nf_ct_proto_mutex)
) != &nf_conntrack_l4proto_generic) {
ret = -EBUSY;
goto out_unlock;
}
ret = nf_ct_l4proto_register_sysctl(l4proto);
if (ret < 0)
goto out_unlock;
l4proto->nla_size = 0;
if (l4proto->nlattr_size)
l4proto->nla_size += l4proto->nlattr_size();
if (l4proto->nlattr_tuple_size)
l4proto->nla_size += 3 * l4proto->nlattr_tuple_size();
rcu_assign_pointer(nf_ct_protos[l4proto->l3proto][l4proto->l4proto],
l4proto);
out_unlock:
mutex_unlock(&nf_ct_proto_mutex);
return ret;
}
void nf_conntrack_l4proto_unregister(struct nf_conntrack_l4proto *l4proto)
{
struct net *net;
BUG_ON(l4proto->l3proto >= PF_MAX);
mutex_lock(&nf_ct_proto_mutex);
BUG_ON(rcu_dereference_protected(
nf_ct_protos[l4proto->l3proto][l4proto->l4proto],
lockdep_is_held(&nf_ct_proto_mutex)
) != l4proto);
rcu_assign_pointer(nf_ct_protos[l4proto->l3proto][l4proto->l4proto],
&nf_conntrack_l4proto_generic);
nf_ct_l4proto_unregister_sysctl(l4proto);
mutex_unlock(&nf_ct_proto_mutex);
synchronize_rcu();
rtnl_lock();
for_each_net(net)
nf_ct_iterate_cleanup(net, kill_l4proto, l4proto);
rtnl_unlock();
}
int nf_conntrack_proto_init(void)
{
unsigned int i;
int err;
err = nf_ct_l4proto_register_sysctl(&nf_conntrack_l4proto_generic);
if (err < 0)
return err;
for (i = 0; i < AF_MAX; i++)
rcu_assign_pointer(nf_ct_l3protos[i],
&nf_conntrack_l3proto_generic);
return 0;
}
void nf_conntrack_proto_fini(void)
{
unsigned int i;
nf_ct_l4proto_unregister_sysctl(&nf_conntrack_l4proto_generic);
for (i = 0; i < PF_MAX; i++)
kfree(nf_ct_protos[i]);
}
