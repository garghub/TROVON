static int
nf_ct_register_sysctl(struct net *net,
struct ctl_table_header **header,
const char *path,
struct ctl_table *table)
{
if (*header == NULL) {
*header = register_net_sysctl(net, path, table);
if (*header == NULL)
return -ENOMEM;
}
return 0;
}
static void
nf_ct_unregister_sysctl(struct ctl_table_header **header,
struct ctl_table **table,
unsigned int users)
{
if (users > 0)
return;
unregister_net_sysctl_table(*header);
kfree(*table);
*header = NULL;
*table = NULL;
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
int nf_ct_l3proto_register(struct nf_conntrack_l3proto *proto)
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
if (proto->nlattr_tuple_size)
proto->nla_size = 3 * proto->nlattr_tuple_size();
rcu_assign_pointer(nf_ct_l3protos[proto->l3proto], proto);
out_unlock:
mutex_unlock(&nf_ct_proto_mutex);
return ret;
}
int nf_ct_l3proto_pernet_register(struct net *net,
struct nf_conntrack_l3proto *proto)
{
int ret;
if (proto->init_net) {
ret = proto->init_net(net);
if (ret < 0)
return ret;
}
return 0;
}
void nf_ct_l3proto_unregister(struct nf_conntrack_l3proto *proto)
{
BUG_ON(proto->l3proto >= AF_MAX);
mutex_lock(&nf_ct_proto_mutex);
BUG_ON(rcu_dereference_protected(nf_ct_l3protos[proto->l3proto],
lockdep_is_held(&nf_ct_proto_mutex)
) != proto);
rcu_assign_pointer(nf_ct_l3protos[proto->l3proto],
&nf_conntrack_l3proto_generic);
mutex_unlock(&nf_ct_proto_mutex);
synchronize_rcu();
}
void nf_ct_l3proto_pernet_unregister(struct net *net,
struct nf_conntrack_l3proto *proto)
{
nf_ct_iterate_cleanup(net, kill_l3proto, proto, 0, 0);
}
static struct nf_proto_net *nf_ct_l4proto_net(struct net *net,
struct nf_conntrack_l4proto *l4proto)
{
if (l4proto->get_net_proto) {
return l4proto->get_net_proto(net);
} else if (l4proto->net_id) {
return net_generic(net, *l4proto->net_id);
}
return NULL;
}
static
int nf_ct_l4proto_register_sysctl(struct net *net,
struct nf_proto_net *pn,
struct nf_conntrack_l4proto *l4proto)
{
int err = 0;
#ifdef CONFIG_SYSCTL
if (pn->ctl_table != NULL) {
err = nf_ct_register_sysctl(net,
&pn->ctl_table_header,
"net/netfilter",
pn->ctl_table);
if (err < 0) {
if (!pn->users) {
kfree(pn->ctl_table);
pn->ctl_table = NULL;
}
}
}
#endif
return err;
}
static
void nf_ct_l4proto_unregister_sysctl(struct net *net,
struct nf_proto_net *pn,
struct nf_conntrack_l4proto *l4proto)
{
#ifdef CONFIG_SYSCTL
if (pn->ctl_table_header != NULL)
nf_ct_unregister_sysctl(&pn->ctl_table_header,
&pn->ctl_table,
pn->users);
#endif
}
int nf_ct_l4proto_register(struct nf_conntrack_l4proto *l4proto)
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
int nf_ct_l4proto_pernet_register(struct net *net,
struct nf_conntrack_l4proto *l4proto)
{
int ret = 0;
struct nf_proto_net *pn = NULL;
if (l4proto->init_net) {
ret = l4proto->init_net(net, l4proto->l3proto);
if (ret < 0)
goto out;
}
pn = nf_ct_l4proto_net(net, l4proto);
if (pn == NULL)
goto out;
ret = nf_ct_l4proto_register_sysctl(net, pn, l4proto);
if (ret < 0)
goto out;
pn->users++;
out:
return ret;
}
void nf_ct_l4proto_unregister(struct nf_conntrack_l4proto *l4proto)
{
BUG_ON(l4proto->l3proto >= PF_MAX);
mutex_lock(&nf_ct_proto_mutex);
BUG_ON(rcu_dereference_protected(
nf_ct_protos[l4proto->l3proto][l4proto->l4proto],
lockdep_is_held(&nf_ct_proto_mutex)
) != l4proto);
rcu_assign_pointer(nf_ct_protos[l4proto->l3proto][l4proto->l4proto],
&nf_conntrack_l4proto_generic);
mutex_unlock(&nf_ct_proto_mutex);
synchronize_rcu();
}
void nf_ct_l4proto_pernet_unregister(struct net *net,
struct nf_conntrack_l4proto *l4proto)
{
struct nf_proto_net *pn = NULL;
pn = nf_ct_l4proto_net(net, l4proto);
if (pn == NULL)
return;
pn->users--;
nf_ct_l4proto_unregister_sysctl(net, pn, l4proto);
nf_ct_iterate_cleanup(net, kill_l4proto, l4proto, 0, 0);
}
int nf_conntrack_proto_pernet_init(struct net *net)
{
int err;
struct nf_proto_net *pn = nf_ct_l4proto_net(net,
&nf_conntrack_l4proto_generic);
err = nf_conntrack_l4proto_generic.init_net(net,
nf_conntrack_l4proto_generic.l3proto);
if (err < 0)
return err;
err = nf_ct_l4proto_register_sysctl(net,
pn,
&nf_conntrack_l4proto_generic);
if (err < 0)
return err;
pn->users++;
return 0;
}
void nf_conntrack_proto_pernet_fini(struct net *net)
{
struct nf_proto_net *pn = nf_ct_l4proto_net(net,
&nf_conntrack_l4proto_generic);
pn->users--;
nf_ct_l4proto_unregister_sysctl(net,
pn,
&nf_conntrack_l4proto_generic);
}
int nf_conntrack_proto_init(void)
{
unsigned int i;
for (i = 0; i < AF_MAX; i++)
rcu_assign_pointer(nf_ct_l3protos[i],
&nf_conntrack_l3proto_generic);
return 0;
}
void nf_conntrack_proto_fini(void)
{
unsigned int i;
for (i = 0; i < PF_MAX; i++)
kfree(nf_ct_protos[i]);
}
