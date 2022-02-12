static void xadc_write_reg(struct xadc *xadc, unsigned int reg,
uint32_t val)
{
writel(val, xadc->base + reg);
}
static void xadc_read_reg(struct xadc *xadc, unsigned int reg,
uint32_t *val)
{
*val = readl(xadc->base + reg);
}
static void xadc_zynq_write_fifo(struct xadc *xadc, uint32_t *cmd,
unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
xadc_write_reg(xadc, XADC_ZYNQ_REG_CFIFO, cmd[i]);
}
static void xadc_zynq_drain_fifo(struct xadc *xadc)
{
uint32_t status, tmp;
xadc_read_reg(xadc, XADC_ZYNQ_REG_STATUS, &status);
while (!(status & XADC_ZYNQ_STATUS_DFIFOE)) {
xadc_read_reg(xadc, XADC_ZYNQ_REG_DFIFO, &tmp);
xadc_read_reg(xadc, XADC_ZYNQ_REG_STATUS, &status);
}
}
static void xadc_zynq_update_intmsk(struct xadc *xadc, unsigned int mask,
unsigned int val)
{
xadc->zynq_intmask &= ~mask;
xadc->zynq_intmask |= val;
xadc_write_reg(xadc, XADC_ZYNQ_REG_INTMSK,
xadc->zynq_intmask | xadc->zynq_masked_alarm);
}
static int xadc_zynq_write_adc_reg(struct xadc *xadc, unsigned int reg,
uint16_t val)
{
uint32_t cmd[1];
uint32_t tmp;
int ret;
spin_lock_irq(&xadc->lock);
xadc_zynq_update_intmsk(xadc, XADC_ZYNQ_INT_DFIFO_GTH,
XADC_ZYNQ_INT_DFIFO_GTH);
reinit_completion(&xadc->completion);
cmd[0] = XADC_ZYNQ_CMD(XADC_ZYNQ_CMD_WRITE, reg, val);
xadc_zynq_write_fifo(xadc, cmd, ARRAY_SIZE(cmd));
xadc_read_reg(xadc, XADC_ZYNQ_REG_CFG, &tmp);
tmp &= ~XADC_ZYNQ_CFG_DFIFOTH_MASK;
tmp |= 0 << XADC_ZYNQ_CFG_DFIFOTH_OFFSET;
xadc_write_reg(xadc, XADC_ZYNQ_REG_CFG, tmp);
xadc_zynq_update_intmsk(xadc, XADC_ZYNQ_INT_DFIFO_GTH, 0);
spin_unlock_irq(&xadc->lock);
ret = wait_for_completion_interruptible_timeout(&xadc->completion, HZ);
if (ret == 0)
ret = -EIO;
else
ret = 0;
xadc_read_reg(xadc, XADC_ZYNQ_REG_DFIFO, &tmp);
return ret;
}
static int xadc_zynq_read_adc_reg(struct xadc *xadc, unsigned int reg,
uint16_t *val)
{
uint32_t cmd[2];
uint32_t resp, tmp;
int ret;
cmd[0] = XADC_ZYNQ_CMD(XADC_ZYNQ_CMD_READ, reg, 0);
cmd[1] = XADC_ZYNQ_CMD(XADC_ZYNQ_CMD_NOP, 0, 0);
spin_lock_irq(&xadc->lock);
xadc_zynq_update_intmsk(xadc, XADC_ZYNQ_INT_DFIFO_GTH,
XADC_ZYNQ_INT_DFIFO_GTH);
xadc_zynq_drain_fifo(xadc);
reinit_completion(&xadc->completion);
xadc_zynq_write_fifo(xadc, cmd, ARRAY_SIZE(cmd));
xadc_read_reg(xadc, XADC_ZYNQ_REG_CFG, &tmp);
tmp &= ~XADC_ZYNQ_CFG_DFIFOTH_MASK;
tmp |= 1 << XADC_ZYNQ_CFG_DFIFOTH_OFFSET;
xadc_write_reg(xadc, XADC_ZYNQ_REG_CFG, tmp);
xadc_zynq_update_intmsk(xadc, XADC_ZYNQ_INT_DFIFO_GTH, 0);
spin_unlock_irq(&xadc->lock);
ret = wait_for_completion_interruptible_timeout(&xadc->completion, HZ);
if (ret == 0)
ret = -EIO;
if (ret < 0)
return ret;
xadc_read_reg(xadc, XADC_ZYNQ_REG_DFIFO, &resp);
xadc_read_reg(xadc, XADC_ZYNQ_REG_DFIFO, &resp);
*val = resp & 0xffff;
return 0;
}
static unsigned int xadc_zynq_transform_alarm(unsigned int alarm)
{
return ((alarm & 0x80) >> 4) |
((alarm & 0x78) << 1) |
(alarm & 0x07);
}
static void xadc_zynq_unmask_worker(struct work_struct *work)
{
struct xadc *xadc = container_of(work, struct xadc, zynq_unmask_work.work);
unsigned int misc_sts, unmask;
xadc_read_reg(xadc, XADC_ZYNQ_REG_STATUS, &misc_sts);
misc_sts &= XADC_ZYNQ_INT_ALARM_MASK;
spin_lock_irq(&xadc->lock);
unmask = (xadc->zynq_masked_alarm ^ misc_sts) & xadc->zynq_masked_alarm;
xadc->zynq_masked_alarm &= misc_sts;
xadc->zynq_masked_alarm &= ~xadc->zynq_intmask;
xadc_write_reg(xadc, XADC_ZYNQ_REG_INTSTS, unmask);
xadc_zynq_update_intmsk(xadc, 0, 0);
spin_unlock_irq(&xadc->lock);
if (xadc->zynq_masked_alarm) {
schedule_delayed_work(&xadc->zynq_unmask_work,
msecs_to_jiffies(XADC_ZYNQ_UNMASK_TIMEOUT));
}
}
static irqreturn_t xadc_zynq_interrupt_handler(int irq, void *devid)
{
struct iio_dev *indio_dev = devid;
struct xadc *xadc = iio_priv(indio_dev);
uint32_t status;
xadc_read_reg(xadc, XADC_ZYNQ_REG_INTSTS, &status);
status &= ~(xadc->zynq_intmask | xadc->zynq_masked_alarm);
if (!status)
return IRQ_NONE;
spin_lock(&xadc->lock);
xadc_write_reg(xadc, XADC_ZYNQ_REG_INTSTS, status);
if (status & XADC_ZYNQ_INT_DFIFO_GTH) {
xadc_zynq_update_intmsk(xadc, XADC_ZYNQ_INT_DFIFO_GTH,
XADC_ZYNQ_INT_DFIFO_GTH);
complete(&xadc->completion);
}
status &= XADC_ZYNQ_INT_ALARM_MASK;
if (status) {
xadc->zynq_masked_alarm |= status;
xadc_zynq_update_intmsk(xadc, 0, 0);
xadc_handle_events(indio_dev,
xadc_zynq_transform_alarm(status));
schedule_delayed_work(&xadc->zynq_unmask_work,
msecs_to_jiffies(XADC_ZYNQ_UNMASK_TIMEOUT));
}
spin_unlock(&xadc->lock);
return IRQ_HANDLED;
}
static int xadc_zynq_setup(struct platform_device *pdev,
struct iio_dev *indio_dev, int irq)
{
struct xadc *xadc = iio_priv(indio_dev);
unsigned long pcap_rate;
unsigned int tck_div;
unsigned int div;
unsigned int igap;
unsigned int tck_rate;
igap = XADC_ZYNQ_IGAP_DEFAULT;
tck_rate = XADC_ZYNQ_TCK_RATE_MAX;
xadc->zynq_intmask = ~0;
pcap_rate = clk_get_rate(xadc->clk);
if (tck_rate > XADC_ZYNQ_TCK_RATE_MAX)
tck_rate = XADC_ZYNQ_TCK_RATE_MAX;
if (tck_rate > pcap_rate / 2) {
div = 2;
} else {
div = pcap_rate / tck_rate;
if (pcap_rate / div > XADC_ZYNQ_TCK_RATE_MAX)
div++;
}
if (div <= 3)
tck_div = XADC_ZYNQ_CFG_TCKRATE_DIV2;
else if (div <= 7)
tck_div = XADC_ZYNQ_CFG_TCKRATE_DIV4;
else if (div <= 15)
tck_div = XADC_ZYNQ_CFG_TCKRATE_DIV8;
else
tck_div = XADC_ZYNQ_CFG_TCKRATE_DIV16;
xadc_write_reg(xadc, XADC_ZYNQ_REG_CTL, XADC_ZYNQ_CTL_RESET);
xadc_write_reg(xadc, XADC_ZYNQ_REG_CTL, 0);
xadc_write_reg(xadc, XADC_ZYNQ_REG_INTSTS, ~0);
xadc_write_reg(xadc, XADC_ZYNQ_REG_INTMSK, xadc->zynq_intmask);
xadc_write_reg(xadc, XADC_ZYNQ_REG_CFG, XADC_ZYNQ_CFG_ENABLE |
XADC_ZYNQ_CFG_REDGE | XADC_ZYNQ_CFG_WEDGE |
tck_div | XADC_ZYNQ_CFG_IGAP(igap));
return 0;
}
static unsigned long xadc_zynq_get_dclk_rate(struct xadc *xadc)
{
unsigned int div;
uint32_t val;
xadc_read_reg(xadc, XADC_ZYNQ_REG_CFG, &val);
switch (val & XADC_ZYNQ_CFG_TCKRATE_MASK) {
case XADC_ZYNQ_CFG_TCKRATE_DIV4:
div = 4;
break;
case XADC_ZYNQ_CFG_TCKRATE_DIV8:
div = 8;
break;
case XADC_ZYNQ_CFG_TCKRATE_DIV16:
div = 16;
break;
default:
div = 2;
break;
}
return clk_get_rate(xadc->clk) / div;
}
static void xadc_zynq_update_alarm(struct xadc *xadc, unsigned int alarm)
{
unsigned long flags;
uint32_t status;
alarm = ((alarm & 0x08) << 4) | ((alarm & 0xf0) >> 1) | (alarm & 0x07);
spin_lock_irqsave(&xadc->lock, flags);
xadc_read_reg(xadc, XADC_ZYNQ_REG_INTSTS, &status);
xadc_write_reg(xadc, XADC_ZYNQ_REG_INTSTS, status & alarm);
xadc_zynq_update_intmsk(xadc, XADC_ZYNQ_INT_ALARM_MASK,
~alarm & XADC_ZYNQ_INT_ALARM_MASK);
spin_unlock_irqrestore(&xadc->lock, flags);
}
static int xadc_axi_read_adc_reg(struct xadc *xadc, unsigned int reg,
uint16_t *val)
{
uint32_t val32;
xadc_read_reg(xadc, XADC_AXI_ADC_REG_OFFSET + reg * 4, &val32);
*val = val32 & 0xffff;
return 0;
}
static int xadc_axi_write_adc_reg(struct xadc *xadc, unsigned int reg,
uint16_t val)
{
xadc_write_reg(xadc, XADC_AXI_ADC_REG_OFFSET + reg * 4, val);
return 0;
}
static int xadc_axi_setup(struct platform_device *pdev,
struct iio_dev *indio_dev, int irq)
{
struct xadc *xadc = iio_priv(indio_dev);
xadc_write_reg(xadc, XADC_AXI_REG_RESET, XADC_AXI_RESET_MAGIC);
xadc_write_reg(xadc, XADC_AXI_REG_GIER, XADC_AXI_GIER_ENABLE);
return 0;
}
static irqreturn_t xadc_axi_interrupt_handler(int irq, void *devid)
{
struct iio_dev *indio_dev = devid;
struct xadc *xadc = iio_priv(indio_dev);
uint32_t status, mask;
unsigned int events;
xadc_read_reg(xadc, XADC_AXI_REG_IPISR, &status);
xadc_read_reg(xadc, XADC_AXI_REG_IPIER, &mask);
status &= mask;
if (!status)
return IRQ_NONE;
if ((status & XADC_AXI_INT_EOS) && xadc->trigger)
iio_trigger_poll(xadc->trigger);
if (status & XADC_AXI_INT_ALARM_MASK) {
events = (status & 0x000e) >> 1;
events |= (status & 0x0001) << 3;
events |= (status & 0x3c00) >> 6;
xadc_handle_events(indio_dev, events);
}
xadc_write_reg(xadc, XADC_AXI_REG_IPISR, status);
return IRQ_HANDLED;
}
static void xadc_axi_update_alarm(struct xadc *xadc, unsigned int alarm)
{
uint32_t val;
unsigned long flags;
alarm = ((alarm & 0x07) << 1) | ((alarm & 0x08) >> 3) |
((alarm & 0xf0) << 6);
spin_lock_irqsave(&xadc->lock, flags);
xadc_read_reg(xadc, XADC_AXI_REG_IPIER, &val);
val &= ~XADC_AXI_INT_ALARM_MASK;
val |= alarm;
xadc_write_reg(xadc, XADC_AXI_REG_IPIER, val);
spin_unlock_irqrestore(&xadc->lock, flags);
}
static unsigned long xadc_axi_get_dclk(struct xadc *xadc)
{
return clk_get_rate(xadc->clk);
}
static int _xadc_update_adc_reg(struct xadc *xadc, unsigned int reg,
uint16_t mask, uint16_t val)
{
uint16_t tmp;
int ret;
ret = _xadc_read_adc_reg(xadc, reg, &tmp);
if (ret)
return ret;
return _xadc_write_adc_reg(xadc, reg, (tmp & ~mask) | val);
}
static int xadc_update_adc_reg(struct xadc *xadc, unsigned int reg,
uint16_t mask, uint16_t val)
{
int ret;
mutex_lock(&xadc->mutex);
ret = _xadc_update_adc_reg(xadc, reg, mask, val);
mutex_unlock(&xadc->mutex);
return ret;
}
static unsigned long xadc_get_dclk_rate(struct xadc *xadc)
{
return xadc->ops->get_dclk_rate(xadc);
}
static int xadc_update_scan_mode(struct iio_dev *indio_dev,
const unsigned long *mask)
{
struct xadc *xadc = iio_priv(indio_dev);
unsigned int n;
n = bitmap_weight(mask, indio_dev->masklength);
kfree(xadc->data);
xadc->data = kcalloc(n, sizeof(*xadc->data), GFP_KERNEL);
if (!xadc->data)
return -ENOMEM;
return 0;
}
static unsigned int xadc_scan_index_to_channel(unsigned int scan_index)
{
switch (scan_index) {
case 5:
return XADC_REG_VCCPINT;
case 6:
return XADC_REG_VCCPAUX;
case 7:
return XADC_REG_VCCO_DDR;
case 8:
return XADC_REG_TEMP;
case 9:
return XADC_REG_VCCINT;
case 10:
return XADC_REG_VCCAUX;
case 11:
return XADC_REG_VPVN;
case 12:
return XADC_REG_VREFP;
case 13:
return XADC_REG_VREFN;
case 14:
return XADC_REG_VCCBRAM;
default:
return XADC_REG_VAUX(scan_index - 16);
}
}
static irqreturn_t xadc_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct xadc *xadc = iio_priv(indio_dev);
unsigned int chan;
int i, j;
if (!xadc->data)
goto out;
j = 0;
for_each_set_bit(i, indio_dev->active_scan_mask,
indio_dev->masklength) {
chan = xadc_scan_index_to_channel(i);
xadc_read_adc_reg(xadc, chan, &xadc->data[j]);
j++;
}
iio_push_to_buffers(indio_dev, xadc->data);
out:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int xadc_trigger_set_state(struct iio_trigger *trigger, bool state)
{
struct xadc *xadc = iio_trigger_get_drvdata(trigger);
unsigned long flags;
unsigned int convst;
unsigned int val;
int ret = 0;
mutex_lock(&xadc->mutex);
if (state) {
if (xadc->trigger != NULL) {
ret = -EBUSY;
goto err_out;
} else {
xadc->trigger = trigger;
if (trigger == xadc->convst_trigger)
convst = XADC_CONF0_EC;
else
convst = 0;
}
ret = _xadc_update_adc_reg(xadc, XADC_REG_CONF1, XADC_CONF0_EC,
convst);
if (ret)
goto err_out;
} else {
xadc->trigger = NULL;
}
spin_lock_irqsave(&xadc->lock, flags);
xadc_read_reg(xadc, XADC_AXI_REG_IPIER, &val);
xadc_write_reg(xadc, XADC_AXI_REG_IPISR, val & XADC_AXI_INT_EOS);
if (state)
val |= XADC_AXI_INT_EOS;
else
val &= ~XADC_AXI_INT_EOS;
xadc_write_reg(xadc, XADC_AXI_REG_IPIER, val);
spin_unlock_irqrestore(&xadc->lock, flags);
err_out:
mutex_unlock(&xadc->mutex);
return ret;
}
static struct iio_trigger *xadc_alloc_trigger(struct iio_dev *indio_dev,
const char *name)
{
struct iio_trigger *trig;
int ret;
trig = iio_trigger_alloc("%s%d-%s", indio_dev->name,
indio_dev->id, name);
if (trig == NULL)
return ERR_PTR(-ENOMEM);
trig->dev.parent = indio_dev->dev.parent;
trig->ops = &xadc_trigger_ops;
iio_trigger_set_drvdata(trig, iio_priv(indio_dev));
ret = iio_trigger_register(trig);
if (ret)
goto error_free_trig;
return trig;
error_free_trig:
iio_trigger_free(trig);
return ERR_PTR(ret);
}
static int xadc_power_adc_b(struct xadc *xadc, unsigned int seq_mode)
{
uint16_t val;
switch (seq_mode) {
case XADC_CONF1_SEQ_SIMULTANEOUS:
case XADC_CONF1_SEQ_INDEPENDENT:
val = XADC_CONF2_PD_ADC_B;
break;
default:
val = 0;
break;
}
return xadc_update_adc_reg(xadc, XADC_REG_CONF2, XADC_CONF2_PD_MASK,
val);
}
static int xadc_get_seq_mode(struct xadc *xadc, unsigned long scan_mode)
{
unsigned int aux_scan_mode = scan_mode >> 16;
if (xadc->external_mux_mode == XADC_EXTERNAL_MUX_DUAL)
return XADC_CONF1_SEQ_SIMULTANEOUS;
if ((aux_scan_mode & 0xff00) == 0 ||
(aux_scan_mode & 0x00ff) == 0)
return XADC_CONF1_SEQ_CONTINUOUS;
return XADC_CONF1_SEQ_SIMULTANEOUS;
}
static int xadc_postdisable(struct iio_dev *indio_dev)
{
struct xadc *xadc = iio_priv(indio_dev);
unsigned long scan_mask;
int ret;
int i;
scan_mask = 1;
for (i = 0; i < indio_dev->num_channels; i++)
scan_mask |= BIT(indio_dev->channels[i].scan_index);
ret = xadc_write_adc_reg(xadc, XADC_REG_SEQ(0), scan_mask & 0xffff);
if (ret)
return ret;
ret = xadc_write_adc_reg(xadc, XADC_REG_SEQ(1), scan_mask >> 16);
if (ret)
return ret;
ret = xadc_update_adc_reg(xadc, XADC_REG_CONF1, XADC_CONF1_SEQ_MASK,
XADC_CONF1_SEQ_CONTINUOUS);
if (ret)
return ret;
return xadc_power_adc_b(xadc, XADC_CONF1_SEQ_CONTINUOUS);
}
static int xadc_preenable(struct iio_dev *indio_dev)
{
struct xadc *xadc = iio_priv(indio_dev);
unsigned long scan_mask;
int seq_mode;
int ret;
ret = xadc_update_adc_reg(xadc, XADC_REG_CONF1, XADC_CONF1_SEQ_MASK,
XADC_CONF1_SEQ_DEFAULT);
if (ret)
goto err;
scan_mask = *indio_dev->active_scan_mask;
seq_mode = xadc_get_seq_mode(xadc, scan_mask);
ret = xadc_write_adc_reg(xadc, XADC_REG_SEQ(0), scan_mask & 0xffff);
if (ret)
goto err;
ret = xadc_write_adc_reg(xadc, XADC_REG_SEQ(1), scan_mask >> 16);
if (ret)
goto err;
ret = xadc_power_adc_b(xadc, seq_mode);
if (ret)
goto err;
ret = xadc_update_adc_reg(xadc, XADC_REG_CONF1, XADC_CONF1_SEQ_MASK,
seq_mode);
if (ret)
goto err;
return 0;
err:
xadc_postdisable(indio_dev);
return ret;
}
static int xadc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2, long info)
{
struct xadc *xadc = iio_priv(indio_dev);
unsigned int div;
uint16_t val16;
int ret;
switch (info) {
case IIO_CHAN_INFO_RAW:
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
ret = xadc_read_adc_reg(xadc, chan->address, &val16);
if (ret < 0)
return ret;
val16 >>= 4;
if (chan->scan_type.sign == 'u')
*val = val16;
else
*val = sign_extend32(val16, 11);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_VOLTAGE:
switch (chan->address) {
case XADC_REG_VCCINT:
case XADC_REG_VCCAUX:
case XADC_REG_VREFP:
case XADC_REG_VREFN:
case XADC_REG_VCCBRAM:
case XADC_REG_VCCPINT:
case XADC_REG_VCCPAUX:
case XADC_REG_VCCO_DDR:
*val = 3000;
break;
default:
*val = 1000;
break;
}
*val2 = 12;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_TEMP:
*val = 503975;
*val2 = 12;
return IIO_VAL_FRACTIONAL_LOG2;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
*val = -((273150 << 12) / 503975);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SAMP_FREQ:
ret = xadc_read_adc_reg(xadc, XADC_REG_CONF2, &val16);
if (ret)
return ret;
div = (val16 & XADC_CONF2_DIV_MASK) >> XADC_CONF2_DIV_OFFSET;
if (div < 2)
div = 2;
*val = xadc_get_dclk_rate(xadc) / div / 26;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int xadc_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long info)
{
struct xadc *xadc = iio_priv(indio_dev);
unsigned long clk_rate = xadc_get_dclk_rate(xadc);
unsigned int div;
if (info != IIO_CHAN_INFO_SAMP_FREQ)
return -EINVAL;
if (val <= 0)
return -EINVAL;
if (val > 150000)
val = 150000;
val *= 26;
if (val < 1000000)
val = 1000000;
div = clk_rate / val;
if (clk_rate / div / 26 > 150000)
div++;
if (div < 2)
div = 2;
else if (div > 0xff)
div = 0xff;
return xadc_update_adc_reg(xadc, XADC_REG_CONF2, XADC_CONF2_DIV_MASK,
div << XADC_CONF2_DIV_OFFSET);
}
static int xadc_parse_dt(struct iio_dev *indio_dev, struct device_node *np,
unsigned int *conf)
{
struct xadc *xadc = iio_priv(indio_dev);
struct iio_chan_spec *channels, *chan;
struct device_node *chan_node, *child;
unsigned int num_channels;
const char *external_mux;
u32 ext_mux_chan;
int reg;
int ret;
*conf = 0;
ret = of_property_read_string(np, "xlnx,external-mux", &external_mux);
if (ret < 0 || strcasecmp(external_mux, "none") == 0)
xadc->external_mux_mode = XADC_EXTERNAL_MUX_NONE;
else if (strcasecmp(external_mux, "single") == 0)
xadc->external_mux_mode = XADC_EXTERNAL_MUX_SINGLE;
else if (strcasecmp(external_mux, "dual") == 0)
xadc->external_mux_mode = XADC_EXTERNAL_MUX_DUAL;
else
return -EINVAL;
if (xadc->external_mux_mode != XADC_EXTERNAL_MUX_NONE) {
ret = of_property_read_u32(np, "xlnx,external-mux-channel",
&ext_mux_chan);
if (ret < 0)
return ret;
if (xadc->external_mux_mode == XADC_EXTERNAL_MUX_SINGLE) {
if (ext_mux_chan == 0)
ext_mux_chan = XADC_REG_VPVN;
else if (ext_mux_chan <= 16)
ext_mux_chan = XADC_REG_VAUX(ext_mux_chan - 1);
else
return -EINVAL;
} else {
if (ext_mux_chan > 0 && ext_mux_chan <= 8)
ext_mux_chan = XADC_REG_VAUX(ext_mux_chan - 1);
else
return -EINVAL;
}
*conf |= XADC_CONF0_MUX | XADC_CONF0_CHAN(ext_mux_chan);
}
channels = kmemdup(xadc_channels, sizeof(xadc_channels), GFP_KERNEL);
if (!channels)
return -ENOMEM;
num_channels = 9;
chan = &channels[9];
chan_node = of_get_child_by_name(np, "xlnx,channels");
if (chan_node) {
for_each_child_of_node(chan_node, child) {
if (num_channels >= ARRAY_SIZE(xadc_channels)) {
of_node_put(child);
break;
}
ret = of_property_read_u32(child, "reg", &reg);
if (ret || reg > 16)
continue;
if (of_property_read_bool(child, "xlnx,bipolar"))
chan->scan_type.sign = 's';
if (reg == 0) {
chan->scan_index = 11;
chan->address = XADC_REG_VPVN;
} else {
chan->scan_index = 15 + reg;
chan->address = XADC_REG_VAUX(reg - 1);
}
num_channels++;
chan++;
}
}
of_node_put(chan_node);
indio_dev->num_channels = num_channels;
indio_dev->channels = krealloc(channels, sizeof(*channels) *
num_channels, GFP_KERNEL);
if (!indio_dev->channels)
indio_dev->channels = channels;
return 0;
}
static int xadc_probe(struct platform_device *pdev)
{
const struct of_device_id *id;
struct iio_dev *indio_dev;
unsigned int bipolar_mask;
struct resource *mem;
unsigned int conf0;
struct xadc *xadc;
int ret;
int irq;
int i;
if (!pdev->dev.of_node)
return -ENODEV;
id = of_match_node(xadc_of_match_table, pdev->dev.of_node);
if (!id)
return -EINVAL;
irq = platform_get_irq(pdev, 0);
if (irq <= 0)
return -ENXIO;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*xadc));
if (!indio_dev)
return -ENOMEM;
xadc = iio_priv(indio_dev);
xadc->ops = id->data;
init_completion(&xadc->completion);
mutex_init(&xadc->mutex);
spin_lock_init(&xadc->lock);
INIT_DELAYED_WORK(&xadc->zynq_unmask_work, xadc_zynq_unmask_worker);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
xadc->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(xadc->base))
return PTR_ERR(xadc->base);
indio_dev->dev.parent = &pdev->dev;
indio_dev->dev.of_node = pdev->dev.of_node;
indio_dev->name = "xadc";
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &xadc_info;
ret = xadc_parse_dt(indio_dev, pdev->dev.of_node, &conf0);
if (ret)
goto err_device_free;
if (xadc->ops->flags & XADC_FLAGS_BUFFERED) {
ret = iio_triggered_buffer_setup(indio_dev,
&iio_pollfunc_store_time, &xadc_trigger_handler,
&xadc_buffer_ops);
if (ret)
goto err_device_free;
xadc->convst_trigger = xadc_alloc_trigger(indio_dev, "convst");
if (IS_ERR(xadc->convst_trigger)) {
ret = PTR_ERR(xadc->convst_trigger);
goto err_triggered_buffer_cleanup;
}
xadc->samplerate_trigger = xadc_alloc_trigger(indio_dev,
"samplerate");
if (IS_ERR(xadc->samplerate_trigger)) {
ret = PTR_ERR(xadc->samplerate_trigger);
goto err_free_convst_trigger;
}
}
xadc->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(xadc->clk)) {
ret = PTR_ERR(xadc->clk);
goto err_free_samplerate_trigger;
}
ret = clk_prepare_enable(xadc->clk);
if (ret)
goto err_free_samplerate_trigger;
ret = xadc->ops->setup(pdev, indio_dev, irq);
if (ret)
goto err_clk_disable_unprepare;
ret = request_irq(irq, xadc->ops->interrupt_handler, 0,
dev_name(&pdev->dev), indio_dev);
if (ret)
goto err_clk_disable_unprepare;
for (i = 0; i < 16; i++)
xadc_read_adc_reg(xadc, XADC_REG_THRESHOLD(i),
&xadc->threshold[i]);
ret = xadc_write_adc_reg(xadc, XADC_REG_CONF0, conf0);
if (ret)
goto err_free_irq;
bipolar_mask = 0;
for (i = 0; i < indio_dev->num_channels; i++) {
if (indio_dev->channels[i].scan_type.sign == 's')
bipolar_mask |= BIT(indio_dev->channels[i].scan_index);
}
ret = xadc_write_adc_reg(xadc, XADC_REG_INPUT_MODE(0), bipolar_mask);
if (ret)
goto err_free_irq;
ret = xadc_write_adc_reg(xadc, XADC_REG_INPUT_MODE(1),
bipolar_mask >> 16);
if (ret)
goto err_free_irq;
xadc_update_adc_reg(xadc, XADC_REG_CONF1, XADC_CONF1_ALARM_MASK,
XADC_CONF1_ALARM_MASK);
for (i = 0; i < 16; i++) {
if (i % 8 < 4 || i == 7)
xadc->threshold[i] = 0xffff;
else
xadc->threshold[i] = 0;
xadc_write_adc_reg(xadc, XADC_REG_THRESHOLD(i),
xadc->threshold[i]);
}
xadc_postdisable(indio_dev);
ret = iio_device_register(indio_dev);
if (ret)
goto err_free_irq;
platform_set_drvdata(pdev, indio_dev);
return 0;
err_free_irq:
free_irq(irq, indio_dev);
err_clk_disable_unprepare:
clk_disable_unprepare(xadc->clk);
err_free_samplerate_trigger:
if (xadc->ops->flags & XADC_FLAGS_BUFFERED)
iio_trigger_free(xadc->samplerate_trigger);
err_free_convst_trigger:
if (xadc->ops->flags & XADC_FLAGS_BUFFERED)
iio_trigger_free(xadc->convst_trigger);
err_triggered_buffer_cleanup:
if (xadc->ops->flags & XADC_FLAGS_BUFFERED)
iio_triggered_buffer_cleanup(indio_dev);
err_device_free:
kfree(indio_dev->channels);
return ret;
}
static int xadc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct xadc *xadc = iio_priv(indio_dev);
int irq = platform_get_irq(pdev, 0);
iio_device_unregister(indio_dev);
if (xadc->ops->flags & XADC_FLAGS_BUFFERED) {
iio_trigger_free(xadc->samplerate_trigger);
iio_trigger_free(xadc->convst_trigger);
iio_triggered_buffer_cleanup(indio_dev);
}
free_irq(irq, indio_dev);
clk_disable_unprepare(xadc->clk);
cancel_delayed_work(&xadc->zynq_unmask_work);
kfree(xadc->data);
kfree(indio_dev->channels);
return 0;
}
