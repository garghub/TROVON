static int __init hash_setup(char *str)
{
struct ima_template_desc *template_desc = ima_template_desc_current();
int i;
if (hash_setup_done)
return 1;
if (strcmp(template_desc->name, IMA_TEMPLATE_IMA_NAME) == 0) {
if (strncmp(str, "sha1", 4) == 0)
ima_hash_algo = HASH_ALGO_SHA1;
else if (strncmp(str, "md5", 3) == 0)
ima_hash_algo = HASH_ALGO_MD5;
goto out;
}
for (i = 0; i < HASH_ALGO__LAST; i++) {
if (strcmp(str, hash_algo_name[i]) == 0) {
ima_hash_algo = i;
break;
}
}
out:
hash_setup_done = 1;
return 1;
}
static void ima_rdwr_violation_check(struct file *file,
struct integrity_iint_cache *iint,
int must_measure,
char **pathbuf,
const char **pathname)
{
struct inode *inode = file_inode(file);
fmode_t mode = file->f_mode;
bool send_tomtou = false, send_writers = false;
if (mode & FMODE_WRITE) {
if (atomic_read(&inode->i_readcount) && IS_IMA(inode)) {
if (!iint)
iint = integrity_iint_find(inode);
if (iint && (iint->flags & IMA_MEASURE))
send_tomtou = true;
}
} else {
if ((atomic_read(&inode->i_writecount) > 0) && must_measure)
send_writers = true;
}
if (!send_tomtou && !send_writers)
return;
*pathname = ima_d_path(&file->f_path, pathbuf);
if (send_tomtou)
ima_add_violation(file, *pathname, iint,
"invalid_pcr", "ToMToU");
if (send_writers)
ima_add_violation(file, *pathname, iint,
"invalid_pcr", "open_writers");
}
static void ima_check_last_writer(struct integrity_iint_cache *iint,
struct inode *inode, struct file *file)
{
fmode_t mode = file->f_mode;
if (!(mode & FMODE_WRITE))
return;
inode_lock(inode);
if (atomic_read(&inode->i_writecount) == 1) {
if ((iint->version != inode->i_version) ||
(iint->flags & IMA_NEW_FILE)) {
iint->flags &= ~(IMA_DONE_MASK | IMA_NEW_FILE);
iint->measured_pcrs = 0;
if (iint->flags & IMA_APPRAISE)
ima_update_xattr(iint, file);
}
}
inode_unlock(inode);
}
void ima_file_free(struct file *file)
{
struct inode *inode = file_inode(file);
struct integrity_iint_cache *iint;
if (!ima_policy_flag || !S_ISREG(inode->i_mode))
return;
iint = integrity_iint_find(inode);
if (!iint)
return;
ima_check_last_writer(iint, inode, file);
}
static int process_measurement(struct file *file, char *buf, loff_t size,
int mask, enum ima_hooks func, int opened)
{
struct inode *inode = file_inode(file);
struct integrity_iint_cache *iint = NULL;
struct ima_template_desc *template_desc;
char *pathbuf = NULL;
const char *pathname = NULL;
int rc = -ENOMEM, action, must_appraise;
int pcr = CONFIG_IMA_MEASURE_PCR_IDX;
struct evm_ima_xattr_data *xattr_value = NULL;
int xattr_len = 0;
bool violation_check;
enum hash_algo hash_algo;
if (!ima_policy_flag || !S_ISREG(inode->i_mode))
return 0;
action = ima_get_action(inode, mask, func, &pcr);
violation_check = ((func == FILE_CHECK || func == MMAP_CHECK) &&
(ima_policy_flag & IMA_MEASURE));
if (!action && !violation_check)
return 0;
must_appraise = action & IMA_APPRAISE;
if (action & IMA_FILE_APPRAISE)
func = FILE_CHECK;
inode_lock(inode);
if (action) {
iint = integrity_inode_get(inode);
if (!iint)
goto out;
}
if (violation_check) {
ima_rdwr_violation_check(file, iint, action & IMA_MEASURE,
&pathbuf, &pathname);
if (!action) {
rc = 0;
goto out_free;
}
}
iint->flags |= action;
action &= IMA_DO_MASK;
action &= ~((iint->flags & (IMA_DONE_MASK ^ IMA_MEASURED)) >> 1);
if ((action & IMA_MEASURE) && (iint->measured_pcrs & (0x1 << pcr)))
action ^= IMA_MEASURE;
if (!action) {
if (must_appraise)
rc = ima_get_cache_status(iint, func);
goto out_digsig;
}
template_desc = ima_template_desc_current();
if ((action & IMA_APPRAISE_SUBMASK) ||
strcmp(template_desc->name, IMA_TEMPLATE_IMA_NAME) != 0)
xattr_len = ima_read_xattr(file_dentry(file), &xattr_value);
hash_algo = ima_get_hash_algo(xattr_value, xattr_len);
rc = ima_collect_measurement(iint, file, buf, size, hash_algo);
if (rc != 0) {
if (file->f_flags & O_DIRECT)
rc = (iint->flags & IMA_PERMIT_DIRECTIO) ? 0 : -EACCES;
goto out_digsig;
}
if (!pathname)
pathname = ima_d_path(&file->f_path, &pathbuf);
if (action & IMA_MEASURE)
ima_store_measurement(iint, file, pathname,
xattr_value, xattr_len, pcr);
if (action & IMA_APPRAISE_SUBMASK)
rc = ima_appraise_measurement(func, iint, file, pathname,
xattr_value, xattr_len, opened);
if (action & IMA_AUDIT)
ima_audit_measurement(iint, pathname);
out_digsig:
if ((mask & MAY_WRITE) && (iint->flags & IMA_DIGSIG) &&
!(iint->flags & IMA_NEW_FILE))
rc = -EACCES;
kfree(xattr_value);
out_free:
if (pathbuf)
__putname(pathbuf);
out:
inode_unlock(inode);
if ((rc && must_appraise) && (ima_appraise & IMA_APPRAISE_ENFORCE))
return -EACCES;
return 0;
}
int ima_file_mmap(struct file *file, unsigned long prot)
{
if (file && (prot & PROT_EXEC))
return process_measurement(file, NULL, 0, MAY_EXEC,
MMAP_CHECK, 0);
return 0;
}
int ima_bprm_check(struct linux_binprm *bprm)
{
return process_measurement(bprm->file, NULL, 0, MAY_EXEC,
BPRM_CHECK, 0);
}
int ima_file_check(struct file *file, int mask, int opened)
{
return process_measurement(file, NULL, 0,
mask & (MAY_READ | MAY_WRITE | MAY_EXEC),
FILE_CHECK, opened);
}
void ima_post_path_mknod(struct dentry *dentry)
{
struct integrity_iint_cache *iint;
struct inode *inode = dentry->d_inode;
int must_appraise;
must_appraise = ima_must_appraise(inode, MAY_ACCESS, FILE_CHECK);
if (!must_appraise)
return;
iint = integrity_inode_get(inode);
if (iint)
iint->flags |= IMA_NEW_FILE;
}
int ima_read_file(struct file *file, enum kernel_read_file_id read_id)
{
if (!file && read_id == READING_MODULE) {
#ifndef CONFIG_MODULE_SIG_FORCE
if ((ima_appraise & IMA_APPRAISE_MODULES) &&
(ima_appraise & IMA_APPRAISE_ENFORCE))
return -EACCES;
#endif
return 0;
}
return 0;
}
int ima_post_read_file(struct file *file, void *buf, loff_t size,
enum kernel_read_file_id read_id)
{
enum ima_hooks func;
if (!file && read_id == READING_FIRMWARE) {
if ((ima_appraise & IMA_APPRAISE_FIRMWARE) &&
(ima_appraise & IMA_APPRAISE_ENFORCE))
return -EACCES;
return 0;
}
if (!file && read_id == READING_MODULE)
return 0;
if (!file || !buf || size == 0) {
if (ima_appraise & IMA_APPRAISE_ENFORCE)
return -EACCES;
return 0;
}
func = read_idmap[read_id] ?: FILE_CHECK;
return process_measurement(file, buf, size, MAY_READ, func, 0);
}
static int __init init_ima(void)
{
int error;
hash_setup(CONFIG_IMA_DEFAULT_HASH);
error = ima_init();
if (!error) {
ima_initialized = 1;
ima_update_policy_flag();
}
return error;
}
