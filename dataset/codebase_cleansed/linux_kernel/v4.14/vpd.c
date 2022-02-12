static ssize_t vpd_attrib_read(struct file *filp, struct kobject *kobp,
struct bin_attribute *bin_attr, char *buf,
loff_t pos, size_t count)
{
struct vpd_attrib_info *info = bin_attr->private;
return memory_read_from_buffer(buf, count, &pos, info->value,
info->bin_attr.size);
}
static int vpd_section_check_key_name(const u8 *key, s32 key_len)
{
int c;
while (key_len-- > 0) {
c = *key++;
if (!isalnum(c) && c != '_')
return VPD_FAIL;
}
return VPD_OK;
}
static int vpd_section_attrib_add(const u8 *key, s32 key_len,
const u8 *value, s32 value_len,
void *arg)
{
int ret;
struct vpd_section *sec = arg;
struct vpd_attrib_info *info;
if (vpd_section_check_key_name(key, key_len) != VPD_OK)
return VPD_OK;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->key = kstrndup(key, key_len, GFP_KERNEL);
if (!info->key) {
ret = -ENOMEM;
goto free_info;
}
sysfs_bin_attr_init(&info->bin_attr);
info->bin_attr.attr.name = info->key;
info->bin_attr.attr.mode = 0444;
info->bin_attr.size = value_len;
info->bin_attr.read = vpd_attrib_read;
info->bin_attr.private = info;
info->value = value;
INIT_LIST_HEAD(&info->list);
ret = sysfs_create_bin_file(sec->kobj, &info->bin_attr);
if (ret)
goto free_info_key;
list_add_tail(&info->list, &sec->attribs);
return 0;
free_info_key:
kfree(info->key);
free_info:
kfree(info);
return ret;
}
static void vpd_section_attrib_destroy(struct vpd_section *sec)
{
struct vpd_attrib_info *info;
struct vpd_attrib_info *temp;
list_for_each_entry_safe(info, temp, &sec->attribs, list) {
sysfs_remove_bin_file(sec->kobj, &info->bin_attr);
kfree(info->key);
kfree(info);
}
}
static ssize_t vpd_section_read(struct file *filp, struct kobject *kobp,
struct bin_attribute *bin_attr, char *buf,
loff_t pos, size_t count)
{
struct vpd_section *sec = bin_attr->private;
return memory_read_from_buffer(buf, count, &pos, sec->baseaddr,
sec->bin_attr.size);
}
static int vpd_section_create_attribs(struct vpd_section *sec)
{
s32 consumed;
int ret;
consumed = 0;
do {
ret = vpd_decode_string(sec->bin_attr.size, sec->baseaddr,
&consumed, vpd_section_attrib_add, sec);
} while (ret == VPD_OK);
return 0;
}
static int vpd_section_init(const char *name, struct vpd_section *sec,
phys_addr_t physaddr, size_t size)
{
int err;
sec->baseaddr = memremap(physaddr, size, MEMREMAP_WB);
if (!sec->baseaddr)
return -ENOMEM;
sec->name = name;
sec->raw_name = kasprintf(GFP_KERNEL, "%s_raw", name);
if (!sec->raw_name) {
err = -ENOMEM;
goto err_memunmap;
}
sysfs_bin_attr_init(&sec->bin_attr);
sec->bin_attr.attr.name = sec->raw_name;
sec->bin_attr.attr.mode = 0444;
sec->bin_attr.size = size;
sec->bin_attr.read = vpd_section_read;
sec->bin_attr.private = sec;
err = sysfs_create_bin_file(vpd_kobj, &sec->bin_attr);
if (err)
goto err_free_raw_name;
sec->kobj = kobject_create_and_add(name, vpd_kobj);
if (!sec->kobj) {
err = -EINVAL;
goto err_sysfs_remove;
}
INIT_LIST_HEAD(&sec->attribs);
vpd_section_create_attribs(sec);
sec->enabled = true;
return 0;
err_sysfs_remove:
sysfs_remove_bin_file(vpd_kobj, &sec->bin_attr);
err_free_raw_name:
kfree(sec->raw_name);
err_memunmap:
memunmap(sec->baseaddr);
return err;
}
static int vpd_section_destroy(struct vpd_section *sec)
{
if (sec->enabled) {
vpd_section_attrib_destroy(sec);
kobject_put(sec->kobj);
sysfs_remove_bin_file(vpd_kobj, &sec->bin_attr);
kfree(sec->raw_name);
memunmap(sec->baseaddr);
}
return 0;
}
static int vpd_sections_init(phys_addr_t physaddr)
{
struct vpd_cbmem __iomem *temp;
struct vpd_cbmem header;
int ret = 0;
temp = memremap(physaddr, sizeof(struct vpd_cbmem), MEMREMAP_WB);
if (!temp)
return -ENOMEM;
memcpy_fromio(&header, temp, sizeof(struct vpd_cbmem));
memunmap(temp);
if (header.magic != VPD_CBMEM_MAGIC)
return -ENODEV;
if (header.ro_size) {
ret = vpd_section_init("ro", &ro_vpd,
physaddr + sizeof(struct vpd_cbmem),
header.ro_size);
if (ret)
return ret;
}
if (header.rw_size) {
ret = vpd_section_init("rw", &rw_vpd,
physaddr + sizeof(struct vpd_cbmem) +
header.ro_size, header.rw_size);
if (ret)
return ret;
}
return 0;
}
static int vpd_probe(struct platform_device *pdev)
{
int ret;
struct lb_cbmem_ref entry;
ret = coreboot_table_find(CB_TAG_VPD, &entry, sizeof(entry));
if (ret)
return ret;
return vpd_sections_init(entry.cbmem_addr);
}
static int __init vpd_platform_init(void)
{
struct platform_device *pdev;
pdev = platform_device_register_simple("vpd", -1, NULL, 0);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
vpd_kobj = kobject_create_and_add("vpd", firmware_kobj);
if (!vpd_kobj)
return -ENOMEM;
platform_driver_register(&vpd_driver);
return 0;
}
static void __exit vpd_platform_exit(void)
{
vpd_section_destroy(&ro_vpd);
vpd_section_destroy(&rw_vpd);
kobject_put(vpd_kobj);
}
