static int tcf_skbmod_run(struct sk_buff *skb, const struct tc_action *a,
struct tcf_result *res)
{
struct tcf_skbmod *d = to_skbmod(a);
int action;
struct tcf_skbmod_params *p;
u64 flags;
int err;
tcf_lastuse_update(&d->tcf_tm);
bstats_cpu_update(this_cpu_ptr(d->common.cpu_bstats), skb);
err = skb_ensure_writable(skb, MAX_EDIT_LEN);
if (unlikely(err)) {
qstats_overlimit_inc(this_cpu_ptr(d->common.cpu_qstats));
return TC_ACT_SHOT;
}
rcu_read_lock();
action = READ_ONCE(d->tcf_action);
if (unlikely(action == TC_ACT_SHOT)) {
qstats_overlimit_inc(this_cpu_ptr(d->common.cpu_qstats));
rcu_read_unlock();
return action;
}
p = rcu_dereference(d->skbmod_p);
flags = p->flags;
if (flags & SKBMOD_F_DMAC)
ether_addr_copy(eth_hdr(skb)->h_dest, p->eth_dst);
if (flags & SKBMOD_F_SMAC)
ether_addr_copy(eth_hdr(skb)->h_source, p->eth_src);
if (flags & SKBMOD_F_ETYPE)
eth_hdr(skb)->h_proto = p->eth_type;
rcu_read_unlock();
if (flags & SKBMOD_F_SWAPMAC) {
u16 tmpaddr[ETH_ALEN / 2];
ether_addr_copy((u8 *)tmpaddr, eth_hdr(skb)->h_dest);
ether_addr_copy(eth_hdr(skb)->h_dest, eth_hdr(skb)->h_source);
ether_addr_copy(eth_hdr(skb)->h_source, (u8 *)tmpaddr);
}
return action;
}
static int tcf_skbmod_init(struct net *net, struct nlattr *nla,
struct nlattr *est, struct tc_action **a,
int ovr, int bind)
{
struct tc_action_net *tn = net_generic(net, skbmod_net_id);
struct nlattr *tb[TCA_SKBMOD_MAX + 1];
struct tcf_skbmod_params *p, *p_old;
struct tc_skbmod *parm;
struct tcf_skbmod *d;
bool exists = false;
u8 *daddr = NULL;
u8 *saddr = NULL;
u16 eth_type = 0;
u32 lflags = 0;
int ret = 0, err;
if (!nla)
return -EINVAL;
err = nla_parse_nested(tb, TCA_SKBMOD_MAX, nla, skbmod_policy);
if (err < 0)
return err;
if (!tb[TCA_SKBMOD_PARMS])
return -EINVAL;
if (tb[TCA_SKBMOD_DMAC]) {
daddr = nla_data(tb[TCA_SKBMOD_DMAC]);
lflags |= SKBMOD_F_DMAC;
}
if (tb[TCA_SKBMOD_SMAC]) {
saddr = nla_data(tb[TCA_SKBMOD_SMAC]);
lflags |= SKBMOD_F_SMAC;
}
if (tb[TCA_SKBMOD_ETYPE]) {
eth_type = nla_get_u16(tb[TCA_SKBMOD_ETYPE]);
lflags |= SKBMOD_F_ETYPE;
}
parm = nla_data(tb[TCA_SKBMOD_PARMS]);
if (parm->flags & SKBMOD_F_SWAPMAC)
lflags = SKBMOD_F_SWAPMAC;
exists = tcf_hash_check(tn, parm->index, a, bind);
if (exists && bind)
return 0;
if (!lflags)
return -EINVAL;
if (!exists) {
ret = tcf_hash_create(tn, parm->index, est, a,
&act_skbmod_ops, bind, true);
if (ret)
return ret;
ret = ACT_P_CREATED;
} else {
tcf_hash_release(*a, bind);
if (!ovr)
return -EEXIST;
}
d = to_skbmod(*a);
ASSERT_RTNL();
p = kzalloc(sizeof(struct tcf_skbmod_params), GFP_KERNEL);
if (unlikely(!p)) {
if (ovr)
tcf_hash_release(*a, bind);
return -ENOMEM;
}
p->flags = lflags;
d->tcf_action = parm->action;
p_old = rtnl_dereference(d->skbmod_p);
if (ovr)
spin_lock_bh(&d->tcf_lock);
if (lflags & SKBMOD_F_DMAC)
ether_addr_copy(p->eth_dst, daddr);
if (lflags & SKBMOD_F_SMAC)
ether_addr_copy(p->eth_src, saddr);
if (lflags & SKBMOD_F_ETYPE)
p->eth_type = htons(eth_type);
rcu_assign_pointer(d->skbmod_p, p);
if (ovr)
spin_unlock_bh(&d->tcf_lock);
if (p_old)
kfree_rcu(p_old, rcu);
if (ret == ACT_P_CREATED)
tcf_hash_insert(tn, *a);
return ret;
}
static void tcf_skbmod_cleanup(struct tc_action *a, int bind)
{
struct tcf_skbmod *d = to_skbmod(a);
struct tcf_skbmod_params *p;
p = rcu_dereference_protected(d->skbmod_p, 1);
kfree_rcu(p, rcu);
}
static int tcf_skbmod_dump(struct sk_buff *skb, struct tc_action *a,
int bind, int ref)
{
struct tcf_skbmod *d = to_skbmod(a);
unsigned char *b = skb_tail_pointer(skb);
struct tcf_skbmod_params *p = rtnl_dereference(d->skbmod_p);
struct tc_skbmod opt = {
.index = d->tcf_index,
.refcnt = d->tcf_refcnt - ref,
.bindcnt = d->tcf_bindcnt - bind,
.action = d->tcf_action,
};
struct tcf_t t;
opt.flags = p->flags;
if (nla_put(skb, TCA_SKBMOD_PARMS, sizeof(opt), &opt))
goto nla_put_failure;
if ((p->flags & SKBMOD_F_DMAC) &&
nla_put(skb, TCA_SKBMOD_DMAC, ETH_ALEN, p->eth_dst))
goto nla_put_failure;
if ((p->flags & SKBMOD_F_SMAC) &&
nla_put(skb, TCA_SKBMOD_SMAC, ETH_ALEN, p->eth_src))
goto nla_put_failure;
if ((p->flags & SKBMOD_F_ETYPE) &&
nla_put_u16(skb, TCA_SKBMOD_ETYPE, ntohs(p->eth_type)))
goto nla_put_failure;
tcf_tm_dump(&t, &d->tcf_tm);
if (nla_put_64bit(skb, TCA_SKBMOD_TM, sizeof(t), &t, TCA_SKBMOD_PAD))
goto nla_put_failure;
return skb->len;
nla_put_failure:
nlmsg_trim(skb, b);
return -1;
}
static int tcf_skbmod_walker(struct net *net, struct sk_buff *skb,
struct netlink_callback *cb, int type,
const struct tc_action_ops *ops)
{
struct tc_action_net *tn = net_generic(net, skbmod_net_id);
return tcf_generic_walker(tn, skb, cb, type, ops);
}
static int tcf_skbmod_search(struct net *net, struct tc_action **a, u32 index)
{
struct tc_action_net *tn = net_generic(net, skbmod_net_id);
return tcf_hash_search(tn, a, index);
}
static __net_init int skbmod_init_net(struct net *net)
{
struct tc_action_net *tn = net_generic(net, skbmod_net_id);
return tc_action_net_init(tn, &act_skbmod_ops, SKBMOD_TAB_MASK);
}
static void __net_exit skbmod_exit_net(struct net *net)
{
struct tc_action_net *tn = net_generic(net, skbmod_net_id);
tc_action_net_exit(tn);
}
static int __init skbmod_init_module(void)
{
return tcf_register_action(&act_skbmod_ops, &skbmod_net_ops);
}
static void __exit skbmod_cleanup_module(void)
{
tcf_unregister_action(&act_skbmod_ops, &skbmod_net_ops);
}
