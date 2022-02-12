static int exynos4210_rate_to_clk(unsigned long rate, u32 *reg)
{
switch (rate) {
case 12 * MHZ:
*reg = EXYNOS_4210_UPHYCLK_PHYFSEL_12MHZ;
break;
case 24 * MHZ:
*reg = EXYNOS_4210_UPHYCLK_PHYFSEL_24MHZ;
break;
case 48 * MHZ:
*reg = EXYNOS_4210_UPHYCLK_PHYFSEL_48MHZ;
break;
default:
return -EINVAL;
}
return 0;
}
static void exynos4210_isol(struct samsung_usb2_phy_instance *inst, bool on)
{
struct samsung_usb2_phy_driver *drv = inst->drv;
u32 offset;
u32 mask;
switch (inst->cfg->id) {
case EXYNOS4210_DEVICE:
offset = EXYNOS_4210_USB_ISOL_DEVICE_OFFSET;
mask = EXYNOS_4210_USB_ISOL_DEVICE;
break;
case EXYNOS4210_HOST:
offset = EXYNOS_4210_USB_ISOL_HOST_OFFSET;
mask = EXYNOS_4210_USB_ISOL_HOST;
break;
default:
return;
};
regmap_update_bits(drv->reg_pmu, offset, mask, on ? 0 : mask);
}
static void exynos4210_phy_pwr(struct samsung_usb2_phy_instance *inst, bool on)
{
struct samsung_usb2_phy_driver *drv = inst->drv;
u32 rstbits = 0;
u32 phypwr = 0;
u32 rst;
u32 pwr;
u32 clk;
switch (inst->cfg->id) {
case EXYNOS4210_DEVICE:
phypwr = EXYNOS_4210_UPHYPWR_PHY0;
rstbits = EXYNOS_4210_URSTCON_PHY0;
break;
case EXYNOS4210_HOST:
phypwr = EXYNOS_4210_UPHYPWR_PHY1;
rstbits = EXYNOS_4210_URSTCON_PHY1_ALL |
EXYNOS_4210_URSTCON_PHY1_P0 |
EXYNOS_4210_URSTCON_PHY1_P1P2 |
EXYNOS_4210_URSTCON_HOST_LINK_ALL |
EXYNOS_4210_URSTCON_HOST_LINK_P0;
writel(on, drv->reg_phy + EXYNOS_4210_UPHY1CON);
break;
case EXYNOS4210_HSIC0:
phypwr = EXYNOS_4210_UPHYPWR_HSIC0;
rstbits = EXYNOS_4210_URSTCON_PHY1_P1P2 |
EXYNOS_4210_URSTCON_HOST_LINK_P1;
break;
case EXYNOS4210_HSIC1:
phypwr = EXYNOS_4210_UPHYPWR_HSIC1;
rstbits = EXYNOS_4210_URSTCON_PHY1_P1P2 |
EXYNOS_4210_URSTCON_HOST_LINK_P2;
break;
};
if (on) {
clk = readl(drv->reg_phy + EXYNOS_4210_UPHYCLK);
clk &= ~EXYNOS_4210_UPHYCLK_PHYFSEL_MASK;
clk |= drv->ref_reg_val << EXYNOS_4210_UPHYCLK_PHYFSEL_OFFSET;
writel(clk, drv->reg_phy + EXYNOS_4210_UPHYCLK);
pwr = readl(drv->reg_phy + EXYNOS_4210_UPHYPWR);
pwr &= ~phypwr;
writel(pwr, drv->reg_phy + EXYNOS_4210_UPHYPWR);
rst = readl(drv->reg_phy + EXYNOS_4210_UPHYRST);
rst |= rstbits;
writel(rst, drv->reg_phy + EXYNOS_4210_UPHYRST);
udelay(10);
rst &= ~rstbits;
writel(rst, drv->reg_phy + EXYNOS_4210_UPHYRST);
udelay(80);
} else {
pwr = readl(drv->reg_phy + EXYNOS_4210_UPHYPWR);
pwr |= phypwr;
writel(pwr, drv->reg_phy + EXYNOS_4210_UPHYPWR);
}
}
static int exynos4210_power_on(struct samsung_usb2_phy_instance *inst)
{
exynos4210_phy_pwr(inst, 1);
exynos4210_isol(inst, 0);
return 0;
}
static int exynos4210_power_off(struct samsung_usb2_phy_instance *inst)
{
exynos4210_isol(inst, 1);
exynos4210_phy_pwr(inst, 0);
return 0;
}
