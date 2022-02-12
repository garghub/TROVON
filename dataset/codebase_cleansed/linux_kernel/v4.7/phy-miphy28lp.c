static inline void miphy28lp_set_reset(struct miphy28lp_phy *miphy_phy)
{
void __iomem *base = miphy_phy->base;
u8 val;
writeb_relaxed(RST_APPLI_SW, base + MIPHY_CONF_RESET);
val = RST_APPLI_SW | RST_CONF_SW;
writeb_relaxed(val, base + MIPHY_CONF_RESET);
writeb_relaxed(RST_APPLI_SW, base + MIPHY_CONF_RESET);
if (miphy_phy->type == PHY_TYPE_PCIE) {
val = AUTO_RST_RX | TERM_EN_SW;
writeb_relaxed(val, base + MIPHY_CONTROL);
} else {
val = AUTO_RST_RX | TERM_EN_SW | DIS_LINK_RST;
writeb_relaxed(val, base + MIPHY_CONTROL);
}
}
static inline void miphy28lp_pll_calibration(struct miphy28lp_phy *miphy_phy,
struct pll_ratio *pll_ratio)
{
void __iomem *base = miphy_phy->base;
u8 val;
writeb_relaxed(0x1d, base + MIPHY_PLL_SPAREIN);
writeb_relaxed(pll_ratio->clk_ref, base + MIPHY_PLL_CLKREF_FREQ);
writeb_relaxed(pll_ratio->calset_1, base + MIPHY_PLL_CALSET_1);
writeb_relaxed(pll_ratio->calset_2, base + MIPHY_PLL_CALSET_2);
writeb_relaxed(pll_ratio->calset_3, base + MIPHY_PLL_CALSET_3);
writeb_relaxed(pll_ratio->calset_4, base + MIPHY_PLL_CALSET_4);
writeb_relaxed(pll_ratio->cal_ctrl, base + MIPHY_PLL_CALSET_CTRL);
writeb_relaxed(TX_SEL, base + MIPHY_BOUNDARY_SEL);
val = (0x68 << 1) | TX_SLEW_CAL_MAN_EN;
writeb_relaxed(val, base + MIPHY_TX_CAL_MAN);
val = VGA_OFFSET_POLARITY | CAL_OFFSET_THRESHOLD_64 | CAL_OFFSET_VGA_64;
if (miphy_phy->type != PHY_TYPE_SATA)
val |= OFFSET_COMPENSATION_EN;
writeb_relaxed(val, base + MIPHY_RX_CAL_OFFSET_CTRL);
if (miphy_phy->type == PHY_TYPE_USB3) {
writeb_relaxed(0x00, base + MIPHY_CONF);
writeb_relaxed(0x70, base + MIPHY_RX_LOCK_STEP);
writeb_relaxed(EN_FIRST_HALF, base + MIPHY_RX_SIGDET_SLEEP_OA);
writeb_relaxed(EN_FIRST_HALF, base + MIPHY_RX_SIGDET_SLEEP_SEL);
writeb_relaxed(EN_FIRST_HALF, base + MIPHY_RX_SIGDET_WAIT_SEL);
val = EN_DIGIT_SIGNAL_CHECK | EN_FIRST_HALF;
writeb_relaxed(val, base + MIPHY_RX_SIGDET_DATA_SEL);
}
}
static inline void miphy28lp_sata_config_gen(struct miphy28lp_phy *miphy_phy)
{
void __iomem *base = miphy_phy->base;
int i;
for (i = 0; i < ARRAY_SIZE(sata_pll_gen); i++) {
struct miphy28lp_pll_gen *gen = &sata_pll_gen[i];
writeb_relaxed(gen->bank, base + MIPHY_CONF);
writeb_relaxed(gen->speed, base + MIPHY_SPEED);
writeb_relaxed(gen->bias_boost_1, base + MIPHY_BIAS_BOOST_1);
writeb_relaxed(gen->bias_boost_2, base + MIPHY_BIAS_BOOST_2);
writeb_relaxed(gen->tx_ctrl_2, base + MIPHY_TX_CTRL_2);
writeb_relaxed(gen->tx_ctrl_3, base + MIPHY_TX_CTRL_3);
writeb_relaxed(gen->rx_buff_ctrl, base + MIPHY_RX_BUFFER_CTRL);
writeb_relaxed(gen->rx_vga_gain, base + MIPHY_RX_VGA_GAIN);
writeb_relaxed(gen->rx_equ_gain_1, base + MIPHY_RX_EQU_GAIN_1);
writeb_relaxed(gen->rx_equ_gain_2, base + MIPHY_RX_EQU_GAIN_2);
writeb_relaxed(gen->rx_equ_gain_3, base + MIPHY_RX_EQU_GAIN_3);
}
}
static inline void miphy28lp_pcie_config_gen(struct miphy28lp_phy *miphy_phy)
{
void __iomem *base = miphy_phy->base;
int i;
for (i = 0; i < ARRAY_SIZE(pcie_pll_gen); i++) {
struct miphy28lp_pll_gen *gen = &pcie_pll_gen[i];
writeb_relaxed(gen->bank, base + MIPHY_CONF);
writeb_relaxed(gen->speed, base + MIPHY_SPEED);
writeb_relaxed(gen->bias_boost_1, base + MIPHY_BIAS_BOOST_1);
writeb_relaxed(gen->bias_boost_2, base + MIPHY_BIAS_BOOST_2);
writeb_relaxed(gen->tx_ctrl_1, base + MIPHY_TX_CTRL_1);
writeb_relaxed(gen->tx_ctrl_2, base + MIPHY_TX_CTRL_2);
writeb_relaxed(gen->tx_ctrl_3, base + MIPHY_TX_CTRL_3);
writeb_relaxed(gen->rx_k_gain, base + MIPHY_RX_K_GAIN);
writeb_relaxed(gen->rx_buff_ctrl, base + MIPHY_RX_BUFFER_CTRL);
writeb_relaxed(gen->rx_vga_gain, base + MIPHY_RX_VGA_GAIN);
writeb_relaxed(gen->rx_equ_gain_1, base + MIPHY_RX_EQU_GAIN_1);
writeb_relaxed(gen->rx_equ_gain_2, base + MIPHY_RX_EQU_GAIN_2);
}
}
static inline int miphy28lp_wait_compensation(struct miphy28lp_phy *miphy_phy)
{
unsigned long finish = jiffies + 5 * HZ;
u8 val;
do {
val = readb_relaxed(miphy_phy->base + MIPHY_COMP_FSM_6);
if (time_after_eq(jiffies, finish))
return -EBUSY;
cpu_relax();
} while (!(val & COMP_DONE));
return 0;
}
static inline int miphy28lp_compensation(struct miphy28lp_phy *miphy_phy,
struct pll_ratio *pll_ratio)
{
void __iomem *base = miphy_phy->base;
writeb_relaxed(RST_PLL_SW | RST_COMP_SW, base + MIPHY_RESET);
writeb_relaxed(0x00, base + MIPHY_PLL_COMMON_MISC_2);
writeb_relaxed(pll_ratio->clk_ref, base + MIPHY_PLL_CLKREF_FREQ);
writeb_relaxed(COMP_START, base + MIPHY_COMP_FSM_1);
if (miphy_phy->type == PHY_TYPE_PCIE)
writeb_relaxed(RST_PLL_SW, base + MIPHY_RESET);
writeb_relaxed(0x00, base + MIPHY_RESET);
writeb_relaxed(START_ACT_FILT, base + MIPHY_PLL_COMMON_MISC_2);
writeb_relaxed(SET_NEW_CHANGE, base + MIPHY_PLL_SBR_1);
writeb_relaxed(0x00, base + MIPHY_COMP_POSTP);
if (miphy_phy->type == PHY_TYPE_PCIE)
return miphy28lp_wait_compensation(miphy_phy);
return 0;
}
static inline void miphy28_usb3_miphy_reset(struct miphy28lp_phy *miphy_phy)
{
void __iomem *base = miphy_phy->base;
u8 val;
writeb_relaxed(RST_APPLI_SW, base + MIPHY_CONF_RESET);
writeb_relaxed(0x00, base + MIPHY_CONF_RESET);
writeb_relaxed(RST_COMP_SW, base + MIPHY_RESET);
val = RST_COMP_SW | RST_PLL_SW;
writeb_relaxed(val, base + MIPHY_RESET);
writeb_relaxed(0x00, base + MIPHY_PLL_COMMON_MISC_2);
writeb_relaxed(0x1e, base + MIPHY_PLL_CLKREF_FREQ);
writeb_relaxed(COMP_START, base + MIPHY_COMP_FSM_1);
writeb_relaxed(RST_PLL_SW, base + MIPHY_RESET);
writeb_relaxed(0x00, base + MIPHY_RESET);
writeb_relaxed(START_ACT_FILT, base + MIPHY_PLL_COMMON_MISC_2);
writeb_relaxed(0x00, base + MIPHY_CONF);
writeb_relaxed(0x00, base + MIPHY_BOUNDARY_1);
writeb_relaxed(0x00, base + MIPHY_TST_BIAS_BOOST_2);
writeb_relaxed(0x00, base + MIPHY_CONF);
writeb_relaxed(SET_NEW_CHANGE, base + MIPHY_PLL_SBR_1);
writeb_relaxed(0xa5, base + MIPHY_DEBUG_BUS);
writeb_relaxed(0x00, base + MIPHY_CONF);
}
static void miphy_sata_tune_ssc(struct miphy28lp_phy *miphy_phy)
{
void __iomem *base = miphy_phy->base;
u8 val;
val = readb_relaxed(base + MIPHY_BOUNDARY_2);
val |= SSC_EN_SW;
writeb_relaxed(val, base + MIPHY_BOUNDARY_2);
val = readb_relaxed(base + MIPHY_BOUNDARY_SEL);
val |= SSC_SEL;
writeb_relaxed(val, base + MIPHY_BOUNDARY_SEL);
for (val = 0; val < MIPHY_SATA_BANK_NB; val++) {
writeb_relaxed(val, base + MIPHY_CONF);
writeb_relaxed(0x3c, base + MIPHY_PLL_SBR_2);
writeb_relaxed(0x6c, base + MIPHY_PLL_SBR_3);
writeb_relaxed(0x81, base + MIPHY_PLL_SBR_4);
writeb_relaxed(0x00, base + MIPHY_PLL_SBR_1);
writeb_relaxed(SET_NEW_CHANGE, base + MIPHY_PLL_SBR_1);
writeb_relaxed(0x00, base + MIPHY_PLL_SBR_1);
}
}
static void miphy_pcie_tune_ssc(struct miphy28lp_phy *miphy_phy)
{
void __iomem *base = miphy_phy->base;
u8 val;
val = readb_relaxed(base + MIPHY_BOUNDARY_2);
val |= SSC_EN_SW;
writeb_relaxed(val, base + MIPHY_BOUNDARY_2);
val = readb_relaxed(base + MIPHY_BOUNDARY_SEL);
val |= SSC_SEL;
writeb_relaxed(val, base + MIPHY_BOUNDARY_SEL);
for (val = 0; val < MIPHY_PCIE_BANK_NB; val++) {
writeb_relaxed(val, base + MIPHY_CONF);
writeb_relaxed(0x69, base + MIPHY_PLL_SBR_3);
writeb_relaxed(0x21, base + MIPHY_PLL_SBR_4);
writeb_relaxed(0x3c, base + MIPHY_PLL_SBR_2);
writeb_relaxed(0x21, base + MIPHY_PLL_SBR_4);
writeb_relaxed(0x00, base + MIPHY_PLL_SBR_1);
writeb_relaxed(SET_NEW_CHANGE, base + MIPHY_PLL_SBR_1);
writeb_relaxed(0x00, base + MIPHY_PLL_SBR_1);
}
}
static inline void miphy_tune_tx_impedance(struct miphy28lp_phy *miphy_phy)
{
writeb_relaxed(0x02, miphy_phy->base + MIPHY_COMP_POSTP);
}
static inline int miphy28lp_configure_sata(struct miphy28lp_phy *miphy_phy)
{
void __iomem *base = miphy_phy->base;
int err;
u8 val;
miphy28lp_set_reset(miphy_phy);
miphy28lp_pll_calibration(miphy_phy, &sata_pll_ratio);
miphy28lp_sata_config_gen(miphy_phy);
writeb_relaxed(0x21, base + MIPHY_RX_POWER_CTRL_1);
writeb_relaxed(0x00, base + MIPHY_CONF_RESET);
err = miphy28lp_compensation(miphy_phy, &sata_pll_ratio);
if (err)
return err;
if (miphy_phy->px_rx_pol_inv) {
val = readb_relaxed(miphy_phy->base + MIPHY_CONTROL);
val |= PX_RX_POL;
writeb_relaxed(val, miphy_phy->base + MIPHY_CONTROL);
}
if (miphy_phy->ssc)
miphy_sata_tune_ssc(miphy_phy);
if (miphy_phy->tx_impedance)
miphy_tune_tx_impedance(miphy_phy);
return 0;
}
static inline int miphy28lp_configure_pcie(struct miphy28lp_phy *miphy_phy)
{
void __iomem *base = miphy_phy->base;
int err;
miphy28lp_set_reset(miphy_phy);
miphy28lp_pll_calibration(miphy_phy, &pcie_pll_ratio);
miphy28lp_pcie_config_gen(miphy_phy);
writeb_relaxed(0x21, base + MIPHY_RX_POWER_CTRL_1);
writeb_relaxed(0x00, base + MIPHY_CONF_RESET);
err = miphy28lp_compensation(miphy_phy, &pcie_pll_ratio);
if (err)
return err;
if (miphy_phy->ssc)
miphy_pcie_tune_ssc(miphy_phy);
if (miphy_phy->tx_impedance)
miphy_tune_tx_impedance(miphy_phy);
return 0;
}
static inline void miphy28lp_configure_usb3(struct miphy28lp_phy *miphy_phy)
{
void __iomem *base = miphy_phy->base;
u8 val;
miphy28lp_set_reset(miphy_phy);
miphy28lp_pll_calibration(miphy_phy, &usb3_pll_ratio);
writeb_relaxed(0x00, base + MIPHY_CONF);
val = RX_SPDSEL_20DEC | TX_SPDSEL_20DEC;
writeb_relaxed(val, base + MIPHY_SPEED);
writeb_relaxed(0x1c, base + MIPHY_RX_LOCK_SETTINGS_OPT);
writeb_relaxed(0x51, base + MIPHY_RX_CAL_CTRL_1);
writeb_relaxed(0x70, base + MIPHY_RX_CAL_CTRL_2);
val = OFFSET_COMPENSATION_EN | VGA_OFFSET_POLARITY |
CAL_OFFSET_THRESHOLD_64 | CAL_OFFSET_VGA_64;
writeb_relaxed(val, base + MIPHY_RX_CAL_OFFSET_CTRL);
writeb_relaxed(0x22, base + MIPHY_RX_CAL_VGA_STEP);
writeb_relaxed(0x0e, base + MIPHY_RX_CAL_OPT_LENGTH);
val = EQ_DC_GAIN | VGA_GAIN;
writeb_relaxed(val, base + MIPHY_RX_BUFFER_CTRL);
writeb_relaxed(0x78, base + MIPHY_RX_EQU_GAIN_1);
writeb_relaxed(0x1b, base + MIPHY_SYNCHAR_CONTROL);
writeb_relaxed(0x02, base + MIPHY_COMP_POSTP);
val = SSC_SEL | GENSEL_SEL;
writeb_relaxed(val, base + MIPHY_BOUNDARY_SEL);
writeb_relaxed(0x00, base + MIPHY_BIAS_BOOST_1);
writeb_relaxed(0xa7, base + MIPHY_BIAS_BOOST_2);
writeb_relaxed(SSC_EN_SW, base + MIPHY_BOUNDARY_2);
writeb_relaxed(0x00, base + MIPHY_CONF);
writeb_relaxed(0x5a, base + MIPHY_PLL_SBR_3);
writeb_relaxed(0xa0, base + MIPHY_PLL_SBR_4);
writeb_relaxed(0x3c, base + MIPHY_PLL_SBR_2);
writeb_relaxed(0xa1, base + MIPHY_PLL_SBR_4);
writeb_relaxed(0x00, base + MIPHY_PLL_SBR_1);
writeb_relaxed(0x02, base + MIPHY_PLL_SBR_1);
writeb_relaxed(0x00, base + MIPHY_PLL_SBR_1);
writeb_relaxed(0xca, base + MIPHY_RX_K_GAIN);
writeb_relaxed(0x21, base + MIPHY_RX_POWER_CTRL_1);
writeb_relaxed(0x29, base + MIPHY_RX_POWER_CTRL_1);
writeb_relaxed(0x1a, base + MIPHY_RX_POWER_CTRL_2);
miphy28_usb3_miphy_reset(miphy_phy);
}
static inline int miphy_is_ready(struct miphy28lp_phy *miphy_phy)
{
unsigned long finish = jiffies + 5 * HZ;
u8 mask = HFC_PLL | HFC_RDY;
u8 val;
if (miphy_phy->type == PHY_TYPE_SATA)
mask |= PHY_RDY;
do {
val = readb_relaxed(miphy_phy->base + MIPHY_STATUS_1);
if ((val & mask) != mask)
cpu_relax();
else
return 0;
} while (!time_after_eq(jiffies, finish));
return -EBUSY;
}
static int miphy_osc_is_ready(struct miphy28lp_phy *miphy_phy)
{
struct miphy28lp_dev *miphy_dev = miphy_phy->phydev;
unsigned long finish = jiffies + 5 * HZ;
u32 val;
if (!miphy_phy->osc_rdy)
return 0;
if (!miphy_phy->syscfg_reg[SYSCFG_STATUS])
return -EINVAL;
do {
regmap_read(miphy_dev->regmap,
miphy_phy->syscfg_reg[SYSCFG_STATUS], &val);
if ((val & MIPHY_OSC_RDY) != MIPHY_OSC_RDY)
cpu_relax();
else
return 0;
} while (!time_after_eq(jiffies, finish));
return -EBUSY;
}
static int miphy28lp_get_resource_byname(struct device_node *child,
char *rname, struct resource *res)
{
int index;
index = of_property_match_string(child, "reg-names", rname);
if (index < 0)
return -ENODEV;
return of_address_to_resource(child, index, res);
}
static int miphy28lp_get_one_addr(struct device *dev,
struct device_node *child, char *rname,
void __iomem **base)
{
struct resource res;
int ret;
ret = miphy28lp_get_resource_byname(child, rname, &res);
if (!ret) {
*base = devm_ioremap(dev, res.start, resource_size(&res));
if (!*base) {
dev_err(dev, "failed to ioremap %s address region\n"
, rname);
return -ENOENT;
}
}
return 0;
}
static int miphy28lp_setup(struct miphy28lp_phy *miphy_phy, u32 miphy_val)
{
int err;
struct miphy28lp_dev *miphy_dev = miphy_phy->phydev;
if (!miphy_phy->syscfg_reg[SYSCFG_CTRL])
return -EINVAL;
err = reset_control_assert(miphy_phy->miphy_rst);
if (err) {
dev_err(miphy_dev->dev, "unable to bring out of miphy reset\n");
return err;
}
if (miphy_phy->osc_force_ext)
miphy_val |= MIPHY_OSC_FORCE_EXT;
regmap_update_bits(miphy_dev->regmap,
miphy_phy->syscfg_reg[SYSCFG_CTRL],
MIPHY_CTRL_MASK, miphy_val);
err = reset_control_deassert(miphy_phy->miphy_rst);
if (err) {
dev_err(miphy_dev->dev, "unable to bring out of miphy reset\n");
return err;
}
return miphy_osc_is_ready(miphy_phy);
}
static int miphy28lp_init_sata(struct miphy28lp_phy *miphy_phy)
{
struct miphy28lp_dev *miphy_dev = miphy_phy->phydev;
int err, sata_conf = SATA_CTRL_SELECT_SATA;
if ((!miphy_phy->syscfg_reg[SYSCFG_SATA]) ||
(!miphy_phy->syscfg_reg[SYSCFG_PCI]) ||
(!miphy_phy->base))
return -EINVAL;
dev_info(miphy_dev->dev, "sata-up mode, addr 0x%p\n", miphy_phy->base);
sata_conf |= ((miphy_phy->sata_gen - SATA_GEN1) << SATA_SPDMODE);
regmap_update_bits(miphy_dev->regmap,
miphy_phy->syscfg_reg[SYSCFG_SATA],
SATA_CTRL_MASK, sata_conf);
regmap_update_bits(miphy_dev->regmap, miphy_phy->syscfg_reg[SYSCFG_PCI],
PCIE_CTRL_MASK, SATA_CTRL_SELECT_PCIE);
err = miphy28lp_setup(miphy_phy, MIPHY_CTRL_DEFAULT);
if (err) {
dev_err(miphy_dev->dev, "SATA phy setup failed\n");
return err;
}
miphy28lp_configure_sata(miphy_phy);
return miphy_is_ready(miphy_phy);
}
static int miphy28lp_init_pcie(struct miphy28lp_phy *miphy_phy)
{
struct miphy28lp_dev *miphy_dev = miphy_phy->phydev;
int err;
if ((!miphy_phy->syscfg_reg[SYSCFG_SATA]) ||
(!miphy_phy->syscfg_reg[SYSCFG_PCI])
|| (!miphy_phy->base) || (!miphy_phy->pipebase))
return -EINVAL;
dev_info(miphy_dev->dev, "pcie-up mode, addr 0x%p\n", miphy_phy->base);
regmap_update_bits(miphy_dev->regmap,
miphy_phy->syscfg_reg[SYSCFG_SATA],
SATA_CTRL_MASK, SATA_CTRL_SELECT_PCIE);
regmap_update_bits(miphy_dev->regmap, miphy_phy->syscfg_reg[SYSCFG_PCI],
PCIE_CTRL_MASK, SYSCFG_PCIE_PCIE_VAL);
err = miphy28lp_setup(miphy_phy, MIPHY_CTRL_DEFAULT);
if (err) {
dev_err(miphy_dev->dev, "PCIe phy setup failed\n");
return err;
}
err = miphy28lp_configure_pcie(miphy_phy);
if (err)
return err;
writeb_relaxed(0x68, miphy_phy->pipebase + 0x104);
writeb_relaxed(0x61, miphy_phy->pipebase + 0x105);
writeb_relaxed(0x68, miphy_phy->pipebase + 0x108);
writeb_relaxed(0x61, miphy_phy->pipebase + 0x109);
writeb_relaxed(0x68, miphy_phy->pipebase + 0x10c);
writeb_relaxed(0x60, miphy_phy->pipebase + 0x10d);
return miphy_is_ready(miphy_phy);
}
static int miphy28lp_init_usb3(struct miphy28lp_phy *miphy_phy)
{
struct miphy28lp_dev *miphy_dev = miphy_phy->phydev;
int err;
if ((!miphy_phy->base) || (!miphy_phy->pipebase))
return -EINVAL;
dev_info(miphy_dev->dev, "usb3-up mode, addr 0x%p\n", miphy_phy->base);
err = miphy28lp_setup(miphy_phy, MIPHY_CTRL_SYNC_D_EN);
if (err) {
dev_err(miphy_dev->dev, "USB3 phy setup failed\n");
return err;
}
miphy28lp_configure_usb3(miphy_phy);
writeb_relaxed(0x68, miphy_phy->pipebase + 0x23);
writeb_relaxed(0x61, miphy_phy->pipebase + 0x24);
writeb_relaxed(0x68, miphy_phy->pipebase + 0x26);
writeb_relaxed(0x61, miphy_phy->pipebase + 0x27);
writeb_relaxed(0x18, miphy_phy->pipebase + 0x29);
writeb_relaxed(0x61, miphy_phy->pipebase + 0x2a);
writeb_relaxed(0X67, miphy_phy->pipebase + 0x68);
writeb_relaxed(0x0d, miphy_phy->pipebase + 0x69);
writeb_relaxed(0X67, miphy_phy->pipebase + 0x6a);
writeb_relaxed(0X0d, miphy_phy->pipebase + 0x6b);
writeb_relaxed(0X67, miphy_phy->pipebase + 0x6c);
writeb_relaxed(0X0d, miphy_phy->pipebase + 0x6d);
writeb_relaxed(0X67, miphy_phy->pipebase + 0x6e);
writeb_relaxed(0X0d, miphy_phy->pipebase + 0x6f);
return miphy_is_ready(miphy_phy);
}
static int miphy28lp_init(struct phy *phy)
{
struct miphy28lp_phy *miphy_phy = phy_get_drvdata(phy);
struct miphy28lp_dev *miphy_dev = miphy_phy->phydev;
int ret;
mutex_lock(&miphy_dev->miphy_mutex);
switch (miphy_phy->type) {
case PHY_TYPE_SATA:
ret = miphy28lp_init_sata(miphy_phy);
break;
case PHY_TYPE_PCIE:
ret = miphy28lp_init_pcie(miphy_phy);
break;
case PHY_TYPE_USB3:
ret = miphy28lp_init_usb3(miphy_phy);
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&miphy_dev->miphy_mutex);
return ret;
}
static int miphy28lp_get_addr(struct miphy28lp_phy *miphy_phy)
{
struct miphy28lp_dev *miphy_dev = miphy_phy->phydev;
struct device_node *phynode = miphy_phy->phy->dev.of_node;
int err;
if ((miphy_phy->type != PHY_TYPE_SATA) &&
(miphy_phy->type != PHY_TYPE_PCIE) &&
(miphy_phy->type != PHY_TYPE_USB3)) {
return -EINVAL;
}
err = miphy28lp_get_one_addr(miphy_dev->dev, phynode,
PHY_TYPE_name[miphy_phy->type - PHY_TYPE_SATA],
&miphy_phy->base);
if (err)
return err;
if ((miphy_phy->type == PHY_TYPE_PCIE) ||
(miphy_phy->type == PHY_TYPE_USB3)) {
err = miphy28lp_get_one_addr(miphy_dev->dev, phynode, "pipew",
&miphy_phy->pipebase);
if (err)
return err;
}
return 0;
}
static struct phy *miphy28lp_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct miphy28lp_dev *miphy_dev = dev_get_drvdata(dev);
struct miphy28lp_phy *miphy_phy = NULL;
struct device_node *phynode = args->np;
int ret, index = 0;
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
ret = miphy28lp_get_addr(miphy_phy);
if (ret < 0)
return ERR_PTR(ret);
return miphy_phy->phy;
}
static int miphy28lp_probe_resets(struct device_node *node,
struct miphy28lp_phy *miphy_phy)
{
struct miphy28lp_dev *miphy_dev = miphy_phy->phydev;
int err;
miphy_phy->miphy_rst =
of_reset_control_get_shared(node, "miphy-sw-rst");
if (IS_ERR(miphy_phy->miphy_rst)) {
dev_err(miphy_dev->dev,
"miphy soft reset control not defined\n");
return PTR_ERR(miphy_phy->miphy_rst);
}
err = reset_control_deassert(miphy_phy->miphy_rst);
if (err) {
dev_err(miphy_dev->dev, "unable to bring out of miphy reset\n");
return err;
}
return 0;
}
static int miphy28lp_of_probe(struct device_node *np,
struct miphy28lp_phy *miphy_phy)
{
int i;
u32 ctrlreg;
miphy_phy->osc_force_ext =
of_property_read_bool(np, "st,osc-force-ext");
miphy_phy->osc_rdy = of_property_read_bool(np, "st,osc-rdy");
miphy_phy->px_rx_pol_inv =
of_property_read_bool(np, "st,px_rx_pol_inv");
miphy_phy->ssc = of_property_read_bool(np, "st,ssc-on");
miphy_phy->tx_impedance =
of_property_read_bool(np, "st,tx-impedance-comp");
of_property_read_u32(np, "st,sata-gen", &miphy_phy->sata_gen);
if (!miphy_phy->sata_gen)
miphy_phy->sata_gen = SATA_GEN1;
for (i = 0; i < SYSCFG_REG_MAX; i++) {
if (!of_property_read_u32_index(np, "st,syscfg", i, &ctrlreg))
miphy_phy->syscfg_reg[i] = ctrlreg;
}
return 0;
}
static int miphy28lp_probe(struct platform_device *pdev)
{
struct device_node *child, *np = pdev->dev.of_node;
struct miphy28lp_dev *miphy_dev;
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
struct miphy28lp_phy *miphy_phy;
miphy_phy = devm_kzalloc(&pdev->dev, sizeof(*miphy_phy),
GFP_KERNEL);
if (!miphy_phy) {
ret = -ENOMEM;
goto put_child;
}
miphy_dev->phys[port] = miphy_phy;
phy = devm_phy_create(&pdev->dev, child, &miphy28lp_ops);
if (IS_ERR(phy)) {
dev_err(&pdev->dev, "failed to create PHY\n");
ret = PTR_ERR(phy);
goto put_child;
}
miphy_dev->phys[port]->phy = phy;
miphy_dev->phys[port]->phydev = miphy_dev;
ret = miphy28lp_of_probe(child, miphy_phy);
if (ret)
goto put_child;
ret = miphy28lp_probe_resets(child, miphy_dev->phys[port]);
if (ret)
goto put_child;
phy_set_drvdata(phy, miphy_dev->phys[port]);
port++;
}
provider = devm_of_phy_provider_register(&pdev->dev, miphy28lp_xlate);
return PTR_ERR_OR_ZERO(provider);
put_child:
of_node_put(child);
return ret;
}
