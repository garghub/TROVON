static inline void __hmatrix_write_reg(unsigned long offset, u32 value)
{
__raw_writel(value, (void __iomem __force *)(HMATRIX_BASE + offset));
}
static inline u32 __hmatrix_read_reg(unsigned long offset)
{
return __raw_readl((void __iomem __force *)(HMATRIX_BASE + offset));
}
void hmatrix_write_reg(unsigned long offset, u32 value)
{
clk_enable(&at32_hmatrix_clk);
__hmatrix_write_reg(offset, value);
__hmatrix_read_reg(offset);
clk_disable(&at32_hmatrix_clk);
}
u32 hmatrix_read_reg(unsigned long offset)
{
u32 value;
clk_enable(&at32_hmatrix_clk);
value = __hmatrix_read_reg(offset);
clk_disable(&at32_hmatrix_clk);
return value;
}
void hmatrix_sfr_set_bits(unsigned int slave_id, u32 mask)
{
u32 value;
clk_enable(&at32_hmatrix_clk);
value = __hmatrix_read_reg(HMATRIX_SFR(slave_id));
value |= mask;
__hmatrix_write_reg(HMATRIX_SFR(slave_id), value);
__hmatrix_read_reg(HMATRIX_SFR(slave_id));
clk_disable(&at32_hmatrix_clk);
}
void hmatrix_sfr_clear_bits(unsigned int slave_id, u32 mask)
{
u32 value;
clk_enable(&at32_hmatrix_clk);
value = __hmatrix_read_reg(HMATRIX_SFR(slave_id));
value &= ~mask;
__hmatrix_write_reg(HMATRIX_SFR(slave_id), value);
__hmatrix_read_reg(HMATRIX_SFR(slave_id));
clk_disable(&at32_hmatrix_clk);
}
