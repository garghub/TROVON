static void report_load(const char *origin, struct file *file, char *operation)
{
char *cmdline, *pathname;
pathname = kstrdup_quotable_file(file, GFP_KERNEL);
cmdline = kstrdup_quotable_cmdline(current, GFP_KERNEL);
pr_notice("%s %s obj=%s%s%s pid=%d cmdline=%s%s%s\n",
origin, operation,
(pathname && pathname[0] != '<') ? "\"" : "",
pathname,
(pathname && pathname[0] != '<') ? "\"" : "",
task_pid_nr(current),
cmdline ? "\"" : "", cmdline, cmdline ? "\"" : "");
kfree(cmdline);
kfree(pathname);
}
static void check_pinning_enforcement(struct super_block *mnt_sb)
{
bool ro = false;
if (mnt_sb->s_bdev) {
ro = bdev_read_only(mnt_sb->s_bdev);
pr_info("dev(%u,%u): %s\n",
MAJOR(mnt_sb->s_bdev->bd_dev),
MINOR(mnt_sb->s_bdev->bd_dev),
ro ? "read-only" : "writable");
} else
pr_info("mnt_sb lacks block device, treating as: writable\n");
if (!ro) {
if (!register_sysctl_paths(loadpin_sysctl_path,
loadpin_sysctl_table))
pr_notice("sysctl registration failed!\n");
else
pr_info("load pinning can be disabled.\n");
} else
pr_info("load pinning engaged.\n");
}
static void check_pinning_enforcement(struct super_block *mnt_sb)
{
pr_info("load pinning engaged.\n");
}
static void loadpin_sb_free_security(struct super_block *mnt_sb)
{
if (!IS_ERR_OR_NULL(pinned_root) && mnt_sb == pinned_root) {
pinned_root = ERR_PTR(-EIO);
pr_info("umount pinned fs: refusing further loads\n");
}
}
static int loadpin_read_file(struct file *file, enum kernel_read_file_id id)
{
struct super_block *load_root;
const char *origin = kernel_read_file_id_str(id);
if (!file) {
if (!enabled) {
report_load(origin, NULL, "old-api-pinning-ignored");
return 0;
}
report_load(origin, NULL, "old-api-denied");
return -EPERM;
}
load_root = file->f_path.mnt->mnt_sb;
spin_lock(&pinned_root_spinlock);
if (!pinned_root) {
pinned_root = load_root;
spin_unlock(&pinned_root_spinlock);
check_pinning_enforcement(pinned_root);
report_load(origin, file, "pinned");
} else {
spin_unlock(&pinned_root_spinlock);
}
if (IS_ERR_OR_NULL(pinned_root) || load_root != pinned_root) {
if (unlikely(!enabled)) {
report_load(origin, file, "pinning-ignored");
return 0;
}
report_load(origin, file, "denied");
return -EPERM;
}
return 0;
}
void __init loadpin_add_hooks(void)
{
pr_info("ready to pin (currently %sabled)", enabled ? "en" : "dis");
security_add_hooks(loadpin_hooks, ARRAY_SIZE(loadpin_hooks));
}
