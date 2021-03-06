void drbd_md_io_complete(struct bio *bio, int error)
{
struct drbd_md_io *md_io;
struct drbd_conf *mdev;
md_io = (struct drbd_md_io *)bio->bi_private;
mdev = container_of(md_io, struct drbd_conf, md_io);
md_io->error = error;
drbd_md_put_buffer(mdev);
md_io->done = 1;
wake_up(&mdev->misc_wait);
bio_put(bio);
put_ldev(mdev);
}
void drbd_endio_read_sec_final(struct drbd_epoch_entry *e) __releases(local)
{
unsigned long flags = 0;
struct drbd_conf *mdev = e->mdev;
D_ASSERT(e->block_id != ID_VACANT);
spin_lock_irqsave(&mdev->req_lock, flags);
mdev->read_cnt += e->size >> 9;
list_del(&e->w.list);
if (list_empty(&mdev->read_ee))
wake_up(&mdev->ee_wait);
if (test_bit(__EE_WAS_ERROR, &e->flags))
__drbd_chk_io_error(mdev, false);
spin_unlock_irqrestore(&mdev->req_lock, flags);
drbd_queue_work(&mdev->data.work, &e->w);
put_ldev(mdev);
}
static void drbd_endio_write_sec_final(struct drbd_epoch_entry *e) __releases(local)
{
unsigned long flags = 0;
struct drbd_conf *mdev = e->mdev;
sector_t e_sector;
int do_wake;
int is_syncer_req;
int do_al_complete_io;
D_ASSERT(e->block_id != ID_VACANT);
e_sector = e->sector;
do_al_complete_io = e->flags & EE_CALL_AL_COMPLETE_IO;
is_syncer_req = is_syncer_block_id(e->block_id);
spin_lock_irqsave(&mdev->req_lock, flags);
mdev->writ_cnt += e->size >> 9;
list_del(&e->w.list);
list_add_tail(&e->w.list, &mdev->done_ee);
do_wake = is_syncer_req
? list_empty(&mdev->sync_ee)
: list_empty(&mdev->active_ee);
if (test_bit(__EE_WAS_ERROR, &e->flags))
__drbd_chk_io_error(mdev, false);
spin_unlock_irqrestore(&mdev->req_lock, flags);
if (is_syncer_req)
drbd_rs_complete_io(mdev, e_sector);
if (do_wake)
wake_up(&mdev->ee_wait);
if (do_al_complete_io)
drbd_al_complete_io(mdev, e_sector);
wake_asender(mdev);
put_ldev(mdev);
}
void drbd_endio_sec(struct bio *bio, int error)
{
struct drbd_epoch_entry *e = bio->bi_private;
struct drbd_conf *mdev = e->mdev;
int uptodate = bio_flagged(bio, BIO_UPTODATE);
int is_write = bio_data_dir(bio) == WRITE;
if (error && __ratelimit(&drbd_ratelimit_state))
dev_warn(DEV, "%s: error=%d s=%llus\n",
is_write ? "write" : "read", error,
(unsigned long long)e->sector);
if (!error && !uptodate) {
if (__ratelimit(&drbd_ratelimit_state))
dev_warn(DEV, "%s: setting error to -EIO s=%llus\n",
is_write ? "write" : "read",
(unsigned long long)e->sector);
error = -EIO;
}
if (error)
set_bit(__EE_WAS_ERROR, &e->flags);
bio_put(bio);
if (atomic_dec_and_test(&e->pending_bios)) {
if (is_write)
drbd_endio_write_sec_final(e);
else
drbd_endio_read_sec_final(e);
}
}
void drbd_endio_pri(struct bio *bio, int error)
{
unsigned long flags;
struct drbd_request *req = bio->bi_private;
struct drbd_conf *mdev = req->mdev;
struct bio_and_error m;
enum drbd_req_event what;
int uptodate = bio_flagged(bio, BIO_UPTODATE);
if (!error && !uptodate) {
dev_warn(DEV, "p %s: setting error to -EIO\n",
bio_data_dir(bio) == WRITE ? "write" : "read");
error = -EIO;
}
if (unlikely(error)) {
what = (bio_data_dir(bio) == WRITE)
? write_completed_with_error
: (bio_rw(bio) == READ)
? read_completed_with_error
: read_ahead_completed_with_error;
} else
what = completed_ok;
bio_put(req->private_bio);
req->private_bio = ERR_PTR(error);
spin_lock_irqsave(&mdev->req_lock, flags);
__req_mod(req, what, &m);
spin_unlock_irqrestore(&mdev->req_lock, flags);
put_ldev(mdev);
if (m.bio)
complete_master_bio(mdev, &m);
}
int w_read_retry_remote(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
struct drbd_request *req = container_of(w, struct drbd_request, w);
spin_lock_irq(&mdev->req_lock);
if (cancel || mdev->state.pdsk != D_UP_TO_DATE) {
_req_mod(req, read_retry_remote_canceled);
spin_unlock_irq(&mdev->req_lock);
return 1;
}
spin_unlock_irq(&mdev->req_lock);
return w_send_read_req(mdev, w, 0);
}
void drbd_csum_ee(struct drbd_conf *mdev, struct crypto_hash *tfm, struct drbd_epoch_entry *e, void *digest)
{
struct hash_desc desc;
struct scatterlist sg;
struct page *page = e->pages;
struct page *tmp;
unsigned len;
desc.tfm = tfm;
desc.flags = 0;
sg_init_table(&sg, 1);
crypto_hash_init(&desc);
while ((tmp = page_chain_next(page))) {
sg_set_page(&sg, page, PAGE_SIZE, 0);
crypto_hash_update(&desc, &sg, sg.length);
page = tmp;
}
len = e->size & (PAGE_SIZE - 1);
sg_set_page(&sg, page, len ?: PAGE_SIZE, 0);
crypto_hash_update(&desc, &sg, sg.length);
crypto_hash_final(&desc, digest);
}
void drbd_csum_bio(struct drbd_conf *mdev, struct crypto_hash *tfm, struct bio *bio, void *digest)
{
struct hash_desc desc;
struct scatterlist sg;
struct bio_vec *bvec;
int i;
desc.tfm = tfm;
desc.flags = 0;
sg_init_table(&sg, 1);
crypto_hash_init(&desc);
bio_for_each_segment(bvec, bio, i) {
sg_set_page(&sg, bvec->bv_page, bvec->bv_len, bvec->bv_offset);
crypto_hash_update(&desc, &sg, sg.length);
}
crypto_hash_final(&desc, digest);
}
int w_e_send_csum(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
struct drbd_epoch_entry *e = container_of(w, struct drbd_epoch_entry, w);
int digest_size;
void *digest;
int ok = 1;
D_ASSERT(e->block_id == DRBD_MAGIC + 0xbeef);
if (unlikely(cancel))
goto out;
if (likely((e->flags & EE_WAS_ERROR) != 0))
goto out;
digest_size = crypto_hash_digestsize(mdev->csums_tfm);
digest = kmalloc(digest_size, GFP_NOIO);
if (digest) {
sector_t sector = e->sector;
unsigned int size = e->size;
drbd_csum_ee(mdev, mdev->csums_tfm, e, digest);
drbd_free_ee(mdev, e);
e = NULL;
inc_rs_pending(mdev);
ok = drbd_send_drequest_csum(mdev, sector, size,
digest, digest_size,
P_CSUM_RS_REQUEST);
kfree(digest);
} else {
dev_err(DEV, "kmalloc() of digest failed.\n");
ok = 0;
}
out:
if (e)
drbd_free_ee(mdev, e);
if (unlikely(!ok))
dev_err(DEV, "drbd_send_drequest(..., csum) failed\n");
return ok;
}
static int read_for_csum(struct drbd_conf *mdev, sector_t sector, int size)
{
struct drbd_epoch_entry *e;
if (!get_ldev(mdev))
return -EIO;
if (drbd_rs_should_slow_down(mdev, sector))
goto defer;
e = drbd_alloc_ee(mdev, DRBD_MAGIC+0xbeef, sector, size, GFP_TRY);
if (!e)
goto defer;
e->w.cb = w_e_send_csum;
spin_lock_irq(&mdev->req_lock);
list_add(&e->w.list, &mdev->read_ee);
spin_unlock_irq(&mdev->req_lock);
atomic_add(size >> 9, &mdev->rs_sect_ev);
if (drbd_submit_ee(mdev, e, READ, DRBD_FAULT_RS_RD) == 0)
return 0;
spin_lock_irq(&mdev->req_lock);
list_del(&e->w.list);
spin_unlock_irq(&mdev->req_lock);
drbd_free_ee(mdev, e);
defer:
put_ldev(mdev);
return -EAGAIN;
}
int w_resync_timer(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
switch (mdev->state.conn) {
case C_VERIFY_S:
w_make_ov_request(mdev, w, cancel);
break;
case C_SYNC_TARGET:
w_make_resync_request(mdev, w, cancel);
break;
}
return 1;
}
void resync_timer_fn(unsigned long data)
{
struct drbd_conf *mdev = (struct drbd_conf *) data;
if (list_empty(&mdev->resync_work.list))
drbd_queue_work(&mdev->data.work, &mdev->resync_work);
}
static void fifo_set(struct fifo_buffer *fb, int value)
{
int i;
for (i = 0; i < fb->size; i++)
fb->values[i] = value;
}
static int fifo_push(struct fifo_buffer *fb, int value)
{
int ov;
ov = fb->values[fb->head_index];
fb->values[fb->head_index++] = value;
if (fb->head_index >= fb->size)
fb->head_index = 0;
return ov;
}
static void fifo_add_val(struct fifo_buffer *fb, int value)
{
int i;
for (i = 0; i < fb->size; i++)
fb->values[i] += value;
}
static int drbd_rs_controller(struct drbd_conf *mdev)
{
unsigned int sect_in;
unsigned int want;
int req_sect;
int correction;
int cps;
int steps;
int curr_corr;
int max_sect;
sect_in = atomic_xchg(&mdev->rs_sect_in, 0);
mdev->rs_in_flight -= sect_in;
spin_lock(&mdev->peer_seq_lock);
steps = mdev->rs_plan_s.size;
if (mdev->rs_in_flight + sect_in == 0) {
want = ((mdev->sync_conf.rate * 2 * SLEEP_TIME) / HZ) * steps;
} else {
want = mdev->sync_conf.c_fill_target ? mdev->sync_conf.c_fill_target :
sect_in * mdev->sync_conf.c_delay_target * HZ / (SLEEP_TIME * 10);
}
correction = want - mdev->rs_in_flight - mdev->rs_planed;
cps = correction / steps;
fifo_add_val(&mdev->rs_plan_s, cps);
mdev->rs_planed += cps * steps;
curr_corr = fifo_push(&mdev->rs_plan_s, 0);
spin_unlock(&mdev->peer_seq_lock);
mdev->rs_planed -= curr_corr;
req_sect = sect_in + curr_corr;
if (req_sect < 0)
req_sect = 0;
max_sect = (mdev->sync_conf.c_max_rate * 2 * SLEEP_TIME) / HZ;
if (req_sect > max_sect)
req_sect = max_sect;
return req_sect;
}
static int drbd_rs_number_requests(struct drbd_conf *mdev)
{
int number;
if (mdev->rs_plan_s.size) {
number = drbd_rs_controller(mdev) >> (BM_BLOCK_SHIFT - 9);
mdev->c_sync_rate = number * HZ * (BM_BLOCK_SIZE / 1024) / SLEEP_TIME;
} else {
mdev->c_sync_rate = mdev->sync_conf.rate;
number = SLEEP_TIME * mdev->c_sync_rate / ((BM_BLOCK_SIZE / 1024) * HZ);
}
return number;
}
static int w_make_resync_request(struct drbd_conf *mdev,
struct drbd_work *w, int cancel)
{
unsigned long bit;
sector_t sector;
const sector_t capacity = drbd_get_capacity(mdev->this_bdev);
int max_bio_size;
int number, rollback_i, size;
int align, queued, sndbuf;
int i = 0;
if (unlikely(cancel))
return 1;
if (mdev->rs_total == 0) {
drbd_resync_finished(mdev);
return 1;
}
if (!get_ldev(mdev)) {
dev_err(DEV, "Disk broke down during resync!\n");
return 1;
}
max_bio_size = queue_max_hw_sectors(mdev->rq_queue) << 9;
number = drbd_rs_number_requests(mdev);
if (number == 0)
goto requeue;
for (i = 0; i < number; i++) {
mutex_lock(&mdev->data.mutex);
if (mdev->data.socket) {
queued = mdev->data.socket->sk->sk_wmem_queued;
sndbuf = mdev->data.socket->sk->sk_sndbuf;
} else {
queued = 1;
sndbuf = 0;
}
mutex_unlock(&mdev->data.mutex);
if (queued > sndbuf / 2)
goto requeue;
next_sector:
size = BM_BLOCK_SIZE;
bit = drbd_bm_find_next(mdev, mdev->bm_resync_fo);
if (bit == DRBD_END_OF_BITMAP) {
mdev->bm_resync_fo = drbd_bm_bits(mdev);
put_ldev(mdev);
return 1;
}
sector = BM_BIT_TO_SECT(bit);
if (drbd_rs_should_slow_down(mdev, sector) ||
drbd_try_rs_begin_io(mdev, sector)) {
mdev->bm_resync_fo = bit;
goto requeue;
}
mdev->bm_resync_fo = bit + 1;
if (unlikely(drbd_bm_test_bit(mdev, bit) == 0)) {
drbd_rs_complete_io(mdev, sector);
goto next_sector;
}
#if DRBD_MAX_BIO_SIZE > BM_BLOCK_SIZE
align = 1;
rollback_i = i;
for (;;) {
if (size + BM_BLOCK_SIZE > max_bio_size)
break;
if (sector & ((1<<(align+3))-1))
break;
if (((bit+1) & BM_BLOCKS_PER_BM_EXT_MASK) == 0)
break;
if (drbd_bm_test_bit(mdev, bit+1) != 1)
break;
bit++;
size += BM_BLOCK_SIZE;
if ((BM_BLOCK_SIZE << align) <= size)
align++;
i++;
}
if (size > BM_BLOCK_SIZE)
mdev->bm_resync_fo = bit + 1;
#endif
if (sector + (size>>9) > capacity)
size = (capacity-sector)<<9;
if (mdev->agreed_pro_version >= 89 && mdev->csums_tfm) {
switch (read_for_csum(mdev, sector, size)) {
case -EIO:
put_ldev(mdev);
return 0;
case -EAGAIN:
drbd_rs_complete_io(mdev, sector);
mdev->bm_resync_fo = BM_SECT_TO_BIT(sector);
i = rollback_i;
goto requeue;
case 0:
break;
default:
BUG();
}
} else {
inc_rs_pending(mdev);
if (!drbd_send_drequest(mdev, P_RS_DATA_REQUEST,
sector, size, ID_SYNCER)) {
dev_err(DEV, "drbd_send_drequest() failed, aborting...\n");
dec_rs_pending(mdev);
put_ldev(mdev);
return 0;
}
}
}
if (mdev->bm_resync_fo >= drbd_bm_bits(mdev)) {
put_ldev(mdev);
return 1;
}
requeue:
mdev->rs_in_flight += (i << (BM_BLOCK_SHIFT - 9));
mod_timer(&mdev->resync_timer, jiffies + SLEEP_TIME);
put_ldev(mdev);
return 1;
}
static int w_make_ov_request(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
int number, i, size;
sector_t sector;
const sector_t capacity = drbd_get_capacity(mdev->this_bdev);
if (unlikely(cancel))
return 1;
number = drbd_rs_number_requests(mdev);
sector = mdev->ov_position;
for (i = 0; i < number; i++) {
if (sector >= capacity) {
return 1;
}
size = BM_BLOCK_SIZE;
if (drbd_rs_should_slow_down(mdev, sector) ||
drbd_try_rs_begin_io(mdev, sector)) {
mdev->ov_position = sector;
goto requeue;
}
if (sector + (size>>9) > capacity)
size = (capacity-sector)<<9;
inc_rs_pending(mdev);
if (!drbd_send_ov_request(mdev, sector, size)) {
dec_rs_pending(mdev);
return 0;
}
sector += BM_SECT_PER_BIT;
}
mdev->ov_position = sector;
requeue:
mdev->rs_in_flight += (i << (BM_BLOCK_SHIFT - 9));
mod_timer(&mdev->resync_timer, jiffies + SLEEP_TIME);
return 1;
}
void start_resync_timer_fn(unsigned long data)
{
struct drbd_conf *mdev = (struct drbd_conf *) data;
drbd_queue_work(&mdev->data.work, &mdev->start_resync_work);
}
int w_start_resync(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
if (atomic_read(&mdev->unacked_cnt) || atomic_read(&mdev->rs_pending_cnt)) {
dev_warn(DEV, "w_start_resync later...\n");
mdev->start_resync_timer.expires = jiffies + HZ/10;
add_timer(&mdev->start_resync_timer);
return 1;
}
drbd_start_resync(mdev, C_SYNC_SOURCE);
clear_bit(AHEAD_TO_SYNC_SOURCE, &mdev->flags);
return 1;
}
int w_ov_finished(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
kfree(w);
ov_oos_print(mdev);
drbd_resync_finished(mdev);
return 1;
}
static int w_resync_finished(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
kfree(w);
drbd_resync_finished(mdev);
return 1;
}
static void ping_peer(struct drbd_conf *mdev)
{
clear_bit(GOT_PING_ACK, &mdev->flags);
request_ping(mdev);
wait_event(mdev->misc_wait,
test_bit(GOT_PING_ACK, &mdev->flags) || mdev->state.conn < C_CONNECTED);
}
int drbd_resync_finished(struct drbd_conf *mdev)
{
unsigned long db, dt, dbdt;
unsigned long n_oos;
union drbd_state os, ns;
struct drbd_work *w;
char *khelper_cmd = NULL;
int verify_done = 0;
if (drbd_rs_del_all(mdev)) {
schedule_timeout_interruptible(HZ / 10);
w = kmalloc(sizeof(struct drbd_work), GFP_ATOMIC);
if (w) {
w->cb = w_resync_finished;
drbd_queue_work(&mdev->data.work, w);
return 1;
}
dev_err(DEV, "Warn failed to drbd_rs_del_all() and to kmalloc(w).\n");
}
dt = (jiffies - mdev->rs_start - mdev->rs_paused) / HZ;
if (dt <= 0)
dt = 1;
db = mdev->rs_total;
dbdt = Bit2KB(db/dt);
mdev->rs_paused /= HZ;
if (!get_ldev(mdev))
goto out;
ping_peer(mdev);
spin_lock_irq(&mdev->req_lock);
os = mdev->state;
verify_done = (os.conn == C_VERIFY_S || os.conn == C_VERIFY_T);
if (os.conn <= C_CONNECTED)
goto out_unlock;
ns = os;
ns.conn = C_CONNECTED;
dev_info(DEV, "%s done (total %lu sec; paused %lu sec; %lu K/sec)\n",
verify_done ? "Online verify " : "Resync",
dt + mdev->rs_paused, mdev->rs_paused, dbdt);
n_oos = drbd_bm_total_weight(mdev);
if (os.conn == C_VERIFY_S || os.conn == C_VERIFY_T) {
if (n_oos) {
dev_alert(DEV, "Online verify found %lu %dk block out of sync!\n",
n_oos, Bit2KB(1));
khelper_cmd = "out-of-sync";
}
} else {
D_ASSERT((n_oos - mdev->rs_failed) == 0);
if (os.conn == C_SYNC_TARGET || os.conn == C_PAUSED_SYNC_T)
khelper_cmd = "after-resync-target";
if (mdev->csums_tfm && mdev->rs_total) {
const unsigned long s = mdev->rs_same_csum;
const unsigned long t = mdev->rs_total;
const int ratio =
(t == 0) ? 0 :
(t < 100000) ? ((s*100)/t) : (s/(t/100));
dev_info(DEV, "%u %% had equal checksums, eliminated: %luK; "
"transferred %luK total %luK\n",
ratio,
Bit2KB(mdev->rs_same_csum),
Bit2KB(mdev->rs_total - mdev->rs_same_csum),
Bit2KB(mdev->rs_total));
}
}
if (mdev->rs_failed) {
dev_info(DEV, " %lu failed blocks\n", mdev->rs_failed);
if (os.conn == C_SYNC_TARGET || os.conn == C_PAUSED_SYNC_T) {
ns.disk = D_INCONSISTENT;
ns.pdsk = D_UP_TO_DATE;
} else {
ns.disk = D_UP_TO_DATE;
ns.pdsk = D_INCONSISTENT;
}
} else {
ns.disk = D_UP_TO_DATE;
ns.pdsk = D_UP_TO_DATE;
if (os.conn == C_SYNC_TARGET || os.conn == C_PAUSED_SYNC_T) {
if (mdev->p_uuid) {
int i;
for (i = UI_BITMAP ; i <= UI_HISTORY_END ; i++)
_drbd_uuid_set(mdev, i, mdev->p_uuid[i]);
drbd_uuid_set(mdev, UI_BITMAP, mdev->ldev->md.uuid[UI_CURRENT]);
_drbd_uuid_set(mdev, UI_CURRENT, mdev->p_uuid[UI_CURRENT]);
} else {
dev_err(DEV, "mdev->p_uuid is NULL! BUG\n");
}
}
if (!(os.conn == C_VERIFY_S || os.conn == C_VERIFY_T)) {
drbd_uuid_set_bm(mdev, 0UL);
drbd_print_uuids(mdev, "updated UUIDs");
if (mdev->p_uuid) {
int i;
for (i = UI_CURRENT ; i <= UI_HISTORY_END ; i++)
mdev->p_uuid[i] = mdev->ldev->md.uuid[i];
}
}
}
_drbd_set_state(mdev, ns, CS_VERBOSE, NULL);
out_unlock:
spin_unlock_irq(&mdev->req_lock);
put_ldev(mdev);
out:
mdev->rs_total = 0;
mdev->rs_failed = 0;
mdev->rs_paused = 0;
if (verify_done)
mdev->ov_start_sector = 0;
drbd_md_sync(mdev);
if (khelper_cmd)
drbd_khelper(mdev, khelper_cmd);
return 1;
}
static void move_to_net_ee_or_free(struct drbd_conf *mdev, struct drbd_epoch_entry *e)
{
if (drbd_ee_has_active_page(e)) {
int i = (e->size + PAGE_SIZE -1) >> PAGE_SHIFT;
atomic_add(i, &mdev->pp_in_use_by_net);
atomic_sub(i, &mdev->pp_in_use);
spin_lock_irq(&mdev->req_lock);
list_add_tail(&e->w.list, &mdev->net_ee);
spin_unlock_irq(&mdev->req_lock);
wake_up(&drbd_pp_wait);
} else
drbd_free_ee(mdev, e);
}
int w_e_end_data_req(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
struct drbd_epoch_entry *e = container_of(w, struct drbd_epoch_entry, w);
int ok;
if (unlikely(cancel)) {
drbd_free_ee(mdev, e);
dec_unacked(mdev);
return 1;
}
if (likely((e->flags & EE_WAS_ERROR) == 0)) {
ok = drbd_send_block(mdev, P_DATA_REPLY, e);
} else {
if (__ratelimit(&drbd_ratelimit_state))
dev_err(DEV, "Sending NegDReply. sector=%llus.\n",
(unsigned long long)e->sector);
ok = drbd_send_ack(mdev, P_NEG_DREPLY, e);
}
dec_unacked(mdev);
move_to_net_ee_or_free(mdev, e);
if (unlikely(!ok))
dev_err(DEV, "drbd_send_block() failed\n");
return ok;
}
int w_e_end_rsdata_req(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
struct drbd_epoch_entry *e = container_of(w, struct drbd_epoch_entry, w);
int ok;
if (unlikely(cancel)) {
drbd_free_ee(mdev, e);
dec_unacked(mdev);
return 1;
}
if (get_ldev_if_state(mdev, D_FAILED)) {
drbd_rs_complete_io(mdev, e->sector);
put_ldev(mdev);
}
if (mdev->state.conn == C_AHEAD) {
ok = drbd_send_ack(mdev, P_RS_CANCEL, e);
} else if (likely((e->flags & EE_WAS_ERROR) == 0)) {
if (likely(mdev->state.pdsk >= D_INCONSISTENT)) {
inc_rs_pending(mdev);
ok = drbd_send_block(mdev, P_RS_DATA_REPLY, e);
} else {
if (__ratelimit(&drbd_ratelimit_state))
dev_err(DEV, "Not sending RSDataReply, "
"partner DISKLESS!\n");
ok = 1;
}
} else {
if (__ratelimit(&drbd_ratelimit_state))
dev_err(DEV, "Sending NegRSDReply. sector %llus.\n",
(unsigned long long)e->sector);
ok = drbd_send_ack(mdev, P_NEG_RS_DREPLY, e);
drbd_rs_failed_io(mdev, e->sector, e->size);
}
dec_unacked(mdev);
move_to_net_ee_or_free(mdev, e);
if (unlikely(!ok))
dev_err(DEV, "drbd_send_block() failed\n");
return ok;
}
int w_e_end_csum_rs_req(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
struct drbd_epoch_entry *e = container_of(w, struct drbd_epoch_entry, w);
struct digest_info *di;
int digest_size;
void *digest = NULL;
int ok, eq = 0;
if (unlikely(cancel)) {
drbd_free_ee(mdev, e);
dec_unacked(mdev);
return 1;
}
if (get_ldev(mdev)) {
drbd_rs_complete_io(mdev, e->sector);
put_ldev(mdev);
}
di = e->digest;
if (likely((e->flags & EE_WAS_ERROR) == 0)) {
if (mdev->csums_tfm) {
digest_size = crypto_hash_digestsize(mdev->csums_tfm);
D_ASSERT(digest_size == di->digest_size);
digest = kmalloc(digest_size, GFP_NOIO);
}
if (digest) {
drbd_csum_ee(mdev, mdev->csums_tfm, e, digest);
eq = !memcmp(digest, di->digest, digest_size);
kfree(digest);
}
if (eq) {
drbd_set_in_sync(mdev, e->sector, e->size);
mdev->rs_same_csum += e->size >> BM_BLOCK_SHIFT;
ok = drbd_send_ack(mdev, P_RS_IS_IN_SYNC, e);
} else {
inc_rs_pending(mdev);
e->block_id = ID_SYNCER;
e->flags &= ~EE_HAS_DIGEST;
kfree(di);
ok = drbd_send_block(mdev, P_RS_DATA_REPLY, e);
}
} else {
ok = drbd_send_ack(mdev, P_NEG_RS_DREPLY, e);
if (__ratelimit(&drbd_ratelimit_state))
dev_err(DEV, "Sending NegDReply. I guess it gets messy.\n");
}
dec_unacked(mdev);
move_to_net_ee_or_free(mdev, e);
if (unlikely(!ok))
dev_err(DEV, "drbd_send_block/ack() failed\n");
return ok;
}
int w_e_end_ov_req(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
struct drbd_epoch_entry *e = container_of(w, struct drbd_epoch_entry, w);
sector_t sector = e->sector;
unsigned int size = e->size;
int digest_size;
void *digest;
int ok = 1;
if (unlikely(cancel))
goto out;
digest_size = crypto_hash_digestsize(mdev->verify_tfm);
digest = kmalloc(digest_size, GFP_NOIO);
if (!digest) {
ok = 0;
goto out;
}
if (likely(!(e->flags & EE_WAS_ERROR)))
drbd_csum_ee(mdev, mdev->verify_tfm, e, digest);
else
memset(digest, 0, digest_size);
drbd_free_ee(mdev, e);
e = NULL;
inc_rs_pending(mdev);
ok = drbd_send_drequest_csum(mdev, sector, size,
digest, digest_size,
P_OV_REPLY);
if (!ok)
dec_rs_pending(mdev);
kfree(digest);
out:
if (e)
drbd_free_ee(mdev, e);
dec_unacked(mdev);
return ok;
}
void drbd_ov_oos_found(struct drbd_conf *mdev, sector_t sector, int size)
{
if (mdev->ov_last_oos_start + mdev->ov_last_oos_size == sector) {
mdev->ov_last_oos_size += size>>9;
} else {
mdev->ov_last_oos_start = sector;
mdev->ov_last_oos_size = size>>9;
}
drbd_set_out_of_sync(mdev, sector, size);
}
int w_e_end_ov_reply(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
struct drbd_epoch_entry *e = container_of(w, struct drbd_epoch_entry, w);
struct digest_info *di;
void *digest;
sector_t sector = e->sector;
unsigned int size = e->size;
int digest_size;
int ok, eq = 0;
if (unlikely(cancel)) {
drbd_free_ee(mdev, e);
dec_unacked(mdev);
return 1;
}
if (get_ldev(mdev)) {
drbd_rs_complete_io(mdev, e->sector);
put_ldev(mdev);
}
di = e->digest;
if (likely((e->flags & EE_WAS_ERROR) == 0)) {
digest_size = crypto_hash_digestsize(mdev->verify_tfm);
digest = kmalloc(digest_size, GFP_NOIO);
if (digest) {
drbd_csum_ee(mdev, mdev->verify_tfm, e, digest);
D_ASSERT(digest_size == di->digest_size);
eq = !memcmp(digest, di->digest, digest_size);
kfree(digest);
}
}
drbd_free_ee(mdev, e);
if (!eq)
drbd_ov_oos_found(mdev, sector, size);
else
ov_oos_print(mdev);
ok = drbd_send_ack_ex(mdev, P_OV_RESULT, sector, size,
eq ? ID_IN_SYNC : ID_OUT_OF_SYNC);
dec_unacked(mdev);
--mdev->ov_left;
if ((mdev->ov_left & 0x200) == 0x200)
drbd_advance_rs_marks(mdev, mdev->ov_left);
if (mdev->ov_left == 0) {
ov_oos_print(mdev);
drbd_resync_finished(mdev);
}
return ok;
}
int w_prev_work_done(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
struct drbd_wq_barrier *b = container_of(w, struct drbd_wq_barrier, w);
complete(&b->done);
return 1;
}
int w_send_barrier(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
struct drbd_tl_epoch *b = container_of(w, struct drbd_tl_epoch, w);
struct p_barrier *p = &mdev->data.sbuf.barrier;
int ok = 1;
spin_lock_irq(&mdev->req_lock);
if (w->cb != w_send_barrier || mdev->state.conn < C_CONNECTED)
cancel = 1;
spin_unlock_irq(&mdev->req_lock);
if (cancel)
return 1;
if (!drbd_get_data_sock(mdev))
return 0;
p->barrier = b->br_number;
ok = _drbd_send_cmd(mdev, mdev->data.socket, P_BARRIER,
(struct p_header80 *)p, sizeof(*p), 0);
drbd_put_data_sock(mdev);
return ok;
}
int w_send_write_hint(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
if (cancel)
return 1;
return drbd_send_short_cmd(mdev, P_UNPLUG_REMOTE);
}
int w_send_oos(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
struct drbd_request *req = container_of(w, struct drbd_request, w);
int ok;
if (unlikely(cancel)) {
req_mod(req, send_canceled);
return 1;
}
ok = drbd_send_oos(mdev, req);
req_mod(req, oos_handed_to_network);
return ok;
}
int w_send_dblock(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
struct drbd_request *req = container_of(w, struct drbd_request, w);
int ok;
if (unlikely(cancel)) {
req_mod(req, send_canceled);
return 1;
}
ok = drbd_send_dblock(mdev, req);
req_mod(req, ok ? handed_over_to_network : send_failed);
return ok;
}
int w_send_read_req(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
struct drbd_request *req = container_of(w, struct drbd_request, w);
int ok;
if (unlikely(cancel)) {
req_mod(req, send_canceled);
return 1;
}
ok = drbd_send_drequest(mdev, P_DATA_REQUEST, req->sector, req->size,
(unsigned long)req);
if (!ok) {
if (mdev->state.conn >= C_CONNECTED)
drbd_force_state(mdev, NS(conn, C_NETWORK_FAILURE));
}
req_mod(req, ok ? handed_over_to_network : send_failed);
return ok;
}
int w_restart_disk_io(struct drbd_conf *mdev, struct drbd_work *w, int cancel)
{
struct drbd_request *req = container_of(w, struct drbd_request, w);
if (bio_data_dir(req->master_bio) == WRITE && req->rq_state & RQ_IN_ACT_LOG)
drbd_al_begin_io(mdev, req->sector);
drbd_req_make_private_bio(req, req->master_bio);
req->private_bio->bi_bdev = mdev->ldev->backing_bdev;
generic_make_request(req->private_bio);
return 1;
}
static int _drbd_may_sync_now(struct drbd_conf *mdev)
{
struct drbd_conf *odev = mdev;
while (1) {
if (odev->sync_conf.after == -1)
return 1;
odev = minor_to_mdev(odev->sync_conf.after);
ERR_IF(!odev) return 1;
if ((odev->state.conn >= C_SYNC_SOURCE &&
odev->state.conn <= C_PAUSED_SYNC_T) ||
odev->state.aftr_isp || odev->state.peer_isp ||
odev->state.user_isp)
return 0;
}
}
static int _drbd_pause_after(struct drbd_conf *mdev)
{
struct drbd_conf *odev;
int i, rv = 0;
for (i = 0; i < minor_count; i++) {
odev = minor_to_mdev(i);
if (!odev)
continue;
if (odev->state.conn == C_STANDALONE && odev->state.disk == D_DISKLESS)
continue;
if (!_drbd_may_sync_now(odev))
rv |= (__drbd_set_state(_NS(odev, aftr_isp, 1), CS_HARD, NULL)
!= SS_NOTHING_TO_DO);
}
return rv;
}
static int _drbd_resume_next(struct drbd_conf *mdev)
{
struct drbd_conf *odev;
int i, rv = 0;
for (i = 0; i < minor_count; i++) {
odev = minor_to_mdev(i);
if (!odev)
continue;
if (odev->state.conn == C_STANDALONE && odev->state.disk == D_DISKLESS)
continue;
if (odev->state.aftr_isp) {
if (_drbd_may_sync_now(odev))
rv |= (__drbd_set_state(_NS(odev, aftr_isp, 0),
CS_HARD, NULL)
!= SS_NOTHING_TO_DO) ;
}
}
return rv;
}
void resume_next_sg(struct drbd_conf *mdev)
{
write_lock_irq(&global_state_lock);
_drbd_resume_next(mdev);
write_unlock_irq(&global_state_lock);
}
void suspend_other_sg(struct drbd_conf *mdev)
{
write_lock_irq(&global_state_lock);
_drbd_pause_after(mdev);
write_unlock_irq(&global_state_lock);
}
static int sync_after_error(struct drbd_conf *mdev, int o_minor)
{
struct drbd_conf *odev;
if (o_minor == -1)
return NO_ERROR;
if (o_minor < -1 || minor_to_mdev(o_minor) == NULL)
return ERR_SYNC_AFTER;
odev = minor_to_mdev(o_minor);
while (1) {
if (odev == mdev)
return ERR_SYNC_AFTER_CYCLE;
if (odev->sync_conf.after == -1)
return NO_ERROR;
odev = minor_to_mdev(odev->sync_conf.after);
}
}
int drbd_alter_sa(struct drbd_conf *mdev, int na)
{
int changes;
int retcode;
write_lock_irq(&global_state_lock);
retcode = sync_after_error(mdev, na);
if (retcode == NO_ERROR) {
mdev->sync_conf.after = na;
do {
changes = _drbd_pause_after(mdev);
changes |= _drbd_resume_next(mdev);
} while (changes);
}
write_unlock_irq(&global_state_lock);
return retcode;
}
void drbd_rs_controller_reset(struct drbd_conf *mdev)
{
atomic_set(&mdev->rs_sect_in, 0);
atomic_set(&mdev->rs_sect_ev, 0);
mdev->rs_in_flight = 0;
mdev->rs_planed = 0;
spin_lock(&mdev->peer_seq_lock);
fifo_set(&mdev->rs_plan_s, 0);
spin_unlock(&mdev->peer_seq_lock);
}
void drbd_start_resync(struct drbd_conf *mdev, enum drbd_conns side)
{
union drbd_state ns;
int r;
if (mdev->state.conn >= C_SYNC_SOURCE && mdev->state.conn < C_AHEAD) {
dev_err(DEV, "Resync already running!\n");
return;
}
if (mdev->state.conn < C_AHEAD) {
drbd_rs_cancel_all(mdev);
}
if (side == C_SYNC_TARGET) {
r = drbd_khelper(mdev, "before-resync-target");
r = (r >> 8) & 0xff;
if (r > 0) {
dev_info(DEV, "before-resync-target handler returned %d, "
"dropping connection.\n", r);
drbd_force_state(mdev, NS(conn, C_DISCONNECTING));
return;
}
} else {
r = drbd_khelper(mdev, "before-resync-source");
r = (r >> 8) & 0xff;
if (r > 0) {
if (r == 3) {
dev_info(DEV, "before-resync-source handler returned %d, "
"ignoring. Old userland tools?", r);
} else {
dev_info(DEV, "before-resync-source handler returned %d, "
"dropping connection.\n", r);
drbd_force_state(mdev, NS(conn, C_DISCONNECTING));
return;
}
}
}
drbd_state_lock(mdev);
write_lock_irq(&global_state_lock);
if (!get_ldev_if_state(mdev, D_NEGOTIATING)) {
write_unlock_irq(&global_state_lock);
drbd_state_unlock(mdev);
return;
}
ns.i = mdev->state.i;
ns.aftr_isp = !_drbd_may_sync_now(mdev);
ns.conn = side;
if (side == C_SYNC_TARGET)
ns.disk = D_INCONSISTENT;
else
ns.pdsk = D_INCONSISTENT;
r = __drbd_set_state(mdev, ns, CS_VERBOSE, NULL);
ns = mdev->state;
if (ns.conn < C_CONNECTED)
r = SS_UNKNOWN_ERROR;
if (r == SS_SUCCESS) {
unsigned long tw = drbd_bm_total_weight(mdev);
unsigned long now = jiffies;
int i;
mdev->rs_failed = 0;
mdev->rs_paused = 0;
mdev->rs_same_csum = 0;
mdev->rs_last_events = 0;
mdev->rs_last_sect_ev = 0;
mdev->rs_total = tw;
mdev->rs_start = now;
for (i = 0; i < DRBD_SYNC_MARKS; i++) {
mdev->rs_mark_left[i] = tw;
mdev->rs_mark_time[i] = now;
}
_drbd_pause_after(mdev);
}
write_unlock_irq(&global_state_lock);
if (r == SS_SUCCESS) {
dev_info(DEV, "Began resync as %s (will sync %lu KB [%lu bits set]).\n",
drbd_conn_str(ns.conn),
(unsigned long) mdev->rs_total << (BM_BLOCK_SHIFT-10),
(unsigned long) mdev->rs_total);
if (side == C_SYNC_TARGET)
mdev->bm_resync_fo = 0;
if (side == C_SYNC_SOURCE && mdev->agreed_pro_version < 96)
drbd_gen_and_send_sync_uuid(mdev);
if (mdev->agreed_pro_version < 95 && mdev->rs_total == 0) {
if (side == C_SYNC_SOURCE)
schedule_timeout_interruptible(
mdev->net_conf->ping_int * HZ +
mdev->net_conf->ping_timeo*HZ/9);
drbd_resync_finished(mdev);
}
drbd_rs_controller_reset(mdev);
if (ns.conn == C_SYNC_TARGET)
mod_timer(&mdev->resync_timer, jiffies);
drbd_md_sync(mdev);
}
put_ldev(mdev);
drbd_state_unlock(mdev);
}
int drbd_worker(struct drbd_thread *thi)
{
struct drbd_conf *mdev = thi->mdev;
struct drbd_work *w = NULL;
LIST_HEAD(work_list);
int intr = 0, i;
sprintf(current->comm, "drbd%d_worker", mdev_to_minor(mdev));
while (get_t_state(thi) == Running) {
drbd_thread_current_set_cpu(mdev);
if (down_trylock(&mdev->data.work.s)) {
mutex_lock(&mdev->data.mutex);
if (mdev->data.socket && !mdev->net_conf->no_cork)
drbd_tcp_uncork(mdev->data.socket);
mutex_unlock(&mdev->data.mutex);
intr = down_interruptible(&mdev->data.work.s);
mutex_lock(&mdev->data.mutex);
if (mdev->data.socket && !mdev->net_conf->no_cork)
drbd_tcp_cork(mdev->data.socket);
mutex_unlock(&mdev->data.mutex);
}
if (intr) {
D_ASSERT(intr == -EINTR);
flush_signals(current);
ERR_IF (get_t_state(thi) == Running)
continue;
break;
}
if (get_t_state(thi) != Running)
break;
w = NULL;
spin_lock_irq(&mdev->data.work.q_lock);
ERR_IF(list_empty(&mdev->data.work.q)) {
spin_unlock_irq(&mdev->data.work.q_lock);
continue;
}
w = list_entry(mdev->data.work.q.next, struct drbd_work, list);
list_del_init(&w->list);
spin_unlock_irq(&mdev->data.work.q_lock);
if (!w->cb(mdev, w, mdev->state.conn < C_CONNECTED)) {
if (mdev->state.conn >= C_CONNECTED)
drbd_force_state(mdev,
NS(conn, C_NETWORK_FAILURE));
}
}
D_ASSERT(test_bit(DEVICE_DYING, &mdev->flags));
D_ASSERT(test_bit(CONFIG_PENDING, &mdev->flags));
spin_lock_irq(&mdev->data.work.q_lock);
i = 0;
while (!list_empty(&mdev->data.work.q)) {
list_splice_init(&mdev->data.work.q, &work_list);
spin_unlock_irq(&mdev->data.work.q_lock);
while (!list_empty(&work_list)) {
w = list_entry(work_list.next, struct drbd_work, list);
list_del_init(&w->list);
w->cb(mdev, w, 1);
i++;
}
spin_lock_irq(&mdev->data.work.q_lock);
}
sema_init(&mdev->data.work.s, 0);
spin_unlock_irq(&mdev->data.work.q_lock);
D_ASSERT(mdev->state.disk == D_DISKLESS && mdev->state.conn == C_STANDALONE);
drbd_thread_stop(&mdev->receiver);
drbd_mdev_cleanup(mdev);
dev_info(DEV, "worker terminated\n");
clear_bit(DEVICE_DYING, &mdev->flags);
clear_bit(CONFIG_PENDING, &mdev->flags);
wake_up(&mdev->state_wait);
return 0;
}
