static int synaptics_rmi4_set_page(struct synaptics_rmi4_data *pdata,
unsigned int address)
{
unsigned char txbuf[PAGE_LEN];
int retval;
unsigned int page;
struct i2c_client *i2c = pdata->i2c_client;
page = ((address >> 8) & MASK_8BIT);
if (page != pdata->current_page) {
txbuf[0] = MASK_8BIT;
txbuf[1] = page;
retval = i2c_master_send(i2c, txbuf, PAGE_LEN);
if (retval != PAGE_LEN)
dev_err(&i2c->dev, "%s:failed:%d\n", __func__, retval);
else
pdata->current_page = page;
} else
retval = PAGE_LEN;
return retval;
}
static int synaptics_rmi4_i2c_block_read(struct synaptics_rmi4_data *pdata,
unsigned short address,
unsigned char *valp, int size)
{
int retval = 0;
int retry_count = 0;
int index;
struct i2c_client *i2c = pdata->i2c_client;
mutex_lock(&(pdata->rmi4_page_mutex));
retval = synaptics_rmi4_set_page(pdata, address);
if (retval != PAGE_LEN)
goto exit;
index = address & MASK_8BIT;
retry:
retval = i2c_smbus_read_i2c_block_data(i2c, index, size, valp);
if (retval != size) {
if (++retry_count == MAX_RETRY_COUNT)
dev_err(&i2c->dev,
"%s:address 0x%04x size %d failed:%d\n",
__func__, address, size, retval);
else {
synaptics_rmi4_set_page(pdata, address);
goto retry;
}
}
exit:
mutex_unlock(&(pdata->rmi4_page_mutex));
return retval;
}
static int synaptics_rmi4_i2c_byte_write(struct synaptics_rmi4_data *pdata,
unsigned short address,
unsigned char data)
{
unsigned char txbuf[2];
int retval = 0;
struct i2c_client *i2c = pdata->i2c_client;
mutex_lock(&(pdata->rmi4_page_mutex));
retval = synaptics_rmi4_set_page(pdata, address);
if (retval != PAGE_LEN)
goto exit;
txbuf[0] = address & MASK_8BIT;
txbuf[1] = data;
retval = i2c_master_send(pdata->i2c_client, txbuf, 2);
if (retval != 2) {
dev_err(&i2c->dev, "%s:failed:%d\n", __func__, retval);
retval = -EIO;
} else
retval = 1;
exit:
mutex_unlock(&(pdata->rmi4_page_mutex));
return retval;
}
static int synpatics_rmi4_touchpad_report(struct synaptics_rmi4_data *pdata,
struct synaptics_rmi4_fn *rfi)
{
int touch_count = 0;
int finger;
int finger_registers;
int reg;
int finger_shift;
int finger_status;
int retval;
int x, y;
int wx, wy;
unsigned short data_base_addr;
unsigned short data_offset;
unsigned char data_reg_blk_size;
unsigned char values[2];
unsigned char data[DATA_LEN];
unsigned char fingers_supported = pdata->fingers_supported;
struct i2c_client *client = pdata->i2c_client;
struct input_dev *input_dev = pdata->input_dev;
finger_registers = (fingers_supported + 3)/4;
data_base_addr = rfi->fn_desc.data_base_addr;
retval = synaptics_rmi4_i2c_block_read(pdata, data_base_addr, values,
finger_registers);
if (retval != finger_registers) {
dev_err(&client->dev, "%s:read status registers failed\n",
__func__);
return 0;
}
data_reg_blk_size = rfi->size_of_data_register_block;
for (finger = 0; finger < fingers_supported; finger++) {
reg = finger/4;
finger_shift = (finger % 4) * 2;
finger_status = (values[reg] >> finger_shift) & 3;
input_mt_slot(input_dev, finger);
input_mt_report_slot_state(input_dev, MT_TOOL_FINGER,
finger_status != 0);
if (finger_status) {
data_offset = data_base_addr +
((finger * data_reg_blk_size) +
finger_registers);
retval = synaptics_rmi4_i2c_block_read(pdata,
data_offset, data,
data_reg_blk_size);
if (retval != data_reg_blk_size) {
dev_err(&client->dev, "%s:read data failed\n",
__func__);
return 0;
}
x = (data[0] << 4) | (data[2] & MASK_4BIT);
y = (data[1] << 4) | ((data[2] >> 4) & MASK_4BIT);
wy = (data[3] >> 4) & MASK_4BIT;
wx = (data[3] & MASK_4BIT);
if (pdata->board->x_flip)
x = pdata->sensor_max_x - x;
if (pdata->board->y_flip)
y = pdata->sensor_max_y - y;
input_report_abs(input_dev, ABS_MT_TOUCH_MAJOR,
max(wx, wy));
input_report_abs(input_dev, ABS_MT_POSITION_X, x);
input_report_abs(input_dev, ABS_MT_POSITION_Y, y);
touch_count++;
}
}
input_mt_sync_frame(input_dev);
input_sync(input_dev);
return touch_count;
}
static int synaptics_rmi4_report_device(struct synaptics_rmi4_data *pdata,
struct synaptics_rmi4_fn *rfi)
{
int touch = 0;
struct i2c_client *client = pdata->i2c_client;
static int num_error_reports;
if (rfi->fn_number != SYNAPTICS_RMI4_TOUCHPAD_FUNC_NUM) {
num_error_reports++;
if (num_error_reports < MAX_ERROR_REPORT)
dev_err(&client->dev, "%s:report not supported\n",
__func__);
} else
touch = synpatics_rmi4_touchpad_report(pdata, rfi);
return touch;
}
static int synaptics_rmi4_sensor_report(struct synaptics_rmi4_data *pdata)
{
unsigned char intr_status[4];
int touch = 0;
unsigned int retval;
struct synaptics_rmi4_fn *rfi;
struct synaptics_rmi4_device_info *rmi;
struct i2c_client *client = pdata->i2c_client;
retval = synaptics_rmi4_i2c_block_read(pdata,
pdata->fn01_data_base_addr + 1,
intr_status,
pdata->number_of_interrupt_register);
if (retval != pdata->number_of_interrupt_register) {
dev_err(&client->dev,
"could not read interrupt status registers\n");
return 0;
}
rmi = &(pdata->rmi4_mod_info);
list_for_each_entry(rfi, &rmi->support_fn_list, link) {
if (rfi->num_of_data_sources) {
if (intr_status[rfi->index_to_intr_reg] &
rfi->intr_mask)
touch = synaptics_rmi4_report_device(pdata,
rfi);
}
}
return touch;
}
static irqreturn_t synaptics_rmi4_irq(int irq, void *data)
{
struct synaptics_rmi4_data *pdata = data;
int touch_count;
do {
touch_count = synaptics_rmi4_sensor_report(pdata);
if (touch_count)
wait_event_timeout(pdata->wait, pdata->touch_stopped,
msecs_to_jiffies(1));
else
break;
} while (!pdata->touch_stopped);
return IRQ_HANDLED;
}
static int synpatics_rmi4_touchpad_detect(struct synaptics_rmi4_data *pdata,
struct synaptics_rmi4_fn *rfi,
struct synaptics_rmi4_fn_desc *fd,
unsigned int interruptcount)
{
unsigned char queries[QUERY_LEN];
unsigned short intr_offset;
unsigned char abs_data_size;
unsigned char abs_data_blk_size;
unsigned char egr_0, egr_1;
unsigned int all_data_blk_size;
int has_pinch, has_flick, has_tap;
int has_tapandhold, has_doubletap;
int has_earlytap, has_press;
int has_palmdetect, has_rotate;
int has_rel;
int i;
int retval;
struct i2c_client *client = pdata->i2c_client;
rfi->fn_desc.query_base_addr = fd->query_base_addr;
rfi->fn_desc.data_base_addr = fd->data_base_addr;
rfi->fn_desc.intr_src_count = fd->intr_src_count;
rfi->fn_desc.fn_number = fd->fn_number;
rfi->fn_number = fd->fn_number;
rfi->num_of_data_sources = fd->intr_src_count;
rfi->fn_desc.ctrl_base_addr = fd->ctrl_base_addr;
rfi->fn_desc.cmd_base_addr = fd->cmd_base_addr;
retval = synaptics_rmi4_i2c_block_read(pdata, fd->query_base_addr,
queries,
sizeof(queries));
if (retval != sizeof(queries)) {
dev_err(&client->dev, "%s:read function query registers\n",
__func__);
return retval;
}
if ((queries[1] & MASK_3BIT) <= 4)
rfi->num_of_data_points = (queries[1] & MASK_3BIT) + 1;
else {
if ((queries[1] & MASK_3BIT) == 5)
rfi->num_of_data_points = 10;
}
pdata->fingers_supported = rfi->num_of_data_points;
rfi->index_to_intr_reg = (interruptcount + 7)/8;
if (rfi->index_to_intr_reg != 0)
rfi->index_to_intr_reg -= 1;
intr_offset = interruptcount % 8;
rfi->intr_mask = 0;
for (i = intr_offset;
i < ((fd->intr_src_count & MASK_3BIT) + intr_offset); i++)
rfi->intr_mask |= 1 << i;
abs_data_size = queries[5] & MASK_2BIT;
abs_data_blk_size = 3 + (2 * (abs_data_size == 0 ? 1 : 0));
rfi->size_of_data_register_block = abs_data_blk_size;
egr_0 = queries[7];
egr_1 = queries[8];
has_pinch = egr_0 & HAS_PINCH;
has_flick = egr_0 & HAS_FLICK;
has_tap = egr_0 & HAS_TAP;
has_earlytap = egr_0 & HAS_EARLYTAP;
has_press = egr_0 & HAS_PRESS;
has_rotate = egr_1 & HAS_ROTATE;
has_rel = queries[1] & HAS_RELEASE;
has_tapandhold = egr_0 & HAS_TAPANDHOLD;
has_doubletap = egr_0 & HAS_DOUBLETAP;
has_palmdetect = egr_1 & HAS_PALMDETECT;
all_data_blk_size =
((rfi->num_of_data_points + 3) / 4) +
(abs_data_blk_size * rfi->num_of_data_points) +
2 * has_rel +
!!(egr_0) +
(egr_0 || egr_1) +
!!(has_pinch | has_flick) +
2 * !!(has_flick);
return retval;
}
static int synaptics_rmi4_touchpad_config(struct synaptics_rmi4_data *pdata,
struct synaptics_rmi4_fn *rfi)
{
unsigned char data[BUF_LEN];
int retval = 0;
struct i2c_client *client = pdata->i2c_client;
retval = synaptics_rmi4_i2c_block_read(pdata,
rfi->fn_desc.query_base_addr,
data, QUERY_LEN);
if (retval != QUERY_LEN)
dev_err(&client->dev, "%s:read query registers failed\n",
__func__);
else {
retval = synaptics_rmi4_i2c_block_read(pdata,
rfi->fn_desc.ctrl_base_addr,
data, DATA_BUF_LEN);
if (retval != DATA_BUF_LEN) {
dev_err(&client->dev,
"%s:read control registers failed\n",
__func__);
return retval;
}
pdata->sensor_max_x = ((data[6] & MASK_8BIT) << 0) |
((data[7] & MASK_4BIT) << 8);
pdata->sensor_max_y = ((data[8] & MASK_5BIT) << 0) |
((data[9] & MASK_4BIT) << 8);
}
return retval;
}
static int synaptics_rmi4_i2c_query_device(struct synaptics_rmi4_data *pdata)
{
int i;
int retval;
unsigned char std_queries[STD_QUERY_LEN];
unsigned char intr_count = 0;
int data_sources = 0;
unsigned int ctrl_offset;
struct synaptics_rmi4_fn *rfi;
struct synaptics_rmi4_fn_desc rmi_fd;
struct synaptics_rmi4_device_info *rmi;
struct i2c_client *client = pdata->i2c_client;
INIT_LIST_HEAD(&pdata->rmi4_mod_info.support_fn_list);
for (i = PDT_START_SCAN_LOCATION; i > PDT_END_SCAN_LOCATION;
i -= PDT_ENTRY_SIZE) {
retval = synaptics_rmi4_i2c_block_read(pdata, i,
(unsigned char *)&rmi_fd,
sizeof(rmi_fd));
if (retval != sizeof(rmi_fd)) {
dev_err(&client->dev, "%s: read error\n", __func__);
return -EIO;
}
rfi = NULL;
if (rmi_fd.fn_number) {
switch (rmi_fd.fn_number & MASK_8BIT) {
case SYNAPTICS_RMI4_DEVICE_CONTROL_FUNC_NUM:
pdata->fn01_query_base_addr =
rmi_fd.query_base_addr;
pdata->fn01_ctrl_base_addr =
rmi_fd.ctrl_base_addr;
pdata->fn01_data_base_addr =
rmi_fd.data_base_addr;
break;
case SYNAPTICS_RMI4_TOUCHPAD_FUNC_NUM:
if (rmi_fd.intr_src_count) {
rfi = kmalloc(sizeof(*rfi),
GFP_KERNEL);
if (!rfi)
return -ENOMEM;
retval = synpatics_rmi4_touchpad_detect
(pdata, rfi,
&rmi_fd,
intr_count);
if (retval < 0) {
kfree(rfi);
return retval;
}
}
break;
}
intr_count += (rmi_fd.intr_src_count & MASK_3BIT);
if (rfi && rmi_fd.intr_src_count) {
mutex_lock(&(pdata->fn_list_mutex));
list_add_tail(&rfi->link,
&pdata->rmi4_mod_info.support_fn_list);
mutex_unlock(&(pdata->fn_list_mutex));
}
} else {
dev_dbg(&client->dev,
"%s:end of PDT\n", __func__);
break;
}
}
pdata->number_of_interrupt_register = (intr_count + 7) / 8;
retval = synaptics_rmi4_i2c_block_read(pdata,
pdata->fn01_query_base_addr,
std_queries,
sizeof(std_queries));
if (retval != sizeof(std_queries)) {
dev_err(&client->dev, "%s:Failed reading queries\n",
__func__);
return -EIO;
}
pdata->rmi4_mod_info.version_major = 4;
pdata->rmi4_mod_info.version_minor = 0;
pdata->rmi4_mod_info.manufacturer_id = std_queries[0];
pdata->rmi4_mod_info.product_props = std_queries[1];
pdata->rmi4_mod_info.product_info[0] = std_queries[2];
pdata->rmi4_mod_info.product_info[1] = std_queries[3];
pdata->rmi4_mod_info.date_code[0] = std_queries[4] & MASK_5BIT;
pdata->rmi4_mod_info.date_code[1] = std_queries[5] & MASK_4BIT;
pdata->rmi4_mod_info.date_code[2] = std_queries[6] & MASK_5BIT;
pdata->rmi4_mod_info.tester_id = ((std_queries[7] & MASK_7BIT) << 8) |
(std_queries[8] & MASK_7BIT);
pdata->rmi4_mod_info.serial_number =
((std_queries[9] & MASK_7BIT) << 8) |
(std_queries[10] & MASK_7BIT);
memcpy(pdata->rmi4_mod_info.product_id_string, &std_queries[11], 10);
if (pdata->rmi4_mod_info.manufacturer_id != 1)
dev_err(&client->dev, "%s: non-Synaptics mfg id:%d\n",
__func__, pdata->rmi4_mod_info.manufacturer_id);
list_for_each_entry(rfi, &pdata->rmi4_mod_info.support_fn_list, link)
data_sources += rfi->num_of_data_sources;
if (data_sources) {
rmi = &(pdata->rmi4_mod_info);
list_for_each_entry(rfi, &rmi->support_fn_list, link) {
if (rfi->num_of_data_sources) {
if (rfi->fn_number ==
SYNAPTICS_RMI4_TOUCHPAD_FUNC_NUM) {
retval = synaptics_rmi4_touchpad_config
(pdata, rfi);
if (retval < 0)
return retval;
} else
dev_err(&client->dev,
"%s:fn_number not supported\n",
__func__);
ctrl_offset = pdata->fn01_ctrl_base_addr + 1 +
rfi->index_to_intr_reg;
retval = synaptics_rmi4_i2c_byte_write(pdata,
ctrl_offset,
rfi->intr_mask);
if (retval < 0)
return retval;
}
}
}
return 0;
}
static int synaptics_rmi4_probe
(struct i2c_client *client, const struct i2c_device_id *dev_id)
{
int retval;
unsigned char intr_status[4];
struct synaptics_rmi4_data *rmi4_data;
const struct synaptics_rmi4_platform_data *platformdata =
client->dev.platform_data;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(&client->dev, "i2c smbus byte data not supported\n");
return -EIO;
}
if (!platformdata)
platformdata = &synaptics_rmi4_platformdata;
rmi4_data = kcalloc(2, sizeof(struct synaptics_rmi4_data),
GFP_KERNEL);
if (!rmi4_data)
return -ENOMEM;
rmi4_data->input_dev = input_allocate_device();
if (rmi4_data->input_dev == NULL) {
retval = -ENOMEM;
goto err_input;
}
rmi4_data->regulator = regulator_get(&client->dev, "vdd");
if (IS_ERR(rmi4_data->regulator)) {
dev_err(&client->dev, "%s:get regulator failed\n",
__func__);
retval = PTR_ERR(rmi4_data->regulator);
goto err_get_regulator;
}
retval = regulator_enable(rmi4_data->regulator);
if (retval < 0) {
dev_err(&client->dev, "%s:regulator enable failed\n",
__func__);
goto err_regulator_enable;
}
init_waitqueue_head(&rmi4_data->wait);
rmi4_data->i2c_client = client;
rmi4_data->current_page = MASK_16BIT;
rmi4_data->board = platformdata;
rmi4_data->touch_stopped = false;
mutex_init(&(rmi4_data->fn_list_mutex));
mutex_init(&(rmi4_data->rmi4_page_mutex));
retval = synaptics_rmi4_i2c_query_device(rmi4_data);
if (retval) {
dev_err(&client->dev, "%s: rmi4 query device failed\n",
__func__);
goto err_query_dev;
}
i2c_set_clientdata(client, rmi4_data);
rmi4_data->input_dev->name = DRIVER_NAME;
rmi4_data->input_dev->phys = "Synaptics_Clearpad";
rmi4_data->input_dev->id.bustype = BUS_I2C;
rmi4_data->input_dev->dev.parent = &client->dev;
input_set_drvdata(rmi4_data->input_dev, rmi4_data);
set_bit(EV_SYN, rmi4_data->input_dev->evbit);
set_bit(EV_KEY, rmi4_data->input_dev->evbit);
set_bit(EV_ABS, rmi4_data->input_dev->evbit);
input_set_abs_params(rmi4_data->input_dev, ABS_MT_POSITION_X, 0,
rmi4_data->sensor_max_x, 0, 0);
input_set_abs_params(rmi4_data->input_dev, ABS_MT_POSITION_Y, 0,
rmi4_data->sensor_max_y, 0, 0);
input_set_abs_params(rmi4_data->input_dev, ABS_MT_TOUCH_MAJOR, 0,
MAX_TOUCH_MAJOR, 0, 0);
input_mt_init_slots(rmi4_data->input_dev,
rmi4_data->fingers_supported, 0);
synaptics_rmi4_i2c_block_read(rmi4_data,
rmi4_data->fn01_data_base_addr + 1, intr_status,
rmi4_data->number_of_interrupt_register);
retval = request_threaded_irq(client->irq, NULL,
synaptics_rmi4_irq,
platformdata->irq_type,
DRIVER_NAME, rmi4_data);
if (retval) {
dev_err(&client->dev, "%s:Unable to get attn irq %d\n",
__func__, client->irq);
goto err_query_dev;
}
retval = input_register_device(rmi4_data->input_dev);
if (retval) {
dev_err(&client->dev, "%s:input register failed\n", __func__);
goto err_free_irq;
}
return retval;
err_free_irq:
free_irq(client->irq, rmi4_data);
err_query_dev:
regulator_disable(rmi4_data->regulator);
err_regulator_enable:
regulator_put(rmi4_data->regulator);
err_get_regulator:
input_free_device(rmi4_data->input_dev);
rmi4_data->input_dev = NULL;
err_input:
kfree(rmi4_data);
return retval;
}
static int synaptics_rmi4_remove(struct i2c_client *client)
{
struct synaptics_rmi4_data *rmi4_data = i2c_get_clientdata(client);
rmi4_data->touch_stopped = true;
wake_up(&rmi4_data->wait);
free_irq(client->irq, rmi4_data);
input_unregister_device(rmi4_data->input_dev);
regulator_disable(rmi4_data->regulator);
regulator_put(rmi4_data->regulator);
kfree(rmi4_data);
return 0;
}
static int synaptics_rmi4_suspend(struct device *dev)
{
int retval;
unsigned char intr_status;
struct synaptics_rmi4_data *rmi4_data = dev_get_drvdata(dev);
rmi4_data->touch_stopped = true;
disable_irq(rmi4_data->i2c_client->irq);
retval = synaptics_rmi4_i2c_block_read(rmi4_data,
rmi4_data->fn01_data_base_addr + 1,
&intr_status,
rmi4_data->number_of_interrupt_register);
if (retval < 0)
return retval;
retval = synaptics_rmi4_i2c_byte_write(rmi4_data,
rmi4_data->fn01_ctrl_base_addr + 1,
(intr_status & ~TOUCHPAD_CTRL_INTR));
if (retval < 0)
return retval;
regulator_disable(rmi4_data->regulator);
return 0;
}
static int synaptics_rmi4_resume(struct device *dev)
{
int retval;
unsigned char intr_status;
struct synaptics_rmi4_data *rmi4_data = dev_get_drvdata(dev);
retval = regulator_enable(rmi4_data->regulator);
if (retval) {
dev_err(dev, "Regulator enable failed (%d)\n", retval);
return retval;
}
enable_irq(rmi4_data->i2c_client->irq);
rmi4_data->touch_stopped = false;
retval = synaptics_rmi4_i2c_block_read(rmi4_data,
rmi4_data->fn01_data_base_addr + 1,
&intr_status,
rmi4_data->number_of_interrupt_register);
if (retval < 0)
return retval;
retval = synaptics_rmi4_i2c_byte_write(rmi4_data,
rmi4_data->fn01_ctrl_base_addr + 1,
(intr_status | TOUCHPAD_CTRL_INTR));
if (retval < 0)
return retval;
return 0;
}
