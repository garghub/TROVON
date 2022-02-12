static void collect_cpu_info_local(void *arg)
{
struct cpu_info_ctx *ctx = arg;
ctx->err = microcode_ops->collect_cpu_info(smp_processor_id(),
ctx->cpu_sig);
}
static int collect_cpu_info_on_target(int cpu, struct cpu_signature *cpu_sig)
{
struct cpu_info_ctx ctx = { .cpu_sig = cpu_sig, .err = 0 };
int ret;
ret = smp_call_function_single(cpu, collect_cpu_info_local, &ctx, 1);
if (!ret)
ret = ctx.err;
return ret;
}
static int collect_cpu_info(int cpu)
{
struct ucode_cpu_info *uci = ucode_cpu_info + cpu;
int ret;
memset(uci, 0, sizeof(*uci));
ret = collect_cpu_info_on_target(cpu, &uci->cpu_sig);
if (!ret)
uci->valid = 1;
return ret;
}
static void apply_microcode_local(void *arg)
{
struct apply_microcode_ctx *ctx = arg;
ctx->err = microcode_ops->apply_microcode(smp_processor_id());
}
static int apply_microcode_on_target(int cpu)
{
struct apply_microcode_ctx ctx = { .err = 0 };
int ret;
ret = smp_call_function_single(cpu, apply_microcode_local, &ctx, 1);
if (!ret)
ret = ctx.err;
return ret;
}
static int do_microcode_update(const void __user *buf, size_t size)
{
int error = 0;
int cpu;
for_each_online_cpu(cpu) {
struct ucode_cpu_info *uci = ucode_cpu_info + cpu;
enum ucode_state ustate;
if (!uci->valid)
continue;
ustate = microcode_ops->request_microcode_user(cpu, buf, size);
if (ustate == UCODE_ERROR) {
error = -1;
break;
} else if (ustate == UCODE_OK)
apply_microcode_on_target(cpu);
}
return error;
}
static int microcode_open(struct inode *inode, struct file *file)
{
return capable(CAP_SYS_RAWIO) ? nonseekable_open(inode, file) : -EPERM;
}
static ssize_t microcode_write(struct file *file, const char __user *buf,
size_t len, loff_t *ppos)
{
ssize_t ret = -EINVAL;
if ((len >> PAGE_SHIFT) > totalram_pages) {
pr_err("too much data (max %ld pages)\n", totalram_pages);
return ret;
}
get_online_cpus();
mutex_lock(&microcode_mutex);
if (do_microcode_update(buf, len) == 0)
ret = (ssize_t)len;
mutex_unlock(&microcode_mutex);
put_online_cpus();
return ret;
}
static int __init microcode_dev_init(void)
{
int error;
error = misc_register(&microcode_dev);
if (error) {
pr_err("can't misc_register on minor=%d\n", MICROCODE_MINOR);
return error;
}
return 0;
}
static void __exit microcode_dev_exit(void)
{
misc_deregister(&microcode_dev);
}
static int reload_for_cpu(int cpu)
{
struct ucode_cpu_info *uci = ucode_cpu_info + cpu;
int err = 0;
mutex_lock(&microcode_mutex);
if (uci->valid) {
enum ucode_state ustate;
ustate = microcode_ops->request_microcode_fw(cpu, &microcode_pdev->dev);
if (ustate == UCODE_OK)
apply_microcode_on_target(cpu);
else
if (ustate == UCODE_ERROR)
err = -EINVAL;
}
mutex_unlock(&microcode_mutex);
return err;
}
static ssize_t reload_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned long val;
int cpu = dev->id;
int ret = 0;
char *end;
val = simple_strtoul(buf, &end, 0);
if (end == buf)
return -EINVAL;
if (val == 1) {
get_online_cpus();
if (cpu_online(cpu))
ret = reload_for_cpu(cpu);
put_online_cpus();
}
if (!ret)
ret = size;
return ret;
}
static ssize_t version_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ucode_cpu_info *uci = ucode_cpu_info + dev->id;
return sprintf(buf, "0x%x\n", uci->cpu_sig.rev);
}
static ssize_t pf_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ucode_cpu_info *uci = ucode_cpu_info + dev->id;
return sprintf(buf, "0x%x\n", uci->cpu_sig.pf);
}
static void microcode_fini_cpu(int cpu)
{
struct ucode_cpu_info *uci = ucode_cpu_info + cpu;
microcode_ops->microcode_fini_cpu(cpu);
uci->valid = 0;
}
static enum ucode_state microcode_resume_cpu(int cpu)
{
struct ucode_cpu_info *uci = ucode_cpu_info + cpu;
if (!uci->mc)
return UCODE_NFOUND;
pr_debug("CPU%d updated upon resume\n", cpu);
apply_microcode_on_target(cpu);
return UCODE_OK;
}
static enum ucode_state microcode_init_cpu(int cpu)
{
enum ucode_state ustate;
if (collect_cpu_info(cpu))
return UCODE_ERROR;
if (system_state != SYSTEM_RUNNING)
return UCODE_NFOUND;
ustate = microcode_ops->request_microcode_fw(cpu, &microcode_pdev->dev);
if (ustate == UCODE_OK) {
pr_debug("CPU%d updated upon init\n", cpu);
apply_microcode_on_target(cpu);
}
return ustate;
}
static enum ucode_state microcode_update_cpu(int cpu)
{
struct ucode_cpu_info *uci = ucode_cpu_info + cpu;
enum ucode_state ustate;
if (uci->valid)
ustate = microcode_resume_cpu(cpu);
else
ustate = microcode_init_cpu(cpu);
return ustate;
}
static int mc_device_add(struct device *dev, struct subsys_interface *sif)
{
int err, cpu = dev->id;
if (!cpu_online(cpu))
return 0;
pr_debug("CPU%d added\n", cpu);
err = sysfs_create_group(&dev->kobj, &mc_attr_group);
if (err)
return err;
if (microcode_init_cpu(cpu) == UCODE_ERROR) {
sysfs_remove_group(&dev->kobj, &mc_attr_group);
return -EINVAL;
}
return err;
}
static int mc_device_remove(struct device *dev, struct subsys_interface *sif)
{
int cpu = dev->id;
if (!cpu_online(cpu))
return 0;
pr_debug("CPU%d removed\n", cpu);
microcode_fini_cpu(cpu);
sysfs_remove_group(&dev->kobj, &mc_attr_group);
return 0;
}
static void mc_bp_resume(void)
{
int cpu = smp_processor_id();
struct ucode_cpu_info *uci = ucode_cpu_info + cpu;
if (uci->valid && uci->mc)
microcode_ops->apply_microcode(cpu);
}
static __cpuinit int
mc_cpu_callback(struct notifier_block *nb, unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
struct device *dev;
dev = get_cpu_device(cpu);
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
microcode_update_cpu(cpu);
case CPU_DOWN_FAILED:
case CPU_DOWN_FAILED_FROZEN:
pr_debug("CPU%d added\n", cpu);
if (sysfs_create_group(&dev->kobj, &mc_attr_group))
pr_err("Failed to create group for CPU%d\n", cpu);
break;
case CPU_DOWN_PREPARE:
case CPU_DOWN_PREPARE_FROZEN:
sysfs_remove_group(&dev->kobj, &mc_attr_group);
pr_debug("CPU%d removed\n", cpu);
break;
case CPU_UP_CANCELED_FROZEN:
microcode_fini_cpu(cpu);
break;
}
return NOTIFY_OK;
}
static int __init microcode_init(void)
{
struct cpuinfo_x86 *c = &cpu_data(0);
int error;
if (c->x86_vendor == X86_VENDOR_INTEL)
microcode_ops = init_intel_microcode();
else if (c->x86_vendor == X86_VENDOR_AMD)
microcode_ops = init_amd_microcode();
if (!microcode_ops) {
pr_err("no support for this CPU vendor\n");
return -ENODEV;
}
microcode_pdev = platform_device_register_simple("microcode", -1,
NULL, 0);
if (IS_ERR(microcode_pdev))
return PTR_ERR(microcode_pdev);
get_online_cpus();
mutex_lock(&microcode_mutex);
error = subsys_interface_register(&mc_cpu_interface);
mutex_unlock(&microcode_mutex);
put_online_cpus();
if (error)
goto out_pdev;
error = microcode_dev_init();
if (error)
goto out_driver;
register_syscore_ops(&mc_syscore_ops);
register_hotcpu_notifier(&mc_cpu_notifier);
pr_info("Microcode Update Driver: v" MICROCODE_VERSION
" <tigran@aivazian.fsnet.co.uk>, Peter Oruba\n");
return 0;
out_driver:
get_online_cpus();
mutex_lock(&microcode_mutex);
subsys_interface_unregister(&mc_cpu_interface);
mutex_unlock(&microcode_mutex);
put_online_cpus();
out_pdev:
platform_device_unregister(microcode_pdev);
return error;
}
static void __exit microcode_exit(void)
{
struct cpuinfo_x86 *c = &cpu_data(0);
microcode_dev_exit();
unregister_hotcpu_notifier(&mc_cpu_notifier);
unregister_syscore_ops(&mc_syscore_ops);
get_online_cpus();
mutex_lock(&microcode_mutex);
subsys_interface_unregister(&mc_cpu_interface);
mutex_unlock(&microcode_mutex);
put_online_cpus();
platform_device_unregister(microcode_pdev);
microcode_ops = NULL;
if (c->x86_vendor == X86_VENDOR_AMD)
exit_amd_microcode();
pr_info("Microcode Update Driver: v" MICROCODE_VERSION " removed.\n");
}
