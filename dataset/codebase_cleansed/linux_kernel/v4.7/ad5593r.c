static int ad5593r_write_dac(struct ad5592r_state *st, unsigned chan, u16 value)
{
struct i2c_client *i2c = to_i2c_client(st->dev);
return i2c_smbus_write_word_swapped(i2c,
AD5593R_MODE_DAC_WRITE | chan, value);
}
static int ad5593r_read_adc(struct ad5592r_state *st, unsigned chan, u16 *value)
{
struct i2c_client *i2c = to_i2c_client(st->dev);
s32 val;
val = i2c_smbus_write_word_swapped(i2c,
AD5593R_MODE_CONF | AD5592R_REG_ADC_SEQ, BIT(chan));
if (val < 0)
return (int) val;
val = i2c_smbus_read_word_swapped(i2c, AD5593R_MODE_ADC_READBACK);
if (val < 0)
return (int) val;
*value = (u16) val;
return 0;
}
static int ad5593r_reg_write(struct ad5592r_state *st, u8 reg, u16 value)
{
struct i2c_client *i2c = to_i2c_client(st->dev);
return i2c_smbus_write_word_swapped(i2c,
AD5593R_MODE_CONF | reg, value);
}
static int ad5593r_reg_read(struct ad5592r_state *st, u8 reg, u16 *value)
{
struct i2c_client *i2c = to_i2c_client(st->dev);
s32 val;
val = i2c_smbus_read_word_swapped(i2c, AD5593R_MODE_REG_READBACK | reg);
if (val < 0)
return (int) val;
*value = (u16) val;
return 0;
}
static int ad5593r_gpio_read(struct ad5592r_state *st, u8 *value)
{
struct i2c_client *i2c = to_i2c_client(st->dev);
s32 val;
val = i2c_smbus_read_word_swapped(i2c, AD5593R_MODE_GPIO_READBACK);
if (val < 0)
return (int) val;
*value = (u8) val;
return 0;
}
static int ad5593r_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
return ad5592r_probe(&i2c->dev, id->name, &ad5593r_rw_ops);
}
static int ad5593r_i2c_remove(struct i2c_client *i2c)
{
return ad5592r_remove(&i2c->dev);
}
