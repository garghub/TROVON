static inline unsigned int u32_hash_fold(__be32 key,
const struct tc_u32_sel *sel,
u8 fshift)
{
unsigned int h = ntohl(key & sel->hmask) >> fshift;
return h;
}
static int u32_classify(struct sk_buff *skb, const struct tcf_proto *tp, struct tcf_result *res)
{
struct {
struct tc_u_knode *knode;
unsigned int off;
} stack[TC_U32_MAXDEPTH];
struct tc_u_hnode *ht = tp->root;
unsigned int off = skb_network_offset(skb);
struct tc_u_knode *n;
int sdepth = 0;
int off2 = 0;
int sel = 0;
#ifdef CONFIG_CLS_U32_PERF
int j;
#endif
int i, r;
next_ht:
n = ht->ht[sel];
next_knode:
if (n) {
struct tc_u32_key *key = n->sel.keys;
#ifdef CONFIG_CLS_U32_PERF
n->pf->rcnt += 1;
j = 0;
#endif
#ifdef CONFIG_CLS_U32_MARK
if ((skb->mark & n->mark.mask) != n->mark.val) {
n = n->next;
goto next_knode;
} else {
n->mark.success++;
}
#endif
for (i = n->sel.nkeys; i > 0; i--, key++) {
int toff = off + key->off + (off2 & key->offmask);
__be32 *data, hdata;
if (skb_headroom(skb) + toff > INT_MAX)
goto out;
data = skb_header_pointer(skb, toff, 4, &hdata);
if (!data)
goto out;
if ((*data ^ key->val) & key->mask) {
n = n->next;
goto next_knode;
}
#ifdef CONFIG_CLS_U32_PERF
n->pf->kcnts[j] += 1;
j++;
#endif
}
if (n->ht_down == NULL) {
check_terminal:
if (n->sel.flags & TC_U32_TERMINAL) {
*res = n->res;
#ifdef CONFIG_NET_CLS_IND
if (!tcf_match_indev(skb, n->ifindex)) {
n = n->next;
goto next_knode;
}
#endif
#ifdef CONFIG_CLS_U32_PERF
n->pf->rhit += 1;
#endif
r = tcf_exts_exec(skb, &n->exts, res);
if (r < 0) {
n = n->next;
goto next_knode;
}
return r;
}
n = n->next;
goto next_knode;
}
if (sdepth >= TC_U32_MAXDEPTH)
goto deadloop;
stack[sdepth].knode = n;
stack[sdepth].off = off;
sdepth++;
ht = n->ht_down;
sel = 0;
if (ht->divisor) {
__be32 *data, hdata;
data = skb_header_pointer(skb, off + n->sel.hoff, 4,
&hdata);
if (!data)
goto out;
sel = ht->divisor & u32_hash_fold(*data, &n->sel,
n->fshift);
}
if (!(n->sel.flags & (TC_U32_VAROFFSET | TC_U32_OFFSET | TC_U32_EAT)))
goto next_ht;
if (n->sel.flags & (TC_U32_OFFSET | TC_U32_VAROFFSET)) {
off2 = n->sel.off + 3;
if (n->sel.flags & TC_U32_VAROFFSET) {
__be16 *data, hdata;
data = skb_header_pointer(skb,
off + n->sel.offoff,
2, &hdata);
if (!data)
goto out;
off2 += ntohs(n->sel.offmask & *data) >>
n->sel.offshift;
}
off2 &= ~3;
}
if (n->sel.flags & TC_U32_EAT) {
off += off2;
off2 = 0;
}
if (off < skb->len)
goto next_ht;
}
if (sdepth--) {
n = stack[sdepth].knode;
ht = n->ht_up;
off = stack[sdepth].off;
goto check_terminal;
}
out:
return -1;
deadloop:
net_warn_ratelimited("cls_u32: dead loop\n");
return -1;
}
static struct tc_u_hnode *
u32_lookup_ht(struct tc_u_common *tp_c, u32 handle)
{
struct tc_u_hnode *ht;
for (ht = tp_c->hlist; ht; ht = ht->next)
if (ht->handle == handle)
break;
return ht;
}
static struct tc_u_knode *
u32_lookup_key(struct tc_u_hnode *ht, u32 handle)
{
unsigned int sel;
struct tc_u_knode *n = NULL;
sel = TC_U32_HASH(handle);
if (sel > ht->divisor)
goto out;
for (n = ht->ht[sel]; n; n = n->next)
if (n->handle == handle)
break;
out:
return n;
}
static unsigned long u32_get(struct tcf_proto *tp, u32 handle)
{
struct tc_u_hnode *ht;
struct tc_u_common *tp_c = tp->data;
if (TC_U32_HTID(handle) == TC_U32_ROOT)
ht = tp->root;
else
ht = u32_lookup_ht(tp_c, TC_U32_HTID(handle));
if (!ht)
return 0;
if (TC_U32_KEY(handle) == 0)
return (unsigned long)ht;
return (unsigned long)u32_lookup_key(ht, handle);
}
static void u32_put(struct tcf_proto *tp, unsigned long f)
{
}
static u32 gen_new_htid(struct tc_u_common *tp_c)
{
int i = 0x800;
do {
if (++tp_c->hgenerator == 0x7FF)
tp_c->hgenerator = 1;
} while (--i > 0 && u32_lookup_ht(tp_c, (tp_c->hgenerator|0x800)<<20));
return i > 0 ? (tp_c->hgenerator|0x800)<<20 : 0;
}
static int u32_init(struct tcf_proto *tp)
{
struct tc_u_hnode *root_ht;
struct tc_u_common *tp_c;
tp_c = tp->q->u32_node;
root_ht = kzalloc(sizeof(*root_ht), GFP_KERNEL);
if (root_ht == NULL)
return -ENOBUFS;
root_ht->divisor = 0;
root_ht->refcnt++;
root_ht->handle = tp_c ? gen_new_htid(tp_c) : 0x80000000;
root_ht->prio = tp->prio;
if (tp_c == NULL) {
tp_c = kzalloc(sizeof(*tp_c), GFP_KERNEL);
if (tp_c == NULL) {
kfree(root_ht);
return -ENOBUFS;
}
tp_c->q = tp->q;
tp->q->u32_node = tp_c;
}
tp_c->refcnt++;
root_ht->next = tp_c->hlist;
tp_c->hlist = root_ht;
root_ht->tp_c = tp_c;
tp->root = root_ht;
tp->data = tp_c;
return 0;
}
static int u32_destroy_key(struct tcf_proto *tp, struct tc_u_knode *n)
{
tcf_unbind_filter(tp, &n->res);
tcf_exts_destroy(tp, &n->exts);
if (n->ht_down)
n->ht_down->refcnt--;
#ifdef CONFIG_CLS_U32_PERF
kfree(n->pf);
#endif
kfree(n);
return 0;
}
static int u32_delete_key(struct tcf_proto *tp, struct tc_u_knode *key)
{
struct tc_u_knode **kp;
struct tc_u_hnode *ht = key->ht_up;
if (ht) {
for (kp = &ht->ht[TC_U32_HASH(key->handle)]; *kp; kp = &(*kp)->next) {
if (*kp == key) {
tcf_tree_lock(tp);
*kp = key->next;
tcf_tree_unlock(tp);
u32_destroy_key(tp, key);
return 0;
}
}
}
WARN_ON(1);
return 0;
}
static void u32_clear_hnode(struct tcf_proto *tp, struct tc_u_hnode *ht)
{
struct tc_u_knode *n;
unsigned int h;
for (h = 0; h <= ht->divisor; h++) {
while ((n = ht->ht[h]) != NULL) {
ht->ht[h] = n->next;
u32_destroy_key(tp, n);
}
}
}
static int u32_destroy_hnode(struct tcf_proto *tp, struct tc_u_hnode *ht)
{
struct tc_u_common *tp_c = tp->data;
struct tc_u_hnode **hn;
WARN_ON(ht->refcnt);
u32_clear_hnode(tp, ht);
for (hn = &tp_c->hlist; *hn; hn = &(*hn)->next) {
if (*hn == ht) {
*hn = ht->next;
kfree(ht);
return 0;
}
}
WARN_ON(1);
return -ENOENT;
}
static void u32_destroy(struct tcf_proto *tp)
{
struct tc_u_common *tp_c = tp->data;
struct tc_u_hnode *root_ht = tp->root;
WARN_ON(root_ht == NULL);
if (root_ht && --root_ht->refcnt == 0)
u32_destroy_hnode(tp, root_ht);
if (--tp_c->refcnt == 0) {
struct tc_u_hnode *ht;
tp->q->u32_node = NULL;
for (ht = tp_c->hlist; ht; ht = ht->next) {
ht->refcnt--;
u32_clear_hnode(tp, ht);
}
while ((ht = tp_c->hlist) != NULL) {
tp_c->hlist = ht->next;
WARN_ON(ht->refcnt != 0);
kfree(ht);
}
kfree(tp_c);
}
tp->data = NULL;
}
static int u32_delete(struct tcf_proto *tp, unsigned long arg)
{
struct tc_u_hnode *ht = (struct tc_u_hnode *)arg;
if (ht == NULL)
return 0;
if (TC_U32_KEY(ht->handle))
return u32_delete_key(tp, (struct tc_u_knode *)ht);
if (tp->root == ht)
return -EINVAL;
if (ht->refcnt == 1) {
ht->refcnt--;
u32_destroy_hnode(tp, ht);
} else {
return -EBUSY;
}
return 0;
}
static u32 gen_new_kid(struct tc_u_hnode *ht, u32 handle)
{
struct tc_u_knode *n;
unsigned int i = 0x7FF;
for (n = ht->ht[TC_U32_HASH(handle)]; n; n = n->next)
if (i < TC_U32_NODE(n->handle))
i = TC_U32_NODE(n->handle);
i++;
return handle | (i > 0xFFF ? 0xFFF : i);
}
static int u32_set_parms(struct net *net, struct tcf_proto *tp,
unsigned long base, struct tc_u_hnode *ht,
struct tc_u_knode *n, struct nlattr **tb,
struct nlattr *est)
{
int err;
struct tcf_exts e;
tcf_exts_init(&e, TCA_U32_ACT, TCA_U32_POLICE);
err = tcf_exts_validate(net, tp, tb, est, &e);
if (err < 0)
return err;
err = -EINVAL;
if (tb[TCA_U32_LINK]) {
u32 handle = nla_get_u32(tb[TCA_U32_LINK]);
struct tc_u_hnode *ht_down = NULL, *ht_old;
if (TC_U32_KEY(handle))
goto errout;
if (handle) {
ht_down = u32_lookup_ht(ht->tp_c, handle);
if (ht_down == NULL)
goto errout;
ht_down->refcnt++;
}
tcf_tree_lock(tp);
ht_old = n->ht_down;
n->ht_down = ht_down;
tcf_tree_unlock(tp);
if (ht_old)
ht_old->refcnt--;
}
if (tb[TCA_U32_CLASSID]) {
n->res.classid = nla_get_u32(tb[TCA_U32_CLASSID]);
tcf_bind_filter(tp, &n->res, base);
}
#ifdef CONFIG_NET_CLS_IND
if (tb[TCA_U32_INDEV]) {
int ret;
ret = tcf_change_indev(net, tb[TCA_U32_INDEV]);
if (ret < 0)
goto errout;
n->ifindex = ret;
}
#endif
tcf_exts_change(tp, &n->exts, &e);
return 0;
errout:
tcf_exts_destroy(tp, &e);
return err;
}
static int u32_change(struct net *net, struct sk_buff *in_skb,
struct tcf_proto *tp, unsigned long base, u32 handle,
struct nlattr **tca,
unsigned long *arg)
{
struct tc_u_common *tp_c = tp->data;
struct tc_u_hnode *ht;
struct tc_u_knode *n;
struct tc_u32_sel *s;
struct nlattr *opt = tca[TCA_OPTIONS];
struct nlattr *tb[TCA_U32_MAX + 1];
u32 htid;
int err;
if (opt == NULL)
return handle ? -EINVAL : 0;
err = nla_parse_nested(tb, TCA_U32_MAX, opt, u32_policy);
if (err < 0)
return err;
n = (struct tc_u_knode *)*arg;
if (n) {
if (TC_U32_KEY(n->handle) == 0)
return -EINVAL;
return u32_set_parms(net, tp, base, n->ht_up, n, tb,
tca[TCA_RATE]);
}
if (tb[TCA_U32_DIVISOR]) {
unsigned int divisor = nla_get_u32(tb[TCA_U32_DIVISOR]);
if (--divisor > 0x100)
return -EINVAL;
if (TC_U32_KEY(handle))
return -EINVAL;
if (handle == 0) {
handle = gen_new_htid(tp->data);
if (handle == 0)
return -ENOMEM;
}
ht = kzalloc(sizeof(*ht) + divisor*sizeof(void *), GFP_KERNEL);
if (ht == NULL)
return -ENOBUFS;
ht->tp_c = tp_c;
ht->refcnt = 1;
ht->divisor = divisor;
ht->handle = handle;
ht->prio = tp->prio;
ht->next = tp_c->hlist;
tp_c->hlist = ht;
*arg = (unsigned long)ht;
return 0;
}
if (tb[TCA_U32_HASH]) {
htid = nla_get_u32(tb[TCA_U32_HASH]);
if (TC_U32_HTID(htid) == TC_U32_ROOT) {
ht = tp->root;
htid = ht->handle;
} else {
ht = u32_lookup_ht(tp->data, TC_U32_HTID(htid));
if (ht == NULL)
return -EINVAL;
}
} else {
ht = tp->root;
htid = ht->handle;
}
if (ht->divisor < TC_U32_HASH(htid))
return -EINVAL;
if (handle) {
if (TC_U32_HTID(handle) && TC_U32_HTID(handle^htid))
return -EINVAL;
handle = htid | TC_U32_NODE(handle);
} else
handle = gen_new_kid(ht, htid);
if (tb[TCA_U32_SEL] == NULL)
return -EINVAL;
s = nla_data(tb[TCA_U32_SEL]);
n = kzalloc(sizeof(*n) + s->nkeys*sizeof(struct tc_u32_key), GFP_KERNEL);
if (n == NULL)
return -ENOBUFS;
#ifdef CONFIG_CLS_U32_PERF
n->pf = kzalloc(sizeof(struct tc_u32_pcnt) + s->nkeys*sizeof(u64), GFP_KERNEL);
if (n->pf == NULL) {
kfree(n);
return -ENOBUFS;
}
#endif
memcpy(&n->sel, s, sizeof(*s) + s->nkeys*sizeof(struct tc_u32_key));
n->ht_up = ht;
n->handle = handle;
n->fshift = s->hmask ? ffs(ntohl(s->hmask)) - 1 : 0;
tcf_exts_init(&n->exts, TCA_U32_ACT, TCA_U32_POLICE);
#ifdef CONFIG_CLS_U32_MARK
if (tb[TCA_U32_MARK]) {
struct tc_u32_mark *mark;
mark = nla_data(tb[TCA_U32_MARK]);
memcpy(&n->mark, mark, sizeof(struct tc_u32_mark));
n->mark.success = 0;
}
#endif
err = u32_set_parms(net, tp, base, ht, n, tb, tca[TCA_RATE]);
if (err == 0) {
struct tc_u_knode **ins;
for (ins = &ht->ht[TC_U32_HASH(handle)]; *ins; ins = &(*ins)->next)
if (TC_U32_NODE(handle) < TC_U32_NODE((*ins)->handle))
break;
n->next = *ins;
tcf_tree_lock(tp);
*ins = n;
tcf_tree_unlock(tp);
*arg = (unsigned long)n;
return 0;
}
#ifdef CONFIG_CLS_U32_PERF
kfree(n->pf);
#endif
kfree(n);
return err;
}
static void u32_walk(struct tcf_proto *tp, struct tcf_walker *arg)
{
struct tc_u_common *tp_c = tp->data;
struct tc_u_hnode *ht;
struct tc_u_knode *n;
unsigned int h;
if (arg->stop)
return;
for (ht = tp_c->hlist; ht; ht = ht->next) {
if (ht->prio != tp->prio)
continue;
if (arg->count >= arg->skip) {
if (arg->fn(tp, (unsigned long)ht, arg) < 0) {
arg->stop = 1;
return;
}
}
arg->count++;
for (h = 0; h <= ht->divisor; h++) {
for (n = ht->ht[h]; n; n = n->next) {
if (arg->count < arg->skip) {
arg->count++;
continue;
}
if (arg->fn(tp, (unsigned long)n, arg) < 0) {
arg->stop = 1;
return;
}
arg->count++;
}
}
}
}
static int u32_dump(struct net *net, struct tcf_proto *tp, unsigned long fh,
struct sk_buff *skb, struct tcmsg *t)
{
struct tc_u_knode *n = (struct tc_u_knode *)fh;
struct nlattr *nest;
if (n == NULL)
return skb->len;
t->tcm_handle = n->handle;
nest = nla_nest_start(skb, TCA_OPTIONS);
if (nest == NULL)
goto nla_put_failure;
if (TC_U32_KEY(n->handle) == 0) {
struct tc_u_hnode *ht = (struct tc_u_hnode *)fh;
u32 divisor = ht->divisor + 1;
if (nla_put_u32(skb, TCA_U32_DIVISOR, divisor))
goto nla_put_failure;
} else {
if (nla_put(skb, TCA_U32_SEL,
sizeof(n->sel) + n->sel.nkeys*sizeof(struct tc_u32_key),
&n->sel))
goto nla_put_failure;
if (n->ht_up) {
u32 htid = n->handle & 0xFFFFF000;
if (nla_put_u32(skb, TCA_U32_HASH, htid))
goto nla_put_failure;
}
if (n->res.classid &&
nla_put_u32(skb, TCA_U32_CLASSID, n->res.classid))
goto nla_put_failure;
if (n->ht_down &&
nla_put_u32(skb, TCA_U32_LINK, n->ht_down->handle))
goto nla_put_failure;
#ifdef CONFIG_CLS_U32_MARK
if ((n->mark.val || n->mark.mask) &&
nla_put(skb, TCA_U32_MARK, sizeof(n->mark), &n->mark))
goto nla_put_failure;
#endif
if (tcf_exts_dump(skb, &n->exts) < 0)
goto nla_put_failure;
#ifdef CONFIG_NET_CLS_IND
if (n->ifindex) {
struct net_device *dev;
dev = __dev_get_by_index(net, n->ifindex);
if (dev && nla_put_string(skb, TCA_U32_INDEV, dev->name))
goto nla_put_failure;
}
#endif
#ifdef CONFIG_CLS_U32_PERF
if (nla_put(skb, TCA_U32_PCNT,
sizeof(struct tc_u32_pcnt) + n->sel.nkeys*sizeof(u64),
n->pf))
goto nla_put_failure;
#endif
}
nla_nest_end(skb, nest);
if (TC_U32_KEY(n->handle))
if (tcf_exts_dump_stats(skb, &n->exts) < 0)
goto nla_put_failure;
return skb->len;
nla_put_failure:
nla_nest_cancel(skb, nest);
return -1;
}
static int __init init_u32(void)
{
pr_info("u32 classifier\n");
#ifdef CONFIG_CLS_U32_PERF
pr_info(" Performance counters on\n");
#endif
#ifdef CONFIG_NET_CLS_IND
pr_info(" input device check on\n");
#endif
#ifdef CONFIG_NET_CLS_ACT
pr_info(" Actions configured\n");
#endif
return register_tcf_proto_ops(&cls_u32_ops);
}
static void __exit exit_u32(void)
{
unregister_tcf_proto_ops(&cls_u32_ops);
}
