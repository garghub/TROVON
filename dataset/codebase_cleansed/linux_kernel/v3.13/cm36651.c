static int cm36651_setup_reg(struct cm36651_data *cm36651)
{
struct i2c_client *client = cm36651->client;
struct i2c_client *ps_client = cm36651->ps_client;
int i, ret;
cm36651->cs_ctrl_regs[CM36651_CS_CONF1] = CM36651_ALS_ENABLE |
CM36651_ALS_THRES;
cm36651->cs_ctrl_regs[CM36651_CS_CONF2] = CM36651_CS_CONF2_DEFAULT_BIT;
for (i = 0; i < CM36651_CS_CONF_REG_NUM; i++) {
ret = i2c_smbus_write_byte_data(client, cm36651_cs_reg[i],
cm36651->cs_ctrl_regs[i]);
if (ret < 0)
return ret;
}
cm36651->ps_ctrl_regs[CM36651_PS_CONF1] = CM36651_PS_ENABLE |
CM36651_PS_IT2;
cm36651->ps_ctrl_regs[CM36651_PS_THD] = CM36651_PS_INITIAL_THD;
cm36651->ps_ctrl_regs[CM36651_PS_CANC] = CM36651_PS_CANC_DEFAULT;
cm36651->ps_ctrl_regs[CM36651_PS_CONF2] = CM36651_PS_HYS2 |
CM36651_PS_DIR_INT | CM36651_PS_SMART_PERS_EN;
for (i = 0; i < CM36651_PS_REG_NUM; i++) {
ret = i2c_smbus_write_byte_data(ps_client, cm36651_ps_reg[i],
cm36651->ps_ctrl_regs[i]);
if (ret < 0)
return ret;
}
ret = i2c_smbus_write_byte_data(client, CM36651_CS_CONF1,
CM36651_ALS_DISABLE);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(cm36651->ps_client,
CM36651_PS_CONF1, CM36651_PS_DISABLE);
if (ret < 0)
return ret;
return 0;
}
static int cm36651_read_output(struct cm36651_data *cm36651,
struct iio_chan_spec const *chan, int *val)
{
struct i2c_client *client = cm36651->client;
int ret = -EINVAL;
switch (chan->type) {
case IIO_LIGHT:
*val = i2c_smbus_read_word_data(client, chan->address);
if (*val < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, CM36651_CS_CONF1,
CM36651_ALS_DISABLE);
if (ret < 0)
return ret;
ret = IIO_VAL_INT;
break;
case IIO_PROXIMITY:
*val = i2c_smbus_read_byte(cm36651->ps_client);
if (*val < 0)
return ret;
if (!test_bit(CM36651_PROXIMITY_EV_EN, &cm36651->flags)) {
ret = i2c_smbus_write_byte_data(cm36651->ps_client,
CM36651_PS_CONF1, CM36651_PS_DISABLE);
if (ret < 0)
return ret;
}
ret = IIO_VAL_INT;
break;
default:
break;
}
return ret;
}
static irqreturn_t cm36651_irq_handler(int irq, void *data)
{
struct iio_dev *indio_dev = data;
struct cm36651_data *cm36651 = iio_priv(indio_dev);
struct i2c_client *client = cm36651->client;
int ev_dir, ret;
u64 ev_code;
ret = i2c_smbus_read_byte(cm36651->ara_client);
if (ret < 0) {
dev_err(&client->dev,
"%s: Data read failed: %d\n", __func__, ret);
return IRQ_HANDLED;
}
switch (ret) {
case CM36651_CLOSE_PROXIMITY:
ev_dir = IIO_EV_DIR_RISING;
break;
case CM36651_FAR_PROXIMITY:
ev_dir = IIO_EV_DIR_FALLING;
break;
default:
dev_err(&client->dev,
"%s: Data read wrong: %d\n", __func__, ret);
return IRQ_HANDLED;
}
ev_code = IIO_UNMOD_EVENT_CODE(IIO_PROXIMITY,
CM36651_CMD_READ_RAW_PROXIMITY,
IIO_EV_TYPE_THRESH, ev_dir);
iio_push_event(indio_dev, ev_code, iio_get_time_ns());
return IRQ_HANDLED;
}
static int cm36651_set_operation_mode(struct cm36651_data *cm36651, int cmd)
{
struct i2c_client *client = cm36651->client;
struct i2c_client *ps_client = cm36651->ps_client;
int ret = -EINVAL;
switch (cmd) {
case CM36651_CMD_READ_RAW_LIGHT:
ret = i2c_smbus_write_byte_data(client, CM36651_CS_CONF1,
cm36651->cs_ctrl_regs[CM36651_CS_CONF1]);
break;
case CM36651_CMD_READ_RAW_PROXIMITY:
if (test_bit(CM36651_PROXIMITY_EV_EN, &cm36651->flags))
return CM36651_PROXIMITY_EV_EN;
ret = i2c_smbus_write_byte_data(ps_client, CM36651_PS_CONF1,
cm36651->ps_ctrl_regs[CM36651_PS_CONF1]);
break;
case CM36651_CMD_PROX_EV_EN:
if (test_bit(CM36651_PROXIMITY_EV_EN, &cm36651->flags)) {
dev_err(&client->dev,
"Already proximity event enable state\n");
return ret;
}
set_bit(CM36651_PROXIMITY_EV_EN, &cm36651->flags);
ret = i2c_smbus_write_byte_data(ps_client,
cm36651_ps_reg[CM36651_PS_CONF1],
CM36651_PS_INT_EN | CM36651_PS_PERS2 | CM36651_PS_IT2);
if (ret < 0) {
dev_err(&client->dev, "Proximity enable event failed\n");
return ret;
}
break;
case CM36651_CMD_PROX_EV_DIS:
if (!test_bit(CM36651_PROXIMITY_EV_EN, &cm36651->flags)) {
dev_err(&client->dev,
"Already proximity event disable state\n");
return ret;
}
clear_bit(CM36651_PROXIMITY_EV_EN, &cm36651->flags);
ret = i2c_smbus_write_byte_data(ps_client,
CM36651_PS_CONF1, CM36651_PS_DISABLE);
break;
}
if (ret < 0)
dev_err(&client->dev, "Write register failed\n");
return ret;
}
static int cm36651_read_channel(struct cm36651_data *cm36651,
struct iio_chan_spec const *chan, int *val)
{
struct i2c_client *client = cm36651->client;
int cmd, ret;
if (chan->type == IIO_LIGHT)
cmd = CM36651_CMD_READ_RAW_LIGHT;
else if (chan->type == IIO_PROXIMITY)
cmd = CM36651_CMD_READ_RAW_PROXIMITY;
else
return -EINVAL;
ret = cm36651_set_operation_mode(cm36651, cmd);
if (ret < 0) {
dev_err(&client->dev, "CM36651 set operation mode failed\n");
return ret;
}
msleep(50);
ret = cm36651_read_output(cm36651, chan, val);
if (ret < 0) {
dev_err(&client->dev, "CM36651 read output failed\n");
return ret;
}
return ret;
}
static int cm36651_read_int_time(struct cm36651_data *cm36651,
struct iio_chan_spec const *chan, int *val)
{
switch (chan->type) {
case IIO_LIGHT:
if (cm36651->cs_int_time[chan->address] == CM36651_CS_IT1)
*val = 80000;
else if (cm36651->cs_int_time[chan->address] == CM36651_CS_IT2)
*val = 160000;
else if (cm36651->cs_int_time[chan->address] == CM36651_CS_IT3)
*val = 320000;
else if (cm36651->cs_int_time[chan->address] == CM36651_CS_IT4)
*val = 640000;
else
return -EINVAL;
break;
case IIO_PROXIMITY:
if (cm36651->ps_int_time == CM36651_PS_IT1)
*val = 320;
else if (cm36651->ps_int_time == CM36651_PS_IT2)
*val = 420;
else if (cm36651->ps_int_time == CM36651_PS_IT3)
*val = 520;
else if (cm36651->ps_int_time == CM36651_PS_IT4)
*val = 640;
else
return -EINVAL;
break;
default:
return -EINVAL;
}
return IIO_VAL_INT;
}
static int cm36651_write_int_time(struct cm36651_data *cm36651,
struct iio_chan_spec const *chan, int val)
{
struct i2c_client *client = cm36651->client;
struct i2c_client *ps_client = cm36651->ps_client;
int int_time, ret;
switch (chan->type) {
case IIO_LIGHT:
if (val == 80000)
int_time = CM36651_CS_IT1;
else if (val == 160000)
int_time = CM36651_CS_IT2;
else if (val == 320000)
int_time = CM36651_CS_IT3;
else if (val == 640000)
int_time = CM36651_CS_IT4;
else
return -EINVAL;
ret = i2c_smbus_write_byte_data(client, CM36651_CS_CONF3,
int_time >> 2 * (chan->address));
if (ret < 0) {
dev_err(&client->dev, "CS integration time write failed\n");
return ret;
}
cm36651->cs_int_time[chan->address] = int_time;
break;
case IIO_PROXIMITY:
if (val == 320)
int_time = CM36651_PS_IT1;
else if (val == 420)
int_time = CM36651_PS_IT2;
else if (val == 520)
int_time = CM36651_PS_IT3;
else if (val == 640)
int_time = CM36651_PS_IT4;
else
return -EINVAL;
ret = i2c_smbus_write_byte_data(ps_client,
CM36651_PS_CONF1, int_time);
if (ret < 0) {
dev_err(&client->dev, "PS integration time write failed\n");
return ret;
}
cm36651->ps_int_time = int_time;
break;
default:
return -EINVAL;
}
return ret;
}
static int cm36651_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct cm36651_data *cm36651 = iio_priv(indio_dev);
int ret;
mutex_lock(&cm36651->lock);
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = cm36651_read_channel(cm36651, chan, val);
break;
case IIO_CHAN_INFO_INT_TIME:
ret = cm36651_read_int_time(cm36651, chan, val);
break;
default:
ret = -EINVAL;
}
mutex_unlock(&cm36651->lock);
return ret;
}
static int cm36651_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct cm36651_data *cm36651 = iio_priv(indio_dev);
struct i2c_client *client = cm36651->client;
int ret = -EINVAL;
if (mask == IIO_CHAN_INFO_INT_TIME) {
ret = cm36651_write_int_time(cm36651, chan, val);
if (ret < 0)
dev_err(&client->dev, "Integration time write failed\n");
}
return ret;
}
static int cm36651_read_prox_thresh(struct iio_dev *indio_dev,
u64 event_code, int *val)
{
struct cm36651_data *cm36651 = iio_priv(indio_dev);
*val = cm36651->ps_ctrl_regs[CM36651_PS_THD];
return 0;
}
static int cm36651_write_prox_thresh(struct iio_dev *indio_dev,
u64 event_code, int val)
{
struct cm36651_data *cm36651 = iio_priv(indio_dev);
struct i2c_client *client = cm36651->client;
int ret;
if (val < 3 || val > 255)
return -EINVAL;
cm36651->ps_ctrl_regs[CM36651_PS_THD] = val;
ret = i2c_smbus_write_byte_data(cm36651->ps_client, CM36651_PS_THD,
cm36651->ps_ctrl_regs[CM36651_PS_THD]);
if (ret < 0) {
dev_err(&client->dev, "PS threshold write failed: %d\n", ret);
return ret;
}
return 0;
}
static int cm36651_write_prox_event_config(struct iio_dev *indio_dev,
u64 event_code, int state)
{
struct cm36651_data *cm36651 = iio_priv(indio_dev);
int cmd, ret = -EINVAL;
mutex_lock(&cm36651->lock);
cmd = state ? CM36651_CMD_PROX_EV_EN : CM36651_CMD_PROX_EV_DIS;
ret = cm36651_set_operation_mode(cm36651, cmd);
mutex_unlock(&cm36651->lock);
return ret;
}
static int cm36651_read_prox_event_config(struct iio_dev *indio_dev,
u64 event_code)
{
struct cm36651_data *cm36651 = iio_priv(indio_dev);
int event_en;
mutex_lock(&cm36651->lock);
event_en = test_bit(CM36651_PROXIMITY_EV_EN, &cm36651->flags);
mutex_unlock(&cm36651->lock);
return event_en;
}
static int cm36651_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct cm36651_data *cm36651;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*cm36651));
if (!indio_dev)
return -ENOMEM;
cm36651 = iio_priv(indio_dev);
cm36651->vled_reg = devm_regulator_get(&client->dev, "vled");
if (IS_ERR(cm36651->vled_reg)) {
dev_err(&client->dev, "get regulator vled failed\n");
return PTR_ERR(cm36651->vled_reg);
}
ret = regulator_enable(cm36651->vled_reg);
if (ret) {
dev_err(&client->dev, "enable regulator vled failed\n");
return ret;
}
i2c_set_clientdata(client, indio_dev);
cm36651->client = client;
cm36651->ps_client = i2c_new_dummy(client->adapter,
CM36651_I2C_ADDR_PS);
cm36651->ara_client = i2c_new_dummy(client->adapter, CM36651_ARA);
mutex_init(&cm36651->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->channels = cm36651_channels;
indio_dev->num_channels = ARRAY_SIZE(cm36651_channels);
indio_dev->info = &cm36651_info;
indio_dev->name = id->name;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = cm36651_setup_reg(cm36651);
if (ret) {
dev_err(&client->dev, "%s: register setup failed\n", __func__);
goto error_disable_reg;
}
ret = request_threaded_irq(client->irq, NULL, cm36651_irq_handler,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"cm36651", indio_dev);
if (ret) {
dev_err(&client->dev, "%s: request irq failed\n", __func__);
goto error_disable_reg;
}
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&client->dev, "%s: regist device failed\n", __func__);
goto error_free_irq;
}
return 0;
error_free_irq:
free_irq(client->irq, indio_dev);
error_disable_reg:
regulator_disable(cm36651->vled_reg);
return ret;
}
static int cm36651_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct cm36651_data *cm36651 = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
regulator_disable(cm36651->vled_reg);
free_irq(client->irq, indio_dev);
return 0;
}
