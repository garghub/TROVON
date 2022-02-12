bool r5c_is_writeback(struct r5l_log *log)
{
return (log != NULL &&
log->r5c_journal_mode == R5C_JOURNAL_MODE_WRITE_BACK);
}
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
static void
r5c_return_dev_pending_writes(struct r5conf *conf, struct r5dev *dev,
struct bio_list *return_bi)
{
struct bio *wbi, *wbi2;
wbi = dev->written;
dev->written = NULL;
while (wbi && wbi->bi_iter.bi_sector <
dev->sector + STRIPE_SECTORS) {
wbi2 = r5_next_bio(wbi, dev->sector);
if (!raid5_dec_bi_active_stripes(wbi)) {
md_write_end(conf->mddev);
bio_list_add(return_bi, wbi);
}
wbi = wbi2;
}
}
void r5c_handle_cached_data_endio(struct r5conf *conf,
struct stripe_head *sh, int disks, struct bio_list *return_bi)
{
int i;
for (i = sh->disks; i--; ) {
if (sh->dev[i].written) {
set_bit(R5_UPTODATE, &sh->dev[i].flags);
r5c_return_dev_pending_writes(conf, &sh->dev[i],
return_bi);
bitmap_endwrite(conf->mddev->bitmap, sh->sector,
STRIPE_SECTORS,
!test_bit(STRIPE_DEGRADED, &sh->state),
0);
}
}
}
void r5c_check_stripe_cache_usage(struct r5conf *conf)
{
int total_cached;
if (!r5c_is_writeback(conf->log))
return;
total_cached = atomic_read(&conf->r5c_cached_partial_stripes) +
atomic_read(&conf->r5c_cached_full_stripes);
if (total_cached > conf->min_nr_stripes * 1 / 2 ||
atomic_read(&conf->empty_inactive_list_nr) > 0)
r5l_wake_reclaim(conf->log, 0);
}
void r5c_check_cached_full_stripe(struct r5conf *conf)
{
if (!r5c_is_writeback(conf->log))
return;
if (atomic_read(&conf->r5c_cached_full_stripes) >=
min(R5C_FULL_STRIPE_FLUSH_BATCH,
conf->chunk_sectors >> STRIPE_SHIFT))
r5l_wake_reclaim(conf->log, 0);
}
static sector_t r5c_log_required_to_flush_cache(struct r5conf *conf)
{
struct r5l_log *log = conf->log;
if (!r5c_is_writeback(log))
return 0;
return BLOCK_SECTORS * (conf->raid_disks + 1) *
atomic_read(&log->stripe_in_journal_count);
}
static inline void r5c_update_log_state(struct r5l_log *log)
{
struct r5conf *conf = log->rdev->mddev->private;
sector_t free_space;
sector_t reclaim_space;
bool wake_reclaim = false;
if (!r5c_is_writeback(log))
return;
free_space = r5l_ring_distance(log, log->log_start,
log->last_checkpoint);
reclaim_space = r5c_log_required_to_flush_cache(conf);
if (free_space < 2 * reclaim_space)
set_bit(R5C_LOG_CRITICAL, &conf->cache_state);
else {
if (test_bit(R5C_LOG_CRITICAL, &conf->cache_state))
wake_reclaim = true;
clear_bit(R5C_LOG_CRITICAL, &conf->cache_state);
}
if (free_space < 3 * reclaim_space)
set_bit(R5C_LOG_TIGHT, &conf->cache_state);
else
clear_bit(R5C_LOG_TIGHT, &conf->cache_state);
if (wake_reclaim)
r5l_wake_reclaim(log, 0);
}
void r5c_make_stripe_write_out(struct stripe_head *sh)
{
struct r5conf *conf = sh->raid_conf;
struct r5l_log *log = conf->log;
BUG_ON(!r5c_is_writeback(log));
WARN_ON(!test_bit(STRIPE_R5C_CACHING, &sh->state));
clear_bit(STRIPE_R5C_CACHING, &sh->state);
if (!test_and_set_bit(STRIPE_PREREAD_ACTIVE, &sh->state))
atomic_inc(&conf->preread_active_stripes);
if (test_and_clear_bit(STRIPE_R5C_PARTIAL_STRIPE, &sh->state)) {
BUG_ON(atomic_read(&conf->r5c_cached_partial_stripes) == 0);
atomic_dec(&conf->r5c_cached_partial_stripes);
}
if (test_and_clear_bit(STRIPE_R5C_FULL_STRIPE, &sh->state)) {
BUG_ON(atomic_read(&conf->r5c_cached_full_stripes) == 0);
atomic_dec(&conf->r5c_cached_full_stripes);
}
}
static void r5c_handle_data_cached(struct stripe_head *sh)
{
int i;
for (i = sh->disks; i--; )
if (test_and_clear_bit(R5_Wantwrite, &sh->dev[i].flags)) {
set_bit(R5_InJournal, &sh->dev[i].flags);
clear_bit(R5_LOCKED, &sh->dev[i].flags);
}
clear_bit(STRIPE_LOG_TRAPPED, &sh->state);
}
static void r5c_handle_parity_cached(struct stripe_head *sh)
{
int i;
for (i = sh->disks; i--; )
if (test_bit(R5_InJournal, &sh->dev[i].flags))
set_bit(R5_Wantwrite, &sh->dev[i].flags);
}
static void r5c_finish_cache_stripe(struct stripe_head *sh)
{
struct r5l_log *log = sh->raid_conf->log;
if (log->r5c_journal_mode == R5C_JOURNAL_MODE_WRITE_THROUGH) {
BUG_ON(test_bit(STRIPE_R5C_CACHING, &sh->state));
set_bit(R5_InJournal, &sh->dev[sh->pd_idx].flags);
} else if (test_bit(STRIPE_R5C_CACHING, &sh->state)) {
r5c_handle_data_cached(sh);
} else {
r5c_handle_parity_cached(sh);
set_bit(R5_InJournal, &sh->dev[sh->pd_idx].flags);
}
}
static void r5l_io_run_stripes(struct r5l_io_unit *io)
{
struct stripe_head *sh, *next;
list_for_each_entry_safe(sh, next, &io->stripe_list, log_list) {
list_del_init(&sh->log_list);
r5c_finish_cache_stripe(sh);
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
struct r5l_io_unit *io_deferred;
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
if (!list_empty(&log->running_ios)) {
io_deferred = list_first_entry(&log->running_ios,
struct r5l_io_unit, log_sibling);
if (io_deferred->io_deferred)
schedule_work(&log->deferred_io_work);
}
spin_unlock_irqrestore(&log->io_list_lock, flags);
if (log->need_cache_flush)
md_wakeup_thread(log->rdev->mddev->thread);
if (io->has_null_flush) {
struct bio *bi;
WARN_ON(bio_list_empty(&io->flush_barriers));
while ((bi = bio_list_pop(&io->flush_barriers)) != NULL) {
bio_endio(bi);
atomic_dec(&io->pending_stripe);
}
if (atomic_read(&io->pending_stripe) == 0)
__r5l_stripe_write_finished(io);
}
}
static void r5l_do_submit_io(struct r5l_log *log, struct r5l_io_unit *io)
{
unsigned long flags;
spin_lock_irqsave(&log->io_list_lock, flags);
__r5l_set_io_unit_state(io, IO_UNIT_IO_START);
spin_unlock_irqrestore(&log->io_list_lock, flags);
if (io->has_flush)
io->current_bio->bi_opf |= REQ_PREFLUSH;
if (io->has_fua)
io->current_bio->bi_opf |= REQ_FUA;
submit_bio(io->current_bio);
if (!io->split_bio)
return;
if (io->has_flush)
io->split_bio->bi_opf |= REQ_PREFLUSH;
if (io->has_fua)
io->split_bio->bi_opf |= REQ_FUA;
submit_bio(io->split_bio);
}
static void r5l_submit_io_async(struct work_struct *work)
{
struct r5l_log *log = container_of(work, struct r5l_log,
deferred_io_work);
struct r5l_io_unit *io = NULL;
unsigned long flags;
spin_lock_irqsave(&log->io_list_lock, flags);
if (!list_empty(&log->running_ios)) {
io = list_first_entry(&log->running_ios, struct r5l_io_unit,
log_sibling);
if (!io->io_deferred)
io = NULL;
else
io->io_deferred = 0;
}
spin_unlock_irqrestore(&log->io_list_lock, flags);
if (io)
r5l_do_submit_io(log, io);
}
static void r5c_disable_writeback_async(struct work_struct *work)
{
struct r5l_log *log = container_of(work, struct r5l_log,
disable_writeback_work);
struct mddev *mddev = log->rdev->mddev;
if (log->r5c_journal_mode == R5C_JOURNAL_MODE_WRITE_THROUGH)
return;
pr_info("md/raid:%s: Disabling writeback cache for degraded array.\n",
mdname(mddev));
mddev_suspend(mddev);
log->r5c_journal_mode = R5C_JOURNAL_MODE_WRITE_THROUGH;
mddev_resume(mddev);
}
static void r5l_submit_current_io(struct r5l_log *log)
{
struct r5l_io_unit *io = log->current_io;
struct bio *bio;
struct r5l_meta_block *block;
unsigned long flags;
u32 crc;
bool do_submit = true;
if (!io)
return;
block = page_address(io->meta_page);
block->meta_size = cpu_to_le32(io->meta_offset);
crc = crc32c_le(log->uuid_checksum, block, PAGE_SIZE);
block->checksum = cpu_to_le32(crc);
bio = io->current_bio;
log->current_io = NULL;
spin_lock_irqsave(&log->io_list_lock, flags);
if (io->has_flush || io->has_fua) {
if (io != list_first_entry(&log->running_ios,
struct r5l_io_unit, log_sibling)) {
io->io_deferred = 1;
do_submit = false;
}
}
spin_unlock_irqrestore(&log->io_list_lock, flags);
if (do_submit)
r5l_do_submit_io(log, io);
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
r5c_update_log_state(log);
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
bio_list_init(&io->flush_barriers);
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
BUG_ON(io->split_bio);
io->split_bio = io->current_bio;
io->current_bio = r5l_bio_alloc(log);
bio_chain(io->current_bio, io->split_bio);
io->need_split_bio = false;
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
if (test_and_clear_bit(STRIPE_R5C_PREFLUSH, &sh->state))
io->has_flush = 1;
for (i = 0; i < sh->disks; i++) {
if (!test_bit(R5_Wantwrite, &sh->dev[i].flags) ||
test_bit(R5_InJournal, &sh->dev[i].flags))
continue;
if (i == sh->pd_idx || i == sh->qd_idx)
continue;
if (test_bit(R5_WantFUA, &sh->dev[i].flags) &&
log->r5c_journal_mode == R5C_JOURNAL_MODE_WRITE_BACK) {
io->has_fua = 1;
io->has_flush = 1;
}
r5l_append_payload_meta(log, R5LOG_PAYLOAD_DATA,
raid5_compute_blocknr(sh, i, 0),
sh->dev[i].log_checksum, 0, false);
r5l_append_payload_page(log, sh->dev[i].page);
}
if (parity_pages == 2) {
r5l_append_payload_meta(log, R5LOG_PAYLOAD_PARITY,
sh->sector, sh->dev[sh->pd_idx].log_checksum,
sh->dev[sh->qd_idx].log_checksum, true);
r5l_append_payload_page(log, sh->dev[sh->pd_idx].page);
r5l_append_payload_page(log, sh->dev[sh->qd_idx].page);
} else if (parity_pages == 1) {
r5l_append_payload_meta(log, R5LOG_PAYLOAD_PARITY,
sh->sector, sh->dev[sh->pd_idx].log_checksum,
0, false);
r5l_append_payload_page(log, sh->dev[sh->pd_idx].page);
} else
BUG_ON(parity_pages != 0);
list_add_tail(&sh->log_list, &io->stripe_list);
atomic_inc(&io->pending_stripe);
sh->log_io = io;
if (log->r5c_journal_mode == R5C_JOURNAL_MODE_WRITE_THROUGH)
return 0;
if (sh->log_start == MaxSector) {
BUG_ON(!list_empty(&sh->r5c));
sh->log_start = io->log_start;
spin_lock_irq(&log->stripe_in_journal_lock);
list_add_tail(&sh->r5c,
&log->stripe_in_journal_list);
spin_unlock_irq(&log->stripe_in_journal_lock);
atomic_inc(&log->stripe_in_journal_count);
}
return 0;
}
static inline void r5l_add_no_space_stripe(struct r5l_log *log,
struct stripe_head *sh)
{
spin_lock(&log->no_space_stripes_lock);
list_add_tail(&sh->log_list, &log->no_space_stripes);
spin_unlock(&log->no_space_stripes_lock);
}
int r5l_write_stripe(struct r5l_log *log, struct stripe_head *sh)
{
struct r5conf *conf = sh->raid_conf;
int write_disks = 0;
int data_pages, parity_pages;
int reserve;
int i;
int ret = 0;
bool wake_reclaim = false;
if (!log)
return -EAGAIN;
if (sh->log_io || !test_bit(R5_Wantwrite, &sh->dev[sh->pd_idx].flags) ||
test_bit(STRIPE_SYNCING, &sh->state)) {
clear_bit(STRIPE_LOG_TRAPPED, &sh->state);
return -EAGAIN;
}
WARN_ON(test_bit(STRIPE_R5C_CACHING, &sh->state));
for (i = 0; i < sh->disks; i++) {
void *addr;
if (!test_bit(R5_Wantwrite, &sh->dev[i].flags) ||
test_bit(R5_InJournal, &sh->dev[i].flags))
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
set_bit(STRIPE_LOG_TRAPPED, &sh->state);
clear_bit(STRIPE_DELAYED, &sh->state);
atomic_inc(&sh->count);
mutex_lock(&log->io_mutex);
reserve = (1 + write_disks) << (PAGE_SHIFT - 9);
if (log->r5c_journal_mode == R5C_JOURNAL_MODE_WRITE_THROUGH) {
if (!r5l_has_free_space(log, reserve)) {
r5l_add_no_space_stripe(log, sh);
wake_reclaim = true;
} else {
ret = r5l_log_stripe(log, sh, data_pages, parity_pages);
if (ret) {
spin_lock_irq(&log->io_list_lock);
list_add_tail(&sh->log_list,
&log->no_mem_stripes);
spin_unlock_irq(&log->io_list_lock);
}
}
} else {
if (test_bit(R5C_LOG_CRITICAL, &conf->cache_state) &&
sh->log_start == MaxSector) {
r5l_add_no_space_stripe(log, sh);
wake_reclaim = true;
reserve = 0;
} else if (!r5l_has_free_space(log, reserve)) {
if (sh->log_start == log->last_checkpoint)
BUG();
else
r5l_add_no_space_stripe(log, sh);
} else {
ret = r5l_log_stripe(log, sh, data_pages, parity_pages);
if (ret) {
spin_lock_irq(&log->io_list_lock);
list_add_tail(&sh->log_list,
&log->no_mem_stripes);
spin_unlock_irq(&log->io_list_lock);
}
}
}
mutex_unlock(&log->io_mutex);
if (wake_reclaim)
r5l_wake_reclaim(log, reserve);
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
if (log->r5c_journal_mode == R5C_JOURNAL_MODE_WRITE_THROUGH) {
if (bio->bi_iter.bi_size == 0) {
bio_endio(bio);
return 0;
}
bio->bi_opf &= ~REQ_PREFLUSH;
} else {
if (bio->bi_iter.bi_size == 0) {
mutex_lock(&log->io_mutex);
r5l_get_meta(log, 0);
bio_list_add(&log->current_io->flush_barriers, bio);
log->current_io->has_flush = 1;
log->current_io->has_null_flush = 1;
atomic_inc(&log->current_io->pending_stripe);
r5l_submit_current_io(log);
mutex_unlock(&log->io_mutex);
return 0;
}
}
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
static sector_t r5c_calculate_new_cp(struct r5conf *conf)
{
struct stripe_head *sh;
struct r5l_log *log = conf->log;
sector_t new_cp;
unsigned long flags;
if (log->r5c_journal_mode == R5C_JOURNAL_MODE_WRITE_THROUGH)
return log->next_checkpoint;
spin_lock_irqsave(&log->stripe_in_journal_lock, flags);
if (list_empty(&conf->log->stripe_in_journal_list)) {
spin_unlock_irqrestore(&log->stripe_in_journal_lock, flags);
return log->next_checkpoint;
}
sh = list_first_entry(&conf->log->stripe_in_journal_list,
struct stripe_head, r5c);
new_cp = sh->log_start;
spin_unlock_irqrestore(&log->stripe_in_journal_lock, flags);
return new_cp;
}
static sector_t r5l_reclaimable_space(struct r5l_log *log)
{
struct r5conf *conf = log->rdev->mddev->private;
return r5l_ring_distance(log, log->last_checkpoint,
r5c_calculate_new_cp(conf));
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
struct r5conf *conf = log->rdev->mddev->private;
unsigned long flags;
spin_lock_irqsave(&log->io_list_lock, flags);
__r5l_set_io_unit_state(io, IO_UNIT_STRIPE_END);
if (!r5l_complete_finished_ios(log)) {
spin_unlock_irqrestore(&log->io_list_lock, flags);
return;
}
if (r5l_reclaimable_space(log) > log->max_free_space ||
test_bit(R5C_LOG_TIGHT, &conf->cache_state))
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
log->flush_bio.bi_opf = REQ_OP_WRITE | REQ_PREFLUSH;
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
set_mask_bits(&mddev->sb_flags, 0,
BIT(MD_SB_CHANGE_DEVS) | BIT(MD_SB_CHANGE_PENDING));
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
static void r5c_flush_stripe(struct r5conf *conf, struct stripe_head *sh)
{
BUG_ON(list_empty(&sh->lru));
BUG_ON(!test_bit(STRIPE_R5C_CACHING, &sh->state));
BUG_ON(test_bit(STRIPE_HANDLE, &sh->state));
BUG_ON(test_bit(STRIPE_ON_RELEASE_LIST, &sh->state));
assert_spin_locked(&conf->device_lock);
list_del_init(&sh->lru);
atomic_inc(&sh->count);
set_bit(STRIPE_HANDLE, &sh->state);
atomic_inc(&conf->active_stripes);
r5c_make_stripe_write_out(sh);
raid5_release_stripe(sh);
}
void r5c_flush_cache(struct r5conf *conf, int num)
{
int count;
struct stripe_head *sh, *next;
assert_spin_locked(&conf->device_lock);
if (!conf->log)
return;
count = 0;
list_for_each_entry_safe(sh, next, &conf->r5c_full_stripe_list, lru) {
r5c_flush_stripe(conf, sh);
count++;
}
if (count >= num)
return;
list_for_each_entry_safe(sh, next,
&conf->r5c_partial_stripe_list, lru) {
r5c_flush_stripe(conf, sh);
if (++count >= num)
break;
}
}
static void r5c_do_reclaim(struct r5conf *conf)
{
struct r5l_log *log = conf->log;
struct stripe_head *sh;
int count = 0;
unsigned long flags;
int total_cached;
int stripes_to_flush;
if (!r5c_is_writeback(log))
return;
total_cached = atomic_read(&conf->r5c_cached_partial_stripes) +
atomic_read(&conf->r5c_cached_full_stripes);
if (total_cached > conf->min_nr_stripes * 3 / 4 ||
atomic_read(&conf->empty_inactive_list_nr) > 0)
stripes_to_flush = R5C_RECLAIM_STRIPE_GROUP;
else if (total_cached > conf->min_nr_stripes * 1 / 2 ||
atomic_read(&conf->r5c_cached_full_stripes) >
R5C_FULL_STRIPE_FLUSH_BATCH)
stripes_to_flush = 0;
else
stripes_to_flush = -1;
if (stripes_to_flush >= 0) {
spin_lock_irqsave(&conf->device_lock, flags);
r5c_flush_cache(conf, stripes_to_flush);
spin_unlock_irqrestore(&conf->device_lock, flags);
}
if (test_bit(R5C_LOG_TIGHT, &conf->cache_state)) {
spin_lock_irqsave(&log->stripe_in_journal_lock, flags);
spin_lock(&conf->device_lock);
list_for_each_entry(sh, &log->stripe_in_journal_list, r5c) {
if (!list_empty(&sh->lru) &&
!test_bit(STRIPE_HANDLE, &sh->state) &&
atomic_read(&sh->count) == 0) {
r5c_flush_stripe(conf, sh);
}
if (count++ >= R5C_RECLAIM_STRIPE_GROUP)
break;
}
spin_unlock(&conf->device_lock);
spin_unlock_irqrestore(&log->stripe_in_journal_lock, flags);
}
if (!test_bit(R5C_LOG_CRITICAL, &conf->cache_state))
r5l_run_no_space_stripes(log);
md_wakeup_thread(conf->mddev->thread);
}
static void r5l_do_reclaim(struct r5l_log *log)
{
struct r5conf *conf = log->rdev->mddev->private;
sector_t reclaim_target = xchg(&log->reclaim_target, 0);
sector_t reclaimable;
sector_t next_checkpoint;
bool write_super;
spin_lock_irq(&log->io_list_lock);
write_super = r5l_reclaimable_space(log) > log->max_free_space ||
reclaim_target != 0 || !list_empty(&log->no_space_stripes);
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
next_checkpoint = r5c_calculate_new_cp(conf);
spin_unlock_irq(&log->io_list_lock);
if (reclaimable == 0 || !write_super)
return;
r5l_write_super_and_discard_space(log, next_checkpoint);
mutex_lock(&log->io_mutex);
log->last_checkpoint = next_checkpoint;
r5c_update_log_state(log);
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
r5c_do_reclaim(conf);
r5l_do_reclaim(log);
}
void r5l_wake_reclaim(struct r5l_log *log, sector_t space)
{
unsigned long target;
unsigned long new = (unsigned long)space;
if (!log)
return;
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
if (state == 0)
kthread_unpark(log->reclaim_thread->tsk);
else if (state == 1) {
mddev = log->rdev->mddev;
wake_up(&mddev->sb_wait);
kthread_park(log->reclaim_thread->tsk);
r5l_wake_reclaim(log, MaxSector);
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
static int r5l_recovery_read_meta_block(struct r5l_log *log,
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
static void
r5l_recovery_create_empty_meta_block(struct r5l_log *log,
struct page *page,
sector_t pos, u64 seq)
{
struct r5l_meta_block *mb;
mb = page_address(page);
clear_page(mb);
mb->magic = cpu_to_le32(R5LOG_MAGIC);
mb->version = R5LOG_VERSION;
mb->meta_size = cpu_to_le32(sizeof(struct r5l_meta_block));
mb->seq = cpu_to_le64(seq);
mb->position = cpu_to_le64(pos);
}
static int r5l_log_write_empty_meta_block(struct r5l_log *log, sector_t pos,
u64 seq)
{
struct page *page;
struct r5l_meta_block *mb;
page = alloc_page(GFP_KERNEL);
if (!page)
return -ENOMEM;
r5l_recovery_create_empty_meta_block(log, page, pos, seq);
mb = page_address(page);
mb->checksum = cpu_to_le32(crc32c_le(log->uuid_checksum,
mb, PAGE_SIZE));
if (!sync_page_io(log->rdev, pos, PAGE_SIZE, page, REQ_OP_WRITE,
REQ_FUA, false)) {
__free_page(page);
return -EIO;
}
__free_page(page);
return 0;
}
static void r5l_recovery_load_data(struct r5l_log *log,
struct stripe_head *sh,
struct r5l_recovery_ctx *ctx,
struct r5l_payload_data_parity *payload,
sector_t log_offset)
{
struct mddev *mddev = log->rdev->mddev;
struct r5conf *conf = mddev->private;
int dd_idx;
raid5_compute_sector(conf,
le64_to_cpu(payload->location), 0,
&dd_idx, sh);
sync_page_io(log->rdev, log_offset, PAGE_SIZE,
sh->dev[dd_idx].page, REQ_OP_READ, 0, false);
sh->dev[dd_idx].log_checksum =
le32_to_cpu(payload->checksum[0]);
ctx->meta_total_blocks += BLOCK_SECTORS;
set_bit(R5_Wantwrite, &sh->dev[dd_idx].flags);
set_bit(STRIPE_R5C_CACHING, &sh->state);
}
static void r5l_recovery_load_parity(struct r5l_log *log,
struct stripe_head *sh,
struct r5l_recovery_ctx *ctx,
struct r5l_payload_data_parity *payload,
sector_t log_offset)
{
struct mddev *mddev = log->rdev->mddev;
struct r5conf *conf = mddev->private;
ctx->meta_total_blocks += BLOCK_SECTORS * conf->max_degraded;
sync_page_io(log->rdev, log_offset, PAGE_SIZE,
sh->dev[sh->pd_idx].page, REQ_OP_READ, 0, false);
sh->dev[sh->pd_idx].log_checksum =
le32_to_cpu(payload->checksum[0]);
set_bit(R5_Wantwrite, &sh->dev[sh->pd_idx].flags);
if (sh->qd_idx >= 0) {
sync_page_io(log->rdev,
r5l_ring_add(log, log_offset, BLOCK_SECTORS),
PAGE_SIZE, sh->dev[sh->qd_idx].page,
REQ_OP_READ, 0, false);
sh->dev[sh->qd_idx].log_checksum =
le32_to_cpu(payload->checksum[1]);
set_bit(R5_Wantwrite, &sh->dev[sh->qd_idx].flags);
}
clear_bit(STRIPE_R5C_CACHING, &sh->state);
}
static void r5l_recovery_reset_stripe(struct stripe_head *sh)
{
int i;
sh->state = 0;
sh->log_start = MaxSector;
for (i = sh->disks; i--; )
sh->dev[i].flags = 0;
}
static void
r5l_recovery_replay_one_stripe(struct r5conf *conf,
struct stripe_head *sh,
struct r5l_recovery_ctx *ctx)
{
struct md_rdev *rdev, *rrdev;
int disk_index;
int data_count = 0;
for (disk_index = 0; disk_index < sh->disks; disk_index++) {
if (!test_bit(R5_Wantwrite, &sh->dev[disk_index].flags))
continue;
if (disk_index == sh->qd_idx || disk_index == sh->pd_idx)
continue;
data_count++;
}
if (data_count == 0)
goto out;
for (disk_index = 0; disk_index < sh->disks; disk_index++) {
if (!test_bit(R5_Wantwrite, &sh->dev[disk_index].flags))
continue;
rcu_read_lock();
rdev = rcu_dereference(conf->disks[disk_index].rdev);
if (rdev) {
atomic_inc(&rdev->nr_pending);
rcu_read_unlock();
sync_page_io(rdev, sh->sector, PAGE_SIZE,
sh->dev[disk_index].page, REQ_OP_WRITE, 0,
false);
rdev_dec_pending(rdev, rdev->mddev);
rcu_read_lock();
}
rrdev = rcu_dereference(conf->disks[disk_index].replacement);
if (rrdev) {
atomic_inc(&rrdev->nr_pending);
rcu_read_unlock();
sync_page_io(rrdev, sh->sector, PAGE_SIZE,
sh->dev[disk_index].page, REQ_OP_WRITE, 0,
false);
rdev_dec_pending(rrdev, rrdev->mddev);
rcu_read_lock();
}
rcu_read_unlock();
}
ctx->data_parity_stripes++;
out:
r5l_recovery_reset_stripe(sh);
}
static struct stripe_head *
r5c_recovery_alloc_stripe(struct r5conf *conf,
sector_t stripe_sect)
{
struct stripe_head *sh;
sh = raid5_get_active_stripe(conf, stripe_sect, 0, 1, 0);
if (!sh)
return NULL;
r5l_recovery_reset_stripe(sh);
return sh;
}
static struct stripe_head *
r5c_recovery_lookup_stripe(struct list_head *list, sector_t sect)
{
struct stripe_head *sh;
list_for_each_entry(sh, list, lru)
if (sh->sector == sect)
return sh;
return NULL;
}
static void
r5c_recovery_drop_stripes(struct list_head *cached_stripe_list,
struct r5l_recovery_ctx *ctx)
{
struct stripe_head *sh, *next;
list_for_each_entry_safe(sh, next, cached_stripe_list, lru) {
r5l_recovery_reset_stripe(sh);
list_del_init(&sh->lru);
raid5_release_stripe(sh);
}
}
static void
r5c_recovery_replay_stripes(struct list_head *cached_stripe_list,
struct r5l_recovery_ctx *ctx)
{
struct stripe_head *sh, *next;
list_for_each_entry_safe(sh, next, cached_stripe_list, lru)
if (!test_bit(STRIPE_R5C_CACHING, &sh->state)) {
r5l_recovery_replay_one_stripe(sh->raid_conf, sh, ctx);
list_del_init(&sh->lru);
raid5_release_stripe(sh);
}
}
static int
r5l_recovery_verify_data_checksum(struct r5l_log *log, struct page *page,
sector_t log_offset, __le32 log_checksum)
{
void *addr;
u32 checksum;
sync_page_io(log->rdev, log_offset, PAGE_SIZE,
page, REQ_OP_READ, 0, false);
addr = kmap_atomic(page);
checksum = crc32c_le(log->uuid_checksum, addr, PAGE_SIZE);
kunmap_atomic(addr);
return (le32_to_cpu(log_checksum) == checksum) ? 0 : -EINVAL;
}
static int
r5l_recovery_verify_data_checksum_for_mb(struct r5l_log *log,
struct r5l_recovery_ctx *ctx)
{
struct mddev *mddev = log->rdev->mddev;
struct r5conf *conf = mddev->private;
struct r5l_meta_block *mb = page_address(ctx->meta_page);
sector_t mb_offset = sizeof(struct r5l_meta_block);
sector_t log_offset = r5l_ring_add(log, ctx->pos, BLOCK_SECTORS);
struct page *page;
struct r5l_payload_data_parity *payload;
page = alloc_page(GFP_KERNEL);
if (!page)
return -ENOMEM;
while (mb_offset < le32_to_cpu(mb->meta_size)) {
payload = (void *)mb + mb_offset;
if (payload->header.type == R5LOG_PAYLOAD_DATA) {
if (r5l_recovery_verify_data_checksum(
log, page, log_offset,
payload->checksum[0]) < 0)
goto mismatch;
} else if (payload->header.type == R5LOG_PAYLOAD_PARITY) {
if (r5l_recovery_verify_data_checksum(
log, page, log_offset,
payload->checksum[0]) < 0)
goto mismatch;
if (conf->max_degraded == 2 &&
r5l_recovery_verify_data_checksum(
log, page,
r5l_ring_add(log, log_offset,
BLOCK_SECTORS),
payload->checksum[1]) < 0)
goto mismatch;
} else
goto mismatch;
log_offset = r5l_ring_add(log, log_offset,
le32_to_cpu(payload->size));
mb_offset += sizeof(struct r5l_payload_data_parity) +
sizeof(__le32) *
(le32_to_cpu(payload->size) >> (PAGE_SHIFT - 9));
}
put_page(page);
return 0;
mismatch:
put_page(page);
return -EINVAL;
}
static int
r5c_recovery_analyze_meta_block(struct r5l_log *log,
struct r5l_recovery_ctx *ctx,
struct list_head *cached_stripe_list)
{
struct mddev *mddev = log->rdev->mddev;
struct r5conf *conf = mddev->private;
struct r5l_meta_block *mb;
struct r5l_payload_data_parity *payload;
int mb_offset;
sector_t log_offset;
sector_t stripe_sect;
struct stripe_head *sh;
int ret;
ret = r5l_recovery_verify_data_checksum_for_mb(log, ctx);
if (ret == -EINVAL)
return -EAGAIN;
else if (ret)
return ret;
mb = page_address(ctx->meta_page);
mb_offset = sizeof(struct r5l_meta_block);
log_offset = r5l_ring_add(log, ctx->pos, BLOCK_SECTORS);
while (mb_offset < le32_to_cpu(mb->meta_size)) {
int dd;
payload = (void *)mb + mb_offset;
stripe_sect = (payload->header.type == R5LOG_PAYLOAD_DATA) ?
raid5_compute_sector(
conf, le64_to_cpu(payload->location), 0, &dd,
NULL)
: le64_to_cpu(payload->location);
sh = r5c_recovery_lookup_stripe(cached_stripe_list,
stripe_sect);
if (!sh) {
sh = r5c_recovery_alloc_stripe(conf, stripe_sect);
if (!sh) {
r5c_recovery_replay_stripes(
cached_stripe_list, ctx);
sh = r5c_recovery_alloc_stripe(
conf, stripe_sect);
}
if (!sh) {
pr_debug("md/raid:%s: Increasing stripe cache size to %d to recovery data on journal.\n",
mdname(mddev),
conf->min_nr_stripes * 2);
raid5_set_cache_size(mddev,
conf->min_nr_stripes * 2);
sh = r5c_recovery_alloc_stripe(conf,
stripe_sect);
}
if (!sh) {
pr_err("md/raid:%s: Cannot get enough stripes due to memory pressure. Recovery failed.\n",
mdname(mddev));
return -ENOMEM;
}
list_add_tail(&sh->lru, cached_stripe_list);
}
if (payload->header.type == R5LOG_PAYLOAD_DATA) {
if (!test_bit(STRIPE_R5C_CACHING, &sh->state) &&
test_bit(R5_Wantwrite, &sh->dev[sh->pd_idx].flags)) {
r5l_recovery_replay_one_stripe(conf, sh, ctx);
list_move_tail(&sh->lru, cached_stripe_list);
}
r5l_recovery_load_data(log, sh, ctx, payload,
log_offset);
} else if (payload->header.type == R5LOG_PAYLOAD_PARITY)
r5l_recovery_load_parity(log, sh, ctx, payload,
log_offset);
else
return -EINVAL;
log_offset = r5l_ring_add(log, log_offset,
le32_to_cpu(payload->size));
mb_offset += sizeof(struct r5l_payload_data_parity) +
sizeof(__le32) *
(le32_to_cpu(payload->size) >> (PAGE_SHIFT - 9));
}
return 0;
}
static void r5c_recovery_load_one_stripe(struct r5l_log *log,
struct stripe_head *sh)
{
struct r5dev *dev;
int i;
for (i = sh->disks; i--; ) {
dev = sh->dev + i;
if (test_and_clear_bit(R5_Wantwrite, &dev->flags)) {
set_bit(R5_InJournal, &dev->flags);
set_bit(R5_UPTODATE, &dev->flags);
}
}
}
static int r5c_recovery_flush_log(struct r5l_log *log,
struct r5l_recovery_ctx *ctx)
{
struct stripe_head *sh;
int ret = 0;
while (1) {
if (r5l_recovery_read_meta_block(log, ctx))
break;
ret = r5c_recovery_analyze_meta_block(log, ctx,
&ctx->cached_list);
if (ret && ret != -EAGAIN)
break;
ctx->seq++;
ctx->pos = r5l_ring_add(log, ctx->pos, ctx->meta_total_blocks);
}
if (ret == -ENOMEM) {
r5c_recovery_drop_stripes(&ctx->cached_list, ctx);
return ret;
}
r5c_recovery_replay_stripes(&ctx->cached_list, ctx);
list_for_each_entry(sh, &ctx->cached_list, lru) {
WARN_ON(!test_bit(STRIPE_R5C_CACHING, &sh->state));
r5c_recovery_load_one_stripe(log, sh);
ctx->data_only_stripes++;
}
return 0;
}
static int
r5c_recovery_rewrite_data_only_stripes(struct r5l_log *log,
struct r5l_recovery_ctx *ctx)
{
struct stripe_head *sh;
struct mddev *mddev = log->rdev->mddev;
struct page *page;
sector_t next_checkpoint = MaxSector;
page = alloc_page(GFP_KERNEL);
if (!page) {
pr_err("md/raid:%s: cannot allocate memory to rewrite data only stripes\n",
mdname(mddev));
return -ENOMEM;
}
WARN_ON(list_empty(&ctx->cached_list));
list_for_each_entry(sh, &ctx->cached_list, lru) {
struct r5l_meta_block *mb;
int i;
int offset;
sector_t write_pos;
WARN_ON(!test_bit(STRIPE_R5C_CACHING, &sh->state));
r5l_recovery_create_empty_meta_block(log, page,
ctx->pos, ctx->seq);
mb = page_address(page);
offset = le32_to_cpu(mb->meta_size);
write_pos = r5l_ring_add(log, ctx->pos, BLOCK_SECTORS);
for (i = sh->disks; i--; ) {
struct r5dev *dev = &sh->dev[i];
struct r5l_payload_data_parity *payload;
void *addr;
if (test_bit(R5_InJournal, &dev->flags)) {
payload = (void *)mb + offset;
payload->header.type = cpu_to_le16(
R5LOG_PAYLOAD_DATA);
payload->size = BLOCK_SECTORS;
payload->location = cpu_to_le64(
raid5_compute_blocknr(sh, i, 0));
addr = kmap_atomic(dev->page);
payload->checksum[0] = cpu_to_le32(
crc32c_le(log->uuid_checksum, addr,
PAGE_SIZE));
kunmap_atomic(addr);
sync_page_io(log->rdev, write_pos, PAGE_SIZE,
dev->page, REQ_OP_WRITE, 0, false);
write_pos = r5l_ring_add(log, write_pos,
BLOCK_SECTORS);
offset += sizeof(__le32) +
sizeof(struct r5l_payload_data_parity);
}
}
mb->meta_size = cpu_to_le32(offset);
mb->checksum = cpu_to_le32(crc32c_le(log->uuid_checksum,
mb, PAGE_SIZE));
sync_page_io(log->rdev, ctx->pos, PAGE_SIZE, page,
REQ_OP_WRITE, REQ_FUA, false);
sh->log_start = ctx->pos;
list_add_tail(&sh->r5c, &log->stripe_in_journal_list);
atomic_inc(&log->stripe_in_journal_count);
ctx->pos = write_pos;
ctx->seq += 1;
next_checkpoint = sh->log_start;
}
log->next_checkpoint = next_checkpoint;
__free_page(page);
return 0;
}
static void r5c_recovery_flush_data_only_stripes(struct r5l_log *log,
struct r5l_recovery_ctx *ctx)
{
struct mddev *mddev = log->rdev->mddev;
struct r5conf *conf = mddev->private;
struct stripe_head *sh, *next;
if (ctx->data_only_stripes == 0)
return;
log->r5c_journal_mode = R5C_JOURNAL_MODE_WRITE_BACK;
list_for_each_entry_safe(sh, next, &ctx->cached_list, lru) {
r5c_make_stripe_write_out(sh);
set_bit(STRIPE_HANDLE, &sh->state);
list_del_init(&sh->lru);
raid5_release_stripe(sh);
}
md_wakeup_thread(conf->mddev->thread);
wait_event(conf->wait_for_quiescent,
atomic_read(&conf->active_stripes) == 0);
log->r5c_journal_mode = R5C_JOURNAL_MODE_WRITE_THROUGH;
}
static int r5l_recovery_log(struct r5l_log *log)
{
struct mddev *mddev = log->rdev->mddev;
struct r5l_recovery_ctx ctx;
int ret;
sector_t pos;
ctx.pos = log->last_checkpoint;
ctx.seq = log->last_cp_seq;
ctx.meta_page = alloc_page(GFP_KERNEL);
ctx.data_only_stripes = 0;
ctx.data_parity_stripes = 0;
INIT_LIST_HEAD(&ctx.cached_list);
if (!ctx.meta_page)
return -ENOMEM;
ret = r5c_recovery_flush_log(log, &ctx);
__free_page(ctx.meta_page);
if (ret)
return ret;
pos = ctx.pos;
ctx.seq += 10000;
if ((ctx.data_only_stripes == 0) && (ctx.data_parity_stripes == 0))
pr_debug("md/raid:%s: starting from clean shutdown\n",
mdname(mddev));
else
pr_debug("md/raid:%s: recovering %d data-only stripes and %d data-parity stripes\n",
mdname(mddev), ctx.data_only_stripes,
ctx.data_parity_stripes);
if (ctx.data_only_stripes == 0) {
log->next_checkpoint = ctx.pos;
r5l_log_write_empty_meta_block(log, ctx.pos, ctx.seq++);
ctx.pos = r5l_ring_add(log, ctx.pos, BLOCK_SECTORS);
} else if (r5c_recovery_rewrite_data_only_stripes(log, &ctx)) {
pr_err("md/raid:%s: failed to rewrite stripes to journal\n",
mdname(mddev));
return -EIO;
}
log->log_start = ctx.pos;
log->seq = ctx.seq;
log->last_checkpoint = pos;
r5l_write_super(log, pos);
r5c_recovery_flush_data_only_stripes(log, &ctx);
return 0;
}
static void r5l_write_super(struct r5l_log *log, sector_t cp)
{
struct mddev *mddev = log->rdev->mddev;
log->rdev->journal_tail = cp;
set_bit(MD_SB_CHANGE_DEVS, &mddev->sb_flags);
}
static ssize_t r5c_journal_mode_show(struct mddev *mddev, char *page)
{
struct r5conf *conf = mddev->private;
int ret;
if (!conf->log)
return 0;
switch (conf->log->r5c_journal_mode) {
case R5C_JOURNAL_MODE_WRITE_THROUGH:
ret = snprintf(
page, PAGE_SIZE, "[%s] %s\n",
r5c_journal_mode_str[R5C_JOURNAL_MODE_WRITE_THROUGH],
r5c_journal_mode_str[R5C_JOURNAL_MODE_WRITE_BACK]);
break;
case R5C_JOURNAL_MODE_WRITE_BACK:
ret = snprintf(
page, PAGE_SIZE, "%s [%s]\n",
r5c_journal_mode_str[R5C_JOURNAL_MODE_WRITE_THROUGH],
r5c_journal_mode_str[R5C_JOURNAL_MODE_WRITE_BACK]);
break;
default:
ret = 0;
}
return ret;
}
static ssize_t r5c_journal_mode_store(struct mddev *mddev,
const char *page, size_t length)
{
struct r5conf *conf = mddev->private;
struct r5l_log *log = conf->log;
int val = -1, i;
int len = length;
if (!log)
return -ENODEV;
if (len && page[len - 1] == '\n')
len -= 1;
for (i = 0; i < ARRAY_SIZE(r5c_journal_mode_str); i++)
if (strlen(r5c_journal_mode_str[i]) == len &&
strncmp(page, r5c_journal_mode_str[i], len) == 0) {
val = i;
break;
}
if (val < R5C_JOURNAL_MODE_WRITE_THROUGH ||
val > R5C_JOURNAL_MODE_WRITE_BACK)
return -EINVAL;
if (raid5_calc_degraded(conf) > 0 &&
val == R5C_JOURNAL_MODE_WRITE_BACK)
return -EINVAL;
mddev_suspend(mddev);
conf->log->r5c_journal_mode = val;
mddev_resume(mddev);
pr_debug("md/raid:%s: setting r5c cache mode to %d: %s\n",
mdname(mddev), val, r5c_journal_mode_str[val]);
return length;
}
int r5c_try_caching_write(struct r5conf *conf,
struct stripe_head *sh,
struct stripe_head_state *s,
int disks)
{
struct r5l_log *log = conf->log;
int i;
struct r5dev *dev;
int to_cache = 0;
BUG_ON(!r5c_is_writeback(log));
if (!test_bit(STRIPE_R5C_CACHING, &sh->state)) {
if (s->injournal > 0 || s->written > 0)
return -EAGAIN;
set_bit(STRIPE_R5C_CACHING, &sh->state);
}
if (s->failed) {
r5c_make_stripe_write_out(sh);
return -EAGAIN;
}
for (i = disks; i--; ) {
dev = &sh->dev[i];
if (dev->towrite && !test_bit(R5_OVERWRITE, &dev->flags) &&
!test_bit(R5_InJournal, &dev->flags)) {
r5c_make_stripe_write_out(sh);
return -EAGAIN;
}
}
for (i = disks; i--; ) {
dev = &sh->dev[i];
if (dev->towrite) {
set_bit(R5_Wantwrite, &dev->flags);
set_bit(R5_Wantdrain, &dev->flags);
set_bit(R5_LOCKED, &dev->flags);
to_cache++;
}
}
if (to_cache) {
set_bit(STRIPE_OP_BIODRAIN, &s->ops_request);
set_bit(STRIPE_LOG_TRAPPED, &sh->state);
}
return 0;
}
void r5c_release_extra_page(struct stripe_head *sh)
{
struct r5conf *conf = sh->raid_conf;
int i;
bool using_disk_info_extra_page;
using_disk_info_extra_page =
sh->dev[0].orig_page == conf->disks[0].extra_page;
for (i = sh->disks; i--; )
if (sh->dev[i].page != sh->dev[i].orig_page) {
struct page *p = sh->dev[i].orig_page;
sh->dev[i].orig_page = sh->dev[i].page;
clear_bit(R5_OrigPageUPTDODATE, &sh->dev[i].flags);
if (!using_disk_info_extra_page)
put_page(p);
}
if (using_disk_info_extra_page) {
clear_bit(R5C_EXTRA_PAGE_IN_USE, &conf->cache_state);
md_wakeup_thread(conf->mddev->thread);
}
}
void r5c_use_extra_page(struct stripe_head *sh)
{
struct r5conf *conf = sh->raid_conf;
int i;
struct r5dev *dev;
for (i = sh->disks; i--; ) {
dev = &sh->dev[i];
if (dev->orig_page != dev->page)
put_page(dev->orig_page);
dev->orig_page = conf->disks[i].extra_page;
}
}
void r5c_finish_stripe_write_out(struct r5conf *conf,
struct stripe_head *sh,
struct stripe_head_state *s)
{
int i;
int do_wakeup = 0;
if (!conf->log ||
!test_bit(R5_InJournal, &sh->dev[sh->pd_idx].flags))
return;
WARN_ON(test_bit(STRIPE_R5C_CACHING, &sh->state));
clear_bit(R5_InJournal, &sh->dev[sh->pd_idx].flags);
if (conf->log->r5c_journal_mode == R5C_JOURNAL_MODE_WRITE_THROUGH)
return;
for (i = sh->disks; i--; ) {
clear_bit(R5_InJournal, &sh->dev[i].flags);
if (test_and_clear_bit(R5_Overlap, &sh->dev[i].flags))
do_wakeup = 1;
}
s->injournal = 0;
if (test_and_clear_bit(STRIPE_FULL_WRITE, &sh->state))
if (atomic_dec_and_test(&conf->pending_full_writes))
md_wakeup_thread(conf->mddev->thread);
if (do_wakeup)
wake_up(&conf->wait_for_overlap);
spin_lock_irq(&conf->log->stripe_in_journal_lock);
list_del_init(&sh->r5c);
spin_unlock_irq(&conf->log->stripe_in_journal_lock);
sh->log_start = MaxSector;
atomic_dec(&conf->log->stripe_in_journal_count);
r5c_update_log_state(conf->log);
}
int
r5c_cache_data(struct r5l_log *log, struct stripe_head *sh,
struct stripe_head_state *s)
{
struct r5conf *conf = sh->raid_conf;
int pages = 0;
int reserve;
int i;
int ret = 0;
BUG_ON(!log);
for (i = 0; i < sh->disks; i++) {
void *addr;
if (!test_bit(R5_Wantwrite, &sh->dev[i].flags))
continue;
addr = kmap_atomic(sh->dev[i].page);
sh->dev[i].log_checksum = crc32c_le(log->uuid_checksum,
addr, PAGE_SIZE);
kunmap_atomic(addr);
pages++;
}
WARN_ON(pages == 0);
clear_bit(STRIPE_DELAYED, &sh->state);
atomic_inc(&sh->count);
mutex_lock(&log->io_mutex);
reserve = (1 + pages) << (PAGE_SHIFT - 9);
if (test_bit(R5C_LOG_CRITICAL, &conf->cache_state) &&
sh->log_start == MaxSector)
r5l_add_no_space_stripe(log, sh);
else if (!r5l_has_free_space(log, reserve)) {
if (sh->log_start == log->last_checkpoint)
BUG();
else
r5l_add_no_space_stripe(log, sh);
} else {
ret = r5l_log_stripe(log, sh, pages, 0);
if (ret) {
spin_lock_irq(&log->io_list_lock);
list_add_tail(&sh->log_list, &log->no_mem_stripes);
spin_unlock_irq(&log->io_list_lock);
}
}
mutex_unlock(&log->io_mutex);
return 0;
}
static int r5l_load_log(struct r5l_log *log)
{
struct md_rdev *rdev = log->rdev;
struct page *page;
struct r5l_meta_block *mb;
sector_t cp = log->rdev->journal_tail;
u32 stored_crc, expected_crc;
bool create_super = false;
int ret = 0;
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
__free_page(page);
if (create_super) {
log->log_start = r5l_ring_add(log, cp, BLOCK_SECTORS);
log->seq = log->last_cp_seq + 1;
log->next_checkpoint = cp;
} else
ret = r5l_recovery_log(log);
r5c_update_log_state(log);
return ret;
ioerr:
__free_page(page);
return ret;
}
void r5c_update_on_rdev_error(struct mddev *mddev)
{
struct r5conf *conf = mddev->private;
struct r5l_log *log = conf->log;
if (!log)
return;
if (raid5_calc_degraded(conf) > 0 &&
conf->log->r5c_journal_mode == R5C_JOURNAL_MODE_WRITE_BACK)
schedule_work(&log->disable_writeback_work);
}
int r5l_init_log(struct r5conf *conf, struct md_rdev *rdev)
{
struct request_queue *q = bdev_get_queue(rdev->bdev);
struct r5l_log *log;
if (PAGE_SIZE != 4096)
return -EINVAL;
if (sizeof(struct r5l_meta_block) +
((sizeof(struct r5l_payload_data_parity) + sizeof(__le32)) *
conf->raid_disks) > PAGE_SIZE) {
pr_err("md/raid:%s: write journal/cache doesn't work for array with %d disks\n",
mdname(conf->mddev), conf->raid_disks);
return -EINVAL;
}
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
bio_init(&log->flush_bio, NULL, 0);
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
log->reclaim_thread->timeout = R5C_RECLAIM_WAKEUP_INTERVAL;
init_waitqueue_head(&log->iounit_wait);
INIT_LIST_HEAD(&log->no_mem_stripes);
INIT_LIST_HEAD(&log->no_space_stripes);
spin_lock_init(&log->no_space_stripes_lock);
INIT_WORK(&log->deferred_io_work, r5l_submit_io_async);
INIT_WORK(&log->disable_writeback_work, r5c_disable_writeback_async);
log->r5c_journal_mode = R5C_JOURNAL_MODE_WRITE_THROUGH;
INIT_LIST_HEAD(&log->stripe_in_journal_list);
spin_lock_init(&log->stripe_in_journal_lock);
atomic_set(&log->stripe_in_journal_count, 0);
rcu_assign_pointer(conf->log, log);
if (r5l_load_log(log))
goto error;
set_bit(MD_HAS_JOURNAL, &conf->mddev->flags);
return 0;
error:
rcu_assign_pointer(conf->log, NULL);
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
flush_work(&log->disable_writeback_work);
md_unregister_thread(&log->reclaim_thread);
mempool_destroy(log->meta_pool);
bioset_free(log->bs);
mempool_destroy(log->io_pool);
kmem_cache_destroy(log->io_kc);
kfree(log);
}
