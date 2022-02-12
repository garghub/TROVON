static size_t find_smbios_instance_string(struct pci_dev *pdev, char *buf,
enum smbios_attr_enum attribute)
{
const struct dmi_device *dmi;
struct dmi_dev_onboard *donboard;
int bus;
int devfn;
bus = pdev->bus->number;
devfn = pdev->devfn;
dmi = NULL;
while ((dmi = dmi_find_device(DMI_DEV_TYPE_DEV_ONBOARD,
NULL, dmi)) != NULL) {
donboard = dmi->device_data;
if (donboard && donboard->bus == bus &&
donboard->devfn == devfn) {
if (buf) {
if (attribute == SMBIOS_ATTR_INSTANCE_SHOW)
return scnprintf(buf, PAGE_SIZE,
"%d\n",
donboard->instance);
else if (attribute == SMBIOS_ATTR_LABEL_SHOW)
return scnprintf(buf, PAGE_SIZE,
"%s\n",
dmi->name);
}
return strlen(dmi->name);
}
}
return 0;
}
static umode_t smbios_instance_string_exist(struct kobject *kobj,
struct attribute *attr, int n)
{
struct device *dev;
struct pci_dev *pdev;
dev = container_of(kobj, struct device, kobj);
pdev = to_pci_dev(dev);
return find_smbios_instance_string(pdev, NULL, SMBIOS_ATTR_NONE) ?
S_IRUGO : 0;
}
static ssize_t smbioslabel_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct pci_dev *pdev;
pdev = to_pci_dev(dev);
return find_smbios_instance_string(pdev, buf,
SMBIOS_ATTR_LABEL_SHOW);
}
static ssize_t smbiosinstance_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct pci_dev *pdev;
pdev = to_pci_dev(dev);
return find_smbios_instance_string(pdev, buf,
SMBIOS_ATTR_INSTANCE_SHOW);
}
static int pci_create_smbiosname_file(struct pci_dev *pdev)
{
return sysfs_create_group(&pdev->dev.kobj, &smbios_attr_group);
}
static void pci_remove_smbiosname_file(struct pci_dev *pdev)
{
sysfs_remove_group(&pdev->dev.kobj, &smbios_attr_group);
}
static inline int pci_create_smbiosname_file(struct pci_dev *pdev)
{
return -1;
}
static inline void pci_remove_smbiosname_file(struct pci_dev *pdev)
{
}
static void dsm_label_utf16s_to_utf8s(union acpi_object *obj, char *buf)
{
int len;
len = utf16s_to_utf8s((const wchar_t *)obj->string.pointer,
obj->string.length,
UTF16_LITTLE_ENDIAN,
buf, PAGE_SIZE);
buf[len] = '\n';
}
static int dsm_get_label(struct device *dev, char *buf,
enum acpi_attr_enum attr)
{
acpi_handle handle;
union acpi_object *obj, *tmp;
int len = -1;
handle = ACPI_HANDLE(dev);
if (!handle)
return -1;
obj = acpi_evaluate_dsm(handle, device_label_dsm_uuid, 0x2,
DEVICE_LABEL_DSM, NULL);
if (!obj)
return -1;
tmp = obj->package.elements;
if (obj->type == ACPI_TYPE_PACKAGE && obj->package.count == 2 &&
tmp[0].type == ACPI_TYPE_INTEGER &&
tmp[1].type == ACPI_TYPE_STRING) {
if (attr == ACPI_ATTR_INDEX_SHOW)
scnprintf(buf, PAGE_SIZE, "%llu\n", tmp->integer.value);
else if (attr == ACPI_ATTR_LABEL_SHOW)
dsm_label_utf16s_to_utf8s(tmp + 1, buf);
len = strlen(buf) > 0 ? strlen(buf) : -1;
}
ACPI_FREE(obj);
return len;
}
static bool device_has_dsm(struct device *dev)
{
acpi_handle handle;
handle = ACPI_HANDLE(dev);
if (!handle)
return false;
return !!acpi_check_dsm(handle, device_label_dsm_uuid, 0x2,
1 << DEVICE_LABEL_DSM);
}
static umode_t acpi_index_string_exist(struct kobject *kobj,
struct attribute *attr, int n)
{
struct device *dev;
dev = container_of(kobj, struct device, kobj);
if (device_has_dsm(dev))
return S_IRUGO;
return 0;
}
static ssize_t acpilabel_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return dsm_get_label(dev, buf, ACPI_ATTR_LABEL_SHOW);
}
static ssize_t acpiindex_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return dsm_get_label(dev, buf, ACPI_ATTR_INDEX_SHOW);
}
static int pci_create_acpi_index_label_files(struct pci_dev *pdev)
{
return sysfs_create_group(&pdev->dev.kobj, &acpi_attr_group);
}
static int pci_remove_acpi_index_label_files(struct pci_dev *pdev)
{
sysfs_remove_group(&pdev->dev.kobj, &acpi_attr_group);
return 0;
}
static inline int pci_create_acpi_index_label_files(struct pci_dev *pdev)
{
return -1;
}
static inline int pci_remove_acpi_index_label_files(struct pci_dev *pdev)
{
return -1;
}
static inline bool device_has_dsm(struct device *dev)
{
return false;
}
void pci_create_firmware_label_files(struct pci_dev *pdev)
{
if (device_has_dsm(&pdev->dev))
pci_create_acpi_index_label_files(pdev);
else
pci_create_smbiosname_file(pdev);
}
void pci_remove_firmware_label_files(struct pci_dev *pdev)
{
if (device_has_dsm(&pdev->dev))
pci_remove_acpi_index_label_files(pdev);
else
pci_remove_smbiosname_file(pdev);
}
