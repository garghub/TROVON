static int i2c_pca_pf_readbyte8(void *pd, int reg)
{
struct i2c_pca_pf_data *i2c = pd;
return ioread8(i2c->reg_base + reg);
}
static int i2c_pca_pf_readbyte16(void *pd, int reg)
{
struct i2c_pca_pf_data *i2c = pd;
return ioread8(i2c->reg_base + reg * 2);
}
static int i2c_pca_pf_readbyte32(void *pd, int reg)
{
struct i2c_pca_pf_data *i2c = pd;
return ioread8(i2c->reg_base + reg * 4);
}
static void i2c_pca_pf_writebyte8(void *pd, int reg, int val)
{
struct i2c_pca_pf_data *i2c = pd;
iowrite8(val, i2c->reg_base + reg);
}
static void i2c_pca_pf_writebyte16(void *pd, int reg, int val)
{
struct i2c_pca_pf_data *i2c = pd;
iowrite8(val, i2c->reg_base + reg * 2);
}
static void i2c_pca_pf_writebyte32(void *pd, int reg, int val)
{
struct i2c_pca_pf_data *i2c = pd;
iowrite8(val, i2c->reg_base + reg * 4);
}
static int i2c_pca_pf_waitforcompletion(void *pd)
{
struct i2c_pca_pf_data *i2c = pd;
unsigned long timeout;
long ret;
if (i2c->irq) {
ret = wait_event_timeout(i2c->wait,
i2c->algo_data.read_byte(i2c, I2C_PCA_CON)
& I2C_PCA_CON_SI, i2c->adap.timeout);
} else {
timeout = jiffies + i2c->adap.timeout;
do {
ret = time_before(jiffies, timeout);
if (i2c->algo_data.read_byte(i2c, I2C_PCA_CON)
& I2C_PCA_CON_SI)
break;
udelay(100);
} while (ret);
}
return ret > 0;
}
static void i2c_pca_pf_dummyreset(void *pd)
{
struct i2c_pca_pf_data *i2c = pd;
dev_warn(&i2c->adap.dev, "No reset-pin found. Chip may get stuck!\n");
}
static void i2c_pca_pf_resetchip(void *pd)
{
struct i2c_pca_pf_data *i2c = pd;
gpiod_set_value(i2c->gpio, 1);
ndelay(100);
gpiod_set_value(i2c->gpio, 0);
}
static irqreturn_t i2c_pca_pf_handler(int this_irq, void *dev_id)
{
struct i2c_pca_pf_data *i2c = dev_id;
if ((i2c->algo_data.read_byte(i2c, I2C_PCA_CON) & I2C_PCA_CON_SI) == 0)
return IRQ_NONE;
wake_up(&i2c->wait);
return IRQ_HANDLED;
}
static int i2c_pca_pf_probe(struct platform_device *pdev)
{
struct i2c_pca_pf_data *i2c;
struct resource *res;
struct i2c_pca9564_pf_platform_data *platform_data =
dev_get_platdata(&pdev->dev);
struct device_node *np = pdev->dev.of_node;
int ret = 0;
int irq;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
irq = 0;
i2c = devm_kzalloc(&pdev->dev, sizeof(*i2c), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(i2c->reg_base))
return PTR_ERR(i2c->reg_base);
init_waitqueue_head(&i2c->wait);
i2c->io_base = res->start;
i2c->io_size = resource_size(res);
i2c->irq = irq;
i2c->adap.nr = pdev->id;
i2c->adap.owner = THIS_MODULE;
snprintf(i2c->adap.name, sizeof(i2c->adap.name),
"PCA9564/PCA9665 at 0x%08lx",
(unsigned long) res->start);
i2c->adap.algo_data = &i2c->algo_data;
i2c->adap.dev.parent = &pdev->dev;
i2c->adap.dev.of_node = np;
if (platform_data) {
i2c->adap.timeout = platform_data->timeout;
i2c->algo_data.i2c_clock = platform_data->i2c_clock_speed;
if (gpio_is_valid(platform_data->gpio)) {
ret = devm_gpio_request_one(&pdev->dev,
platform_data->gpio,
GPIOF_ACTIVE_LOW,
i2c->adap.name);
if (ret == 0) {
i2c->gpio = gpio_to_desc(platform_data->gpio);
gpiod_direction_output(i2c->gpio, 0);
} else {
dev_warn(&pdev->dev, "Registering gpio failed!\n");
i2c->gpio = NULL;
}
}
} else if (np) {
i2c->adap.timeout = HZ;
i2c->gpio = devm_gpiod_get_optional(&pdev->dev, "reset-gpios", GPIOD_OUT_LOW);
if (IS_ERR(i2c->gpio))
return PTR_ERR(i2c->gpio);
of_property_read_u32_index(np, "clock-frequency", 0,
&i2c->algo_data.i2c_clock);
} else {
i2c->adap.timeout = HZ;
i2c->algo_data.i2c_clock = 59000;
i2c->gpio = NULL;
}
i2c->algo_data.data = i2c;
i2c->algo_data.wait_for_completion = i2c_pca_pf_waitforcompletion;
if (i2c->gpio)
i2c->algo_data.reset_chip = i2c_pca_pf_resetchip;
else
i2c->algo_data.reset_chip = i2c_pca_pf_dummyreset;
switch (res->flags & IORESOURCE_MEM_TYPE_MASK) {
case IORESOURCE_MEM_32BIT:
i2c->algo_data.write_byte = i2c_pca_pf_writebyte32;
i2c->algo_data.read_byte = i2c_pca_pf_readbyte32;
break;
case IORESOURCE_MEM_16BIT:
i2c->algo_data.write_byte = i2c_pca_pf_writebyte16;
i2c->algo_data.read_byte = i2c_pca_pf_readbyte16;
break;
case IORESOURCE_MEM_8BIT:
default:
i2c->algo_data.write_byte = i2c_pca_pf_writebyte8;
i2c->algo_data.read_byte = i2c_pca_pf_readbyte8;
break;
}
if (irq) {
ret = devm_request_irq(&pdev->dev, irq, i2c_pca_pf_handler,
IRQF_TRIGGER_FALLING, pdev->name, i2c);
if (ret)
return ret;
}
ret = i2c_pca_add_numbered_bus(&i2c->adap);
if (ret)
return ret;
platform_set_drvdata(pdev, i2c);
dev_info(&pdev->dev, "registered.\n");
return 0;
}
static int i2c_pca_pf_remove(struct platform_device *pdev)
{
struct i2c_pca_pf_data *i2c = platform_get_drvdata(pdev);
i2c_del_adapter(&i2c->adap);
return 0;
}
