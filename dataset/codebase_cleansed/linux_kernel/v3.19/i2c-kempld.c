static int kempld_i2c_process(struct kempld_i2c_data *i2c)
{
struct kempld_device_data *pld = i2c->pld;
u8 stat = kempld_read8(pld, KEMPLD_I2C_STAT);
struct i2c_msg *msg = i2c->msg;
u8 addr;
if (stat & I2C_STAT_TIP)
return -EBUSY;
if (i2c->state == STATE_DONE || i2c->state == STATE_ERROR) {
kempld_write8(pld, KEMPLD_I2C_CMD, I2C_CMD_IACK);
if (i2c->state == STATE_ERROR)
return -EIO;
return 0;
}
if (stat & I2C_STAT_ARBLOST) {
i2c->state = STATE_ERROR;
kempld_write8(pld, KEMPLD_I2C_CMD, I2C_CMD_STOP);
return -EAGAIN;
}
if (i2c->state == STATE_INIT) {
if (stat & I2C_STAT_BUSY)
return -EBUSY;
i2c->state = STATE_ADDR;
}
if (i2c->state == STATE_ADDR) {
if (i2c->msg->flags & I2C_M_TEN) {
addr = 0xf0 | ((i2c->msg->addr >> 7) & 0x6);
i2c->state = STATE_ADDR10;
} else {
addr = (i2c->msg->addr << 1);
i2c->state = STATE_START;
}
addr |= (i2c->msg->flags & I2C_M_RD) ? 1 : 0;
kempld_write8(pld, KEMPLD_I2C_DATA, addr);
kempld_write8(pld, KEMPLD_I2C_CMD, I2C_CMD_START);
return 0;
}
if (i2c->state == STATE_ADDR10) {
kempld_write8(pld, KEMPLD_I2C_DATA, i2c->msg->addr & 0xff);
kempld_write8(pld, KEMPLD_I2C_CMD, I2C_CMD_WRITE);
i2c->state = STATE_START;
return 0;
}
if (i2c->state == STATE_START || i2c->state == STATE_WRITE) {
i2c->state = (msg->flags & I2C_M_RD) ? STATE_READ : STATE_WRITE;
if (stat & I2C_STAT_NACK) {
i2c->state = STATE_ERROR;
kempld_write8(pld, KEMPLD_I2C_CMD, I2C_CMD_STOP);
return -ENXIO;
}
} else {
msg->buf[i2c->pos++] = kempld_read8(pld, KEMPLD_I2C_DATA);
}
if (i2c->pos >= msg->len) {
i2c->nmsgs--;
i2c->msg++;
i2c->pos = 0;
msg = i2c->msg;
if (i2c->nmsgs) {
if (!(msg->flags & I2C_M_NOSTART)) {
i2c->state = STATE_ADDR;
return 0;
} else {
i2c->state = (msg->flags & I2C_M_RD)
? STATE_READ : STATE_WRITE;
}
} else {
i2c->state = STATE_DONE;
kempld_write8(pld, KEMPLD_I2C_CMD, I2C_CMD_STOP);
return 0;
}
}
if (i2c->state == STATE_READ) {
kempld_write8(pld, KEMPLD_I2C_CMD, i2c->pos == (msg->len - 1) ?
I2C_CMD_READ_NACK : I2C_CMD_READ_ACK);
} else {
kempld_write8(pld, KEMPLD_I2C_DATA, msg->buf[i2c->pos++]);
kempld_write8(pld, KEMPLD_I2C_CMD, I2C_CMD_WRITE);
}
return 0;
}
static int kempld_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
int num)
{
struct kempld_i2c_data *i2c = i2c_get_adapdata(adap);
struct kempld_device_data *pld = i2c->pld;
unsigned long timeout = jiffies + HZ;
int ret;
i2c->msg = msgs;
i2c->pos = 0;
i2c->nmsgs = num;
i2c->state = STATE_INIT;
while (time_before(jiffies, timeout)) {
kempld_get_mutex(pld);
ret = kempld_i2c_process(i2c);
kempld_release_mutex(pld);
if (i2c->state == STATE_DONE || i2c->state == STATE_ERROR)
return (i2c->state == STATE_DONE) ? num : ret;
if (ret == 0)
timeout = jiffies + HZ;
usleep_range(5, 15);
}
i2c->state = STATE_ERROR;
return -ETIMEDOUT;
}
static void kempld_i2c_device_init(struct kempld_i2c_data *i2c)
{
struct kempld_device_data *pld = i2c->pld;
u16 prescale_corr;
long prescale;
u8 ctrl;
u8 stat;
u8 cfg;
ctrl = kempld_read8(pld, KEMPLD_I2C_CTRL);
ctrl &= ~(I2C_CTRL_EN | I2C_CTRL_IEN);
kempld_write8(pld, KEMPLD_I2C_CTRL, ctrl);
if (bus_frequency > KEMPLD_I2C_FREQ_MAX)
bus_frequency = KEMPLD_I2C_FREQ_MAX;
if (pld->info.spec_major == 1)
prescale = pld->pld_clock / (bus_frequency * 5) - 1000;
else
prescale = pld->pld_clock / (bus_frequency * 4) - 3000;
if (prescale < 0)
prescale = 0;
prescale_corr = prescale / 1000;
if (prescale % 1000 >= 500)
prescale_corr++;
kempld_write8(pld, KEMPLD_I2C_PRELOW, prescale_corr & 0xff);
kempld_write8(pld, KEMPLD_I2C_PREHIGH, prescale_corr >> 8);
cfg = kempld_read8(pld, KEMPLD_CFG);
if (i2c_gpio_mux)
cfg |= KEMPLD_CFG_GPIO_I2C_MUX;
else
cfg &= ~KEMPLD_CFG_GPIO_I2C_MUX;
kempld_write8(pld, KEMPLD_CFG, cfg);
kempld_write8(pld, KEMPLD_I2C_CMD, I2C_CMD_IACK);
ctrl |= I2C_CTRL_EN;
kempld_write8(pld, KEMPLD_I2C_CTRL, ctrl);
stat = kempld_read8(pld, KEMPLD_I2C_STAT);
if (stat & I2C_STAT_BUSY)
kempld_write8(pld, KEMPLD_I2C_CMD, I2C_CMD_STOP);
}
static u32 kempld_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_10BIT_ADDR | I2C_FUNC_SMBUS_EMUL;
}
static int kempld_i2c_probe(struct platform_device *pdev)
{
struct kempld_device_data *pld = dev_get_drvdata(pdev->dev.parent);
struct kempld_i2c_data *i2c;
int ret;
u8 ctrl;
i2c = devm_kzalloc(&pdev->dev, sizeof(*i2c), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
i2c->pld = pld;
i2c->dev = &pdev->dev;
i2c->adap = kempld_i2c_adapter;
i2c->adap.dev.parent = i2c->dev;
i2c_set_adapdata(&i2c->adap, i2c);
platform_set_drvdata(pdev, i2c);
kempld_get_mutex(pld);
ctrl = kempld_read8(pld, KEMPLD_I2C_CTRL);
if (ctrl & I2C_CTRL_EN)
i2c->was_active = true;
kempld_i2c_device_init(i2c);
kempld_release_mutex(pld);
if (i2c_bus >= -1)
i2c->adap.nr = i2c_bus;
ret = i2c_add_numbered_adapter(&i2c->adap);
if (ret)
return ret;
dev_info(i2c->dev, "I2C bus initialized at %dkHz\n",
bus_frequency);
return 0;
}
static int kempld_i2c_remove(struct platform_device *pdev)
{
struct kempld_i2c_data *i2c = platform_get_drvdata(pdev);
struct kempld_device_data *pld = i2c->pld;
u8 ctrl;
kempld_get_mutex(pld);
if (!i2c->was_active) {
ctrl = kempld_read8(pld, KEMPLD_I2C_CTRL);
ctrl &= ~I2C_CTRL_EN;
kempld_write8(pld, KEMPLD_I2C_CTRL, ctrl);
}
kempld_release_mutex(pld);
i2c_del_adapter(&i2c->adap);
return 0;
}
static int kempld_i2c_suspend(struct platform_device *pdev, pm_message_t state)
{
struct kempld_i2c_data *i2c = platform_get_drvdata(pdev);
struct kempld_device_data *pld = i2c->pld;
u8 ctrl;
kempld_get_mutex(pld);
ctrl = kempld_read8(pld, KEMPLD_I2C_CTRL);
ctrl &= ~I2C_CTRL_EN;
kempld_write8(pld, KEMPLD_I2C_CTRL, ctrl);
kempld_release_mutex(pld);
return 0;
}
static int kempld_i2c_resume(struct platform_device *pdev)
{
struct kempld_i2c_data *i2c = platform_get_drvdata(pdev);
struct kempld_device_data *pld = i2c->pld;
kempld_get_mutex(pld);
kempld_i2c_device_init(i2c);
kempld_release_mutex(pld);
return 0;
}
