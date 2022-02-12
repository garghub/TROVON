static void _drbd_start_io_acct(struct drbd_device *device, struct drbd_request *req)
{
generic_start_io_acct(bio_data_dir(req->master_bio), req->i.size >> 9,
&device->vdisk->part0);
}
static void _drbd_end_io_acct(struct drbd_device *device, struct drbd_request *req)
{
generic_end_io_acct(bio_data_dir(req->master_bio),
&device->vdisk->part0, req->start_jif);
}
static struct drbd_request *drbd_req_new(struct drbd_device *device,
struct bio *bio_src)
{
struct drbd_request *req;
req = mempool_alloc(drbd_request_mempool, GFP_NOIO);
if (!req)
return NULL;
memset(req, 0, sizeof(*req));
drbd_req_make_private_bio(req, bio_src);
req->rq_state = bio_data_dir(bio_src) == WRITE ? RQ_WRITE : 0;
req->device = device;
req->master_bio = bio_src;
req->epoch = 0;
drbd_clear_interval(&req->i);
req->i.sector = bio_src->bi_iter.bi_sector;
req->i.size = bio_src->bi_iter.bi_size;
req->i.local = true;
req->i.waiting = false;
INIT_LIST_HEAD(&req->tl_requests);
INIT_LIST_HEAD(&req->w.list);
INIT_LIST_HEAD(&req->req_pending_master_completion);
INIT_LIST_HEAD(&req->req_pending_local);
atomic_set(&req->completion_ref, 1);
kref_init(&req->kref);
return req;
}
static void drbd_remove_request_interval(struct rb_root *root,
struct drbd_request *req)
{
struct drbd_device *device = req->device;
struct drbd_interval *i = &req->i;
drbd_remove_interval(root, i);
if (i->waiting)
wake_up(&device->misc_wait);
}
void drbd_req_destroy(struct kref *kref)
{
struct drbd_request *req = container_of(kref, struct drbd_request, kref);
struct drbd_device *device = req->device;
const unsigned s = req->rq_state;
if ((req->master_bio && !(s & RQ_POSTPONED)) ||
atomic_read(&req->completion_ref) ||
(s & RQ_LOCAL_PENDING) ||
((s & RQ_NET_MASK) && !(s & RQ_NET_DONE))) {
drbd_err(device, "drbd_req_destroy: Logic BUG rq_state = 0x%x, completion_ref = %d\n",
s, atomic_read(&req->completion_ref));
return;
}
list_del_init(&req->tl_requests);
if (!drbd_interval_empty(&req->i)) {
struct rb_root *root;
if (s & RQ_WRITE)
root = &device->write_requests;
else
root = &device->read_requests;
drbd_remove_request_interval(root, req);
} else if (s & (RQ_NET_MASK & ~RQ_NET_DONE) && req->i.size != 0)
drbd_err(device, "drbd_req_destroy: Logic BUG: interval empty, but: rq_state=0x%x, sect=%llu, size=%u\n",
s, (unsigned long long)req->i.sector, req->i.size);
if (s & RQ_WRITE) {
if ((s & (RQ_POSTPONED|RQ_LOCAL_MASK|RQ_NET_MASK)) != RQ_POSTPONED) {
if (!(s & RQ_NET_OK) || !(s & RQ_LOCAL_OK))
drbd_set_out_of_sync(device, req->i.sector, req->i.size);
if ((s & RQ_NET_OK) && (s & RQ_LOCAL_OK) && (s & RQ_NET_SIS))
drbd_set_in_sync(device, req->i.sector, req->i.size);
}
if (s & RQ_IN_ACT_LOG) {
if (get_ldev_if_state(device, D_FAILED)) {
drbd_al_complete_io(device, &req->i);
put_ldev(device);
} else if (__ratelimit(&drbd_ratelimit_state)) {
drbd_warn(device, "Should have called drbd_al_complete_io(, %llu, %u), "
"but my Disk seems to have failed :(\n",
(unsigned long long) req->i.sector, req->i.size);
}
}
}
mempool_free(req, drbd_request_mempool);
}
static void wake_all_senders(struct drbd_connection *connection)
{
wake_up(&connection->sender_work.q_wait);
}
void start_new_tl_epoch(struct drbd_connection *connection)
{
if (connection->current_tle_writes == 0)
return;
connection->current_tle_writes = 0;
atomic_inc(&connection->current_tle_nr);
wake_all_senders(connection);
}
void complete_master_bio(struct drbd_device *device,
struct bio_and_error *m)
{
m->bio->bi_error = m->error;
bio_endio(m->bio);
dec_ap_bio(device);
}
static
void drbd_req_complete(struct drbd_request *req, struct bio_and_error *m)
{
const unsigned s = req->rq_state;
struct drbd_device *device = req->device;
int rw;
int error, ok;
if ((s & RQ_LOCAL_PENDING && !(s & RQ_LOCAL_ABORTED)) ||
(s & RQ_NET_QUEUED) || (s & RQ_NET_PENDING) ||
(s & RQ_COMPLETION_SUSP)) {
drbd_err(device, "drbd_req_complete: Logic BUG rq_state = 0x%x\n", s);
return;
}
if (!req->master_bio) {
drbd_err(device, "drbd_req_complete: Logic BUG, master_bio == NULL!\n");
return;
}
rw = bio_rw(req->master_bio);
ok = (s & RQ_LOCAL_OK) || (s & RQ_NET_OK);
error = PTR_ERR(req->private_bio);
if (rw == WRITE &&
req->epoch == atomic_read(&first_peer_device(device)->connection->current_tle_nr))
start_new_tl_epoch(first_peer_device(device)->connection);
_drbd_end_io_acct(device, req);
if (!ok && rw == READ && !list_empty(&req->tl_requests))
req->rq_state |= RQ_POSTPONED;
if (!(req->rq_state & RQ_POSTPONED)) {
m->error = ok ? 0 : (error ?: -EIO);
m->bio = req->master_bio;
req->master_bio = NULL;
req->i.completed = true;
}
if (req->i.waiting)
wake_up(&device->misc_wait);
list_del_init(&req->req_pending_master_completion);
}
static int drbd_req_put_completion_ref(struct drbd_request *req, struct bio_and_error *m, int put)
{
struct drbd_device *device = req->device;
D_ASSERT(device, m || (req->rq_state & RQ_POSTPONED));
if (!atomic_sub_and_test(put, &req->completion_ref))
return 0;
drbd_req_complete(req, m);
if (req->rq_state & RQ_POSTPONED) {
drbd_restart_request(req);
return 0;
}
return 1;
}
static void set_if_null_req_next(struct drbd_peer_device *peer_device, struct drbd_request *req)
{
struct drbd_connection *connection = peer_device ? peer_device->connection : NULL;
if (!connection)
return;
if (connection->req_next == NULL)
connection->req_next = req;
}
static void advance_conn_req_next(struct drbd_peer_device *peer_device, struct drbd_request *req)
{
struct drbd_connection *connection = peer_device ? peer_device->connection : NULL;
if (!connection)
return;
if (connection->req_next != req)
return;
list_for_each_entry_continue(req, &connection->transfer_log, tl_requests) {
const unsigned s = req->rq_state;
if (s & RQ_NET_QUEUED)
break;
}
if (&req->tl_requests == &connection->transfer_log)
req = NULL;
connection->req_next = req;
}
static void set_if_null_req_ack_pending(struct drbd_peer_device *peer_device, struct drbd_request *req)
{
struct drbd_connection *connection = peer_device ? peer_device->connection : NULL;
if (!connection)
return;
if (connection->req_ack_pending == NULL)
connection->req_ack_pending = req;
}
static void advance_conn_req_ack_pending(struct drbd_peer_device *peer_device, struct drbd_request *req)
{
struct drbd_connection *connection = peer_device ? peer_device->connection : NULL;
if (!connection)
return;
if (connection->req_ack_pending != req)
return;
list_for_each_entry_continue(req, &connection->transfer_log, tl_requests) {
const unsigned s = req->rq_state;
if ((s & RQ_NET_SENT) && (s & RQ_NET_PENDING))
break;
}
if (&req->tl_requests == &connection->transfer_log)
req = NULL;
connection->req_ack_pending = req;
}
static void set_if_null_req_not_net_done(struct drbd_peer_device *peer_device, struct drbd_request *req)
{
struct drbd_connection *connection = peer_device ? peer_device->connection : NULL;
if (!connection)
return;
if (connection->req_not_net_done == NULL)
connection->req_not_net_done = req;
}
static void advance_conn_req_not_net_done(struct drbd_peer_device *peer_device, struct drbd_request *req)
{
struct drbd_connection *connection = peer_device ? peer_device->connection : NULL;
if (!connection)
return;
if (connection->req_not_net_done != req)
return;
list_for_each_entry_continue(req, &connection->transfer_log, tl_requests) {
const unsigned s = req->rq_state;
if ((s & RQ_NET_SENT) && !(s & RQ_NET_DONE))
break;
}
if (&req->tl_requests == &connection->transfer_log)
req = NULL;
connection->req_not_net_done = req;
}
static void mod_rq_state(struct drbd_request *req, struct bio_and_error *m,
int clear, int set)
{
struct drbd_device *device = req->device;
struct drbd_peer_device *peer_device = first_peer_device(device);
unsigned s = req->rq_state;
int c_put = 0;
int k_put = 0;
if (drbd_suspended(device) && !((s | clear) & RQ_COMPLETION_SUSP))
set |= RQ_COMPLETION_SUSP;
req->rq_state &= ~clear;
req->rq_state |= set;
if (req->rq_state == s)
return;
if (!(s & RQ_LOCAL_PENDING) && (set & RQ_LOCAL_PENDING))
atomic_inc(&req->completion_ref);
if (!(s & RQ_NET_PENDING) && (set & RQ_NET_PENDING)) {
inc_ap_pending(device);
atomic_inc(&req->completion_ref);
}
if (!(s & RQ_NET_QUEUED) && (set & RQ_NET_QUEUED)) {
atomic_inc(&req->completion_ref);
set_if_null_req_next(peer_device, req);
}
if (!(s & RQ_EXP_BARR_ACK) && (set & RQ_EXP_BARR_ACK))
kref_get(&req->kref);
if (!(s & RQ_NET_SENT) && (set & RQ_NET_SENT)) {
if (!(s & RQ_NET_DONE)) {
atomic_add(req->i.size >> 9, &device->ap_in_flight);
set_if_null_req_not_net_done(peer_device, req);
}
if (s & RQ_NET_PENDING)
set_if_null_req_ack_pending(peer_device, req);
}
if (!(s & RQ_COMPLETION_SUSP) && (set & RQ_COMPLETION_SUSP))
atomic_inc(&req->completion_ref);
if ((s & RQ_COMPLETION_SUSP) && (clear & RQ_COMPLETION_SUSP))
++c_put;
if (!(s & RQ_LOCAL_ABORTED) && (set & RQ_LOCAL_ABORTED)) {
D_ASSERT(device, req->rq_state & RQ_LOCAL_PENDING);
kref_get(&req->kref);
++c_put;
}
if ((s & RQ_LOCAL_PENDING) && (clear & RQ_LOCAL_PENDING)) {
if (req->rq_state & RQ_LOCAL_ABORTED)
++k_put;
else
++c_put;
list_del_init(&req->req_pending_local);
}
if ((s & RQ_NET_PENDING) && (clear & RQ_NET_PENDING)) {
dec_ap_pending(device);
++c_put;
req->acked_jif = jiffies;
advance_conn_req_ack_pending(peer_device, req);
}
if ((s & RQ_NET_QUEUED) && (clear & RQ_NET_QUEUED)) {
++c_put;
advance_conn_req_next(peer_device, req);
}
if (!(s & RQ_NET_DONE) && (set & RQ_NET_DONE)) {
if (s & RQ_NET_SENT)
atomic_sub(req->i.size >> 9, &device->ap_in_flight);
if (s & RQ_EXP_BARR_ACK)
++k_put;
req->net_done_jif = jiffies;
advance_conn_req_next(peer_device, req);
advance_conn_req_ack_pending(peer_device, req);
advance_conn_req_not_net_done(peer_device, req);
}
if (k_put || c_put) {
int at_least = k_put + !!c_put;
int refcount = atomic_read(&req->kref.refcount);
if (refcount < at_least)
drbd_err(device,
"mod_rq_state: Logic BUG: %x -> %x: refcount = %d, should be >= %d\n",
s, req->rq_state, refcount, at_least);
}
if (req->i.waiting)
wake_up(&device->misc_wait);
if (c_put)
k_put += drbd_req_put_completion_ref(req, m, c_put);
if (k_put)
kref_sub(&req->kref, k_put, drbd_req_destroy);
}
static void drbd_report_io_error(struct drbd_device *device, struct drbd_request *req)
{
char b[BDEVNAME_SIZE];
if (!__ratelimit(&drbd_ratelimit_state))
return;
drbd_warn(device, "local %s IO error sector %llu+%u on %s\n",
(req->rq_state & RQ_WRITE) ? "WRITE" : "READ",
(unsigned long long)req->i.sector,
req->i.size >> 9,
bdevname(device->ldev->backing_bdev, b));
}
static inline bool is_pending_write_protocol_A(struct drbd_request *req)
{
return (req->rq_state &
(RQ_WRITE|RQ_NET_PENDING|RQ_EXP_WRITE_ACK|RQ_EXP_RECEIVE_ACK))
== (RQ_WRITE|RQ_NET_PENDING);
}
int __req_mod(struct drbd_request *req, enum drbd_req_event what,
struct bio_and_error *m)
{
struct drbd_device *const device = req->device;
struct drbd_peer_device *const peer_device = first_peer_device(device);
struct drbd_connection *const connection = peer_device ? peer_device->connection : NULL;
struct net_conf *nc;
int p, rv = 0;
if (m)
m->bio = NULL;
switch (what) {
default:
drbd_err(device, "LOGIC BUG in %s:%u\n", __FILE__ , __LINE__);
break;
case TO_BE_SENT:
D_ASSERT(device, !(req->rq_state & RQ_NET_MASK));
rcu_read_lock();
nc = rcu_dereference(connection->net_conf);
p = nc->wire_protocol;
rcu_read_unlock();
req->rq_state |=
p == DRBD_PROT_C ? RQ_EXP_WRITE_ACK :
p == DRBD_PROT_B ? RQ_EXP_RECEIVE_ACK : 0;
mod_rq_state(req, m, 0, RQ_NET_PENDING);
break;
case TO_BE_SUBMITTED:
D_ASSERT(device, !(req->rq_state & RQ_LOCAL_MASK));
mod_rq_state(req, m, 0, RQ_LOCAL_PENDING);
break;
case COMPLETED_OK:
if (req->rq_state & RQ_WRITE)
device->writ_cnt += req->i.size >> 9;
else
device->read_cnt += req->i.size >> 9;
mod_rq_state(req, m, RQ_LOCAL_PENDING,
RQ_LOCAL_COMPLETED|RQ_LOCAL_OK);
break;
case ABORT_DISK_IO:
mod_rq_state(req, m, 0, RQ_LOCAL_ABORTED);
break;
case WRITE_COMPLETED_WITH_ERROR:
drbd_report_io_error(device, req);
__drbd_chk_io_error(device, DRBD_WRITE_ERROR);
mod_rq_state(req, m, RQ_LOCAL_PENDING, RQ_LOCAL_COMPLETED);
break;
case READ_COMPLETED_WITH_ERROR:
drbd_set_out_of_sync(device, req->i.sector, req->i.size);
drbd_report_io_error(device, req);
__drbd_chk_io_error(device, DRBD_READ_ERROR);
case READ_AHEAD_COMPLETED_WITH_ERROR:
mod_rq_state(req, m, RQ_LOCAL_PENDING, RQ_LOCAL_COMPLETED);
break;
case DISCARD_COMPLETED_NOTSUPP:
case DISCARD_COMPLETED_WITH_ERROR:
mod_rq_state(req, m, RQ_LOCAL_PENDING, RQ_LOCAL_COMPLETED);
break;
case QUEUE_FOR_NET_READ:
D_ASSERT(device, drbd_interval_empty(&req->i));
drbd_insert_interval(&device->read_requests, &req->i);
set_bit(UNPLUG_REMOTE, &device->flags);
D_ASSERT(device, req->rq_state & RQ_NET_PENDING);
D_ASSERT(device, (req->rq_state & RQ_LOCAL_MASK) == 0);
mod_rq_state(req, m, 0, RQ_NET_QUEUED);
req->w.cb = w_send_read_req;
drbd_queue_work(&connection->sender_work,
&req->w);
break;
case QUEUE_FOR_NET_WRITE:
D_ASSERT(device, drbd_interval_empty(&req->i));
drbd_insert_interval(&device->write_requests, &req->i);
set_bit(UNPLUG_REMOTE, &device->flags);
D_ASSERT(device, req->rq_state & RQ_NET_PENDING);
mod_rq_state(req, m, 0, RQ_NET_QUEUED|RQ_EXP_BARR_ACK);
req->w.cb = w_send_dblock;
drbd_queue_work(&connection->sender_work,
&req->w);
rcu_read_lock();
nc = rcu_dereference(connection->net_conf);
p = nc->max_epoch_size;
rcu_read_unlock();
if (connection->current_tle_writes >= p)
start_new_tl_epoch(connection);
break;
case QUEUE_FOR_SEND_OOS:
mod_rq_state(req, m, 0, RQ_NET_QUEUED);
req->w.cb = w_send_out_of_sync;
drbd_queue_work(&connection->sender_work,
&req->w);
break;
case READ_RETRY_REMOTE_CANCELED:
case SEND_CANCELED:
case SEND_FAILED:
mod_rq_state(req, m, RQ_NET_QUEUED, 0);
break;
case HANDED_OVER_TO_NETWORK:
if (is_pending_write_protocol_A(req))
mod_rq_state(req, m, RQ_NET_QUEUED|RQ_NET_PENDING,
RQ_NET_SENT|RQ_NET_OK);
else
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
D_ASSERT(device, req->rq_state & RQ_NET_PENDING);
D_ASSERT(device, req->rq_state & RQ_EXP_WRITE_ACK);
mod_rq_state(req, m, RQ_NET_PENDING, RQ_NET_DONE|RQ_NET_OK);
break;
case WRITE_ACKED_BY_PEER_AND_SIS:
req->rq_state |= RQ_NET_SIS;
case WRITE_ACKED_BY_PEER:
goto ack_common;
case RECV_ACKED_BY_PEER:
D_ASSERT(device, req->rq_state & RQ_EXP_RECEIVE_ACK);
ack_common:
mod_rq_state(req, m, RQ_NET_PENDING, RQ_NET_OK);
break;
case POSTPONE_WRITE:
D_ASSERT(device, req->rq_state & RQ_EXP_WRITE_ACK);
D_ASSERT(device, req->rq_state & RQ_NET_PENDING);
req->rq_state |= RQ_POSTPONED;
if (req->i.waiting)
wake_up(&device->misc_wait);
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
get_ldev(device);
req->w.cb = w_restart_disk_io;
drbd_queue_work(&connection->sender_work,
&req->w);
break;
case RESEND:
if (!(req->rq_state & RQ_WRITE) && !req->w.cb) {
mod_rq_state(req, m, RQ_COMPLETION_SUSP, 0);
break;
}
if (!(req->rq_state & RQ_NET_OK)) {
mod_rq_state(req, m, RQ_COMPLETION_SUSP, RQ_NET_QUEUED|RQ_NET_PENDING);
if (req->w.cb) {
drbd_queue_work(&connection->sender_work,
&req->w);
rv = req->rq_state & RQ_WRITE ? MR_WRITE : MR_READ;
}
break;
}
case BARRIER_ACKED:
if (!(req->rq_state & RQ_WRITE))
break;
if (req->rq_state & RQ_NET_PENDING) {
drbd_err(device, "FIXME (BARRIER_ACKED but pending)\n");
}
mod_rq_state(req, m, RQ_COMPLETION_SUSP,
(req->rq_state & RQ_NET_MASK) ? RQ_NET_DONE : 0);
break;
case DATA_RECEIVED:
D_ASSERT(device, req->rq_state & RQ_NET_PENDING);
mod_rq_state(req, m, RQ_NET_PENDING, RQ_NET_OK|RQ_NET_DONE);
break;
case QUEUE_AS_DRBD_BARRIER:
start_new_tl_epoch(connection);
mod_rq_state(req, m, 0, RQ_NET_OK|RQ_NET_DONE);
break;
};
return rv;
}
static bool drbd_may_do_local_read(struct drbd_device *device, sector_t sector, int size)
{
unsigned long sbnr, ebnr;
sector_t esector, nr_sectors;
if (device->state.disk == D_UP_TO_DATE)
return true;
if (device->state.disk != D_INCONSISTENT)
return false;
esector = sector + (size >> 9) - 1;
nr_sectors = drbd_get_capacity(device->this_bdev);
D_ASSERT(device, sector < nr_sectors);
D_ASSERT(device, esector < nr_sectors);
sbnr = BM_SECT_TO_BIT(sector);
ebnr = BM_SECT_TO_BIT(esector);
return drbd_bm_count_bits(device, sbnr, ebnr) == 0;
}
static bool remote_due_to_read_balancing(struct drbd_device *device, sector_t sector,
enum drbd_read_balancing rbm)
{
struct backing_dev_info *bdi;
int stripe_shift;
switch (rbm) {
case RB_CONGESTED_REMOTE:
bdi = &device->ldev->backing_bdev->bd_disk->queue->backing_dev_info;
return bdi_read_congested(bdi);
case RB_LEAST_PENDING:
return atomic_read(&device->local_cnt) >
atomic_read(&device->ap_pending_cnt) + atomic_read(&device->rs_pending_cnt);
case RB_32K_STRIPING:
case RB_64K_STRIPING:
case RB_128K_STRIPING:
case RB_256K_STRIPING:
case RB_512K_STRIPING:
case RB_1M_STRIPING:
stripe_shift = (rbm - RB_32K_STRIPING + 15);
return (sector >> (stripe_shift - 9)) & 1;
case RB_ROUND_ROBIN:
return test_and_change_bit(READ_BALANCE_RR, &device->flags);
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
struct drbd_device *device = req->device;
struct drbd_interval *i;
sector_t sector = req->i.sector;
int size = req->i.size;
i = drbd_find_overlap(&device->write_requests, sector, size);
if (!i)
return;
for (;;) {
prepare_to_wait(&device->misc_wait, &wait, TASK_UNINTERRUPTIBLE);
i = drbd_find_overlap(&device->write_requests, sector, size);
if (!i)
break;
i->waiting = true;
spin_unlock_irq(&device->resource->req_lock);
schedule();
spin_lock_irq(&device->resource->req_lock);
}
finish_wait(&device->misc_wait, &wait);
}
static void maybe_pull_ahead(struct drbd_device *device)
{
struct drbd_connection *connection = first_peer_device(device)->connection;
struct net_conf *nc;
bool congested = false;
enum drbd_on_congestion on_congestion;
rcu_read_lock();
nc = rcu_dereference(connection->net_conf);
on_congestion = nc ? nc->on_congestion : OC_BLOCK;
rcu_read_unlock();
if (on_congestion == OC_BLOCK ||
connection->agreed_pro_version < 96)
return;
if (on_congestion == OC_PULL_AHEAD && device->state.conn == C_AHEAD)
return;
if (!get_ldev_if_state(device, D_UP_TO_DATE))
return;
if (nc->cong_fill &&
atomic_read(&device->ap_in_flight) >= nc->cong_fill) {
drbd_info(device, "Congestion-fill threshold reached\n");
congested = true;
}
if (device->act_log->used >= nc->cong_extents) {
drbd_info(device, "Congestion-extents threshold reached\n");
congested = true;
}
if (congested) {
start_new_tl_epoch(first_peer_device(device)->connection);
if (on_congestion == OC_PULL_AHEAD)
_drbd_set_state(_NS(device, conn, C_AHEAD), 0, NULL);
else
_drbd_set_state(_NS(device, conn, C_DISCONNECTING), 0, NULL);
}
put_ldev(device);
}
static bool do_remote_read(struct drbd_request *req)
{
struct drbd_device *device = req->device;
enum drbd_read_balancing rbm;
if (req->private_bio) {
if (!drbd_may_do_local_read(device,
req->i.sector, req->i.size)) {
bio_put(req->private_bio);
req->private_bio = NULL;
put_ldev(device);
}
}
if (device->state.pdsk != D_UP_TO_DATE)
return false;
if (req->private_bio == NULL)
return true;
rcu_read_lock();
rbm = rcu_dereference(device->ldev->disk_conf)->read_balancing;
rcu_read_unlock();
if (rbm == RB_PREFER_LOCAL && req->private_bio)
return false;
if (remote_due_to_read_balancing(device, req->i.sector, rbm)) {
if (req->private_bio) {
bio_put(req->private_bio);
req->private_bio = NULL;
put_ldev(device);
}
return true;
}
return false;
}
static int drbd_process_write_request(struct drbd_request *req)
{
struct drbd_device *device = req->device;
int remote, send_oos;
remote = drbd_should_do_remote(device->state);
send_oos = drbd_should_send_out_of_sync(device->state);
if (unlikely(req->i.size == 0)) {
D_ASSERT(device, req->master_bio->bi_rw & REQ_FLUSH);
if (remote)
_req_mod(req, QUEUE_AS_DRBD_BARRIER);
return remote;
}
if (!remote && !send_oos)
return 0;
D_ASSERT(device, !(remote && send_oos));
if (remote) {
_req_mod(req, TO_BE_SENT);
_req_mod(req, QUEUE_FOR_NET_WRITE);
} else if (drbd_set_out_of_sync(device, req->i.sector, req->i.size))
_req_mod(req, QUEUE_FOR_SEND_OOS);
return remote;
}
static void
drbd_submit_req_private_bio(struct drbd_request *req)
{
struct drbd_device *device = req->device;
struct bio *bio = req->private_bio;
const int rw = bio_rw(bio);
bio->bi_bdev = device->ldev->backing_bdev;
if (get_ldev(device)) {
req->pre_submit_jif = jiffies;
if (drbd_insert_fault(device,
rw == WRITE ? DRBD_FAULT_DT_WR
: rw == READ ? DRBD_FAULT_DT_RD
: DRBD_FAULT_DT_RA))
bio_io_error(bio);
else
generic_make_request(bio);
put_ldev(device);
} else
bio_io_error(bio);
}
static void drbd_queue_write(struct drbd_device *device, struct drbd_request *req)
{
spin_lock_irq(&device->resource->req_lock);
list_add_tail(&req->tl_requests, &device->submit.writes);
list_add_tail(&req->req_pending_master_completion,
&device->pending_master_completion[1 ]);
spin_unlock_irq(&device->resource->req_lock);
queue_work(device->submit.wq, &device->submit.worker);
wake_up(&device->al_wait);
}
static struct drbd_request *
drbd_request_prepare(struct drbd_device *device, struct bio *bio, unsigned long start_jif)
{
const int rw = bio_data_dir(bio);
struct drbd_request *req;
req = drbd_req_new(device, bio);
if (!req) {
dec_ap_bio(device);
drbd_err(device, "could not kmalloc() req\n");
bio->bi_error = -ENOMEM;
bio_endio(bio);
return ERR_PTR(-ENOMEM);
}
req->start_jif = start_jif;
if (!get_ldev(device)) {
bio_put(req->private_bio);
req->private_bio = NULL;
}
_drbd_start_io_acct(device, req);
if (rw == WRITE && req->private_bio && req->i.size
&& !test_bit(AL_SUSPENDED, &device->flags)) {
if (!drbd_al_begin_io_fastpath(device, &req->i)) {
atomic_inc(&device->ap_actlog_cnt);
drbd_queue_write(device, req);
return NULL;
}
req->rq_state |= RQ_IN_ACT_LOG;
req->in_actlog_jif = jiffies;
}
return req;
}
static void drbd_send_and_submit(struct drbd_device *device, struct drbd_request *req)
{
struct drbd_resource *resource = device->resource;
const int rw = bio_rw(req->master_bio);
struct bio_and_error m = { NULL, };
bool no_remote = false;
bool submit_private_bio = false;
spin_lock_irq(&resource->req_lock);
if (rw == WRITE) {
complete_conflicting_writes(req);
maybe_pull_ahead(device);
}
if (drbd_suspended(device)) {
req->rq_state |= RQ_POSTPONED;
if (req->private_bio) {
bio_put(req->private_bio);
req->private_bio = NULL;
put_ldev(device);
}
goto out;
}
if (rw != WRITE) {
if (!do_remote_read(req) && !req->private_bio)
goto nodata;
}
req->epoch = atomic_read(&first_peer_device(device)->connection->current_tle_nr);
if (likely(req->i.size!=0)) {
if (rw == WRITE)
first_peer_device(device)->connection->current_tle_writes++;
list_add_tail(&req->tl_requests, &first_peer_device(device)->connection->transfer_log);
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
if (list_empty(&req->req_pending_master_completion))
list_add_tail(&req->req_pending_master_completion,
&device->pending_master_completion[rw == WRITE]);
if (req->private_bio) {
list_add_tail(&req->req_pending_local,
&device->pending_completion[rw == WRITE]);
_req_mod(req, TO_BE_SUBMITTED);
submit_private_bio = true;
} else if (no_remote) {
nodata:
if (__ratelimit(&drbd_ratelimit_state))
drbd_err(device, "IO ERROR: neither local nor remote data, sector %llu+%u\n",
(unsigned long long)req->i.sector, req->i.size >> 9);
}
out:
if (drbd_req_put_completion_ref(req, &m, 1))
kref_put(&req->kref, drbd_req_destroy);
spin_unlock_irq(&resource->req_lock);
if (submit_private_bio)
drbd_submit_req_private_bio(req);
if (m.bio)
complete_master_bio(device, &m);
}
void __drbd_make_request(struct drbd_device *device, struct bio *bio, unsigned long start_jif)
{
struct drbd_request *req = drbd_request_prepare(device, bio, start_jif);
if (IS_ERR_OR_NULL(req))
return;
drbd_send_and_submit(device, req);
}
static void submit_fast_path(struct drbd_device *device, struct list_head *incoming)
{
struct drbd_request *req, *tmp;
list_for_each_entry_safe(req, tmp, incoming, tl_requests) {
const int rw = bio_data_dir(req->master_bio);
if (rw == WRITE
&& req->private_bio && req->i.size
&& !test_bit(AL_SUSPENDED, &device->flags)) {
if (!drbd_al_begin_io_fastpath(device, &req->i))
continue;
req->rq_state |= RQ_IN_ACT_LOG;
req->in_actlog_jif = jiffies;
atomic_dec(&device->ap_actlog_cnt);
}
list_del_init(&req->tl_requests);
drbd_send_and_submit(device, req);
}
}
static bool prepare_al_transaction_nonblock(struct drbd_device *device,
struct list_head *incoming,
struct list_head *pending,
struct list_head *later)
{
struct drbd_request *req, *tmp;
int wake = 0;
int err;
spin_lock_irq(&device->al_lock);
list_for_each_entry_safe(req, tmp, incoming, tl_requests) {
err = drbd_al_begin_io_nonblock(device, &req->i);
if (err == -ENOBUFS)
break;
if (err == -EBUSY)
wake = 1;
if (err)
list_move_tail(&req->tl_requests, later);
else
list_move_tail(&req->tl_requests, pending);
}
spin_unlock_irq(&device->al_lock);
if (wake)
wake_up(&device->al_wait);
return !list_empty(pending);
}
void send_and_submit_pending(struct drbd_device *device, struct list_head *pending)
{
struct drbd_request *req, *tmp;
list_for_each_entry_safe(req, tmp, pending, tl_requests) {
req->rq_state |= RQ_IN_ACT_LOG;
req->in_actlog_jif = jiffies;
atomic_dec(&device->ap_actlog_cnt);
list_del_init(&req->tl_requests);
drbd_send_and_submit(device, req);
}
}
void do_submit(struct work_struct *ws)
{
struct drbd_device *device = container_of(ws, struct drbd_device, submit.worker);
LIST_HEAD(incoming);
LIST_HEAD(pending);
LIST_HEAD(busy);
spin_lock_irq(&device->resource->req_lock);
list_splice_tail_init(&device->submit.writes, &incoming);
spin_unlock_irq(&device->resource->req_lock);
for (;;) {
DEFINE_WAIT(wait);
list_splice_init(&busy, &incoming);
submit_fast_path(device, &incoming);
if (list_empty(&incoming))
break;
for (;;) {
prepare_to_wait(&device->al_wait, &wait, TASK_UNINTERRUPTIBLE);
list_splice_init(&busy, &incoming);
prepare_al_transaction_nonblock(device, &incoming, &pending, &busy);
if (!list_empty(&pending))
break;
schedule();
if (!list_empty(&incoming))
continue;
spin_lock_irq(&device->resource->req_lock);
list_splice_tail_init(&device->submit.writes, &incoming);
spin_unlock_irq(&device->resource->req_lock);
}
finish_wait(&device->al_wait, &wait);
while (list_empty(&incoming)) {
LIST_HEAD(more_pending);
LIST_HEAD(more_incoming);
bool made_progress;
if (list_empty(&device->submit.writes))
break;
spin_lock_irq(&device->resource->req_lock);
list_splice_tail_init(&device->submit.writes, &more_incoming);
spin_unlock_irq(&device->resource->req_lock);
if (list_empty(&more_incoming))
break;
made_progress = prepare_al_transaction_nonblock(device, &more_incoming, &more_pending, &busy);
list_splice_tail_init(&more_pending, &pending);
list_splice_tail_init(&more_incoming, &incoming);
if (!made_progress)
break;
}
drbd_al_begin_io_commit(device);
send_and_submit_pending(device, &pending);
}
}
void drbd_make_request(struct request_queue *q, struct bio *bio)
{
struct drbd_device *device = (struct drbd_device *) q->queuedata;
unsigned long start_jif;
blk_queue_split(q, &bio, q->bio_split);
start_jif = jiffies;
D_ASSERT(device, IS_ALIGNED(bio->bi_iter.bi_size, 512));
inc_ap_bio(device);
__drbd_make_request(device, bio, start_jif);
}
void request_timer_fn(unsigned long data)
{
struct drbd_device *device = (struct drbd_device *) data;
struct drbd_connection *connection = first_peer_device(device)->connection;
struct drbd_request *req_read, *req_write, *req_peer;
struct net_conf *nc;
unsigned long oldest_submit_jif;
unsigned long ent = 0, dt = 0, et, nt;
unsigned long now;
rcu_read_lock();
nc = rcu_dereference(connection->net_conf);
if (nc && device->state.conn >= C_WF_REPORT_PARAMS)
ent = nc->timeout * HZ/10 * nc->ko_count;
if (get_ldev(device)) {
dt = rcu_dereference(device->ldev->disk_conf)->disk_timeout * HZ / 10;
put_ldev(device);
}
rcu_read_unlock();
et = min_not_zero(dt, ent);
if (!et)
return;
now = jiffies;
nt = now + et;
spin_lock_irq(&device->resource->req_lock);
req_read = list_first_entry_or_null(&device->pending_completion[0], struct drbd_request, req_pending_local);
req_write = list_first_entry_or_null(&device->pending_completion[1], struct drbd_request, req_pending_local);
req_peer = connection->req_not_net_done;
if (!req_peer && connection->req_next && connection->req_next->pre_send_jif)
req_peer = connection->req_next;
if (req_peer && req_peer->device != device)
req_peer = NULL;
if (req_peer == NULL && req_write == NULL && req_read == NULL)
goto out;
oldest_submit_jif =
(req_write && req_read)
? ( time_before(req_write->pre_submit_jif, req_read->pre_submit_jif)
? req_write->pre_submit_jif : req_read->pre_submit_jif )
: req_write ? req_write->pre_submit_jif
: req_read ? req_read->pre_submit_jif : now;
if (ent && req_peer &&
time_after(now, req_peer->pre_send_jif + ent) &&
!time_in_range(now, connection->last_reconnect_jif, connection->last_reconnect_jif + ent)) {
drbd_warn(device, "Remote failed to finish a request within ko-count * timeout\n");
_conn_request_state(connection, NS(conn, C_TIMEOUT), CS_VERBOSE | CS_HARD);
}
if (dt && oldest_submit_jif != now &&
time_after(now, oldest_submit_jif + dt) &&
!time_in_range(now, device->last_reattach_jif, device->last_reattach_jif + dt)) {
drbd_warn(device, "Local backing device failed to meet the disk-timeout\n");
__drbd_chk_io_error(device, DRBD_FORCE_DETACH);
}
ent = (ent && req_peer && time_before(now, req_peer->pre_send_jif + ent))
? req_peer->pre_send_jif + ent : now + et;
dt = (dt && oldest_submit_jif != now && time_before(now, oldest_submit_jif + dt))
? oldest_submit_jif + dt : now + et;
nt = time_before(ent, dt) ? ent : dt;
out:
spin_unlock_irq(&device->resource->req_lock);
mod_timer(&device->request_timer, nt);
}
