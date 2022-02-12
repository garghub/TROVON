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
static inline long firmware_loading_timeout(void)
{
return loading_timeout > 0 ? loading_timeout * HZ : MAX_SCHEDULE_TIMEOUT;
}
static struct firmware_buf *__allocate_fw_buf(const char *fw_name,
struct firmware_cache *fwc)
{
struct firmware_buf *buf;
buf = kzalloc(sizeof(*buf) + strlen(fw_name) + 1 , GFP_ATOMIC);
if (!buf)
return buf;
kref_init(&buf->ref);
strcpy(buf->fw_id, fw_name);
buf->fwc = fwc;
init_completion(&buf->completion);
buf->fmt = VMALLOC_BUF;
pr_debug("%s: fw-%s buf=%p\n", __func__, fw_name, buf);
return buf;
}
static struct firmware_buf *__fw_lookup_buf(const char *fw_name)
{
struct firmware_buf *tmp;
struct firmware_cache *fwc = &fw_cache;
list_for_each_entry(tmp, &fwc->head, list)
if (!strcmp(tmp->fw_id, fw_name))
return tmp;
return NULL;
}
static int fw_lookup_and_allocate_buf(const char *fw_name,
struct firmware_cache *fwc,
struct firmware_buf **buf)
{
struct firmware_buf *tmp;
spin_lock(&fwc->lock);
tmp = __fw_lookup_buf(fw_name);
if (tmp) {
kref_get(&tmp->ref);
spin_unlock(&fwc->lock);
*buf = tmp;
return 1;
}
tmp = __allocate_fw_buf(fw_name, fwc);
if (tmp)
list_add(&tmp->list, &fwc->head);
spin_unlock(&fwc->lock);
*buf = tmp;
return tmp ? 0 : -ENOMEM;
}
static struct firmware_buf *fw_lookup_buf(const char *fw_name)
{
struct firmware_buf *tmp;
struct firmware_cache *fwc = &fw_cache;
spin_lock(&fwc->lock);
tmp = __fw_lookup_buf(fw_name);
spin_unlock(&fwc->lock);
return tmp;
}
static void __fw_free_buf(struct kref *ref)
{
struct firmware_buf *buf = to_fwbuf(ref);
struct firmware_cache *fwc = buf->fwc;
int i;
pr_debug("%s: fw-%s buf=%p data=%p size=%u\n",
__func__, buf->fw_id, buf, buf->data,
(unsigned int)buf->size);
spin_lock(&fwc->lock);
list_del(&buf->list);
spin_unlock(&fwc->lock);
if (buf->fmt == PAGE_BUF) {
vunmap(buf->data);
for (i = 0; i < buf->nr_pages; i++)
__free_page(buf->pages[i]);
kfree(buf->pages);
} else
vfree(buf->data);
kfree(buf);
}
static void fw_free_buf(struct firmware_buf *buf)
{
kref_put(&buf->ref, __fw_free_buf);
}
static noinline long fw_file_size(struct file *file)
{
struct kstat st;
if (vfs_getattr(file->f_path.mnt, file->f_path.dentry, &st))
return -1;
if (!S_ISREG(st.mode))
return -1;
if (st.size != (long)st.size)
return -1;
return st.size;
}
static bool fw_read_file_contents(struct file *file, struct firmware_buf *fw_buf)
{
long size;
char *buf;
size = fw_file_size(file);
if (size < 0)
return false;
buf = vmalloc(size);
if (!buf)
return false;
if (kernel_read(file, 0, buf, size) != size) {
vfree(buf);
return false;
}
fw_buf->data = buf;
fw_buf->size = size;
return true;
}
static bool fw_get_filesystem_firmware(struct firmware_buf *buf)
{
int i;
bool success = false;
char *path = __getname();
for (i = 0; i < ARRAY_SIZE(fw_path); i++) {
struct file *file;
snprintf(path, PATH_MAX, "%s/%s", fw_path[i], buf->fw_id);
file = filp_open(path, O_RDONLY, 0);
if (IS_ERR(file))
continue;
success = fw_read_file_contents(file, buf);
fput(file);
if (success)
break;
}
__putname(path);
return success;
}
static struct firmware_priv *to_firmware_priv(struct device *dev)
{
return container_of(dev, struct firmware_priv, dev);
}
static void fw_load_abort(struct firmware_priv *fw_priv)
{
struct firmware_buf *buf = fw_priv->buf;
set_bit(FW_STATUS_ABORT, &buf->status);
complete_all(&buf->completion);
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
kfree(fw_priv);
module_put(THIS_MODULE);
}
static int firmware_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct firmware_priv *fw_priv = to_firmware_priv(dev);
if (add_uevent_var(env, "FIRMWARE=%s", fw_priv->buf->fw_id))
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
int loading = test_bit(FW_STATUS_LOADING, &fw_priv->buf->status);
return sprintf(buf, "%d\n", loading);
}
static void firmware_free_data(const struct firmware *fw)
{
if (!fw->priv) {
vfree(fw->data);
return;
}
fw_free_buf(fw->priv);
}
static int fw_map_pages_buf(struct firmware_buf *buf)
{
if (buf->fmt != PAGE_BUF)
return 0;
if (buf->data)
vunmap(buf->data);
buf->data = vmap(buf->pages, buf->nr_pages, 0, PAGE_KERNEL_RO);
if (!buf->data)
return -ENOMEM;
return 0;
}
static ssize_t firmware_loading_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct firmware_priv *fw_priv = to_firmware_priv(dev);
struct firmware_buf *fw_buf = fw_priv->buf;
int loading = simple_strtol(buf, NULL, 10);
int i;
mutex_lock(&fw_lock);
if (!fw_buf)
goto out;
switch (loading) {
case 1:
if (!test_bit(FW_STATUS_DONE, &fw_buf->status)) {
for (i = 0; i < fw_buf->nr_pages; i++)
__free_page(fw_buf->pages[i]);
kfree(fw_buf->pages);
fw_buf->pages = NULL;
fw_buf->page_array_size = 0;
fw_buf->nr_pages = 0;
set_bit(FW_STATUS_LOADING, &fw_buf->status);
}
break;
case 0:
if (test_bit(FW_STATUS_LOADING, &fw_buf->status)) {
set_bit(FW_STATUS_DONE, &fw_buf->status);
clear_bit(FW_STATUS_LOADING, &fw_buf->status);
fw_map_pages_buf(fw_buf);
complete_all(&fw_buf->completion);
break;
}
default:
dev_err(dev, "%s: unexpected value (%d)\n", __func__, loading);
case -1:
fw_load_abort(fw_priv);
break;
}
out:
mutex_unlock(&fw_lock);
return count;
}
static ssize_t firmware_data_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buffer, loff_t offset, size_t count)
{
struct device *dev = kobj_to_dev(kobj);
struct firmware_priv *fw_priv = to_firmware_priv(dev);
struct firmware_buf *buf;
ssize_t ret_count;
mutex_lock(&fw_lock);
buf = fw_priv->buf;
if (!buf || test_bit(FW_STATUS_DONE, &buf->status)) {
ret_count = -ENODEV;
goto out;
}
if (offset > buf->size) {
ret_count = 0;
goto out;
}
if (count > buf->size - offset)
count = buf->size - offset;
ret_count = count;
while (count) {
void *page_data;
int page_nr = offset >> PAGE_SHIFT;
int page_ofs = offset & (PAGE_SIZE-1);
int page_cnt = min_t(size_t, PAGE_SIZE - page_ofs, count);
page_data = kmap(buf->pages[page_nr]);
memcpy(buffer, page_data + page_ofs, page_cnt);
kunmap(buf->pages[page_nr]);
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
struct firmware_buf *buf = fw_priv->buf;
int pages_needed = ALIGN(min_size, PAGE_SIZE) >> PAGE_SHIFT;
if (buf->page_array_size < pages_needed) {
int new_array_size = max(pages_needed,
buf->page_array_size * 2);
struct page **new_pages;
new_pages = kmalloc(new_array_size * sizeof(void *),
GFP_KERNEL);
if (!new_pages) {
fw_load_abort(fw_priv);
return -ENOMEM;
}
memcpy(new_pages, buf->pages,
buf->page_array_size * sizeof(void *));
memset(&new_pages[buf->page_array_size], 0, sizeof(void *) *
(new_array_size - buf->page_array_size));
kfree(buf->pages);
buf->pages = new_pages;
buf->page_array_size = new_array_size;
}
while (buf->nr_pages < pages_needed) {
buf->pages[buf->nr_pages] =
alloc_page(GFP_KERNEL | __GFP_HIGHMEM);
if (!buf->pages[buf->nr_pages]) {
fw_load_abort(fw_priv);
return -ENOMEM;
}
buf->nr_pages++;
}
return 0;
}
static ssize_t firmware_data_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buffer, loff_t offset, size_t count)
{
struct device *dev = kobj_to_dev(kobj);
struct firmware_priv *fw_priv = to_firmware_priv(dev);
struct firmware_buf *buf;
ssize_t retval;
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
mutex_lock(&fw_lock);
buf = fw_priv->buf;
if (!buf || test_bit(FW_STATUS_DONE, &buf->status)) {
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
page_data = kmap(buf->pages[page_nr]);
memcpy(page_data + page_ofs, buffer, page_cnt);
kunmap(buf->pages[page_nr]);
buffer += page_cnt;
offset += page_cnt;
count -= page_cnt;
}
buf->size = max_t(size_t, offset, buf->size);
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
fw_priv = kzalloc(sizeof(*fw_priv), GFP_KERNEL);
if (!fw_priv) {
dev_err(device, "%s: kmalloc failed\n", __func__);
fw_priv = ERR_PTR(-ENOMEM);
goto exit;
}
fw_priv->nowait = nowait;
fw_priv->fw = firmware;
setup_timer(&fw_priv->timeout,
firmware_class_timeout, (u_long) fw_priv);
f_dev = &fw_priv->dev;
device_initialize(f_dev);
dev_set_name(f_dev, "%s", fw_name);
f_dev->parent = device;
f_dev->class = &firmware_class;
exit:
return fw_priv;
}
static void fw_set_page_data(struct firmware_buf *buf, struct firmware *fw)
{
fw->priv = buf;
fw->pages = buf->pages;
fw->size = buf->size;
fw->data = buf->data;
pr_debug("%s: fw-%s buf=%p data=%p size=%u\n",
__func__, buf->fw_id, buf, buf->data,
(unsigned int)buf->size);
}
static void fw_name_devm_release(struct device *dev, void *res)
{
struct fw_name_devm *fwn = res;
if (fwn->magic == (unsigned long)&fw_cache)
pr_debug("%s: fw_name-%s devm-%p released\n",
__func__, fwn->name, res);
}
static int fw_devm_match(struct device *dev, void *res,
void *match_data)
{
struct fw_name_devm *fwn = res;
return (fwn->magic == (unsigned long)&fw_cache) &&
!strcmp(fwn->name, match_data);
}
static struct fw_name_devm *fw_find_devm_name(struct device *dev,
const char *name)
{
struct fw_name_devm *fwn;
fwn = devres_find(dev, fw_name_devm_release,
fw_devm_match, (void *)name);
return fwn;
}
static int fw_add_devm_name(struct device *dev, const char *name)
{
struct fw_name_devm *fwn;
fwn = fw_find_devm_name(dev, name);
if (fwn)
return 1;
fwn = devres_alloc(fw_name_devm_release, sizeof(struct fw_name_devm) +
strlen(name) + 1, GFP_KERNEL);
if (!fwn)
return -ENOMEM;
fwn->magic = (unsigned long)&fw_cache;
strcpy(fwn->name, name);
devres_add(dev, fwn);
return 0;
}
static int fw_add_devm_name(struct device *dev, const char *name)
{
return 0;
}
static void _request_firmware_cleanup(const struct firmware **firmware_p)
{
release_firmware(*firmware_p);
*firmware_p = NULL;
}
static struct firmware_priv *
_request_firmware_prepare(const struct firmware **firmware_p, const char *name,
struct device *device, bool uevent, bool nowait)
{
struct firmware *firmware;
struct firmware_priv *fw_priv = NULL;
struct firmware_buf *buf;
int ret;
if (!firmware_p)
return ERR_PTR(-EINVAL);
*firmware_p = firmware = kzalloc(sizeof(*firmware), GFP_KERNEL);
if (!firmware) {
dev_err(device, "%s: kmalloc(struct firmware) failed\n",
__func__);
return ERR_PTR(-ENOMEM);
}
if (fw_get_builtin_firmware(firmware, name)) {
dev_dbg(device, "firmware: using built-in firmware %s\n", name);
return NULL;
}
ret = fw_lookup_and_allocate_buf(name, &fw_cache, &buf);
if (!ret)
fw_priv = fw_create_instance(firmware, name, device,
uevent, nowait);
if (IS_ERR(fw_priv) || ret < 0) {
kfree(firmware);
*firmware_p = NULL;
return ERR_PTR(-ENOMEM);
} else if (fw_priv) {
fw_priv->buf = buf;
firmware->priv = buf;
return fw_priv;
}
check_status:
mutex_lock(&fw_lock);
if (test_bit(FW_STATUS_ABORT, &buf->status)) {
fw_priv = ERR_PTR(-ENOENT);
firmware->priv = buf;
_request_firmware_cleanup(firmware_p);
goto exit;
} else if (test_bit(FW_STATUS_DONE, &buf->status)) {
fw_priv = NULL;
fw_set_page_data(buf, firmware);
goto exit;
}
mutex_unlock(&fw_lock);
wait_for_completion(&buf->completion);
goto check_status;
exit:
mutex_unlock(&fw_lock);
return fw_priv;
}
static int _request_firmware_load(struct firmware_priv *fw_priv, bool uevent,
long timeout)
{
int retval = 0;
struct device *f_dev = &fw_priv->dev;
struct firmware_buf *buf = fw_priv->buf;
struct firmware_cache *fwc = &fw_cache;
int direct_load = 0;
if (fw_get_filesystem_firmware(buf)) {
dev_dbg(f_dev->parent, "firmware: direct-loading"
" firmware %s\n", buf->fw_id);
set_bit(FW_STATUS_DONE, &buf->status);
complete_all(&buf->completion);
direct_load = 1;
goto handle_fw;
}
buf->fmt = PAGE_BUF;
dev_set_uevent_suppress(f_dev, true);
__module_get(THIS_MODULE);
retval = device_add(f_dev);
if (retval) {
dev_err(f_dev, "%s: device_register failed\n", __func__);
goto err_put_dev;
}
retval = device_create_bin_file(f_dev, &firmware_attr_data);
if (retval) {
dev_err(f_dev, "%s: sysfs_create_bin_file failed\n", __func__);
goto err_del_dev;
}
retval = device_create_file(f_dev, &dev_attr_loading);
if (retval) {
dev_err(f_dev, "%s: device_create_file failed\n", __func__);
goto err_del_bin_attr;
}
if (uevent) {
dev_set_uevent_suppress(f_dev, false);
dev_dbg(f_dev, "firmware: requesting %s\n", buf->fw_id);
if (timeout != MAX_SCHEDULE_TIMEOUT)
mod_timer(&fw_priv->timeout,
round_jiffies_up(jiffies + timeout));
kobject_uevent(&fw_priv->dev.kobj, KOBJ_ADD);
}
wait_for_completion(&buf->completion);
del_timer_sync(&fw_priv->timeout);
handle_fw:
mutex_lock(&fw_lock);
if (!buf->size || test_bit(FW_STATUS_ABORT, &buf->status))
retval = -ENOENT;
if (!retval && f_dev->parent)
fw_add_devm_name(f_dev->parent, buf->fw_id);
if (!retval && fwc->state == FW_LOADER_START_CACHE) {
if (fw_cache_piggyback_on_request(buf->fw_id))
kref_get(&buf->ref);
}
fw_set_page_data(buf, fw_priv->fw);
fw_priv->buf = NULL;
mutex_unlock(&fw_lock);
if (direct_load)
goto err_put_dev;
device_remove_file(f_dev, &dev_attr_loading);
err_del_bin_attr:
device_remove_bin_file(f_dev, &firmware_attr_data);
err_del_dev:
device_del(f_dev);
err_put_dev:
put_device(f_dev);
return retval;
}
int
request_firmware(const struct firmware **firmware_p, const char *name,
struct device *device)
{
struct firmware_priv *fw_priv;
int ret;
fw_priv = _request_firmware_prepare(firmware_p, name, device, true,
false);
if (IS_ERR_OR_NULL(fw_priv))
return PTR_RET(fw_priv);
ret = usermodehelper_read_trylock();
if (WARN_ON(ret)) {
dev_err(device, "firmware: %s will not be loaded\n", name);
} else {
ret = _request_firmware_load(fw_priv, true,
firmware_loading_timeout());
usermodehelper_read_unlock();
}
if (ret)
_request_firmware_cleanup(firmware_p);
return ret;
}
void release_firmware(const struct firmware *fw)
{
if (fw) {
if (!fw_is_builtin_firmware(fw))
firmware_free_data(fw);
kfree(fw);
}
}
static void request_firmware_work_func(struct work_struct *work)
{
struct firmware_work *fw_work;
const struct firmware *fw;
struct firmware_priv *fw_priv;
long timeout;
int ret;
fw_work = container_of(work, struct firmware_work, work);
fw_priv = _request_firmware_prepare(&fw, fw_work->name, fw_work->device,
fw_work->uevent, true);
if (IS_ERR_OR_NULL(fw_priv)) {
ret = PTR_RET(fw_priv);
goto out;
}
timeout = usermodehelper_read_lock_wait(firmware_loading_timeout());
if (timeout) {
ret = _request_firmware_load(fw_priv, fw_work->uevent, timeout);
usermodehelper_read_unlock();
} else {
dev_dbg(fw_work->device, "firmware: %s loading timed out\n",
fw_work->name);
ret = -EAGAIN;
}
if (ret)
_request_firmware_cleanup(&fw);
out:
fw_work->cont(fw, fw_work->context);
put_device(fw_work->device);
module_put(fw_work->module);
kfree(fw_work);
}
int
request_firmware_nowait(
struct module *module, bool uevent,
const char *name, struct device *device, gfp_t gfp, void *context,
void (*cont)(const struct firmware *fw, void *context))
{
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
get_device(fw_work->device);
INIT_WORK(&fw_work->work, request_firmware_work_func);
schedule_work(&fw_work->work);
return 0;
}
int cache_firmware(const char *fw_name)
{
int ret;
const struct firmware *fw;
pr_debug("%s: %s\n", __func__, fw_name);
ret = request_firmware(&fw, fw_name, NULL);
if (!ret)
kfree(fw);
pr_debug("%s: %s ret=%d\n", __func__, fw_name, ret);
return ret;
}
int uncache_firmware(const char *fw_name)
{
struct firmware_buf *buf;
struct firmware fw;
pr_debug("%s: %s\n", __func__, fw_name);
if (fw_get_builtin_firmware(&fw, fw_name))
return 0;
buf = fw_lookup_buf(fw_name);
if (buf) {
fw_free_buf(buf);
return 0;
}
return -EINVAL;
}
static struct fw_cache_entry *alloc_fw_cache_entry(const char *name)
{
struct fw_cache_entry *fce;
fce = kzalloc(sizeof(*fce) + strlen(name) + 1, GFP_ATOMIC);
if (!fce)
goto exit;
strcpy(fce->name, name);
exit:
return fce;
}
static int __fw_entry_found(const char *name)
{
struct firmware_cache *fwc = &fw_cache;
struct fw_cache_entry *fce;
list_for_each_entry(fce, &fwc->fw_names, list) {
if (!strcmp(fce->name, name))
return 1;
}
return 0;
}
static int fw_cache_piggyback_on_request(const char *name)
{
struct firmware_cache *fwc = &fw_cache;
struct fw_cache_entry *fce;
int ret = 0;
spin_lock(&fwc->name_lock);
if (__fw_entry_found(name))
goto found;
fce = alloc_fw_cache_entry(name);
if (fce) {
ret = 1;
list_add(&fce->list, &fwc->fw_names);
pr_debug("%s: fw: %s\n", __func__, name);
}
found:
spin_unlock(&fwc->name_lock);
return ret;
}
static void free_fw_cache_entry(struct fw_cache_entry *fce)
{
kfree(fce);
}
static void __async_dev_cache_fw_image(void *fw_entry,
async_cookie_t cookie)
{
struct fw_cache_entry *fce = fw_entry;
struct firmware_cache *fwc = &fw_cache;
int ret;
ret = cache_firmware(fce->name);
if (ret) {
spin_lock(&fwc->name_lock);
list_del(&fce->list);
spin_unlock(&fwc->name_lock);
free_fw_cache_entry(fce);
}
}
static void dev_create_fw_entry(struct device *dev, void *res,
void *data)
{
struct fw_name_devm *fwn = res;
const char *fw_name = fwn->name;
struct list_head *head = data;
struct fw_cache_entry *fce;
fce = alloc_fw_cache_entry(fw_name);
if (fce)
list_add(&fce->list, head);
}
static int devm_name_match(struct device *dev, void *res,
void *match_data)
{
struct fw_name_devm *fwn = res;
return (fwn->magic == (unsigned long)match_data);
}
static void dev_cache_fw_image(struct device *dev, void *data)
{
LIST_HEAD(todo);
struct fw_cache_entry *fce;
struct fw_cache_entry *fce_next;
struct firmware_cache *fwc = &fw_cache;
devres_for_each_res(dev, fw_name_devm_release,
devm_name_match, &fw_cache,
dev_create_fw_entry, &todo);
list_for_each_entry_safe(fce, fce_next, &todo, list) {
list_del(&fce->list);
spin_lock(&fwc->name_lock);
if (!__fw_entry_found(fce->name)) {
list_add(&fce->list, &fwc->fw_names);
} else {
free_fw_cache_entry(fce);
fce = NULL;
}
spin_unlock(&fwc->name_lock);
if (fce)
async_schedule_domain(__async_dev_cache_fw_image,
(void *)fce,
&fw_cache_domain);
}
}
static void __device_uncache_fw_images(void)
{
struct firmware_cache *fwc = &fw_cache;
struct fw_cache_entry *fce;
spin_lock(&fwc->name_lock);
while (!list_empty(&fwc->fw_names)) {
fce = list_entry(fwc->fw_names.next,
struct fw_cache_entry, list);
list_del(&fce->list);
spin_unlock(&fwc->name_lock);
uncache_firmware(fce->name);
free_fw_cache_entry(fce);
spin_lock(&fwc->name_lock);
}
spin_unlock(&fwc->name_lock);
}
static void device_cache_fw_images(void)
{
struct firmware_cache *fwc = &fw_cache;
int old_timeout;
DEFINE_WAIT(wait);
pr_debug("%s\n", __func__);
cancel_delayed_work_sync(&fwc->work);
old_timeout = loading_timeout;
loading_timeout = 10;
mutex_lock(&fw_lock);
fwc->state = FW_LOADER_START_CACHE;
dpm_for_each_dev(NULL, dev_cache_fw_image);
mutex_unlock(&fw_lock);
async_synchronize_full_domain(&fw_cache_domain);
loading_timeout = old_timeout;
}
static void device_uncache_fw_images(void)
{
pr_debug("%s\n", __func__);
__device_uncache_fw_images();
}
static void device_uncache_fw_images_work(struct work_struct *work)
{
device_uncache_fw_images();
}
static void device_uncache_fw_images_delay(unsigned long delay)
{
schedule_delayed_work(&fw_cache.work,
msecs_to_jiffies(delay));
}
static int fw_pm_notify(struct notifier_block *notify_block,
unsigned long mode, void *unused)
{
switch (mode) {
case PM_HIBERNATION_PREPARE:
case PM_SUSPEND_PREPARE:
device_cache_fw_images();
break;
case PM_POST_SUSPEND:
case PM_POST_HIBERNATION:
case PM_POST_RESTORE:
mutex_lock(&fw_lock);
fw_cache.state = FW_LOADER_NO_CACHE;
mutex_unlock(&fw_lock);
device_uncache_fw_images_delay(10 * MSEC_PER_SEC);
break;
}
return 0;
}
static int fw_suspend(void)
{
fw_cache.state = FW_LOADER_NO_CACHE;
return 0;
}
static int fw_cache_piggyback_on_request(const char *name)
{
return 0;
}
static void __init fw_cache_init(void)
{
spin_lock_init(&fw_cache.lock);
INIT_LIST_HEAD(&fw_cache.head);
fw_cache.state = FW_LOADER_NO_CACHE;
#ifdef CONFIG_PM_SLEEP
spin_lock_init(&fw_cache.name_lock);
INIT_LIST_HEAD(&fw_cache.fw_names);
INIT_DELAYED_WORK(&fw_cache.work,
device_uncache_fw_images_work);
fw_cache.pm_notify.notifier_call = fw_pm_notify;
register_pm_notifier(&fw_cache.pm_notify);
register_syscore_ops(&fw_syscore_ops);
#endif
}
static int __init firmware_class_init(void)
{
fw_cache_init();
return class_register(&firmware_class);
}
static void __exit firmware_class_exit(void)
{
#ifdef CONFIG_PM_SLEEP
unregister_syscore_ops(&fw_syscore_ops);
unregister_pm_notifier(&fw_cache.pm_notify);
#endif
class_unregister(&firmware_class);
}
