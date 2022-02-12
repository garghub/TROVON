static inline struct sch311x_gpio_block *
to_sch311x_gpio_block(struct gpio_chip *chip)
{
return container_of(chip, struct sch311x_gpio_block, chip);
}
static inline int sch311x_sio_enter(int sio_config_port)
{
if (!request_muxed_region(sio_config_port, 2, DRV_NAME)) {
pr_err(DRV_NAME "I/O address 0x%04x already in use\n",
sio_config_port);
return -EBUSY;
}
outb(SIO_CONFIG_KEY_ENTER, sio_config_port);
return 0;
}
static inline void sch311x_sio_exit(int sio_config_port)
{
outb(SIO_CONFIG_KEY_EXIT, sio_config_port);
release_region(sio_config_port, 2);
}
static inline int sch311x_sio_inb(int sio_config_port, int reg)
{
outb(reg, sio_config_port);
return inb(sio_config_port + 1);
}
static inline void sch311x_sio_outb(int sio_config_port, int reg, int val)
{
outb(reg, sio_config_port);
outb(val, sio_config_port + 1);
}
static int sch311x_gpio_request(struct gpio_chip *chip, unsigned offset)
{
struct sch311x_gpio_block *block = to_sch311x_gpio_block(chip);
if (block->config_regs[offset] == 0)
return -ENODEV;
if (!request_region(block->runtime_reg + block->config_regs[offset],
1, DRV_NAME)) {
dev_err(chip->dev, "Failed to request region 0x%04x.\n",
block->runtime_reg + block->config_regs[offset]);
return -EBUSY;
}
return 0;
}
static void sch311x_gpio_free(struct gpio_chip *chip, unsigned offset)
{
struct sch311x_gpio_block *block = to_sch311x_gpio_block(chip);
if (block->config_regs[offset] == 0)
return;
release_region(block->runtime_reg + block->config_regs[offset], 1);
}
static int sch311x_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct sch311x_gpio_block *block = to_sch311x_gpio_block(chip);
unsigned char data;
spin_lock(&block->lock);
data = inb(block->runtime_reg + block->data_reg);
spin_unlock(&block->lock);
return !!(data & BIT(offset));
}
static void __sch311x_gpio_set(struct sch311x_gpio_block *block,
unsigned offset, int value)
{
unsigned char data = inb(block->runtime_reg + block->data_reg);
if (value)
data |= BIT(offset);
else
data &= ~BIT(offset);
outb(data, block->runtime_reg + block->data_reg);
}
static void sch311x_gpio_set(struct gpio_chip *chip, unsigned offset,
int value)
{
struct sch311x_gpio_block *block = to_sch311x_gpio_block(chip);
spin_lock(&block->lock);
__sch311x_gpio_set(block, offset, value);
spin_unlock(&block->lock);
}
static int sch311x_gpio_direction_in(struct gpio_chip *chip, unsigned offset)
{
struct sch311x_gpio_block *block = to_sch311x_gpio_block(chip);
spin_lock(&block->lock);
outb(SCH311X_GPIO_CONF_IN, block->runtime_reg +
block->config_regs[offset]);
spin_unlock(&block->lock);
return 0;
}
static int sch311x_gpio_direction_out(struct gpio_chip *chip, unsigned offset,
int value)
{
struct sch311x_gpio_block *block = to_sch311x_gpio_block(chip);
spin_lock(&block->lock);
outb(SCH311X_GPIO_CONF_OUT, block->runtime_reg +
block->config_regs[offset]);
__sch311x_gpio_set(block, offset, value);
spin_unlock(&block->lock);
return 0;
}
static int sch311x_gpio_probe(struct platform_device *pdev)
{
struct sch311x_pdev_data *pdata = pdev->dev.platform_data;
struct sch311x_gpio_priv *priv;
struct sch311x_gpio_block *block;
int err, i;
if (!request_region(pdata->runtime_reg + GP1, 6, DRV_NAME)) {
dev_err(&pdev->dev, "Failed to request region 0x%04x-0x%04x.\n",
pdata->runtime_reg + GP1, pdata->runtime_reg + GP1 + 5);
return -EBUSY;
}
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
platform_set_drvdata(pdev, priv);
for (i = 0; i < ARRAY_SIZE(priv->blocks); i++) {
block = &priv->blocks[i];
spin_lock_init(&block->lock);
block->chip.label = DRV_NAME;
block->chip.owner = THIS_MODULE;
block->chip.request = sch311x_gpio_request;
block->chip.free = sch311x_gpio_free;
block->chip.direction_input = sch311x_gpio_direction_in;
block->chip.direction_output = sch311x_gpio_direction_out;
block->chip.get = sch311x_gpio_get;
block->chip.set = sch311x_gpio_set;
block->chip.ngpio = 8;
block->chip.dev = &pdev->dev;
block->chip.base = sch311x_gpio_blocks[i].base;
block->config_regs = sch311x_gpio_blocks[i].config_regs;
block->data_reg = sch311x_gpio_blocks[i].data_reg;
block->runtime_reg = pdata->runtime_reg;
err = gpiochip_add(&block->chip);
if (err < 0) {
dev_err(&pdev->dev,
"Could not register gpiochip, %d\n", err);
goto exit_err;
}
dev_info(&pdev->dev,
"SMSC SCH311x GPIO block %d registered.\n", i);
}
return 0;
exit_err:
release_region(pdata->runtime_reg + GP1, 6);
for (--i; i >= 0; i--)
gpiochip_remove(&priv->blocks[i].chip);
return err;
}
static int sch311x_gpio_remove(struct platform_device *pdev)
{
struct sch311x_pdev_data *pdata = pdev->dev.platform_data;
struct sch311x_gpio_priv *priv = platform_get_drvdata(pdev);
int err, i;
release_region(pdata->runtime_reg + GP1, 6);
for (i = 0; i < ARRAY_SIZE(priv->blocks); i++) {
err = gpiochip_remove(&priv->blocks[i].chip);
if (err)
return err;
dev_info(&pdev->dev,
"SMSC SCH311x GPIO block %d unregistered.\n", i);
}
return 0;
}
static int __init sch311x_detect(int sio_config_port, unsigned short *addr)
{
int err = 0, reg;
unsigned short base_addr;
unsigned char dev_id;
err = sch311x_sio_enter(sio_config_port);
if (err)
return err;
reg = sch311x_sio_inb(sio_config_port, 0x20);
switch (reg) {
case 0x7c:
dev_id = 2;
break;
case 0x7d:
dev_id = 4;
break;
case 0x7f:
dev_id = 6;
break;
default:
err = -ENODEV;
goto exit;
}
sch311x_sio_outb(sio_config_port, 0x07, 0x0a);
if ((sch311x_sio_inb(sio_config_port, 0x30) & 0x01) == 0)
pr_info("Seems that LDN 0x0a is not active...\n");
base_addr = (sch311x_sio_inb(sio_config_port, 0x60) << 8) |
sch311x_sio_inb(sio_config_port, 0x61);
if (!base_addr) {
pr_err("Base address not set\n");
err = -ENODEV;
goto exit;
}
*addr = base_addr;
pr_info("Found an SMSC SCH311%d chip at 0x%04x\n", dev_id, base_addr);
exit:
sch311x_sio_exit(sio_config_port);
return err;
}
static int __init sch311x_gpio_pdev_add(const unsigned short addr)
{
struct sch311x_pdev_data pdata;
int err;
pdata.runtime_reg = addr;
sch311x_gpio_pdev = platform_device_alloc(DRV_NAME, -1);
if (!sch311x_gpio_pdev)
return -ENOMEM;
err = platform_device_add_data(sch311x_gpio_pdev,
&pdata, sizeof(pdata));
if (err) {
pr_err(DRV_NAME "Platform data allocation failed\n");
goto err;
}
err = platform_device_add(sch311x_gpio_pdev);
if (err) {
pr_err(DRV_NAME "Device addition failed\n");
goto err;
}
return 0;
err:
platform_device_put(sch311x_gpio_pdev);
return err;
}
static int __init sch311x_gpio_init(void)
{
int err, i;
unsigned short addr = 0;
for (i = 0; i < ARRAY_SIZE(sch311x_ioports); i++)
if (sch311x_detect(sch311x_ioports[i], &addr) == 0)
break;
if (!addr)
return -ENODEV;
err = platform_driver_register(&sch311x_gpio_driver);
if (err)
return err;
err = sch311x_gpio_pdev_add(addr);
if (err)
goto unreg_platform_driver;
return 0;
unreg_platform_driver:
platform_driver_unregister(&sch311x_gpio_driver);
return err;
}
static void __exit sch311x_gpio_exit(void)
{
platform_device_unregister(sch311x_gpio_pdev);
platform_driver_unregister(&sch311x_gpio_driver);
}
