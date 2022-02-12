static int cmci_supported(int *banks)
{
u64 cap;
if (mca_cfg.cmci_disabled || mca_cfg.ignore_ce)
return 0;
if (boot_cpu_data.x86_vendor != X86_VENDOR_INTEL)
return 0;
if (!cpu_has_apic || lapic_get_maxlvt() < 6)
return 0;
rdmsrl(MSR_IA32_MCG_CAP, cap);
*banks = min_t(unsigned, MAX_NR_BANKS, cap & 0xff);
return !!(cap & MCG_CMCI_P);
}
void mce_intel_cmci_poll(void)
{
if (__this_cpu_read(cmci_storm_state) == CMCI_STORM_NONE)
return;
machine_check_poll(MCP_TIMESTAMP, &__get_cpu_var(mce_banks_owned));
}
void mce_intel_hcpu_update(unsigned long cpu)
{
if (per_cpu(cmci_storm_state, cpu) == CMCI_STORM_ACTIVE)
atomic_dec(&cmci_storm_on_cpus);
per_cpu(cmci_storm_state, cpu) = CMCI_STORM_NONE;
}
unsigned long mce_intel_adjust_timer(unsigned long interval)
{
int r;
if (interval < CMCI_POLL_INTERVAL)
return interval;
switch (__this_cpu_read(cmci_storm_state)) {
case CMCI_STORM_ACTIVE:
__this_cpu_write(cmci_storm_state, CMCI_STORM_SUBSIDED);
r = atomic_sub_return(1, &cmci_storm_on_cpus);
if (r == 0)
pr_notice("CMCI storm subsided: switching to interrupt mode\n");
case CMCI_STORM_SUBSIDED:
if (!atomic_read(&cmci_storm_on_cpus)) {
__this_cpu_write(cmci_storm_state, CMCI_STORM_NONE);
cmci_reenable();
cmci_recheck();
}
return CMCI_POLL_INTERVAL;
default:
return interval;
}
}
static bool cmci_storm_detect(void)
{
unsigned int cnt = __this_cpu_read(cmci_storm_cnt);
unsigned long ts = __this_cpu_read(cmci_time_stamp);
unsigned long now = jiffies;
int r;
if (__this_cpu_read(cmci_storm_state) != CMCI_STORM_NONE)
return true;
if (time_before_eq(now, ts + CMCI_STORM_INTERVAL)) {
cnt++;
} else {
cnt = 1;
__this_cpu_write(cmci_time_stamp, now);
}
__this_cpu_write(cmci_storm_cnt, cnt);
if (cnt <= CMCI_STORM_THRESHOLD)
return false;
cmci_clear();
__this_cpu_write(cmci_storm_state, CMCI_STORM_ACTIVE);
r = atomic_add_return(1, &cmci_storm_on_cpus);
mce_timer_kick(CMCI_POLL_INTERVAL);
if (r == 1)
pr_notice("CMCI storm detected: switching to poll mode\n");
return true;
}
static void intel_threshold_interrupt(void)
{
if (cmci_storm_detect())
return;
machine_check_poll(MCP_TIMESTAMP, &__get_cpu_var(mce_banks_owned));
mce_notify_irq();
}
static void cmci_discover(int banks)
{
unsigned long *owned = (void *)&__get_cpu_var(mce_banks_owned);
unsigned long flags;
int i;
int bios_wrong_thresh = 0;
raw_spin_lock_irqsave(&cmci_discover_lock, flags);
for (i = 0; i < banks; i++) {
u64 val;
int bios_zero_thresh = 0;
if (test_bit(i, owned))
continue;
rdmsrl(MSR_IA32_MCx_CTL2(i), val);
if (val & MCI_CTL2_CMCI_EN) {
clear_bit(i, owned);
__clear_bit(i, __get_cpu_var(mce_poll_banks));
continue;
}
if (!mca_cfg.bios_cmci_threshold) {
val &= ~MCI_CTL2_CMCI_THRESHOLD_MASK;
val |= CMCI_THRESHOLD;
} else if (!(val & MCI_CTL2_CMCI_THRESHOLD_MASK)) {
bios_zero_thresh = 1;
val |= CMCI_THRESHOLD;
}
val |= MCI_CTL2_CMCI_EN;
wrmsrl(MSR_IA32_MCx_CTL2(i), val);
rdmsrl(MSR_IA32_MCx_CTL2(i), val);
if (val & MCI_CTL2_CMCI_EN) {
set_bit(i, owned);
__clear_bit(i, __get_cpu_var(mce_poll_banks));
if (mca_cfg.bios_cmci_threshold && bios_zero_thresh &&
(val & MCI_CTL2_CMCI_THRESHOLD_MASK))
bios_wrong_thresh = 1;
} else {
WARN_ON(!test_bit(i, __get_cpu_var(mce_poll_banks)));
}
}
raw_spin_unlock_irqrestore(&cmci_discover_lock, flags);
if (mca_cfg.bios_cmci_threshold && bios_wrong_thresh) {
pr_info_once(
"bios_cmci_threshold: Some banks do not have valid thresholds set\n");
pr_info_once(
"bios_cmci_threshold: Make sure your BIOS supports this boot option\n");
}
}
void cmci_recheck(void)
{
unsigned long flags;
int banks;
if (!mce_available(__this_cpu_ptr(&cpu_info)) || !cmci_supported(&banks))
return;
local_irq_save(flags);
machine_check_poll(MCP_TIMESTAMP, &__get_cpu_var(mce_banks_owned));
local_irq_restore(flags);
}
void cmci_clear(void)
{
unsigned long flags;
int i;
int banks;
u64 val;
if (!cmci_supported(&banks))
return;
raw_spin_lock_irqsave(&cmci_discover_lock, flags);
for (i = 0; i < banks; i++) {
if (!test_bit(i, __get_cpu_var(mce_banks_owned)))
continue;
rdmsrl(MSR_IA32_MCx_CTL2(i), val);
val &= ~MCI_CTL2_CMCI_EN;
wrmsrl(MSR_IA32_MCx_CTL2(i), val);
__clear_bit(i, __get_cpu_var(mce_banks_owned));
}
raw_spin_unlock_irqrestore(&cmci_discover_lock, flags);
}
static long cmci_rediscover_work_func(void *arg)
{
int banks;
if (cmci_supported(&banks))
cmci_discover(banks);
return 0;
}
void cmci_rediscover(int dying)
{
int cpu, banks;
if (!cmci_supported(&banks))
return;
for_each_online_cpu(cpu) {
if (cpu == dying)
continue;
if (cpu == smp_processor_id()) {
cmci_rediscover_work_func(NULL);
continue;
}
work_on_cpu(cpu, cmci_rediscover_work_func, NULL);
}
}
void cmci_reenable(void)
{
int banks;
if (cmci_supported(&banks))
cmci_discover(banks);
}
static void intel_init_cmci(void)
{
int banks;
if (!cmci_supported(&banks))
return;
mce_threshold_vector = intel_threshold_interrupt;
cmci_discover(banks);
apic_write(APIC_LVTCMCI, THRESHOLD_APIC_VECTOR|APIC_DM_FIXED);
cmci_recheck();
}
void mce_intel_feature_init(struct cpuinfo_x86 *c)
{
intel_init_thermal(c);
intel_init_cmci();
}
