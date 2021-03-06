static inline u32 gic_read32(unsigned int reg)
{
return __raw_readl(gic_base + reg);
}
static inline u64 gic_read64(unsigned int reg)
{
return __raw_readq(gic_base + reg);
}
static inline unsigned long gic_read(unsigned int reg)
{
if (!mips_cm_is64)
return gic_read32(reg);
else
return gic_read64(reg);
}
static inline void gic_write32(unsigned int reg, u32 val)
{
return __raw_writel(val, gic_base + reg);
}
static inline void gic_write64(unsigned int reg, u64 val)
{
return __raw_writeq(val, gic_base + reg);
}
static inline void gic_write(unsigned int reg, unsigned long val)
{
if (!mips_cm_is64)
return gic_write32(reg, (u32)val);
else
return gic_write64(reg, (u64)val);
}
static inline void gic_update_bits(unsigned int reg, unsigned long mask,
unsigned long val)
{
unsigned long regval;
regval = gic_read(reg);
regval &= ~mask;
regval |= val;
gic_write(reg, regval);
}
static inline void gic_reset_mask(unsigned int intr)
{
gic_write(GIC_REG(SHARED, GIC_SH_RMASK) + GIC_INTR_OFS(intr),
1ul << GIC_INTR_BIT(intr));
}
static inline void gic_set_mask(unsigned int intr)
{
gic_write(GIC_REG(SHARED, GIC_SH_SMASK) + GIC_INTR_OFS(intr),
1ul << GIC_INTR_BIT(intr));
}
static inline void gic_set_polarity(unsigned int intr, unsigned int pol)
{
gic_update_bits(GIC_REG(SHARED, GIC_SH_SET_POLARITY) +
GIC_INTR_OFS(intr), 1ul << GIC_INTR_BIT(intr),
(unsigned long)pol << GIC_INTR_BIT(intr));
}
static inline void gic_set_trigger(unsigned int intr, unsigned int trig)
{
gic_update_bits(GIC_REG(SHARED, GIC_SH_SET_TRIGGER) +
GIC_INTR_OFS(intr), 1ul << GIC_INTR_BIT(intr),
(unsigned long)trig << GIC_INTR_BIT(intr));
}
static inline void gic_set_dual_edge(unsigned int intr, unsigned int dual)
{
gic_update_bits(GIC_REG(SHARED, GIC_SH_SET_DUAL) + GIC_INTR_OFS(intr),
1ul << GIC_INTR_BIT(intr),
(unsigned long)dual << GIC_INTR_BIT(intr));
}
static inline void gic_map_to_pin(unsigned int intr, unsigned int pin)
{
gic_write32(GIC_REG(SHARED, GIC_SH_INTR_MAP_TO_PIN_BASE) +
GIC_SH_MAP_TO_PIN(intr), GIC_MAP_TO_PIN_MSK | pin);
}
static inline void gic_map_to_vpe(unsigned int intr, unsigned int vpe)
{
gic_write(GIC_REG(SHARED, GIC_SH_INTR_MAP_TO_VPE_BASE) +
GIC_SH_MAP_TO_VPE_REG_OFF(intr, vpe),
GIC_SH_MAP_TO_VPE_REG_BIT(vpe));
}
u64 notrace gic_read_count(void)
{
unsigned int hi, hi2, lo;
if (mips_cm_is64)
return (u64)gic_read(GIC_REG(SHARED, GIC_SH_COUNTER));
do {
hi = gic_read32(GIC_REG(SHARED, GIC_SH_COUNTER_63_32));
lo = gic_read32(GIC_REG(SHARED, GIC_SH_COUNTER_31_00));
hi2 = gic_read32(GIC_REG(SHARED, GIC_SH_COUNTER_63_32));
} while (hi2 != hi);
return (((u64) hi) << 32) + lo;
}
unsigned int gic_get_count_width(void)
{
unsigned int bits, config;
config = gic_read(GIC_REG(SHARED, GIC_SH_CONFIG));
bits = 32 + 4 * ((config & GIC_SH_CONFIG_COUNTBITS_MSK) >>
GIC_SH_CONFIG_COUNTBITS_SHF);
return bits;
}
void notrace gic_write_compare(u64 cnt)
{
if (mips_cm_is64) {
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_COMPARE), cnt);
} else {
gic_write32(GIC_REG(VPE_LOCAL, GIC_VPE_COMPARE_HI),
(int)(cnt >> 32));
gic_write32(GIC_REG(VPE_LOCAL, GIC_VPE_COMPARE_LO),
(int)(cnt & 0xffffffff));
}
}
void notrace gic_write_cpu_compare(u64 cnt, int cpu)
{
unsigned long flags;
local_irq_save(flags);
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_OTHER_ADDR), mips_cm_vp_id(cpu));
if (mips_cm_is64) {
gic_write(GIC_REG(VPE_OTHER, GIC_VPE_COMPARE), cnt);
} else {
gic_write32(GIC_REG(VPE_OTHER, GIC_VPE_COMPARE_HI),
(int)(cnt >> 32));
gic_write32(GIC_REG(VPE_OTHER, GIC_VPE_COMPARE_LO),
(int)(cnt & 0xffffffff));
}
local_irq_restore(flags);
}
u64 gic_read_compare(void)
{
unsigned int hi, lo;
if (mips_cm_is64)
return (u64)gic_read(GIC_REG(VPE_LOCAL, GIC_VPE_COMPARE));
hi = gic_read32(GIC_REG(VPE_LOCAL, GIC_VPE_COMPARE_HI));
lo = gic_read32(GIC_REG(VPE_LOCAL, GIC_VPE_COMPARE_LO));
return (((u64) hi) << 32) + lo;
}
void gic_start_count(void)
{
u32 gicconfig;
gicconfig = gic_read(GIC_REG(SHARED, GIC_SH_CONFIG));
gicconfig &= ~(1 << GIC_SH_CONFIG_COUNTSTOP_SHF);
gic_write(GIC_REG(SHARED, GIC_SH_CONFIG), gicconfig);
}
void gic_stop_count(void)
{
u32 gicconfig;
gicconfig = gic_read(GIC_REG(SHARED, GIC_SH_CONFIG));
gicconfig |= 1 << GIC_SH_CONFIG_COUNTSTOP_SHF;
gic_write(GIC_REG(SHARED, GIC_SH_CONFIG), gicconfig);
}
unsigned gic_read_local_vp_id(void)
{
unsigned long ident;
ident = gic_read(GIC_REG(VPE_LOCAL, GIC_VP_IDENT));
return ident & GIC_VP_IDENT_VCNUM_MSK;
}
static bool gic_local_irq_is_routable(int intr)
{
u32 vpe_ctl;
if (cpu_has_veic)
return true;
vpe_ctl = gic_read32(GIC_REG(VPE_LOCAL, GIC_VPE_CTL));
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
static void gic_bind_eic_interrupt(int irq, int set)
{
irq -= GIC_PIN_TO_VEC_OFFSET;
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_EIC_SHADOW_SET_BASE) +
GIC_VPE_EIC_SS(irq), set);
}
static void gic_send_ipi(struct irq_data *d, unsigned int cpu)
{
irq_hw_number_t hwirq = GIC_HWIRQ_TO_SHARED(irqd_to_hwirq(d));
gic_write(GIC_REG(SHARED, GIC_SH_WEDGE), GIC_SH_WEDGE_SET(hwirq));
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
int gic_get_c0_fdc_int(void)
{
if (!gic_local_irq_is_routable(GIC_LOCAL_INT_FDC)) {
if (cp0_fdc_irq < 0)
return -1;
return MIPS_CPU_IRQ_BASE + cp0_fdc_irq;
}
return irq_create_mapping(gic_irq_domain,
GIC_LOCAL_TO_HWIRQ(GIC_LOCAL_INT_FDC));
}
int gic_get_usm_range(struct resource *gic_usm_res)
{
if (!gic_present)
return -1;
gic_usm_res->start = __gic_base_addr + USM_VISIBLE_SECTION_OFS;
gic_usm_res->end = gic_usm_res->start + (USM_VISIBLE_SECTION_SIZE - 1);
return 0;
}
static void gic_handle_shared_int(bool chained)
{
unsigned int i, intr, virq, gic_reg_step = mips_cm_is64 ? 8 : 4;
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
pending_reg += gic_reg_step;
intrmask_reg += gic_reg_step;
if (!IS_ENABLED(CONFIG_64BIT) || mips_cm_is64)
continue;
pending[i] |= (u64)gic_read(pending_reg) << 32;
intrmask[i] |= (u64)gic_read(intrmask_reg) << 32;
pending_reg += gic_reg_step;
intrmask_reg += gic_reg_step;
}
bitmap_and(pending, pending, intrmask, gic_shared_intrs);
bitmap_and(pending, pending, pcpu_mask, gic_shared_intrs);
for_each_set_bit(intr, pending, gic_shared_intrs) {
virq = irq_linear_revmap(gic_irq_domain,
GIC_SHARED_TO_HWIRQ(intr));
if (chained)
generic_handle_irq(virq);
else
do_IRQ(virq);
}
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
if (is_edge)
irq_set_chip_handler_name_locked(d, &gic_edge_irq_controller,
handle_edge_irq, NULL);
else
irq_set_chip_handler_name_locked(d, &gic_level_irq_controller,
handle_level_irq, NULL);
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
if (cpumask_empty(&tmp))
return -EINVAL;
spin_lock_irqsave(&gic_lock, flags);
gic_map_to_vpe(irq, mips_cm_vp_id(cpumask_first(&tmp)));
for (i = 0; i < min(gic_vpes, NR_CPUS); i++)
clear_bit(irq, pcpu_masks[i].pcpu_mask);
set_bit(irq, pcpu_masks[cpumask_first(&tmp)].pcpu_mask);
cpumask_copy(irq_data_get_affinity_mask(d), cpumask);
spin_unlock_irqrestore(&gic_lock, flags);
return IRQ_SET_MASK_OK_NOCOPY;
}
static void gic_handle_local_int(bool chained)
{
unsigned long pending, masked;
unsigned int intr, virq;
pending = gic_read32(GIC_REG(VPE_LOCAL, GIC_VPE_PEND));
masked = gic_read32(GIC_REG(VPE_LOCAL, GIC_VPE_MASK));
bitmap_and(&pending, &pending, &masked, GIC_NUM_LOCAL_INTRS);
for_each_set_bit(intr, &pending, GIC_NUM_LOCAL_INTRS) {
virq = irq_linear_revmap(gic_irq_domain,
GIC_LOCAL_TO_HWIRQ(intr));
if (chained)
generic_handle_irq(virq);
else
do_IRQ(virq);
}
}
static void gic_mask_local_irq(struct irq_data *d)
{
int intr = GIC_HWIRQ_TO_LOCAL(d->hwirq);
gic_write32(GIC_REG(VPE_LOCAL, GIC_VPE_RMASK), 1 << intr);
}
static void gic_unmask_local_irq(struct irq_data *d)
{
int intr = GIC_HWIRQ_TO_LOCAL(d->hwirq);
gic_write32(GIC_REG(VPE_LOCAL, GIC_VPE_SMASK), 1 << intr);
}
static void gic_mask_local_irq_all_vpes(struct irq_data *d)
{
int intr = GIC_HWIRQ_TO_LOCAL(d->hwirq);
int i;
unsigned long flags;
spin_lock_irqsave(&gic_lock, flags);
for (i = 0; i < gic_vpes; i++) {
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_OTHER_ADDR),
mips_cm_vp_id(i));
gic_write32(GIC_REG(VPE_OTHER, GIC_VPE_RMASK), 1 << intr);
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
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_OTHER_ADDR),
mips_cm_vp_id(i));
gic_write32(GIC_REG(VPE_OTHER, GIC_VPE_SMASK), 1 << intr);
}
spin_unlock_irqrestore(&gic_lock, flags);
}
static void __gic_irq_dispatch(void)
{
gic_handle_local_int(false);
gic_handle_shared_int(false);
}
static void gic_irq_dispatch(struct irq_desc *desc)
{
gic_handle_local_int(true);
gic_handle_shared_int(true);
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
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_OTHER_ADDR),
mips_cm_vp_id(i));
for (j = 0; j < GIC_NUM_LOCAL_INTRS; j++) {
if (!gic_local_irq_is_routable(j))
continue;
gic_write32(GIC_REG(VPE_OTHER, GIC_VPE_RMASK), 1 << j);
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
spin_lock_irqsave(&gic_lock, flags);
for (i = 0; i < gic_vpes; i++) {
u32 val = GIC_MAP_TO_PIN_MSK | gic_cpu_pin;
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_OTHER_ADDR),
mips_cm_vp_id(i));
switch (intr) {
case GIC_LOCAL_INT_WD:
gic_write32(GIC_REG(VPE_OTHER, GIC_VPE_WD_MAP), val);
break;
case GIC_LOCAL_INT_COMPARE:
gic_write32(GIC_REG(VPE_OTHER, GIC_VPE_COMPARE_MAP),
val);
break;
case GIC_LOCAL_INT_TIMER:
val = GIC_MAP_TO_PIN_MSK | timer_cpu_pin;
gic_write32(GIC_REG(VPE_OTHER, GIC_VPE_TIMER_MAP),
val);
break;
case GIC_LOCAL_INT_PERFCTR:
gic_write32(GIC_REG(VPE_OTHER, GIC_VPE_PERFCTR_MAP),
val);
break;
case GIC_LOCAL_INT_SWINT0:
gic_write32(GIC_REG(VPE_OTHER, GIC_VPE_SWINT0_MAP),
val);
break;
case GIC_LOCAL_INT_SWINT1:
gic_write32(GIC_REG(VPE_OTHER, GIC_VPE_SWINT1_MAP),
val);
break;
case GIC_LOCAL_INT_FDC:
gic_write32(GIC_REG(VPE_OTHER, GIC_VPE_FDC_MAP), val);
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
irq_hw_number_t hw, unsigned int vpe)
{
int intr = GIC_HWIRQ_TO_SHARED(hw);
unsigned long flags;
int i;
spin_lock_irqsave(&gic_lock, flags);
gic_map_to_pin(intr, gic_cpu_pin);
gic_map_to_vpe(intr, mips_cm_vp_id(vpe));
for (i = 0; i < min(gic_vpes, NR_CPUS); i++)
clear_bit(intr, pcpu_masks[i].pcpu_mask);
set_bit(intr, pcpu_masks[vpe].pcpu_mask);
spin_unlock_irqrestore(&gic_lock, flags);
return 0;
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
static int gic_irq_domain_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hwirq)
{
int err;
if (hwirq >= GIC_SHARED_HWIRQ_BASE) {
if (test_bit(GIC_HWIRQ_TO_SHARED(hwirq), ipi_resrv))
return -EBUSY;
err = irq_domain_set_hwirq_and_chip(d, virq, hwirq,
&gic_level_irq_controller,
NULL);
if (err)
return err;
return gic_shared_irq_domain_map(d, virq, hwirq, 0);
}
switch (GIC_HWIRQ_TO_LOCAL(hwirq)) {
case GIC_LOCAL_INT_TIMER:
case GIC_LOCAL_INT_PERFCTR:
case GIC_LOCAL_INT_FDC:
err = irq_domain_set_hwirq_and_chip(d, virq, hwirq,
&gic_all_vpes_local_irq_controller,
NULL);
if (err)
return err;
irq_set_handler(virq, handle_percpu_irq);
break;
default:
err = irq_domain_set_hwirq_and_chip(d, virq, hwirq,
&gic_local_irq_controller,
NULL);
if (err)
return err;
irq_set_handler(virq, handle_percpu_devid_irq);
irq_set_percpu_devid(virq);
break;
}
return gic_local_irq_domain_map(d, virq, hwirq);
}
static int gic_irq_domain_alloc(struct irq_domain *d, unsigned int virq,
unsigned int nr_irqs, void *arg)
{
struct irq_fwspec *fwspec = arg;
irq_hw_number_t hwirq;
if (fwspec->param[0] == GIC_SHARED)
hwirq = GIC_SHARED_TO_HWIRQ(fwspec->param[1]);
else
hwirq = GIC_LOCAL_TO_HWIRQ(fwspec->param[1]);
return gic_irq_domain_map(d, virq, hwirq);
}
void gic_irq_domain_free(struct irq_domain *d, unsigned int virq,
unsigned int nr_irqs)
{
}
static int gic_ipi_domain_xlate(struct irq_domain *d, struct device_node *ctrlr,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq,
unsigned int *out_type)
{
*out_hwirq = 0;
*out_type = IRQ_TYPE_EDGE_RISING;
return 0;
}
static int gic_ipi_domain_alloc(struct irq_domain *d, unsigned int virq,
unsigned int nr_irqs, void *arg)
{
struct cpumask *ipimask = arg;
irq_hw_number_t hwirq, base_hwirq;
int cpu, ret, i;
base_hwirq = find_first_bit(ipi_available, gic_shared_intrs);
if (base_hwirq == gic_shared_intrs)
return -ENOMEM;
for (i = base_hwirq; i < nr_irqs; i++) {
if (!test_bit(i, ipi_available))
return -EBUSY;
}
bitmap_clear(ipi_available, base_hwirq, nr_irqs);
i = 0;
for_each_cpu(cpu, ipimask) {
hwirq = GIC_SHARED_TO_HWIRQ(base_hwirq + i);
ret = irq_domain_set_hwirq_and_chip(d, virq + i, hwirq,
&gic_edge_irq_controller,
NULL);
if (ret)
goto error;
ret = irq_domain_set_hwirq_and_chip(d->parent, virq + i, hwirq,
&gic_edge_irq_controller,
NULL);
if (ret)
goto error;
ret = irq_set_irq_type(virq + i, IRQ_TYPE_EDGE_RISING);
if (ret)
goto error;
ret = gic_shared_irq_domain_map(d, virq + i, hwirq, cpu);
if (ret)
goto error;
i++;
}
return 0;
error:
bitmap_set(ipi_available, base_hwirq, nr_irqs);
return ret;
}
void gic_ipi_domain_free(struct irq_domain *d, unsigned int virq,
unsigned int nr_irqs)
{
irq_hw_number_t base_hwirq;
struct irq_data *data;
data = irq_get_irq_data(virq);
if (!data)
return;
base_hwirq = GIC_HWIRQ_TO_SHARED(irqd_to_hwirq(data));
bitmap_set(ipi_available, base_hwirq, nr_irqs);
}
int gic_ipi_domain_match(struct irq_domain *d, struct device_node *node,
enum irq_domain_bus_token bus_token)
{
bool is_ipi;
switch (bus_token) {
case DOMAIN_BUS_IPI:
is_ipi = d->bus_token == bus_token;
return (!node || to_of_node(d->fwnode) == node) && is_ipi;
break;
default:
return 0;
}
}
static void __init __gic_init(unsigned long gic_base_addr,
unsigned long gic_addrspace_size,
unsigned int cpu_vec, unsigned int irqbase,
struct device_node *node)
{
unsigned int gicconfig, cpu;
unsigned int v[2];
__gic_base_addr = gic_base_addr;
gic_base = ioremap_nocache(gic_base_addr, gic_addrspace_size);
gicconfig = gic_read(GIC_REG(SHARED, GIC_SH_CONFIG));
gic_shared_intrs = (gicconfig & GIC_SH_CONFIG_NUMINTRS_MSK) >>
GIC_SH_CONFIG_NUMINTRS_SHF;
gic_shared_intrs = ((gic_shared_intrs + 1) * 8);
gic_vpes = (gicconfig & GIC_SH_CONFIG_NUMVPES_MSK) >>
GIC_SH_CONFIG_NUMVPES_SHF;
gic_vpes = gic_vpes + 1;
if (cpu_has_veic) {
for_each_present_cpu(cpu) {
gic_write(GIC_REG(VPE_LOCAL, GIC_VPE_OTHER_ADDR),
mips_cm_vp_id(cpu));
gic_write(GIC_REG(VPE_OTHER, GIC_VPE_CTL),
GIC_VPE_CTL_EIC_MODE_MSK);
}
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
timer_cpu_pin = gic_read32(GIC_REG(VPE_LOCAL,
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
gic_irq_domain->name = "mips-gic-irq";
gic_ipi_domain = irq_domain_add_hierarchy(gic_irq_domain,
IRQ_DOMAIN_FLAG_IPI_PER_CPU,
GIC_NUM_LOCAL_INTRS + gic_shared_intrs,
node, &gic_ipi_domain_ops, NULL);
if (!gic_ipi_domain)
panic("Failed to add GIC IPI domain");
gic_ipi_domain->name = "mips-gic-ipi";
gic_ipi_domain->bus_token = DOMAIN_BUS_IPI;
if (node &&
!of_property_read_u32_array(node, "mti,reserved-ipi-vectors", v, 2)) {
bitmap_set(ipi_resrv, v[0], v[1]);
} else {
bitmap_set(ipi_resrv,
gic_shared_intrs - 2 * gic_vpes,
2 * gic_vpes);
}
bitmap_copy(ipi_available, ipi_resrv, GIC_MAX_INTRS);
gic_basic_init();
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
