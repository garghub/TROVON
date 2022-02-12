static inline int is_imx25_esdhc(struct pltfm_imx_data *data)
{
return data->socdata == &esdhc_imx25_data;
}
static inline int is_imx53_esdhc(struct pltfm_imx_data *data)
{
return data->socdata == &esdhc_imx53_data;
}
static inline int is_imx6q_usdhc(struct pltfm_imx_data *data)
{
return data->socdata == &usdhc_imx6q_data;
}
static inline int esdhc_is_usdhc(struct pltfm_imx_data *data)
{
return !!(data->socdata->flags & ESDHC_FLAG_USDHC);
}
static inline void esdhc_clrset_le(struct sdhci_host *host, u32 mask, u32 val, int reg)
{
void __iomem *base = host->ioaddr + (reg & ~0x3);
u32 shift = (reg & 0x3) * 8;
writel(((readl(base) & ~(mask << shift)) | (val << shift)), base);
}
static u32 esdhc_readl_le(struct sdhci_host *host, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
u32 val = readl(host->ioaddr + reg);
if (unlikely(reg == SDHCI_PRESENT_STATE)) {
u32 fsl_prss = val;
val = fsl_prss & 0x000FFFFF;
val |= (fsl_prss & 0x0F000000) >> 4;
val |= (fsl_prss & 0x00800000) << 1;
}
if (unlikely(reg == SDHCI_CAPABILITIES)) {
if (imx_data->socdata->flags & ESDHC_FLAG_HAVE_CAP1)
val &= 0xffff0000;
if (val & SDHCI_CAN_DO_ADMA1) {
val &= ~SDHCI_CAN_DO_ADMA1;
val |= SDHCI_CAN_DO_ADMA2;
}
}
if (unlikely(reg == SDHCI_CAPABILITIES_1)) {
if (esdhc_is_usdhc(imx_data)) {
if (imx_data->socdata->flags & ESDHC_FLAG_HAVE_CAP1)
val = readl(host->ioaddr + SDHCI_CAPABILITIES) & 0xFFFF;
else
val = SDHCI_SUPPORT_DDR50 | SDHCI_SUPPORT_SDR104
| SDHCI_SUPPORT_SDR50
| SDHCI_USE_SDR50_TUNING;
}
}
if (unlikely(reg == SDHCI_MAX_CURRENT) && esdhc_is_usdhc(imx_data)) {
val = 0;
val |= 0xFF << SDHCI_MAX_CURRENT_330_SHIFT;
val |= 0xFF << SDHCI_MAX_CURRENT_300_SHIFT;
val |= 0xFF << SDHCI_MAX_CURRENT_180_SHIFT;
}
if (unlikely(reg == SDHCI_INT_STATUS)) {
if (val & ESDHC_INT_VENDOR_SPEC_DMA_ERR) {
val &= ~ESDHC_INT_VENDOR_SPEC_DMA_ERR;
val |= SDHCI_INT_ADMA_ERROR;
}
if ((imx_data->multiblock_status == WAIT_FOR_INT) &&
((val & SDHCI_INT_RESPONSE) == SDHCI_INT_RESPONSE)) {
val &= ~SDHCI_INT_RESPONSE;
writel(SDHCI_INT_RESPONSE, host->ioaddr +
SDHCI_INT_STATUS);
imx_data->multiblock_status = NO_CMD_PENDING;
}
}
return val;
}
static void esdhc_writel_le(struct sdhci_host *host, u32 val, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
u32 data;
if (unlikely(reg == SDHCI_INT_ENABLE || reg == SDHCI_SIGNAL_ENABLE)) {
if (val & SDHCI_INT_CARD_INT) {
data = readl(host->ioaddr + SDHCI_HOST_CONTROL);
data &= ~ESDHC_CTRL_D3CD;
writel(data, host->ioaddr + SDHCI_HOST_CONTROL);
data |= ESDHC_CTRL_D3CD;
writel(data, host->ioaddr + SDHCI_HOST_CONTROL);
}
}
if (unlikely((imx_data->socdata->flags & ESDHC_FLAG_MULTIBLK_NO_INT)
&& (reg == SDHCI_INT_STATUS)
&& (val & SDHCI_INT_DATA_END))) {
u32 v;
v = readl(host->ioaddr + ESDHC_VENDOR_SPEC);
v &= ~ESDHC_VENDOR_SPEC_SDIO_QUIRK;
writel(v, host->ioaddr + ESDHC_VENDOR_SPEC);
if (imx_data->multiblock_status == MULTIBLK_IN_PROCESS)
{
data = MMC_STOP_TRANSMISSION << 24 |
SDHCI_CMD_ABORTCMD << 16;
writel(data, host->ioaddr + SDHCI_TRANSFER_MODE);
imx_data->multiblock_status = WAIT_FOR_INT;
}
}
if (unlikely(reg == SDHCI_INT_ENABLE || reg == SDHCI_SIGNAL_ENABLE)) {
if (val & SDHCI_INT_ADMA_ERROR) {
val &= ~SDHCI_INT_ADMA_ERROR;
val |= ESDHC_INT_VENDOR_SPEC_DMA_ERR;
}
}
writel(val, host->ioaddr + reg);
}
static u16 esdhc_readw_le(struct sdhci_host *host, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
u16 ret = 0;
u32 val;
if (unlikely(reg == SDHCI_HOST_VERSION)) {
reg ^= 2;
if (esdhc_is_usdhc(imx_data)) {
return SDHCI_SPEC_300;
}
}
if (unlikely(reg == SDHCI_HOST_CONTROL2)) {
val = readl(host->ioaddr + ESDHC_VENDOR_SPEC);
if (val & ESDHC_VENDOR_SPEC_VSELECT)
ret |= SDHCI_CTRL_VDD_180;
if (esdhc_is_usdhc(imx_data)) {
if (imx_data->socdata->flags & ESDHC_FLAG_MAN_TUNING)
val = readl(host->ioaddr + ESDHC_MIX_CTRL);
else if (imx_data->socdata->flags & ESDHC_FLAG_STD_TUNING)
val = readl(host->ioaddr + SDHCI_ACMD12_ERR);
}
if (val & ESDHC_MIX_CTRL_EXE_TUNE)
ret |= SDHCI_CTRL_EXEC_TUNING;
if (val & ESDHC_MIX_CTRL_SMPCLK_SEL)
ret |= SDHCI_CTRL_TUNED_CLK;
ret &= ~SDHCI_CTRL_PRESET_VAL_ENABLE;
return ret;
}
if (unlikely(reg == SDHCI_TRANSFER_MODE)) {
if (esdhc_is_usdhc(imx_data)) {
u32 m = readl(host->ioaddr + ESDHC_MIX_CTRL);
ret = m & ESDHC_MIX_CTRL_SDHCI_MASK;
if (m & ESDHC_MIX_CTRL_AC23EN) {
ret &= ~ESDHC_MIX_CTRL_AC23EN;
ret |= SDHCI_TRNS_AUTO_CMD23;
}
} else {
ret = readw(host->ioaddr + SDHCI_TRANSFER_MODE);
}
return ret;
}
return readw(host->ioaddr + reg);
}
static void esdhc_writew_le(struct sdhci_host *host, u16 val, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
u32 new_val = 0;
switch (reg) {
case SDHCI_CLOCK_CONTROL:
new_val = readl(host->ioaddr + ESDHC_VENDOR_SPEC);
if (val & SDHCI_CLOCK_CARD_EN)
new_val |= ESDHC_VENDOR_SPEC_FRC_SDCLK_ON;
else
new_val &= ~ESDHC_VENDOR_SPEC_FRC_SDCLK_ON;
writel(new_val, host->ioaddr + ESDHC_VENDOR_SPEC);
return;
case SDHCI_HOST_CONTROL2:
new_val = readl(host->ioaddr + ESDHC_VENDOR_SPEC);
if (val & SDHCI_CTRL_VDD_180)
new_val |= ESDHC_VENDOR_SPEC_VSELECT;
else
new_val &= ~ESDHC_VENDOR_SPEC_VSELECT;
writel(new_val, host->ioaddr + ESDHC_VENDOR_SPEC);
if (imx_data->socdata->flags & ESDHC_FLAG_MAN_TUNING) {
new_val = readl(host->ioaddr + ESDHC_MIX_CTRL);
if (val & SDHCI_CTRL_TUNED_CLK)
new_val |= ESDHC_MIX_CTRL_SMPCLK_SEL;
else
new_val &= ~ESDHC_MIX_CTRL_SMPCLK_SEL;
writel(new_val , host->ioaddr + ESDHC_MIX_CTRL);
} else if (imx_data->socdata->flags & ESDHC_FLAG_STD_TUNING) {
u32 v = readl(host->ioaddr + SDHCI_ACMD12_ERR);
u32 m = readl(host->ioaddr + ESDHC_MIX_CTRL);
if (val & SDHCI_CTRL_TUNED_CLK) {
v |= ESDHC_MIX_CTRL_SMPCLK_SEL;
} else {
v &= ~ESDHC_MIX_CTRL_SMPCLK_SEL;
m &= ~ESDHC_MIX_CTRL_FBCLK_SEL;
}
if (val & SDHCI_CTRL_EXEC_TUNING) {
v |= ESDHC_MIX_CTRL_EXE_TUNE;
m |= ESDHC_MIX_CTRL_FBCLK_SEL;
} else {
v &= ~ESDHC_MIX_CTRL_EXE_TUNE;
}
writel(v, host->ioaddr + SDHCI_ACMD12_ERR);
writel(m, host->ioaddr + ESDHC_MIX_CTRL);
}
return;
case SDHCI_TRANSFER_MODE:
if ((imx_data->socdata->flags & ESDHC_FLAG_MULTIBLK_NO_INT)
&& (host->cmd->opcode == SD_IO_RW_EXTENDED)
&& (host->cmd->data->blocks > 1)
&& (host->cmd->data->flags & MMC_DATA_READ)) {
u32 v;
v = readl(host->ioaddr + ESDHC_VENDOR_SPEC);
v |= ESDHC_VENDOR_SPEC_SDIO_QUIRK;
writel(v, host->ioaddr + ESDHC_VENDOR_SPEC);
}
if (esdhc_is_usdhc(imx_data)) {
u32 m = readl(host->ioaddr + ESDHC_MIX_CTRL);
if (val & SDHCI_TRNS_AUTO_CMD23) {
val &= ~SDHCI_TRNS_AUTO_CMD23;
val |= ESDHC_MIX_CTRL_AC23EN;
}
m = val | (m & ~ESDHC_MIX_CTRL_SDHCI_MASK);
writel(m, host->ioaddr + ESDHC_MIX_CTRL);
} else {
imx_data->scratchpad = val;
}
return;
case SDHCI_COMMAND:
if (host->cmd->opcode == MMC_STOP_TRANSMISSION)
val |= SDHCI_CMD_ABORTCMD;
if ((host->cmd->opcode == MMC_SET_BLOCK_COUNT) &&
(imx_data->socdata->flags & ESDHC_FLAG_MULTIBLK_NO_INT))
imx_data->multiblock_status = MULTIBLK_IN_PROCESS;
if (esdhc_is_usdhc(imx_data))
writel(val << 16,
host->ioaddr + SDHCI_TRANSFER_MODE);
else
writel(val << 16 | imx_data->scratchpad,
host->ioaddr + SDHCI_TRANSFER_MODE);
return;
case SDHCI_BLOCK_SIZE:
val &= ~SDHCI_MAKE_BLKSZ(0x7, 0);
break;
}
esdhc_clrset_le(host, 0xffff, val, reg);
}
static void esdhc_writeb_le(struct sdhci_host *host, u8 val, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
u32 new_val;
u32 mask;
switch (reg) {
case SDHCI_POWER_CONTROL:
return;
case SDHCI_HOST_CONTROL:
new_val = val & SDHCI_CTRL_LED;
new_val |= ESDHC_HOST_CONTROL_LE;
if (!is_imx25_esdhc(imx_data)) {
new_val |= (val & SDHCI_CTRL_DMA_MASK) << 5;
}
mask = 0xffff & ~(ESDHC_CTRL_BUSWIDTH_MASK | ESDHC_CTRL_D3CD);
esdhc_clrset_le(host, mask, new_val, reg);
return;
}
esdhc_clrset_le(host, 0xff, val, reg);
if ((reg == SDHCI_SOFTWARE_RESET) && (val & 1)) {
esdhc_clrset_le(host, 0x7, 0x7, ESDHC_SYSTEM_CONTROL);
if (esdhc_is_usdhc(imx_data)) {
new_val = readl(host->ioaddr + ESDHC_MIX_CTRL);
writel(new_val & ESDHC_MIX_CTRL_TUNING_MASK,
host->ioaddr + ESDHC_MIX_CTRL);
imx_data->is_ddr = 0;
}
}
}
static unsigned int esdhc_pltfm_get_max_clock(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
struct esdhc_platform_data *boarddata = &imx_data->boarddata;
if (boarddata->f_max && (boarddata->f_max < pltfm_host->clock))
return boarddata->f_max;
else
return pltfm_host->clock;
}
static unsigned int esdhc_pltfm_get_min_clock(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
return pltfm_host->clock / 256 / 16;
}
static inline void esdhc_pltfm_set_clock(struct sdhci_host *host,
unsigned int clock)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
unsigned int host_clock = pltfm_host->clock;
int pre_div = 2;
int div = 1;
u32 temp, val;
if (clock == 0) {
host->mmc->actual_clock = 0;
if (esdhc_is_usdhc(imx_data)) {
val = readl(host->ioaddr + ESDHC_VENDOR_SPEC);
writel(val & ~ESDHC_VENDOR_SPEC_FRC_SDCLK_ON,
host->ioaddr + ESDHC_VENDOR_SPEC);
}
return;
}
if (esdhc_is_usdhc(imx_data) && !imx_data->is_ddr)
pre_div = 1;
temp = sdhci_readl(host, ESDHC_SYSTEM_CONTROL);
temp &= ~(ESDHC_CLOCK_IPGEN | ESDHC_CLOCK_HCKEN | ESDHC_CLOCK_PEREN
| ESDHC_CLOCK_MASK);
sdhci_writel(host, temp, ESDHC_SYSTEM_CONTROL);
while (host_clock / pre_div / 16 > clock && pre_div < 256)
pre_div *= 2;
while (host_clock / pre_div / div > clock && div < 16)
div++;
host->mmc->actual_clock = host_clock / pre_div / div;
dev_dbg(mmc_dev(host->mmc), "desired SD clock: %d, actual: %d\n",
clock, host->mmc->actual_clock);
if (imx_data->is_ddr)
pre_div >>= 2;
else
pre_div >>= 1;
div--;
temp = sdhci_readl(host, ESDHC_SYSTEM_CONTROL);
temp |= (ESDHC_CLOCK_IPGEN | ESDHC_CLOCK_HCKEN | ESDHC_CLOCK_PEREN
| (div << ESDHC_DIVIDER_SHIFT)
| (pre_div << ESDHC_PREDIV_SHIFT));
sdhci_writel(host, temp, ESDHC_SYSTEM_CONTROL);
if (esdhc_is_usdhc(imx_data)) {
val = readl(host->ioaddr + ESDHC_VENDOR_SPEC);
writel(val | ESDHC_VENDOR_SPEC_FRC_SDCLK_ON,
host->ioaddr + ESDHC_VENDOR_SPEC);
}
mdelay(1);
}
static unsigned int esdhc_pltfm_get_ro(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
struct esdhc_platform_data *boarddata = &imx_data->boarddata;
switch (boarddata->wp_type) {
case ESDHC_WP_GPIO:
return mmc_gpio_get_ro(host->mmc);
case ESDHC_WP_CONTROLLER:
return !(readl(host->ioaddr + SDHCI_PRESENT_STATE) &
SDHCI_WRITE_PROTECT);
case ESDHC_WP_NONE:
break;
}
return -ENOSYS;
}
static void esdhc_pltfm_set_bus_width(struct sdhci_host *host, int width)
{
u32 ctrl;
switch (width) {
case MMC_BUS_WIDTH_8:
ctrl = ESDHC_CTRL_8BITBUS;
break;
case MMC_BUS_WIDTH_4:
ctrl = ESDHC_CTRL_4BITBUS;
break;
default:
ctrl = 0;
break;
}
esdhc_clrset_le(host, ESDHC_CTRL_BUSWIDTH_MASK, ctrl,
SDHCI_HOST_CONTROL);
}
static void esdhc_prepare_tuning(struct sdhci_host *host, u32 val)
{
u32 reg;
mdelay(1);
reg = readl(host->ioaddr + ESDHC_MIX_CTRL);
reg |= ESDHC_MIX_CTRL_EXE_TUNE | ESDHC_MIX_CTRL_SMPCLK_SEL |
ESDHC_MIX_CTRL_FBCLK_SEL;
writel(reg, host->ioaddr + ESDHC_MIX_CTRL);
writel(val << 8, host->ioaddr + ESDHC_TUNE_CTRL_STATUS);
dev_dbg(mmc_dev(host->mmc),
"tunning with delay 0x%x ESDHC_TUNE_CTRL_STATUS 0x%x\n",
val, readl(host->ioaddr + ESDHC_TUNE_CTRL_STATUS));
}
static void esdhc_post_tuning(struct sdhci_host *host)
{
u32 reg;
reg = readl(host->ioaddr + ESDHC_MIX_CTRL);
reg &= ~ESDHC_MIX_CTRL_EXE_TUNE;
writel(reg, host->ioaddr + ESDHC_MIX_CTRL);
}
static int esdhc_executing_tuning(struct sdhci_host *host, u32 opcode)
{
int min, max, avg, ret;
min = ESDHC_TUNE_CTRL_MIN;
while (min < ESDHC_TUNE_CTRL_MAX) {
esdhc_prepare_tuning(host, min);
if (!mmc_send_tuning(host->mmc))
break;
min += ESDHC_TUNE_CTRL_STEP;
}
max = min + ESDHC_TUNE_CTRL_STEP;
while (max < ESDHC_TUNE_CTRL_MAX) {
esdhc_prepare_tuning(host, max);
if (mmc_send_tuning(host->mmc)) {
max -= ESDHC_TUNE_CTRL_STEP;
break;
}
max += ESDHC_TUNE_CTRL_STEP;
}
avg = (min + max) / 2;
esdhc_prepare_tuning(host, avg);
ret = mmc_send_tuning(host->mmc);
esdhc_post_tuning(host);
dev_dbg(mmc_dev(host->mmc), "tunning %s at 0x%x ret %d\n",
ret ? "failed" : "passed", avg, ret);
return ret;
}
static int esdhc_change_pinstate(struct sdhci_host *host,
unsigned int uhs)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
struct pinctrl_state *pinctrl;
dev_dbg(mmc_dev(host->mmc), "change pinctrl state for uhs %d\n", uhs);
if (IS_ERR(imx_data->pinctrl) ||
IS_ERR(imx_data->pins_default) ||
IS_ERR(imx_data->pins_100mhz) ||
IS_ERR(imx_data->pins_200mhz))
return -EINVAL;
switch (uhs) {
case MMC_TIMING_UHS_SDR50:
pinctrl = imx_data->pins_100mhz;
break;
case MMC_TIMING_UHS_SDR104:
case MMC_TIMING_MMC_HS200:
pinctrl = imx_data->pins_200mhz;
break;
default:
pinctrl = imx_data->pins_default;
}
return pinctrl_select_state(imx_data->pinctrl, pinctrl);
}
static void esdhc_set_uhs_signaling(struct sdhci_host *host, unsigned timing)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
struct esdhc_platform_data *boarddata = &imx_data->boarddata;
switch (timing) {
case MMC_TIMING_UHS_SDR12:
case MMC_TIMING_UHS_SDR25:
case MMC_TIMING_UHS_SDR50:
case MMC_TIMING_UHS_SDR104:
case MMC_TIMING_MMC_HS200:
break;
case MMC_TIMING_UHS_DDR50:
case MMC_TIMING_MMC_DDR52:
writel(readl(host->ioaddr + ESDHC_MIX_CTRL) |
ESDHC_MIX_CTRL_DDREN,
host->ioaddr + ESDHC_MIX_CTRL);
imx_data->is_ddr = 1;
if (boarddata->delay_line) {
u32 v;
v = boarddata->delay_line <<
ESDHC_DLL_OVERRIDE_VAL_SHIFT |
(1 << ESDHC_DLL_OVERRIDE_EN_SHIFT);
if (is_imx53_esdhc(imx_data))
v <<= 1;
writel(v, host->ioaddr + ESDHC_DLL_CTRL);
}
break;
}
esdhc_change_pinstate(host, timing);
}
static void esdhc_reset(struct sdhci_host *host, u8 mask)
{
sdhci_reset(host, mask);
sdhci_writel(host, host->ier, SDHCI_INT_ENABLE);
sdhci_writel(host, host->ier, SDHCI_SIGNAL_ENABLE);
}
static unsigned int esdhc_get_max_timeout_count(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
return esdhc_is_usdhc(imx_data) ? 1 << 28 : 1 << 27;
}
static void esdhc_set_timeout(struct sdhci_host *host, struct mmc_command *cmd)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
sdhci_writeb(host, esdhc_is_usdhc(imx_data) ? 0xF : 0xE,
SDHCI_TIMEOUT_CONTROL);
}
static int
sdhci_esdhc_imx_probe_dt(struct platform_device *pdev,
struct esdhc_platform_data *boarddata)
{
struct device_node *np = pdev->dev.of_node;
if (!np)
return -ENODEV;
if (of_get_property(np, "non-removable", NULL))
boarddata->cd_type = ESDHC_CD_PERMANENT;
if (of_get_property(np, "fsl,cd-controller", NULL))
boarddata->cd_type = ESDHC_CD_CONTROLLER;
if (of_get_property(np, "fsl,wp-controller", NULL))
boarddata->wp_type = ESDHC_WP_CONTROLLER;
boarddata->cd_gpio = of_get_named_gpio(np, "cd-gpios", 0);
if (gpio_is_valid(boarddata->cd_gpio))
boarddata->cd_type = ESDHC_CD_GPIO;
boarddata->wp_gpio = of_get_named_gpio(np, "wp-gpios", 0);
if (gpio_is_valid(boarddata->wp_gpio))
boarddata->wp_type = ESDHC_WP_GPIO;
of_property_read_u32(np, "bus-width", &boarddata->max_bus_width);
of_property_read_u32(np, "max-frequency", &boarddata->f_max);
if (of_find_property(np, "no-1-8-v", NULL))
boarddata->support_vsel = false;
else
boarddata->support_vsel = true;
if (of_property_read_u32(np, "fsl,delay-line", &boarddata->delay_line))
boarddata->delay_line = 0;
return 0;
}
static inline int
sdhci_esdhc_imx_probe_dt(struct platform_device *pdev,
struct esdhc_platform_data *boarddata)
{
return -ENODEV;
}
static int sdhci_esdhc_imx_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(imx_esdhc_dt_ids, &pdev->dev);
struct sdhci_pltfm_host *pltfm_host;
struct sdhci_host *host;
struct esdhc_platform_data *boarddata;
int err;
struct pltfm_imx_data *imx_data;
host = sdhci_pltfm_init(pdev, &sdhci_esdhc_imx_pdata, 0);
if (IS_ERR(host))
return PTR_ERR(host);
pltfm_host = sdhci_priv(host);
imx_data = devm_kzalloc(&pdev->dev, sizeof(*imx_data), GFP_KERNEL);
if (!imx_data) {
err = -ENOMEM;
goto free_sdhci;
}
imx_data->socdata = of_id ? of_id->data : (struct esdhc_soc_data *)
pdev->id_entry->driver_data;
pltfm_host->priv = imx_data;
imx_data->clk_ipg = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(imx_data->clk_ipg)) {
err = PTR_ERR(imx_data->clk_ipg);
goto free_sdhci;
}
imx_data->clk_ahb = devm_clk_get(&pdev->dev, "ahb");
if (IS_ERR(imx_data->clk_ahb)) {
err = PTR_ERR(imx_data->clk_ahb);
goto free_sdhci;
}
imx_data->clk_per = devm_clk_get(&pdev->dev, "per");
if (IS_ERR(imx_data->clk_per)) {
err = PTR_ERR(imx_data->clk_per);
goto free_sdhci;
}
pltfm_host->clk = imx_data->clk_per;
pltfm_host->clock = clk_get_rate(pltfm_host->clk);
clk_prepare_enable(imx_data->clk_per);
clk_prepare_enable(imx_data->clk_ipg);
clk_prepare_enable(imx_data->clk_ahb);
imx_data->pinctrl = devm_pinctrl_get(&pdev->dev);
if (IS_ERR(imx_data->pinctrl)) {
err = PTR_ERR(imx_data->pinctrl);
goto disable_clk;
}
imx_data->pins_default = pinctrl_lookup_state(imx_data->pinctrl,
PINCTRL_STATE_DEFAULT);
if (IS_ERR(imx_data->pins_default))
dev_warn(mmc_dev(host->mmc), "could not get default state\n");
host->quirks |= SDHCI_QUIRK_BROKEN_TIMEOUT_VAL;
if (imx_data->socdata->flags & ESDHC_FLAG_ENGCM07207)
host->quirks |= SDHCI_QUIRK_NO_MULTIBLOCK
| SDHCI_QUIRK_BROKEN_ADMA;
if (esdhc_is_usdhc(imx_data)) {
writel(0x08100810, host->ioaddr + ESDHC_WTMK_LVL);
host->quirks2 |= SDHCI_QUIRK2_PRESET_VALUE_BROKEN;
host->mmc->caps |= MMC_CAP_1_8V_DDR;
}
if (imx_data->socdata->flags & ESDHC_FLAG_MAN_TUNING)
sdhci_esdhc_ops.platform_execute_tuning =
esdhc_executing_tuning;
if (imx_data->socdata->flags & ESDHC_FLAG_STD_TUNING)
writel(readl(host->ioaddr + ESDHC_TUNING_CTRL) |
ESDHC_STD_TUNING_EN | ESDHC_TUNING_START_TAP,
host->ioaddr + ESDHC_TUNING_CTRL);
boarddata = &imx_data->boarddata;
if (sdhci_esdhc_imx_probe_dt(pdev, boarddata) < 0) {
if (!host->mmc->parent->platform_data) {
dev_err(mmc_dev(host->mmc), "no board data!\n");
err = -EINVAL;
goto disable_clk;
}
imx_data->boarddata = *((struct esdhc_platform_data *)
host->mmc->parent->platform_data);
}
if (boarddata->wp_type == ESDHC_WP_GPIO) {
err = mmc_gpio_request_ro(host->mmc, boarddata->wp_gpio);
if (err) {
dev_err(mmc_dev(host->mmc),
"failed to request write-protect gpio!\n");
goto disable_clk;
}
host->mmc->caps2 |= MMC_CAP2_RO_ACTIVE_HIGH;
}
switch (boarddata->cd_type) {
case ESDHC_CD_GPIO:
err = mmc_gpio_request_cd(host->mmc, boarddata->cd_gpio, 0);
if (err) {
dev_err(mmc_dev(host->mmc),
"failed to request card-detect gpio!\n");
goto disable_clk;
}
case ESDHC_CD_CONTROLLER:
host->quirks &= ~SDHCI_QUIRK_BROKEN_CARD_DETECTION;
break;
case ESDHC_CD_PERMANENT:
host->mmc->caps |= MMC_CAP_NONREMOVABLE;
break;
case ESDHC_CD_NONE:
break;
}
switch (boarddata->max_bus_width) {
case 8:
host->mmc->caps |= MMC_CAP_8_BIT_DATA | MMC_CAP_4_BIT_DATA;
break;
case 4:
host->mmc->caps |= MMC_CAP_4_BIT_DATA;
break;
case 1:
default:
host->quirks |= SDHCI_QUIRK_FORCE_1_BIT_DATA;
break;
}
if ((boarddata->support_vsel) && esdhc_is_usdhc(imx_data) &&
!IS_ERR(imx_data->pins_default)) {
imx_data->pins_100mhz = pinctrl_lookup_state(imx_data->pinctrl,
ESDHC_PINCTRL_STATE_100MHZ);
imx_data->pins_200mhz = pinctrl_lookup_state(imx_data->pinctrl,
ESDHC_PINCTRL_STATE_200MHZ);
if (IS_ERR(imx_data->pins_100mhz) ||
IS_ERR(imx_data->pins_200mhz)) {
dev_warn(mmc_dev(host->mmc),
"could not get ultra high speed state, work on normal mode\n");
host->quirks2 |= SDHCI_QUIRK2_NO_1_8_V;
}
} else {
host->quirks2 |= SDHCI_QUIRK2_NO_1_8_V;
}
err = sdhci_add_host(host);
if (err)
goto disable_clk;
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
pm_runtime_set_autosuspend_delay(&pdev->dev, 50);
pm_runtime_use_autosuspend(&pdev->dev);
pm_suspend_ignore_children(&pdev->dev, 1);
return 0;
disable_clk:
clk_disable_unprepare(imx_data->clk_per);
clk_disable_unprepare(imx_data->clk_ipg);
clk_disable_unprepare(imx_data->clk_ahb);
free_sdhci:
sdhci_pltfm_free(pdev);
return err;
}
static int sdhci_esdhc_imx_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
int dead = (readl(host->ioaddr + SDHCI_INT_STATUS) == 0xffffffff);
sdhci_remove_host(host, dead);
pm_runtime_dont_use_autosuspend(&pdev->dev);
pm_runtime_disable(&pdev->dev);
if (!IS_ENABLED(CONFIG_PM)) {
clk_disable_unprepare(imx_data->clk_per);
clk_disable_unprepare(imx_data->clk_ipg);
clk_disable_unprepare(imx_data->clk_ahb);
}
sdhci_pltfm_free(pdev);
return 0;
}
static int sdhci_esdhc_runtime_suspend(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
int ret;
ret = sdhci_runtime_suspend_host(host);
if (!sdhci_sdio_irq_enabled(host)) {
clk_disable_unprepare(imx_data->clk_per);
clk_disable_unprepare(imx_data->clk_ipg);
}
clk_disable_unprepare(imx_data->clk_ahb);
return ret;
}
static int sdhci_esdhc_runtime_resume(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
if (!sdhci_sdio_irq_enabled(host)) {
clk_prepare_enable(imx_data->clk_per);
clk_prepare_enable(imx_data->clk_ipg);
}
clk_prepare_enable(imx_data->clk_ahb);
return sdhci_runtime_resume_host(host);
}
