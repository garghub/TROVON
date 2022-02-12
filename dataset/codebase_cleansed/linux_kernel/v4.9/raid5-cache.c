static sector_t r5l_ring_add(struct r5l_log *log, sector_t start, sector_t inc)
{
start += inc;
if (start >= log->device_size)
start = start - log->device_size;
return start;
}
static sector_t r5l_ring_distance(struct r5l_log *log, sector_t start,
sector_t end)
{
if (end >= start)
return end - start;
else
return end + log->device_size - start;
}
static bool r5l_has_free_space(struct r5l_log *log, sector_t size)
{
sector_t used_size;
used_size = r5l_ring_distance(log, log->last_checkpoint,
log->log_start);
return log->device_size > used_size + size;
}
static void __r5l_set_io_unit_state(struct r5l_io_unit *io,
enum r5l_io_unit_state state)
{
if (WARN_ON(io->state >= state))
return;
io->state = state;
}
static void r5l_io_run_stripes(struct r5l_io_unit *io)
{
struct stripe_head *sh, *next;
list_for_each_entry_safe(sh, next, &io->stripe_list, log_list) {
list_del_init(&sh->log_list);
set_bit(STRIPE_HANDLE, &sh->state);
raid5_release_stripe(sh);
}
}
static void r5l_log_run_stripes(struct r5l_log *log)
{
struct r5l_io_unit *io, *next;
assert_spin_locked(&log->io_list_lock);
list_for_each_entry_safe(io, next, &log->running_ios, log_sibling) {
if (io->state < IO_UNIT_IO_END)
break;
list_move_tail(&io->log_sibling, &log->finished_ios);
r5l_io_run_stripes(io);
}
}
static void r5l_move_to_end_ios(struct r5l_log *log)
{
struct r5l_io_unit *io, *next;
assert_spin_locked(&log->io_list_lock);
list_for_each_entry_safe(io, next, &log->running_ios, log_sibling) {
if (io->state < IO_UNIT_IO_END)
break;
list_move_tail(&io->log_sibling, &log->io_end_ios);
}
}
static void r5l_log_endio(struct bio *bio)
{
struct r5l_io_unit *io = bio->bi_private;
struct r5l_log *log = io->log;
unsigned long flags;
if (bio->bi_error)
md_error(log->rdev->mddev, log->rdev);
bio_put(bio);
mempool_free(io->meta_page, log->meta_pool);
spin_lock_irqsave(&log->io_list_lock, flags);
__r5l_set_io_unit_state(io, IO_UNIT_IO_END);
if (log->need_cache_flush)
r5l_move_to_end_ios(log);
else
r5l_log_run_stripes(log);
spin_unlock_irqrestore(&log->io_list_lock, flags);
if (log->need_cache_flush)
md_wakeup_thread(log->rdev->mddev->thread);
}
static void r5l_submit_current_io(struct r5l_log *log)
{
struct r5l_io_unit *io = log->current_io;
struct r5l_meta_block *block;
unsigned long flags;
u32 crc;
if (!io)
return;
block = page_address(io->meta_page);
block->meta_size = cpu_to_le32(io->meta_offset);
crc = crc32c_le(log->uuid_checksum, block, PAGE_SIZE);
block->checksum = cpu_to_le32(crc);
log->current_io = NULL;
spin_lock_irqsave(&log->io_list_lock, flags);
__r5l_set_io_unit_state(io, IO_UNIT_IO_START);
spin_unlock_irqrestore(&log->io_list_lock, flags);
submit_bio(io->current_bio);
}
static struct bio *r5l_bio_alloc(struct r5l_log *log)
{
struct bio *bio = bio_alloc_bioset(GFP_NOIO, BIO_MAX_PAGES, log->bs);
bio_set_op_attrs(bio, REQ_OP_WRITE, 0);
bio->bi_bdev = log->rdev->bdev;
bio->bi_iter.bi_sector = log->rdev->data_offset + log->log_start;
return bio;
}
static void r5_reserve_log_entry(struct r5l_log *log, struct r5l_io_unit *io)
{
log->log_start = r5l_ring_add(log, log->log_start, BLOCK_SECTORS);
if (log->log_start == 0)
io->need_split_bio = true;
io->log_end = log->log_start;
}
static struct r5l_io_unit *r5l_new_meta(struct r5l_log *log)
{
struct r5l_io_unit *io;
struct r5l_meta_block *block;
io = mempool_alloc(log->io_pool, GFP_ATOMIC);
if (!io)
return NULL;
memset(io, 0, sizeof(*io));
io->log = log;
INIT_LIST_HEAD(&io->log_sibling);
INIT_LIST_HEAD(&io->stripe_list);
io->state = IO_UNIT_RUNNING;
io->meta_page = mempool_alloc(log->meta_pool, GFP_NOIO);
block = page_address(io->meta_page);
clear_page(block);
block->magic = cpu_to_le32(R5LOG_MAGIC);
block->version = R5LOG_VERSION;
block->seq = cpu_to_le64(log->seq);
block->position = cpu_to_le64(log->log_start);
io->log_start = log->log_start;
io->meta_offset = sizeof(struct r5l_meta_block);
io->seq = log->seq++;
io->current_bio = r5l_bio_alloc(log);
io->current_bio->bi_end_io = r5l_log_endio;
io->current_bio->bi_private = io;
bio_add_page(io->current_bio, io->meta_page, PAGE_SIZE, 0);
r5_reserve_log_entry(log, io);
spin_lock_irq(&log->io_list_lock);
list_add_tail(&io->log_sibling, &log->running_ios);
spin_unlock_irq(&log->io_list_lock);
return io;
}
static int r5l_get_meta(struct r5l_log *log, unsigned int payload_size)
{
if (log->current_io &&
log->current_io->meta_offset + payload_size > PAGE_SIZE)
r5l_submit_current_io(log);
if (!log->current_io) {
log->current_io = r5l_new_meta(log);
if (!log->current_io)
return -ENOMEM;
}
return 0;
}
static void r5l_append_payload_meta(struct r5l_log *log, u16 type,
sector_t location,
u32 checksum1, u32 checksum2,
bool checksum2_valid)
{
struct r5l_io_unit *io = log->current_io;
struct r5l_payload_data_parity *payload;
payload = page_address(io->meta_page) + io->meta_offset;
payload->header.type = cpu_to_le16(type);
payload->header.flags = cpu_to_le16(0);
payload->size = cpu_to_le32((1 + !!checksum2_valid) <<
(PAGE_SHIFT - 9));
payload->location = cpu_to_le64(location);
payload->checksum[0] = cpu_to_le32(checksum1);
if (checksum2_valid)
payload->checksum[1] = cpu_to_le32(checksum2);
io->meta_offset += sizeof(struct r5l_payload_data_parity) +
sizeof(__le32) * (1 + !!checksum2_valid);
}
static void r5l_append_payload_page(struct r5l_log *log, struct page *page)
{
struct r5l_io_unit *io = log->current_io;
if (io->need_split_bio) {
struct bio *prev = io->current_bio;
io->current_bio = r5l_bio_alloc(log);
bio_chain(io->current_bio, prev);
submit_bio(prev);
}
if (!bio_add_page(io->current_bio, page, PAGE_SIZE, 0))
BUG();
r5_reserve_log_entry(log, io);
}
static int r5l_log_stripe(struct r5l_log *log, struct stripe_head *sh,
int data_pages, int parity_pages)
{
int i;
int meta_size;
int ret;
struct r5l_io_unit *io;
meta_size =
((sizeof(struct r5l_payload_data_parity) + sizeof(__le32))
* data_pages) +
sizeof(struct r5l_payload_data_parity) +
sizeof(__le32) * parity_pages;
ret = r5l_get_meta(log, meta_size);
if (ret)
return ret;
io = log->current_io;
for (i = 0; i < sh->disks; i++) {
if (!test_bit(R5_Wantwrite, &sh->dev[i].flags))
continue;
if (i == sh->pd_idx || i == sh->qd_idx)
continue;
r5l_append_payload_meta(log, R5LOG_PAYLOAD_DATA,
raid5_compute_blocknr(sh, i, 0),
sh->dev[i].log_checksum, 0, false);
r5l_append_payload_page(log, sh->dev[i].page);
}
if (sh->qd_idx >= 0) {
r5l_append_payload_meta(log, R5LOG_PAYLOAD_PARITY,
sh->sector, sh->dev[sh->pd_idx].log_checksum,
sh->dev[sh->qd_idx].log_checksum, true);
r5l_append_payload_page(log, sh->dev[sh->pd_idx].page);
r5l_append_payload_page(log, sh->dev[sh->qd_idx].page);
} else {
r5l_append_payload_meta(log, R5LOG_PAYLOAD_PARITY,
sh->sector, sh->dev[sh->pd_idx].log_checksum,
0, false);
r5l_append_payload_page(log, sh->dev[sh->pd_idx].page);
}
list_add_tail(&sh->log_list, &io->stripe_list);
atomic_inc(&io->pending_stripe);
sh->log_io = io;
return 0;
}
int r5l_write_stripe(struct r5l_log *log, struct stripe_head *sh)
{
int write_disks = 0;
int data_pages, parity_pages;
int meta_size;
int reserve;
int i;
int ret = 0;
if (!log)
return -EAGAIN;
if (sh->log_io || !test_bit(R5_Wantwrite, &sh->dev[sh->pd_idx].flags) ||
test_bit(STRIPE_SYNCING, &sh->state)) {
clear_bit(STRIPE_LOG_TRAPPED, &sh->state);
return -EAGAIN;
}
for (i = 0; i < sh->disks; i++) {
void *addr;
if (!test_bit(R5_Wantwrite, &sh->dev[i].flags))
continue;
write_disks++;
if (test_bit(STRIPE_LOG_TRAPPED, &sh->state))
continue;
addr = kmap_atomic(sh->dev[i].page);
sh->dev[i].log_checksum = crc32c_le(log->uuid_checksum,
addr, PAGE_SIZE);
kunmap_atomic(addr);
}
parity_pages = 1 + !!(sh->qd_idx >= 0);
data_pages = write_disks - parity_pages;
meta_size =
((sizeof(struct r5l_payload_data_parity) + sizeof(__le32))
* data_pages) +
sizeof(struct r5l_payload_data_parity) +
sizeof(__le32) * parity_pages;
if (meta_size + sizeof(struct r5l_meta_block) > PAGE_SIZE)
return -EINVAL;
set_bit(STRIPE_LOG_TRAPPED, &sh->state);
clear_bit(STRIPE_DELAYED, &sh->state);
atomic_inc(&sh->count);
mutex_lock(&log->io_mutex);
reserve = (1 + write_disks) << (PAGE_SHIFT - 9);
if (!r5l_has_free_space(log, reserve)) {
spin_lock(&log->no_space_stripes_lock);
list_add_tail(&sh->log_list, &log->no_space_stripes);
spin_unlock(&log->no_space_stripes_lock);
r5l_wake_reclaim(log, reserve);
} else {
ret = r5l_log_stripe(log, sh, data_pages, parity_pages);
if (ret) {
spin_lock_irq(&log->io_list_lock);
list_add_tail(&sh->log_list, &log->no_mem_stripes);
spin_unlock_irq(&log->io_list_lock);
}
}
mutex_unlock(&log->io_mutex);
return 0;
}
void r5l_write_stripe_run(struct r5l_log *log)
{
if (!log)
return;
mutex_lock(&log->io_mutex);
r5l_submit_current_io(log);
mutex_unlock(&log->io_mutex);
}
int r5l_handle_flush_request(struct r5l_log *log, struct bio *bio)
{
if (!log)
return -ENODEV;
if (bio->bi_iter.bi_size == 0) {
bio_endio(bio);
return 0;
}
bio->bi_opf &= ~REQ_PREFLUSH;
return -EAGAIN;
}
static void r5l_run_no_space_stripes(struct r5l_log *log)
{
struct stripe_head *sh;
spin_lock(&log->no_space_stripes_lock);
while (!list_empty(&log->no_space_stripes)) {
sh = list_first_entry(&log->no_space_stripes,
struct stripe_head, log_list);
list_del_init(&sh->log_list);
set_bit(STRIPE_HANDLE, &sh->state);
raid5_release_stripe(sh);
}
spin_unlock(&log->no_space_stripes_lock);
}
static sector_t r5l_reclaimable_space(struct r5l_log *log)
{
return r5l_ring_distance(log, log->last_checkpoint,
log->next_checkpoint);
}
static void r5l_run_no_mem_stripe(struct r5l_log *log)
{
struct stripe_head *sh;
assert_spin_locked(&log->io_list_lock);
if (!list_empty(&log->no_mem_stripes)) {
sh = list_first_entry(&log->no_mem_stripes,
struct stripe_head, log_list);
list_del_init(&sh->log_list);
set_bit(STRIPE_HANDLE, &sh->state);
raid5_release_stripe(sh);
}
}
static bool r5l_complete_finished_ios(struct r5l_log *log)
{
struct r5l_io_unit *io, *next;
bool found = false;
assert_spin_locked(&log->io_list_lock);
list_for_each_entry_safe(io, next, &log->finished_ios, log_sibling) {
if (io->state < IO_UNIT_STRIPE_END)
break;
log->next_checkpoint = io->log_start;
log->next_cp_seq = io->seq;
list_del(&io->log_sibling);
mempool_free(io, log->io_pool);
r5l_run_no_mem_stripe(log);
found = true;
}
return found;
}
static void __r5l_stripe_write_finished(struct r5l_io_unit *io)
{
struct r5l_log *log = io->log;
unsigned long flags;
spin_lock_irqsave(&log->io_list_lock, flags);
__r5l_set_io_unit_state(io, IO_UNIT_STRIPE_END);
if (!r5l_complete_finished_ios(log)) {
spin_unlock_irqrestore(&log->io_list_lock, flags);
return;
}
if (r5l_reclaimable_space(log) > log->max_free_space)
r5l_wake_reclaim(log, 0);
spin_unlock_irqrestore(&log->io_list_lock, flags);
wake_up(&log->iounit_wait);
}
void r5l_stripe_write_finished(struct stripe_head *sh)
{
struct r5l_io_unit *io;
io = sh->log_io;
sh->log_io = NULL;
if (io && atomic_dec_and_test(&io->pending_stripe))
__r5l_stripe_write_finished(io);
}
static void r5l_log_flush_endio(struct bio *bio)
{
struct r5l_log *log = container_of(bio, struct r5l_log,
flush_bio);
unsigned long flags;
struct r5l_io_unit *io;
if (bio->bi_error)
md_error(log->rdev->mddev, log->rdev);
spin_lock_irqsave(&log->io_list_lock, flags);
list_for_each_entry(io, &log->flushing_ios, log_sibling)
r5l_io_run_stripes(io);
list_splice_tail_init(&log->flushing_ios, &log->finished_ios);
spin_unlock_irqrestore(&log->io_list_lock, flags);
}
void r5l_flush_stripe_to_raid(struct r5l_log *log)
{
bool do_flush;
if (!log || !log->need_cache_flush)
return;
spin_lock_irq(&log->io_list_lock);
if (!list_empty(&log->flushing_ios)) {
spin_unlock_irq(&log->io_list_lock);
return;
}
list_splice_tail_init(&log->io_end_ios, &log->flushing_ios);
do_flush = !list_empty(&log->flushing_ios);
spin_unlock_irq(&log->io_list_lock);
if (!do_flush)
return;
bio_reset(&log->flush_bio);
log->flush_bio.bi_bdev = log->rdev->bdev;
log->flush_bio.bi_end_io = r5l_log_flush_endio;
bio_set_op_attrs(&log->flush_bio, REQ_OP_WRITE, WRITE_FLUSH);
submit_bio(&log->flush_bio);
}
static void r5l_write_super_and_discard_space(struct r5l_log *log,
sector_t end)
{
struct block_device *bdev = log->rdev->bdev;
struct mddev *mddev;
r5l_write_super(log, end);
if (!blk_queue_discard(bdev_get_queue(bdev)))
return;
mddev = log->rdev->mddev;
set_mask_bits(&mddev->flags, 0,
BIT(MD_CHANGE_DEVS) | BIT(MD_CHANGE_PENDING));
if (!mddev_trylock(mddev))
return;
md_update_sb(mddev, 1);
mddev_unlock(mddev);
if (log->last_checkpoint < end) {
blkdev_issue_discard(bdev,
log->last_checkpoint + log->rdev->data_offset,
end - log->last_checkpoint, GFP_NOIO, 0);
} else {
blkdev_issue_discard(bdev,
log->last_checkpoint + log->rdev->data_offset,
log->device_size - log->last_checkpoint,
GFP_NOIO, 0);
blkdev_issue_discard(bdev, log->rdev->data_offset, end,
GFP_NOIO, 0);
}
}
static void r5l_do_reclaim(struct r5l_log *log)
{
sector_t reclaim_target = xchg(&log->reclaim_target, 0);
sector_t reclaimable;
sector_t next_checkpoint;
u64 next_cp_seq;
spin_lock_irq(&log->io_list_lock);
while (1) {
reclaimable = r5l_reclaimable_space(log);
if (reclaimable >= reclaim_target ||
(list_empty(&log->running_ios) &&
list_empty(&log->io_end_ios) &&
list_empty(&log->flushing_ios) &&
list_empty(&log->finished_ios)))
break;
md_wakeup_thread(log->rdev->mddev->thread);
wait_event_lock_irq(log->iounit_wait,
r5l_reclaimable_space(log) > reclaimable,
log->io_list_lock);
}
next_checkpoint = log->next_checkpoint;
next_cp_seq = log->next_cp_seq;
spin_unlock_irq(&log->io_list_lock);
BUG_ON(reclaimable < 0);
if (reclaimable == 0)
return;
r5l_write_super_and_discard_space(log, next_checkpoint);
mutex_lock(&log->io_mutex);
log->last_checkpoint = next_checkpoint;
log->last_cp_seq = next_cp_seq;
mutex_unlock(&log->io_mutex);
r5l_run_no_space_stripes(log);
}
static void r5l_reclaim_thread(struct md_thread *thread)
{
struct mddev *mddev = thread->mddev;
struct r5conf *conf = mddev->private;
struct r5l_log *log = conf->log;
if (!log)
return;
r5l_do_reclaim(log);
}
static void r5l_wake_reclaim(struct r5l_log *log, sector_t space)
{
unsigned long target;
unsigned long new = (unsigned long)space;
do {
target = log->reclaim_target;
if (new < target)
return;
} while (cmpxchg(&log->reclaim_target, target, new) != target);
md_wakeup_thread(log->reclaim_thread);
}
void r5l_quiesce(struct r5l_log *log, int state)
{
struct mddev *mddev;
if (!log || state == 2)
return;
if (state == 0) {
if (log->reclaim_thread)
return;
log->reclaim_thread = md_register_thread(r5l_reclaim_thread,
log->rdev->mddev, "reclaim");
} else if (state == 1) {
mddev = log->rdev->mddev;
wake_up(&mddev->sb_wait);
r5l_wake_reclaim(log, -1L);
md_unregister_thread(&log->reclaim_thread);
r5l_do_reclaim(log);
}
}
bool r5l_log_disk_error(struct r5conf *conf)
{
struct r5l_log *log;
bool ret;
rcu_read_lock();
log = rcu_dereference(conf->log);
if (!log)
ret = test_bit(MD_HAS_JOURNAL, &conf->mddev->flags);
else
ret = test_bit(Faulty, &log->rdev->flags);
rcu_read_unlock();
return ret;
}
static int r5l_read_meta_block(struct r5l_log *log,
struct r5l_recovery_ctx *ctx)
{
struct page *page = ctx->meta_page;
struct r5l_meta_block *mb;
u32 crc, stored_crc;
if (!sync_page_io(log->rdev, ctx->pos, PAGE_SIZE, page, REQ_OP_READ, 0,
false))
return -EIO;
mb = page_address(page);
stored_crc = le32_to_cpu(mb->checksum);
mb->checksum = 0;
if (le32_to_cpu(mb->magic) != R5LOG_MAGIC ||
le64_to_cpu(mb->seq) != ctx->seq ||
mb->version != R5LOG_VERSION ||
le64_to_cpu(mb->position) != ctx->pos)
return -EINVAL;
crc = crc32c_le(log->uuid_checksum, mb, PAGE_SIZE);
if (stored_crc != crc)
return -EINVAL;
if (le32_to_cpu(mb->meta_size) > PAGE_SIZE)
return -EINVAL;
ctx->meta_total_blocks = BLOCK_SECTORS;
return 0;
}
static int r5l_recovery_flush_one_stripe(struct r5l_log *log,
struct r5l_recovery_ctx *ctx,
sector_t stripe_sect,
int *offset, sector_t *log_offset)
{
struct r5conf *conf = log->rdev->mddev->private;
struct stripe_head *sh;
struct r5l_payload_data_parity *payload;
int disk_index;
sh = raid5_get_active_stripe(conf, stripe_sect, 0, 0, 0);
while (1) {
payload = page_address(ctx->meta_page) + *offset;
if (le16_to_cpu(payload->header.type) == R5LOG_PAYLOAD_DATA) {
raid5_compute_sector(conf,
le64_to_cpu(payload->location), 0,
&disk_index, sh);
sync_page_io(log->rdev, *log_offset, PAGE_SIZE,
sh->dev[disk_index].page, REQ_OP_READ, 0,
false);
sh->dev[disk_index].log_checksum =
le32_to_cpu(payload->checksum[0]);
set_bit(R5_Wantwrite, &sh->dev[disk_index].flags);
ctx->meta_total_blocks += BLOCK_SECTORS;
} else {
disk_index = sh->pd_idx;
sync_page_io(log->rdev, *log_offset, PAGE_SIZE,
sh->dev[disk_index].page, REQ_OP_READ, 0,
false);
sh->dev[disk_index].log_checksum =
le32_to_cpu(payload->checksum[0]);
set_bit(R5_Wantwrite, &sh->dev[disk_index].flags);
if (sh->qd_idx >= 0) {
disk_index = sh->qd_idx;
sync_page_io(log->rdev,
r5l_ring_add(log, *log_offset, BLOCK_SECTORS),
PAGE_SIZE, sh->dev[disk_index].page,
REQ_OP_READ, 0, false);
sh->dev[disk_index].log_checksum =
le32_to_cpu(payload->checksum[1]);
set_bit(R5_Wantwrite,
&sh->dev[disk_index].flags);
}
ctx->meta_total_blocks += BLOCK_SECTORS * conf->max_degraded;
}
*log_offset = r5l_ring_add(log, *log_offset,
le32_to_cpu(payload->size));
*offset += sizeof(struct r5l_payload_data_parity) +
sizeof(__le32) *
(le32_to_cpu(payload->size) >> (PAGE_SHIFT - 9));
if (le16_to_cpu(payload->header.type) == R5LOG_PAYLOAD_PARITY)
break;
}
for (disk_index = 0; disk_index < sh->disks; disk_index++) {
void *addr;
u32 checksum;
if (!test_bit(R5_Wantwrite, &sh->dev[disk_index].flags))
continue;
addr = kmap_atomic(sh->dev[disk_index].page);
checksum = crc32c_le(log->uuid_checksum, addr, PAGE_SIZE);
kunmap_atomic(addr);
if (checksum != sh->dev[disk_index].log_checksum)
goto error;
}
for (disk_index = 0; disk_index < sh->disks; disk_index++) {
struct md_rdev *rdev, *rrdev;
if (!test_and_clear_bit(R5_Wantwrite,
&sh->dev[disk_index].flags))
continue;
rdev = rcu_dereference(conf->disks[disk_index].rdev);
if (rdev)
sync_page_io(rdev, stripe_sect, PAGE_SIZE,
sh->dev[disk_index].page, REQ_OP_WRITE, 0,
false);
rrdev = rcu_dereference(conf->disks[disk_index].replacement);
if (rrdev)
sync_page_io(rrdev, stripe_sect, PAGE_SIZE,
sh->dev[disk_index].page, REQ_OP_WRITE, 0,
false);
}
raid5_release_stripe(sh);
return 0;
error:
for (disk_index = 0; disk_index < sh->disks; disk_index++)
sh->dev[disk_index].flags = 0;
raid5_release_stripe(sh);
return -EINVAL;
}
static int r5l_recovery_flush_one_meta(struct r5l_log *log,
struct r5l_recovery_ctx *ctx)
{
struct r5conf *conf = log->rdev->mddev->private;
struct r5l_payload_data_parity *payload;
struct r5l_meta_block *mb;
int offset;
sector_t log_offset;
sector_t stripe_sector;
mb = page_address(ctx->meta_page);
offset = sizeof(struct r5l_meta_block);
log_offset = r5l_ring_add(log, ctx->pos, BLOCK_SECTORS);
while (offset < le32_to_cpu(mb->meta_size)) {
int dd;
payload = (void *)mb + offset;
stripe_sector = raid5_compute_sector(conf,
le64_to_cpu(payload->location), 0, &dd, NULL);
if (r5l_recovery_flush_one_stripe(log, ctx, stripe_sector,
&offset, &log_offset))
return -EINVAL;
}
return 0;
}
static void r5l_recovery_flush_log(struct r5l_log *log,
struct r5l_recovery_ctx *ctx)
{
while (1) {
if (r5l_read_meta_block(log, ctx))
return;
if (r5l_recovery_flush_one_meta(log, ctx))
return;
ctx->seq++;
ctx->pos = r5l_ring_add(log, ctx->pos, ctx->meta_total_blocks);
}
}
static int r5l_log_write_empty_meta_block(struct r5l_log *log, sector_t pos,
u64 seq)
{
struct page *page;
struct r5l_meta_block *mb;
u32 crc;
page = alloc_page(GFP_KERNEL | __GFP_ZERO);
if (!page)
return -ENOMEM;
mb = page_address(page);
mb->magic = cpu_to_le32(R5LOG_MAGIC);
mb->version = R5LOG_VERSION;
mb->meta_size = cpu_to_le32(sizeof(struct r5l_meta_block));
mb->seq = cpu_to_le64(seq);
mb->position = cpu_to_le64(pos);
crc = crc32c_le(log->uuid_checksum, mb, PAGE_SIZE);
mb->checksum = cpu_to_le32(crc);
if (!sync_page_io(log->rdev, pos, PAGE_SIZE, page, REQ_OP_WRITE,
WRITE_FUA, false)) {
__free_page(page);
return -EIO;
}
__free_page(page);
return 0;
}
static int r5l_recovery_log(struct r5l_log *log)
{
struct r5l_recovery_ctx ctx;
ctx.pos = log->last_checkpoint;
ctx.seq = log->last_cp_seq;
ctx.meta_page = alloc_page(GFP_KERNEL);
if (!ctx.meta_page)
return -ENOMEM;
r5l_recovery_flush_log(log, &ctx);
__free_page(ctx.meta_page);
if (ctx.seq > log->last_cp_seq) {
int ret;
ret = r5l_log_write_empty_meta_block(log, ctx.pos, ctx.seq + 10);
if (ret)
return ret;
log->seq = ctx.seq + 11;
log->log_start = r5l_ring_add(log, ctx.pos, BLOCK_SECTORS);
r5l_write_super(log, ctx.pos);
log->last_checkpoint = ctx.pos;
log->next_checkpoint = ctx.pos;
} else {
log->log_start = ctx.pos;
log->seq = ctx.seq;
}
return 0;
}
static void r5l_write_super(struct r5l_log *log, sector_t cp)
{
struct mddev *mddev = log->rdev->mddev;
log->rdev->journal_tail = cp;
set_bit(MD_CHANGE_DEVS, &mddev->flags);
}
static int r5l_load_log(struct r5l_log *log)
{
struct md_rdev *rdev = log->rdev;
struct page *page;
struct r5l_meta_block *mb;
sector_t cp = log->rdev->journal_tail;
u32 stored_crc, expected_crc;
bool create_super = false;
int ret;
if (cp >= rdev->sectors || round_down(cp, BLOCK_SECTORS) != cp)
cp = 0;
page = alloc_page(GFP_KERNEL);
if (!page)
return -ENOMEM;
if (!sync_page_io(rdev, cp, PAGE_SIZE, page, REQ_OP_READ, 0, false)) {
ret = -EIO;
goto ioerr;
}
mb = page_address(page);
if (le32_to_cpu(mb->magic) != R5LOG_MAGIC ||
mb->version != R5LOG_VERSION) {
create_super = true;
goto create;
}
stored_crc = le32_to_cpu(mb->checksum);
mb->checksum = 0;
expected_crc = crc32c_le(log->uuid_checksum, mb, PAGE_SIZE);
if (stored_crc != expected_crc) {
create_super = true;
goto create;
}
if (le64_to_cpu(mb->position) != cp) {
create_super = true;
goto create;
}
create:
if (create_super) {
log->last_cp_seq = prandom_u32();
cp = 0;
r5l_log_write_empty_meta_block(log, cp, log->last_cp_seq);
r5l_write_super(log, cp);
} else
log->last_cp_seq = le64_to_cpu(mb->seq);
log->device_size = round_down(rdev->sectors, BLOCK_SECTORS);
log->max_free_space = log->device_size >> RECLAIM_MAX_FREE_SPACE_SHIFT;
if (log->max_free_space > RECLAIM_MAX_FREE_SPACE)
log->max_free_space = RECLAIM_MAX_FREE_SPACE;
log->last_checkpoint = cp;
log->next_checkpoint = cp;
__free_page(page);
return r5l_recovery_log(log);
ioerr:
__free_page(page);
return ret;
}
int r5l_init_log(struct r5conf *conf, struct md_rdev *rdev)
{
struct request_queue *q = bdev_get_queue(rdev->bdev);
struct r5l_log *log;
if (PAGE_SIZE != 4096)
return -EINVAL;
log = kzalloc(sizeof(*log), GFP_KERNEL);
if (!log)
return -ENOMEM;
log->rdev = rdev;
log->need_cache_flush = test_bit(QUEUE_FLAG_WC, &q->queue_flags) != 0;
log->uuid_checksum = crc32c_le(~0, rdev->mddev->uuid,
sizeof(rdev->mddev->uuid));
mutex_init(&log->io_mutex);
spin_lock_init(&log->io_list_lock);
INIT_LIST_HEAD(&log->running_ios);
INIT_LIST_HEAD(&log->io_end_ios);
INIT_LIST_HEAD(&log->flushing_ios);
INIT_LIST_HEAD(&log->finished_ios);
bio_init(&log->flush_bio);
log->io_kc = KMEM_CACHE(r5l_io_unit, 0);
if (!log->io_kc)
goto io_kc;
log->io_pool = mempool_create_slab_pool(R5L_POOL_SIZE, log->io_kc);
if (!log->io_pool)
goto io_pool;
log->bs = bioset_create(R5L_POOL_SIZE, 0);
if (!log->bs)
goto io_bs;
log->meta_pool = mempool_create_page_pool(R5L_POOL_SIZE, 0);
if (!log->meta_pool)
goto out_mempool;
log->reclaim_thread = md_register_thread(r5l_reclaim_thread,
log->rdev->mddev, "reclaim");
if (!log->reclaim_thread)
goto reclaim_thread;
init_waitqueue_head(&log->iounit_wait);
INIT_LIST_HEAD(&log->no_mem_stripes);
INIT_LIST_HEAD(&log->no_space_stripes);
spin_lock_init(&log->no_space_stripes_lock);
if (r5l_load_log(log))
goto error;
rcu_assign_pointer(conf->log, log);
set_bit(MD_HAS_JOURNAL, &conf->mddev->flags);
return 0;
error:
md_unregister_thread(&log->reclaim_thread);
reclaim_thread:
mempool_destroy(log->meta_pool);
out_mempool:
bioset_free(log->bs);
io_bs:
mempool_destroy(log->io_pool);
io_pool:
kmem_cache_destroy(log->io_kc);
io_kc:
kfree(log);
return -EINVAL;
}
void r5l_exit_log(struct r5l_log *log)
{
md_unregister_thread(&log->reclaim_thread);
mempool_destroy(log->meta_pool);
bioset_free(log->bs);
mempool_destroy(log->io_pool);
kmem_cache_destroy(log->io_kc);
kfree(log);
}
