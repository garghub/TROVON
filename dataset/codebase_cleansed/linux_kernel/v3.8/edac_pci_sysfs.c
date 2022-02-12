int edac_pci_get_check_errors(void)
{
return check_pci_errors;
}
static int edac_pci_get_log_pe(void)
{
return edac_pci_log_pe;
}
static int edac_pci_get_log_npe(void)
{
return edac_pci_log_npe;
}
static int edac_pci_get_panic_on_pe(void)
{
return edac_pci_panic_on_pe;
}
int edac_pci_get_poll_msec(void)
{
return edac_pci_poll_msec;
}
static ssize_t instance_pe_count_show(struct edac_pci_ctl_info *pci, char *data)
{
return sprintf(data, "%u\n", atomic_read(&pci->counters.pe_count));
}
static ssize_t instance_npe_count_show(struct edac_pci_ctl_info *pci,
char *data)
{
return sprintf(data, "%u\n", atomic_read(&pci->counters.npe_count));
}
static void edac_pci_instance_release(struct kobject *kobj)
{
struct edac_pci_ctl_info *pci;
edac_dbg(0, "\n");
pci = to_instance(kobj);
kobject_put(edac_pci_top_main_kobj);
kfree(pci);
}
static ssize_t edac_pci_instance_show(struct kobject *kobj,
struct attribute *attr, char *buffer)
{
struct edac_pci_ctl_info *pci = to_instance(kobj);
struct instance_attribute *instance_attr = to_instance_attr(attr);
if (instance_attr->show)
return instance_attr->show(pci, buffer);
return -EIO;
}
static ssize_t edac_pci_instance_store(struct kobject *kobj,
struct attribute *attr,
const char *buffer, size_t count)
{
struct edac_pci_ctl_info *pci = to_instance(kobj);
struct instance_attribute *instance_attr = to_instance_attr(attr);
if (instance_attr->store)
return instance_attr->store(pci, buffer, count);
return -EIO;
}
static int edac_pci_create_instance_kobj(struct edac_pci_ctl_info *pci, int idx)
{
struct kobject *main_kobj;
int err;
edac_dbg(0, "\n");
main_kobj = kobject_get(edac_pci_top_main_kobj);
if (!main_kobj) {
err = -ENODEV;
goto error_out;
}
err = kobject_init_and_add(&pci->kobj, &ktype_pci_instance,
edac_pci_top_main_kobj, "pci%d", idx);
if (err != 0) {
edac_dbg(2, "failed to register instance pci%d\n", idx);
kobject_put(edac_pci_top_main_kobj);
goto error_out;
}
kobject_uevent(&pci->kobj, KOBJ_ADD);
edac_dbg(1, "Register instance 'pci%d' kobject\n", idx);
return 0;
error_out:
return err;
}
static void edac_pci_unregister_sysfs_instance_kobj(
struct edac_pci_ctl_info *pci)
{
edac_dbg(0, "\n");
kobject_put(&pci->kobj);
}
static ssize_t edac_pci_int_show(void *ptr, char *buffer)
{
int *value = ptr;
return sprintf(buffer, "%d\n", *value);
}
static ssize_t edac_pci_int_store(void *ptr, const char *buffer, size_t count)
{
int *value = ptr;
if (isdigit(*buffer))
*value = simple_strtoul(buffer, NULL, 0);
return count;
}
static ssize_t edac_pci_dev_show(struct kobject *kobj, struct attribute *attr,
char *buffer)
{
struct edac_pci_dev_attribute *edac_pci_dev;
edac_pci_dev = (struct edac_pci_dev_attribute *)attr;
if (edac_pci_dev->show)
return edac_pci_dev->show(edac_pci_dev->value, buffer);
return -EIO;
}
static ssize_t edac_pci_dev_store(struct kobject *kobj,
struct attribute *attr, const char *buffer,
size_t count)
{
struct edac_pci_dev_attribute *edac_pci_dev;
edac_pci_dev = (struct edac_pci_dev_attribute *)attr;
if (edac_pci_dev->store)
return edac_pci_dev->store(edac_pci_dev->value, buffer, count);
return -EIO;
}
static void edac_pci_release_main_kobj(struct kobject *kobj)
{
edac_dbg(0, "here to module_put(THIS_MODULE)\n");
kfree(kobj);
module_put(THIS_MODULE);
}
static int edac_pci_main_kobj_setup(void)
{
int err;
struct bus_type *edac_subsys;
edac_dbg(0, "\n");
if (atomic_inc_return(&edac_pci_sysfs_refcount) != 1)
return 0;
edac_subsys = edac_get_sysfs_subsys();
if (edac_subsys == NULL) {
edac_dbg(1, "no edac_subsys\n");
err = -ENODEV;
goto decrement_count_fail;
}
if (!try_module_get(THIS_MODULE)) {
edac_dbg(1, "try_module_get() failed\n");
err = -ENODEV;
goto mod_get_fail;
}
edac_pci_top_main_kobj = kzalloc(sizeof(struct kobject), GFP_KERNEL);
if (!edac_pci_top_main_kobj) {
edac_dbg(1, "Failed to allocate\n");
err = -ENOMEM;
goto kzalloc_fail;
}
err = kobject_init_and_add(edac_pci_top_main_kobj,
&ktype_edac_pci_main_kobj,
&edac_subsys->dev_root->kobj, "pci");
if (err) {
edac_dbg(1, "Failed to register '.../edac/pci'\n");
goto kobject_init_and_add_fail;
}
kobject_uevent(edac_pci_top_main_kobj, KOBJ_ADD);
edac_dbg(1, "Registered '.../edac/pci' kobject\n");
return 0;
kobject_init_and_add_fail:
kfree(edac_pci_top_main_kobj);
kzalloc_fail:
module_put(THIS_MODULE);
mod_get_fail:
edac_put_sysfs_subsys();
decrement_count_fail:
atomic_dec(&edac_pci_sysfs_refcount);
return err;
}
static void edac_pci_main_kobj_teardown(void)
{
edac_dbg(0, "\n");
if (atomic_dec_return(&edac_pci_sysfs_refcount) == 0) {
edac_dbg(0, "called kobject_put on main kobj\n");
kobject_put(edac_pci_top_main_kobj);
}
edac_put_sysfs_subsys();
}
int edac_pci_create_sysfs(struct edac_pci_ctl_info *pci)
{
int err;
struct kobject *edac_kobj = &pci->kobj;
edac_dbg(0, "idx=%d\n", pci->pci_idx);
err = edac_pci_main_kobj_setup();
if (err)
return err;
err = edac_pci_create_instance_kobj(pci, pci->pci_idx);
if (err)
goto unregister_cleanup;
err = sysfs_create_link(edac_kobj, &pci->dev->kobj, EDAC_PCI_SYMLINK);
if (err) {
edac_dbg(0, "sysfs_create_link() returned err= %d\n", err);
goto symlink_fail;
}
return 0;
symlink_fail:
edac_pci_unregister_sysfs_instance_kobj(pci);
unregister_cleanup:
edac_pci_main_kobj_teardown();
return err;
}
void edac_pci_remove_sysfs(struct edac_pci_ctl_info *pci)
{
edac_dbg(0, "index=%d\n", pci->pci_idx);
sysfs_remove_link(&pci->kobj, EDAC_PCI_SYMLINK);
edac_pci_unregister_sysfs_instance_kobj(pci);
edac_dbg(0, "calling edac_pci_main_kobj_teardown()\n");
edac_pci_main_kobj_teardown();
}
static u16 get_pci_parity_status(struct pci_dev *dev, int secondary)
{
int where;
u16 status;
where = secondary ? PCI_SEC_STATUS : PCI_STATUS;
pci_read_config_word(dev, where, &status);
if (status == 0xFFFF) {
u32 sanity;
pci_read_config_dword(dev, 0, &sanity);
if (sanity == 0xFFFFFFFF)
return 0;
}
status &= PCI_STATUS_DETECTED_PARITY | PCI_STATUS_SIG_SYSTEM_ERROR |
PCI_STATUS_PARITY;
if (status)
pci_write_config_word(dev, where, status);
return status;
}
static void edac_pci_dev_parity_clear(struct pci_dev *dev)
{
u8 header_type;
get_pci_parity_status(dev, 0);
pci_read_config_byte(dev, PCI_HEADER_TYPE, &header_type);
if ((header_type & 0x7F) == PCI_HEADER_TYPE_BRIDGE)
get_pci_parity_status(dev, 1);
}
static void edac_pci_dev_parity_test(struct pci_dev *dev)
{
unsigned long flags;
u16 status;
u8 header_type;
local_irq_save(flags);
status = get_pci_parity_status(dev, 0);
pci_read_config_byte(dev, PCI_HEADER_TYPE, &header_type);
local_irq_restore(flags);
edac_dbg(4, "PCI STATUS= 0x%04x %s\n", status, dev_name(&dev->dev));
if (status && !dev->broken_parity_status) {
if (status & (PCI_STATUS_SIG_SYSTEM_ERROR)) {
edac_printk(KERN_CRIT, EDAC_PCI,
"Signaled System Error on %s\n",
pci_name(dev));
atomic_inc(&pci_nonparity_count);
}
if (status & (PCI_STATUS_PARITY)) {
edac_printk(KERN_CRIT, EDAC_PCI,
"Master Data Parity Error on %s\n",
pci_name(dev));
atomic_inc(&pci_parity_count);
}
if (status & (PCI_STATUS_DETECTED_PARITY)) {
edac_printk(KERN_CRIT, EDAC_PCI,
"Detected Parity Error on %s\n",
pci_name(dev));
atomic_inc(&pci_parity_count);
}
}
edac_dbg(4, "PCI HEADER TYPE= 0x%02x %s\n",
header_type, dev_name(&dev->dev));
if ((header_type & 0x7F) == PCI_HEADER_TYPE_BRIDGE) {
status = get_pci_parity_status(dev, 1);
edac_dbg(4, "PCI SEC_STATUS= 0x%04x %s\n",
status, dev_name(&dev->dev));
if (status && !dev->broken_parity_status) {
if (status & (PCI_STATUS_SIG_SYSTEM_ERROR)) {
edac_printk(KERN_CRIT, EDAC_PCI, "Bridge "
"Signaled System Error on %s\n",
pci_name(dev));
atomic_inc(&pci_nonparity_count);
}
if (status & (PCI_STATUS_PARITY)) {
edac_printk(KERN_CRIT, EDAC_PCI, "Bridge "
"Master Data Parity Error on "
"%s\n", pci_name(dev));
atomic_inc(&pci_parity_count);
}
if (status & (PCI_STATUS_DETECTED_PARITY)) {
edac_printk(KERN_CRIT, EDAC_PCI, "Bridge "
"Detected Parity Error on %s\n",
pci_name(dev));
atomic_inc(&pci_parity_count);
}
}
}
}
static inline void edac_pci_dev_parity_iterator(pci_parity_check_fn_t fn)
{
struct pci_dev *dev = NULL;
for_each_pci_dev(dev)
fn(dev);
}
void edac_pci_do_parity_check(void)
{
int before_count;
edac_dbg(3, "\n");
if (!check_pci_errors)
return;
before_count = atomic_read(&pci_parity_count);
edac_pci_dev_parity_iterator(edac_pci_dev_parity_test);
if (edac_pci_get_panic_on_pe()) {
if (before_count != atomic_read(&pci_parity_count))
panic("EDAC: PCI Parity Error");
}
}
void edac_pci_clear_parity_errors(void)
{
edac_pci_dev_parity_iterator(edac_pci_dev_parity_clear);
}
void edac_pci_handle_pe(struct edac_pci_ctl_info *pci, const char *msg)
{
atomic_inc(&pci->counters.pe_count);
if (edac_pci_get_log_pe())
edac_pci_printk(pci, KERN_WARNING,
"Parity Error ctl: %s %d: %s\n",
pci->ctl_name, pci->pci_idx, msg);
edac_pci_do_parity_check();
}
void edac_pci_handle_npe(struct edac_pci_ctl_info *pci, const char *msg)
{
atomic_inc(&pci->counters.npe_count);
if (edac_pci_get_log_npe())
edac_pci_printk(pci, KERN_WARNING,
"Non-Parity Error ctl: %s %d: %s\n",
pci->ctl_name, pci->pci_idx, msg);
edac_pci_do_parity_check();
}
