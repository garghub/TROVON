static inline u32 request_hash(u32 xid)
{
u32 h = xid;
h ^= (xid >> 24);
return h & (HASHSIZE-1);
}
static unsigned int
nfsd_cache_size_limit(void)
{
unsigned int limit;
unsigned long low_pages = totalram_pages - totalhigh_pages;
limit = (16 * int_sqrt(low_pages)) << (PAGE_SHIFT-10);
return min_t(unsigned int, limit, 256*1024);
}
static struct svc_cacherep *
nfsd_reply_cache_alloc(void)
{
struct svc_cacherep *rp;
rp = kmem_cache_alloc(drc_slab, GFP_KERNEL);
if (rp) {
rp->c_state = RC_UNUSED;
rp->c_type = RC_NOCACHE;
INIT_LIST_HEAD(&rp->c_lru);
INIT_HLIST_NODE(&rp->c_hash);
}
return rp;
}
static void
nfsd_reply_cache_free_locked(struct svc_cacherep *rp)
{
if (rp->c_type == RC_REPLBUFF)
kfree(rp->c_replvec.iov_base);
if (!hlist_unhashed(&rp->c_hash))
hlist_del(&rp->c_hash);
list_del(&rp->c_lru);
--num_drc_entries;
kmem_cache_free(drc_slab, rp);
}
static void
nfsd_reply_cache_free(struct svc_cacherep *rp)
{
spin_lock(&cache_lock);
nfsd_reply_cache_free_locked(rp);
spin_unlock(&cache_lock);
}
int nfsd_reply_cache_init(void)
{
INIT_LIST_HEAD(&lru_head);
max_drc_entries = nfsd_cache_size_limit();
num_drc_entries = 0;
register_shrinker(&nfsd_reply_cache_shrinker);
drc_slab = kmem_cache_create("nfsd_drc", sizeof(struct svc_cacherep),
0, 0, NULL);
if (!drc_slab)
goto out_nomem;
cache_hash = kcalloc(HASHSIZE, sizeof(struct hlist_head), GFP_KERNEL);
if (!cache_hash)
goto out_nomem;
return 0;
out_nomem:
printk(KERN_ERR "nfsd: failed to allocate reply cache\n");
nfsd_reply_cache_shutdown();
return -ENOMEM;
}
void nfsd_reply_cache_shutdown(void)
{
struct svc_cacherep *rp;
unregister_shrinker(&nfsd_reply_cache_shrinker);
cancel_delayed_work_sync(&cache_cleaner);
while (!list_empty(&lru_head)) {
rp = list_entry(lru_head.next, struct svc_cacherep, c_lru);
nfsd_reply_cache_free_locked(rp);
}
kfree (cache_hash);
cache_hash = NULL;
if (drc_slab) {
kmem_cache_destroy(drc_slab);
drc_slab = NULL;
}
}
static void
lru_put_end(struct svc_cacherep *rp)
{
rp->c_timestamp = jiffies;
list_move_tail(&rp->c_lru, &lru_head);
schedule_delayed_work(&cache_cleaner, RC_EXPIRE);
}
static void
hash_refile(struct svc_cacherep *rp)
{
hlist_del_init(&rp->c_hash);
hlist_add_head(&rp->c_hash, cache_hash + request_hash(rp->c_xid));
}
static inline bool
nfsd_cache_entry_expired(struct svc_cacherep *rp)
{
return rp->c_state != RC_INPROG &&
time_after(jiffies, rp->c_timestamp + RC_EXPIRE);
}
static void
prune_cache_entries(void)
{
struct svc_cacherep *rp, *tmp;
list_for_each_entry_safe(rp, tmp, &lru_head, c_lru) {
if (!nfsd_cache_entry_expired(rp) &&
num_drc_entries <= max_drc_entries)
break;
nfsd_reply_cache_free_locked(rp);
}
if (list_empty(&lru_head))
cancel_delayed_work(&cache_cleaner);
else
mod_delayed_work(system_wq, &cache_cleaner, RC_EXPIRE);
}
static void
cache_cleaner_func(struct work_struct *unused)
{
spin_lock(&cache_lock);
prune_cache_entries();
spin_unlock(&cache_lock);
}
static int
nfsd_reply_cache_shrink(struct shrinker *shrink, struct shrink_control *sc)
{
unsigned int num;
spin_lock(&cache_lock);
if (sc->nr_to_scan)
prune_cache_entries();
num = num_drc_entries;
spin_unlock(&cache_lock);
return num;
}
static __wsum
nfsd_cache_csum(struct svc_rqst *rqstp)
{
int idx;
unsigned int base;
__wsum csum;
struct xdr_buf *buf = &rqstp->rq_arg;
const unsigned char *p = buf->head[0].iov_base;
size_t csum_len = min_t(size_t, buf->head[0].iov_len + buf->page_len,
RC_CSUMLEN);
size_t len = min(buf->head[0].iov_len, csum_len);
csum = csum_partial(p, len, 0);
csum_len -= len;
idx = buf->page_base / PAGE_SIZE;
base = buf->page_base & ~PAGE_MASK;
while (csum_len) {
p = page_address(buf->pages[idx]) + base;
len = min_t(size_t, PAGE_SIZE - base, csum_len);
csum = csum_partial(p, len, csum);
csum_len -= len;
base = 0;
++idx;
}
return csum;
}
static struct svc_cacherep *
nfsd_cache_search(struct svc_rqst *rqstp, __wsum csum)
{
struct svc_cacherep *rp;
struct hlist_head *rh;
__be32 xid = rqstp->rq_xid;
u32 proto = rqstp->rq_prot,
vers = rqstp->rq_vers,
proc = rqstp->rq_proc;
rh = &cache_hash[request_hash(xid)];
hlist_for_each_entry(rp, rh, c_hash) {
if (xid == rp->c_xid && proc == rp->c_proc &&
proto == rp->c_prot && vers == rp->c_vers &&
rqstp->rq_arg.len == rp->c_len && csum == rp->c_csum &&
rpc_cmp_addr(svc_addr(rqstp), (struct sockaddr *)&rp->c_addr) &&
rpc_get_port(svc_addr(rqstp)) == rpc_get_port((struct sockaddr *)&rp->c_addr))
return rp;
}
return NULL;
}
int
nfsd_cache_lookup(struct svc_rqst *rqstp)
{
struct svc_cacherep *rp, *found;
__be32 xid = rqstp->rq_xid;
u32 proto = rqstp->rq_prot,
vers = rqstp->rq_vers,
proc = rqstp->rq_proc;
__wsum csum;
unsigned long age;
int type = rqstp->rq_cachetype;
int rtn;
rqstp->rq_cacherep = NULL;
if (type == RC_NOCACHE) {
nfsdstats.rcnocache++;
return RC_DOIT;
}
csum = nfsd_cache_csum(rqstp);
spin_lock(&cache_lock);
rtn = RC_DOIT;
rp = nfsd_cache_search(rqstp, csum);
if (rp)
goto found_entry;
if (!list_empty(&lru_head)) {
rp = list_first_entry(&lru_head, struct svc_cacherep, c_lru);
if (nfsd_cache_entry_expired(rp) ||
num_drc_entries >= max_drc_entries) {
lru_put_end(rp);
prune_cache_entries();
goto setup_entry;
}
}
spin_unlock(&cache_lock);
rp = nfsd_reply_cache_alloc();
if (!rp) {
dprintk("nfsd: unable to allocate DRC entry!\n");
return RC_DOIT;
}
spin_lock(&cache_lock);
++num_drc_entries;
found = nfsd_cache_search(rqstp, csum);
if (found) {
nfsd_reply_cache_free_locked(rp);
rp = found;
goto found_entry;
}
if (num_drc_entries >= max_drc_entries)
nfsd_reply_cache_free_locked(list_first_entry(&lru_head,
struct svc_cacherep, c_lru));
setup_entry:
nfsdstats.rcmisses++;
rqstp->rq_cacherep = rp;
rp->c_state = RC_INPROG;
rp->c_xid = xid;
rp->c_proc = proc;
rpc_copy_addr((struct sockaddr *)&rp->c_addr, svc_addr(rqstp));
rpc_set_port((struct sockaddr *)&rp->c_addr, rpc_get_port(svc_addr(rqstp)));
rp->c_prot = proto;
rp->c_vers = vers;
rp->c_len = rqstp->rq_arg.len;
rp->c_csum = csum;
hash_refile(rp);
lru_put_end(rp);
if (rp->c_type == RC_REPLBUFF) {
kfree(rp->c_replvec.iov_base);
rp->c_replvec.iov_base = NULL;
}
rp->c_type = RC_NOCACHE;
out:
spin_unlock(&cache_lock);
return rtn;
found_entry:
nfsdstats.rchits++;
age = jiffies - rp->c_timestamp;
lru_put_end(rp);
rtn = RC_DROPIT;
if (rp->c_state == RC_INPROG || age < RC_DELAY)
goto out;
rtn = RC_DOIT;
if (!rqstp->rq_secure && rp->c_secure)
goto out;
switch (rp->c_type) {
case RC_NOCACHE:
break;
case RC_REPLSTAT:
svc_putu32(&rqstp->rq_res.head[0], rp->c_replstat);
rtn = RC_REPLY;
break;
case RC_REPLBUFF:
if (!nfsd_cache_append(rqstp, &rp->c_replvec))
goto out;
rtn = RC_REPLY;
break;
default:
printk(KERN_WARNING "nfsd: bad repcache type %d\n", rp->c_type);
nfsd_reply_cache_free_locked(rp);
}
goto out;
}
void
nfsd_cache_update(struct svc_rqst *rqstp, int cachetype, __be32 *statp)
{
struct svc_cacherep *rp = rqstp->rq_cacherep;
struct kvec *resv = &rqstp->rq_res.head[0], *cachv;
int len;
if (!rp)
return;
len = resv->iov_len - ((char*)statp - (char*)resv->iov_base);
len >>= 2;
if (!statp || len > (256 >> 2)) {
nfsd_reply_cache_free(rp);
return;
}
switch (cachetype) {
case RC_REPLSTAT:
if (len != 1)
printk("nfsd: RC_REPLSTAT/reply len %d!\n",len);
rp->c_replstat = *statp;
break;
case RC_REPLBUFF:
cachv = &rp->c_replvec;
cachv->iov_base = kmalloc(len << 2, GFP_KERNEL);
if (!cachv->iov_base) {
nfsd_reply_cache_free(rp);
return;
}
cachv->iov_len = len << 2;
memcpy(cachv->iov_base, statp, len << 2);
break;
case RC_NOCACHE:
nfsd_reply_cache_free(rp);
return;
}
spin_lock(&cache_lock);
lru_put_end(rp);
rp->c_secure = rqstp->rq_secure;
rp->c_type = cachetype;
rp->c_state = RC_DONE;
spin_unlock(&cache_lock);
return;
}
static int
nfsd_cache_append(struct svc_rqst *rqstp, struct kvec *data)
{
struct kvec *vec = &rqstp->rq_res.head[0];
if (vec->iov_len + data->iov_len > PAGE_SIZE) {
printk(KERN_WARNING "nfsd: cached reply too large (%Zd).\n",
data->iov_len);
return 0;
}
memcpy((char*)vec->iov_base + vec->iov_len, data->iov_base, data->iov_len);
vec->iov_len += data->iov_len;
return 1;
}
