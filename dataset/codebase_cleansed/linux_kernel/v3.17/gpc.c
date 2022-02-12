void imx_gpc_pre_suspend(bool arm_power_off)
{
void __iomem *reg_imr1 = gpc_base + GPC_IMR1;
int i;
if (arm_power_off)
writel_relaxed(0x1, gpc_base + GPC_PGC_CPU_PDN);
for (i = 0; i < IMR_NUM; i++) {
gpc_saved_imrs[i] = readl_relaxed(reg_imr1 + i * 4);
writel_relaxed(~gpc_wake_irqs[i], reg_imr1 + i * 4);
}
}
void imx_gpc_post_resume(void)
{
void __iomem *reg_imr1 = gpc_base + GPC_IMR1;
int i;
writel_relaxed(0x0, gpc_base + GPC_PGC_CPU_PDN);
for (i = 0; i < IMR_NUM; i++)
writel_relaxed(gpc_saved_imrs[i], reg_imr1 + i * 4);
}
static int imx_gpc_irq_set_wake(struct irq_data *d, unsigned int on)
{
unsigned int idx = d->irq / 32 - 1;
u32 mask;
if (d->irq < 32)
return -EINVAL;
mask = 1 << d->irq % 32;
gpc_wake_irqs[idx] = on ? gpc_wake_irqs[idx] | mask :
gpc_wake_irqs[idx] & ~mask;
return 0;
}
void imx_gpc_mask_all(void)
{
void __iomem *reg_imr1 = gpc_base + GPC_IMR1;
int i;
for (i = 0; i < IMR_NUM; i++) {
gpc_saved_imrs[i] = readl_relaxed(reg_imr1 + i * 4);
writel_relaxed(~0, reg_imr1 + i * 4);
}
}
void imx_gpc_restore_all(void)
{
void __iomem *reg_imr1 = gpc_base + GPC_IMR1;
int i;
for (i = 0; i < IMR_NUM; i++)
writel_relaxed(gpc_saved_imrs[i], reg_imr1 + i * 4);
}
void imx_gpc_irq_unmask(struct irq_data *d)
{
void __iomem *reg;
u32 val;
if (d->irq < 32)
return;
reg = gpc_base + GPC_IMR1 + (d->irq / 32 - 1) * 4;
val = readl_relaxed(reg);
val &= ~(1 << d->irq % 32);
writel_relaxed(val, reg);
}
void imx_gpc_irq_mask(struct irq_data *d)
{
void __iomem *reg;
u32 val;
if (d->irq < 32)
return;
reg = gpc_base + GPC_IMR1 + (d->irq / 32 - 1) * 4;
val = readl_relaxed(reg);
val |= 1 << (d->irq % 32);
writel_relaxed(val, reg);
}
void __init imx_gpc_init(void)
{
struct device_node *np;
int i;
np = of_find_compatible_node(NULL, NULL, "fsl,imx6q-gpc");
gpc_base = of_iomap(np, 0);
WARN_ON(!gpc_base);
for (i = 0; i < IMR_NUM; i++)
writel_relaxed(~0, gpc_base + GPC_IMR1 + i * 4);
gic_arch_extn.irq_mask = imx_gpc_irq_mask;
gic_arch_extn.irq_unmask = imx_gpc_irq_unmask;
gic_arch_extn.irq_set_wake = imx_gpc_irq_set_wake;
}
