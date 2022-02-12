static inline int route4_fastmap_hash(u32 id, int iif)
{
return id & 0xF;
}
static void
route4_reset_fastmap(struct Qdisc *q, struct route4_head *head, u32 id)
{
spinlock_t *root_lock = qdisc_root_sleeping_lock(q);
spin_lock_bh(root_lock);
memset(head->fastmap, 0, sizeof(head->fastmap));
spin_unlock_bh(root_lock);
}
static void
route4_set_fastmap(struct route4_head *head, u32 id, int iif,
struct route4_filter *f)
{
int h = route4_fastmap_hash(id, iif);
head->fastmap[h].id = id;
head->fastmap[h].iif = iif;
head->fastmap[h].filter = f;
}
static inline int route4_hash_to(u32 id)
{
return id & 0xFF;
}
static inline int route4_hash_from(u32 id)
{
return (id >> 16) & 0xF;
}
static inline int route4_hash_iif(int iif)
{
return 16 + ((iif >> 16) & 0xF);
}
static inline int route4_hash_wild(void)
{
return 32;
}
static int route4_classify(struct sk_buff *skb, const struct tcf_proto *tp,
struct tcf_result *res)
{
struct route4_head *head = (struct route4_head *)tp->root;
struct dst_entry *dst;
struct route4_bucket *b;
struct route4_filter *f;
u32 id, h;
int iif, dont_cache = 0;
dst = skb_dst(skb);
if (!dst)
goto failure;
id = dst->tclassid;
if (head == NULL)
goto old_method;
iif = inet_iif(skb);
h = route4_fastmap_hash(id, iif);
if (id == head->fastmap[h].id &&
iif == head->fastmap[h].iif &&
(f = head->fastmap[h].filter) != NULL) {
if (f == ROUTE4_FAILURE)
goto failure;
*res = f->res;
return 0;
}
h = route4_hash_to(id);
restart:
b = head->table[h];
if (b) {
for (f = b->ht[route4_hash_from(id)]; f; f = f->next)
if (f->id == id)
ROUTE4_APPLY_RESULT();
for (f = b->ht[route4_hash_iif(iif)]; f; f = f->next)
if (f->iif == iif)
ROUTE4_APPLY_RESULT();
for (f = b->ht[route4_hash_wild()]; f; f = f->next)
ROUTE4_APPLY_RESULT();
}
if (h < 256) {
h = 256;
id &= ~0xFFFF;
goto restart;
}
if (!dont_cache)
route4_set_fastmap(head, id, iif, ROUTE4_FAILURE);
failure:
return -1;
old_method:
if (id && (TC_H_MAJ(id) == 0 ||
!(TC_H_MAJ(id^tp->q->handle)))) {
res->classid = id;
res->class = 0;
return 0;
}
return -1;
}
static inline u32 to_hash(u32 id)
{
u32 h = id & 0xFF;
if (id & 0x8000)
h += 256;
return h;
}
static inline u32 from_hash(u32 id)
{
id &= 0xFFFF;
if (id == 0xFFFF)
return 32;
if (!(id & 0x8000)) {
if (id > 255)
return 256;
return id & 0xF;
}
return 16 + (id & 0xF);
}
static unsigned long route4_get(struct tcf_proto *tp, u32 handle)
{
struct route4_head *head = (struct route4_head *)tp->root;
struct route4_bucket *b;
struct route4_filter *f;
unsigned int h1, h2;
if (!head)
return 0;
h1 = to_hash(handle);
if (h1 > 256)
return 0;
h2 = from_hash(handle >> 16);
if (h2 > 32)
return 0;
b = head->table[h1];
if (b) {
for (f = b->ht[h2]; f; f = f->next)
if (f->handle == handle)
return (unsigned long)f;
}
return 0;
}
static void route4_put(struct tcf_proto *tp, unsigned long f)
{
}
static int route4_init(struct tcf_proto *tp)
{
return 0;
}
static void
route4_delete_filter(struct tcf_proto *tp, struct route4_filter *f)
{
tcf_unbind_filter(tp, &f->res);
tcf_exts_destroy(tp, &f->exts);
kfree(f);
}
static void route4_destroy(struct tcf_proto *tp)
{
struct route4_head *head = tp->root;
int h1, h2;
if (head == NULL)
return;
for (h1 = 0; h1 <= 256; h1++) {
struct route4_bucket *b;
b = head->table[h1];
if (b) {
for (h2 = 0; h2 <= 32; h2++) {
struct route4_filter *f;
while ((f = b->ht[h2]) != NULL) {
b->ht[h2] = f->next;
route4_delete_filter(tp, f);
}
}
kfree(b);
}
}
kfree(head);
}
static int route4_delete(struct tcf_proto *tp, unsigned long arg)
{
struct route4_head *head = (struct route4_head *)tp->root;
struct route4_filter **fp, *f = (struct route4_filter *)arg;
unsigned int h = 0;
struct route4_bucket *b;
int i;
if (!head || !f)
return -EINVAL;
h = f->handle;
b = f->bkt;
for (fp = &b->ht[from_hash(h >> 16)]; *fp; fp = &(*fp)->next) {
if (*fp == f) {
tcf_tree_lock(tp);
*fp = f->next;
tcf_tree_unlock(tp);
route4_reset_fastmap(tp->q, head, f->id);
route4_delete_filter(tp, f);
for (i = 0; i <= 32; i++)
if (b->ht[i])
return 0;
tcf_tree_lock(tp);
head->table[to_hash(h)] = NULL;
tcf_tree_unlock(tp);
kfree(b);
return 0;
}
}
return 0;
}
static int route4_set_parms(struct net *net, struct tcf_proto *tp,
unsigned long base, struct route4_filter *f,
u32 handle, struct route4_head *head,
struct nlattr **tb, struct nlattr *est, int new)
{
int err;
u32 id = 0, to = 0, nhandle = 0x8000;
struct route4_filter *fp;
unsigned int h1;
struct route4_bucket *b;
struct tcf_exts e;
err = tcf_exts_validate(net, tp, tb, est, &e, &route_ext_map);
if (err < 0)
return err;
err = -EINVAL;
if (tb[TCA_ROUTE4_TO]) {
if (new && handle & 0x8000)
goto errout;
to = nla_get_u32(tb[TCA_ROUTE4_TO]);
if (to > 0xFF)
goto errout;
nhandle = to;
}
if (tb[TCA_ROUTE4_FROM]) {
if (tb[TCA_ROUTE4_IIF])
goto errout;
id = nla_get_u32(tb[TCA_ROUTE4_FROM]);
if (id > 0xFF)
goto errout;
nhandle |= id << 16;
} else if (tb[TCA_ROUTE4_IIF]) {
id = nla_get_u32(tb[TCA_ROUTE4_IIF]);
if (id > 0x7FFF)
goto errout;
nhandle |= (id | 0x8000) << 16;
} else
nhandle |= 0xFFFF << 16;
if (handle && new) {
nhandle |= handle & 0x7F00;
if (nhandle != handle)
goto errout;
}
h1 = to_hash(nhandle);
b = head->table[h1];
if (!b) {
err = -ENOBUFS;
b = kzalloc(sizeof(struct route4_bucket), GFP_KERNEL);
if (b == NULL)
goto errout;
tcf_tree_lock(tp);
head->table[h1] = b;
tcf_tree_unlock(tp);
} else {
unsigned int h2 = from_hash(nhandle >> 16);
err = -EEXIST;
for (fp = b->ht[h2]; fp; fp = fp->next)
if (fp->handle == f->handle)
goto errout;
}
tcf_tree_lock(tp);
if (tb[TCA_ROUTE4_TO])
f->id = to;
if (tb[TCA_ROUTE4_FROM])
f->id = to | id<<16;
else if (tb[TCA_ROUTE4_IIF])
f->iif = id;
f->handle = nhandle;
f->bkt = b;
tcf_tree_unlock(tp);
if (tb[TCA_ROUTE4_CLASSID]) {
f->res.classid = nla_get_u32(tb[TCA_ROUTE4_CLASSID]);
tcf_bind_filter(tp, &f->res, base);
}
tcf_exts_change(tp, &f->exts, &e);
return 0;
errout:
tcf_exts_destroy(tp, &e);
return err;
}
static int route4_change(struct net *net, struct sk_buff *in_skb,
struct tcf_proto *tp, unsigned long base,
u32 handle,
struct nlattr **tca,
unsigned long *arg)
{
struct route4_head *head = tp->root;
struct route4_filter *f, *f1, **fp;
struct route4_bucket *b;
struct nlattr *opt = tca[TCA_OPTIONS];
struct nlattr *tb[TCA_ROUTE4_MAX + 1];
unsigned int h, th;
u32 old_handle = 0;
int err;
if (opt == NULL)
return handle ? -EINVAL : 0;
err = nla_parse_nested(tb, TCA_ROUTE4_MAX, opt, route4_policy);
if (err < 0)
return err;
f = (struct route4_filter *)*arg;
if (f) {
if (f->handle != handle && handle)
return -EINVAL;
if (f->bkt)
old_handle = f->handle;
err = route4_set_parms(net, tp, base, f, handle, head, tb,
tca[TCA_RATE], 0);
if (err < 0)
return err;
goto reinsert;
}
err = -ENOBUFS;
if (head == NULL) {
head = kzalloc(sizeof(struct route4_head), GFP_KERNEL);
if (head == NULL)
goto errout;
tcf_tree_lock(tp);
tp->root = head;
tcf_tree_unlock(tp);
}
f = kzalloc(sizeof(struct route4_filter), GFP_KERNEL);
if (f == NULL)
goto errout;
err = route4_set_parms(net, tp, base, f, handle, head, tb,
tca[TCA_RATE], 1);
if (err < 0)
goto errout;
reinsert:
h = from_hash(f->handle >> 16);
for (fp = &f->bkt->ht[h]; (f1 = *fp) != NULL; fp = &f1->next)
if (f->handle < f1->handle)
break;
f->next = f1;
tcf_tree_lock(tp);
*fp = f;
if (old_handle && f->handle != old_handle) {
th = to_hash(old_handle);
h = from_hash(old_handle >> 16);
b = head->table[th];
if (b) {
for (fp = &b->ht[h]; *fp; fp = &(*fp)->next) {
if (*fp == f) {
*fp = f->next;
break;
}
}
}
}
tcf_tree_unlock(tp);
route4_reset_fastmap(tp->q, head, f->id);
*arg = (unsigned long)f;
return 0;
errout:
kfree(f);
return err;
}
static void route4_walk(struct tcf_proto *tp, struct tcf_walker *arg)
{
struct route4_head *head = tp->root;
unsigned int h, h1;
if (head == NULL)
arg->stop = 1;
if (arg->stop)
return;
for (h = 0; h <= 256; h++) {
struct route4_bucket *b = head->table[h];
if (b) {
for (h1 = 0; h1 <= 32; h1++) {
struct route4_filter *f;
for (f = b->ht[h1]; f; f = f->next) {
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
}
}
static int route4_dump(struct tcf_proto *tp, unsigned long fh,
struct sk_buff *skb, struct tcmsg *t)
{
struct route4_filter *f = (struct route4_filter *)fh;
unsigned char *b = skb_tail_pointer(skb);
struct nlattr *nest;
u32 id;
if (f == NULL)
return skb->len;
t->tcm_handle = f->handle;
nest = nla_nest_start(skb, TCA_OPTIONS);
if (nest == NULL)
goto nla_put_failure;
if (!(f->handle & 0x8000)) {
id = f->id & 0xFF;
if (nla_put_u32(skb, TCA_ROUTE4_TO, id))
goto nla_put_failure;
}
if (f->handle & 0x80000000) {
if ((f->handle >> 16) != 0xFFFF &&
nla_put_u32(skb, TCA_ROUTE4_IIF, f->iif))
goto nla_put_failure;
} else {
id = f->id >> 16;
if (nla_put_u32(skb, TCA_ROUTE4_FROM, id))
goto nla_put_failure;
}
if (f->res.classid &&
nla_put_u32(skb, TCA_ROUTE4_CLASSID, f->res.classid))
goto nla_put_failure;
if (tcf_exts_dump(skb, &f->exts, &route_ext_map) < 0)
goto nla_put_failure;
nla_nest_end(skb, nest);
if (tcf_exts_dump_stats(skb, &f->exts, &route_ext_map) < 0)
goto nla_put_failure;
return skb->len;
nla_put_failure:
nlmsg_trim(skb, b);
return -1;
}
static int __init init_route4(void)
{
return register_tcf_proto_ops(&cls_route4_ops);
}
static void __exit exit_route4(void)
{
unregister_tcf_proto_ops(&cls_route4_ops);
}
