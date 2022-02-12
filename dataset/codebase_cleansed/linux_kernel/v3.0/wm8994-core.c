static int wm8994_read(struct wm8994 *wm8994, unsigned short reg,
int bytes, void *dest)
{
int ret, i;
u16 *buf = dest;
BUG_ON(bytes % 2);
BUG_ON(bytes <= 0);
ret = wm8994->read_dev(wm8994, reg, bytes, dest);
if (ret < 0)
return ret;
for (i = 0; i < bytes / 2; i++) {
dev_vdbg(wm8994->dev, "Read %04x from R%d(0x%x)\n",
be16_to_cpu(buf[i]), reg + i, reg + i);
}
return 0;
}
int wm8994_reg_read(struct wm8994 *wm8994, unsigned short reg)
{
unsigned short val;
int ret;
mutex_lock(&wm8994->io_lock);
ret = wm8994_read(wm8994, reg, 2, &val);
mutex_unlock(&wm8994->io_lock);
if (ret < 0)
return ret;
else
return be16_to_cpu(val);
}
int wm8994_bulk_read(struct wm8994 *wm8994, unsigned short reg,
int count, u16 *buf)
{
int ret;
mutex_lock(&wm8994->io_lock);
ret = wm8994_read(wm8994, reg, count * 2, buf);
mutex_unlock(&wm8994->io_lock);
return ret;
}
static int wm8994_write(struct wm8994 *wm8994, unsigned short reg,
int bytes, const void *src)
{
const u16 *buf = src;
int i;
BUG_ON(bytes % 2);
BUG_ON(bytes <= 0);
for (i = 0; i < bytes / 2; i++) {
dev_vdbg(wm8994->dev, "Write %04x to R%d(0x%x)\n",
be16_to_cpu(buf[i]), reg + i, reg + i);
}
return wm8994->write_dev(wm8994, reg, bytes, src);
}
int wm8994_reg_write(struct wm8994 *wm8994, unsigned short reg,
unsigned short val)
{
int ret;
val = cpu_to_be16(val);
mutex_lock(&wm8994->io_lock);
ret = wm8994_write(wm8994, reg, 2, &val);
mutex_unlock(&wm8994->io_lock);
return ret;
}
int wm8994_bulk_write(struct wm8994 *wm8994, unsigned short reg,
int count, const u16 *buf)
{
int ret;
mutex_lock(&wm8994->io_lock);
ret = wm8994_write(wm8994, reg, count * 2, buf);
mutex_unlock(&wm8994->io_lock);
return ret;
}
int wm8994_set_bits(struct wm8994 *wm8994, unsigned short reg,
unsigned short mask, unsigned short val)
{
int ret;
u16 r;
mutex_lock(&wm8994->io_lock);
ret = wm8994_read(wm8994, reg, 2, &r);
if (ret < 0)
goto out;
r = be16_to_cpu(r);
r &= ~mask;
r |= val;
r = cpu_to_be16(r);
ret = wm8994_write(wm8994, reg, 2, &r);
out:
mutex_unlock(&wm8994->io_lock);
return ret;
}
static int wm8994_suspend(struct device *dev)
{
struct wm8994 *wm8994 = dev_get_drvdata(dev);
int ret;
ret = wm8994_reg_read(wm8994, WM8994_POWER_MANAGEMENT_1);
if (ret < 0) {
dev_err(dev, "Failed to read power status: %d\n", ret);
} else if (ret & WM8994_VMID_SEL_MASK) {
dev_dbg(dev, "CODEC still active, ignoring suspend\n");
return 0;
}
ret = wm8994_read(wm8994, WM8994_GPIO_1, WM8994_NUM_GPIO_REGS * 2,
&wm8994->gpio_regs);
if (ret < 0)
dev_err(dev, "Failed to save GPIO registers: %d\n", ret);
ret = wm8994_read(wm8994, WM8994_LDO_1, WM8994_NUM_LDO_REGS * 2,
&wm8994->ldo_regs);
if (ret < 0)
dev_err(dev, "Failed to save LDO registers: %d\n", ret);
wm8994_reg_write(wm8994, WM8994_SOFTWARE_RESET, 0x8994);
wm8994->suspended = true;
ret = regulator_bulk_disable(wm8994->num_supplies,
wm8994->supplies);
if (ret != 0) {
dev_err(dev, "Failed to disable supplies: %d\n", ret);
return ret;
}
return 0;
}
static int wm8994_resume(struct device *dev)
{
struct wm8994 *wm8994 = dev_get_drvdata(dev);
int ret;
if (!wm8994->suspended)
return 0;
ret = regulator_bulk_enable(wm8994->num_supplies,
wm8994->supplies);
if (ret != 0) {
dev_err(dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
ret = wm8994_write(wm8994, WM8994_INTERRUPT_STATUS_1_MASK,
WM8994_NUM_IRQ_REGS * 2, &wm8994->irq_masks_cur);
if (ret < 0)
dev_err(dev, "Failed to restore interrupt masks: %d\n", ret);
ret = wm8994_write(wm8994, WM8994_LDO_1, WM8994_NUM_LDO_REGS * 2,
&wm8994->ldo_regs);
if (ret < 0)
dev_err(dev, "Failed to restore LDO registers: %d\n", ret);
ret = wm8994_write(wm8994, WM8994_GPIO_1, WM8994_NUM_GPIO_REGS * 2,
&wm8994->gpio_regs);
if (ret < 0)
dev_err(dev, "Failed to restore GPIO registers: %d\n", ret);
wm8994->suspended = false;
return 0;
}
static int wm8994_ldo_in_use(struct wm8994_pdata *pdata, int ldo)
{
struct wm8994_ldo_pdata *ldo_pdata;
if (!pdata)
return 0;
ldo_pdata = &pdata->ldo[ldo];
if (!ldo_pdata->init_data)
return 0;
return ldo_pdata->init_data->num_consumer_supplies != 0;
}
static int wm8994_ldo_in_use(struct wm8994_pdata *pdata, int ldo)
{
return 0;
}
static int wm8994_device_init(struct wm8994 *wm8994, int irq)
{
struct wm8994_pdata *pdata = wm8994->dev->platform_data;
const char *devname;
int ret, i;
mutex_init(&wm8994->io_lock);
dev_set_drvdata(wm8994->dev, wm8994);
ret = mfd_add_devices(wm8994->dev, -1,
wm8994_regulator_devs,
ARRAY_SIZE(wm8994_regulator_devs),
NULL, 0);
if (ret != 0) {
dev_err(wm8994->dev, "Failed to add children: %d\n", ret);
goto err;
}
switch (wm8994->type) {
case WM8994:
wm8994->num_supplies = ARRAY_SIZE(wm8994_main_supplies);
break;
case WM8958:
wm8994->num_supplies = ARRAY_SIZE(wm8958_main_supplies);
break;
default:
BUG();
return -EINVAL;
}
wm8994->supplies = kzalloc(sizeof(struct regulator_bulk_data) *
wm8994->num_supplies,
GFP_KERNEL);
if (!wm8994->supplies) {
ret = -ENOMEM;
goto err;
}
switch (wm8994->type) {
case WM8994:
for (i = 0; i < ARRAY_SIZE(wm8994_main_supplies); i++)
wm8994->supplies[i].supply = wm8994_main_supplies[i];
break;
case WM8958:
for (i = 0; i < ARRAY_SIZE(wm8958_main_supplies); i++)
wm8994->supplies[i].supply = wm8958_main_supplies[i];
break;
default:
BUG();
return -EINVAL;
}
ret = regulator_bulk_get(wm8994->dev, wm8994->num_supplies,
wm8994->supplies);
if (ret != 0) {
dev_err(wm8994->dev, "Failed to get supplies: %d\n", ret);
goto err_supplies;
}
ret = regulator_bulk_enable(wm8994->num_supplies,
wm8994->supplies);
if (ret != 0) {
dev_err(wm8994->dev, "Failed to enable supplies: %d\n", ret);
goto err_get;
}
ret = wm8994_reg_read(wm8994, WM8994_SOFTWARE_RESET);
if (ret < 0) {
dev_err(wm8994->dev, "Failed to read ID register\n");
goto err_enable;
}
switch (ret) {
case 0x8994:
devname = "WM8994";
if (wm8994->type != WM8994)
dev_warn(wm8994->dev, "Device registered as type %d\n",
wm8994->type);
wm8994->type = WM8994;
break;
case 0x8958:
devname = "WM8958";
if (wm8994->type != WM8958)
dev_warn(wm8994->dev, "Device registered as type %d\n",
wm8994->type);
wm8994->type = WM8958;
break;
default:
dev_err(wm8994->dev, "Device is not a WM8994, ID is %x\n",
ret);
ret = -EINVAL;
goto err_enable;
}
ret = wm8994_reg_read(wm8994, WM8994_CHIP_REVISION);
if (ret < 0) {
dev_err(wm8994->dev, "Failed to read revision register: %d\n",
ret);
goto err_enable;
}
switch (ret) {
case 0:
case 1:
if (wm8994->type == WM8994)
dev_warn(wm8994->dev,
"revision %c not fully supported\n",
'A' + ret);
break;
default:
break;
}
dev_info(wm8994->dev, "%s revision %c\n", devname, 'A' + ret);
if (pdata) {
wm8994->irq_base = pdata->irq_base;
wm8994->gpio_base = pdata->gpio_base;
for (i = 0; i < ARRAY_SIZE(pdata->gpio_defaults); i++) {
if (pdata->gpio_defaults[i]) {
wm8994_set_bits(wm8994, WM8994_GPIO_1 + i,
0xffff,
pdata->gpio_defaults[i]);
}
}
}
for (i = 0; i < WM8994_NUM_LDO_REGS; i++) {
if (wm8994_ldo_in_use(pdata, i))
wm8994_set_bits(wm8994, WM8994_LDO_1 + i,
WM8994_LDO1_DISCH, WM8994_LDO1_DISCH);
else
wm8994_set_bits(wm8994, WM8994_LDO_1 + i,
WM8994_LDO1_DISCH, 0);
}
wm8994_irq_init(wm8994);
ret = mfd_add_devices(wm8994->dev, -1,
wm8994_devs, ARRAY_SIZE(wm8994_devs),
NULL, 0);
if (ret != 0) {
dev_err(wm8994->dev, "Failed to add children: %d\n", ret);
goto err_irq;
}
pm_runtime_enable(wm8994->dev);
pm_runtime_resume(wm8994->dev);
return 0;
err_irq:
wm8994_irq_exit(wm8994);
err_enable:
regulator_bulk_disable(wm8994->num_supplies,
wm8994->supplies);
err_get:
regulator_bulk_free(wm8994->num_supplies, wm8994->supplies);
err_supplies:
kfree(wm8994->supplies);
err:
mfd_remove_devices(wm8994->dev);
kfree(wm8994);
return ret;
}
static void wm8994_device_exit(struct wm8994 *wm8994)
{
pm_runtime_disable(wm8994->dev);
mfd_remove_devices(wm8994->dev);
wm8994_irq_exit(wm8994);
regulator_bulk_disable(wm8994->num_supplies,
wm8994->supplies);
regulator_bulk_free(wm8994->num_supplies, wm8994->supplies);
kfree(wm8994->supplies);
kfree(wm8994);
}
static int wm8994_i2c_read_device(struct wm8994 *wm8994, unsigned short reg,
int bytes, void *dest)
{
struct i2c_client *i2c = wm8994->control_data;
int ret;
u16 r = cpu_to_be16(reg);
ret = i2c_master_send(i2c, (unsigned char *)&r, 2);
if (ret < 0)
return ret;
if (ret != 2)
return -EIO;
ret = i2c_master_recv(i2c, dest, bytes);
if (ret < 0)
return ret;
if (ret != bytes)
return -EIO;
return 0;
}
static int wm8994_i2c_write_device(struct wm8994 *wm8994, unsigned short reg,
int bytes, const void *src)
{
struct i2c_client *i2c = wm8994->control_data;
struct i2c_msg xfer[2];
int ret;
reg = cpu_to_be16(reg);
xfer[0].addr = i2c->addr;
xfer[0].flags = 0;
xfer[0].len = 2;
xfer[0].buf = (char *)&reg;
xfer[1].addr = i2c->addr;
xfer[1].flags = I2C_M_NOSTART;
xfer[1].len = bytes;
xfer[1].buf = (char *)src;
ret = i2c_transfer(i2c->adapter, xfer, 2);
if (ret < 0)
return ret;
if (ret != 2)
return -EIO;
return 0;
}
static int wm8994_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8994 *wm8994;
wm8994 = kzalloc(sizeof(struct wm8994), GFP_KERNEL);
if (wm8994 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8994);
wm8994->dev = &i2c->dev;
wm8994->control_data = i2c;
wm8994->read_dev = wm8994_i2c_read_device;
wm8994->write_dev = wm8994_i2c_write_device;
wm8994->irq = i2c->irq;
wm8994->type = id->driver_data;
return wm8994_device_init(wm8994, i2c->irq);
}
static int wm8994_i2c_remove(struct i2c_client *i2c)
{
struct wm8994 *wm8994 = i2c_get_clientdata(i2c);
wm8994_device_exit(wm8994);
return 0;
}
static int __init wm8994_i2c_init(void)
{
int ret;
ret = i2c_add_driver(&wm8994_i2c_driver);
if (ret != 0)
pr_err("Failed to register wm8994 I2C driver: %d\n", ret);
return ret;
}
static void __exit wm8994_i2c_exit(void)
{
i2c_del_driver(&wm8994_i2c_driver);
}
