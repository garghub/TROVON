static int miphy365x_set_path(struct miphy365x_phy *miphy_phy,
struct miphy365x_dev *miphy_dev)
{
bool sata = (miphy_phy->type == PHY_TYPE_SATA);
return regmap_update_bits(miphy_dev->regmap,
miphy_phy->ctrlreg,
SYSCFG_SELECT_SATA_MASK,
sata << SYSCFG_SELECT_SATA_POS);
}
static int miphy365x_init_pcie_port(struct miphy365x_phy *miphy_phy,
struct miphy365x_dev *miphy_dev)
{
u8 val;
if (miphy_phy->pcie_tx_pol_inv) {
val = TERM_EN | PCI_EN | DES_BIT_LOCK_EN | TX_POL;
writeb_relaxed(val, miphy_phy->base + CTRL_REG);
writeb_relaxed(0x00, miphy_phy->base + PCIE_REG);
}
return 0;
}
static inline int miphy365x_hfc_not_rdy(struct miphy365x_phy *miphy_phy,
struct miphy365x_dev *miphy_dev)
{
unsigned long timeout = jiffies + msecs_to_jiffies(HFC_TIMEOUT);
u8 mask = IDLL_RDY | PLL_RDY;
u8 regval;
do {
regval = readb_relaxed(miphy_phy->base + STATUS_REG);
if (!(regval & mask))
return 0;
usleep_range(2000, 2500);
} while (time_before(jiffies, timeout));
dev_err(miphy_dev->dev, "HFC ready timeout!\n");
return -EBUSY;
}
static inline int miphy365x_rdy(struct miphy365x_phy *miphy_phy,
struct miphy365x_dev *miphy_dev)
{
unsigned long timeout = jiffies + msecs_to_jiffies(HFC_TIMEOUT);
u8 mask = IDLL_RDY | PLL_RDY;
u8 regval;
do {
regval = readb_relaxed(miphy_phy->base + STATUS_REG);
if ((regval & mask) == mask)
return 0;
usleep_range(2000, 2500);
} while (time_before(jiffies, timeout));
dev_err(miphy_dev->dev, "PHY not ready timeout!\n");
return -EBUSY;
}
static inline void miphy365x_set_comp(struct miphy365x_phy *miphy_phy,
struct miphy365x_dev *miphy_dev)
{
u8 val, mask;
if (miphy_phy->sata_gen == SATA_GEN1)
writeb_relaxed(COMP_2MHZ_RAT_GEN1,
miphy_phy->base + COMP_CTRL2_REG);
else
writeb_relaxed(COMP_2MHZ_RAT,
miphy_phy->base + COMP_CTRL2_REG);
if (miphy_phy->sata_gen != SATA_GEN3) {
writeb_relaxed(COMSR_COMP_REF,
miphy_phy->base + COMP_CTRL3_REG);
writeb_relaxed(BYPASS_PLL_CAL, miphy_phy->base + PLL_CTRL2_REG);
writeb_relaxed(COMZC_IDLL, miphy_phy->base + COMP_IDLL_REG);
}
val = START_COMSR | START_COMZC | COMP_AUTO_LOAD;
writeb_relaxed(val, miphy_phy->base + COMP_CTRL1_REG);
mask = COMSR_DONE | COMZC_DONE;
while ((readb_relaxed(miphy_phy->base + COMP_CTRL1_REG) & mask) != mask)
cpu_relax();
}
static inline void miphy365x_set_ssc(struct miphy365x_phy *miphy_phy,
struct miphy365x_dev *miphy_dev)
{
u8 val;
writeb_relaxed(PLL_SSC_STEP_MSB_VAL,
miphy_phy->base + PLL_SSC_STEP_MSB_REG);
writeb_relaxed(PLL_SSC_STEP_LSB_VAL,
miphy_phy->base + PLL_SSC_STEP_LSB_REG);
writeb_relaxed(PLL_SSC_PER_MSB_VAL,
miphy_phy->base + PLL_SSC_PER_MSB_REG);
writeb_relaxed(PLL_SSC_PER_LSB_VAL,
miphy_phy->base + PLL_SSC_PER_LSB_REG);
if (miphy_phy->sata_gen == SATA_GEN1) {
val = PLL_START_CAL | BUF_EN | SYNCHRO_TX | CONFIG_PLL;
writeb_relaxed(val, miphy_phy->base + PLL_CTRL1_REG);
} else {
val = SSC_EN | PLL_START_CAL | BUF_EN | SYNCHRO_TX | CONFIG_PLL;
writeb_relaxed(val, miphy_phy->base + PLL_CTRL1_REG);
}
}
static int miphy365x_init_sata_port(struct miphy365x_phy *miphy_phy,
struct miphy365x_dev *miphy_dev)
{
int ret;
u8 val;
val = RST_PLL | RST_PLL_CAL | RST_RX | RST_MACRO;
writeb_relaxed(val, miphy_phy->base + RESET_REG);
if (miphy_phy->sata_tx_pol_inv)
writeb_relaxed(TX_POL, miphy_phy->base + CTRL_REG);
writeb_relaxed(SPDSEL_SEL, miphy_phy->base + BOUNDARY1_REG);
writeb_relaxed(START_CLK_HF, miphy_phy->base + IDLL_TEST_REG);
val = rx_tx_spd[miphy_phy->sata_gen];
writeb_relaxed(val, miphy_phy->base + BOUNDARY3_REG);
ret = miphy365x_hfc_not_rdy(miphy_phy, miphy_dev);
if (ret)
return ret;
miphy365x_set_comp(miphy_phy, miphy_dev);
switch (miphy_phy->sata_gen) {
case SATA_GEN3:
val = PD_VDDTFILTER | CONF_GEN_SEL_GEN3;
writeb_relaxed(val, miphy_phy->base + BUF_SEL_REG);
val = SWING_VAL | PREEMPH_VAL;
writeb_relaxed(val, miphy_phy->base + TXBUF1_REG);
writeb_relaxed(TXSLEW_VAL, miphy_phy->base + TXBUF2_REG);
writeb_relaxed(0x00, miphy_phy->base + RXBUF_OFFSET_CTRL_REG);
val = SDTHRES_VAL | EQ_ON3;
writeb_relaxed(val, miphy_phy->base + RXBUF_REG);
break;
case SATA_GEN2:
writeb_relaxed(CONF_GEN_SEL_GEN2,
miphy_phy->base + BUF_SEL_REG);
writeb_relaxed(SWING_VAL, miphy_phy->base + TXBUF1_REG);
writeb_relaxed(TXSLEW_VAL, miphy_phy->base + TXBUF2_REG);
val = SDTHRES_VAL | EQ_ON1;
writeb_relaxed(val, miphy_phy->base + RXBUF_REG);
break;
case SATA_GEN1:
writeb_relaxed(PD_VDDTFILTER, miphy_phy->base + BUF_SEL_REG);
writeb_relaxed(SWING_VAL_GEN1, miphy_phy->base + TXBUF1_REG);
writeb_relaxed(TXSLEW_VAL_GEN1, miphy_phy->base + TXBUF2_REG);
break;
default:
break;
}
writeb_relaxed(RST_RX, miphy_phy->base + RESET_REG);
usleep_range(100, 150);
miphy365x_set_ssc(miphy_phy, miphy_dev);
ret = miphy365x_rdy(miphy_phy, miphy_dev);
if (ret)
return ret;
writeb_relaxed(0x00, miphy_phy->base + BOUNDARY1_REG);
writeb_relaxed(0x00, miphy_phy->base + IDLL_TEST_REG);
writeb_relaxed(RST_RX, miphy_phy->base + RESET_REG);
val = miphy_phy->sata_tx_pol_inv ?
(TX_POL | DES_BIT_LOCK_EN) : DES_BIT_LOCK_EN;
writeb_relaxed(val, miphy_phy->base + CTRL_REG);
val = BIT_LOCK_CNT_512 | BIT_LOCK_LEVEL;
writeb_relaxed(val, miphy_phy->base + DES_BITLOCK_REG);
writeb_relaxed(0x00, miphy_phy->base + RESET_REG);
return 0;
}
static int miphy365x_init(struct phy *phy)
{
struct miphy365x_phy *miphy_phy = phy_get_drvdata(phy);
struct miphy365x_dev *miphy_dev = dev_get_drvdata(phy->dev.parent);
int ret = 0;
mutex_lock(&miphy_dev->miphy_mutex);
ret = miphy365x_set_path(miphy_phy, miphy_dev);
if (ret) {
mutex_unlock(&miphy_dev->miphy_mutex);
return ret;
}
if (miphy_phy->type == PHY_TYPE_PCIE)
ret = miphy365x_init_pcie_port(miphy_phy, miphy_dev);
else
ret = miphy365x_init_sata_port(miphy_phy, miphy_dev);
mutex_unlock(&miphy_dev->miphy_mutex);
return ret;
}
int miphy365x_get_addr(struct device *dev, struct miphy365x_phy *miphy_phy,
int index)
{
struct device_node *phynode = miphy_phy->phy->dev.of_node;
const char *name;
int type = miphy_phy->type;
int ret;
ret = of_property_read_string_index(phynode, "reg-names", index, &name);
if (ret) {
dev_err(dev, "no reg-names property not found\n");
return ret;
}
if (!((!strncmp(name, "sata", 4) && type == PHY_TYPE_SATA) ||
(!strncmp(name, "pcie", 4) && type == PHY_TYPE_PCIE)))
return 0;
miphy_phy->base = of_iomap(phynode, index);
if (!miphy_phy->base) {
dev_err(dev, "Failed to map %s\n", phynode->full_name);
return -EINVAL;
}
return 0;
}
static struct phy *miphy365x_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct miphy365x_dev *miphy_dev = dev_get_drvdata(dev);
struct miphy365x_phy *miphy_phy = NULL;
struct device_node *phynode = args->np;
int ret, index;
if (!of_device_is_available(phynode)) {
dev_warn(dev, "Requested PHY is disabled\n");
return ERR_PTR(-ENODEV);
}
if (args->args_count != 1) {
dev_err(dev, "Invalid number of cells in 'phy' property\n");
return ERR_PTR(-EINVAL);
}
for (index = 0; index < miphy_dev->nphys; index++)
if (phynode == miphy_dev->phys[index]->phy->dev.of_node) {
miphy_phy = miphy_dev->phys[index];
break;
}
if (!miphy_phy) {
dev_err(dev, "Failed to find appropriate phy\n");
return ERR_PTR(-EINVAL);
}
miphy_phy->type = args->args[0];
if (!(miphy_phy->type == PHY_TYPE_SATA ||
miphy_phy->type == PHY_TYPE_PCIE)) {
dev_err(dev, "Unsupported device type: %d\n", miphy_phy->type);
return ERR_PTR(-EINVAL);
}
for (index = 0; index < 3; index++) {
ret = miphy365x_get_addr(dev, miphy_phy, index);
if (ret < 0)
return ERR_PTR(ret);
}
return miphy_phy->phy;
}
static int miphy365x_of_probe(struct device_node *phynode,
struct miphy365x_phy *miphy_phy)
{
of_property_read_u32(phynode, "st,sata-gen", &miphy_phy->sata_gen);
if (!miphy_phy->sata_gen)
miphy_phy->sata_gen = SATA_GEN1;
miphy_phy->pcie_tx_pol_inv =
of_property_read_bool(phynode, "st,pcie-tx-pol-inv");
miphy_phy->sata_tx_pol_inv =
of_property_read_bool(phynode, "st,sata-tx-pol-inv");
return 0;
}
static int miphy365x_probe(struct platform_device *pdev)
{
struct device_node *child, *np = pdev->dev.of_node;
struct miphy365x_dev *miphy_dev;
struct phy_provider *provider;
struct phy *phy;
int ret, port = 0;
miphy_dev = devm_kzalloc(&pdev->dev, sizeof(*miphy_dev), GFP_KERNEL);
if (!miphy_dev)
return -ENOMEM;
miphy_dev->nphys = of_get_child_count(np);
miphy_dev->phys = devm_kcalloc(&pdev->dev, miphy_dev->nphys,
sizeof(*miphy_dev->phys), GFP_KERNEL);
if (!miphy_dev->phys)
return -ENOMEM;
miphy_dev->regmap = syscon_regmap_lookup_by_phandle(np, "st,syscfg");
if (IS_ERR(miphy_dev->regmap)) {
dev_err(miphy_dev->dev, "No syscfg phandle specified\n");
return PTR_ERR(miphy_dev->regmap);
}
miphy_dev->dev = &pdev->dev;
dev_set_drvdata(&pdev->dev, miphy_dev);
mutex_init(&miphy_dev->miphy_mutex);
for_each_child_of_node(np, child) {
struct miphy365x_phy *miphy_phy;
miphy_phy = devm_kzalloc(&pdev->dev, sizeof(*miphy_phy),
GFP_KERNEL);
if (!miphy_phy)
return -ENOMEM;
miphy_dev->phys[port] = miphy_phy;
phy = devm_phy_create(&pdev->dev, child, &miphy365x_ops);
if (IS_ERR(phy)) {
dev_err(&pdev->dev, "failed to create PHY\n");
return PTR_ERR(phy);
}
miphy_dev->phys[port]->phy = phy;
ret = miphy365x_of_probe(child, miphy_phy);
if (ret)
return ret;
phy_set_drvdata(phy, miphy_dev->phys[port]);
port++;
ret = of_property_read_u32_index(np, "st,syscfg", port,
&miphy_phy->ctrlreg);
if (ret) {
dev_err(&pdev->dev, "No sysconfig offset found\n");
return ret;
}
}
provider = devm_of_phy_provider_register(&pdev->dev, miphy365x_xlate);
return PTR_ERR_OR_ZERO(provider);
}
