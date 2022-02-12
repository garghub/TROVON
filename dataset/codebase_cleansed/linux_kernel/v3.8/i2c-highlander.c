static inline void highlander_i2c_irq_enable(struct highlander_i2c_dev *dev)
{
iowrite16(ioread16(dev->base + SMCR) | SMCR_IEIC, dev->base + SMCR);
}
static inline void highlander_i2c_irq_disable(struct highlander_i2c_dev *dev)
{
iowrite16(ioread16(dev->base + SMCR) & ~SMCR_IEIC, dev->base + SMCR);
}
static inline void highlander_i2c_start(struct highlander_i2c_dev *dev)
{
iowrite16(ioread16(dev->base + SMCR) | SMCR_START, dev->base + SMCR);
}
static inline void highlander_i2c_done(struct highlander_i2c_dev *dev)
{
iowrite16(ioread16(dev->base + SMCR) | SMCR_IRIC, dev->base + SMCR);
}
static void highlander_i2c_setup(struct highlander_i2c_dev *dev)
{
u16 smmr;
smmr = ioread16(dev->base + SMMR);
smmr |= SMMR_TMMD;
if (iic_force_normal)
smmr &= ~SMMR_SP;
else
smmr |= SMMR_SP;
iowrite16(smmr, dev->base + SMMR);
}
static void smbus_write_data(u8 *src, u16 *dst, int len)
{
for (; len > 1; len -= 2) {
*dst++ = be16_to_cpup((__be16 *)src);
src += 2;
}
if (len)
*dst = *src << 8;
}
static void smbus_read_data(u16 *src, u8 *dst, int len)
{
for (; len > 1; len -= 2) {
*(__be16 *)dst = cpu_to_be16p(src++);
dst += 2;
}
if (len)
*dst = *src >> 8;
}
static void highlander_i2c_command(struct highlander_i2c_dev *dev,
u8 command, int len)
{
unsigned int i;
u16 cmd = (command << 8) | command;
for (i = 0; i < len; i += 2) {
if (len - i == 1)
cmd = command << 8;
iowrite16(cmd, dev->base + SMSADR + i);
dev_dbg(dev->dev, "command data[%x] 0x%04x\n", i/2, cmd);
}
}
static int highlander_i2c_wait_for_bbsy(struct highlander_i2c_dev *dev)
{
unsigned long timeout;
timeout = jiffies + msecs_to_jiffies(iic_timeout);
while (ioread16(dev->base + SMCR) & SMCR_BBSY) {
if (time_after(jiffies, timeout)) {
dev_warn(dev->dev, "timeout waiting for bus ready\n");
return -ETIMEDOUT;
}
msleep(1);
}
return 0;
}
static int highlander_i2c_reset(struct highlander_i2c_dev *dev)
{
iowrite16(ioread16(dev->base + SMCR) | SMCR_RST, dev->base + SMCR);
return highlander_i2c_wait_for_bbsy(dev);
}
static int highlander_i2c_wait_for_ack(struct highlander_i2c_dev *dev)
{
u16 tmp = ioread16(dev->base + SMCR);
if ((tmp & (SMCR_IRIC | SMCR_ACKE)) == SMCR_ACKE) {
dev_warn(dev->dev, "ack abnormality\n");
return highlander_i2c_reset(dev);
}
return 0;
}
static irqreturn_t highlander_i2c_irq(int irq, void *dev_id)
{
struct highlander_i2c_dev *dev = dev_id;
highlander_i2c_done(dev);
complete(&dev->cmd_complete);
return IRQ_HANDLED;
}
static void highlander_i2c_poll(struct highlander_i2c_dev *dev)
{
unsigned long timeout;
u16 smcr;
timeout = jiffies + msecs_to_jiffies(iic_timeout);
for (;;) {
smcr = ioread16(dev->base + SMCR);
if (smcr & SMCR_IRIC)
return;
if (time_after(jiffies, timeout))
break;
cpu_relax();
cond_resched();
}
dev_err(dev->dev, "polling timed out\n");
}
static inline int highlander_i2c_wait_xfer_done(struct highlander_i2c_dev *dev)
{
if (dev->irq)
wait_for_completion_timeout(&dev->cmd_complete,
msecs_to_jiffies(iic_timeout));
else
highlander_i2c_poll(dev);
return highlander_i2c_wait_for_ack(dev);
}
static int highlander_i2c_read(struct highlander_i2c_dev *dev)
{
int i, cnt;
u16 data[16];
if (highlander_i2c_wait_for_bbsy(dev))
return -EAGAIN;
highlander_i2c_start(dev);
if (highlander_i2c_wait_xfer_done(dev)) {
dev_err(dev->dev, "Arbitration loss\n");
return -EAGAIN;
}
if (iic_read_delay && time_before(jiffies, dev->last_read_time +
msecs_to_jiffies(iic_read_delay)))
msleep(jiffies_to_msecs((dev->last_read_time +
msecs_to_jiffies(iic_read_delay)) - jiffies));
cnt = (dev->buf_len + 1) >> 1;
for (i = 0; i < cnt; i++) {
data[i] = ioread16(dev->base + SMTRDR + (i * sizeof(u16)));
dev_dbg(dev->dev, "read data[%x] 0x%04x\n", i, data[i]);
}
smbus_read_data(data, dev->buf, dev->buf_len);
dev->last_read_time = jiffies;
return 0;
}
static int highlander_i2c_write(struct highlander_i2c_dev *dev)
{
int i, cnt;
u16 data[16];
smbus_write_data(dev->buf, data, dev->buf_len);
cnt = (dev->buf_len + 1) >> 1;
for (i = 0; i < cnt; i++) {
iowrite16(data[i], dev->base + SMTRDR + (i * sizeof(u16)));
dev_dbg(dev->dev, "write data[%x] 0x%04x\n", i, data[i]);
}
if (highlander_i2c_wait_for_bbsy(dev))
return -EAGAIN;
highlander_i2c_start(dev);
return highlander_i2c_wait_xfer_done(dev);
}
static int highlander_i2c_smbus_xfer(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size,
union i2c_smbus_data *data)
{
struct highlander_i2c_dev *dev = i2c_get_adapdata(adap);
u16 tmp;
init_completion(&dev->cmd_complete);
dev_dbg(dev->dev, "addr %04x, command %02x, read_write %d, size %d\n",
addr, command, read_write, size);
switch (size) {
case I2C_SMBUS_BYTE_DATA:
dev->buf = &data->byte;
dev->buf_len = 1;
break;
case I2C_SMBUS_I2C_BLOCK_DATA:
dev->buf = &data->block[1];
dev->buf_len = data->block[0];
break;
default:
dev_err(dev->dev, "unsupported command %d\n", size);
return -EINVAL;
}
tmp = ioread16(dev->base + SMMR);
tmp &= ~(SMMR_MODE0 | SMMR_MODE1);
switch (dev->buf_len) {
case 1:
break;
case 8:
tmp |= SMMR_MODE0;
break;
case 16:
tmp |= SMMR_MODE1;
break;
case 32:
tmp |= (SMMR_MODE0 | SMMR_MODE1);
break;
default:
dev_err(dev->dev, "unsupported xfer size %d\n", dev->buf_len);
return -EINVAL;
}
iowrite16(tmp, dev->base + SMMR);
highlander_i2c_done(dev);
iowrite16((addr << 1) | read_write, dev->base + SMSMADR);
highlander_i2c_command(dev, command, dev->buf_len);
if (read_write == I2C_SMBUS_READ)
return highlander_i2c_read(dev);
else
return highlander_i2c_write(dev);
}
static u32 highlander_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_I2C_BLOCK;
}
static int highlander_i2c_probe(struct platform_device *pdev)
{
struct highlander_i2c_dev *dev;
struct i2c_adapter *adap;
struct resource *res;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (unlikely(!res)) {
dev_err(&pdev->dev, "no mem resource\n");
return -ENODEV;
}
dev = kzalloc(sizeof(struct highlander_i2c_dev), GFP_KERNEL);
if (unlikely(!dev))
return -ENOMEM;
dev->base = ioremap_nocache(res->start, resource_size(res));
if (unlikely(!dev->base)) {
ret = -ENXIO;
goto err;
}
dev->dev = &pdev->dev;
platform_set_drvdata(pdev, dev);
dev->irq = platform_get_irq(pdev, 0);
if (iic_force_poll)
dev->irq = 0;
if (dev->irq) {
ret = request_irq(dev->irq, highlander_i2c_irq, 0,
pdev->name, dev);
if (unlikely(ret))
goto err_unmap;
highlander_i2c_irq_enable(dev);
} else {
dev_notice(&pdev->dev, "no IRQ, using polling mode\n");
highlander_i2c_irq_disable(dev);
}
dev->last_read_time = jiffies;
highlander_i2c_setup(dev);
adap = &dev->adapter;
i2c_set_adapdata(adap, dev);
adap->owner = THIS_MODULE;
adap->class = I2C_CLASS_HWMON;
strlcpy(adap->name, "HL FPGA I2C adapter", sizeof(adap->name));
adap->algo = &highlander_i2c_algo;
adap->dev.parent = &pdev->dev;
adap->nr = pdev->id;
ret = highlander_i2c_reset(dev);
if (unlikely(ret)) {
dev_err(&pdev->dev, "controller didn't come up\n");
goto err_free_irq;
}
ret = i2c_add_numbered_adapter(adap);
if (unlikely(ret)) {
dev_err(&pdev->dev, "failure adding adapter\n");
goto err_free_irq;
}
return 0;
err_free_irq:
if (dev->irq)
free_irq(dev->irq, dev);
err_unmap:
iounmap(dev->base);
err:
kfree(dev);
platform_set_drvdata(pdev, NULL);
return ret;
}
static int highlander_i2c_remove(struct platform_device *pdev)
{
struct highlander_i2c_dev *dev = platform_get_drvdata(pdev);
i2c_del_adapter(&dev->adapter);
if (dev->irq)
free_irq(dev->irq, dev);
iounmap(dev->base);
kfree(dev);
platform_set_drvdata(pdev, NULL);
return 0;
}
