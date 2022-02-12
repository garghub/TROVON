static int regmap_spmi_base_read(void *context,
const void *reg, size_t reg_size,
void *val, size_t val_size)
{
u8 addr = *(u8 *)reg;
int err = 0;
BUG_ON(reg_size != 1);
while (val_size-- && !err)
err = spmi_register_read(context, addr++, val++);
return err;
}
static int regmap_spmi_base_gather_write(void *context,
const void *reg, size_t reg_size,
const void *val, size_t val_size)
{
const u8 *data = val;
u8 addr = *(u8 *)reg;
int err = 0;
BUG_ON(reg_size != 1);
if (addr == 0 && val_size) {
err = spmi_register_zero_write(context, *data);
if (err)
goto err_out;
data++;
addr++;
val_size--;
}
while (val_size) {
err = spmi_register_write(context, addr, *data);
if (err)
goto err_out;
data++;
addr++;
val_size--;
}
err_out:
return err;
}
static int regmap_spmi_base_write(void *context, const void *data,
size_t count)
{
BUG_ON(count < 1);
return regmap_spmi_base_gather_write(context, data, 1, data + 1,
count - 1);
}
struct regmap *__regmap_init_spmi_base(struct spmi_device *sdev,
const struct regmap_config *config,
struct lock_class_key *lock_key,
const char *lock_name)
{
return __regmap_init(&sdev->dev, &regmap_spmi_base, sdev, config,
lock_key, lock_name);
}
struct regmap *__devm_regmap_init_spmi_base(struct spmi_device *sdev,
const struct regmap_config *config,
struct lock_class_key *lock_key,
const char *lock_name)
{
return __devm_regmap_init(&sdev->dev, &regmap_spmi_base, sdev, config,
lock_key, lock_name);
}
static int regmap_spmi_ext_read(void *context,
const void *reg, size_t reg_size,
void *val, size_t val_size)
{
int err = 0;
size_t len;
u16 addr;
BUG_ON(reg_size != 2);
addr = *(u16 *)reg;
while (addr <= 0xFF && val_size) {
len = min_t(size_t, val_size, 16);
err = spmi_ext_register_read(context, addr, val, len);
if (err)
goto err_out;
addr += len;
val += len;
val_size -= len;
}
while (val_size) {
len = min_t(size_t, val_size, 8);
err = spmi_ext_register_readl(context, addr, val, len);
if (err)
goto err_out;
addr += len;
val += len;
val_size -= len;
}
err_out:
return err;
}
static int regmap_spmi_ext_gather_write(void *context,
const void *reg, size_t reg_size,
const void *val, size_t val_size)
{
int err = 0;
size_t len;
u16 addr;
BUG_ON(reg_size != 2);
addr = *(u16 *)reg;
while (addr <= 0xFF && val_size) {
len = min_t(size_t, val_size, 16);
err = spmi_ext_register_write(context, addr, val, len);
if (err)
goto err_out;
addr += len;
val += len;
val_size -= len;
}
while (val_size) {
len = min_t(size_t, val_size, 8);
err = spmi_ext_register_writel(context, addr, val, len);
if (err)
goto err_out;
addr += len;
val += len;
val_size -= len;
}
err_out:
return err;
}
static int regmap_spmi_ext_write(void *context, const void *data,
size_t count)
{
BUG_ON(count < 2);
return regmap_spmi_ext_gather_write(context, data, 2, data + 2,
count - 2);
}
struct regmap *__regmap_init_spmi_ext(struct spmi_device *sdev,
const struct regmap_config *config,
struct lock_class_key *lock_key,
const char *lock_name)
{
return __regmap_init(&sdev->dev, &regmap_spmi_ext, sdev, config,
lock_key, lock_name);
}
struct regmap *__devm_regmap_init_spmi_ext(struct spmi_device *sdev,
const struct regmap_config *config,
struct lock_class_key *lock_key,
const char *lock_name)
{
return __devm_regmap_init(&sdev->dev, &regmap_spmi_ext, sdev, config,
lock_key, lock_name);
}
