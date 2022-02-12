static int zynq_slcr_write(u32 val, u32 offset)
{
if (!zynq_slcr_regmap) {
writel(val, zynq_slcr_base + offset);
return 0;
}
return regmap_write(zynq_slcr_regmap, offset, val);
}
static int zynq_slcr_read(u32 *val, u32 offset)
{
if (zynq_slcr_regmap)
return regmap_read(zynq_slcr_regmap, offset, val);
*val = readl(zynq_slcr_base + offset);
return 0;
}
static inline int zynq_slcr_unlock(void)
{
zynq_slcr_write(SLCR_UNLOCK_MAGIC, SLCR_UNLOCK_OFFSET);
return 0;
}
u32 zynq_slcr_get_device_id(void)
{
u32 val;
zynq_slcr_read(&val, SLCR_PSS_IDCODE);
val >>= SLCR_PSS_IDCODE_DEVICE_SHIFT;
val &= SLCR_PSS_IDCODE_DEVICE_MASK;
return val;
}
void zynq_slcr_system_reset(void)
{
u32 reboot;
zynq_slcr_unlock();
zynq_slcr_read(&reboot, SLCR_REBOOT_STATUS_OFFSET);
zynq_slcr_write(reboot & 0xF0FFFFFF, SLCR_REBOOT_STATUS_OFFSET);
zynq_slcr_write(1, SLCR_PS_RST_CTRL_OFFSET);
}
void zynq_slcr_cpu_start(int cpu)
{
u32 reg;
zynq_slcr_read(&reg, SLCR_A9_CPU_RST_CTRL_OFFSET);
reg &= ~(SLCR_A9_CPU_RST << cpu);
zynq_slcr_write(reg, SLCR_A9_CPU_RST_CTRL_OFFSET);
reg &= ~(SLCR_A9_CPU_CLKSTOP << cpu);
zynq_slcr_write(reg, SLCR_A9_CPU_RST_CTRL_OFFSET);
zynq_slcr_cpu_state_write(cpu, false);
}
void zynq_slcr_cpu_stop(int cpu)
{
u32 reg;
zynq_slcr_read(&reg, SLCR_A9_CPU_RST_CTRL_OFFSET);
reg |= (SLCR_A9_CPU_CLKSTOP | SLCR_A9_CPU_RST) << cpu;
zynq_slcr_write(reg, SLCR_A9_CPU_RST_CTRL_OFFSET);
}
bool zynq_slcr_cpu_state_read(int cpu)
{
u32 state;
state = readl(zynq_slcr_base + SLCR_REBOOT_STATUS_OFFSET);
state &= 1 << (31 - cpu);
return !state;
}
void zynq_slcr_cpu_state_write(int cpu, bool die)
{
u32 state, mask;
state = readl(zynq_slcr_base + SLCR_REBOOT_STATUS_OFFSET);
mask = 1 << (31 - cpu);
if (die)
state |= mask;
else
state &= ~mask;
writel(state, zynq_slcr_base + SLCR_REBOOT_STATUS_OFFSET);
}
int __init zynq_slcr_init(void)
{
zynq_slcr_regmap = syscon_regmap_lookup_by_compatible("xlnx,zynq-slcr");
if (IS_ERR(zynq_slcr_regmap)) {
pr_err("%s: failed to find zynq-slcr\n", __func__);
return -ENODEV;
}
return 0;
}
int __init zynq_early_slcr_init(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "xlnx,zynq-slcr");
if (!np) {
pr_err("%s: no slcr node found\n", __func__);
BUG();
}
zynq_slcr_base = of_iomap(np, 0);
if (!zynq_slcr_base) {
pr_err("%s: Unable to map I/O memory\n", __func__);
BUG();
}
np->data = (__force void *)zynq_slcr_base;
zynq_slcr_unlock();
pr_info("%s mapped to %p\n", np->name, zynq_slcr_base);
of_node_put(np);
return 0;
}
