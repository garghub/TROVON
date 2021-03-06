static int tcf_connmark(struct sk_buff *skb, const struct tc_action *a,
struct tcf_result *res)
{
const struct nf_conntrack_tuple_hash *thash;
struct nf_conntrack_tuple tuple;
enum ip_conntrack_info ctinfo;
struct tcf_connmark_info *ca = a->priv;
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
nf_ct_put(c);
goto out;
}
if (!nf_ct_get_tuplepr(skb, skb_network_offset(skb),
proto, &tuple))
goto out;
thash = nf_conntrack_find_get(dev_net(skb->dev), ca->zone, &tuple);
if (!thash)
goto out;
c = nf_ct_tuplehash_to_ctrack(thash);
ca->tcf_qstats.overlimits++;
skb->mark = c->mark;
nf_ct_put(c);
out:
skb->nfct = NULL;
spin_unlock(&ca->tcf_lock);
return ca->tcf_action;
}
static int tcf_connmark_init(struct net *net, struct nlattr *nla,
struct nlattr *est, struct tc_action *a,
int ovr, int bind)
{
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
if (!tcf_hash_check(parm->index, a, bind)) {
ret = tcf_hash_create(parm->index, est, a, sizeof(*ci), bind);
if (ret)
return ret;
ci = to_connmark(a);
ci->tcf_action = parm->action;
ci->zone = parm->zone;
tcf_hash_insert(a);
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
static int __init connmark_init_module(void)
{
return tcf_register_action(&act_connmark_ops, CONNMARK_TAB_MASK);
}
static void __exit connmark_cleanup_module(void)
{
tcf_unregister_action(&act_connmark_ops);
}
