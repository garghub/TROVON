static int silead_ts_request_input_dev(struct silead_ts_data *data)
{
struct device *dev = &data->client->dev;
int error;
data->input = devm_input_allocate_device(dev);
if (!data->input) {
dev_err(dev,
"Failed to allocate input device\n");
return -ENOMEM;
}
input_set_abs_params(data->input, ABS_MT_POSITION_X, 0, 4095, 0, 0);
input_set_abs_params(data->input, ABS_MT_POSITION_Y, 0, 4095, 0, 0);
touchscreen_parse_properties(data->input, true, &data->prop);
input_mt_init_slots(data->input, data->max_fingers,
INPUT_MT_DIRECT | INPUT_MT_DROP_UNUSED |
INPUT_MT_TRACK);
data->input->name = SILEAD_TS_NAME;
data->input->phys = "input/ts";
data->input->id.bustype = BUS_I2C;
error = input_register_device(data->input);
if (error) {
dev_err(dev, "Failed to register input device: %d\n", error);
return error;
}
return 0;
}
static void silead_ts_set_power(struct i2c_client *client,
enum silead_ts_power state)
{
struct silead_ts_data *data = i2c_get_clientdata(client);
if (data->gpio_power) {
gpiod_set_value_cansleep(data->gpio_power, state);
msleep(SILEAD_POWER_SLEEP);
}
}
static void silead_ts_read_data(struct i2c_client *client)
{
struct silead_ts_data *data = i2c_get_clientdata(client);
struct input_dev *input = data->input;
struct device *dev = &client->dev;
u8 *bufp, buf[SILEAD_TS_DATA_LEN];
int touch_nr, error, i;
error = i2c_smbus_read_i2c_block_data(client, SILEAD_REG_DATA,
SILEAD_TS_DATA_LEN, buf);
if (error < 0) {
dev_err(dev, "Data read error %d\n", error);
return;
}
touch_nr = buf[0];
if (touch_nr > data->max_fingers) {
dev_warn(dev, "More touches reported then supported %d > %d\n",
touch_nr, data->max_fingers);
touch_nr = data->max_fingers;
}
bufp = buf + SILEAD_POINT_DATA_LEN;
for (i = 0; i < touch_nr; i++, bufp += SILEAD_POINT_DATA_LEN) {
data->id[i] = (bufp[SILEAD_POINT_X_MSB_OFF] &
SILEAD_TOUCH_ID_MASK) >> 4;
touchscreen_set_mt_pos(&data->pos[i], &data->prop,
get_unaligned_le16(&bufp[SILEAD_POINT_X_OFF]) & 0xfff,
get_unaligned_le16(&bufp[SILEAD_POINT_Y_OFF]) & 0xfff);
}
input_mt_assign_slots(input, data->slots, data->pos, touch_nr, 0);
for (i = 0; i < touch_nr; i++) {
input_mt_slot(input, data->slots[i]);
input_mt_report_slot_state(input, MT_TOOL_FINGER, true);
input_report_abs(input, ABS_MT_POSITION_X, data->pos[i].x);
input_report_abs(input, ABS_MT_POSITION_Y, data->pos[i].y);
dev_dbg(dev, "x=%d y=%d hw_id=%d sw_id=%d\n", data->pos[i].x,
data->pos[i].y, data->id[i], data->slots[i]);
}
input_mt_sync_frame(input);
input_sync(input);
}
static int silead_ts_init(struct i2c_client *client)
{
struct silead_ts_data *data = i2c_get_clientdata(client);
int error;
error = i2c_smbus_write_byte_data(client, SILEAD_REG_RESET,
SILEAD_CMD_RESET);
if (error)
goto i2c_write_err;
usleep_range(SILEAD_CMD_SLEEP_MIN, SILEAD_CMD_SLEEP_MAX);
error = i2c_smbus_write_byte_data(client, SILEAD_REG_TOUCH_NR,
data->max_fingers);
if (error)
goto i2c_write_err;
usleep_range(SILEAD_CMD_SLEEP_MIN, SILEAD_CMD_SLEEP_MAX);
error = i2c_smbus_write_byte_data(client, SILEAD_REG_CLOCK,
SILEAD_CLOCK);
if (error)
goto i2c_write_err;
usleep_range(SILEAD_CMD_SLEEP_MIN, SILEAD_CMD_SLEEP_MAX);
error = i2c_smbus_write_byte_data(client, SILEAD_REG_RESET,
SILEAD_CMD_START);
if (error)
goto i2c_write_err;
usleep_range(SILEAD_CMD_SLEEP_MIN, SILEAD_CMD_SLEEP_MAX);
return 0;
i2c_write_err:
dev_err(&client->dev, "Registers clear error %d\n", error);
return error;
}
static int silead_ts_reset(struct i2c_client *client)
{
int error;
error = i2c_smbus_write_byte_data(client, SILEAD_REG_RESET,
SILEAD_CMD_RESET);
if (error)
goto i2c_write_err;
usleep_range(SILEAD_CMD_SLEEP_MIN, SILEAD_CMD_SLEEP_MAX);
error = i2c_smbus_write_byte_data(client, SILEAD_REG_CLOCK,
SILEAD_CLOCK);
if (error)
goto i2c_write_err;
usleep_range(SILEAD_CMD_SLEEP_MIN, SILEAD_CMD_SLEEP_MAX);
error = i2c_smbus_write_byte_data(client, SILEAD_REG_POWER,
SILEAD_CMD_START);
if (error)
goto i2c_write_err;
usleep_range(SILEAD_CMD_SLEEP_MIN, SILEAD_CMD_SLEEP_MAX);
return 0;
i2c_write_err:
dev_err(&client->dev, "Chip reset error %d\n", error);
return error;
}
static int silead_ts_startup(struct i2c_client *client)
{
int error;
error = i2c_smbus_write_byte_data(client, SILEAD_REG_RESET, 0x00);
if (error) {
dev_err(&client->dev, "Startup error %d\n", error);
return error;
}
msleep(SILEAD_STARTUP_SLEEP);
return 0;
}
static int silead_ts_load_fw(struct i2c_client *client)
{
struct device *dev = &client->dev;
struct silead_ts_data *data = i2c_get_clientdata(client);
unsigned int fw_size, i;
const struct firmware *fw;
struct silead_fw_data *fw_data;
int error;
dev_dbg(dev, "Firmware file name: %s", data->fw_name);
error = request_firmware(&fw, data->fw_name, dev);
if (error) {
dev_err(dev, "Firmware request error %d\n", error);
return error;
}
fw_size = fw->size / sizeof(*fw_data);
fw_data = (struct silead_fw_data *)fw->data;
for (i = 0; i < fw_size; i++) {
error = i2c_smbus_write_i2c_block_data(client,
fw_data[i].offset,
4,
(u8 *)&fw_data[i].val);
if (error) {
dev_err(dev, "Firmware load error %d\n", error);
break;
}
}
release_firmware(fw);
return error ?: 0;
}
static u32 silead_ts_get_status(struct i2c_client *client)
{
int error;
__le32 status;
error = i2c_smbus_read_i2c_block_data(client, SILEAD_REG_STATUS,
sizeof(status), (u8 *)&status);
if (error < 0) {
dev_err(&client->dev, "Status read error %d\n", error);
return error;
}
return le32_to_cpu(status);
}
static int silead_ts_get_id(struct i2c_client *client)
{
struct silead_ts_data *data = i2c_get_clientdata(client);
__le32 chip_id;
int error;
error = i2c_smbus_read_i2c_block_data(client, SILEAD_REG_ID,
sizeof(chip_id), (u8 *)&chip_id);
if (error < 0) {
dev_err(&client->dev, "Chip ID read error %d\n", error);
return error;
}
data->chip_id = le32_to_cpu(chip_id);
dev_info(&client->dev, "Silead chip ID: 0x%8X", data->chip_id);
return 0;
}
static int silead_ts_setup(struct i2c_client *client)
{
int error;
u32 status;
silead_ts_set_power(client, SILEAD_POWER_OFF);
silead_ts_set_power(client, SILEAD_POWER_ON);
error = silead_ts_get_id(client);
if (error)
return error;
error = silead_ts_init(client);
if (error)
return error;
error = silead_ts_reset(client);
if (error)
return error;
error = silead_ts_load_fw(client);
if (error)
return error;
error = silead_ts_startup(client);
if (error)
return error;
status = silead_ts_get_status(client);
if (status != SILEAD_STATUS_OK) {
dev_err(&client->dev,
"Initialization error, status: 0x%X\n", status);
return -ENODEV;
}
return 0;
}
static irqreturn_t silead_ts_threaded_irq_handler(int irq, void *id)
{
struct silead_ts_data *data = id;
struct i2c_client *client = data->client;
silead_ts_read_data(client);
return IRQ_HANDLED;
}
static void silead_ts_read_props(struct i2c_client *client)
{
struct silead_ts_data *data = i2c_get_clientdata(client);
struct device *dev = &client->dev;
const char *str;
int error;
error = device_property_read_u32(dev, "silead,max-fingers",
&data->max_fingers);
if (error) {
dev_dbg(dev, "Max fingers read error %d\n", error);
data->max_fingers = 5;
}
error = device_property_read_string(dev, "firmware-name", &str);
if (!error)
snprintf(data->fw_name, sizeof(data->fw_name),
"silead/%s", str);
else
dev_dbg(dev, "Firmware file name read error. Using default.");
}
static int silead_ts_set_default_fw_name(struct silead_ts_data *data,
const struct i2c_device_id *id)
{
const struct acpi_device_id *acpi_id;
struct device *dev = &data->client->dev;
int i;
if (ACPI_HANDLE(dev)) {
acpi_id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!acpi_id)
return -ENODEV;
snprintf(data->fw_name, sizeof(data->fw_name),
"silead/%s.fw", acpi_id->id);
for (i = 0; i < strlen(data->fw_name); i++)
data->fw_name[i] = tolower(data->fw_name[i]);
} else {
snprintf(data->fw_name, sizeof(data->fw_name),
"silead/%s.fw", id->name);
}
return 0;
}
static int silead_ts_set_default_fw_name(struct silead_ts_data *data,
const struct i2c_device_id *id)
{
snprintf(data->fw_name, sizeof(data->fw_name),
"silead/%s.fw", id->name);
return 0;
}
static int silead_ts_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct silead_ts_data *data;
struct device *dev = &client->dev;
int error;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_I2C |
I2C_FUNC_SMBUS_READ_I2C_BLOCK |
I2C_FUNC_SMBUS_WRITE_I2C_BLOCK)) {
dev_err(dev, "I2C functionality check failed\n");
return -ENXIO;
}
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
data->client = client;
error = silead_ts_set_default_fw_name(data, id);
if (error)
return error;
silead_ts_read_props(client);
if (client->irq <= 0)
return -ENODEV;
data->gpio_power = devm_gpiod_get_optional(dev, "power", GPIOD_OUT_LOW);
if (IS_ERR(data->gpio_power)) {
if (PTR_ERR(data->gpio_power) != -EPROBE_DEFER)
dev_err(dev, "Shutdown GPIO request failed\n");
return PTR_ERR(data->gpio_power);
}
error = silead_ts_setup(client);
if (error)
return error;
error = silead_ts_request_input_dev(data);
if (error)
return error;
error = devm_request_threaded_irq(dev, client->irq,
NULL, silead_ts_threaded_irq_handler,
IRQF_ONESHOT, client->name, data);
if (error) {
if (error != -EPROBE_DEFER)
dev_err(dev, "IRQ request failed %d\n", error);
return error;
}
return 0;
}
static int __maybe_unused silead_ts_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
silead_ts_set_power(client, SILEAD_POWER_OFF);
return 0;
}
static int __maybe_unused silead_ts_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
int error, status;
silead_ts_set_power(client, SILEAD_POWER_ON);
error = silead_ts_reset(client);
if (error)
return error;
error = silead_ts_startup(client);
if (error)
return error;
status = silead_ts_get_status(client);
if (status != SILEAD_STATUS_OK) {
dev_err(dev, "Resume error, status: 0x%02x\n", status);
return -ENODEV;
}
return 0;
}
