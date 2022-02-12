static int call_fib_entry_notifier(struct notifier_block *nb, struct net *net,
enum fib_event_type event_type, u32 dst,
int dst_len, struct fib_info *fi,
u8 tos, u8 type, u32 tb_id)
{
struct fib_entry_notifier_info info = {
.dst = dst,
.dst_len = dst_len,
.fi = fi,
.tos = tos,
.type = type,
.tb_id = tb_id,
};
return call_fib_notifier(nb, net, event_type, &info.info);
}
static int call_fib_entry_notifiers(struct net *net,
enum fib_event_type event_type, u32 dst,
int dst_len, struct fib_info *fi,
u8 tos, u8 type, u32 tb_id)
{
struct fib_entry_notifier_info info = {
.dst = dst,
.dst_len = dst_len,
.fi = fi,
.tos = tos,
.type = type,
.tb_id = tb_id,
};
return call_fib_notifiers(net, event_type, &info.info);
}
static inline struct tnode *tn_info(struct key_vector *kv)
{
return container_of(kv, struct tnode, kv[0]);
}
static inline void node_set_parent(struct key_vector *n, struct key_vector *tp)
{
if (n)
rcu_assign_pointer(tn_info(n)->parent, tp);
}
static inline unsigned long child_length(const struct key_vector *tn)
{
return (1ul << tn->bits) & ~(1ul);
}
static inline unsigned long get_index(t_key key, struct key_vector *kv)
{
unsigned long index = key ^ kv->key;
if ((BITS_PER_LONG <= KEYLENGTH) && (KEYLENGTH == kv->pos))
return 0;
return index >> kv->pos;
}
static void __alias_free_mem(struct rcu_head *head)
{
struct fib_alias *fa = container_of(head, struct fib_alias, rcu);
kmem_cache_free(fn_alias_kmem, fa);
}
static inline void alias_free_mem_rcu(struct fib_alias *fa)
{
call_rcu(&fa->rcu, __alias_free_mem);
}
static void __node_free_rcu(struct rcu_head *head)
{
struct tnode *n = container_of(head, struct tnode, rcu);
if (!n->tn_bits)
kmem_cache_free(trie_leaf_kmem, n);
else
kvfree(n);
}
static struct tnode *tnode_alloc(int bits)
{
size_t size;
if (bits > TNODE_VMALLOC_MAX)
return NULL;
size = TNODE_SIZE(1ul << bits);
if (size <= PAGE_SIZE)
return kzalloc(size, GFP_KERNEL);
else
return vzalloc(size);
}
static inline void empty_child_inc(struct key_vector *n)
{
++tn_info(n)->empty_children ? : ++tn_info(n)->full_children;
}
static inline void empty_child_dec(struct key_vector *n)
{
tn_info(n)->empty_children-- ? : tn_info(n)->full_children--;
}
static struct key_vector *leaf_new(t_key key, struct fib_alias *fa)
{
struct key_vector *l;
struct tnode *kv;
kv = kmem_cache_alloc(trie_leaf_kmem, GFP_KERNEL);
if (!kv)
return NULL;
l = kv->kv;
l->key = key;
l->pos = 0;
l->bits = 0;
l->slen = fa->fa_slen;
INIT_HLIST_HEAD(&l->leaf);
hlist_add_head(&fa->fa_list, &l->leaf);
return l;
}
static struct key_vector *tnode_new(t_key key, int pos, int bits)
{
unsigned int shift = pos + bits;
struct key_vector *tn;
struct tnode *tnode;
BUG_ON(!bits || (shift > KEYLENGTH));
tnode = tnode_alloc(bits);
if (!tnode)
return NULL;
pr_debug("AT %p s=%zu %zu\n", tnode, TNODE_SIZE(0),
sizeof(struct key_vector *) << bits);
if (bits == KEYLENGTH)
tnode->full_children = 1;
else
tnode->empty_children = 1ul << bits;
tn = tnode->kv;
tn->key = (shift < KEYLENGTH) ? (key >> shift) << shift : 0;
tn->pos = pos;
tn->bits = bits;
tn->slen = pos;
return tn;
}
static inline int tnode_full(struct key_vector *tn, struct key_vector *n)
{
return n && ((n->pos + n->bits) == tn->pos) && IS_TNODE(n);
}
static void put_child(struct key_vector *tn, unsigned long i,
struct key_vector *n)
{
struct key_vector *chi = get_child(tn, i);
int isfull, wasfull;
BUG_ON(i >= child_length(tn));
if (!n && chi)
empty_child_inc(tn);
if (n && !chi)
empty_child_dec(tn);
wasfull = tnode_full(tn, chi);
isfull = tnode_full(tn, n);
if (wasfull && !isfull)
tn_info(tn)->full_children--;
else if (!wasfull && isfull)
tn_info(tn)->full_children++;
if (n && (tn->slen < n->slen))
tn->slen = n->slen;
rcu_assign_pointer(tn->tnode[i], n);
}
static void update_children(struct key_vector *tn)
{
unsigned long i;
for (i = child_length(tn); i;) {
struct key_vector *inode = get_child(tn, --i);
if (!inode)
continue;
if (node_parent(inode) == tn)
update_children(inode);
else
node_set_parent(inode, tn);
}
}
static inline void put_child_root(struct key_vector *tp, t_key key,
struct key_vector *n)
{
if (IS_TRIE(tp))
rcu_assign_pointer(tp->tnode[0], n);
else
put_child(tp, get_index(key, tp), n);
}
static inline void tnode_free_init(struct key_vector *tn)
{
tn_info(tn)->rcu.next = NULL;
}
static inline void tnode_free_append(struct key_vector *tn,
struct key_vector *n)
{
tn_info(n)->rcu.next = tn_info(tn)->rcu.next;
tn_info(tn)->rcu.next = &tn_info(n)->rcu;
}
static void tnode_free(struct key_vector *tn)
{
struct callback_head *head = &tn_info(tn)->rcu;
while (head) {
head = head->next;
tnode_free_size += TNODE_SIZE(1ul << tn->bits);
node_free(tn);
tn = container_of(head, struct tnode, rcu)->kv;
}
if (tnode_free_size >= PAGE_SIZE * sync_pages) {
tnode_free_size = 0;
synchronize_rcu();
}
}
static struct key_vector *replace(struct trie *t,
struct key_vector *oldtnode,
struct key_vector *tn)
{
struct key_vector *tp = node_parent(oldtnode);
unsigned long i;
NODE_INIT_PARENT(tn, tp);
put_child_root(tp, tn->key, tn);
update_children(tn);
tnode_free(oldtnode);
for (i = child_length(tn); i;) {
struct key_vector *inode = get_child(tn, --i);
if (tnode_full(tn, inode))
tn = resize(t, inode);
}
return tp;
}
static struct key_vector *inflate(struct trie *t,
struct key_vector *oldtnode)
{
struct key_vector *tn;
unsigned long i;
t_key m;
pr_debug("In inflate\n");
tn = tnode_new(oldtnode->key, oldtnode->pos - 1, oldtnode->bits + 1);
if (!tn)
goto notnode;
tnode_free_init(oldtnode);
for (i = child_length(oldtnode), m = 1u << tn->pos; i;) {
struct key_vector *inode = get_child(oldtnode, --i);
struct key_vector *node0, *node1;
unsigned long j, k;
if (!inode)
continue;
if (!tnode_full(oldtnode, inode)) {
put_child(tn, get_index(inode->key, tn), inode);
continue;
}
tnode_free_append(oldtnode, inode);
if (inode->bits == 1) {
put_child(tn, 2 * i + 1, get_child(inode, 1));
put_child(tn, 2 * i, get_child(inode, 0));
continue;
}
node1 = tnode_new(inode->key | m, inode->pos, inode->bits - 1);
if (!node1)
goto nomem;
node0 = tnode_new(inode->key, inode->pos, inode->bits - 1);
tnode_free_append(tn, node1);
if (!node0)
goto nomem;
tnode_free_append(tn, node0);
for (k = child_length(inode), j = k / 2; j;) {
put_child(node1, --j, get_child(inode, --k));
put_child(node0, j, get_child(inode, j));
put_child(node1, --j, get_child(inode, --k));
put_child(node0, j, get_child(inode, j));
}
NODE_INIT_PARENT(node1, tn);
NODE_INIT_PARENT(node0, tn);
put_child(tn, 2 * i + 1, node1);
put_child(tn, 2 * i, node0);
}
return replace(t, oldtnode, tn);
nomem:
tnode_free(tn);
notnode:
return NULL;
}
static struct key_vector *halve(struct trie *t,
struct key_vector *oldtnode)
{
struct key_vector *tn;
unsigned long i;
pr_debug("In halve\n");
tn = tnode_new(oldtnode->key, oldtnode->pos + 1, oldtnode->bits - 1);
if (!tn)
goto notnode;
tnode_free_init(oldtnode);
for (i = child_length(oldtnode); i;) {
struct key_vector *node1 = get_child(oldtnode, --i);
struct key_vector *node0 = get_child(oldtnode, --i);
struct key_vector *inode;
if (!node1 || !node0) {
put_child(tn, i / 2, node1 ? : node0);
continue;
}
inode = tnode_new(node0->key, oldtnode->pos, 1);
if (!inode)
goto nomem;
tnode_free_append(tn, inode);
put_child(inode, 1, node1);
put_child(inode, 0, node0);
NODE_INIT_PARENT(inode, tn);
put_child(tn, i / 2, inode);
}
return replace(t, oldtnode, tn);
nomem:
tnode_free(tn);
notnode:
return NULL;
}
static struct key_vector *collapse(struct trie *t,
struct key_vector *oldtnode)
{
struct key_vector *n, *tp;
unsigned long i;
for (n = NULL, i = child_length(oldtnode); !n && i;)
n = get_child(oldtnode, --i);
tp = node_parent(oldtnode);
put_child_root(tp, oldtnode->key, n);
node_set_parent(n, tp);
node_free(oldtnode);
return tp;
}
static unsigned char update_suffix(struct key_vector *tn)
{
unsigned char slen = tn->pos;
unsigned long stride, i;
unsigned char slen_max;
slen_max = min_t(unsigned char, tn->pos + tn->bits - 1, tn->slen);
for (i = 0, stride = 0x2ul ; i < child_length(tn); i += stride) {
struct key_vector *n = get_child(tn, i);
if (!n || (n->slen <= slen))
continue;
stride <<= (n->slen - slen);
slen = n->slen;
i &= ~(stride - 1);
if (slen >= slen_max)
break;
}
tn->slen = slen;
return slen;
}
static inline bool should_inflate(struct key_vector *tp, struct key_vector *tn)
{
unsigned long used = child_length(tn);
unsigned long threshold = used;
threshold *= IS_TRIE(tp) ? inflate_threshold_root : inflate_threshold;
used -= tn_info(tn)->empty_children;
used += tn_info(tn)->full_children;
return (used > 1) && tn->pos && ((50 * used) >= threshold);
}
static inline bool should_halve(struct key_vector *tp, struct key_vector *tn)
{
unsigned long used = child_length(tn);
unsigned long threshold = used;
threshold *= IS_TRIE(tp) ? halve_threshold_root : halve_threshold;
used -= tn_info(tn)->empty_children;
return (used > 1) && (tn->bits > 1) && ((100 * used) < threshold);
}
static inline bool should_collapse(struct key_vector *tn)
{
unsigned long used = child_length(tn);
used -= tn_info(tn)->empty_children;
if ((tn->bits == KEYLENGTH) && tn_info(tn)->full_children)
used -= KEY_MAX;
return used < 2;
}
static struct key_vector *resize(struct trie *t, struct key_vector *tn)
{
#ifdef CONFIG_IP_FIB_TRIE_STATS
struct trie_use_stats __percpu *stats = t->stats;
#endif
struct key_vector *tp = node_parent(tn);
unsigned long cindex = get_index(tn->key, tp);
int max_work = MAX_WORK;
pr_debug("In tnode_resize %p inflate_threshold=%d threshold=%d\n",
tn, inflate_threshold, halve_threshold);
BUG_ON(tn != get_child(tp, cindex));
while (should_inflate(tp, tn) && max_work) {
tp = inflate(t, tn);
if (!tp) {
#ifdef CONFIG_IP_FIB_TRIE_STATS
this_cpu_inc(stats->resize_node_skipped);
#endif
break;
}
max_work--;
tn = get_child(tp, cindex);
}
tp = node_parent(tn);
if (max_work != MAX_WORK)
return tp;
while (should_halve(tp, tn) && max_work) {
tp = halve(t, tn);
if (!tp) {
#ifdef CONFIG_IP_FIB_TRIE_STATS
this_cpu_inc(stats->resize_node_skipped);
#endif
break;
}
max_work--;
tn = get_child(tp, cindex);
}
if (should_collapse(tn))
return collapse(t, tn);
return node_parent(tn);
}
static void node_pull_suffix(struct key_vector *tn, unsigned char slen)
{
unsigned char node_slen = tn->slen;
while ((node_slen > tn->pos) && (node_slen > slen)) {
slen = update_suffix(tn);
if (node_slen == slen)
break;
tn = node_parent(tn);
node_slen = tn->slen;
}
}
static void node_push_suffix(struct key_vector *tn, unsigned char slen)
{
while (tn->slen < slen) {
tn->slen = slen;
tn = node_parent(tn);
}
}
static struct key_vector *fib_find_node(struct trie *t,
struct key_vector **tp, u32 key)
{
struct key_vector *pn, *n = t->kv;
unsigned long index = 0;
do {
pn = n;
n = get_child_rcu(n, index);
if (!n)
break;
index = get_cindex(key, n);
if (index >= (1ul << n->bits)) {
n = NULL;
break;
}
} while (IS_TNODE(n));
*tp = pn;
return n;
}
static struct fib_alias *fib_find_alias(struct hlist_head *fah, u8 slen,
u8 tos, u32 prio, u32 tb_id)
{
struct fib_alias *fa;
if (!fah)
return NULL;
hlist_for_each_entry(fa, fah, fa_list) {
if (fa->fa_slen < slen)
continue;
if (fa->fa_slen != slen)
break;
if (fa->tb_id > tb_id)
continue;
if (fa->tb_id != tb_id)
break;
if (fa->fa_tos > tos)
continue;
if (fa->fa_info->fib_priority >= prio || fa->fa_tos < tos)
return fa;
}
return NULL;
}
static void trie_rebalance(struct trie *t, struct key_vector *tn)
{
while (!IS_TRIE(tn))
tn = resize(t, tn);
}
static int fib_insert_node(struct trie *t, struct key_vector *tp,
struct fib_alias *new, t_key key)
{
struct key_vector *n, *l;
l = leaf_new(key, new);
if (!l)
goto noleaf;
n = get_child(tp, get_index(key, tp));
if (n) {
struct key_vector *tn;
tn = tnode_new(key, __fls(key ^ n->key), 1);
if (!tn)
goto notnode;
NODE_INIT_PARENT(tn, tp);
put_child(tn, get_index(key, tn) ^ 1, n);
put_child_root(tp, key, tn);
node_set_parent(n, tn);
tp = tn;
}
node_push_suffix(tp, new->fa_slen);
NODE_INIT_PARENT(l, tp);
put_child_root(tp, key, l);
trie_rebalance(t, tp);
return 0;
notnode:
node_free(l);
noleaf:
return -ENOMEM;
}
static int fib_insert_alias(struct trie *t, struct key_vector *tp,
struct key_vector *l, struct fib_alias *new,
struct fib_alias *fa, t_key key)
{
if (!l)
return fib_insert_node(t, tp, new, key);
if (fa) {
hlist_add_before_rcu(&new->fa_list, &fa->fa_list);
} else {
struct fib_alias *last;
hlist_for_each_entry(last, &l->leaf, fa_list) {
if (new->fa_slen < last->fa_slen)
break;
if ((new->fa_slen == last->fa_slen) &&
(new->tb_id > last->tb_id))
break;
fa = last;
}
if (fa)
hlist_add_behind_rcu(&new->fa_list, &fa->fa_list);
else
hlist_add_head_rcu(&new->fa_list, &l->leaf);
}
if (l->slen < new->fa_slen) {
l->slen = new->fa_slen;
node_push_suffix(tp, new->fa_slen);
}
return 0;
}
int fib_table_insert(struct net *net, struct fib_table *tb,
struct fib_config *cfg)
{
enum fib_event_type event = FIB_EVENT_ENTRY_ADD;
struct trie *t = (struct trie *)tb->tb_data;
struct fib_alias *fa, *new_fa;
struct key_vector *l, *tp;
u16 nlflags = NLM_F_EXCL;
struct fib_info *fi;
u8 plen = cfg->fc_dst_len;
u8 slen = KEYLENGTH - plen;
u8 tos = cfg->fc_tos;
u32 key;
int err;
if (plen > KEYLENGTH)
return -EINVAL;
key = ntohl(cfg->fc_dst);
pr_debug("Insert table=%u %08x/%d\n", tb->tb_id, key, plen);
if ((plen < KEYLENGTH) && (key << plen))
return -EINVAL;
fi = fib_create_info(cfg);
if (IS_ERR(fi)) {
err = PTR_ERR(fi);
goto err;
}
l = fib_find_node(t, &tp, key);
fa = l ? fib_find_alias(&l->leaf, slen, tos, fi->fib_priority,
tb->tb_id) : NULL;
if (fa && fa->fa_tos == tos &&
fa->fa_info->fib_priority == fi->fib_priority) {
struct fib_alias *fa_first, *fa_match;
err = -EEXIST;
if (cfg->fc_nlflags & NLM_F_EXCL)
goto out;
nlflags &= ~NLM_F_EXCL;
fa_match = NULL;
fa_first = fa;
hlist_for_each_entry_from(fa, fa_list) {
if ((fa->fa_slen != slen) ||
(fa->tb_id != tb->tb_id) ||
(fa->fa_tos != tos))
break;
if (fa->fa_info->fib_priority != fi->fib_priority)
break;
if (fa->fa_type == cfg->fc_type &&
fa->fa_info == fi) {
fa_match = fa;
break;
}
}
if (cfg->fc_nlflags & NLM_F_REPLACE) {
struct fib_info *fi_drop;
u8 state;
nlflags |= NLM_F_REPLACE;
fa = fa_first;
if (fa_match) {
if (fa == fa_match)
err = 0;
goto out;
}
err = -ENOBUFS;
new_fa = kmem_cache_alloc(fn_alias_kmem, GFP_KERNEL);
if (!new_fa)
goto out;
fi_drop = fa->fa_info;
new_fa->fa_tos = fa->fa_tos;
new_fa->fa_info = fi;
new_fa->fa_type = cfg->fc_type;
state = fa->fa_state;
new_fa->fa_state = state & ~FA_S_ACCESSED;
new_fa->fa_slen = fa->fa_slen;
new_fa->tb_id = tb->tb_id;
new_fa->fa_default = -1;
call_fib_entry_notifiers(net, FIB_EVENT_ENTRY_REPLACE,
key, plen, fi,
new_fa->fa_tos, cfg->fc_type,
tb->tb_id);
rtmsg_fib(RTM_NEWROUTE, htonl(key), new_fa, plen,
tb->tb_id, &cfg->fc_nlinfo, nlflags);
hlist_replace_rcu(&fa->fa_list, &new_fa->fa_list);
alias_free_mem_rcu(fa);
fib_release_info(fi_drop);
if (state & FA_S_ACCESSED)
rt_cache_flush(cfg->fc_nlinfo.nl_net);
goto succeeded;
}
if (fa_match)
goto out;
if (cfg->fc_nlflags & NLM_F_APPEND) {
event = FIB_EVENT_ENTRY_APPEND;
nlflags |= NLM_F_APPEND;
} else {
fa = fa_first;
}
}
err = -ENOENT;
if (!(cfg->fc_nlflags & NLM_F_CREATE))
goto out;
nlflags |= NLM_F_CREATE;
err = -ENOBUFS;
new_fa = kmem_cache_alloc(fn_alias_kmem, GFP_KERNEL);
if (!new_fa)
goto out;
new_fa->fa_info = fi;
new_fa->fa_tos = tos;
new_fa->fa_type = cfg->fc_type;
new_fa->fa_state = 0;
new_fa->fa_slen = slen;
new_fa->tb_id = tb->tb_id;
new_fa->fa_default = -1;
err = fib_insert_alias(t, tp, l, new_fa, fa, key);
if (err)
goto out_free_new_fa;
if (!plen)
tb->tb_num_default++;
rt_cache_flush(cfg->fc_nlinfo.nl_net);
call_fib_entry_notifiers(net, event, key, plen, fi, tos, cfg->fc_type,
tb->tb_id);
rtmsg_fib(RTM_NEWROUTE, htonl(key), new_fa, plen, new_fa->tb_id,
&cfg->fc_nlinfo, nlflags);
succeeded:
return 0;
out_free_new_fa:
kmem_cache_free(fn_alias_kmem, new_fa);
out:
fib_release_info(fi);
err:
return err;
}
static inline t_key prefix_mismatch(t_key key, struct key_vector *n)
{
t_key prefix = n->key;
return (key ^ prefix) & (prefix | -prefix);
}
int fib_table_lookup(struct fib_table *tb, const struct flowi4 *flp,
struct fib_result *res, int fib_flags)
{
struct trie *t = (struct trie *) tb->tb_data;
#ifdef CONFIG_IP_FIB_TRIE_STATS
struct trie_use_stats __percpu *stats = t->stats;
#endif
const t_key key = ntohl(flp->daddr);
struct key_vector *n, *pn;
struct fib_alias *fa;
unsigned long index;
t_key cindex;
trace_fib_table_lookup(tb->tb_id, flp);
pn = t->kv;
cindex = 0;
n = get_child_rcu(pn, cindex);
if (!n)
return -EAGAIN;
#ifdef CONFIG_IP_FIB_TRIE_STATS
this_cpu_inc(stats->gets);
#endif
for (;;) {
index = get_cindex(key, n);
if (index >= (1ul << n->bits))
break;
if (IS_LEAF(n))
goto found;
if (n->slen > n->pos) {
pn = n;
cindex = index;
}
n = get_child_rcu(n, index);
if (unlikely(!n))
goto backtrace;
}
for (;;) {
struct key_vector __rcu **cptr = n->tnode;
if (unlikely(prefix_mismatch(key, n)) || (n->slen == n->pos))
goto backtrace;
if (unlikely(IS_LEAF(n)))
break;
while ((n = rcu_dereference(*cptr)) == NULL) {
backtrace:
#ifdef CONFIG_IP_FIB_TRIE_STATS
if (!n)
this_cpu_inc(stats->null_node_hit);
#endif
while (!cindex) {
t_key pkey = pn->key;
if (IS_TRIE(pn))
return -EAGAIN;
#ifdef CONFIG_IP_FIB_TRIE_STATS
this_cpu_inc(stats->backtrack);
#endif
pn = node_parent_rcu(pn);
cindex = get_index(pkey, pn);
}
cindex &= cindex - 1;
cptr = &pn->tnode[cindex];
}
}
found:
index = key ^ n->key;
hlist_for_each_entry_rcu(fa, &n->leaf, fa_list) {
struct fib_info *fi = fa->fa_info;
int nhsel, err;
if ((BITS_PER_LONG > KEYLENGTH) || (fa->fa_slen < KEYLENGTH)) {
if (index >= (1ul << fa->fa_slen))
continue;
}
if (fa->fa_tos && fa->fa_tos != flp->flowi4_tos)
continue;
if (fi->fib_dead)
continue;
if (fa->fa_info->fib_scope < flp->flowi4_scope)
continue;
fib_alias_accessed(fa);
err = fib_props[fa->fa_type].error;
if (unlikely(err < 0)) {
#ifdef CONFIG_IP_FIB_TRIE_STATS
this_cpu_inc(stats->semantic_match_passed);
#endif
return err;
}
if (fi->fib_flags & RTNH_F_DEAD)
continue;
for (nhsel = 0; nhsel < fi->fib_nhs; nhsel++) {
const struct fib_nh *nh = &fi->fib_nh[nhsel];
struct in_device *in_dev = __in_dev_get_rcu(nh->nh_dev);
if (nh->nh_flags & RTNH_F_DEAD)
continue;
if (in_dev &&
IN_DEV_IGNORE_ROUTES_WITH_LINKDOWN(in_dev) &&
nh->nh_flags & RTNH_F_LINKDOWN &&
!(fib_flags & FIB_LOOKUP_IGNORE_LINKSTATE))
continue;
if (!(flp->flowi4_flags & FLOWI_FLAG_SKIP_NH_OIF)) {
if (flp->flowi4_oif &&
flp->flowi4_oif != nh->nh_oif)
continue;
}
if (!(fib_flags & FIB_LOOKUP_NOREF))
atomic_inc(&fi->fib_clntref);
res->prefixlen = KEYLENGTH - fa->fa_slen;
res->nh_sel = nhsel;
res->type = fa->fa_type;
res->scope = fi->fib_scope;
res->fi = fi;
res->table = tb;
res->fa_head = &n->leaf;
#ifdef CONFIG_IP_FIB_TRIE_STATS
this_cpu_inc(stats->semantic_match_passed);
#endif
trace_fib_table_lookup_nh(nh);
return err;
}
}
#ifdef CONFIG_IP_FIB_TRIE_STATS
this_cpu_inc(stats->semantic_match_miss);
#endif
goto backtrace;
}
static void fib_remove_alias(struct trie *t, struct key_vector *tp,
struct key_vector *l, struct fib_alias *old)
{
struct hlist_node **pprev = old->fa_list.pprev;
struct fib_alias *fa = hlist_entry(pprev, typeof(*fa), fa_list.next);
hlist_del_rcu(&old->fa_list);
if (hlist_empty(&l->leaf)) {
if (tp->slen == l->slen)
node_pull_suffix(tp, tp->pos);
put_child_root(tp, l->key, NULL);
node_free(l);
trie_rebalance(t, tp);
return;
}
if (*pprev)
return;
l->slen = fa->fa_slen;
node_pull_suffix(tp, fa->fa_slen);
}
int fib_table_delete(struct net *net, struct fib_table *tb,
struct fib_config *cfg)
{
struct trie *t = (struct trie *) tb->tb_data;
struct fib_alias *fa, *fa_to_delete;
struct key_vector *l, *tp;
u8 plen = cfg->fc_dst_len;
u8 slen = KEYLENGTH - plen;
u8 tos = cfg->fc_tos;
u32 key;
if (plen > KEYLENGTH)
return -EINVAL;
key = ntohl(cfg->fc_dst);
if ((plen < KEYLENGTH) && (key << plen))
return -EINVAL;
l = fib_find_node(t, &tp, key);
if (!l)
return -ESRCH;
fa = fib_find_alias(&l->leaf, slen, tos, 0, tb->tb_id);
if (!fa)
return -ESRCH;
pr_debug("Deleting %08x/%d tos=%d t=%p\n", key, plen, tos, t);
fa_to_delete = NULL;
hlist_for_each_entry_from(fa, fa_list) {
struct fib_info *fi = fa->fa_info;
if ((fa->fa_slen != slen) ||
(fa->tb_id != tb->tb_id) ||
(fa->fa_tos != tos))
break;
if ((!cfg->fc_type || fa->fa_type == cfg->fc_type) &&
(cfg->fc_scope == RT_SCOPE_NOWHERE ||
fa->fa_info->fib_scope == cfg->fc_scope) &&
(!cfg->fc_prefsrc ||
fi->fib_prefsrc == cfg->fc_prefsrc) &&
(!cfg->fc_protocol ||
fi->fib_protocol == cfg->fc_protocol) &&
fib_nh_match(cfg, fi) == 0) {
fa_to_delete = fa;
break;
}
}
if (!fa_to_delete)
return -ESRCH;
call_fib_entry_notifiers(net, FIB_EVENT_ENTRY_DEL, key, plen,
fa_to_delete->fa_info, tos,
fa_to_delete->fa_type, tb->tb_id);
rtmsg_fib(RTM_DELROUTE, htonl(key), fa_to_delete, plen, tb->tb_id,
&cfg->fc_nlinfo, 0);
if (!plen)
tb->tb_num_default--;
fib_remove_alias(t, tp, l, fa_to_delete);
if (fa_to_delete->fa_state & FA_S_ACCESSED)
rt_cache_flush(cfg->fc_nlinfo.nl_net);
fib_release_info(fa_to_delete->fa_info);
alias_free_mem_rcu(fa_to_delete);
return 0;
}
static struct key_vector *leaf_walk_rcu(struct key_vector **tn, t_key key)
{
struct key_vector *pn, *n = *tn;
unsigned long cindex;
do {
pn = n;
cindex = (key > pn->key) ? get_index(key, pn) : 0;
if (cindex >> pn->bits)
break;
n = get_child_rcu(pn, cindex++);
if (!n)
break;
if (IS_LEAF(n) && (n->key >= key))
goto found;
} while (IS_TNODE(n));
while (!IS_TRIE(pn)) {
if (cindex >= (1ul << pn->bits)) {
t_key pkey = pn->key;
pn = node_parent_rcu(pn);
cindex = get_index(pkey, pn) + 1;
continue;
}
n = get_child_rcu(pn, cindex++);
if (!n)
continue;
if (IS_LEAF(n))
goto found;
pn = n;
cindex = 0;
}
*tn = pn;
return NULL;
found:
*tn = pn;
return n;
}
static void fib_trie_free(struct fib_table *tb)
{
struct trie *t = (struct trie *)tb->tb_data;
struct key_vector *pn = t->kv;
unsigned long cindex = 1;
struct hlist_node *tmp;
struct fib_alias *fa;
for (;;) {
struct key_vector *n;
if (!(cindex--)) {
t_key pkey = pn->key;
if (IS_TRIE(pn))
break;
n = pn;
pn = node_parent(pn);
put_child_root(pn, n->key, NULL);
node_free(n);
cindex = get_index(pkey, pn);
continue;
}
n = get_child(pn, cindex);
if (!n)
continue;
if (IS_TNODE(n)) {
pn = n;
cindex = 1ul << n->bits;
continue;
}
hlist_for_each_entry_safe(fa, tmp, &n->leaf, fa_list) {
hlist_del_rcu(&fa->fa_list);
alias_free_mem_rcu(fa);
}
put_child_root(pn, n->key, NULL);
node_free(n);
}
#ifdef CONFIG_IP_FIB_TRIE_STATS
free_percpu(t->stats);
#endif
kfree(tb);
}
struct fib_table *fib_trie_unmerge(struct fib_table *oldtb)
{
struct trie *ot = (struct trie *)oldtb->tb_data;
struct key_vector *l, *tp = ot->kv;
struct fib_table *local_tb;
struct fib_alias *fa;
struct trie *lt;
t_key key = 0;
if (oldtb->tb_data == oldtb->__data)
return oldtb;
local_tb = fib_trie_table(RT_TABLE_LOCAL, NULL);
if (!local_tb)
return NULL;
lt = (struct trie *)local_tb->tb_data;
while ((l = leaf_walk_rcu(&tp, key)) != NULL) {
struct key_vector *local_l = NULL, *local_tp;
hlist_for_each_entry_rcu(fa, &l->leaf, fa_list) {
struct fib_alias *new_fa;
if (local_tb->tb_id != fa->tb_id)
continue;
new_fa = kmem_cache_alloc(fn_alias_kmem, GFP_KERNEL);
if (!new_fa)
goto out;
memcpy(new_fa, fa, sizeof(*fa));
if (!local_l)
local_l = fib_find_node(lt, &local_tp, l->key);
if (fib_insert_alias(lt, local_tp, local_l, new_fa,
NULL, l->key)) {
kmem_cache_free(fn_alias_kmem, new_fa);
goto out;
}
}
key = l->key + 1;
if (key < l->key)
break;
}
return local_tb;
out:
fib_trie_free(local_tb);
return NULL;
}
void fib_table_flush_external(struct fib_table *tb)
{
struct trie *t = (struct trie *)tb->tb_data;
struct key_vector *pn = t->kv;
unsigned long cindex = 1;
struct hlist_node *tmp;
struct fib_alias *fa;
for (;;) {
unsigned char slen = 0;
struct key_vector *n;
if (!(cindex--)) {
t_key pkey = pn->key;
if (IS_TRIE(pn))
break;
if (pn->slen > pn->pos)
update_suffix(pn);
pn = resize(t, pn);
cindex = get_index(pkey, pn);
continue;
}
n = get_child(pn, cindex);
if (!n)
continue;
if (IS_TNODE(n)) {
pn = n;
cindex = 1ul << n->bits;
continue;
}
hlist_for_each_entry_safe(fa, tmp, &n->leaf, fa_list) {
if (tb->tb_id != fa->tb_id) {
hlist_del_rcu(&fa->fa_list);
alias_free_mem_rcu(fa);
continue;
}
slen = fa->fa_slen;
}
n->slen = slen;
if (hlist_empty(&n->leaf)) {
put_child_root(pn, n->key, NULL);
node_free(n);
}
}
}
int fib_table_flush(struct net *net, struct fib_table *tb)
{
struct trie *t = (struct trie *)tb->tb_data;
struct key_vector *pn = t->kv;
unsigned long cindex = 1;
struct hlist_node *tmp;
struct fib_alias *fa;
int found = 0;
for (;;) {
unsigned char slen = 0;
struct key_vector *n;
if (!(cindex--)) {
t_key pkey = pn->key;
if (IS_TRIE(pn))
break;
if (pn->slen > pn->pos)
update_suffix(pn);
pn = resize(t, pn);
cindex = get_index(pkey, pn);
continue;
}
n = get_child(pn, cindex);
if (!n)
continue;
if (IS_TNODE(n)) {
pn = n;
cindex = 1ul << n->bits;
continue;
}
hlist_for_each_entry_safe(fa, tmp, &n->leaf, fa_list) {
struct fib_info *fi = fa->fa_info;
if (!fi || !(fi->fib_flags & RTNH_F_DEAD) ||
tb->tb_id != fa->tb_id) {
slen = fa->fa_slen;
continue;
}
call_fib_entry_notifiers(net, FIB_EVENT_ENTRY_DEL,
n->key,
KEYLENGTH - fa->fa_slen,
fi, fa->fa_tos, fa->fa_type,
tb->tb_id);
hlist_del_rcu(&fa->fa_list);
fib_release_info(fa->fa_info);
alias_free_mem_rcu(fa);
found++;
}
n->slen = slen;
if (hlist_empty(&n->leaf)) {
put_child_root(pn, n->key, NULL);
node_free(n);
}
}
pr_debug("trie_flush found=%d\n", found);
return found;
}
static void fib_leaf_notify(struct net *net, struct key_vector *l,
struct fib_table *tb, struct notifier_block *nb)
{
struct fib_alias *fa;
hlist_for_each_entry_rcu(fa, &l->leaf, fa_list) {
struct fib_info *fi = fa->fa_info;
if (!fi)
continue;
if (tb->tb_id != fa->tb_id)
continue;
call_fib_entry_notifier(nb, net, FIB_EVENT_ENTRY_ADD, l->key,
KEYLENGTH - fa->fa_slen, fi, fa->fa_tos,
fa->fa_type, fa->tb_id);
}
}
static void fib_table_notify(struct net *net, struct fib_table *tb,
struct notifier_block *nb)
{
struct trie *t = (struct trie *)tb->tb_data;
struct key_vector *l, *tp = t->kv;
t_key key = 0;
while ((l = leaf_walk_rcu(&tp, key)) != NULL) {
fib_leaf_notify(net, l, tb, nb);
key = l->key + 1;
if (key < l->key)
break;
}
}
void fib_notify(struct net *net, struct notifier_block *nb)
{
unsigned int h;
for (h = 0; h < FIB_TABLE_HASHSZ; h++) {
struct hlist_head *head = &net->ipv4.fib_table_hash[h];
struct fib_table *tb;
hlist_for_each_entry_rcu(tb, head, tb_hlist)
fib_table_notify(net, tb, nb);
}
}
static void __trie_free_rcu(struct rcu_head *head)
{
struct fib_table *tb = container_of(head, struct fib_table, rcu);
#ifdef CONFIG_IP_FIB_TRIE_STATS
struct trie *t = (struct trie *)tb->tb_data;
if (tb->tb_data == tb->__data)
free_percpu(t->stats);
#endif
kfree(tb);
}
void fib_free_table(struct fib_table *tb)
{
call_rcu(&tb->rcu, __trie_free_rcu);
}
static int fn_trie_dump_leaf(struct key_vector *l, struct fib_table *tb,
struct sk_buff *skb, struct netlink_callback *cb)
{
__be32 xkey = htonl(l->key);
struct fib_alias *fa;
int i, s_i;
s_i = cb->args[4];
i = 0;
hlist_for_each_entry_rcu(fa, &l->leaf, fa_list) {
int err;
if (i < s_i) {
i++;
continue;
}
if (tb->tb_id != fa->tb_id) {
i++;
continue;
}
err = fib_dump_info(skb, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, RTM_NEWROUTE,
tb->tb_id, fa->fa_type,
xkey, KEYLENGTH - fa->fa_slen,
fa->fa_tos, fa->fa_info, NLM_F_MULTI);
if (err < 0) {
cb->args[4] = i;
return err;
}
i++;
}
cb->args[4] = i;
return skb->len;
}
int fib_table_dump(struct fib_table *tb, struct sk_buff *skb,
struct netlink_callback *cb)
{
struct trie *t = (struct trie *)tb->tb_data;
struct key_vector *l, *tp = t->kv;
int count = cb->args[2];
t_key key = cb->args[3];
while ((l = leaf_walk_rcu(&tp, key)) != NULL) {
int err;
err = fn_trie_dump_leaf(l, tb, skb, cb);
if (err < 0) {
cb->args[3] = key;
cb->args[2] = count;
return err;
}
++count;
key = l->key + 1;
memset(&cb->args[4], 0,
sizeof(cb->args) - 4*sizeof(cb->args[0]));
if (key < l->key)
break;
}
cb->args[3] = key;
cb->args[2] = count;
return skb->len;
}
void __init fib_trie_init(void)
{
fn_alias_kmem = kmem_cache_create("ip_fib_alias",
sizeof(struct fib_alias),
0, SLAB_PANIC, NULL);
trie_leaf_kmem = kmem_cache_create("ip_fib_trie",
LEAF_SIZE,
0, SLAB_PANIC, NULL);
}
struct fib_table *fib_trie_table(u32 id, struct fib_table *alias)
{
struct fib_table *tb;
struct trie *t;
size_t sz = sizeof(*tb);
if (!alias)
sz += sizeof(struct trie);
tb = kzalloc(sz, GFP_KERNEL);
if (!tb)
return NULL;
tb->tb_id = id;
tb->tb_num_default = 0;
tb->tb_data = (alias ? alias->__data : tb->__data);
if (alias)
return tb;
t = (struct trie *) tb->tb_data;
t->kv[0].pos = KEYLENGTH;
t->kv[0].slen = KEYLENGTH;
#ifdef CONFIG_IP_FIB_TRIE_STATS
t->stats = alloc_percpu(struct trie_use_stats);
if (!t->stats) {
kfree(tb);
tb = NULL;
}
#endif
return tb;
}
static struct key_vector *fib_trie_get_next(struct fib_trie_iter *iter)
{
unsigned long cindex = iter->index;
struct key_vector *pn = iter->tnode;
t_key pkey;
pr_debug("get_next iter={node=%p index=%d depth=%d}\n",
iter->tnode, iter->index, iter->depth);
while (!IS_TRIE(pn)) {
while (cindex < child_length(pn)) {
struct key_vector *n = get_child_rcu(pn, cindex++);
if (!n)
continue;
if (IS_LEAF(n)) {
iter->tnode = pn;
iter->index = cindex;
} else {
iter->tnode = n;
iter->index = 0;
++iter->depth;
}
return n;
}
pkey = pn->key;
pn = node_parent_rcu(pn);
cindex = get_index(pkey, pn) + 1;
--iter->depth;
}
iter->tnode = pn;
iter->index = 0;
return NULL;
}
static struct key_vector *fib_trie_get_first(struct fib_trie_iter *iter,
struct trie *t)
{
struct key_vector *n, *pn;
if (!t)
return NULL;
pn = t->kv;
n = rcu_dereference(pn->tnode[0]);
if (!n)
return NULL;
if (IS_TNODE(n)) {
iter->tnode = n;
iter->index = 0;
iter->depth = 1;
} else {
iter->tnode = pn;
iter->index = 0;
iter->depth = 0;
}
return n;
}
static void trie_collect_stats(struct trie *t, struct trie_stat *s)
{
struct key_vector *n;
struct fib_trie_iter iter;
memset(s, 0, sizeof(*s));
rcu_read_lock();
for (n = fib_trie_get_first(&iter, t); n; n = fib_trie_get_next(&iter)) {
if (IS_LEAF(n)) {
struct fib_alias *fa;
s->leaves++;
s->totdepth += iter.depth;
if (iter.depth > s->maxdepth)
s->maxdepth = iter.depth;
hlist_for_each_entry_rcu(fa, &n->leaf, fa_list)
++s->prefixes;
} else {
s->tnodes++;
if (n->bits < MAX_STAT_DEPTH)
s->nodesizes[n->bits]++;
s->nullpointers += tn_info(n)->empty_children;
}
}
rcu_read_unlock();
}
static void trie_show_stats(struct seq_file *seq, struct trie_stat *stat)
{
unsigned int i, max, pointers, bytes, avdepth;
if (stat->leaves)
avdepth = stat->totdepth*100 / stat->leaves;
else
avdepth = 0;
seq_printf(seq, "\tAver depth: %u.%02d\n",
avdepth / 100, avdepth % 100);
seq_printf(seq, "\tMax depth: %u\n", stat->maxdepth);
seq_printf(seq, "\tLeaves: %u\n", stat->leaves);
bytes = LEAF_SIZE * stat->leaves;
seq_printf(seq, "\tPrefixes: %u\n", stat->prefixes);
bytes += sizeof(struct fib_alias) * stat->prefixes;
seq_printf(seq, "\tInternal nodes: %u\n\t", stat->tnodes);
bytes += TNODE_SIZE(0) * stat->tnodes;
max = MAX_STAT_DEPTH;
while (max > 0 && stat->nodesizes[max-1] == 0)
max--;
pointers = 0;
for (i = 1; i < max; i++)
if (stat->nodesizes[i] != 0) {
seq_printf(seq, " %u: %u", i, stat->nodesizes[i]);
pointers += (1<<i) * stat->nodesizes[i];
}
seq_putc(seq, '\n');
seq_printf(seq, "\tPointers: %u\n", pointers);
bytes += sizeof(struct key_vector *) * pointers;
seq_printf(seq, "Null ptrs: %u\n", stat->nullpointers);
seq_printf(seq, "Total size: %u kB\n", (bytes + 1023) / 1024);
}
static void trie_show_usage(struct seq_file *seq,
const struct trie_use_stats __percpu *stats)
{
struct trie_use_stats s = { 0 };
int cpu;
for_each_possible_cpu(cpu) {
const struct trie_use_stats *pcpu = per_cpu_ptr(stats, cpu);
s.gets += pcpu->gets;
s.backtrack += pcpu->backtrack;
s.semantic_match_passed += pcpu->semantic_match_passed;
s.semantic_match_miss += pcpu->semantic_match_miss;
s.null_node_hit += pcpu->null_node_hit;
s.resize_node_skipped += pcpu->resize_node_skipped;
}
seq_printf(seq, "\nCounters:\n---------\n");
seq_printf(seq, "gets = %u\n", s.gets);
seq_printf(seq, "backtracks = %u\n", s.backtrack);
seq_printf(seq, "semantic match passed = %u\n",
s.semantic_match_passed);
seq_printf(seq, "semantic match miss = %u\n", s.semantic_match_miss);
seq_printf(seq, "null node hit= %u\n", s.null_node_hit);
seq_printf(seq, "skipped node resize = %u\n\n", s.resize_node_skipped);
}
static void fib_table_print(struct seq_file *seq, struct fib_table *tb)
{
if (tb->tb_id == RT_TABLE_LOCAL)
seq_puts(seq, "Local:\n");
else if (tb->tb_id == RT_TABLE_MAIN)
seq_puts(seq, "Main:\n");
else
seq_printf(seq, "Id %d:\n", tb->tb_id);
}
static int fib_triestat_seq_show(struct seq_file *seq, void *v)
{
struct net *net = (struct net *)seq->private;
unsigned int h;
seq_printf(seq,
"Basic info: size of leaf:"
" %zd bytes, size of tnode: %zd bytes.\n",
LEAF_SIZE, TNODE_SIZE(0));
for (h = 0; h < FIB_TABLE_HASHSZ; h++) {
struct hlist_head *head = &net->ipv4.fib_table_hash[h];
struct fib_table *tb;
hlist_for_each_entry_rcu(tb, head, tb_hlist) {
struct trie *t = (struct trie *) tb->tb_data;
struct trie_stat stat;
if (!t)
continue;
fib_table_print(seq, tb);
trie_collect_stats(t, &stat);
trie_show_stats(seq, &stat);
#ifdef CONFIG_IP_FIB_TRIE_STATS
trie_show_usage(seq, t->stats);
#endif
}
}
return 0;
}
static int fib_triestat_seq_open(struct inode *inode, struct file *file)
{
return single_open_net(inode, file, fib_triestat_seq_show);
}
static struct key_vector *fib_trie_get_idx(struct seq_file *seq, loff_t pos)
{
struct fib_trie_iter *iter = seq->private;
struct net *net = seq_file_net(seq);
loff_t idx = 0;
unsigned int h;
for (h = 0; h < FIB_TABLE_HASHSZ; h++) {
struct hlist_head *head = &net->ipv4.fib_table_hash[h];
struct fib_table *tb;
hlist_for_each_entry_rcu(tb, head, tb_hlist) {
struct key_vector *n;
for (n = fib_trie_get_first(iter,
(struct trie *) tb->tb_data);
n; n = fib_trie_get_next(iter))
if (pos == idx++) {
iter->tb = tb;
return n;
}
}
}
return NULL;
}
static void *fib_trie_seq_start(struct seq_file *seq, loff_t *pos)
__acquires(RCU)
{
rcu_read_lock();
return fib_trie_get_idx(seq, *pos);
}
static void *fib_trie_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct fib_trie_iter *iter = seq->private;
struct net *net = seq_file_net(seq);
struct fib_table *tb = iter->tb;
struct hlist_node *tb_node;
unsigned int h;
struct key_vector *n;
++*pos;
n = fib_trie_get_next(iter);
if (n)
return n;
h = tb->tb_id & (FIB_TABLE_HASHSZ - 1);
while ((tb_node = rcu_dereference(hlist_next_rcu(&tb->tb_hlist)))) {
tb = hlist_entry(tb_node, struct fib_table, tb_hlist);
n = fib_trie_get_first(iter, (struct trie *) tb->tb_data);
if (n)
goto found;
}
while (++h < FIB_TABLE_HASHSZ) {
struct hlist_head *head = &net->ipv4.fib_table_hash[h];
hlist_for_each_entry_rcu(tb, head, tb_hlist) {
n = fib_trie_get_first(iter, (struct trie *) tb->tb_data);
if (n)
goto found;
}
}
return NULL;
found:
iter->tb = tb;
return n;
}
static void fib_trie_seq_stop(struct seq_file *seq, void *v)
__releases(RCU)
{
rcu_read_unlock();
}
static void seq_indent(struct seq_file *seq, int n)
{
while (n-- > 0)
seq_puts(seq, " ");
}
static inline const char *rtn_scope(char *buf, size_t len, enum rt_scope_t s)
{
switch (s) {
case RT_SCOPE_UNIVERSE: return "universe";
case RT_SCOPE_SITE: return "site";
case RT_SCOPE_LINK: return "link";
case RT_SCOPE_HOST: return "host";
case RT_SCOPE_NOWHERE: return "nowhere";
default:
snprintf(buf, len, "scope=%d", s);
return buf;
}
}
static inline const char *rtn_type(char *buf, size_t len, unsigned int t)
{
if (t < __RTN_MAX && rtn_type_names[t])
return rtn_type_names[t];
snprintf(buf, len, "type %u", t);
return buf;
}
static int fib_trie_seq_show(struct seq_file *seq, void *v)
{
const struct fib_trie_iter *iter = seq->private;
struct key_vector *n = v;
if (IS_TRIE(node_parent_rcu(n)))
fib_table_print(seq, iter->tb);
if (IS_TNODE(n)) {
__be32 prf = htonl(n->key);
seq_indent(seq, iter->depth-1);
seq_printf(seq, " +-- %pI4/%zu %u %u %u\n",
&prf, KEYLENGTH - n->pos - n->bits, n->bits,
tn_info(n)->full_children,
tn_info(n)->empty_children);
} else {
__be32 val = htonl(n->key);
struct fib_alias *fa;
seq_indent(seq, iter->depth);
seq_printf(seq, " |-- %pI4\n", &val);
hlist_for_each_entry_rcu(fa, &n->leaf, fa_list) {
char buf1[32], buf2[32];
seq_indent(seq, iter->depth + 1);
seq_printf(seq, " /%zu %s %s",
KEYLENGTH - fa->fa_slen,
rtn_scope(buf1, sizeof(buf1),
fa->fa_info->fib_scope),
rtn_type(buf2, sizeof(buf2),
fa->fa_type));
if (fa->fa_tos)
seq_printf(seq, " tos=%d", fa->fa_tos);
seq_putc(seq, '\n');
}
}
return 0;
}
static int fib_trie_seq_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &fib_trie_seq_ops,
sizeof(struct fib_trie_iter));
}
static struct key_vector *fib_route_get_idx(struct fib_route_iter *iter,
loff_t pos)
{
struct key_vector *l, **tp = &iter->tnode;
t_key key;
if (iter->pos > 0 && pos >= iter->pos) {
key = iter->key;
} else {
iter->pos = 1;
key = 0;
}
pos -= iter->pos;
while ((l = leaf_walk_rcu(tp, key)) && (pos-- > 0)) {
key = l->key + 1;
iter->pos++;
l = NULL;
if (!key)
break;
}
if (l)
iter->key = l->key;
else
iter->pos = 0;
return l;
}
static void *fib_route_seq_start(struct seq_file *seq, loff_t *pos)
__acquires(RCU)
{
struct fib_route_iter *iter = seq->private;
struct fib_table *tb;
struct trie *t;
rcu_read_lock();
tb = fib_get_table(seq_file_net(seq), RT_TABLE_MAIN);
if (!tb)
return NULL;
iter->main_tb = tb;
t = (struct trie *)tb->tb_data;
iter->tnode = t->kv;
if (*pos != 0)
return fib_route_get_idx(iter, *pos);
iter->pos = 0;
iter->key = KEY_MAX;
return SEQ_START_TOKEN;
}
static void *fib_route_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct fib_route_iter *iter = seq->private;
struct key_vector *l = NULL;
t_key key = iter->key + 1;
++*pos;
if ((v == SEQ_START_TOKEN) || key)
l = leaf_walk_rcu(&iter->tnode, key);
if (l) {
iter->key = l->key;
iter->pos++;
} else {
iter->pos = 0;
}
return l;
}
static void fib_route_seq_stop(struct seq_file *seq, void *v)
__releases(RCU)
{
rcu_read_unlock();
}
static unsigned int fib_flag_trans(int type, __be32 mask, const struct fib_info *fi)
{
unsigned int flags = 0;
if (type == RTN_UNREACHABLE || type == RTN_PROHIBIT)
flags = RTF_REJECT;
if (fi && fi->fib_nh->nh_gw)
flags |= RTF_GATEWAY;
if (mask == htonl(0xFFFFFFFF))
flags |= RTF_HOST;
flags |= RTF_UP;
return flags;
}
static int fib_route_seq_show(struct seq_file *seq, void *v)
{
struct fib_route_iter *iter = seq->private;
struct fib_table *tb = iter->main_tb;
struct fib_alias *fa;
struct key_vector *l = v;
__be32 prefix;
if (v == SEQ_START_TOKEN) {
seq_printf(seq, "%-127s\n", "Iface\tDestination\tGateway "
"\tFlags\tRefCnt\tUse\tMetric\tMask\t\tMTU"
"\tWindow\tIRTT");
return 0;
}
prefix = htonl(l->key);
hlist_for_each_entry_rcu(fa, &l->leaf, fa_list) {
const struct fib_info *fi = fa->fa_info;
__be32 mask = inet_make_mask(KEYLENGTH - fa->fa_slen);
unsigned int flags = fib_flag_trans(fa->fa_type, mask, fi);
if ((fa->fa_type == RTN_BROADCAST) ||
(fa->fa_type == RTN_MULTICAST))
continue;
if (fa->tb_id != tb->tb_id)
continue;
seq_setwidth(seq, 127);
if (fi)
seq_printf(seq,
"%s\t%08X\t%08X\t%04X\t%d\t%u\t"
"%d\t%08X\t%d\t%u\t%u",
fi->fib_dev ? fi->fib_dev->name : "*",
prefix,
fi->fib_nh->nh_gw, flags, 0, 0,
fi->fib_priority,
mask,
(fi->fib_advmss ?
fi->fib_advmss + 40 : 0),
fi->fib_window,
fi->fib_rtt >> 3);
else
seq_printf(seq,
"*\t%08X\t%08X\t%04X\t%d\t%u\t"
"%d\t%08X\t%d\t%u\t%u",
prefix, 0, flags, 0, 0, 0,
mask, 0, 0, 0);
seq_pad(seq, '\n');
}
return 0;
}
static int fib_route_seq_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &fib_route_seq_ops,
sizeof(struct fib_route_iter));
}
int __net_init fib_proc_init(struct net *net)
{
if (!proc_create("fib_trie", S_IRUGO, net->proc_net, &fib_trie_fops))
goto out1;
if (!proc_create("fib_triestat", S_IRUGO, net->proc_net,
&fib_triestat_fops))
goto out2;
if (!proc_create("route", S_IRUGO, net->proc_net, &fib_route_fops))
goto out3;
return 0;
out3:
remove_proc_entry("fib_triestat", net->proc_net);
out2:
remove_proc_entry("fib_trie", net->proc_net);
out1:
return -ENOMEM;
}
void __net_exit fib_proc_exit(struct net *net)
{
remove_proc_entry("fib_trie", net->proc_net);
remove_proc_entry("fib_triestat", net->proc_net);
remove_proc_entry("route", net->proc_net);
}
