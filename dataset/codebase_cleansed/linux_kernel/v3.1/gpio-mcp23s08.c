static int mcp23008_read(struct mcp23s08 *mcp, unsigned reg)
{
return i2c_smbus_read_byte_data(mcp->data, reg);
}
static int mcp23008_write(struct mcp23s08 *mcp, unsigned reg, unsigned val)
{
return i2c_smbus_write_byte_data(mcp->data, reg, val);
}
static int
mcp23008_read_regs(struct mcp23s08 *mcp, unsigned reg, u16 *vals, unsigned n)
{
while (n--) {
int ret = mcp23008_read(mcp, reg++);
if (ret < 0)
return ret;
*vals++ = ret;
}
return 0;
}
static int mcp23017_read(struct mcp23s08 *mcp, unsigned reg)
{
return i2c_smbus_read_word_data(mcp->data, reg << 1);
}
static int mcp23017_write(struct mcp23s08 *mcp, unsigned reg, unsigned val)
{
return i2c_smbus_write_word_data(mcp->data, reg << 1, val);
}
static int
mcp23017_read_regs(struct mcp23s08 *mcp, unsigned reg, u16 *vals, unsigned n)
{
while (n--) {
int ret = mcp23017_read(mcp, reg++);
if (ret < 0)
return ret;
*vals++ = ret;
}
return 0;
}
static int mcp23s08_read(struct mcp23s08 *mcp, unsigned reg)
{
u8 tx[2], rx[1];
int status;
tx[0] = mcp->addr | 0x01;
tx[1] = reg;
status = spi_write_then_read(mcp->data, tx, sizeof tx, rx, sizeof rx);
return (status < 0) ? status : rx[0];
}
static int mcp23s08_write(struct mcp23s08 *mcp, unsigned reg, unsigned val)
{
u8 tx[3];
tx[0] = mcp->addr;
tx[1] = reg;
tx[2] = val;
return spi_write_then_read(mcp->data, tx, sizeof tx, NULL, 0);
}
static int
mcp23s08_read_regs(struct mcp23s08 *mcp, unsigned reg, u16 *vals, unsigned n)
{
u8 tx[2], *tmp;
int status;
if ((n + reg) > sizeof mcp->cache)
return -EINVAL;
tx[0] = mcp->addr | 0x01;
tx[1] = reg;
tmp = (u8 *)vals;
status = spi_write_then_read(mcp->data, tx, sizeof tx, tmp, n);
if (status >= 0) {
while (n--)
vals[n] = tmp[n];
}
return status;
}
static int mcp23s17_read(struct mcp23s08 *mcp, unsigned reg)
{
u8 tx[2], rx[2];
int status;
tx[0] = mcp->addr | 0x01;
tx[1] = reg << 1;
status = spi_write_then_read(mcp->data, tx, sizeof tx, rx, sizeof rx);
return (status < 0) ? status : (rx[0] | (rx[1] << 8));
}
static int mcp23s17_write(struct mcp23s08 *mcp, unsigned reg, unsigned val)
{
u8 tx[4];
tx[0] = mcp->addr;
tx[1] = reg << 1;
tx[2] = val;
tx[3] = val >> 8;
return spi_write_then_read(mcp->data, tx, sizeof tx, NULL, 0);
}
static int
mcp23s17_read_regs(struct mcp23s08 *mcp, unsigned reg, u16 *vals, unsigned n)
{
u8 tx[2];
int status;
if ((n + reg) > sizeof mcp->cache)
return -EINVAL;
tx[0] = mcp->addr | 0x01;
tx[1] = reg << 1;
status = spi_write_then_read(mcp->data, tx, sizeof tx,
(u8 *)vals, n * 2);
if (status >= 0) {
while (n--)
vals[n] = __le16_to_cpu((__le16)vals[n]);
}
return status;
}
static int mcp23s08_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct mcp23s08 *mcp = container_of(chip, struct mcp23s08, chip);
int status;
mutex_lock(&mcp->lock);
mcp->cache[MCP_IODIR] |= (1 << offset);
status = mcp->ops->write(mcp, MCP_IODIR, mcp->cache[MCP_IODIR]);
mutex_unlock(&mcp->lock);
return status;
}
static int mcp23s08_get(struct gpio_chip *chip, unsigned offset)
{
struct mcp23s08 *mcp = container_of(chip, struct mcp23s08, chip);
int status;
mutex_lock(&mcp->lock);
status = mcp->ops->read(mcp, MCP_GPIO);
if (status < 0)
status = 0;
else {
mcp->cache[MCP_GPIO] = status;
status = !!(status & (1 << offset));
}
mutex_unlock(&mcp->lock);
return status;
}
static int __mcp23s08_set(struct mcp23s08 *mcp, unsigned mask, int value)
{
unsigned olat = mcp->cache[MCP_OLAT];
if (value)
olat |= mask;
else
olat &= ~mask;
mcp->cache[MCP_OLAT] = olat;
return mcp->ops->write(mcp, MCP_OLAT, olat);
}
static void mcp23s08_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct mcp23s08 *mcp = container_of(chip, struct mcp23s08, chip);
unsigned mask = 1 << offset;
mutex_lock(&mcp->lock);
__mcp23s08_set(mcp, mask, value);
mutex_unlock(&mcp->lock);
}
static int
mcp23s08_direction_output(struct gpio_chip *chip, unsigned offset, int value)
{
struct mcp23s08 *mcp = container_of(chip, struct mcp23s08, chip);
unsigned mask = 1 << offset;
int status;
mutex_lock(&mcp->lock);
status = __mcp23s08_set(mcp, mask, value);
if (status == 0) {
mcp->cache[MCP_IODIR] &= ~mask;
status = mcp->ops->write(mcp, MCP_IODIR, mcp->cache[MCP_IODIR]);
}
mutex_unlock(&mcp->lock);
return status;
}
static void mcp23s08_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
struct mcp23s08 *mcp;
char bank;
int t;
unsigned mask;
mcp = container_of(chip, struct mcp23s08, chip);
bank = '0' + ((mcp->addr >> 1) & 0x7);
mutex_lock(&mcp->lock);
t = mcp->ops->read_regs(mcp, 0, mcp->cache, ARRAY_SIZE(mcp->cache));
if (t < 0) {
seq_printf(s, " I/O ERROR %d\n", t);
goto done;
}
for (t = 0, mask = 1; t < chip->ngpio; t++, mask <<= 1) {
const char *label;
label = gpiochip_is_requested(chip, t);
if (!label)
continue;
seq_printf(s, " gpio-%-3d P%c.%d (%-12s) %s %s %s",
chip->base + t, bank, t, label,
(mcp->cache[MCP_IODIR] & mask) ? "in " : "out",
(mcp->cache[MCP_GPIO] & mask) ? "hi" : "lo",
(mcp->cache[MCP_GPPU] & mask) ? " " : "up");
seq_printf(s, "\n");
}
done:
mutex_unlock(&mcp->lock);
}
static int mcp23s08_probe_one(struct mcp23s08 *mcp, struct device *dev,
void *data, unsigned addr,
unsigned type, unsigned base, unsigned pullups)
{
int status;
mutex_init(&mcp->lock);
mcp->data = data;
mcp->addr = addr;
mcp->chip.direction_input = mcp23s08_direction_input;
mcp->chip.get = mcp23s08_get;
mcp->chip.direction_output = mcp23s08_direction_output;
mcp->chip.set = mcp23s08_set;
mcp->chip.dbg_show = mcp23s08_dbg_show;
switch (type) {
#ifdef CONFIG_SPI_MASTER
case MCP_TYPE_S08:
mcp->ops = &mcp23s08_ops;
mcp->chip.ngpio = 8;
mcp->chip.label = "mcp23s08";
break;
case MCP_TYPE_S17:
mcp->ops = &mcp23s17_ops;
mcp->chip.ngpio = 16;
mcp->chip.label = "mcp23s17";
break;
#endif
#ifdef CONFIG_I2C
case MCP_TYPE_008:
mcp->ops = &mcp23008_ops;
mcp->chip.ngpio = 8;
mcp->chip.label = "mcp23008";
break;
case MCP_TYPE_017:
mcp->ops = &mcp23017_ops;
mcp->chip.ngpio = 16;
mcp->chip.label = "mcp23017";
break;
#endif
default:
dev_err(dev, "invalid device type (%d)\n", type);
return -EINVAL;
}
mcp->chip.base = base;
mcp->chip.can_sleep = 1;
mcp->chip.dev = dev;
mcp->chip.owner = THIS_MODULE;
status = mcp->ops->read(mcp, MCP_IOCON);
if (status < 0)
goto fail;
if ((status & IOCON_SEQOP) || !(status & IOCON_HAEN)) {
status &= ~(IOCON_SEQOP | (IOCON_SEQOP << 8));
status |= IOCON_HAEN | (IOCON_HAEN << 8);
status = mcp->ops->write(mcp, MCP_IOCON, status);
if (status < 0)
goto fail;
}
status = mcp->ops->write(mcp, MCP_GPPU, pullups);
if (status < 0)
goto fail;
status = mcp->ops->read_regs(mcp, 0, mcp->cache, ARRAY_SIZE(mcp->cache));
if (status < 0)
goto fail;
if (mcp->cache[MCP_IPOL] != 0) {
mcp->cache[MCP_IPOL] = 0;
status = mcp->ops->write(mcp, MCP_IPOL, 0);
if (status < 0)
goto fail;
}
if (mcp->cache[MCP_GPINTEN] != 0) {
mcp->cache[MCP_GPINTEN] = 0;
status = mcp->ops->write(mcp, MCP_GPINTEN, 0);
if (status < 0)
goto fail;
}
status = gpiochip_add(&mcp->chip);
fail:
if (status < 0)
dev_dbg(dev, "can't setup chip %d, --> %d\n",
addr, status);
return status;
}
static int __devinit mcp230xx_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mcp23s08_platform_data *pdata;
struct mcp23s08 *mcp;
int status;
pdata = client->dev.platform_data;
if (!pdata || !gpio_is_valid(pdata->base)) {
dev_dbg(&client->dev, "invalid or missing platform data\n");
return -EINVAL;
}
mcp = kzalloc(sizeof *mcp, GFP_KERNEL);
if (!mcp)
return -ENOMEM;
status = mcp23s08_probe_one(mcp, &client->dev, client, client->addr,
id->driver_data, pdata->base,
pdata->chip[0].pullups);
if (status)
goto fail;
i2c_set_clientdata(client, mcp);
return 0;
fail:
kfree(mcp);
return status;
}
static int __devexit mcp230xx_remove(struct i2c_client *client)
{
struct mcp23s08 *mcp = i2c_get_clientdata(client);
int status;
status = gpiochip_remove(&mcp->chip);
if (status == 0)
kfree(mcp);
return status;
}
static int __init mcp23s08_i2c_init(void)
{
return i2c_add_driver(&mcp230xx_driver);
}
static void mcp23s08_i2c_exit(void)
{
i2c_del_driver(&mcp230xx_driver);
}
static int __init mcp23s08_i2c_init(void) { return 0; }
static void mcp23s08_i2c_exit(void) { }
static int mcp23s08_probe(struct spi_device *spi)
{
struct mcp23s08_platform_data *pdata;
unsigned addr;
unsigned chips = 0;
struct mcp23s08_driver_data *data;
int status, type;
unsigned base;
type = spi_get_device_id(spi)->driver_data;
pdata = spi->dev.platform_data;
if (!pdata || !gpio_is_valid(pdata->base)) {
dev_dbg(&spi->dev, "invalid or missing platform data\n");
return -EINVAL;
}
for (addr = 0; addr < ARRAY_SIZE(pdata->chip); addr++) {
if (!pdata->chip[addr].is_present)
continue;
chips++;
if ((type == MCP_TYPE_S08) && (addr > 3)) {
dev_err(&spi->dev,
"mcp23s08 only supports address 0..3\n");
return -EINVAL;
}
}
if (!chips)
return -ENODEV;
data = kzalloc(sizeof *data + chips * sizeof(struct mcp23s08),
GFP_KERNEL);
if (!data)
return -ENOMEM;
spi_set_drvdata(spi, data);
base = pdata->base;
for (addr = 0; addr < ARRAY_SIZE(pdata->chip); addr++) {
if (!pdata->chip[addr].is_present)
continue;
chips--;
data->mcp[addr] = &data->chip[chips];
status = mcp23s08_probe_one(data->mcp[addr], &spi->dev, spi,
0x40 | (addr << 1), type, base,
pdata->chip[addr].pullups);
if (status < 0)
goto fail;
base += (type == MCP_TYPE_S17) ? 16 : 8;
}
data->ngpio = base - pdata->base;
return 0;
fail:
for (addr = 0; addr < ARRAY_SIZE(data->mcp); addr++) {
int tmp;
if (!data->mcp[addr])
continue;
tmp = gpiochip_remove(&data->mcp[addr]->chip);
if (tmp < 0)
dev_err(&spi->dev, "%s --> %d\n", "remove", tmp);
}
kfree(data);
return status;
}
static int mcp23s08_remove(struct spi_device *spi)
{
struct mcp23s08_driver_data *data = spi_get_drvdata(spi);
unsigned addr;
int status = 0;
for (addr = 0; addr < ARRAY_SIZE(data->mcp); addr++) {
int tmp;
if (!data->mcp[addr])
continue;
tmp = gpiochip_remove(&data->mcp[addr]->chip);
if (tmp < 0) {
dev_err(&spi->dev, "%s --> %d\n", "remove", tmp);
status = tmp;
}
}
if (status == 0)
kfree(data);
return status;
}
static int __init mcp23s08_spi_init(void)
{
return spi_register_driver(&mcp23s08_driver);
}
static void mcp23s08_spi_exit(void)
{
spi_unregister_driver(&mcp23s08_driver);
}
static int __init mcp23s08_spi_init(void) { return 0; }
static void mcp23s08_spi_exit(void) { }
static int __init mcp23s08_init(void)
{
int ret;
ret = mcp23s08_spi_init();
if (ret)
goto spi_fail;
ret = mcp23s08_i2c_init();
if (ret)
goto i2c_fail;
return 0;
i2c_fail:
mcp23s08_spi_exit();
spi_fail:
return ret;
}
static void __exit mcp23s08_exit(void)
{
mcp23s08_spi_exit();
mcp23s08_i2c_exit();
}
