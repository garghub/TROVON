static struct xlog_ticket *
xlog_cil_ticket_alloc(
struct xlog *log)
{
struct xlog_ticket *tic;
tic = xlog_ticket_alloc(log, 0, 1, XFS_TRANSACTION, 0,
KM_SLEEP|KM_NOFS);
tic->t_trans_type = XFS_TRANS_CHECKPOINT;
tic->t_curr_res = 0;
return tic;
}
void
xlog_cil_init_post_recovery(
struct xlog *log)
{
log->l_cilp->xc_ctx->ticket = xlog_cil_ticket_alloc(log);
log->l_cilp->xc_ctx->sequence = 1;
log->l_cilp->xc_ctx->commit_lsn = xlog_assign_lsn(log->l_curr_cycle,
log->l_curr_block);
}
STATIC void
xfs_cil_prepare_item(
struct xlog *log,
struct xfs_log_vec *lv,
struct xfs_log_vec *old_lv,
int *diff_len,
int *diff_iovecs)
{
if (lv->lv_buf_len != XFS_LOG_VEC_ORDERED) {
*diff_len += lv->lv_bytes;
*diff_iovecs += lv->lv_niovecs;
}
if (!old_lv)
lv->lv_item->li_ops->iop_pin(lv->lv_item);
else if (old_lv != lv) {
ASSERT(lv->lv_buf_len != XFS_LOG_VEC_ORDERED);
*diff_len -= old_lv->lv_bytes;
*diff_iovecs -= old_lv->lv_niovecs;
kmem_free(old_lv);
}
lv->lv_item->li_lv = lv;
if (!lv->lv_item->li_seq)
lv->lv_item->li_seq = log->l_cilp->xc_ctx->sequence;
}
static void
xlog_cil_insert_format_items(
struct xlog *log,
struct xfs_trans *tp,
int *diff_len,
int *diff_iovecs)
{
struct xfs_log_item_desc *lidp;
if (list_empty(&tp->t_items)) {
ASSERT(0);
return;
}
list_for_each_entry(lidp, &tp->t_items, lid_trans) {
struct xfs_log_item *lip = lidp->lid_item;
struct xfs_log_vec *lv;
struct xfs_log_vec *old_lv;
int niovecs = 0;
int nbytes = 0;
int buf_size;
bool ordered = false;
if (!(lidp->lid_flags & XFS_LID_DIRTY))
continue;
lip->li_ops->iop_size(lip, &niovecs, &nbytes);
if (!niovecs)
continue;
if (niovecs == XFS_LOG_VEC_ORDERED) {
ordered = true;
niovecs = 0;
nbytes = 0;
}
nbytes += niovecs * sizeof(uint64_t);
nbytes = round_up(nbytes, sizeof(uint64_t));
old_lv = lip->li_lv;
buf_size = nbytes +
round_up((sizeof(struct xfs_log_vec) +
niovecs * sizeof(struct xfs_log_iovec)),
sizeof(uint64_t));
if (lip->li_lv && buf_size <= lip->li_lv->lv_size) {
lv = lip->li_lv;
lv->lv_next = NULL;
if (ordered)
goto insert;
*diff_iovecs -= lv->lv_niovecs;
*diff_len -= lv->lv_bytes;
} else {
lv = kmem_zalloc(buf_size, KM_SLEEP|KM_NOFS);
lv->lv_item = lip;
lv->lv_size = buf_size;
if (ordered) {
ASSERT(lip->li_lv == NULL);
lv->lv_buf_len = XFS_LOG_VEC_ORDERED;
goto insert;
}
lv->lv_iovecp = (struct xfs_log_iovec *)&lv[1];
}
lv->lv_niovecs = niovecs;
lv->lv_buf_len = 0;
lv->lv_bytes = 0;
lv->lv_buf = (char *)lv + buf_size - nbytes;
ASSERT(IS_ALIGNED((unsigned long)lv->lv_buf, sizeof(uint64_t)));
lip->li_ops->iop_format(lip, lv);
insert:
ASSERT(lv->lv_buf_len <= nbytes);
xfs_cil_prepare_item(log, lv, old_lv, diff_len, diff_iovecs);
}
}
static void
xlog_cil_insert_items(
struct xlog *log,
struct xfs_trans *tp)
{
struct xfs_cil *cil = log->l_cilp;
struct xfs_cil_ctx *ctx = cil->xc_ctx;
struct xfs_log_item_desc *lidp;
int len = 0;
int diff_iovecs = 0;
int iclog_space;
ASSERT(tp);
xlog_cil_insert_format_items(log, tp, &len, &diff_iovecs);
spin_lock(&cil->xc_cil_lock);
list_for_each_entry(lidp, &tp->t_items, lid_trans) {
struct xfs_log_item *lip = lidp->lid_item;
if (!(lidp->lid_flags & XFS_LID_DIRTY))
continue;
list_move_tail(&lip->li_cil, &cil->xc_cil);
}
len += diff_iovecs * sizeof(xlog_op_header_t);
ctx->nvecs += diff_iovecs;
if (!list_empty(&tp->t_busy))
list_splice_init(&tp->t_busy, &ctx->busy_extents);
if (ctx->ticket->t_curr_res == 0) {
ctx->ticket->t_curr_res = ctx->ticket->t_unit_res;
tp->t_ticket->t_curr_res -= ctx->ticket->t_unit_res;
}
iclog_space = log->l_iclog_size - log->l_iclog_hsize;
if (len > 0 && (ctx->space_used / iclog_space !=
(ctx->space_used + len) / iclog_space)) {
int hdrs;
hdrs = (len + iclog_space - 1) / iclog_space;
hdrs *= log->l_iclog_hsize + sizeof(struct xlog_op_header);
ctx->ticket->t_unit_res += hdrs;
ctx->ticket->t_curr_res += hdrs;
tp->t_ticket->t_curr_res -= hdrs;
ASSERT(tp->t_ticket->t_curr_res >= len);
}
tp->t_ticket->t_curr_res -= len;
ctx->space_used += len;
spin_unlock(&cil->xc_cil_lock);
}
static void
xlog_cil_free_logvec(
struct xfs_log_vec *log_vector)
{
struct xfs_log_vec *lv;
for (lv = log_vector; lv; ) {
struct xfs_log_vec *next = lv->lv_next;
kmem_free(lv);
lv = next;
}
}
static void
xlog_cil_committed(
void *args,
int abort)
{
struct xfs_cil_ctx *ctx = args;
struct xfs_mount *mp = ctx->cil->xc_log->l_mp;
xfs_trans_committed_bulk(ctx->cil->xc_log->l_ailp, ctx->lv_chain,
ctx->start_lsn, abort);
xfs_extent_busy_sort(&ctx->busy_extents);
xfs_extent_busy_clear(mp, &ctx->busy_extents,
(mp->m_flags & XFS_MOUNT_DISCARD) && !abort);
spin_lock(&ctx->cil->xc_push_lock);
if (abort)
wake_up_all(&ctx->cil->xc_commit_wait);
list_del(&ctx->committing);
spin_unlock(&ctx->cil->xc_push_lock);
xlog_cil_free_logvec(ctx->lv_chain);
if (!list_empty(&ctx->busy_extents)) {
ASSERT(mp->m_flags & XFS_MOUNT_DISCARD);
xfs_discard_extents(mp, &ctx->busy_extents);
xfs_extent_busy_clear(mp, &ctx->busy_extents, false);
}
kmem_free(ctx);
}
STATIC int
xlog_cil_push(
struct xlog *log)
{
struct xfs_cil *cil = log->l_cilp;
struct xfs_log_vec *lv;
struct xfs_cil_ctx *ctx;
struct xfs_cil_ctx *new_ctx;
struct xlog_in_core *commit_iclog;
struct xlog_ticket *tic;
int num_iovecs;
int error = 0;
struct xfs_trans_header thdr;
struct xfs_log_iovec lhdr;
struct xfs_log_vec lvhdr = { NULL };
xfs_lsn_t commit_lsn;
xfs_lsn_t push_seq;
if (!cil)
return 0;
new_ctx = kmem_zalloc(sizeof(*new_ctx), KM_SLEEP|KM_NOFS);
new_ctx->ticket = xlog_cil_ticket_alloc(log);
down_write(&cil->xc_ctx_lock);
ctx = cil->xc_ctx;
spin_lock(&cil->xc_push_lock);
push_seq = cil->xc_push_seq;
ASSERT(push_seq <= ctx->sequence);
if (list_empty(&cil->xc_cil)) {
cil->xc_push_seq = 0;
spin_unlock(&cil->xc_push_lock);
goto out_skip;
}
spin_unlock(&cil->xc_push_lock);
if (push_seq < cil->xc_ctx->sequence)
goto out_skip;
lv = NULL;
num_iovecs = 0;
while (!list_empty(&cil->xc_cil)) {
struct xfs_log_item *item;
item = list_first_entry(&cil->xc_cil,
struct xfs_log_item, li_cil);
list_del_init(&item->li_cil);
if (!ctx->lv_chain)
ctx->lv_chain = item->li_lv;
else
lv->lv_next = item->li_lv;
lv = item->li_lv;
item->li_lv = NULL;
num_iovecs += lv->lv_niovecs;
}
INIT_LIST_HEAD(&new_ctx->committing);
INIT_LIST_HEAD(&new_ctx->busy_extents);
new_ctx->sequence = ctx->sequence + 1;
new_ctx->cil = cil;
cil->xc_ctx = new_ctx;
spin_lock(&cil->xc_push_lock);
cil->xc_current_sequence = new_ctx->sequence;
list_add(&ctx->committing, &cil->xc_committing);
spin_unlock(&cil->xc_push_lock);
up_write(&cil->xc_ctx_lock);
tic = ctx->ticket;
thdr.th_magic = XFS_TRANS_HEADER_MAGIC;
thdr.th_type = XFS_TRANS_CHECKPOINT;
thdr.th_tid = tic->t_tid;
thdr.th_num_items = num_iovecs;
lhdr.i_addr = &thdr;
lhdr.i_len = sizeof(xfs_trans_header_t);
lhdr.i_type = XLOG_REG_TYPE_TRANSHDR;
tic->t_curr_res -= lhdr.i_len + sizeof(xlog_op_header_t);
lvhdr.lv_niovecs = 1;
lvhdr.lv_iovecp = &lhdr;
lvhdr.lv_next = ctx->lv_chain;
error = xlog_write(log, &lvhdr, tic, &ctx->start_lsn, NULL, 0);
if (error)
goto out_abort_free_ticket;
restart:
spin_lock(&cil->xc_push_lock);
list_for_each_entry(new_ctx, &cil->xc_committing, committing) {
if (XLOG_FORCED_SHUTDOWN(log)) {
spin_unlock(&cil->xc_push_lock);
goto out_abort_free_ticket;
}
if (new_ctx->sequence >= ctx->sequence)
continue;
if (!new_ctx->commit_lsn) {
xlog_wait(&cil->xc_commit_wait, &cil->xc_push_lock);
goto restart;
}
}
spin_unlock(&cil->xc_push_lock);
commit_lsn = xfs_log_done(log->l_mp, tic, &commit_iclog, 0);
if (commit_lsn == -1)
goto out_abort;
ctx->log_cb.cb_func = xlog_cil_committed;
ctx->log_cb.cb_arg = ctx;
error = xfs_log_notify(log->l_mp, commit_iclog, &ctx->log_cb);
if (error)
goto out_abort;
spin_lock(&cil->xc_push_lock);
ctx->commit_lsn = commit_lsn;
wake_up_all(&cil->xc_commit_wait);
spin_unlock(&cil->xc_push_lock);
return xfs_log_release_iclog(log->l_mp, commit_iclog);
out_skip:
up_write(&cil->xc_ctx_lock);
xfs_log_ticket_put(new_ctx->ticket);
kmem_free(new_ctx);
return 0;
out_abort_free_ticket:
xfs_log_ticket_put(tic);
out_abort:
xlog_cil_committed(ctx, XFS_LI_ABORTED);
return XFS_ERROR(EIO);
}
static void
xlog_cil_push_work(
struct work_struct *work)
{
struct xfs_cil *cil = container_of(work, struct xfs_cil,
xc_push_work);
xlog_cil_push(cil->xc_log);
}
static void
xlog_cil_push_background(
struct xlog *log)
{
struct xfs_cil *cil = log->l_cilp;
ASSERT(!list_empty(&cil->xc_cil));
if (cil->xc_ctx->space_used < XLOG_CIL_SPACE_LIMIT(log))
return;
spin_lock(&cil->xc_push_lock);
if (cil->xc_push_seq < cil->xc_current_sequence) {
cil->xc_push_seq = cil->xc_current_sequence;
queue_work(log->l_mp->m_cil_workqueue, &cil->xc_push_work);
}
spin_unlock(&cil->xc_push_lock);
}
static void
xlog_cil_push_now(
struct xlog *log,
xfs_lsn_t push_seq)
{
struct xfs_cil *cil = log->l_cilp;
if (!cil)
return;
ASSERT(push_seq && push_seq <= cil->xc_current_sequence);
flush_work(&cil->xc_push_work);
spin_lock(&cil->xc_push_lock);
if (list_empty(&cil->xc_cil) || push_seq <= cil->xc_push_seq) {
spin_unlock(&cil->xc_push_lock);
return;
}
cil->xc_push_seq = push_seq;
queue_work(log->l_mp->m_cil_workqueue, &cil->xc_push_work);
spin_unlock(&cil->xc_push_lock);
}
bool
xlog_cil_empty(
struct xlog *log)
{
struct xfs_cil *cil = log->l_cilp;
bool empty = false;
spin_lock(&cil->xc_push_lock);
if (list_empty(&cil->xc_cil))
empty = true;
spin_unlock(&cil->xc_push_lock);
return empty;
}
void
xfs_log_commit_cil(
struct xfs_mount *mp,
struct xfs_trans *tp,
xfs_lsn_t *commit_lsn,
int flags)
{
struct xlog *log = mp->m_log;
struct xfs_cil *cil = log->l_cilp;
int log_flags = 0;
if (flags & XFS_TRANS_RELEASE_LOG_RES)
log_flags = XFS_LOG_REL_PERM_RESERV;
down_read(&cil->xc_ctx_lock);
xlog_cil_insert_items(log, tp);
if (tp->t_ticket->t_curr_res < 0)
xlog_print_tic_res(mp, tp->t_ticket);
tp->t_commit_lsn = cil->xc_ctx->sequence;
if (commit_lsn)
*commit_lsn = tp->t_commit_lsn;
xfs_log_done(mp, tp->t_ticket, NULL, log_flags);
xfs_trans_unreserve_and_mod_sb(tp);
xfs_trans_free_items(tp, tp->t_commit_lsn, 0);
xlog_cil_push_background(log);
up_read(&cil->xc_ctx_lock);
}
xfs_lsn_t
xlog_cil_force_lsn(
struct xlog *log,
xfs_lsn_t sequence)
{
struct xfs_cil *cil = log->l_cilp;
struct xfs_cil_ctx *ctx;
xfs_lsn_t commit_lsn = NULLCOMMITLSN;
ASSERT(sequence <= cil->xc_current_sequence);
restart:
xlog_cil_push_now(log, sequence);
spin_lock(&cil->xc_push_lock);
list_for_each_entry(ctx, &cil->xc_committing, committing) {
if (XLOG_FORCED_SHUTDOWN(log))
goto out_shutdown;
if (ctx->sequence > sequence)
continue;
if (!ctx->commit_lsn) {
xlog_wait(&cil->xc_commit_wait, &cil->xc_push_lock);
goto restart;
}
if (ctx->sequence != sequence)
continue;
commit_lsn = ctx->commit_lsn;
}
if (sequence == cil->xc_current_sequence &&
!list_empty(&cil->xc_cil)) {
spin_unlock(&cil->xc_push_lock);
goto restart;
}
spin_unlock(&cil->xc_push_lock);
return commit_lsn;
out_shutdown:
spin_unlock(&cil->xc_push_lock);
return 0;
}
bool
xfs_log_item_in_current_chkpt(
struct xfs_log_item *lip)
{
struct xfs_cil_ctx *ctx;
if (list_empty(&lip->li_cil))
return false;
ctx = lip->li_mountp->m_log->l_cilp->xc_ctx;
if (XFS_LSN_CMP(lip->li_seq, ctx->sequence) != 0)
return false;
return true;
}
int
xlog_cil_init(
struct xlog *log)
{
struct xfs_cil *cil;
struct xfs_cil_ctx *ctx;
cil = kmem_zalloc(sizeof(*cil), KM_SLEEP|KM_MAYFAIL);
if (!cil)
return ENOMEM;
ctx = kmem_zalloc(sizeof(*ctx), KM_SLEEP|KM_MAYFAIL);
if (!ctx) {
kmem_free(cil);
return ENOMEM;
}
INIT_WORK(&cil->xc_push_work, xlog_cil_push_work);
INIT_LIST_HEAD(&cil->xc_cil);
INIT_LIST_HEAD(&cil->xc_committing);
spin_lock_init(&cil->xc_cil_lock);
spin_lock_init(&cil->xc_push_lock);
init_rwsem(&cil->xc_ctx_lock);
init_waitqueue_head(&cil->xc_commit_wait);
INIT_LIST_HEAD(&ctx->committing);
INIT_LIST_HEAD(&ctx->busy_extents);
ctx->sequence = 1;
ctx->cil = cil;
cil->xc_ctx = ctx;
cil->xc_current_sequence = ctx->sequence;
cil->xc_log = log;
log->l_cilp = cil;
return 0;
}
void
xlog_cil_destroy(
struct xlog *log)
{
if (log->l_cilp->xc_ctx) {
if (log->l_cilp->xc_ctx->ticket)
xfs_log_ticket_put(log->l_cilp->xc_ctx->ticket);
kmem_free(log->l_cilp->xc_ctx);
}
ASSERT(list_empty(&log->l_cilp->xc_cil));
kmem_free(log->l_cilp);
}
