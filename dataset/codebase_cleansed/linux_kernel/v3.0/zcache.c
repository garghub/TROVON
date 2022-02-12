static inline unsigned zbud_max_buddy_size(void)
{
return MAX_CHUNK << CHUNK_SHIFT;
}
static inline unsigned zbud_size_to_chunks(unsigned size)
{
BUG_ON(size == 0 || size > zbud_max_buddy_size());
return (size + CHUNK_SIZE - 1) >> CHUNK_SHIFT;
}
static inline int zbud_budnum(struct zbud_hdr *zh)
{
unsigned offset = (unsigned long)zh & (PAGE_SIZE - 1);
struct zbud_page *zbpg = NULL;
unsigned budnum = -1U;
int i;
for (i = 0; i < ZBUD_MAX_BUDS; i++)
if (offset == offsetof(typeof(*zbpg), buddy[i])) {
budnum = i;
break;
}
BUG_ON(budnum == -1U);
return budnum;
}
static char *zbud_data(struct zbud_hdr *zh, unsigned size)
{
struct zbud_page *zbpg;
char *p;
unsigned budnum;
ASSERT_SENTINEL(zh, ZBH);
budnum = zbud_budnum(zh);
BUG_ON(size == 0 || size > zbud_max_buddy_size());
zbpg = container_of(zh, struct zbud_page, buddy[budnum]);
ASSERT_SPINLOCK(&zbpg->lock);
p = (char *)zbpg;
if (budnum == 0)
p += ((sizeof(struct zbud_page) + CHUNK_SIZE - 1) &
CHUNK_MASK);
else if (budnum == 1)
p += PAGE_SIZE - ((size + CHUNK_SIZE - 1) & CHUNK_MASK);
return p;
}
static struct zbud_page *zbud_alloc_raw_page(void)
{
struct zbud_page *zbpg = NULL;
struct zbud_hdr *zh0, *zh1;
bool recycled = 0;
spin_lock(&zbpg_unused_list_spinlock);
if (!list_empty(&zbpg_unused_list)) {
zbpg = list_first_entry(&zbpg_unused_list,
struct zbud_page, bud_list);
list_del_init(&zbpg->bud_list);
zcache_zbpg_unused_list_count--;
recycled = 1;
}
spin_unlock(&zbpg_unused_list_spinlock);
if (zbpg == NULL)
zbpg = zcache_get_free_page();
if (likely(zbpg != NULL)) {
INIT_LIST_HEAD(&zbpg->bud_list);
zh0 = &zbpg->buddy[0]; zh1 = &zbpg->buddy[1];
spin_lock_init(&zbpg->lock);
if (recycled) {
ASSERT_INVERTED_SENTINEL(zbpg, ZBPG);
SET_SENTINEL(zbpg, ZBPG);
BUG_ON(zh0->size != 0 || tmem_oid_valid(&zh0->oid));
BUG_ON(zh1->size != 0 || tmem_oid_valid(&zh1->oid));
} else {
atomic_inc(&zcache_zbud_curr_raw_pages);
INIT_LIST_HEAD(&zbpg->bud_list);
SET_SENTINEL(zbpg, ZBPG);
zh0->size = 0; zh1->size = 0;
tmem_oid_set_invalid(&zh0->oid);
tmem_oid_set_invalid(&zh1->oid);
}
}
return zbpg;
}
static void zbud_free_raw_page(struct zbud_page *zbpg)
{
struct zbud_hdr *zh0 = &zbpg->buddy[0], *zh1 = &zbpg->buddy[1];
ASSERT_SENTINEL(zbpg, ZBPG);
BUG_ON(!list_empty(&zbpg->bud_list));
ASSERT_SPINLOCK(&zbpg->lock);
BUG_ON(zh0->size != 0 || tmem_oid_valid(&zh0->oid));
BUG_ON(zh1->size != 0 || tmem_oid_valid(&zh1->oid));
INVERT_SENTINEL(zbpg, ZBPG);
spin_unlock(&zbpg->lock);
spin_lock(&zbpg_unused_list_spinlock);
list_add(&zbpg->bud_list, &zbpg_unused_list);
zcache_zbpg_unused_list_count++;
spin_unlock(&zbpg_unused_list_spinlock);
}
static unsigned zbud_free(struct zbud_hdr *zh)
{
unsigned size;
ASSERT_SENTINEL(zh, ZBH);
BUG_ON(!tmem_oid_valid(&zh->oid));
size = zh->size;
BUG_ON(zh->size == 0 || zh->size > zbud_max_buddy_size());
zh->size = 0;
tmem_oid_set_invalid(&zh->oid);
INVERT_SENTINEL(zh, ZBH);
zcache_zbud_curr_zbytes -= size;
atomic_dec(&zcache_zbud_curr_zpages);
return size;
}
static void zbud_free_and_delist(struct zbud_hdr *zh)
{
unsigned chunks;
struct zbud_hdr *zh_other;
unsigned budnum = zbud_budnum(zh), size;
struct zbud_page *zbpg =
container_of(zh, struct zbud_page, buddy[budnum]);
spin_lock(&zbpg->lock);
if (list_empty(&zbpg->bud_list)) {
spin_unlock(&zbpg->lock);
return;
}
size = zbud_free(zh);
ASSERT_SPINLOCK(&zbpg->lock);
zh_other = &zbpg->buddy[(budnum == 0) ? 1 : 0];
if (zh_other->size == 0) {
chunks = zbud_size_to_chunks(size) ;
spin_lock(&zbud_budlists_spinlock);
BUG_ON(list_empty(&zbud_unbuddied[chunks].list));
list_del_init(&zbpg->bud_list);
zbud_unbuddied[chunks].count--;
spin_unlock(&zbud_budlists_spinlock);
zbud_free_raw_page(zbpg);
} else {
chunks = zbud_size_to_chunks(zh_other->size) ;
spin_lock(&zbud_budlists_spinlock);
list_del_init(&zbpg->bud_list);
zcache_zbud_buddied_count--;
list_add_tail(&zbpg->bud_list, &zbud_unbuddied[chunks].list);
zbud_unbuddied[chunks].count++;
spin_unlock(&zbud_budlists_spinlock);
spin_unlock(&zbpg->lock);
}
}
static struct zbud_hdr *zbud_create(uint32_t pool_id, struct tmem_oid *oid,
uint32_t index, struct page *page,
void *cdata, unsigned size)
{
struct zbud_hdr *zh0, *zh1, *zh = NULL;
struct zbud_page *zbpg = NULL, *ztmp;
unsigned nchunks;
char *to;
int i, found_good_buddy = 0;
nchunks = zbud_size_to_chunks(size) ;
for (i = MAX_CHUNK - nchunks + 1; i > 0; i--) {
spin_lock(&zbud_budlists_spinlock);
if (!list_empty(&zbud_unbuddied[i].list)) {
list_for_each_entry_safe(zbpg, ztmp,
&zbud_unbuddied[i].list, bud_list) {
if (spin_trylock(&zbpg->lock)) {
found_good_buddy = i;
goto found_unbuddied;
}
}
}
spin_unlock(&zbud_budlists_spinlock);
}
zbpg = zbud_alloc_raw_page();
if (unlikely(zbpg == NULL))
goto out;
spin_lock(&zbpg->lock);
spin_lock(&zbud_budlists_spinlock);
list_add_tail(&zbpg->bud_list, &zbud_unbuddied[nchunks].list);
zbud_unbuddied[nchunks].count++;
zh = &zbpg->buddy[0];
goto init_zh;
found_unbuddied:
ASSERT_SPINLOCK(&zbpg->lock);
zh0 = &zbpg->buddy[0]; zh1 = &zbpg->buddy[1];
BUG_ON(!((zh0->size == 0) ^ (zh1->size == 0)));
if (zh0->size != 0) {
ASSERT_SENTINEL(zh0, ZBH);
zh = zh1;
} else if (zh1->size != 0) {
ASSERT_SENTINEL(zh1, ZBH);
zh = zh0;
} else
BUG();
list_del_init(&zbpg->bud_list);
zbud_unbuddied[found_good_buddy].count--;
list_add_tail(&zbpg->bud_list, &zbud_buddied_list);
zcache_zbud_buddied_count++;
init_zh:
SET_SENTINEL(zh, ZBH);
zh->size = size;
zh->index = index;
zh->oid = *oid;
zh->pool_id = pool_id;
spin_unlock(&zbud_budlists_spinlock);
to = zbud_data(zh, size);
memcpy(to, cdata, size);
spin_unlock(&zbpg->lock);
zbud_cumul_chunk_counts[nchunks]++;
atomic_inc(&zcache_zbud_curr_zpages);
zcache_zbud_cumul_zpages++;
zcache_zbud_curr_zbytes += size;
zcache_zbud_cumul_zbytes += size;
out:
return zh;
}
static int zbud_decompress(struct page *page, struct zbud_hdr *zh)
{
struct zbud_page *zbpg;
unsigned budnum = zbud_budnum(zh);
size_t out_len = PAGE_SIZE;
char *to_va, *from_va;
unsigned size;
int ret = 0;
zbpg = container_of(zh, struct zbud_page, buddy[budnum]);
spin_lock(&zbpg->lock);
if (list_empty(&zbpg->bud_list)) {
ret = -EINVAL;
goto out;
}
ASSERT_SENTINEL(zh, ZBH);
BUG_ON(zh->size == 0 || zh->size > zbud_max_buddy_size());
to_va = kmap_atomic(page, KM_USER0);
size = zh->size;
from_va = zbud_data(zh, size);
ret = lzo1x_decompress_safe(from_va, size, to_va, &out_len);
BUG_ON(ret != LZO_E_OK);
BUG_ON(out_len != PAGE_SIZE);
kunmap_atomic(to_va, KM_USER0);
out:
spin_unlock(&zbpg->lock);
return ret;
}
static void zbud_evict_zbpg(struct zbud_page *zbpg)
{
struct zbud_hdr *zh;
int i, j;
uint32_t pool_id[ZBUD_MAX_BUDS], index[ZBUD_MAX_BUDS];
struct tmem_oid oid[ZBUD_MAX_BUDS];
struct tmem_pool *pool;
ASSERT_SPINLOCK(&zbpg->lock);
BUG_ON(!list_empty(&zbpg->bud_list));
for (i = 0, j = 0; i < ZBUD_MAX_BUDS; i++) {
zh = &zbpg->buddy[i];
if (zh->size) {
pool_id[j] = zh->pool_id;
oid[j] = zh->oid;
index[j] = zh->index;
j++;
zbud_free(zh);
}
}
spin_unlock(&zbpg->lock);
for (i = 0; i < j; i++) {
pool = zcache_get_pool_by_id(pool_id[i]);
if (pool != NULL) {
tmem_flush_page(pool, &oid[i], index[i]);
zcache_put_pool(pool);
}
}
ASSERT_SENTINEL(zbpg, ZBPG);
spin_lock(&zbpg->lock);
zbud_free_raw_page(zbpg);
}
static void zbud_evict_pages(int nr)
{
struct zbud_page *zbpg;
int i;
retry_unused_list:
spin_lock_bh(&zbpg_unused_list_spinlock);
if (!list_empty(&zbpg_unused_list)) {
zbpg = list_first_entry(&zbpg_unused_list,
struct zbud_page, bud_list);
list_del_init(&zbpg->bud_list);
zcache_zbpg_unused_list_count--;
atomic_dec(&zcache_zbud_curr_raw_pages);
spin_unlock_bh(&zbpg_unused_list_spinlock);
zcache_free_page(zbpg);
zcache_evicted_raw_pages++;
if (--nr <= 0)
goto out;
goto retry_unused_list;
}
spin_unlock_bh(&zbpg_unused_list_spinlock);
for (i = 0; i < MAX_CHUNK; i++) {
retry_unbud_list_i:
spin_lock_bh(&zbud_budlists_spinlock);
if (list_empty(&zbud_unbuddied[i].list)) {
spin_unlock_bh(&zbud_budlists_spinlock);
continue;
}
list_for_each_entry(zbpg, &zbud_unbuddied[i].list, bud_list) {
if (unlikely(!spin_trylock(&zbpg->lock)))
continue;
list_del_init(&zbpg->bud_list);
zbud_unbuddied[i].count--;
spin_unlock(&zbud_budlists_spinlock);
zcache_evicted_unbuddied_pages++;
zbud_evict_zbpg(zbpg);
local_bh_enable();
if (--nr <= 0)
goto out;
goto retry_unbud_list_i;
}
spin_unlock_bh(&zbud_budlists_spinlock);
}
retry_bud_list:
spin_lock_bh(&zbud_budlists_spinlock);
if (list_empty(&zbud_buddied_list)) {
spin_unlock_bh(&zbud_budlists_spinlock);
goto out;
}
list_for_each_entry(zbpg, &zbud_buddied_list, bud_list) {
if (unlikely(!spin_trylock(&zbpg->lock)))
continue;
list_del_init(&zbpg->bud_list);
zcache_zbud_buddied_count--;
spin_unlock(&zbud_budlists_spinlock);
zcache_evicted_buddied_pages++;
zbud_evict_zbpg(zbpg);
local_bh_enable();
if (--nr <= 0)
goto out;
goto retry_bud_list;
}
spin_unlock_bh(&zbud_budlists_spinlock);
out:
return;
}
static void zbud_init(void)
{
int i;
INIT_LIST_HEAD(&zbud_buddied_list);
zcache_zbud_buddied_count = 0;
for (i = 0; i < NCHUNKS; i++) {
INIT_LIST_HEAD(&zbud_unbuddied[i].list);
zbud_unbuddied[i].count = 0;
}
}
static int zbud_show_unbuddied_list_counts(char *buf)
{
int i;
char *p = buf;
for (i = 0; i < NCHUNKS - 1; i++)
p += sprintf(p, "%u ", zbud_unbuddied[i].count);
p += sprintf(p, "%d\n", zbud_unbuddied[i].count);
return p - buf;
}
static int zbud_show_cumul_chunk_counts(char *buf)
{
unsigned long i, chunks = 0, total_chunks = 0, sum_total_chunks = 0;
unsigned long total_chunks_lte_21 = 0, total_chunks_lte_32 = 0;
unsigned long total_chunks_lte_42 = 0;
char *p = buf;
for (i = 0; i < NCHUNKS; i++) {
p += sprintf(p, "%lu ", zbud_cumul_chunk_counts[i]);
chunks += zbud_cumul_chunk_counts[i];
total_chunks += zbud_cumul_chunk_counts[i];
sum_total_chunks += i * zbud_cumul_chunk_counts[i];
if (i == 21)
total_chunks_lte_21 = total_chunks;
if (i == 32)
total_chunks_lte_32 = total_chunks;
if (i == 42)
total_chunks_lte_42 = total_chunks;
}
p += sprintf(p, "<=21:%lu <=32:%lu <=42:%lu, mean:%lu\n",
total_chunks_lte_21, total_chunks_lte_32, total_chunks_lte_42,
chunks == 0 ? 0 : sum_total_chunks / chunks);
return p - buf;
}
static struct zv_hdr *zv_create(struct xv_pool *xvpool, uint32_t pool_id,
struct tmem_oid *oid, uint32_t index,
void *cdata, unsigned clen)
{
struct page *page;
struct zv_hdr *zv = NULL;
uint32_t offset;
int ret;
BUG_ON(!irqs_disabled());
ret = xv_malloc(xvpool, clen + sizeof(struct zv_hdr),
&page, &offset, ZCACHE_GFP_MASK);
if (unlikely(ret))
goto out;
zv = kmap_atomic(page, KM_USER0) + offset;
zv->index = index;
zv->oid = *oid;
zv->pool_id = pool_id;
SET_SENTINEL(zv, ZVH);
memcpy((char *)zv + sizeof(struct zv_hdr), cdata, clen);
kunmap_atomic(zv, KM_USER0);
out:
return zv;
}
static void zv_free(struct xv_pool *xvpool, struct zv_hdr *zv)
{
unsigned long flags;
struct page *page;
uint32_t offset;
uint16_t size;
ASSERT_SENTINEL(zv, ZVH);
size = xv_get_object_size(zv) - sizeof(*zv);
BUG_ON(size == 0 || size > zv_max_page_size);
INVERT_SENTINEL(zv, ZVH);
page = virt_to_page(zv);
offset = (unsigned long)zv & ~PAGE_MASK;
local_irq_save(flags);
xv_free(xvpool, page, offset);
local_irq_restore(flags);
}
static void zv_decompress(struct page *page, struct zv_hdr *zv)
{
size_t clen = PAGE_SIZE;
char *to_va;
unsigned size;
int ret;
ASSERT_SENTINEL(zv, ZVH);
size = xv_get_object_size(zv) - sizeof(*zv);
BUG_ON(size == 0 || size > zv_max_page_size);
to_va = kmap_atomic(page, KM_USER0);
ret = lzo1x_decompress_safe((char *)zv + sizeof(*zv),
size, to_va, &clen);
kunmap_atomic(to_va, KM_USER0);
BUG_ON(ret != LZO_E_OK);
BUG_ON(clen != PAGE_SIZE);
}
static struct tmem_pool *zcache_get_pool_by_id(uint32_t poolid)
{
struct tmem_pool *pool = NULL;
if (poolid >= 0) {
pool = zcache_client.tmem_pools[poolid];
if (pool != NULL)
atomic_inc(&pool->refcount);
}
return pool;
}
static void zcache_put_pool(struct tmem_pool *pool)
{
if (pool != NULL)
atomic_dec(&pool->refcount);
}
static int zcache_do_preload(struct tmem_pool *pool)
{
struct zcache_preload *kp;
struct tmem_objnode *objnode;
struct tmem_obj *obj;
void *page;
int ret = -ENOMEM;
if (unlikely(zcache_objnode_cache == NULL))
goto out;
if (unlikely(zcache_obj_cache == NULL))
goto out;
if (!spin_trylock(&zcache_direct_reclaim_lock)) {
zcache_aborted_preload++;
goto out;
}
preempt_disable();
kp = &__get_cpu_var(zcache_preloads);
while (kp->nr < ARRAY_SIZE(kp->objnodes)) {
preempt_enable_no_resched();
objnode = kmem_cache_alloc(zcache_objnode_cache,
ZCACHE_GFP_MASK);
if (unlikely(objnode == NULL)) {
zcache_failed_alloc++;
goto unlock_out;
}
preempt_disable();
kp = &__get_cpu_var(zcache_preloads);
if (kp->nr < ARRAY_SIZE(kp->objnodes))
kp->objnodes[kp->nr++] = objnode;
else
kmem_cache_free(zcache_objnode_cache, objnode);
}
preempt_enable_no_resched();
obj = kmem_cache_alloc(zcache_obj_cache, ZCACHE_GFP_MASK);
if (unlikely(obj == NULL)) {
zcache_failed_alloc++;
goto unlock_out;
}
page = (void *)__get_free_page(ZCACHE_GFP_MASK);
if (unlikely(page == NULL)) {
zcache_failed_get_free_pages++;
kmem_cache_free(zcache_obj_cache, obj);
goto unlock_out;
}
preempt_disable();
kp = &__get_cpu_var(zcache_preloads);
if (kp->obj == NULL)
kp->obj = obj;
else
kmem_cache_free(zcache_obj_cache, obj);
if (kp->page == NULL)
kp->page = page;
else
free_page((unsigned long)page);
ret = 0;
unlock_out:
spin_unlock(&zcache_direct_reclaim_lock);
out:
return ret;
}
static void *zcache_get_free_page(void)
{
struct zcache_preload *kp;
void *page;
kp = &__get_cpu_var(zcache_preloads);
page = kp->page;
BUG_ON(page == NULL);
kp->page = NULL;
return page;
}
static void zcache_free_page(void *p)
{
free_page((unsigned long)p);
}
static struct tmem_objnode *zcache_objnode_alloc(struct tmem_pool *pool)
{
struct tmem_objnode *objnode = NULL;
unsigned long count;
struct zcache_preload *kp;
kp = &__get_cpu_var(zcache_preloads);
if (kp->nr <= 0)
goto out;
objnode = kp->objnodes[kp->nr - 1];
BUG_ON(objnode == NULL);
kp->objnodes[kp->nr - 1] = NULL;
kp->nr--;
count = atomic_inc_return(&zcache_curr_objnode_count);
if (count > zcache_curr_objnode_count_max)
zcache_curr_objnode_count_max = count;
out:
return objnode;
}
static void zcache_objnode_free(struct tmem_objnode *objnode,
struct tmem_pool *pool)
{
atomic_dec(&zcache_curr_objnode_count);
BUG_ON(atomic_read(&zcache_curr_objnode_count) < 0);
kmem_cache_free(zcache_objnode_cache, objnode);
}
static struct tmem_obj *zcache_obj_alloc(struct tmem_pool *pool)
{
struct tmem_obj *obj = NULL;
unsigned long count;
struct zcache_preload *kp;
kp = &__get_cpu_var(zcache_preloads);
obj = kp->obj;
BUG_ON(obj == NULL);
kp->obj = NULL;
count = atomic_inc_return(&zcache_curr_obj_count);
if (count > zcache_curr_obj_count_max)
zcache_curr_obj_count_max = count;
return obj;
}
static void zcache_obj_free(struct tmem_obj *obj, struct tmem_pool *pool)
{
atomic_dec(&zcache_curr_obj_count);
BUG_ON(atomic_read(&zcache_curr_obj_count) < 0);
kmem_cache_free(zcache_obj_cache, obj);
}
static void *zcache_pampd_create(struct tmem_pool *pool, struct tmem_oid *oid,
uint32_t index, struct page *page)
{
void *pampd = NULL, *cdata;
size_t clen;
int ret;
bool ephemeral = is_ephemeral(pool);
unsigned long count;
if (ephemeral) {
ret = zcache_compress(page, &cdata, &clen);
if (ret == 0)
goto out;
if (clen == 0 || clen > zbud_max_buddy_size()) {
zcache_compress_poor++;
goto out;
}
pampd = (void *)zbud_create(pool->pool_id, oid, index,
page, cdata, clen);
if (pampd != NULL) {
count = atomic_inc_return(&zcache_curr_eph_pampd_count);
if (count > zcache_curr_eph_pampd_count_max)
zcache_curr_eph_pampd_count_max = count;
}
} else {
if (atomic_read(&zcache_curr_pers_pampd_count) >
3 * totalram_pages / 4)
goto out;
ret = zcache_compress(page, &cdata, &clen);
if (ret == 0)
goto out;
if (clen > zv_max_page_size) {
zcache_compress_poor++;
goto out;
}
pampd = (void *)zv_create(zcache_client.xvpool, pool->pool_id,
oid, index, cdata, clen);
if (pampd == NULL)
goto out;
count = atomic_inc_return(&zcache_curr_pers_pampd_count);
if (count > zcache_curr_pers_pampd_count_max)
zcache_curr_pers_pampd_count_max = count;
}
out:
return pampd;
}
static int zcache_pampd_get_data(struct page *page, void *pampd,
struct tmem_pool *pool)
{
int ret = 0;
if (is_ephemeral(pool))
ret = zbud_decompress(page, pampd);
else
zv_decompress(page, pampd);
return ret;
}
static void zcache_pampd_free(void *pampd, struct tmem_pool *pool)
{
if (is_ephemeral(pool)) {
zbud_free_and_delist((struct zbud_hdr *)pampd);
atomic_dec(&zcache_curr_eph_pampd_count);
BUG_ON(atomic_read(&zcache_curr_eph_pampd_count) < 0);
} else {
zv_free(zcache_client.xvpool, (struct zv_hdr *)pampd);
atomic_dec(&zcache_curr_pers_pampd_count);
BUG_ON(atomic_read(&zcache_curr_pers_pampd_count) < 0);
}
}
static int zcache_compress(struct page *from, void **out_va, size_t *out_len)
{
int ret = 0;
unsigned char *dmem = __get_cpu_var(zcache_dstmem);
unsigned char *wmem = __get_cpu_var(zcache_workmem);
char *from_va;
BUG_ON(!irqs_disabled());
if (unlikely(dmem == NULL || wmem == NULL))
goto out;
from_va = kmap_atomic(from, KM_USER0);
mb();
ret = lzo1x_1_compress(from_va, PAGE_SIZE, dmem, out_len, wmem);
BUG_ON(ret != LZO_E_OK);
*out_va = dmem;
kunmap_atomic(from_va, KM_USER0);
ret = 1;
out:
return ret;
}
static int zcache_cpu_notifier(struct notifier_block *nb,
unsigned long action, void *pcpu)
{
int cpu = (long)pcpu;
struct zcache_preload *kp;
switch (action) {
case CPU_UP_PREPARE:
per_cpu(zcache_dstmem, cpu) = (void *)__get_free_pages(
GFP_KERNEL | __GFP_REPEAT,
LZO_DSTMEM_PAGE_ORDER),
per_cpu(zcache_workmem, cpu) =
kzalloc(LZO1X_MEM_COMPRESS,
GFP_KERNEL | __GFP_REPEAT);
break;
case CPU_DEAD:
case CPU_UP_CANCELED:
free_pages((unsigned long)per_cpu(zcache_dstmem, cpu),
LZO_DSTMEM_PAGE_ORDER);
per_cpu(zcache_dstmem, cpu) = NULL;
kfree(per_cpu(zcache_workmem, cpu));
per_cpu(zcache_workmem, cpu) = NULL;
kp = &per_cpu(zcache_preloads, cpu);
while (kp->nr) {
kmem_cache_free(zcache_objnode_cache,
kp->objnodes[kp->nr - 1]);
kp->objnodes[kp->nr - 1] = NULL;
kp->nr--;
}
kmem_cache_free(zcache_obj_cache, kp->obj);
free_page((unsigned long)kp->page);
break;
default:
break;
}
return NOTIFY_OK;
}
static int shrink_zcache_memory(struct shrinker *shrink,
struct shrink_control *sc)
{
int ret = -1;
int nr = sc->nr_to_scan;
gfp_t gfp_mask = sc->gfp_mask;
if (nr >= 0) {
if (!(gfp_mask & __GFP_FS))
goto out;
if (spin_trylock(&zcache_direct_reclaim_lock)) {
zbud_evict_pages(nr);
spin_unlock(&zcache_direct_reclaim_lock);
} else
zcache_aborted_shrink++;
}
ret = (int)atomic_read(&zcache_zbud_curr_raw_pages);
out:
return ret;
}
static int zcache_put_page(int pool_id, struct tmem_oid *oidp,
uint32_t index, struct page *page)
{
struct tmem_pool *pool;
int ret = -1;
BUG_ON(!irqs_disabled());
pool = zcache_get_pool_by_id(pool_id);
if (unlikely(pool == NULL))
goto out;
if (!zcache_freeze && zcache_do_preload(pool) == 0) {
ret = tmem_put(pool, oidp, index, page);
if (ret < 0) {
if (is_ephemeral(pool))
zcache_failed_eph_puts++;
else
zcache_failed_pers_puts++;
}
zcache_put_pool(pool);
preempt_enable_no_resched();
} else {
zcache_put_to_flush++;
if (atomic_read(&pool->obj_count) > 0)
(void)tmem_flush_page(pool, oidp, index);
zcache_put_pool(pool);
}
out:
return ret;
}
static int zcache_get_page(int pool_id, struct tmem_oid *oidp,
uint32_t index, struct page *page)
{
struct tmem_pool *pool;
int ret = -1;
unsigned long flags;
local_irq_save(flags);
pool = zcache_get_pool_by_id(pool_id);
if (likely(pool != NULL)) {
if (atomic_read(&pool->obj_count) > 0)
ret = tmem_get(pool, oidp, index, page);
zcache_put_pool(pool);
}
local_irq_restore(flags);
return ret;
}
static int zcache_flush_page(int pool_id, struct tmem_oid *oidp, uint32_t index)
{
struct tmem_pool *pool;
int ret = -1;
unsigned long flags;
local_irq_save(flags);
zcache_flush_total++;
pool = zcache_get_pool_by_id(pool_id);
if (likely(pool != NULL)) {
if (atomic_read(&pool->obj_count) > 0)
ret = tmem_flush_page(pool, oidp, index);
zcache_put_pool(pool);
}
if (ret >= 0)
zcache_flush_found++;
local_irq_restore(flags);
return ret;
}
static int zcache_flush_object(int pool_id, struct tmem_oid *oidp)
{
struct tmem_pool *pool;
int ret = -1;
unsigned long flags;
local_irq_save(flags);
zcache_flobj_total++;
pool = zcache_get_pool_by_id(pool_id);
if (likely(pool != NULL)) {
if (atomic_read(&pool->obj_count) > 0)
ret = tmem_flush_object(pool, oidp);
zcache_put_pool(pool);
}
if (ret >= 0)
zcache_flobj_found++;
local_irq_restore(flags);
return ret;
}
static int zcache_destroy_pool(int pool_id)
{
struct tmem_pool *pool = NULL;
int ret = -1;
if (pool_id < 0)
goto out;
pool = zcache_client.tmem_pools[pool_id];
if (pool == NULL)
goto out;
zcache_client.tmem_pools[pool_id] = NULL;
while (atomic_read(&pool->refcount) != 0)
;
local_bh_disable();
ret = tmem_destroy_pool(pool);
local_bh_enable();
kfree(pool);
pr_info("zcache: destroyed pool id=%d\n", pool_id);
out:
return ret;
}
static int zcache_new_pool(uint32_t flags)
{
int poolid = -1;
struct tmem_pool *pool;
pool = kmalloc(sizeof(struct tmem_pool), GFP_KERNEL);
if (pool == NULL) {
pr_info("zcache: pool creation failed: out of memory\n");
goto out;
}
for (poolid = 0; poolid < MAX_POOLS_PER_CLIENT; poolid++)
if (zcache_client.tmem_pools[poolid] == NULL)
break;
if (poolid >= MAX_POOLS_PER_CLIENT) {
pr_info("zcache: pool creation failed: max exceeded\n");
kfree(pool);
poolid = -1;
goto out;
}
atomic_set(&pool->refcount, 0);
pool->client = &zcache_client;
pool->pool_id = poolid;
tmem_new_pool(pool, flags);
zcache_client.tmem_pools[poolid] = pool;
pr_info("zcache: created %s tmem pool, id=%d\n",
flags & TMEM_POOL_PERSIST ? "persistent" : "ephemeral",
poolid);
out:
return poolid;
}
static void zcache_cleancache_put_page(int pool_id,
struct cleancache_filekey key,
pgoff_t index, struct page *page)
{
u32 ind = (u32) index;
struct tmem_oid oid = *(struct tmem_oid *)&key;
if (likely(ind == index))
(void)zcache_put_page(pool_id, &oid, index, page);
}
static int zcache_cleancache_get_page(int pool_id,
struct cleancache_filekey key,
pgoff_t index, struct page *page)
{
u32 ind = (u32) index;
struct tmem_oid oid = *(struct tmem_oid *)&key;
int ret = -1;
if (likely(ind == index))
ret = zcache_get_page(pool_id, &oid, index, page);
return ret;
}
static void zcache_cleancache_flush_page(int pool_id,
struct cleancache_filekey key,
pgoff_t index)
{
u32 ind = (u32) index;
struct tmem_oid oid = *(struct tmem_oid *)&key;
if (likely(ind == index))
(void)zcache_flush_page(pool_id, &oid, ind);
}
static void zcache_cleancache_flush_inode(int pool_id,
struct cleancache_filekey key)
{
struct tmem_oid oid = *(struct tmem_oid *)&key;
(void)zcache_flush_object(pool_id, &oid);
}
static void zcache_cleancache_flush_fs(int pool_id)
{
if (pool_id >= 0)
(void)zcache_destroy_pool(pool_id);
}
static int zcache_cleancache_init_fs(size_t pagesize)
{
BUG_ON(sizeof(struct cleancache_filekey) !=
sizeof(struct tmem_oid));
BUG_ON(pagesize != PAGE_SIZE);
return zcache_new_pool(0);
}
static int zcache_cleancache_init_shared_fs(char *uuid, size_t pagesize)
{
BUG_ON(sizeof(struct cleancache_filekey) !=
sizeof(struct tmem_oid));
BUG_ON(pagesize != PAGE_SIZE);
return zcache_new_pool(0);
}
struct cleancache_ops zcache_cleancache_register_ops(void)
{
struct cleancache_ops old_ops =
cleancache_register_ops(&zcache_cleancache_ops);
return old_ops;
}
static inline struct tmem_oid oswiz(unsigned type, u32 ind)
{
struct tmem_oid oid = { .oid = { 0 } };
oid.oid[0] = _oswiz(type, ind);
return oid;
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
if (likely(ind64 == ind)) {
local_irq_save(flags);
ret = zcache_put_page(zcache_frontswap_poolid, &oid,
iswiz(ind), page);
local_irq_restore(flags);
}
return ret;
}
static int zcache_frontswap_get_page(unsigned type, pgoff_t offset,
struct page *page)
{
u64 ind64 = (u64)offset;
u32 ind = (u32)offset;
struct tmem_oid oid = oswiz(type, ind);
int ret = -1;
BUG_ON(!PageLocked(page));
if (likely(ind64 == ind))
ret = zcache_get_page(zcache_frontswap_poolid, &oid,
iswiz(ind), page);
return ret;
}
static void zcache_frontswap_flush_page(unsigned type, pgoff_t offset)
{
u64 ind64 = (u64)offset;
u32 ind = (u32)offset;
struct tmem_oid oid = oswiz(type, ind);
if (likely(ind64 == ind))
(void)zcache_flush_page(zcache_frontswap_poolid, &oid,
iswiz(ind));
}
static void zcache_frontswap_flush_area(unsigned type)
{
struct tmem_oid oid;
int ind;
for (ind = SWIZ_MASK; ind >= 0; ind--) {
oid = oswiz(type, ind);
(void)zcache_flush_object(zcache_frontswap_poolid, &oid);
}
}
static void zcache_frontswap_init(unsigned ignored)
{
if (zcache_frontswap_poolid < 0)
zcache_frontswap_poolid = zcache_new_pool(TMEM_POOL_PERSIST);
}
struct frontswap_ops zcache_frontswap_register_ops(void)
{
struct frontswap_ops old_ops =
frontswap_register_ops(&zcache_frontswap_ops);
return old_ops;
}
static int __init enable_zcache(char *s)
{
zcache_enabled = 1;
return 1;
}
static int __init no_cleancache(char *s)
{
use_cleancache = 0;
return 1;
}
static int __init no_frontswap(char *s)
{
use_frontswap = 0;
return 1;
}
static int __init zcache_init(void)
{
#ifdef CONFIG_SYSFS
int ret = 0;
ret = sysfs_create_group(mm_kobj, &zcache_attr_group);
if (ret) {
pr_err("zcache: can't create sysfs\n");
goto out;
}
#endif
#if defined(CONFIG_CLEANCACHE) || defined(CONFIG_FRONTSWAP)
if (zcache_enabled) {
unsigned int cpu;
tmem_register_hostops(&zcache_hostops);
tmem_register_pamops(&zcache_pamops);
ret = register_cpu_notifier(&zcache_cpu_notifier_block);
if (ret) {
pr_err("zcache: can't register cpu notifier\n");
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
#endif
#ifdef CONFIG_CLEANCACHE
if (zcache_enabled && use_cleancache) {
struct cleancache_ops old_ops;
zbud_init();
register_shrinker(&zcache_shrinker);
old_ops = zcache_cleancache_register_ops();
pr_info("zcache: cleancache enabled using kernel "
"transcendent memory and compression buddies\n");
if (old_ops.init_fs != NULL)
pr_warning("zcache: cleancache_ops overridden");
}
#endif
#ifdef CONFIG_FRONTSWAP
if (zcache_enabled && use_frontswap) {
struct frontswap_ops old_ops;
zcache_client.xvpool = xv_create_pool();
if (zcache_client.xvpool == NULL) {
pr_err("zcache: can't create xvpool\n");
goto out;
}
old_ops = zcache_frontswap_register_ops();
pr_info("zcache: frontswap enabled using kernel "
"transcendent memory and xvmalloc\n");
if (old_ops.init != NULL)
pr_warning("ktmem: frontswap_ops overridden");
}
#endif
out:
return ret;
}
