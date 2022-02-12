static int __init ima_add_boot_aggregate(void)
{
static const char op[] = "add_boot_aggregate";
const char *audit_cause = "ENOMEM";
struct ima_template_entry *entry;
struct integrity_iint_cache tmp_iint, *iint = &tmp_iint;
struct ima_event_data event_data = {iint, NULL, boot_aggregate_name,
NULL, 0, NULL};
int result = -ENOMEM;
int violation = 0;
struct {
struct ima_digest_data hdr;
char digest[TPM_DIGEST_SIZE];
} hash;
memset(iint, 0, sizeof(*iint));
memset(&hash, 0, sizeof(hash));
iint->ima_hash = &hash.hdr;
iint->ima_hash->algo = HASH_ALGO_SHA1;
iint->ima_hash->length = SHA1_DIGEST_SIZE;
if (ima_used_chip) {
result = ima_calc_boot_aggregate(&hash.hdr);
if (result < 0) {
audit_cause = "hashing_error";
goto err_out;
}
}
result = ima_alloc_init_template(&event_data, &entry);
if (result < 0) {
audit_cause = "alloc_entry";
goto err_out;
}
result = ima_store_template(entry, violation, NULL,
boot_aggregate_name,
CONFIG_IMA_MEASURE_PCR_IDX);
if (result < 0) {
ima_free_template_entry(entry);
audit_cause = "store_entry";
goto err_out;
}
return 0;
err_out:
integrity_audit_msg(AUDIT_INTEGRITY_PCR, NULL, boot_aggregate_name, op,
audit_cause, result, 0);
return result;
}
void __init ima_load_x509(void)
{
int unset_flags = ima_policy_flag & IMA_APPRAISE;
ima_policy_flag &= ~unset_flags;
integrity_load_x509(INTEGRITY_KEYRING_IMA, CONFIG_IMA_X509_PATH);
ima_policy_flag |= unset_flags;
}
int __init ima_init(void)
{
u8 pcr_i[TPM_DIGEST_SIZE];
int rc;
ima_used_chip = 0;
rc = tpm_pcr_read(TPM_ANY_NUM, 0, pcr_i);
if (rc == 0)
ima_used_chip = 1;
if (!ima_used_chip)
pr_info("No TPM chip found, activating TPM-bypass! (rc=%d)\n",
rc);
rc = integrity_init_keyring(INTEGRITY_KEYRING_IMA);
if (rc)
return rc;
rc = ima_init_crypto();
if (rc)
return rc;
rc = ima_init_template();
if (rc != 0)
return rc;
ima_load_kexec_buffer();
rc = ima_add_boot_aggregate();
if (rc != 0)
return rc;
ima_init_policy();
return ima_fs_init();
}
