static int prepend(char **buffer, int buflen, const char *str, int namelen)
{
buflen -= namelen;
if (buflen < 0)
return -ENAMETOOLONG;
*buffer -= namelen;
memcpy(*buffer, str, namelen);
return 0;
}
static int d_namespace_path(struct path *path, char *buf, int buflen,
char **name, int flags)
{
struct path root, tmp;
char *res;
int connected, error = 0;
if (flags & PATH_CHROOT_REL) {
get_fs_root(current->fs, &root);
} else {
root.mnt = current->nsproxy->mnt_ns->root;
root.dentry = root.mnt->mnt_root;
path_get(&root);
}
tmp = root;
res = __d_path(path, &tmp, buf, buflen);
*name = res;
if (IS_ERR(res)) {
error = PTR_ERR(res);
*name = buf;
goto out;
}
if (d_unlinked(path->dentry) && path->dentry->d_inode &&
!(flags & PATH_MEDIATE_DELETED)) {
error = -ENOENT;
goto out;
}
connected = tmp.dentry == root.dentry && tmp.mnt == root.mnt;
if (!connected) {
if (tmp.dentry->d_sb->s_magic == PROC_SUPER_MAGIC &&
strncmp(*name, "/sys/", 5) == 0) {
error = prepend(name, *name - buf, "/proc", 5);
} else if (!(flags & PATH_CONNECT_PATH) &&
!(((flags & CHROOT_NSCONNECT) == CHROOT_NSCONNECT) &&
(tmp.mnt == current->nsproxy->mnt_ns->root &&
tmp.dentry == tmp.mnt->mnt_root))) {
error = -ESTALE;
if (*res == '/')
*name = res + 1;
}
}
out:
path_put(&root);
return error;
}
static int get_name_to_buffer(struct path *path, int flags, char *buffer,
int size, char **name)
{
int adjust = (flags & PATH_IS_DIR) ? 1 : 0;
int error = d_namespace_path(path, buffer, size - adjust, name, flags);
if (!error && (flags & PATH_IS_DIR) && (*name)[1] != '\0')
strcpy(&buffer[size - 2], "/");
return error;
}
int aa_get_name(struct path *path, int flags, char **buffer, const char **name)
{
char *buf, *str = NULL;
int size = 256;
int error;
*name = NULL;
*buffer = NULL;
for (;;) {
buf = kmalloc(size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
error = get_name_to_buffer(path, flags, buf, size, &str);
if (error != -ENAMETOOLONG)
break;
kfree(buf);
size <<= 1;
if (size > aa_g_path_max)
return -ENAMETOOLONG;
}
*buffer = buf;
*name = str;
return error;
}
