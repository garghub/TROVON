unsigned long tpm_calc_ordinal_duration(struct tpm_chip *chip,
u32 ordinal)
{
int duration_idx = TPM_UNDEFINED;
int duration = 0;
u8 category = (ordinal >> 24) & 0xFF;
if ((category == TPM_PROTECTED_COMMAND && ordinal < TPM_MAX_ORDINAL) ||
(category == TPM_CONNECTION_COMMAND && ordinal < TSC_MAX_ORDINAL))
duration_idx = tpm_ordinal_duration[ordinal];
if (duration_idx != TPM_UNDEFINED)
duration = chip->vendor.duration[duration_idx];
if (duration <= 0)
return 2 * 60 * HZ;
else
return duration;
}
ssize_t tpm_transmit(struct tpm_chip *chip, const char *buf,
size_t bufsiz)
{
ssize_t rc;
u32 count, ordinal;
unsigned long stop;
if (bufsiz > TPM_BUFSIZE)
bufsiz = TPM_BUFSIZE;
count = be32_to_cpu(*((__be32 *) (buf + 2)));
ordinal = be32_to_cpu(*((__be32 *) (buf + 6)));
if (count == 0)
return -ENODATA;
if (count > bufsiz) {
dev_err(chip->dev,
"invalid count value %x %zx\n", count, bufsiz);
return -E2BIG;
}
mutex_lock(&chip->tpm_mutex);
rc = chip->ops->send(chip, (u8 *) buf, count);
if (rc < 0) {
dev_err(chip->dev,
"tpm_transmit: tpm_send: error %zd\n", rc);
goto out;
}
if (chip->vendor.irq)
goto out_recv;
stop = jiffies + tpm_calc_ordinal_duration(chip, ordinal);
do {
u8 status = chip->ops->status(chip);
if ((status & chip->ops->req_complete_mask) ==
chip->ops->req_complete_val)
goto out_recv;
if (chip->ops->req_canceled(chip, status)) {
dev_err(chip->dev, "Operation Canceled\n");
rc = -ECANCELED;
goto out;
}
msleep(TPM_TIMEOUT);
rmb();
} while (time_before(jiffies, stop));
chip->ops->cancel(chip);
dev_err(chip->dev, "Operation Timed out\n");
rc = -ETIME;
goto out;
out_recv:
rc = chip->ops->recv(chip, (u8 *) buf, bufsiz);
if (rc < 0)
dev_err(chip->dev,
"tpm_transmit: tpm_recv: error %zd\n", rc);
out:
mutex_unlock(&chip->tpm_mutex);
return rc;
}
static ssize_t transmit_cmd(struct tpm_chip *chip, struct tpm_cmd_t *cmd,
int len, const char *desc)
{
int err;
len = tpm_transmit(chip, (u8 *) cmd, len);
if (len < 0)
return len;
else if (len < TPM_HEADER_SIZE)
return -EFAULT;
err = be32_to_cpu(cmd->header.out.return_code);
if (err != 0 && desc)
dev_err(chip->dev, "A TPM error (%d) occurred %s\n", err, desc);
return err;
}
ssize_t tpm_getcap(struct device *dev, __be32 subcap_id, cap_t *cap,
const char *desc)
{
struct tpm_cmd_t tpm_cmd;
int rc;
struct tpm_chip *chip = dev_get_drvdata(dev);
tpm_cmd.header.in = tpm_getcap_header;
if (subcap_id == CAP_VERSION_1_1 || subcap_id == CAP_VERSION_1_2) {
tpm_cmd.params.getcap_in.cap = subcap_id;
tpm_cmd.params.getcap_in.subcap_size = cpu_to_be32(0);
tpm_cmd.header.in.length -= cpu_to_be32(sizeof(__be32));
} else {
if (subcap_id == TPM_CAP_FLAG_PERM ||
subcap_id == TPM_CAP_FLAG_VOL)
tpm_cmd.params.getcap_in.cap = TPM_CAP_FLAG;
else
tpm_cmd.params.getcap_in.cap = TPM_CAP_PROP;
tpm_cmd.params.getcap_in.subcap_size = cpu_to_be32(4);
tpm_cmd.params.getcap_in.subcap = subcap_id;
}
rc = transmit_cmd(chip, &tpm_cmd, TPM_INTERNAL_RESULT_SIZE, desc);
if (!rc)
*cap = tpm_cmd.params.getcap_out.cap;
return rc;
}
void tpm_gen_interrupt(struct tpm_chip *chip)
{
struct tpm_cmd_t tpm_cmd;
ssize_t rc;
tpm_cmd.header.in = tpm_getcap_header;
tpm_cmd.params.getcap_in.cap = TPM_CAP_PROP;
tpm_cmd.params.getcap_in.subcap_size = cpu_to_be32(4);
tpm_cmd.params.getcap_in.subcap = TPM_CAP_PROP_TIS_TIMEOUT;
rc = transmit_cmd(chip, &tpm_cmd, TPM_INTERNAL_RESULT_SIZE,
"attempting to determine the timeouts");
}
static int tpm_startup(struct tpm_chip *chip, __be16 startup_type)
{
struct tpm_cmd_t start_cmd;
start_cmd.header.in = tpm_startup_header;
start_cmd.params.startup_in.startup_type = startup_type;
return transmit_cmd(chip, &start_cmd, TPM_INTERNAL_RESULT_SIZE,
"attempting to start the TPM");
}
int tpm_get_timeouts(struct tpm_chip *chip)
{
struct tpm_cmd_t tpm_cmd;
struct timeout_t *timeout_cap;
struct duration_t *duration_cap;
ssize_t rc;
u32 timeout;
unsigned int scale = 1;
tpm_cmd.header.in = tpm_getcap_header;
tpm_cmd.params.getcap_in.cap = TPM_CAP_PROP;
tpm_cmd.params.getcap_in.subcap_size = cpu_to_be32(4);
tpm_cmd.params.getcap_in.subcap = TPM_CAP_PROP_TIS_TIMEOUT;
rc = transmit_cmd(chip, &tpm_cmd, TPM_INTERNAL_RESULT_SIZE, NULL);
if (rc == TPM_ERR_INVALID_POSTINIT) {
dev_info(chip->dev, "Issuing TPM_STARTUP");
if (tpm_startup(chip, TPM_ST_CLEAR))
return rc;
tpm_cmd.header.in = tpm_getcap_header;
tpm_cmd.params.getcap_in.cap = TPM_CAP_PROP;
tpm_cmd.params.getcap_in.subcap_size = cpu_to_be32(4);
tpm_cmd.params.getcap_in.subcap = TPM_CAP_PROP_TIS_TIMEOUT;
rc = transmit_cmd(chip, &tpm_cmd, TPM_INTERNAL_RESULT_SIZE,
NULL);
}
if (rc) {
dev_err(chip->dev,
"A TPM error (%zd) occurred attempting to determine the timeouts\n",
rc);
goto duration;
}
if (be32_to_cpu(tpm_cmd.header.out.return_code) != 0 ||
be32_to_cpu(tpm_cmd.header.out.length)
!= sizeof(tpm_cmd.header.out) + sizeof(u32) + 4 * sizeof(u32))
return -EINVAL;
timeout_cap = &tpm_cmd.params.getcap_out.cap.timeout;
timeout = be32_to_cpu(timeout_cap->a);
if (timeout && timeout < 1000) {
scale = 1000;
chip->vendor.timeout_adjusted = true;
}
if (timeout)
chip->vendor.timeout_a = usecs_to_jiffies(timeout * scale);
timeout = be32_to_cpu(timeout_cap->b);
if (timeout)
chip->vendor.timeout_b = usecs_to_jiffies(timeout * scale);
timeout = be32_to_cpu(timeout_cap->c);
if (timeout)
chip->vendor.timeout_c = usecs_to_jiffies(timeout * scale);
timeout = be32_to_cpu(timeout_cap->d);
if (timeout)
chip->vendor.timeout_d = usecs_to_jiffies(timeout * scale);
duration:
tpm_cmd.header.in = tpm_getcap_header;
tpm_cmd.params.getcap_in.cap = TPM_CAP_PROP;
tpm_cmd.params.getcap_in.subcap_size = cpu_to_be32(4);
tpm_cmd.params.getcap_in.subcap = TPM_CAP_PROP_TIS_DURATION;
rc = transmit_cmd(chip, &tpm_cmd, TPM_INTERNAL_RESULT_SIZE,
"attempting to determine the durations");
if (rc)
return rc;
if (be32_to_cpu(tpm_cmd.header.out.return_code) != 0 ||
be32_to_cpu(tpm_cmd.header.out.length)
!= sizeof(tpm_cmd.header.out) + sizeof(u32) + 3 * sizeof(u32))
return -EINVAL;
duration_cap = &tpm_cmd.params.getcap_out.cap.duration;
chip->vendor.duration[TPM_SHORT] =
usecs_to_jiffies(be32_to_cpu(duration_cap->tpm_short));
chip->vendor.duration[TPM_MEDIUM] =
usecs_to_jiffies(be32_to_cpu(duration_cap->tpm_medium));
chip->vendor.duration[TPM_LONG] =
usecs_to_jiffies(be32_to_cpu(duration_cap->tpm_long));
if (chip->vendor.duration[TPM_SHORT] < (HZ / 100)) {
chip->vendor.duration[TPM_SHORT] = HZ;
chip->vendor.duration[TPM_MEDIUM] *= 1000;
chip->vendor.duration[TPM_LONG] *= 1000;
chip->vendor.duration_adjusted = true;
dev_info(chip->dev, "Adjusting TPM timeout parameters.");
}
return 0;
}
static int tpm_continue_selftest(struct tpm_chip *chip)
{
int rc;
struct tpm_cmd_t cmd;
cmd.header.in = continue_selftest_header;
rc = transmit_cmd(chip, &cmd, CONTINUE_SELFTEST_RESULT_SIZE,
"continue selftest");
return rc;
}
static struct tpm_chip *tpm_chip_find_get(int chip_num)
{
struct tpm_chip *pos, *chip = NULL;
rcu_read_lock();
list_for_each_entry_rcu(pos, &tpm_chip_list, list) {
if (chip_num != TPM_ANY_NUM && chip_num != pos->dev_num)
continue;
if (try_module_get(pos->dev->driver->owner)) {
chip = pos;
break;
}
}
rcu_read_unlock();
return chip;
}
int tpm_pcr_read_dev(struct tpm_chip *chip, int pcr_idx, u8 *res_buf)
{
int rc;
struct tpm_cmd_t cmd;
cmd.header.in = pcrread_header;
cmd.params.pcrread_in.pcr_idx = cpu_to_be32(pcr_idx);
rc = transmit_cmd(chip, &cmd, READ_PCR_RESULT_SIZE,
"attempting to read a pcr value");
if (rc == 0)
memcpy(res_buf, cmd.params.pcrread_out.pcr_result,
TPM_DIGEST_SIZE);
return rc;
}
int tpm_pcr_read(u32 chip_num, int pcr_idx, u8 *res_buf)
{
struct tpm_chip *chip;
int rc;
chip = tpm_chip_find_get(chip_num);
if (chip == NULL)
return -ENODEV;
rc = tpm_pcr_read_dev(chip, pcr_idx, res_buf);
tpm_chip_put(chip);
return rc;
}
int tpm_pcr_extend(u32 chip_num, int pcr_idx, const u8 *hash)
{
struct tpm_cmd_t cmd;
int rc;
struct tpm_chip *chip;
chip = tpm_chip_find_get(chip_num);
if (chip == NULL)
return -ENODEV;
cmd.header.in = pcrextend_header;
cmd.params.pcrextend_in.pcr_idx = cpu_to_be32(pcr_idx);
memcpy(cmd.params.pcrextend_in.hash, hash, TPM_DIGEST_SIZE);
rc = transmit_cmd(chip, &cmd, EXTEND_PCR_RESULT_SIZE,
"attempting extend a PCR value");
tpm_chip_put(chip);
return rc;
}
int tpm_do_selftest(struct tpm_chip *chip)
{
int rc;
unsigned int loops;
unsigned int delay_msec = 100;
unsigned long duration;
struct tpm_cmd_t cmd;
duration = tpm_calc_ordinal_duration(chip, TPM_ORD_CONTINUE_SELFTEST);
loops = jiffies_to_msecs(duration) / delay_msec;
rc = tpm_continue_selftest(chip);
if (rc)
return rc;
do {
cmd.header.in = pcrread_header;
cmd.params.pcrread_in.pcr_idx = cpu_to_be32(0);
rc = tpm_transmit(chip, (u8 *) &cmd, READ_PCR_RESULT_SIZE);
if (rc == -ETIME) {
dev_info(chip->dev, HW_ERR "TPM command timed out during continue self test");
msleep(delay_msec);
continue;
}
if (rc < TPM_HEADER_SIZE)
return -EFAULT;
rc = be32_to_cpu(cmd.header.out.return_code);
if (rc == TPM_ERR_DISABLED || rc == TPM_ERR_DEACTIVATED) {
dev_info(chip->dev,
"TPM is disabled/deactivated (0x%X)\n", rc);
return 0;
}
if (rc != TPM_WARN_DOING_SELFTEST)
return rc;
msleep(delay_msec);
} while (--loops > 0);
return rc;
}
int tpm_send(u32 chip_num, void *cmd, size_t buflen)
{
struct tpm_chip *chip;
int rc;
chip = tpm_chip_find_get(chip_num);
if (chip == NULL)
return -ENODEV;
rc = transmit_cmd(chip, cmd, buflen, "attempting tpm_cmd");
tpm_chip_put(chip);
return rc;
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
int wait_for_tpm_stat(struct tpm_chip *chip, u8 mask, unsigned long timeout,
wait_queue_head_t *queue, bool check_cancel)
{
unsigned long stop;
long rc;
u8 status;
bool canceled = false;
status = chip->ops->status(chip);
if ((status & mask) == mask)
return 0;
stop = jiffies + timeout;
if (chip->vendor.irq) {
again:
timeout = stop - jiffies;
if ((long)timeout <= 0)
return -ETIME;
rc = wait_event_interruptible_timeout(*queue,
wait_for_tpm_stat_cond(chip, mask, check_cancel,
&canceled),
timeout);
if (rc > 0) {
if (canceled)
return -ECANCELED;
return 0;
}
if (rc == -ERESTARTSYS && freezing(current)) {
clear_thread_flag(TIF_SIGPENDING);
goto again;
}
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
void tpm_remove_hardware(struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
if (chip == NULL) {
dev_err(dev, "No device data found\n");
return;
}
spin_lock(&driver_lock);
list_del_rcu(&chip->list);
spin_unlock(&driver_lock);
synchronize_rcu();
tpm_dev_del_device(chip);
tpm_sysfs_del_device(chip);
tpm_remove_ppi(&dev->kobj);
tpm_bios_log_teardown(chip->bios_dir);
put_device(chip->dev);
}
int tpm_pm_suspend(struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
struct tpm_cmd_t cmd;
int rc, try;
u8 dummy_hash[TPM_DIGEST_SIZE] = { 0 };
if (chip == NULL)
return -ENODEV;
if (tpm_suspend_pcr) {
cmd.header.in = pcrextend_header;
cmd.params.pcrextend_in.pcr_idx = cpu_to_be32(tpm_suspend_pcr);
memcpy(cmd.params.pcrextend_in.hash, dummy_hash,
TPM_DIGEST_SIZE);
rc = transmit_cmd(chip, &cmd, EXTEND_PCR_RESULT_SIZE,
"extending dummy pcr before suspend");
}
for (try = 0; try < TPM_RETRY; try++) {
cmd.header.in = savestate_header;
rc = transmit_cmd(chip, &cmd, SAVESTATE_RESULT_SIZE, NULL);
if (rc != TPM_WARN_RETRY)
break;
msleep(TPM_TIMEOUT_RETRY);
}
if (rc)
dev_err(chip->dev,
"Error (%d) sending savestate before suspend\n", rc);
else if (try > 0)
dev_warn(chip->dev, "TPM savestate took %dms\n",
try * TPM_TIMEOUT_RETRY);
return rc;
}
int tpm_pm_resume(struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
if (chip == NULL)
return -ENODEV;
return 0;
}
int tpm_get_random(u32 chip_num, u8 *out, size_t max)
{
struct tpm_chip *chip;
struct tpm_cmd_t tpm_cmd;
u32 recd, num_bytes = min_t(u32, max, TPM_MAX_RNG_DATA);
int err, total = 0, retries = 5;
u8 *dest = out;
chip = tpm_chip_find_get(chip_num);
if (chip == NULL)
return -ENODEV;
if (!out || !num_bytes || max > TPM_MAX_RNG_DATA)
return -EINVAL;
do {
tpm_cmd.header.in = tpm_getrandom_header;
tpm_cmd.params.getrandom_in.num_bytes = cpu_to_be32(num_bytes);
err = transmit_cmd(chip, &tpm_cmd,
TPM_GETRANDOM_RESULT_SIZE + num_bytes,
"attempting get random");
if (err)
break;
recd = be32_to_cpu(tpm_cmd.params.getrandom_out.rng_data_len);
memcpy(dest, tpm_cmd.params.getrandom_out.rng_data, recd);
dest += recd;
total += recd;
num_bytes -= recd;
} while (retries-- && total < max);
return total ? total : -EIO;
}
void tpm_dev_vendor_release(struct tpm_chip *chip)
{
if (!chip)
return;
clear_bit(chip->dev_num, dev_mask);
}
static void tpm_dev_release(struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
if (!chip)
return;
tpm_dev_vendor_release(chip);
chip->release(dev);
kfree(chip);
}
struct tpm_chip *tpm_register_hardware(struct device *dev,
const struct tpm_class_ops *ops)
{
struct tpm_chip *chip;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL)
return NULL;
mutex_init(&chip->tpm_mutex);
INIT_LIST_HEAD(&chip->list);
chip->ops = ops;
chip->dev_num = find_first_zero_bit(dev_mask, TPM_NUM_DEVICES);
if (chip->dev_num >= TPM_NUM_DEVICES) {
dev_err(dev, "No available tpm device numbers\n");
goto out_free;
}
set_bit(chip->dev_num, dev_mask);
scnprintf(chip->devname, sizeof(chip->devname), "%s%d", "tpm",
chip->dev_num);
chip->dev = get_device(dev);
chip->release = dev->release;
dev->release = tpm_dev_release;
dev_set_drvdata(dev, chip);
if (tpm_dev_add_device(chip))
goto put_device;
if (tpm_sysfs_add_device(chip))
goto del_misc;
if (tpm_add_ppi(&dev->kobj))
goto del_misc;
chip->bios_dir = tpm_bios_log_setup(chip->devname);
spin_lock(&driver_lock);
list_add_rcu(&chip->list, &tpm_chip_list);
spin_unlock(&driver_lock);
return chip;
del_misc:
tpm_dev_del_device(chip);
put_device:
put_device(chip->dev);
out_free:
kfree(chip);
return NULL;
}
