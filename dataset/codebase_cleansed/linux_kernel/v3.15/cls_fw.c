static u32 fw_hash(u32 handle)
{
handle ^= (handle >> 16);
handle ^= (handle >> 8);
return handle % HTSIZE;
}
static int fw_classify(struct sk_buff *skb, const struct tcf_proto *tp,
struct tcf_result *res)
{
struct fw_head *head = tp->root;
struct fw_filter *f;
int r;
u32 id = skb->mark;
if (head != NULL) {
id &= head->mask;
for (f = head->ht[fw_hash(id)]; f; f = f->next) {
if (f->id == id) {
*res = f->res;
#ifdef CONFIG_NET_CLS_IND
if (!tcf_match_indev(skb, f->ifindex))
continue;
#endif
r = tcf_exts_exec(skb, &f->exts, res);
if (r < 0)
continue;
return r;
}
}
} else {
if (id && (TC_H_MAJ(id) == 0 ||
!(TC_H_MAJ(id ^ tp->q->handle)))) {
res->classid = id;
res->class = 0;
return 0;
}
}
return -1;
}
static unsigned long fw_get(struct tcf_proto *tp, u32 handle)
{
struct fw_head *head = tp->root;
struct fw_filter *f;
if (head == NULL)
return 0;
for (f = head->ht[fw_hash(handle)]; f; f = f->next) {
if (f->id == handle)
return (unsigned long)f;
}
return 0;
}
static void fw_put(struct tcf_proto *tp, unsigned long f)
{
}
static int fw_init(struct tcf_proto *tp)
{
return 0;
}
static void fw_delete_filter(struct tcf_proto *tp, struct fw_filter *f)
{
tcf_unbind_filter(tp, &f->res);
tcf_exts_destroy(tp, &f->exts);
kfree(f);
}
static void fw_destroy(struct tcf_proto *tp)
{
struct fw_head *head = tp->root;
struct fw_filter *f;
int h;
if (head == NULL)
return;
for (h = 0; h < HTSIZE; h++) {
while ((f = head->ht[h]) != NULL) {
head->ht[h] = f->next;
fw_delete_filter(tp, f);
}
}
kfree(head);
}
static int fw_delete(struct tcf_proto *tp, unsigned long arg)
{
struct fw_head *head = tp->root;
struct fw_filter *f = (struct fw_filter *)arg;
struct fw_filter **fp;
if (head == NULL || f == NULL)
goto out;
for (fp = &head->ht[fw_hash(f->id)]; *fp; fp = &(*fp)->next) {
if (*fp == f) {
tcf_tree_lock(tp);
*fp = f->next;
tcf_tree_unlock(tp);
fw_delete_filter(tp, f);
return 0;
}
}
out:
return -EINVAL;
}
static int
fw_change_attrs(struct net *net, struct tcf_proto *tp, struct fw_filter *f,
struct nlattr **tb, struct nlattr **tca, unsigned long base)
{
struct fw_head *head = tp->root;
struct tcf_exts e;
u32 mask;
int err;
tcf_exts_init(&e, TCA_FW_ACT, TCA_FW_POLICE);
err = tcf_exts_validate(net, tp, tb, tca[TCA_RATE], &e);
if (err < 0)
return err;
if (tb[TCA_FW_CLASSID]) {
f->res.classid = nla_get_u32(tb[TCA_FW_CLASSID]);
tcf_bind_filter(tp, &f->res, base);
}
#ifdef CONFIG_NET_CLS_IND
if (tb[TCA_FW_INDEV]) {
int ret;
ret = tcf_change_indev(net, tb[TCA_FW_INDEV]);
if (ret < 0) {
err = ret;
goto errout;
}
f->ifindex = ret;
}
#endif
err = -EINVAL;
if (tb[TCA_FW_MASK]) {
mask = nla_get_u32(tb[TCA_FW_MASK]);
if (mask != head->mask)
goto errout;
} else if (head->mask != 0xFFFFFFFF)
goto errout;
tcf_exts_change(tp, &f->exts, &e);
return 0;
errout:
tcf_exts_destroy(tp, &e);
return err;
}
static int fw_change(struct net *net, struct sk_buff *in_skb,
struct tcf_proto *tp, unsigned long base,
u32 handle,
struct nlattr **tca,
unsigned long *arg)
{
struct fw_head *head = tp->root;
struct fw_filter *f = (struct fw_filter *) *arg;
struct nlattr *opt = tca[TCA_OPTIONS];
struct nlattr *tb[TCA_FW_MAX + 1];
int err;
if (!opt)
return handle ? -EINVAL : 0;
err = nla_parse_nested(tb, TCA_FW_MAX, opt, fw_policy);
if (err < 0)
return err;
if (f != NULL) {
if (f->id != handle && handle)
return -EINVAL;
return fw_change_attrs(net, tp, f, tb, tca, base);
}
if (!handle)
return -EINVAL;
if (head == NULL) {
u32 mask = 0xFFFFFFFF;
if (tb[TCA_FW_MASK])
mask = nla_get_u32(tb[TCA_FW_MASK]);
head = kzalloc(sizeof(struct fw_head), GFP_KERNEL);
if (head == NULL)
return -ENOBUFS;
head->mask = mask;
tcf_tree_lock(tp);
tp->root = head;
tcf_tree_unlock(tp);
}
f = kzalloc(sizeof(struct fw_filter), GFP_KERNEL);
if (f == NULL)
return -ENOBUFS;
tcf_exts_init(&f->exts, TCA_FW_ACT, TCA_FW_POLICE);
f->id = handle;
err = fw_change_attrs(net, tp, f, tb, tca, base);
if (err < 0)
goto errout;
f->next = head->ht[fw_hash(handle)];
tcf_tree_lock(tp);
head->ht[fw_hash(handle)] = f;
tcf_tree_unlock(tp);
*arg = (unsigned long)f;
return 0;
errout:
kfree(f);
return err;
}
static void fw_walk(struct tcf_proto *tp, struct tcf_walker *arg)
{
struct fw_head *head = tp->root;
int h;
if (head == NULL)
arg->stop = 1;
if (arg->stop)
return;
for (h = 0; h < HTSIZE; h++) {
struct fw_filter *f;
for (f = head->ht[h]; f; f = f->next) {
if (arg->count < arg->skip) {
arg->count++;
continue;
}
if (arg->fn(tp, (unsigned long)f, arg) < 0) {
arg->stop = 1;
return;
}
arg->count++;
}
}
}
static int fw_dump(struct net *net, struct tcf_proto *tp, unsigned long fh,
struct sk_buff *skb, struct tcmsg *t)
{
struct fw_head *head = tp->root;
struct fw_filter *f = (struct fw_filter *)fh;
unsigned char *b = skb_tail_pointer(skb);
struct nlattr *nest;
if (f == NULL)
return skb->len;
t->tcm_handle = f->id;
if (!f->res.classid && !tcf_exts_is_available(&f->exts))
return skb->len;
nest = nla_nest_start(skb, TCA_OPTIONS);
if (nest == NULL)
goto nla_put_failure;
if (f->res.classid &&
nla_put_u32(skb, TCA_FW_CLASSID, f->res.classid))
goto nla_put_failure;
#ifdef CONFIG_NET_CLS_IND
if (f->ifindex) {
struct net_device *dev;
dev = __dev_get_by_index(net, f->ifindex);
if (dev && nla_put_string(skb, TCA_FW_INDEV, dev->name))
goto nla_put_failure;
}
#endif
if (head->mask != 0xFFFFFFFF &&
nla_put_u32(skb, TCA_FW_MASK, head->mask))
goto nla_put_failure;
if (tcf_exts_dump(skb, &f->exts) < 0)
goto nla_put_failure;
nla_nest_end(skb, nest);
if (tcf_exts_dump_stats(skb, &f->exts) < 0)
goto nla_put_failure;
return skb->len;
nla_put_failure:
nlmsg_trim(skb, b);
return -1;
}
static int __init init_fw(void)
{
return register_tcf_proto_ops(&cls_fw_ops);
}
static void __exit exit_fw(void)
{
unregister_tcf_proto_ops(&cls_fw_ops);
}
