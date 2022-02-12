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
struct rtas_update_flash_t *const uf = &rtas_update_flash_data;
mutex_lock(&rtas_update_flash_mutex);
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
mutex_unlock(&rtas_update_flash_mutex);
return 0;
}
static size_t get_flash_status_msg(int status, char *buf)
{
const char *msg;
size_t len;
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
return sprintf(buf, "error: unexpected status value %d\n",
status);
}
len = strlen(msg);
memcpy(buf, msg, len + 1);
return len;
}
static ssize_t rtas_flash_read_msg(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct rtas_update_flash_t *const uf = &rtas_update_flash_data;
char msg[RTAS_MSG_MAXLEN];
size_t len;
int status;
mutex_lock(&rtas_update_flash_mutex);
status = uf->status;
mutex_unlock(&rtas_update_flash_mutex);
len = get_flash_status_msg(status, msg);
return simple_read_from_buffer(buf, count, ppos, msg, len);
}
static ssize_t rtas_flash_read_num(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct rtas_update_flash_t *const uf = &rtas_update_flash_data;
char msg[RTAS_MSG_MAXLEN];
int status;
mutex_lock(&rtas_update_flash_mutex);
status = uf->status;
mutex_unlock(&rtas_update_flash_mutex);
sprintf(msg, "%d\n", status);
return simple_read_from_buffer(buf, count, ppos, msg, strlen(msg));
}
static ssize_t rtas_flash_write(struct file *file, const char __user *buffer,
size_t count, loff_t *off)
{
struct rtas_update_flash_t *const uf = &rtas_update_flash_data;
char *p;
int next_free, rc;
struct flash_block_list *fl;
mutex_lock(&rtas_update_flash_mutex);
if (uf->status == FLASH_AUTH || count == 0)
goto out;
if (uf->flist == NULL) {
uf->flist = kmem_cache_zalloc(flash_block_cache, GFP_KERNEL);
if (!uf->flist)
goto nomem;
}
fl = uf->flist;
while (fl->next)
fl = fl->next;
next_free = fl->num_blocks;
if (next_free == FLASH_BLOCKS_PER_NODE) {
fl->next = kmem_cache_zalloc(flash_block_cache, GFP_KERNEL);
if (!fl->next)
goto nomem;
fl = fl->next;
next_free = 0;
}
if (count > RTAS_BLK_SIZE)
count = RTAS_BLK_SIZE;
p = kmem_cache_zalloc(flash_block_cache, GFP_KERNEL);
if (!p)
goto nomem;
if(copy_from_user(p, buffer, count)) {
kmem_cache_free(flash_block_cache, p);
rc = -EFAULT;
goto error;
}
fl->blocks[next_free].data = p;
fl->blocks[next_free].length = count;
fl->num_blocks++;
out:
mutex_unlock(&rtas_update_flash_mutex);
return count;
nomem:
rc = -ENOMEM;
error:
mutex_unlock(&rtas_update_flash_mutex);
return rc;
}
static void manage_flash(struct rtas_manage_flash_t *args_buf, unsigned int op)
{
s32 rc;
do {
rc = rtas_call(rtas_token("ibm,manage-flash-image"), 1, 1,
NULL, op);
} while (rtas_busy_delay(rc));
args_buf->status = rc;
}
static ssize_t manage_flash_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct rtas_manage_flash_t *const args_buf = &rtas_manage_flash_data;
char msg[RTAS_MSG_MAXLEN];
int msglen, status;
mutex_lock(&rtas_manage_flash_mutex);
status = args_buf->status;
mutex_unlock(&rtas_manage_flash_mutex);
msglen = sprintf(msg, "%d\n", status);
return simple_read_from_buffer(buf, count, ppos, msg, msglen);
}
static ssize_t manage_flash_write(struct file *file, const char __user *buf,
size_t count, loff_t *off)
{
struct rtas_manage_flash_t *const args_buf = &rtas_manage_flash_data;
static const char reject_str[] = "0";
static const char commit_str[] = "1";
char stkbuf[10];
int op, rc;
mutex_lock(&rtas_manage_flash_mutex);
if ((args_buf->status == MANAGE_AUTH) || (count == 0))
goto out;
op = -1;
if (buf) {
if (count > 9) count = 9;
rc = -EFAULT;
if (copy_from_user (stkbuf, buf, count))
goto error;
if (strncmp(stkbuf, reject_str, strlen(reject_str)) == 0)
op = RTAS_REJECT_TMP_IMG;
else if (strncmp(stkbuf, commit_str, strlen(commit_str)) == 0)
op = RTAS_COMMIT_TMP_IMG;
}
if (op == -1) {
rc = -EINVAL;
goto error;
}
manage_flash(args_buf, op);
out:
mutex_unlock(&rtas_manage_flash_mutex);
return count;
error:
mutex_unlock(&rtas_manage_flash_mutex);
return rc;
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
char *msg, int msglen)
{
int n;
if (args_buf->status >= VALIDATE_TMP_UPDATE) {
n = sprintf(msg, "%d\n", args_buf->update_results);
if ((args_buf->update_results >= VALIDATE_CUR_UNKNOWN) ||
(args_buf->update_results == VALIDATE_TMP_UPDATE))
n += snprintf(msg + n, msglen - n, "%s\n",
args_buf->buf);
} else {
n = sprintf(msg, "%d\n", args_buf->status);
}
return n;
}
static ssize_t validate_flash_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct rtas_validate_flash_t *const args_buf =
&rtas_validate_flash_data;
char msg[VALIDATE_MSG_LEN];
int msglen;
mutex_lock(&rtas_validate_flash_mutex);
msglen = get_validate_flash_msg(args_buf, msg, VALIDATE_MSG_LEN);
mutex_unlock(&rtas_validate_flash_mutex);
return simple_read_from_buffer(buf, count, ppos, msg, msglen);
}
static ssize_t validate_flash_write(struct file *file, const char __user *buf,
size_t count, loff_t *off)
{
struct rtas_validate_flash_t *const args_buf =
&rtas_validate_flash_data;
int rc;
mutex_lock(&rtas_validate_flash_mutex);
if ((*off >= VALIDATE_BUF_SIZE) ||
(args_buf->status == VALIDATE_AUTH)) {
*off += count;
mutex_unlock(&rtas_validate_flash_mutex);
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
mutex_unlock(&rtas_validate_flash_mutex);
return rc;
}
static int validate_flash_release(struct inode *inode, struct file *file)
{
struct rtas_validate_flash_t *const args_buf =
&rtas_validate_flash_data;
mutex_lock(&rtas_validate_flash_mutex);
if (args_buf->status == VALIDATE_READY) {
args_buf->buf_size = VALIDATE_BUF_SIZE;
validate_flash(args_buf);
}
mutex_unlock(&rtas_validate_flash_mutex);
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
f->blocks[i].data = (char *)cpu_to_be64(__pa(f->blocks[i].data));
image_size += f->blocks[i].length;
f->blocks[i].length = cpu_to_be64(f->blocks[i].length);
}
next = f->next;
if (f->next)
f->next = (struct flash_block_list *)cpu_to_be64(__pa(f->next));
else
f->next = NULL;
f->num_blocks = (FLASH_BLOCK_LIST_VERSION << 56) | ((f->num_blocks+1)*16);
f->num_blocks = cpu_to_be64(f->num_blocks);
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
static int __init rtas_flash_init(void)
{
int i;
if (rtas_token("ibm,update-flash-64-and-reboot") ==
RTAS_UNKNOWN_SERVICE) {
pr_info("rtas_flash: no firmware flash support\n");
return -EINVAL;
}
rtas_validate_flash_data.buf = kzalloc(VALIDATE_BUF_SIZE, GFP_KERNEL);
if (!rtas_validate_flash_data.buf)
return -ENOMEM;
flash_block_cache = kmem_cache_create("rtas_flash_cache",
RTAS_BLK_SIZE, RTAS_BLK_SIZE, 0,
NULL);
if (!flash_block_cache) {
printk(KERN_ERR "%s: failed to create block cache\n",
__func__);
goto enomem_buf;
}
for (i = 0; i < ARRAY_SIZE(rtas_flash_files); i++) {
const struct rtas_flash_file *f = &rtas_flash_files[i];
int token;
if (!proc_create(f->filename, S_IRUSR | S_IWUSR, NULL, &f->fops))
goto enomem;
token = rtas_token(f->rtas_call_name);
if (token == RTAS_UNKNOWN_SERVICE)
*f->status = FLASH_AUTH;
else
*f->status = FLASH_NO_OP;
}
rtas_flash_term_hook = rtas_flash_firmware;
return 0;
enomem:
while (--i >= 0) {
const struct rtas_flash_file *f = &rtas_flash_files[i];
remove_proc_entry(f->filename, NULL);
}
kmem_cache_destroy(flash_block_cache);
enomem_buf:
kfree(rtas_validate_flash_data.buf);
return -ENOMEM;
}
static void __exit rtas_flash_cleanup(void)
{
int i;
rtas_flash_term_hook = NULL;
if (rtas_firmware_flash_list) {
free_flash_list(rtas_firmware_flash_list);
rtas_firmware_flash_list = NULL;
}
for (i = 0; i < ARRAY_SIZE(rtas_flash_files); i++) {
const struct rtas_flash_file *f = &rtas_flash_files[i];
remove_proc_entry(f->filename, NULL);
}
kmem_cache_destroy(flash_block_cache);
kfree(rtas_validate_flash_data.buf);
}
