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
printk(KERN_WARNING "%s: No reset-pin found. Chip may get stuck!\n",
i2c->adap.name);
}
static void i2c_pca_pf_resetchip(void *pd)
{
struct i2c_pca_pf_data *i2c = pd;
gpio_set_value(i2c->gpio, 0);
ndelay(100);
gpio_set_value(i2c->gpio, 1);
}
static irqreturn_t i2c_pca_pf_handler(int this_irq, void *dev_id)
{
struct i2c_pca_pf_data *i2c = dev_id;
if ((i2c->algo_data.read_byte(i2c, I2C_PCA_CON) & I2C_PCA_CON_SI) == 0)
return IRQ_NONE;
wake_up(&i2c->wait);
return IRQ_HANDLED;
}
static int __devinit i2c_pca_pf_probe(struct platform_device *pdev)
{
struct i2c_pca_pf_data *i2c;
struct resource *res;
struct i2c_pca9564_pf_platform_data *platform_data =
pdev->dev.platform_data;
int ret = 0;
int irq;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (res == NULL) {
ret = -ENODEV;
goto e_print;
}
if (!request_mem_region(res->start, resource_size(res), res->name)) {
ret = -ENOMEM;
goto e_print;
}
i2c = kzalloc(sizeof(struct i2c_pca_pf_data), GFP_KERNEL);
if (!i2c) {
ret = -ENOMEM;
goto e_alloc;
}
init_waitqueue_head(&i2c->wait);
i2c->reg_base = ioremap(res->start, resource_size(res));
if (!i2c->reg_base) {
ret = -ENOMEM;
goto e_remap;
}
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
if (platform_data) {
i2c->adap.timeout = platform_data->timeout;
i2c->algo_data.i2c_clock = platform_data->i2c_clock_speed;
i2c->gpio = platform_data->gpio;
} else {
i2c->adap.timeout = HZ;
i2c->algo_data.i2c_clock = 59000;
i2c->gpio = -1;
}
i2c->algo_data.data = i2c;
i2c->algo_data.wait_for_completion = i2c_pca_pf_waitforcompletion;
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
if (i2c->gpio > -1) {
ret = gpio_request(i2c->gpio, i2c->adap.name);
if (ret == 0) {
gpio_direction_output(i2c->gpio, 1);
i2c->algo_data.reset_chip = i2c_pca_pf_resetchip;
} else {
printk(KERN_WARNING "%s: Registering gpio failed!\n",
i2c->adap.name);
i2c->gpio = ret;
}
}
if (irq) {
ret = request_irq(irq, i2c_pca_pf_handler,
IRQF_TRIGGER_FALLING, pdev->name, i2c);
if (ret)
goto e_reqirq;
}
if (i2c_pca_add_numbered_bus(&i2c->adap) < 0) {
ret = -ENODEV;
goto e_adapt;
}
platform_set_drvdata(pdev, i2c);
printk(KERN_INFO "%s registered.\n", i2c->adap.name);
return 0;
e_adapt:
if (irq)
free_irq(irq, i2c);
e_reqirq:
if (i2c->gpio > -1)
gpio_free(i2c->gpio);
iounmap(i2c->reg_base);
e_remap:
kfree(i2c);
e_alloc:
release_mem_region(res->start, resource_size(res));
e_print:
printk(KERN_ERR "Registering PCA9564/PCA9665 FAILED! (%d)\n", ret);
return ret;
}
static int __devexit i2c_pca_pf_remove(struct platform_device *pdev)
{
struct i2c_pca_pf_data *i2c = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
i2c_del_adapter(&i2c->adap);
if (i2c->irq)
free_irq(i2c->irq, i2c);
if (i2c->gpio > -1)
gpio_free(i2c->gpio);
iounmap(i2c->reg_base);
release_mem_region(i2c->io_base, i2c->io_size);
kfree(i2c);
return 0;
}
