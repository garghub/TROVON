static void omap_hsmmc1_before_set_reg(struct device *dev,
int power_on, int vdd)
{
u32 reg, prog_io;
struct omap_hsmmc_platform_data *mmc = dev->platform_data;
if (mmc->remux)
mmc->remux(dev, power_on);
if (power_on) {
if (cpu_is_omap2430()) {
reg = omap_ctrl_readl(OMAP243X_CONTROL_DEVCONF1);
if ((1 << vdd) >= MMC_VDD_30_31)
reg |= OMAP243X_MMC1_ACTIVE_OVERWRITE;
else
reg &= ~OMAP243X_MMC1_ACTIVE_OVERWRITE;
omap_ctrl_writel(reg, OMAP243X_CONTROL_DEVCONF1);
}
if (mmc->internal_clock) {
reg = omap_ctrl_readl(OMAP2_CONTROL_DEVCONF0);
reg |= OMAP2_MMCSDIO1ADPCLKISEL;
omap_ctrl_writel(reg, OMAP2_CONTROL_DEVCONF0);
}
reg = omap_ctrl_readl(control_pbias_offset);
if (cpu_is_omap3630()) {
prog_io = omap_ctrl_readl(OMAP343X_CONTROL_PROG_IO1);
prog_io |= OMAP3630_PRG_SDMMC1_SPEEDCTRL;
omap_ctrl_writel(prog_io, OMAP343X_CONTROL_PROG_IO1);
} else {
reg |= OMAP2_PBIASSPEEDCTRL0;
}
reg &= ~OMAP2_PBIASLITEPWRDNZ0;
omap_ctrl_writel(reg, control_pbias_offset);
} else {
reg = omap_ctrl_readl(control_pbias_offset);
reg &= ~OMAP2_PBIASLITEPWRDNZ0;
omap_ctrl_writel(reg, control_pbias_offset);
}
}
static void omap_hsmmc1_after_set_reg(struct device *dev, int power_on, int vdd)
{
u32 reg;
msleep(100);
if (power_on) {
reg = omap_ctrl_readl(control_pbias_offset);
reg |= (OMAP2_PBIASLITEPWRDNZ0 | OMAP2_PBIASSPEEDCTRL0);
if ((1 << vdd) <= MMC_VDD_165_195)
reg &= ~OMAP2_PBIASLITEVMODE0;
else
reg |= OMAP2_PBIASLITEVMODE0;
omap_ctrl_writel(reg, control_pbias_offset);
} else {
reg = omap_ctrl_readl(control_pbias_offset);
reg |= (OMAP2_PBIASSPEEDCTRL0 | OMAP2_PBIASLITEPWRDNZ0 |
OMAP2_PBIASLITEVMODE0);
omap_ctrl_writel(reg, control_pbias_offset);
}
}
static void hsmmc2_select_input_clk_src(struct omap_hsmmc_platform_data *mmc)
{
u32 reg;
reg = omap_ctrl_readl(control_devconf1_offset);
if (mmc->internal_clock)
reg |= OMAP2_MMCSDIO2ADPCLKISEL;
else
reg &= ~OMAP2_MMCSDIO2ADPCLKISEL;
omap_ctrl_writel(reg, control_devconf1_offset);
}
static void hsmmc2_before_set_reg(struct device *dev, int power_on, int vdd)
{
struct omap_hsmmc_platform_data *mmc = dev->platform_data;
if (mmc->remux)
mmc->remux(dev, power_on);
if (power_on)
hsmmc2_select_input_clk_src(mmc);
}
static int am35x_hsmmc2_set_power(struct device *dev, int power_on, int vdd)
{
struct omap_hsmmc_platform_data *mmc = dev->platform_data;
if (power_on)
hsmmc2_select_input_clk_src(mmc);
return 0;
}
static int nop_mmc_set_power(struct device *dev, int power_on, int vdd)
{
return 0;
}
static int __init omap_hsmmc_pdata_init(struct omap2_hsmmc_info *c,
struct omap_hsmmc_platform_data *mmc)
{
char *hc_name;
hc_name = kzalloc(sizeof(char) * (HSMMC_NAME_LEN + 1), GFP_KERNEL);
if (!hc_name) {
pr_err("Cannot allocate memory for controller slot name\n");
kfree(hc_name);
return -ENOMEM;
}
if (c->name)
strncpy(hc_name, c->name, HSMMC_NAME_LEN);
else
snprintf(hc_name, (HSMMC_NAME_LEN + 1), "mmc%islot%i",
c->mmc, 1);
mmc->name = hc_name;
mmc->caps = c->caps;
mmc->internal_clock = !c->ext_clock;
mmc->reg_offset = 0;
if (c->cover_only) {
mmc->gpio_cd = -EINVAL;
mmc->gpio_cod = c->gpio_cd;
} else {
mmc->gpio_cd = c->gpio_cd;
mmc->gpio_cod = -EINVAL;
}
mmc->gpio_wp = c->gpio_wp;
mmc->remux = c->remux;
mmc->init_card = c->init_card;
if (c->nonremovable)
mmc->nonremovable = 1;
if (soc_is_am35xx())
mmc->ocr_mask = MMC_VDD_165_195 |
MMC_VDD_26_27 |
MMC_VDD_27_28 |
MMC_VDD_29_30 |
MMC_VDD_30_31 |
MMC_VDD_31_32;
else
mmc->ocr_mask = c->ocr_mask;
if (!soc_is_am35xx())
mmc->features |= HSMMC_HAS_PBIAS;
switch (c->mmc) {
case 1:
if (mmc->features & HSMMC_HAS_PBIAS) {
mmc->before_set_reg =
omap_hsmmc1_before_set_reg;
mmc->after_set_reg =
omap_hsmmc1_after_set_reg;
}
if (soc_is_am35xx())
mmc->set_power = nop_mmc_set_power;
if (cpu_is_omap3630() &&
(c->caps & MMC_CAP_8_BIT_DATA)) {
c->caps &= ~MMC_CAP_8_BIT_DATA;
c->caps |= MMC_CAP_4_BIT_DATA;
mmc->caps = c->caps;
}
break;
case 2:
if (soc_is_am35xx())
mmc->set_power = am35x_hsmmc2_set_power;
if (c->ext_clock)
c->transceiver = 1;
if (c->transceiver && (c->caps & MMC_CAP_8_BIT_DATA)) {
c->caps &= ~MMC_CAP_8_BIT_DATA;
c->caps |= MMC_CAP_4_BIT_DATA;
}
if (mmc->features & HSMMC_HAS_PBIAS) {
mmc->before_set_reg = hsmmc2_before_set_reg;
mmc->after_set_reg = NULL;
}
break;
case 3:
case 4:
case 5:
mmc->before_set_reg = NULL;
mmc->after_set_reg = NULL;
break;
default:
pr_err("MMC%d configuration not supported!\n", c->mmc);
kfree(hc_name);
return -ENODEV;
}
return 0;
}
void omap_hsmmc_late_init(struct omap2_hsmmc_info *c)
{
struct platform_device *pdev;
struct omap_hsmmc_platform_data *mmc_pdata;
int res;
if (omap_hsmmc_done != 1)
return;
omap_hsmmc_done++;
for (; c->mmc; c++) {
if (!c->deferred)
continue;
pdev = c->pdev;
if (!pdev)
continue;
mmc_pdata = pdev->dev.platform_data;
if (!mmc_pdata)
continue;
if (c->cover_only) {
mmc_pdata->gpio_cd = -EINVAL;
mmc_pdata->gpio_cod = c->gpio_cd;
} else {
mmc_pdata->gpio_cd = c->gpio_cd;
mmc_pdata->gpio_cod = -EINVAL;
}
mmc_pdata->gpio_wp = c->gpio_wp;
res = omap_device_register(pdev);
if (res)
pr_err("Could not late init MMC %s\n",
c->name);
}
}
static void __init omap_hsmmc_init_one(struct omap2_hsmmc_info *hsmmcinfo,
int ctrl_nr)
{
struct omap_hwmod *oh;
struct omap_hwmod *ohs[1];
struct omap_device *od;
struct platform_device *pdev;
char oh_name[MAX_OMAP_MMC_HWMOD_NAME_LEN];
struct omap_hsmmc_platform_data *mmc_data;
struct omap_hsmmc_dev_attr *mmc_dev_attr;
char *name;
int res;
mmc_data = kzalloc(sizeof(*mmc_data), GFP_KERNEL);
if (!mmc_data) {
pr_err("Cannot allocate memory for mmc device!\n");
return;
}
res = omap_hsmmc_pdata_init(hsmmcinfo, mmc_data);
if (res < 0)
goto free_mmc;
name = "omap_hsmmc";
res = snprintf(oh_name, MAX_OMAP_MMC_HWMOD_NAME_LEN,
"mmc%d", ctrl_nr);
WARN(res >= MAX_OMAP_MMC_HWMOD_NAME_LEN,
"String buffer overflow in MMC%d device setup\n", ctrl_nr);
oh = omap_hwmod_lookup(oh_name);
if (!oh) {
pr_err("Could not look up %s\n", oh_name);
goto free_name;
}
ohs[0] = oh;
if (oh->dev_attr != NULL) {
mmc_dev_attr = oh->dev_attr;
mmc_data->controller_flags = mmc_dev_attr->flags;
if (hsmmcinfo->transceiver)
mmc_data->controller_flags &=
~OMAP_HSMMC_BROKEN_MULTIBLOCK_READ;
}
pdev = platform_device_alloc(name, ctrl_nr - 1);
if (!pdev) {
pr_err("Could not allocate pdev for %s\n", name);
goto free_name;
}
dev_set_name(&pdev->dev, "%s.%d", pdev->name, pdev->id);
od = omap_device_alloc(pdev, ohs, 1);
if (IS_ERR(od)) {
pr_err("Could not allocate od for %s\n", name);
goto put_pdev;
}
res = platform_device_add_data(pdev, mmc_data,
sizeof(struct omap_hsmmc_platform_data));
if (res) {
pr_err("Could not add pdata for %s\n", name);
goto put_pdev;
}
hsmmcinfo->pdev = pdev;
if (hsmmcinfo->deferred)
goto free_mmc;
res = omap_device_register(pdev);
if (res) {
pr_err("Could not register od for %s\n", name);
goto free_od;
}
goto free_mmc;
free_od:
omap_device_delete(od);
put_pdev:
platform_device_put(pdev);
free_name:
kfree(mmc_data->name);
free_mmc:
kfree(mmc_data);
}
void __init omap_hsmmc_init(struct omap2_hsmmc_info *controllers)
{
if (omap_hsmmc_done)
return;
omap_hsmmc_done = 1;
if (cpu_is_omap2430()) {
control_pbias_offset = OMAP243X_CONTROL_PBIAS_LITE;
control_devconf1_offset = OMAP243X_CONTROL_DEVCONF1;
} else {
control_pbias_offset = OMAP343X_CONTROL_PBIAS_LITE;
control_devconf1_offset = OMAP343X_CONTROL_DEVCONF1;
}
for (; controllers->mmc; controllers++)
omap_hsmmc_init_one(controllers, controllers->mmc);
}
