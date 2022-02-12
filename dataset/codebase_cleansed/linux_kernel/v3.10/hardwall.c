static int __init noudn(char *str)
{
pr_info("User-space UDN access is disabled\n");
hardwall_types[HARDWALL_UDN].disabled = 1;
return 0;
}
static int __init noidn(char *str)
{
pr_info("User-space IDN access is disabled\n");
hardwall_types[HARDWALL_IDN].disabled = 1;
return 0;
}
static int __init noipi(char *str)
{
pr_info("User-space IPI access is disabled\n");
hardwall_types[HARDWALL_IPI].disabled = 1;
return 0;
}
static int contains(struct hardwall_info *r, int x, int y)
{
return (x >= r->ulhc_x && x < r->ulhc_x + r->width) &&
(y >= r->ulhc_y && y < r->ulhc_y + r->height);
}
static int check_rectangle(struct hardwall_info *r, struct cpumask *mask)
{
int x, y, cpu, ulhc, lrhc;
ulhc = find_first_bit(cpumask_bits(mask), nr_cpumask_bits);
lrhc = find_last_bit(cpumask_bits(mask), nr_cpumask_bits);
r->ulhc_x = cpu_x(ulhc);
r->ulhc_y = cpu_y(ulhc);
r->width = cpu_x(lrhc) - r->ulhc_x + 1;
r->height = cpu_y(lrhc) - r->ulhc_y + 1;
if (r->width <= 0 || r->height <= 0)
return -EINVAL;
for (y = 0, cpu = 0; y < smp_height; ++y)
for (x = 0; x < smp_width; ++x, ++cpu)
if (cpumask_test_cpu(cpu, mask) != contains(r, x, y))
return -EINVAL;
return 0;
}
static inline int xdn_which_interrupt(struct hardwall_type *hwt)
{
#ifndef __tilepro__
if (hwt->is_idn)
return INT_IDN_FIREWALL;
#endif
return INT_UDN_FIREWALL;
}
static void enable_firewall_interrupts(struct hardwall_type *hwt)
{
arch_local_irq_unmask_now(xdn_which_interrupt(hwt));
}
static void disable_firewall_interrupts(struct hardwall_type *hwt)
{
arch_local_irq_mask_now(xdn_which_interrupt(hwt));
}
static void hardwall_setup_func(void *info)
{
struct hardwall_info *r = info;
struct hardwall_type *hwt = r->type;
int cpu = smp_processor_id();
int x = cpu % smp_width;
int y = cpu / smp_width;
int bits = 0;
if (x == r->ulhc_x)
bits |= W_PROTECT;
if (x == r->ulhc_x + r->width - 1)
bits |= E_PROTECT;
if (y == r->ulhc_y)
bits |= N_PROTECT;
if (y == r->ulhc_y + r->height - 1)
bits |= S_PROTECT;
BUG_ON(bits == 0);
mtspr_XDN(hwt, DIRECTION_PROTECT, bits);
enable_firewall_interrupts(hwt);
}
static void hardwall_protect_rectangle(struct hardwall_info *r)
{
int x, y, cpu, delta;
struct cpumask rect_cpus;
cpumask_clear(&rect_cpus);
cpu = r->ulhc_y * smp_width + r->ulhc_x;
delta = (r->height - 1) * smp_width;
for (x = 0; x < r->width; ++x, ++cpu) {
cpu_online_set(cpu, &rect_cpus);
cpu_online_set(cpu + delta, &rect_cpus);
}
cpu -= r->width;
delta = r->width - 1;
for (y = 0; y < r->height; ++y, cpu += smp_width) {
cpu_online_set(cpu, &rect_cpus);
cpu_online_set(cpu + delta, &rect_cpus);
}
on_each_cpu_mask(&rect_cpus, hardwall_setup_func, r, 1);
}
void __kprobes do_hardwall_trap(struct pt_regs* regs, int fault_num)
{
struct hardwall_info *rect;
struct hardwall_type *hwt;
struct task_struct *p;
struct siginfo info;
int cpu = smp_processor_id();
int found_processes;
unsigned long flags;
struct pt_regs *old_regs = set_irq_regs(regs);
irq_enter();
switch (fault_num) {
#ifndef __tilepro__
case INT_IDN_FIREWALL:
hwt = &hardwall_types[HARDWALL_IDN];
break;
#endif
case INT_UDN_FIREWALL:
hwt = &hardwall_types[HARDWALL_UDN];
break;
default:
BUG();
}
BUG_ON(hwt->disabled);
spin_lock_irqsave(&hwt->lock, flags);
list_for_each_entry(rect, &hwt->list, list) {
if (cpumask_test_cpu(cpu, &rect->cpumask))
break;
}
BUG_ON(&rect->list == &hwt->list);
if (rect->teardown_in_progress) {
pr_notice("cpu %d: detected %s hardwall violation %#lx"
" while teardown already in progress\n",
cpu, hwt->name,
(long)mfspr_XDN(hwt, DIRECTION_PROTECT));
goto done;
}
rect->teardown_in_progress = 1;
wmb();
pr_notice("cpu %d: detected %s hardwall violation %#lx...\n",
cpu, hwt->name, (long)mfspr_XDN(hwt, DIRECTION_PROTECT));
info.si_signo = SIGILL;
info.si_errno = 0;
info.si_code = ILL_HARDWALL;
found_processes = 0;
list_for_each_entry(p, &rect->task_head,
thread.hardwall[hwt->index].list) {
BUG_ON(p->thread.hardwall[hwt->index].info != rect);
if (!(p->flags & PF_EXITING)) {
found_processes = 1;
pr_notice("hardwall: killing %d\n", p->pid);
do_send_sig_info(info.si_signo, &info, p, false);
}
}
if (!found_processes)
pr_notice("hardwall: no associated processes!\n");
done:
spin_unlock_irqrestore(&hwt->lock, flags);
disable_firewall_interrupts(hwt);
irq_exit();
set_irq_regs(old_regs);
}
void grant_hardwall_mpls(struct hardwall_type *hwt)
{
#ifndef __tilepro__
if (!hwt->is_xdn) {
__insn_mtspr(SPR_MPL_IPI_0_SET_0, 1);
return;
}
#endif
mtspr_MPL_XDN(hwt, ACCESS_SET_0, 1);
mtspr_MPL_XDN(hwt, AVAIL_SET_0, 1);
mtspr_MPL_XDN(hwt, COMPLETE_SET_0, 1);
mtspr_MPL_XDN(hwt, TIMER_SET_0, 1);
#if !CHIP_HAS_REV1_XDN()
mtspr_MPL_XDN(hwt, REFILL_SET_0, 1);
mtspr_MPL_XDN(hwt, CA_SET_0, 1);
#endif
}
void restrict_hardwall_mpls(struct hardwall_type *hwt)
{
#ifndef __tilepro__
if (!hwt->is_xdn) {
__insn_mtspr(SPR_MPL_IPI_0_SET_1, 1);
return;
}
#endif
mtspr_MPL_XDN(hwt, ACCESS_SET_1, 1);
mtspr_MPL_XDN(hwt, AVAIL_SET_1, 1);
mtspr_MPL_XDN(hwt, COMPLETE_SET_1, 1);
mtspr_MPL_XDN(hwt, TIMER_SET_1, 1);
#if !CHIP_HAS_REV1_XDN()
mtspr_MPL_XDN(hwt, REFILL_SET_1, 1);
mtspr_MPL_XDN(hwt, CA_SET_1, 1);
#endif
}
void hardwall_switch_tasks(struct task_struct *prev,
struct task_struct *next)
{
int i;
for (i = 0; i < HARDWALL_TYPES; ++i) {
if (prev->thread.hardwall[i].info != NULL) {
if (next->thread.hardwall[i].info == NULL)
restrict_hardwall_mpls(&hardwall_types[i]);
} else if (next->thread.hardwall[i].info != NULL) {
grant_hardwall_mpls(&hardwall_types[i]);
}
}
}
int hardwall_ipi_valid(int cpu)
{
#ifdef __tilegx__
struct hardwall_info *info =
current->thread.hardwall[HARDWALL_IPI].info;
return info && cpumask_test_cpu(cpu, &info->cpumask);
#else
return 0;
#endif
}
static struct hardwall_info *hardwall_create(struct hardwall_type *hwt,
size_t size,
const unsigned char __user *bits)
{
struct hardwall_info *iter, *info;
struct cpumask mask;
unsigned long flags;
int rc;
if (size > PAGE_SIZE)
return ERR_PTR(-EINVAL);
if (copy_from_user(&mask, bits, min(sizeof(struct cpumask), size)))
return ERR_PTR(-EFAULT);
if (size < sizeof(struct cpumask)) {
memset((char *)&mask + size, 0, sizeof(struct cpumask) - size);
} else if (size > sizeof(struct cpumask)) {
size_t i;
for (i = sizeof(struct cpumask); i < size; ++i) {
char c;
if (get_user(c, &bits[i]))
return ERR_PTR(-EFAULT);
if (c)
return ERR_PTR(-EINVAL);
}
}
info = kmalloc(sizeof(struct hardwall_info),
GFP_KERNEL | __GFP_ZERO);
if (info == NULL)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&info->task_head);
info->type = hwt;
cpumask_copy(&info->cpumask, &mask);
info->id = find_first_bit(cpumask_bits(&mask), nr_cpumask_bits);
if (hwt->is_xdn) {
rc = check_rectangle(info, &mask);
if (rc != 0) {
kfree(info);
return ERR_PTR(rc);
}
}
spin_lock_irqsave(&hwt->lock, flags);
list_for_each_entry(iter, &hwt->list, list) {
if (cpumask_intersects(&iter->cpumask, &info->cpumask)) {
spin_unlock_irqrestore(&hwt->lock, flags);
kfree(info);
return ERR_PTR(-EBUSY);
}
}
list_add_tail(&info->list, &hwt->list);
spin_unlock_irqrestore(&hwt->lock, flags);
if (hwt->is_xdn)
hardwall_protect_rectangle(info);
hardwall_add_proc(info);
return info;
}
static int hardwall_activate(struct hardwall_info *info)
{
int cpu;
unsigned long flags;
struct task_struct *p = current;
struct thread_struct *ts = &p->thread;
struct hardwall_type *hwt;
if (info == NULL)
return -ENODATA;
if (info->teardown_in_progress)
return -EINVAL;
if (cpumask_weight(&p->cpus_allowed) != 1)
return -EPERM;
cpu = smp_processor_id();
BUG_ON(cpumask_first(&p->cpus_allowed) != cpu);
if (!cpumask_test_cpu(cpu, &info->cpumask))
return -EINVAL;
hwt = info->type;
if (ts->hardwall[hwt->index].info) {
BUG_ON(ts->hardwall[hwt->index].info != info);
return 0;
}
ts->hardwall[hwt->index].info = info;
spin_lock_irqsave(&hwt->lock, flags);
list_add(&ts->hardwall[hwt->index].list, &info->task_head);
spin_unlock_irqrestore(&hwt->lock, flags);
grant_hardwall_mpls(hwt);
printk(KERN_DEBUG "Pid %d (%s) activated for %s hardwall: cpu %d\n",
p->pid, p->comm, hwt->name, cpu);
return 0;
}
static void _hardwall_deactivate(struct hardwall_type *hwt,
struct task_struct *task)
{
struct thread_struct *ts = &task->thread;
if (cpumask_weight(&task->cpus_allowed) != 1) {
pr_err("pid %d (%s) releasing %s hardwall with"
" an affinity mask containing %d cpus!\n",
task->pid, task->comm, hwt->name,
cpumask_weight(&task->cpus_allowed));
BUG();
}
BUG_ON(ts->hardwall[hwt->index].info == NULL);
ts->hardwall[hwt->index].info = NULL;
list_del(&ts->hardwall[hwt->index].list);
if (task == current)
restrict_hardwall_mpls(hwt);
}
static int hardwall_deactivate(struct hardwall_type *hwt,
struct task_struct *task)
{
unsigned long flags;
int activated;
spin_lock_irqsave(&hwt->lock, flags);
activated = (task->thread.hardwall[hwt->index].info != NULL);
if (activated)
_hardwall_deactivate(hwt, task);
spin_unlock_irqrestore(&hwt->lock, flags);
if (!activated)
return -EINVAL;
printk(KERN_DEBUG "Pid %d (%s) deactivated for %s hardwall: cpu %d\n",
task->pid, task->comm, hwt->name, smp_processor_id());
return 0;
}
void hardwall_deactivate_all(struct task_struct *task)
{
int i;
for (i = 0; i < HARDWALL_TYPES; ++i)
if (task->thread.hardwall[i].info)
hardwall_deactivate(&hardwall_types[i], task);
}
static void stop_xdn_switch(void *arg)
{
#if !CHIP_HAS_REV1_XDN()
__insn_mtspr(SPR_UDN_SP_FREEZE,
SPR_UDN_SP_FREEZE__SP_FRZ_MASK |
SPR_UDN_SP_FREEZE__DEMUX_FRZ_MASK |
SPR_UDN_SP_FREEZE__NON_DEST_EXT_MASK);
#else
struct hardwall_type *hwt = arg;
unsigned long protect = mfspr_XDN(hwt, DIRECTION_PROTECT);
mtspr_XDN(hwt, DIRECTION_PROTECT, (protect | C_PROTECT) << 5);
#endif
}
static void empty_xdn_demuxes(struct hardwall_type *hwt)
{
#ifndef __tilepro__
if (hwt->is_idn) {
while (__insn_mfspr(SPR_IDN_DATA_AVAIL) & (1 << 0))
(void) __tile_idn0_receive();
while (__insn_mfspr(SPR_IDN_DATA_AVAIL) & (1 << 1))
(void) __tile_idn1_receive();
return;
}
#endif
while (__insn_mfspr(SPR_UDN_DATA_AVAIL) & (1 << 0))
(void) __tile_udn0_receive();
while (__insn_mfspr(SPR_UDN_DATA_AVAIL) & (1 << 1))
(void) __tile_udn1_receive();
while (__insn_mfspr(SPR_UDN_DATA_AVAIL) & (1 << 2))
(void) __tile_udn2_receive();
while (__insn_mfspr(SPR_UDN_DATA_AVAIL) & (1 << 3))
(void) __tile_udn3_receive();
}
static void drain_xdn_switch(void *arg)
{
struct hardwall_info *info = arg;
struct hardwall_type *hwt = info->type;
#if CHIP_HAS_REV1_XDN()
int pending = mfspr_XDN(hwt, PENDING);
while (pending--) {
empty_xdn_demuxes(hwt);
if (hwt->is_idn)
__tile_idn_send(0);
else
__tile_udn_send(0);
}
atomic_dec(&info->xdn_pending_count);
while (atomic_read(&info->xdn_pending_count))
empty_xdn_demuxes(hwt);
#else
int i;
int from_tile_words, ca_count;
for (i = 0; i < 5; i++) {
int words, j;
__insn_mtspr(SPR_UDN_SP_FIFO_SEL, i);
words = __insn_mfspr(SPR_UDN_SP_STATE) & 0xF;
for (j = 0; j < words; j++)
(void) __insn_mfspr(SPR_UDN_SP_FIFO_DATA);
BUG_ON((__insn_mfspr(SPR_UDN_SP_STATE) & 0xF) != 0);
}
from_tile_words = (__insn_mfspr(SPR_UDN_DEMUX_STATUS) >> 10) & 0x3;
for (i = 0; i < from_tile_words; i++)
(void) __insn_mfspr(SPR_UDN_DEMUX_WRITE_FIFO);
empty_xdn_demuxes(hwt);
ca_count = __insn_mfspr(SPR_UDN_DEMUX_CA_COUNT);
for (i = 0; i < ca_count; i++)
(void) __insn_mfspr(SPR_UDN_CA_DATA);
BUG_ON(__insn_mfspr(SPR_UDN_DEMUX_CA_COUNT) != 0);
__insn_mtspr(SPR_UDN_DEMUX_CTL, 1);
for (i = 0; i < 5; i++) {
__insn_mtspr(SPR_UDN_SP_FIFO_SEL, i);
__insn_mtspr(SPR_UDN_SP_STATE, 0xc3000);
}
#endif
}
static void reset_xdn_network_state(struct hardwall_type *hwt)
{
if (hwt->disabled)
return;
mtspr_XDN(hwt, DIRECTION_PROTECT, 0);
mtspr_XDN(hwt, AVAIL_EN, 0);
mtspr_XDN(hwt, DEADLOCK_TIMEOUT, 0);
#if !CHIP_HAS_REV1_XDN()
{
unsigned int cpu = smp_processor_id();
unsigned int x = cpu % smp_width;
unsigned int y = cpu / smp_width;
__insn_mtspr(SPR_UDN_TILE_COORD, (x << 18) | (y << 7));
}
__insn_mtspr(SPR_UDN_TAG_VALID, 0xf);
__insn_mtspr(SPR_UDN_TAG_0, (1 << 0));
__insn_mtspr(SPR_UDN_TAG_1, (1 << 1));
__insn_mtspr(SPR_UDN_TAG_2, (1 << 2));
__insn_mtspr(SPR_UDN_TAG_3, (1 << 3));
__insn_mtspr(SPR_UDN_REFILL_EN, 0);
__insn_mtspr(SPR_UDN_DEMUX_QUEUE_SEL, 0);
__insn_mtspr(SPR_UDN_SP_FIFO_SEL, 0);
__insn_mtspr(SPR_UDN_SP_FREEZE, 0);
#endif
}
void reset_network_state(void)
{
reset_xdn_network_state(&hardwall_types[HARDWALL_UDN]);
#ifndef __tilepro__
reset_xdn_network_state(&hardwall_types[HARDWALL_IDN]);
#endif
}
static void restart_xdn_switch(void *arg)
{
struct hardwall_type *hwt = arg;
#if CHIP_HAS_REV1_XDN()
empty_xdn_demuxes(hwt);
#endif
reset_xdn_network_state(hwt);
disable_firewall_interrupts(hwt);
}
static void hardwall_destroy(struct hardwall_info *info)
{
struct task_struct *task;
struct hardwall_type *hwt;
unsigned long flags;
if (info == NULL)
return;
hwt = info->type;
info->teardown_in_progress = 1;
spin_lock_irqsave(&hwt->lock, flags);
list_for_each_entry(task, &info->task_head,
thread.hardwall[hwt->index].list)
_hardwall_deactivate(hwt, task);
spin_unlock_irqrestore(&hwt->lock, flags);
if (hwt->is_xdn) {
printk(KERN_DEBUG
"Clearing %s hardwall rectangle %dx%d %d,%d\n",
hwt->name, info->width, info->height,
info->ulhc_x, info->ulhc_y);
on_each_cpu_mask(&info->cpumask, stop_xdn_switch, hwt, 1);
#if CHIP_HAS_REV1_XDN()
atomic_set(&info->xdn_pending_count,
cpumask_weight(&info->cpumask));
on_each_cpu_mask(&info->cpumask, drain_xdn_switch, info, 0);
#else
on_each_cpu_mask(&info->cpumask, drain_xdn_switch, info, 1);
#endif
on_each_cpu_mask(&info->cpumask, restart_xdn_switch, hwt, 1);
}
hardwall_remove_proc(info);
spin_lock_irqsave(&hwt->lock, flags);
BUG_ON(!list_empty(&info->task_head));
list_del(&info->list);
spin_unlock_irqrestore(&hwt->lock, flags);
kfree(info);
}
static int hardwall_proc_show(struct seq_file *sf, void *v)
{
struct hardwall_info *info = sf->private;
char buf[256];
int rc = cpulist_scnprintf(buf, sizeof(buf), &info->cpumask);
buf[rc++] = '\n';
seq_write(sf, buf, rc);
return 0;
}
static int hardwall_proc_open(struct inode *inode,
struct file *file)
{
return single_open(file, hardwall_proc_show, PDE_DATA(inode));
}
static void hardwall_add_proc(struct hardwall_info *info)
{
char buf[64];
snprintf(buf, sizeof(buf), "%d", info->id);
proc_create_data(buf, 0444, info->type->proc_dir,
&hardwall_proc_fops, info);
}
static void hardwall_remove_proc(struct hardwall_info *info)
{
char buf[64];
snprintf(buf, sizeof(buf), "%d", info->id);
remove_proc_entry(buf, info->type->proc_dir);
}
int proc_pid_hardwall(struct task_struct *task, char *buffer)
{
int i;
int n = 0;
for (i = 0; i < HARDWALL_TYPES; ++i) {
struct hardwall_info *info = task->thread.hardwall[i].info;
if (info)
n += sprintf(&buffer[n], "%s: %d\n",
info->type->name, info->id);
}
return n;
}
void proc_tile_hardwall_init(struct proc_dir_entry *root)
{
int i;
for (i = 0; i < HARDWALL_TYPES; ++i) {
struct hardwall_type *hwt = &hardwall_types[i];
if (hwt->disabled)
continue;
if (hardwall_proc_dir == NULL)
hardwall_proc_dir = proc_mkdir("hardwall", root);
hwt->proc_dir = proc_mkdir(hwt->name, hardwall_proc_dir);
}
}
static long hardwall_ioctl(struct file *file, unsigned int a, unsigned long b)
{
struct hardwall_info *info = file->private_data;
int minor = iminor(file->f_mapping->host);
struct hardwall_type* hwt;
if (_IOC_TYPE(a) != HARDWALL_IOCTL_BASE)
return -EINVAL;
BUILD_BUG_ON(HARDWALL_TYPES != _HARDWALL_TYPES);
BUILD_BUG_ON(HARDWALL_TYPES !=
sizeof(hardwall_types)/sizeof(hardwall_types[0]));
if (minor < 0 || minor >= HARDWALL_TYPES)
return -EINVAL;
hwt = &hardwall_types[minor];
WARN_ON(info && hwt != info->type);
switch (_IOC_NR(a)) {
case _HARDWALL_CREATE:
if (hwt->disabled)
return -ENOSYS;
if (info != NULL)
return -EALREADY;
info = hardwall_create(hwt, _IOC_SIZE(a),
(const unsigned char __user *)b);
if (IS_ERR(info))
return PTR_ERR(info);
file->private_data = info;
return 0;
case _HARDWALL_ACTIVATE:
return hardwall_activate(info);
case _HARDWALL_DEACTIVATE:
if (current->thread.hardwall[hwt->index].info != info)
return -EINVAL;
return hardwall_deactivate(hwt, current);
case _HARDWALL_GET_ID:
return info ? info->id : -EINVAL;
default:
return -EINVAL;
}
}
static long hardwall_compat_ioctl(struct file *file,
unsigned int a, unsigned long b)
{
return hardwall_ioctl(file, a, (unsigned long)compat_ptr(b));
}
static int hardwall_flush(struct file *file, fl_owner_t owner)
{
struct hardwall_info *info = file->private_data;
struct task_struct *task, *tmp;
unsigned long flags;
if (info) {
struct hardwall_type *hwt = info->type;
spin_lock_irqsave(&hwt->lock, flags);
list_for_each_entry_safe(task, tmp, &info->task_head,
thread.hardwall[hwt->index].list) {
if (task->files == owner || task->files == NULL)
_hardwall_deactivate(hwt, task);
}
spin_unlock_irqrestore(&hwt->lock, flags);
}
return 0;
}
static int hardwall_release(struct inode *inode, struct file *file)
{
hardwall_destroy(file->private_data);
return 0;
}
static int __init dev_hardwall_init(void)
{
int rc;
dev_t dev;
rc = alloc_chrdev_region(&dev, 0, HARDWALL_TYPES, "hardwall");
if (rc < 0)
return rc;
cdev_init(&hardwall_dev, &dev_hardwall_fops);
rc = cdev_add(&hardwall_dev, dev, HARDWALL_TYPES);
if (rc < 0)
return rc;
return 0;
}
