int sptlrpc_proc_enc_pool_seq_show(struct seq_file *m, void *v)
{
spin_lock(&page_pools.epp_lock);
seq_printf(m,
"physical pages: %lu\n"
"pages per pool: %lu\n"
"max pages: %lu\n"
"max pools: %u\n"
"total pages: %lu\n"
"total free: %lu\n"
"idle index: %lu/100\n"
"last shrink: %lds\n"
"last access: %lds\n"
"max pages reached: %lu\n"
"grows: %u\n"
"grows failure: %u\n"
"shrinks: %u\n"
"cache access: %lu\n"
"cache missing: %lu\n"
"low free mark: %lu\n"
"max waitqueue depth: %u\n"
"max wait time: " CFS_TIME_T "/%u\n",
totalram_pages,
PAGES_PER_POOL,
page_pools.epp_max_pages,
page_pools.epp_max_pools,
page_pools.epp_total_pages,
page_pools.epp_free_pages,
page_pools.epp_idle_idx,
get_seconds() - page_pools.epp_last_shrink,
get_seconds() - page_pools.epp_last_access,
page_pools.epp_st_max_pages,
page_pools.epp_st_grows,
page_pools.epp_st_grow_fails,
page_pools.epp_st_shrinks,
page_pools.epp_st_access,
page_pools.epp_st_missings,
page_pools.epp_st_lowfree,
page_pools.epp_st_max_wqlen,
page_pools.epp_st_max_wait,
HZ);
spin_unlock(&page_pools.epp_lock);
return 0;
}
static void enc_pools_release_free_pages(long npages)
{
int p_idx, g_idx;
int p_idx_max1, p_idx_max2;
LASSERT(npages > 0);
LASSERT(npages <= page_pools.epp_free_pages);
LASSERT(page_pools.epp_free_pages <= page_pools.epp_total_pages);
p_idx_max2 = (page_pools.epp_total_pages - 1) / PAGES_PER_POOL;
page_pools.epp_free_pages -= npages;
page_pools.epp_total_pages -= npages;
p_idx_max1 = page_pools.epp_total_pages == 0 ? -1 :
((page_pools.epp_total_pages - 1) / PAGES_PER_POOL);
p_idx = page_pools.epp_free_pages / PAGES_PER_POOL;
g_idx = page_pools.epp_free_pages % PAGES_PER_POOL;
LASSERT(page_pools.epp_pools[p_idx]);
while (npages--) {
LASSERT(page_pools.epp_pools[p_idx]);
LASSERT(page_pools.epp_pools[p_idx][g_idx] != NULL);
__free_page(page_pools.epp_pools[p_idx][g_idx]);
page_pools.epp_pools[p_idx][g_idx] = NULL;
if (++g_idx == PAGES_PER_POOL) {
p_idx++;
g_idx = 0;
}
}
while (p_idx_max1 < p_idx_max2) {
LASSERT(page_pools.epp_pools[p_idx_max2]);
OBD_FREE(page_pools.epp_pools[p_idx_max2], PAGE_CACHE_SIZE);
page_pools.epp_pools[p_idx_max2] = NULL;
p_idx_max2--;
}
}
static unsigned long enc_pools_shrink_count(struct shrinker *s,
struct shrink_control *sc)
{
if (unlikely(get_seconds() - page_pools.epp_last_access >
CACHE_QUIESCENT_PERIOD)) {
spin_lock(&page_pools.epp_lock);
page_pools.epp_idle_idx = IDLE_IDX_MAX;
spin_unlock(&page_pools.epp_lock);
}
LASSERT(page_pools.epp_idle_idx <= IDLE_IDX_MAX);
return max((int)page_pools.epp_free_pages - PTLRPC_MAX_BRW_PAGES, 0) *
(IDLE_IDX_MAX - page_pools.epp_idle_idx) / IDLE_IDX_MAX;
}
static unsigned long enc_pools_shrink_scan(struct shrinker *s,
struct shrink_control *sc)
{
spin_lock(&page_pools.epp_lock);
sc->nr_to_scan = min_t(unsigned long, sc->nr_to_scan,
page_pools.epp_free_pages - PTLRPC_MAX_BRW_PAGES);
if (sc->nr_to_scan > 0) {
enc_pools_release_free_pages(sc->nr_to_scan);
CDEBUG(D_SEC, "released %ld pages, %ld left\n",
(long)sc->nr_to_scan, page_pools.epp_free_pages);
page_pools.epp_st_shrinks++;
page_pools.epp_last_shrink = get_seconds();
}
spin_unlock(&page_pools.epp_lock);
if (unlikely(get_seconds() - page_pools.epp_last_access >
CACHE_QUIESCENT_PERIOD)) {
spin_lock(&page_pools.epp_lock);
page_pools.epp_idle_idx = IDLE_IDX_MAX;
spin_unlock(&page_pools.epp_lock);
}
LASSERT(page_pools.epp_idle_idx <= IDLE_IDX_MAX);
return sc->nr_to_scan;
}
static inline
int npages_to_npools(unsigned long npages)
{
return (int) ((npages + PAGES_PER_POOL - 1) / PAGES_PER_POOL);
}
static unsigned long enc_pools_cleanup(struct page ***pools, int npools)
{
unsigned long cleaned = 0;
int i, j;
for (i = 0; i < npools; i++) {
if (pools[i]) {
for (j = 0; j < PAGES_PER_POOL; j++) {
if (pools[i][j]) {
__free_page(pools[i][j]);
cleaned++;
}
}
OBD_FREE(pools[i], PAGE_CACHE_SIZE);
pools[i] = NULL;
}
}
return cleaned;
}
static void enc_pools_insert(struct page ***pools, int npools, int npages)
{
int freeslot;
int op_idx, np_idx, og_idx, ng_idx;
int cur_npools, end_npools;
LASSERT(npages > 0);
LASSERT(page_pools.epp_total_pages+npages <= page_pools.epp_max_pages);
LASSERT(npages_to_npools(npages) == npools);
LASSERT(page_pools.epp_growing);
spin_lock(&page_pools.epp_lock);
freeslot = page_pools.epp_total_pages % PAGES_PER_POOL;
if (freeslot != 0)
freeslot = PAGES_PER_POOL - freeslot;
freeslot += page_pools.epp_total_pages - page_pools.epp_free_pages;
op_idx = page_pools.epp_free_pages / PAGES_PER_POOL;
og_idx = page_pools.epp_free_pages % PAGES_PER_POOL;
np_idx = npools - 1;
ng_idx = (npages - 1) % PAGES_PER_POOL;
while (freeslot) {
LASSERT(page_pools.epp_pools[op_idx][og_idx] == NULL);
LASSERT(pools[np_idx][ng_idx] != NULL);
page_pools.epp_pools[op_idx][og_idx] = pools[np_idx][ng_idx];
pools[np_idx][ng_idx] = NULL;
freeslot--;
if (++og_idx == PAGES_PER_POOL) {
op_idx++;
og_idx = 0;
}
if (--ng_idx < 0) {
if (np_idx == 0)
break;
np_idx--;
ng_idx = PAGES_PER_POOL - 1;
}
}
cur_npools = (page_pools.epp_total_pages + PAGES_PER_POOL - 1) /
PAGES_PER_POOL;
end_npools = (page_pools.epp_total_pages + npages + PAGES_PER_POOL - 1)
/ PAGES_PER_POOL;
LASSERT(end_npools <= page_pools.epp_max_pools);
np_idx = 0;
while (cur_npools < end_npools) {
LASSERT(page_pools.epp_pools[cur_npools] == NULL);
LASSERT(np_idx < npools);
LASSERT(pools[np_idx] != NULL);
page_pools.epp_pools[cur_npools++] = pools[np_idx];
pools[np_idx++] = NULL;
}
page_pools.epp_total_pages += npages;
page_pools.epp_free_pages += npages;
page_pools.epp_st_lowfree = page_pools.epp_free_pages;
if (page_pools.epp_total_pages > page_pools.epp_st_max_pages)
page_pools.epp_st_max_pages = page_pools.epp_total_pages;
CDEBUG(D_SEC, "add %d pages to total %lu\n", npages,
page_pools.epp_total_pages);
spin_unlock(&page_pools.epp_lock);
}
static int enc_pools_add_pages(int npages)
{
static DEFINE_MUTEX(add_pages_mutex);
struct page ***pools;
int npools, alloced = 0;
int i, j, rc = -ENOMEM;
if (npages < PTLRPC_MAX_BRW_PAGES)
npages = PTLRPC_MAX_BRW_PAGES;
mutex_lock(&add_pages_mutex);
if (npages + page_pools.epp_total_pages > page_pools.epp_max_pages)
npages = page_pools.epp_max_pages - page_pools.epp_total_pages;
LASSERT(npages > 0);
page_pools.epp_st_grows++;
npools = npages_to_npools(npages);
OBD_ALLOC(pools, npools * sizeof(*pools));
if (pools == NULL)
goto out;
for (i = 0; i < npools; i++) {
OBD_ALLOC(pools[i], PAGE_CACHE_SIZE);
if (pools[i] == NULL)
goto out_pools;
for (j = 0; j < PAGES_PER_POOL && alloced < npages; j++) {
pools[i][j] = alloc_page(GFP_NOFS |
__GFP_HIGHMEM);
if (pools[i][j] == NULL)
goto out_pools;
alloced++;
}
}
LASSERT(alloced == npages);
enc_pools_insert(pools, npools, npages);
CDEBUG(D_SEC, "added %d pages into pools\n", npages);
rc = 0;
out_pools:
enc_pools_cleanup(pools, npools);
OBD_FREE(pools, npools * sizeof(*pools));
out:
if (rc) {
page_pools.epp_st_grow_fails++;
CERROR("Failed to allocate %d enc pages\n", npages);
}
mutex_unlock(&add_pages_mutex);
return rc;
}
static inline void enc_pools_wakeup(void)
{
assert_spin_locked(&page_pools.epp_lock);
LASSERT(page_pools.epp_waitqlen >= 0);
if (unlikely(page_pools.epp_waitqlen)) {
LASSERT(waitqueue_active(&page_pools.epp_waitq));
wake_up_all(&page_pools.epp_waitq);
}
}
static int enc_pools_should_grow(int page_needed, long now)
{
if (page_pools.epp_growing ||
page_pools.epp_total_pages == page_pools.epp_max_pages)
return 0;
if (page_pools.epp_total_pages < page_needed)
return 1;
#if 0
if (now - page_pools.epp_last_shrink < 2)
return 0;
#endif
return 1;
}
int sptlrpc_enc_pool_get_pages(struct ptlrpc_bulk_desc *desc)
{
wait_queue_t waitlink;
unsigned long this_idle = -1;
unsigned long tick = 0;
long now;
int p_idx, g_idx;
int i;
LASSERT(desc->bd_iov_count > 0);
LASSERT(desc->bd_iov_count <= page_pools.epp_max_pages);
if (desc->bd_enc_iov != NULL)
return 0;
OBD_ALLOC(desc->bd_enc_iov,
desc->bd_iov_count * sizeof(*desc->bd_enc_iov));
if (desc->bd_enc_iov == NULL)
return -ENOMEM;
spin_lock(&page_pools.epp_lock);
page_pools.epp_st_access++;
again:
if (unlikely(page_pools.epp_free_pages < desc->bd_iov_count)) {
if (tick == 0)
tick = cfs_time_current();
now = get_seconds();
page_pools.epp_st_missings++;
page_pools.epp_pages_short += desc->bd_iov_count;
if (enc_pools_should_grow(desc->bd_iov_count, now)) {
page_pools.epp_growing = 1;
spin_unlock(&page_pools.epp_lock);
enc_pools_add_pages(page_pools.epp_pages_short / 2);
spin_lock(&page_pools.epp_lock);
page_pools.epp_growing = 0;
enc_pools_wakeup();
} else {
if (++page_pools.epp_waitqlen >
page_pools.epp_st_max_wqlen)
page_pools.epp_st_max_wqlen =
page_pools.epp_waitqlen;
set_current_state(TASK_UNINTERRUPTIBLE);
init_waitqueue_entry(&waitlink, current);
add_wait_queue(&page_pools.epp_waitq, &waitlink);
spin_unlock(&page_pools.epp_lock);
schedule();
remove_wait_queue(&page_pools.epp_waitq, &waitlink);
LASSERT(page_pools.epp_waitqlen > 0);
spin_lock(&page_pools.epp_lock);
page_pools.epp_waitqlen--;
}
LASSERT(page_pools.epp_pages_short >= desc->bd_iov_count);
page_pools.epp_pages_short -= desc->bd_iov_count;
this_idle = 0;
goto again;
}
if (unlikely(tick != 0)) {
tick = cfs_time_current() - tick;
if (tick > page_pools.epp_st_max_wait)
page_pools.epp_st_max_wait = tick;
}
page_pools.epp_free_pages -= desc->bd_iov_count;
p_idx = page_pools.epp_free_pages / PAGES_PER_POOL;
g_idx = page_pools.epp_free_pages % PAGES_PER_POOL;
for (i = 0; i < desc->bd_iov_count; i++) {
LASSERT(page_pools.epp_pools[p_idx][g_idx] != NULL);
desc->bd_enc_iov[i].kiov_page =
page_pools.epp_pools[p_idx][g_idx];
page_pools.epp_pools[p_idx][g_idx] = NULL;
if (++g_idx == PAGES_PER_POOL) {
p_idx++;
g_idx = 0;
}
}
if (page_pools.epp_free_pages < page_pools.epp_st_lowfree)
page_pools.epp_st_lowfree = page_pools.epp_free_pages;
if (this_idle == -1) {
this_idle = page_pools.epp_free_pages * IDLE_IDX_MAX /
page_pools.epp_total_pages;
}
page_pools.epp_idle_idx = (page_pools.epp_idle_idx * IDLE_IDX_WEIGHT +
this_idle) /
(IDLE_IDX_WEIGHT + 1);
page_pools.epp_last_access = get_seconds();
spin_unlock(&page_pools.epp_lock);
return 0;
}
void sptlrpc_enc_pool_put_pages(struct ptlrpc_bulk_desc *desc)
{
int p_idx, g_idx;
int i;
if (desc->bd_enc_iov == NULL)
return;
LASSERT(desc->bd_iov_count > 0);
spin_lock(&page_pools.epp_lock);
p_idx = page_pools.epp_free_pages / PAGES_PER_POOL;
g_idx = page_pools.epp_free_pages % PAGES_PER_POOL;
LASSERT(page_pools.epp_free_pages + desc->bd_iov_count <=
page_pools.epp_total_pages);
LASSERT(page_pools.epp_pools[p_idx]);
for (i = 0; i < desc->bd_iov_count; i++) {
LASSERT(desc->bd_enc_iov[i].kiov_page != NULL);
LASSERT(g_idx != 0 || page_pools.epp_pools[p_idx]);
LASSERT(page_pools.epp_pools[p_idx][g_idx] == NULL);
page_pools.epp_pools[p_idx][g_idx] =
desc->bd_enc_iov[i].kiov_page;
if (++g_idx == PAGES_PER_POOL) {
p_idx++;
g_idx = 0;
}
}
page_pools.epp_free_pages += desc->bd_iov_count;
enc_pools_wakeup();
spin_unlock(&page_pools.epp_lock);
OBD_FREE(desc->bd_enc_iov,
desc->bd_iov_count * sizeof(*desc->bd_enc_iov));
desc->bd_enc_iov = NULL;
}
int sptlrpc_enc_pool_add_user(void)
{
int need_grow = 0;
spin_lock(&page_pools.epp_lock);
if (page_pools.epp_growing == 0 && page_pools.epp_total_pages == 0) {
page_pools.epp_growing = 1;
need_grow = 1;
}
spin_unlock(&page_pools.epp_lock);
if (need_grow) {
enc_pools_add_pages(PTLRPC_MAX_BRW_PAGES +
PTLRPC_MAX_BRW_PAGES);
spin_lock(&page_pools.epp_lock);
page_pools.epp_growing = 0;
enc_pools_wakeup();
spin_unlock(&page_pools.epp_lock);
}
return 0;
}
int sptlrpc_enc_pool_del_user(void)
{
return 0;
}
static inline void enc_pools_alloc(void)
{
LASSERT(page_pools.epp_max_pools);
OBD_ALLOC_LARGE(page_pools.epp_pools,
page_pools.epp_max_pools *
sizeof(*page_pools.epp_pools));
}
static inline void enc_pools_free(void)
{
LASSERT(page_pools.epp_max_pools);
LASSERT(page_pools.epp_pools);
OBD_FREE_LARGE(page_pools.epp_pools,
page_pools.epp_max_pools *
sizeof(*page_pools.epp_pools));
}
int sptlrpc_enc_pool_init(void)
{
page_pools.epp_max_pages = totalram_pages / 8;
page_pools.epp_max_pools = npages_to_npools(page_pools.epp_max_pages);
init_waitqueue_head(&page_pools.epp_waitq);
page_pools.epp_waitqlen = 0;
page_pools.epp_pages_short = 0;
page_pools.epp_growing = 0;
page_pools.epp_idle_idx = 0;
page_pools.epp_last_shrink = get_seconds();
page_pools.epp_last_access = get_seconds();
spin_lock_init(&page_pools.epp_lock);
page_pools.epp_total_pages = 0;
page_pools.epp_free_pages = 0;
page_pools.epp_st_max_pages = 0;
page_pools.epp_st_grows = 0;
page_pools.epp_st_grow_fails = 0;
page_pools.epp_st_shrinks = 0;
page_pools.epp_st_access = 0;
page_pools.epp_st_missings = 0;
page_pools.epp_st_lowfree = 0;
page_pools.epp_st_max_wqlen = 0;
page_pools.epp_st_max_wait = 0;
enc_pools_alloc();
if (page_pools.epp_pools == NULL)
return -ENOMEM;
register_shrinker(&pools_shrinker);
return 0;
}
void sptlrpc_enc_pool_fini(void)
{
unsigned long cleaned, npools;
LASSERT(page_pools.epp_pools);
LASSERT(page_pools.epp_total_pages == page_pools.epp_free_pages);
unregister_shrinker(&pools_shrinker);
npools = npages_to_npools(page_pools.epp_total_pages);
cleaned = enc_pools_cleanup(page_pools.epp_pools, npools);
LASSERT(cleaned == page_pools.epp_total_pages);
enc_pools_free();
if (page_pools.epp_st_access > 0) {
CDEBUG(D_SEC,
"max pages %lu, grows %u, grow fails %u, shrinks %u, access %lu, missing %lu, max qlen %u, max wait "
CFS_TIME_T"/%d\n",
page_pools.epp_st_max_pages, page_pools.epp_st_grows,
page_pools.epp_st_grow_fails,
page_pools.epp_st_shrinks, page_pools.epp_st_access,
page_pools.epp_st_missings, page_pools.epp_st_max_wqlen,
page_pools.epp_st_max_wait, HZ);
}
}
const char *sptlrpc_get_hash_name(__u8 hash_alg)
{
return cfs_crypto_hash_name(cfs_hash_alg_id[hash_alg]);
}
__u8 sptlrpc_get_hash_alg(const char *algname)
{
return cfs_crypto_hash_alg(algname);
}
int bulk_sec_desc_unpack(struct lustre_msg *msg, int offset, int swabbed)
{
struct ptlrpc_bulk_sec_desc *bsd;
int size = msg->lm_buflens[offset];
bsd = lustre_msg_buf(msg, offset, sizeof(*bsd));
if (bsd == NULL) {
CERROR("Invalid bulk sec desc: size %d\n", size);
return -EINVAL;
}
if (swabbed)
__swab32s(&bsd->bsd_nob);
if (unlikely(bsd->bsd_version != 0)) {
CERROR("Unexpected version %u\n", bsd->bsd_version);
return -EPROTO;
}
if (unlikely(bsd->bsd_type >= SPTLRPC_BULK_MAX)) {
CERROR("Invalid type %u\n", bsd->bsd_type);
return -EPROTO;
}
if (unlikely(bsd->bsd_svc != SPTLRPC_BULK_SVC_NULL &&
bsd->bsd_svc != SPTLRPC_BULK_SVC_INTG &&
bsd->bsd_svc != SPTLRPC_BULK_SVC_PRIV)) {
CERROR("Invalid svc %u\n", bsd->bsd_svc);
return -EPROTO;
}
return 0;
}
int sptlrpc_get_bulk_checksum(struct ptlrpc_bulk_desc *desc, __u8 alg,
void *buf, int buflen)
{
struct cfs_crypto_hash_desc *hdesc;
int hashsize;
char hashbuf[64];
unsigned int bufsize;
int i, err;
LASSERT(alg > BULK_HASH_ALG_NULL && alg < BULK_HASH_ALG_MAX);
LASSERT(buflen >= 4);
hdesc = cfs_crypto_hash_init(cfs_hash_alg_id[alg], NULL, 0);
if (IS_ERR(hdesc)) {
CERROR("Unable to initialize checksum hash %s\n",
cfs_crypto_hash_name(cfs_hash_alg_id[alg]));
return PTR_ERR(hdesc);
}
hashsize = cfs_crypto_hash_digestsize(cfs_hash_alg_id[alg]);
for (i = 0; i < desc->bd_iov_count; i++) {
cfs_crypto_hash_update_page(hdesc, desc->bd_iov[i].kiov_page,
desc->bd_iov[i].kiov_offset & ~CFS_PAGE_MASK,
desc->bd_iov[i].kiov_len);
}
if (hashsize > buflen) {
bufsize = sizeof(hashbuf);
err = cfs_crypto_hash_final(hdesc, (unsigned char *)hashbuf,
&bufsize);
memcpy(buf, hashbuf, buflen);
} else {
bufsize = buflen;
err = cfs_crypto_hash_final(hdesc, (unsigned char *)buf,
&bufsize);
}
if (err)
cfs_crypto_hash_final(hdesc, NULL, NULL);
return err;
}
