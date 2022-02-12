char *tomoyo_encode(const char *str)
{
int len = 0;
const char *p = str;
char *cp;
char *cp0;
if (!p)
return NULL;
while (*p) {
const unsigned char c = *p++;
if (c == '\\')
len += 2;
else if (c > ' ' && c < 127)
len++;
else
len += 4;
}
len++;
cp = kzalloc(len + 10, GFP_NOFS);
if (!cp)
return NULL;
cp0 = cp;
p = str;
while (*p) {
const unsigned char c = *p++;
if (c == '\\') {
*cp++ = '\\';
*cp++ = '\\';
} else if (c > ' ' && c < 127) {
*cp++ = c;
} else {
*cp++ = '\\';
*cp++ = (c >> 6) + '0';
*cp++ = ((c >> 3) & 7) + '0';
*cp++ = (c & 7) + '0';
}
}
return cp0;
}
char *tomoyo_realpath_from_path(struct path *path)
{
char *buf = NULL;
char *name = NULL;
unsigned int buf_len = PAGE_SIZE / 2;
struct dentry *dentry = path->dentry;
bool is_dir;
if (!dentry)
return NULL;
is_dir = dentry->d_inode && S_ISDIR(dentry->d_inode->i_mode);
while (1) {
struct path ns_root = { .mnt = NULL, .dentry = NULL };
char *pos;
buf_len <<= 1;
kfree(buf);
buf = kmalloc(buf_len, GFP_NOFS);
if (!buf)
break;
if (dentry->d_sb && dentry->d_sb->s_magic == SOCKFS_MAGIC) {
struct inode *inode = dentry->d_inode;
struct socket *sock = inode ? SOCKET_I(inode) : NULL;
struct sock *sk = sock ? sock->sk : NULL;
if (sk) {
snprintf(buf, buf_len - 1, "socket:[family=%u:"
"type=%u:protocol=%u]", sk->sk_family,
sk->sk_type, sk->sk_protocol);
} else {
snprintf(buf, buf_len - 1, "socket:[unknown]");
}
name = tomoyo_encode(buf);
break;
}
if (dentry->d_op && dentry->d_op->d_dname) {
pos = dentry->d_op->d_dname(dentry, buf, buf_len - 1);
if (IS_ERR(pos))
continue;
name = tomoyo_encode(pos);
break;
}
if (!path->mnt)
break;
pos = __d_path(path, &ns_root, buf, buf_len);
if (!IS_ERR(pos) && (path->mnt->mnt_flags & MNT_INTERNAL) &&
(path->mnt->mnt_sb->s_magic == PROC_SUPER_MAGIC)) {
pos -= 5;
if (pos >= buf)
memcpy(pos, "/proc", 5);
else
pos = ERR_PTR(-ENOMEM);
}
if (IS_ERR(pos))
continue;
name = tomoyo_encode(pos);
break;
}
kfree(buf);
if (!name)
tomoyo_warn_oom(__func__);
else if (is_dir && *name) {
char *pos = name + strlen(name) - 1;
if (*pos != '/')
*++pos = '/';
}
return name;
}
char *tomoyo_realpath_nofollow(const char *pathname)
{
struct path path;
if (pathname && kern_path(pathname, 0, &path) == 0) {
char *buf = tomoyo_realpath_from_path(&path);
path_put(&path);
return buf;
}
return NULL;
}
