static int adt7316_i2c_read(void *client, u8 reg, u8 *data)
{
struct i2c_client *cl = client;
int ret = 0;
ret = i2c_smbus_write_byte(cl, reg);
if (ret < 0) {
dev_err(&cl->dev, "I2C fail to select reg\n");
return ret;
}
ret = i2c_smbus_read_byte(client);
if (ret < 0) {
dev_err(&cl->dev, "I2C read error\n");
return ret;
}
return 0;
}
static int adt7316_i2c_write(void *client, u8 reg, u8 data)
{
struct i2c_client *cl = client;
int ret = 0;
ret = i2c_smbus_write_byte_data(cl, reg, data);
if (ret < 0)
dev_err(&cl->dev, "I2C write error\n");
return ret;
}
static int adt7316_i2c_multi_read(void *client, u8 reg, u8 count, u8 *data)
{
struct i2c_client *cl = client;
int i, ret = 0;
if (count > ADT7316_REG_MAX_ADDR)
count = ADT7316_REG_MAX_ADDR;
for (i = 0; i < count; i++) {
ret = adt7316_i2c_read(cl, reg, &data[i]);
if (ret < 0) {
dev_err(&cl->dev, "I2C multi read error\n");
return ret;
}
}
return 0;
}
static int adt7316_i2c_multi_write(void *client, u8 reg, u8 count, u8 *data)
{
struct i2c_client *cl = client;
int i, ret = 0;
if (count > ADT7316_REG_MAX_ADDR)
count = ADT7316_REG_MAX_ADDR;
for (i = 0; i < count; i++) {
ret = adt7316_i2c_write(cl, reg, data[i]);
if (ret < 0) {
dev_err(&cl->dev, "I2C multi write error\n");
return ret;
}
}
return 0;
}
static int adt7316_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adt7316_bus bus = {
.client = client,
.irq = client->irq,
.irq_flags = IRQF_TRIGGER_LOW,
.read = adt7316_i2c_read,
.write = adt7316_i2c_write,
.multi_read = adt7316_i2c_multi_read,
.multi_write = adt7316_i2c_multi_write,
};
return adt7316_probe(&client->dev, &bus, id->name);
}
