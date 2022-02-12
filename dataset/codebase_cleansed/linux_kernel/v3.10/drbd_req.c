static void _drbd_start_io_acct(struct drbd_conf *mdev, struct drbd_request *req)
{
const int rw = bio_data_dir(req->master_bio);
int cpu;
cpu = part_stat_lock();
part_round_stats(cpu, &mdev->vdisk->part0);
part_stat_inc(cpu, &mdev->vdisk->part0, ios[rw]);
part_stat_add(cpu, &mdev->vdisk->part0, sectors[rw], req->i.size >> 9);
(void) cpu;
part_inc_in_flight(&mdev->vdisk->part0, rw);
part_stat_unlock();
}
static void _drbd_end_io_acct(struct drbd_conf *mdev, struct drbd_request *req)
{
int rw = bio_data_dir(req->master_bio);
unsigned long duration = jiffies - req->start_time;
int cpu;
cpu = part_stat_lock();
part_stat_add(cpu, &mdev->vdisk->part0, ticks[rw], duration);
part_round_stats(cpu, &mdev->vdisk->part0);
part_dec_in_flight(&mdev->vdisk->part0, rw);
part_stat_unlock();
}
static struct drbd_request *drbd_req_new(struct drbd_conf *mdev,
struct bio *bio_src)
{
struct drbd_request *req;
req = mempool_alloc(drbd_request_mempool, GFP_NOIO);
if (!req)
return NULL;
drbd_req_make_private_bio(req, bio_src);
req->rq_state = bio_data_dir(bio_src) == WRITE ? RQ_WRITE : 0;
req->w.mdev = mdev;
req->master_bio = bio_src;
req->epoch = 0;
drbd_clear_interval(&req->i);
req->i.sector = bio_src->bi_sector;
req->i.size = bio_src->bi_size;
req->i.local = true;
req->i.waiting = false;
INIT_LIST_HEAD(&req->tl_requests);
INIT_LIST_HEAD(&req->w.list);
atomic_set(&req->completion_ref, 1);
kref_init(&req->kref);
return req;
}
void drbd_req_destroy(struct kref *kref)
{
struct drbd_request *req = container_of(kref, struct drbd_request, kref);
struct drbd_conf *mdev = req->w.mdev;
const unsigned s = req->rq_state;
if ((req->master_bio && !(s & RQ_POSTPONED)) ||
atomic_read(&req->completion_ref) ||
(s & RQ_LOCAL_PENDING) ||
((s & RQ_NET_MASK) && !(s & RQ_NET_DONE))) {
dev_err(DEV, "drbd_req_destroy: Logic BUG rq_state = 0x%x, completion_ref = %d\n",
s, atomic_read(&req->completion_ref));
return;
}
list_del_init(&req->tl_requests);
if (s & RQ_WRITE) {
if ((s & (RQ_POSTPONED|RQ_LOCAL_MASK|RQ_NET_MASK)) != RQ_POSTPONED) {
if (!(s & RQ_NET_OK) || !(s & RQ_LOCAL_OK))
drbd_set_out_of_sync(mdev, req->i.sector, req->i.size);
if ((s & RQ_NET_OK) && (s & RQ_LOCAL_OK) && (s & RQ_NET_SIS))
drbd_set_in_sync(mdev, req->i.sector, req->i.size);
}
if (s & RQ_IN_ACT_LOG) {
if (get_ldev_if_state(mdev, D_FAILED)) {
drbd_al_complete_io(mdev, &req->i);
put_ldev(mdev);
} else if (__ratelimit(&drbd_ratelimit_state)) {
dev_warn(DEV, "Should have called drbd_al_complete_io(, %llu, %u), "
"but my Disk seems to have failed :(\n",
(unsigned long long) req->i.sector, req->i.size);
}
}
}
mempool_free(req, drbd_request_mempool);
}
static void wake_all_senders(struct drbd_tconn *tconn) {
wake_up(&tconn->sender_work.q_wait);
}
void start_new_tl_epoch(struct drbd_tconn *tconn)
{
if (tconn->current_tle_writes == 0)
return;
tconn->current_tle_writes = 0;
atomic_inc(&tconn->current_tle_nr);
wake_all_senders(tconn);
}
void complete_master_bio(struct drbd_conf *mdev,
struct bio_and_error *m)
{
bio_endio(m->bio, m->error);
dec_ap_bio(mdev);
}
static void drbd_remove_request_interval(struct rb_root *root,
struct drbd_request *req)
{
struct drbd_conf *mdev = req->w.mdev;
struct drbd_interval *i = &req->i;
drbd_remove_interval(root, i);
if (i->waiting)
wake_up(&mdev->misc_wait);
}
static
void drbd_req_complete(struct drbd_request *req, struct bio_and_error *m)
{
const unsigned s = req->rq_state;
struct drbd_conf *mdev = req->w.mdev;
int rw;
int error, ok;
if ((s & RQ_LOCAL_PENDING && !(s & RQ_LOCAL_ABORTED)) ||
(s & RQ_NET_QUEUED) || (s & RQ_NET_PENDING) ||
(s & RQ_COMPLETION_SUSP)) {
dev_err(DEV, "drbd_req_complete: Logic BUG rq_state = 0x%x\n", s);
return;
}
if (!req->master_bio) {
dev_err(DEV, "drbd_req_complete: Logic BUG, master_bio == NULL!\n");
return;
}
rw = bio_rw(req->master_bio);
ok = (s & RQ_LOCAL_OK) || (s & RQ_NET_OK);
error = PTR_ERR(req->private_bio);
if (!drbd_interval_empty(&req->i)) {
struct rb_root *root;
if (rw == WRITE)
root = &mdev->write_requests;
else
root = &mdev->read_requests;
drbd_remove_request_interval(root, req);
}
if (rw == WRITE &&
req->epoch == atomic_read(&mdev->tconn->current_tle_nr))
start_new_tl_epoch(mdev->tconn);
_drbd_end_io_acct(mdev, req);
if (!ok && rw == READ && !list_empty(&req->tl_requests))
req->rq_state |= RQ_POSTPONED;
if (!(req->rq_state & RQ_POSTPONED)) {
m->error = ok ? 0 : (error ?: -EIO);
m->bio = req->master_bio;
req->master_bio = NULL;
}
}
static int drbd_req_put_completion_ref(struct drbd_request *req, struct bio_and_error *m, int put)
{
struct drbd_conf *mdev = req->w.mdev;
D_ASSERT(m || (req->rq_state & RQ_POSTPONED));
if (!atomic_sub_and_test(put, &req->completion_ref))
return 0;
drbd_req_complete(req, m);
if (req->rq_state & RQ_POSTPONED) {
drbd_restart_request(req);
return 0;
}
return 1;
}
static void mod_rq_state(struct drbd_request *req, struct bio_and_error *m,
int clear, int set)
{
struct drbd_conf *mdev = req->w.mdev;
unsigned s = req->rq_state;
int c_put = 0;
int k_put = 0;
if (drbd_suspended(mdev) && !((s | clear) & RQ_COMPLETION_SUSP))
set |= RQ_COMPLETION_SUSP;
req->rq_state &= ~clear;
req->rq_state |= set;
if (req->rq_state == s)
return;
if (!(s & RQ_LOCAL_PENDING) && (set & RQ_LOCAL_PENDING))
atomic_inc(&req->completion_ref);
if (!(s & RQ_NET_PENDING) && (set & RQ_NET_PENDING)) {
inc_ap_pending(mdev);
atomic_inc(&req->completion_ref);
}
if (!(s & RQ_NET_QUEUED) && (set & RQ_NET_QUEUED))
atomic_inc(&req->completion_ref);
if (!(s & RQ_EXP_BARR_ACK) && (set & RQ_EXP_BARR_ACK))
kref_get(&req->kref);
if (!(s & RQ_NET_SENT) && (set & RQ_NET_SENT))
atomic_add(req->i.size >> 9, &mdev->ap_in_flight);
if (!(s & RQ_COMPLETION_SUSP) && (set & RQ_COMPLETION_SUSP))
atomic_inc(&req->completion_ref);
if ((s & RQ_COMPLETION_SUSP) && (clear & RQ_COMPLETION_SUSP))
++c_put;
if (!(s & RQ_LOCAL_ABORTED) && (set & RQ_LOCAL_ABORTED)) {
D_ASSERT(req->rq_state & RQ_LOCAL_PENDING);
kref_get(&req->kref);
++c_put;
}
if ((s & RQ_LOCAL_PENDING) && (clear & RQ_LOCAL_PENDING)) {
if (req->rq_state & RQ_LOCAL_ABORTED)
++k_put;
else
++c_put;
}
if ((s & RQ_NET_PENDING) && (clear & RQ_NET_PENDING)) {
dec_ap_pending(mdev);
++c_put;
}
if ((s & RQ_NET_QUEUED) && (clear & RQ_NET_QUEUED))
++c_put;
if ((s & RQ_EXP_BARR_ACK) && !(s & RQ_NET_DONE) && (set & RQ_NET_DONE)) {
if (req->rq_state & RQ_NET_SENT)
atomic_sub(req->i.size >> 9, &mdev->ap_in_flight);
++k_put;
}
if (k_put || c_put) {
int at_least = k_put + !!c_put;
int refcount = atomic_read(&req->kref.refcount);
if (refcount < at_least)
dev_err(DEV,
"mod_rq_state: Logic BUG: %x -> %x: refcount = %d, should be >= %d\n",
s, req->rq_state, refcount, at_least);
}
if (req->i.waiting)
wake_up(&mdev->misc_wait);
if (c_put)
k_put += drbd_req_put_completion_ref(req, m, c_put);
if (k_put)
kref_sub(&req->kref, k_put, drbd_req_destroy);
}
static void drbd_report_io_error(struct drbd_conf *mdev, struct drbd_request *req)
{
char b[BDEVNAME_SIZE];
if (!__ratelimit(&drbd_ratelimit_state))
return;
dev_warn(DEV, "local %s IO error sector %llu+%u on %s\n",
(req->rq_state & RQ_WRITE) ? "WRITE" : "READ",
(unsigned long long)req->i.sector,
req->i.size >> 9,
bdevname(mdev->ldev->backing_bdev, b));
}
int __req_mod(struct drbd_request *req, enum drbd_req_event what,
struct bio_and_error *m)
{
struct drbd_conf *mdev = req->w.mdev;
struct net_conf *nc;
int p, rv = 0;
if (m)
m->bio = NULL;
switch (what) {
default:
dev_err(DEV, "LOGIC BUG in %s:%u\n", __FILE__ , __LINE__);
break;
case TO_BE_SENT:
D_ASSERT(!(req->rq_state & RQ_NET_MASK));
rcu_read_lock();
nc = rcu_dereference(mdev->tconn->net_conf);
p = nc->wire_protocol;
rcu_read_unlock();
req->rq_state |=
p == DRBD_PROT_C ? RQ_EXP_WRITE_ACK :
p == DRBD_PROT_B ? RQ_EXP_RECEIVE_ACK : 0;
mod_rq_state(req, m, 0, RQ_NET_PENDING);
break;
case TO_BE_SUBMITTED:
D_ASSERT(!(req->rq_state & RQ_LOCAL_MASK));
mod_rq_state(req, m, 0, RQ_LOCAL_PENDING);
break;
case COMPLETED_OK:
if (req->rq_state & RQ_WRITE)
mdev->writ_cnt += req->i.size >> 9;
else
mdev->read_cnt += req->i.size >> 9;
mod_rq_state(req, m, RQ_LOCAL_PENDING,
RQ_LOCAL_COMPLETED|RQ_LOCAL_OK);
break;
case ABORT_DISK_IO:
mod_rq_state(req, m, 0, RQ_LOCAL_ABORTED);
break;
case WRITE_COMPLETED_WITH_ERROR:
drbd_report_io_error(mdev, req);
__drbd_chk_io_error(mdev, DRBD_WRITE_ERROR);
mod_rq_state(req, m, RQ_LOCAL_PENDING, RQ_LOCAL_COMPLETED);
break;
case READ_COMPLETED_WITH_ERROR:
drbd_set_out_of_sync(mdev, req->i.sector, req->i.size);
drbd_report_io_error(mdev, req);
__drbd_chk_io_error(mdev, DRBD_READ_ERROR);
case READ_AHEAD_COMPLETED_WITH_ERROR:
mod_rq_state(req, m, RQ_LOCAL_PENDING, RQ_LOCAL_COMPLETED);
break;
case QUEUE_FOR_NET_READ:
D_ASSERT(drbd_interval_empty(&req->i));
drbd_insert_interval(&mdev->read_requests, &req->i);
set_bit(UNPLUG_REMOTE, &mdev->flags);
D_ASSERT(req->rq_state & RQ_NET_PENDING);
D_ASSERT((req->rq_state & RQ_LOCAL_MASK) == 0);
mod_rq_state(req, m, 0, RQ_NET_QUEUED);
req->w.cb = w_send_read_req;
drbd_queue_work(&mdev->tconn->sender_work, &req->w);
break;
case QUEUE_FOR_NET_WRITE:
D_ASSERT(drbd_interval_empty(&req->i));
drbd_insert_interval(&mdev->write_requests, &req->i);
set_bit(UNPLUG_REMOTE, &mdev->flags);
D_ASSERT(req->rq_state & RQ_NET_PENDING);
mod_rq_state(req, m, 0, RQ_NET_QUEUED|RQ_EXP_BARR_ACK);
req->w.cb = w_send_dblock;
drbd_queue_work(&mdev->tconn->sender_work, &req->w);
rcu_read_lock();
nc = rcu_dereference(mdev->tconn->net_conf);
p = nc->max_epoch_size;
rcu_read_unlock();
if (mdev->tconn->current_tle_writes >= p)
start_new_tl_epoch(mdev->tconn);
break;
case QUEUE_FOR_SEND_OOS:
mod_rq_state(req, m, 0, RQ_NET_QUEUED);
req->w.cb = w_send_out_of_sync;
drbd_queue_work(&mdev->tconn->sender_work, &req->w);
break;
case READ_RETRY_REMOTE_CANCELED:
case SEND_CANCELED:
case SEND_FAILED:
mod_rq_state(req, m, RQ_NET_QUEUED, 0);
break;
case HANDED_OVER_TO_NETWORK:
if (bio_data_dir(req->master_bio) == WRITE &&
!(req->rq_state & (RQ_EXP_RECEIVE_ACK | RQ_EXP_WRITE_ACK))) {
if (req->rq_state & RQ_NET_PENDING)
mod_rq_state(req, m, RQ_NET_PENDING, RQ_NET_OK);
}
mod_rq_state(req, m, RQ_NET_QUEUED, RQ_NET_SENT);
break;
case OOS_HANDED_TO_NETWORK:
mod_rq_state(req, m, RQ_NET_QUEUED, RQ_NET_DONE);
break;
case CONNECTION_LOST_WHILE_PENDING:
mod_rq_state(req, m,
RQ_NET_OK|RQ_NET_PENDING|RQ_COMPLETION_SUSP,
RQ_NET_DONE);
break;
case CONFLICT_RESOLVED:
D_ASSERT(req->rq_state & RQ_NET_PENDING);
D_ASSERT(req->rq_state & RQ_EXP_WRITE_ACK);
mod_rq_state(req, m, RQ_NET_PENDING, RQ_NET_DONE|RQ_NET_OK);
break;
case WRITE_ACKED_BY_PEER_AND_SIS:
req->rq_state |= RQ_NET_SIS;
case WRITE_ACKED_BY_PEER:
D_ASSERT(req->rq_state & RQ_EXP_WRITE_ACK);
goto ack_common;
case RECV_ACKED_BY_PEER:
D_ASSERT(req->rq_state & RQ_EXP_RECEIVE_ACK);
ack_common:
D_ASSERT(req->rq_state & RQ_NET_PENDING);
mod_rq_state(req, m, RQ_NET_PENDING, RQ_NET_OK);
break;
case POSTPONE_WRITE:
D_ASSERT(req->rq_state & RQ_EXP_WRITE_ACK);
D_ASSERT(req->rq_state & RQ_NET_PENDING);
req->rq_state |= RQ_POSTPONED;
if (req->i.waiting)
wake_up(&mdev->misc_wait);
break;
case NEG_ACKED:
mod_rq_state(req, m, RQ_NET_OK|RQ_NET_PENDING, 0);
break;
case FAIL_FROZEN_DISK_IO:
if (!(req->rq_state & RQ_LOCAL_COMPLETED))
break;
mod_rq_state(req, m, RQ_COMPLETION_SUSP, 0);
break;
case RESTART_FROZEN_DISK_IO:
if (!(req->rq_state & RQ_LOCAL_COMPLETED))
break;
mod_rq_state(req, m,
RQ_COMPLETION_SUSP|RQ_LOCAL_COMPLETED,
RQ_LOCAL_PENDING);
rv = MR_READ;
if (bio_data_dir(req->master_bio) == WRITE)
rv = MR_WRITE;
get_ldev(mdev);
req->w.cb = w_restart_disk_io;
drbd_queue_work(&mdev->tconn->sender_work, &req->w);
break;
case RESEND:
if (!(req->rq_state & RQ_WRITE) && !req->w.cb) {
mod_rq_state(req, m, RQ_COMPLETION_SUSP, 0);
break;
}
if (!(req->rq_state & RQ_NET_OK)) {
mod_rq_state(req, m, RQ_COMPLETION_SUSP, RQ_NET_QUEUED|RQ_NET_PENDING);
if (req->w.cb) {
drbd_queue_work(&mdev->tconn->sender_work, &req->w);
rv = req->rq_state & RQ_WRITE ? MR_WRITE : MR_READ;
}
break;
}
case BARRIER_ACKED:
if (!(req->rq_state & RQ_WRITE))
break;
if (req->rq_state & RQ_NET_PENDING) {
dev_err(DEV, "FIXME (BARRIER_ACKED but pending)\n");
}
mod_rq_state(req, m, RQ_COMPLETION_SUSP,
(req->rq_state & RQ_NET_MASK) ? RQ_NET_DONE : 0);
break;
case DATA_RECEIVED:
D_ASSERT(req->rq_state & RQ_NET_PENDING);
mod_rq_state(req, m, RQ_NET_PENDING, RQ_NET_OK|RQ_NET_DONE);
break;
case QUEUE_AS_DRBD_BARRIER:
start_new_tl_epoch(mdev->tconn);
mod_rq_state(req, m, 0, RQ_NET_OK|RQ_NET_DONE);
break;
};
return rv;
}
static bool drbd_may_do_local_read(struct drbd_conf *mdev, sector_t sector, int size)
{
unsigned long sbnr, ebnr;
sector_t esector, nr_sectors;
if (mdev->state.disk == D_UP_TO_DATE)
return true;
if (mdev->state.disk != D_INCONSISTENT)
return false;
esector = sector + (size >> 9) - 1;
nr_sectors = drbd_get_capacity(mdev->this_bdev);
D_ASSERT(sector < nr_sectors);
D_ASSERT(esector < nr_sectors);
sbnr = BM_SECT_TO_BIT(sector);
ebnr = BM_SECT_TO_BIT(esector);
return drbd_bm_count_bits(mdev, sbnr, ebnr) == 0;
}
static bool remote_due_to_read_balancing(struct drbd_conf *mdev, sector_t sector,
enum drbd_read_balancing rbm)
{
struct backing_dev_info *bdi;
int stripe_shift;
switch (rbm) {
case RB_CONGESTED_REMOTE:
bdi = &mdev->ldev->backing_bdev->bd_disk->queue->backing_dev_info;
return bdi_read_congested(bdi);
case RB_LEAST_PENDING:
return atomic_read(&mdev->local_cnt) >
atomic_read(&mdev->ap_pending_cnt) + atomic_read(&mdev->rs_pending_cnt);
case RB_32K_STRIPING:
case RB_64K_STRIPING:
case RB_128K_STRIPING:
case RB_256K_STRIPING:
case RB_512K_STRIPING:
case RB_1M_STRIPING:
stripe_shift = (rbm - RB_32K_STRIPING + 15);
return (sector >> (stripe_shift - 9)) & 1;
case RB_ROUND_ROBIN:
return test_and_change_bit(READ_BALANCE_RR, &mdev->flags);
case RB_PREFER_REMOTE:
return true;
case RB_PREFER_LOCAL:
default:
return false;
}
}
static void complete_conflicting_writes(struct drbd_request *req)
{
DEFINE_WAIT(wait);
struct drbd_conf *mdev = req->w.mdev;
struct drbd_interval *i;
sector_t sector = req->i.sector;
int size = req->i.size;
i = drbd_find_overlap(&mdev->write_requests, sector, size);
if (!i)
return;
for (;;) {
prepare_to_wait(&mdev->misc_wait, &wait, TASK_UNINTERRUPTIBLE);
i = drbd_find_overlap(&mdev->write_requests, sector, size);
if (!i)
break;
i->waiting = true;
spin_unlock_irq(&mdev->tconn->req_lock);
schedule();
spin_lock_irq(&mdev->tconn->req_lock);
}
finish_wait(&mdev->misc_wait, &wait);
}
static void maybe_pull_ahead(struct drbd_conf *mdev)
{
struct drbd_tconn *tconn = mdev->tconn;
struct net_conf *nc;
bool congested = false;
enum drbd_on_congestion on_congestion;
rcu_read_lock();
nc = rcu_dereference(tconn->net_conf);
on_congestion = nc ? nc->on_congestion : OC_BLOCK;
rcu_read_unlock();
if (on_congestion == OC_BLOCK ||
tconn->agreed_pro_version < 96)
return;
if (!get_ldev_if_state(mdev, D_UP_TO_DATE))
return;
if (nc->cong_fill &&
atomic_read(&mdev->ap_in_flight) >= nc->cong_fill) {
dev_info(DEV, "Congestion-fill threshold reached\n");
congested = true;
}
if (mdev->act_log->used >= nc->cong_extents) {
dev_info(DEV, "Congestion-extents threshold reached\n");
congested = true;
}
if (congested) {
start_new_tl_epoch(mdev->tconn);
if (on_congestion == OC_PULL_AHEAD)
_drbd_set_state(_NS(mdev, conn, C_AHEAD), 0, NULL);
else
_drbd_set_state(_NS(mdev, conn, C_DISCONNECTING), 0, NULL);
}
put_ldev(mdev);
}
static bool do_remote_read(struct drbd_request *req)
{
struct drbd_conf *mdev = req->w.mdev;
enum drbd_read_balancing rbm;
if (req->private_bio) {
if (!drbd_may_do_local_read(mdev,
req->i.sector, req->i.size)) {
bio_put(req->private_bio);
req->private_bio = NULL;
put_ldev(mdev);
}
}
if (mdev->state.pdsk != D_UP_TO_DATE)
return false;
if (req->private_bio == NULL)
return true;
rcu_read_lock();
rbm = rcu_dereference(mdev->ldev->disk_conf)->read_balancing;
rcu_read_unlock();
if (rbm == RB_PREFER_LOCAL && req->private_bio)
return false;
if (remote_due_to_read_balancing(mdev, req->i.sector, rbm)) {
if (req->private_bio) {
bio_put(req->private_bio);
req->private_bio = NULL;
put_ldev(mdev);
}
return true;
}
return false;
}
static int drbd_process_write_request(struct drbd_request *req)
{
struct drbd_conf *mdev = req->w.mdev;
int remote, send_oos;
remote = drbd_should_do_remote(mdev->state);
send_oos = drbd_should_send_out_of_sync(mdev->state);
if (unlikely(req->i.size == 0)) {
D_ASSERT(req->master_bio->bi_rw & REQ_FLUSH);
if (remote)
_req_mod(req, QUEUE_AS_DRBD_BARRIER);
return remote;
}
if (!remote && !send_oos)
return 0;
D_ASSERT(!(remote && send_oos));
if (remote) {
_req_mod(req, TO_BE_SENT);
_req_mod(req, QUEUE_FOR_NET_WRITE);
} else if (drbd_set_out_of_sync(mdev, req->i.sector, req->i.size))
_req_mod(req, QUEUE_FOR_SEND_OOS);
return remote;
}
static void
drbd_submit_req_private_bio(struct drbd_request *req)
{
struct drbd_conf *mdev = req->w.mdev;
struct bio *bio = req->private_bio;
const int rw = bio_rw(bio);
bio->bi_bdev = mdev->ldev->backing_bdev;
if (get_ldev(mdev)) {
if (drbd_insert_fault(mdev,
rw == WRITE ? DRBD_FAULT_DT_WR
: rw == READ ? DRBD_FAULT_DT_RD
: DRBD_FAULT_DT_RA))
bio_endio(bio, -EIO);
else
generic_make_request(bio);
put_ldev(mdev);
} else
bio_endio(bio, -EIO);
}
static void drbd_queue_write(struct drbd_conf *mdev, struct drbd_request *req)
{
spin_lock(&mdev->submit.lock);
list_add_tail(&req->tl_requests, &mdev->submit.writes);
spin_unlock(&mdev->submit.lock);
queue_work(mdev->submit.wq, &mdev->submit.worker);
}
struct drbd_request *
drbd_request_prepare(struct drbd_conf *mdev, struct bio *bio, unsigned long start_time)
{
const int rw = bio_data_dir(bio);
struct drbd_request *req;
req = drbd_req_new(mdev, bio);
if (!req) {
dec_ap_bio(mdev);
dev_err(DEV, "could not kmalloc() req\n");
bio_endio(bio, -ENOMEM);
return ERR_PTR(-ENOMEM);
}
req->start_time = start_time;
if (!get_ldev(mdev)) {
bio_put(req->private_bio);
req->private_bio = NULL;
}
_drbd_start_io_acct(mdev, req);
if (rw == WRITE && req->private_bio && req->i.size
&& !test_bit(AL_SUSPENDED, &mdev->flags)) {
if (!drbd_al_begin_io_fastpath(mdev, &req->i)) {
drbd_queue_write(mdev, req);
return NULL;
}
req->rq_state |= RQ_IN_ACT_LOG;
}
return req;
}
static void drbd_send_and_submit(struct drbd_conf *mdev, struct drbd_request *req)
{
const int rw = bio_rw(req->master_bio);
struct bio_and_error m = { NULL, };
bool no_remote = false;
spin_lock_irq(&mdev->tconn->req_lock);
if (rw == WRITE) {
complete_conflicting_writes(req);
maybe_pull_ahead(mdev);
}
if (drbd_suspended(mdev)) {
req->rq_state |= RQ_POSTPONED;
if (req->private_bio) {
bio_put(req->private_bio);
req->private_bio = NULL;
put_ldev(mdev);
}
goto out;
}
if (rw != WRITE) {
if (!do_remote_read(req) && !req->private_bio)
goto nodata;
}
req->epoch = atomic_read(&mdev->tconn->current_tle_nr);
if (likely(req->i.size!=0)) {
if (rw == WRITE)
mdev->tconn->current_tle_writes++;
list_add_tail(&req->tl_requests, &mdev->tconn->transfer_log);
}
if (rw == WRITE) {
if (!drbd_process_write_request(req))
no_remote = true;
} else {
if (req->private_bio == NULL) {
_req_mod(req, TO_BE_SENT);
_req_mod(req, QUEUE_FOR_NET_READ);
} else
no_remote = true;
}
if (req->private_bio) {
_req_mod(req, TO_BE_SUBMITTED);
spin_unlock_irq(&mdev->tconn->req_lock);
drbd_submit_req_private_bio(req);
spin_lock_irq(&mdev->tconn->req_lock);
} else if (no_remote) {
nodata:
if (__ratelimit(&drbd_ratelimit_state))
dev_err(DEV, "IO ERROR: neither local nor remote data, sector %llu+%u\n",
(unsigned long long)req->i.sector, req->i.size >> 9);
}
out:
if (drbd_req_put_completion_ref(req, &m, 1))
kref_put(&req->kref, drbd_req_destroy);
spin_unlock_irq(&mdev->tconn->req_lock);
if (m.bio)
complete_master_bio(mdev, &m);
}
void __drbd_make_request(struct drbd_conf *mdev, struct bio *bio, unsigned long start_time)
{
struct drbd_request *req = drbd_request_prepare(mdev, bio, start_time);
if (IS_ERR_OR_NULL(req))
return;
drbd_send_and_submit(mdev, req);
}
static void submit_fast_path(struct drbd_conf *mdev, struct list_head *incoming)
{
struct drbd_request *req, *tmp;
list_for_each_entry_safe(req, tmp, incoming, tl_requests) {
const int rw = bio_data_dir(req->master_bio);
if (rw == WRITE
&& req->private_bio && req->i.size
&& !test_bit(AL_SUSPENDED, &mdev->flags)) {
if (!drbd_al_begin_io_fastpath(mdev, &req->i))
continue;
req->rq_state |= RQ_IN_ACT_LOG;
}
list_del_init(&req->tl_requests);
drbd_send_and_submit(mdev, req);
}
}
static bool prepare_al_transaction_nonblock(struct drbd_conf *mdev,
struct list_head *incoming,
struct list_head *pending)
{
struct drbd_request *req, *tmp;
int wake = 0;
int err;
spin_lock_irq(&mdev->al_lock);
list_for_each_entry_safe(req, tmp, incoming, tl_requests) {
err = drbd_al_begin_io_nonblock(mdev, &req->i);
if (err == -EBUSY)
wake = 1;
if (err)
continue;
req->rq_state |= RQ_IN_ACT_LOG;
list_move_tail(&req->tl_requests, pending);
}
spin_unlock_irq(&mdev->al_lock);
if (wake)
wake_up(&mdev->al_wait);
return !list_empty(pending);
}
void do_submit(struct work_struct *ws)
{
struct drbd_conf *mdev = container_of(ws, struct drbd_conf, submit.worker);
LIST_HEAD(incoming);
LIST_HEAD(pending);
struct drbd_request *req, *tmp;
for (;;) {
spin_lock(&mdev->submit.lock);
list_splice_tail_init(&mdev->submit.writes, &incoming);
spin_unlock(&mdev->submit.lock);
submit_fast_path(mdev, &incoming);
if (list_empty(&incoming))
break;
wait_event(mdev->al_wait, prepare_al_transaction_nonblock(mdev, &incoming, &pending));
for (;;) {
LIST_HEAD(more_pending);
LIST_HEAD(more_incoming);
bool made_progress;
if (list_empty(&mdev->submit.writes))
break;
spin_lock(&mdev->submit.lock);
list_splice_tail_init(&mdev->submit.writes, &more_incoming);
spin_unlock(&mdev->submit.lock);
if (list_empty(&more_incoming))
break;
made_progress = prepare_al_transaction_nonblock(mdev, &more_incoming, &more_pending);
list_splice_tail_init(&more_pending, &pending);
list_splice_tail_init(&more_incoming, &incoming);
if (!made_progress)
break;
}
drbd_al_begin_io_commit(mdev, false);
list_for_each_entry_safe(req, tmp, &pending, tl_requests) {
list_del_init(&req->tl_requests);
drbd_send_and_submit(mdev, req);
}
}
}
void drbd_make_request(struct request_queue *q, struct bio *bio)
{
struct drbd_conf *mdev = (struct drbd_conf *) q->queuedata;
unsigned long start_time;
start_time = jiffies;
D_ASSERT(IS_ALIGNED(bio->bi_size, 512));
inc_ap_bio(mdev);
__drbd_make_request(mdev, bio, start_time);
}
int drbd_merge_bvec(struct request_queue *q, struct bvec_merge_data *bvm, struct bio_vec *bvec)
{
struct drbd_conf *mdev = (struct drbd_conf *) q->queuedata;
unsigned int bio_size = bvm->bi_size;
int limit = DRBD_MAX_BIO_SIZE;
int backing_limit;
if (bio_size && get_ldev(mdev)) {
struct request_queue * const b =
mdev->ldev->backing_bdev->bd_disk->queue;
if (b->merge_bvec_fn) {
backing_limit = b->merge_bvec_fn(b, bvm, bvec);
limit = min(limit, backing_limit);
}
put_ldev(mdev);
}
return limit;
}
struct drbd_request *find_oldest_request(struct drbd_tconn *tconn)
{
struct drbd_request *r;
list_for_each_entry(r, &tconn->transfer_log, tl_requests) {
if (atomic_read(&r->completion_ref))
return r;
}
return NULL;
}
void request_timer_fn(unsigned long data)
{
struct drbd_conf *mdev = (struct drbd_conf *) data;
struct drbd_tconn *tconn = mdev->tconn;
struct drbd_request *req;
struct net_conf *nc;
unsigned long ent = 0, dt = 0, et, nt;
unsigned long now;
rcu_read_lock();
nc = rcu_dereference(tconn->net_conf);
if (nc && mdev->state.conn >= C_WF_REPORT_PARAMS)
ent = nc->timeout * HZ/10 * nc->ko_count;
if (get_ldev(mdev)) {
dt = rcu_dereference(mdev->ldev->disk_conf)->disk_timeout * HZ / 10;
put_ldev(mdev);
}
rcu_read_unlock();
et = min_not_zero(dt, ent);
if (!et)
return;
now = jiffies;
spin_lock_irq(&tconn->req_lock);
req = find_oldest_request(tconn);
if (!req) {
spin_unlock_irq(&tconn->req_lock);
mod_timer(&mdev->request_timer, now + et);
return;
}
if (ent && req->rq_state & RQ_NET_PENDING &&
time_after(now, req->start_time + ent) &&
!time_in_range(now, tconn->last_reconnect_jif, tconn->last_reconnect_jif + ent)) {
dev_warn(DEV, "Remote failed to finish a request within ko-count * timeout\n");
_drbd_set_state(_NS(mdev, conn, C_TIMEOUT), CS_VERBOSE | CS_HARD, NULL);
}
if (dt && req->rq_state & RQ_LOCAL_PENDING && req->w.mdev == mdev &&
time_after(now, req->start_time + dt) &&
!time_in_range(now, mdev->last_reattach_jif, mdev->last_reattach_jif + dt)) {
dev_warn(DEV, "Local backing device failed to meet the disk-timeout\n");
__drbd_chk_io_error(mdev, DRBD_FORCE_DETACH);
}
nt = (time_after(now, req->start_time + et) ? now : req->start_time) + et;
spin_unlock_irq(&tconn->req_lock);
mod_timer(&mdev->request_timer, nt);
}
