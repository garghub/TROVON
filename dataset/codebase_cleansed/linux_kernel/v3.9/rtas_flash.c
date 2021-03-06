static int flash_list_valid(struct flash_block_list *flist)
{
struct flash_block_list *f;
int i;
unsigned long block_size, image_size;
image_size = 0;
for (f = flist; f; f = f->next) {
for (i = 0; i < f->num_blocks; i++) {
if (f->blocks[i].data == NULL) {
return FLASH_IMG_NULL_DATA;
}
block_size = f->blocks[i].length;
if (block_size <= 0 || block_size > RTAS_BLK_SIZE) {
return FLASH_IMG_BAD_LEN;
}
image_size += block_size;
}
}
if (image_size < (256 << 10)) {
if (image_size < 2)
return FLASH_NO_OP;
}
printk(KERN_INFO "FLASH: flash image with %ld bytes stored for hardware flash on reboot\n", image_size);
return FLASH_IMG_READY;
}
static void free_flash_list(struct flash_block_list *f)
{
struct flash_block_list *next;
int i;
while (f) {
for (i = 0; i < f->num_blocks; i++)
kmem_cache_free(flash_block_cache, f->blocks[i].data);
next = f->next;
kmem_cache_free(flash_block_cache, f);
f = next;
}
}
static int rtas_flash_release(struct inode *inode, struct file *file)
{
struct proc_dir_entry *dp = PDE(file_inode(file));
struct rtas_update_flash_t *uf;
uf = (struct rtas_update_flash_t *) dp->data;
if (uf->flist) {
if (rtas_firmware_flash_list) {
free_flash_list(rtas_firmware_flash_list);
rtas_firmware_flash_list = NULL;
}
if (uf->status != FLASH_AUTH)
uf->status = flash_list_valid(uf->flist);
if (uf->status == FLASH_IMG_READY)
rtas_firmware_flash_list = uf->flist;
else
free_flash_list(uf->flist);
uf->flist = NULL;
}
atomic_dec(&dp->count);
return 0;
}
static void get_flash_status_msg(int status, char *buf)
{
char *msg;
switch (status) {
case FLASH_AUTH:
msg = "error: this partition does not have service authority\n";
break;
case FLASH_NO_OP:
msg = "info: no firmware image for flash\n";
break;
case FLASH_IMG_SHORT:
msg = "error: flash image short\n";
break;
case FLASH_IMG_BAD_LEN:
msg = "error: internal error bad length\n";
break;
case FLASH_IMG_NULL_DATA:
msg = "error: internal error null data\n";
break;
case FLASH_IMG_READY:
msg = "ready: firmware image ready for flash on reboot\n";
break;
default:
sprintf(buf, "error: unexpected status value %d\n", status);
return;
}
strcpy(buf, msg);
}
static ssize_t rtas_flash_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct proc_dir_entry *dp = PDE(file_inode(file));
struct rtas_update_flash_t *uf;
char msg[RTAS_MSG_MAXLEN];
uf = dp->data;
if (!strcmp(dp->name, FIRMWARE_FLASH_NAME)) {
get_flash_status_msg(uf->status, msg);
} else {
sprintf(msg, "%d\n", uf->status);
}
return simple_read_from_buffer(buf, count, ppos, msg, strlen(msg));
}
void rtas_block_ctor(void *ptr)
{
memset(ptr, 0, RTAS_BLK_SIZE);
}
static ssize_t rtas_flash_write(struct file *file, const char __user *buffer,
size_t count, loff_t *off)
{
struct proc_dir_entry *dp = PDE(file_inode(file));
struct rtas_update_flash_t *uf;
char *p;
int next_free;
struct flash_block_list *fl;
uf = (struct rtas_update_flash_t *) dp->data;
if (uf->status == FLASH_AUTH || count == 0)
return count;
if (uf->flist == NULL) {
uf->flist = kmem_cache_alloc(flash_block_cache, GFP_KERNEL);
if (!uf->flist)
return -ENOMEM;
}
fl = uf->flist;
while (fl->next)
fl = fl->next;
next_free = fl->num_blocks;
if (next_free == FLASH_BLOCKS_PER_NODE) {
fl->next = kmem_cache_alloc(flash_block_cache, GFP_KERNEL);
if (!fl->next)
return -ENOMEM;
fl = fl->next;
next_free = 0;
}
if (count > RTAS_BLK_SIZE)
count = RTAS_BLK_SIZE;
p = kmem_cache_alloc(flash_block_cache, GFP_KERNEL);
if (!p)
return -ENOMEM;
if(copy_from_user(p, buffer, count)) {
kmem_cache_free(flash_block_cache, p);
return -EFAULT;
}
fl->blocks[next_free].data = p;
fl->blocks[next_free].length = count;
fl->num_blocks++;
return count;
}
static int rtas_excl_open(struct inode *inode, struct file *file)
{
struct proc_dir_entry *dp = PDE(inode);
spin_lock(&flash_file_open_lock);
if (atomic_read(&dp->count) > 2) {
spin_unlock(&flash_file_open_lock);
return -EBUSY;
}
atomic_inc(&dp->count);
spin_unlock(&flash_file_open_lock);
return 0;
}
static int rtas_excl_release(struct inode *inode, struct file *file)
{
struct proc_dir_entry *dp = PDE(inode);
atomic_dec(&dp->count);
return 0;
}
static void manage_flash(struct rtas_manage_flash_t *args_buf)
{
s32 rc;
do {
rc = rtas_call(rtas_token("ibm,manage-flash-image"), 1,
1, NULL, args_buf->op);
} while (rtas_busy_delay(rc));
args_buf->status = rc;
}
static ssize_t manage_flash_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct proc_dir_entry *dp = PDE(file_inode(file));
struct rtas_manage_flash_t *args_buf;
char msg[RTAS_MSG_MAXLEN];
int msglen;
args_buf = dp->data;
if (args_buf == NULL)
return 0;
msglen = sprintf(msg, "%d\n", args_buf->status);
return simple_read_from_buffer(buf, count, ppos, msg, msglen);
}
static ssize_t manage_flash_write(struct file *file, const char __user *buf,
size_t count, loff_t *off)
{
struct proc_dir_entry *dp = PDE(file_inode(file));
struct rtas_manage_flash_t *args_buf;
const char reject_str[] = "0";
const char commit_str[] = "1";
char stkbuf[10];
int op;
args_buf = (struct rtas_manage_flash_t *) dp->data;
if ((args_buf->status == MANAGE_AUTH) || (count == 0))
return count;
op = -1;
if (buf) {
if (count > 9) count = 9;
if (copy_from_user (stkbuf, buf, count)) {
return -EFAULT;
}
if (strncmp(stkbuf, reject_str, strlen(reject_str)) == 0)
op = RTAS_REJECT_TMP_IMG;
else if (strncmp(stkbuf, commit_str, strlen(commit_str)) == 0)
op = RTAS_COMMIT_TMP_IMG;
}
if (op == -1)
return -EINVAL;
args_buf->op = op;
manage_flash(args_buf);
return count;
}
static void validate_flash(struct rtas_validate_flash_t *args_buf)
{
int token = rtas_token("ibm,validate-flash-image");
int update_results;
s32 rc;
rc = 0;
do {
spin_lock(&rtas_data_buf_lock);
memcpy(rtas_data_buf, args_buf->buf, VALIDATE_BUF_SIZE);
rc = rtas_call(token, 2, 2, &update_results,
(u32) __pa(rtas_data_buf), args_buf->buf_size);
memcpy(args_buf->buf, rtas_data_buf, VALIDATE_BUF_SIZE);
spin_unlock(&rtas_data_buf_lock);
} while (rtas_busy_delay(rc));
args_buf->status = rc;
args_buf->update_results = update_results;
}
static int get_validate_flash_msg(struct rtas_validate_flash_t *args_buf,
char *msg)
{
int n;
if (args_buf->status >= VALIDATE_TMP_UPDATE) {
n = sprintf(msg, "%d\n", args_buf->update_results);
if ((args_buf->update_results >= VALIDATE_CUR_UNKNOWN) ||
(args_buf->update_results == VALIDATE_TMP_UPDATE))
n += sprintf(msg + n, "%s\n", args_buf->buf);
} else {
n = sprintf(msg, "%d\n", args_buf->status);
}
return n;
}
static ssize_t validate_flash_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct proc_dir_entry *dp = PDE(file_inode(file));
struct rtas_validate_flash_t *args_buf;
char msg[RTAS_MSG_MAXLEN];
int msglen;
args_buf = dp->data;
msglen = get_validate_flash_msg(args_buf, msg);
return simple_read_from_buffer(buf, count, ppos, msg, msglen);
}
static ssize_t validate_flash_write(struct file *file, const char __user *buf,
size_t count, loff_t *off)
{
struct proc_dir_entry *dp = PDE(file_inode(file));
struct rtas_validate_flash_t *args_buf;
int rc;
args_buf = (struct rtas_validate_flash_t *) dp->data;
if (dp->data == NULL) {
dp->data = kmalloc(sizeof(struct rtas_validate_flash_t),
GFP_KERNEL);
if (dp->data == NULL)
return -ENOMEM;
}
if ((*off >= VALIDATE_BUF_SIZE) ||
(args_buf->status == VALIDATE_AUTH)) {
*off += count;
return count;
}
if (*off + count >= VALIDATE_BUF_SIZE) {
count = VALIDATE_BUF_SIZE - *off;
args_buf->status = VALIDATE_READY;
} else {
args_buf->status = VALIDATE_INCOMPLETE;
}
if (!access_ok(VERIFY_READ, buf, count)) {
rc = -EFAULT;
goto done;
}
if (copy_from_user(args_buf->buf + *off, buf, count)) {
rc = -EFAULT;
goto done;
}
*off += count;
rc = count;
done:
if (rc < 0) {
kfree(dp->data);
dp->data = NULL;
}
return rc;
}
static int validate_flash_release(struct inode *inode, struct file *file)
{
struct proc_dir_entry *dp = PDE(file_inode(file));
struct rtas_validate_flash_t *args_buf;
args_buf = (struct rtas_validate_flash_t *) dp->data;
if (args_buf->status == VALIDATE_READY) {
args_buf->buf_size = VALIDATE_BUF_SIZE;
validate_flash(args_buf);
}
atomic_dec(&dp->count);
return 0;
}
static void rtas_flash_firmware(int reboot_type)
{
unsigned long image_size;
struct flash_block_list *f, *next, *flist;
unsigned long rtas_block_list;
int i, status, update_token;
if (rtas_firmware_flash_list == NULL)
return;
if (reboot_type != SYS_RESTART) {
printk(KERN_ALERT "FLASH: firmware flash requires a reboot\n");
printk(KERN_ALERT "FLASH: the firmware image will NOT be flashed\n");
return;
}
update_token = rtas_token("ibm,update-flash-64-and-reboot");
if (update_token == RTAS_UNKNOWN_SERVICE) {
printk(KERN_ALERT "FLASH: ibm,update-flash-64-and-reboot "
"is not available -- not a service partition?\n");
printk(KERN_ALERT "FLASH: firmware will not be flashed\n");
return;
}
rtas_cancel_event_scan();
spin_lock(&rtas_data_buf_lock);
flist = (struct flash_block_list *)&rtas_data_buf[0];
flist->num_blocks = 0;
flist->next = rtas_firmware_flash_list;
rtas_block_list = __pa(flist);
if (rtas_block_list >= 4UL*1024*1024*1024) {
printk(KERN_ALERT "FLASH: kernel bug...flash list header addr above 4GB\n");
spin_unlock(&rtas_data_buf_lock);
return;
}
printk(KERN_ALERT "FLASH: preparing saved firmware image for flash\n");
rtas_firmware_flash_list = NULL;
image_size = 0;
for (f = flist; f; f = next) {
for (i = 0; i < f->num_blocks; i++) {
f->blocks[i].data = (char *)__pa(f->blocks[i].data);
image_size += f->blocks[i].length;
}
next = f->next;
if (f->next)
f->next = (struct flash_block_list *)__pa(f->next);
else
f->next = NULL;
f->num_blocks = (FLASH_BLOCK_LIST_VERSION << 56) | ((f->num_blocks+1)*16);
}
printk(KERN_ALERT "FLASH: flash image is %ld bytes\n", image_size);
printk(KERN_ALERT "FLASH: performing flash and reboot\n");
rtas_progress("Flashing \n", 0x0);
rtas_progress("Please Wait... ", 0x0);
printk(KERN_ALERT "FLASH: this will take several minutes. Do not power off!\n");
status = rtas_call(update_token, 1, 1, NULL, rtas_block_list);
switch (status) {
case 0:
printk(KERN_ALERT "FLASH: success\n");
break;
case -1:
printk(KERN_ALERT "FLASH: hardware error. Firmware may not be not flashed\n");
break;
case -3:
printk(KERN_ALERT "FLASH: image is corrupt or not correct for this platform. Firmware not flashed\n");
break;
case -4:
printk(KERN_ALERT "FLASH: flash failed when partially complete. System may not reboot\n");
break;
default:
printk(KERN_ALERT "FLASH: unknown flash return code %d\n", status);
break;
}
spin_unlock(&rtas_data_buf_lock);
}
static void remove_flash_pde(struct proc_dir_entry *dp)
{
if (dp) {
kfree(dp->data);
remove_proc_entry(dp->name, dp->parent);
}
}
static int initialize_flash_pde_data(const char *rtas_call_name,
size_t buf_size,
struct proc_dir_entry *dp)
{
int *status;
int token;
dp->data = kzalloc(buf_size, GFP_KERNEL);
if (dp->data == NULL)
return -ENOMEM;
status = (int *) dp->data;
token = rtas_token(rtas_call_name);
if (token == RTAS_UNKNOWN_SERVICE)
*status = FLASH_AUTH;
else
*status = FLASH_NO_OP;
return 0;
}
static struct proc_dir_entry *create_flash_pde(const char *filename,
const struct file_operations *fops)
{
return proc_create(filename, S_IRUSR | S_IWUSR, NULL, fops);
}
static int __init rtas_flash_init(void)
{
int rc;
if (rtas_token("ibm,update-flash-64-and-reboot") ==
RTAS_UNKNOWN_SERVICE) {
pr_info("rtas_flash: no firmware flash support\n");
return 1;
}
firmware_flash_pde = create_flash_pde("powerpc/rtas/"
FIRMWARE_FLASH_NAME,
&rtas_flash_operations);
if (firmware_flash_pde == NULL) {
rc = -ENOMEM;
goto cleanup;
}
rc = initialize_flash_pde_data("ibm,update-flash-64-and-reboot",
sizeof(struct rtas_update_flash_t),
firmware_flash_pde);
if (rc != 0)
goto cleanup;
firmware_update_pde = create_flash_pde("powerpc/rtas/"
FIRMWARE_UPDATE_NAME,
&rtas_flash_operations);
if (firmware_update_pde == NULL) {
rc = -ENOMEM;
goto cleanup;
}
rc = initialize_flash_pde_data("ibm,update-flash-64-and-reboot",
sizeof(struct rtas_update_flash_t),
firmware_update_pde);
if (rc != 0)
goto cleanup;
validate_pde = create_flash_pde("powerpc/rtas/" VALIDATE_FLASH_NAME,
&validate_flash_operations);
if (validate_pde == NULL) {
rc = -ENOMEM;
goto cleanup;
}
rc = initialize_flash_pde_data("ibm,validate-flash-image",
sizeof(struct rtas_validate_flash_t),
validate_pde);
if (rc != 0)
goto cleanup;
manage_pde = create_flash_pde("powerpc/rtas/" MANAGE_FLASH_NAME,
&manage_flash_operations);
if (manage_pde == NULL) {
rc = -ENOMEM;
goto cleanup;
}
rc = initialize_flash_pde_data("ibm,manage-flash-image",
sizeof(struct rtas_manage_flash_t),
manage_pde);
if (rc != 0)
goto cleanup;
rtas_flash_term_hook = rtas_flash_firmware;
flash_block_cache = kmem_cache_create("rtas_flash_cache",
RTAS_BLK_SIZE, RTAS_BLK_SIZE, 0,
rtas_block_ctor);
if (!flash_block_cache) {
printk(KERN_ERR "%s: failed to create block cache\n",
__func__);
rc = -ENOMEM;
goto cleanup;
}
return 0;
cleanup:
remove_flash_pde(firmware_flash_pde);
remove_flash_pde(firmware_update_pde);
remove_flash_pde(validate_pde);
remove_flash_pde(manage_pde);
return rc;
}
static void __exit rtas_flash_cleanup(void)
{
rtas_flash_term_hook = NULL;
if (flash_block_cache)
kmem_cache_destroy(flash_block_cache);
remove_flash_pde(firmware_flash_pde);
remove_flash_pde(firmware_update_pde);
remove_flash_pde(validate_pde);
remove_flash_pde(manage_pde);
}
