static inline void __enable_block(int block)
{
void __iomem *base = (void __iomem *)VSS_ADDR(block);
__raw_writel(3, base + VSS_CLKRST);
wmb();
__raw_writel(0x01fffffe, base + VSS_GATE);
wmb();
__raw_writel(0x01, base + VSS_FTR);
wmb();
__raw_writel(0x03, base + VSS_FTR);
wmb();
__raw_writel(0x07, base + VSS_FTR);
wmb();
__raw_writel(0x0f, base + VSS_FTR);
wmb();
__raw_writel(0x01ffffff, base + VSS_GATE);
wmb();
__raw_writel(2, base + VSS_CLKRST);
wmb();
__raw_writel(0x1f, base + VSS_FTR);
wmb();
}
static inline void __disable_block(int block)
{
void __iomem *base = (void __iomem *)VSS_ADDR(block);
__raw_writel(0x0f, base + VSS_FTR);
wmb();
__raw_writel(0, base + VSS_GATE);
wmb();
__raw_writel(3, base + VSS_CLKRST);
wmb();
__raw_writel(1, base + VSS_CLKRST);
wmb();
__raw_writel(0, base + VSS_FTR);
wmb();
}
void au1300_vss_block_control(int block, int enable)
{
unsigned long flags;
if (alchemy_get_cputype() != ALCHEMY_CPU_AU1300)
return;
spin_lock_irqsave(&au1300_vss_lock, flags);
if (enable)
__enable_block(block);
else
__disable_block(block);
spin_unlock_irqrestore(&au1300_vss_lock, flags);
}
