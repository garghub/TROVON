static inline int vaddr_pagenr(struct pending_req *req, int seg)
{
return (req - blkbk->pending_reqs) *
BLKIF_MAX_SEGMENTS_PER_REQUEST + seg;
}
static inline unsigned long vaddr(struct pending_req *req, int seg)
{
unsigned long pfn = page_to_pfn(blkbk->pending_page(req, seg));
return (unsigned long)pfn_to_kaddr(pfn);
}
static struct pending_req *alloc_req(void)
{
struct pending_req *req = NULL;
unsigned long flags;
spin_lock_irqsave(&blkbk->pending_free_lock, flags);
if (!list_empty(&blkbk->pending_free)) {
req = list_entry(blkbk->pending_free.next, struct pending_req,
free_list);
list_del(&req->free_list);
}
spin_unlock_irqrestore(&blkbk->pending_free_lock, flags);
return req;
}
static void free_req(struct pending_req *req)
{
unsigned long flags;
int was_empty;
spin_lock_irqsave(&blkbk->pending_free_lock, flags);
was_empty = list_empty(&blkbk->pending_free);
list_add(&req->free_list, &blkbk->pending_free);
spin_unlock_irqrestore(&blkbk->pending_free_lock, flags);
if (was_empty)
wake_up(&blkbk->pending_free_wq);
}
static int xen_vbd_translate(struct phys_req *req, struct xen_blkif *blkif,
int operation)
{
struct xen_vbd *vbd = &blkif->vbd;
int rc = -EACCES;
if ((operation != READ) && vbd->readonly)
goto out;
if (likely(req->nr_sects)) {
blkif_sector_t end = req->sector_number + req->nr_sects;
if (unlikely(end < req->sector_number))
goto out;
if (unlikely(end > vbd_sz(vbd)))
goto out;
}
req->dev = vbd->pdevice;
req->bdev = vbd->bdev;
rc = 0;
out:
return rc;
}
static void xen_vbd_resize(struct xen_blkif *blkif)
{
struct xen_vbd *vbd = &blkif->vbd;
struct xenbus_transaction xbt;
int err;
struct xenbus_device *dev = xen_blkbk_xenbus(blkif->be);
unsigned long long new_size = vbd_sz(vbd);
pr_info(DRV_PFX "VBD Resize: Domid: %d, Device: (%d, %d)\n",
blkif->domid, MAJOR(vbd->pdevice), MINOR(vbd->pdevice));
pr_info(DRV_PFX "VBD Resize: new size %llu\n", new_size);
vbd->size = new_size;
again:
err = xenbus_transaction_start(&xbt);
if (err) {
pr_warn(DRV_PFX "Error starting transaction");
return;
}
err = xenbus_printf(xbt, dev->nodename, "sectors", "%llu",
(unsigned long long)vbd_sz(vbd));
if (err) {
pr_warn(DRV_PFX "Error writing new size");
goto abort;
}
err = xenbus_printf(xbt, dev->nodename, "state", "%d", dev->state);
if (err) {
pr_warn(DRV_PFX "Error writing the state");
goto abort;
}
err = xenbus_transaction_end(xbt, 0);
if (err == -EAGAIN)
goto again;
if (err)
pr_warn(DRV_PFX "Error ending transaction");
return;
abort:
xenbus_transaction_end(xbt, 1);
}
static void blkif_notify_work(struct xen_blkif *blkif)
{
blkif->waiting_reqs = 1;
wake_up(&blkif->wq);
}
irqreturn_t xen_blkif_be_int(int irq, void *dev_id)
{
blkif_notify_work(dev_id);
return IRQ_HANDLED;
}
static void print_stats(struct xen_blkif *blkif)
{
pr_info("xen-blkback (%s): oo %3d | rd %4d | wr %4d | f %4d"
" | ds %4d\n",
current->comm, blkif->st_oo_req,
blkif->st_rd_req, blkif->st_wr_req,
blkif->st_f_req, blkif->st_ds_req);
blkif->st_print = jiffies + msecs_to_jiffies(10 * 1000);
blkif->st_rd_req = 0;
blkif->st_wr_req = 0;
blkif->st_oo_req = 0;
blkif->st_ds_req = 0;
}
int xen_blkif_schedule(void *arg)
{
struct xen_blkif *blkif = arg;
struct xen_vbd *vbd = &blkif->vbd;
xen_blkif_get(blkif);
while (!kthread_should_stop()) {
if (try_to_freeze())
continue;
if (unlikely(vbd->size != vbd_sz(vbd)))
xen_vbd_resize(blkif);
wait_event_interruptible(
blkif->wq,
blkif->waiting_reqs || kthread_should_stop());
wait_event_interruptible(
blkbk->pending_free_wq,
!list_empty(&blkbk->pending_free) ||
kthread_should_stop());
blkif->waiting_reqs = 0;
smp_mb();
if (do_block_io_op(blkif))
blkif->waiting_reqs = 1;
if (log_stats && time_after(jiffies, blkif->st_print))
print_stats(blkif);
}
if (log_stats)
print_stats(blkif);
blkif->xenblkd = NULL;
xen_blkif_put(blkif);
return 0;
}
static void xen_blkbk_unmap(struct pending_req *req)
{
struct gnttab_unmap_grant_ref unmap[BLKIF_MAX_SEGMENTS_PER_REQUEST];
unsigned int i, invcount = 0;
grant_handle_t handle;
int ret;
for (i = 0; i < req->nr_pages; i++) {
handle = pending_handle(req, i);
if (handle == BLKBACK_INVALID_HANDLE)
continue;
gnttab_set_unmap_op(&unmap[invcount], vaddr(req, i),
GNTMAP_host_map, handle);
pending_handle(req, i) = BLKBACK_INVALID_HANDLE;
invcount++;
}
ret = HYPERVISOR_grant_table_op(
GNTTABOP_unmap_grant_ref, unmap, invcount);
BUG_ON(ret);
for (i = 0; i < invcount; i++) {
ret = m2p_remove_override(
virt_to_page(unmap[i].host_addr), false);
if (ret) {
pr_alert(DRV_PFX "Failed to remove M2P override for %lx\n",
(unsigned long)unmap[i].host_addr);
continue;
}
}
}
static int xen_blkbk_map(struct blkif_request *req,
struct pending_req *pending_req,
struct seg_buf seg[])
{
struct gnttab_map_grant_ref map[BLKIF_MAX_SEGMENTS_PER_REQUEST];
int i;
int nseg = req->nr_segments;
int ret = 0;
for (i = 0; i < nseg; i++) {
uint32_t flags;
flags = GNTMAP_host_map;
if (pending_req->operation != BLKIF_OP_READ)
flags |= GNTMAP_readonly;
gnttab_set_map_op(&map[i], vaddr(pending_req, i), flags,
req->u.rw.seg[i].gref,
pending_req->blkif->domid);
}
ret = HYPERVISOR_grant_table_op(GNTTABOP_map_grant_ref, map, nseg);
BUG_ON(ret);
for (i = 0; i < nseg; i++) {
if (unlikely(map[i].status != 0)) {
pr_debug(DRV_PFX "invalid buffer -- could not remap it\n");
map[i].handle = BLKBACK_INVALID_HANDLE;
ret |= 1;
}
pending_handle(pending_req, i) = map[i].handle;
if (ret)
continue;
ret = m2p_add_override(PFN_DOWN(map[i].dev_bus_addr),
blkbk->pending_page(pending_req, i), NULL);
if (ret) {
pr_alert(DRV_PFX "Failed to install M2P override for %lx (ret: %d)\n",
(unsigned long)map[i].dev_bus_addr, ret);
continue;
}
seg[i].buf = map[i].dev_bus_addr |
(req->u.rw.seg[i].first_sect << 9);
}
return ret;
}
static void xen_blk_discard(struct xen_blkif *blkif, struct blkif_request *req)
{
int err = 0;
int status = BLKIF_RSP_OKAY;
struct block_device *bdev = blkif->vbd.bdev;
if (blkif->blk_backend_type == BLKIF_BACKEND_PHY)
err = blkdev_issue_discard(bdev,
req->u.discard.sector_number,
req->u.discard.nr_sectors,
GFP_KERNEL, 0);
else if (blkif->blk_backend_type == BLKIF_BACKEND_FILE) {
struct loop_device *lo = bdev->bd_disk->private_data;
struct file *file = lo->lo_backing_file;
if (file->f_op->fallocate)
err = file->f_op->fallocate(file,
FALLOC_FL_KEEP_SIZE | FALLOC_FL_PUNCH_HOLE,
req->u.discard.sector_number << 9,
req->u.discard.nr_sectors << 9);
else
err = -EOPNOTSUPP;
} else
err = -EOPNOTSUPP;
if (err == -EOPNOTSUPP) {
pr_debug(DRV_PFX "discard op failed, not supported\n");
status = BLKIF_RSP_EOPNOTSUPP;
} else if (err)
status = BLKIF_RSP_ERROR;
make_response(blkif, req->id, req->operation, status);
}
static void xen_blk_drain_io(struct xen_blkif *blkif)
{
atomic_set(&blkif->drain, 1);
do {
if (atomic_read(&blkif->refcnt) <= 2)
break;
wait_for_completion_interruptible_timeout(
&blkif->drain_complete, HZ);
if (!atomic_read(&blkif->drain))
break;
} while (!kthread_should_stop());
atomic_set(&blkif->drain, 0);
}
static void __end_block_io_op(struct pending_req *pending_req, int error)
{
if ((pending_req->operation == BLKIF_OP_FLUSH_DISKCACHE) &&
(error == -EOPNOTSUPP)) {
pr_debug(DRV_PFX "flush diskcache op failed, not supported\n");
xen_blkbk_flush_diskcache(XBT_NIL, pending_req->blkif->be, 0);
pending_req->status = BLKIF_RSP_EOPNOTSUPP;
} else if ((pending_req->operation == BLKIF_OP_WRITE_BARRIER) &&
(error == -EOPNOTSUPP)) {
pr_debug(DRV_PFX "write barrier op failed, not supported\n");
xen_blkbk_barrier(XBT_NIL, pending_req->blkif->be, 0);
pending_req->status = BLKIF_RSP_EOPNOTSUPP;
} else if (error) {
pr_debug(DRV_PFX "Buffer not up-to-date at end of operation,"
" error=%d\n", error);
pending_req->status = BLKIF_RSP_ERROR;
}
if (atomic_dec_and_test(&pending_req->pendcnt)) {
xen_blkbk_unmap(pending_req);
make_response(pending_req->blkif, pending_req->id,
pending_req->operation, pending_req->status);
xen_blkif_put(pending_req->blkif);
if (atomic_read(&pending_req->blkif->refcnt) <= 2) {
if (atomic_read(&pending_req->blkif->drain))
complete(&pending_req->blkif->drain_complete);
}
free_req(pending_req);
}
}
static void end_block_io_op(struct bio *bio, int error)
{
__end_block_io_op(bio->bi_private, error);
bio_put(bio);
}
static int
__do_block_io_op(struct xen_blkif *blkif)
{
union blkif_back_rings *blk_rings = &blkif->blk_rings;
struct blkif_request req;
struct pending_req *pending_req;
RING_IDX rc, rp;
int more_to_do = 0;
rc = blk_rings->common.req_cons;
rp = blk_rings->common.sring->req_prod;
rmb();
while (rc != rp) {
if (RING_REQUEST_CONS_OVERFLOW(&blk_rings->common, rc))
break;
if (kthread_should_stop()) {
more_to_do = 1;
break;
}
pending_req = alloc_req();
if (NULL == pending_req) {
blkif->st_oo_req++;
more_to_do = 1;
break;
}
switch (blkif->blk_protocol) {
case BLKIF_PROTOCOL_NATIVE:
memcpy(&req, RING_GET_REQUEST(&blk_rings->native, rc), sizeof(req));
break;
case BLKIF_PROTOCOL_X86_32:
blkif_get_x86_32_req(&req, RING_GET_REQUEST(&blk_rings->x86_32, rc));
break;
case BLKIF_PROTOCOL_X86_64:
blkif_get_x86_64_req(&req, RING_GET_REQUEST(&blk_rings->x86_64, rc));
break;
default:
BUG();
}
blk_rings->common.req_cons = ++rc;
barrier();
if (dispatch_rw_block_io(blkif, &req, pending_req))
break;
cond_resched();
}
return more_to_do;
}
static int
do_block_io_op(struct xen_blkif *blkif)
{
union blkif_back_rings *blk_rings = &blkif->blk_rings;
int more_to_do;
do {
more_to_do = __do_block_io_op(blkif);
if (more_to_do)
break;
RING_FINAL_CHECK_FOR_REQUESTS(&blk_rings->common, more_to_do);
} while (more_to_do);
return more_to_do;
}
static int dispatch_rw_block_io(struct xen_blkif *blkif,
struct blkif_request *req,
struct pending_req *pending_req)
{
struct phys_req preq;
struct seg_buf seg[BLKIF_MAX_SEGMENTS_PER_REQUEST];
unsigned int nseg;
struct bio *bio = NULL;
struct bio *biolist[BLKIF_MAX_SEGMENTS_PER_REQUEST];
int i, nbio = 0;
int operation;
struct blk_plug plug;
bool drain = false;
switch (req->operation) {
case BLKIF_OP_READ:
blkif->st_rd_req++;
operation = READ;
break;
case BLKIF_OP_WRITE:
blkif->st_wr_req++;
operation = WRITE_ODIRECT;
break;
case BLKIF_OP_WRITE_BARRIER:
drain = true;
case BLKIF_OP_FLUSH_DISKCACHE:
blkif->st_f_req++;
operation = WRITE_FLUSH;
break;
case BLKIF_OP_DISCARD:
blkif->st_ds_req++;
operation = REQ_DISCARD;
break;
default:
operation = 0;
goto fail_response;
break;
}
nseg = req->nr_segments;
if (unlikely(nseg == 0 && operation != WRITE_FLUSH &&
operation != REQ_DISCARD) ||
unlikely(nseg > BLKIF_MAX_SEGMENTS_PER_REQUEST)) {
pr_debug(DRV_PFX "Bad number of segments in request (%d)\n",
nseg);
goto fail_response;
}
preq.dev = req->handle;
preq.sector_number = req->u.rw.sector_number;
preq.nr_sects = 0;
pending_req->blkif = blkif;
pending_req->id = req->id;
pending_req->operation = req->operation;
pending_req->status = BLKIF_RSP_OKAY;
pending_req->nr_pages = nseg;
for (i = 0; i < nseg; i++) {
seg[i].nsec = req->u.rw.seg[i].last_sect -
req->u.rw.seg[i].first_sect + 1;
if ((req->u.rw.seg[i].last_sect >= (PAGE_SIZE >> 9)) ||
(req->u.rw.seg[i].last_sect < req->u.rw.seg[i].first_sect))
goto fail_response;
preq.nr_sects += seg[i].nsec;
}
if (xen_vbd_translate(&preq, blkif, operation) != 0) {
pr_debug(DRV_PFX "access denied: %s of [%llu,%llu] on dev=%04x\n",
operation == READ ? "read" : "write",
preq.sector_number,
preq.sector_number + preq.nr_sects, preq.dev);
goto fail_response;
}
for (i = 0; i < nseg; i++) {
if (((int)preq.sector_number|(int)seg[i].nsec) &
((bdev_logical_block_size(preq.bdev) >> 9) - 1)) {
pr_debug(DRV_PFX "Misaligned I/O request from domain %d",
blkif->domid);
goto fail_response;
}
}
if (drain)
xen_blk_drain_io(pending_req->blkif);
if (operation != REQ_DISCARD && xen_blkbk_map(req, pending_req, seg))
goto fail_flush;
xen_blkif_get(blkif);
for (i = 0; i < nseg; i++) {
while ((bio == NULL) ||
(bio_add_page(bio,
blkbk->pending_page(pending_req, i),
seg[i].nsec << 9,
seg[i].buf & ~PAGE_MASK) == 0)) {
bio = bio_alloc(GFP_KERNEL, nseg-i);
if (unlikely(bio == NULL))
goto fail_put_bio;
biolist[nbio++] = bio;
bio->bi_bdev = preq.bdev;
bio->bi_private = pending_req;
bio->bi_end_io = end_block_io_op;
bio->bi_sector = preq.sector_number;
}
preq.sector_number += seg[i].nsec;
}
if (!bio) {
BUG_ON(operation != WRITE_FLUSH && operation != REQ_DISCARD);
if (operation == WRITE_FLUSH) {
bio = bio_alloc(GFP_KERNEL, 0);
if (unlikely(bio == NULL))
goto fail_put_bio;
biolist[nbio++] = bio;
bio->bi_bdev = preq.bdev;
bio->bi_private = pending_req;
bio->bi_end_io = end_block_io_op;
} else if (operation == REQ_DISCARD) {
xen_blk_discard(blkif, req);
xen_blkif_put(blkif);
free_req(pending_req);
return 0;
}
}
atomic_set(&pending_req->pendcnt, nbio);
blk_start_plug(&plug);
for (i = 0; i < nbio; i++)
submit_bio(operation, biolist[i]);
blk_finish_plug(&plug);
if (operation == READ)
blkif->st_rd_sect += preq.nr_sects;
else if (operation & WRITE)
blkif->st_wr_sect += preq.nr_sects;
return 0;
fail_flush:
xen_blkbk_unmap(pending_req);
fail_response:
make_response(blkif, req->id, req->operation, BLKIF_RSP_ERROR);
free_req(pending_req);
msleep(1);
return -EIO;
fail_put_bio:
for (i = 0; i < nbio; i++)
bio_put(biolist[i]);
__end_block_io_op(pending_req, -EINVAL);
msleep(1);
return -EIO;
}
static void make_response(struct xen_blkif *blkif, u64 id,
unsigned short op, int st)
{
struct blkif_response resp;
unsigned long flags;
union blkif_back_rings *blk_rings = &blkif->blk_rings;
int notify;
resp.id = id;
resp.operation = op;
resp.status = st;
spin_lock_irqsave(&blkif->blk_ring_lock, flags);
switch (blkif->blk_protocol) {
case BLKIF_PROTOCOL_NATIVE:
memcpy(RING_GET_RESPONSE(&blk_rings->native, blk_rings->native.rsp_prod_pvt),
&resp, sizeof(resp));
break;
case BLKIF_PROTOCOL_X86_32:
memcpy(RING_GET_RESPONSE(&blk_rings->x86_32, blk_rings->x86_32.rsp_prod_pvt),
&resp, sizeof(resp));
break;
case BLKIF_PROTOCOL_X86_64:
memcpy(RING_GET_RESPONSE(&blk_rings->x86_64, blk_rings->x86_64.rsp_prod_pvt),
&resp, sizeof(resp));
break;
default:
BUG();
}
blk_rings->common.rsp_prod_pvt++;
RING_PUSH_RESPONSES_AND_CHECK_NOTIFY(&blk_rings->common, notify);
spin_unlock_irqrestore(&blkif->blk_ring_lock, flags);
if (notify)
notify_remote_via_irq(blkif->irq);
}
static int __init xen_blkif_init(void)
{
int i, mmap_pages;
int rc = 0;
if (!xen_pv_domain())
return -ENODEV;
blkbk = kzalloc(sizeof(struct xen_blkbk), GFP_KERNEL);
if (!blkbk) {
pr_alert(DRV_PFX "%s: out of memory!\n", __func__);
return -ENOMEM;
}
mmap_pages = xen_blkif_reqs * BLKIF_MAX_SEGMENTS_PER_REQUEST;
blkbk->pending_reqs = kzalloc(sizeof(blkbk->pending_reqs[0]) *
xen_blkif_reqs, GFP_KERNEL);
blkbk->pending_grant_handles = kmalloc(sizeof(blkbk->pending_grant_handles[0]) *
mmap_pages, GFP_KERNEL);
blkbk->pending_pages = kzalloc(sizeof(blkbk->pending_pages[0]) *
mmap_pages, GFP_KERNEL);
if (!blkbk->pending_reqs || !blkbk->pending_grant_handles ||
!blkbk->pending_pages) {
rc = -ENOMEM;
goto out_of_memory;
}
for (i = 0; i < mmap_pages; i++) {
blkbk->pending_grant_handles[i] = BLKBACK_INVALID_HANDLE;
blkbk->pending_pages[i] = alloc_page(GFP_KERNEL);
if (blkbk->pending_pages[i] == NULL) {
rc = -ENOMEM;
goto out_of_memory;
}
}
rc = xen_blkif_interface_init();
if (rc)
goto failed_init;
INIT_LIST_HEAD(&blkbk->pending_free);
spin_lock_init(&blkbk->pending_free_lock);
init_waitqueue_head(&blkbk->pending_free_wq);
for (i = 0; i < xen_blkif_reqs; i++)
list_add_tail(&blkbk->pending_reqs[i].free_list,
&blkbk->pending_free);
rc = xen_blkif_xenbus_init();
if (rc)
goto failed_init;
return 0;
out_of_memory:
pr_alert(DRV_PFX "%s: out of memory\n", __func__);
failed_init:
kfree(blkbk->pending_reqs);
kfree(blkbk->pending_grant_handles);
if (blkbk->pending_pages) {
for (i = 0; i < mmap_pages; i++) {
if (blkbk->pending_pages[i])
__free_page(blkbk->pending_pages[i]);
}
kfree(blkbk->pending_pages);
}
kfree(blkbk);
blkbk = NULL;
return rc;
}
