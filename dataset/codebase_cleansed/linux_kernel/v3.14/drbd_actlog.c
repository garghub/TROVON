void *drbd_md_get_buffer(struct drbd_conf *mdev)
{
int r;
wait_event(mdev->misc_wait,
(r = atomic_cmpxchg(&mdev->md_io_in_use, 0, 1)) == 0 ||
mdev->state.disk <= D_FAILED);
return r ? NULL : page_address(mdev->md_io_page);
}
void drbd_md_put_buffer(struct drbd_conf *mdev)
{
if (atomic_dec_and_test(&mdev->md_io_in_use))
wake_up(&mdev->misc_wait);
}
void wait_until_done_or_force_detached(struct drbd_conf *mdev, struct drbd_backing_dev *bdev,
unsigned int *done)
{
long dt;
rcu_read_lock();
dt = rcu_dereference(bdev->disk_conf)->disk_timeout;
rcu_read_unlock();
dt = dt * HZ / 10;
if (dt == 0)
dt = MAX_SCHEDULE_TIMEOUT;
dt = wait_event_timeout(mdev->misc_wait,
*done || test_bit(FORCE_DETACH, &mdev->flags), dt);
if (dt == 0) {
dev_err(DEV, "meta-data IO operation timed out\n");
drbd_chk_io_error(mdev, 1, DRBD_FORCE_DETACH);
}
}
static int _drbd_md_sync_page_io(struct drbd_conf *mdev,
struct drbd_backing_dev *bdev,
struct page *page, sector_t sector,
int rw, int size)
{
struct bio *bio;
int err;
mdev->md_io.done = 0;
mdev->md_io.error = -ENODEV;
if ((rw & WRITE) && !test_bit(MD_NO_FUA, &mdev->flags))
rw |= REQ_FUA | REQ_FLUSH;
rw |= REQ_SYNC;
bio = bio_alloc_drbd(GFP_NOIO);
bio->bi_bdev = bdev->md_bdev;
bio->bi_iter.bi_sector = sector;
err = -EIO;
if (bio_add_page(bio, page, size, 0) != size)
goto out;
bio->bi_private = &mdev->md_io;
bio->bi_end_io = drbd_md_io_complete;
bio->bi_rw = rw;
if (!(rw & WRITE) && mdev->state.disk == D_DISKLESS && mdev->ldev == NULL)
;
else if (!get_ldev_if_state(mdev, D_ATTACHING)) {
dev_err(DEV, "ASSERT FAILED: get_ldev_if_state() == 1 in _drbd_md_sync_page_io()\n");
err = -ENODEV;
goto out;
}
bio_get(bio);
atomic_inc(&mdev->md_io_in_use);
if (drbd_insert_fault(mdev, (rw & WRITE) ? DRBD_FAULT_MD_WR : DRBD_FAULT_MD_RD))
bio_endio(bio, -EIO);
else
submit_bio(rw, bio);
wait_until_done_or_force_detached(mdev, bdev, &mdev->md_io.done);
if (bio_flagged(bio, BIO_UPTODATE))
err = mdev->md_io.error;
out:
bio_put(bio);
return err;
}
int drbd_md_sync_page_io(struct drbd_conf *mdev, struct drbd_backing_dev *bdev,
sector_t sector, int rw)
{
int err;
struct page *iop = mdev->md_io_page;
D_ASSERT(atomic_read(&mdev->md_io_in_use) == 1);
BUG_ON(!bdev->md_bdev);
dev_dbg(DEV, "meta_data io: %s [%d]:%s(,%llus,%s) %pS\n",
current->comm, current->pid, __func__,
(unsigned long long)sector, (rw & WRITE) ? "WRITE" : "READ",
(void*)_RET_IP_ );
if (sector < drbd_md_first_sector(bdev) ||
sector + 7 > drbd_md_last_sector(bdev))
dev_alert(DEV, "%s [%d]:%s(,%llus,%s) out of range md access!\n",
current->comm, current->pid, __func__,
(unsigned long long)sector, (rw & WRITE) ? "WRITE" : "READ");
err = _drbd_md_sync_page_io(mdev, bdev, iop, sector, rw, 4096);
if (err) {
dev_err(DEV, "drbd_md_sync_page_io(,%llus,%s) failed with error %d\n",
(unsigned long long)sector, (rw & WRITE) ? "WRITE" : "READ", err);
}
return err;
}
static struct bm_extent *find_active_resync_extent(struct drbd_conf *mdev, unsigned int enr)
{
struct lc_element *tmp;
tmp = lc_find(mdev->resync, enr/AL_EXT_PER_BM_SECT);
if (unlikely(tmp != NULL)) {
struct bm_extent *bm_ext = lc_entry(tmp, struct bm_extent, lce);
if (test_bit(BME_NO_WRITES, &bm_ext->flags))
return bm_ext;
}
return NULL;
}
static struct lc_element *_al_get(struct drbd_conf *mdev, unsigned int enr, bool nonblock)
{
struct lc_element *al_ext;
struct bm_extent *bm_ext;
int wake;
spin_lock_irq(&mdev->al_lock);
bm_ext = find_active_resync_extent(mdev, enr);
if (bm_ext) {
wake = !test_and_set_bit(BME_PRIORITY, &bm_ext->flags);
spin_unlock_irq(&mdev->al_lock);
if (wake)
wake_up(&mdev->al_wait);
return NULL;
}
if (nonblock)
al_ext = lc_try_get(mdev->act_log, enr);
else
al_ext = lc_get(mdev->act_log, enr);
spin_unlock_irq(&mdev->al_lock);
return al_ext;
}
bool drbd_al_begin_io_fastpath(struct drbd_conf *mdev, struct drbd_interval *i)
{
unsigned first = i->sector >> (AL_EXTENT_SHIFT-9);
unsigned last = i->size == 0 ? first : (i->sector + (i->size >> 9) - 1) >> (AL_EXTENT_SHIFT-9);
D_ASSERT((unsigned)(last - first) <= 1);
D_ASSERT(atomic_read(&mdev->local_cnt) > 0);
if (first != last)
return false;
return _al_get(mdev, first, true);
}
bool drbd_al_begin_io_prepare(struct drbd_conf *mdev, struct drbd_interval *i)
{
unsigned first = i->sector >> (AL_EXTENT_SHIFT-9);
unsigned last = i->size == 0 ? first : (i->sector + (i->size >> 9) - 1) >> (AL_EXTENT_SHIFT-9);
unsigned enr;
bool need_transaction = false;
D_ASSERT(first <= last);
D_ASSERT(atomic_read(&mdev->local_cnt) > 0);
for (enr = first; enr <= last; enr++) {
struct lc_element *al_ext;
wait_event(mdev->al_wait,
(al_ext = _al_get(mdev, enr, false)) != NULL);
if (al_ext->lc_number != enr)
need_transaction = true;
}
return need_transaction;
}
void drbd_al_begin_io_commit(struct drbd_conf *mdev, bool delegate)
{
bool locked = false;
BUG_ON(delegate && current == mdev->tconn->worker.task);
wait_event(mdev->al_wait,
mdev->act_log->pending_changes == 0 ||
(locked = lc_try_lock_for_transaction(mdev->act_log)));
if (locked) {
if (mdev->act_log->pending_changes) {
bool write_al_updates;
rcu_read_lock();
write_al_updates = rcu_dereference(mdev->ldev->disk_conf)->al_updates;
rcu_read_unlock();
if (write_al_updates)
al_write_transaction(mdev, delegate);
spin_lock_irq(&mdev->al_lock);
lc_committed(mdev->act_log);
spin_unlock_irq(&mdev->al_lock);
}
lc_unlock(mdev->act_log);
wake_up(&mdev->al_wait);
}
}
void drbd_al_begin_io(struct drbd_conf *mdev, struct drbd_interval *i, bool delegate)
{
BUG_ON(delegate && current == mdev->tconn->worker.task);
if (drbd_al_begin_io_prepare(mdev, i))
drbd_al_begin_io_commit(mdev, delegate);
}
int drbd_al_begin_io_nonblock(struct drbd_conf *mdev, struct drbd_interval *i)
{
struct lru_cache *al = mdev->act_log;
unsigned first = i->sector >> (AL_EXTENT_SHIFT-9);
unsigned last = i->size == 0 ? first : (i->sector + (i->size >> 9) - 1) >> (AL_EXTENT_SHIFT-9);
unsigned nr_al_extents;
unsigned available_update_slots;
unsigned enr;
D_ASSERT(first <= last);
nr_al_extents = 1 + last - first;
available_update_slots = min(al->nr_elements - al->used,
al->max_pending_changes - al->pending_changes);
if (available_update_slots < nr_al_extents)
return -EWOULDBLOCK;
for (enr = first; enr <= last; enr++) {
struct lc_element *tmp;
tmp = lc_find(mdev->resync, enr/AL_EXT_PER_BM_SECT);
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
al_ext = lc_get_cumulative(mdev->act_log, enr);
if (!al_ext)
dev_info(DEV, "LOGIC BUG for enr=%u\n", enr);
}
return 0;
}
void drbd_al_complete_io(struct drbd_conf *mdev, struct drbd_interval *i)
{
unsigned first = i->sector >> (AL_EXTENT_SHIFT-9);
unsigned last = i->size == 0 ? first : (i->sector + (i->size >> 9) - 1) >> (AL_EXTENT_SHIFT-9);
unsigned enr;
struct lc_element *extent;
unsigned long flags;
D_ASSERT(first <= last);
spin_lock_irqsave(&mdev->al_lock, flags);
for (enr = first; enr <= last; enr++) {
extent = lc_find(mdev->act_log, enr);
if (!extent) {
dev_err(DEV, "al_complete_io() called on inactive extent %u\n", enr);
continue;
}
lc_put(mdev->act_log, extent);
}
spin_unlock_irqrestore(&mdev->al_lock, flags);
wake_up(&mdev->al_wait);
}
static unsigned int al_extent_to_bm_page(unsigned int al_enr)
{
return al_enr >>
((PAGE_SHIFT + 3) -
(AL_EXTENT_SHIFT - BM_BLOCK_SHIFT));
}
static unsigned int rs_extent_to_bm_page(unsigned int rs_enr)
{
return rs_enr >>
((PAGE_SHIFT + 3) -
(BM_EXT_SHIFT - BM_BLOCK_SHIFT));
}
static sector_t al_tr_number_to_on_disk_sector(struct drbd_conf *mdev)
{
const unsigned int stripes = mdev->ldev->md.al_stripes;
const unsigned int stripe_size_4kB = mdev->ldev->md.al_stripe_size_4k;
unsigned int t = mdev->al_tr_number % (mdev->ldev->md.al_size_4k);
t = ((t % stripes) * stripe_size_4kB) + t/stripes;
t *= 8;
return mdev->ldev->md.md_offset + mdev->ldev->md.al_offset + t;
}
static int
_al_write_transaction(struct drbd_conf *mdev)
{
struct al_transaction_on_disk *buffer;
struct lc_element *e;
sector_t sector;
int i, mx;
unsigned extent_nr;
unsigned crc = 0;
int err = 0;
if (!get_ldev(mdev)) {
dev_err(DEV, "disk is %s, cannot start al transaction\n",
drbd_disk_str(mdev->state.disk));
return -EIO;
}
if (mdev->state.disk < D_INCONSISTENT) {
dev_err(DEV,
"disk is %s, cannot write al transaction\n",
drbd_disk_str(mdev->state.disk));
put_ldev(mdev);
return -EIO;
}
buffer = drbd_md_get_buffer(mdev);
if (!buffer) {
dev_err(DEV, "disk failed while waiting for md_io buffer\n");
put_ldev(mdev);
return -ENODEV;
}
memset(buffer, 0, sizeof(*buffer));
buffer->magic = cpu_to_be32(DRBD_AL_MAGIC);
buffer->tr_number = cpu_to_be32(mdev->al_tr_number);
i = 0;
spin_lock_irq(&mdev->al_lock);
list_for_each_entry(e, &mdev->act_log->to_be_changed, list) {
if (i == AL_UPDATES_PER_TRANSACTION) {
i++;
break;
}
buffer->update_slot_nr[i] = cpu_to_be16(e->lc_index);
buffer->update_extent_nr[i] = cpu_to_be32(e->lc_new_number);
if (e->lc_number != LC_FREE)
drbd_bm_mark_for_writeout(mdev,
al_extent_to_bm_page(e->lc_number));
i++;
}
spin_unlock_irq(&mdev->al_lock);
BUG_ON(i > AL_UPDATES_PER_TRANSACTION);
buffer->n_updates = cpu_to_be16(i);
for ( ; i < AL_UPDATES_PER_TRANSACTION; i++) {
buffer->update_slot_nr[i] = cpu_to_be16(-1);
buffer->update_extent_nr[i] = cpu_to_be32(LC_FREE);
}
buffer->context_size = cpu_to_be16(mdev->act_log->nr_elements);
buffer->context_start_slot_nr = cpu_to_be16(mdev->al_tr_cycle);
mx = min_t(int, AL_CONTEXT_PER_TRANSACTION,
mdev->act_log->nr_elements - mdev->al_tr_cycle);
for (i = 0; i < mx; i++) {
unsigned idx = mdev->al_tr_cycle + i;
extent_nr = lc_element_by_index(mdev->act_log, idx)->lc_number;
buffer->context[i] = cpu_to_be32(extent_nr);
}
for (; i < AL_CONTEXT_PER_TRANSACTION; i++)
buffer->context[i] = cpu_to_be32(LC_FREE);
mdev->al_tr_cycle += AL_CONTEXT_PER_TRANSACTION;
if (mdev->al_tr_cycle >= mdev->act_log->nr_elements)
mdev->al_tr_cycle = 0;
sector = al_tr_number_to_on_disk_sector(mdev);
crc = crc32c(0, buffer, 4096);
buffer->crc32c = cpu_to_be32(crc);
if (drbd_bm_write_hinted(mdev))
err = -EIO;
else {
bool write_al_updates;
rcu_read_lock();
write_al_updates = rcu_dereference(mdev->ldev->disk_conf)->al_updates;
rcu_read_unlock();
if (write_al_updates) {
if (drbd_md_sync_page_io(mdev, mdev->ldev, sector, WRITE)) {
err = -EIO;
drbd_chk_io_error(mdev, 1, DRBD_META_IO_ERROR);
} else {
mdev->al_tr_number++;
mdev->al_writ_cnt++;
}
}
}
drbd_md_put_buffer(mdev);
put_ldev(mdev);
return err;
}
static int w_al_write_transaction(struct drbd_work *w, int unused)
{
struct update_al_work *aw = container_of(w, struct update_al_work, w);
struct drbd_conf *mdev = w->mdev;
int err;
err = _al_write_transaction(mdev);
aw->err = err;
complete(&aw->event);
return err != -EIO ? err : 0;
}
static int al_write_transaction(struct drbd_conf *mdev, bool delegate)
{
if (delegate) {
struct update_al_work al_work;
init_completion(&al_work.event);
al_work.w.cb = w_al_write_transaction;
al_work.w.mdev = mdev;
drbd_queue_work_front(&mdev->tconn->sender_work, &al_work.w);
wait_for_completion(&al_work.event);
return al_work.err;
} else
return _al_write_transaction(mdev);
}
static int _try_lc_del(struct drbd_conf *mdev, struct lc_element *al_ext)
{
int rv;
spin_lock_irq(&mdev->al_lock);
rv = (al_ext->refcnt == 0);
if (likely(rv))
lc_del(mdev->act_log, al_ext);
spin_unlock_irq(&mdev->al_lock);
return rv;
}
void drbd_al_shrink(struct drbd_conf *mdev)
{
struct lc_element *al_ext;
int i;
D_ASSERT(test_bit(__LC_LOCKED, &mdev->act_log->flags));
for (i = 0; i < mdev->act_log->nr_elements; i++) {
al_ext = lc_element_by_index(mdev->act_log, i);
if (al_ext->lc_number == LC_FREE)
continue;
wait_event(mdev->al_wait, _try_lc_del(mdev, al_ext));
}
wake_up(&mdev->al_wait);
}
int drbd_initialize_al(struct drbd_conf *mdev, void *buffer)
{
struct al_transaction_on_disk *al = buffer;
struct drbd_md *md = &mdev->ldev->md;
sector_t al_base = md->md_offset + md->al_offset;
int al_size_4k = md->al_stripes * md->al_stripe_size_4k;
int i;
memset(al, 0, 4096);
al->magic = cpu_to_be32(DRBD_AL_MAGIC);
al->transaction_type = cpu_to_be16(AL_TR_INITIALIZED);
al->crc32c = cpu_to_be32(crc32c(0, al, 4096));
for (i = 0; i < al_size_4k; i++) {
int err = drbd_md_sync_page_io(mdev, mdev->ldev, al_base + i * 8, WRITE);
if (err)
return err;
}
return 0;
}
static int w_update_odbm(struct drbd_work *w, int unused)
{
struct update_odbm_work *udw = container_of(w, struct update_odbm_work, w);
struct drbd_conf *mdev = w->mdev;
struct sib_info sib = { .sib_reason = SIB_SYNC_PROGRESS, };
if (!get_ldev(mdev)) {
if (__ratelimit(&drbd_ratelimit_state))
dev_warn(DEV, "Can not update on disk bitmap, local IO disabled.\n");
kfree(udw);
return 0;
}
drbd_bm_write_page(mdev, rs_extent_to_bm_page(udw->enr));
put_ldev(mdev);
kfree(udw);
if (drbd_bm_total_weight(mdev) <= mdev->rs_failed) {
switch (mdev->state.conn) {
case C_SYNC_SOURCE: case C_SYNC_TARGET:
case C_PAUSED_SYNC_S: case C_PAUSED_SYNC_T:
drbd_resync_finished(mdev);
default:
break;
}
}
drbd_bcast_event(mdev, &sib);
return 0;
}
static void drbd_try_clear_on_disk_bm(struct drbd_conf *mdev, sector_t sector,
int count, int success)
{
struct lc_element *e;
struct update_odbm_work *udw;
unsigned int enr;
D_ASSERT(atomic_read(&mdev->local_cnt));
enr = BM_SECT_TO_EXT(sector);
e = lc_get(mdev->resync, enr);
if (e) {
struct bm_extent *ext = lc_entry(e, struct bm_extent, lce);
if (ext->lce.lc_number == enr) {
if (success)
ext->rs_left -= count;
else
ext->rs_failed += count;
if (ext->rs_left < ext->rs_failed) {
dev_warn(DEV, "BAD! sector=%llus enr=%u rs_left=%d "
"rs_failed=%d count=%d cstate=%s\n",
(unsigned long long)sector,
ext->lce.lc_number, ext->rs_left,
ext->rs_failed, count,
drbd_conn_str(mdev->state.conn));
ext->rs_left = drbd_bm_e_weight(mdev, enr);
}
} else {
int rs_left = drbd_bm_e_weight(mdev, enr);
if (ext->flags != 0) {
dev_warn(DEV, "changing resync lce: %d[%u;%02lx]"
" -> %d[%u;00]\n",
ext->lce.lc_number, ext->rs_left,
ext->flags, enr, rs_left);
ext->flags = 0;
}
if (ext->rs_failed) {
dev_warn(DEV, "Kicking resync_lru element enr=%u "
"out with rs_failed=%d\n",
ext->lce.lc_number, ext->rs_failed);
}
ext->rs_left = rs_left;
ext->rs_failed = success ? 0 : count;
lc_committed(mdev->resync);
}
lc_put(mdev->resync, &ext->lce);
if (ext->rs_left == ext->rs_failed) {
ext->rs_failed = 0;
udw = kmalloc(sizeof(*udw), GFP_ATOMIC);
if (udw) {
udw->enr = ext->lce.lc_number;
udw->w.cb = w_update_odbm;
udw->w.mdev = mdev;
drbd_queue_work_front(&mdev->tconn->sender_work, &udw->w);
} else {
dev_warn(DEV, "Could not kmalloc an udw\n");
}
}
} else {
dev_err(DEV, "lc_get() failed! locked=%d/%d flags=%lu\n",
mdev->resync_locked,
mdev->resync->nr_elements,
mdev->resync->flags);
}
}
void drbd_advance_rs_marks(struct drbd_conf *mdev, unsigned long still_to_go)
{
unsigned long now = jiffies;
unsigned long last = mdev->rs_mark_time[mdev->rs_last_mark];
int next = (mdev->rs_last_mark + 1) % DRBD_SYNC_MARKS;
if (time_after_eq(now, last + DRBD_SYNC_MARK_STEP)) {
if (mdev->rs_mark_left[mdev->rs_last_mark] != still_to_go &&
mdev->state.conn != C_PAUSED_SYNC_T &&
mdev->state.conn != C_PAUSED_SYNC_S) {
mdev->rs_mark_time[next] = now;
mdev->rs_mark_left[next] = still_to_go;
mdev->rs_last_mark = next;
}
}
}
void __drbd_set_in_sync(struct drbd_conf *mdev, sector_t sector, int size,
const char *file, const unsigned int line)
{
unsigned long sbnr, ebnr, lbnr;
unsigned long count = 0;
sector_t esector, nr_sectors;
int wake_up = 0;
unsigned long flags;
if (size <= 0 || !IS_ALIGNED(size, 512) || size > DRBD_MAX_BIO_SIZE) {
dev_err(DEV, "drbd_set_in_sync: sector=%llus size=%d nonsense!\n",
(unsigned long long)sector, size);
return;
}
if (!get_ldev(mdev))
return;
nr_sectors = drbd_get_capacity(mdev->this_bdev);
esector = sector + (size >> 9) - 1;
if (!expect(sector < nr_sectors))
goto out;
if (!expect(esector < nr_sectors))
esector = nr_sectors - 1;
lbnr = BM_SECT_TO_BIT(nr_sectors-1);
if (unlikely(esector < BM_SECT_PER_BIT-1))
goto out;
if (unlikely(esector == (nr_sectors-1)))
ebnr = lbnr;
else
ebnr = BM_SECT_TO_BIT(esector - (BM_SECT_PER_BIT-1));
sbnr = BM_SECT_TO_BIT(sector + BM_SECT_PER_BIT-1);
if (sbnr > ebnr)
goto out;
count = drbd_bm_clear_bits(mdev, sbnr, ebnr);
if (count) {
drbd_advance_rs_marks(mdev, drbd_bm_total_weight(mdev));
spin_lock_irqsave(&mdev->al_lock, flags);
drbd_try_clear_on_disk_bm(mdev, sector, count, true);
spin_unlock_irqrestore(&mdev->al_lock, flags);
wake_up = 1;
}
out:
put_ldev(mdev);
if (wake_up)
wake_up(&mdev->al_wait);
}
int __drbd_set_out_of_sync(struct drbd_conf *mdev, sector_t sector, int size,
const char *file, const unsigned int line)
{
unsigned long sbnr, ebnr, flags;
sector_t esector, nr_sectors;
unsigned int enr, count = 0;
struct lc_element *e;
if (size == 0)
return 0;
if (size < 0 || !IS_ALIGNED(size, 512) || size > DRBD_MAX_BIO_SIZE) {
dev_err(DEV, "sector: %llus, size: %d\n",
(unsigned long long)sector, size);
return 0;
}
if (!get_ldev(mdev))
return 0;
nr_sectors = drbd_get_capacity(mdev->this_bdev);
esector = sector + (size >> 9) - 1;
if (!expect(sector < nr_sectors))
goto out;
if (!expect(esector < nr_sectors))
esector = nr_sectors - 1;
sbnr = BM_SECT_TO_BIT(sector);
ebnr = BM_SECT_TO_BIT(esector);
spin_lock_irqsave(&mdev->al_lock, flags);
count = drbd_bm_set_bits(mdev, sbnr, ebnr);
enr = BM_SECT_TO_EXT(sector);
e = lc_find(mdev->resync, enr);
if (e)
lc_entry(e, struct bm_extent, lce)->rs_left += count;
spin_unlock_irqrestore(&mdev->al_lock, flags);
out:
put_ldev(mdev);
return count;
}
static
struct bm_extent *_bme_get(struct drbd_conf *mdev, unsigned int enr)
{
struct lc_element *e;
struct bm_extent *bm_ext;
int wakeup = 0;
unsigned long rs_flags;
spin_lock_irq(&mdev->al_lock);
if (mdev->resync_locked > mdev->resync->nr_elements/2) {
spin_unlock_irq(&mdev->al_lock);
return NULL;
}
e = lc_get(mdev->resync, enr);
bm_ext = e ? lc_entry(e, struct bm_extent, lce) : NULL;
if (bm_ext) {
if (bm_ext->lce.lc_number != enr) {
bm_ext->rs_left = drbd_bm_e_weight(mdev, enr);
bm_ext->rs_failed = 0;
lc_committed(mdev->resync);
wakeup = 1;
}
if (bm_ext->lce.refcnt == 1)
mdev->resync_locked++;
set_bit(BME_NO_WRITES, &bm_ext->flags);
}
rs_flags = mdev->resync->flags;
spin_unlock_irq(&mdev->al_lock);
if (wakeup)
wake_up(&mdev->al_wait);
if (!bm_ext) {
if (rs_flags & LC_STARVING)
dev_warn(DEV, "Have to wait for element"
" (resync LRU too small?)\n");
BUG_ON(rs_flags & LC_LOCKED);
}
return bm_ext;
}
static int _is_in_al(struct drbd_conf *mdev, unsigned int enr)
{
int rv;
spin_lock_irq(&mdev->al_lock);
rv = lc_is_used(mdev->act_log, enr);
spin_unlock_irq(&mdev->al_lock);
return rv;
}
int drbd_rs_begin_io(struct drbd_conf *mdev, sector_t sector)
{
unsigned int enr = BM_SECT_TO_EXT(sector);
struct bm_extent *bm_ext;
int i, sig;
int sa = 200;
retry:
sig = wait_event_interruptible(mdev->al_wait,
(bm_ext = _bme_get(mdev, enr)));
if (sig)
return -EINTR;
if (test_bit(BME_LOCKED, &bm_ext->flags))
return 0;
for (i = 0; i < AL_EXT_PER_BM_SECT; i++) {
sig = wait_event_interruptible(mdev->al_wait,
!_is_in_al(mdev, enr * AL_EXT_PER_BM_SECT + i) ||
test_bit(BME_PRIORITY, &bm_ext->flags));
if (sig || (test_bit(BME_PRIORITY, &bm_ext->flags) && sa)) {
spin_lock_irq(&mdev->al_lock);
if (lc_put(mdev->resync, &bm_ext->lce) == 0) {
bm_ext->flags = 0;
mdev->resync_locked--;
wake_up(&mdev->al_wait);
}
spin_unlock_irq(&mdev->al_lock);
if (sig)
return -EINTR;
if (schedule_timeout_interruptible(HZ/10))
return -EINTR;
if (sa && --sa == 0)
dev_warn(DEV,"drbd_rs_begin_io() stepped aside for 20sec."
"Resync stalled?\n");
goto retry;
}
}
set_bit(BME_LOCKED, &bm_ext->flags);
return 0;
}
int drbd_try_rs_begin_io(struct drbd_conf *mdev, sector_t sector)
{
unsigned int enr = BM_SECT_TO_EXT(sector);
const unsigned int al_enr = enr*AL_EXT_PER_BM_SECT;
struct lc_element *e;
struct bm_extent *bm_ext;
int i;
spin_lock_irq(&mdev->al_lock);
if (mdev->resync_wenr != LC_FREE && mdev->resync_wenr != enr) {
e = lc_find(mdev->resync, mdev->resync_wenr);
bm_ext = e ? lc_entry(e, struct bm_extent, lce) : NULL;
if (bm_ext) {
D_ASSERT(!test_bit(BME_LOCKED, &bm_ext->flags));
D_ASSERT(test_bit(BME_NO_WRITES, &bm_ext->flags));
clear_bit(BME_NO_WRITES, &bm_ext->flags);
mdev->resync_wenr = LC_FREE;
if (lc_put(mdev->resync, &bm_ext->lce) == 0)
mdev->resync_locked--;
wake_up(&mdev->al_wait);
} else {
dev_alert(DEV, "LOGIC BUG\n");
}
}
e = lc_try_get(mdev->resync, enr);
bm_ext = e ? lc_entry(e, struct bm_extent, lce) : NULL;
if (bm_ext) {
if (test_bit(BME_LOCKED, &bm_ext->flags))
goto proceed;
if (!test_and_set_bit(BME_NO_WRITES, &bm_ext->flags)) {
mdev->resync_locked++;
} else {
bm_ext->lce.refcnt--;
D_ASSERT(bm_ext->lce.refcnt > 0);
}
goto check_al;
} else {
if (mdev->resync_locked > mdev->resync->nr_elements-3)
goto try_again;
e = lc_get(mdev->resync, enr);
bm_ext = e ? lc_entry(e, struct bm_extent, lce) : NULL;
if (!bm_ext) {
const unsigned long rs_flags = mdev->resync->flags;
if (rs_flags & LC_STARVING)
dev_warn(DEV, "Have to wait for element"
" (resync LRU too small?)\n");
BUG_ON(rs_flags & LC_LOCKED);
goto try_again;
}
if (bm_ext->lce.lc_number != enr) {
bm_ext->rs_left = drbd_bm_e_weight(mdev, enr);
bm_ext->rs_failed = 0;
lc_committed(mdev->resync);
wake_up(&mdev->al_wait);
D_ASSERT(test_bit(BME_LOCKED, &bm_ext->flags) == 0);
}
set_bit(BME_NO_WRITES, &bm_ext->flags);
D_ASSERT(bm_ext->lce.refcnt == 1);
mdev->resync_locked++;
goto check_al;
}
check_al:
for (i = 0; i < AL_EXT_PER_BM_SECT; i++) {
if (lc_is_used(mdev->act_log, al_enr+i))
goto try_again;
}
set_bit(BME_LOCKED, &bm_ext->flags);
proceed:
mdev->resync_wenr = LC_FREE;
spin_unlock_irq(&mdev->al_lock);
return 0;
try_again:
if (bm_ext)
mdev->resync_wenr = enr;
spin_unlock_irq(&mdev->al_lock);
return -EAGAIN;
}
void drbd_rs_complete_io(struct drbd_conf *mdev, sector_t sector)
{
unsigned int enr = BM_SECT_TO_EXT(sector);
struct lc_element *e;
struct bm_extent *bm_ext;
unsigned long flags;
spin_lock_irqsave(&mdev->al_lock, flags);
e = lc_find(mdev->resync, enr);
bm_ext = e ? lc_entry(e, struct bm_extent, lce) : NULL;
if (!bm_ext) {
spin_unlock_irqrestore(&mdev->al_lock, flags);
if (__ratelimit(&drbd_ratelimit_state))
dev_err(DEV, "drbd_rs_complete_io() called, but extent not found\n");
return;
}
if (bm_ext->lce.refcnt == 0) {
spin_unlock_irqrestore(&mdev->al_lock, flags);
dev_err(DEV, "drbd_rs_complete_io(,%llu [=%u]) called, "
"but refcnt is 0!?\n",
(unsigned long long)sector, enr);
return;
}
if (lc_put(mdev->resync, &bm_ext->lce) == 0) {
bm_ext->flags = 0;
mdev->resync_locked--;
wake_up(&mdev->al_wait);
}
spin_unlock_irqrestore(&mdev->al_lock, flags);
}
void drbd_rs_cancel_all(struct drbd_conf *mdev)
{
spin_lock_irq(&mdev->al_lock);
if (get_ldev_if_state(mdev, D_FAILED)) {
lc_reset(mdev->resync);
put_ldev(mdev);
}
mdev->resync_locked = 0;
mdev->resync_wenr = LC_FREE;
spin_unlock_irq(&mdev->al_lock);
wake_up(&mdev->al_wait);
}
int drbd_rs_del_all(struct drbd_conf *mdev)
{
struct lc_element *e;
struct bm_extent *bm_ext;
int i;
spin_lock_irq(&mdev->al_lock);
if (get_ldev_if_state(mdev, D_FAILED)) {
for (i = 0; i < mdev->resync->nr_elements; i++) {
e = lc_element_by_index(mdev->resync, i);
bm_ext = lc_entry(e, struct bm_extent, lce);
if (bm_ext->lce.lc_number == LC_FREE)
continue;
if (bm_ext->lce.lc_number == mdev->resync_wenr) {
dev_info(DEV, "dropping %u in drbd_rs_del_all, apparently"
" got 'synced' by application io\n",
mdev->resync_wenr);
D_ASSERT(!test_bit(BME_LOCKED, &bm_ext->flags));
D_ASSERT(test_bit(BME_NO_WRITES, &bm_ext->flags));
clear_bit(BME_NO_WRITES, &bm_ext->flags);
mdev->resync_wenr = LC_FREE;
lc_put(mdev->resync, &bm_ext->lce);
}
if (bm_ext->lce.refcnt != 0) {
dev_info(DEV, "Retrying drbd_rs_del_all() later. "
"refcnt=%d\n", bm_ext->lce.refcnt);
put_ldev(mdev);
spin_unlock_irq(&mdev->al_lock);
return -EAGAIN;
}
D_ASSERT(!test_bit(BME_LOCKED, &bm_ext->flags));
D_ASSERT(!test_bit(BME_NO_WRITES, &bm_ext->flags));
lc_del(mdev->resync, &bm_ext->lce);
}
D_ASSERT(mdev->resync->used == 0);
put_ldev(mdev);
}
spin_unlock_irq(&mdev->al_lock);
wake_up(&mdev->al_wait);
return 0;
}
void drbd_rs_failed_io(struct drbd_conf *mdev, sector_t sector, int size)
{
unsigned long sbnr, ebnr, lbnr;
unsigned long count;
sector_t esector, nr_sectors;
int wake_up = 0;
if (size <= 0 || !IS_ALIGNED(size, 512) || size > DRBD_MAX_BIO_SIZE) {
dev_err(DEV, "drbd_rs_failed_io: sector=%llus size=%d nonsense!\n",
(unsigned long long)sector, size);
return;
}
nr_sectors = drbd_get_capacity(mdev->this_bdev);
esector = sector + (size >> 9) - 1;
if (!expect(sector < nr_sectors))
return;
if (!expect(esector < nr_sectors))
esector = nr_sectors - 1;
lbnr = BM_SECT_TO_BIT(nr_sectors-1);
if (unlikely(esector < BM_SECT_PER_BIT-1))
return;
if (unlikely(esector == (nr_sectors-1)))
ebnr = lbnr;
else
ebnr = BM_SECT_TO_BIT(esector - (BM_SECT_PER_BIT-1));
sbnr = BM_SECT_TO_BIT(sector + BM_SECT_PER_BIT-1);
if (sbnr > ebnr)
return;
spin_lock_irq(&mdev->al_lock);
count = drbd_bm_count_bits(mdev, sbnr, ebnr);
if (count) {
mdev->rs_failed += count;
if (get_ldev(mdev)) {
drbd_try_clear_on_disk_bm(mdev, sector, count, false);
put_ldev(mdev);
}
wake_up = 1;
}
spin_unlock_irq(&mdev->al_lock);
if (wake_up)
wake_up(&mdev->al_wait);
}
