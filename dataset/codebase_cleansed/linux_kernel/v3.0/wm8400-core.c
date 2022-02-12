static int wm8400_read(struct wm8400 *wm8400, u8 reg, int num_regs, u16 *dest)
{
int i, ret = 0;
BUG_ON(reg + num_regs > ARRAY_SIZE(wm8400->reg_cache));
for (i = reg; i < reg + num_regs; i++)
if (reg_data[i].vol) {
ret = wm8400->read_dev(wm8400->io_data, reg,
num_regs, dest);
if (ret != 0)
return ret;
for (i = 0; i < num_regs; i++)
dest[i] = be16_to_cpu(dest[i]);
return 0;
}
memcpy(dest, &wm8400->reg_cache[reg], num_regs * sizeof(u16));
return 0;
}
static int wm8400_write(struct wm8400 *wm8400, u8 reg, int num_regs,
u16 *src)
{
int ret, i;
BUG_ON(reg + num_regs > ARRAY_SIZE(wm8400->reg_cache));
for (i = 0; i < num_regs; i++) {
BUG_ON(!reg_data[reg + i].writable);
wm8400->reg_cache[reg + i] = src[i];
src[i] = cpu_to_be16(src[i]);
}
ret = wm8400->write_dev(wm8400->io_data, reg, num_regs, src);
if (ret != 0)
return -EIO;
return 0;
}
u16 wm8400_reg_read(struct wm8400 *wm8400, u8 reg)
{
u16 val;
mutex_lock(&wm8400->io_lock);
wm8400_read(wm8400, reg, 1, &val);
mutex_unlock(&wm8400->io_lock);
return val;
}
int wm8400_block_read(struct wm8400 *wm8400, u8 reg, int count, u16 *data)
{
int ret;
mutex_lock(&wm8400->io_lock);
ret = wm8400_read(wm8400, reg, count, data);
mutex_unlock(&wm8400->io_lock);
return ret;
}
int wm8400_set_bits(struct wm8400 *wm8400, u8 reg, u16 mask, u16 val)
{
u16 tmp;
int ret;
mutex_lock(&wm8400->io_lock);
ret = wm8400_read(wm8400, reg, 1, &tmp);
tmp = (tmp & ~mask) | val;
if (ret == 0)
ret = wm8400_write(wm8400, reg, 1, &tmp);
mutex_unlock(&wm8400->io_lock);
return ret;
}
void wm8400_reset_codec_reg_cache(struct wm8400 *wm8400)
{
int i;
mutex_lock(&wm8400->io_lock);
for (i = 0; i < ARRAY_SIZE(wm8400->reg_cache); i++)
if (reg_data[i].is_codec)
wm8400->reg_cache[i] = reg_data[i].default_val;
mutex_unlock(&wm8400->io_lock);
}
static int wm8400_register_codec(struct wm8400 *wm8400)
{
struct mfd_cell cell = {
.name = "wm8400-codec",
.platform_data = wm8400,
.pdata_size = sizeof(*wm8400),
};
return mfd_add_devices(wm8400->dev, -1, &cell, 1, NULL, 0);
}
static int wm8400_init(struct wm8400 *wm8400,
struct wm8400_platform_data *pdata)
{
u16 reg;
int ret, i;
mutex_init(&wm8400->io_lock);
dev_set_drvdata(wm8400->dev, wm8400);
ret = wm8400->read_dev(wm8400->io_data, WM8400_RESET_ID, 1, &reg);
if (ret != 0) {
dev_err(wm8400->dev, "Chip ID register read failed\n");
return -EIO;
}
if (be16_to_cpu(reg) != reg_data[WM8400_RESET_ID].default_val) {
dev_err(wm8400->dev, "Device is not a WM8400, ID is %x\n",
be16_to_cpu(reg));
return -ENODEV;
}
ret = wm8400->read_dev(wm8400->io_data, 0,
ARRAY_SIZE(wm8400->reg_cache),
wm8400->reg_cache);
if (ret != 0) {
dev_err(wm8400->dev, "Register cache read failed\n");
return -EIO;
}
for (i = 0; i < ARRAY_SIZE(wm8400->reg_cache); i++)
wm8400->reg_cache[i] = be16_to_cpu(wm8400->reg_cache[i]);
if (!(wm8400->reg_cache[WM8400_POWER_MANAGEMENT_1] & WM8400_CODEC_ENA))
for (i = 0; i < ARRAY_SIZE(wm8400->reg_cache); i++)
if (reg_data[i].is_codec)
wm8400->reg_cache[i] = reg_data[i].default_val;
ret = wm8400_read(wm8400, WM8400_ID, 1, &reg);
if (ret != 0) {
dev_err(wm8400->dev, "ID register read failed: %d\n", ret);
return ret;
}
reg = (reg & WM8400_CHIP_REV_MASK) >> WM8400_CHIP_REV_SHIFT;
dev_info(wm8400->dev, "WM8400 revision %x\n", reg);
ret = wm8400_register_codec(wm8400);
if (ret != 0) {
dev_err(wm8400->dev, "Failed to register codec\n");
goto err_children;
}
if (pdata && pdata->platform_init) {
ret = pdata->platform_init(wm8400->dev);
if (ret != 0) {
dev_err(wm8400->dev, "Platform init failed: %d\n",
ret);
goto err_children;
}
} else
dev_warn(wm8400->dev, "No platform initialisation supplied\n");
return 0;
err_children:
mfd_remove_devices(wm8400->dev);
return ret;
}
static void wm8400_release(struct wm8400 *wm8400)
{
mfd_remove_devices(wm8400->dev);
}
static int wm8400_i2c_read(void *io_data, char reg, int count, u16 *dest)
{
struct i2c_client *i2c = io_data;
struct i2c_msg xfer[2];
int ret;
xfer[0].addr = i2c->addr;
xfer[0].flags = 0;
xfer[0].len = 1;
xfer[0].buf = &reg;
xfer[1].addr = i2c->addr;
xfer[1].flags = I2C_M_RD;
xfer[1].len = count * sizeof(u16);
xfer[1].buf = (u8 *)dest;
ret = i2c_transfer(i2c->adapter, xfer, 2);
if (ret == 2)
ret = 0;
else if (ret >= 0)
ret = -EIO;
return ret;
}
static int wm8400_i2c_write(void *io_data, char reg, int count, const u16 *src)
{
struct i2c_client *i2c = io_data;
u8 *msg;
int ret;
msg = kmalloc((count * sizeof(u16)) + 1, GFP_KERNEL);
if (msg == NULL)
return -ENOMEM;
msg[0] = reg;
memcpy(&msg[1], src, count * sizeof(u16));
ret = i2c_master_send(i2c, msg, (count * sizeof(u16)) + 1);
if (ret == (count * 2) + 1)
ret = 0;
else if (ret >= 0)
ret = -EIO;
kfree(msg);
return ret;
}
static int wm8400_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8400 *wm8400;
int ret;
wm8400 = kzalloc(sizeof(struct wm8400), GFP_KERNEL);
if (wm8400 == NULL) {
ret = -ENOMEM;
goto err;
}
wm8400->io_data = i2c;
wm8400->read_dev = wm8400_i2c_read;
wm8400->write_dev = wm8400_i2c_write;
wm8400->dev = &i2c->dev;
i2c_set_clientdata(i2c, wm8400);
ret = wm8400_init(wm8400, i2c->dev.platform_data);
if (ret != 0)
goto struct_err;
return 0;
struct_err:
kfree(wm8400);
err:
return ret;
}
static int wm8400_i2c_remove(struct i2c_client *i2c)
{
struct wm8400 *wm8400 = i2c_get_clientdata(i2c);
wm8400_release(wm8400);
kfree(wm8400);
return 0;
}
static int __init wm8400_module_init(void)
{
int ret = -ENODEV;
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
ret = i2c_add_driver(&wm8400_i2c_driver);
if (ret != 0)
pr_err("Failed to register I2C driver: %d\n", ret);
#endif
return ret;
}
static void __exit wm8400_module_exit(void)
{
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
i2c_del_driver(&wm8400_i2c_driver);
#endif
}
