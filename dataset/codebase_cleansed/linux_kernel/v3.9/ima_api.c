int ima_store_template(struct ima_template_entry *entry,
int violation, struct inode *inode)
{
const char *op = "add_template_measure";
const char *audit_cause = "hashing_error";
int result;
memset(entry->digest, 0, sizeof(entry->digest));
entry->template_name = IMA_TEMPLATE_NAME;
entry->template_len = sizeof(entry->template);
if (!violation) {
result = ima_calc_buffer_hash(&entry->template,
entry->template_len,
entry->digest);
if (result < 0) {
integrity_audit_msg(AUDIT_INTEGRITY_PCR, inode,
entry->template_name, op,
audit_cause, result, 0);
return result;
}
}
result = ima_add_template_entry(entry, violation, op, inode);
return result;
}
void ima_add_violation(struct inode *inode, const unsigned char *filename,
const char *op, const char *cause)
{
struct ima_template_entry *entry;
int violation = 1;
int result;
atomic_long_inc(&ima_htable.violations);
entry = kmalloc(sizeof(*entry), GFP_KERNEL);
if (!entry) {
result = -ENOMEM;
goto err_out;
}
memset(&entry->template, 0, sizeof(entry->template));
strncpy(entry->template.file_name, filename, IMA_EVENT_NAME_LEN_MAX);
result = ima_store_template(entry, violation, inode);
if (result < 0)
kfree(entry);
err_out:
integrity_audit_msg(AUDIT_INTEGRITY_PCR, inode, filename,
op, cause, result, 0);
}
int ima_get_action(struct inode *inode, int mask, int function)
{
int flags = IMA_MEASURE | IMA_AUDIT | IMA_APPRAISE;
if (!ima_appraise)
flags &= ~IMA_APPRAISE;
return ima_match_policy(inode, function, mask, flags);
}
int ima_must_measure(struct inode *inode, int mask, int function)
{
return ima_match_policy(inode, function, mask, IMA_MEASURE);
}
int ima_collect_measurement(struct integrity_iint_cache *iint,
struct file *file)
{
struct inode *inode = file_inode(file);
const char *filename = file->f_dentry->d_name.name;
int result = 0;
if (!(iint->flags & IMA_COLLECTED)) {
u64 i_version = file_inode(file)->i_version;
iint->ima_xattr.type = IMA_XATTR_DIGEST;
result = ima_calc_file_hash(file, iint->ima_xattr.digest);
if (!result) {
iint->version = i_version;
iint->flags |= IMA_COLLECTED;
}
}
if (result)
integrity_audit_msg(AUDIT_INTEGRITY_DATA, inode,
filename, "collect_data", "failed",
result, 0);
return result;
}
void ima_store_measurement(struct integrity_iint_cache *iint,
struct file *file, const unsigned char *filename)
{
const char *op = "add_template_measure";
const char *audit_cause = "ENOMEM";
int result = -ENOMEM;
struct inode *inode = file_inode(file);
struct ima_template_entry *entry;
int violation = 0;
if (iint->flags & IMA_MEASURED)
return;
entry = kmalloc(sizeof(*entry), GFP_KERNEL);
if (!entry) {
integrity_audit_msg(AUDIT_INTEGRITY_PCR, inode, filename,
op, audit_cause, result, 0);
return;
}
memset(&entry->template, 0, sizeof(entry->template));
memcpy(entry->template.digest, iint->ima_xattr.digest, IMA_DIGEST_SIZE);
strcpy(entry->template.file_name,
(strlen(filename) > IMA_EVENT_NAME_LEN_MAX) ?
file->f_dentry->d_name.name : filename);
result = ima_store_template(entry, violation, inode);
if (!result || result == -EEXIST)
iint->flags |= IMA_MEASURED;
if (result < 0)
kfree(entry);
}
void ima_audit_measurement(struct integrity_iint_cache *iint,
const unsigned char *filename)
{
struct audit_buffer *ab;
char hash[(IMA_DIGEST_SIZE * 2) + 1];
int i;
if (iint->flags & IMA_AUDITED)
return;
for (i = 0; i < IMA_DIGEST_SIZE; i++)
hex_byte_pack(hash + (i * 2), iint->ima_xattr.digest[i]);
hash[i * 2] = '\0';
ab = audit_log_start(current->audit_context, GFP_KERNEL,
AUDIT_INTEGRITY_RULE);
if (!ab)
return;
audit_log_format(ab, "file=");
audit_log_untrustedstring(ab, filename);
audit_log_format(ab, " hash=");
audit_log_untrustedstring(ab, hash);
audit_log_task_info(ab, current);
audit_log_end(ab);
iint->flags |= IMA_AUDITED;
}
const char *ima_d_path(struct path *path, char **pathbuf)
{
char *pathname = NULL;
*pathbuf = kmalloc(PATH_MAX + 11, GFP_KERNEL);
if (*pathbuf) {
pathname = d_path(path, *pathbuf, PATH_MAX + 11);
if (IS_ERR(pathname)) {
kfree(*pathbuf);
*pathbuf = NULL;
pathname = NULL;
}
}
return pathname;
}
