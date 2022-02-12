static inline void node_set_parent(struct tnode *n, struct tnode *tp)
{
if (n)
rcu_assign_pointer(n->parent, tp);
}
static inline unsigned long tnode_child_length(const struct tnode *tn)
{
return (1ul << tn->bits) & ~(1ul);
}
static inline struct tnode *tnode_get_child(const struct tnode *tn,
unsigned long i)
{
return rtnl_dereference(tn->child[i]);
}
static inline struct tnode *tnode_get_child_rcu(const struct tnode *tn,
unsigned long i)
{
return rcu_dereference_rtnl(tn->child[i]);
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
if (IS_LEAF(n))
kmem_cache_free(trie_leaf_kmem, n);
else if (n->bits <= TNODE_KMALLOC_MAX)
kfree(n);
else
vfree(n);
}
static inline void free_leaf_info(struct leaf_info *leaf)
{
kfree_rcu(leaf, rcu);
}
static struct tnode *tnode_alloc(size_t size)
{
if (size <= PAGE_SIZE)
return kzalloc(size, GFP_KERNEL);
else
return vzalloc(size);
}
static inline void empty_child_inc(struct tnode *n)
{
++n->empty_children ? : ++n->full_children;
}
static inline void empty_child_dec(struct tnode *n)
{
n->empty_children-- ? : n->full_children--;
}
static struct tnode *leaf_new(t_key key)
{
struct tnode *l = kmem_cache_alloc(trie_leaf_kmem, GFP_KERNEL);
if (l) {
l->parent = NULL;
l->key = key;
l->slen = 0;
l->pos = 0;
l->bits = 0;
INIT_HLIST_HEAD(&l->list);
}
return l;
}
static struct leaf_info *leaf_info_new(int plen)
{
struct leaf_info *li = kmalloc(sizeof(struct leaf_info), GFP_KERNEL);
if (li) {
li->plen = plen;
li->mask_plen = ntohl(inet_make_mask(plen));
INIT_LIST_HEAD(&li->falh);
}
return li;
}
static struct tnode *tnode_new(t_key key, int pos, int bits)
{
size_t sz = offsetof(struct tnode, child[1ul << bits]);
struct tnode *tn = tnode_alloc(sz);
unsigned int shift = pos + bits;
BUG_ON(!bits || (shift > KEYLENGTH));
if (tn) {
tn->parent = NULL;
tn->slen = pos;
tn->pos = pos;
tn->bits = bits;
tn->key = (shift < KEYLENGTH) ? (key >> shift) << shift : 0;
if (bits == KEYLENGTH)
tn->full_children = 1;
else
tn->empty_children = 1ul << bits;
}
pr_debug("AT %p s=%zu %zu\n", tn, sizeof(struct tnode),
sizeof(struct tnode *) << bits);
return tn;
}
static inline int tnode_full(const struct tnode *tn, const struct tnode *n)
{
return n && ((n->pos + n->bits) == tn->pos) && IS_TNODE(n);
}
static void put_child(struct tnode *tn, unsigned long i, struct tnode *n)
{
struct tnode *chi = tnode_get_child(tn, i);
int isfull, wasfull;
BUG_ON(i >= tnode_child_length(tn));
if (n == NULL && chi != NULL)
empty_child_inc(tn);
if (n != NULL && chi == NULL)
empty_child_dec(tn);
wasfull = tnode_full(tn, chi);
isfull = tnode_full(tn, n);
if (wasfull && !isfull)
tn->full_children--;
else if (!wasfull && isfull)
tn->full_children++;
if (n && (tn->slen < n->slen))
tn->slen = n->slen;
rcu_assign_pointer(tn->child[i], n);
}
static void update_children(struct tnode *tn)
{
unsigned long i;
for (i = tnode_child_length(tn); i;) {
struct tnode *inode = tnode_get_child(tn, --i);
if (!inode)
continue;
if (node_parent(inode) == tn)
update_children(inode);
else
node_set_parent(inode, tn);
}
}
static inline void put_child_root(struct tnode *tp, struct trie *t,
t_key key, struct tnode *n)
{
if (tp)
put_child(tp, get_index(key, tp), n);
else
rcu_assign_pointer(t->trie, n);
}
static inline void tnode_free_init(struct tnode *tn)
{
tn->rcu.next = NULL;
}
static inline void tnode_free_append(struct tnode *tn, struct tnode *n)
{
n->rcu.next = tn->rcu.next;
tn->rcu.next = &n->rcu;
}
static void tnode_free(struct tnode *tn)
{
struct callback_head *head = &tn->rcu;
while (head) {
head = head->next;
tnode_free_size += offsetof(struct tnode, child[1 << tn->bits]);
node_free(tn);
tn = container_of(head, struct tnode, rcu);
}
if (tnode_free_size >= PAGE_SIZE * sync_pages) {
tnode_free_size = 0;
synchronize_rcu();
}
}
static void replace(struct trie *t, struct tnode *oldtnode, struct tnode *tn)
{
struct tnode *tp = node_parent(oldtnode);
unsigned long i;
NODE_INIT_PARENT(tn, tp);
put_child_root(tp, t, tn->key, tn);
update_children(tn);
tnode_free(oldtnode);
for (i = tnode_child_length(tn); i;) {
struct tnode *inode = tnode_get_child(tn, --i);
if (tnode_full(tn, inode))
resize(t, inode);
}
}
static int inflate(struct trie *t, struct tnode *oldtnode)
{
struct tnode *tn;
unsigned long i;
t_key m;
pr_debug("In inflate\n");
tn = tnode_new(oldtnode->key, oldtnode->pos - 1, oldtnode->bits + 1);
if (!tn)
return -ENOMEM;
tnode_free_init(oldtnode);
for (i = tnode_child_length(oldtnode), m = 1u << tn->pos; i;) {
struct tnode *inode = tnode_get_child(oldtnode, --i);
struct tnode *node0, *node1;
unsigned long j, k;
if (inode == NULL)
continue;
if (!tnode_full(oldtnode, inode)) {
put_child(tn, get_index(inode->key, tn), inode);
continue;
}
tnode_free_append(oldtnode, inode);
if (inode->bits == 1) {
put_child(tn, 2 * i + 1, tnode_get_child(inode, 1));
put_child(tn, 2 * i, tnode_get_child(inode, 0));
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
for (k = tnode_child_length(inode), j = k / 2; j;) {
put_child(node1, --j, tnode_get_child(inode, --k));
put_child(node0, j, tnode_get_child(inode, j));
put_child(node1, --j, tnode_get_child(inode, --k));
put_child(node0, j, tnode_get_child(inode, j));
}
NODE_INIT_PARENT(node1, tn);
NODE_INIT_PARENT(node0, tn);
put_child(tn, 2 * i + 1, node1);
put_child(tn, 2 * i, node0);
}
replace(t, oldtnode, tn);
return 0;
nomem:
tnode_free(tn);
return -ENOMEM;
}
static int halve(struct trie *t, struct tnode *oldtnode)
{
struct tnode *tn;
unsigned long i;
pr_debug("In halve\n");
tn = tnode_new(oldtnode->key, oldtnode->pos + 1, oldtnode->bits - 1);
if (!tn)
return -ENOMEM;
tnode_free_init(oldtnode);
for (i = tnode_child_length(oldtnode); i;) {
struct tnode *node1 = tnode_get_child(oldtnode, --i);
struct tnode *node0 = tnode_get_child(oldtnode, --i);
struct tnode *inode;
if (!node1 || !node0) {
put_child(tn, i / 2, node1 ? : node0);
continue;
}
inode = tnode_new(node0->key, oldtnode->pos, 1);
if (!inode) {
tnode_free(tn);
return -ENOMEM;
}
tnode_free_append(tn, inode);
put_child(inode, 1, node1);
put_child(inode, 0, node0);
NODE_INIT_PARENT(inode, tn);
put_child(tn, i / 2, inode);
}
replace(t, oldtnode, tn);
return 0;
}
static void collapse(struct trie *t, struct tnode *oldtnode)
{
struct tnode *n, *tp;
unsigned long i;
for (n = NULL, i = tnode_child_length(oldtnode); !n && i;)
n = tnode_get_child(oldtnode, --i);
tp = node_parent(oldtnode);
put_child_root(tp, t, oldtnode->key, n);
node_set_parent(n, tp);
node_free(oldtnode);
}
static unsigned char update_suffix(struct tnode *tn)
{
unsigned char slen = tn->pos;
unsigned long stride, i;
for (i = 0, stride = 0x2ul ; i < tnode_child_length(tn); i += stride) {
struct tnode *n = tnode_get_child(tn, i);
if (!n || (n->slen <= slen))
continue;
stride <<= (n->slen - slen);
slen = n->slen;
i &= ~(stride - 1);
if ((slen + 1) >= (tn->pos + tn->bits))
break;
}
tn->slen = slen;
return slen;
}
static bool should_inflate(const struct tnode *tp, const struct tnode *tn)
{
unsigned long used = tnode_child_length(tn);
unsigned long threshold = used;
threshold *= tp ? inflate_threshold : inflate_threshold_root;
used -= tn->empty_children;
used += tn->full_children;
return (used > 1) && tn->pos && ((50 * used) >= threshold);
}
static bool should_halve(const struct tnode *tp, const struct tnode *tn)
{
unsigned long used = tnode_child_length(tn);
unsigned long threshold = used;
threshold *= tp ? halve_threshold : halve_threshold_root;
used -= tn->empty_children;
return (used > 1) && (tn->bits > 1) && ((100 * used) < threshold);
}
static bool should_collapse(const struct tnode *tn)
{
unsigned long used = tnode_child_length(tn);
used -= tn->empty_children;
if ((tn->bits == KEYLENGTH) && tn->full_children)
used -= KEY_MAX;
return used < 2;
}
static void resize(struct trie *t, struct tnode *tn)
{
struct tnode *tp = node_parent(tn);
struct tnode __rcu **cptr;
int max_work = MAX_WORK;
pr_debug("In tnode_resize %p inflate_threshold=%d threshold=%d\n",
tn, inflate_threshold, halve_threshold);
cptr = tp ? &tp->child[get_index(tn->key, tp)] : &t->trie;
BUG_ON(tn != rtnl_dereference(*cptr));
while (should_inflate(tp, tn) && max_work) {
if (inflate(t, tn)) {
#ifdef CONFIG_IP_FIB_TRIE_STATS
this_cpu_inc(t->stats->resize_node_skipped);
#endif
break;
}
max_work--;
tn = rtnl_dereference(*cptr);
}
if (max_work != MAX_WORK)
return;
while (should_halve(tp, tn) && max_work) {
if (halve(t, tn)) {
#ifdef CONFIG_IP_FIB_TRIE_STATS
this_cpu_inc(t->stats->resize_node_skipped);
#endif
break;
}
max_work--;
tn = rtnl_dereference(*cptr);
}
if (should_collapse(tn)) {
collapse(t, tn);
return;
}
if (max_work != MAX_WORK)
return;
if (tn->slen > tn->pos) {
unsigned char slen = update_suffix(tn);
if (tp && (slen > tp->slen))
tp->slen = slen;
}
}
static struct leaf_info *find_leaf_info(struct tnode *l, int plen)
{
struct hlist_head *head = &l->list;
struct leaf_info *li;
hlist_for_each_entry_rcu(li, head, hlist)
if (li->plen == plen)
return li;
return NULL;
}
static inline struct list_head *get_fa_head(struct tnode *l, int plen)
{
struct leaf_info *li = find_leaf_info(l, plen);
if (!li)
return NULL;
return &li->falh;
}
static void leaf_pull_suffix(struct tnode *l)
{
struct tnode *tp = node_parent(l);
while (tp && (tp->slen > tp->pos) && (tp->slen > l->slen)) {
if (update_suffix(tp) > l->slen)
break;
tp = node_parent(tp);
}
}
static void leaf_push_suffix(struct tnode *l)
{
struct tnode *tn = node_parent(l);
while (tn && (tn->slen < l->slen)) {
tn->slen = l->slen;
tn = node_parent(tn);
}
}
static void remove_leaf_info(struct tnode *l, struct leaf_info *old)
{
struct hlist_node **pprev = old->hlist.pprev;
struct leaf_info *li = hlist_entry(pprev, typeof(*li), hlist.next);
hlist_del_rcu(&old->hlist);
if (hlist_empty(&l->list) || (*pprev))
return;
l->slen = KEYLENGTH - li->plen;
leaf_pull_suffix(l);
}
static void insert_leaf_info(struct tnode *l, struct leaf_info *new)
{
struct hlist_head *head = &l->list;
struct leaf_info *li = NULL, *last = NULL;
if (hlist_empty(head)) {
hlist_add_head_rcu(&new->hlist, head);
} else {
hlist_for_each_entry(li, head, hlist) {
if (new->plen > li->plen)
break;
last = li;
}
if (last)
hlist_add_behind_rcu(&new->hlist, &last->hlist);
else
hlist_add_before_rcu(&new->hlist, &li->hlist);
}
if (l->slen < (KEYLENGTH - new->plen)) {
l->slen = KEYLENGTH - new->plen;
leaf_push_suffix(l);
}
}
static struct tnode *fib_find_node(struct trie *t, u32 key)
{
struct tnode *n = rcu_dereference_rtnl(t->trie);
while (n) {
unsigned long index = get_index(key, n);
if (index & (~0ul << n->bits))
return NULL;
if (IS_LEAF(n))
break;
n = tnode_get_child_rcu(n, index);
}
return n;
}
static struct fib_alias *fib_find_alias(struct list_head *fah, u8 tos, u32 prio)
{
struct fib_alias *fa;
if (!fah)
return NULL;
list_for_each_entry(fa, fah, fa_list) {
if (fa->fa_tos > tos)
continue;
if (fa->fa_info->fib_priority >= prio || fa->fa_tos < tos)
return fa;
}
return NULL;
}
static void trie_rebalance(struct trie *t, struct tnode *tn)
{
struct tnode *tp;
while ((tp = node_parent(tn)) != NULL) {
resize(t, tn);
tn = tp;
}
if (IS_TNODE(tn))
resize(t, tn);
}
static struct list_head *fib_insert_node(struct trie *t, u32 key, int plen)
{
struct list_head *fa_head = NULL;
struct tnode *l, *n, *tp = NULL;
struct leaf_info *li;
li = leaf_info_new(plen);
if (!li)
return NULL;
fa_head = &li->falh;
n = rtnl_dereference(t->trie);
while (n) {
unsigned long index = get_index(key, n);
if (index >> n->bits)
break;
if (IS_LEAF(n)) {
insert_leaf_info(n, li);
return fa_head;
}
tp = n;
n = tnode_get_child_rcu(n, index);
}
l = leaf_new(key);
if (!l) {
free_leaf_info(li);
return NULL;
}
insert_leaf_info(l, li);
if (n) {
struct tnode *tn;
tn = tnode_new(key, __fls(key ^ n->key), 1);
if (!tn) {
free_leaf_info(li);
node_free(l);
return NULL;
}
NODE_INIT_PARENT(tn, tp);
put_child(tn, get_index(key, tn) ^ 1, n);
put_child_root(tp, t, key, tn);
node_set_parent(n, tn);
tp = tn;
}
if (tp) {
NODE_INIT_PARENT(l, tp);
put_child(tp, get_index(key, tp), l);
trie_rebalance(t, tp);
} else {
rcu_assign_pointer(t->trie, l);
}
return fa_head;
}
int fib_table_insert(struct fib_table *tb, struct fib_config *cfg)
{
struct trie *t = (struct trie *) tb->tb_data;
struct fib_alias *fa, *new_fa;
struct list_head *fa_head = NULL;
struct fib_info *fi;
int plen = cfg->fc_dst_len;
u8 tos = cfg->fc_tos;
u32 key, mask;
int err;
struct tnode *l;
if (plen > 32)
return -EINVAL;
key = ntohl(cfg->fc_dst);
pr_debug("Insert table=%u %08x/%d\n", tb->tb_id, key, plen);
mask = ntohl(inet_make_mask(plen));
if (key & ~mask)
return -EINVAL;
key = key & mask;
fi = fib_create_info(cfg);
if (IS_ERR(fi)) {
err = PTR_ERR(fi);
goto err;
}
l = fib_find_node(t, key);
fa = NULL;
if (l) {
fa_head = get_fa_head(l, plen);
fa = fib_find_alias(fa_head, tos, fi->fib_priority);
}
if (fa && fa->fa_tos == tos &&
fa->fa_info->fib_priority == fi->fib_priority) {
struct fib_alias *fa_first, *fa_match;
err = -EEXIST;
if (cfg->fc_nlflags & NLM_F_EXCL)
goto out;
fa_match = NULL;
fa_first = fa;
fa = list_entry(fa->fa_list.prev, struct fib_alias, fa_list);
list_for_each_entry_continue(fa, fa_head, fa_list) {
if (fa->fa_tos != tos)
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
fa = fa_first;
if (fa_match) {
if (fa == fa_match)
err = 0;
goto out;
}
err = -ENOBUFS;
new_fa = kmem_cache_alloc(fn_alias_kmem, GFP_KERNEL);
if (new_fa == NULL)
goto out;
fi_drop = fa->fa_info;
new_fa->fa_tos = fa->fa_tos;
new_fa->fa_info = fi;
new_fa->fa_type = cfg->fc_type;
state = fa->fa_state;
new_fa->fa_state = state & ~FA_S_ACCESSED;
list_replace_rcu(&fa->fa_list, &new_fa->fa_list);
alias_free_mem_rcu(fa);
fib_release_info(fi_drop);
if (state & FA_S_ACCESSED)
rt_cache_flush(cfg->fc_nlinfo.nl_net);
rtmsg_fib(RTM_NEWROUTE, htonl(key), new_fa, plen,
tb->tb_id, &cfg->fc_nlinfo, NLM_F_REPLACE);
goto succeeded;
}
if (fa_match)
goto out;
if (!(cfg->fc_nlflags & NLM_F_APPEND))
fa = fa_first;
}
err = -ENOENT;
if (!(cfg->fc_nlflags & NLM_F_CREATE))
goto out;
err = -ENOBUFS;
new_fa = kmem_cache_alloc(fn_alias_kmem, GFP_KERNEL);
if (new_fa == NULL)
goto out;
new_fa->fa_info = fi;
new_fa->fa_tos = tos;
new_fa->fa_type = cfg->fc_type;
new_fa->fa_state = 0;
if (!fa_head) {
fa_head = fib_insert_node(t, key, plen);
if (unlikely(!fa_head)) {
err = -ENOMEM;
goto out_free_new_fa;
}
}
if (!plen)
tb->tb_num_default++;
list_add_tail_rcu(&new_fa->fa_list,
(fa ? &fa->fa_list : fa_head));
rt_cache_flush(cfg->fc_nlinfo.nl_net);
rtmsg_fib(RTM_NEWROUTE, htonl(key), new_fa, plen, tb->tb_id,
&cfg->fc_nlinfo, 0);
succeeded:
return 0;
out_free_new_fa:
kmem_cache_free(fn_alias_kmem, new_fa);
out:
fib_release_info(fi);
err:
return err;
}
static inline t_key prefix_mismatch(t_key key, struct tnode *n)
{
t_key prefix = n->key;
return (key ^ prefix) & (prefix | -prefix);
}
int fib_table_lookup(struct fib_table *tb, const struct flowi4 *flp,
struct fib_result *res, int fib_flags)
{
struct trie *t = (struct trie *)tb->tb_data;
#ifdef CONFIG_IP_FIB_TRIE_STATS
struct trie_use_stats __percpu *stats = t->stats;
#endif
const t_key key = ntohl(flp->daddr);
struct tnode *n, *pn;
struct leaf_info *li;
t_key cindex;
n = rcu_dereference(t->trie);
if (!n)
return -EAGAIN;
#ifdef CONFIG_IP_FIB_TRIE_STATS
this_cpu_inc(stats->gets);
#endif
pn = n;
cindex = 0;
for (;;) {
unsigned long index = get_index(key, n);
if (index & (~0ul << n->bits))
break;
if (IS_LEAF(n))
goto found;
if (n->slen > n->pos) {
pn = n;
cindex = index;
}
n = tnode_get_child_rcu(n, index);
if (unlikely(!n))
goto backtrace;
}
for (;;) {
struct tnode __rcu **cptr = n->child;
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
pn = node_parent_rcu(pn);
if (unlikely(!pn))
return -EAGAIN;
#ifdef CONFIG_IP_FIB_TRIE_STATS
this_cpu_inc(stats->backtrack);
#endif
cindex = get_index(pkey, pn);
}
cindex &= cindex - 1;
cptr = &pn->child[cindex];
}
}
found:
hlist_for_each_entry_rcu(li, &n->list, hlist) {
struct fib_alias *fa;
if ((key ^ n->key) & li->mask_plen)
continue;
list_for_each_entry_rcu(fa, &li->falh, fa_list) {
struct fib_info *fi = fa->fa_info;
int nhsel, err;
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
if (nh->nh_flags & RTNH_F_DEAD)
continue;
if (flp->flowi4_oif && flp->flowi4_oif != nh->nh_oif)
continue;
if (!(fib_flags & FIB_LOOKUP_NOREF))
atomic_inc(&fi->fib_clntref);
res->prefixlen = li->plen;
res->nh_sel = nhsel;
res->type = fa->fa_type;
res->scope = fi->fib_scope;
res->fi = fi;
res->table = tb;
res->fa_head = &li->falh;
#ifdef CONFIG_IP_FIB_TRIE_STATS
this_cpu_inc(stats->semantic_match_passed);
#endif
return err;
}
}
#ifdef CONFIG_IP_FIB_TRIE_STATS
this_cpu_inc(stats->semantic_match_miss);
#endif
}
goto backtrace;
}
static void trie_leaf_remove(struct trie *t, struct tnode *l)
{
struct tnode *tp = node_parent(l);
pr_debug("entering trie_leaf_remove(%p)\n", l);
if (tp) {
put_child(tp, get_index(l->key, tp), NULL);
trie_rebalance(t, tp);
} else {
RCU_INIT_POINTER(t->trie, NULL);
}
node_free(l);
}
int fib_table_delete(struct fib_table *tb, struct fib_config *cfg)
{
struct trie *t = (struct trie *) tb->tb_data;
u32 key, mask;
int plen = cfg->fc_dst_len;
u8 tos = cfg->fc_tos;
struct fib_alias *fa, *fa_to_delete;
struct list_head *fa_head;
struct tnode *l;
struct leaf_info *li;
if (plen > 32)
return -EINVAL;
key = ntohl(cfg->fc_dst);
mask = ntohl(inet_make_mask(plen));
if (key & ~mask)
return -EINVAL;
key = key & mask;
l = fib_find_node(t, key);
if (!l)
return -ESRCH;
li = find_leaf_info(l, plen);
if (!li)
return -ESRCH;
fa_head = &li->falh;
fa = fib_find_alias(fa_head, tos, 0);
if (!fa)
return -ESRCH;
pr_debug("Deleting %08x/%d tos=%d t=%p\n", key, plen, tos, t);
fa_to_delete = NULL;
fa = list_entry(fa->fa_list.prev, struct fib_alias, fa_list);
list_for_each_entry_continue(fa, fa_head, fa_list) {
struct fib_info *fi = fa->fa_info;
if (fa->fa_tos != tos)
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
fa = fa_to_delete;
rtmsg_fib(RTM_DELROUTE, htonl(key), fa, plen, tb->tb_id,
&cfg->fc_nlinfo, 0);
list_del_rcu(&fa->fa_list);
if (!plen)
tb->tb_num_default--;
if (list_empty(fa_head)) {
remove_leaf_info(l, li);
free_leaf_info(li);
}
if (hlist_empty(&l->list))
trie_leaf_remove(t, l);
if (fa->fa_state & FA_S_ACCESSED)
rt_cache_flush(cfg->fc_nlinfo.nl_net);
fib_release_info(fa->fa_info);
alias_free_mem_rcu(fa);
return 0;
}
static int trie_flush_list(struct list_head *head)
{
struct fib_alias *fa, *fa_node;
int found = 0;
list_for_each_entry_safe(fa, fa_node, head, fa_list) {
struct fib_info *fi = fa->fa_info;
if (fi && (fi->fib_flags & RTNH_F_DEAD)) {
list_del_rcu(&fa->fa_list);
fib_release_info(fa->fa_info);
alias_free_mem_rcu(fa);
found++;
}
}
return found;
}
static int trie_flush_leaf(struct tnode *l)
{
int found = 0;
struct hlist_head *lih = &l->list;
struct hlist_node *tmp;
struct leaf_info *li = NULL;
unsigned char plen = KEYLENGTH;
hlist_for_each_entry_safe(li, tmp, lih, hlist) {
found += trie_flush_list(&li->falh);
if (list_empty(&li->falh)) {
hlist_del_rcu(&li->hlist);
free_leaf_info(li);
continue;
}
plen = li->plen;
}
l->slen = KEYLENGTH - plen;
return found;
}
static struct tnode *leaf_walk_rcu(struct tnode *p, struct tnode *c)
{
do {
unsigned long idx = c ? idx = get_index(c->key, p) + 1 : 0;
while (idx < tnode_child_length(p)) {
c = tnode_get_child_rcu(p, idx++);
if (!c)
continue;
if (IS_LEAF(c))
return c;
p = c;
idx = 0;
}
c = p;
} while ((p = node_parent_rcu(c)) != NULL);
return NULL;
}
static struct tnode *trie_firstleaf(struct trie *t)
{
struct tnode *n = rcu_dereference_rtnl(t->trie);
if (!n)
return NULL;
if (IS_LEAF(n))
return n;
return leaf_walk_rcu(n, NULL);
}
static struct tnode *trie_nextleaf(struct tnode *l)
{
struct tnode *p = node_parent_rcu(l);
if (!p)
return NULL;
return leaf_walk_rcu(p, l);
}
static struct tnode *trie_leafindex(struct trie *t, int index)
{
struct tnode *l = trie_firstleaf(t);
while (l && index-- > 0)
l = trie_nextleaf(l);
return l;
}
int fib_table_flush(struct fib_table *tb)
{
struct trie *t = (struct trie *) tb->tb_data;
struct tnode *l, *ll = NULL;
int found = 0;
for (l = trie_firstleaf(t); l; l = trie_nextleaf(l)) {
found += trie_flush_leaf(l);
if (ll) {
if (hlist_empty(&ll->list))
trie_leaf_remove(t, ll);
else
leaf_pull_suffix(ll);
}
ll = l;
}
if (ll) {
if (hlist_empty(&ll->list))
trie_leaf_remove(t, ll);
else
leaf_pull_suffix(ll);
}
pr_debug("trie_flush found=%d\n", found);
return found;
}
void fib_free_table(struct fib_table *tb)
{
#ifdef CONFIG_IP_FIB_TRIE_STATS
struct trie *t = (struct trie *)tb->tb_data;
free_percpu(t->stats);
#endif
kfree(tb);
}
static int fn_trie_dump_fa(t_key key, int plen, struct list_head *fah,
struct fib_table *tb,
struct sk_buff *skb, struct netlink_callback *cb)
{
int i, s_i;
struct fib_alias *fa;
__be32 xkey = htonl(key);
s_i = cb->args[5];
i = 0;
list_for_each_entry_rcu(fa, fah, fa_list) {
if (i < s_i) {
i++;
continue;
}
if (fib_dump_info(skb, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq,
RTM_NEWROUTE,
tb->tb_id,
fa->fa_type,
xkey,
plen,
fa->fa_tos,
fa->fa_info, NLM_F_MULTI) < 0) {
cb->args[5] = i;
return -1;
}
i++;
}
cb->args[5] = i;
return skb->len;
}
static int fn_trie_dump_leaf(struct tnode *l, struct fib_table *tb,
struct sk_buff *skb, struct netlink_callback *cb)
{
struct leaf_info *li;
int i, s_i;
s_i = cb->args[4];
i = 0;
hlist_for_each_entry_rcu(li, &l->list, hlist) {
if (i < s_i) {
i++;
continue;
}
if (i > s_i)
cb->args[5] = 0;
if (list_empty(&li->falh))
continue;
if (fn_trie_dump_fa(l->key, li->plen, &li->falh, tb, skb, cb) < 0) {
cb->args[4] = i;
return -1;
}
i++;
}
cb->args[4] = i;
return skb->len;
}
int fib_table_dump(struct fib_table *tb, struct sk_buff *skb,
struct netlink_callback *cb)
{
struct tnode *l;
struct trie *t = (struct trie *) tb->tb_data;
t_key key = cb->args[2];
int count = cb->args[3];
rcu_read_lock();
if (count == 0)
l = trie_firstleaf(t);
else {
l = fib_find_node(t, key);
if (!l)
l = trie_leafindex(t, count);
}
while (l) {
cb->args[2] = l->key;
if (fn_trie_dump_leaf(l, tb, skb, cb) < 0) {
cb->args[3] = count;
rcu_read_unlock();
return -1;
}
++count;
l = trie_nextleaf(l);
memset(&cb->args[4], 0,
sizeof(cb->args) - 4*sizeof(cb->args[0]));
}
cb->args[3] = count;
rcu_read_unlock();
return skb->len;
}
void __init fib_trie_init(void)
{
fn_alias_kmem = kmem_cache_create("ip_fib_alias",
sizeof(struct fib_alias),
0, SLAB_PANIC, NULL);
trie_leaf_kmem = kmem_cache_create("ip_fib_trie",
max(sizeof(struct tnode),
sizeof(struct leaf_info)),
0, SLAB_PANIC, NULL);
}
struct fib_table *fib_trie_table(u32 id)
{
struct fib_table *tb;
struct trie *t;
tb = kmalloc(sizeof(struct fib_table) + sizeof(struct trie),
GFP_KERNEL);
if (tb == NULL)
return NULL;
tb->tb_id = id;
tb->tb_default = -1;
tb->tb_num_default = 0;
t = (struct trie *) tb->tb_data;
RCU_INIT_POINTER(t->trie, NULL);
#ifdef CONFIG_IP_FIB_TRIE_STATS
t->stats = alloc_percpu(struct trie_use_stats);
if (!t->stats) {
kfree(tb);
tb = NULL;
}
#endif
return tb;
}
static struct tnode *fib_trie_get_next(struct fib_trie_iter *iter)
{
unsigned long cindex = iter->index;
struct tnode *tn = iter->tnode;
struct tnode *p;
if (!tn)
return NULL;
pr_debug("get_next iter={node=%p index=%d depth=%d}\n",
iter->tnode, iter->index, iter->depth);
rescan:
while (cindex < tnode_child_length(tn)) {
struct tnode *n = tnode_get_child_rcu(tn, cindex);
if (n) {
if (IS_LEAF(n)) {
iter->tnode = tn;
iter->index = cindex + 1;
} else {
iter->tnode = n;
iter->index = 0;
++iter->depth;
}
return n;
}
++cindex;
}
p = node_parent_rcu(tn);
if (p) {
cindex = get_index(tn->key, p) + 1;
tn = p;
--iter->depth;
goto rescan;
}
return NULL;
}
static struct tnode *fib_trie_get_first(struct fib_trie_iter *iter,
struct trie *t)
{
struct tnode *n;
if (!t)
return NULL;
n = rcu_dereference(t->trie);
if (!n)
return NULL;
if (IS_TNODE(n)) {
iter->tnode = n;
iter->index = 0;
iter->depth = 1;
} else {
iter->tnode = NULL;
iter->index = 0;
iter->depth = 0;
}
return n;
}
static void trie_collect_stats(struct trie *t, struct trie_stat *s)
{
struct tnode *n;
struct fib_trie_iter iter;
memset(s, 0, sizeof(*s));
rcu_read_lock();
for (n = fib_trie_get_first(&iter, t); n; n = fib_trie_get_next(&iter)) {
if (IS_LEAF(n)) {
struct leaf_info *li;
s->leaves++;
s->totdepth += iter.depth;
if (iter.depth > s->maxdepth)
s->maxdepth = iter.depth;
hlist_for_each_entry_rcu(li, &n->list, hlist)
++s->prefixes;
} else {
s->tnodes++;
if (n->bits < MAX_STAT_DEPTH)
s->nodesizes[n->bits]++;
s->nullpointers += n->empty_children;
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
bytes = sizeof(struct tnode) * stat->leaves;
seq_printf(seq, "\tPrefixes: %u\n", stat->prefixes);
bytes += sizeof(struct leaf_info) * stat->prefixes;
seq_printf(seq, "\tInternal nodes: %u\n\t", stat->tnodes);
bytes += sizeof(struct tnode) * stat->tnodes;
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
bytes += sizeof(struct tnode *) * pointers;
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
" %Zd bytes, size of tnode: %Zd bytes.\n",
sizeof(struct tnode), sizeof(struct tnode));
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
static struct tnode *fib_trie_get_idx(struct seq_file *seq, loff_t pos)
{
struct fib_trie_iter *iter = seq->private;
struct net *net = seq_file_net(seq);
loff_t idx = 0;
unsigned int h;
for (h = 0; h < FIB_TABLE_HASHSZ; h++) {
struct hlist_head *head = &net->ipv4.fib_table_hash[h];
struct fib_table *tb;
hlist_for_each_entry_rcu(tb, head, tb_hlist) {
struct tnode *n;
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
struct tnode *n;
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
struct tnode *n = v;
if (!node_parent_rcu(n))
fib_table_print(seq, iter->tb);
if (IS_TNODE(n)) {
__be32 prf = htonl(n->key);
seq_indent(seq, iter->depth-1);
seq_printf(seq, " +-- %pI4/%zu %u %u %u\n",
&prf, KEYLENGTH - n->pos - n->bits, n->bits,
n->full_children, n->empty_children);
} else {
struct leaf_info *li;
__be32 val = htonl(n->key);
seq_indent(seq, iter->depth);
seq_printf(seq, " |-- %pI4\n", &val);
hlist_for_each_entry_rcu(li, &n->list, hlist) {
struct fib_alias *fa;
list_for_each_entry_rcu(fa, &li->falh, fa_list) {
char buf1[32], buf2[32];
seq_indent(seq, iter->depth+1);
seq_printf(seq, " /%d %s %s", li->plen,
rtn_scope(buf1, sizeof(buf1),
fa->fa_info->fib_scope),
rtn_type(buf2, sizeof(buf2),
fa->fa_type));
if (fa->fa_tos)
seq_printf(seq, " tos=%d", fa->fa_tos);
seq_putc(seq, '\n');
}
}
}
return 0;
}
static int fib_trie_seq_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &fib_trie_seq_ops,
sizeof(struct fib_trie_iter));
}
static struct tnode *fib_route_get_idx(struct fib_route_iter *iter, loff_t pos)
{
struct tnode *l = NULL;
struct trie *t = iter->main_trie;
if (iter->pos > 0 && pos >= iter->pos && (l = fib_find_node(t, iter->key)))
pos -= iter->pos;
else {
iter->pos = 0;
l = trie_firstleaf(t);
}
while (l && pos-- > 0) {
iter->pos++;
l = trie_nextleaf(l);
}
if (l)
iter->key = pos;
else
iter->pos = 0;
return l;
}
static void *fib_route_seq_start(struct seq_file *seq, loff_t *pos)
__acquires(RCU)
{
struct fib_route_iter *iter = seq->private;
struct fib_table *tb;
rcu_read_lock();
tb = fib_get_table(seq_file_net(seq), RT_TABLE_MAIN);
if (!tb)
return NULL;
iter->main_trie = (struct trie *) tb->tb_data;
if (*pos == 0)
return SEQ_START_TOKEN;
else
return fib_route_get_idx(iter, *pos - 1);
}
static void *fib_route_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct fib_route_iter *iter = seq->private;
struct tnode *l = v;
++*pos;
if (v == SEQ_START_TOKEN) {
iter->pos = 0;
l = trie_firstleaf(iter->main_trie);
} else {
iter->pos++;
l = trie_nextleaf(l);
}
if (l)
iter->key = l->key;
else
iter->pos = 0;
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
struct tnode *l = v;
struct leaf_info *li;
if (v == SEQ_START_TOKEN) {
seq_printf(seq, "%-127s\n", "Iface\tDestination\tGateway "
"\tFlags\tRefCnt\tUse\tMetric\tMask\t\tMTU"
"\tWindow\tIRTT");
return 0;
}
hlist_for_each_entry_rcu(li, &l->list, hlist) {
struct fib_alias *fa;
__be32 mask, prefix;
mask = inet_make_mask(li->plen);
prefix = htonl(l->key);
list_for_each_entry_rcu(fa, &li->falh, fa_list) {
const struct fib_info *fi = fa->fa_info;
unsigned int flags = fib_flag_trans(fa->fa_type, mask, fi);
if (fa->fa_type == RTN_BROADCAST
|| fa->fa_type == RTN_MULTICAST)
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
