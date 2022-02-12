static inline int msm_dll_poll_ck_out_en(struct sdhci_host *host, u8 poll)
{
u32 wait_cnt = 50;
u8 ck_out_en;
struct mmc_host *mmc = host->mmc;
ck_out_en = !!(readl_relaxed(host->ioaddr + CORE_DLL_CONFIG) &
CORE_CK_OUT_EN);
while (ck_out_en != poll) {
if (--wait_cnt == 0) {
dev_err(mmc_dev(mmc), "%s: CK_OUT_EN bit is not %d\n",
mmc_hostname(mmc), poll);
return -ETIMEDOUT;
}
udelay(1);
ck_out_en = !!(readl_relaxed(host->ioaddr + CORE_DLL_CONFIG) &
CORE_CK_OUT_EN);
}
return 0;
}
static int msm_config_cm_dll_phase(struct sdhci_host *host, u8 phase)
{
int rc;
static const u8 grey_coded_phase_table[] = {
0x0, 0x1, 0x3, 0x2, 0x6, 0x7, 0x5, 0x4,
0xc, 0xd, 0xf, 0xe, 0xa, 0xb, 0x9, 0x8
};
unsigned long flags;
u32 config;
struct mmc_host *mmc = host->mmc;
spin_lock_irqsave(&host->lock, flags);
config = readl_relaxed(host->ioaddr + CORE_DLL_CONFIG);
config &= ~(CORE_CDR_EN | CORE_CK_OUT_EN);
config |= (CORE_CDR_EXT_EN | CORE_DLL_EN);
writel_relaxed(config, host->ioaddr + CORE_DLL_CONFIG);
rc = msm_dll_poll_ck_out_en(host, 0);
if (rc)
goto err_out;
config = readl_relaxed(host->ioaddr + CORE_DLL_CONFIG);
config &= ~CDR_SELEXT_MASK;
config |= grey_coded_phase_table[phase] << CDR_SELEXT_SHIFT;
writel_relaxed(config, host->ioaddr + CORE_DLL_CONFIG);
writel_relaxed((readl_relaxed(host->ioaddr + CORE_DLL_CONFIG)
| CORE_CK_OUT_EN), host->ioaddr + CORE_DLL_CONFIG);
rc = msm_dll_poll_ck_out_en(host, 1);
if (rc)
goto err_out;
config = readl_relaxed(host->ioaddr + CORE_DLL_CONFIG);
config |= CORE_CDR_EN;
config &= ~CORE_CDR_EXT_EN;
writel_relaxed(config, host->ioaddr + CORE_DLL_CONFIG);
goto out;
err_out:
dev_err(mmc_dev(mmc), "%s: Failed to set DLL phase: %d\n",
mmc_hostname(mmc), phase);
out:
spin_unlock_irqrestore(&host->lock, flags);
return rc;
}
static int msm_find_most_appropriate_phase(struct sdhci_host *host,
u8 *phase_table, u8 total_phases)
{
int ret;
u8 ranges[MAX_PHASES][MAX_PHASES] = { {0}, {0} };
u8 phases_per_row[MAX_PHASES] = { 0 };
int row_index = 0, col_index = 0, selected_row_index = 0, curr_max = 0;
int i, cnt, phase_0_raw_index = 0, phase_15_raw_index = 0;
bool phase_0_found = false, phase_15_found = false;
struct mmc_host *mmc = host->mmc;
if (!total_phases || (total_phases > MAX_PHASES)) {
dev_err(mmc_dev(mmc), "%s: Invalid argument: total_phases=%d\n",
mmc_hostname(mmc), total_phases);
return -EINVAL;
}
for (cnt = 0; cnt < total_phases; cnt++) {
ranges[row_index][col_index] = phase_table[cnt];
phases_per_row[row_index] += 1;
col_index++;
if ((cnt + 1) == total_phases) {
continue;
} else if ((phase_table[cnt] + 1) != phase_table[cnt + 1]) {
row_index++;
col_index = 0;
}
}
if (row_index >= MAX_PHASES)
return -EINVAL;
if (!ranges[0][0]) {
phase_0_found = true;
phase_0_raw_index = 0;
for (cnt = 1; cnt <= row_index; cnt++) {
if (phases_per_row[cnt]) {
for (i = 0; i < phases_per_row[cnt]; i++) {
if (ranges[cnt][i] == 15) {
phase_15_found = true;
phase_15_raw_index = cnt;
break;
}
}
}
}
}
if (phase_0_found && phase_15_found) {
u8 phases_0 = phases_per_row[phase_0_raw_index];
u8 phases_15 = phases_per_row[phase_15_raw_index];
if (phases_0 + phases_15 >= MAX_PHASES)
return -EINVAL;
i = phases_15;
for (cnt = 0; cnt < phases_0; cnt++) {
ranges[phase_15_raw_index][i] =
ranges[phase_0_raw_index][cnt];
if (++i >= MAX_PHASES)
break;
}
phases_per_row[phase_0_raw_index] = 0;
phases_per_row[phase_15_raw_index] = phases_15 + phases_0;
}
for (cnt = 0; cnt <= row_index; cnt++) {
if (phases_per_row[cnt] > curr_max) {
curr_max = phases_per_row[cnt];
selected_row_index = cnt;
}
}
i = (curr_max * 3) / 4;
if (i)
i--;
ret = ranges[selected_row_index][i];
if (ret >= MAX_PHASES) {
ret = -EINVAL;
dev_err(mmc_dev(mmc), "%s: Invalid phase selected=%d\n",
mmc_hostname(mmc), ret);
}
return ret;
}
static inline void msm_cm_dll_set_freq(struct sdhci_host *host)
{
u32 mclk_freq = 0, config;
if (host->clock <= 112000000)
mclk_freq = 0;
else if (host->clock <= 125000000)
mclk_freq = 1;
else if (host->clock <= 137000000)
mclk_freq = 2;
else if (host->clock <= 150000000)
mclk_freq = 3;
else if (host->clock <= 162000000)
mclk_freq = 4;
else if (host->clock <= 175000000)
mclk_freq = 5;
else if (host->clock <= 187000000)
mclk_freq = 6;
else if (host->clock <= 200000000)
mclk_freq = 7;
config = readl_relaxed(host->ioaddr + CORE_DLL_CONFIG);
config &= ~CMUX_SHIFT_PHASE_MASK;
config |= mclk_freq << CMUX_SHIFT_PHASE_SHIFT;
writel_relaxed(config, host->ioaddr + CORE_DLL_CONFIG);
}
static int msm_init_cm_dll(struct sdhci_host *host)
{
struct mmc_host *mmc = host->mmc;
int wait_cnt = 50;
unsigned long flags;
spin_lock_irqsave(&host->lock, flags);
writel_relaxed((readl_relaxed(host->ioaddr + CORE_VENDOR_SPEC)
& ~CORE_CLK_PWRSAVE), host->ioaddr + CORE_VENDOR_SPEC);
writel_relaxed((readl_relaxed(host->ioaddr + CORE_DLL_CONFIG)
| CORE_DLL_RST), host->ioaddr + CORE_DLL_CONFIG);
writel_relaxed((readl_relaxed(host->ioaddr + CORE_DLL_CONFIG)
| CORE_DLL_PDN), host->ioaddr + CORE_DLL_CONFIG);
msm_cm_dll_set_freq(host);
writel_relaxed((readl_relaxed(host->ioaddr + CORE_DLL_CONFIG)
& ~CORE_DLL_RST), host->ioaddr + CORE_DLL_CONFIG);
writel_relaxed((readl_relaxed(host->ioaddr + CORE_DLL_CONFIG)
& ~CORE_DLL_PDN), host->ioaddr + CORE_DLL_CONFIG);
writel_relaxed((readl_relaxed(host->ioaddr + CORE_DLL_CONFIG)
| CORE_DLL_EN), host->ioaddr + CORE_DLL_CONFIG);
writel_relaxed((readl_relaxed(host->ioaddr + CORE_DLL_CONFIG)
| CORE_CK_OUT_EN), host->ioaddr + CORE_DLL_CONFIG);
while (!(readl_relaxed(host->ioaddr + CORE_DLL_STATUS) &
CORE_DLL_LOCK)) {
if (--wait_cnt == 0) {
dev_err(mmc_dev(mmc), "%s: DLL failed to LOCK\n",
mmc_hostname(mmc));
spin_unlock_irqrestore(&host->lock, flags);
return -ETIMEDOUT;
}
udelay(1);
}
spin_unlock_irqrestore(&host->lock, flags);
return 0;
}
static int sdhci_msm_execute_tuning(struct sdhci_host *host, u32 opcode)
{
int tuning_seq_cnt = 3;
u8 phase, tuned_phases[16], tuned_phase_cnt = 0;
int rc;
struct mmc_host *mmc = host->mmc;
struct mmc_ios ios = host->mmc->ios;
if (host->clock <= 100 * 1000 * 1000 ||
!((ios.timing == MMC_TIMING_MMC_HS200) ||
(ios.timing == MMC_TIMING_UHS_SDR104)))
return 0;
retry:
rc = msm_init_cm_dll(host);
if (rc)
return rc;
phase = 0;
do {
rc = msm_config_cm_dll_phase(host, phase);
if (rc)
return rc;
rc = mmc_send_tuning(mmc, opcode, NULL);
if (!rc) {
tuned_phases[tuned_phase_cnt++] = phase;
dev_dbg(mmc_dev(mmc), "%s: Found good phase = %d\n",
mmc_hostname(mmc), phase);
}
} while (++phase < ARRAY_SIZE(tuned_phases));
if (tuned_phase_cnt) {
rc = msm_find_most_appropriate_phase(host, tuned_phases,
tuned_phase_cnt);
if (rc < 0)
return rc;
else
phase = rc;
rc = msm_config_cm_dll_phase(host, phase);
if (rc)
return rc;
dev_dbg(mmc_dev(mmc), "%s: Setting the tuning phase to %d\n",
mmc_hostname(mmc), phase);
} else {
if (--tuning_seq_cnt)
goto retry;
dev_dbg(mmc_dev(mmc), "%s: No tuning point found\n",
mmc_hostname(mmc));
rc = -EIO;
}
return rc;
}
static int sdhci_msm_probe(struct platform_device *pdev)
{
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
struct sdhci_msm_host *msm_host;
struct resource *core_memres;
int ret;
u16 host_version, core_minor;
u32 core_version, caps;
u8 core_major;
host = sdhci_pltfm_init(pdev, &sdhci_msm_pdata, sizeof(*msm_host));
if (IS_ERR(host))
return PTR_ERR(host);
pltfm_host = sdhci_priv(host);
msm_host = sdhci_pltfm_priv(pltfm_host);
msm_host->mmc = host->mmc;
msm_host->pdev = pdev;
ret = mmc_of_parse(host->mmc);
if (ret)
goto pltfm_free;
sdhci_get_of_property(pdev);
msm_host->bus_clk = devm_clk_get(&pdev->dev, "bus");
if (!IS_ERR(msm_host->bus_clk)) {
ret = clk_set_rate(msm_host->bus_clk, INT_MAX);
if (ret)
goto pltfm_free;
ret = clk_prepare_enable(msm_host->bus_clk);
if (ret)
goto pltfm_free;
}
msm_host->pclk = devm_clk_get(&pdev->dev, "iface");
if (IS_ERR(msm_host->pclk)) {
ret = PTR_ERR(msm_host->pclk);
dev_err(&pdev->dev, "Perpheral clk setup failed (%d)\n", ret);
goto bus_clk_disable;
}
ret = clk_prepare_enable(msm_host->pclk);
if (ret)
goto bus_clk_disable;
msm_host->clk = devm_clk_get(&pdev->dev, "core");
if (IS_ERR(msm_host->clk)) {
ret = PTR_ERR(msm_host->clk);
dev_err(&pdev->dev, "SDC MMC clk setup failed (%d)\n", ret);
goto pclk_disable;
}
ret = clk_set_rate(msm_host->clk, INT_MAX);
if (ret)
dev_warn(&pdev->dev, "core clock boost failed\n");
ret = clk_prepare_enable(msm_host->clk);
if (ret)
goto pclk_disable;
core_memres = platform_get_resource(pdev, IORESOURCE_MEM, 1);
msm_host->core_mem = devm_ioremap_resource(&pdev->dev, core_memres);
if (IS_ERR(msm_host->core_mem)) {
dev_err(&pdev->dev, "Failed to remap registers\n");
ret = PTR_ERR(msm_host->core_mem);
goto clk_disable;
}
writel_relaxed(readl_relaxed(msm_host->core_mem + CORE_POWER) |
CORE_SW_RST, msm_host->core_mem + CORE_POWER);
usleep_range(1000, 5000);
if (readl(msm_host->core_mem + CORE_POWER) & CORE_SW_RST) {
dev_err(&pdev->dev, "Stuck in reset\n");
ret = -ETIMEDOUT;
goto clk_disable;
}
writel_relaxed(HC_MODE_EN, (msm_host->core_mem + CORE_HC_MODE));
host_version = readw_relaxed((host->ioaddr + SDHCI_HOST_VERSION));
dev_dbg(&pdev->dev, "Host Version: 0x%x Vendor Version 0x%x\n",
host_version, ((host_version & SDHCI_VENDOR_VER_MASK) >>
SDHCI_VENDOR_VER_SHIFT));
core_version = readl_relaxed(msm_host->core_mem + CORE_MCI_VERSION);
core_major = (core_version & CORE_VERSION_MAJOR_MASK) >>
CORE_VERSION_MAJOR_SHIFT;
core_minor = core_version & CORE_VERSION_MINOR_MASK;
dev_dbg(&pdev->dev, "MCI Version: 0x%08x, major: 0x%04x, minor: 0x%02x\n",
core_version, core_major, core_minor);
if (core_major >= 1 && core_minor != 0x11 && core_minor != 0x12) {
caps = readl_relaxed(host->ioaddr + SDHCI_CAPABILITIES);
caps |= SDHCI_CAN_VDD_300 | SDHCI_CAN_DO_8BIT;
writel_relaxed(caps, host->ioaddr +
CORE_VENDOR_SPEC_CAPABILITIES0);
}
ret = sdhci_add_host(host);
if (ret)
goto clk_disable;
return 0;
clk_disable:
clk_disable_unprepare(msm_host->clk);
pclk_disable:
clk_disable_unprepare(msm_host->pclk);
bus_clk_disable:
if (!IS_ERR(msm_host->bus_clk))
clk_disable_unprepare(msm_host->bus_clk);
pltfm_free:
sdhci_pltfm_free(pdev);
return ret;
}
static int sdhci_msm_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_msm_host *msm_host = sdhci_pltfm_priv(pltfm_host);
int dead = (readl_relaxed(host->ioaddr + SDHCI_INT_STATUS) ==
0xffffffff);
sdhci_remove_host(host, dead);
clk_disable_unprepare(msm_host->clk);
clk_disable_unprepare(msm_host->pclk);
if (!IS_ERR(msm_host->bus_clk))
clk_disable_unprepare(msm_host->bus_clk);
sdhci_pltfm_free(pdev);
return 0;
}
