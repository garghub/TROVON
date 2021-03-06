static int __init load_ramdisk(char *str)
{
rd_doload = simple_strtol(str,NULL,0) & 3;
return 1;
}
static int __init readonly(char *str)
{
if (*str)
return 0;
root_mountflags |= MS_RDONLY;
return 1;
}
static int __init readwrite(char *str)
{
if (*str)
return 0;
root_mountflags &= ~MS_RDONLY;
return 1;
}
static int match_dev_by_uuid(struct device *dev, const void *data)
{
const struct uuidcmp *cmp = data;
struct hd_struct *part = dev_to_part(dev);
if (!part->info)
goto no_match;
if (strncasecmp(cmp->uuid, part->info->uuid, cmp->len))
goto no_match;
return 1;
no_match:
return 0;
}
static dev_t devt_from_partuuid(const char *uuid_str)
{
dev_t res = 0;
struct uuidcmp cmp;
struct device *dev = NULL;
struct gendisk *disk;
struct hd_struct *part;
int offset = 0;
bool clear_root_wait = false;
char *slash;
cmp.uuid = uuid_str;
slash = strchr(uuid_str, '/');
if (slash) {
char c = 0;
if (sscanf(slash + 1,
"PARTNROFF=%d%c", &offset, &c) != 1) {
clear_root_wait = true;
goto done;
}
cmp.len = slash - uuid_str;
} else {
cmp.len = strlen(uuid_str);
}
if (!cmp.len) {
clear_root_wait = true;
goto done;
}
dev = class_find_device(&block_class, NULL, &cmp,
&match_dev_by_uuid);
if (!dev)
goto done;
res = dev->devt;
if (!offset)
goto no_offset;
res = 0;
disk = part_to_disk(dev_to_part(dev));
part = disk_get_part(disk, dev_to_part(dev)->partno + offset);
if (part) {
res = part_devt(part);
put_device(part_to_dev(part));
}
no_offset:
put_device(dev);
done:
if (clear_root_wait) {
pr_err("VFS: PARTUUID= is invalid.\n"
"Expected PARTUUID=<valid-uuid-id>[/PARTNROFF=%%d]\n");
if (root_wait)
pr_err("Disabling rootwait; root= is invalid.\n");
root_wait = 0;
}
return res;
}
dev_t name_to_dev_t(const char *name)
{
char s[32];
char *p;
dev_t res = 0;
int part;
#ifdef CONFIG_BLOCK
if (strncmp(name, "PARTUUID=", 9) == 0) {
name += 9;
res = devt_from_partuuid(name);
if (!res)
goto fail;
goto done;
}
#endif
if (strncmp(name, "/dev/", 5) != 0) {
unsigned maj, min, offset;
char dummy;
if ((sscanf(name, "%u:%u%c", &maj, &min, &dummy) == 2) ||
(sscanf(name, "%u:%u:%u:%c", &maj, &min, &offset, &dummy) == 3)) {
res = MKDEV(maj, min);
if (maj != MAJOR(res) || min != MINOR(res))
goto fail;
} else {
res = new_decode_dev(simple_strtoul(name, &p, 16));
if (*p)
goto fail;
}
goto done;
}
name += 5;
res = Root_NFS;
if (strcmp(name, "nfs") == 0)
goto done;
res = Root_RAM0;
if (strcmp(name, "ram") == 0)
goto done;
if (strlen(name) > 31)
goto fail;
strcpy(s, name);
for (p = s; *p; p++)
if (*p == '/')
*p = '!';
res = blk_lookup_devt(s, 0);
if (res)
goto done;
while (p > s && isdigit(p[-1]))
p--;
if (p == s || !*p || *p == '0')
goto fail;
part = simple_strtoul(p, NULL, 10);
*p = '\0';
res = blk_lookup_devt(s, part);
if (res)
goto done;
if (p < s + 2 || !isdigit(p[-2]) || p[-1] != 'p')
goto fail;
p[-1] = '\0';
res = blk_lookup_devt(s, part);
if (res)
goto done;
fail:
return 0;
done:
return res;
}
static int __init root_dev_setup(char *line)
{
strlcpy(saved_root_name, line, sizeof(saved_root_name));
return 1;
}
static int __init rootwait_setup(char *str)
{
if (*str)
return 0;
root_wait = 1;
return 1;
}
static int __init root_data_setup(char *str)
{
root_mount_data = str;
return 1;
}
static int __init fs_names_setup(char *str)
{
root_fs_names = str;
return 1;
}
static int __init root_delay_setup(char *str)
{
root_delay = simple_strtoul(str, NULL, 0);
return 1;
}
static void __init get_fs_names(char *page)
{
char *s = page;
if (root_fs_names) {
strcpy(page, root_fs_names);
while (*s++) {
if (s[-1] == ',')
s[-1] = '\0';
}
} else {
int len = get_filesystem_list(page);
char *p, *next;
page[len] = '\0';
for (p = page-1; p; p = next) {
next = strchr(++p, '\n');
if (*p++ != '\t')
continue;
while ((*s++ = *p++) != '\n')
;
s[-1] = '\0';
}
}
*s = '\0';
}
static int __init do_mount_root(char *name, char *fs, int flags, void *data)
{
struct super_block *s;
int err = sys_mount(name, "/root", fs, flags, data);
if (err)
return err;
sys_chdir("/root");
s = current->fs->pwd.dentry->d_sb;
ROOT_DEV = s->s_dev;
printk(KERN_INFO
"VFS: Mounted root (%s filesystem)%s on device %u:%u.\n",
s->s_type->name,
s->s_flags & MS_RDONLY ? " readonly" : "",
MAJOR(ROOT_DEV), MINOR(ROOT_DEV));
return 0;
}
void __init mount_block_root(char *name, int flags)
{
struct page *page = alloc_page(GFP_KERNEL |
__GFP_NOTRACK_FALSE_POSITIVE);
char *fs_names = page_address(page);
char *p;
#ifdef CONFIG_BLOCK
char b[BDEVNAME_SIZE];
#else
const char *b = name;
#endif
get_fs_names(fs_names);
retry:
for (p = fs_names; *p; p += strlen(p)+1) {
int err = do_mount_root(name, p, flags, root_mount_data);
switch (err) {
case 0:
goto out;
case -EACCES:
case -EINVAL:
continue;
}
#ifdef CONFIG_BLOCK
__bdevname(ROOT_DEV, b);
#endif
printk("VFS: Cannot open root device \"%s\" or %s: error %d\n",
root_device_name, b, err);
printk("Please append a correct \"root=\" boot option; here are the available partitions:\n");
printk_all_partitions();
#ifdef CONFIG_DEBUG_BLOCK_EXT_DEVT
printk("DEBUG_BLOCK_EXT_DEVT is enabled, you need to specify "
"explicit textual name for \"root=\" boot option.\n");
#endif
panic("VFS: Unable to mount root fs on %s", b);
}
if (!(flags & MS_RDONLY)) {
flags |= MS_RDONLY;
goto retry;
}
printk("List of all partitions:\n");
printk_all_partitions();
printk("No filesystem could mount root, tried: ");
for (p = fs_names; *p; p += strlen(p)+1)
printk(" %s", p);
printk("\n");
#ifdef CONFIG_BLOCK
__bdevname(ROOT_DEV, b);
#endif
panic("VFS: Unable to mount root fs on %s", b);
out:
put_page(page);
}
static int __init mount_nfs_root(void)
{
char *root_dev, *root_data;
unsigned int timeout;
int try, err;
err = nfs_root_data(&root_dev, &root_data);
if (err != 0)
return 0;
timeout = NFSROOT_TIMEOUT_MIN;
for (try = 1; ; try++) {
err = do_mount_root(root_dev, "nfs",
root_mountflags, root_data);
if (err == 0)
return 1;
if (try > NFSROOT_RETRY_MAX)
break;
ssleep(timeout);
timeout <<= 1;
if (timeout > NFSROOT_TIMEOUT_MAX)
timeout = NFSROOT_TIMEOUT_MAX;
}
return 0;
}
void __init change_floppy(char *fmt, ...)
{
struct termios termios;
char buf[80];
char c;
int fd;
va_list args;
va_start(args, fmt);
vsprintf(buf, fmt, args);
va_end(args);
fd = sys_open("/dev/root", O_RDWR | O_NDELAY, 0);
if (fd >= 0) {
sys_ioctl(fd, FDEJECT, 0);
sys_close(fd);
}
printk(KERN_NOTICE "VFS: Insert %s and press ENTER\n", buf);
fd = sys_open("/dev/console", O_RDWR, 0);
if (fd >= 0) {
sys_ioctl(fd, TCGETS, (long)&termios);
termios.c_lflag &= ~ICANON;
sys_ioctl(fd, TCSETSF, (long)&termios);
sys_read(fd, &c, 1);
termios.c_lflag |= ICANON;
sys_ioctl(fd, TCSETSF, (long)&termios);
sys_close(fd);
}
}
void __init mount_root(void)
{
#ifdef CONFIG_ROOT_NFS
if (ROOT_DEV == Root_NFS) {
if (mount_nfs_root())
return;
printk(KERN_ERR "VFS: Unable to mount root fs via NFS, trying floppy.\n");
ROOT_DEV = Root_FD0;
}
#endif
#ifdef CONFIG_BLK_DEV_FD
if (MAJOR(ROOT_DEV) == FLOPPY_MAJOR) {
if (rd_doload==2) {
if (rd_load_disk(1)) {
ROOT_DEV = Root_RAM1;
root_device_name = NULL;
}
} else
change_floppy("root floppy");
}
#endif
#ifdef CONFIG_BLOCK
{
int err = create_dev("/dev/root", ROOT_DEV);
if (err < 0)
pr_emerg("Failed to create /dev/root: %d\n", err);
mount_block_root("/dev/root", root_mountflags);
}
#endif
}
void __init prepare_namespace(void)
{
int is_floppy;
if (root_delay) {
printk(KERN_INFO "Waiting %d sec before mounting root device...\n",
root_delay);
ssleep(root_delay);
}
wait_for_device_probe();
md_run_setup();
if (saved_root_name[0]) {
root_device_name = saved_root_name;
if (!strncmp(root_device_name, "mtd", 3) ||
!strncmp(root_device_name, "ubi", 3)) {
mount_block_root(root_device_name, root_mountflags);
goto out;
}
ROOT_DEV = name_to_dev_t(root_device_name);
if (strncmp(root_device_name, "/dev/", 5) == 0)
root_device_name += 5;
}
if (initrd_load())
goto out;
if ((ROOT_DEV == 0) && root_wait) {
printk(KERN_INFO "Waiting for root device %s...\n",
saved_root_name);
while (driver_probe_done() != 0 ||
(ROOT_DEV = name_to_dev_t(saved_root_name)) == 0)
msleep(5);
async_synchronize_full();
}
is_floppy = MAJOR(ROOT_DEV) == FLOPPY_MAJOR;
if (is_floppy && rd_doload && rd_load_disk(0))
ROOT_DEV = Root_RAM0;
mount_root();
out:
devtmpfs_mount("dev");
sys_mount(".", "/", NULL, MS_MOVE, NULL);
sys_chroot(".");
}
static struct dentry *rootfs_mount(struct file_system_type *fs_type,
int flags, const char *dev_name, void *data)
{
static unsigned long once;
void *fill = ramfs_fill_super;
if (test_and_set_bit(0, &once))
return ERR_PTR(-ENODEV);
if (IS_ENABLED(CONFIG_TMPFS) && is_tmpfs)
fill = shmem_fill_super;
return mount_nodev(fs_type, flags, data, fill);
}
int __init init_rootfs(void)
{
int err = register_filesystem(&rootfs_fs_type);
if (err)
return err;
if (IS_ENABLED(CONFIG_TMPFS) && !saved_root_name[0] &&
(!root_fs_names || strstr(root_fs_names, "tmpfs"))) {
err = shmem_init();
is_tmpfs = true;
} else {
err = init_ramfs_fs();
}
if (err)
unregister_filesystem(&rootfs_fs_type);
return err;
}
