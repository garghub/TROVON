static unsigned int u2o_read(unsigned int base, unsigned int offset)
{
return readl(base + offset);
}
static void u2o_set(unsigned int base, unsigned int offset, unsigned int value)
{
unsigned int reg;
reg = readl(base + offset);
reg |= value;
writel(reg, base + offset);
readl(base + offset);
}
static void u2o_clear(unsigned int base, unsigned int offset,
unsigned int value)
{
unsigned int reg;
reg = readl(base + offset);
reg &= ~value;
writel(reg, base + offset);
readl(base + offset);
}
static void u2o_write(unsigned int base, unsigned int offset,
unsigned int value)
{
writel(value, base + offset);
readl(base + offset);
}
int mv_udc_phy_init(unsigned int base)
{
unsigned long timeout;
if (cpu_is_pxa910()) {
u2o_set(base, UTMI_CTRL, (1 << UTMI_CTRL_INPKT_DELAY_SOF_SHIFT)
| (1 << UTMI_CTRL_PU_REF_SHIFT));
}
u2o_set(base, UTMI_CTRL, 1 << UTMI_CTRL_PLL_PWR_UP_SHIFT);
u2o_set(base, UTMI_CTRL, 1 << UTMI_CTRL_PWR_UP_SHIFT);
u2o_clear(base, UTMI_PLL, UTMI_PLL_PLLVDD18_MASK
| UTMI_PLL_PLLVDD12_MASK | UTMI_PLL_PLLCALI12_MASK
| UTMI_PLL_FBDIV_MASK | UTMI_PLL_REFDIV_MASK
| UTMI_PLL_ICP_MASK | UTMI_PLL_KVCO_MASK);
u2o_set(base, UTMI_PLL, (0xee << UTMI_PLL_FBDIV_SHIFT)
| (0xb << UTMI_PLL_REFDIV_SHIFT)
| (3 << UTMI_PLL_PLLVDD18_SHIFT)
| (3 << UTMI_PLL_PLLVDD12_SHIFT)
| (3 << UTMI_PLL_PLLCALI12_SHIFT)
| (1 << UTMI_PLL_ICP_SHIFT) | (3 << UTMI_PLL_KVCO_SHIFT));
u2o_clear(base, UTMI_TX, UTMI_TX_REG_EXT_FS_RCAL_EN_MASK
| UTMI_TX_TXVDD12_MASK
| UTMI_TX_CK60_PHSEL_MASK | UTMI_TX_IMPCAL_VTH_MASK
| UTMI_TX_REG_EXT_FS_RCAL_MASK | UTMI_TX_AMP_MASK);
u2o_set(base, UTMI_TX, (3 << UTMI_TX_TXVDD12_SHIFT)
| (4 << UTMI_TX_CK60_PHSEL_SHIFT)
| (4 << UTMI_TX_IMPCAL_VTH_SHIFT)
| (8 << UTMI_TX_REG_EXT_FS_RCAL_SHIFT)
| (3 << UTMI_TX_AMP_SHIFT));
u2o_clear(base, UTMI_RX, UTMI_RX_SQ_THRESH_MASK
| UTMI_REG_SQ_LENGTH_MASK);
if (cpu_is_pxa168())
u2o_set(base, UTMI_RX, (7 << UTMI_RX_SQ_THRESH_SHIFT)
| (2 << UTMI_REG_SQ_LENGTH_SHIFT));
else
u2o_set(base, UTMI_RX, (0x7 << UTMI_RX_SQ_THRESH_SHIFT)
| (2 << UTMI_REG_SQ_LENGTH_SHIFT));
if (cpu_is_pxa168())
u2o_write(base, UTMI_IVREF, 0x4bf);
timeout = jiffies + 100;
while ((u2o_read(base, UTMI_PLL) & PLL_READY) == 0) {
if (time_after(jiffies, timeout))
return -ETIME;
cpu_relax();
}
udelay(200);
u2o_set(base, UTMI_PLL, VCOCAL_START);
udelay(40);
u2o_clear(base, UTMI_PLL, VCOCAL_START);
udelay(200);
u2o_set(base, UTMI_TX, REG_RCAL_START);
udelay(40);
u2o_clear(base, UTMI_TX, REG_RCAL_START);
udelay(200);
timeout = jiffies + 100;
while ((u2o_read(base, UTMI_PLL) & PLL_READY) == 0) {
if (time_after(jiffies, timeout))
return -ETIME;
cpu_relax();
}
if (cpu_is_pxa168()) {
u2o_set(base, UTMI_RESERVE, 1 << 5);
u2o_write(base, UTMI_OTG_ADDON, 1);
}
return 0;
}
int mv_udc_phy_init(unsigned int base)
{
return 0;
}
