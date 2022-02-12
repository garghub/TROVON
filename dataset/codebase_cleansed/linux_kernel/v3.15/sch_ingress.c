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
static struct tcf_proto **ingress_find_tcf(struct Qdisc *sch, unsigned long cl)
{
struct ingress_qdisc_data *p = qdisc_priv(sch);
return &p->filter_list;
}
static int ingress_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
struct ingress_qdisc_data *p = qdisc_priv(sch);
struct tcf_result res;
int result;
result = tc_classify(skb, p->filter_list, &res);
qdisc_bstats_update(sch, skb);
switch (result) {
case TC_ACT_SHOT:
result = TC_ACT_SHOT;
sch->qstats.drops++;
break;
case TC_ACT_STOLEN:
case TC_ACT_QUEUED:
result = TC_ACT_STOLEN;
break;
case TC_ACT_RECLASSIFY:
case TC_ACT_OK:
skb->tc_index = TC_H_MIN(res.classid);
default:
result = TC_ACT_OK;
break;
}
return result;
}
static void ingress_destroy(struct Qdisc *sch)
{
struct ingress_qdisc_data *p = qdisc_priv(sch);
tcf_destroy_chain(&p->filter_list);
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
