int twl6040_reg_read(struct twl6040 *twl6040, unsigned int reg)
{
int ret;
u8 val = 0;
mutex_lock(&twl6040->io_mutex);
if (unlikely(reg == TWL6040_REG_VIBCTLL ||
reg == TWL6040_REG_VIBCTLR)) {
val = twl6040->vibra_ctrl_cache[VIBRACTRL_MEMBER(reg)];
} else {
ret = twl_i2c_read_u8(TWL_MODULE_AUDIO_VOICE, &val, reg);
if (ret < 0) {
mutex_unlock(&twl6040->io_mutex);
return ret;
}
}
mutex_unlock(&twl6040->io_mutex);
return val;
}
int twl6040_reg_write(struct twl6040 *twl6040, unsigned int reg, u8 val)
{
int ret;
mutex_lock(&twl6040->io_mutex);
ret = twl_i2c_write_u8(TWL_MODULE_AUDIO_VOICE, val, reg);
if (reg == TWL6040_REG_VIBCTLL || reg == TWL6040_REG_VIBCTLR)
twl6040->vibra_ctrl_cache[VIBRACTRL_MEMBER(reg)] = val;
mutex_unlock(&twl6040->io_mutex);
return ret;
}
int twl6040_set_bits(struct twl6040 *twl6040, unsigned int reg, u8 mask)
{
int ret;
u8 val;
mutex_lock(&twl6040->io_mutex);
ret = twl_i2c_read_u8(TWL_MODULE_AUDIO_VOICE, &val, reg);
if (ret)
goto out;
val |= mask;
ret = twl_i2c_write_u8(TWL_MODULE_AUDIO_VOICE, val, reg);
out:
mutex_unlock(&twl6040->io_mutex);
return ret;
}
int twl6040_clear_bits(struct twl6040 *twl6040, unsigned int reg, u8 mask)
{
int ret;
u8 val;
mutex_lock(&twl6040->io_mutex);
ret = twl_i2c_read_u8(TWL_MODULE_AUDIO_VOICE, &val, reg);
if (ret)
goto out;
val &= ~mask;
ret = twl_i2c_write_u8(TWL_MODULE_AUDIO_VOICE, val, reg);
out:
mutex_unlock(&twl6040->io_mutex);
return ret;
}
static int twl6040_power_up(struct twl6040 *twl6040)
{
u8 ldoctl, ncpctl, lppllctl;
int ret;
ldoctl = TWL6040_HSLDOENA | TWL6040_REFENA | TWL6040_OSCENA;
ret = twl6040_reg_write(twl6040, TWL6040_REG_LDOCTL, ldoctl);
if (ret)
return ret;
usleep_range(10000, 10500);
ncpctl = TWL6040_NCPENA;
ret = twl6040_reg_write(twl6040, TWL6040_REG_NCPCTL, ncpctl);
if (ret)
goto ncp_err;
usleep_range(1000, 1500);
ldoctl |= TWL6040_LSLDOENA;
ret = twl6040_reg_write(twl6040, TWL6040_REG_LDOCTL, ldoctl);
if (ret)
goto lsldo_err;
usleep_range(1000, 1500);
lppllctl = TWL6040_LPLLENA;
ret = twl6040_reg_write(twl6040, TWL6040_REG_LPPLLCTL, lppllctl);
if (ret)
goto lppll_err;
usleep_range(5000, 5500);
ldoctl &= ~TWL6040_OSCENA;
ret = twl6040_reg_write(twl6040, TWL6040_REG_LDOCTL, ldoctl);
if (ret)
goto osc_err;
return 0;
osc_err:
lppllctl &= ~TWL6040_LPLLENA;
twl6040_reg_write(twl6040, TWL6040_REG_LPPLLCTL, lppllctl);
lppll_err:
ldoctl &= ~TWL6040_LSLDOENA;
twl6040_reg_write(twl6040, TWL6040_REG_LDOCTL, ldoctl);
lsldo_err:
ncpctl &= ~TWL6040_NCPENA;
twl6040_reg_write(twl6040, TWL6040_REG_NCPCTL, ncpctl);
ncp_err:
ldoctl &= ~(TWL6040_HSLDOENA | TWL6040_REFENA | TWL6040_OSCENA);
twl6040_reg_write(twl6040, TWL6040_REG_LDOCTL, ldoctl);
return ret;
}
static void twl6040_power_down(struct twl6040 *twl6040)
{
u8 ncpctl, ldoctl, lppllctl;
ncpctl = twl6040_reg_read(twl6040, TWL6040_REG_NCPCTL);
ldoctl = twl6040_reg_read(twl6040, TWL6040_REG_LDOCTL);
lppllctl = twl6040_reg_read(twl6040, TWL6040_REG_LPPLLCTL);
ldoctl |= TWL6040_OSCENA;
twl6040_reg_write(twl6040, TWL6040_REG_LDOCTL, ldoctl);
usleep_range(1000, 1500);
lppllctl &= ~TWL6040_LPLLENA;
twl6040_reg_write(twl6040, TWL6040_REG_LPPLLCTL, lppllctl);
ldoctl &= ~TWL6040_LSLDOENA;
twl6040_reg_write(twl6040, TWL6040_REG_LDOCTL, ldoctl);
ncpctl &= ~TWL6040_NCPENA;
twl6040_reg_write(twl6040, TWL6040_REG_NCPCTL, ncpctl);
ldoctl &= ~(TWL6040_HSLDOENA | TWL6040_REFENA | TWL6040_OSCENA);
twl6040_reg_write(twl6040, TWL6040_REG_LDOCTL, ldoctl);
}
static irqreturn_t twl6040_naudint_handler(int irq, void *data)
{
struct twl6040 *twl6040 = data;
u8 intid, status;
intid = twl6040_reg_read(twl6040, TWL6040_REG_INTID);
if (intid & TWL6040_READYINT)
complete(&twl6040->ready);
if (intid & TWL6040_THINT) {
status = twl6040_reg_read(twl6040, TWL6040_REG_STATUS);
if (status & TWL6040_TSHUTDET) {
dev_warn(twl6040->dev,
"Thermal shutdown, powering-off");
twl6040_power(twl6040, 0);
} else {
dev_warn(twl6040->dev,
"Leaving thermal shutdown, powering-on");
twl6040_power(twl6040, 1);
}
}
return IRQ_HANDLED;
}
static int twl6040_power_up_completion(struct twl6040 *twl6040,
int naudint)
{
int time_left;
u8 intid;
time_left = wait_for_completion_timeout(&twl6040->ready,
msecs_to_jiffies(144));
if (!time_left) {
intid = twl6040_reg_read(twl6040, TWL6040_REG_INTID);
if (!(intid & TWL6040_READYINT)) {
dev_err(twl6040->dev,
"timeout waiting for READYINT\n");
return -ETIMEDOUT;
}
}
return 0;
}
int twl6040_power(struct twl6040 *twl6040, int on)
{
int audpwron = twl6040->audpwron;
int naudint = twl6040->irq;
int ret = 0;
mutex_lock(&twl6040->mutex);
if (on) {
if (twl6040->power_count++)
goto out;
if (gpio_is_valid(audpwron)) {
gpio_set_value(audpwron, 1);
ret = twl6040_power_up_completion(twl6040, naudint);
if (ret) {
dev_err(twl6040->dev,
"automatic power-down failed\n");
twl6040->power_count = 0;
goto out;
}
} else {
ret = twl6040_power_up(twl6040);
if (ret) {
dev_err(twl6040->dev,
"manual power-up failed\n");
twl6040->power_count = 0;
goto out;
}
}
twl6040->pll = TWL6040_SYSCLK_SEL_LPPLL;
twl6040->sysclk = 19200000;
twl6040->mclk = 32768;
} else {
if (!twl6040->power_count) {
dev_err(twl6040->dev,
"device is already powered-off\n");
ret = -EPERM;
goto out;
}
if (--twl6040->power_count)
goto out;
if (gpio_is_valid(audpwron)) {
gpio_set_value(audpwron, 0);
usleep_range(500, 700);
} else {
twl6040_power_down(twl6040);
}
twl6040->sysclk = 0;
twl6040->mclk = 0;
}
out:
mutex_unlock(&twl6040->mutex);
return ret;
}
int twl6040_set_pll(struct twl6040 *twl6040, int pll_id,
unsigned int freq_in, unsigned int freq_out)
{
u8 hppllctl, lppllctl;
int ret = 0;
mutex_lock(&twl6040->mutex);
hppllctl = twl6040_reg_read(twl6040, TWL6040_REG_HPPLLCTL);
lppllctl = twl6040_reg_read(twl6040, TWL6040_REG_LPPLLCTL);
if (pll_id != twl6040->pll) {
twl6040->sysclk = 0;
twl6040->mclk = 0;
}
switch (pll_id) {
case TWL6040_SYSCLK_SEL_LPPLL:
if (twl6040->sysclk != freq_out) {
switch (freq_out) {
case 17640000:
lppllctl |= TWL6040_LPLLFIN;
break;
case 19200000:
lppllctl &= ~TWL6040_LPLLFIN;
break;
default:
dev_err(twl6040->dev,
"freq_out %d not supported\n",
freq_out);
ret = -EINVAL;
goto pll_out;
}
twl6040_reg_write(twl6040, TWL6040_REG_LPPLLCTL,
lppllctl);
}
if (twl6040->pll == pll_id)
break;
switch (freq_in) {
case 32768:
lppllctl |= TWL6040_LPLLENA;
twl6040_reg_write(twl6040, TWL6040_REG_LPPLLCTL,
lppllctl);
mdelay(5);
lppllctl &= ~TWL6040_HPLLSEL;
twl6040_reg_write(twl6040, TWL6040_REG_LPPLLCTL,
lppllctl);
hppllctl &= ~TWL6040_HPLLENA;
twl6040_reg_write(twl6040, TWL6040_REG_HPPLLCTL,
hppllctl);
break;
default:
dev_err(twl6040->dev,
"freq_in %d not supported\n", freq_in);
ret = -EINVAL;
goto pll_out;
}
break;
case TWL6040_SYSCLK_SEL_HPPLL:
if (freq_out != 19200000) {
dev_err(twl6040->dev,
"freq_out %d not supported\n", freq_out);
ret = -EINVAL;
goto pll_out;
}
if (twl6040->mclk != freq_in) {
hppllctl &= ~TWL6040_MCLK_MSK;
switch (freq_in) {
case 12000000:
hppllctl |= TWL6040_MCLK_12000KHZ |
TWL6040_HPLLENA;
break;
case 19200000:
hppllctl |= TWL6040_MCLK_19200KHZ;
break;
case 26000000:
hppllctl |= TWL6040_MCLK_26000KHZ |
TWL6040_HPLLENA;
break;
case 38400000:
hppllctl |= TWL6040_MCLK_38400KHZ |
TWL6040_HPLLENA;
break;
default:
dev_err(twl6040->dev,
"freq_in %d not supported\n", freq_in);
ret = -EINVAL;
goto pll_out;
}
hppllctl |= TWL6040_HPLLSQRENA;
twl6040_reg_write(twl6040, TWL6040_REG_HPPLLCTL,
hppllctl);
usleep_range(500, 700);
lppllctl |= TWL6040_HPLLSEL;
twl6040_reg_write(twl6040, TWL6040_REG_LPPLLCTL,
lppllctl);
lppllctl &= ~TWL6040_LPLLENA;
twl6040_reg_write(twl6040, TWL6040_REG_LPPLLCTL,
lppllctl);
}
break;
default:
dev_err(twl6040->dev, "unknown pll id %d\n", pll_id);
ret = -EINVAL;
goto pll_out;
}
twl6040->sysclk = freq_out;
twl6040->mclk = freq_in;
twl6040->pll = pll_id;
pll_out:
mutex_unlock(&twl6040->mutex);
return ret;
}
int twl6040_get_pll(struct twl6040 *twl6040)
{
if (twl6040->power_count)
return twl6040->pll;
else
return -ENODEV;
}
unsigned int twl6040_get_sysclk(struct twl6040 *twl6040)
{
return twl6040->sysclk;
}
int twl6040_get_vibralr_status(struct twl6040 *twl6040)
{
u8 status;
status = twl6040->vibra_ctrl_cache[0] | twl6040->vibra_ctrl_cache[1];
status &= (TWL6040_VIBENA | TWL6040_VIBSEL);
return status;
}
static int __devinit twl6040_probe(struct platform_device *pdev)
{
struct twl4030_audio_data *pdata = pdev->dev.platform_data;
struct twl6040 *twl6040;
struct mfd_cell *cell = NULL;
int ret, children = 0;
if (!pdata) {
dev_err(&pdev->dev, "Platform data is missing\n");
return -EINVAL;
}
if (!pdata->naudint_irq || !pdata->irq_base) {
dev_err(&pdev->dev, "Invalid IRQ configuration\n");
return -EINVAL;
}
twl6040 = kzalloc(sizeof(struct twl6040), GFP_KERNEL);
if (!twl6040)
return -ENOMEM;
platform_set_drvdata(pdev, twl6040);
twl6040->dev = &pdev->dev;
twl6040->irq = pdata->naudint_irq;
twl6040->irq_base = pdata->irq_base;
mutex_init(&twl6040->mutex);
mutex_init(&twl6040->io_mutex);
init_completion(&twl6040->ready);
twl6040->rev = twl6040_reg_read(twl6040, TWL6040_REG_ASICREV);
if (twl6040_get_revid(twl6040) > TWL6040_REV_ES1_0)
twl6040->audpwron = pdata->audpwron_gpio;
else
twl6040->audpwron = -EINVAL;
if (gpio_is_valid(twl6040->audpwron)) {
ret = gpio_request_one(twl6040->audpwron, GPIOF_OUT_INIT_LOW,
"audpwron");
if (ret)
goto gpio1_err;
}
ret = twl6040_irq_init(twl6040);
if (ret)
goto gpio2_err;
ret = request_threaded_irq(twl6040->irq_base + TWL6040_IRQ_READY,
NULL, twl6040_naudint_handler, 0,
"twl6040_irq_ready", twl6040);
if (ret) {
dev_err(twl6040->dev, "READY IRQ request failed: %d\n",
ret);
goto irq_err;
}
twl6040_set_bits(twl6040, TWL6040_REG_ACCCTL, TWL6040_I2CSEL);
if (pdata->codec) {
int irq = twl6040->irq_base + TWL6040_IRQ_PLUG;
cell = &twl6040->cells[children];
cell->name = "twl6040-codec";
twl6040_codec_rsrc[0].start = irq;
twl6040_codec_rsrc[0].end = irq;
cell->resources = twl6040_codec_rsrc;
cell->num_resources = ARRAY_SIZE(twl6040_codec_rsrc);
cell->platform_data = pdata->codec;
cell->pdata_size = sizeof(*pdata->codec);
children++;
}
if (pdata->vibra) {
int irq = twl6040->irq_base + TWL6040_IRQ_VIB;
cell = &twl6040->cells[children];
cell->name = "twl6040-vibra";
twl6040_vibra_rsrc[0].start = irq;
twl6040_vibra_rsrc[0].end = irq;
cell->resources = twl6040_vibra_rsrc;
cell->num_resources = ARRAY_SIZE(twl6040_vibra_rsrc);
cell->platform_data = pdata->vibra;
cell->pdata_size = sizeof(*pdata->vibra);
children++;
}
if (children) {
ret = mfd_add_devices(&pdev->dev, pdev->id, twl6040->cells,
children, NULL, 0);
if (ret)
goto mfd_err;
} else {
dev_err(&pdev->dev, "No platform data found for children\n");
ret = -ENODEV;
goto mfd_err;
}
return 0;
mfd_err:
free_irq(twl6040->irq_base + TWL6040_IRQ_READY, twl6040);
irq_err:
twl6040_irq_exit(twl6040);
gpio2_err:
if (gpio_is_valid(twl6040->audpwron))
gpio_free(twl6040->audpwron);
gpio1_err:
platform_set_drvdata(pdev, NULL);
kfree(twl6040);
return ret;
}
static int __devexit twl6040_remove(struct platform_device *pdev)
{
struct twl6040 *twl6040 = platform_get_drvdata(pdev);
if (twl6040->power_count)
twl6040_power(twl6040, 0);
if (gpio_is_valid(twl6040->audpwron))
gpio_free(twl6040->audpwron);
free_irq(twl6040->irq_base + TWL6040_IRQ_READY, twl6040);
twl6040_irq_exit(twl6040);
mfd_remove_devices(&pdev->dev);
platform_set_drvdata(pdev, NULL);
kfree(twl6040);
return 0;
}
