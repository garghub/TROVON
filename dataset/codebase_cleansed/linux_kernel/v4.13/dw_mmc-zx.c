static int dw_mci_zx_emmc_set_delay(struct dw_mci *host, unsigned int delay,
enum delay_type dflag)
{
struct dw_mci_zx_priv_data *priv = host->priv;
struct regmap *sysc_base = priv->sysc_base;
unsigned int clksel;
unsigned int loop = 1000;
int ret;
if (!sysc_base)
return -EINVAL;
ret = regmap_update_bits(sysc_base, LB_AON_EMMC_CFG_REG0,
PARA_HALF_CLK_MODE | PARA_DLL_BYPASS_MODE |
PARA_PHASE_DET_SEL_MASK |
PARA_DLL_LOCK_NUM_MASK |
DLL_REG_SET | PARA_DLL_START_MASK,
PARA_DLL_START(4) | PARA_DLL_LOCK_NUM(4));
if (ret)
return ret;
ret = regmap_read(sysc_base, LB_AON_EMMC_CFG_REG1, &clksel);
if (ret)
return ret;
if (dflag == DELAY_TYPE_CLK) {
clksel &= ~CLK_SAMP_DELAY_MASK;
clksel |= CLK_SAMP_DELAY(delay);
} else {
clksel &= ~READ_DQS_DELAY_MASK;
clksel |= READ_DQS_DELAY(delay);
}
regmap_write(sysc_base, LB_AON_EMMC_CFG_REG1, clksel);
regmap_update_bits(sysc_base, LB_AON_EMMC_CFG_REG0,
PARA_DLL_START_MASK | PARA_DLL_LOCK_NUM_MASK |
DLL_REG_SET,
PARA_DLL_START(4) | PARA_DLL_LOCK_NUM(4) |
DLL_REG_SET);
do {
ret = regmap_read(sysc_base, LB_AON_EMMC_CFG_REG2, &clksel);
if (ret)
return ret;
} while (--loop && !(clksel & ZX_DLL_LOCKED));
if (!loop) {
dev_err(host->dev, "Error: %s dll lock fail\n", __func__);
return -EIO;
}
return 0;
}
static int dw_mci_zx_emmc_execute_tuning(struct dw_mci_slot *slot, u32 opcode)
{
struct dw_mci *host = slot->host;
struct mmc_host *mmc = slot->mmc;
int ret, len = 0, start = 0, end = 0, delay, best = 0;
for (delay = 1; delay < 128; delay++) {
ret = dw_mci_zx_emmc_set_delay(host, delay, DELAY_TYPE_CLK);
if (!ret && mmc_send_tuning(mmc, opcode, NULL)) {
if (start >= 0) {
end = delay - 1;
if ((end - start) > len) {
best = (start + end) >> 1;
len = end - start;
}
}
start = -1;
end = 0;
continue;
}
if (start < 0)
start = delay;
}
if (start >= 0) {
end = delay - 1;
if ((end - start) > len) {
best = (start + end) >> 1;
len = end - start;
}
}
if (best < 0)
return -EIO;
dev_info(host->dev, "%s best range: start %d end %d\n", __func__,
start, end);
return dw_mci_zx_emmc_set_delay(host, best, DELAY_TYPE_CLK);
}
static int dw_mci_zx_prepare_hs400_tuning(struct dw_mci *host,
struct mmc_ios *ios)
{
int ret;
ret = dw_mci_zx_emmc_set_delay(host, 32, DELAY_TYPE_READ);
if (ret < 0)
return -EIO;
return 0;
}
static int dw_mci_zx_execute_tuning(struct dw_mci_slot *slot, u32 opcode)
{
struct dw_mci *host = slot->host;
if (host->verid == 0x290a)
return dw_mci_zx_emmc_execute_tuning(slot, opcode);
return 0;
}
static int dw_mci_zx_parse_dt(struct dw_mci *host)
{
struct device_node *np = host->dev->of_node;
struct device_node *node;
struct dw_mci_zx_priv_data *priv;
struct regmap *sysc_base;
int ret;
node = of_parse_phandle(np, "zte,aon-syscon", 0);
if (node) {
sysc_base = syscon_node_to_regmap(node);
of_node_put(node);
if (IS_ERR(sysc_base)) {
ret = PTR_ERR(sysc_base);
if (ret != -EPROBE_DEFER)
dev_err(host->dev, "Can't get syscon: %d\n",
ret);
return ret;
}
} else {
return 0;
}
priv = devm_kzalloc(host->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->sysc_base = sysc_base;
host->priv = priv;
return 0;
}
static int dw_mci_zx_probe(struct platform_device *pdev)
{
const struct dw_mci_drv_data *drv_data;
const struct of_device_id *match;
match = of_match_node(dw_mci_zx_match, pdev->dev.of_node);
drv_data = match->data;
return dw_mci_pltfm_register(pdev, drv_data);
}
