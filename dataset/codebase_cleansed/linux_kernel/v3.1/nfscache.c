static inline u32 request_hash(u32 xid)
{
u32 h = xid;
h ^= (xid >> 24);
return h & (HASHSIZE-1);
}
int nfsd_reply_cache_init(void)
{
struct svc_cacherep *rp;
int i;
INIT_LIST_HEAD(&lru_head);
i = CACHESIZE;
while (i) {
rp = kmalloc(sizeof(*rp), GFP_KERNEL);
if (!rp)
goto out_nomem;
list_add(&rp->c_lru, &lru_head);
rp->c_state = RC_UNUSED;
rp->c_type = RC_NOCACHE;
INIT_HLIST_NODE(&rp->c_hash);
i--;
}
cache_hash = kcalloc (HASHSIZE, sizeof(struct hlist_head), GFP_KERNEL);
if (!cache_hash)
goto out_nomem;
cache_disabled = 0;
return 0;
out_nomem:
printk(KERN_ERR "nfsd: failed to allocate reply cache\n");
nfsd_reply_cache_shutdown();
return -ENOMEM;
}
void nfsd_reply_cache_shutdown(void)
{
struct svc_cacherep *rp;
while (!list_empty(&lru_head)) {
rp = list_entry(lru_head.next, struct svc_cacherep, c_lru);
if (rp->c_state == RC_DONE && rp->c_type == RC_REPLBUFF)
kfree(rp->c_replvec.iov_base);
list_del(&rp->c_lru);
kfree(rp);
}
cache_disabled = 1;
kfree (cache_hash);
cache_hash = NULL;
}
static void
lru_put_end(struct svc_cacherep *rp)
{
list_move_tail(&rp->c_lru, &lru_head);
}
static void
hash_refile(struct svc_cacherep *rp)
{
hlist_del_init(&rp->c_hash);
hlist_add_head(&rp->c_hash, cache_hash + request_hash(rp->c_xid));
}
int
nfsd_cache_lookup(struct svc_rqst *rqstp)
{
struct hlist_node *hn;
struct hlist_head *rh;
struct svc_cacherep *rp;
__be32 xid = rqstp->rq_xid;
u32 proto = rqstp->rq_prot,
vers = rqstp->rq_vers,
proc = rqstp->rq_proc;
unsigned long age;
int type = rqstp->rq_cachetype;
int rtn;
rqstp->rq_cacherep = NULL;
if (cache_disabled || type == RC_NOCACHE) {
nfsdstats.rcnocache++;
return RC_DOIT;
}
spin_lock(&cache_lock);
rtn = RC_DOIT;
rh = &cache_hash[request_hash(xid)];
hlist_for_each_entry(rp, hn, rh, c_hash) {
if (rp->c_state != RC_UNUSED &&
xid == rp->c_xid && proc == rp->c_proc &&
proto == rp->c_prot && vers == rp->c_vers &&
time_before(jiffies, rp->c_timestamp + 120*HZ) &&
memcmp((char*)&rqstp->rq_addr, (char*)&rp->c_addr, sizeof(rp->c_addr))==0) {
nfsdstats.rchits++;
goto found_entry;
}
}
nfsdstats.rcmisses++;
{
int safe = 0;
list_for_each_entry(rp, &lru_head, c_lru) {
if (rp->c_state != RC_INPROG)
break;
if (safe++ > CACHESIZE) {
printk("nfsd: loop in repcache LRU list\n");
cache_disabled = 1;
goto out;
}
}
}
if (&rp->c_lru == &lru_head) {
static int complaints;
printk(KERN_WARNING "nfsd: all repcache entries locked!\n");
if (++complaints > 5) {
printk(KERN_WARNING "nfsd: disabling repcache.\n");
cache_disabled = 1;
}
goto out;
}
rqstp->rq_cacherep = rp;
rp->c_state = RC_INPROG;
rp->c_xid = xid;
rp->c_proc = proc;
memcpy(&rp->c_addr, svc_addr_in(rqstp), sizeof(rp->c_addr));
rp->c_prot = proto;
rp->c_vers = vers;
rp->c_timestamp = jiffies;
hash_refile(rp);
if (rp->c_type == RC_REPLBUFF) {
kfree(rp->c_replvec.iov_base);
rp->c_replvec.iov_base = NULL;
}
rp->c_type = RC_NOCACHE;
out:
spin_unlock(&cache_lock);
return rtn;
found_entry:
age = jiffies - rp->c_timestamp;
rp->c_timestamp = jiffies;
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
rp->c_state = RC_UNUSED;
}
goto out;
}
void
nfsd_cache_update(struct svc_rqst *rqstp, int cachetype, __be32 *statp)
{
struct svc_cacherep *rp;
struct kvec *resv = &rqstp->rq_res.head[0], *cachv;
int len;
if (!(rp = rqstp->rq_cacherep) || cache_disabled)
return;
len = resv->iov_len - ((char*)statp - (char*)resv->iov_base);
len >>= 2;
if (!statp || len > (256 >> 2)) {
rp->c_state = RC_UNUSED;
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
spin_lock(&cache_lock);
rp->c_state = RC_UNUSED;
spin_unlock(&cache_lock);
return;
}
cachv->iov_len = len << 2;
memcpy(cachv->iov_base, statp, len << 2);
break;
}
spin_lock(&cache_lock);
lru_put_end(rp);
rp->c_secure = rqstp->rq_secure;
rp->c_type = cachetype;
rp->c_state = RC_DONE;
rp->c_timestamp = jiffies;
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
