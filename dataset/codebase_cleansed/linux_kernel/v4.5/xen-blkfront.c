static int get_id_from_freelist(struct blkfront_ring_info *rinfo)
{
unsigned long free = rinfo->shadow_free;
BUG_ON(free >= BLK_RING_SIZE(rinfo->dev_info));
rinfo->shadow_free = rinfo->shadow[free].req.u.rw.id;
rinfo->shadow[free].req.u.rw.id = 0x0fffffee;
return free;
}
static int add_id_to_freelist(struct blkfront_ring_info *rinfo,
unsigned long id)
{
if (rinfo->shadow[id].req.u.rw.id != id)
return -EINVAL;
if (rinfo->shadow[id].request == NULL)
return -EINVAL;
rinfo->shadow[id].req.u.rw.id = rinfo->shadow_free;
rinfo->shadow[id].request = NULL;
rinfo->shadow_free = id;
return 0;
}
static int fill_grant_buffer(struct blkfront_ring_info *rinfo, int num)
{
struct blkfront_info *info = rinfo->dev_info;
struct page *granted_page;
struct grant *gnt_list_entry, *n;
int i = 0;
while (i < num) {
gnt_list_entry = kzalloc(sizeof(struct grant), GFP_NOIO);
if (!gnt_list_entry)
goto out_of_memory;
if (info->feature_persistent) {
granted_page = alloc_page(GFP_NOIO);
if (!granted_page) {
kfree(gnt_list_entry);
goto out_of_memory;
}
gnt_list_entry->page = granted_page;
}
gnt_list_entry->gref = GRANT_INVALID_REF;
list_add(&gnt_list_entry->node, &rinfo->grants);
i++;
}
return 0;
out_of_memory:
list_for_each_entry_safe(gnt_list_entry, n,
&rinfo->grants, node) {
list_del(&gnt_list_entry->node);
if (info->feature_persistent)
__free_page(gnt_list_entry->page);
kfree(gnt_list_entry);
i--;
}
BUG_ON(i != 0);
return -ENOMEM;
}
static struct grant *get_free_grant(struct blkfront_ring_info *rinfo)
{
struct grant *gnt_list_entry;
BUG_ON(list_empty(&rinfo->grants));
gnt_list_entry = list_first_entry(&rinfo->grants, struct grant,
node);
list_del(&gnt_list_entry->node);
if (gnt_list_entry->gref != GRANT_INVALID_REF)
rinfo->persistent_gnts_c--;
return gnt_list_entry;
}
static inline void grant_foreign_access(const struct grant *gnt_list_entry,
const struct blkfront_info *info)
{
gnttab_page_grant_foreign_access_ref_one(gnt_list_entry->gref,
info->xbdev->otherend_id,
gnt_list_entry->page,
0);
}
static struct grant *get_grant(grant_ref_t *gref_head,
unsigned long gfn,
struct blkfront_ring_info *rinfo)
{
struct grant *gnt_list_entry = get_free_grant(rinfo);
struct blkfront_info *info = rinfo->dev_info;
if (gnt_list_entry->gref != GRANT_INVALID_REF)
return gnt_list_entry;
gnt_list_entry->gref = gnttab_claim_grant_reference(gref_head);
BUG_ON(gnt_list_entry->gref == -ENOSPC);
if (info->feature_persistent)
grant_foreign_access(gnt_list_entry, info);
else {
gnttab_grant_foreign_access_ref(gnt_list_entry->gref,
info->xbdev->otherend_id,
gfn, 0);
}
return gnt_list_entry;
}
static struct grant *get_indirect_grant(grant_ref_t *gref_head,
struct blkfront_ring_info *rinfo)
{
struct grant *gnt_list_entry = get_free_grant(rinfo);
struct blkfront_info *info = rinfo->dev_info;
if (gnt_list_entry->gref != GRANT_INVALID_REF)
return gnt_list_entry;
gnt_list_entry->gref = gnttab_claim_grant_reference(gref_head);
BUG_ON(gnt_list_entry->gref == -ENOSPC);
if (!info->feature_persistent) {
struct page *indirect_page;
BUG_ON(list_empty(&rinfo->indirect_pages));
indirect_page = list_first_entry(&rinfo->indirect_pages,
struct page, lru);
list_del(&indirect_page->lru);
gnt_list_entry->page = indirect_page;
}
grant_foreign_access(gnt_list_entry, info);
return gnt_list_entry;
}
static const char *op_name(int op)
{
static const char *const names[] = {
[BLKIF_OP_READ] = "read",
[BLKIF_OP_WRITE] = "write",
[BLKIF_OP_WRITE_BARRIER] = "barrier",
[BLKIF_OP_FLUSH_DISKCACHE] = "flush",
[BLKIF_OP_DISCARD] = "discard" };
if (op < 0 || op >= ARRAY_SIZE(names))
return "unknown";
if (!names[op])
return "reserved";
return names[op];
}
static int xlbd_reserve_minors(unsigned int minor, unsigned int nr)
{
unsigned int end = minor + nr;
int rc;
if (end > nr_minors) {
unsigned long *bitmap, *old;
bitmap = kcalloc(BITS_TO_LONGS(end), sizeof(*bitmap),
GFP_KERNEL);
if (bitmap == NULL)
return -ENOMEM;
spin_lock(&minor_lock);
if (end > nr_minors) {
old = minors;
memcpy(bitmap, minors,
BITS_TO_LONGS(nr_minors) * sizeof(*bitmap));
minors = bitmap;
nr_minors = BITS_TO_LONGS(end) * BITS_PER_LONG;
} else
old = bitmap;
spin_unlock(&minor_lock);
kfree(old);
}
spin_lock(&minor_lock);
if (find_next_bit(minors, end, minor) >= end) {
bitmap_set(minors, minor, nr);
rc = 0;
} else
rc = -EBUSY;
spin_unlock(&minor_lock);
return rc;
}
static void xlbd_release_minors(unsigned int minor, unsigned int nr)
{
unsigned int end = minor + nr;
BUG_ON(end > nr_minors);
spin_lock(&minor_lock);
bitmap_clear(minors, minor, nr);
spin_unlock(&minor_lock);
}
static void blkif_restart_queue_callback(void *arg)
{
struct blkfront_ring_info *rinfo = (struct blkfront_ring_info *)arg;
schedule_work(&rinfo->work);
}
static int blkif_getgeo(struct block_device *bd, struct hd_geometry *hg)
{
sector_t nsect = get_capacity(bd->bd_disk);
sector_t cylinders = nsect;
hg->heads = 0xff;
hg->sectors = 0x3f;
sector_div(cylinders, hg->heads * hg->sectors);
hg->cylinders = cylinders;
if ((sector_t)(hg->cylinders + 1) * hg->heads * hg->sectors < nsect)
hg->cylinders = 0xffff;
return 0;
}
static int blkif_ioctl(struct block_device *bdev, fmode_t mode,
unsigned command, unsigned long argument)
{
struct blkfront_info *info = bdev->bd_disk->private_data;
int i;
dev_dbg(&info->xbdev->dev, "command: 0x%x, argument: 0x%lx\n",
command, (long)argument);
switch (command) {
case CDROMMULTISESSION:
dev_dbg(&info->xbdev->dev, "FIXME: support multisession CDs later\n");
for (i = 0; i < sizeof(struct cdrom_multisession); i++)
if (put_user(0, (char __user *)(argument + i)))
return -EFAULT;
return 0;
case CDROM_GET_CAPABILITY: {
struct gendisk *gd = info->gd;
if (gd->flags & GENHD_FL_CD)
return 0;
return -EINVAL;
}
default:
return -EINVAL;
}
return 0;
}
static unsigned long blkif_ring_get_request(struct blkfront_ring_info *rinfo,
struct request *req,
struct blkif_request **ring_req)
{
unsigned long id;
*ring_req = RING_GET_REQUEST(&rinfo->ring, rinfo->ring.req_prod_pvt);
rinfo->ring.req_prod_pvt++;
id = get_id_from_freelist(rinfo);
rinfo->shadow[id].request = req;
rinfo->shadow[id].status = REQ_WAITING;
rinfo->shadow[id].associated_id = NO_ASSOCIATED_ID;
(*ring_req)->u.rw.id = id;
return id;
}
static int blkif_queue_discard_req(struct request *req, struct blkfront_ring_info *rinfo)
{
struct blkfront_info *info = rinfo->dev_info;
struct blkif_request *ring_req;
unsigned long id;
id = blkif_ring_get_request(rinfo, req, &ring_req);
ring_req->operation = BLKIF_OP_DISCARD;
ring_req->u.discard.nr_sectors = blk_rq_sectors(req);
ring_req->u.discard.id = id;
ring_req->u.discard.sector_number = (blkif_sector_t)blk_rq_pos(req);
if ((req->cmd_flags & REQ_SECURE) && info->feature_secdiscard)
ring_req->u.discard.flag = BLKIF_DISCARD_SECURE;
else
ring_req->u.discard.flag = 0;
rinfo->shadow[id].req = *ring_req;
return 0;
}
static void blkif_setup_rw_req_grant(unsigned long gfn, unsigned int offset,
unsigned int len, void *data)
{
struct setup_rw_req *setup = data;
int n, ref;
struct grant *gnt_list_entry;
unsigned int fsect, lsect;
unsigned int grant_idx = setup->grant_idx;
struct blkif_request *ring_req = setup->ring_req;
struct blkfront_ring_info *rinfo = setup->rinfo;
struct blk_shadow *shadow = &rinfo->shadow[setup->id];
if (unlikely(setup->require_extra_req &&
grant_idx >= BLKIF_MAX_SEGMENTS_PER_REQUEST)) {
grant_idx -= BLKIF_MAX_SEGMENTS_PER_REQUEST;
ring_req = setup->extra_ring_req;
}
if ((ring_req->operation == BLKIF_OP_INDIRECT) &&
(grant_idx % GRANTS_PER_INDIRECT_FRAME == 0)) {
if (setup->segments)
kunmap_atomic(setup->segments);
n = grant_idx / GRANTS_PER_INDIRECT_FRAME;
gnt_list_entry = get_indirect_grant(&setup->gref_head, rinfo);
shadow->indirect_grants[n] = gnt_list_entry;
setup->segments = kmap_atomic(gnt_list_entry->page);
ring_req->u.indirect.indirect_grefs[n] = gnt_list_entry->gref;
}
gnt_list_entry = get_grant(&setup->gref_head, gfn, rinfo);
ref = gnt_list_entry->gref;
shadow->grants_used[setup->grant_idx] = gnt_list_entry;
if (setup->need_copy) {
void *shared_data;
shared_data = kmap_atomic(gnt_list_entry->page);
memcpy(shared_data + offset,
setup->bvec_data + setup->bvec_off,
len);
kunmap_atomic(shared_data);
setup->bvec_off += len;
}
fsect = offset >> 9;
lsect = fsect + (len >> 9) - 1;
if (ring_req->operation != BLKIF_OP_INDIRECT) {
ring_req->u.rw.seg[grant_idx] =
(struct blkif_request_segment) {
.gref = ref,
.first_sect = fsect,
.last_sect = lsect };
} else {
setup->segments[grant_idx % GRANTS_PER_INDIRECT_FRAME] =
(struct blkif_request_segment) {
.gref = ref,
.first_sect = fsect,
.last_sect = lsect };
}
(setup->grant_idx)++;
}
static void blkif_setup_extra_req(struct blkif_request *first,
struct blkif_request *second)
{
uint16_t nr_segments = first->u.rw.nr_segments;
first->u.rw.nr_segments = BLKIF_MAX_SEGMENTS_PER_REQUEST;
second->u.rw.nr_segments = nr_segments - BLKIF_MAX_SEGMENTS_PER_REQUEST;
second->u.rw.sector_number = first->u.rw.sector_number +
(BLKIF_MAX_SEGMENTS_PER_REQUEST * XEN_PAGE_SIZE) / 512;
second->u.rw.handle = first->u.rw.handle;
second->operation = first->operation;
}
static int blkif_queue_rw_req(struct request *req, struct blkfront_ring_info *rinfo)
{
struct blkfront_info *info = rinfo->dev_info;
struct blkif_request *ring_req, *extra_ring_req = NULL;
unsigned long id, extra_id = NO_ASSOCIATED_ID;
bool require_extra_req = false;
int i;
struct setup_rw_req setup = {
.grant_idx = 0,
.segments = NULL,
.rinfo = rinfo,
.need_copy = rq_data_dir(req) && info->feature_persistent,
};
struct scatterlist *sg;
int num_sg, max_grefs, num_grant;
max_grefs = req->nr_phys_segments * GRANTS_PER_PSEG;
if (max_grefs > BLKIF_MAX_SEGMENTS_PER_REQUEST)
max_grefs += INDIRECT_GREFS(max_grefs);
if (max_grefs > 0)
if (gnttab_alloc_grant_references(max_grefs, &setup.gref_head) < 0) {
gnttab_request_free_callback(
&rinfo->callback,
blkif_restart_queue_callback,
rinfo,
max_grefs);
return 1;
}
id = blkif_ring_get_request(rinfo, req, &ring_req);
num_sg = blk_rq_map_sg(req->q, req, rinfo->shadow[id].sg);
num_grant = 0;
for_each_sg(rinfo->shadow[id].sg, sg, num_sg, i)
num_grant += gnttab_count_grant(sg->offset, sg->length);
require_extra_req = info->max_indirect_segments == 0 &&
num_grant > BLKIF_MAX_SEGMENTS_PER_REQUEST;
BUG_ON(!HAS_EXTRA_REQ && require_extra_req);
rinfo->shadow[id].num_sg = num_sg;
if (num_grant > BLKIF_MAX_SEGMENTS_PER_REQUEST &&
likely(!require_extra_req)) {
BUG_ON(req->cmd_flags & (REQ_FLUSH | REQ_FUA));
ring_req->operation = BLKIF_OP_INDIRECT;
ring_req->u.indirect.indirect_op = rq_data_dir(req) ?
BLKIF_OP_WRITE : BLKIF_OP_READ;
ring_req->u.indirect.sector_number = (blkif_sector_t)blk_rq_pos(req);
ring_req->u.indirect.handle = info->handle;
ring_req->u.indirect.nr_segments = num_grant;
} else {
ring_req->u.rw.sector_number = (blkif_sector_t)blk_rq_pos(req);
ring_req->u.rw.handle = info->handle;
ring_req->operation = rq_data_dir(req) ?
BLKIF_OP_WRITE : BLKIF_OP_READ;
if (req->cmd_flags & (REQ_FLUSH | REQ_FUA)) {
switch (info->feature_flush &
((REQ_FLUSH|REQ_FUA))) {
case REQ_FLUSH|REQ_FUA:
ring_req->operation =
BLKIF_OP_WRITE_BARRIER;
break;
case REQ_FLUSH:
ring_req->operation =
BLKIF_OP_FLUSH_DISKCACHE;
break;
default:
ring_req->operation = 0;
}
}
ring_req->u.rw.nr_segments = num_grant;
if (unlikely(require_extra_req)) {
extra_id = blkif_ring_get_request(rinfo, req,
&extra_ring_req);
rinfo->shadow[extra_id].num_sg = 0;
blkif_setup_extra_req(ring_req, extra_ring_req);
rinfo->shadow[extra_id].associated_id = id;
rinfo->shadow[id].associated_id = extra_id;
}
}
setup.ring_req = ring_req;
setup.id = id;
setup.require_extra_req = require_extra_req;
if (unlikely(require_extra_req))
setup.extra_ring_req = extra_ring_req;
for_each_sg(rinfo->shadow[id].sg, sg, num_sg, i) {
BUG_ON(sg->offset + sg->length > PAGE_SIZE);
if (setup.need_copy) {
setup.bvec_off = sg->offset;
setup.bvec_data = kmap_atomic(sg_page(sg));
}
gnttab_foreach_grant_in_range(sg_page(sg),
sg->offset,
sg->length,
blkif_setup_rw_req_grant,
&setup);
if (setup.need_copy)
kunmap_atomic(setup.bvec_data);
}
if (setup.segments)
kunmap_atomic(setup.segments);
rinfo->shadow[id].req = *ring_req;
if (unlikely(require_extra_req))
rinfo->shadow[extra_id].req = *extra_ring_req;
if (max_grefs > 0)
gnttab_free_grant_references(setup.gref_head);
return 0;
}
static int blkif_queue_request(struct request *req, struct blkfront_ring_info *rinfo)
{
if (unlikely(rinfo->dev_info->connected != BLKIF_STATE_CONNECTED))
return 1;
if (unlikely(req->cmd_flags & (REQ_DISCARD | REQ_SECURE)))
return blkif_queue_discard_req(req, rinfo);
else
return blkif_queue_rw_req(req, rinfo);
}
static inline void flush_requests(struct blkfront_ring_info *rinfo)
{
int notify;
RING_PUSH_REQUESTS_AND_CHECK_NOTIFY(&rinfo->ring, notify);
if (notify)
notify_remote_via_irq(rinfo->irq);
}
static inline bool blkif_request_flush_invalid(struct request *req,
struct blkfront_info *info)
{
return ((req->cmd_type != REQ_TYPE_FS) ||
((req->cmd_flags & REQ_FLUSH) &&
!(info->feature_flush & REQ_FLUSH)) ||
((req->cmd_flags & REQ_FUA) &&
!(info->feature_flush & REQ_FUA)));
}
static int blkif_queue_rq(struct blk_mq_hw_ctx *hctx,
const struct blk_mq_queue_data *qd)
{
unsigned long flags;
struct blkfront_ring_info *rinfo = (struct blkfront_ring_info *)hctx->driver_data;
blk_mq_start_request(qd->rq);
spin_lock_irqsave(&rinfo->ring_lock, flags);
if (RING_FULL(&rinfo->ring))
goto out_busy;
if (blkif_request_flush_invalid(qd->rq, rinfo->dev_info))
goto out_err;
if (blkif_queue_request(qd->rq, rinfo))
goto out_busy;
flush_requests(rinfo);
spin_unlock_irqrestore(&rinfo->ring_lock, flags);
return BLK_MQ_RQ_QUEUE_OK;
out_err:
spin_unlock_irqrestore(&rinfo->ring_lock, flags);
return BLK_MQ_RQ_QUEUE_ERROR;
out_busy:
spin_unlock_irqrestore(&rinfo->ring_lock, flags);
blk_mq_stop_hw_queue(hctx);
return BLK_MQ_RQ_QUEUE_BUSY;
}
static int blk_mq_init_hctx(struct blk_mq_hw_ctx *hctx, void *data,
unsigned int index)
{
struct blkfront_info *info = (struct blkfront_info *)data;
BUG_ON(info->nr_rings <= index);
hctx->driver_data = &info->rinfo[index];
return 0;
}
static int xlvbd_init_blk_queue(struct gendisk *gd, u16 sector_size,
unsigned int physical_sector_size,
unsigned int segments)
{
struct request_queue *rq;
struct blkfront_info *info = gd->private_data;
memset(&info->tag_set, 0, sizeof(info->tag_set));
info->tag_set.ops = &blkfront_mq_ops;
info->tag_set.nr_hw_queues = info->nr_rings;
if (HAS_EXTRA_REQ && info->max_indirect_segments == 0) {
info->tag_set.queue_depth = BLK_RING_SIZE(info) / 2;
} else
info->tag_set.queue_depth = BLK_RING_SIZE(info);
info->tag_set.numa_node = NUMA_NO_NODE;
info->tag_set.flags = BLK_MQ_F_SHOULD_MERGE | BLK_MQ_F_SG_MERGE;
info->tag_set.cmd_size = 0;
info->tag_set.driver_data = info;
if (blk_mq_alloc_tag_set(&info->tag_set))
return -EINVAL;
rq = blk_mq_init_queue(&info->tag_set);
if (IS_ERR(rq)) {
blk_mq_free_tag_set(&info->tag_set);
return PTR_ERR(rq);
}
queue_flag_set_unlocked(QUEUE_FLAG_VIRT, rq);
if (info->feature_discard) {
queue_flag_set_unlocked(QUEUE_FLAG_DISCARD, rq);
blk_queue_max_discard_sectors(rq, get_capacity(gd));
rq->limits.discard_granularity = info->discard_granularity;
rq->limits.discard_alignment = info->discard_alignment;
if (info->feature_secdiscard)
queue_flag_set_unlocked(QUEUE_FLAG_SECDISCARD, rq);
}
blk_queue_logical_block_size(rq, sector_size);
blk_queue_physical_block_size(rq, physical_sector_size);
blk_queue_max_hw_sectors(rq, (segments * XEN_PAGE_SIZE) / 512);
blk_queue_segment_boundary(rq, PAGE_SIZE - 1);
blk_queue_max_segment_size(rq, PAGE_SIZE);
blk_queue_max_segments(rq, segments / GRANTS_PER_PSEG);
blk_queue_dma_alignment(rq, 511);
blk_queue_bounce_limit(rq, BLK_BOUNCE_ANY);
gd->queue = rq;
return 0;
}
static const char *flush_info(unsigned int feature_flush)
{
switch (feature_flush & ((REQ_FLUSH | REQ_FUA))) {
case REQ_FLUSH|REQ_FUA:
return "barrier: enabled;";
case REQ_FLUSH:
return "flush diskcache: enabled;";
default:
return "barrier or flush: disabled;";
}
}
static void xlvbd_flush(struct blkfront_info *info)
{
blk_queue_flush(info->rq, info->feature_flush);
pr_info("blkfront: %s: %s %s %s %s %s\n",
info->gd->disk_name, flush_info(info->feature_flush),
"persistent grants:", info->feature_persistent ?
"enabled;" : "disabled;", "indirect descriptors:",
info->max_indirect_segments ? "enabled;" : "disabled;");
}
static int xen_translate_vdev(int vdevice, int *minor, unsigned int *offset)
{
int major;
major = BLKIF_MAJOR(vdevice);
*minor = BLKIF_MINOR(vdevice);
switch (major) {
case XEN_IDE0_MAJOR:
*offset = (*minor / 64) + EMULATED_HD_DISK_NAME_OFFSET;
*minor = ((*minor / 64) * PARTS_PER_DISK) +
EMULATED_HD_DISK_MINOR_OFFSET;
break;
case XEN_IDE1_MAJOR:
*offset = (*minor / 64) + 2 + EMULATED_HD_DISK_NAME_OFFSET;
*minor = (((*minor / 64) + 2) * PARTS_PER_DISK) +
EMULATED_HD_DISK_MINOR_OFFSET;
break;
case XEN_SCSI_DISK0_MAJOR:
*offset = (*minor / PARTS_PER_DISK) + EMULATED_SD_DISK_NAME_OFFSET;
*minor = *minor + EMULATED_SD_DISK_MINOR_OFFSET;
break;
case XEN_SCSI_DISK1_MAJOR:
case XEN_SCSI_DISK2_MAJOR:
case XEN_SCSI_DISK3_MAJOR:
case XEN_SCSI_DISK4_MAJOR:
case XEN_SCSI_DISK5_MAJOR:
case XEN_SCSI_DISK6_MAJOR:
case XEN_SCSI_DISK7_MAJOR:
*offset = (*minor / PARTS_PER_DISK) +
((major - XEN_SCSI_DISK1_MAJOR + 1) * 16) +
EMULATED_SD_DISK_NAME_OFFSET;
*minor = *minor +
((major - XEN_SCSI_DISK1_MAJOR + 1) * 16 * PARTS_PER_DISK) +
EMULATED_SD_DISK_MINOR_OFFSET;
break;
case XEN_SCSI_DISK8_MAJOR:
case XEN_SCSI_DISK9_MAJOR:
case XEN_SCSI_DISK10_MAJOR:
case XEN_SCSI_DISK11_MAJOR:
case XEN_SCSI_DISK12_MAJOR:
case XEN_SCSI_DISK13_MAJOR:
case XEN_SCSI_DISK14_MAJOR:
case XEN_SCSI_DISK15_MAJOR:
*offset = (*minor / PARTS_PER_DISK) +
((major - XEN_SCSI_DISK8_MAJOR + 8) * 16) +
EMULATED_SD_DISK_NAME_OFFSET;
*minor = *minor +
((major - XEN_SCSI_DISK8_MAJOR + 8) * 16 * PARTS_PER_DISK) +
EMULATED_SD_DISK_MINOR_OFFSET;
break;
case XENVBD_MAJOR:
*offset = *minor / PARTS_PER_DISK;
break;
default:
printk(KERN_WARNING "blkfront: your disk configuration is "
"incorrect, please use an xvd device instead\n");
return -ENODEV;
}
return 0;
}
static char *encode_disk_name(char *ptr, unsigned int n)
{
if (n >= 26)
ptr = encode_disk_name(ptr, n / 26 - 1);
*ptr = 'a' + n % 26;
return ptr + 1;
}
static int xlvbd_alloc_gendisk(blkif_sector_t capacity,
struct blkfront_info *info,
u16 vdisk_info, u16 sector_size,
unsigned int physical_sector_size)
{
struct gendisk *gd;
int nr_minors = 1;
int err;
unsigned int offset;
int minor;
int nr_parts;
char *ptr;
BUG_ON(info->gd != NULL);
BUG_ON(info->rq != NULL);
if ((info->vdevice>>EXT_SHIFT) > 1) {
printk(KERN_WARNING "blkfront: vdevice 0x%x is above the extended range; ignoring\n", info->vdevice);
return -ENODEV;
}
if (!VDEV_IS_EXTENDED(info->vdevice)) {
err = xen_translate_vdev(info->vdevice, &minor, &offset);
if (err)
return err;
nr_parts = PARTS_PER_DISK;
} else {
minor = BLKIF_MINOR_EXT(info->vdevice);
nr_parts = PARTS_PER_EXT_DISK;
offset = minor / nr_parts;
if (xen_hvm_domain() && offset < EMULATED_HD_DISK_NAME_OFFSET + 4)
printk(KERN_WARNING "blkfront: vdevice 0x%x might conflict with "
"emulated IDE disks,\n\t choose an xvd device name"
"from xvde on\n", info->vdevice);
}
if (minor >> MINORBITS) {
pr_warn("blkfront: %#x's minor (%#x) out of range; ignoring\n",
info->vdevice, minor);
return -ENODEV;
}
if ((minor % nr_parts) == 0)
nr_minors = nr_parts;
err = xlbd_reserve_minors(minor, nr_minors);
if (err)
goto out;
err = -ENODEV;
gd = alloc_disk(nr_minors);
if (gd == NULL)
goto release;
strcpy(gd->disk_name, DEV_NAME);
ptr = encode_disk_name(gd->disk_name + sizeof(DEV_NAME) - 1, offset);
BUG_ON(ptr >= gd->disk_name + DISK_NAME_LEN);
if (nr_minors > 1)
*ptr = 0;
else
snprintf(ptr, gd->disk_name + DISK_NAME_LEN - ptr,
"%d", minor & (nr_parts - 1));
gd->major = XENVBD_MAJOR;
gd->first_minor = minor;
gd->fops = &xlvbd_block_fops;
gd->private_data = info;
gd->driverfs_dev = &(info->xbdev->dev);
set_capacity(gd, capacity);
if (xlvbd_init_blk_queue(gd, sector_size, physical_sector_size,
info->max_indirect_segments ? :
BLKIF_MAX_SEGMENTS_PER_REQUEST)) {
del_gendisk(gd);
goto release;
}
info->rq = gd->queue;
info->gd = gd;
xlvbd_flush(info);
if (vdisk_info & VDISK_READONLY)
set_disk_ro(gd, 1);
if (vdisk_info & VDISK_REMOVABLE)
gd->flags |= GENHD_FL_REMOVABLE;
if (vdisk_info & VDISK_CDROM)
gd->flags |= GENHD_FL_CD;
return 0;
release:
xlbd_release_minors(minor, nr_minors);
out:
return err;
}
static void xlvbd_release_gendisk(struct blkfront_info *info)
{
unsigned int minor, nr_minors, i;
if (info->rq == NULL)
return;
blk_mq_stop_hw_queues(info->rq);
for (i = 0; i < info->nr_rings; i++) {
struct blkfront_ring_info *rinfo = &info->rinfo[i];
gnttab_cancel_free_callback(&rinfo->callback);
flush_work(&rinfo->work);
}
del_gendisk(info->gd);
minor = info->gd->first_minor;
nr_minors = info->gd->minors;
xlbd_release_minors(minor, nr_minors);
blk_cleanup_queue(info->rq);
blk_mq_free_tag_set(&info->tag_set);
info->rq = NULL;
put_disk(info->gd);
info->gd = NULL;
}
static inline void kick_pending_request_queues_locked(struct blkfront_ring_info *rinfo)
{
if (!RING_FULL(&rinfo->ring))
blk_mq_start_stopped_hw_queues(rinfo->dev_info->rq, true);
}
static void kick_pending_request_queues(struct blkfront_ring_info *rinfo)
{
unsigned long flags;
spin_lock_irqsave(&rinfo->ring_lock, flags);
kick_pending_request_queues_locked(rinfo);
spin_unlock_irqrestore(&rinfo->ring_lock, flags);
}
static void blkif_restart_queue(struct work_struct *work)
{
struct blkfront_ring_info *rinfo = container_of(work, struct blkfront_ring_info, work);
if (rinfo->dev_info->connected == BLKIF_STATE_CONNECTED)
kick_pending_request_queues(rinfo);
}
static void blkif_free_ring(struct blkfront_ring_info *rinfo)
{
struct grant *persistent_gnt, *n;
struct blkfront_info *info = rinfo->dev_info;
int i, j, segs;
if (!list_empty(&rinfo->indirect_pages)) {
struct page *indirect_page, *n;
BUG_ON(info->feature_persistent);
list_for_each_entry_safe(indirect_page, n, &rinfo->indirect_pages, lru) {
list_del(&indirect_page->lru);
__free_page(indirect_page);
}
}
if (!list_empty(&rinfo->grants)) {
list_for_each_entry_safe(persistent_gnt, n,
&rinfo->grants, node) {
list_del(&persistent_gnt->node);
if (persistent_gnt->gref != GRANT_INVALID_REF) {
gnttab_end_foreign_access(persistent_gnt->gref,
0, 0UL);
rinfo->persistent_gnts_c--;
}
if (info->feature_persistent)
__free_page(persistent_gnt->page);
kfree(persistent_gnt);
}
}
BUG_ON(rinfo->persistent_gnts_c != 0);
for (i = 0; i < BLK_RING_SIZE(info); i++) {
if (!rinfo->shadow[i].request)
goto free_shadow;
segs = rinfo->shadow[i].req.operation == BLKIF_OP_INDIRECT ?
rinfo->shadow[i].req.u.indirect.nr_segments :
rinfo->shadow[i].req.u.rw.nr_segments;
for (j = 0; j < segs; j++) {
persistent_gnt = rinfo->shadow[i].grants_used[j];
gnttab_end_foreign_access(persistent_gnt->gref, 0, 0UL);
if (info->feature_persistent)
__free_page(persistent_gnt->page);
kfree(persistent_gnt);
}
if (rinfo->shadow[i].req.operation != BLKIF_OP_INDIRECT)
goto free_shadow;
for (j = 0; j < INDIRECT_GREFS(segs); j++) {
persistent_gnt = rinfo->shadow[i].indirect_grants[j];
gnttab_end_foreign_access(persistent_gnt->gref, 0, 0UL);
__free_page(persistent_gnt->page);
kfree(persistent_gnt);
}
free_shadow:
kfree(rinfo->shadow[i].grants_used);
rinfo->shadow[i].grants_used = NULL;
kfree(rinfo->shadow[i].indirect_grants);
rinfo->shadow[i].indirect_grants = NULL;
kfree(rinfo->shadow[i].sg);
rinfo->shadow[i].sg = NULL;
}
gnttab_cancel_free_callback(&rinfo->callback);
flush_work(&rinfo->work);
for (i = 0; i < info->nr_ring_pages; i++) {
if (rinfo->ring_ref[i] != GRANT_INVALID_REF) {
gnttab_end_foreign_access(rinfo->ring_ref[i], 0, 0);
rinfo->ring_ref[i] = GRANT_INVALID_REF;
}
}
free_pages((unsigned long)rinfo->ring.sring, get_order(info->nr_ring_pages * PAGE_SIZE));
rinfo->ring.sring = NULL;
if (rinfo->irq)
unbind_from_irqhandler(rinfo->irq, rinfo);
rinfo->evtchn = rinfo->irq = 0;
}
static void blkif_free(struct blkfront_info *info, int suspend)
{
unsigned int i;
info->connected = suspend ?
BLKIF_STATE_SUSPENDED : BLKIF_STATE_DISCONNECTED;
if (info->rq)
blk_mq_stop_hw_queues(info->rq);
for (i = 0; i < info->nr_rings; i++)
blkif_free_ring(&info->rinfo[i]);
kfree(info->rinfo);
info->rinfo = NULL;
info->nr_rings = 0;
}
static void blkif_copy_from_grant(unsigned long gfn, unsigned int offset,
unsigned int len, void *data)
{
struct copy_from_grant *info = data;
char *shared_data;
const struct blk_shadow *s = info->s;
shared_data = kmap_atomic(s->grants_used[info->grant_idx]->page);
memcpy(info->bvec_data + info->bvec_offset,
shared_data + offset, len);
info->bvec_offset += len;
info->grant_idx++;
kunmap_atomic(shared_data);
}
static enum blk_req_status blkif_rsp_to_req_status(int rsp)
{
switch (rsp)
{
case BLKIF_RSP_OKAY:
return REQ_DONE;
case BLKIF_RSP_EOPNOTSUPP:
return REQ_EOPNOTSUPP;
case BLKIF_RSP_ERROR:
default:
return REQ_ERROR;
}
}
static int blkif_get_final_status(enum blk_req_status s1,
enum blk_req_status s2)
{
BUG_ON(s1 == REQ_WAITING);
BUG_ON(s2 == REQ_WAITING);
if (s1 == REQ_ERROR || s2 == REQ_ERROR)
return BLKIF_RSP_ERROR;
else if (s1 == REQ_EOPNOTSUPP || s2 == REQ_EOPNOTSUPP)
return BLKIF_RSP_EOPNOTSUPP;
return BLKIF_RSP_OKAY;
}
static bool blkif_completion(unsigned long *id,
struct blkfront_ring_info *rinfo,
struct blkif_response *bret)
{
int i = 0;
struct scatterlist *sg;
int num_sg, num_grant;
struct blkfront_info *info = rinfo->dev_info;
struct blk_shadow *s = &rinfo->shadow[*id];
struct copy_from_grant data = {
.grant_idx = 0,
};
num_grant = s->req.operation == BLKIF_OP_INDIRECT ?
s->req.u.indirect.nr_segments : s->req.u.rw.nr_segments;
if (unlikely(s->associated_id != NO_ASSOCIATED_ID)) {
struct blk_shadow *s2 = &rinfo->shadow[s->associated_id];
s->status = blkif_rsp_to_req_status(bret->status);
if (s2->status == REQ_WAITING)
return 0;
bret->status = blkif_get_final_status(s->status,
s2->status);
num_grant += s2->req.u.rw.nr_segments;
if (s2->num_sg != 0) {
*id = s->associated_id;
s = s2;
}
if (add_id_to_freelist(rinfo, s->associated_id))
WARN(1, "%s: can't recycle the second part (id = %ld) of the request\n",
info->gd->disk_name, s->associated_id);
}
data.s = s;
num_sg = s->num_sg;
if (bret->operation == BLKIF_OP_READ && info->feature_persistent) {
for_each_sg(s->sg, sg, num_sg, i) {
BUG_ON(sg->offset + sg->length > PAGE_SIZE);
data.bvec_offset = sg->offset;
data.bvec_data = kmap_atomic(sg_page(sg));
gnttab_foreach_grant_in_range(sg_page(sg),
sg->offset,
sg->length,
blkif_copy_from_grant,
&data);
kunmap_atomic(data.bvec_data);
}
}
for (i = 0; i < num_grant; i++) {
if (gnttab_query_foreign_access(s->grants_used[i]->gref)) {
if (!info->feature_persistent)
pr_alert_ratelimited("backed has not unmapped grant: %u\n",
s->grants_used[i]->gref);
list_add(&s->grants_used[i]->node, &rinfo->grants);
rinfo->persistent_gnts_c++;
} else {
gnttab_end_foreign_access(s->grants_used[i]->gref, 0, 0UL);
s->grants_used[i]->gref = GRANT_INVALID_REF;
list_add_tail(&s->grants_used[i]->node, &rinfo->grants);
}
}
if (s->req.operation == BLKIF_OP_INDIRECT) {
for (i = 0; i < INDIRECT_GREFS(num_grant); i++) {
if (gnttab_query_foreign_access(s->indirect_grants[i]->gref)) {
if (!info->feature_persistent)
pr_alert_ratelimited("backed has not unmapped grant: %u\n",
s->indirect_grants[i]->gref);
list_add(&s->indirect_grants[i]->node, &rinfo->grants);
rinfo->persistent_gnts_c++;
} else {
struct page *indirect_page;
gnttab_end_foreign_access(s->indirect_grants[i]->gref, 0, 0UL);
if (!info->feature_persistent) {
indirect_page = s->indirect_grants[i]->page;
list_add(&indirect_page->lru, &rinfo->indirect_pages);
}
s->indirect_grants[i]->gref = GRANT_INVALID_REF;
list_add_tail(&s->indirect_grants[i]->node, &rinfo->grants);
}
}
}
return 1;
}
static irqreturn_t blkif_interrupt(int irq, void *dev_id)
{
struct request *req;
struct blkif_response *bret;
RING_IDX i, rp;
unsigned long flags;
struct blkfront_ring_info *rinfo = (struct blkfront_ring_info *)dev_id;
struct blkfront_info *info = rinfo->dev_info;
int error;
if (unlikely(info->connected != BLKIF_STATE_CONNECTED))
return IRQ_HANDLED;
spin_lock_irqsave(&rinfo->ring_lock, flags);
again:
rp = rinfo->ring.sring->rsp_prod;
rmb();
for (i = rinfo->ring.rsp_cons; i != rp; i++) {
unsigned long id;
bret = RING_GET_RESPONSE(&rinfo->ring, i);
id = bret->id;
if (id >= BLK_RING_SIZE(info)) {
WARN(1, "%s: response to %s has incorrect id (%ld)\n",
info->gd->disk_name, op_name(bret->operation), id);
continue;
}
req = rinfo->shadow[id].request;
if (bret->operation != BLKIF_OP_DISCARD) {
if (!blkif_completion(&id, rinfo, bret))
continue;
}
if (add_id_to_freelist(rinfo, id)) {
WARN(1, "%s: response to %s (id %ld) couldn't be recycled!\n",
info->gd->disk_name, op_name(bret->operation), id);
continue;
}
error = (bret->status == BLKIF_RSP_OKAY) ? 0 : -EIO;
switch (bret->operation) {
case BLKIF_OP_DISCARD:
if (unlikely(bret->status == BLKIF_RSP_EOPNOTSUPP)) {
struct request_queue *rq = info->rq;
printk(KERN_WARNING "blkfront: %s: %s op failed\n",
info->gd->disk_name, op_name(bret->operation));
error = -EOPNOTSUPP;
info->feature_discard = 0;
info->feature_secdiscard = 0;
queue_flag_clear(QUEUE_FLAG_DISCARD, rq);
queue_flag_clear(QUEUE_FLAG_SECDISCARD, rq);
}
blk_mq_complete_request(req, error);
break;
case BLKIF_OP_FLUSH_DISKCACHE:
case BLKIF_OP_WRITE_BARRIER:
if (unlikely(bret->status == BLKIF_RSP_EOPNOTSUPP)) {
printk(KERN_WARNING "blkfront: %s: %s op failed\n",
info->gd->disk_name, op_name(bret->operation));
error = -EOPNOTSUPP;
}
if (unlikely(bret->status == BLKIF_RSP_ERROR &&
rinfo->shadow[id].req.u.rw.nr_segments == 0)) {
printk(KERN_WARNING "blkfront: %s: empty %s op failed\n",
info->gd->disk_name, op_name(bret->operation));
error = -EOPNOTSUPP;
}
if (unlikely(error)) {
if (error == -EOPNOTSUPP)
error = 0;
info->feature_flush = 0;
xlvbd_flush(info);
}
case BLKIF_OP_READ:
case BLKIF_OP_WRITE:
if (unlikely(bret->status != BLKIF_RSP_OKAY))
dev_dbg(&info->xbdev->dev, "Bad return from blkdev data "
"request: %x\n", bret->status);
blk_mq_complete_request(req, error);
break;
default:
BUG();
}
}
rinfo->ring.rsp_cons = i;
if (i != rinfo->ring.req_prod_pvt) {
int more_to_do;
RING_FINAL_CHECK_FOR_RESPONSES(&rinfo->ring, more_to_do);
if (more_to_do)
goto again;
} else
rinfo->ring.sring->rsp_event = i + 1;
kick_pending_request_queues_locked(rinfo);
spin_unlock_irqrestore(&rinfo->ring_lock, flags);
return IRQ_HANDLED;
}
static int setup_blkring(struct xenbus_device *dev,
struct blkfront_ring_info *rinfo)
{
struct blkif_sring *sring;
int err, i;
struct blkfront_info *info = rinfo->dev_info;
unsigned long ring_size = info->nr_ring_pages * XEN_PAGE_SIZE;
grant_ref_t gref[XENBUS_MAX_RING_GRANTS];
for (i = 0; i < info->nr_ring_pages; i++)
rinfo->ring_ref[i] = GRANT_INVALID_REF;
sring = (struct blkif_sring *)__get_free_pages(GFP_NOIO | __GFP_HIGH,
get_order(ring_size));
if (!sring) {
xenbus_dev_fatal(dev, -ENOMEM, "allocating shared ring");
return -ENOMEM;
}
SHARED_RING_INIT(sring);
FRONT_RING_INIT(&rinfo->ring, sring, ring_size);
err = xenbus_grant_ring(dev, rinfo->ring.sring, info->nr_ring_pages, gref);
if (err < 0) {
free_pages((unsigned long)sring, get_order(ring_size));
rinfo->ring.sring = NULL;
goto fail;
}
for (i = 0; i < info->nr_ring_pages; i++)
rinfo->ring_ref[i] = gref[i];
err = xenbus_alloc_evtchn(dev, &rinfo->evtchn);
if (err)
goto fail;
err = bind_evtchn_to_irqhandler(rinfo->evtchn, blkif_interrupt, 0,
"blkif", rinfo);
if (err <= 0) {
xenbus_dev_fatal(dev, err,
"bind_evtchn_to_irqhandler failed");
goto fail;
}
rinfo->irq = err;
return 0;
fail:
blkif_free(info, 0);
return err;
}
static int write_per_ring_nodes(struct xenbus_transaction xbt,
struct blkfront_ring_info *rinfo, const char *dir)
{
int err;
unsigned int i;
const char *message = NULL;
struct blkfront_info *info = rinfo->dev_info;
if (info->nr_ring_pages == 1) {
err = xenbus_printf(xbt, dir, "ring-ref", "%u", rinfo->ring_ref[0]);
if (err) {
message = "writing ring-ref";
goto abort_transaction;
}
} else {
for (i = 0; i < info->nr_ring_pages; i++) {
char ring_ref_name[RINGREF_NAME_LEN];
snprintf(ring_ref_name, RINGREF_NAME_LEN, "ring-ref%u", i);
err = xenbus_printf(xbt, dir, ring_ref_name,
"%u", rinfo->ring_ref[i]);
if (err) {
message = "writing ring-ref";
goto abort_transaction;
}
}
}
err = xenbus_printf(xbt, dir, "event-channel", "%u", rinfo->evtchn);
if (err) {
message = "writing event-channel";
goto abort_transaction;
}
return 0;
abort_transaction:
xenbus_transaction_end(xbt, 1);
if (message)
xenbus_dev_fatal(info->xbdev, err, "%s", message);
return err;
}
static int talk_to_blkback(struct xenbus_device *dev,
struct blkfront_info *info)
{
const char *message = NULL;
struct xenbus_transaction xbt;
int err;
unsigned int i, max_page_order = 0;
unsigned int ring_page_order = 0;
err = xenbus_scanf(XBT_NIL, info->xbdev->otherend,
"max-ring-page-order", "%u", &max_page_order);
if (err != 1)
info->nr_ring_pages = 1;
else {
ring_page_order = min(xen_blkif_max_ring_order, max_page_order);
info->nr_ring_pages = 1 << ring_page_order;
}
for (i = 0; i < info->nr_rings; i++) {
struct blkfront_ring_info *rinfo = &info->rinfo[i];
err = setup_blkring(dev, rinfo);
if (err)
goto destroy_blkring;
}
again:
err = xenbus_transaction_start(&xbt);
if (err) {
xenbus_dev_fatal(dev, err, "starting transaction");
goto destroy_blkring;
}
if (info->nr_ring_pages > 1) {
err = xenbus_printf(xbt, dev->nodename, "ring-page-order", "%u",
ring_page_order);
if (err) {
message = "writing ring-page-order";
goto abort_transaction;
}
}
if (info->nr_rings == 1) {
err = write_per_ring_nodes(xbt, &info->rinfo[0], dev->nodename);
if (err)
goto destroy_blkring;
} else {
char *path;
size_t pathsize;
err = xenbus_printf(xbt, dev->nodename, "multi-queue-num-queues", "%u",
info->nr_rings);
if (err) {
message = "writing multi-queue-num-queues";
goto abort_transaction;
}
pathsize = strlen(dev->nodename) + QUEUE_NAME_LEN;
path = kmalloc(pathsize, GFP_KERNEL);
if (!path) {
err = -ENOMEM;
message = "ENOMEM while writing ring references";
goto abort_transaction;
}
for (i = 0; i < info->nr_rings; i++) {
memset(path, 0, pathsize);
snprintf(path, pathsize, "%s/queue-%u", dev->nodename, i);
err = write_per_ring_nodes(xbt, &info->rinfo[i], path);
if (err) {
kfree(path);
goto destroy_blkring;
}
}
kfree(path);
}
err = xenbus_printf(xbt, dev->nodename, "protocol", "%s",
XEN_IO_PROTO_ABI_NATIVE);
if (err) {
message = "writing protocol";
goto abort_transaction;
}
err = xenbus_printf(xbt, dev->nodename,
"feature-persistent", "%u", 1);
if (err)
dev_warn(&dev->dev,
"writing persistent grants feature to xenbus");
err = xenbus_transaction_end(xbt, 0);
if (err) {
if (err == -EAGAIN)
goto again;
xenbus_dev_fatal(dev, err, "completing transaction");
goto destroy_blkring;
}
for (i = 0; i < info->nr_rings; i++) {
unsigned int j;
struct blkfront_ring_info *rinfo = &info->rinfo[i];
for (j = 0; j < BLK_RING_SIZE(info); j++)
rinfo->shadow[j].req.u.rw.id = j + 1;
rinfo->shadow[BLK_RING_SIZE(info)-1].req.u.rw.id = 0x0fffffff;
}
xenbus_switch_state(dev, XenbusStateInitialised);
return 0;
abort_transaction:
xenbus_transaction_end(xbt, 1);
if (message)
xenbus_dev_fatal(dev, err, "%s", message);
destroy_blkring:
blkif_free(info, 0);
kfree(info);
dev_set_drvdata(&dev->dev, NULL);
return err;
}
static int negotiate_mq(struct blkfront_info *info)
{
unsigned int backend_max_queues = 0;
int err;
unsigned int i;
BUG_ON(info->nr_rings);
err = xenbus_scanf(XBT_NIL, info->xbdev->otherend,
"multi-queue-max-queues", "%u", &backend_max_queues);
if (err < 0)
backend_max_queues = 1;
info->nr_rings = min(backend_max_queues, xen_blkif_max_queues);
if (!info->nr_rings)
info->nr_rings = 1;
info->rinfo = kzalloc(sizeof(struct blkfront_ring_info) * info->nr_rings, GFP_KERNEL);
if (!info->rinfo) {
xenbus_dev_fatal(info->xbdev, -ENOMEM, "allocating ring_info structure");
return -ENOMEM;
}
for (i = 0; i < info->nr_rings; i++) {
struct blkfront_ring_info *rinfo;
rinfo = &info->rinfo[i];
INIT_LIST_HEAD(&rinfo->indirect_pages);
INIT_LIST_HEAD(&rinfo->grants);
rinfo->dev_info = info;
INIT_WORK(&rinfo->work, blkif_restart_queue);
spin_lock_init(&rinfo->ring_lock);
}
return 0;
}
static int blkfront_probe(struct xenbus_device *dev,
const struct xenbus_device_id *id)
{
int err, vdevice;
struct blkfront_info *info;
err = xenbus_scanf(XBT_NIL, dev->nodename,
"virtual-device", "%i", &vdevice);
if (err != 1) {
err = xenbus_scanf(XBT_NIL, dev->nodename, "virtual-device-ext",
"%i", &vdevice);
if (err != 1) {
xenbus_dev_fatal(dev, err, "reading virtual-device");
return err;
}
}
if (xen_hvm_domain()) {
char *type;
int len;
if (xen_has_pv_and_legacy_disk_devices()) {
int major;
if (!VDEV_IS_EXTENDED(vdevice))
major = BLKIF_MAJOR(vdevice);
else
major = XENVBD_MAJOR;
if (major != XENVBD_MAJOR) {
printk(KERN_INFO
"%s: HVM does not support vbd %d as xen block device\n",
__func__, vdevice);
return -ENODEV;
}
}
type = xenbus_read(XBT_NIL, dev->nodename, "device-type", &len);
if (IS_ERR(type))
return -ENODEV;
if (strncmp(type, "cdrom", 5) == 0) {
kfree(type);
return -ENODEV;
}
kfree(type);
}
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info) {
xenbus_dev_fatal(dev, -ENOMEM, "allocating info structure");
return -ENOMEM;
}
info->xbdev = dev;
err = negotiate_mq(info);
if (err) {
kfree(info);
return err;
}
mutex_init(&info->mutex);
info->vdevice = vdevice;
info->connected = BLKIF_STATE_DISCONNECTED;
info->handle = simple_strtoul(strrchr(dev->nodename, '/')+1, NULL, 0);
dev_set_drvdata(&dev->dev, info);
return 0;
}
static void split_bio_end(struct bio *bio)
{
struct split_bio *split_bio = bio->bi_private;
if (atomic_dec_and_test(&split_bio->pending)) {
split_bio->bio->bi_phys_segments = 0;
split_bio->bio->bi_error = bio->bi_error;
bio_endio(split_bio->bio);
kfree(split_bio);
}
bio_put(bio);
}
static int blkif_recover(struct blkfront_info *info)
{
unsigned int i, r_index;
struct request *req, *n;
struct blk_shadow *copy;
int rc;
struct bio *bio, *cloned_bio;
struct bio_list bio_list, merge_bio;
unsigned int segs, offset;
int pending, size;
struct split_bio *split_bio;
struct list_head requests;
blkfront_gather_backend_features(info);
segs = info->max_indirect_segments ? : BLKIF_MAX_SEGMENTS_PER_REQUEST;
blk_queue_max_segments(info->rq, segs);
bio_list_init(&bio_list);
INIT_LIST_HEAD(&requests);
for (r_index = 0; r_index < info->nr_rings; r_index++) {
struct blkfront_ring_info *rinfo;
rinfo = &info->rinfo[r_index];
copy = kmemdup(rinfo->shadow, sizeof(rinfo->shadow),
GFP_NOIO | __GFP_REPEAT | __GFP_HIGH);
if (!copy)
return -ENOMEM;
memset(&rinfo->shadow, 0, sizeof(rinfo->shadow));
for (i = 0; i < BLK_RING_SIZE(info); i++)
rinfo->shadow[i].req.u.rw.id = i+1;
rinfo->shadow_free = rinfo->ring.req_prod_pvt;
rinfo->shadow[BLK_RING_SIZE(info)-1].req.u.rw.id = 0x0fffffff;
rc = blkfront_setup_indirect(rinfo);
if (rc) {
kfree(copy);
return rc;
}
for (i = 0; i < BLK_RING_SIZE(info); i++) {
if (!copy[i].request)
continue;
if (copy[i].request->cmd_flags &
(REQ_FLUSH | REQ_FUA | REQ_DISCARD | REQ_SECURE)) {
list_add(&copy[i].request->queuelist, &requests);
continue;
}
merge_bio.head = copy[i].request->bio;
merge_bio.tail = copy[i].request->biotail;
bio_list_merge(&bio_list, &merge_bio);
copy[i].request->bio = NULL;
blk_end_request_all(copy[i].request, 0);
}
kfree(copy);
}
xenbus_switch_state(info->xbdev, XenbusStateConnected);
info->connected = BLKIF_STATE_CONNECTED;
for (r_index = 0; r_index < info->nr_rings; r_index++) {
struct blkfront_ring_info *rinfo;
rinfo = &info->rinfo[r_index];
kick_pending_request_queues(rinfo);
}
list_for_each_entry_safe(req, n, &requests, queuelist) {
list_del_init(&req->queuelist);
BUG_ON(req->nr_phys_segments > segs);
blk_mq_requeue_request(req);
}
blk_mq_kick_requeue_list(info->rq);
while ((bio = bio_list_pop(&bio_list)) != NULL) {
if (bio_segments(bio) > segs) {
pending = (bio_segments(bio) + segs - 1) / segs;
split_bio = kzalloc(sizeof(*split_bio), GFP_NOIO);
BUG_ON(split_bio == NULL);
atomic_set(&split_bio->pending, pending);
split_bio->bio = bio;
for (i = 0; i < pending; i++) {
offset = (i * segs * XEN_PAGE_SIZE) >> 9;
size = min((unsigned int)(segs * XEN_PAGE_SIZE) >> 9,
(unsigned int)bio_sectors(bio) - offset);
cloned_bio = bio_clone(bio, GFP_NOIO);
BUG_ON(cloned_bio == NULL);
bio_trim(cloned_bio, offset, size);
cloned_bio->bi_private = split_bio;
cloned_bio->bi_end_io = split_bio_end;
submit_bio(cloned_bio->bi_rw, cloned_bio);
}
continue;
}
submit_bio(bio->bi_rw, bio);
}
return 0;
}
static int blkfront_resume(struct xenbus_device *dev)
{
struct blkfront_info *info = dev_get_drvdata(&dev->dev);
int err = 0;
dev_dbg(&dev->dev, "blkfront_resume: %s\n", dev->nodename);
blkif_free(info, info->connected == BLKIF_STATE_CONNECTED);
err = negotiate_mq(info);
if (err)
return err;
err = talk_to_blkback(dev, info);
return err;
}
static void blkfront_closing(struct blkfront_info *info)
{
struct xenbus_device *xbdev = info->xbdev;
struct block_device *bdev = NULL;
mutex_lock(&info->mutex);
if (xbdev->state == XenbusStateClosing) {
mutex_unlock(&info->mutex);
return;
}
if (info->gd)
bdev = bdget_disk(info->gd, 0);
mutex_unlock(&info->mutex);
if (!bdev) {
xenbus_frontend_closed(xbdev);
return;
}
mutex_lock(&bdev->bd_mutex);
if (bdev->bd_openers) {
xenbus_dev_error(xbdev, -EBUSY,
"Device in use; refusing to close");
xenbus_switch_state(xbdev, XenbusStateClosing);
} else {
xlvbd_release_gendisk(info);
xenbus_frontend_closed(xbdev);
}
mutex_unlock(&bdev->bd_mutex);
bdput(bdev);
}
static void blkfront_setup_discard(struct blkfront_info *info)
{
int err;
unsigned int discard_granularity;
unsigned int discard_alignment;
unsigned int discard_secure;
info->feature_discard = 1;
err = xenbus_gather(XBT_NIL, info->xbdev->otherend,
"discard-granularity", "%u", &discard_granularity,
"discard-alignment", "%u", &discard_alignment,
NULL);
if (!err) {
info->discard_granularity = discard_granularity;
info->discard_alignment = discard_alignment;
}
err = xenbus_gather(XBT_NIL, info->xbdev->otherend,
"discard-secure", "%d", &discard_secure,
NULL);
if (!err)
info->feature_secdiscard = !!discard_secure;
}
static int blkfront_setup_indirect(struct blkfront_ring_info *rinfo)
{
unsigned int psegs, grants;
int err, i;
struct blkfront_info *info = rinfo->dev_info;
if (info->max_indirect_segments == 0) {
if (!HAS_EXTRA_REQ)
grants = BLKIF_MAX_SEGMENTS_PER_REQUEST;
else {
grants = GRANTS_PER_PSEG;
}
}
else
grants = info->max_indirect_segments;
psegs = grants / GRANTS_PER_PSEG;
err = fill_grant_buffer(rinfo,
(grants + INDIRECT_GREFS(grants)) * BLK_RING_SIZE(info));
if (err)
goto out_of_memory;
if (!info->feature_persistent && info->max_indirect_segments) {
int num = INDIRECT_GREFS(grants) * BLK_RING_SIZE(info);
BUG_ON(!list_empty(&rinfo->indirect_pages));
for (i = 0; i < num; i++) {
struct page *indirect_page = alloc_page(GFP_NOIO);
if (!indirect_page)
goto out_of_memory;
list_add(&indirect_page->lru, &rinfo->indirect_pages);
}
}
for (i = 0; i < BLK_RING_SIZE(info); i++) {
rinfo->shadow[i].grants_used = kzalloc(
sizeof(rinfo->shadow[i].grants_used[0]) * grants,
GFP_NOIO);
rinfo->shadow[i].sg = kzalloc(sizeof(rinfo->shadow[i].sg[0]) * psegs, GFP_NOIO);
if (info->max_indirect_segments)
rinfo->shadow[i].indirect_grants = kzalloc(
sizeof(rinfo->shadow[i].indirect_grants[0]) *
INDIRECT_GREFS(grants),
GFP_NOIO);
if ((rinfo->shadow[i].grants_used == NULL) ||
(rinfo->shadow[i].sg == NULL) ||
(info->max_indirect_segments &&
(rinfo->shadow[i].indirect_grants == NULL)))
goto out_of_memory;
sg_init_table(rinfo->shadow[i].sg, psegs);
}
return 0;
out_of_memory:
for (i = 0; i < BLK_RING_SIZE(info); i++) {
kfree(rinfo->shadow[i].grants_used);
rinfo->shadow[i].grants_used = NULL;
kfree(rinfo->shadow[i].sg);
rinfo->shadow[i].sg = NULL;
kfree(rinfo->shadow[i].indirect_grants);
rinfo->shadow[i].indirect_grants = NULL;
}
if (!list_empty(&rinfo->indirect_pages)) {
struct page *indirect_page, *n;
list_for_each_entry_safe(indirect_page, n, &rinfo->indirect_pages, lru) {
list_del(&indirect_page->lru);
__free_page(indirect_page);
}
}
return -ENOMEM;
}
static void blkfront_gather_backend_features(struct blkfront_info *info)
{
int err;
int barrier, flush, discard, persistent;
unsigned int indirect_segments;
info->feature_flush = 0;
err = xenbus_gather(XBT_NIL, info->xbdev->otherend,
"feature-barrier", "%d", &barrier,
NULL);
if (!err && barrier)
info->feature_flush = REQ_FLUSH | REQ_FUA;
err = xenbus_gather(XBT_NIL, info->xbdev->otherend,
"feature-flush-cache", "%d", &flush,
NULL);
if (!err && flush)
info->feature_flush = REQ_FLUSH;
err = xenbus_gather(XBT_NIL, info->xbdev->otherend,
"feature-discard", "%d", &discard,
NULL);
if (!err && discard)
blkfront_setup_discard(info);
err = xenbus_gather(XBT_NIL, info->xbdev->otherend,
"feature-persistent", "%u", &persistent,
NULL);
if (err)
info->feature_persistent = 0;
else
info->feature_persistent = persistent;
err = xenbus_gather(XBT_NIL, info->xbdev->otherend,
"feature-max-indirect-segments", "%u", &indirect_segments,
NULL);
if (err)
info->max_indirect_segments = 0;
else
info->max_indirect_segments = min(indirect_segments,
xen_blkif_max_segments);
}
static void blkfront_connect(struct blkfront_info *info)
{
unsigned long long sectors;
unsigned long sector_size;
unsigned int physical_sector_size;
unsigned int binfo;
int err, i;
switch (info->connected) {
case BLKIF_STATE_CONNECTED:
err = xenbus_scanf(XBT_NIL, info->xbdev->otherend,
"sectors", "%Lu", &sectors);
if (XENBUS_EXIST_ERR(err))
return;
printk(KERN_INFO "Setting capacity to %Lu\n",
sectors);
set_capacity(info->gd, sectors);
revalidate_disk(info->gd);
return;
case BLKIF_STATE_SUSPENDED:
blkif_recover(info);
return;
default:
break;
}
dev_dbg(&info->xbdev->dev, "%s:%s.\n",
__func__, info->xbdev->otherend);
err = xenbus_gather(XBT_NIL, info->xbdev->otherend,
"sectors", "%llu", &sectors,
"info", "%u", &binfo,
"sector-size", "%lu", &sector_size,
NULL);
if (err) {
xenbus_dev_fatal(info->xbdev, err,
"reading backend fields at %s",
info->xbdev->otherend);
return;
}
err = xenbus_scanf(XBT_NIL, info->xbdev->otherend,
"physical-sector-size", "%u", &physical_sector_size);
if (err != 1)
physical_sector_size = sector_size;
blkfront_gather_backend_features(info);
for (i = 0; i < info->nr_rings; i++) {
err = blkfront_setup_indirect(&info->rinfo[i]);
if (err) {
xenbus_dev_fatal(info->xbdev, err, "setup_indirect at %s",
info->xbdev->otherend);
blkif_free(info, 0);
break;
}
}
err = xlvbd_alloc_gendisk(sectors, info, binfo, sector_size,
physical_sector_size);
if (err) {
xenbus_dev_fatal(info->xbdev, err, "xlvbd_add at %s",
info->xbdev->otherend);
return;
}
xenbus_switch_state(info->xbdev, XenbusStateConnected);
info->connected = BLKIF_STATE_CONNECTED;
for (i = 0; i < info->nr_rings; i++)
kick_pending_request_queues(&info->rinfo[i]);
add_disk(info->gd);
info->is_ready = 1;
}
static void blkback_changed(struct xenbus_device *dev,
enum xenbus_state backend_state)
{
struct blkfront_info *info = dev_get_drvdata(&dev->dev);
dev_dbg(&dev->dev, "blkfront:blkback_changed to state %d.\n", backend_state);
switch (backend_state) {
case XenbusStateInitWait:
if (dev->state != XenbusStateInitialising)
break;
if (talk_to_blkback(dev, info))
break;
case XenbusStateInitialising:
case XenbusStateInitialised:
case XenbusStateReconfiguring:
case XenbusStateReconfigured:
case XenbusStateUnknown:
break;
case XenbusStateConnected:
if (dev->state != XenbusStateInitialised) {
if (talk_to_blkback(dev, info))
break;
}
blkfront_connect(info);
break;
case XenbusStateClosed:
if (dev->state == XenbusStateClosed)
break;
case XenbusStateClosing:
if (info)
blkfront_closing(info);
break;
}
}
static int blkfront_remove(struct xenbus_device *xbdev)
{
struct blkfront_info *info = dev_get_drvdata(&xbdev->dev);
struct block_device *bdev = NULL;
struct gendisk *disk;
dev_dbg(&xbdev->dev, "%s removed", xbdev->nodename);
blkif_free(info, 0);
mutex_lock(&info->mutex);
disk = info->gd;
if (disk)
bdev = bdget_disk(disk, 0);
info->xbdev = NULL;
mutex_unlock(&info->mutex);
if (!bdev) {
kfree(info);
return 0;
}
mutex_lock(&bdev->bd_mutex);
info = disk->private_data;
dev_warn(disk_to_dev(disk),
"%s was hot-unplugged, %d stale handles\n",
xbdev->nodename, bdev->bd_openers);
if (info && !bdev->bd_openers) {
xlvbd_release_gendisk(info);
disk->private_data = NULL;
kfree(info);
}
mutex_unlock(&bdev->bd_mutex);
bdput(bdev);
return 0;
}
static int blkfront_is_ready(struct xenbus_device *dev)
{
struct blkfront_info *info = dev_get_drvdata(&dev->dev);
return info->is_ready && info->xbdev;
}
static int blkif_open(struct block_device *bdev, fmode_t mode)
{
struct gendisk *disk = bdev->bd_disk;
struct blkfront_info *info;
int err = 0;
mutex_lock(&blkfront_mutex);
info = disk->private_data;
if (!info) {
err = -ERESTARTSYS;
goto out;
}
mutex_lock(&info->mutex);
if (!info->gd)
err = -ERESTARTSYS;
mutex_unlock(&info->mutex);
out:
mutex_unlock(&blkfront_mutex);
return err;
}
static void blkif_release(struct gendisk *disk, fmode_t mode)
{
struct blkfront_info *info = disk->private_data;
struct block_device *bdev;
struct xenbus_device *xbdev;
mutex_lock(&blkfront_mutex);
bdev = bdget_disk(disk, 0);
if (!bdev) {
WARN(1, "Block device %s yanked out from us!\n", disk->disk_name);
goto out_mutex;
}
if (bdev->bd_openers)
goto out;
mutex_lock(&info->mutex);
xbdev = info->xbdev;
if (xbdev && xbdev->state == XenbusStateClosing) {
dev_info(disk_to_dev(bdev->bd_disk), "releasing disk\n");
xlvbd_release_gendisk(info);
xenbus_frontend_closed(info->xbdev);
}
mutex_unlock(&info->mutex);
if (!xbdev) {
dev_info(disk_to_dev(bdev->bd_disk), "releasing disk\n");
xlvbd_release_gendisk(info);
disk->private_data = NULL;
kfree(info);
}
out:
bdput(bdev);
out_mutex:
mutex_unlock(&blkfront_mutex);
}
static int __init xlblk_init(void)
{
int ret;
int nr_cpus = num_online_cpus();
if (!xen_domain())
return -ENODEV;
if (xen_blkif_max_ring_order > XENBUS_MAX_RING_GRANT_ORDER) {
pr_info("Invalid max_ring_order (%d), will use default max: %d.\n",
xen_blkif_max_ring_order, XENBUS_MAX_RING_GRANT_ORDER);
xen_blkif_max_ring_order = XENBUS_MAX_RING_GRANT_ORDER;
}
if (xen_blkif_max_queues > nr_cpus) {
pr_info("Invalid max_queues (%d), will use default max: %d.\n",
xen_blkif_max_queues, nr_cpus);
xen_blkif_max_queues = nr_cpus;
}
if (!xen_has_pv_disk_devices())
return -ENODEV;
if (register_blkdev(XENVBD_MAJOR, DEV_NAME)) {
printk(KERN_WARNING "xen_blk: can't get major %d with name %s\n",
XENVBD_MAJOR, DEV_NAME);
return -ENODEV;
}
ret = xenbus_register_frontend(&blkfront_driver);
if (ret) {
unregister_blkdev(XENVBD_MAJOR, DEV_NAME);
return ret;
}
return 0;
}
static void __exit xlblk_exit(void)
{
xenbus_unregister_driver(&blkfront_driver);
unregister_blkdev(XENVBD_MAJOR, DEV_NAME);
kfree(minors);
}
