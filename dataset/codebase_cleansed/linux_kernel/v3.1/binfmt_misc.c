static Node *check_file(struct linux_binprm *bprm)
{
char *p = strrchr(bprm->interp, '.');
struct list_head *l;
list_for_each(l, &entries) {
Node *e = list_entry(l, Node, list);
char *s;
int j;
if (!test_bit(Enabled, &e->flags))
continue;
if (!test_bit(Magic, &e->flags)) {
if (p && !strcmp(e->magic, p + 1))
return e;
continue;
}
s = bprm->buf + e->offset;
if (e->mask) {
for (j = 0; j < e->size; j++)
if ((*s++ ^ e->magic[j]) & e->mask[j])
break;
} else {
for (j = 0; j < e->size; j++)
if ((*s++ ^ e->magic[j]))
break;
}
if (j == e->size)
return e;
}
return NULL;
}
static int load_misc_binary(struct linux_binprm *bprm, struct pt_regs *regs)
{
Node *fmt;
struct file * interp_file = NULL;
char iname[BINPRM_BUF_SIZE];
const char *iname_addr = iname;
int retval;
int fd_binary = -1;
retval = -ENOEXEC;
if (!enabled)
goto _ret;
retval = -ENOEXEC;
if (bprm->recursion_depth > BINPRM_MAX_RECURSION)
goto _ret;
read_lock(&entries_lock);
fmt = check_file(bprm);
if (fmt)
strlcpy(iname, fmt->interpreter, BINPRM_BUF_SIZE);
read_unlock(&entries_lock);
if (!fmt)
goto _ret;
if (!(fmt->flags & MISC_FMT_PRESERVE_ARGV0)) {
retval = remove_arg_zero(bprm);
if (retval)
goto _ret;
}
if (fmt->flags & MISC_FMT_OPEN_BINARY) {
fd_binary = get_unused_fd();
if (fd_binary < 0) {
retval = fd_binary;
goto _ret;
}
fd_install(fd_binary, bprm->file);
would_dump(bprm, bprm->file);
allow_write_access(bprm->file);
bprm->file = NULL;
bprm->interp_flags |= BINPRM_FLAGS_EXECFD;
bprm->interp_data = fd_binary;
} else {
allow_write_access(bprm->file);
fput(bprm->file);
bprm->file = NULL;
}
retval = copy_strings_kernel (1, &bprm->interp, bprm);
if (retval < 0)
goto _error;
bprm->argc++;
retval = copy_strings_kernel (1, &iname_addr, bprm);
if (retval < 0)
goto _error;
bprm->argc ++;
bprm->interp = iname;
interp_file = open_exec (iname);
retval = PTR_ERR (interp_file);
if (IS_ERR (interp_file))
goto _error;
bprm->file = interp_file;
if (fmt->flags & MISC_FMT_CREDENTIALS) {
memset(bprm->buf, 0, BINPRM_BUF_SIZE);
retval = kernel_read(bprm->file, 0, bprm->buf, BINPRM_BUF_SIZE);
} else
retval = prepare_binprm (bprm);
if (retval < 0)
goto _error;
bprm->recursion_depth++;
retval = search_binary_handler (bprm, regs);
if (retval < 0)
goto _error;
_ret:
return retval;
_error:
if (fd_binary > 0)
sys_close(fd_binary);
bprm->interp_flags = 0;
bprm->interp_data = 0;
goto _ret;
}
static char *scanarg(char *s, char del)
{
char c;
while ((c = *s++) != del) {
if (c == '\\' && *s == 'x') {
s++;
if (!isxdigit(*s++))
return NULL;
if (!isxdigit(*s++))
return NULL;
}
}
return s;
}
static int unquote(char *from)
{
char c = 0, *s = from, *p = from;
while ((c = *s++) != '\0') {
if (c == '\\' && *s == 'x') {
s++;
c = toupper(*s++);
*p = (c - (isdigit(c) ? '0' : 'A' - 10)) << 4;
c = toupper(*s++);
*p++ |= c - (isdigit(c) ? '0' : 'A' - 10);
continue;
}
*p++ = c;
}
return p - from;
}
static char * check_special_flags (char * sfs, Node * e)
{
char * p = sfs;
int cont = 1;
while (cont) {
switch (*p) {
case 'P':
p++;
e->flags |= MISC_FMT_PRESERVE_ARGV0;
break;
case 'O':
p++;
e->flags |= MISC_FMT_OPEN_BINARY;
break;
case 'C':
p++;
e->flags |= (MISC_FMT_CREDENTIALS |
MISC_FMT_OPEN_BINARY);
break;
default:
cont = 0;
}
}
return p;
}
static Node *create_entry(const char __user *buffer, size_t count)
{
Node *e;
int memsize, err;
char *buf, *p;
char del;
err = -EINVAL;
if ((count < 11) || (count > 256))
goto out;
err = -ENOMEM;
memsize = sizeof(Node) + count + 8;
e = kmalloc(memsize, GFP_USER);
if (!e)
goto out;
p = buf = (char *)e + sizeof(Node);
memset(e, 0, sizeof(Node));
if (copy_from_user(buf, buffer, count))
goto Efault;
del = *p++;
memset(buf+count, del, 8);
e->name = p;
p = strchr(p, del);
if (!p)
goto Einval;
*p++ = '\0';
if (!e->name[0] ||
!strcmp(e->name, ".") ||
!strcmp(e->name, "..") ||
strchr(e->name, '/'))
goto Einval;
switch (*p++) {
case 'E': e->flags = 1<<Enabled; break;
case 'M': e->flags = (1<<Enabled) | (1<<Magic); break;
default: goto Einval;
}
if (*p++ != del)
goto Einval;
if (test_bit(Magic, &e->flags)) {
char *s = strchr(p, del);
if (!s)
goto Einval;
*s++ = '\0';
e->offset = simple_strtoul(p, &p, 10);
if (*p++)
goto Einval;
e->magic = p;
p = scanarg(p, del);
if (!p)
goto Einval;
p[-1] = '\0';
if (!e->magic[0])
goto Einval;
e->mask = p;
p = scanarg(p, del);
if (!p)
goto Einval;
p[-1] = '\0';
if (!e->mask[0])
e->mask = NULL;
e->size = unquote(e->magic);
if (e->mask && unquote(e->mask) != e->size)
goto Einval;
if (e->size + e->offset > BINPRM_BUF_SIZE)
goto Einval;
} else {
p = strchr(p, del);
if (!p)
goto Einval;
*p++ = '\0';
e->magic = p;
p = strchr(p, del);
if (!p)
goto Einval;
*p++ = '\0';
if (!e->magic[0] || strchr(e->magic, '/'))
goto Einval;
p = strchr(p, del);
if (!p)
goto Einval;
*p++ = '\0';
}
e->interpreter = p;
p = strchr(p, del);
if (!p)
goto Einval;
*p++ = '\0';
if (!e->interpreter[0])
goto Einval;
p = check_special_flags (p, e);
if (*p == '\n')
p++;
if (p != buf + count)
goto Einval;
return e;
out:
return ERR_PTR(err);
Efault:
kfree(e);
return ERR_PTR(-EFAULT);
Einval:
kfree(e);
return ERR_PTR(-EINVAL);
}
static int parse_command(const char __user *buffer, size_t count)
{
char s[4];
if (!count)
return 0;
if (count > 3)
return -EINVAL;
if (copy_from_user(s, buffer, count))
return -EFAULT;
if (s[count-1] == '\n')
count--;
if (count == 1 && s[0] == '0')
return 1;
if (count == 1 && s[0] == '1')
return 2;
if (count == 2 && s[0] == '-' && s[1] == '1')
return 3;
return -EINVAL;
}
static void entry_status(Node *e, char *page)
{
char *dp;
char *status = "disabled";
const char * flags = "flags: ";
if (test_bit(Enabled, &e->flags))
status = "enabled";
if (!VERBOSE_STATUS) {
sprintf(page, "%s\n", status);
return;
}
sprintf(page, "%s\ninterpreter %s\n", status, e->interpreter);
dp = page + strlen(page);
sprintf (dp, "%s", flags);
dp += strlen (flags);
if (e->flags & MISC_FMT_PRESERVE_ARGV0) {
*dp ++ = 'P';
}
if (e->flags & MISC_FMT_OPEN_BINARY) {
*dp ++ = 'O';
}
if (e->flags & MISC_FMT_CREDENTIALS) {
*dp ++ = 'C';
}
*dp ++ = '\n';
if (!test_bit(Magic, &e->flags)) {
sprintf(dp, "extension .%s\n", e->magic);
} else {
int i;
sprintf(dp, "offset %i\nmagic ", e->offset);
dp = page + strlen(page);
for (i = 0; i < e->size; i++) {
sprintf(dp, "%02x", 0xff & (int) (e->magic[i]));
dp += 2;
}
if (e->mask) {
sprintf(dp, "\nmask ");
dp += 6;
for (i = 0; i < e->size; i++) {
sprintf(dp, "%02x", 0xff & (int) (e->mask[i]));
dp += 2;
}
}
*dp++ = '\n';
*dp = '\0';
}
}
static struct inode *bm_get_inode(struct super_block *sb, int mode)
{
struct inode * inode = new_inode(sb);
if (inode) {
inode->i_ino = get_next_ino();
inode->i_mode = mode;
inode->i_atime = inode->i_mtime = inode->i_ctime =
current_fs_time(inode->i_sb);
}
return inode;
}
static void bm_evict_inode(struct inode *inode)
{
end_writeback(inode);
kfree(inode->i_private);
}
static void kill_node(Node *e)
{
struct dentry *dentry;
write_lock(&entries_lock);
dentry = e->dentry;
if (dentry) {
list_del_init(&e->list);
e->dentry = NULL;
}
write_unlock(&entries_lock);
if (dentry) {
dentry->d_inode->i_nlink--;
d_drop(dentry);
dput(dentry);
simple_release_fs(&bm_mnt, &entry_count);
}
}
static ssize_t
bm_entry_read(struct file * file, char __user * buf, size_t nbytes, loff_t *ppos)
{
Node *e = file->f_path.dentry->d_inode->i_private;
ssize_t res;
char *page;
if (!(page = (char*) __get_free_page(GFP_KERNEL)))
return -ENOMEM;
entry_status(e, page);
res = simple_read_from_buffer(buf, nbytes, ppos, page, strlen(page));
free_page((unsigned long) page);
return res;
}
static ssize_t bm_entry_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
struct dentry *root;
Node *e = file->f_path.dentry->d_inode->i_private;
int res = parse_command(buffer, count);
switch (res) {
case 1: clear_bit(Enabled, &e->flags);
break;
case 2: set_bit(Enabled, &e->flags);
break;
case 3: root = dget(file->f_path.mnt->mnt_sb->s_root);
mutex_lock(&root->d_inode->i_mutex);
kill_node(e);
mutex_unlock(&root->d_inode->i_mutex);
dput(root);
break;
default: return res;
}
return count;
}
static ssize_t bm_register_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
Node *e;
struct inode *inode;
struct dentry *root, *dentry;
struct super_block *sb = file->f_path.mnt->mnt_sb;
int err = 0;
e = create_entry(buffer, count);
if (IS_ERR(e))
return PTR_ERR(e);
root = dget(sb->s_root);
mutex_lock(&root->d_inode->i_mutex);
dentry = lookup_one_len(e->name, root, strlen(e->name));
err = PTR_ERR(dentry);
if (IS_ERR(dentry))
goto out;
err = -EEXIST;
if (dentry->d_inode)
goto out2;
inode = bm_get_inode(sb, S_IFREG | 0644);
err = -ENOMEM;
if (!inode)
goto out2;
err = simple_pin_fs(&bm_fs_type, &bm_mnt, &entry_count);
if (err) {
iput(inode);
inode = NULL;
goto out2;
}
e->dentry = dget(dentry);
inode->i_private = e;
inode->i_fop = &bm_entry_operations;
d_instantiate(dentry, inode);
write_lock(&entries_lock);
list_add(&e->list, &entries);
write_unlock(&entries_lock);
err = 0;
out2:
dput(dentry);
out:
mutex_unlock(&root->d_inode->i_mutex);
dput(root);
if (err) {
kfree(e);
return -EINVAL;
}
return count;
}
static ssize_t
bm_status_read(struct file *file, char __user *buf, size_t nbytes, loff_t *ppos)
{
char *s = enabled ? "enabled\n" : "disabled\n";
return simple_read_from_buffer(buf, nbytes, ppos, s, strlen(s));
}
static ssize_t bm_status_write(struct file * file, const char __user * buffer,
size_t count, loff_t *ppos)
{
int res = parse_command(buffer, count);
struct dentry *root;
switch (res) {
case 1: enabled = 0; break;
case 2: enabled = 1; break;
case 3: root = dget(file->f_path.mnt->mnt_sb->s_root);
mutex_lock(&root->d_inode->i_mutex);
while (!list_empty(&entries))
kill_node(list_entry(entries.next, Node, list));
mutex_unlock(&root->d_inode->i_mutex);
dput(root);
default: return res;
}
return count;
}
static int bm_fill_super(struct super_block * sb, void * data, int silent)
{
static struct tree_descr bm_files[] = {
[2] = {"status", &bm_status_operations, S_IWUSR|S_IRUGO},
[3] = {"register", &bm_register_operations, S_IWUSR},
{""}
};
int err = simple_fill_super(sb, 0x42494e4d, bm_files);
if (!err)
sb->s_op = &s_ops;
return err;
}
static struct dentry *bm_mount(struct file_system_type *fs_type,
int flags, const char *dev_name, void *data)
{
return mount_single(fs_type, flags, data, bm_fill_super);
}
static int __init init_misc_binfmt(void)
{
int err = register_filesystem(&bm_fs_type);
if (!err) {
err = insert_binfmt(&misc_format);
if (err)
unregister_filesystem(&bm_fs_type);
}
return err;
}
static void __exit exit_misc_binfmt(void)
{
unregister_binfmt(&misc_format);
unregister_filesystem(&bm_fs_type);
}
