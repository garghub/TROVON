void __fsnotify_inode_delete(struct inode *inode)
{
fsnotify_clear_marks_by_inode(inode);
}
void __fsnotify_vfsmount_delete(struct vfsmount *mnt)
{
fsnotify_clear_marks_by_mount(mnt);
}
void __fsnotify_update_child_dentry_flags(struct inode *inode)
{
struct dentry *alias;
int watched;
if (!S_ISDIR(inode->i_mode))
return;
watched = fsnotify_inode_watches_children(inode);
spin_lock(&inode->i_lock);
hlist_for_each_entry(alias, &inode->i_dentry, d_alias) {
struct dentry *child;
spin_lock(&alias->d_lock);
list_for_each_entry(child, &alias->d_subdirs, d_u.d_child) {
if (!child->d_inode)
continue;
spin_lock_nested(&child->d_lock, DENTRY_D_LOCK_NESTED);
if (watched)
child->d_flags |= DCACHE_FSNOTIFY_PARENT_WATCHED;
else
child->d_flags &= ~DCACHE_FSNOTIFY_PARENT_WATCHED;
spin_unlock(&child->d_lock);
}
spin_unlock(&alias->d_lock);
}
spin_unlock(&inode->i_lock);
}
int __fsnotify_parent(struct path *path, struct dentry *dentry, __u32 mask)
{
struct dentry *parent;
struct inode *p_inode;
int ret = 0;
if (!dentry)
dentry = path->dentry;
if (!(dentry->d_flags & DCACHE_FSNOTIFY_PARENT_WATCHED))
return 0;
parent = dget_parent(dentry);
p_inode = parent->d_inode;
if (unlikely(!fsnotify_inode_watches_children(p_inode)))
__fsnotify_update_child_dentry_flags(p_inode);
else if (p_inode->i_fsnotify_mask & mask) {
mask |= FS_EVENT_ON_CHILD;
if (path)
ret = fsnotify(p_inode, mask, path, FSNOTIFY_EVENT_PATH,
dentry->d_name.name, 0);
else
ret = fsnotify(p_inode, mask, dentry->d_inode, FSNOTIFY_EVENT_INODE,
dentry->d_name.name, 0);
}
dput(parent);
return ret;
}
static int send_to_group(struct inode *to_tell,
struct fsnotify_mark *inode_mark,
struct fsnotify_mark *vfsmount_mark,
__u32 mask, void *data,
int data_is, u32 cookie,
const unsigned char *file_name,
struct fsnotify_event **event)
{
struct fsnotify_group *group = NULL;
__u32 inode_test_mask = 0;
__u32 vfsmount_test_mask = 0;
if (unlikely(!inode_mark && !vfsmount_mark)) {
BUG();
return 0;
}
if (mask & FS_MODIFY) {
if (inode_mark &&
!(inode_mark->flags & FSNOTIFY_MARK_FLAG_IGNORED_SURV_MODIFY))
inode_mark->ignored_mask = 0;
if (vfsmount_mark &&
!(vfsmount_mark->flags & FSNOTIFY_MARK_FLAG_IGNORED_SURV_MODIFY))
vfsmount_mark->ignored_mask = 0;
}
if (inode_mark) {
group = inode_mark->group;
inode_test_mask = (mask & ~FS_EVENT_ON_CHILD);
inode_test_mask &= inode_mark->mask;
inode_test_mask &= ~inode_mark->ignored_mask;
}
if (vfsmount_mark) {
vfsmount_test_mask = (mask & ~FS_EVENT_ON_CHILD);
group = vfsmount_mark->group;
vfsmount_test_mask &= vfsmount_mark->mask;
vfsmount_test_mask &= ~vfsmount_mark->ignored_mask;
if (inode_mark)
vfsmount_test_mask &= ~inode_mark->ignored_mask;
}
pr_debug("%s: group=%p to_tell=%p mask=%x inode_mark=%p"
" inode_test_mask=%x vfsmount_mark=%p vfsmount_test_mask=%x"
" data=%p data_is=%d cookie=%d event=%p\n",
__func__, group, to_tell, mask, inode_mark,
inode_test_mask, vfsmount_mark, vfsmount_test_mask, data,
data_is, cookie, *event);
if (!inode_test_mask && !vfsmount_test_mask)
return 0;
if (group->ops->should_send_event(group, to_tell, inode_mark,
vfsmount_mark, mask, data,
data_is) == false)
return 0;
if (!*event) {
*event = fsnotify_create_event(to_tell, mask, data,
data_is, file_name,
cookie, GFP_KERNEL);
if (!*event)
return -ENOMEM;
}
return group->ops->handle_event(group, inode_mark, vfsmount_mark, *event);
}
int fsnotify(struct inode *to_tell, __u32 mask, void *data, int data_is,
const unsigned char *file_name, u32 cookie)
{
struct hlist_node *inode_node = NULL, *vfsmount_node = NULL;
struct fsnotify_mark *inode_mark = NULL, *vfsmount_mark = NULL;
struct fsnotify_group *inode_group, *vfsmount_group;
struct fsnotify_event *event = NULL;
struct mount *mnt;
int idx, ret = 0;
__u32 test_mask = (mask & ~FS_EVENT_ON_CHILD);
if (data_is == FSNOTIFY_EVENT_PATH)
mnt = real_mount(((struct path *)data)->mnt);
else
mnt = NULL;
if (!(mask & FS_MODIFY) &&
!(test_mask & to_tell->i_fsnotify_mask) &&
!(mnt && test_mask & mnt->mnt_fsnotify_mask))
return 0;
idx = srcu_read_lock(&fsnotify_mark_srcu);
if ((mask & FS_MODIFY) ||
(test_mask & to_tell->i_fsnotify_mask))
inode_node = srcu_dereference(to_tell->i_fsnotify_marks.first,
&fsnotify_mark_srcu);
if (mnt && ((mask & FS_MODIFY) ||
(test_mask & mnt->mnt_fsnotify_mask))) {
vfsmount_node = srcu_dereference(mnt->mnt_fsnotify_marks.first,
&fsnotify_mark_srcu);
inode_node = srcu_dereference(to_tell->i_fsnotify_marks.first,
&fsnotify_mark_srcu);
}
while (inode_node || vfsmount_node) {
inode_group = vfsmount_group = NULL;
if (inode_node) {
inode_mark = hlist_entry(srcu_dereference(inode_node, &fsnotify_mark_srcu),
struct fsnotify_mark, i.i_list);
inode_group = inode_mark->group;
}
if (vfsmount_node) {
vfsmount_mark = hlist_entry(srcu_dereference(vfsmount_node, &fsnotify_mark_srcu),
struct fsnotify_mark, m.m_list);
vfsmount_group = vfsmount_mark->group;
}
if (inode_group > vfsmount_group) {
ret = send_to_group(to_tell, inode_mark, NULL, mask, data,
data_is, cookie, file_name, &event);
vfsmount_group = NULL;
} else if (vfsmount_group > inode_group) {
ret = send_to_group(to_tell, NULL, vfsmount_mark, mask, data,
data_is, cookie, file_name, &event);
inode_group = NULL;
} else {
ret = send_to_group(to_tell, inode_mark, vfsmount_mark,
mask, data, data_is, cookie, file_name,
&event);
}
if (ret && (mask & ALL_FSNOTIFY_PERM_EVENTS))
goto out;
if (inode_group)
inode_node = srcu_dereference(inode_node->next,
&fsnotify_mark_srcu);
if (vfsmount_group)
vfsmount_node = srcu_dereference(vfsmount_node->next,
&fsnotify_mark_srcu);
}
ret = 0;
out:
srcu_read_unlock(&fsnotify_mark_srcu, idx);
if (event)
fsnotify_put_event(event);
return ret;
}
static __init int fsnotify_init(void)
{
int ret;
BUG_ON(hweight32(ALL_FSNOTIFY_EVENTS) != 23);
ret = init_srcu_struct(&fsnotify_mark_srcu);
if (ret)
panic("initializing fsnotify_mark_srcu");
return 0;
}
