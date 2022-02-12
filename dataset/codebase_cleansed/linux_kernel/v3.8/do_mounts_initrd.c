static int __init no_initrd(char *str)
{
mount_initrd = 0;
return 1;
}
static int init_linuxrc(struct subprocess_info *info, struct cred *new)
{
sys_unshare(CLONE_FS | CLONE_FILES);
sys_open("/dev/console", O_RDWR, 0);
sys_dup(0);
sys_dup(0);
sys_chdir("/root");
sys_mount(".", "/", NULL, MS_MOVE, NULL);
sys_chroot(".");
sys_setsid();
return 0;
}
static void __init handle_initrd(void)
{
static char *argv[] = { "linuxrc", NULL, };
extern char *envp_init[];
int error;
real_root_dev = new_encode_dev(ROOT_DEV);
create_dev("/dev/root.old", Root_RAM0);
mount_block_root("/dev/root.old", root_mountflags & ~MS_RDONLY);
sys_mkdir("/old", 0700);
sys_chdir("/old");
current->flags |= PF_FREEZER_SKIP;
call_usermodehelper_fns("/linuxrc", argv, envp_init, UMH_WAIT_PROC,
init_linuxrc, NULL, NULL);
current->flags &= ~PF_FREEZER_SKIP;
sys_mount("..", ".", NULL, MS_MOVE, NULL);
sys_chroot("..");
if (new_decode_dev(real_root_dev) == Root_RAM0) {
sys_chdir("/old");
return;
}
sys_chdir("/");
ROOT_DEV = new_decode_dev(real_root_dev);
mount_root();
printk(KERN_NOTICE "Trying to move old root to /initrd ... ");
error = sys_mount("/old", "/root/initrd", NULL, MS_MOVE, NULL);
if (!error)
printk("okay\n");
else {
int fd = sys_open("/dev/root.old", O_RDWR, 0);
if (error == -ENOENT)
printk("/initrd does not exist. Ignored.\n");
else
printk("failed\n");
printk(KERN_NOTICE "Unmounting old root\n");
sys_umount("/old", MNT_DETACH);
printk(KERN_NOTICE "Trying to free ramdisk memory ... ");
if (fd < 0) {
error = fd;
} else {
error = sys_ioctl(fd, BLKFLSBUF, 0);
sys_close(fd);
}
printk(!error ? "okay\n" : "failed\n");
}
}
int __init initrd_load(void)
{
if (mount_initrd) {
create_dev("/dev/ram", Root_RAM0);
if (rd_load_image("/initrd.image") && ROOT_DEV != Root_RAM0) {
sys_unlink("/initrd.image");
handle_initrd();
return 1;
}
}
sys_unlink("/initrd.image");
return 0;
}
