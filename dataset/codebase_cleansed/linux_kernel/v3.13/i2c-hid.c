static int __i2c_hid_command(struct i2c_client *client,
const struct i2c_hid_cmd *command, u8 reportID,
u8 reportType, u8 *args, int args_len,
unsigned char *buf_recv, int data_len)
{
struct i2c_hid *ihid = i2c_get_clientdata(client);
union command *cmd = (union command *)ihid->cmdbuf;
int ret;
struct i2c_msg msg[2];
int msg_num = 1;
int length = command->length;
bool wait = command->wait;
unsigned int registerIndex = command->registerIndex;
if (command == &hid_descr_cmd) {
cmd->c.reg = ihid->wHIDDescRegister;
} else {
cmd->data[0] = ihid->hdesc_buffer[registerIndex];
cmd->data[1] = ihid->hdesc_buffer[registerIndex + 1];
}
if (length > 2) {
cmd->c.opcode = command->opcode;
cmd->c.reportTypeID = reportID | reportType << 4;
}
memcpy(cmd->data + length, args, args_len);
length += args_len;
i2c_hid_dbg(ihid, "%s: cmd=%*ph\n", __func__, length, cmd->data);
msg[0].addr = client->addr;
msg[0].flags = client->flags & I2C_M_TEN;
msg[0].len = length;
msg[0].buf = cmd->data;
if (data_len > 0) {
msg[1].addr = client->addr;
msg[1].flags = client->flags & I2C_M_TEN;
msg[1].flags |= I2C_M_RD;
msg[1].len = data_len;
msg[1].buf = buf_recv;
msg_num = 2;
set_bit(I2C_HID_READ_PENDING, &ihid->flags);
}
if (wait)
set_bit(I2C_HID_RESET_PENDING, &ihid->flags);
ret = i2c_transfer(client->adapter, msg, msg_num);
if (data_len > 0)
clear_bit(I2C_HID_READ_PENDING, &ihid->flags);
if (ret != msg_num)
return ret < 0 ? ret : -EIO;
ret = 0;
if (wait) {
i2c_hid_dbg(ihid, "%s: waiting...\n", __func__);
if (!wait_event_timeout(ihid->wait,
!test_bit(I2C_HID_RESET_PENDING, &ihid->flags),
msecs_to_jiffies(5000)))
ret = -ENODATA;
i2c_hid_dbg(ihid, "%s: finished.\n", __func__);
}
return ret;
}
static int i2c_hid_command(struct i2c_client *client,
const struct i2c_hid_cmd *command,
unsigned char *buf_recv, int data_len)
{
return __i2c_hid_command(client, command, 0, 0, NULL, 0,
buf_recv, data_len);
}
static int i2c_hid_get_report(struct i2c_client *client, u8 reportType,
u8 reportID, unsigned char *buf_recv, int data_len)
{
struct i2c_hid *ihid = i2c_get_clientdata(client);
u8 args[3];
int ret;
int args_len = 0;
u16 readRegister = le16_to_cpu(ihid->hdesc.wDataRegister);
i2c_hid_dbg(ihid, "%s\n", __func__);
if (reportID >= 0x0F) {
args[args_len++] = reportID;
reportID = 0x0F;
}
args[args_len++] = readRegister & 0xFF;
args[args_len++] = readRegister >> 8;
ret = __i2c_hid_command(client, &hid_get_report_cmd, reportID,
reportType, args, args_len, buf_recv, data_len);
if (ret) {
dev_err(&client->dev,
"failed to retrieve report from device.\n");
return ret;
}
return 0;
}
static int i2c_hid_set_report(struct i2c_client *client, u8 reportType,
u8 reportID, unsigned char *buf, size_t data_len)
{
struct i2c_hid *ihid = i2c_get_clientdata(client);
u8 *args = ihid->argsbuf;
const struct i2c_hid_cmd * hidcmd = &hid_set_report_cmd;
int ret;
u16 dataRegister = le16_to_cpu(ihid->hdesc.wDataRegister);
u16 outputRegister = le16_to_cpu(ihid->hdesc.wOutputRegister);
u16 maxOutputLength = le16_to_cpu(ihid->hdesc.wMaxOutputLength);
u16 size = 2 +
(reportID ? 1 : 0) +
data_len ;
int args_len = (reportID >= 0x0F ? 1 : 0) +
2 +
size ;
int index = 0;
i2c_hid_dbg(ihid, "%s\n", __func__);
if (reportID >= 0x0F) {
args[index++] = reportID;
reportID = 0x0F;
}
if (reportType == 0x03 || maxOutputLength == 0) {
args[index++] = dataRegister & 0xFF;
args[index++] = dataRegister >> 8;
} else {
args[index++] = outputRegister & 0xFF;
args[index++] = outputRegister >> 8;
hidcmd = &hid_no_cmd;
}
args[index++] = size & 0xFF;
args[index++] = size >> 8;
if (reportID)
args[index++] = reportID;
memcpy(&args[index], buf, data_len);
ret = __i2c_hid_command(client, hidcmd, reportID,
reportType, args, args_len, NULL, 0);
if (ret) {
dev_err(&client->dev, "failed to set a report to device.\n");
return ret;
}
return data_len;
}
static int i2c_hid_set_power(struct i2c_client *client, int power_state)
{
struct i2c_hid *ihid = i2c_get_clientdata(client);
int ret;
i2c_hid_dbg(ihid, "%s\n", __func__);
ret = __i2c_hid_command(client, &hid_set_power_cmd, power_state,
0, NULL, 0, NULL, 0);
if (ret)
dev_err(&client->dev, "failed to change power setting.\n");
return ret;
}
static int i2c_hid_hwreset(struct i2c_client *client)
{
struct i2c_hid *ihid = i2c_get_clientdata(client);
int ret;
i2c_hid_dbg(ihid, "%s\n", __func__);
ret = i2c_hid_set_power(client, I2C_HID_PWR_ON);
if (ret)
return ret;
i2c_hid_dbg(ihid, "resetting...\n");
ret = i2c_hid_command(client, &hid_reset_cmd, NULL, 0);
if (ret) {
dev_err(&client->dev, "failed to reset device.\n");
i2c_hid_set_power(client, I2C_HID_PWR_SLEEP);
return ret;
}
return 0;
}
static void i2c_hid_get_input(struct i2c_hid *ihid)
{
int ret, ret_size;
int size = le16_to_cpu(ihid->hdesc.wMaxInputLength);
ret = i2c_master_recv(ihid->client, ihid->inbuf, size);
if (ret != size) {
if (ret < 0)
return;
dev_err(&ihid->client->dev, "%s: got %d data instead of %d\n",
__func__, ret, size);
return;
}
ret_size = ihid->inbuf[0] | ihid->inbuf[1] << 8;
if (!ret_size) {
if (test_and_clear_bit(I2C_HID_RESET_PENDING, &ihid->flags))
wake_up(&ihid->wait);
return;
}
if (ret_size > size) {
dev_err(&ihid->client->dev, "%s: incomplete report (%d/%d)\n",
__func__, size, ret_size);
return;
}
i2c_hid_dbg(ihid, "input: %*ph\n", ret_size, ihid->inbuf);
if (test_bit(I2C_HID_STARTED, &ihid->flags))
hid_input_report(ihid->hid, HID_INPUT_REPORT, ihid->inbuf + 2,
ret_size - 2, 1);
return;
}
static irqreturn_t i2c_hid_irq(int irq, void *dev_id)
{
struct i2c_hid *ihid = dev_id;
if (test_bit(I2C_HID_READ_PENDING, &ihid->flags))
return IRQ_HANDLED;
i2c_hid_get_input(ihid);
return IRQ_HANDLED;
}
static int i2c_hid_get_report_length(struct hid_report *report)
{
return ((report->size - 1) >> 3) + 1 +
report->device->report_enum[report->type].numbered + 2;
}
static void i2c_hid_init_report(struct hid_report *report, u8 *buffer,
size_t bufsize)
{
struct hid_device *hid = report->device;
struct i2c_client *client = hid->driver_data;
struct i2c_hid *ihid = i2c_get_clientdata(client);
unsigned int size, ret_size;
size = i2c_hid_get_report_length(report);
if (i2c_hid_get_report(client,
report->type == HID_FEATURE_REPORT ? 0x03 : 0x01,
report->id, buffer, size))
return;
i2c_hid_dbg(ihid, "report (len=%d): %*ph\n", size, size, ihid->inbuf);
ret_size = buffer[0] | (buffer[1] << 8);
if (ret_size != size) {
dev_err(&client->dev, "error in %s size:%d / ret_size:%d\n",
__func__, size, ret_size);
return;
}
hid_report_raw_event(hid, report->type, buffer + 2, size - 2, 1);
}
static void i2c_hid_init_reports(struct hid_device *hid)
{
struct hid_report *report;
struct i2c_client *client = hid->driver_data;
struct i2c_hid *ihid = i2c_get_clientdata(client);
u8 *inbuf = kzalloc(ihid->bufsize, GFP_KERNEL);
if (!inbuf) {
dev_err(&client->dev, "can not retrieve initial reports\n");
return;
}
list_for_each_entry(report,
&hid->report_enum[HID_FEATURE_REPORT].report_list, list)
i2c_hid_init_report(report, inbuf, ihid->bufsize);
kfree(inbuf);
}
static void i2c_hid_find_max_report(struct hid_device *hid, unsigned int type,
unsigned int *max)
{
struct hid_report *report;
unsigned int size;
list_for_each_entry(report, &hid->report_enum[type].report_list, list) {
size = i2c_hid_get_report_length(report);
if (*max < size)
*max = size;
}
}
static void i2c_hid_free_buffers(struct i2c_hid *ihid)
{
kfree(ihid->inbuf);
kfree(ihid->argsbuf);
kfree(ihid->cmdbuf);
ihid->inbuf = NULL;
ihid->cmdbuf = NULL;
ihid->argsbuf = NULL;
ihid->bufsize = 0;
}
static int i2c_hid_alloc_buffers(struct i2c_hid *ihid, size_t report_size)
{
int args_len = sizeof(__u8) +
sizeof(__u16) +
sizeof(__u16) +
report_size;
ihid->inbuf = kzalloc(report_size, GFP_KERNEL);
ihid->argsbuf = kzalloc(args_len, GFP_KERNEL);
ihid->cmdbuf = kzalloc(sizeof(union command) + args_len, GFP_KERNEL);
if (!ihid->inbuf || !ihid->argsbuf || !ihid->cmdbuf) {
i2c_hid_free_buffers(ihid);
return -ENOMEM;
}
ihid->bufsize = report_size;
return 0;
}
static int i2c_hid_get_raw_report(struct hid_device *hid,
unsigned char report_number, __u8 *buf, size_t count,
unsigned char report_type)
{
struct i2c_client *client = hid->driver_data;
struct i2c_hid *ihid = i2c_get_clientdata(client);
size_t ret_count, ask_count;
int ret;
if (report_type == HID_OUTPUT_REPORT)
return -EINVAL;
ask_count = min(count + 2, (size_t)ihid->bufsize);
ret = i2c_hid_get_report(client,
report_type == HID_FEATURE_REPORT ? 0x03 : 0x01,
report_number, ihid->inbuf, ask_count);
if (ret < 0)
return ret;
ret_count = ihid->inbuf[0] | (ihid->inbuf[1] << 8);
if (ret_count <= 2)
return 0;
ret_count = min(ret_count, ask_count);
count = min(count, ret_count - 2);
memcpy(buf, ihid->inbuf + 2, count);
return count;
}
static int i2c_hid_output_raw_report(struct hid_device *hid, __u8 *buf,
size_t count, unsigned char report_type)
{
struct i2c_client *client = hid->driver_data;
int report_id = buf[0];
int ret;
if (report_type == HID_INPUT_REPORT)
return -EINVAL;
if (report_id) {
buf++;
count--;
}
ret = i2c_hid_set_report(client,
report_type == HID_FEATURE_REPORT ? 0x03 : 0x02,
report_id, buf, count);
if (report_id && ret >= 0)
ret++;
return ret;
}
static void i2c_hid_request(struct hid_device *hid, struct hid_report *rep,
int reqtype)
{
struct i2c_client *client = hid->driver_data;
char *buf;
int ret;
int len = i2c_hid_get_report_length(rep) - 2;
buf = kzalloc(len, GFP_KERNEL);
if (!buf)
return;
switch (reqtype) {
case HID_REQ_GET_REPORT:
ret = i2c_hid_get_raw_report(hid, rep->id, buf, len, rep->type);
if (ret < 0)
dev_err(&client->dev, "%s: unable to get report: %d\n",
__func__, ret);
else
hid_input_report(hid, rep->type, buf, ret, 0);
break;
case HID_REQ_SET_REPORT:
hid_output_report(rep, buf);
i2c_hid_output_raw_report(hid, buf, len, rep->type);
break;
}
kfree(buf);
}
static int i2c_hid_parse(struct hid_device *hid)
{
struct i2c_client *client = hid->driver_data;
struct i2c_hid *ihid = i2c_get_clientdata(client);
struct i2c_hid_desc *hdesc = &ihid->hdesc;
unsigned int rsize;
char *rdesc;
int ret;
int tries = 3;
i2c_hid_dbg(ihid, "entering %s\n", __func__);
rsize = le16_to_cpu(hdesc->wReportDescLength);
if (!rsize || rsize > HID_MAX_DESCRIPTOR_SIZE) {
dbg_hid("weird size of report descriptor (%u)\n", rsize);
return -EINVAL;
}
do {
ret = i2c_hid_hwreset(client);
if (ret)
msleep(1000);
} while (tries-- > 0 && ret);
if (ret)
return ret;
rdesc = kzalloc(rsize, GFP_KERNEL);
if (!rdesc) {
dbg_hid("couldn't allocate rdesc memory\n");
return -ENOMEM;
}
i2c_hid_dbg(ihid, "asking HID report descriptor\n");
ret = i2c_hid_command(client, &hid_report_descr_cmd, rdesc, rsize);
if (ret) {
hid_err(hid, "reading report descriptor failed\n");
kfree(rdesc);
return -EIO;
}
i2c_hid_dbg(ihid, "Report Descriptor: %*ph\n", rsize, rdesc);
ret = hid_parse_report(hid, rdesc, rsize);
kfree(rdesc);
if (ret) {
dbg_hid("parsing report descriptor failed\n");
return ret;
}
return 0;
}
static int i2c_hid_start(struct hid_device *hid)
{
struct i2c_client *client = hid->driver_data;
struct i2c_hid *ihid = i2c_get_clientdata(client);
int ret;
unsigned int bufsize = HID_MIN_BUFFER_SIZE;
i2c_hid_find_max_report(hid, HID_INPUT_REPORT, &bufsize);
i2c_hid_find_max_report(hid, HID_OUTPUT_REPORT, &bufsize);
i2c_hid_find_max_report(hid, HID_FEATURE_REPORT, &bufsize);
if (bufsize > ihid->bufsize) {
i2c_hid_free_buffers(ihid);
ret = i2c_hid_alloc_buffers(ihid, bufsize);
if (ret)
return ret;
}
if (!(hid->quirks & HID_QUIRK_NO_INIT_REPORTS))
i2c_hid_init_reports(hid);
return 0;
}
static void i2c_hid_stop(struct hid_device *hid)
{
struct i2c_client *client = hid->driver_data;
struct i2c_hid *ihid = i2c_get_clientdata(client);
hid->claimed = 0;
i2c_hid_free_buffers(ihid);
}
static int i2c_hid_open(struct hid_device *hid)
{
struct i2c_client *client = hid->driver_data;
struct i2c_hid *ihid = i2c_get_clientdata(client);
int ret = 0;
mutex_lock(&i2c_hid_open_mut);
if (!hid->open++) {
ret = i2c_hid_set_power(client, I2C_HID_PWR_ON);
if (ret) {
hid->open--;
goto done;
}
set_bit(I2C_HID_STARTED, &ihid->flags);
}
done:
mutex_unlock(&i2c_hid_open_mut);
return ret;
}
static void i2c_hid_close(struct hid_device *hid)
{
struct i2c_client *client = hid->driver_data;
struct i2c_hid *ihid = i2c_get_clientdata(client);
mutex_lock(&i2c_hid_open_mut);
if (!--hid->open) {
clear_bit(I2C_HID_STARTED, &ihid->flags);
i2c_hid_set_power(client, I2C_HID_PWR_SLEEP);
}
mutex_unlock(&i2c_hid_open_mut);
}
static int i2c_hid_power(struct hid_device *hid, int lvl)
{
struct i2c_client *client = hid->driver_data;
struct i2c_hid *ihid = i2c_get_clientdata(client);
int ret = 0;
i2c_hid_dbg(ihid, "%s lvl:%d\n", __func__, lvl);
switch (lvl) {
case PM_HINT_FULLON:
ret = i2c_hid_set_power(client, I2C_HID_PWR_ON);
break;
case PM_HINT_NORMAL:
ret = i2c_hid_set_power(client, I2C_HID_PWR_SLEEP);
break;
}
return ret;
}
static int i2c_hid_init_irq(struct i2c_client *client)
{
struct i2c_hid *ihid = i2c_get_clientdata(client);
int ret;
dev_dbg(&client->dev, "Requesting IRQ: %d\n", client->irq);
ret = request_threaded_irq(client->irq, NULL, i2c_hid_irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
client->name, ihid);
if (ret < 0) {
dev_warn(&client->dev,
"Could not register for %s interrupt, irq = %d,"
" ret = %d\n",
client->name, client->irq, ret);
return ret;
}
return 0;
}
static int i2c_hid_fetch_hid_descriptor(struct i2c_hid *ihid)
{
struct i2c_client *client = ihid->client;
struct i2c_hid_desc *hdesc = &ihid->hdesc;
unsigned int dsize;
int ret;
ret = i2c_hid_command(client, &hid_descr_cmd, ihid->hdesc_buffer, 4);
i2c_hid_dbg(ihid, "%s, ihid->hdesc_buffer: %4ph\n", __func__,
ihid->hdesc_buffer);
if (ret) {
dev_err(&client->dev,
"unable to fetch the size of HID descriptor (ret=%d)\n",
ret);
return -ENODEV;
}
dsize = le16_to_cpu(hdesc->wHIDDescLength);
if (dsize < 4 || dsize > sizeof(struct i2c_hid_desc)) {
dev_err(&client->dev, "weird size of HID descriptor (%u)\n",
dsize);
return -ENODEV;
}
if (le16_to_cpu(hdesc->bcdVersion) != 0x0100) {
dev_err(&client->dev,
"unexpected HID descriptor bcdVersion (0x%04hx)\n",
le16_to_cpu(hdesc->bcdVersion));
return -ENODEV;
}
i2c_hid_dbg(ihid, "Fetching the HID descriptor\n");
ret = i2c_hid_command(client, &hid_descr_cmd, ihid->hdesc_buffer,
dsize);
if (ret) {
dev_err(&client->dev, "hid_descr_cmd Fail\n");
return -ENODEV;
}
i2c_hid_dbg(ihid, "HID Descriptor: %*ph\n", dsize, ihid->hdesc_buffer);
return 0;
}
static int i2c_hid_acpi_pdata(struct i2c_client *client,
struct i2c_hid_platform_data *pdata)
{
static u8 i2c_hid_guid[] = {
0xF7, 0xF6, 0xDF, 0x3C, 0x67, 0x42, 0x55, 0x45,
0xAD, 0x05, 0xB3, 0x0A, 0x3D, 0x89, 0x38, 0xDE,
};
union acpi_object params[4];
struct acpi_object_list input;
struct acpi_device *adev;
unsigned long long value;
acpi_handle handle;
handle = ACPI_HANDLE(&client->dev);
if (!handle || acpi_bus_get_device(handle, &adev))
return -ENODEV;
input.count = ARRAY_SIZE(params);
input.pointer = params;
params[0].type = ACPI_TYPE_BUFFER;
params[0].buffer.length = sizeof(i2c_hid_guid);
params[0].buffer.pointer = i2c_hid_guid;
params[1].type = ACPI_TYPE_INTEGER;
params[1].integer.value = 1;
params[2].type = ACPI_TYPE_INTEGER;
params[2].integer.value = 1;
params[3].type = ACPI_TYPE_PACKAGE;
params[3].package.count = 0;
params[3].package.elements = NULL;
if (ACPI_FAILURE(acpi_evaluate_integer(handle, "_DSM", &input,
&value))) {
dev_err(&client->dev, "device _DSM execution failed\n");
return -ENODEV;
}
pdata->hid_descriptor_address = value;
return 0;
}
static inline int i2c_hid_acpi_pdata(struct i2c_client *client,
struct i2c_hid_platform_data *pdata)
{
return -ENODEV;
}
static int i2c_hid_of_probe(struct i2c_client *client,
struct i2c_hid_platform_data *pdata)
{
struct device *dev = &client->dev;
u32 val;
int ret;
ret = of_property_read_u32(dev->of_node, "hid-descr-addr", &val);
if (ret) {
dev_err(&client->dev, "HID register address not provided\n");
return -ENODEV;
}
if (val >> 16) {
dev_err(&client->dev, "Bad HID register address: 0x%08x\n",
val);
return -EINVAL;
}
pdata->hid_descriptor_address = val;
return 0;
}
static inline int i2c_hid_of_probe(struct i2c_client *client,
struct i2c_hid_platform_data *pdata)
{
return -ENODEV;
}
static int i2c_hid_probe(struct i2c_client *client,
const struct i2c_device_id *dev_id)
{
int ret;
struct i2c_hid *ihid;
struct hid_device *hid;
__u16 hidRegister;
struct i2c_hid_platform_data *platform_data = client->dev.platform_data;
dbg_hid("HID probe called for i2c 0x%02x\n", client->addr);
if (!client->irq) {
dev_err(&client->dev,
"HID over i2c has not been provided an Int IRQ\n");
return -EINVAL;
}
ihid = kzalloc(sizeof(struct i2c_hid), GFP_KERNEL);
if (!ihid)
return -ENOMEM;
if (client->dev.of_node) {
ret = i2c_hid_of_probe(client, &ihid->pdata);
if (ret)
goto err;
} else if (!platform_data) {
ret = i2c_hid_acpi_pdata(client, &ihid->pdata);
if (ret) {
dev_err(&client->dev,
"HID register address not provided\n");
goto err;
}
} else {
ihid->pdata = *platform_data;
}
i2c_set_clientdata(client, ihid);
ihid->client = client;
hidRegister = ihid->pdata.hid_descriptor_address;
ihid->wHIDDescRegister = cpu_to_le16(hidRegister);
init_waitqueue_head(&ihid->wait);
ret = i2c_hid_alloc_buffers(ihid, HID_MIN_BUFFER_SIZE);
if (ret < 0)
goto err;
ret = i2c_hid_fetch_hid_descriptor(ihid);
if (ret < 0)
goto err;
ret = i2c_hid_init_irq(client);
if (ret < 0)
goto err;
hid = hid_allocate_device();
if (IS_ERR(hid)) {
ret = PTR_ERR(hid);
goto err_irq;
}
ihid->hid = hid;
hid->driver_data = client;
hid->ll_driver = &i2c_hid_ll_driver;
hid->hid_get_raw_report = i2c_hid_get_raw_report;
hid->hid_output_raw_report = i2c_hid_output_raw_report;
hid->dev.parent = &client->dev;
ACPI_COMPANION_SET(&hid->dev, ACPI_COMPANION(&client->dev));
hid->bus = BUS_I2C;
hid->version = le16_to_cpu(ihid->hdesc.bcdVersion);
hid->vendor = le16_to_cpu(ihid->hdesc.wVendorID);
hid->product = le16_to_cpu(ihid->hdesc.wProductID);
snprintf(hid->name, sizeof(hid->name), "%s %04hX:%04hX",
client->name, hid->vendor, hid->product);
ret = hid_add_device(hid);
if (ret) {
if (ret != -ENODEV)
hid_err(client, "can't add hid device: %d\n", ret);
goto err_mem_free;
}
return 0;
err_mem_free:
hid_destroy_device(hid);
err_irq:
free_irq(client->irq, ihid);
err:
i2c_hid_free_buffers(ihid);
kfree(ihid);
return ret;
}
static int i2c_hid_remove(struct i2c_client *client)
{
struct i2c_hid *ihid = i2c_get_clientdata(client);
struct hid_device *hid;
hid = ihid->hid;
hid_destroy_device(hid);
free_irq(client->irq, ihid);
if (ihid->bufsize)
i2c_hid_free_buffers(ihid);
kfree(ihid);
return 0;
}
static int i2c_hid_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
if (device_may_wakeup(&client->dev))
enable_irq_wake(client->irq);
i2c_hid_set_power(client, I2C_HID_PWR_SLEEP);
return 0;
}
static int i2c_hid_resume(struct device *dev)
{
int ret;
struct i2c_client *client = to_i2c_client(dev);
ret = i2c_hid_hwreset(client);
if (ret)
return ret;
if (device_may_wakeup(&client->dev))
disable_irq_wake(client->irq);
return 0;
}
