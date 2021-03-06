static void ocfs2_global_disk2memdqb(struct dquot *dquot, void *dp)
{
struct ocfs2_global_disk_dqblk *d = dp;
struct mem_dqblk *m = &dquot->dq_dqb;
if (!test_bit(DQ_LASTSET_B + QIF_ILIMITS_B, &dquot->dq_flags)) {
m->dqb_ihardlimit = le64_to_cpu(d->dqb_ihardlimit);
m->dqb_isoftlimit = le64_to_cpu(d->dqb_isoftlimit);
}
if (!test_bit(DQ_LASTSET_B + QIF_INODES_B, &dquot->dq_flags))
m->dqb_curinodes = le64_to_cpu(d->dqb_curinodes);
if (!test_bit(DQ_LASTSET_B + QIF_BLIMITS_B, &dquot->dq_flags)) {
m->dqb_bhardlimit = le64_to_cpu(d->dqb_bhardlimit);
m->dqb_bsoftlimit = le64_to_cpu(d->dqb_bsoftlimit);
}
if (!test_bit(DQ_LASTSET_B + QIF_SPACE_B, &dquot->dq_flags))
m->dqb_curspace = le64_to_cpu(d->dqb_curspace);
if (!test_bit(DQ_LASTSET_B + QIF_BTIME_B, &dquot->dq_flags))
m->dqb_btime = le64_to_cpu(d->dqb_btime);
if (!test_bit(DQ_LASTSET_B + QIF_ITIME_B, &dquot->dq_flags))
m->dqb_itime = le64_to_cpu(d->dqb_itime);
OCFS2_DQUOT(dquot)->dq_use_count = le32_to_cpu(d->dqb_use_count);
}
static void ocfs2_global_mem2diskdqb(void *dp, struct dquot *dquot)
{
struct ocfs2_global_disk_dqblk *d = dp;
struct mem_dqblk *m = &dquot->dq_dqb;
d->dqb_id = cpu_to_le32(from_kqid(&init_user_ns, dquot->dq_id));
d->dqb_use_count = cpu_to_le32(OCFS2_DQUOT(dquot)->dq_use_count);
d->dqb_ihardlimit = cpu_to_le64(m->dqb_ihardlimit);
d->dqb_isoftlimit = cpu_to_le64(m->dqb_isoftlimit);
d->dqb_curinodes = cpu_to_le64(m->dqb_curinodes);
d->dqb_bhardlimit = cpu_to_le64(m->dqb_bhardlimit);
d->dqb_bsoftlimit = cpu_to_le64(m->dqb_bsoftlimit);
d->dqb_curspace = cpu_to_le64(m->dqb_curspace);
d->dqb_btime = cpu_to_le64(m->dqb_btime);
d->dqb_itime = cpu_to_le64(m->dqb_itime);
d->dqb_pad1 = d->dqb_pad2 = 0;
}
static int ocfs2_global_is_id(void *dp, struct dquot *dquot)
{
struct ocfs2_global_disk_dqblk *d = dp;
struct ocfs2_mem_dqinfo *oinfo =
sb_dqinfo(dquot->dq_sb, dquot->dq_id.type)->dqi_priv;
if (qtree_entry_unused(&oinfo->dqi_gi, dp))
return 0;
return qid_eq(make_kqid(&init_user_ns, dquot->dq_id.type,
le32_to_cpu(d->dqb_id)),
dquot->dq_id);
}
int ocfs2_validate_quota_block(struct super_block *sb, struct buffer_head *bh)
{
struct ocfs2_disk_dqtrailer *dqt =
ocfs2_block_dqtrailer(sb->s_blocksize, bh->b_data);
trace_ocfs2_validate_quota_block((unsigned long long)bh->b_blocknr);
BUG_ON(!buffer_uptodate(bh));
return ocfs2_validate_meta_ecc(sb, bh->b_data, &dqt->dq_check);
}
int ocfs2_read_quota_phys_block(struct inode *inode, u64 p_block,
struct buffer_head **bhp)
{
int rc;
*bhp = NULL;
rc = ocfs2_read_blocks(INODE_CACHE(inode), p_block, 1, bhp, 0,
ocfs2_validate_quota_block);
if (rc)
mlog_errno(rc);
return rc;
}
ssize_t ocfs2_quota_read(struct super_block *sb, int type, char *data,
size_t len, loff_t off)
{
struct ocfs2_mem_dqinfo *oinfo = sb_dqinfo(sb, type)->dqi_priv;
struct inode *gqinode = oinfo->dqi_gqinode;
loff_t i_size = i_size_read(gqinode);
int offset = off & (sb->s_blocksize - 1);
sector_t blk = off >> sb->s_blocksize_bits;
int err = 0;
struct buffer_head *bh;
size_t toread, tocopy;
u64 pblock = 0, pcount = 0;
if (off > i_size)
return 0;
if (off + len > i_size)
len = i_size - off;
toread = len;
while (toread > 0) {
tocopy = min_t(size_t, (sb->s_blocksize - offset), toread);
if (!pcount) {
err = ocfs2_extent_map_get_blocks(gqinode, blk, &pblock,
&pcount, NULL);
if (err) {
mlog_errno(err);
return err;
}
} else {
pcount--;
pblock++;
}
bh = NULL;
err = ocfs2_read_quota_phys_block(gqinode, pblock, &bh);
if (err) {
mlog_errno(err);
return err;
}
memcpy(data, bh->b_data + offset, tocopy);
brelse(bh);
offset = 0;
toread -= tocopy;
data += tocopy;
blk++;
}
return len;
}
ssize_t ocfs2_quota_write(struct super_block *sb, int type,
const char *data, size_t len, loff_t off)
{
struct mem_dqinfo *info = sb_dqinfo(sb, type);
struct ocfs2_mem_dqinfo *oinfo = info->dqi_priv;
struct inode *gqinode = oinfo->dqi_gqinode;
int offset = off & (sb->s_blocksize - 1);
sector_t blk = off >> sb->s_blocksize_bits;
int err = 0, new = 0, ja_type;
struct buffer_head *bh = NULL;
handle_t *handle = journal_current_handle();
u64 pblock, pcount;
if (!handle) {
mlog(ML_ERROR, "Quota write (off=%llu, len=%llu) cancelled "
"because transaction was not started.\n",
(unsigned long long)off, (unsigned long long)len);
return -EIO;
}
if (len > sb->s_blocksize - OCFS2_QBLK_RESERVED_SPACE - offset) {
WARN_ON(1);
len = sb->s_blocksize - OCFS2_QBLK_RESERVED_SPACE - offset;
}
if (i_size_read(gqinode) < off + len) {
loff_t rounded_end =
ocfs2_align_bytes_to_blocks(sb, off + len);
err = ocfs2_simple_size_update(gqinode,
oinfo->dqi_gqi_bh,
rounded_end);
if (err < 0)
goto out;
new = 1;
}
err = ocfs2_extent_map_get_blocks(gqinode, blk, &pblock, &pcount, NULL);
if (err) {
mlog_errno(err);
goto out;
}
if ((offset || len < sb->s_blocksize - OCFS2_QBLK_RESERVED_SPACE) &&
!new) {
err = ocfs2_read_quota_phys_block(gqinode, pblock, &bh);
ja_type = OCFS2_JOURNAL_ACCESS_WRITE;
} else {
bh = sb_getblk(sb, pblock);
if (!bh)
err = -ENOMEM;
ja_type = OCFS2_JOURNAL_ACCESS_CREATE;
}
if (err) {
mlog_errno(err);
goto out;
}
lock_buffer(bh);
if (new)
memset(bh->b_data, 0, sb->s_blocksize);
memcpy(bh->b_data + offset, data, len);
flush_dcache_page(bh->b_page);
set_buffer_uptodate(bh);
unlock_buffer(bh);
ocfs2_set_buffer_uptodate(INODE_CACHE(gqinode), bh);
err = ocfs2_journal_access_dq(handle, INODE_CACHE(gqinode), bh,
ja_type);
if (err < 0) {
brelse(bh);
goto out;
}
ocfs2_journal_dirty(handle, bh);
brelse(bh);
out:
if (err) {
mlog_errno(err);
return err;
}
gqinode->i_version++;
ocfs2_mark_inode_dirty(handle, gqinode, oinfo->dqi_gqi_bh);
return len;
}
int ocfs2_lock_global_qf(struct ocfs2_mem_dqinfo *oinfo, int ex)
{
int status;
struct buffer_head *bh = NULL;
status = ocfs2_inode_lock(oinfo->dqi_gqinode, &bh, ex);
if (status < 0)
return status;
spin_lock(&dq_data_lock);
if (!oinfo->dqi_gqi_count++)
oinfo->dqi_gqi_bh = bh;
else
WARN_ON(bh != oinfo->dqi_gqi_bh);
spin_unlock(&dq_data_lock);
if (ex) {
inode_lock(oinfo->dqi_gqinode);
down_write(&OCFS2_I(oinfo->dqi_gqinode)->ip_alloc_sem);
} else {
down_read(&OCFS2_I(oinfo->dqi_gqinode)->ip_alloc_sem);
}
return 0;
}
void ocfs2_unlock_global_qf(struct ocfs2_mem_dqinfo *oinfo, int ex)
{
if (ex) {
up_write(&OCFS2_I(oinfo->dqi_gqinode)->ip_alloc_sem);
inode_unlock(oinfo->dqi_gqinode);
} else {
up_read(&OCFS2_I(oinfo->dqi_gqinode)->ip_alloc_sem);
}
ocfs2_inode_unlock(oinfo->dqi_gqinode, ex);
brelse(oinfo->dqi_gqi_bh);
spin_lock(&dq_data_lock);
if (!--oinfo->dqi_gqi_count)
oinfo->dqi_gqi_bh = NULL;
spin_unlock(&dq_data_lock);
}
int ocfs2_global_read_info(struct super_block *sb, int type)
{
struct inode *gqinode = NULL;
unsigned int ino[OCFS2_MAXQUOTAS] = { USER_QUOTA_SYSTEM_INODE,
GROUP_QUOTA_SYSTEM_INODE };
struct ocfs2_global_disk_dqinfo dinfo;
struct mem_dqinfo *info = sb_dqinfo(sb, type);
struct ocfs2_mem_dqinfo *oinfo = info->dqi_priv;
u64 pcount;
int status;
gqinode = ocfs2_get_system_file_inode(OCFS2_SB(sb), ino[type],
OCFS2_INVALID_SLOT);
if (!gqinode) {
mlog(ML_ERROR, "failed to get global quota inode (type=%d)\n",
type);
status = -EINVAL;
goto out_err;
}
oinfo->dqi_gi.dqi_sb = sb;
oinfo->dqi_gi.dqi_type = type;
ocfs2_qinfo_lock_res_init(&oinfo->dqi_gqlock, oinfo);
oinfo->dqi_gi.dqi_entry_size = sizeof(struct ocfs2_global_disk_dqblk);
oinfo->dqi_gi.dqi_ops = &ocfs2_global_ops;
oinfo->dqi_gqi_bh = NULL;
oinfo->dqi_gqi_count = 0;
oinfo->dqi_gqinode = gqinode;
status = ocfs2_lock_global_qf(oinfo, 0);
if (status < 0) {
mlog_errno(status);
goto out_err;
}
status = ocfs2_extent_map_get_blocks(gqinode, 0, &oinfo->dqi_giblk,
&pcount, NULL);
if (status < 0)
goto out_unlock;
status = ocfs2_qinfo_lock(oinfo, 0);
if (status < 0)
goto out_unlock;
status = sb->s_op->quota_read(sb, type, (char *)&dinfo,
sizeof(struct ocfs2_global_disk_dqinfo),
OCFS2_GLOBAL_INFO_OFF);
ocfs2_qinfo_unlock(oinfo, 0);
ocfs2_unlock_global_qf(oinfo, 0);
if (status != sizeof(struct ocfs2_global_disk_dqinfo)) {
mlog(ML_ERROR, "Cannot read global quota info (%d).\n",
status);
if (status >= 0)
status = -EIO;
mlog_errno(status);
goto out_err;
}
info->dqi_bgrace = le32_to_cpu(dinfo.dqi_bgrace);
info->dqi_igrace = le32_to_cpu(dinfo.dqi_igrace);
oinfo->dqi_syncms = le32_to_cpu(dinfo.dqi_syncms);
oinfo->dqi_gi.dqi_blocks = le32_to_cpu(dinfo.dqi_blocks);
oinfo->dqi_gi.dqi_free_blk = le32_to_cpu(dinfo.dqi_free_blk);
oinfo->dqi_gi.dqi_free_entry = le32_to_cpu(dinfo.dqi_free_entry);
oinfo->dqi_gi.dqi_blocksize_bits = sb->s_blocksize_bits;
oinfo->dqi_gi.dqi_usable_bs = sb->s_blocksize -
OCFS2_QBLK_RESERVED_SPACE;
oinfo->dqi_gi.dqi_qtree_depth = qtree_depth(&oinfo->dqi_gi);
INIT_DELAYED_WORK(&oinfo->dqi_sync_work, qsync_work_fn);
schedule_delayed_work(&oinfo->dqi_sync_work,
msecs_to_jiffies(oinfo->dqi_syncms));
out_err:
return status;
out_unlock:
ocfs2_unlock_global_qf(oinfo, 0);
mlog_errno(status);
goto out_err;
}
static int __ocfs2_global_write_info(struct super_block *sb, int type)
{
struct mem_dqinfo *info = sb_dqinfo(sb, type);
struct ocfs2_mem_dqinfo *oinfo = info->dqi_priv;
struct ocfs2_global_disk_dqinfo dinfo;
ssize_t size;
spin_lock(&dq_data_lock);
info->dqi_flags &= ~DQF_INFO_DIRTY;
dinfo.dqi_bgrace = cpu_to_le32(info->dqi_bgrace);
dinfo.dqi_igrace = cpu_to_le32(info->dqi_igrace);
spin_unlock(&dq_data_lock);
dinfo.dqi_syncms = cpu_to_le32(oinfo->dqi_syncms);
dinfo.dqi_blocks = cpu_to_le32(oinfo->dqi_gi.dqi_blocks);
dinfo.dqi_free_blk = cpu_to_le32(oinfo->dqi_gi.dqi_free_blk);
dinfo.dqi_free_entry = cpu_to_le32(oinfo->dqi_gi.dqi_free_entry);
size = sb->s_op->quota_write(sb, type, (char *)&dinfo,
sizeof(struct ocfs2_global_disk_dqinfo),
OCFS2_GLOBAL_INFO_OFF);
if (size != sizeof(struct ocfs2_global_disk_dqinfo)) {
mlog(ML_ERROR, "Cannot write global quota info structure\n");
if (size >= 0)
size = -EIO;
return size;
}
return 0;
}
int ocfs2_global_write_info(struct super_block *sb, int type)
{
int err;
struct ocfs2_mem_dqinfo *info = sb_dqinfo(sb, type)->dqi_priv;
err = ocfs2_qinfo_lock(info, 1);
if (err < 0)
return err;
err = __ocfs2_global_write_info(sb, type);
ocfs2_qinfo_unlock(info, 1);
return err;
}
static int ocfs2_global_qinit_alloc(struct super_block *sb, int type)
{
struct ocfs2_mem_dqinfo *oinfo = sb_dqinfo(sb, type)->dqi_priv;
return oinfo->dqi_gi.dqi_qtree_depth;
}
static int ocfs2_calc_global_qinit_credits(struct super_block *sb, int type)
{
return (ocfs2_global_qinit_alloc(sb, type) + 2) *
OCFS2_QUOTA_BLOCK_UPDATE_CREDITS + 1;
}
int __ocfs2_sync_dquot(struct dquot *dquot, int freeing)
{
int err, err2;
struct super_block *sb = dquot->dq_sb;
int type = dquot->dq_id.type;
struct ocfs2_mem_dqinfo *info = sb_dqinfo(sb, type)->dqi_priv;
struct ocfs2_global_disk_dqblk dqblk;
s64 spacechange, inodechange;
time_t olditime, oldbtime;
err = sb->s_op->quota_read(sb, type, (char *)&dqblk,
sizeof(struct ocfs2_global_disk_dqblk),
dquot->dq_off);
if (err != sizeof(struct ocfs2_global_disk_dqblk)) {
if (err >= 0) {
mlog(ML_ERROR, "Short read from global quota file "
"(%u read)\n", err);
err = -EIO;
}
goto out;
}
spin_lock(&dq_data_lock);
spacechange = dquot->dq_dqb.dqb_curspace -
OCFS2_DQUOT(dquot)->dq_origspace;
inodechange = dquot->dq_dqb.dqb_curinodes -
OCFS2_DQUOT(dquot)->dq_originodes;
olditime = dquot->dq_dqb.dqb_itime;
oldbtime = dquot->dq_dqb.dqb_btime;
ocfs2_global_disk2memdqb(dquot, &dqblk);
trace_ocfs2_sync_dquot(from_kqid(&init_user_ns, dquot->dq_id),
dquot->dq_dqb.dqb_curspace,
(long long)spacechange,
dquot->dq_dqb.dqb_curinodes,
(long long)inodechange);
if (!test_bit(DQ_LASTSET_B + QIF_SPACE_B, &dquot->dq_flags))
dquot->dq_dqb.dqb_curspace += spacechange;
if (!test_bit(DQ_LASTSET_B + QIF_INODES_B, &dquot->dq_flags))
dquot->dq_dqb.dqb_curinodes += inodechange;
if (dquot->dq_dqb.dqb_bsoftlimit &&
dquot->dq_dqb.dqb_curspace > dquot->dq_dqb.dqb_bsoftlimit) {
if (!test_bit(DQ_LASTSET_B + QIF_BTIME_B, &dquot->dq_flags) &&
oldbtime > 0) {
if (dquot->dq_dqb.dqb_btime > 0)
dquot->dq_dqb.dqb_btime =
min(dquot->dq_dqb.dqb_btime, oldbtime);
else
dquot->dq_dqb.dqb_btime = oldbtime;
}
} else {
dquot->dq_dqb.dqb_btime = 0;
clear_bit(DQ_BLKS_B, &dquot->dq_flags);
}
if (dquot->dq_dqb.dqb_isoftlimit &&
dquot->dq_dqb.dqb_curinodes > dquot->dq_dqb.dqb_isoftlimit) {
if (!test_bit(DQ_LASTSET_B + QIF_ITIME_B, &dquot->dq_flags) &&
olditime > 0) {
if (dquot->dq_dqb.dqb_itime > 0)
dquot->dq_dqb.dqb_itime =
min(dquot->dq_dqb.dqb_itime, olditime);
else
dquot->dq_dqb.dqb_itime = olditime;
}
} else {
dquot->dq_dqb.dqb_itime = 0;
clear_bit(DQ_INODES_B, &dquot->dq_flags);
}
__clear_bit(DQ_LASTSET_B + QIF_SPACE_B, &dquot->dq_flags);
__clear_bit(DQ_LASTSET_B + QIF_INODES_B, &dquot->dq_flags);
__clear_bit(DQ_LASTSET_B + QIF_BLIMITS_B, &dquot->dq_flags);
__clear_bit(DQ_LASTSET_B + QIF_ILIMITS_B, &dquot->dq_flags);
__clear_bit(DQ_LASTSET_B + QIF_BTIME_B, &dquot->dq_flags);
__clear_bit(DQ_LASTSET_B + QIF_ITIME_B, &dquot->dq_flags);
OCFS2_DQUOT(dquot)->dq_origspace = dquot->dq_dqb.dqb_curspace;
OCFS2_DQUOT(dquot)->dq_originodes = dquot->dq_dqb.dqb_curinodes;
spin_unlock(&dq_data_lock);
err = ocfs2_qinfo_lock(info, freeing);
if (err < 0) {
mlog(ML_ERROR, "Failed to lock quota info, losing quota write"
" (type=%d, id=%u)\n", dquot->dq_id.type,
(unsigned)from_kqid(&init_user_ns, dquot->dq_id));
goto out;
}
if (freeing)
OCFS2_DQUOT(dquot)->dq_use_count--;
err = qtree_write_dquot(&info->dqi_gi, dquot);
if (err < 0)
goto out_qlock;
if (freeing && !OCFS2_DQUOT(dquot)->dq_use_count) {
err = qtree_release_dquot(&info->dqi_gi, dquot);
if (info_dirty(sb_dqinfo(sb, type))) {
err2 = __ocfs2_global_write_info(sb, type);
if (!err)
err = err2;
}
}
out_qlock:
ocfs2_qinfo_unlock(info, freeing);
out:
if (err < 0)
mlog_errno(err);
return err;
}
static int ocfs2_sync_dquot_helper(struct dquot *dquot, unsigned long type)
{
handle_t *handle;
struct super_block *sb = dquot->dq_sb;
struct ocfs2_mem_dqinfo *oinfo = sb_dqinfo(sb, type)->dqi_priv;
struct ocfs2_super *osb = OCFS2_SB(sb);
int status = 0;
trace_ocfs2_sync_dquot_helper(from_kqid(&init_user_ns, dquot->dq_id),
dquot->dq_id.type,
type, sb->s_id);
if (type != dquot->dq_id.type)
goto out;
status = ocfs2_lock_global_qf(oinfo, 1);
if (status < 0)
goto out;
handle = ocfs2_start_trans(osb, OCFS2_QSYNC_CREDITS);
if (IS_ERR(handle)) {
status = PTR_ERR(handle);
mlog_errno(status);
goto out_ilock;
}
mutex_lock(&sb_dqopt(sb)->dqio_mutex);
status = ocfs2_sync_dquot(dquot);
if (status < 0)
mlog_errno(status);
status = ocfs2_local_write_dquot(dquot);
if (status < 0)
mlog_errno(status);
mutex_unlock(&sb_dqopt(sb)->dqio_mutex);
ocfs2_commit_trans(osb, handle);
out_ilock:
ocfs2_unlock_global_qf(oinfo, 1);
out:
return status;
}
static void qsync_work_fn(struct work_struct *work)
{
struct ocfs2_mem_dqinfo *oinfo = container_of(work,
struct ocfs2_mem_dqinfo,
dqi_sync_work.work);
struct super_block *sb = oinfo->dqi_gqinode->i_sb;
dquot_scan_active(sb, ocfs2_sync_dquot_helper, oinfo->dqi_type);
schedule_delayed_work(&oinfo->dqi_sync_work,
msecs_to_jiffies(oinfo->dqi_syncms));
}
static int ocfs2_write_dquot(struct dquot *dquot)
{
handle_t *handle;
struct ocfs2_super *osb = OCFS2_SB(dquot->dq_sb);
int status = 0;
trace_ocfs2_write_dquot(from_kqid(&init_user_ns, dquot->dq_id),
dquot->dq_id.type);
handle = ocfs2_start_trans(osb, OCFS2_QWRITE_CREDITS);
if (IS_ERR(handle)) {
status = PTR_ERR(handle);
mlog_errno(status);
goto out;
}
mutex_lock(&sb_dqopt(dquot->dq_sb)->dqio_mutex);
status = ocfs2_local_write_dquot(dquot);
mutex_unlock(&sb_dqopt(dquot->dq_sb)->dqio_mutex);
ocfs2_commit_trans(osb, handle);
out:
return status;
}
static int ocfs2_calc_qdel_credits(struct super_block *sb, int type)
{
struct ocfs2_mem_dqinfo *oinfo = sb_dqinfo(sb, type)->dqi_priv;
return (oinfo->dqi_gi.dqi_qtree_depth + 2) *
OCFS2_QUOTA_BLOCK_UPDATE_CREDITS +
OCFS2_QINFO_WRITE_CREDITS +
OCFS2_INODE_UPDATE_CREDITS;
}
void ocfs2_drop_dquot_refs(struct work_struct *work)
{
struct ocfs2_super *osb = container_of(work, struct ocfs2_super,
dquot_drop_work);
struct llist_node *list;
struct ocfs2_dquot *odquot, *next_odquot;
list = llist_del_all(&osb->dquot_drop_list);
llist_for_each_entry_safe(odquot, next_odquot, list, list) {
dqput(&odquot->dq_dquot);
}
}
static int ocfs2_release_dquot(struct dquot *dquot)
{
handle_t *handle;
struct ocfs2_mem_dqinfo *oinfo =
sb_dqinfo(dquot->dq_sb, dquot->dq_id.type)->dqi_priv;
struct ocfs2_super *osb = OCFS2_SB(dquot->dq_sb);
int status = 0;
trace_ocfs2_release_dquot(from_kqid(&init_user_ns, dquot->dq_id),
dquot->dq_id.type);
mutex_lock(&dquot->dq_lock);
if (atomic_read(&dquot->dq_count) > 1)
goto out;
if (current == osb->dc_task) {
dqgrab(dquot);
if (llist_add(&OCFS2_DQUOT(dquot)->list, &osb->dquot_drop_list))
queue_work(osb->ocfs2_wq, &osb->dquot_drop_work);
goto out;
}
status = ocfs2_lock_global_qf(oinfo, 1);
if (status < 0)
goto out;
handle = ocfs2_start_trans(osb,
ocfs2_calc_qdel_credits(dquot->dq_sb, dquot->dq_id.type));
if (IS_ERR(handle)) {
status = PTR_ERR(handle);
mlog_errno(status);
goto out_ilock;
}
status = ocfs2_global_release_dquot(dquot);
if (status < 0) {
mlog_errno(status);
goto out_trans;
}
status = ocfs2_local_release_dquot(handle, dquot);
if (status < 0)
mlog_errno(status);
dquot->dq_off = 0;
clear_bit(DQ_ACTIVE_B, &dquot->dq_flags);
out_trans:
ocfs2_commit_trans(osb, handle);
out_ilock:
ocfs2_unlock_global_qf(oinfo, 1);
out:
mutex_unlock(&dquot->dq_lock);
if (status)
mlog_errno(status);
return status;
}
static int ocfs2_acquire_dquot(struct dquot *dquot)
{
int status = 0, err;
int ex = 0;
struct super_block *sb = dquot->dq_sb;
struct ocfs2_super *osb = OCFS2_SB(sb);
int type = dquot->dq_id.type;
struct ocfs2_mem_dqinfo *info = sb_dqinfo(sb, type)->dqi_priv;
struct inode *gqinode = info->dqi_gqinode;
int need_alloc = ocfs2_global_qinit_alloc(sb, type);
handle_t *handle;
trace_ocfs2_acquire_dquot(from_kqid(&init_user_ns, dquot->dq_id),
type);
mutex_lock(&dquot->dq_lock);
status = ocfs2_lock_global_qf(info, 1);
if (status < 0)
goto out;
status = ocfs2_qinfo_lock(info, 0);
if (status < 0)
goto out_dq;
status = qtree_read_dquot(&info->dqi_gi, dquot);
ocfs2_qinfo_unlock(info, 0);
if (status < 0)
goto out_dq;
OCFS2_DQUOT(dquot)->dq_use_count++;
OCFS2_DQUOT(dquot)->dq_origspace = dquot->dq_dqb.dqb_curspace;
OCFS2_DQUOT(dquot)->dq_originodes = dquot->dq_dqb.dqb_curinodes;
if (!dquot->dq_off) {
ex = 1;
WARN_ON(journal_current_handle());
status = ocfs2_extend_no_holes(gqinode, NULL,
i_size_read(gqinode) + (need_alloc << sb->s_blocksize_bits),
i_size_read(gqinode));
if (status < 0)
goto out_dq;
}
handle = ocfs2_start_trans(osb,
ocfs2_calc_global_qinit_credits(sb, type));
if (IS_ERR(handle)) {
status = PTR_ERR(handle);
goto out_dq;
}
status = ocfs2_qinfo_lock(info, ex);
if (status < 0)
goto out_trans;
status = qtree_write_dquot(&info->dqi_gi, dquot);
if (ex && info_dirty(sb_dqinfo(sb, type))) {
err = __ocfs2_global_write_info(sb, type);
if (!status)
status = err;
}
ocfs2_qinfo_unlock(info, ex);
out_trans:
ocfs2_commit_trans(osb, handle);
out_dq:
ocfs2_unlock_global_qf(info, 1);
if (status < 0)
goto out;
status = ocfs2_create_local_dquot(dquot);
if (status < 0)
goto out;
set_bit(DQ_ACTIVE_B, &dquot->dq_flags);
out:
mutex_unlock(&dquot->dq_lock);
if (status)
mlog_errno(status);
return status;
}
static int ocfs2_get_next_id(struct super_block *sb, struct kqid *qid)
{
int type = qid->type;
struct ocfs2_mem_dqinfo *info = sb_dqinfo(sb, type)->dqi_priv;
int status = 0;
trace_ocfs2_get_next_id(from_kqid(&init_user_ns, *qid), type);
if (!sb_has_quota_loaded(sb, type)) {
status = -ESRCH;
goto out;
}
status = ocfs2_lock_global_qf(info, 0);
if (status < 0)
goto out;
status = ocfs2_qinfo_lock(info, 0);
if (status < 0)
goto out_global;
status = qtree_get_next_id(&info->dqi_gi, qid);
ocfs2_qinfo_unlock(info, 0);
out_global:
ocfs2_unlock_global_qf(info, 0);
out:
if (status && status != -ENOENT && status != -ESRCH)
mlog_errno(status);
return status;
}
static int ocfs2_mark_dquot_dirty(struct dquot *dquot)
{
unsigned long mask = (1 << (DQ_LASTSET_B + QIF_ILIMITS_B)) |
(1 << (DQ_LASTSET_B + QIF_BLIMITS_B)) |
(1 << (DQ_LASTSET_B + QIF_INODES_B)) |
(1 << (DQ_LASTSET_B + QIF_SPACE_B)) |
(1 << (DQ_LASTSET_B + QIF_BTIME_B)) |
(1 << (DQ_LASTSET_B + QIF_ITIME_B));
int sync = 0;
int status;
struct super_block *sb = dquot->dq_sb;
int type = dquot->dq_id.type;
struct ocfs2_mem_dqinfo *oinfo = sb_dqinfo(sb, type)->dqi_priv;
handle_t *handle;
struct ocfs2_super *osb = OCFS2_SB(sb);
trace_ocfs2_mark_dquot_dirty(from_kqid(&init_user_ns, dquot->dq_id),
type);
spin_lock(&dq_data_lock);
if (dquot->dq_flags & mask)
sync = 1;
spin_unlock(&dq_data_lock);
if (!sync || journal_current_handle()) {
status = ocfs2_write_dquot(dquot);
goto out;
}
status = ocfs2_lock_global_qf(oinfo, 1);
if (status < 0)
goto out;
handle = ocfs2_start_trans(osb, OCFS2_QSYNC_CREDITS);
if (IS_ERR(handle)) {
status = PTR_ERR(handle);
mlog_errno(status);
goto out_ilock;
}
mutex_lock(&sb_dqopt(sb)->dqio_mutex);
status = ocfs2_sync_dquot(dquot);
if (status < 0) {
mlog_errno(status);
goto out_dlock;
}
status = ocfs2_local_write_dquot(dquot);
out_dlock:
mutex_unlock(&sb_dqopt(sb)->dqio_mutex);
ocfs2_commit_trans(osb, handle);
out_ilock:
ocfs2_unlock_global_qf(oinfo, 1);
out:
if (status)
mlog_errno(status);
return status;
}
static int ocfs2_write_info(struct super_block *sb, int type)
{
handle_t *handle;
int status = 0;
struct ocfs2_mem_dqinfo *oinfo = sb_dqinfo(sb, type)->dqi_priv;
status = ocfs2_lock_global_qf(oinfo, 1);
if (status < 0)
goto out;
handle = ocfs2_start_trans(OCFS2_SB(sb), OCFS2_QINFO_WRITE_CREDITS);
if (IS_ERR(handle)) {
status = PTR_ERR(handle);
mlog_errno(status);
goto out_ilock;
}
status = dquot_commit_info(sb, type);
ocfs2_commit_trans(OCFS2_SB(sb), handle);
out_ilock:
ocfs2_unlock_global_qf(oinfo, 1);
out:
if (status)
mlog_errno(status);
return status;
}
static struct dquot *ocfs2_alloc_dquot(struct super_block *sb, int type)
{
struct ocfs2_dquot *dquot =
kmem_cache_zalloc(ocfs2_dquot_cachep, GFP_NOFS);
if (!dquot)
return NULL;
return &dquot->dq_dquot;
}
static void ocfs2_destroy_dquot(struct dquot *dquot)
{
kmem_cache_free(ocfs2_dquot_cachep, dquot);
}
