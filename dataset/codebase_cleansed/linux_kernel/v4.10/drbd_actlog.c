void *drbd_md_get_buffer(struct drbd_device *device, const char *intent)
{
int r;
wait_event(device->misc_wait,
(r = atomic_cmpxchg(&device->md_io.in_use, 0, 1)) == 0 ||
device->state.disk <= D_FAILED);
if (r)
return NULL;
device->md_io.current_use = intent;
device->md_io.start_jif = jiffies;
device->md_io.submit_jif = device->md_io.start_jif - 1;
return page_address(device->md_io.page);
}
void drbd_md_put_buffer(struct drbd_device *device)
{
if (atomic_dec_and_test(&device->md_io.in_use))
wake_up(&device->misc_wait);
}
void wait_until_done_or_force_detached(struct drbd_device *device, struct drbd_backing_dev *bdev,
unsigned int *done)
{
long dt;
rcu_read_lock();
dt = rcu_dereference(bdev->disk_conf)->disk_timeout;
rcu_read_unlock();
dt = dt * HZ / 10;
if (dt == 0)
dt = MAX_SCHEDULE_TIMEOUT;
dt = wait_event_timeout(device->misc_wait,
*done || test_bit(FORCE_DETACH, &device->flags), dt);
if (dt == 0) {
drbd_err(device, "meta-data IO operation timed out\n");
drbd_chk_io_error(device, 1, DRBD_FORCE_DETACH);
}
}
static int _drbd_md_sync_page_io(struct drbd_device *device,
struct drbd_backing_dev *bdev,
sector_t sector, int op)
{
struct bio *bio;
const int size = 4096;
int err, op_flags = 0;
device->md_io.done = 0;
device->md_io.error = -ENODEV;
if ((op == REQ_OP_WRITE) && !test_bit(MD_NO_FUA, &device->flags))
op_flags |= REQ_FUA | REQ_PREFLUSH;
op_flags |= REQ_SYNC;
bio = bio_alloc_drbd(GFP_NOIO);
bio->bi_bdev = bdev->md_bdev;
bio->bi_iter.bi_sector = sector;
err = -EIO;
if (bio_add_page(bio, device->md_io.page, size, 0) != size)
goto out;
bio->bi_private = device;
bio->bi_end_io = drbd_md_endio;
bio_set_op_attrs(bio, op, op_flags);
if (op != REQ_OP_WRITE && device->state.disk == D_DISKLESS && device->ldev == NULL)
;
else if (!get_ldev_if_state(device, D_ATTACHING)) {
drbd_err(device, "ASSERT FAILED: get_ldev_if_state() == 1 in _drbd_md_sync_page_io()\n");
err = -ENODEV;
goto out;
}
bio_get(bio);
atomic_inc(&device->md_io.in_use);
device->md_io.submit_jif = jiffies;
if (drbd_insert_fault(device, (op == REQ_OP_WRITE) ? DRBD_FAULT_MD_WR : DRBD_FAULT_MD_RD))
bio_io_error(bio);
else
submit_bio(bio);
wait_until_done_or_force_detached(device, bdev, &device->md_io.done);
if (!bio->bi_error)
err = device->md_io.error;
out:
bio_put(bio);
return err;
}
int drbd_md_sync_page_io(struct drbd_device *device, struct drbd_backing_dev *bdev,
sector_t sector, int op)
{
int err;
D_ASSERT(device, atomic_read(&device->md_io.in_use) == 1);
BUG_ON(!bdev->md_bdev);
dynamic_drbd_dbg(device, "meta_data io: %s [%d]:%s(,%llus,%s) %pS\n",
current->comm, current->pid, __func__,
(unsigned long long)sector, (op == REQ_OP_WRITE) ? "WRITE" : "READ",
(void*)_RET_IP_ );
if (sector < drbd_md_first_sector(bdev) ||
sector + 7 > drbd_md_last_sector(bdev))
drbd_alert(device, "%s [%d]:%s(,%llus,%s) out of range md access!\n",
current->comm, current->pid, __func__,
(unsigned long long)sector,
(op == REQ_OP_WRITE) ? "WRITE" : "READ");
err = _drbd_md_sync_page_io(device, bdev, sector, op);
if (err) {
drbd_err(device, "drbd_md_sync_page_io(,%llus,%s) failed with error %d\n",
(unsigned long long)sector,
(op == REQ_OP_WRITE) ? "WRITE" : "READ", err);
}
return err;
}
static struct bm_extent *find_active_resync_extent(struct drbd_device *device, unsigned int enr)
{
struct lc_element *tmp;
tmp = lc_find(device->resync, enr/AL_EXT_PER_BM_SECT);
if (unlikely(tmp != NULL)) {
struct bm_extent *bm_ext = lc_entry(tmp, struct bm_extent, lce);
if (test_bit(BME_NO_WRITES, &bm_ext->flags))
return bm_ext;
}
return NULL;
}
static struct lc_element *_al_get(struct drbd_device *device, unsigned int enr, bool nonblock)
{
struct lc_element *al_ext;
struct bm_extent *bm_ext;
int wake;
spin_lock_irq(&device->al_lock);
bm_ext = find_active_resync_extent(device, enr);
if (bm_ext) {
wake = !test_and_set_bit(BME_PRIORITY, &bm_ext->flags);
spin_unlock_irq(&device->al_lock);
if (wake)
wake_up(&device->al_wait);
return NULL;
}
if (nonblock)
al_ext = lc_try_get(device->act_log, enr);
else
al_ext = lc_get(device->act_log, enr);
spin_unlock_irq(&device->al_lock);
return al_ext;
}
bool drbd_al_begin_io_fastpath(struct drbd_device *device, struct drbd_interval *i)
{
unsigned first = i->sector >> (AL_EXTENT_SHIFT-9);
unsigned last = i->size == 0 ? first : (i->sector + (i->size >> 9) - 1) >> (AL_EXTENT_SHIFT-9);
D_ASSERT(device, first <= last);
D_ASSERT(device, atomic_read(&device->local_cnt) > 0);
if (first != last)
return false;
return _al_get(device, first, true);
}
bool drbd_al_begin_io_prepare(struct drbd_device *device, struct drbd_interval *i)
{
unsigned first = i->sector >> (AL_EXTENT_SHIFT-9);
unsigned last = i->size == 0 ? first : (i->sector + (i->size >> 9) - 1) >> (AL_EXTENT_SHIFT-9);
unsigned enr;
bool need_transaction = false;
D_ASSERT(device, first <= last);
D_ASSERT(device, atomic_read(&device->local_cnt) > 0);
for (enr = first; enr <= last; enr++) {
struct lc_element *al_ext;
wait_event(device->al_wait,
(al_ext = _al_get(device, enr, false)) != NULL);
if (al_ext->lc_number != enr)
need_transaction = true;
}
return need_transaction;
}
static unsigned int al_extent_to_bm_page(unsigned int al_enr)
{
return al_enr >>
((PAGE_SHIFT + 3) -
(AL_EXTENT_SHIFT - BM_BLOCK_SHIFT));
}
static sector_t al_tr_number_to_on_disk_sector(struct drbd_device *device)
{
const unsigned int stripes = device->ldev->md.al_stripes;
const unsigned int stripe_size_4kB = device->ldev->md.al_stripe_size_4k;
unsigned int t = device->al_tr_number % (device->ldev->md.al_size_4k);
t = ((t % stripes) * stripe_size_4kB) + t/stripes;
t *= 8;
return device->ldev->md.md_offset + device->ldev->md.al_offset + t;
}
static int __al_write_transaction(struct drbd_device *device, struct al_transaction_on_disk *buffer)
{
struct lc_element *e;
sector_t sector;
int i, mx;
unsigned extent_nr;
unsigned crc = 0;
int err = 0;
memset(buffer, 0, sizeof(*buffer));
buffer->magic = cpu_to_be32(DRBD_AL_MAGIC);
buffer->tr_number = cpu_to_be32(device->al_tr_number);
i = 0;
drbd_bm_reset_al_hints(device);
spin_lock_irq(&device->al_lock);
list_for_each_entry(e, &device->act_log->to_be_changed, list) {
if (i == AL_UPDATES_PER_TRANSACTION) {
i++;
break;
}
buffer->update_slot_nr[i] = cpu_to_be16(e->lc_index);
buffer->update_extent_nr[i] = cpu_to_be32(e->lc_new_number);
if (e->lc_number != LC_FREE)
drbd_bm_mark_for_writeout(device,
al_extent_to_bm_page(e->lc_number));
i++;
}
spin_unlock_irq(&device->al_lock);
BUG_ON(i > AL_UPDATES_PER_TRANSACTION);
buffer->n_updates = cpu_to_be16(i);
for ( ; i < AL_UPDATES_PER_TRANSACTION; i++) {
buffer->update_slot_nr[i] = cpu_to_be16(-1);
buffer->update_extent_nr[i] = cpu_to_be32(LC_FREE);
}
buffer->context_size = cpu_to_be16(device->act_log->nr_elements);
buffer->context_start_slot_nr = cpu_to_be16(device->al_tr_cycle);
mx = min_t(int, AL_CONTEXT_PER_TRANSACTION,
device->act_log->nr_elements - device->al_tr_cycle);
for (i = 0; i < mx; i++) {
unsigned idx = device->al_tr_cycle + i;
extent_nr = lc_element_by_index(device->act_log, idx)->lc_number;
buffer->context[i] = cpu_to_be32(extent_nr);
}
for (; i < AL_CONTEXT_PER_TRANSACTION; i++)
buffer->context[i] = cpu_to_be32(LC_FREE);
device->al_tr_cycle += AL_CONTEXT_PER_TRANSACTION;
if (device->al_tr_cycle >= device->act_log->nr_elements)
device->al_tr_cycle = 0;
sector = al_tr_number_to_on_disk_sector(device);
crc = crc32c(0, buffer, 4096);
buffer->crc32c = cpu_to_be32(crc);
if (drbd_bm_write_hinted(device))
err = -EIO;
else {
bool write_al_updates;
rcu_read_lock();
write_al_updates = rcu_dereference(device->ldev->disk_conf)->al_updates;
rcu_read_unlock();
if (write_al_updates) {
if (drbd_md_sync_page_io(device, device->ldev, sector, WRITE)) {
err = -EIO;
drbd_chk_io_error(device, 1, DRBD_META_IO_ERROR);
} else {
device->al_tr_number++;
device->al_writ_cnt++;
}
}
}
return err;
}
static int al_write_transaction(struct drbd_device *device)
{
struct al_transaction_on_disk *buffer;
int err;
if (!get_ldev(device)) {
drbd_err(device, "disk is %s, cannot start al transaction\n",
drbd_disk_str(device->state.disk));
return -EIO;
}
if (device->state.disk < D_INCONSISTENT) {
drbd_err(device,
"disk is %s, cannot write al transaction\n",
drbd_disk_str(device->state.disk));
put_ldev(device);
return -EIO;
}
buffer = drbd_md_get_buffer(device, __func__);
if (!buffer) {
drbd_err(device, "disk failed while waiting for md_io buffer\n");
put_ldev(device);
return -ENODEV;
}
err = __al_write_transaction(device, buffer);
drbd_md_put_buffer(device);
put_ldev(device);
return err;
}
void drbd_al_begin_io_commit(struct drbd_device *device)
{
bool locked = false;
wait_event(device->al_wait,
device->act_log->pending_changes == 0 ||
(locked = lc_try_lock_for_transaction(device->act_log)));
if (locked) {
if (device->act_log->pending_changes) {
bool write_al_updates;
rcu_read_lock();
write_al_updates = rcu_dereference(device->ldev->disk_conf)->al_updates;
rcu_read_unlock();
if (write_al_updates)
al_write_transaction(device);
spin_lock_irq(&device->al_lock);
lc_committed(device->act_log);
spin_unlock_irq(&device->al_lock);
}
lc_unlock(device->act_log);
wake_up(&device->al_wait);
}
}
void drbd_al_begin_io(struct drbd_device *device, struct drbd_interval *i)
{
if (drbd_al_begin_io_prepare(device, i))
drbd_al_begin_io_commit(device);
}
int drbd_al_begin_io_nonblock(struct drbd_device *device, struct drbd_interval *i)
{
struct lru_cache *al = device->act_log;
unsigned first = i->sector >> (AL_EXTENT_SHIFT-9);
unsigned last = i->size == 0 ? first : (i->sector + (i->size >> 9) - 1) >> (AL_EXTENT_SHIFT-9);
unsigned nr_al_extents;
unsigned available_update_slots;
unsigned enr;
D_ASSERT(device, first <= last);
nr_al_extents = 1 + last - first;
available_update_slots = min(al->nr_elements - al->used,
al->max_pending_changes - al->pending_changes);
if (available_update_slots < nr_al_extents) {
if (!al->pending_changes)
__set_bit(__LC_STARVING, &device->act_log->flags);
return -ENOBUFS;
}
for (enr = first; enr <= last; enr++) {
struct lc_element *tmp;
tmp = lc_find(device->resync, enr/AL_EXT_PER_BM_SECT);
if (unlikely(tmp != NULL)) {
struct bm_extent *bm_ext = lc_entry(tmp, struct bm_extent, lce);
if (test_bit(BME_NO_WRITES, &bm_ext->flags)) {
if (!test_and_set_bit(BME_PRIORITY, &bm_ext->flags))
return -EBUSY;
return -EWOULDBLOCK;
}
}
}
for (enr = first; enr <= last; enr++) {
struct lc_element *al_ext;
al_ext = lc_get_cumulative(device->act_log, enr);
if (!al_ext)
drbd_info(device, "LOGIC BUG for enr=%u\n", enr);
}
return 0;
}
void drbd_al_complete_io(struct drbd_device *device, struct drbd_interval *i)
{
unsigned first = i->sector >> (AL_EXTENT_SHIFT-9);
unsigned last = i->size == 0 ? first : (i->sector + (i->size >> 9) - 1) >> (AL_EXTENT_SHIFT-9);
unsigned enr;
struct lc_element *extent;
unsigned long flags;
D_ASSERT(device, first <= last);
spin_lock_irqsave(&device->al_lock, flags);
for (enr = first; enr <= last; enr++) {
extent = lc_find(device->act_log, enr);
if (!extent) {
drbd_err(device, "al_complete_io() called on inactive extent %u\n", enr);
continue;
}
lc_put(device->act_log, extent);
}
spin_unlock_irqrestore(&device->al_lock, flags);
wake_up(&device->al_wait);
}
static int _try_lc_del(struct drbd_device *device, struct lc_element *al_ext)
{
int rv;
spin_lock_irq(&device->al_lock);
rv = (al_ext->refcnt == 0);
if (likely(rv))
lc_del(device->act_log, al_ext);
spin_unlock_irq(&device->al_lock);
return rv;
}
void drbd_al_shrink(struct drbd_device *device)
{
struct lc_element *al_ext;
int i;
D_ASSERT(device, test_bit(__LC_LOCKED, &device->act_log->flags));
for (i = 0; i < device->act_log->nr_elements; i++) {
al_ext = lc_element_by_index(device->act_log, i);
if (al_ext->lc_number == LC_FREE)
continue;
wait_event(device->al_wait, _try_lc_del(device, al_ext));
}
wake_up(&device->al_wait);
}
int drbd_al_initialize(struct drbd_device *device, void *buffer)
{
struct al_transaction_on_disk *al = buffer;
struct drbd_md *md = &device->ldev->md;
int al_size_4k = md->al_stripes * md->al_stripe_size_4k;
int i;
__al_write_transaction(device, al);
spin_lock_irq(&device->al_lock);
lc_committed(device->act_log);
spin_unlock_irq(&device->al_lock);
for (i = 1; i < al_size_4k; i++) {
int err = __al_write_transaction(device, al);
if (err)
return err;
}
return 0;
}
static bool update_rs_extent(struct drbd_device *device,
unsigned int enr, int count,
enum update_sync_bits_mode mode)
{
struct lc_element *e;
D_ASSERT(device, atomic_read(&device->local_cnt));
if (mode == SET_OUT_OF_SYNC)
e = lc_find(device->resync, enr);
else
e = lc_get(device->resync, enr);
if (e) {
struct bm_extent *ext = lc_entry(e, struct bm_extent, lce);
if (ext->lce.lc_number == enr) {
if (mode == SET_IN_SYNC)
ext->rs_left -= count;
else if (mode == SET_OUT_OF_SYNC)
ext->rs_left += count;
else
ext->rs_failed += count;
if (ext->rs_left < ext->rs_failed) {
drbd_warn(device, "BAD! enr=%u rs_left=%d "
"rs_failed=%d count=%d cstate=%s\n",
ext->lce.lc_number, ext->rs_left,
ext->rs_failed, count,
drbd_conn_str(device->state.conn));
ext->rs_left = drbd_bm_e_weight(device, enr);
}
} else {
int rs_left = drbd_bm_e_weight(device, enr);
if (ext->flags != 0) {
drbd_warn(device, "changing resync lce: %d[%u;%02lx]"
" -> %d[%u;00]\n",
ext->lce.lc_number, ext->rs_left,
ext->flags, enr, rs_left);
ext->flags = 0;
}
if (ext->rs_failed) {
drbd_warn(device, "Kicking resync_lru element enr=%u "
"out with rs_failed=%d\n",
ext->lce.lc_number, ext->rs_failed);
}
ext->rs_left = rs_left;
ext->rs_failed = (mode == RECORD_RS_FAILED) ? count : 0;
lc_committed(device->resync);
}
if (mode != SET_OUT_OF_SYNC)
lc_put(device->resync, &ext->lce);
if (ext->rs_left <= ext->rs_failed) {
ext->rs_failed = 0;
return true;
}
} else if (mode != SET_OUT_OF_SYNC) {
drbd_err(device, "lc_get() failed! locked=%d/%d flags=%lu\n",
device->resync_locked,
device->resync->nr_elements,
device->resync->flags);
}
return false;
}
void drbd_advance_rs_marks(struct drbd_device *device, unsigned long still_to_go)
{
unsigned long now = jiffies;
unsigned long last = device->rs_mark_time[device->rs_last_mark];
int next = (device->rs_last_mark + 1) % DRBD_SYNC_MARKS;
if (time_after_eq(now, last + DRBD_SYNC_MARK_STEP)) {
if (device->rs_mark_left[device->rs_last_mark] != still_to_go &&
device->state.conn != C_PAUSED_SYNC_T &&
device->state.conn != C_PAUSED_SYNC_S) {
device->rs_mark_time[next] = now;
device->rs_mark_left[next] = still_to_go;
device->rs_last_mark = next;
}
}
}
static bool lazy_bitmap_update_due(struct drbd_device *device)
{
return time_after(jiffies, device->rs_last_bcast + 2*HZ);
}
static void maybe_schedule_on_disk_bitmap_update(struct drbd_device *device, bool rs_done)
{
if (rs_done) {
struct drbd_connection *connection = first_peer_device(device)->connection;
if (connection->agreed_pro_version <= 95 ||
is_sync_target_state(device->state.conn))
set_bit(RS_DONE, &device->flags);
} else if (!lazy_bitmap_update_due(device))
return;
drbd_device_post_work(device, RS_PROGRESS);
}
static int update_sync_bits(struct drbd_device *device,
unsigned long sbnr, unsigned long ebnr,
enum update_sync_bits_mode mode)
{
unsigned long flags;
unsigned long count = 0;
unsigned int cleared = 0;
while (sbnr <= ebnr) {
unsigned long tbnr = min(ebnr, sbnr | BM_BLOCKS_PER_BM_EXT_MASK);
unsigned long c;
if (mode == RECORD_RS_FAILED)
c = drbd_bm_count_bits(device, sbnr, tbnr);
else if (mode == SET_IN_SYNC)
c = drbd_bm_clear_bits(device, sbnr, tbnr);
else
c = drbd_bm_set_bits(device, sbnr, tbnr);
if (c) {
spin_lock_irqsave(&device->al_lock, flags);
cleared += update_rs_extent(device, BM_BIT_TO_EXT(sbnr), c, mode);
spin_unlock_irqrestore(&device->al_lock, flags);
count += c;
}
sbnr = tbnr + 1;
}
if (count) {
if (mode == SET_IN_SYNC) {
unsigned long still_to_go = drbd_bm_total_weight(device);
bool rs_is_done = (still_to_go <= device->rs_failed);
drbd_advance_rs_marks(device, still_to_go);
if (cleared || rs_is_done)
maybe_schedule_on_disk_bitmap_update(device, rs_is_done);
} else if (mode == RECORD_RS_FAILED)
device->rs_failed += count;
wake_up(&device->al_wait);
}
return count;
}
static bool plausible_request_size(int size)
{
return size > 0
&& size <= DRBD_MAX_BATCH_BIO_SIZE
&& IS_ALIGNED(size, 512);
}
int __drbd_change_sync(struct drbd_device *device, sector_t sector, int size,
enum update_sync_bits_mode mode)
{
unsigned long sbnr, ebnr, lbnr;
unsigned long count = 0;
sector_t esector, nr_sectors;
if ((mode == SET_OUT_OF_SYNC) && size == 0)
return 0;
if (!plausible_request_size(size)) {
drbd_err(device, "%s: sector=%llus size=%d nonsense!\n",
drbd_change_sync_fname[mode],
(unsigned long long)sector, size);
return 0;
}
if (!get_ldev(device))
return 0;
nr_sectors = drbd_get_capacity(device->this_bdev);
esector = sector + (size >> 9) - 1;
if (!expect(sector < nr_sectors))
goto out;
if (!expect(esector < nr_sectors))
esector = nr_sectors - 1;
lbnr = BM_SECT_TO_BIT(nr_sectors-1);
if (mode == SET_IN_SYNC) {
if (unlikely(esector < BM_SECT_PER_BIT-1))
goto out;
if (unlikely(esector == (nr_sectors-1)))
ebnr = lbnr;
else
ebnr = BM_SECT_TO_BIT(esector - (BM_SECT_PER_BIT-1));
sbnr = BM_SECT_TO_BIT(sector + BM_SECT_PER_BIT-1);
} else {
sbnr = BM_SECT_TO_BIT(sector);
ebnr = BM_SECT_TO_BIT(esector);
}
count = update_sync_bits(device, sbnr, ebnr, mode);
out:
put_ldev(device);
return count;
}
static
struct bm_extent *_bme_get(struct drbd_device *device, unsigned int enr)
{
struct lc_element *e;
struct bm_extent *bm_ext;
int wakeup = 0;
unsigned long rs_flags;
spin_lock_irq(&device->al_lock);
if (device->resync_locked > device->resync->nr_elements/2) {
spin_unlock_irq(&device->al_lock);
return NULL;
}
e = lc_get(device->resync, enr);
bm_ext = e ? lc_entry(e, struct bm_extent, lce) : NULL;
if (bm_ext) {
if (bm_ext->lce.lc_number != enr) {
bm_ext->rs_left = drbd_bm_e_weight(device, enr);
bm_ext->rs_failed = 0;
lc_committed(device->resync);
wakeup = 1;
}
if (bm_ext->lce.refcnt == 1)
device->resync_locked++;
set_bit(BME_NO_WRITES, &bm_ext->flags);
}
rs_flags = device->resync->flags;
spin_unlock_irq(&device->al_lock);
if (wakeup)
wake_up(&device->al_wait);
if (!bm_ext) {
if (rs_flags & LC_STARVING)
drbd_warn(device, "Have to wait for element"
" (resync LRU too small?)\n");
BUG_ON(rs_flags & LC_LOCKED);
}
return bm_ext;
}
static int _is_in_al(struct drbd_device *device, unsigned int enr)
{
int rv;
spin_lock_irq(&device->al_lock);
rv = lc_is_used(device->act_log, enr);
spin_unlock_irq(&device->al_lock);
return rv;
}
int drbd_rs_begin_io(struct drbd_device *device, sector_t sector)
{
unsigned int enr = BM_SECT_TO_EXT(sector);
struct bm_extent *bm_ext;
int i, sig;
bool sa;
retry:
sig = wait_event_interruptible(device->al_wait,
(bm_ext = _bme_get(device, enr)));
if (sig)
return -EINTR;
if (test_bit(BME_LOCKED, &bm_ext->flags))
return 0;
sa = drbd_rs_c_min_rate_throttle(device);
for (i = 0; i < AL_EXT_PER_BM_SECT; i++) {
sig = wait_event_interruptible(device->al_wait,
!_is_in_al(device, enr * AL_EXT_PER_BM_SECT + i) ||
(sa && test_bit(BME_PRIORITY, &bm_ext->flags)));
if (sig || (sa && test_bit(BME_PRIORITY, &bm_ext->flags))) {
spin_lock_irq(&device->al_lock);
if (lc_put(device->resync, &bm_ext->lce) == 0) {
bm_ext->flags = 0;
device->resync_locked--;
wake_up(&device->al_wait);
}
spin_unlock_irq(&device->al_lock);
if (sig)
return -EINTR;
if (schedule_timeout_interruptible(HZ/10))
return -EINTR;
goto retry;
}
}
set_bit(BME_LOCKED, &bm_ext->flags);
return 0;
}
int drbd_try_rs_begin_io(struct drbd_device *device, sector_t sector)
{
unsigned int enr = BM_SECT_TO_EXT(sector);
const unsigned int al_enr = enr*AL_EXT_PER_BM_SECT;
struct lc_element *e;
struct bm_extent *bm_ext;
int i;
bool throttle = drbd_rs_should_slow_down(device, sector, true);
if (throttle && device->resync_wenr != enr)
return -EAGAIN;
spin_lock_irq(&device->al_lock);
if (device->resync_wenr != LC_FREE && device->resync_wenr != enr) {
e = lc_find(device->resync, device->resync_wenr);
bm_ext = e ? lc_entry(e, struct bm_extent, lce) : NULL;
if (bm_ext) {
D_ASSERT(device, !test_bit(BME_LOCKED, &bm_ext->flags));
D_ASSERT(device, test_bit(BME_NO_WRITES, &bm_ext->flags));
clear_bit(BME_NO_WRITES, &bm_ext->flags);
device->resync_wenr = LC_FREE;
if (lc_put(device->resync, &bm_ext->lce) == 0) {
bm_ext->flags = 0;
device->resync_locked--;
}
wake_up(&device->al_wait);
} else {
drbd_alert(device, "LOGIC BUG\n");
}
}
e = lc_try_get(device->resync, enr);
bm_ext = e ? lc_entry(e, struct bm_extent, lce) : NULL;
if (bm_ext) {
if (test_bit(BME_LOCKED, &bm_ext->flags))
goto proceed;
if (!test_and_set_bit(BME_NO_WRITES, &bm_ext->flags)) {
device->resync_locked++;
} else {
bm_ext->lce.refcnt--;
D_ASSERT(device, bm_ext->lce.refcnt > 0);
}
goto check_al;
} else {
if (device->resync_locked > device->resync->nr_elements-3)
goto try_again;
e = lc_get(device->resync, enr);
bm_ext = e ? lc_entry(e, struct bm_extent, lce) : NULL;
if (!bm_ext) {
const unsigned long rs_flags = device->resync->flags;
if (rs_flags & LC_STARVING)
drbd_warn(device, "Have to wait for element"
" (resync LRU too small?)\n");
BUG_ON(rs_flags & LC_LOCKED);
goto try_again;
}
if (bm_ext->lce.lc_number != enr) {
bm_ext->rs_left = drbd_bm_e_weight(device, enr);
bm_ext->rs_failed = 0;
lc_committed(device->resync);
wake_up(&device->al_wait);
D_ASSERT(device, test_bit(BME_LOCKED, &bm_ext->flags) == 0);
}
set_bit(BME_NO_WRITES, &bm_ext->flags);
D_ASSERT(device, bm_ext->lce.refcnt == 1);
device->resync_locked++;
goto check_al;
}
check_al:
for (i = 0; i < AL_EXT_PER_BM_SECT; i++) {
if (lc_is_used(device->act_log, al_enr+i))
goto try_again;
}
set_bit(BME_LOCKED, &bm_ext->flags);
proceed:
device->resync_wenr = LC_FREE;
spin_unlock_irq(&device->al_lock);
return 0;
try_again:
if (bm_ext) {
if (throttle) {
D_ASSERT(device, !test_bit(BME_LOCKED, &bm_ext->flags));
D_ASSERT(device, test_bit(BME_NO_WRITES, &bm_ext->flags));
clear_bit(BME_NO_WRITES, &bm_ext->flags);
device->resync_wenr = LC_FREE;
if (lc_put(device->resync, &bm_ext->lce) == 0) {
bm_ext->flags = 0;
device->resync_locked--;
}
wake_up(&device->al_wait);
} else
device->resync_wenr = enr;
}
spin_unlock_irq(&device->al_lock);
return -EAGAIN;
}
void drbd_rs_complete_io(struct drbd_device *device, sector_t sector)
{
unsigned int enr = BM_SECT_TO_EXT(sector);
struct lc_element *e;
struct bm_extent *bm_ext;
unsigned long flags;
spin_lock_irqsave(&device->al_lock, flags);
e = lc_find(device->resync, enr);
bm_ext = e ? lc_entry(e, struct bm_extent, lce) : NULL;
if (!bm_ext) {
spin_unlock_irqrestore(&device->al_lock, flags);
if (__ratelimit(&drbd_ratelimit_state))
drbd_err(device, "drbd_rs_complete_io() called, but extent not found\n");
return;
}
if (bm_ext->lce.refcnt == 0) {
spin_unlock_irqrestore(&device->al_lock, flags);
drbd_err(device, "drbd_rs_complete_io(,%llu [=%u]) called, "
"but refcnt is 0!?\n",
(unsigned long long)sector, enr);
return;
}
if (lc_put(device->resync, &bm_ext->lce) == 0) {
bm_ext->flags = 0;
device->resync_locked--;
wake_up(&device->al_wait);
}
spin_unlock_irqrestore(&device->al_lock, flags);
}
void drbd_rs_cancel_all(struct drbd_device *device)
{
spin_lock_irq(&device->al_lock);
if (get_ldev_if_state(device, D_FAILED)) {
lc_reset(device->resync);
put_ldev(device);
}
device->resync_locked = 0;
device->resync_wenr = LC_FREE;
spin_unlock_irq(&device->al_lock);
wake_up(&device->al_wait);
}
int drbd_rs_del_all(struct drbd_device *device)
{
struct lc_element *e;
struct bm_extent *bm_ext;
int i;
spin_lock_irq(&device->al_lock);
if (get_ldev_if_state(device, D_FAILED)) {
for (i = 0; i < device->resync->nr_elements; i++) {
e = lc_element_by_index(device->resync, i);
bm_ext = lc_entry(e, struct bm_extent, lce);
if (bm_ext->lce.lc_number == LC_FREE)
continue;
if (bm_ext->lce.lc_number == device->resync_wenr) {
drbd_info(device, "dropping %u in drbd_rs_del_all, apparently"
" got 'synced' by application io\n",
device->resync_wenr);
D_ASSERT(device, !test_bit(BME_LOCKED, &bm_ext->flags));
D_ASSERT(device, test_bit(BME_NO_WRITES, &bm_ext->flags));
clear_bit(BME_NO_WRITES, &bm_ext->flags);
device->resync_wenr = LC_FREE;
lc_put(device->resync, &bm_ext->lce);
}
if (bm_ext->lce.refcnt != 0) {
drbd_info(device, "Retrying drbd_rs_del_all() later. "
"refcnt=%d\n", bm_ext->lce.refcnt);
put_ldev(device);
spin_unlock_irq(&device->al_lock);
return -EAGAIN;
}
D_ASSERT(device, !test_bit(BME_LOCKED, &bm_ext->flags));
D_ASSERT(device, !test_bit(BME_NO_WRITES, &bm_ext->flags));
lc_del(device->resync, &bm_ext->lce);
}
D_ASSERT(device, device->resync->used == 0);
put_ldev(device);
}
spin_unlock_irq(&device->al_lock);
wake_up(&device->al_wait);
return 0;
}
