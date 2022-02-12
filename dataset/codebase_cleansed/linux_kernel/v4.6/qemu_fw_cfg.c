static inline u16 fw_cfg_sel_endianness(u16 key)
{
return fw_cfg_is_mmio ? cpu_to_be16(key) : cpu_to_le16(key);
}
static inline void fw_cfg_read_blob(u16 key,
void *buf, loff_t pos, size_t count)
{
u32 glk = -1U;
acpi_status status;
status = acpi_acquire_global_lock(ACPI_WAIT_FOREVER, &glk);
if (ACPI_FAILURE(status) && status != AE_NOT_CONFIGURED) {
WARN(1, "fw_cfg_read_blob: Failed to lock ACPI!\n");
memset(buf, 0, count);
return;
}
mutex_lock(&fw_cfg_dev_lock);
iowrite16(fw_cfg_sel_endianness(key), fw_cfg_reg_ctrl);
while (pos-- > 0)
ioread8(fw_cfg_reg_data);
ioread8_rep(fw_cfg_reg_data, buf, count);
mutex_unlock(&fw_cfg_dev_lock);
acpi_release_global_lock(glk);
}
static void fw_cfg_io_cleanup(void)
{
if (fw_cfg_is_mmio) {
iounmap(fw_cfg_dev_base);
release_mem_region(fw_cfg_p_base, fw_cfg_p_size);
} else {
ioport_unmap(fw_cfg_dev_base);
release_region(fw_cfg_p_base, fw_cfg_p_size);
}
}
static int fw_cfg_do_platform_probe(struct platform_device *pdev)
{
char sig[FW_CFG_SIG_SIZE];
struct resource *range, *ctrl, *data;
fw_cfg_is_mmio = false;
range = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!range) {
fw_cfg_is_mmio = true;
range = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!range)
return -EINVAL;
}
fw_cfg_p_base = range->start;
fw_cfg_p_size = resource_size(range);
if (fw_cfg_is_mmio) {
if (!request_mem_region(fw_cfg_p_base,
fw_cfg_p_size, "fw_cfg_mem"))
return -EBUSY;
fw_cfg_dev_base = ioremap(fw_cfg_p_base, fw_cfg_p_size);
if (!fw_cfg_dev_base) {
release_mem_region(fw_cfg_p_base, fw_cfg_p_size);
return -EFAULT;
}
} else {
if (!request_region(fw_cfg_p_base,
fw_cfg_p_size, "fw_cfg_io"))
return -EBUSY;
fw_cfg_dev_base = ioport_map(fw_cfg_p_base, fw_cfg_p_size);
if (!fw_cfg_dev_base) {
release_region(fw_cfg_p_base, fw_cfg_p_size);
return -EFAULT;
}
}
ctrl = platform_get_resource_byname(pdev, IORESOURCE_REG, "ctrl");
data = platform_get_resource_byname(pdev, IORESOURCE_REG, "data");
if (ctrl && data) {
fw_cfg_reg_ctrl = fw_cfg_dev_base + ctrl->start;
fw_cfg_reg_data = fw_cfg_dev_base + data->start;
} else {
fw_cfg_reg_ctrl = fw_cfg_dev_base + FW_CFG_CTRL_OFF;
fw_cfg_reg_data = fw_cfg_dev_base + FW_CFG_DATA_OFF;
}
fw_cfg_read_blob(FW_CFG_SIGNATURE, sig, 0, FW_CFG_SIG_SIZE);
if (memcmp(sig, "QEMU", FW_CFG_SIG_SIZE) != 0) {
fw_cfg_io_cleanup();
return -ENODEV;
}
return 0;
}
static ssize_t fw_cfg_showrev(struct kobject *k, struct attribute *a, char *buf)
{
return sprintf(buf, "%u\n", fw_cfg_rev);
}
static inline struct fw_cfg_sysfs_entry *to_entry(struct kobject *kobj)
{
return container_of(kobj, struct fw_cfg_sysfs_entry, kobj);
}
static inline struct fw_cfg_sysfs_attribute *to_attr(struct attribute *attr)
{
return container_of(attr, struct fw_cfg_sysfs_attribute, attr);
}
static inline void fw_cfg_sysfs_cache_enlist(struct fw_cfg_sysfs_entry *entry)
{
spin_lock(&fw_cfg_cache_lock);
list_add_tail(&entry->list, &fw_cfg_entry_cache);
spin_unlock(&fw_cfg_cache_lock);
}
static inline void fw_cfg_sysfs_cache_delist(struct fw_cfg_sysfs_entry *entry)
{
spin_lock(&fw_cfg_cache_lock);
list_del(&entry->list);
spin_unlock(&fw_cfg_cache_lock);
}
static void fw_cfg_sysfs_cache_cleanup(void)
{
struct fw_cfg_sysfs_entry *entry, *next;
list_for_each_entry_safe(entry, next, &fw_cfg_entry_cache, list) {
kobject_put(&entry->kobj);
}
}
static ssize_t fw_cfg_sysfs_show_size(struct fw_cfg_sysfs_entry *e, char *buf)
{
return sprintf(buf, "%u\n", e->f.size);
}
static ssize_t fw_cfg_sysfs_show_key(struct fw_cfg_sysfs_entry *e, char *buf)
{
return sprintf(buf, "%u\n", e->f.select);
}
static ssize_t fw_cfg_sysfs_show_name(struct fw_cfg_sysfs_entry *e, char *buf)
{
return sprintf(buf, "%s\n", e->f.name);
}
static ssize_t fw_cfg_sysfs_attr_show(struct kobject *kobj, struct attribute *a,
char *buf)
{
struct fw_cfg_sysfs_entry *entry = to_entry(kobj);
struct fw_cfg_sysfs_attribute *attr = to_attr(a);
return attr->show(entry, buf);
}
static void fw_cfg_sysfs_release_entry(struct kobject *kobj)
{
struct fw_cfg_sysfs_entry *entry = to_entry(kobj);
fw_cfg_sysfs_cache_delist(entry);
kfree(entry);
}
static ssize_t fw_cfg_sysfs_read_raw(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t count)
{
struct fw_cfg_sysfs_entry *entry = to_entry(kobj);
if (pos > entry->f.size)
return -EINVAL;
if (count > entry->f.size - pos)
count = entry->f.size - pos;
fw_cfg_read_blob(entry->f.select, buf, pos, count);
return count;
}
static int fw_cfg_build_symlink(struct kset *dir,
struct kobject *target, const char *name)
{
int ret;
struct kset *subdir;
struct kobject *ko;
char *name_copy, *p, *tok;
if (!dir || !target || !name || !*name)
return -EINVAL;
name_copy = p = kstrdup(name, GFP_KERNEL);
if (!name_copy)
return -ENOMEM;
while ((tok = strsep(&p, "/")) && *tok) {
if (!p || !*p) {
ret = sysfs_create_link(&dir->kobj, target, tok);
break;
}
ko = kset_find_obj(dir, tok);
if (ko) {
kobject_put(ko);
if (ko->ktype != dir->kobj.ktype) {
ret = -EINVAL;
break;
}
dir = to_kset(ko);
} else {
subdir = kzalloc(sizeof(struct kset), GFP_KERNEL);
if (!subdir) {
ret = -ENOMEM;
break;
}
subdir->kobj.kset = dir;
subdir->kobj.ktype = dir->kobj.ktype;
ret = kobject_set_name(&subdir->kobj, "%s", tok);
if (ret) {
kfree(subdir);
break;
}
ret = kset_register(subdir);
if (ret) {
kfree(subdir);
break;
}
dir = subdir;
}
}
kfree(name_copy);
return ret;
}
static void fw_cfg_kset_unregister_recursive(struct kset *kset)
{
struct kobject *k, *next;
list_for_each_entry_safe(k, next, &kset->list, entry)
if (k->ktype == kset->kobj.ktype)
fw_cfg_kset_unregister_recursive(to_kset(k));
kset_unregister(kset);
}
static int fw_cfg_register_file(const struct fw_cfg_file *f)
{
int err;
struct fw_cfg_sysfs_entry *entry;
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
return -ENOMEM;
memcpy(&entry->f, f, sizeof(struct fw_cfg_file));
err = kobject_init_and_add(&entry->kobj, &fw_cfg_sysfs_entry_ktype,
fw_cfg_sel_ko, "%d", entry->f.select);
if (err)
goto err_register;
err = sysfs_create_bin_file(&entry->kobj, &fw_cfg_sysfs_attr_raw);
if (err)
goto err_add_raw;
fw_cfg_build_symlink(fw_cfg_fname_kset, &entry->kobj, entry->f.name);
fw_cfg_sysfs_cache_enlist(entry);
return 0;
err_add_raw:
kobject_del(&entry->kobj);
err_register:
kfree(entry);
return err;
}
static int fw_cfg_register_dir_entries(void)
{
int ret = 0;
u32 count, i;
struct fw_cfg_file *dir;
size_t dir_size;
fw_cfg_read_blob(FW_CFG_FILE_DIR, &count, 0, sizeof(count));
count = be32_to_cpu(count);
dir_size = count * sizeof(struct fw_cfg_file);
dir = kmalloc(dir_size, GFP_KERNEL);
if (!dir)
return -ENOMEM;
fw_cfg_read_blob(FW_CFG_FILE_DIR, dir, sizeof(count), dir_size);
for (i = 0; i < count; i++) {
dir[i].size = be32_to_cpu(dir[i].size);
dir[i].select = be16_to_cpu(dir[i].select);
ret = fw_cfg_register_file(&dir[i]);
if (ret)
break;
}
kfree(dir);
return ret;
}
static inline void fw_cfg_kobj_cleanup(struct kobject *kobj)
{
kobject_del(kobj);
kobject_put(kobj);
}
static int fw_cfg_sysfs_probe(struct platform_device *pdev)
{
int err;
if (fw_cfg_sel_ko)
return -EBUSY;
err = -ENOMEM;
fw_cfg_sel_ko = kobject_create_and_add("by_key", fw_cfg_top_ko);
if (!fw_cfg_sel_ko)
goto err_sel;
fw_cfg_fname_kset = kset_create_and_add("by_name", NULL, fw_cfg_top_ko);
if (!fw_cfg_fname_kset)
goto err_name;
err = fw_cfg_do_platform_probe(pdev);
if (err)
goto err_probe;
fw_cfg_read_blob(FW_CFG_ID, &fw_cfg_rev, 0, sizeof(fw_cfg_rev));
fw_cfg_rev = le32_to_cpu(fw_cfg_rev);
err = sysfs_create_file(fw_cfg_top_ko, &fw_cfg_rev_attr.attr);
if (err)
goto err_rev;
err = fw_cfg_register_dir_entries();
if (err)
goto err_dir;
pr_debug("fw_cfg: loaded.\n");
return 0;
err_dir:
fw_cfg_sysfs_cache_cleanup();
sysfs_remove_file(fw_cfg_top_ko, &fw_cfg_rev_attr.attr);
err_rev:
fw_cfg_io_cleanup();
err_probe:
fw_cfg_kset_unregister_recursive(fw_cfg_fname_kset);
err_name:
fw_cfg_kobj_cleanup(fw_cfg_sel_ko);
err_sel:
return err;
}
static int fw_cfg_sysfs_remove(struct platform_device *pdev)
{
pr_debug("fw_cfg: unloading.\n");
fw_cfg_sysfs_cache_cleanup();
fw_cfg_kset_unregister_recursive(fw_cfg_fname_kset);
fw_cfg_kobj_cleanup(fw_cfg_sel_ko);
fw_cfg_io_cleanup();
return 0;
}
static int fw_cfg_cmdline_set(const char *arg, const struct kernel_param *kp)
{
struct resource res[3] = {};
char *str;
phys_addr_t base;
resource_size_t size, ctrl_off, data_off;
int processed, consumed = 0;
if (fw_cfg_cmdline_dev) {
platform_device_unregister(fw_cfg_cmdline_dev);
return -EINVAL;
}
size = memparse(arg, &str);
processed = sscanf(str, PH_ADDR_SCAN_FMT,
&base, &consumed,
&ctrl_off, &data_off, &consumed);
if (str[consumed] ||
(processed != 1 && processed != 3))
return -EINVAL;
res[0].start = base;
res[0].end = base + size - 1;
res[0].flags = !strcmp(kp->name, "mmio") ? IORESOURCE_MEM :
IORESOURCE_IO;
if (processed > 1) {
res[1].name = "ctrl";
res[1].start = ctrl_off;
res[1].flags = IORESOURCE_REG;
res[2].name = "data";
res[2].start = data_off;
res[2].flags = IORESOURCE_REG;
}
fw_cfg_cmdline_dev = platform_device_register_simple("fw_cfg",
PLATFORM_DEVID_NONE, res, processed);
if (IS_ERR(fw_cfg_cmdline_dev))
return PTR_ERR(fw_cfg_cmdline_dev);
return 0;
}
static int fw_cfg_cmdline_get(char *buf, const struct kernel_param *kp)
{
if (!fw_cfg_cmdline_dev ||
(!strcmp(kp->name, "mmio") ^
(fw_cfg_cmdline_dev->resource[0].flags == IORESOURCE_MEM)))
return 0;
switch (fw_cfg_cmdline_dev->num_resources) {
case 1:
return snprintf(buf, PAGE_SIZE, PH_ADDR_PR_1_FMT,
resource_size(&fw_cfg_cmdline_dev->resource[0]),
fw_cfg_cmdline_dev->resource[0].start);
case 3:
return snprintf(buf, PAGE_SIZE, PH_ADDR_PR_3_FMT,
resource_size(&fw_cfg_cmdline_dev->resource[0]),
fw_cfg_cmdline_dev->resource[0].start,
fw_cfg_cmdline_dev->resource[1].start,
fw_cfg_cmdline_dev->resource[2].start);
}
WARN(1, "Unexpected number of resources: %d\n",
fw_cfg_cmdline_dev->num_resources);
return 0;
}
static int __init fw_cfg_sysfs_init(void)
{
int ret;
fw_cfg_top_ko = kobject_create_and_add("qemu_fw_cfg", firmware_kobj);
if (!fw_cfg_top_ko)
return -ENOMEM;
ret = platform_driver_register(&fw_cfg_sysfs_driver);
if (ret)
fw_cfg_kobj_cleanup(fw_cfg_top_ko);
return ret;
}
static void __exit fw_cfg_sysfs_exit(void)
{
platform_driver_unregister(&fw_cfg_sysfs_driver);
#ifdef CONFIG_FW_CFG_SYSFS_CMDLINE
platform_device_unregister(fw_cfg_cmdline_dev);
#endif
fw_cfg_kobj_cleanup(fw_cfg_top_ko);
}
