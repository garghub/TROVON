static int ext4_sync_parent(struct inode *inode)
{
struct dentry *dentry = NULL;
struct inode *next;
int ret = 0;
if (!ext4_test_inode_state(inode, EXT4_STATE_NEWENTRY))
return 0;
inode = igrab(inode);
while (ext4_test_inode_state(inode, EXT4_STATE_NEWENTRY)) {
ext4_clear_inode_state(inode, EXT4_STATE_NEWENTRY);
dentry = d_find_any_alias(inode);
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
ret = sync_inode_metadata(inode, 1);
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
int ret, err;
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
ret = ext4_flush_unwritten_io(inode);
if (ret < 0)
goto out;
if (!journal) {
ret = __sync_inode(inode, datasync);
if (!ret && !hlist_empty(&inode->i_dentry))
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
if (needs_barrier) {
err = blkdev_issue_flush(inode->i_sb->s_bdev, GFP_KERNEL, NULL);
if (!ret)
ret = err;
}
out:
mutex_unlock(&inode->i_mutex);
trace_ext4_sync_file_exit(inode, ret);
return ret;
}
