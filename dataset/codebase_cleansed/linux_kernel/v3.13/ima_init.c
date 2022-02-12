static void __init ima_add_boot_aggregate(void)
{
struct ima_template_entry *entry;
struct integrity_iint_cache tmp_iint, *iint = &tmp_iint;
const char *op = "add_boot_aggregate";
const char *audit_cause = "ENOMEM";
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
result = ima_alloc_init_template(iint, NULL, boot_aggregate_name,
NULL, 0, &entry);
if (result < 0)
return;
result = ima_store_template(entry, violation, NULL,
boot_aggregate_name);
if (result < 0)
ima_free_template_entry(entry);
return;
err_out:
integrity_audit_msg(AUDIT_INTEGRITY_PCR, NULL, boot_aggregate_name, op,
audit_cause, result, 0);
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
pr_info("IMA: No TPM chip found, activating TPM-bypass!\n");
rc = ima_init_crypto();
if (rc)
return rc;
rc = ima_init_template();
if (rc != 0)
return rc;
ima_add_boot_aggregate();
ima_init_policy();
return ima_fs_init();
}
