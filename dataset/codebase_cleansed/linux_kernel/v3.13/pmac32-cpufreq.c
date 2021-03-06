static inline void local_delay(unsigned long ms)
{
if (no_schedule)
mdelay(ms);
else
msleep(ms);
}
static inline void debug_calc_bogomips(void)
{
unsigned long save_lpj = loops_per_jiffy;
calibrate_delay();
loops_per_jiffy = save_lpj;
}
static int cpu_750fx_cpu_speed(int low_speed)
{
u32 hid2;
if (low_speed == 0) {
pmac_call_feature(PMAC_FTR_WRITE_GPIO, NULL, voltage_gpio, 0x05);
local_delay(10);
if (has_cpu_l2lve) {
hid2 = mfspr(SPRN_HID2);
hid2 &= ~0x2000;
mtspr(SPRN_HID2, hid2);
}
}
#ifdef CONFIG_6xx
low_choose_750fx_pll(low_speed);
#endif
if (low_speed == 1) {
if (has_cpu_l2lve) {
hid2 = mfspr(SPRN_HID2);
hid2 |= 0x2000;
mtspr(SPRN_HID2, hid2);
}
pmac_call_feature(PMAC_FTR_WRITE_GPIO, NULL, voltage_gpio, 0x04);
local_delay(10);
}
return 0;
}
static unsigned int cpu_750fx_get_cpu_speed(void)
{
if (mfspr(SPRN_HID1) & HID1_PS)
return low_freq;
else
return hi_freq;
}
static int dfs_set_cpu_speed(int low_speed)
{
if (low_speed == 0) {
pmac_call_feature(PMAC_FTR_WRITE_GPIO, NULL, voltage_gpio, 0x05);
local_delay(1);
}
#ifdef CONFIG_6xx
low_choose_7447a_dfs(low_speed);
#endif
udelay(100);
if (low_speed == 1) {
pmac_call_feature(PMAC_FTR_WRITE_GPIO, NULL, voltage_gpio, 0x04);
local_delay(1);
}
return 0;
}
static unsigned int dfs_get_cpu_speed(void)
{
if (mfspr(SPRN_HID1) & HID1_DFS)
return low_freq;
else
return hi_freq;
}
static int gpios_set_cpu_speed(int low_speed)
{
int gpio, timeout = 0;
if (low_speed == 0) {
pmac_call_feature(PMAC_FTR_WRITE_GPIO, NULL, voltage_gpio, 0x05);
local_delay(10);
}
gpio = pmac_call_feature(PMAC_FTR_READ_GPIO, NULL, frequency_gpio, 0);
if (low_speed == ((gpio & 0x01) == 0))
goto skip;
pmac_call_feature(PMAC_FTR_WRITE_GPIO, NULL, frequency_gpio,
low_speed ? 0x04 : 0x05);
udelay(200);
do {
if (++timeout > 100)
break;
local_delay(1);
gpio = pmac_call_feature(PMAC_FTR_READ_GPIO, NULL, slew_done_gpio, 0);
} while((gpio & 0x02) == 0);
skip:
if (low_speed == 1) {
pmac_call_feature(PMAC_FTR_WRITE_GPIO, NULL, voltage_gpio, 0x04);
local_delay(10);
}
#ifdef DEBUG_FREQ
debug_calc_bogomips();
#endif
return 0;
}
static int pmu_set_cpu_speed(int low_speed)
{
struct adb_request req;
unsigned long save_l2cr;
unsigned long save_l3cr;
unsigned int pic_prio;
unsigned long flags;
preempt_disable();
#ifdef DEBUG_FREQ
printk(KERN_DEBUG "HID1, before: %x\n", mfspr(SPRN_HID1));
#endif
pmu_suspend();
pic_prio = mpic_cpu_get_priority();
mpic_cpu_set_priority(0xf);
asm volatile("mtdec %0" : : "r" (0x7fffffff));
mb();
asm volatile("mtdec %0" : : "r" (0x7fffffff));
local_irq_save(flags);
enable_kernel_fp();
#ifdef CONFIG_ALTIVEC
if (cpu_has_feature(CPU_FTR_ALTIVEC))
enable_kernel_altivec();
#endif
save_l3cr = _get_L3CR();
save_l2cr = _get_L2CR();
pmu_request(&req, NULL, 6, PMU_CPU_SPEED, 'W', 'O', 'O', 'F', low_speed);
while (!req.complete)
pmu_poll();
pmac_call_feature(PMAC_FTR_SLEEP_STATE,NULL,1,1);
low_sleep_handler();
pmac_call_feature(PMAC_FTR_SLEEP_STATE,NULL,1,0);
if (save_l2cr != 0xffffffff && (save_l2cr & L2CR_L2E) != 0)
_set_L2CR(save_l2cr);
if (save_l3cr != 0xffffffff && (save_l3cr & L3CR_L3E) != 0)
_set_L3CR(save_l3cr);
switch_mmu_context(NULL, current->active_mm);
#ifdef DEBUG_FREQ
printk(KERN_DEBUG "HID1, after: %x\n", mfspr(SPRN_HID1));
#endif
pmu_unlock();
set_dec(1);
mpic_cpu_set_priority(pic_prio);
local_irq_restore(flags);
#ifdef DEBUG_FREQ
debug_calc_bogomips();
#endif
pmu_resume();
preempt_enable();
return 0;
}
static int do_set_cpu_speed(struct cpufreq_policy *policy, int speed_mode)
{
unsigned long l3cr;
static unsigned long prev_l3cr;
if (speed_mode == CPUFREQ_LOW &&
cpu_has_feature(CPU_FTR_L3CR)) {
l3cr = _get_L3CR();
if (l3cr & L3CR_L3E) {
prev_l3cr = l3cr;
_set_L3CR(0);
}
}
set_speed_proc(speed_mode == CPUFREQ_LOW);
if (speed_mode == CPUFREQ_HIGH &&
cpu_has_feature(CPU_FTR_L3CR)) {
l3cr = _get_L3CR();
if ((prev_l3cr & L3CR_L3E) && l3cr != prev_l3cr)
_set_L3CR(prev_l3cr);
}
cur_freq = (speed_mode == CPUFREQ_HIGH) ? hi_freq : low_freq;
return 0;
}
static unsigned int pmac_cpufreq_get_speed(unsigned int cpu)
{
return cur_freq;
}
static int pmac_cpufreq_target( struct cpufreq_policy *policy,
unsigned int index)
{
int rc;
rc = do_set_cpu_speed(policy, index);
ppc_proc_freq = cur_freq * 1000ul;
return rc;
}
static int pmac_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
return cpufreq_generic_init(policy, pmac_cpu_freqs, transition_latency);
}
static u32 read_gpio(struct device_node *np)
{
const u32 *reg = of_get_property(np, "reg", NULL);
u32 offset;
if (reg == NULL)
return 0;
offset = *reg;
if (offset < KEYLARGO_GPIO_LEVELS0)
offset += KEYLARGO_GPIO_LEVELS0;
return offset;
}
static int pmac_cpufreq_suspend(struct cpufreq_policy *policy)
{
no_schedule = 1;
sleep_freq = cur_freq;
if (cur_freq == low_freq && !is_pmu_based)
do_set_cpu_speed(policy, CPUFREQ_HIGH);
return 0;
}
static int pmac_cpufreq_resume(struct cpufreq_policy *policy)
{
if (get_speed_proc)
cur_freq = get_speed_proc();
else
cur_freq = 0;
do_set_cpu_speed(policy, sleep_freq == low_freq ?
CPUFREQ_LOW : CPUFREQ_HIGH);
ppc_proc_freq = cur_freq * 1000ul;
no_schedule = 0;
return 0;
}
static int pmac_cpufreq_init_MacRISC3(struct device_node *cpunode)
{
struct device_node *volt_gpio_np = of_find_node_by_name(NULL,
"voltage-gpio");
struct device_node *freq_gpio_np = of_find_node_by_name(NULL,
"frequency-gpio");
struct device_node *slew_done_gpio_np = of_find_node_by_name(NULL,
"slewing-done");
const u32 *value;
if (volt_gpio_np)
voltage_gpio = read_gpio(volt_gpio_np);
if (freq_gpio_np)
frequency_gpio = read_gpio(freq_gpio_np);
if (slew_done_gpio_np)
slew_done_gpio = read_gpio(slew_done_gpio_np);
if (frequency_gpio && slew_done_gpio) {
int lenp, rc;
const u32 *freqs, *ratio;
freqs = of_get_property(cpunode, "bus-frequencies", &lenp);
lenp /= sizeof(u32);
if (freqs == NULL || lenp != 2) {
printk(KERN_ERR "cpufreq: bus-frequencies incorrect or missing\n");
return 1;
}
ratio = of_get_property(cpunode, "processor-to-bus-ratio*2",
NULL);
if (ratio == NULL) {
printk(KERN_ERR "cpufreq: processor-to-bus-ratio*2 missing\n");
return 1;
}
low_freq = min(freqs[0], freqs[1]);
hi_freq = max(freqs[0], freqs[1]);
if (low_freq < 98000000)
low_freq = 101000000;
low_freq = (low_freq * (*ratio)) / 2000;
hi_freq = (hi_freq * (*ratio)) / 2000;
rc = pmac_call_feature(PMAC_FTR_READ_GPIO, NULL, frequency_gpio, 0);
cur_freq = (rc & 0x01) ? hi_freq : low_freq;
set_speed_proc = gpios_set_cpu_speed;
return 1;
}
value = of_get_property(cpunode, "min-clock-frequency", NULL);
if (!value)
return 1;
low_freq = (*value) / 1000;
if (low_freq < 100000)
low_freq *= 10;
value = of_get_property(cpunode, "max-clock-frequency", NULL);
if (!value)
return 1;
hi_freq = (*value) / 1000;
set_speed_proc = pmu_set_cpu_speed;
is_pmu_based = 1;
return 0;
}
static int pmac_cpufreq_init_7447A(struct device_node *cpunode)
{
struct device_node *volt_gpio_np;
if (of_get_property(cpunode, "dynamic-power-step", NULL) == NULL)
return 1;
volt_gpio_np = of_find_node_by_name(NULL, "cpu-vcore-select");
if (volt_gpio_np)
voltage_gpio = read_gpio(volt_gpio_np);
if (!voltage_gpio){
printk(KERN_ERR "cpufreq: missing cpu-vcore-select gpio\n");
return 1;
}
hi_freq = cur_freq;
low_freq = cur_freq/2;
cur_freq = dfs_get_cpu_speed();
set_speed_proc = dfs_set_cpu_speed;
get_speed_proc = dfs_get_cpu_speed;
return 0;
}
static int pmac_cpufreq_init_750FX(struct device_node *cpunode)
{
struct device_node *volt_gpio_np;
u32 pvr;
const u32 *value;
if (of_get_property(cpunode, "dynamic-power-step", NULL) == NULL)
return 1;
hi_freq = cur_freq;
value = of_get_property(cpunode, "reduced-clock-frequency", NULL);
if (!value)
return 1;
low_freq = (*value) / 1000;
volt_gpio_np = of_find_node_by_name(NULL, "cpu-vcore-select");
if (volt_gpio_np)
voltage_gpio = read_gpio(volt_gpio_np);
pvr = mfspr(SPRN_PVR);
has_cpu_l2lve = !((pvr & 0xf00) == 0x100);
set_speed_proc = cpu_750fx_cpu_speed;
get_speed_proc = cpu_750fx_get_cpu_speed;
cur_freq = cpu_750fx_get_cpu_speed();
return 0;
}
static int __init pmac_cpufreq_setup(void)
{
struct device_node *cpunode;
const u32 *value;
if (strstr(cmd_line, "nocpufreq"))
return 0;
cpunode = of_cpu_device_node_get(0);
if (!cpunode)
goto out;
value = of_get_property(cpunode, "clock-frequency", NULL);
if (!value)
goto out;
cur_freq = (*value) / 1000;
transition_latency = CPUFREQ_ETERNAL;
if (of_machine_is_compatible("MacRISC3") &&
of_get_property(cpunode, "dynamic-power-step", NULL) &&
PVR_VER(mfspr(SPRN_PVR)) == 0x8003) {
pmac_cpufreq_init_7447A(cpunode);
transition_latency = 8000000;
} else if (of_machine_is_compatible("PowerBook3,4") ||
of_machine_is_compatible("PowerBook3,5") ||
of_machine_is_compatible("MacRISC3")) {
pmac_cpufreq_init_MacRISC3(cpunode);
} else if (of_machine_is_compatible("PowerBook4,1")) {
hi_freq = cur_freq;
low_freq = 400000;
set_speed_proc = pmu_set_cpu_speed;
is_pmu_based = 1;
}
else if (of_machine_is_compatible("PowerBook3,3") && cur_freq == 550000) {
hi_freq = cur_freq;
low_freq = 500000;
set_speed_proc = pmu_set_cpu_speed;
is_pmu_based = 1;
}
else if (of_machine_is_compatible("PowerBook3,2")) {
if (cur_freq < 350000 || cur_freq > 550000)
goto out;
hi_freq = cur_freq;
low_freq = 300000;
set_speed_proc = pmu_set_cpu_speed;
is_pmu_based = 1;
}
else if (PVR_VER(mfspr(SPRN_PVR)) == 0x7000)
pmac_cpufreq_init_750FX(cpunode);
out:
of_node_put(cpunode);
if (set_speed_proc == NULL)
return -ENODEV;
pmac_cpu_freqs[CPUFREQ_LOW].frequency = low_freq;
pmac_cpu_freqs[CPUFREQ_HIGH].frequency = hi_freq;
ppc_proc_freq = cur_freq * 1000ul;
printk(KERN_INFO "Registering PowerMac CPU frequency driver\n");
printk(KERN_INFO "Low: %d Mhz, High: %d Mhz, Boot: %d Mhz\n",
low_freq/1000, hi_freq/1000, cur_freq/1000);
return cpufreq_register_driver(&pmac_cpufreq_driver);
}
