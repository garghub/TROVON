static int tcf_connmark(struct sk_buff *skb, const struct tc_action *a,
struct tcf_result *res)
{
const struct nf_conntrack_tuple_hash *thash;
struct nf_conntrack_tuple tuple;
enum ip_conntrack_info ctinfo;
struct tcf_connmark_info *ca = a->priv;
struct nf_conntrack_zone zone;
struct nf_conn *c;
int proto;
spin_lock(&ca->tcf_lock);
ca->tcf_tm.lastuse = jiffies;
bstats_update(&ca->tcf_bstats, skb);
if (skb->protocol == htons(ETH_P_IP)) {
if (skb->len < sizeof(struct iphdr))
goto out;
proto = NFPROTO_IPV4;
} else if (skb->protocol == htons(ETH_P_IPV6)) {
if (skb->len < sizeof(struct ipv6hdr))
goto out;
proto = NFPROTO_IPV6;
} else {
goto out;
}
c = nf_ct_get(skb, &ctinfo);
if (c) {
skb->mark = c->mark;
ca->tcf_qstats.overlimits++;
goto out;
}
if (!nf_ct_get_tuplepr(skb, skb_network_offset(skb),
proto, ca->net, &tuple))
goto out;
zone.id = ca->zone;
zone.dir = NF_CT_DEFAULT_ZONE_DIR;
thash = nf_conntrack_find_get(ca->net, &zone, &tuple);
if (!thash)
goto out;
c = nf_ct_tuplehash_to_ctrack(thash);
ca->tcf_qstats.overlimits++;
skb->mark = c->mark;
nf_ct_put(c);
out:
spin_unlock(&ca->tcf_lock);
return ca->tcf_action;
}
static int tcf_connmark_init(struct net *net, struct nlattr *nla,
struct nlattr *est, struct tc_action *a,
int ovr, int bind)
{
struct tc_action_net *tn = net_generic(net, connmark_net_id);
struct nlattr *tb[TCA_CONNMARK_MAX + 1];
struct tcf_connmark_info *ci;
struct tc_connmark *parm;
int ret = 0;
if (!nla)
return -EINVAL;
ret = nla_parse_nested(tb, TCA_CONNMARK_MAX, nla, connmark_policy);
if (ret < 0)
return ret;
parm = nla_data(tb[TCA_CONNMARK_PARMS]);
if (!tcf_hash_check(tn, parm->index, a, bind)) {
ret = tcf_hash_create(tn, parm->index, est, a,
sizeof(*ci), bind, false);
if (ret)
return ret;
ci = to_connmark(a);
ci->tcf_action = parm->action;
ci->net = net;
ci->zone = parm->zone;
tcf_hash_insert(tn, a);
ret = ACT_P_CREATED;
} else {
ci = to_connmark(a);
if (bind)
return 0;
tcf_hash_release(a, bind);
if (!ovr)
return -EEXIST;
ci->tcf_action = parm->action;
ci->zone = parm->zone;
}
return ret;
}
static inline int tcf_connmark_dump(struct sk_buff *skb, struct tc_action *a,
int bind, int ref)
{
unsigned char *b = skb_tail_pointer(skb);
struct tcf_connmark_info *ci = a->priv;
struct tc_connmark opt = {
.index = ci->tcf_index,
.refcnt = ci->tcf_refcnt - ref,
.bindcnt = ci->tcf_bindcnt - bind,
.action = ci->tcf_action,
.zone = ci->zone,
};
struct tcf_t t;
if (nla_put(skb, TCA_CONNMARK_PARMS, sizeof(opt), &opt))
goto nla_put_failure;
t.install = jiffies_to_clock_t(jiffies - ci->tcf_tm.install);
t.lastuse = jiffies_to_clock_t(jiffies - ci->tcf_tm.lastuse);
t.expires = jiffies_to_clock_t(ci->tcf_tm.expires);
if (nla_put(skb, TCA_CONNMARK_TM, sizeof(t), &t))
goto nla_put_failure;
return skb->len;
nla_put_failure:
nlmsg_trim(skb, b);
return -1;
}
static int tcf_connmark_walker(struct net *net, struct sk_buff *skb,
struct netlink_callback *cb, int type,
struct tc_action *a)
{
struct tc_action_net *tn = net_generic(net, connmark_net_id);
return tcf_generic_walker(tn, skb, cb, type, a);
}
static int tcf_connmark_search(struct net *net, struct tc_action *a, u32 index)
{
struct tc_action_net *tn = net_generic(net, connmark_net_id);
return tcf_hash_search(tn, a, index);
}
static __net_init int connmark_init_net(struct net *net)
{
struct tc_action_net *tn = net_generic(net, connmark_net_id);
return tc_action_net_init(tn, &act_connmark_ops, CONNMARK_TAB_MASK);
}
static void __net_exit connmark_exit_net(struct net *net)
{
struct tc_action_net *tn = net_generic(net, connmark_net_id);
tc_action_net_exit(tn);
}
static int __init connmark_init_module(void)
{
return tcf_register_action(&act_connmark_ops, &connmark_net_ops);
}
static void __exit connmark_cleanup_module(void)
{
tcf_unregister_action(&act_connmark_ops, &connmark_net_ops);
}
