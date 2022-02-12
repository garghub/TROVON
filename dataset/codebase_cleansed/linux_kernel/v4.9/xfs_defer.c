STATIC void
xfs_defer_intake_work(
struct xfs_trans *tp,
struct xfs_defer_ops *dop)
{
struct list_head *li;
struct xfs_defer_pending *dfp;
list_for_each_entry(dfp, &dop->dop_intake, dfp_list) {
dfp->dfp_intent = dfp->dfp_type->create_intent(tp,
dfp->dfp_count);
trace_xfs_defer_intake_work(tp->t_mountp, dfp);
list_sort(tp->t_mountp, &dfp->dfp_work,
dfp->dfp_type->diff_items);
list_for_each(li, &dfp->dfp_work)
dfp->dfp_type->log_item(tp, dfp->dfp_intent, li);
}
list_splice_tail_init(&dop->dop_intake, &dop->dop_pending);
}
STATIC void
xfs_defer_trans_abort(
struct xfs_trans *tp,
struct xfs_defer_ops *dop,
int error)
{
struct xfs_defer_pending *dfp;
trace_xfs_defer_trans_abort(tp->t_mountp, dop);
list_for_each_entry(dfp, &dop->dop_pending, dfp_list) {
trace_xfs_defer_pending_abort(tp->t_mountp, dfp);
if (dfp->dfp_intent && !dfp->dfp_done) {
dfp->dfp_type->abort_intent(dfp->dfp_intent);
dfp->dfp_intent = NULL;
}
}
xfs_force_shutdown(tp->t_mountp, (error == -EFSCORRUPTED) ?
SHUTDOWN_CORRUPT_INCORE : SHUTDOWN_META_IO_ERROR);
}
STATIC int
xfs_defer_trans_roll(
struct xfs_trans **tp,
struct xfs_defer_ops *dop,
struct xfs_inode *ip)
{
int i;
int error;
for (i = 0; i < XFS_DEFER_OPS_NR_INODES && dop->dop_inodes[i]; i++) {
if (dop->dop_inodes[i] == ip)
continue;
xfs_trans_log_inode(*tp, dop->dop_inodes[i], XFS_ILOG_CORE);
}
trace_xfs_defer_trans_roll((*tp)->t_mountp, dop);
error = xfs_trans_roll(tp, ip);
if (error) {
trace_xfs_defer_trans_roll_error((*tp)->t_mountp, dop, error);
xfs_defer_trans_abort(*tp, dop, error);
return error;
}
dop->dop_committed = true;
for (i = 0; i < XFS_DEFER_OPS_NR_INODES && dop->dop_inodes[i]; i++) {
if (dop->dop_inodes[i] == ip)
continue;
xfs_trans_ijoin(*tp, dop->dop_inodes[i], 0);
}
return error;
}
bool
xfs_defer_has_unfinished_work(
struct xfs_defer_ops *dop)
{
return !list_empty(&dop->dop_pending) || !list_empty(&dop->dop_intake);
}
int
xfs_defer_join(
struct xfs_defer_ops *dop,
struct xfs_inode *ip)
{
int i;
for (i = 0; i < XFS_DEFER_OPS_NR_INODES; i++) {
if (dop->dop_inodes[i] == ip)
return 0;
else if (dop->dop_inodes[i] == NULL) {
dop->dop_inodes[i] = ip;
return 0;
}
}
return -EFSCORRUPTED;
}
int
xfs_defer_finish(
struct xfs_trans **tp,
struct xfs_defer_ops *dop,
struct xfs_inode *ip)
{
struct xfs_defer_pending *dfp;
struct list_head *li;
struct list_head *n;
void *state;
int error = 0;
void (*cleanup_fn)(struct xfs_trans *, void *, int);
ASSERT((*tp)->t_flags & XFS_TRANS_PERM_LOG_RES);
trace_xfs_defer_finish((*tp)->t_mountp, dop);
while (xfs_defer_has_unfinished_work(dop)) {
xfs_defer_intake_work(*tp, dop);
error = xfs_defer_trans_roll(tp, dop, ip);
if (error)
goto out;
dfp = list_first_entry(&dop->dop_pending,
struct xfs_defer_pending, dfp_list);
trace_xfs_defer_pending_finish((*tp)->t_mountp, dfp);
dfp->dfp_done = dfp->dfp_type->create_done(*tp, dfp->dfp_intent,
dfp->dfp_count);
cleanup_fn = dfp->dfp_type->finish_cleanup;
state = NULL;
list_for_each_safe(li, n, &dfp->dfp_work) {
list_del(li);
dfp->dfp_count--;
error = dfp->dfp_type->finish_item(*tp, dop, li,
dfp->dfp_done, &state);
if (error == -EAGAIN) {
list_add(li, &dfp->dfp_work);
dfp->dfp_count++;
break;
} else if (error) {
if (cleanup_fn)
cleanup_fn(*tp, state, error);
xfs_defer_trans_abort(*tp, dop, error);
goto out;
}
}
if (error == -EAGAIN) {
dfp->dfp_intent = dfp->dfp_type->create_intent(*tp,
dfp->dfp_count);
dfp->dfp_done = NULL;
list_for_each(li, &dfp->dfp_work)
dfp->dfp_type->log_item(*tp, dfp->dfp_intent,
li);
} else {
list_del(&dfp->dfp_list);
kmem_free(dfp);
}
if (cleanup_fn)
cleanup_fn(*tp, state, error);
}
out:
if (error)
trace_xfs_defer_finish_error((*tp)->t_mountp, dop, error);
else
trace_xfs_defer_finish_done((*tp)->t_mountp, dop);
return error;
}
void
xfs_defer_cancel(
struct xfs_defer_ops *dop)
{
struct xfs_defer_pending *dfp;
struct xfs_defer_pending *pli;
struct list_head *pwi;
struct list_head *n;
trace_xfs_defer_cancel(NULL, dop);
list_for_each_entry_safe(dfp, pli, &dop->dop_intake, dfp_list) {
trace_xfs_defer_intake_cancel(NULL, dfp);
list_del(&dfp->dfp_list);
list_for_each_safe(pwi, n, &dfp->dfp_work) {
list_del(pwi);
dfp->dfp_count--;
dfp->dfp_type->cancel_item(pwi);
}
ASSERT(dfp->dfp_count == 0);
kmem_free(dfp);
}
list_for_each_entry_safe(dfp, pli, &dop->dop_pending, dfp_list) {
trace_xfs_defer_pending_cancel(NULL, dfp);
list_del(&dfp->dfp_list);
list_for_each_safe(pwi, n, &dfp->dfp_work) {
list_del(pwi);
dfp->dfp_count--;
dfp->dfp_type->cancel_item(pwi);
}
ASSERT(dfp->dfp_count == 0);
kmem_free(dfp);
}
}
void
xfs_defer_add(
struct xfs_defer_ops *dop,
enum xfs_defer_ops_type type,
struct list_head *li)
{
struct xfs_defer_pending *dfp = NULL;
if (!list_empty(&dop->dop_intake)) {
dfp = list_last_entry(&dop->dop_intake,
struct xfs_defer_pending, dfp_list);
if (dfp->dfp_type->type != type ||
(dfp->dfp_type->max_items &&
dfp->dfp_count >= dfp->dfp_type->max_items))
dfp = NULL;
}
if (!dfp) {
dfp = kmem_alloc(sizeof(struct xfs_defer_pending),
KM_SLEEP | KM_NOFS);
dfp->dfp_type = defer_op_types[type];
dfp->dfp_intent = NULL;
dfp->dfp_done = NULL;
dfp->dfp_count = 0;
INIT_LIST_HEAD(&dfp->dfp_work);
list_add_tail(&dfp->dfp_list, &dop->dop_intake);
}
list_add_tail(li, &dfp->dfp_work);
dfp->dfp_count++;
}
void
xfs_defer_init_op_type(
const struct xfs_defer_op_type *type)
{
defer_op_types[type->type] = type;
}
void
xfs_defer_init(
struct xfs_defer_ops *dop,
xfs_fsblock_t *fbp)
{
dop->dop_committed = false;
dop->dop_low = false;
memset(&dop->dop_inodes, 0, sizeof(dop->dop_inodes));
*fbp = NULLFSBLOCK;
INIT_LIST_HEAD(&dop->dop_intake);
INIT_LIST_HEAD(&dop->dop_pending);
trace_xfs_defer_init(NULL, dop);
}
