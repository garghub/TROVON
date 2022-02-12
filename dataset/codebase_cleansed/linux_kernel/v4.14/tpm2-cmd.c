int tpm2_pcr_read(struct tpm_chip *chip, int pcr_idx, u8 *res_buf)
{
int rc;
struct tpm_buf buf;
struct tpm2_pcr_read_out *out;
u8 pcr_select[TPM2_PCR_SELECT_MIN] = {0};
if (pcr_idx >= TPM2_PLATFORM_PCR)
return -EINVAL;
rc = tpm_buf_init(&buf, TPM2_ST_NO_SESSIONS, TPM2_CC_PCR_READ);
if (rc)
return rc;
pcr_select[pcr_idx >> 3] = 1 << (pcr_idx & 0x7);
tpm_buf_append_u32(&buf, 1);
tpm_buf_append_u16(&buf, TPM2_ALG_SHA1);
tpm_buf_append_u8(&buf, TPM2_PCR_SELECT_MIN);
tpm_buf_append(&buf, (const unsigned char *)pcr_select,
sizeof(pcr_select));
rc = tpm_transmit_cmd(chip, NULL, buf.data, PAGE_SIZE, 0, 0,
res_buf ? "attempting to read a pcr value" : NULL);
if (rc == 0 && res_buf) {
out = (struct tpm2_pcr_read_out *)&buf.data[TPM_HEADER_SIZE];
memcpy(res_buf, out->digest, SHA1_DIGEST_SIZE);
}
tpm_buf_destroy(&buf);
return rc;
}
int tpm2_pcr_extend(struct tpm_chip *chip, int pcr_idx, u32 count,
struct tpm2_digest *digests)
{
struct tpm_buf buf;
struct tpm2_null_auth_area auth_area;
int rc;
int i;
int j;
if (count > ARRAY_SIZE(chip->active_banks))
return -EINVAL;
rc = tpm_buf_init(&buf, TPM2_ST_SESSIONS, TPM2_CC_PCR_EXTEND);
if (rc)
return rc;
tpm_buf_append_u32(&buf, pcr_idx);
auth_area.handle = cpu_to_be32(TPM2_RS_PW);
auth_area.nonce_size = 0;
auth_area.attributes = 0;
auth_area.auth_size = 0;
tpm_buf_append_u32(&buf, sizeof(struct tpm2_null_auth_area));
tpm_buf_append(&buf, (const unsigned char *)&auth_area,
sizeof(auth_area));
tpm_buf_append_u32(&buf, count);
for (i = 0; i < count; i++) {
for (j = 0; j < ARRAY_SIZE(tpm2_hash_map); j++) {
if (digests[i].alg_id != tpm2_hash_map[j].tpm_id)
continue;
tpm_buf_append_u16(&buf, digests[i].alg_id);
tpm_buf_append(&buf, (const unsigned char
*)&digests[i].digest,
hash_digest_size[tpm2_hash_map[j].crypto_id]);
}
}
rc = tpm_transmit_cmd(chip, NULL, buf.data, PAGE_SIZE, 0, 0,
"attempting extend a PCR value");
tpm_buf_destroy(&buf);
return rc;
}
int tpm2_get_random(struct tpm_chip *chip, u8 *out, size_t max)
{
struct tpm2_cmd cmd;
u32 recd, rlength;
u32 num_bytes;
int err;
int total = 0;
int retries = 5;
u8 *dest = out;
num_bytes = min_t(u32, max, sizeof(cmd.params.getrandom_out.buffer));
if (!out || !num_bytes ||
max > sizeof(cmd.params.getrandom_out.buffer))
return -EINVAL;
do {
cmd.header.in = tpm2_getrandom_header;
cmd.params.getrandom_in.size = cpu_to_be16(num_bytes);
err = tpm_transmit_cmd(chip, NULL, &cmd, sizeof(cmd),
offsetof(struct tpm2_get_random_out,
buffer),
0, "attempting get random");
if (err)
break;
recd = min_t(u32, be16_to_cpu(cmd.params.getrandom_out.size),
num_bytes);
rlength = be32_to_cpu(cmd.header.out.length);
if (rlength < offsetof(struct tpm2_get_random_out, buffer) +
recd)
return -EFAULT;
memcpy(dest, cmd.params.getrandom_out.buffer, recd);
dest += recd;
total += recd;
num_bytes -= recd;
} while (retries-- && total < max);
return total ? total : -EIO;
}
void tpm2_flush_context_cmd(struct tpm_chip *chip, u32 handle,
unsigned int flags)
{
struct tpm_buf buf;
int rc;
rc = tpm_buf_init(&buf, TPM2_ST_NO_SESSIONS, TPM2_CC_FLUSH_CONTEXT);
if (rc) {
dev_warn(&chip->dev, "0x%08x was not flushed, out of memory\n",
handle);
return;
}
tpm_buf_append_u32(&buf, handle);
(void) tpm_transmit_cmd(chip, NULL, buf.data, PAGE_SIZE, 0, flags,
"flushing context");
tpm_buf_destroy(&buf);
}
static void tpm2_buf_append_auth(struct tpm_buf *buf, u32 session_handle,
const u8 *nonce, u16 nonce_len,
u8 attributes,
const u8 *hmac, u16 hmac_len)
{
tpm_buf_append_u32(buf, 9 + nonce_len + hmac_len);
tpm_buf_append_u32(buf, session_handle);
tpm_buf_append_u16(buf, nonce_len);
if (nonce && nonce_len)
tpm_buf_append(buf, nonce, nonce_len);
tpm_buf_append_u8(buf, attributes);
tpm_buf_append_u16(buf, hmac_len);
if (hmac && hmac_len)
tpm_buf_append(buf, hmac, hmac_len);
}
int tpm2_seal_trusted(struct tpm_chip *chip,
struct trusted_key_payload *payload,
struct trusted_key_options *options)
{
unsigned int blob_len;
struct tpm_buf buf;
u32 hash, rlength;
int i;
int rc;
for (i = 0; i < ARRAY_SIZE(tpm2_hash_map); i++) {
if (options->hash == tpm2_hash_map[i].crypto_id) {
hash = tpm2_hash_map[i].tpm_id;
break;
}
}
if (i == ARRAY_SIZE(tpm2_hash_map))
return -EINVAL;
rc = tpm_buf_init(&buf, TPM2_ST_SESSIONS, TPM2_CC_CREATE);
if (rc)
return rc;
tpm_buf_append_u32(&buf, options->keyhandle);
tpm2_buf_append_auth(&buf, TPM2_RS_PW,
NULL , 0,
0 ,
options->keyauth ,
TPM_DIGEST_SIZE);
tpm_buf_append_u16(&buf, 4 + TPM_DIGEST_SIZE + payload->key_len + 1);
tpm_buf_append_u16(&buf, TPM_DIGEST_SIZE);
tpm_buf_append(&buf, options->blobauth, TPM_DIGEST_SIZE);
tpm_buf_append_u16(&buf, payload->key_len + 1);
tpm_buf_append(&buf, payload->key, payload->key_len);
tpm_buf_append_u8(&buf, payload->migratable);
tpm_buf_append_u16(&buf, 14 + options->policydigest_len);
tpm_buf_append_u16(&buf, TPM2_ALG_KEYEDHASH);
tpm_buf_append_u16(&buf, hash);
if (options->policydigest_len) {
tpm_buf_append_u32(&buf, 0);
tpm_buf_append_u16(&buf, options->policydigest_len);
tpm_buf_append(&buf, options->policydigest,
options->policydigest_len);
} else {
tpm_buf_append_u32(&buf, TPM2_OA_USER_WITH_AUTH);
tpm_buf_append_u16(&buf, 0);
}
tpm_buf_append_u16(&buf, TPM2_ALG_NULL);
tpm_buf_append_u16(&buf, 0);
tpm_buf_append_u16(&buf, 0);
tpm_buf_append_u32(&buf, 0);
if (buf.flags & TPM_BUF_OVERFLOW) {
rc = -E2BIG;
goto out;
}
rc = tpm_transmit_cmd(chip, NULL, buf.data, PAGE_SIZE, 4, 0,
"sealing data");
if (rc)
goto out;
blob_len = be32_to_cpup((__be32 *) &buf.data[TPM_HEADER_SIZE]);
if (blob_len > MAX_BLOB_SIZE) {
rc = -E2BIG;
goto out;
}
rlength = be32_to_cpu(((struct tpm2_cmd *)&buf)->header.out.length);
if (rlength < TPM_HEADER_SIZE + 4 + blob_len) {
rc = -EFAULT;
goto out;
}
memcpy(payload->blob, &buf.data[TPM_HEADER_SIZE + 4], blob_len);
payload->blob_len = blob_len;
out:
tpm_buf_destroy(&buf);
if (rc > 0) {
if (tpm2_rc_value(rc) == TPM2_RC_HASH)
rc = -EINVAL;
else
rc = -EPERM;
}
return rc;
}
static int tpm2_load_cmd(struct tpm_chip *chip,
struct trusted_key_payload *payload,
struct trusted_key_options *options,
u32 *blob_handle, unsigned int flags)
{
struct tpm_buf buf;
unsigned int private_len;
unsigned int public_len;
unsigned int blob_len;
int rc;
private_len = be16_to_cpup((__be16 *) &payload->blob[0]);
if (private_len > (payload->blob_len - 2))
return -E2BIG;
public_len = be16_to_cpup((__be16 *) &payload->blob[2 + private_len]);
blob_len = private_len + public_len + 4;
if (blob_len > payload->blob_len)
return -E2BIG;
rc = tpm_buf_init(&buf, TPM2_ST_SESSIONS, TPM2_CC_LOAD);
if (rc)
return rc;
tpm_buf_append_u32(&buf, options->keyhandle);
tpm2_buf_append_auth(&buf, TPM2_RS_PW,
NULL , 0,
0 ,
options->keyauth ,
TPM_DIGEST_SIZE);
tpm_buf_append(&buf, payload->blob, blob_len);
if (buf.flags & TPM_BUF_OVERFLOW) {
rc = -E2BIG;
goto out;
}
rc = tpm_transmit_cmd(chip, NULL, buf.data, PAGE_SIZE, 4, flags,
"loading blob");
if (!rc)
*blob_handle = be32_to_cpup(
(__be32 *) &buf.data[TPM_HEADER_SIZE]);
out:
tpm_buf_destroy(&buf);
if (rc > 0)
rc = -EPERM;
return rc;
}
static int tpm2_unseal_cmd(struct tpm_chip *chip,
struct trusted_key_payload *payload,
struct trusted_key_options *options,
u32 blob_handle, unsigned int flags)
{
struct tpm_buf buf;
u16 data_len;
u8 *data;
int rc;
u32 rlength;
rc = tpm_buf_init(&buf, TPM2_ST_SESSIONS, TPM2_CC_UNSEAL);
if (rc)
return rc;
tpm_buf_append_u32(&buf, blob_handle);
tpm2_buf_append_auth(&buf,
options->policyhandle ?
options->policyhandle : TPM2_RS_PW,
NULL , 0,
TPM2_SA_CONTINUE_SESSION,
options->blobauth ,
TPM_DIGEST_SIZE);
rc = tpm_transmit_cmd(chip, NULL, buf.data, PAGE_SIZE, 6, flags,
"unsealing");
if (rc > 0)
rc = -EPERM;
if (!rc) {
data_len = be16_to_cpup(
(__be16 *) &buf.data[TPM_HEADER_SIZE + 4]);
rlength = be32_to_cpu(((struct tpm2_cmd *)&buf)
->header.out.length);
if (rlength < TPM_HEADER_SIZE + 6 + data_len) {
rc = -EFAULT;
goto out;
}
data = &buf.data[TPM_HEADER_SIZE + 6];
memcpy(payload->key, data, data_len - 1);
payload->key_len = data_len - 1;
payload->migratable = data[data_len - 1];
}
out:
tpm_buf_destroy(&buf);
return rc;
}
int tpm2_unseal_trusted(struct tpm_chip *chip,
struct trusted_key_payload *payload,
struct trusted_key_options *options)
{
u32 blob_handle;
int rc;
mutex_lock(&chip->tpm_mutex);
rc = tpm2_load_cmd(chip, payload, options, &blob_handle,
TPM_TRANSMIT_UNLOCKED);
if (rc)
goto out;
rc = tpm2_unseal_cmd(chip, payload, options, blob_handle,
TPM_TRANSMIT_UNLOCKED);
tpm2_flush_context_cmd(chip, blob_handle, TPM_TRANSMIT_UNLOCKED);
out:
mutex_unlock(&chip->tpm_mutex);
return rc;
}
ssize_t tpm2_get_tpm_pt(struct tpm_chip *chip, u32 property_id, u32 *value,
const char *desc)
{
struct tpm2_cmd cmd;
int rc;
cmd.header.in = tpm2_get_tpm_pt_header;
cmd.params.get_tpm_pt_in.cap_id = cpu_to_be32(TPM2_CAP_TPM_PROPERTIES);
cmd.params.get_tpm_pt_in.property_id = cpu_to_be32(property_id);
cmd.params.get_tpm_pt_in.property_cnt = cpu_to_be32(1);
rc = tpm_transmit_cmd(chip, NULL, &cmd, sizeof(cmd),
TPM2_GET_TPM_PT_OUT_BODY_SIZE, 0, desc);
if (!rc)
*value = be32_to_cpu(cmd.params.get_tpm_pt_out.value);
return rc;
}
void tpm2_shutdown(struct tpm_chip *chip, u16 shutdown_type)
{
struct tpm2_cmd cmd;
int rc;
cmd.header.in = tpm2_shutdown_header;
cmd.params.startup_in.startup_type = cpu_to_be16(shutdown_type);
rc = tpm_transmit_cmd(chip, NULL, &cmd, sizeof(cmd), 0, 0,
"stopping the TPM");
if (rc < 0 && rc != -EPIPE)
dev_warn(&chip->dev, "transmit returned %d while stopping the TPM",
rc);
}
unsigned long tpm2_calc_ordinal_duration(struct tpm_chip *chip, u32 ordinal)
{
int index = TPM_UNDEFINED;
int duration = 0;
if (ordinal >= TPM2_CC_FIRST && ordinal <= TPM2_CC_LAST)
index = tpm2_ordinal_duration[ordinal - TPM2_CC_FIRST];
if (index != TPM_UNDEFINED)
duration = chip->duration[index];
if (duration <= 0)
duration = 2 * 60 * HZ;
return duration;
}
static int tpm2_start_selftest(struct tpm_chip *chip, bool full)
{
int rc;
struct tpm2_cmd cmd;
cmd.header.in = tpm2_selftest_header;
cmd.params.selftest_in.full_test = full;
rc = tpm_transmit_cmd(chip, NULL, &cmd, TPM2_SELF_TEST_IN_SIZE, 0, 0,
"continue selftest");
if (rc == TPM2_RC_TESTING) {
dev_warn(&chip->dev, "Got RC_TESTING, ignoring\n");
rc = 0;
}
return rc;
}
static int tpm2_do_selftest(struct tpm_chip *chip)
{
int rc;
unsigned int loops;
unsigned int delay_msec = 100;
unsigned long duration;
int i;
duration = tpm2_calc_ordinal_duration(chip, TPM2_CC_SELF_TEST);
loops = jiffies_to_msecs(duration) / delay_msec;
rc = tpm2_start_selftest(chip, true);
if (rc)
return rc;
for (i = 0; i < loops; i++) {
rc = tpm2_pcr_read(chip, 0, NULL);
if (rc < 0)
break;
if (rc != TPM2_RC_TESTING)
break;
tpm_msleep(delay_msec);
}
return rc;
}
int tpm2_probe(struct tpm_chip *chip)
{
struct tpm2_cmd cmd;
int rc;
cmd.header.in = tpm2_get_tpm_pt_header;
cmd.params.get_tpm_pt_in.cap_id = cpu_to_be32(TPM2_CAP_TPM_PROPERTIES);
cmd.params.get_tpm_pt_in.property_id = cpu_to_be32(0x100);
cmd.params.get_tpm_pt_in.property_cnt = cpu_to_be32(1);
rc = tpm_transmit_cmd(chip, NULL, &cmd, sizeof(cmd), 0, 0, NULL);
if (rc < 0)
return rc;
if (be16_to_cpu(cmd.header.out.tag) == TPM2_ST_NO_SESSIONS)
chip->flags |= TPM_CHIP_FLAG_TPM2;
return 0;
}
static ssize_t tpm2_get_pcr_allocation(struct tpm_chip *chip)
{
struct tpm2_pcr_selection pcr_selection;
struct tpm_buf buf;
void *marker;
void *end;
void *pcr_select_offset;
unsigned int count;
u32 sizeof_pcr_selection;
u32 rsp_len;
int rc;
int i = 0;
rc = tpm_buf_init(&buf, TPM2_ST_NO_SESSIONS, TPM2_CC_GET_CAPABILITY);
if (rc)
return rc;
tpm_buf_append_u32(&buf, TPM2_CAP_PCRS);
tpm_buf_append_u32(&buf, 0);
tpm_buf_append_u32(&buf, 1);
rc = tpm_transmit_cmd(chip, NULL, buf.data, PAGE_SIZE, 9, 0,
"get tpm pcr allocation");
if (rc)
goto out;
count = be32_to_cpup(
(__be32 *)&buf.data[TPM_HEADER_SIZE + 5]);
if (count > ARRAY_SIZE(chip->active_banks)) {
rc = -ENODEV;
goto out;
}
marker = &buf.data[TPM_HEADER_SIZE + 9];
rsp_len = be32_to_cpup((__be32 *)&buf.data[2]);
end = &buf.data[rsp_len];
for (i = 0; i < count; i++) {
pcr_select_offset = marker +
offsetof(struct tpm2_pcr_selection, size_of_select);
if (pcr_select_offset >= end) {
rc = -EFAULT;
break;
}
memcpy(&pcr_selection, marker, sizeof(pcr_selection));
chip->active_banks[i] = be16_to_cpu(pcr_selection.hash_alg);
sizeof_pcr_selection = sizeof(pcr_selection.hash_alg) +
sizeof(pcr_selection.size_of_select) +
pcr_selection.size_of_select;
marker = marker + sizeof_pcr_selection;
}
out:
if (i < ARRAY_SIZE(chip->active_banks))
chip->active_banks[i] = TPM2_ALG_ERROR;
tpm_buf_destroy(&buf);
return rc;
}
static int tpm2_get_cc_attrs_tbl(struct tpm_chip *chip)
{
struct tpm_buf buf;
u32 nr_commands;
u32 *attrs;
u32 cc;
int i;
int rc;
rc = tpm2_get_tpm_pt(chip, TPM_PT_TOTAL_COMMANDS, &nr_commands, NULL);
if (rc)
goto out;
if (nr_commands > 0xFFFFF) {
rc = -EFAULT;
goto out;
}
chip->cc_attrs_tbl = devm_kzalloc(&chip->dev, 4 * nr_commands,
GFP_KERNEL);
rc = tpm_buf_init(&buf, TPM2_ST_NO_SESSIONS, TPM2_CC_GET_CAPABILITY);
if (rc)
goto out;
tpm_buf_append_u32(&buf, TPM2_CAP_COMMANDS);
tpm_buf_append_u32(&buf, TPM2_CC_FIRST);
tpm_buf_append_u32(&buf, nr_commands);
rc = tpm_transmit_cmd(chip, NULL, buf.data, PAGE_SIZE,
9 + 4 * nr_commands, 0, NULL);
if (rc) {
tpm_buf_destroy(&buf);
goto out;
}
if (nr_commands !=
be32_to_cpup((__be32 *)&buf.data[TPM_HEADER_SIZE + 5])) {
tpm_buf_destroy(&buf);
goto out;
}
chip->nr_commands = nr_commands;
attrs = (u32 *)&buf.data[TPM_HEADER_SIZE + 9];
for (i = 0; i < nr_commands; i++, attrs++) {
chip->cc_attrs_tbl[i] = be32_to_cpup(attrs);
cc = chip->cc_attrs_tbl[i] & 0xFFFF;
if (cc == TPM2_CC_CONTEXT_SAVE || cc == TPM2_CC_FLUSH_CONTEXT) {
chip->cc_attrs_tbl[i] &=
~(GENMASK(2, 0) << TPM2_CC_ATTR_CHANDLES);
chip->cc_attrs_tbl[i] |= 1 << TPM2_CC_ATTR_CHANDLES;
}
}
tpm_buf_destroy(&buf);
out:
if (rc > 0)
rc = -ENODEV;
return rc;
}
int tpm2_auto_startup(struct tpm_chip *chip)
{
int rc;
rc = tpm_get_timeouts(chip);
if (rc)
goto out;
rc = tpm2_do_selftest(chip);
if (rc != 0 && rc != TPM2_RC_INITIALIZE) {
dev_err(&chip->dev, "TPM self test failed\n");
goto out;
}
if (rc == TPM2_RC_INITIALIZE) {
rc = tpm_startup(chip);
if (rc)
goto out;
rc = tpm2_do_selftest(chip);
if (rc) {
dev_err(&chip->dev, "TPM self test failed\n");
goto out;
}
}
rc = tpm2_get_pcr_allocation(chip);
if (rc)
goto out;
rc = tpm2_get_cc_attrs_tbl(chip);
out:
if (rc > 0)
rc = -ENODEV;
return rc;
}
int tpm2_find_cc(struct tpm_chip *chip, u32 cc)
{
int i;
for (i = 0; i < chip->nr_commands; i++)
if (cc == (chip->cc_attrs_tbl[i] & GENMASK(15, 0)))
return i;
return -1;
}
