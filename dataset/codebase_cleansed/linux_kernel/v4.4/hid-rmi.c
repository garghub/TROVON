static int rmi_set_page(struct hid_device *hdev, u8 page)
{
struct rmi_data *data = hid_get_drvdata(hdev);
int retval;
data->writeReport[0] = RMI_WRITE_REPORT_ID;
data->writeReport[1] = 1;
data->writeReport[2] = 0xFF;
data->writeReport[4] = page;
retval = rmi_write_report(hdev, data->writeReport,
data->output_report_size);
if (retval != data->output_report_size) {
dev_err(&hdev->dev,
"%s: set page failed: %d.", __func__, retval);
return retval;
}
data->page = page;
return 0;
}
static int rmi_set_mode(struct hid_device *hdev, u8 mode)
{
int ret;
u8 txbuf[2] = {RMI_SET_RMI_MODE_REPORT_ID, mode};
ret = hid_hw_raw_request(hdev, RMI_SET_RMI_MODE_REPORT_ID, txbuf,
sizeof(txbuf), HID_FEATURE_REPORT, HID_REQ_SET_REPORT);
if (ret < 0) {
dev_err(&hdev->dev, "unable to set rmi mode to %d (%d)\n", mode,
ret);
return ret;
}
return 0;
}
static int rmi_write_report(struct hid_device *hdev, u8 *report, int len)
{
int ret;
ret = hid_hw_output_report(hdev, (void *)report, len);
if (ret < 0) {
dev_err(&hdev->dev, "failed to write hid report (%d)\n", ret);
return ret;
}
return ret;
}
static int rmi_read_block(struct hid_device *hdev, u16 addr, void *buf,
const int len)
{
struct rmi_data *data = hid_get_drvdata(hdev);
int ret;
int bytes_read;
int bytes_needed;
int retries;
int read_input_count;
mutex_lock(&data->page_mutex);
if (RMI_PAGE(addr) != data->page) {
ret = rmi_set_page(hdev, RMI_PAGE(addr));
if (ret < 0)
goto exit;
}
for (retries = 5; retries > 0; retries--) {
data->writeReport[0] = RMI_READ_ADDR_REPORT_ID;
data->writeReport[1] = 0;
data->writeReport[2] = addr & 0xFF;
data->writeReport[3] = (addr >> 8) & 0xFF;
data->writeReport[4] = len & 0xFF;
data->writeReport[5] = (len >> 8) & 0xFF;
set_bit(RMI_READ_REQUEST_PENDING, &data->flags);
ret = rmi_write_report(hdev, data->writeReport,
data->output_report_size);
if (ret != data->output_report_size) {
clear_bit(RMI_READ_REQUEST_PENDING, &data->flags);
dev_err(&hdev->dev,
"failed to write request output report (%d)\n",
ret);
goto exit;
}
bytes_read = 0;
bytes_needed = len;
while (bytes_read < len) {
if (!wait_event_timeout(data->wait,
test_bit(RMI_READ_DATA_PENDING, &data->flags),
msecs_to_jiffies(1000))) {
hid_warn(hdev, "%s: timeout elapsed\n",
__func__);
ret = -EAGAIN;
break;
}
read_input_count = data->readReport[1];
memcpy(buf + bytes_read, &data->readReport[2],
read_input_count < bytes_needed ?
read_input_count : bytes_needed);
bytes_read += read_input_count;
bytes_needed -= read_input_count;
clear_bit(RMI_READ_DATA_PENDING, &data->flags);
}
if (ret >= 0) {
ret = 0;
break;
}
}
exit:
clear_bit(RMI_READ_REQUEST_PENDING, &data->flags);
mutex_unlock(&data->page_mutex);
return ret;
}
static inline int rmi_read(struct hid_device *hdev, u16 addr, void *buf)
{
return rmi_read_block(hdev, addr, buf, 1);
}
static int rmi_write_block(struct hid_device *hdev, u16 addr, void *buf,
const int len)
{
struct rmi_data *data = hid_get_drvdata(hdev);
int ret;
mutex_lock(&data->page_mutex);
if (RMI_PAGE(addr) != data->page) {
ret = rmi_set_page(hdev, RMI_PAGE(addr));
if (ret < 0)
goto exit;
}
data->writeReport[0] = RMI_WRITE_REPORT_ID;
data->writeReport[1] = len;
data->writeReport[2] = addr & 0xFF;
data->writeReport[3] = (addr >> 8) & 0xFF;
memcpy(&data->writeReport[4], buf, len);
ret = rmi_write_report(hdev, data->writeReport,
data->output_report_size);
if (ret < 0) {
dev_err(&hdev->dev,
"failed to write request output report (%d)\n",
ret);
goto exit;
}
ret = 0;
exit:
mutex_unlock(&data->page_mutex);
return ret;
}
static inline int rmi_write(struct hid_device *hdev, u16 addr, void *buf)
{
return rmi_write_block(hdev, addr, buf, 1);
}
static void rmi_f11_process_touch(struct rmi_data *hdata, int slot,
u8 finger_state, u8 *touch_data)
{
int x, y, wx, wy;
int wide, major, minor;
int z;
input_mt_slot(hdata->input, slot);
input_mt_report_slot_state(hdata->input, MT_TOOL_FINGER,
finger_state == 0x01);
if (finger_state == 0x01) {
x = (touch_data[0] << 4) | (touch_data[2] & 0x0F);
y = (touch_data[1] << 4) | (touch_data[2] >> 4);
wx = touch_data[3] & 0x0F;
wy = touch_data[3] >> 4;
wide = (wx > wy);
major = max(wx, wy);
minor = min(wx, wy);
z = touch_data[4];
y = hdata->max_y - y;
input_event(hdata->input, EV_ABS, ABS_MT_POSITION_X, x);
input_event(hdata->input, EV_ABS, ABS_MT_POSITION_Y, y);
input_event(hdata->input, EV_ABS, ABS_MT_ORIENTATION, wide);
input_event(hdata->input, EV_ABS, ABS_MT_PRESSURE, z);
input_event(hdata->input, EV_ABS, ABS_MT_TOUCH_MAJOR, major);
input_event(hdata->input, EV_ABS, ABS_MT_TOUCH_MINOR, minor);
}
}
static int rmi_reset_attn_mode(struct hid_device *hdev)
{
struct rmi_data *data = hid_get_drvdata(hdev);
int ret;
ret = rmi_set_mode(hdev, RMI_MODE_ATTN_REPORTS);
if (ret)
return ret;
if (data->restore_interrupt_mask) {
ret = rmi_write(hdev, data->f01.control_base_addr + 1,
&data->interrupt_enable_mask);
if (ret) {
hid_err(hdev, "can not write F01 control register\n");
return ret;
}
}
return 0;
}
static void rmi_reset_work(struct work_struct *work)
{
struct rmi_data *hdata = container_of(work, struct rmi_data,
reset_work);
rmi_reset_attn_mode(hdata->hdev);
}
static inline int rmi_schedule_reset(struct hid_device *hdev)
{
struct rmi_data *hdata = hid_get_drvdata(hdev);
return schedule_work(&hdata->reset_work);
}
static int rmi_f11_input_event(struct hid_device *hdev, u8 irq, u8 *data,
int size)
{
struct rmi_data *hdata = hid_get_drvdata(hdev);
int offset;
int i;
if (!(irq & hdata->f11.irq_mask) || size <= 0)
return 0;
offset = (hdata->max_fingers >> 2) + 1;
for (i = 0; i < hdata->max_fingers; i++) {
int fs_byte_position = i >> 2;
int fs_bit_position = (i & 0x3) << 1;
int finger_state = (data[fs_byte_position] >> fs_bit_position) &
0x03;
int position = offset + 5 * i;
if (position + 5 > size) {
printk_once(KERN_WARNING
"%s %s: Detected incomplete finger report. Finger reports may occasionally get dropped on this platform.\n",
dev_driver_string(&hdev->dev),
dev_name(&hdev->dev));
hid_dbg(hdev, "Incomplete finger report\n");
break;
}
rmi_f11_process_touch(hdata, i, finger_state, &data[position]);
}
input_mt_sync_frame(hdata->input);
input_sync(hdata->input);
return hdata->f11.report_size;
}
static int rmi_f30_input_event(struct hid_device *hdev, u8 irq, u8 *data,
int size)
{
struct rmi_data *hdata = hid_get_drvdata(hdev);
int i;
int button = 0;
bool value;
if (!(irq & hdata->f30.irq_mask))
return 0;
if (size < (int)hdata->f30.report_size) {
hid_warn(hdev, "Click Button pressed, but the click data is missing\n");
return 0;
}
for (i = 0; i < hdata->gpio_led_count; i++) {
if (test_bit(i, &hdata->button_mask)) {
value = (data[i / 8] >> (i & 0x07)) & BIT(0);
if (test_bit(i, &hdata->button_state_mask))
value = !value;
input_event(hdata->input, EV_KEY, BTN_LEFT + button++,
value);
}
}
return hdata->f30.report_size;
}
static int rmi_input_event(struct hid_device *hdev, u8 *data, int size)
{
struct rmi_data *hdata = hid_get_drvdata(hdev);
unsigned long irq_mask = 0;
unsigned index = 2;
if (!(test_bit(RMI_STARTED, &hdata->flags)))
return 0;
irq_mask |= hdata->f11.irq_mask;
irq_mask |= hdata->f30.irq_mask;
if (data[1] & ~irq_mask)
hid_dbg(hdev, "unknown intr source:%02lx %s:%d\n",
data[1] & ~irq_mask, __FILE__, __LINE__);
if (hdata->f11.interrupt_base < hdata->f30.interrupt_base) {
index += rmi_f11_input_event(hdev, data[1], &data[index],
size - index);
index += rmi_f30_input_event(hdev, data[1], &data[index],
size - index);
} else {
index += rmi_f30_input_event(hdev, data[1], &data[index],
size - index);
index += rmi_f11_input_event(hdev, data[1], &data[index],
size - index);
}
return 1;
}
static int rmi_read_data_event(struct hid_device *hdev, u8 *data, int size)
{
struct rmi_data *hdata = hid_get_drvdata(hdev);
if (!test_bit(RMI_READ_REQUEST_PENDING, &hdata->flags)) {
hid_dbg(hdev, "no read request pending\n");
return 0;
}
memcpy(hdata->readReport, data, size < hdata->input_report_size ?
size : hdata->input_report_size);
set_bit(RMI_READ_DATA_PENDING, &hdata->flags);
wake_up(&hdata->wait);
return 1;
}
static int rmi_check_sanity(struct hid_device *hdev, u8 *data, int size)
{
int valid_size = size;
while ((data[valid_size - 1] == 0xff) && valid_size > 0)
valid_size--;
return valid_size;
}
static int rmi_raw_event(struct hid_device *hdev,
struct hid_report *report, u8 *data, int size)
{
size = rmi_check_sanity(hdev, data, size);
if (size < 2)
return 0;
switch (data[0]) {
case RMI_READ_DATA_REPORT_ID:
return rmi_read_data_event(hdev, data, size);
case RMI_ATTN_REPORT_ID:
return rmi_input_event(hdev, data, size);
default:
return 1;
}
return 0;
}
static int rmi_event(struct hid_device *hdev, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
struct rmi_data *data = hid_get_drvdata(hdev);
if ((data->device_flags & RMI_DEVICE) &&
(field->application == HID_GD_POINTER ||
field->application == HID_GD_MOUSE)) {
if (data->device_flags & RMI_DEVICE_HAS_PHYS_BUTTONS) {
if ((usage->hid & HID_USAGE_PAGE) == HID_UP_BUTTON)
return 0;
if ((usage->hid == HID_GD_X || usage->hid == HID_GD_Y)
&& !value)
return 1;
}
rmi_schedule_reset(hdev);
return 1;
}
return 0;
}
static int rmi_set_sleep_mode(struct hid_device *hdev, int sleep_mode)
{
struct rmi_data *data = hid_get_drvdata(hdev);
int ret;
u8 f01_ctrl0;
f01_ctrl0 = (data->f01_ctrl0 & ~0x3) | sleep_mode;
ret = rmi_write(hdev, data->f01.control_base_addr,
&f01_ctrl0);
if (ret) {
hid_err(hdev, "can not write sleep mode\n");
return ret;
}
return 0;
}
static int rmi_suspend(struct hid_device *hdev, pm_message_t message)
{
struct rmi_data *data = hid_get_drvdata(hdev);
int ret;
u8 buf[RMI_F11_CTRL_REG_COUNT];
ret = rmi_read_block(hdev, data->f11.control_base_addr, buf,
RMI_F11_CTRL_REG_COUNT);
if (ret)
hid_warn(hdev, "can not read F11 control registers\n");
else
memcpy(data->f11_ctrl_regs, buf, RMI_F11_CTRL_REG_COUNT);
if (!device_may_wakeup(hdev->dev.parent))
return rmi_set_sleep_mode(hdev, RMI_SLEEP_DEEP_SLEEP);
return 0;
}
static int rmi_post_reset(struct hid_device *hdev)
{
struct rmi_data *data = hid_get_drvdata(hdev);
int ret;
ret = rmi_reset_attn_mode(hdev);
if (ret) {
hid_err(hdev, "can not set rmi mode\n");
return ret;
}
if (data->read_f11_ctrl_regs) {
ret = rmi_write_block(hdev, data->f11.control_base_addr,
data->f11_ctrl_regs, RMI_F11_CTRL_REG_COUNT);
if (ret)
hid_warn(hdev,
"can not write F11 control registers after reset\n");
}
if (!device_may_wakeup(hdev->dev.parent)) {
ret = rmi_set_sleep_mode(hdev, RMI_SLEEP_NORMAL);
if (ret) {
hid_err(hdev, "can not write sleep mode\n");
return ret;
}
}
return ret;
}
static int rmi_post_resume(struct hid_device *hdev)
{
return rmi_reset_attn_mode(hdev);
}
static inline unsigned long rmi_gen_mask(unsigned irq_base, unsigned irq_count)
{
return GENMASK(irq_count + irq_base - 1, irq_base);
}
static void rmi_register_function(struct rmi_data *data,
struct pdt_entry *pdt_entry, int page, unsigned interrupt_count)
{
struct rmi_function *f = NULL;
u16 page_base = page << 8;
switch (pdt_entry->function_number) {
case 0x01:
f = &data->f01;
break;
case 0x11:
f = &data->f11;
break;
case 0x30:
f = &data->f30;
break;
}
if (f) {
f->page = page;
f->query_base_addr = page_base | pdt_entry->query_base_addr;
f->command_base_addr = page_base | pdt_entry->command_base_addr;
f->control_base_addr = page_base | pdt_entry->control_base_addr;
f->data_base_addr = page_base | pdt_entry->data_base_addr;
f->interrupt_base = interrupt_count;
f->interrupt_count = pdt_entry->interrupt_source_count;
f->irq_mask = rmi_gen_mask(f->interrupt_base,
f->interrupt_count);
data->interrupt_enable_mask |= f->irq_mask;
}
}
static int rmi_scan_pdt(struct hid_device *hdev)
{
struct rmi_data *data = hid_get_drvdata(hdev);
struct pdt_entry entry;
int page;
bool page_has_function;
int i;
int retval;
int interrupt = 0;
u16 page_start, pdt_start , pdt_end;
hid_info(hdev, "Scanning PDT...\n");
for (page = 0; (page <= RMI4_MAX_PAGE); page++) {
page_start = RMI4_PAGE_SIZE * page;
pdt_start = page_start + PDT_START_SCAN_LOCATION;
pdt_end = page_start + PDT_END_SCAN_LOCATION;
page_has_function = false;
for (i = pdt_start; i >= pdt_end; i -= sizeof(entry)) {
retval = rmi_read_block(hdev, i, &entry, sizeof(entry));
if (retval) {
hid_err(hdev,
"Read of PDT entry at %#06x failed.\n",
i);
goto error_exit;
}
if (RMI4_END_OF_PDT(entry.function_number))
break;
page_has_function = true;
hid_info(hdev, "Found F%02X on page %#04x\n",
entry.function_number, page);
rmi_register_function(data, &entry, page, interrupt);
interrupt += entry.interrupt_source_count;
}
if (!page_has_function)
break;
}
hid_info(hdev, "%s: Done with PDT scan.\n", __func__);
retval = 0;
error_exit:
return retval;
}
static int rmi_populate_f01(struct hid_device *hdev)
{
struct rmi_data *data = hid_get_drvdata(hdev);
u8 basic_queries[RMI_DEVICE_F01_BASIC_QUERY_LEN];
u8 info[3];
int ret;
bool has_query42;
bool has_lts;
bool has_sensor_id;
bool has_ds4_queries = false;
bool has_build_id_query = false;
bool has_package_id_query = false;
u16 query_offset = data->f01.query_base_addr;
u16 prod_info_addr;
u8 ds4_query_len;
ret = rmi_read_block(hdev, query_offset, basic_queries,
RMI_DEVICE_F01_BASIC_QUERY_LEN);
if (ret) {
hid_err(hdev, "Can not read basic queries from Function 0x1.\n");
return ret;
}
has_lts = !!(basic_queries[0] & BIT(2));
has_sensor_id = !!(basic_queries[1] & BIT(3));
has_query42 = !!(basic_queries[1] & BIT(7));
query_offset += 11;
prod_info_addr = query_offset + 6;
query_offset += 10;
if (has_lts)
query_offset += 20;
if (has_sensor_id)
query_offset++;
if (has_query42) {
ret = rmi_read(hdev, query_offset, info);
if (ret) {
hid_err(hdev, "Can not read query42.\n");
return ret;
}
has_ds4_queries = !!(info[0] & BIT(0));
query_offset++;
}
if (has_ds4_queries) {
ret = rmi_read(hdev, query_offset, &ds4_query_len);
if (ret) {
hid_err(hdev, "Can not read DS4 Query length.\n");
return ret;
}
query_offset++;
if (ds4_query_len > 0) {
ret = rmi_read(hdev, query_offset, info);
if (ret) {
hid_err(hdev, "Can not read DS4 query.\n");
return ret;
}
has_package_id_query = !!(info[0] & BIT(0));
has_build_id_query = !!(info[0] & BIT(1));
}
}
if (has_package_id_query)
prod_info_addr++;
if (has_build_id_query) {
ret = rmi_read_block(hdev, prod_info_addr, info, 3);
if (ret) {
hid_err(hdev, "Can not read product info.\n");
return ret;
}
data->firmware_id = info[1] << 8 | info[0];
data->firmware_id += info[2] * 65536;
}
ret = rmi_read_block(hdev, data->f01.control_base_addr, info,
2);
if (ret) {
hid_err(hdev, "can not read f01 ctrl registers\n");
return ret;
}
data->f01_ctrl0 = info[0];
if (!info[1]) {
data->restore_interrupt_mask = true;
ret = rmi_write(hdev, data->f01.control_base_addr + 1,
&data->interrupt_enable_mask);
if (ret) {
hid_err(hdev, "can not write to control reg 1: %d.\n",
ret);
return ret;
}
}
return 0;
}
static int rmi_populate_f11(struct hid_device *hdev)
{
struct rmi_data *data = hid_get_drvdata(hdev);
u8 buf[20];
int ret;
bool has_query9;
bool has_query10 = false;
bool has_query11;
bool has_query12;
bool has_query27;
bool has_query28;
bool has_query36 = false;
bool has_physical_props;
bool has_gestures;
bool has_rel;
bool has_data40 = false;
bool has_dribble = false;
bool has_palm_detect = false;
unsigned x_size, y_size;
u16 query_offset;
if (!data->f11.query_base_addr) {
hid_err(hdev, "No 2D sensor found, giving up.\n");
return -ENODEV;
}
ret = rmi_read(hdev, data->f11.query_base_addr, buf);
if (ret) {
hid_err(hdev, "can not get query 0: %d.\n", ret);
return ret;
}
has_query9 = !!(buf[0] & BIT(3));
has_query11 = !!(buf[0] & BIT(4));
has_query12 = !!(buf[0] & BIT(5));
has_query27 = !!(buf[0] & BIT(6));
has_query28 = !!(buf[0] & BIT(7));
ret = rmi_read(hdev, data->f11.query_base_addr + 1, buf);
if (ret) {
hid_err(hdev, "can not get NumberOfFingers: %d.\n", ret);
return ret;
}
data->max_fingers = (buf[0] & 0x07) + 1;
if (data->max_fingers > 5)
data->max_fingers = 10;
data->f11.report_size = data->max_fingers * 5 +
DIV_ROUND_UP(data->max_fingers, 4);
if (!(buf[0] & BIT(4))) {
hid_err(hdev, "No absolute events, giving up.\n");
return -ENODEV;
}
has_rel = !!(buf[0] & BIT(3));
has_gestures = !!(buf[0] & BIT(5));
ret = rmi_read(hdev, data->f11.query_base_addr + 5, buf);
if (ret) {
hid_err(hdev, "can not get absolute data sources: %d.\n", ret);
return ret;
}
has_dribble = !!(buf[0] & BIT(4));
query_offset = 6;
if (has_rel)
++query_offset;
if (has_gestures) {
ret = rmi_read(hdev,
data->f11.query_base_addr + query_offset + 1, buf);
if (ret) {
hid_err(hdev, "can not read gesture information: %d.\n",
ret);
return ret;
}
has_palm_detect = !!(buf[0] & BIT(0));
has_query10 = !!(buf[0] & BIT(2));
query_offset += 2;
}
if (has_query9)
++query_offset;
if (has_query10)
++query_offset;
if (has_query11)
++query_offset;
if (has_query12) {
ret = rmi_read(hdev, data->f11.query_base_addr
+ query_offset, buf);
if (ret) {
hid_err(hdev, "can not get query 12: %d.\n", ret);
return ret;
}
has_physical_props = !!(buf[0] & BIT(5));
if (has_physical_props) {
query_offset += 1;
ret = rmi_read_block(hdev,
data->f11.query_base_addr
+ query_offset, buf, 4);
if (ret) {
hid_err(hdev, "can not read query 15-18: %d.\n",
ret);
return ret;
}
x_size = buf[0] | (buf[1] << 8);
y_size = buf[2] | (buf[3] << 8);
data->x_size_mm = DIV_ROUND_CLOSEST(x_size, 10);
data->y_size_mm = DIV_ROUND_CLOSEST(y_size, 10);
hid_info(hdev, "%s: size in mm: %d x %d\n",
__func__, data->x_size_mm, data->y_size_mm);
query_offset += 12;
}
}
if (has_query27)
++query_offset;
if (has_query28) {
ret = rmi_read(hdev, data->f11.query_base_addr
+ query_offset, buf);
if (ret) {
hid_err(hdev, "can not get query 28: %d.\n", ret);
return ret;
}
has_query36 = !!(buf[0] & BIT(6));
}
if (has_query36) {
query_offset += 2;
ret = rmi_read(hdev, data->f11.query_base_addr
+ query_offset, buf);
if (ret) {
hid_err(hdev, "can not get query 36: %d.\n", ret);
return ret;
}
has_data40 = !!(buf[0] & BIT(5));
}
if (has_data40)
data->f11.report_size += data->max_fingers * 2;
ret = rmi_read_block(hdev, data->f11.control_base_addr,
data->f11_ctrl_regs, RMI_F11_CTRL_REG_COUNT);
if (ret) {
hid_err(hdev, "can not read ctrl block of size 11: %d.\n", ret);
return ret;
}
data->read_f11_ctrl_regs = true;
data->max_x = data->f11_ctrl_regs[6] | (data->f11_ctrl_regs[7] << 8);
data->max_y = data->f11_ctrl_regs[8] | (data->f11_ctrl_regs[9] << 8);
if (has_dribble) {
data->f11_ctrl_regs[0] = data->f11_ctrl_regs[0] & ~BIT(6);
ret = rmi_write(hdev, data->f11.control_base_addr,
data->f11_ctrl_regs);
if (ret) {
hid_err(hdev, "can not write to control reg 0: %d.\n",
ret);
return ret;
}
}
if (has_palm_detect) {
data->f11_ctrl_regs[11] = data->f11_ctrl_regs[11] & ~BIT(0);
ret = rmi_write(hdev, data->f11.control_base_addr + 11,
&data->f11_ctrl_regs[11]);
if (ret) {
hid_err(hdev, "can not write to control reg 11: %d.\n",
ret);
return ret;
}
}
return 0;
}
static int rmi_populate_f30(struct hid_device *hdev)
{
struct rmi_data *data = hid_get_drvdata(hdev);
u8 buf[20];
int ret;
bool has_gpio, has_led;
unsigned bytes_per_ctrl;
u8 ctrl2_addr;
int ctrl2_3_length;
int i;
if (!data->f30.query_base_addr) {
hid_err(hdev, "No GPIO/LEDs found, giving up.\n");
return -ENODEV;
}
ret = rmi_read_block(hdev, data->f30.query_base_addr, buf, 2);
if (ret) {
hid_err(hdev, "can not get F30 query registers: %d.\n", ret);
return ret;
}
has_gpio = !!(buf[0] & BIT(3));
has_led = !!(buf[0] & BIT(2));
data->gpio_led_count = buf[1] & 0x1f;
bytes_per_ctrl = (data->gpio_led_count + 7) / 8;
ctrl2_addr = (has_gpio && has_led) ? bytes_per_ctrl : 0;
ctrl2_addr += bytes_per_ctrl;
ctrl2_3_length = 2 * bytes_per_ctrl;
data->f30.report_size = bytes_per_ctrl;
ret = rmi_read_block(hdev, data->f30.control_base_addr + ctrl2_addr,
buf, ctrl2_3_length);
if (ret) {
hid_err(hdev, "can not read ctrl 2&3 block of size %d: %d.\n",
ctrl2_3_length, ret);
return ret;
}
for (i = 0; i < data->gpio_led_count; i++) {
int byte_position = i >> 3;
int bit_position = i & 0x07;
u8 dir_byte = buf[byte_position];
u8 data_byte = buf[byte_position + bytes_per_ctrl];
bool dir = (dir_byte >> bit_position) & BIT(0);
bool dat = (data_byte >> bit_position) & BIT(0);
if (dir == 0) {
if (dat) {
data->button_count++;
set_bit(i, &data->button_mask);
set_bit(i, &data->button_state_mask);
}
}
}
return 0;
}
static int rmi_populate(struct hid_device *hdev)
{
struct rmi_data *data = hid_get_drvdata(hdev);
int ret;
ret = rmi_scan_pdt(hdev);
if (ret) {
hid_err(hdev, "PDT scan failed with code %d.\n", ret);
return ret;
}
ret = rmi_populate_f01(hdev);
if (ret) {
hid_err(hdev, "Error while initializing F01 (%d).\n", ret);
return ret;
}
ret = rmi_populate_f11(hdev);
if (ret) {
hid_err(hdev, "Error while initializing F11 (%d).\n", ret);
return ret;
}
if (!(data->device_flags & RMI_DEVICE_HAS_PHYS_BUTTONS)) {
ret = rmi_populate_f30(hdev);
if (ret)
hid_warn(hdev, "Error while initializing F30 (%d).\n", ret);
}
return 0;
}
static int rmi_input_configured(struct hid_device *hdev, struct hid_input *hi)
{
struct rmi_data *data = hid_get_drvdata(hdev);
struct input_dev *input = hi->input;
int ret;
int res_x, res_y, i;
data->input = input;
hid_dbg(hdev, "Opening low level driver\n");
ret = hid_hw_open(hdev);
if (ret)
return ret;
if (!(data->device_flags & RMI_DEVICE))
return 0;
hid_device_io_start(hdev);
ret = rmi_set_mode(hdev, RMI_MODE_ATTN_REPORTS);
if (ret < 0) {
dev_err(&hdev->dev, "failed to set rmi mode\n");
goto exit;
}
ret = rmi_set_page(hdev, 0);
if (ret < 0) {
dev_err(&hdev->dev, "failed to set page select to 0.\n");
goto exit;
}
ret = rmi_populate(hdev);
if (ret)
goto exit;
hid_info(hdev, "firmware id: %ld\n", data->firmware_id);
__set_bit(EV_ABS, input->evbit);
input_set_abs_params(input, ABS_MT_POSITION_X, 1, data->max_x, 0, 0);
input_set_abs_params(input, ABS_MT_POSITION_Y, 1, data->max_y, 0, 0);
if (data->x_size_mm && data->y_size_mm) {
res_x = (data->max_x - 1) / data->x_size_mm;
res_y = (data->max_y - 1) / data->y_size_mm;
input_abs_set_res(input, ABS_MT_POSITION_X, res_x);
input_abs_set_res(input, ABS_MT_POSITION_Y, res_y);
}
input_set_abs_params(input, ABS_MT_ORIENTATION, 0, 1, 0, 0);
input_set_abs_params(input, ABS_MT_PRESSURE, 0, 0xff, 0, 0);
input_set_abs_params(input, ABS_MT_TOUCH_MAJOR, 0, 0x0f, 0, 0);
input_set_abs_params(input, ABS_MT_TOUCH_MINOR, 0, 0x0f, 0, 0);
ret = input_mt_init_slots(input, data->max_fingers, INPUT_MT_POINTER);
if (ret < 0)
goto exit;
if (data->button_count) {
__set_bit(EV_KEY, input->evbit);
for (i = 0; i < data->button_count; i++)
__set_bit(BTN_LEFT + i, input->keybit);
if (data->button_count == 1)
__set_bit(INPUT_PROP_BUTTONPAD, input->propbit);
}
set_bit(RMI_STARTED, &data->flags);
exit:
hid_device_io_stop(hdev);
hid_hw_close(hdev);
return ret;
}
static int rmi_input_mapping(struct hid_device *hdev,
struct hid_input *hi, struct hid_field *field,
struct hid_usage *usage, unsigned long **bit, int *max)
{
struct rmi_data *data = hid_get_drvdata(hdev);
if (data->device_flags & RMI_DEVICE) {
if ((data->device_flags & RMI_DEVICE_HAS_PHYS_BUTTONS) &&
((usage->hid & HID_USAGE_PAGE) == HID_UP_BUTTON))
return 0;
return -1;
}
return 0;
}
static int rmi_check_valid_report_id(struct hid_device *hdev, unsigned type,
unsigned id, struct hid_report **report)
{
int i;
*report = hdev->report_enum[type].report_id_hash[id];
if (*report) {
for (i = 0; i < (*report)->maxfield; i++) {
unsigned app = (*report)->field[i]->application;
if ((app & HID_USAGE_PAGE) >= HID_UP_MSVENDOR)
return 1;
}
}
return 0;
}
static int rmi_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
struct rmi_data *data = NULL;
int ret;
size_t alloc_size;
struct hid_report *input_report;
struct hid_report *output_report;
struct hid_report *feature_report;
data = devm_kzalloc(&hdev->dev, sizeof(struct rmi_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
INIT_WORK(&data->reset_work, rmi_reset_work);
data->hdev = hdev;
hid_set_drvdata(hdev, data);
hdev->quirks |= HID_QUIRK_NO_INIT_REPORTS;
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
return ret;
}
if (id->driver_data)
data->device_flags = id->driver_data;
if (!rmi_check_valid_report_id(hdev, HID_FEATURE_REPORT,
RMI_SET_RMI_MODE_REPORT_ID, &feature_report)) {
hid_dbg(hdev, "device does not have set mode feature report\n");
goto start;
}
if (!rmi_check_valid_report_id(hdev, HID_INPUT_REPORT,
RMI_ATTN_REPORT_ID, &input_report)) {
hid_dbg(hdev, "device does not have attention input report\n");
goto start;
}
data->input_report_size = hid_report_len(input_report);
if (!rmi_check_valid_report_id(hdev, HID_OUTPUT_REPORT,
RMI_WRITE_REPORT_ID, &output_report)) {
hid_dbg(hdev,
"device does not have rmi write output report\n");
goto start;
}
data->output_report_size = hid_report_len(output_report);
data->device_flags |= RMI_DEVICE;
alloc_size = data->output_report_size + data->input_report_size;
data->writeReport = devm_kzalloc(&hdev->dev, alloc_size, GFP_KERNEL);
if (!data->writeReport) {
ret = -ENOMEM;
return ret;
}
data->readReport = data->writeReport + data->output_report_size;
init_waitqueue_head(&data->wait);
mutex_init(&data->page_mutex);
start:
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (ret) {
hid_err(hdev, "hw start failed\n");
return ret;
}
if ((data->device_flags & RMI_DEVICE) &&
!test_bit(RMI_STARTED, &data->flags))
hid_err(hdev, "Device failed to be properly configured\n");
return 0;
}
static void rmi_remove(struct hid_device *hdev)
{
struct rmi_data *hdata = hid_get_drvdata(hdev);
clear_bit(RMI_STARTED, &hdata->flags);
hid_hw_stop(hdev);
}
