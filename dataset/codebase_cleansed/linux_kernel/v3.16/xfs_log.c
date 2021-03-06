static void
xlog_grant_sub_space(
struct xlog *log,
atomic64_t *head,
int bytes)
{
int64_t head_val = atomic64_read(head);
int64_t new, old;
do {
int cycle, space;
xlog_crack_grant_head_val(head_val, &cycle, &space);
space -= bytes;
if (space < 0) {
space += log->l_logsize;
cycle--;
}
old = head_val;
new = xlog_assign_grant_head_val(cycle, space);
head_val = atomic64_cmpxchg(head, old, new);
} while (head_val != old);
}
static void
xlog_grant_add_space(
struct xlog *log,
atomic64_t *head,
int bytes)
{
int64_t head_val = atomic64_read(head);
int64_t new, old;
do {
int tmp;
int cycle, space;
xlog_crack_grant_head_val(head_val, &cycle, &space);
tmp = log->l_logsize - space;
if (tmp > bytes)
space += bytes;
else {
space = bytes - tmp;
cycle++;
}
old = head_val;
new = xlog_assign_grant_head_val(cycle, space);
head_val = atomic64_cmpxchg(head, old, new);
} while (head_val != old);
}
STATIC void
xlog_grant_head_init(
struct xlog_grant_head *head)
{
xlog_assign_grant_head(&head->grant, 1, 0);
INIT_LIST_HEAD(&head->waiters);
spin_lock_init(&head->lock);
}
STATIC void
xlog_grant_head_wake_all(
struct xlog_grant_head *head)
{
struct xlog_ticket *tic;
spin_lock(&head->lock);
list_for_each_entry(tic, &head->waiters, t_queue)
wake_up_process(tic->t_task);
spin_unlock(&head->lock);
}
static inline int
xlog_ticket_reservation(
struct xlog *log,
struct xlog_grant_head *head,
struct xlog_ticket *tic)
{
if (head == &log->l_write_head) {
ASSERT(tic->t_flags & XLOG_TIC_PERM_RESERV);
return tic->t_unit_res;
} else {
if (tic->t_flags & XLOG_TIC_PERM_RESERV)
return tic->t_unit_res * tic->t_cnt;
else
return tic->t_unit_res;
}
}
STATIC bool
xlog_grant_head_wake(
struct xlog *log,
struct xlog_grant_head *head,
int *free_bytes)
{
struct xlog_ticket *tic;
int need_bytes;
list_for_each_entry(tic, &head->waiters, t_queue) {
need_bytes = xlog_ticket_reservation(log, head, tic);
if (*free_bytes < need_bytes)
return false;
*free_bytes -= need_bytes;
trace_xfs_log_grant_wake_up(log, tic);
wake_up_process(tic->t_task);
}
return true;
}
STATIC int
xlog_grant_head_wait(
struct xlog *log,
struct xlog_grant_head *head,
struct xlog_ticket *tic,
int need_bytes) __releases(&head->lock
STATIC int
xlog_grant_head_check(
struct xlog *log,
struct xlog_grant_head *head,
struct xlog_ticket *tic,
int *need_bytes)
{
int free_bytes;
int error = 0;
ASSERT(!(log->l_flags & XLOG_ACTIVE_RECOVERY));
*need_bytes = xlog_ticket_reservation(log, head, tic);
free_bytes = xlog_space_left(log, &head->grant);
if (!list_empty_careful(&head->waiters)) {
spin_lock(&head->lock);
if (!xlog_grant_head_wake(log, head, &free_bytes) ||
free_bytes < *need_bytes) {
error = xlog_grant_head_wait(log, head, tic,
*need_bytes);
}
spin_unlock(&head->lock);
} else if (free_bytes < *need_bytes) {
spin_lock(&head->lock);
error = xlog_grant_head_wait(log, head, tic, *need_bytes);
spin_unlock(&head->lock);
}
return error;
}
static void
xlog_tic_reset_res(xlog_ticket_t *tic)
{
tic->t_res_num = 0;
tic->t_res_arr_sum = 0;
tic->t_res_num_ophdrs = 0;
}
static void
xlog_tic_add_region(xlog_ticket_t *tic, uint len, uint type)
{
if (tic->t_res_num == XLOG_TIC_LEN_MAX) {
tic->t_res_o_flow += tic->t_res_arr_sum;
tic->t_res_num = 0;
tic->t_res_arr_sum = 0;
}
tic->t_res_arr[tic->t_res_num].r_len = len;
tic->t_res_arr[tic->t_res_num].r_type = type;
tic->t_res_arr_sum += len;
tic->t_res_num++;
}
int
xfs_log_regrant(
struct xfs_mount *mp,
struct xlog_ticket *tic)
{
struct xlog *log = mp->m_log;
int need_bytes;
int error = 0;
if (XLOG_FORCED_SHUTDOWN(log))
return XFS_ERROR(EIO);
XFS_STATS_INC(xs_try_logspace);
tic->t_tid++;
xlog_grant_push_ail(log, tic->t_unit_res);
tic->t_curr_res = tic->t_unit_res;
xlog_tic_reset_res(tic);
if (tic->t_cnt > 0)
return 0;
trace_xfs_log_regrant(log, tic);
error = xlog_grant_head_check(log, &log->l_write_head, tic,
&need_bytes);
if (error)
goto out_error;
xlog_grant_add_space(log, &log->l_write_head.grant, need_bytes);
trace_xfs_log_regrant_exit(log, tic);
xlog_verify_grant_tail(log);
return 0;
out_error:
tic->t_curr_res = 0;
tic->t_cnt = 0;
return error;
}
int
xfs_log_reserve(
struct xfs_mount *mp,
int unit_bytes,
int cnt,
struct xlog_ticket **ticp,
__uint8_t client,
bool permanent,
uint t_type)
{
struct xlog *log = mp->m_log;
struct xlog_ticket *tic;
int need_bytes;
int error = 0;
ASSERT(client == XFS_TRANSACTION || client == XFS_LOG);
if (XLOG_FORCED_SHUTDOWN(log))
return XFS_ERROR(EIO);
XFS_STATS_INC(xs_try_logspace);
ASSERT(*ticp == NULL);
tic = xlog_ticket_alloc(log, unit_bytes, cnt, client, permanent,
KM_SLEEP | KM_MAYFAIL);
if (!tic)
return XFS_ERROR(ENOMEM);
tic->t_trans_type = t_type;
*ticp = tic;
xlog_grant_push_ail(log, tic->t_cnt ? tic->t_unit_res * tic->t_cnt
: tic->t_unit_res);
trace_xfs_log_reserve(log, tic);
error = xlog_grant_head_check(log, &log->l_reserve_head, tic,
&need_bytes);
if (error)
goto out_error;
xlog_grant_add_space(log, &log->l_reserve_head.grant, need_bytes);
xlog_grant_add_space(log, &log->l_write_head.grant, need_bytes);
trace_xfs_log_reserve_exit(log, tic);
xlog_verify_grant_tail(log);
return 0;
out_error:
tic->t_curr_res = 0;
tic->t_cnt = 0;
return error;
}
xfs_lsn_t
xfs_log_done(
struct xfs_mount *mp,
struct xlog_ticket *ticket,
struct xlog_in_core **iclog,
uint flags)
{
struct xlog *log = mp->m_log;
xfs_lsn_t lsn = 0;
if (XLOG_FORCED_SHUTDOWN(log) ||
(((ticket->t_flags & XLOG_TIC_INITED) == 0) &&
(xlog_commit_record(log, ticket, iclog, &lsn)))) {
lsn = (xfs_lsn_t) -1;
if (ticket->t_flags & XLOG_TIC_PERM_RESERV) {
flags |= XFS_LOG_REL_PERM_RESERV;
}
}
if ((ticket->t_flags & XLOG_TIC_PERM_RESERV) == 0 ||
(flags & XFS_LOG_REL_PERM_RESERV)) {
trace_xfs_log_done_nonperm(log, ticket);
xlog_ungrant_log_space(log, ticket);
xfs_log_ticket_put(ticket);
} else {
trace_xfs_log_done_perm(log, ticket);
xlog_regrant_reserve_log_space(log, ticket);
ticket->t_flags |= XLOG_TIC_INITED;
}
return lsn;
}
int
xfs_log_notify(
struct xfs_mount *mp,
struct xlog_in_core *iclog,
xfs_log_callback_t *cb)
{
int abortflg;
spin_lock(&iclog->ic_callback_lock);
abortflg = (iclog->ic_state & XLOG_STATE_IOERROR);
if (!abortflg) {
ASSERT_ALWAYS((iclog->ic_state == XLOG_STATE_ACTIVE) ||
(iclog->ic_state == XLOG_STATE_WANT_SYNC));
cb->cb_next = NULL;
*(iclog->ic_callback_tail) = cb;
iclog->ic_callback_tail = &(cb->cb_next);
}
spin_unlock(&iclog->ic_callback_lock);
return abortflg;
}
int
xfs_log_release_iclog(
struct xfs_mount *mp,
struct xlog_in_core *iclog)
{
if (xlog_state_release_iclog(mp->m_log, iclog)) {
xfs_force_shutdown(mp, SHUTDOWN_LOG_IO_ERROR);
return EIO;
}
return 0;
}
int
xfs_log_mount(
xfs_mount_t *mp,
xfs_buftarg_t *log_target,
xfs_daddr_t blk_offset,
int num_bblks)
{
int error = 0;
int min_logfsbs;
if (!(mp->m_flags & XFS_MOUNT_NORECOVERY)) {
xfs_notice(mp, "Mounting V%d Filesystem",
XFS_SB_VERSION_NUM(&mp->m_sb));
} else {
xfs_notice(mp,
"Mounting V%d filesystem in no-recovery mode. Filesystem will be inconsistent.",
XFS_SB_VERSION_NUM(&mp->m_sb));
ASSERT(mp->m_flags & XFS_MOUNT_RDONLY);
}
mp->m_log = xlog_alloc_log(mp, log_target, blk_offset, num_bblks);
if (IS_ERR(mp->m_log)) {
error = -PTR_ERR(mp->m_log);
goto out;
}
min_logfsbs = xfs_log_calc_minimum_size(mp);
if (mp->m_sb.sb_logblocks < min_logfsbs) {
xfs_warn(mp,
"Log size %d blocks too small, minimum size is %d blocks",
mp->m_sb.sb_logblocks, min_logfsbs);
error = EINVAL;
} else if (mp->m_sb.sb_logblocks > XFS_MAX_LOG_BLOCKS) {
xfs_warn(mp,
"Log size %d blocks too large, maximum size is %lld blocks",
mp->m_sb.sb_logblocks, XFS_MAX_LOG_BLOCKS);
error = EINVAL;
} else if (XFS_FSB_TO_B(mp, mp->m_sb.sb_logblocks) > XFS_MAX_LOG_BYTES) {
xfs_warn(mp,
"log size %lld bytes too large, maximum size is %lld bytes",
XFS_FSB_TO_B(mp, mp->m_sb.sb_logblocks),
XFS_MAX_LOG_BYTES);
error = EINVAL;
}
if (error) {
if (xfs_sb_version_hascrc(&mp->m_sb)) {
xfs_crit(mp, "AAIEEE! Log failed size checks. Abort!");
ASSERT(0);
goto out_free_log;
}
xfs_crit(mp,
"Log size out of supported range. Continuing onwards, but if log hangs are\n"
"experienced then please report this message in the bug report.");
}
error = xfs_trans_ail_init(mp);
if (error) {
xfs_warn(mp, "AIL initialisation failed: error %d", error);
goto out_free_log;
}
mp->m_log->l_ailp = mp->m_ail;
if (!(mp->m_flags & XFS_MOUNT_NORECOVERY)) {
int readonly = (mp->m_flags & XFS_MOUNT_RDONLY);
if (readonly)
mp->m_flags &= ~XFS_MOUNT_RDONLY;
error = xlog_recover(mp->m_log);
if (readonly)
mp->m_flags |= XFS_MOUNT_RDONLY;
if (error) {
xfs_warn(mp, "log mount/recovery failed: error %d",
error);
goto out_destroy_ail;
}
}
mp->m_log->l_flags &= ~XLOG_ACTIVE_RECOVERY;
xlog_cil_init_post_recovery(mp->m_log);
return 0;
out_destroy_ail:
xfs_trans_ail_destroy(mp);
out_free_log:
xlog_dealloc_log(mp->m_log);
out:
return error;
}
int
xfs_log_mount_finish(xfs_mount_t *mp)
{
int error = 0;
if (!(mp->m_flags & XFS_MOUNT_NORECOVERY)) {
error = xlog_recover_finish(mp->m_log);
if (!error)
xfs_log_work_queue(mp);
} else {
ASSERT(mp->m_flags & XFS_MOUNT_RDONLY);
}
return error;
}
int
xfs_log_unmount_write(xfs_mount_t *mp)
{
struct xlog *log = mp->m_log;
xlog_in_core_t *iclog;
#ifdef DEBUG
xlog_in_core_t *first_iclog;
#endif
xlog_ticket_t *tic = NULL;
xfs_lsn_t lsn;
int error;
if (mp->m_flags & XFS_MOUNT_RDONLY)
return 0;
error = _xfs_log_force(mp, XFS_LOG_SYNC, NULL);
ASSERT(error || !(XLOG_FORCED_SHUTDOWN(log)));
#ifdef DEBUG
first_iclog = iclog = log->l_iclog;
do {
if (!(iclog->ic_state & XLOG_STATE_IOERROR)) {
ASSERT(iclog->ic_state & XLOG_STATE_ACTIVE);
ASSERT(iclog->ic_offset == 0);
}
iclog = iclog->ic_next;
} while (iclog != first_iclog);
#endif
if (! (XLOG_FORCED_SHUTDOWN(log))) {
error = xfs_log_reserve(mp, 600, 1, &tic,
XFS_LOG, 0, XLOG_UNMOUNT_REC_TYPE);
if (!error) {
struct {
__uint16_t magic;
__uint16_t pad1;
__uint32_t pad2;
} magic = {
.magic = XLOG_UNMOUNT_TYPE,
};
struct xfs_log_iovec reg = {
.i_addr = &magic,
.i_len = sizeof(magic),
.i_type = XLOG_REG_TYPE_UNMOUNT,
};
struct xfs_log_vec vec = {
.lv_niovecs = 1,
.lv_iovecp = &reg,
};
tic->t_flags = 0;
tic->t_curr_res -= sizeof(magic);
error = xlog_write(log, &vec, tic, &lsn,
NULL, XLOG_UNMOUNT_TRANS);
}
if (error)
xfs_alert(mp, "%s: unmount record failed", __func__);
spin_lock(&log->l_icloglock);
iclog = log->l_iclog;
atomic_inc(&iclog->ic_refcnt);
xlog_state_want_sync(log, iclog);
spin_unlock(&log->l_icloglock);
error = xlog_state_release_iclog(log, iclog);
spin_lock(&log->l_icloglock);
if (!(iclog->ic_state == XLOG_STATE_ACTIVE ||
iclog->ic_state == XLOG_STATE_DIRTY)) {
if (!XLOG_FORCED_SHUTDOWN(log)) {
xlog_wait(&iclog->ic_force_wait,
&log->l_icloglock);
} else {
spin_unlock(&log->l_icloglock);
}
} else {
spin_unlock(&log->l_icloglock);
}
if (tic) {
trace_xfs_log_umount_write(log, tic);
xlog_ungrant_log_space(log, tic);
xfs_log_ticket_put(tic);
}
} else {
spin_lock(&log->l_icloglock);
iclog = log->l_iclog;
atomic_inc(&iclog->ic_refcnt);
xlog_state_want_sync(log, iclog);
spin_unlock(&log->l_icloglock);
error = xlog_state_release_iclog(log, iclog);
spin_lock(&log->l_icloglock);
if ( ! ( iclog->ic_state == XLOG_STATE_ACTIVE
|| iclog->ic_state == XLOG_STATE_DIRTY
|| iclog->ic_state == XLOG_STATE_IOERROR) ) {
xlog_wait(&iclog->ic_force_wait,
&log->l_icloglock);
} else {
spin_unlock(&log->l_icloglock);
}
}
return error;
}
void
xfs_log_quiesce(
struct xfs_mount *mp)
{
cancel_delayed_work_sync(&mp->m_log->l_work);
xfs_log_force(mp, XFS_LOG_SYNC);
xfs_ail_push_all_sync(mp->m_ail);
xfs_wait_buftarg(mp->m_ddev_targp);
xfs_buf_lock(mp->m_sb_bp);
xfs_buf_unlock(mp->m_sb_bp);
xfs_log_unmount_write(mp);
}
void
xfs_log_unmount(
struct xfs_mount *mp)
{
xfs_log_quiesce(mp);
xfs_trans_ail_destroy(mp);
xlog_dealloc_log(mp->m_log);
}
void
xfs_log_item_init(
struct xfs_mount *mp,
struct xfs_log_item *item,
int type,
const struct xfs_item_ops *ops)
{
item->li_mountp = mp;
item->li_ailp = mp->m_ail;
item->li_type = type;
item->li_ops = ops;
item->li_lv = NULL;
INIT_LIST_HEAD(&item->li_ail);
INIT_LIST_HEAD(&item->li_cil);
}
void
xfs_log_space_wake(
struct xfs_mount *mp)
{
struct xlog *log = mp->m_log;
int free_bytes;
if (XLOG_FORCED_SHUTDOWN(log))
return;
if (!list_empty_careful(&log->l_write_head.waiters)) {
ASSERT(!(log->l_flags & XLOG_ACTIVE_RECOVERY));
spin_lock(&log->l_write_head.lock);
free_bytes = xlog_space_left(log, &log->l_write_head.grant);
xlog_grant_head_wake(log, &log->l_write_head, &free_bytes);
spin_unlock(&log->l_write_head.lock);
}
if (!list_empty_careful(&log->l_reserve_head.waiters)) {
ASSERT(!(log->l_flags & XLOG_ACTIVE_RECOVERY));
spin_lock(&log->l_reserve_head.lock);
free_bytes = xlog_space_left(log, &log->l_reserve_head.grant);
xlog_grant_head_wake(log, &log->l_reserve_head, &free_bytes);
spin_unlock(&log->l_reserve_head.lock);
}
}
int
xfs_log_need_covered(xfs_mount_t *mp)
{
struct xlog *log = mp->m_log;
int needed = 0;
if (!xfs_fs_writable(mp))
return 0;
if (!xlog_cil_empty(log))
return 0;
spin_lock(&log->l_icloglock);
switch (log->l_covered_state) {
case XLOG_STATE_COVER_DONE:
case XLOG_STATE_COVER_DONE2:
case XLOG_STATE_COVER_IDLE:
break;
case XLOG_STATE_COVER_NEED:
case XLOG_STATE_COVER_NEED2:
if (xfs_ail_min_lsn(log->l_ailp))
break;
if (!xlog_iclogs_empty(log))
break;
needed = 1;
if (log->l_covered_state == XLOG_STATE_COVER_NEED)
log->l_covered_state = XLOG_STATE_COVER_DONE;
else
log->l_covered_state = XLOG_STATE_COVER_DONE2;
break;
default:
needed = 1;
break;
}
spin_unlock(&log->l_icloglock);
return needed;
}
xfs_lsn_t
xlog_assign_tail_lsn_locked(
struct xfs_mount *mp)
{
struct xlog *log = mp->m_log;
struct xfs_log_item *lip;
xfs_lsn_t tail_lsn;
assert_spin_locked(&mp->m_ail->xa_lock);
lip = xfs_ail_min(mp->m_ail);
if (lip)
tail_lsn = lip->li_lsn;
else
tail_lsn = atomic64_read(&log->l_last_sync_lsn);
trace_xfs_log_assign_tail_lsn(log, tail_lsn);
atomic64_set(&log->l_tail_lsn, tail_lsn);
return tail_lsn;
}
xfs_lsn_t
xlog_assign_tail_lsn(
struct xfs_mount *mp)
{
xfs_lsn_t tail_lsn;
spin_lock(&mp->m_ail->xa_lock);
tail_lsn = xlog_assign_tail_lsn_locked(mp);
spin_unlock(&mp->m_ail->xa_lock);
return tail_lsn;
}
STATIC int
xlog_space_left(
struct xlog *log,
atomic64_t *head)
{
int free_bytes;
int tail_bytes;
int tail_cycle;
int head_cycle;
int head_bytes;
xlog_crack_grant_head(head, &head_cycle, &head_bytes);
xlog_crack_atomic_lsn(&log->l_tail_lsn, &tail_cycle, &tail_bytes);
tail_bytes = BBTOB(tail_bytes);
if (tail_cycle == head_cycle && head_bytes >= tail_bytes)
free_bytes = log->l_logsize - (head_bytes - tail_bytes);
else if (tail_cycle + 1 < head_cycle)
return 0;
else if (tail_cycle < head_cycle) {
ASSERT(tail_cycle == (head_cycle - 1));
free_bytes = tail_bytes - head_bytes;
} else {
xfs_alert(log->l_mp,
"xlog_space_left: head behind tail\n"
" tail_cycle = %d, tail_bytes = %d\n"
" GH cycle = %d, GH bytes = %d",
tail_cycle, tail_bytes, head_cycle, head_bytes);
ASSERT(0);
free_bytes = log->l_logsize;
}
return free_bytes;
}
void
xlog_iodone(xfs_buf_t *bp)
{
struct xlog_in_core *iclog = bp->b_fspriv;
struct xlog *l = iclog->ic_log;
int aborted = 0;
if (XFS_TEST_ERROR(bp->b_error, l->l_mp,
XFS_ERRTAG_IODONE_IOERR, XFS_RANDOM_IODONE_IOERR)) {
xfs_buf_ioerror_alert(bp, __func__);
xfs_buf_stale(bp);
xfs_force_shutdown(l->l_mp, SHUTDOWN_LOG_IO_ERROR);
aborted = XFS_LI_ABORTED;
} else if (iclog->ic_state & XLOG_STATE_IOERROR) {
aborted = XFS_LI_ABORTED;
}
ASSERT(XFS_BUF_ISASYNC(bp));
xlog_state_done_syncing(iclog, aborted);
xfs_buf_unlock(bp);
}
STATIC void
xlog_get_iclog_buffer_size(
struct xfs_mount *mp,
struct xlog *log)
{
int size;
int xhdrs;
if (mp->m_logbufs <= 0)
log->l_iclog_bufs = XLOG_MAX_ICLOGS;
else
log->l_iclog_bufs = mp->m_logbufs;
if (mp->m_logbsize > 0) {
size = log->l_iclog_size = mp->m_logbsize;
log->l_iclog_size_log = 0;
while (size != 1) {
log->l_iclog_size_log++;
size >>= 1;
}
if (xfs_sb_version_haslogv2(&mp->m_sb)) {
xhdrs = mp->m_logbsize / XLOG_HEADER_CYCLE_SIZE;
if (mp->m_logbsize % XLOG_HEADER_CYCLE_SIZE)
xhdrs++;
log->l_iclog_hsize = xhdrs << BBSHIFT;
log->l_iclog_heads = xhdrs;
} else {
ASSERT(mp->m_logbsize <= XLOG_BIG_RECORD_BSIZE);
log->l_iclog_hsize = BBSIZE;
log->l_iclog_heads = 1;
}
goto done;
}
log->l_iclog_size = XLOG_BIG_RECORD_BSIZE;
log->l_iclog_size_log = XLOG_BIG_RECORD_BSHIFT;
log->l_iclog_hsize = BBSIZE;
log->l_iclog_heads = 1;
done:
if (mp->m_logbufs == 0)
mp->m_logbufs = log->l_iclog_bufs;
if (mp->m_logbsize == 0)
mp->m_logbsize = log->l_iclog_size;
}
void
xfs_log_work_queue(
struct xfs_mount *mp)
{
queue_delayed_work(mp->m_log_workqueue, &mp->m_log->l_work,
msecs_to_jiffies(xfs_syncd_centisecs * 10));
}
void
xfs_log_worker(
struct work_struct *work)
{
struct xlog *log = container_of(to_delayed_work(work),
struct xlog, l_work);
struct xfs_mount *mp = log->l_mp;
if (xfs_log_need_covered(mp))
xfs_fs_log_dummy(mp);
else
xfs_log_force(mp, 0);
xfs_ail_push_all(mp->m_ail);
xfs_log_work_queue(mp);
}
STATIC struct xlog *
xlog_alloc_log(
struct xfs_mount *mp,
struct xfs_buftarg *log_target,
xfs_daddr_t blk_offset,
int num_bblks)
{
struct xlog *log;
xlog_rec_header_t *head;
xlog_in_core_t **iclogp;
xlog_in_core_t *iclog, *prev_iclog=NULL;
xfs_buf_t *bp;
int i;
int error = ENOMEM;
uint log2_size = 0;
log = kmem_zalloc(sizeof(struct xlog), KM_MAYFAIL);
if (!log) {
xfs_warn(mp, "Log allocation failed: No memory!");
goto out;
}
log->l_mp = mp;
log->l_targ = log_target;
log->l_logsize = BBTOB(num_bblks);
log->l_logBBstart = blk_offset;
log->l_logBBsize = num_bblks;
log->l_covered_state = XLOG_STATE_COVER_IDLE;
log->l_flags |= XLOG_ACTIVE_RECOVERY;
INIT_DELAYED_WORK(&log->l_work, xfs_log_worker);
log->l_prev_block = -1;
xlog_assign_atomic_lsn(&log->l_tail_lsn, 1, 0);
xlog_assign_atomic_lsn(&log->l_last_sync_lsn, 1, 0);
log->l_curr_cycle = 1;
xlog_grant_head_init(&log->l_reserve_head);
xlog_grant_head_init(&log->l_write_head);
error = EFSCORRUPTED;
if (xfs_sb_version_hassector(&mp->m_sb)) {
log2_size = mp->m_sb.sb_logsectlog;
if (log2_size < BBSHIFT) {
xfs_warn(mp, "Log sector size too small (0x%x < 0x%x)",
log2_size, BBSHIFT);
goto out_free_log;
}
log2_size -= BBSHIFT;
if (log2_size > mp->m_sectbb_log) {
xfs_warn(mp, "Log sector size too large (0x%x > 0x%x)",
log2_size, mp->m_sectbb_log);
goto out_free_log;
}
if (log2_size && log->l_logBBstart > 0 &&
!xfs_sb_version_haslogv2(&mp->m_sb)) {
xfs_warn(mp,
"log sector size (0x%x) invalid for configuration.",
log2_size);
goto out_free_log;
}
}
log->l_sectBBsize = 1 << log2_size;
xlog_get_iclog_buffer_size(mp, log);
error = ENOMEM;
bp = xfs_buf_alloc(mp->m_logdev_targp, 0, BTOBB(log->l_iclog_size), 0);
if (!bp)
goto out_free_log;
ASSERT(xfs_buf_islocked(bp));
xfs_buf_unlock(bp);
bp->b_iodone = xlog_iodone;
log->l_xbuf = bp;
spin_lock_init(&log->l_icloglock);
init_waitqueue_head(&log->l_flush_wait);
iclogp = &log->l_iclog;
ASSERT(log->l_iclog_size >= 4096);
for (i=0; i < log->l_iclog_bufs; i++) {
*iclogp = kmem_zalloc(sizeof(xlog_in_core_t), KM_MAYFAIL);
if (!*iclogp)
goto out_free_iclog;
iclog = *iclogp;
iclog->ic_prev = prev_iclog;
prev_iclog = iclog;
bp = xfs_buf_get_uncached(mp->m_logdev_targp,
BTOBB(log->l_iclog_size), 0);
if (!bp)
goto out_free_iclog;
ASSERT(xfs_buf_islocked(bp));
xfs_buf_unlock(bp);
bp->b_iodone = xlog_iodone;
iclog->ic_bp = bp;
iclog->ic_data = bp->b_addr;
#ifdef DEBUG
log->l_iclog_bak[i] = (xfs_caddr_t)&(iclog->ic_header);
#endif
head = &iclog->ic_header;
memset(head, 0, sizeof(xlog_rec_header_t));
head->h_magicno = cpu_to_be32(XLOG_HEADER_MAGIC_NUM);
head->h_version = cpu_to_be32(
xfs_sb_version_haslogv2(&log->l_mp->m_sb) ? 2 : 1);
head->h_size = cpu_to_be32(log->l_iclog_size);
head->h_fmt = cpu_to_be32(XLOG_FMT);
memcpy(&head->h_fs_uuid, &mp->m_sb.sb_uuid, sizeof(uuid_t));
iclog->ic_size = BBTOB(bp->b_length) - log->l_iclog_hsize;
iclog->ic_state = XLOG_STATE_ACTIVE;
iclog->ic_log = log;
atomic_set(&iclog->ic_refcnt, 0);
spin_lock_init(&iclog->ic_callback_lock);
iclog->ic_callback_tail = &(iclog->ic_callback);
iclog->ic_datap = (char *)iclog->ic_data + log->l_iclog_hsize;
init_waitqueue_head(&iclog->ic_force_wait);
init_waitqueue_head(&iclog->ic_write_wait);
iclogp = &iclog->ic_next;
}
*iclogp = log->l_iclog;
log->l_iclog->ic_prev = prev_iclog;
error = xlog_cil_init(log);
if (error)
goto out_free_iclog;
return log;
out_free_iclog:
for (iclog = log->l_iclog; iclog; iclog = prev_iclog) {
prev_iclog = iclog->ic_next;
if (iclog->ic_bp)
xfs_buf_free(iclog->ic_bp);
kmem_free(iclog);
}
spinlock_destroy(&log->l_icloglock);
xfs_buf_free(log->l_xbuf);
out_free_log:
kmem_free(log);
out:
return ERR_PTR(-error);
}
STATIC int
xlog_commit_record(
struct xlog *log,
struct xlog_ticket *ticket,
struct xlog_in_core **iclog,
xfs_lsn_t *commitlsnp)
{
struct xfs_mount *mp = log->l_mp;
int error;
struct xfs_log_iovec reg = {
.i_addr = NULL,
.i_len = 0,
.i_type = XLOG_REG_TYPE_COMMIT,
};
struct xfs_log_vec vec = {
.lv_niovecs = 1,
.lv_iovecp = &reg,
};
ASSERT_ALWAYS(iclog);
error = xlog_write(log, &vec, ticket, commitlsnp, iclog,
XLOG_COMMIT_TRANS);
if (error)
xfs_force_shutdown(mp, SHUTDOWN_LOG_IO_ERROR);
return error;
}
STATIC void
xlog_grant_push_ail(
struct xlog *log,
int need_bytes)
{
xfs_lsn_t threshold_lsn = 0;
xfs_lsn_t last_sync_lsn;
int free_blocks;
int free_bytes;
int threshold_block;
int threshold_cycle;
int free_threshold;
ASSERT(BTOBB(need_bytes) < log->l_logBBsize);
free_bytes = xlog_space_left(log, &log->l_reserve_head.grant);
free_blocks = BTOBBT(free_bytes);
free_threshold = BTOBB(need_bytes);
free_threshold = MAX(free_threshold, (log->l_logBBsize >> 2));
free_threshold = MAX(free_threshold, 256);
if (free_blocks >= free_threshold)
return;
xlog_crack_atomic_lsn(&log->l_tail_lsn, &threshold_cycle,
&threshold_block);
threshold_block += free_threshold;
if (threshold_block >= log->l_logBBsize) {
threshold_block -= log->l_logBBsize;
threshold_cycle += 1;
}
threshold_lsn = xlog_assign_lsn(threshold_cycle,
threshold_block);
last_sync_lsn = atomic64_read(&log->l_last_sync_lsn);
if (XFS_LSN_CMP(threshold_lsn, last_sync_lsn) > 0)
threshold_lsn = last_sync_lsn;
if (!XLOG_FORCED_SHUTDOWN(log))
xfs_ail_push(log->l_ailp, threshold_lsn);
}
STATIC void
xlog_pack_data(
struct xlog *log,
struct xlog_in_core *iclog,
int roundoff)
{
int i, j, k;
int size = iclog->ic_offset + roundoff;
__be32 cycle_lsn;
xfs_caddr_t dp;
cycle_lsn = CYCLE_LSN_DISK(iclog->ic_header.h_lsn);
dp = iclog->ic_datap;
for (i = 0; i < BTOBB(size); i++) {
if (i >= (XLOG_HEADER_CYCLE_SIZE / BBSIZE))
break;
iclog->ic_header.h_cycle_data[i] = *(__be32 *)dp;
*(__be32 *)dp = cycle_lsn;
dp += BBSIZE;
}
if (xfs_sb_version_haslogv2(&log->l_mp->m_sb)) {
xlog_in_core_2_t *xhdr = iclog->ic_data;
for ( ; i < BTOBB(size); i++) {
j = i / (XLOG_HEADER_CYCLE_SIZE / BBSIZE);
k = i % (XLOG_HEADER_CYCLE_SIZE / BBSIZE);
xhdr[j].hic_xheader.xh_cycle_data[k] = *(__be32 *)dp;
*(__be32 *)dp = cycle_lsn;
dp += BBSIZE;
}
for (i = 1; i < log->l_iclog_heads; i++)
xhdr[i].hic_xheader.xh_cycle = cycle_lsn;
}
}
__le32
xlog_cksum(
struct xlog *log,
struct xlog_rec_header *rhead,
char *dp,
int size)
{
__uint32_t crc;
crc = xfs_start_cksum((char *)rhead,
sizeof(struct xlog_rec_header),
offsetof(struct xlog_rec_header, h_crc));
if (xfs_sb_version_haslogv2(&log->l_mp->m_sb)) {
union xlog_in_core2 *xhdr = (union xlog_in_core2 *)rhead;
int i;
for (i = 1; i < log->l_iclog_heads; i++) {
crc = crc32c(crc, &xhdr[i].hic_xheader,
sizeof(struct xlog_rec_ext_header));
}
}
crc = crc32c(crc, dp, size);
return xfs_end_cksum(crc);
}
STATIC int
xlog_bdstrat(
struct xfs_buf *bp)
{
struct xlog_in_core *iclog = bp->b_fspriv;
xfs_buf_lock(bp);
if (iclog->ic_state & XLOG_STATE_IOERROR) {
xfs_buf_ioerror(bp, EIO);
xfs_buf_stale(bp);
xfs_buf_ioend(bp, 0);
return 0;
}
xfs_buf_iorequest(bp);
return 0;
}
STATIC int
xlog_sync(
struct xlog *log,
struct xlog_in_core *iclog)
{
xfs_buf_t *bp;
int i;
uint count;
uint count_init;
int roundoff;
int split = 0;
int error;
int v2 = xfs_sb_version_haslogv2(&log->l_mp->m_sb);
int size;
XFS_STATS_INC(xs_log_writes);
ASSERT(atomic_read(&iclog->ic_refcnt) == 0);
count_init = log->l_iclog_hsize + iclog->ic_offset;
if (v2 && log->l_mp->m_sb.sb_logsunit > 1) {
count = XLOG_LSUNITTOB(log, XLOG_BTOLSUNIT(log, count_init));
} else {
count = BBTOB(BTOBB(count_init));
}
roundoff = count - count_init;
ASSERT(roundoff >= 0);
ASSERT((v2 && log->l_mp->m_sb.sb_logsunit > 1 &&
roundoff < log->l_mp->m_sb.sb_logsunit)
||
(log->l_mp->m_sb.sb_logsunit <= 1 &&
roundoff < BBTOB(1)));
xlog_grant_add_space(log, &log->l_reserve_head.grant, roundoff);
xlog_grant_add_space(log, &log->l_write_head.grant, roundoff);
xlog_pack_data(log, iclog, roundoff);
size = iclog->ic_offset;
if (v2)
size += roundoff;
iclog->ic_header.h_len = cpu_to_be32(size);
bp = iclog->ic_bp;
XFS_BUF_SET_ADDR(bp, BLOCK_LSN(be64_to_cpu(iclog->ic_header.h_lsn)));
XFS_STATS_ADD(xs_log_blocks, BTOBB(count));
if (XFS_BUF_ADDR(bp) + BTOBB(count) > log->l_logBBsize) {
char *dptr;
split = count - (BBTOB(log->l_logBBsize - XFS_BUF_ADDR(bp)));
count = BBTOB(log->l_logBBsize - XFS_BUF_ADDR(bp));
iclog->ic_bwritecnt = 2;
dptr = (char *)&iclog->ic_header + count;
for (i = 0; i < split; i += BBSIZE) {
__uint32_t cycle = be32_to_cpu(*(__be32 *)dptr);
if (++cycle == XLOG_HEADER_MAGIC_NUM)
cycle++;
*(__be32 *)dptr = cpu_to_be32(cycle);
dptr += BBSIZE;
}
} else {
iclog->ic_bwritecnt = 1;
}
iclog->ic_header.h_crc = xlog_cksum(log, &iclog->ic_header,
iclog->ic_datap, size);
bp->b_io_length = BTOBB(count);
bp->b_fspriv = iclog;
XFS_BUF_ZEROFLAGS(bp);
XFS_BUF_ASYNC(bp);
bp->b_flags |= XBF_SYNCIO;
if (log->l_mp->m_flags & XFS_MOUNT_BARRIER) {
bp->b_flags |= XBF_FUA;
if (log->l_mp->m_logdev_targp != log->l_mp->m_ddev_targp)
xfs_blkdev_issue_flush(log->l_mp->m_ddev_targp);
else
bp->b_flags |= XBF_FLUSH;
}
ASSERT(XFS_BUF_ADDR(bp) <= log->l_logBBsize-1);
ASSERT(XFS_BUF_ADDR(bp) + BTOBB(count) <= log->l_logBBsize);
xlog_verify_iclog(log, iclog, count, true);
XFS_BUF_SET_ADDR(bp, XFS_BUF_ADDR(bp) + log->l_logBBstart);
XFS_BUF_WRITE(bp);
error = xlog_bdstrat(bp);
if (error) {
xfs_buf_ioerror_alert(bp, "xlog_sync");
return error;
}
if (split) {
bp = iclog->ic_log->l_xbuf;
XFS_BUF_SET_ADDR(bp, 0);
xfs_buf_associate_memory(bp,
(char *)&iclog->ic_header + count, split);
bp->b_fspriv = iclog;
XFS_BUF_ZEROFLAGS(bp);
XFS_BUF_ASYNC(bp);
bp->b_flags |= XBF_SYNCIO;
if (log->l_mp->m_flags & XFS_MOUNT_BARRIER)
bp->b_flags |= XBF_FUA;
ASSERT(XFS_BUF_ADDR(bp) <= log->l_logBBsize-1);
ASSERT(XFS_BUF_ADDR(bp) + BTOBB(count) <= log->l_logBBsize);
XFS_BUF_SET_ADDR(bp, XFS_BUF_ADDR(bp) + log->l_logBBstart);
XFS_BUF_WRITE(bp);
error = xlog_bdstrat(bp);
if (error) {
xfs_buf_ioerror_alert(bp, "xlog_sync (split)");
return error;
}
}
return 0;
}
STATIC void
xlog_dealloc_log(
struct xlog *log)
{
xlog_in_core_t *iclog, *next_iclog;
int i;
xlog_cil_destroy(log);
iclog = log->l_iclog;
for (i = 0; i < log->l_iclog_bufs; i++) {
xfs_buf_lock(iclog->ic_bp);
xfs_buf_unlock(iclog->ic_bp);
iclog = iclog->ic_next;
}
xfs_buf_lock(log->l_xbuf);
xfs_buf_unlock(log->l_xbuf);
xfs_buf_set_empty(log->l_xbuf, BTOBB(log->l_iclog_size));
xfs_buf_free(log->l_xbuf);
iclog = log->l_iclog;
for (i = 0; i < log->l_iclog_bufs; i++) {
xfs_buf_free(iclog->ic_bp);
next_iclog = iclog->ic_next;
kmem_free(iclog);
iclog = next_iclog;
}
spinlock_destroy(&log->l_icloglock);
log->l_mp->m_log = NULL;
kmem_free(log);
}
static inline void
xlog_state_finish_copy(
struct xlog *log,
struct xlog_in_core *iclog,
int record_cnt,
int copy_bytes)
{
spin_lock(&log->l_icloglock);
be32_add_cpu(&iclog->ic_header.h_num_logops, record_cnt);
iclog->ic_offset += copy_bytes;
spin_unlock(&log->l_icloglock);
}
void
xlog_print_tic_res(
struct xfs_mount *mp,
struct xlog_ticket *ticket)
{
uint i;
uint ophdr_spc = ticket->t_res_num_ophdrs * (uint)sizeof(xlog_op_header_t);
static char *res_type_str[XLOG_REG_TYPE_MAX] = {
"bformat",
"bchunk",
"efi_format",
"efd_format",
"iformat",
"icore",
"iext",
"ibroot",
"ilocal",
"iattr_ext",
"iattr_broot",
"iattr_local",
"qformat",
"dquot",
"quotaoff",
"LR header",
"unmount",
"commit",
"trans header"
};
static char *trans_type_str[XFS_TRANS_TYPE_MAX] = {
"SETATTR_NOT_SIZE",
"SETATTR_SIZE",
"INACTIVE",
"CREATE",
"CREATE_TRUNC",
"TRUNCATE_FILE",
"REMOVE",
"LINK",
"RENAME",
"MKDIR",
"RMDIR",
"SYMLINK",
"SET_DMATTRS",
"GROWFS",
"STRAT_WRITE",
"DIOSTRAT",
"WRITE_SYNC",
"WRITEID",
"ADDAFORK",
"ATTRINVAL",
"ATRUNCATE",
"ATTR_SET",
"ATTR_RM",
"ATTR_FLAG",
"CLEAR_AGI_BUCKET",
"QM_SBCHANGE",
"DUMMY1",
"DUMMY2",
"QM_QUOTAOFF",
"QM_DQALLOC",
"QM_SETQLIM",
"QM_DQCLUSTER",
"QM_QINOCREATE",
"QM_QUOTAOFF_END",
"SB_UNIT",
"FSYNC_TS",
"GROWFSRT_ALLOC",
"GROWFSRT_ZERO",
"GROWFSRT_FREE",
"SWAPEXT"
};
xfs_warn(mp,
"xlog_write: reservation summary:\n"
" trans type = %s (%u)\n"
" unit res = %d bytes\n"
" current res = %d bytes\n"
" total reg = %u bytes (o/flow = %u bytes)\n"
" ophdrs = %u (ophdr space = %u bytes)\n"
" ophdr + reg = %u bytes\n"
" num regions = %u\n",
((ticket->t_trans_type <= 0 ||
ticket->t_trans_type > XFS_TRANS_TYPE_MAX) ?
"bad-trans-type" : trans_type_str[ticket->t_trans_type-1]),
ticket->t_trans_type,
ticket->t_unit_res,
ticket->t_curr_res,
ticket->t_res_arr_sum, ticket->t_res_o_flow,
ticket->t_res_num_ophdrs, ophdr_spc,
ticket->t_res_arr_sum +
ticket->t_res_o_flow + ophdr_spc,
ticket->t_res_num);
for (i = 0; i < ticket->t_res_num; i++) {
uint r_type = ticket->t_res_arr[i].r_type;
xfs_warn(mp, "region[%u]: %s - %u bytes", i,
((r_type <= 0 || r_type > XLOG_REG_TYPE_MAX) ?
"bad-rtype" : res_type_str[r_type-1]),
ticket->t_res_arr[i].r_len);
}
xfs_alert_tag(mp, XFS_PTAG_LOGRES,
"xlog_write: reservation ran out. Need to up reservation");
xfs_force_shutdown(mp, SHUTDOWN_LOG_IO_ERROR);
}
static int
xlog_write_calc_vec_length(
struct xlog_ticket *ticket,
struct xfs_log_vec *log_vector)
{
struct xfs_log_vec *lv;
int headers = 0;
int len = 0;
int i;
if (ticket->t_flags & XLOG_TIC_INITED)
headers++;
for (lv = log_vector; lv; lv = lv->lv_next) {
if (lv->lv_buf_len == XFS_LOG_VEC_ORDERED)
continue;
headers += lv->lv_niovecs;
for (i = 0; i < lv->lv_niovecs; i++) {
struct xfs_log_iovec *vecp = &lv->lv_iovecp[i];
len += vecp->i_len;
xlog_tic_add_region(ticket, vecp->i_len, vecp->i_type);
}
}
ticket->t_res_num_ophdrs += headers;
len += headers * sizeof(struct xlog_op_header);
return len;
}
static int
xlog_write_start_rec(
struct xlog_op_header *ophdr,
struct xlog_ticket *ticket)
{
if (!(ticket->t_flags & XLOG_TIC_INITED))
return 0;
ophdr->oh_tid = cpu_to_be32(ticket->t_tid);
ophdr->oh_clientid = ticket->t_clientid;
ophdr->oh_len = 0;
ophdr->oh_flags = XLOG_START_TRANS;
ophdr->oh_res2 = 0;
ticket->t_flags &= ~XLOG_TIC_INITED;
return sizeof(struct xlog_op_header);
}
static xlog_op_header_t *
xlog_write_setup_ophdr(
struct xlog *log,
struct xlog_op_header *ophdr,
struct xlog_ticket *ticket,
uint flags)
{
ophdr->oh_tid = cpu_to_be32(ticket->t_tid);
ophdr->oh_clientid = ticket->t_clientid;
ophdr->oh_res2 = 0;
ophdr->oh_flags = flags;
switch (ophdr->oh_clientid) {
case XFS_TRANSACTION:
case XFS_VOLUME:
case XFS_LOG:
break;
default:
xfs_warn(log->l_mp,
"Bad XFS transaction clientid 0x%x in ticket 0x%p",
ophdr->oh_clientid, ticket);
return NULL;
}
return ophdr;
}
static int
xlog_write_setup_copy(
struct xlog_ticket *ticket,
struct xlog_op_header *ophdr,
int space_available,
int space_required,
int *copy_off,
int *copy_len,
int *last_was_partial_copy,
int *bytes_consumed)
{
int still_to_copy;
still_to_copy = space_required - *bytes_consumed;
*copy_off = *bytes_consumed;
if (still_to_copy <= space_available) {
*copy_len = still_to_copy;
ophdr->oh_len = cpu_to_be32(*copy_len);
if (*last_was_partial_copy)
ophdr->oh_flags |= (XLOG_END_TRANS|XLOG_WAS_CONT_TRANS);
*last_was_partial_copy = 0;
*bytes_consumed = 0;
return 0;
}
*copy_len = space_available;
ophdr->oh_len = cpu_to_be32(*copy_len);
ophdr->oh_flags |= XLOG_CONTINUE_TRANS;
if (*last_was_partial_copy)
ophdr->oh_flags |= XLOG_WAS_CONT_TRANS;
*bytes_consumed += *copy_len;
(*last_was_partial_copy)++;
ticket->t_curr_res -= sizeof(struct xlog_op_header);
ticket->t_res_num_ophdrs++;
return sizeof(struct xlog_op_header);
}
static int
xlog_write_copy_finish(
struct xlog *log,
struct xlog_in_core *iclog,
uint flags,
int *record_cnt,
int *data_cnt,
int *partial_copy,
int *partial_copy_len,
int log_offset,
struct xlog_in_core **commit_iclog)
{
if (*partial_copy) {
xlog_state_finish_copy(log, iclog, *record_cnt, *data_cnt);
*record_cnt = 0;
*data_cnt = 0;
return xlog_state_release_iclog(log, iclog);
}
*partial_copy = 0;
*partial_copy_len = 0;
if (iclog->ic_size - log_offset <= sizeof(xlog_op_header_t)) {
xlog_state_finish_copy(log, iclog, *record_cnt, *data_cnt);
*record_cnt = 0;
*data_cnt = 0;
spin_lock(&log->l_icloglock);
xlog_state_want_sync(log, iclog);
spin_unlock(&log->l_icloglock);
if (!commit_iclog)
return xlog_state_release_iclog(log, iclog);
ASSERT(flags & XLOG_COMMIT_TRANS);
*commit_iclog = iclog;
}
return 0;
}
int
xlog_write(
struct xlog *log,
struct xfs_log_vec *log_vector,
struct xlog_ticket *ticket,
xfs_lsn_t *start_lsn,
struct xlog_in_core **commit_iclog,
uint flags)
{
struct xlog_in_core *iclog = NULL;
struct xfs_log_iovec *vecp;
struct xfs_log_vec *lv;
int len;
int index;
int partial_copy = 0;
int partial_copy_len = 0;
int contwr = 0;
int record_cnt = 0;
int data_cnt = 0;
int error;
*start_lsn = 0;
len = xlog_write_calc_vec_length(ticket, log_vector);
if (ticket->t_flags & XLOG_TIC_INITED)
ticket->t_curr_res -= sizeof(xlog_op_header_t);
if (flags & (XLOG_COMMIT_TRANS | XLOG_UNMOUNT_TRANS))
ticket->t_curr_res -= sizeof(xlog_op_header_t);
if (ticket->t_curr_res < 0)
xlog_print_tic_res(log->l_mp, ticket);
index = 0;
lv = log_vector;
vecp = lv->lv_iovecp;
while (lv && (!lv->lv_niovecs || index < lv->lv_niovecs)) {
void *ptr;
int log_offset;
error = xlog_state_get_iclog_space(log, len, &iclog, ticket,
&contwr, &log_offset);
if (error)
return error;
ASSERT(log_offset <= iclog->ic_size - 1);
ptr = iclog->ic_datap + log_offset;
if (!*start_lsn)
*start_lsn = be64_to_cpu(iclog->ic_header.h_lsn);
while (lv && (!lv->lv_niovecs || index < lv->lv_niovecs)) {
struct xfs_log_iovec *reg;
struct xlog_op_header *ophdr;
int start_rec_copy;
int copy_len;
int copy_off;
bool ordered = false;
if (lv->lv_buf_len == XFS_LOG_VEC_ORDERED) {
ASSERT(lv->lv_niovecs == 0);
ordered = true;
goto next_lv;
}
reg = &vecp[index];
ASSERT(reg->i_len % sizeof(__int32_t) == 0);
ASSERT((unsigned long)ptr % sizeof(__int32_t) == 0);
start_rec_copy = xlog_write_start_rec(ptr, ticket);
if (start_rec_copy) {
record_cnt++;
xlog_write_adv_cnt(&ptr, &len, &log_offset,
start_rec_copy);
}
ophdr = xlog_write_setup_ophdr(log, ptr, ticket, flags);
if (!ophdr)
return XFS_ERROR(EIO);
xlog_write_adv_cnt(&ptr, &len, &log_offset,
sizeof(struct xlog_op_header));
len += xlog_write_setup_copy(ticket, ophdr,
iclog->ic_size-log_offset,
reg->i_len,
&copy_off, &copy_len,
&partial_copy,
&partial_copy_len);
xlog_verify_dest_ptr(log, ptr);
ASSERT(copy_len >= 0);
memcpy(ptr, reg->i_addr + copy_off, copy_len);
xlog_write_adv_cnt(&ptr, &len, &log_offset, copy_len);
copy_len += start_rec_copy + sizeof(xlog_op_header_t);
record_cnt++;
data_cnt += contwr ? copy_len : 0;
error = xlog_write_copy_finish(log, iclog, flags,
&record_cnt, &data_cnt,
&partial_copy,
&partial_copy_len,
log_offset,
commit_iclog);
if (error)
return error;
if (partial_copy)
break;
if (++index == lv->lv_niovecs) {
next_lv:
lv = lv->lv_next;
index = 0;
if (lv)
vecp = lv->lv_iovecp;
}
if (record_cnt == 0 && ordered == false) {
if (!lv)
return 0;
break;
}
}
}
ASSERT(len == 0);
xlog_state_finish_copy(log, iclog, record_cnt, data_cnt);
if (!commit_iclog)
return xlog_state_release_iclog(log, iclog);
ASSERT(flags & XLOG_COMMIT_TRANS);
*commit_iclog = iclog;
return 0;
}
STATIC void
xlog_state_clean_log(
struct xlog *log)
{
xlog_in_core_t *iclog;
int changed = 0;
iclog = log->l_iclog;
do {
if (iclog->ic_state == XLOG_STATE_DIRTY) {
iclog->ic_state = XLOG_STATE_ACTIVE;
iclog->ic_offset = 0;
ASSERT(iclog->ic_callback == NULL);
if (!changed &&
(be32_to_cpu(iclog->ic_header.h_num_logops) ==
XLOG_COVER_OPS)) {
changed = 1;
} else {
changed = 2;
}
iclog->ic_header.h_num_logops = 0;
memset(iclog->ic_header.h_cycle_data, 0,
sizeof(iclog->ic_header.h_cycle_data));
iclog->ic_header.h_lsn = 0;
} else if (iclog->ic_state == XLOG_STATE_ACTIVE)
;
else
break;
iclog = iclog->ic_next;
} while (iclog != log->l_iclog);
if (changed) {
switch (log->l_covered_state) {
case XLOG_STATE_COVER_IDLE:
case XLOG_STATE_COVER_NEED:
case XLOG_STATE_COVER_NEED2:
log->l_covered_state = XLOG_STATE_COVER_NEED;
break;
case XLOG_STATE_COVER_DONE:
if (changed == 1)
log->l_covered_state = XLOG_STATE_COVER_NEED2;
else
log->l_covered_state = XLOG_STATE_COVER_NEED;
break;
case XLOG_STATE_COVER_DONE2:
if (changed == 1)
log->l_covered_state = XLOG_STATE_COVER_IDLE;
else
log->l_covered_state = XLOG_STATE_COVER_NEED;
break;
default:
ASSERT(0);
}
}
}
STATIC xfs_lsn_t
xlog_get_lowest_lsn(
struct xlog *log)
{
xlog_in_core_t *lsn_log;
xfs_lsn_t lowest_lsn, lsn;
lsn_log = log->l_iclog;
lowest_lsn = 0;
do {
if (!(lsn_log->ic_state & (XLOG_STATE_ACTIVE|XLOG_STATE_DIRTY))) {
lsn = be64_to_cpu(lsn_log->ic_header.h_lsn);
if ((lsn && !lowest_lsn) ||
(XFS_LSN_CMP(lsn, lowest_lsn) < 0)) {
lowest_lsn = lsn;
}
}
lsn_log = lsn_log->ic_next;
} while (lsn_log != log->l_iclog);
return lowest_lsn;
}
STATIC void
xlog_state_do_callback(
struct xlog *log,
int aborted,
struct xlog_in_core *ciclog)
{
xlog_in_core_t *iclog;
xlog_in_core_t *first_iclog;
xfs_log_callback_t *cb, *cb_next;
int flushcnt = 0;
xfs_lsn_t lowest_lsn;
int ioerrors;
int loopdidcallbacks;
int funcdidcallbacks;
int repeats;
int wake = 0;
spin_lock(&log->l_icloglock);
first_iclog = iclog = log->l_iclog;
ioerrors = 0;
funcdidcallbacks = 0;
repeats = 0;
do {
first_iclog = log->l_iclog;
iclog = log->l_iclog;
loopdidcallbacks = 0;
repeats++;
do {
if (iclog->ic_state &
(XLOG_STATE_ACTIVE|XLOG_STATE_DIRTY)) {
iclog = iclog->ic_next;
continue;
}
if (!(iclog->ic_state & XLOG_STATE_IOERROR)) {
if (!(iclog->ic_state &
(XLOG_STATE_DONE_SYNC |
XLOG_STATE_DO_CALLBACK))) {
if (ciclog && (ciclog->ic_state ==
XLOG_STATE_DONE_SYNC)) {
ciclog->ic_state = XLOG_STATE_DO_CALLBACK;
}
break;
}
lowest_lsn = xlog_get_lowest_lsn(log);
if (lowest_lsn &&
XFS_LSN_CMP(lowest_lsn,
be64_to_cpu(iclog->ic_header.h_lsn)) < 0) {
iclog = iclog->ic_next;
continue;
}
iclog->ic_state = XLOG_STATE_CALLBACK;
ASSERT(XFS_LSN_CMP(atomic64_read(&log->l_last_sync_lsn),
be64_to_cpu(iclog->ic_header.h_lsn)) <= 0);
if (iclog->ic_callback)
atomic64_set(&log->l_last_sync_lsn,
be64_to_cpu(iclog->ic_header.h_lsn));
} else
ioerrors++;
spin_unlock(&log->l_icloglock);
spin_lock(&iclog->ic_callback_lock);
cb = iclog->ic_callback;
while (cb) {
iclog->ic_callback_tail = &(iclog->ic_callback);
iclog->ic_callback = NULL;
spin_unlock(&iclog->ic_callback_lock);
for (; cb; cb = cb_next) {
cb_next = cb->cb_next;
cb->cb_func(cb->cb_arg, aborted);
}
spin_lock(&iclog->ic_callback_lock);
cb = iclog->ic_callback;
}
loopdidcallbacks++;
funcdidcallbacks++;
spin_lock(&log->l_icloglock);
ASSERT(iclog->ic_callback == NULL);
spin_unlock(&iclog->ic_callback_lock);
if (!(iclog->ic_state & XLOG_STATE_IOERROR))
iclog->ic_state = XLOG_STATE_DIRTY;
xlog_state_clean_log(log);
wake_up_all(&iclog->ic_force_wait);
iclog = iclog->ic_next;
} while (first_iclog != iclog);
if (repeats > 5000) {
flushcnt += repeats;
repeats = 0;
xfs_warn(log->l_mp,
"%s: possible infinite loop (%d iterations)",
__func__, flushcnt);
}
} while (!ioerrors && loopdidcallbacks);
#ifdef DEBUG
if (funcdidcallbacks) {
first_iclog = iclog = log->l_iclog;
do {
ASSERT(iclog->ic_state != XLOG_STATE_DO_CALLBACK);
if (iclog->ic_state == XLOG_STATE_WANT_SYNC ||
iclog->ic_state == XLOG_STATE_SYNCING ||
iclog->ic_state == XLOG_STATE_DONE_SYNC ||
iclog->ic_state == XLOG_STATE_IOERROR )
break;
iclog = iclog->ic_next;
} while (first_iclog != iclog);
}
#endif
if (log->l_iclog->ic_state & (XLOG_STATE_ACTIVE|XLOG_STATE_IOERROR))
wake = 1;
spin_unlock(&log->l_icloglock);
if (wake)
wake_up_all(&log->l_flush_wait);
}
STATIC void
xlog_state_done_syncing(
xlog_in_core_t *iclog,
int aborted)
{
struct xlog *log = iclog->ic_log;
spin_lock(&log->l_icloglock);
ASSERT(iclog->ic_state == XLOG_STATE_SYNCING ||
iclog->ic_state == XLOG_STATE_IOERROR);
ASSERT(atomic_read(&iclog->ic_refcnt) == 0);
ASSERT(iclog->ic_bwritecnt == 1 || iclog->ic_bwritecnt == 2);
if (iclog->ic_state != XLOG_STATE_IOERROR) {
if (--iclog->ic_bwritecnt == 1) {
spin_unlock(&log->l_icloglock);
return;
}
iclog->ic_state = XLOG_STATE_DONE_SYNC;
}
wake_up_all(&iclog->ic_write_wait);
spin_unlock(&log->l_icloglock);
xlog_state_do_callback(log, aborted, iclog);
}
STATIC int
xlog_state_get_iclog_space(
struct xlog *log,
int len,
struct xlog_in_core **iclogp,
struct xlog_ticket *ticket,
int *continued_write,
int *logoffsetp)
{
int log_offset;
xlog_rec_header_t *head;
xlog_in_core_t *iclog;
int error;
restart:
spin_lock(&log->l_icloglock);
if (XLOG_FORCED_SHUTDOWN(log)) {
spin_unlock(&log->l_icloglock);
return XFS_ERROR(EIO);
}
iclog = log->l_iclog;
if (iclog->ic_state != XLOG_STATE_ACTIVE) {
XFS_STATS_INC(xs_log_noiclogs);
xlog_wait(&log->l_flush_wait, &log->l_icloglock);
goto restart;
}
head = &iclog->ic_header;
atomic_inc(&iclog->ic_refcnt);
log_offset = iclog->ic_offset;
if (log_offset == 0) {
ticket->t_curr_res -= log->l_iclog_hsize;
xlog_tic_add_region(ticket,
log->l_iclog_hsize,
XLOG_REG_TYPE_LRHEADER);
head->h_cycle = cpu_to_be32(log->l_curr_cycle);
head->h_lsn = cpu_to_be64(
xlog_assign_lsn(log->l_curr_cycle, log->l_curr_block));
ASSERT(log->l_curr_block >= 0);
}
if (iclog->ic_size - iclog->ic_offset < 2*sizeof(xlog_op_header_t)) {
xlog_state_switch_iclogs(log, iclog, iclog->ic_size);
if (!atomic_add_unless(&iclog->ic_refcnt, -1, 1)) {
spin_unlock(&log->l_icloglock);
error = xlog_state_release_iclog(log, iclog);
if (error)
return error;
} else {
spin_unlock(&log->l_icloglock);
}
goto restart;
}
if (len <= iclog->ic_size - iclog->ic_offset) {
*continued_write = 0;
iclog->ic_offset += len;
} else {
*continued_write = 1;
xlog_state_switch_iclogs(log, iclog, iclog->ic_size);
}
*iclogp = iclog;
ASSERT(iclog->ic_offset <= iclog->ic_size);
spin_unlock(&log->l_icloglock);
*logoffsetp = log_offset;
return 0;
}
STATIC void
xlog_regrant_reserve_log_space(
struct xlog *log,
struct xlog_ticket *ticket)
{
trace_xfs_log_regrant_reserve_enter(log, ticket);
if (ticket->t_cnt > 0)
ticket->t_cnt--;
xlog_grant_sub_space(log, &log->l_reserve_head.grant,
ticket->t_curr_res);
xlog_grant_sub_space(log, &log->l_write_head.grant,
ticket->t_curr_res);
ticket->t_curr_res = ticket->t_unit_res;
xlog_tic_reset_res(ticket);
trace_xfs_log_regrant_reserve_sub(log, ticket);
if (ticket->t_cnt > 0)
return;
xlog_grant_add_space(log, &log->l_reserve_head.grant,
ticket->t_unit_res);
trace_xfs_log_regrant_reserve_exit(log, ticket);
ticket->t_curr_res = ticket->t_unit_res;
xlog_tic_reset_res(ticket);
}
STATIC void
xlog_ungrant_log_space(
struct xlog *log,
struct xlog_ticket *ticket)
{
int bytes;
if (ticket->t_cnt > 0)
ticket->t_cnt--;
trace_xfs_log_ungrant_enter(log, ticket);
trace_xfs_log_ungrant_sub(log, ticket);
bytes = ticket->t_curr_res;
if (ticket->t_cnt > 0) {
ASSERT(ticket->t_flags & XLOG_TIC_PERM_RESERV);
bytes += ticket->t_unit_res*ticket->t_cnt;
}
xlog_grant_sub_space(log, &log->l_reserve_head.grant, bytes);
xlog_grant_sub_space(log, &log->l_write_head.grant, bytes);
trace_xfs_log_ungrant_exit(log, ticket);
xfs_log_space_wake(log->l_mp);
}
STATIC int
xlog_state_release_iclog(
struct xlog *log,
struct xlog_in_core *iclog)
{
int sync = 0;
if (iclog->ic_state & XLOG_STATE_IOERROR)
return XFS_ERROR(EIO);
ASSERT(atomic_read(&iclog->ic_refcnt) > 0);
if (!atomic_dec_and_lock(&iclog->ic_refcnt, &log->l_icloglock))
return 0;
if (iclog->ic_state & XLOG_STATE_IOERROR) {
spin_unlock(&log->l_icloglock);
return XFS_ERROR(EIO);
}
ASSERT(iclog->ic_state == XLOG_STATE_ACTIVE ||
iclog->ic_state == XLOG_STATE_WANT_SYNC);
if (iclog->ic_state == XLOG_STATE_WANT_SYNC) {
xfs_lsn_t tail_lsn = xlog_assign_tail_lsn(log->l_mp);
sync++;
iclog->ic_state = XLOG_STATE_SYNCING;
iclog->ic_header.h_tail_lsn = cpu_to_be64(tail_lsn);
xlog_verify_tail_lsn(log, iclog, tail_lsn);
}
spin_unlock(&log->l_icloglock);
if (sync)
return xlog_sync(log, iclog);
return 0;
}
STATIC void
xlog_state_switch_iclogs(
struct xlog *log,
struct xlog_in_core *iclog,
int eventual_size)
{
ASSERT(iclog->ic_state == XLOG_STATE_ACTIVE);
if (!eventual_size)
eventual_size = iclog->ic_offset;
iclog->ic_state = XLOG_STATE_WANT_SYNC;
iclog->ic_header.h_prev_block = cpu_to_be32(log->l_prev_block);
log->l_prev_block = log->l_curr_block;
log->l_prev_cycle = log->l_curr_cycle;
log->l_curr_block += BTOBB(eventual_size)+BTOBB(log->l_iclog_hsize);
if (xfs_sb_version_haslogv2(&log->l_mp->m_sb) &&
log->l_mp->m_sb.sb_logsunit > 1) {
__uint32_t sunit_bb = BTOBB(log->l_mp->m_sb.sb_logsunit);
log->l_curr_block = roundup(log->l_curr_block, sunit_bb);
}
if (log->l_curr_block >= log->l_logBBsize) {
log->l_curr_cycle++;
if (log->l_curr_cycle == XLOG_HEADER_MAGIC_NUM)
log->l_curr_cycle++;
log->l_curr_block -= log->l_logBBsize;
ASSERT(log->l_curr_block >= 0);
}
ASSERT(iclog == log->l_iclog);
log->l_iclog = iclog->ic_next;
}
int
_xfs_log_force(
struct xfs_mount *mp,
uint flags,
int *log_flushed)
{
struct xlog *log = mp->m_log;
struct xlog_in_core *iclog;
xfs_lsn_t lsn;
XFS_STATS_INC(xs_log_force);
xlog_cil_force(log);
spin_lock(&log->l_icloglock);
iclog = log->l_iclog;
if (iclog->ic_state & XLOG_STATE_IOERROR) {
spin_unlock(&log->l_icloglock);
return XFS_ERROR(EIO);
}
if (iclog->ic_state == XLOG_STATE_ACTIVE ||
iclog->ic_state == XLOG_STATE_DIRTY) {
if (iclog->ic_state == XLOG_STATE_DIRTY ||
(atomic_read(&iclog->ic_refcnt) == 0
&& iclog->ic_offset == 0)) {
iclog = iclog->ic_prev;
if (iclog->ic_state == XLOG_STATE_ACTIVE ||
iclog->ic_state == XLOG_STATE_DIRTY)
goto no_sleep;
else
goto maybe_sleep;
} else {
if (atomic_read(&iclog->ic_refcnt) == 0) {
atomic_inc(&iclog->ic_refcnt);
lsn = be64_to_cpu(iclog->ic_header.h_lsn);
xlog_state_switch_iclogs(log, iclog, 0);
spin_unlock(&log->l_icloglock);
if (xlog_state_release_iclog(log, iclog))
return XFS_ERROR(EIO);
if (log_flushed)
*log_flushed = 1;
spin_lock(&log->l_icloglock);
if (be64_to_cpu(iclog->ic_header.h_lsn) == lsn &&
iclog->ic_state != XLOG_STATE_DIRTY)
goto maybe_sleep;
else
goto no_sleep;
} else {
xlog_state_switch_iclogs(log, iclog, 0);
goto maybe_sleep;
}
}
}
maybe_sleep:
if (flags & XFS_LOG_SYNC) {
if (iclog->ic_state & XLOG_STATE_IOERROR) {
spin_unlock(&log->l_icloglock);
return XFS_ERROR(EIO);
}
XFS_STATS_INC(xs_log_force_sleep);
xlog_wait(&iclog->ic_force_wait, &log->l_icloglock);
if (iclog->ic_state & XLOG_STATE_IOERROR)
return XFS_ERROR(EIO);
if (log_flushed)
*log_flushed = 1;
} else {
no_sleep:
spin_unlock(&log->l_icloglock);
}
return 0;
}
void
xfs_log_force(
xfs_mount_t *mp,
uint flags)
{
int error;
trace_xfs_log_force(mp, 0);
error = _xfs_log_force(mp, flags, NULL);
if (error)
xfs_warn(mp, "%s: error %d returned.", __func__, error);
}
int
_xfs_log_force_lsn(
struct xfs_mount *mp,
xfs_lsn_t lsn,
uint flags,
int *log_flushed)
{
struct xlog *log = mp->m_log;
struct xlog_in_core *iclog;
int already_slept = 0;
ASSERT(lsn != 0);
XFS_STATS_INC(xs_log_force);
lsn = xlog_cil_force_lsn(log, lsn);
if (lsn == NULLCOMMITLSN)
return 0;
try_again:
spin_lock(&log->l_icloglock);
iclog = log->l_iclog;
if (iclog->ic_state & XLOG_STATE_IOERROR) {
spin_unlock(&log->l_icloglock);
return XFS_ERROR(EIO);
}
do {
if (be64_to_cpu(iclog->ic_header.h_lsn) != lsn) {
iclog = iclog->ic_next;
continue;
}
if (iclog->ic_state == XLOG_STATE_DIRTY) {
spin_unlock(&log->l_icloglock);
return 0;
}
if (iclog->ic_state == XLOG_STATE_ACTIVE) {
if (!already_slept &&
(iclog->ic_prev->ic_state &
(XLOG_STATE_WANT_SYNC | XLOG_STATE_SYNCING))) {
ASSERT(!(iclog->ic_state & XLOG_STATE_IOERROR));
XFS_STATS_INC(xs_log_force_sleep);
xlog_wait(&iclog->ic_prev->ic_write_wait,
&log->l_icloglock);
if (log_flushed)
*log_flushed = 1;
already_slept = 1;
goto try_again;
}
atomic_inc(&iclog->ic_refcnt);
xlog_state_switch_iclogs(log, iclog, 0);
spin_unlock(&log->l_icloglock);
if (xlog_state_release_iclog(log, iclog))
return XFS_ERROR(EIO);
if (log_flushed)
*log_flushed = 1;
spin_lock(&log->l_icloglock);
}
if ((flags & XFS_LOG_SYNC) &&
!(iclog->ic_state &
(XLOG_STATE_ACTIVE | XLOG_STATE_DIRTY))) {
if (iclog->ic_state & XLOG_STATE_IOERROR) {
spin_unlock(&log->l_icloglock);
return XFS_ERROR(EIO);
}
XFS_STATS_INC(xs_log_force_sleep);
xlog_wait(&iclog->ic_force_wait, &log->l_icloglock);
if (iclog->ic_state & XLOG_STATE_IOERROR)
return XFS_ERROR(EIO);
if (log_flushed)
*log_flushed = 1;
} else {
spin_unlock(&log->l_icloglock);
}
return 0;
} while (iclog != log->l_iclog);
spin_unlock(&log->l_icloglock);
return 0;
}
void
xfs_log_force_lsn(
xfs_mount_t *mp,
xfs_lsn_t lsn,
uint flags)
{
int error;
trace_xfs_log_force(mp, lsn);
error = _xfs_log_force_lsn(mp, lsn, flags, NULL);
if (error)
xfs_warn(mp, "%s: error %d returned.", __func__, error);
}
STATIC void
xlog_state_want_sync(
struct xlog *log,
struct xlog_in_core *iclog)
{
assert_spin_locked(&log->l_icloglock);
if (iclog->ic_state == XLOG_STATE_ACTIVE) {
xlog_state_switch_iclogs(log, iclog, 0);
} else {
ASSERT(iclog->ic_state &
(XLOG_STATE_WANT_SYNC|XLOG_STATE_IOERROR));
}
}
void
xfs_log_ticket_put(
xlog_ticket_t *ticket)
{
ASSERT(atomic_read(&ticket->t_ref) > 0);
if (atomic_dec_and_test(&ticket->t_ref))
kmem_zone_free(xfs_log_ticket_zone, ticket);
}
xlog_ticket_t *
xfs_log_ticket_get(
xlog_ticket_t *ticket)
{
ASSERT(atomic_read(&ticket->t_ref) > 0);
atomic_inc(&ticket->t_ref);
return ticket;
}
int
xfs_log_calc_unit_res(
struct xfs_mount *mp,
int unit_bytes)
{
struct xlog *log = mp->m_log;
int iclog_space;
uint num_headers;
unit_bytes += sizeof(xlog_op_header_t);
unit_bytes += sizeof(xfs_trans_header_t);
unit_bytes += sizeof(xlog_op_header_t);
iclog_space = log->l_iclog_size - log->l_iclog_hsize;
num_headers = howmany(unit_bytes, iclog_space);
unit_bytes += sizeof(xlog_op_header_t) * num_headers;
while (!num_headers ||
howmany(unit_bytes, iclog_space) > num_headers) {
unit_bytes += sizeof(xlog_op_header_t);
num_headers++;
}
unit_bytes += log->l_iclog_hsize * num_headers;
unit_bytes += log->l_iclog_hsize;
if (xfs_sb_version_haslogv2(&mp->m_sb) && mp->m_sb.sb_logsunit > 1) {
unit_bytes += 2 * mp->m_sb.sb_logsunit;
} else {
unit_bytes += 2 * BBSIZE;
}
return unit_bytes;
}
struct xlog_ticket *
xlog_ticket_alloc(
struct xlog *log,
int unit_bytes,
int cnt,
char client,
bool permanent,
xfs_km_flags_t alloc_flags)
{
struct xlog_ticket *tic;
int unit_res;
tic = kmem_zone_zalloc(xfs_log_ticket_zone, alloc_flags);
if (!tic)
return NULL;
unit_res = xfs_log_calc_unit_res(log->l_mp, unit_bytes);
atomic_set(&tic->t_ref, 1);
tic->t_task = current;
INIT_LIST_HEAD(&tic->t_queue);
tic->t_unit_res = unit_res;
tic->t_curr_res = unit_res;
tic->t_cnt = cnt;
tic->t_ocnt = cnt;
tic->t_tid = prandom_u32();
tic->t_clientid = client;
tic->t_flags = XLOG_TIC_INITED;
tic->t_trans_type = 0;
if (permanent)
tic->t_flags |= XLOG_TIC_PERM_RESERV;
xlog_tic_reset_res(tic);
return tic;
}
void
xlog_verify_dest_ptr(
struct xlog *log,
char *ptr)
{
int i;
int good_ptr = 0;
for (i = 0; i < log->l_iclog_bufs; i++) {
if (ptr >= log->l_iclog_bak[i] &&
ptr <= log->l_iclog_bak[i] + log->l_iclog_size)
good_ptr++;
}
if (!good_ptr)
xfs_emerg(log->l_mp, "%s: invalid ptr", __func__);
}
STATIC void
xlog_verify_grant_tail(
struct xlog *log)
{
int tail_cycle, tail_blocks;
int cycle, space;
xlog_crack_grant_head(&log->l_write_head.grant, &cycle, &space);
xlog_crack_atomic_lsn(&log->l_tail_lsn, &tail_cycle, &tail_blocks);
if (tail_cycle != cycle) {
if (cycle - 1 != tail_cycle &&
!(log->l_flags & XLOG_TAIL_WARN)) {
xfs_alert_tag(log->l_mp, XFS_PTAG_LOGRES,
"%s: cycle - 1 != tail_cycle", __func__);
log->l_flags |= XLOG_TAIL_WARN;
}
if (space > BBTOB(tail_blocks) &&
!(log->l_flags & XLOG_TAIL_WARN)) {
xfs_alert_tag(log->l_mp, XFS_PTAG_LOGRES,
"%s: space > BBTOB(tail_blocks)", __func__);
log->l_flags |= XLOG_TAIL_WARN;
}
}
}
STATIC void
xlog_verify_tail_lsn(
struct xlog *log,
struct xlog_in_core *iclog,
xfs_lsn_t tail_lsn)
{
int blocks;
if (CYCLE_LSN(tail_lsn) == log->l_prev_cycle) {
blocks =
log->l_logBBsize - (log->l_prev_block - BLOCK_LSN(tail_lsn));
if (blocks < BTOBB(iclog->ic_offset)+BTOBB(log->l_iclog_hsize))
xfs_emerg(log->l_mp, "%s: ran out of log space", __func__);
} else {
ASSERT(CYCLE_LSN(tail_lsn)+1 == log->l_prev_cycle);
if (BLOCK_LSN(tail_lsn) == log->l_prev_block)
xfs_emerg(log->l_mp, "%s: tail wrapped", __func__);
blocks = BLOCK_LSN(tail_lsn) - log->l_prev_block;
if (blocks < BTOBB(iclog->ic_offset) + 1)
xfs_emerg(log->l_mp, "%s: ran out of log space", __func__);
}
}
STATIC void
xlog_verify_iclog(
struct xlog *log,
struct xlog_in_core *iclog,
int count,
bool syncing)
{
xlog_op_header_t *ophead;
xlog_in_core_t *icptr;
xlog_in_core_2_t *xhdr;
xfs_caddr_t ptr;
xfs_caddr_t base_ptr;
__psint_t field_offset;
__uint8_t clientid;
int len, i, j, k, op_len;
int idx;
spin_lock(&log->l_icloglock);
icptr = log->l_iclog;
for (i = 0; i < log->l_iclog_bufs; i++, icptr = icptr->ic_next)
ASSERT(icptr);
if (icptr != log->l_iclog)
xfs_emerg(log->l_mp, "%s: corrupt iclog ring", __func__);
spin_unlock(&log->l_icloglock);
if (iclog->ic_header.h_magicno != cpu_to_be32(XLOG_HEADER_MAGIC_NUM))
xfs_emerg(log->l_mp, "%s: invalid magic num", __func__);
ptr = (xfs_caddr_t) &iclog->ic_header;
for (ptr += BBSIZE; ptr < ((xfs_caddr_t)&iclog->ic_header) + count;
ptr += BBSIZE) {
if (*(__be32 *)ptr == cpu_to_be32(XLOG_HEADER_MAGIC_NUM))
xfs_emerg(log->l_mp, "%s: unexpected magic num",
__func__);
}
len = be32_to_cpu(iclog->ic_header.h_num_logops);
ptr = iclog->ic_datap;
base_ptr = ptr;
ophead = (xlog_op_header_t *)ptr;
xhdr = iclog->ic_data;
for (i = 0; i < len; i++) {
ophead = (xlog_op_header_t *)ptr;
field_offset = (__psint_t)
((xfs_caddr_t)&(ophead->oh_clientid) - base_ptr);
if (!syncing || (field_offset & 0x1ff)) {
clientid = ophead->oh_clientid;
} else {
idx = BTOBBT((xfs_caddr_t)&(ophead->oh_clientid) - iclog->ic_datap);
if (idx >= (XLOG_HEADER_CYCLE_SIZE / BBSIZE)) {
j = idx / (XLOG_HEADER_CYCLE_SIZE / BBSIZE);
k = idx % (XLOG_HEADER_CYCLE_SIZE / BBSIZE);
clientid = xlog_get_client_id(
xhdr[j].hic_xheader.xh_cycle_data[k]);
} else {
clientid = xlog_get_client_id(
iclog->ic_header.h_cycle_data[idx]);
}
}
if (clientid != XFS_TRANSACTION && clientid != XFS_LOG)
xfs_warn(log->l_mp,
"%s: invalid clientid %d op 0x%p offset 0x%lx",
__func__, clientid, ophead,
(unsigned long)field_offset);
field_offset = (__psint_t)
((xfs_caddr_t)&(ophead->oh_len) - base_ptr);
if (!syncing || (field_offset & 0x1ff)) {
op_len = be32_to_cpu(ophead->oh_len);
} else {
idx = BTOBBT((__psint_t)&ophead->oh_len -
(__psint_t)iclog->ic_datap);
if (idx >= (XLOG_HEADER_CYCLE_SIZE / BBSIZE)) {
j = idx / (XLOG_HEADER_CYCLE_SIZE / BBSIZE);
k = idx % (XLOG_HEADER_CYCLE_SIZE / BBSIZE);
op_len = be32_to_cpu(xhdr[j].hic_xheader.xh_cycle_data[k]);
} else {
op_len = be32_to_cpu(iclog->ic_header.h_cycle_data[idx]);
}
}
ptr += sizeof(xlog_op_header_t) + op_len;
}
}
STATIC int
xlog_state_ioerror(
struct xlog *log)
{
xlog_in_core_t *iclog, *ic;
iclog = log->l_iclog;
if (! (iclog->ic_state & XLOG_STATE_IOERROR)) {
ic = iclog;
do {
ic->ic_state = XLOG_STATE_IOERROR;
ic = ic->ic_next;
} while (ic != iclog);
return 0;
}
return 1;
}
int
xfs_log_force_umount(
struct xfs_mount *mp,
int logerror)
{
struct xlog *log;
int retval;
log = mp->m_log;
if (!log ||
log->l_flags & XLOG_ACTIVE_RECOVERY) {
mp->m_flags |= XFS_MOUNT_FS_SHUTDOWN;
if (mp->m_sb_bp)
XFS_BUF_DONE(mp->m_sb_bp);
return 0;
}
if (logerror && log->l_iclog->ic_state & XLOG_STATE_IOERROR) {
ASSERT(XLOG_FORCED_SHUTDOWN(log));
return 1;
}
retval = 0;
if (!logerror)
xlog_cil_force(log);
spin_lock(&log->l_icloglock);
mp->m_flags |= XFS_MOUNT_FS_SHUTDOWN;
if (mp->m_sb_bp)
XFS_BUF_DONE(mp->m_sb_bp);
log->l_flags |= XLOG_IO_ERROR;
if (logerror)
retval = xlog_state_ioerror(log);
spin_unlock(&log->l_icloglock);
xlog_grant_head_wake_all(&log->l_reserve_head);
xlog_grant_head_wake_all(&log->l_write_head);
if (!(log->l_iclog->ic_state & XLOG_STATE_IOERROR)) {
ASSERT(!logerror);
_xfs_log_force(mp, XFS_LOG_SYNC, NULL);
spin_lock(&log->l_icloglock);
retval = xlog_state_ioerror(log);
spin_unlock(&log->l_icloglock);
}
wake_up_all(&log->l_cilp->xc_commit_wait);
xlog_state_do_callback(log, XFS_LI_ABORTED, NULL);
#ifdef XFSERRORDEBUG
{
xlog_in_core_t *iclog;
spin_lock(&log->l_icloglock);
iclog = log->l_iclog;
do {
ASSERT(iclog->ic_callback == 0);
iclog = iclog->ic_next;
} while (iclog != log->l_iclog);
spin_unlock(&log->l_icloglock);
}
#endif
return retval;
}
STATIC int
xlog_iclogs_empty(
struct xlog *log)
{
xlog_in_core_t *iclog;
iclog = log->l_iclog;
do {
if (iclog->ic_header.h_num_logops)
return 0;
iclog = iclog->ic_next;
} while (iclog != log->l_iclog);
return 1;
}
