static inline void zbudpage_spin_lock(struct zbudpage *zbudpage)
{
struct page *page = (struct page *)zbudpage;
while (unlikely(test_and_set_bit_lock(PG_locked, &page->flags))) {
do {
cpu_relax();
} while (test_bit(PG_locked, &page->flags));
}
}
static inline void zbudpage_spin_unlock(struct zbudpage *zbudpage)
{
struct page *page = (struct page *)zbudpage;
clear_bit(PG_locked, &page->flags);
}
static inline int zbudpage_spin_trylock(struct zbudpage *zbudpage)
{
return trylock_page((struct page *)zbudpage);
}
static inline int zbudpage_is_locked(struct zbudpage *zbudpage)
{
return PageLocked((struct page *)zbudpage);
}
static inline void *kmap_zbudpage_atomic(struct zbudpage *zbudpage)
{
return kmap_atomic((struct page *)zbudpage);
}
static inline int zbudpage_is_dying(struct zbudpage *zbudpage)
{
struct page *page = (struct page *)zbudpage;
return test_bit(PG_reclaim, &page->flags);
}
static inline void zbudpage_set_dying(struct zbudpage *zbudpage)
{
struct page *page = (struct page *)zbudpage;
set_bit(PG_reclaim, &page->flags);
}
static inline void zbudpage_clear_dying(struct zbudpage *zbudpage)
{
struct page *page = (struct page *)zbudpage;
clear_bit(PG_reclaim, &page->flags);
}
static inline int zbudpage_is_zombie(struct zbudpage *zbudpage)
{
struct page *page = (struct page *)zbudpage;
return test_bit(PG_dirty, &page->flags);
}
static inline void zbudpage_set_zombie(struct zbudpage *zbudpage)
{
struct page *page = (struct page *)zbudpage;
set_bit(PG_dirty, &page->flags);
}
static inline void zbudpage_clear_zombie(struct zbudpage *zbudpage)
{
struct page *page = (struct page *)zbudpage;
clear_bit(PG_dirty, &page->flags);
}
static inline void kunmap_zbudpage_atomic(void *zbpg)
{
kunmap_atomic(zbpg);
}
static inline struct zbudpage *zbudref_to_zbudpage(struct zbudref *zref)
{
unsigned long zbud = (unsigned long)zref;
zbud &= ~1UL;
return (struct zbudpage *)zbud;
}
static inline struct zbudref *zbudpage_to_zbudref(struct zbudpage *zbudpage,
unsigned budnum)
{
unsigned long zbud = (unsigned long)zbudpage;
BUG_ON(budnum > 1);
zbud |= budnum;
return (struct zbudref *)zbud;
}
static inline int zbudref_budnum(struct zbudref *zbudref)
{
unsigned long zbud = (unsigned long)zbudref;
return zbud & 1UL;
}
static inline unsigned zbud_max_size(void)
{
return MAX_CHUNK << CHUNK_SHIFT;
}
static inline unsigned zbud_size_to_chunks(unsigned size)
{
BUG_ON(size == 0 || size > zbud_max_size());
return (size + CHUNK_SIZE - 1) >> CHUNK_SHIFT;
}
static inline char *zbud_data(void *zbpg,
unsigned budnum, unsigned size)
{
char *p;
BUG_ON(size == 0 || size > zbud_max_size());
p = (char *)zbpg;
if (budnum == 1)
p += PAGE_SIZE - ((size + CHUNK_SIZE - 1) & CHUNK_MASK);
return p;
}
static int zbud_debugfs_init(void)
{
struct dentry *root = debugfs_create_dir("zbud", NULL);
if (root == NULL)
return -ENXIO;
zdfs64("eph_zbytes", S_IRUGO, root, &zbud_eph_zbytes);
zdfs64("eph_cumul_zbytes", S_IRUGO, root, &zbud_eph_cumul_zbytes);
zdfs64("pers_zbytes", S_IRUGO, root, &zbud_pers_zbytes);
zdfs64("pers_cumul_zbytes", S_IRUGO, root, &zbud_pers_cumul_zbytes);
zdfs("eph_cumul_zpages", S_IRUGO, root, &zbud_eph_cumul_zpages);
zdfs("eph_evicted_pageframes", S_IRUGO, root,
&zbud_eph_evicted_pageframes);
zdfs("eph_zpages", S_IRUGO, root, &zbud_eph_zpages);
zdfs("eph_pageframes", S_IRUGO, root, &zbud_eph_pageframes);
zdfs("eph_buddied_count", S_IRUGO, root, &zbud_eph_buddied_count);
zdfs("eph_unbuddied_count", S_IRUGO, root, &zbud_eph_unbuddied_count);
zdfs("pers_cumul_zpages", S_IRUGO, root, &zbud_pers_cumul_zpages);
zdfs("pers_evicted_pageframes", S_IRUGO, root,
&zbud_pers_evicted_pageframes);
zdfs("pers_zpages", S_IRUGO, root, &zbud_pers_zpages);
zdfs("pers_pageframes", S_IRUGO, root, &zbud_pers_pageframes);
zdfs("pers_buddied_count", S_IRUGO, root, &zbud_pers_buddied_count);
zdfs("pers_unbuddied_count", S_IRUGO, root, &zbud_pers_unbuddied_count);
zdfs("pers_zombie_count", S_IRUGO, root, &zbud_pers_zombie_count);
return 0;
}
static inline int zbud_debugfs_init(void)
{
return 0;
}
static inline struct zbudpage *zbud_init_zbudpage(struct page *page, bool eph)
{
struct zbudpage *zbudpage = (struct zbudpage *)page;
BUG_ON(page == NULL);
INIT_LIST_HEAD(&zbudpage->budlist);
INIT_LIST_HEAD(&zbudpage->lru);
zbudpage->zbud0_size = 0;
zbudpage->zbud1_size = 0;
zbudpage->unevictable = 0;
if (eph)
zbud_eph_pageframes++;
else
zbud_pers_pageframes++;
return zbudpage;
}
static inline struct page *zbud_unuse_zbudpage(struct zbudpage *zbudpage,
bool eph)
{
struct page *page = (struct page *)zbudpage;
BUG_ON(!list_empty(&zbudpage->budlist));
BUG_ON(!list_empty(&zbudpage->lru));
BUG_ON(zbudpage->zbud0_size != 0);
BUG_ON(zbudpage->zbud1_size != 0);
BUG_ON(!PageLocked(page));
BUG_ON(zbudpage->unevictable != 0);
BUG_ON(zbudpage_is_dying(zbudpage));
BUG_ON(zbudpage_is_zombie(zbudpage));
if (eph)
zbud_eph_pageframes--;
else
zbud_pers_pageframes--;
zbudpage_spin_unlock(zbudpage);
page_mapcount_reset(page);
init_page_count(page);
page->index = 0;
return page;
}
static inline void zbud_unuse_zbud(struct zbudpage *zbudpage,
int budnum, bool eph)
{
unsigned size;
BUG_ON(!zbudpage_is_locked(zbudpage));
if (budnum == 0) {
size = zbudpage->zbud0_size;
zbudpage->zbud0_size = 0;
} else {
size = zbudpage->zbud1_size;
zbudpage->zbud1_size = 0;
}
if (eph) {
zbud_eph_zbytes -= size;
zbud_eph_zpages--;
} else {
zbud_pers_zbytes -= size;
zbud_pers_zpages--;
}
}
static void zbud_init_zbud(struct zbudpage *zbudpage, struct tmem_handle *th,
bool eph, void *cdata,
unsigned budnum, unsigned size)
{
char *to;
void *zbpg;
struct tmem_handle *to_th;
unsigned nchunks = zbud_size_to_chunks(size);
BUG_ON(!zbudpage_is_locked(zbudpage));
zbpg = kmap_zbudpage_atomic(zbudpage);
to = zbud_data(zbpg, budnum, size);
to_th = (struct tmem_handle *)to;
to_th->index = th->index;
to_th->oid = th->oid;
to_th->pool_id = th->pool_id;
to_th->client_id = th->client_id;
to += sizeof(struct tmem_handle);
if (cdata != NULL)
memcpy(to, cdata, size - sizeof(struct tmem_handle));
kunmap_zbudpage_atomic(zbpg);
if (budnum == 0)
zbudpage->zbud0_size = size;
else
zbudpage->zbud1_size = size;
if (eph) {
zbud_eph_cumul_chunk_counts[nchunks]++;
zbud_eph_zpages++;
zbud_eph_cumul_zpages++;
zbud_eph_zbytes += size;
zbud_eph_cumul_zbytes += size;
} else {
zbud_pers_cumul_chunk_counts[nchunks]++;
zbud_pers_zpages++;
zbud_pers_cumul_zpages++;
zbud_pers_zbytes += size;
zbud_pers_cumul_zbytes += size;
}
}
static void zbud_evict_tmem(struct zbudpage *zbudpage)
{
int i, j;
uint32_t pool_id[2], client_id[2];
uint32_t index[2];
struct tmem_oid oid[2];
struct tmem_pool *pool;
void *zbpg;
struct tmem_handle *th;
unsigned size;
zbpg = kmap_zbudpage_atomic(zbudpage);
for (i = 0, j = 0; i < 2; i++) {
size = (i == 0) ? zbudpage->zbud0_size : zbudpage->zbud1_size;
if (size) {
th = (struct tmem_handle *)zbud_data(zbpg, i, size);
client_id[j] = th->client_id;
pool_id[j] = th->pool_id;
oid[j] = th->oid;
index[j] = th->index;
j++;
zbud_unuse_zbud(zbudpage, i, true);
}
}
kunmap_zbudpage_atomic(zbpg);
zbudpage_spin_unlock(zbudpage);
for (i = 0; i < j; i++) {
pool = zcache_get_pool_by_id(client_id[i], pool_id[i]);
if (pool != NULL) {
tmem_flush_page(pool, &oid[i], index[i]);
zcache_put_pool(pool);
}
}
}
unsigned int zbud_max_buddy_size(void)
{
return zbud_max_size() - sizeof(struct tmem_handle);
}
struct page *zbud_free_and_delist(struct zbudref *zref, bool eph,
unsigned int *zsize, unsigned int *zpages)
{
unsigned long budnum = zbudref_budnum(zref);
struct zbudpage *zbudpage = zbudref_to_zbudpage(zref);
struct page *page = NULL;
unsigned chunks, bud_size, other_bud_size;
spinlock_t *lists_lock =
eph ? &zbud_eph_lists_lock : &zbud_pers_lists_lock;
struct zbud_unbuddied *unbud =
eph ? zbud_eph_unbuddied : zbud_pers_unbuddied;
spin_lock(lists_lock);
zbudpage_spin_lock(zbudpage);
if (zbudpage_is_dying(zbudpage)) {
zbudpage_spin_unlock(zbudpage);
spin_unlock(lists_lock);
*zpages = 0;
*zsize = 0;
goto out;
}
if (budnum == 0) {
bud_size = zbudpage->zbud0_size;
other_bud_size = zbudpage->zbud1_size;
} else {
bud_size = zbudpage->zbud1_size;
other_bud_size = zbudpage->zbud0_size;
}
*zsize = bud_size - sizeof(struct tmem_handle);
*zpages = 1;
zbud_unuse_zbud(zbudpage, budnum, eph);
if (other_bud_size == 0) {
chunks = zbud_size_to_chunks(bud_size) ;
if (zbudpage_is_zombie(zbudpage)) {
if (eph)
zbud_pers_zombie_count =
atomic_dec_return(&zbud_eph_zombie_atomic);
else
zbud_pers_zombie_count =
atomic_dec_return(&zbud_pers_zombie_atomic);
zbudpage_clear_zombie(zbudpage);
} else {
BUG_ON(list_empty(&unbud[chunks].list));
list_del_init(&zbudpage->budlist);
unbud[chunks].count--;
}
list_del_init(&zbudpage->lru);
spin_unlock(lists_lock);
if (eph)
zbud_eph_unbuddied_count--;
else
zbud_pers_unbuddied_count--;
page = zbud_unuse_zbudpage(zbudpage, eph);
} else {
chunks = zbud_size_to_chunks(other_bud_size) ;
if (!zbudpage_is_zombie(zbudpage)) {
list_del_init(&zbudpage->budlist);
list_add_tail(&zbudpage->budlist, &unbud[chunks].list);
unbud[chunks].count++;
}
if (eph) {
zbud_eph_buddied_count--;
zbud_eph_unbuddied_count++;
} else {
zbud_pers_unbuddied_count++;
zbud_pers_buddied_count--;
}
zbudpage_spin_unlock(zbudpage);
spin_unlock(lists_lock);
}
out:
return page;
}
struct zbudref *zbud_match_prep(struct tmem_handle *th, bool eph,
void *cdata, unsigned size)
{
struct zbudpage *zbudpage = NULL, *zbudpage2;
unsigned long budnum = 0UL;
unsigned nchunks;
int i, found_good_buddy = 0;
spinlock_t *lists_lock =
eph ? &zbud_eph_lists_lock : &zbud_pers_lists_lock;
struct zbud_unbuddied *unbud =
eph ? zbud_eph_unbuddied : zbud_pers_unbuddied;
size += sizeof(struct tmem_handle);
nchunks = zbud_size_to_chunks(size);
for (i = MAX_CHUNK - nchunks + 1; i > 0; i--) {
spin_lock(lists_lock);
if (!list_empty(&unbud[i].list)) {
list_for_each_entry_safe(zbudpage, zbudpage2,
&unbud[i].list, budlist) {
if (zbudpage_spin_trylock(zbudpage)) {
found_good_buddy = i;
goto found_unbuddied;
}
}
}
spin_unlock(lists_lock);
}
zbudpage = NULL;
goto out;
found_unbuddied:
BUG_ON(!zbudpage_is_locked(zbudpage));
BUG_ON(!((zbudpage->zbud0_size == 0) ^ (zbudpage->zbud1_size == 0)));
if (zbudpage->zbud0_size == 0)
budnum = 0UL;
else if (zbudpage->zbud1_size == 0)
budnum = 1UL;
list_del_init(&zbudpage->budlist);
if (eph) {
list_add_tail(&zbudpage->budlist, &zbud_eph_buddied_list);
unbud[found_good_buddy].count--;
zbud_eph_unbuddied_count--;
zbud_eph_buddied_count++;
list_del_init(&zbudpage->lru);
list_add_tail(&zbudpage->lru, &zbud_eph_lru_list);
} else {
list_add_tail(&zbudpage->budlist, &zbud_pers_buddied_list);
unbud[found_good_buddy].count--;
zbud_pers_unbuddied_count--;
zbud_pers_buddied_count++;
list_del_init(&zbudpage->lru);
list_add_tail(&zbudpage->lru, &zbud_pers_lru_list);
}
zbud_init_zbud(zbudpage, th, eph, cdata, budnum, size);
zbudpage->unevictable++;
BUG_ON(zbudpage->unevictable == 3);
zbudpage_spin_unlock(zbudpage);
spin_unlock(lists_lock);
out:
return zbudpage_to_zbudref(zbudpage, budnum);
}
struct zbudref *zbud_create_prep(struct tmem_handle *th, bool eph,
void *cdata, unsigned size,
struct page *newpage)
{
struct zbudpage *zbudpage;
unsigned long budnum = 0;
unsigned nchunks;
spinlock_t *lists_lock =
eph ? &zbud_eph_lists_lock : &zbud_pers_lists_lock;
struct zbud_unbuddied *unbud =
eph ? zbud_eph_unbuddied : zbud_pers_unbuddied;
#if 0
static unsigned long counter;
budnum = counter++ & 1;
#endif
if (size > zbud_max_buddy_size())
return NULL;
if (newpage == NULL)
return NULL;
size += sizeof(struct tmem_handle);
nchunks = zbud_size_to_chunks(size) ;
spin_lock(lists_lock);
zbudpage = zbud_init_zbudpage(newpage, eph);
zbudpage_spin_lock(zbudpage);
list_add_tail(&zbudpage->budlist, &unbud[nchunks].list);
if (eph) {
list_add_tail(&zbudpage->lru, &zbud_eph_lru_list);
zbud_eph_unbuddied_count++;
} else {
list_add_tail(&zbudpage->lru, &zbud_pers_lru_list);
zbud_pers_unbuddied_count++;
}
unbud[nchunks].count++;
zbud_init_zbud(zbudpage, th, eph, cdata, budnum, size);
zbudpage->unevictable++;
BUG_ON(zbudpage->unevictable == 3);
zbudpage_spin_unlock(zbudpage);
spin_unlock(lists_lock);
return zbudpage_to_zbudref(zbudpage, budnum);
}
void zbud_create_finish(struct zbudref *zref, bool eph)
{
struct zbudpage *zbudpage = zbudref_to_zbudpage(zref);
spinlock_t *lists_lock =
eph ? &zbud_eph_lists_lock : &zbud_pers_lists_lock;
spin_lock(lists_lock);
zbudpage_spin_lock(zbudpage);
BUG_ON(zbudpage_is_dying(zbudpage));
zbudpage->unevictable--;
BUG_ON((int)zbudpage->unevictable < 0);
zbudpage_spin_unlock(zbudpage);
spin_unlock(lists_lock);
}
int zbud_decompress(struct page *data_page, struct zbudref *zref, bool eph,
void (*decompress)(char *, unsigned int, char *))
{
struct zbudpage *zbudpage = zbudref_to_zbudpage(zref);
unsigned long budnum = zbudref_budnum(zref);
void *zbpg;
char *to_va, *from_va;
unsigned size;
int ret = -1;
spinlock_t *lists_lock =
eph ? &zbud_eph_lists_lock : &zbud_pers_lists_lock;
spin_lock(lists_lock);
zbudpage_spin_lock(zbudpage);
if (zbudpage_is_dying(zbudpage)) {
goto out;
}
zbpg = kmap_zbudpage_atomic(zbudpage);
to_va = kmap_atomic(data_page);
if (budnum == 0)
size = zbudpage->zbud0_size;
else
size = zbudpage->zbud1_size;
BUG_ON(size == 0 || size > zbud_max_size());
from_va = zbud_data(zbpg, budnum, size);
from_va += sizeof(struct tmem_handle);
size -= sizeof(struct tmem_handle);
decompress(from_va, size, to_va);
kunmap_atomic(to_va);
kunmap_zbudpage_atomic(zbpg);
ret = 0;
out:
zbudpage_spin_unlock(zbudpage);
spin_unlock(lists_lock);
return ret;
}
int zbud_copy_from_zbud(char *to_va, struct zbudref *zref,
size_t *sizep, bool eph)
{
struct zbudpage *zbudpage = zbudref_to_zbudpage(zref);
unsigned long budnum = zbudref_budnum(zref);
void *zbpg;
char *from_va;
unsigned size;
int ret = -1;
spinlock_t *lists_lock =
eph ? &zbud_eph_lists_lock : &zbud_pers_lists_lock;
spin_lock(lists_lock);
zbudpage_spin_lock(zbudpage);
if (zbudpage_is_dying(zbudpage)) {
goto out;
}
zbpg = kmap_zbudpage_atomic(zbudpage);
if (budnum == 0)
size = zbudpage->zbud0_size;
else
size = zbudpage->zbud1_size;
BUG_ON(size == 0 || size > zbud_max_size());
from_va = zbud_data(zbpg, budnum, size);
from_va += sizeof(struct tmem_handle);
size -= sizeof(struct tmem_handle);
*sizep = size;
memcpy(to_va, from_va, size);
kunmap_zbudpage_atomic(zbpg);
ret = 0;
out:
zbudpage_spin_unlock(zbudpage);
spin_unlock(lists_lock);
return ret;
}
int zbud_copy_to_zbud(struct zbudref *zref, char *from_va, bool eph)
{
struct zbudpage *zbudpage = zbudref_to_zbudpage(zref);
unsigned long budnum = zbudref_budnum(zref);
void *zbpg;
char *to_va;
unsigned size;
int ret = -1;
spinlock_t *lists_lock =
eph ? &zbud_eph_lists_lock : &zbud_pers_lists_lock;
spin_lock(lists_lock);
zbudpage_spin_lock(zbudpage);
if (zbudpage_is_dying(zbudpage)) {
goto out;
}
zbpg = kmap_zbudpage_atomic(zbudpage);
if (budnum == 0)
size = zbudpage->zbud0_size;
else
size = zbudpage->zbud1_size;
BUG_ON(size == 0 || size > zbud_max_size());
to_va = zbud_data(zbpg, budnum, size);
to_va += sizeof(struct tmem_handle);
size -= sizeof(struct tmem_handle);
memcpy(to_va, from_va, size);
kunmap_zbudpage_atomic(zbpg);
ret = 0;
out:
zbudpage_spin_unlock(zbudpage);
spin_unlock(lists_lock);
return ret;
}
struct page *zbud_evict_pageframe_lru(unsigned int *zsize, unsigned int *zpages)
{
struct zbudpage *zbudpage = NULL, *zbudpage2;
struct zbud_unbuddied *unbud = zbud_eph_unbuddied;
struct page *page = NULL;
bool irqs_disabled = irqs_disabled();
if (irqs_disabled)
spin_lock(&zbud_eph_lists_lock);
else
spin_lock_bh(&zbud_eph_lists_lock);
*zsize = 0;
if (list_empty(&zbud_eph_lru_list))
goto unlock_out;
list_for_each_entry_safe(zbudpage, zbudpage2, &zbud_eph_lru_list, lru) {
if (unlikely(!zbudpage_spin_trylock(zbudpage)))
continue;
if (unlikely(zbudpage->unevictable != 0)) {
zbudpage_spin_unlock(zbudpage);
continue;
}
goto evict_page;
}
unlock_out:
if (irqs_disabled)
spin_unlock(&zbud_eph_lists_lock);
else
spin_unlock_bh(&zbud_eph_lists_lock);
goto out;
evict_page:
list_del_init(&zbudpage->budlist);
list_del_init(&zbudpage->lru);
zbudpage_set_dying(zbudpage);
if (zbudpage->zbud0_size != 0 && zbudpage->zbud1_size != 0) {
*zsize = zbudpage->zbud0_size + zbudpage->zbud1_size -
(2 * sizeof(struct tmem_handle));
*zpages = 2;
} else if (zbudpage->zbud0_size != 0) {
unbud[zbud_size_to_chunks(zbudpage->zbud0_size)].count--;
*zsize = zbudpage->zbud0_size - sizeof(struct tmem_handle);
*zpages = 1;
} else if (zbudpage->zbud1_size != 0) {
unbud[zbud_size_to_chunks(zbudpage->zbud1_size)].count--;
*zsize = zbudpage->zbud1_size - sizeof(struct tmem_handle);
*zpages = 1;
} else {
BUG();
}
spin_unlock(&zbud_eph_lists_lock);
zbud_eph_evicted_pageframes++;
if (*zpages == 1)
zbud_eph_unbuddied_count--;
else
zbud_eph_buddied_count--;
zbud_evict_tmem(zbudpage);
zbudpage_spin_lock(zbudpage);
zbudpage_clear_dying(zbudpage);
page = zbud_unuse_zbudpage(zbudpage, true);
if (!irqs_disabled)
local_bh_enable();
out:
return page;
}
unsigned int zbud_make_zombie_lru(struct tmem_handle *th, unsigned char **data,
unsigned int *zsize, bool eph)
{
struct zbudpage *zbudpage = NULL, *zbudpag2;
struct tmem_handle *thfrom;
char *from_va;
void *zbpg;
unsigned size;
int ret = 0, i;
spinlock_t *lists_lock =
eph ? &zbud_eph_lists_lock : &zbud_pers_lists_lock;
struct list_head *lru_list =
eph ? &zbud_eph_lru_list : &zbud_pers_lru_list;
spin_lock_bh(lists_lock);
if (list_empty(lru_list))
goto out;
list_for_each_entry_safe(zbudpage, zbudpag2, lru_list, lru) {
if (unlikely(!zbudpage_spin_trylock(zbudpage)))
continue;
if (unlikely(zbudpage->unevictable != 0)) {
zbudpage_spin_unlock(zbudpage);
continue;
}
goto zombify_page;
}
goto out;
zombify_page:
list_del_init(&zbudpage->budlist);
zbudpage_set_zombie(zbudpage);
list_del_init(&zbudpage->lru);
if (eph) {
list_add_tail(&zbudpage->lru, &zbud_eph_zombie_list);
zbud_eph_zombie_count =
atomic_inc_return(&zbud_eph_zombie_atomic);
} else {
list_add_tail(&zbudpage->lru, &zbud_pers_zombie_list);
zbud_pers_zombie_count =
atomic_inc_return(&zbud_pers_zombie_atomic);
}
zbpg = kmap_zbudpage_atomic(zbudpage);
for (i = 0; i < 2; i++) {
size = (i == 0) ? zbudpage->zbud0_size : zbudpage->zbud1_size;
if (size) {
from_va = zbud_data(zbpg, i, size);
thfrom = (struct tmem_handle *)from_va;
from_va += sizeof(struct tmem_handle);
size -= sizeof(struct tmem_handle);
if (th != NULL)
th[ret] = *thfrom;
if (data != NULL)
memcpy(data[ret], from_va, size);
if (zsize != NULL)
*zsize++ = size;
ret++;
}
}
kunmap_zbudpage_atomic(zbpg);
zbudpage_spin_unlock(zbudpage);
out:
spin_unlock_bh(lists_lock);
return ret;
}
void zbud_init(void)
{
int i;
zbud_debugfs_init();
BUG_ON((sizeof(struct tmem_handle) * 2 > CHUNK_SIZE));
BUG_ON(sizeof(struct zbudpage) > sizeof(struct page));
for (i = 0; i < NCHUNKS; i++) {
INIT_LIST_HEAD(&zbud_eph_unbuddied[i].list);
INIT_LIST_HEAD(&zbud_pers_unbuddied[i].list);
}
}
