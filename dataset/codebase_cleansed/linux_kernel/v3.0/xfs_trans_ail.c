STATIC void
xfs_ail_check(
struct xfs_ail *ailp,
xfs_log_item_t *lip)
{
xfs_log_item_t *prev_lip;
if (list_empty(&ailp->xa_ail))
return;
ASSERT((lip->li_flags & XFS_LI_IN_AIL) != 0);
prev_lip = list_entry(lip->li_ail.prev, xfs_log_item_t, li_ail);
if (&prev_lip->li_ail != &ailp->xa_ail)
ASSERT(XFS_LSN_CMP(prev_lip->li_lsn, lip->li_lsn) <= 0);
prev_lip = list_entry(lip->li_ail.next, xfs_log_item_t, li_ail);
if (&prev_lip->li_ail != &ailp->xa_ail)
ASSERT(XFS_LSN_CMP(prev_lip->li_lsn, lip->li_lsn) >= 0);
#ifdef XFS_TRANS_DEBUG
prev_lip = list_entry(&ailp->xa_ail, xfs_log_item_t, li_ail);
list_for_each_entry(lip, &ailp->xa_ail, li_ail) {
if (&prev_lip->li_ail != &ailp->xa_ail)
ASSERT(XFS_LSN_CMP(prev_lip->li_lsn, lip->li_lsn) <= 0);
ASSERT((lip->li_flags & XFS_LI_IN_AIL) != 0);
prev_lip = lip;
}
#endif
}
static xfs_log_item_t *
xfs_ail_min(
struct xfs_ail *ailp)
{
if (list_empty(&ailp->xa_ail))
return NULL;
return list_first_entry(&ailp->xa_ail, xfs_log_item_t, li_ail);
}
static xfs_log_item_t *
xfs_ail_max(
struct xfs_ail *ailp)
{
if (list_empty(&ailp->xa_ail))
return NULL;
return list_entry(ailp->xa_ail.prev, xfs_log_item_t, li_ail);
}
static xfs_log_item_t *
xfs_ail_next(
struct xfs_ail *ailp,
xfs_log_item_t *lip)
{
if (lip->li_ail.next == &ailp->xa_ail)
return NULL;
return list_first_entry(&lip->li_ail, xfs_log_item_t, li_ail);
}
xfs_lsn_t
xfs_ail_min_lsn(
struct xfs_ail *ailp)
{
xfs_lsn_t lsn = 0;
xfs_log_item_t *lip;
spin_lock(&ailp->xa_lock);
lip = xfs_ail_min(ailp);
if (lip)
lsn = lip->li_lsn;
spin_unlock(&ailp->xa_lock);
return lsn;
}
static xfs_lsn_t
xfs_ail_max_lsn(
struct xfs_ail *ailp)
{
xfs_lsn_t lsn = 0;
xfs_log_item_t *lip;
spin_lock(&ailp->xa_lock);
lip = xfs_ail_max(ailp);
if (lip)
lsn = lip->li_lsn;
spin_unlock(&ailp->xa_lock);
return lsn;
}
STATIC void
xfs_trans_ail_cursor_init(
struct xfs_ail *ailp,
struct xfs_ail_cursor *cur)
{
cur->item = NULL;
if (cur == &ailp->xa_cursors)
return;
cur->next = ailp->xa_cursors.next;
ailp->xa_cursors.next = cur;
}
STATIC void
xfs_trans_ail_cursor_set(
struct xfs_ail *ailp,
struct xfs_ail_cursor *cur,
struct xfs_log_item *lip)
{
if (lip)
cur->item = xfs_ail_next(ailp, lip);
}
struct xfs_log_item *
xfs_trans_ail_cursor_next(
struct xfs_ail *ailp,
struct xfs_ail_cursor *cur)
{
struct xfs_log_item *lip = cur->item;
if ((__psint_t)lip & 1)
lip = xfs_ail_min(ailp);
xfs_trans_ail_cursor_set(ailp, cur, lip);
return lip;
}
void
xfs_trans_ail_cursor_done(
struct xfs_ail *ailp,
struct xfs_ail_cursor *done)
{
struct xfs_ail_cursor *prev = NULL;
struct xfs_ail_cursor *cur;
done->item = NULL;
if (done == &ailp->xa_cursors)
return;
prev = &ailp->xa_cursors;
for (cur = prev->next; cur; prev = cur, cur = prev->next) {
if (cur == done) {
prev->next = cur->next;
break;
}
}
ASSERT(cur);
}
STATIC void
xfs_trans_ail_cursor_clear(
struct xfs_ail *ailp,
struct xfs_log_item *lip)
{
struct xfs_ail_cursor *cur;
for (cur = &ailp->xa_cursors; cur; cur = cur->next) {
if (cur->item == lip)
cur->item = (struct xfs_log_item *)
((__psint_t)cur->item | 1);
}
}
xfs_log_item_t *
xfs_trans_ail_cursor_first(
struct xfs_ail *ailp,
struct xfs_ail_cursor *cur,
xfs_lsn_t lsn)
{
xfs_log_item_t *lip;
xfs_trans_ail_cursor_init(ailp, cur);
lip = xfs_ail_min(ailp);
if (lsn == 0)
goto out;
list_for_each_entry(lip, &ailp->xa_ail, li_ail) {
if (XFS_LSN_CMP(lip->li_lsn, lsn) >= 0)
goto out;
}
lip = NULL;
out:
xfs_trans_ail_cursor_set(ailp, cur, lip);
return lip;
}
static void
xfs_ail_splice(
struct xfs_ail *ailp,
struct list_head *list,
xfs_lsn_t lsn)
{
xfs_log_item_t *next_lip;
if (list_empty(&ailp->xa_ail)) {
list_splice(list, &ailp->xa_ail);
return;
}
list_for_each_entry_reverse(next_lip, &ailp->xa_ail, li_ail) {
if (XFS_LSN_CMP(next_lip->li_lsn, lsn) <= 0)
break;
}
ASSERT(&next_lip->li_ail == &ailp->xa_ail ||
XFS_LSN_CMP(next_lip->li_lsn, lsn) <= 0);
list_splice_init(list, &next_lip->li_ail);
}
static void
xfs_ail_delete(
struct xfs_ail *ailp,
xfs_log_item_t *lip)
{
xfs_ail_check(ailp, lip);
list_del(&lip->li_ail);
xfs_trans_ail_cursor_clear(ailp, lip);
}
STATIC void
xfs_ail_worker(
struct work_struct *work)
{
struct xfs_ail *ailp = container_of(to_delayed_work(work),
struct xfs_ail, xa_work);
xfs_mount_t *mp = ailp->xa_mount;
struct xfs_ail_cursor *cur = &ailp->xa_cursors;
xfs_log_item_t *lip;
xfs_lsn_t lsn;
xfs_lsn_t target;
long tout = 10;
int flush_log = 0;
int stuck = 0;
int count = 0;
int push_xfsbufd = 0;
spin_lock(&ailp->xa_lock);
target = ailp->xa_target;
xfs_trans_ail_cursor_init(ailp, cur);
lip = xfs_trans_ail_cursor_first(ailp, cur, ailp->xa_last_pushed_lsn);
if (!lip || XFS_FORCED_SHUTDOWN(mp)) {
xfs_trans_ail_cursor_done(ailp, cur);
spin_unlock(&ailp->xa_lock);
goto out_done;
}
XFS_STATS_INC(xs_push_ail);
lsn = lip->li_lsn;
while ((XFS_LSN_CMP(lip->li_lsn, target) <= 0)) {
int lock_result;
lock_result = IOP_TRYLOCK(lip);
spin_unlock(&ailp->xa_lock);
switch (lock_result) {
case XFS_ITEM_SUCCESS:
XFS_STATS_INC(xs_push_ail_success);
IOP_PUSH(lip);
ailp->xa_last_pushed_lsn = lsn;
break;
case XFS_ITEM_PUSHBUF:
XFS_STATS_INC(xs_push_ail_pushbuf);
IOP_PUSHBUF(lip);
ailp->xa_last_pushed_lsn = lsn;
push_xfsbufd = 1;
break;
case XFS_ITEM_PINNED:
XFS_STATS_INC(xs_push_ail_pinned);
stuck++;
flush_log = 1;
break;
case XFS_ITEM_LOCKED:
XFS_STATS_INC(xs_push_ail_locked);
ailp->xa_last_pushed_lsn = lsn;
stuck++;
break;
default:
ASSERT(0);
break;
}
spin_lock(&ailp->xa_lock);
if (XFS_FORCED_SHUTDOWN(mp))
break;
ASSERT(mp->m_log);
count++;
if (stuck > 100)
break;
lip = xfs_trans_ail_cursor_next(ailp, cur);
if (lip == NULL)
break;
lsn = lip->li_lsn;
}
xfs_trans_ail_cursor_done(ailp, cur);
spin_unlock(&ailp->xa_lock);
if (flush_log) {
XFS_STATS_INC(xs_push_ail_flush);
xfs_log_force(mp, 0);
}
if (push_xfsbufd) {
wake_up_process(mp->m_ddev_targp->bt_task);
}
out_done:
if (!count) {
ailp->xa_last_pushed_lsn = 0;
clear_bit(XFS_AIL_PUSHING_BIT, &ailp->xa_flags);
smp_rmb();
if (XFS_LSN_CMP(ailp->xa_target, target) == 0 ||
test_and_set_bit(XFS_AIL_PUSHING_BIT, &ailp->xa_flags))
return;
tout = 50;
} else if (XFS_LSN_CMP(lsn, target) >= 0) {
tout = 50;
ailp->xa_last_pushed_lsn = 0;
} else if ((stuck * 100) / count > 90) {
tout = 20;
}
queue_delayed_work(xfs_syncd_wq, &ailp->xa_work,
msecs_to_jiffies(tout));
}
void
xfs_ail_push(
struct xfs_ail *ailp,
xfs_lsn_t threshold_lsn)
{
xfs_log_item_t *lip;
lip = xfs_ail_min(ailp);
if (!lip || XFS_FORCED_SHUTDOWN(ailp->xa_mount) ||
XFS_LSN_CMP(threshold_lsn, ailp->xa_target) <= 0)
return;
smp_wmb();
xfs_trans_ail_copy_lsn(ailp, &ailp->xa_target, &threshold_lsn);
if (!test_and_set_bit(XFS_AIL_PUSHING_BIT, &ailp->xa_flags))
queue_delayed_work(xfs_syncd_wq, &ailp->xa_work, 0);
}
void
xfs_ail_push_all(
struct xfs_ail *ailp)
{
xfs_lsn_t threshold_lsn = xfs_ail_max_lsn(ailp);
if (threshold_lsn)
xfs_ail_push(ailp, threshold_lsn);
}
void
xfs_trans_unlocked_item(
struct xfs_ail *ailp,
xfs_log_item_t *lip)
{
xfs_log_item_t *min_lip;
if (!(lip->li_flags & XFS_LI_IN_AIL) ||
XFS_FORCED_SHUTDOWN(ailp->xa_mount)) {
return;
}
min_lip = xfs_ail_min(ailp);
if (min_lip == lip)
xfs_log_move_tail(ailp->xa_mount, 1);
}
void
xfs_trans_ail_update_bulk(
struct xfs_ail *ailp,
struct xfs_log_item **log_items,
int nr_items,
xfs_lsn_t lsn) __releases(ailp->xa_lock)
{
xfs_log_item_t *mlip;
xfs_lsn_t tail_lsn;
int mlip_changed = 0;
int i;
LIST_HEAD(tmp);
mlip = xfs_ail_min(ailp);
for (i = 0; i < nr_items; i++) {
struct xfs_log_item *lip = log_items[i];
if (lip->li_flags & XFS_LI_IN_AIL) {
if (XFS_LSN_CMP(lsn, lip->li_lsn) <= 0)
continue;
xfs_ail_delete(ailp, lip);
if (mlip == lip)
mlip_changed = 1;
} else {
lip->li_flags |= XFS_LI_IN_AIL;
}
lip->li_lsn = lsn;
list_add(&lip->li_ail, &tmp);
}
xfs_ail_splice(ailp, &tmp, lsn);
if (!mlip_changed) {
spin_unlock(&ailp->xa_lock);
return;
}
mlip = xfs_ail_min(ailp);
tail_lsn = mlip->li_lsn;
spin_unlock(&ailp->xa_lock);
xfs_log_move_tail(ailp->xa_mount, tail_lsn);
}
void
xfs_trans_ail_delete_bulk(
struct xfs_ail *ailp,
struct xfs_log_item **log_items,
int nr_items) __releases(ailp->xa_lock)
{
xfs_log_item_t *mlip;
xfs_lsn_t tail_lsn;
int mlip_changed = 0;
int i;
mlip = xfs_ail_min(ailp);
for (i = 0; i < nr_items; i++) {
struct xfs_log_item *lip = log_items[i];
if (!(lip->li_flags & XFS_LI_IN_AIL)) {
struct xfs_mount *mp = ailp->xa_mount;
spin_unlock(&ailp->xa_lock);
if (!XFS_FORCED_SHUTDOWN(mp)) {
xfs_alert_tag(mp, XFS_PTAG_AILDELETE,
"%s: attempting to delete a log item that is not in the AIL",
__func__);
xfs_force_shutdown(mp, SHUTDOWN_CORRUPT_INCORE);
}
return;
}
xfs_ail_delete(ailp, lip);
lip->li_flags &= ~XFS_LI_IN_AIL;
lip->li_lsn = 0;
if (mlip == lip)
mlip_changed = 1;
}
if (!mlip_changed) {
spin_unlock(&ailp->xa_lock);
return;
}
mlip = xfs_ail_min(ailp);
tail_lsn = mlip ? mlip->li_lsn : 0;
spin_unlock(&ailp->xa_lock);
xfs_log_move_tail(ailp->xa_mount, tail_lsn);
}
int
xfs_trans_ail_init(
xfs_mount_t *mp)
{
struct xfs_ail *ailp;
ailp = kmem_zalloc(sizeof(struct xfs_ail), KM_MAYFAIL);
if (!ailp)
return ENOMEM;
ailp->xa_mount = mp;
INIT_LIST_HEAD(&ailp->xa_ail);
spin_lock_init(&ailp->xa_lock);
INIT_DELAYED_WORK(&ailp->xa_work, xfs_ail_worker);
mp->m_ail = ailp;
return 0;
}
void
xfs_trans_ail_destroy(
xfs_mount_t *mp)
{
struct xfs_ail *ailp = mp->m_ail;
cancel_delayed_work_sync(&ailp->xa_work);
kmem_free(ailp);
}
