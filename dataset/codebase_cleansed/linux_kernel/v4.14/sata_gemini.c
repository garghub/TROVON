struct sata_gemini *gemini_sata_bridge_get(void)
{
if (sg_singleton)
return sg_singleton;
return ERR_PTR(-EPROBE_DEFER);
}
bool gemini_sata_bridge_enabled(struct sata_gemini *sg, bool is_ata1)
{
if (!sg->sata_bridge)
return false;
if ((sg->muxmode == GEMINI_MUXMODE_2) &&
!is_ata1)
return false;
if ((sg->muxmode == GEMINI_MUXMODE_3) &&
is_ata1)
return false;
return true;
}
enum gemini_muxmode gemini_sata_get_muxmode(struct sata_gemini *sg)
{
return sg->muxmode;
}
static int gemini_sata_setup_bridge(struct sata_gemini *sg,
unsigned int bridge)
{
unsigned long timeout = jiffies + (HZ * 1);
bool bridge_online;
u32 val;
if (bridge == 0) {
val = GEMINI_SATA_CTRL_HOTPLUG_DETECT_EN | GEMINI_SATA_CTRL_EN;
if (sg->muxmode == GEMINI_MUXMODE_2)
val |= GEMINI_SATA_CTRL_SLAVE_EN;
writel(val, sg->base + GEMINI_SATA0_CTRL);
} else {
val = GEMINI_SATA_CTRL_HOTPLUG_DETECT_EN | GEMINI_SATA_CTRL_EN;
if (sg->muxmode == GEMINI_MUXMODE_3)
val |= GEMINI_SATA_CTRL_SLAVE_EN;
writel(val, sg->base + GEMINI_SATA1_CTRL);
}
msleep(10);
do {
msleep(100);
if (bridge == 0)
val = readl(sg->base + GEMINI_SATA0_STATUS);
else
val = readl(sg->base + GEMINI_SATA1_STATUS);
if (val & GEMINI_SATA_STATUS_PHY_READY)
break;
} while (time_before(jiffies, timeout));
bridge_online = !!(val & GEMINI_SATA_STATUS_PHY_READY);
dev_info(sg->dev, "SATA%d PHY %s\n", bridge,
bridge_online ? "ready" : "not ready");
return bridge_online ? 0: -ENODEV;
}
int gemini_sata_start_bridge(struct sata_gemini *sg, unsigned int bridge)
{
struct clk *pclk;
int ret;
if (bridge == 0)
pclk = sg->sata0_pclk;
else
pclk = sg->sata1_pclk;
clk_enable(pclk);
msleep(10);
ret = gemini_sata_setup_bridge(sg, bridge);
if (ret)
clk_disable(pclk);
return ret;
}
void gemini_sata_stop_bridge(struct sata_gemini *sg, unsigned int bridge)
{
if (bridge == 0)
clk_disable(sg->sata0_pclk);
else if (bridge == 1)
clk_disable(sg->sata1_pclk);
}
int gemini_sata_reset_bridge(struct sata_gemini *sg,
unsigned int bridge)
{
if (bridge == 0)
reset_control_reset(sg->sata0_reset);
else
reset_control_reset(sg->sata1_reset);
msleep(10);
return gemini_sata_setup_bridge(sg, bridge);
}
static int gemini_sata_bridge_init(struct sata_gemini *sg)
{
struct device *dev = sg->dev;
u32 sata_id, sata_phy_id;
int ret;
sg->sata0_pclk = devm_clk_get(dev, "SATA0_PCLK");
if (IS_ERR(sg->sata0_pclk)) {
dev_err(dev, "no SATA0 PCLK");
return -ENODEV;
}
sg->sata1_pclk = devm_clk_get(dev, "SATA1_PCLK");
if (IS_ERR(sg->sata1_pclk)) {
dev_err(dev, "no SATA1 PCLK");
return -ENODEV;
}
ret = clk_prepare_enable(sg->sata0_pclk);
if (ret) {
pr_err("failed to enable SATA0 PCLK\n");
return ret;
}
ret = clk_prepare_enable(sg->sata1_pclk);
if (ret) {
pr_err("failed to enable SATA1 PCLK\n");
clk_disable_unprepare(sg->sata0_pclk);
return ret;
}
sg->sata0_reset = devm_reset_control_get_exclusive(dev, "sata0");
if (IS_ERR(sg->sata0_reset)) {
dev_err(dev, "no SATA0 reset controller\n");
clk_disable_unprepare(sg->sata1_pclk);
clk_disable_unprepare(sg->sata0_pclk);
return PTR_ERR(sg->sata0_reset);
}
sg->sata1_reset = devm_reset_control_get_exclusive(dev, "sata1");
if (IS_ERR(sg->sata1_reset)) {
dev_err(dev, "no SATA1 reset controller\n");
clk_disable_unprepare(sg->sata1_pclk);
clk_disable_unprepare(sg->sata0_pclk);
return PTR_ERR(sg->sata1_reset);
}
sata_id = readl(sg->base + GEMINI_SATA_ID);
sata_phy_id = readl(sg->base + GEMINI_SATA_PHY_ID);
sg->sata_bridge = true;
clk_disable(sg->sata0_pclk);
clk_disable(sg->sata1_pclk);
dev_info(dev, "SATA ID %08x, PHY ID: %08x\n", sata_id, sata_phy_id);
return 0;
}
static int gemini_setup_ide_pins(struct device *dev)
{
struct pinctrl *p;
struct pinctrl_state *ide_state;
int ret;
p = devm_pinctrl_get(dev);
if (IS_ERR(p))
return PTR_ERR(p);
ide_state = pinctrl_lookup_state(p, "ide");
if (IS_ERR(ide_state))
return PTR_ERR(ide_state);
ret = pinctrl_select_state(p, ide_state);
if (ret) {
dev_err(dev, "could not select IDE state\n");
return ret;
}
return 0;
}
static int gemini_sata_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct sata_gemini *sg;
struct regmap *map;
struct resource *res;
enum gemini_muxmode muxmode;
u32 gmode;
u32 gmask;
int ret;
sg = devm_kzalloc(dev, sizeof(*sg), GFP_KERNEL);
if (!sg)
return -ENOMEM;
sg->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
sg->base = devm_ioremap_resource(dev, res);
if (IS_ERR(sg->base))
return PTR_ERR(sg->base);
map = syscon_regmap_lookup_by_phandle(np, "syscon");
if (IS_ERR(map)) {
dev_err(dev, "no global syscon\n");
return PTR_ERR(map);
}
if (of_property_read_bool(np, "cortina,gemini-enable-sata-bridge")) {
ret = gemini_sata_bridge_init(sg);
if (ret)
return ret;
}
if (of_property_read_bool(np, "cortina,gemini-enable-ide-pins"))
sg->ide_pins = true;
if (!sg->sata_bridge && !sg->ide_pins) {
dev_err(dev, "neither SATA bridge or IDE output enabled\n");
ret = -EINVAL;
goto out_unprep_clk;
}
ret = of_property_read_u32(np, "cortina,gemini-ata-muxmode", &muxmode);
if (ret) {
dev_err(dev, "could not parse ATA muxmode\n");
goto out_unprep_clk;
}
if (muxmode > GEMINI_MUXMODE_3) {
dev_err(dev, "illegal muxmode %d\n", muxmode);
ret = -EINVAL;
goto out_unprep_clk;
}
sg->muxmode = muxmode;
gmask = GEMINI_IDE_IOMUX_MASK;
gmode = (muxmode << GEMINI_IDE_IOMUX_SHIFT);
ret = regmap_update_bits(map, GEMINI_GLOBAL_MISC_CTRL, gmask, gmode);
if (ret) {
dev_err(dev, "unable to set up IDE muxing\n");
ret = -ENODEV;
goto out_unprep_clk;
}
if (sg->ide_pins) {
ret = gemini_setup_ide_pins(dev);
if (ret)
return ret;
}
dev_info(dev, "set up the Gemini IDE/SATA nexus\n");
platform_set_drvdata(pdev, sg);
sg_singleton = sg;
return 0;
out_unprep_clk:
if (sg->sata_bridge) {
clk_unprepare(sg->sata1_pclk);
clk_unprepare(sg->sata0_pclk);
}
return ret;
}
static int gemini_sata_remove(struct platform_device *pdev)
{
struct sata_gemini *sg = platform_get_drvdata(pdev);
if (sg->sata_bridge) {
clk_unprepare(sg->sata1_pclk);
clk_unprepare(sg->sata0_pclk);
}
sg_singleton = NULL;
return 0;
}
