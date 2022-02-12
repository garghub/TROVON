static void * r1bio_pool_alloc(gfp_t gfp_flags, void *data)
{
struct pool_info *pi = data;
int size = offsetof(struct r1bio, bios[pi->raid_disks]);
return kzalloc(size, gfp_flags);
}
static void r1bio_pool_free(void *r1_bio, void *data)
{
kfree(r1_bio);
}
static void * r1buf_pool_alloc(gfp_t gfp_flags, void *data)
{
struct pool_info *pi = data;
struct r1bio *r1_bio;
struct bio *bio;
int need_pages;
int i, j;
r1_bio = r1bio_pool_alloc(gfp_flags, pi);
if (!r1_bio)
return NULL;
for (j = pi->raid_disks ; j-- ; ) {
bio = bio_kmalloc(gfp_flags, RESYNC_PAGES);
if (!bio)
goto out_free_bio;
r1_bio->bios[j] = bio;
}
if (test_bit(MD_RECOVERY_REQUESTED, &pi->mddev->recovery))
need_pages = pi->raid_disks;
else
need_pages = 1;
for (j = 0; j < need_pages; j++) {
bio = r1_bio->bios[j];
bio->bi_vcnt = RESYNC_PAGES;
if (bio_alloc_pages(bio, gfp_flags))
goto out_free_pages;
}
if (!test_bit(MD_RECOVERY_REQUESTED, &pi->mddev->recovery)) {
for (i=0; i<RESYNC_PAGES ; i++)
for (j=1; j<pi->raid_disks; j++)
r1_bio->bios[j]->bi_io_vec[i].bv_page =
r1_bio->bios[0]->bi_io_vec[i].bv_page;
}
r1_bio->master_bio = NULL;
return r1_bio;
out_free_pages:
while (--j >= 0)
bio_free_pages(r1_bio->bios[j]);
out_free_bio:
while (++j < pi->raid_disks)
bio_put(r1_bio->bios[j]);
r1bio_pool_free(r1_bio, data);
return NULL;
}
static void r1buf_pool_free(void *__r1_bio, void *data)
{
struct pool_info *pi = data;
int i,j;
struct r1bio *r1bio = __r1_bio;
for (i = 0; i < RESYNC_PAGES; i++)
for (j = pi->raid_disks; j-- ;) {
if (j == 0 ||
r1bio->bios[j]->bi_io_vec[i].bv_page !=
r1bio->bios[0]->bi_io_vec[i].bv_page)
safe_put_page(r1bio->bios[j]->bi_io_vec[i].bv_page);
}
for (i=0 ; i < pi->raid_disks; i++)
bio_put(r1bio->bios[i]);
r1bio_pool_free(r1bio, data);
}
static void put_all_bios(struct r1conf *conf, struct r1bio *r1_bio)
{
int i;
for (i = 0; i < conf->raid_disks * 2; i++) {
struct bio **bio = r1_bio->bios + i;
if (!BIO_SPECIAL(*bio))
bio_put(*bio);
*bio = NULL;
}
}
static void free_r1bio(struct r1bio *r1_bio)
{
struct r1conf *conf = r1_bio->mddev->private;
put_all_bios(conf, r1_bio);
mempool_free(r1_bio, conf->r1bio_pool);
}
static void put_buf(struct r1bio *r1_bio)
{
struct r1conf *conf = r1_bio->mddev->private;
sector_t sect = r1_bio->sector;
int i;
for (i = 0; i < conf->raid_disks * 2; i++) {
struct bio *bio = r1_bio->bios[i];
if (bio->bi_end_io)
rdev_dec_pending(conf->mirrors[i].rdev, r1_bio->mddev);
}
mempool_free(r1_bio, conf->r1buf_pool);
lower_barrier(conf, sect);
}
static void reschedule_retry(struct r1bio *r1_bio)
{
unsigned long flags;
struct mddev *mddev = r1_bio->mddev;
struct r1conf *conf = mddev->private;
int idx;
idx = sector_to_idx(r1_bio->sector);
spin_lock_irqsave(&conf->device_lock, flags);
list_add(&r1_bio->retry_list, &conf->retry_list);
atomic_inc(&conf->nr_queued[idx]);
spin_unlock_irqrestore(&conf->device_lock, flags);
wake_up(&conf->wait_barrier);
md_wakeup_thread(mddev->thread);
}
static void call_bio_endio(struct r1bio *r1_bio)
{
struct bio *bio = r1_bio->master_bio;
int done;
struct r1conf *conf = r1_bio->mddev->private;
sector_t bi_sector = bio->bi_iter.bi_sector;
if (bio->bi_phys_segments) {
unsigned long flags;
spin_lock_irqsave(&conf->device_lock, flags);
bio->bi_phys_segments--;
done = (bio->bi_phys_segments == 0);
spin_unlock_irqrestore(&conf->device_lock, flags);
wake_up(&conf->wait_barrier);
} else
done = 1;
if (!test_bit(R1BIO_Uptodate, &r1_bio->state))
bio->bi_error = -EIO;
if (done) {
bio_endio(bio);
allow_barrier(conf, bi_sector);
}
}
static void raid_end_bio_io(struct r1bio *r1_bio)
{
struct bio *bio = r1_bio->master_bio;
if (!test_and_set_bit(R1BIO_Returned, &r1_bio->state)) {
pr_debug("raid1: sync end %s on sectors %llu-%llu\n",
(bio_data_dir(bio) == WRITE) ? "write" : "read",
(unsigned long long) bio->bi_iter.bi_sector,
(unsigned long long) bio_end_sector(bio) - 1);
call_bio_endio(r1_bio);
}
free_r1bio(r1_bio);
}
static inline void update_head_pos(int disk, struct r1bio *r1_bio)
{
struct r1conf *conf = r1_bio->mddev->private;
conf->mirrors[disk].head_position =
r1_bio->sector + (r1_bio->sectors);
}
static int find_bio_disk(struct r1bio *r1_bio, struct bio *bio)
{
int mirror;
struct r1conf *conf = r1_bio->mddev->private;
int raid_disks = conf->raid_disks;
for (mirror = 0; mirror < raid_disks * 2; mirror++)
if (r1_bio->bios[mirror] == bio)
break;
BUG_ON(mirror == raid_disks * 2);
update_head_pos(mirror, r1_bio);
return mirror;
}
static void raid1_end_read_request(struct bio *bio)
{
int uptodate = !bio->bi_error;
struct r1bio *r1_bio = bio->bi_private;
struct r1conf *conf = r1_bio->mddev->private;
struct md_rdev *rdev = conf->mirrors[r1_bio->read_disk].rdev;
update_head_pos(r1_bio->read_disk, r1_bio);
if (uptodate)
set_bit(R1BIO_Uptodate, &r1_bio->state);
else if (test_bit(FailFast, &rdev->flags) &&
test_bit(R1BIO_FailFast, &r1_bio->state))
;
else {
unsigned long flags;
spin_lock_irqsave(&conf->device_lock, flags);
if (r1_bio->mddev->degraded == conf->raid_disks ||
(r1_bio->mddev->degraded == conf->raid_disks-1 &&
test_bit(In_sync, &rdev->flags)))
uptodate = 1;
spin_unlock_irqrestore(&conf->device_lock, flags);
}
if (uptodate) {
raid_end_bio_io(r1_bio);
rdev_dec_pending(rdev, conf->mddev);
} else {
char b[BDEVNAME_SIZE];
pr_err_ratelimited("md/raid1:%s: %s: rescheduling sector %llu\n",
mdname(conf->mddev),
bdevname(rdev->bdev, b),
(unsigned long long)r1_bio->sector);
set_bit(R1BIO_ReadError, &r1_bio->state);
reschedule_retry(r1_bio);
}
}
static void close_write(struct r1bio *r1_bio)
{
if (test_bit(R1BIO_BehindIO, &r1_bio->state)) {
int i = r1_bio->behind_page_count;
while (i--)
safe_put_page(r1_bio->behind_bvecs[i].bv_page);
kfree(r1_bio->behind_bvecs);
r1_bio->behind_bvecs = NULL;
}
bitmap_endwrite(r1_bio->mddev->bitmap, r1_bio->sector,
r1_bio->sectors,
!test_bit(R1BIO_Degraded, &r1_bio->state),
test_bit(R1BIO_BehindIO, &r1_bio->state));
md_write_end(r1_bio->mddev);
}
static void r1_bio_write_done(struct r1bio *r1_bio)
{
if (!atomic_dec_and_test(&r1_bio->remaining))
return;
if (test_bit(R1BIO_WriteError, &r1_bio->state))
reschedule_retry(r1_bio);
else {
close_write(r1_bio);
if (test_bit(R1BIO_MadeGood, &r1_bio->state))
reschedule_retry(r1_bio);
else
raid_end_bio_io(r1_bio);
}
}
static void raid1_end_write_request(struct bio *bio)
{
struct r1bio *r1_bio = bio->bi_private;
int behind = test_bit(R1BIO_BehindIO, &r1_bio->state);
struct r1conf *conf = r1_bio->mddev->private;
struct bio *to_put = NULL;
int mirror = find_bio_disk(r1_bio, bio);
struct md_rdev *rdev = conf->mirrors[mirror].rdev;
bool discard_error;
discard_error = bio->bi_error && bio_op(bio) == REQ_OP_DISCARD;
if (bio->bi_error && !discard_error) {
set_bit(WriteErrorSeen, &rdev->flags);
if (!test_and_set_bit(WantReplacement, &rdev->flags))
set_bit(MD_RECOVERY_NEEDED, &
conf->mddev->recovery);
if (test_bit(FailFast, &rdev->flags) &&
(bio->bi_opf & MD_FAILFAST) &&
!test_bit(WriteMostly, &rdev->flags)) {
md_error(r1_bio->mddev, rdev);
if (!test_bit(Faulty, &rdev->flags))
set_bit(R1BIO_WriteError, &r1_bio->state);
else {
r1_bio->bios[mirror] = NULL;
to_put = bio;
}
} else
set_bit(R1BIO_WriteError, &r1_bio->state);
} else {
sector_t first_bad;
int bad_sectors;
r1_bio->bios[mirror] = NULL;
to_put = bio;
if (test_bit(In_sync, &rdev->flags) &&
!test_bit(Faulty, &rdev->flags))
set_bit(R1BIO_Uptodate, &r1_bio->state);
if (is_badblock(rdev, r1_bio->sector, r1_bio->sectors,
&first_bad, &bad_sectors) && !discard_error) {
r1_bio->bios[mirror] = IO_MADE_GOOD;
set_bit(R1BIO_MadeGood, &r1_bio->state);
}
}
if (behind) {
if (test_bit(WriteMostly, &rdev->flags))
atomic_dec(&r1_bio->behind_remaining);
if (atomic_read(&r1_bio->behind_remaining) >= (atomic_read(&r1_bio->remaining)-1) &&
test_bit(R1BIO_Uptodate, &r1_bio->state)) {
if (!test_and_set_bit(R1BIO_Returned, &r1_bio->state)) {
struct bio *mbio = r1_bio->master_bio;
pr_debug("raid1: behind end write sectors"
" %llu-%llu\n",
(unsigned long long) mbio->bi_iter.bi_sector,
(unsigned long long) bio_end_sector(mbio) - 1);
call_bio_endio(r1_bio);
}
}
}
if (r1_bio->bios[mirror] == NULL)
rdev_dec_pending(rdev, conf->mddev);
r1_bio_write_done(r1_bio);
if (to_put)
bio_put(to_put);
}
static sector_t align_to_barrier_unit_end(sector_t start_sector,
sector_t sectors)
{
sector_t len;
WARN_ON(sectors == 0);
len = round_up(start_sector + 1, BARRIER_UNIT_SECTOR_SIZE) -
start_sector;
if (len > sectors)
len = sectors;
return len;
}
static int read_balance(struct r1conf *conf, struct r1bio *r1_bio, int *max_sectors)
{
const sector_t this_sector = r1_bio->sector;
int sectors;
int best_good_sectors;
int best_disk, best_dist_disk, best_pending_disk;
int has_nonrot_disk;
int disk;
sector_t best_dist;
unsigned int min_pending;
struct md_rdev *rdev;
int choose_first;
int choose_next_idle;
rcu_read_lock();
retry:
sectors = r1_bio->sectors;
best_disk = -1;
best_dist_disk = -1;
best_dist = MaxSector;
best_pending_disk = -1;
min_pending = UINT_MAX;
best_good_sectors = 0;
has_nonrot_disk = 0;
choose_next_idle = 0;
clear_bit(R1BIO_FailFast, &r1_bio->state);
if ((conf->mddev->recovery_cp < this_sector + sectors) ||
(mddev_is_clustered(conf->mddev) &&
md_cluster_ops->area_resyncing(conf->mddev, READ, this_sector,
this_sector + sectors)))
choose_first = 1;
else
choose_first = 0;
for (disk = 0 ; disk < conf->raid_disks * 2 ; disk++) {
sector_t dist;
sector_t first_bad;
int bad_sectors;
unsigned int pending;
bool nonrot;
rdev = rcu_dereference(conf->mirrors[disk].rdev);
if (r1_bio->bios[disk] == IO_BLOCKED
|| rdev == NULL
|| test_bit(Faulty, &rdev->flags))
continue;
if (!test_bit(In_sync, &rdev->flags) &&
rdev->recovery_offset < this_sector + sectors)
continue;
if (test_bit(WriteMostly, &rdev->flags)) {
if (best_dist_disk < 0) {
if (is_badblock(rdev, this_sector, sectors,
&first_bad, &bad_sectors)) {
if (first_bad <= this_sector)
continue;
best_good_sectors = first_bad - this_sector;
} else
best_good_sectors = sectors;
best_dist_disk = disk;
best_pending_disk = disk;
}
continue;
}
if (is_badblock(rdev, this_sector, sectors,
&first_bad, &bad_sectors)) {
if (best_dist < MaxSector)
continue;
if (first_bad <= this_sector) {
bad_sectors -= (this_sector - first_bad);
if (choose_first && sectors > bad_sectors)
sectors = bad_sectors;
if (best_good_sectors > sectors)
best_good_sectors = sectors;
} else {
sector_t good_sectors = first_bad - this_sector;
if (good_sectors > best_good_sectors) {
best_good_sectors = good_sectors;
best_disk = disk;
}
if (choose_first)
break;
}
continue;
} else
best_good_sectors = sectors;
if (best_disk >= 0)
set_bit(R1BIO_FailFast, &r1_bio->state);
nonrot = blk_queue_nonrot(bdev_get_queue(rdev->bdev));
has_nonrot_disk |= nonrot;
pending = atomic_read(&rdev->nr_pending);
dist = abs(this_sector - conf->mirrors[disk].head_position);
if (choose_first) {
best_disk = disk;
break;
}
if (conf->mirrors[disk].next_seq_sect == this_sector
|| dist == 0) {
int opt_iosize = bdev_io_opt(rdev->bdev) >> 9;
struct raid1_info *mirror = &conf->mirrors[disk];
best_disk = disk;
if (nonrot && opt_iosize > 0 &&
mirror->seq_start != MaxSector &&
mirror->next_seq_sect > opt_iosize &&
mirror->next_seq_sect - opt_iosize >=
mirror->seq_start) {
choose_next_idle = 1;
continue;
}
break;
}
if (choose_next_idle)
continue;
if (min_pending > pending) {
min_pending = pending;
best_pending_disk = disk;
}
if (dist < best_dist) {
best_dist = dist;
best_dist_disk = disk;
}
}
if (best_disk == -1) {
if (has_nonrot_disk || min_pending == 0)
best_disk = best_pending_disk;
else
best_disk = best_dist_disk;
}
if (best_disk >= 0) {
rdev = rcu_dereference(conf->mirrors[best_disk].rdev);
if (!rdev)
goto retry;
atomic_inc(&rdev->nr_pending);
sectors = best_good_sectors;
if (conf->mirrors[best_disk].next_seq_sect != this_sector)
conf->mirrors[best_disk].seq_start = this_sector;
conf->mirrors[best_disk].next_seq_sect = this_sector + sectors;
}
rcu_read_unlock();
*max_sectors = sectors;
return best_disk;
}
static int raid1_congested(struct mddev *mddev, int bits)
{
struct r1conf *conf = mddev->private;
int i, ret = 0;
if ((bits & (1 << WB_async_congested)) &&
conf->pending_count >= max_queued_requests)
return 1;
rcu_read_lock();
for (i = 0; i < conf->raid_disks * 2; i++) {
struct md_rdev *rdev = rcu_dereference(conf->mirrors[i].rdev);
if (rdev && !test_bit(Faulty, &rdev->flags)) {
struct request_queue *q = bdev_get_queue(rdev->bdev);
BUG_ON(!q);
if ((bits & (1 << WB_async_congested)) || 1)
ret |= bdi_congested(q->backing_dev_info, bits);
else
ret &= bdi_congested(q->backing_dev_info, bits);
}
}
rcu_read_unlock();
return ret;
}
static void flush_pending_writes(struct r1conf *conf)
{
spin_lock_irq(&conf->device_lock);
if (conf->pending_bio_list.head) {
struct bio *bio;
bio = bio_list_get(&conf->pending_bio_list);
conf->pending_count = 0;
spin_unlock_irq(&conf->device_lock);
bitmap_unplug(conf->mddev->bitmap);
wake_up(&conf->wait_barrier);
while (bio) {
struct bio *next = bio->bi_next;
struct md_rdev *rdev = (void*)bio->bi_bdev;
bio->bi_next = NULL;
bio->bi_bdev = rdev->bdev;
if (test_bit(Faulty, &rdev->flags)) {
bio->bi_error = -EIO;
bio_endio(bio);
} else if (unlikely((bio_op(bio) == REQ_OP_DISCARD) &&
!blk_queue_discard(bdev_get_queue(bio->bi_bdev))))
bio_endio(bio);
else
generic_make_request(bio);
bio = next;
}
} else
spin_unlock_irq(&conf->device_lock);
}
static void raise_barrier(struct r1conf *conf, sector_t sector_nr)
{
int idx = sector_to_idx(sector_nr);
spin_lock_irq(&conf->resync_lock);
wait_event_lock_irq(conf->wait_barrier,
!atomic_read(&conf->nr_waiting[idx]),
conf->resync_lock);
atomic_inc(&conf->barrier[idx]);
smp_mb__after_atomic();
wait_event_lock_irq(conf->wait_barrier,
!conf->array_frozen &&
!atomic_read(&conf->nr_pending[idx]) &&
atomic_read(&conf->barrier[idx]) < RESYNC_DEPTH,
conf->resync_lock);
atomic_inc(&conf->nr_pending[idx]);
spin_unlock_irq(&conf->resync_lock);
}
static void lower_barrier(struct r1conf *conf, sector_t sector_nr)
{
int idx = sector_to_idx(sector_nr);
BUG_ON(atomic_read(&conf->barrier[idx]) <= 0);
atomic_dec(&conf->barrier[idx]);
atomic_dec(&conf->nr_pending[idx]);
wake_up(&conf->wait_barrier);
}
static void _wait_barrier(struct r1conf *conf, int idx)
{
atomic_inc(&conf->nr_pending[idx]);
smp_mb__after_atomic();
if (!READ_ONCE(conf->array_frozen) &&
!atomic_read(&conf->barrier[idx]))
return;
spin_lock_irq(&conf->resync_lock);
atomic_inc(&conf->nr_waiting[idx]);
atomic_dec(&conf->nr_pending[idx]);
wake_up(&conf->wait_barrier);
wait_event_lock_irq(conf->wait_barrier,
!conf->array_frozen &&
!atomic_read(&conf->barrier[idx]),
conf->resync_lock);
atomic_inc(&conf->nr_pending[idx]);
atomic_dec(&conf->nr_waiting[idx]);
spin_unlock_irq(&conf->resync_lock);
}
static void wait_read_barrier(struct r1conf *conf, sector_t sector_nr)
{
int idx = sector_to_idx(sector_nr);
atomic_inc(&conf->nr_pending[idx]);
if (!READ_ONCE(conf->array_frozen))
return;
spin_lock_irq(&conf->resync_lock);
atomic_inc(&conf->nr_waiting[idx]);
atomic_dec(&conf->nr_pending[idx]);
wake_up(&conf->wait_barrier);
wait_event_lock_irq(conf->wait_barrier,
!conf->array_frozen,
conf->resync_lock);
atomic_inc(&conf->nr_pending[idx]);
atomic_dec(&conf->nr_waiting[idx]);
spin_unlock_irq(&conf->resync_lock);
}
static void wait_barrier(struct r1conf *conf, sector_t sector_nr)
{
int idx = sector_to_idx(sector_nr);
_wait_barrier(conf, idx);
}
static void wait_all_barriers(struct r1conf *conf)
{
int idx;
for (idx = 0; idx < BARRIER_BUCKETS_NR; idx++)
_wait_barrier(conf, idx);
}
static void _allow_barrier(struct r1conf *conf, int idx)
{
atomic_dec(&conf->nr_pending[idx]);
wake_up(&conf->wait_barrier);
}
static void allow_barrier(struct r1conf *conf, sector_t sector_nr)
{
int idx = sector_to_idx(sector_nr);
_allow_barrier(conf, idx);
}
static void allow_all_barriers(struct r1conf *conf)
{
int idx;
for (idx = 0; idx < BARRIER_BUCKETS_NR; idx++)
_allow_barrier(conf, idx);
}
static int get_unqueued_pending(struct r1conf *conf)
{
int idx, ret;
for (ret = 0, idx = 0; idx < BARRIER_BUCKETS_NR; idx++)
ret += atomic_read(&conf->nr_pending[idx]) -
atomic_read(&conf->nr_queued[idx]);
return ret;
}
static void freeze_array(struct r1conf *conf, int extra)
{
spin_lock_irq(&conf->resync_lock);
conf->array_frozen = 1;
raid1_log(conf->mddev, "wait freeze");
wait_event_lock_irq_cmd(
conf->wait_barrier,
get_unqueued_pending(conf) == extra,
conf->resync_lock,
flush_pending_writes(conf));
spin_unlock_irq(&conf->resync_lock);
}
static void unfreeze_array(struct r1conf *conf)
{
spin_lock_irq(&conf->resync_lock);
conf->array_frozen = 0;
spin_unlock_irq(&conf->resync_lock);
wake_up(&conf->wait_barrier);
}
static void alloc_behind_pages(struct bio *bio, struct r1bio *r1_bio)
{
int i;
struct bio_vec *bvec;
struct bio_vec *bvecs = kzalloc(bio->bi_vcnt * sizeof(struct bio_vec),
GFP_NOIO);
if (unlikely(!bvecs))
return;
bio_for_each_segment_all(bvec, bio, i) {
bvecs[i] = *bvec;
bvecs[i].bv_page = alloc_page(GFP_NOIO);
if (unlikely(!bvecs[i].bv_page))
goto do_sync_io;
memcpy(kmap(bvecs[i].bv_page) + bvec->bv_offset,
kmap(bvec->bv_page) + bvec->bv_offset, bvec->bv_len);
kunmap(bvecs[i].bv_page);
kunmap(bvec->bv_page);
}
r1_bio->behind_bvecs = bvecs;
r1_bio->behind_page_count = bio->bi_vcnt;
set_bit(R1BIO_BehindIO, &r1_bio->state);
return;
do_sync_io:
for (i = 0; i < bio->bi_vcnt; i++)
if (bvecs[i].bv_page)
put_page(bvecs[i].bv_page);
kfree(bvecs);
pr_debug("%dB behind alloc failed, doing sync I/O\n",
bio->bi_iter.bi_size);
}
static void raid1_unplug(struct blk_plug_cb *cb, bool from_schedule)
{
struct raid1_plug_cb *plug = container_of(cb, struct raid1_plug_cb,
cb);
struct mddev *mddev = plug->cb.data;
struct r1conf *conf = mddev->private;
struct bio *bio;
if (from_schedule || current->bio_list) {
spin_lock_irq(&conf->device_lock);
bio_list_merge(&conf->pending_bio_list, &plug->pending);
conf->pending_count += plug->pending_cnt;
spin_unlock_irq(&conf->device_lock);
wake_up(&conf->wait_barrier);
md_wakeup_thread(mddev->thread);
kfree(plug);
return;
}
bio = bio_list_get(&plug->pending);
bitmap_unplug(mddev->bitmap);
wake_up(&conf->wait_barrier);
while (bio) {
struct bio *next = bio->bi_next;
struct md_rdev *rdev = (void*)bio->bi_bdev;
bio->bi_next = NULL;
bio->bi_bdev = rdev->bdev;
if (test_bit(Faulty, &rdev->flags)) {
bio->bi_error = -EIO;
bio_endio(bio);
} else if (unlikely((bio_op(bio) == REQ_OP_DISCARD) &&
!blk_queue_discard(bdev_get_queue(bio->bi_bdev))))
bio_endio(bio);
else
generic_make_request(bio);
bio = next;
}
kfree(plug);
}
static inline struct r1bio *
alloc_r1bio(struct mddev *mddev, struct bio *bio, sector_t sectors_handled)
{
struct r1conf *conf = mddev->private;
struct r1bio *r1_bio;
r1_bio = mempool_alloc(conf->r1bio_pool, GFP_NOIO);
r1_bio->master_bio = bio;
r1_bio->sectors = bio_sectors(bio) - sectors_handled;
r1_bio->state = 0;
r1_bio->mddev = mddev;
r1_bio->sector = bio->bi_iter.bi_sector + sectors_handled;
return r1_bio;
}
static void raid1_read_request(struct mddev *mddev, struct bio *bio)
{
struct r1conf *conf = mddev->private;
struct raid1_info *mirror;
struct r1bio *r1_bio;
struct bio *read_bio;
struct bitmap *bitmap = mddev->bitmap;
const int op = bio_op(bio);
const unsigned long do_sync = (bio->bi_opf & REQ_SYNC);
int sectors_handled;
int max_sectors;
int rdisk;
wait_read_barrier(conf, bio->bi_iter.bi_sector);
r1_bio = alloc_r1bio(mddev, bio, 0);
bio->bi_phys_segments = 0;
bio_clear_flag(bio, BIO_SEG_VALID);
read_again:
rdisk = read_balance(conf, r1_bio, &max_sectors);
if (rdisk < 0) {
raid_end_bio_io(r1_bio);
return;
}
mirror = conf->mirrors + rdisk;
if (test_bit(WriteMostly, &mirror->rdev->flags) &&
bitmap) {
raid1_log(mddev, "wait behind writes");
wait_event(bitmap->behind_wait,
atomic_read(&bitmap->behind_writes) == 0);
}
r1_bio->read_disk = rdisk;
read_bio = bio_clone_fast(bio, GFP_NOIO, mddev->bio_set);
bio_trim(read_bio, r1_bio->sector - bio->bi_iter.bi_sector,
max_sectors);
r1_bio->bios[rdisk] = read_bio;
read_bio->bi_iter.bi_sector = r1_bio->sector +
mirror->rdev->data_offset;
read_bio->bi_bdev = mirror->rdev->bdev;
read_bio->bi_end_io = raid1_end_read_request;
bio_set_op_attrs(read_bio, op, do_sync);
if (test_bit(FailFast, &mirror->rdev->flags) &&
test_bit(R1BIO_FailFast, &r1_bio->state))
read_bio->bi_opf |= MD_FAILFAST;
read_bio->bi_private = r1_bio;
if (mddev->gendisk)
trace_block_bio_remap(bdev_get_queue(read_bio->bi_bdev),
read_bio, disk_devt(mddev->gendisk),
r1_bio->sector);
if (max_sectors < r1_bio->sectors) {
sectors_handled = (r1_bio->sector + max_sectors
- bio->bi_iter.bi_sector);
r1_bio->sectors = max_sectors;
spin_lock_irq(&conf->device_lock);
if (bio->bi_phys_segments == 0)
bio->bi_phys_segments = 2;
else
bio->bi_phys_segments++;
spin_unlock_irq(&conf->device_lock);
reschedule_retry(r1_bio);
r1_bio = alloc_r1bio(mddev, bio, sectors_handled);
goto read_again;
} else
generic_make_request(read_bio);
}
static void raid1_write_request(struct mddev *mddev, struct bio *bio)
{
struct r1conf *conf = mddev->private;
struct r1bio *r1_bio;
int i, disks;
struct bitmap *bitmap = mddev->bitmap;
unsigned long flags;
struct md_rdev *blocked_rdev;
struct blk_plug_cb *cb;
struct raid1_plug_cb *plug = NULL;
int first_clone;
int sectors_handled;
int max_sectors;
md_write_start(mddev, bio);
if ((bio_end_sector(bio) > mddev->suspend_lo &&
bio->bi_iter.bi_sector < mddev->suspend_hi) ||
(mddev_is_clustered(mddev) &&
md_cluster_ops->area_resyncing(mddev, WRITE,
bio->bi_iter.bi_sector, bio_end_sector(bio)))) {
DEFINE_WAIT(w);
for (;;) {
flush_signals(current);
prepare_to_wait(&conf->wait_barrier,
&w, TASK_INTERRUPTIBLE);
if (bio_end_sector(bio) <= mddev->suspend_lo ||
bio->bi_iter.bi_sector >= mddev->suspend_hi ||
(mddev_is_clustered(mddev) &&
!md_cluster_ops->area_resyncing(mddev, WRITE,
bio->bi_iter.bi_sector,
bio_end_sector(bio))))
break;
schedule();
}
finish_wait(&conf->wait_barrier, &w);
}
wait_barrier(conf, bio->bi_iter.bi_sector);
r1_bio = alloc_r1bio(mddev, bio, 0);
bio->bi_phys_segments = 0;
bio_clear_flag(bio, BIO_SEG_VALID);
if (conf->pending_count >= max_queued_requests) {
md_wakeup_thread(mddev->thread);
raid1_log(mddev, "wait queued");
wait_event(conf->wait_barrier,
conf->pending_count < max_queued_requests);
}
disks = conf->raid_disks * 2;
retry_write:
blocked_rdev = NULL;
rcu_read_lock();
max_sectors = r1_bio->sectors;
for (i = 0; i < disks; i++) {
struct md_rdev *rdev = rcu_dereference(conf->mirrors[i].rdev);
if (rdev && unlikely(test_bit(Blocked, &rdev->flags))) {
atomic_inc(&rdev->nr_pending);
blocked_rdev = rdev;
break;
}
r1_bio->bios[i] = NULL;
if (!rdev || test_bit(Faulty, &rdev->flags)) {
if (i < conf->raid_disks)
set_bit(R1BIO_Degraded, &r1_bio->state);
continue;
}
atomic_inc(&rdev->nr_pending);
if (test_bit(WriteErrorSeen, &rdev->flags)) {
sector_t first_bad;
int bad_sectors;
int is_bad;
is_bad = is_badblock(rdev, r1_bio->sector, max_sectors,
&first_bad, &bad_sectors);
if (is_bad < 0) {
set_bit(BlockedBadBlocks, &rdev->flags);
blocked_rdev = rdev;
break;
}
if (is_bad && first_bad <= r1_bio->sector) {
bad_sectors -= (r1_bio->sector - first_bad);
if (bad_sectors < max_sectors)
max_sectors = bad_sectors;
rdev_dec_pending(rdev, mddev);
continue;
}
if (is_bad) {
int good_sectors = first_bad - r1_bio->sector;
if (good_sectors < max_sectors)
max_sectors = good_sectors;
}
}
r1_bio->bios[i] = bio;
}
rcu_read_unlock();
if (unlikely(blocked_rdev)) {
int j;
for (j = 0; j < i; j++)
if (r1_bio->bios[j])
rdev_dec_pending(conf->mirrors[j].rdev, mddev);
r1_bio->state = 0;
allow_barrier(conf, bio->bi_iter.bi_sector);
raid1_log(mddev, "wait rdev %d blocked", blocked_rdev->raid_disk);
md_wait_for_blocked_rdev(blocked_rdev, mddev);
wait_barrier(conf, bio->bi_iter.bi_sector);
goto retry_write;
}
if (max_sectors < r1_bio->sectors) {
r1_bio->sectors = max_sectors;
spin_lock_irq(&conf->device_lock);
if (bio->bi_phys_segments == 0)
bio->bi_phys_segments = 2;
else
bio->bi_phys_segments++;
spin_unlock_irq(&conf->device_lock);
}
sectors_handled = r1_bio->sector + max_sectors - bio->bi_iter.bi_sector;
atomic_set(&r1_bio->remaining, 1);
atomic_set(&r1_bio->behind_remaining, 0);
first_clone = 1;
for (i = 0; i < disks; i++) {
struct bio *mbio = NULL;
sector_t offset;
if (!r1_bio->bios[i])
continue;
offset = r1_bio->sector - bio->bi_iter.bi_sector;
if (first_clone) {
if (bitmap &&
(atomic_read(&bitmap->behind_writes)
< mddev->bitmap_info.max_write_behind) &&
!waitqueue_active(&bitmap->behind_wait)) {
mbio = bio_clone_bioset_partial(bio, GFP_NOIO,
mddev->bio_set,
offset << 9,
max_sectors << 9);
alloc_behind_pages(mbio, r1_bio);
}
bitmap_startwrite(bitmap, r1_bio->sector,
r1_bio->sectors,
test_bit(R1BIO_BehindIO,
&r1_bio->state));
first_clone = 0;
}
if (!mbio) {
if (r1_bio->behind_bvecs)
mbio = bio_clone_bioset_partial(bio, GFP_NOIO,
mddev->bio_set,
offset << 9,
max_sectors << 9);
else {
mbio = bio_clone_fast(bio, GFP_NOIO, mddev->bio_set);
bio_trim(mbio, offset, max_sectors);
}
}
if (r1_bio->behind_bvecs) {
struct bio_vec *bvec;
int j;
bio_for_each_segment_all(bvec, mbio, j)
bvec->bv_page = r1_bio->behind_bvecs[j].bv_page;
if (test_bit(WriteMostly, &conf->mirrors[i].rdev->flags))
atomic_inc(&r1_bio->behind_remaining);
}
r1_bio->bios[i] = mbio;
mbio->bi_iter.bi_sector = (r1_bio->sector +
conf->mirrors[i].rdev->data_offset);
mbio->bi_bdev = conf->mirrors[i].rdev->bdev;
mbio->bi_end_io = raid1_end_write_request;
mbio->bi_opf = bio_op(bio) | (bio->bi_opf & (REQ_SYNC | REQ_FUA));
if (test_bit(FailFast, &conf->mirrors[i].rdev->flags) &&
!test_bit(WriteMostly, &conf->mirrors[i].rdev->flags) &&
conf->raid_disks - mddev->degraded > 1)
mbio->bi_opf |= MD_FAILFAST;
mbio->bi_private = r1_bio;
atomic_inc(&r1_bio->remaining);
if (mddev->gendisk)
trace_block_bio_remap(bdev_get_queue(mbio->bi_bdev),
mbio, disk_devt(mddev->gendisk),
r1_bio->sector);
mbio->bi_bdev = (void*)conf->mirrors[i].rdev;
cb = blk_check_plugged(raid1_unplug, mddev, sizeof(*plug));
if (cb)
plug = container_of(cb, struct raid1_plug_cb, cb);
else
plug = NULL;
spin_lock_irqsave(&conf->device_lock, flags);
if (plug) {
bio_list_add(&plug->pending, mbio);
plug->pending_cnt++;
} else {
bio_list_add(&conf->pending_bio_list, mbio);
conf->pending_count++;
}
spin_unlock_irqrestore(&conf->device_lock, flags);
if (!plug)
md_wakeup_thread(mddev->thread);
}
if (sectors_handled < bio_sectors(bio)) {
r1_bio_write_done(r1_bio);
r1_bio = alloc_r1bio(mddev, bio, sectors_handled);
goto retry_write;
}
r1_bio_write_done(r1_bio);
wake_up(&conf->wait_barrier);
}
static void raid1_make_request(struct mddev *mddev, struct bio *bio)
{
struct bio *split;
sector_t sectors;
if (unlikely(bio->bi_opf & REQ_PREFLUSH)) {
md_flush_request(mddev, bio);
return;
}
do {
sectors = align_to_barrier_unit_end(
bio->bi_iter.bi_sector, bio_sectors(bio));
if (sectors < bio_sectors(bio)) {
split = bio_split(bio, sectors, GFP_NOIO, fs_bio_set);
bio_chain(split, bio);
} else {
split = bio;
}
if (bio_data_dir(split) == READ) {
raid1_read_request(mddev, split);
if (split != bio) {
generic_make_request(bio);
break;
}
} else
raid1_write_request(mddev, split);
} while (split != bio);
}
static void raid1_status(struct seq_file *seq, struct mddev *mddev)
{
struct r1conf *conf = mddev->private;
int i;
seq_printf(seq, " [%d/%d] [", conf->raid_disks,
conf->raid_disks - mddev->degraded);
rcu_read_lock();
for (i = 0; i < conf->raid_disks; i++) {
struct md_rdev *rdev = rcu_dereference(conf->mirrors[i].rdev);
seq_printf(seq, "%s",
rdev && test_bit(In_sync, &rdev->flags) ? "U" : "_");
}
rcu_read_unlock();
seq_printf(seq, "]");
}
static void raid1_error(struct mddev *mddev, struct md_rdev *rdev)
{
char b[BDEVNAME_SIZE];
struct r1conf *conf = mddev->private;
unsigned long flags;
spin_lock_irqsave(&conf->device_lock, flags);
if (test_bit(In_sync, &rdev->flags)
&& (conf->raid_disks - mddev->degraded) == 1) {
conf->recovery_disabled = mddev->recovery_disabled;
spin_unlock_irqrestore(&conf->device_lock, flags);
return;
}
set_bit(Blocked, &rdev->flags);
if (test_and_clear_bit(In_sync, &rdev->flags)) {
mddev->degraded++;
set_bit(Faulty, &rdev->flags);
} else
set_bit(Faulty, &rdev->flags);
spin_unlock_irqrestore(&conf->device_lock, flags);
set_bit(MD_RECOVERY_INTR, &mddev->recovery);
set_mask_bits(&mddev->sb_flags, 0,
BIT(MD_SB_CHANGE_DEVS) | BIT(MD_SB_CHANGE_PENDING));
pr_crit("md/raid1:%s: Disk failure on %s, disabling device.\n"
"md/raid1:%s: Operation continuing on %d devices.\n",
mdname(mddev), bdevname(rdev->bdev, b),
mdname(mddev), conf->raid_disks - mddev->degraded);
}
static void print_conf(struct r1conf *conf)
{
int i;
pr_debug("RAID1 conf printout:\n");
if (!conf) {
pr_debug("(!conf)\n");
return;
}
pr_debug(" --- wd:%d rd:%d\n", conf->raid_disks - conf->mddev->degraded,
conf->raid_disks);
rcu_read_lock();
for (i = 0; i < conf->raid_disks; i++) {
char b[BDEVNAME_SIZE];
struct md_rdev *rdev = rcu_dereference(conf->mirrors[i].rdev);
if (rdev)
pr_debug(" disk %d, wo:%d, o:%d, dev:%s\n",
i, !test_bit(In_sync, &rdev->flags),
!test_bit(Faulty, &rdev->flags),
bdevname(rdev->bdev,b));
}
rcu_read_unlock();
}
static void close_sync(struct r1conf *conf)
{
wait_all_barriers(conf);
allow_all_barriers(conf);
mempool_destroy(conf->r1buf_pool);
conf->r1buf_pool = NULL;
}
static int raid1_spare_active(struct mddev *mddev)
{
int i;
struct r1conf *conf = mddev->private;
int count = 0;
unsigned long flags;
spin_lock_irqsave(&conf->device_lock, flags);
for (i = 0; i < conf->raid_disks; i++) {
struct md_rdev *rdev = conf->mirrors[i].rdev;
struct md_rdev *repl = conf->mirrors[conf->raid_disks + i].rdev;
if (repl
&& !test_bit(Candidate, &repl->flags)
&& repl->recovery_offset == MaxSector
&& !test_bit(Faulty, &repl->flags)
&& !test_and_set_bit(In_sync, &repl->flags)) {
if (!rdev ||
!test_and_clear_bit(In_sync, &rdev->flags))
count++;
if (rdev) {
set_bit(Faulty, &rdev->flags);
sysfs_notify_dirent_safe(
rdev->sysfs_state);
}
}
if (rdev
&& rdev->recovery_offset == MaxSector
&& !test_bit(Faulty, &rdev->flags)
&& !test_and_set_bit(In_sync, &rdev->flags)) {
count++;
sysfs_notify_dirent_safe(rdev->sysfs_state);
}
}
mddev->degraded -= count;
spin_unlock_irqrestore(&conf->device_lock, flags);
print_conf(conf);
return count;
}
static int raid1_add_disk(struct mddev *mddev, struct md_rdev *rdev)
{
struct r1conf *conf = mddev->private;
int err = -EEXIST;
int mirror = 0;
struct raid1_info *p;
int first = 0;
int last = conf->raid_disks - 1;
if (mddev->recovery_disabled == conf->recovery_disabled)
return -EBUSY;
if (md_integrity_add_rdev(rdev, mddev))
return -ENXIO;
if (rdev->raid_disk >= 0)
first = last = rdev->raid_disk;
if (rdev->saved_raid_disk >= 0 &&
rdev->saved_raid_disk >= first &&
conf->mirrors[rdev->saved_raid_disk].rdev == NULL)
first = last = rdev->saved_raid_disk;
for (mirror = first; mirror <= last; mirror++) {
p = conf->mirrors+mirror;
if (!p->rdev) {
if (mddev->gendisk)
disk_stack_limits(mddev->gendisk, rdev->bdev,
rdev->data_offset << 9);
p->head_position = 0;
rdev->raid_disk = mirror;
err = 0;
if (rdev->saved_raid_disk < 0)
conf->fullsync = 1;
rcu_assign_pointer(p->rdev, rdev);
break;
}
if (test_bit(WantReplacement, &p->rdev->flags) &&
p[conf->raid_disks].rdev == NULL) {
clear_bit(In_sync, &rdev->flags);
set_bit(Replacement, &rdev->flags);
rdev->raid_disk = mirror;
err = 0;
conf->fullsync = 1;
rcu_assign_pointer(p[conf->raid_disks].rdev, rdev);
break;
}
}
if (mddev->queue && blk_queue_discard(bdev_get_queue(rdev->bdev)))
queue_flag_set_unlocked(QUEUE_FLAG_DISCARD, mddev->queue);
print_conf(conf);
return err;
}
static int raid1_remove_disk(struct mddev *mddev, struct md_rdev *rdev)
{
struct r1conf *conf = mddev->private;
int err = 0;
int number = rdev->raid_disk;
struct raid1_info *p = conf->mirrors + number;
if (rdev != p->rdev)
p = conf->mirrors + conf->raid_disks + number;
print_conf(conf);
if (rdev == p->rdev) {
if (test_bit(In_sync, &rdev->flags) ||
atomic_read(&rdev->nr_pending)) {
err = -EBUSY;
goto abort;
}
if (!test_bit(Faulty, &rdev->flags) &&
mddev->recovery_disabled != conf->recovery_disabled &&
mddev->degraded < conf->raid_disks) {
err = -EBUSY;
goto abort;
}
p->rdev = NULL;
if (!test_bit(RemoveSynchronized, &rdev->flags)) {
synchronize_rcu();
if (atomic_read(&rdev->nr_pending)) {
err = -EBUSY;
p->rdev = rdev;
goto abort;
}
}
if (conf->mirrors[conf->raid_disks + number].rdev) {
struct md_rdev *repl =
conf->mirrors[conf->raid_disks + number].rdev;
freeze_array(conf, 0);
clear_bit(Replacement, &repl->flags);
p->rdev = repl;
conf->mirrors[conf->raid_disks + number].rdev = NULL;
unfreeze_array(conf);
clear_bit(WantReplacement, &rdev->flags);
} else
clear_bit(WantReplacement, &rdev->flags);
err = md_integrity_register(mddev);
}
abort:
print_conf(conf);
return err;
}
static void end_sync_read(struct bio *bio)
{
struct r1bio *r1_bio = bio->bi_private;
update_head_pos(r1_bio->read_disk, r1_bio);
if (!bio->bi_error)
set_bit(R1BIO_Uptodate, &r1_bio->state);
if (atomic_dec_and_test(&r1_bio->remaining))
reschedule_retry(r1_bio);
}
static void end_sync_write(struct bio *bio)
{
int uptodate = !bio->bi_error;
struct r1bio *r1_bio = bio->bi_private;
struct mddev *mddev = r1_bio->mddev;
struct r1conf *conf = mddev->private;
sector_t first_bad;
int bad_sectors;
struct md_rdev *rdev = conf->mirrors[find_bio_disk(r1_bio, bio)].rdev;
if (!uptodate) {
sector_t sync_blocks = 0;
sector_t s = r1_bio->sector;
long sectors_to_go = r1_bio->sectors;
do {
bitmap_end_sync(mddev->bitmap, s,
&sync_blocks, 1);
s += sync_blocks;
sectors_to_go -= sync_blocks;
} while (sectors_to_go > 0);
set_bit(WriteErrorSeen, &rdev->flags);
if (!test_and_set_bit(WantReplacement, &rdev->flags))
set_bit(MD_RECOVERY_NEEDED, &
mddev->recovery);
set_bit(R1BIO_WriteError, &r1_bio->state);
} else if (is_badblock(rdev, r1_bio->sector, r1_bio->sectors,
&first_bad, &bad_sectors) &&
!is_badblock(conf->mirrors[r1_bio->read_disk].rdev,
r1_bio->sector,
r1_bio->sectors,
&first_bad, &bad_sectors)
)
set_bit(R1BIO_MadeGood, &r1_bio->state);
if (atomic_dec_and_test(&r1_bio->remaining)) {
int s = r1_bio->sectors;
if (test_bit(R1BIO_MadeGood, &r1_bio->state) ||
test_bit(R1BIO_WriteError, &r1_bio->state))
reschedule_retry(r1_bio);
else {
put_buf(r1_bio);
md_done_sync(mddev, s, uptodate);
}
}
}
static int r1_sync_page_io(struct md_rdev *rdev, sector_t sector,
int sectors, struct page *page, int rw)
{
if (sync_page_io(rdev, sector, sectors << 9, page, rw, 0, false))
return 1;
if (rw == WRITE) {
set_bit(WriteErrorSeen, &rdev->flags);
if (!test_and_set_bit(WantReplacement,
&rdev->flags))
set_bit(MD_RECOVERY_NEEDED, &
rdev->mddev->recovery);
}
if (!rdev_set_badblocks(rdev, sector, sectors, 0))
md_error(rdev->mddev, rdev);
return 0;
}
static int fix_sync_read_error(struct r1bio *r1_bio)
{
struct mddev *mddev = r1_bio->mddev;
struct r1conf *conf = mddev->private;
struct bio *bio = r1_bio->bios[r1_bio->read_disk];
sector_t sect = r1_bio->sector;
int sectors = r1_bio->sectors;
int idx = 0;
struct md_rdev *rdev;
rdev = conf->mirrors[r1_bio->read_disk].rdev;
if (test_bit(FailFast, &rdev->flags)) {
md_error(mddev, rdev);
if (test_bit(Faulty, &rdev->flags))
bio->bi_end_io = end_sync_write;
}
while(sectors) {
int s = sectors;
int d = r1_bio->read_disk;
int success = 0;
int start;
if (s > (PAGE_SIZE>>9))
s = PAGE_SIZE >> 9;
do {
if (r1_bio->bios[d]->bi_end_io == end_sync_read) {
rdev = conf->mirrors[d].rdev;
if (sync_page_io(rdev, sect, s<<9,
bio->bi_io_vec[idx].bv_page,
REQ_OP_READ, 0, false)) {
success = 1;
break;
}
}
d++;
if (d == conf->raid_disks * 2)
d = 0;
} while (!success && d != r1_bio->read_disk);
if (!success) {
char b[BDEVNAME_SIZE];
int abort = 0;
pr_crit_ratelimited("md/raid1:%s: %s: unrecoverable I/O read error for block %llu\n",
mdname(mddev),
bdevname(bio->bi_bdev, b),
(unsigned long long)r1_bio->sector);
for (d = 0; d < conf->raid_disks * 2; d++) {
rdev = conf->mirrors[d].rdev;
if (!rdev || test_bit(Faulty, &rdev->flags))
continue;
if (!rdev_set_badblocks(rdev, sect, s, 0))
abort = 1;
}
if (abort) {
conf->recovery_disabled =
mddev->recovery_disabled;
set_bit(MD_RECOVERY_INTR, &mddev->recovery);
md_done_sync(mddev, r1_bio->sectors, 0);
put_buf(r1_bio);
return 0;
}
sectors -= s;
sect += s;
idx++;
continue;
}
start = d;
while (d != r1_bio->read_disk) {
if (d == 0)
d = conf->raid_disks * 2;
d--;
if (r1_bio->bios[d]->bi_end_io != end_sync_read)
continue;
rdev = conf->mirrors[d].rdev;
if (r1_sync_page_io(rdev, sect, s,
bio->bi_io_vec[idx].bv_page,
WRITE) == 0) {
r1_bio->bios[d]->bi_end_io = NULL;
rdev_dec_pending(rdev, mddev);
}
}
d = start;
while (d != r1_bio->read_disk) {
if (d == 0)
d = conf->raid_disks * 2;
d--;
if (r1_bio->bios[d]->bi_end_io != end_sync_read)
continue;
rdev = conf->mirrors[d].rdev;
if (r1_sync_page_io(rdev, sect, s,
bio->bi_io_vec[idx].bv_page,
READ) != 0)
atomic_add(s, &rdev->corrected_errors);
}
sectors -= s;
sect += s;
idx ++;
}
set_bit(R1BIO_Uptodate, &r1_bio->state);
bio->bi_error = 0;
return 1;
}
static void process_checks(struct r1bio *r1_bio)
{
struct mddev *mddev = r1_bio->mddev;
struct r1conf *conf = mddev->private;
int primary;
int i;
int vcnt;
vcnt = (r1_bio->sectors + PAGE_SIZE / 512 - 1) >> (PAGE_SHIFT - 9);
for (i = 0; i < conf->raid_disks * 2; i++) {
int j;
int size;
int error;
struct bio *b = r1_bio->bios[i];
if (b->bi_end_io != end_sync_read)
continue;
error = b->bi_error;
bio_reset(b);
b->bi_error = error;
b->bi_vcnt = vcnt;
b->bi_iter.bi_size = r1_bio->sectors << 9;
b->bi_iter.bi_sector = r1_bio->sector +
conf->mirrors[i].rdev->data_offset;
b->bi_bdev = conf->mirrors[i].rdev->bdev;
b->bi_end_io = end_sync_read;
b->bi_private = r1_bio;
size = b->bi_iter.bi_size;
for (j = 0; j < vcnt ; j++) {
struct bio_vec *bi;
bi = &b->bi_io_vec[j];
bi->bv_offset = 0;
if (size > PAGE_SIZE)
bi->bv_len = PAGE_SIZE;
else
bi->bv_len = size;
size -= PAGE_SIZE;
}
}
for (primary = 0; primary < conf->raid_disks * 2; primary++)
if (r1_bio->bios[primary]->bi_end_io == end_sync_read &&
!r1_bio->bios[primary]->bi_error) {
r1_bio->bios[primary]->bi_end_io = NULL;
rdev_dec_pending(conf->mirrors[primary].rdev, mddev);
break;
}
r1_bio->read_disk = primary;
for (i = 0; i < conf->raid_disks * 2; i++) {
int j;
struct bio *pbio = r1_bio->bios[primary];
struct bio *sbio = r1_bio->bios[i];
int error = sbio->bi_error;
if (sbio->bi_end_io != end_sync_read)
continue;
sbio->bi_error = 0;
if (!error) {
for (j = vcnt; j-- ; ) {
struct page *p, *s;
p = pbio->bi_io_vec[j].bv_page;
s = sbio->bi_io_vec[j].bv_page;
if (memcmp(page_address(p),
page_address(s),
sbio->bi_io_vec[j].bv_len))
break;
}
} else
j = 0;
if (j >= 0)
atomic64_add(r1_bio->sectors, &mddev->resync_mismatches);
if (j < 0 || (test_bit(MD_RECOVERY_CHECK, &mddev->recovery)
&& !error)) {
sbio->bi_end_io = NULL;
rdev_dec_pending(conf->mirrors[i].rdev, mddev);
continue;
}
bio_copy_data(sbio, pbio);
}
}
static void sync_request_write(struct mddev *mddev, struct r1bio *r1_bio)
{
struct r1conf *conf = mddev->private;
int i;
int disks = conf->raid_disks * 2;
struct bio *bio, *wbio;
bio = r1_bio->bios[r1_bio->read_disk];
if (!test_bit(R1BIO_Uptodate, &r1_bio->state))
if (!fix_sync_read_error(r1_bio))
return;
if (test_bit(MD_RECOVERY_REQUESTED, &mddev->recovery))
process_checks(r1_bio);
atomic_set(&r1_bio->remaining, 1);
for (i = 0; i < disks ; i++) {
wbio = r1_bio->bios[i];
if (wbio->bi_end_io == NULL ||
(wbio->bi_end_io == end_sync_read &&
(i == r1_bio->read_disk ||
!test_bit(MD_RECOVERY_SYNC, &mddev->recovery))))
continue;
bio_set_op_attrs(wbio, REQ_OP_WRITE, 0);
if (test_bit(FailFast, &conf->mirrors[i].rdev->flags))
wbio->bi_opf |= MD_FAILFAST;
wbio->bi_end_io = end_sync_write;
atomic_inc(&r1_bio->remaining);
md_sync_acct(conf->mirrors[i].rdev->bdev, bio_sectors(wbio));
generic_make_request(wbio);
}
if (atomic_dec_and_test(&r1_bio->remaining)) {
int s = r1_bio->sectors;
if (test_bit(R1BIO_MadeGood, &r1_bio->state) ||
test_bit(R1BIO_WriteError, &r1_bio->state))
reschedule_retry(r1_bio);
else {
put_buf(r1_bio);
md_done_sync(mddev, s, 1);
}
}
}
static void fix_read_error(struct r1conf *conf, int read_disk,
sector_t sect, int sectors)
{
struct mddev *mddev = conf->mddev;
while(sectors) {
int s = sectors;
int d = read_disk;
int success = 0;
int start;
struct md_rdev *rdev;
if (s > (PAGE_SIZE>>9))
s = PAGE_SIZE >> 9;
do {
sector_t first_bad;
int bad_sectors;
rcu_read_lock();
rdev = rcu_dereference(conf->mirrors[d].rdev);
if (rdev &&
(test_bit(In_sync, &rdev->flags) ||
(!test_bit(Faulty, &rdev->flags) &&
rdev->recovery_offset >= sect + s)) &&
is_badblock(rdev, sect, s,
&first_bad, &bad_sectors) == 0) {
atomic_inc(&rdev->nr_pending);
rcu_read_unlock();
if (sync_page_io(rdev, sect, s<<9,
conf->tmppage, REQ_OP_READ, 0, false))
success = 1;
rdev_dec_pending(rdev, mddev);
if (success)
break;
} else
rcu_read_unlock();
d++;
if (d == conf->raid_disks * 2)
d = 0;
} while (!success && d != read_disk);
if (!success) {
struct md_rdev *rdev = conf->mirrors[read_disk].rdev;
if (!rdev_set_badblocks(rdev, sect, s, 0))
md_error(mddev, rdev);
break;
}
start = d;
while (d != read_disk) {
if (d==0)
d = conf->raid_disks * 2;
d--;
rcu_read_lock();
rdev = rcu_dereference(conf->mirrors[d].rdev);
if (rdev &&
!test_bit(Faulty, &rdev->flags)) {
atomic_inc(&rdev->nr_pending);
rcu_read_unlock();
r1_sync_page_io(rdev, sect, s,
conf->tmppage, WRITE);
rdev_dec_pending(rdev, mddev);
} else
rcu_read_unlock();
}
d = start;
while (d != read_disk) {
char b[BDEVNAME_SIZE];
if (d==0)
d = conf->raid_disks * 2;
d--;
rcu_read_lock();
rdev = rcu_dereference(conf->mirrors[d].rdev);
if (rdev &&
!test_bit(Faulty, &rdev->flags)) {
atomic_inc(&rdev->nr_pending);
rcu_read_unlock();
if (r1_sync_page_io(rdev, sect, s,
conf->tmppage, READ)) {
atomic_add(s, &rdev->corrected_errors);
pr_info("md/raid1:%s: read error corrected (%d sectors at %llu on %s)\n",
mdname(mddev), s,
(unsigned long long)(sect +
rdev->data_offset),
bdevname(rdev->bdev, b));
}
rdev_dec_pending(rdev, mddev);
} else
rcu_read_unlock();
}
sectors -= s;
sect += s;
}
}
static int narrow_write_error(struct r1bio *r1_bio, int i)
{
struct mddev *mddev = r1_bio->mddev;
struct r1conf *conf = mddev->private;
struct md_rdev *rdev = conf->mirrors[i].rdev;
int block_sectors;
sector_t sector;
int sectors;
int sect_to_write = r1_bio->sectors;
int ok = 1;
if (rdev->badblocks.shift < 0)
return 0;
block_sectors = roundup(1 << rdev->badblocks.shift,
bdev_logical_block_size(rdev->bdev) >> 9);
sector = r1_bio->sector;
sectors = ((sector + block_sectors)
& ~(sector_t)(block_sectors - 1))
- sector;
while (sect_to_write) {
struct bio *wbio;
if (sectors > sect_to_write)
sectors = sect_to_write;
if (test_bit(R1BIO_BehindIO, &r1_bio->state)) {
unsigned vcnt = r1_bio->behind_page_count;
struct bio_vec *vec = r1_bio->behind_bvecs;
while (!vec->bv_page) {
vec++;
vcnt--;
}
wbio = bio_alloc_mddev(GFP_NOIO, vcnt, mddev);
memcpy(wbio->bi_io_vec, vec, vcnt * sizeof(struct bio_vec));
wbio->bi_vcnt = vcnt;
} else {
wbio = bio_clone_fast(r1_bio->master_bio, GFP_NOIO,
mddev->bio_set);
}
bio_set_op_attrs(wbio, REQ_OP_WRITE, 0);
wbio->bi_iter.bi_sector = r1_bio->sector;
wbio->bi_iter.bi_size = r1_bio->sectors << 9;
bio_trim(wbio, sector - r1_bio->sector, sectors);
wbio->bi_iter.bi_sector += rdev->data_offset;
wbio->bi_bdev = rdev->bdev;
if (submit_bio_wait(wbio) < 0)
ok = rdev_set_badblocks(rdev, sector,
sectors, 0)
&& ok;
bio_put(wbio);
sect_to_write -= sectors;
sector += sectors;
sectors = block_sectors;
}
return ok;
}
static void handle_sync_write_finished(struct r1conf *conf, struct r1bio *r1_bio)
{
int m;
int s = r1_bio->sectors;
for (m = 0; m < conf->raid_disks * 2 ; m++) {
struct md_rdev *rdev = conf->mirrors[m].rdev;
struct bio *bio = r1_bio->bios[m];
if (bio->bi_end_io == NULL)
continue;
if (!bio->bi_error &&
test_bit(R1BIO_MadeGood, &r1_bio->state)) {
rdev_clear_badblocks(rdev, r1_bio->sector, s, 0);
}
if (bio->bi_error &&
test_bit(R1BIO_WriteError, &r1_bio->state)) {
if (!rdev_set_badblocks(rdev, r1_bio->sector, s, 0))
md_error(conf->mddev, rdev);
}
}
put_buf(r1_bio);
md_done_sync(conf->mddev, s, 1);
}
static void handle_write_finished(struct r1conf *conf, struct r1bio *r1_bio)
{
int m, idx;
bool fail = false;
for (m = 0; m < conf->raid_disks * 2 ; m++)
if (r1_bio->bios[m] == IO_MADE_GOOD) {
struct md_rdev *rdev = conf->mirrors[m].rdev;
rdev_clear_badblocks(rdev,
r1_bio->sector,
r1_bio->sectors, 0);
rdev_dec_pending(rdev, conf->mddev);
} else if (r1_bio->bios[m] != NULL) {
fail = true;
if (!narrow_write_error(r1_bio, m)) {
md_error(conf->mddev,
conf->mirrors[m].rdev);
set_bit(R1BIO_Degraded, &r1_bio->state);
}
rdev_dec_pending(conf->mirrors[m].rdev,
conf->mddev);
}
if (fail) {
spin_lock_irq(&conf->device_lock);
list_add(&r1_bio->retry_list, &conf->bio_end_io_list);
idx = sector_to_idx(r1_bio->sector);
atomic_inc(&conf->nr_queued[idx]);
spin_unlock_irq(&conf->device_lock);
wake_up(&conf->wait_barrier);
md_wakeup_thread(conf->mddev->thread);
} else {
if (test_bit(R1BIO_WriteError, &r1_bio->state))
close_write(r1_bio);
raid_end_bio_io(r1_bio);
}
}
static void handle_read_error(struct r1conf *conf, struct r1bio *r1_bio)
{
int disk;
int max_sectors;
struct mddev *mddev = conf->mddev;
struct bio *bio;
char b[BDEVNAME_SIZE];
struct md_rdev *rdev;
dev_t bio_dev;
sector_t bio_sector;
clear_bit(R1BIO_ReadError, &r1_bio->state);
bio = r1_bio->bios[r1_bio->read_disk];
bdevname(bio->bi_bdev, b);
bio_dev = bio->bi_bdev->bd_dev;
bio_sector = conf->mirrors[r1_bio->read_disk].rdev->data_offset + r1_bio->sector;
bio_put(bio);
r1_bio->bios[r1_bio->read_disk] = NULL;
rdev = conf->mirrors[r1_bio->read_disk].rdev;
if (mddev->ro == 0
&& !test_bit(FailFast, &rdev->flags)) {
freeze_array(conf, 1);
fix_read_error(conf, r1_bio->read_disk,
r1_bio->sector, r1_bio->sectors);
unfreeze_array(conf);
} else {
r1_bio->bios[r1_bio->read_disk] = IO_BLOCKED;
}
rdev_dec_pending(rdev, conf->mddev);
read_more:
disk = read_balance(conf, r1_bio, &max_sectors);
if (disk == -1) {
pr_crit_ratelimited("md/raid1:%s: %s: unrecoverable I/O read error for block %llu\n",
mdname(mddev), b, (unsigned long long)r1_bio->sector);
raid_end_bio_io(r1_bio);
} else {
const unsigned long do_sync
= r1_bio->master_bio->bi_opf & REQ_SYNC;
r1_bio->read_disk = disk;
bio = bio_clone_fast(r1_bio->master_bio, GFP_NOIO,
mddev->bio_set);
bio_trim(bio, r1_bio->sector - bio->bi_iter.bi_sector,
max_sectors);
r1_bio->bios[r1_bio->read_disk] = bio;
rdev = conf->mirrors[disk].rdev;
pr_info_ratelimited("md/raid1:%s: redirecting sector %llu to other mirror: %s\n",
mdname(mddev),
(unsigned long long)r1_bio->sector,
bdevname(rdev->bdev, b));
bio->bi_iter.bi_sector = r1_bio->sector + rdev->data_offset;
bio->bi_bdev = rdev->bdev;
bio->bi_end_io = raid1_end_read_request;
bio_set_op_attrs(bio, REQ_OP_READ, do_sync);
if (test_bit(FailFast, &rdev->flags) &&
test_bit(R1BIO_FailFast, &r1_bio->state))
bio->bi_opf |= MD_FAILFAST;
bio->bi_private = r1_bio;
if (max_sectors < r1_bio->sectors) {
struct bio *mbio = r1_bio->master_bio;
int sectors_handled = (r1_bio->sector + max_sectors
- mbio->bi_iter.bi_sector);
r1_bio->sectors = max_sectors;
spin_lock_irq(&conf->device_lock);
if (mbio->bi_phys_segments == 0)
mbio->bi_phys_segments = 2;
else
mbio->bi_phys_segments++;
spin_unlock_irq(&conf->device_lock);
trace_block_bio_remap(bdev_get_queue(bio->bi_bdev),
bio, bio_dev, bio_sector);
generic_make_request(bio);
bio = NULL;
r1_bio = alloc_r1bio(mddev, mbio, sectors_handled);
set_bit(R1BIO_ReadError, &r1_bio->state);
goto read_more;
} else {
trace_block_bio_remap(bdev_get_queue(bio->bi_bdev),
bio, bio_dev, bio_sector);
generic_make_request(bio);
}
}
}
static void raid1d(struct md_thread *thread)
{
struct mddev *mddev = thread->mddev;
struct r1bio *r1_bio;
unsigned long flags;
struct r1conf *conf = mddev->private;
struct list_head *head = &conf->retry_list;
struct blk_plug plug;
int idx;
md_check_recovery(mddev);
if (!list_empty_careful(&conf->bio_end_io_list) &&
!test_bit(MD_SB_CHANGE_PENDING, &mddev->sb_flags)) {
LIST_HEAD(tmp);
spin_lock_irqsave(&conf->device_lock, flags);
if (!test_bit(MD_SB_CHANGE_PENDING, &mddev->sb_flags))
list_splice_init(&conf->bio_end_io_list, &tmp);
spin_unlock_irqrestore(&conf->device_lock, flags);
while (!list_empty(&tmp)) {
r1_bio = list_first_entry(&tmp, struct r1bio,
retry_list);
list_del(&r1_bio->retry_list);
idx = sector_to_idx(r1_bio->sector);
atomic_dec(&conf->nr_queued[idx]);
if (mddev->degraded)
set_bit(R1BIO_Degraded, &r1_bio->state);
if (test_bit(R1BIO_WriteError, &r1_bio->state))
close_write(r1_bio);
raid_end_bio_io(r1_bio);
}
}
blk_start_plug(&plug);
for (;;) {
flush_pending_writes(conf);
spin_lock_irqsave(&conf->device_lock, flags);
if (list_empty(head)) {
spin_unlock_irqrestore(&conf->device_lock, flags);
break;
}
r1_bio = list_entry(head->prev, struct r1bio, retry_list);
list_del(head->prev);
idx = sector_to_idx(r1_bio->sector);
atomic_dec(&conf->nr_queued[idx]);
spin_unlock_irqrestore(&conf->device_lock, flags);
mddev = r1_bio->mddev;
conf = mddev->private;
if (test_bit(R1BIO_IsSync, &r1_bio->state)) {
if (test_bit(R1BIO_MadeGood, &r1_bio->state) ||
test_bit(R1BIO_WriteError, &r1_bio->state))
handle_sync_write_finished(conf, r1_bio);
else
sync_request_write(mddev, r1_bio);
} else if (test_bit(R1BIO_MadeGood, &r1_bio->state) ||
test_bit(R1BIO_WriteError, &r1_bio->state))
handle_write_finished(conf, r1_bio);
else if (test_bit(R1BIO_ReadError, &r1_bio->state))
handle_read_error(conf, r1_bio);
else
generic_make_request(r1_bio->bios[r1_bio->read_disk]);
cond_resched();
if (mddev->sb_flags & ~(1<<MD_SB_CHANGE_PENDING))
md_check_recovery(mddev);
}
blk_finish_plug(&plug);
}
static int init_resync(struct r1conf *conf)
{
int buffs;
buffs = RESYNC_WINDOW / RESYNC_BLOCK_SIZE;
BUG_ON(conf->r1buf_pool);
conf->r1buf_pool = mempool_create(buffs, r1buf_pool_alloc, r1buf_pool_free,
conf->poolinfo);
if (!conf->r1buf_pool)
return -ENOMEM;
return 0;
}
static sector_t raid1_sync_request(struct mddev *mddev, sector_t sector_nr,
int *skipped)
{
struct r1conf *conf = mddev->private;
struct r1bio *r1_bio;
struct bio *bio;
sector_t max_sector, nr_sectors;
int disk = -1;
int i;
int wonly = -1;
int write_targets = 0, read_targets = 0;
sector_t sync_blocks;
int still_degraded = 0;
int good_sectors = RESYNC_SECTORS;
int min_bad = 0;
int idx = sector_to_idx(sector_nr);
if (!conf->r1buf_pool)
if (init_resync(conf))
return 0;
max_sector = mddev->dev_sectors;
if (sector_nr >= max_sector) {
if (mddev->curr_resync < max_sector)
bitmap_end_sync(mddev->bitmap, mddev->curr_resync,
&sync_blocks, 1);
else
conf->fullsync = 0;
bitmap_close_sync(mddev->bitmap);
close_sync(conf);
if (mddev_is_clustered(mddev)) {
conf->cluster_sync_low = 0;
conf->cluster_sync_high = 0;
}
return 0;
}
if (mddev->bitmap == NULL &&
mddev->recovery_cp == MaxSector &&
!test_bit(MD_RECOVERY_REQUESTED, &mddev->recovery) &&
conf->fullsync == 0) {
*skipped = 1;
return max_sector - sector_nr;
}
if (!bitmap_start_sync(mddev->bitmap, sector_nr, &sync_blocks, 1) &&
!conf->fullsync && !test_bit(MD_RECOVERY_REQUESTED, &mddev->recovery)) {
*skipped = 1;
return sync_blocks;
}
if (atomic_read(&conf->nr_waiting[idx]))
schedule_timeout_uninterruptible(1);
bitmap_cond_end_sync(mddev->bitmap, sector_nr,
mddev_is_clustered(mddev) && (sector_nr + 2 * RESYNC_SECTORS > conf->cluster_sync_high));
r1_bio = mempool_alloc(conf->r1buf_pool, GFP_NOIO);
raise_barrier(conf, sector_nr);
rcu_read_lock();
r1_bio->mddev = mddev;
r1_bio->sector = sector_nr;
r1_bio->state = 0;
set_bit(R1BIO_IsSync, &r1_bio->state);
good_sectors = align_to_barrier_unit_end(sector_nr, good_sectors);
for (i = 0; i < conf->raid_disks * 2; i++) {
struct md_rdev *rdev;
bio = r1_bio->bios[i];
bio_reset(bio);
rdev = rcu_dereference(conf->mirrors[i].rdev);
if (rdev == NULL ||
test_bit(Faulty, &rdev->flags)) {
if (i < conf->raid_disks)
still_degraded = 1;
} else if (!test_bit(In_sync, &rdev->flags)) {
bio_set_op_attrs(bio, REQ_OP_WRITE, 0);
bio->bi_end_io = end_sync_write;
write_targets ++;
} else {
sector_t first_bad = MaxSector;
int bad_sectors;
if (is_badblock(rdev, sector_nr, good_sectors,
&first_bad, &bad_sectors)) {
if (first_bad > sector_nr)
good_sectors = first_bad - sector_nr;
else {
bad_sectors -= (sector_nr - first_bad);
if (min_bad == 0 ||
min_bad > bad_sectors)
min_bad = bad_sectors;
}
}
if (sector_nr < first_bad) {
if (test_bit(WriteMostly, &rdev->flags)) {
if (wonly < 0)
wonly = i;
} else {
if (disk < 0)
disk = i;
}
bio_set_op_attrs(bio, REQ_OP_READ, 0);
bio->bi_end_io = end_sync_read;
read_targets++;
} else if (!test_bit(WriteErrorSeen, &rdev->flags) &&
test_bit(MD_RECOVERY_SYNC, &mddev->recovery) &&
!test_bit(MD_RECOVERY_CHECK, &mddev->recovery)) {
bio_set_op_attrs(bio, REQ_OP_WRITE, 0);
bio->bi_end_io = end_sync_write;
write_targets++;
}
}
if (bio->bi_end_io) {
atomic_inc(&rdev->nr_pending);
bio->bi_iter.bi_sector = sector_nr + rdev->data_offset;
bio->bi_bdev = rdev->bdev;
bio->bi_private = r1_bio;
if (test_bit(FailFast, &rdev->flags))
bio->bi_opf |= MD_FAILFAST;
}
}
rcu_read_unlock();
if (disk < 0)
disk = wonly;
r1_bio->read_disk = disk;
if (read_targets == 0 && min_bad > 0) {
int ok = 1;
for (i = 0 ; i < conf->raid_disks * 2 ; i++)
if (r1_bio->bios[i]->bi_end_io == end_sync_write) {
struct md_rdev *rdev = conf->mirrors[i].rdev;
ok = rdev_set_badblocks(rdev, sector_nr,
min_bad, 0
) && ok;
}
set_bit(MD_SB_CHANGE_DEVS, &mddev->sb_flags);
*skipped = 1;
put_buf(r1_bio);
if (!ok) {
conf->recovery_disabled = mddev->recovery_disabled;
set_bit(MD_RECOVERY_INTR, &mddev->recovery);
return 0;
} else
return min_bad;
}
if (min_bad > 0 && min_bad < good_sectors) {
good_sectors = min_bad;
}
if (test_bit(MD_RECOVERY_SYNC, &mddev->recovery) && read_targets > 0)
write_targets += read_targets-1;
if (write_targets == 0 || read_targets == 0) {
sector_t rv;
if (min_bad > 0)
max_sector = sector_nr + min_bad;
rv = max_sector - sector_nr;
*skipped = 1;
put_buf(r1_bio);
return rv;
}
if (max_sector > mddev->resync_max)
max_sector = mddev->resync_max;
if (max_sector > sector_nr + good_sectors)
max_sector = sector_nr + good_sectors;
nr_sectors = 0;
sync_blocks = 0;
do {
struct page *page;
int len = PAGE_SIZE;
if (sector_nr + (len>>9) > max_sector)
len = (max_sector - sector_nr) << 9;
if (len == 0)
break;
if (sync_blocks == 0) {
if (!bitmap_start_sync(mddev->bitmap, sector_nr,
&sync_blocks, still_degraded) &&
!conf->fullsync &&
!test_bit(MD_RECOVERY_REQUESTED, &mddev->recovery))
break;
if ((len >> 9) > sync_blocks)
len = sync_blocks<<9;
}
for (i = 0 ; i < conf->raid_disks * 2; i++) {
bio = r1_bio->bios[i];
if (bio->bi_end_io) {
page = bio->bi_io_vec[bio->bi_vcnt].bv_page;
if (bio_add_page(bio, page, len, 0) == 0) {
bio->bi_io_vec[bio->bi_vcnt].bv_page = page;
while (i > 0) {
i--;
bio = r1_bio->bios[i];
if (bio->bi_end_io==NULL)
continue;
bio->bi_vcnt--;
bio->bi_iter.bi_size -= len;
bio_clear_flag(bio, BIO_SEG_VALID);
}
goto bio_full;
}
}
}
nr_sectors += len>>9;
sector_nr += len>>9;
sync_blocks -= (len>>9);
} while (r1_bio->bios[disk]->bi_vcnt < RESYNC_PAGES);
bio_full:
r1_bio->sectors = nr_sectors;
if (mddev_is_clustered(mddev) &&
conf->cluster_sync_high < sector_nr + nr_sectors) {
conf->cluster_sync_low = mddev->curr_resync_completed;
conf->cluster_sync_high = conf->cluster_sync_low + CLUSTER_RESYNC_WINDOW_SECTORS;
md_cluster_ops->resync_info_update(mddev,
conf->cluster_sync_low,
conf->cluster_sync_high);
}
if (test_bit(MD_RECOVERY_REQUESTED, &mddev->recovery)) {
atomic_set(&r1_bio->remaining, read_targets);
for (i = 0; i < conf->raid_disks * 2 && read_targets; i++) {
bio = r1_bio->bios[i];
if (bio->bi_end_io == end_sync_read) {
read_targets--;
md_sync_acct(bio->bi_bdev, nr_sectors);
if (read_targets == 1)
bio->bi_opf &= ~MD_FAILFAST;
generic_make_request(bio);
}
}
} else {
atomic_set(&r1_bio->remaining, 1);
bio = r1_bio->bios[r1_bio->read_disk];
md_sync_acct(bio->bi_bdev, nr_sectors);
if (read_targets == 1)
bio->bi_opf &= ~MD_FAILFAST;
generic_make_request(bio);
}
return nr_sectors;
}
static sector_t raid1_size(struct mddev *mddev, sector_t sectors, int raid_disks)
{
if (sectors)
return sectors;
return mddev->dev_sectors;
}
static struct r1conf *setup_conf(struct mddev *mddev)
{
struct r1conf *conf;
int i;
struct raid1_info *disk;
struct md_rdev *rdev;
int err = -ENOMEM;
conf = kzalloc(sizeof(struct r1conf), GFP_KERNEL);
if (!conf)
goto abort;
conf->nr_pending = kcalloc(BARRIER_BUCKETS_NR,
sizeof(atomic_t), GFP_KERNEL);
if (!conf->nr_pending)
goto abort;
conf->nr_waiting = kcalloc(BARRIER_BUCKETS_NR,
sizeof(atomic_t), GFP_KERNEL);
if (!conf->nr_waiting)
goto abort;
conf->nr_queued = kcalloc(BARRIER_BUCKETS_NR,
sizeof(atomic_t), GFP_KERNEL);
if (!conf->nr_queued)
goto abort;
conf->barrier = kcalloc(BARRIER_BUCKETS_NR,
sizeof(atomic_t), GFP_KERNEL);
if (!conf->barrier)
goto abort;
conf->mirrors = kzalloc(sizeof(struct raid1_info)
* mddev->raid_disks * 2,
GFP_KERNEL);
if (!conf->mirrors)
goto abort;
conf->tmppage = alloc_page(GFP_KERNEL);
if (!conf->tmppage)
goto abort;
conf->poolinfo = kzalloc(sizeof(*conf->poolinfo), GFP_KERNEL);
if (!conf->poolinfo)
goto abort;
conf->poolinfo->raid_disks = mddev->raid_disks * 2;
conf->r1bio_pool = mempool_create(NR_RAID1_BIOS, r1bio_pool_alloc,
r1bio_pool_free,
conf->poolinfo);
if (!conf->r1bio_pool)
goto abort;
conf->poolinfo->mddev = mddev;
err = -EINVAL;
spin_lock_init(&conf->device_lock);
rdev_for_each(rdev, mddev) {
struct request_queue *q;
int disk_idx = rdev->raid_disk;
if (disk_idx >= mddev->raid_disks
|| disk_idx < 0)
continue;
if (test_bit(Replacement, &rdev->flags))
disk = conf->mirrors + mddev->raid_disks + disk_idx;
else
disk = conf->mirrors + disk_idx;
if (disk->rdev)
goto abort;
disk->rdev = rdev;
q = bdev_get_queue(rdev->bdev);
disk->head_position = 0;
disk->seq_start = MaxSector;
}
conf->raid_disks = mddev->raid_disks;
conf->mddev = mddev;
INIT_LIST_HEAD(&conf->retry_list);
INIT_LIST_HEAD(&conf->bio_end_io_list);
spin_lock_init(&conf->resync_lock);
init_waitqueue_head(&conf->wait_barrier);
bio_list_init(&conf->pending_bio_list);
conf->pending_count = 0;
conf->recovery_disabled = mddev->recovery_disabled - 1;
err = -EIO;
for (i = 0; i < conf->raid_disks * 2; i++) {
disk = conf->mirrors + i;
if (i < conf->raid_disks &&
disk[conf->raid_disks].rdev) {
if (!disk->rdev) {
disk->rdev =
disk[conf->raid_disks].rdev;
disk[conf->raid_disks].rdev = NULL;
} else if (!test_bit(In_sync, &disk->rdev->flags))
goto abort;
}
if (!disk->rdev ||
!test_bit(In_sync, &disk->rdev->flags)) {
disk->head_position = 0;
if (disk->rdev &&
(disk->rdev->saved_raid_disk < 0))
conf->fullsync = 1;
}
}
err = -ENOMEM;
conf->thread = md_register_thread(raid1d, mddev, "raid1");
if (!conf->thread)
goto abort;
return conf;
abort:
if (conf) {
mempool_destroy(conf->r1bio_pool);
kfree(conf->mirrors);
safe_put_page(conf->tmppage);
kfree(conf->poolinfo);
kfree(conf->nr_pending);
kfree(conf->nr_waiting);
kfree(conf->nr_queued);
kfree(conf->barrier);
kfree(conf);
}
return ERR_PTR(err);
}
static int raid1_run(struct mddev *mddev)
{
struct r1conf *conf;
int i;
struct md_rdev *rdev;
int ret;
bool discard_supported = false;
if (mddev->level != 1) {
pr_warn("md/raid1:%s: raid level not set to mirroring (%d)\n",
mdname(mddev), mddev->level);
return -EIO;
}
if (mddev->reshape_position != MaxSector) {
pr_warn("md/raid1:%s: reshape_position set but not supported\n",
mdname(mddev));
return -EIO;
}
if (mddev->private == NULL)
conf = setup_conf(mddev);
else
conf = mddev->private;
if (IS_ERR(conf))
return PTR_ERR(conf);
if (mddev->queue)
blk_queue_max_write_same_sectors(mddev->queue, 0);
rdev_for_each(rdev, mddev) {
if (!mddev->gendisk)
continue;
disk_stack_limits(mddev->gendisk, rdev->bdev,
rdev->data_offset << 9);
if (blk_queue_discard(bdev_get_queue(rdev->bdev)))
discard_supported = true;
}
mddev->degraded = 0;
for (i=0; i < conf->raid_disks; i++)
if (conf->mirrors[i].rdev == NULL ||
!test_bit(In_sync, &conf->mirrors[i].rdev->flags) ||
test_bit(Faulty, &conf->mirrors[i].rdev->flags))
mddev->degraded++;
if (conf->raid_disks - mddev->degraded == 1)
mddev->recovery_cp = MaxSector;
if (mddev->recovery_cp != MaxSector)
pr_info("md/raid1:%s: not clean -- starting background reconstruction\n",
mdname(mddev));
pr_info("md/raid1:%s: active with %d out of %d mirrors\n",
mdname(mddev), mddev->raid_disks - mddev->degraded,
mddev->raid_disks);
mddev->thread = conf->thread;
conf->thread = NULL;
mddev->private = conf;
set_bit(MD_FAILFAST_SUPPORTED, &mddev->flags);
md_set_array_sectors(mddev, raid1_size(mddev, 0, 0));
if (mddev->queue) {
if (discard_supported)
queue_flag_set_unlocked(QUEUE_FLAG_DISCARD,
mddev->queue);
else
queue_flag_clear_unlocked(QUEUE_FLAG_DISCARD,
mddev->queue);
}
ret = md_integrity_register(mddev);
if (ret) {
md_unregister_thread(&mddev->thread);
raid1_free(mddev, conf);
}
return ret;
}
static void raid1_free(struct mddev *mddev, void *priv)
{
struct r1conf *conf = priv;
mempool_destroy(conf->r1bio_pool);
kfree(conf->mirrors);
safe_put_page(conf->tmppage);
kfree(conf->poolinfo);
kfree(conf->nr_pending);
kfree(conf->nr_waiting);
kfree(conf->nr_queued);
kfree(conf->barrier);
kfree(conf);
}
static int raid1_resize(struct mddev *mddev, sector_t sectors)
{
sector_t newsize = raid1_size(mddev, sectors, 0);
if (mddev->external_size &&
mddev->array_sectors > newsize)
return -EINVAL;
if (mddev->bitmap) {
int ret = bitmap_resize(mddev->bitmap, newsize, 0, 0);
if (ret)
return ret;
}
md_set_array_sectors(mddev, newsize);
if (sectors > mddev->dev_sectors &&
mddev->recovery_cp > mddev->dev_sectors) {
mddev->recovery_cp = mddev->dev_sectors;
set_bit(MD_RECOVERY_NEEDED, &mddev->recovery);
}
mddev->dev_sectors = sectors;
mddev->resync_max_sectors = sectors;
return 0;
}
static int raid1_reshape(struct mddev *mddev)
{
mempool_t *newpool, *oldpool;
struct pool_info *newpoolinfo;
struct raid1_info *newmirrors;
struct r1conf *conf = mddev->private;
int cnt, raid_disks;
unsigned long flags;
int d, d2, err;
if (mddev->chunk_sectors != mddev->new_chunk_sectors ||
mddev->layout != mddev->new_layout ||
mddev->level != mddev->new_level) {
mddev->new_chunk_sectors = mddev->chunk_sectors;
mddev->new_layout = mddev->layout;
mddev->new_level = mddev->level;
return -EINVAL;
}
if (!mddev_is_clustered(mddev)) {
err = md_allow_write(mddev);
if (err)
return err;
}
raid_disks = mddev->raid_disks + mddev->delta_disks;
if (raid_disks < conf->raid_disks) {
cnt=0;
for (d= 0; d < conf->raid_disks; d++)
if (conf->mirrors[d].rdev)
cnt++;
if (cnt > raid_disks)
return -EBUSY;
}
newpoolinfo = kmalloc(sizeof(*newpoolinfo), GFP_KERNEL);
if (!newpoolinfo)
return -ENOMEM;
newpoolinfo->mddev = mddev;
newpoolinfo->raid_disks = raid_disks * 2;
newpool = mempool_create(NR_RAID1_BIOS, r1bio_pool_alloc,
r1bio_pool_free, newpoolinfo);
if (!newpool) {
kfree(newpoolinfo);
return -ENOMEM;
}
newmirrors = kzalloc(sizeof(struct raid1_info) * raid_disks * 2,
GFP_KERNEL);
if (!newmirrors) {
kfree(newpoolinfo);
mempool_destroy(newpool);
return -ENOMEM;
}
freeze_array(conf, 0);
oldpool = conf->r1bio_pool;
conf->r1bio_pool = newpool;
for (d = d2 = 0; d < conf->raid_disks; d++) {
struct md_rdev *rdev = conf->mirrors[d].rdev;
if (rdev && rdev->raid_disk != d2) {
sysfs_unlink_rdev(mddev, rdev);
rdev->raid_disk = d2;
sysfs_unlink_rdev(mddev, rdev);
if (sysfs_link_rdev(mddev, rdev))
pr_warn("md/raid1:%s: cannot register rd%d\n",
mdname(mddev), rdev->raid_disk);
}
if (rdev)
newmirrors[d2++].rdev = rdev;
}
kfree(conf->mirrors);
conf->mirrors = newmirrors;
kfree(conf->poolinfo);
conf->poolinfo = newpoolinfo;
spin_lock_irqsave(&conf->device_lock, flags);
mddev->degraded += (raid_disks - conf->raid_disks);
spin_unlock_irqrestore(&conf->device_lock, flags);
conf->raid_disks = mddev->raid_disks = raid_disks;
mddev->delta_disks = 0;
unfreeze_array(conf);
set_bit(MD_RECOVERY_RECOVER, &mddev->recovery);
set_bit(MD_RECOVERY_NEEDED, &mddev->recovery);
md_wakeup_thread(mddev->thread);
mempool_destroy(oldpool);
return 0;
}
static void raid1_quiesce(struct mddev *mddev, int state)
{
struct r1conf *conf = mddev->private;
switch(state) {
case 2:
wake_up(&conf->wait_barrier);
break;
case 1:
freeze_array(conf, 0);
break;
case 0:
unfreeze_array(conf);
break;
}
}
static void *raid1_takeover(struct mddev *mddev)
{
if (mddev->level == 5 && mddev->raid_disks == 2) {
struct r1conf *conf;
mddev->new_level = 1;
mddev->new_layout = 0;
mddev->new_chunk_sectors = 0;
conf = setup_conf(mddev);
if (!IS_ERR(conf)) {
conf->array_frozen = 1;
mddev_clear_unsupported_flags(mddev,
UNSUPPORTED_MDDEV_FLAGS);
}
return conf;
}
return ERR_PTR(-EINVAL);
}
static int __init raid_init(void)
{
return register_md_personality(&raid1_personality);
}
static void raid_exit(void)
{
unregister_md_personality(&raid1_personality);
}
