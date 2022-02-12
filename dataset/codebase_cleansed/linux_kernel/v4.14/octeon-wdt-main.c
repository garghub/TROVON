static int cpu2core(int cpu)
{
#ifdef CONFIG_SMP
return cpu_logical_map(cpu) & 0x3f;
#else
return cvmx_get_core_num();
#endif
}
static irqreturn_t octeon_wdt_poke_irq(int cpl, void *dev_id)
{
int cpu = raw_smp_processor_id();
unsigned int core = cpu2core(cpu);
int node = cpu_to_node(cpu);
if (do_countdown) {
if (per_cpu_countdown[cpu] > 0) {
cvmx_write_csr_node(node, CVMX_CIU_PP_POKEX(core), 1);
per_cpu_countdown[cpu]--;
} else {
disable_irq_nosync(cpl);
cpumask_clear_cpu(cpu, &irq_enabled_cpus);
}
} else {
cvmx_write_csr_node(node, CVMX_CIU_PP_POKEX(core), 1);
}
return IRQ_HANDLED;
}
static void octeon_wdt_write_string(const char *str)
{
while (*str)
prom_putchar(*str++);
}
static void octeon_wdt_write_hex(u64 value, int digits)
{
int d;
int v;
for (d = 0; d < digits; d++) {
v = (value >> ((digits - d - 1) * 4)) & 0xf;
if (v >= 10)
prom_putchar('a' + v - 10);
else
prom_putchar('0' + v);
}
}
void octeon_wdt_nmi_stage3(u64 reg[32])
{
u64 i;
unsigned int coreid = cvmx_get_core_num();
u64 cp0_cause = read_c0_cause();
u64 cp0_status = read_c0_status();
u64 cp0_error_epc = read_c0_errorepc();
u64 cp0_epc = read_c0_epc();
udelay(85000 * coreid);
octeon_wdt_write_string("\r\n*** NMI Watchdog interrupt on Core 0x");
octeon_wdt_write_hex(coreid, 2);
octeon_wdt_write_string(" ***\r\n");
for (i = 0; i < 32; i++) {
octeon_wdt_write_string("\t");
octeon_wdt_write_string(reg_name[i]);
octeon_wdt_write_string("\t0x");
octeon_wdt_write_hex(reg[i], 16);
if (i & 1)
octeon_wdt_write_string("\r\n");
}
octeon_wdt_write_string("\terr_epc\t0x");
octeon_wdt_write_hex(cp0_error_epc, 16);
octeon_wdt_write_string("\tepc\t0x");
octeon_wdt_write_hex(cp0_epc, 16);
octeon_wdt_write_string("\r\n");
octeon_wdt_write_string("\tstatus\t0x");
octeon_wdt_write_hex(cp0_status, 16);
octeon_wdt_write_string("\tcause\t0x");
octeon_wdt_write_hex(cp0_cause, 16);
octeon_wdt_write_string("\r\n");
if (OCTEON_IS_MODEL(OCTEON_CN68XX)) {
octeon_wdt_write_string("\tsrc_wd\t0x");
octeon_wdt_write_hex(cvmx_read_csr(CVMX_CIU2_SRC_PPX_IP2_WDOG(coreid)), 16);
octeon_wdt_write_string("\ten_wd\t0x");
octeon_wdt_write_hex(cvmx_read_csr(CVMX_CIU2_EN_PPX_IP2_WDOG(coreid)), 16);
octeon_wdt_write_string("\r\n");
octeon_wdt_write_string("\tsrc_rml\t0x");
octeon_wdt_write_hex(cvmx_read_csr(CVMX_CIU2_SRC_PPX_IP2_RML(coreid)), 16);
octeon_wdt_write_string("\ten_rml\t0x");
octeon_wdt_write_hex(cvmx_read_csr(CVMX_CIU2_EN_PPX_IP2_RML(coreid)), 16);
octeon_wdt_write_string("\r\n");
octeon_wdt_write_string("\tsum\t0x");
octeon_wdt_write_hex(cvmx_read_csr(CVMX_CIU2_SUM_PPX_IP2(coreid)), 16);
octeon_wdt_write_string("\r\n");
} else if (!octeon_has_feature(OCTEON_FEATURE_CIU3)) {
octeon_wdt_write_string("\tsum0\t0x");
octeon_wdt_write_hex(cvmx_read_csr(CVMX_CIU_INTX_SUM0(coreid * 2)), 16);
octeon_wdt_write_string("\ten0\t0x");
octeon_wdt_write_hex(cvmx_read_csr(CVMX_CIU_INTX_EN0(coreid * 2)), 16);
octeon_wdt_write_string("\r\n");
}
octeon_wdt_write_string("*** Chip soft reset soon ***\r\n");
if (OCTEON_IS_OCTEON3() && !OCTEON_IS_MODEL(OCTEON_CN70XX)) {
u64 scr;
unsigned int node = cvmx_get_node_num();
unsigned int lcore = cvmx_get_local_core_num();
union cvmx_ciu_wdogx ciu_wdog;
do {
ciu_wdog.u64 = cvmx_read_csr_node(node, CVMX_CIU_WDOGX(lcore));
} while (ciu_wdog.s.cnt > 0x10000);
scr = cvmx_read_csr_node(0, CVMX_GSERX_SCRATCH(0));
scr |= 1 << 11;
cvmx_write_csr_node(0, CVMX_GSERX_SCRATCH(0), scr);
cvmx_write_csr_node(0, CVMX_RST_SOFT_RST, 1);
}
}
static int octeon_wdt_cpu_to_irq(int cpu)
{
unsigned int coreid;
int node;
int irq;
coreid = cpu2core(cpu);
node = cpu_to_node(cpu);
if (octeon_has_feature(OCTEON_FEATURE_CIU3)) {
struct irq_domain *domain;
int hwirq;
domain = octeon_irq_get_block_domain(node,
WD_BLOCK_NUMBER);
hwirq = WD_BLOCK_NUMBER << 12 | 0x200 | coreid;
irq = irq_find_mapping(domain, hwirq);
} else {
irq = OCTEON_IRQ_WDOG0 + coreid;
}
return irq;
}
static int octeon_wdt_cpu_pre_down(unsigned int cpu)
{
unsigned int core;
int node;
union cvmx_ciu_wdogx ciu_wdog;
core = cpu2core(cpu);
node = cpu_to_node(cpu);
cvmx_write_csr_node(node, CVMX_CIU_PP_POKEX(core), 1);
ciu_wdog.u64 = 0;
cvmx_write_csr_node(node, CVMX_CIU_WDOGX(core), ciu_wdog.u64);
free_irq(octeon_wdt_cpu_to_irq(cpu), octeon_wdt_poke_irq);
return 0;
}
static int octeon_wdt_cpu_online(unsigned int cpu)
{
unsigned int core;
unsigned int irq;
union cvmx_ciu_wdogx ciu_wdog;
int node;
struct irq_domain *domain;
int hwirq;
core = cpu2core(cpu);
node = cpu_to_node(cpu);
octeon_wdt_bootvector[core].target_ptr = (u64)octeon_wdt_nmi_stage2;
ciu_wdog.u64 = 0;
cvmx_write_csr_node(node, CVMX_CIU_WDOGX(core), ciu_wdog.u64);
per_cpu_countdown[cpu] = countdown_reset;
if (octeon_has_feature(OCTEON_FEATURE_CIU3)) {
domain = octeon_irq_get_block_domain(node, WD_BLOCK_NUMBER);
hwirq = WD_BLOCK_NUMBER << 12 | 0x200 | core;
irq = irq_create_mapping(domain, hwirq);
irqd_set_trigger_type(irq_get_irq_data(irq),
IRQ_TYPE_EDGE_RISING);
} else
irq = OCTEON_IRQ_WDOG0 + core;
if (request_irq(irq, octeon_wdt_poke_irq,
IRQF_NO_THREAD, "octeon_wdt", octeon_wdt_poke_irq))
panic("octeon_wdt: Couldn't obtain irq %d", irq);
if (octeon_has_feature(OCTEON_FEATURE_CIU3)) {
cpumask_t mask;
cpumask_clear(&mask);
cpumask_set_cpu(cpu, &mask);
irq_set_affinity(irq, &mask);
}
cpumask_set_cpu(cpu, &irq_enabled_cpus);
cvmx_write_csr_node(node, CVMX_CIU_PP_POKEX(core), 1);
ciu_wdog.u64 = 0;
ciu_wdog.s.len = timeout_cnt;
ciu_wdog.s.mode = 3;
cvmx_write_csr_node(node, CVMX_CIU_WDOGX(core), ciu_wdog.u64);
return 0;
}
static int octeon_wdt_ping(struct watchdog_device __always_unused *wdog)
{
int cpu;
int coreid;
int node;
if (disable)
return 0;
for_each_online_cpu(cpu) {
coreid = cpu2core(cpu);
node = cpu_to_node(cpu);
cvmx_write_csr_node(node, CVMX_CIU_PP_POKEX(coreid), 1);
per_cpu_countdown[cpu] = countdown_reset;
if ((countdown_reset || !do_countdown) &&
!cpumask_test_cpu(cpu, &irq_enabled_cpus)) {
enable_irq(octeon_wdt_cpu_to_irq(cpu));
cpumask_set_cpu(cpu, &irq_enabled_cpus);
}
}
return 0;
}
static void octeon_wdt_calc_parameters(int t)
{
unsigned int periods;
timeout_sec = max_timeout_sec;
while ((t % timeout_sec) != 0)
timeout_sec--;
periods = t / timeout_sec;
countdown_reset = periods > 2 ? periods - 2 : 0;
heartbeat = t;
timeout_cnt = ((octeon_get_io_clock_rate() / divisor) * timeout_sec) >> 8;
}
static int octeon_wdt_set_timeout(struct watchdog_device *wdog,
unsigned int t)
{
int cpu;
int coreid;
union cvmx_ciu_wdogx ciu_wdog;
int node;
if (t <= 0)
return -1;
octeon_wdt_calc_parameters(t);
if (disable)
return 0;
for_each_online_cpu(cpu) {
coreid = cpu2core(cpu);
node = cpu_to_node(cpu);
cvmx_write_csr_node(node, CVMX_CIU_PP_POKEX(coreid), 1);
ciu_wdog.u64 = 0;
ciu_wdog.s.len = timeout_cnt;
ciu_wdog.s.mode = 3;
cvmx_write_csr_node(node, CVMX_CIU_WDOGX(coreid), ciu_wdog.u64);
cvmx_write_csr_node(node, CVMX_CIU_PP_POKEX(coreid), 1);
}
octeon_wdt_ping(wdog);
return 0;
}
static int octeon_wdt_start(struct watchdog_device *wdog)
{
octeon_wdt_ping(wdog);
do_countdown = 1;
return 0;
}
static int octeon_wdt_stop(struct watchdog_device *wdog)
{
do_countdown = 0;
octeon_wdt_ping(wdog);
return 0;
}
static int __init octeon_wdt_init(void)
{
int ret;
octeon_wdt_bootvector = cvmx_boot_vector_get();
if (!octeon_wdt_bootvector) {
pr_err("Error: Cannot allocate boot vector.\n");
return -ENOMEM;
}
if (OCTEON_IS_MODEL(OCTEON_CN68XX))
divisor = 0x200;
else if (OCTEON_IS_MODEL(OCTEON_CN78XX))
divisor = 0x400;
else
divisor = 0x100;
max_timeout_sec = 6;
do {
max_timeout_sec--;
timeout_cnt = ((octeon_get_io_clock_rate() / divisor) * max_timeout_sec) >> 8;
} while (timeout_cnt > 65535);
BUG_ON(timeout_cnt == 0);
octeon_wdt_calc_parameters(heartbeat);
pr_info("Initial granularity %d Sec\n", timeout_sec);
octeon_wdt.timeout = timeout_sec;
octeon_wdt.max_timeout = UINT_MAX;
watchdog_set_nowayout(&octeon_wdt, nowayout);
ret = watchdog_register_device(&octeon_wdt);
if (ret) {
pr_err("watchdog_register_device() failed: %d\n", ret);
return ret;
}
if (disable) {
pr_notice("disabled\n");
return 0;
}
cpumask_clear(&irq_enabled_cpus);
ret = cpuhp_setup_state(CPUHP_AP_ONLINE_DYN, "watchdog/octeon:online",
octeon_wdt_cpu_online, octeon_wdt_cpu_pre_down);
if (ret < 0)
goto err;
octeon_wdt_online = ret;
return 0;
err:
cvmx_write_csr(CVMX_MIO_BOOT_LOC_CFGX(0), 0);
watchdog_unregister_device(&octeon_wdt);
return ret;
}
static void __exit octeon_wdt_cleanup(void)
{
watchdog_unregister_device(&octeon_wdt);
if (disable)
return;
cpuhp_remove_state(octeon_wdt_online);
cvmx_write_csr(CVMX_MIO_BOOT_LOC_CFGX(0), 0);
}
