int cyttsp_i2c_read_block_data(struct device *dev, u8 *xfer_buf,
u16 addr, u8 length, void *values)
{
struct i2c_client *client = to_i2c_client(dev);
u8 client_addr = client->addr | ((addr >> 8) & 0x1);
u8 addr_lo = addr & 0xFF;
struct i2c_msg msgs[] = {
{
.addr = client_addr,
.flags = 0,
.len = 1,
.buf = &addr_lo,
},
{
.addr = client_addr,
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
int cyttsp_i2c_write_block_data(struct device *dev, u8 *xfer_buf,
u16 addr, u8 length, const void *values)
{
struct i2c_client *client = to_i2c_client(dev);
u8 client_addr = client->addr | ((addr >> 8) & 0x1);
u8 addr_lo = addr & 0xFF;
struct i2c_msg msgs[] = {
{
.addr = client_addr,
.flags = 0,
.len = length + 1,
.buf = xfer_buf,
},
};
int retval;
xfer_buf[0] = addr_lo;
memcpy(&xfer_buf[1], values, length);
retval = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (retval < 0)
return retval;
return retval != ARRAY_SIZE(msgs) ? -EIO : 0;
}
