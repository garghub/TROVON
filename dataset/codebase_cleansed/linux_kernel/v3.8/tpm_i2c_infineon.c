static int iic_tpm_read(u8 addr, u8 *buffer, size_t len)
{
struct i2c_msg msg1 = { tpm_dev.client->addr, 0, 1, &addr };
struct i2c_msg msg2 = { tpm_dev.client->addr, I2C_M_RD, len, buffer };
int rc;
int count;
if (!tpm_dev.client->adapter->algo->master_xfer)
return -EOPNOTSUPP;
i2c_lock_adapter(tpm_dev.client->adapter);
for (count = 0; count < MAX_COUNT; count++) {
rc = __i2c_transfer(tpm_dev.client->adapter, &msg1, 1);
if (rc > 0)
break;
usleep_range(SLEEP_DURATION_LOW, SLEEP_DURATION_HI);
}
if (rc <= 0)
goto out;
for (count = 0; count < MAX_COUNT; count++) {
usleep_range(SLEEP_DURATION_LOW, SLEEP_DURATION_HI);
rc = __i2c_transfer(tpm_dev.client->adapter, &msg2, 1);
if (rc > 0)
break;
}
out:
i2c_unlock_adapter(tpm_dev.client->adapter);
if (rc <= 0)
return -EIO;
return 0;
}
static int iic_tpm_write_generic(u8 addr, u8 *buffer, size_t len,
unsigned int sleep_low,
unsigned int sleep_hi, u8 max_count)
{
int rc = -EIO;
int count;
struct i2c_msg msg1 = { tpm_dev.client->addr, 0, len + 1, tpm_dev.buf };
if (len > TPM_BUFSIZE)
return -EINVAL;
if (!tpm_dev.client->adapter->algo->master_xfer)
return -EOPNOTSUPP;
i2c_lock_adapter(tpm_dev.client->adapter);
tpm_dev.buf[0] = addr;
memcpy(&(tpm_dev.buf[1]), buffer, len);
for (count = 0; count < max_count; count++) {
rc = __i2c_transfer(tpm_dev.client->adapter, &msg1, 1);
if (rc > 0)
break;
usleep_range(sleep_low, sleep_hi);
}
i2c_unlock_adapter(tpm_dev.client->adapter);
if (rc <= 0)
return -EIO;
return 0;
}
static int iic_tpm_write(u8 addr, u8 *buffer, size_t len)
{
return iic_tpm_write_generic(addr, buffer, len, SLEEP_DURATION_LOW,
SLEEP_DURATION_HI, MAX_COUNT);
}
static int iic_tpm_write_long(u8 addr, u8 *buffer, size_t len)
{
return iic_tpm_write_generic(addr, buffer, len, SLEEP_DURATION_LONG_LOW,
SLEEP_DURATION_LONG_HI, MAX_COUNT_LONG);
}
static int check_locality(struct tpm_chip *chip, int loc)
{
u8 buf;
int rc;
rc = iic_tpm_read(TPM_ACCESS(loc), &buf, 1);
if (rc < 0)
return rc;
if ((buf & (TPM_ACCESS_ACTIVE_LOCALITY | TPM_ACCESS_VALID)) ==
(TPM_ACCESS_ACTIVE_LOCALITY | TPM_ACCESS_VALID)) {
chip->vendor.locality = loc;
return loc;
}
return -EIO;
}
static void release_locality(struct tpm_chip *chip, int loc, int force)
{
u8 buf;
if (iic_tpm_read(TPM_ACCESS(loc), &buf, 1) < 0)
return;
if (force || (buf & (TPM_ACCESS_REQUEST_PENDING | TPM_ACCESS_VALID)) ==
(TPM_ACCESS_REQUEST_PENDING | TPM_ACCESS_VALID)) {
buf = TPM_ACCESS_ACTIVE_LOCALITY;
iic_tpm_write(TPM_ACCESS(loc), &buf, 1);
}
}
static int request_locality(struct tpm_chip *chip, int loc)
{
unsigned long stop;
u8 buf = TPM_ACCESS_REQUEST_USE;
if (check_locality(chip, loc) >= 0)
return loc;
iic_tpm_write(TPM_ACCESS(loc), &buf, 1);
stop = jiffies + chip->vendor.timeout_a;
do {
if (check_locality(chip, loc) >= 0)
return loc;
usleep_range(TPM_TIMEOUT_US_LOW, TPM_TIMEOUT_US_HI);
} while (time_before(jiffies, stop));
return -ETIME;
}
static u8 tpm_tis_i2c_status(struct tpm_chip *chip)
{
u8 buf;
if (iic_tpm_read(TPM_STS(chip->vendor.locality), &buf, 1) < 0)
return 0;
else
return buf;
}
static void tpm_tis_i2c_ready(struct tpm_chip *chip)
{
u8 buf = TPM_STS_COMMAND_READY;
iic_tpm_write_long(TPM_STS(chip->vendor.locality), &buf, 1);
}
static ssize_t get_burstcount(struct tpm_chip *chip)
{
unsigned long stop;
ssize_t burstcnt;
u8 buf[3];
stop = jiffies + chip->vendor.timeout_d;
do {
if (iic_tpm_read(TPM_STS(chip->vendor.locality)+1, buf, 3) < 0)
burstcnt = 0;
else
burstcnt = (buf[2] << 16) + (buf[1] << 8) + buf[0];
if (burstcnt)
return burstcnt;
usleep_range(TPM_TIMEOUT_US_LOW, TPM_TIMEOUT_US_HI);
} while (time_before(jiffies, stop));
return -EBUSY;
}
static int wait_for_stat(struct tpm_chip *chip, u8 mask, unsigned long timeout,
int *status)
{
unsigned long stop;
*status = tpm_tis_i2c_status(chip);
if ((*status & mask) == mask)
return 0;
stop = jiffies + timeout;
do {
usleep_range(TPM_TIMEOUT_US_LOW, TPM_TIMEOUT_US_HI);
*status = tpm_tis_i2c_status(chip);
if ((*status & mask) == mask)
return 0;
} while (time_before(jiffies, stop));
return -ETIME;
}
static int recv_data(struct tpm_chip *chip, u8 *buf, size_t count)
{
size_t size = 0;
ssize_t burstcnt;
u8 retries = 0;
int rc;
while (size < count) {
burstcnt = get_burstcount(chip);
if (burstcnt < 0)
return burstcnt;
if (burstcnt > (count - size))
burstcnt = count - size;
rc = iic_tpm_read(TPM_DATA_FIFO(chip->vendor.locality),
&(buf[size]), burstcnt);
if (rc == 0)
size += burstcnt;
else if (rc < 0)
retries++;
if (retries > MAX_COUNT_LONG)
return -EIO;
}
return size;
}
static int tpm_tis_i2c_recv(struct tpm_chip *chip, u8 *buf, size_t count)
{
int size = 0;
int expected, status;
if (count < TPM_HEADER_SIZE) {
size = -EIO;
goto out;
}
size = recv_data(chip, buf, TPM_HEADER_SIZE);
if (size < TPM_HEADER_SIZE) {
dev_err(chip->dev, "Unable to read header\n");
goto out;
}
expected = be32_to_cpu(*(__be32 *)(buf + 2));
if ((size_t) expected > count) {
size = -EIO;
goto out;
}
size += recv_data(chip, &buf[TPM_HEADER_SIZE],
expected - TPM_HEADER_SIZE);
if (size < expected) {
dev_err(chip->dev, "Unable to read remainder of result\n");
size = -ETIME;
goto out;
}
wait_for_stat(chip, TPM_STS_VALID, chip->vendor.timeout_c, &status);
if (status & TPM_STS_DATA_AVAIL) {
dev_err(chip->dev, "Error left over data\n");
size = -EIO;
goto out;
}
out:
tpm_tis_i2c_ready(chip);
usleep_range(SLEEP_DURATION_RESET_LOW, SLEEP_DURATION_RESET_HI);
release_locality(chip, chip->vendor.locality, 0);
return size;
}
static int tpm_tis_i2c_send(struct tpm_chip *chip, u8 *buf, size_t len)
{
int rc, status;
ssize_t burstcnt;
size_t count = 0;
u8 retries = 0;
u8 sts = TPM_STS_GO;
if (len > TPM_BUFSIZE)
return -E2BIG;
if (request_locality(chip, 0) < 0)
return -EBUSY;
status = tpm_tis_i2c_status(chip);
if ((status & TPM_STS_COMMAND_READY) == 0) {
tpm_tis_i2c_ready(chip);
if (wait_for_stat
(chip, TPM_STS_COMMAND_READY,
chip->vendor.timeout_b, &status) < 0) {
rc = -ETIME;
goto out_err;
}
}
while (count < len - 1) {
burstcnt = get_burstcount(chip);
if (burstcnt < 0)
return burstcnt;
if (burstcnt > (len - 1 - count))
burstcnt = len - 1 - count;
rc = iic_tpm_write(TPM_DATA_FIFO(chip->vendor.locality),
&(buf[count]), burstcnt);
if (rc == 0)
count += burstcnt;
else if (rc < 0)
retries++;
if (retries > MAX_COUNT_LONG) {
rc = -EIO;
goto out_err;
}
wait_for_stat(chip, TPM_STS_VALID,
chip->vendor.timeout_c, &status);
if ((status & TPM_STS_DATA_EXPECT) == 0) {
rc = -EIO;
goto out_err;
}
}
iic_tpm_write(TPM_DATA_FIFO(chip->vendor.locality), &(buf[count]), 1);
wait_for_stat(chip, TPM_STS_VALID, chip->vendor.timeout_c, &status);
if ((status & TPM_STS_DATA_EXPECT) != 0) {
rc = -EIO;
goto out_err;
}
iic_tpm_write(TPM_STS(chip->vendor.locality), &sts, 1);
return len;
out_err:
tpm_tis_i2c_ready(chip);
usleep_range(SLEEP_DURATION_RESET_LOW, SLEEP_DURATION_RESET_HI);
release_locality(chip, chip->vendor.locality, 0);
return rc;
}
static int tpm_tis_i2c_init(struct device *dev)
{
u32 vendor;
int rc = 0;
struct tpm_chip *chip;
chip = tpm_register_hardware(dev, &tpm_tis_i2c);
if (!chip) {
rc = -ENODEV;
goto out_err;
}
chip->vendor.irq = 0;
chip->vendor.timeout_a = msecs_to_jiffies(TIS_SHORT_TIMEOUT);
chip->vendor.timeout_b = msecs_to_jiffies(TIS_LONG_TIMEOUT);
chip->vendor.timeout_c = msecs_to_jiffies(TIS_SHORT_TIMEOUT);
chip->vendor.timeout_d = msecs_to_jiffies(TIS_SHORT_TIMEOUT);
if (request_locality(chip, 0) != 0) {
rc = -ENODEV;
goto out_vendor;
}
if (iic_tpm_read(TPM_DID_VID(0), (u8 *)&vendor, 4) < 0) {
rc = -EIO;
goto out_release;
}
vendor = be32_to_cpu((__be32) vendor);
if (vendor != TPM_TIS_I2C_DID_VID) {
rc = -ENODEV;
goto out_release;
}
dev_info(dev, "1.2 TPM (device-id 0x%X)\n", vendor >> 16);
INIT_LIST_HEAD(&chip->vendor.list);
tpm_dev.chip = chip;
tpm_get_timeouts(chip);
tpm_do_selftest(chip);
return 0;
out_release:
release_locality(chip, chip->vendor.locality, 1);
out_vendor:
tpm_dev_vendor_release(chip);
tpm_remove_hardware(chip->dev);
chip->dev->release = NULL;
chip->release = NULL;
tpm_dev.client = NULL;
dev_set_drvdata(chip->dev, chip);
out_err:
return rc;
}
static int tpm_tis_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int rc;
if (tpm_dev.client != NULL)
return -EBUSY;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev,
"no algorithms associated to the i2c bus\n");
return -ENODEV;
}
client->driver = &tpm_tis_i2c_driver;
tpm_dev.client = client;
rc = tpm_tis_i2c_init(&client->dev);
if (rc != 0) {
client->driver = NULL;
tpm_dev.client = NULL;
rc = -ENODEV;
}
return rc;
}
static int tpm_tis_i2c_remove(struct i2c_client *client)
{
struct tpm_chip *chip = tpm_dev.chip;
release_locality(chip, chip->vendor.locality, 1);
tpm_dev_vendor_release(chip);
tpm_remove_hardware(chip->dev);
chip->dev->release = NULL;
chip->release = NULL;
tpm_dev.client = NULL;
dev_set_drvdata(chip->dev, chip);
return 0;
}
