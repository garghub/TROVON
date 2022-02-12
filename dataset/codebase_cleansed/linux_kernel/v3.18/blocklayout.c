static bool is_hole(struct pnfs_block_extent *be)
{
switch (be->be_state) {
case PNFS_BLOCK_NONE_DATA:
return true;
case PNFS_BLOCK_INVALID_DATA:
return be->be_tag ? false : true;
default:
return false;
}
}
static inline struct parallel_io *alloc_parallel(void *data)
{
struct parallel_io *rv;
rv = kmalloc(sizeof(*rv), GFP_NOFS);
if (rv) {
rv->data = data;
kref_init(&rv->refcnt);
}
return rv;
}
static inline void get_parallel(struct parallel_io *p)
{
kref_get(&p->refcnt);
}
static void destroy_parallel(struct kref *kref)
{
struct parallel_io *p = container_of(kref, struct parallel_io, refcnt);
dprintk("%s enter\n", __func__);
p->pnfs_callback(p->data);
kfree(p);
}
static inline void put_parallel(struct parallel_io *p)
{
kref_put(&p->refcnt, destroy_parallel);
}
static struct bio *
bl_submit_bio(int rw, struct bio *bio)
{
if (bio) {
get_parallel(bio->bi_private);
dprintk("%s submitting %s bio %u@%llu\n", __func__,
rw == READ ? "read" : "write", bio->bi_iter.bi_size,
(unsigned long long)bio->bi_iter.bi_sector);
submit_bio(rw, bio);
}
return NULL;
}
static struct bio *
bl_alloc_init_bio(int npg, struct block_device *bdev, sector_t disk_sector,
void (*end_io)(struct bio *, int err), struct parallel_io *par)
{
struct bio *bio;
npg = min(npg, BIO_MAX_PAGES);
bio = bio_alloc(GFP_NOIO, npg);
if (!bio && (current->flags & PF_MEMALLOC)) {
while (!bio && (npg /= 2))
bio = bio_alloc(GFP_NOIO, npg);
}
if (bio) {
bio->bi_iter.bi_sector = disk_sector;
bio->bi_bdev = bdev;
bio->bi_end_io = end_io;
bio->bi_private = par;
}
return bio;
}
static struct bio *
do_add_page_to_bio(struct bio *bio, int npg, int rw, sector_t isect,
struct page *page, struct pnfs_block_dev_map *map,
struct pnfs_block_extent *be,
void (*end_io)(struct bio *, int err),
struct parallel_io *par, unsigned int offset, int *len)
{
struct pnfs_block_dev *dev =
container_of(be->be_device, struct pnfs_block_dev, node);
u64 disk_addr, end;
dprintk("%s: npg %d rw %d isect %llu offset %u len %d\n", __func__,
npg, rw, (unsigned long long)isect, offset, *len);
isect += be->be_v_offset;
isect -= be->be_f_offset;
disk_addr = (u64)isect << SECTOR_SHIFT;
if (disk_addr < map->start || disk_addr >= map->start + map->len) {
if (!dev->map(dev, disk_addr, map))
return ERR_PTR(-EIO);
bio = bl_submit_bio(rw, bio);
}
disk_addr += map->disk_offset;
disk_addr -= map->start;
end = disk_addr + *len;
if (end >= map->start + map->len)
*len = map->start + map->len - disk_addr;
retry:
if (!bio) {
bio = bl_alloc_init_bio(npg, map->bdev,
disk_addr >> SECTOR_SHIFT, end_io, par);
if (!bio)
return ERR_PTR(-ENOMEM);
}
if (bio_add_page(bio, page, *len, offset) < *len) {
bio = bl_submit_bio(rw, bio);
goto retry;
}
return bio;
}
static void bl_end_io_read(struct bio *bio, int err)
{
struct parallel_io *par = bio->bi_private;
if (err) {
struct nfs_pgio_header *header = par->data;
if (!header->pnfs_error)
header->pnfs_error = -EIO;
pnfs_set_lo_fail(header->lseg);
}
bio_put(bio);
put_parallel(par);
}
static void bl_read_cleanup(struct work_struct *work)
{
struct rpc_task *task;
struct nfs_pgio_header *hdr;
dprintk("%s enter\n", __func__);
task = container_of(work, struct rpc_task, u.tk_work);
hdr = container_of(task, struct nfs_pgio_header, task);
pnfs_ld_read_done(hdr);
}
static void
bl_end_par_io_read(void *data)
{
struct nfs_pgio_header *hdr = data;
hdr->task.tk_status = hdr->pnfs_error;
INIT_WORK(&hdr->task.u.tk_work, bl_read_cleanup);
schedule_work(&hdr->task.u.tk_work);
}
static enum pnfs_try_status
bl_read_pagelist(struct nfs_pgio_header *header)
{
struct pnfs_block_layout *bl = BLK_LSEG2EXT(header->lseg);
struct pnfs_block_dev_map map = { .start = NFS4_MAX_UINT64 };
struct bio *bio = NULL;
struct pnfs_block_extent be;
sector_t isect, extent_length = 0;
struct parallel_io *par;
loff_t f_offset = header->args.offset;
size_t bytes_left = header->args.count;
unsigned int pg_offset, pg_len;
struct page **pages = header->args.pages;
int pg_index = header->args.pgbase >> PAGE_CACHE_SHIFT;
const bool is_dio = (header->dreq != NULL);
struct blk_plug plug;
int i;
dprintk("%s enter nr_pages %u offset %lld count %u\n", __func__,
header->page_array.npages, f_offset,
(unsigned int)header->args.count);
par = alloc_parallel(header);
if (!par)
return PNFS_NOT_ATTEMPTED;
par->pnfs_callback = bl_end_par_io_read;
blk_start_plug(&plug);
isect = (sector_t) (f_offset >> SECTOR_SHIFT);
for (i = pg_index; i < header->page_array.npages; i++) {
if (extent_length <= 0) {
bio = bl_submit_bio(READ, bio);
if (!ext_tree_lookup(bl, isect, &be, false)) {
header->pnfs_error = -EIO;
goto out;
}
extent_length = be.be_length - (isect - be.be_f_offset);
}
pg_offset = f_offset & ~PAGE_CACHE_MASK;
if (is_dio) {
if (pg_offset + bytes_left > PAGE_CACHE_SIZE)
pg_len = PAGE_CACHE_SIZE - pg_offset;
else
pg_len = bytes_left;
} else {
BUG_ON(pg_offset != 0);
pg_len = PAGE_CACHE_SIZE;
}
isect += (pg_offset >> SECTOR_SHIFT);
extent_length -= (pg_offset >> SECTOR_SHIFT);
if (is_hole(&be)) {
bio = bl_submit_bio(READ, bio);
dprintk("%s Zeroing page for hole\n", __func__);
zero_user_segment(pages[i], pg_offset, pg_len);
map.start = NFS4_MAX_UINT64;
} else {
bio = do_add_page_to_bio(bio,
header->page_array.npages - i,
READ,
isect, pages[i], &map, &be,
bl_end_io_read, par,
pg_offset, &pg_len);
if (IS_ERR(bio)) {
header->pnfs_error = PTR_ERR(bio);
bio = NULL;
goto out;
}
}
isect += (pg_len >> SECTOR_SHIFT);
extent_length -= (pg_len >> SECTOR_SHIFT);
f_offset += pg_len;
bytes_left -= pg_len;
}
if ((isect << SECTOR_SHIFT) >= header->inode->i_size) {
header->res.eof = 1;
header->res.count = header->inode->i_size - header->args.offset;
} else {
header->res.count = (isect << SECTOR_SHIFT) - header->args.offset;
}
out:
bl_submit_bio(READ, bio);
blk_finish_plug(&plug);
put_parallel(par);
return PNFS_ATTEMPTED;
}
static void bl_end_io_write(struct bio *bio, int err)
{
struct parallel_io *par = bio->bi_private;
const int uptodate = test_bit(BIO_UPTODATE, &bio->bi_flags);
struct nfs_pgio_header *header = par->data;
if (!uptodate) {
if (!header->pnfs_error)
header->pnfs_error = -EIO;
pnfs_set_lo_fail(header->lseg);
}
bio_put(bio);
put_parallel(par);
}
static void bl_write_cleanup(struct work_struct *work)
{
struct rpc_task *task = container_of(work, struct rpc_task, u.tk_work);
struct nfs_pgio_header *hdr =
container_of(task, struct nfs_pgio_header, task);
dprintk("%s enter\n", __func__);
if (likely(!hdr->pnfs_error)) {
struct pnfs_block_layout *bl = BLK_LSEG2EXT(hdr->lseg);
u64 start = hdr->args.offset & (loff_t)PAGE_CACHE_MASK;
u64 end = (hdr->args.offset + hdr->args.count +
PAGE_CACHE_SIZE - 1) & (loff_t)PAGE_CACHE_MASK;
ext_tree_mark_written(bl, start >> SECTOR_SHIFT,
(end - start) >> SECTOR_SHIFT);
}
pnfs_ld_write_done(hdr);
}
static void bl_end_par_io_write(void *data)
{
struct nfs_pgio_header *hdr = data;
hdr->task.tk_status = hdr->pnfs_error;
hdr->verf.committed = NFS_FILE_SYNC;
INIT_WORK(&hdr->task.u.tk_work, bl_write_cleanup);
schedule_work(&hdr->task.u.tk_work);
}
static enum pnfs_try_status
bl_write_pagelist(struct nfs_pgio_header *header, int sync)
{
struct pnfs_block_layout *bl = BLK_LSEG2EXT(header->lseg);
struct pnfs_block_dev_map map = { .start = NFS4_MAX_UINT64 };
struct bio *bio = NULL;
struct pnfs_block_extent be;
sector_t isect, extent_length = 0;
struct parallel_io *par = NULL;
loff_t offset = header->args.offset;
size_t count = header->args.count;
struct page **pages = header->args.pages;
int pg_index = header->args.pgbase >> PAGE_CACHE_SHIFT;
unsigned int pg_len;
struct blk_plug plug;
int i;
dprintk("%s enter, %Zu@%lld\n", __func__, count, offset);
par = alloc_parallel(header);
if (!par)
return PNFS_NOT_ATTEMPTED;
par->pnfs_callback = bl_end_par_io_write;
blk_start_plug(&plug);
offset = offset & (loff_t)PAGE_CACHE_MASK;
isect = offset >> SECTOR_SHIFT;
for (i = pg_index; i < header->page_array.npages; i++) {
if (extent_length <= 0) {
bio = bl_submit_bio(WRITE, bio);
if (!ext_tree_lookup(bl, isect, &be, true)) {
header->pnfs_error = -EINVAL;
goto out;
}
extent_length = be.be_length - (isect - be.be_f_offset);
}
pg_len = PAGE_CACHE_SIZE;
bio = do_add_page_to_bio(bio, header->page_array.npages - i,
WRITE, isect, pages[i], &map, &be,
bl_end_io_write, par,
0, &pg_len);
if (IS_ERR(bio)) {
header->pnfs_error = PTR_ERR(bio);
bio = NULL;
goto out;
}
offset += pg_len;
count -= pg_len;
isect += (pg_len >> SECTOR_SHIFT);
extent_length -= (pg_len >> SECTOR_SHIFT);
}
header->res.count = header->args.count;
out:
bl_submit_bio(WRITE, bio);
blk_finish_plug(&plug);
put_parallel(par);
return PNFS_ATTEMPTED;
}
static void bl_free_layout_hdr(struct pnfs_layout_hdr *lo)
{
struct pnfs_block_layout *bl = BLK_LO2EXT(lo);
int err;
dprintk("%s enter\n", __func__);
err = ext_tree_remove(bl, true, 0, LLONG_MAX);
WARN_ON(err);
kfree(bl);
}
static struct pnfs_layout_hdr *bl_alloc_layout_hdr(struct inode *inode,
gfp_t gfp_flags)
{
struct pnfs_block_layout *bl;
dprintk("%s enter\n", __func__);
bl = kzalloc(sizeof(*bl), gfp_flags);
if (!bl)
return NULL;
bl->bl_ext_rw = RB_ROOT;
bl->bl_ext_ro = RB_ROOT;
spin_lock_init(&bl->bl_ext_lock);
return &bl->bl_layout;
}
static void bl_free_lseg(struct pnfs_layout_segment *lseg)
{
dprintk("%s enter\n", __func__);
kfree(lseg);
}
static int verify_extent(struct pnfs_block_extent *be,
struct layout_verification *lv)
{
if (lv->mode == IOMODE_READ) {
if (be->be_state == PNFS_BLOCK_READWRITE_DATA ||
be->be_state == PNFS_BLOCK_INVALID_DATA)
return -EIO;
if (be->be_f_offset != lv->start)
return -EIO;
lv->start += be->be_length;
return 0;
}
if (be->be_state == PNFS_BLOCK_READWRITE_DATA) {
if (be->be_f_offset != lv->start)
return -EIO;
if (lv->cowread > lv->start)
return -EIO;
lv->start += be->be_length;
lv->inval = lv->start;
return 0;
} else if (be->be_state == PNFS_BLOCK_INVALID_DATA) {
if (be->be_f_offset != lv->start)
return -EIO;
lv->start += be->be_length;
return 0;
} else if (be->be_state == PNFS_BLOCK_READ_DATA) {
if (be->be_f_offset > lv->start)
return -EIO;
if (be->be_f_offset < lv->inval)
return -EIO;
if (be->be_f_offset < lv->cowread)
return -EIO;
lv->inval = lv->inval + be->be_length;
lv->cowread = be->be_f_offset + be->be_length;
return 0;
} else
return -EIO;
}
static int decode_sector_number(__be32 **rp, sector_t *sp)
{
uint64_t s;
*rp = xdr_decode_hyper(*rp, &s);
if (s & 0x1ff) {
printk(KERN_WARNING "NFS: %s: sector not aligned\n", __func__);
return -1;
}
*sp = s >> SECTOR_SHIFT;
return 0;
}
static int
bl_alloc_extent(struct xdr_stream *xdr, struct pnfs_layout_hdr *lo,
struct layout_verification *lv, struct list_head *extents,
gfp_t gfp_mask)
{
struct pnfs_block_extent *be;
struct nfs4_deviceid id;
int error;
__be32 *p;
p = xdr_inline_decode(xdr, 28 + NFS4_DEVICEID4_SIZE);
if (!p)
return -EIO;
be = kzalloc(sizeof(*be), GFP_NOFS);
if (!be)
return -ENOMEM;
memcpy(&id, p, NFS4_DEVICEID4_SIZE);
p += XDR_QUADLEN(NFS4_DEVICEID4_SIZE);
error = -EIO;
be->be_device = nfs4_find_get_deviceid(NFS_SERVER(lo->plh_inode), &id,
lo->plh_lc_cred, gfp_mask);
if (!be->be_device)
goto out_free_be;
if (decode_sector_number(&p, &be->be_f_offset) < 0)
goto out_put_deviceid;
if (decode_sector_number(&p, &be->be_length) < 0)
goto out_put_deviceid;
if (decode_sector_number(&p, &be->be_v_offset) < 0)
goto out_put_deviceid;
be->be_state = be32_to_cpup(p++);
error = verify_extent(be, lv);
if (error) {
dprintk("%s: extent verification failed\n", __func__);
goto out_put_deviceid;
}
list_add_tail(&be->be_list, extents);
return 0;
out_put_deviceid:
nfs4_put_deviceid_node(be->be_device);
out_free_be:
kfree(be);
return error;
}
static struct pnfs_layout_segment *
bl_alloc_lseg(struct pnfs_layout_hdr *lo, struct nfs4_layoutget_res *lgr,
gfp_t gfp_mask)
{
struct layout_verification lv = {
.mode = lgr->range.iomode,
.start = lgr->range.offset >> SECTOR_SHIFT,
.inval = lgr->range.offset >> SECTOR_SHIFT,
.cowread = lgr->range.offset >> SECTOR_SHIFT,
};
struct pnfs_block_layout *bl = BLK_LO2EXT(lo);
struct pnfs_layout_segment *lseg;
struct xdr_buf buf;
struct xdr_stream xdr;
struct page *scratch;
int status, i;
uint32_t count;
__be32 *p;
LIST_HEAD(extents);
dprintk("---> %s\n", __func__);
lseg = kzalloc(sizeof(*lseg), gfp_mask);
if (!lseg)
return ERR_PTR(-ENOMEM);
status = -ENOMEM;
scratch = alloc_page(gfp_mask);
if (!scratch)
goto out;
xdr_init_decode_pages(&xdr, &buf,
lgr->layoutp->pages, lgr->layoutp->len);
xdr_set_scratch_buffer(&xdr, page_address(scratch), PAGE_SIZE);
status = -EIO;
p = xdr_inline_decode(&xdr, 4);
if (unlikely(!p))
goto out_free_scratch;
count = be32_to_cpup(p++);
dprintk("%s: number of extents %d\n", __func__, count);
for (i = 0; i < count; i++) {
status = bl_alloc_extent(&xdr, lo, &lv, &extents, gfp_mask);
if (status)
goto process_extents;
}
if (lgr->range.offset + lgr->range.length !=
lv.start << SECTOR_SHIFT) {
dprintk("%s Final length mismatch\n", __func__);
status = -EIO;
goto process_extents;
}
if (lv.start < lv.cowread) {
dprintk("%s Final uncovered COW extent\n", __func__);
status = -EIO;
}
process_extents:
while (!list_empty(&extents)) {
struct pnfs_block_extent *be =
list_first_entry(&extents, struct pnfs_block_extent,
be_list);
list_del(&be->be_list);
if (!status)
status = ext_tree_insert(bl, be);
if (status) {
nfs4_put_deviceid_node(be->be_device);
kfree(be);
}
}
out_free_scratch:
__free_page(scratch);
out:
dprintk("%s returns %d\n", __func__, status);
if (status) {
kfree(lseg);
return ERR_PTR(status);
}
return lseg;
}
static void
bl_return_range(struct pnfs_layout_hdr *lo,
struct pnfs_layout_range *range)
{
struct pnfs_block_layout *bl = BLK_LO2EXT(lo);
sector_t offset = range->offset >> SECTOR_SHIFT, end;
if (range->offset % 8) {
dprintk("%s: offset %lld not block size aligned\n",
__func__, range->offset);
return;
}
if (range->length != NFS4_MAX_UINT64) {
if (range->length % 8) {
dprintk("%s: length %lld not block size aligned\n",
__func__, range->length);
return;
}
end = offset + (range->length >> SECTOR_SHIFT);
} else {
end = round_down(NFS4_MAX_UINT64, PAGE_SIZE);
}
ext_tree_remove(bl, range->iomode & IOMODE_RW, offset, end);
}
static int
bl_prepare_layoutcommit(struct nfs4_layoutcommit_args *arg)
{
return ext_tree_prepare_commit(arg);
}
static void
bl_cleanup_layoutcommit(struct nfs4_layoutcommit_data *lcdata)
{
ext_tree_mark_committed(&lcdata->args, lcdata->res.status);
}
static int
bl_set_layoutdriver(struct nfs_server *server, const struct nfs_fh *fh)
{
dprintk("%s enter\n", __func__);
if (server->pnfs_blksize == 0) {
dprintk("%s Server did not return blksize\n", __func__);
return -EINVAL;
}
if (server->pnfs_blksize > PAGE_SIZE) {
printk(KERN_ERR "%s: pNFS blksize %d not supported.\n",
__func__, server->pnfs_blksize);
return -EINVAL;
}
return 0;
}
static bool
is_aligned_req(struct nfs_pageio_descriptor *pgio,
struct nfs_page *req, unsigned int alignment)
{
if (pgio->pg_dreq == NULL)
return true;
if (!IS_ALIGNED(req->wb_offset, alignment))
return false;
if (IS_ALIGNED(req->wb_bytes, alignment))
return true;
if (req_offset(req) + req->wb_bytes == i_size_read(pgio->pg_inode)) {
return true;
}
return false;
}
static void
bl_pg_init_read(struct nfs_pageio_descriptor *pgio, struct nfs_page *req)
{
if (!is_aligned_req(pgio, req, SECTOR_SIZE)) {
nfs_pageio_reset_read_mds(pgio);
return;
}
pnfs_generic_pg_init_read(pgio, req);
}
static size_t
bl_pg_test_read(struct nfs_pageio_descriptor *pgio, struct nfs_page *prev,
struct nfs_page *req)
{
if (!is_aligned_req(pgio, req, SECTOR_SIZE))
return 0;
return pnfs_generic_pg_test(pgio, prev, req);
}
static u64 pnfs_num_cont_bytes(struct inode *inode, pgoff_t idx)
{
struct address_space *mapping = inode->i_mapping;
pgoff_t end;
end = DIV_ROUND_UP(i_size_read(inode), PAGE_CACHE_SIZE);
if (end != NFS_I(inode)->npages) {
rcu_read_lock();
end = page_cache_next_hole(mapping, idx + 1, ULONG_MAX);
rcu_read_unlock();
}
if (!end)
return i_size_read(inode) - (idx << PAGE_CACHE_SHIFT);
else
return (end - idx) << PAGE_CACHE_SHIFT;
}
static void
bl_pg_init_write(struct nfs_pageio_descriptor *pgio, struct nfs_page *req)
{
u64 wb_size;
if (!is_aligned_req(pgio, req, PAGE_SIZE)) {
nfs_pageio_reset_write_mds(pgio);
return;
}
if (pgio->pg_dreq == NULL)
wb_size = pnfs_num_cont_bytes(pgio->pg_inode,
req->wb_index);
else
wb_size = nfs_dreq_bytes_left(pgio->pg_dreq);
pnfs_generic_pg_init_write(pgio, req, wb_size);
}
static size_t
bl_pg_test_write(struct nfs_pageio_descriptor *pgio, struct nfs_page *prev,
struct nfs_page *req)
{
if (!is_aligned_req(pgio, req, PAGE_SIZE))
return 0;
return pnfs_generic_pg_test(pgio, prev, req);
}
static int __init nfs4blocklayout_init(void)
{
int ret;
dprintk("%s: NFSv4 Block Layout Driver Registering...\n", __func__);
ret = pnfs_register_layoutdriver(&blocklayout_type);
if (ret)
goto out;
ret = bl_init_pipefs();
if (ret)
goto out_unregister;
return 0;
out_unregister:
pnfs_unregister_layoutdriver(&blocklayout_type);
out:
return ret;
}
static void __exit nfs4blocklayout_exit(void)
{
dprintk("%s: NFSv4 Block Layout Driver Unregistering...\n",
__func__);
bl_cleanup_pipefs();
pnfs_unregister_layoutdriver(&blocklayout_type);
}
