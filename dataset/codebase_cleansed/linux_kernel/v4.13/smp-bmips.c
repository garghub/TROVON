static void __init bmips_smp_setup(void)
{
int i, cpu = 1, boot_cpu = 0;
int cpu_hw_intr;
switch (current_cpu_type()) {
case CPU_BMIPS4350:
case CPU_BMIPS4380:
clear_c0_brcm_cmt_ctrl(0x30);
set_c0_brcm_config_0(0x30000);
boot_cpu = !!(read_c0_brcm_cmt_local() & (1 << 31));
if (boot_cpu == 0)
cpu_hw_intr = 0x02;
else
cpu_hw_intr = 0x1d;
change_c0_brcm_cmt_intr(0xf8018000,
(cpu_hw_intr << 27) | (0x03 << 15));
max_cpus = 2;
break;
case CPU_BMIPS5000:
set_c0_brcm_config(0x03 << 22);
change_c0_brcm_mode(0x1f << 27, 0x02 << 27);
max_cpus = (((read_c0_brcm_config() >> 6) & 0x03) + 1) << 1;
for (i = 0; i < max_cpus; i++) {
write_c0_brcm_action(ACTION_CLR_IPI(i, 0));
write_c0_brcm_action(ACTION_CLR_IPI(i, 1));
}
break;
default:
max_cpus = 1;
}
if (!bmips_smp_enabled)
max_cpus = 1;
if (!board_ebase_setup)
board_ebase_setup = &bmips_ebase_setup;
__cpu_number_map[boot_cpu] = 0;
__cpu_logical_map[0] = boot_cpu;
for (i = 0; i < max_cpus; i++) {
if (i != boot_cpu) {
__cpu_number_map[i] = cpu;
__cpu_logical_map[cpu] = i;
cpu++;
}
set_cpu_possible(i, 1);
set_cpu_present(i, 1);
}
}
static void bmips_prepare_cpus(unsigned int max_cpus)
{
irqreturn_t (*bmips_ipi_interrupt)(int irq, void *dev_id);
switch (current_cpu_type()) {
case CPU_BMIPS4350:
case CPU_BMIPS4380:
bmips_ipi_interrupt = bmips43xx_ipi_interrupt;
break;
case CPU_BMIPS5000:
bmips_ipi_interrupt = bmips5000_ipi_interrupt;
break;
default:
return;
}
if (request_irq(IPI0_IRQ, bmips_ipi_interrupt, IRQF_PERCPU,
"smp_ipi0", NULL))
panic("Can't request IPI0 interrupt");
if (request_irq(IPI1_IRQ, bmips_ipi_interrupt, IRQF_PERCPU,
"smp_ipi1", NULL))
panic("Can't request IPI1 interrupt");
}
static void bmips_boot_secondary(int cpu, struct task_struct *idle)
{
bmips_smp_boot_sp = __KSTK_TOS(idle);
bmips_smp_boot_gp = (unsigned long)task_thread_info(idle);
mb();
pr_info("SMP: Booting CPU%d...\n", cpu);
if (cpumask_test_cpu(cpu, &bmips_booted_mask)) {
bmips_set_reset_vec(cpu, RESET_FROM_KSEG0);
switch (current_cpu_type()) {
case CPU_BMIPS4350:
case CPU_BMIPS4380:
bmips43xx_send_ipi_single(cpu, 0);
break;
case CPU_BMIPS5000:
bmips5000_send_ipi_single(cpu, 0);
break;
}
} else {
bmips_set_reset_vec(cpu, RESET_FROM_KSEG1);
switch (current_cpu_type()) {
case CPU_BMIPS4350:
case CPU_BMIPS4380:
if (cpu_logical_map(cpu) == 1)
set_c0_brcm_cmt_ctrl(0x01);
break;
case CPU_BMIPS5000:
write_c0_brcm_action(ACTION_BOOT_THREAD(cpu));
break;
}
cpumask_set_cpu(cpu, &bmips_booted_mask);
}
}
static void bmips_init_secondary(void)
{
switch (current_cpu_type()) {
case CPU_BMIPS4350:
case CPU_BMIPS4380:
clear_c0_cause(smp_processor_id() ? C_SW1 : C_SW0);
break;
case CPU_BMIPS5000:
write_c0_brcm_action(ACTION_CLR_IPI(smp_processor_id(), 0));
current_cpu_data.core = (read_c0_brcm_config() >> 25) & 3;
break;
}
}
static void bmips_smp_finish(void)
{
pr_info("SMP: CPU%d is running\n", smp_processor_id());
write_c0_compare(read_c0_count() + mips_hpt_frequency / HZ);
irq_enable_hazard();
set_c0_status(IE_SW0 | IE_SW1 | bmips_tp1_irqs | IE_IRQ5 | ST0_IE);
irq_enable_hazard();
}
static void bmips5000_send_ipi_single(int cpu, unsigned int action)
{
write_c0_brcm_action(ACTION_SET_IPI(cpu, action == SMP_CALL_FUNCTION));
}
static irqreturn_t bmips5000_ipi_interrupt(int irq, void *dev_id)
{
int action = irq - IPI0_IRQ;
write_c0_brcm_action(ACTION_CLR_IPI(smp_processor_id(), action));
if (action == 0)
scheduler_ipi();
else
generic_smp_call_function_interrupt();
return IRQ_HANDLED;
}
static void bmips5000_send_ipi_mask(const struct cpumask *mask,
unsigned int action)
{
unsigned int i;
for_each_cpu(i, mask)
bmips5000_send_ipi_single(i, action);
}
static void bmips43xx_send_ipi_single(int cpu, unsigned int action)
{
unsigned long flags;
spin_lock_irqsave(&ipi_lock, flags);
set_c0_cause(cpu ? C_SW1 : C_SW0);
per_cpu(ipi_action_mask, cpu) |= action;
irq_enable_hazard();
spin_unlock_irqrestore(&ipi_lock, flags);
}
static irqreturn_t bmips43xx_ipi_interrupt(int irq, void *dev_id)
{
unsigned long flags;
int action, cpu = irq - IPI0_IRQ;
spin_lock_irqsave(&ipi_lock, flags);
action = __this_cpu_read(ipi_action_mask);
per_cpu(ipi_action_mask, cpu) = 0;
clear_c0_cause(cpu ? C_SW1 : C_SW0);
spin_unlock_irqrestore(&ipi_lock, flags);
if (action & SMP_RESCHEDULE_YOURSELF)
scheduler_ipi();
if (action & SMP_CALL_FUNCTION)
generic_smp_call_function_interrupt();
return IRQ_HANDLED;
}
static void bmips43xx_send_ipi_mask(const struct cpumask *mask,
unsigned int action)
{
unsigned int i;
for_each_cpu(i, mask)
bmips43xx_send_ipi_single(i, action);
}
static int bmips_cpu_disable(void)
{
unsigned int cpu = smp_processor_id();
if (cpu == 0)
return -EBUSY;
pr_info("SMP: CPU%d is offline\n", cpu);
set_cpu_online(cpu, false);
calculate_cpu_foreign_map();
irq_cpu_offline();
clear_c0_status(IE_IRQ5);
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
change_c0_status(
IE_IRQ5 | bmips_tp1_irqs | IE_SW0 | IE_SW1 | ST0_IE | ST0_BEV,
IE_SW0 | IE_SW1 | ST0_IE | ST0_BEV);
irq_disable_hazard();
__asm__ __volatile__(
" wait\n"
" j bmips_secondary_reentry\n"
: : : "memory");
}
static void bmips_wr_vec(unsigned long dst, char *start, char *end)
{
memcpy((void *)dst, start, end - start);
dma_cache_wback(dst, end - start);
local_flush_icache_range(dst, dst + (end - start));
instruction_hazard();
}
static inline void bmips_nmi_handler_setup(void)
{
bmips_wr_vec(BMIPS_NMI_RESET_VEC, &bmips_reset_nmi_vec,
&bmips_reset_nmi_vec_end);
bmips_wr_vec(BMIPS_WARM_RESTART_VEC, &bmips_smp_int_vec,
&bmips_smp_int_vec_end);
}
static void bmips_set_reset_vec_remote(void *vinfo)
{
struct reset_vec_info *info = vinfo;
int shift = info->cpu & 0x01 ? 16 : 0;
u32 mask = ~(0xffff << shift), val = info->val >> 16;
preempt_disable();
if (smp_processor_id() > 0) {
smp_call_function_single(0, &bmips_set_reset_vec_remote,
info, 1);
} else {
if (info->cpu & 0x02) {
bmips_write_zscm_reg(0xa0, (val << 16) | val);
bmips_read_zscm_reg(0xa0);
} else {
write_c0_brcm_bootvec((read_c0_brcm_bootvec() & mask) |
(val << shift));
}
}
preempt_enable();
}
static void bmips_set_reset_vec(int cpu, u32 val)
{
struct reset_vec_info info;
if (current_cpu_type() == CPU_BMIPS5000) {
info.cpu = cpu;
info.val = val;
bmips_set_reset_vec_remote(&info);
} else {
void __iomem *cbr = BMIPS_GET_CBR();
if (cpu == 0)
__raw_writel(val, cbr + BMIPS_RELO_VECTOR_CONTROL_0);
else {
if (current_cpu_type() != CPU_BMIPS4380)
return;
__raw_writel(val, cbr + BMIPS_RELO_VECTOR_CONTROL_1);
}
}
__sync();
back_to_back_c0_hazard();
}
void bmips_ebase_setup(void)
{
unsigned long new_ebase = ebase;
BUG_ON(ebase != CKSEG0);
switch (current_cpu_type()) {
case CPU_BMIPS4350:
set_uncached_handler(BMIPS_WARM_RESTART_VEC - CKSEG0,
&bmips_smp_int_vec, 0x80);
__sync();
return;
case CPU_BMIPS3300:
case CPU_BMIPS4380:
new_ebase = 0x80000400;
bmips_set_reset_vec(0, RESET_FROM_KSEG0);
break;
case CPU_BMIPS5000:
new_ebase = 0x80001000;
bmips_set_reset_vec(0, RESET_FROM_KSEG0);
write_c0_ebase(new_ebase);
break;
default:
return;
}
board_nmi_handler_setup = &bmips_nmi_handler_setup;
ebase = new_ebase;
}
asmlinkage void __weak plat_wired_tlb_setup(void)
{
}
void __init bmips_cpu_setup(void)
{
void __iomem __maybe_unused *cbr = BMIPS_GET_CBR();
u32 __maybe_unused cfg;
switch (current_cpu_type()) {
case CPU_BMIPS3300:
set_c0_brcm_bus_pll(BIT(22));
__sync();
clear_c0_brcm_bus_pll(BIT(22));
clear_c0_brcm_reset(BIT(16));
cfg = __raw_readl(cbr + BMIPS_RAC_CONFIG);
__raw_writel(cfg | 0x100, BMIPS_RAC_CONFIG);
__raw_readl(cbr + BMIPS_RAC_CONFIG);
cfg = __raw_readl(cbr + BMIPS_RAC_CONFIG);
__raw_writel(cfg | 0xf, BMIPS_RAC_CONFIG);
__raw_readl(cbr + BMIPS_RAC_CONFIG);
cfg = __raw_readl(cbr + BMIPS_RAC_ADDRESS_RANGE);
__raw_writel(cfg | 0x0fff0000, cbr + BMIPS_RAC_ADDRESS_RANGE);
__raw_readl(cbr + BMIPS_RAC_ADDRESS_RANGE);
break;
case CPU_BMIPS4380:
switch (read_c0_prid()) {
case 0x2a040:
case 0x2a042:
case 0x2a044:
case 0x2a060:
cfg = __raw_readl(cbr + BMIPS_L2_CONFIG);
__raw_writel(cfg & ~0x07000000, cbr + BMIPS_L2_CONFIG);
__raw_readl(cbr + BMIPS_L2_CONFIG);
}
clear_c0_brcm_config_0(BIT(21));
set_c0_brcm_config_0(BIT(23));
set_c0_brcm_cmt_ctrl(BIT(15));
break;
case CPU_BMIPS5000:
set_c0_brcm_config(BIT(17) | BIT(21));
__asm__ __volatile__(
" .set noreorder\n"
" li $8, 0x5a455048\n"
" .word 0x4088b00f\n"
" .word 0x4008b008\n"
" li $9, 0x00008000\n"
" or $8, $8, $9\n"
" .word 0x4088b008\n"
" sync\n"
" li $8, 0x0\n"
" .word 0x4088b00f\n"
" .set reorder\n"
: : : "$8", "$9");
set_c0_brcm_config(BIT(27));
__asm__ __volatile__(
" li $8, 0x5a455048\n"
" .word 0x4088b00f\n"
" nop; nop; nop\n"
" .word 0x4008b008\n"
" lui $9, 0x0100\n"
" or $8, $9\n"
" .word 0x4088b008\n"
: : : "$8", "$9");
break;
}
}
