static void cbus_send_bit(struct cbus_host *host, unsigned bit)
{
gpio_set_value(host->dat_gpio, bit ? 1 : 0);
gpio_set_value(host->clk_gpio, 1);
gpio_set_value(host->clk_gpio, 0);
}
static void cbus_send_data(struct cbus_host *host, unsigned data, unsigned len)
{
int i;
for (i = len; i > 0; i--)
cbus_send_bit(host, data & (1 << (i - 1)));
}
static int cbus_receive_bit(struct cbus_host *host)
{
int ret;
gpio_set_value(host->clk_gpio, 1);
ret = gpio_get_value(host->dat_gpio);
gpio_set_value(host->clk_gpio, 0);
return ret;
}
static int cbus_receive_word(struct cbus_host *host)
{
int ret = 0;
int i;
for (i = 16; i > 0; i--) {
int bit = cbus_receive_bit(host);
if (bit < 0)
return bit;
if (bit)
ret |= 1 << (i - 1);
}
return ret;
}
static int cbus_transfer(struct cbus_host *host, char rw, unsigned dev,
unsigned reg, unsigned data)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&host->lock, flags);
gpio_set_value(host->sel_gpio, 0);
gpio_direction_output(host->dat_gpio, 1);
cbus_send_data(host, dev, CBUS_ADDR_BITS);
cbus_send_bit(host, rw == I2C_SMBUS_READ);
cbus_send_data(host, reg, CBUS_REG_BITS);
if (rw == I2C_SMBUS_WRITE) {
cbus_send_data(host, data, 16);
ret = 0;
} else {
ret = gpio_direction_input(host->dat_gpio);
if (ret) {
dev_dbg(host->dev, "failed setting direction\n");
goto out;
}
gpio_set_value(host->clk_gpio, 1);
ret = cbus_receive_word(host);
if (ret < 0) {
dev_dbg(host->dev, "failed receiving data\n");
goto out;
}
}
gpio_set_value(host->sel_gpio, 1);
gpio_set_value(host->clk_gpio, 1);
gpio_set_value(host->clk_gpio, 0);
out:
spin_unlock_irqrestore(&host->lock, flags);
return ret;
}
static int cbus_i2c_smbus_xfer(struct i2c_adapter *adapter,
u16 addr,
unsigned short flags,
char read_write,
u8 command,
int size,
union i2c_smbus_data *data)
{
struct cbus_host *chost = i2c_get_adapdata(adapter);
int ret;
if (size != I2C_SMBUS_WORD_DATA)
return -EINVAL;
ret = cbus_transfer(chost, read_write == I2C_SMBUS_READ, addr,
command, data->word);
if (ret < 0)
return ret;
if (read_write == I2C_SMBUS_READ)
data->word = ret;
return 0;
}
static u32 cbus_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_SMBUS_READ_WORD_DATA | I2C_FUNC_SMBUS_WRITE_WORD_DATA;
}
static int cbus_i2c_remove(struct platform_device *pdev)
{
struct i2c_adapter *adapter = platform_get_drvdata(pdev);
i2c_del_adapter(adapter);
return 0;
}
static int cbus_i2c_probe(struct platform_device *pdev)
{
struct i2c_adapter *adapter;
struct cbus_host *chost;
int ret;
adapter = devm_kzalloc(&pdev->dev, sizeof(struct i2c_adapter),
GFP_KERNEL);
if (!adapter)
return -ENOMEM;
chost = devm_kzalloc(&pdev->dev, sizeof(*chost), GFP_KERNEL);
if (!chost)
return -ENOMEM;
if (pdev->dev.of_node) {
struct device_node *dnode = pdev->dev.of_node;
if (of_gpio_count(dnode) != 3)
return -ENODEV;
chost->clk_gpio = of_get_gpio(dnode, 0);
chost->dat_gpio = of_get_gpio(dnode, 1);
chost->sel_gpio = of_get_gpio(dnode, 2);
} else if (pdev->dev.platform_data) {
struct i2c_cbus_platform_data *pdata = pdev->dev.platform_data;
chost->clk_gpio = pdata->clk_gpio;
chost->dat_gpio = pdata->dat_gpio;
chost->sel_gpio = pdata->sel_gpio;
} else {
return -ENODEV;
}
adapter->owner = THIS_MODULE;
adapter->class = I2C_CLASS_HWMON;
adapter->dev.parent = &pdev->dev;
adapter->nr = pdev->id;
adapter->timeout = HZ;
adapter->algo = &cbus_i2c_algo;
strlcpy(adapter->name, "CBUS I2C adapter", sizeof(adapter->name));
spin_lock_init(&chost->lock);
chost->dev = &pdev->dev;
ret = devm_gpio_request_one(&pdev->dev, chost->clk_gpio,
GPIOF_OUT_INIT_LOW, "CBUS clk");
if (ret)
return ret;
ret = devm_gpio_request_one(&pdev->dev, chost->dat_gpio, GPIOF_IN,
"CBUS data");
if (ret)
return ret;
ret = devm_gpio_request_one(&pdev->dev, chost->sel_gpio,
GPIOF_OUT_INIT_HIGH, "CBUS sel");
if (ret)
return ret;
i2c_set_adapdata(adapter, chost);
platform_set_drvdata(pdev, adapter);
return i2c_add_numbered_adapter(adapter);
}
