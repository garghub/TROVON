static inline void opal_flash_validate(void)
{
struct validate_flash_t *args_buf = &validate_flash_data;
args_buf->status = opal_validate_flash(__pa(args_buf->buf),
&(args_buf->buf_size),
&(args_buf->result));
}
static ssize_t validate_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct validate_flash_t *args_buf = &validate_flash_data;
int len;
if (args_buf->status < VALIDATE_TMP_UPDATE) {
len = sprintf(buf, "%d\n", args_buf->status);
goto out;
}
len = sprintf(buf, "%d\n", args_buf->result);
if ((args_buf->result != VALIDATE_TMP_UPDATE) &&
(args_buf->result < VALIDATE_CUR_UNKNOWN))
goto out;
if (args_buf->buf_size > (VALIDATE_BUF_SIZE - len)) {
memcpy(buf + len, args_buf->buf, VALIDATE_BUF_SIZE - len);
len = VALIDATE_BUF_SIZE;
} else {
memcpy(buf + len, args_buf->buf, args_buf->buf_size);
len += args_buf->buf_size;
}
out:
args_buf->status = FLASH_NO_OP;
return len;
}
static ssize_t validate_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
struct validate_flash_t *args_buf = &validate_flash_data;
if (buf[0] != '1')
return -EINVAL;
mutex_lock(&image_data_mutex);
if (image_data.status != IMAGE_READY ||
image_data.size < VALIDATE_BUF_SIZE) {
args_buf->result = VALIDATE_INVALID_IMG;
args_buf->status = VALIDATE_IMG_INCOMPLETE;
goto out;
}
memcpy(args_buf->buf, image_data.data, VALIDATE_BUF_SIZE);
args_buf->status = VALIDATE_IMG_READY;
args_buf->buf_size = VALIDATE_BUF_SIZE;
opal_flash_validate();
out:
mutex_unlock(&image_data_mutex);
return count;
}
static inline void opal_flash_manage(uint8_t op)
{
struct manage_flash_t *const args_buf = &manage_flash_data;
args_buf->status = opal_manage_flash(op);
}
static ssize_t manage_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct manage_flash_t *const args_buf = &manage_flash_data;
int rc;
rc = sprintf(buf, "%d\n", args_buf->status);
args_buf->status = FLASH_NO_OP;
return rc;
}
static ssize_t manage_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
uint8_t op;
switch (buf[0]) {
case '0':
op = FLASH_REJECT_TMP_SIDE;
break;
case '1':
op = FLASH_COMMIT_TMP_SIDE;
break;
default:
return -EINVAL;
}
opal_flash_manage(op);
return count;
}
static void free_sg_list(struct opal_sg_list *list)
{
struct opal_sg_list *sg1;
while (list) {
sg1 = list->next;
kfree(list);
list = sg1;
}
list = NULL;
}
static struct opal_sg_list *image_data_to_sglist(void)
{
struct opal_sg_list *sg1, *list = NULL;
void *addr;
int size;
addr = image_data.data;
size = image_data.size;
sg1 = kzalloc((sizeof(struct opal_sg_list)), GFP_KERNEL);
if (!sg1)
return NULL;
list = sg1;
sg1->num_entries = 0;
while (size > 0) {
sg1->entry[sg1->num_entries].data =
(void *)(vmalloc_to_pfn(addr) << PAGE_SHIFT);
if (size > PAGE_SIZE)
sg1->entry[sg1->num_entries].length = PAGE_SIZE;
else
sg1->entry[sg1->num_entries].length = size;
sg1->num_entries++;
if (sg1->num_entries >= SG_ENTRIES_PER_NODE) {
sg1->next = kzalloc((sizeof(struct opal_sg_list)),
GFP_KERNEL);
if (!sg1->next) {
pr_err("%s : Failed to allocate memory\n",
__func__);
goto nomem;
}
sg1 = sg1->next;
sg1->num_entries = 0;
}
addr += PAGE_SIZE;
size -= PAGE_SIZE;
}
return list;
nomem:
free_sg_list(list);
return NULL;
}
static int opal_flash_update(int op)
{
struct opal_sg_list *sg, *list, *next;
unsigned long addr;
int64_t rc = OPAL_PARAMETER;
if (op == FLASH_UPDATE_CANCEL) {
pr_alert("FLASH: Image update cancelled\n");
addr = '\0';
goto flash;
}
list = image_data_to_sglist();
if (!list)
goto invalid_img;
addr = __pa(list);
for (sg = list; sg; sg = next) {
next = sg->next;
if (sg->next)
sg->next = (struct opal_sg_list *)__pa(sg->next);
else
sg->next = NULL;
sg->num_entries = (SG_LIST_VERSION << 56) |
(sg->num_entries * sizeof(struct opal_sg_entry) + 16);
}
pr_alert("FLASH: Image is %u bytes\n", image_data.size);
pr_alert("FLASH: Image update requested\n");
pr_alert("FLASH: Image will be updated during system reboot\n");
pr_alert("FLASH: This will take several minutes. Do not power off!\n");
flash:
rc = opal_update_flash(addr);
invalid_img:
return rc;
}
static ssize_t update_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct update_flash_t *const args_buf = &update_flash_data;
return sprintf(buf, "%d\n", args_buf->status);
}
static ssize_t update_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
struct update_flash_t *const args_buf = &update_flash_data;
int rc = count;
mutex_lock(&image_data_mutex);
switch (buf[0]) {
case '0':
if (args_buf->status == FLASH_IMG_READY)
opal_flash_update(FLASH_UPDATE_CANCEL);
args_buf->status = FLASH_NO_OP;
break;
case '1':
if (image_data.status == IMAGE_READY)
args_buf->status =
opal_flash_update(FLASH_UPDATE_INIT);
else
args_buf->status = FLASH_INVALID_IMG;
break;
default:
rc = -EINVAL;
}
mutex_unlock(&image_data_mutex);
return rc;
}
static void free_image_buf(void)
{
void *addr;
int size;
addr = image_data.data;
size = PAGE_ALIGN(image_data.size);
while (size > 0) {
ClearPageReserved(vmalloc_to_page(addr));
addr += PAGE_SIZE;
size -= PAGE_SIZE;
}
vfree(image_data.data);
image_data.data = NULL;
image_data.status = IMAGE_INVALID;
}
static int alloc_image_buf(char *buffer, size_t count)
{
void *addr;
int size;
if (count < sizeof(struct image_header_t)) {
pr_warn("FLASH: Invalid candidate image\n");
return -EINVAL;
}
memcpy(&image_header, (void *)buffer, sizeof(struct image_header_t));
image_data.size = be32_to_cpu(image_header.size);
pr_debug("FLASH: Candiate image size = %u\n", image_data.size);
if (image_data.size > MAX_IMAGE_SIZE) {
pr_warn("FLASH: Too large image\n");
return -EINVAL;
}
if (image_data.size < VALIDATE_BUF_SIZE) {
pr_warn("FLASH: Image is shorter than expected\n");
return -EINVAL;
}
image_data.data = vzalloc(PAGE_ALIGN(image_data.size));
if (!image_data.data) {
pr_err("%s : Failed to allocate memory\n", __func__);
return -ENOMEM;
}
addr = image_data.data;
size = PAGE_ALIGN(image_data.size);
while (size > 0) {
SetPageReserved(vmalloc_to_page(addr));
addr += PAGE_SIZE;
size -= PAGE_SIZE;
}
image_data.status = IMAGE_LOADING;
return 0;
}
static ssize_t image_data_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buffer, loff_t pos, size_t count)
{
int rc;
mutex_lock(&image_data_mutex);
if (pos == 0) {
if (image_data.data)
free_image_buf();
if (update_flash_data.status == FLASH_IMG_READY)
opal_flash_update(FLASH_UPDATE_CANCEL);
rc = alloc_image_buf(buffer, count);
if (rc)
goto out;
}
if (image_data.status != IMAGE_LOADING) {
rc = -ENOMEM;
goto out;
}
if ((pos + count) > image_data.size) {
rc = -EINVAL;
goto out;
}
memcpy(image_data.data + pos, (void *)buffer, count);
rc = count;
if ((pos + count) == image_data.size) {
pr_debug("FLASH: Candidate image loaded....\n");
image_data.status = IMAGE_READY;
}
out:
mutex_unlock(&image_data_mutex);
return rc;
}
void __init opal_flash_init(void)
{
int ret;
validate_flash_data.buf = kzalloc(VALIDATE_BUF_SIZE, GFP_KERNEL);
if (!validate_flash_data.buf) {
pr_err("%s : Failed to allocate memory\n", __func__);
return;
}
if (!opal_kobj) {
pr_warn("FLASH: opal kobject is not available\n");
goto nokobj;
}
ret = sysfs_create_group(opal_kobj, &image_op_attr_group);
if (ret) {
pr_warn("FLASH: Failed to create sysfs files\n");
goto nokobj;
}
ret = sysfs_create_bin_file(opal_kobj, &image_data_attr);
if (ret) {
pr_warn("FLASH: Failed to create sysfs files\n");
goto nosysfs_file;
}
validate_flash_data.status = FLASH_NO_OP;
manage_flash_data.status = FLASH_NO_OP;
update_flash_data.status = FLASH_NO_OP;
image_data.status = IMAGE_INVALID;
return;
nosysfs_file:
sysfs_remove_group(opal_kobj, &image_op_attr_group);
nokobj:
kfree(validate_flash_data.buf);
return;
}
