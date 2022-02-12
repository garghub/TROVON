static inline unsigned int gic_read(unsigned int reg)
{
return __raw_readl(gic_base + reg);
}
static inline void gic_write(unsigned int reg, unsigned int val)
{
__raw_writel(val, gic_base + reg);
}
static inline void gic_update_bits(unsigned int reg, unsigned int mask,
unsigned int val)
{
unsigned int regval;
regval = gic_read(reg);
regval &= ~mask;
regval |= val;
gic_write(reg, regval);
}
static inline void gic_reset_mask(unsigned int intr)
{
gic_write(GIC_REG(SHARED, GIC_SH_RMASK) + GIC_INTR_OFS(intr),
1 << GIC_INTR_BIT(intr));
}
static inline void gic_set_mask(unsigned int intr)
{
gic_write(GIC_REG(SHARED, GIC_SH_SMASK) + GIC_INTR_OFS(intr),
1 << GIC_INTR_BIT(intr));
}
static inline void gic_set_polarity(unsigned int intr, unsigned int pol)
{
gic_update_bits(GIC_REG(SHARED, GIC_SH_SET_POLARITY) +
GIC_INTR_OFS(intr), 1 << GIC_INTR_BIT(intr),
pol << GIC_INTR_BIT(intr));
}
static inline void gic_set_trigger(unsigned int intr, unsigned int trig)
{
gic_update_bits(GIC_REG(SHARED, GIC_SH_SET_TRIGGER) +
GIC_INTR_OFS(intr), 1 << GIC_INTR_BIT(intr),
trig << GIC_INTR_BIT(intr));
}
static inline void gic_set_dual_edge(unsigned int intr, unsigned int dual)
{
gic_update_bits(GIC_REG(SHARED, GIC_SH_SET_DUAL) + GIC_INTR_OFS(intr),
1 << GIC_INTR_BIT(intr),
dual << GIC_INTR_BIT(intr));
}
static inline void gic_map_to_pin(unsigned int intr, unsigned int pin)
{
gic_write(GIC_REG(SHARED, GIC_SH_INTR_MAP_TO_PIN_BASE) +
GIC_SH_MAP_TO_PIN(intr), GIC_MAP_TO_PIN_MSK | pin);
}
static inline void gic_map_to_vpe(unsigned int intr, unsigned int vpe)
{
gic_write(GIC_REG(SHARED, GIC_SH_INTR_MAP_TO_VPE_BASE) +
GIC_SH_MAP_TO_VPE_REG_OFF(intr, vpe),
GIC_SH_MAP_TO_VPE_REG_BIT(vpe));
}
cycle_t gic_read_count(void)
{
unsigned int hi, hi2, lo;
do {
hi = gic_read(GIC_REG(SHARED, GIC_SH_COUNTER_63_32));
lo = gic_read(GIC_REG(SHARED, GIC_SH_COUNTER_31_00));
hi2 = gic_read(GIC_REG(SHARED, GIC_SH_COUNTER_63_32));
} while (hi2 != hi);
return (((cycle_t) hi) << 32) + lo;
}
unsigned int gic_get_count_width(void)
{
unsigned int bits, config;
config = gic_read(GIC_REG(SHARED, GIC_SH_CONFIG));
bits = 32 + 4 * ((config & GIC_SH_CONFIG_COUNTBITS_MSK) >>
GIC_SH_CONFIG_COUNTBITS_SHF);
return bits;
}
void gic_write_compare(cycle_t cnt)
{
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_COMPARE_HI),
(int)(cnt >> 32));
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_COMPARE_LO),
(int)(cnt & 0xffffffff));
}
void gic_write_cpu_compare(cycle_t cnt, int cpu)
{
unsigned long flags;
local_irq_save(flags);
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_OTHER_ADDR), cpu);
gic_write(GIC_REG(VPE_OTHER, GIC_VPE_COMPARE_HI),
(int)(cnt >> 32));
gic_write(GIC_REG(VPE_OTHER, GIC_VPE_COMPARE_LO),
(int)(cnt & 0xffffffff));
local_irq_restore(flags);
}
cycle_t gic_read_compare(void)
{
unsigned int hi, lo;
hi = gic_read(GIC_REG(VPE_LOCAL, GIC_VPE_COMPARE_HI));
lo = gic_read(GIC_REG(VPE_LOCAL, GIC_VPE_COMPARE_LO));
return (((cycle_t) hi) << 32) + lo;
}
static bool gic_local_irq_is_routable(int intr)
{
u32 vpe_ctl;
if (cpu_has_veic)
return true;
vpe_ctl = gic_read(GIC_REG(VPE_LOCAL, GIC_VPE_CTL));
switch (intr) {
case GIC_LOCAL_INT_TIMER:
return vpe_ctl & GIC_VPE_CTL_TIMER_RTBL_MSK;
case GIC_LOCAL_INT_PERFCTR:
return vpe_ctl & GIC_VPE_CTL_PERFCNT_RTBL_MSK;
case GIC_LOCAL_INT_FDC:
return vpe_ctl & GIC_VPE_CTL_FDC_RTBL_MSK;
case GIC_LOCAL_INT_SWINT0:
case GIC_LOCAL_INT_SWINT1:
return vpe_ctl & GIC_VPE_CTL_SWINT_RTBL_MSK;
default:
return true;
}
}
unsigned int gic_get_timer_pending(void)
{
unsigned int vpe_pending;
vpe_pending = gic_read(GIC_REG(VPE_LOCAL, GIC_VPE_PEND));
return vpe_pending & GIC_VPE_PEND_TIMER_MSK;
}
static void gic_bind_eic_interrupt(int irq, int set)
{
irq -= GIC_PIN_TO_VEC_OFFSET;
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_EIC_SHADOW_SET_BASE) +
GIC_VPE_EIC_SS(irq), set);
}
void gic_send_ipi(unsigned int intr)
{
gic_write(GIC_REG(SHARED, GIC_SH_WEDGE), GIC_SH_WEDGE_SET(intr));
}
int gic_get_c0_compare_int(void)
{
if (!gic_local_irq_is_routable(GIC_LOCAL_INT_TIMER))
return MIPS_CPU_IRQ_BASE + cp0_compare_irq;
return irq_create_mapping(gic_irq_domain,
GIC_LOCAL_TO_HWIRQ(GIC_LOCAL_INT_TIMER));
}
int gic_get_c0_perfcount_int(void)
{
if (!gic_local_irq_is_routable(GIC_LOCAL_INT_PERFCTR)) {
if (cp0_perfcount_irq < 0)
return -1;
return MIPS_CPU_IRQ_BASE + cp0_perfcount_irq;
}
return irq_create_mapping(gic_irq_domain,
GIC_LOCAL_TO_HWIRQ(GIC_LOCAL_INT_PERFCTR));
}
static unsigned int gic_get_int(void)
{
unsigned int i;
unsigned long *pcpu_mask;
unsigned long pending_reg, intrmask_reg;
DECLARE_BITMAP(pending, GIC_MAX_INTRS);
DECLARE_BITMAP(intrmask, GIC_MAX_INTRS);
pcpu_mask = pcpu_masks[smp_processor_id()].pcpu_mask;
pending_reg = GIC_REG(SHARED, GIC_SH_PEND);
intrmask_reg = GIC_REG(SHARED, GIC_SH_MASK);
for (i = 0; i < BITS_TO_LONGS(gic_shared_intrs); i++) {
pending[i] = gic_read(pending_reg);
intrmask[i] = gic_read(intrmask_reg);
pending_reg += 0x4;
intrmask_reg += 0x4;
}
bitmap_and(pending, pending, intrmask, gic_shared_intrs);
bitmap_and(pending, pending, pcpu_mask, gic_shared_intrs);
return find_first_bit(pending, gic_shared_intrs);
}
static void gic_mask_irq(struct irq_data *d)
{
gic_reset_mask(GIC_HWIRQ_TO_SHARED(d->hwirq));
}
static void gic_unmask_irq(struct irq_data *d)
{
gic_set_mask(GIC_HWIRQ_TO_SHARED(d->hwirq));
}
static void gic_ack_irq(struct irq_data *d)
{
unsigned int irq = GIC_HWIRQ_TO_SHARED(d->hwirq);
gic_write(GIC_REG(SHARED, GIC_SH_WEDGE), GIC_SH_WEDGE_CLR(irq));
}
static int gic_set_type(struct irq_data *d, unsigned int type)
{
unsigned int irq = GIC_HWIRQ_TO_SHARED(d->hwirq);
unsigned long flags;
bool is_edge;
spin_lock_irqsave(&gic_lock, flags);
switch (type & IRQ_TYPE_SENSE_MASK) {
case IRQ_TYPE_EDGE_FALLING:
gic_set_polarity(irq, GIC_POL_NEG);
gic_set_trigger(irq, GIC_TRIG_EDGE);
gic_set_dual_edge(irq, GIC_TRIG_DUAL_DISABLE);
is_edge = true;
break;
case IRQ_TYPE_EDGE_RISING:
gic_set_polarity(irq, GIC_POL_POS);
gic_set_trigger(irq, GIC_TRIG_EDGE);
gic_set_dual_edge(irq, GIC_TRIG_DUAL_DISABLE);
is_edge = true;
break;
case IRQ_TYPE_EDGE_BOTH:
gic_set_trigger(irq, GIC_TRIG_EDGE);
gic_set_dual_edge(irq, GIC_TRIG_DUAL_ENABLE);
is_edge = true;
break;
case IRQ_TYPE_LEVEL_LOW:
gic_set_polarity(irq, GIC_POL_NEG);
gic_set_trigger(irq, GIC_TRIG_LEVEL);
gic_set_dual_edge(irq, GIC_TRIG_DUAL_DISABLE);
is_edge = false;
break;
case IRQ_TYPE_LEVEL_HIGH:
default:
gic_set_polarity(irq, GIC_POL_POS);
gic_set_trigger(irq, GIC_TRIG_LEVEL);
gic_set_dual_edge(irq, GIC_TRIG_DUAL_DISABLE);
is_edge = false;
break;
}
if (is_edge) {
__irq_set_chip_handler_name_locked(d->irq,
&gic_edge_irq_controller,
handle_edge_irq, NULL);
} else {
__irq_set_chip_handler_name_locked(d->irq,
&gic_level_irq_controller,
handle_level_irq, NULL);
}
spin_unlock_irqrestore(&gic_lock, flags);
return 0;
}
static int gic_set_affinity(struct irq_data *d, const struct cpumask *cpumask,
bool force)
{
unsigned int irq = GIC_HWIRQ_TO_SHARED(d->hwirq);
cpumask_t tmp = CPU_MASK_NONE;
unsigned long flags;
int i;
cpumask_and(&tmp, cpumask, cpu_online_mask);
if (cpus_empty(tmp))
return -EINVAL;
spin_lock_irqsave(&gic_lock, flags);
gic_map_to_vpe(irq, first_cpu(tmp));
for (i = 0; i < NR_CPUS; i++)
clear_bit(irq, pcpu_masks[i].pcpu_mask);
set_bit(irq, pcpu_masks[first_cpu(tmp)].pcpu_mask);
cpumask_copy(d->affinity, cpumask);
spin_unlock_irqrestore(&gic_lock, flags);
return IRQ_SET_MASK_OK_NOCOPY;
}
static unsigned int gic_get_local_int(void)
{
unsigned long pending, masked;
pending = gic_read(GIC_REG(VPE_LOCAL, GIC_VPE_PEND));
masked = gic_read(GIC_REG(VPE_LOCAL, GIC_VPE_MASK));
bitmap_and(&pending, &pending, &masked, GIC_NUM_LOCAL_INTRS);
return find_first_bit(&pending, GIC_NUM_LOCAL_INTRS);
}
static void gic_mask_local_irq(struct irq_data *d)
{
int intr = GIC_HWIRQ_TO_LOCAL(d->hwirq);
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_RMASK), 1 << intr);
}
static void gic_unmask_local_irq(struct irq_data *d)
{
int intr = GIC_HWIRQ_TO_LOCAL(d->hwirq);
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_SMASK), 1 << intr);
}
static void gic_mask_local_irq_all_vpes(struct irq_data *d)
{
int intr = GIC_HWIRQ_TO_LOCAL(d->hwirq);
int i;
unsigned long flags;
spin_lock_irqsave(&gic_lock, flags);
for (i = 0; i < gic_vpes; i++) {
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_OTHER_ADDR), i);
gic_write(GIC_REG(VPE_OTHER, GIC_VPE_RMASK), 1 << intr);
}
spin_unlock_irqrestore(&gic_lock, flags);
}
static void gic_unmask_local_irq_all_vpes(struct irq_data *d)
{
int intr = GIC_HWIRQ_TO_LOCAL(d->hwirq);
int i;
unsigned long flags;
spin_lock_irqsave(&gic_lock, flags);
for (i = 0; i < gic_vpes; i++) {
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_OTHER_ADDR), i);
gic_write(GIC_REG(VPE_OTHER, GIC_VPE_SMASK), 1 << intr);
}
spin_unlock_irqrestore(&gic_lock, flags);
}
static void __gic_irq_dispatch(void)
{
unsigned int intr, virq;
while ((intr = gic_get_local_int()) != GIC_NUM_LOCAL_INTRS) {
virq = irq_linear_revmap(gic_irq_domain,
GIC_LOCAL_TO_HWIRQ(intr));
do_IRQ(virq);
}
while ((intr = gic_get_int()) != gic_shared_intrs) {
virq = irq_linear_revmap(gic_irq_domain,
GIC_SHARED_TO_HWIRQ(intr));
do_IRQ(virq);
}
}
static void gic_irq_dispatch(unsigned int irq, struct irq_desc *desc)
{
__gic_irq_dispatch();
}
unsigned int plat_ipi_resched_int_xlate(unsigned int cpu)
{
return gic_resched_int_base + cpu;
}
unsigned int plat_ipi_call_int_xlate(unsigned int cpu)
{
return gic_call_int_base + cpu;
}
static irqreturn_t ipi_resched_interrupt(int irq, void *dev_id)
{
scheduler_ipi();
return IRQ_HANDLED;
}
static irqreturn_t ipi_call_interrupt(int irq, void *dev_id)
{
smp_call_function_interrupt();
return IRQ_HANDLED;
}
static __init void gic_ipi_init_one(unsigned int intr, int cpu,
struct irqaction *action)
{
int virq = irq_create_mapping(gic_irq_domain,
GIC_SHARED_TO_HWIRQ(intr));
int i;
gic_map_to_vpe(intr, cpu);
for (i = 0; i < NR_CPUS; i++)
clear_bit(intr, pcpu_masks[i].pcpu_mask);
set_bit(intr, pcpu_masks[cpu].pcpu_mask);
irq_set_irq_type(virq, IRQ_TYPE_EDGE_RISING);
irq_set_handler(virq, handle_percpu_irq);
setup_irq(virq, action);
}
static __init void gic_ipi_init(void)
{
int i;
gic_resched_int_base = gic_shared_intrs - nr_cpu_ids;
gic_call_int_base = gic_resched_int_base - nr_cpu_ids;
for (i = 0; i < nr_cpu_ids; i++) {
gic_ipi_init_one(gic_call_int_base + i, i, &irq_call);
gic_ipi_init_one(gic_resched_int_base + i, i, &irq_resched);
}
}
static inline void gic_ipi_init(void)
{
}
static void __init gic_basic_init(void)
{
unsigned int i;
board_bind_eic_interrupt = &gic_bind_eic_interrupt;
for (i = 0; i < gic_shared_intrs; i++) {
gic_set_polarity(i, GIC_POL_POS);
gic_set_trigger(i, GIC_TRIG_LEVEL);
gic_reset_mask(i);
}
for (i = 0; i < gic_vpes; i++) {
unsigned int j;
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_OTHER_ADDR), i);
for (j = 0; j < GIC_NUM_LOCAL_INTRS; j++) {
if (!gic_local_irq_is_routable(j))
continue;
gic_write(GIC_REG(VPE_OTHER, GIC_VPE_RMASK), 1 << j);
}
}
}
static int gic_local_irq_domain_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hw)
{
int intr = GIC_HWIRQ_TO_LOCAL(hw);
int ret = 0;
int i;
unsigned long flags;
if (!gic_local_irq_is_routable(intr))
return -EPERM;
if (intr != GIC_LOCAL_INT_TIMER && intr != GIC_LOCAL_INT_PERFCTR) {
irq_set_chip_and_handler(virq,
&gic_local_irq_controller,
handle_percpu_devid_irq);
irq_set_percpu_devid(virq);
} else {
irq_set_chip_and_handler(virq,
&gic_all_vpes_local_irq_controller,
handle_percpu_irq);
}
spin_lock_irqsave(&gic_lock, flags);
for (i = 0; i < gic_vpes; i++) {
u32 val = GIC_MAP_TO_PIN_MSK | gic_cpu_pin;
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_OTHER_ADDR), i);
switch (intr) {
case GIC_LOCAL_INT_WD:
gic_write(GIC_REG(VPE_OTHER, GIC_VPE_WD_MAP), val);
break;
case GIC_LOCAL_INT_COMPARE:
gic_write(GIC_REG(VPE_OTHER, GIC_VPE_COMPARE_MAP), val);
break;
case GIC_LOCAL_INT_TIMER:
val = GIC_MAP_TO_PIN_MSK | timer_cpu_pin;
gic_write(GIC_REG(VPE_OTHER, GIC_VPE_TIMER_MAP), val);
break;
case GIC_LOCAL_INT_PERFCTR:
gic_write(GIC_REG(VPE_OTHER, GIC_VPE_PERFCTR_MAP), val);
break;
case GIC_LOCAL_INT_SWINT0:
gic_write(GIC_REG(VPE_OTHER, GIC_VPE_SWINT0_MAP), val);
break;
case GIC_LOCAL_INT_SWINT1:
gic_write(GIC_REG(VPE_OTHER, GIC_VPE_SWINT1_MAP), val);
break;
case GIC_LOCAL_INT_FDC:
gic_write(GIC_REG(VPE_OTHER, GIC_VPE_FDC_MAP), val);
break;
default:
pr_err("Invalid local IRQ %d\n", intr);
ret = -EINVAL;
break;
}
}
spin_unlock_irqrestore(&gic_lock, flags);
return ret;
}
static int gic_shared_irq_domain_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hw)
{
int intr = GIC_HWIRQ_TO_SHARED(hw);
unsigned long flags;
irq_set_chip_and_handler(virq, &gic_level_irq_controller,
handle_level_irq);
spin_lock_irqsave(&gic_lock, flags);
gic_map_to_pin(intr, gic_cpu_pin);
gic_map_to_vpe(intr, 0);
set_bit(intr, pcpu_masks[0].pcpu_mask);
spin_unlock_irqrestore(&gic_lock, flags);
return 0;
}
static int gic_irq_domain_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hw)
{
if (GIC_HWIRQ_TO_LOCAL(hw) < GIC_NUM_LOCAL_INTRS)
return gic_local_irq_domain_map(d, virq, hw);
return gic_shared_irq_domain_map(d, virq, hw);
}
static int gic_irq_domain_xlate(struct irq_domain *d, struct device_node *ctrlr,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq,
unsigned int *out_type)
{
if (intsize != 3)
return -EINVAL;
if (intspec[0] == GIC_SHARED)
*out_hwirq = GIC_SHARED_TO_HWIRQ(intspec[1]);
else if (intspec[0] == GIC_LOCAL)
*out_hwirq = GIC_LOCAL_TO_HWIRQ(intspec[1]);
else
return -EINVAL;
*out_type = intspec[2] & IRQ_TYPE_SENSE_MASK;
return 0;
}
static void __init __gic_init(unsigned long gic_base_addr,
unsigned long gic_addrspace_size,
unsigned int cpu_vec, unsigned int irqbase,
struct device_node *node)
{
unsigned int gicconfig;
gic_base = ioremap_nocache(gic_base_addr, gic_addrspace_size);
gicconfig = gic_read(GIC_REG(SHARED, GIC_SH_CONFIG));
gic_shared_intrs = (gicconfig & GIC_SH_CONFIG_NUMINTRS_MSK) >>
GIC_SH_CONFIG_NUMINTRS_SHF;
gic_shared_intrs = ((gic_shared_intrs + 1) * 8);
gic_vpes = (gicconfig & GIC_SH_CONFIG_NUMVPES_MSK) >>
GIC_SH_CONFIG_NUMVPES_SHF;
gic_vpes = gic_vpes + 1;
if (cpu_has_veic) {
gic_cpu_pin = 0;
timer_cpu_pin = gic_cpu_pin;
set_vi_handler(gic_cpu_pin + GIC_PIN_TO_VEC_OFFSET,
__gic_irq_dispatch);
} else {
gic_cpu_pin = cpu_vec - GIC_CPU_PIN_OFFSET;
irq_set_chained_handler(MIPS_CPU_IRQ_BASE + cpu_vec,
gic_irq_dispatch);
if (IS_ENABLED(CONFIG_MIPS_CMP) &&
gic_local_irq_is_routable(GIC_LOCAL_INT_TIMER)) {
timer_cpu_pin = gic_read(GIC_REG(VPE_LOCAL,
GIC_VPE_TIMER_MAP)) &
GIC_MAP_MSK;
irq_set_chained_handler(MIPS_CPU_IRQ_BASE +
GIC_CPU_PIN_OFFSET +
timer_cpu_pin,
gic_irq_dispatch);
} else {
timer_cpu_pin = gic_cpu_pin;
}
}
gic_irq_domain = irq_domain_add_simple(node, GIC_NUM_LOCAL_INTRS +
gic_shared_intrs, irqbase,
&gic_irq_domain_ops, NULL);
if (!gic_irq_domain)
panic("Failed to add GIC IRQ domain");
gic_basic_init();
gic_ipi_init();
}
void __init gic_init(unsigned long gic_base_addr,
unsigned long gic_addrspace_size,
unsigned int cpu_vec, unsigned int irqbase)
{
__gic_init(gic_base_addr, gic_addrspace_size, cpu_vec, irqbase, NULL);
}
static int __init gic_of_init(struct device_node *node,
struct device_node *parent)
{
struct resource res;
unsigned int cpu_vec, i = 0, reserved = 0;
phys_addr_t gic_base;
size_t gic_len;
while (!of_property_read_u32_index(node, "mti,reserved-cpu-vectors",
i++, &cpu_vec))
reserved |= BIT(cpu_vec);
for (cpu_vec = 2; cpu_vec < 8; cpu_vec++) {
if (!(reserved & BIT(cpu_vec)))
break;
}
if (cpu_vec == 8) {
pr_err("No CPU vectors available for GIC\n");
return -ENODEV;
}
if (of_address_to_resource(node, 0, &res)) {
if (mips_cm_present()) {
gic_base = read_gcr_gic_base() &
~CM_GCR_GIC_BASE_GICEN_MSK;
gic_len = 0x20000;
} else {
pr_err("Failed to get GIC memory range\n");
return -ENODEV;
}
} else {
gic_base = res.start;
gic_len = resource_size(&res);
}
if (mips_cm_present())
write_gcr_gic_base(gic_base | CM_GCR_GIC_BASE_GICEN_MSK);
gic_present = true;
__gic_init(gic_base, gic_len, cpu_vec, 0, node);
return 0;
}
