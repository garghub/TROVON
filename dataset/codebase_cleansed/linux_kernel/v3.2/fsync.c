static void dump_completed_IO(struct inode * inode)
{
#ifdef EXT4FS_DEBUG
struct list_head *cur, *before, *after;
ext4_io_end_t *io, *io0, *io1;
unsigned long flags;
if (list_empty(&EXT4_I(inode)->i_completed_io_list)){
ext4_debug("inode %lu completed_io list is empty\n", inode->i_ino);
return;
}
ext4_debug("Dump inode %lu completed_io list \n", inode->i_ino);
spin_lock_irqsave(&EXT4_I(inode)->i_completed_io_lock, flags);
list_for_each_entry(io, &EXT4_I(inode)->i_completed_io_list, list){
cur = &io->list;
before = cur->prev;
io0 = container_of(before, ext4_io_end_t, list);
after = cur->next;
io1 = container_of(after, ext4_io_end_t, list);
ext4_debug("io 0x%p from inode %lu,prev 0x%p,next 0x%p\n",
io, inode->i_ino, io0, io1);
}
spin_unlock_irqrestore(&EXT4_I(inode)->i_completed_io_lock, flags);
#endif
}
int ext4_flush_completed_IO(struct inode *inode)
{
ext4_io_end_t *io;
struct ext4_inode_info *ei = EXT4_I(inode);
unsigned long flags;
int ret = 0;
int ret2 = 0;
dump_completed_IO(inode);
spin_lock_irqsave(&ei->i_completed_io_lock, flags);
while (!list_empty(&ei->i_completed_io_list)){
io = list_entry(ei->i_completed_io_list.next,
ext4_io_end_t, list);
list_del_init(&io->list);
spin_unlock_irqrestore(&ei->i_completed_io_lock, flags);
ret = ext4_end_io_nolock(io);
if (ret < 0)
ret2 = ret;
spin_lock_irqsave(&ei->i_completed_io_lock, flags);
}
spin_unlock_irqrestore(&ei->i_completed_io_lock, flags);
return (ret2 < 0) ? ret2 : 0;
}
static int ext4_sync_parent(struct inode *inode)
{
struct writeback_control wbc;
struct dentry *dentry = NULL;
struct inode *next;
int ret = 0;
if (!ext4_test_inode_state(inode, EXT4_STATE_NEWENTRY))
return 0;
inode = igrab(inode);
while (ext4_test_inode_state(inode, EXT4_STATE_NEWENTRY)) {
ext4_clear_inode_state(inode, EXT4_STATE_NEWENTRY);
dentry = NULL;
spin_lock(&inode->i_lock);
if (!list_empty(&inode->i_dentry)) {
dentry = list_first_entry(&inode->i_dentry,
struct dentry, d_alias);
dget(dentry);
}
spin_unlock(&inode->i_lock);
if (!dentry)
break;
next = igrab(dentry->d_parent->d_inode);
dput(dentry);
if (!next)
break;
iput(inode);
inode = next;
ret = sync_mapping_buffers(inode->i_mapping);
if (ret)
break;
memset(&wbc, 0, sizeof(wbc));
wbc.sync_mode = WB_SYNC_ALL;
wbc.nr_to_write = 0;
ret = sync_inode(inode, &wbc);
if (ret)
break;
}
iput(inode);
return ret;
}
static int __sync_inode(struct inode *inode, int datasync)
{
int err;
int ret;
ret = sync_mapping_buffers(inode->i_mapping);
if (!(inode->i_state & I_DIRTY))
return ret;
if (datasync && !(inode->i_state & I_DIRTY_DATASYNC))
return ret;
err = sync_inode_metadata(inode, 1);
if (ret == 0)
ret = err;
return ret;
}
int ext4_sync_file(struct file *file, loff_t start, loff_t end, int datasync)
{
struct inode *inode = file->f_mapping->host;
struct ext4_inode_info *ei = EXT4_I(inode);
journal_t *journal = EXT4_SB(inode->i_sb)->s_journal;
int ret;
tid_t commit_tid;
bool needs_barrier = false;
J_ASSERT(ext4_journal_current_handle() == NULL);
trace_ext4_sync_file_enter(file, datasync);
ret = filemap_write_and_wait_range(inode->i_mapping, start, end);
if (ret)
return ret;
mutex_lock(&inode->i_mutex);
if (inode->i_sb->s_flags & MS_RDONLY)
goto out;
ret = ext4_flush_completed_IO(inode);
if (ret < 0)
goto out;
if (!journal) {
ret = __sync_inode(inode, datasync);
if (!ret && !list_empty(&inode->i_dentry))
ret = ext4_sync_parent(inode);
goto out;
}
if (ext4_should_journal_data(inode)) {
ret = ext4_force_commit(inode->i_sb);
goto out;
}
commit_tid = datasync ? ei->i_datasync_tid : ei->i_sync_tid;
if (journal->j_flags & JBD2_BARRIER &&
!jbd2_trans_will_send_data_barrier(journal, commit_tid))
needs_barrier = true;
jbd2_log_start_commit(journal, commit_tid);
ret = jbd2_log_wait_commit(journal, commit_tid);
if (needs_barrier)
blkdev_issue_flush(inode->i_sb->s_bdev, GFP_KERNEL, NULL);
out:
mutex_unlock(&inode->i_mutex);
trace_ext4_sync_file_exit(inode, ret);
return ret;
}
