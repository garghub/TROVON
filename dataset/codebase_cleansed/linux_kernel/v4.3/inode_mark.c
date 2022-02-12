void fsnotify_recalc_inode_mask(struct inode *inode)
{
spin_lock(&inode->i_lock);
inode->i_fsnotify_mask = fsnotify_recalc_mask(&inode->i_fsnotify_marks);
spin_unlock(&inode->i_lock);
__fsnotify_update_child_dentry_flags(inode);
}
void fsnotify_destroy_inode_mark(struct fsnotify_mark *mark)
{
struct inode *inode = mark->inode;
BUG_ON(!mutex_is_locked(&mark->group->mark_mutex));
assert_spin_locked(&mark->lock);
spin_lock(&inode->i_lock);
hlist_del_init_rcu(&mark->obj_list);
mark->inode = NULL;
inode->i_fsnotify_mask = fsnotify_recalc_mask(&inode->i_fsnotify_marks);
spin_unlock(&inode->i_lock);
}
void fsnotify_clear_inode_marks_by_group(struct fsnotify_group *group)
{
fsnotify_clear_marks_by_group_flags(group, FSNOTIFY_MARK_FLAG_INODE);
}
struct fsnotify_mark *fsnotify_find_inode_mark(struct fsnotify_group *group,
struct inode *inode)
{
struct fsnotify_mark *mark;
spin_lock(&inode->i_lock);
mark = fsnotify_find_mark(&inode->i_fsnotify_marks, group);
spin_unlock(&inode->i_lock);
return mark;
}
void fsnotify_set_inode_mark_mask_locked(struct fsnotify_mark *mark,
__u32 mask)
{
struct inode *inode;
assert_spin_locked(&mark->lock);
if (mask &&
mark->inode &&
!(mark->flags & FSNOTIFY_MARK_FLAG_OBJECT_PINNED)) {
mark->flags |= FSNOTIFY_MARK_FLAG_OBJECT_PINNED;
inode = igrab(mark->inode);
BUG_ON(!inode);
}
}
int fsnotify_add_inode_mark(struct fsnotify_mark *mark,
struct fsnotify_group *group, struct inode *inode,
int allow_dups)
{
int ret;
mark->flags |= FSNOTIFY_MARK_FLAG_INODE;
BUG_ON(!mutex_is_locked(&group->mark_mutex));
assert_spin_locked(&mark->lock);
spin_lock(&inode->i_lock);
mark->inode = inode;
ret = fsnotify_add_mark_list(&inode->i_fsnotify_marks, mark,
allow_dups);
inode->i_fsnotify_mask = fsnotify_recalc_mask(&inode->i_fsnotify_marks);
spin_unlock(&inode->i_lock);
return ret;
}
void fsnotify_unmount_inodes(struct super_block *sb)
{
struct inode *inode, *next_i, *need_iput = NULL;
spin_lock(&sb->s_inode_list_lock);
list_for_each_entry_safe(inode, next_i, &sb->s_inodes, i_sb_list) {
struct inode *need_iput_tmp;
spin_lock(&inode->i_lock);
if (inode->i_state & (I_FREEING|I_WILL_FREE|I_NEW)) {
spin_unlock(&inode->i_lock);
continue;
}
if (!atomic_read(&inode->i_count)) {
spin_unlock(&inode->i_lock);
continue;
}
need_iput_tmp = need_iput;
need_iput = NULL;
if (inode != need_iput_tmp)
__iget(inode);
else
need_iput_tmp = NULL;
spin_unlock(&inode->i_lock);
while (&next_i->i_sb_list != &sb->s_inodes) {
spin_lock(&next_i->i_lock);
if (!(next_i->i_state & (I_FREEING | I_WILL_FREE)) &&
atomic_read(&next_i->i_count)) {
__iget(next_i);
need_iput = next_i;
spin_unlock(&next_i->i_lock);
break;
}
spin_unlock(&next_i->i_lock);
next_i = list_entry(next_i->i_sb_list.next,
struct inode, i_sb_list);
}
spin_unlock(&sb->s_inode_list_lock);
if (need_iput_tmp)
iput(need_iput_tmp);
fsnotify(inode, FS_UNMOUNT, inode, FSNOTIFY_EVENT_INODE, NULL, 0);
fsnotify_inode_delete(inode);
iput(inode);
spin_lock(&sb->s_inode_list_lock);
}
spin_unlock(&sb->s_inode_list_lock);
}
