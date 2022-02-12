static int omap_hsmmc_card_detect(struct device *dev, int slot)
{
struct omap_mmc_platform_data *mmc = dev->platform_data;
return !gpio_get_value_cansleep(mmc->slots[0].switch_pin);
}
static int omap_hsmmc_get_wp(struct device *dev, int slot)
{
struct omap_mmc_platform_data *mmc = dev->platform_data;
return gpio_get_value_cansleep(mmc->slots[0].gpio_wp);
}
static int omap_hsmmc_get_cover_state(struct device *dev, int slot)
{
struct omap_mmc_platform_data *mmc = dev->platform_data;
return !gpio_get_value_cansleep(mmc->slots[0].switch_pin);
}
static int omap_hsmmc_suspend_cdirq(struct device *dev, int slot)
{
struct omap_mmc_platform_data *mmc = dev->platform_data;
disable_irq(mmc->slots[0].card_detect_irq);
return 0;
}
static int omap_hsmmc_resume_cdirq(struct device *dev, int slot)
{
struct omap_mmc_platform_data *mmc = dev->platform_data;
enable_irq(mmc->slots[0].card_detect_irq);
return 0;
}
static int omap_hsmmc_1_set_power(struct device *dev, int slot, int power_on,
int vdd)
{
struct omap_hsmmc_host *host =
platform_get_drvdata(to_platform_device(dev));
int ret;
if (mmc_slot(host).before_set_reg)
mmc_slot(host).before_set_reg(dev, slot, power_on, vdd);
if (power_on)
ret = mmc_regulator_set_ocr(host->mmc, host->vcc, vdd);
else
ret = mmc_regulator_set_ocr(host->mmc, host->vcc, 0);
if (mmc_slot(host).after_set_reg)
mmc_slot(host).after_set_reg(dev, slot, power_on, vdd);
return ret;
}
static int omap_hsmmc_235_set_power(struct device *dev, int slot, int power_on,
int vdd)
{
struct omap_hsmmc_host *host =
platform_get_drvdata(to_platform_device(dev));
int ret = 0;
if (!host->vcc)
return 0;
if (mmc_slot(host).before_set_reg)
mmc_slot(host).before_set_reg(dev, slot, power_on, vdd);
if (power_on) {
ret = mmc_regulator_set_ocr(host->mmc, host->vcc, vdd);
if (ret == 0 && host->vcc_aux) {
ret = regulator_enable(host->vcc_aux);
if (ret < 0)
ret = mmc_regulator_set_ocr(host->mmc,
host->vcc, 0);
}
} else {
if (host->vcc_aux)
ret = regulator_disable(host->vcc_aux);
if (!ret) {
ret = mmc_regulator_set_ocr(host->mmc,
host->vcc, 0);
}
}
if (mmc_slot(host).after_set_reg)
mmc_slot(host).after_set_reg(dev, slot, power_on, vdd);
return ret;
}
static int omap_hsmmc_4_set_power(struct device *dev, int slot, int power_on,
int vdd)
{
return 0;
}
static int omap_hsmmc_1_set_sleep(struct device *dev, int slot, int sleep,
int vdd, int cardsleep)
{
struct omap_hsmmc_host *host =
platform_get_drvdata(to_platform_device(dev));
int mode = sleep ? REGULATOR_MODE_STANDBY : REGULATOR_MODE_NORMAL;
return regulator_set_mode(host->vcc, mode);
}
static int omap_hsmmc_235_set_sleep(struct device *dev, int slot, int sleep,
int vdd, int cardsleep)
{
struct omap_hsmmc_host *host =
platform_get_drvdata(to_platform_device(dev));
int err, mode;
if (!host->vcc)
return 0;
mode = sleep ? REGULATOR_MODE_STANDBY : REGULATOR_MODE_NORMAL;
if (!host->vcc_aux)
return regulator_set_mode(host->vcc, mode);
if (cardsleep) {
if (sleep)
err = mmc_regulator_set_ocr(host->mmc, host->vcc, 0);
else
err = mmc_regulator_set_ocr(host->mmc, host->vcc, vdd);
} else
err = regulator_set_mode(host->vcc, mode);
if (err)
return err;
if (!mmc_slot(host).vcc_aux_disable_is_sleep)
return regulator_set_mode(host->vcc_aux, mode);
if (sleep)
return regulator_disable(host->vcc_aux);
else
return regulator_enable(host->vcc_aux);
}
static int omap_hsmmc_4_set_sleep(struct device *dev, int slot, int sleep,
int vdd, int cardsleep)
{
return 0;
}
static int omap_hsmmc_reg_get(struct omap_hsmmc_host *host)
{
struct regulator *reg;
int ret = 0;
int ocr_value = 0;
switch (host->id) {
case OMAP_MMC1_DEVID:
mmc_slot(host).set_power = omap_hsmmc_1_set_power;
mmc_slot(host).set_sleep = omap_hsmmc_1_set_sleep;
break;
case OMAP_MMC2_DEVID:
case OMAP_MMC3_DEVID:
case OMAP_MMC5_DEVID:
mmc_slot(host).set_power = omap_hsmmc_235_set_power;
mmc_slot(host).set_sleep = omap_hsmmc_235_set_sleep;
break;
case OMAP_MMC4_DEVID:
mmc_slot(host).set_power = omap_hsmmc_4_set_power;
mmc_slot(host).set_sleep = omap_hsmmc_4_set_sleep;
default:
pr_err("MMC%d configuration not supported!\n", host->id);
return -EINVAL;
}
reg = regulator_get(host->dev, "vmmc");
if (IS_ERR(reg)) {
dev_dbg(host->dev, "vmmc regulator missing\n");
if (host->id == OMAP_MMC1_DEVID) {
ret = PTR_ERR(reg);
goto err;
}
} else {
host->vcc = reg;
ocr_value = mmc_regulator_get_ocrmask(reg);
if (!mmc_slot(host).ocr_mask) {
mmc_slot(host).ocr_mask = ocr_value;
} else {
if (!(mmc_slot(host).ocr_mask & ocr_value)) {
pr_err("MMC%d ocrmask %x is not supported\n",
host->id, mmc_slot(host).ocr_mask);
mmc_slot(host).ocr_mask = 0;
return -EINVAL;
}
}
reg = regulator_get(host->dev, "vmmc_aux");
host->vcc_aux = IS_ERR(reg) ? NULL : reg;
if (mmc_slot(host).no_regulator_off_init)
return 0;
if (regulator_is_enabled(host->vcc) > 0 ||
(host->vcc_aux && regulator_is_enabled(host->vcc_aux))) {
int vdd = ffs(mmc_slot(host).ocr_mask) - 1;
mmc_slot(host).set_power(host->dev, host->slot_id,
1, vdd);
mmc_slot(host).set_power(host->dev, host->slot_id,
0, 0);
}
}
return 0;
err:
mmc_slot(host).set_power = NULL;
mmc_slot(host).set_sleep = NULL;
return ret;
}
static void omap_hsmmc_reg_put(struct omap_hsmmc_host *host)
{
regulator_put(host->vcc);
regulator_put(host->vcc_aux);
mmc_slot(host).set_power = NULL;
mmc_slot(host).set_sleep = NULL;
}
static inline int omap_hsmmc_have_reg(void)
{
return 1;
}
static inline int omap_hsmmc_reg_get(struct omap_hsmmc_host *host)
{
return -EINVAL;
}
static inline void omap_hsmmc_reg_put(struct omap_hsmmc_host *host)
{
}
static inline int omap_hsmmc_have_reg(void)
{
return 0;
}
static int omap_hsmmc_gpio_init(struct omap_mmc_platform_data *pdata)
{
int ret;
if (gpio_is_valid(pdata->slots[0].switch_pin)) {
if (pdata->slots[0].cover)
pdata->slots[0].get_cover_state =
omap_hsmmc_get_cover_state;
else
pdata->slots[0].card_detect = omap_hsmmc_card_detect;
pdata->slots[0].card_detect_irq =
gpio_to_irq(pdata->slots[0].switch_pin);
ret = gpio_request(pdata->slots[0].switch_pin, "mmc_cd");
if (ret)
return ret;
ret = gpio_direction_input(pdata->slots[0].switch_pin);
if (ret)
goto err_free_sp;
} else
pdata->slots[0].switch_pin = -EINVAL;
if (gpio_is_valid(pdata->slots[0].gpio_wp)) {
pdata->slots[0].get_ro = omap_hsmmc_get_wp;
ret = gpio_request(pdata->slots[0].gpio_wp, "mmc_wp");
if (ret)
goto err_free_cd;
ret = gpio_direction_input(pdata->slots[0].gpio_wp);
if (ret)
goto err_free_wp;
} else
pdata->slots[0].gpio_wp = -EINVAL;
return 0;
err_free_wp:
gpio_free(pdata->slots[0].gpio_wp);
err_free_cd:
if (gpio_is_valid(pdata->slots[0].switch_pin))
err_free_sp:
gpio_free(pdata->slots[0].switch_pin);
return ret;
}
static void omap_hsmmc_gpio_free(struct omap_mmc_platform_data *pdata)
{
if (gpio_is_valid(pdata->slots[0].gpio_wp))
gpio_free(pdata->slots[0].gpio_wp);
if (gpio_is_valid(pdata->slots[0].switch_pin))
gpio_free(pdata->slots[0].switch_pin);
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
dev_dbg(mmc_dev(host->mmc), "MMC Clock is not stoped\n");
}
static void omap_hsmmc_enable_irq(struct omap_hsmmc_host *host,
struct mmc_command *cmd)
{
unsigned int irq_mask;
if (host->use_dma)
irq_mask = INT_EN_MASK & ~(BRR_ENABLE | BWR_ENABLE);
else
irq_mask = INT_EN_MASK;
if (cmd->opcode == MMC_ERASE)
irq_mask &= ~DTO_ENABLE;
OMAP_HSMMC_WRITE(host->base, STAT, STAT_CLEAR);
OMAP_HSMMC_WRITE(host->base, ISE, irq_mask);
OMAP_HSMMC_WRITE(host->base, IE, irq_mask);
}
static void omap_hsmmc_disable_irq(struct omap_hsmmc_host *host)
{
OMAP_HSMMC_WRITE(host->base, ISE, 0);
OMAP_HSMMC_WRITE(host->base, IE, 0);
OMAP_HSMMC_WRITE(host->base, STAT, STAT_CLEAR);
}
static u16 calc_divisor(struct omap_hsmmc_host *host, struct mmc_ios *ios)
{
u16 dsor = 0;
if (ios->clock) {
dsor = DIV_ROUND_UP(clk_get_rate(host->fclk), ios->clock);
if (dsor > 250)
dsor = 250;
}
return dsor;
}
static void omap_hsmmc_set_clock(struct omap_hsmmc_host *host)
{
struct mmc_ios *ios = &host->mmc->ios;
unsigned long regval;
unsigned long timeout;
dev_dbg(mmc_dev(host->mmc), "Set clock to %uHz\n", ios->clock);
omap_hsmmc_stop_clock(host);
regval = OMAP_HSMMC_READ(host->base, SYSCTL);
regval = regval & ~(CLKD_MASK | DTO_MASK);
regval = regval | (calc_divisor(host, ios) << 6) | (DTO << 16);
OMAP_HSMMC_WRITE(host->base, SYSCTL, regval);
OMAP_HSMMC_WRITE(host->base, SYSCTL,
OMAP_HSMMC_READ(host->base, SYSCTL) | ICE);
timeout = jiffies + msecs_to_jiffies(MMC_TIMEOUT_MS);
while ((OMAP_HSMMC_READ(host->base, SYSCTL) & ICS) != ICS
&& time_before(jiffies, timeout))
cpu_relax();
omap_hsmmc_start_clock(host);
}
static void omap_hsmmc_set_bus_width(struct omap_hsmmc_host *host)
{
struct mmc_ios *ios = &host->mmc->ios;
u32 con;
con = OMAP_HSMMC_READ(host->base, CON);
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
struct omap_mmc_platform_data *pdata = host->pdata;
int context_loss = 0;
u32 hctl, capa;
unsigned long timeout;
if (pdata->get_context_loss_count) {
context_loss = pdata->get_context_loss_count(host->dev);
if (context_loss < 0)
return 1;
}
dev_dbg(mmc_dev(host->mmc), "context was %slost\n",
context_loss == host->context_loss ? "not " : "");
if (host->context_loss == context_loss)
return 1;
timeout = jiffies + msecs_to_jiffies(MMC_TIMEOUT_MS);
while ((OMAP_HSMMC_READ(host->base, SYSSTATUS) & RESETDONE) != RESETDONE
&& time_before(jiffies, timeout))
;
OMAP_HSMMC_WRITE(host->base, SYSCONFIG, SOFTRESET);
timeout = jiffies + msecs_to_jiffies(MMC_TIMEOUT_MS);
while ((OMAP_HSMMC_READ(host->base, SYSSTATUS) & RESETDONE) != RESETDONE
&& time_before(jiffies, timeout))
;
OMAP_HSMMC_WRITE(host->base, SYSCONFIG,
OMAP_HSMMC_READ(host->base, SYSCONFIG) | AUTOIDLE);
if (host->id == OMAP_MMC1_DEVID) {
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
omap_hsmmc_disable_irq(host);
if (host->power_mode == MMC_POWER_OFF)
goto out;
omap_hsmmc_set_bus_width(host);
omap_hsmmc_set_clock(host);
omap_hsmmc_set_bus_mode(host);
out:
host->context_loss = context_loss;
dev_dbg(mmc_dev(host->mmc), "context is restored\n");
return 0;
}
static void omap_hsmmc_context_save(struct omap_hsmmc_host *host)
{
struct omap_mmc_platform_data *pdata = host->pdata;
int context_loss;
if (pdata->get_context_loss_count) {
context_loss = pdata->get_context_loss_count(host->dev);
if (context_loss < 0)
return;
host->context_loss = context_loss;
}
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
while ((reg != CC) && time_before(jiffies, timeout))
reg = OMAP_HSMMC_READ(host->base, STAT) & CC;
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
if (mmc_slot(host).get_cover_state)
r = mmc_slot(host).get_cover_state(host->dev, host->slot_id);
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
return sprintf(buf, "%s\n", mmc_slot(host).name);
}
static void
omap_hsmmc_start_command(struct omap_hsmmc_host *host, struct mmc_command *cmd,
struct mmc_data *data)
{
int cmdreg = 0, resptype = 0, cmdtype = 0;
dev_dbg(mmc_dev(host->mmc), "%s: CMD%d, argument 0x%08x\n",
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
if (data) {
cmdreg |= DP_SELECT | MSBS | BCE;
if (data->flags & MMC_DATA_READ)
cmdreg |= DDIR;
else
cmdreg &= ~(DDIR);
}
if (host->use_dma)
cmdreg |= DMA_EN;
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
static void omap_hsmmc_request_done(struct omap_hsmmc_host *host, struct mmc_request *mrq)
{
int dma_ch;
spin_lock(&host->irq_lock);
host->req_in_progress = 0;
dma_ch = host->dma_ch;
spin_unlock(&host->irq_lock);
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
if (!data->stop) {
omap_hsmmc_request_done(host, data->mrq);
return;
}
omap_hsmmc_start_command(host, data->stop, NULL);
}
static void
omap_hsmmc_cmd_done(struct omap_hsmmc_host *host, struct mmc_command *cmd)
{
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
omap_hsmmc_request_done(host, cmd->mrq);
}
static void omap_hsmmc_dma_cleanup(struct omap_hsmmc_host *host, int errno)
{
int dma_ch;
host->data->error = errno;
spin_lock(&host->irq_lock);
dma_ch = host->dma_ch;
host->dma_ch = -1;
spin_unlock(&host->irq_lock);
if (host->use_dma && dma_ch != -1) {
dma_unmap_sg(mmc_dev(host->mmc), host->data->sg,
host->data->sg_len,
omap_hsmmc_get_dma_dir(host, host->data));
omap_free_dma(dma_ch);
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
dev_dbg(mmc_dev(host->mmc), "%s\n", res);
}
static inline void omap_hsmmc_dbg_report_irq(struct omap_hsmmc_host *host,
u32 status)
{
}
static inline void omap_hsmmc_reset_controller_fsm(struct omap_hsmmc_host *host,
unsigned long bit)
{
unsigned long i = 0;
unsigned long limit = (loops_per_jiffy *
msecs_to_jiffies(MMC_TIMEOUT_MS));
OMAP_HSMMC_WRITE(host->base, SYSCTL,
OMAP_HSMMC_READ(host->base, SYSCTL) | bit);
if (mmc_slot(host).features & HSMMC_HAS_UPDATED_RESET) {
while ((!(OMAP_HSMMC_READ(host->base, SYSCTL) & bit))
&& (i++ < limit))
cpu_relax();
}
i = 0;
while ((OMAP_HSMMC_READ(host->base, SYSCTL) & bit) &&
(i++ < limit))
cpu_relax();
if (OMAP_HSMMC_READ(host->base, SYSCTL) & bit)
dev_err(mmc_dev(host->mmc),
"Timeout waiting on controller reset in %s\n",
__func__);
}
static void omap_hsmmc_do_irq(struct omap_hsmmc_host *host, int status)
{
struct mmc_data *data;
int end_cmd = 0, end_trans = 0;
if (!host->req_in_progress) {
do {
OMAP_HSMMC_WRITE(host->base, STAT, status);
status = OMAP_HSMMC_READ(host->base, STAT);
} while (status & INT_EN_MASK);
return;
}
data = host->data;
dev_dbg(mmc_dev(host->mmc), "IRQ Status is %x\n", status);
if (status & ERR) {
omap_hsmmc_dbg_report_irq(host, status);
if ((status & CMD_TIMEOUT) ||
(status & CMD_CRC)) {
if (host->cmd) {
if (status & CMD_TIMEOUT) {
omap_hsmmc_reset_controller_fsm(host,
SRC);
host->cmd->error = -ETIMEDOUT;
} else {
host->cmd->error = -EILSEQ;
}
end_cmd = 1;
}
if (host->data || host->response_busy) {
if (host->data)
omap_hsmmc_dma_cleanup(host,
-ETIMEDOUT);
host->response_busy = 0;
omap_hsmmc_reset_controller_fsm(host, SRD);
}
}
if ((status & DATA_TIMEOUT) ||
(status & DATA_CRC)) {
if (host->data || host->response_busy) {
int err = (status & DATA_TIMEOUT) ?
-ETIMEDOUT : -EILSEQ;
if (host->data)
omap_hsmmc_dma_cleanup(host, err);
else
host->mrq->cmd->error = err;
host->response_busy = 0;
omap_hsmmc_reset_controller_fsm(host, SRD);
end_trans = 1;
}
}
if (status & CARD_ERR) {
dev_dbg(mmc_dev(host->mmc),
"Ignoring card err CMD%d\n", host->cmd->opcode);
if (host->cmd)
end_cmd = 1;
if (host->data)
end_trans = 1;
}
}
OMAP_HSMMC_WRITE(host->base, STAT, status);
if (end_cmd || ((status & CC) && host->cmd))
omap_hsmmc_cmd_done(host, host->cmd);
if ((end_trans || (status & TC)) && host->mrq)
omap_hsmmc_xfer_done(host, data);
}
static irqreturn_t omap_hsmmc_irq(int irq, void *dev_id)
{
struct omap_hsmmc_host *host = dev_id;
int status;
status = OMAP_HSMMC_READ(host->base, STAT);
do {
omap_hsmmc_do_irq(host, status);
status = OMAP_HSMMC_READ(host->base, STAT);
} while (status & INT_EN_MASK);
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
pm_runtime_put_sync(host->dev);
if (host->got_dbclk)
clk_disable(host->dbclk);
ret = mmc_slot(host).set_power(host->dev, host->slot_id, 0, 0);
if (!ret)
ret = mmc_slot(host).set_power(host->dev, host->slot_id, 1,
vdd);
pm_runtime_get_sync(host->dev);
if (host->got_dbclk)
clk_enable(host->dbclk);
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
dev_dbg(mmc_dev(host->mmc), "Unable to switch operating voltage\n");
return ret;
}
static void omap_hsmmc_protect_card(struct omap_hsmmc_host *host)
{
if (!mmc_slot(host).get_cover_state)
return;
host->reqs_blocked = 0;
if (mmc_slot(host).get_cover_state(host->dev, host->slot_id)) {
if (host->protect_card) {
pr_info("%s: cover is closed, "
"card is now accessible\n",
mmc_hostname(host->mmc));
host->protect_card = 0;
}
} else {
if (!host->protect_card) {
pr_info("%s: cover is open, "
"card is now inaccessible\n",
mmc_hostname(host->mmc));
host->protect_card = 1;
}
}
}
static irqreturn_t omap_hsmmc_detect(int irq, void *dev_id)
{
struct omap_hsmmc_host *host = dev_id;
struct omap_mmc_slot_data *slot = &mmc_slot(host);
int carddetect;
if (host->suspended)
return IRQ_HANDLED;
sysfs_notify(&host->mmc->class_dev.kobj, NULL, "cover_switch");
if (slot->card_detect)
carddetect = slot->card_detect(host->dev, host->slot_id);
else {
omap_hsmmc_protect_card(host);
carddetect = -ENOSYS;
}
if (carddetect)
mmc_detect_change(host->mmc, (HZ * 200) / 1000);
else
mmc_detect_change(host->mmc, (HZ * 50) / 1000);
return IRQ_HANDLED;
}
static int omap_hsmmc_get_dma_sync_dev(struct omap_hsmmc_host *host,
struct mmc_data *data)
{
int sync_dev;
if (data->flags & MMC_DATA_WRITE)
sync_dev = host->dma_line_tx;
else
sync_dev = host->dma_line_rx;
return sync_dev;
}
static void omap_hsmmc_config_dma_params(struct omap_hsmmc_host *host,
struct mmc_data *data,
struct scatterlist *sgl)
{
int blksz, nblk, dma_ch;
dma_ch = host->dma_ch;
if (data->flags & MMC_DATA_WRITE) {
omap_set_dma_dest_params(dma_ch, 0, OMAP_DMA_AMODE_CONSTANT,
(host->mapbase + OMAP_HSMMC_DATA), 0, 0);
omap_set_dma_src_params(dma_ch, 0, OMAP_DMA_AMODE_POST_INC,
sg_dma_address(sgl), 0, 0);
} else {
omap_set_dma_src_params(dma_ch, 0, OMAP_DMA_AMODE_CONSTANT,
(host->mapbase + OMAP_HSMMC_DATA), 0, 0);
omap_set_dma_dest_params(dma_ch, 0, OMAP_DMA_AMODE_POST_INC,
sg_dma_address(sgl), 0, 0);
}
blksz = host->data->blksz;
nblk = sg_dma_len(sgl) / blksz;
omap_set_dma_transfer_params(dma_ch, OMAP_DMA_DATA_TYPE_S32,
blksz / 4, nblk, OMAP_DMA_SYNC_FRAME,
omap_hsmmc_get_dma_sync_dev(host, data),
!(data->flags & MMC_DATA_WRITE));
omap_start_dma(dma_ch);
}
static void omap_hsmmc_dma_cb(int lch, u16 ch_status, void *cb_data)
{
struct omap_hsmmc_host *host = cb_data;
struct mmc_data *data;
int dma_ch, req_in_progress;
if (!(ch_status & OMAP_DMA_BLOCK_IRQ)) {
dev_warn(mmc_dev(host->mmc), "unexpected dma status %x\n",
ch_status);
return;
}
spin_lock(&host->irq_lock);
if (host->dma_ch < 0) {
spin_unlock(&host->irq_lock);
return;
}
data = host->mrq->data;
host->dma_sg_idx++;
if (host->dma_sg_idx < host->dma_len) {
omap_hsmmc_config_dma_params(host, data,
data->sg + host->dma_sg_idx);
spin_unlock(&host->irq_lock);
return;
}
if (!data->host_cookie)
dma_unmap_sg(mmc_dev(host->mmc), data->sg, data->sg_len,
omap_hsmmc_get_dma_dir(host, data));
req_in_progress = host->req_in_progress;
dma_ch = host->dma_ch;
host->dma_ch = -1;
spin_unlock(&host->irq_lock);
omap_free_dma(dma_ch);
if (!req_in_progress) {
struct mmc_request *mrq = host->mrq;
host->mrq = NULL;
mmc_request_done(host->mmc, mrq);
}
}
static int omap_hsmmc_pre_dma_transfer(struct omap_hsmmc_host *host,
struct mmc_data *data,
struct omap_hsmmc_next *next)
{
int dma_len;
if (!next && data->host_cookie &&
data->host_cookie != host->next_data.cookie) {
pr_warning("[%s] invalid cookie: data->host_cookie %d"
" host->next_data.cookie %d\n",
__func__, data->host_cookie, host->next_data.cookie);
data->host_cookie = 0;
}
if (next ||
(!next && data->host_cookie != host->next_data.cookie)) {
dma_len = dma_map_sg(mmc_dev(host->mmc), data->sg,
data->sg_len,
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
static int omap_hsmmc_start_dma_transfer(struct omap_hsmmc_host *host,
struct mmc_request *req)
{
int dma_ch = 0, ret = 0, i;
struct mmc_data *data = req->data;
for (i = 0; i < data->sg_len; i++) {
struct scatterlist *sgl;
sgl = data->sg + i;
if (sgl->length % data->blksz)
return -EINVAL;
}
if ((data->blksz % 4) != 0)
return -EINVAL;
BUG_ON(host->dma_ch != -1);
ret = omap_request_dma(omap_hsmmc_get_dma_sync_dev(host, data),
"MMC/SD", omap_hsmmc_dma_cb, host, &dma_ch);
if (ret != 0) {
dev_err(mmc_dev(host->mmc),
"%s: omap_request_dma() failed with %d\n",
mmc_hostname(host->mmc), ret);
return ret;
}
ret = omap_hsmmc_pre_dma_transfer(host, data, NULL);
if (ret)
return ret;
host->dma_ch = dma_ch;
host->dma_sg_idx = 0;
omap_hsmmc_config_dma_params(host, data, data->sg);
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
cycle_ns = 1000000000 / (clk_get_rate(host->fclk) / clkd);
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
OMAP_HSMMC_WRITE(host->base, BLK, (req->data->blksz)
| (req->data->blocks << 16));
set_data_timeout(host, req->data->timeout_ns, req->data->timeout_clks);
if (host->use_dma) {
ret = omap_hsmmc_start_dma_transfer(host, req);
if (ret != 0) {
dev_dbg(mmc_dev(host->mmc), "MMC start dma failure\n");
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
if (host->use_dma) {
if (data->host_cookie)
dma_unmap_sg(mmc_dev(host->mmc), data->sg,
data->sg_len,
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
if (host->use_dma)
if (omap_hsmmc_pre_dma_transfer(host, mrq->data,
&host->next_data))
mrq->data->host_cookie = 0;
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
err = omap_hsmmc_prepare_data(host, req);
if (err) {
req->cmd->error = err;
if (req->data)
req->data->error = err;
host->mrq = NULL;
mmc_request_done(mmc, req);
return;
}
omap_hsmmc_start_command(host, req->cmd, req->data);
}
static void omap_hsmmc_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct omap_hsmmc_host *host = mmc_priv(mmc);
int do_send_init_stream = 0;
pm_runtime_get_sync(host->dev);
if (ios->power_mode != host->power_mode) {
switch (ios->power_mode) {
case MMC_POWER_OFF:
mmc_slot(host).set_power(host->dev, host->slot_id,
0, 0);
host->vdd = 0;
break;
case MMC_POWER_UP:
mmc_slot(host).set_power(host->dev, host->slot_id,
1, ios->vdd);
host->vdd = ios->vdd;
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
pm_runtime_put_autosuspend(host->dev);
}
static int omap_hsmmc_get_cd(struct mmc_host *mmc)
{
struct omap_hsmmc_host *host = mmc_priv(mmc);
if (!mmc_slot(host).card_detect)
return -ENOSYS;
return mmc_slot(host).card_detect(host->dev, host->slot_id);
}
static int omap_hsmmc_get_ro(struct mmc_host *mmc)
{
struct omap_hsmmc_host *host = mmc_priv(mmc);
if (!mmc_slot(host).get_ro)
return -ENOSYS;
return mmc_slot(host).get_ro(host->dev, 0);
}
static void omap_hsmmc_init_card(struct mmc_host *mmc, struct mmc_card *card)
{
struct omap_hsmmc_host *host = mmc_priv(mmc);
if (mmc_slot(host).init_card)
mmc_slot(host).init_card(card);
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
value = OMAP_HSMMC_READ(host->base, SYSCONFIG);
OMAP_HSMMC_WRITE(host->base, SYSCONFIG, value | AUTOIDLE);
set_sd_bus_power(host);
}
static int omap_hsmmc_enable_fclk(struct mmc_host *mmc)
{
struct omap_hsmmc_host *host = mmc_priv(mmc);
pm_runtime_get_sync(host->dev);
return 0;
}
static int omap_hsmmc_disable_fclk(struct mmc_host *mmc, int lazy)
{
struct omap_hsmmc_host *host = mmc_priv(mmc);
pm_runtime_mark_last_busy(host->dev);
pm_runtime_put_autosuspend(host->dev);
return 0;
}
static int omap_hsmmc_regs_show(struct seq_file *s, void *data)
{
struct mmc_host *mmc = s->private;
struct omap_hsmmc_host *host = mmc_priv(mmc);
int context_loss = 0;
if (host->pdata->get_context_loss_count)
context_loss = host->pdata->get_context_loss_count(host->dev);
seq_printf(s, "mmc%d:\n"
" enabled:\t%d\n"
" dpm_state:\t%d\n"
" nesting_cnt:\t%d\n"
" ctx_loss:\t%d:%d\n"
"\nregs:\n",
mmc->index, mmc->enabled ? 1 : 0,
host->dpm_state, mmc->nesting_cnt,
host->context_loss, context_loss);
if (host->suspended) {
seq_printf(s, "host suspended, can't read registers\n");
return 0;
}
pm_runtime_get_sync(host->dev);
seq_printf(s, "SYSCONFIG:\t0x%08x\n",
OMAP_HSMMC_READ(host->base, SYSCONFIG));
seq_printf(s, "CON:\t\t0x%08x\n",
OMAP_HSMMC_READ(host->base, CON));
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
static int __init omap_hsmmc_probe(struct platform_device *pdev)
{
struct omap_mmc_platform_data *pdata = pdev->dev.platform_data;
struct mmc_host *mmc;
struct omap_hsmmc_host *host = NULL;
struct resource *res;
int ret, irq;
if (pdata == NULL) {
dev_err(&pdev->dev, "Platform Data is missing\n");
return -ENXIO;
}
if (pdata->nr_slots == 0) {
dev_err(&pdev->dev, "No Slots\n");
return -ENXIO;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (res == NULL || irq < 0)
return -ENXIO;
res->start += pdata->reg_offset;
res->end += pdata->reg_offset;
res = request_mem_region(res->start, resource_size(res), pdev->name);
if (res == NULL)
return -EBUSY;
ret = omap_hsmmc_gpio_init(pdata);
if (ret)
goto err;
mmc = mmc_alloc_host(sizeof(struct omap_hsmmc_host), &pdev->dev);
if (!mmc) {
ret = -ENOMEM;
goto err_alloc;
}
host = mmc_priv(mmc);
host->mmc = mmc;
host->pdata = pdata;
host->dev = &pdev->dev;
host->use_dma = 1;
host->dev->dma_mask = &pdata->dma_mask;
host->dma_ch = -1;
host->irq = irq;
host->id = pdev->id;
host->slot_id = 0;
host->mapbase = res->start;
host->base = ioremap(host->mapbase, SZ_4K);
host->power_mode = MMC_POWER_OFF;
host->next_data.cookie = 1;
platform_set_drvdata(pdev, host);
mmc->ops = &omap_hsmmc_ops;
if (mmc_slot(host).vcc_aux_disable_is_sleep)
mmc_slot(host).no_off = 1;
mmc->f_min = OMAP_MMC_MIN_CLOCK;
mmc->f_max = OMAP_MMC_MAX_CLOCK;
spin_lock_init(&host->irq_lock);
host->fclk = clk_get(&pdev->dev, "fck");
if (IS_ERR(host->fclk)) {
ret = PTR_ERR(host->fclk);
host->fclk = NULL;
goto err1;
}
omap_hsmmc_context_save(host);
mmc->caps |= MMC_CAP_DISABLE;
if (host->pdata->controller_flags & OMAP_HSMMC_BROKEN_MULTIBLOCK_READ) {
dev_info(&pdev->dev, "multiblock reads disabled due to 35xx erratum 2.1.1.128; MMC read performance may suffer\n");
mmc->caps2 |= MMC_CAP2_NO_MULTI_READ;
}
pm_runtime_enable(host->dev);
pm_runtime_get_sync(host->dev);
pm_runtime_set_autosuspend_delay(host->dev, MMC_AUTOSUSPEND_DELAY);
pm_runtime_use_autosuspend(host->dev);
if (cpu_is_omap2430()) {
host->dbclk = clk_get(&pdev->dev, "mmchsdb_fck");
if (IS_ERR(host->dbclk))
dev_warn(mmc_dev(host->mmc),
"Failed to get debounce clock\n");
else
host->got_dbclk = 1;
if (host->got_dbclk)
if (clk_enable(host->dbclk) != 0)
dev_dbg(mmc_dev(host->mmc), "Enabling debounce"
" clk failed\n");
}
mmc->max_segs = 1024;
mmc->max_blk_size = 512;
mmc->max_blk_count = 0xFFFF;
mmc->max_req_size = mmc->max_blk_size * mmc->max_blk_count;
mmc->max_seg_size = mmc->max_req_size;
mmc->caps |= MMC_CAP_MMC_HIGHSPEED | MMC_CAP_SD_HIGHSPEED |
MMC_CAP_WAIT_WHILE_BUSY | MMC_CAP_ERASE;
mmc->caps |= mmc_slot(host).caps;
if (mmc->caps & MMC_CAP_8_BIT_DATA)
mmc->caps |= MMC_CAP_4_BIT_DATA;
if (mmc_slot(host).nonremovable)
mmc->caps |= MMC_CAP_NONREMOVABLE;
mmc->pm_caps = mmc_slot(host).pm_caps;
omap_hsmmc_conf_bus_power(host);
switch (host->id) {
case OMAP_MMC1_DEVID:
host->dma_line_tx = OMAP24XX_DMA_MMC1_TX;
host->dma_line_rx = OMAP24XX_DMA_MMC1_RX;
break;
case OMAP_MMC2_DEVID:
host->dma_line_tx = OMAP24XX_DMA_MMC2_TX;
host->dma_line_rx = OMAP24XX_DMA_MMC2_RX;
break;
case OMAP_MMC3_DEVID:
host->dma_line_tx = OMAP34XX_DMA_MMC3_TX;
host->dma_line_rx = OMAP34XX_DMA_MMC3_RX;
break;
case OMAP_MMC4_DEVID:
host->dma_line_tx = OMAP44XX_DMA_MMC4_TX;
host->dma_line_rx = OMAP44XX_DMA_MMC4_RX;
break;
case OMAP_MMC5_DEVID:
host->dma_line_tx = OMAP44XX_DMA_MMC5_TX;
host->dma_line_rx = OMAP44XX_DMA_MMC5_RX;
break;
default:
dev_err(mmc_dev(host->mmc), "Invalid MMC id\n");
goto err_irq;
}
ret = request_irq(host->irq, omap_hsmmc_irq, 0,
mmc_hostname(mmc), host);
if (ret) {
dev_dbg(mmc_dev(host->mmc), "Unable to grab HSMMC IRQ\n");
goto err_irq;
}
if (pdata->init != NULL) {
if (pdata->init(&pdev->dev) != 0) {
dev_dbg(mmc_dev(host->mmc),
"Unable to configure MMC IRQs\n");
goto err_irq_cd_init;
}
}
if (omap_hsmmc_have_reg() && !mmc_slot(host).set_power) {
ret = omap_hsmmc_reg_get(host);
if (ret)
goto err_reg;
host->use_reg = 1;
}
mmc->ocr_avail = mmc_slot(host).ocr_mask;
if ((mmc_slot(host).card_detect_irq)) {
ret = request_threaded_irq(mmc_slot(host).card_detect_irq,
NULL,
omap_hsmmc_detect,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
mmc_hostname(mmc), host);
if (ret) {
dev_dbg(mmc_dev(host->mmc),
"Unable to grab MMC CD IRQ\n");
goto err_irq_cd;
}
pdata->suspend = omap_hsmmc_suspend_cdirq;
pdata->resume = omap_hsmmc_resume_cdirq;
}
omap_hsmmc_disable_irq(host);
omap_hsmmc_protect_card(host);
mmc_add_host(mmc);
if (mmc_slot(host).name != NULL) {
ret = device_create_file(&mmc->class_dev, &dev_attr_slot_name);
if (ret < 0)
goto err_slot_name;
}
if (mmc_slot(host).card_detect_irq && mmc_slot(host).get_cover_state) {
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
free_irq(mmc_slot(host).card_detect_irq, host);
err_irq_cd:
if (host->use_reg)
omap_hsmmc_reg_put(host);
err_reg:
if (host->pdata->cleanup)
host->pdata->cleanup(&pdev->dev);
err_irq_cd_init:
free_irq(host->irq, host);
err_irq:
pm_runtime_mark_last_busy(host->dev);
pm_runtime_put_autosuspend(host->dev);
clk_put(host->fclk);
if (host->got_dbclk) {
clk_disable(host->dbclk);
clk_put(host->dbclk);
}
err1:
iounmap(host->base);
platform_set_drvdata(pdev, NULL);
mmc_free_host(mmc);
err_alloc:
omap_hsmmc_gpio_free(pdata);
err:
release_mem_region(res->start, resource_size(res));
return ret;
}
static int omap_hsmmc_remove(struct platform_device *pdev)
{
struct omap_hsmmc_host *host = platform_get_drvdata(pdev);
struct resource *res;
if (host) {
pm_runtime_get_sync(host->dev);
mmc_remove_host(host->mmc);
if (host->use_reg)
omap_hsmmc_reg_put(host);
if (host->pdata->cleanup)
host->pdata->cleanup(&pdev->dev);
free_irq(host->irq, host);
if (mmc_slot(host).card_detect_irq)
free_irq(mmc_slot(host).card_detect_irq, host);
pm_runtime_put_sync(host->dev);
pm_runtime_disable(host->dev);
clk_put(host->fclk);
if (host->got_dbclk) {
clk_disable(host->dbclk);
clk_put(host->dbclk);
}
mmc_free_host(host->mmc);
iounmap(host->base);
omap_hsmmc_gpio_free(pdev->dev.platform_data);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res)
release_mem_region(res->start, resource_size(res));
platform_set_drvdata(pdev, NULL);
return 0;
}
static int omap_hsmmc_suspend(struct device *dev)
{
int ret = 0;
struct platform_device *pdev = to_platform_device(dev);
struct omap_hsmmc_host *host = platform_get_drvdata(pdev);
if (host && host->suspended)
return 0;
if (host) {
pm_runtime_get_sync(host->dev);
host->suspended = 1;
if (host->pdata->suspend) {
ret = host->pdata->suspend(&pdev->dev,
host->slot_id);
if (ret) {
dev_dbg(mmc_dev(host->mmc),
"Unable to handle MMC board"
" level suspend\n");
host->suspended = 0;
return ret;
}
}
ret = mmc_suspend_host(host->mmc);
if (ret) {
host->suspended = 0;
if (host->pdata->resume) {
ret = host->pdata->resume(&pdev->dev,
host->slot_id);
if (ret)
dev_dbg(mmc_dev(host->mmc),
"Unmask interrupt failed\n");
}
goto err;
}
if (!(host->mmc->pm_flags & MMC_PM_KEEP_POWER)) {
omap_hsmmc_disable_irq(host);
OMAP_HSMMC_WRITE(host->base, HCTL,
OMAP_HSMMC_READ(host->base, HCTL) & ~SDBP);
}
if (host->got_dbclk)
clk_disable(host->dbclk);
}
err:
pm_runtime_put_sync(host->dev);
return ret;
}
static int omap_hsmmc_resume(struct device *dev)
{
int ret = 0;
struct platform_device *pdev = to_platform_device(dev);
struct omap_hsmmc_host *host = platform_get_drvdata(pdev);
if (host && !host->suspended)
return 0;
if (host) {
pm_runtime_get_sync(host->dev);
if (host->got_dbclk)
clk_enable(host->dbclk);
if (!(host->mmc->pm_flags & MMC_PM_KEEP_POWER))
omap_hsmmc_conf_bus_power(host);
if (host->pdata->resume) {
ret = host->pdata->resume(&pdev->dev, host->slot_id);
if (ret)
dev_dbg(mmc_dev(host->mmc),
"Unmask interrupt failed\n");
}
omap_hsmmc_protect_card(host);
ret = mmc_resume_host(host->mmc);
if (ret == 0)
host->suspended = 0;
pm_runtime_mark_last_busy(host->dev);
pm_runtime_put_autosuspend(host->dev);
}
return ret;
}
static int omap_hsmmc_runtime_suspend(struct device *dev)
{
struct omap_hsmmc_host *host;
host = platform_get_drvdata(to_platform_device(dev));
omap_hsmmc_context_save(host);
dev_dbg(mmc_dev(host->mmc), "disabled\n");
return 0;
}
static int omap_hsmmc_runtime_resume(struct device *dev)
{
struct omap_hsmmc_host *host;
host = platform_get_drvdata(to_platform_device(dev));
omap_hsmmc_context_restore(host);
dev_dbg(mmc_dev(host->mmc), "enabled\n");
return 0;
}
static int __init omap_hsmmc_init(void)
{
return platform_driver_probe(&omap_hsmmc_driver, omap_hsmmc_probe);
}
static void __exit omap_hsmmc_cleanup(void)
{
platform_driver_unregister(&omap_hsmmc_driver);
}
