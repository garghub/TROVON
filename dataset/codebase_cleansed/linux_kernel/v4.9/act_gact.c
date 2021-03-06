static int gact_net_rand(struct tcf_gact *gact)
{
smp_rmb();
if (prandom_u32() % gact->tcfg_pval)
return gact->tcf_action;
return gact->tcfg_paction;
}
static int gact_determ(struct tcf_gact *gact)
{
u32 pack = atomic_inc_return(&gact->packets);
smp_rmb();
if (pack % gact->tcfg_pval)
return gact->tcf_action;
return gact->tcfg_paction;
}
static int tcf_gact_init(struct net *net, struct nlattr *nla,
struct nlattr *est, struct tc_action **a,
int ovr, int bind)
{
struct tc_action_net *tn = net_generic(net, gact_net_id);
struct nlattr *tb[TCA_GACT_MAX + 1];
struct tc_gact *parm;
struct tcf_gact *gact;
int ret = 0;
int err;
#ifdef CONFIG_GACT_PROB
struct tc_gact_p *p_parm = NULL;
#endif
if (nla == NULL)
return -EINVAL;
err = nla_parse_nested(tb, TCA_GACT_MAX, nla, gact_policy);
if (err < 0)
return err;
if (tb[TCA_GACT_PARMS] == NULL)
return -EINVAL;
parm = nla_data(tb[TCA_GACT_PARMS]);
#ifndef CONFIG_GACT_PROB
if (tb[TCA_GACT_PROB] != NULL)
return -EOPNOTSUPP;
#else
if (tb[TCA_GACT_PROB]) {
p_parm = nla_data(tb[TCA_GACT_PROB]);
if (p_parm->ptype >= MAX_RAND)
return -EINVAL;
}
#endif
if (!tcf_hash_check(tn, parm->index, a, bind)) {
ret = tcf_hash_create(tn, parm->index, est, a,
&act_gact_ops, bind, true);
if (ret)
return ret;
ret = ACT_P_CREATED;
} else {
if (bind)
return 0;
tcf_hash_release(*a, bind);
if (!ovr)
return -EEXIST;
}
gact = to_gact(*a);
ASSERT_RTNL();
gact->tcf_action = parm->action;
#ifdef CONFIG_GACT_PROB
if (p_parm) {
gact->tcfg_paction = p_parm->paction;
gact->tcfg_pval = max_t(u16, 1, p_parm->pval);
smp_wmb();
gact->tcfg_ptype = p_parm->ptype;
}
#endif
if (ret == ACT_P_CREATED)
tcf_hash_insert(tn, *a);
return ret;
}
static int tcf_gact(struct sk_buff *skb, const struct tc_action *a,
struct tcf_result *res)
{
struct tcf_gact *gact = to_gact(a);
int action = READ_ONCE(gact->tcf_action);
#ifdef CONFIG_GACT_PROB
{
u32 ptype = READ_ONCE(gact->tcfg_ptype);
if (ptype)
action = gact_rand[ptype](gact);
}
#endif
bstats_cpu_update(this_cpu_ptr(gact->common.cpu_bstats), skb);
if (action == TC_ACT_SHOT)
qstats_drop_inc(this_cpu_ptr(gact->common.cpu_qstats));
tcf_lastuse_update(&gact->tcf_tm);
return action;
}
static void tcf_gact_stats_update(struct tc_action *a, u64 bytes, u32 packets,
u64 lastuse)
{
struct tcf_gact *gact = to_gact(a);
int action = READ_ONCE(gact->tcf_action);
struct tcf_t *tm = &gact->tcf_tm;
_bstats_cpu_update(this_cpu_ptr(gact->common.cpu_bstats), bytes,
packets);
if (action == TC_ACT_SHOT)
this_cpu_ptr(gact->common.cpu_qstats)->drops += packets;
tm->lastuse = lastuse;
}
static int tcf_gact_dump(struct sk_buff *skb, struct tc_action *a,
int bind, int ref)
{
unsigned char *b = skb_tail_pointer(skb);
struct tcf_gact *gact = to_gact(a);
struct tc_gact opt = {
.index = gact->tcf_index,
.refcnt = gact->tcf_refcnt - ref,
.bindcnt = gact->tcf_bindcnt - bind,
.action = gact->tcf_action,
};
struct tcf_t t;
if (nla_put(skb, TCA_GACT_PARMS, sizeof(opt), &opt))
goto nla_put_failure;
#ifdef CONFIG_GACT_PROB
if (gact->tcfg_ptype) {
struct tc_gact_p p_opt = {
.paction = gact->tcfg_paction,
.pval = gact->tcfg_pval,
.ptype = gact->tcfg_ptype,
};
if (nla_put(skb, TCA_GACT_PROB, sizeof(p_opt), &p_opt))
goto nla_put_failure;
}
#endif
tcf_tm_dump(&t, &gact->tcf_tm);
if (nla_put_64bit(skb, TCA_GACT_TM, sizeof(t), &t, TCA_GACT_PAD))
goto nla_put_failure;
return skb->len;
nla_put_failure:
nlmsg_trim(skb, b);
return -1;
}
static int tcf_gact_walker(struct net *net, struct sk_buff *skb,
struct netlink_callback *cb, int type,
const struct tc_action_ops *ops)
{
struct tc_action_net *tn = net_generic(net, gact_net_id);
return tcf_generic_walker(tn, skb, cb, type, ops);
}
static int tcf_gact_search(struct net *net, struct tc_action **a, u32 index)
{
struct tc_action_net *tn = net_generic(net, gact_net_id);
return tcf_hash_search(tn, a, index);
}
static __net_init int gact_init_net(struct net *net)
{
struct tc_action_net *tn = net_generic(net, gact_net_id);
return tc_action_net_init(tn, &act_gact_ops, GACT_TAB_MASK);
}
static void __net_exit gact_exit_net(struct net *net)
{
struct tc_action_net *tn = net_generic(net, gact_net_id);
tc_action_net_exit(tn);
}
static int __init gact_init_module(void)
{
#ifdef CONFIG_GACT_PROB
pr_info("GACT probability on\n");
#else
pr_info("GACT probability NOT on\n");
#endif
return tcf_register_action(&act_gact_ops, &gact_net_ops);
}
static void __exit gact_cleanup_module(void)
{
tcf_unregister_action(&act_gact_ops, &gact_net_ops);
}
