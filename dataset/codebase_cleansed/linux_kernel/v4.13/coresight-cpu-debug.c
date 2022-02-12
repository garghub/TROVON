static void debug_os_unlock(struct debug_drvdata *drvdata)
{
writel_relaxed(0x0, drvdata->base + EDOSLAR);
wmb();
}
static bool debug_access_permitted(struct debug_drvdata *drvdata)
{
if (!(drvdata->edprsr & EDPRSR_PU))
return false;
if (drvdata->edprsr & EDPRSR_DLK)
return false;
return true;
}
static void debug_force_cpu_powered_up(struct debug_drvdata *drvdata)
{
u32 edprcr;
try_again:
edprcr = readl_relaxed(drvdata->base + EDPRCR);
edprcr |= EDPRCR_COREPURQ;
writel_relaxed(edprcr, drvdata->base + EDPRCR);
if (readx_poll_timeout_atomic(readl_relaxed, drvdata->base + EDPRSR,
drvdata->edprsr, (drvdata->edprsr & EDPRSR_PU),
DEBUG_WAIT_SLEEP, DEBUG_WAIT_TIMEOUT)) {
dev_err(drvdata->dev, "%s: power up request for CPU%d failed\n",
__func__, drvdata->cpu);
return;
}
edprcr = readl_relaxed(drvdata->base + EDPRCR);
edprcr |= EDPRCR_COREPURQ | EDPRCR_CORENPDRQ;
writel_relaxed(edprcr, drvdata->base + EDPRCR);
drvdata->edprsr = readl_relaxed(drvdata->base + EDPRSR);
if (unlikely(!(drvdata->edprsr & EDPRSR_PU)))
goto try_again;
}
static void debug_read_regs(struct debug_drvdata *drvdata)
{
u32 save_edprcr;
CS_UNLOCK(drvdata->base);
debug_os_unlock(drvdata);
save_edprcr = readl_relaxed(drvdata->base + EDPRCR);
debug_force_cpu_powered_up(drvdata);
if (!debug_access_permitted(drvdata))
goto out;
drvdata->edpcsr = readl_relaxed(drvdata->base + EDPCSR);
if (drvdata->edpcsr == EDPCSR_PROHIBITED)
goto out;
if (IS_ENABLED(CONFIG_64BIT))
drvdata->edpcsr_hi = readl_relaxed(drvdata->base + EDPCSR_HI);
if (drvdata->edcidsr_present)
drvdata->edcidsr = readl_relaxed(drvdata->base + EDCIDSR);
if (drvdata->edvidsr_present)
drvdata->edvidsr = readl_relaxed(drvdata->base + EDVIDSR);
out:
writel_relaxed(save_edprcr, drvdata->base + EDPRCR);
CS_LOCK(drvdata->base);
}
static unsigned long debug_adjust_pc(struct debug_drvdata *drvdata)
{
return (unsigned long)drvdata->edpcsr_hi << 32 |
(unsigned long)drvdata->edpcsr;
}
static unsigned long debug_adjust_pc(struct debug_drvdata *drvdata)
{
unsigned long arm_inst_offset = 0, thumb_inst_offset = 0;
unsigned long pc;
pc = (unsigned long)drvdata->edpcsr;
if (drvdata->pc_has_offset) {
arm_inst_offset = 8;
thumb_inst_offset = 4;
}
if (pc & EDPCSR_THUMB) {
pc = (pc & EDPCSR_THUMB_INST_MASK) - thumb_inst_offset;
return pc;
}
if (pc & BIT(1))
dev_emerg(drvdata->dev,
"Instruction offset is implementation defined\n");
else
pc = (pc & EDPCSR_ARM_INST_MASK) - arm_inst_offset;
return pc;
}
static void debug_dump_regs(struct debug_drvdata *drvdata)
{
struct device *dev = drvdata->dev;
unsigned long pc;
dev_emerg(dev, " EDPRSR: %08x (Power:%s DLK:%s)\n",
drvdata->edprsr,
drvdata->edprsr & EDPRSR_PU ? "On" : "Off",
drvdata->edprsr & EDPRSR_DLK ? "Lock" : "Unlock");
if (!debug_access_permitted(drvdata)) {
dev_emerg(dev, "No permission to access debug registers!\n");
return;
}
if (drvdata->edpcsr == EDPCSR_PROHIBITED) {
dev_emerg(dev, "CPU is in Debug state or profiling is prohibited!\n");
return;
}
pc = debug_adjust_pc(drvdata);
dev_emerg(dev, " EDPCSR: [<%p>] %pS\n", (void *)pc, (void *)pc);
if (drvdata->edcidsr_present)
dev_emerg(dev, " EDCIDSR: %08x\n", drvdata->edcidsr);
if (drvdata->edvidsr_present)
dev_emerg(dev, " EDVIDSR: %08x (State:%s Mode:%s Width:%dbits VMID:%x)\n",
drvdata->edvidsr,
drvdata->edvidsr & EDVIDSR_NS ?
"Non-secure" : "Secure",
drvdata->edvidsr & EDVIDSR_E3 ? "EL3" :
(drvdata->edvidsr & EDVIDSR_E2 ?
"EL2" : "EL1/0"),
drvdata->edvidsr & EDVIDSR_HV ? 64 : 32,
drvdata->edvidsr & (u32)EDVIDSR_VMID);
}
static void debug_init_arch_data(void *info)
{
struct debug_drvdata *drvdata = info;
u32 mode, pcsr_offset;
u32 eddevid, eddevid1;
CS_UNLOCK(drvdata->base);
eddevid = readl_relaxed(drvdata->base + EDDEVID);
eddevid1 = readl_relaxed(drvdata->base + EDDEVID1);
CS_LOCK(drvdata->base);
mode = eddevid & EDDEVID_PCSAMPLE_MODE;
pcsr_offset = eddevid1 & EDDEVID1_PCSR_OFFSET_MASK;
drvdata->edpcsr_present = false;
drvdata->edcidsr_present = false;
drvdata->edvidsr_present = false;
drvdata->pc_has_offset = false;
switch (mode) {
case EDDEVID_IMPL_FULL:
drvdata->edvidsr_present = true;
case EDDEVID_IMPL_EDPCSR_EDCIDSR:
drvdata->edcidsr_present = true;
case EDDEVID_IMPL_EDPCSR:
drvdata->edpcsr_present =
((IS_ENABLED(CONFIG_64BIT) && pcsr_offset != 0) ||
(pcsr_offset != EDDEVID1_PCSR_NO_OFFSET_DIS_AARCH32));
drvdata->pc_has_offset =
(pcsr_offset == EDDEVID1_PCSR_OFFSET_INS_SET);
break;
default:
break;
}
}
static int debug_notifier_call(struct notifier_block *self,
unsigned long v, void *p)
{
int cpu;
struct debug_drvdata *drvdata;
mutex_lock(&debug_lock);
if (!debug_enable)
goto skip_dump;
pr_emerg("ARM external debug module:\n");
for_each_possible_cpu(cpu) {
drvdata = per_cpu(debug_drvdata, cpu);
if (!drvdata)
continue;
dev_emerg(drvdata->dev, "CPU[%d]:\n", drvdata->cpu);
debug_read_regs(drvdata);
debug_dump_regs(drvdata);
}
skip_dump:
mutex_unlock(&debug_lock);
return 0;
}
static int debug_enable_func(void)
{
struct debug_drvdata *drvdata;
int cpu, ret = 0;
cpumask_t mask;
cpumask_clear(&mask);
for_each_possible_cpu(cpu) {
drvdata = per_cpu(debug_drvdata, cpu);
if (!drvdata)
continue;
ret = pm_runtime_get_sync(drvdata->dev);
if (ret < 0)
goto err;
else
cpumask_set_cpu(cpu, &mask);
}
return 0;
err:
for_each_cpu(cpu, &mask) {
drvdata = per_cpu(debug_drvdata, cpu);
pm_runtime_put_noidle(drvdata->dev);
}
return ret;
}
static int debug_disable_func(void)
{
struct debug_drvdata *drvdata;
int cpu, ret, err = 0;
for_each_possible_cpu(cpu) {
drvdata = per_cpu(debug_drvdata, cpu);
if (!drvdata)
continue;
ret = pm_runtime_put(drvdata->dev);
if (ret < 0)
err = ret;
}
return err;
}
static ssize_t debug_func_knob_write(struct file *f,
const char __user *buf, size_t count, loff_t *ppos)
{
u8 val;
int ret;
ret = kstrtou8_from_user(buf, count, 2, &val);
if (ret)
return ret;
mutex_lock(&debug_lock);
if (val == debug_enable)
goto out;
if (val)
ret = debug_enable_func();
else
ret = debug_disable_func();
if (ret) {
pr_err("%s: unable to %s debug function: %d\n",
__func__, val ? "enable" : "disable", ret);
goto err;
}
debug_enable = val;
out:
ret = count;
err:
mutex_unlock(&debug_lock);
return ret;
}
static ssize_t debug_func_knob_read(struct file *f,
char __user *ubuf, size_t count, loff_t *ppos)
{
ssize_t ret;
char buf[3];
mutex_lock(&debug_lock);
snprintf(buf, sizeof(buf), "%d\n", debug_enable);
mutex_unlock(&debug_lock);
ret = simple_read_from_buffer(ubuf, count, ppos, buf, sizeof(buf));
return ret;
}
static int debug_func_init(void)
{
struct dentry *file;
int ret;
debug_debugfs_dir = debugfs_create_dir("coresight_cpu_debug", NULL);
if (!debug_debugfs_dir) {
pr_err("%s: unable to create debugfs directory\n", __func__);
return -ENOMEM;
}
file = debugfs_create_file("enable", 0644, debug_debugfs_dir, NULL,
&debug_func_knob_fops);
if (!file) {
pr_err("%s: unable to create enable knob file\n", __func__);
ret = -ENOMEM;
goto err;
}
ret = atomic_notifier_chain_register(&panic_notifier_list,
&debug_notifier);
if (ret) {
pr_err("%s: unable to register notifier: %d\n",
__func__, ret);
goto err;
}
return 0;
err:
debugfs_remove_recursive(debug_debugfs_dir);
return ret;
}
static void debug_func_exit(void)
{
atomic_notifier_chain_unregister(&panic_notifier_list,
&debug_notifier);
debugfs_remove_recursive(debug_debugfs_dir);
}
static int debug_probe(struct amba_device *adev, const struct amba_id *id)
{
void __iomem *base;
struct device *dev = &adev->dev;
struct debug_drvdata *drvdata;
struct resource *res = &adev->res;
struct device_node *np = adev->dev.of_node;
int ret;
drvdata = devm_kzalloc(dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
drvdata->cpu = np ? of_coresight_get_cpu(np) : 0;
if (per_cpu(debug_drvdata, drvdata->cpu)) {
dev_err(dev, "CPU%d drvdata has already been initialized\n",
drvdata->cpu);
return -EBUSY;
}
drvdata->dev = &adev->dev;
amba_set_drvdata(adev, drvdata);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
drvdata->base = base;
get_online_cpus();
per_cpu(debug_drvdata, drvdata->cpu) = drvdata;
ret = smp_call_function_single(drvdata->cpu, debug_init_arch_data,
drvdata, 1);
put_online_cpus();
if (ret) {
dev_err(dev, "CPU%d debug arch init failed\n", drvdata->cpu);
goto err;
}
if (!drvdata->edpcsr_present) {
dev_err(dev, "CPU%d sample-based profiling isn't implemented\n",
drvdata->cpu);
ret = -ENXIO;
goto err;
}
if (!debug_count++) {
ret = debug_func_init();
if (ret)
goto err_func_init;
}
mutex_lock(&debug_lock);
if (!debug_enable)
pm_runtime_put(dev);
mutex_unlock(&debug_lock);
dev_info(dev, "Coresight debug-CPU%d initialized\n", drvdata->cpu);
return 0;
err_func_init:
debug_count--;
err:
per_cpu(debug_drvdata, drvdata->cpu) = NULL;
return ret;
}
static int debug_remove(struct amba_device *adev)
{
struct device *dev = &adev->dev;
struct debug_drvdata *drvdata = amba_get_drvdata(adev);
per_cpu(debug_drvdata, drvdata->cpu) = NULL;
mutex_lock(&debug_lock);
if (debug_enable)
pm_runtime_put(dev);
mutex_unlock(&debug_lock);
if (!--debug_count)
debug_func_exit();
return 0;
}
