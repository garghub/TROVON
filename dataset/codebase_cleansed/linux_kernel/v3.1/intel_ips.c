static inline __u64 readq(const volatile void __iomem *addr)
{
const volatile u32 __iomem *p = addr;
u32 low, high;
low = readl(p);
high = readl(p + 1);
return low + ((u64)high << 32);
}
static bool ips_cpu_busy(struct ips_driver *ips)
{
if ((avenrun[0] >> FSHIFT) > 1)
return true;
return false;
}
static void ips_cpu_raise(struct ips_driver *ips)
{
u64 turbo_override;
u16 cur_tdp_limit, new_tdp_limit;
if (!ips->cpu_turbo_enabled)
return;
rdmsrl(TURBO_POWER_CURRENT_LIMIT, turbo_override);
cur_tdp_limit = turbo_override & TURBO_TDP_MASK;
new_tdp_limit = cur_tdp_limit + 8;
if (((new_tdp_limit * 10) / 8) > ips->core_power_limit)
new_tdp_limit = cur_tdp_limit;
thm_writew(THM_MPCPC, (new_tdp_limit * 10) / 8);
turbo_override |= TURBO_TDC_OVR_EN | TURBO_TDP_OVR_EN;
wrmsrl(TURBO_POWER_CURRENT_LIMIT, turbo_override);
turbo_override &= ~TURBO_TDP_MASK;
turbo_override |= new_tdp_limit;
wrmsrl(TURBO_POWER_CURRENT_LIMIT, turbo_override);
}
static void ips_cpu_lower(struct ips_driver *ips)
{
u64 turbo_override;
u16 cur_limit, new_limit;
rdmsrl(TURBO_POWER_CURRENT_LIMIT, turbo_override);
cur_limit = turbo_override & TURBO_TDP_MASK;
new_limit = cur_limit - 8;
if (new_limit < (ips->orig_turbo_limit & TURBO_TDP_MASK))
new_limit = ips->orig_turbo_limit & TURBO_TDP_MASK;
thm_writew(THM_MPCPC, (new_limit * 10) / 8);
turbo_override |= TURBO_TDC_OVR_EN | TURBO_TDP_OVR_EN;
wrmsrl(TURBO_POWER_CURRENT_LIMIT, turbo_override);
turbo_override &= ~TURBO_TDP_MASK;
turbo_override |= new_limit;
wrmsrl(TURBO_POWER_CURRENT_LIMIT, turbo_override);
}
static void do_enable_cpu_turbo(void *data)
{
u64 perf_ctl;
rdmsrl(IA32_PERF_CTL, perf_ctl);
if (perf_ctl & IA32_PERF_TURBO_DIS) {
perf_ctl &= ~IA32_PERF_TURBO_DIS;
wrmsrl(IA32_PERF_CTL, perf_ctl);
}
}
static void ips_enable_cpu_turbo(struct ips_driver *ips)
{
if (ips->__cpu_turbo_on)
return;
if (ips->turbo_toggle_allowed)
on_each_cpu(do_enable_cpu_turbo, ips, 1);
ips->__cpu_turbo_on = true;
}
static void do_disable_cpu_turbo(void *data)
{
u64 perf_ctl;
rdmsrl(IA32_PERF_CTL, perf_ctl);
if (!(perf_ctl & IA32_PERF_TURBO_DIS)) {
perf_ctl |= IA32_PERF_TURBO_DIS;
wrmsrl(IA32_PERF_CTL, perf_ctl);
}
}
static void ips_disable_cpu_turbo(struct ips_driver *ips)
{
if (!ips->__cpu_turbo_on)
return;
if (ips->turbo_toggle_allowed)
on_each_cpu(do_disable_cpu_turbo, ips, 1);
ips->__cpu_turbo_on = false;
}
static bool ips_gpu_busy(struct ips_driver *ips)
{
if (!ips_gpu_turbo_enabled(ips))
return false;
return ips->gpu_busy();
}
static void ips_gpu_raise(struct ips_driver *ips)
{
if (!ips_gpu_turbo_enabled(ips))
return;
if (!ips->gpu_raise())
ips->gpu_turbo_enabled = false;
return;
}
static void ips_gpu_lower(struct ips_driver *ips)
{
if (!ips_gpu_turbo_enabled(ips))
return;
if (!ips->gpu_lower())
ips->gpu_turbo_enabled = false;
return;
}
static void ips_enable_gpu_turbo(struct ips_driver *ips)
{
if (ips->__gpu_turbo_on)
return;
ips->__gpu_turbo_on = true;
}
static void ips_disable_gpu_turbo(struct ips_driver *ips)
{
if (!ips->__gpu_turbo_on)
return;
if (!ips->gpu_turbo_disable())
dev_err(&ips->dev->dev, "failed to disable graphis turbo\n");
else
ips->__gpu_turbo_on = false;
}
static bool mcp_exceeded(struct ips_driver *ips)
{
unsigned long flags;
bool ret = false;
u32 temp_limit;
u32 avg_power;
const char *msg = "MCP limit exceeded: ";
spin_lock_irqsave(&ips->turbo_status_lock, flags);
temp_limit = ips->mcp_temp_limit * 100;
if (ips->mcp_avg_temp > temp_limit) {
dev_info(&ips->dev->dev,
"%sAvg temp %u, limit %u\n", msg, ips->mcp_avg_temp,
temp_limit);
ret = true;
}
avg_power = ips->cpu_avg_power + ips->mch_avg_power;
if (avg_power > ips->mcp_power_limit) {
dev_info(&ips->dev->dev,
"%sAvg power %u, limit %u\n", msg, avg_power,
ips->mcp_power_limit);
ret = true;
}
spin_unlock_irqrestore(&ips->turbo_status_lock, flags);
return ret;
}
static bool cpu_exceeded(struct ips_driver *ips, int cpu)
{
unsigned long flags;
int avg;
bool ret = false;
spin_lock_irqsave(&ips->turbo_status_lock, flags);
avg = cpu ? ips->ctv2_avg_temp : ips->ctv1_avg_temp;
if (avg > (ips->limits->core_temp_limit * 100))
ret = true;
if (ips->cpu_avg_power > ips->core_power_limit * 100)
ret = true;
spin_unlock_irqrestore(&ips->turbo_status_lock, flags);
if (ret)
dev_info(&ips->dev->dev,
"CPU power or thermal limit exceeded\n");
return ret;
}
static bool mch_exceeded(struct ips_driver *ips)
{
unsigned long flags;
bool ret = false;
spin_lock_irqsave(&ips->turbo_status_lock, flags);
if (ips->mch_avg_temp > (ips->limits->mch_temp_limit * 100))
ret = true;
if (ips->mch_avg_power > ips->mch_power_limit)
ret = true;
spin_unlock_irqrestore(&ips->turbo_status_lock, flags);
return ret;
}
static void verify_limits(struct ips_driver *ips)
{
if (ips->mcp_power_limit < ips->limits->mcp_power_limit ||
ips->mcp_power_limit > 35000)
ips->mcp_power_limit = ips->limits->mcp_power_limit;
if (ips->mcp_temp_limit < ips->limits->core_temp_limit ||
ips->mcp_temp_limit < ips->limits->mch_temp_limit ||
ips->mcp_temp_limit > 150)
ips->mcp_temp_limit = min(ips->limits->core_temp_limit,
ips->limits->mch_temp_limit);
}
static void update_turbo_limits(struct ips_driver *ips)
{
u32 hts = thm_readl(THM_HTS);
ips->cpu_turbo_enabled = !(hts & HTS_PCTD_DIS);
ips->cpu_turbo_enabled = false;
if (ips->gpu_busy)
ips->gpu_turbo_enabled = !(hts & HTS_GTD_DIS);
ips->core_power_limit = thm_readw(THM_MPCPC);
ips->mch_power_limit = thm_readw(THM_MMGPC);
ips->mcp_temp_limit = thm_readw(THM_PTL);
ips->mcp_power_limit = thm_readw(THM_MPPC);
verify_limits(ips);
}
static int ips_adjust(void *data)
{
struct ips_driver *ips = data;
unsigned long flags;
dev_dbg(&ips->dev->dev, "starting ips-adjust thread\n");
do {
bool cpu_busy = ips_cpu_busy(ips);
bool gpu_busy = ips_gpu_busy(ips);
spin_lock_irqsave(&ips->turbo_status_lock, flags);
if (ips->poll_turbo_status)
update_turbo_limits(ips);
spin_unlock_irqrestore(&ips->turbo_status_lock, flags);
if (ips->cpu_turbo_enabled)
ips_enable_cpu_turbo(ips);
else
ips_disable_cpu_turbo(ips);
if (ips->gpu_turbo_enabled)
ips_enable_gpu_turbo(ips);
else
ips_disable_gpu_turbo(ips);
if (mcp_exceeded(ips)) {
ips_cpu_lower(ips);
ips_gpu_lower(ips);
goto sleep;
}
if (!cpu_exceeded(ips, 0) && cpu_busy)
ips_cpu_raise(ips);
else
ips_cpu_lower(ips);
if (!mch_exceeded(ips) && gpu_busy)
ips_gpu_raise(ips);
else
ips_gpu_lower(ips);
sleep:
schedule_timeout_interruptible(msecs_to_jiffies(IPS_ADJUST_PERIOD));
} while (!kthread_should_stop());
dev_dbg(&ips->dev->dev, "ips-adjust thread stopped\n");
return 0;
}
static u16 calc_avg_temp(struct ips_driver *ips, u16 *array)
{
u64 total = 0;
int i;
u16 avg;
for (i = 0; i < IPS_SAMPLE_COUNT; i++)
total += (u64)(array[i] * 100);
do_div(total, IPS_SAMPLE_COUNT);
avg = (u16)total;
return avg;
}
static u16 read_mgtv(struct ips_driver *ips)
{
u16 ret;
u64 slope, offset;
u64 val;
val = thm_readq(THM_MGTV);
val = (val & TV_MASK) >> TV_SHIFT;
slope = offset = thm_readw(THM_MGTA);
slope = (slope & MGTA_SLOPE_MASK) >> MGTA_SLOPE_SHIFT;
offset = offset & MGTA_OFFSET_MASK;
ret = ((val * slope + 0x40) >> 7) + offset;
return 0;
}
static u16 read_ptv(struct ips_driver *ips)
{
u16 val, slope, offset;
slope = (ips->pta_val & PTA_SLOPE_MASK) >> PTA_SLOPE_SHIFT;
offset = ips->pta_val & PTA_OFFSET_MASK;
val = thm_readw(THM_PTV) & PTV_MASK;
return val;
}
static u16 read_ctv(struct ips_driver *ips, int cpu)
{
int reg = cpu ? THM_CTV2 : THM_CTV1;
u16 val;
val = thm_readw(reg);
if (!(val & CTV_TEMP_ERROR))
val = (val) >> 6;
else
val = 0;
return val;
}
static u32 get_cpu_power(struct ips_driver *ips, u32 *last, int period)
{
u32 val;
u32 ret;
val = thm_readl(THM_CEC);
ret = (((val - *last) * 1000) / period);
ret = (ret * 1000) / 65535;
*last = val;
return 0;
}
static u16 update_average_temp(u16 avg, u16 val)
{
u16 ret;
ret = (val * 100 / temp_decay_factor) +
(((temp_decay_factor - 1) * avg) / temp_decay_factor);
return ret;
}
static u16 update_average_power(u32 avg, u32 val)
{
u32 ret;
ret = (val / power_decay_factor) +
(((power_decay_factor - 1) * avg) / power_decay_factor);
return ret;
}
static u32 calc_avg_power(struct ips_driver *ips, u32 *array)
{
u64 total = 0;
u32 avg;
int i;
for (i = 0; i < IPS_SAMPLE_COUNT; i++)
total += array[i];
do_div(total, IPS_SAMPLE_COUNT);
avg = (u32)total;
return avg;
}
static void monitor_timeout(unsigned long arg)
{
wake_up_process((struct task_struct *)arg);
}
static int ips_monitor(void *data)
{
struct ips_driver *ips = data;
struct timer_list timer;
unsigned long seqno_timestamp, expire, last_msecs, last_sample_period;
int i;
u32 *cpu_samples, *mchp_samples, old_cpu_power;
u16 *mcp_samples, *ctv1_samples, *ctv2_samples, *mch_samples;
u8 cur_seqno, last_seqno;
mcp_samples = kzalloc(sizeof(u16) * IPS_SAMPLE_COUNT, GFP_KERNEL);
ctv1_samples = kzalloc(sizeof(u16) * IPS_SAMPLE_COUNT, GFP_KERNEL);
ctv2_samples = kzalloc(sizeof(u16) * IPS_SAMPLE_COUNT, GFP_KERNEL);
mch_samples = kzalloc(sizeof(u16) * IPS_SAMPLE_COUNT, GFP_KERNEL);
cpu_samples = kzalloc(sizeof(u32) * IPS_SAMPLE_COUNT, GFP_KERNEL);
mchp_samples = kzalloc(sizeof(u32) * IPS_SAMPLE_COUNT, GFP_KERNEL);
if (!mcp_samples || !ctv1_samples || !ctv2_samples || !mch_samples ||
!cpu_samples || !mchp_samples) {
dev_err(&ips->dev->dev,
"failed to allocate sample array, ips disabled\n");
kfree(mcp_samples);
kfree(ctv1_samples);
kfree(ctv2_samples);
kfree(mch_samples);
kfree(cpu_samples);
kfree(mchp_samples);
return -ENOMEM;
}
last_seqno = (thm_readl(THM_ITV) & ITV_ME_SEQNO_MASK) >>
ITV_ME_SEQNO_SHIFT;
seqno_timestamp = get_jiffies_64();
old_cpu_power = thm_readl(THM_CEC);
schedule_timeout_interruptible(msecs_to_jiffies(IPS_SAMPLE_PERIOD));
for (i = 0; i < IPS_SAMPLE_COUNT; i++) {
u32 mchp, cpu_power;
u16 val;
mcp_samples[i] = read_ptv(ips);
val = read_ctv(ips, 0);
ctv1_samples[i] = val;
val = read_ctv(ips, 1);
ctv2_samples[i] = val;
val = read_mgtv(ips);
mch_samples[i] = val;
cpu_power = get_cpu_power(ips, &old_cpu_power,
IPS_SAMPLE_PERIOD);
cpu_samples[i] = cpu_power;
if (ips->read_mch_val) {
mchp = ips->read_mch_val();
mchp_samples[i] = mchp;
}
schedule_timeout_interruptible(msecs_to_jiffies(IPS_SAMPLE_PERIOD));
if (kthread_should_stop())
break;
}
ips->mcp_avg_temp = calc_avg_temp(ips, mcp_samples);
ips->ctv1_avg_temp = calc_avg_temp(ips, ctv1_samples);
ips->ctv2_avg_temp = calc_avg_temp(ips, ctv2_samples);
ips->mch_avg_temp = calc_avg_temp(ips, mch_samples);
ips->cpu_avg_power = calc_avg_power(ips, cpu_samples);
ips->mch_avg_power = calc_avg_power(ips, mchp_samples);
kfree(mcp_samples);
kfree(ctv1_samples);
kfree(ctv2_samples);
kfree(mch_samples);
kfree(cpu_samples);
kfree(mchp_samples);
wake_up_process(ips->adjust);
old_cpu_power = thm_readl(THM_CEC);
schedule_timeout_interruptible(msecs_to_jiffies(IPS_SAMPLE_PERIOD));
last_sample_period = IPS_SAMPLE_PERIOD;
setup_deferrable_timer_on_stack(&timer, monitor_timeout,
(unsigned long)current);
do {
u32 cpu_val, mch_val;
u16 val;
val = read_ptv(ips);
ips->mcp_avg_temp = update_average_temp(ips->mcp_avg_temp, val);
val = read_ctv(ips, 0);
ips->ctv1_avg_temp =
update_average_temp(ips->ctv1_avg_temp, val);
cpu_val = get_cpu_power(ips, &old_cpu_power,
last_sample_period);
ips->cpu_avg_power =
update_average_power(ips->cpu_avg_power, cpu_val);
if (ips->second_cpu) {
val = read_ctv(ips, 1);
ips->ctv2_avg_temp =
update_average_temp(ips->ctv2_avg_temp, val);
}
val = read_mgtv(ips);
ips->mch_avg_temp = update_average_temp(ips->mch_avg_temp, val);
if (ips->read_mch_val) {
mch_val = ips->read_mch_val();
ips->mch_avg_power =
update_average_power(ips->mch_avg_power,
mch_val);
}
cur_seqno = (thm_readl(THM_ITV) & ITV_ME_SEQNO_MASK) >>
ITV_ME_SEQNO_SHIFT;
if (cur_seqno == last_seqno &&
time_after(jiffies, seqno_timestamp + HZ)) {
dev_warn(&ips->dev->dev, "ME failed to update for more than 1s, likely hung\n");
} else {
seqno_timestamp = get_jiffies_64();
last_seqno = cur_seqno;
}
last_msecs = jiffies_to_msecs(jiffies);
expire = jiffies + msecs_to_jiffies(IPS_SAMPLE_PERIOD);
__set_current_state(TASK_INTERRUPTIBLE);
mod_timer(&timer, expire);
schedule();
last_sample_period = jiffies_to_msecs(jiffies) - last_msecs;
if (!last_sample_period)
last_sample_period = 1;
} while (!kthread_should_stop());
del_timer_sync(&timer);
destroy_timer_on_stack(&timer);
dev_dbg(&ips->dev->dev, "ips-monitor thread stopped\n");
return 0;
}
static irqreturn_t ips_irq_handler(int irq, void *arg)
{
struct ips_driver *ips = arg;
u8 tses = thm_readb(THM_TSES);
u8 tes = thm_readb(THM_TES);
if (!tses && !tes)
return IRQ_NONE;
dev_info(&ips->dev->dev, "TSES: 0x%02x\n", tses);
dev_info(&ips->dev->dev, "TES: 0x%02x\n", tes);
if (tes & 1) {
u32 sts, tc1;
sts = thm_readl(THM_STS);
tc1 = thm_readl(THM_TC1);
if (sts & STS_NVV) {
spin_lock(&ips->turbo_status_lock);
ips->core_power_limit = (sts & STS_PCPL_MASK) >>
STS_PCPL_SHIFT;
ips->mch_power_limit = (sts & STS_GPL_MASK) >>
STS_GPL_SHIFT;
ips->cpu_turbo_enabled = !(sts & STS_PCTD_DIS);
ips->cpu_turbo_enabled = false;
if (ips->gpu_busy)
ips->gpu_turbo_enabled = !(sts & STS_GTD_DIS);
ips->mcp_temp_limit = (sts & STS_PTL_MASK) >>
STS_PTL_SHIFT;
ips->mcp_power_limit = (tc1 & STS_PPL_MASK) >>
STS_PPL_SHIFT;
verify_limits(ips);
spin_unlock(&ips->turbo_status_lock);
thm_writeb(THM_SEC, SEC_ACK);
}
thm_writeb(THM_TES, tes);
}
if (tses) {
dev_warn(&ips->dev->dev,
"thermal trip occurred, tses: 0x%04x\n", tses);
thm_writeb(THM_TSES, tses);
}
return IRQ_HANDLED;
}
static void ips_debugfs_init(struct ips_driver *ips) { return; }
static void ips_debugfs_cleanup(struct ips_driver *ips) { return; }
static int show_cpu_temp(struct seq_file *m, void *data)
{
struct ips_driver *ips = m->private;
seq_printf(m, "%d.%02d\n", ips->ctv1_avg_temp / 100,
ips->ctv1_avg_temp % 100);
return 0;
}
static int show_cpu_power(struct seq_file *m, void *data)
{
struct ips_driver *ips = m->private;
seq_printf(m, "%dmW\n", ips->cpu_avg_power);
return 0;
}
static int show_cpu_clamp(struct seq_file *m, void *data)
{
u64 turbo_override;
int tdp, tdc;
rdmsrl(TURBO_POWER_CURRENT_LIMIT, turbo_override);
tdp = (int)(turbo_override & TURBO_TDP_MASK);
tdc = (int)((turbo_override & TURBO_TDC_MASK) >> TURBO_TDC_SHIFT);
tdp = tdp * 10 / 8;
tdc = tdc * 10 / 8;
seq_printf(m, "%d.%dW %d.%dA\n", tdp / 10, tdp % 10,
tdc / 10, tdc % 10);
return 0;
}
static int show_mch_temp(struct seq_file *m, void *data)
{
struct ips_driver *ips = m->private;
seq_printf(m, "%d.%02d\n", ips->mch_avg_temp / 100,
ips->mch_avg_temp % 100);
return 0;
}
static int show_mch_power(struct seq_file *m, void *data)
{
struct ips_driver *ips = m->private;
seq_printf(m, "%dmW\n", ips->mch_avg_power);
return 0;
}
static int ips_debugfs_open(struct inode *inode, struct file *file)
{
struct ips_debugfs_node *node = inode->i_private;
return single_open(file, node->show, node->ips);
}
static void ips_debugfs_cleanup(struct ips_driver *ips)
{
if (ips->debug_root)
debugfs_remove_recursive(ips->debug_root);
return;
}
static void ips_debugfs_init(struct ips_driver *ips)
{
int i;
ips->debug_root = debugfs_create_dir("ips", NULL);
if (!ips->debug_root) {
dev_err(&ips->dev->dev,
"failed to create debugfs entries: %ld\n",
PTR_ERR(ips->debug_root));
return;
}
for (i = 0; i < ARRAY_SIZE(ips_debug_files); i++) {
struct dentry *ent;
struct ips_debugfs_node *node = &ips_debug_files[i];
node->ips = ips;
ent = debugfs_create_file(node->name, S_IFREG | S_IRUGO,
ips->debug_root, node,
&ips_debugfs_ops);
if (!ent) {
dev_err(&ips->dev->dev,
"failed to create debug file: %ld\n",
PTR_ERR(ent));
goto err_cleanup;
}
}
return;
err_cleanup:
ips_debugfs_cleanup(ips);
return;
}
static struct ips_mcp_limits *ips_detect_cpu(struct ips_driver *ips)
{
u64 turbo_power, misc_en;
struct ips_mcp_limits *limits = NULL;
u16 tdp;
if (!(boot_cpu_data.x86 == 6 && boot_cpu_data.x86_model == 37)) {
dev_info(&ips->dev->dev, "Non-IPS CPU detected.\n");
goto out;
}
rdmsrl(IA32_MISC_ENABLE, misc_en);
if (misc_en & IA32_MISC_TURBO_EN)
ips->turbo_toggle_allowed = true;
else
ips->turbo_toggle_allowed = false;
if (strstr(boot_cpu_data.x86_model_id, "CPU M"))
limits = &ips_sv_limits;
else if (strstr(boot_cpu_data.x86_model_id, "CPU L"))
limits = &ips_lv_limits;
else if (strstr(boot_cpu_data.x86_model_id, "CPU U"))
limits = &ips_ulv_limits;
else {
dev_info(&ips->dev->dev, "No CPUID match found.\n");
goto out;
}
rdmsrl(TURBO_POWER_CURRENT_LIMIT, turbo_power);
tdp = turbo_power & TURBO_TDP_MASK;
if (limits->core_power_limit != (tdp / 8) * 1000) {
dev_info(&ips->dev->dev, "CPU TDP doesn't match expected value (found %d, expected %d)\n",
tdp / 8, limits->core_power_limit / 1000);
limits->core_power_limit = (tdp / 8) * 1000;
}
out:
return limits;
}
static bool ips_get_i915_syms(struct ips_driver *ips)
{
ips->read_mch_val = symbol_get(i915_read_mch_val);
if (!ips->read_mch_val)
goto out_err;
ips->gpu_raise = symbol_get(i915_gpu_raise);
if (!ips->gpu_raise)
goto out_put_mch;
ips->gpu_lower = symbol_get(i915_gpu_lower);
if (!ips->gpu_lower)
goto out_put_raise;
ips->gpu_busy = symbol_get(i915_gpu_busy);
if (!ips->gpu_busy)
goto out_put_lower;
ips->gpu_turbo_disable = symbol_get(i915_gpu_turbo_disable);
if (!ips->gpu_turbo_disable)
goto out_put_busy;
return true;
out_put_busy:
symbol_put(i915_gpu_busy);
out_put_lower:
symbol_put(i915_gpu_lower);
out_put_raise:
symbol_put(i915_gpu_raise);
out_put_mch:
symbol_put(i915_read_mch_val);
out_err:
return false;
}
static bool
ips_gpu_turbo_enabled(struct ips_driver *ips)
{
if (!ips->gpu_busy && late_i915_load) {
if (ips_get_i915_syms(ips)) {
dev_info(&ips->dev->dev,
"i915 driver attached, reenabling gpu turbo\n");
ips->gpu_turbo_enabled = !(thm_readl(THM_HTS) & HTS_GTD_DIS);
}
}
return ips->gpu_turbo_enabled;
}
void
ips_link_to_i915_driver(void)
{
late_i915_load = true;
}
static int ips_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
u64 platform_info;
struct ips_driver *ips;
u32 hts;
int ret = 0;
u16 htshi, trc, trc_required_mask;
u8 tse;
ips = kzalloc(sizeof(struct ips_driver), GFP_KERNEL);
if (!ips)
return -ENOMEM;
pci_set_drvdata(dev, ips);
ips->dev = dev;
ips->limits = ips_detect_cpu(ips);
if (!ips->limits) {
dev_info(&dev->dev, "IPS not supported on this CPU\n");
ret = -ENXIO;
goto error_free;
}
spin_lock_init(&ips->turbo_status_lock);
ret = pci_enable_device(dev);
if (ret) {
dev_err(&dev->dev, "can't enable PCI device, aborting\n");
goto error_free;
}
if (!pci_resource_start(dev, 0)) {
dev_err(&dev->dev, "TBAR not assigned, aborting\n");
ret = -ENXIO;
goto error_free;
}
ret = pci_request_regions(dev, "ips thermal sensor");
if (ret) {
dev_err(&dev->dev, "thermal resource busy, aborting\n");
goto error_free;
}
ips->regmap = ioremap(pci_resource_start(dev, 0),
pci_resource_len(dev, 0));
if (!ips->regmap) {
dev_err(&dev->dev, "failed to map thermal regs, aborting\n");
ret = -EBUSY;
goto error_release;
}
tse = thm_readb(THM_TSE);
if (tse != TSE_EN) {
dev_err(&dev->dev, "thermal device not enabled (0x%02x), aborting\n", tse);
ret = -ENXIO;
goto error_unmap;
}
trc = thm_readw(THM_TRC);
trc_required_mask = TRC_CORE1_EN | TRC_CORE_PWR | TRC_MCH_EN;
if ((trc & trc_required_mask) != trc_required_mask) {
dev_err(&dev->dev, "thermal reporting for required devices not enabled, aborting\n");
ret = -ENXIO;
goto error_unmap;
}
if (trc & TRC_CORE2_EN)
ips->second_cpu = true;
update_turbo_limits(ips);
dev_dbg(&dev->dev, "max cpu power clamp: %dW\n",
ips->mcp_power_limit / 10);
dev_dbg(&dev->dev, "max core power clamp: %dW\n",
ips->core_power_limit / 10);
if (thm_readl(THM_PSC) & PSP_PBRT)
ips->poll_turbo_status = true;
if (!ips_get_i915_syms(ips)) {
dev_err(&dev->dev, "failed to get i915 symbols, graphics turbo disabled\n");
ips->gpu_turbo_enabled = false;
} else {
dev_dbg(&dev->dev, "graphics turbo enabled\n");
ips->gpu_turbo_enabled = true;
}
rdmsrl(PLATFORM_INFO, platform_info);
if (!(platform_info & PLATFORM_TDP)) {
dev_err(&dev->dev, "platform indicates TDP override unavailable, aborting\n");
ret = -ENODEV;
goto error_unmap;
}
pci_disable_msi(dev);
ret = request_irq(dev->irq, ips_irq_handler, IRQF_SHARED, "ips",
ips);
if (ret) {
dev_err(&dev->dev, "request irq failed, aborting\n");
goto error_unmap;
}
thm_writeb(THM_TSPIEN, TSPIEN_AUX2_LOHI | TSPIEN_CRIT_LOHI |
TSPIEN_HOT_LOHI | TSPIEN_AUX_LOHI);
thm_writeb(THM_TEN, TEN_UPDATE_EN);
ips->cta_val = thm_readw(THM_CTA);
ips->pta_val = thm_readw(THM_PTA);
ips->mgta_val = thm_readw(THM_MGTA);
rdmsrl(TURBO_POWER_CURRENT_LIMIT, ips->orig_turbo_limit);
ips_disable_cpu_turbo(ips);
ips->cpu_turbo_enabled = false;
ips->adjust = kthread_create(ips_adjust, ips, "ips-adjust");
if (IS_ERR(ips->adjust)) {
dev_err(&dev->dev,
"failed to create thermal adjust thread, aborting\n");
ret = -ENOMEM;
goto error_free_irq;
}
ips->monitor = kthread_run(ips_monitor, ips, "ips-monitor");
if (IS_ERR(ips->monitor)) {
dev_err(&dev->dev,
"failed to create thermal monitor thread, aborting\n");
ret = -ENOMEM;
goto error_thread_cleanup;
}
hts = (ips->core_power_limit << HTS_PCPL_SHIFT) |
(ips->mcp_temp_limit << HTS_PTL_SHIFT) | HTS_NVV;
htshi = HTS2_PRST_RUNNING << HTS2_PRST_SHIFT;
thm_writew(THM_HTSHI, htshi);
thm_writel(THM_HTS, hts);
ips_debugfs_init(ips);
dev_info(&dev->dev, "IPS driver initialized, MCP temp limit %d\n",
ips->mcp_temp_limit);
return ret;
error_thread_cleanup:
kthread_stop(ips->adjust);
error_free_irq:
free_irq(ips->dev->irq, ips);
error_unmap:
iounmap(ips->regmap);
error_release:
pci_release_regions(dev);
error_free:
kfree(ips);
return ret;
}
static void ips_remove(struct pci_dev *dev)
{
struct ips_driver *ips = pci_get_drvdata(dev);
u64 turbo_override;
if (!ips)
return;
ips_debugfs_cleanup(ips);
if (ips->read_mch_val)
symbol_put(i915_read_mch_val);
if (ips->gpu_raise)
symbol_put(i915_gpu_raise);
if (ips->gpu_lower)
symbol_put(i915_gpu_lower);
if (ips->gpu_busy)
symbol_put(i915_gpu_busy);
if (ips->gpu_turbo_disable)
symbol_put(i915_gpu_turbo_disable);
rdmsrl(TURBO_POWER_CURRENT_LIMIT, turbo_override);
turbo_override &= ~(TURBO_TDC_OVR_EN | TURBO_TDP_OVR_EN);
wrmsrl(TURBO_POWER_CURRENT_LIMIT, turbo_override);
wrmsrl(TURBO_POWER_CURRENT_LIMIT, ips->orig_turbo_limit);
free_irq(ips->dev->irq, ips);
if (ips->adjust)
kthread_stop(ips->adjust);
if (ips->monitor)
kthread_stop(ips->monitor);
iounmap(ips->regmap);
pci_release_regions(dev);
kfree(ips);
dev_dbg(&dev->dev, "IPS driver removed\n");
}
static int ips_suspend(struct pci_dev *dev, pm_message_t state)
{
return 0;
}
static int ips_resume(struct pci_dev *dev)
{
return 0;
}
static void ips_shutdown(struct pci_dev *dev)
{
}
static int __init ips_init(void)
{
return pci_register_driver(&ips_pci_driver);
}
static void ips_exit(void)
{
pci_unregister_driver(&ips_pci_driver);
return;
}
