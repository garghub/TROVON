static inline void l2c_wait_mask(void __iomem *reg, unsigned long mask)
{
while (readl_relaxed(reg) & mask)
cpu_relax();
}
static void l2c_write_sec(unsigned long val, void __iomem *base, unsigned reg)
{
if (val == readl_relaxed(base + reg))
return;
if (outer_cache.write_sec)
outer_cache.write_sec(val, reg);
else
writel_relaxed(val, base + reg);
}
static inline void l2c_set_debug(void __iomem *base, unsigned long val)
{
l2c_write_sec(val, base, L2X0_DEBUG_CTRL);
}
static void __l2c_op_way(void __iomem *reg)
{
writel_relaxed(l2x0_way_mask, reg);
l2c_wait_mask(reg, l2x0_way_mask);
}
static inline void l2c_unlock(void __iomem *base, unsigned num)
{
unsigned i;
for (i = 0; i < num; i++) {
writel_relaxed(0, base + L2X0_LOCKDOWN_WAY_D_BASE +
i * L2X0_LOCKDOWN_STRIDE);
writel_relaxed(0, base + L2X0_LOCKDOWN_WAY_I_BASE +
i * L2X0_LOCKDOWN_STRIDE);
}
}
static void l2c_configure(void __iomem *base)
{
l2c_write_sec(l2x0_saved_regs.aux_ctrl, base, L2X0_AUX_CTRL);
}
static void l2c_enable(void __iomem *base, unsigned num_lock)
{
unsigned long flags;
if (outer_cache.configure)
outer_cache.configure(&l2x0_saved_regs);
else
l2x0_data->configure(base);
l2x0_data->unlock(base, num_lock);
local_irq_save(flags);
__l2c_op_way(base + L2X0_INV_WAY);
writel_relaxed(0, base + sync_reg_offset);
l2c_wait_mask(base + sync_reg_offset, 1);
local_irq_restore(flags);
l2c_write_sec(L2X0_CTRL_EN, base, L2X0_CTRL);
}
static void l2c_disable(void)
{
void __iomem *base = l2x0_base;
l2x0_pmu_suspend();
outer_cache.flush_all();
l2c_write_sec(0, base, L2X0_CTRL);
dsb(st);
}
static void l2c_save(void __iomem *base)
{
l2x0_saved_regs.aux_ctrl = readl_relaxed(l2x0_base + L2X0_AUX_CTRL);
}
static void l2c_resume(void)
{
void __iomem *base = l2x0_base;
if (!(readl_relaxed(base + L2X0_CTRL) & L2X0_CTRL_EN))
l2c_enable(base, l2x0_data->num_lock);
l2x0_pmu_resume();
}
static void __l2c210_cache_sync(void __iomem *base)
{
writel_relaxed(0, base + sync_reg_offset);
}
static void __l2c210_op_pa_range(void __iomem *reg, unsigned long start,
unsigned long end)
{
while (start < end) {
writel_relaxed(start, reg);
start += CACHE_LINE_SIZE;
}
}
static void l2c210_inv_range(unsigned long start, unsigned long end)
{
void __iomem *base = l2x0_base;
if (start & (CACHE_LINE_SIZE - 1)) {
start &= ~(CACHE_LINE_SIZE - 1);
writel_relaxed(start, base + L2X0_CLEAN_INV_LINE_PA);
start += CACHE_LINE_SIZE;
}
if (end & (CACHE_LINE_SIZE - 1)) {
end &= ~(CACHE_LINE_SIZE - 1);
writel_relaxed(end, base + L2X0_CLEAN_INV_LINE_PA);
}
__l2c210_op_pa_range(base + L2X0_INV_LINE_PA, start, end);
__l2c210_cache_sync(base);
}
static void l2c210_clean_range(unsigned long start, unsigned long end)
{
void __iomem *base = l2x0_base;
start &= ~(CACHE_LINE_SIZE - 1);
__l2c210_op_pa_range(base + L2X0_CLEAN_LINE_PA, start, end);
__l2c210_cache_sync(base);
}
static void l2c210_flush_range(unsigned long start, unsigned long end)
{
void __iomem *base = l2x0_base;
start &= ~(CACHE_LINE_SIZE - 1);
__l2c210_op_pa_range(base + L2X0_CLEAN_INV_LINE_PA, start, end);
__l2c210_cache_sync(base);
}
static void l2c210_flush_all(void)
{
void __iomem *base = l2x0_base;
BUG_ON(!irqs_disabled());
__l2c_op_way(base + L2X0_CLEAN_INV_WAY);
__l2c210_cache_sync(base);
}
static void l2c210_sync(void)
{
__l2c210_cache_sync(l2x0_base);
}
static inline void __l2c220_cache_sync(void __iomem *base)
{
writel_relaxed(0, base + L2X0_CACHE_SYNC);
l2c_wait_mask(base + L2X0_CACHE_SYNC, 1);
}
static void l2c220_op_way(void __iomem *base, unsigned reg)
{
unsigned long flags;
raw_spin_lock_irqsave(&l2x0_lock, flags);
__l2c_op_way(base + reg);
__l2c220_cache_sync(base);
raw_spin_unlock_irqrestore(&l2x0_lock, flags);
}
static unsigned long l2c220_op_pa_range(void __iomem *reg, unsigned long start,
unsigned long end, unsigned long flags)
{
raw_spinlock_t *lock = &l2x0_lock;
while (start < end) {
unsigned long blk_end = start + min(end - start, 4096UL);
while (start < blk_end) {
l2c_wait_mask(reg, 1);
writel_relaxed(start, reg);
start += CACHE_LINE_SIZE;
}
if (blk_end < end) {
raw_spin_unlock_irqrestore(lock, flags);
raw_spin_lock_irqsave(lock, flags);
}
}
return flags;
}
static void l2c220_inv_range(unsigned long start, unsigned long end)
{
void __iomem *base = l2x0_base;
unsigned long flags;
raw_spin_lock_irqsave(&l2x0_lock, flags);
if ((start | end) & (CACHE_LINE_SIZE - 1)) {
if (start & (CACHE_LINE_SIZE - 1)) {
start &= ~(CACHE_LINE_SIZE - 1);
writel_relaxed(start, base + L2X0_CLEAN_INV_LINE_PA);
start += CACHE_LINE_SIZE;
}
if (end & (CACHE_LINE_SIZE - 1)) {
end &= ~(CACHE_LINE_SIZE - 1);
l2c_wait_mask(base + L2X0_CLEAN_INV_LINE_PA, 1);
writel_relaxed(end, base + L2X0_CLEAN_INV_LINE_PA);
}
}
flags = l2c220_op_pa_range(base + L2X0_INV_LINE_PA,
start, end, flags);
l2c_wait_mask(base + L2X0_INV_LINE_PA, 1);
__l2c220_cache_sync(base);
raw_spin_unlock_irqrestore(&l2x0_lock, flags);
}
static void l2c220_clean_range(unsigned long start, unsigned long end)
{
void __iomem *base = l2x0_base;
unsigned long flags;
start &= ~(CACHE_LINE_SIZE - 1);
if ((end - start) >= l2x0_size) {
l2c220_op_way(base, L2X0_CLEAN_WAY);
return;
}
raw_spin_lock_irqsave(&l2x0_lock, flags);
flags = l2c220_op_pa_range(base + L2X0_CLEAN_LINE_PA,
start, end, flags);
l2c_wait_mask(base + L2X0_CLEAN_INV_LINE_PA, 1);
__l2c220_cache_sync(base);
raw_spin_unlock_irqrestore(&l2x0_lock, flags);
}
static void l2c220_flush_range(unsigned long start, unsigned long end)
{
void __iomem *base = l2x0_base;
unsigned long flags;
start &= ~(CACHE_LINE_SIZE - 1);
if ((end - start) >= l2x0_size) {
l2c220_op_way(base, L2X0_CLEAN_INV_WAY);
return;
}
raw_spin_lock_irqsave(&l2x0_lock, flags);
flags = l2c220_op_pa_range(base + L2X0_CLEAN_INV_LINE_PA,
start, end, flags);
l2c_wait_mask(base + L2X0_CLEAN_INV_LINE_PA, 1);
__l2c220_cache_sync(base);
raw_spin_unlock_irqrestore(&l2x0_lock, flags);
}
static void l2c220_flush_all(void)
{
l2c220_op_way(l2x0_base, L2X0_CLEAN_INV_WAY);
}
static void l2c220_sync(void)
{
unsigned long flags;
raw_spin_lock_irqsave(&l2x0_lock, flags);
__l2c220_cache_sync(l2x0_base);
raw_spin_unlock_irqrestore(&l2x0_lock, flags);
}
static void l2c220_enable(void __iomem *base, unsigned num_lock)
{
l2x0_saved_regs.aux_ctrl |= L220_AUX_CTRL_NS_LOCKDOWN;
l2c_enable(base, num_lock);
}
static void l2c220_unlock(void __iomem *base, unsigned num_lock)
{
if (readl_relaxed(base + L2X0_AUX_CTRL) & L220_AUX_CTRL_NS_LOCKDOWN)
l2c_unlock(base, num_lock);
}
static void l2c310_inv_range_erratum(unsigned long start, unsigned long end)
{
void __iomem *base = l2x0_base;
if ((start | end) & (CACHE_LINE_SIZE - 1)) {
unsigned long flags;
raw_spin_lock_irqsave(&l2x0_lock, flags);
l2c_set_debug(base, 0x03);
if (start & (CACHE_LINE_SIZE - 1)) {
start &= ~(CACHE_LINE_SIZE - 1);
writel_relaxed(start, base + L2X0_CLEAN_LINE_PA);
writel_relaxed(start, base + L2X0_INV_LINE_PA);
start += CACHE_LINE_SIZE;
}
if (end & (CACHE_LINE_SIZE - 1)) {
end &= ~(CACHE_LINE_SIZE - 1);
writel_relaxed(end, base + L2X0_CLEAN_LINE_PA);
writel_relaxed(end, base + L2X0_INV_LINE_PA);
}
l2c_set_debug(base, 0x00);
raw_spin_unlock_irqrestore(&l2x0_lock, flags);
}
__l2c210_op_pa_range(base + L2X0_INV_LINE_PA, start, end);
__l2c210_cache_sync(base);
}
static void l2c310_flush_range_erratum(unsigned long start, unsigned long end)
{
raw_spinlock_t *lock = &l2x0_lock;
unsigned long flags;
void __iomem *base = l2x0_base;
raw_spin_lock_irqsave(lock, flags);
while (start < end) {
unsigned long blk_end = start + min(end - start, 4096UL);
l2c_set_debug(base, 0x03);
while (start < blk_end) {
writel_relaxed(start, base + L2X0_CLEAN_LINE_PA);
writel_relaxed(start, base + L2X0_INV_LINE_PA);
start += CACHE_LINE_SIZE;
}
l2c_set_debug(base, 0x00);
if (blk_end < end) {
raw_spin_unlock_irqrestore(lock, flags);
raw_spin_lock_irqsave(lock, flags);
}
}
raw_spin_unlock_irqrestore(lock, flags);
__l2c210_cache_sync(base);
}
static void l2c310_flush_all_erratum(void)
{
void __iomem *base = l2x0_base;
unsigned long flags;
raw_spin_lock_irqsave(&l2x0_lock, flags);
l2c_set_debug(base, 0x03);
__l2c_op_way(base + L2X0_CLEAN_INV_WAY);
l2c_set_debug(base, 0x00);
__l2c210_cache_sync(base);
raw_spin_unlock_irqrestore(&l2x0_lock, flags);
}
static void __init l2c310_save(void __iomem *base)
{
unsigned revision;
l2c_save(base);
l2x0_saved_regs.tag_latency = readl_relaxed(base +
L310_TAG_LATENCY_CTRL);
l2x0_saved_regs.data_latency = readl_relaxed(base +
L310_DATA_LATENCY_CTRL);
l2x0_saved_regs.filter_end = readl_relaxed(base +
L310_ADDR_FILTER_END);
l2x0_saved_regs.filter_start = readl_relaxed(base +
L310_ADDR_FILTER_START);
revision = readl_relaxed(base + L2X0_CACHE_ID) &
L2X0_CACHE_ID_RTL_MASK;
if (revision >= L310_CACHE_ID_RTL_R2P0)
l2x0_saved_regs.prefetch_ctrl = readl_relaxed(base +
L310_PREFETCH_CTRL);
if (revision >= L310_CACHE_ID_RTL_R3P0)
l2x0_saved_regs.pwr_ctrl = readl_relaxed(base +
L310_POWER_CTRL);
}
static void l2c310_configure(void __iomem *base)
{
unsigned revision;
l2c_configure(base);
l2c_write_sec(l2x0_saved_regs.tag_latency, base,
L310_TAG_LATENCY_CTRL);
l2c_write_sec(l2x0_saved_regs.data_latency, base,
L310_DATA_LATENCY_CTRL);
l2c_write_sec(l2x0_saved_regs.filter_end, base,
L310_ADDR_FILTER_END);
l2c_write_sec(l2x0_saved_regs.filter_start, base,
L310_ADDR_FILTER_START);
revision = readl_relaxed(base + L2X0_CACHE_ID) &
L2X0_CACHE_ID_RTL_MASK;
if (revision >= L310_CACHE_ID_RTL_R2P0)
l2c_write_sec(l2x0_saved_regs.prefetch_ctrl, base,
L310_PREFETCH_CTRL);
if (revision >= L310_CACHE_ID_RTL_R3P0)
l2c_write_sec(l2x0_saved_regs.pwr_ctrl, base,
L310_POWER_CTRL);
}
static int l2c310_starting_cpu(unsigned int cpu)
{
set_auxcr(get_auxcr() | BIT(3) | BIT(2) | BIT(1));
return 0;
}
static int l2c310_dying_cpu(unsigned int cpu)
{
set_auxcr(get_auxcr() & ~(BIT(3) | BIT(2) | BIT(1)));
return 0;
}
static void __init l2c310_enable(void __iomem *base, unsigned num_lock)
{
unsigned rev = readl_relaxed(base + L2X0_CACHE_ID) & L2X0_CACHE_ID_RTL_MASK;
bool cortex_a9 = read_cpuid_part() == ARM_CPU_PART_CORTEX_A9;
u32 aux = l2x0_saved_regs.aux_ctrl;
if (rev >= L310_CACHE_ID_RTL_R2P0) {
if (cortex_a9 && !l2x0_bresp_disable) {
aux |= L310_AUX_CTRL_EARLY_BRESP;
pr_info("L2C-310 enabling early BRESP for Cortex-A9\n");
} else if (aux & L310_AUX_CTRL_EARLY_BRESP) {
pr_warn("L2C-310 early BRESP only supported with Cortex-A9\n");
aux &= ~L310_AUX_CTRL_EARLY_BRESP;
}
}
if (cortex_a9 && !l2x0_flz_disable) {
u32 aux_cur = readl_relaxed(base + L2X0_AUX_CTRL);
u32 acr = get_auxcr();
pr_debug("Cortex-A9 ACR=0x%08x\n", acr);
if (acr & BIT(3) && !(aux_cur & L310_AUX_CTRL_FULL_LINE_ZERO))
pr_err("L2C-310: full line of zeros enabled in Cortex-A9 but not L2C-310 - invalid\n");
if (aux & L310_AUX_CTRL_FULL_LINE_ZERO && !(acr & BIT(3)))
pr_err("L2C-310: enabling full line of zeros but not enabled in Cortex-A9\n");
if (!(aux & L310_AUX_CTRL_FULL_LINE_ZERO) && !outer_cache.write_sec) {
aux |= L310_AUX_CTRL_FULL_LINE_ZERO;
pr_info("L2C-310 full line of zeros enabled for Cortex-A9\n");
}
} else if (aux & (L310_AUX_CTRL_FULL_LINE_ZERO | L310_AUX_CTRL_EARLY_BRESP)) {
pr_err("L2C-310: disabling Cortex-A9 specific feature bits\n");
aux &= ~(L310_AUX_CTRL_FULL_LINE_ZERO | L310_AUX_CTRL_EARLY_BRESP);
}
l2x0_saved_regs.aux_ctrl = aux | L310_AUX_CTRL_NS_LOCKDOWN;
l2c_enable(base, num_lock);
aux = readl_relaxed(base + L2X0_AUX_CTRL);
if (aux & (L310_AUX_CTRL_DATA_PREFETCH | L310_AUX_CTRL_INSTR_PREFETCH)) {
u32 prefetch = readl_relaxed(base + L310_PREFETCH_CTRL);
pr_info("L2C-310 %s%s prefetch enabled, offset %u lines\n",
aux & L310_AUX_CTRL_INSTR_PREFETCH ? "I" : "",
aux & L310_AUX_CTRL_DATA_PREFETCH ? "D" : "",
1 + (prefetch & L310_PREFETCH_CTRL_OFFSET_MASK));
}
if (rev >= L310_CACHE_ID_RTL_R3P0) {
u32 power_ctrl;
power_ctrl = readl_relaxed(base + L310_POWER_CTRL);
pr_info("L2C-310 dynamic clock gating %sabled, standby mode %sabled\n",
power_ctrl & L310_DYNAMIC_CLK_GATING_EN ? "en" : "dis",
power_ctrl & L310_STNDBY_MODE_EN ? "en" : "dis");
}
if (aux & L310_AUX_CTRL_FULL_LINE_ZERO)
cpuhp_setup_state(CPUHP_AP_ARM_L2X0_STARTING,
"arm/l2x0:starting", l2c310_starting_cpu,
l2c310_dying_cpu);
}
static void __init l2c310_fixup(void __iomem *base, u32 cache_id,
struct outer_cache_fns *fns)
{
unsigned revision = cache_id & L2X0_CACHE_ID_RTL_MASK;
const char *errata[8];
unsigned n = 0;
if (IS_ENABLED(CONFIG_PL310_ERRATA_588369) &&
revision < L310_CACHE_ID_RTL_R2P0 &&
fns->inv_range == l2c210_inv_range) {
fns->inv_range = l2c310_inv_range_erratum;
fns->flush_range = l2c310_flush_range_erratum;
errata[n++] = "588369";
}
if (IS_ENABLED(CONFIG_PL310_ERRATA_727915) &&
revision >= L310_CACHE_ID_RTL_R2P0 &&
revision < L310_CACHE_ID_RTL_R3P1) {
fns->flush_all = l2c310_flush_all_erratum;
errata[n++] = "727915";
}
if (revision >= L310_CACHE_ID_RTL_R3P0 &&
revision < L310_CACHE_ID_RTL_R3P2) {
u32 val = l2x0_saved_regs.prefetch_ctrl;
if (val & L310_PREFETCH_CTRL_DBL_LINEFILL) {
val &= ~L310_PREFETCH_CTRL_DBL_LINEFILL;
l2x0_saved_regs.prefetch_ctrl = val;
errata[n++] = "752271";
}
}
if (IS_ENABLED(CONFIG_PL310_ERRATA_753970) &&
revision == L310_CACHE_ID_RTL_R3P0) {
sync_reg_offset = L2X0_DUMMY_REG;
errata[n++] = "753970";
}
if (IS_ENABLED(CONFIG_PL310_ERRATA_769419))
errata[n++] = "769419";
if (n) {
unsigned i;
pr_info("L2C-310 errat%s", n > 1 ? "a" : "um");
for (i = 0; i < n; i++)
pr_cont(" %s", errata[i]);
pr_cont(" enabled\n");
}
}
static void l2c310_disable(void)
{
if (l2x0_saved_regs.aux_ctrl & L310_AUX_CTRL_FULL_LINE_ZERO)
set_auxcr(get_auxcr() & ~(BIT(3) | BIT(2) | BIT(1)));
l2c_disable();
}
static void l2c310_resume(void)
{
l2c_resume();
if (l2x0_saved_regs.aux_ctrl & L310_AUX_CTRL_FULL_LINE_ZERO)
set_auxcr(get_auxcr() | BIT(3) | BIT(2) | BIT(1));
}
static void l2c310_unlock(void __iomem *base, unsigned num_lock)
{
if (readl_relaxed(base + L2X0_AUX_CTRL) & L310_AUX_CTRL_NS_LOCKDOWN)
l2c_unlock(base, num_lock);
}
static int __init __l2c_init(const struct l2c_init_data *data,
u32 aux_val, u32 aux_mask, u32 cache_id, bool nosync)
{
struct outer_cache_fns fns;
unsigned way_size_bits, ways;
u32 aux, old_aux;
l2x0_data = kmemdup(data, sizeof(*data), GFP_KERNEL);
if (!l2x0_data)
return -ENOMEM;
if (aux_val & aux_mask)
pr_alert("L2C: platform provided aux values permit register corruption.\n");
old_aux = aux = readl_relaxed(l2x0_base + L2X0_AUX_CTRL);
aux &= aux_mask;
aux |= aux_val;
if (old_aux != aux)
pr_warn("L2C: DT/platform modifies aux control register: 0x%08x -> 0x%08x\n",
old_aux, aux);
switch (cache_id & L2X0_CACHE_ID_PART_MASK) {
case L2X0_CACHE_ID_PART_L310:
if ((aux_val | ~aux_mask) & (L2C_AUX_CTRL_WAY_SIZE_MASK | L310_AUX_CTRL_ASSOCIATIVITY_16))
pr_warn("L2C: DT/platform tries to modify or specify cache size\n");
if (aux & (1 << 16))
ways = 16;
else
ways = 8;
break;
case L2X0_CACHE_ID_PART_L210:
case L2X0_CACHE_ID_PART_L220:
ways = (aux >> 13) & 0xf;
break;
case AURORA_CACHE_ID:
ways = (aux >> 13) & 0xf;
ways = 2 << ((ways + 1) >> 2);
break;
default:
ways = 8;
break;
}
l2x0_way_mask = (1 << ways) - 1;
way_size_bits = (aux & L2C_AUX_CTRL_WAY_SIZE_MASK) >>
L2C_AUX_CTRL_WAY_SIZE_SHIFT;
l2x0_size = ways * (data->way_size_0 << way_size_bits);
fns = data->outer_cache;
fns.write_sec = outer_cache.write_sec;
fns.configure = outer_cache.configure;
if (data->fixup)
data->fixup(l2x0_base, cache_id, &fns);
if (nosync) {
pr_info("L2C: disabling outer sync\n");
fns.sync = NULL;
}
if (!(readl_relaxed(l2x0_base + L2X0_CTRL) & L2X0_CTRL_EN)) {
l2x0_saved_regs.aux_ctrl = aux;
data->enable(l2x0_base, data->num_lock);
}
outer_cache = fns;
if (data->save)
data->save(l2x0_base);
aux = readl_relaxed(l2x0_base + L2X0_AUX_CTRL);
pr_info("%s cache controller enabled, %d ways, %d kB\n",
data->type, ways, l2x0_size >> 10);
pr_info("%s: CACHE_ID 0x%08x, AUX_CTRL 0x%08x\n",
data->type, cache_id, aux);
l2x0_pmu_register(l2x0_base, cache_id);
return 0;
}
void __init l2x0_init(void __iomem *base, u32 aux_val, u32 aux_mask)
{
const struct l2c_init_data *data;
u32 cache_id;
l2x0_base = base;
cache_id = readl_relaxed(base + L2X0_CACHE_ID);
switch (cache_id & L2X0_CACHE_ID_PART_MASK) {
default:
case L2X0_CACHE_ID_PART_L210:
data = &l2c210_data;
break;
case L2X0_CACHE_ID_PART_L220:
data = &l2c220_data;
break;
case L2X0_CACHE_ID_PART_L310:
data = &l2c310_init_fns;
break;
}
if (data->save)
data->save(l2x0_base);
__l2c_init(data, aux_val, aux_mask, cache_id, false);
}
static int __init l2x0_cache_size_of_parse(const struct device_node *np,
u32 *aux_val, u32 *aux_mask,
u32 *associativity,
u32 max_way_size)
{
u32 mask = 0, val = 0;
u32 cache_size = 0, sets = 0;
u32 way_size_bits = 1;
u32 way_size = 0;
u32 block_size = 0;
u32 line_size = 0;
of_property_read_u32(np, "cache-size", &cache_size);
of_property_read_u32(np, "cache-sets", &sets);
of_property_read_u32(np, "cache-block-size", &block_size);
of_property_read_u32(np, "cache-line-size", &line_size);
if (!cache_size || !sets)
return -ENODEV;
if (!line_size) {
if (block_size) {
line_size = block_size;
} else {
pr_warn("L2C OF: no cache block/line size given: "
"falling back to default size %d bytes\n",
CACHE_LINE_SIZE);
line_size = CACHE_LINE_SIZE;
}
}
if (line_size != CACHE_LINE_SIZE)
pr_warn("L2C OF: DT supplied line size %d bytes does "
"not match hardware line size of %d bytes\n",
line_size,
CACHE_LINE_SIZE);
way_size = sets * line_size;
*associativity = cache_size / way_size;
if (way_size > max_way_size) {
pr_err("L2C OF: set size %dKB is too large\n", way_size);
return -EINVAL;
}
pr_info("L2C OF: override cache size: %d bytes (%dKB)\n",
cache_size, cache_size >> 10);
pr_info("L2C OF: override line size: %d bytes\n", line_size);
pr_info("L2C OF: override way size: %d bytes (%dKB)\n",
way_size, way_size >> 10);
pr_info("L2C OF: override associativity: %d\n", *associativity);
way_size_bits = ilog2(way_size >> 10) - 3;
if (way_size_bits < 1 || way_size_bits > 6) {
pr_err("L2C OF: cache way size illegal: %dKB is not mapped\n",
way_size);
return -EINVAL;
}
mask |= L2C_AUX_CTRL_WAY_SIZE_MASK;
val |= (way_size_bits << L2C_AUX_CTRL_WAY_SIZE_SHIFT);
*aux_val &= ~mask;
*aux_val |= val;
*aux_mask &= ~mask;
return 0;
}
static void __init l2x0_of_parse(const struct device_node *np,
u32 *aux_val, u32 *aux_mask)
{
u32 data[2] = { 0, 0 };
u32 tag = 0;
u32 dirty = 0;
u32 val = 0, mask = 0;
u32 assoc;
int ret;
of_property_read_u32(np, "arm,tag-latency", &tag);
if (tag) {
mask |= L2X0_AUX_CTRL_TAG_LATENCY_MASK;
val |= (tag - 1) << L2X0_AUX_CTRL_TAG_LATENCY_SHIFT;
}
of_property_read_u32_array(np, "arm,data-latency",
data, ARRAY_SIZE(data));
if (data[0] && data[1]) {
mask |= L2X0_AUX_CTRL_DATA_RD_LATENCY_MASK |
L2X0_AUX_CTRL_DATA_WR_LATENCY_MASK;
val |= ((data[0] - 1) << L2X0_AUX_CTRL_DATA_RD_LATENCY_SHIFT) |
((data[1] - 1) << L2X0_AUX_CTRL_DATA_WR_LATENCY_SHIFT);
}
of_property_read_u32(np, "arm,dirty-latency", &dirty);
if (dirty) {
mask |= L2X0_AUX_CTRL_DIRTY_LATENCY_MASK;
val |= (dirty - 1) << L2X0_AUX_CTRL_DIRTY_LATENCY_SHIFT;
}
if (of_property_read_bool(np, "arm,parity-enable")) {
mask &= ~L2C_AUX_CTRL_PARITY_ENABLE;
val |= L2C_AUX_CTRL_PARITY_ENABLE;
} else if (of_property_read_bool(np, "arm,parity-disable")) {
mask &= ~L2C_AUX_CTRL_PARITY_ENABLE;
}
if (of_property_read_bool(np, "arm,shared-override")) {
mask &= ~L2C_AUX_CTRL_SHARED_OVERRIDE;
val |= L2C_AUX_CTRL_SHARED_OVERRIDE;
}
ret = l2x0_cache_size_of_parse(np, aux_val, aux_mask, &assoc, SZ_256K);
if (ret)
return;
if (assoc > 8) {
pr_err("l2x0 of: cache setting yield too high associativity\n");
pr_err("l2x0 of: %d calculated, max 8\n", assoc);
} else {
mask |= L2X0_AUX_CTRL_ASSOC_MASK;
val |= (assoc << L2X0_AUX_CTRL_ASSOC_SHIFT);
}
*aux_val &= ~mask;
*aux_val |= val;
*aux_mask &= ~mask;
}
static void __init l2c310_of_parse(const struct device_node *np,
u32 *aux_val, u32 *aux_mask)
{
u32 data[3] = { 0, 0, 0 };
u32 tag[3] = { 0, 0, 0 };
u32 filter[2] = { 0, 0 };
u32 assoc;
u32 prefetch;
u32 power;
u32 val;
int ret;
of_property_read_u32_array(np, "arm,tag-latency", tag, ARRAY_SIZE(tag));
if (tag[0] && tag[1] && tag[2])
l2x0_saved_regs.tag_latency =
L310_LATENCY_CTRL_RD(tag[0] - 1) |
L310_LATENCY_CTRL_WR(tag[1] - 1) |
L310_LATENCY_CTRL_SETUP(tag[2] - 1);
of_property_read_u32_array(np, "arm,data-latency",
data, ARRAY_SIZE(data));
if (data[0] && data[1] && data[2])
l2x0_saved_regs.data_latency =
L310_LATENCY_CTRL_RD(data[0] - 1) |
L310_LATENCY_CTRL_WR(data[1] - 1) |
L310_LATENCY_CTRL_SETUP(data[2] - 1);
of_property_read_u32_array(np, "arm,filter-ranges",
filter, ARRAY_SIZE(filter));
if (filter[1]) {
l2x0_saved_regs.filter_end =
ALIGN(filter[0] + filter[1], SZ_1M);
l2x0_saved_regs.filter_start = (filter[0] & ~(SZ_1M - 1))
| L310_ADDR_FILTER_EN;
}
ret = l2x0_cache_size_of_parse(np, aux_val, aux_mask, &assoc, SZ_512K);
if (!ret) {
switch (assoc) {
case 16:
*aux_val &= ~L2X0_AUX_CTRL_ASSOC_MASK;
*aux_val |= L310_AUX_CTRL_ASSOCIATIVITY_16;
*aux_mask &= ~L2X0_AUX_CTRL_ASSOC_MASK;
break;
case 8:
*aux_val &= ~L2X0_AUX_CTRL_ASSOC_MASK;
*aux_mask &= ~L2X0_AUX_CTRL_ASSOC_MASK;
break;
default:
pr_err("L2C-310 OF cache associativity %d invalid, only 8 or 16 permitted\n",
assoc);
break;
}
}
if (of_property_read_bool(np, "arm,shared-override")) {
*aux_val |= L2C_AUX_CTRL_SHARED_OVERRIDE;
*aux_mask &= ~L2C_AUX_CTRL_SHARED_OVERRIDE;
}
if (of_property_read_bool(np, "arm,parity-enable")) {
*aux_val |= L2C_AUX_CTRL_PARITY_ENABLE;
*aux_mask &= ~L2C_AUX_CTRL_PARITY_ENABLE;
} else if (of_property_read_bool(np, "arm,parity-disable")) {
*aux_val &= ~L2C_AUX_CTRL_PARITY_ENABLE;
*aux_mask &= ~L2C_AUX_CTRL_PARITY_ENABLE;
}
if (of_property_read_bool(np, "arm,early-bresp-disable"))
l2x0_bresp_disable = true;
if (of_property_read_bool(np, "arm,full-line-zero-disable"))
l2x0_flz_disable = true;
prefetch = l2x0_saved_regs.prefetch_ctrl;
ret = of_property_read_u32(np, "arm,double-linefill", &val);
if (ret == 0) {
if (val)
prefetch |= L310_PREFETCH_CTRL_DBL_LINEFILL;
else
prefetch &= ~L310_PREFETCH_CTRL_DBL_LINEFILL;
} else if (ret != -EINVAL) {
pr_err("L2C-310 OF arm,double-linefill property value is missing\n");
}
ret = of_property_read_u32(np, "arm,double-linefill-incr", &val);
if (ret == 0) {
if (val)
prefetch |= L310_PREFETCH_CTRL_DBL_LINEFILL_INCR;
else
prefetch &= ~L310_PREFETCH_CTRL_DBL_LINEFILL_INCR;
} else if (ret != -EINVAL) {
pr_err("L2C-310 OF arm,double-linefill-incr property value is missing\n");
}
ret = of_property_read_u32(np, "arm,double-linefill-wrap", &val);
if (ret == 0) {
if (!val)
prefetch |= L310_PREFETCH_CTRL_DBL_LINEFILL_WRAP;
else
prefetch &= ~L310_PREFETCH_CTRL_DBL_LINEFILL_WRAP;
} else if (ret != -EINVAL) {
pr_err("L2C-310 OF arm,double-linefill-wrap property value is missing\n");
}
ret = of_property_read_u32(np, "arm,prefetch-drop", &val);
if (ret == 0) {
if (val)
prefetch |= L310_PREFETCH_CTRL_PREFETCH_DROP;
else
prefetch &= ~L310_PREFETCH_CTRL_PREFETCH_DROP;
} else if (ret != -EINVAL) {
pr_err("L2C-310 OF arm,prefetch-drop property value is missing\n");
}
ret = of_property_read_u32(np, "arm,prefetch-offset", &val);
if (ret == 0) {
prefetch &= ~L310_PREFETCH_CTRL_OFFSET_MASK;
prefetch |= val & L310_PREFETCH_CTRL_OFFSET_MASK;
} else if (ret != -EINVAL) {
pr_err("L2C-310 OF arm,prefetch-offset property value is missing\n");
}
ret = of_property_read_u32(np, "prefetch-data", &val);
if (ret == 0) {
if (val)
prefetch |= L310_PREFETCH_CTRL_DATA_PREFETCH;
else
prefetch &= ~L310_PREFETCH_CTRL_DATA_PREFETCH;
} else if (ret != -EINVAL) {
pr_err("L2C-310 OF prefetch-data property value is missing\n");
}
ret = of_property_read_u32(np, "prefetch-instr", &val);
if (ret == 0) {
if (val)
prefetch |= L310_PREFETCH_CTRL_INSTR_PREFETCH;
else
prefetch &= ~L310_PREFETCH_CTRL_INSTR_PREFETCH;
} else if (ret != -EINVAL) {
pr_err("L2C-310 OF prefetch-instr property value is missing\n");
}
l2x0_saved_regs.prefetch_ctrl = prefetch;
power = l2x0_saved_regs.pwr_ctrl |
L310_DYNAMIC_CLK_GATING_EN | L310_STNDBY_MODE_EN;
ret = of_property_read_u32(np, "arm,dynamic-clock-gating", &val);
if (!ret) {
if (!val)
power &= ~L310_DYNAMIC_CLK_GATING_EN;
} else if (ret != -EINVAL) {
pr_err("L2C-310 OF dynamic-clock-gating property value is missing or invalid\n");
}
ret = of_property_read_u32(np, "arm,standby-mode", &val);
if (!ret) {
if (!val)
power &= ~L310_STNDBY_MODE_EN;
} else if (ret != -EINVAL) {
pr_err("L2C-310 OF standby-mode property value is missing or invalid\n");
}
l2x0_saved_regs.pwr_ctrl = power;
}
static unsigned long aurora_range_end(unsigned long start, unsigned long end)
{
if (end > start + MAX_RANGE_SIZE)
end = start + MAX_RANGE_SIZE;
if (end > PAGE_ALIGN(start+1))
end = PAGE_ALIGN(start+1);
return end;
}
static void aurora_pa_range(unsigned long start, unsigned long end,
unsigned long offset)
{
void __iomem *base = l2x0_base;
unsigned long range_end;
unsigned long flags;
start &= ~(CACHE_LINE_SIZE - 1);
end = ALIGN(end, CACHE_LINE_SIZE);
while (start < end) {
range_end = aurora_range_end(start, end);
raw_spin_lock_irqsave(&l2x0_lock, flags);
writel_relaxed(start, base + AURORA_RANGE_BASE_ADDR_REG);
writel_relaxed(range_end - CACHE_LINE_SIZE, base + offset);
raw_spin_unlock_irqrestore(&l2x0_lock, flags);
writel_relaxed(0, base + AURORA_SYNC_REG);
start = range_end;
}
}
static void aurora_inv_range(unsigned long start, unsigned long end)
{
aurora_pa_range(start, end, AURORA_INVAL_RANGE_REG);
}
static void aurora_clean_range(unsigned long start, unsigned long end)
{
if (!l2_wt_override)
aurora_pa_range(start, end, AURORA_CLEAN_RANGE_REG);
}
static void aurora_flush_range(unsigned long start, unsigned long end)
{
if (l2_wt_override)
aurora_pa_range(start, end, AURORA_INVAL_RANGE_REG);
else
aurora_pa_range(start, end, AURORA_FLUSH_RANGE_REG);
}
static void aurora_flush_all(void)
{
void __iomem *base = l2x0_base;
unsigned long flags;
raw_spin_lock_irqsave(&l2x0_lock, flags);
__l2c_op_way(base + L2X0_CLEAN_INV_WAY);
raw_spin_unlock_irqrestore(&l2x0_lock, flags);
writel_relaxed(0, base + AURORA_SYNC_REG);
}
static void aurora_cache_sync(void)
{
writel_relaxed(0, l2x0_base + AURORA_SYNC_REG);
}
static void aurora_disable(void)
{
void __iomem *base = l2x0_base;
unsigned long flags;
raw_spin_lock_irqsave(&l2x0_lock, flags);
__l2c_op_way(base + L2X0_CLEAN_INV_WAY);
writel_relaxed(0, base + AURORA_SYNC_REG);
l2c_write_sec(0, base, L2X0_CTRL);
dsb(st);
raw_spin_unlock_irqrestore(&l2x0_lock, flags);
}
static void aurora_save(void __iomem *base)
{
l2x0_saved_regs.ctrl = readl_relaxed(base + L2X0_CTRL);
l2x0_saved_regs.aux_ctrl = readl_relaxed(base + L2X0_AUX_CTRL);
}
static void __init aurora_enable_no_outer(void __iomem *base,
unsigned num_lock)
{
u32 u;
asm volatile("mrc p15, 1, %0, c15, c2, 0" : "=r" (u));
u |= AURORA_CTRL_FW;
asm volatile("mcr p15, 1, %0, c15, c2, 0" : : "r" (u));
isb();
l2c_enable(base, num_lock);
}
static void __init aurora_fixup(void __iomem *base, u32 cache_id,
struct outer_cache_fns *fns)
{
sync_reg_offset = AURORA_SYNC_REG;
}
static void __init aurora_of_parse(const struct device_node *np,
u32 *aux_val, u32 *aux_mask)
{
u32 val = AURORA_ACR_REPLACEMENT_TYPE_SEMIPLRU;
u32 mask = AURORA_ACR_REPLACEMENT_MASK;
of_property_read_u32(np, "cache-id-part",
&cache_id_part_number_from_dt);
l2_wt_override = of_property_read_bool(np, "wt-override");
if (l2_wt_override) {
val |= AURORA_ACR_FORCE_WRITE_THRO_POLICY;
mask |= AURORA_ACR_FORCE_WRITE_POLICY_MASK;
}
*aux_val &= ~mask;
*aux_val |= val;
*aux_mask &= ~mask;
}
static inline int bcm_addr_is_sys_emi(unsigned long addr)
{
return (addr >= BCM_SYS_EMI_START_ADDR) &&
(addr < BCM_VC_EMI_SEC3_START_ADDR);
}
static inline unsigned long bcm_l2_phys_addr(unsigned long addr)
{
if (bcm_addr_is_sys_emi(addr))
return addr + BCM_SYS_EMI_OFFSET;
else
return addr + BCM_VC_EMI_OFFSET;
}
static void bcm_inv_range(unsigned long start, unsigned long end)
{
unsigned long new_start, new_end;
BUG_ON(start < BCM_SYS_EMI_START_ADDR);
if (unlikely(end <= start))
return;
new_start = bcm_l2_phys_addr(start);
new_end = bcm_l2_phys_addr(end);
if (likely(bcm_addr_is_sys_emi(end) || !bcm_addr_is_sys_emi(start))) {
l2c210_inv_range(new_start, new_end);
return;
}
l2c210_inv_range(new_start,
bcm_l2_phys_addr(BCM_VC_EMI_SEC3_START_ADDR-1));
l2c210_inv_range(bcm_l2_phys_addr(BCM_VC_EMI_SEC3_START_ADDR),
new_end);
}
static void bcm_clean_range(unsigned long start, unsigned long end)
{
unsigned long new_start, new_end;
BUG_ON(start < BCM_SYS_EMI_START_ADDR);
if (unlikely(end <= start))
return;
new_start = bcm_l2_phys_addr(start);
new_end = bcm_l2_phys_addr(end);
if (likely(bcm_addr_is_sys_emi(end) || !bcm_addr_is_sys_emi(start))) {
l2c210_clean_range(new_start, new_end);
return;
}
l2c210_clean_range(new_start,
bcm_l2_phys_addr(BCM_VC_EMI_SEC3_START_ADDR-1));
l2c210_clean_range(bcm_l2_phys_addr(BCM_VC_EMI_SEC3_START_ADDR),
new_end);
}
static void bcm_flush_range(unsigned long start, unsigned long end)
{
unsigned long new_start, new_end;
BUG_ON(start < BCM_SYS_EMI_START_ADDR);
if (unlikely(end <= start))
return;
if ((end - start) >= l2x0_size) {
outer_cache.flush_all();
return;
}
new_start = bcm_l2_phys_addr(start);
new_end = bcm_l2_phys_addr(end);
if (likely(bcm_addr_is_sys_emi(end) || !bcm_addr_is_sys_emi(start))) {
l2c210_flush_range(new_start, new_end);
return;
}
l2c210_flush_range(new_start,
bcm_l2_phys_addr(BCM_VC_EMI_SEC3_START_ADDR-1));
l2c210_flush_range(bcm_l2_phys_addr(BCM_VC_EMI_SEC3_START_ADDR),
new_end);
}
static void __init tauros3_save(void __iomem *base)
{
l2c_save(base);
l2x0_saved_regs.aux2_ctrl =
readl_relaxed(base + TAUROS3_AUX2_CTRL);
l2x0_saved_regs.prefetch_ctrl =
readl_relaxed(base + L310_PREFETCH_CTRL);
}
static void tauros3_configure(void __iomem *base)
{
l2c_configure(base);
writel_relaxed(l2x0_saved_regs.aux2_ctrl,
base + TAUROS3_AUX2_CTRL);
writel_relaxed(l2x0_saved_regs.prefetch_ctrl,
base + L310_PREFETCH_CTRL);
}
int __init l2x0_of_init(u32 aux_val, u32 aux_mask)
{
const struct l2c_init_data *data;
struct device_node *np;
struct resource res;
u32 cache_id, old_aux;
u32 cache_level = 2;
bool nosync = false;
np = of_find_matching_node(NULL, l2x0_ids);
if (!np)
return -ENODEV;
if (of_address_to_resource(np, 0, &res))
return -ENODEV;
l2x0_base = ioremap(res.start, resource_size(&res));
if (!l2x0_base)
return -ENOMEM;
l2x0_saved_regs.phy_base = res.start;
data = of_match_node(l2x0_ids, np)->data;
if (of_device_is_compatible(np, "arm,pl310-cache") &&
of_property_read_bool(np, "arm,io-coherent"))
data = &of_l2c310_coherent_data;
old_aux = readl_relaxed(l2x0_base + L2X0_AUX_CTRL);
if (old_aux != ((old_aux & aux_mask) | aux_val)) {
pr_warn("L2C: platform modifies aux control register: 0x%08x -> 0x%08x\n",
old_aux, (old_aux & aux_mask) | aux_val);
} else if (aux_mask != ~0U && aux_val != 0) {
pr_alert("L2C: platform provided aux values match the hardware, so have no effect. Please remove them.\n");
}
if (!of_property_read_bool(np, "cache-unified"))
pr_err("L2C: device tree omits to specify unified cache\n");
if (of_property_read_u32(np, "cache-level", &cache_level))
pr_err("L2C: device tree omits to specify cache-level\n");
if (cache_level != 2)
pr_err("L2C: device tree specifies invalid cache level\n");
nosync = of_property_read_bool(np, "arm,outer-sync-disable");
if (data->save)
data->save(l2x0_base);
if (!(readl_relaxed(l2x0_base + L2X0_CTRL) & L2X0_CTRL_EN))
if (data->of_parse)
data->of_parse(np, &aux_val, &aux_mask);
if (cache_id_part_number_from_dt)
cache_id = cache_id_part_number_from_dt;
else
cache_id = readl_relaxed(l2x0_base + L2X0_CACHE_ID);
return __l2c_init(data, aux_val, aux_mask, cache_id, nosync);
}
