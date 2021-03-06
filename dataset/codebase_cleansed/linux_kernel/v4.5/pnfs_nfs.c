void pnfs_generic_rw_release(void *data)
{
struct nfs_pgio_header *hdr = data;
nfs_put_client(hdr->ds_clp);
hdr->mds_ops->rpc_release(data);
}
void pnfs_generic_prepare_to_resend_writes(struct nfs_commit_data *data)
{
struct nfs_page *first = nfs_list_entry(data->pages.next);
data->task.tk_status = 0;
memcpy(&data->verf.verifier, &first->wb_verf,
sizeof(data->verf.verifier));
data->verf.verifier.data[0]++;
}
void pnfs_generic_write_commit_done(struct rpc_task *task, void *data)
{
struct nfs_commit_data *wdata = data;
wdata->mds_ops->rpc_call_done(task, data);
}
void pnfs_generic_commit_release(void *calldata)
{
struct nfs_commit_data *data = calldata;
data->completion_ops->completion(data);
pnfs_put_lseg(data->lseg);
nfs_put_client(data->ds_clp);
nfs_commitdata_release(data);
}
void
pnfs_generic_clear_request_commit(struct nfs_page *req,
struct nfs_commit_info *cinfo)
{
struct pnfs_layout_segment *freeme = NULL;
if (!test_and_clear_bit(PG_COMMIT_TO_DS, &req->wb_flags))
goto out;
cinfo->ds->nwritten--;
if (list_is_singular(&req->wb_list)) {
struct pnfs_commit_bucket *bucket;
bucket = list_first_entry(&req->wb_list,
struct pnfs_commit_bucket,
written);
freeme = bucket->wlseg;
bucket->wlseg = NULL;
}
out:
nfs_request_remove_commit_list(req, cinfo);
pnfs_put_lseg_locked(freeme);
}
static int
pnfs_generic_transfer_commit_list(struct list_head *src, struct list_head *dst,
struct nfs_commit_info *cinfo, int max)
{
struct nfs_page *req, *tmp;
int ret = 0;
list_for_each_entry_safe(req, tmp, src, wb_list) {
if (!nfs_lock_request(req))
continue;
kref_get(&req->wb_kref);
if (cond_resched_lock(cinfo->lock))
list_safe_reset_next(req, tmp, wb_list);
nfs_request_remove_commit_list(req, cinfo);
clear_bit(PG_COMMIT_TO_DS, &req->wb_flags);
nfs_list_add_request(req, dst);
ret++;
if ((ret == max) && !cinfo->dreq)
break;
}
return ret;
}
static int
pnfs_generic_scan_ds_commit_list(struct pnfs_commit_bucket *bucket,
struct nfs_commit_info *cinfo,
int max)
{
struct list_head *src = &bucket->written;
struct list_head *dst = &bucket->committing;
int ret;
lockdep_assert_held(cinfo->lock);
ret = pnfs_generic_transfer_commit_list(src, dst, cinfo, max);
if (ret) {
cinfo->ds->nwritten -= ret;
cinfo->ds->ncommitting += ret;
if (bucket->clseg == NULL)
bucket->clseg = pnfs_get_lseg(bucket->wlseg);
if (list_empty(src)) {
pnfs_put_lseg_locked(bucket->wlseg);
bucket->wlseg = NULL;
}
}
return ret;
}
int pnfs_generic_scan_commit_lists(struct nfs_commit_info *cinfo,
int max)
{
int i, rv = 0, cnt;
lockdep_assert_held(cinfo->lock);
for (i = 0; i < cinfo->ds->nbuckets && max != 0; i++) {
cnt = pnfs_generic_scan_ds_commit_list(&cinfo->ds->buckets[i],
cinfo, max);
max -= cnt;
rv += cnt;
}
return rv;
}
void pnfs_generic_recover_commit_reqs(struct list_head *dst,
struct nfs_commit_info *cinfo)
{
struct pnfs_commit_bucket *b;
struct pnfs_layout_segment *freeme;
int i;
lockdep_assert_held(cinfo->lock);
restart:
for (i = 0, b = cinfo->ds->buckets; i < cinfo->ds->nbuckets; i++, b++) {
if (pnfs_generic_transfer_commit_list(&b->written, dst,
cinfo, 0)) {
freeme = b->wlseg;
b->wlseg = NULL;
spin_unlock(cinfo->lock);
pnfs_put_lseg(freeme);
spin_lock(cinfo->lock);
goto restart;
}
}
cinfo->ds->nwritten = 0;
}
static void pnfs_generic_retry_commit(struct nfs_commit_info *cinfo, int idx)
{
struct pnfs_ds_commit_info *fl_cinfo = cinfo->ds;
struct pnfs_commit_bucket *bucket;
struct pnfs_layout_segment *freeme;
LIST_HEAD(pages);
int i;
spin_lock(cinfo->lock);
for (i = idx; i < fl_cinfo->nbuckets; i++) {
bucket = &fl_cinfo->buckets[i];
if (list_empty(&bucket->committing))
continue;
freeme = bucket->clseg;
bucket->clseg = NULL;
list_splice_init(&bucket->committing, &pages);
spin_unlock(cinfo->lock);
nfs_retry_commit(&pages, freeme, cinfo, i);
pnfs_put_lseg(freeme);
spin_lock(cinfo->lock);
}
spin_unlock(cinfo->lock);
}
static unsigned int
pnfs_generic_alloc_ds_commits(struct nfs_commit_info *cinfo,
struct list_head *list)
{
struct pnfs_ds_commit_info *fl_cinfo;
struct pnfs_commit_bucket *bucket;
struct nfs_commit_data *data;
int i;
unsigned int nreq = 0;
fl_cinfo = cinfo->ds;
bucket = fl_cinfo->buckets;
for (i = 0; i < fl_cinfo->nbuckets; i++, bucket++) {
if (list_empty(&bucket->committing))
continue;
data = nfs_commitdata_alloc();
if (!data)
break;
data->ds_commit_index = i;
list_add(&data->pages, list);
nreq++;
}
pnfs_generic_retry_commit(cinfo, i);
return nreq;
}
static inline
void pnfs_fetch_commit_bucket_list(struct list_head *pages,
struct nfs_commit_data *data,
struct nfs_commit_info *cinfo)
{
struct pnfs_commit_bucket *bucket;
bucket = &cinfo->ds->buckets[data->ds_commit_index];
spin_lock(cinfo->lock);
list_splice_init(&bucket->committing, pages);
data->lseg = bucket->clseg;
bucket->clseg = NULL;
spin_unlock(cinfo->lock);
}
int
pnfs_generic_commit_pagelist(struct inode *inode, struct list_head *mds_pages,
int how, struct nfs_commit_info *cinfo,
int (*initiate_commit)(struct nfs_commit_data *data,
int how))
{
struct nfs_commit_data *data, *tmp;
LIST_HEAD(list);
unsigned int nreq = 0;
if (!list_empty(mds_pages)) {
data = nfs_commitdata_alloc();
if (data != NULL) {
data->ds_commit_index = -1;
list_add(&data->pages, &list);
nreq++;
} else {
nfs_retry_commit(mds_pages, NULL, cinfo, 0);
pnfs_generic_retry_commit(cinfo, 0);
return -ENOMEM;
}
}
nreq += pnfs_generic_alloc_ds_commits(cinfo, &list);
if (nreq == 0)
goto out;
atomic_add(nreq, &cinfo->mds->rpcs_out);
list_for_each_entry_safe(data, tmp, &list, pages) {
list_del_init(&data->pages);
if (data->ds_commit_index < 0) {
nfs_init_commit(data, mds_pages, NULL, cinfo);
nfs_initiate_commit(NFS_CLIENT(inode), data,
NFS_PROTO(data->inode),
data->mds_ops, how, 0);
} else {
LIST_HEAD(pages);
pnfs_fetch_commit_bucket_list(&pages, data, cinfo);
nfs_init_commit(data, &pages, data->lseg, cinfo);
initiate_commit(data, how);
}
}
out:
cinfo->ds->ncommitting = 0;
return PNFS_ATTEMPTED;
}
static void
print_ds(struct nfs4_pnfs_ds *ds)
{
if (ds == NULL) {
printk(KERN_WARNING "%s NULL device\n", __func__);
return;
}
printk(KERN_WARNING " ds %s\n"
" ref count %d\n"
" client %p\n"
" cl_exchange_flags %x\n",
ds->ds_remotestr,
atomic_read(&ds->ds_count), ds->ds_clp,
ds->ds_clp ? ds->ds_clp->cl_exchange_flags : 0);
}
static bool
same_sockaddr(struct sockaddr *addr1, struct sockaddr *addr2)
{
struct sockaddr_in *a, *b;
struct sockaddr_in6 *a6, *b6;
if (addr1->sa_family != addr2->sa_family)
return false;
switch (addr1->sa_family) {
case AF_INET:
a = (struct sockaddr_in *)addr1;
b = (struct sockaddr_in *)addr2;
if (a->sin_addr.s_addr == b->sin_addr.s_addr &&
a->sin_port == b->sin_port)
return true;
break;
case AF_INET6:
a6 = (struct sockaddr_in6 *)addr1;
b6 = (struct sockaddr_in6 *)addr2;
if (ipv6_addr_src_scope(&a6->sin6_addr) ==
IPV6_ADDR_SCOPE_LINKLOCAL &&
a6->sin6_scope_id != b6->sin6_scope_id)
return false;
if (ipv6_addr_equal(&a6->sin6_addr, &b6->sin6_addr) &&
a6->sin6_port == b6->sin6_port)
return true;
break;
default:
dprintk("%s: unhandled address family: %u\n",
__func__, addr1->sa_family);
return false;
}
return false;
}
static bool
_same_data_server_addrs_locked(const struct list_head *dsaddrs1,
const struct list_head *dsaddrs2)
{
struct nfs4_pnfs_ds_addr *da1, *da2;
struct sockaddr *sa1, *sa2;
bool match = false;
list_for_each_entry(da1, dsaddrs1, da_node) {
sa1 = (struct sockaddr *)&da1->da_addr;
match = false;
list_for_each_entry(da2, dsaddrs2, da_node) {
sa2 = (struct sockaddr *)&da2->da_addr;
match = same_sockaddr(sa1, sa2);
if (match)
break;
}
if (!match)
break;
}
return match;
}
static struct nfs4_pnfs_ds *
_data_server_lookup_locked(const struct list_head *dsaddrs)
{
struct nfs4_pnfs_ds *ds;
list_for_each_entry(ds, &nfs4_data_server_cache, ds_node)
if (_same_data_server_addrs_locked(&ds->ds_addrs, dsaddrs))
return ds;
return NULL;
}
static void destroy_ds(struct nfs4_pnfs_ds *ds)
{
struct nfs4_pnfs_ds_addr *da;
dprintk("--> %s\n", __func__);
ifdebug(FACILITY)
print_ds(ds);
nfs_put_client(ds->ds_clp);
while (!list_empty(&ds->ds_addrs)) {
da = list_first_entry(&ds->ds_addrs,
struct nfs4_pnfs_ds_addr,
da_node);
list_del_init(&da->da_node);
kfree(da->da_remotestr);
kfree(da);
}
kfree(ds->ds_remotestr);
kfree(ds);
}
void nfs4_pnfs_ds_put(struct nfs4_pnfs_ds *ds)
{
if (atomic_dec_and_lock(&ds->ds_count,
&nfs4_ds_cache_lock)) {
list_del_init(&ds->ds_node);
spin_unlock(&nfs4_ds_cache_lock);
destroy_ds(ds);
}
}
static char *
nfs4_pnfs_remotestr(struct list_head *dsaddrs, gfp_t gfp_flags)
{
struct nfs4_pnfs_ds_addr *da;
char *remotestr;
size_t len;
char *p;
len = 3;
list_for_each_entry(da, dsaddrs, da_node) {
len += strlen(da->da_remotestr) + 1;
}
remotestr = kzalloc(len, gfp_flags);
if (!remotestr)
return NULL;
p = remotestr;
*(p++) = '{';
len--;
list_for_each_entry(da, dsaddrs, da_node) {
size_t ll = strlen(da->da_remotestr);
if (ll > len)
goto out_err;
memcpy(p, da->da_remotestr, ll);
p += ll;
len -= ll;
if (len < 1)
goto out_err;
(*p++) = ',';
len--;
}
if (len < 2)
goto out_err;
*(p++) = '}';
*p = '\0';
return remotestr;
out_err:
kfree(remotestr);
return NULL;
}
struct nfs4_pnfs_ds *
nfs4_pnfs_ds_add(struct list_head *dsaddrs, gfp_t gfp_flags)
{
struct nfs4_pnfs_ds *tmp_ds, *ds = NULL;
char *remotestr;
if (list_empty(dsaddrs)) {
dprintk("%s: no addresses defined\n", __func__);
goto out;
}
ds = kzalloc(sizeof(*ds), gfp_flags);
if (!ds)
goto out;
remotestr = nfs4_pnfs_remotestr(dsaddrs, gfp_flags);
spin_lock(&nfs4_ds_cache_lock);
tmp_ds = _data_server_lookup_locked(dsaddrs);
if (tmp_ds == NULL) {
INIT_LIST_HEAD(&ds->ds_addrs);
list_splice_init(dsaddrs, &ds->ds_addrs);
ds->ds_remotestr = remotestr;
atomic_set(&ds->ds_count, 1);
INIT_LIST_HEAD(&ds->ds_node);
ds->ds_clp = NULL;
list_add(&ds->ds_node, &nfs4_data_server_cache);
dprintk("%s add new data server %s\n", __func__,
ds->ds_remotestr);
} else {
kfree(remotestr);
kfree(ds);
atomic_inc(&tmp_ds->ds_count);
dprintk("%s data server %s found, inc'ed ds_count to %d\n",
__func__, tmp_ds->ds_remotestr,
atomic_read(&tmp_ds->ds_count));
ds = tmp_ds;
}
spin_unlock(&nfs4_ds_cache_lock);
out:
return ds;
}
static void nfs4_wait_ds_connect(struct nfs4_pnfs_ds *ds)
{
might_sleep();
wait_on_bit(&ds->ds_state, NFS4DS_CONNECTING,
TASK_KILLABLE);
}
static void nfs4_clear_ds_conn_bit(struct nfs4_pnfs_ds *ds)
{
smp_mb__before_atomic();
clear_bit(NFS4DS_CONNECTING, &ds->ds_state);
smp_mb__after_atomic();
wake_up_bit(&ds->ds_state, NFS4DS_CONNECTING);
}
static bool load_v3_ds_connect(void)
{
if (!get_v3_ds_connect) {
get_v3_ds_connect = symbol_request(nfs3_set_ds_client);
WARN_ON_ONCE(!get_v3_ds_connect);
}
return(get_v3_ds_connect != NULL);
}
void nfs4_pnfs_v3_ds_connect_unload(void)
{
if (get_v3_ds_connect) {
symbol_put(nfs3_set_ds_client);
get_v3_ds_connect = NULL;
}
}
static int _nfs4_pnfs_v3_ds_connect(struct nfs_server *mds_srv,
struct nfs4_pnfs_ds *ds,
unsigned int timeo,
unsigned int retrans,
rpc_authflavor_t au_flavor)
{
struct nfs_client *clp = ERR_PTR(-EIO);
struct nfs4_pnfs_ds_addr *da;
int status = 0;
dprintk("--> %s DS %s au_flavor %d\n", __func__,
ds->ds_remotestr, au_flavor);
if (!load_v3_ds_connect())
goto out;
list_for_each_entry(da, &ds->ds_addrs, da_node) {
dprintk("%s: DS %s: trying address %s\n",
__func__, ds->ds_remotestr, da->da_remotestr);
clp = get_v3_ds_connect(mds_srv->nfs_client,
(struct sockaddr *)&da->da_addr,
da->da_addrlen, IPPROTO_TCP,
timeo, retrans, au_flavor);
if (!IS_ERR(clp))
break;
}
if (IS_ERR(clp)) {
status = PTR_ERR(clp);
goto out;
}
smp_wmb();
ds->ds_clp = clp;
dprintk("%s [new] addr: %s\n", __func__, ds->ds_remotestr);
out:
return status;
}
static int _nfs4_pnfs_v4_ds_connect(struct nfs_server *mds_srv,
struct nfs4_pnfs_ds *ds,
unsigned int timeo,
unsigned int retrans,
u32 minor_version,
rpc_authflavor_t au_flavor)
{
struct nfs_client *clp = ERR_PTR(-EIO);
struct nfs4_pnfs_ds_addr *da;
int status = 0;
dprintk("--> %s DS %s au_flavor %d\n", __func__, ds->ds_remotestr,
au_flavor);
list_for_each_entry(da, &ds->ds_addrs, da_node) {
dprintk("%s: DS %s: trying address %s\n",
__func__, ds->ds_remotestr, da->da_remotestr);
clp = nfs4_set_ds_client(mds_srv->nfs_client,
(struct sockaddr *)&da->da_addr,
da->da_addrlen, IPPROTO_TCP,
timeo, retrans, minor_version,
au_flavor);
if (!IS_ERR(clp))
break;
}
if (IS_ERR(clp)) {
status = PTR_ERR(clp);
goto out;
}
status = nfs4_init_ds_session(clp, mds_srv->nfs_client->cl_lease_time);
if (status)
goto out_put;
smp_wmb();
ds->ds_clp = clp;
dprintk("%s [new] addr: %s\n", __func__, ds->ds_remotestr);
out:
return status;
out_put:
nfs_put_client(clp);
goto out;
}
void nfs4_pnfs_ds_connect(struct nfs_server *mds_srv, struct nfs4_pnfs_ds *ds,
struct nfs4_deviceid_node *devid, unsigned int timeo,
unsigned int retrans, u32 version,
u32 minor_version, rpc_authflavor_t au_flavor)
{
if (test_and_set_bit(NFS4DS_CONNECTING, &ds->ds_state) == 0) {
int err = 0;
if (version == 3) {
err = _nfs4_pnfs_v3_ds_connect(mds_srv, ds, timeo,
retrans, au_flavor);
} else if (version == 4) {
err = _nfs4_pnfs_v4_ds_connect(mds_srv, ds, timeo,
retrans, minor_version,
au_flavor);
} else {
dprintk("%s: unsupported DS version %d\n", __func__,
version);
err = -EPROTONOSUPPORT;
}
if (err)
nfs4_mark_deviceid_unavailable(devid);
nfs4_clear_ds_conn_bit(ds);
} else {
nfs4_wait_ds_connect(ds);
}
}
struct nfs4_pnfs_ds_addr *
nfs4_decode_mp_ds_addr(struct net *net, struct xdr_stream *xdr, gfp_t gfp_flags)
{
struct nfs4_pnfs_ds_addr *da = NULL;
char *buf, *portstr;
__be16 port;
int nlen, rlen;
int tmp[2];
__be32 *p;
char *netid, *match_netid;
size_t len, match_netid_len;
char *startsep = "";
char *endsep = "";
p = xdr_inline_decode(xdr, 4);
if (unlikely(!p))
goto out_err;
nlen = be32_to_cpup(p++);
p = xdr_inline_decode(xdr, nlen);
if (unlikely(!p))
goto out_err;
netid = kmalloc(nlen+1, gfp_flags);
if (unlikely(!netid))
goto out_err;
netid[nlen] = '\0';
memcpy(netid, p, nlen);
p = xdr_inline_decode(xdr, 4);
if (unlikely(!p))
goto out_free_netid;
rlen = be32_to_cpup(p);
p = xdr_inline_decode(xdr, rlen);
if (unlikely(!p))
goto out_free_netid;
if (rlen > INET6_ADDRSTRLEN + IPV6_SCOPE_ID_LEN + 8) {
dprintk("%s: Invalid address, length %d\n", __func__,
rlen);
goto out_free_netid;
}
buf = kmalloc(rlen + 1, gfp_flags);
if (!buf) {
dprintk("%s: Not enough memory\n", __func__);
goto out_free_netid;
}
buf[rlen] = '\0';
memcpy(buf, p, rlen);
portstr = strrchr(buf, '.');
if (!portstr) {
dprintk("%s: Failed finding expected dot in port\n",
__func__);
goto out_free_buf;
}
*portstr = '-';
portstr = strrchr(buf, '.');
if (!portstr) {
dprintk("%s: Failed finding expected dot between address and "
"port\n", __func__);
goto out_free_buf;
}
*portstr = '\0';
da = kzalloc(sizeof(*da), gfp_flags);
if (unlikely(!da))
goto out_free_buf;
INIT_LIST_HEAD(&da->da_node);
if (!rpc_pton(net, buf, portstr-buf, (struct sockaddr *)&da->da_addr,
sizeof(da->da_addr))) {
dprintk("%s: error parsing address %s\n", __func__, buf);
goto out_free_da;
}
portstr++;
sscanf(portstr, "%d-%d", &tmp[0], &tmp[1]);
port = htons((tmp[0] << 8) | (tmp[1]));
switch (da->da_addr.ss_family) {
case AF_INET:
((struct sockaddr_in *)&da->da_addr)->sin_port = port;
da->da_addrlen = sizeof(struct sockaddr_in);
match_netid = "tcp";
match_netid_len = 3;
break;
case AF_INET6:
((struct sockaddr_in6 *)&da->da_addr)->sin6_port = port;
da->da_addrlen = sizeof(struct sockaddr_in6);
match_netid = "tcp6";
match_netid_len = 4;
startsep = "[";
endsep = "]";
break;
default:
dprintk("%s: unsupported address family: %u\n",
__func__, da->da_addr.ss_family);
goto out_free_da;
}
if (nlen != match_netid_len || strncmp(netid, match_netid, nlen)) {
dprintk("%s: ERROR: r_netid \"%s\" != \"%s\"\n",
__func__, netid, match_netid);
goto out_free_da;
}
len = strlen(startsep) + strlen(buf) + strlen(endsep) + 7;
da->da_remotestr = kzalloc(len, gfp_flags);
if (da->da_remotestr)
snprintf(da->da_remotestr, len, "%s%s%s:%u", startsep,
buf, endsep, ntohs(port));
dprintk("%s: Parsed DS addr %s\n", __func__, da->da_remotestr);
kfree(buf);
kfree(netid);
return da;
out_free_da:
kfree(da);
out_free_buf:
dprintk("%s: Error parsing DS addr: %s\n", __func__, buf);
kfree(buf);
out_free_netid:
kfree(netid);
out_err:
return NULL;
}
void
pnfs_layout_mark_request_commit(struct nfs_page *req,
struct pnfs_layout_segment *lseg,
struct nfs_commit_info *cinfo,
u32 ds_commit_idx)
{
struct list_head *list;
struct pnfs_commit_bucket *buckets;
spin_lock(cinfo->lock);
buckets = cinfo->ds->buckets;
list = &buckets[ds_commit_idx].written;
if (list_empty(list)) {
if (!pnfs_is_valid_lseg(lseg)) {
spin_unlock(cinfo->lock);
cinfo->completion_ops->resched_write(cinfo, req);
return;
}
WARN_ON_ONCE(buckets[ds_commit_idx].wlseg != NULL);
buckets[ds_commit_idx].wlseg = pnfs_get_lseg(lseg);
}
set_bit(PG_COMMIT_TO_DS, &req->wb_flags);
cinfo->ds->nwritten++;
nfs_request_add_commit_list_locked(req, list, cinfo);
spin_unlock(cinfo->lock);
nfs_mark_page_unstable(req->wb_page, cinfo);
}
int
pnfs_nfs_generic_sync(struct inode *inode, bool datasync)
{
if (datasync)
return 0;
return pnfs_layoutcommit_inode(inode, true);
}
