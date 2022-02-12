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
static struct nfs_pgio_header *nfs_writehdr_alloc(void)
{
struct nfs_pgio_header *p = mempool_alloc(nfs_wdata_mempool, GFP_NOIO);
if (p)
memset(p, 0, sizeof(*p));
return p;
}
static void nfs_writehdr_free(struct nfs_pgio_header *hdr)
{
mempool_free(hdr, nfs_wdata_mempool);
}
static void nfs_context_set_write_error(struct nfs_open_context *ctx, int error)
{
ctx->error = error;
smp_wmb();
set_bit(NFS_CONTEXT_ERROR_WRITE, &ctx->flags);
}
static struct nfs_page *
nfs_page_find_head_request_locked(struct nfs_inode *nfsi, struct page *page)
{
struct nfs_page *req = NULL;
if (PagePrivate(page))
req = (struct nfs_page *)page_private(page);
else if (unlikely(PageSwapCache(page)))
req = nfs_page_search_commits_for_head_request_locked(nfsi,
page);
if (req) {
WARN_ON_ONCE(req->wb_head != req);
kref_get(&req->wb_kref);
}
return req;
}
static struct nfs_page *nfs_page_find_head_request(struct page *page)
{
struct inode *inode = page_file_mapping(page)->host;
struct nfs_page *req = NULL;
spin_lock(&inode->i_lock);
req = nfs_page_find_head_request_locked(NFS_I(inode), page);
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
static struct nfs_page *
nfs_page_group_search_locked(struct nfs_page *head, unsigned int page_offset)
{
struct nfs_page *req;
WARN_ON_ONCE(head != head->wb_head);
WARN_ON_ONCE(!test_bit(PG_HEADLOCK, &head->wb_head->wb_flags));
req = head;
do {
if (page_offset >= req->wb_pgbase &&
page_offset < (req->wb_pgbase + req->wb_bytes))
return req;
req = req->wb_this_page;
} while (req != head);
return NULL;
}
static bool nfs_page_group_covers_page(struct nfs_page *req)
{
struct nfs_page *tmp;
unsigned int pos = 0;
unsigned int len = nfs_page_length(req->wb_page);
nfs_page_group_lock(req, false);
do {
tmp = nfs_page_group_search_locked(req->wb_head, pos);
if (tmp) {
WARN_ON_ONCE(tmp->wb_pgbase != pos);
pos += tmp->wb_bytes - (pos - tmp->wb_pgbase);
}
} while (tmp && pos < len);
nfs_page_group_unlock(req);
WARN_ON_ONCE(pos > len);
return pos == len;
}
static void nfs_mark_uptodate(struct nfs_page *req)
{
if (PageUptodate(req->wb_page))
return;
if (!nfs_page_group_covers_page(req))
return;
SetPageUptodate(req->wb_page);
}
static int wb_priority(struct writeback_control *wbc)
{
int ret = 0;
if (wbc->for_reclaim)
return FLUSH_HIGHPRI | FLUSH_STABLE;
if (wbc->sync_mode == WB_SYNC_ALL)
ret = FLUSH_COND_STABLE;
if (wbc->for_kupdate || wbc->for_background)
ret |= FLUSH_LOWPRI;
return ret;
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
static void nfs_end_page_writeback(struct nfs_page *req)
{
struct inode *inode = page_file_mapping(req->wb_page)->host;
struct nfs_server *nfss = NFS_SERVER(inode);
if (!nfs_page_group_sync_on_bit(req, PG_WB_END))
return;
end_page_writeback(req->wb_page);
if (atomic_long_dec_return(&nfss->writeback) < NFS_CONGESTION_OFF_THRESH)
clear_bdi_congested(&nfss->backing_dev_info, BLK_RW_ASYNC);
}
static void
nfs_page_group_clear_bits(struct nfs_page *req)
{
clear_bit(PG_TEARDOWN, &req->wb_flags);
clear_bit(PG_UNLOCKPAGE, &req->wb_flags);
clear_bit(PG_UPTODATE, &req->wb_flags);
clear_bit(PG_WB_END, &req->wb_flags);
clear_bit(PG_REMOVE, &req->wb_flags);
}
static int
nfs_unroll_locks_and_wait(struct inode *inode, struct nfs_page *head,
struct nfs_page *req, bool nonblock)
__releases(&inode->i_lock
static void
nfs_destroy_unlinked_subrequests(struct nfs_page *destroy_list,
struct nfs_page *old_head)
{
while (destroy_list) {
struct nfs_page *subreq = destroy_list;
destroy_list = (subreq->wb_this_page == old_head) ?
NULL : subreq->wb_this_page;
WARN_ON_ONCE(old_head != subreq->wb_head);
subreq->wb_head = subreq;
subreq->wb_this_page = subreq;
nfs_unlock_request(subreq);
if (!test_bit(PG_TEARDOWN, &subreq->wb_flags)) {
nfs_release_request(old_head);
nfs_page_group_clear_bits(subreq);
if (test_and_clear_bit(PG_INODE_REF, &subreq->wb_flags))
nfs_release_request(subreq);
else
WARN_ON_ONCE(1);
} else {
WARN_ON_ONCE(test_bit(PG_CLEAN, &subreq->wb_flags));
nfs_page_group_clear_bits(subreq);
nfs_free_request(subreq);
}
}
}
static struct nfs_page *
nfs_lock_and_join_requests(struct page *page, bool nonblock)
{
struct inode *inode = page_file_mapping(page)->host;
struct nfs_page *head, *subreq;
struct nfs_page *destroy_list = NULL;
unsigned int total_bytes;
int ret;
try_again:
total_bytes = 0;
WARN_ON_ONCE(destroy_list);
spin_lock(&inode->i_lock);
head = nfs_page_find_head_request_locked(NFS_I(inode), page);
if (!head) {
spin_unlock(&inode->i_lock);
return NULL;
}
ret = nfs_page_group_lock(head, true);
if (ret < 0) {
spin_unlock(&inode->i_lock);
if (!nonblock && ret == -EAGAIN) {
nfs_page_group_lock_wait(head);
nfs_release_request(head);
goto try_again;
}
nfs_release_request(head);
return ERR_PTR(ret);
}
subreq = head;
do {
if (subreq->wb_offset == (head->wb_offset + total_bytes)) {
total_bytes += subreq->wb_bytes;
} else if (WARN_ON_ONCE(subreq->wb_offset < head->wb_offset ||
((subreq->wb_offset + subreq->wb_bytes) >
(head->wb_offset + total_bytes)))) {
nfs_page_group_unlock(head);
spin_unlock(&inode->i_lock);
return ERR_PTR(-EIO);
}
if (!nfs_lock_request(subreq)) {
ret = nfs_unroll_locks_and_wait(inode, head,
subreq, nonblock);
if (ret == 0)
goto try_again;
return ERR_PTR(ret);
}
subreq = subreq->wb_this_page;
} while (subreq != head);
subreq = head;
do {
nfs_clear_request_commit(subreq);
subreq = subreq->wb_this_page;
} while (subreq != head);
if (head->wb_this_page != head) {
destroy_list = head->wb_this_page;
head->wb_this_page = head;
head->wb_bytes = total_bytes;
}
nfs_page_group_clear_bits(head);
if (!test_and_set_bit(PG_INODE_REF, &head->wb_flags))
kref_get(&head->wb_kref);
nfs_page_group_unlock(head);
spin_unlock(&inode->i_lock);
nfs_destroy_unlinked_subrequests(destroy_list, head);
return head;
}
static int nfs_page_async_flush(struct nfs_pageio_descriptor *pgio,
struct page *page, bool nonblock)
{
struct nfs_page *req;
int ret = 0;
req = nfs_lock_and_join_requests(page, nonblock);
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
} else
nfs_add_stats(page_file_mapping(page)->host,
NFSIOS_WRITEPAGES, 1);
out:
return ret;
}
static int nfs_do_writepage(struct page *page, struct writeback_control *wbc, struct nfs_pageio_descriptor *pgio)
{
int ret;
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
struct inode *inode = page_file_mapping(page)->host;
int err;
nfs_inc_stats(inode, NFSIOS_VFSWRITEPAGE);
nfs_pageio_init_write(&pgio, inode, wb_priority(wbc),
false, &nfs_async_write_completion_ops);
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
err = wait_on_bit_lock_action(bitlock, NFS_INO_FLUSHING,
nfs_wait_bit_killable, TASK_KILLABLE);
if (err)
goto out_err;
nfs_inc_stats(inode, NFSIOS_VFSWRITEPAGES);
nfs_pageio_init_write(&pgio, inode, wb_priority(wbc), false,
&nfs_async_write_completion_ops);
err = write_cache_pages(mapping, wbc, nfs_writepages_callback, &pgio);
nfs_pageio_complete(&pgio);
clear_bit_unlock(NFS_INO_FLUSHING, bitlock);
smp_mb__after_atomic();
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
WARN_ON_ONCE(req->wb_this_page != req);
nfs_lock_request(req);
spin_lock(&inode->i_lock);
if (!nfsi->nrequests &&
NFS_PROTO(inode)->have_delegation(inode, FMODE_WRITE))
inode->i_version++;
if (likely(!PageSwapCache(req->wb_page))) {
set_bit(PG_MAPPED, &req->wb_flags);
SetPagePrivate(req->wb_page);
set_page_private(req->wb_page, (unsigned long)req);
}
nfsi->nrequests++;
WARN_ON(test_and_set_bit(PG_INODE_REF, &req->wb_flags));
kref_get(&req->wb_kref);
spin_unlock(&inode->i_lock);
}
static void nfs_inode_remove_request(struct nfs_page *req)
{
struct inode *inode = d_inode(req->wb_context->dentry);
struct nfs_inode *nfsi = NFS_I(inode);
struct nfs_page *head;
if (nfs_page_group_sync_on_bit(req, PG_REMOVE)) {
head = req->wb_head;
spin_lock(&inode->i_lock);
if (likely(!PageSwapCache(head->wb_page))) {
set_page_private(head->wb_page, 0);
ClearPagePrivate(head->wb_page);
smp_mb__after_atomic();
wake_up_page(head->wb_page, PG_private);
clear_bit(PG_MAPPED, &head->wb_flags);
}
nfsi->nrequests--;
spin_unlock(&inode->i_lock);
} else {
spin_lock(&inode->i_lock);
nfsi->nrequests--;
spin_unlock(&inode->i_lock);
}
if (test_and_clear_bit(PG_INODE_REF, &req->wb_flags))
nfs_release_request(req);
}
static void
nfs_mark_request_dirty(struct nfs_page *req)
{
__set_page_dirty_nobuffers(req->wb_page);
}
static struct nfs_page *
nfs_page_search_commits_for_head_request_locked(struct nfs_inode *nfsi,
struct page *page)
{
struct nfs_page *freq, *t;
struct nfs_commit_info cinfo;
struct inode *inode = &nfsi->vfs_inode;
nfs_init_cinfo_from_inode(&cinfo, inode);
freq = pnfs_search_commit_reqs(inode, &cinfo, page);
if (freq)
return freq->wb_head;
list_for_each_entry_safe(freq, t, &cinfo.mds->list, wb_list) {
if (freq->wb_page == page)
return freq->wb_head;
}
return NULL;
}
void
nfs_request_add_commit_list_locked(struct nfs_page *req, struct list_head *dst,
struct nfs_commit_info *cinfo)
{
set_bit(PG_CLEAN, &req->wb_flags);
nfs_list_add_request(req, dst);
cinfo->mds->ncommit++;
}
void
nfs_request_add_commit_list(struct nfs_page *req, struct list_head *dst,
struct nfs_commit_info *cinfo)
{
spin_lock(cinfo->lock);
nfs_request_add_commit_list_locked(req, dst, cinfo);
spin_unlock(cinfo->lock);
nfs_mark_page_unstable(req->wb_page, cinfo);
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
struct nfs_commit_info *cinfo, u32 ds_commit_idx)
{
if (pnfs_mark_request_commit(req, lseg, cinfo, ds_commit_idx))
return;
nfs_request_add_commit_list(req, &cinfo->mds->list, cinfo);
}
static void
nfs_clear_page_commit(struct page *page)
{
dec_zone_page_state(page, NR_UNSTABLE_NFS);
dec_wb_stat(&inode_to_bdi(page_file_mapping(page)->host)->wb,
WB_RECLAIMABLE);
}
static void
nfs_clear_request_commit(struct nfs_page *req)
{
if (test_bit(PG_CLEAN, &req->wb_flags)) {
struct inode *inode = d_inode(req->wb_context->dentry);
struct nfs_commit_info cinfo;
nfs_init_cinfo_from_inode(&cinfo, inode);
if (!pnfs_clear_request_commit(req, &cinfo)) {
nfs_request_remove_commit_list(req, &cinfo);
}
nfs_clear_page_commit(req->wb_page);
}
}
int nfs_write_need_commit(struct nfs_pgio_header *hdr)
{
if (hdr->verf.committed == NFS_DATA_SYNC)
return hdr->lseg == NULL;
return hdr->verf.committed != NFS_FILE_SYNC;
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
if (nfs_write_need_commit(hdr)) {
memcpy(&req->wb_verf, &hdr->verf.verifier, sizeof(req->wb_verf));
nfs_mark_request_commit(req, hdr->lseg, &cinfo,
hdr->pgio_mirror_idx);
goto next;
}
remove_req:
nfs_inode_remove_request(req);
next:
nfs_unlock_request(req);
nfs_end_page_writeback(req);
nfs_release_request(req);
}
out:
hdr->release(hdr);
}
unsigned long
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
req = nfs_page_find_head_request_locked(NFS_I(inode), page);
if (req == NULL)
goto out_unlock;
WARN_ON_ONCE(req->wb_head != req);
WARN_ON_ONCE(req->wb_this_page != req);
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
if (req)
nfs_clear_request_commit(req);
spin_unlock(&inode->i_lock);
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
req = nfs_create_request(ctx, page, NULL, offset, bytes);
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
nfs_mark_uptodate(req);
nfs_mark_request_dirty(req);
nfs_unlock_and_release_request(req);
return 0;
}
int nfs_flush_incompatible(struct file *file, struct page *page)
{
struct nfs_open_context *ctx = nfs_file_open_context(file);
struct nfs_lock_context *l_ctx;
struct file_lock_context *flctx = file_inode(file)->i_flctx;
struct nfs_page *req;
int do_flush, status;
do {
req = nfs_page_find_head_request(page);
if (req == NULL)
return 0;
l_ctx = req->wb_lock_context;
do_flush = req->wb_page != page || req->wb_context != ctx;
do_flush |= req->wb_this_page != req;
if (l_ctx && flctx &&
!(list_empty_careful(&flctx->flc_posix) &&
list_empty_careful(&flctx->flc_flock))) {
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
struct nfs_inode *nfsi = NFS_I(inode);
if (nfs_have_delegated_attributes(inode))
goto out;
if (nfsi->cache_validity & NFS_INO_REVAL_PAGECACHE)
return false;
smp_rmb();
if (test_bit(NFS_INO_INVALIDATING, &nfsi->flags))
return false;
out:
if (nfsi->cache_validity & NFS_INO_INVALID_DATA)
return false;
return PageUptodate(page) != 0;
}
static bool
is_whole_file_wrlock(struct file_lock *fl)
{
return fl->fl_start == 0 && fl->fl_end == OFFSET_MAX &&
fl->fl_type == F_WRLCK;
}
static int nfs_can_extend_write(struct file *file, struct page *page, struct inode *inode)
{
int ret;
struct file_lock_context *flctx = inode->i_flctx;
struct file_lock *fl;
if (file->f_flags & O_DSYNC)
return 0;
if (!nfs_write_pageuptodate(page, inode))
return 0;
if (NFS_PROTO(inode)->have_delegation(inode, FMODE_WRITE))
return 1;
if (!flctx || (list_empty_careful(&flctx->flc_flock) &&
list_empty_careful(&flctx->flc_posix)))
return 1;
ret = 0;
spin_lock(&flctx->flc_lock);
if (!list_empty(&flctx->flc_posix)) {
fl = list_first_entry(&flctx->flc_posix, struct file_lock,
fl_list);
if (is_whole_file_wrlock(fl))
ret = 1;
} else if (!list_empty(&flctx->flc_flock)) {
fl = list_first_entry(&flctx->flc_flock, struct file_lock,
fl_list);
if (fl->fl_type == F_WRLCK)
ret = 1;
}
spin_unlock(&flctx->flc_lock);
return ret;
}
int nfs_updatepage(struct file *file, struct page *page,
unsigned int offset, unsigned int count)
{
struct nfs_open_context *ctx = nfs_file_open_context(file);
struct inode *inode = page_file_mapping(page)->host;
int status = 0;
nfs_inc_stats(inode, NFSIOS_VFSUPDATEPAGE);
dprintk("NFS: nfs_updatepage(%pD2 %d@%lld)\n",
file, count, (long long)(page_file_offset(page) + offset));
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
static void nfs_initiate_write(struct nfs_pgio_header *hdr,
struct rpc_message *msg,
const struct nfs_rpc_ops *rpc_ops,
struct rpc_task_setup *task_setup_data, int how)
{
int priority = flush_task_priority(how);
task_setup_data->priority = priority;
rpc_ops->write_setup(hdr, msg);
nfs4_state_protect_write(NFS_SERVER(hdr->inode)->nfs_client,
&task_setup_data->rpc_client, msg, hdr);
}
static void nfs_redirty_request(struct nfs_page *req)
{
nfs_mark_request_dirty(req);
set_bit(NFS_CONTEXT_RESEND_WRITES, &req->wb_context->flags);
nfs_unlock_request(req);
nfs_end_page_writeback(req);
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
void nfs_pageio_init_write(struct nfs_pageio_descriptor *pgio,
struct inode *inode, int ioflags, bool force_mds,
const struct nfs_pgio_completion_ops *compl_ops)
{
struct nfs_server *server = NFS_SERVER(inode);
const struct nfs_pageio_ops *pg_ops = &nfs_pgio_rw_ops;
#ifdef CONFIG_NFS_V4_1
if (server->pnfs_curr_ld && !force_mds)
pg_ops = server->pnfs_curr_ld->pg_write_ops;
#endif
nfs_pageio_init(pgio, inode, pg_ops, compl_ops, &nfs_rw_write_ops,
server->wsize, ioflags);
}
void nfs_pageio_reset_write_mds(struct nfs_pageio_descriptor *pgio)
{
struct nfs_pgio_mirror *mirror;
if (pgio->pg_ops && pgio->pg_ops->pg_cleanup)
pgio->pg_ops->pg_cleanup(pgio);
pgio->pg_ops = &nfs_pgio_rw_ops;
nfs_pageio_stop_mirroring(pgio);
mirror = &pgio->pg_mirrors[0];
mirror->pg_bsize = NFS_SERVER(pgio->pg_inode)->wsize;
}
void nfs_commit_prepare(struct rpc_task *task, void *calldata)
{
struct nfs_commit_data *data = calldata;
NFS_PROTO(data->inode)->commit_rpc_prepare(task, data);
}
static int nfs_should_remove_suid(const struct inode *inode)
{
umode_t mode = inode->i_mode;
int kill = 0;
if (unlikely(mode & S_ISUID))
kill = ATTR_KILL_SUID;
if (unlikely((mode & S_ISGID) && (mode & S_IXGRP)))
kill |= ATTR_KILL_SGID;
if (unlikely(kill && S_ISREG(mode)))
return kill;
return 0;
}
static void nfs_writeback_check_extend(struct nfs_pgio_header *hdr,
struct nfs_fattr *fattr)
{
struct nfs_pgio_args *argp = &hdr->args;
struct nfs_pgio_res *resp = &hdr->res;
u64 size = argp->offset + resp->count;
if (!(fattr->valid & NFS_ATTR_FATTR_SIZE))
fattr->size = size;
if (nfs_size_to_loff_t(fattr->size) < i_size_read(hdr->inode)) {
fattr->valid &= ~NFS_ATTR_FATTR_SIZE;
return;
}
if (size != fattr->size)
return;
nfs_fattr_set_barrier(fattr);
fattr->valid |= NFS_ATTR_FATTR_SIZE;
}
void nfs_writeback_update_inode(struct nfs_pgio_header *hdr)
{
struct nfs_fattr *fattr = &hdr->fattr;
struct inode *inode = hdr->inode;
spin_lock(&inode->i_lock);
nfs_writeback_check_extend(hdr, fattr);
nfs_post_op_update_inode_force_wcc_locked(inode, fattr);
spin_unlock(&inode->i_lock);
}
static int nfs_writeback_done(struct rpc_task *task,
struct nfs_pgio_header *hdr,
struct inode *inode)
{
int status;
status = NFS_PROTO(inode)->write_done(task, hdr);
if (status != 0)
return status;
nfs_add_stats(inode, NFSIOS_SERVERWRITTENBYTES, hdr->res.count);
if (hdr->res.verf->committed < hdr->args.stable &&
task->tk_status >= 0) {
static unsigned long complain;
if (time_before(complain, jiffies)) {
dprintk("NFS: faulty NFS server %s:"
" (committed = %d) != (stable = %d)\n",
NFS_SERVER(inode)->nfs_client->cl_hostname,
hdr->res.verf->committed, hdr->args.stable);
complain = jiffies + 300 * HZ;
}
}
if (nfs_should_remove_suid(inode))
nfs_mark_for_revalidate(inode);
return 0;
}
static void nfs_writeback_result(struct rpc_task *task,
struct nfs_pgio_header *hdr)
{
struct nfs_pgio_args *argp = &hdr->args;
struct nfs_pgio_res *resp = &hdr->res;
if (resp->count < argp->count) {
static unsigned long complain;
nfs_inc_stats(hdr->inode, NFSIOS_SHORTWRITE);
if (resp->count == 0) {
if (time_before(complain, jiffies)) {
printk(KERN_WARNING
"NFS: Server wrote zero bytes, expected %u.\n",
argp->count);
complain = jiffies + 300 * HZ;
}
nfs_set_pgio_error(hdr, -EIO, argp->offset);
task->tk_status = -EIO;
return;
}
if (resp->verf->committed != NFS_UNSTABLE) {
hdr->mds_offset += resp->count;
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
smp_mb__after_atomic();
wake_up_bit(&nfsi->flags, NFS_INO_COMMIT);
}
void nfs_commitdata_release(struct nfs_commit_data *data)
{
put_nfs_open_context(data->context);
nfs_commit_free(data);
}
int nfs_initiate_commit(struct rpc_clnt *clnt, struct nfs_commit_data *data,
const struct nfs_rpc_ops *nfs_ops,
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
nfs_ops->commit_setup(data, &msg);
dprintk("NFS: initiated commit call\n");
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
static loff_t nfs_get_lwb(struct list_head *head)
{
loff_t lwb = 0;
struct nfs_page *req;
list_for_each_entry(req, head, wb_list)
if (lwb < (req_offset(req) + req->wb_bytes))
lwb = req_offset(req) + req->wb_bytes;
return lwb;
}
void nfs_init_commit(struct nfs_commit_data *data,
struct list_head *head,
struct pnfs_layout_segment *lseg,
struct nfs_commit_info *cinfo)
{
struct nfs_page *first = nfs_list_entry(head->next);
struct inode *inode = d_inode(first->wb_context->dentry);
list_splice_init(head, &data->pages);
data->inode = inode;
data->cred = first->wb_context->cred;
data->lseg = lseg;
if (lseg)
data->lwb = nfs_get_lwb(&data->pages);
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
struct nfs_commit_info *cinfo,
u32 ds_commit_idx)
{
struct nfs_page *req;
while (!list_empty(page_list)) {
req = nfs_list_entry(page_list->next);
nfs_list_remove_request(req);
nfs_mark_request_commit(req, lseg, cinfo, ds_commit_idx);
if (!cinfo->dreq)
nfs_clear_page_commit(req->wb_page);
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
return nfs_initiate_commit(NFS_CLIENT(inode), data, NFS_PROTO(inode),
data->mds_ops, how, 0);
out_bad:
nfs_retry_commit(head, NULL, cinfo, 0);
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
struct nfs_server *nfss;
while (!list_empty(&data->pages)) {
req = nfs_list_entry(data->pages.next);
nfs_list_remove_request(req);
nfs_clear_page_commit(req->wb_page);
dprintk("NFS: commit (%s/%llu %d@%lld)",
req->wb_context->dentry->d_sb->s_id,
(unsigned long long)NFS_FILEID(d_inode(req->wb_context->dentry)),
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
nfss = NFS_SERVER(data->inode);
if (atomic_long_read(&nfss->writeback) < NFS_CONGESTION_OFF_THRESH)
clear_bdi_congested(&nfss->backing_dev_info, BLK_RW_ASYNC);
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
error = wait_on_bit_action(&NFS_I(inode)->flags,
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
int nfs_write_inode(struct inode *inode, struct writeback_control *wbc)
{
struct nfs_inode *nfsi = NFS_I(inode);
int flags = FLUSH_SYNC;
int ret = 0;
if (!nfsi->commit_info.ncommit)
return ret;
if (wbc->sync_mode == WB_SYNC_NONE) {
if (nfsi->commit_info.ncommit <= (nfsi->nrequests >> 1))
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
int nfs_wb_all(struct inode *inode)
{
int ret;
trace_nfs_writeback_inode_enter(inode);
ret = filemap_write_and_wait(inode->i_mapping);
if (ret)
goto out;
ret = nfs_commit_inode(inode, FLUSH_SYNC);
if (ret < 0)
goto out;
pnfs_sync_inode(inode, true);
ret = 0;
out:
trace_nfs_writeback_inode_exit(inode, ret);
return ret;
}
int nfs_wb_page_cancel(struct inode *inode, struct page *page)
{
struct nfs_page *req;
int ret = 0;
wait_on_page_writeback(page);
req = nfs_lock_and_join_requests(page, false);
if (IS_ERR(req)) {
ret = PTR_ERR(req);
} else if (req) {
nfs_inode_remove_request(req);
nfs_unlock_and_release_request(req);
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
sizeof(struct nfs_pgio_header),
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
