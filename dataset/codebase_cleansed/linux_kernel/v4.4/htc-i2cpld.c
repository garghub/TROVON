static void htcpld_mask(struct irq_data *data)
{
struct htcpld_chip *chip = irq_data_get_irq_chip_data(data);
chip->irqs_enabled &= ~(1 << (data->irq - chip->irq_start));
pr_debug("HTCPLD mask %d %04x\n", data->irq, chip->irqs_enabled);
}
static void htcpld_unmask(struct irq_data *data)
{
struct htcpld_chip *chip = irq_data_get_irq_chip_data(data);
chip->irqs_enabled |= 1 << (data->irq - chip->irq_start);
pr_debug("HTCPLD unmask %d %04x\n", data->irq, chip->irqs_enabled);
}
static int htcpld_set_type(struct irq_data *data, unsigned int flags)
{
struct htcpld_chip *chip = irq_data_get_irq_chip_data(data);
if (flags & ~IRQ_TYPE_SENSE_MASK)
return -EINVAL;
if (flags & (IRQ_TYPE_LEVEL_LOW|IRQ_TYPE_LEVEL_HIGH))
return -EINVAL;
chip->flow_type = flags;
return 0;
}
static irqreturn_t htcpld_handler(int irq, void *dev)
{
struct htcpld_data *htcpld = dev;
unsigned int i;
unsigned long flags;
int irqpin;
if (!htcpld) {
pr_debug("htcpld is null in ISR\n");
return IRQ_HANDLED;
}
for (i = 0; i < htcpld->nchips; i++) {
struct htcpld_chip *chip = &htcpld->chip[i];
struct i2c_client *client;
int val;
unsigned long uval, old_val;
if (!chip) {
pr_debug("chip %d is null in ISR\n", i);
continue;
}
if (chip->nirqs == 0)
continue;
client = chip->client;
if (!client) {
pr_debug("client %d is null in ISR\n", i);
continue;
}
val = i2c_smbus_read_byte_data(client, chip->cache_out);
if (val < 0) {
dev_warn(chip->dev, "Unable to read from chip: %d\n",
val);
continue;
}
uval = (unsigned long)val;
spin_lock_irqsave(&chip->lock, flags);
old_val = chip->cache_in;
chip->cache_in = uval;
spin_unlock_irqrestore(&chip->lock, flags);
for (irqpin = 0; irqpin < chip->nirqs; irqpin++) {
unsigned oldb, newb, type = chip->flow_type;
irq = chip->irq_start + irqpin;
oldb = (old_val >> irqpin) & 1;
newb = (uval >> irqpin) & 1;
if ((!oldb && newb && (type & IRQ_TYPE_EDGE_RISING)) ||
(oldb && !newb && (type & IRQ_TYPE_EDGE_FALLING))) {
pr_debug("fire IRQ %d\n", irqpin);
generic_handle_irq(irq);
}
}
}
if (htcpld->int_reset_gpio_hi)
gpio_set_value(htcpld->int_reset_gpio_hi, 1);
if (htcpld->int_reset_gpio_lo)
gpio_set_value(htcpld->int_reset_gpio_lo, 0);
return IRQ_HANDLED;
}
static void htcpld_chip_set(struct gpio_chip *chip, unsigned offset, int val)
{
struct i2c_client *client;
struct htcpld_chip *chip_data =
container_of(chip, struct htcpld_chip, chip_out);
unsigned long flags;
client = chip_data->client;
if (!client)
return;
spin_lock_irqsave(&chip_data->lock, flags);
if (val)
chip_data->cache_out |= (1 << offset);
else
chip_data->cache_out &= ~(1 << offset);
spin_unlock_irqrestore(&chip_data->lock, flags);
schedule_work(&(chip_data->set_val_work));
}
static void htcpld_chip_set_ni(struct work_struct *work)
{
struct htcpld_chip *chip_data;
struct i2c_client *client;
chip_data = container_of(work, struct htcpld_chip, set_val_work);
client = chip_data->client;
i2c_smbus_read_byte_data(client, chip_data->cache_out);
}
static int htcpld_chip_get(struct gpio_chip *chip, unsigned offset)
{
struct htcpld_chip *chip_data;
u8 cache;
if (!strncmp(chip->label, "htcpld-out", 10)) {
chip_data = container_of(chip, struct htcpld_chip, chip_out);
cache = chip_data->cache_out;
} else if (!strncmp(chip->label, "htcpld-in", 9)) {
chip_data = container_of(chip, struct htcpld_chip, chip_in);
cache = chip_data->cache_in;
} else
return -EINVAL;
return (cache >> offset) & 1;
}
static int htcpld_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
htcpld_chip_set(chip, offset, value);
return 0;
}
static int htcpld_direction_input(struct gpio_chip *chip,
unsigned offset)
{
return (offset < chip->ngpio) ? 0 : -EINVAL;
}
static int htcpld_chip_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct htcpld_chip *chip_data;
chip_data = container_of(chip, struct htcpld_chip, chip_in);
if (offset < chip_data->nirqs)
return chip_data->irq_start + offset;
else
return -EINVAL;
}
static void htcpld_chip_reset(struct i2c_client *client)
{
struct htcpld_chip *chip_data = i2c_get_clientdata(client);
if (!chip_data)
return;
i2c_smbus_read_byte_data(
client, (chip_data->cache_out = chip_data->reset));
}
static int htcpld_setup_chip_irq(
struct platform_device *pdev,
int chip_index)
{
struct htcpld_data *htcpld;
struct htcpld_chip *chip;
unsigned int irq, irq_end;
htcpld = platform_get_drvdata(pdev);
chip = &htcpld->chip[chip_index];
irq_end = chip->irq_start + chip->nirqs;
for (irq = chip->irq_start; irq < irq_end; irq++) {
irq_set_chip_and_handler(irq, &htcpld_muxed_chip,
handle_simple_irq);
irq_set_chip_data(irq, chip);
irq_clear_status_flags(irq, IRQ_NOREQUEST | IRQ_NOPROBE);
}
return 0;
}
static int htcpld_register_chip_i2c(
struct platform_device *pdev,
int chip_index)
{
struct htcpld_data *htcpld;
struct device *dev = &pdev->dev;
struct htcpld_core_platform_data *pdata;
struct htcpld_chip *chip;
struct htcpld_chip_platform_data *plat_chip_data;
struct i2c_adapter *adapter;
struct i2c_client *client;
struct i2c_board_info info;
pdata = dev_get_platdata(dev);
htcpld = platform_get_drvdata(pdev);
chip = &htcpld->chip[chip_index];
plat_chip_data = &pdata->chip[chip_index];
adapter = i2c_get_adapter(pdata->i2c_adapter_id);
if (!adapter) {
dev_warn(dev, "Chip at i2c address 0x%x: Invalid i2c adapter %d\n",
plat_chip_data->addr, pdata->i2c_adapter_id);
return -ENODEV;
}
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_READ_BYTE_DATA)) {
dev_warn(dev, "i2c adapter %d non-functional\n",
pdata->i2c_adapter_id);
return -EINVAL;
}
memset(&info, 0, sizeof(struct i2c_board_info));
info.addr = plat_chip_data->addr;
strlcpy(info.type, "htcpld-chip", I2C_NAME_SIZE);
info.platform_data = chip;
client = i2c_new_device(adapter, &info);
if (!client) {
dev_warn(dev, "Unable to add I2C device for 0x%x\n",
plat_chip_data->addr);
return -ENODEV;
}
i2c_set_clientdata(client, chip);
snprintf(client->name, I2C_NAME_SIZE, "Chip_0x%x", client->addr);
chip->client = client;
htcpld_chip_reset(client);
chip->cache_in = i2c_smbus_read_byte_data(client, chip->cache_out);
return 0;
}
static void htcpld_unregister_chip_i2c(
struct platform_device *pdev,
int chip_index)
{
struct htcpld_data *htcpld;
struct htcpld_chip *chip;
htcpld = platform_get_drvdata(pdev);
chip = &htcpld->chip[chip_index];
if (chip->client)
i2c_unregister_device(chip->client);
}
static int htcpld_register_chip_gpio(
struct platform_device *pdev,
int chip_index)
{
struct htcpld_data *htcpld;
struct device *dev = &pdev->dev;
struct htcpld_core_platform_data *pdata;
struct htcpld_chip *chip;
struct htcpld_chip_platform_data *plat_chip_data;
struct gpio_chip *gpio_chip;
int ret = 0;
pdata = dev_get_platdata(dev);
htcpld = platform_get_drvdata(pdev);
chip = &htcpld->chip[chip_index];
plat_chip_data = &pdata->chip[chip_index];
gpio_chip = &(chip->chip_out);
gpio_chip->label = "htcpld-out";
gpio_chip->dev = dev;
gpio_chip->owner = THIS_MODULE;
gpio_chip->get = htcpld_chip_get;
gpio_chip->set = htcpld_chip_set;
gpio_chip->direction_input = NULL;
gpio_chip->direction_output = htcpld_direction_output;
gpio_chip->base = plat_chip_data->gpio_out_base;
gpio_chip->ngpio = plat_chip_data->num_gpios;
gpio_chip = &(chip->chip_in);
gpio_chip->label = "htcpld-in";
gpio_chip->dev = dev;
gpio_chip->owner = THIS_MODULE;
gpio_chip->get = htcpld_chip_get;
gpio_chip->set = NULL;
gpio_chip->direction_input = htcpld_direction_input;
gpio_chip->direction_output = NULL;
gpio_chip->to_irq = htcpld_chip_to_irq;
gpio_chip->base = plat_chip_data->gpio_in_base;
gpio_chip->ngpio = plat_chip_data->num_gpios;
ret = gpiochip_add(&(chip->chip_out));
if (ret) {
dev_warn(dev, "Unable to register output GPIOs for 0x%x: %d\n",
plat_chip_data->addr, ret);
return ret;
}
ret = gpiochip_add(&(chip->chip_in));
if (ret) {
dev_warn(dev, "Unable to register input GPIOs for 0x%x: %d\n",
plat_chip_data->addr, ret);
gpiochip_remove(&(chip->chip_out));
return ret;
}
return 0;
}
static int htcpld_setup_chips(struct platform_device *pdev)
{
struct htcpld_data *htcpld;
struct device *dev = &pdev->dev;
struct htcpld_core_platform_data *pdata;
int i;
pdata = dev_get_platdata(dev);
htcpld = platform_get_drvdata(pdev);
htcpld->nchips = pdata->num_chip;
htcpld->chip = devm_kzalloc(dev, sizeof(struct htcpld_chip) * htcpld->nchips,
GFP_KERNEL);
if (!htcpld->chip) {
dev_warn(dev, "Unable to allocate memory for chips\n");
return -ENOMEM;
}
for (i = 0; i < htcpld->nchips; i++) {
int ret;
htcpld->chip[i].reset = pdata->chip[i].reset;
htcpld->chip[i].cache_out = pdata->chip[i].reset;
htcpld->chip[i].cache_in = 0;
htcpld->chip[i].dev = dev;
htcpld->chip[i].irq_start = pdata->chip[i].irq_base;
htcpld->chip[i].nirqs = pdata->chip[i].num_irqs;
INIT_WORK(&(htcpld->chip[i].set_val_work), &htcpld_chip_set_ni);
spin_lock_init(&(htcpld->chip[i].lock));
if (htcpld->chained_irq) {
ret = htcpld_setup_chip_irq(pdev, i);
if (ret)
continue;
}
ret = htcpld_register_chip_i2c(pdev, i);
if (ret)
continue;
ret = htcpld_register_chip_gpio(pdev, i);
if (ret) {
htcpld_unregister_chip_i2c(pdev, i);
continue;
}
dev_info(dev, "Registered chip at 0x%x\n", pdata->chip[i].addr);
}
return 0;
}
static int htcpld_core_probe(struct platform_device *pdev)
{
struct htcpld_data *htcpld;
struct device *dev = &pdev->dev;
struct htcpld_core_platform_data *pdata;
struct resource *res;
int ret = 0;
if (!dev)
return -ENODEV;
pdata = dev_get_platdata(dev);
if (!pdata) {
dev_warn(dev, "Platform data not found for htcpld core!\n");
return -ENXIO;
}
htcpld = devm_kzalloc(dev, sizeof(struct htcpld_data), GFP_KERNEL);
if (!htcpld)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (res) {
int flags;
htcpld->chained_irq = res->start;
flags = IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING |
IRQF_ONESHOT;
ret = request_threaded_irq(htcpld->chained_irq,
NULL, htcpld_handler,
flags, pdev->name, htcpld);
if (ret) {
dev_warn(dev, "Unable to setup chained irq handler: %d\n", ret);
return ret;
} else
device_init_wakeup(dev, 0);
}
platform_set_drvdata(pdev, htcpld);
ret = htcpld_setup_chips(pdev);
if (ret)
return ret;
if (pdata->int_reset_gpio_hi) {
ret = gpio_request(pdata->int_reset_gpio_hi, "htcpld-core");
if (ret) {
dev_warn(dev, "Unable to request int_reset_gpio_hi -- interrupts may not work\n");
htcpld->int_reset_gpio_hi = 0;
} else {
htcpld->int_reset_gpio_hi = pdata->int_reset_gpio_hi;
gpio_set_value(htcpld->int_reset_gpio_hi, 1);
}
}
if (pdata->int_reset_gpio_lo) {
ret = gpio_request(pdata->int_reset_gpio_lo, "htcpld-core");
if (ret) {
dev_warn(dev, "Unable to request int_reset_gpio_lo -- interrupts may not work\n");
htcpld->int_reset_gpio_lo = 0;
} else {
htcpld->int_reset_gpio_lo = pdata->int_reset_gpio_lo;
gpio_set_value(htcpld->int_reset_gpio_lo, 0);
}
}
dev_info(dev, "Initialized successfully\n");
return 0;
}
static int __init htcpld_core_init(void)
{
int ret;
ret = i2c_add_driver(&htcpld_chip_driver);
if (ret)
return ret;
return platform_driver_probe(&htcpld_core_driver, htcpld_core_probe);
}
static void __exit htcpld_core_exit(void)
{
i2c_del_driver(&htcpld_chip_driver);
platform_driver_unregister(&htcpld_core_driver);
}
