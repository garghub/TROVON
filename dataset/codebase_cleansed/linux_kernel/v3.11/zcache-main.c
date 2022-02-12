static inline bool PageWasActive(struct page *page)
{
return true;
}
static inline void SetPageWasActive(struct page *page)
{
}
static inline void frontswap_tmem_exclusive_gets(bool b)
{
}
static inline int zcache_comp_op(enum comp_op op,
const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen)
{
struct crypto_comp *tfm;
int ret = -1;
BUG_ON(!zcache_comp_pcpu_tfms);
tfm = *per_cpu_ptr(zcache_comp_pcpu_tfms, get_cpu());
BUG_ON(!tfm);
switch (op) {
case ZCACHE_COMPOP_COMPRESS:
ret = crypto_comp_compress(tfm, src, slen, dst, dlen);
break;
case ZCACHE_COMPOP_DECOMPRESS:
ret = crypto_comp_decompress(tfm, src, slen, dst, dlen);
break;
default:
ret = -EINVAL;
}
put_cpu();
return ret;
}
static inline bool is_local_client(struct zcache_client *cli)
{
return cli == &zcache_host;
}
static struct zcache_client *zcache_get_client_by_id(uint16_t cli_id)
{
struct zcache_client *cli = &zcache_host;
if (cli_id != LOCAL_CLIENT) {
if (cli_id >= MAX_CLIENTS)
goto out;
cli = &zcache_clients[cli_id];
}
out:
return cli;
}
struct tmem_pool *zcache_get_pool_by_id(uint16_t cli_id, uint16_t poolid)
{
struct tmem_pool *pool = NULL;
struct zcache_client *cli = NULL;
cli = zcache_get_client_by_id(cli_id);
if (cli == NULL)
goto out;
if (!is_local_client(cli))
atomic_inc(&cli->refcount);
if (poolid < MAX_POOLS_PER_CLIENT) {
pool = cli->tmem_pools[poolid];
if (pool != NULL)
atomic_inc(&pool->refcount);
}
out:
return pool;
}
void zcache_put_pool(struct tmem_pool *pool)
{
struct zcache_client *cli = NULL;
if (pool == NULL)
BUG();
cli = pool->client;
atomic_dec(&pool->refcount);
if (!is_local_client(cli))
atomic_dec(&cli->refcount);
}
int zcache_new_client(uint16_t cli_id)
{
struct zcache_client *cli;
int ret = -1;
cli = zcache_get_client_by_id(cli_id);
if (cli == NULL)
goto out;
if (cli->allocated)
goto out;
cli->allocated = 1;
ret = 0;
out:
return ret;
}
static struct tmem_objnode *zcache_objnode_alloc(struct tmem_pool *pool)
{
struct tmem_objnode *objnode = NULL;
struct zcache_preload *kp;
int i;
kp = &__get_cpu_var(zcache_preloads);
for (i = 0; i < ARRAY_SIZE(kp->objnodes); i++) {
objnode = kp->objnodes[i];
if (objnode != NULL) {
kp->objnodes[i] = NULL;
break;
}
}
BUG_ON(objnode == NULL);
inc_zcache_objnode_count();
return objnode;
}
static void zcache_objnode_free(struct tmem_objnode *objnode,
struct tmem_pool *pool)
{
dec_zcache_objnode_count();
kmem_cache_free(zcache_objnode_cache, objnode);
}
static struct tmem_obj *zcache_obj_alloc(struct tmem_pool *pool)
{
struct tmem_obj *obj = NULL;
struct zcache_preload *kp;
kp = &__get_cpu_var(zcache_preloads);
obj = kp->obj;
BUG_ON(obj == NULL);
kp->obj = NULL;
inc_zcache_obj_count();
return obj;
}
static void zcache_obj_free(struct tmem_obj *obj, struct tmem_pool *pool)
{
dec_zcache_obj_count();
kmem_cache_free(zcache_obj_cache, obj);
}
static bool page_is_zero_filled(struct page *p)
{
unsigned int pos;
char *page;
page = kmap_atomic(p);
for (pos = 0; pos < PAGE_SIZE / sizeof(*page); pos++) {
if (page[pos]) {
kunmap_atomic(page);
return false;
}
}
kunmap_atomic(page);
return true;
}
static void handle_zero_filled_page(void *p)
{
void *user_mem;
struct page *page = (struct page *)p;
user_mem = kmap_atomic(page);
memset(user_mem, 0, PAGE_SIZE);
kunmap_atomic(user_mem);
flush_dcache_page(page);
}
static struct page *zcache_alloc_page(void)
{
struct page *page = alloc_page(ZCACHE_GFP_MASK);
if (page != NULL)
inc_zcache_pageframes_alloced();
return page;
}
static void zcache_free_page(struct page *page)
{
long curr_pageframes;
static long max_pageframes, min_pageframes;
if (page == NULL)
BUG();
__free_page(page);
inc_zcache_pageframes_freed();
curr_pageframes = curr_pageframes_count();
if (curr_pageframes > max_pageframes)
max_pageframes = curr_pageframes;
if (curr_pageframes < min_pageframes)
min_pageframes = curr_pageframes;
#ifdef CONFIG_ZCACHE_DEBUG
if (curr_pageframes > 2L || curr_pageframes < -2L) {
}
#endif
}
static void *zcache_pampd_eph_create(char *data, size_t size, bool raw,
struct tmem_handle *th)
{
void *pampd = NULL, *cdata = data;
unsigned clen = size;
bool zero_filled = false;
struct page *page = (struct page *)(data), *newpage;
if (page_is_zero_filled(page)) {
clen = 0;
zero_filled = true;
inc_zcache_zero_filled_pages();
goto got_pampd;
}
if (!raw) {
zcache_compress(page, &cdata, &clen);
if (clen > zbud_max_buddy_size()) {
inc_zcache_compress_poor();
goto out;
}
} else {
BUG_ON(clen > zbud_max_buddy_size());
}
pampd = (void *)zbud_match_prep(th, true, cdata, clen);
if (pampd != NULL)
goto got_pampd;
newpage = zcache_alloc_page();
if (newpage != NULL)
goto create_in_new_page;
inc_zcache_failed_getfreepages();
newpage = zcache_evict_eph_pageframe();
if (newpage == NULL) {
inc_zcache_eph_ate_tail_failed();
goto out;
}
inc_zcache_eph_ate_tail();
create_in_new_page:
pampd = (void *)zbud_create_prep(th, true, cdata, clen, newpage);
BUG_ON(pampd == NULL);
inc_zcache_eph_pageframes();
got_pampd:
inc_zcache_eph_zbytes(clen);
inc_zcache_eph_zpages();
if (ramster_enabled && raw && !zero_filled)
ramster_count_foreign_pages(true, 1);
if (zero_filled)
pampd = (void *)ZERO_FILLED;
out:
return pampd;
}
static void *zcache_pampd_pers_create(char *data, size_t size, bool raw,
struct tmem_handle *th)
{
void *pampd = NULL, *cdata = data;
unsigned clen = size;
bool zero_filled = false;
struct page *page = (struct page *)(data), *newpage;
unsigned long zbud_mean_zsize;
unsigned long curr_pers_zpages, total_zsize;
if (data == NULL) {
BUG_ON(!ramster_enabled);
goto create_pampd;
}
if (page_is_zero_filled(page)) {
clen = 0;
zero_filled = true;
inc_zcache_zero_filled_pages();
goto got_pampd;
}
curr_pers_zpages = zcache_pers_zpages;
if (!raw)
zcache_compress(page, &cdata, &clen);
if (clen > zbud_max_zsize) {
inc_zcache_compress_poor();
goto out;
}
if ((clen > zbud_max_mean_zsize) && (curr_pers_zpages > 0)) {
total_zsize = zcache_pers_zbytes;
if ((long)total_zsize < 0)
total_zsize = 0;
zbud_mean_zsize = div_u64(total_zsize,
curr_pers_zpages);
if (zbud_mean_zsize > zbud_max_mean_zsize) {
inc_zcache_mean_compress_poor();
goto out;
}
}
create_pampd:
pampd = (void *)zbud_match_prep(th, false, cdata, clen);
if (pampd != NULL)
goto got_pampd;
newpage = zcache_alloc_page();
if (newpage != NULL)
goto create_in_new_page;
inc_zcache_failed_getfreepages();
newpage = zcache_evict_eph_pageframe();
if (newpage == NULL) {
inc_zcache_pers_ate_eph_failed();
goto out;
}
inc_zcache_pers_ate_eph();
create_in_new_page:
pampd = (void *)zbud_create_prep(th, false, cdata, clen, newpage);
BUG_ON(pampd == NULL);
inc_zcache_pers_pageframes();
got_pampd:
inc_zcache_pers_zpages();
inc_zcache_pers_zbytes(clen);
if (ramster_enabled && raw && !zero_filled)
ramster_count_foreign_pages(false, 1);
if (zero_filled)
pampd = (void *)ZERO_FILLED;
out:
return pampd;
}
void *zcache_pampd_create(char *data, unsigned int size, bool raw,
int eph, struct tmem_handle *th)
{
void *pampd = NULL;
struct zcache_preload *kp;
struct tmem_objnode *objnode;
struct tmem_obj *obj;
int i;
BUG_ON(!irqs_disabled());
BUG_ON(zcache_objnode_cache == NULL);
BUG_ON(zcache_obj_cache == NULL);
kp = &__get_cpu_var(zcache_preloads);
for (i = 0; i < ARRAY_SIZE(kp->objnodes); i++) {
objnode = kp->objnodes[i];
if (objnode == NULL) {
objnode = kmem_cache_alloc(zcache_objnode_cache,
ZCACHE_GFP_MASK);
if (unlikely(objnode == NULL)) {
inc_zcache_failed_alloc();
goto out;
}
kp->objnodes[i] = objnode;
}
}
if (kp->obj == NULL) {
obj = kmem_cache_alloc(zcache_obj_cache, ZCACHE_GFP_MASK);
kp->obj = obj;
}
if (unlikely(kp->obj == NULL)) {
inc_zcache_failed_alloc();
goto out;
}
if (eph)
pampd = zcache_pampd_eph_create(data, size, raw, th);
else
pampd = zcache_pampd_pers_create(data, size, raw, th);
out:
return pampd;
}
void zcache_pampd_create_finish(void *pampd, bool eph)
{
if (pampd != (void *)ZERO_FILLED)
zbud_create_finish((struct zbudref *)pampd, eph);
}
static void zcache_decompress(char *from_va, unsigned int size, char *to_va)
{
int ret;
unsigned int outlen = PAGE_SIZE;
ret = zcache_comp_op(ZCACHE_COMPOP_DECOMPRESS, from_va, size,
to_va, &outlen);
BUG_ON(ret);
BUG_ON(outlen != PAGE_SIZE);
}
void zcache_decompress_to_page(char *from_va, unsigned int size,
struct page *to_page)
{
char *to_va = kmap_atomic(to_page);
zcache_decompress(from_va, size, to_va);
kunmap_atomic(to_va);
}
static int zcache_pampd_get_data(char *data, size_t *sizep, bool raw,
void *pampd, struct tmem_pool *pool,
struct tmem_oid *oid, uint32_t index)
{
int ret;
bool eph = !is_persistent(pool);
BUG_ON(preemptible());
BUG_ON(eph);
BUG_ON(pampd_is_remote(pampd));
if (pampd == (void *)ZERO_FILLED) {
handle_zero_filled_page(data);
if (!raw)
*sizep = PAGE_SIZE;
return 0;
}
if (raw)
ret = zbud_copy_from_zbud(data, (struct zbudref *)pampd,
sizep, eph);
else {
ret = zbud_decompress((struct page *)(data),
(struct zbudref *)pampd, false,
zcache_decompress);
*sizep = PAGE_SIZE;
}
return ret;
}
static int zcache_pampd_get_data_and_free(char *data, size_t *sizep, bool raw,
void *pampd, struct tmem_pool *pool,
struct tmem_oid *oid, uint32_t index)
{
int ret = 0;
bool eph = !is_persistent(pool), zero_filled = false;
struct page *page = NULL;
unsigned int zsize, zpages;
BUG_ON(preemptible());
BUG_ON(pampd_is_remote(pampd));
if (pampd == (void *)ZERO_FILLED) {
handle_zero_filled_page(data);
zero_filled = true;
zsize = 0;
zpages = 1;
if (!raw)
*sizep = PAGE_SIZE;
dec_zcache_zero_filled_pages();
goto zero_fill;
}
if (raw)
ret = zbud_copy_from_zbud(data, (struct zbudref *)pampd,
sizep, eph);
else {
ret = zbud_decompress((struct page *)(data),
(struct zbudref *)pampd, eph,
zcache_decompress);
*sizep = PAGE_SIZE;
}
page = zbud_free_and_delist((struct zbudref *)pampd, eph,
&zsize, &zpages);
zero_fill:
if (eph) {
if (page)
dec_zcache_eph_pageframes();
dec_zcache_eph_zpages(zpages);
dec_zcache_eph_zbytes(zsize);
} else {
if (page)
dec_zcache_pers_pageframes();
dec_zcache_pers_zpages(zpages);
dec_zcache_pers_zbytes(zsize);
}
if (!is_local_client(pool->client) && !zero_filled)
ramster_count_foreign_pages(eph, -1);
if (page && !zero_filled)
zcache_free_page(page);
return ret;
}
static void zcache_pampd_free(void *pampd, struct tmem_pool *pool,
struct tmem_oid *oid, uint32_t index, bool acct)
{
struct page *page = NULL;
unsigned int zsize, zpages;
bool zero_filled = false;
BUG_ON(preemptible());
if (pampd == (void *)ZERO_FILLED) {
zero_filled = true;
zsize = 0;
zpages = 1;
dec_zcache_zero_filled_pages();
}
if (pampd_is_remote(pampd) && !zero_filled) {
BUG_ON(!ramster_enabled);
pampd = ramster_pampd_free(pampd, pool, oid, index, acct);
if (pampd == NULL)
return;
}
if (is_ephemeral(pool)) {
if (!zero_filled)
page = zbud_free_and_delist((struct zbudref *)pampd,
true, &zsize, &zpages);
if (page)
dec_zcache_eph_pageframes();
dec_zcache_eph_zpages(zpages);
dec_zcache_eph_zbytes(zsize);
} else {
if (!zero_filled)
page = zbud_free_and_delist((struct zbudref *)pampd,
false, &zsize, &zpages);
if (page)
dec_zcache_pers_pageframes();
dec_zcache_pers_zpages(zpages);
dec_zcache_pers_zbytes(zsize);
}
if (!is_local_client(pool->client) && !zero_filled)
ramster_count_foreign_pages(is_ephemeral(pool), -1);
if (page && !zero_filled)
zcache_free_page(page);
}
static void zcache_compress(struct page *from, void **out_va, unsigned *out_len)
{
int ret;
unsigned char *dmem = __get_cpu_var(zcache_dstmem);
char *from_va;
BUG_ON(!irqs_disabled());
BUG_ON(dmem == NULL);
*out_len = PAGE_SIZE << ZCACHE_DSTMEM_ORDER;
from_va = kmap_atomic(from);
mb();
ret = zcache_comp_op(ZCACHE_COMPOP_COMPRESS, from_va, PAGE_SIZE, dmem,
out_len);
BUG_ON(ret);
*out_va = dmem;
kunmap_atomic(from_va);
}
static int zcache_comp_cpu_up(int cpu)
{
struct crypto_comp *tfm;
tfm = crypto_alloc_comp(zcache_comp_name, 0, 0);
if (IS_ERR(tfm))
return NOTIFY_BAD;
*per_cpu_ptr(zcache_comp_pcpu_tfms, cpu) = tfm;
return NOTIFY_OK;
}
static void zcache_comp_cpu_down(int cpu)
{
struct crypto_comp *tfm;
tfm = *per_cpu_ptr(zcache_comp_pcpu_tfms, cpu);
crypto_free_comp(tfm);
*per_cpu_ptr(zcache_comp_pcpu_tfms, cpu) = NULL;
}
static int zcache_cpu_notifier(struct notifier_block *nb,
unsigned long action, void *pcpu)
{
int ret, i, cpu = (long)pcpu;
struct zcache_preload *kp;
switch (action) {
case CPU_UP_PREPARE:
ret = zcache_comp_cpu_up(cpu);
if (ret != NOTIFY_OK) {
pr_err("%s: can't allocate compressor xform\n",
namestr);
return ret;
}
per_cpu(zcache_dstmem, cpu) = (void *)__get_free_pages(
GFP_KERNEL | __GFP_REPEAT, ZCACHE_DSTMEM_ORDER);
if (ramster_enabled)
ramster_cpu_up(cpu);
break;
case CPU_DEAD:
case CPU_UP_CANCELED:
zcache_comp_cpu_down(cpu);
free_pages((unsigned long)per_cpu(zcache_dstmem, cpu),
ZCACHE_DSTMEM_ORDER);
per_cpu(zcache_dstmem, cpu) = NULL;
kp = &per_cpu(zcache_preloads, cpu);
for (i = 0; i < ARRAY_SIZE(kp->objnodes); i++) {
if (kp->objnodes[i])
kmem_cache_free(zcache_objnode_cache,
kp->objnodes[i]);
}
if (kp->obj) {
kmem_cache_free(zcache_obj_cache, kp->obj);
kp->obj = NULL;
}
if (ramster_enabled)
ramster_cpu_down(cpu);
break;
default:
break;
}
return NOTIFY_OK;
}
static struct page *zcache_evict_eph_pageframe(void)
{
struct page *page;
unsigned int zsize = 0, zpages = 0;
page = zbud_evict_pageframe_lru(&zsize, &zpages);
if (page == NULL)
goto out;
dec_zcache_eph_zbytes(zsize);
dec_zcache_eph_zpages(zpages);
inc_zcache_evicted_eph_zpages(zpages);
dec_zcache_eph_pageframes();
inc_zcache_evicted_eph_pageframes();
out:
return page;
}
static inline void inc_zcache_outstanding_writeback_pages(void)
{
zcache_outstanding_writeback_pages =
atomic_inc_return(&zcache_outstanding_writeback_pages_atomic);
}
static inline void dec_zcache_outstanding_writeback_pages(void)
{
zcache_outstanding_writeback_pages =
atomic_dec_return(&zcache_outstanding_writeback_pages_atomic);
}
static void zcache_end_swap_write(struct bio *bio, int err)
{
end_swap_bio_write(bio, err);
dec_zcache_outstanding_writeback_pages();
zcache_writtenback_pages++;
}
static int zcache_get_swap_cache_page(int type, pgoff_t offset,
struct page *new_page)
{
struct page *found_page;
swp_entry_t entry = swp_entry(type, offset);
int err;
BUG_ON(new_page == NULL);
do {
found_page = find_get_page(&swapper_space, entry.val);
if (found_page)
return 0;
err = radix_tree_preload(GFP_KERNEL);
if (err)
break;
err = swapcache_prepare(entry);
if (err == -EEXIST) {
radix_tree_preload_end();
continue;
}
if (err) {
radix_tree_preload_end();
break;
}
__set_page_locked(new_page);
SetPageSwapBacked(new_page);
err = __add_to_swap_cache(new_page, entry);
if (likely(!err)) {
radix_tree_preload_end();
lru_cache_add_anon(new_page);
return 1;
}
radix_tree_preload_end();
ClearPageSwapBacked(new_page);
__clear_page_locked(new_page);
swapcache_free(entry, NULL);
} while (err != -ENOMEM);
return -ENOMEM;
}
static int zcache_frontswap_writeback_zpage(int type, pgoff_t offset,
struct page *newpage)
{
struct page *page = newpage;
int ret;
struct writeback_control wbc = {
.sync_mode = WB_SYNC_NONE,
};
ret = zcache_get_swap_cache_page(type, offset, page);
if (ret < 0)
return ret;
else if (ret == 0) {
__frontswap_invalidate_page(type, offset);
return 1;
}
BUG_ON(!frontswap_has_exclusive_gets);
__frontswap_load(page);
SetPageUptodate(page);
SetPageReclaim(page);
(void)__swap_writepage(page, &wbc, zcache_end_swap_write);
page_cache_release(page);
inc_zcache_outstanding_writeback_pages();
return 0;
}
static int zcache_frontswap_writeback(void)
{
struct tmem_handle th[2];
int ret = 0;
int nzbuds, writeback_ret;
unsigned type;
struct page *znewpage1 = NULL, *znewpage2 = NULL;
struct page *evictpage1 = NULL, *evictpage2 = NULL;
struct page *newpage1 = NULL, *newpage2 = NULL;
struct page *page1 = NULL, *page2 = NULL;
pgoff_t offset;
znewpage1 = alloc_page(ZCACHE_GFP_MASK);
znewpage2 = alloc_page(ZCACHE_GFP_MASK);
if (znewpage1 == NULL)
evictpage1 = zcache_evict_eph_pageframe();
if (znewpage2 == NULL)
evictpage2 = zcache_evict_eph_pageframe();
if ((evictpage1 == NULL || evictpage2 == NULL) &&
atomic_read(&zcache_outstanding_writeback_pages_atomic) >
ZCACHE_MAX_OUTSTANDING_WRITEBACK_PAGES) {
goto free_and_out;
}
if (znewpage1 == NULL && evictpage1 == NULL)
newpage1 = alloc_page(GFP_KERNEL);
if (znewpage2 == NULL && evictpage2 == NULL)
newpage2 = alloc_page(GFP_KERNEL);
if (newpage1 == NULL || newpage2 == NULL)
goto free_and_out;
nzbuds = zbud_make_zombie_lru(&th[0], NULL, NULL, false);
if (nzbuds == 0) {
ret = -ENOENT;
goto free_and_out;
}
unswiz(th[0].oid, th[0].index, &type, &offset);
page1 = (znewpage1 != NULL) ? znewpage1 :
((newpage1 != NULL) ? newpage1 : evictpage1);
writeback_ret = zcache_frontswap_writeback_zpage(type, offset, page1);
if (writeback_ret < 0) {
ret = -ENOMEM;
goto free_and_out;
}
if (evictpage1 != NULL)
zcache_pageframes_freed =
atomic_inc_return(&zcache_pageframes_freed_atomic);
if (writeback_ret == 0) {
znewpage1 = NULL;
newpage1 = NULL;
evictpage1 = NULL;
}
if (nzbuds < 2)
goto free_and_out;
unswiz(th[1].oid, th[1].index, &type, &offset);
page2 = (znewpage2 != NULL) ? znewpage2 :
((newpage2 != NULL) ? newpage2 : evictpage2);
writeback_ret = zcache_frontswap_writeback_zpage(type, offset, page2);
if (writeback_ret < 0) {
ret = -ENOMEM;
goto free_and_out;
}
if (evictpage2 != NULL)
zcache_pageframes_freed =
atomic_inc_return(&zcache_pageframes_freed_atomic);
if (writeback_ret == 0) {
znewpage2 = NULL;
newpage2 = NULL;
evictpage2 = NULL;
}
free_and_out:
if (znewpage1 != NULL)
page_cache_release(znewpage1);
if (znewpage2 != NULL)
page_cache_release(znewpage2);
if (newpage1 != NULL)
page_cache_release(newpage1);
if (newpage2 != NULL)
page_cache_release(newpage2);
if (evictpage1 != NULL)
zcache_free_page(evictpage1);
if (evictpage2 != NULL)
zcache_free_page(evictpage2);
return ret;
}
static int shrink_zcache_memory(struct shrinker *shrink,
struct shrink_control *sc)
{
static bool in_progress;
int ret = -1;
int nr = sc->nr_to_scan;
int nr_evict = 0;
int nr_writeback = 0;
struct page *page;
int file_pageframes_inuse, anon_pageframes_inuse;
if (nr <= 0)
goto skip_evict;
if (in_progress)
goto skip_evict;
in_progress = true;
zcache_last_active_file_pageframes =
global_page_state(NR_LRU_BASE + LRU_ACTIVE_FILE);
zcache_last_inactive_file_pageframes =
global_page_state(NR_LRU_BASE + LRU_INACTIVE_FILE);
file_pageframes_inuse = zcache_last_active_file_pageframes +
zcache_last_inactive_file_pageframes;
if (zcache_eph_pageframes > file_pageframes_inuse)
nr_evict = zcache_eph_pageframes - file_pageframes_inuse;
else
nr_evict = 0;
while (nr_evict-- > 0) {
page = zcache_evict_eph_pageframe();
if (page == NULL)
break;
zcache_free_page(page);
}
zcache_last_active_anon_pageframes =
global_page_state(NR_LRU_BASE + LRU_ACTIVE_ANON);
zcache_last_inactive_anon_pageframes =
global_page_state(NR_LRU_BASE + LRU_INACTIVE_ANON);
anon_pageframes_inuse = zcache_last_active_anon_pageframes +
zcache_last_inactive_anon_pageframes;
if (zcache_pers_pageframes > anon_pageframes_inuse)
nr_writeback = zcache_pers_pageframes - anon_pageframes_inuse;
else
nr_writeback = 0;
while (nr_writeback-- > 0) {
#ifdef CONFIG_ZCACHE_WRITEBACK
int writeback_ret;
writeback_ret = zcache_frontswap_writeback();
if (writeback_ret == -ENOMEM)
#endif
break;
}
in_progress = false;
skip_evict:
zcache_last_active_file_pageframes =
global_page_state(NR_LRU_BASE + LRU_ACTIVE_FILE);
zcache_last_inactive_file_pageframes =
global_page_state(NR_LRU_BASE + LRU_INACTIVE_FILE);
ret = zcache_eph_pageframes - zcache_last_active_file_pageframes +
zcache_last_inactive_file_pageframes;
if (ret < 0)
ret = 0;
return ret;
}
int zcache_put_page(int cli_id, int pool_id, struct tmem_oid *oidp,
uint32_t index, void *page,
unsigned int size, bool raw, int ephemeral)
{
struct tmem_pool *pool;
struct tmem_handle th;
int ret = -1;
void *pampd = NULL;
BUG_ON(!irqs_disabled());
pool = zcache_get_pool_by_id(cli_id, pool_id);
if (unlikely(pool == NULL))
goto out;
if (!zcache_freeze) {
ret = 0;
th.client_id = cli_id;
th.pool_id = pool_id;
th.oid = *oidp;
th.index = index;
pampd = zcache_pampd_create((char *)page, size, raw,
ephemeral, &th);
if (pampd == NULL) {
ret = -ENOMEM;
if (ephemeral)
inc_zcache_failed_eph_puts();
else
inc_zcache_failed_pers_puts();
} else {
if (ramster_enabled)
ramster_do_preload_flnode(pool);
ret = tmem_put(pool, oidp, index, 0, pampd);
if (ret < 0)
BUG();
}
zcache_put_pool(pool);
} else {
inc_zcache_put_to_flush();
if (ramster_enabled)
ramster_do_preload_flnode(pool);
if (atomic_read(&pool->obj_count) > 0)
(void)tmem_flush_page(pool, oidp, index);
zcache_put_pool(pool);
}
out:
return ret;
}
int zcache_get_page(int cli_id, int pool_id, struct tmem_oid *oidp,
uint32_t index, void *page,
size_t *sizep, bool raw, int get_and_free)
{
struct tmem_pool *pool;
int ret = -1;
bool eph;
if (!raw) {
BUG_ON(irqs_disabled());
BUG_ON(in_softirq());
}
pool = zcache_get_pool_by_id(cli_id, pool_id);
eph = is_ephemeral(pool);
if (likely(pool != NULL)) {
if (atomic_read(&pool->obj_count) > 0)
ret = tmem_get(pool, oidp, index, (char *)(page),
sizep, raw, get_and_free);
zcache_put_pool(pool);
}
WARN_ONCE((!is_ephemeral(pool) && (ret != 0)),
"zcache_get fails on persistent pool, "
"bad things are very likely to happen soon\n");
#ifdef RAMSTER_TESTING
if (ret != 0 && ret != -1 && !(ret == -EINVAL && is_ephemeral(pool)))
pr_err("TESTING zcache_get tmem_get returns ret=%d\n", ret);
#endif
return ret;
}
int zcache_flush_page(int cli_id, int pool_id,
struct tmem_oid *oidp, uint32_t index)
{
struct tmem_pool *pool;
int ret = -1;
unsigned long flags;
local_irq_save(flags);
inc_zcache_flush_total();
pool = zcache_get_pool_by_id(cli_id, pool_id);
if (ramster_enabled)
ramster_do_preload_flnode(pool);
if (likely(pool != NULL)) {
if (atomic_read(&pool->obj_count) > 0)
ret = tmem_flush_page(pool, oidp, index);
zcache_put_pool(pool);
}
if (ret >= 0)
inc_zcache_flush_found();
local_irq_restore(flags);
return ret;
}
int zcache_flush_object(int cli_id, int pool_id,
struct tmem_oid *oidp)
{
struct tmem_pool *pool;
int ret = -1;
unsigned long flags;
local_irq_save(flags);
inc_zcache_flobj_total();
pool = zcache_get_pool_by_id(cli_id, pool_id);
if (ramster_enabled)
ramster_do_preload_flnode(pool);
if (likely(pool != NULL)) {
if (atomic_read(&pool->obj_count) > 0)
ret = tmem_flush_object(pool, oidp);
zcache_put_pool(pool);
}
if (ret >= 0)
inc_zcache_flobj_found();
local_irq_restore(flags);
return ret;
}
static int zcache_client_destroy_pool(int cli_id, int pool_id)
{
struct tmem_pool *pool = NULL;
struct zcache_client *cli = NULL;
int ret = -1;
if (pool_id < 0)
goto out;
if (cli_id == LOCAL_CLIENT)
cli = &zcache_host;
else if ((unsigned int)cli_id < MAX_CLIENTS)
cli = &zcache_clients[cli_id];
if (cli == NULL)
goto out;
atomic_inc(&cli->refcount);
pool = cli->tmem_pools[pool_id];
if (pool == NULL)
goto out;
cli->tmem_pools[pool_id] = NULL;
while (atomic_read(&pool->refcount) != 0)
;
atomic_dec(&cli->refcount);
local_bh_disable();
ret = tmem_destroy_pool(pool);
local_bh_enable();
kfree(pool);
if (cli_id == LOCAL_CLIENT)
pr_info("%s: destroyed local pool id=%d\n", namestr, pool_id);
else
pr_info("%s: destroyed pool id=%d, client=%d\n",
namestr, pool_id, cli_id);
out:
return ret;
}
int zcache_new_pool(uint16_t cli_id, uint32_t flags)
{
int poolid = -1;
struct tmem_pool *pool;
struct zcache_client *cli = NULL;
if (cli_id == LOCAL_CLIENT)
cli = &zcache_host;
else if ((unsigned int)cli_id < MAX_CLIENTS)
cli = &zcache_clients[cli_id];
if (cli == NULL)
goto out;
atomic_inc(&cli->refcount);
pool = kmalloc(sizeof(struct tmem_pool), GFP_ATOMIC);
if (pool == NULL)
goto out;
for (poolid = 0; poolid < MAX_POOLS_PER_CLIENT; poolid++)
if (cli->tmem_pools[poolid] == NULL)
break;
if (poolid >= MAX_POOLS_PER_CLIENT) {
pr_info("%s: pool creation failed: max exceeded\n", namestr);
kfree(pool);
poolid = -1;
goto out;
}
atomic_set(&pool->refcount, 0);
pool->client = cli;
pool->pool_id = poolid;
tmem_new_pool(pool, flags);
cli->tmem_pools[poolid] = pool;
if (cli_id == LOCAL_CLIENT)
pr_info("%s: created %s local tmem pool, id=%d\n", namestr,
flags & TMEM_POOL_PERSIST ? "persistent" : "ephemeral",
poolid);
else
pr_info("%s: created %s tmem pool, id=%d, client=%d\n", namestr,
flags & TMEM_POOL_PERSIST ? "persistent" : "ephemeral",
poolid, cli_id);
out:
if (cli != NULL)
atomic_dec(&cli->refcount);
return poolid;
}
static int zcache_local_new_pool(uint32_t flags)
{
return zcache_new_pool(LOCAL_CLIENT, flags);
}
int zcache_autocreate_pool(unsigned int cli_id, unsigned int pool_id, bool eph)
{
struct tmem_pool *pool;
struct zcache_client *cli = NULL;
uint32_t flags = eph ? 0 : TMEM_POOL_PERSIST;
int ret = -1;
BUG_ON(!ramster_enabled);
if (cli_id == LOCAL_CLIENT)
goto out;
if (pool_id >= MAX_POOLS_PER_CLIENT)
goto out;
if (cli_id >= MAX_CLIENTS)
goto out;
cli = &zcache_clients[cli_id];
if ((eph && disable_cleancache) || (!eph && disable_frontswap)) {
pr_err("zcache_autocreate_pool: pool type disabled\n");
goto out;
}
if (!cli->allocated) {
if (zcache_new_client(cli_id)) {
pr_err("zcache_autocreate_pool: can't create client\n");
goto out;
}
cli = &zcache_clients[cli_id];
}
atomic_inc(&cli->refcount);
pool = cli->tmem_pools[pool_id];
if (pool != NULL) {
if (pool->persistent && eph) {
pr_err("zcache_autocreate_pool: type mismatch\n");
goto out;
}
ret = 0;
goto out;
}
pool = kmalloc(sizeof(struct tmem_pool), GFP_KERNEL);
if (pool == NULL)
goto out;
atomic_set(&pool->refcount, 0);
pool->client = cli;
pool->pool_id = pool_id;
tmem_new_pool(pool, flags);
cli->tmem_pools[pool_id] = pool;
pr_info("%s: AUTOcreated %s tmem poolid=%d, for remote client=%d\n",
namestr, flags & TMEM_POOL_PERSIST ? "persistent" : "ephemeral",
pool_id, cli_id);
ret = 0;
out:
if (cli != NULL)
atomic_dec(&cli->refcount);
return ret;
}
static void zcache_cleancache_put_page(int pool_id,
struct cleancache_filekey key,
pgoff_t index, struct page *page)
{
u32 ind = (u32) index;
struct tmem_oid oid = *(struct tmem_oid *)&key;
if (!disable_cleancache_ignore_nonactive && !PageWasActive(page)) {
inc_zcache_eph_nonactive_puts_ignored();
return;
}
if (likely(ind == index))
(void)zcache_put_page(LOCAL_CLIENT, pool_id, &oid, index,
page, PAGE_SIZE, false, 1);
}
static int zcache_cleancache_get_page(int pool_id,
struct cleancache_filekey key,
pgoff_t index, struct page *page)
{
u32 ind = (u32) index;
struct tmem_oid oid = *(struct tmem_oid *)&key;
size_t size;
int ret = -1;
if (likely(ind == index)) {
ret = zcache_get_page(LOCAL_CLIENT, pool_id, &oid, index,
page, &size, false, 0);
BUG_ON(ret >= 0 && size != PAGE_SIZE);
if (ret == 0)
SetPageWasActive(page);
}
return ret;
}
static void zcache_cleancache_flush_page(int pool_id,
struct cleancache_filekey key,
pgoff_t index)
{
u32 ind = (u32) index;
struct tmem_oid oid = *(struct tmem_oid *)&key;
if (likely(ind == index))
(void)zcache_flush_page(LOCAL_CLIENT, pool_id, &oid, ind);
}
static void zcache_cleancache_flush_inode(int pool_id,
struct cleancache_filekey key)
{
struct tmem_oid oid = *(struct tmem_oid *)&key;
(void)zcache_flush_object(LOCAL_CLIENT, pool_id, &oid);
}
static void zcache_cleancache_flush_fs(int pool_id)
{
if (pool_id >= 0)
(void)zcache_client_destroy_pool(LOCAL_CLIENT, pool_id);
}
static int zcache_cleancache_init_fs(size_t pagesize)
{
BUG_ON(sizeof(struct cleancache_filekey) !=
sizeof(struct tmem_oid));
BUG_ON(pagesize != PAGE_SIZE);
return zcache_local_new_pool(0);
}
static int zcache_cleancache_init_shared_fs(char *uuid, size_t pagesize)
{
BUG_ON(sizeof(struct cleancache_filekey) !=
sizeof(struct tmem_oid));
BUG_ON(pagesize != PAGE_SIZE);
return zcache_local_new_pool(0);
}
struct cleancache_ops *zcache_cleancache_register_ops(void)
{
struct cleancache_ops *old_ops =
cleancache_register_ops(&zcache_cleancache_ops);
return old_ops;
}
static inline struct tmem_oid oswiz(unsigned type, u32 ind)
{
struct tmem_oid oid = { .oid = { 0 } };
oid.oid[0] = _oswiz(type, ind);
return oid;
}
static void unswiz(struct tmem_oid oid, u32 index,
unsigned *type, pgoff_t *offset)
{
*type = (unsigned)(oid.oid[0] >> SWIZ_BITS);
*offset = (pgoff_t)((index << SWIZ_BITS) |
(oid.oid[0] & SWIZ_MASK));
}
static int zcache_frontswap_put_page(unsigned type, pgoff_t offset,
struct page *page)
{
u64 ind64 = (u64)offset;
u32 ind = (u32)offset;
struct tmem_oid oid = oswiz(type, ind);
int ret = -1;
unsigned long flags;
BUG_ON(!PageLocked(page));
if (!disable_frontswap_ignore_nonactive && !PageWasActive(page)) {
inc_zcache_pers_nonactive_puts_ignored();
ret = -ERANGE;
goto out;
}
if (likely(ind64 == ind)) {
local_irq_save(flags);
ret = zcache_put_page(LOCAL_CLIENT, zcache_frontswap_poolid,
&oid, iswiz(ind),
page, PAGE_SIZE, false, 0);
local_irq_restore(flags);
}
out:
return ret;
}
static int zcache_frontswap_get_page(unsigned type, pgoff_t offset,
struct page *page)
{
u64 ind64 = (u64)offset;
u32 ind = (u32)offset;
struct tmem_oid oid = oswiz(type, ind);
size_t size;
int ret = -1, get_and_free;
if (frontswap_has_exclusive_gets)
get_and_free = 1;
else
get_and_free = -1;
BUG_ON(!PageLocked(page));
if (likely(ind64 == ind)) {
ret = zcache_get_page(LOCAL_CLIENT, zcache_frontswap_poolid,
&oid, iswiz(ind),
page, &size, false, get_and_free);
BUG_ON(ret >= 0 && size != PAGE_SIZE);
}
return ret;
}
static void zcache_frontswap_flush_page(unsigned type, pgoff_t offset)
{
u64 ind64 = (u64)offset;
u32 ind = (u32)offset;
struct tmem_oid oid = oswiz(type, ind);
if (likely(ind64 == ind))
(void)zcache_flush_page(LOCAL_CLIENT, zcache_frontswap_poolid,
&oid, iswiz(ind));
}
static void zcache_frontswap_flush_area(unsigned type)
{
struct tmem_oid oid;
int ind;
for (ind = SWIZ_MASK; ind >= 0; ind--) {
oid = oswiz(type, ind);
(void)zcache_flush_object(LOCAL_CLIENT,
zcache_frontswap_poolid, &oid);
}
}
static void zcache_frontswap_init(unsigned ignored)
{
if (zcache_frontswap_poolid < 0)
zcache_frontswap_poolid =
zcache_local_new_pool(TMEM_POOL_PERSIST);
}
struct frontswap_ops *zcache_frontswap_register_ops(void)
{
struct frontswap_ops *old_ops =
frontswap_register_ops(&zcache_frontswap_ops);
return old_ops;
}
static int __init enable_zcache(char *s)
{
zcache_enabled = true;
return 1;
}
static int __init enable_ramster(char *s)
{
zcache_enabled = true;
#ifdef CONFIG_RAMSTER
ramster_enabled = true;
#endif
return 1;
}
static int __init no_cleancache(char *s)
{
disable_cleancache = true;
return 1;
}
static int __init no_frontswap(char *s)
{
disable_frontswap = true;
return 1;
}
static int __init no_frontswap_exclusive_gets(char *s)
{
frontswap_has_exclusive_gets = false;
return 1;
}
static int __init no_frontswap_ignore_nonactive(char *s)
{
disable_frontswap_ignore_nonactive = true;
return 1;
}
static int __init no_cleancache_ignore_nonactive(char *s)
{
disable_cleancache_ignore_nonactive = true;
return 1;
}
static int __init enable_zcache_compressor(char *s)
{
strlcpy(zcache_comp_name, s, sizeof(zcache_comp_name));
zcache_enabled = true;
return 1;
}
static int zcache_comp_init(void)
{
int ret = 0;
#ifdef CONFIG_ZCACHE_MODULE
ret = crypto_has_comp(zcache_comp_name, 0, 0);
if (!ret) {
ret = -1;
goto out;
}
#else
if (*zcache_comp_name != '\0') {
ret = crypto_has_comp(zcache_comp_name, 0, 0);
if (!ret) {
pr_info("zcache: %s not supported\n",
zcache_comp_name);
ret = 1;
goto out;
}
}
if (!ret)
strcpy(zcache_comp_name, "lzo");
ret = crypto_has_comp(zcache_comp_name, 0, 0);
if (!ret) {
ret = 1;
goto out;
}
#endif
pr_info("zcache: using %s compressor\n", zcache_comp_name);
ret = 0;
zcache_comp_pcpu_tfms = alloc_percpu(struct crypto_comp *);
if (!zcache_comp_pcpu_tfms)
ret = 1;
out:
return ret;
}
static int zcache_init(void)
{
int ret = 0;
#ifdef CONFIG_ZCACHE_MODULE
zcache_enabled = 1;
#endif
if (ramster_enabled) {
namestr = "ramster";
ramster_register_pamops(&zcache_pamops);
}
zcache_debugfs_init();
if (zcache_enabled) {
unsigned int cpu;
tmem_register_hostops(&zcache_hostops);
tmem_register_pamops(&zcache_pamops);
ret = register_cpu_notifier(&zcache_cpu_notifier_block);
if (ret) {
pr_err("%s: can't register cpu notifier\n", namestr);
goto out;
}
ret = zcache_comp_init();
if (ret) {
pr_err("%s: compressor initialization failed\n",
namestr);
goto out;
}
for_each_online_cpu(cpu) {
void *pcpu = (void *)(long)cpu;
zcache_cpu_notifier(&zcache_cpu_notifier_block,
CPU_UP_PREPARE, pcpu);
}
}
zcache_objnode_cache = kmem_cache_create("zcache_objnode",
sizeof(struct tmem_objnode), 0, 0, NULL);
zcache_obj_cache = kmem_cache_create("zcache_obj",
sizeof(struct tmem_obj), 0, 0, NULL);
ret = zcache_new_client(LOCAL_CLIENT);
if (ret) {
pr_err("%s: can't create client\n", namestr);
goto out;
}
zbud_init();
if (zcache_enabled && !disable_cleancache) {
struct cleancache_ops *old_ops;
register_shrinker(&zcache_shrinker);
old_ops = zcache_cleancache_register_ops();
pr_info("%s: cleancache enabled using kernel transcendent "
"memory and compression buddies\n", namestr);
#ifdef CONFIG_ZCACHE_DEBUG
pr_info("%s: cleancache: ignorenonactive = %d\n",
namestr, !disable_cleancache_ignore_nonactive);
#endif
if (old_ops != NULL)
pr_warn("%s: cleancache_ops overridden\n", namestr);
}
if (zcache_enabled && !disable_frontswap) {
struct frontswap_ops *old_ops;
old_ops = zcache_frontswap_register_ops();
if (frontswap_has_exclusive_gets)
frontswap_tmem_exclusive_gets(true);
pr_info("%s: frontswap enabled using kernel transcendent "
"memory and compression buddies\n", namestr);
#ifdef CONFIG_ZCACHE_DEBUG
pr_info("%s: frontswap: excl gets = %d active only = %d\n",
namestr, frontswap_has_exclusive_gets,
!disable_frontswap_ignore_nonactive);
#endif
if (IS_ERR(old_ops) || old_ops) {
if (IS_ERR(old_ops))
return PTR_RET(old_ops);
pr_warn("%s: frontswap_ops overridden\n", namestr);
}
}
if (ramster_enabled)
ramster_init(!disable_cleancache, !disable_frontswap,
frontswap_has_exclusive_gets,
!disable_frontswap_selfshrink);
out:
return ret;
}
