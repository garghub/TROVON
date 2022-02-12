void ima_free_template_entry(struct ima_template_entry *entry)
{
int i;
for (i = 0; i < entry->template_desc->num_fields; i++)
kfree(entry->template_data[i].data);
kfree(entry);
}
int ima_alloc_init_template(struct ima_event_data *event_data,
struct ima_template_entry **entry)
{
struct ima_template_desc *template_desc = ima_template_desc_current();
int i, result = 0;
*entry = kzalloc(sizeof(**entry) + template_desc->num_fields *
sizeof(struct ima_field_data), GFP_NOFS);
if (!*entry)
return -ENOMEM;
(*entry)->template_desc = template_desc;
for (i = 0; i < template_desc->num_fields; i++) {
struct ima_template_field *field = template_desc->fields[i];
u32 len;
result = field->field_init(event_data,
&((*entry)->template_data[i]));
if (result != 0)
goto out;
len = (*entry)->template_data[i].len;
(*entry)->template_data_len += sizeof(len);
(*entry)->template_data_len += len;
}
return 0;
out:
ima_free_template_entry(*entry);
*entry = NULL;
return result;
}
int ima_store_template(struct ima_template_entry *entry,
int violation, struct inode *inode,
const unsigned char *filename, int pcr)
{
static const char op[] = "add_template_measure";
static const char audit_cause[] = "hashing_error";
char *template_name = entry->template_desc->name;
int result;
struct {
struct ima_digest_data hdr;
char digest[TPM_DIGEST_SIZE];
} hash;
if (!violation) {
int num_fields = entry->template_desc->num_fields;
hash.hdr.algo = HASH_ALGO_SHA1;
result = ima_calc_field_array_hash(&entry->template_data[0],
entry->template_desc,
num_fields, &hash.hdr);
if (result < 0) {
integrity_audit_msg(AUDIT_INTEGRITY_PCR, inode,
template_name, op,
audit_cause, result, 0);
return result;
}
memcpy(entry->digest, hash.hdr.digest, hash.hdr.length);
}
entry->pcr = pcr;
result = ima_add_template_entry(entry, violation, op, inode, filename);
return result;
}
void ima_add_violation(struct file *file, const unsigned char *filename,
struct integrity_iint_cache *iint,
const char *op, const char *cause)
{
struct ima_template_entry *entry;
struct inode *inode = file_inode(file);
struct ima_event_data event_data = {iint, file, filename, NULL, 0,
cause};
int violation = 1;
int result;
atomic_long_inc(&ima_htable.violations);
result = ima_alloc_init_template(&event_data, &entry);
if (result < 0) {
result = -ENOMEM;
goto err_out;
}
result = ima_store_template(entry, violation, inode,
filename, CONFIG_IMA_MEASURE_PCR_IDX);
if (result < 0)
ima_free_template_entry(entry);
err_out:
integrity_audit_msg(AUDIT_INTEGRITY_PCR, inode, filename,
op, cause, result, 0);
}
int ima_get_action(struct inode *inode, int mask, enum ima_hooks func, int *pcr)
{
int flags = IMA_MEASURE | IMA_AUDIT | IMA_APPRAISE;
flags &= ima_policy_flag;
return ima_match_policy(inode, func, mask, flags, pcr);
}
int ima_collect_measurement(struct integrity_iint_cache *iint,
struct file *file, void *buf, loff_t size,
enum hash_algo algo)
{
const char *audit_cause = "failed";
struct inode *inode = file_inode(file);
const char *filename = file->f_path.dentry->d_name.name;
int result = 0;
struct {
struct ima_digest_data hdr;
char digest[IMA_MAX_DIGEST_SIZE];
} hash;
if (!(iint->flags & IMA_COLLECTED)) {
u64 i_version = file_inode(file)->i_version;
if (file->f_flags & O_DIRECT) {
audit_cause = "failed(directio)";
result = -EACCES;
goto out;
}
hash.hdr.algo = algo;
result = (!buf) ? ima_calc_file_hash(file, &hash.hdr) :
ima_calc_buffer_hash(buf, size, &hash.hdr);
if (!result) {
int length = sizeof(hash.hdr) + hash.hdr.length;
void *tmpbuf = krealloc(iint->ima_hash, length,
GFP_NOFS);
if (tmpbuf) {
iint->ima_hash = tmpbuf;
memcpy(iint->ima_hash, &hash, length);
iint->version = i_version;
iint->flags |= IMA_COLLECTED;
} else
result = -ENOMEM;
}
}
out:
if (result)
integrity_audit_msg(AUDIT_INTEGRITY_DATA, inode,
filename, "collect_data", audit_cause,
result, 0);
return result;
}
void ima_store_measurement(struct integrity_iint_cache *iint,
struct file *file, const unsigned char *filename,
struct evm_ima_xattr_data *xattr_value,
int xattr_len, int pcr)
{
static const char op[] = "add_template_measure";
static const char audit_cause[] = "ENOMEM";
int result = -ENOMEM;
struct inode *inode = file_inode(file);
struct ima_template_entry *entry;
struct ima_event_data event_data = {iint, file, filename, xattr_value,
xattr_len, NULL};
int violation = 0;
if (iint->measured_pcrs & (0x1 << pcr))
return;
result = ima_alloc_init_template(&event_data, &entry);
if (result < 0) {
integrity_audit_msg(AUDIT_INTEGRITY_PCR, inode, filename,
op, audit_cause, result, 0);
return;
}
result = ima_store_template(entry, violation, inode, filename, pcr);
if (!result || result == -EEXIST) {
iint->flags |= IMA_MEASURED;
iint->measured_pcrs |= (0x1 << pcr);
}
if (result < 0)
ima_free_template_entry(entry);
}
void ima_audit_measurement(struct integrity_iint_cache *iint,
const unsigned char *filename)
{
struct audit_buffer *ab;
char hash[(iint->ima_hash->length * 2) + 1];
const char *algo_name = hash_algo_name[iint->ima_hash->algo];
char algo_hash[sizeof(hash) + strlen(algo_name) + 2];
int i;
if (iint->flags & IMA_AUDITED)
return;
for (i = 0; i < iint->ima_hash->length; i++)
hex_byte_pack(hash + (i * 2), iint->ima_hash->digest[i]);
hash[i * 2] = '\0';
ab = audit_log_start(current->audit_context, GFP_KERNEL,
AUDIT_INTEGRITY_RULE);
if (!ab)
return;
audit_log_format(ab, "file=");
audit_log_untrustedstring(ab, filename);
audit_log_format(ab, " hash=");
snprintf(algo_hash, sizeof(algo_hash), "%s:%s", algo_name, hash);
audit_log_untrustedstring(ab, algo_hash);
audit_log_task_info(ab, current);
audit_log_end(ab);
iint->flags |= IMA_AUDITED;
}
const char *ima_d_path(const struct path *path, char **pathbuf, char *namebuf)
{
char *pathname = NULL;
*pathbuf = __getname();
if (*pathbuf) {
pathname = d_absolute_path(path, *pathbuf, PATH_MAX);
if (IS_ERR(pathname)) {
__putname(*pathbuf);
*pathbuf = NULL;
pathname = NULL;
}
}
if (!pathname) {
strlcpy(namebuf, path->dentry->d_name.name, NAME_MAX);
pathname = namebuf;
}
return pathname;
}
