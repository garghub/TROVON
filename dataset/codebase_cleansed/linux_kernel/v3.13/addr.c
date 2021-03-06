static inline struct ceph_snap_context *page_snap_context(struct page *page)
{
if (PagePrivate(page))
return (void *)page->private;
return NULL;
}
static int ceph_set_page_dirty(struct page *page)
{
struct address_space *mapping = page->mapping;
struct inode *inode;
struct ceph_inode_info *ci;
struct ceph_snap_context *snapc;
int ret;
if (unlikely(!mapping))
return !TestSetPageDirty(page);
if (PageDirty(page)) {
dout("%p set_page_dirty %p idx %lu -- already dirty\n",
mapping->host, page, page->index);
BUG_ON(!PagePrivate(page));
return 0;
}
inode = mapping->host;
ci = ceph_inode(inode);
snapc = ceph_get_snap_context(ci->i_snap_realm->cached_context);
spin_lock(&ci->i_ceph_lock);
if (ci->i_head_snapc == NULL)
ci->i_head_snapc = ceph_get_snap_context(snapc);
++ci->i_wrbuffer_ref_head;
if (ci->i_wrbuffer_ref == 0)
ihold(inode);
++ci->i_wrbuffer_ref;
dout("%p set_page_dirty %p idx %lu head %d/%d -> %d/%d "
"snapc %p seq %lld (%d snaps)\n",
mapping->host, page, page->index,
ci->i_wrbuffer_ref-1, ci->i_wrbuffer_ref_head-1,
ci->i_wrbuffer_ref, ci->i_wrbuffer_ref_head,
snapc, snapc->seq, snapc->num_snaps);
spin_unlock(&ci->i_ceph_lock);
BUG_ON(PagePrivate(page));
page->private = (unsigned long)snapc;
SetPagePrivate(page);
ret = __set_page_dirty_nobuffers(page);
WARN_ON(!PageLocked(page));
WARN_ON(!page->mapping);
return ret;
}
static void ceph_invalidatepage(struct page *page, unsigned int offset,
unsigned int length)
{
struct inode *inode;
struct ceph_inode_info *ci;
struct ceph_snap_context *snapc = page_snap_context(page);
inode = page->mapping->host;
ci = ceph_inode(inode);
if (offset != 0 || length != PAGE_CACHE_SIZE) {
dout("%p invalidatepage %p idx %lu partial dirty page %u~%u\n",
inode, page, page->index, offset, length);
return;
}
ceph_invalidate_fscache_page(inode, page);
if (!PagePrivate(page))
return;
if (!PageDirty(page))
pr_err("%p invalidatepage %p page not dirty\n", inode, page);
ClearPageChecked(page);
dout("%p invalidatepage %p idx %lu full dirty page\n",
inode, page, page->index);
ceph_put_wrbuffer_cap_refs(ci, 1, snapc);
ceph_put_snap_context(snapc);
page->private = 0;
ClearPagePrivate(page);
}
static int ceph_releasepage(struct page *page, gfp_t g)
{
struct inode *inode = page->mapping ? page->mapping->host : NULL;
dout("%p releasepage %p idx %lu\n", inode, page, page->index);
WARN_ON(PageDirty(page));
if (!ceph_release_fscache_page(page, g))
return 0;
return !PagePrivate(page);
}
static int readpage_nounlock(struct file *filp, struct page *page)
{
struct inode *inode = file_inode(filp);
struct ceph_inode_info *ci = ceph_inode(inode);
struct ceph_osd_client *osdc =
&ceph_inode_to_client(inode)->client->osdc;
int err = 0;
u64 len = PAGE_CACHE_SIZE;
err = ceph_readpage_from_fscache(inode, page);
if (err == 0)
goto out;
dout("readpage inode %p file %p page %p index %lu\n",
inode, filp, page, page->index);
err = ceph_osdc_readpages(osdc, ceph_vino(inode), &ci->i_layout,
(u64) page_offset(page), &len,
ci->i_truncate_seq, ci->i_truncate_size,
&page, 1, 0);
if (err == -ENOENT)
err = 0;
if (err < 0) {
SetPageError(page);
goto out;
} else {
if (err < PAGE_CACHE_SIZE) {
zero_user_segment(page, err, PAGE_CACHE_SIZE);
} else {
flush_dcache_page(page);
}
}
SetPageUptodate(page);
if (err >= 0)
ceph_readpage_to_fscache(inode, page);
out:
return err < 0 ? err : 0;
}
static int ceph_readpage(struct file *filp, struct page *page)
{
int r = readpage_nounlock(filp, page);
unlock_page(page);
return r;
}
static void finish_read(struct ceph_osd_request *req, struct ceph_msg *msg)
{
struct inode *inode = req->r_inode;
struct ceph_osd_data *osd_data;
int rc = req->r_result;
int bytes = le32_to_cpu(msg->hdr.data_len);
int num_pages;
int i;
dout("finish_read %p req %p rc %d bytes %d\n", inode, req, rc, bytes);
osd_data = osd_req_op_extent_osd_data(req, 0);
BUG_ON(osd_data->type != CEPH_OSD_DATA_TYPE_PAGES);
num_pages = calc_pages_for((u64)osd_data->alignment,
(u64)osd_data->length);
for (i = 0; i < num_pages; i++) {
struct page *page = osd_data->pages[i];
if (bytes < (int)PAGE_CACHE_SIZE) {
int s = bytes < 0 ? 0 : bytes;
zero_user_segment(page, s, PAGE_CACHE_SIZE);
}
dout("finish_read %p uptodate %p idx %lu\n", inode, page,
page->index);
flush_dcache_page(page);
SetPageUptodate(page);
ceph_readpage_to_fscache(inode, page);
unlock_page(page);
page_cache_release(page);
bytes -= PAGE_CACHE_SIZE;
}
kfree(osd_data->pages);
}
static void ceph_unlock_page_vector(struct page **pages, int num_pages)
{
int i;
for (i = 0; i < num_pages; i++)
unlock_page(pages[i]);
}
static int start_read(struct inode *inode, struct list_head *page_list, int max)
{
struct ceph_osd_client *osdc =
&ceph_inode_to_client(inode)->client->osdc;
struct ceph_inode_info *ci = ceph_inode(inode);
struct page *page = list_entry(page_list->prev, struct page, lru);
struct ceph_vino vino;
struct ceph_osd_request *req;
u64 off;
u64 len;
int i;
struct page **pages;
pgoff_t next_index;
int nr_pages = 0;
int ret;
off = (u64) page_offset(page);
next_index = page->index;
list_for_each_entry_reverse(page, page_list, lru) {
if (page->index != next_index)
break;
nr_pages++;
next_index++;
if (max && nr_pages == max)
break;
}
len = nr_pages << PAGE_CACHE_SHIFT;
dout("start_read %p nr_pages %d is %lld~%lld\n", inode, nr_pages,
off, len);
vino = ceph_vino(inode);
req = ceph_osdc_new_request(osdc, &ci->i_layout, vino, off, &len,
1, CEPH_OSD_OP_READ,
CEPH_OSD_FLAG_READ, NULL,
ci->i_truncate_seq, ci->i_truncate_size,
false);
if (IS_ERR(req))
return PTR_ERR(req);
nr_pages = calc_pages_for(0, len);
pages = kmalloc(sizeof(*pages) * nr_pages, GFP_NOFS);
ret = -ENOMEM;
if (!pages)
goto out;
for (i = 0; i < nr_pages; ++i) {
page = list_entry(page_list->prev, struct page, lru);
BUG_ON(PageLocked(page));
list_del(&page->lru);
dout("start_read %p adding %p idx %lu\n", inode, page,
page->index);
if (add_to_page_cache_lru(page, &inode->i_data, page->index,
GFP_NOFS)) {
ceph_fscache_uncache_page(inode, page);
page_cache_release(page);
dout("start_read %p add_to_page_cache failed %p\n",
inode, page);
nr_pages = i;
goto out_pages;
}
pages[i] = page;
}
osd_req_op_extent_osd_data_pages(req, 0, pages, len, 0, false, false);
req->r_callback = finish_read;
req->r_inode = inode;
ceph_osdc_build_request(req, off, NULL, vino.snap, NULL);
dout("start_read %p starting %p %lld~%lld\n", inode, req, off, len);
ret = ceph_osdc_start_request(osdc, req, false);
if (ret < 0)
goto out_pages;
ceph_osdc_put_request(req);
return nr_pages;
out_pages:
ceph_unlock_page_vector(pages, nr_pages);
ceph_release_page_vector(pages, nr_pages);
out:
ceph_osdc_put_request(req);
return ret;
}
static int ceph_readpages(struct file *file, struct address_space *mapping,
struct list_head *page_list, unsigned nr_pages)
{
struct inode *inode = file_inode(file);
struct ceph_fs_client *fsc = ceph_inode_to_client(inode);
int rc = 0;
int max = 0;
rc = ceph_readpages_from_fscache(mapping->host, mapping, page_list,
&nr_pages);
if (rc == 0)
goto out;
if (fsc->mount_options->rsize >= PAGE_CACHE_SIZE)
max = (fsc->mount_options->rsize + PAGE_CACHE_SIZE - 1)
>> PAGE_SHIFT;
dout("readpages %p file %p nr_pages %d max %d\n", inode,
file, nr_pages,
max);
while (!list_empty(page_list)) {
rc = start_read(inode, page_list, max);
if (rc < 0)
goto out;
BUG_ON(rc == 0);
}
out:
ceph_fscache_readpages_cancel(inode, page_list);
dout("readpages %p file %p ret %d\n", inode, file, rc);
return rc;
}
static struct ceph_snap_context *get_oldest_context(struct inode *inode,
u64 *snap_size)
{
struct ceph_inode_info *ci = ceph_inode(inode);
struct ceph_snap_context *snapc = NULL;
struct ceph_cap_snap *capsnap = NULL;
spin_lock(&ci->i_ceph_lock);
list_for_each_entry(capsnap, &ci->i_cap_snaps, ci_item) {
dout(" cap_snap %p snapc %p has %d dirty pages\n", capsnap,
capsnap->context, capsnap->dirty_pages);
if (capsnap->dirty_pages) {
snapc = ceph_get_snap_context(capsnap->context);
if (snap_size)
*snap_size = capsnap->size;
break;
}
}
if (!snapc && ci->i_wrbuffer_ref_head) {
snapc = ceph_get_snap_context(ci->i_head_snapc);
dout(" head snapc %p has %d dirty pages\n",
snapc, ci->i_wrbuffer_ref_head);
}
spin_unlock(&ci->i_ceph_lock);
return snapc;
}
static int writepage_nounlock(struct page *page, struct writeback_control *wbc)
{
struct inode *inode;
struct ceph_inode_info *ci;
struct ceph_fs_client *fsc;
struct ceph_osd_client *osdc;
struct ceph_snap_context *snapc, *oldest;
loff_t page_off = page_offset(page);
long writeback_stat;
u64 truncate_size, snap_size = 0;
u32 truncate_seq;
int err = 0, len = PAGE_CACHE_SIZE;
dout("writepage %p idx %lu\n", page, page->index);
if (!page->mapping || !page->mapping->host) {
dout("writepage %p - no mapping\n", page);
return -EFAULT;
}
inode = page->mapping->host;
ci = ceph_inode(inode);
fsc = ceph_inode_to_client(inode);
osdc = &fsc->client->osdc;
snapc = page_snap_context(page);
if (snapc == NULL) {
dout("writepage %p page %p not dirty?\n", inode, page);
goto out;
}
oldest = get_oldest_context(inode, &snap_size);
if (snapc->seq > oldest->seq) {
dout("writepage %p page %p snapc %p not writeable - noop\n",
inode, page, snapc);
WARN_ON((current->flags & PF_MEMALLOC) == 0);
ceph_put_snap_context(oldest);
goto out;
}
ceph_put_snap_context(oldest);
spin_lock(&ci->i_ceph_lock);
truncate_seq = ci->i_truncate_seq;
truncate_size = ci->i_truncate_size;
if (!snap_size)
snap_size = i_size_read(inode);
spin_unlock(&ci->i_ceph_lock);
if (page_off >= snap_size) {
dout("%p page eof %llu\n", page, snap_size);
goto out;
}
if (snap_size < page_off + len)
len = snap_size - page_off;
dout("writepage %p page %p index %lu on %llu~%u snapc %p\n",
inode, page, page->index, page_off, len, snapc);
writeback_stat = atomic_long_inc_return(&fsc->writeback_count);
if (writeback_stat >
CONGESTION_ON_THRESH(fsc->mount_options->congestion_kb))
set_bdi_congested(&fsc->backing_dev_info, BLK_RW_ASYNC);
ceph_readpage_to_fscache(inode, page);
set_page_writeback(page);
err = ceph_osdc_writepages(osdc, ceph_vino(inode),
&ci->i_layout, snapc,
page_off, len,
truncate_seq, truncate_size,
&inode->i_mtime, &page, 1);
if (err < 0) {
dout("writepage setting page/mapping error %d %p\n", err, page);
SetPageError(page);
mapping_set_error(&inode->i_data, err);
if (wbc)
wbc->pages_skipped++;
} else {
dout("writepage cleaned page %p\n", page);
err = 0;
}
page->private = 0;
ClearPagePrivate(page);
end_page_writeback(page);
ceph_put_wrbuffer_cap_refs(ci, 1, snapc);
ceph_put_snap_context(snapc);
out:
return err;
}
static int ceph_writepage(struct page *page, struct writeback_control *wbc)
{
int err;
struct inode *inode = page->mapping->host;
BUG_ON(!inode);
ihold(inode);
err = writepage_nounlock(page, wbc);
unlock_page(page);
iput(inode);
return err;
}
static void ceph_release_pages(struct page **pages, int num)
{
struct pagevec pvec;
int i;
pagevec_init(&pvec, 0);
for (i = 0; i < num; i++) {
if (pagevec_add(&pvec, pages[i]) == 0)
pagevec_release(&pvec);
}
pagevec_release(&pvec);
}
static void writepages_finish(struct ceph_osd_request *req,
struct ceph_msg *msg)
{
struct inode *inode = req->r_inode;
struct ceph_inode_info *ci = ceph_inode(inode);
struct ceph_osd_data *osd_data;
unsigned wrote;
struct page *page;
int num_pages;
int i;
struct ceph_snap_context *snapc = req->r_snapc;
struct address_space *mapping = inode->i_mapping;
int rc = req->r_result;
u64 bytes = req->r_ops[0].extent.length;
struct ceph_fs_client *fsc = ceph_inode_to_client(inode);
long writeback_stat;
unsigned issued = ceph_caps_issued(ci);
osd_data = osd_req_op_extent_osd_data(req, 0);
BUG_ON(osd_data->type != CEPH_OSD_DATA_TYPE_PAGES);
num_pages = calc_pages_for((u64)osd_data->alignment,
(u64)osd_data->length);
if (rc >= 0) {
wrote = num_pages;
} else {
wrote = 0;
mapping_set_error(mapping, rc);
}
dout("writepages_finish %p rc %d bytes %llu wrote %d (pages)\n",
inode, rc, bytes, wrote);
for (i = 0; i < num_pages; i++) {
page = osd_data->pages[i];
BUG_ON(!page);
WARN_ON(!PageUptodate(page));
writeback_stat =
atomic_long_dec_return(&fsc->writeback_count);
if (writeback_stat <
CONGESTION_OFF_THRESH(fsc->mount_options->congestion_kb))
clear_bdi_congested(&fsc->backing_dev_info,
BLK_RW_ASYNC);
ceph_put_snap_context(page_snap_context(page));
page->private = 0;
ClearPagePrivate(page);
dout("unlocking %d %p\n", i, page);
end_page_writeback(page);
if ((issued & (CEPH_CAP_FILE_CACHE|CEPH_CAP_FILE_LAZYIO)) == 0)
generic_error_remove_page(inode->i_mapping, page);
unlock_page(page);
}
dout("%p wrote+cleaned %d pages\n", inode, wrote);
ceph_put_wrbuffer_cap_refs(ci, num_pages, snapc);
ceph_release_pages(osd_data->pages, num_pages);
if (osd_data->pages_from_pool)
mempool_free(osd_data->pages,
ceph_sb_to_client(inode->i_sb)->wb_pagevec_pool);
else
kfree(osd_data->pages);
ceph_osdc_put_request(req);
}
static int ceph_writepages_start(struct address_space *mapping,
struct writeback_control *wbc)
{
struct inode *inode = mapping->host;
struct ceph_inode_info *ci = ceph_inode(inode);
struct ceph_fs_client *fsc = ceph_inode_to_client(inode);
struct ceph_vino vino = ceph_vino(inode);
pgoff_t index, start, end;
int range_whole = 0;
int should_loop = 1;
pgoff_t max_pages = 0, max_pages_ever = 0;
struct ceph_snap_context *snapc = NULL, *last_snapc = NULL, *pgsnapc;
struct pagevec pvec;
int done = 0;
int rc = 0;
unsigned wsize = 1 << inode->i_blkbits;
struct ceph_osd_request *req = NULL;
int do_sync;
u64 truncate_size, snap_size;
u32 truncate_seq;
if ((wbc->sync_mode == WB_SYNC_ALL) ||
ceph_caps_revoking(ci, CEPH_CAP_FILE_BUFFER))
do_sync = 1;
dout("writepages_start %p dosync=%d (mode=%s)\n",
inode, do_sync,
wbc->sync_mode == WB_SYNC_NONE ? "NONE" :
(wbc->sync_mode == WB_SYNC_ALL ? "ALL" : "HOLD"));
if (fsc->mount_state == CEPH_MOUNT_SHUTDOWN) {
pr_warning("writepage_start %p on forced umount\n", inode);
return -EIO;
}
if (fsc->mount_options->wsize && fsc->mount_options->wsize < wsize)
wsize = fsc->mount_options->wsize;
if (wsize < PAGE_CACHE_SIZE)
wsize = PAGE_CACHE_SIZE;
max_pages_ever = wsize >> PAGE_CACHE_SHIFT;
pagevec_init(&pvec, 0);
if (wbc->range_cyclic) {
start = mapping->writeback_index;
end = -1;
dout(" cyclic, start at %lu\n", start);
} else {
start = wbc->range_start >> PAGE_CACHE_SHIFT;
end = wbc->range_end >> PAGE_CACHE_SHIFT;
if (wbc->range_start == 0 && wbc->range_end == LLONG_MAX)
range_whole = 1;
should_loop = 0;
dout(" not cyclic, %lu to %lu\n", start, end);
}
index = start;
retry:
ceph_put_snap_context(snapc);
snap_size = 0;
snapc = get_oldest_context(inode, &snap_size);
if (!snapc) {
dout(" no snap context with dirty data?\n");
goto out;
}
if (snap_size == 0)
snap_size = i_size_read(inode);
dout(" oldest snapc is %p seq %lld (%d snaps)\n",
snapc, snapc->seq, snapc->num_snaps);
spin_lock(&ci->i_ceph_lock);
truncate_seq = ci->i_truncate_seq;
truncate_size = ci->i_truncate_size;
if (!snap_size)
snap_size = i_size_read(inode);
spin_unlock(&ci->i_ceph_lock);
if (last_snapc && snapc != last_snapc) {
dout(" snapc differs from last pass, restarting at %lu\n",
index);
index = start;
}
last_snapc = snapc;
while (!done && index <= end) {
int num_ops = do_sync ? 2 : 1;
unsigned i;
int first;
pgoff_t next;
int pvec_pages, locked_pages;
struct page **pages = NULL;
mempool_t *pool = NULL;
struct page *page;
int want;
u64 offset, len;
long writeback_stat;
next = 0;
locked_pages = 0;
max_pages = max_pages_ever;
get_more_pages:
first = -1;
want = min(end - index,
min((pgoff_t)PAGEVEC_SIZE,
max_pages - (pgoff_t)locked_pages) - 1)
+ 1;
pvec_pages = pagevec_lookup_tag(&pvec, mapping, &index,
PAGECACHE_TAG_DIRTY,
want);
dout("pagevec_lookup_tag got %d\n", pvec_pages);
if (!pvec_pages && !locked_pages)
break;
for (i = 0; i < pvec_pages && locked_pages < max_pages; i++) {
page = pvec.pages[i];
dout("? %p idx %lu\n", page, page->index);
if (locked_pages == 0)
lock_page(page);
else if (!trylock_page(page))
break;
if (unlikely(!PageDirty(page)) ||
unlikely(page->mapping != mapping)) {
dout("!dirty or !mapping %p\n", page);
unlock_page(page);
break;
}
if (!wbc->range_cyclic && page->index > end) {
dout("end of range %p\n", page);
done = 1;
unlock_page(page);
break;
}
if (next && (page->index != next)) {
dout("not consecutive %p\n", page);
unlock_page(page);
break;
}
if (wbc->sync_mode != WB_SYNC_NONE) {
dout("waiting on writeback %p\n", page);
wait_on_page_writeback(page);
}
if (page_offset(page) >= snap_size) {
dout("%p page eof %llu\n", page, snap_size);
done = 1;
unlock_page(page);
break;
}
if (PageWriteback(page)) {
dout("%p under writeback\n", page);
unlock_page(page);
break;
}
pgsnapc = page_snap_context(page);
if (pgsnapc->seq > snapc->seq) {
dout("page snapc %p %lld > oldest %p %lld\n",
pgsnapc, pgsnapc->seq, snapc, snapc->seq);
unlock_page(page);
if (!locked_pages)
continue;
break;
}
if (!clear_page_dirty_for_io(page)) {
dout("%p !clear_page_dirty_for_io\n", page);
unlock_page(page);
break;
}
if (locked_pages == 0) {
BUG_ON(pages);
offset = (u64)page_offset(page);
len = wsize;
req = ceph_osdc_new_request(&fsc->client->osdc,
&ci->i_layout, vino,
offset, &len, num_ops,
CEPH_OSD_OP_WRITE,
CEPH_OSD_FLAG_WRITE |
CEPH_OSD_FLAG_ONDISK,
snapc, truncate_seq,
truncate_size, true);
if (IS_ERR(req)) {
rc = PTR_ERR(req);
unlock_page(page);
break;
}
req->r_callback = writepages_finish;
req->r_inode = inode;
max_pages = calc_pages_for(0, (u64)len);
pages = kmalloc(max_pages * sizeof (*pages),
GFP_NOFS);
if (!pages) {
pool = fsc->wb_pagevec_pool;
pages = mempool_alloc(pool, GFP_NOFS);
BUG_ON(!pages);
}
}
if (first < 0)
first = i;
dout("%p will write page %p idx %lu\n",
inode, page, page->index);
writeback_stat =
atomic_long_inc_return(&fsc->writeback_count);
if (writeback_stat > CONGESTION_ON_THRESH(
fsc->mount_options->congestion_kb)) {
set_bdi_congested(&fsc->backing_dev_info,
BLK_RW_ASYNC);
}
set_page_writeback(page);
pages[locked_pages] = page;
locked_pages++;
next = page->index + 1;
}
if (!locked_pages)
goto release_pvec_pages;
if (i) {
int j;
BUG_ON(!locked_pages || first < 0);
if (pvec_pages && i == pvec_pages &&
locked_pages < max_pages) {
dout("reached end pvec, trying for more\n");
pagevec_reinit(&pvec);
goto get_more_pages;
}
for (j = i; j < pvec_pages; j++) {
dout(" pvec leftover page %p\n",
pvec.pages[j]);
pvec.pages[j-i+first] = pvec.pages[j];
}
pvec.nr -= i-first;
}
offset = page_offset(pages[0]);
len = min(snap_size - offset,
(u64)locked_pages << PAGE_CACHE_SHIFT);
dout("writepages got %d pages at %llu~%llu\n",
locked_pages, offset, len);
osd_req_op_extent_osd_data_pages(req, 0, pages, len, 0,
!!pool, false);
pages = NULL;
pool = NULL;
osd_req_op_extent_update(req, 0, len);
vino = ceph_vino(inode);
ceph_osdc_build_request(req, offset, snapc, vino.snap,
&inode->i_mtime);
rc = ceph_osdc_start_request(&fsc->client->osdc, req, true);
BUG_ON(rc);
req = NULL;
index = next;
wbc->nr_to_write -= locked_pages;
if (wbc->nr_to_write <= 0)
done = 1;
release_pvec_pages:
dout("pagevec_release on %d pages (%p)\n", (int)pvec.nr,
pvec.nr ? pvec.pages[0] : NULL);
pagevec_release(&pvec);
if (locked_pages && !done)
goto retry;
}
if (should_loop && !done) {
dout("writepages looping back to beginning of file\n");
should_loop = 0;
index = 0;
goto retry;
}
if (wbc->range_cyclic || (range_whole && wbc->nr_to_write > 0))
mapping->writeback_index = index;
out:
if (req)
ceph_osdc_put_request(req);
ceph_put_snap_context(snapc);
dout("writepages done, rc = %d\n", rc);
return rc;
}
static int context_is_writeable_or_written(struct inode *inode,
struct ceph_snap_context *snapc)
{
struct ceph_snap_context *oldest = get_oldest_context(inode, NULL);
int ret = !oldest || snapc->seq <= oldest->seq;
ceph_put_snap_context(oldest);
return ret;
}
static int ceph_update_writeable_page(struct file *file,
loff_t pos, unsigned len,
struct page *page)
{
struct inode *inode = file_inode(file);
struct ceph_inode_info *ci = ceph_inode(inode);
struct ceph_mds_client *mdsc = ceph_inode_to_client(inode)->mdsc;
loff_t page_off = pos & PAGE_CACHE_MASK;
int pos_in_page = pos & ~PAGE_CACHE_MASK;
int end_in_page = pos_in_page + len;
loff_t i_size;
int r;
struct ceph_snap_context *snapc, *oldest;
retry_locked:
wait_on_page_writeback(page);
BUG_ON(!ci->i_snap_realm);
down_read(&mdsc->snap_rwsem);
BUG_ON(!ci->i_snap_realm->cached_context);
snapc = page_snap_context(page);
if (snapc && snapc != ci->i_head_snapc) {
oldest = get_oldest_context(inode, NULL);
up_read(&mdsc->snap_rwsem);
if (snapc->seq > oldest->seq) {
ceph_put_snap_context(oldest);
dout(" page %p snapc %p not current or oldest\n",
page, snapc);
snapc = ceph_get_snap_context(snapc);
unlock_page(page);
ceph_queue_writeback(inode);
r = wait_event_interruptible(ci->i_cap_wq,
context_is_writeable_or_written(inode, snapc));
ceph_put_snap_context(snapc);
if (r == -ERESTARTSYS)
return r;
return -EAGAIN;
}
ceph_put_snap_context(oldest);
dout(" page %p snapc %p not current, but oldest\n",
page, snapc);
if (!clear_page_dirty_for_io(page))
goto retry_locked;
r = writepage_nounlock(page, NULL);
if (r < 0)
goto fail_nosnap;
goto retry_locked;
}
if (PageUptodate(page)) {
dout(" page %p already uptodate\n", page);
return 0;
}
if (pos_in_page == 0 && len == PAGE_CACHE_SIZE)
return 0;
i_size = inode->i_size;
if (i_size + len > inode->i_sb->s_maxbytes) {
r = -EINVAL;
goto fail;
}
if (page_off >= i_size ||
(pos_in_page == 0 && (pos+len) >= i_size &&
end_in_page - pos_in_page != PAGE_CACHE_SIZE)) {
dout(" zeroing %p 0 - %d and %d - %d\n",
page, pos_in_page, end_in_page, (int)PAGE_CACHE_SIZE);
zero_user_segments(page,
0, pos_in_page,
end_in_page, PAGE_CACHE_SIZE);
return 0;
}
up_read(&mdsc->snap_rwsem);
r = readpage_nounlock(file, page);
if (r < 0)
goto fail_nosnap;
goto retry_locked;
fail:
up_read(&mdsc->snap_rwsem);
fail_nosnap:
unlock_page(page);
return r;
}
static int ceph_write_begin(struct file *file, struct address_space *mapping,
loff_t pos, unsigned len, unsigned flags,
struct page **pagep, void **fsdata)
{
struct inode *inode = file_inode(file);
struct page *page;
pgoff_t index = pos >> PAGE_CACHE_SHIFT;
int r;
do {
page = grab_cache_page_write_begin(mapping, index, 0);
if (!page)
return -ENOMEM;
*pagep = page;
dout("write_begin file %p inode %p page %p %d~%d\n", file,
inode, page, (int)pos, (int)len);
r = ceph_update_writeable_page(file, pos, len, page);
} while (r == -EAGAIN);
return r;
}
static int ceph_write_end(struct file *file, struct address_space *mapping,
loff_t pos, unsigned len, unsigned copied,
struct page *page, void *fsdata)
{
struct inode *inode = file_inode(file);
struct ceph_fs_client *fsc = ceph_inode_to_client(inode);
struct ceph_mds_client *mdsc = fsc->mdsc;
unsigned from = pos & (PAGE_CACHE_SIZE - 1);
int check_cap = 0;
dout("write_end file %p inode %p page %p %d~%d (%d)\n", file,
inode, page, (int)pos, (int)copied, (int)len);
if (copied < len)
zero_user_segment(page, from+copied, len);
if (pos+copied > inode->i_size)
check_cap = ceph_inode_set_size(inode, pos+copied);
if (!PageUptodate(page))
SetPageUptodate(page);
set_page_dirty(page);
unlock_page(page);
up_read(&mdsc->snap_rwsem);
page_cache_release(page);
if (check_cap)
ceph_check_caps(ceph_inode(inode), CHECK_CAPS_AUTHONLY, NULL);
return copied;
}
static ssize_t ceph_direct_io(int rw, struct kiocb *iocb,
const struct iovec *iov,
loff_t pos, unsigned long nr_segs)
{
WARN_ON(1);
return -EINVAL;
}
static int ceph_page_mkwrite(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct inode *inode = file_inode(vma->vm_file);
struct page *page = vmf->page;
struct ceph_mds_client *mdsc = ceph_inode_to_client(inode)->mdsc;
loff_t off = page_offset(page);
loff_t size, len;
int ret;
file_update_time(vma->vm_file);
size = i_size_read(inode);
if (off + PAGE_CACHE_SIZE <= size)
len = PAGE_CACHE_SIZE;
else
len = size & ~PAGE_CACHE_MASK;
dout("page_mkwrite %p %llu~%llu page %p idx %lu\n", inode,
off, len, page, page->index);
lock_page(page);
ret = VM_FAULT_NOPAGE;
if ((off > size) ||
(page->mapping != inode->i_mapping))
goto out;
ret = ceph_update_writeable_page(vma->vm_file, off, len, page);
if (ret == 0) {
set_page_dirty(page);
up_read(&mdsc->snap_rwsem);
ret = VM_FAULT_LOCKED;
} else {
if (ret == -ENOMEM)
ret = VM_FAULT_OOM;
else
ret = VM_FAULT_SIGBUS;
}
out:
dout("page_mkwrite %p %llu~%llu = %d\n", inode, off, len, ret);
if (ret != VM_FAULT_LOCKED)
unlock_page(page);
return ret;
}
int ceph_mmap(struct file *file, struct vm_area_struct *vma)
{
struct address_space *mapping = file->f_mapping;
if (!mapping->a_ops->readpage)
return -ENOEXEC;
file_accessed(file);
vma->vm_ops = &ceph_vmops;
return 0;
}
