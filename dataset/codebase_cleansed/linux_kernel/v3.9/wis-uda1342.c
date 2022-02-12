static int write_reg(struct i2c_client *client, int reg, int value)
{
i2c_smbus_write_word_data(client, reg, swab16(value));
return 0;
}
static int wis_uda1342_command(struct i2c_client *client,
unsigned int cmd, void *arg)
{
switch (cmd) {
case VIDIOC_S_AUDIO:
{
int *inp = arg;
switch (*inp) {
case TVAUDIO_INPUT_TUNER:
write_reg(client, 0x00, 0x1441);
break;
case TVAUDIO_INPUT_EXTERN:
write_reg(client, 0x00, 0x1241);
break;
default:
dev_err(&client->dev, "input %d not supported\n",
*inp);
break;
}
break;
}
default:
break;
}
return 0;
}
static int wis_uda1342_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
dev_dbg(&client->dev, "initializing UDA1342 at address %d on %s\n",
client->addr, adapter->name);
write_reg(client, 0x00, 0x8000);
write_reg(client, 0x00, 0x1241);
return 0;
}
static int wis_uda1342_remove(struct i2c_client *client)
{
return 0;
}
