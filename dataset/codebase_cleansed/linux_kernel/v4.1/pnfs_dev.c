void
nfs4_print_deviceid(const struct nfs4_deviceid *id)
{
u32 *p = (u32 *)id;
dprintk("%s: device id= [%x%x%x%x]\n", __func__,
p[0], p[1], p[2], p[3]);
}
static inline u32
nfs4_deviceid_hash(const struct nfs4_deviceid *id)
{
unsigned char *cptr = (unsigned char *)id->data;
unsigned int nbytes = NFS4_DEVICEID4_SIZE;
u32 x = 0;
while (nbytes--) {
x *= 37;
x += *cptr++;
}
return x & NFS4_DEVICE_ID_HASH_MASK;
}
static struct nfs4_deviceid_node *
_lookup_deviceid(const struct pnfs_layoutdriver_type *ld,
const struct nfs_client *clp, const struct nfs4_deviceid *id,
long hash)
{
struct nfs4_deviceid_node *d;
hlist_for_each_entry_rcu(d, &nfs4_deviceid_cache[hash], node)
if (d->ld == ld && d->nfs_client == clp &&
!memcmp(&d->deviceid, id, sizeof(*id))) {
if (atomic_read(&d->ref))
return d;
else
continue;
}
return NULL;
}
static struct nfs4_deviceid_node *
nfs4_get_device_info(struct nfs_server *server,
const struct nfs4_deviceid *dev_id,
struct rpc_cred *cred, gfp_t gfp_flags)
{
struct nfs4_deviceid_node *d = NULL;
struct pnfs_device *pdev = NULL;
struct page **pages = NULL;
u32 max_resp_sz;
int max_pages;
int rc, i;
max_resp_sz = server->nfs_client->cl_session->fc_attrs.max_resp_sz;
if (server->pnfs_curr_ld->max_deviceinfo_size &&
server->pnfs_curr_ld->max_deviceinfo_size < max_resp_sz)
max_resp_sz = server->pnfs_curr_ld->max_deviceinfo_size;
max_pages = nfs_page_array_len(0, max_resp_sz);
dprintk("%s: server %p max_resp_sz %u max_pages %d\n",
__func__, server, max_resp_sz, max_pages);
pdev = kzalloc(sizeof(*pdev), gfp_flags);
if (!pdev)
return NULL;
pages = kcalloc(max_pages, sizeof(struct page *), gfp_flags);
if (!pages)
goto out_free_pdev;
for (i = 0; i < max_pages; i++) {
pages[i] = alloc_page(gfp_flags);
if (!pages[i])
goto out_free_pages;
}
memcpy(&pdev->dev_id, dev_id, sizeof(*dev_id));
pdev->layout_type = server->pnfs_curr_ld->id;
pdev->pages = pages;
pdev->pgbase = 0;
pdev->pglen = max_resp_sz;
pdev->mincount = 0;
pdev->maxcount = max_resp_sz - nfs41_maxgetdevinfo_overhead;
rc = nfs4_proc_getdeviceinfo(server, pdev, cred);
dprintk("%s getdevice info returns %d\n", __func__, rc);
if (rc)
goto out_free_pages;
d = server->pnfs_curr_ld->alloc_deviceid_node(server, pdev,
gfp_flags);
if (d && pdev->nocache)
set_bit(NFS_DEVICEID_NOCACHE, &d->flags);
out_free_pages:
for (i = 0; i < max_pages; i++)
__free_page(pages[i]);
kfree(pages);
out_free_pdev:
kfree(pdev);
dprintk("<-- %s d %p\n", __func__, d);
return d;
}
static struct nfs4_deviceid_node *
__nfs4_find_get_deviceid(struct nfs_server *server,
const struct nfs4_deviceid *id, long hash)
{
struct nfs4_deviceid_node *d;
rcu_read_lock();
d = _lookup_deviceid(server->pnfs_curr_ld, server->nfs_client, id,
hash);
if (d != NULL && !atomic_inc_not_zero(&d->ref))
d = NULL;
rcu_read_unlock();
return d;
}
struct nfs4_deviceid_node *
nfs4_find_get_deviceid(struct nfs_server *server,
const struct nfs4_deviceid *id, struct rpc_cred *cred,
gfp_t gfp_mask)
{
long hash = nfs4_deviceid_hash(id);
struct nfs4_deviceid_node *d, *new;
d = __nfs4_find_get_deviceid(server, id, hash);
if (d)
return d;
new = nfs4_get_device_info(server, id, cred, gfp_mask);
if (!new)
return new;
spin_lock(&nfs4_deviceid_lock);
d = __nfs4_find_get_deviceid(server, id, hash);
if (d) {
spin_unlock(&nfs4_deviceid_lock);
server->pnfs_curr_ld->free_deviceid_node(new);
return d;
}
hlist_add_head_rcu(&new->node, &nfs4_deviceid_cache[hash]);
atomic_inc(&new->ref);
spin_unlock(&nfs4_deviceid_lock);
return new;
}
void
nfs4_delete_deviceid(const struct pnfs_layoutdriver_type *ld,
const struct nfs_client *clp, const struct nfs4_deviceid *id)
{
struct nfs4_deviceid_node *d;
spin_lock(&nfs4_deviceid_lock);
rcu_read_lock();
d = _lookup_deviceid(ld, clp, id, nfs4_deviceid_hash(id));
rcu_read_unlock();
if (!d) {
spin_unlock(&nfs4_deviceid_lock);
return;
}
hlist_del_init_rcu(&d->node);
clear_bit(NFS_DEVICEID_NOCACHE, &d->flags);
spin_unlock(&nfs4_deviceid_lock);
nfs4_put_deviceid_node(d);
}
void
nfs4_init_deviceid_node(struct nfs4_deviceid_node *d, struct nfs_server *server,
const struct nfs4_deviceid *id)
{
INIT_HLIST_NODE(&d->node);
INIT_HLIST_NODE(&d->tmpnode);
d->ld = server->pnfs_curr_ld;
d->nfs_client = server->nfs_client;
d->flags = 0;
d->deviceid = *id;
atomic_set(&d->ref, 1);
}
bool
nfs4_put_deviceid_node(struct nfs4_deviceid_node *d)
{
if (test_bit(NFS_DEVICEID_NOCACHE, &d->flags)) {
if (atomic_add_unless(&d->ref, -1, 2))
return false;
nfs4_delete_deviceid(d->ld, d->nfs_client, &d->deviceid);
}
if (!atomic_dec_and_test(&d->ref))
return false;
d->ld->free_deviceid_node(d);
return true;
}
void
nfs4_mark_deviceid_unavailable(struct nfs4_deviceid_node *node)
{
node->timestamp_unavailable = jiffies;
set_bit(NFS_DEVICEID_UNAVAILABLE, &node->flags);
}
bool
nfs4_test_deviceid_unavailable(struct nfs4_deviceid_node *node)
{
if (test_bit(NFS_DEVICEID_UNAVAILABLE, &node->flags)) {
unsigned long start, end;
end = jiffies;
start = end - PNFS_DEVICE_RETRY_TIMEOUT;
if (time_in_range(node->timestamp_unavailable, start, end))
return true;
clear_bit(NFS_DEVICEID_UNAVAILABLE, &node->flags);
}
return false;
}
static void
_deviceid_purge_client(const struct nfs_client *clp, long hash)
{
struct nfs4_deviceid_node *d;
HLIST_HEAD(tmp);
spin_lock(&nfs4_deviceid_lock);
rcu_read_lock();
hlist_for_each_entry_rcu(d, &nfs4_deviceid_cache[hash], node)
if (d->nfs_client == clp && atomic_read(&d->ref)) {
hlist_del_init_rcu(&d->node);
hlist_add_head(&d->tmpnode, &tmp);
clear_bit(NFS_DEVICEID_NOCACHE, &d->flags);
}
rcu_read_unlock();
spin_unlock(&nfs4_deviceid_lock);
if (hlist_empty(&tmp))
return;
while (!hlist_empty(&tmp)) {
d = hlist_entry(tmp.first, struct nfs4_deviceid_node, tmpnode);
hlist_del(&d->tmpnode);
nfs4_put_deviceid_node(d);
}
}
void
nfs4_deviceid_purge_client(const struct nfs_client *clp)
{
long h;
if (!(clp->cl_exchange_flags & EXCHGID4_FLAG_USE_PNFS_MDS))
return;
for (h = 0; h < NFS4_DEVICE_ID_HASH_SIZE; h++)
_deviceid_purge_client(clp, h);
}
void
nfs4_deviceid_mark_client_invalid(struct nfs_client *clp)
{
struct nfs4_deviceid_node *d;
int i;
rcu_read_lock();
for (i = 0; i < NFS4_DEVICE_ID_HASH_SIZE; i ++){
hlist_for_each_entry_rcu(d, &nfs4_deviceid_cache[i], node)
if (d->nfs_client == clp)
set_bit(NFS_DEVICEID_INVALID, &d->flags);
}
rcu_read_unlock();
}
