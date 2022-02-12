static int tcf_skbedit(struct sk_buff *skb, struct tc_action *a,
struct tcf_result *res)
{
struct tcf_skbedit *d = a->priv;
spin_lock(&d->tcf_lock);
d->tcf_tm.lastuse = jiffies;
bstats_update(&d->tcf_bstats, skb);
if (d->flags & SKBEDIT_F_PRIORITY)
skb->priority = d->priority;
if (d->flags & SKBEDIT_F_QUEUE_MAPPING &&
skb->dev->real_num_tx_queues > d->queue_mapping)
skb_set_queue_mapping(skb, d->queue_mapping);
if (d->flags & SKBEDIT_F_MARK)
skb->mark = d->mark;
spin_unlock(&d->tcf_lock);
return d->tcf_action;
}
static int tcf_skbedit_init(struct nlattr *nla, struct nlattr *est,
struct tc_action *a, int ovr, int bind)
{
struct nlattr *tb[TCA_SKBEDIT_MAX + 1];
struct tc_skbedit *parm;
struct tcf_skbedit *d;
struct tcf_common *pc;
u32 flags = 0, *priority = NULL, *mark = NULL;
u16 *queue_mapping = NULL;
int ret = 0, err;
if (nla == NULL)
return -EINVAL;
err = nla_parse_nested(tb, TCA_SKBEDIT_MAX, nla, skbedit_policy);
if (err < 0)
return err;
if (tb[TCA_SKBEDIT_PARMS] == NULL)
return -EINVAL;
if (tb[TCA_SKBEDIT_PRIORITY] != NULL) {
flags |= SKBEDIT_F_PRIORITY;
priority = nla_data(tb[TCA_SKBEDIT_PRIORITY]);
}
if (tb[TCA_SKBEDIT_QUEUE_MAPPING] != NULL) {
flags |= SKBEDIT_F_QUEUE_MAPPING;
queue_mapping = nla_data(tb[TCA_SKBEDIT_QUEUE_MAPPING]);
}
if (tb[TCA_SKBEDIT_MARK] != NULL) {
flags |= SKBEDIT_F_MARK;
mark = nla_data(tb[TCA_SKBEDIT_MARK]);
}
if (!flags)
return -EINVAL;
parm = nla_data(tb[TCA_SKBEDIT_PARMS]);
pc = tcf_hash_check(parm->index, a, bind, &skbedit_hash_info);
if (!pc) {
pc = tcf_hash_create(parm->index, est, a, sizeof(*d), bind,
&skbedit_idx_gen, &skbedit_hash_info);
if (IS_ERR(pc))
return PTR_ERR(pc);
d = to_skbedit(pc);
ret = ACT_P_CREATED;
} else {
d = to_skbedit(pc);
if (!ovr) {
tcf_hash_release(pc, bind, &skbedit_hash_info);
return -EEXIST;
}
}
spin_lock_bh(&d->tcf_lock);
d->flags = flags;
if (flags & SKBEDIT_F_PRIORITY)
d->priority = *priority;
if (flags & SKBEDIT_F_QUEUE_MAPPING)
d->queue_mapping = *queue_mapping;
if (flags & SKBEDIT_F_MARK)
d->mark = *mark;
d->tcf_action = parm->action;
spin_unlock_bh(&d->tcf_lock);
if (ret == ACT_P_CREATED)
tcf_hash_insert(pc, &skbedit_hash_info);
return ret;
}
static int tcf_skbedit_cleanup(struct tc_action *a, int bind)
{
struct tcf_skbedit *d = a->priv;
if (d)
return tcf_hash_release(&d->common, bind, &skbedit_hash_info);
return 0;
}
static int tcf_skbedit_dump(struct sk_buff *skb, struct tc_action *a,
int bind, int ref)
{
unsigned char *b = skb_tail_pointer(skb);
struct tcf_skbedit *d = a->priv;
struct tc_skbedit opt = {
.index = d->tcf_index,
.refcnt = d->tcf_refcnt - ref,
.bindcnt = d->tcf_bindcnt - bind,
.action = d->tcf_action,
};
struct tcf_t t;
NLA_PUT(skb, TCA_SKBEDIT_PARMS, sizeof(opt), &opt);
if (d->flags & SKBEDIT_F_PRIORITY)
NLA_PUT(skb, TCA_SKBEDIT_PRIORITY, sizeof(d->priority),
&d->priority);
if (d->flags & SKBEDIT_F_QUEUE_MAPPING)
NLA_PUT(skb, TCA_SKBEDIT_QUEUE_MAPPING,
sizeof(d->queue_mapping), &d->queue_mapping);
if (d->flags & SKBEDIT_F_MARK)
NLA_PUT(skb, TCA_SKBEDIT_MARK, sizeof(d->mark),
&d->mark);
t.install = jiffies_to_clock_t(jiffies - d->tcf_tm.install);
t.lastuse = jiffies_to_clock_t(jiffies - d->tcf_tm.lastuse);
t.expires = jiffies_to_clock_t(d->tcf_tm.expires);
NLA_PUT(skb, TCA_SKBEDIT_TM, sizeof(t), &t);
return skb->len;
nla_put_failure:
nlmsg_trim(skb, b);
return -1;
}
static int __init skbedit_init_module(void)
{
return tcf_register_action(&act_skbedit_ops);
}
static void __exit skbedit_cleanup_module(void)
{
tcf_unregister_action(&act_skbedit_ops);
}
