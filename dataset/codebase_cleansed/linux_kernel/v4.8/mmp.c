static __le32 ext4_mmp_csum(struct super_block *sb, struct mmp_struct *mmp)
{
struct ext4_sb_info *sbi = EXT4_SB(sb);
int offset = offsetof(struct mmp_struct, mmp_checksum);
__u32 csum;
csum = ext4_chksum(sbi, sbi->s_csum_seed, (char *)mmp, offset);
return cpu_to_le32(csum);
}
static int ext4_mmp_csum_verify(struct super_block *sb, struct mmp_struct *mmp)
{
if (!ext4_has_metadata_csum(sb))
return 1;
return mmp->mmp_checksum == ext4_mmp_csum(sb, mmp);
}
static void ext4_mmp_csum_set(struct super_block *sb, struct mmp_struct *mmp)
{
if (!ext4_has_metadata_csum(sb))
return;
mmp->mmp_checksum = ext4_mmp_csum(sb, mmp);
}
static int write_mmp_block(struct super_block *sb, struct buffer_head *bh)
{
struct mmp_struct *mmp = (struct mmp_struct *)(bh->b_data);
sb_start_write(sb);
ext4_mmp_csum_set(sb, mmp);
mark_buffer_dirty(bh);
lock_buffer(bh);
bh->b_end_io = end_buffer_write_sync;
get_bh(bh);
submit_bh(REQ_OP_WRITE, WRITE_SYNC | REQ_META | REQ_PRIO, bh);
wait_on_buffer(bh);
sb_end_write(sb);
if (unlikely(!buffer_uptodate(bh)))
return 1;
return 0;
}
static int read_mmp_block(struct super_block *sb, struct buffer_head **bh,
ext4_fsblk_t mmp_block)
{
struct mmp_struct *mmp;
int ret;
if (*bh)
clear_buffer_uptodate(*bh);
if (!*bh) {
*bh = sb_getblk(sb, mmp_block);
if (!*bh) {
ret = -ENOMEM;
goto warn_exit;
}
}
get_bh(*bh);
lock_buffer(*bh);
(*bh)->b_end_io = end_buffer_read_sync;
submit_bh(REQ_OP_READ, READ_SYNC | REQ_META | REQ_PRIO, *bh);
wait_on_buffer(*bh);
if (!buffer_uptodate(*bh)) {
ret = -EIO;
goto warn_exit;
}
mmp = (struct mmp_struct *)((*bh)->b_data);
if (le32_to_cpu(mmp->mmp_magic) != EXT4_MMP_MAGIC) {
ret = -EFSCORRUPTED;
goto warn_exit;
}
if (!ext4_mmp_csum_verify(sb, mmp)) {
ret = -EFSBADCRC;
goto warn_exit;
}
return 0;
warn_exit:
brelse(*bh);
*bh = NULL;
ext4_warning(sb, "Error %d while reading MMP block %llu",
ret, mmp_block);
return ret;
}
void __dump_mmp_msg(struct super_block *sb, struct mmp_struct *mmp,
const char *function, unsigned int line, const char *msg)
{
__ext4_warning(sb, function, line, "%s", msg);
__ext4_warning(sb, function, line,
"MMP failure info: last update time: %llu, last update "
"node: %s, last update device: %s",
(long long unsigned int) le64_to_cpu(mmp->mmp_time),
mmp->mmp_nodename, mmp->mmp_bdevname);
}
static int kmmpd(void *data)
{
struct super_block *sb = ((struct mmpd_data *) data)->sb;
struct buffer_head *bh = ((struct mmpd_data *) data)->bh;
struct ext4_super_block *es = EXT4_SB(sb)->s_es;
struct mmp_struct *mmp;
ext4_fsblk_t mmp_block;
u32 seq = 0;
unsigned long failed_writes = 0;
int mmp_update_interval = le16_to_cpu(es->s_mmp_update_interval);
unsigned mmp_check_interval;
unsigned long last_update_time;
unsigned long diff;
int retval;
mmp_block = le64_to_cpu(es->s_mmp_block);
mmp = (struct mmp_struct *)(bh->b_data);
mmp->mmp_time = cpu_to_le64(get_seconds());
mmp_check_interval = max(EXT4_MMP_CHECK_MULT * mmp_update_interval,
EXT4_MMP_MIN_CHECK_INTERVAL);
mmp->mmp_check_interval = cpu_to_le16(mmp_check_interval);
bdevname(bh->b_bdev, mmp->mmp_bdevname);
memcpy(mmp->mmp_nodename, init_utsname()->nodename,
sizeof(mmp->mmp_nodename));
while (!kthread_should_stop()) {
if (++seq > EXT4_MMP_SEQ_MAX)
seq = 1;
mmp->mmp_seq = cpu_to_le32(seq);
mmp->mmp_time = cpu_to_le64(get_seconds());
last_update_time = jiffies;
retval = write_mmp_block(sb, bh);
if (retval) {
if ((failed_writes % 60) == 0)
ext4_error(sb, "Error writing to MMP block");
failed_writes++;
}
if (!(le32_to_cpu(es->s_feature_incompat) &
EXT4_FEATURE_INCOMPAT_MMP)) {
ext4_warning(sb, "kmmpd being stopped since MMP feature"
" has been disabled.");
goto exit_thread;
}
if (sb->s_flags & MS_RDONLY) {
ext4_warning(sb, "kmmpd being stopped since filesystem "
"has been remounted as readonly.");
goto exit_thread;
}
diff = jiffies - last_update_time;
if (diff < mmp_update_interval * HZ)
schedule_timeout_interruptible(mmp_update_interval *
HZ - diff);
diff = jiffies - last_update_time;
if (diff > mmp_check_interval * HZ) {
struct buffer_head *bh_check = NULL;
struct mmp_struct *mmp_check;
retval = read_mmp_block(sb, &bh_check, mmp_block);
if (retval) {
ext4_error(sb, "error reading MMP data: %d",
retval);
goto exit_thread;
}
mmp_check = (struct mmp_struct *)(bh_check->b_data);
if (mmp->mmp_seq != mmp_check->mmp_seq ||
memcmp(mmp->mmp_nodename, mmp_check->mmp_nodename,
sizeof(mmp->mmp_nodename))) {
dump_mmp_msg(sb, mmp_check,
"Error while updating MMP info. "
"The filesystem seems to have been"
" multiply mounted.");
ext4_error(sb, "abort");
put_bh(bh_check);
retval = -EBUSY;
goto exit_thread;
}
put_bh(bh_check);
}
mmp_check_interval = max(min(EXT4_MMP_CHECK_MULT * diff / HZ,
EXT4_MMP_MAX_CHECK_INTERVAL),
EXT4_MMP_MIN_CHECK_INTERVAL);
mmp->mmp_check_interval = cpu_to_le16(mmp_check_interval);
}
mmp->mmp_seq = cpu_to_le32(EXT4_MMP_SEQ_CLEAN);
mmp->mmp_time = cpu_to_le64(get_seconds());
retval = write_mmp_block(sb, bh);
exit_thread:
EXT4_SB(sb)->s_mmp_tsk = NULL;
kfree(data);
brelse(bh);
return retval;
}
static unsigned int mmp_new_seq(void)
{
u32 new_seq;
do {
new_seq = prandom_u32();
} while (new_seq > EXT4_MMP_SEQ_MAX);
return new_seq;
}
int ext4_multi_mount_protect(struct super_block *sb,
ext4_fsblk_t mmp_block)
{
struct ext4_super_block *es = EXT4_SB(sb)->s_es;
struct buffer_head *bh = NULL;
struct mmp_struct *mmp = NULL;
struct mmpd_data *mmpd_data;
u32 seq;
unsigned int mmp_check_interval = le16_to_cpu(es->s_mmp_update_interval);
unsigned int wait_time = 0;
int retval;
if (mmp_block < le32_to_cpu(es->s_first_data_block) ||
mmp_block >= ext4_blocks_count(es)) {
ext4_warning(sb, "Invalid MMP block in superblock");
goto failed;
}
retval = read_mmp_block(sb, &bh, mmp_block);
if (retval)
goto failed;
mmp = (struct mmp_struct *)(bh->b_data);
if (mmp_check_interval < EXT4_MMP_MIN_CHECK_INTERVAL)
mmp_check_interval = EXT4_MMP_MIN_CHECK_INTERVAL;
if (le16_to_cpu(mmp->mmp_check_interval) > mmp_check_interval)
mmp_check_interval = le16_to_cpu(mmp->mmp_check_interval);
seq = le32_to_cpu(mmp->mmp_seq);
if (seq == EXT4_MMP_SEQ_CLEAN)
goto skip;
if (seq == EXT4_MMP_SEQ_FSCK) {
dump_mmp_msg(sb, mmp, "fsck is running on the filesystem");
goto failed;
}
wait_time = min(mmp_check_interval * 2 + 1,
mmp_check_interval + 60);
if (wait_time > EXT4_MMP_MIN_CHECK_INTERVAL * 4)
ext4_warning(sb, "MMP interval %u higher than expected, please"
" wait.\n", wait_time * 2);
if (schedule_timeout_interruptible(HZ * wait_time) != 0) {
ext4_warning(sb, "MMP startup interrupted, failing mount\n");
goto failed;
}
retval = read_mmp_block(sb, &bh, mmp_block);
if (retval)
goto failed;
mmp = (struct mmp_struct *)(bh->b_data);
if (seq != le32_to_cpu(mmp->mmp_seq)) {
dump_mmp_msg(sb, mmp,
"Device is already active on another node.");
goto failed;
}
skip:
seq = mmp_new_seq();
mmp->mmp_seq = cpu_to_le32(seq);
retval = write_mmp_block(sb, bh);
if (retval)
goto failed;
if (schedule_timeout_interruptible(HZ * wait_time) != 0) {
ext4_warning(sb, "MMP startup interrupted, failing mount");
goto failed;
}
retval = read_mmp_block(sb, &bh, mmp_block);
if (retval)
goto failed;
mmp = (struct mmp_struct *)(bh->b_data);
if (seq != le32_to_cpu(mmp->mmp_seq)) {
dump_mmp_msg(sb, mmp,
"Device is already active on another node.");
goto failed;
}
mmpd_data = kmalloc(sizeof(struct mmpd_data), GFP_KERNEL);
if (!mmpd_data) {
ext4_warning(sb, "not enough memory for mmpd_data");
goto failed;
}
mmpd_data->sb = sb;
mmpd_data->bh = bh;
EXT4_SB(sb)->s_mmp_tsk = kthread_run(kmmpd, mmpd_data, "kmmpd-%s",
bdevname(bh->b_bdev,
mmp->mmp_bdevname));
if (IS_ERR(EXT4_SB(sb)->s_mmp_tsk)) {
EXT4_SB(sb)->s_mmp_tsk = NULL;
kfree(mmpd_data);
ext4_warning(sb, "Unable to create kmmpd thread for %s.",
sb->s_id);
goto failed;
}
return 0;
failed:
brelse(bh);
return 1;
}
