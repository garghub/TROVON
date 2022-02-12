struct fld_cache *fld_cache_init(const char *name,
int cache_size, int cache_threshold)
{
struct fld_cache *cache;
LASSERT(name != NULL);
LASSERT(cache_threshold < cache_size);
cache = kzalloc(sizeof(*cache), GFP_NOFS);
if (!cache)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&cache->fci_entries_head);
INIT_LIST_HEAD(&cache->fci_lru);
cache->fci_cache_count = 0;
rwlock_init(&cache->fci_lock);
strlcpy(cache->fci_name, name,
sizeof(cache->fci_name));
cache->fci_cache_size = cache_size;
cache->fci_threshold = cache_threshold;
memset(&cache->fci_stat, 0, sizeof(cache->fci_stat));
CDEBUG(D_INFO, "%s: FLD cache - Size: %d, Threshold: %d\n",
cache->fci_name, cache_size, cache_threshold);
return cache;
}
void fld_cache_fini(struct fld_cache *cache)
{
__u64 pct;
LASSERT(cache != NULL);
fld_cache_flush(cache);
if (cache->fci_stat.fst_count > 0) {
pct = cache->fci_stat.fst_cache * 100;
do_div(pct, cache->fci_stat.fst_count);
} else {
pct = 0;
}
CDEBUG(D_INFO, "FLD cache statistics (%s):\n", cache->fci_name);
CDEBUG(D_INFO, " Total reqs: %llu\n", cache->fci_stat.fst_count);
CDEBUG(D_INFO, " Cache reqs: %llu\n", cache->fci_stat.fst_cache);
CDEBUG(D_INFO, " Cache hits: %llu%%\n", pct);
kfree(cache);
}
static void fld_cache_entry_delete(struct fld_cache *cache,
struct fld_cache_entry *node)
{
list_del(&node->fce_list);
list_del(&node->fce_lru);
cache->fci_cache_count--;
kfree(node);
}
static void fld_fix_new_list(struct fld_cache *cache)
{
struct fld_cache_entry *f_curr;
struct fld_cache_entry *f_next;
struct lu_seq_range *c_range;
struct lu_seq_range *n_range;
struct list_head *head = &cache->fci_entries_head;
restart_fixup:
list_for_each_entry_safe(f_curr, f_next, head, fce_list) {
c_range = &f_curr->fce_range;
n_range = &f_next->fce_range;
LASSERT(range_is_sane(c_range));
if (&f_next->fce_list == head)
break;
if (c_range->lsr_flags != n_range->lsr_flags)
continue;
LASSERTF(c_range->lsr_start <= n_range->lsr_start,
"cur lsr_start "DRANGE" next lsr_start "DRANGE"\n",
PRANGE(c_range), PRANGE(n_range));
if (c_range->lsr_end == n_range->lsr_start) {
if (c_range->lsr_index != n_range->lsr_index)
continue;
n_range->lsr_start = c_range->lsr_start;
fld_cache_entry_delete(cache, f_curr);
continue;
}
if (n_range->lsr_start < c_range->lsr_end) {
if (c_range->lsr_index == n_range->lsr_index) {
n_range->lsr_start = c_range->lsr_start;
n_range->lsr_end = max(c_range->lsr_end,
n_range->lsr_end);
fld_cache_entry_delete(cache, f_curr);
} else {
if (n_range->lsr_end <= c_range->lsr_end) {
*n_range = *c_range;
fld_cache_entry_delete(cache, f_curr);
} else
n_range->lsr_start = c_range->lsr_end;
}
goto restart_fixup;
}
if (c_range->lsr_start == n_range->lsr_start &&
c_range->lsr_end == n_range->lsr_end)
fld_cache_entry_delete(cache, f_curr);
}
}
static inline void fld_cache_entry_add(struct fld_cache *cache,
struct fld_cache_entry *f_new,
struct list_head *pos)
{
list_add(&f_new->fce_list, pos);
list_add(&f_new->fce_lru, &cache->fci_lru);
cache->fci_cache_count++;
fld_fix_new_list(cache);
}
static int fld_cache_shrink(struct fld_cache *cache)
{
struct fld_cache_entry *flde;
struct list_head *curr;
int num = 0;
LASSERT(cache != NULL);
if (cache->fci_cache_count < cache->fci_cache_size)
return 0;
curr = cache->fci_lru.prev;
while (cache->fci_cache_count + cache->fci_threshold >
cache->fci_cache_size && curr != &cache->fci_lru) {
flde = list_entry(curr, struct fld_cache_entry, fce_lru);
curr = curr->prev;
fld_cache_entry_delete(cache, flde);
num++;
}
CDEBUG(D_INFO, "%s: FLD cache - Shrunk by %d entries\n",
cache->fci_name, num);
return 0;
}
void fld_cache_flush(struct fld_cache *cache)
{
write_lock(&cache->fci_lock);
cache->fci_cache_size = 0;
fld_cache_shrink(cache);
write_unlock(&cache->fci_lock);
}
static void fld_cache_punch_hole(struct fld_cache *cache,
struct fld_cache_entry *f_curr,
struct fld_cache_entry *f_new)
{
const struct lu_seq_range *range = &f_new->fce_range;
const u64 new_start = range->lsr_start;
const u64 new_end = range->lsr_end;
struct fld_cache_entry *fldt;
fldt = kzalloc(sizeof(*fldt), GFP_ATOMIC);
if (!fldt) {
kfree(f_new);
return;
}
fldt->fce_range.lsr_start = new_end;
fldt->fce_range.lsr_end = f_curr->fce_range.lsr_end;
fldt->fce_range.lsr_index = f_curr->fce_range.lsr_index;
f_curr->fce_range.lsr_end = new_start;
fld_cache_entry_add(cache, f_new, &f_curr->fce_list);
fld_cache_entry_add(cache, fldt, &f_new->fce_list);
}
static void fld_cache_overlap_handle(struct fld_cache *cache,
struct fld_cache_entry *f_curr,
struct fld_cache_entry *f_new)
{
const struct lu_seq_range *range = &f_new->fce_range;
const u64 new_start = range->lsr_start;
const u64 new_end = range->lsr_end;
const u32 mdt = range->lsr_index;
if (f_curr->fce_range.lsr_index == mdt) {
f_curr->fce_range.lsr_start = min(f_curr->fce_range.lsr_start,
new_start);
f_curr->fce_range.lsr_end = max(f_curr->fce_range.lsr_end,
new_end);
kfree(f_new);
fld_fix_new_list(cache);
} else if (new_start <= f_curr->fce_range.lsr_start &&
f_curr->fce_range.lsr_end <= new_end) {
f_curr->fce_range = *range;
kfree(f_new);
fld_fix_new_list(cache);
} else if (f_curr->fce_range.lsr_start < new_start &&
new_end < f_curr->fce_range.lsr_end) {
fld_cache_punch_hole(cache, f_curr, f_new);
} else if (new_end <= f_curr->fce_range.lsr_end) {
LASSERT(new_start <= f_curr->fce_range.lsr_start);
f_curr->fce_range.lsr_start = new_end;
fld_cache_entry_add(cache, f_new, f_curr->fce_list.prev);
} else if (f_curr->fce_range.lsr_start <= new_start) {
LASSERT(f_curr->fce_range.lsr_end <= new_end);
f_curr->fce_range.lsr_end = new_start;
fld_cache_entry_add(cache, f_new, &f_curr->fce_list);
} else
CERROR("NEW range ="DRANGE" curr = "DRANGE"\n",
PRANGE(range), PRANGE(&f_curr->fce_range));
}
struct fld_cache_entry
*fld_cache_entry_create(const struct lu_seq_range *range)
{
struct fld_cache_entry *f_new;
LASSERT(range_is_sane(range));
f_new = kzalloc(sizeof(*f_new), GFP_NOFS);
if (!f_new)
return ERR_PTR(-ENOMEM);
f_new->fce_range = *range;
return f_new;
}
static int fld_cache_insert_nolock(struct fld_cache *cache,
struct fld_cache_entry *f_new)
{
struct fld_cache_entry *f_curr;
struct fld_cache_entry *n;
struct list_head *head;
struct list_head *prev = NULL;
const u64 new_start = f_new->fce_range.lsr_start;
const u64 new_end = f_new->fce_range.lsr_end;
__u32 new_flags = f_new->fce_range.lsr_flags;
if (!cache->fci_no_shrink)
fld_cache_shrink(cache);
head = &cache->fci_entries_head;
list_for_each_entry_safe(f_curr, n, head, fce_list) {
if (new_end < f_curr->fce_range.lsr_start ||
(new_end == f_curr->fce_range.lsr_start &&
new_flags != f_curr->fce_range.lsr_flags))
break;
prev = &f_curr->fce_list;
if (new_start < f_curr->fce_range.lsr_end &&
new_flags == f_curr->fce_range.lsr_flags) {
fld_cache_overlap_handle(cache, f_curr, f_new);
goto out;
}
}
if (prev == NULL)
prev = head;
CDEBUG(D_INFO, "insert range "DRANGE"\n", PRANGE(&f_new->fce_range));
fld_cache_entry_add(cache, f_new, prev);
out:
return 0;
}
int fld_cache_insert(struct fld_cache *cache,
const struct lu_seq_range *range)
{
struct fld_cache_entry *flde;
int rc;
flde = fld_cache_entry_create(range);
if (IS_ERR(flde))
return PTR_ERR(flde);
write_lock(&cache->fci_lock);
rc = fld_cache_insert_nolock(cache, flde);
write_unlock(&cache->fci_lock);
if (rc)
kfree(flde);
return rc;
}
struct fld_cache_entry
*fld_cache_entry_lookup_nolock(struct fld_cache *cache,
struct lu_seq_range *range)
{
struct fld_cache_entry *flde;
struct fld_cache_entry *got = NULL;
struct list_head *head;
head = &cache->fci_entries_head;
list_for_each_entry(flde, head, fce_list) {
if (range->lsr_start == flde->fce_range.lsr_start ||
(range->lsr_end == flde->fce_range.lsr_end &&
range->lsr_flags == flde->fce_range.lsr_flags)) {
got = flde;
break;
}
}
return got;
}
struct fld_cache_entry
*fld_cache_entry_lookup(struct fld_cache *cache, struct lu_seq_range *range)
{
struct fld_cache_entry *got = NULL;
read_lock(&cache->fci_lock);
got = fld_cache_entry_lookup_nolock(cache, range);
read_unlock(&cache->fci_lock);
return got;
}
int fld_cache_lookup(struct fld_cache *cache,
const u64 seq, struct lu_seq_range *range)
{
struct fld_cache_entry *flde;
struct fld_cache_entry *prev = NULL;
struct list_head *head;
read_lock(&cache->fci_lock);
head = &cache->fci_entries_head;
cache->fci_stat.fst_count++;
list_for_each_entry(flde, head, fce_list) {
if (flde->fce_range.lsr_start > seq) {
if (prev != NULL)
*range = prev->fce_range;
break;
}
prev = flde;
if (range_within(&flde->fce_range, seq)) {
*range = flde->fce_range;
cache->fci_stat.fst_cache++;
read_unlock(&cache->fci_lock);
return 0;
}
}
read_unlock(&cache->fci_lock);
return -ENOENT;
}
