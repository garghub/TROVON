static int hi8435_readb(struct hi8435_priv *priv, u8 reg, u8 *val)
{
reg |= HI8435_READ_OPCODE;
return spi_write_then_read(priv->spi, &reg, 1, val, 1);
}
static int hi8435_readw(struct hi8435_priv *priv, u8 reg, u16 *val)
{
int ret;
__be16 be_val;
reg |= HI8435_READ_OPCODE;
ret = spi_write_then_read(priv->spi, &reg, 1, &be_val, 2);
*val = be16_to_cpu(be_val);
return ret;
}
static int hi8435_readl(struct hi8435_priv *priv, u8 reg, u32 *val)
{
int ret;
__be32 be_val;
reg |= HI8435_READ_OPCODE;
ret = spi_write_then_read(priv->spi, &reg, 1, &be_val, 4);
*val = be32_to_cpu(be_val);
return ret;
}
static int hi8435_writeb(struct hi8435_priv *priv, u8 reg, u8 val)
{
priv->reg_buffer[0] = reg | HI8435_WRITE_OPCODE;
priv->reg_buffer[1] = val;
return spi_write(priv->spi, priv->reg_buffer, 2);
}
static int hi8435_writew(struct hi8435_priv *priv, u8 reg, u16 val)
{
priv->reg_buffer[0] = reg | HI8435_WRITE_OPCODE;
priv->reg_buffer[1] = (val >> 8) & 0xff;
priv->reg_buffer[2] = val & 0xff;
return spi_write(priv->spi, priv->reg_buffer, 3);
}
static int hi8435_read_event_config(struct iio_dev *idev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
struct hi8435_priv *priv = iio_priv(idev);
return !!(priv->event_scan_mask & BIT(chan->channel));
}
static int hi8435_write_event_config(struct iio_dev *idev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir, int state)
{
struct hi8435_priv *priv = iio_priv(idev);
priv->event_scan_mask &= ~BIT(chan->channel);
if (state)
priv->event_scan_mask |= BIT(chan->channel);
return 0;
}
static int hi8435_read_event_value(struct iio_dev *idev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
struct hi8435_priv *priv = iio_priv(idev);
int ret;
u8 mode, psen;
u16 reg;
ret = hi8435_readb(priv, HI8435_PSEN_REG, &psen);
if (ret < 0)
return ret;
mode = !!(psen & BIT(chan->channel / 8));
ret = hi8435_readw(priv, mode ? HI8435_SOCENHYS_REG :
HI8435_GOCENHYS_REG, &reg);
if (ret < 0)
return ret;
if (dir == IIO_EV_DIR_FALLING)
*val = ((reg & 0xff) - (reg >> 8)) / 2;
else if (dir == IIO_EV_DIR_RISING)
*val = ((reg & 0xff) + (reg >> 8)) / 2;
return IIO_VAL_INT;
}
static int hi8435_write_event_value(struct iio_dev *idev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
struct hi8435_priv *priv = iio_priv(idev);
int ret;
u8 mode, psen;
u16 reg;
ret = hi8435_readb(priv, HI8435_PSEN_REG, &psen);
if (ret < 0)
return ret;
mode = !!(psen & BIT(chan->channel / 8));
ret = hi8435_readw(priv, mode ? HI8435_SOCENHYS_REG :
HI8435_GOCENHYS_REG, &reg);
if (ret < 0)
return ret;
if (dir == IIO_EV_DIR_FALLING) {
if (val < 2 || val > 21 || (val + 2) > priv->threshold_hi[mode])
return -EINVAL;
if (val == priv->threshold_lo[mode])
return 0;
priv->threshold_lo[mode] = val;
if ((priv->threshold_hi[mode] - priv->threshold_lo[mode]) % 2)
priv->threshold_hi[mode]--;
} else if (dir == IIO_EV_DIR_RISING) {
if (val < 3 || val > 22 || val < (priv->threshold_lo[mode] + 2))
return -EINVAL;
if (val == priv->threshold_hi[mode])
return 0;
priv->threshold_hi[mode] = val;
if ((priv->threshold_hi[mode] - priv->threshold_lo[mode]) % 2)
priv->threshold_lo[mode]++;
}
mutex_lock(&priv->lock);
ret = hi8435_readw(priv, mode ? HI8435_SOCENHYS_REG :
HI8435_GOCENHYS_REG, &reg);
if (ret < 0) {
mutex_unlock(&priv->lock);
return ret;
}
reg = priv->threshold_hi[mode] - priv->threshold_lo[mode];
reg <<= 8;
reg |= (priv->threshold_hi[mode] + priv->threshold_lo[mode]);
ret = hi8435_writew(priv, mode ? HI8435_SOCENHYS_REG :
HI8435_GOCENHYS_REG, reg);
mutex_unlock(&priv->lock);
return ret;
}
static int hi8435_debugfs_reg_access(struct iio_dev *idev,
unsigned reg, unsigned writeval,
unsigned *readval)
{
struct hi8435_priv *priv = iio_priv(idev);
int ret;
u8 val;
if (readval != NULL) {
ret = hi8435_readb(priv, reg, &val);
*readval = val;
} else {
val = (u8)writeval;
ret = hi8435_writeb(priv, reg, val);
}
return ret;
}
static int hi8435_get_sensing_mode(struct iio_dev *idev,
const struct iio_chan_spec *chan)
{
struct hi8435_priv *priv = iio_priv(idev);
int ret;
u8 reg;
ret = hi8435_readb(priv, HI8435_PSEN_REG, &reg);
if (ret < 0)
return ret;
return !!(reg & BIT(chan->channel / 8));
}
static int hi8435_set_sensing_mode(struct iio_dev *idev,
const struct iio_chan_spec *chan,
unsigned int mode)
{
struct hi8435_priv *priv = iio_priv(idev);
int ret;
u8 reg;
mutex_lock(&priv->lock);
ret = hi8435_readb(priv, HI8435_PSEN_REG, &reg);
if (ret < 0) {
mutex_unlock(&priv->lock);
return ret;
}
reg &= ~BIT(chan->channel / 8);
if (mode)
reg |= BIT(chan->channel / 8);
ret = hi8435_writeb(priv, HI8435_PSEN_REG, reg);
mutex_unlock(&priv->lock);
return ret;
}
static void hi8435_iio_push_event(struct iio_dev *idev, unsigned int val)
{
struct hi8435_priv *priv = iio_priv(idev);
enum iio_event_direction dir;
unsigned int i;
unsigned int status = priv->event_prev_val ^ val;
if (!status)
return;
for_each_set_bit(i, &priv->event_scan_mask, 32) {
if (status & BIT(i)) {
dir = val & BIT(i) ? IIO_EV_DIR_RISING :
IIO_EV_DIR_FALLING;
iio_push_event(idev,
IIO_UNMOD_EVENT_CODE(IIO_VOLTAGE, i,
IIO_EV_TYPE_THRESH, dir),
iio_get_time_ns());
}
}
priv->event_prev_val = val;
}
static irqreturn_t hi8435_trigger_handler(int irq, void *private)
{
struct iio_poll_func *pf = private;
struct iio_dev *idev = pf->indio_dev;
struct hi8435_priv *priv = iio_priv(idev);
u32 val;
int ret;
ret = hi8435_readl(priv, HI8435_SO31_0_REG, &val);
if (ret < 0)
goto err_read;
hi8435_iio_push_event(idev, val);
err_read:
iio_trigger_notify_done(idev->trig);
return IRQ_HANDLED;
}
static int hi8435_probe(struct spi_device *spi)
{
struct iio_dev *idev;
struct hi8435_priv *priv;
struct gpio_desc *reset_gpio;
int ret;
idev = devm_iio_device_alloc(&spi->dev, sizeof(*priv));
if (!idev)
return -ENOMEM;
priv = iio_priv(idev);
priv->spi = spi;
reset_gpio = devm_gpiod_get(&spi->dev, NULL, GPIOD_OUT_LOW);
if (IS_ERR(reset_gpio)) {
hi8435_writeb(priv, HI8435_CTRL_REG, HI8435_CTRL_SRST);
hi8435_writeb(priv, HI8435_CTRL_REG, 0);
} else {
udelay(5);
gpiod_set_value(reset_gpio, 1);
}
spi_set_drvdata(spi, idev);
mutex_init(&priv->lock);
idev->dev.parent = &spi->dev;
idev->name = spi_get_device_id(spi)->name;
idev->modes = INDIO_DIRECT_MODE;
idev->info = &hi8435_info;
idev->channels = hi8435_channels;
idev->num_channels = ARRAY_SIZE(hi8435_channels);
priv->event_scan_mask = ~(0);
priv->threshold_lo[0] = priv->threshold_lo[1] = 2;
priv->threshold_hi[0] = priv->threshold_hi[1] = 4;
hi8435_writew(priv, HI8435_GOCENHYS_REG, 0x206);
hi8435_writew(priv, HI8435_SOCENHYS_REG, 0x206);
ret = iio_triggered_event_setup(idev, NULL, hi8435_trigger_handler);
if (ret)
return ret;
ret = iio_device_register(idev);
if (ret < 0) {
dev_err(&spi->dev, "unable to register device\n");
goto unregister_triggered_event;
}
return 0;
unregister_triggered_event:
iio_triggered_event_cleanup(idev);
return ret;
}
static int hi8435_remove(struct spi_device *spi)
{
struct iio_dev *idev = spi_get_drvdata(spi);
iio_device_unregister(idev);
iio_triggered_event_cleanup(idev);
return 0;
}
