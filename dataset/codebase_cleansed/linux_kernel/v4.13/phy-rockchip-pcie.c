static inline void phy_wr_cfg(struct rockchip_pcie_phy *rk_phy,
u32 addr, u32 data)
{
regmap_write(rk_phy->reg_base, rk_phy->phy_data->pcie_conf,
HIWORD_UPDATE(data,
PHY_CFG_DATA_MASK,
PHY_CFG_DATA_SHIFT) |
HIWORD_UPDATE(addr,
PHY_CFG_ADDR_MASK,
PHY_CFG_ADDR_SHIFT));
udelay(1);
regmap_write(rk_phy->reg_base, rk_phy->phy_data->pcie_conf,
HIWORD_UPDATE(PHY_CFG_WR_ENABLE,
PHY_CFG_WR_MASK,
PHY_CFG_WR_SHIFT));
udelay(1);
regmap_write(rk_phy->reg_base, rk_phy->phy_data->pcie_conf,
HIWORD_UPDATE(PHY_CFG_WR_DISABLE,
PHY_CFG_WR_MASK,
PHY_CFG_WR_SHIFT));
}
static inline u32 phy_rd_cfg(struct rockchip_pcie_phy *rk_phy,
u32 addr)
{
u32 val;
regmap_write(rk_phy->reg_base, rk_phy->phy_data->pcie_conf,
HIWORD_UPDATE(addr,
PHY_CFG_RD_MASK,
PHY_CFG_ADDR_SHIFT));
regmap_read(rk_phy->reg_base,
rk_phy->phy_data->pcie_status,
&val);
return val;
}
static int rockchip_pcie_phy_power_off(struct phy *phy)
{
struct rockchip_pcie_phy *rk_phy = phy_get_drvdata(phy);
int err = 0;
err = reset_control_assert(rk_phy->phy_rst);
if (err) {
dev_err(&phy->dev, "assert phy_rst err %d\n", err);
return err;
}
return 0;
}
static int rockchip_pcie_phy_power_on(struct phy *phy)
{
struct rockchip_pcie_phy *rk_phy = phy_get_drvdata(phy);
int err = 0;
u32 status;
unsigned long timeout;
err = reset_control_deassert(rk_phy->phy_rst);
if (err) {
dev_err(&phy->dev, "deassert phy_rst err %d\n", err);
return err;
}
regmap_write(rk_phy->reg_base, rk_phy->phy_data->pcie_conf,
HIWORD_UPDATE(PHY_CFG_PLL_LOCK,
PHY_CFG_ADDR_MASK,
PHY_CFG_ADDR_SHIFT));
timeout = jiffies + msecs_to_jiffies(1000);
err = -EINVAL;
while (time_before(jiffies, timeout)) {
regmap_read(rk_phy->reg_base,
rk_phy->phy_data->pcie_status,
&status);
if (status & PHY_PLL_LOCKED) {
dev_dbg(&phy->dev, "pll locked!\n");
err = 0;
break;
}
msleep(20);
}
if (err) {
dev_err(&phy->dev, "pll lock timeout!\n");
goto err_pll_lock;
}
phy_wr_cfg(rk_phy, PHY_CFG_CLK_TEST, PHY_CFG_SEPE_RATE);
phy_wr_cfg(rk_phy, PHY_CFG_CLK_SCC, PHY_CFG_PLL_100M);
err = -ETIMEDOUT;
while (time_before(jiffies, timeout)) {
regmap_read(rk_phy->reg_base,
rk_phy->phy_data->pcie_status,
&status);
if (!(status & PHY_PLL_OUTPUT)) {
dev_dbg(&phy->dev, "pll output enable done!\n");
err = 0;
break;
}
msleep(20);
}
if (err) {
dev_err(&phy->dev, "pll output enable timeout!\n");
goto err_pll_lock;
}
regmap_write(rk_phy->reg_base, rk_phy->phy_data->pcie_conf,
HIWORD_UPDATE(PHY_CFG_PLL_LOCK,
PHY_CFG_ADDR_MASK,
PHY_CFG_ADDR_SHIFT));
err = -EINVAL;
while (time_before(jiffies, timeout)) {
regmap_read(rk_phy->reg_base,
rk_phy->phy_data->pcie_status,
&status);
if (status & PHY_PLL_LOCKED) {
dev_dbg(&phy->dev, "pll relocked!\n");
err = 0;
break;
}
msleep(20);
}
if (err) {
dev_err(&phy->dev, "pll relock timeout!\n");
goto err_pll_lock;
}
return 0;
err_pll_lock:
reset_control_assert(rk_phy->phy_rst);
return err;
}
static int rockchip_pcie_phy_init(struct phy *phy)
{
struct rockchip_pcie_phy *rk_phy = phy_get_drvdata(phy);
int err = 0;
err = clk_prepare_enable(rk_phy->clk_pciephy_ref);
if (err) {
dev_err(&phy->dev, "Fail to enable pcie ref clock.\n");
goto err_refclk;
}
err = reset_control_assert(rk_phy->phy_rst);
if (err) {
dev_err(&phy->dev, "assert phy_rst err %d\n", err);
goto err_reset;
}
return err;
err_reset:
clk_disable_unprepare(rk_phy->clk_pciephy_ref);
err_refclk:
return err;
}
static int rockchip_pcie_phy_exit(struct phy *phy)
{
struct rockchip_pcie_phy *rk_phy = phy_get_drvdata(phy);
clk_disable_unprepare(rk_phy->clk_pciephy_ref);
return 0;
}
static int rockchip_pcie_phy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rockchip_pcie_phy *rk_phy;
struct phy *generic_phy;
struct phy_provider *phy_provider;
struct regmap *grf;
const struct of_device_id *of_id;
grf = syscon_node_to_regmap(dev->parent->of_node);
if (IS_ERR(grf)) {
dev_err(dev, "Cannot find GRF syscon\n");
return PTR_ERR(grf);
}
rk_phy = devm_kzalloc(dev, sizeof(*rk_phy), GFP_KERNEL);
if (!rk_phy)
return -ENOMEM;
of_id = of_match_device(rockchip_pcie_phy_dt_ids, &pdev->dev);
if (!of_id)
return -EINVAL;
rk_phy->phy_data = (struct rockchip_pcie_data *)of_id->data;
rk_phy->reg_base = grf;
rk_phy->phy_rst = devm_reset_control_get(dev, "phy");
if (IS_ERR(rk_phy->phy_rst)) {
if (PTR_ERR(rk_phy->phy_rst) != -EPROBE_DEFER)
dev_err(dev,
"missing phy property for reset controller\n");
return PTR_ERR(rk_phy->phy_rst);
}
rk_phy->clk_pciephy_ref = devm_clk_get(dev, "refclk");
if (IS_ERR(rk_phy->clk_pciephy_ref)) {
dev_err(dev, "refclk not found.\n");
return PTR_ERR(rk_phy->clk_pciephy_ref);
}
generic_phy = devm_phy_create(dev, dev->of_node, &ops);
if (IS_ERR(generic_phy)) {
dev_err(dev, "failed to create PHY\n");
return PTR_ERR(generic_phy);
}
phy_set_drvdata(generic_phy, rk_phy);
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
