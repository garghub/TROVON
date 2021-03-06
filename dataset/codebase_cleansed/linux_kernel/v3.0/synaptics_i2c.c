static inline void set_scan_rate(struct synaptics_i2c *touch, int scan_rate)
{
touch->scan_ms = MSEC_PER_SEC / scan_rate;
touch->scan_rate_param = scan_rate;
}
static s32 synaptics_i2c_reg_get(struct i2c_client *client, u16 reg)
{
int ret;
ret = i2c_smbus_write_byte_data(client, PAGE_SEL_REG, reg >> 8);
if (ret == 0)
ret = i2c_smbus_read_byte_data(client, reg & 0xff);
return ret;
}
static s32 synaptics_i2c_reg_set(struct i2c_client *client, u16 reg, u8 val)
{
int ret;
ret = i2c_smbus_write_byte_data(client, PAGE_SEL_REG, reg >> 8);
if (ret == 0)
ret = i2c_smbus_write_byte_data(client, reg & 0xff, val);
return ret;
}
static s32 synaptics_i2c_word_get(struct i2c_client *client, u16 reg)
{
int ret;
ret = i2c_smbus_write_byte_data(client, PAGE_SEL_REG, reg >> 8);
if (ret == 0)
ret = i2c_smbus_read_word_data(client, reg & 0xff);
return ret;
}
static int synaptics_i2c_config(struct i2c_client *client)
{
int ret, control;
u8 int_en;
ret = synaptics_i2c_reg_set(client, DEV_CONTROL_REG, 0xc1);
if (ret)
return ret;
int_en = (polling_req) ? 0 : INT_ENA_ABS_MSK | INT_ENA_REL_MSK;
ret = synaptics_i2c_reg_set(client, INTERRUPT_EN_REG, int_en);
if (ret)
return ret;
control = synaptics_i2c_reg_get(client, GENERAL_2D_CONTROL_REG);
control |= no_decel ? 1 << NO_DECELERATION : 0;
control |= reduce_report ? 1 << REDUCE_REPORTING : 0;
control |= no_filter ? 1 << NO_FILTER : 0;
ret = synaptics_i2c_reg_set(client, GENERAL_2D_CONTROL_REG, control);
if (ret)
return ret;
return 0;
}
static int synaptics_i2c_reset_config(struct i2c_client *client)
{
int ret;
ret = synaptics_i2c_reg_set(client, DEV_COMMAND_REG, RESET_COMMAND);
if (ret) {
dev_err(&client->dev, "Unable to reset device\n");
} else {
msleep(SOFT_RESET_DELAY_MS);
ret = synaptics_i2c_config(client);
if (ret)
dev_err(&client->dev, "Unable to config device\n");
}
return ret;
}
static int synaptics_i2c_check_error(struct i2c_client *client)
{
int status, ret = 0;
status = i2c_smbus_read_byte_data(client, DEVICE_STATUS_REG) &
(CONFIGURED_MSK | ERROR_MSK);
if (status != CONFIGURED_MSK)
ret = synaptics_i2c_reset_config(client);
return ret;
}
static bool synaptics_i2c_get_input(struct synaptics_i2c *touch)
{
struct input_dev *input = touch->input;
int xy_delta, gesture;
s32 data;
s8 x_delta, y_delta;
if (synaptics_i2c_check_error(touch->client))
return 0;
data = synaptics_i2c_reg_get(touch->client, DATA_REG0);
gesture = (data >> GESTURE) & 0x1;
xy_delta = synaptics_i2c_word_get(touch->client, REL_X_REG) & 0xffff;
x_delta = xy_delta & 0xff;
y_delta = (xy_delta >> REGISTER_LENGTH) & 0xff;
input_report_key(input, BTN_LEFT, gesture);
input_report_rel(input, REL_X, x_delta);
input_report_rel(input, REL_Y, -y_delta);
input_sync(input);
return xy_delta || gesture;
}
static void synaptics_i2c_reschedule_work(struct synaptics_i2c *touch,
unsigned long delay)
{
unsigned long flags;
spin_lock_irqsave(&touch->lock, flags);
__cancel_delayed_work(&touch->dwork);
schedule_delayed_work(&touch->dwork, delay);
spin_unlock_irqrestore(&touch->lock, flags);
}
static irqreturn_t synaptics_i2c_irq(int irq, void *dev_id)
{
struct synaptics_i2c *touch = dev_id;
synaptics_i2c_reschedule_work(touch, 0);
return IRQ_HANDLED;
}
static void synaptics_i2c_check_params(struct synaptics_i2c *touch)
{
bool reset = false;
if (scan_rate != touch->scan_rate_param)
set_scan_rate(touch, scan_rate);
if (no_decel != touch->no_decel_param) {
touch->no_decel_param = no_decel;
reset = true;
}
if (no_filter != touch->no_filter_param) {
touch->no_filter_param = no_filter;
reset = true;
}
if (reduce_report != touch->reduce_report_param) {
touch->reduce_report_param = reduce_report;
reset = true;
}
if (reset)
synaptics_i2c_reset_config(touch->client);
}
static unsigned long synaptics_i2c_adjust_delay(struct synaptics_i2c *touch,
bool have_data)
{
unsigned long delay, nodata_count_thres;
if (polling_req) {
delay = touch->scan_ms;
if (have_data) {
touch->no_data_count = 0;
} else {
nodata_count_thres = NO_DATA_THRES / touch->scan_ms;
if (touch->no_data_count < nodata_count_thres)
touch->no_data_count++;
else
delay = NO_DATA_SLEEP_MSECS;
}
return msecs_to_jiffies(delay);
} else {
delay = msecs_to_jiffies(THREAD_IRQ_SLEEP_MSECS);
return round_jiffies_relative(delay);
}
}
static void synaptics_i2c_work_handler(struct work_struct *work)
{
bool have_data;
struct synaptics_i2c *touch =
container_of(work, struct synaptics_i2c, dwork.work);
unsigned long delay;
synaptics_i2c_check_params(touch);
have_data = synaptics_i2c_get_input(touch);
delay = synaptics_i2c_adjust_delay(touch, have_data);
synaptics_i2c_reschedule_work(touch, delay);
}
static int synaptics_i2c_open(struct input_dev *input)
{
struct synaptics_i2c *touch = input_get_drvdata(input);
int ret;
ret = synaptics_i2c_reset_config(touch->client);
if (ret)
return ret;
if (polling_req)
synaptics_i2c_reschedule_work(touch,
msecs_to_jiffies(NO_DATA_SLEEP_MSECS));
return 0;
}
static void synaptics_i2c_close(struct input_dev *input)
{
struct synaptics_i2c *touch = input_get_drvdata(input);
if (!polling_req)
synaptics_i2c_reg_set(touch->client, INTERRUPT_EN_REG, 0);
cancel_delayed_work_sync(&touch->dwork);
synaptics_i2c_reg_set(touch->client, DEV_CONTROL_REG, DEEP_SLEEP);
}
static void synaptics_i2c_set_input_params(struct synaptics_i2c *touch)
{
struct input_dev *input = touch->input;
input->name = touch->client->name;
input->phys = touch->client->adapter->name;
input->id.bustype = BUS_I2C;
input->id.version = synaptics_i2c_word_get(touch->client,
INFO_QUERY_REG0);
input->dev.parent = &touch->client->dev;
input->open = synaptics_i2c_open;
input->close = synaptics_i2c_close;
input_set_drvdata(input, touch);
__set_bit(EV_REL, input->evbit);
__set_bit(REL_X, input->relbit);
__set_bit(REL_Y, input->relbit);
__set_bit(EV_KEY, input->evbit);
__set_bit(BTN_LEFT, input->keybit);
}
static struct synaptics_i2c *synaptics_i2c_touch_create(struct i2c_client *client)
{
struct synaptics_i2c *touch;
touch = kzalloc(sizeof(struct synaptics_i2c), GFP_KERNEL);
if (!touch)
return NULL;
touch->client = client;
touch->no_decel_param = no_decel;
touch->scan_rate_param = scan_rate;
set_scan_rate(touch, scan_rate);
INIT_DELAYED_WORK(&touch->dwork, synaptics_i2c_work_handler);
spin_lock_init(&touch->lock);
return touch;
}
static int __devinit synaptics_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *dev_id)
{
int ret;
struct synaptics_i2c *touch;
touch = synaptics_i2c_touch_create(client);
if (!touch)
return -ENOMEM;
ret = synaptics_i2c_reset_config(client);
if (ret)
goto err_mem_free;
if (client->irq < 1)
polling_req = true;
touch->input = input_allocate_device();
if (!touch->input) {
ret = -ENOMEM;
goto err_mem_free;
}
synaptics_i2c_set_input_params(touch);
if (!polling_req) {
dev_dbg(&touch->client->dev,
"Requesting IRQ: %d\n", touch->client->irq);
ret = request_irq(touch->client->irq, synaptics_i2c_irq,
IRQF_DISABLED|IRQ_TYPE_EDGE_FALLING,
DRIVER_NAME, touch);
if (ret) {
dev_warn(&touch->client->dev,
"IRQ request failed: %d, "
"falling back to polling\n", ret);
polling_req = true;
synaptics_i2c_reg_set(touch->client,
INTERRUPT_EN_REG, 0);
}
}
if (polling_req)
dev_dbg(&touch->client->dev,
"Using polling at rate: %d times/sec\n", scan_rate);
ret = input_register_device(touch->input);
if (ret) {
dev_err(&client->dev,
"Input device register failed: %d\n", ret);
goto err_input_free;
}
i2c_set_clientdata(client, touch);
return 0;
err_input_free:
input_free_device(touch->input);
err_mem_free:
kfree(touch);
return ret;
}
static int __devexit synaptics_i2c_remove(struct i2c_client *client)
{
struct synaptics_i2c *touch = i2c_get_clientdata(client);
if (!polling_req)
free_irq(client->irq, touch);
input_unregister_device(touch->input);
kfree(touch);
return 0;
}
static int synaptics_i2c_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct synaptics_i2c *touch = i2c_get_clientdata(client);
cancel_delayed_work_sync(&touch->dwork);
synaptics_i2c_reg_set(touch->client, DEV_CONTROL_REG, DEEP_SLEEP);
return 0;
}
static int synaptics_i2c_resume(struct device *dev)
{
int ret;
struct i2c_client *client = to_i2c_client(dev);
struct synaptics_i2c *touch = i2c_get_clientdata(client);
ret = synaptics_i2c_reset_config(client);
if (ret)
return ret;
synaptics_i2c_reschedule_work(touch,
msecs_to_jiffies(NO_DATA_SLEEP_MSECS));
return 0;
}
static int __init synaptics_i2c_init(void)
{
return i2c_add_driver(&synaptics_i2c_driver);
}
static void __exit synaptics_i2c_exit(void)
{
i2c_del_driver(&synaptics_i2c_driver);
}
