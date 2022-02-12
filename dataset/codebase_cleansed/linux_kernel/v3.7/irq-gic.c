unsigned int gic_get_timer_pending(void)
{
unsigned int vpe_pending;
GICWRITE(GIC_REG(VPE_LOCAL, GIC_VPE_OTHER_ADDR), 0);
GICREAD(GIC_REG(VPE_OTHER, GIC_VPE_PEND), vpe_pending);
return (vpe_pending & GIC_VPE_PEND_TIMER_MSK);
}
void gic_bind_eic_interrupt(int irq, int set)
{
irq -= GIC_PIN_TO_VEC_OFFSET;
GICWRITE(GIC_REG_ADDR(VPE_LOCAL, GIC_VPE_EIC_SS(irq)), set);
}
void gic_send_ipi(unsigned int intr)
{
GICWRITE(GIC_REG(SHARED, GIC_SH_WEDGE), 0x80000000 | intr);
}
static void gic_eic_irq_dispatch(void)
{
unsigned int cause = read_c0_cause();
int irq;
irq = (cause & ST0_IM) >> STATUSB_IP2;
if (irq == 0)
irq = -1;
if (irq >= 0)
do_IRQ(gic_irq_base + irq);
else
spurious_interrupt();
}
static void __init vpe_local_setup(unsigned int numvpes)
{
unsigned long timer_intr = GIC_INT_TMR;
unsigned long perf_intr = GIC_INT_PERFCTR;
unsigned int vpe_ctl;
int i;
if (cpu_has_veic) {
timer_intr += (GIC_CPU_TO_VEC_OFFSET - GIC_PIN_TO_VEC_OFFSET);
perf_intr += (GIC_CPU_TO_VEC_OFFSET - GIC_PIN_TO_VEC_OFFSET);
}
for (i = 0; i < numvpes; i++) {
GICWRITE(GIC_REG(VPE_LOCAL, GIC_VPE_OTHER_ADDR), i);
GICREAD(GIC_REG(VPE_OTHER, GIC_VPE_CTL), vpe_ctl);
if (vpe_ctl & GIC_VPE_CTL_TIMER_RTBL_MSK)
GICWRITE(GIC_REG(VPE_OTHER, GIC_VPE_TIMER_MAP),
GIC_MAP_TO_PIN_MSK | timer_intr);
if (cpu_has_veic) {
set_vi_handler(timer_intr + GIC_PIN_TO_VEC_OFFSET,
gic_eic_irq_dispatch);
gic_shared_intr_map[timer_intr + GIC_PIN_TO_VEC_OFFSET].local_intr_mask |= GIC_VPE_RMASK_TIMER_MSK;
}
if (vpe_ctl & GIC_VPE_CTL_PERFCNT_RTBL_MSK)
GICWRITE(GIC_REG(VPE_OTHER, GIC_VPE_PERFCTR_MAP),
GIC_MAP_TO_PIN_MSK | perf_intr);
if (cpu_has_veic) {
set_vi_handler(perf_intr + GIC_PIN_TO_VEC_OFFSET, gic_eic_irq_dispatch);
gic_shared_intr_map[perf_intr + GIC_PIN_TO_VEC_OFFSET].local_intr_mask |= GIC_VPE_RMASK_PERFCNT_MSK;
}
}
}
unsigned int gic_get_int(void)
{
unsigned int i;
unsigned long *pending, *intrmask, *pcpu_mask;
unsigned long *pending_abs, *intrmask_abs;
pending = pending_regs[smp_processor_id()].pending;
intrmask = intrmask_regs[smp_processor_id()].intrmask;
pcpu_mask = pcpu_masks[smp_processor_id()].pcpu_mask;
pending_abs = (unsigned long *) GIC_REG_ABS_ADDR(SHARED,
GIC_SH_PEND_31_0_OFS);
intrmask_abs = (unsigned long *) GIC_REG_ABS_ADDR(SHARED,
GIC_SH_MASK_31_0_OFS);
for (i = 0; i < BITS_TO_LONGS(GIC_NUM_INTRS); i++) {
GICREAD(*pending_abs, pending[i]);
GICREAD(*intrmask_abs, intrmask[i]);
pending_abs++;
intrmask_abs++;
}
bitmap_and(pending, pending, intrmask, GIC_NUM_INTRS);
bitmap_and(pending, pending, pcpu_mask, GIC_NUM_INTRS);
return find_first_bit(pending, GIC_NUM_INTRS);
}
static void gic_mask_irq(struct irq_data *d)
{
GIC_CLR_INTR_MASK(d->irq - gic_irq_base);
}
static void gic_unmask_irq(struct irq_data *d)
{
GIC_SET_INTR_MASK(d->irq - gic_irq_base);
}
static int gic_set_affinity(struct irq_data *d, const struct cpumask *cpumask,
bool force)
{
unsigned int irq = (d->irq - gic_irq_base);
cpumask_t tmp = CPU_MASK_NONE;
unsigned long flags;
int i;
cpumask_and(&tmp, cpumask, cpu_online_mask);
if (cpus_empty(tmp))
return -1;
spin_lock_irqsave(&gic_lock, flags);
for (;;) {
GIC_SH_MAP_TO_VPE_SMASK(irq, first_cpu(tmp));
for (i = 0; i < NR_CPUS; i++)
clear_bit(irq, pcpu_masks[i].pcpu_mask);
set_bit(irq, pcpu_masks[first_cpu(tmp)].pcpu_mask);
}
cpumask_copy(d->affinity, cpumask);
spin_unlock_irqrestore(&gic_lock, flags);
return IRQ_SET_MASK_OK_NOCOPY;
}
static void __init gic_setup_intr(unsigned int intr, unsigned int cpu,
unsigned int pin, unsigned int polarity, unsigned int trigtype,
unsigned int flags)
{
struct gic_shared_intr_map *map_ptr;
if (pin & GIC_MAP_TO_NMI_MSK) {
GICWRITE(GIC_REG_ADDR(SHARED, GIC_SH_MAP_TO_PIN(intr)), pin);
for (cpu = 0; cpu < NR_CPUS; cpu += 32) {
GICWRITE(GIC_REG_ADDR(SHARED,
GIC_SH_MAP_TO_VPE_REG_OFF(intr, cpu)),
0xffffffff);
}
} else {
GICWRITE(GIC_REG_ADDR(SHARED, GIC_SH_MAP_TO_PIN(intr)),
GIC_MAP_TO_PIN_MSK | pin);
GIC_SH_MAP_TO_VPE_SMASK(intr, cpu);
if (cpu_has_veic) {
set_vi_handler(pin + GIC_PIN_TO_VEC_OFFSET,
gic_eic_irq_dispatch);
map_ptr = &gic_shared_intr_map[pin + GIC_PIN_TO_VEC_OFFSET];
if (map_ptr->num_shared_intr >= GIC_MAX_SHARED_INTR)
BUG();
map_ptr->intr_list[map_ptr->num_shared_intr++] = intr;
}
}
GIC_SET_POLARITY(intr, polarity);
GIC_SET_TRIGGER(intr, trigtype);
GIC_CLR_INTR_MASK(intr);
if (flags & GIC_FLAG_IPI)
set_bit(intr, pcpu_masks[cpu].pcpu_mask);
if ((flags & GIC_FLAG_TRANSPARENT) && (cpu_has_veic == 0))
GIC_SET_INTR_MASK(intr);
if (trigtype == GIC_TRIG_EDGE)
gic_irq_flags[intr] |= GIC_TRIG_EDGE;
}
static void __init gic_basic_init(int numintrs, int numvpes,
struct gic_intr_map *intrmap, int mapsize)
{
unsigned int i, cpu;
unsigned int pin_offset = 0;
board_bind_eic_interrupt = &gic_bind_eic_interrupt;
for (i = 0; i < numintrs; i++) {
GIC_SET_POLARITY(i, GIC_POL_POS);
GIC_SET_TRIGGER(i, GIC_TRIG_LEVEL);
GIC_CLR_INTR_MASK(i);
if (i < GIC_NUM_INTRS) {
gic_irq_flags[i] = 0;
gic_shared_intr_map[i].num_shared_intr = 0;
gic_shared_intr_map[i].local_intr_mask = 0;
}
}
if (cpu_has_veic)
pin_offset = (GIC_CPU_TO_VEC_OFFSET - GIC_PIN_TO_VEC_OFFSET);
for (i = 0; i < mapsize; i++) {
cpu = intrmap[i].cpunum;
if (cpu == GIC_UNUSED)
continue;
if (cpu == 0 && i != 0 && intrmap[i].flags == 0)
continue;
gic_setup_intr(i,
intrmap[i].cpunum,
intrmap[i].pin + pin_offset,
intrmap[i].polarity,
intrmap[i].trigtype,
intrmap[i].flags);
}
vpe_local_setup(numvpes);
}
void __init gic_init(unsigned long gic_base_addr,
unsigned long gic_addrspace_size,
struct gic_intr_map *intr_map, unsigned int intr_map_size,
unsigned int irqbase)
{
unsigned int gicconfig;
int numvpes, numintrs;
_gic_base = (unsigned long) ioremap_nocache(gic_base_addr,
gic_addrspace_size);
gic_irq_base = irqbase;
GICREAD(GIC_REG(SHARED, GIC_SH_CONFIG), gicconfig);
numintrs = (gicconfig & GIC_SH_CONFIG_NUMINTRS_MSK) >>
GIC_SH_CONFIG_NUMINTRS_SHF;
numintrs = ((numintrs + 1) * 8);
numvpes = (gicconfig & GIC_SH_CONFIG_NUMVPES_MSK) >>
GIC_SH_CONFIG_NUMVPES_SHF;
numvpes = numvpes + 1;
gic_basic_init(numintrs, numvpes, intr_map, intr_map_size);
gic_platform_init(numintrs, &gic_irq_controller);
}
