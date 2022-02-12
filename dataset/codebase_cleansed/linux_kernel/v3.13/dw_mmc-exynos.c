static int dw_mci_exynos_priv_init(struct dw_mci *host)
{
struct dw_mci_exynos_priv_data *priv = host->priv;
if (priv->ctrl_type == DW_MCI_TYPE_EXYNOS5420_SMU) {
mci_writel(host, MPSBEGIN0, 0);
mci_writel(host, MPSEND0, DWMCI_BLOCK_NUM);
mci_writel(host, MPSCTRL0, DWMCI_MPSCTRL_SECURE_WRITE_BIT |
DWMCI_MPSCTRL_NON_SECURE_READ_BIT |
DWMCI_MPSCTRL_VALID |
DWMCI_MPSCTRL_NON_SECURE_WRITE_BIT);
}
return 0;
}
static int dw_mci_exynos_setup_clock(struct dw_mci *host)
{
struct dw_mci_exynos_priv_data *priv = host->priv;
unsigned long rate = clk_get_rate(host->ciu_clk);
host->bus_hz = rate / (priv->ciu_div + 1);
return 0;
}
static int dw_mci_exynos_suspend(struct device *dev)
{
struct dw_mci *host = dev_get_drvdata(dev);
return dw_mci_suspend(host);
}
static int dw_mci_exynos_resume(struct device *dev)
{
struct dw_mci *host = dev_get_drvdata(dev);
dw_mci_exynos_priv_init(host);
return dw_mci_resume(host);
}
static int dw_mci_exynos_resume_noirq(struct device *dev)
{
struct dw_mci *host = dev_get_drvdata(dev);
u32 clksel;
clksel = mci_readl(host, CLKSEL);
if (clksel & SDMMC_CLKSEL_WAKEUP_INT)
mci_writel(host, CLKSEL, clksel);
return 0;
}
static void dw_mci_exynos_prepare_command(struct dw_mci *host, u32 *cmdr)
{
if (SDMMC_CLKSEL_GET_DRV_WD3(mci_readl(host, CLKSEL)))
*cmdr |= SDMMC_CMD_USE_HOLD_REG;
}
static void dw_mci_exynos_set_ios(struct dw_mci *host, struct mmc_ios *ios)
{
struct dw_mci_exynos_priv_data *priv = host->priv;
unsigned int wanted = ios->clock;
unsigned long actual;
u8 div = priv->ciu_div + 1;
if (ios->timing == MMC_TIMING_UHS_DDR50) {
mci_writel(host, CLKSEL, priv->ddr_timing);
if (ios->bus_width == MMC_BUS_WIDTH_8)
wanted <<= 1;
} else {
mci_writel(host, CLKSEL, priv->sdr_timing);
}
if (!wanted)
return;
if (wanted < EXYNOS_CCLKIN_MIN)
wanted = EXYNOS_CCLKIN_MIN;
if (wanted != priv->cur_speed) {
int ret = clk_set_rate(host->ciu_clk, wanted * div);
if (ret)
dev_warn(host->dev,
"failed to set clk-rate %u error: %d\n",
wanted * div, ret);
actual = clk_get_rate(host->ciu_clk);
host->bus_hz = actual / div;
priv->cur_speed = wanted;
host->current_speed = 0;
}
}
static int dw_mci_exynos_parse_dt(struct dw_mci *host)
{
struct dw_mci_exynos_priv_data *priv;
struct device_node *np = host->dev->of_node;
u32 timing[2];
u32 div = 0;
int idx;
int ret;
priv = devm_kzalloc(host->dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(host->dev, "mem alloc failed for private data\n");
return -ENOMEM;
}
for (idx = 0; idx < ARRAY_SIZE(exynos_compat); idx++) {
if (of_device_is_compatible(np, exynos_compat[idx].compatible))
priv->ctrl_type = exynos_compat[idx].ctrl_type;
}
if (priv->ctrl_type == DW_MCI_TYPE_EXYNOS4412)
priv->ciu_div = EXYNOS4412_FIXED_CIU_CLK_DIV - 1;
else if (priv->ctrl_type == DW_MCI_TYPE_EXYNOS4210)
priv->ciu_div = EXYNOS4210_FIXED_CIU_CLK_DIV - 1;
else {
of_property_read_u32(np, "samsung,dw-mshc-ciu-div", &div);
priv->ciu_div = div;
}
ret = of_property_read_u32_array(np,
"samsung,dw-mshc-sdr-timing", timing, 2);
if (ret)
return ret;
priv->sdr_timing = SDMMC_CLKSEL_TIMING(timing[0], timing[1], div);
ret = of_property_read_u32_array(np,
"samsung,dw-mshc-ddr-timing", timing, 2);
if (ret)
return ret;
priv->ddr_timing = SDMMC_CLKSEL_TIMING(timing[0], timing[1], div);
host->priv = priv;
return 0;
}
static inline u8 dw_mci_exynos_get_clksmpl(struct dw_mci *host)
{
return SDMMC_CLKSEL_CCLK_SAMPLE(mci_readl(host, CLKSEL));
}
static inline void dw_mci_exynos_set_clksmpl(struct dw_mci *host, u8 sample)
{
u32 clksel;
clksel = mci_readl(host, CLKSEL);
clksel = (clksel & ~0x7) | SDMMC_CLKSEL_CCLK_SAMPLE(sample);
mci_writel(host, CLKSEL, clksel);
}
static inline u8 dw_mci_exynos_move_next_clksmpl(struct dw_mci *host)
{
u32 clksel;
u8 sample;
clksel = mci_readl(host, CLKSEL);
sample = (clksel + 1) & 0x7;
clksel = (clksel & ~0x7) | sample;
mci_writel(host, CLKSEL, clksel);
return sample;
}
static s8 dw_mci_exynos_get_best_clksmpl(u8 candiates)
{
const u8 iter = 8;
u8 __c;
s8 i, loc = -1;
for (i = 0; i < iter; i++) {
__c = ror8(candiates, i);
if ((__c & 0xc7) == 0xc7) {
loc = i;
goto out;
}
}
for (i = 0; i < iter; i++) {
__c = ror8(candiates, i);
if ((__c & 0x83) == 0x83) {
loc = i;
goto out;
}
}
out:
return loc;
}
static int dw_mci_exynos_execute_tuning(struct dw_mci_slot *slot, u32 opcode,
struct dw_mci_tuning_data *tuning_data)
{
struct dw_mci *host = slot->host;
struct mmc_host *mmc = slot->mmc;
const u8 *blk_pattern = tuning_data->blk_pattern;
u8 *blk_test;
unsigned int blksz = tuning_data->blksz;
u8 start_smpl, smpl, candiates = 0;
s8 found = -1;
int ret = 0;
blk_test = kmalloc(blksz, GFP_KERNEL);
if (!blk_test)
return -ENOMEM;
start_smpl = dw_mci_exynos_get_clksmpl(host);
do {
struct mmc_request mrq = {NULL};
struct mmc_command cmd = {0};
struct mmc_command stop = {0};
struct mmc_data data = {0};
struct scatterlist sg;
cmd.opcode = opcode;
cmd.arg = 0;
cmd.flags = MMC_RSP_R1 | MMC_CMD_ADTC;
stop.opcode = MMC_STOP_TRANSMISSION;
stop.arg = 0;
stop.flags = MMC_RSP_R1B | MMC_CMD_AC;
data.blksz = blksz;
data.blocks = 1;
data.flags = MMC_DATA_READ;
data.sg = &sg;
data.sg_len = 1;
sg_init_one(&sg, blk_test, blksz);
mrq.cmd = &cmd;
mrq.stop = &stop;
mrq.data = &data;
host->mrq = &mrq;
mci_writel(host, TMOUT, ~0);
smpl = dw_mci_exynos_move_next_clksmpl(host);
mmc_wait_for_req(mmc, &mrq);
if (!cmd.error && !data.error) {
if (!memcmp(blk_pattern, blk_test, blksz))
candiates |= (1 << smpl);
} else {
dev_dbg(host->dev,
"Tuning error: cmd.error:%d, data.error:%d\n",
cmd.error, data.error);
}
} while (start_smpl != smpl);
found = dw_mci_exynos_get_best_clksmpl(candiates);
if (found >= 0)
dw_mci_exynos_set_clksmpl(host, found);
else
ret = -EIO;
kfree(blk_test);
return ret;
}
static int dw_mci_exynos_probe(struct platform_device *pdev)
{
const struct dw_mci_drv_data *drv_data;
const struct of_device_id *match;
match = of_match_node(dw_mci_exynos_match, pdev->dev.of_node);
drv_data = match->data;
return dw_mci_pltfm_register(pdev, drv_data);
}
