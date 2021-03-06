static void cpuid_smp_cpuid(void *cmd_block)
{
struct cpuid_regs *cmd = (struct cpuid_regs *)cmd_block;
cpuid_count(cmd->eax, cmd->ecx,
&cmd->eax, &cmd->ebx, &cmd->ecx, &cmd->edx);
}
static loff_t cpuid_seek(struct file *file, loff_t offset, int orig)
{
loff_t ret;
struct inode *inode = file->f_mapping->host;
mutex_lock(&inode->i_mutex);
switch (orig) {
case 0:
file->f_pos = offset;
ret = file->f_pos;
break;
case 1:
file->f_pos += offset;
ret = file->f_pos;
break;
default:
ret = -EINVAL;
}
mutex_unlock(&inode->i_mutex);
return ret;
}
static ssize_t cpuid_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
char __user *tmp = buf;
struct cpuid_regs cmd;
int cpu = iminor(file->f_path.dentry->d_inode);
u64 pos = *ppos;
ssize_t bytes = 0;
int err = 0;
if (count % 16)
return -EINVAL;
for (; count; count -= 16) {
cmd.eax = pos;
cmd.ecx = pos >> 32;
err = smp_call_function_single(cpu, cpuid_smp_cpuid, &cmd, 1);
if (err)
break;
if (copy_to_user(tmp, &cmd, 16)) {
err = -EFAULT;
break;
}
tmp += 16;
bytes += 16;
*ppos = ++pos;
}
return bytes ? bytes : err;
}
static int cpuid_open(struct inode *inode, struct file *file)
{
unsigned int cpu;
struct cpuinfo_x86 *c;
cpu = iminor(file->f_path.dentry->d_inode);
if (cpu >= nr_cpu_ids || !cpu_online(cpu))
return -ENXIO;
c = &cpu_data(cpu);
if (c->cpuid_level < 0)
return -EIO;
return 0;
}
static __cpuinit int cpuid_device_create(int cpu)
{
struct device *dev;
dev = device_create(cpuid_class, NULL, MKDEV(CPUID_MAJOR, cpu), NULL,
"cpu%d", cpu);
return IS_ERR(dev) ? PTR_ERR(dev) : 0;
}
static void cpuid_device_destroy(int cpu)
{
device_destroy(cpuid_class, MKDEV(CPUID_MAJOR, cpu));
}
static int __cpuinit cpuid_class_cpu_callback(struct notifier_block *nfb,
unsigned long action,
void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
int err = 0;
switch (action) {
case CPU_UP_PREPARE:
err = cpuid_device_create(cpu);
break;
case CPU_UP_CANCELED:
case CPU_UP_CANCELED_FROZEN:
case CPU_DEAD:
cpuid_device_destroy(cpu);
break;
}
return notifier_from_errno(err);
}
static char *cpuid_devnode(struct device *dev, mode_t *mode)
{
return kasprintf(GFP_KERNEL, "cpu/%u/cpuid", MINOR(dev->devt));
}
static int __init cpuid_init(void)
{
int i, err = 0;
i = 0;
if (__register_chrdev(CPUID_MAJOR, 0, NR_CPUS,
"cpu/cpuid", &cpuid_fops)) {
printk(KERN_ERR "cpuid: unable to get major %d for cpuid\n",
CPUID_MAJOR);
err = -EBUSY;
goto out;
}
cpuid_class = class_create(THIS_MODULE, "cpuid");
if (IS_ERR(cpuid_class)) {
err = PTR_ERR(cpuid_class);
goto out_chrdev;
}
cpuid_class->devnode = cpuid_devnode;
for_each_online_cpu(i) {
err = cpuid_device_create(i);
if (err != 0)
goto out_class;
}
register_hotcpu_notifier(&cpuid_class_cpu_notifier);
err = 0;
goto out;
out_class:
i = 0;
for_each_online_cpu(i) {
cpuid_device_destroy(i);
}
class_destroy(cpuid_class);
out_chrdev:
__unregister_chrdev(CPUID_MAJOR, 0, NR_CPUS, "cpu/cpuid");
out:
return err;
}
static void __exit cpuid_exit(void)
{
int cpu = 0;
for_each_online_cpu(cpu)
cpuid_device_destroy(cpu);
class_destroy(cpuid_class);
__unregister_chrdev(CPUID_MAJOR, 0, NR_CPUS, "cpu/cpuid");
unregister_hotcpu_notifier(&cpuid_class_cpu_notifier);
}
