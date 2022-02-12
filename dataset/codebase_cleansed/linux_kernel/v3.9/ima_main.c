static int __init hash_setup(char *str)
{
if (strncmp(str, "md5", 3) == 0)
ima_hash = "md5";
return 1;
}
static void ima_rdwr_violation_check(struct file *file)
{
struct dentry *dentry = file->f_path.dentry;
struct inode *inode = dentry->d_inode;
fmode_t mode = file->f_mode;
int must_measure;
bool send_tomtou = false, send_writers = false;
char *pathbuf = NULL;
const char *pathname;
if (!S_ISREG(inode->i_mode) || !ima_initialized)
return;
mutex_lock(&inode->i_mutex);
if (mode & FMODE_WRITE) {
if (atomic_read(&inode->i_readcount) && IS_IMA(inode))
send_tomtou = true;
goto out;
}
must_measure = ima_must_measure(inode, MAY_READ, FILE_CHECK);
if (!must_measure)
goto out;
if (atomic_read(&inode->i_writecount) > 0)
send_writers = true;
out:
mutex_unlock(&inode->i_mutex);
if (!send_tomtou && !send_writers)
return;
pathname = ima_d_path(&file->f_path, &pathbuf);
if (!pathname || strlen(pathname) > IMA_EVENT_NAME_LEN_MAX)
pathname = dentry->d_name.name;
if (send_tomtou)
ima_add_violation(inode, pathname,
"invalid_pcr", "ToMToU");
if (send_writers)
ima_add_violation(inode, pathname,
"invalid_pcr", "open_writers");
kfree(pathbuf);
}
static void ima_check_last_writer(struct integrity_iint_cache *iint,
struct inode *inode, struct file *file)
{
fmode_t mode = file->f_mode;
if (!(mode & FMODE_WRITE))
return;
mutex_lock(&inode->i_mutex);
if (atomic_read(&inode->i_writecount) == 1 &&
iint->version != inode->i_version) {
iint->flags &= ~IMA_DONE_MASK;
if (iint->flags & IMA_APPRAISE)
ima_update_xattr(iint, file);
}
mutex_unlock(&inode->i_mutex);
}
void ima_file_free(struct file *file)
{
struct inode *inode = file_inode(file);
struct integrity_iint_cache *iint;
if (!iint_initialized || !S_ISREG(inode->i_mode))
return;
iint = integrity_iint_find(inode);
if (!iint)
return;
ima_check_last_writer(iint, inode, file);
}
static int process_measurement(struct file *file, const char *filename,
int mask, int function)
{
struct inode *inode = file_inode(file);
struct integrity_iint_cache *iint;
char *pathbuf = NULL;
const char *pathname = NULL;
int rc = -ENOMEM, action, must_appraise, _func;
if (!ima_initialized || !S_ISREG(inode->i_mode))
return 0;
action = ima_get_action(inode, mask, function);
if (!action)
return 0;
must_appraise = action & IMA_APPRAISE;
_func = (action & IMA_FILE_APPRAISE) ? FILE_CHECK : function;
mutex_lock(&inode->i_mutex);
iint = integrity_inode_get(inode);
if (!iint)
goto out;
iint->flags |= action;
action &= IMA_DO_MASK;
action &= ~((iint->flags & IMA_DONE_MASK) >> 1);
if (!action) {
if (must_appraise)
rc = ima_get_cache_status(iint, _func);
goto out_digsig;
}
rc = ima_collect_measurement(iint, file);
if (rc != 0)
goto out_digsig;
if (function != BPRM_CHECK)
pathname = ima_d_path(&file->f_path, &pathbuf);
if (!pathname)
pathname = filename;
if (action & IMA_MEASURE)
ima_store_measurement(iint, file, pathname);
if (action & IMA_APPRAISE_SUBMASK)
rc = ima_appraise_measurement(_func, iint, file, pathname);
if (action & IMA_AUDIT)
ima_audit_measurement(iint, pathname);
kfree(pathbuf);
out_digsig:
if ((mask & MAY_WRITE) && (iint->flags & IMA_DIGSIG))
rc = -EACCES;
out:
mutex_unlock(&inode->i_mutex);
if ((rc && must_appraise) && (ima_appraise & IMA_APPRAISE_ENFORCE))
return -EACCES;
return 0;
}
int ima_file_mmap(struct file *file, unsigned long prot)
{
if (file && (prot & PROT_EXEC))
return process_measurement(file, file->f_dentry->d_name.name,
MAY_EXEC, MMAP_CHECK);
return 0;
}
int ima_bprm_check(struct linux_binprm *bprm)
{
return process_measurement(bprm->file,
(strcmp(bprm->filename, bprm->interp) == 0) ?
bprm->filename : bprm->interp,
MAY_EXEC, BPRM_CHECK);
}
int ima_file_check(struct file *file, int mask)
{
ima_rdwr_violation_check(file);
return process_measurement(file, file->f_dentry->d_name.name,
mask & (MAY_READ | MAY_WRITE | MAY_EXEC),
FILE_CHECK);
}
int ima_module_check(struct file *file)
{
if (!file) {
#ifndef CONFIG_MODULE_SIG_FORCE
if ((ima_appraise & IMA_APPRAISE_MODULES) &&
(ima_appraise & IMA_APPRAISE_ENFORCE))
return -EACCES;
#endif
return 0;
}
return process_measurement(file, file->f_dentry->d_name.name,
MAY_EXEC, MODULE_CHECK);
}
static int __init init_ima(void)
{
int error;
error = ima_init();
if (!error)
ima_initialized = 1;
return error;
}
