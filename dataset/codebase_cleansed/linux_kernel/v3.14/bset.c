void bch_dump_bset(struct btree_keys *b, struct bset *i, unsigned set)
{
struct bkey *k, *next;
for (k = i->start; k < bset_bkey_last(i); k = next) {
next = bkey_next(k);
printk(KERN_ERR "block %u key %li/%u: ", set,
(uint64_t *) k - i->d, i->keys);
if (b->ops->key_dump)
b->ops->key_dump(b, k);
else
printk("%llu:%llu\n", KEY_INODE(k), KEY_OFFSET(k));
if (next < bset_bkey_last(i) &&
bkey_cmp(k, b->ops->is_extents ?
&START_KEY(next) : next) > 0)
printk(KERN_ERR "Key skipped backwards\n");
}
}
void bch_dump_bucket(struct btree_keys *b)
{
unsigned i;
console_lock();
for (i = 0; i <= b->nsets; i++)
bch_dump_bset(b, b->set[i].data,
bset_sector_offset(b, b->set[i].data));
console_unlock();
}
int __bch_count_data(struct btree_keys *b)
{
unsigned ret = 0;
struct btree_iter iter;
struct bkey *k;
if (b->ops->is_extents)
for_each_key(b, k, &iter)
ret += KEY_SIZE(k);
return ret;
}
void __bch_check_keys(struct btree_keys *b, const char *fmt, ...)
{
va_list args;
struct bkey *k, *p = NULL;
struct btree_iter iter;
const char *err;
for_each_key(b, k, &iter) {
if (b->ops->is_extents) {
err = "Keys out of order";
if (p && bkey_cmp(&START_KEY(p), &START_KEY(k)) > 0)
goto bug;
if (bch_ptr_invalid(b, k))
continue;
err = "Overlapping keys";
if (p && bkey_cmp(p, &START_KEY(k)) > 0)
goto bug;
} else {
if (bch_ptr_bad(b, k))
continue;
err = "Duplicate keys";
if (p && !bkey_cmp(p, k))
goto bug;
}
p = k;
}
#if 0
err = "Key larger than btree node key";
if (p && bkey_cmp(p, &b->key) > 0)
goto bug;
#endif
return;
bug:
bch_dump_bucket(b);
va_start(args, fmt);
vprintk(fmt, args);
va_end(args);
panic("bch_check_keys error: %s:\n", err);
}
static void bch_btree_iter_next_check(struct btree_iter *iter)
{
struct bkey *k = iter->data->k, *next = bkey_next(k);
if (next < iter->data->end &&
bkey_cmp(k, iter->b->ops->is_extents ?
&START_KEY(next) : next) > 0) {
bch_dump_bucket(iter->b);
panic("Key skipped backwards\n");
}
}
static inline void bch_btree_iter_next_check(struct btree_iter *iter) {}
int __bch_keylist_realloc(struct keylist *l, unsigned u64s)
{
size_t oldsize = bch_keylist_nkeys(l);
size_t newsize = oldsize + u64s;
uint64_t *old_keys = l->keys_p == l->inline_keys ? NULL : l->keys_p;
uint64_t *new_keys;
newsize = roundup_pow_of_two(newsize);
if (newsize <= KEYLIST_INLINE ||
roundup_pow_of_two(oldsize) == newsize)
return 0;
new_keys = krealloc(old_keys, sizeof(uint64_t) * newsize, GFP_NOIO);
if (!new_keys)
return -ENOMEM;
if (!old_keys)
memcpy(new_keys, l->inline_keys, sizeof(uint64_t) * oldsize);
l->keys_p = new_keys;
l->top_p = new_keys + oldsize;
return 0;
}
struct bkey *bch_keylist_pop(struct keylist *l)
{
struct bkey *k = l->keys;
if (k == l->top)
return NULL;
while (bkey_next(k) != l->top)
k = bkey_next(k);
return l->top = k;
}
void bch_keylist_pop_front(struct keylist *l)
{
l->top_p -= bkey_u64s(l->keys);
memmove(l->keys,
bkey_next(l->keys),
bch_keylist_bytes(l));
}
void bch_bkey_copy_single_ptr(struct bkey *dest, const struct bkey *src,
unsigned i)
{
BUG_ON(i > KEY_PTRS(src));
memcpy(dest, src, 2 * sizeof(uint64_t));
dest->ptr[0] = src->ptr[i];
SET_KEY_PTRS(dest, 1);
SET_KEY_CSUM(dest, 0);
}
bool __bch_cut_front(const struct bkey *where, struct bkey *k)
{
unsigned i, len = 0;
if (bkey_cmp(where, &START_KEY(k)) <= 0)
return false;
if (bkey_cmp(where, k) < 0)
len = KEY_OFFSET(k) - KEY_OFFSET(where);
else
bkey_copy_key(k, where);
for (i = 0; i < KEY_PTRS(k); i++)
SET_PTR_OFFSET(k, i, PTR_OFFSET(k, i) + KEY_SIZE(k) - len);
BUG_ON(len > KEY_SIZE(k));
SET_KEY_SIZE(k, len);
return true;
}
bool __bch_cut_back(const struct bkey *where, struct bkey *k)
{
unsigned len = 0;
if (bkey_cmp(where, k) >= 0)
return false;
BUG_ON(KEY_INODE(where) != KEY_INODE(k));
if (bkey_cmp(where, &START_KEY(k)) > 0)
len = KEY_OFFSET(where) - KEY_START(k);
bkey_copy_key(k, where);
BUG_ON(len > KEY_SIZE(k));
SET_KEY_SIZE(k, len);
return true;
}
static inline size_t btree_keys_bytes(struct btree_keys *b)
{
return PAGE_SIZE << b->page_order;
}
static inline size_t btree_keys_cachelines(struct btree_keys *b)
{
return btree_keys_bytes(b) / BSET_CACHELINE;
}
static inline size_t bset_tree_bytes(struct btree_keys *b)
{
return btree_keys_cachelines(b) * sizeof(struct bkey_float);
}
static inline size_t bset_prev_bytes(struct btree_keys *b)
{
return btree_keys_cachelines(b) * sizeof(uint8_t);
}
void bch_btree_keys_free(struct btree_keys *b)
{
struct bset_tree *t = b->set;
if (bset_prev_bytes(b) < PAGE_SIZE)
kfree(t->prev);
else
free_pages((unsigned long) t->prev,
get_order(bset_prev_bytes(b)));
if (bset_tree_bytes(b) < PAGE_SIZE)
kfree(t->tree);
else
free_pages((unsigned long) t->tree,
get_order(bset_tree_bytes(b)));
free_pages((unsigned long) t->data, b->page_order);
t->prev = NULL;
t->tree = NULL;
t->data = NULL;
}
int bch_btree_keys_alloc(struct btree_keys *b, unsigned page_order, gfp_t gfp)
{
struct bset_tree *t = b->set;
BUG_ON(t->data);
b->page_order = page_order;
t->data = (void *) __get_free_pages(gfp, b->page_order);
if (!t->data)
goto err;
t->tree = bset_tree_bytes(b) < PAGE_SIZE
? kmalloc(bset_tree_bytes(b), gfp)
: (void *) __get_free_pages(gfp, get_order(bset_tree_bytes(b)));
if (!t->tree)
goto err;
t->prev = bset_prev_bytes(b) < PAGE_SIZE
? kmalloc(bset_prev_bytes(b), gfp)
: (void *) __get_free_pages(gfp, get_order(bset_prev_bytes(b)));
if (!t->prev)
goto err;
return 0;
err:
bch_btree_keys_free(b);
return -ENOMEM;
}
void bch_btree_keys_init(struct btree_keys *b, const struct btree_keys_ops *ops,
bool *expensive_debug_checks)
{
unsigned i;
b->ops = ops;
b->expensive_debug_checks = expensive_debug_checks;
b->nsets = 0;
b->last_set_unwritten = 0;
for (i = 0; i < MAX_BSETS; i++)
b->set[i].size = 0;
for (i = 1; i < MAX_BSETS; i++)
b->set[i].data = NULL;
}
static unsigned inorder_next(unsigned j, unsigned size)
{
if (j * 2 + 1 < size) {
j = j * 2 + 1;
while (j * 2 < size)
j *= 2;
} else
j >>= ffz(j) + 1;
return j;
}
static unsigned inorder_prev(unsigned j, unsigned size)
{
if (j * 2 < size) {
j = j * 2;
while (j * 2 + 1 < size)
j = j * 2 + 1;
} else
j >>= ffs(j);
return j;
}
static unsigned __to_inorder(unsigned j, unsigned size, unsigned extra)
{
unsigned b = fls(j);
unsigned shift = fls(size - 1) - b;
j ^= 1U << (b - 1);
j <<= 1;
j |= 1;
j <<= shift;
if (j > extra)
j -= (j - extra) >> 1;
return j;
}
static unsigned to_inorder(unsigned j, struct bset_tree *t)
{
return __to_inorder(j, t->size, t->extra);
}
static unsigned __inorder_to_tree(unsigned j, unsigned size, unsigned extra)
{
unsigned shift;
if (j > extra)
j += j - extra;
shift = ffs(j);
j >>= shift;
j |= roundup_pow_of_two(size) >> shift;
return j;
}
static unsigned inorder_to_tree(unsigned j, struct bset_tree *t)
{
return __inorder_to_tree(j, t->size, t->extra);
}
static struct bkey *cacheline_to_bkey(struct bset_tree *t, unsigned cacheline,
unsigned offset)
{
return ((void *) t->data) + cacheline * BSET_CACHELINE + offset * 8;
}
static unsigned bkey_to_cacheline(struct bset_tree *t, struct bkey *k)
{
return ((void *) k - (void *) t->data) / BSET_CACHELINE;
}
static unsigned bkey_to_cacheline_offset(struct bset_tree *t,
unsigned cacheline,
struct bkey *k)
{
return (u64 *) k - (u64 *) cacheline_to_bkey(t, cacheline, 0);
}
static struct bkey *tree_to_bkey(struct bset_tree *t, unsigned j)
{
return cacheline_to_bkey(t, to_inorder(j, t), t->tree[j].m);
}
static struct bkey *tree_to_prev_bkey(struct bset_tree *t, unsigned j)
{
return (void *) (((uint64_t *) tree_to_bkey(t, j)) - t->prev[j]);
}
static struct bkey *table_to_bkey(struct bset_tree *t, unsigned cacheline)
{
return cacheline_to_bkey(t, cacheline, t->prev[cacheline]);
}
static inline uint64_t shrd128(uint64_t high, uint64_t low, uint8_t shift)
{
low >>= shift;
low |= (high << 1) << (63U - shift);
return low;
}
static inline unsigned bfloat_mantissa(const struct bkey *k,
struct bkey_float *f)
{
const uint64_t *p = &k->low - (f->exponent >> 6);
return shrd128(p[-1], p[0], f->exponent & 63) & BKEY_MANTISSA_MASK;
}
static void make_bfloat(struct bset_tree *t, unsigned j)
{
struct bkey_float *f = &t->tree[j];
struct bkey *m = tree_to_bkey(t, j);
struct bkey *p = tree_to_prev_bkey(t, j);
struct bkey *l = is_power_of_2(j)
? t->data->start
: tree_to_prev_bkey(t, j >> ffs(j));
struct bkey *r = is_power_of_2(j + 1)
? bset_bkey_idx(t->data, t->data->keys - bkey_u64s(&t->end))
: tree_to_bkey(t, j >> (ffz(j) + 1));
BUG_ON(m < l || m > r);
BUG_ON(bkey_next(p) != m);
if (KEY_INODE(l) != KEY_INODE(r))
f->exponent = fls64(KEY_INODE(r) ^ KEY_INODE(l)) + 64;
else
f->exponent = fls64(r->low ^ l->low);
f->exponent = max_t(int, f->exponent - BKEY_MANTISSA_BITS, 0);
if (bfloat_mantissa(m, f) != bfloat_mantissa(p, f))
f->mantissa = bfloat_mantissa(m, f) - 1;
else
f->exponent = 127;
}
static void bset_alloc_tree(struct btree_keys *b, struct bset_tree *t)
{
if (t != b->set) {
unsigned j = roundup(t[-1].size,
64 / sizeof(struct bkey_float));
t->tree = t[-1].tree + j;
t->prev = t[-1].prev + j;
}
while (t < b->set + MAX_BSETS)
t++->size = 0;
}
static void bch_bset_build_unwritten_tree(struct btree_keys *b)
{
struct bset_tree *t = bset_tree_last(b);
BUG_ON(b->last_set_unwritten);
b->last_set_unwritten = 1;
bset_alloc_tree(b, t);
if (t->tree != b->set->tree + btree_keys_cachelines(b)) {
t->prev[0] = bkey_to_cacheline_offset(t, 0, t->data->start);
t->size = 1;
}
}
void bch_bset_init_next(struct btree_keys *b, struct bset *i, uint64_t magic)
{
if (i != b->set->data) {
b->set[++b->nsets].data = i;
i->seq = b->set->data->seq;
} else
get_random_bytes(&i->seq, sizeof(uint64_t));
i->magic = magic;
i->version = 0;
i->keys = 0;
bch_bset_build_unwritten_tree(b);
}
void bch_bset_build_written_tree(struct btree_keys *b)
{
struct bset_tree *t = bset_tree_last(b);
struct bkey *prev = NULL, *k = t->data->start;
unsigned j, cacheline = 1;
b->last_set_unwritten = 0;
bset_alloc_tree(b, t);
t->size = min_t(unsigned,
bkey_to_cacheline(t, bset_bkey_last(t->data)),
b->set->tree + btree_keys_cachelines(b) - t->tree);
if (t->size < 2) {
t->size = 0;
return;
}
t->extra = (t->size - rounddown_pow_of_two(t->size - 1)) << 1;
for (j = inorder_next(0, t->size);
j;
j = inorder_next(j, t->size)) {
while (bkey_to_cacheline(t, k) < cacheline)
prev = k, k = bkey_next(k);
t->prev[j] = bkey_u64s(prev);
t->tree[j].m = bkey_to_cacheline_offset(t, cacheline++, k);
}
while (bkey_next(k) != bset_bkey_last(t->data))
k = bkey_next(k);
t->end = *k;
for (j = inorder_next(0, t->size);
j;
j = inorder_next(j, t->size))
make_bfloat(t, j);
}
void bch_bset_fix_invalidated_key(struct btree_keys *b, struct bkey *k)
{
struct bset_tree *t;
unsigned inorder, j = 1;
for (t = b->set; t <= bset_tree_last(b); t++)
if (k < bset_bkey_last(t->data))
goto found_set;
BUG();
found_set:
if (!t->size || !bset_written(b, t))
return;
inorder = bkey_to_cacheline(t, k);
if (k == t->data->start)
goto fix_left;
if (bkey_next(k) == bset_bkey_last(t->data)) {
t->end = *k;
goto fix_right;
}
j = inorder_to_tree(inorder, t);
if (j &&
j < t->size &&
k == tree_to_bkey(t, j))
fix_left: do {
make_bfloat(t, j);
j = j * 2;
} while (j < t->size);
j = inorder_to_tree(inorder + 1, t);
if (j &&
j < t->size &&
k == tree_to_prev_bkey(t, j))
fix_right: do {
make_bfloat(t, j);
j = j * 2 + 1;
} while (j < t->size);
}
static void bch_bset_fix_lookup_table(struct btree_keys *b,
struct bset_tree *t,
struct bkey *k)
{
unsigned shift = bkey_u64s(k);
unsigned j = bkey_to_cacheline(t, k);
if (!t->size)
return;
while (j < t->size &&
table_to_bkey(t, j) <= k)
j++;
for (; j < t->size; j++) {
t->prev[j] += shift;
if (t->prev[j] > 7) {
k = table_to_bkey(t, j - 1);
while (k < cacheline_to_bkey(t, j, 0))
k = bkey_next(k);
t->prev[j] = bkey_to_cacheline_offset(t, j, k);
}
}
if (t->size == b->set->tree + btree_keys_cachelines(b) - t->tree)
return;
for (k = table_to_bkey(t, t->size - 1);
k != bset_bkey_last(t->data);
k = bkey_next(k))
if (t->size == bkey_to_cacheline(t, k)) {
t->prev[t->size] = bkey_to_cacheline_offset(t, t->size, k);
t->size++;
}
}
bool bch_bkey_try_merge(struct btree_keys *b, struct bkey *l, struct bkey *r)
{
if (!b->ops->key_merge)
return false;
if (!bch_bkey_equal_header(l, r) ||
bkey_cmp(l, &START_KEY(r)))
return false;
return b->ops->key_merge(b, l, r);
}
void bch_bset_insert(struct btree_keys *b, struct bkey *where,
struct bkey *insert)
{
struct bset_tree *t = bset_tree_last(b);
BUG_ON(!b->last_set_unwritten);
BUG_ON(bset_byte_offset(b, t->data) +
__set_bytes(t->data, t->data->keys + bkey_u64s(insert)) >
PAGE_SIZE << b->page_order);
memmove((uint64_t *) where + bkey_u64s(insert),
where,
(void *) bset_bkey_last(t->data) - (void *) where);
t->data->keys += bkey_u64s(insert);
bkey_copy(where, insert);
bch_bset_fix_lookup_table(b, t, where);
}
unsigned bch_btree_insert_key(struct btree_keys *b, struct bkey *k,
struct bkey *replace_key)
{
unsigned status = BTREE_INSERT_STATUS_NO_INSERT;
struct bset *i = bset_tree_last(b)->data;
struct bkey *m, *prev = NULL;
struct btree_iter iter;
BUG_ON(b->ops->is_extents && !KEY_SIZE(k));
m = bch_btree_iter_init(b, &iter, b->ops->is_extents
? PRECEDING_KEY(&START_KEY(k))
: PRECEDING_KEY(k));
if (b->ops->insert_fixup(b, k, &iter, replace_key))
return status;
status = BTREE_INSERT_STATUS_INSERT;
while (m != bset_bkey_last(i) &&
bkey_cmp(k, b->ops->is_extents ? &START_KEY(m) : m) > 0)
prev = m, m = bkey_next(m);
status = BTREE_INSERT_STATUS_BACK_MERGE;
if (prev &&
bch_bkey_try_merge(b, prev, k))
goto merged;
#if 0
status = BTREE_INSERT_STATUS_OVERWROTE;
if (m != bset_bkey_last(i) &&
KEY_PTRS(m) == KEY_PTRS(k) && !KEY_SIZE(m))
goto copy;
#endif
status = BTREE_INSERT_STATUS_FRONT_MERGE;
if (m != bset_bkey_last(i) &&
bch_bkey_try_merge(b, k, m))
goto copy;
bch_bset_insert(b, m, k);
copy: bkey_copy(m, k);
merged:
return status;
}
static struct bset_search_iter bset_search_write_set(struct bset_tree *t,
const struct bkey *search)
{
unsigned li = 0, ri = t->size;
while (li + 1 != ri) {
unsigned m = (li + ri) >> 1;
if (bkey_cmp(table_to_bkey(t, m), search) > 0)
ri = m;
else
li = m;
}
return (struct bset_search_iter) {
table_to_bkey(t, li),
ri < t->size ? table_to_bkey(t, ri) : bset_bkey_last(t->data)
};
}
static struct bset_search_iter bset_search_tree(struct bset_tree *t,
const struct bkey *search)
{
struct bkey *l, *r;
struct bkey_float *f;
unsigned inorder, j, n = 1;
do {
unsigned p = n << 4;
p &= ((int) (p - t->size)) >> 31;
prefetch(&t->tree[p]);
j = n;
f = &t->tree[j];
if (likely(f->exponent != 127))
n = j * 2 + (((unsigned)
(f->mantissa -
bfloat_mantissa(search, f))) >> 31);
else
n = (bkey_cmp(tree_to_bkey(t, j), search) > 0)
? j * 2
: j * 2 + 1;
} while (n < t->size);
inorder = to_inorder(j, t);
if (n & 1) {
l = cacheline_to_bkey(t, inorder, f->m);
if (++inorder != t->size) {
f = &t->tree[inorder_next(j, t->size)];
r = cacheline_to_bkey(t, inorder, f->m);
} else
r = bset_bkey_last(t->data);
} else {
r = cacheline_to_bkey(t, inorder, f->m);
if (--inorder) {
f = &t->tree[inorder_prev(j, t->size)];
l = cacheline_to_bkey(t, inorder, f->m);
} else
l = t->data->start;
}
return (struct bset_search_iter) {l, r};
}
struct bkey *__bch_bset_search(struct btree_keys *b, struct bset_tree *t,
const struct bkey *search)
{
struct bset_search_iter i;
if (unlikely(!t->size)) {
i.l = t->data->start;
i.r = bset_bkey_last(t->data);
} else if (bset_written(b, t)) {
if (unlikely(bkey_cmp(search, &t->end) >= 0))
return bset_bkey_last(t->data);
if (unlikely(bkey_cmp(search, t->data->start) < 0))
return t->data->start;
i = bset_search_tree(t, search);
} else {
BUG_ON(!b->nsets &&
t->size < bkey_to_cacheline(t, bset_bkey_last(t->data)));
i = bset_search_write_set(t, search);
}
if (btree_keys_expensive_checks(b)) {
BUG_ON(bset_written(b, t) &&
i.l != t->data->start &&
bkey_cmp(tree_to_prev_bkey(t,
inorder_to_tree(bkey_to_cacheline(t, i.l), t)),
search) > 0);
BUG_ON(i.r != bset_bkey_last(t->data) &&
bkey_cmp(i.r, search) <= 0);
}
while (likely(i.l != i.r) &&
bkey_cmp(i.l, search) <= 0)
i.l = bkey_next(i.l);
return i.l;
}
static inline bool btree_iter_cmp(struct btree_iter_set l,
struct btree_iter_set r)
{
return bkey_cmp(l.k, r.k) > 0;
}
static inline bool btree_iter_end(struct btree_iter *iter)
{
return !iter->used;
}
void bch_btree_iter_push(struct btree_iter *iter, struct bkey *k,
struct bkey *end)
{
if (k != end)
BUG_ON(!heap_add(iter,
((struct btree_iter_set) { k, end }),
btree_iter_cmp));
}
static struct bkey *__bch_btree_iter_init(struct btree_keys *b,
struct btree_iter *iter,
struct bkey *search,
struct bset_tree *start)
{
struct bkey *ret = NULL;
iter->size = ARRAY_SIZE(iter->data);
iter->used = 0;
#ifdef CONFIG_BCACHE_DEBUG
iter->b = b;
#endif
for (; start <= bset_tree_last(b); start++) {
ret = bch_bset_search(b, start, search);
bch_btree_iter_push(iter, ret, bset_bkey_last(start->data));
}
return ret;
}
struct bkey *bch_btree_iter_init(struct btree_keys *b,
struct btree_iter *iter,
struct bkey *search)
{
return __bch_btree_iter_init(b, iter, search, b->set);
}
static inline struct bkey *__bch_btree_iter_next(struct btree_iter *iter,
btree_iter_cmp_fn *cmp)
{
struct btree_iter_set unused;
struct bkey *ret = NULL;
if (!btree_iter_end(iter)) {
bch_btree_iter_next_check(iter);
ret = iter->data->k;
iter->data->k = bkey_next(iter->data->k);
if (iter->data->k > iter->data->end) {
WARN_ONCE(1, "bset was corrupt!\n");
iter->data->k = iter->data->end;
}
if (iter->data->k == iter->data->end)
heap_pop(iter, unused, cmp);
else
heap_sift(iter, 0, cmp);
}
return ret;
}
struct bkey *bch_btree_iter_next(struct btree_iter *iter)
{
return __bch_btree_iter_next(iter, btree_iter_cmp);
}
struct bkey *bch_btree_iter_next_filter(struct btree_iter *iter,
struct btree_keys *b, ptr_filter_fn fn)
{
struct bkey *ret;
do {
ret = bch_btree_iter_next(iter);
} while (ret && fn(b, ret));
return ret;
}
void bch_bset_sort_state_free(struct bset_sort_state *state)
{
if (state->pool)
mempool_destroy(state->pool);
}
int bch_bset_sort_state_init(struct bset_sort_state *state, unsigned page_order)
{
spin_lock_init(&state->time.lock);
state->page_order = page_order;
state->crit_factor = int_sqrt(1 << page_order);
state->pool = mempool_create_page_pool(1, page_order);
if (!state->pool)
return -ENOMEM;
return 0;
}
static void btree_mergesort(struct btree_keys *b, struct bset *out,
struct btree_iter *iter,
bool fixup, bool remove_stale)
{
int i;
struct bkey *k, *last = NULL;
BKEY_PADDED(k) tmp;
bool (*bad)(struct btree_keys *, const struct bkey *) = remove_stale
? bch_ptr_bad
: bch_ptr_invalid;
for (i = iter->used / 2 - 1; i >= 0; --i)
heap_sift(iter, i, b->ops->sort_cmp);
while (!btree_iter_end(iter)) {
if (b->ops->sort_fixup && fixup)
k = b->ops->sort_fixup(iter, &tmp.k);
else
k = NULL;
if (!k)
k = __bch_btree_iter_next(iter, b->ops->sort_cmp);
if (bad(b, k))
continue;
if (!last) {
last = out->start;
bkey_copy(last, k);
} else if (!bch_bkey_try_merge(b, last, k)) {
last = bkey_next(last);
bkey_copy(last, k);
}
}
out->keys = last ? (uint64_t *) bkey_next(last) - out->d : 0;
pr_debug("sorted %i keys", out->keys);
}
static void __btree_sort(struct btree_keys *b, struct btree_iter *iter,
unsigned start, unsigned order, bool fixup,
struct bset_sort_state *state)
{
uint64_t start_time;
bool used_mempool = false;
struct bset *out = (void *) __get_free_pages(__GFP_NOWARN|GFP_NOIO,
order);
if (!out) {
struct page *outp;
BUG_ON(order > state->page_order);
outp = mempool_alloc(state->pool, GFP_NOIO);
out = page_address(outp);
used_mempool = true;
order = state->page_order;
}
start_time = local_clock();
btree_mergesort(b, out, iter, fixup, false);
b->nsets = start;
if (!start && order == b->page_order) {
out->magic = b->set->data->magic;
out->seq = b->set->data->seq;
out->version = b->set->data->version;
swap(out, b->set->data);
} else {
b->set[start].data->keys = out->keys;
memcpy(b->set[start].data->start, out->start,
(void *) bset_bkey_last(out) - (void *) out->start);
}
if (used_mempool)
mempool_free(virt_to_page(out), state->pool);
else
free_pages((unsigned long) out, order);
bch_bset_build_written_tree(b);
if (!start)
bch_time_stats_update(&state->time, start_time);
}
void bch_btree_sort_partial(struct btree_keys *b, unsigned start,
struct bset_sort_state *state)
{
size_t order = b->page_order, keys = 0;
struct btree_iter iter;
int oldsize = bch_count_data(b);
__bch_btree_iter_init(b, &iter, NULL, &b->set[start]);
if (start) {
unsigned i;
for (i = start; i <= b->nsets; i++)
keys += b->set[i].data->keys;
order = get_order(__set_bytes(b->set->data, keys));
}
__btree_sort(b, &iter, start, order, false, state);
EBUG_ON(oldsize >= 0 && bch_count_data(b) != oldsize);
}
void bch_btree_sort_and_fix_extents(struct btree_keys *b,
struct btree_iter *iter,
struct bset_sort_state *state)
{
__btree_sort(b, iter, 0, b->page_order, true, state);
}
void bch_btree_sort_into(struct btree_keys *b, struct btree_keys *new,
struct bset_sort_state *state)
{
uint64_t start_time = local_clock();
struct btree_iter iter;
bch_btree_iter_init(b, &iter, NULL);
btree_mergesort(b, new->set->data, &iter, false, true);
bch_time_stats_update(&state->time, start_time);
new->set->size = 0;
}
void bch_btree_sort_lazy(struct btree_keys *b, struct bset_sort_state *state)
{
unsigned crit = SORT_CRIT;
int i;
if (!b->nsets)
goto out;
for (i = b->nsets - 1; i >= 0; --i) {
crit *= state->crit_factor;
if (b->set[i].data->keys < crit) {
bch_btree_sort_partial(b, i, state);
return;
}
}
if (b->nsets + 1 == MAX_BSETS) {
bch_btree_sort(b, state);
return;
}
out:
bch_bset_build_written_tree(b);
}
void bch_btree_keys_stats(struct btree_keys *b, struct bset_stats *stats)
{
unsigned i;
for (i = 0; i <= b->nsets; i++) {
struct bset_tree *t = &b->set[i];
size_t bytes = t->data->keys * sizeof(uint64_t);
size_t j;
if (bset_written(b, t)) {
stats->sets_written++;
stats->bytes_written += bytes;
stats->floats += t->size - 1;
for (j = 1; j < t->size; j++)
if (t->tree[j].exponent == 127)
stats->failed++;
} else {
stats->sets_unwritten++;
stats->bytes_unwritten += bytes;
}
}
}
