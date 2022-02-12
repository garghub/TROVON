static struct Qdisc *ingress_leaf(struct Qdisc *sch, unsigned long arg)
{
return NULL;
}
static unsigned long ingress_get(struct Qdisc *sch, u32 classid)
{
return TC_H_MIN(classid) + 1;
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
static struct tcf_proto __rcu **ingress_find_tcf(struct Qdisc *sch,
unsigned long cl)
{
struct net_device *dev = qdisc_dev(sch);
return &dev->ingress_cl_list;
}
static int ingress_init(struct Qdisc *sch, struct nlattr *opt)
{
net_inc_ingress_queue();
sch->flags |= TCQ_F_CPUSTATS;
return 0;
}
static void ingress_destroy(struct Qdisc *sch)
{
struct net_device *dev = qdisc_dev(sch);
tcf_destroy_chain(&dev->ingress_cl_list);
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
static int __init ingress_module_init(void)
{
return register_qdisc(&ingress_qdisc_ops);
}
static void __exit ingress_module_exit(void)
{
unregister_qdisc(&ingress_qdisc_ops);
}
