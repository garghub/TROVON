static int write8_reg(struct tpm_stm_dev *tpm_dev, u8 tpm_register,
u8 *tpm_data, u16 tpm_size)
{
tpm_dev->buf[0] = tpm_register;
memcpy(tpm_dev->buf + 1, tpm_data, tpm_size);
return i2c_master_send(tpm_dev->client, tpm_dev->buf, tpm_size + 1);
}
static int read8_reg(struct tpm_stm_dev *tpm_dev, u8 tpm_register,
u8 *tpm_data, int tpm_size)
{
u8 status = 0;
u8 data;
data = TPM_DUMMY_BYTE;
status = write8_reg(tpm_dev, tpm_register, &data, 1);
if (status == 2)
status = i2c_master_recv(tpm_dev->client, tpm_data, tpm_size);
return status;
}
static u8 clear_interruption(struct tpm_stm_dev *tpm_dev)
{
u8 interrupt;
I2C_READ_DATA(tpm_dev, TPM_INT_STATUS, &interrupt, 1);
I2C_WRITE_DATA(tpm_dev, TPM_INT_STATUS, &interrupt, 1);
return interrupt;
}
static void tpm_stm_i2c_cancel(struct tpm_chip *chip)
{
struct tpm_stm_dev *tpm_dev;
u8 data;
tpm_dev = (struct tpm_stm_dev *)TPM_VPRIV(chip);
data = TPM_STS_COMMAND_READY;
I2C_WRITE_DATA(tpm_dev, TPM_STS, &data, 1);
}
static u8 tpm_stm_i2c_status(struct tpm_chip *chip)
{
struct tpm_stm_dev *tpm_dev;
u8 data;
tpm_dev = (struct tpm_stm_dev *)TPM_VPRIV(chip);
I2C_READ_DATA(tpm_dev, TPM_STS, &data, 1);
return data;
}
static int check_locality(struct tpm_chip *chip)
{
struct tpm_stm_dev *tpm_dev;
u8 data;
u8 status;
tpm_dev = (struct tpm_stm_dev *)TPM_VPRIV(chip);
status = I2C_READ_DATA(tpm_dev, TPM_ACCESS, &data, 1);
if (status && (data &
(TPM_ACCESS_ACTIVE_LOCALITY | TPM_ACCESS_VALID)) ==
(TPM_ACCESS_ACTIVE_LOCALITY | TPM_ACCESS_VALID))
return chip->vendor.locality;
return -EACCES;
}
static int request_locality(struct tpm_chip *chip)
{
unsigned long stop;
long ret;
struct tpm_stm_dev *tpm_dev;
u8 data;
if (check_locality(chip) == chip->vendor.locality)
return chip->vendor.locality;
tpm_dev = (struct tpm_stm_dev *)TPM_VPRIV(chip);
data = TPM_ACCESS_REQUEST_USE;
ret = I2C_WRITE_DATA(tpm_dev, TPM_ACCESS, &data, 1);
if (ret < 0)
goto end;
stop = jiffies + chip->vendor.timeout_a;
do {
if (check_locality(chip) >= 0)
return chip->vendor.locality;
msleep(TPM_TIMEOUT);
} while (time_before(jiffies, stop));
ret = -EACCES;
end:
return ret;
}
static void release_locality(struct tpm_chip *chip)
{
struct tpm_stm_dev *tpm_dev;
u8 data;
tpm_dev = (struct tpm_stm_dev *)TPM_VPRIV(chip);
data = TPM_ACCESS_ACTIVE_LOCALITY;
I2C_WRITE_DATA(tpm_dev, TPM_ACCESS, &data, 1);
}
static int get_burstcount(struct tpm_chip *chip)
{
unsigned long stop;
int burstcnt, status;
u8 tpm_reg, temp;
struct tpm_stm_dev *tpm_dev;
tpm_dev = (struct tpm_stm_dev *)TPM_VPRIV(chip);
stop = jiffies + chip->vendor.timeout_d;
do {
tpm_reg = TPM_STS + 1;
status = I2C_READ_DATA(tpm_dev, tpm_reg, &temp, 1);
if (status < 0)
goto end;
tpm_reg = tpm_reg + 1;
burstcnt = temp;
status = I2C_READ_DATA(tpm_dev, tpm_reg, &temp, 1);
if (status < 0)
goto end;
burstcnt |= temp << 8;
if (burstcnt)
return burstcnt;
msleep(TPM_TIMEOUT);
} while (time_before(jiffies, stop));
end:
return -EBUSY;
}
static bool wait_for_tpm_stat_cond(struct tpm_chip *chip, u8 mask,
bool check_cancel, bool *canceled)
{
u8 status = chip->ops->status(chip);
*canceled = false;
if ((status & mask) == mask)
return true;
if (check_cancel && chip->ops->req_canceled(chip, status)) {
*canceled = true;
return true;
}
return false;
}
static u8 interrupt_to_status(u8 irq_mask)
{
u8 status = 0;
if ((irq_mask & TPM_INTF_STS_VALID_INT) == TPM_INTF_STS_VALID_INT)
status |= TPM_STS_VALID;
if ((irq_mask & TPM_INTF_DATA_AVAIL_INT) == TPM_INTF_DATA_AVAIL_INT)
status |= TPM_STS_DATA_AVAIL;
if ((irq_mask & TPM_INTF_CMD_READY_INT) == TPM_INTF_CMD_READY_INT)
status |= TPM_STS_COMMAND_READY;
return status;
}
static int wait_for_stat(struct tpm_chip *chip, u8 mask, unsigned long timeout,
wait_queue_head_t *queue, bool check_cancel)
{
unsigned long stop;
int ret;
bool canceled = false;
bool condition;
u32 cur_intrs;
u8 interrupt, status;
struct tpm_stm_dev *tpm_dev;
tpm_dev = (struct tpm_stm_dev *)TPM_VPRIV(chip);
status = tpm_stm_i2c_status(chip);
if ((status & mask) == mask)
return 0;
stop = jiffies + timeout;
if (chip->vendor.irq) {
cur_intrs = tpm_dev->intrs;
interrupt = clear_interruption(tpm_dev);
enable_irq(chip->vendor.irq);
again:
timeout = stop - jiffies;
if ((long) timeout <= 0)
return -1;
ret = wait_event_interruptible_timeout(*queue,
cur_intrs != tpm_dev->intrs, timeout);
interrupt |= clear_interruption(tpm_dev);
status = interrupt_to_status(interrupt);
condition = wait_for_tpm_stat_cond(chip, mask,
check_cancel, &canceled);
if (ret >= 0 && condition) {
if (canceled)
return -ECANCELED;
return 0;
}
if (ret == -ERESTARTSYS && freezing(current)) {
clear_thread_flag(TIF_SIGPENDING);
goto again;
}
disable_irq_nosync(chip->vendor.irq);
} else {
do {
msleep(TPM_TIMEOUT);
status = chip->ops->status(chip);
if ((status & mask) == mask)
return 0;
} while (time_before(jiffies, stop));
}
return -ETIME;
}
static int recv_data(struct tpm_chip *chip, u8 *buf, size_t count)
{
int size = 0, burstcnt, len, ret;
struct tpm_stm_dev *tpm_dev;
tpm_dev = (struct tpm_stm_dev *)TPM_VPRIV(chip);
while (size < count &&
wait_for_stat(chip,
TPM_STS_DATA_AVAIL | TPM_STS_VALID,
chip->vendor.timeout_c,
&chip->vendor.read_queue, true) == 0) {
burstcnt = get_burstcount(chip);
if (burstcnt < 0)
return burstcnt;
len = min_t(int, burstcnt, count - size);
ret = I2C_READ_DATA(tpm_dev, TPM_DATA_FIFO, buf + size, len);
if (ret < 0)
return ret;
size += len;
}
return size;
}
static irqreturn_t tpm_ioserirq_handler(int irq, void *dev_id)
{
struct tpm_chip *chip = dev_id;
struct tpm_stm_dev *tpm_dev;
tpm_dev = (struct tpm_stm_dev *)TPM_VPRIV(chip);
tpm_dev->intrs++;
wake_up_interruptible(&chip->vendor.read_queue);
disable_irq_nosync(chip->vendor.irq);
return IRQ_HANDLED;
}
static int tpm_stm_i2c_send(struct tpm_chip *chip, unsigned char *buf,
size_t len)
{
u32 status, i, size;
int burstcnt = 0;
int ret;
u8 data;
struct i2c_client *client;
struct tpm_stm_dev *tpm_dev;
if (!chip)
return -EBUSY;
if (len < TPM_HEADER_SIZE)
return -EBUSY;
tpm_dev = (struct tpm_stm_dev *)TPM_VPRIV(chip);
client = tpm_dev->client;
client->flags = 0;
ret = request_locality(chip);
if (ret < 0)
return ret;
status = tpm_stm_i2c_status(chip);
if ((status & TPM_STS_COMMAND_READY) == 0) {
tpm_stm_i2c_cancel(chip);
if (wait_for_stat
(chip, TPM_STS_COMMAND_READY, chip->vendor.timeout_b,
&chip->vendor.read_queue, false) < 0) {
ret = -ETIME;
goto out_err;
}
}
for (i = 0; i < len - 1;) {
burstcnt = get_burstcount(chip);
if (burstcnt < 0)
return burstcnt;
size = min_t(int, len - i - 1, burstcnt);
ret = I2C_WRITE_DATA(tpm_dev, TPM_DATA_FIFO, buf + i, size);
if (ret < 0)
goto out_err;
i += size;
}
status = tpm_stm_i2c_status(chip);
if ((status & TPM_STS_DATA_EXPECT) == 0) {
ret = -EIO;
goto out_err;
}
ret = I2C_WRITE_DATA(tpm_dev, TPM_DATA_FIFO, buf + len - 1, 1);
if (ret < 0)
goto out_err;
status = tpm_stm_i2c_status(chip);
if ((status & TPM_STS_DATA_EXPECT) != 0) {
ret = -EIO;
goto out_err;
}
data = TPM_STS_GO;
I2C_WRITE_DATA(tpm_dev, TPM_STS, &data, 1);
return len;
out_err:
tpm_stm_i2c_cancel(chip);
release_locality(chip);
return ret;
}
static int tpm_stm_i2c_recv(struct tpm_chip *chip, unsigned char *buf,
size_t count)
{
int size = 0;
int expected;
if (!chip)
return -EBUSY;
if (count < TPM_HEADER_SIZE) {
size = -EIO;
goto out;
}
size = recv_data(chip, buf, TPM_HEADER_SIZE);
if (size < TPM_HEADER_SIZE) {
dev_err(chip->pdev, "Unable to read header\n");
goto out;
}
expected = be32_to_cpu(*(__be32 *)(buf + 2));
if (expected > count) {
size = -EIO;
goto out;
}
size += recv_data(chip, &buf[TPM_HEADER_SIZE],
expected - TPM_HEADER_SIZE);
if (size < expected) {
dev_err(chip->pdev, "Unable to read remainder of result\n");
size = -ETIME;
goto out;
}
out:
chip->ops->cancel(chip);
release_locality(chip);
return size;
}
static bool tpm_stm_i2c_req_canceled(struct tpm_chip *chip, u8 status)
{
return (status == TPM_STS_COMMAND_READY);
}
static int tpm_stm_i2c_of_request_resources(struct tpm_chip *chip)
{
struct device_node *pp;
struct tpm_stm_dev *tpm_dev = (struct tpm_stm_dev *)TPM_VPRIV(chip);
struct i2c_client *client = tpm_dev->client;
int gpio;
int ret;
pp = client->dev.of_node;
if (!pp) {
dev_err(chip->pdev, "No platform data\n");
return -ENODEV;
}
gpio = of_get_named_gpio(pp, "lpcpd-gpios", 0);
if (gpio < 0) {
dev_err(chip->pdev, "Failed to retrieve lpcpd-gpios from dts.\n");
tpm_dev->io_lpcpd = -1;
return 0;
}
ret = devm_gpio_request_one(&client->dev, gpio,
GPIOF_OUT_INIT_HIGH, "TPM IO LPCPD");
if (ret) {
dev_err(chip->pdev, "Failed to request lpcpd pin\n");
return -ENODEV;
}
tpm_dev->io_lpcpd = gpio;
return 0;
}
static int tpm_stm_i2c_of_request_resources(struct tpm_chip *chip)
{
return -ENODEV;
}
static int tpm_stm_i2c_request_resources(struct i2c_client *client,
struct tpm_chip *chip)
{
struct st33zp24_platform_data *pdata;
struct tpm_stm_dev *tpm_dev = (struct tpm_stm_dev *)TPM_VPRIV(chip);
int ret;
pdata = client->dev.platform_data;
if (!pdata) {
dev_err(chip->pdev, "No platform data\n");
return -ENODEV;
}
tpm_dev->io_lpcpd = pdata->io_lpcpd;
if (gpio_is_valid(pdata->io_lpcpd)) {
ret = devm_gpio_request_one(&client->dev,
pdata->io_lpcpd, GPIOF_OUT_INIT_HIGH,
"TPM IO_LPCPD");
if (ret) {
dev_err(chip->pdev, "%s : reset gpio_request failed\n",
__FILE__);
return ret;
}
}
return 0;
}
static int
tpm_stm_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
int ret;
u8 intmask = 0;
struct tpm_chip *chip;
struct st33zp24_platform_data *platform_data;
struct tpm_stm_dev *tpm_dev;
if (!client) {
pr_info("%s: i2c client is NULL. Device not accessible.\n",
__func__);
return -ENODEV;
}
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_info(&client->dev, "client not i2c capable\n");
return -ENODEV;
}
tpm_dev = devm_kzalloc(&client->dev, sizeof(struct tpm_stm_dev),
GFP_KERNEL);
if (!tpm_dev)
return -ENOMEM;
chip = tpmm_chip_alloc(&client->dev, &st_i2c_tpm);
if (IS_ERR(chip))
return PTR_ERR(chip);
TPM_VPRIV(chip) = tpm_dev;
tpm_dev->client = client;
platform_data = client->dev.platform_data;
if (!platform_data && client->dev.of_node) {
ret = tpm_stm_i2c_of_request_resources(chip);
if (ret)
goto _tpm_clean_answer;
} else if (platform_data) {
ret = tpm_stm_i2c_request_resources(client, chip);
if (ret)
goto _tpm_clean_answer;
}
chip->vendor.timeout_a = msecs_to_jiffies(TIS_SHORT_TIMEOUT);
chip->vendor.timeout_b = msecs_to_jiffies(TIS_LONG_TIMEOUT);
chip->vendor.timeout_c = msecs_to_jiffies(TIS_SHORT_TIMEOUT);
chip->vendor.timeout_d = msecs_to_jiffies(TIS_SHORT_TIMEOUT);
chip->vendor.locality = LOCALITY0;
if (client->irq) {
init_waitqueue_head(&chip->vendor.read_queue);
tpm_dev->intrs = 0;
if (request_locality(chip) != LOCALITY0) {
ret = -ENODEV;
goto _tpm_clean_answer;
}
clear_interruption(tpm_dev);
ret = devm_request_irq(&client->dev, client->irq,
tpm_ioserirq_handler,
IRQF_TRIGGER_HIGH,
"TPM SERIRQ management", chip);
if (ret < 0) {
dev_err(chip->pdev, "TPM SERIRQ signals %d not available\n",
client->irq);
goto _tpm_clean_answer;
}
intmask |= TPM_INTF_CMD_READY_INT
| TPM_INTF_STS_VALID_INT
| TPM_INTF_DATA_AVAIL_INT;
ret = I2C_WRITE_DATA(tpm_dev, TPM_INT_ENABLE, &intmask, 1);
if (ret < 0)
goto _tpm_clean_answer;
intmask = TPM_GLOBAL_INT_ENABLE;
ret = I2C_WRITE_DATA(tpm_dev, (TPM_INT_ENABLE + 3),
&intmask, 1);
if (ret < 0)
goto _tpm_clean_answer;
chip->vendor.irq = client->irq;
disable_irq_nosync(chip->vendor.irq);
tpm_gen_interrupt(chip);
}
tpm_get_timeouts(chip);
tpm_do_selftest(chip);
return tpm_chip_register(chip);
_tpm_clean_answer:
dev_info(chip->pdev, "TPM I2C initialisation fail\n");
return ret;
}
static int tpm_stm_i2c_remove(struct i2c_client *client)
{
struct tpm_chip *chip =
(struct tpm_chip *) i2c_get_clientdata(client);
if (chip)
tpm_chip_unregister(chip);
return 0;
}
static int tpm_stm_i2c_pm_suspend(struct device *dev)
{
struct st33zp24_platform_data *pin_infos = dev->platform_data;
int ret = 0;
if (gpio_is_valid(pin_infos->io_lpcpd))
gpio_set_value(pin_infos->io_lpcpd, 0);
else
ret = tpm_pm_suspend(dev);
return ret;
}
static int tpm_stm_i2c_pm_resume(struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
struct st33zp24_platform_data *pin_infos = dev->platform_data;
int ret = 0;
if (gpio_is_valid(pin_infos->io_lpcpd)) {
gpio_set_value(pin_infos->io_lpcpd, 1);
ret = wait_for_stat(chip,
TPM_STS_VALID, chip->vendor.timeout_b,
&chip->vendor.read_queue, false);
} else {
ret = tpm_pm_resume(dev);
if (!ret)
tpm_do_selftest(chip);
}
return ret;
}
