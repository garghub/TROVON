void __init s3c_fb_set_platdata(struct s3c_fb_platdata *pd)
{
s3c_set_platdata(pd, sizeof(struct s3c_fb_platdata),
&s3c_device_fb);
}
void __init s5p_fimd0_set_platdata(struct s3c_fb_platdata *pd)
{
s3c_set_platdata(pd, sizeof(struct s3c_fb_platdata),
&s5p_device_fimd0);
}
void __init s3c_hwmon_set_platdata(struct s3c_hwmon_pdata *pd)
{
s3c_set_platdata(pd, sizeof(struct s3c_hwmon_pdata),
&s3c_device_hwmon);
}
void s3c_sdhci0_set_platdata(struct s3c_sdhci_platdata *pd)
{
s3c_sdhci_set_platdata(pd, &s3c_hsmmc0_def_platdata);
}
void s3c_sdhci1_set_platdata(struct s3c_sdhci_platdata *pd)
{
s3c_sdhci_set_platdata(pd, &s3c_hsmmc1_def_platdata);
}
void s3c_sdhci2_set_platdata(struct s3c_sdhci_platdata *pd)
{
s3c_sdhci_set_platdata(pd, &s3c_hsmmc2_def_platdata);
}
void s3c_sdhci3_set_platdata(struct s3c_sdhci_platdata *pd)
{
s3c_sdhci_set_platdata(pd, &s3c_hsmmc3_def_platdata);
}
void __init s3c_i2c0_set_platdata(struct s3c2410_platform_i2c *pd)
{
struct s3c2410_platform_i2c *npd;
if (!pd) {
pd = &default_i2c_data;
pd->bus_num = 0;
}
npd = s3c_set_platdata(pd, sizeof(struct s3c2410_platform_i2c),
&s3c_device_i2c0);
if (!npd->cfg_gpio)
npd->cfg_gpio = s3c_i2c0_cfg_gpio;
}
void __init s3c_i2c1_set_platdata(struct s3c2410_platform_i2c *pd)
{
struct s3c2410_platform_i2c *npd;
if (!pd) {
pd = &default_i2c_data;
pd->bus_num = 1;
}
npd = s3c_set_platdata(pd, sizeof(struct s3c2410_platform_i2c),
&s3c_device_i2c1);
if (!npd->cfg_gpio)
npd->cfg_gpio = s3c_i2c1_cfg_gpio;
}
void __init s3c_i2c2_set_platdata(struct s3c2410_platform_i2c *pd)
{
struct s3c2410_platform_i2c *npd;
if (!pd) {
pd = &default_i2c_data;
pd->bus_num = 2;
}
npd = s3c_set_platdata(pd, sizeof(struct s3c2410_platform_i2c),
&s3c_device_i2c2);
if (!npd->cfg_gpio)
npd->cfg_gpio = s3c_i2c2_cfg_gpio;
}
void __init s3c_i2c3_set_platdata(struct s3c2410_platform_i2c *pd)
{
struct s3c2410_platform_i2c *npd;
if (!pd) {
pd = &default_i2c_data;
pd->bus_num = 3;
}
npd = s3c_set_platdata(pd, sizeof(struct s3c2410_platform_i2c),
&s3c_device_i2c3);
if (!npd->cfg_gpio)
npd->cfg_gpio = s3c_i2c3_cfg_gpio;
}
void __init s3c_i2c4_set_platdata(struct s3c2410_platform_i2c *pd)
{
struct s3c2410_platform_i2c *npd;
if (!pd) {
pd = &default_i2c_data;
pd->bus_num = 4;
}
npd = s3c_set_platdata(pd, sizeof(struct s3c2410_platform_i2c),
&s3c_device_i2c4);
if (!npd->cfg_gpio)
npd->cfg_gpio = s3c_i2c4_cfg_gpio;
}
void __init s3c_i2c5_set_platdata(struct s3c2410_platform_i2c *pd)
{
struct s3c2410_platform_i2c *npd;
if (!pd) {
pd = &default_i2c_data;
pd->bus_num = 5;
}
npd = s3c_set_platdata(pd, sizeof(struct s3c2410_platform_i2c),
&s3c_device_i2c5);
if (!npd->cfg_gpio)
npd->cfg_gpio = s3c_i2c5_cfg_gpio;
}
void __init s3c_i2c6_set_platdata(struct s3c2410_platform_i2c *pd)
{
struct s3c2410_platform_i2c *npd;
if (!pd) {
pd = &default_i2c_data;
pd->bus_num = 6;
}
npd = s3c_set_platdata(pd, sizeof(struct s3c2410_platform_i2c),
&s3c_device_i2c6);
if (!npd->cfg_gpio)
npd->cfg_gpio = s3c_i2c6_cfg_gpio;
}
void __init s3c_i2c7_set_platdata(struct s3c2410_platform_i2c *pd)
{
struct s3c2410_platform_i2c *npd;
if (!pd) {
pd = &default_i2c_data;
pd->bus_num = 7;
}
npd = s3c_set_platdata(pd, sizeof(struct s3c2410_platform_i2c),
&s3c_device_i2c7);
if (!npd->cfg_gpio)
npd->cfg_gpio = s3c_i2c7_cfg_gpio;
}
void __init s5p_i2c_hdmiphy_set_platdata(struct s3c2410_platform_i2c *pd)
{
struct s3c2410_platform_i2c *npd;
if (!pd) {
pd = &default_i2c_data;
if (soc_is_exynos4210() ||
soc_is_exynos4212() || soc_is_exynos4412())
pd->bus_num = 8;
else if (soc_is_s5pv210())
pd->bus_num = 3;
else
pd->bus_num = 0;
}
npd = s3c_set_platdata(pd, sizeof(struct s3c2410_platform_i2c),
&s5p_device_i2c_hdmiphy);
}
void __init s5p_hdmi_set_platdata(struct i2c_board_info *hdmiphy_info,
struct i2c_board_info *mhl_info, int mhl_bus)
{
struct s5p_hdmi_platform_data *pd = &s5p_hdmi_def_platdata;
if (soc_is_exynos4210() ||
soc_is_exynos4212() || soc_is_exynos4412())
pd->hdmiphy_bus = 8;
else if (soc_is_s5pv210())
pd->hdmiphy_bus = 3;
else
pd->hdmiphy_bus = 0;
pd->hdmiphy_info = hdmiphy_info;
pd->mhl_info = mhl_info;
pd->mhl_bus = mhl_bus;
s3c_set_platdata(pd, sizeof(struct s5p_hdmi_platform_data),
&s5p_device_hdmi);
}
void __init s3c_ide_set_platdata(struct s3c_ide_platdata *pdata)
{
s3c_set_platdata(pdata, sizeof(struct s3c_ide_platdata),
&s3c_device_cfcon);
}
void __init samsung_keypad_set_platdata(struct samsung_keypad_platdata *pd)
{
struct samsung_keypad_platdata *npd;
npd = s3c_set_platdata(pd, sizeof(struct samsung_keypad_platdata),
&samsung_device_keypad);
if (!npd->cfg_gpio)
npd->cfg_gpio = samsung_keypad_cfg_gpio;
}
void __init s3c24xx_fb_set_platdata(struct s3c2410fb_mach_info *pd)
{
struct s3c2410fb_mach_info *npd;
npd = s3c_set_platdata(pd, sizeof(*npd), &s3c_device_lcd);
if (npd) {
npd->displays = kmemdup(pd->displays,
sizeof(struct s3c2410fb_display) * npd->num_displays,
GFP_KERNEL);
if (!npd->displays)
printk(KERN_ERR "no memory for LCD display data\n");
} else {
printk(KERN_ERR "no memory for LCD platform data\n");
}
}
static int __init s3c_nand_copy_set(struct s3c2410_nand_set *set)
{
void *ptr;
int size;
size = sizeof(struct mtd_partition) * set->nr_partitions;
if (size) {
ptr = kmemdup(set->partitions, size, GFP_KERNEL);
set->partitions = ptr;
if (!ptr)
return -ENOMEM;
}
if (set->nr_map && set->nr_chips) {
size = sizeof(int) * set->nr_chips;
ptr = kmemdup(set->nr_map, size, GFP_KERNEL);
set->nr_map = ptr;
if (!ptr)
return -ENOMEM;
}
if (set->ecc_layout) {
ptr = kmemdup(set->ecc_layout,
sizeof(struct nand_ecclayout), GFP_KERNEL);
set->ecc_layout = ptr;
if (!ptr)
return -ENOMEM;
}
return 0;
}
void __init s3c_nand_set_platdata(struct s3c2410_platform_nand *nand)
{
struct s3c2410_platform_nand *npd;
int size;
int ret;
npd = s3c_set_platdata(nand, sizeof(struct s3c2410_platform_nand),
&s3c_device_nand);
if (!npd)
return;
size = sizeof(struct s3c2410_nand_set) * npd->nr_sets;
if (size) {
struct s3c2410_nand_set *from = npd->sets;
struct s3c2410_nand_set *to;
int i;
to = kmemdup(from, size, GFP_KERNEL);
npd->sets = to;
if (!to) {
printk(KERN_ERR "%s: no memory for sets\n", __func__);
return;
}
for (i = 0; i < npd->nr_sets; i++) {
ret = s3c_nand_copy_set(to);
if (ret) {
printk(KERN_ERR "%s: failed to copy set %d\n",
__func__, i);
return;
}
to++;
}
}
}
void __init s3c64xx_onenand1_set_platdata(struct onenand_platform_data *pdata)
{
s3c_set_platdata(pdata, sizeof(struct onenand_platform_data),
&s3c64xx_device_onenand1);
}
static int __init s5p_pmu_init(void)
{
platform_device_register(&s5p_device_pmu);
return 0;
}
void __init s3c24xx_mci_set_platdata(struct s3c24xx_mci_pdata *pdata)
{
s3c_set_platdata(pdata, sizeof(struct s3c24xx_mci_pdata),
&s3c_device_sdi);
}
void __init s3c24xx_ts_set_platdata(struct s3c2410_ts_mach_info *hard_s3c2410ts_info)
{
s3c_set_platdata(hard_s3c2410ts_info,
sizeof(struct s3c2410_ts_mach_info), &s3c_device_ts);
}
void __init s3c24xx_ts_set_platdata(struct s3c2410_ts_mach_info *pd)
{
if (!pd)
pd = &default_ts_data;
s3c_set_platdata(pd, sizeof(struct s3c2410_ts_mach_info),
&s3c_device_ts);
}
void __init s3c_ohci_set_platdata(struct s3c2410_hcd_info *info)
{
s3c_set_platdata(info, sizeof(struct s3c2410_hcd_info),
&s3c_device_ohci);
}
void __init s3c24xx_udc_set_platdata(struct s3c2410_udc_mach_info *pd)
{
s3c_set_platdata(pd, sizeof(*pd), &s3c_device_usbgadget);
}
void __init s5p_ehci_set_platdata(struct s5p_ehci_platdata *pd)
{
struct s5p_ehci_platdata *npd;
npd = s3c_set_platdata(pd, sizeof(struct s5p_ehci_platdata),
&s5p_device_ehci);
if (!npd->phy_init)
npd->phy_init = s5p_usb_phy_init;
if (!npd->phy_exit)
npd->phy_exit = s5p_usb_phy_exit;
}
void __init s3c_hsotg_set_platdata(struct s3c_hsotg_plat *pd)
{
struct s3c_hsotg_plat *npd;
npd = s3c_set_platdata(pd, sizeof(struct s3c_hsotg_plat),
&s3c_device_usb_hsotg);
if (!npd->phy_init)
npd->phy_init = s5p_usb_phy_init;
if (!npd->phy_exit)
npd->phy_exit = s5p_usb_phy_exit;
}
void __init s3c24xx_hsudc_set_platdata(struct s3c24xx_hsudc_platdata *pd)
{
s3c_set_platdata(pd, sizeof(*pd), &s3c_device_usb_hsudc);
}
void __init s3c64xx_spi0_set_platdata(int (*cfg_gpio)(void), int src_clk_nr,
int num_cs)
{
struct s3c64xx_spi_info pd;
if (!num_cs || src_clk_nr < 0) {
pr_err("%s: Invalid SPI configuration\n", __func__);
return;
}
pd.num_cs = num_cs;
pd.src_clk_nr = src_clk_nr;
pd.cfg_gpio = (cfg_gpio) ? cfg_gpio : s3c64xx_spi0_cfg_gpio;
s3c_set_platdata(&pd, sizeof(pd), &s3c64xx_device_spi0);
}
void __init s3c64xx_spi1_set_platdata(int (*cfg_gpio)(void), int src_clk_nr,
int num_cs)
{
if (!num_cs || src_clk_nr < 0) {
pr_err("%s: Invalid SPI configuration\n", __func__);
return;
}
pd.num_cs = num_cs;
pd.src_clk_nr = src_clk_nr;
pd.cfg_gpio = (cfg_gpio) ? cfg_gpio : s3c64xx_spi1_cfg_gpio;
s3c_set_platdata(&pd, sizeof(pd), &s3c64xx_device_spi1);
}
void __init s3c64xx_spi2_set_platdata(int (*cfg_gpio)(void), int src_clk_nr,
int num_cs)
{
struct s3c64xx_spi_info pd;
if (!num_cs || src_clk_nr < 0) {
pr_err("%s: Invalid SPI configuration\n", __func__);
return;
}
pd.num_cs = num_cs;
pd.src_clk_nr = src_clk_nr;
pd.cfg_gpio = (cfg_gpio) ? cfg_gpio : s3c64xx_spi2_cfg_gpio;
s3c_set_platdata(&pd, sizeof(pd), &s3c64xx_device_spi2);
}
