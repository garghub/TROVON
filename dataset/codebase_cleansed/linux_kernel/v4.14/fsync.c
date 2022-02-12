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
next = igrab(d_inode(dentry->d_parent));
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
int ext4_sync_file(struct file *file, loff_t start, loff_t end, int datasync)
{
struct inode *inode = file->f_mapping->host;
struct ext4_inode_info *ei = EXT4_I(inode);
journal_t *journal = EXT4_SB(inode->i_sb)->s_journal;
int ret = 0, err;
tid_t commit_tid;
bool needs_barrier = false;
if (unlikely(ext4_forced_shutdown(EXT4_SB(inode->i_sb))))
return -EIO;
J_ASSERT(ext4_journal_current_handle() == NULL);
trace_ext4_sync_file_enter(file, datasync);
if (sb_rdonly(inode->i_sb)) {
smp_rmb();
if (EXT4_SB(inode->i_sb)->s_mount_flags & EXT4_MF_FS_ABORTED)
ret = -EROFS;
goto out;
}
if (!journal) {
ret = __generic_file_fsync(file, start, end, datasync);
if (!ret)
ret = ext4_sync_parent(inode);
if (test_opt(inode->i_sb, BARRIER))
goto issue_flush;
goto out;
}
ret = file_write_and_wait_range(file, start, end);
if (ret)
return ret;
if (ext4_should_journal_data(inode)) {
ret = ext4_force_commit(inode->i_sb);
goto out;
}
commit_tid = datasync ? ei->i_datasync_tid : ei->i_sync_tid;
if (journal->j_flags & JBD2_BARRIER &&
!jbd2_trans_will_send_data_barrier(journal, commit_tid))
needs_barrier = true;
ret = jbd2_complete_transaction(journal, commit_tid);
if (needs_barrier) {
issue_flush:
err = blkdev_issue_flush(inode->i_sb->s_bdev, GFP_KERNEL, NULL);
if (!ret)
ret = err;
}
out:
trace_ext4_sync_file_exit(inode, ret);
return ret;
}
