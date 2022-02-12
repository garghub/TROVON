static int s5pv210_rate_to_clk(unsigned long rate, u32 *reg)
{
switch (rate) {
case 12 * MHZ:
*reg = S5PV210_UPHYCLK_PHYFSEL_12MHZ;
break;
case 24 * MHZ:
*reg = S5PV210_UPHYCLK_PHYFSEL_24MHZ;
break;
case 48 * MHZ:
*reg = S5PV210_UPHYCLK_PHYFSEL_48MHZ;
break;
default:
return -EINVAL;
}
return 0;
}
static void s5pv210_isol(struct samsung_usb2_phy_instance *inst, bool on)
{
struct samsung_usb2_phy_driver *drv = inst->drv;
u32 mask;
switch (inst->cfg->id) {
case S5PV210_DEVICE:
mask = S5PV210_USB_ISOL_DEVICE;
break;
case S5PV210_HOST:
mask = S5PV210_USB_ISOL_HOST;
break;
default:
return;
};
regmap_update_bits(drv->reg_pmu, S5PV210_USB_ISOL_OFFSET,
mask, on ? 0 : mask);
}
static void s5pv210_phy_pwr(struct samsung_usb2_phy_instance *inst, bool on)
{
struct samsung_usb2_phy_driver *drv = inst->drv;
u32 rstbits = 0;
u32 phypwr = 0;
u32 rst;
u32 pwr;
switch (inst->cfg->id) {
case S5PV210_DEVICE:
phypwr = S5PV210_UPHYPWR_PHY0;
rstbits = S5PV210_URSTCON_PHY0;
break;
case S5PV210_HOST:
phypwr = S5PV210_UPHYPWR_PHY1;
rstbits = S5PV210_URSTCON_PHY1_ALL |
S5PV210_URSTCON_HOST_LINK_ALL;
break;
};
if (on) {
writel(drv->ref_reg_val, drv->reg_phy + S5PV210_UPHYCLK);
pwr = readl(drv->reg_phy + S5PV210_UPHYPWR);
pwr &= ~phypwr;
writel(pwr, drv->reg_phy + S5PV210_UPHYPWR);
rst = readl(drv->reg_phy + S5PV210_UPHYRST);
rst |= rstbits;
writel(rst, drv->reg_phy + S5PV210_UPHYRST);
udelay(10);
rst &= ~rstbits;
writel(rst, drv->reg_phy + S5PV210_UPHYRST);
} else {
pwr = readl(drv->reg_phy + S5PV210_UPHYPWR);
pwr |= phypwr;
writel(pwr, drv->reg_phy + S5PV210_UPHYPWR);
}
}
static int s5pv210_power_on(struct samsung_usb2_phy_instance *inst)
{
s5pv210_isol(inst, 0);
s5pv210_phy_pwr(inst, 1);
return 0;
}
static int s5pv210_power_off(struct samsung_usb2_phy_instance *inst)
{
s5pv210_phy_pwr(inst, 0);
s5pv210_isol(inst, 1);
return 0;
}
