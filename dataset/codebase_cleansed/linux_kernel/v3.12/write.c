struct nfs_commit_data *nfs_commitdata_alloc(void)
{
struct nfs_commit_data *p = mempool_alloc(nfs_commit_mempool, GFP_NOIO);
if (p) {
memset(p, 0, sizeof(*p));
INIT_LIST_HEAD(&p->pages);
}
return p;
}
void nfs_commit_free(struct nfs_commit_data *p)
{
mempool_free(p, nfs_commit_mempool);
}
struct nfs_write_header *nfs_writehdr_alloc(void)
{
struct nfs_write_header *p = mempool_alloc(nfs_wdata_mempool, GFP_NOIO);
if (p) {
struct nfs_pgio_header *hdr = &p->header;
memset(p, 0, sizeof(*p));
INIT_LIST_HEAD(&hdr->pages);
INIT_LIST_HEAD(&hdr->rpc_list);
spin_lock_init(&hdr->lock);
atomic_set(&hdr->refcnt, 0);
hdr->verf = &p->verf;
}
return p;
}
static struct nfs_write_data *nfs_writedata_alloc(struct nfs_pgio_header *hdr,
unsigned int pagecount)
{
struct nfs_write_data *data, *prealloc;
prealloc = &container_of(hdr, struct nfs_write_header, header)->rpc_data;
if (prealloc->header == NULL)
data = prealloc;
else
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
goto out;
if (nfs_pgarray_set(&data->pages, pagecount)) {
data->header = hdr;
atomic_inc(&hdr->refcnt);
} else {
if (data != prealloc)
kfree(data);
data = NULL;
}
out:
return data;
}
void nfs_writehdr_free(struct nfs_pgio_header *hdr)
{
struct nfs_write_header *whdr = container_of(hdr, struct nfs_write_header, header);
mempool_free(whdr, nfs_wdata_mempool);
}
void nfs_writedata_release(struct nfs_write_data *wdata)
{
struct nfs_pgio_header *hdr = wdata->header;
struct nfs_write_header *write_header = container_of(hdr, struct nfs_write_header, header);
put_nfs_open_context(wdata->args.context);
if (wdata->pages.pagevec != wdata->pages.page_array)
kfree(wdata->pages.pagevec);
if (wdata == &write_header->rpc_data) {
wdata->header = NULL;
wdata = NULL;
}
if (atomic_dec_and_test(&hdr->refcnt))
hdr->completion_ops->completion(hdr);
kfree(wdata);
}
static void nfs_context_set_write_error(struct nfs_open_context *ctx, int error)
{
ctx->error = error;
smp_wmb();
set_bit(NFS_CONTEXT_ERROR_WRITE, &ctx->flags);
}
static struct nfs_page *
nfs_page_find_request_locked(struct nfs_inode *nfsi, struct page *page)
{
struct nfs_page *req = NULL;
if (PagePrivate(page))
req = (struct nfs_page *)page_private(page);
else if (unlikely(PageSwapCache(page))) {
struct nfs_page *freq, *t;
list_for_each_entry_safe(freq, t, &nfsi->commit_info.list, wb_list) {
if (freq->wb_page == page) {
req = freq;
break;
}
}
}
if (req)
kref_get(&req->wb_kref);
return req;
}
static struct nfs_page *nfs_page_find_request(struct page *page)
{
struct inode *inode = page_file_mapping(page)->host;
struct nfs_page *req = NULL;
spin_lock(&inode->i_lock);
req = nfs_page_find_request_locked(NFS_I(inode), page);
spin_unlock(&inode->i_lock);
return req;
}
static void nfs_grow_file(struct page *page, unsigned int offset, unsigned int count)
{
struct inode *inode = page_file_mapping(page)->host;
loff_t end, i_size;
pgoff_t end_index;
spin_lock(&inode->i_lock);
i_size = i_size_read(inode);
end_index = (i_size - 1) >> PAGE_CACHE_SHIFT;
if (i_size > 0 && page_file_index(page) < end_index)
goto out;
end = page_file_offset(page) + ((loff_t)offset+count);
if (i_size >= end)
goto out;
i_size_write(inode, end);
nfs_inc_stats(inode, NFSIOS_EXTENDWRITE);
out:
spin_unlock(&inode->i_lock);
}
static void nfs_set_pageerror(struct page *page)
{
nfs_zap_mapping(page_file_mapping(page)->host, page_file_mapping(page));
}
static void nfs_mark_uptodate(struct page *page, unsigned int base, unsigned int count)
{
if (PageUptodate(page))
return;
if (base != 0)
return;
if (count != nfs_page_length(page))
return;
SetPageUptodate(page);
}
static int wb_priority(struct writeback_control *wbc)
{
if (wbc->for_reclaim)
return FLUSH_HIGHPRI | FLUSH_STABLE;
if (wbc->for_kupdate || wbc->for_background)
return FLUSH_LOWPRI | FLUSH_COND_STABLE;
return FLUSH_COND_STABLE;
}
static void nfs_set_page_writeback(struct page *page)
{
struct nfs_server *nfss = NFS_SERVER(page_file_mapping(page)->host);
int ret = test_set_page_writeback(page);
WARN_ON_ONCE(ret != 0);
if (atomic_long_inc_return(&nfss->writeback) >
NFS_CONGESTION_ON_THRESH) {
set_bdi_congested(&nfss->backing_dev_info,
BLK_RW_ASYNC);
}
}
static void nfs_end_page_writeback(struct page *page)
{
struct inode *inode = page_file_mapping(page)->host;
struct nfs_server *nfss = NFS_SERVER(inode);
end_page_writeback(page);
if (atomic_long_dec_return(&nfss->writeback) < NFS_CONGESTION_OFF_THRESH)
clear_bdi_congested(&nfss->backing_dev_info, BLK_RW_ASYNC);
}
static struct nfs_page *nfs_find_and_lock_request(struct page *page, bool nonblock)
{
struct inode *inode = page_file_mapping(page)->host;
struct nfs_page *req;
int ret;
spin_lock(&inode->i_lock);
for (;;) {
req = nfs_page_find_request_locked(NFS_I(inode), page);
if (req == NULL)
break;
if (nfs_lock_request(req))
break;
spin_unlock(&inode->i_lock);
if (!nonblock)
ret = nfs_wait_on_request(req);
else
ret = -EAGAIN;
nfs_release_request(req);
if (ret != 0)
return ERR_PTR(ret);
spin_lock(&inode->i_lock);
}
spin_unlock(&inode->i_lock);
return req;
}
static int nfs_page_async_flush(struct nfs_pageio_descriptor *pgio,
struct page *page, bool nonblock)
{
struct nfs_page *req;
int ret = 0;
req = nfs_find_and_lock_request(page, nonblock);
if (!req)
goto out;
ret = PTR_ERR(req);
if (IS_ERR(req))
goto out;
nfs_set_page_writeback(page);
WARN_ON_ONCE(test_bit(PG_CLEAN, &req->wb_flags));
ret = 0;
if (!nfs_pageio_add_request(pgio, req)) {
nfs_redirty_request(req);
ret = pgio->pg_error;
}
out:
return ret;
}
static int nfs_do_writepage(struct page *page, struct writeback_control *wbc, struct nfs_pageio_descriptor *pgio)
{
struct inode *inode = page_file_mapping(page)->host;
int ret;
nfs_inc_stats(inode, NFSIOS_VFSWRITEPAGE);
nfs_add_stats(inode, NFSIOS_WRITEPAGES, 1);
nfs_pageio_cond_complete(pgio, page_file_index(page));
ret = nfs_page_async_flush(pgio, page, wbc->sync_mode == WB_SYNC_NONE);
if (ret == -EAGAIN) {
redirty_page_for_writepage(wbc, page);
ret = 0;
}
return ret;
}
static int nfs_writepage_locked(struct page *page, struct writeback_control *wbc)
{
struct nfs_pageio_descriptor pgio;
int err;
NFS_PROTO(page_file_mapping(page)->host)->write_pageio_init(&pgio,
page->mapping->host,
wb_priority(wbc),
&nfs_async_write_completion_ops);
err = nfs_do_writepage(page, wbc, &pgio);
nfs_pageio_complete(&pgio);
if (err < 0)
return err;
if (pgio.pg_error < 0)
return pgio.pg_error;
return 0;
}
int nfs_writepage(struct page *page, struct writeback_control *wbc)
{
int ret;
ret = nfs_writepage_locked(page, wbc);
unlock_page(page);
return ret;
}
static int nfs_writepages_callback(struct page *page, struct writeback_control *wbc, void *data)
{
int ret;
ret = nfs_do_writepage(page, wbc, data);
unlock_page(page);
return ret;
}
int nfs_writepages(struct address_space *mapping, struct writeback_control *wbc)
{
struct inode *inode = mapping->host;
unsigned long *bitlock = &NFS_I(inode)->flags;
struct nfs_pageio_descriptor pgio;
int err;
err = wait_on_bit_lock(bitlock, NFS_INO_FLUSHING,
nfs_wait_bit_killable, TASK_KILLABLE);
if (err)
goto out_err;
nfs_inc_stats(inode, NFSIOS_VFSWRITEPAGES);
NFS_PROTO(inode)->write_pageio_init(&pgio, inode, wb_priority(wbc), &nfs_async_write_completion_ops);
err = write_cache_pages(mapping, wbc, nfs_writepages_callback, &pgio);
nfs_pageio_complete(&pgio);
clear_bit_unlock(NFS_INO_FLUSHING, bitlock);
smp_mb__after_clear_bit();
wake_up_bit(bitlock, NFS_INO_FLUSHING);
if (err < 0)
goto out_err;
err = pgio.pg_error;
if (err < 0)
goto out_err;
return 0;
out_err:
return err;
}
static void nfs_inode_add_request(struct inode *inode, struct nfs_page *req)
{
struct nfs_inode *nfsi = NFS_I(inode);
nfs_lock_request(req);
spin_lock(&inode->i_lock);
if (!nfsi->npages && NFS_PROTO(inode)->have_delegation(inode, FMODE_WRITE))
inode->i_version++;
if (likely(!PageSwapCache(req->wb_page))) {
set_bit(PG_MAPPED, &req->wb_flags);
SetPagePrivate(req->wb_page);
set_page_private(req->wb_page, (unsigned long)req);
}
nfsi->npages++;
kref_get(&req->wb_kref);
spin_unlock(&inode->i_lock);
}
static void nfs_inode_remove_request(struct nfs_page *req)
{
struct inode *inode = req->wb_context->dentry->d_inode;
struct nfs_inode *nfsi = NFS_I(inode);
spin_lock(&inode->i_lock);
if (likely(!PageSwapCache(req->wb_page))) {
set_page_private(req->wb_page, 0);
ClearPagePrivate(req->wb_page);
clear_bit(PG_MAPPED, &req->wb_flags);
}
nfsi->npages--;
spin_unlock(&inode->i_lock);
nfs_release_request(req);
}
static void
nfs_mark_request_dirty(struct nfs_page *req)
{
__set_page_dirty_nobuffers(req->wb_page);
}
void
nfs_request_add_commit_list(struct nfs_page *req, struct list_head *dst,
struct nfs_commit_info *cinfo)
{
set_bit(PG_CLEAN, &(req)->wb_flags);
spin_lock(cinfo->lock);
nfs_list_add_request(req, dst);
cinfo->mds->ncommit++;
spin_unlock(cinfo->lock);
if (!cinfo->dreq) {
inc_zone_page_state(req->wb_page, NR_UNSTABLE_NFS);
inc_bdi_stat(page_file_mapping(req->wb_page)->backing_dev_info,
BDI_RECLAIMABLE);
__mark_inode_dirty(req->wb_context->dentry->d_inode,
I_DIRTY_DATASYNC);
}
}
void
nfs_request_remove_commit_list(struct nfs_page *req,
struct nfs_commit_info *cinfo)
{
if (!test_and_clear_bit(PG_CLEAN, &(req)->wb_flags))
return;
nfs_list_remove_request(req);
cinfo->mds->ncommit--;
}
static void nfs_init_cinfo_from_inode(struct nfs_commit_info *cinfo,
struct inode *inode)
{
cinfo->lock = &inode->i_lock;
cinfo->mds = &NFS_I(inode)->commit_info;
cinfo->ds = pnfs_get_ds_info(inode);
cinfo->dreq = NULL;
cinfo->completion_ops = &nfs_commit_completion_ops;
}
void nfs_init_cinfo(struct nfs_commit_info *cinfo,
struct inode *inode,
struct nfs_direct_req *dreq)
{
if (dreq)
nfs_init_cinfo_from_dreq(cinfo, dreq);
else
nfs_init_cinfo_from_inode(cinfo, inode);
}
void
nfs_mark_request_commit(struct nfs_page *req, struct pnfs_layout_segment *lseg,
struct nfs_commit_info *cinfo)
{
if (pnfs_mark_request_commit(req, lseg, cinfo))
return;
nfs_request_add_commit_list(req, &cinfo->mds->list, cinfo);
}
static void
nfs_clear_page_commit(struct page *page)
{
dec_zone_page_state(page, NR_UNSTABLE_NFS);
dec_bdi_stat(page_file_mapping(page)->backing_dev_info, BDI_RECLAIMABLE);
}
static void
nfs_clear_request_commit(struct nfs_page *req)
{
if (test_bit(PG_CLEAN, &req->wb_flags)) {
struct inode *inode = req->wb_context->dentry->d_inode;
struct nfs_commit_info cinfo;
nfs_init_cinfo_from_inode(&cinfo, inode);
if (!pnfs_clear_request_commit(req, &cinfo)) {
spin_lock(cinfo.lock);
nfs_request_remove_commit_list(req, &cinfo);
spin_unlock(cinfo.lock);
}
nfs_clear_page_commit(req->wb_page);
}
}
static inline
int nfs_write_need_commit(struct nfs_write_data *data)
{
if (data->verf.committed == NFS_DATA_SYNC)
return data->header->lseg == NULL;
return data->verf.committed != NFS_FILE_SYNC;
}
static void nfs_init_cinfo_from_inode(struct nfs_commit_info *cinfo,
struct inode *inode)
{
}
void nfs_init_cinfo(struct nfs_commit_info *cinfo,
struct inode *inode,
struct nfs_direct_req *dreq)
{
}
void
nfs_mark_request_commit(struct nfs_page *req, struct pnfs_layout_segment *lseg,
struct nfs_commit_info *cinfo)
{
}
static void
nfs_clear_request_commit(struct nfs_page *req)
{
}
static inline
int nfs_write_need_commit(struct nfs_write_data *data)
{
return 0;
}
static void nfs_write_completion(struct nfs_pgio_header *hdr)
{
struct nfs_commit_info cinfo;
unsigned long bytes = 0;
if (test_bit(NFS_IOHDR_REDO, &hdr->flags))
goto out;
nfs_init_cinfo_from_inode(&cinfo, hdr->inode);
while (!list_empty(&hdr->pages)) {
struct nfs_page *req = nfs_list_entry(hdr->pages.next);
bytes += req->wb_bytes;
nfs_list_remove_request(req);
if (test_bit(NFS_IOHDR_ERROR, &hdr->flags) &&
(hdr->good_bytes < bytes)) {
nfs_set_pageerror(req->wb_page);
nfs_context_set_write_error(req->wb_context, hdr->error);
goto remove_req;
}
if (test_bit(NFS_IOHDR_NEED_RESCHED, &hdr->flags)) {
nfs_mark_request_dirty(req);
goto next;
}
if (test_bit(NFS_IOHDR_NEED_COMMIT, &hdr->flags)) {
memcpy(&req->wb_verf, &hdr->verf->verifier, sizeof(req->wb_verf));
nfs_mark_request_commit(req, hdr->lseg, &cinfo);
goto next;
}
remove_req:
nfs_inode_remove_request(req);
next:
nfs_unlock_request(req);
nfs_end_page_writeback(req->wb_page);
nfs_release_request(req);
}
out:
hdr->release(hdr);
}
static unsigned long
nfs_reqs_to_commit(struct nfs_commit_info *cinfo)
{
return cinfo->mds->ncommit;
}
int
nfs_scan_commit_list(struct list_head *src, struct list_head *dst,
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
nfs_list_add_request(req, dst);
ret++;
if ((ret == max) && !cinfo->dreq)
break;
}
return ret;
}
int
nfs_scan_commit(struct inode *inode, struct list_head *dst,
struct nfs_commit_info *cinfo)
{
int ret = 0;
spin_lock(cinfo->lock);
if (cinfo->mds->ncommit > 0) {
const int max = INT_MAX;
ret = nfs_scan_commit_list(&cinfo->mds->list, dst,
cinfo, max);
ret += pnfs_scan_commit_lists(inode, cinfo, max - ret);
}
spin_unlock(cinfo->lock);
return ret;
}
static unsigned long nfs_reqs_to_commit(struct nfs_commit_info *cinfo)
{
return 0;
}
int nfs_scan_commit(struct inode *inode, struct list_head *dst,
struct nfs_commit_info *cinfo)
{
return 0;
}
static struct nfs_page *nfs_try_to_update_request(struct inode *inode,
struct page *page,
unsigned int offset,
unsigned int bytes)
{
struct nfs_page *req;
unsigned int rqend;
unsigned int end;
int error;
if (!PagePrivate(page))
return NULL;
end = offset + bytes;
spin_lock(&inode->i_lock);
for (;;) {
req = nfs_page_find_request_locked(NFS_I(inode), page);
if (req == NULL)
goto out_unlock;
rqend = req->wb_offset + req->wb_bytes;
if (offset > rqend
|| end < req->wb_offset)
goto out_flushme;
if (nfs_lock_request(req))
break;
spin_unlock(&inode->i_lock);
error = nfs_wait_on_request(req);
nfs_release_request(req);
if (error != 0)
goto out_err;
spin_lock(&inode->i_lock);
}
if (offset < req->wb_offset) {
req->wb_offset = offset;
req->wb_pgbase = offset;
}
if (end > rqend)
req->wb_bytes = end - req->wb_offset;
else
req->wb_bytes = rqend - req->wb_offset;
out_unlock:
spin_unlock(&inode->i_lock);
if (req)
nfs_clear_request_commit(req);
return req;
out_flushme:
spin_unlock(&inode->i_lock);
nfs_release_request(req);
error = nfs_wb_page(inode, page);
out_err:
return ERR_PTR(error);
}
static struct nfs_page * nfs_setup_write_request(struct nfs_open_context* ctx,
struct page *page, unsigned int offset, unsigned int bytes)
{
struct inode *inode = page_file_mapping(page)->host;
struct nfs_page *req;
req = nfs_try_to_update_request(inode, page, offset, bytes);
if (req != NULL)
goto out;
req = nfs_create_request(ctx, inode, page, offset, bytes);
if (IS_ERR(req))
goto out;
nfs_inode_add_request(inode, req);
out:
return req;
}
static int nfs_writepage_setup(struct nfs_open_context *ctx, struct page *page,
unsigned int offset, unsigned int count)
{
struct nfs_page *req;
req = nfs_setup_write_request(ctx, page, offset, count);
if (IS_ERR(req))
return PTR_ERR(req);
nfs_grow_file(page, offset, count);
nfs_mark_uptodate(page, req->wb_pgbase, req->wb_bytes);
nfs_mark_request_dirty(req);
nfs_unlock_and_release_request(req);
return 0;
}
int nfs_flush_incompatible(struct file *file, struct page *page)
{
struct nfs_open_context *ctx = nfs_file_open_context(file);
struct nfs_lock_context *l_ctx;
struct nfs_page *req;
int do_flush, status;
do {
req = nfs_page_find_request(page);
if (req == NULL)
return 0;
l_ctx = req->wb_lock_context;
do_flush = req->wb_page != page || req->wb_context != ctx;
if (l_ctx && ctx->dentry->d_inode->i_flock != NULL) {
do_flush |= l_ctx->lockowner.l_owner != current->files
|| l_ctx->lockowner.l_pid != current->tgid;
}
nfs_release_request(req);
if (!do_flush)
return 0;
status = nfs_wb_page(page_file_mapping(page)->host, page);
} while (status == 0);
return status;
}
int
nfs_key_timeout_notify(struct file *filp, struct inode *inode)
{
struct nfs_open_context *ctx = nfs_file_open_context(filp);
struct rpc_auth *auth = NFS_SERVER(inode)->client->cl_auth;
return rpcauth_key_timeout_notify(auth, ctx->cred);
}
bool nfs_ctx_key_to_expire(struct nfs_open_context *ctx)
{
return rpcauth_cred_key_to_expire(ctx->cred);
}
static bool nfs_write_pageuptodate(struct page *page, struct inode *inode)
{
if (nfs_have_delegated_attributes(inode))
goto out;
if (NFS_I(inode)->cache_validity & (NFS_INO_INVALID_DATA|NFS_INO_REVAL_PAGECACHE))
return false;
out:
return PageUptodate(page) != 0;
}
static int nfs_can_extend_write(struct file *file, struct page *page, struct inode *inode)
{
if (file->f_flags & O_DSYNC)
return 0;
if (NFS_PROTO(inode)->have_delegation(inode, FMODE_WRITE))
return 1;
if (nfs_write_pageuptodate(page, inode) && (inode->i_flock == NULL ||
(inode->i_flock->fl_start == 0 &&
inode->i_flock->fl_end == OFFSET_MAX &&
inode->i_flock->fl_type != F_RDLCK)))
return 1;
return 0;
}
int nfs_updatepage(struct file *file, struct page *page,
unsigned int offset, unsigned int count)
{
struct nfs_open_context *ctx = nfs_file_open_context(file);
struct inode *inode = page_file_mapping(page)->host;
int status = 0;
nfs_inc_stats(inode, NFSIOS_VFSUPDATEPAGE);
dprintk("NFS: nfs_updatepage(%s/%s %d@%lld)\n",
file->f_path.dentry->d_parent->d_name.name,
file->f_path.dentry->d_name.name, count,
(long long)(page_file_offset(page) + offset));
if (nfs_can_extend_write(file, page, inode)) {
count = max(count + offset, nfs_page_length(page));
offset = 0;
}
status = nfs_writepage_setup(ctx, page, offset, count);
if (status < 0)
nfs_set_pageerror(page);
else
__set_page_dirty_nobuffers(page);
dprintk("NFS: nfs_updatepage returns %d (isize %lld)\n",
status, (long long)i_size_read(inode));
return status;
}
static int flush_task_priority(int how)
{
switch (how & (FLUSH_HIGHPRI|FLUSH_LOWPRI)) {
case FLUSH_HIGHPRI:
return RPC_PRIORITY_HIGH;
case FLUSH_LOWPRI:
return RPC_PRIORITY_LOW;
}
return RPC_PRIORITY_NORMAL;
}
int nfs_initiate_write(struct rpc_clnt *clnt,
struct nfs_write_data *data,
const struct rpc_call_ops *call_ops,
int how, int flags)
{
struct inode *inode = data->header->inode;
int priority = flush_task_priority(how);
struct rpc_task *task;
struct rpc_message msg = {
.rpc_argp = &data->args,
.rpc_resp = &data->res,
.rpc_cred = data->header->cred,
};
struct rpc_task_setup task_setup_data = {
.rpc_client = clnt,
.task = &data->task,
.rpc_message = &msg,
.callback_ops = call_ops,
.callback_data = data,
.workqueue = nfsiod_workqueue,
.flags = RPC_TASK_ASYNC | flags,
.priority = priority,
};
int ret = 0;
NFS_PROTO(inode)->write_setup(data, &msg);
dprintk("NFS: %5u initiated write call "
"(req %s/%lld, %u bytes @ offset %llu)\n",
data->task.tk_pid,
inode->i_sb->s_id,
(long long)NFS_FILEID(inode),
data->args.count,
(unsigned long long)data->args.offset);
nfs4_state_protect_write(NFS_SERVER(inode)->nfs_client,
&task_setup_data.rpc_client, &msg, data);
task = rpc_run_task(&task_setup_data);
if (IS_ERR(task)) {
ret = PTR_ERR(task);
goto out;
}
if (how & FLUSH_SYNC) {
ret = rpc_wait_for_completion_task(task);
if (ret == 0)
ret = task->tk_status;
}
rpc_put_task(task);
out:
return ret;
}
static void nfs_write_rpcsetup(struct nfs_write_data *data,
unsigned int count, unsigned int offset,
int how, struct nfs_commit_info *cinfo)
{
struct nfs_page *req = data->header->req;
data->args.fh = NFS_FH(data->header->inode);
data->args.offset = req_offset(req) + offset;
data->mds_offset = data->args.offset;
data->args.pgbase = req->wb_pgbase + offset;
data->args.pages = data->pages.pagevec;
data->args.count = count;
data->args.context = get_nfs_open_context(req->wb_context);
data->args.lock_context = req->wb_lock_context;
data->args.stable = NFS_UNSTABLE;
switch (how & (FLUSH_STABLE | FLUSH_COND_STABLE)) {
case 0:
break;
case FLUSH_COND_STABLE:
if (nfs_reqs_to_commit(cinfo))
break;
default:
data->args.stable = NFS_FILE_SYNC;
}
data->res.fattr = &data->fattr;
data->res.count = count;
data->res.verf = &data->verf;
nfs_fattr_init(&data->fattr);
}
static int nfs_do_write(struct nfs_write_data *data,
const struct rpc_call_ops *call_ops,
int how)
{
struct inode *inode = data->header->inode;
return nfs_initiate_write(NFS_CLIENT(inode), data, call_ops, how, 0);
}
static int nfs_do_multiple_writes(struct list_head *head,
const struct rpc_call_ops *call_ops,
int how)
{
struct nfs_write_data *data;
int ret = 0;
while (!list_empty(head)) {
int ret2;
data = list_first_entry(head, struct nfs_write_data, list);
list_del_init(&data->list);
ret2 = nfs_do_write(data, call_ops, how);
if (ret == 0)
ret = ret2;
}
return ret;
}
static void nfs_redirty_request(struct nfs_page *req)
{
nfs_mark_request_dirty(req);
nfs_unlock_request(req);
nfs_end_page_writeback(req->wb_page);
nfs_release_request(req);
}
static void nfs_async_write_error(struct list_head *head)
{
struct nfs_page *req;
while (!list_empty(head)) {
req = nfs_list_entry(head->next);
nfs_list_remove_request(req);
nfs_redirty_request(req);
}
}
static void nfs_flush_error(struct nfs_pageio_descriptor *desc,
struct nfs_pgio_header *hdr)
{
set_bit(NFS_IOHDR_REDO, &hdr->flags);
while (!list_empty(&hdr->rpc_list)) {
struct nfs_write_data *data = list_first_entry(&hdr->rpc_list,
struct nfs_write_data, list);
list_del(&data->list);
nfs_writedata_release(data);
}
desc->pg_completion_ops->error_cleanup(&desc->pg_list);
}
static int nfs_flush_multi(struct nfs_pageio_descriptor *desc,
struct nfs_pgio_header *hdr)
{
struct nfs_page *req = hdr->req;
struct page *page = req->wb_page;
struct nfs_write_data *data;
size_t wsize = desc->pg_bsize, nbytes;
unsigned int offset;
int requests = 0;
struct nfs_commit_info cinfo;
nfs_init_cinfo(&cinfo, desc->pg_inode, desc->pg_dreq);
if ((desc->pg_ioflags & FLUSH_COND_STABLE) &&
(desc->pg_moreio || nfs_reqs_to_commit(&cinfo) ||
desc->pg_count > wsize))
desc->pg_ioflags &= ~FLUSH_COND_STABLE;
offset = 0;
nbytes = desc->pg_count;
do {
size_t len = min(nbytes, wsize);
data = nfs_writedata_alloc(hdr, 1);
if (!data) {
nfs_flush_error(desc, hdr);
return -ENOMEM;
}
data->pages.pagevec[0] = page;
nfs_write_rpcsetup(data, len, offset, desc->pg_ioflags, &cinfo);
list_add(&data->list, &hdr->rpc_list);
requests++;
nbytes -= len;
offset += len;
} while (nbytes != 0);
nfs_list_remove_request(req);
nfs_list_add_request(req, &hdr->pages);
desc->pg_rpc_callops = &nfs_write_common_ops;
return 0;
}
static int nfs_flush_one(struct nfs_pageio_descriptor *desc,
struct nfs_pgio_header *hdr)
{
struct nfs_page *req;
struct page **pages;
struct nfs_write_data *data;
struct list_head *head = &desc->pg_list;
struct nfs_commit_info cinfo;
data = nfs_writedata_alloc(hdr, nfs_page_array_len(desc->pg_base,
desc->pg_count));
if (!data) {
nfs_flush_error(desc, hdr);
return -ENOMEM;
}
nfs_init_cinfo(&cinfo, desc->pg_inode, desc->pg_dreq);
pages = data->pages.pagevec;
while (!list_empty(head)) {
req = nfs_list_entry(head->next);
nfs_list_remove_request(req);
nfs_list_add_request(req, &hdr->pages);
*pages++ = req->wb_page;
}
if ((desc->pg_ioflags & FLUSH_COND_STABLE) &&
(desc->pg_moreio || nfs_reqs_to_commit(&cinfo)))
desc->pg_ioflags &= ~FLUSH_COND_STABLE;
nfs_write_rpcsetup(data, desc->pg_count, 0, desc->pg_ioflags, &cinfo);
list_add(&data->list, &hdr->rpc_list);
desc->pg_rpc_callops = &nfs_write_common_ops;
return 0;
}
int nfs_generic_flush(struct nfs_pageio_descriptor *desc,
struct nfs_pgio_header *hdr)
{
if (desc->pg_bsize < PAGE_CACHE_SIZE)
return nfs_flush_multi(desc, hdr);
return nfs_flush_one(desc, hdr);
}
static int nfs_generic_pg_writepages(struct nfs_pageio_descriptor *desc)
{
struct nfs_write_header *whdr;
struct nfs_pgio_header *hdr;
int ret;
whdr = nfs_writehdr_alloc();
if (!whdr) {
desc->pg_completion_ops->error_cleanup(&desc->pg_list);
return -ENOMEM;
}
hdr = &whdr->header;
nfs_pgheader_init(desc, hdr, nfs_writehdr_free);
atomic_inc(&hdr->refcnt);
ret = nfs_generic_flush(desc, hdr);
if (ret == 0)
ret = nfs_do_multiple_writes(&hdr->rpc_list,
desc->pg_rpc_callops,
desc->pg_ioflags);
if (atomic_dec_and_test(&hdr->refcnt))
hdr->completion_ops->completion(hdr);
return ret;
}
void nfs_pageio_init_write(struct nfs_pageio_descriptor *pgio,
struct inode *inode, int ioflags,
const struct nfs_pgio_completion_ops *compl_ops)
{
nfs_pageio_init(pgio, inode, &nfs_pageio_write_ops, compl_ops,
NFS_SERVER(inode)->wsize, ioflags);
}
void nfs_pageio_reset_write_mds(struct nfs_pageio_descriptor *pgio)
{
pgio->pg_ops = &nfs_pageio_write_ops;
pgio->pg_bsize = NFS_SERVER(pgio->pg_inode)->wsize;
}
void nfs_write_prepare(struct rpc_task *task, void *calldata)
{
struct nfs_write_data *data = calldata;
int err;
err = NFS_PROTO(data->header->inode)->write_rpc_prepare(task, data);
if (err)
rpc_exit(task, err);
}
void nfs_commit_prepare(struct rpc_task *task, void *calldata)
{
struct nfs_commit_data *data = calldata;
NFS_PROTO(data->inode)->commit_rpc_prepare(task, data);
}
static void nfs_writeback_done_common(struct rpc_task *task, void *calldata)
{
struct nfs_write_data *data = calldata;
nfs_writeback_done(task, data);
}
static void nfs_writeback_release_common(void *calldata)
{
struct nfs_write_data *data = calldata;
struct nfs_pgio_header *hdr = data->header;
int status = data->task.tk_status;
if ((status >= 0) && nfs_write_need_commit(data)) {
spin_lock(&hdr->lock);
if (test_bit(NFS_IOHDR_NEED_RESCHED, &hdr->flags))
;
else if (!test_and_set_bit(NFS_IOHDR_NEED_COMMIT, &hdr->flags))
memcpy(hdr->verf, &data->verf, sizeof(*hdr->verf));
else if (memcmp(hdr->verf, &data->verf, sizeof(*hdr->verf)))
set_bit(NFS_IOHDR_NEED_RESCHED, &hdr->flags);
spin_unlock(&hdr->lock);
}
nfs_writedata_release(data);
}
void nfs_writeback_done(struct rpc_task *task, struct nfs_write_data *data)
{
struct nfs_writeargs *argp = &data->args;
struct nfs_writeres *resp = &data->res;
struct inode *inode = data->header->inode;
int status;
dprintk("NFS: %5u nfs_writeback_done (status %d)\n",
task->tk_pid, task->tk_status);
status = NFS_PROTO(inode)->write_done(task, data);
if (status != 0)
return;
nfs_add_stats(inode, NFSIOS_SERVERWRITTENBYTES, resp->count);
#if IS_ENABLED(CONFIG_NFS_V3) || IS_ENABLED(CONFIG_NFS_V4)
if (resp->verf->committed < argp->stable && task->tk_status >= 0) {
static unsigned long complain;
if (time_before(complain, jiffies)) {
dprintk("NFS: faulty NFS server %s:"
" (committed = %d) != (stable = %d)\n",
NFS_SERVER(inode)->nfs_client->cl_hostname,
resp->verf->committed, argp->stable);
complain = jiffies + 300 * HZ;
}
}
#endif
if (task->tk_status < 0)
nfs_set_pgio_error(data->header, task->tk_status, argp->offset);
else if (resp->count < argp->count) {
static unsigned long complain;
nfs_inc_stats(inode, NFSIOS_SHORTWRITE);
if (resp->count == 0) {
if (time_before(complain, jiffies)) {
printk(KERN_WARNING
"NFS: Server wrote zero bytes, expected %u.\n",
argp->count);
complain = jiffies + 300 * HZ;
}
nfs_set_pgio_error(data->header, -EIO, argp->offset);
task->tk_status = -EIO;
return;
}
if (resp->verf->committed != NFS_UNSTABLE) {
data->mds_offset += resp->count;
argp->offset += resp->count;
argp->pgbase += resp->count;
argp->count -= resp->count;
} else {
argp->stable = NFS_FILE_SYNC;
}
rpc_restart_call_prepare(task);
}
}
static int nfs_commit_set_lock(struct nfs_inode *nfsi, int may_wait)
{
int ret;
if (!test_and_set_bit(NFS_INO_COMMIT, &nfsi->flags))
return 1;
if (!may_wait)
return 0;
ret = out_of_line_wait_on_bit_lock(&nfsi->flags,
NFS_INO_COMMIT,
nfs_wait_bit_killable,
TASK_KILLABLE);
return (ret < 0) ? ret : 1;
}
static void nfs_commit_clear_lock(struct nfs_inode *nfsi)
{
clear_bit(NFS_INO_COMMIT, &nfsi->flags);
smp_mb__after_clear_bit();
wake_up_bit(&nfsi->flags, NFS_INO_COMMIT);
}
void nfs_commitdata_release(struct nfs_commit_data *data)
{
put_nfs_open_context(data->context);
nfs_commit_free(data);
}
int nfs_initiate_commit(struct rpc_clnt *clnt, struct nfs_commit_data *data,
const struct rpc_call_ops *call_ops,
int how, int flags)
{
struct rpc_task *task;
int priority = flush_task_priority(how);
struct rpc_message msg = {
.rpc_argp = &data->args,
.rpc_resp = &data->res,
.rpc_cred = data->cred,
};
struct rpc_task_setup task_setup_data = {
.task = &data->task,
.rpc_client = clnt,
.rpc_message = &msg,
.callback_ops = call_ops,
.callback_data = data,
.workqueue = nfsiod_workqueue,
.flags = RPC_TASK_ASYNC | flags,
.priority = priority,
};
NFS_PROTO(data->inode)->commit_setup(data, &msg);
dprintk("NFS: %5u initiated commit call\n", data->task.tk_pid);
nfs4_state_protect(NFS_SERVER(data->inode)->nfs_client,
NFS_SP4_MACH_CRED_COMMIT, &task_setup_data.rpc_client, &msg);
task = rpc_run_task(&task_setup_data);
if (IS_ERR(task))
return PTR_ERR(task);
if (how & FLUSH_SYNC)
rpc_wait_for_completion_task(task);
rpc_put_task(task);
return 0;
}
void nfs_init_commit(struct nfs_commit_data *data,
struct list_head *head,
struct pnfs_layout_segment *lseg,
struct nfs_commit_info *cinfo)
{
struct nfs_page *first = nfs_list_entry(head->next);
struct inode *inode = first->wb_context->dentry->d_inode;
list_splice_init(head, &data->pages);
data->inode = inode;
data->cred = first->wb_context->cred;
data->lseg = lseg;
data->mds_ops = &nfs_commit_ops;
data->completion_ops = cinfo->completion_ops;
data->dreq = cinfo->dreq;
data->args.fh = NFS_FH(data->inode);
data->args.offset = 0;
data->args.count = 0;
data->context = get_nfs_open_context(first->wb_context);
data->res.fattr = &data->fattr;
data->res.verf = &data->verf;
nfs_fattr_init(&data->fattr);
}
void nfs_retry_commit(struct list_head *page_list,
struct pnfs_layout_segment *lseg,
struct nfs_commit_info *cinfo)
{
struct nfs_page *req;
while (!list_empty(page_list)) {
req = nfs_list_entry(page_list->next);
nfs_list_remove_request(req);
nfs_mark_request_commit(req, lseg, cinfo);
if (!cinfo->dreq) {
dec_zone_page_state(req->wb_page, NR_UNSTABLE_NFS);
dec_bdi_stat(page_file_mapping(req->wb_page)->backing_dev_info,
BDI_RECLAIMABLE);
}
nfs_unlock_and_release_request(req);
}
}
static int
nfs_commit_list(struct inode *inode, struct list_head *head, int how,
struct nfs_commit_info *cinfo)
{
struct nfs_commit_data *data;
data = nfs_commitdata_alloc();
if (!data)
goto out_bad;
nfs_init_commit(data, head, NULL, cinfo);
atomic_inc(&cinfo->mds->rpcs_out);
return nfs_initiate_commit(NFS_CLIENT(inode), data, data->mds_ops,
how, 0);
out_bad:
nfs_retry_commit(head, NULL, cinfo);
cinfo->completion_ops->error_cleanup(NFS_I(inode));
return -ENOMEM;
}
static void nfs_commit_done(struct rpc_task *task, void *calldata)
{
struct nfs_commit_data *data = calldata;
dprintk("NFS: %5u nfs_commit_done (status %d)\n",
task->tk_pid, task->tk_status);
NFS_PROTO(data->inode)->commit_done(task, data);
}
static void nfs_commit_release_pages(struct nfs_commit_data *data)
{
struct nfs_page *req;
int status = data->task.tk_status;
struct nfs_commit_info cinfo;
while (!list_empty(&data->pages)) {
req = nfs_list_entry(data->pages.next);
nfs_list_remove_request(req);
nfs_clear_page_commit(req->wb_page);
dprintk("NFS: commit (%s/%lld %d@%lld)",
req->wb_context->dentry->d_sb->s_id,
(long long)NFS_FILEID(req->wb_context->dentry->d_inode),
req->wb_bytes,
(long long)req_offset(req));
if (status < 0) {
nfs_context_set_write_error(req->wb_context, status);
nfs_inode_remove_request(req);
dprintk(", error = %d\n", status);
goto next;
}
if (!memcmp(&req->wb_verf, &data->verf.verifier, sizeof(req->wb_verf))) {
nfs_inode_remove_request(req);
dprintk(" OK\n");
goto next;
}
dprintk(" mismatch\n");
nfs_mark_request_dirty(req);
set_bit(NFS_CONTEXT_RESEND_WRITES, &req->wb_context->flags);
next:
nfs_unlock_and_release_request(req);
}
nfs_init_cinfo(&cinfo, data->inode, data->dreq);
if (atomic_dec_and_test(&cinfo.mds->rpcs_out))
nfs_commit_clear_lock(NFS_I(data->inode));
}
static void nfs_commit_release(void *calldata)
{
struct nfs_commit_data *data = calldata;
data->completion_ops->completion(data);
nfs_commitdata_release(calldata);
}
int nfs_generic_commit_list(struct inode *inode, struct list_head *head,
int how, struct nfs_commit_info *cinfo)
{
int status;
status = pnfs_commit_list(inode, head, how, cinfo);
if (status == PNFS_NOT_ATTEMPTED)
status = nfs_commit_list(inode, head, how, cinfo);
return status;
}
int nfs_commit_inode(struct inode *inode, int how)
{
LIST_HEAD(head);
struct nfs_commit_info cinfo;
int may_wait = how & FLUSH_SYNC;
int res;
res = nfs_commit_set_lock(NFS_I(inode), may_wait);
if (res <= 0)
goto out_mark_dirty;
nfs_init_cinfo_from_inode(&cinfo, inode);
res = nfs_scan_commit(inode, &head, &cinfo);
if (res) {
int error;
error = nfs_generic_commit_list(inode, &head, how, &cinfo);
if (error < 0)
return error;
if (!may_wait)
goto out_mark_dirty;
error = wait_on_bit(&NFS_I(inode)->flags,
NFS_INO_COMMIT,
nfs_wait_bit_killable,
TASK_KILLABLE);
if (error < 0)
return error;
} else
nfs_commit_clear_lock(NFS_I(inode));
return res;
out_mark_dirty:
__mark_inode_dirty(inode, I_DIRTY_DATASYNC);
return res;
}
static int nfs_commit_unstable_pages(struct inode *inode, struct writeback_control *wbc)
{
struct nfs_inode *nfsi = NFS_I(inode);
int flags = FLUSH_SYNC;
int ret = 0;
if (!nfsi->commit_info.ncommit)
return ret;
if (wbc->sync_mode == WB_SYNC_NONE) {
if (nfsi->commit_info.ncommit <= (nfsi->npages >> 1))
goto out_mark_dirty;
flags = 0;
}
ret = nfs_commit_inode(inode, flags);
if (ret >= 0) {
if (wbc->sync_mode == WB_SYNC_NONE) {
if (ret < wbc->nr_to_write)
wbc->nr_to_write -= ret;
else
wbc->nr_to_write = 0;
}
return 0;
}
out_mark_dirty:
__mark_inode_dirty(inode, I_DIRTY_DATASYNC);
return ret;
}
static int nfs_commit_unstable_pages(struct inode *inode, struct writeback_control *wbc)
{
return 0;
}
int nfs_write_inode(struct inode *inode, struct writeback_control *wbc)
{
return nfs_commit_unstable_pages(inode, wbc);
}
int nfs_wb_all(struct inode *inode)
{
struct writeback_control wbc = {
.sync_mode = WB_SYNC_ALL,
.nr_to_write = LONG_MAX,
.range_start = 0,
.range_end = LLONG_MAX,
};
int ret;
trace_nfs_writeback_inode_enter(inode);
ret = sync_inode(inode, &wbc);
trace_nfs_writeback_inode_exit(inode, ret);
return ret;
}
int nfs_wb_page_cancel(struct inode *inode, struct page *page)
{
struct nfs_page *req;
int ret = 0;
for (;;) {
wait_on_page_writeback(page);
req = nfs_page_find_request(page);
if (req == NULL)
break;
if (nfs_lock_request(req)) {
nfs_clear_request_commit(req);
nfs_inode_remove_request(req);
cancel_dirty_page(page, PAGE_CACHE_SIZE);
nfs_unlock_and_release_request(req);
break;
}
ret = nfs_wait_on_request(req);
nfs_release_request(req);
if (ret < 0)
break;
}
return ret;
}
int nfs_wb_page(struct inode *inode, struct page *page)
{
loff_t range_start = page_file_offset(page);
loff_t range_end = range_start + (loff_t)(PAGE_CACHE_SIZE - 1);
struct writeback_control wbc = {
.sync_mode = WB_SYNC_ALL,
.nr_to_write = 0,
.range_start = range_start,
.range_end = range_end,
};
int ret;
trace_nfs_writeback_page_enter(inode);
for (;;) {
wait_on_page_writeback(page);
if (clear_page_dirty_for_io(page)) {
ret = nfs_writepage_locked(page, &wbc);
if (ret < 0)
goto out_error;
continue;
}
ret = 0;
if (!PagePrivate(page))
break;
ret = nfs_commit_inode(inode, FLUSH_SYNC);
if (ret < 0)
goto out_error;
}
out_error:
trace_nfs_writeback_page_exit(inode, ret);
return ret;
}
int nfs_migrate_page(struct address_space *mapping, struct page *newpage,
struct page *page, enum migrate_mode mode)
{
if (PagePrivate(page))
return -EBUSY;
if (!nfs_fscache_release_page(page, GFP_KERNEL))
return -EBUSY;
return migrate_page(mapping, newpage, page, mode);
}
int __init nfs_init_writepagecache(void)
{
nfs_wdata_cachep = kmem_cache_create("nfs_write_data",
sizeof(struct nfs_write_header),
0, SLAB_HWCACHE_ALIGN,
NULL);
if (nfs_wdata_cachep == NULL)
return -ENOMEM;
nfs_wdata_mempool = mempool_create_slab_pool(MIN_POOL_WRITE,
nfs_wdata_cachep);
if (nfs_wdata_mempool == NULL)
goto out_destroy_write_cache;
nfs_cdata_cachep = kmem_cache_create("nfs_commit_data",
sizeof(struct nfs_commit_data),
0, SLAB_HWCACHE_ALIGN,
NULL);
if (nfs_cdata_cachep == NULL)
goto out_destroy_write_mempool;
nfs_commit_mempool = mempool_create_slab_pool(MIN_POOL_COMMIT,
nfs_cdata_cachep);
if (nfs_commit_mempool == NULL)
goto out_destroy_commit_cache;
nfs_congestion_kb = (16*int_sqrt(totalram_pages)) << (PAGE_SHIFT-10);
if (nfs_congestion_kb > 256*1024)
nfs_congestion_kb = 256*1024;
return 0;
out_destroy_commit_cache:
kmem_cache_destroy(nfs_cdata_cachep);
out_destroy_write_mempool:
mempool_destroy(nfs_wdata_mempool);
out_destroy_write_cache:
kmem_cache_destroy(nfs_wdata_cachep);
return -ENOMEM;
}
void nfs_destroy_writepagecache(void)
{
mempool_destroy(nfs_commit_mempool);
kmem_cache_destroy(nfs_cdata_cachep);
mempool_destroy(nfs_wdata_mempool);
kmem_cache_destroy(nfs_wdata_cachep);
}
