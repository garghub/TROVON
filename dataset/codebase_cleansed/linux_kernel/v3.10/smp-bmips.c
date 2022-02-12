static void __init bmips_smp_setup(void)
{
int i;
#if defined(CONFIG_CPU_BMIPS4350) || defined(CONFIG_CPU_BMIPS4380)
clear_c0_brcm_cmt_ctrl(0x30);
set_c0_brcm_config_0(0x30000);
change_c0_brcm_cmt_intr(0xf8018000,
(0x02 << 27) | (0x03 << 15));
max_cpus = 2;
#elif defined(CONFIG_CPU_BMIPS5000)
set_c0_brcm_config(0x03 << 22);
change_c0_brcm_mode(0x1f << 27, 0x02 << 27);
max_cpus = (((read_c0_brcm_config() >> 6) & 0x03) + 1) << 1;
for (i = 0; i < max_cpus; i++) {
write_c0_brcm_action(ACTION_CLR_IPI(i, 0));
write_c0_brcm_action(ACTION_CLR_IPI(i, 1));
}
#endif
if (!bmips_smp_enabled)
max_cpus = 1;
if (!board_ebase_setup)
board_ebase_setup = &bmips_ebase_setup;
for (i = 0; i < max_cpus; i++) {
__cpu_number_map[i] = 1;
__cpu_logical_map[i] = 1;
set_cpu_possible(i, 1);
set_cpu_present(i, 1);
}
}
static void bmips_prepare_cpus(unsigned int max_cpus)
{
if (request_irq(IPI0_IRQ, bmips_ipi_interrupt, IRQF_PERCPU,
"smp_ipi0", NULL))
panic("Can't request IPI0 interrupt\n");
if (request_irq(IPI1_IRQ, bmips_ipi_interrupt, IRQF_PERCPU,
"smp_ipi1", NULL))
panic("Can't request IPI1 interrupt\n");
}
static void bmips_boot_secondary(int cpu, struct task_struct *idle)
{
bmips_smp_boot_sp = __KSTK_TOS(idle);
bmips_smp_boot_gp = (unsigned long)task_thread_info(idle);
mb();
pr_info("SMP: Booting CPU%d...\n", cpu);
if (cpumask_test_cpu(cpu, &bmips_booted_mask))
bmips_send_ipi_single(cpu, 0);
else {
#if defined(CONFIG_CPU_BMIPS4350) || defined(CONFIG_CPU_BMIPS4380)
set_c0_brcm_cmt_ctrl(0x01);
#elif defined(CONFIG_CPU_BMIPS5000)
if (cpu & 0x01)
write_c0_brcm_action(ACTION_BOOT_THREAD(cpu));
else {
bmips_write_zscm_reg(0x210, 0xc0000000);
udelay(10);
bmips_write_zscm_reg(0x210, 0x00);
}
#endif
cpumask_set_cpu(cpu, &bmips_booted_mask);
}
}
static void bmips_init_secondary(void)
{
#if defined(CONFIG_CPU_BMIPS4350) || defined(CONFIG_CPU_BMIPS4380)
void __iomem *cbr = BMIPS_GET_CBR();
unsigned long old_vec;
old_vec = __raw_readl(cbr + BMIPS_RELO_VECTOR_CONTROL_1);
__raw_writel(old_vec & ~0x20000000, cbr + BMIPS_RELO_VECTOR_CONTROL_1);
clear_c0_cause(smp_processor_id() ? C_SW1 : C_SW0);
#elif defined(CONFIG_CPU_BMIPS5000)
write_c0_brcm_bootvec(read_c0_brcm_bootvec() &
(smp_processor_id() & 0x01 ? ~0x20000000 : ~0x2000));
write_c0_brcm_action(ACTION_CLR_IPI(smp_processor_id(), 0));
#endif
}
static void bmips_smp_finish(void)
{
pr_info("SMP: CPU%d is running\n", smp_processor_id());
write_c0_compare(read_c0_count() + mips_hpt_frequency / HZ);
irq_enable_hazard();
set_c0_status(IE_SW0 | IE_SW1 | IE_IRQ1 | IE_IRQ5 | ST0_IE);
irq_enable_hazard();
}
static void bmips_cpus_done(void)
{
}
static void bmips_send_ipi_single(int cpu, unsigned int action)
{
write_c0_brcm_action(ACTION_SET_IPI(cpu, action == SMP_CALL_FUNCTION));
}
static irqreturn_t bmips_ipi_interrupt(int irq, void *dev_id)
{
int action = irq - IPI0_IRQ;
write_c0_brcm_action(ACTION_CLR_IPI(smp_processor_id(), action));
if (action == 0)
scheduler_ipi();
else
smp_call_function_interrupt();
return IRQ_HANDLED;
}
static void bmips_send_ipi_single(int cpu, unsigned int action)
{
unsigned long flags;
spin_lock_irqsave(&ipi_lock, flags);
set_c0_cause(cpu ? C_SW1 : C_SW0);
per_cpu(ipi_action_mask, cpu) |= action;
irq_enable_hazard();
spin_unlock_irqrestore(&ipi_lock, flags);
}
static irqreturn_t bmips_ipi_interrupt(int irq, void *dev_id)
{
unsigned long flags;
int action, cpu = irq - IPI0_IRQ;
spin_lock_irqsave(&ipi_lock, flags);
action = __get_cpu_var(ipi_action_mask);
per_cpu(ipi_action_mask, cpu) = 0;
clear_c0_cause(cpu ? C_SW1 : C_SW0);
spin_unlock_irqrestore(&ipi_lock, flags);
if (action & SMP_RESCHEDULE_YOURSELF)
scheduler_ipi();
if (action & SMP_CALL_FUNCTION)
smp_call_function_interrupt();
return IRQ_HANDLED;
}
static void bmips_send_ipi_mask(const struct cpumask *mask,
unsigned int action)
{
unsigned int i;
for_each_cpu(i, mask)
bmips_send_ipi_single(i, action);
}
static int bmips_cpu_disable(void)
{
unsigned int cpu = smp_processor_id();
if (cpu == 0)
return -EBUSY;
pr_info("SMP: CPU%d is offline\n", cpu);
set_cpu_online(cpu, false);
cpu_clear(cpu, cpu_callin_map);
local_flush_tlb_all();
local_flush_icache_range(0, ~0);
return 0;
}
static void bmips_cpu_die(unsigned int cpu)
{
}
void __ref play_dead(void)
{
idle_task_exit();
_dma_cache_wback_inv(0, ~0);
clear_c0_cause(CAUSEF_IV | C_SW0 | C_SW1);
change_c0_status(IE_IRQ5 | IE_IRQ1 | IE_SW0 | IE_SW1 | ST0_IE | ST0_BEV,
IE_SW0 | IE_SW1 | ST0_IE | ST0_BEV);
irq_disable_hazard();
__asm__ __volatile__(
" wait\n"
" j bmips_secondary_reentry\n"
: : : "memory");
}
static void __cpuinit bmips_wr_vec(unsigned long dst, char *start, char *end)
{
memcpy((void *)dst, start, end - start);
dma_cache_wback((unsigned long)start, end - start);
local_flush_icache_range(dst, dst + (end - start));
instruction_hazard();
}
static inline void __cpuinit bmips_nmi_handler_setup(void)
{
bmips_wr_vec(BMIPS_NMI_RESET_VEC, &bmips_reset_nmi_vec,
&bmips_reset_nmi_vec_end);
bmips_wr_vec(BMIPS_WARM_RESTART_VEC, &bmips_smp_int_vec,
&bmips_smp_int_vec_end);
}
void __cpuinit bmips_ebase_setup(void)
{
unsigned long new_ebase = ebase;
void __iomem __maybe_unused *cbr;
BUG_ON(ebase != CKSEG0);
#if defined(CONFIG_CPU_BMIPS4350)
set_uncached_handler(BMIPS_WARM_RESTART_VEC - CKSEG0,
&bmips_smp_int_vec, 0x80);
__sync();
return;
#elif defined(CONFIG_CPU_BMIPS4380)
new_ebase = 0x80000400;
cbr = BMIPS_GET_CBR();
__raw_writel(0x80080800, cbr + BMIPS_RELO_VECTOR_CONTROL_0);
__raw_writel(0xa0080800, cbr + BMIPS_RELO_VECTOR_CONTROL_1);
#elif defined(CONFIG_CPU_BMIPS5000)
new_ebase = 0x80001000;
write_c0_brcm_bootvec(0xa0088008);
write_c0_ebase(new_ebase);
if (max_cpus > 2)
bmips_write_zscm_reg(0xa0, 0xa008a008);
#else
return;
#endif
board_nmi_handler_setup = &bmips_nmi_handler_setup;
ebase = new_ebase;
}
asmlinkage void __weak plat_wired_tlb_setup(void)
{
}
