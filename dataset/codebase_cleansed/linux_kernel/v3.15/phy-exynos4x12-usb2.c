static int exynos4x12_rate_to_clk(unsigned long rate, u32 *reg)
{
switch (rate) {
case 9600 * KHZ:
*reg = EXYNOS_4x12_UPHYCLK_PHYFSEL_9MHZ6;
break;
case 10 * MHZ:
*reg = EXYNOS_4x12_UPHYCLK_PHYFSEL_10MHZ;
break;
case 12 * MHZ:
*reg = EXYNOS_4x12_UPHYCLK_PHYFSEL_12MHZ;
break;
case 19200 * KHZ:
*reg = EXYNOS_4x12_UPHYCLK_PHYFSEL_19MHZ2;
break;
case 20 * MHZ:
*reg = EXYNOS_4x12_UPHYCLK_PHYFSEL_20MHZ;
break;
case 24 * MHZ:
*reg = EXYNOS_4x12_UPHYCLK_PHYFSEL_24MHZ;
break;
case 50 * MHZ:
*reg = EXYNOS_4x12_UPHYCLK_PHYFSEL_50MHZ;
break;
default:
return -EINVAL;
}
return 0;
}
static void exynos4x12_isol(struct samsung_usb2_phy_instance *inst, bool on)
{
struct samsung_usb2_phy_driver *drv = inst->drv;
u32 offset;
u32 mask;
switch (inst->cfg->id) {
case EXYNOS4x12_DEVICE:
case EXYNOS4x12_HOST:
offset = EXYNOS_4x12_USB_ISOL_OFFSET;
mask = EXYNOS_4x12_USB_ISOL_OTG;
break;
case EXYNOS4x12_HSIC0:
offset = EXYNOS_4x12_USB_ISOL_HSIC0_OFFSET;
mask = EXYNOS_4x12_USB_ISOL_HSIC0;
break;
case EXYNOS4x12_HSIC1:
offset = EXYNOS_4x12_USB_ISOL_HSIC1_OFFSET;
mask = EXYNOS_4x12_USB_ISOL_HSIC1;
break;
default:
return;
};
regmap_update_bits(drv->reg_pmu, offset, mask, on ? 0 : mask);
}
static void exynos4x12_setup_clk(struct samsung_usb2_phy_instance *inst)
{
struct samsung_usb2_phy_driver *drv = inst->drv;
u32 clk;
clk = readl(drv->reg_phy + EXYNOS_4x12_UPHYCLK);
clk &= ~EXYNOS_4x12_UPHYCLK_PHYFSEL_MASK;
clk |= drv->ref_reg_val << EXYNOS_4x12_UPHYCLK_PHYFSEL_OFFSET;
writel(clk, drv->reg_phy + EXYNOS_4x12_UPHYCLK);
}
static void exynos4x12_phy_pwr(struct samsung_usb2_phy_instance *inst, bool on)
{
struct samsung_usb2_phy_driver *drv = inst->drv;
u32 rstbits = 0;
u32 phypwr = 0;
u32 rst;
u32 pwr;
u32 mode = 0;
u32 switch_mode = 0;
switch (inst->cfg->id) {
case EXYNOS4x12_DEVICE:
phypwr = EXYNOS_4x12_UPHYPWR_PHY0;
rstbits = EXYNOS_4x12_URSTCON_PHY0;
mode = EXYNOS_4x12_MODE_SWITCH_DEVICE;
switch_mode = 1;
break;
case EXYNOS4x12_HOST:
phypwr = EXYNOS_4x12_UPHYPWR_PHY1;
rstbits = EXYNOS_4x12_URSTCON_HOST_PHY;
mode = EXYNOS_4x12_MODE_SWITCH_HOST;
switch_mode = 1;
break;
case EXYNOS4x12_HSIC0:
phypwr = EXYNOS_4x12_UPHYPWR_HSIC0;
rstbits = EXYNOS_4x12_URSTCON_HSIC1 |
EXYNOS_4x12_URSTCON_HOST_LINK_P0 |
EXYNOS_4x12_URSTCON_HOST_PHY;
break;
case EXYNOS4x12_HSIC1:
phypwr = EXYNOS_4x12_UPHYPWR_HSIC1;
rstbits = EXYNOS_4x12_URSTCON_HSIC1 |
EXYNOS_4x12_URSTCON_HOST_LINK_P1;
break;
};
if (on) {
if (switch_mode)
regmap_update_bits(drv->reg_sys,
EXYNOS_4x12_MODE_SWITCH_OFFSET,
EXYNOS_4x12_MODE_SWITCH_MASK, mode);
pwr = readl(drv->reg_phy + EXYNOS_4x12_UPHYPWR);
pwr &= ~phypwr;
writel(pwr, drv->reg_phy + EXYNOS_4x12_UPHYPWR);
rst = readl(drv->reg_phy + EXYNOS_4x12_UPHYRST);
rst |= rstbits;
writel(rst, drv->reg_phy + EXYNOS_4x12_UPHYRST);
udelay(10);
rst &= ~rstbits;
writel(rst, drv->reg_phy + EXYNOS_4x12_UPHYRST);
udelay(80);
} else {
pwr = readl(drv->reg_phy + EXYNOS_4x12_UPHYPWR);
pwr |= phypwr;
writel(pwr, drv->reg_phy + EXYNOS_4x12_UPHYPWR);
}
}
static int exynos4x12_power_on(struct samsung_usb2_phy_instance *inst)
{
struct samsung_usb2_phy_driver *drv = inst->drv;
inst->enabled = 1;
exynos4x12_setup_clk(inst);
exynos4x12_phy_pwr(inst, 1);
exynos4x12_isol(inst, 0);
if (inst->cfg->id == EXYNOS4x12_HSIC0) {
struct samsung_usb2_phy_instance *device =
&drv->instances[EXYNOS4x12_DEVICE];
exynos4x12_phy_pwr(device, 1);
exynos4x12_isol(device, 0);
}
return 0;
}
static int exynos4x12_power_off(struct samsung_usb2_phy_instance *inst)
{
struct samsung_usb2_phy_driver *drv = inst->drv;
struct samsung_usb2_phy_instance *device =
&drv->instances[EXYNOS4x12_DEVICE];
inst->enabled = 0;
exynos4x12_isol(inst, 1);
exynos4x12_phy_pwr(inst, 0);
if (inst->cfg->id == EXYNOS4x12_HSIC0 && !device->enabled) {
exynos4x12_isol(device, 1);
exynos4x12_phy_pwr(device, 0);
}
return 0;
}
