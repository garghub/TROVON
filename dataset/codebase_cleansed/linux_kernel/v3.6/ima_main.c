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
int rc;
bool send_tomtou = false, send_writers = false;
unsigned char *pathname = NULL, *pathbuf = NULL;
if (!S_ISREG(inode->i_mode) || !ima_initialized)
return;
mutex_lock(&inode->i_mutex);
if (mode & FMODE_WRITE) {
if (atomic_read(&inode->i_readcount) && IS_IMA(inode))
send_tomtou = true;
goto out;
}
rc = ima_must_measure(inode, MAY_READ, FILE_CHECK);
if (rc < 0)
goto out;
if (atomic_read(&inode->i_writecount) > 0)
send_writers = true;
out:
mutex_unlock(&inode->i_mutex);
if (!send_tomtou && !send_writers)
return;
pathbuf = kmalloc(PATH_MAX + 11, GFP_KERNEL);
if (pathbuf) {
pathname = d_path(&file->f_path, pathbuf, PATH_MAX + 11);
if (IS_ERR(pathname))
pathname = NULL;
else if (strlen(pathname) > IMA_EVENT_NAME_LEN_MAX)
pathname = NULL;
}
if (send_tomtou)
ima_add_violation(inode,
!pathname ? dentry->d_name.name : pathname,
"invalid_pcr", "ToMToU");
if (send_writers)
ima_add_violation(inode,
!pathname ? dentry->d_name.name : pathname,
"invalid_pcr", "open_writers");
kfree(pathbuf);
}
static void ima_check_last_writer(struct integrity_iint_cache *iint,
struct inode *inode,
struct file *file)
{
fmode_t mode = file->f_mode;
mutex_lock(&iint->mutex);
if (mode & FMODE_WRITE &&
atomic_read(&inode->i_writecount) == 1 &&
iint->version != inode->i_version)
iint->flags &= ~IMA_MEASURED;
mutex_unlock(&iint->mutex);
}
void ima_file_free(struct file *file)
{
struct inode *inode = file->f_dentry->d_inode;
struct integrity_iint_cache *iint;
if (!iint_initialized || !S_ISREG(inode->i_mode))
return;
iint = integrity_iint_find(inode);
if (!iint)
return;
ima_check_last_writer(iint, inode, file);
}
static int process_measurement(struct file *file, const unsigned char *filename,
int mask, int function)
{
struct inode *inode = file->f_dentry->d_inode;
struct integrity_iint_cache *iint;
unsigned char *pathname = NULL, *pathbuf = NULL;
int rc = 0;
if (!ima_initialized || !S_ISREG(inode->i_mode))
return 0;
rc = ima_must_measure(inode, mask, function);
if (rc != 0)
return rc;
retry:
iint = integrity_iint_find(inode);
if (!iint) {
rc = integrity_inode_alloc(inode);
if (!rc || rc == -EEXIST)
goto retry;
return rc;
}
mutex_lock(&iint->mutex);
rc = iint->flags & IMA_MEASURED ? 1 : 0;
if (rc != 0)
goto out;
rc = ima_collect_measurement(iint, file);
if (rc != 0)
goto out;
if (function != BPRM_CHECK) {
pathbuf = kmalloc(PATH_MAX + 11, GFP_KERNEL);
if (pathbuf) {
pathname =
d_path(&file->f_path, pathbuf, PATH_MAX + 11);
if (IS_ERR(pathname))
pathname = NULL;
}
}
ima_store_measurement(iint, file, !pathname ? filename : pathname);
kfree(pathbuf);
out:
mutex_unlock(&iint->mutex);
return rc;
}
int ima_file_mmap(struct file *file, unsigned long prot)
{
int rc;
if (!file)
return 0;
if (prot & PROT_EXEC)
rc = process_measurement(file, file->f_dentry->d_name.name,
MAY_EXEC, FILE_MMAP);
return 0;
}
int ima_bprm_check(struct linux_binprm *bprm)
{
int rc;
rc = process_measurement(bprm->file,
(strcmp(bprm->filename, bprm->interp) == 0) ?
bprm->filename : bprm->interp,
MAY_EXEC, BPRM_CHECK);
return 0;
}
int ima_file_check(struct file *file, int mask)
{
int rc;
ima_rdwr_violation_check(file);
rc = process_measurement(file, file->f_dentry->d_name.name,
mask & (MAY_READ | MAY_WRITE | MAY_EXEC),
FILE_CHECK);
return 0;
}
static int __init init_ima(void)
{
int error;
error = ima_init();
if (!error)
ima_initialized = 1;
return error;
}
