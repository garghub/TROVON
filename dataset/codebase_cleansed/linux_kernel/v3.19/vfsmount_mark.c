void fsnotify_clear_marks_by_mount(struct vfsmount *mnt)
{
struct fsnotify_mark *mark;
struct hlist_node *n;
struct mount *m = real_mount(mnt);
LIST_HEAD(free_list);
spin_lock(&mnt->mnt_root->d_lock);
hlist_for_each_entry_safe(mark, n, &m->mnt_fsnotify_marks, obj_list) {
list_add(&mark->free_list, &free_list);
hlist_del_init_rcu(&mark->obj_list);
fsnotify_get_mark(mark);
}
spin_unlock(&mnt->mnt_root->d_lock);
fsnotify_destroy_marks(&free_list);
}
void fsnotify_clear_vfsmount_marks_by_group(struct fsnotify_group *group)
{
fsnotify_clear_marks_by_group_flags(group, FSNOTIFY_MARK_FLAG_VFSMOUNT);
}
void fsnotify_recalc_vfsmount_mask(struct vfsmount *mnt)
{
struct mount *m = real_mount(mnt);
spin_lock(&mnt->mnt_root->d_lock);
m->mnt_fsnotify_mask = fsnotify_recalc_mask(&m->mnt_fsnotify_marks);
spin_unlock(&mnt->mnt_root->d_lock);
}
void fsnotify_destroy_vfsmount_mark(struct fsnotify_mark *mark)
{
struct vfsmount *mnt = mark->mnt;
struct mount *m = real_mount(mnt);
BUG_ON(!mutex_is_locked(&mark->group->mark_mutex));
assert_spin_locked(&mark->lock);
spin_lock(&mnt->mnt_root->d_lock);
hlist_del_init_rcu(&mark->obj_list);
mark->mnt = NULL;
m->mnt_fsnotify_mask = fsnotify_recalc_mask(&m->mnt_fsnotify_marks);
spin_unlock(&mnt->mnt_root->d_lock);
}
struct fsnotify_mark *fsnotify_find_vfsmount_mark(struct fsnotify_group *group,
struct vfsmount *mnt)
{
struct mount *m = real_mount(mnt);
struct fsnotify_mark *mark;
spin_lock(&mnt->mnt_root->d_lock);
mark = fsnotify_find_mark(&m->mnt_fsnotify_marks, group);
spin_unlock(&mnt->mnt_root->d_lock);
return mark;
}
int fsnotify_add_vfsmount_mark(struct fsnotify_mark *mark,
struct fsnotify_group *group, struct vfsmount *mnt,
int allow_dups)
{
struct mount *m = real_mount(mnt);
int ret;
mark->flags |= FSNOTIFY_MARK_FLAG_VFSMOUNT;
BUG_ON(!mutex_is_locked(&group->mark_mutex));
assert_spin_locked(&mark->lock);
spin_lock(&mnt->mnt_root->d_lock);
mark->mnt = mnt;
ret = fsnotify_add_mark_list(&m->mnt_fsnotify_marks, mark, allow_dups);
m->mnt_fsnotify_mask = fsnotify_recalc_mask(&m->mnt_fsnotify_marks);
spin_unlock(&mnt->mnt_root->d_lock);
return ret;
}
