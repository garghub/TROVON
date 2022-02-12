static inline struct mtk_mipi_tx *mtk_mipi_tx_from_clk_hw(struct clk_hw *hw)
{
return container_of(hw, struct mtk_mipi_tx, pll_hw);
}
static void mtk_mipi_tx_clear_bits(struct mtk_mipi_tx *mipi_tx, u32 offset,
u32 bits)
{
u32 temp = readl(mipi_tx->regs + offset);
writel(temp & ~bits, mipi_tx->regs + offset);
}
static void mtk_mipi_tx_set_bits(struct mtk_mipi_tx *mipi_tx, u32 offset,
u32 bits)
{
u32 temp = readl(mipi_tx->regs + offset);
writel(temp | bits, mipi_tx->regs + offset);
}
static void mtk_mipi_tx_update_bits(struct mtk_mipi_tx *mipi_tx, u32 offset,
u32 mask, u32 data)
{
u32 temp = readl(mipi_tx->regs + offset);
writel((temp & ~mask) | (data & mask), mipi_tx->regs + offset);
}
static int mtk_mipi_tx_pll_prepare(struct clk_hw *hw)
{
struct mtk_mipi_tx *mipi_tx = mtk_mipi_tx_from_clk_hw(hw);
unsigned int txdiv, txdiv0, txdiv1;
u64 pcw;
dev_dbg(mipi_tx->dev, "prepare: %u Hz\n", mipi_tx->data_rate);
if (mipi_tx->data_rate >= 500000000) {
txdiv = 1;
txdiv0 = 0;
txdiv1 = 0;
} else if (mipi_tx->data_rate >= 250000000) {
txdiv = 2;
txdiv0 = 1;
txdiv1 = 0;
} else if (mipi_tx->data_rate >= 125000000) {
txdiv = 4;
txdiv0 = 2;
txdiv1 = 0;
} else if (mipi_tx->data_rate > 62000000) {
txdiv = 8;
txdiv0 = 2;
txdiv1 = 1;
} else if (mipi_tx->data_rate >= 50000000) {
txdiv = 16;
txdiv0 = 2;
txdiv1 = 2;
} else {
return -EINVAL;
}
mtk_mipi_tx_update_bits(mipi_tx, MIPITX_DSI_BG_CON,
RG_DSI_VOUT_MSK |
RG_DSI_BG_CKEN | RG_DSI_BG_CORE_EN,
(4 << 20) | (4 << 17) | (4 << 14) |
(4 << 11) | (4 << 8) | (4 << 5) |
RG_DSI_BG_CKEN | RG_DSI_BG_CORE_EN);
usleep_range(30, 100);
mtk_mipi_tx_update_bits(mipi_tx, MIPITX_DSI_TOP_CON,
RG_DSI_LNT_IMP_CAL_CODE | RG_DSI_LNT_HS_BIAS_EN,
(8 << 4) | RG_DSI_LNT_HS_BIAS_EN);
mtk_mipi_tx_set_bits(mipi_tx, MIPITX_DSI_CON,
RG_DSI_CKG_LDOOUT_EN | RG_DSI_LDOCORE_EN);
mtk_mipi_tx_update_bits(mipi_tx, MIPITX_DSI_PLL_PWR,
RG_DSI_MPPLL_SDM_PWR_ON |
RG_DSI_MPPLL_SDM_ISO_EN,
RG_DSI_MPPLL_SDM_PWR_ON);
mtk_mipi_tx_clear_bits(mipi_tx, MIPITX_DSI_PLL_CON0,
RG_DSI_MPPLL_PLL_EN);
mtk_mipi_tx_update_bits(mipi_tx, MIPITX_DSI_PLL_CON0,
RG_DSI_MPPLL_TXDIV0 | RG_DSI_MPPLL_TXDIV1 |
RG_DSI_MPPLL_PREDIV,
(txdiv0 << 3) | (txdiv1 << 5));
pcw = div_u64(((u64)mipi_tx->data_rate * 2 * txdiv) << 24,
26000000);
writel(pcw, mipi_tx->regs + MIPITX_DSI_PLL_CON2);
mtk_mipi_tx_set_bits(mipi_tx, MIPITX_DSI_PLL_CON1,
RG_DSI_MPPLL_SDM_FRA_EN);
mtk_mipi_tx_set_bits(mipi_tx, MIPITX_DSI_PLL_CON0, RG_DSI_MPPLL_PLL_EN);
usleep_range(20, 100);
mtk_mipi_tx_clear_bits(mipi_tx, MIPITX_DSI_PLL_CON1,
RG_DSI_MPPLL_SDM_SSC_EN);
return 0;
}
static void mtk_mipi_tx_pll_unprepare(struct clk_hw *hw)
{
struct mtk_mipi_tx *mipi_tx = mtk_mipi_tx_from_clk_hw(hw);
dev_dbg(mipi_tx->dev, "unprepare\n");
mtk_mipi_tx_clear_bits(mipi_tx, MIPITX_DSI_PLL_CON0,
RG_DSI_MPPLL_PLL_EN);
mtk_mipi_tx_update_bits(mipi_tx, MIPITX_DSI_PLL_PWR,
RG_DSI_MPPLL_SDM_ISO_EN |
RG_DSI_MPPLL_SDM_PWR_ON,
RG_DSI_MPPLL_SDM_ISO_EN);
mtk_mipi_tx_clear_bits(mipi_tx, MIPITX_DSI_TOP_CON,
RG_DSI_LNT_HS_BIAS_EN);
mtk_mipi_tx_clear_bits(mipi_tx, MIPITX_DSI_CON,
RG_DSI_CKG_LDOOUT_EN | RG_DSI_LDOCORE_EN);
mtk_mipi_tx_clear_bits(mipi_tx, MIPITX_DSI_BG_CON,
RG_DSI_BG_CKEN | RG_DSI_BG_CORE_EN);
mtk_mipi_tx_clear_bits(mipi_tx, MIPITX_DSI_PLL_CON0,
RG_DSI_MPPLL_DIV_MSK);
}
static long mtk_mipi_tx_pll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
return clamp_val(rate, 50000000, 1250000000);
}
static int mtk_mipi_tx_pll_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct mtk_mipi_tx *mipi_tx = mtk_mipi_tx_from_clk_hw(hw);
dev_dbg(mipi_tx->dev, "set rate: %lu Hz\n", rate);
mipi_tx->data_rate = rate;
return 0;
}
static unsigned long mtk_mipi_tx_pll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct mtk_mipi_tx *mipi_tx = mtk_mipi_tx_from_clk_hw(hw);
return mipi_tx->data_rate;
}
static int mtk_mipi_tx_power_on_signal(struct phy *phy)
{
struct mtk_mipi_tx *mipi_tx = phy_get_drvdata(phy);
unsigned int reg;
for (reg = MIPITX_DSI_CLOCK_LANE;
reg <= MIPITX_DSI_DATA_LANE3; reg += 4)
mtk_mipi_tx_set_bits(mipi_tx, reg, RG_DSI_LNTx_LDOOUT_EN);
mtk_mipi_tx_clear_bits(mipi_tx, MIPITX_DSI_TOP_CON,
RG_DSI_PAD_TIE_LOW_EN);
return 0;
}
static int mtk_mipi_tx_power_on(struct phy *phy)
{
struct mtk_mipi_tx *mipi_tx = phy_get_drvdata(phy);
int ret;
ret = clk_prepare_enable(mipi_tx->pll);
if (ret < 0)
return ret;
mtk_mipi_tx_power_on_signal(phy);
return 0;
}
static void mtk_mipi_tx_power_off_signal(struct phy *phy)
{
struct mtk_mipi_tx *mipi_tx = phy_get_drvdata(phy);
unsigned int reg;
mtk_mipi_tx_set_bits(mipi_tx, MIPITX_DSI_TOP_CON,
RG_DSI_PAD_TIE_LOW_EN);
for (reg = MIPITX_DSI_CLOCK_LANE;
reg <= MIPITX_DSI_DATA_LANE3; reg += 4)
mtk_mipi_tx_clear_bits(mipi_tx, reg, RG_DSI_LNTx_LDOOUT_EN);
}
static int mtk_mipi_tx_power_off(struct phy *phy)
{
struct mtk_mipi_tx *mipi_tx = phy_get_drvdata(phy);
mtk_mipi_tx_power_off_signal(phy);
clk_disable_unprepare(mipi_tx->pll);
return 0;
}
static int mtk_mipi_tx_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct mtk_mipi_tx *mipi_tx;
struct resource *mem;
struct clk *ref_clk;
const char *ref_clk_name;
struct clk_init_data clk_init = {
.ops = &mtk_mipi_tx_pll_ops,
.num_parents = 1,
.parent_names = (const char * const *)&ref_clk_name,
.flags = CLK_SET_RATE_GATE,
};
struct phy *phy;
struct phy_provider *phy_provider;
int ret;
mipi_tx = devm_kzalloc(dev, sizeof(*mipi_tx), GFP_KERNEL);
if (!mipi_tx)
return -ENOMEM;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mipi_tx->regs = devm_ioremap_resource(dev, mem);
if (IS_ERR(mipi_tx->regs)) {
ret = PTR_ERR(mipi_tx->regs);
dev_err(dev, "Failed to get memory resource: %d\n", ret);
return ret;
}
ref_clk = devm_clk_get(dev, NULL);
if (IS_ERR(ref_clk)) {
ret = PTR_ERR(ref_clk);
dev_err(dev, "Failed to get reference clock: %d\n", ret);
return ret;
}
ref_clk_name = __clk_get_name(ref_clk);
ret = of_property_read_string(dev->of_node, "clock-output-names",
&clk_init.name);
if (ret < 0) {
dev_err(dev, "Failed to read clock-output-names: %d\n", ret);
return ret;
}
mipi_tx->pll_hw.init = &clk_init;
mipi_tx->pll = devm_clk_register(dev, &mipi_tx->pll_hw);
if (IS_ERR(mipi_tx->pll)) {
ret = PTR_ERR(mipi_tx->pll);
dev_err(dev, "Failed to register PLL: %d\n", ret);
return ret;
}
phy = devm_phy_create(dev, NULL, &mtk_mipi_tx_ops);
if (IS_ERR(phy)) {
ret = PTR_ERR(phy);
dev_err(dev, "Failed to create MIPI D-PHY: %d\n", ret);
return ret;
}
phy_set_drvdata(phy, mipi_tx);
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
if (IS_ERR(phy_provider)) {
ret = PTR_ERR(phy_provider);
return ret;
}
mipi_tx->dev = dev;
return of_clk_add_provider(dev->of_node, of_clk_src_simple_get,
mipi_tx->pll);
}
static int mtk_mipi_tx_remove(struct platform_device *pdev)
{
of_clk_del_provider(pdev->dev.of_node);
return 0;
}
