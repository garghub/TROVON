static int rockchip_emmc_phy_power(struct phy *phy, bool on_off)
{
struct rockchip_emmc_phy *rk_phy = phy_get_drvdata(phy);
unsigned int caldone;
unsigned int dllrdy;
unsigned int freqsel = PHYCTRL_FREQSEL_200M;
unsigned long rate;
unsigned long timeout;
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
rate = clk_get_rate(rk_phy->emmcclk);
if (rate != 0) {
unsigned long ideal_rate;
unsigned long diff;
switch (rate) {
case 1 ... 74999999:
ideal_rate = 50000000;
freqsel = PHYCTRL_FREQSEL_50M;
break;
case 75000000 ... 124999999:
ideal_rate = 100000000;
freqsel = PHYCTRL_FREQSEL_100M;
break;
case 125000000 ... 174999999:
ideal_rate = 150000000;
freqsel = PHYCTRL_FREQSEL_150M;
break;
default:
ideal_rate = 200000000;
break;
};
diff = (rate > ideal_rate) ?
rate - ideal_rate : ideal_rate - rate;
if ((rate > 50000000 && diff > 15000000) || (rate > 200000000))
dev_warn(&phy->dev, "Unsupported rate: %lu\n", rate);
}
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
rk_phy->reg_offset + GRF_EMMCPHY_CON0,
HIWORD_UPDATE(freqsel, PHYCTRL_FREQSEL_MASK,
PHYCTRL_FREQSEL_SHIFT));
regmap_write(rk_phy->reg_base,
rk_phy->reg_offset + GRF_EMMCPHY_CON6,
HIWORD_UPDATE(PHYCTRL_ENDLL_ENABLE,
PHYCTRL_ENDLL_MASK,
PHYCTRL_ENDLL_SHIFT));
if (rate == 0)
return 0;
timeout = jiffies + msecs_to_jiffies(50);
do {
udelay(1);
regmap_read(rk_phy->reg_base,
rk_phy->reg_offset + GRF_EMMCPHY_STATUS,
&dllrdy);
dllrdy = (dllrdy >> PHYCTRL_DLLRDY_SHIFT) & PHYCTRL_DLLRDY_MASK;
if (dllrdy == PHYCTRL_DLLRDY_DONE)
break;
} while (!time_after(jiffies, timeout));
if (dllrdy != PHYCTRL_DLLRDY_DONE) {
pr_err("rockchip_emmc_phy_power: dllrdy timeout.\n");
return -ETIMEDOUT;
}
return 0;
}
static int rockchip_emmc_phy_init(struct phy *phy)
{
struct rockchip_emmc_phy *rk_phy = phy_get_drvdata(phy);
int ret = 0;
rk_phy->emmcclk = clk_get(&phy->dev, "emmcclk");
if (IS_ERR(rk_phy->emmcclk)) {
dev_dbg(&phy->dev, "Error getting emmcclk: %d\n", ret);
rk_phy->emmcclk = NULL;
}
return ret;
}
static int rockchip_emmc_phy_exit(struct phy *phy)
{
struct rockchip_emmc_phy *rk_phy = phy_get_drvdata(phy);
clk_put(rk_phy->emmcclk);
return 0;
}
static int rockchip_emmc_phy_power_off(struct phy *phy)
{
return rockchip_emmc_phy_power(phy, PHYCTRL_PDB_PWR_OFF);
}
static int rockchip_emmc_phy_power_on(struct phy *phy)
{
struct rockchip_emmc_phy *rk_phy = phy_get_drvdata(phy);
regmap_write(rk_phy->reg_base,
rk_phy->reg_offset + GRF_EMMCPHY_CON6,
HIWORD_UPDATE(PHYCTRL_DR_50OHM,
PHYCTRL_DR_MASK,
PHYCTRL_DR_SHIFT));
regmap_write(rk_phy->reg_base,
rk_phy->reg_offset + GRF_EMMCPHY_CON0,
HIWORD_UPDATE(PHYCTRL_OTAPDLYENA,
PHYCTRL_OTAPDLYENA_MASK,
PHYCTRL_OTAPDLYENA_SHIFT));
regmap_write(rk_phy->reg_base,
rk_phy->reg_offset + GRF_EMMCPHY_CON0,
HIWORD_UPDATE(4,
PHYCTRL_OTAPDLYSEL_MASK,
PHYCTRL_OTAPDLYSEL_SHIFT));
return rockchip_emmc_phy_power(phy, PHYCTRL_PDB_PWR_ON);
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
