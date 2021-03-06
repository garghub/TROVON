static int tcf_simp(struct sk_buff *skb, const struct tc_action *a,
struct tcf_result *res)
{
struct tcf_defact *d = to_defact(a);
spin_lock(&d->tcf_lock);
tcf_lastuse_update(&d->tcf_tm);
bstats_update(&d->tcf_bstats, skb);
pr_info("simple: %s_%d\n",
(char *)d->tcfd_defdata, d->tcf_bstats.packets);
spin_unlock(&d->tcf_lock);
return d->tcf_action;
}
static void tcf_simp_release(struct tc_action *a, int bind)
{
struct tcf_defact *d = to_defact(a);
kfree(d->tcfd_defdata);
}
static int alloc_defdata(struct tcf_defact *d, char *defdata)
{
d->tcfd_defdata = kzalloc(SIMP_MAX_DATA, GFP_KERNEL);
if (unlikely(!d->tcfd_defdata))
return -ENOMEM;
strlcpy(d->tcfd_defdata, defdata, SIMP_MAX_DATA);
return 0;
}
static void reset_policy(struct tcf_defact *d, char *defdata,
struct tc_defact *p)
{
spin_lock_bh(&d->tcf_lock);
d->tcf_action = p->action;
memset(d->tcfd_defdata, 0, SIMP_MAX_DATA);
strlcpy(d->tcfd_defdata, defdata, SIMP_MAX_DATA);
spin_unlock_bh(&d->tcf_lock);
}
static int tcf_simp_init(struct net *net, struct nlattr *nla,
struct nlattr *est, struct tc_action **a,
int ovr, int bind)
{
struct tc_action_net *tn = net_generic(net, simp_net_id);
struct nlattr *tb[TCA_DEF_MAX + 1];
struct tc_defact *parm;
struct tcf_defact *d;
bool exists = false;
int ret = 0, err;
char *defdata;
if (nla == NULL)
return -EINVAL;
err = nla_parse_nested(tb, TCA_DEF_MAX, nla, simple_policy);
if (err < 0)
return err;
if (tb[TCA_DEF_PARMS] == NULL)
return -EINVAL;
parm = nla_data(tb[TCA_DEF_PARMS]);
exists = tcf_hash_check(tn, parm->index, a, bind);
if (exists && bind)
return 0;
if (tb[TCA_DEF_DATA] == NULL) {
if (exists)
tcf_hash_release(*a, bind);
return -EINVAL;
}
defdata = nla_data(tb[TCA_DEF_DATA]);
if (!exists) {
ret = tcf_hash_create(tn, parm->index, est, a,
&act_simp_ops, bind, false);
if (ret)
return ret;
d = to_defact(*a);
ret = alloc_defdata(d, defdata);
if (ret < 0) {
tcf_hash_cleanup(*a, est);
return ret;
}
d->tcf_action = parm->action;
ret = ACT_P_CREATED;
} else {
d = to_defact(*a);
tcf_hash_release(*a, bind);
if (!ovr)
return -EEXIST;
reset_policy(d, defdata, parm);
}
if (ret == ACT_P_CREATED)
tcf_hash_insert(tn, *a);
return ret;
}
static int tcf_simp_dump(struct sk_buff *skb, struct tc_action *a,
int bind, int ref)
{
unsigned char *b = skb_tail_pointer(skb);
struct tcf_defact *d = to_defact(a);
struct tc_defact opt = {
.index = d->tcf_index,
.refcnt = d->tcf_refcnt - ref,
.bindcnt = d->tcf_bindcnt - bind,
.action = d->tcf_action,
};
struct tcf_t t;
if (nla_put(skb, TCA_DEF_PARMS, sizeof(opt), &opt) ||
nla_put_string(skb, TCA_DEF_DATA, d->tcfd_defdata))
goto nla_put_failure;
tcf_tm_dump(&t, &d->tcf_tm);
if (nla_put_64bit(skb, TCA_DEF_TM, sizeof(t), &t, TCA_DEF_PAD))
goto nla_put_failure;
return skb->len;
nla_put_failure:
nlmsg_trim(skb, b);
return -1;
}
static int tcf_simp_walker(struct net *net, struct sk_buff *skb,
struct netlink_callback *cb, int type,
const struct tc_action_ops *ops)
{
struct tc_action_net *tn = net_generic(net, simp_net_id);
return tcf_generic_walker(tn, skb, cb, type, ops);
}
static int tcf_simp_search(struct net *net, struct tc_action **a, u32 index)
{
struct tc_action_net *tn = net_generic(net, simp_net_id);
return tcf_hash_search(tn, a, index);
}
static __net_init int simp_init_net(struct net *net)
{
struct tc_action_net *tn = net_generic(net, simp_net_id);
return tc_action_net_init(tn, &act_simp_ops, SIMP_TAB_MASK);
}
static void __net_exit simp_exit_net(struct net *net)
{
struct tc_action_net *tn = net_generic(net, simp_net_id);
tc_action_net_exit(tn);
}
static int __init simp_init_module(void)
{
int ret = tcf_register_action(&act_simp_ops, &simp_net_ops);
if (!ret)
pr_info("Simple TC action Loaded\n");
return ret;
}
static void __exit simp_cleanup_module(void)
{
tcf_unregister_action(&act_simp_ops, &simp_net_ops);
}
