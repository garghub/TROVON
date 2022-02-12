static u8 clear_interruption(struct st33zp24_dev *tpm_dev)
{
u8 interrupt;
tpm_dev->ops->recv(tpm_dev->phy_id, TPM_INT_STATUS, &interrupt, 1);
tpm_dev->ops->send(tpm_dev->phy_id, TPM_INT_STATUS, &interrupt, 1);
return interrupt;
}
static void st33zp24_cancel(struct tpm_chip *chip)
{
struct st33zp24_dev *tpm_dev;
u8 data;
tpm_dev = (struct st33zp24_dev *)TPM_VPRIV(chip);
data = TPM_STS_COMMAND_READY;
tpm_dev->ops->send(tpm_dev->phy_id, TPM_STS, &data, 1);
}
static u8 st33zp24_status(struct tpm_chip *chip)
{
struct st33zp24_dev *tpm_dev;
u8 data;
tpm_dev = (struct st33zp24_dev *)TPM_VPRIV(chip);
tpm_dev->ops->recv(tpm_dev->phy_id, TPM_STS, &data, 1);
return data;
}
static int check_locality(struct tpm_chip *chip)
{
struct st33zp24_dev *tpm_dev;
u8 data;
u8 status;
tpm_dev = (struct st33zp24_dev *)TPM_VPRIV(chip);
status = tpm_dev->ops->recv(tpm_dev->phy_id, TPM_ACCESS, &data, 1);
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
struct st33zp24_dev *tpm_dev;
u8 data;
if (check_locality(chip) == chip->vendor.locality)
return chip->vendor.locality;
tpm_dev = (struct st33zp24_dev *)TPM_VPRIV(chip);
data = TPM_ACCESS_REQUEST_USE;
ret = tpm_dev->ops->send(tpm_dev->phy_id, TPM_ACCESS, &data, 1);
if (ret < 0)
return ret;
stop = jiffies + chip->vendor.timeout_a;
do {
if (check_locality(chip) >= 0)
return chip->vendor.locality;
msleep(TPM_TIMEOUT);
} while (time_before(jiffies, stop));
return -EACCES;
}
static void release_locality(struct tpm_chip *chip)
{
struct st33zp24_dev *tpm_dev;
u8 data;
tpm_dev = (struct st33zp24_dev *)TPM_VPRIV(chip);
data = TPM_ACCESS_ACTIVE_LOCALITY;
tpm_dev->ops->send(tpm_dev->phy_id, TPM_ACCESS, &data, 1);
}
static int get_burstcount(struct tpm_chip *chip)
{
unsigned long stop;
int burstcnt, status;
u8 tpm_reg, temp;
struct st33zp24_dev *tpm_dev;
tpm_dev = (struct st33zp24_dev *)TPM_VPRIV(chip);
stop = jiffies + chip->vendor.timeout_d;
do {
tpm_reg = TPM_STS + 1;
status = tpm_dev->ops->recv(tpm_dev->phy_id, tpm_reg, &temp, 1);
if (status < 0)
return -EBUSY;
tpm_reg = TPM_STS + 2;
burstcnt = temp;
status = tpm_dev->ops->recv(tpm_dev->phy_id, tpm_reg, &temp, 1);
if (status < 0)
return -EBUSY;
burstcnt |= temp << 8;
if (burstcnt)
return burstcnt;
msleep(TPM_TIMEOUT);
} while (time_before(jiffies, stop));
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
static int wait_for_stat(struct tpm_chip *chip, u8 mask, unsigned long timeout,
wait_queue_head_t *queue, bool check_cancel)
{
unsigned long stop;
int ret = 0;
bool canceled = false;
bool condition;
u32 cur_intrs;
u8 status;
struct st33zp24_dev *tpm_dev;
tpm_dev = (struct st33zp24_dev *)TPM_VPRIV(chip);
status = st33zp24_status(chip);
if ((status & mask) == mask)
return 0;
stop = jiffies + timeout;
if (chip->vendor.irq) {
cur_intrs = tpm_dev->intrs;
clear_interruption(tpm_dev);
enable_irq(chip->vendor.irq);
do {
if (ret == -ERESTARTSYS && freezing(current))
clear_thread_flag(TIF_SIGPENDING);
timeout = stop - jiffies;
if ((long) timeout <= 0)
return -1;
ret = wait_event_interruptible_timeout(*queue,
cur_intrs != tpm_dev->intrs,
timeout);
clear_interruption(tpm_dev);
condition = wait_for_tpm_stat_cond(chip, mask,
check_cancel, &canceled);
if (ret >= 0 && condition) {
if (canceled)
return -ECANCELED;
return 0;
}
} while (ret == -ERESTARTSYS && freezing(current));
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
struct st33zp24_dev *tpm_dev;
tpm_dev = (struct st33zp24_dev *)TPM_VPRIV(chip);
while (size < count &&
wait_for_stat(chip,
TPM_STS_DATA_AVAIL | TPM_STS_VALID,
chip->vendor.timeout_c,
&chip->vendor.read_queue, true) == 0) {
burstcnt = get_burstcount(chip);
if (burstcnt < 0)
return burstcnt;
len = min_t(int, burstcnt, count - size);
ret = tpm_dev->ops->recv(tpm_dev->phy_id, TPM_DATA_FIFO,
buf + size, len);
if (ret < 0)
return ret;
size += len;
}
return size;
}
static irqreturn_t tpm_ioserirq_handler(int irq, void *dev_id)
{
struct tpm_chip *chip = dev_id;
struct st33zp24_dev *tpm_dev;
tpm_dev = (struct st33zp24_dev *)TPM_VPRIV(chip);
tpm_dev->intrs++;
wake_up_interruptible(&chip->vendor.read_queue);
disable_irq_nosync(chip->vendor.irq);
return IRQ_HANDLED;
}
static int st33zp24_send(struct tpm_chip *chip, unsigned char *buf,
size_t len)
{
u32 status, i, size, ordinal;
int burstcnt = 0;
int ret;
u8 data;
struct st33zp24_dev *tpm_dev;
if (!chip)
return -EBUSY;
if (len < TPM_HEADER_SIZE)
return -EBUSY;
tpm_dev = (struct st33zp24_dev *)TPM_VPRIV(chip);
ret = request_locality(chip);
if (ret < 0)
return ret;
status = st33zp24_status(chip);
if ((status & TPM_STS_COMMAND_READY) == 0) {
st33zp24_cancel(chip);
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
ret = tpm_dev->ops->send(tpm_dev->phy_id, TPM_DATA_FIFO,
buf + i, size);
if (ret < 0)
goto out_err;
i += size;
}
status = st33zp24_status(chip);
if ((status & TPM_STS_DATA_EXPECT) == 0) {
ret = -EIO;
goto out_err;
}
ret = tpm_dev->ops->send(tpm_dev->phy_id, TPM_DATA_FIFO,
buf + len - 1, 1);
if (ret < 0)
goto out_err;
status = st33zp24_status(chip);
if ((status & TPM_STS_DATA_EXPECT) != 0) {
ret = -EIO;
goto out_err;
}
data = TPM_STS_GO;
ret = tpm_dev->ops->send(tpm_dev->phy_id, TPM_STS, &data, 1);
if (ret < 0)
goto out_err;
if (chip->vendor.irq) {
ordinal = be32_to_cpu(*((__be32 *) (buf + 6)));
ret = wait_for_stat(chip, TPM_STS_DATA_AVAIL | TPM_STS_VALID,
tpm_calc_ordinal_duration(chip, ordinal),
&chip->vendor.read_queue, false);
if (ret < 0)
goto out_err;
}
return len;
out_err:
st33zp24_cancel(chip);
release_locality(chip);
return ret;
}
static int st33zp24_recv(struct tpm_chip *chip, unsigned char *buf,
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
dev_err(&chip->dev, "Unable to read header\n");
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
dev_err(&chip->dev, "Unable to read remainder of result\n");
size = -ETIME;
}
out:
st33zp24_cancel(chip);
release_locality(chip);
return size;
}
static bool st33zp24_req_canceled(struct tpm_chip *chip, u8 status)
{
return (status == TPM_STS_COMMAND_READY);
}
int st33zp24_probe(void *phy_id, const struct st33zp24_phy_ops *ops,
struct device *dev, int irq, int io_lpcpd)
{
int ret;
u8 intmask = 0;
struct tpm_chip *chip;
struct st33zp24_dev *tpm_dev;
chip = tpmm_chip_alloc(dev, &st33zp24_tpm);
if (IS_ERR(chip))
return PTR_ERR(chip);
tpm_dev = devm_kzalloc(dev, sizeof(struct st33zp24_dev),
GFP_KERNEL);
if (!tpm_dev)
return -ENOMEM;
TPM_VPRIV(chip) = tpm_dev;
tpm_dev->phy_id = phy_id;
tpm_dev->ops = ops;
chip->vendor.timeout_a = msecs_to_jiffies(TIS_SHORT_TIMEOUT);
chip->vendor.timeout_b = msecs_to_jiffies(TIS_LONG_TIMEOUT);
chip->vendor.timeout_c = msecs_to_jiffies(TIS_SHORT_TIMEOUT);
chip->vendor.timeout_d = msecs_to_jiffies(TIS_SHORT_TIMEOUT);
chip->vendor.locality = LOCALITY0;
if (irq) {
init_waitqueue_head(&chip->vendor.read_queue);
tpm_dev->intrs = 0;
if (request_locality(chip) != LOCALITY0) {
ret = -ENODEV;
goto _tpm_clean_answer;
}
clear_interruption(tpm_dev);
ret = devm_request_irq(dev, irq, tpm_ioserirq_handler,
IRQF_TRIGGER_HIGH, "TPM SERIRQ management",
chip);
if (ret < 0) {
dev_err(&chip->dev, "TPM SERIRQ signals %d not available\n",
irq);
goto _tpm_clean_answer;
}
intmask |= TPM_INTF_CMD_READY_INT
| TPM_INTF_STS_VALID_INT
| TPM_INTF_DATA_AVAIL_INT;
ret = tpm_dev->ops->send(tpm_dev->phy_id, TPM_INT_ENABLE,
&intmask, 1);
if (ret < 0)
goto _tpm_clean_answer;
intmask = TPM_GLOBAL_INT_ENABLE;
ret = tpm_dev->ops->send(tpm_dev->phy_id, (TPM_INT_ENABLE + 3),
&intmask, 1);
if (ret < 0)
goto _tpm_clean_answer;
chip->vendor.irq = irq;
disable_irq_nosync(chip->vendor.irq);
tpm_gen_interrupt(chip);
}
tpm_get_timeouts(chip);
tpm_do_selftest(chip);
return tpm_chip_register(chip);
_tpm_clean_answer:
dev_info(&chip->dev, "TPM initialization fail\n");
return ret;
}
int st33zp24_remove(struct tpm_chip *chip)
{
tpm_chip_unregister(chip);
return 0;
}
int st33zp24_pm_suspend(struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
struct st33zp24_dev *tpm_dev;
int ret = 0;
tpm_dev = (struct st33zp24_dev *)TPM_VPRIV(chip);
if (gpio_is_valid(tpm_dev->io_lpcpd))
gpio_set_value(tpm_dev->io_lpcpd, 0);
else
ret = tpm_pm_suspend(dev);
return ret;
}
int st33zp24_pm_resume(struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
struct st33zp24_dev *tpm_dev;
int ret = 0;
tpm_dev = (struct st33zp24_dev *)TPM_VPRIV(chip);
if (gpio_is_valid(tpm_dev->io_lpcpd)) {
gpio_set_value(tpm_dev->io_lpcpd, 1);
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
