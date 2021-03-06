static int regmap_i2c_write(struct device *dev, const void *data, size_t count)
{
struct i2c_client *i2c = to_i2c_client(dev);
int ret;
ret = i2c_master_send(i2c, data, count);
if (ret == count)
return 0;
else if (ret < 0)
return ret;
else
return -EIO;
}
static int regmap_i2c_gather_write(struct device *dev,
const void *reg, size_t reg_size,
const void *val, size_t val_size)
{
struct i2c_client *i2c = to_i2c_client(dev);
struct i2c_msg xfer[2];
int ret;
if (!i2c_check_functionality(i2c->adapter, I2C_FUNC_PROTOCOL_MANGLING))
return -ENOTSUPP;
xfer[0].addr = i2c->addr;
xfer[0].flags = 0;
xfer[0].len = reg_size;
xfer[0].buf = (void *)reg;
xfer[1].addr = i2c->addr;
xfer[1].flags = I2C_M_NOSTART;
xfer[1].len = val_size;
xfer[1].buf = (void *)val;
ret = i2c_transfer(i2c->adapter, xfer, 2);
if (ret == 2)
return 0;
if (ret < 0)
return ret;
else
return -EIO;
}
static int regmap_i2c_read(struct device *dev,
const void *reg, size_t reg_size,
void *val, size_t val_size)
{
struct i2c_client *i2c = to_i2c_client(dev);
struct i2c_msg xfer[2];
int ret;
xfer[0].addr = i2c->addr;
xfer[0].flags = 0;
xfer[0].len = reg_size;
xfer[0].buf = (void *)reg;
xfer[1].addr = i2c->addr;
xfer[1].flags = I2C_M_RD;
xfer[1].len = val_size;
xfer[1].buf = val;
ret = i2c_transfer(i2c->adapter, xfer, 2);
if (ret == 2)
return 0;
else if (ret < 0)
return ret;
else
return -EIO;
}
struct regmap *regmap_init_i2c(struct i2c_client *i2c,
const struct regmap_config *config)
{
return regmap_init(&i2c->dev, &regmap_i2c, config);
}
struct regmap *devm_regmap_init_i2c(struct i2c_client *i2c,
const struct regmap_config *config)
{
return devm_regmap_init(&i2c->dev, &regmap_i2c, config);
}
