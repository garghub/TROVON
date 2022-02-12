static s32 i2c_nuvoton_read_buf(struct i2c_client *client, u8 offset, u8 size,
u8 *data)
{
s32 status;
status = i2c_smbus_read_i2c_block_data(client, offset, size, data);
dev_dbg(&client->dev,
"%s(offset=%u size=%u data=%*ph) -> sts=%d\n", __func__,
offset, size, (int)size, data, status);
return status;
}
static s32 i2c_nuvoton_write_buf(struct i2c_client *client, u8 offset, u8 size,
u8 *data)
{
s32 status;
status = i2c_smbus_write_i2c_block_data(client, offset, size, data);
dev_dbg(&client->dev,
"%s(offset=%u size=%u data=%*ph) -> sts=%d\n", __func__,
offset, size, (int)size, data, status);
return status;
}
static u8 i2c_nuvoton_read_status(struct tpm_chip *chip)
{
struct i2c_client *client = to_i2c_client(chip->dev);
s32 status;
u8 data;
status = i2c_nuvoton_read_buf(client, TPM_STS, 1, &data);
if (status <= 0) {
dev_err(chip->dev, "%s() error return %d\n", __func__,
status);
data = TPM_STS_ERR_VAL;
}
return data;
}
static s32 i2c_nuvoton_write_status(struct i2c_client *client, u8 data)
{
s32 status;
int i;
for (i = 0, status = -1; i < TPM_I2C_RETRY_COUNT && status < 0; i++) {
status = i2c_nuvoton_write_buf(client, TPM_STS, 1, &data);
msleep(TPM_I2C_BUS_DELAY);
}
return status;
}
static void i2c_nuvoton_ready(struct tpm_chip *chip)
{
struct i2c_client *client = to_i2c_client(chip->dev);
s32 status;
status = i2c_nuvoton_write_status(client, TPM_STS_COMMAND_READY);
if (status < 0)
dev_err(chip->dev,
"%s() fail to write TPM_STS.commandReady\n", __func__);
}
static int i2c_nuvoton_get_burstcount(struct i2c_client *client,
struct tpm_chip *chip)
{
unsigned long stop = jiffies + chip->vendor.timeout_d;
s32 status;
int burst_count = -1;
u8 data;
do {
status = i2c_nuvoton_read_buf(client, TPM_BURST_COUNT, 1,
&data);
if (status > 0 && data > 0) {
burst_count = min_t(u8, TPM_I2C_MAX_BUF_SIZE, data);
break;
}
msleep(TPM_I2C_BUS_DELAY);
} while (time_before(jiffies, stop));
return burst_count;
}
static bool i2c_nuvoton_check_status(struct tpm_chip *chip, u8 mask, u8 value)
{
u8 status = i2c_nuvoton_read_status(chip);
return (status != TPM_STS_ERR_VAL) && ((status & mask) == value);
}
static int i2c_nuvoton_wait_for_stat(struct tpm_chip *chip, u8 mask, u8 value,
u32 timeout, wait_queue_head_t *queue)
{
if (chip->vendor.irq && queue) {
s32 rc;
struct priv_data *priv = chip->vendor.priv;
unsigned int cur_intrs = priv->intrs;
enable_irq(chip->vendor.irq);
rc = wait_event_interruptible_timeout(*queue,
cur_intrs != priv->intrs,
timeout);
if (rc > 0)
return 0;
} else {
unsigned long ten_msec, stop;
bool status_valid;
status_valid = i2c_nuvoton_check_status(chip, mask, value);
if (status_valid)
return 0;
ten_msec = jiffies + msecs_to_jiffies(TPM_I2C_RETRY_DELAY_LONG);
stop = jiffies + timeout;
do {
if (time_before(jiffies, ten_msec))
msleep(TPM_I2C_RETRY_DELAY_SHORT);
else
msleep(TPM_I2C_RETRY_DELAY_LONG);
status_valid = i2c_nuvoton_check_status(chip, mask,
value);
if (status_valid)
return 0;
} while (time_before(jiffies, stop));
}
dev_err(chip->dev, "%s(%02x, %02x) -> timeout\n", __func__, mask,
value);
return -ETIMEDOUT;
}
static int i2c_nuvoton_wait_for_data_avail(struct tpm_chip *chip, u32 timeout,
wait_queue_head_t *queue)
{
return i2c_nuvoton_wait_for_stat(chip,
TPM_STS_DATA_AVAIL | TPM_STS_VALID,
TPM_STS_DATA_AVAIL | TPM_STS_VALID,
timeout, queue);
}
static int i2c_nuvoton_recv_data(struct i2c_client *client,
struct tpm_chip *chip, u8 *buf, size_t count)
{
s32 rc;
int burst_count, bytes2read, size = 0;
while (size < count &&
i2c_nuvoton_wait_for_data_avail(chip,
chip->vendor.timeout_c,
&chip->vendor.read_queue) == 0) {
burst_count = i2c_nuvoton_get_burstcount(client, chip);
if (burst_count < 0) {
dev_err(chip->dev,
"%s() fail to read burstCount=%d\n", __func__,
burst_count);
return -EIO;
}
bytes2read = min_t(size_t, burst_count, count - size);
rc = i2c_nuvoton_read_buf(client, TPM_DATA_FIFO_R,
bytes2read, &buf[size]);
if (rc < 0) {
dev_err(chip->dev,
"%s() fail on i2c_nuvoton_read_buf()=%d\n",
__func__, rc);
return -EIO;
}
dev_dbg(chip->dev, "%s(%d):", __func__, bytes2read);
size += bytes2read;
}
return size;
}
static int i2c_nuvoton_recv(struct tpm_chip *chip, u8 *buf, size_t count)
{
struct device *dev = chip->dev;
struct i2c_client *client = to_i2c_client(dev);
s32 rc;
int expected, status, burst_count, retries, size = 0;
if (count < TPM_HEADER_SIZE) {
i2c_nuvoton_ready(chip);
dev_err(dev, "%s() count < header size\n", __func__);
return -EIO;
}
for (retries = 0; retries < TPM_RETRY; retries++) {
if (retries > 0) {
i2c_nuvoton_write_status(client,
TPM_STS_RESPONSE_RETRY);
}
status = i2c_nuvoton_wait_for_data_avail(
chip, chip->vendor.timeout_c, &chip->vendor.read_queue);
if (status != 0) {
dev_err(dev, "%s() timeout on dataAvail\n", __func__);
size = -ETIMEDOUT;
continue;
}
burst_count = i2c_nuvoton_get_burstcount(client, chip);
if (burst_count < 0) {
dev_err(dev, "%s() fail to get burstCount\n", __func__);
size = -EIO;
continue;
}
size = i2c_nuvoton_recv_data(client, chip, buf,
burst_count);
if (size < TPM_HEADER_SIZE) {
dev_err(dev, "%s() fail to read header\n", __func__);
size = -EIO;
continue;
}
expected = be32_to_cpu(*(__be32 *) (buf + 2));
if (expected > count) {
dev_err(dev, "%s() expected > count\n", __func__);
size = -EIO;
continue;
}
rc = i2c_nuvoton_recv_data(client, chip, &buf[size],
expected - size);
size += rc;
if (rc < 0 || size < expected) {
dev_err(dev, "%s() fail to read remainder of result\n",
__func__);
size = -EIO;
continue;
}
if (i2c_nuvoton_wait_for_stat(
chip, TPM_STS_VALID | TPM_STS_DATA_AVAIL,
TPM_STS_VALID, chip->vendor.timeout_c,
NULL)) {
dev_err(dev, "%s() error left over data\n", __func__);
size = -ETIMEDOUT;
continue;
}
break;
}
i2c_nuvoton_ready(chip);
dev_dbg(chip->dev, "%s() -> %d\n", __func__, size);
return size;
}
static int i2c_nuvoton_send(struct tpm_chip *chip, u8 *buf, size_t len)
{
struct device *dev = chip->dev;
struct i2c_client *client = to_i2c_client(dev);
u32 ordinal;
size_t count = 0;
int burst_count, bytes2write, retries, rc = -EIO;
for (retries = 0; retries < TPM_RETRY; retries++) {
i2c_nuvoton_ready(chip);
if (i2c_nuvoton_wait_for_stat(chip, TPM_STS_COMMAND_READY,
TPM_STS_COMMAND_READY,
chip->vendor.timeout_b, NULL)) {
dev_err(dev, "%s() timeout on commandReady\n",
__func__);
rc = -EIO;
continue;
}
rc = 0;
while (count < len - 1) {
burst_count = i2c_nuvoton_get_burstcount(client,
chip);
if (burst_count < 0) {
dev_err(dev, "%s() fail get burstCount\n",
__func__);
rc = -EIO;
break;
}
bytes2write = min_t(size_t, burst_count,
len - 1 - count);
rc = i2c_nuvoton_write_buf(client, TPM_DATA_FIFO_W,
bytes2write, &buf[count]);
if (rc < 0) {
dev_err(dev, "%s() fail i2cWriteBuf\n",
__func__);
break;
}
dev_dbg(dev, "%s(%d):", __func__, bytes2write);
count += bytes2write;
rc = i2c_nuvoton_wait_for_stat(chip,
TPM_STS_VALID |
TPM_STS_EXPECT,
TPM_STS_VALID |
TPM_STS_EXPECT,
chip->vendor.timeout_c,
NULL);
if (rc < 0) {
dev_err(dev, "%s() timeout on Expect\n",
__func__);
rc = -ETIMEDOUT;
break;
}
}
if (rc < 0)
continue;
rc = i2c_nuvoton_write_buf(client, TPM_DATA_FIFO_W, 1,
&buf[count]);
if (rc < 0) {
dev_err(dev, "%s() fail to write last byte\n",
__func__);
rc = -EIO;
continue;
}
dev_dbg(dev, "%s(last): %02x", __func__, buf[count]);
rc = i2c_nuvoton_wait_for_stat(chip,
TPM_STS_VALID | TPM_STS_EXPECT,
TPM_STS_VALID,
chip->vendor.timeout_c, NULL);
if (rc) {
dev_err(dev, "%s() timeout on Expect to clear\n",
__func__);
rc = -ETIMEDOUT;
continue;
}
break;
}
if (rc < 0) {
i2c_nuvoton_ready(chip);
return rc;
}
rc = i2c_nuvoton_write_status(client, TPM_STS_GO);
if (rc < 0) {
dev_err(dev, "%s() fail to write Go\n", __func__);
i2c_nuvoton_ready(chip);
return rc;
}
ordinal = be32_to_cpu(*((__be32 *) (buf + 6)));
rc = i2c_nuvoton_wait_for_data_avail(chip,
tpm_calc_ordinal_duration(chip,
ordinal),
&chip->vendor.read_queue);
if (rc) {
dev_err(dev, "%s() timeout command duration\n", __func__);
i2c_nuvoton_ready(chip);
return rc;
}
dev_dbg(dev, "%s() -> %zd\n", __func__, len);
return len;
}
static bool i2c_nuvoton_req_canceled(struct tpm_chip *chip, u8 status)
{
return (status == TPM_STS_COMMAND_READY);
}
static irqreturn_t i2c_nuvoton_int_handler(int dummy, void *dev_id)
{
struct tpm_chip *chip = dev_id;
struct priv_data *priv = chip->vendor.priv;
priv->intrs++;
wake_up(&chip->vendor.read_queue);
disable_irq_nosync(chip->vendor.irq);
return IRQ_HANDLED;
}
static int get_vid(struct i2c_client *client, u32 *res)
{
static const u8 vid_did_rid_value[] = { 0x50, 0x10, 0xfe };
u32 temp;
s32 rc;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
rc = i2c_nuvoton_read_buf(client, TPM_VID_DID_RID, 4, (u8 *)&temp);
if (rc < 0)
return rc;
if (memcmp(&temp, vid_did_rid_value, sizeof(vid_did_rid_value))) {
rc = i2c_nuvoton_read_buf(client, TPM_DATA_FIFO_W, 4,
(u8 *) (&temp));
if (rc < 0)
return rc;
if (memcmp(&temp, vid_did_rid_value,
sizeof(vid_did_rid_value)))
return -ENODEV;
}
*res = temp;
return 0;
}
static int i2c_nuvoton_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int rc;
struct tpm_chip *chip;
struct device *dev = &client->dev;
u32 vid = 0;
rc = get_vid(client, &vid);
if (rc)
return rc;
dev_info(dev, "VID: %04X DID: %02X RID: %02X\n", (u16) vid,
(u8) (vid >> 16), (u8) (vid >> 24));
chip = tpm_register_hardware(dev, &tpm_i2c);
if (!chip) {
dev_err(dev, "%s() error in tpm_register_hardware\n", __func__);
return -ENODEV;
}
chip->vendor.priv = devm_kzalloc(dev, sizeof(struct priv_data),
GFP_KERNEL);
init_waitqueue_head(&chip->vendor.read_queue);
init_waitqueue_head(&chip->vendor.int_queue);
chip->vendor.timeout_a = msecs_to_jiffies(TPM_I2C_SHORT_TIMEOUT);
chip->vendor.timeout_b = msecs_to_jiffies(TPM_I2C_LONG_TIMEOUT);
chip->vendor.timeout_c = msecs_to_jiffies(TPM_I2C_SHORT_TIMEOUT);
chip->vendor.timeout_d = msecs_to_jiffies(TPM_I2C_SHORT_TIMEOUT);
chip->vendor.irq = client->irq;
if (chip->vendor.irq) {
dev_dbg(dev, "%s() chip-vendor.irq\n", __func__);
rc = devm_request_irq(dev, chip->vendor.irq,
i2c_nuvoton_int_handler,
IRQF_TRIGGER_LOW,
chip->vendor.miscdev.name,
chip);
if (rc) {
dev_err(dev, "%s() Unable to request irq: %d for use\n",
__func__, chip->vendor.irq);
chip->vendor.irq = 0;
} else {
i2c_nuvoton_ready(chip);
rc = i2c_nuvoton_wait_for_stat(chip,
TPM_STS_COMMAND_READY,
TPM_STS_COMMAND_READY,
chip->vendor.timeout_b,
NULL);
if (rc == 0) {
rc = i2c_nuvoton_write_buf(client,
TPM_DATA_FIFO_W,
1, (u8 *) (&rc));
if (rc < 0)
goto out_err;
i2c_nuvoton_ready(chip);
} else {
if (i2c_nuvoton_read_status(chip) !=
TPM_STS_VALID) {
rc = -EIO;
goto out_err;
}
}
}
}
if (tpm_get_timeouts(chip)) {
rc = -ENODEV;
goto out_err;
}
if (tpm_do_selftest(chip)) {
rc = -ENODEV;
goto out_err;
}
return 0;
out_err:
tpm_dev_vendor_release(chip);
tpm_remove_hardware(chip->dev);
return rc;
}
static int i2c_nuvoton_remove(struct i2c_client *client)
{
struct device *dev = &(client->dev);
struct tpm_chip *chip = dev_get_drvdata(dev);
if (chip)
tpm_dev_vendor_release(chip);
tpm_remove_hardware(dev);
kfree(chip);
return 0;
}
