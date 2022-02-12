static int omap_hsmmc_card_detect(struct device *dev)
{
struct omap_hsmmc_host *host = dev_get_drvdata(dev);
return mmc_gpio_get_cd(host->mmc);
}
static int omap_hsmmc_get_cover_state(struct device *dev)
{
struct omap_hsmmc_host *host = dev_get_drvdata(dev);
return mmc_gpio_get_cd(host->mmc);
}
static int omap_hsmmc_enable_supply(struct mmc_host *mmc)
{
int ret;
struct omap_hsmmc_host *host = mmc_priv(mmc);
struct mmc_ios *ios = &mmc->ios;
if (mmc->supply.vmmc) {
ret = mmc_regulator_set_ocr(mmc, mmc->supply.vmmc, ios->vdd);
if (ret)
return ret;
}
if (mmc->supply.vqmmc && !host->vqmmc_enabled) {
ret = regulator_enable(mmc->supply.vqmmc);
if (ret) {
dev_err(mmc_dev(mmc), "vmmc_aux reg enable failed\n");
goto err_vqmmc;
}
host->vqmmc_enabled = 1;
}
return 0;
err_vqmmc:
if (mmc->supply.vmmc)
mmc_regulator_set_ocr(mmc, mmc->supply.vmmc, 0);
return ret;
}
static int omap_hsmmc_disable_supply(struct mmc_host *mmc)
{
int ret;
int status;
struct omap_hsmmc_host *host = mmc_priv(mmc);
if (mmc->supply.vqmmc && host->vqmmc_enabled) {
ret = regulator_disable(mmc->supply.vqmmc);
if (ret) {
dev_err(mmc_dev(mmc), "vmmc_aux reg disable failed\n");
return ret;
}
host->vqmmc_enabled = 0;
}
if (mmc->supply.vmmc) {
ret = mmc_regulator_set_ocr(mmc, mmc->supply.vmmc, 0);
if (ret)
goto err_set_ocr;
}
return 0;
err_set_ocr:
if (mmc->supply.vqmmc) {
status = regulator_enable(mmc->supply.vqmmc);
if (status)
dev_err(mmc_dev(mmc), "vmmc_aux re-enable failed\n");
}
return ret;
}
static int omap_hsmmc_set_pbias(struct omap_hsmmc_host *host, bool power_on,
int vdd)
{
int ret;
if (!host->pbias)
return 0;
if (power_on) {
if (vdd <= VDD_165_195)
ret = regulator_set_voltage(host->pbias, VDD_1V8,
VDD_1V8);
else
ret = regulator_set_voltage(host->pbias, VDD_3V0,
VDD_3V0);
if (ret < 0) {
dev_err(host->dev, "pbias set voltage fail\n");
return ret;
}
if (host->pbias_enabled == 0) {
ret = regulator_enable(host->pbias);
if (ret) {
dev_err(host->dev, "pbias reg enable fail\n");
return ret;
}
host->pbias_enabled = 1;
}
} else {
if (host->pbias_enabled == 1) {
ret = regulator_disable(host->pbias);
if (ret) {
dev_err(host->dev, "pbias reg disable fail\n");
return ret;
}
host->pbias_enabled = 0;
}
}
return 0;
}
static int omap_hsmmc_set_power(struct omap_hsmmc_host *host, int power_on,
int vdd)
{
struct mmc_host *mmc = host->mmc;
int ret = 0;
if (mmc_pdata(host)->set_power)
return mmc_pdata(host)->set_power(host->dev, power_on, vdd);
if (!mmc->supply.vmmc)
return 0;
if (mmc_pdata(host)->before_set_reg)
mmc_pdata(host)->before_set_reg(host->dev, power_on, vdd);
ret = omap_hsmmc_set_pbias(host, false, 0);
if (ret)
return ret;
if (power_on) {
ret = omap_hsmmc_enable_supply(mmc);
if (ret)
return ret;
ret = omap_hsmmc_set_pbias(host, true, vdd);
if (ret)
goto err_set_voltage;
} else {
ret = omap_hsmmc_disable_supply(mmc);
if (ret)
return ret;
}
if (mmc_pdata(host)->after_set_reg)
mmc_pdata(host)->after_set_reg(host->dev, power_on, vdd);
return 0;
err_set_voltage:
omap_hsmmc_disable_supply(mmc);
return ret;
}
static int omap_hsmmc_disable_boot_regulator(struct regulator *reg)
{
int ret;
if (!reg)
return 0;
if (regulator_is_enabled(reg)) {
ret = regulator_enable(reg);
if (ret)
return ret;
ret = regulator_disable(reg);
if (ret)
return ret;
}
return 0;
}
static int omap_hsmmc_disable_boot_regulators(struct omap_hsmmc_host *host)
{
struct mmc_host *mmc = host->mmc;
int ret;
ret = omap_hsmmc_disable_boot_regulator(mmc->supply.vmmc);
if (ret) {
dev_err(host->dev, "fail to disable boot enabled vmmc reg\n");
return ret;
}
ret = omap_hsmmc_disable_boot_regulator(mmc->supply.vqmmc);
if (ret) {
dev_err(host->dev,
"fail to disable boot enabled vmmc_aux reg\n");
return ret;
}
ret = omap_hsmmc_disable_boot_regulator(host->pbias);
if (ret) {
dev_err(host->dev,
"failed to disable boot enabled pbias reg\n");
return ret;
}
return 0;
}
static int omap_hsmmc_reg_get(struct omap_hsmmc_host *host)
{
int ocr_value = 0;
int ret;
struct mmc_host *mmc = host->mmc;
if (mmc_pdata(host)->set_power)
return 0;
mmc->supply.vmmc = devm_regulator_get_optional(host->dev, "vmmc");
if (IS_ERR(mmc->supply.vmmc)) {
ret = PTR_ERR(mmc->supply.vmmc);
if ((ret != -ENODEV) && host->dev->of_node)
return ret;
dev_dbg(host->dev, "unable to get vmmc regulator %ld\n",
PTR_ERR(mmc->supply.vmmc));
mmc->supply.vmmc = NULL;
} else {
ocr_value = mmc_regulator_get_ocrmask(mmc->supply.vmmc);
if (ocr_value > 0)
mmc_pdata(host)->ocr_mask = ocr_value;
}
mmc->supply.vqmmc = devm_regulator_get_optional(host->dev, "vmmc_aux");
if (IS_ERR(mmc->supply.vqmmc)) {
ret = PTR_ERR(mmc->supply.vqmmc);
if ((ret != -ENODEV) && host->dev->of_node)
return ret;
dev_dbg(host->dev, "unable to get vmmc_aux regulator %ld\n",
PTR_ERR(mmc->supply.vqmmc));
mmc->supply.vqmmc = NULL;
}
host->pbias = devm_regulator_get_optional(host->dev, "pbias");
if (IS_ERR(host->pbias)) {
ret = PTR_ERR(host->pbias);
if ((ret != -ENODEV) && host->dev->of_node) {
dev_err(host->dev,
"SD card detect fail? enable CONFIG_REGULATOR_PBIAS\n");
return ret;
}
dev_dbg(host->dev, "unable to get pbias regulator %ld\n",
PTR_ERR(host->pbias));
host->pbias = NULL;
}
if (mmc_pdata(host)->no_regulator_off_init)
return 0;
ret = omap_hsmmc_disable_boot_regulators(host);
if (ret)
return ret;
return 0;
}
static int omap_hsmmc_gpio_init(struct mmc_host *mmc,
struct omap_hsmmc_host *host,
struct omap_hsmmc_platform_data *pdata)
{
int ret;
if (gpio_is_valid(pdata->gpio_cod)) {
ret = mmc_gpio_request_cd(mmc, pdata->gpio_cod, 0);
if (ret)
return ret;
host->get_cover_state = omap_hsmmc_get_cover_state;
mmc_gpio_set_cd_isr(mmc, omap_hsmmc_cover_irq);
} else if (gpio_is_valid(pdata->gpio_cd)) {
ret = mmc_gpio_request_cd(mmc, pdata->gpio_cd, 0);
if (ret)
return ret;
host->card_detect = omap_hsmmc_card_detect;
}
if (gpio_is_valid(pdata->gpio_wp)) {
ret = mmc_gpio_request_ro(mmc, pdata->gpio_wp);
if (ret)
return ret;
}
return 0;
}
static void omap_hsmmc_start_clock(struct omap_hsmmc_host *host)
{
OMAP_HSMMC_WRITE(host->base, SYSCTL,
OMAP_HSMMC_READ(host->base, SYSCTL) | CEN);
}
static void omap_hsmmc_stop_clock(struct omap_hsmmc_host *host)
{
OMAP_HSMMC_WRITE(host->base, SYSCTL,
OMAP_HSMMC_READ(host->base, SYSCTL) & ~CEN);
if ((OMAP_HSMMC_READ(host->base, SYSCTL) & CEN) != 0x0)
dev_dbg(mmc_dev(host->mmc), "MMC Clock is not stopped\n");
}
static void omap_hsmmc_enable_irq(struct omap_hsmmc_host *host,
struct mmc_command *cmd)
{
u32 irq_mask = INT_EN_MASK;
unsigned long flags;
if (host->use_dma)
irq_mask &= ~(BRR_EN | BWR_EN);
if (cmd->opcode == MMC_ERASE)
irq_mask &= ~DTO_EN;
spin_lock_irqsave(&host->irq_lock, flags);
OMAP_HSMMC_WRITE(host->base, STAT, STAT_CLEAR);
OMAP_HSMMC_WRITE(host->base, ISE, irq_mask);
if (host->flags & HSMMC_SDIO_IRQ_ENABLED)
irq_mask |= CIRQ_EN;
OMAP_HSMMC_WRITE(host->base, IE, irq_mask);
spin_unlock_irqrestore(&host->irq_lock, flags);
}
static void omap_hsmmc_disable_irq(struct omap_hsmmc_host *host)
{
u32 irq_mask = 0;
unsigned long flags;
spin_lock_irqsave(&host->irq_lock, flags);
if (host->flags & HSMMC_SDIO_IRQ_ENABLED)
irq_mask |= CIRQ_EN;
OMAP_HSMMC_WRITE(host->base, ISE, irq_mask);
OMAP_HSMMC_WRITE(host->base, IE, irq_mask);
OMAP_HSMMC_WRITE(host->base, STAT, STAT_CLEAR);
spin_unlock_irqrestore(&host->irq_lock, flags);
}
static u16 calc_divisor(struct omap_hsmmc_host *host, struct mmc_ios *ios)
{
u16 dsor = 0;
if (ios->clock) {
dsor = DIV_ROUND_UP(clk_get_rate(host->fclk), ios->clock);
if (dsor > CLKD_MAX)
dsor = CLKD_MAX;
}
return dsor;
}
static void omap_hsmmc_set_clock(struct omap_hsmmc_host *host)
{
struct mmc_ios *ios = &host->mmc->ios;
unsigned long regval;
unsigned long timeout;
unsigned long clkdiv;
dev_vdbg(mmc_dev(host->mmc), "Set clock to %uHz\n", ios->clock);
omap_hsmmc_stop_clock(host);
regval = OMAP_HSMMC_READ(host->base, SYSCTL);
regval = regval & ~(CLKD_MASK | DTO_MASK);
clkdiv = calc_divisor(host, ios);
regval = regval | (clkdiv << 6) | (DTO << 16);
OMAP_HSMMC_WRITE(host->base, SYSCTL, regval);
OMAP_HSMMC_WRITE(host->base, SYSCTL,
OMAP_HSMMC_READ(host->base, SYSCTL) | ICE);
timeout = jiffies + msecs_to_jiffies(MMC_TIMEOUT_MS);
while ((OMAP_HSMMC_READ(host->base, SYSCTL) & ICS) != ICS
&& time_before(jiffies, timeout))
cpu_relax();
if ((mmc_pdata(host)->features & HSMMC_HAS_HSPE_SUPPORT) &&
(ios->timing != MMC_TIMING_MMC_DDR52) &&
(ios->timing != MMC_TIMING_UHS_DDR50) &&
((OMAP_HSMMC_READ(host->base, CAPA) & HSS) == HSS)) {
regval = OMAP_HSMMC_READ(host->base, HCTL);
if (clkdiv && (clk_get_rate(host->fclk)/clkdiv) > 25000000)
regval |= HSPE;
else
regval &= ~HSPE;
OMAP_HSMMC_WRITE(host->base, HCTL, regval);
}
omap_hsmmc_start_clock(host);
}
static void omap_hsmmc_set_bus_width(struct omap_hsmmc_host *host)
{
struct mmc_ios *ios = &host->mmc->ios;
u32 con;
con = OMAP_HSMMC_READ(host->base, CON);
if (ios->timing == MMC_TIMING_MMC_DDR52 ||
ios->timing == MMC_TIMING_UHS_DDR50)
con |= DDR;
else
con &= ~DDR;
switch (ios->bus_width) {
case MMC_BUS_WIDTH_8:
OMAP_HSMMC_WRITE(host->base, CON, con | DW8);
break;
case MMC_BUS_WIDTH_4:
OMAP_HSMMC_WRITE(host->base, CON, con & ~DW8);
OMAP_HSMMC_WRITE(host->base, HCTL,
OMAP_HSMMC_READ(host->base, HCTL) | FOUR_BIT);
break;
case MMC_BUS_WIDTH_1:
OMAP_HSMMC_WRITE(host->base, CON, con & ~DW8);
OMAP_HSMMC_WRITE(host->base, HCTL,
OMAP_HSMMC_READ(host->base, HCTL) & ~FOUR_BIT);
break;
}
}
static void omap_hsmmc_set_bus_mode(struct omap_hsmmc_host *host)
{
struct mmc_ios *ios = &host->mmc->ios;
u32 con;
con = OMAP_HSMMC_READ(host->base, CON);
if (ios->bus_mode == MMC_BUSMODE_OPENDRAIN)
OMAP_HSMMC_WRITE(host->base, CON, con | OD);
else
OMAP_HSMMC_WRITE(host->base, CON, con & ~OD);
}
static int omap_hsmmc_context_restore(struct omap_hsmmc_host *host)
{
struct mmc_ios *ios = &host->mmc->ios;
u32 hctl, capa;
unsigned long timeout;
if (host->con == OMAP_HSMMC_READ(host->base, CON) &&
host->hctl == OMAP_HSMMC_READ(host->base, HCTL) &&
host->sysctl == OMAP_HSMMC_READ(host->base, SYSCTL) &&
host->capa == OMAP_HSMMC_READ(host->base, CAPA))
return 0;
host->context_loss++;
if (host->pdata->controller_flags & OMAP_HSMMC_SUPPORTS_DUAL_VOLT) {
if (host->power_mode != MMC_POWER_OFF &&
(1 << ios->vdd) <= MMC_VDD_23_24)
hctl = SDVS18;
else
hctl = SDVS30;
capa = VS30 | VS18;
} else {
hctl = SDVS18;
capa = VS18;
}
if (host->mmc->caps & MMC_CAP_SDIO_IRQ)
hctl |= IWE;
OMAP_HSMMC_WRITE(host->base, HCTL,
OMAP_HSMMC_READ(host->base, HCTL) | hctl);
OMAP_HSMMC_WRITE(host->base, CAPA,
OMAP_HSMMC_READ(host->base, CAPA) | capa);
OMAP_HSMMC_WRITE(host->base, HCTL,
OMAP_HSMMC_READ(host->base, HCTL) | SDBP);
timeout = jiffies + msecs_to_jiffies(MMC_TIMEOUT_MS);
while ((OMAP_HSMMC_READ(host->base, HCTL) & SDBP) != SDBP
&& time_before(jiffies, timeout))
;
OMAP_HSMMC_WRITE(host->base, ISE, 0);
OMAP_HSMMC_WRITE(host->base, IE, 0);
OMAP_HSMMC_WRITE(host->base, STAT, STAT_CLEAR);
if (host->power_mode == MMC_POWER_OFF)
goto out;
omap_hsmmc_set_bus_width(host);
omap_hsmmc_set_clock(host);
omap_hsmmc_set_bus_mode(host);
out:
dev_dbg(mmc_dev(host->mmc), "context is restored: restore count %d\n",
host->context_loss);
return 0;
}
static void omap_hsmmc_context_save(struct omap_hsmmc_host *host)
{
host->con = OMAP_HSMMC_READ(host->base, CON);
host->hctl = OMAP_HSMMC_READ(host->base, HCTL);
host->sysctl = OMAP_HSMMC_READ(host->base, SYSCTL);
host->capa = OMAP_HSMMC_READ(host->base, CAPA);
}
static int omap_hsmmc_context_restore(struct omap_hsmmc_host *host)
{
return 0;
}
static void omap_hsmmc_context_save(struct omap_hsmmc_host *host)
{
}
static void send_init_stream(struct omap_hsmmc_host *host)
{
int reg = 0;
unsigned long timeout;
if (host->protect_card)
return;
disable_irq(host->irq);
OMAP_HSMMC_WRITE(host->base, IE, INT_EN_MASK);
OMAP_HSMMC_WRITE(host->base, CON,
OMAP_HSMMC_READ(host->base, CON) | INIT_STREAM);
OMAP_HSMMC_WRITE(host->base, CMD, INIT_STREAM_CMD);
timeout = jiffies + msecs_to_jiffies(MMC_TIMEOUT_MS);
while ((reg != CC_EN) && time_before(jiffies, timeout))
reg = OMAP_HSMMC_READ(host->base, STAT) & CC_EN;
OMAP_HSMMC_WRITE(host->base, CON,
OMAP_HSMMC_READ(host->base, CON) & ~INIT_STREAM);
OMAP_HSMMC_WRITE(host->base, STAT, STAT_CLEAR);
OMAP_HSMMC_READ(host->base, STAT);
enable_irq(host->irq);
}
static inline
int omap_hsmmc_cover_is_closed(struct omap_hsmmc_host *host)
{
int r = 1;
if (host->get_cover_state)
r = host->get_cover_state(host->dev);
return r;
}
static ssize_t
omap_hsmmc_show_cover_switch(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct mmc_host *mmc = container_of(dev, struct mmc_host, class_dev);
struct omap_hsmmc_host *host = mmc_priv(mmc);
return sprintf(buf, "%s\n",
omap_hsmmc_cover_is_closed(host) ? "closed" : "open");
}
static ssize_t
omap_hsmmc_show_slot_name(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct mmc_host *mmc = container_of(dev, struct mmc_host, class_dev);
struct omap_hsmmc_host *host = mmc_priv(mmc);
return sprintf(buf, "%s\n", mmc_pdata(host)->name);
}
static void
omap_hsmmc_start_command(struct omap_hsmmc_host *host, struct mmc_command *cmd,
struct mmc_data *data)
{
int cmdreg = 0, resptype = 0, cmdtype = 0;
dev_vdbg(mmc_dev(host->mmc), "%s: CMD%d, argument 0x%08x\n",
mmc_hostname(host->mmc), cmd->opcode, cmd->arg);
host->cmd = cmd;
omap_hsmmc_enable_irq(host, cmd);
host->response_busy = 0;
if (cmd->flags & MMC_RSP_PRESENT) {
if (cmd->flags & MMC_RSP_136)
resptype = 1;
else if (cmd->flags & MMC_RSP_BUSY) {
resptype = 3;
host->response_busy = 1;
} else
resptype = 2;
}
if (cmd == host->mrq->stop)
cmdtype = 0x3;
cmdreg = (cmd->opcode << 24) | (resptype << 16) | (cmdtype << 22);
if ((host->flags & AUTO_CMD23) && mmc_op_multi(cmd->opcode) &&
host->mrq->sbc) {
cmdreg |= ACEN_ACMD23;
OMAP_HSMMC_WRITE(host->base, SDMASA, host->mrq->sbc->arg);
}
if (data) {
cmdreg |= DP_SELECT | MSBS | BCE;
if (data->flags & MMC_DATA_READ)
cmdreg |= DDIR;
else
cmdreg &= ~(DDIR);
}
if (host->use_dma)
cmdreg |= DMAE;
host->req_in_progress = 1;
OMAP_HSMMC_WRITE(host->base, ARG, cmd->arg);
OMAP_HSMMC_WRITE(host->base, CMD, cmdreg);
}
static int
omap_hsmmc_get_dma_dir(struct omap_hsmmc_host *host, struct mmc_data *data)
{
if (data->flags & MMC_DATA_WRITE)
return DMA_TO_DEVICE;
else
return DMA_FROM_DEVICE;
}
static struct dma_chan *omap_hsmmc_get_dma_chan(struct omap_hsmmc_host *host,
struct mmc_data *data)
{
return data->flags & MMC_DATA_WRITE ? host->tx_chan : host->rx_chan;
}
static void omap_hsmmc_request_done(struct omap_hsmmc_host *host, struct mmc_request *mrq)
{
int dma_ch;
unsigned long flags;
spin_lock_irqsave(&host->irq_lock, flags);
host->req_in_progress = 0;
dma_ch = host->dma_ch;
spin_unlock_irqrestore(&host->irq_lock, flags);
omap_hsmmc_disable_irq(host);
if (mrq->data && host->use_dma && dma_ch != -1)
return;
host->mrq = NULL;
mmc_request_done(host->mmc, mrq);
}
static void
omap_hsmmc_xfer_done(struct omap_hsmmc_host *host, struct mmc_data *data)
{
if (!data) {
struct mmc_request *mrq = host->mrq;
if (host->cmd && host->cmd->opcode == 6 &&
host->response_busy) {
host->response_busy = 0;
return;
}
omap_hsmmc_request_done(host, mrq);
return;
}
host->data = NULL;
if (!data->error)
data->bytes_xfered += data->blocks * (data->blksz);
else
data->bytes_xfered = 0;
if (data->stop && (data->error || !host->mrq->sbc))
omap_hsmmc_start_command(host, data->stop, NULL);
else
omap_hsmmc_request_done(host, data->mrq);
}
static void
omap_hsmmc_cmd_done(struct omap_hsmmc_host *host, struct mmc_command *cmd)
{
if (host->mrq->sbc && (host->cmd == host->mrq->sbc) &&
!host->mrq->sbc->error && !(host->flags & AUTO_CMD23)) {
host->cmd = NULL;
omap_hsmmc_start_dma_transfer(host);
omap_hsmmc_start_command(host, host->mrq->cmd,
host->mrq->data);
return;
}
host->cmd = NULL;
if (cmd->flags & MMC_RSP_PRESENT) {
if (cmd->flags & MMC_RSP_136) {
cmd->resp[3] = OMAP_HSMMC_READ(host->base, RSP10);
cmd->resp[2] = OMAP_HSMMC_READ(host->base, RSP32);
cmd->resp[1] = OMAP_HSMMC_READ(host->base, RSP54);
cmd->resp[0] = OMAP_HSMMC_READ(host->base, RSP76);
} else {
cmd->resp[0] = OMAP_HSMMC_READ(host->base, RSP10);
}
}
if ((host->data == NULL && !host->response_busy) || cmd->error)
omap_hsmmc_request_done(host, host->mrq);
}
static void omap_hsmmc_dma_cleanup(struct omap_hsmmc_host *host, int errno)
{
int dma_ch;
unsigned long flags;
host->data->error = errno;
spin_lock_irqsave(&host->irq_lock, flags);
dma_ch = host->dma_ch;
host->dma_ch = -1;
spin_unlock_irqrestore(&host->irq_lock, flags);
if (host->use_dma && dma_ch != -1) {
struct dma_chan *chan = omap_hsmmc_get_dma_chan(host, host->data);
dmaengine_terminate_all(chan);
dma_unmap_sg(chan->device->dev,
host->data->sg, host->data->sg_len,
omap_hsmmc_get_dma_dir(host, host->data));
host->data->host_cookie = 0;
}
host->data = NULL;
}
static void omap_hsmmc_dbg_report_irq(struct omap_hsmmc_host *host, u32 status)
{
static const char *omap_hsmmc_status_bits[] = {
"CC" , "TC" , "BGE", "---", "BWR" , "BRR" , "---" , "---" ,
"CIRQ", "OBI" , "---", "---", "---" , "---" , "---" , "ERRI",
"CTO" , "CCRC", "CEB", "CIE", "DTO" , "DCRC", "DEB" , "---" ,
"ACE" , "---" , "---", "---", "CERR", "BADA", "---" , "---"
};
char res[256];
char *buf = res;
int len, i;
len = sprintf(buf, "MMC IRQ 0x%x :", status);
buf += len;
for (i = 0; i < ARRAY_SIZE(omap_hsmmc_status_bits); i++)
if (status & (1 << i)) {
len = sprintf(buf, " %s", omap_hsmmc_status_bits[i]);
buf += len;
}
dev_vdbg(mmc_dev(host->mmc), "%s\n", res);
}
static inline void omap_hsmmc_dbg_report_irq(struct omap_hsmmc_host *host,
u32 status)
{
}
static inline void omap_hsmmc_reset_controller_fsm(struct omap_hsmmc_host *host,
unsigned long bit)
{
unsigned long i = 0;
unsigned long limit = MMC_TIMEOUT_US;
OMAP_HSMMC_WRITE(host->base, SYSCTL,
OMAP_HSMMC_READ(host->base, SYSCTL) | bit);
if (mmc_pdata(host)->features & HSMMC_HAS_UPDATED_RESET) {
while ((!(OMAP_HSMMC_READ(host->base, SYSCTL) & bit))
&& (i++ < limit))
udelay(1);
}
i = 0;
while ((OMAP_HSMMC_READ(host->base, SYSCTL) & bit) &&
(i++ < limit))
udelay(1);
if (OMAP_HSMMC_READ(host->base, SYSCTL) & bit)
dev_err(mmc_dev(host->mmc),
"Timeout waiting on controller reset in %s\n",
__func__);
}
static void hsmmc_command_incomplete(struct omap_hsmmc_host *host,
int err, int end_cmd)
{
if (end_cmd) {
omap_hsmmc_reset_controller_fsm(host, SRC);
if (host->cmd)
host->cmd->error = err;
}
if (host->data) {
omap_hsmmc_reset_controller_fsm(host, SRD);
omap_hsmmc_dma_cleanup(host, err);
} else if (host->mrq && host->mrq->cmd)
host->mrq->cmd->error = err;
}
static void omap_hsmmc_do_irq(struct omap_hsmmc_host *host, int status)
{
struct mmc_data *data;
int end_cmd = 0, end_trans = 0;
int error = 0;
data = host->data;
dev_vdbg(mmc_dev(host->mmc), "IRQ Status is %x\n", status);
if (status & ERR_EN) {
omap_hsmmc_dbg_report_irq(host, status);
if (status & (CTO_EN | CCRC_EN))
end_cmd = 1;
if (host->data || host->response_busy) {
end_trans = !end_cmd;
host->response_busy = 0;
}
if (status & (CTO_EN | DTO_EN))
hsmmc_command_incomplete(host, -ETIMEDOUT, end_cmd);
else if (status & (CCRC_EN | DCRC_EN | DEB_EN | CEB_EN |
BADA_EN))
hsmmc_command_incomplete(host, -EILSEQ, end_cmd);
if (status & ACE_EN) {
u32 ac12;
ac12 = OMAP_HSMMC_READ(host->base, AC12);
if (!(ac12 & ACNE) && host->mrq->sbc) {
end_cmd = 1;
if (ac12 & ACTO)
error = -ETIMEDOUT;
else if (ac12 & (ACCE | ACEB | ACIE))
error = -EILSEQ;
host->mrq->sbc->error = error;
hsmmc_command_incomplete(host, error, end_cmd);
}
dev_dbg(mmc_dev(host->mmc), "AC12 err: 0x%x\n", ac12);
}
}
OMAP_HSMMC_WRITE(host->base, STAT, status);
if (end_cmd || ((status & CC_EN) && host->cmd))
omap_hsmmc_cmd_done(host, host->cmd);
if ((end_trans || (status & TC_EN)) && host->mrq)
omap_hsmmc_xfer_done(host, data);
}
static irqreturn_t omap_hsmmc_irq(int irq, void *dev_id)
{
struct omap_hsmmc_host *host = dev_id;
int status;
status = OMAP_HSMMC_READ(host->base, STAT);
while (status & (INT_EN_MASK | CIRQ_EN)) {
if (host->req_in_progress)
omap_hsmmc_do_irq(host, status);
if (status & CIRQ_EN)
mmc_signal_sdio_irq(host->mmc);
status = OMAP_HSMMC_READ(host->base, STAT);
}
return IRQ_HANDLED;
}
static void set_sd_bus_power(struct omap_hsmmc_host *host)
{
unsigned long i;
OMAP_HSMMC_WRITE(host->base, HCTL,
OMAP_HSMMC_READ(host->base, HCTL) | SDBP);
for (i = 0; i < loops_per_jiffy; i++) {
if (OMAP_HSMMC_READ(host->base, HCTL) & SDBP)
break;
cpu_relax();
}
}
static int omap_hsmmc_switch_opcond(struct omap_hsmmc_host *host, int vdd)
{
u32 reg_val = 0;
int ret;
if (host->dbclk)
clk_disable_unprepare(host->dbclk);
ret = omap_hsmmc_set_power(host, 0, 0);
if (!ret)
ret = omap_hsmmc_set_power(host, 1, vdd);
if (host->dbclk)
clk_prepare_enable(host->dbclk);
if (ret != 0)
goto err;
OMAP_HSMMC_WRITE(host->base, HCTL,
OMAP_HSMMC_READ(host->base, HCTL) & SDVSCLR);
reg_val = OMAP_HSMMC_READ(host->base, HCTL);
if ((1 << vdd) <= MMC_VDD_23_24)
reg_val |= SDVS18;
else
reg_val |= SDVS30;
OMAP_HSMMC_WRITE(host->base, HCTL, reg_val);
set_sd_bus_power(host);
return 0;
err:
dev_err(mmc_dev(host->mmc), "Unable to switch operating voltage\n");
return ret;
}
static void omap_hsmmc_protect_card(struct omap_hsmmc_host *host)
{
if (!host->get_cover_state)
return;
host->reqs_blocked = 0;
if (host->get_cover_state(host->dev)) {
if (host->protect_card) {
dev_info(host->dev, "%s: cover is closed, "
"card is now accessible\n",
mmc_hostname(host->mmc));
host->protect_card = 0;
}
} else {
if (!host->protect_card) {
dev_info(host->dev, "%s: cover is open, "
"card is now inaccessible\n",
mmc_hostname(host->mmc));
host->protect_card = 1;
}
}
}
static irqreturn_t omap_hsmmc_cover_irq(int irq, void *dev_id)
{
struct omap_hsmmc_host *host = dev_id;
sysfs_notify(&host->mmc->class_dev.kobj, NULL, "cover_switch");
omap_hsmmc_protect_card(host);
mmc_detect_change(host->mmc, (HZ * 200) / 1000);
return IRQ_HANDLED;
}
static void omap_hsmmc_dma_callback(void *param)
{
struct omap_hsmmc_host *host = param;
struct dma_chan *chan;
struct mmc_data *data;
int req_in_progress;
spin_lock_irq(&host->irq_lock);
if (host->dma_ch < 0) {
spin_unlock_irq(&host->irq_lock);
return;
}
data = host->mrq->data;
chan = omap_hsmmc_get_dma_chan(host, data);
if (!data->host_cookie)
dma_unmap_sg(chan->device->dev,
data->sg, data->sg_len,
omap_hsmmc_get_dma_dir(host, data));
req_in_progress = host->req_in_progress;
host->dma_ch = -1;
spin_unlock_irq(&host->irq_lock);
if (!req_in_progress) {
struct mmc_request *mrq = host->mrq;
host->mrq = NULL;
mmc_request_done(host->mmc, mrq);
}
}
static int omap_hsmmc_pre_dma_transfer(struct omap_hsmmc_host *host,
struct mmc_data *data,
struct omap_hsmmc_next *next,
struct dma_chan *chan)
{
int dma_len;
if (!next && data->host_cookie &&
data->host_cookie != host->next_data.cookie) {
dev_warn(host->dev, "[%s] invalid cookie: data->host_cookie %d"
" host->next_data.cookie %d\n",
__func__, data->host_cookie, host->next_data.cookie);
data->host_cookie = 0;
}
if (next || data->host_cookie != host->next_data.cookie) {
dma_len = dma_map_sg(chan->device->dev, data->sg, data->sg_len,
omap_hsmmc_get_dma_dir(host, data));
} else {
dma_len = host->next_data.dma_len;
host->next_data.dma_len = 0;
}
if (dma_len == 0)
return -EINVAL;
if (next) {
next->dma_len = dma_len;
data->host_cookie = ++next->cookie < 0 ? 1 : next->cookie;
} else
host->dma_len = dma_len;
return 0;
}
static int omap_hsmmc_setup_dma_transfer(struct omap_hsmmc_host *host,
struct mmc_request *req)
{
struct dma_slave_config cfg;
struct dma_async_tx_descriptor *tx;
int ret = 0, i;
struct mmc_data *data = req->data;
struct dma_chan *chan;
for (i = 0; i < data->sg_len; i++) {
struct scatterlist *sgl;
sgl = data->sg + i;
if (sgl->length % data->blksz)
return -EINVAL;
}
if ((data->blksz % 4) != 0)
return -EINVAL;
BUG_ON(host->dma_ch != -1);
chan = omap_hsmmc_get_dma_chan(host, data);
cfg.src_addr = host->mapbase + OMAP_HSMMC_DATA;
cfg.dst_addr = host->mapbase + OMAP_HSMMC_DATA;
cfg.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
cfg.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
cfg.src_maxburst = data->blksz / 4;
cfg.dst_maxburst = data->blksz / 4;
ret = dmaengine_slave_config(chan, &cfg);
if (ret)
return ret;
ret = omap_hsmmc_pre_dma_transfer(host, data, NULL, chan);
if (ret)
return ret;
tx = dmaengine_prep_slave_sg(chan, data->sg, data->sg_len,
data->flags & MMC_DATA_WRITE ? DMA_MEM_TO_DEV : DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!tx) {
dev_err(mmc_dev(host->mmc), "prep_slave_sg() failed\n");
return -1;
}
tx->callback = omap_hsmmc_dma_callback;
tx->callback_param = host;
dmaengine_submit(tx);
host->dma_ch = 1;
return 0;
}
static void set_data_timeout(struct omap_hsmmc_host *host,
unsigned int timeout_ns,
unsigned int timeout_clks)
{
unsigned int timeout, cycle_ns;
uint32_t reg, clkd, dto = 0;
reg = OMAP_HSMMC_READ(host->base, SYSCTL);
clkd = (reg & CLKD_MASK) >> CLKD_SHIFT;
if (clkd == 0)
clkd = 1;
cycle_ns = 1000000000 / (host->clk_rate / clkd);
timeout = timeout_ns / cycle_ns;
timeout += timeout_clks;
if (timeout) {
while ((timeout & 0x80000000) == 0) {
dto += 1;
timeout <<= 1;
}
dto = 31 - dto;
timeout <<= 1;
if (timeout && dto)
dto += 1;
if (dto >= 13)
dto -= 13;
else
dto = 0;
if (dto > 14)
dto = 14;
}
reg &= ~DTO_MASK;
reg |= dto << DTO_SHIFT;
OMAP_HSMMC_WRITE(host->base, SYSCTL, reg);
}
static void omap_hsmmc_start_dma_transfer(struct omap_hsmmc_host *host)
{
struct mmc_request *req = host->mrq;
struct dma_chan *chan;
if (!req->data)
return;
OMAP_HSMMC_WRITE(host->base, BLK, (req->data->blksz)
| (req->data->blocks << 16));
set_data_timeout(host, req->data->timeout_ns,
req->data->timeout_clks);
chan = omap_hsmmc_get_dma_chan(host, req->data);
dma_async_issue_pending(chan);
}
static int
omap_hsmmc_prepare_data(struct omap_hsmmc_host *host, struct mmc_request *req)
{
int ret;
host->data = req->data;
if (req->data == NULL) {
OMAP_HSMMC_WRITE(host->base, BLK, 0);
if (req->cmd->flags & MMC_RSP_BUSY)
set_data_timeout(host, 100000000U, 0);
return 0;
}
if (host->use_dma) {
ret = omap_hsmmc_setup_dma_transfer(host, req);
if (ret != 0) {
dev_err(mmc_dev(host->mmc), "MMC start dma failure\n");
return ret;
}
}
return 0;
}
static void omap_hsmmc_post_req(struct mmc_host *mmc, struct mmc_request *mrq,
int err)
{
struct omap_hsmmc_host *host = mmc_priv(mmc);
struct mmc_data *data = mrq->data;
if (host->use_dma && data->host_cookie) {
struct dma_chan *c = omap_hsmmc_get_dma_chan(host, data);
dma_unmap_sg(c->device->dev, data->sg, data->sg_len,
omap_hsmmc_get_dma_dir(host, data));
data->host_cookie = 0;
}
}
static void omap_hsmmc_pre_req(struct mmc_host *mmc, struct mmc_request *mrq,
bool is_first_req)
{
struct omap_hsmmc_host *host = mmc_priv(mmc);
if (mrq->data->host_cookie) {
mrq->data->host_cookie = 0;
return ;
}
if (host->use_dma) {
struct dma_chan *c = omap_hsmmc_get_dma_chan(host, mrq->data);
if (omap_hsmmc_pre_dma_transfer(host, mrq->data,
&host->next_data, c))
mrq->data->host_cookie = 0;
}
}
static void omap_hsmmc_request(struct mmc_host *mmc, struct mmc_request *req)
{
struct omap_hsmmc_host *host = mmc_priv(mmc);
int err;
BUG_ON(host->req_in_progress);
BUG_ON(host->dma_ch != -1);
if (host->protect_card) {
if (host->reqs_blocked < 3) {
omap_hsmmc_reset_controller_fsm(host, SRD);
omap_hsmmc_reset_controller_fsm(host, SRC);
host->reqs_blocked += 1;
}
req->cmd->error = -EBADF;
if (req->data)
req->data->error = -EBADF;
req->cmd->retries = 0;
mmc_request_done(mmc, req);
return;
} else if (host->reqs_blocked)
host->reqs_blocked = 0;
WARN_ON(host->mrq != NULL);
host->mrq = req;
host->clk_rate = clk_get_rate(host->fclk);
err = omap_hsmmc_prepare_data(host, req);
if (err) {
req->cmd->error = err;
if (req->data)
req->data->error = err;
host->mrq = NULL;
mmc_request_done(mmc, req);
return;
}
if (req->sbc && !(host->flags & AUTO_CMD23)) {
omap_hsmmc_start_command(host, req->sbc, NULL);
return;
}
omap_hsmmc_start_dma_transfer(host);
omap_hsmmc_start_command(host, req->cmd, req->data);
}
static void omap_hsmmc_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct omap_hsmmc_host *host = mmc_priv(mmc);
int do_send_init_stream = 0;
if (ios->power_mode != host->power_mode) {
switch (ios->power_mode) {
case MMC_POWER_OFF:
omap_hsmmc_set_power(host, 0, 0);
break;
case MMC_POWER_UP:
omap_hsmmc_set_power(host, 1, ios->vdd);
break;
case MMC_POWER_ON:
do_send_init_stream = 1;
break;
}
host->power_mode = ios->power_mode;
}
omap_hsmmc_set_bus_width(host);
if (host->pdata->controller_flags & OMAP_HSMMC_SUPPORTS_DUAL_VOLT) {
if ((OMAP_HSMMC_READ(host->base, HCTL) & SDVSDET) &&
(ios->vdd == DUAL_VOLT_OCR_BIT)) {
if (omap_hsmmc_switch_opcond(host, ios->vdd) != 0)
dev_dbg(mmc_dev(host->mmc),
"Switch operation failed\n");
}
}
omap_hsmmc_set_clock(host);
if (do_send_init_stream)
send_init_stream(host);
omap_hsmmc_set_bus_mode(host);
}
static int omap_hsmmc_get_cd(struct mmc_host *mmc)
{
struct omap_hsmmc_host *host = mmc_priv(mmc);
if (!host->card_detect)
return -ENOSYS;
return host->card_detect(host->dev);
}
static void omap_hsmmc_init_card(struct mmc_host *mmc, struct mmc_card *card)
{
struct omap_hsmmc_host *host = mmc_priv(mmc);
if (mmc_pdata(host)->init_card)
mmc_pdata(host)->init_card(card);
}
static void omap_hsmmc_enable_sdio_irq(struct mmc_host *mmc, int enable)
{
struct omap_hsmmc_host *host = mmc_priv(mmc);
u32 irq_mask, con;
unsigned long flags;
spin_lock_irqsave(&host->irq_lock, flags);
con = OMAP_HSMMC_READ(host->base, CON);
irq_mask = OMAP_HSMMC_READ(host->base, ISE);
if (enable) {
host->flags |= HSMMC_SDIO_IRQ_ENABLED;
irq_mask |= CIRQ_EN;
con |= CTPL | CLKEXTFREE;
} else {
host->flags &= ~HSMMC_SDIO_IRQ_ENABLED;
irq_mask &= ~CIRQ_EN;
con &= ~(CTPL | CLKEXTFREE);
}
OMAP_HSMMC_WRITE(host->base, CON, con);
OMAP_HSMMC_WRITE(host->base, IE, irq_mask);
if (!host->req_in_progress || !enable)
OMAP_HSMMC_WRITE(host->base, ISE, irq_mask);
OMAP_HSMMC_READ(host->base, IE);
spin_unlock_irqrestore(&host->irq_lock, flags);
}
static int omap_hsmmc_configure_wake_irq(struct omap_hsmmc_host *host)
{
int ret;
if (!host->dev->of_node || !host->wake_irq)
return -ENODEV;
ret = dev_pm_set_dedicated_wake_irq(host->dev, host->wake_irq);
if (ret) {
dev_err(mmc_dev(host->mmc), "Unable to request wake IRQ\n");
goto err;
}
if (host->pdata->controller_flags & OMAP_HSMMC_SWAKEUP_MISSING) {
struct pinctrl *p = devm_pinctrl_get(host->dev);
if (!p) {
ret = -ENODEV;
goto err_free_irq;
}
if (IS_ERR(pinctrl_lookup_state(p, PINCTRL_STATE_DEFAULT))) {
dev_info(host->dev, "missing default pinctrl state\n");
devm_pinctrl_put(p);
ret = -EINVAL;
goto err_free_irq;
}
if (IS_ERR(pinctrl_lookup_state(p, PINCTRL_STATE_IDLE))) {
dev_info(host->dev, "missing idle pinctrl state\n");
devm_pinctrl_put(p);
ret = -EINVAL;
goto err_free_irq;
}
devm_pinctrl_put(p);
}
OMAP_HSMMC_WRITE(host->base, HCTL,
OMAP_HSMMC_READ(host->base, HCTL) | IWE);
return 0;
err_free_irq:
dev_pm_clear_wake_irq(host->dev);
err:
dev_warn(host->dev, "no SDIO IRQ support, falling back to polling\n");
host->wake_irq = 0;
return ret;
}
static void omap_hsmmc_conf_bus_power(struct omap_hsmmc_host *host)
{
u32 hctl, capa, value;
if (host->pdata->controller_flags & OMAP_HSMMC_SUPPORTS_DUAL_VOLT) {
hctl = SDVS30;
capa = VS30 | VS18;
} else {
hctl = SDVS18;
capa = VS18;
}
value = OMAP_HSMMC_READ(host->base, HCTL) & ~SDVS_MASK;
OMAP_HSMMC_WRITE(host->base, HCTL, value | hctl);
value = OMAP_HSMMC_READ(host->base, CAPA);
OMAP_HSMMC_WRITE(host->base, CAPA, value | capa);
set_sd_bus_power(host);
}
static int omap_hsmmc_multi_io_quirk(struct mmc_card *card,
unsigned int direction, int blk_size)
{
if (direction == MMC_DATA_READ)
return 1;
return blk_size;
}
static int omap_hsmmc_regs_show(struct seq_file *s, void *data)
{
struct mmc_host *mmc = s->private;
struct omap_hsmmc_host *host = mmc_priv(mmc);
seq_printf(s, "mmc%d:\n", mmc->index);
seq_printf(s, "sdio irq mode\t%s\n",
(mmc->caps & MMC_CAP_SDIO_IRQ) ? "interrupt" : "polling");
if (mmc->caps & MMC_CAP_SDIO_IRQ) {
seq_printf(s, "sdio irq \t%s\n",
(host->flags & HSMMC_SDIO_IRQ_ENABLED) ? "enabled"
: "disabled");
}
seq_printf(s, "ctx_loss:\t%d\n", host->context_loss);
pm_runtime_get_sync(host->dev);
seq_puts(s, "\nregs:\n");
seq_printf(s, "CON:\t\t0x%08x\n",
OMAP_HSMMC_READ(host->base, CON));
seq_printf(s, "PSTATE:\t\t0x%08x\n",
OMAP_HSMMC_READ(host->base, PSTATE));
seq_printf(s, "HCTL:\t\t0x%08x\n",
OMAP_HSMMC_READ(host->base, HCTL));
seq_printf(s, "SYSCTL:\t\t0x%08x\n",
OMAP_HSMMC_READ(host->base, SYSCTL));
seq_printf(s, "IE:\t\t0x%08x\n",
OMAP_HSMMC_READ(host->base, IE));
seq_printf(s, "ISE:\t\t0x%08x\n",
OMAP_HSMMC_READ(host->base, ISE));
seq_printf(s, "CAPA:\t\t0x%08x\n",
OMAP_HSMMC_READ(host->base, CAPA));
pm_runtime_mark_last_busy(host->dev);
pm_runtime_put_autosuspend(host->dev);
return 0;
}
static int omap_hsmmc_regs_open(struct inode *inode, struct file *file)
{
return single_open(file, omap_hsmmc_regs_show, inode->i_private);
}
static void omap_hsmmc_debugfs(struct mmc_host *mmc)
{
if (mmc->debugfs_root)
debugfs_create_file("regs", S_IRUSR, mmc->debugfs_root,
mmc, &mmc_regs_fops);
}
static void omap_hsmmc_debugfs(struct mmc_host *mmc)
{
}
static struct omap_hsmmc_platform_data *of_get_hsmmc_pdata(struct device *dev)
{
struct omap_hsmmc_platform_data *pdata, *legacy;
struct device_node *np = dev->of_node;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
legacy = dev_get_platdata(dev);
if (legacy && legacy->name)
pdata->name = legacy->name;
if (of_find_property(np, "ti,dual-volt", NULL))
pdata->controller_flags |= OMAP_HSMMC_SUPPORTS_DUAL_VOLT;
pdata->gpio_cd = -EINVAL;
pdata->gpio_cod = -EINVAL;
pdata->gpio_wp = -EINVAL;
if (of_find_property(np, "ti,non-removable", NULL)) {
pdata->nonremovable = true;
pdata->no_regulator_off_init = true;
}
if (of_find_property(np, "ti,needs-special-reset", NULL))
pdata->features |= HSMMC_HAS_UPDATED_RESET;
if (of_find_property(np, "ti,needs-special-hs-handling", NULL))
pdata->features |= HSMMC_HAS_HSPE_SUPPORT;
return pdata;
}
static inline struct omap_hsmmc_platform_data
*of_get_hsmmc_pdata(struct device *dev)
{
return ERR_PTR(-EINVAL);
}
static int omap_hsmmc_probe(struct platform_device *pdev)
{
struct omap_hsmmc_platform_data *pdata = pdev->dev.platform_data;
struct mmc_host *mmc;
struct omap_hsmmc_host *host = NULL;
struct resource *res;
int ret, irq;
const struct of_device_id *match;
const struct omap_mmc_of_data *data;
void __iomem *base;
match = of_match_device(of_match_ptr(omap_mmc_of_match), &pdev->dev);
if (match) {
pdata = of_get_hsmmc_pdata(&pdev->dev);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
if (match->data) {
data = match->data;
pdata->reg_offset = data->reg_offset;
pdata->controller_flags |= data->controller_flags;
}
}
if (pdata == NULL) {
dev_err(&pdev->dev, "Platform Data is missing\n");
return -ENXIO;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (res == NULL || irq < 0)
return -ENXIO;
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
mmc = mmc_alloc_host(sizeof(struct omap_hsmmc_host), &pdev->dev);
if (!mmc) {
ret = -ENOMEM;
goto err;
}
ret = mmc_of_parse(mmc);
if (ret)
goto err1;
host = mmc_priv(mmc);
host->mmc = mmc;
host->pdata = pdata;
host->dev = &pdev->dev;
host->use_dma = 1;
host->dma_ch = -1;
host->irq = irq;
host->mapbase = res->start + pdata->reg_offset;
host->base = base + pdata->reg_offset;
host->power_mode = MMC_POWER_OFF;
host->next_data.cookie = 1;
host->pbias_enabled = 0;
host->vqmmc_enabled = 0;
ret = omap_hsmmc_gpio_init(mmc, host, pdata);
if (ret)
goto err_gpio;
platform_set_drvdata(pdev, host);
if (pdev->dev.of_node)
host->wake_irq = irq_of_parse_and_map(pdev->dev.of_node, 1);
mmc->ops = &omap_hsmmc_ops;
mmc->f_min = OMAP_MMC_MIN_CLOCK;
if (pdata->max_freq > 0)
mmc->f_max = pdata->max_freq;
else if (mmc->f_max == 0)
mmc->f_max = OMAP_MMC_MAX_CLOCK;
spin_lock_init(&host->irq_lock);
host->fclk = devm_clk_get(&pdev->dev, "fck");
if (IS_ERR(host->fclk)) {
ret = PTR_ERR(host->fclk);
host->fclk = NULL;
goto err1;
}
if (host->pdata->controller_flags & OMAP_HSMMC_BROKEN_MULTIBLOCK_READ) {
dev_info(&pdev->dev, "multiblock reads disabled due to 35xx erratum 2.1.1.128; MMC read performance may suffer\n");
omap_hsmmc_ops.multi_io_quirk = omap_hsmmc_multi_io_quirk;
}
device_init_wakeup(&pdev->dev, true);
pm_runtime_enable(host->dev);
pm_runtime_get_sync(host->dev);
pm_runtime_set_autosuspend_delay(host->dev, MMC_AUTOSUSPEND_DELAY);
pm_runtime_use_autosuspend(host->dev);
omap_hsmmc_context_save(host);
host->dbclk = devm_clk_get(&pdev->dev, "mmchsdb_fck");
if (IS_ERR(host->dbclk)) {
host->dbclk = NULL;
} else if (clk_prepare_enable(host->dbclk) != 0) {
dev_warn(mmc_dev(host->mmc), "Failed to enable debounce clk\n");
host->dbclk = NULL;
}
mmc->max_segs = 1024;
mmc->max_blk_size = 512;
mmc->max_blk_count = 0xFFFF;
mmc->max_req_size = mmc->max_blk_size * mmc->max_blk_count;
mmc->max_seg_size = mmc->max_req_size;
mmc->caps |= MMC_CAP_MMC_HIGHSPEED | MMC_CAP_SD_HIGHSPEED |
MMC_CAP_WAIT_WHILE_BUSY | MMC_CAP_ERASE;
mmc->caps |= mmc_pdata(host)->caps;
if (mmc->caps & MMC_CAP_8_BIT_DATA)
mmc->caps |= MMC_CAP_4_BIT_DATA;
if (mmc_pdata(host)->nonremovable)
mmc->caps |= MMC_CAP_NONREMOVABLE;
mmc->pm_caps |= mmc_pdata(host)->pm_caps;
omap_hsmmc_conf_bus_power(host);
host->rx_chan = dma_request_chan(&pdev->dev, "rx");
if (IS_ERR(host->rx_chan)) {
dev_err(mmc_dev(host->mmc), "RX DMA channel request failed\n");
ret = PTR_ERR(host->rx_chan);
goto err_irq;
}
host->tx_chan = dma_request_chan(&pdev->dev, "tx");
if (IS_ERR(host->tx_chan)) {
dev_err(mmc_dev(host->mmc), "TX DMA channel request failed\n");
ret = PTR_ERR(host->tx_chan);
goto err_irq;
}
ret = devm_request_irq(&pdev->dev, host->irq, omap_hsmmc_irq, 0,
mmc_hostname(mmc), host);
if (ret) {
dev_err(mmc_dev(host->mmc), "Unable to grab HSMMC IRQ\n");
goto err_irq;
}
ret = omap_hsmmc_reg_get(host);
if (ret)
goto err_irq;
mmc->ocr_avail = mmc_pdata(host)->ocr_mask;
omap_hsmmc_disable_irq(host);
ret = omap_hsmmc_configure_wake_irq(host);
if (!ret)
mmc->caps |= MMC_CAP_SDIO_IRQ;
omap_hsmmc_protect_card(host);
mmc_add_host(mmc);
if (mmc_pdata(host)->name != NULL) {
ret = device_create_file(&mmc->class_dev, &dev_attr_slot_name);
if (ret < 0)
goto err_slot_name;
}
if (host->get_cover_state) {
ret = device_create_file(&mmc->class_dev,
&dev_attr_cover_switch);
if (ret < 0)
goto err_slot_name;
}
omap_hsmmc_debugfs(mmc);
pm_runtime_mark_last_busy(host->dev);
pm_runtime_put_autosuspend(host->dev);
return 0;
err_slot_name:
mmc_remove_host(mmc);
err_irq:
device_init_wakeup(&pdev->dev, false);
if (!IS_ERR_OR_NULL(host->tx_chan))
dma_release_channel(host->tx_chan);
if (!IS_ERR_OR_NULL(host->rx_chan))
dma_release_channel(host->rx_chan);
pm_runtime_dont_use_autosuspend(host->dev);
pm_runtime_put_sync(host->dev);
pm_runtime_disable(host->dev);
if (host->dbclk)
clk_disable_unprepare(host->dbclk);
err1:
err_gpio:
mmc_free_host(mmc);
err:
return ret;
}
static int omap_hsmmc_remove(struct platform_device *pdev)
{
struct omap_hsmmc_host *host = platform_get_drvdata(pdev);
pm_runtime_get_sync(host->dev);
mmc_remove_host(host->mmc);
dma_release_channel(host->tx_chan);
dma_release_channel(host->rx_chan);
pm_runtime_dont_use_autosuspend(host->dev);
pm_runtime_put_sync(host->dev);
pm_runtime_disable(host->dev);
device_init_wakeup(&pdev->dev, false);
if (host->dbclk)
clk_disable_unprepare(host->dbclk);
mmc_free_host(host->mmc);
return 0;
}
static int omap_hsmmc_suspend(struct device *dev)
{
struct omap_hsmmc_host *host = dev_get_drvdata(dev);
if (!host)
return 0;
pm_runtime_get_sync(host->dev);
if (!(host->mmc->pm_flags & MMC_PM_KEEP_POWER)) {
OMAP_HSMMC_WRITE(host->base, ISE, 0);
OMAP_HSMMC_WRITE(host->base, IE, 0);
OMAP_HSMMC_WRITE(host->base, STAT, STAT_CLEAR);
OMAP_HSMMC_WRITE(host->base, HCTL,
OMAP_HSMMC_READ(host->base, HCTL) & ~SDBP);
}
if (host->dbclk)
clk_disable_unprepare(host->dbclk);
pm_runtime_put_sync(host->dev);
return 0;
}
static int omap_hsmmc_resume(struct device *dev)
{
struct omap_hsmmc_host *host = dev_get_drvdata(dev);
if (!host)
return 0;
pm_runtime_get_sync(host->dev);
if (host->dbclk)
clk_prepare_enable(host->dbclk);
if (!(host->mmc->pm_flags & MMC_PM_KEEP_POWER))
omap_hsmmc_conf_bus_power(host);
omap_hsmmc_protect_card(host);
pm_runtime_mark_last_busy(host->dev);
pm_runtime_put_autosuspend(host->dev);
return 0;
}
static int omap_hsmmc_runtime_suspend(struct device *dev)
{
struct omap_hsmmc_host *host;
unsigned long flags;
int ret = 0;
host = platform_get_drvdata(to_platform_device(dev));
omap_hsmmc_context_save(host);
dev_dbg(dev, "disabled\n");
spin_lock_irqsave(&host->irq_lock, flags);
if ((host->mmc->caps & MMC_CAP_SDIO_IRQ) &&
(host->flags & HSMMC_SDIO_IRQ_ENABLED)) {
OMAP_HSMMC_WRITE(host->base, ISE, 0);
OMAP_HSMMC_WRITE(host->base, IE, 0);
if (!(OMAP_HSMMC_READ(host->base, PSTATE) & DLEV_DAT(1))) {
dev_dbg(dev, "pending sdio irq, abort suspend\n");
OMAP_HSMMC_WRITE(host->base, STAT, STAT_CLEAR);
OMAP_HSMMC_WRITE(host->base, ISE, CIRQ_EN);
OMAP_HSMMC_WRITE(host->base, IE, CIRQ_EN);
pm_runtime_mark_last_busy(dev);
ret = -EBUSY;
goto abort;
}
pinctrl_pm_select_idle_state(dev);
} else {
pinctrl_pm_select_idle_state(dev);
}
abort:
spin_unlock_irqrestore(&host->irq_lock, flags);
return ret;
}
static int omap_hsmmc_runtime_resume(struct device *dev)
{
struct omap_hsmmc_host *host;
unsigned long flags;
host = platform_get_drvdata(to_platform_device(dev));
omap_hsmmc_context_restore(host);
dev_dbg(dev, "enabled\n");
spin_lock_irqsave(&host->irq_lock, flags);
if ((host->mmc->caps & MMC_CAP_SDIO_IRQ) &&
(host->flags & HSMMC_SDIO_IRQ_ENABLED)) {
pinctrl_pm_select_default_state(host->dev);
OMAP_HSMMC_WRITE(host->base, STAT, STAT_CLEAR);
OMAP_HSMMC_WRITE(host->base, ISE, CIRQ_EN);
OMAP_HSMMC_WRITE(host->base, IE, CIRQ_EN);
} else {
pinctrl_pm_select_default_state(host->dev);
}
spin_unlock_irqrestore(&host->irq_lock, flags);
return 0;
}
