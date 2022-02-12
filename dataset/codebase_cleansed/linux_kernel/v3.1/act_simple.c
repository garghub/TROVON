static int tcf_simp(struct sk_buff *skb, const struct tc_action *a,
struct tcf_result *res)
{
struct tcf_defact *d = a->priv;
spin_lock(&d->tcf_lock);
d->tcf_tm.lastuse = jiffies;
bstats_update(&d->tcf_bstats, skb);
pr_info("simple: %s_%d\n",
(char *)d->tcfd_defdata, d->tcf_bstats.packets);
spin_unlock(&d->tcf_lock);
return d->tcf_action;
}
static int tcf_simp_release(struct tcf_defact *d, int bind)
{
int ret = 0;
if (d) {
if (bind)
d->tcf_bindcnt--;
d->tcf_refcnt--;
if (d->tcf_bindcnt <= 0 && d->tcf_refcnt <= 0) {
kfree(d->tcfd_defdata);
tcf_hash_destroy(&d->common, &simp_hash_info);
ret = 1;
}
}
return ret;
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
static int tcf_simp_init(struct nlattr *nla, struct nlattr *est,
struct tc_action *a, int ovr, int bind)
{
struct nlattr *tb[TCA_DEF_MAX + 1];
struct tc_defact *parm;
struct tcf_defact *d;
struct tcf_common *pc;
char *defdata;
int ret = 0, err;
if (nla == NULL)
return -EINVAL;
err = nla_parse_nested(tb, TCA_DEF_MAX, nla, simple_policy);
if (err < 0)
return err;
if (tb[TCA_DEF_PARMS] == NULL)
return -EINVAL;
if (tb[TCA_DEF_DATA] == NULL)
return -EINVAL;
parm = nla_data(tb[TCA_DEF_PARMS]);
defdata = nla_data(tb[TCA_DEF_DATA]);
pc = tcf_hash_check(parm->index, a, bind, &simp_hash_info);
if (!pc) {
pc = tcf_hash_create(parm->index, est, a, sizeof(*d), bind,
&simp_idx_gen, &simp_hash_info);
if (IS_ERR(pc))
return PTR_ERR(pc);
d = to_defact(pc);
ret = alloc_defdata(d, defdata);
if (ret < 0) {
kfree(pc);
return ret;
}
d->tcf_action = parm->action;
ret = ACT_P_CREATED;
} else {
d = to_defact(pc);
if (!ovr) {
tcf_simp_release(d, bind);
return -EEXIST;
}
reset_policy(d, defdata, parm);
}
if (ret == ACT_P_CREATED)
tcf_hash_insert(pc, &simp_hash_info);
return ret;
}
static int tcf_simp_cleanup(struct tc_action *a, int bind)
{
struct tcf_defact *d = a->priv;
if (d)
return tcf_simp_release(d, bind);
return 0;
}
static int tcf_simp_dump(struct sk_buff *skb, struct tc_action *a,
int bind, int ref)
{
unsigned char *b = skb_tail_pointer(skb);
struct tcf_defact *d = a->priv;
struct tc_defact opt = {
.index = d->tcf_index,
.refcnt = d->tcf_refcnt - ref,
.bindcnt = d->tcf_bindcnt - bind,
.action = d->tcf_action,
};
struct tcf_t t;
NLA_PUT(skb, TCA_DEF_PARMS, sizeof(opt), &opt);
NLA_PUT_STRING(skb, TCA_DEF_DATA, d->tcfd_defdata);
t.install = jiffies_to_clock_t(jiffies - d->tcf_tm.install);
t.lastuse = jiffies_to_clock_t(jiffies - d->tcf_tm.lastuse);
t.expires = jiffies_to_clock_t(d->tcf_tm.expires);
NLA_PUT(skb, TCA_DEF_TM, sizeof(t), &t);
return skb->len;
nla_put_failure:
nlmsg_trim(skb, b);
return -1;
}
static int __init simp_init_module(void)
{
int ret = tcf_register_action(&act_simp_ops);
if (!ret)
pr_info("Simple TC action Loaded\n");
return ret;
}
static void __exit simp_cleanup_module(void)
{
tcf_unregister_action(&act_simp_ops);
}
