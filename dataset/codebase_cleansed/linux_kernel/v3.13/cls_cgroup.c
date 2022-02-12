static inline struct cgroup_cls_state *css_cls_state(struct cgroup_subsys_state *css)
{
return css ? container_of(css, struct cgroup_cls_state, css) : NULL;
}
static inline struct cgroup_cls_state *task_cls_state(struct task_struct *p)
{
return css_cls_state(task_css(p, net_cls_subsys_id));
}
static struct cgroup_subsys_state *
cgrp_css_alloc(struct cgroup_subsys_state *parent_css)
{
struct cgroup_cls_state *cs;
cs = kzalloc(sizeof(*cs), GFP_KERNEL);
if (!cs)
return ERR_PTR(-ENOMEM);
return &cs->css;
}
static int cgrp_css_online(struct cgroup_subsys_state *css)
{
struct cgroup_cls_state *cs = css_cls_state(css);
struct cgroup_cls_state *parent = css_cls_state(css_parent(css));
if (parent)
cs->classid = parent->classid;
return 0;
}
static void cgrp_css_free(struct cgroup_subsys_state *css)
{
kfree(css_cls_state(css));
}
static int update_classid(const void *v, struct file *file, unsigned n)
{
int err;
struct socket *sock = sock_from_file(file, &err);
if (sock)
sock->sk->sk_classid = (u32)(unsigned long)v;
return 0;
}
static void cgrp_attach(struct cgroup_subsys_state *css,
struct cgroup_taskset *tset)
{
struct task_struct *p;
struct cgroup_cls_state *cs = css_cls_state(css);
void *v = (void *)(unsigned long)cs->classid;
cgroup_taskset_for_each(p, css, tset) {
task_lock(p);
iterate_fd(p->files, 0, update_classid, v);
task_unlock(p);
}
}
static u64 read_classid(struct cgroup_subsys_state *css, struct cftype *cft)
{
return css_cls_state(css)->classid;
}
static int write_classid(struct cgroup_subsys_state *css, struct cftype *cft,
u64 value)
{
css_cls_state(css)->classid = (u32) value;
return 0;
}
static int cls_cgroup_classify(struct sk_buff *skb, const struct tcf_proto *tp,
struct tcf_result *res)
{
struct cls_cgroup_head *head = tp->root;
u32 classid;
rcu_read_lock();
classid = task_cls_state(current)->classid;
rcu_read_unlock();
if (in_serving_softirq()) {
if (!skb->sk)
return -1;
classid = skb->sk->sk_classid;
}
if (!classid)
return -1;
if (!tcf_em_tree_match(skb, &head->ematches, NULL))
return -1;
res->classid = classid;
res->class = 0;
return tcf_exts_exec(skb, &head->exts, res);
}
static unsigned long cls_cgroup_get(struct tcf_proto *tp, u32 handle)
{
return 0UL;
}
static void cls_cgroup_put(struct tcf_proto *tp, unsigned long f)
{
}
static int cls_cgroup_init(struct tcf_proto *tp)
{
return 0;
}
static int cls_cgroup_change(struct net *net, struct sk_buff *in_skb,
struct tcf_proto *tp, unsigned long base,
u32 handle, struct nlattr **tca,
unsigned long *arg)
{
struct nlattr *tb[TCA_CGROUP_MAX + 1];
struct cls_cgroup_head *head = tp->root;
struct tcf_ematch_tree t;
struct tcf_exts e;
int err;
if (!tca[TCA_OPTIONS])
return -EINVAL;
if (head == NULL) {
if (!handle)
return -EINVAL;
head = kzalloc(sizeof(*head), GFP_KERNEL);
if (head == NULL)
return -ENOBUFS;
head->handle = handle;
tcf_tree_lock(tp);
tp->root = head;
tcf_tree_unlock(tp);
}
if (handle != head->handle)
return -ENOENT;
err = nla_parse_nested(tb, TCA_CGROUP_MAX, tca[TCA_OPTIONS],
cgroup_policy);
if (err < 0)
return err;
err = tcf_exts_validate(net, tp, tb, tca[TCA_RATE], &e,
&cgroup_ext_map);
if (err < 0)
return err;
err = tcf_em_tree_validate(tp, tb[TCA_CGROUP_EMATCHES], &t);
if (err < 0)
return err;
tcf_exts_change(tp, &head->exts, &e);
tcf_em_tree_change(tp, &head->ematches, &t);
return 0;
}
static void cls_cgroup_destroy(struct tcf_proto *tp)
{
struct cls_cgroup_head *head = tp->root;
if (head) {
tcf_exts_destroy(tp, &head->exts);
tcf_em_tree_destroy(tp, &head->ematches);
kfree(head);
}
}
static int cls_cgroup_delete(struct tcf_proto *tp, unsigned long arg)
{
return -EOPNOTSUPP;
}
static void cls_cgroup_walk(struct tcf_proto *tp, struct tcf_walker *arg)
{
struct cls_cgroup_head *head = tp->root;
if (arg->count < arg->skip)
goto skip;
if (arg->fn(tp, (unsigned long) head, arg) < 0) {
arg->stop = 1;
return;
}
skip:
arg->count++;
}
static int cls_cgroup_dump(struct tcf_proto *tp, unsigned long fh,
struct sk_buff *skb, struct tcmsg *t)
{
struct cls_cgroup_head *head = tp->root;
unsigned char *b = skb_tail_pointer(skb);
struct nlattr *nest;
t->tcm_handle = head->handle;
nest = nla_nest_start(skb, TCA_OPTIONS);
if (nest == NULL)
goto nla_put_failure;
if (tcf_exts_dump(skb, &head->exts, &cgroup_ext_map) < 0 ||
tcf_em_tree_dump(skb, &head->ematches, TCA_CGROUP_EMATCHES) < 0)
goto nla_put_failure;
nla_nest_end(skb, nest);
if (tcf_exts_dump_stats(skb, &head->exts, &cgroup_ext_map) < 0)
goto nla_put_failure;
return skb->len;
nla_put_failure:
nlmsg_trim(skb, b);
return -1;
}
static int __init init_cgroup_cls(void)
{
int ret;
ret = cgroup_load_subsys(&net_cls_subsys);
if (ret)
goto out;
ret = register_tcf_proto_ops(&cls_cgroup_ops);
if (ret)
cgroup_unload_subsys(&net_cls_subsys);
out:
return ret;
}
static void __exit exit_cgroup_cls(void)
{
unregister_tcf_proto_ops(&cls_cgroup_ops);
cgroup_unload_subsys(&net_cls_subsys);
}
