static bool fw_get_builtin_firmware(struct firmware *fw, const char *name)
{
struct builtin_fw *b_fw;
for (b_fw = __start_builtin_fw; b_fw != __end_builtin_fw; b_fw++) {
if (strcmp(name, b_fw->name) == 0) {
fw->size = b_fw->size;
fw->data = b_fw->data;
return true;
}
}
return false;
}
static bool fw_is_builtin_firmware(const struct firmware *fw)
{
struct builtin_fw *b_fw;
for (b_fw = __start_builtin_fw; b_fw != __end_builtin_fw; b_fw++)
if (fw->data == b_fw->data)
return true;
return false;
}
static inline bool fw_get_builtin_firmware(struct firmware *fw, const char *name)
{
return false;
}
static inline bool fw_is_builtin_firmware(const struct firmware *fw)
{
return false;
}
static struct firmware_priv *to_firmware_priv(struct device *dev)
{
return container_of(dev, struct firmware_priv, dev);
}
static void fw_load_abort(struct firmware_priv *fw_priv)
{
set_bit(FW_STATUS_ABORT, &fw_priv->status);
wmb();
complete(&fw_priv->completion);
}
static ssize_t firmware_timeout_show(struct class *class,
struct class_attribute *attr,
char *buf)
{
return sprintf(buf, "%d\n", loading_timeout);
}
static ssize_t firmware_timeout_store(struct class *class,
struct class_attribute *attr,
const char *buf, size_t count)
{
loading_timeout = simple_strtol(buf, NULL, 10);
if (loading_timeout < 0)
loading_timeout = 0;
return count;
}
static void fw_dev_release(struct device *dev)
{
struct firmware_priv *fw_priv = to_firmware_priv(dev);
int i;
for (i = 0; i < fw_priv->nr_pages; i++)
__free_page(fw_priv->pages[i]);
kfree(fw_priv->pages);
kfree(fw_priv);
module_put(THIS_MODULE);
}
static int firmware_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct firmware_priv *fw_priv = to_firmware_priv(dev);
if (add_uevent_var(env, "FIRMWARE=%s", fw_priv->fw_id))
return -ENOMEM;
if (add_uevent_var(env, "TIMEOUT=%i", loading_timeout))
return -ENOMEM;
if (add_uevent_var(env, "ASYNC=%d", fw_priv->nowait))
return -ENOMEM;
return 0;
}
static ssize_t firmware_loading_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct firmware_priv *fw_priv = to_firmware_priv(dev);
int loading = test_bit(FW_STATUS_LOADING, &fw_priv->status);
return sprintf(buf, "%d\n", loading);
}
static void firmware_free_data(const struct firmware *fw)
{
int i;
vunmap(fw->data);
if (fw->pages) {
for (i = 0; i < PFN_UP(fw->size); i++)
__free_page(fw->pages[i]);
kfree(fw->pages);
}
}
static ssize_t firmware_loading_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct firmware_priv *fw_priv = to_firmware_priv(dev);
int loading = simple_strtol(buf, NULL, 10);
int i;
switch (loading) {
case 1:
mutex_lock(&fw_lock);
if (!fw_priv->fw) {
mutex_unlock(&fw_lock);
break;
}
firmware_free_data(fw_priv->fw);
memset(fw_priv->fw, 0, sizeof(struct firmware));
for (i = 0; i < fw_priv->nr_pages; i++)
__free_page(fw_priv->pages[i]);
kfree(fw_priv->pages);
fw_priv->pages = NULL;
fw_priv->page_array_size = 0;
fw_priv->nr_pages = 0;
set_bit(FW_STATUS_LOADING, &fw_priv->status);
mutex_unlock(&fw_lock);
break;
case 0:
if (test_bit(FW_STATUS_LOADING, &fw_priv->status)) {
vunmap(fw_priv->fw->data);
fw_priv->fw->data = vmap(fw_priv->pages,
fw_priv->nr_pages,
0, PAGE_KERNEL_RO);
if (!fw_priv->fw->data) {
dev_err(dev, "%s: vmap() failed\n", __func__);
goto err;
}
fw_priv->fw->pages = fw_priv->pages;
fw_priv->pages = NULL;
fw_priv->page_array_size = 0;
fw_priv->nr_pages = 0;
complete(&fw_priv->completion);
clear_bit(FW_STATUS_LOADING, &fw_priv->status);
break;
}
default:
dev_err(dev, "%s: unexpected value (%d)\n", __func__, loading);
case -1:
err:
fw_load_abort(fw_priv);
break;
}
return count;
}
static ssize_t firmware_data_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buffer, loff_t offset, size_t count)
{
struct device *dev = to_dev(kobj);
struct firmware_priv *fw_priv = to_firmware_priv(dev);
struct firmware *fw;
ssize_t ret_count;
mutex_lock(&fw_lock);
fw = fw_priv->fw;
if (!fw || test_bit(FW_STATUS_DONE, &fw_priv->status)) {
ret_count = -ENODEV;
goto out;
}
if (offset > fw->size) {
ret_count = 0;
goto out;
}
if (count > fw->size - offset)
count = fw->size - offset;
ret_count = count;
while (count) {
void *page_data;
int page_nr = offset >> PAGE_SHIFT;
int page_ofs = offset & (PAGE_SIZE-1);
int page_cnt = min_t(size_t, PAGE_SIZE - page_ofs, count);
page_data = kmap(fw_priv->pages[page_nr]);
memcpy(buffer, page_data + page_ofs, page_cnt);
kunmap(fw_priv->pages[page_nr]);
buffer += page_cnt;
offset += page_cnt;
count -= page_cnt;
}
out:
mutex_unlock(&fw_lock);
return ret_count;
}
static int fw_realloc_buffer(struct firmware_priv *fw_priv, int min_size)
{
int pages_needed = ALIGN(min_size, PAGE_SIZE) >> PAGE_SHIFT;
if (fw_priv->page_array_size < pages_needed) {
int new_array_size = max(pages_needed,
fw_priv->page_array_size * 2);
struct page **new_pages;
new_pages = kmalloc(new_array_size * sizeof(void *),
GFP_KERNEL);
if (!new_pages) {
fw_load_abort(fw_priv);
return -ENOMEM;
}
memcpy(new_pages, fw_priv->pages,
fw_priv->page_array_size * sizeof(void *));
memset(&new_pages[fw_priv->page_array_size], 0, sizeof(void *) *
(new_array_size - fw_priv->page_array_size));
kfree(fw_priv->pages);
fw_priv->pages = new_pages;
fw_priv->page_array_size = new_array_size;
}
while (fw_priv->nr_pages < pages_needed) {
fw_priv->pages[fw_priv->nr_pages] =
alloc_page(GFP_KERNEL | __GFP_HIGHMEM);
if (!fw_priv->pages[fw_priv->nr_pages]) {
fw_load_abort(fw_priv);
return -ENOMEM;
}
fw_priv->nr_pages++;
}
return 0;
}
static ssize_t firmware_data_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buffer, loff_t offset, size_t count)
{
struct device *dev = to_dev(kobj);
struct firmware_priv *fw_priv = to_firmware_priv(dev);
struct firmware *fw;
ssize_t retval;
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
mutex_lock(&fw_lock);
fw = fw_priv->fw;
if (!fw || test_bit(FW_STATUS_DONE, &fw_priv->status)) {
retval = -ENODEV;
goto out;
}
retval = fw_realloc_buffer(fw_priv, offset + count);
if (retval)
goto out;
retval = count;
while (count) {
void *page_data;
int page_nr = offset >> PAGE_SHIFT;
int page_ofs = offset & (PAGE_SIZE - 1);
int page_cnt = min_t(size_t, PAGE_SIZE - page_ofs, count);
page_data = kmap(fw_priv->pages[page_nr]);
memcpy(page_data + page_ofs, buffer, page_cnt);
kunmap(fw_priv->pages[page_nr]);
buffer += page_cnt;
offset += page_cnt;
count -= page_cnt;
}
fw->size = max_t(size_t, offset, fw->size);
out:
mutex_unlock(&fw_lock);
return retval;
}
static void firmware_class_timeout(u_long data)
{
struct firmware_priv *fw_priv = (struct firmware_priv *) data;
fw_load_abort(fw_priv);
}
static struct firmware_priv *
fw_create_instance(struct firmware *firmware, const char *fw_name,
struct device *device, bool uevent, bool nowait)
{
struct firmware_priv *fw_priv;
struct device *f_dev;
int error;
fw_priv = kzalloc(sizeof(*fw_priv) + strlen(fw_name) + 1 , GFP_KERNEL);
if (!fw_priv) {
dev_err(device, "%s: kmalloc failed\n", __func__);
error = -ENOMEM;
goto err_out;
}
fw_priv->fw = firmware;
fw_priv->nowait = nowait;
strcpy(fw_priv->fw_id, fw_name);
init_completion(&fw_priv->completion);
setup_timer(&fw_priv->timeout,
firmware_class_timeout, (u_long) fw_priv);
f_dev = &fw_priv->dev;
device_initialize(f_dev);
dev_set_name(f_dev, "%s", dev_name(device));
f_dev->parent = device;
f_dev->class = &firmware_class;
dev_set_uevent_suppress(f_dev, true);
__module_get(THIS_MODULE);
error = device_add(f_dev);
if (error) {
dev_err(device, "%s: device_register failed\n", __func__);
goto err_put_dev;
}
error = device_create_bin_file(f_dev, &firmware_attr_data);
if (error) {
dev_err(device, "%s: sysfs_create_bin_file failed\n", __func__);
goto err_del_dev;
}
error = device_create_file(f_dev, &dev_attr_loading);
if (error) {
dev_err(device, "%s: device_create_file failed\n", __func__);
goto err_del_bin_attr;
}
if (uevent)
dev_set_uevent_suppress(f_dev, false);
return fw_priv;
err_del_bin_attr:
device_remove_bin_file(f_dev, &firmware_attr_data);
err_del_dev:
device_del(f_dev);
err_put_dev:
put_device(f_dev);
err_out:
return ERR_PTR(error);
}
static void fw_destroy_instance(struct firmware_priv *fw_priv)
{
struct device *f_dev = &fw_priv->dev;
device_remove_file(f_dev, &dev_attr_loading);
device_remove_bin_file(f_dev, &firmware_attr_data);
device_unregister(f_dev);
}
static int _request_firmware(const struct firmware **firmware_p,
const char *name, struct device *device,
bool uevent, bool nowait)
{
struct firmware_priv *fw_priv;
struct firmware *firmware;
int retval = 0;
if (!firmware_p)
return -EINVAL;
*firmware_p = firmware = kzalloc(sizeof(*firmware), GFP_KERNEL);
if (!firmware) {
dev_err(device, "%s: kmalloc(struct firmware) failed\n",
__func__);
retval = -ENOMEM;
goto out;
}
if (fw_get_builtin_firmware(firmware, name)) {
dev_dbg(device, "firmware: using built-in firmware %s\n", name);
return 0;
}
if (WARN_ON(usermodehelper_is_disabled())) {
dev_err(device, "firmware: %s will not be loaded\n", name);
retval = -EBUSY;
goto out;
}
if (uevent)
dev_dbg(device, "firmware: requesting %s\n", name);
fw_priv = fw_create_instance(firmware, name, device, uevent, nowait);
if (IS_ERR(fw_priv)) {
retval = PTR_ERR(fw_priv);
goto out;
}
if (uevent) {
if (loading_timeout > 0)
mod_timer(&fw_priv->timeout,
round_jiffies_up(jiffies +
loading_timeout * HZ));
kobject_uevent(&fw_priv->dev.kobj, KOBJ_ADD);
}
wait_for_completion(&fw_priv->completion);
set_bit(FW_STATUS_DONE, &fw_priv->status);
del_timer_sync(&fw_priv->timeout);
mutex_lock(&fw_lock);
if (!fw_priv->fw->size || test_bit(FW_STATUS_ABORT, &fw_priv->status))
retval = -ENOENT;
fw_priv->fw = NULL;
mutex_unlock(&fw_lock);
fw_destroy_instance(fw_priv);
out:
if (retval) {
release_firmware(firmware);
*firmware_p = NULL;
}
return retval;
}
int
request_firmware(const struct firmware **firmware_p, const char *name,
struct device *device)
{
return _request_firmware(firmware_p, name, device, true, false);
}
void release_firmware(const struct firmware *fw)
{
if (fw) {
if (!fw_is_builtin_firmware(fw))
firmware_free_data(fw);
kfree(fw);
}
}
static int request_firmware_work_func(void *arg)
{
struct firmware_work *fw_work = arg;
const struct firmware *fw;
int ret;
if (!arg) {
WARN_ON(1);
return 0;
}
ret = _request_firmware(&fw, fw_work->name, fw_work->device,
fw_work->uevent, true);
fw_work->cont(fw, fw_work->context);
module_put(fw_work->module);
kfree(fw_work);
return ret;
}
int
request_firmware_nowait(
struct module *module, bool uevent,
const char *name, struct device *device, gfp_t gfp, void *context,
void (*cont)(const struct firmware *fw, void *context))
{
struct task_struct *task;
struct firmware_work *fw_work;
fw_work = kzalloc(sizeof (struct firmware_work), gfp);
if (!fw_work)
return -ENOMEM;
fw_work->module = module;
fw_work->name = name;
fw_work->device = device;
fw_work->context = context;
fw_work->cont = cont;
fw_work->uevent = uevent;
if (!try_module_get(module)) {
kfree(fw_work);
return -EFAULT;
}
task = kthread_run(request_firmware_work_func, fw_work,
"firmware/%s", name);
if (IS_ERR(task)) {
fw_work->cont(NULL, fw_work->context);
module_put(fw_work->module);
kfree(fw_work);
return PTR_ERR(task);
}
return 0;
}
static int __init firmware_class_init(void)
{
return class_register(&firmware_class);
}
static void __exit firmware_class_exit(void)
{
class_unregister(&firmware_class);
}
