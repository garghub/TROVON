static int param_get_local64(char *buffer, const struct kernel_param *kp)
{
return sprintf(buffer, "%lu\n", local64_read((local64_t *)kp->arg));
}
static int param_set_local64(const char *val, const struct kernel_param *kp)
{
local64_set((local64_t *)kp->arg, 0);
return 0;
}
static int param_get_action(char *buffer, const struct kernel_param *kp)
{
return sprintf(buffer, "%s\n", uv_nmi_action);
}
static int param_set_action(const char *val, const struct kernel_param *kp)
{
int i;
int n = ARRAY_SIZE(valid_acts);
char arg[ACTION_LEN], *p;
strncpy(arg, val, ACTION_LEN - 1);
arg[ACTION_LEN - 1] = '\0';
p = strchr(arg, '\n');
if (p)
*p = '\0';
for (i = 0; i < n; i++)
if (!strcmp(arg, valid_acts[i].action))
break;
if (i < n) {
strcpy(uv_nmi_action, arg);
pr_info("UV: New NMI action:%s\n", uv_nmi_action);
return 0;
}
pr_err("UV: Invalid NMI action:%s, valid actions are:\n", arg);
for (i = 0; i < n; i++)
pr_err("UV: %-8s - %s\n",
valid_acts[i].action, valid_acts[i].desc);
return -EINVAL;
}
static inline bool uv_nmi_action_is(const char *action)
{
return (strncmp(uv_nmi_action, action, strlen(action)) == 0);
}
static void uv_nmi_setup_mmrs(void)
{
if (uv_read_local_mmr(UVH_NMI_MMRX_SUPPORTED)) {
uv_write_local_mmr(UVH_NMI_MMRX_REQ,
1UL << UVH_NMI_MMRX_REQ_SHIFT);
nmi_mmr = UVH_NMI_MMRX;
nmi_mmr_clear = UVH_NMI_MMRX_CLEAR;
nmi_mmr_pending = 1UL << UVH_NMI_MMRX_SHIFT;
pr_info("UV: SMI NMI support: %s\n", UVH_NMI_MMRX_TYPE);
} else {
nmi_mmr = UVH_NMI_MMR;
nmi_mmr_clear = UVH_NMI_MMR_CLEAR;
nmi_mmr_pending = 1UL << UVH_NMI_MMR_SHIFT;
pr_info("UV: SMI NMI support: %s\n", UVH_NMI_MMR_TYPE);
}
}
static inline int uv_nmi_test_mmr(struct uv_hub_nmi_s *hub_nmi)
{
hub_nmi->nmi_value = uv_read_local_mmr(nmi_mmr);
atomic_inc(&hub_nmi->read_mmr_count);
return !!(hub_nmi->nmi_value & nmi_mmr_pending);
}
static inline void uv_local_mmr_clear_nmi(void)
{
uv_write_local_mmr(nmi_mmr_clear, nmi_mmr_pending);
}
static inline void uv_reassert_nmi(void)
{
outb(0x8f, NMI_CONTROL_PORT);
inb(NMI_DUMMY_PORT);
outb(0x0f, NMI_CONTROL_PORT);
inb(NMI_DUMMY_PORT);
}
static void uv_init_hubless_pch_io(int offset, int mask, int data)
{
int *addr = PCH_PCR_GPIO_ADDRESS(offset);
int readd = readl(addr);
if (mask) {
int writed = (readd & ~mask) | data;
nmi_debug("UV:PCH: %p = %x & %x | %x (%x)\n",
addr, readd, ~mask, data, writed);
writel(writed, addr);
} else if (readd & data) {
nmi_debug("UV:PCH: %p = %x\n", addr, data);
writel(data, addr);
}
(void)readl(addr);
}
static void uv_nmi_setup_hubless_intr(void)
{
uv_pch_intr_now_enabled = uv_pch_intr_enable;
uv_init_hubless_pch_io(
PAD_CFG_DW0_GPP_D_0, GPIROUTNMI,
uv_pch_intr_now_enabled ? GPIROUTNMI : 0);
nmi_debug("UV:NMI: GPP_D_0 interrupt %s\n",
uv_pch_intr_now_enabled ? "enabled" : "disabled");
}
static void uv_init_hubless_pch_d0(void)
{
int i, read;
read = *PCH_PCR_GPIO_ADDRESS(PAD_OWN_GPP_D_0);
if (read != 0) {
pr_info("UV: Hubless NMI already configured\n");
return;
}
nmi_debug("UV: Initializing UV Hubless NMI on PCH\n");
for (i = 0; i < ARRAY_SIZE(init_nmi); i++) {
uv_init_hubless_pch_io(init_nmi[i].offset,
init_nmi[i].mask,
init_nmi[i].data);
}
}
static int uv_nmi_test_hubless(struct uv_hub_nmi_s *hub_nmi)
{
int *pstat = PCH_PCR_GPIO_ADDRESS(GPI_NMI_STS_GPP_D_0);
int status = *pstat;
hub_nmi->nmi_value = status;
atomic_inc(&hub_nmi->read_mmr_count);
if (!(status & STS_GPP_D_0_MASK))
return 0;
*pstat = STS_GPP_D_0_MASK;
(void)*pstat;
return 1;
}
static int uv_test_nmi(struct uv_hub_nmi_s *hub_nmi)
{
if (hub_nmi->hub_present)
return uv_nmi_test_mmr(hub_nmi);
if (hub_nmi->pch_owner)
return uv_nmi_test_hubless(hub_nmi);
return -1;
}
static int uv_set_in_nmi(int cpu, struct uv_hub_nmi_s *hub_nmi)
{
int first = atomic_add_unless(&hub_nmi->in_nmi, 1, 1);
if (first) {
atomic_set(&hub_nmi->cpu_owner, cpu);
if (atomic_add_unless(&uv_in_nmi, 1, 1))
atomic_set(&uv_nmi_cpu, cpu);
atomic_inc(&hub_nmi->nmi_count);
}
return first;
}
static int uv_check_nmi(struct uv_hub_nmi_s *hub_nmi)
{
int cpu = smp_processor_id();
int nmi = 0;
int nmi_detected = 0;
local64_inc(&uv_nmi_count);
this_cpu_inc(uv_cpu_nmi.queries);
do {
nmi = atomic_read(&hub_nmi->in_nmi);
if (nmi)
break;
if (raw_spin_trylock(&hub_nmi->nmi_lock)) {
nmi_detected = uv_test_nmi(hub_nmi);
if (nmi_detected > 0) {
uv_set_in_nmi(cpu, hub_nmi);
nmi = 1;
break;
}
else if (nmi_detected < 0)
goto slave_wait;
raw_spin_unlock(&hub_nmi->nmi_lock);
} else {
slave_wait: cpu_relax();
udelay(uv_nmi_slave_delay);
nmi = atomic_read(&hub_nmi->in_nmi);
if (nmi)
break;
}
if (!nmi) {
nmi = atomic_read(&uv_in_nmi);
if (nmi)
uv_set_in_nmi(cpu, hub_nmi);
}
if (nmi_detected < 0)
raw_spin_unlock(&hub_nmi->nmi_lock);
} while (0);
if (!nmi)
local64_inc(&uv_nmi_misses);
return nmi;
}
static inline void uv_clear_nmi(int cpu)
{
struct uv_hub_nmi_s *hub_nmi = uv_hub_nmi;
if (cpu == atomic_read(&hub_nmi->cpu_owner)) {
atomic_set(&hub_nmi->cpu_owner, -1);
atomic_set(&hub_nmi->in_nmi, 0);
if (hub_nmi->hub_present)
uv_local_mmr_clear_nmi();
else
uv_reassert_nmi();
raw_spin_unlock(&hub_nmi->nmi_lock);
}
}
static void uv_nmi_nr_cpus_ping(void)
{
int cpu;
for_each_cpu(cpu, uv_nmi_cpu_mask)
uv_cpu_nmi_per(cpu).pinging = 1;
apic->send_IPI_mask(uv_nmi_cpu_mask, APIC_DM_NMI);
}
static void uv_nmi_cleanup_mask(void)
{
int cpu;
for_each_cpu(cpu, uv_nmi_cpu_mask) {
uv_cpu_nmi_per(cpu).pinging = 0;
uv_cpu_nmi_per(cpu).state = UV_NMI_STATE_OUT;
cpumask_clear_cpu(cpu, uv_nmi_cpu_mask);
}
}
static int uv_nmi_wait_cpus(int first)
{
int i, j, k, n = num_online_cpus();
int last_k = 0, waiting = 0;
int cpu = smp_processor_id();
if (first) {
cpumask_copy(uv_nmi_cpu_mask, cpu_online_mask);
k = 0;
} else {
k = n - cpumask_weight(uv_nmi_cpu_mask);
}
if (first && uv_pch_intr_now_enabled) {
cpumask_clear_cpu(cpu, uv_nmi_cpu_mask);
return n - k - 1;
}
udelay(uv_nmi_initial_delay);
for (i = 0; i < uv_nmi_retry_count; i++) {
int loop_delay = uv_nmi_loop_delay;
for_each_cpu(j, uv_nmi_cpu_mask) {
if (uv_cpu_nmi_per(j).state) {
cpumask_clear_cpu(j, uv_nmi_cpu_mask);
if (++k >= n)
break;
}
}
if (k >= n) {
k = n;
break;
}
if (last_k != k) {
last_k = k;
waiting = 0;
} else if (++waiting > uv_nmi_wait_count)
break;
if (waiting && (n - k) == 1 &&
cpumask_test_cpu(0, uv_nmi_cpu_mask))
loop_delay *= 100;
udelay(loop_delay);
}
atomic_set(&uv_nmi_cpus_in_nmi, k);
return n - k;
}
static void uv_nmi_wait(int master)
{
this_cpu_write(uv_cpu_nmi.state, UV_NMI_STATE_IN);
if (!master)
return;
do {
if (!uv_nmi_wait_cpus(1))
break;
pr_alert("UV: Sending NMI IPI to %d CPUs: %*pbl\n",
cpumask_weight(uv_nmi_cpu_mask),
cpumask_pr_args(uv_nmi_cpu_mask));
uv_nmi_nr_cpus_ping();
if (!uv_nmi_wait_cpus(0))
break;
pr_alert("UV: %d CPUs not in NMI loop: %*pbl\n",
cpumask_weight(uv_nmi_cpu_mask),
cpumask_pr_args(uv_nmi_cpu_mask));
} while (0);
pr_alert("UV: %d of %d CPUs in NMI\n",
atomic_read(&uv_nmi_cpus_in_nmi), num_online_cpus());
}
static void uv_nmi_dump_cpu_ip_hdr(void)
{
pr_info("\nUV: %4s %6s %-32s %s (Note: PID 0 not listed)\n",
"CPU", "PID", "COMMAND", "IP");
}
static void uv_nmi_dump_cpu_ip(int cpu, struct pt_regs *regs)
{
pr_info("UV: %4d %6d %-32.32s %pS",
cpu, current->pid, current->comm, (void *)regs->ip);
}
static void uv_nmi_dump_state_cpu(int cpu, struct pt_regs *regs)
{
const char *dots = " ................................. ";
if (cpu == 0)
uv_nmi_dump_cpu_ip_hdr();
if (current->pid != 0 || !uv_nmi_action_is("ips"))
uv_nmi_dump_cpu_ip(cpu, regs);
if (uv_nmi_action_is("dump")) {
pr_info("UV:%sNMI process trace for CPU %d\n", dots, cpu);
show_regs(regs);
}
this_cpu_write(uv_cpu_nmi.state, UV_NMI_STATE_DUMP_DONE);
}
static void uv_nmi_trigger_dump(int cpu)
{
int retry = uv_nmi_trigger_delay;
if (uv_cpu_nmi_per(cpu).state != UV_NMI_STATE_IN)
return;
uv_cpu_nmi_per(cpu).state = UV_NMI_STATE_DUMP;
do {
cpu_relax();
udelay(10);
if (uv_cpu_nmi_per(cpu).state
!= UV_NMI_STATE_DUMP)
return;
} while (--retry > 0);
pr_crit("UV: CPU %d stuck in process dump function\n", cpu);
uv_cpu_nmi_per(cpu).state = UV_NMI_STATE_DUMP_DONE;
}
static void uv_nmi_sync_exit(int master)
{
atomic_dec(&uv_nmi_cpus_in_nmi);
if (master) {
while (atomic_read(&uv_nmi_cpus_in_nmi) > 0)
cpu_relax();
atomic_set(&uv_nmi_slave_continue, SLAVE_CLEAR);
} else {
while (atomic_read(&uv_nmi_slave_continue))
cpu_relax();
}
}
static void uv_nmi_action_health(int cpu, struct pt_regs *regs, int master)
{
if (master) {
int in = atomic_read(&uv_nmi_cpus_in_nmi);
int out = num_online_cpus() - in;
pr_alert("UV: NMI CPU health check (non-responding:%d)\n", out);
atomic_set(&uv_nmi_slave_continue, SLAVE_EXIT);
} else {
while (!atomic_read(&uv_nmi_slave_continue))
cpu_relax();
}
uv_nmi_sync_exit(master);
}
static void uv_nmi_dump_state(int cpu, struct pt_regs *regs, int master)
{
if (master) {
int tcpu;
int ignored = 0;
int saved_console_loglevel = console_loglevel;
pr_alert("UV: tracing %s for %d CPUs from CPU %d\n",
uv_nmi_action_is("ips") ? "IPs" : "processes",
atomic_read(&uv_nmi_cpus_in_nmi), cpu);
console_loglevel = uv_nmi_loglevel;
atomic_set(&uv_nmi_slave_continue, SLAVE_EXIT);
for_each_online_cpu(tcpu) {
if (cpumask_test_cpu(tcpu, uv_nmi_cpu_mask))
ignored++;
else if (tcpu == cpu)
uv_nmi_dump_state_cpu(tcpu, regs);
else
uv_nmi_trigger_dump(tcpu);
}
if (ignored)
pr_alert("UV: %d CPUs ignored NMI\n", ignored);
console_loglevel = saved_console_loglevel;
pr_alert("UV: process trace complete\n");
} else {
while (!atomic_read(&uv_nmi_slave_continue))
cpu_relax();
while (this_cpu_read(uv_cpu_nmi.state) != UV_NMI_STATE_DUMP)
cpu_relax();
uv_nmi_dump_state_cpu(cpu, regs);
}
uv_nmi_sync_exit(master);
}
static void uv_nmi_touch_watchdogs(void)
{
touch_softlockup_watchdog_sync();
clocksource_touch_watchdog();
rcu_cpu_stall_reset();
touch_nmi_watchdog();
}
static void uv_nmi_kdump(int cpu, int master, struct pt_regs *regs)
{
if (master) {
pr_emerg("UV: NMI executing crash_kexec on CPU%d\n", cpu);
crash_kexec(regs);
pr_emerg("UV: crash_kexec unexpectedly returned, ");
atomic_set(&uv_nmi_kexec_failed, 1);
if (!kexec_crash_image) {
pr_cont("crash kernel not loaded\n");
return;
}
pr_cont("kexec busy, stalling cpus while waiting\n");
}
while (atomic_read(&uv_nmi_kexec_failed) == 0)
mdelay(10);
}
static inline void uv_nmi_kdump(int cpu, int master, struct pt_regs *regs)
{
if (master)
pr_err("UV: NMI kdump: KEXEC not supported in this kernel\n");
atomic_set(&uv_nmi_kexec_failed, 1);
}
static inline int uv_nmi_kdb_reason(void)
{
return KDB_REASON_SYSTEM_NMI;
}
static inline int uv_nmi_kdb_reason(void)
{
if (uv_nmi_action_is("kgdb"))
return 0;
pr_err("UV: NMI error: KDB is not enabled in this kernel\n");
return -1;
}
static void uv_call_kgdb_kdb(int cpu, struct pt_regs *regs, int master)
{
if (master) {
int reason = uv_nmi_kdb_reason();
int ret;
if (reason < 0)
return;
ret = kgdb_nmicallin(cpu, X86_TRAP_NMI, regs, reason,
&uv_nmi_slave_continue);
if (ret) {
pr_alert("KGDB returned error, is kgdboc set?\n");
atomic_set(&uv_nmi_slave_continue, SLAVE_EXIT);
}
} else {
int sig;
do {
cpu_relax();
sig = atomic_read(&uv_nmi_slave_continue);
} while (!sig);
if (sig == SLAVE_CONTINUE)
kgdb_nmicallback(cpu, regs);
}
uv_nmi_sync_exit(master);
}
static inline void uv_call_kgdb_kdb(int cpu, struct pt_regs *regs, int master)
{
pr_err("UV: NMI error: KGDB is not enabled in this kernel\n");
}
int uv_handle_nmi(unsigned int reason, struct pt_regs *regs)
{
struct uv_hub_nmi_s *hub_nmi = uv_hub_nmi;
int cpu = smp_processor_id();
int master = 0;
unsigned long flags;
local_irq_save(flags);
if (!this_cpu_read(uv_cpu_nmi.pinging) && !uv_check_nmi(hub_nmi)) {
local_irq_restore(flags);
return NMI_DONE;
}
master = (atomic_read(&uv_nmi_cpu) == cpu);
if (uv_nmi_action_is("kdump")) {
uv_nmi_kdump(cpu, master, regs);
if (master)
strncpy(uv_nmi_action, "dump", strlen(uv_nmi_action));
}
uv_nmi_wait(master);
if (uv_nmi_action_is("health")) {
uv_nmi_action_health(cpu, regs, master);
} else if (uv_nmi_action_is("ips") || uv_nmi_action_is("dump")) {
uv_nmi_dump_state(cpu, regs, master);
} else if (uv_nmi_action_is("kdb") || uv_nmi_action_is("kgdb")) {
uv_call_kgdb_kdb(cpu, regs, master);
} else {
if (master)
pr_alert("UV: unknown NMI action: %s\n", uv_nmi_action);
uv_nmi_sync_exit(master);
}
this_cpu_write(uv_cpu_nmi.state, UV_NMI_STATE_OUT);
uv_clear_nmi(cpu);
if (master) {
if (cpumask_weight(uv_nmi_cpu_mask))
uv_nmi_cleanup_mask();
atomic_set(&uv_nmi_cpus_in_nmi, -1);
atomic_set(&uv_nmi_cpu, -1);
atomic_set(&uv_in_nmi, 0);
atomic_set(&uv_nmi_kexec_failed, 0);
atomic_set(&uv_nmi_slave_continue, SLAVE_CLEAR);
}
uv_nmi_touch_watchdogs();
local_irq_restore(flags);
return NMI_HANDLED;
}
static int uv_handle_nmi_ping(unsigned int reason, struct pt_regs *regs)
{
int ret;
this_cpu_inc(uv_cpu_nmi.queries);
if (!this_cpu_read(uv_cpu_nmi.pinging)) {
local64_inc(&uv_nmi_ping_misses);
return NMI_DONE;
}
this_cpu_inc(uv_cpu_nmi.pings);
local64_inc(&uv_nmi_ping_count);
ret = uv_handle_nmi(reason, regs);
this_cpu_write(uv_cpu_nmi.pinging, 0);
return ret;
}
static void uv_register_nmi_notifier(void)
{
if (register_nmi_handler(NMI_UNKNOWN, uv_handle_nmi, 0, "uv"))
pr_warn("UV: NMI handler failed to register\n");
if (register_nmi_handler(NMI_LOCAL, uv_handle_nmi_ping, 0, "uvping"))
pr_warn("UV: PING NMI handler failed to register\n");
}
void uv_nmi_init(void)
{
unsigned int value;
value = apic_read(APIC_LVT1) | APIC_DM_NMI;
value &= ~APIC_LVT_MASKED;
apic_write(APIC_LVT1, value);
}
void __init uv_nmi_setup_common(bool hubbed)
{
int size = sizeof(void *) * (1 << NODES_SHIFT);
int cpu;
uv_hub_nmi_list = kzalloc(size, GFP_KERNEL);
nmi_debug("UV: NMI hub list @ 0x%p (%d)\n", uv_hub_nmi_list, size);
BUG_ON(!uv_hub_nmi_list);
size = sizeof(struct uv_hub_nmi_s);
for_each_present_cpu(cpu) {
int nid = cpu_to_node(cpu);
if (uv_hub_nmi_list[nid] == NULL) {
uv_hub_nmi_list[nid] = kzalloc_node(size,
GFP_KERNEL, nid);
BUG_ON(!uv_hub_nmi_list[nid]);
raw_spin_lock_init(&(uv_hub_nmi_list[nid]->nmi_lock));
atomic_set(&uv_hub_nmi_list[nid]->cpu_owner, -1);
uv_hub_nmi_list[nid]->hub_present = hubbed;
uv_hub_nmi_list[nid]->pch_owner = (nid == 0);
}
uv_hub_nmi_per(cpu) = uv_hub_nmi_list[nid];
}
BUG_ON(!alloc_cpumask_var(&uv_nmi_cpu_mask, GFP_KERNEL));
}
void __init uv_nmi_setup(void)
{
uv_nmi_setup_mmrs();
uv_nmi_setup_common(true);
uv_register_nmi_notifier();
pr_info("UV: Hub NMI enabled\n");
}
void __init uv_nmi_setup_hubless(void)
{
uv_nmi_setup_common(false);
pch_base = xlate_dev_mem_ptr(PCH_PCR_GPIO_1_BASE);
nmi_debug("UV: PCH base:%p from 0x%lx, GPP_D_0\n",
pch_base, PCH_PCR_GPIO_1_BASE);
if (uv_pch_init_enable)
uv_init_hubless_pch_d0();
uv_init_hubless_pch_io(GPI_NMI_ENA_GPP_D_0,
STS_GPP_D_0_MASK, STS_GPP_D_0_MASK);
uv_nmi_setup_hubless_intr();
uv_reassert_nmi();
uv_register_nmi_notifier();
pr_info("UV: Hubless NMI enabled\n");
}
