static struct ima_queue_entry *ima_lookup_digest_entry(u8 *digest_value,
int pcr)
{
struct ima_queue_entry *qe, *ret = NULL;
unsigned int key;
int rc;
key = ima_hash_key(digest_value);
rcu_read_lock();
hlist_for_each_entry_rcu(qe, &ima_htable.queue[key], hnext) {
rc = memcmp(qe->entry->digest, digest_value, TPM_DIGEST_SIZE);
if ((rc == 0) && (qe->entry->pcr == pcr)) {
ret = qe;
break;
}
}
rcu_read_unlock();
return ret;
}
static int get_binary_runtime_size(struct ima_template_entry *entry)
{
int size = 0;
size += sizeof(u32);
size += sizeof(entry->digest);
size += sizeof(int);
size += strlen(entry->template_desc->name) + 1;
size += sizeof(entry->template_data_len);
size += entry->template_data_len;
return size;
}
static int ima_add_digest_entry(struct ima_template_entry *entry,
bool update_htable)
{
struct ima_queue_entry *qe;
unsigned int key;
qe = kmalloc(sizeof(*qe), GFP_KERNEL);
if (qe == NULL) {
pr_err("OUT OF MEMORY ERROR creating queue entry\n");
return -ENOMEM;
}
qe->entry = entry;
INIT_LIST_HEAD(&qe->later);
list_add_tail_rcu(&qe->later, &ima_measurements);
atomic_long_inc(&ima_htable.len);
if (update_htable) {
key = ima_hash_key(entry->digest);
hlist_add_head_rcu(&qe->hnext, &ima_htable.queue[key]);
}
if (binary_runtime_size != ULONG_MAX) {
int size;
size = get_binary_runtime_size(entry);
binary_runtime_size = (binary_runtime_size < ULONG_MAX - size) ?
binary_runtime_size + size : ULONG_MAX;
}
return 0;
}
unsigned long ima_get_binary_runtime_size(void)
{
if (binary_runtime_size >= (ULONG_MAX - sizeof(struct ima_kexec_hdr)))
return ULONG_MAX;
else
return binary_runtime_size + sizeof(struct ima_kexec_hdr);
}
static int ima_pcr_extend(const u8 *hash, int pcr)
{
int result = 0;
if (!ima_used_chip)
return result;
result = tpm_pcr_extend(TPM_ANY_NUM, pcr, hash);
if (result != 0)
pr_err("Error Communicating to TPM chip, result: %d\n", result);
return result;
}
int ima_add_template_entry(struct ima_template_entry *entry, int violation,
const char *op, struct inode *inode,
const unsigned char *filename)
{
u8 digest[TPM_DIGEST_SIZE];
const char *audit_cause = "hash_added";
char tpm_audit_cause[AUDIT_CAUSE_LEN_MAX];
int audit_info = 1;
int result = 0, tpmresult = 0;
mutex_lock(&ima_extend_list_mutex);
if (!violation) {
memcpy(digest, entry->digest, sizeof(digest));
if (ima_lookup_digest_entry(digest, entry->pcr)) {
audit_cause = "hash_exists";
result = -EEXIST;
goto out;
}
}
result = ima_add_digest_entry(entry, 1);
if (result < 0) {
audit_cause = "ENOMEM";
audit_info = 0;
goto out;
}
if (violation)
memset(digest, 0xff, sizeof(digest));
tpmresult = ima_pcr_extend(digest, entry->pcr);
if (tpmresult != 0) {
snprintf(tpm_audit_cause, AUDIT_CAUSE_LEN_MAX, "TPM_error(%d)",
tpmresult);
audit_cause = tpm_audit_cause;
audit_info = 0;
}
out:
mutex_unlock(&ima_extend_list_mutex);
integrity_audit_msg(AUDIT_INTEGRITY_PCR, inode, filename,
op, audit_cause, result, audit_info);
return result;
}
int ima_restore_measurement_entry(struct ima_template_entry *entry)
{
int result = 0;
mutex_lock(&ima_extend_list_mutex);
result = ima_add_digest_entry(entry, 0);
mutex_unlock(&ima_extend_list_mutex);
return result;
}
