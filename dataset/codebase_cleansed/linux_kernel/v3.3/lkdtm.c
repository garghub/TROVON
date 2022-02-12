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
int jp_generic_ide_ioctl(ide_drive_t *drive, struct file *file,
struct block_device *bdev, unsigned int cmd,
unsigned long arg)
{
lkdtm_handler();
jprobe_return();
return 0;
}
static enum ctype parse_cp_type(const char *what, size_t count)
{
int i;
for (i = 0; i < ARRAY_SIZE(cp_type); i++) {
if (!strcmp(what, cp_type[i]))
return i + 1;
}
return CT_NONE;
}
static const char *cp_type_to_str(enum ctype type)
{
if (type == CT_NONE || type < 0 || type > ARRAY_SIZE(cp_type))
return "None";
return cp_type[type - 1];
}
static const char *cp_name_to_str(enum cname name)
{
if (name == CN_INVALID || name < 0 || name > ARRAY_SIZE(cp_name))
return "INVALID";
return cp_name[name - 1];
}
static int lkdtm_parse_commandline(void)
{
int i;
unsigned long flags;
if (cpoint_count < 1 || recur_count < 1)
return -EINVAL;
spin_lock_irqsave(&count_lock, flags);
count = cpoint_count;
spin_unlock_irqrestore(&count_lock, flags);
if (!cpoint_type && !cpoint_name)
return 0;
if (!cpoint_type || !cpoint_name)
return -EINVAL;
cptype = parse_cp_type(cpoint_type, strlen(cpoint_type));
if (cptype == CT_NONE)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(cp_name); i++) {
if (!strcmp(cpoint_name, cp_name[i])) {
cpoint = i + 1;
return 0;
}
}
return -EINVAL;
}
static int recursive_loop(int a)
{
char buf[1024];
memset(buf,0xFF,1024);
recur_count--;
if (!recur_count)
return 0;
else
return recursive_loop(a);
}
static void lkdtm_do_action(enum ctype which)
{
switch (which) {
case CT_PANIC:
panic("dumptest");
break;
case CT_BUG:
BUG();
break;
case CT_EXCEPTION:
*((int *) 0) = 0;
break;
case CT_LOOP:
for (;;)
;
break;
case CT_OVERFLOW:
(void) recursive_loop(0);
break;
case CT_CORRUPT_STACK: {
volatile u32 data[8];
volatile u32 *p = data;
p[12] = 0x12345678;
break;
}
case CT_UNALIGNED_LOAD_STORE_WRITE: {
static u8 data[5] __attribute__((aligned(4))) = {1, 2,
3, 4, 5};
u32 *p;
u32 val = 0x12345678;
p = (u32 *)(data + 1);
if (*p == 0)
val = 0x87654321;
*p = val;
break;
}
case CT_OVERWRITE_ALLOCATION: {
size_t len = 1020;
u32 *data = kmalloc(len, GFP_KERNEL);
data[1024 / sizeof(u32)] = 0x12345678;
kfree(data);
break;
}
case CT_WRITE_AFTER_FREE: {
size_t len = 1024;
u32 *data = kmalloc(len, GFP_KERNEL);
kfree(data);
schedule();
memset(data, 0x78, len);
break;
}
case CT_SOFTLOCKUP:
preempt_disable();
for (;;)
cpu_relax();
break;
case CT_HARDLOCKUP:
local_irq_disable();
for (;;)
cpu_relax();
break;
case CT_HUNG_TASK:
set_current_state(TASK_UNINTERRUPTIBLE);
schedule();
break;
case CT_NONE:
default:
break;
}
}
static void lkdtm_handler(void)
{
unsigned long flags;
bool do_it = false;
spin_lock_irqsave(&count_lock, flags);
count--;
printk(KERN_INFO "lkdtm: Crash point %s of type %s hit, trigger in %d rounds\n",
cp_name_to_str(cpoint), cp_type_to_str(cptype), count);
if (count == 0) {
do_it = true;
count = cpoint_count;
}
spin_unlock_irqrestore(&count_lock, flags);
if (do_it)
lkdtm_do_action(cptype);
}
static int lkdtm_register_cpoint(enum cname which)
{
int ret;
cpoint = CN_INVALID;
if (lkdtm.entry != NULL)
unregister_jprobe(&lkdtm);
switch (which) {
case CN_DIRECT:
lkdtm_do_action(cptype);
return 0;
case CN_INT_HARDWARE_ENTRY:
lkdtm.kp.symbol_name = "do_IRQ";
lkdtm.entry = (kprobe_opcode_t*) jp_do_irq;
break;
case CN_INT_HW_IRQ_EN:
lkdtm.kp.symbol_name = "handle_IRQ_event";
lkdtm.entry = (kprobe_opcode_t*) jp_handle_irq_event;
break;
case CN_INT_TASKLET_ENTRY:
lkdtm.kp.symbol_name = "tasklet_action";
lkdtm.entry = (kprobe_opcode_t*) jp_tasklet_action;
break;
case CN_FS_DEVRW:
lkdtm.kp.symbol_name = "ll_rw_block";
lkdtm.entry = (kprobe_opcode_t*) jp_ll_rw_block;
break;
case CN_MEM_SWAPOUT:
lkdtm.kp.symbol_name = "shrink_inactive_list";
lkdtm.entry = (kprobe_opcode_t*) jp_shrink_inactive_list;
break;
case CN_TIMERADD:
lkdtm.kp.symbol_name = "hrtimer_start";
lkdtm.entry = (kprobe_opcode_t*) jp_hrtimer_start;
break;
case CN_SCSI_DISPATCH_CMD:
lkdtm.kp.symbol_name = "scsi_dispatch_cmd";
lkdtm.entry = (kprobe_opcode_t*) jp_scsi_dispatch_cmd;
break;
case CN_IDE_CORE_CP:
#ifdef CONFIG_IDE
lkdtm.kp.symbol_name = "generic_ide_ioctl";
lkdtm.entry = (kprobe_opcode_t*) jp_generic_ide_ioctl;
#else
printk(KERN_INFO "lkdtm: Crash point not available\n");
return -EINVAL;
#endif
break;
default:
printk(KERN_INFO "lkdtm: Invalid Crash Point\n");
return -EINVAL;
}
cpoint = which;
if ((ret = register_jprobe(&lkdtm)) < 0) {
printk(KERN_INFO "lkdtm: Couldn't register jprobe\n");
cpoint = CN_INVALID;
}
return ret;
}
static ssize_t do_register_entry(enum cname which, struct file *f,
const char __user *user_buf, size_t count, loff_t *off)
{
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
cptype = parse_cp_type(buf, count);
free_page((unsigned long) buf);
if (cptype == CT_NONE)
return -EINVAL;
err = lkdtm_register_cpoint(which);
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
n = snprintf(buf, PAGE_SIZE, "Available crash types:\n");
for (i = 0; i < ARRAY_SIZE(cp_type); i++)
n += snprintf(buf + n, PAGE_SIZE - n, "%s\n", cp_type[i]);
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
static ssize_t int_hardware_entry(struct file *f, const char __user *buf,
size_t count, loff_t *off)
{
return do_register_entry(CN_INT_HARDWARE_ENTRY, f, buf, count, off);
}
static ssize_t int_hw_irq_en(struct file *f, const char __user *buf,
size_t count, loff_t *off)
{
return do_register_entry(CN_INT_HW_IRQ_EN, f, buf, count, off);
}
static ssize_t int_tasklet_entry(struct file *f, const char __user *buf,
size_t count, loff_t *off)
{
return do_register_entry(CN_INT_TASKLET_ENTRY, f, buf, count, off);
}
static ssize_t fs_devrw_entry(struct file *f, const char __user *buf,
size_t count, loff_t *off)
{
return do_register_entry(CN_FS_DEVRW, f, buf, count, off);
}
static ssize_t mem_swapout_entry(struct file *f, const char __user *buf,
size_t count, loff_t *off)
{
return do_register_entry(CN_MEM_SWAPOUT, f, buf, count, off);
}
static ssize_t timeradd_entry(struct file *f, const char __user *buf,
size_t count, loff_t *off)
{
return do_register_entry(CN_TIMERADD, f, buf, count, off);
}
static ssize_t scsi_dispatch_cmd_entry(struct file *f,
const char __user *buf, size_t count, loff_t *off)
{
return do_register_entry(CN_SCSI_DISPATCH_CMD, f, buf, count, off);
}
static ssize_t ide_core_cp_entry(struct file *f, const char __user *buf,
size_t count, loff_t *off)
{
return do_register_entry(CN_IDE_CORE_CP, f, buf, count, off);
}
static ssize_t direct_entry(struct file *f, const char __user *user_buf,
size_t count, loff_t *off)
{
enum ctype type;
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
type = parse_cp_type(buf, count);
free_page((unsigned long) buf);
if (type == CT_NONE)
return -EINVAL;
printk(KERN_INFO "lkdtm: Performing direct entry %s\n",
cp_type_to_str(type));
lkdtm_do_action(type);
*off += count;
return count;
}
static int __init lkdtm_module_init(void)
{
int ret = -EINVAL;
int n_debugfs_entries = 1;
int i;
lkdtm_debugfs_root = debugfs_create_dir("provoke-crash", NULL);
if (!lkdtm_debugfs_root) {
printk(KERN_ERR "lkdtm: creating root dir failed\n");
return -ENODEV;
}
#ifdef CONFIG_KPROBES
n_debugfs_entries = ARRAY_SIZE(crash_entries);
#endif
for (i = 0; i < n_debugfs_entries; i++) {
const struct crash_entry *cur = &crash_entries[i];
struct dentry *de;
de = debugfs_create_file(cur->name, 0644, lkdtm_debugfs_root,
NULL, &cur->fops);
if (de == NULL) {
printk(KERN_ERR "lkdtm: could not create %s\n",
cur->name);
goto out_err;
}
}
if (lkdtm_parse_commandline() == -EINVAL) {
printk(KERN_INFO "lkdtm: Invalid command\n");
goto out_err;
}
if (cpoint != CN_INVALID && cptype != CT_NONE) {
ret = lkdtm_register_cpoint(cpoint);
if (ret < 0) {
printk(KERN_INFO "lkdtm: Invalid crash point %d\n",
cpoint);
goto out_err;
}
printk(KERN_INFO "lkdtm: Crash point %s of type %s registered\n",
cpoint_name, cpoint_type);
} else {
printk(KERN_INFO "lkdtm: No crash points registered, enable through debugfs\n");
}
return 0;
out_err:
debugfs_remove_recursive(lkdtm_debugfs_root);
return ret;
}
static void __exit lkdtm_module_exit(void)
{
debugfs_remove_recursive(lkdtm_debugfs_root);
unregister_jprobe(&lkdtm);
printk(KERN_INFO "lkdtm: Crash point unregistered\n");
}
