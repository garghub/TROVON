static int cyttsp_i2c_read_block_data(struct cyttsp *ts,
u8 addr, u8 length, void *values)
{
struct i2c_client *client = to_i2c_client(ts->dev);
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.flags = 0,
.len = 1,
.buf = &addr,
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = length,
.buf = values,
},
};
int retval;
retval = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (retval < 0)
return retval;
return retval != ARRAY_SIZE(msgs) ? -EIO : 0;
}
static int cyttsp_i2c_write_block_data(struct cyttsp *ts,
u8 addr, u8 length, const void *values)
{
struct i2c_client *client = to_i2c_client(ts->dev);
int retval;
ts->xfer_buf[0] = addr;
memcpy(&ts->xfer_buf[1], values, length);
retval = i2c_master_send(client, ts->xfer_buf, length + 1);
return retval < 0 ? retval : 0;
}
static int cyttsp_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct cyttsp *ts;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "I2C functionality not Supported\n");
return -EIO;
}
ts = cyttsp_probe(&cyttsp_i2c_bus_ops, &client->dev, client->irq,
CY_I2C_DATA_SIZE);
if (IS_ERR(ts))
return PTR_ERR(ts);
i2c_set_clientdata(client, ts);
return 0;
}
static int cyttsp_i2c_remove(struct i2c_client *client)
{
struct cyttsp *ts = i2c_get_clientdata(client);
cyttsp_remove(ts);
return 0;
}
