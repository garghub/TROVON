int drbd_khelper(struct drbd_conf *mdev, char *cmd)
{
char *envp[] = { "HOME=/",
"TERM=linux",
"PATH=/sbin:/usr/sbin:/bin:/usr/bin",
NULL,
NULL,
NULL };
char mb[12], af[20], ad[60], *afs;
char *argv[] = {usermode_helper, cmd, mb, NULL };
int ret;
if (current == mdev->worker.task)
set_bit(CALLBACK_PENDING, &mdev->flags);
snprintf(mb, 12, "minor-%d", mdev_to_minor(mdev));
if (get_net_conf(mdev)) {
switch (((struct sockaddr *)mdev->net_conf->peer_addr)->sa_family) {
case AF_INET6:
afs = "ipv6";
snprintf(ad, 60, "DRBD_PEER_ADDRESS=%pI6",
&((struct sockaddr_in6 *)mdev->net_conf->peer_addr)->sin6_addr);
break;
case AF_INET:
afs = "ipv4";
snprintf(ad, 60, "DRBD_PEER_ADDRESS=%pI4",
&((struct sockaddr_in *)mdev->net_conf->peer_addr)->sin_addr);
break;
default:
afs = "ssocks";
snprintf(ad, 60, "DRBD_PEER_ADDRESS=%pI4",
&((struct sockaddr_in *)mdev->net_conf->peer_addr)->sin_addr);
}
snprintf(af, 20, "DRBD_PEER_AF=%s", afs);
envp[3]=af;
envp[4]=ad;
put_net_conf(mdev);
}
drbd_md_sync(mdev);
dev_info(DEV, "helper command: %s %s %s\n", usermode_helper, cmd, mb);
drbd_bcast_ev_helper(mdev, cmd);
ret = call_usermodehelper(usermode_helper, argv, envp, UMH_WAIT_PROC);
if (ret)
dev_warn(DEV, "helper command: %s %s %s exit code %u (0x%x)\n",
usermode_helper, cmd, mb,
(ret >> 8) & 0xff, ret);
else
dev_info(DEV, "helper command: %s %s %s exit code %u (0x%x)\n",
usermode_helper, cmd, mb,
(ret >> 8) & 0xff, ret);
if (current == mdev->worker.task)
clear_bit(CALLBACK_PENDING, &mdev->flags);
if (ret < 0)
ret = 0;
return ret;
}
enum drbd_disk_state drbd_try_outdate_peer(struct drbd_conf *mdev)
{
char *ex_to_string;
int r;
enum drbd_disk_state nps;
enum drbd_fencing_p fp;
D_ASSERT(mdev->state.pdsk == D_UNKNOWN);
if (get_ldev_if_state(mdev, D_CONSISTENT)) {
fp = mdev->ldev->dc.fencing;
put_ldev(mdev);
} else {
dev_warn(DEV, "Not fencing peer, I'm not even Consistent myself.\n");
nps = mdev->state.pdsk;
goto out;
}
r = drbd_khelper(mdev, "fence-peer");
switch ((r>>8) & 0xff) {
case 3:
ex_to_string = "peer is inconsistent or worse";
nps = D_INCONSISTENT;
break;
case 4:
ex_to_string = "peer was fenced";
nps = D_OUTDATED;
break;
case 5:
if (mdev->state.disk == D_UP_TO_DATE) {
ex_to_string = "peer is unreachable, assumed to be dead";
nps = D_OUTDATED;
} else {
ex_to_string = "peer unreachable, doing nothing since disk != UpToDate";
nps = mdev->state.pdsk;
}
break;
case 6:
ex_to_string = "peer is active";
dev_warn(DEV, "Peer is primary, outdating myself.\n");
nps = D_UNKNOWN;
_drbd_request_state(mdev, NS(disk, D_OUTDATED), CS_WAIT_COMPLETE);
break;
case 7:
if (fp != FP_STONITH)
dev_err(DEV, "fence-peer() = 7 && fencing != Stonith !!!\n");
ex_to_string = "peer was stonithed";
nps = D_OUTDATED;
break;
default:
nps = D_UNKNOWN;
dev_err(DEV, "fence-peer helper broken, returned %d\n", (r>>8)&0xff);
return nps;
}
dev_info(DEV, "fence-peer helper returned %d (%s)\n",
(r>>8) & 0xff, ex_to_string);
out:
if (mdev->state.susp_fen && nps >= D_UNKNOWN) {
_drbd_request_state(mdev, NS(susp_fen, 0), CS_VERBOSE);
}
return nps;
}
static int _try_outdate_peer_async(void *data)
{
struct drbd_conf *mdev = (struct drbd_conf *)data;
enum drbd_disk_state nps;
union drbd_state ns;
nps = drbd_try_outdate_peer(mdev);
spin_lock_irq(&mdev->req_lock);
ns = mdev->state;
if (ns.conn < C_WF_REPORT_PARAMS && !test_bit(STATE_SENT, &mdev->flags)) {
ns.pdsk = nps;
_drbd_set_state(mdev, ns, CS_VERBOSE, NULL);
}
spin_unlock_irq(&mdev->req_lock);
return 0;
}
void drbd_try_outdate_peer_async(struct drbd_conf *mdev)
{
struct task_struct *opa;
opa = kthread_run(_try_outdate_peer_async, mdev, "drbd%d_a_helper", mdev_to_minor(mdev));
if (IS_ERR(opa))
dev_err(DEV, "out of mem, failed to invoke fence-peer helper\n");
}
enum drbd_state_rv
drbd_set_role(struct drbd_conf *mdev, enum drbd_role new_role, int force)
{
const int max_tries = 4;
enum drbd_state_rv rv = SS_UNKNOWN_ERROR;
int try = 0;
int forced = 0;
union drbd_state mask, val;
enum drbd_disk_state nps;
if (new_role == R_PRIMARY)
request_ping(mdev);
mutex_lock(&mdev->state_mutex);
mask.i = 0; mask.role = R_MASK;
val.i = 0; val.role = new_role;
while (try++ < max_tries) {
rv = _drbd_request_state(mdev, mask, val, CS_WAIT_COMPLETE);
if (rv == SS_CW_FAILED_BY_PEER && mask.pdsk != 0) {
val.pdsk = 0;
mask.pdsk = 0;
continue;
}
if (rv == SS_NO_UP_TO_DATE_DISK && force &&
(mdev->state.disk < D_UP_TO_DATE &&
mdev->state.disk >= D_INCONSISTENT)) {
mask.disk = D_MASK;
val.disk = D_UP_TO_DATE;
forced = 1;
continue;
}
if (rv == SS_NO_UP_TO_DATE_DISK &&
mdev->state.disk == D_CONSISTENT && mask.pdsk == 0) {
D_ASSERT(mdev->state.pdsk == D_UNKNOWN);
nps = drbd_try_outdate_peer(mdev);
if (nps == D_OUTDATED || nps == D_INCONSISTENT) {
val.disk = D_UP_TO_DATE;
mask.disk = D_MASK;
}
val.pdsk = nps;
mask.pdsk = D_MASK;
continue;
}
if (rv == SS_NOTHING_TO_DO)
goto fail;
if (rv == SS_PRIMARY_NOP && mask.pdsk == 0) {
nps = drbd_try_outdate_peer(mdev);
if (force && nps > D_OUTDATED) {
dev_warn(DEV, "Forced into split brain situation!\n");
nps = D_OUTDATED;
}
mask.pdsk = D_MASK;
val.pdsk = nps;
continue;
}
if (rv == SS_TWO_PRIMARIES) {
schedule_timeout_interruptible((mdev->net_conf->ping_timeo+1)*HZ/10);
if (try < max_tries)
try = max_tries - 1;
continue;
}
if (rv < SS_SUCCESS) {
rv = _drbd_request_state(mdev, mask, val,
CS_VERBOSE + CS_WAIT_COMPLETE);
if (rv < SS_SUCCESS)
goto fail;
}
break;
}
if (rv < SS_SUCCESS)
goto fail;
if (forced)
dev_warn(DEV, "Forced to consider local data as UpToDate!\n");
wait_event(mdev->misc_wait, atomic_read(&mdev->ap_pending_cnt) == 0);
if (new_role == R_SECONDARY) {
set_disk_ro(mdev->vdisk, true);
if (get_ldev(mdev)) {
mdev->ldev->md.uuid[UI_CURRENT] &= ~(u64)1;
put_ldev(mdev);
}
} else {
if (get_net_conf(mdev)) {
mdev->net_conf->want_lose = 0;
put_net_conf(mdev);
}
set_disk_ro(mdev->vdisk, false);
if (get_ldev(mdev)) {
if (((mdev->state.conn < C_CONNECTED ||
mdev->state.pdsk <= D_FAILED)
&& mdev->ldev->md.uuid[UI_BITMAP] == 0) || forced)
drbd_uuid_new_current(mdev);
mdev->ldev->md.uuid[UI_CURRENT] |= (u64)1;
put_ldev(mdev);
}
}
if (mdev->state.conn >= C_WF_REPORT_PARAMS) {
if (forced)
drbd_send_uuids(mdev);
drbd_send_current_state(mdev);
}
drbd_md_sync(mdev);
kobject_uevent(&disk_to_dev(mdev->vdisk)->kobj, KOBJ_CHANGE);
fail:
mutex_unlock(&mdev->state_mutex);
return rv;
}
static struct drbd_conf *ensure_mdev(int minor, int create)
{
struct drbd_conf *mdev;
if (minor >= minor_count)
return NULL;
mdev = minor_to_mdev(minor);
if (!mdev && create) {
struct gendisk *disk = NULL;
mdev = drbd_new_device(minor);
spin_lock_irq(&drbd_pp_lock);
if (minor_table[minor] == NULL) {
minor_table[minor] = mdev;
disk = mdev->vdisk;
mdev = NULL;
}
spin_unlock_irq(&drbd_pp_lock);
if (disk)
add_disk(disk);
else
drbd_free_mdev(mdev);
mdev = minor_to_mdev(minor);
}
return mdev;
}
static int drbd_nl_primary(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
struct primary primary_args;
memset(&primary_args, 0, sizeof(struct primary));
if (!primary_from_tags(mdev, nlp->tag_list, &primary_args)) {
reply->ret_code = ERR_MANDATORY_TAG;
return 0;
}
reply->ret_code =
drbd_set_role(mdev, R_PRIMARY, primary_args.primary_force);
return 0;
}
static int drbd_nl_secondary(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
reply->ret_code = drbd_set_role(mdev, R_SECONDARY, 0);
return 0;
}
static void drbd_md_set_sector_offsets(struct drbd_conf *mdev,
struct drbd_backing_dev *bdev)
{
sector_t md_size_sect = 0;
switch (bdev->dc.meta_dev_idx) {
default:
bdev->md.md_size_sect = MD_RESERVED_SECT;
bdev->md.md_offset = drbd_md_ss__(mdev, bdev);
bdev->md.al_offset = MD_AL_OFFSET;
bdev->md.bm_offset = MD_BM_OFFSET;
break;
case DRBD_MD_INDEX_FLEX_EXT:
bdev->md.md_size_sect = drbd_get_capacity(bdev->md_bdev);
bdev->md.md_offset = 0;
bdev->md.al_offset = MD_AL_OFFSET;
bdev->md.bm_offset = MD_BM_OFFSET;
break;
case DRBD_MD_INDEX_INTERNAL:
case DRBD_MD_INDEX_FLEX_INT:
bdev->md.md_offset = drbd_md_ss__(mdev, bdev);
bdev->md.al_offset = -MD_AL_MAX_SIZE;
md_size_sect = drbd_get_capacity(bdev->backing_bdev);
md_size_sect = ALIGN(md_size_sect, BM_SECT_PER_EXT);
md_size_sect = BM_SECT_TO_EXT(md_size_sect);
md_size_sect = ALIGN(md_size_sect, 8);
md_size_sect += MD_BM_OFFSET;
bdev->md.md_size_sect = md_size_sect;
bdev->md.bm_offset = -md_size_sect + MD_AL_OFFSET;
break;
}
}
char *ppsize(char *buf, unsigned long long size)
{
static char units[] = { 'K', 'M', 'G', 'T', 'P', 'E' };
int base = 0;
while (size >= 10000 && base < sizeof(units)-1) {
size = (size >> 10) + !!(size & (1<<9));
base++;
}
sprintf(buf, "%u %cB", (unsigned)size, units[base]);
return buf;
}
void drbd_suspend_io(struct drbd_conf *mdev)
{
set_bit(SUSPEND_IO, &mdev->flags);
if (is_susp(mdev->state))
return;
wait_event(mdev->misc_wait, !atomic_read(&mdev->ap_bio_cnt));
}
void drbd_resume_io(struct drbd_conf *mdev)
{
clear_bit(SUSPEND_IO, &mdev->flags);
wake_up(&mdev->misc_wait);
}
enum determine_dev_size drbd_determine_dev_size(struct drbd_conf *mdev, enum dds_flags flags) __must_hold(local)
{
sector_t prev_first_sect, prev_size;
sector_t la_size;
sector_t size;
char ppb[10];
int md_moved, la_size_changed;
enum determine_dev_size rv = unchanged;
drbd_suspend_io(mdev);
wait_event(mdev->al_wait, lc_try_lock(mdev->act_log));
prev_first_sect = drbd_md_first_sector(mdev->ldev);
prev_size = mdev->ldev->md.md_size_sect;
la_size = mdev->ldev->md.la_size_sect;
drbd_md_set_sector_offsets(mdev, mdev->ldev);
size = drbd_new_dev_size(mdev, mdev->ldev, flags & DDSF_FORCED);
if (drbd_get_capacity(mdev->this_bdev) != size ||
drbd_bm_capacity(mdev) != size) {
int err;
err = drbd_bm_resize(mdev, size, !(flags & DDSF_NO_RESYNC));
if (unlikely(err)) {
size = drbd_bm_capacity(mdev)>>1;
if (size == 0) {
dev_err(DEV, "OUT OF MEMORY! "
"Could not allocate bitmap!\n");
} else {
dev_err(DEV, "BM resizing failed. "
"Leaving size unchanged at size = %lu KB\n",
(unsigned long)size);
}
rv = dev_size_error;
}
drbd_set_my_capacity(mdev, size);
mdev->ldev->md.la_size_sect = size;
dev_info(DEV, "size = %s (%llu KB)\n", ppsize(ppb, size>>1),
(unsigned long long)size>>1);
}
if (rv == dev_size_error)
goto out;
la_size_changed = (la_size != mdev->ldev->md.la_size_sect);
md_moved = prev_first_sect != drbd_md_first_sector(mdev->ldev)
|| prev_size != mdev->ldev->md.md_size_sect;
if (la_size_changed || md_moved) {
int err;
drbd_al_shrink(mdev);
dev_info(DEV, "Writing the whole bitmap, %s\n",
la_size_changed && md_moved ? "size changed and md moved" :
la_size_changed ? "size changed" : "md moved");
err = drbd_bitmap_io(mdev, md_moved ? &drbd_bm_write_all : &drbd_bm_write,
"size changed", BM_LOCKED_MASK);
if (err) {
rv = dev_size_error;
goto out;
}
drbd_md_mark_dirty(mdev);
}
if (size > la_size)
rv = grew;
if (size < la_size)
rv = shrunk;
out:
lc_unlock(mdev->act_log);
wake_up(&mdev->al_wait);
drbd_resume_io(mdev);
return rv;
}
sector_t
drbd_new_dev_size(struct drbd_conf *mdev, struct drbd_backing_dev *bdev, int assume_peer_has_space)
{
sector_t p_size = mdev->p_size;
sector_t la_size = bdev->md.la_size_sect;
sector_t m_size;
sector_t u_size = bdev->dc.disk_size;
sector_t size = 0;
m_size = drbd_get_max_capacity(bdev);
if (mdev->state.conn < C_CONNECTED && assume_peer_has_space) {
dev_warn(DEV, "Resize while not connected was forced by the user!\n");
p_size = m_size;
}
if (p_size && m_size) {
size = min_t(sector_t, p_size, m_size);
} else {
if (la_size) {
size = la_size;
if (m_size && m_size < size)
size = m_size;
if (p_size && p_size < size)
size = p_size;
} else {
if (m_size)
size = m_size;
if (p_size)
size = p_size;
}
}
if (size == 0)
dev_err(DEV, "Both nodes diskless!\n");
if (u_size) {
if (u_size > size)
dev_err(DEV, "Requested disk size is too big (%lu > %lu)\n",
(unsigned long)u_size>>1, (unsigned long)size>>1);
else
size = u_size;
}
return size;
}
static int drbd_check_al_size(struct drbd_conf *mdev)
{
struct lru_cache *n, *t;
struct lc_element *e;
unsigned int in_use;
int i;
ERR_IF(mdev->sync_conf.al_extents < 7)
mdev->sync_conf.al_extents = 127;
if (mdev->act_log &&
mdev->act_log->nr_elements == mdev->sync_conf.al_extents)
return 0;
in_use = 0;
t = mdev->act_log;
n = lc_create("act_log", drbd_al_ext_cache,
mdev->sync_conf.al_extents, sizeof(struct lc_element), 0);
if (n == NULL) {
dev_err(DEV, "Cannot allocate act_log lru!\n");
return -ENOMEM;
}
spin_lock_irq(&mdev->al_lock);
if (t) {
for (i = 0; i < t->nr_elements; i++) {
e = lc_element_by_index(t, i);
if (e->refcnt)
dev_err(DEV, "refcnt(%d)==%d\n",
e->lc_number, e->refcnt);
in_use += e->refcnt;
}
}
if (!in_use)
mdev->act_log = n;
spin_unlock_irq(&mdev->al_lock);
if (in_use) {
dev_err(DEV, "Activity log still in use!\n");
lc_destroy(n);
return -EBUSY;
} else {
if (t)
lc_destroy(t);
}
drbd_md_mark_dirty(mdev);
return 0;
}
static void drbd_setup_queue_param(struct drbd_conf *mdev, unsigned int max_bio_size)
{
struct request_queue * const q = mdev->rq_queue;
unsigned int max_hw_sectors = max_bio_size >> 9;
unsigned int max_segments = 0;
if (get_ldev_if_state(mdev, D_ATTACHING)) {
struct request_queue * const b = mdev->ldev->backing_bdev->bd_disk->queue;
max_hw_sectors = min(queue_max_hw_sectors(b), max_bio_size >> 9);
max_segments = mdev->ldev->dc.max_bio_bvecs;
put_ldev(mdev);
}
blk_queue_logical_block_size(q, 512);
blk_queue_max_hw_sectors(q, max_hw_sectors);
blk_queue_max_segments(q, max_segments ? max_segments : BLK_MAX_SEGMENTS);
blk_queue_segment_boundary(q, PAGE_CACHE_SIZE-1);
if (get_ldev_if_state(mdev, D_ATTACHING)) {
struct request_queue * const b = mdev->ldev->backing_bdev->bd_disk->queue;
blk_queue_stack_limits(q, b);
if (q->backing_dev_info.ra_pages != b->backing_dev_info.ra_pages) {
dev_info(DEV, "Adjusting my ra_pages to backing device's (%lu -> %lu)\n",
q->backing_dev_info.ra_pages,
b->backing_dev_info.ra_pages);
q->backing_dev_info.ra_pages = b->backing_dev_info.ra_pages;
}
put_ldev(mdev);
}
}
void drbd_reconsider_max_bio_size(struct drbd_conf *mdev)
{
unsigned int now, new, local, peer;
now = queue_max_hw_sectors(mdev->rq_queue) << 9;
local = mdev->local_max_bio_size;
peer = mdev->peer_max_bio_size;
if (get_ldev_if_state(mdev, D_ATTACHING)) {
local = queue_max_hw_sectors(mdev->ldev->backing_bdev->bd_disk->queue) << 9;
mdev->local_max_bio_size = local;
put_ldev(mdev);
}
local = min(local, DRBD_MAX_BIO_SIZE);
if (mdev->state.conn >= C_CONNECTED) {
if (mdev->agreed_pro_version < 94) {
peer = min(mdev->peer_max_bio_size, DRBD_MAX_SIZE_H80_PACKET);
} else if (mdev->agreed_pro_version == 94)
peer = DRBD_MAX_SIZE_H80_PACKET;
else
peer = DRBD_MAX_BIO_SIZE;
}
new = min(local, peer);
if (mdev->state.role == R_PRIMARY && new < now)
dev_err(DEV, "ASSERT FAILED new < now; (%u < %u)\n", new, now);
if (new != now)
dev_info(DEV, "max BIO size = %u\n", new);
drbd_setup_queue_param(mdev, new);
}
static void drbd_reconfig_start(struct drbd_conf *mdev)
{
wait_event(mdev->state_wait, !test_and_set_bit(CONFIG_PENDING, &mdev->flags));
wait_event(mdev->state_wait, !test_bit(DEVICE_DYING, &mdev->flags));
drbd_thread_start(&mdev->worker);
drbd_flush_workqueue(mdev);
}
static void drbd_reconfig_done(struct drbd_conf *mdev)
{
spin_lock_irq(&mdev->req_lock);
if (mdev->state.disk == D_DISKLESS &&
mdev->state.conn == C_STANDALONE &&
mdev->state.role == R_SECONDARY) {
set_bit(DEVICE_DYING, &mdev->flags);
drbd_thread_stop_nowait(&mdev->worker);
} else
clear_bit(CONFIG_PENDING, &mdev->flags);
spin_unlock_irq(&mdev->req_lock);
wake_up(&mdev->state_wait);
}
static void drbd_suspend_al(struct drbd_conf *mdev)
{
int s = 0;
if (lc_try_lock(mdev->act_log)) {
drbd_al_shrink(mdev);
lc_unlock(mdev->act_log);
} else {
dev_warn(DEV, "Failed to lock al in drbd_suspend_al()\n");
return;
}
spin_lock_irq(&mdev->req_lock);
if (mdev->state.conn < C_CONNECTED)
s = !test_and_set_bit(AL_SUSPENDED, &mdev->flags);
spin_unlock_irq(&mdev->req_lock);
if (s)
dev_info(DEV, "Suspended AL updates\n");
}
static int drbd_nl_disk_conf(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
enum drbd_ret_code retcode;
enum determine_dev_size dd;
sector_t max_possible_sectors;
sector_t min_md_device_sectors;
struct drbd_backing_dev *nbc = NULL;
struct block_device *bdev;
struct lru_cache *resync_lru = NULL;
union drbd_state ns, os;
enum drbd_state_rv rv;
int cp_discovered = 0;
int logical_block_size;
drbd_reconfig_start(mdev);
if (mdev->state.disk > D_DISKLESS) {
retcode = ERR_DISK_CONFIGURED;
goto fail;
}
wait_event(mdev->misc_wait, !atomic_read(&mdev->local_cnt));
clear_bit(FORCE_DETACH, &mdev->flags);
mdev->rs_total = 0;
mdev->rs_failed = 0;
atomic_set(&mdev->rs_pending_cnt, 0);
nbc = kzalloc(sizeof(struct drbd_backing_dev), GFP_KERNEL);
if (!nbc) {
retcode = ERR_NOMEM;
goto fail;
}
nbc->dc.disk_size = DRBD_DISK_SIZE_SECT_DEF;
nbc->dc.on_io_error = DRBD_ON_IO_ERROR_DEF;
nbc->dc.fencing = DRBD_FENCING_DEF;
nbc->dc.max_bio_bvecs = DRBD_MAX_BIO_BVECS_DEF;
if (!disk_conf_from_tags(mdev, nlp->tag_list, &nbc->dc)) {
retcode = ERR_MANDATORY_TAG;
goto fail;
}
if (nbc->dc.meta_dev_idx < DRBD_MD_INDEX_FLEX_INT) {
retcode = ERR_MD_IDX_INVALID;
goto fail;
}
if (get_net_conf(mdev)) {
int prot = mdev->net_conf->wire_protocol;
put_net_conf(mdev);
if (nbc->dc.fencing == FP_STONITH && prot == DRBD_PROT_A) {
retcode = ERR_STONITH_AND_PROT_A;
goto fail;
}
}
bdev = blkdev_get_by_path(nbc->dc.backing_dev,
FMODE_READ | FMODE_WRITE | FMODE_EXCL, mdev);
if (IS_ERR(bdev)) {
dev_err(DEV, "open(\"%s\") failed with %ld\n", nbc->dc.backing_dev,
PTR_ERR(bdev));
retcode = ERR_OPEN_DISK;
goto fail;
}
nbc->backing_bdev = bdev;
bdev = blkdev_get_by_path(nbc->dc.meta_dev,
FMODE_READ | FMODE_WRITE | FMODE_EXCL,
(nbc->dc.meta_dev_idx < 0) ?
(void *)mdev : (void *)drbd_m_holder);
if (IS_ERR(bdev)) {
dev_err(DEV, "open(\"%s\") failed with %ld\n", nbc->dc.meta_dev,
PTR_ERR(bdev));
retcode = ERR_OPEN_MD_DISK;
goto fail;
}
nbc->md_bdev = bdev;
if ((nbc->backing_bdev == nbc->md_bdev) !=
(nbc->dc.meta_dev_idx == DRBD_MD_INDEX_INTERNAL ||
nbc->dc.meta_dev_idx == DRBD_MD_INDEX_FLEX_INT)) {
retcode = ERR_MD_IDX_INVALID;
goto fail;
}
resync_lru = lc_create("resync", drbd_bm_ext_cache,
61, sizeof(struct bm_extent),
offsetof(struct bm_extent, lce));
if (!resync_lru) {
retcode = ERR_NOMEM;
goto fail;
}
drbd_md_set_sector_offsets(mdev, nbc);
if (drbd_get_max_capacity(nbc) < nbc->dc.disk_size) {
dev_err(DEV, "max capacity %llu smaller than disk size %llu\n",
(unsigned long long) drbd_get_max_capacity(nbc),
(unsigned long long) nbc->dc.disk_size);
retcode = ERR_DISK_TOO_SMALL;
goto fail;
}
if (nbc->dc.meta_dev_idx < 0) {
max_possible_sectors = DRBD_MAX_SECTORS_FLEX;
min_md_device_sectors = (2<<10);
} else {
max_possible_sectors = DRBD_MAX_SECTORS;
min_md_device_sectors = MD_RESERVED_SECT * (nbc->dc.meta_dev_idx + 1);
}
if (drbd_get_capacity(nbc->md_bdev) < min_md_device_sectors) {
retcode = ERR_MD_DISK_TOO_SMALL;
dev_warn(DEV, "refusing attach: md-device too small, "
"at least %llu sectors needed for this meta-disk type\n",
(unsigned long long) min_md_device_sectors);
goto fail;
}
if (drbd_get_max_capacity(nbc) <
drbd_get_capacity(mdev->this_bdev)) {
retcode = ERR_DISK_TOO_SMALL;
goto fail;
}
nbc->known_size = drbd_get_capacity(nbc->backing_bdev);
if (nbc->known_size > max_possible_sectors) {
dev_warn(DEV, "==> truncating very big lower level device "
"to currently maximum possible %llu sectors <==\n",
(unsigned long long) max_possible_sectors);
if (nbc->dc.meta_dev_idx >= 0)
dev_warn(DEV, "==>> using internal or flexible "
"meta data may help <<==\n");
}
drbd_suspend_io(mdev);
wait_event(mdev->misc_wait, !atomic_read(&mdev->ap_pending_cnt) || is_susp(mdev->state));
drbd_flush_workqueue(mdev);
rv = _drbd_request_state(mdev, NS(disk, D_ATTACHING), CS_VERBOSE);
retcode = rv;
drbd_resume_io(mdev);
if (rv < SS_SUCCESS)
goto fail;
if (!get_ldev_if_state(mdev, D_ATTACHING))
goto force_diskless;
drbd_md_set_sector_offsets(mdev, nbc);
logical_block_size = bdev_logical_block_size(nbc->md_bdev);
if (logical_block_size == 0)
logical_block_size = MD_SECTOR_SIZE;
if (logical_block_size != MD_SECTOR_SIZE) {
if (!mdev->md_io_tmpp) {
struct page *page = alloc_page(GFP_NOIO);
if (!page)
goto force_diskless_dec;
dev_warn(DEV, "Meta data's bdev logical_block_size = %d != %d\n",
logical_block_size, MD_SECTOR_SIZE);
dev_warn(DEV, "Workaround engaged (has performance impact).\n");
mdev->md_io_tmpp = page;
}
}
if (!mdev->bitmap) {
if (drbd_bm_init(mdev)) {
retcode = ERR_NOMEM;
goto force_diskless_dec;
}
}
retcode = drbd_md_read(mdev, nbc);
if (retcode != NO_ERROR)
goto force_diskless_dec;
if (mdev->state.conn < C_CONNECTED &&
mdev->state.role == R_PRIMARY &&
(mdev->ed_uuid & ~((u64)1)) != (nbc->md.uuid[UI_CURRENT] & ~((u64)1))) {
dev_err(DEV, "Can only attach to data with current UUID=%016llX\n",
(unsigned long long)mdev->ed_uuid);
retcode = ERR_DATA_NOT_CURRENT;
goto force_diskless_dec;
}
if (drbd_check_al_size(mdev)) {
retcode = ERR_NOMEM;
goto force_diskless_dec;
}
if (drbd_md_test_flag(nbc, MDF_CONSISTENT) &&
drbd_new_dev_size(mdev, nbc, 0) < nbc->md.la_size_sect) {
dev_warn(DEV, "refusing to truncate a consistent device\n");
retcode = ERR_DISK_TOO_SMALL;
goto force_diskless_dec;
}
if (!drbd_al_read_log(mdev, nbc)) {
retcode = ERR_IO_MD_DISK;
goto force_diskless_dec;
}
if (nbc->dc.no_md_flush)
set_bit(MD_NO_FUA, &mdev->flags);
else
clear_bit(MD_NO_FUA, &mdev->flags);
D_ASSERT(mdev->ldev == NULL);
mdev->ldev = nbc;
mdev->resync = resync_lru;
nbc = NULL;
resync_lru = NULL;
mdev->write_ordering = WO_bdev_flush;
drbd_bump_write_ordering(mdev, WO_bdev_flush);
if (drbd_md_test_flag(mdev->ldev, MDF_CRASHED_PRIMARY))
set_bit(CRASHED_PRIMARY, &mdev->flags);
else
clear_bit(CRASHED_PRIMARY, &mdev->flags);
if (drbd_md_test_flag(mdev->ldev, MDF_PRIMARY_IND) &&
!(mdev->state.role == R_PRIMARY && mdev->state.susp_nod)) {
set_bit(CRASHED_PRIMARY, &mdev->flags);
cp_discovered = 1;
}
mdev->send_cnt = 0;
mdev->recv_cnt = 0;
mdev->read_cnt = 0;
mdev->writ_cnt = 0;
drbd_reconsider_max_bio_size(mdev);
clear_bit(USE_DEGR_WFC_T, &mdev->flags);
if (mdev->state.role != R_PRIMARY &&
drbd_md_test_flag(mdev->ldev, MDF_PRIMARY_IND) &&
!drbd_md_test_flag(mdev->ldev, MDF_CONNECTED_IND))
set_bit(USE_DEGR_WFC_T, &mdev->flags);
dd = drbd_determine_dev_size(mdev, 0);
if (dd == dev_size_error) {
retcode = ERR_NOMEM_BITMAP;
goto force_diskless_dec;
} else if (dd == grew)
set_bit(RESYNC_AFTER_NEG, &mdev->flags);
if (drbd_md_test_flag(mdev->ldev, MDF_FULL_SYNC)) {
dev_info(DEV, "Assuming that all blocks are out of sync "
"(aka FullSync)\n");
if (drbd_bitmap_io(mdev, &drbd_bmio_set_n_write,
"set_n_write from attaching", BM_LOCKED_MASK)) {
retcode = ERR_IO_MD_DISK;
goto force_diskless_dec;
}
} else {
if (drbd_bitmap_io(mdev, &drbd_bm_read,
"read from attaching", BM_LOCKED_MASK) < 0) {
retcode = ERR_IO_MD_DISK;
goto force_diskless_dec;
}
}
if (cp_discovered) {
drbd_al_apply_to_bm(mdev);
if (drbd_bitmap_io(mdev, &drbd_bm_write,
"crashed primary apply AL", BM_LOCKED_MASK)) {
retcode = ERR_IO_MD_DISK;
goto force_diskless_dec;
}
}
if (_drbd_bm_total_weight(mdev) == drbd_bm_bits(mdev))
drbd_suspend_al(mdev);
spin_lock_irq(&mdev->req_lock);
os = mdev->state;
ns.i = os.i;
if (drbd_md_test_flag(mdev->ldev, MDF_CONSISTENT)) {
if (drbd_md_test_flag(mdev->ldev, MDF_WAS_UP_TO_DATE))
ns.disk = D_CONSISTENT;
else
ns.disk = D_OUTDATED;
} else {
ns.disk = D_INCONSISTENT;
}
if (drbd_md_test_flag(mdev->ldev, MDF_PEER_OUT_DATED))
ns.pdsk = D_OUTDATED;
if ( ns.disk == D_CONSISTENT &&
(ns.pdsk == D_OUTDATED || mdev->ldev->dc.fencing == FP_DONT_CARE))
ns.disk = D_UP_TO_DATE;
if (mdev->state.conn == C_CONNECTED) {
mdev->new_state_tmp.i = ns.i;
ns.i = os.i;
ns.disk = D_NEGOTIATING;
kfree(mdev->p_uuid);
mdev->p_uuid = NULL;
}
rv = _drbd_set_state(mdev, ns, CS_VERBOSE, NULL);
ns = mdev->state;
spin_unlock_irq(&mdev->req_lock);
if (rv < SS_SUCCESS)
goto force_diskless_dec;
if (mdev->state.role == R_PRIMARY)
mdev->ldev->md.uuid[UI_CURRENT] |= (u64)1;
else
mdev->ldev->md.uuid[UI_CURRENT] &= ~(u64)1;
drbd_md_mark_dirty(mdev);
drbd_md_sync(mdev);
kobject_uevent(&disk_to_dev(mdev->vdisk)->kobj, KOBJ_CHANGE);
put_ldev(mdev);
reply->ret_code = retcode;
drbd_reconfig_done(mdev);
return 0;
force_diskless_dec:
put_ldev(mdev);
force_diskless:
drbd_force_state(mdev, NS(disk, D_FAILED));
drbd_md_sync(mdev);
fail:
if (nbc) {
if (nbc->backing_bdev)
blkdev_put(nbc->backing_bdev,
FMODE_READ | FMODE_WRITE | FMODE_EXCL);
if (nbc->md_bdev)
blkdev_put(nbc->md_bdev,
FMODE_READ | FMODE_WRITE | FMODE_EXCL);
kfree(nbc);
}
lc_destroy(resync_lru);
reply->ret_code = retcode;
drbd_reconfig_done(mdev);
return 0;
}
static int drbd_nl_detach(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
enum drbd_ret_code retcode;
int ret;
struct detach dt = {};
if (!detach_from_tags(mdev, nlp->tag_list, &dt)) {
reply->ret_code = ERR_MANDATORY_TAG;
goto out;
}
if (dt.detach_force) {
set_bit(FORCE_DETACH, &mdev->flags);
drbd_force_state(mdev, NS(disk, D_FAILED));
reply->ret_code = SS_SUCCESS;
goto out;
}
drbd_suspend_io(mdev);
drbd_md_get_buffer(mdev);
retcode = drbd_request_state(mdev, NS(disk, D_FAILED));
drbd_md_put_buffer(mdev);
ret = wait_event_interruptible(mdev->misc_wait,
mdev->state.disk != D_FAILED);
drbd_resume_io(mdev);
if ((int)retcode == (int)SS_IS_DISKLESS)
retcode = SS_NOTHING_TO_DO;
if (ret)
retcode = ERR_INTR;
reply->ret_code = retcode;
out:
return 0;
}
static int drbd_nl_net_conf(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
int i, ns;
enum drbd_ret_code retcode;
struct net_conf *new_conf = NULL;
struct crypto_hash *tfm = NULL;
struct crypto_hash *integrity_w_tfm = NULL;
struct crypto_hash *integrity_r_tfm = NULL;
struct hlist_head *new_tl_hash = NULL;
struct hlist_head *new_ee_hash = NULL;
struct drbd_conf *odev;
char hmac_name[CRYPTO_MAX_ALG_NAME];
void *int_dig_out = NULL;
void *int_dig_in = NULL;
void *int_dig_vv = NULL;
struct sockaddr *new_my_addr, *new_peer_addr, *taken_addr;
drbd_reconfig_start(mdev);
if (mdev->state.conn > C_STANDALONE) {
retcode = ERR_NET_CONFIGURED;
goto fail;
}
new_conf = kzalloc(sizeof(struct net_conf), GFP_KERNEL);
if (!new_conf) {
retcode = ERR_NOMEM;
goto fail;
}
new_conf->timeout = DRBD_TIMEOUT_DEF;
new_conf->try_connect_int = DRBD_CONNECT_INT_DEF;
new_conf->ping_int = DRBD_PING_INT_DEF;
new_conf->max_epoch_size = DRBD_MAX_EPOCH_SIZE_DEF;
new_conf->max_buffers = DRBD_MAX_BUFFERS_DEF;
new_conf->unplug_watermark = DRBD_UNPLUG_WATERMARK_DEF;
new_conf->sndbuf_size = DRBD_SNDBUF_SIZE_DEF;
new_conf->rcvbuf_size = DRBD_RCVBUF_SIZE_DEF;
new_conf->ko_count = DRBD_KO_COUNT_DEF;
new_conf->after_sb_0p = DRBD_AFTER_SB_0P_DEF;
new_conf->after_sb_1p = DRBD_AFTER_SB_1P_DEF;
new_conf->after_sb_2p = DRBD_AFTER_SB_2P_DEF;
new_conf->want_lose = 0;
new_conf->two_primaries = 0;
new_conf->wire_protocol = DRBD_PROT_C;
new_conf->ping_timeo = DRBD_PING_TIMEO_DEF;
new_conf->rr_conflict = DRBD_RR_CONFLICT_DEF;
new_conf->on_congestion = DRBD_ON_CONGESTION_DEF;
new_conf->cong_extents = DRBD_CONG_EXTENTS_DEF;
if (!net_conf_from_tags(mdev, nlp->tag_list, new_conf)) {
retcode = ERR_MANDATORY_TAG;
goto fail;
}
if (new_conf->two_primaries
&& (new_conf->wire_protocol != DRBD_PROT_C)) {
retcode = ERR_NOT_PROTO_C;
goto fail;
}
if (get_ldev(mdev)) {
enum drbd_fencing_p fp = mdev->ldev->dc.fencing;
put_ldev(mdev);
if (new_conf->wire_protocol == DRBD_PROT_A && fp == FP_STONITH) {
retcode = ERR_STONITH_AND_PROT_A;
goto fail;
}
}
if (new_conf->on_congestion != OC_BLOCK && new_conf->wire_protocol != DRBD_PROT_A) {
retcode = ERR_CONG_NOT_PROTO_A;
goto fail;
}
if (mdev->state.role == R_PRIMARY && new_conf->want_lose) {
retcode = ERR_DISCARD;
goto fail;
}
retcode = NO_ERROR;
new_my_addr = (struct sockaddr *)&new_conf->my_addr;
new_peer_addr = (struct sockaddr *)&new_conf->peer_addr;
for (i = 0; i < minor_count; i++) {
odev = minor_to_mdev(i);
if (!odev || odev == mdev)
continue;
if (get_net_conf(odev)) {
taken_addr = (struct sockaddr *)&odev->net_conf->my_addr;
if (new_conf->my_addr_len == odev->net_conf->my_addr_len &&
!memcmp(new_my_addr, taken_addr, new_conf->my_addr_len))
retcode = ERR_LOCAL_ADDR;
taken_addr = (struct sockaddr *)&odev->net_conf->peer_addr;
if (new_conf->peer_addr_len == odev->net_conf->peer_addr_len &&
!memcmp(new_peer_addr, taken_addr, new_conf->peer_addr_len))
retcode = ERR_PEER_ADDR;
put_net_conf(odev);
if (retcode != NO_ERROR)
goto fail;
}
}
if (new_conf->cram_hmac_alg[0] != 0) {
snprintf(hmac_name, CRYPTO_MAX_ALG_NAME, "hmac(%s)",
new_conf->cram_hmac_alg);
tfm = crypto_alloc_hash(hmac_name, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(tfm)) {
tfm = NULL;
retcode = ERR_AUTH_ALG;
goto fail;
}
if (!drbd_crypto_is_hash(crypto_hash_tfm(tfm))) {
retcode = ERR_AUTH_ALG_ND;
goto fail;
}
}
if (new_conf->integrity_alg[0]) {
integrity_w_tfm = crypto_alloc_hash(new_conf->integrity_alg, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(integrity_w_tfm)) {
integrity_w_tfm = NULL;
retcode=ERR_INTEGRITY_ALG;
goto fail;
}
if (!drbd_crypto_is_hash(crypto_hash_tfm(integrity_w_tfm))) {
retcode=ERR_INTEGRITY_ALG_ND;
goto fail;
}
integrity_r_tfm = crypto_alloc_hash(new_conf->integrity_alg, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(integrity_r_tfm)) {
integrity_r_tfm = NULL;
retcode=ERR_INTEGRITY_ALG;
goto fail;
}
}
ns = new_conf->max_epoch_size/8;
if (mdev->tl_hash_s != ns) {
new_tl_hash = kzalloc(ns*sizeof(void *), GFP_KERNEL);
if (!new_tl_hash) {
retcode = ERR_NOMEM;
goto fail;
}
}
ns = new_conf->max_buffers/8;
if (new_conf->two_primaries && (mdev->ee_hash_s != ns)) {
new_ee_hash = kzalloc(ns*sizeof(void *), GFP_KERNEL);
if (!new_ee_hash) {
retcode = ERR_NOMEM;
goto fail;
}
}
((char *)new_conf->shared_secret)[SHARED_SECRET_MAX-1] = 0;
if (integrity_w_tfm) {
i = crypto_hash_digestsize(integrity_w_tfm);
int_dig_out = kmalloc(i, GFP_KERNEL);
if (!int_dig_out) {
retcode = ERR_NOMEM;
goto fail;
}
int_dig_in = kmalloc(i, GFP_KERNEL);
if (!int_dig_in) {
retcode = ERR_NOMEM;
goto fail;
}
int_dig_vv = kmalloc(i, GFP_KERNEL);
if (!int_dig_vv) {
retcode = ERR_NOMEM;
goto fail;
}
}
if (!mdev->bitmap) {
if(drbd_bm_init(mdev)) {
retcode = ERR_NOMEM;
goto fail;
}
}
drbd_flush_workqueue(mdev);
spin_lock_irq(&mdev->req_lock);
if (mdev->net_conf != NULL) {
retcode = ERR_NET_CONFIGURED;
spin_unlock_irq(&mdev->req_lock);
goto fail;
}
mdev->net_conf = new_conf;
mdev->send_cnt = 0;
mdev->recv_cnt = 0;
if (new_tl_hash) {
kfree(mdev->tl_hash);
mdev->tl_hash_s = mdev->net_conf->max_epoch_size/8;
mdev->tl_hash = new_tl_hash;
}
if (new_ee_hash) {
kfree(mdev->ee_hash);
mdev->ee_hash_s = mdev->net_conf->max_buffers/8;
mdev->ee_hash = new_ee_hash;
}
crypto_free_hash(mdev->cram_hmac_tfm);
mdev->cram_hmac_tfm = tfm;
crypto_free_hash(mdev->integrity_w_tfm);
mdev->integrity_w_tfm = integrity_w_tfm;
crypto_free_hash(mdev->integrity_r_tfm);
mdev->integrity_r_tfm = integrity_r_tfm;
kfree(mdev->int_dig_out);
kfree(mdev->int_dig_in);
kfree(mdev->int_dig_vv);
mdev->int_dig_out=int_dig_out;
mdev->int_dig_in=int_dig_in;
mdev->int_dig_vv=int_dig_vv;
retcode = _drbd_set_state(_NS(mdev, conn, C_UNCONNECTED), CS_VERBOSE, NULL);
spin_unlock_irq(&mdev->req_lock);
kobject_uevent(&disk_to_dev(mdev->vdisk)->kobj, KOBJ_CHANGE);
reply->ret_code = retcode;
drbd_reconfig_done(mdev);
return 0;
fail:
kfree(int_dig_out);
kfree(int_dig_in);
kfree(int_dig_vv);
crypto_free_hash(tfm);
crypto_free_hash(integrity_w_tfm);
crypto_free_hash(integrity_r_tfm);
kfree(new_tl_hash);
kfree(new_ee_hash);
kfree(new_conf);
reply->ret_code = retcode;
drbd_reconfig_done(mdev);
return 0;
}
static int drbd_nl_disconnect(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
int retcode;
struct disconnect dc;
memset(&dc, 0, sizeof(struct disconnect));
if (!disconnect_from_tags(mdev, nlp->tag_list, &dc)) {
retcode = ERR_MANDATORY_TAG;
goto fail;
}
if (dc.force) {
spin_lock_irq(&mdev->req_lock);
if (mdev->state.conn >= C_WF_CONNECTION)
_drbd_set_state(_NS(mdev, conn, C_DISCONNECTING), CS_HARD, NULL);
spin_unlock_irq(&mdev->req_lock);
goto done;
}
retcode = _drbd_request_state(mdev, NS(conn, C_DISCONNECTING), CS_ORDERED);
if (retcode == SS_NOTHING_TO_DO)
goto done;
else if (retcode == SS_ALREADY_STANDALONE)
goto done;
else if (retcode == SS_PRIMARY_NOP) {
retcode = drbd_request_state(mdev, NS2(conn, C_DISCONNECTING,
pdsk, D_OUTDATED));
} else if (retcode == SS_CW_FAILED_BY_PEER) {
retcode = _drbd_request_state(mdev, NS2(conn, C_DISCONNECTING,
disk, D_OUTDATED),
CS_ORDERED);
if (retcode == SS_IS_DISKLESS || retcode == SS_LOWER_THAN_OUTDATED) {
drbd_force_state(mdev, NS(conn, C_DISCONNECTING));
retcode = SS_SUCCESS;
}
}
if (retcode < SS_SUCCESS)
goto fail;
if (wait_event_interruptible(mdev->state_wait,
mdev->state.conn != C_DISCONNECTING)) {
retcode = ERR_INTR;
goto fail;
}
done:
retcode = NO_ERROR;
fail:
drbd_md_sync(mdev);
reply->ret_code = retcode;
return 0;
}
void resync_after_online_grow(struct drbd_conf *mdev)
{
int iass;
dev_info(DEV, "Resync of new storage after online grow\n");
if (mdev->state.role != mdev->state.peer)
iass = (mdev->state.role == R_PRIMARY);
else
iass = test_bit(DISCARD_CONCURRENT, &mdev->flags);
if (iass)
drbd_start_resync(mdev, C_SYNC_SOURCE);
else
_drbd_request_state(mdev, NS(conn, C_WF_SYNC_UUID), CS_VERBOSE + CS_SERIALIZE);
}
static int drbd_nl_resize(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
struct resize rs;
int retcode = NO_ERROR;
enum determine_dev_size dd;
enum dds_flags ddsf;
memset(&rs, 0, sizeof(struct resize));
if (!resize_from_tags(mdev, nlp->tag_list, &rs)) {
retcode = ERR_MANDATORY_TAG;
goto fail;
}
if (mdev->state.conn > C_CONNECTED) {
retcode = ERR_RESIZE_RESYNC;
goto fail;
}
if (mdev->state.role == R_SECONDARY &&
mdev->state.peer == R_SECONDARY) {
retcode = ERR_NO_PRIMARY;
goto fail;
}
if (!get_ldev(mdev)) {
retcode = ERR_NO_DISK;
goto fail;
}
if (rs.no_resync && mdev->agreed_pro_version < 93) {
retcode = ERR_NEED_APV_93;
goto fail_ldev;
}
if (mdev->ldev->known_size != drbd_get_capacity(mdev->ldev->backing_bdev))
mdev->ldev->known_size = drbd_get_capacity(mdev->ldev->backing_bdev);
mdev->ldev->dc.disk_size = (sector_t)rs.resize_size;
ddsf = (rs.resize_force ? DDSF_FORCED : 0) | (rs.no_resync ? DDSF_NO_RESYNC : 0);
dd = drbd_determine_dev_size(mdev, ddsf);
drbd_md_sync(mdev);
put_ldev(mdev);
if (dd == dev_size_error) {
retcode = ERR_NOMEM_BITMAP;
goto fail;
}
if (mdev->state.conn == C_CONNECTED) {
if (dd == grew)
set_bit(RESIZE_PENDING, &mdev->flags);
drbd_send_uuids(mdev);
drbd_send_sizes(mdev, 1, ddsf);
}
fail:
reply->ret_code = retcode;
return 0;
fail_ldev:
put_ldev(mdev);
goto fail;
}
static int drbd_nl_syncer_conf(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
int retcode = NO_ERROR;
int err;
int ovr;
int rsr;
struct crypto_hash *verify_tfm = NULL;
struct crypto_hash *csums_tfm = NULL;
struct syncer_conf sc;
cpumask_var_t new_cpu_mask;
int *rs_plan_s = NULL;
int fifo_size;
if (!zalloc_cpumask_var(&new_cpu_mask, GFP_KERNEL)) {
retcode = ERR_NOMEM;
goto fail;
}
if (nlp->flags & DRBD_NL_SET_DEFAULTS) {
memset(&sc, 0, sizeof(struct syncer_conf));
sc.rate = DRBD_RATE_DEF;
sc.after = DRBD_AFTER_DEF;
sc.al_extents = DRBD_AL_EXTENTS_DEF;
sc.on_no_data = DRBD_ON_NO_DATA_DEF;
sc.c_plan_ahead = DRBD_C_PLAN_AHEAD_DEF;
sc.c_delay_target = DRBD_C_DELAY_TARGET_DEF;
sc.c_fill_target = DRBD_C_FILL_TARGET_DEF;
sc.c_max_rate = DRBD_C_MAX_RATE_DEF;
sc.c_min_rate = DRBD_C_MIN_RATE_DEF;
} else
memcpy(&sc, &mdev->sync_conf, sizeof(struct syncer_conf));
if (!syncer_conf_from_tags(mdev, nlp->tag_list, &sc)) {
retcode = ERR_MANDATORY_TAG;
goto fail;
}
rsr = ( mdev->state.conn == C_SYNC_SOURCE ||
mdev->state.conn == C_SYNC_TARGET ||
mdev->state.conn == C_PAUSED_SYNC_S ||
mdev->state.conn == C_PAUSED_SYNC_T );
if (rsr && strcmp(sc.csums_alg, mdev->sync_conf.csums_alg)) {
retcode = ERR_CSUMS_RESYNC_RUNNING;
goto fail;
}
if (!rsr && sc.csums_alg[0]) {
csums_tfm = crypto_alloc_hash(sc.csums_alg, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(csums_tfm)) {
csums_tfm = NULL;
retcode = ERR_CSUMS_ALG;
goto fail;
}
if (!drbd_crypto_is_hash(crypto_hash_tfm(csums_tfm))) {
retcode = ERR_CSUMS_ALG_ND;
goto fail;
}
}
ovr = (mdev->state.conn == C_VERIFY_S || mdev->state.conn == C_VERIFY_T);
if (ovr) {
if (strcmp(sc.verify_alg, mdev->sync_conf.verify_alg)) {
retcode = ERR_VERIFY_RUNNING;
goto fail;
}
}
if (!ovr && sc.verify_alg[0]) {
verify_tfm = crypto_alloc_hash(sc.verify_alg, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(verify_tfm)) {
verify_tfm = NULL;
retcode = ERR_VERIFY_ALG;
goto fail;
}
if (!drbd_crypto_is_hash(crypto_hash_tfm(verify_tfm))) {
retcode = ERR_VERIFY_ALG_ND;
goto fail;
}
}
if (nr_cpu_ids > 1 && sc.cpu_mask[0] != 0) {
err = bitmap_parse(sc.cpu_mask, 32,
cpumask_bits(new_cpu_mask), nr_cpu_ids);
if (err) {
dev_warn(DEV, "bitmap_parse() failed with %d\n", err);
retcode = ERR_CPU_MASK_PARSE;
goto fail;
}
}
ERR_IF (sc.rate < 1) sc.rate = 1;
ERR_IF (sc.al_extents < 7) sc.al_extents = 127;
#define AL_MAX ((MD_AL_MAX_SIZE-1) * AL_EXTENTS_PT)
if (sc.al_extents > AL_MAX) {
dev_err(DEV, "sc.al_extents > %d\n", AL_MAX);
sc.al_extents = AL_MAX;
}
#undef AL_MAX
if (sc.after >= 0)
ensure_mdev(sc.after, 1);
retcode = drbd_alter_sa(mdev, sc.after);
if (retcode != NO_ERROR)
goto fail;
fifo_size = (sc.c_plan_ahead * 10 * SLEEP_TIME) / HZ;
if (fifo_size != mdev->rs_plan_s.size && fifo_size > 0) {
rs_plan_s = kzalloc(sizeof(int) * fifo_size, GFP_KERNEL);
if (!rs_plan_s) {
dev_err(DEV, "kmalloc of fifo_buffer failed");
retcode = ERR_NOMEM;
goto fail;
}
}
spin_lock(&mdev->peer_seq_lock);
mdev->sync_conf = sc;
if (!rsr) {
crypto_free_hash(mdev->csums_tfm);
mdev->csums_tfm = csums_tfm;
csums_tfm = NULL;
}
if (!ovr) {
crypto_free_hash(mdev->verify_tfm);
mdev->verify_tfm = verify_tfm;
verify_tfm = NULL;
}
if (fifo_size != mdev->rs_plan_s.size) {
kfree(mdev->rs_plan_s.values);
mdev->rs_plan_s.values = rs_plan_s;
mdev->rs_plan_s.size = fifo_size;
mdev->rs_planed = 0;
rs_plan_s = NULL;
}
spin_unlock(&mdev->peer_seq_lock);
if (get_ldev(mdev)) {
wait_event(mdev->al_wait, lc_try_lock(mdev->act_log));
drbd_al_shrink(mdev);
err = drbd_check_al_size(mdev);
lc_unlock(mdev->act_log);
wake_up(&mdev->al_wait);
put_ldev(mdev);
drbd_md_sync(mdev);
if (err) {
retcode = ERR_NOMEM;
goto fail;
}
}
if (mdev->state.conn >= C_CONNECTED)
drbd_send_sync_param(mdev, &sc);
if (!cpumask_equal(mdev->cpu_mask, new_cpu_mask)) {
cpumask_copy(mdev->cpu_mask, new_cpu_mask);
drbd_calc_cpu_mask(mdev);
mdev->receiver.reset_cpu_mask = 1;
mdev->asender.reset_cpu_mask = 1;
mdev->worker.reset_cpu_mask = 1;
}
kobject_uevent(&disk_to_dev(mdev->vdisk)->kobj, KOBJ_CHANGE);
fail:
kfree(rs_plan_s);
free_cpumask_var(new_cpu_mask);
crypto_free_hash(csums_tfm);
crypto_free_hash(verify_tfm);
reply->ret_code = retcode;
return 0;
}
static int drbd_nl_invalidate(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
int retcode;
drbd_suspend_io(mdev);
wait_event(mdev->misc_wait, !test_bit(BITMAP_IO, &mdev->flags));
drbd_flush_workqueue(mdev);
retcode = _drbd_request_state(mdev, NS(conn, C_STARTING_SYNC_T), CS_ORDERED);
if (retcode < SS_SUCCESS && retcode != SS_NEED_CONNECTION)
retcode = drbd_request_state(mdev, NS(conn, C_STARTING_SYNC_T));
while (retcode == SS_NEED_CONNECTION) {
spin_lock_irq(&mdev->req_lock);
if (mdev->state.conn < C_CONNECTED)
retcode = _drbd_set_state(_NS(mdev, disk, D_INCONSISTENT), CS_VERBOSE, NULL);
spin_unlock_irq(&mdev->req_lock);
if (retcode != SS_NEED_CONNECTION)
break;
retcode = drbd_request_state(mdev, NS(conn, C_STARTING_SYNC_T));
}
drbd_resume_io(mdev);
reply->ret_code = retcode;
return 0;
}
static int drbd_bmio_set_susp_al(struct drbd_conf *mdev)
{
int rv;
rv = drbd_bmio_set_n_write(mdev);
drbd_suspend_al(mdev);
return rv;
}
static int drbd_nl_invalidate_peer(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
int retcode;
drbd_suspend_io(mdev);
wait_event(mdev->misc_wait, !test_bit(BITMAP_IO, &mdev->flags));
drbd_flush_workqueue(mdev);
retcode = _drbd_request_state(mdev, NS(conn, C_STARTING_SYNC_S), CS_ORDERED);
if (retcode < SS_SUCCESS) {
if (retcode == SS_NEED_CONNECTION && mdev->state.role == R_PRIMARY) {
retcode = drbd_request_state(mdev, NS(pdsk, D_INCONSISTENT));
if (retcode >= SS_SUCCESS) {
if (drbd_bitmap_io(mdev, &drbd_bmio_set_susp_al,
"set_n_write from invalidate_peer",
BM_LOCKED_SET_ALLOWED))
retcode = ERR_IO_MD_DISK;
}
} else
retcode = drbd_request_state(mdev, NS(conn, C_STARTING_SYNC_S));
}
drbd_resume_io(mdev);
reply->ret_code = retcode;
return 0;
}
static int drbd_nl_pause_sync(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
int retcode = NO_ERROR;
if (drbd_request_state(mdev, NS(user_isp, 1)) == SS_NOTHING_TO_DO)
retcode = ERR_PAUSE_IS_SET;
reply->ret_code = retcode;
return 0;
}
static int drbd_nl_resume_sync(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
int retcode = NO_ERROR;
union drbd_state s;
if (drbd_request_state(mdev, NS(user_isp, 0)) == SS_NOTHING_TO_DO) {
s = mdev->state;
if (s.conn == C_PAUSED_SYNC_S || s.conn == C_PAUSED_SYNC_T) {
retcode = s.aftr_isp ? ERR_PIC_AFTER_DEP :
s.peer_isp ? ERR_PIC_PEER_DEP : ERR_PAUSE_IS_CLEAR;
} else {
retcode = ERR_PAUSE_IS_CLEAR;
}
}
reply->ret_code = retcode;
return 0;
}
static int drbd_nl_suspend_io(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
reply->ret_code = drbd_request_state(mdev, NS(susp, 1));
return 0;
}
static int drbd_nl_resume_io(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
if (test_bit(NEW_CUR_UUID, &mdev->flags)) {
drbd_uuid_new_current(mdev);
clear_bit(NEW_CUR_UUID, &mdev->flags);
}
drbd_suspend_io(mdev);
reply->ret_code = drbd_request_state(mdev, NS3(susp, 0, susp_nod, 0, susp_fen, 0));
if (reply->ret_code == SS_SUCCESS) {
if (mdev->state.conn < C_CONNECTED)
tl_clear(mdev);
if (mdev->state.disk == D_DISKLESS || mdev->state.disk == D_FAILED)
tl_restart(mdev, fail_frozen_disk_io);
}
drbd_resume_io(mdev);
return 0;
}
static int drbd_nl_outdate(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
reply->ret_code = drbd_request_state(mdev, NS(disk, D_OUTDATED));
return 0;
}
static int drbd_nl_get_config(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
unsigned short *tl;
tl = reply->tag_list;
if (get_ldev(mdev)) {
tl = disk_conf_to_tags(mdev, &mdev->ldev->dc, tl);
put_ldev(mdev);
}
if (get_net_conf(mdev)) {
tl = net_conf_to_tags(mdev, mdev->net_conf, tl);
put_net_conf(mdev);
}
tl = syncer_conf_to_tags(mdev, &mdev->sync_conf, tl);
put_unaligned(TT_END, tl++);
return (int)((char *)tl - (char *)reply->tag_list);
}
static int drbd_nl_get_state(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
unsigned short *tl = reply->tag_list;
union drbd_state s = mdev->state;
unsigned long rs_left;
unsigned int res;
tl = get_state_to_tags(mdev, (struct get_state *)&s, tl);
if (s.conn >= C_SYNC_SOURCE && s.conn <= C_PAUSED_SYNC_T) {
if (get_ldev(mdev)) {
drbd_get_syncer_progress(mdev, &rs_left, &res);
tl = tl_add_int(tl, T_sync_progress, &res);
put_ldev(mdev);
}
}
put_unaligned(TT_END, tl++);
return (int)((char *)tl - (char *)reply->tag_list);
}
static int drbd_nl_get_uuids(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
unsigned short *tl;
tl = reply->tag_list;
if (get_ldev(mdev)) {
tl = tl_add_blob(tl, T_uuids, mdev->ldev->md.uuid, UI_SIZE*sizeof(u64));
tl = tl_add_int(tl, T_uuids_flags, &mdev->ldev->md.flags);
put_ldev(mdev);
}
put_unaligned(TT_END, tl++);
return (int)((char *)tl - (char *)reply->tag_list);
}
static int drbd_nl_get_timeout_flag(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
unsigned short *tl;
char rv;
tl = reply->tag_list;
rv = mdev->state.pdsk == D_OUTDATED ? UT_PEER_OUTDATED :
test_bit(USE_DEGR_WFC_T, &mdev->flags) ? UT_DEGRADED : UT_DEFAULT;
tl = tl_add_blob(tl, T_use_degraded, &rv, sizeof(rv));
put_unaligned(TT_END, tl++);
return (int)((char *)tl - (char *)reply->tag_list);
}
static int drbd_nl_start_ov(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
struct start_ov args =
{ .start_sector = mdev->ov_start_sector };
if (!start_ov_from_tags(mdev, nlp->tag_list, &args)) {
reply->ret_code = ERR_MANDATORY_TAG;
return 0;
}
drbd_suspend_io(mdev);
wait_event(mdev->misc_wait, !test_bit(BITMAP_IO, &mdev->flags));
mdev->ov_start_sector = args.start_sector & ~BM_SECT_PER_BIT;
reply->ret_code = drbd_request_state(mdev,NS(conn,C_VERIFY_S));
drbd_resume_io(mdev);
return 0;
}
static int drbd_nl_new_c_uuid(struct drbd_conf *mdev, struct drbd_nl_cfg_req *nlp,
struct drbd_nl_cfg_reply *reply)
{
int retcode = NO_ERROR;
int skip_initial_sync = 0;
int err;
struct new_c_uuid args;
memset(&args, 0, sizeof(struct new_c_uuid));
if (!new_c_uuid_from_tags(mdev, nlp->tag_list, &args)) {
reply->ret_code = ERR_MANDATORY_TAG;
return 0;
}
mutex_lock(&mdev->state_mutex);
if (!get_ldev(mdev)) {
retcode = ERR_NO_DISK;
goto out;
}
if (mdev->state.conn == C_CONNECTED && mdev->agreed_pro_version >= 90 &&
mdev->ldev->md.uuid[UI_CURRENT] == UUID_JUST_CREATED && args.clear_bm) {
dev_info(DEV, "Preparing to skip initial sync\n");
skip_initial_sync = 1;
} else if (mdev->state.conn != C_STANDALONE) {
retcode = ERR_CONNECTED;
goto out_dec;
}
drbd_uuid_set(mdev, UI_BITMAP, 0);
drbd_uuid_new_current(mdev);
if (args.clear_bm) {
err = drbd_bitmap_io(mdev, &drbd_bmio_clear_n_write,
"clear_n_write from new_c_uuid", BM_LOCKED_MASK);
if (err) {
dev_err(DEV, "Writing bitmap failed with %d\n",err);
retcode = ERR_IO_MD_DISK;
}
if (skip_initial_sync) {
drbd_send_uuids_skip_initial_sync(mdev);
_drbd_uuid_set(mdev, UI_BITMAP, 0);
drbd_print_uuids(mdev, "cleared bitmap UUID");
spin_lock_irq(&mdev->req_lock);
_drbd_set_state(_NS2(mdev, disk, D_UP_TO_DATE, pdsk, D_UP_TO_DATE),
CS_VERBOSE, NULL);
spin_unlock_irq(&mdev->req_lock);
}
}
drbd_md_sync(mdev);
out_dec:
put_ldev(mdev);
out:
mutex_unlock(&mdev->state_mutex);
reply->ret_code = retcode;
return 0;
}
static void drbd_connector_callback(struct cn_msg *req, struct netlink_skb_parms *nsp)
{
struct drbd_nl_cfg_req *nlp = (struct drbd_nl_cfg_req *)req->data;
struct cn_handler_struct *cm;
struct cn_msg *cn_reply;
struct drbd_nl_cfg_reply *reply;
struct drbd_conf *mdev;
int retcode, rr;
int reply_size = sizeof(struct cn_msg)
+ sizeof(struct drbd_nl_cfg_reply)
+ sizeof(short int);
if (!try_module_get(THIS_MODULE)) {
printk(KERN_ERR "drbd: try_module_get() failed!\n");
return;
}
if (!capable(CAP_SYS_ADMIN)) {
retcode = ERR_PERM;
goto fail;
}
mdev = ensure_mdev(nlp->drbd_minor,
(nlp->flags & DRBD_NL_CREATE_DEVICE));
if (!mdev) {
retcode = ERR_MINOR_INVALID;
goto fail;
}
if (nlp->packet_type >= P_nl_after_last_packet ||
nlp->packet_type == P_return_code_only) {
retcode = ERR_PACKET_NR;
goto fail;
}
cm = cnd_table + nlp->packet_type;
if (cm->function == NULL) {
retcode = ERR_PACKET_NR;
goto fail;
}
reply_size += cm->reply_body_size;
cn_reply = kzalloc(reply_size, GFP_KERNEL);
if (!cn_reply) {
retcode = ERR_NOMEM;
goto fail;
}
reply = (struct drbd_nl_cfg_reply *) cn_reply->data;
reply->packet_type =
cm->reply_body_size ? nlp->packet_type : P_return_code_only;
reply->minor = nlp->drbd_minor;
reply->ret_code = NO_ERROR;
rr = cm->function(mdev, nlp, reply);
cn_reply->id = req->id;
cn_reply->seq = req->seq;
cn_reply->ack = req->ack + 1;
cn_reply->len = sizeof(struct drbd_nl_cfg_reply) + rr;
cn_reply->flags = 0;
rr = cn_netlink_send(cn_reply, CN_IDX_DRBD, GFP_KERNEL);
if (rr && rr != -ESRCH)
printk(KERN_INFO "drbd: cn_netlink_send()=%d\n", rr);
kfree(cn_reply);
module_put(THIS_MODULE);
return;
fail:
drbd_nl_send_reply(req, retcode);
module_put(THIS_MODULE);
}
static unsigned short *
__tl_add_blob(unsigned short *tl, enum drbd_tags tag, const void *data,
unsigned short len, int nul_terminated)
{
unsigned short l = tag_descriptions[tag_number(tag)].max_len;
len = (len < l) ? len : l;
put_unaligned(tag, tl++);
put_unaligned(len, tl++);
memcpy(tl, data, len);
tl = (unsigned short*)((char*)tl + len);
if (nul_terminated)
*((char*)tl - 1) = 0;
return tl;
}
static unsigned short *
tl_add_blob(unsigned short *tl, enum drbd_tags tag, const void *data, int len)
{
return __tl_add_blob(tl, tag, data, len, 0);
}
static unsigned short *
tl_add_str(unsigned short *tl, enum drbd_tags tag, const char *str)
{
return __tl_add_blob(tl, tag, str, strlen(str)+1, 0);
}
static unsigned short *
tl_add_int(unsigned short *tl, enum drbd_tags tag, const void *val)
{
put_unaligned(tag, tl++);
switch(tag_type(tag)) {
case TT_INTEGER:
put_unaligned(sizeof(int), tl++);
put_unaligned(*(int *)val, (int *)tl);
tl = (unsigned short*)((char*)tl+sizeof(int));
break;
case TT_INT64:
put_unaligned(sizeof(u64), tl++);
put_unaligned(*(u64 *)val, (u64 *)tl);
tl = (unsigned short*)((char*)tl+sizeof(u64));
break;
default:
;
}
return tl;
}
void drbd_bcast_state(struct drbd_conf *mdev, union drbd_state state)
{
char buffer[sizeof(struct cn_msg)+
sizeof(struct drbd_nl_cfg_reply)+
sizeof(struct get_state_tag_len_struct)+
sizeof(short int)];
struct cn_msg *cn_reply = (struct cn_msg *) buffer;
struct drbd_nl_cfg_reply *reply =
(struct drbd_nl_cfg_reply *)cn_reply->data;
unsigned short *tl = reply->tag_list;
tl = get_state_to_tags(mdev, (struct get_state *)&state, tl);
put_unaligned(TT_END, tl++);
cn_reply->id.idx = CN_IDX_DRBD;
cn_reply->id.val = CN_VAL_DRBD;
cn_reply->seq = atomic_add_return(1, &drbd_nl_seq);
cn_reply->ack = 0;
cn_reply->len = sizeof(struct drbd_nl_cfg_reply) +
(int)((char *)tl - (char *)reply->tag_list);
cn_reply->flags = 0;
reply->packet_type = P_get_state;
reply->minor = mdev_to_minor(mdev);
reply->ret_code = NO_ERROR;
cn_netlink_send(cn_reply, CN_IDX_DRBD, GFP_NOIO);
}
void drbd_bcast_ev_helper(struct drbd_conf *mdev, char *helper_name)
{
char buffer[sizeof(struct cn_msg)+
sizeof(struct drbd_nl_cfg_reply)+
sizeof(struct call_helper_tag_len_struct)+
sizeof(short int)];
struct cn_msg *cn_reply = (struct cn_msg *) buffer;
struct drbd_nl_cfg_reply *reply =
(struct drbd_nl_cfg_reply *)cn_reply->data;
unsigned short *tl = reply->tag_list;
tl = tl_add_str(tl, T_helper, helper_name);
put_unaligned(TT_END, tl++);
cn_reply->id.idx = CN_IDX_DRBD;
cn_reply->id.val = CN_VAL_DRBD;
cn_reply->seq = atomic_add_return(1, &drbd_nl_seq);
cn_reply->ack = 0;
cn_reply->len = sizeof(struct drbd_nl_cfg_reply) +
(int)((char *)tl - (char *)reply->tag_list);
cn_reply->flags = 0;
reply->packet_type = P_call_helper;
reply->minor = mdev_to_minor(mdev);
reply->ret_code = NO_ERROR;
cn_netlink_send(cn_reply, CN_IDX_DRBD, GFP_NOIO);
}
void drbd_bcast_ee(struct drbd_conf *mdev,
const char *reason, const int dgs,
const char* seen_hash, const char* calc_hash,
const struct drbd_epoch_entry* e)
{
struct cn_msg *cn_reply;
struct drbd_nl_cfg_reply *reply;
unsigned short *tl;
struct page *page;
unsigned len;
if (!e)
return;
if (!reason || !reason[0])
return;
cn_reply = kzalloc(
sizeof(struct cn_msg)+
sizeof(struct drbd_nl_cfg_reply)+
sizeof(struct dump_ee_tag_len_struct)+
sizeof(short int),
GFP_NOIO);
if (!cn_reply) {
dev_err(DEV, "could not kmalloc buffer for drbd_bcast_ee, sector %llu, size %u\n",
(unsigned long long)e->sector, e->size);
return;
}
reply = (struct drbd_nl_cfg_reply*)cn_reply->data;
tl = reply->tag_list;
tl = tl_add_str(tl, T_dump_ee_reason, reason);
tl = tl_add_blob(tl, T_seen_digest, seen_hash, dgs);
tl = tl_add_blob(tl, T_calc_digest, calc_hash, dgs);
tl = tl_add_int(tl, T_ee_sector, &e->sector);
tl = tl_add_int(tl, T_ee_block_id, &e->block_id);
len = min_t(unsigned, e->size, 32 << 10);
put_unaligned(T_ee_data, tl++);
put_unaligned(len, tl++);
page = e->pages;
page_chain_for_each(page) {
void *d = kmap_atomic(page);
unsigned l = min_t(unsigned, len, PAGE_SIZE);
memcpy(tl, d, l);
kunmap_atomic(d);
tl = (unsigned short*)((char*)tl + l);
len -= l;
if (len == 0)
break;
}
put_unaligned(TT_END, tl++);
cn_reply->id.idx = CN_IDX_DRBD;
cn_reply->id.val = CN_VAL_DRBD;
cn_reply->seq = atomic_add_return(1,&drbd_nl_seq);
cn_reply->ack = 0;
cn_reply->len = sizeof(struct drbd_nl_cfg_reply) +
(int)((char*)tl - (char*)reply->tag_list);
cn_reply->flags = 0;
reply->packet_type = P_dump_ee;
reply->minor = mdev_to_minor(mdev);
reply->ret_code = NO_ERROR;
cn_netlink_send(cn_reply, CN_IDX_DRBD, GFP_NOIO);
kfree(cn_reply);
}
void drbd_bcast_sync_progress(struct drbd_conf *mdev)
{
char buffer[sizeof(struct cn_msg)+
sizeof(struct drbd_nl_cfg_reply)+
sizeof(struct sync_progress_tag_len_struct)+
sizeof(short int)];
struct cn_msg *cn_reply = (struct cn_msg *) buffer;
struct drbd_nl_cfg_reply *reply =
(struct drbd_nl_cfg_reply *)cn_reply->data;
unsigned short *tl = reply->tag_list;
unsigned long rs_left;
unsigned int res;
if (!get_ldev(mdev))
return;
drbd_get_syncer_progress(mdev, &rs_left, &res);
put_ldev(mdev);
tl = tl_add_int(tl, T_sync_progress, &res);
put_unaligned(TT_END, tl++);
cn_reply->id.idx = CN_IDX_DRBD;
cn_reply->id.val = CN_VAL_DRBD;
cn_reply->seq = atomic_add_return(1, &drbd_nl_seq);
cn_reply->ack = 0;
cn_reply->len = sizeof(struct drbd_nl_cfg_reply) +
(int)((char *)tl - (char *)reply->tag_list);
cn_reply->flags = 0;
reply->packet_type = P_sync_progress;
reply->minor = mdev_to_minor(mdev);
reply->ret_code = NO_ERROR;
cn_netlink_send(cn_reply, CN_IDX_DRBD, GFP_NOIO);
}
int __init drbd_nl_init(void)
{
static struct cb_id cn_id_drbd;
int err, try=10;
cn_id_drbd.val = CN_VAL_DRBD;
do {
cn_id_drbd.idx = cn_idx;
err = cn_add_callback(&cn_id_drbd, "cn_drbd", &drbd_connector_callback);
if (!err)
break;
cn_idx = (cn_idx + CN_IDX_STEP);
} while (try--);
if (err) {
printk(KERN_ERR "drbd: cn_drbd failed to register\n");
return err;
}
return 0;
}
void drbd_nl_cleanup(void)
{
static struct cb_id cn_id_drbd;
cn_id_drbd.idx = cn_idx;
cn_id_drbd.val = CN_VAL_DRBD;
cn_del_callback(&cn_id_drbd);
}
void drbd_nl_send_reply(struct cn_msg *req, int ret_code)
{
char buffer[sizeof(struct cn_msg)+sizeof(struct drbd_nl_cfg_reply)];
struct cn_msg *cn_reply = (struct cn_msg *) buffer;
struct drbd_nl_cfg_reply *reply =
(struct drbd_nl_cfg_reply *)cn_reply->data;
int rr;
memset(buffer, 0, sizeof(buffer));
cn_reply->id = req->id;
cn_reply->seq = req->seq;
cn_reply->ack = req->ack + 1;
cn_reply->len = sizeof(struct drbd_nl_cfg_reply);
cn_reply->flags = 0;
reply->packet_type = P_return_code_only;
reply->minor = ((struct drbd_nl_cfg_req *)req->data)->drbd_minor;
reply->ret_code = ret_code;
rr = cn_netlink_send(cn_reply, CN_IDX_DRBD, GFP_NOIO);
if (rr && rr != -ESRCH)
printk(KERN_INFO "drbd: cn_netlink_send()=%d\n", rr);
}
