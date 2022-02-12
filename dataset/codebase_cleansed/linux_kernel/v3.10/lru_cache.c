int lc_try_lock(struct lru_cache *lc)
{
unsigned long val;
do {
val = cmpxchg(&lc->flags, 0, LC_LOCKED);
} while (unlikely (val == LC_PARANOIA));
return 0 == val;
#if 0
unsigned long old, new, val;
do {
old = lc->flags & LC_PARANOIA;
new = old | LC_LOCKED;
val = cmpxchg(&lc->flags, old, new);
} while (unlikely (val == (old ^ LC_PARANOIA)));
return old == val;
#endif
}
struct lru_cache *lc_create(const char *name, struct kmem_cache *cache,
unsigned max_pending_changes,
unsigned e_count, size_t e_size, size_t e_off)
{
struct hlist_head *slot = NULL;
struct lc_element **element = NULL;
struct lru_cache *lc;
struct lc_element *e;
unsigned cache_obj_size = kmem_cache_size(cache);
unsigned i;
WARN_ON(cache_obj_size < e_size);
if (cache_obj_size < e_size)
return NULL;
if (e_count > LC_MAX_ACTIVE)
return NULL;
slot = kcalloc(e_count, sizeof(struct hlist_head), GFP_KERNEL);
if (!slot)
goto out_fail;
element = kzalloc(e_count * sizeof(struct lc_element *), GFP_KERNEL);
if (!element)
goto out_fail;
lc = kzalloc(sizeof(*lc), GFP_KERNEL);
if (!lc)
goto out_fail;
INIT_LIST_HEAD(&lc->in_use);
INIT_LIST_HEAD(&lc->lru);
INIT_LIST_HEAD(&lc->free);
INIT_LIST_HEAD(&lc->to_be_changed);
lc->name = name;
lc->element_size = e_size;
lc->element_off = e_off;
lc->nr_elements = e_count;
lc->max_pending_changes = max_pending_changes;
lc->lc_cache = cache;
lc->lc_element = element;
lc->lc_slot = slot;
for (i = 0; i < e_count; i++) {
void *p = kmem_cache_alloc(cache, GFP_KERNEL);
if (!p)
break;
memset(p, 0, lc->element_size);
e = p + e_off;
e->lc_index = i;
e->lc_number = LC_FREE;
e->lc_new_number = LC_FREE;
list_add(&e->list, &lc->free);
element[i] = e;
}
if (i == e_count)
return lc;
for (i--; i; i--) {
void *p = element[i];
kmem_cache_free(cache, p - e_off);
}
kfree(lc);
out_fail:
kfree(element);
kfree(slot);
return NULL;
}
void lc_free_by_index(struct lru_cache *lc, unsigned i)
{
void *p = lc->lc_element[i];
WARN_ON(!p);
if (p) {
p -= lc->element_off;
kmem_cache_free(lc->lc_cache, p);
}
}
void lc_destroy(struct lru_cache *lc)
{
unsigned i;
if (!lc)
return;
for (i = 0; i < lc->nr_elements; i++)
lc_free_by_index(lc, i);
kfree(lc->lc_element);
kfree(lc->lc_slot);
kfree(lc);
}
void lc_reset(struct lru_cache *lc)
{
unsigned i;
INIT_LIST_HEAD(&lc->in_use);
INIT_LIST_HEAD(&lc->lru);
INIT_LIST_HEAD(&lc->free);
INIT_LIST_HEAD(&lc->to_be_changed);
lc->used = 0;
lc->hits = 0;
lc->misses = 0;
lc->starving = 0;
lc->locked = 0;
lc->changed = 0;
lc->pending_changes = 0;
lc->flags = 0;
memset(lc->lc_slot, 0, sizeof(struct hlist_head) * lc->nr_elements);
for (i = 0; i < lc->nr_elements; i++) {
struct lc_element *e = lc->lc_element[i];
void *p = e;
p -= lc->element_off;
memset(p, 0, lc->element_size);
e->lc_index = i;
e->lc_number = LC_FREE;
e->lc_new_number = LC_FREE;
list_add(&e->list, &lc->free);
}
}
size_t lc_seq_printf_stats(struct seq_file *seq, struct lru_cache *lc)
{
return seq_printf(seq, "\t%s: used:%u/%u "
"hits:%lu misses:%lu starving:%lu locked:%lu changed:%lu\n",
lc->name, lc->used, lc->nr_elements,
lc->hits, lc->misses, lc->starving, lc->locked, lc->changed);
}
static struct hlist_head *lc_hash_slot(struct lru_cache *lc, unsigned int enr)
{
return lc->lc_slot + (enr % lc->nr_elements);
}
static struct lc_element *__lc_find(struct lru_cache *lc, unsigned int enr,
bool include_changing)
{
struct lc_element *e;
BUG_ON(!lc);
BUG_ON(!lc->nr_elements);
hlist_for_each_entry(e, lc_hash_slot(lc, enr), colision) {
if (e->lc_new_number != enr)
continue;
if (e->lc_new_number == e->lc_number || include_changing)
return e;
break;
}
return NULL;
}
struct lc_element *lc_find(struct lru_cache *lc, unsigned int enr)
{
return __lc_find(lc, enr, 0);
}
bool lc_is_used(struct lru_cache *lc, unsigned int enr)
{
struct lc_element *e = __lc_find(lc, enr, 1);
return e && e->refcnt;
}
void lc_del(struct lru_cache *lc, struct lc_element *e)
{
PARANOIA_ENTRY();
PARANOIA_LC_ELEMENT(lc, e);
BUG_ON(e->refcnt);
e->lc_number = e->lc_new_number = LC_FREE;
hlist_del_init(&e->colision);
list_move(&e->list, &lc->free);
RETURN();
}
static struct lc_element *lc_prepare_for_change(struct lru_cache *lc, unsigned new_number)
{
struct list_head *n;
struct lc_element *e;
if (!list_empty(&lc->free))
n = lc->free.next;
else if (!list_empty(&lc->lru))
n = lc->lru.prev;
else
return NULL;
e = list_entry(n, struct lc_element, list);
PARANOIA_LC_ELEMENT(lc, e);
e->lc_new_number = new_number;
if (!hlist_unhashed(&e->colision))
__hlist_del(&e->colision);
hlist_add_head(&e->colision, lc_hash_slot(lc, new_number));
list_move(&e->list, &lc->to_be_changed);
return e;
}
static int lc_unused_element_available(struct lru_cache *lc)
{
if (!list_empty(&lc->free))
return 1;
if (!list_empty(&lc->lru))
return 1;
return 0;
}
static struct lc_element *__lc_get(struct lru_cache *lc, unsigned int enr, unsigned int flags)
{
struct lc_element *e;
PARANOIA_ENTRY();
if (lc->flags & LC_STARVING) {
++lc->starving;
RETURN(NULL);
}
e = __lc_find(lc, enr, 1);
if (e) {
if (e->lc_new_number != e->lc_number) {
if (!(flags & LC_GET_MAY_USE_UNCOMMITTED))
RETURN(NULL);
++e->refcnt;
++lc->hits;
RETURN(e);
}
++lc->hits;
if (e->refcnt++ == 0)
lc->used++;
list_move(&e->list, &lc->in_use);
RETURN(e);
}
++lc->misses;
if (!(flags & LC_GET_MAY_CHANGE))
RETURN(NULL);
test_and_set_bit(__LC_DIRTY, &lc->flags);
if (test_bit(__LC_LOCKED, &lc->flags)) {
++lc->locked;
RETURN(NULL);
}
if (!lc_unused_element_available(lc)) {
__set_bit(__LC_STARVING, &lc->flags);
RETURN(NULL);
}
if (lc->pending_changes >= lc->max_pending_changes)
RETURN(NULL);
e = lc_prepare_for_change(lc, enr);
BUG_ON(!e);
clear_bit(__LC_STARVING, &lc->flags);
BUG_ON(++e->refcnt != 1);
lc->used++;
lc->pending_changes++;
RETURN(e);
}
struct lc_element *lc_get(struct lru_cache *lc, unsigned int enr)
{
return __lc_get(lc, enr, LC_GET_MAY_CHANGE);
}
struct lc_element *lc_get_cumulative(struct lru_cache *lc, unsigned int enr)
{
return __lc_get(lc, enr, LC_GET_MAY_CHANGE|LC_GET_MAY_USE_UNCOMMITTED);
}
struct lc_element *lc_try_get(struct lru_cache *lc, unsigned int enr)
{
return __lc_get(lc, enr, 0);
}
void lc_committed(struct lru_cache *lc)
{
struct lc_element *e, *tmp;
PARANOIA_ENTRY();
list_for_each_entry_safe(e, tmp, &lc->to_be_changed, list) {
++lc->changed;
e->lc_number = e->lc_new_number;
list_move(&e->list, &lc->in_use);
}
lc->pending_changes = 0;
RETURN();
}
unsigned int lc_put(struct lru_cache *lc, struct lc_element *e)
{
PARANOIA_ENTRY();
PARANOIA_LC_ELEMENT(lc, e);
BUG_ON(e->refcnt == 0);
BUG_ON(e->lc_number != e->lc_new_number);
if (--e->refcnt == 0) {
list_move(&e->list, &lc->lru);
lc->used--;
clear_bit_unlock(__LC_STARVING, &lc->flags);
}
RETURN(e->refcnt);
}
struct lc_element *lc_element_by_index(struct lru_cache *lc, unsigned i)
{
BUG_ON(i >= lc->nr_elements);
BUG_ON(lc->lc_element[i] == NULL);
BUG_ON(lc->lc_element[i]->lc_index != i);
return lc->lc_element[i];
}
unsigned int lc_index_of(struct lru_cache *lc, struct lc_element *e)
{
PARANOIA_LC_ELEMENT(lc, e);
return e->lc_index;
}
void lc_set(struct lru_cache *lc, unsigned int enr, int index)
{
struct lc_element *e;
struct list_head *lh;
if (index < 0 || index >= lc->nr_elements)
return;
e = lc_element_by_index(lc, index);
BUG_ON(e->lc_number != e->lc_new_number);
BUG_ON(e->refcnt != 0);
e->lc_number = e->lc_new_number = enr;
hlist_del_init(&e->colision);
if (enr == LC_FREE)
lh = &lc->free;
else {
hlist_add_head(&e->colision, lc_hash_slot(lc, enr));
lh = &lc->lru;
}
list_move(&e->list, lh);
}
void lc_seq_dump_details(struct seq_file *seq, struct lru_cache *lc, char *utext,
void (*detail) (struct seq_file *, struct lc_element *))
{
unsigned int nr_elements = lc->nr_elements;
struct lc_element *e;
int i;
seq_printf(seq, "\tnn: lc_number refcnt %s\n ", utext);
for (i = 0; i < nr_elements; i++) {
e = lc_element_by_index(lc, i);
if (e->lc_number == LC_FREE) {
seq_printf(seq, "\t%2d: FREE\n", i);
} else {
seq_printf(seq, "\t%2d: %4u %4u ", i,
e->lc_number, e->refcnt);
detail(seq, e);
}
}
}
