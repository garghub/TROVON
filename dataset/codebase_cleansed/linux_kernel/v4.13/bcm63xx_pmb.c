static int bpcm_wr_rd_mask(void __iomem *master,
unsigned int addr, u32 off, u32 *val,
u32 shift, u32 mask, u32 cond)
{
int ret;
ret = bpcm_wr(master, addr, off, *val);
if (ret)
return ret;
do {
ret = bpcm_rd(master, addr, off, val);
if (ret)
return ret;
cpu_relax();
} while (((*val >> shift) & mask) != cond);
return ret;
}
static int bcm63xx_pmb_get_resources(struct device_node *dn,
void __iomem **base,
unsigned int *cpu,
unsigned int *addr)
{
struct of_phandle_args args;
int ret;
ret = of_property_read_u32(dn, "reg", cpu);
if (ret) {
pr_err("CPU is missing a reg node\n");
return ret;
}
ret = of_parse_phandle_with_args(dn, "resets", "#reset-cells",
0, &args);
if (ret) {
pr_err("CPU is missing a resets phandle\n");
return ret;
}
if (args.args_count != 2) {
pr_err("reset-controller does not conform to reset-cells\n");
return -EINVAL;
}
*base = of_iomap(args.np, 0);
if (!*base) {
pr_err("failed remapping PMB register\n");
return -ENOMEM;
}
*addr = args.args[0];
return 0;
}
int bcm63xx_pmb_power_on_cpu(struct device_node *dn)
{
void __iomem *base;
unsigned int cpu, addr;
unsigned long flags;
u32 val, ctrl;
int ret;
ret = bcm63xx_pmb_get_resources(dn, &base, &cpu, &addr);
if (ret)
return ret;
WARN_ON(cpu > 1);
spin_lock_irqsave(&pmb_lock, flags);
ret = bpcm_rd(base, addr, ARM_CONTROL, &ctrl);
if (ret)
goto out;
if (ctrl & CPU_RESET_N(cpu)) {
pr_info("PMB: CPU%d is already powered on\n", cpu);
ret = 0;
goto out;
}
ret = bpcm_rd(base, addr, ARM_PWR_CONTROL(cpu), &val);
if (ret)
goto out;
val |= (PWR_CPU_MASK << PWR_ON_SHIFT);
ret = bpcm_wr_rd_mask(base, addr, ARM_PWR_CONTROL(cpu), &val,
PWR_ON_STATUS_SHIFT, PWR_CPU_MASK, PWR_CPU_MASK);
if (ret)
goto out;
val |= (PWR_CPU_MASK << PWR_OK_SHIFT);
ret = bpcm_wr_rd_mask(base, addr, ARM_PWR_CONTROL(cpu), &val,
PWR_OK_STATUS_SHIFT, PWR_CPU_MASK, PWR_CPU_MASK);
if (ret)
goto out;
val &= ~CLAMP_ON;
ret = bpcm_wr(base, addr, ARM_PWR_CONTROL(cpu), val);
if (ret)
goto out;
val &= ~(MEM_PDA_MASK << MEM_PDA_SHIFT);
ret = bpcm_wr(base, addr, ARM_PWR_CONTROL(cpu), val);
if (ret)
goto out;
val |= MEM_PWR_ON;
ret = bpcm_wr_rd_mask(base, addr, ARM_PWR_CONTROL(cpu), &val,
0, MEM_PWR_ON_STATUS, MEM_PWR_ON_STATUS);
if (ret)
goto out;
val |= MEM_PWR_OK;
ret = bpcm_wr_rd_mask(base, addr, ARM_PWR_CONTROL(cpu), &val,
0, MEM_PWR_OK_STATUS, MEM_PWR_OK_STATUS);
if (ret)
goto out;
val &= ~MEM_CLAMP_ON;
ret = bpcm_wr(base, addr, ARM_PWR_CONTROL(cpu), val);
if (ret)
goto out;
ctrl |= CPU_RESET_N(cpu);
ret = bpcm_wr(base, addr, ARM_CONTROL, ctrl);
out:
spin_unlock_irqrestore(&pmb_lock, flags);
iounmap(base);
return ret;
}
