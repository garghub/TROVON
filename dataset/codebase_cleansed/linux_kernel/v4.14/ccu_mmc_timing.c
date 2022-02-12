int sunxi_ccu_set_mmc_timing_mode(struct clk *clk, bool new_mode)
{
struct clk_hw *hw = __clk_get_hw(clk);
struct ccu_common *cm = hw_to_ccu_common(hw);
unsigned long flags;
u32 val;
if (!(cm->features & CCU_FEATURE_MMC_TIMING_SWITCH))
return -ENOTSUPP;
spin_lock_irqsave(cm->lock, flags);
val = readl(cm->base + cm->reg);
if (new_mode)
val |= CCU_MMC_NEW_TIMING_MODE;
else
val &= ~CCU_MMC_NEW_TIMING_MODE;
writel(val, cm->base + cm->reg);
spin_unlock_irqrestore(cm->lock, flags);
return 0;
}
int sunxi_ccu_get_mmc_timing_mode(struct clk *clk)
{
struct clk_hw *hw = __clk_get_hw(clk);
struct ccu_common *cm = hw_to_ccu_common(hw);
if (!(cm->features & CCU_FEATURE_MMC_TIMING_SWITCH))
return -ENOTSUPP;
return !!(readl(cm->base + cm->reg) & CCU_MMC_NEW_TIMING_MODE);
}
