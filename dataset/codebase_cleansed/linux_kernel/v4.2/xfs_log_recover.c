static inline int
xlog_buf_bbcount_valid(
struct xlog *log,
int bbcount)
{
return bbcount > 0 && bbcount <= log->l_logBBsize;
}
STATIC xfs_buf_t *
xlog_get_bp(
struct xlog *log,
int nbblks)
{
struct xfs_buf *bp;
if (!xlog_buf_bbcount_valid(log, nbblks)) {
xfs_warn(log->l_mp, "Invalid block length (0x%x) for buffer",
nbblks);
XFS_ERROR_REPORT(__func__, XFS_ERRLEVEL_HIGH, log->l_mp);
return NULL;
}
if (nbblks > 1 && log->l_sectBBsize > 1)
nbblks += log->l_sectBBsize;
nbblks = round_up(nbblks, log->l_sectBBsize);
bp = xfs_buf_get_uncached(log->l_mp->m_logdev_targp, nbblks, 0);
if (bp)
xfs_buf_unlock(bp);
return bp;
}
STATIC void
xlog_put_bp(
xfs_buf_t *bp)
{
xfs_buf_free(bp);
}
STATIC char *
xlog_align(
struct xlog *log,
xfs_daddr_t blk_no,
int nbblks,
struct xfs_buf *bp)
{
xfs_daddr_t offset = blk_no & ((xfs_daddr_t)log->l_sectBBsize - 1);
ASSERT(offset + nbblks <= bp->b_length);
return bp->b_addr + BBTOB(offset);
}
STATIC int
xlog_bread_noalign(
struct xlog *log,
xfs_daddr_t blk_no,
int nbblks,
struct xfs_buf *bp)
{
int error;
if (!xlog_buf_bbcount_valid(log, nbblks)) {
xfs_warn(log->l_mp, "Invalid block length (0x%x) for buffer",
nbblks);
XFS_ERROR_REPORT(__func__, XFS_ERRLEVEL_HIGH, log->l_mp);
return -EFSCORRUPTED;
}
blk_no = round_down(blk_no, log->l_sectBBsize);
nbblks = round_up(nbblks, log->l_sectBBsize);
ASSERT(nbblks > 0);
ASSERT(nbblks <= bp->b_length);
XFS_BUF_SET_ADDR(bp, log->l_logBBstart + blk_no);
XFS_BUF_READ(bp);
bp->b_io_length = nbblks;
bp->b_error = 0;
error = xfs_buf_submit_wait(bp);
if (error && !XFS_FORCED_SHUTDOWN(log->l_mp))
xfs_buf_ioerror_alert(bp, __func__);
return error;
}
STATIC int
xlog_bread(
struct xlog *log,
xfs_daddr_t blk_no,
int nbblks,
struct xfs_buf *bp,
char **offset)
{
int error;
error = xlog_bread_noalign(log, blk_no, nbblks, bp);
if (error)
return error;
*offset = xlog_align(log, blk_no, nbblks, bp);
return 0;
}
STATIC int
xlog_bread_offset(
struct xlog *log,
xfs_daddr_t blk_no,
int nbblks,
struct xfs_buf *bp,
char *offset)
{
char *orig_offset = bp->b_addr;
int orig_len = BBTOB(bp->b_length);
int error, error2;
error = xfs_buf_associate_memory(bp, offset, BBTOB(nbblks));
if (error)
return error;
error = xlog_bread_noalign(log, blk_no, nbblks, bp);
error2 = xfs_buf_associate_memory(bp, orig_offset, orig_len);
if (error)
return error;
return error2;
}
STATIC int
xlog_bwrite(
struct xlog *log,
xfs_daddr_t blk_no,
int nbblks,
struct xfs_buf *bp)
{
int error;
if (!xlog_buf_bbcount_valid(log, nbblks)) {
xfs_warn(log->l_mp, "Invalid block length (0x%x) for buffer",
nbblks);
XFS_ERROR_REPORT(__func__, XFS_ERRLEVEL_HIGH, log->l_mp);
return -EFSCORRUPTED;
}
blk_no = round_down(blk_no, log->l_sectBBsize);
nbblks = round_up(nbblks, log->l_sectBBsize);
ASSERT(nbblks > 0);
ASSERT(nbblks <= bp->b_length);
XFS_BUF_SET_ADDR(bp, log->l_logBBstart + blk_no);
XFS_BUF_ZEROFLAGS(bp);
xfs_buf_hold(bp);
xfs_buf_lock(bp);
bp->b_io_length = nbblks;
bp->b_error = 0;
error = xfs_bwrite(bp);
if (error)
xfs_buf_ioerror_alert(bp, __func__);
xfs_buf_relse(bp);
return error;
}
STATIC void
xlog_header_check_dump(
xfs_mount_t *mp,
xlog_rec_header_t *head)
{
xfs_debug(mp, "%s: SB : uuid = %pU, fmt = %d",
__func__, &mp->m_sb.sb_uuid, XLOG_FMT);
xfs_debug(mp, " log : uuid = %pU, fmt = %d",
&head->h_fs_uuid, be32_to_cpu(head->h_fmt));
}
STATIC int
xlog_header_check_recover(
xfs_mount_t *mp,
xlog_rec_header_t *head)
{
ASSERT(head->h_magicno == cpu_to_be32(XLOG_HEADER_MAGIC_NUM));
if (unlikely(head->h_fmt != cpu_to_be32(XLOG_FMT))) {
xfs_warn(mp,
"dirty log written in incompatible format - can't recover");
xlog_header_check_dump(mp, head);
XFS_ERROR_REPORT("xlog_header_check_recover(1)",
XFS_ERRLEVEL_HIGH, mp);
return -EFSCORRUPTED;
} else if (unlikely(!uuid_equal(&mp->m_sb.sb_uuid, &head->h_fs_uuid))) {
xfs_warn(mp,
"dirty log entry has mismatched uuid - can't recover");
xlog_header_check_dump(mp, head);
XFS_ERROR_REPORT("xlog_header_check_recover(2)",
XFS_ERRLEVEL_HIGH, mp);
return -EFSCORRUPTED;
}
return 0;
}
STATIC int
xlog_header_check_mount(
xfs_mount_t *mp,
xlog_rec_header_t *head)
{
ASSERT(head->h_magicno == cpu_to_be32(XLOG_HEADER_MAGIC_NUM));
if (uuid_is_nil(&head->h_fs_uuid)) {
xfs_warn(mp, "nil uuid in log - IRIX style log");
} else if (unlikely(!uuid_equal(&mp->m_sb.sb_uuid, &head->h_fs_uuid))) {
xfs_warn(mp, "log has mismatched uuid - can't recover");
xlog_header_check_dump(mp, head);
XFS_ERROR_REPORT("xlog_header_check_mount",
XFS_ERRLEVEL_HIGH, mp);
return -EFSCORRUPTED;
}
return 0;
}
STATIC void
xlog_recover_iodone(
struct xfs_buf *bp)
{
if (bp->b_error) {
if (!XFS_FORCED_SHUTDOWN(bp->b_target->bt_mount)) {
xfs_buf_ioerror_alert(bp, __func__);
xfs_force_shutdown(bp->b_target->bt_mount,
SHUTDOWN_META_IO_ERROR);
}
}
bp->b_iodone = NULL;
xfs_buf_ioend(bp);
}
STATIC int
xlog_find_cycle_start(
struct xlog *log,
struct xfs_buf *bp,
xfs_daddr_t first_blk,
xfs_daddr_t *last_blk,
uint cycle)
{
char *offset;
xfs_daddr_t mid_blk;
xfs_daddr_t end_blk;
uint mid_cycle;
int error;
end_blk = *last_blk;
mid_blk = BLK_AVG(first_blk, end_blk);
while (mid_blk != first_blk && mid_blk != end_blk) {
error = xlog_bread(log, mid_blk, 1, bp, &offset);
if (error)
return error;
mid_cycle = xlog_get_cycle(offset);
if (mid_cycle == cycle)
end_blk = mid_blk;
else
first_blk = mid_blk;
mid_blk = BLK_AVG(first_blk, end_blk);
}
ASSERT((mid_blk == first_blk && mid_blk+1 == end_blk) ||
(mid_blk == end_blk && mid_blk-1 == first_blk));
*last_blk = end_blk;
return 0;
}
STATIC int
xlog_find_verify_cycle(
struct xlog *log,
xfs_daddr_t start_blk,
int nbblks,
uint stop_on_cycle_no,
xfs_daddr_t *new_blk)
{
xfs_daddr_t i, j;
uint cycle;
xfs_buf_t *bp;
xfs_daddr_t bufblks;
char *buf = NULL;
int error = 0;
bufblks = 1 << ffs(nbblks);
while (bufblks > log->l_logBBsize)
bufblks >>= 1;
while (!(bp = xlog_get_bp(log, bufblks))) {
bufblks >>= 1;
if (bufblks < log->l_sectBBsize)
return -ENOMEM;
}
for (i = start_blk; i < start_blk + nbblks; i += bufblks) {
int bcount;
bcount = min(bufblks, (start_blk + nbblks - i));
error = xlog_bread(log, i, bcount, bp, &buf);
if (error)
goto out;
for (j = 0; j < bcount; j++) {
cycle = xlog_get_cycle(buf);
if (cycle == stop_on_cycle_no) {
*new_blk = i+j;
goto out;
}
buf += BBSIZE;
}
}
*new_blk = -1;
out:
xlog_put_bp(bp);
return error;
}
STATIC int
xlog_find_verify_log_record(
struct xlog *log,
xfs_daddr_t start_blk,
xfs_daddr_t *last_blk,
int extra_bblks)
{
xfs_daddr_t i;
xfs_buf_t *bp;
char *offset = NULL;
xlog_rec_header_t *head = NULL;
int error = 0;
int smallmem = 0;
int num_blks = *last_blk - start_blk;
int xhdrs;
ASSERT(start_blk != 0 || *last_blk != start_blk);
if (!(bp = xlog_get_bp(log, num_blks))) {
if (!(bp = xlog_get_bp(log, 1)))
return -ENOMEM;
smallmem = 1;
} else {
error = xlog_bread(log, start_blk, num_blks, bp, &offset);
if (error)
goto out;
offset += ((num_blks - 1) << BBSHIFT);
}
for (i = (*last_blk) - 1; i >= 0; i--) {
if (i < start_blk) {
xfs_warn(log->l_mp,
"Log inconsistent (didn't find previous header)");
ASSERT(0);
error = -EIO;
goto out;
}
if (smallmem) {
error = xlog_bread(log, i, 1, bp, &offset);
if (error)
goto out;
}
head = (xlog_rec_header_t *)offset;
if (head->h_magicno == cpu_to_be32(XLOG_HEADER_MAGIC_NUM))
break;
if (!smallmem)
offset -= BBSIZE;
}
if (i == -1) {
error = 1;
goto out;
}
if ((error = xlog_header_check_mount(log->l_mp, head)))
goto out;
if (xfs_sb_version_haslogv2(&log->l_mp->m_sb)) {
uint h_size = be32_to_cpu(head->h_size);
xhdrs = h_size / XLOG_HEADER_CYCLE_SIZE;
if (h_size % XLOG_HEADER_CYCLE_SIZE)
xhdrs++;
} else {
xhdrs = 1;
}
if (*last_blk - i + extra_bblks !=
BTOBB(be32_to_cpu(head->h_len)) + xhdrs)
*last_blk = i;
out:
xlog_put_bp(bp);
return error;
}
STATIC int
xlog_find_head(
struct xlog *log,
xfs_daddr_t *return_head_blk)
{
xfs_buf_t *bp;
char *offset;
xfs_daddr_t new_blk, first_blk, start_blk, last_blk, head_blk;
int num_scan_bblks;
uint first_half_cycle, last_half_cycle;
uint stop_on_cycle;
int error, log_bbnum = log->l_logBBsize;
error = xlog_find_zeroed(log, &first_blk);
if (error < 0) {
xfs_warn(log->l_mp, "empty log check failed");
return error;
}
if (error == 1) {
*return_head_blk = first_blk;
if (!first_blk) {
xfs_warn(log->l_mp, "totally zeroed log");
}
return 0;
}
first_blk = 0;
bp = xlog_get_bp(log, 1);
if (!bp)
return -ENOMEM;
error = xlog_bread(log, 0, 1, bp, &offset);
if (error)
goto bp_err;
first_half_cycle = xlog_get_cycle(offset);
last_blk = head_blk = log_bbnum - 1;
error = xlog_bread(log, last_blk, 1, bp, &offset);
if (error)
goto bp_err;
last_half_cycle = xlog_get_cycle(offset);
ASSERT(last_half_cycle != 0);
if (first_half_cycle == last_half_cycle) {
head_blk = log_bbnum;
stop_on_cycle = last_half_cycle - 1;
} else {
stop_on_cycle = last_half_cycle;
if ((error = xlog_find_cycle_start(log, bp, first_blk,
&head_blk, last_half_cycle)))
goto bp_err;
}
num_scan_bblks = XLOG_TOTAL_REC_SHIFT(log);
if (head_blk >= num_scan_bblks) {
start_blk = head_blk - num_scan_bblks;
if ((error = xlog_find_verify_cycle(log,
start_blk, num_scan_bblks,
stop_on_cycle, &new_blk)))
goto bp_err;
if (new_blk != -1)
head_blk = new_blk;
} else {
ASSERT(head_blk <= INT_MAX &&
(xfs_daddr_t) num_scan_bblks >= head_blk);
start_blk = log_bbnum - (num_scan_bblks - head_blk);
if ((error = xlog_find_verify_cycle(log, start_blk,
num_scan_bblks - (int)head_blk,
(stop_on_cycle - 1), &new_blk)))
goto bp_err;
if (new_blk != -1) {
head_blk = new_blk;
goto validate_head;
}
start_blk = 0;
ASSERT(head_blk <= INT_MAX);
if ((error = xlog_find_verify_cycle(log,
start_blk, (int)head_blk,
stop_on_cycle, &new_blk)))
goto bp_err;
if (new_blk != -1)
head_blk = new_blk;
}
validate_head:
num_scan_bblks = XLOG_REC_SHIFT(log);
if (head_blk >= num_scan_bblks) {
start_blk = head_blk - num_scan_bblks;
error = xlog_find_verify_log_record(log, start_blk, &head_blk, 0);
if (error == 1)
error = -EIO;
if (error)
goto bp_err;
} else {
start_blk = 0;
ASSERT(head_blk <= INT_MAX);
error = xlog_find_verify_log_record(log, start_blk, &head_blk, 0);
if (error < 0)
goto bp_err;
if (error == 1) {
start_blk = log_bbnum - (num_scan_bblks - head_blk);
new_blk = log_bbnum;
ASSERT(start_blk <= INT_MAX &&
(xfs_daddr_t) log_bbnum-start_blk >= 0);
ASSERT(head_blk <= INT_MAX);
error = xlog_find_verify_log_record(log, start_blk,
&new_blk, (int)head_blk);
if (error == 1)
error = -EIO;
if (error)
goto bp_err;
if (new_blk != log_bbnum)
head_blk = new_blk;
} else if (error)
goto bp_err;
}
xlog_put_bp(bp);
if (head_blk == log_bbnum)
*return_head_blk = 0;
else
*return_head_blk = head_blk;
return 0;
bp_err:
xlog_put_bp(bp);
if (error)
xfs_warn(log->l_mp, "failed to find log head");
return error;
}
STATIC int
xlog_find_tail(
struct xlog *log,
xfs_daddr_t *head_blk,
xfs_daddr_t *tail_blk)
{
xlog_rec_header_t *rhead;
xlog_op_header_t *op_head;
char *offset = NULL;
xfs_buf_t *bp;
int error, i, found;
xfs_daddr_t umount_data_blk;
xfs_daddr_t after_umount_blk;
xfs_lsn_t tail_lsn;
int hblks;
found = 0;
if ((error = xlog_find_head(log, head_blk)))
return error;
bp = xlog_get_bp(log, 1);
if (!bp)
return -ENOMEM;
if (*head_blk == 0) {
error = xlog_bread(log, 0, 1, bp, &offset);
if (error)
goto done;
if (xlog_get_cycle(offset) == 0) {
*tail_blk = 0;
goto done;
}
}
ASSERT(*head_blk < INT_MAX);
for (i = (int)(*head_blk) - 1; i >= 0; i--) {
error = xlog_bread(log, i, 1, bp, &offset);
if (error)
goto done;
if (*(__be32 *)offset == cpu_to_be32(XLOG_HEADER_MAGIC_NUM)) {
found = 1;
break;
}
}
if (!found) {
for (i = log->l_logBBsize - 1; i >= (int)(*head_blk); i--) {
error = xlog_bread(log, i, 1, bp, &offset);
if (error)
goto done;
if (*(__be32 *)offset ==
cpu_to_be32(XLOG_HEADER_MAGIC_NUM)) {
found = 2;
break;
}
}
}
if (!found) {
xfs_warn(log->l_mp, "%s: couldn't find sync record", __func__);
xlog_put_bp(bp);
ASSERT(0);
return -EIO;
}
rhead = (xlog_rec_header_t *)offset;
*tail_blk = BLOCK_LSN(be64_to_cpu(rhead->h_tail_lsn));
log->l_prev_block = i;
log->l_curr_block = (int)*head_blk;
log->l_curr_cycle = be32_to_cpu(rhead->h_cycle);
if (found == 2)
log->l_curr_cycle++;
atomic64_set(&log->l_tail_lsn, be64_to_cpu(rhead->h_tail_lsn));
atomic64_set(&log->l_last_sync_lsn, be64_to_cpu(rhead->h_lsn));
xlog_assign_grant_head(&log->l_reserve_head.grant, log->l_curr_cycle,
BBTOB(log->l_curr_block));
xlog_assign_grant_head(&log->l_write_head.grant, log->l_curr_cycle,
BBTOB(log->l_curr_block));
if (xfs_sb_version_haslogv2(&log->l_mp->m_sb)) {
int h_size = be32_to_cpu(rhead->h_size);
int h_version = be32_to_cpu(rhead->h_version);
if ((h_version & XLOG_VERSION_2) &&
(h_size > XLOG_HEADER_CYCLE_SIZE)) {
hblks = h_size / XLOG_HEADER_CYCLE_SIZE;
if (h_size % XLOG_HEADER_CYCLE_SIZE)
hblks++;
} else {
hblks = 1;
}
} else {
hblks = 1;
}
after_umount_blk = (i + hblks + (int)
BTOBB(be32_to_cpu(rhead->h_len))) % log->l_logBBsize;
tail_lsn = atomic64_read(&log->l_tail_lsn);
if (*head_blk == after_umount_blk &&
be32_to_cpu(rhead->h_num_logops) == 1) {
umount_data_blk = (i + hblks) % log->l_logBBsize;
error = xlog_bread(log, umount_data_blk, 1, bp, &offset);
if (error)
goto done;
op_head = (xlog_op_header_t *)offset;
if (op_head->oh_flags & XLOG_UNMOUNT_TRANS) {
xlog_assign_atomic_lsn(&log->l_tail_lsn,
log->l_curr_cycle, after_umount_blk);
xlog_assign_atomic_lsn(&log->l_last_sync_lsn,
log->l_curr_cycle, after_umount_blk);
*tail_blk = after_umount_blk;
log->l_mp->m_flags |= XFS_MOUNT_WAS_CLEAN;
}
}
if (!xfs_readonly_buftarg(log->l_mp->m_logdev_targp))
error = xlog_clear_stale_blocks(log, tail_lsn);
done:
xlog_put_bp(bp);
if (error)
xfs_warn(log->l_mp, "failed to locate log tail");
return error;
}
STATIC int
xlog_find_zeroed(
struct xlog *log,
xfs_daddr_t *blk_no)
{
xfs_buf_t *bp;
char *offset;
uint first_cycle, last_cycle;
xfs_daddr_t new_blk, last_blk, start_blk;
xfs_daddr_t num_scan_bblks;
int error, log_bbnum = log->l_logBBsize;
*blk_no = 0;
bp = xlog_get_bp(log, 1);
if (!bp)
return -ENOMEM;
error = xlog_bread(log, 0, 1, bp, &offset);
if (error)
goto bp_err;
first_cycle = xlog_get_cycle(offset);
if (first_cycle == 0) {
*blk_no = 0;
xlog_put_bp(bp);
return 1;
}
error = xlog_bread(log, log_bbnum-1, 1, bp, &offset);
if (error)
goto bp_err;
last_cycle = xlog_get_cycle(offset);
if (last_cycle != 0) {
xlog_put_bp(bp);
return 0;
} else if (first_cycle != 1) {
xfs_warn(log->l_mp,
"Log inconsistent or not a log (last==0, first!=1)");
error = -EINVAL;
goto bp_err;
}
last_blk = log_bbnum-1;
if ((error = xlog_find_cycle_start(log, bp, 0, &last_blk, 0)))
goto bp_err;
num_scan_bblks = XLOG_TOTAL_REC_SHIFT(log);
ASSERT(num_scan_bblks <= INT_MAX);
if (last_blk < num_scan_bblks)
num_scan_bblks = last_blk;
start_blk = last_blk - num_scan_bblks;
if ((error = xlog_find_verify_cycle(log, start_blk,
(int)num_scan_bblks, 0, &new_blk)))
goto bp_err;
if (new_blk != -1)
last_blk = new_blk;
error = xlog_find_verify_log_record(log, start_blk, &last_blk, 0);
if (error == 1)
error = -EIO;
if (error)
goto bp_err;
*blk_no = last_blk;
bp_err:
xlog_put_bp(bp);
if (error)
return error;
return 1;
}
STATIC void
xlog_add_record(
struct xlog *log,
char *buf,
int cycle,
int block,
int tail_cycle,
int tail_block)
{
xlog_rec_header_t *recp = (xlog_rec_header_t *)buf;
memset(buf, 0, BBSIZE);
recp->h_magicno = cpu_to_be32(XLOG_HEADER_MAGIC_NUM);
recp->h_cycle = cpu_to_be32(cycle);
recp->h_version = cpu_to_be32(
xfs_sb_version_haslogv2(&log->l_mp->m_sb) ? 2 : 1);
recp->h_lsn = cpu_to_be64(xlog_assign_lsn(cycle, block));
recp->h_tail_lsn = cpu_to_be64(xlog_assign_lsn(tail_cycle, tail_block));
recp->h_fmt = cpu_to_be32(XLOG_FMT);
memcpy(&recp->h_fs_uuid, &log->l_mp->m_sb.sb_uuid, sizeof(uuid_t));
}
STATIC int
xlog_write_log_records(
struct xlog *log,
int cycle,
int start_block,
int blocks,
int tail_cycle,
int tail_block)
{
char *offset;
xfs_buf_t *bp;
int balign, ealign;
int sectbb = log->l_sectBBsize;
int end_block = start_block + blocks;
int bufblks;
int error = 0;
int i, j = 0;
bufblks = 1 << ffs(blocks);
while (bufblks > log->l_logBBsize)
bufblks >>= 1;
while (!(bp = xlog_get_bp(log, bufblks))) {
bufblks >>= 1;
if (bufblks < sectbb)
return -ENOMEM;
}
balign = round_down(start_block, sectbb);
if (balign != start_block) {
error = xlog_bread_noalign(log, start_block, 1, bp);
if (error)
goto out_put_bp;
j = start_block - balign;
}
for (i = start_block; i < end_block; i += bufblks) {
int bcount, endcount;
bcount = min(bufblks, end_block - start_block);
endcount = bcount - j;
ealign = round_down(end_block, sectbb);
if (j == 0 && (start_block + endcount > ealign)) {
offset = bp->b_addr + BBTOB(ealign - start_block);
error = xlog_bread_offset(log, ealign, sectbb,
bp, offset);
if (error)
break;
}
offset = xlog_align(log, start_block, endcount, bp);
for (; j < endcount; j++) {
xlog_add_record(log, offset, cycle, i+j,
tail_cycle, tail_block);
offset += BBSIZE;
}
error = xlog_bwrite(log, start_block, endcount, bp);
if (error)
break;
start_block += endcount;
j = 0;
}
out_put_bp:
xlog_put_bp(bp);
return error;
}
STATIC int
xlog_clear_stale_blocks(
struct xlog *log,
xfs_lsn_t tail_lsn)
{
int tail_cycle, head_cycle;
int tail_block, head_block;
int tail_distance, max_distance;
int distance;
int error;
tail_cycle = CYCLE_LSN(tail_lsn);
tail_block = BLOCK_LSN(tail_lsn);
head_cycle = log->l_curr_cycle;
head_block = log->l_curr_block;
if (head_cycle == tail_cycle) {
if (unlikely(head_block < tail_block || head_block >= log->l_logBBsize)) {
XFS_ERROR_REPORT("xlog_clear_stale_blocks(1)",
XFS_ERRLEVEL_LOW, log->l_mp);
return -EFSCORRUPTED;
}
tail_distance = tail_block + (log->l_logBBsize - head_block);
} else {
if (unlikely(head_block >= tail_block || head_cycle != (tail_cycle + 1))){
XFS_ERROR_REPORT("xlog_clear_stale_blocks(2)",
XFS_ERRLEVEL_LOW, log->l_mp);
return -EFSCORRUPTED;
}
tail_distance = tail_block - head_block;
}
if (tail_distance <= 0) {
ASSERT(tail_distance == 0);
return 0;
}
max_distance = XLOG_TOTAL_REC_SHIFT(log);
max_distance = MIN(max_distance, tail_distance);
if ((head_block + max_distance) <= log->l_logBBsize) {
error = xlog_write_log_records(log, (head_cycle - 1),
head_block, max_distance, tail_cycle,
tail_block);
if (error)
return error;
} else {
distance = log->l_logBBsize - head_block;
error = xlog_write_log_records(log, (head_cycle - 1),
head_block, distance, tail_cycle,
tail_block);
if (error)
return error;
distance = max_distance - (log->l_logBBsize - head_block);
error = xlog_write_log_records(log, head_cycle, 0, distance,
tail_cycle, tail_block);
if (error)
return error;
}
return 0;
}
STATIC int
xlog_recover_reorder_trans(
struct xlog *log,
struct xlog_recover *trans,
int pass)
{
xlog_recover_item_t *item, *n;
int error = 0;
LIST_HEAD(sort_list);
LIST_HEAD(cancel_list);
LIST_HEAD(buffer_list);
LIST_HEAD(inode_buffer_list);
LIST_HEAD(inode_list);
list_splice_init(&trans->r_itemq, &sort_list);
list_for_each_entry_safe(item, n, &sort_list, ri_list) {
xfs_buf_log_format_t *buf_f = item->ri_buf[0].i_addr;
switch (ITEM_TYPE(item)) {
case XFS_LI_ICREATE:
list_move_tail(&item->ri_list, &buffer_list);
break;
case XFS_LI_BUF:
if (buf_f->blf_flags & XFS_BLF_CANCEL) {
trace_xfs_log_recover_item_reorder_head(log,
trans, item, pass);
list_move(&item->ri_list, &cancel_list);
break;
}
if (buf_f->blf_flags & XFS_BLF_INODE_BUF) {
list_move(&item->ri_list, &inode_buffer_list);
break;
}
list_move_tail(&item->ri_list, &buffer_list);
break;
case XFS_LI_INODE:
case XFS_LI_DQUOT:
case XFS_LI_QUOTAOFF:
case XFS_LI_EFD:
case XFS_LI_EFI:
trace_xfs_log_recover_item_reorder_tail(log,
trans, item, pass);
list_move_tail(&item->ri_list, &inode_list);
break;
default:
xfs_warn(log->l_mp,
"%s: unrecognized type of log operation",
__func__);
ASSERT(0);
if (!list_empty(&sort_list))
list_splice_init(&sort_list, &trans->r_itemq);
error = -EIO;
goto out;
}
}
out:
ASSERT(list_empty(&sort_list));
if (!list_empty(&buffer_list))
list_splice(&buffer_list, &trans->r_itemq);
if (!list_empty(&inode_list))
list_splice_tail(&inode_list, &trans->r_itemq);
if (!list_empty(&inode_buffer_list))
list_splice_tail(&inode_buffer_list, &trans->r_itemq);
if (!list_empty(&cancel_list))
list_splice_tail(&cancel_list, &trans->r_itemq);
return error;
}
STATIC int
xlog_recover_buffer_pass1(
struct xlog *log,
struct xlog_recover_item *item)
{
xfs_buf_log_format_t *buf_f = item->ri_buf[0].i_addr;
struct list_head *bucket;
struct xfs_buf_cancel *bcp;
if (!(buf_f->blf_flags & XFS_BLF_CANCEL)) {
trace_xfs_log_recover_buf_not_cancel(log, buf_f);
return 0;
}
bucket = XLOG_BUF_CANCEL_BUCKET(log, buf_f->blf_blkno);
list_for_each_entry(bcp, bucket, bc_list) {
if (bcp->bc_blkno == buf_f->blf_blkno &&
bcp->bc_len == buf_f->blf_len) {
bcp->bc_refcount++;
trace_xfs_log_recover_buf_cancel_ref_inc(log, buf_f);
return 0;
}
}
bcp = kmem_alloc(sizeof(struct xfs_buf_cancel), KM_SLEEP);
bcp->bc_blkno = buf_f->blf_blkno;
bcp->bc_len = buf_f->blf_len;
bcp->bc_refcount = 1;
list_add_tail(&bcp->bc_list, bucket);
trace_xfs_log_recover_buf_cancel_add(log, buf_f);
return 0;
}
STATIC struct xfs_buf_cancel *
xlog_peek_buffer_cancelled(
struct xlog *log,
xfs_daddr_t blkno,
uint len,
ushort flags)
{
struct list_head *bucket;
struct xfs_buf_cancel *bcp;
if (!log->l_buf_cancel_table) {
ASSERT(!(flags & XFS_BLF_CANCEL));
return NULL;
}
bucket = XLOG_BUF_CANCEL_BUCKET(log, blkno);
list_for_each_entry(bcp, bucket, bc_list) {
if (bcp->bc_blkno == blkno && bcp->bc_len == len)
return bcp;
}
ASSERT(!(flags & XFS_BLF_CANCEL));
return NULL;
}
STATIC int
xlog_check_buffer_cancelled(
struct xlog *log,
xfs_daddr_t blkno,
uint len,
ushort flags)
{
struct xfs_buf_cancel *bcp;
bcp = xlog_peek_buffer_cancelled(log, blkno, len, flags);
if (!bcp)
return 0;
if (flags & XFS_BLF_CANCEL) {
if (--bcp->bc_refcount == 0) {
list_del(&bcp->bc_list);
kmem_free(bcp);
}
}
return 1;
}
STATIC int
xlog_recover_do_inode_buffer(
struct xfs_mount *mp,
xlog_recover_item_t *item,
struct xfs_buf *bp,
xfs_buf_log_format_t *buf_f)
{
int i;
int item_index = 0;
int bit = 0;
int nbits = 0;
int reg_buf_offset = 0;
int reg_buf_bytes = 0;
int next_unlinked_offset;
int inodes_per_buf;
xfs_agino_t *logged_nextp;
xfs_agino_t *buffer_nextp;
trace_xfs_log_recover_buf_inode_buf(mp->m_log, buf_f);
if (xfs_sb_version_hascrc(&mp->m_sb))
bp->b_ops = &xfs_inode_buf_ops;
inodes_per_buf = BBTOB(bp->b_io_length) >> mp->m_sb.sb_inodelog;
for (i = 0; i < inodes_per_buf; i++) {
next_unlinked_offset = (i * mp->m_sb.sb_inodesize) +
offsetof(xfs_dinode_t, di_next_unlinked);
while (next_unlinked_offset >=
(reg_buf_offset + reg_buf_bytes)) {
bit += nbits;
bit = xfs_next_bit(buf_f->blf_data_map,
buf_f->blf_map_size, bit);
if (bit == -1)
return 0;
nbits = xfs_contig_bits(buf_f->blf_data_map,
buf_f->blf_map_size, bit);
ASSERT(nbits > 0);
reg_buf_offset = bit << XFS_BLF_SHIFT;
reg_buf_bytes = nbits << XFS_BLF_SHIFT;
item_index++;
}
if (next_unlinked_offset < reg_buf_offset)
continue;
ASSERT(item->ri_buf[item_index].i_addr != NULL);
ASSERT((item->ri_buf[item_index].i_len % XFS_BLF_CHUNK) == 0);
ASSERT((reg_buf_offset + reg_buf_bytes) <=
BBTOB(bp->b_io_length));
logged_nextp = item->ri_buf[item_index].i_addr +
next_unlinked_offset - reg_buf_offset;
if (unlikely(*logged_nextp == 0)) {
xfs_alert(mp,
"Bad inode buffer log record (ptr = 0x%p, bp = 0x%p). "
"Trying to replay bad (0) inode di_next_unlinked field.",
item, bp);
XFS_ERROR_REPORT("xlog_recover_do_inode_buf",
XFS_ERRLEVEL_LOW, mp);
return -EFSCORRUPTED;
}
buffer_nextp = xfs_buf_offset(bp, next_unlinked_offset);
*buffer_nextp = *logged_nextp;
xfs_dinode_calc_crc(mp,
xfs_buf_offset(bp, i * mp->m_sb.sb_inodesize));
}
return 0;
}
static xfs_lsn_t
xlog_recover_get_buf_lsn(
struct xfs_mount *mp,
struct xfs_buf *bp)
{
__uint32_t magic32;
__uint16_t magic16;
__uint16_t magicda;
void *blk = bp->b_addr;
uuid_t *uuid;
xfs_lsn_t lsn = -1;
if (!xfs_sb_version_hascrc(&mp->m_sb))
goto recover_immediately;
magic32 = be32_to_cpu(*(__be32 *)blk);
switch (magic32) {
case XFS_ABTB_CRC_MAGIC:
case XFS_ABTC_CRC_MAGIC:
case XFS_ABTB_MAGIC:
case XFS_ABTC_MAGIC:
case XFS_IBT_CRC_MAGIC:
case XFS_IBT_MAGIC: {
struct xfs_btree_block *btb = blk;
lsn = be64_to_cpu(btb->bb_u.s.bb_lsn);
uuid = &btb->bb_u.s.bb_uuid;
break;
}
case XFS_BMAP_CRC_MAGIC:
case XFS_BMAP_MAGIC: {
struct xfs_btree_block *btb = blk;
lsn = be64_to_cpu(btb->bb_u.l.bb_lsn);
uuid = &btb->bb_u.l.bb_uuid;
break;
}
case XFS_AGF_MAGIC:
lsn = be64_to_cpu(((struct xfs_agf *)blk)->agf_lsn);
uuid = &((struct xfs_agf *)blk)->agf_uuid;
break;
case XFS_AGFL_MAGIC:
lsn = be64_to_cpu(((struct xfs_agfl *)blk)->agfl_lsn);
uuid = &((struct xfs_agfl *)blk)->agfl_uuid;
break;
case XFS_AGI_MAGIC:
lsn = be64_to_cpu(((struct xfs_agi *)blk)->agi_lsn);
uuid = &((struct xfs_agi *)blk)->agi_uuid;
break;
case XFS_SYMLINK_MAGIC:
lsn = be64_to_cpu(((struct xfs_dsymlink_hdr *)blk)->sl_lsn);
uuid = &((struct xfs_dsymlink_hdr *)blk)->sl_uuid;
break;
case XFS_DIR3_BLOCK_MAGIC:
case XFS_DIR3_DATA_MAGIC:
case XFS_DIR3_FREE_MAGIC:
lsn = be64_to_cpu(((struct xfs_dir3_blk_hdr *)blk)->lsn);
uuid = &((struct xfs_dir3_blk_hdr *)blk)->uuid;
break;
case XFS_ATTR3_RMT_MAGIC:
goto recover_immediately;
case XFS_SB_MAGIC:
lsn = be64_to_cpu(((struct xfs_dsb *)blk)->sb_lsn);
uuid = &((struct xfs_dsb *)blk)->sb_uuid;
break;
default:
break;
}
if (lsn != (xfs_lsn_t)-1) {
if (!uuid_equal(&mp->m_sb.sb_uuid, uuid))
goto recover_immediately;
return lsn;
}
magicda = be16_to_cpu(((struct xfs_da_blkinfo *)blk)->magic);
switch (magicda) {
case XFS_DIR3_LEAF1_MAGIC:
case XFS_DIR3_LEAFN_MAGIC:
case XFS_DA3_NODE_MAGIC:
lsn = be64_to_cpu(((struct xfs_da3_blkinfo *)blk)->lsn);
uuid = &((struct xfs_da3_blkinfo *)blk)->uuid;
break;
default:
break;
}
if (lsn != (xfs_lsn_t)-1) {
if (!uuid_equal(&mp->m_sb.sb_uuid, uuid))
goto recover_immediately;
return lsn;
}
magic16 = be16_to_cpu(*(__be16 *)blk);
switch (magic16) {
case XFS_DQUOT_MAGIC:
case XFS_DINODE_MAGIC:
goto recover_immediately;
default:
break;
}
recover_immediately:
return (xfs_lsn_t)-1;
}
static void
xlog_recover_validate_buf_type(
struct xfs_mount *mp,
struct xfs_buf *bp,
xfs_buf_log_format_t *buf_f)
{
struct xfs_da_blkinfo *info = bp->b_addr;
__uint32_t magic32;
__uint16_t magic16;
__uint16_t magicda;
if (!xfs_sb_version_hascrc(&mp->m_sb))
return;
magic32 = be32_to_cpu(*(__be32 *)bp->b_addr);
magic16 = be16_to_cpu(*(__be16*)bp->b_addr);
magicda = be16_to_cpu(info->magic);
switch (xfs_blft_from_flags(buf_f)) {
case XFS_BLFT_BTREE_BUF:
switch (magic32) {
case XFS_ABTB_CRC_MAGIC:
case XFS_ABTC_CRC_MAGIC:
case XFS_ABTB_MAGIC:
case XFS_ABTC_MAGIC:
bp->b_ops = &xfs_allocbt_buf_ops;
break;
case XFS_IBT_CRC_MAGIC:
case XFS_FIBT_CRC_MAGIC:
case XFS_IBT_MAGIC:
case XFS_FIBT_MAGIC:
bp->b_ops = &xfs_inobt_buf_ops;
break;
case XFS_BMAP_CRC_MAGIC:
case XFS_BMAP_MAGIC:
bp->b_ops = &xfs_bmbt_buf_ops;
break;
default:
xfs_warn(mp, "Bad btree block magic!");
ASSERT(0);
break;
}
break;
case XFS_BLFT_AGF_BUF:
if (magic32 != XFS_AGF_MAGIC) {
xfs_warn(mp, "Bad AGF block magic!");
ASSERT(0);
break;
}
bp->b_ops = &xfs_agf_buf_ops;
break;
case XFS_BLFT_AGFL_BUF:
if (magic32 != XFS_AGFL_MAGIC) {
xfs_warn(mp, "Bad AGFL block magic!");
ASSERT(0);
break;
}
bp->b_ops = &xfs_agfl_buf_ops;
break;
case XFS_BLFT_AGI_BUF:
if (magic32 != XFS_AGI_MAGIC) {
xfs_warn(mp, "Bad AGI block magic!");
ASSERT(0);
break;
}
bp->b_ops = &xfs_agi_buf_ops;
break;
case XFS_BLFT_UDQUOT_BUF:
case XFS_BLFT_PDQUOT_BUF:
case XFS_BLFT_GDQUOT_BUF:
#ifdef CONFIG_XFS_QUOTA
if (magic16 != XFS_DQUOT_MAGIC) {
xfs_warn(mp, "Bad DQUOT block magic!");
ASSERT(0);
break;
}
bp->b_ops = &xfs_dquot_buf_ops;
#else
xfs_alert(mp,
"Trying to recover dquots without QUOTA support built in!");
ASSERT(0);
#endif
break;
case XFS_BLFT_DINO_BUF:
if (magic16 != XFS_DINODE_MAGIC) {
xfs_warn(mp, "Bad INODE block magic!");
ASSERT(0);
break;
}
bp->b_ops = &xfs_inode_buf_ops;
break;
case XFS_BLFT_SYMLINK_BUF:
if (magic32 != XFS_SYMLINK_MAGIC) {
xfs_warn(mp, "Bad symlink block magic!");
ASSERT(0);
break;
}
bp->b_ops = &xfs_symlink_buf_ops;
break;
case XFS_BLFT_DIR_BLOCK_BUF:
if (magic32 != XFS_DIR2_BLOCK_MAGIC &&
magic32 != XFS_DIR3_BLOCK_MAGIC) {
xfs_warn(mp, "Bad dir block magic!");
ASSERT(0);
break;
}
bp->b_ops = &xfs_dir3_block_buf_ops;
break;
case XFS_BLFT_DIR_DATA_BUF:
if (magic32 != XFS_DIR2_DATA_MAGIC &&
magic32 != XFS_DIR3_DATA_MAGIC) {
xfs_warn(mp, "Bad dir data magic!");
ASSERT(0);
break;
}
bp->b_ops = &xfs_dir3_data_buf_ops;
break;
case XFS_BLFT_DIR_FREE_BUF:
if (magic32 != XFS_DIR2_FREE_MAGIC &&
magic32 != XFS_DIR3_FREE_MAGIC) {
xfs_warn(mp, "Bad dir3 free magic!");
ASSERT(0);
break;
}
bp->b_ops = &xfs_dir3_free_buf_ops;
break;
case XFS_BLFT_DIR_LEAF1_BUF:
if (magicda != XFS_DIR2_LEAF1_MAGIC &&
magicda != XFS_DIR3_LEAF1_MAGIC) {
xfs_warn(mp, "Bad dir leaf1 magic!");
ASSERT(0);
break;
}
bp->b_ops = &xfs_dir3_leaf1_buf_ops;
break;
case XFS_BLFT_DIR_LEAFN_BUF:
if (magicda != XFS_DIR2_LEAFN_MAGIC &&
magicda != XFS_DIR3_LEAFN_MAGIC) {
xfs_warn(mp, "Bad dir leafn magic!");
ASSERT(0);
break;
}
bp->b_ops = &xfs_dir3_leafn_buf_ops;
break;
case XFS_BLFT_DA_NODE_BUF:
if (magicda != XFS_DA_NODE_MAGIC &&
magicda != XFS_DA3_NODE_MAGIC) {
xfs_warn(mp, "Bad da node magic!");
ASSERT(0);
break;
}
bp->b_ops = &xfs_da3_node_buf_ops;
break;
case XFS_BLFT_ATTR_LEAF_BUF:
if (magicda != XFS_ATTR_LEAF_MAGIC &&
magicda != XFS_ATTR3_LEAF_MAGIC) {
xfs_warn(mp, "Bad attr leaf magic!");
ASSERT(0);
break;
}
bp->b_ops = &xfs_attr3_leaf_buf_ops;
break;
case XFS_BLFT_ATTR_RMT_BUF:
if (magic32 != XFS_ATTR3_RMT_MAGIC) {
xfs_warn(mp, "Bad attr remote magic!");
ASSERT(0);
break;
}
bp->b_ops = &xfs_attr3_rmt_buf_ops;
break;
case XFS_BLFT_SB_BUF:
if (magic32 != XFS_SB_MAGIC) {
xfs_warn(mp, "Bad SB block magic!");
ASSERT(0);
break;
}
bp->b_ops = &xfs_sb_buf_ops;
break;
default:
xfs_warn(mp, "Unknown buffer type %d!",
xfs_blft_from_flags(buf_f));
break;
}
}
STATIC void
xlog_recover_do_reg_buffer(
struct xfs_mount *mp,
xlog_recover_item_t *item,
struct xfs_buf *bp,
xfs_buf_log_format_t *buf_f)
{
int i;
int bit;
int nbits;
int error;
trace_xfs_log_recover_buf_reg_buf(mp->m_log, buf_f);
bit = 0;
i = 1;
while (1) {
bit = xfs_next_bit(buf_f->blf_data_map,
buf_f->blf_map_size, bit);
if (bit == -1)
break;
nbits = xfs_contig_bits(buf_f->blf_data_map,
buf_f->blf_map_size, bit);
ASSERT(nbits > 0);
ASSERT(item->ri_buf[i].i_addr != NULL);
ASSERT(item->ri_buf[i].i_len % XFS_BLF_CHUNK == 0);
ASSERT(BBTOB(bp->b_io_length) >=
((uint)bit << XFS_BLF_SHIFT) + (nbits << XFS_BLF_SHIFT));
if (item->ri_buf[i].i_len < (nbits << XFS_BLF_SHIFT))
nbits = item->ri_buf[i].i_len >> XFS_BLF_SHIFT;
error = 0;
if (buf_f->blf_flags &
(XFS_BLF_UDQUOT_BUF|XFS_BLF_PDQUOT_BUF|XFS_BLF_GDQUOT_BUF)) {
if (item->ri_buf[i].i_addr == NULL) {
xfs_alert(mp,
"XFS: NULL dquot in %s.", __func__);
goto next;
}
if (item->ri_buf[i].i_len < sizeof(xfs_disk_dquot_t)) {
xfs_alert(mp,
"XFS: dquot too small (%d) in %s.",
item->ri_buf[i].i_len, __func__);
goto next;
}
error = xfs_dqcheck(mp, item->ri_buf[i].i_addr,
-1, 0, XFS_QMOPT_DOWARN,
"dquot_buf_recover");
if (error)
goto next;
}
memcpy(xfs_buf_offset(bp,
(uint)bit << XFS_BLF_SHIFT),
item->ri_buf[i].i_addr,
nbits<<XFS_BLF_SHIFT);
next:
i++;
bit += nbits;
}
ASSERT(i == item->ri_total);
xlog_recover_validate_buf_type(mp, bp, buf_f);
}
STATIC bool
xlog_recover_do_dquot_buffer(
struct xfs_mount *mp,
struct xlog *log,
struct xlog_recover_item *item,
struct xfs_buf *bp,
struct xfs_buf_log_format *buf_f)
{
uint type;
trace_xfs_log_recover_buf_dquot_buf(log, buf_f);
if (!mp->m_qflags)
return false;
type = 0;
if (buf_f->blf_flags & XFS_BLF_UDQUOT_BUF)
type |= XFS_DQ_USER;
if (buf_f->blf_flags & XFS_BLF_PDQUOT_BUF)
type |= XFS_DQ_PROJ;
if (buf_f->blf_flags & XFS_BLF_GDQUOT_BUF)
type |= XFS_DQ_GROUP;
if (log->l_quotaoffs_flag & type)
return false;
xlog_recover_do_reg_buffer(mp, item, bp, buf_f);
return true;
}
STATIC int
xlog_recover_buffer_pass2(
struct xlog *log,
struct list_head *buffer_list,
struct xlog_recover_item *item,
xfs_lsn_t current_lsn)
{
xfs_buf_log_format_t *buf_f = item->ri_buf[0].i_addr;
xfs_mount_t *mp = log->l_mp;
xfs_buf_t *bp;
int error;
uint buf_flags;
xfs_lsn_t lsn;
if (xlog_check_buffer_cancelled(log, buf_f->blf_blkno,
buf_f->blf_len, buf_f->blf_flags)) {
trace_xfs_log_recover_buf_cancel(log, buf_f);
return 0;
}
trace_xfs_log_recover_buf_recover(log, buf_f);
buf_flags = 0;
if (buf_f->blf_flags & XFS_BLF_INODE_BUF)
buf_flags |= XBF_UNMAPPED;
bp = xfs_buf_read(mp->m_ddev_targp, buf_f->blf_blkno, buf_f->blf_len,
buf_flags, NULL);
if (!bp)
return -ENOMEM;
error = bp->b_error;
if (error) {
xfs_buf_ioerror_alert(bp, "xlog_recover_do..(read#1)");
goto out_release;
}
lsn = xlog_recover_get_buf_lsn(mp, bp);
if (lsn && lsn != -1 && XFS_LSN_CMP(lsn, current_lsn) >= 0) {
xlog_recover_validate_buf_type(mp, bp, buf_f);
goto out_release;
}
if (buf_f->blf_flags & XFS_BLF_INODE_BUF) {
error = xlog_recover_do_inode_buffer(mp, item, bp, buf_f);
if (error)
goto out_release;
} else if (buf_f->blf_flags &
(XFS_BLF_UDQUOT_BUF|XFS_BLF_PDQUOT_BUF|XFS_BLF_GDQUOT_BUF)) {
bool dirty;
dirty = xlog_recover_do_dquot_buffer(mp, log, item, bp, buf_f);
if (!dirty)
goto out_release;
} else {
xlog_recover_do_reg_buffer(mp, item, bp, buf_f);
}
if (XFS_DINODE_MAGIC ==
be16_to_cpu(*((__be16 *)xfs_buf_offset(bp, 0))) &&
(BBTOB(bp->b_io_length) != MAX(log->l_mp->m_sb.sb_blocksize,
(__uint32_t)log->l_mp->m_inode_cluster_size))) {
xfs_buf_stale(bp);
error = xfs_bwrite(bp);
} else {
ASSERT(bp->b_target->bt_mount == mp);
bp->b_iodone = xlog_recover_iodone;
xfs_buf_delwri_queue(bp, buffer_list);
}
out_release:
xfs_buf_relse(bp);
return error;
}
STATIC int
xfs_recover_inode_owner_change(
struct xfs_mount *mp,
struct xfs_dinode *dip,
struct xfs_inode_log_format *in_f,
struct list_head *buffer_list)
{
struct xfs_inode *ip;
int error;
ASSERT(in_f->ilf_fields & (XFS_ILOG_DOWNER|XFS_ILOG_AOWNER));
ip = xfs_inode_alloc(mp, in_f->ilf_ino);
if (!ip)
return -ENOMEM;
xfs_dinode_from_disk(&ip->i_d, dip);
ASSERT(ip->i_d.di_version >= 3);
error = xfs_iformat_fork(ip, dip);
if (error)
goto out_free_ip;
if (in_f->ilf_fields & XFS_ILOG_DOWNER) {
ASSERT(in_f->ilf_fields & XFS_ILOG_DBROOT);
error = xfs_bmbt_change_owner(NULL, ip, XFS_DATA_FORK,
ip->i_ino, buffer_list);
if (error)
goto out_free_ip;
}
if (in_f->ilf_fields & XFS_ILOG_AOWNER) {
ASSERT(in_f->ilf_fields & XFS_ILOG_ABROOT);
error = xfs_bmbt_change_owner(NULL, ip, XFS_ATTR_FORK,
ip->i_ino, buffer_list);
if (error)
goto out_free_ip;
}
out_free_ip:
xfs_inode_free(ip);
return error;
}
STATIC int
xlog_recover_inode_pass2(
struct xlog *log,
struct list_head *buffer_list,
struct xlog_recover_item *item,
xfs_lsn_t current_lsn)
{
xfs_inode_log_format_t *in_f;
xfs_mount_t *mp = log->l_mp;
xfs_buf_t *bp;
xfs_dinode_t *dip;
int len;
char *src;
char *dest;
int error;
int attr_index;
uint fields;
xfs_icdinode_t *dicp;
uint isize;
int need_free = 0;
if (item->ri_buf[0].i_len == sizeof(xfs_inode_log_format_t)) {
in_f = item->ri_buf[0].i_addr;
} else {
in_f = kmem_alloc(sizeof(xfs_inode_log_format_t), KM_SLEEP);
need_free = 1;
error = xfs_inode_item_format_convert(&item->ri_buf[0], in_f);
if (error)
goto error;
}
if (xlog_check_buffer_cancelled(log, in_f->ilf_blkno,
in_f->ilf_len, 0)) {
error = 0;
trace_xfs_log_recover_inode_cancel(log, in_f);
goto error;
}
trace_xfs_log_recover_inode_recover(log, in_f);
bp = xfs_buf_read(mp->m_ddev_targp, in_f->ilf_blkno, in_f->ilf_len, 0,
&xfs_inode_buf_ops);
if (!bp) {
error = -ENOMEM;
goto error;
}
error = bp->b_error;
if (error) {
xfs_buf_ioerror_alert(bp, "xlog_recover_do..(read#2)");
goto out_release;
}
ASSERT(in_f->ilf_fields & XFS_ILOG_CORE);
dip = xfs_buf_offset(bp, in_f->ilf_boffset);
if (unlikely(dip->di_magic != cpu_to_be16(XFS_DINODE_MAGIC))) {
xfs_alert(mp,
"%s: Bad inode magic number, dip = 0x%p, dino bp = 0x%p, ino = %Ld",
__func__, dip, bp, in_f->ilf_ino);
XFS_ERROR_REPORT("xlog_recover_inode_pass2(1)",
XFS_ERRLEVEL_LOW, mp);
error = -EFSCORRUPTED;
goto out_release;
}
dicp = item->ri_buf[1].i_addr;
if (unlikely(dicp->di_magic != XFS_DINODE_MAGIC)) {
xfs_alert(mp,
"%s: Bad inode log record, rec ptr 0x%p, ino %Ld",
__func__, item, in_f->ilf_ino);
XFS_ERROR_REPORT("xlog_recover_inode_pass2(2)",
XFS_ERRLEVEL_LOW, mp);
error = -EFSCORRUPTED;
goto out_release;
}
if (dip->di_version >= 3) {
xfs_lsn_t lsn = be64_to_cpu(dip->di_lsn);
if (lsn && lsn != -1 && XFS_LSN_CMP(lsn, current_lsn) >= 0) {
trace_xfs_log_recover_inode_skip(log, in_f);
error = 0;
goto out_owner_change;
}
}
if (!xfs_sb_version_hascrc(&mp->m_sb) &&
dicp->di_flushiter < be16_to_cpu(dip->di_flushiter)) {
if (be16_to_cpu(dip->di_flushiter) == DI_MAX_FLUSH &&
dicp->di_flushiter < (DI_MAX_FLUSH >> 1)) {
} else {
trace_xfs_log_recover_inode_skip(log, in_f);
error = 0;
goto out_release;
}
}
dicp->di_flushiter = 0;
if (unlikely(S_ISREG(dicp->di_mode))) {
if ((dicp->di_format != XFS_DINODE_FMT_EXTENTS) &&
(dicp->di_format != XFS_DINODE_FMT_BTREE)) {
XFS_CORRUPTION_ERROR("xlog_recover_inode_pass2(3)",
XFS_ERRLEVEL_LOW, mp, dicp);
xfs_alert(mp,
"%s: Bad regular inode log record, rec ptr 0x%p, "
"ino ptr = 0x%p, ino bp = 0x%p, ino %Ld",
__func__, item, dip, bp, in_f->ilf_ino);
error = -EFSCORRUPTED;
goto out_release;
}
} else if (unlikely(S_ISDIR(dicp->di_mode))) {
if ((dicp->di_format != XFS_DINODE_FMT_EXTENTS) &&
(dicp->di_format != XFS_DINODE_FMT_BTREE) &&
(dicp->di_format != XFS_DINODE_FMT_LOCAL)) {
XFS_CORRUPTION_ERROR("xlog_recover_inode_pass2(4)",
XFS_ERRLEVEL_LOW, mp, dicp);
xfs_alert(mp,
"%s: Bad dir inode log record, rec ptr 0x%p, "
"ino ptr = 0x%p, ino bp = 0x%p, ino %Ld",
__func__, item, dip, bp, in_f->ilf_ino);
error = -EFSCORRUPTED;
goto out_release;
}
}
if (unlikely(dicp->di_nextents + dicp->di_anextents > dicp->di_nblocks)){
XFS_CORRUPTION_ERROR("xlog_recover_inode_pass2(5)",
XFS_ERRLEVEL_LOW, mp, dicp);
xfs_alert(mp,
"%s: Bad inode log record, rec ptr 0x%p, dino ptr 0x%p, "
"dino bp 0x%p, ino %Ld, total extents = %d, nblocks = %Ld",
__func__, item, dip, bp, in_f->ilf_ino,
dicp->di_nextents + dicp->di_anextents,
dicp->di_nblocks);
error = -EFSCORRUPTED;
goto out_release;
}
if (unlikely(dicp->di_forkoff > mp->m_sb.sb_inodesize)) {
XFS_CORRUPTION_ERROR("xlog_recover_inode_pass2(6)",
XFS_ERRLEVEL_LOW, mp, dicp);
xfs_alert(mp,
"%s: Bad inode log record, rec ptr 0x%p, dino ptr 0x%p, "
"dino bp 0x%p, ino %Ld, forkoff 0x%x", __func__,
item, dip, bp, in_f->ilf_ino, dicp->di_forkoff);
error = -EFSCORRUPTED;
goto out_release;
}
isize = xfs_icdinode_size(dicp->di_version);
if (unlikely(item->ri_buf[1].i_len > isize)) {
XFS_CORRUPTION_ERROR("xlog_recover_inode_pass2(7)",
XFS_ERRLEVEL_LOW, mp, dicp);
xfs_alert(mp,
"%s: Bad inode log record length %d, rec ptr 0x%p",
__func__, item->ri_buf[1].i_len, item);
error = -EFSCORRUPTED;
goto out_release;
}
xfs_dinode_to_disk(dip, dicp);
if (item->ri_buf[1].i_len > isize) {
memcpy((char *)dip + isize,
item->ri_buf[1].i_addr + isize,
item->ri_buf[1].i_len - isize);
}
fields = in_f->ilf_fields;
switch (fields & (XFS_ILOG_DEV | XFS_ILOG_UUID)) {
case XFS_ILOG_DEV:
xfs_dinode_put_rdev(dip, in_f->ilf_u.ilfu_rdev);
break;
case XFS_ILOG_UUID:
memcpy(XFS_DFORK_DPTR(dip),
&in_f->ilf_u.ilfu_uuid,
sizeof(uuid_t));
break;
}
if (in_f->ilf_size == 2)
goto out_owner_change;
len = item->ri_buf[2].i_len;
src = item->ri_buf[2].i_addr;
ASSERT(in_f->ilf_size <= 4);
ASSERT((in_f->ilf_size == 3) || (fields & XFS_ILOG_AFORK));
ASSERT(!(fields & XFS_ILOG_DFORK) ||
(len == in_f->ilf_dsize));
switch (fields & XFS_ILOG_DFORK) {
case XFS_ILOG_DDATA:
case XFS_ILOG_DEXT:
memcpy(XFS_DFORK_DPTR(dip), src, len);
break;
case XFS_ILOG_DBROOT:
xfs_bmbt_to_bmdr(mp, (struct xfs_btree_block *)src, len,
(xfs_bmdr_block_t *)XFS_DFORK_DPTR(dip),
XFS_DFORK_DSIZE(dip, mp));
break;
default:
ASSERT((fields & XFS_ILOG_DFORK) == 0);
break;
}
if (in_f->ilf_fields & XFS_ILOG_AFORK) {
if (in_f->ilf_fields & XFS_ILOG_DFORK) {
attr_index = 3;
} else {
attr_index = 2;
}
len = item->ri_buf[attr_index].i_len;
src = item->ri_buf[attr_index].i_addr;
ASSERT(len == in_f->ilf_asize);
switch (in_f->ilf_fields & XFS_ILOG_AFORK) {
case XFS_ILOG_ADATA:
case XFS_ILOG_AEXT:
dest = XFS_DFORK_APTR(dip);
ASSERT(len <= XFS_DFORK_ASIZE(dip, mp));
memcpy(dest, src, len);
break;
case XFS_ILOG_ABROOT:
dest = XFS_DFORK_APTR(dip);
xfs_bmbt_to_bmdr(mp, (struct xfs_btree_block *)src,
len, (xfs_bmdr_block_t*)dest,
XFS_DFORK_ASIZE(dip, mp));
break;
default:
xfs_warn(log->l_mp, "%s: Invalid flag", __func__);
ASSERT(0);
error = -EIO;
goto out_release;
}
}
out_owner_change:
if (in_f->ilf_fields & (XFS_ILOG_DOWNER|XFS_ILOG_AOWNER))
error = xfs_recover_inode_owner_change(mp, dip, in_f,
buffer_list);
xfs_dinode_calc_crc(log->l_mp, dip);
ASSERT(bp->b_target->bt_mount == mp);
bp->b_iodone = xlog_recover_iodone;
xfs_buf_delwri_queue(bp, buffer_list);
out_release:
xfs_buf_relse(bp);
error:
if (need_free)
kmem_free(in_f);
return error;
}
STATIC int
xlog_recover_quotaoff_pass1(
struct xlog *log,
struct xlog_recover_item *item)
{
xfs_qoff_logformat_t *qoff_f = item->ri_buf[0].i_addr;
ASSERT(qoff_f);
if (qoff_f->qf_flags & XFS_UQUOTA_ACCT)
log->l_quotaoffs_flag |= XFS_DQ_USER;
if (qoff_f->qf_flags & XFS_PQUOTA_ACCT)
log->l_quotaoffs_flag |= XFS_DQ_PROJ;
if (qoff_f->qf_flags & XFS_GQUOTA_ACCT)
log->l_quotaoffs_flag |= XFS_DQ_GROUP;
return 0;
}
STATIC int
xlog_recover_dquot_pass2(
struct xlog *log,
struct list_head *buffer_list,
struct xlog_recover_item *item,
xfs_lsn_t current_lsn)
{
xfs_mount_t *mp = log->l_mp;
xfs_buf_t *bp;
struct xfs_disk_dquot *ddq, *recddq;
int error;
xfs_dq_logformat_t *dq_f;
uint type;
if (mp->m_qflags == 0)
return 0;
recddq = item->ri_buf[1].i_addr;
if (recddq == NULL) {
xfs_alert(log->l_mp, "NULL dquot in %s.", __func__);
return -EIO;
}
if (item->ri_buf[1].i_len < sizeof(xfs_disk_dquot_t)) {
xfs_alert(log->l_mp, "dquot too small (%d) in %s.",
item->ri_buf[1].i_len, __func__);
return -EIO;
}
type = recddq->d_flags & (XFS_DQ_USER | XFS_DQ_PROJ | XFS_DQ_GROUP);
ASSERT(type);
if (log->l_quotaoffs_flag & type)
return 0;
dq_f = item->ri_buf[0].i_addr;
ASSERT(dq_f);
error = xfs_dqcheck(mp, recddq, dq_f->qlf_id, 0, XFS_QMOPT_DOWARN,
"xlog_recover_dquot_pass2 (log copy)");
if (error)
return -EIO;
ASSERT(dq_f->qlf_len == 1);
error = xfs_trans_read_buf(mp, NULL, mp->m_ddev_targp, dq_f->qlf_blkno,
XFS_FSB_TO_BB(mp, dq_f->qlf_len), 0, &bp,
&xfs_dquot_buf_ops);
if (error)
return error;
ASSERT(bp);
ddq = xfs_buf_offset(bp, dq_f->qlf_boffset);
if (xfs_sb_version_hascrc(&mp->m_sb)) {
struct xfs_dqblk *dqb = (struct xfs_dqblk *)ddq;
xfs_lsn_t lsn = be64_to_cpu(dqb->dd_lsn);
if (lsn && lsn != -1 && XFS_LSN_CMP(lsn, current_lsn) >= 0) {
goto out_release;
}
}
memcpy(ddq, recddq, item->ri_buf[1].i_len);
if (xfs_sb_version_hascrc(&mp->m_sb)) {
xfs_update_cksum((char *)ddq, sizeof(struct xfs_dqblk),
XFS_DQUOT_CRC_OFF);
}
ASSERT(dq_f->qlf_size == 2);
ASSERT(bp->b_target->bt_mount == mp);
bp->b_iodone = xlog_recover_iodone;
xfs_buf_delwri_queue(bp, buffer_list);
out_release:
xfs_buf_relse(bp);
return 0;
}
STATIC int
xlog_recover_efi_pass2(
struct xlog *log,
struct xlog_recover_item *item,
xfs_lsn_t lsn)
{
int error;
xfs_mount_t *mp = log->l_mp;
xfs_efi_log_item_t *efip;
xfs_efi_log_format_t *efi_formatp;
efi_formatp = item->ri_buf[0].i_addr;
efip = xfs_efi_init(mp, efi_formatp->efi_nextents);
if ((error = xfs_efi_copy_format(&(item->ri_buf[0]),
&(efip->efi_format)))) {
xfs_efi_item_free(efip);
return error;
}
atomic_set(&efip->efi_next_extent, efi_formatp->efi_nextents);
spin_lock(&log->l_ailp->xa_lock);
xfs_trans_ail_update(log->l_ailp, &efip->efi_item, lsn);
return 0;
}
STATIC int
xlog_recover_efd_pass2(
struct xlog *log,
struct xlog_recover_item *item)
{
xfs_efd_log_format_t *efd_formatp;
xfs_efi_log_item_t *efip = NULL;
xfs_log_item_t *lip;
__uint64_t efi_id;
struct xfs_ail_cursor cur;
struct xfs_ail *ailp = log->l_ailp;
efd_formatp = item->ri_buf[0].i_addr;
ASSERT((item->ri_buf[0].i_len == (sizeof(xfs_efd_log_format_32_t) +
((efd_formatp->efd_nextents - 1) * sizeof(xfs_extent_32_t)))) ||
(item->ri_buf[0].i_len == (sizeof(xfs_efd_log_format_64_t) +
((efd_formatp->efd_nextents - 1) * sizeof(xfs_extent_64_t)))));
efi_id = efd_formatp->efd_efi_id;
spin_lock(&ailp->xa_lock);
lip = xfs_trans_ail_cursor_first(ailp, &cur, 0);
while (lip != NULL) {
if (lip->li_type == XFS_LI_EFI) {
efip = (xfs_efi_log_item_t *)lip;
if (efip->efi_format.efi_id == efi_id) {
xfs_trans_ail_delete(ailp, lip,
SHUTDOWN_CORRUPT_INCORE);
xfs_efi_item_free(efip);
spin_lock(&ailp->xa_lock);
break;
}
}
lip = xfs_trans_ail_cursor_next(ailp, &cur);
}
xfs_trans_ail_cursor_done(&cur);
spin_unlock(&ailp->xa_lock);
return 0;
}
STATIC int
xlog_recover_do_icreate_pass2(
struct xlog *log,
struct list_head *buffer_list,
xlog_recover_item_t *item)
{
struct xfs_mount *mp = log->l_mp;
struct xfs_icreate_log *icl;
xfs_agnumber_t agno;
xfs_agblock_t agbno;
unsigned int count;
unsigned int isize;
xfs_agblock_t length;
icl = (struct xfs_icreate_log *)item->ri_buf[0].i_addr;
if (icl->icl_type != XFS_LI_ICREATE) {
xfs_warn(log->l_mp, "xlog_recover_do_icreate_trans: bad type");
return -EINVAL;
}
if (icl->icl_size != 1) {
xfs_warn(log->l_mp, "xlog_recover_do_icreate_trans: bad icl size");
return -EINVAL;
}
agno = be32_to_cpu(icl->icl_ag);
if (agno >= mp->m_sb.sb_agcount) {
xfs_warn(log->l_mp, "xlog_recover_do_icreate_trans: bad agno");
return -EINVAL;
}
agbno = be32_to_cpu(icl->icl_agbno);
if (!agbno || agbno == NULLAGBLOCK || agbno >= mp->m_sb.sb_agblocks) {
xfs_warn(log->l_mp, "xlog_recover_do_icreate_trans: bad agbno");
return -EINVAL;
}
isize = be32_to_cpu(icl->icl_isize);
if (isize != mp->m_sb.sb_inodesize) {
xfs_warn(log->l_mp, "xlog_recover_do_icreate_trans: bad isize");
return -EINVAL;
}
count = be32_to_cpu(icl->icl_count);
if (!count) {
xfs_warn(log->l_mp, "xlog_recover_do_icreate_trans: bad count");
return -EINVAL;
}
length = be32_to_cpu(icl->icl_length);
if (!length || length >= mp->m_sb.sb_agblocks) {
xfs_warn(log->l_mp, "xlog_recover_do_icreate_trans: bad length");
return -EINVAL;
}
if (length != mp->m_ialloc_blks &&
length != mp->m_ialloc_min_blks) {
xfs_warn(log->l_mp,
"%s: unsupported chunk length", __FUNCTION__);
return -EINVAL;
}
if ((count >> mp->m_sb.sb_inopblog) != length) {
xfs_warn(log->l_mp,
"%s: inconsistent inode count and chunk length",
__FUNCTION__);
return -EINVAL;
}
if (xlog_check_buffer_cancelled(log,
XFS_AGB_TO_DADDR(mp, agno, agbno), length, 0))
return 0;
xfs_ialloc_inode_init(mp, NULL, buffer_list, count, agno, agbno, length,
be32_to_cpu(icl->icl_gen));
return 0;
}
STATIC void
xlog_recover_buffer_ra_pass2(
struct xlog *log,
struct xlog_recover_item *item)
{
struct xfs_buf_log_format *buf_f = item->ri_buf[0].i_addr;
struct xfs_mount *mp = log->l_mp;
if (xlog_peek_buffer_cancelled(log, buf_f->blf_blkno,
buf_f->blf_len, buf_f->blf_flags)) {
return;
}
xfs_buf_readahead(mp->m_ddev_targp, buf_f->blf_blkno,
buf_f->blf_len, NULL);
}
STATIC void
xlog_recover_inode_ra_pass2(
struct xlog *log,
struct xlog_recover_item *item)
{
struct xfs_inode_log_format ilf_buf;
struct xfs_inode_log_format *ilfp;
struct xfs_mount *mp = log->l_mp;
int error;
if (item->ri_buf[0].i_len == sizeof(struct xfs_inode_log_format)) {
ilfp = item->ri_buf[0].i_addr;
} else {
ilfp = &ilf_buf;
memset(ilfp, 0, sizeof(*ilfp));
error = xfs_inode_item_format_convert(&item->ri_buf[0], ilfp);
if (error)
return;
}
if (xlog_peek_buffer_cancelled(log, ilfp->ilf_blkno, ilfp->ilf_len, 0))
return;
xfs_buf_readahead(mp->m_ddev_targp, ilfp->ilf_blkno,
ilfp->ilf_len, &xfs_inode_buf_ra_ops);
}
STATIC void
xlog_recover_dquot_ra_pass2(
struct xlog *log,
struct xlog_recover_item *item)
{
struct xfs_mount *mp = log->l_mp;
struct xfs_disk_dquot *recddq;
struct xfs_dq_logformat *dq_f;
uint type;
if (mp->m_qflags == 0)
return;
recddq = item->ri_buf[1].i_addr;
if (recddq == NULL)
return;
if (item->ri_buf[1].i_len < sizeof(struct xfs_disk_dquot))
return;
type = recddq->d_flags & (XFS_DQ_USER | XFS_DQ_PROJ | XFS_DQ_GROUP);
ASSERT(type);
if (log->l_quotaoffs_flag & type)
return;
dq_f = item->ri_buf[0].i_addr;
ASSERT(dq_f);
ASSERT(dq_f->qlf_len == 1);
xfs_buf_readahead(mp->m_ddev_targp, dq_f->qlf_blkno,
XFS_FSB_TO_BB(mp, dq_f->qlf_len), NULL);
}
STATIC void
xlog_recover_ra_pass2(
struct xlog *log,
struct xlog_recover_item *item)
{
switch (ITEM_TYPE(item)) {
case XFS_LI_BUF:
xlog_recover_buffer_ra_pass2(log, item);
break;
case XFS_LI_INODE:
xlog_recover_inode_ra_pass2(log, item);
break;
case XFS_LI_DQUOT:
xlog_recover_dquot_ra_pass2(log, item);
break;
case XFS_LI_EFI:
case XFS_LI_EFD:
case XFS_LI_QUOTAOFF:
default:
break;
}
}
STATIC int
xlog_recover_commit_pass1(
struct xlog *log,
struct xlog_recover *trans,
struct xlog_recover_item *item)
{
trace_xfs_log_recover_item_recover(log, trans, item, XLOG_RECOVER_PASS1);
switch (ITEM_TYPE(item)) {
case XFS_LI_BUF:
return xlog_recover_buffer_pass1(log, item);
case XFS_LI_QUOTAOFF:
return xlog_recover_quotaoff_pass1(log, item);
case XFS_LI_INODE:
case XFS_LI_EFI:
case XFS_LI_EFD:
case XFS_LI_DQUOT:
case XFS_LI_ICREATE:
return 0;
default:
xfs_warn(log->l_mp, "%s: invalid item type (%d)",
__func__, ITEM_TYPE(item));
ASSERT(0);
return -EIO;
}
}
STATIC int
xlog_recover_commit_pass2(
struct xlog *log,
struct xlog_recover *trans,
struct list_head *buffer_list,
struct xlog_recover_item *item)
{
trace_xfs_log_recover_item_recover(log, trans, item, XLOG_RECOVER_PASS2);
switch (ITEM_TYPE(item)) {
case XFS_LI_BUF:
return xlog_recover_buffer_pass2(log, buffer_list, item,
trans->r_lsn);
case XFS_LI_INODE:
return xlog_recover_inode_pass2(log, buffer_list, item,
trans->r_lsn);
case XFS_LI_EFI:
return xlog_recover_efi_pass2(log, item, trans->r_lsn);
case XFS_LI_EFD:
return xlog_recover_efd_pass2(log, item);
case XFS_LI_DQUOT:
return xlog_recover_dquot_pass2(log, buffer_list, item,
trans->r_lsn);
case XFS_LI_ICREATE:
return xlog_recover_do_icreate_pass2(log, buffer_list, item);
case XFS_LI_QUOTAOFF:
return 0;
default:
xfs_warn(log->l_mp, "%s: invalid item type (%d)",
__func__, ITEM_TYPE(item));
ASSERT(0);
return -EIO;
}
}
STATIC int
xlog_recover_items_pass2(
struct xlog *log,
struct xlog_recover *trans,
struct list_head *buffer_list,
struct list_head *item_list)
{
struct xlog_recover_item *item;
int error = 0;
list_for_each_entry(item, item_list, ri_list) {
error = xlog_recover_commit_pass2(log, trans,
buffer_list, item);
if (error)
return error;
}
return error;
}
STATIC int
xlog_recover_commit_trans(
struct xlog *log,
struct xlog_recover *trans,
int pass)
{
int error = 0;
int error2;
int items_queued = 0;
struct xlog_recover_item *item;
struct xlog_recover_item *next;
LIST_HEAD (buffer_list);
LIST_HEAD (ra_list);
LIST_HEAD (done_list);
#define XLOG_RECOVER_COMMIT_QUEUE_MAX 100
hlist_del(&trans->r_list);
error = xlog_recover_reorder_trans(log, trans, pass);
if (error)
return error;
list_for_each_entry_safe(item, next, &trans->r_itemq, ri_list) {
switch (pass) {
case XLOG_RECOVER_PASS1:
error = xlog_recover_commit_pass1(log, trans, item);
break;
case XLOG_RECOVER_PASS2:
xlog_recover_ra_pass2(log, item);
list_move_tail(&item->ri_list, &ra_list);
items_queued++;
if (items_queued >= XLOG_RECOVER_COMMIT_QUEUE_MAX) {
error = xlog_recover_items_pass2(log, trans,
&buffer_list, &ra_list);
list_splice_tail_init(&ra_list, &done_list);
items_queued = 0;
}
break;
default:
ASSERT(0);
}
if (error)
goto out;
}
out:
if (!list_empty(&ra_list)) {
if (!error)
error = xlog_recover_items_pass2(log, trans,
&buffer_list, &ra_list);
list_splice_tail_init(&ra_list, &done_list);
}
if (!list_empty(&done_list))
list_splice_init(&done_list, &trans->r_itemq);
error2 = xfs_buf_delwri_submit(&buffer_list);
return error ? error : error2;
}
STATIC void
xlog_recover_add_item(
struct list_head *head)
{
xlog_recover_item_t *item;
item = kmem_zalloc(sizeof(xlog_recover_item_t), KM_SLEEP);
INIT_LIST_HEAD(&item->ri_list);
list_add_tail(&item->ri_list, head);
}
STATIC int
xlog_recover_add_to_cont_trans(
struct xlog *log,
struct xlog_recover *trans,
char *dp,
int len)
{
xlog_recover_item_t *item;
char *ptr, *old_ptr;
int old_len;
if (list_empty(&trans->r_itemq)) {
xlog_recover_add_item(&trans->r_itemq);
ptr = (char *)&trans->r_theader +
sizeof(xfs_trans_header_t) - len;
memcpy(ptr, dp, len);
return 0;
}
item = list_entry(trans->r_itemq.prev, xlog_recover_item_t, ri_list);
old_ptr = item->ri_buf[item->ri_cnt-1].i_addr;
old_len = item->ri_buf[item->ri_cnt-1].i_len;
ptr = kmem_realloc(old_ptr, len+old_len, old_len, KM_SLEEP);
memcpy(&ptr[old_len], dp, len);
item->ri_buf[item->ri_cnt-1].i_len += len;
item->ri_buf[item->ri_cnt-1].i_addr = ptr;
trace_xfs_log_recover_item_add_cont(log, trans, item, 0);
return 0;
}
STATIC int
xlog_recover_add_to_trans(
struct xlog *log,
struct xlog_recover *trans,
char *dp,
int len)
{
xfs_inode_log_format_t *in_f;
xlog_recover_item_t *item;
char *ptr;
if (!len)
return 0;
if (list_empty(&trans->r_itemq)) {
if (*(uint *)dp != XFS_TRANS_HEADER_MAGIC) {
xfs_warn(log->l_mp, "%s: bad header magic number",
__func__);
ASSERT(0);
return -EIO;
}
if (len == sizeof(xfs_trans_header_t))
xlog_recover_add_item(&trans->r_itemq);
memcpy(&trans->r_theader, dp, len);
return 0;
}
ptr = kmem_alloc(len, KM_SLEEP);
memcpy(ptr, dp, len);
in_f = (xfs_inode_log_format_t *)ptr;
item = list_entry(trans->r_itemq.prev, xlog_recover_item_t, ri_list);
if (item->ri_total != 0 &&
item->ri_total == item->ri_cnt) {
xlog_recover_add_item(&trans->r_itemq);
item = list_entry(trans->r_itemq.prev,
xlog_recover_item_t, ri_list);
}
if (item->ri_total == 0) {
if (in_f->ilf_size == 0 ||
in_f->ilf_size > XLOG_MAX_REGIONS_IN_ITEM) {
xfs_warn(log->l_mp,
"bad number of regions (%d) in inode log format",
in_f->ilf_size);
ASSERT(0);
kmem_free(ptr);
return -EIO;
}
item->ri_total = in_f->ilf_size;
item->ri_buf =
kmem_zalloc(item->ri_total * sizeof(xfs_log_iovec_t),
KM_SLEEP);
}
ASSERT(item->ri_total > item->ri_cnt);
item->ri_buf[item->ri_cnt].i_addr = ptr;
item->ri_buf[item->ri_cnt].i_len = len;
item->ri_cnt++;
trace_xfs_log_recover_item_add(log, trans, item, 0);
return 0;
}
STATIC void
xlog_recover_free_trans(
struct xlog_recover *trans)
{
xlog_recover_item_t *item, *n;
int i;
list_for_each_entry_safe(item, n, &trans->r_itemq, ri_list) {
list_del(&item->ri_list);
for (i = 0; i < item->ri_cnt; i++)
kmem_free(item->ri_buf[i].i_addr);
kmem_free(item->ri_buf);
kmem_free(item);
}
kmem_free(trans);
}
STATIC int
xlog_recovery_process_trans(
struct xlog *log,
struct xlog_recover *trans,
char *dp,
unsigned int len,
unsigned int flags,
int pass)
{
int error = 0;
bool freeit = false;
flags &= ~XLOG_END_TRANS;
if (flags & XLOG_WAS_CONT_TRANS)
flags &= ~XLOG_CONTINUE_TRANS;
switch (flags) {
case 0:
case XLOG_CONTINUE_TRANS:
error = xlog_recover_add_to_trans(log, trans, dp, len);
break;
case XLOG_WAS_CONT_TRANS:
error = xlog_recover_add_to_cont_trans(log, trans, dp, len);
break;
case XLOG_COMMIT_TRANS:
error = xlog_recover_commit_trans(log, trans, pass);
freeit = true;
break;
case XLOG_UNMOUNT_TRANS:
xfs_warn(log->l_mp, "%s: Unmount LR", __func__);
freeit = true;
break;
case XLOG_START_TRANS:
default:
xfs_warn(log->l_mp, "%s: bad flag 0x%x", __func__, flags);
ASSERT(0);
error = -EIO;
break;
}
if (error || freeit)
xlog_recover_free_trans(trans);
return error;
}
STATIC struct xlog_recover *
xlog_recover_ophdr_to_trans(
struct hlist_head rhash[],
struct xlog_rec_header *rhead,
struct xlog_op_header *ohead)
{
struct xlog_recover *trans;
xlog_tid_t tid;
struct hlist_head *rhp;
tid = be32_to_cpu(ohead->oh_tid);
rhp = &rhash[XLOG_RHASH(tid)];
hlist_for_each_entry(trans, rhp, r_list) {
if (trans->r_log_tid == tid)
return trans;
}
if (!(ohead->oh_flags & XLOG_START_TRANS))
return NULL;
ASSERT(be32_to_cpu(ohead->oh_len) == 0);
trans = kmem_zalloc(sizeof(struct xlog_recover), KM_SLEEP);
trans->r_log_tid = tid;
trans->r_lsn = be64_to_cpu(rhead->h_lsn);
INIT_LIST_HEAD(&trans->r_itemq);
INIT_HLIST_NODE(&trans->r_list);
hlist_add_head(&trans->r_list, rhp);
return NULL;
}
STATIC int
xlog_recover_process_ophdr(
struct xlog *log,
struct hlist_head rhash[],
struct xlog_rec_header *rhead,
struct xlog_op_header *ohead,
char *dp,
char *end,
int pass)
{
struct xlog_recover *trans;
unsigned int len;
if (ohead->oh_clientid != XFS_TRANSACTION &&
ohead->oh_clientid != XFS_LOG) {
xfs_warn(log->l_mp, "%s: bad clientid 0x%x",
__func__, ohead->oh_clientid);
ASSERT(0);
return -EIO;
}
len = be32_to_cpu(ohead->oh_len);
if (dp + len > end) {
xfs_warn(log->l_mp, "%s: bad length 0x%x", __func__, len);
WARN_ON(1);
return -EIO;
}
trans = xlog_recover_ophdr_to_trans(rhash, rhead, ohead);
if (!trans) {
return 0;
}
return xlog_recovery_process_trans(log, trans, dp, len,
ohead->oh_flags, pass);
}
STATIC int
xlog_recover_process_data(
struct xlog *log,
struct hlist_head rhash[],
struct xlog_rec_header *rhead,
char *dp,
int pass)
{
struct xlog_op_header *ohead;
char *end;
int num_logops;
int error;
end = dp + be32_to_cpu(rhead->h_len);
num_logops = be32_to_cpu(rhead->h_num_logops);
if (xlog_header_check_recover(log->l_mp, rhead))
return -EIO;
while ((dp < end) && num_logops) {
ohead = (struct xlog_op_header *)dp;
dp += sizeof(*ohead);
ASSERT(dp <= end);
error = xlog_recover_process_ophdr(log, rhash, rhead, ohead,
dp, end, pass);
if (error)
return error;
dp += be32_to_cpu(ohead->oh_len);
num_logops--;
}
return 0;
}
STATIC int
xlog_recover_process_efi(
xfs_mount_t *mp,
xfs_efi_log_item_t *efip)
{
xfs_efd_log_item_t *efdp;
xfs_trans_t *tp;
int i;
int error = 0;
xfs_extent_t *extp;
xfs_fsblock_t startblock_fsb;
ASSERT(!test_bit(XFS_EFI_RECOVERED, &efip->efi_flags));
for (i = 0; i < efip->efi_format.efi_nextents; i++) {
extp = &(efip->efi_format.efi_extents[i]);
startblock_fsb = XFS_BB_TO_FSB(mp,
XFS_FSB_TO_DADDR(mp, extp->ext_start));
if ((startblock_fsb == 0) ||
(extp->ext_len == 0) ||
(startblock_fsb >= mp->m_sb.sb_dblocks) ||
(extp->ext_len >= mp->m_sb.sb_agblocks)) {
set_bit(XFS_EFI_RECOVERED, &efip->efi_flags);
xfs_efi_release(efip, efip->efi_format.efi_nextents);
return -EIO;
}
}
tp = xfs_trans_alloc(mp, 0);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_itruncate, 0, 0);
if (error)
goto abort_error;
efdp = xfs_trans_get_efd(tp, efip, efip->efi_format.efi_nextents);
for (i = 0; i < efip->efi_format.efi_nextents; i++) {
extp = &(efip->efi_format.efi_extents[i]);
error = xfs_free_extent(tp, extp->ext_start, extp->ext_len);
if (error)
goto abort_error;
xfs_trans_log_efd_extent(tp, efdp, extp->ext_start,
extp->ext_len);
}
set_bit(XFS_EFI_RECOVERED, &efip->efi_flags);
error = xfs_trans_commit(tp);
return error;
abort_error:
xfs_trans_cancel(tp);
return error;
}
STATIC int
xlog_recover_process_efis(
struct xlog *log)
{
xfs_log_item_t *lip;
xfs_efi_log_item_t *efip;
int error = 0;
struct xfs_ail_cursor cur;
struct xfs_ail *ailp;
ailp = log->l_ailp;
spin_lock(&ailp->xa_lock);
lip = xfs_trans_ail_cursor_first(ailp, &cur, 0);
while (lip != NULL) {
if (lip->li_type != XFS_LI_EFI) {
#ifdef DEBUG
for (; lip; lip = xfs_trans_ail_cursor_next(ailp, &cur))
ASSERT(lip->li_type != XFS_LI_EFI);
#endif
break;
}
efip = (xfs_efi_log_item_t *)lip;
if (test_bit(XFS_EFI_RECOVERED, &efip->efi_flags)) {
lip = xfs_trans_ail_cursor_next(ailp, &cur);
continue;
}
spin_unlock(&ailp->xa_lock);
error = xlog_recover_process_efi(log->l_mp, efip);
spin_lock(&ailp->xa_lock);
if (error)
goto out;
lip = xfs_trans_ail_cursor_next(ailp, &cur);
}
out:
xfs_trans_ail_cursor_done(&cur);
spin_unlock(&ailp->xa_lock);
return error;
}
STATIC void
xlog_recover_clear_agi_bucket(
xfs_mount_t *mp,
xfs_agnumber_t agno,
int bucket)
{
xfs_trans_t *tp;
xfs_agi_t *agi;
xfs_buf_t *agibp;
int offset;
int error;
tp = xfs_trans_alloc(mp, XFS_TRANS_CLEAR_AGI_BUCKET);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_clearagi, 0, 0);
if (error)
goto out_abort;
error = xfs_read_agi(mp, tp, agno, &agibp);
if (error)
goto out_abort;
agi = XFS_BUF_TO_AGI(agibp);
agi->agi_unlinked[bucket] = cpu_to_be32(NULLAGINO);
offset = offsetof(xfs_agi_t, agi_unlinked) +
(sizeof(xfs_agino_t) * bucket);
xfs_trans_log_buf(tp, agibp, offset,
(offset + sizeof(xfs_agino_t) - 1));
error = xfs_trans_commit(tp);
if (error)
goto out_error;
return;
out_abort:
xfs_trans_cancel(tp);
out_error:
xfs_warn(mp, "%s: failed to clear agi %d. Continuing.", __func__, agno);
return;
}
STATIC xfs_agino_t
xlog_recover_process_one_iunlink(
struct xfs_mount *mp,
xfs_agnumber_t agno,
xfs_agino_t agino,
int bucket)
{
struct xfs_buf *ibp;
struct xfs_dinode *dip;
struct xfs_inode *ip;
xfs_ino_t ino;
int error;
ino = XFS_AGINO_TO_INO(mp, agno, agino);
error = xfs_iget(mp, NULL, ino, 0, 0, &ip);
if (error)
goto fail;
error = xfs_imap_to_bp(mp, NULL, &ip->i_imap, &dip, &ibp, 0, 0);
if (error)
goto fail_iput;
ASSERT(ip->i_d.di_nlink == 0);
ASSERT(ip->i_d.di_mode != 0);
agino = be32_to_cpu(dip->di_next_unlinked);
xfs_buf_relse(ibp);
ip->i_d.di_dmevmask = 0;
IRELE(ip);
return agino;
fail_iput:
IRELE(ip);
fail:
xlog_recover_clear_agi_bucket(mp, agno, bucket);
return NULLAGINO;
}
STATIC void
xlog_recover_process_iunlinks(
struct xlog *log)
{
xfs_mount_t *mp;
xfs_agnumber_t agno;
xfs_agi_t *agi;
xfs_buf_t *agibp;
xfs_agino_t agino;
int bucket;
int error;
uint mp_dmevmask;
mp = log->l_mp;
mp_dmevmask = mp->m_dmevmask;
mp->m_dmevmask = 0;
for (agno = 0; agno < mp->m_sb.sb_agcount; agno++) {
error = xfs_read_agi(mp, NULL, agno, &agibp);
if (error) {
continue;
}
agi = XFS_BUF_TO_AGI(agibp);
xfs_buf_unlock(agibp);
for (bucket = 0; bucket < XFS_AGI_UNLINKED_BUCKETS; bucket++) {
agino = be32_to_cpu(agi->agi_unlinked[bucket]);
while (agino != NULLAGINO) {
agino = xlog_recover_process_one_iunlink(mp,
agno, agino, bucket);
}
}
xfs_buf_rele(agibp);
}
mp->m_dmevmask = mp_dmevmask;
}
STATIC int
xlog_unpack_data_crc(
struct xlog_rec_header *rhead,
char *dp,
struct xlog *log)
{
__le32 crc;
crc = xlog_cksum(log, rhead, dp, be32_to_cpu(rhead->h_len));
if (crc != rhead->h_crc) {
if (rhead->h_crc || xfs_sb_version_hascrc(&log->l_mp->m_sb)) {
xfs_alert(log->l_mp,
"log record CRC mismatch: found 0x%x, expected 0x%x.",
le32_to_cpu(rhead->h_crc),
le32_to_cpu(crc));
xfs_hex_dump(dp, 32);
}
if (xfs_sb_version_hascrc(&log->l_mp->m_sb))
return -EFSCORRUPTED;
}
return 0;
}
STATIC int
xlog_unpack_data(
struct xlog_rec_header *rhead,
char *dp,
struct xlog *log)
{
int i, j, k;
int error;
error = xlog_unpack_data_crc(rhead, dp, log);
if (error)
return error;
for (i = 0; i < BTOBB(be32_to_cpu(rhead->h_len)) &&
i < (XLOG_HEADER_CYCLE_SIZE / BBSIZE); i++) {
*(__be32 *)dp = *(__be32 *)&rhead->h_cycle_data[i];
dp += BBSIZE;
}
if (xfs_sb_version_haslogv2(&log->l_mp->m_sb)) {
xlog_in_core_2_t *xhdr = (xlog_in_core_2_t *)rhead;
for ( ; i < BTOBB(be32_to_cpu(rhead->h_len)); i++) {
j = i / (XLOG_HEADER_CYCLE_SIZE / BBSIZE);
k = i % (XLOG_HEADER_CYCLE_SIZE / BBSIZE);
*(__be32 *)dp = xhdr[j].hic_xheader.xh_cycle_data[k];
dp += BBSIZE;
}
}
return 0;
}
STATIC int
xlog_valid_rec_header(
struct xlog *log,
struct xlog_rec_header *rhead,
xfs_daddr_t blkno)
{
int hlen;
if (unlikely(rhead->h_magicno != cpu_to_be32(XLOG_HEADER_MAGIC_NUM))) {
XFS_ERROR_REPORT("xlog_valid_rec_header(1)",
XFS_ERRLEVEL_LOW, log->l_mp);
return -EFSCORRUPTED;
}
if (unlikely(
(!rhead->h_version ||
(be32_to_cpu(rhead->h_version) & (~XLOG_VERSION_OKBITS))))) {
xfs_warn(log->l_mp, "%s: unrecognised log version (%d).",
__func__, be32_to_cpu(rhead->h_version));
return -EIO;
}
hlen = be32_to_cpu(rhead->h_len);
if (unlikely( hlen <= 0 || hlen > INT_MAX )) {
XFS_ERROR_REPORT("xlog_valid_rec_header(2)",
XFS_ERRLEVEL_LOW, log->l_mp);
return -EFSCORRUPTED;
}
if (unlikely( blkno > log->l_logBBsize || blkno > INT_MAX )) {
XFS_ERROR_REPORT("xlog_valid_rec_header(3)",
XFS_ERRLEVEL_LOW, log->l_mp);
return -EFSCORRUPTED;
}
return 0;
}
STATIC int
xlog_do_recovery_pass(
struct xlog *log,
xfs_daddr_t head_blk,
xfs_daddr_t tail_blk,
int pass)
{
xlog_rec_header_t *rhead;
xfs_daddr_t blk_no;
char *offset;
xfs_buf_t *hbp, *dbp;
int error = 0, h_size;
int bblks, split_bblks;
int hblks, split_hblks, wrapped_hblks;
struct hlist_head rhash[XLOG_RHASH_SIZE];
ASSERT(head_blk != tail_blk);
if (xfs_sb_version_haslogv2(&log->l_mp->m_sb)) {
hbp = xlog_get_bp(log, 1);
if (!hbp)
return -ENOMEM;
error = xlog_bread(log, tail_blk, 1, hbp, &offset);
if (error)
goto bread_err1;
rhead = (xlog_rec_header_t *)offset;
error = xlog_valid_rec_header(log, rhead, tail_blk);
if (error)
goto bread_err1;
h_size = be32_to_cpu(rhead->h_size);
if ((be32_to_cpu(rhead->h_version) & XLOG_VERSION_2) &&
(h_size > XLOG_HEADER_CYCLE_SIZE)) {
hblks = h_size / XLOG_HEADER_CYCLE_SIZE;
if (h_size % XLOG_HEADER_CYCLE_SIZE)
hblks++;
xlog_put_bp(hbp);
hbp = xlog_get_bp(log, hblks);
} else {
hblks = 1;
}
} else {
ASSERT(log->l_sectBBsize == 1);
hblks = 1;
hbp = xlog_get_bp(log, 1);
h_size = XLOG_BIG_RECORD_BSIZE;
}
if (!hbp)
return -ENOMEM;
dbp = xlog_get_bp(log, BTOBB(h_size));
if (!dbp) {
xlog_put_bp(hbp);
return -ENOMEM;
}
memset(rhash, 0, sizeof(rhash));
blk_no = tail_blk;
if (tail_blk > head_blk) {
while (blk_no < log->l_logBBsize) {
offset = hbp->b_addr;
split_hblks = 0;
wrapped_hblks = 0;
if (blk_no + hblks <= log->l_logBBsize) {
error = xlog_bread(log, blk_no, hblks, hbp,
&offset);
if (error)
goto bread_err2;
} else {
if (blk_no != log->l_logBBsize) {
ASSERT(blk_no <= INT_MAX);
split_hblks = log->l_logBBsize - (int)blk_no;
ASSERT(split_hblks > 0);
error = xlog_bread(log, blk_no,
split_hblks, hbp,
&offset);
if (error)
goto bread_err2;
}
wrapped_hblks = hblks - split_hblks;
error = xlog_bread_offset(log, 0,
wrapped_hblks, hbp,
offset + BBTOB(split_hblks));
if (error)
goto bread_err2;
}
rhead = (xlog_rec_header_t *)offset;
error = xlog_valid_rec_header(log, rhead,
split_hblks ? blk_no : 0);
if (error)
goto bread_err2;
bblks = (int)BTOBB(be32_to_cpu(rhead->h_len));
blk_no += hblks;
if (blk_no + bblks <= log->l_logBBsize) {
error = xlog_bread(log, blk_no, bblks, dbp,
&offset);
if (error)
goto bread_err2;
} else {
offset = dbp->b_addr;
split_bblks = 0;
if (blk_no != log->l_logBBsize) {
ASSERT(!wrapped_hblks);
ASSERT(blk_no <= INT_MAX);
split_bblks =
log->l_logBBsize - (int)blk_no;
ASSERT(split_bblks > 0);
error = xlog_bread(log, blk_no,
split_bblks, dbp,
&offset);
if (error)
goto bread_err2;
}
error = xlog_bread_offset(log, 0,
bblks - split_bblks, dbp,
offset + BBTOB(split_bblks));
if (error)
goto bread_err2;
}
error = xlog_unpack_data(rhead, offset, log);
if (error)
goto bread_err2;
error = xlog_recover_process_data(log, rhash,
rhead, offset, pass);
if (error)
goto bread_err2;
blk_no += bblks;
}
ASSERT(blk_no >= log->l_logBBsize);
blk_no -= log->l_logBBsize;
}
while (blk_no < head_blk) {
error = xlog_bread(log, blk_no, hblks, hbp, &offset);
if (error)
goto bread_err2;
rhead = (xlog_rec_header_t *)offset;
error = xlog_valid_rec_header(log, rhead, blk_no);
if (error)
goto bread_err2;
bblks = (int)BTOBB(be32_to_cpu(rhead->h_len));
error = xlog_bread(log, blk_no+hblks, bblks, dbp,
&offset);
if (error)
goto bread_err2;
error = xlog_unpack_data(rhead, offset, log);
if (error)
goto bread_err2;
error = xlog_recover_process_data(log, rhash,
rhead, offset, pass);
if (error)
goto bread_err2;
blk_no += bblks + hblks;
}
bread_err2:
xlog_put_bp(dbp);
bread_err1:
xlog_put_bp(hbp);
return error;
}
STATIC int
xlog_do_log_recovery(
struct xlog *log,
xfs_daddr_t head_blk,
xfs_daddr_t tail_blk)
{
int error, i;
ASSERT(head_blk != tail_blk);
log->l_buf_cancel_table = kmem_zalloc(XLOG_BC_TABLE_SIZE *
sizeof(struct list_head),
KM_SLEEP);
for (i = 0; i < XLOG_BC_TABLE_SIZE; i++)
INIT_LIST_HEAD(&log->l_buf_cancel_table[i]);
error = xlog_do_recovery_pass(log, head_blk, tail_blk,
XLOG_RECOVER_PASS1);
if (error != 0) {
kmem_free(log->l_buf_cancel_table);
log->l_buf_cancel_table = NULL;
return error;
}
error = xlog_do_recovery_pass(log, head_blk, tail_blk,
XLOG_RECOVER_PASS2);
#ifdef DEBUG
if (!error) {
int i;
for (i = 0; i < XLOG_BC_TABLE_SIZE; i++)
ASSERT(list_empty(&log->l_buf_cancel_table[i]));
}
#endif
kmem_free(log->l_buf_cancel_table);
log->l_buf_cancel_table = NULL;
return error;
}
STATIC int
xlog_do_recover(
struct xlog *log,
xfs_daddr_t head_blk,
xfs_daddr_t tail_blk)
{
int error;
xfs_buf_t *bp;
xfs_sb_t *sbp;
error = xlog_do_log_recovery(log, head_blk, tail_blk);
if (error)
return error;
if (XFS_FORCED_SHUTDOWN(log->l_mp)) {
return -EIO;
}
xlog_assign_tail_lsn(log->l_mp);
bp = xfs_getsb(log->l_mp, 0);
XFS_BUF_UNDONE(bp);
ASSERT(!(XFS_BUF_ISWRITE(bp)));
XFS_BUF_READ(bp);
XFS_BUF_UNASYNC(bp);
bp->b_ops = &xfs_sb_buf_ops;
error = xfs_buf_submit_wait(bp);
if (error) {
if (!XFS_FORCED_SHUTDOWN(log->l_mp)) {
xfs_buf_ioerror_alert(bp, __func__);
ASSERT(0);
}
xfs_buf_relse(bp);
return error;
}
sbp = &log->l_mp->m_sb;
xfs_sb_from_disk(sbp, XFS_BUF_TO_SBP(bp));
ASSERT(sbp->sb_magicnum == XFS_SB_MAGIC);
ASSERT(xfs_sb_good_version(sbp));
xfs_reinit_percpu_counters(log->l_mp);
xfs_buf_relse(bp);
xlog_recover_check_summary(log);
log->l_flags &= ~XLOG_ACTIVE_RECOVERY;
return 0;
}
int
xlog_recover(
struct xlog *log)
{
xfs_daddr_t head_blk, tail_blk;
int error;
if ((error = xlog_find_tail(log, &head_blk, &tail_blk)))
return error;
if (tail_blk != head_blk) {
if ((error = xfs_dev_is_read_only(log->l_mp, "recovery"))) {
return error;
}
if (XFS_SB_VERSION_NUM(&log->l_mp->m_sb) == XFS_SB_VERSION_5 &&
xfs_sb_has_incompat_log_feature(&log->l_mp->m_sb,
XFS_SB_FEAT_INCOMPAT_LOG_UNKNOWN)) {
xfs_warn(log->l_mp,
"Superblock has unknown incompatible log features (0x%x) enabled.\n"
"The log can not be fully and/or safely recovered by this kernel.\n"
"Please recover the log on a kernel that supports the unknown features.",
(log->l_mp->m_sb.sb_features_log_incompat &
XFS_SB_FEAT_INCOMPAT_LOG_UNKNOWN));
return -EINVAL;
}
if (xfs_globals.log_recovery_delay) {
xfs_notice(log->l_mp,
"Delaying log recovery for %d seconds.",
xfs_globals.log_recovery_delay);
msleep(xfs_globals.log_recovery_delay * 1000);
}
xfs_notice(log->l_mp, "Starting recovery (logdev: %s)",
log->l_mp->m_logname ? log->l_mp->m_logname
: "internal");
error = xlog_do_recover(log, head_blk, tail_blk);
log->l_flags |= XLOG_RECOVERY_NEEDED;
}
return error;
}
int
xlog_recover_finish(
struct xlog *log)
{
if (log->l_flags & XLOG_RECOVERY_NEEDED) {
int error;
error = xlog_recover_process_efis(log);
if (error) {
xfs_alert(log->l_mp, "Failed to recover EFIs");
return error;
}
xfs_log_force(log->l_mp, XFS_LOG_SYNC);
xlog_recover_process_iunlinks(log);
xlog_recover_check_summary(log);
xfs_notice(log->l_mp, "Ending recovery (logdev: %s)",
log->l_mp->m_logname ? log->l_mp->m_logname
: "internal");
log->l_flags &= ~XLOG_RECOVERY_NEEDED;
} else {
xfs_info(log->l_mp, "Ending clean mount");
}
return 0;
}
void
xlog_recover_check_summary(
struct xlog *log)
{
xfs_mount_t *mp;
xfs_agf_t *agfp;
xfs_buf_t *agfbp;
xfs_buf_t *agibp;
xfs_agnumber_t agno;
__uint64_t freeblks;
__uint64_t itotal;
__uint64_t ifree;
int error;
mp = log->l_mp;
freeblks = 0LL;
itotal = 0LL;
ifree = 0LL;
for (agno = 0; agno < mp->m_sb.sb_agcount; agno++) {
error = xfs_read_agf(mp, NULL, agno, 0, &agfbp);
if (error) {
xfs_alert(mp, "%s agf read failed agno %d error %d",
__func__, agno, error);
} else {
agfp = XFS_BUF_TO_AGF(agfbp);
freeblks += be32_to_cpu(agfp->agf_freeblks) +
be32_to_cpu(agfp->agf_flcount);
xfs_buf_relse(agfbp);
}
error = xfs_read_agi(mp, NULL, agno, &agibp);
if (error) {
xfs_alert(mp, "%s agi read failed agno %d error %d",
__func__, agno, error);
} else {
struct xfs_agi *agi = XFS_BUF_TO_AGI(agibp);
itotal += be32_to_cpu(agi->agi_count);
ifree += be32_to_cpu(agi->agi_freecount);
xfs_buf_relse(agibp);
}
}
}
