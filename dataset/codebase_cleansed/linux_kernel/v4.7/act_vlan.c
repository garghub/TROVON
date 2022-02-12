static int tcf_vlan(struct sk_buff *skb, const struct tc_action *a,
struct tcf_result *res)
{
struct tcf_vlan *v = a->priv;
int action;
int err;
spin_lock(&v->tcf_lock);
v->tcf_tm.lastuse = jiffies;
bstats_update(&v->tcf_bstats, skb);
action = v->tcf_action;
switch (v->tcfv_action) {
case TCA_VLAN_ACT_POP:
err = skb_vlan_pop(skb);
if (err)
goto drop;
break;
case TCA_VLAN_ACT_PUSH:
err = skb_vlan_push(skb, v->tcfv_push_proto, v->tcfv_push_vid);
if (err)
goto drop;
break;
default:
BUG();
}
goto unlock;
drop:
action = TC_ACT_SHOT;
v->tcf_qstats.drops++;
unlock:
spin_unlock(&v->tcf_lock);
return action;
}
static int tcf_vlan_init(struct net *net, struct nlattr *nla,
struct nlattr *est, struct tc_action *a,
int ovr, int bind)
{
struct tc_action_net *tn = net_generic(net, vlan_net_id);
struct nlattr *tb[TCA_VLAN_MAX + 1];
struct tc_vlan *parm;
struct tcf_vlan *v;
int action;
__be16 push_vid = 0;
__be16 push_proto = 0;
int ret = 0, exists = 0;
int err;
if (!nla)
return -EINVAL;
err = nla_parse_nested(tb, TCA_VLAN_MAX, nla, vlan_policy);
if (err < 0)
return err;
if (!tb[TCA_VLAN_PARMS])
return -EINVAL;
parm = nla_data(tb[TCA_VLAN_PARMS]);
exists = tcf_hash_check(tn, parm->index, a, bind);
if (exists && bind)
return 0;
switch (parm->v_action) {
case TCA_VLAN_ACT_POP:
break;
case TCA_VLAN_ACT_PUSH:
if (!tb[TCA_VLAN_PUSH_VLAN_ID]) {
if (exists)
tcf_hash_release(a, bind);
return -EINVAL;
}
push_vid = nla_get_u16(tb[TCA_VLAN_PUSH_VLAN_ID]);
if (push_vid >= VLAN_VID_MASK) {
if (exists)
tcf_hash_release(a, bind);
return -ERANGE;
}
if (tb[TCA_VLAN_PUSH_VLAN_PROTOCOL]) {
push_proto = nla_get_be16(tb[TCA_VLAN_PUSH_VLAN_PROTOCOL]);
switch (push_proto) {
case htons(ETH_P_8021Q):
case htons(ETH_P_8021AD):
break;
default:
return -EPROTONOSUPPORT;
}
} else {
push_proto = htons(ETH_P_8021Q);
}
break;
default:
if (exists)
tcf_hash_release(a, bind);
return -EINVAL;
}
action = parm->v_action;
if (!exists) {
ret = tcf_hash_create(tn, parm->index, est, a,
sizeof(*v), bind, false);
if (ret)
return ret;
ret = ACT_P_CREATED;
} else {
tcf_hash_release(a, bind);
if (!ovr)
return -EEXIST;
}
v = to_vlan(a);
spin_lock_bh(&v->tcf_lock);
v->tcfv_action = action;
v->tcfv_push_vid = push_vid;
v->tcfv_push_proto = push_proto;
v->tcf_action = parm->action;
spin_unlock_bh(&v->tcf_lock);
if (ret == ACT_P_CREATED)
tcf_hash_insert(tn, a);
return ret;
}
static int tcf_vlan_dump(struct sk_buff *skb, struct tc_action *a,
int bind, int ref)
{
unsigned char *b = skb_tail_pointer(skb);
struct tcf_vlan *v = a->priv;
struct tc_vlan opt = {
.index = v->tcf_index,
.refcnt = v->tcf_refcnt - ref,
.bindcnt = v->tcf_bindcnt - bind,
.action = v->tcf_action,
.v_action = v->tcfv_action,
};
struct tcf_t t;
if (nla_put(skb, TCA_VLAN_PARMS, sizeof(opt), &opt))
goto nla_put_failure;
if (v->tcfv_action == TCA_VLAN_ACT_PUSH &&
(nla_put_u16(skb, TCA_VLAN_PUSH_VLAN_ID, v->tcfv_push_vid) ||
nla_put_be16(skb, TCA_VLAN_PUSH_VLAN_PROTOCOL, v->tcfv_push_proto)))
goto nla_put_failure;
t.install = jiffies_to_clock_t(jiffies - v->tcf_tm.install);
t.lastuse = jiffies_to_clock_t(jiffies - v->tcf_tm.lastuse);
t.expires = jiffies_to_clock_t(v->tcf_tm.expires);
if (nla_put_64bit(skb, TCA_VLAN_TM, sizeof(t), &t, TCA_VLAN_PAD))
goto nla_put_failure;
return skb->len;
nla_put_failure:
nlmsg_trim(skb, b);
return -1;
}
static int tcf_vlan_walker(struct net *net, struct sk_buff *skb,
struct netlink_callback *cb, int type,
struct tc_action *a)
{
struct tc_action_net *tn = net_generic(net, vlan_net_id);
return tcf_generic_walker(tn, skb, cb, type, a);
}
static int tcf_vlan_search(struct net *net, struct tc_action *a, u32 index)
{
struct tc_action_net *tn = net_generic(net, vlan_net_id);
return tcf_hash_search(tn, a, index);
}
static __net_init int vlan_init_net(struct net *net)
{
struct tc_action_net *tn = net_generic(net, vlan_net_id);
return tc_action_net_init(tn, &act_vlan_ops, VLAN_TAB_MASK);
}
static void __net_exit vlan_exit_net(struct net *net)
{
struct tc_action_net *tn = net_generic(net, vlan_net_id);
tc_action_net_exit(tn);
}
static int __init vlan_init_module(void)
{
return tcf_register_action(&act_vlan_ops, &vlan_net_ops);
}
static void __exit vlan_cleanup_module(void)
{
tcf_unregister_action(&act_vlan_ops, &vlan_net_ops);
}
