static void qt2160_led_work(struct work_struct *work)
{
struct qt2160_led *led = container_of(work, struct qt2160_led, work);
struct qt2160_data *qt2160 = led->qt2160;
struct i2c_client *client = qt2160->client;
int value = led->new_brightness;
u32 drive, pwmen;
mutex_lock(&qt2160->led_lock);
drive = qt2160_read(client, QT2160_CMD_DRIVE_X);
pwmen = qt2160_read(client, QT2160_CMD_PWMEN_X);
if (value != LED_OFF) {
drive |= (1 << led->id);
pwmen |= (1 << led->id);
} else {
drive &= ~(1 << led->id);
pwmen &= ~(1 << led->id);
}
qt2160_write(client, QT2160_CMD_DRIVE_X, drive);
qt2160_write(client, QT2160_CMD_PWMEN_X, pwmen);
if (value != LED_OFF)
qt2160_write(client, QT2160_CMD_PWM_DUTY, value);
mutex_unlock(&qt2160->led_lock);
}
static void qt2160_led_set(struct led_classdev *cdev,
enum led_brightness value)
{
struct qt2160_led *led = container_of(cdev, struct qt2160_led, cdev);
led->new_brightness = value;
schedule_work(&led->work);
}
static int qt2160_read_block(struct i2c_client *client,
u8 inireg, u8 *buffer, unsigned int count)
{
int error, idx = 0;
if (i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
error = i2c_smbus_write_byte(client, inireg + idx);
if (error) {
dev_err(&client->dev,
"couldn't send request. Returned %d\n", error);
return error;
}
error = i2c_master_recv(client, buffer, count);
if (error != count) {
dev_err(&client->dev,
"couldn't read registers. Returned %d bytes\n", error);
return error;
}
} else {
while (count--) {
int data;
error = i2c_smbus_write_byte(client, inireg + idx);
if (error) {
dev_err(&client->dev,
"couldn't send request. Returned %d\n", error);
return error;
}
data = i2c_smbus_read_byte(client);
if (data < 0) {
dev_err(&client->dev,
"couldn't read register. Returned %d\n", data);
return data;
}
buffer[idx++] = data;
}
}
return 0;
}
static int qt2160_get_key_matrix(struct qt2160_data *qt2160)
{
struct i2c_client *client = qt2160->client;
struct input_dev *input = qt2160->input;
u8 regs[6];
u16 old_matrix, new_matrix;
int ret, i, mask;
dev_dbg(&client->dev, "requesting keys...\n");
ret = qt2160_read_block(client, QT2160_CMD_GSTAT, regs, 6);
if (ret) {
dev_err(&client->dev,
"could not perform chip read.\n");
return ret;
}
old_matrix = qt2160->key_matrix;
qt2160->key_matrix = new_matrix = (regs[2] << 8) | regs[1];
mask = 0x01;
for (i = 0; i < 16; ++i, mask <<= 1) {
int keyval = new_matrix & mask;
if ((old_matrix & mask) != keyval) {
input_report_key(input, qt2160->keycodes[i], keyval);
dev_dbg(&client->dev, "key %d %s\n",
i, keyval ? "pressed" : "released");
}
}
input_sync(input);
return 0;
}
static irqreturn_t qt2160_irq(int irq, void *_qt2160)
{
struct qt2160_data *qt2160 = _qt2160;
unsigned long flags;
spin_lock_irqsave(&qt2160->lock, flags);
mod_delayed_work(system_wq, &qt2160->dwork, 0);
spin_unlock_irqrestore(&qt2160->lock, flags);
return IRQ_HANDLED;
}
static void qt2160_schedule_read(struct qt2160_data *qt2160)
{
spin_lock_irq(&qt2160->lock);
schedule_delayed_work(&qt2160->dwork, QT2160_CYCLE_INTERVAL);
spin_unlock_irq(&qt2160->lock);
}
static void qt2160_worker(struct work_struct *work)
{
struct qt2160_data *qt2160 =
container_of(work, struct qt2160_data, dwork.work);
dev_dbg(&qt2160->client->dev, "worker\n");
qt2160_get_key_matrix(qt2160);
qt2160_schedule_read(qt2160);
}
static int qt2160_read(struct i2c_client *client, u8 reg)
{
int ret;
ret = i2c_smbus_write_byte(client, reg);
if (ret) {
dev_err(&client->dev,
"couldn't send request. Returned %d\n", ret);
return ret;
}
ret = i2c_smbus_read_byte(client);
if (ret < 0) {
dev_err(&client->dev,
"couldn't read register. Returned %d\n", ret);
return ret;
}
return ret;
}
static int qt2160_write(struct i2c_client *client, u8 reg, u8 data)
{
int ret;
ret = i2c_smbus_write_byte_data(client, reg, data);
if (ret < 0)
dev_err(&client->dev,
"couldn't write data. Returned %d\n", ret);
return ret;
}
static int qt2160_register_leds(struct qt2160_data *qt2160)
{
struct i2c_client *client = qt2160->client;
int ret;
int i;
mutex_init(&qt2160->led_lock);
for (i = 0; i < QT2160_NUM_LEDS_X; i++) {
struct qt2160_led *led = &qt2160->leds[i];
snprintf(led->name, sizeof(led->name), "qt2160:x%d", i);
led->cdev.name = led->name;
led->cdev.brightness_set = qt2160_led_set;
led->cdev.brightness = LED_OFF;
led->id = i;
led->qt2160 = qt2160;
INIT_WORK(&led->work, qt2160_led_work);
ret = led_classdev_register(&client->dev, &led->cdev);
if (ret < 0)
return ret;
}
qt2160_write(client, QT2160_CMD_DRIVE_X, 0);
qt2160_write(client, QT2160_CMD_PWMEN_X, 0);
qt2160_write(client, QT2160_CMD_PWM_DUTY, 0);
return 0;
}
static void qt2160_unregister_leds(struct qt2160_data *qt2160)
{
int i;
for (i = 0; i < QT2160_NUM_LEDS_X; i++) {
led_classdev_unregister(&qt2160->leds[i].cdev);
cancel_work_sync(&qt2160->leds[i].work);
}
}
static inline int qt2160_register_leds(struct qt2160_data *qt2160)
{
return 0;
}
static inline void qt2160_unregister_leds(struct qt2160_data *qt2160)
{
}
static bool qt2160_identify(struct i2c_client *client)
{
int id, ver, rev;
id = qt2160_read(client, QT2160_CMD_CHIPID);
if (id != QT2160_VALID_CHIPID) {
dev_err(&client->dev, "ID %d not supported\n", id);
return false;
}
ver = qt2160_read(client, QT2160_CMD_CODEVER);
if (ver < 0) {
dev_err(&client->dev, "could not get firmware version\n");
return false;
}
rev = qt2160_read(client, QT2160_CMD_SUBVER);
if (rev < 0) {
dev_err(&client->dev, "could not get firmware revision\n");
return false;
}
dev_info(&client->dev, "AT42QT2160 firmware version %d.%d.%d\n",
ver >> 4, ver & 0xf, rev);
return true;
}
static int qt2160_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct qt2160_data *qt2160;
struct input_dev *input;
int i;
int error;
error = i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE);
if (!error) {
dev_err(&client->dev, "%s adapter not supported\n",
dev_driver_string(&client->adapter->dev));
return -ENODEV;
}
if (!qt2160_identify(client))
return -ENODEV;
qt2160 = kzalloc(sizeof(struct qt2160_data), GFP_KERNEL);
input = input_allocate_device();
if (!qt2160 || !input) {
dev_err(&client->dev, "insufficient memory\n");
error = -ENOMEM;
goto err_free_mem;
}
qt2160->client = client;
qt2160->input = input;
INIT_DELAYED_WORK(&qt2160->dwork, qt2160_worker);
spin_lock_init(&qt2160->lock);
input->name = "AT42QT2160 Touch Sense Keyboard";
input->id.bustype = BUS_I2C;
input->keycode = qt2160->keycodes;
input->keycodesize = sizeof(qt2160->keycodes[0]);
input->keycodemax = ARRAY_SIZE(qt2160_key2code);
__set_bit(EV_KEY, input->evbit);
__clear_bit(EV_REP, input->evbit);
for (i = 0; i < ARRAY_SIZE(qt2160_key2code); i++) {
qt2160->keycodes[i] = qt2160_key2code[i];
__set_bit(qt2160_key2code[i], input->keybit);
}
__clear_bit(KEY_RESERVED, input->keybit);
error = qt2160_write(client, QT2160_CMD_CALIBRATE, 1);
if (error) {
dev_err(&client->dev, "failed to calibrate device\n");
goto err_free_mem;
}
if (client->irq) {
error = request_irq(client->irq, qt2160_irq,
IRQF_TRIGGER_FALLING, "qt2160", qt2160);
if (error) {
dev_err(&client->dev,
"failed to allocate irq %d\n", client->irq);
goto err_free_mem;
}
}
error = qt2160_register_leds(qt2160);
if (error) {
dev_err(&client->dev, "Failed to register leds\n");
goto err_free_irq;
}
error = input_register_device(qt2160->input);
if (error) {
dev_err(&client->dev,
"Failed to register input device\n");
goto err_unregister_leds;
}
i2c_set_clientdata(client, qt2160);
qt2160_schedule_read(qt2160);
return 0;
err_unregister_leds:
qt2160_unregister_leds(qt2160);
err_free_irq:
if (client->irq)
free_irq(client->irq, qt2160);
err_free_mem:
input_free_device(input);
kfree(qt2160);
return error;
}
static int qt2160_remove(struct i2c_client *client)
{
struct qt2160_data *qt2160 = i2c_get_clientdata(client);
qt2160_unregister_leds(qt2160);
if (client->irq)
free_irq(client->irq, qt2160);
cancel_delayed_work_sync(&qt2160->dwork);
input_unregister_device(qt2160->input);
kfree(qt2160);
return 0;
}
