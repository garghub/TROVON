unsigned long tpm_calc_ordinal_duration(struct tpm_chip *chip,
u32 ordinal)
{
int duration_idx = TPM_UNDEFINED;
int duration = 0;
if (ordinal < TPM_MAX_ORDINAL)
duration_idx = tpm_ordinal_duration[ordinal];
if (duration_idx != TPM_UNDEFINED)
duration = chip->duration[duration_idx];
if (duration <= 0)
return 2 * 60 * HZ;
else
return duration;
}
static bool tpm_validate_command(struct tpm_chip *chip,
struct tpm_space *space,
const u8 *cmd,
size_t len)
{
const struct tpm_input_header *header = (const void *)cmd;
int i;
u32 cc;
u32 attrs;
unsigned int nr_handles;
if (len < TPM_HEADER_SIZE)
return false;
if (!space)
return true;
if (chip->flags & TPM_CHIP_FLAG_TPM2 && chip->nr_commands) {
cc = be32_to_cpu(header->ordinal);
i = tpm2_find_cc(chip, cc);
if (i < 0) {
dev_dbg(&chip->dev, "0x%04X is an invalid command\n",
cc);
return false;
}
attrs = chip->cc_attrs_tbl[i];
nr_handles =
4 * ((attrs >> TPM2_CC_ATTR_CHANDLES) & GENMASK(2, 0));
if (len < TPM_HEADER_SIZE + 4 * nr_handles)
goto err_len;
}
return true;
err_len:
dev_dbg(&chip->dev,
"%s: insufficient command length %zu", __func__, len);
return false;
}
ssize_t tpm_transmit(struct tpm_chip *chip, struct tpm_space *space,
u8 *buf, size_t bufsiz, unsigned int flags)
{
struct tpm_output_header *header = (void *)buf;
int rc;
ssize_t len = 0;
u32 count, ordinal;
unsigned long stop;
bool need_locality;
if (!tpm_validate_command(chip, space, buf, bufsiz))
return -EINVAL;
if (bufsiz > TPM_BUFSIZE)
bufsiz = TPM_BUFSIZE;
count = be32_to_cpu(*((__be32 *) (buf + 2)));
ordinal = be32_to_cpu(*((__be32 *) (buf + 6)));
if (count == 0)
return -ENODATA;
if (count > bufsiz) {
dev_err(&chip->dev,
"invalid count value %x %zx\n", count, bufsiz);
return -E2BIG;
}
if (!(flags & TPM_TRANSMIT_UNLOCKED))
mutex_lock(&chip->tpm_mutex);
if (chip->dev.parent)
pm_runtime_get_sync(chip->dev.parent);
need_locality = chip->locality == -1;
if (need_locality && chip->ops->request_locality) {
rc = chip->ops->request_locality(chip, 0);
if (rc < 0)
goto out_no_locality;
chip->locality = rc;
}
rc = tpm2_prepare_space(chip, space, ordinal, buf);
if (rc)
goto out;
rc = chip->ops->send(chip, (u8 *) buf, count);
if (rc < 0) {
dev_err(&chip->dev,
"tpm_transmit: tpm_send: error %d\n", rc);
goto out;
}
if (chip->flags & TPM_CHIP_FLAG_IRQ)
goto out_recv;
if (chip->flags & TPM_CHIP_FLAG_TPM2)
stop = jiffies + tpm2_calc_ordinal_duration(chip, ordinal);
else
stop = jiffies + tpm_calc_ordinal_duration(chip, ordinal);
do {
u8 status = chip->ops->status(chip);
if ((status & chip->ops->req_complete_mask) ==
chip->ops->req_complete_val)
goto out_recv;
if (chip->ops->req_canceled(chip, status)) {
dev_err(&chip->dev, "Operation Canceled\n");
rc = -ECANCELED;
goto out;
}
msleep(TPM_TIMEOUT);
rmb();
} while (time_before(jiffies, stop));
chip->ops->cancel(chip);
dev_err(&chip->dev, "Operation Timed out\n");
rc = -ETIME;
goto out;
out_recv:
len = chip->ops->recv(chip, (u8 *) buf, bufsiz);
if (len < 0) {
rc = len;
dev_err(&chip->dev,
"tpm_transmit: tpm_recv: error %d\n", rc);
goto out;
} else if (len < TPM_HEADER_SIZE) {
rc = -EFAULT;
goto out;
}
if (len != be32_to_cpu(header->length)) {
rc = -EFAULT;
goto out;
}
rc = tpm2_commit_space(chip, space, ordinal, buf, &len);
out:
if (need_locality && chip->ops->relinquish_locality) {
chip->ops->relinquish_locality(chip, chip->locality);
chip->locality = -1;
}
out_no_locality:
if (chip->dev.parent)
pm_runtime_put_sync(chip->dev.parent);
if (!(flags & TPM_TRANSMIT_UNLOCKED))
mutex_unlock(&chip->tpm_mutex);
return rc ? rc : len;
}
ssize_t tpm_transmit_cmd(struct tpm_chip *chip, struct tpm_space *space,
const void *buf, size_t bufsiz,
size_t min_rsp_body_length, unsigned int flags,
const char *desc)
{
const struct tpm_output_header *header = buf;
int err;
ssize_t len;
len = tpm_transmit(chip, space, (u8 *)buf, bufsiz, flags);
if (len < 0)
return len;
err = be32_to_cpu(header->return_code);
if (err != 0 && desc)
dev_err(&chip->dev, "A TPM error (%d) occurred %s\n", err,
desc);
if (err)
return err;
if (len < min_rsp_body_length + TPM_HEADER_SIZE)
return -EFAULT;
return 0;
}
ssize_t tpm_getcap(struct tpm_chip *chip, u32 subcap_id, cap_t *cap,
const char *desc, size_t min_cap_length)
{
struct tpm_cmd_t tpm_cmd;
int rc;
tpm_cmd.header.in = tpm_getcap_header;
if (subcap_id == TPM_CAP_VERSION_1_1 ||
subcap_id == TPM_CAP_VERSION_1_2) {
tpm_cmd.params.getcap_in.cap = cpu_to_be32(subcap_id);
tpm_cmd.params.getcap_in.subcap_size = cpu_to_be32(0);
tpm_cmd.header.in.length -= cpu_to_be32(sizeof(__be32));
} else {
if (subcap_id == TPM_CAP_FLAG_PERM ||
subcap_id == TPM_CAP_FLAG_VOL)
tpm_cmd.params.getcap_in.cap =
cpu_to_be32(TPM_CAP_FLAG);
else
tpm_cmd.params.getcap_in.cap =
cpu_to_be32(TPM_CAP_PROP);
tpm_cmd.params.getcap_in.subcap_size = cpu_to_be32(4);
tpm_cmd.params.getcap_in.subcap = cpu_to_be32(subcap_id);
}
rc = tpm_transmit_cmd(chip, NULL, &tpm_cmd, TPM_INTERNAL_RESULT_SIZE,
min_cap_length, 0, desc);
if (!rc)
*cap = tpm_cmd.params.getcap_out.cap;
return rc;
}
static int tpm_startup(struct tpm_chip *chip, __be16 startup_type)
{
struct tpm_cmd_t start_cmd;
start_cmd.header.in = tpm_startup_header;
start_cmd.params.startup_in.startup_type = startup_type;
return tpm_transmit_cmd(chip, NULL, &start_cmd,
TPM_INTERNAL_RESULT_SIZE, 0,
0, "attempting to start the TPM");
}
int tpm_get_timeouts(struct tpm_chip *chip)
{
cap_t cap;
unsigned long timeout_old[4], timeout_chip[4], timeout_eff[4];
ssize_t rc;
if (chip->flags & TPM_CHIP_FLAG_HAVE_TIMEOUTS)
return 0;
if (chip->flags & TPM_CHIP_FLAG_TPM2) {
chip->timeout_a = msecs_to_jiffies(TPM2_TIMEOUT_A);
chip->timeout_b = msecs_to_jiffies(TPM2_TIMEOUT_B);
chip->timeout_c = msecs_to_jiffies(TPM2_TIMEOUT_C);
chip->timeout_d = msecs_to_jiffies(TPM2_TIMEOUT_D);
chip->duration[TPM_SHORT] =
msecs_to_jiffies(TPM2_DURATION_SHORT);
chip->duration[TPM_MEDIUM] =
msecs_to_jiffies(TPM2_DURATION_MEDIUM);
chip->duration[TPM_LONG] =
msecs_to_jiffies(TPM2_DURATION_LONG);
chip->flags |= TPM_CHIP_FLAG_HAVE_TIMEOUTS;
return 0;
}
rc = tpm_getcap(chip, TPM_CAP_PROP_TIS_TIMEOUT, &cap, NULL,
sizeof(cap.timeout));
if (rc == TPM_ERR_INVALID_POSTINIT) {
dev_info(&chip->dev, "Issuing TPM_STARTUP\n");
if (tpm_startup(chip, TPM_ST_CLEAR))
return rc;
rc = tpm_getcap(chip, TPM_CAP_PROP_TIS_TIMEOUT, &cap,
"attempting to determine the timeouts",
sizeof(cap.timeout));
}
if (rc) {
dev_err(&chip->dev,
"A TPM error (%zd) occurred attempting to determine the timeouts\n",
rc);
return rc;
}
timeout_old[0] = jiffies_to_usecs(chip->timeout_a);
timeout_old[1] = jiffies_to_usecs(chip->timeout_b);
timeout_old[2] = jiffies_to_usecs(chip->timeout_c);
timeout_old[3] = jiffies_to_usecs(chip->timeout_d);
timeout_chip[0] = be32_to_cpu(cap.timeout.a);
timeout_chip[1] = be32_to_cpu(cap.timeout.b);
timeout_chip[2] = be32_to_cpu(cap.timeout.c);
timeout_chip[3] = be32_to_cpu(cap.timeout.d);
memcpy(timeout_eff, timeout_chip, sizeof(timeout_eff));
if (chip->ops->update_timeouts != NULL)
chip->timeout_adjusted =
chip->ops->update_timeouts(chip, timeout_eff);
if (!chip->timeout_adjusted) {
int i;
for (i = 0; i < ARRAY_SIZE(timeout_eff); i++) {
if (timeout_eff[i])
continue;
timeout_eff[i] = timeout_old[i];
chip->timeout_adjusted = true;
}
if (timeout_eff[0] != 0 && timeout_eff[0] < 1000) {
for (i = 0; i != ARRAY_SIZE(timeout_eff); i++)
timeout_eff[i] *= 1000;
chip->timeout_adjusted = true;
}
}
if (chip->timeout_adjusted) {
dev_info(&chip->dev,
HW_ERR "Adjusting reported timeouts: A %lu->%luus B %lu->%luus C %lu->%luus D %lu->%luus\n",
timeout_chip[0], timeout_eff[0],
timeout_chip[1], timeout_eff[1],
timeout_chip[2], timeout_eff[2],
timeout_chip[3], timeout_eff[3]);
}
chip->timeout_a = usecs_to_jiffies(timeout_eff[0]);
chip->timeout_b = usecs_to_jiffies(timeout_eff[1]);
chip->timeout_c = usecs_to_jiffies(timeout_eff[2]);
chip->timeout_d = usecs_to_jiffies(timeout_eff[3]);
rc = tpm_getcap(chip, TPM_CAP_PROP_TIS_DURATION, &cap,
"attempting to determine the durations",
sizeof(cap.duration));
if (rc)
return rc;
chip->duration[TPM_SHORT] =
usecs_to_jiffies(be32_to_cpu(cap.duration.tpm_short));
chip->duration[TPM_MEDIUM] =
usecs_to_jiffies(be32_to_cpu(cap.duration.tpm_medium));
chip->duration[TPM_LONG] =
usecs_to_jiffies(be32_to_cpu(cap.duration.tpm_long));
if (chip->duration[TPM_SHORT] < (HZ / 100)) {
chip->duration[TPM_SHORT] = HZ;
chip->duration[TPM_MEDIUM] *= 1000;
chip->duration[TPM_LONG] *= 1000;
chip->duration_adjusted = true;
dev_info(&chip->dev, "Adjusting TPM timeout parameters.");
}
chip->flags |= TPM_CHIP_FLAG_HAVE_TIMEOUTS;
return 0;
}
static int tpm_continue_selftest(struct tpm_chip *chip)
{
int rc;
struct tpm_cmd_t cmd;
cmd.header.in = continue_selftest_header;
rc = tpm_transmit_cmd(chip, NULL, &cmd, CONTINUE_SELFTEST_RESULT_SIZE,
0, 0, "continue selftest");
return rc;
}
int tpm_pcr_read_dev(struct tpm_chip *chip, int pcr_idx, u8 *res_buf)
{
int rc;
struct tpm_cmd_t cmd;
cmd.header.in = pcrread_header;
cmd.params.pcrread_in.pcr_idx = cpu_to_be32(pcr_idx);
rc = tpm_transmit_cmd(chip, NULL, &cmd, READ_PCR_RESULT_SIZE,
READ_PCR_RESULT_BODY_SIZE, 0,
"attempting to read a pcr value");
if (rc == 0)
memcpy(res_buf, cmd.params.pcrread_out.pcr_result,
TPM_DIGEST_SIZE);
return rc;
}
int tpm_is_tpm2(u32 chip_num)
{
struct tpm_chip *chip;
int rc;
chip = tpm_chip_find_get(chip_num);
if (chip == NULL)
return -ENODEV;
rc = (chip->flags & TPM_CHIP_FLAG_TPM2) != 0;
tpm_put_ops(chip);
return rc;
}
int tpm_pcr_read(u32 chip_num, int pcr_idx, u8 *res_buf)
{
struct tpm_chip *chip;
int rc;
chip = tpm_chip_find_get(chip_num);
if (chip == NULL)
return -ENODEV;
if (chip->flags & TPM_CHIP_FLAG_TPM2)
rc = tpm2_pcr_read(chip, pcr_idx, res_buf);
else
rc = tpm_pcr_read_dev(chip, pcr_idx, res_buf);
tpm_put_ops(chip);
return rc;
}
int tpm_pcr_extend(u32 chip_num, int pcr_idx, const u8 *hash)
{
struct tpm_cmd_t cmd;
int rc;
struct tpm_chip *chip;
struct tpm2_digest digest_list[ARRAY_SIZE(chip->active_banks)];
u32 count = 0;
int i;
chip = tpm_chip_find_get(chip_num);
if (chip == NULL)
return -ENODEV;
if (chip->flags & TPM_CHIP_FLAG_TPM2) {
memset(digest_list, 0, sizeof(digest_list));
for (i = 0; i < ARRAY_SIZE(chip->active_banks) &&
chip->active_banks[i] != TPM2_ALG_ERROR; i++) {
digest_list[i].alg_id = chip->active_banks[i];
memcpy(digest_list[i].digest, hash, TPM_DIGEST_SIZE);
count++;
}
rc = tpm2_pcr_extend(chip, pcr_idx, count, digest_list);
tpm_put_ops(chip);
return rc;
}
cmd.header.in = pcrextend_header;
cmd.params.pcrextend_in.pcr_idx = cpu_to_be32(pcr_idx);
memcpy(cmd.params.pcrextend_in.hash, hash, TPM_DIGEST_SIZE);
rc = tpm_transmit_cmd(chip, NULL, &cmd, EXTEND_PCR_RESULT_SIZE,
EXTEND_PCR_RESULT_BODY_SIZE, 0,
"attempting extend a PCR value");
tpm_put_ops(chip);
return rc;
}
int tpm_do_selftest(struct tpm_chip *chip)
{
int rc;
unsigned int loops;
unsigned int delay_msec = 100;
unsigned long duration;
u8 dummy[TPM_DIGEST_SIZE];
duration = tpm_calc_ordinal_duration(chip, TPM_ORD_CONTINUE_SELFTEST);
loops = jiffies_to_msecs(duration) / delay_msec;
rc = tpm_continue_selftest(chip);
if (rc)
return rc;
do {
rc = tpm_pcr_read_dev(chip, 0, dummy);
if (rc == -ETIME) {
dev_info(
&chip->dev, HW_ERR
"TPM command timed out during continue self test");
msleep(delay_msec);
continue;
}
if (rc == TPM_ERR_DISABLED || rc == TPM_ERR_DEACTIVATED) {
dev_info(&chip->dev,
"TPM is disabled/deactivated (0x%X)\n", rc);
return 0;
}
if (rc != TPM_WARN_DOING_SELFTEST)
return rc;
msleep(delay_msec);
} while (--loops > 0);
return rc;
}
int tpm1_auto_startup(struct tpm_chip *chip)
{
int rc;
rc = tpm_get_timeouts(chip);
if (rc)
goto out;
rc = tpm_do_selftest(chip);
if (rc) {
dev_err(&chip->dev, "TPM self test failed\n");
goto out;
}
return rc;
out:
if (rc > 0)
rc = -ENODEV;
return rc;
}
int tpm_send(u32 chip_num, void *cmd, size_t buflen)
{
struct tpm_chip *chip;
int rc;
chip = tpm_chip_find_get(chip_num);
if (chip == NULL)
return -ENODEV;
rc = tpm_transmit_cmd(chip, NULL, cmd, buflen, 0, 0,
"attempting tpm_cmd");
tpm_put_ops(chip);
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
if (chip->flags & TPM_CHIP_FLAG_IRQ) {
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
int tpm_pm_suspend(struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
struct tpm_cmd_t cmd;
int rc, try;
u8 dummy_hash[TPM_DIGEST_SIZE] = { 0 };
if (chip == NULL)
return -ENODEV;
if (chip->flags & TPM_CHIP_FLAG_TPM2) {
tpm2_shutdown(chip, TPM2_SU_STATE);
return 0;
}
if (tpm_suspend_pcr) {
cmd.header.in = pcrextend_header;
cmd.params.pcrextend_in.pcr_idx = cpu_to_be32(tpm_suspend_pcr);
memcpy(cmd.params.pcrextend_in.hash, dummy_hash,
TPM_DIGEST_SIZE);
rc = tpm_transmit_cmd(chip, NULL, &cmd, EXTEND_PCR_RESULT_SIZE,
EXTEND_PCR_RESULT_BODY_SIZE, 0,
"extending dummy pcr before suspend");
}
for (try = 0; try < TPM_RETRY; try++) {
cmd.header.in = savestate_header;
rc = tpm_transmit_cmd(chip, NULL, &cmd, SAVESTATE_RESULT_SIZE,
0, 0, NULL);
if (rc != TPM_WARN_RETRY)
break;
msleep(TPM_TIMEOUT_RETRY);
}
if (rc)
dev_err(&chip->dev,
"Error (%d) sending savestate before suspend\n", rc);
else if (try > 0)
dev_warn(&chip->dev, "TPM savestate took %dms\n",
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
u32 recd, num_bytes = min_t(u32, max, TPM_MAX_RNG_DATA), rlength;
int err, total = 0, retries = 5;
u8 *dest = out;
if (!out || !num_bytes || max > TPM_MAX_RNG_DATA)
return -EINVAL;
chip = tpm_chip_find_get(chip_num);
if (chip == NULL)
return -ENODEV;
if (chip->flags & TPM_CHIP_FLAG_TPM2) {
err = tpm2_get_random(chip, out, max);
tpm_put_ops(chip);
return err;
}
do {
tpm_cmd.header.in = tpm_getrandom_header;
tpm_cmd.params.getrandom_in.num_bytes = cpu_to_be32(num_bytes);
err = tpm_transmit_cmd(chip, NULL, &tpm_cmd,
TPM_GETRANDOM_RESULT_SIZE + num_bytes,
offsetof(struct tpm_getrandom_out,
rng_data),
0, "attempting get random");
if (err)
break;
recd = be32_to_cpu(tpm_cmd.params.getrandom_out.rng_data_len);
rlength = be32_to_cpu(tpm_cmd.header.out.length);
if (rlength < offsetof(struct tpm_getrandom_out, rng_data) +
recd) {
total = -EFAULT;
break;
}
memcpy(dest, tpm_cmd.params.getrandom_out.rng_data, recd);
dest += recd;
total += recd;
num_bytes -= recd;
} while (retries-- && total < max);
tpm_put_ops(chip);
return total ? total : -EIO;
}
int tpm_seal_trusted(u32 chip_num, struct trusted_key_payload *payload,
struct trusted_key_options *options)
{
struct tpm_chip *chip;
int rc;
chip = tpm_chip_find_get(chip_num);
if (chip == NULL || !(chip->flags & TPM_CHIP_FLAG_TPM2))
return -ENODEV;
rc = tpm2_seal_trusted(chip, payload, options);
tpm_put_ops(chip);
return rc;
}
int tpm_unseal_trusted(u32 chip_num, struct trusted_key_payload *payload,
struct trusted_key_options *options)
{
struct tpm_chip *chip;
int rc;
chip = tpm_chip_find_get(chip_num);
if (chip == NULL || !(chip->flags & TPM_CHIP_FLAG_TPM2))
return -ENODEV;
rc = tpm2_unseal_trusted(chip, payload, options);
tpm_put_ops(chip);
return rc;
}
static int __init tpm_init(void)
{
int rc;
tpm_class = class_create(THIS_MODULE, "tpm");
if (IS_ERR(tpm_class)) {
pr_err("couldn't create tpm class\n");
return PTR_ERR(tpm_class);
}
tpmrm_class = class_create(THIS_MODULE, "tpmrm");
if (IS_ERR(tpmrm_class)) {
pr_err("couldn't create tpmrm class\n");
class_destroy(tpm_class);
return PTR_ERR(tpmrm_class);
}
rc = alloc_chrdev_region(&tpm_devt, 0, 2*TPM_NUM_DEVICES, "tpm");
if (rc < 0) {
pr_err("tpm: failed to allocate char dev region\n");
class_destroy(tpmrm_class);
class_destroy(tpm_class);
return rc;
}
return 0;
}
static void __exit tpm_exit(void)
{
idr_destroy(&dev_nums_idr);
class_destroy(tpm_class);
class_destroy(tpmrm_class);
unregister_chrdev_region(tpm_devt, 2*TPM_NUM_DEVICES);
}
