static inline void path_get_longterm(struct path *path)
{
path_get(path);
mnt_make_longterm(path->mnt);
}
static inline void path_put_longterm(struct path *path)
{
mnt_make_shortterm(path->mnt);
path_put(path);
}
void set_fs_root(struct fs_struct *fs, struct path *path)
{
struct path old_root;
spin_lock(&fs->lock);
write_seqcount_begin(&fs->seq);
old_root = fs->root;
fs->root = *path;
path_get_longterm(path);
write_seqcount_end(&fs->seq);
spin_unlock(&fs->lock);
if (old_root.dentry)
path_put_longterm(&old_root);
}
void set_fs_pwd(struct fs_struct *fs, struct path *path)
{
struct path old_pwd;
spin_lock(&fs->lock);
write_seqcount_begin(&fs->seq);
old_pwd = fs->pwd;
fs->pwd = *path;
path_get_longterm(path);
write_seqcount_end(&fs->seq);
spin_unlock(&fs->lock);
if (old_pwd.dentry)
path_put_longterm(&old_pwd);
}
void chroot_fs_refs(struct path *old_root, struct path *new_root)
{
struct task_struct *g, *p;
struct fs_struct *fs;
int count = 0;
read_lock(&tasklist_lock);
do_each_thread(g, p) {
task_lock(p);
fs = p->fs;
if (fs) {
spin_lock(&fs->lock);
write_seqcount_begin(&fs->seq);
if (fs->root.dentry == old_root->dentry
&& fs->root.mnt == old_root->mnt) {
path_get_longterm(new_root);
fs->root = *new_root;
count++;
}
if (fs->pwd.dentry == old_root->dentry
&& fs->pwd.mnt == old_root->mnt) {
path_get_longterm(new_root);
fs->pwd = *new_root;
count++;
}
write_seqcount_end(&fs->seq);
spin_unlock(&fs->lock);
}
task_unlock(p);
} while_each_thread(g, p);
read_unlock(&tasklist_lock);
while (count--)
path_put_longterm(old_root);
}
void free_fs_struct(struct fs_struct *fs)
{
path_put_longterm(&fs->root);
path_put_longterm(&fs->pwd);
kmem_cache_free(fs_cachep, fs);
}
void exit_fs(struct task_struct *tsk)
{
struct fs_struct *fs = tsk->fs;
if (fs) {
int kill;
task_lock(tsk);
spin_lock(&fs->lock);
write_seqcount_begin(&fs->seq);
tsk->fs = NULL;
kill = !--fs->users;
write_seqcount_end(&fs->seq);
spin_unlock(&fs->lock);
task_unlock(tsk);
if (kill)
free_fs_struct(fs);
}
}
struct fs_struct *copy_fs_struct(struct fs_struct *old)
{
struct fs_struct *fs = kmem_cache_alloc(fs_cachep, GFP_KERNEL);
if (fs) {
fs->users = 1;
fs->in_exec = 0;
spin_lock_init(&fs->lock);
seqcount_init(&fs->seq);
fs->umask = old->umask;
spin_lock(&old->lock);
fs->root = old->root;
path_get_longterm(&fs->root);
fs->pwd = old->pwd;
path_get_longterm(&fs->pwd);
spin_unlock(&old->lock);
}
return fs;
}
int unshare_fs_struct(void)
{
struct fs_struct *fs = current->fs;
struct fs_struct *new_fs = copy_fs_struct(fs);
int kill;
if (!new_fs)
return -ENOMEM;
task_lock(current);
spin_lock(&fs->lock);
kill = !--fs->users;
current->fs = new_fs;
spin_unlock(&fs->lock);
task_unlock(current);
if (kill)
free_fs_struct(fs);
return 0;
}
int current_umask(void)
{
return current->fs->umask;
}
void daemonize_fs_struct(void)
{
struct fs_struct *fs = current->fs;
if (fs) {
int kill;
task_lock(current);
spin_lock(&init_fs.lock);
init_fs.users++;
spin_unlock(&init_fs.lock);
spin_lock(&fs->lock);
current->fs = &init_fs;
kill = !--fs->users;
spin_unlock(&fs->lock);
task_unlock(current);
if (kill)
free_fs_struct(fs);
}
}
