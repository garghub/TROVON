static irqreturn_t cht_wc_i2c_adap_thread_handler(int id, void *data)
{
struct cht_wc_i2c_adap *adap = data;
int ret, reg;
mutex_lock(&adap->adap_lock);
ret = regmap_read(adap->regmap, CHT_WC_EXTCHGRIRQ, &reg);
if (ret) {
dev_err(&adap->adapter.dev, "Error reading extchgrirq reg\n");
mutex_unlock(&adap->adap_lock);
return IRQ_NONE;
}
reg &= ~adap->irq_mask;
ret = regmap_read(adap->regmap, CHT_WC_I2C_RDDATA, &adap->read_data);
if (ret)
adap->io_error = true;
ret = regmap_write(adap->regmap, CHT_WC_EXTCHGRIRQ, reg);
if (ret)
dev_err(&adap->adapter.dev, "Error writing extchgrirq reg\n");
if (reg & CHT_WC_EXTCHGRIRQ_ADAP_IRQMASK) {
adap->io_error |= !!(reg & CHT_WC_EXTCHGRIRQ_NACK_IRQ);
adap->done = true;
}
mutex_unlock(&adap->adap_lock);
if (reg & CHT_WC_EXTCHGRIRQ_ADAP_IRQMASK)
wake_up(&adap->wait);
if (reg & CHT_WC_EXTCHGRIRQ_CLIENT_IRQ) {
local_irq_disable();
generic_handle_irq(adap->client_irq);
local_irq_enable();
}
return IRQ_HANDLED;
}
static u32 cht_wc_i2c_adap_master_func(struct i2c_adapter *adap)
{
return I2C_FUNC_SMBUS_BYTE_DATA;
}
static int cht_wc_i2c_adap_smbus_xfer(struct i2c_adapter *_adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size,
union i2c_smbus_data *data)
{
struct cht_wc_i2c_adap *adap = i2c_get_adapdata(_adap);
int ret;
mutex_lock(&adap->adap_lock);
adap->io_error = false;
adap->done = false;
mutex_unlock(&adap->adap_lock);
ret = regmap_write(adap->regmap, CHT_WC_I2C_CLIENT_ADDR, addr);
if (ret)
return ret;
if (read_write == I2C_SMBUS_WRITE) {
ret = regmap_write(adap->regmap, CHT_WC_I2C_WRDATA, data->byte);
if (ret)
return ret;
}
ret = regmap_write(adap->regmap, CHT_WC_I2C_REG_OFFSET, command);
if (ret)
return ret;
ret = regmap_write(adap->regmap, CHT_WC_I2C_CTRL,
(read_write == I2C_SMBUS_WRITE) ?
CHT_WC_I2C_CTRL_WR : CHT_WC_I2C_CTRL_RD);
if (ret)
return ret;
ret = wait_event_timeout(adap->wait, adap->done, msecs_to_jiffies(30));
if (ret == 0) {
cht_wc_i2c_adap_thread_handler(0, adap);
if (!adap->done)
return -ETIMEDOUT;
}
ret = 0;
mutex_lock(&adap->adap_lock);
if (adap->io_error)
ret = -EIO;
else if (read_write == I2C_SMBUS_READ)
data->byte = adap->read_data;
mutex_unlock(&adap->adap_lock);
return ret;
}
static void cht_wc_i2c_irq_lock(struct irq_data *data)
{
struct cht_wc_i2c_adap *adap = irq_data_get_irq_chip_data(data);
mutex_lock(&adap->irqchip_lock);
}
static void cht_wc_i2c_irq_sync_unlock(struct irq_data *data)
{
struct cht_wc_i2c_adap *adap = irq_data_get_irq_chip_data(data);
int ret;
if (adap->irq_mask != adap->old_irq_mask) {
ret = regmap_write(adap->regmap, CHT_WC_EXTCHGRIRQ_MSK,
adap->irq_mask);
if (ret == 0)
adap->old_irq_mask = adap->irq_mask;
else
dev_err(&adap->adapter.dev, "Error writing EXTCHGRIRQ_MSK\n");
}
mutex_unlock(&adap->irqchip_lock);
}
static void cht_wc_i2c_irq_enable(struct irq_data *data)
{
struct cht_wc_i2c_adap *adap = irq_data_get_irq_chip_data(data);
adap->irq_mask &= ~CHT_WC_EXTCHGRIRQ_CLIENT_IRQ;
}
static void cht_wc_i2c_irq_disable(struct irq_data *data)
{
struct cht_wc_i2c_adap *adap = irq_data_get_irq_chip_data(data);
adap->irq_mask |= CHT_WC_EXTCHGRIRQ_CLIENT_IRQ;
}
static int cht_wc_i2c_adap_i2c_probe(struct platform_device *pdev)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(pdev->dev.parent);
struct cht_wc_i2c_adap *adap;
struct i2c_board_info board_info = {
.type = "bq24190",
.addr = 0x6b,
.properties = bq24190_props,
};
int ret, reg, irq;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "Error missing irq resource\n");
return -EINVAL;
}
adap = devm_kzalloc(&pdev->dev, sizeof(*adap), GFP_KERNEL);
if (!adap)
return -ENOMEM;
init_waitqueue_head(&adap->wait);
mutex_init(&adap->adap_lock);
mutex_init(&adap->irqchip_lock);
adap->irqchip = cht_wc_i2c_irq_chip;
adap->regmap = pmic->regmap;
adap->adapter.owner = THIS_MODULE;
adap->adapter.class = I2C_CLASS_HWMON;
adap->adapter.algo = &cht_wc_i2c_adap_algo;
strlcpy(adap->adapter.name, "PMIC I2C Adapter",
sizeof(adap->adapter.name));
adap->adapter.dev.parent = &pdev->dev;
adap->old_irq_mask = adap->irq_mask = ~CHT_WC_EXTCHGRIRQ_ADAP_IRQMASK;
ret = regmap_read(adap->regmap, CHT_WC_I2C_RDDATA, &reg);
if (ret)
return ret;
ret = regmap_write(adap->regmap, CHT_WC_EXTCHGRIRQ, ~adap->irq_mask);
if (ret)
return ret;
ret = regmap_write(adap->regmap, CHT_WC_EXTCHGRIRQ_MSK, adap->irq_mask);
if (ret)
return ret;
adap->irq_domain = irq_domain_add_linear(pdev->dev.of_node, 1,
&irq_domain_simple_ops, NULL);
if (!adap->irq_domain)
return -ENOMEM;
adap->client_irq = irq_create_mapping(adap->irq_domain, 0);
if (!adap->client_irq) {
ret = -ENOMEM;
goto remove_irq_domain;
}
irq_set_chip_data(adap->client_irq, adap);
irq_set_chip_and_handler(adap->client_irq, &adap->irqchip,
handle_simple_irq);
ret = devm_request_threaded_irq(&pdev->dev, irq, NULL,
cht_wc_i2c_adap_thread_handler,
IRQF_ONESHOT, "PMIC I2C Adapter", adap);
if (ret)
goto remove_irq_domain;
i2c_set_adapdata(&adap->adapter, adap);
ret = i2c_add_adapter(&adap->adapter);
if (ret)
goto remove_irq_domain;
board_info.irq = adap->client_irq;
adap->client = i2c_new_device(&adap->adapter, &board_info);
if (!adap->client) {
ret = -ENOMEM;
goto del_adapter;
}
platform_set_drvdata(pdev, adap);
return 0;
del_adapter:
i2c_del_adapter(&adap->adapter);
remove_irq_domain:
irq_domain_remove(adap->irq_domain);
return ret;
}
static int cht_wc_i2c_adap_i2c_remove(struct platform_device *pdev)
{
struct cht_wc_i2c_adap *adap = platform_get_drvdata(pdev);
i2c_unregister_device(adap->client);
i2c_del_adapter(&adap->adapter);
irq_domain_remove(adap->irq_domain);
return 0;
}
