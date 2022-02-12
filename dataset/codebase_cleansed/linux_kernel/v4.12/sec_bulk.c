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
"max wait time: %ld/%lu\n"
"out of mem: %lu\n",
totalram_pages,
PAGES_PER_POOL,
page_pools.epp_max_pages,
page_pools.epp_max_pools,
page_pools.epp_total_pages,
page_pools.epp_free_pages,
page_pools.epp_idle_idx,
(long)(ktime_get_seconds() - page_pools.epp_last_shrink),
(long)(ktime_get_seconds() - page_pools.epp_last_access),
page_pools.epp_st_max_pages,
page_pools.epp_st_grows,
page_pools.epp_st_grow_fails,
page_pools.epp_st_shrinks,
page_pools.epp_st_access,
page_pools.epp_st_missings,
page_pools.epp_st_lowfree,
page_pools.epp_st_max_wqlen,
page_pools.epp_st_max_wait,
msecs_to_jiffies(MSEC_PER_SEC),
page_pools.epp_st_outofmem);
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
LASSERT(page_pools.epp_pools[p_idx][g_idx]);
__free_page(page_pools.epp_pools[p_idx][g_idx]);
page_pools.epp_pools[p_idx][g_idx] = NULL;
if (++g_idx == PAGES_PER_POOL) {
p_idx++;
g_idx = 0;
}
}
while (p_idx_max1 < p_idx_max2) {
LASSERT(page_pools.epp_pools[p_idx_max2]);
kfree(page_pools.epp_pools[p_idx_max2]);
page_pools.epp_pools[p_idx_max2] = NULL;
p_idx_max2--;
}
}
static unsigned long enc_pools_shrink_count(struct shrinker *s,
struct shrink_control *sc)
{
if (unlikely(ktime_get_seconds() - page_pools.epp_last_access >
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
page_pools.epp_last_shrink = ktime_get_seconds();
}
spin_unlock(&page_pools.epp_lock);
if (unlikely(ktime_get_seconds() - page_pools.epp_last_access >
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
return (int)DIV_ROUND_UP(npages, PAGES_PER_POOL);
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
kfree(pools[i]);
pools[i] = NULL;
}
}
return cleaned;
}
static inline void enc_pools_wakeup(void)
{
assert_spin_locked(&page_pools.epp_lock);
if (unlikely(page_pools.epp_waitqlen)) {
LASSERT(waitqueue_active(&page_pools.epp_waitq));
wake_up_all(&page_pools.epp_waitq);
}
}
int get_free_pages_in_pool(void)
{
return page_pools.epp_free_pages;
}
int pool_is_at_full_capacity(void)
{
return (page_pools.epp_total_pages == page_pools.epp_max_pages);
}
void sptlrpc_enc_pool_put_pages(struct ptlrpc_bulk_desc *desc)
{
int p_idx, g_idx;
int i;
LASSERT(ptlrpc_is_bulk_desc_kiov(desc->bd_type));
if (!GET_ENC_KIOV(desc))
return;
LASSERT(desc->bd_iov_count > 0);
spin_lock(&page_pools.epp_lock);
p_idx = page_pools.epp_free_pages / PAGES_PER_POOL;
g_idx = page_pools.epp_free_pages % PAGES_PER_POOL;
LASSERT(page_pools.epp_free_pages + desc->bd_iov_count <=
page_pools.epp_total_pages);
LASSERT(page_pools.epp_pools[p_idx]);
for (i = 0; i < desc->bd_iov_count; i++) {
LASSERT(BD_GET_ENC_KIOV(desc, i).bv_page);
LASSERT(g_idx != 0 || page_pools.epp_pools[p_idx]);
LASSERT(!page_pools.epp_pools[p_idx][g_idx]);
page_pools.epp_pools[p_idx][g_idx] =
BD_GET_ENC_KIOV(desc, i).bv_page;
if (++g_idx == PAGES_PER_POOL) {
p_idx++;
g_idx = 0;
}
}
page_pools.epp_free_pages += desc->bd_iov_count;
enc_pools_wakeup();
spin_unlock(&page_pools.epp_lock);
kfree(GET_ENC_KIOV(desc));
GET_ENC_KIOV(desc) = NULL;
}
static inline void enc_pools_alloc(void)
{
LASSERT(page_pools.epp_max_pools);
page_pools.epp_pools =
libcfs_kvzalloc(page_pools.epp_max_pools *
sizeof(*page_pools.epp_pools),
GFP_NOFS);
}
static inline void enc_pools_free(void)
{
LASSERT(page_pools.epp_max_pools);
LASSERT(page_pools.epp_pools);
kvfree(page_pools.epp_pools);
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
page_pools.epp_last_shrink = ktime_get_seconds();
page_pools.epp_last_access = ktime_get_seconds();
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
page_pools.epp_st_outofmem = 0;
enc_pools_alloc();
if (!page_pools.epp_pools)
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
"max pages %lu, grows %u, grow fails %u, shrinks %u, access %lu, missing %lu, max qlen %u, max wait %ld/%ld, out of mem %lu\n",
page_pools.epp_st_max_pages, page_pools.epp_st_grows,
page_pools.epp_st_grow_fails,
page_pools.epp_st_shrinks, page_pools.epp_st_access,
page_pools.epp_st_missings, page_pools.epp_st_max_wqlen,
page_pools.epp_st_max_wait,
msecs_to_jiffies(MSEC_PER_SEC),
page_pools.epp_st_outofmem);
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
if (!bsd) {
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
cfs_crypto_hash_update_page(hdesc,
BD_GET_KIOV(desc, i).bv_page,
BD_GET_KIOV(desc, i).bv_offset &
~PAGE_MASK,
BD_GET_KIOV(desc, i).bv_len);
}
if (hashsize > buflen) {
unsigned char hashbuf[CFS_CRYPTO_HASH_DIGESTSIZE_MAX];
bufsize = sizeof(hashbuf);
LASSERTF(bufsize >= hashsize, "bufsize = %u < hashsize %u\n",
bufsize, hashsize);
err = cfs_crypto_hash_final(hdesc, hashbuf, &bufsize);
memcpy(buf, hashbuf, buflen);
} else {
bufsize = buflen;
err = cfs_crypto_hash_final(hdesc, buf, &bufsize);
}
return err;
}
