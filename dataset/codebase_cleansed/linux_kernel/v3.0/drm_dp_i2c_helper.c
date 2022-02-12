static int
i2c_algo_dp_aux_transaction(struct i2c_adapter *adapter, int mode,
uint8_t write_byte, uint8_t *read_byte)
{
struct i2c_algo_dp_aux_data *algo_data = adapter->algo_data;
int ret;
ret = (*algo_data->aux_ch)(adapter, mode,
write_byte, read_byte);
return ret;
}
static int
i2c_algo_dp_aux_address(struct i2c_adapter *adapter, u16 address, bool reading)
{
struct i2c_algo_dp_aux_data *algo_data = adapter->algo_data;
int mode = MODE_I2C_START;
int ret;
if (reading)
mode |= MODE_I2C_READ;
else
mode |= MODE_I2C_WRITE;
algo_data->address = address;
algo_data->running = true;
ret = i2c_algo_dp_aux_transaction(adapter, mode, 0, NULL);
return ret;
}
static void
i2c_algo_dp_aux_stop(struct i2c_adapter *adapter, bool reading)
{
struct i2c_algo_dp_aux_data *algo_data = adapter->algo_data;
int mode = MODE_I2C_STOP;
if (reading)
mode |= MODE_I2C_READ;
else
mode |= MODE_I2C_WRITE;
if (algo_data->running) {
(void) i2c_algo_dp_aux_transaction(adapter, mode, 0, NULL);
algo_data->running = false;
}
}
static int
i2c_algo_dp_aux_put_byte(struct i2c_adapter *adapter, u8 byte)
{
struct i2c_algo_dp_aux_data *algo_data = adapter->algo_data;
int ret;
if (!algo_data->running)
return -EIO;
ret = i2c_algo_dp_aux_transaction(adapter, MODE_I2C_WRITE, byte, NULL);
return ret;
}
static int
i2c_algo_dp_aux_get_byte(struct i2c_adapter *adapter, u8 *byte_ret)
{
struct i2c_algo_dp_aux_data *algo_data = adapter->algo_data;
int ret;
if (!algo_data->running)
return -EIO;
ret = i2c_algo_dp_aux_transaction(adapter, MODE_I2C_READ, 0, byte_ret);
return ret;
}
static int
i2c_algo_dp_aux_xfer(struct i2c_adapter *adapter,
struct i2c_msg *msgs,
int num)
{
int ret = 0;
bool reading = false;
int m;
int b;
for (m = 0; m < num; m++) {
u16 len = msgs[m].len;
u8 *buf = msgs[m].buf;
reading = (msgs[m].flags & I2C_M_RD) != 0;
ret = i2c_algo_dp_aux_address(adapter, msgs[m].addr, reading);
if (ret < 0)
break;
if (reading) {
for (b = 0; b < len; b++) {
ret = i2c_algo_dp_aux_get_byte(adapter, &buf[b]);
if (ret < 0)
break;
}
} else {
for (b = 0; b < len; b++) {
ret = i2c_algo_dp_aux_put_byte(adapter, buf[b]);
if (ret < 0)
break;
}
}
if (ret < 0)
break;
}
if (ret >= 0)
ret = num;
i2c_algo_dp_aux_stop(adapter, reading);
DRM_DEBUG_KMS("dp_aux_xfer return %d\n", ret);
return ret;
}
static u32
i2c_algo_dp_aux_functionality(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL |
I2C_FUNC_SMBUS_READ_BLOCK_DATA |
I2C_FUNC_SMBUS_BLOCK_PROC_CALL |
I2C_FUNC_10BIT_ADDR;
}
static void
i2c_dp_aux_reset_bus(struct i2c_adapter *adapter)
{
(void) i2c_algo_dp_aux_address(adapter, 0, false);
(void) i2c_algo_dp_aux_stop(adapter, false);
}
static int
i2c_dp_aux_prepare_bus(struct i2c_adapter *adapter)
{
adapter->algo = &i2c_dp_aux_algo;
adapter->retries = 3;
i2c_dp_aux_reset_bus(adapter);
return 0;
}
int
i2c_dp_aux_add_bus(struct i2c_adapter *adapter)
{
int error;
error = i2c_dp_aux_prepare_bus(adapter);
if (error)
return error;
error = i2c_add_adapter(adapter);
return error;
}
