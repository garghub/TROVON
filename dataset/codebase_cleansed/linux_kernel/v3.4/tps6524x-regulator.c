static int __read_reg(struct tps6524x *hw, int reg)
{
int error = 0;
u16 cmd = CMD_READ(reg), in;
u8 status;
struct spi_message m;
struct spi_transfer t[3];
spi_message_init(&m);
memset(t, 0, sizeof(t));
t[0].tx_buf = &cmd;
t[0].len = 2;
t[0].bits_per_word = 12;
spi_message_add_tail(&t[0], &m);
t[1].rx_buf = &in;
t[1].len = 2;
t[1].bits_per_word = 16;
spi_message_add_tail(&t[1], &m);
t[2].rx_buf = &status;
t[2].len = 1;
t[2].bits_per_word = 4;
spi_message_add_tail(&t[2], &m);
error = spi_sync(hw->spi, &m);
if (error < 0)
return error;
dev_dbg(hw->dev, "read reg %d, data %x, status %x\n",
reg, in, status);
if (!(status & STAT_CLK) || (status & STAT_WRITE))
return -EIO;
if (status & STAT_INVALID)
return -EINVAL;
return in;
}
static int read_reg(struct tps6524x *hw, int reg)
{
int ret;
mutex_lock(&hw->lock);
ret = __read_reg(hw, reg);
mutex_unlock(&hw->lock);
return ret;
}
static int __write_reg(struct tps6524x *hw, int reg, int val)
{
int error = 0;
u16 cmd = CMD_WRITE(reg), out = val;
u8 status;
struct spi_message m;
struct spi_transfer t[3];
spi_message_init(&m);
memset(t, 0, sizeof(t));
t[0].tx_buf = &cmd;
t[0].len = 2;
t[0].bits_per_word = 12;
spi_message_add_tail(&t[0], &m);
t[1].tx_buf = &out;
t[1].len = 2;
t[1].bits_per_word = 16;
spi_message_add_tail(&t[1], &m);
t[2].rx_buf = &status;
t[2].len = 1;
t[2].bits_per_word = 4;
spi_message_add_tail(&t[2], &m);
error = spi_sync(hw->spi, &m);
if (error < 0)
return error;
dev_dbg(hw->dev, "wrote reg %d, data %x, status %x\n",
reg, out, status);
if (!(status & STAT_CLK) || !(status & STAT_WRITE))
return -EIO;
if (status & (STAT_INVALID | STAT_WP))
return -EINVAL;
return error;
}
static int __rmw_reg(struct tps6524x *hw, int reg, int mask, int val)
{
int ret;
ret = __read_reg(hw, reg);
if (ret < 0)
return ret;
ret &= ~mask;
ret |= val;
ret = __write_reg(hw, reg, ret);
return (ret < 0) ? ret : 0;
}
static int rmw_protect(struct tps6524x *hw, int reg, int mask, int val)
{
int ret;
mutex_lock(&hw->lock);
ret = __write_reg(hw, REG_WRITE_ENABLE, 1);
if (ret) {
dev_err(hw->dev, "failed to set write enable\n");
goto error;
}
ret = __rmw_reg(hw, reg, mask, val);
if (ret)
dev_err(hw->dev, "failed to rmw register %d\n", reg);
ret = __write_reg(hw, REG_WRITE_ENABLE, 0);
if (ret) {
dev_err(hw->dev, "failed to clear write enable\n");
goto error;
}
error:
mutex_unlock(&hw->lock);
return ret;
}
static int read_field(struct tps6524x *hw, const struct field *field)
{
int tmp;
tmp = read_reg(hw, field->reg);
if (tmp < 0)
return tmp;
return (tmp >> field->shift) & field->mask;
}
static int write_field(struct tps6524x *hw, const struct field *field,
int val)
{
if (val & ~field->mask)
return -EOVERFLOW;
return rmw_protect(hw, field->reg,
field->mask << field->shift,
val << field->shift);
}
static int list_voltage(struct regulator_dev *rdev, unsigned selector)
{
const struct supply_info *info;
struct tps6524x *hw;
hw = rdev_get_drvdata(rdev);
info = &supply_info[rdev_get_id(rdev)];
if (info->flags & FIXED_VOLTAGE)
return selector ? -EINVAL : info->fixed_voltage;
return ((selector < info->n_voltages) ?
info->voltages[selector] : -EINVAL);
}
static int set_voltage(struct regulator_dev *rdev, int min_uV, int max_uV,
unsigned *selector)
{
const struct supply_info *info;
struct tps6524x *hw;
unsigned i;
hw = rdev_get_drvdata(rdev);
info = &supply_info[rdev_get_id(rdev)];
if (info->flags & FIXED_VOLTAGE)
return -EINVAL;
for (i = 0; i < info->n_voltages; i++)
if (min_uV <= info->voltages[i] &&
max_uV >= info->voltages[i])
break;
if (i >= info->n_voltages)
i = info->n_voltages - 1;
*selector = i;
return write_field(hw, &info->voltage, i);
}
static int get_voltage(struct regulator_dev *rdev)
{
const struct supply_info *info;
struct tps6524x *hw;
int ret;
hw = rdev_get_drvdata(rdev);
info = &supply_info[rdev_get_id(rdev)];
if (info->flags & FIXED_VOLTAGE)
return info->fixed_voltage;
ret = read_field(hw, &info->voltage);
if (ret < 0)
return ret;
if (WARN_ON(ret >= info->n_voltages))
return -EIO;
return info->voltages[ret];
}
static int set_current_limit(struct regulator_dev *rdev, int min_uA,
int max_uA)
{
const struct supply_info *info;
struct tps6524x *hw;
int i;
hw = rdev_get_drvdata(rdev);
info = &supply_info[rdev_get_id(rdev)];
if (info->flags & FIXED_ILIMSEL)
return -EINVAL;
for (i = 0; i < info->n_ilimsels; i++)
if (min_uA <= info->ilimsels[i] &&
max_uA >= info->ilimsels[i])
break;
if (i >= info->n_ilimsels)
return -EINVAL;
return write_field(hw, &info->ilimsel, i);
}
static int get_current_limit(struct regulator_dev *rdev)
{
const struct supply_info *info;
struct tps6524x *hw;
int ret;
hw = rdev_get_drvdata(rdev);
info = &supply_info[rdev_get_id(rdev)];
if (info->flags & FIXED_ILIMSEL)
return info->fixed_ilimsel;
ret = read_field(hw, &info->ilimsel);
if (ret < 0)
return ret;
if (WARN_ON(ret >= info->n_ilimsels))
return -EIO;
return info->ilimsels[ret];
}
static int enable_supply(struct regulator_dev *rdev)
{
const struct supply_info *info;
struct tps6524x *hw;
hw = rdev_get_drvdata(rdev);
info = &supply_info[rdev_get_id(rdev)];
return write_field(hw, &info->enable, 1);
}
static int disable_supply(struct regulator_dev *rdev)
{
const struct supply_info *info;
struct tps6524x *hw;
hw = rdev_get_drvdata(rdev);
info = &supply_info[rdev_get_id(rdev)];
return write_field(hw, &info->enable, 0);
}
static int is_supply_enabled(struct regulator_dev *rdev)
{
const struct supply_info *info;
struct tps6524x *hw;
hw = rdev_get_drvdata(rdev);
info = &supply_info[rdev_get_id(rdev)];
return read_field(hw, &info->enable);
}
static int pmic_remove(struct spi_device *spi)
{
struct tps6524x *hw = spi_get_drvdata(spi);
int i;
if (!hw)
return 0;
for (i = 0; i < N_REGULATORS; i++) {
if (hw->rdev[i])
regulator_unregister(hw->rdev[i]);
hw->rdev[i] = NULL;
}
spi_set_drvdata(spi, NULL);
kfree(hw);
return 0;
}
static int __devinit pmic_probe(struct spi_device *spi)
{
struct tps6524x *hw;
struct device *dev = &spi->dev;
const struct supply_info *info = supply_info;
struct regulator_init_data *init_data;
int ret = 0, i;
init_data = dev->platform_data;
if (!init_data) {
dev_err(dev, "could not find regulator platform data\n");
return -EINVAL;
}
hw = kzalloc(sizeof(struct tps6524x), GFP_KERNEL);
if (!hw) {
dev_err(dev, "cannot allocate regulator private data\n");
return -ENOMEM;
}
spi_set_drvdata(spi, hw);
memset(hw, 0, sizeof(struct tps6524x));
hw->dev = dev;
hw->spi = spi_dev_get(spi);
mutex_init(&hw->lock);
for (i = 0; i < N_REGULATORS; i++, info++, init_data++) {
hw->desc[i].name = info->name;
hw->desc[i].id = i;
hw->desc[i].n_voltages = info->n_voltages;
hw->desc[i].ops = &regulator_ops;
hw->desc[i].type = REGULATOR_VOLTAGE;
hw->desc[i].owner = THIS_MODULE;
if (info->flags & FIXED_VOLTAGE)
hw->desc[i].n_voltages = 1;
hw->rdev[i] = regulator_register(&hw->desc[i], dev,
init_data, hw, NULL);
if (IS_ERR(hw->rdev[i])) {
ret = PTR_ERR(hw->rdev[i]);
hw->rdev[i] = NULL;
goto fail;
}
}
return 0;
fail:
pmic_remove(spi);
return ret;
}
static int __init pmic_driver_init(void)
{
return spi_register_driver(&pmic_driver);
}
static void __exit pmic_driver_exit(void)
{
spi_unregister_driver(&pmic_driver);
}
