int pohmelfs_construct_path_string(struct pohmelfs_inode *pi, void *data, int len)
{
struct path path;
struct dentry *d;
char *ptr;
int err = 0, strlen, reduce = 0;
d = d_find_alias(&pi->vfs_inode);
if (!d) {
printk("%s: no alias, list_empty: %d.\n", __func__, list_empty(&pi->vfs_inode.i_dentry));
return -ENOENT;
}
spin_lock(&current->fs->lock);
path.mnt = mntget(current->fs->root.mnt);
spin_unlock(&current->fs->lock);
path.dentry = d;
if (!IS_ROOT(d) && d_unhashed(d))
reduce = 1;
ptr = d_path(&path, data, len);
if (IS_ERR(ptr)) {
err = PTR_ERR(ptr);
goto out;
}
if (reduce && len >= UNHASHED_OBSCURE_STRING_SIZE) {
char *end = data + len - UNHASHED_OBSCURE_STRING_SIZE;
*end = '\0';
}
strlen = len - (ptr - (char *)data);
memmove(data, ptr, strlen);
ptr = data;
err = strlen;
dprintk("%s: dname: '%s', len: %u, maxlen: %u, name: '%s', strlen: %d.\n",
__func__, d->d_name.name, d->d_name.len, len, ptr, strlen);
out:
dput(d);
mntput(path.mnt);
return err;
}
int pohmelfs_path_length(struct pohmelfs_inode *pi)
{
struct dentry *d, *root, *first;
int len;
unsigned seq;
first = d_find_alias(&pi->vfs_inode);
if (!first) {
dprintk("%s: ino: %llu, mode: %o.\n", __func__, pi->ino, pi->vfs_inode.i_mode);
return -ENOENT;
}
spin_lock(&current->fs->lock);
root = dget(current->fs->root.dentry);
spin_unlock(&current->fs->lock);
rename_retry:
len = 1;
d = first;
seq = read_seqbegin(&rename_lock);
rcu_read_lock();
if (!IS_ROOT(d) && d_unhashed(d))
len += UNHASHED_OBSCURE_STRING_SIZE;
while (d && d != root && !IS_ROOT(d)) {
len += d->d_name.len + 1;
d = d->d_parent;
}
rcu_read_unlock();
if (read_seqretry(&rename_lock, seq))
goto rename_retry;
dput(root);
dput(first);
return len + 1;
}
