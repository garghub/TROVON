static int imx_phy_crbit_assert(void __iomem *mmio, u32 bit, bool assert)
{
int timeout = 10;
u32 crval;
u32 srval;
crval = readl(mmio + IMX_P0PHYCR);
if (assert)
crval |= bit;
else
crval &= ~bit;
writel(crval, mmio + IMX_P0PHYCR);
do {
srval = readl(mmio + IMX_P0PHYSR);
if ((assert ? srval : ~srval) & IMX_P0PHYSR_CR_ACK)
break;
usleep_range(100, 200);
} while (--timeout);
return timeout ? 0 : -ETIMEDOUT;
}
static int imx_phy_reg_addressing(u16 addr, void __iomem *mmio)
{
u32 crval = addr;
int ret;
writel(crval, mmio + IMX_P0PHYCR);
ret = imx_phy_crbit_assert(mmio, IMX_P0PHYCR_CR_CAP_ADDR, true);
if (ret)
return ret;
ret = imx_phy_crbit_assert(mmio, IMX_P0PHYCR_CR_CAP_ADDR, false);
if (ret)
return ret;
return 0;
}
static int imx_phy_reg_write(u16 val, void __iomem *mmio)
{
u32 crval = val;
int ret;
writel(crval, mmio + IMX_P0PHYCR);
ret = imx_phy_crbit_assert(mmio, IMX_P0PHYCR_CR_CAP_DATA, true);
if (ret)
return ret;
ret = imx_phy_crbit_assert(mmio, IMX_P0PHYCR_CR_CAP_DATA, false);
if (ret)
return ret;
if (val & IMX_CLOCK_RESET_RESET) {
crval |= IMX_P0PHYCR_CR_WRITE;
writel(crval, mmio + IMX_P0PHYCR);
goto out;
}
ret = imx_phy_crbit_assert(mmio, IMX_P0PHYCR_CR_WRITE, true);
if (ret)
return ret;
ret = imx_phy_crbit_assert(mmio, IMX_P0PHYCR_CR_WRITE, false);
if (ret)
return ret;
out:
return 0;
}
static int imx_phy_reg_read(u16 *val, void __iomem *mmio)
{
int ret;
ret = imx_phy_crbit_assert(mmio, IMX_P0PHYCR_CR_READ, true);
if (ret)
return ret;
*val = readl(mmio + IMX_P0PHYSR) & IMX_P0PHYSR_CR_DATA_OUT;
ret = imx_phy_crbit_assert(mmio, IMX_P0PHYCR_CR_READ, false);
if (ret)
return ret;
return 0;
}
static int imx_sata_phy_reset(struct ahci_host_priv *hpriv)
{
void __iomem *mmio = hpriv->mmio;
int timeout = 10;
u16 val;
int ret;
ret = imx_phy_reg_addressing(IMX_CLOCK_RESET, mmio);
if (ret)
return ret;
ret = imx_phy_reg_write(IMX_CLOCK_RESET_RESET, mmio);
if (ret)
return ret;
do {
usleep_range(100, 200);
ret = imx_phy_reg_addressing(IMX_LANE0_OUT_STAT, mmio);
if (ret)
return ret;
ret = imx_phy_reg_read(&val, mmio);
if (ret)
return ret;
if (val & IMX_LANE0_OUT_STAT_RX_PLL_STATE)
break;
} while (--timeout);
return timeout ? 0 : -ETIMEDOUT;
}
static int read_adc_sum(void *dev, u16 rtune_ctl_reg, void __iomem * mmio)
{
u16 adc_out_reg, read_sum;
u32 index, read_attempt;
const u32 attempt_limit = 100;
imx_phy_reg_addressing(SATA_PHY_CR_CLOCK_RTUNE_CTL, mmio);
imx_phy_reg_write(rtune_ctl_reg, mmio);
index = 0;
read_attempt = 0;
adc_out_reg = 0;
imx_phy_reg_addressing(SATA_PHY_CR_CLOCK_ADC_OUT, mmio);
while (index < 2) {
imx_phy_reg_read(&adc_out_reg, mmio);
if (adc_out_reg & 0x400)
index++;
read_attempt++;
if (read_attempt > attempt_limit) {
dev_err(dev, "Read REG more than %d times!\n",
attempt_limit);
break;
}
}
index = 0;
read_attempt = 0;
read_sum = 0;
while (index < 80) {
imx_phy_reg_read(&adc_out_reg, mmio);
if (adc_out_reg & 0x400) {
read_sum = read_sum + (adc_out_reg & 0x3FF);
index++;
}
read_attempt++;
if (read_attempt > attempt_limit) {
dev_err(dev, "Read REG more than %d times!\n",
attempt_limit);
break;
}
}
return (read_sum * 1000) / 80;
}
static int sata_ahci_read_temperature(void *dev, int *temp)
{
u16 mpll_test_reg, rtune_ctl_reg, dac_ctl_reg, read_sum;
u32 str1, str2, str3, str4;
int m1, m2, a;
struct ahci_host_priv *hpriv = dev_get_drvdata(dev);
void __iomem *mmio = hpriv->mmio;
read_sum = 0;
imx_phy_reg_addressing(SATA_PHY_CR_CLOCK_CRCMP_LT_LIMIT, mmio);
imx_phy_reg_write(read_sum, mmio);
imx_phy_reg_read(&read_sum, mmio);
if ((read_sum & 0xffff) != 0)
dev_err(dev, "Read/Write REG error, 0x%x!\n", read_sum);
imx_phy_reg_write(0x5A5A, mmio);
imx_phy_reg_read(&read_sum, mmio);
if ((read_sum & 0xffff) != 0x5A5A)
dev_err(dev, "Read/Write REG error, 0x%x!\n", read_sum);
imx_phy_reg_write(0x1234, mmio);
imx_phy_reg_read(&read_sum, mmio);
if ((read_sum & 0xffff) != 0x1234)
dev_err(dev, "Read/Write REG error, 0x%x!\n", read_sum);
imx_phy_reg_addressing(SATA_PHY_CR_CLOCK_MPLL_TST, mmio);
imx_phy_reg_read(&mpll_test_reg, mmio);
imx_phy_reg_addressing(SATA_PHY_CR_CLOCK_RTUNE_CTL, mmio);
imx_phy_reg_read(&rtune_ctl_reg, mmio);
imx_phy_reg_addressing(SATA_PHY_CR_CLOCK_DAC_CTL, mmio);
imx_phy_reg_read(&dac_ctl_reg, mmio);
str1 = (mpll_test_reg >> 2) & 0x7FF;
str2 = (rtune_ctl_reg) & 0x3;
str3 = (dac_ctl_reg >> 12) & 0x7;
str4 = (rtune_ctl_reg >> 4);
mpll_test_reg = (mpll_test_reg & 0xE03) | (512) << 2;
rtune_ctl_reg = (rtune_ctl_reg & 0xFFC) | (1);
dac_ctl_reg = (dac_ctl_reg & 0x8FF) | (4) << 12;
rtune_ctl_reg = (rtune_ctl_reg & 0xFEF) | (0) << 4;
imx_phy_reg_addressing(SATA_PHY_CR_CLOCK_MPLL_TST, mmio);
imx_phy_reg_write(mpll_test_reg, mmio);
imx_phy_reg_addressing(SATA_PHY_CR_CLOCK_DAC_CTL, mmio);
imx_phy_reg_write(dac_ctl_reg, mmio);
m1 = read_adc_sum(dev, rtune_ctl_reg, mmio);
rtune_ctl_reg = (rtune_ctl_reg & 0xFEF) | (1) << 4;
m2 = read_adc_sum(dev, rtune_ctl_reg, mmio);
mpll_test_reg = (mpll_test_reg & 0xE03) | (str1) << 2;
rtune_ctl_reg = (rtune_ctl_reg & 0xFFC) | (str2);
dac_ctl_reg = (dac_ctl_reg & 0x8FF) | (str3) << 12;
rtune_ctl_reg = (rtune_ctl_reg & 0xFEF) | (str4) << 4;
imx_phy_reg_addressing(SATA_PHY_CR_CLOCK_MPLL_TST, mmio);
imx_phy_reg_write(mpll_test_reg, mmio);
imx_phy_reg_addressing(SATA_PHY_CR_CLOCK_DAC_CTL, mmio);
imx_phy_reg_write(dac_ctl_reg, mmio);
imx_phy_reg_addressing(SATA_PHY_CR_CLOCK_RTUNE_CTL, mmio);
imx_phy_reg_write(rtune_ctl_reg, mmio);
if (!(m2 / 1000))
m2 = 1000;
a = (m2 - m1) / (m2/1000);
*temp = ((-559) * a * a) / 1000 + (1379) * a + (-458000);
return 0;
}
static ssize_t sata_ahci_show_temp(struct device *dev,
struct device_attribute *da,
char *buf)
{
unsigned int temp = 0;
int err;
err = sata_ahci_read_temperature(dev, &temp);
if (err < 0)
return err;
return sprintf(buf, "%u\n", temp);
}
static int imx_sata_enable(struct ahci_host_priv *hpriv)
{
struct imx_ahci_priv *imxpriv = hpriv->plat_data;
struct device *dev = &imxpriv->ahci_pdev->dev;
int ret;
if (imxpriv->no_device)
return 0;
ret = ahci_platform_enable_regulators(hpriv);
if (ret)
return ret;
ret = clk_prepare_enable(imxpriv->sata_ref_clk);
if (ret < 0)
goto disable_regulator;
if (imxpriv->type == AHCI_IMX6Q) {
regmap_update_bits(imxpriv->gpr, IOMUXC_GPR13,
IMX6Q_GPR13_SATA_RX_EQ_VAL_MASK |
IMX6Q_GPR13_SATA_RX_LOS_LVL_MASK |
IMX6Q_GPR13_SATA_RX_DPLL_MODE_MASK |
IMX6Q_GPR13_SATA_SPD_MODE_MASK |
IMX6Q_GPR13_SATA_MPLL_SS_EN |
IMX6Q_GPR13_SATA_TX_ATTEN_MASK |
IMX6Q_GPR13_SATA_TX_BOOST_MASK |
IMX6Q_GPR13_SATA_TX_LVL_MASK |
IMX6Q_GPR13_SATA_MPLL_CLK_EN |
IMX6Q_GPR13_SATA_TX_EDGE_RATE,
imxpriv->phy_params);
regmap_update_bits(imxpriv->gpr, IOMUXC_GPR13,
IMX6Q_GPR13_SATA_MPLL_CLK_EN,
IMX6Q_GPR13_SATA_MPLL_CLK_EN);
usleep_range(100, 200);
ret = imx_sata_phy_reset(hpriv);
if (ret) {
dev_err(dev, "failed to reset phy: %d\n", ret);
goto disable_clk;
}
}
usleep_range(1000, 2000);
return 0;
disable_clk:
clk_disable_unprepare(imxpriv->sata_ref_clk);
disable_regulator:
ahci_platform_disable_regulators(hpriv);
return ret;
}
static void imx_sata_disable(struct ahci_host_priv *hpriv)
{
struct imx_ahci_priv *imxpriv = hpriv->plat_data;
if (imxpriv->no_device)
return;
if (imxpriv->type == AHCI_IMX6Q) {
regmap_update_bits(imxpriv->gpr, IOMUXC_GPR13,
IMX6Q_GPR13_SATA_MPLL_CLK_EN,
!IMX6Q_GPR13_SATA_MPLL_CLK_EN);
}
clk_disable_unprepare(imxpriv->sata_ref_clk);
ahci_platform_disable_regulators(hpriv);
}
static void ahci_imx_error_handler(struct ata_port *ap)
{
u32 reg_val;
struct ata_device *dev;
struct ata_host *host = dev_get_drvdata(ap->dev);
struct ahci_host_priv *hpriv = host->private_data;
void __iomem *mmio = hpriv->mmio;
struct imx_ahci_priv *imxpriv = hpriv->plat_data;
ahci_error_handler(ap);
if (!(imxpriv->first_time) || ahci_imx_hotplug)
return;
imxpriv->first_time = false;
ata_for_each_dev(dev, &ap->link, ENABLED)
return;
reg_val = readl(mmio + IMX_P0PHYCR);
writel(reg_val | IMX_P0PHYCR_TEST_PDDQ, mmio + IMX_P0PHYCR);
imx_sata_disable(hpriv);
imxpriv->no_device = true;
dev_info(ap->dev, "no device found, disabling link.\n");
dev_info(ap->dev, "pass " MODULE_PARAM_PREFIX ".hotplug=1 to enable hotplug\n");
}
static int ahci_imx_softreset(struct ata_link *link, unsigned int *class,
unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct ata_host *host = dev_get_drvdata(ap->dev);
struct ahci_host_priv *hpriv = host->private_data;
struct imx_ahci_priv *imxpriv = hpriv->plat_data;
int ret = -EIO;
if (imxpriv->type == AHCI_IMX53)
ret = ahci_pmp_retry_srst_ops.softreset(link, class, deadline);
else if (imxpriv->type == AHCI_IMX6Q)
ret = ahci_ops.softreset(link, class, deadline);
return ret;
}
static u32 imx_ahci_parse_props(struct device *dev,
const struct reg_property *prop, size_t num)
{
struct device_node *np = dev->of_node;
u32 reg_value = 0;
int i, j;
for (i = 0; i < num; i++, prop++) {
u32 of_val;
if (prop->num_values == 0) {
if (of_property_read_bool(np, prop->name))
reg_value |= prop->set_value;
else
reg_value |= prop->def_value;
continue;
}
if (of_property_read_u32(np, prop->name, &of_val)) {
dev_info(dev, "%s not specified, using %08x\n",
prop->name, prop->def_value);
reg_value |= prop->def_value;
continue;
}
for (j = 0; j < prop->num_values; j++) {
if (prop->values[j].of_value == of_val) {
dev_info(dev, "%s value %u, using %08x\n",
prop->name, of_val, prop->values[j].reg_value);
reg_value |= prop->values[j].reg_value;
break;
}
}
if (j == prop->num_values) {
dev_err(dev, "DT property %s is not a valid value\n",
prop->name);
reg_value |= prop->def_value;
}
}
return reg_value;
}
static int imx_ahci_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct of_device_id *of_id;
struct ahci_host_priv *hpriv;
struct imx_ahci_priv *imxpriv;
unsigned int reg_val;
int ret;
of_id = of_match_device(imx_ahci_of_match, dev);
if (!of_id)
return -EINVAL;
imxpriv = devm_kzalloc(dev, sizeof(*imxpriv), GFP_KERNEL);
if (!imxpriv)
return -ENOMEM;
imxpriv->ahci_pdev = pdev;
imxpriv->no_device = false;
imxpriv->first_time = true;
imxpriv->type = (enum ahci_imx_type)of_id->data;
imxpriv->sata_clk = devm_clk_get(dev, "sata");
if (IS_ERR(imxpriv->sata_clk)) {
dev_err(dev, "can't get sata clock.\n");
return PTR_ERR(imxpriv->sata_clk);
}
imxpriv->sata_ref_clk = devm_clk_get(dev, "sata_ref");
if (IS_ERR(imxpriv->sata_ref_clk)) {
dev_err(dev, "can't get sata_ref clock.\n");
return PTR_ERR(imxpriv->sata_ref_clk);
}
imxpriv->ahb_clk = devm_clk_get(dev, "ahb");
if (IS_ERR(imxpriv->ahb_clk)) {
dev_err(dev, "can't get ahb clock.\n");
return PTR_ERR(imxpriv->ahb_clk);
}
if (imxpriv->type == AHCI_IMX6Q) {
u32 reg_value;
imxpriv->gpr = syscon_regmap_lookup_by_compatible(
"fsl,imx6q-iomuxc-gpr");
if (IS_ERR(imxpriv->gpr)) {
dev_err(dev,
"failed to find fsl,imx6q-iomux-gpr regmap\n");
return PTR_ERR(imxpriv->gpr);
}
reg_value = imx_ahci_parse_props(dev, gpr13_props,
ARRAY_SIZE(gpr13_props));
imxpriv->phy_params =
IMX6Q_GPR13_SATA_RX_LOS_LVL_SATA2M |
IMX6Q_GPR13_SATA_RX_DPLL_MODE_2P_4F |
IMX6Q_GPR13_SATA_SPD_MODE_3P0G |
reg_value;
}
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
hpriv->plat_data = imxpriv;
ret = clk_prepare_enable(imxpriv->sata_clk);
if (ret)
return ret;
if (imxpriv->type == AHCI_IMX53 &&
IS_ENABLED(CONFIG_HWMON)) {
struct device *hwmon_dev;
hwmon_dev =
devm_hwmon_device_register_with_groups(dev,
"sata_ahci",
hpriv,
fsl_sata_ahci_groups);
if (IS_ERR(hwmon_dev)) {
ret = PTR_ERR(hwmon_dev);
goto disable_clk;
}
devm_thermal_zone_of_sensor_register(hwmon_dev, 0, hwmon_dev,
&fsl_sata_ahci_of_thermal_ops);
dev_info(dev, "%s: sensor 'sata_ahci'\n", dev_name(hwmon_dev));
}
ret = imx_sata_enable(hpriv);
if (ret)
goto disable_clk;
reg_val = readl(hpriv->mmio + HOST_CAP);
if (!(reg_val & HOST_CAP_SSS)) {
reg_val |= HOST_CAP_SSS;
writel(reg_val, hpriv->mmio + HOST_CAP);
}
reg_val = readl(hpriv->mmio + HOST_PORTS_IMPL);
if (!(reg_val & 0x1)) {
reg_val |= 0x1;
writel(reg_val, hpriv->mmio + HOST_PORTS_IMPL);
}
reg_val = clk_get_rate(imxpriv->ahb_clk) / 1000;
writel(reg_val, hpriv->mmio + IMX_TIMER1MS);
ret = ahci_platform_init_host(pdev, hpriv, &ahci_imx_port_info,
&ahci_platform_sht);
if (ret)
goto disable_sata;
return 0;
disable_sata:
imx_sata_disable(hpriv);
disable_clk:
clk_disable_unprepare(imxpriv->sata_clk);
return ret;
}
static void ahci_imx_host_stop(struct ata_host *host)
{
struct ahci_host_priv *hpriv = host->private_data;
struct imx_ahci_priv *imxpriv = hpriv->plat_data;
imx_sata_disable(hpriv);
clk_disable_unprepare(imxpriv->sata_clk);
}
static int imx_ahci_suspend(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
struct ahci_host_priv *hpriv = host->private_data;
int ret;
ret = ahci_platform_suspend_host(dev);
if (ret)
return ret;
imx_sata_disable(hpriv);
return 0;
}
static int imx_ahci_resume(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
struct ahci_host_priv *hpriv = host->private_data;
int ret;
ret = imx_sata_enable(hpriv);
if (ret)
return ret;
return ahci_platform_resume_host(dev);
}
