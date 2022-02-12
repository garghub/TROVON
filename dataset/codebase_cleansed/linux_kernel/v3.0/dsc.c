int s3c2440_set_dsc(unsigned int pin, unsigned int value)
{
void __iomem *base;
unsigned long val;
unsigned long flags;
unsigned long mask;
base = (pin & S3C2440_SELECT_DSC1) ? S3C2440_DSC1 : S3C2440_DSC0;
mask = 3 << S3C2440_DSC_GETSHIFT(pin);
local_irq_save(flags);
val = __raw_readl(base);
val &= ~mask;
val |= value & mask;
__raw_writel(val, base);
local_irq_restore(flags);
return 0;
}
