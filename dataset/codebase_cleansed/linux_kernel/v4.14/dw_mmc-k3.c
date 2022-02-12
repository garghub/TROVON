static void dw_mci_k3_set_ios(struct dw_mci *host, struct mmc_ios *ios)
{
int ret;
ret = clk_set_rate(host->ciu_clk, ios->clock);
if (ret)
dev_warn(host->dev, "failed to set rate %uHz\n", ios->clock);
host->bus_hz = clk_get_rate(host->ciu_clk);
}
static int dw_mci_hi6220_parse_dt(struct dw_mci *host)
{
struct k3_priv *priv;
priv = devm_kzalloc(host->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->reg = syscon_regmap_lookup_by_phandle(host->dev->of_node,
"hisilicon,peripheral-syscon");
if (IS_ERR(priv->reg))
priv->reg = NULL;
priv->ctrl_id = of_alias_get_id(host->dev->of_node, "mshc");
if (priv->ctrl_id < 0)
priv->ctrl_id = 0;
host->priv = priv;
return 0;
}
static int dw_mci_hi6220_switch_voltage(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct dw_mci_slot *slot = mmc_priv(mmc);
struct k3_priv *priv;
struct dw_mci *host;
int min_uv, max_uv;
int ret;
host = slot->host;
priv = host->priv;
if (!priv || !priv->reg)
return 0;
if (ios->signal_voltage == MMC_SIGNAL_VOLTAGE_330) {
ret = regmap_update_bits(priv->reg, AO_SCTRL_CTRL3,
AO_SCTRL_SEL18, 0);
min_uv = 3000000;
max_uv = 3000000;
} else if (ios->signal_voltage == MMC_SIGNAL_VOLTAGE_180) {
ret = regmap_update_bits(priv->reg, AO_SCTRL_CTRL3,
AO_SCTRL_SEL18, AO_SCTRL_SEL18);
min_uv = 1800000;
max_uv = 1800000;
} else {
dev_dbg(host->dev, "voltage not supported\n");
return -EINVAL;
}
if (ret) {
dev_dbg(host->dev, "switch voltage failed\n");
return ret;
}
if (IS_ERR_OR_NULL(mmc->supply.vqmmc))
return 0;
ret = regulator_set_voltage(mmc->supply.vqmmc, min_uv, max_uv);
if (ret) {
dev_dbg(host->dev, "Regulator set error %d: %d - %d\n",
ret, min_uv, max_uv);
return ret;
}
return 0;
}
static void dw_mci_hi6220_set_ios(struct dw_mci *host, struct mmc_ios *ios)
{
int ret;
unsigned int clock;
clock = (ios->clock <= 25000000) ? 25000000 : ios->clock;
ret = clk_set_rate(host->biu_clk, clock);
if (ret)
dev_warn(host->dev, "failed to set rate %uHz\n", clock);
host->bus_hz = clk_get_rate(host->biu_clk);
}
static int dw_mci_hi6220_execute_tuning(struct dw_mci_slot *slot, u32 opcode)
{
return 0;
}
static void dw_mci_hs_set_timing(struct dw_mci *host, int timing,
int smpl_phase)
{
u32 drv_phase;
u32 smpl_dly;
u32 use_smpl_dly = 0;
u32 enable_shift = 0;
u32 reg_value;
int ctrl_id;
struct k3_priv *priv;
priv = host->priv;
ctrl_id = priv->ctrl_id;
drv_phase = hs_timing_cfg[ctrl_id][timing].drv_phase;
smpl_dly = hs_timing_cfg[ctrl_id][timing].smpl_dly;
if (smpl_phase == -1)
smpl_phase = (hs_timing_cfg[ctrl_id][timing].smpl_phase_max +
hs_timing_cfg[ctrl_id][timing].smpl_phase_min) / 2;
switch (timing) {
case MMC_TIMING_UHS_SDR104:
if (smpl_phase >= USE_DLY_MIN_SMPL &&
smpl_phase <= USE_DLY_MAX_SMPL)
use_smpl_dly = 1;
case MMC_TIMING_UHS_SDR50:
if (smpl_phase >= ENABLE_SHIFT_MIN_SMPL &&
smpl_phase <= ENABLE_SHIFT_MAX_SMPL)
enable_shift = 1;
break;
}
mci_writel(host, GPIO, 0x0);
usleep_range(5, 10);
reg_value = FIELD_PREP(UHS_REG_EXT_SAMPLE_PHASE_MASK, smpl_phase) |
FIELD_PREP(UHS_REG_EXT_SAMPLE_DLY_MASK, smpl_dly) |
FIELD_PREP(UHS_REG_EXT_SAMPLE_DRVPHASE_MASK, drv_phase);
mci_writel(host, UHS_REG_EXT, reg_value);
mci_writel(host, ENABLE_SHIFT, enable_shift);
reg_value = FIELD_PREP(GPIO_CLK_DIV_MASK, GENCLK_DIV) |
FIELD_PREP(GPIO_USE_SAMPLE_DLY_MASK, use_smpl_dly);
mci_writel(host, GPIO, (unsigned int)reg_value | GPIO_CLK_ENABLE);
usleep_range(1000, 2000);
}
static int dw_mci_hi3660_init(struct dw_mci *host)
{
mci_writel(host, CDTHRCTL, SDMMC_SET_THLD(SDCARD_RD_THRESHOLD,
SDMMC_CARD_RD_THR_EN));
dw_mci_hs_set_timing(host, MMC_TIMING_LEGACY, -1);
host->bus_hz /= (GENCLK_DIV + 1);
return 0;
}
static int dw_mci_set_sel18(struct dw_mci *host, bool set)
{
int ret;
unsigned int val;
struct k3_priv *priv;
priv = host->priv;
val = set ? SDCARD_IO_SEL18 : 0;
ret = regmap_update_bits(priv->reg, SOC_SCTRL_SCPERCTRL5,
SDCARD_IO_SEL18, val);
if (ret) {
dev_err(host->dev, "sel18 %u error\n", val);
return ret;
}
return 0;
}
static void dw_mci_hi3660_set_ios(struct dw_mci *host, struct mmc_ios *ios)
{
int ret;
unsigned long wanted;
unsigned long actual;
struct k3_priv *priv = host->priv;
if (!ios->clock || ios->clock == priv->cur_speed)
return;
wanted = ios->clock * (GENCLK_DIV + 1);
ret = clk_set_rate(host->ciu_clk, wanted);
if (ret) {
dev_err(host->dev, "failed to set rate %luHz\n", wanted);
return;
}
actual = clk_get_rate(host->ciu_clk);
dw_mci_hs_set_timing(host, ios->timing, -1);
host->bus_hz = actual / (GENCLK_DIV + 1);
host->current_speed = 0;
priv->cur_speed = host->bus_hz;
}
static int dw_mci_get_best_clksmpl(unsigned int sample_flag)
{
int i;
int interval;
unsigned int v;
unsigned int len;
unsigned int range_start = 0;
unsigned int range_length = 0;
unsigned int middle_range = 0;
if (!sample_flag)
return -EIO;
if (~sample_flag == 0)
return 0;
i = ffs(sample_flag) - 1;
while (i < 32) {
v = ror32(sample_flag, i);
len = ffs(~v) - 1;
if (len > range_length) {
range_length = len;
range_start = i;
}
interval = ffs(v >> len) - 1;
if (interval < 0)
break;
i += len + interval;
}
middle_range = range_start + range_length / 2;
if (middle_range >= 32)
middle_range %= 32;
return middle_range;
}
static int dw_mci_hi3660_execute_tuning(struct dw_mci_slot *slot, u32 opcode)
{
int i = 0;
struct dw_mci *host = slot->host;
struct mmc_host *mmc = slot->mmc;
int smpl_phase = 0;
u32 tuning_sample_flag = 0;
int best_clksmpl = 0;
for (i = 0; i < NUM_PHASES; ++i, ++smpl_phase) {
smpl_phase %= 32;
mci_writel(host, TMOUT, ~0);
dw_mci_hs_set_timing(host, mmc->ios.timing, smpl_phase);
if (!mmc_send_tuning(mmc, opcode, NULL))
tuning_sample_flag |= (1 << smpl_phase);
else
tuning_sample_flag &= ~(1 << smpl_phase);
}
best_clksmpl = dw_mci_get_best_clksmpl(tuning_sample_flag);
if (best_clksmpl < 0) {
dev_err(host->dev, "All phases bad!\n");
return -EIO;
}
dw_mci_hs_set_timing(host, mmc->ios.timing, best_clksmpl);
dev_info(host->dev, "tuning ok best_clksmpl %u tuning_sample_flag %x\n",
best_clksmpl, tuning_sample_flag);
return 0;
}
static int dw_mci_hi3660_switch_voltage(struct mmc_host *mmc,
struct mmc_ios *ios)
{
int ret = 0;
struct dw_mci_slot *slot = mmc_priv(mmc);
struct k3_priv *priv;
struct dw_mci *host;
host = slot->host;
priv = host->priv;
if (!priv || !priv->reg)
return 0;
if (priv->ctrl_id == DWMMC_SDIO_ID)
return 0;
if (ios->signal_voltage == MMC_SIGNAL_VOLTAGE_330)
ret = dw_mci_set_sel18(host, 0);
else if (ios->signal_voltage == MMC_SIGNAL_VOLTAGE_180)
ret = dw_mci_set_sel18(host, 1);
if (ret)
return ret;
if (!IS_ERR(mmc->supply.vqmmc)) {
ret = mmc_regulator_set_vqmmc(mmc, ios);
if (ret) {
dev_err(host->dev, "Regulator set error %d\n", ret);
return ret;
}
}
return 0;
}
static int dw_mci_k3_probe(struct platform_device *pdev)
{
const struct dw_mci_drv_data *drv_data;
const struct of_device_id *match;
match = of_match_node(dw_mci_k3_match, pdev->dev.of_node);
drv_data = match->data;
return dw_mci_pltfm_register(pdev, drv_data);
}
