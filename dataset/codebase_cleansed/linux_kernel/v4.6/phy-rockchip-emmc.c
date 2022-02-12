static int rockchip_emmc_phy_power(struct rockchip_emmc_phy *rk_phy,
bool on_off)
{
unsigned int caldone;
unsigned int dllrdy;
regmap_write(rk_phy->reg_base,
rk_phy->reg_offset + GRF_EMMCPHY_CON6,
HIWORD_UPDATE(PHYCTRL_PDB_PWR_OFF,
PHYCTRL_PDB_MASK,
PHYCTRL_PDB_SHIFT));
regmap_write(rk_phy->reg_base,
rk_phy->reg_offset + GRF_EMMCPHY_CON6,
HIWORD_UPDATE(PHYCTRL_ENDLL_DISABLE,
PHYCTRL_ENDLL_MASK,
PHYCTRL_ENDLL_SHIFT));
if (on_off == PHYCTRL_PDB_PWR_OFF)
return 0;
udelay(3);
regmap_write(rk_phy->reg_base,
rk_phy->reg_offset + GRF_EMMCPHY_CON6,
HIWORD_UPDATE(PHYCTRL_PDB_PWR_ON,
PHYCTRL_PDB_MASK,
PHYCTRL_PDB_SHIFT));
udelay(5);
regmap_read(rk_phy->reg_base,
rk_phy->reg_offset + GRF_EMMCPHY_STATUS,
&caldone);
caldone = (caldone >> PHYCTRL_CALDONE_SHIFT) & PHYCTRL_CALDONE_MASK;
if (caldone != PHYCTRL_CALDONE_DONE) {
pr_err("rockchip_emmc_phy_power: caldone timeout.\n");
return -ETIMEDOUT;
}
regmap_write(rk_phy->reg_base,
rk_phy->reg_offset + GRF_EMMCPHY_CON6,
HIWORD_UPDATE(PHYCTRL_ENDLL_ENABLE,
PHYCTRL_ENDLL_MASK,
PHYCTRL_ENDLL_SHIFT));
udelay(11);
regmap_read(rk_phy->reg_base,
rk_phy->reg_offset + GRF_EMMCPHY_STATUS,
&dllrdy);
dllrdy = (dllrdy >> PHYCTRL_DLLRDY_SHIFT) & PHYCTRL_DLLRDY_MASK;
if (dllrdy != PHYCTRL_DLLRDY_DONE) {
pr_err("rockchip_emmc_phy_power: dllrdy timeout.\n");
return -ETIMEDOUT;
}
return 0;
}
static int rockchip_emmc_phy_power_off(struct phy *phy)
{
struct rockchip_emmc_phy *rk_phy = phy_get_drvdata(phy);
int ret = 0;
ret = rockchip_emmc_phy_power(rk_phy, PHYCTRL_PDB_PWR_OFF);
if (ret)
return ret;
return 0;
}
static int rockchip_emmc_phy_power_on(struct phy *phy)
{
struct rockchip_emmc_phy *rk_phy = phy_get_drvdata(phy);
int ret = 0;
ret = rockchip_emmc_phy_power(rk_phy, PHYCTRL_PDB_PWR_ON);
if (ret)
return ret;
return 0;
}
static int rockchip_emmc_phy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rockchip_emmc_phy *rk_phy;
struct phy *generic_phy;
struct phy_provider *phy_provider;
struct regmap *grf;
unsigned int reg_offset;
if (!dev->parent || !dev->parent->of_node)
return -ENODEV;
grf = syscon_node_to_regmap(dev->parent->of_node);
if (IS_ERR(grf)) {
dev_err(dev, "Missing rockchip,grf property\n");
return PTR_ERR(grf);
}
rk_phy = devm_kzalloc(dev, sizeof(*rk_phy), GFP_KERNEL);
if (!rk_phy)
return -ENOMEM;
if (of_property_read_u32(dev->of_node, "reg", &reg_offset)) {
dev_err(dev, "missing reg property in node %s\n",
dev->of_node->name);
return -EINVAL;
}
rk_phy->reg_offset = reg_offset;
rk_phy->reg_base = grf;
generic_phy = devm_phy_create(dev, dev->of_node, &ops);
if (IS_ERR(generic_phy)) {
dev_err(dev, "failed to create PHY\n");
return PTR_ERR(generic_phy);
}
phy_set_drvdata(generic_phy, rk_phy);
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
