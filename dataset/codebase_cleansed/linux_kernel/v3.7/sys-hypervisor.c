static ssize_t type_show(struct hyp_sysfs_attr *attr, char *buffer)
{
return sprintf(buffer, "xen\n");
}
static int __init xen_sysfs_type_init(void)
{
return sysfs_create_file(hypervisor_kobj, &type_attr.attr);
}
static void xen_sysfs_type_destroy(void)
{
sysfs_remove_file(hypervisor_kobj, &type_attr.attr);
}
static ssize_t major_show(struct hyp_sysfs_attr *attr, char *buffer)
{
int version = HYPERVISOR_xen_version(XENVER_version, NULL);
if (version)
return sprintf(buffer, "%d\n", version >> 16);
return -ENODEV;
}
static ssize_t minor_show(struct hyp_sysfs_attr *attr, char *buffer)
{
int version = HYPERVISOR_xen_version(XENVER_version, NULL);
if (version)
return sprintf(buffer, "%d\n", version & 0xff);
return -ENODEV;
}
static ssize_t extra_show(struct hyp_sysfs_attr *attr, char *buffer)
{
int ret = -ENOMEM;
char *extra;
extra = kmalloc(XEN_EXTRAVERSION_LEN, GFP_KERNEL);
if (extra) {
ret = HYPERVISOR_xen_version(XENVER_extraversion, extra);
if (!ret)
ret = sprintf(buffer, "%s\n", extra);
kfree(extra);
}
return ret;
}
static int __init xen_sysfs_version_init(void)
{
return sysfs_create_group(hypervisor_kobj, &version_group);
}
static void xen_sysfs_version_destroy(void)
{
sysfs_remove_group(hypervisor_kobj, &version_group);
}
static ssize_t uuid_show_fallback(struct hyp_sysfs_attr *attr, char *buffer)
{
char *vm, *val;
int ret;
extern int xenstored_ready;
if (!xenstored_ready)
return -EBUSY;
vm = xenbus_read(XBT_NIL, "vm", "", NULL);
if (IS_ERR(vm))
return PTR_ERR(vm);
val = xenbus_read(XBT_NIL, vm, "uuid", NULL);
kfree(vm);
if (IS_ERR(val))
return PTR_ERR(val);
ret = sprintf(buffer, "%s\n", val);
kfree(val);
return ret;
}
static ssize_t uuid_show(struct hyp_sysfs_attr *attr, char *buffer)
{
xen_domain_handle_t uuid;
int ret;
ret = HYPERVISOR_xen_version(XENVER_guest_handle, uuid);
if (ret)
return uuid_show_fallback(attr, buffer);
ret = sprintf(buffer, "%pU\n", uuid);
return ret;
}
static int __init xen_sysfs_uuid_init(void)
{
return sysfs_create_file(hypervisor_kobj, &uuid_attr.attr);
}
static void xen_sysfs_uuid_destroy(void)
{
sysfs_remove_file(hypervisor_kobj, &uuid_attr.attr);
}
static ssize_t compiler_show(struct hyp_sysfs_attr *attr, char *buffer)
{
int ret = -ENOMEM;
struct xen_compile_info *info;
info = kmalloc(sizeof(struct xen_compile_info), GFP_KERNEL);
if (info) {
ret = HYPERVISOR_xen_version(XENVER_compile_info, info);
if (!ret)
ret = sprintf(buffer, "%s\n", info->compiler);
kfree(info);
}
return ret;
}
static ssize_t compiled_by_show(struct hyp_sysfs_attr *attr, char *buffer)
{
int ret = -ENOMEM;
struct xen_compile_info *info;
info = kmalloc(sizeof(struct xen_compile_info), GFP_KERNEL);
if (info) {
ret = HYPERVISOR_xen_version(XENVER_compile_info, info);
if (!ret)
ret = sprintf(buffer, "%s\n", info->compile_by);
kfree(info);
}
return ret;
}
static ssize_t compile_date_show(struct hyp_sysfs_attr *attr, char *buffer)
{
int ret = -ENOMEM;
struct xen_compile_info *info;
info = kmalloc(sizeof(struct xen_compile_info), GFP_KERNEL);
if (info) {
ret = HYPERVISOR_xen_version(XENVER_compile_info, info);
if (!ret)
ret = sprintf(buffer, "%s\n", info->compile_date);
kfree(info);
}
return ret;
}
static int __init xen_compilation_init(void)
{
return sysfs_create_group(hypervisor_kobj, &xen_compilation_group);
}
static void xen_compilation_destroy(void)
{
sysfs_remove_group(hypervisor_kobj, &xen_compilation_group);
}
static ssize_t capabilities_show(struct hyp_sysfs_attr *attr, char *buffer)
{
int ret = -ENOMEM;
char *caps;
caps = kmalloc(XEN_CAPABILITIES_INFO_LEN, GFP_KERNEL);
if (caps) {
ret = HYPERVISOR_xen_version(XENVER_capabilities, caps);
if (!ret)
ret = sprintf(buffer, "%s\n", caps);
kfree(caps);
}
return ret;
}
static ssize_t changeset_show(struct hyp_sysfs_attr *attr, char *buffer)
{
int ret = -ENOMEM;
char *cset;
cset = kmalloc(XEN_CHANGESET_INFO_LEN, GFP_KERNEL);
if (cset) {
ret = HYPERVISOR_xen_version(XENVER_changeset, cset);
if (!ret)
ret = sprintf(buffer, "%s\n", cset);
kfree(cset);
}
return ret;
}
static ssize_t virtual_start_show(struct hyp_sysfs_attr *attr, char *buffer)
{
int ret = -ENOMEM;
struct xen_platform_parameters *parms;
parms = kmalloc(sizeof(struct xen_platform_parameters), GFP_KERNEL);
if (parms) {
ret = HYPERVISOR_xen_version(XENVER_platform_parameters,
parms);
if (!ret)
ret = sprintf(buffer, "%"PRI_xen_ulong"\n",
parms->virt_start);
kfree(parms);
}
return ret;
}
static ssize_t pagesize_show(struct hyp_sysfs_attr *attr, char *buffer)
{
int ret;
ret = HYPERVISOR_xen_version(XENVER_pagesize, NULL);
if (ret > 0)
ret = sprintf(buffer, "%x\n", ret);
return ret;
}
static ssize_t xen_feature_show(int index, char *buffer)
{
ssize_t ret;
struct xen_feature_info info;
info.submap_idx = index;
ret = HYPERVISOR_xen_version(XENVER_get_features, &info);
if (!ret)
ret = sprintf(buffer, "%08x", info.submap);
return ret;
}
static ssize_t features_show(struct hyp_sysfs_attr *attr, char *buffer)
{
ssize_t len;
int i;
len = 0;
for (i = XENFEAT_NR_SUBMAPS-1; i >= 0; i--) {
int ret = xen_feature_show(i, buffer + len);
if (ret < 0) {
if (len == 0)
len = ret;
break;
}
len += ret;
}
if (len > 0)
buffer[len++] = '\n';
return len;
}
static int __init xen_properties_init(void)
{
return sysfs_create_group(hypervisor_kobj, &xen_properties_group);
}
static void xen_properties_destroy(void)
{
sysfs_remove_group(hypervisor_kobj, &xen_properties_group);
}
static int __init hyper_sysfs_init(void)
{
int ret;
if (!xen_domain())
return -ENODEV;
ret = xen_sysfs_type_init();
if (ret)
goto out;
ret = xen_sysfs_version_init();
if (ret)
goto version_out;
ret = xen_compilation_init();
if (ret)
goto comp_out;
ret = xen_sysfs_uuid_init();
if (ret)
goto uuid_out;
ret = xen_properties_init();
if (ret)
goto prop_out;
goto out;
prop_out:
xen_sysfs_uuid_destroy();
uuid_out:
xen_compilation_destroy();
comp_out:
xen_sysfs_version_destroy();
version_out:
xen_sysfs_type_destroy();
out:
return ret;
}
static void __exit hyper_sysfs_exit(void)
{
xen_properties_destroy();
xen_compilation_destroy();
xen_sysfs_uuid_destroy();
xen_sysfs_version_destroy();
xen_sysfs_type_destroy();
}
static ssize_t hyp_sysfs_show(struct kobject *kobj,
struct attribute *attr,
char *buffer)
{
struct hyp_sysfs_attr *hyp_attr;
hyp_attr = container_of(attr, struct hyp_sysfs_attr, attr);
if (hyp_attr->show)
return hyp_attr->show(hyp_attr, buffer);
return 0;
}
static ssize_t hyp_sysfs_store(struct kobject *kobj,
struct attribute *attr,
const char *buffer,
size_t len)
{
struct hyp_sysfs_attr *hyp_attr;
hyp_attr = container_of(attr, struct hyp_sysfs_attr, attr);
if (hyp_attr->store)
return hyp_attr->store(hyp_attr, buffer, len);
return 0;
}
static int __init hypervisor_subsys_init(void)
{
if (!xen_domain())
return -ENODEV;
hypervisor_kobj->ktype = &hyp_sysfs_kobj_type;
return 0;
}
