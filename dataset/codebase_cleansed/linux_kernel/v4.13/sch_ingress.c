static struct Qdisc *ingress_leaf(struct Qdisc *sch, unsigned long arg)
{
return NULL;
}
static unsigned long ingress_get(struct Qdisc *sch, u32 classid)
{
return TC_H_MIN(classid) + 1;
}
static bool ingress_cl_offload(u32 classid)
{
return true;
}
static unsigned long ingress_bind_filter(struct Qdisc *sch,
unsigned long parent, u32 classid)
{
return ingress_get(sch, classid);
}
static void ingress_put(struct Qdisc *sch, unsigned long cl)
{
}
static void ingress_walk(struct Qdisc *sch, struct qdisc_walker *walker)
{
}
static struct tcf_block *ingress_tcf_block(struct Qdisc *sch, unsigned long cl)
{
struct ingress_sched_data *q = qdisc_priv(sch);
return q->block;
}
static int ingress_init(struct Qdisc *sch, struct nlattr *opt)
{
struct ingress_sched_data *q = qdisc_priv(sch);
struct net_device *dev = qdisc_dev(sch);
int err;
err = tcf_block_get(&q->block, &dev->ingress_cl_list);
if (err)
return err;
net_inc_ingress_queue();
sch->flags |= TCQ_F_CPUSTATS;
return 0;
}
static void ingress_destroy(struct Qdisc *sch)
{
struct ingress_sched_data *q = qdisc_priv(sch);
tcf_block_put(q->block);
net_dec_ingress_queue();
}
static int ingress_dump(struct Qdisc *sch, struct sk_buff *skb)
{
struct nlattr *nest;
nest = nla_nest_start(skb, TCA_OPTIONS);
if (nest == NULL)
goto nla_put_failure;
return nla_nest_end(skb, nest);
nla_put_failure:
nla_nest_cancel(skb, nest);
return -1;
}
static unsigned long clsact_get(struct Qdisc *sch, u32 classid)
{
switch (TC_H_MIN(classid)) {
case TC_H_MIN(TC_H_MIN_INGRESS):
case TC_H_MIN(TC_H_MIN_EGRESS):
return TC_H_MIN(classid);
default:
return 0;
}
}
static bool clsact_cl_offload(u32 classid)
{
return TC_H_MIN(classid) == TC_H_MIN(TC_H_MIN_INGRESS);
}
static unsigned long clsact_bind_filter(struct Qdisc *sch,
unsigned long parent, u32 classid)
{
return clsact_get(sch, classid);
}
static struct tcf_block *clsact_tcf_block(struct Qdisc *sch, unsigned long cl)
{
struct clsact_sched_data *q = qdisc_priv(sch);
switch (cl) {
case TC_H_MIN(TC_H_MIN_INGRESS):
return q->ingress_block;
case TC_H_MIN(TC_H_MIN_EGRESS):
return q->egress_block;
default:
return NULL;
}
}
static int clsact_init(struct Qdisc *sch, struct nlattr *opt)
{
struct clsact_sched_data *q = qdisc_priv(sch);
struct net_device *dev = qdisc_dev(sch);
int err;
err = tcf_block_get(&q->ingress_block, &dev->ingress_cl_list);
if (err)
return err;
err = tcf_block_get(&q->egress_block, &dev->egress_cl_list);
if (err)
return err;
net_inc_ingress_queue();
net_inc_egress_queue();
sch->flags |= TCQ_F_CPUSTATS;
return 0;
}
static void clsact_destroy(struct Qdisc *sch)
{
struct clsact_sched_data *q = qdisc_priv(sch);
tcf_block_put(q->egress_block);
tcf_block_put(q->ingress_block);
net_dec_ingress_queue();
net_dec_egress_queue();
}
static int __init ingress_module_init(void)
{
int ret;
ret = register_qdisc(&ingress_qdisc_ops);
if (!ret) {
ret = register_qdisc(&clsact_qdisc_ops);
if (ret)
unregister_qdisc(&ingress_qdisc_ops);
}
return ret;
}
static void __exit ingress_module_exit(void)
{
unregister_qdisc(&ingress_qdisc_ops);
unregister_qdisc(&clsact_qdisc_ops);
}
