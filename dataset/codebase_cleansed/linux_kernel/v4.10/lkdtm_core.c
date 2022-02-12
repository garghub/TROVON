static unsigned int jp_do_irq(unsigned int irq)
{
lkdtm_handler();
jprobe_return();
return 0;
}
static irqreturn_t jp_handle_irq_event(unsigned int irq,
struct irqaction *action)
{
lkdtm_handler();
jprobe_return();
return 0;
}
static void jp_tasklet_action(struct softirq_action *a)
{
lkdtm_handler();
jprobe_return();
}
static void jp_ll_rw_block(int rw, int nr, struct buffer_head *bhs[])
{
lkdtm_handler();
jprobe_return();
}
static unsigned long jp_shrink_inactive_list(unsigned long max_scan,
struct zone *zone,
struct scan_control *sc)
{
lkdtm_handler();
jprobe_return();
return 0;
}
static int jp_hrtimer_start(struct hrtimer *timer, ktime_t tim,
const enum hrtimer_mode mode)
{
lkdtm_handler();
jprobe_return();
return 0;
}
static int jp_scsi_dispatch_cmd(struct scsi_cmnd *cmd)
{
lkdtm_handler();
jprobe_return();
return 0;
}
static int jp_generic_ide_ioctl(ide_drive_t *drive, struct file *file,
struct block_device *bdev, unsigned int cmd,
unsigned long arg)
{
lkdtm_handler();
jprobe_return();
return 0;
}
static struct crashtype *find_crashtype(const char *name)
{
int i;
for (i = 0; i < ARRAY_SIZE(crashtypes); i++) {
if (!strcmp(name, crashtypes[i].name))
return &crashtypes[i];
}
return NULL;
}
static noinline void lkdtm_do_action(struct crashtype *crashtype)
{
BUG_ON(!crashtype || !crashtype->func);
crashtype->func();
}
static int lkdtm_register_cpoint(struct crashpoint *crashpoint,
struct crashtype *crashtype)
{
int ret;
if (!crashpoint->jprobe.kp.symbol_name) {
lkdtm_do_action(crashtype);
return 0;
}
if (lkdtm_jprobe != NULL)
unregister_jprobe(lkdtm_jprobe);
lkdtm_crashpoint = crashpoint;
lkdtm_crashtype = crashtype;
lkdtm_jprobe = &crashpoint->jprobe;
ret = register_jprobe(lkdtm_jprobe);
if (ret < 0) {
pr_info("Couldn't register jprobe %s\n",
crashpoint->jprobe.kp.symbol_name);
lkdtm_jprobe = NULL;
lkdtm_crashpoint = NULL;
lkdtm_crashtype = NULL;
}
return ret;
}
static void lkdtm_handler(void)
{
unsigned long flags;
bool do_it = false;
BUG_ON(!lkdtm_crashpoint || !lkdtm_crashtype);
spin_lock_irqsave(&crash_count_lock, flags);
crash_count--;
pr_info("Crash point %s of type %s hit, trigger in %d rounds\n",
lkdtm_crashpoint->name, lkdtm_crashtype->name, crash_count);
if (crash_count == 0) {
do_it = true;
crash_count = cpoint_count;
}
spin_unlock_irqrestore(&crash_count_lock, flags);
if (do_it)
lkdtm_do_action(lkdtm_crashtype);
}
static ssize_t lkdtm_debugfs_entry(struct file *f,
const char __user *user_buf,
size_t count, loff_t *off)
{
struct crashpoint *crashpoint = file_inode(f)->i_private;
struct crashtype *crashtype = NULL;
char *buf;
int err;
if (count >= PAGE_SIZE)
return -EINVAL;
buf = (char *)__get_free_page(GFP_KERNEL);
if (!buf)
return -ENOMEM;
if (copy_from_user(buf, user_buf, count)) {
free_page((unsigned long) buf);
return -EFAULT;
}
buf[count] = '\0';
strim(buf);
crashtype = find_crashtype(buf);
free_page((unsigned long)buf);
if (!crashtype)
return -EINVAL;
err = lkdtm_register_cpoint(crashpoint, crashtype);
if (err < 0)
return err;
*off += count;
return count;
}
static ssize_t lkdtm_debugfs_read(struct file *f, char __user *user_buf,
size_t count, loff_t *off)
{
char *buf;
int i, n, out;
buf = (char *)__get_free_page(GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
n = snprintf(buf, PAGE_SIZE, "Available crash types:\n");
for (i = 0; i < ARRAY_SIZE(crashtypes); i++) {
n += snprintf(buf + n, PAGE_SIZE - n, "%s\n",
crashtypes[i].name);
}
buf[n] = '\0';
out = simple_read_from_buffer(user_buf, count, off,
buf, n);
free_page((unsigned long) buf);
return out;
}
static int lkdtm_debugfs_open(struct inode *inode, struct file *file)
{
return 0;
}
static ssize_t direct_entry(struct file *f, const char __user *user_buf,
size_t count, loff_t *off)
{
struct crashtype *crashtype;
char *buf;
if (count >= PAGE_SIZE)
return -EINVAL;
if (count < 1)
return -EINVAL;
buf = (char *)__get_free_page(GFP_KERNEL);
if (!buf)
return -ENOMEM;
if (copy_from_user(buf, user_buf, count)) {
free_page((unsigned long) buf);
return -EFAULT;
}
buf[count] = '\0';
strim(buf);
crashtype = find_crashtype(buf);
free_page((unsigned long) buf);
if (!crashtype)
return -EINVAL;
pr_info("Performing direct entry %s\n", crashtype->name);
lkdtm_do_action(crashtype);
*off += count;
return count;
}
static int __init lkdtm_module_init(void)
{
struct crashpoint *crashpoint = NULL;
struct crashtype *crashtype = NULL;
int ret = -EINVAL;
int i;
if ((cpoint_type || cpoint_name) && !(cpoint_type && cpoint_name)) {
pr_err("Need both cpoint_type and cpoint_name or neither\n");
return -EINVAL;
}
if (cpoint_type) {
crashtype = find_crashtype(cpoint_type);
if (!crashtype) {
pr_err("Unknown crashtype '%s'\n", cpoint_type);
return -EINVAL;
}
}
if (cpoint_name) {
for (i = 0; i < ARRAY_SIZE(crashpoints); i++) {
if (!strcmp(cpoint_name, crashpoints[i].name))
crashpoint = &crashpoints[i];
}
if (!crashpoint) {
pr_err("Invalid crashpoint %s\n", cpoint_name);
return -EINVAL;
}
}
#ifdef CONFIG_KPROBES
crash_count = cpoint_count;
#endif
lkdtm_bugs_init(&recur_count);
lkdtm_perms_init();
lkdtm_usercopy_init();
lkdtm_debugfs_root = debugfs_create_dir("provoke-crash", NULL);
if (!lkdtm_debugfs_root) {
pr_err("creating root dir failed\n");
return -ENODEV;
}
for (i = 0; i < ARRAY_SIZE(crashpoints); i++) {
struct crashpoint *cur = &crashpoints[i];
struct dentry *de;
de = debugfs_create_file(cur->name, 0644, lkdtm_debugfs_root,
cur, &cur->fops);
if (de == NULL) {
pr_err("could not create crashpoint %s\n", cur->name);
goto out_err;
}
}
if (crashpoint) {
ret = lkdtm_register_cpoint(crashpoint, crashtype);
if (ret < 0) {
pr_info("Invalid crashpoint %s\n", crashpoint->name);
goto out_err;
}
pr_info("Crash point %s of type %s registered\n",
crashpoint->name, cpoint_type);
} else {
pr_info("No crash points registered, enable through debugfs\n");
}
return 0;
out_err:
debugfs_remove_recursive(lkdtm_debugfs_root);
return ret;
}
static void __exit lkdtm_module_exit(void)
{
debugfs_remove_recursive(lkdtm_debugfs_root);
lkdtm_usercopy_exit();
unregister_jprobe(lkdtm_jprobe);
pr_info("Crash point unregistered\n");
}
