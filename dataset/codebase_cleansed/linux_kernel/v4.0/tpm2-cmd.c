int tpm2_pcr_read(struct tpm_chip *chip, int pcr_idx, u8 *res_buf)
{
int rc;
struct tpm2_cmd cmd;
u8 *buf;
if (pcr_idx >= TPM2_PLATFORM_PCR)
return -EINVAL;
cmd.header.in = tpm2_pcrread_header;
cmd.params.pcrread_in.pcr_selects_cnt = cpu_to_be32(1);
cmd.params.pcrread_in.hash_alg = cpu_to_be16(TPM2_ALG_SHA1);
cmd.params.pcrread_in.pcr_select_size = TPM2_PCR_SELECT_MIN;
memset(cmd.params.pcrread_in.pcr_select, 0,
sizeof(cmd.params.pcrread_in.pcr_select));
cmd.params.pcrread_in.pcr_select[pcr_idx >> 3] = 1 << (pcr_idx & 0x7);
rc = tpm_transmit_cmd(chip, &cmd, sizeof(cmd),
"attempting to read a pcr value");
if (rc == 0) {
buf = cmd.params.pcrread_out.digest;
memcpy(res_buf, buf, TPM_DIGEST_SIZE);
}
return rc;
}
int tpm2_pcr_extend(struct tpm_chip *chip, int pcr_idx, const u8 *hash)
{
struct tpm2_cmd cmd;
int rc;
cmd.header.in = tpm2_pcrextend_header;
cmd.params.pcrextend_in.pcr_idx = cpu_to_be32(pcr_idx);
cmd.params.pcrextend_in.auth_area_size =
cpu_to_be32(sizeof(struct tpm2_null_auth_area));
cmd.params.pcrextend_in.auth_area.handle =
cpu_to_be32(TPM2_RS_PW);
cmd.params.pcrextend_in.auth_area.nonce_size = 0;
cmd.params.pcrextend_in.auth_area.attributes = 0;
cmd.params.pcrextend_in.auth_area.auth_size = 0;
cmd.params.pcrextend_in.digest_cnt = cpu_to_be32(1);
cmd.params.pcrextend_in.hash_alg = cpu_to_be16(TPM2_ALG_SHA1);
memcpy(cmd.params.pcrextend_in.digest, hash, TPM_DIGEST_SIZE);
rc = tpm_transmit_cmd(chip, &cmd, sizeof(cmd),
"attempting extend a PCR value");
return rc;
}
int tpm2_get_random(struct tpm_chip *chip, u8 *out, size_t max)
{
struct tpm2_cmd cmd;
u32 recd;
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
err = tpm_transmit_cmd(chip, &cmd, sizeof(cmd),
"attempting get random");
if (err)
break;
recd = min_t(u32, be16_to_cpu(cmd.params.getrandom_out.size),
num_bytes);
memcpy(dest, cmd.params.getrandom_out.buffer, recd);
dest += recd;
total += recd;
num_bytes -= recd;
} while (retries-- && total < max);
return total ? total : -EIO;
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
rc = tpm_transmit_cmd(chip, &cmd, sizeof(cmd), desc);
if (!rc)
*value = cmd.params.get_tpm_pt_out.value;
return rc;
}
int tpm2_startup(struct tpm_chip *chip, u16 startup_type)
{
struct tpm2_cmd cmd;
cmd.header.in = tpm2_startup_header;
cmd.params.startup_in.startup_type = cpu_to_be16(startup_type);
return tpm_transmit_cmd(chip, &cmd, sizeof(cmd),
"attempting to start the TPM");
}
void tpm2_shutdown(struct tpm_chip *chip, u16 shutdown_type)
{
struct tpm2_cmd cmd;
int rc;
cmd.header.in = tpm2_shutdown_header;
cmd.params.startup_in.startup_type = cpu_to_be16(shutdown_type);
rc = tpm_transmit_cmd(chip, &cmd, sizeof(cmd), "stopping the TPM");
if (rc < 0)
dev_warn(chip->pdev, "transmit returned %d while stopping the TPM",
rc);
}
unsigned long tpm2_calc_ordinal_duration(struct tpm_chip *chip, u32 ordinal)
{
int index = TPM_UNDEFINED;
int duration = 0;
if (ordinal >= TPM2_CC_FIRST && ordinal <= TPM2_CC_LAST)
index = tpm2_ordinal_duration[ordinal - TPM2_CC_FIRST];
if (index != TPM_UNDEFINED)
duration = chip->vendor.duration[index];
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
rc = tpm_transmit_cmd(chip, &cmd, TPM2_SELF_TEST_IN_SIZE,
"continue selftest");
if (rc == TPM2_RC_TESTING) {
dev_warn(chip->pdev, "Got RC_TESTING, ignoring\n");
rc = 0;
}
return rc;
}
int tpm2_do_selftest(struct tpm_chip *chip)
{
int rc;
unsigned int loops;
unsigned int delay_msec = 100;
unsigned long duration;
struct tpm2_cmd cmd;
int i;
duration = tpm2_calc_ordinal_duration(chip, TPM2_CC_SELF_TEST);
loops = jiffies_to_msecs(duration) / delay_msec;
rc = tpm2_start_selftest(chip, true);
if (rc)
return rc;
for (i = 0; i < loops; i++) {
cmd.header.in = tpm2_pcrread_header;
cmd.params.pcrread_in.pcr_selects_cnt = cpu_to_be32(1);
cmd.params.pcrread_in.hash_alg = cpu_to_be16(TPM2_ALG_SHA1);
cmd.params.pcrread_in.pcr_select_size = TPM2_PCR_SELECT_MIN;
cmd.params.pcrread_in.pcr_select[0] = 0x01;
cmd.params.pcrread_in.pcr_select[1] = 0x00;
cmd.params.pcrread_in.pcr_select[2] = 0x00;
rc = tpm_transmit_cmd(chip, (u8 *) &cmd, sizeof(cmd), NULL);
if (rc < 0)
break;
rc = be32_to_cpu(cmd.header.out.return_code);
if (rc != TPM2_RC_TESTING)
break;
msleep(delay_msec);
}
return rc;
}
int tpm2_gen_interrupt(struct tpm_chip *chip)
{
u32 dummy;
return tpm2_get_tpm_pt(chip, 0x100, &dummy,
"attempting to generate an interrupt");
}
int tpm2_probe(struct tpm_chip *chip)
{
struct tpm2_cmd cmd;
int rc;
cmd.header.in = tpm2_get_tpm_pt_header;
cmd.params.get_tpm_pt_in.cap_id = cpu_to_be32(TPM2_CAP_TPM_PROPERTIES);
cmd.params.get_tpm_pt_in.property_id = cpu_to_be32(0x100);
cmd.params.get_tpm_pt_in.property_cnt = cpu_to_be32(1);
rc = tpm_transmit(chip, (const char *) &cmd, sizeof(cmd));
if (rc < 0)
return rc;
else if (rc < TPM_HEADER_SIZE)
return -EFAULT;
if (be16_to_cpu(cmd.header.out.tag) == TPM2_ST_NO_SESSIONS)
chip->flags |= TPM_CHIP_FLAG_TPM2;
return 0;
}
