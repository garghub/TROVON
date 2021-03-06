static inline const char *str_supported(int is_supported) { return ""; }
static void tpacpi_log_usertask(const char * const what)
{
printk(KERN_DEBUG pr_fmt("%s: access by process with PID %d\n"),
what, task_tgid_vnr(current));
}
static unsigned long __init tpacpi_check_quirks(
const struct tpacpi_quirk *qlist,
unsigned int qlist_size)
{
while (qlist_size) {
if ((qlist->vendor == thinkpad_id.vendor ||
qlist->vendor == TPACPI_MATCH_ANY) &&
(qlist->bios == thinkpad_id.bios_model ||
qlist->bios == TPACPI_MATCH_ANY) &&
(qlist->ec == thinkpad_id.ec_model ||
qlist->ec == TPACPI_MATCH_ANY))
return qlist->quirks;
qlist_size--;
qlist++;
}
return 0;
}
static inline bool __pure __init tpacpi_is_lenovo(void)
{
return thinkpad_id.vendor == PCI_VENDOR_ID_LENOVO;
}
static inline bool __pure __init tpacpi_is_ibm(void)
{
return thinkpad_id.vendor == PCI_VENDOR_ID_IBM;
}
static int acpi_evalf(acpi_handle handle,
int *res, char *method, char *fmt, ...)
{
char *fmt0 = fmt;
struct acpi_object_list params;
union acpi_object in_objs[TPACPI_MAX_ACPI_ARGS];
struct acpi_buffer result, *resultp;
union acpi_object out_obj;
acpi_status status;
va_list ap;
char res_type;
int success;
int quiet;
if (!*fmt) {
pr_err("acpi_evalf() called with empty format\n");
return 0;
}
if (*fmt == 'q') {
quiet = 1;
fmt++;
} else
quiet = 0;
res_type = *(fmt++);
params.count = 0;
params.pointer = &in_objs[0];
va_start(ap, fmt);
while (*fmt) {
char c = *(fmt++);
switch (c) {
case 'd':
in_objs[params.count].integer.value = va_arg(ap, int);
in_objs[params.count++].type = ACPI_TYPE_INTEGER;
break;
default:
pr_err("acpi_evalf() called "
"with invalid format character '%c'\n", c);
va_end(ap);
return 0;
}
}
va_end(ap);
if (res_type != 'v') {
result.length = sizeof(out_obj);
result.pointer = &out_obj;
resultp = &result;
} else
resultp = NULL;
status = acpi_evaluate_object(handle, method, &params, resultp);
switch (res_type) {
case 'd':
success = (status == AE_OK &&
out_obj.type == ACPI_TYPE_INTEGER);
if (success && res)
*res = out_obj.integer.value;
break;
case 'v':
success = status == AE_OK;
break;
default:
pr_err("acpi_evalf() called "
"with invalid format character '%c'\n", res_type);
return 0;
}
if (!success && !quiet)
pr_err("acpi_evalf(%s, %s, ...) failed: %s\n",
method, fmt0, acpi_format_exception(status));
return success;
}
static int acpi_ec_read(int i, u8 *p)
{
int v;
if (ecrd_handle) {
if (!acpi_evalf(ecrd_handle, &v, NULL, "dd", i))
return 0;
*p = v;
} else {
if (ec_read(i, p) < 0)
return 0;
}
return 1;
}
static int acpi_ec_write(int i, u8 v)
{
if (ecwr_handle) {
if (!acpi_evalf(ecwr_handle, NULL, NULL, "vdd", i, v))
return 0;
} else {
if (ec_write(i, v) < 0)
return 0;
}
return 1;
}
static int issue_thinkpad_cmos_command(int cmos_cmd)
{
if (!cmos_handle)
return -ENXIO;
if (!acpi_evalf(cmos_handle, NULL, NULL, "vd", cmos_cmd))
return -EIO;
return 0;
}
static void __init drv_acpi_handle_init(const char *name,
acpi_handle *handle, const acpi_handle parent,
char **paths, const int num_paths)
{
int i;
acpi_status status;
vdbg_printk(TPACPI_DBG_INIT, "trying to locate ACPI handle for %s\n",
name);
for (i = 0; i < num_paths; i++) {
status = acpi_get_handle(parent, paths[i], handle);
if (ACPI_SUCCESS(status)) {
dbg_printk(TPACPI_DBG_INIT,
"Found ACPI handle %s for %s\n",
paths[i], name);
return;
}
}
vdbg_printk(TPACPI_DBG_INIT, "ACPI handle for %s not found\n",
name);
*handle = NULL;
}
static acpi_status __init tpacpi_acpi_handle_locate_callback(acpi_handle handle,
u32 level, void *context, void **return_value)
{
struct acpi_device *dev;
if (!strcmp(context, "video")) {
if (acpi_bus_get_device(handle, &dev))
return AE_OK;
if (strcmp(ACPI_VIDEO_HID, acpi_device_hid(dev)))
return AE_OK;
}
*(acpi_handle *)return_value = handle;
return AE_CTRL_TERMINATE;
}
static void __init tpacpi_acpi_handle_locate(const char *name,
const char *hid,
acpi_handle *handle)
{
acpi_status status;
acpi_handle device_found;
BUG_ON(!name || !handle);
vdbg_printk(TPACPI_DBG_INIT,
"trying to locate ACPI handle for %s, using HID %s\n",
name, hid ? hid : "NULL");
memset(&device_found, 0, sizeof(device_found));
status = acpi_get_devices(hid, tpacpi_acpi_handle_locate_callback,
(void *)name, &device_found);
*handle = NULL;
if (ACPI_SUCCESS(status)) {
*handle = device_found;
dbg_printk(TPACPI_DBG_INIT,
"Found ACPI handle for %s\n", name);
} else {
vdbg_printk(TPACPI_DBG_INIT,
"Could not locate an ACPI handle for %s: %s\n",
name, acpi_format_exception(status));
}
}
static void dispatch_acpi_notify(acpi_handle handle, u32 event, void *data)
{
struct ibm_struct *ibm = data;
if (tpacpi_lifecycle != TPACPI_LIFE_RUNNING)
return;
if (!ibm || !ibm->acpi || !ibm->acpi->notify)
return;
ibm->acpi->notify(ibm, event);
}
static int __init setup_acpi_notify(struct ibm_struct *ibm)
{
acpi_status status;
int rc;
BUG_ON(!ibm->acpi);
if (!*ibm->acpi->handle)
return 0;
vdbg_printk(TPACPI_DBG_INIT,
"setting up ACPI notify for %s\n", ibm->name);
rc = acpi_bus_get_device(*ibm->acpi->handle, &ibm->acpi->device);
if (rc < 0) {
pr_err("acpi_bus_get_device(%s) failed: %d\n", ibm->name, rc);
return -ENODEV;
}
ibm->acpi->device->driver_data = ibm;
sprintf(acpi_device_class(ibm->acpi->device), "%s/%s",
TPACPI_ACPI_EVENT_PREFIX,
ibm->name);
status = acpi_install_notify_handler(*ibm->acpi->handle,
ibm->acpi->type, dispatch_acpi_notify, ibm);
if (ACPI_FAILURE(status)) {
if (status == AE_ALREADY_EXISTS) {
pr_notice("another device driver is already "
"handling %s events\n", ibm->name);
} else {
pr_err("acpi_install_notify_handler(%s) failed: %s\n",
ibm->name, acpi_format_exception(status));
}
return -ENODEV;
}
ibm->flags.acpi_notify_installed = 1;
return 0;
}
static int __init tpacpi_device_add(struct acpi_device *device)
{
return 0;
}
static int __init register_tpacpi_subdriver(struct ibm_struct *ibm)
{
int rc;
dbg_printk(TPACPI_DBG_INIT,
"registering %s as an ACPI driver\n", ibm->name);
BUG_ON(!ibm->acpi);
ibm->acpi->driver = kzalloc(sizeof(struct acpi_driver), GFP_KERNEL);
if (!ibm->acpi->driver) {
pr_err("failed to allocate memory for ibm->acpi->driver\n");
return -ENOMEM;
}
sprintf(ibm->acpi->driver->name, "%s_%s", TPACPI_NAME, ibm->name);
ibm->acpi->driver->ids = ibm->acpi->hid;
ibm->acpi->driver->ops.add = &tpacpi_device_add;
rc = acpi_bus_register_driver(ibm->acpi->driver);
if (rc < 0) {
pr_err("acpi_bus_register_driver(%s) failed: %d\n",
ibm->name, rc);
kfree(ibm->acpi->driver);
ibm->acpi->driver = NULL;
} else if (!rc)
ibm->flags.acpi_driver_registered = 1;
return rc;
}
static int dispatch_proc_show(struct seq_file *m, void *v)
{
struct ibm_struct *ibm = m->private;
if (!ibm || !ibm->read)
return -EINVAL;
return ibm->read(m);
}
static int dispatch_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, dispatch_proc_show, PDE_DATA(inode));
}
static ssize_t dispatch_proc_write(struct file *file,
const char __user *userbuf,
size_t count, loff_t *pos)
{
struct ibm_struct *ibm = PDE_DATA(file_inode(file));
char *kernbuf;
int ret;
if (!ibm || !ibm->write)
return -EINVAL;
if (count > PAGE_SIZE - 2)
return -EINVAL;
kernbuf = kmalloc(count + 2, GFP_KERNEL);
if (!kernbuf)
return -ENOMEM;
if (copy_from_user(kernbuf, userbuf, count)) {
kfree(kernbuf);
return -EFAULT;
}
kernbuf[count] = 0;
strcat(kernbuf, ",");
ret = ibm->write(kernbuf);
if (ret == 0)
ret = count;
kfree(kernbuf);
return ret;
}
static char *next_cmd(char **cmds)
{
char *start = *cmds;
char *end;
while ((end = strchr(start, ',')) && end == start)
start = end + 1;
if (!end)
return NULL;
*end = 0;
*cmds = end + 1;
return start;
}
static int tpacpi_suspend_handler(struct device *dev)
{
struct ibm_struct *ibm, *itmp;
list_for_each_entry_safe(ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
if (ibm->suspend)
(ibm->suspend)();
}
return 0;
}
static int tpacpi_resume_handler(struct device *dev)
{
struct ibm_struct *ibm, *itmp;
list_for_each_entry_safe(ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
if (ibm->resume)
(ibm->resume)();
}
return 0;
}
static void tpacpi_shutdown_handler(struct platform_device *pdev)
{
struct ibm_struct *ibm, *itmp;
list_for_each_entry_safe(ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
if (ibm->shutdown)
(ibm->shutdown)();
}
}
static struct attribute_set *create_attr_set(unsigned int max_members,
const char *name)
{
struct attribute_set_obj *sobj;
if (max_members == 0)
return NULL;
sobj = kzalloc(sizeof(struct attribute_set_obj) +
max_members * sizeof(struct attribute *),
GFP_KERNEL);
if (!sobj)
return NULL;
sobj->s.max_members = max_members;
sobj->s.group.attrs = &sobj->a;
sobj->s.group.name = name;
return &sobj->s;
}
static int add_to_attr_set(struct attribute_set *s, struct attribute *attr)
{
if (!s || !attr)
return -EINVAL;
if (s->members >= s->max_members)
return -ENOMEM;
s->group.attrs[s->members] = attr;
s->members++;
return 0;
}
static int add_many_to_attr_set(struct attribute_set *s,
struct attribute **attr,
unsigned int count)
{
int i, res;
for (i = 0; i < count; i++) {
res = add_to_attr_set(s, attr[i]);
if (res)
return res;
}
return 0;
}
static void delete_attr_set(struct attribute_set *s, struct kobject *kobj)
{
sysfs_remove_group(kobj, &s->group);
destroy_attr_set(s);
}
static int parse_strtoul(const char *buf,
unsigned long max, unsigned long *value)
{
char *endp;
*value = simple_strtoul(skip_spaces(buf), &endp, 0);
endp = skip_spaces(endp);
if (*endp || *value > max)
return -EINVAL;
return 0;
}
static void tpacpi_disable_brightness_delay(void)
{
if (acpi_evalf(hkey_handle, NULL, "PWMS", "qvd", 0))
pr_notice("ACPI backlight control delay disabled\n");
}
static void printk_deprecated_attribute(const char * const what,
const char * const details)
{
tpacpi_log_usertask("deprecated sysfs attribute");
pr_warn("WARNING: sysfs attribute %s is deprecated and "
"will be removed. %s\n",
what, details);
}
static int tpacpi_rfk_update_swstate(const struct tpacpi_rfk *tp_rfk)
{
int status;
if (!tp_rfk)
return -ENODEV;
status = (tp_rfk->ops->get_status)();
if (status < 0)
return status;
rfkill_set_sw_state(tp_rfk->rfkill,
(status == TPACPI_RFK_RADIO_OFF));
return status;
}
static void tpacpi_rfk_update_swstate_all(void)
{
unsigned int i;
for (i = 0; i < TPACPI_RFK_SW_MAX; i++)
tpacpi_rfk_update_swstate(tpacpi_rfkill_switches[i]);
}
static void tpacpi_rfk_update_hwblock_state(bool blocked)
{
unsigned int i;
struct tpacpi_rfk *tp_rfk;
for (i = 0; i < TPACPI_RFK_SW_MAX; i++) {
tp_rfk = tpacpi_rfkill_switches[i];
if (tp_rfk) {
if (rfkill_set_hw_state(tp_rfk->rfkill,
blocked)) {
}
}
}
}
static bool tpacpi_rfk_check_hwblock_state(void)
{
int res = hotkey_get_wlsw();
int hw_blocked;
if (res < 0)
return false;
hw_blocked = (res == TPACPI_RFK_RADIO_OFF);
tpacpi_rfk_update_hwblock_state(hw_blocked);
return hw_blocked;
}
static int tpacpi_rfk_hook_set_block(void *data, bool blocked)
{
struct tpacpi_rfk *tp_rfk = data;
int res;
dbg_printk(TPACPI_DBG_RFKILL,
"request to change radio state to %s\n",
blocked ? "blocked" : "unblocked");
res = (tp_rfk->ops->set_status)(blocked ?
TPACPI_RFK_RADIO_OFF : TPACPI_RFK_RADIO_ON);
tpacpi_rfk_update_swstate(tp_rfk);
return (res < 0) ? res : 0;
}
static int __init tpacpi_new_rfkill(const enum tpacpi_rfk_id id,
const struct tpacpi_rfk_ops *tp_rfkops,
const enum rfkill_type rfktype,
const char *name,
const bool set_default)
{
struct tpacpi_rfk *atp_rfk;
int res;
bool sw_state = false;
bool hw_state;
int sw_status;
BUG_ON(id >= TPACPI_RFK_SW_MAX || tpacpi_rfkill_switches[id]);
atp_rfk = kzalloc(sizeof(struct tpacpi_rfk), GFP_KERNEL);
if (atp_rfk)
atp_rfk->rfkill = rfkill_alloc(name,
&tpacpi_pdev->dev,
rfktype,
&tpacpi_rfk_rfkill_ops,
atp_rfk);
if (!atp_rfk || !atp_rfk->rfkill) {
pr_err("failed to allocate memory for rfkill class\n");
kfree(atp_rfk);
return -ENOMEM;
}
atp_rfk->id = id;
atp_rfk->ops = tp_rfkops;
sw_status = (tp_rfkops->get_status)();
if (sw_status < 0) {
pr_err("failed to read initial state for %s, error %d\n",
name, sw_status);
} else {
sw_state = (sw_status == TPACPI_RFK_RADIO_OFF);
if (set_default) {
rfkill_init_sw_state(atp_rfk->rfkill, sw_state);
}
}
hw_state = tpacpi_rfk_check_hwblock_state();
rfkill_set_hw_state(atp_rfk->rfkill, hw_state);
res = rfkill_register(atp_rfk->rfkill);
if (res < 0) {
pr_err("failed to register %s rfkill switch: %d\n", name, res);
rfkill_destroy(atp_rfk->rfkill);
kfree(atp_rfk);
return res;
}
tpacpi_rfkill_switches[id] = atp_rfk;
pr_info("rfkill switch %s: radio is %sblocked\n",
name, (sw_state || hw_state) ? "" : "un");
return 0;
}
static void tpacpi_destroy_rfkill(const enum tpacpi_rfk_id id)
{
struct tpacpi_rfk *tp_rfk;
BUG_ON(id >= TPACPI_RFK_SW_MAX);
tp_rfk = tpacpi_rfkill_switches[id];
if (tp_rfk) {
rfkill_unregister(tp_rfk->rfkill);
rfkill_destroy(tp_rfk->rfkill);
tpacpi_rfkill_switches[id] = NULL;
kfree(tp_rfk);
}
}
static void printk_deprecated_rfkill_attribute(const char * const what)
{
printk_deprecated_attribute(what,
"Please switch to generic rfkill before year 2010");
}
static ssize_t tpacpi_rfk_sysfs_enable_show(const enum tpacpi_rfk_id id,
struct device_attribute *attr,
char *buf)
{
int status;
printk_deprecated_rfkill_attribute(attr->attr.name);
if (tpacpi_rfk_check_hwblock_state()) {
status = TPACPI_RFK_RADIO_OFF;
} else {
status = tpacpi_rfk_update_swstate(tpacpi_rfkill_switches[id]);
if (status < 0)
return status;
}
return snprintf(buf, PAGE_SIZE, "%d\n",
(status == TPACPI_RFK_RADIO_ON) ? 1 : 0);
}
static ssize_t tpacpi_rfk_sysfs_enable_store(const enum tpacpi_rfk_id id,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned long t;
int res;
printk_deprecated_rfkill_attribute(attr->attr.name);
if (parse_strtoul(buf, 1, &t))
return -EINVAL;
tpacpi_disclose_usertask(attr->attr.name, "set to %ld\n", t);
if (tpacpi_rfk_check_hwblock_state() && !!t)
return -EPERM;
res = tpacpi_rfkill_switches[id]->ops->set_status((!!t) ?
TPACPI_RFK_RADIO_ON : TPACPI_RFK_RADIO_OFF);
tpacpi_rfk_update_swstate(tpacpi_rfkill_switches[id]);
return (res < 0) ? res : count;
}
static int tpacpi_rfk_procfs_read(const enum tpacpi_rfk_id id, struct seq_file *m)
{
if (id >= TPACPI_RFK_SW_MAX)
seq_printf(m, "status:\t\tnot supported\n");
else {
int status;
if (tpacpi_rfk_check_hwblock_state()) {
status = TPACPI_RFK_RADIO_OFF;
} else {
status = tpacpi_rfk_update_swstate(
tpacpi_rfkill_switches[id]);
if (status < 0)
return status;
}
seq_printf(m, "status:\t\t%s\n",
(status == TPACPI_RFK_RADIO_ON) ?
"enabled" : "disabled");
seq_printf(m, "commands:\tenable, disable\n");
}
return 0;
}
static int tpacpi_rfk_procfs_write(const enum tpacpi_rfk_id id, char *buf)
{
char *cmd;
int status = -1;
int res = 0;
if (id >= TPACPI_RFK_SW_MAX)
return -ENODEV;
while ((cmd = next_cmd(&buf))) {
if (strlencmp(cmd, "enable") == 0)
status = TPACPI_RFK_RADIO_ON;
else if (strlencmp(cmd, "disable") == 0)
status = TPACPI_RFK_RADIO_OFF;
else
return -EINVAL;
}
if (status != -1) {
tpacpi_disclose_usertask("procfs", "attempt to %s %s\n",
(status == TPACPI_RFK_RADIO_ON) ?
"enable" : "disable",
tpacpi_rfkill_names[id]);
res = (tpacpi_rfkill_switches[id]->ops->set_status)(status);
tpacpi_rfk_update_swstate(tpacpi_rfkill_switches[id]);
}
return res;
}
static ssize_t tpacpi_driver_interface_version_show(
struct device_driver *drv,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "0x%08x\n", TPACPI_SYSFS_VERSION);
}
static ssize_t tpacpi_driver_debug_show(struct device_driver *drv,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "0x%04x\n", dbg_level);
}
static ssize_t tpacpi_driver_debug_store(struct device_driver *drv,
const char *buf, size_t count)
{
unsigned long t;
if (parse_strtoul(buf, 0xffff, &t))
return -EINVAL;
dbg_level = t;
return count;
}
static ssize_t tpacpi_driver_version_show(struct device_driver *drv,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s v%s\n",
TPACPI_DESC, TPACPI_VERSION);
}
static ssize_t tpacpi_driver_wlsw_emulstate_show(struct device_driver *drv,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", !!tpacpi_wlsw_emulstate);
}
static ssize_t tpacpi_driver_wlsw_emulstate_store(struct device_driver *drv,
const char *buf, size_t count)
{
unsigned long t;
if (parse_strtoul(buf, 1, &t))
return -EINVAL;
if (tpacpi_wlsw_emulstate != !!t) {
tpacpi_wlsw_emulstate = !!t;
tpacpi_rfk_update_hwblock_state(!t);
}
return count;
}
static ssize_t tpacpi_driver_bluetooth_emulstate_show(
struct device_driver *drv,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", !!tpacpi_bluetooth_emulstate);
}
static ssize_t tpacpi_driver_bluetooth_emulstate_store(
struct device_driver *drv,
const char *buf, size_t count)
{
unsigned long t;
if (parse_strtoul(buf, 1, &t))
return -EINVAL;
tpacpi_bluetooth_emulstate = !!t;
return count;
}
static ssize_t tpacpi_driver_wwan_emulstate_show(
struct device_driver *drv,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", !!tpacpi_wwan_emulstate);
}
static ssize_t tpacpi_driver_wwan_emulstate_store(
struct device_driver *drv,
const char *buf, size_t count)
{
unsigned long t;
if (parse_strtoul(buf, 1, &t))
return -EINVAL;
tpacpi_wwan_emulstate = !!t;
return count;
}
static ssize_t tpacpi_driver_uwb_emulstate_show(
struct device_driver *drv,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", !!tpacpi_uwb_emulstate);
}
static ssize_t tpacpi_driver_uwb_emulstate_store(
struct device_driver *drv,
const char *buf, size_t count)
{
unsigned long t;
if (parse_strtoul(buf, 1, &t))
return -EINVAL;
tpacpi_uwb_emulstate = !!t;
return count;
}
static int __init tpacpi_create_driver_attributes(struct device_driver *drv)
{
int i, res;
i = 0;
res = 0;
while (!res && i < ARRAY_SIZE(tpacpi_driver_attributes)) {
res = driver_create_file(drv, tpacpi_driver_attributes[i]);
i++;
}
#ifdef CONFIG_THINKPAD_ACPI_DEBUGFACILITIES
if (!res && dbg_wlswemul)
res = driver_create_file(drv, &driver_attr_wlsw_emulstate);
if (!res && dbg_bluetoothemul)
res = driver_create_file(drv, &driver_attr_bluetooth_emulstate);
if (!res && dbg_wwanemul)
res = driver_create_file(drv, &driver_attr_wwan_emulstate);
if (!res && dbg_uwbemul)
res = driver_create_file(drv, &driver_attr_uwb_emulstate);
#endif
return res;
}
static void tpacpi_remove_driver_attributes(struct device_driver *drv)
{
int i;
for (i = 0; i < ARRAY_SIZE(tpacpi_driver_attributes); i++)
driver_remove_file(drv, tpacpi_driver_attributes[i]);
#ifdef THINKPAD_ACPI_DEBUGFACILITIES
driver_remove_file(drv, &driver_attr_wlsw_emulstate);
driver_remove_file(drv, &driver_attr_bluetooth_emulstate);
driver_remove_file(drv, &driver_attr_wwan_emulstate);
driver_remove_file(drv, &driver_attr_uwb_emulstate);
#endif
}
static void __init tpacpi_check_outdated_fw(void)
{
unsigned long fwvers;
u16 ec_version, bios_version;
fwvers = tpacpi_check_quirks(tpacpi_bios_version_qtable,
ARRAY_SIZE(tpacpi_bios_version_qtable));
if (!fwvers)
return;
bios_version = fwvers & 0xffffU;
ec_version = (fwvers >> 16) & 0xffffU;
if ((bios_version > thinkpad_id.bios_release) ||
(ec_version > thinkpad_id.ec_release &&
ec_version != TPACPI_MATCH_ANY)) {
pr_warn("WARNING: Outdated ThinkPad BIOS/EC firmware\n");
pr_warn("WARNING: This firmware may be missing critical bug "
"fixes and/or important features\n");
}
}
static bool __init tpacpi_is_fw_known(void)
{
return tpacpi_check_quirks(tpacpi_bios_version_qtable,
ARRAY_SIZE(tpacpi_bios_version_qtable)) != 0;
}
static int thinkpad_acpi_driver_read(struct seq_file *m)
{
seq_printf(m, "driver:\t\t%s\n", TPACPI_DESC);
seq_printf(m, "version:\t%s\n", TPACPI_VERSION);
return 0;
}
static int hotkey_get_wlsw(void)
{
int status;
if (!tp_features.hotkey_wlsw)
return -ENODEV;
#ifdef CONFIG_THINKPAD_ACPI_DEBUGFACILITIES
if (dbg_wlswemul)
return (tpacpi_wlsw_emulstate) ?
TPACPI_RFK_RADIO_ON : TPACPI_RFK_RADIO_OFF;
#endif
if (!acpi_evalf(hkey_handle, &status, "WLSW", "d"))
return -EIO;
return (status) ? TPACPI_RFK_RADIO_ON : TPACPI_RFK_RADIO_OFF;
}
static int hotkey_get_tablet_mode(int *status)
{
int s;
if (!acpi_evalf(hkey_handle, &s, "MHKG", "d"))
return -EIO;
*status = ((s & TP_HOTKEY_TABLET_MASK) != 0);
return 0;
}
static int hotkey_mask_get(void)
{
if (tp_features.hotkey_mask) {
u32 m = 0;
if (!acpi_evalf(hkey_handle, &m, "DHKN", "d"))
return -EIO;
hotkey_acpi_mask = m;
} else {
hotkey_acpi_mask = hotkey_all_mask;
}
hotkey_user_mask &= (hotkey_acpi_mask | hotkey_source_mask);
return 0;
}
void static hotkey_mask_warn_incomplete_mask(void)
{
const u32 wantedmask = hotkey_driver_mask &
~(hotkey_acpi_mask | hotkey_source_mask) &
(hotkey_all_mask | TPACPI_HKEY_NVRAM_KNOWN_MASK);
if (wantedmask)
pr_notice("required events 0x%08x not enabled!\n", wantedmask);
}
static int hotkey_mask_set(u32 mask)
{
int i;
int rc = 0;
const u32 fwmask = mask & ~hotkey_source_mask;
if (tp_features.hotkey_mask) {
for (i = 0; i < 32; i++) {
if (!acpi_evalf(hkey_handle,
NULL, "MHKM", "vdd", i + 1,
!!(mask & (1 << i)))) {
rc = -EIO;
break;
}
}
}
if (!hotkey_mask_get() && !rc && (fwmask & ~hotkey_acpi_mask)) {
pr_notice("asked for hotkey mask 0x%08x, but "
"firmware forced it to 0x%08x\n",
fwmask, hotkey_acpi_mask);
}
if (tpacpi_lifecycle != TPACPI_LIFE_EXITING)
hotkey_mask_warn_incomplete_mask();
return rc;
}
static int hotkey_user_mask_set(const u32 mask)
{
int rc;
if (!tp_warned.hotkey_mask_ff &&
(mask == 0xffff || mask == 0xffffff ||
mask == 0xffffffff)) {
tp_warned.hotkey_mask_ff = 1;
pr_notice("setting the hotkey mask to 0x%08x is likely "
"not the best way to go about it\n", mask);
pr_notice("please consider using the driver defaults, "
"and refer to up-to-date thinkpad-acpi "
"documentation\n");
}
rc = hotkey_mask_set((mask | hotkey_driver_mask) & ~hotkey_source_mask);
hotkey_user_mask = mask & (hotkey_acpi_mask | hotkey_source_mask);
return rc;
}
static int tpacpi_hotkey_driver_mask_set(const u32 mask)
{
int rc;
if (!tp_features.hotkey) {
hotkey_driver_mask = mask;
return 0;
}
mutex_lock(&hotkey_mutex);
HOTKEY_CONFIG_CRITICAL_START
hotkey_driver_mask = mask;
#ifdef CONFIG_THINKPAD_ACPI_HOTKEY_POLL
hotkey_source_mask |= (mask & ~hotkey_all_mask);
#endif
HOTKEY_CONFIG_CRITICAL_END
rc = hotkey_mask_set((hotkey_acpi_mask | hotkey_driver_mask) &
~hotkey_source_mask);
hotkey_poll_setup(true);
mutex_unlock(&hotkey_mutex);
return rc;
}
static int hotkey_status_get(int *status)
{
if (!acpi_evalf(hkey_handle, status, "DHKC", "d"))
return -EIO;
return 0;
}
static int hotkey_status_set(bool enable)
{
if (!acpi_evalf(hkey_handle, NULL, "MHKC", "vd", enable ? 1 : 0))
return -EIO;
return 0;
}
static void tpacpi_input_send_tabletsw(void)
{
int state;
if (tp_features.hotkey_tablet &&
!hotkey_get_tablet_mode(&state)) {
mutex_lock(&tpacpi_inputdev_send_mutex);
input_report_switch(tpacpi_inputdev,
SW_TABLET_MODE, !!state);
input_sync(tpacpi_inputdev);
mutex_unlock(&tpacpi_inputdev_send_mutex);
}
}
static void tpacpi_input_send_key(const unsigned int scancode)
{
const unsigned int keycode = hotkey_keycode_map[scancode];
if (keycode != KEY_RESERVED) {
mutex_lock(&tpacpi_inputdev_send_mutex);
input_event(tpacpi_inputdev, EV_MSC, MSC_SCAN, scancode);
input_report_key(tpacpi_inputdev, keycode, 1);
input_sync(tpacpi_inputdev);
input_event(tpacpi_inputdev, EV_MSC, MSC_SCAN, scancode);
input_report_key(tpacpi_inputdev, keycode, 0);
input_sync(tpacpi_inputdev);
mutex_unlock(&tpacpi_inputdev_send_mutex);
}
}
static void tpacpi_input_send_key_masked(const unsigned int scancode)
{
hotkey_driver_event(scancode);
if (hotkey_user_mask & (1 << scancode))
tpacpi_input_send_key(scancode);
}
static void tpacpi_hotkey_send_key(unsigned int scancode)
{
tpacpi_input_send_key_masked(scancode);
}
static void hotkey_read_nvram(struct tp_nvram_state *n, const u32 m)
{
u8 d;
if (m & TP_NVRAM_HKEY_GROUP_HK2) {
d = nvram_read_byte(TP_NVRAM_ADDR_HK2);
n->thinkpad_toggle = !!(d & TP_NVRAM_MASK_HKT_THINKPAD);
n->zoom_toggle = !!(d & TP_NVRAM_MASK_HKT_ZOOM);
n->display_toggle = !!(d & TP_NVRAM_MASK_HKT_DISPLAY);
n->hibernate_toggle = !!(d & TP_NVRAM_MASK_HKT_HIBERNATE);
}
if (m & TP_ACPI_HKEY_THNKLGHT_MASK) {
d = nvram_read_byte(TP_NVRAM_ADDR_THINKLIGHT);
n->thinklight_toggle = !!(d & TP_NVRAM_MASK_THINKLIGHT);
}
if (m & TP_ACPI_HKEY_DISPXPAND_MASK) {
d = nvram_read_byte(TP_NVRAM_ADDR_VIDEO);
n->displayexp_toggle =
!!(d & TP_NVRAM_MASK_HKT_DISPEXPND);
}
if (m & TP_NVRAM_HKEY_GROUP_BRIGHTNESS) {
d = nvram_read_byte(TP_NVRAM_ADDR_BRIGHTNESS);
n->brightness_level = (d & TP_NVRAM_MASK_LEVEL_BRIGHTNESS)
>> TP_NVRAM_POS_LEVEL_BRIGHTNESS;
n->brightness_toggle =
!!(d & TP_NVRAM_MASK_HKT_BRIGHTNESS);
}
if (m & TP_NVRAM_HKEY_GROUP_VOLUME) {
d = nvram_read_byte(TP_NVRAM_ADDR_MIXER);
n->volume_level = (d & TP_NVRAM_MASK_LEVEL_VOLUME)
>> TP_NVRAM_POS_LEVEL_VOLUME;
n->mute = !!(d & TP_NVRAM_MASK_MUTE);
n->volume_toggle = !!(d & TP_NVRAM_MASK_HKT_VOLUME);
}
}
void issue_volchange(const unsigned int oldvol,
const unsigned int newvol)
{
unsigned int i = oldvol;
while (i > newvol) {
TPACPI_MAY_SEND_KEY(TP_ACPI_HOTKEYSCAN_VOLUMEDOWN);
i--;
}
while (i < newvol) {
TPACPI_MAY_SEND_KEY(TP_ACPI_HOTKEYSCAN_VOLUMEUP);
i++;
}
}
void issue_brightnesschange(const unsigned int oldbrt,
const unsigned int newbrt)
{
unsigned int i = oldbrt;
while (i > newbrt) {
TPACPI_MAY_SEND_KEY(TP_ACPI_HOTKEYSCAN_FNEND);
i--;
}
while (i < newbrt) {
TPACPI_MAY_SEND_KEY(TP_ACPI_HOTKEYSCAN_FNHOME);
i++;
}
}
static int hotkey_kthread(void *data)
{
struct tp_nvram_state s[2];
u32 poll_mask, event_mask;
unsigned int si, so;
unsigned long t;
unsigned int change_detector;
unsigned int poll_freq;
bool was_frozen;
if (tpacpi_lifecycle == TPACPI_LIFE_EXITING)
goto exit;
set_freezable();
so = 0;
si = 1;
t = 0;
mutex_lock(&hotkey_thread_data_mutex);
change_detector = hotkey_config_change;
poll_mask = hotkey_source_mask;
event_mask = hotkey_source_mask &
(hotkey_driver_mask | hotkey_user_mask);
poll_freq = hotkey_poll_freq;
mutex_unlock(&hotkey_thread_data_mutex);
hotkey_read_nvram(&s[so], poll_mask);
while (!kthread_should_stop()) {
if (t == 0) {
if (likely(poll_freq))
t = 1000/poll_freq;
else
t = 100;
}
t = msleep_interruptible(t);
if (unlikely(kthread_freezable_should_stop(&was_frozen)))
break;
if (t > 0 && !was_frozen)
continue;
mutex_lock(&hotkey_thread_data_mutex);
if (was_frozen || hotkey_config_change != change_detector) {
si = so;
t = 0;
change_detector = hotkey_config_change;
}
poll_mask = hotkey_source_mask;
event_mask = hotkey_source_mask &
(hotkey_driver_mask | hotkey_user_mask);
poll_freq = hotkey_poll_freq;
mutex_unlock(&hotkey_thread_data_mutex);
if (likely(poll_mask)) {
hotkey_read_nvram(&s[si], poll_mask);
if (likely(si != so)) {
hotkey_compare_and_issue_event(&s[so], &s[si],
event_mask);
}
}
so = si;
si ^= 1;
}
exit:
return 0;
}
static void hotkey_poll_stop_sync(void)
{
if (tpacpi_hotkey_task) {
kthread_stop(tpacpi_hotkey_task);
tpacpi_hotkey_task = NULL;
}
}
static void hotkey_poll_setup(const bool may_warn)
{
const u32 poll_driver_mask = hotkey_driver_mask & hotkey_source_mask;
const u32 poll_user_mask = hotkey_user_mask & hotkey_source_mask;
if (hotkey_poll_freq > 0 &&
(poll_driver_mask ||
(poll_user_mask && tpacpi_inputdev->users > 0))) {
if (!tpacpi_hotkey_task) {
tpacpi_hotkey_task = kthread_run(hotkey_kthread,
NULL, TPACPI_NVRAM_KTHREAD_NAME);
if (IS_ERR(tpacpi_hotkey_task)) {
tpacpi_hotkey_task = NULL;
pr_err("could not create kernel thread "
"for hotkey polling\n");
}
}
} else {
hotkey_poll_stop_sync();
if (may_warn && (poll_driver_mask || poll_user_mask) &&
hotkey_poll_freq == 0) {
pr_notice("hot keys 0x%08x and/or events 0x%08x "
"require polling, which is currently "
"disabled\n",
poll_user_mask, poll_driver_mask);
}
}
}
static void hotkey_poll_setup_safe(const bool may_warn)
{
mutex_lock(&hotkey_mutex);
hotkey_poll_setup(may_warn);
mutex_unlock(&hotkey_mutex);
}
static void hotkey_poll_set_freq(unsigned int freq)
{
if (!freq)
hotkey_poll_stop_sync();
hotkey_poll_freq = freq;
}
static void hotkey_poll_setup(const bool __unused)
{
}
static void hotkey_poll_setup_safe(const bool __unused)
{
}
static int hotkey_inputdev_open(struct input_dev *dev)
{
switch (tpacpi_lifecycle) {
case TPACPI_LIFE_INIT:
case TPACPI_LIFE_RUNNING:
hotkey_poll_setup_safe(false);
return 0;
case TPACPI_LIFE_EXITING:
return -EBUSY;
}
BUG();
return -EBUSY;
}
static void hotkey_inputdev_close(struct input_dev *dev)
{
if (tpacpi_lifecycle != TPACPI_LIFE_EXITING &&
!(hotkey_source_mask & hotkey_driver_mask))
hotkey_poll_setup_safe(false);
}
static ssize_t hotkey_enable_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int res, status;
printk_deprecated_attribute("hotkey_enable",
"Hotkey reporting is always enabled");
res = hotkey_status_get(&status);
if (res)
return res;
return snprintf(buf, PAGE_SIZE, "%d\n", status);
}
static ssize_t hotkey_enable_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned long t;
printk_deprecated_attribute("hotkey_enable",
"Hotkeys can be disabled through hotkey_mask");
if (parse_strtoul(buf, 1, &t))
return -EINVAL;
if (t == 0)
return -EPERM;
return count;
}
static ssize_t hotkey_mask_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "0x%08x\n", hotkey_user_mask);
}
static ssize_t hotkey_mask_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned long t;
int res;
if (parse_strtoul(buf, 0xffffffffUL, &t))
return -EINVAL;
if (mutex_lock_killable(&hotkey_mutex))
return -ERESTARTSYS;
res = hotkey_user_mask_set(t);
#ifdef CONFIG_THINKPAD_ACPI_HOTKEY_POLL
hotkey_poll_setup(true);
#endif
mutex_unlock(&hotkey_mutex);
tpacpi_disclose_usertask("hotkey_mask", "set to 0x%08lx\n", t);
return (res) ? res : count;
}
static ssize_t hotkey_bios_enabled_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "0\n");
}
static ssize_t hotkey_bios_mask_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
printk_deprecated_attribute("hotkey_bios_mask",
"This attribute is useless.");
return snprintf(buf, PAGE_SIZE, "0x%08x\n", hotkey_orig_mask);
}
static ssize_t hotkey_all_mask_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "0x%08x\n",
hotkey_all_mask | hotkey_source_mask);
}
static ssize_t hotkey_recommended_mask_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "0x%08x\n",
(hotkey_all_mask | hotkey_source_mask)
& ~hotkey_reserved_mask);
}
static ssize_t hotkey_source_mask_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "0x%08x\n", hotkey_source_mask);
}
static ssize_t hotkey_source_mask_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned long t;
u32 r_ev;
int rc;
if (parse_strtoul(buf, 0xffffffffUL, &t) ||
((t & ~TPACPI_HKEY_NVRAM_KNOWN_MASK) != 0))
return -EINVAL;
if (mutex_lock_killable(&hotkey_mutex))
return -ERESTARTSYS;
HOTKEY_CONFIG_CRITICAL_START
hotkey_source_mask = t;
HOTKEY_CONFIG_CRITICAL_END
rc = hotkey_mask_set((hotkey_user_mask | hotkey_driver_mask) &
~hotkey_source_mask);
hotkey_poll_setup(true);
r_ev = hotkey_driver_mask & ~(hotkey_acpi_mask & hotkey_all_mask)
& ~hotkey_source_mask & TPACPI_HKEY_NVRAM_KNOWN_MASK;
mutex_unlock(&hotkey_mutex);
if (rc < 0)
pr_err("hotkey_source_mask: "
"failed to update the firmware event mask!\n");
if (r_ev)
pr_notice("hotkey_source_mask: "
"some important events were disabled: 0x%04x\n",
r_ev);
tpacpi_disclose_usertask("hotkey_source_mask", "set to 0x%08lx\n", t);
return (rc < 0) ? rc : count;
}
static ssize_t hotkey_poll_freq_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", hotkey_poll_freq);
}
static ssize_t hotkey_poll_freq_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned long t;
if (parse_strtoul(buf, 25, &t))
return -EINVAL;
if (mutex_lock_killable(&hotkey_mutex))
return -ERESTARTSYS;
hotkey_poll_set_freq(t);
hotkey_poll_setup(true);
mutex_unlock(&hotkey_mutex);
tpacpi_disclose_usertask("hotkey_poll_freq", "set to %lu\n", t);
return count;
}
static ssize_t hotkey_radio_sw_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int res;
res = hotkey_get_wlsw();
if (res < 0)
return res;
tpacpi_rfk_update_hwblock_state((res == TPACPI_RFK_RADIO_OFF));
return snprintf(buf, PAGE_SIZE, "%d\n",
(res == TPACPI_RFK_RADIO_OFF) ? 0 : 1);
}
static void hotkey_radio_sw_notify_change(void)
{
if (tp_features.hotkey_wlsw)
sysfs_notify(&tpacpi_pdev->dev.kobj, NULL,
"hotkey_radio_sw");
}
static ssize_t hotkey_tablet_mode_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int res, s;
res = hotkey_get_tablet_mode(&s);
if (res < 0)
return res;
return snprintf(buf, PAGE_SIZE, "%d\n", !!s);
}
static void hotkey_tablet_mode_notify_change(void)
{
if (tp_features.hotkey_tablet)
sysfs_notify(&tpacpi_pdev->dev.kobj, NULL,
"hotkey_tablet_mode");
}
static ssize_t hotkey_wakeup_reason_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", hotkey_wakeup_reason);
}
static void hotkey_wakeup_reason_notify_change(void)
{
sysfs_notify(&tpacpi_pdev->dev.kobj, NULL,
"wakeup_reason");
}
static ssize_t hotkey_wakeup_hotunplug_complete_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", hotkey_autosleep_ack);
}
static void hotkey_wakeup_hotunplug_complete_notify_change(void)
{
sysfs_notify(&tpacpi_pdev->dev.kobj, NULL,
"wakeup_hotunplug_complete");
}
static void tpacpi_send_radiosw_update(void)
{
int wlsw;
wlsw = hotkey_get_wlsw();
if (wlsw == TPACPI_RFK_RADIO_OFF)
tpacpi_rfk_update_hwblock_state(true);
tpacpi_rfk_update_swstate_all();
if (wlsw == TPACPI_RFK_RADIO_ON)
tpacpi_rfk_update_hwblock_state(false);
if (!(wlsw < 0)) {
mutex_lock(&tpacpi_inputdev_send_mutex);
input_report_switch(tpacpi_inputdev,
SW_RFKILL_ALL, (wlsw > 0));
input_sync(tpacpi_inputdev);
mutex_unlock(&tpacpi_inputdev_send_mutex);
}
hotkey_radio_sw_notify_change();
}
static void hotkey_exit(void)
{
#ifdef CONFIG_THINKPAD_ACPI_HOTKEY_POLL
mutex_lock(&hotkey_mutex);
hotkey_poll_stop_sync();
mutex_unlock(&hotkey_mutex);
#endif
if (hotkey_dev_attributes)
delete_attr_set(hotkey_dev_attributes, &tpacpi_pdev->dev.kobj);
dbg_printk(TPACPI_DBG_EXIT | TPACPI_DBG_HKEY,
"restoring original HKEY status and mask\n");
if (((tp_features.hotkey_mask &&
hotkey_mask_set(hotkey_orig_mask)) |
hotkey_status_set(false)) != 0)
pr_err("failed to restore hot key mask "
"to BIOS defaults\n");
}
static void __init hotkey_unmap(const unsigned int scancode)
{
if (hotkey_keycode_map[scancode] != KEY_RESERVED) {
clear_bit(hotkey_keycode_map[scancode],
tpacpi_inputdev->keybit);
hotkey_keycode_map[scancode] = KEY_RESERVED;
}
}
static int __init hotkey_init(struct ibm_init_struct *iibm)
{
enum keymap_index {
TPACPI_KEYMAP_IBM_GENERIC = 0,
TPACPI_KEYMAP_LENOVO_GENERIC,
};
static const tpacpi_keymap_t tpacpi_keymaps[] __initconst = {
[TPACPI_KEYMAP_IBM_GENERIC] = {
KEY_FN_F1, KEY_BATTERY, KEY_COFFEE, KEY_SLEEP,
KEY_WLAN, KEY_FN_F6, KEY_SWITCHVIDEOMODE, KEY_FN_F8,
KEY_FN_F9, KEY_FN_F10, KEY_FN_F11, KEY_SUSPEND,
KEY_UNKNOWN,
KEY_UNKNOWN,
KEY_UNKNOWN,
KEY_RESERVED,
KEY_RESERVED,
KEY_RESERVED,
KEY_UNKNOWN,
KEY_ZOOM,
KEY_RESERVED,
KEY_RESERVED,
KEY_RESERVED,
KEY_VENDOR,
KEY_UNKNOWN, KEY_UNKNOWN, KEY_UNKNOWN, KEY_UNKNOWN,
KEY_UNKNOWN, KEY_UNKNOWN, KEY_UNKNOWN, KEY_UNKNOWN,
},
[TPACPI_KEYMAP_LENOVO_GENERIC] = {
KEY_FN_F1, KEY_COFFEE, KEY_BATTERY, KEY_SLEEP,
KEY_WLAN, KEY_CAMERA, KEY_SWITCHVIDEOMODE, KEY_FN_F8,
KEY_FN_F9, KEY_FN_F10, KEY_FN_F11, KEY_SUSPEND,
KEY_UNKNOWN,
KEY_UNKNOWN,
KEY_UNKNOWN,
KEY_BRIGHTNESSUP,
KEY_BRIGHTNESSDOWN,
KEY_RESERVED,
KEY_UNKNOWN,
KEY_ZOOM,
KEY_RESERVED,
KEY_RESERVED,
KEY_RESERVED,
KEY_VENDOR,
KEY_UNKNOWN, KEY_UNKNOWN,
KEY_MICMUTE,
KEY_UNKNOWN, KEY_UNKNOWN, KEY_UNKNOWN, KEY_UNKNOWN,
KEY_UNKNOWN,
},
};
static const struct tpacpi_quirk tpacpi_keymap_qtable[] __initconst = {
{
.vendor = PCI_VENDOR_ID_IBM,
.bios = TPACPI_MATCH_ANY, .ec = TPACPI_MATCH_ANY,
.quirks = TPACPI_KEYMAP_IBM_GENERIC,
},
{
.vendor = PCI_VENDOR_ID_LENOVO,
.bios = TPACPI_MATCH_ANY, .ec = TPACPI_MATCH_ANY,
.quirks = TPACPI_KEYMAP_LENOVO_GENERIC,
},
};
#define TPACPI_HOTKEY_MAP_SIZE sizeof(tpacpi_keymap_t)
#define TPACPI_HOTKEY_MAP_TYPESIZE sizeof(tpacpi_keymap_entry_t)
int res, i;
int status;
int hkeyv;
bool radiosw_state = false;
bool tabletsw_state = false;
unsigned long quirks;
unsigned long keymap_id;
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_HKEY,
"initializing hotkey subdriver\n");
BUG_ON(!tpacpi_inputdev);
BUG_ON(tpacpi_inputdev->open != NULL ||
tpacpi_inputdev->close != NULL);
TPACPI_ACPIHANDLE_INIT(hkey);
mutex_init(&hotkey_mutex);
#ifdef CONFIG_THINKPAD_ACPI_HOTKEY_POLL
mutex_init(&hotkey_thread_data_mutex);
#endif
tp_features.hotkey = hkey_handle != NULL;
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_HKEY,
"hotkeys are %s\n",
str_supported(tp_features.hotkey));
if (!tp_features.hotkey)
return 1;
quirks = tpacpi_check_quirks(tpacpi_hotkey_qtable,
ARRAY_SIZE(tpacpi_hotkey_qtable));
tpacpi_disable_brightness_delay();
hotkey_dev_attributes = create_attr_set(
ARRAY_SIZE(hotkey_attributes) + 2,
NULL);
if (!hotkey_dev_attributes)
return -ENOMEM;
res = add_many_to_attr_set(hotkey_dev_attributes,
hotkey_attributes,
ARRAY_SIZE(hotkey_attributes));
if (res)
goto err_exit;
if (acpi_evalf(hkey_handle, &hkeyv, "MHKV", "qd")) {
if ((hkeyv >> 8) != 1) {
pr_err("unknown version of the HKEY interface: 0x%x\n",
hkeyv);
pr_err("please report this to %s\n", TPACPI_MAIL);
} else {
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_HKEY,
"firmware HKEY interface version: 0x%x\n",
hkeyv);
if (!acpi_evalf(hkey_handle, &hotkey_all_mask,
"MHKA", "qd")) {
pr_err("missing MHKA handler, "
"please report this to %s\n",
TPACPI_MAIL);
hotkey_all_mask = 0x080cU;
} else {
tp_features.hotkey_mask = 1;
}
}
}
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_HKEY,
"hotkey masks are %s\n",
str_supported(tp_features.hotkey_mask));
if (!tp_features.hotkey_mask && !hotkey_all_mask &&
(quirks & TPACPI_HK_Q_INIMASK))
hotkey_all_mask = 0x080cU;
if (tp_features.hotkey_mask) {
res = hotkey_mask_get();
if (res)
goto err_exit;
hotkey_orig_mask = hotkey_acpi_mask;
} else {
hotkey_orig_mask = hotkey_all_mask;
hotkey_acpi_mask = hotkey_all_mask;
}
#ifdef CONFIG_THINKPAD_ACPI_DEBUGFACILITIES
if (dbg_wlswemul) {
tp_features.hotkey_wlsw = 1;
radiosw_state = !!tpacpi_wlsw_emulstate;
pr_info("radio switch emulation enabled\n");
} else
#endif
if (acpi_evalf(hkey_handle, &status, "WLSW", "qd")) {
tp_features.hotkey_wlsw = 1;
radiosw_state = !!status;
pr_info("radio switch found; radios are %s\n",
enabled(status, 0));
}
if (tp_features.hotkey_wlsw)
res = add_to_attr_set(hotkey_dev_attributes,
&dev_attr_hotkey_radio_sw.attr);
if (!res && acpi_evalf(hkey_handle, &status, "MHKG", "qd")) {
tp_features.hotkey_tablet = 1;
tabletsw_state = !!(status & TP_HOTKEY_TABLET_MASK);
pr_info("possible tablet mode switch found; "
"ThinkPad in %s mode\n",
(tabletsw_state) ? "tablet" : "laptop");
res = add_to_attr_set(hotkey_dev_attributes,
&dev_attr_hotkey_tablet_mode.attr);
}
if (!res)
res = register_attr_set_with_sysfs(
hotkey_dev_attributes,
&tpacpi_pdev->dev.kobj);
if (res)
goto err_exit;
hotkey_keycode_map = kmalloc(TPACPI_HOTKEY_MAP_SIZE,
GFP_KERNEL);
if (!hotkey_keycode_map) {
pr_err("failed to allocate memory for key map\n");
res = -ENOMEM;
goto err_exit;
}
keymap_id = tpacpi_check_quirks(tpacpi_keymap_qtable,
ARRAY_SIZE(tpacpi_keymap_qtable));
BUG_ON(keymap_id >= ARRAY_SIZE(tpacpi_keymaps));
dbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_HKEY,
"using keymap number %lu\n", keymap_id);
memcpy(hotkey_keycode_map, &tpacpi_keymaps[keymap_id],
TPACPI_HOTKEY_MAP_SIZE);
input_set_capability(tpacpi_inputdev, EV_MSC, MSC_SCAN);
tpacpi_inputdev->keycodesize = TPACPI_HOTKEY_MAP_TYPESIZE;
tpacpi_inputdev->keycodemax = TPACPI_HOTKEY_MAP_LEN;
tpacpi_inputdev->keycode = hotkey_keycode_map;
for (i = 0; i < TPACPI_HOTKEY_MAP_LEN; i++) {
if (hotkey_keycode_map[i] != KEY_RESERVED) {
input_set_capability(tpacpi_inputdev, EV_KEY,
hotkey_keycode_map[i]);
} else {
if (i < sizeof(hotkey_reserved_mask)*8)
hotkey_reserved_mask |= 1 << i;
}
}
if (tp_features.hotkey_wlsw) {
input_set_capability(tpacpi_inputdev, EV_SW, SW_RFKILL_ALL);
input_report_switch(tpacpi_inputdev,
SW_RFKILL_ALL, radiosw_state);
}
if (tp_features.hotkey_tablet) {
input_set_capability(tpacpi_inputdev, EV_SW, SW_TABLET_MODE);
input_report_switch(tpacpi_inputdev,
SW_TABLET_MODE, tabletsw_state);
}
if (acpi_video_backlight_support()) {
pr_info("This ThinkPad has standard ACPI backlight "
"brightness control, supported by the ACPI "
"video driver\n");
pr_notice("Disabling thinkpad-acpi brightness events "
"by default...\n");
hotkey_reserved_mask |=
(1 << TP_ACPI_HOTKEYSCAN_FNHOME)
| (1 << TP_ACPI_HOTKEYSCAN_FNEND);
hotkey_unmap(TP_ACPI_HOTKEYSCAN_FNHOME);
hotkey_unmap(TP_ACPI_HOTKEYSCAN_FNEND);
}
#ifdef CONFIG_THINKPAD_ACPI_HOTKEY_POLL
hotkey_source_mask = TPACPI_HKEY_NVRAM_GOOD_MASK
& ~hotkey_all_mask
& ~hotkey_reserved_mask;
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_HKEY,
"hotkey source mask 0x%08x, polling freq %u\n",
hotkey_source_mask, hotkey_poll_freq);
#endif
dbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_HKEY,
"enabling firmware HKEY event interface...\n");
res = hotkey_status_set(true);
if (res) {
hotkey_exit();
return res;
}
res = hotkey_mask_set(((hotkey_all_mask & ~hotkey_reserved_mask)
| hotkey_driver_mask)
& ~hotkey_source_mask);
if (res < 0 && res != -ENXIO) {
hotkey_exit();
return res;
}
hotkey_user_mask = (hotkey_acpi_mask | hotkey_source_mask)
& ~hotkey_reserved_mask;
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_HKEY,
"initial masks: user=0x%08x, fw=0x%08x, poll=0x%08x\n",
hotkey_user_mask, hotkey_acpi_mask, hotkey_source_mask);
tpacpi_inputdev->open = &hotkey_inputdev_open;
tpacpi_inputdev->close = &hotkey_inputdev_close;
hotkey_poll_setup_safe(true);
return 0;
err_exit:
delete_attr_set(hotkey_dev_attributes, &tpacpi_pdev->dev.kobj);
hotkey_dev_attributes = NULL;
return (res < 0)? res : 1;
}
static bool hotkey_notify_hotkey(const u32 hkey,
bool *send_acpi_ev,
bool *ignore_acpi_ev)
{
unsigned int scancode = hkey & 0xfff;
*send_acpi_ev = true;
*ignore_acpi_ev = false;
if (scancode > 0 && scancode <= TPACPI_HOTKEY_MAP_LEN) {
scancode--;
if (!(hotkey_source_mask & (1 << scancode))) {
tpacpi_input_send_key_masked(scancode);
*send_acpi_ev = false;
} else {
*ignore_acpi_ev = true;
}
return true;
}
return false;
}
static bool hotkey_notify_wakeup(const u32 hkey,
bool *send_acpi_ev,
bool *ignore_acpi_ev)
{
*send_acpi_ev = true;
*ignore_acpi_ev = false;
switch (hkey) {
case TP_HKEY_EV_WKUP_S3_UNDOCK:
case TP_HKEY_EV_WKUP_S4_UNDOCK:
hotkey_wakeup_reason = TP_ACPI_WAKEUP_UNDOCK;
*ignore_acpi_ev = true;
break;
case TP_HKEY_EV_WKUP_S3_BAYEJ:
case TP_HKEY_EV_WKUP_S4_BAYEJ:
hotkey_wakeup_reason = TP_ACPI_WAKEUP_BAYEJ;
*ignore_acpi_ev = true;
break;
case TP_HKEY_EV_WKUP_S3_BATLOW:
case TP_HKEY_EV_WKUP_S4_BATLOW:
pr_alert("EMERGENCY WAKEUP: battery almost empty\n");
break;
default:
return false;
}
if (hotkey_wakeup_reason != TP_ACPI_WAKEUP_NONE) {
pr_info("woke up due to a hot-unplug request...\n");
hotkey_wakeup_reason_notify_change();
}
return true;
}
static bool hotkey_notify_dockevent(const u32 hkey,
bool *send_acpi_ev,
bool *ignore_acpi_ev)
{
*send_acpi_ev = true;
*ignore_acpi_ev = false;
switch (hkey) {
case TP_HKEY_EV_UNDOCK_ACK:
hotkey_autosleep_ack = 1;
pr_info("undocked\n");
hotkey_wakeup_hotunplug_complete_notify_change();
return true;
case TP_HKEY_EV_HOTPLUG_DOCK:
pr_info("docked into hotplug port replicator\n");
return true;
case TP_HKEY_EV_HOTPLUG_UNDOCK:
pr_info("undocked from hotplug port replicator\n");
return true;
default:
return false;
}
}
static bool hotkey_notify_usrevent(const u32 hkey,
bool *send_acpi_ev,
bool *ignore_acpi_ev)
{
*send_acpi_ev = true;
*ignore_acpi_ev = false;
switch (hkey) {
case TP_HKEY_EV_PEN_INSERTED:
case TP_HKEY_EV_PEN_REMOVED:
return true;
case TP_HKEY_EV_TABLET_TABLET:
case TP_HKEY_EV_TABLET_NOTEBOOK:
tpacpi_input_send_tabletsw();
hotkey_tablet_mode_notify_change();
*send_acpi_ev = false;
return true;
case TP_HKEY_EV_LID_CLOSE:
case TP_HKEY_EV_LID_OPEN:
case TP_HKEY_EV_BRGHT_CHANGED:
*ignore_acpi_ev = true;
return true;
default:
return false;
}
}
static bool hotkey_notify_6xxx(const u32 hkey,
bool *send_acpi_ev,
bool *ignore_acpi_ev)
{
bool known = true;
*send_acpi_ev = true;
*ignore_acpi_ev = false;
switch (hkey) {
case TP_HKEY_EV_THM_TABLE_CHANGED:
pr_info("EC reports that Thermal Table has changed\n");
return true;
case TP_HKEY_EV_ALARM_BAT_HOT:
pr_crit("THERMAL ALARM: battery is too hot!\n");
break;
case TP_HKEY_EV_ALARM_BAT_XHOT:
pr_alert("THERMAL EMERGENCY: battery is extremely hot!\n");
break;
case TP_HKEY_EV_ALARM_SENSOR_HOT:
pr_crit("THERMAL ALARM: "
"a sensor reports something is too hot!\n");
break;
case TP_HKEY_EV_ALARM_SENSOR_XHOT:
pr_alert("THERMAL EMERGENCY: "
"a sensor reports something is extremely hot!\n");
break;
case TP_HKEY_EV_AC_CHANGED:
case TP_HKEY_EV_KEY_NUMLOCK:
case TP_HKEY_EV_KEY_FN:
*send_acpi_ev = false;
*ignore_acpi_ev = true;
return true;
default:
pr_warn("unknown possible thermal alarm or keyboard event received\n");
known = false;
}
thermal_dump_all_sensors();
return known;
}
static void hotkey_notify(struct ibm_struct *ibm, u32 event)
{
u32 hkey;
bool send_acpi_ev;
bool ignore_acpi_ev;
bool known_ev;
if (event != 0x80) {
pr_err("unknown HKEY notification event %d\n", event);
acpi_bus_generate_netlink_event(
ibm->acpi->device->pnp.device_class,
dev_name(&ibm->acpi->device->dev),
event, 0);
return;
}
while (1) {
if (!acpi_evalf(hkey_handle, &hkey, "MHKP", "d")) {
pr_err("failed to retrieve HKEY event\n");
return;
}
if (hkey == 0) {
return;
}
send_acpi_ev = true;
ignore_acpi_ev = false;
switch (hkey >> 12) {
case 1:
known_ev = hotkey_notify_hotkey(hkey, &send_acpi_ev,
&ignore_acpi_ev);
break;
case 2:
known_ev = hotkey_notify_wakeup(hkey, &send_acpi_ev,
&ignore_acpi_ev);
break;
case 3:
switch (hkey) {
case TP_HKEY_EV_BAYEJ_ACK:
hotkey_autosleep_ack = 1;
pr_info("bay ejected\n");
hotkey_wakeup_hotunplug_complete_notify_change();
known_ev = true;
break;
case TP_HKEY_EV_OPTDRV_EJ:
known_ev = true;
break;
default:
known_ev = false;
}
break;
case 4:
known_ev = hotkey_notify_dockevent(hkey, &send_acpi_ev,
&ignore_acpi_ev);
break;
case 5:
known_ev = hotkey_notify_usrevent(hkey, &send_acpi_ev,
&ignore_acpi_ev);
break;
case 6:
known_ev = hotkey_notify_6xxx(hkey, &send_acpi_ev,
&ignore_acpi_ev);
break;
case 7:
if (tp_features.hotkey_wlsw &&
hkey == TP_HKEY_EV_RFKILL_CHANGED) {
tpacpi_send_radiosw_update();
send_acpi_ev = 0;
known_ev = true;
break;
}
default:
known_ev = false;
}
if (!known_ev) {
pr_notice("unhandled HKEY event 0x%04x\n", hkey);
pr_notice("please report the conditions when this "
"event happened to %s\n", TPACPI_MAIL);
}
if (!ignore_acpi_ev && send_acpi_ev) {
acpi_bus_generate_netlink_event(
ibm->acpi->device->pnp.device_class,
dev_name(&ibm->acpi->device->dev),
event, hkey);
}
}
}
static void hotkey_suspend(void)
{
hotkey_wakeup_reason = TP_ACPI_WAKEUP_NONE;
hotkey_autosleep_ack = 0;
}
static void hotkey_resume(void)
{
tpacpi_disable_brightness_delay();
if (hotkey_status_set(true) < 0 ||
hotkey_mask_set(hotkey_acpi_mask) < 0)
pr_err("error while attempting to reset the event "
"firmware interface\n");
tpacpi_send_radiosw_update();
hotkey_tablet_mode_notify_change();
hotkey_wakeup_reason_notify_change();
hotkey_wakeup_hotunplug_complete_notify_change();
hotkey_poll_setup_safe(false);
}
static int hotkey_read(struct seq_file *m)
{
int res, status;
if (!tp_features.hotkey) {
seq_printf(m, "status:\t\tnot supported\n");
return 0;
}
if (mutex_lock_killable(&hotkey_mutex))
return -ERESTARTSYS;
res = hotkey_status_get(&status);
if (!res)
res = hotkey_mask_get();
mutex_unlock(&hotkey_mutex);
if (res)
return res;
seq_printf(m, "status:\t\t%s\n", enabled(status, 0));
if (hotkey_all_mask) {
seq_printf(m, "mask:\t\t0x%08x\n", hotkey_user_mask);
seq_printf(m, "commands:\tenable, disable, reset, <mask>\n");
} else {
seq_printf(m, "mask:\t\tnot supported\n");
seq_printf(m, "commands:\tenable, disable, reset\n");
}
return 0;
}
static void hotkey_enabledisable_warn(bool enable)
{
tpacpi_log_usertask("procfs hotkey enable/disable");
if (!WARN((tpacpi_lifecycle == TPACPI_LIFE_RUNNING || !enable),
pr_fmt("hotkey enable/disable functionality has been "
"removed from the driver. "
"Hotkeys are always enabled.\n")))
pr_err("Please remove the hotkey=enable module "
"parameter, it is deprecated. "
"Hotkeys are always enabled.\n");
}
static int hotkey_write(char *buf)
{
int res;
u32 mask;
char *cmd;
if (!tp_features.hotkey)
return -ENODEV;
if (mutex_lock_killable(&hotkey_mutex))
return -ERESTARTSYS;
mask = hotkey_user_mask;
res = 0;
while ((cmd = next_cmd(&buf))) {
if (strlencmp(cmd, "enable") == 0) {
hotkey_enabledisable_warn(1);
} else if (strlencmp(cmd, "disable") == 0) {
hotkey_enabledisable_warn(0);
res = -EPERM;
} else if (strlencmp(cmd, "reset") == 0) {
mask = (hotkey_all_mask | hotkey_source_mask)
& ~hotkey_reserved_mask;
} else if (sscanf(cmd, "0x%x", &mask) == 1) {
} else if (sscanf(cmd, "%x", &mask) == 1) {
} else {
res = -EINVAL;
goto errexit;
}
}
if (!res) {
tpacpi_disclose_usertask("procfs hotkey",
"set mask to 0x%08x\n", mask);
res = hotkey_user_mask_set(mask);
}
errexit:
mutex_unlock(&hotkey_mutex);
return res;
}
static int bluetooth_get_status(void)
{
int status;
#ifdef CONFIG_THINKPAD_ACPI_DEBUGFACILITIES
if (dbg_bluetoothemul)
return (tpacpi_bluetooth_emulstate) ?
TPACPI_RFK_RADIO_ON : TPACPI_RFK_RADIO_OFF;
#endif
if (!acpi_evalf(hkey_handle, &status, "GBDC", "d"))
return -EIO;
return ((status & TP_ACPI_BLUETOOTH_RADIOSSW) != 0) ?
TPACPI_RFK_RADIO_ON : TPACPI_RFK_RADIO_OFF;
}
static int bluetooth_set_status(enum tpacpi_rfkill_state state)
{
int status;
vdbg_printk(TPACPI_DBG_RFKILL,
"will attempt to %s bluetooth\n",
(state == TPACPI_RFK_RADIO_ON) ? "enable" : "disable");
#ifdef CONFIG_THINKPAD_ACPI_DEBUGFACILITIES
if (dbg_bluetoothemul) {
tpacpi_bluetooth_emulstate = (state == TPACPI_RFK_RADIO_ON);
return 0;
}
#endif
if (state == TPACPI_RFK_RADIO_ON)
status = TP_ACPI_BLUETOOTH_RADIOSSW
| TP_ACPI_BLUETOOTH_RESUMECTRL;
else
status = 0;
if (!acpi_evalf(hkey_handle, NULL, "SBDC", "vd", status))
return -EIO;
return 0;
}
static ssize_t bluetooth_enable_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return tpacpi_rfk_sysfs_enable_show(TPACPI_RFK_BLUETOOTH_SW_ID,
attr, buf);
}
static ssize_t bluetooth_enable_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return tpacpi_rfk_sysfs_enable_store(TPACPI_RFK_BLUETOOTH_SW_ID,
attr, buf, count);
}
static void bluetooth_shutdown(void)
{
if (!acpi_evalf(NULL, NULL, "\\BLTH", "vd",
TP_ACPI_BLTH_SAVE_STATE))
pr_notice("failed to save bluetooth state to NVRAM\n");
else
vdbg_printk(TPACPI_DBG_RFKILL,
"bluetooth state saved to NVRAM\n");
}
static void bluetooth_exit(void)
{
sysfs_remove_group(&tpacpi_pdev->dev.kobj,
&bluetooth_attr_group);
tpacpi_destroy_rfkill(TPACPI_RFK_BLUETOOTH_SW_ID);
bluetooth_shutdown();
}
static int __init bluetooth_init(struct ibm_init_struct *iibm)
{
int res;
int status = 0;
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_RFKILL,
"initializing bluetooth subdriver\n");
TPACPI_ACPIHANDLE_INIT(hkey);
tp_features.bluetooth = hkey_handle &&
acpi_evalf(hkey_handle, &status, "GBDC", "qd");
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_RFKILL,
"bluetooth is %s, status 0x%02x\n",
str_supported(tp_features.bluetooth),
status);
#ifdef CONFIG_THINKPAD_ACPI_DEBUGFACILITIES
if (dbg_bluetoothemul) {
tp_features.bluetooth = 1;
pr_info("bluetooth switch emulation enabled\n");
} else
#endif
if (tp_features.bluetooth &&
!(status & TP_ACPI_BLUETOOTH_HWPRESENT)) {
tp_features.bluetooth = 0;
dbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_RFKILL,
"bluetooth hardware not installed\n");
}
if (!tp_features.bluetooth)
return 1;
res = tpacpi_new_rfkill(TPACPI_RFK_BLUETOOTH_SW_ID,
&bluetooth_tprfk_ops,
RFKILL_TYPE_BLUETOOTH,
TPACPI_RFK_BLUETOOTH_SW_NAME,
true);
if (res)
return res;
res = sysfs_create_group(&tpacpi_pdev->dev.kobj,
&bluetooth_attr_group);
if (res) {
tpacpi_destroy_rfkill(TPACPI_RFK_BLUETOOTH_SW_ID);
return res;
}
return 0;
}
static int bluetooth_read(struct seq_file *m)
{
return tpacpi_rfk_procfs_read(TPACPI_RFK_BLUETOOTH_SW_ID, m);
}
static int bluetooth_write(char *buf)
{
return tpacpi_rfk_procfs_write(TPACPI_RFK_BLUETOOTH_SW_ID, buf);
}
static int wan_get_status(void)
{
int status;
#ifdef CONFIG_THINKPAD_ACPI_DEBUGFACILITIES
if (dbg_wwanemul)
return (tpacpi_wwan_emulstate) ?
TPACPI_RFK_RADIO_ON : TPACPI_RFK_RADIO_OFF;
#endif
if (!acpi_evalf(hkey_handle, &status, "GWAN", "d"))
return -EIO;
return ((status & TP_ACPI_WANCARD_RADIOSSW) != 0) ?
TPACPI_RFK_RADIO_ON : TPACPI_RFK_RADIO_OFF;
}
static int wan_set_status(enum tpacpi_rfkill_state state)
{
int status;
vdbg_printk(TPACPI_DBG_RFKILL,
"will attempt to %s wwan\n",
(state == TPACPI_RFK_RADIO_ON) ? "enable" : "disable");
#ifdef CONFIG_THINKPAD_ACPI_DEBUGFACILITIES
if (dbg_wwanemul) {
tpacpi_wwan_emulstate = (state == TPACPI_RFK_RADIO_ON);
return 0;
}
#endif
if (state == TPACPI_RFK_RADIO_ON)
status = TP_ACPI_WANCARD_RADIOSSW
| TP_ACPI_WANCARD_RESUMECTRL;
else
status = 0;
if (!acpi_evalf(hkey_handle, NULL, "SWAN", "vd", status))
return -EIO;
return 0;
}
static ssize_t wan_enable_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return tpacpi_rfk_sysfs_enable_show(TPACPI_RFK_WWAN_SW_ID,
attr, buf);
}
static ssize_t wan_enable_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return tpacpi_rfk_sysfs_enable_store(TPACPI_RFK_WWAN_SW_ID,
attr, buf, count);
}
static void wan_shutdown(void)
{
if (!acpi_evalf(NULL, NULL, "\\WGSV", "vd",
TP_ACPI_WGSV_SAVE_STATE))
pr_notice("failed to save WWAN state to NVRAM\n");
else
vdbg_printk(TPACPI_DBG_RFKILL,
"WWAN state saved to NVRAM\n");
}
static void wan_exit(void)
{
sysfs_remove_group(&tpacpi_pdev->dev.kobj,
&wan_attr_group);
tpacpi_destroy_rfkill(TPACPI_RFK_WWAN_SW_ID);
wan_shutdown();
}
static int __init wan_init(struct ibm_init_struct *iibm)
{
int res;
int status = 0;
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_RFKILL,
"initializing wan subdriver\n");
TPACPI_ACPIHANDLE_INIT(hkey);
tp_features.wan = hkey_handle &&
acpi_evalf(hkey_handle, &status, "GWAN", "qd");
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_RFKILL,
"wan is %s, status 0x%02x\n",
str_supported(tp_features.wan),
status);
#ifdef CONFIG_THINKPAD_ACPI_DEBUGFACILITIES
if (dbg_wwanemul) {
tp_features.wan = 1;
pr_info("wwan switch emulation enabled\n");
} else
#endif
if (tp_features.wan &&
!(status & TP_ACPI_WANCARD_HWPRESENT)) {
tp_features.wan = 0;
dbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_RFKILL,
"wan hardware not installed\n");
}
if (!tp_features.wan)
return 1;
res = tpacpi_new_rfkill(TPACPI_RFK_WWAN_SW_ID,
&wan_tprfk_ops,
RFKILL_TYPE_WWAN,
TPACPI_RFK_WWAN_SW_NAME,
true);
if (res)
return res;
res = sysfs_create_group(&tpacpi_pdev->dev.kobj,
&wan_attr_group);
if (res) {
tpacpi_destroy_rfkill(TPACPI_RFK_WWAN_SW_ID);
return res;
}
return 0;
}
static int wan_read(struct seq_file *m)
{
return tpacpi_rfk_procfs_read(TPACPI_RFK_WWAN_SW_ID, m);
}
static int wan_write(char *buf)
{
return tpacpi_rfk_procfs_write(TPACPI_RFK_WWAN_SW_ID, buf);
}
static int uwb_get_status(void)
{
int status;
#ifdef CONFIG_THINKPAD_ACPI_DEBUGFACILITIES
if (dbg_uwbemul)
return (tpacpi_uwb_emulstate) ?
TPACPI_RFK_RADIO_ON : TPACPI_RFK_RADIO_OFF;
#endif
if (!acpi_evalf(hkey_handle, &status, "GUWB", "d"))
return -EIO;
return ((status & TP_ACPI_UWB_RADIOSSW) != 0) ?
TPACPI_RFK_RADIO_ON : TPACPI_RFK_RADIO_OFF;
}
static int uwb_set_status(enum tpacpi_rfkill_state state)
{
int status;
vdbg_printk(TPACPI_DBG_RFKILL,
"will attempt to %s UWB\n",
(state == TPACPI_RFK_RADIO_ON) ? "enable" : "disable");
#ifdef CONFIG_THINKPAD_ACPI_DEBUGFACILITIES
if (dbg_uwbemul) {
tpacpi_uwb_emulstate = (state == TPACPI_RFK_RADIO_ON);
return 0;
}
#endif
if (state == TPACPI_RFK_RADIO_ON)
status = TP_ACPI_UWB_RADIOSSW;
else
status = 0;
if (!acpi_evalf(hkey_handle, NULL, "SUWB", "vd", status))
return -EIO;
return 0;
}
static void uwb_exit(void)
{
tpacpi_destroy_rfkill(TPACPI_RFK_UWB_SW_ID);
}
static int __init uwb_init(struct ibm_init_struct *iibm)
{
int res;
int status = 0;
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_RFKILL,
"initializing uwb subdriver\n");
TPACPI_ACPIHANDLE_INIT(hkey);
tp_features.uwb = hkey_handle &&
acpi_evalf(hkey_handle, &status, "GUWB", "qd");
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_RFKILL,
"uwb is %s, status 0x%02x\n",
str_supported(tp_features.uwb),
status);
#ifdef CONFIG_THINKPAD_ACPI_DEBUGFACILITIES
if (dbg_uwbemul) {
tp_features.uwb = 1;
pr_info("uwb switch emulation enabled\n");
} else
#endif
if (tp_features.uwb &&
!(status & TP_ACPI_UWB_HWPRESENT)) {
tp_features.uwb = 0;
dbg_printk(TPACPI_DBG_INIT,
"uwb hardware not installed\n");
}
if (!tp_features.uwb)
return 1;
res = tpacpi_new_rfkill(TPACPI_RFK_UWB_SW_ID,
&uwb_tprfk_ops,
RFKILL_TYPE_UWB,
TPACPI_RFK_UWB_SW_NAME,
false);
return res;
}
static int __init video_init(struct ibm_init_struct *iibm)
{
int ivga;
vdbg_printk(TPACPI_DBG_INIT, "initializing video subdriver\n");
TPACPI_ACPIHANDLE_INIT(vid);
if (tpacpi_is_ibm())
TPACPI_ACPIHANDLE_INIT(vid2);
if (vid2_handle && acpi_evalf(NULL, &ivga, "\\IVGA", "d") && ivga)
vid_handle = vid2_handle;
if (!vid_handle)
video_supported = TPACPI_VIDEO_NONE;
else if (tpacpi_is_ibm() &&
acpi_evalf(vid_handle, &video_orig_autosw, "SWIT", "qd"))
video_supported = TPACPI_VIDEO_570;
else if (tpacpi_is_ibm() &&
acpi_evalf(vid_handle, &video_orig_autosw, "^VADL", "qd"))
video_supported = TPACPI_VIDEO_770;
else
video_supported = TPACPI_VIDEO_NEW;
vdbg_printk(TPACPI_DBG_INIT, "video is %s, mode %d\n",
str_supported(video_supported != TPACPI_VIDEO_NONE),
video_supported);
return (video_supported != TPACPI_VIDEO_NONE)? 0 : 1;
}
static void video_exit(void)
{
dbg_printk(TPACPI_DBG_EXIT,
"restoring original video autoswitch mode\n");
if (video_autosw_set(video_orig_autosw))
pr_err("error while trying to restore original "
"video autoswitch mode\n");
}
static int video_outputsw_get(void)
{
int status = 0;
int i;
switch (video_supported) {
case TPACPI_VIDEO_570:
if (!acpi_evalf(NULL, &i, "\\_SB.PHS", "dd",
TP_ACPI_VIDEO_570_PHSCMD))
return -EIO;
status = i & TP_ACPI_VIDEO_570_PHSMASK;
break;
case TPACPI_VIDEO_770:
if (!acpi_evalf(NULL, &i, "\\VCDL", "d"))
return -EIO;
if (i)
status |= TP_ACPI_VIDEO_S_LCD;
if (!acpi_evalf(NULL, &i, "\\VCDC", "d"))
return -EIO;
if (i)
status |= TP_ACPI_VIDEO_S_CRT;
break;
case TPACPI_VIDEO_NEW:
if (!acpi_evalf(NULL, NULL, "\\VUPS", "vd", 1) ||
!acpi_evalf(NULL, &i, "\\VCDC", "d"))
return -EIO;
if (i)
status |= TP_ACPI_VIDEO_S_CRT;
if (!acpi_evalf(NULL, NULL, "\\VUPS", "vd", 0) ||
!acpi_evalf(NULL, &i, "\\VCDL", "d"))
return -EIO;
if (i)
status |= TP_ACPI_VIDEO_S_LCD;
if (!acpi_evalf(NULL, &i, "\\VCDD", "d"))
return -EIO;
if (i)
status |= TP_ACPI_VIDEO_S_DVI;
break;
default:
return -ENOSYS;
}
return status;
}
static int video_outputsw_set(int status)
{
int autosw;
int res = 0;
switch (video_supported) {
case TPACPI_VIDEO_570:
res = acpi_evalf(NULL, NULL,
"\\_SB.PHS2", "vdd",
TP_ACPI_VIDEO_570_PHS2CMD,
status | TP_ACPI_VIDEO_570_PHS2SET);
break;
case TPACPI_VIDEO_770:
autosw = video_autosw_get();
if (autosw < 0)
return autosw;
res = video_autosw_set(1);
if (res)
return res;
res = acpi_evalf(vid_handle, NULL,
"ASWT", "vdd", status * 0x100, 0);
if (!autosw && video_autosw_set(autosw)) {
pr_err("video auto-switch left enabled due to error\n");
return -EIO;
}
break;
case TPACPI_VIDEO_NEW:
res = acpi_evalf(NULL, NULL, "\\VUPS", "vd", 0x80) &&
acpi_evalf(NULL, NULL, "\\VSDS", "vdd", status, 1);
break;
default:
return -ENOSYS;
}
return (res)? 0 : -EIO;
}
static int video_autosw_get(void)
{
int autosw = 0;
switch (video_supported) {
case TPACPI_VIDEO_570:
if (!acpi_evalf(vid_handle, &autosw, "SWIT", "d"))
return -EIO;
break;
case TPACPI_VIDEO_770:
case TPACPI_VIDEO_NEW:
if (!acpi_evalf(vid_handle, &autosw, "^VDEE", "d"))
return -EIO;
break;
default:
return -ENOSYS;
}
return autosw & 1;
}
static int video_autosw_set(int enable)
{
if (!acpi_evalf(vid_handle, NULL, "_DOS", "vd", (enable)? 1 : 0))
return -EIO;
return 0;
}
static int video_outputsw_cycle(void)
{
int autosw = video_autosw_get();
int res;
if (autosw < 0)
return autosw;
switch (video_supported) {
case TPACPI_VIDEO_570:
res = video_autosw_set(1);
if (res)
return res;
res = acpi_evalf(ec_handle, NULL, "_Q16", "v");
break;
case TPACPI_VIDEO_770:
case TPACPI_VIDEO_NEW:
res = video_autosw_set(1);
if (res)
return res;
res = acpi_evalf(vid_handle, NULL, "VSWT", "v");
break;
default:
return -ENOSYS;
}
if (!autosw && video_autosw_set(autosw)) {
pr_err("video auto-switch left enabled due to error\n");
return -EIO;
}
return (res)? 0 : -EIO;
}
static int video_expand_toggle(void)
{
switch (video_supported) {
case TPACPI_VIDEO_570:
return acpi_evalf(ec_handle, NULL, "_Q17", "v")?
0 : -EIO;
case TPACPI_VIDEO_770:
return acpi_evalf(vid_handle, NULL, "VEXP", "v")?
0 : -EIO;
case TPACPI_VIDEO_NEW:
return acpi_evalf(NULL, NULL, "\\VEXP", "v")?
0 : -EIO;
default:
return -ENOSYS;
}
}
static int video_read(struct seq_file *m)
{
int status, autosw;
if (video_supported == TPACPI_VIDEO_NONE) {
seq_printf(m, "status:\t\tnot supported\n");
return 0;
}
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
status = video_outputsw_get();
if (status < 0)
return status;
autosw = video_autosw_get();
if (autosw < 0)
return autosw;
seq_printf(m, "status:\t\tsupported\n");
seq_printf(m, "lcd:\t\t%s\n", enabled(status, 0));
seq_printf(m, "crt:\t\t%s\n", enabled(status, 1));
if (video_supported == TPACPI_VIDEO_NEW)
seq_printf(m, "dvi:\t\t%s\n", enabled(status, 3));
seq_printf(m, "auto:\t\t%s\n", enabled(autosw, 0));
seq_printf(m, "commands:\tlcd_enable, lcd_disable\n");
seq_printf(m, "commands:\tcrt_enable, crt_disable\n");
if (video_supported == TPACPI_VIDEO_NEW)
seq_printf(m, "commands:\tdvi_enable, dvi_disable\n");
seq_printf(m, "commands:\tauto_enable, auto_disable\n");
seq_printf(m, "commands:\tvideo_switch, expand_toggle\n");
return 0;
}
static int video_write(char *buf)
{
char *cmd;
int enable, disable, status;
int res;
if (video_supported == TPACPI_VIDEO_NONE)
return -ENODEV;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
enable = 0;
disable = 0;
while ((cmd = next_cmd(&buf))) {
if (strlencmp(cmd, "lcd_enable") == 0) {
enable |= TP_ACPI_VIDEO_S_LCD;
} else if (strlencmp(cmd, "lcd_disable") == 0) {
disable |= TP_ACPI_VIDEO_S_LCD;
} else if (strlencmp(cmd, "crt_enable") == 0) {
enable |= TP_ACPI_VIDEO_S_CRT;
} else if (strlencmp(cmd, "crt_disable") == 0) {
disable |= TP_ACPI_VIDEO_S_CRT;
} else if (video_supported == TPACPI_VIDEO_NEW &&
strlencmp(cmd, "dvi_enable") == 0) {
enable |= TP_ACPI_VIDEO_S_DVI;
} else if (video_supported == TPACPI_VIDEO_NEW &&
strlencmp(cmd, "dvi_disable") == 0) {
disable |= TP_ACPI_VIDEO_S_DVI;
} else if (strlencmp(cmd, "auto_enable") == 0) {
res = video_autosw_set(1);
if (res)
return res;
} else if (strlencmp(cmd, "auto_disable") == 0) {
res = video_autosw_set(0);
if (res)
return res;
} else if (strlencmp(cmd, "video_switch") == 0) {
res = video_outputsw_cycle();
if (res)
return res;
} else if (strlencmp(cmd, "expand_toggle") == 0) {
res = video_expand_toggle();
if (res)
return res;
} else
return -EINVAL;
}
if (enable || disable) {
status = video_outputsw_get();
if (status < 0)
return status;
res = video_outputsw_set((status & ~disable) | enable);
if (res)
return res;
}
return 0;
}
static int light_get_status(void)
{
int status = 0;
if (tp_features.light_status) {
if (!acpi_evalf(ec_handle, &status, "KBLT", "d"))
return -EIO;
return (!!status);
}
return -ENXIO;
}
static int light_set_status(int status)
{
int rc;
if (tp_features.light) {
if (cmos_handle) {
rc = acpi_evalf(cmos_handle, NULL, NULL, "vd",
(status)?
TP_CMOS_THINKLIGHT_ON :
TP_CMOS_THINKLIGHT_OFF);
} else {
rc = acpi_evalf(lght_handle, NULL, NULL, "vd",
(status)? 1 : 0);
}
return (rc)? 0 : -EIO;
}
return -ENXIO;
}
static void light_set_status_worker(struct work_struct *work)
{
struct tpacpi_led_classdev *data =
container_of(work, struct tpacpi_led_classdev, work);
if (likely(tpacpi_lifecycle == TPACPI_LIFE_RUNNING))
light_set_status((data->new_state != TPACPI_LED_OFF));
}
static void light_sysfs_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct tpacpi_led_classdev *data =
container_of(led_cdev,
struct tpacpi_led_classdev,
led_classdev);
data->new_state = (brightness != LED_OFF) ?
TPACPI_LED_ON : TPACPI_LED_OFF;
queue_work(tpacpi_wq, &data->work);
}
static enum led_brightness light_sysfs_get(struct led_classdev *led_cdev)
{
return (light_get_status() == 1)? LED_FULL : LED_OFF;
}
static int __init light_init(struct ibm_init_struct *iibm)
{
int rc;
vdbg_printk(TPACPI_DBG_INIT, "initializing light subdriver\n");
if (tpacpi_is_ibm()) {
TPACPI_ACPIHANDLE_INIT(ledb);
TPACPI_ACPIHANDLE_INIT(lght);
}
TPACPI_ACPIHANDLE_INIT(cmos);
INIT_WORK(&tpacpi_led_thinklight.work, light_set_status_worker);
tp_features.light = (cmos_handle || lght_handle) && !ledb_handle;
if (tp_features.light)
tp_features.light_status =
acpi_evalf(ec_handle, NULL, "KBLT", "qv");
vdbg_printk(TPACPI_DBG_INIT, "light is %s, light status is %s\n",
str_supported(tp_features.light),
str_supported(tp_features.light_status));
if (!tp_features.light)
return 1;
rc = led_classdev_register(&tpacpi_pdev->dev,
&tpacpi_led_thinklight.led_classdev);
if (rc < 0) {
tp_features.light = 0;
tp_features.light_status = 0;
} else {
rc = 0;
}
return rc;
}
static void light_exit(void)
{
led_classdev_unregister(&tpacpi_led_thinklight.led_classdev);
flush_workqueue(tpacpi_wq);
}
static int light_read(struct seq_file *m)
{
int status;
if (!tp_features.light) {
seq_printf(m, "status:\t\tnot supported\n");
} else if (!tp_features.light_status) {
seq_printf(m, "status:\t\tunknown\n");
seq_printf(m, "commands:\ton, off\n");
} else {
status = light_get_status();
if (status < 0)
return status;
seq_printf(m, "status:\t\t%s\n", onoff(status, 0));
seq_printf(m, "commands:\ton, off\n");
}
return 0;
}
static int light_write(char *buf)
{
char *cmd;
int newstatus = 0;
if (!tp_features.light)
return -ENODEV;
while ((cmd = next_cmd(&buf))) {
if (strlencmp(cmd, "on") == 0) {
newstatus = 1;
} else if (strlencmp(cmd, "off") == 0) {
newstatus = 0;
} else
return -EINVAL;
}
return light_set_status(newstatus);
}
static ssize_t cmos_command_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned long cmos_cmd;
int res;
if (parse_strtoul(buf, 21, &cmos_cmd))
return -EINVAL;
res = issue_thinkpad_cmos_command(cmos_cmd);
return (res)? res : count;
}
static int __init cmos_init(struct ibm_init_struct *iibm)
{
int res;
vdbg_printk(TPACPI_DBG_INIT,
"initializing cmos commands subdriver\n");
TPACPI_ACPIHANDLE_INIT(cmos);
vdbg_printk(TPACPI_DBG_INIT, "cmos commands are %s\n",
str_supported(cmos_handle != NULL));
res = device_create_file(&tpacpi_pdev->dev, &dev_attr_cmos_command);
if (res)
return res;
return (cmos_handle)? 0 : 1;
}
static void cmos_exit(void)
{
device_remove_file(&tpacpi_pdev->dev, &dev_attr_cmos_command);
}
static int cmos_read(struct seq_file *m)
{
if (!cmos_handle)
seq_printf(m, "status:\t\tnot supported\n");
else {
seq_printf(m, "status:\t\tsupported\n");
seq_printf(m, "commands:\t<cmd> (<cmd> is 0-21)\n");
}
return 0;
}
static int cmos_write(char *buf)
{
char *cmd;
int cmos_cmd, res;
while ((cmd = next_cmd(&buf))) {
if (sscanf(cmd, "%u", &cmos_cmd) == 1 &&
cmos_cmd >= 0 && cmos_cmd <= 21) {
} else
return -EINVAL;
res = issue_thinkpad_cmos_command(cmos_cmd);
if (res)
return res;
}
return 0;
}
static inline bool tpacpi_is_led_restricted(const unsigned int led)
{
#ifdef CONFIG_THINKPAD_ACPI_UNSAFE_LEDS
return false;
#else
return (1U & (TPACPI_SAFE_LEDS >> led)) == 0;
#endif
}
static int led_get_status(const unsigned int led)
{
int status;
enum led_status_t led_s;
switch (led_supported) {
case TPACPI_LED_570:
if (!acpi_evalf(ec_handle,
&status, "GLED", "dd", 1 << led))
return -EIO;
led_s = (status == 0)?
TPACPI_LED_OFF :
((status == 1)?
TPACPI_LED_ON :
TPACPI_LED_BLINK);
tpacpi_led_state_cache[led] = led_s;
return led_s;
default:
return -ENXIO;
}
}
static int led_set_status(const unsigned int led,
const enum led_status_t ledstatus)
{
static const unsigned int led_sled_arg1[] = { 0, 1, 3 };
static const unsigned int led_led_arg1[] = { 0, 0x80, 0xc0 };
int rc = 0;
switch (led_supported) {
case TPACPI_LED_570:
if (unlikely(led > 7))
return -EINVAL;
if (unlikely(tpacpi_is_led_restricted(led)))
return -EPERM;
if (!acpi_evalf(led_handle, NULL, NULL, "vdd",
(1 << led), led_sled_arg1[ledstatus]))
rc = -EIO;
break;
case TPACPI_LED_OLD:
if (unlikely(led > 7))
return -EINVAL;
if (unlikely(tpacpi_is_led_restricted(led)))
return -EPERM;
rc = ec_write(TPACPI_LED_EC_HLMS, (1 << led));
if (rc >= 0)
rc = ec_write(TPACPI_LED_EC_HLBL,
(ledstatus == TPACPI_LED_BLINK) << led);
if (rc >= 0)
rc = ec_write(TPACPI_LED_EC_HLCL,
(ledstatus != TPACPI_LED_OFF) << led);
break;
case TPACPI_LED_NEW:
if (unlikely(led >= TPACPI_LED_NUMLEDS))
return -EINVAL;
if (unlikely(tpacpi_is_led_restricted(led)))
return -EPERM;
if (!acpi_evalf(led_handle, NULL, NULL, "vdd",
led, led_led_arg1[ledstatus]))
rc = -EIO;
break;
default:
rc = -ENXIO;
}
if (!rc)
tpacpi_led_state_cache[led] = ledstatus;
return rc;
}
static void led_set_status_worker(struct work_struct *work)
{
struct tpacpi_led_classdev *data =
container_of(work, struct tpacpi_led_classdev, work);
if (likely(tpacpi_lifecycle == TPACPI_LIFE_RUNNING))
led_set_status(data->led, data->new_state);
}
static void led_sysfs_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct tpacpi_led_classdev *data = container_of(led_cdev,
struct tpacpi_led_classdev, led_classdev);
if (brightness == LED_OFF)
data->new_state = TPACPI_LED_OFF;
else if (tpacpi_led_state_cache[data->led] != TPACPI_LED_BLINK)
data->new_state = TPACPI_LED_ON;
else
data->new_state = TPACPI_LED_BLINK;
queue_work(tpacpi_wq, &data->work);
}
static int led_sysfs_blink_set(struct led_classdev *led_cdev,
unsigned long *delay_on, unsigned long *delay_off)
{
struct tpacpi_led_classdev *data = container_of(led_cdev,
struct tpacpi_led_classdev, led_classdev);
if (*delay_on == 0 && *delay_off == 0) {
*delay_on = 500;
*delay_off = 500;
} else if ((*delay_on != 500) || (*delay_off != 500))
return -EINVAL;
data->new_state = TPACPI_LED_BLINK;
queue_work(tpacpi_wq, &data->work);
return 0;
}
static enum led_brightness led_sysfs_get(struct led_classdev *led_cdev)
{
int rc;
struct tpacpi_led_classdev *data = container_of(led_cdev,
struct tpacpi_led_classdev, led_classdev);
rc = led_get_status(data->led);
if (rc == TPACPI_LED_OFF || rc < 0)
rc = LED_OFF;
else
rc = LED_FULL;
return rc;
}
static void led_exit(void)
{
unsigned int i;
for (i = 0; i < TPACPI_LED_NUMLEDS; i++) {
if (tpacpi_leds[i].led_classdev.name)
led_classdev_unregister(&tpacpi_leds[i].led_classdev);
}
flush_workqueue(tpacpi_wq);
kfree(tpacpi_leds);
}
static int __init tpacpi_init_led(unsigned int led)
{
int rc;
tpacpi_leds[led].led = led;
if (!tpacpi_led_names[led])
return 0;
tpacpi_leds[led].led_classdev.brightness_set = &led_sysfs_set;
tpacpi_leds[led].led_classdev.blink_set = &led_sysfs_blink_set;
if (led_supported == TPACPI_LED_570)
tpacpi_leds[led].led_classdev.brightness_get =
&led_sysfs_get;
tpacpi_leds[led].led_classdev.name = tpacpi_led_names[led];
INIT_WORK(&tpacpi_leds[led].work, led_set_status_worker);
rc = led_classdev_register(&tpacpi_pdev->dev,
&tpacpi_leds[led].led_classdev);
if (rc < 0)
tpacpi_leds[led].led_classdev.name = NULL;
return rc;
}
static enum led_access_mode __init led_init_detect_mode(void)
{
acpi_status status;
if (tpacpi_is_ibm()) {
status = acpi_get_handle(ec_handle, "SLED", &led_handle);
if (ACPI_SUCCESS(status))
return TPACPI_LED_570;
status = acpi_get_handle(ec_handle, "SYSL", &led_handle);
if (ACPI_SUCCESS(status))
return TPACPI_LED_OLD;
}
status = acpi_get_handle(ec_handle, "LED", &led_handle);
if (ACPI_SUCCESS(status))
return TPACPI_LED_NEW;
led_handle = NULL;
return TPACPI_LED_NONE;
}
static int __init led_init(struct ibm_init_struct *iibm)
{
unsigned int i;
int rc;
unsigned long useful_leds;
vdbg_printk(TPACPI_DBG_INIT, "initializing LED subdriver\n");
led_supported = led_init_detect_mode();
if (led_supported != TPACPI_LED_NONE) {
useful_leds = tpacpi_check_quirks(led_useful_qtable,
ARRAY_SIZE(led_useful_qtable));
if (!useful_leds) {
led_handle = NULL;
led_supported = TPACPI_LED_NONE;
}
}
vdbg_printk(TPACPI_DBG_INIT, "LED commands are %s, mode %d\n",
str_supported(led_supported), led_supported);
if (led_supported == TPACPI_LED_NONE)
return 1;
tpacpi_leds = kzalloc(sizeof(*tpacpi_leds) * TPACPI_LED_NUMLEDS,
GFP_KERNEL);
if (!tpacpi_leds) {
pr_err("Out of memory for LED data\n");
return -ENOMEM;
}
for (i = 0; i < TPACPI_LED_NUMLEDS; i++) {
tpacpi_leds[i].led = -1;
if (!tpacpi_is_led_restricted(i) &&
test_bit(i, &useful_leds)) {
rc = tpacpi_init_led(i);
if (rc < 0) {
led_exit();
return rc;
}
}
}
#ifdef CONFIG_THINKPAD_ACPI_UNSAFE_LEDS
pr_notice("warning: userspace override of important "
"firmware LEDs is enabled\n");
#endif
return 0;
}
static int led_read(struct seq_file *m)
{
if (!led_supported) {
seq_printf(m, "status:\t\tnot supported\n");
return 0;
}
seq_printf(m, "status:\t\tsupported\n");
if (led_supported == TPACPI_LED_570) {
int i, status;
for (i = 0; i < 8; i++) {
status = led_get_status(i);
if (status < 0)
return -EIO;
seq_printf(m, "%d:\t\t%s\n",
i, str_led_status(status));
}
}
seq_printf(m, "commands:\t"
"<led> on, <led> off, <led> blink (<led> is 0-15)\n");
return 0;
}
static int led_write(char *buf)
{
char *cmd;
int led, rc;
enum led_status_t s;
if (!led_supported)
return -ENODEV;
while ((cmd = next_cmd(&buf))) {
if (sscanf(cmd, "%d", &led) != 1)
return -EINVAL;
if (led < 0 || led > (TPACPI_LED_NUMLEDS - 1) ||
tpacpi_leds[led].led < 0)
return -ENODEV;
if (strstr(cmd, "off")) {
s = TPACPI_LED_OFF;
} else if (strstr(cmd, "on")) {
s = TPACPI_LED_ON;
} else if (strstr(cmd, "blink")) {
s = TPACPI_LED_BLINK;
} else {
return -EINVAL;
}
rc = led_set_status(led, s);
if (rc < 0)
return rc;
}
return 0;
}
static int __init beep_init(struct ibm_init_struct *iibm)
{
unsigned long quirks;
vdbg_printk(TPACPI_DBG_INIT, "initializing beep subdriver\n");
TPACPI_ACPIHANDLE_INIT(beep);
vdbg_printk(TPACPI_DBG_INIT, "beep is %s\n",
str_supported(beep_handle != NULL));
quirks = tpacpi_check_quirks(beep_quirk_table,
ARRAY_SIZE(beep_quirk_table));
tp_features.beep_needs_two_args = !!(quirks & TPACPI_BEEP_Q1);
return (beep_handle)? 0 : 1;
}
static int beep_read(struct seq_file *m)
{
if (!beep_handle)
seq_printf(m, "status:\t\tnot supported\n");
else {
seq_printf(m, "status:\t\tsupported\n");
seq_printf(m, "commands:\t<cmd> (<cmd> is 0-17)\n");
}
return 0;
}
static int beep_write(char *buf)
{
char *cmd;
int beep_cmd;
if (!beep_handle)
return -ENODEV;
while ((cmd = next_cmd(&buf))) {
if (sscanf(cmd, "%u", &beep_cmd) == 1 &&
beep_cmd >= 0 && beep_cmd <= 17) {
} else
return -EINVAL;
if (tp_features.beep_needs_two_args) {
if (!acpi_evalf(beep_handle, NULL, NULL, "vdd",
beep_cmd, 0))
return -EIO;
} else {
if (!acpi_evalf(beep_handle, NULL, NULL, "vd",
beep_cmd))
return -EIO;
}
}
return 0;
}
static int thermal_get_sensor(int idx, s32 *value)
{
int t;
s8 tmp;
char tmpi[5];
t = TP_EC_THERMAL_TMP0;
switch (thermal_read_mode) {
#if TPACPI_MAX_THERMAL_SENSORS >= 16
case TPACPI_THERMAL_TPEC_16:
if (idx >= 8 && idx <= 15) {
t = TP_EC_THERMAL_TMP8;
idx -= 8;
}
#endif
case TPACPI_THERMAL_TPEC_8:
if (idx <= 7) {
if (!acpi_ec_read(t + idx, &tmp))
return -EIO;
*value = tmp * 1000;
return 0;
}
break;
case TPACPI_THERMAL_ACPI_UPDT:
if (idx <= 7) {
snprintf(tmpi, sizeof(tmpi), "TMP%c", '0' + idx);
if (!acpi_evalf(ec_handle, NULL, "UPDT", "v"))
return -EIO;
if (!acpi_evalf(ec_handle, &t, tmpi, "d"))
return -EIO;
*value = (t - 2732) * 100;
return 0;
}
break;
case TPACPI_THERMAL_ACPI_TMP07:
if (idx <= 7) {
snprintf(tmpi, sizeof(tmpi), "TMP%c", '0' + idx);
if (!acpi_evalf(ec_handle, &t, tmpi, "d"))
return -EIO;
if (t > 127 || t < -127)
t = TP_EC_THERMAL_TMP_NA;
*value = t * 1000;
return 0;
}
break;
case TPACPI_THERMAL_NONE:
default:
return -ENOSYS;
}
return -EINVAL;
}
static int thermal_get_sensors(struct ibm_thermal_sensors_struct *s)
{
int res, i;
int n;
n = 8;
i = 0;
if (!s)
return -EINVAL;
if (thermal_read_mode == TPACPI_THERMAL_TPEC_16)
n = 16;
for (i = 0 ; i < n; i++) {
res = thermal_get_sensor(i, &s->temp[i]);
if (res)
return res;
}
return n;
}
static void thermal_dump_all_sensors(void)
{
int n, i;
struct ibm_thermal_sensors_struct t;
n = thermal_get_sensors(&t);
if (n <= 0)
return;
pr_notice("temperatures (Celsius):");
for (i = 0; i < n; i++) {
if (t.temp[i] != TPACPI_THERMAL_SENSOR_NA)
pr_cont(" %d", (int)(t.temp[i] / 1000));
else
pr_cont(" N/A");
}
pr_cont("\n");
}
static ssize_t thermal_temp_input_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr =
to_sensor_dev_attr(attr);
int idx = sensor_attr->index;
s32 value;
int res;
res = thermal_get_sensor(idx, &value);
if (res)
return res;
if (value == TPACPI_THERMAL_SENSOR_NA)
return -ENXIO;
return snprintf(buf, PAGE_SIZE, "%d\n", value);
}
static int __init thermal_init(struct ibm_init_struct *iibm)
{
u8 t, ta1, ta2;
int i;
int acpi_tmp7;
int res;
vdbg_printk(TPACPI_DBG_INIT, "initializing thermal subdriver\n");
acpi_tmp7 = acpi_evalf(ec_handle, NULL, "TMP7", "qv");
if (thinkpad_id.ec_model) {
ta1 = ta2 = 0;
for (i = 0; i < 8; i++) {
if (acpi_ec_read(TP_EC_THERMAL_TMP0 + i, &t)) {
ta1 |= t;
} else {
ta1 = 0;
break;
}
if (acpi_ec_read(TP_EC_THERMAL_TMP8 + i, &t)) {
ta2 |= t;
} else {
ta1 = 0;
break;
}
}
if (ta1 == 0) {
if (acpi_tmp7) {
pr_err("ThinkPad ACPI EC access misbehaving, "
"falling back to ACPI TMPx access "
"mode\n");
thermal_read_mode = TPACPI_THERMAL_ACPI_TMP07;
} else {
pr_err("ThinkPad ACPI EC access misbehaving, "
"disabling thermal sensors access\n");
thermal_read_mode = TPACPI_THERMAL_NONE;
}
} else {
thermal_read_mode =
(ta2 != 0) ?
TPACPI_THERMAL_TPEC_16 : TPACPI_THERMAL_TPEC_8;
}
} else if (acpi_tmp7) {
if (tpacpi_is_ibm() &&
acpi_evalf(ec_handle, NULL, "UPDT", "qv")) {
thermal_read_mode = TPACPI_THERMAL_ACPI_UPDT;
} else {
thermal_read_mode = TPACPI_THERMAL_ACPI_TMP07;
}
} else {
thermal_read_mode = TPACPI_THERMAL_NONE;
}
vdbg_printk(TPACPI_DBG_INIT, "thermal is %s, mode %d\n",
str_supported(thermal_read_mode != TPACPI_THERMAL_NONE),
thermal_read_mode);
switch (thermal_read_mode) {
case TPACPI_THERMAL_TPEC_16:
res = sysfs_create_group(&tpacpi_sensors_pdev->dev.kobj,
&thermal_temp_input16_group);
if (res)
return res;
break;
case TPACPI_THERMAL_TPEC_8:
case TPACPI_THERMAL_ACPI_TMP07:
case TPACPI_THERMAL_ACPI_UPDT:
res = sysfs_create_group(&tpacpi_sensors_pdev->dev.kobj,
&thermal_temp_input8_group);
if (res)
return res;
break;
case TPACPI_THERMAL_NONE:
default:
return 1;
}
return 0;
}
static void thermal_exit(void)
{
switch (thermal_read_mode) {
case TPACPI_THERMAL_TPEC_16:
sysfs_remove_group(&tpacpi_sensors_pdev->dev.kobj,
&thermal_temp_input16_group);
break;
case TPACPI_THERMAL_TPEC_8:
case TPACPI_THERMAL_ACPI_TMP07:
case TPACPI_THERMAL_ACPI_UPDT:
sysfs_remove_group(&tpacpi_sensors_pdev->dev.kobj,
&thermal_temp_input8_group);
break;
case TPACPI_THERMAL_NONE:
default:
break;
}
}
static int thermal_read(struct seq_file *m)
{
int n, i;
struct ibm_thermal_sensors_struct t;
n = thermal_get_sensors(&t);
if (unlikely(n < 0))
return n;
seq_printf(m, "temperatures:\t");
if (n > 0) {
for (i = 0; i < (n - 1); i++)
seq_printf(m, "%d ", t.temp[i] / 1000);
seq_printf(m, "%d\n", t.temp[i] / 1000);
} else
seq_printf(m, "not supported\n");
return 0;
}
static unsigned int tpacpi_brightness_nvram_get(void)
{
u8 lnvram;
lnvram = (nvram_read_byte(TP_NVRAM_ADDR_BRIGHTNESS)
& TP_NVRAM_MASK_LEVEL_BRIGHTNESS)
>> TP_NVRAM_POS_LEVEL_BRIGHTNESS;
lnvram &= bright_maxlvl;
return lnvram;
}
static void tpacpi_brightness_checkpoint_nvram(void)
{
u8 lec = 0;
u8 b_nvram;
if (brightness_mode != TPACPI_BRGHT_MODE_ECNVRAM)
return;
vdbg_printk(TPACPI_DBG_BRGHT,
"trying to checkpoint backlight level to NVRAM...\n");
if (mutex_lock_killable(&brightness_mutex) < 0)
return;
if (unlikely(!acpi_ec_read(TP_EC_BACKLIGHT, &lec)))
goto unlock;
lec &= TP_EC_BACKLIGHT_LVLMSK;
b_nvram = nvram_read_byte(TP_NVRAM_ADDR_BRIGHTNESS);
if (lec != ((b_nvram & TP_NVRAM_MASK_LEVEL_BRIGHTNESS)
>> TP_NVRAM_POS_LEVEL_BRIGHTNESS)) {
b_nvram &= ~(TP_NVRAM_MASK_LEVEL_BRIGHTNESS <<
TP_NVRAM_POS_LEVEL_BRIGHTNESS);
b_nvram |= lec;
nvram_write_byte(b_nvram, TP_NVRAM_ADDR_BRIGHTNESS);
dbg_printk(TPACPI_DBG_BRGHT,
"updated NVRAM backlight level to %u (0x%02x)\n",
(unsigned int) lec, (unsigned int) b_nvram);
} else
vdbg_printk(TPACPI_DBG_BRGHT,
"NVRAM backlight level already is %u (0x%02x)\n",
(unsigned int) lec, (unsigned int) b_nvram);
unlock:
mutex_unlock(&brightness_mutex);
}
static int tpacpi_brightness_get_raw(int *status)
{
u8 lec = 0;
switch (brightness_mode) {
case TPACPI_BRGHT_MODE_UCMS_STEP:
*status = tpacpi_brightness_nvram_get();
return 0;
case TPACPI_BRGHT_MODE_EC:
case TPACPI_BRGHT_MODE_ECNVRAM:
if (unlikely(!acpi_ec_read(TP_EC_BACKLIGHT, &lec)))
return -EIO;
*status = lec;
return 0;
default:
return -ENXIO;
}
}
static int tpacpi_brightness_set_ec(unsigned int value)
{
u8 lec = 0;
if (unlikely(!acpi_ec_read(TP_EC_BACKLIGHT, &lec)))
return -EIO;
if (unlikely(!acpi_ec_write(TP_EC_BACKLIGHT,
(lec & TP_EC_BACKLIGHT_CMDMSK) |
(value & TP_EC_BACKLIGHT_LVLMSK))))
return -EIO;
return 0;
}
static int tpacpi_brightness_set_ucmsstep(unsigned int value)
{
int cmos_cmd, inc;
unsigned int current_value, i;
current_value = tpacpi_brightness_nvram_get();
if (value == current_value)
return 0;
cmos_cmd = (value > current_value) ?
TP_CMOS_BRIGHTNESS_UP :
TP_CMOS_BRIGHTNESS_DOWN;
inc = (value > current_value) ? 1 : -1;
for (i = current_value; i != value; i += inc)
if (issue_thinkpad_cmos_command(cmos_cmd))
return -EIO;
return 0;
}
static int brightness_set(unsigned int value)
{
int res;
if (value > bright_maxlvl || value < 0)
return -EINVAL;
vdbg_printk(TPACPI_DBG_BRGHT,
"set backlight level to %d\n", value);
res = mutex_lock_killable(&brightness_mutex);
if (res < 0)
return res;
switch (brightness_mode) {
case TPACPI_BRGHT_MODE_EC:
case TPACPI_BRGHT_MODE_ECNVRAM:
res = tpacpi_brightness_set_ec(value);
break;
case TPACPI_BRGHT_MODE_UCMS_STEP:
res = tpacpi_brightness_set_ucmsstep(value);
break;
default:
res = -ENXIO;
}
mutex_unlock(&brightness_mutex);
return res;
}
static int brightness_update_status(struct backlight_device *bd)
{
unsigned int level =
(bd->props.fb_blank == FB_BLANK_UNBLANK &&
bd->props.power == FB_BLANK_UNBLANK) ?
bd->props.brightness : 0;
dbg_printk(TPACPI_DBG_BRGHT,
"backlight: attempt to set level to %d\n",
level);
return brightness_set(level);
}
static int brightness_get(struct backlight_device *bd)
{
int status, res;
res = mutex_lock_killable(&brightness_mutex);
if (res < 0)
return 0;
res = tpacpi_brightness_get_raw(&status);
mutex_unlock(&brightness_mutex);
if (res < 0)
return 0;
return status & TP_EC_BACKLIGHT_LVLMSK;
}
static void tpacpi_brightness_notify_change(void)
{
backlight_force_update(ibm_backlight_device,
BACKLIGHT_UPDATE_HOTKEY);
}
static int __init tpacpi_query_bcl_levels(acpi_handle handle)
{
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
struct acpi_device *device, *child;
int rc;
if (acpi_bus_get_device(handle, &device))
return 0;
rc = 0;
list_for_each_entry(child, &device->children, node) {
acpi_status status = acpi_evaluate_object(child->handle, "_BCL",
NULL, &buffer);
if (ACPI_FAILURE(status))
continue;
obj = (union acpi_object *)buffer.pointer;
if (!obj || (obj->type != ACPI_TYPE_PACKAGE)) {
pr_err("Unknown _BCL data, please report this to %s\n",
TPACPI_MAIL);
rc = 0;
} else {
rc = obj->package.count;
}
break;
}
kfree(buffer.pointer);
return rc;
}
static unsigned int __init tpacpi_check_std_acpi_brightness_support(void)
{
acpi_handle video_device;
int bcl_levels = 0;
tpacpi_acpi_handle_locate("video", NULL, &video_device);
if (video_device)
bcl_levels = tpacpi_query_bcl_levels(video_device);
tp_features.bright_acpimode = (bcl_levels > 0);
return (bcl_levels > 2) ? (bcl_levels - 2) : 0;
}
static void __init tpacpi_detect_brightness_capabilities(void)
{
unsigned int b;
vdbg_printk(TPACPI_DBG_INIT,
"detecting firmware brightness interface capabilities\n");
b = tpacpi_check_std_acpi_brightness_support();
switch (b) {
case 16:
bright_maxlvl = 15;
pr_info("detected a 16-level brightness capable ThinkPad\n");
break;
case 8:
case 0:
bright_maxlvl = 7;
pr_info("detected a 8-level brightness capable ThinkPad\n");
break;
default:
pr_err("Unsupported brightness interface, "
"please contact %s\n", TPACPI_MAIL);
tp_features.bright_unkfw = 1;
bright_maxlvl = b - 1;
}
}
static int __init brightness_init(struct ibm_init_struct *iibm)
{
struct backlight_properties props;
int b;
unsigned long quirks;
vdbg_printk(TPACPI_DBG_INIT, "initializing brightness subdriver\n");
mutex_init(&brightness_mutex);
quirks = tpacpi_check_quirks(brightness_quirk_table,
ARRAY_SIZE(brightness_quirk_table));
if (tp_features.bright_unkfw)
return 1;
if (!brightness_enable) {
dbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_BRGHT,
"brightness support disabled by "
"module parameter\n");
return 1;
}
if (acpi_video_backlight_support()) {
if (brightness_enable > 1) {
pr_info("Standard ACPI backlight interface "
"available, not loading native one\n");
return 1;
} else if (brightness_enable == 1) {
pr_warn("Cannot enable backlight brightness support, "
"ACPI is already handling it. Refer to the "
"acpi_backlight kernel parameter.\n");
return 1;
}
} else if (tp_features.bright_acpimode && brightness_enable > 1) {
pr_notice("Standard ACPI backlight interface not "
"available, thinkpad_acpi native "
"brightness control enabled\n");
}
if (brightness_mode > TPACPI_BRGHT_MODE_MAX)
return -EINVAL;
if (brightness_mode == TPACPI_BRGHT_MODE_AUTO ||
brightness_mode == TPACPI_BRGHT_MODE_MAX) {
if (quirks & TPACPI_BRGHT_Q_EC)
brightness_mode = TPACPI_BRGHT_MODE_ECNVRAM;
else
brightness_mode = TPACPI_BRGHT_MODE_UCMS_STEP;
dbg_printk(TPACPI_DBG_BRGHT,
"driver auto-selected brightness_mode=%d\n",
brightness_mode);
}
if (!tpacpi_is_ibm() &&
(brightness_mode == TPACPI_BRGHT_MODE_ECNVRAM ||
brightness_mode == TPACPI_BRGHT_MODE_EC))
return -EINVAL;
if (tpacpi_brightness_get_raw(&b) < 0)
return 1;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = bright_maxlvl;
props.brightness = b & TP_EC_BACKLIGHT_LVLMSK;
ibm_backlight_device = backlight_device_register(TPACPI_BACKLIGHT_DEV_NAME,
NULL, NULL,
&ibm_backlight_data,
&props);
if (IS_ERR(ibm_backlight_device)) {
int rc = PTR_ERR(ibm_backlight_device);
ibm_backlight_device = NULL;
pr_err("Could not register backlight device\n");
return rc;
}
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_BRGHT,
"brightness is supported\n");
if (quirks & TPACPI_BRGHT_Q_ASK) {
pr_notice("brightness: will use unverified default: "
"brightness_mode=%d\n", brightness_mode);
pr_notice("brightness: please report to %s whether it works well "
"or not on your ThinkPad\n", TPACPI_MAIL);
}
backlight_update_status(ibm_backlight_device);
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_BRGHT,
"brightness: registering brightness hotkeys "
"as change notification\n");
tpacpi_hotkey_driver_mask_set(hotkey_driver_mask
| TP_ACPI_HKEY_BRGHTUP_MASK
| TP_ACPI_HKEY_BRGHTDWN_MASK);
return 0;
}
static void brightness_suspend(void)
{
tpacpi_brightness_checkpoint_nvram();
}
static void brightness_shutdown(void)
{
tpacpi_brightness_checkpoint_nvram();
}
static void brightness_exit(void)
{
if (ibm_backlight_device) {
vdbg_printk(TPACPI_DBG_EXIT | TPACPI_DBG_BRGHT,
"calling backlight_device_unregister()\n");
backlight_device_unregister(ibm_backlight_device);
}
tpacpi_brightness_checkpoint_nvram();
}
static int brightness_read(struct seq_file *m)
{
int level;
level = brightness_get(NULL);
if (level < 0) {
seq_printf(m, "level:\t\tunreadable\n");
} else {
seq_printf(m, "level:\t\t%d\n", level);
seq_printf(m, "commands:\tup, down\n");
seq_printf(m, "commands:\tlevel <level> (<level> is 0-%d)\n",
bright_maxlvl);
}
return 0;
}
static int brightness_write(char *buf)
{
int level;
int rc;
char *cmd;
level = brightness_get(NULL);
if (level < 0)
return level;
while ((cmd = next_cmd(&buf))) {
if (strlencmp(cmd, "up") == 0) {
if (level < bright_maxlvl)
level++;
} else if (strlencmp(cmd, "down") == 0) {
if (level > 0)
level--;
} else if (sscanf(cmd, "level %d", &level) == 1 &&
level >= 0 && level <= bright_maxlvl) {
} else
return -EINVAL;
}
tpacpi_disclose_usertask("procfs brightness",
"set level to %d\n", level);
rc = brightness_set(level);
if (!rc && ibm_backlight_device)
backlight_force_update(ibm_backlight_device,
BACKLIGHT_UPDATE_SYSFS);
return (rc == -EINTR)? -ERESTARTSYS : rc;
}
static void tpacpi_volume_checkpoint_nvram(void)
{
u8 lec = 0;
u8 b_nvram;
u8 ec_mask;
if (volume_mode != TPACPI_VOL_MODE_ECNVRAM)
return;
if (!volume_control_allowed)
return;
vdbg_printk(TPACPI_DBG_MIXER,
"trying to checkpoint mixer state to NVRAM...\n");
if (tp_features.mixer_no_level_control)
ec_mask = TP_EC_AUDIO_MUTESW_MSK;
else
ec_mask = TP_EC_AUDIO_MUTESW_MSK | TP_EC_AUDIO_LVL_MSK;
if (mutex_lock_killable(&volume_mutex) < 0)
return;
if (unlikely(!acpi_ec_read(TP_EC_AUDIO, &lec)))
goto unlock;
lec &= ec_mask;
b_nvram = nvram_read_byte(TP_NVRAM_ADDR_MIXER);
if (lec != (b_nvram & ec_mask)) {
b_nvram &= ~ec_mask;
b_nvram |= lec;
nvram_write_byte(b_nvram, TP_NVRAM_ADDR_MIXER);
dbg_printk(TPACPI_DBG_MIXER,
"updated NVRAM mixer status to 0x%02x (0x%02x)\n",
(unsigned int) lec, (unsigned int) b_nvram);
} else {
vdbg_printk(TPACPI_DBG_MIXER,
"NVRAM mixer status already is 0x%02x (0x%02x)\n",
(unsigned int) lec, (unsigned int) b_nvram);
}
unlock:
mutex_unlock(&volume_mutex);
}
static int volume_get_status_ec(u8 *status)
{
u8 s;
if (!acpi_ec_read(TP_EC_AUDIO, &s))
return -EIO;
*status = s;
dbg_printk(TPACPI_DBG_MIXER, "status 0x%02x\n", s);
return 0;
}
static int volume_get_status(u8 *status)
{
return volume_get_status_ec(status);
}
static int volume_set_status_ec(const u8 status)
{
if (!acpi_ec_write(TP_EC_AUDIO, status))
return -EIO;
dbg_printk(TPACPI_DBG_MIXER, "set EC mixer to 0x%02x\n", status);
return 0;
}
static int volume_set_status(const u8 status)
{
return volume_set_status_ec(status);
}
static int __volume_set_mute_ec(const bool mute)
{
int rc;
u8 s, n;
if (mutex_lock_killable(&volume_mutex) < 0)
return -EINTR;
rc = volume_get_status_ec(&s);
if (rc)
goto unlock;
n = (mute) ? s | TP_EC_AUDIO_MUTESW_MSK :
s & ~TP_EC_AUDIO_MUTESW_MSK;
if (n != s) {
rc = volume_set_status_ec(n);
if (!rc)
rc = 1;
}
unlock:
mutex_unlock(&volume_mutex);
return rc;
}
static int volume_alsa_set_mute(const bool mute)
{
dbg_printk(TPACPI_DBG_MIXER, "ALSA: trying to %smute\n",
(mute) ? "" : "un");
return __volume_set_mute_ec(mute);
}
static int volume_set_mute(const bool mute)
{
int rc;
dbg_printk(TPACPI_DBG_MIXER, "trying to %smute\n",
(mute) ? "" : "un");
rc = __volume_set_mute_ec(mute);
return (rc < 0) ? rc : 0;
}
static int __volume_set_volume_ec(const u8 vol)
{
int rc;
u8 s, n;
if (vol > TP_EC_VOLUME_MAX)
return -EINVAL;
if (mutex_lock_killable(&volume_mutex) < 0)
return -EINTR;
rc = volume_get_status_ec(&s);
if (rc)
goto unlock;
n = (s & ~TP_EC_AUDIO_LVL_MSK) | vol;
if (n != s) {
rc = volume_set_status_ec(n);
if (!rc)
rc = 1;
}
unlock:
mutex_unlock(&volume_mutex);
return rc;
}
static int volume_alsa_set_volume(const u8 vol)
{
dbg_printk(TPACPI_DBG_MIXER,
"ALSA: trying to set volume level to %hu\n", vol);
return __volume_set_volume_ec(vol);
}
static void volume_alsa_notify_change(void)
{
struct tpacpi_alsa_data *d;
if (alsa_card && alsa_card->private_data) {
d = alsa_card->private_data;
if (d->ctl_mute_id)
snd_ctl_notify(alsa_card,
SNDRV_CTL_EVENT_MASK_VALUE,
d->ctl_mute_id);
if (d->ctl_vol_id)
snd_ctl_notify(alsa_card,
SNDRV_CTL_EVENT_MASK_VALUE,
d->ctl_vol_id);
}
}
static int volume_alsa_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = TP_EC_VOLUME_MAX;
return 0;
}
static int volume_alsa_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
u8 s;
int rc;
rc = volume_get_status(&s);
if (rc < 0)
return rc;
ucontrol->value.integer.value[0] = s & TP_EC_AUDIO_LVL_MSK;
return 0;
}
static int volume_alsa_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
tpacpi_disclose_usertask("ALSA", "set volume to %ld\n",
ucontrol->value.integer.value[0]);
return volume_alsa_set_volume(ucontrol->value.integer.value[0]);
}
static int volume_alsa_mute_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
u8 s;
int rc;
rc = volume_get_status(&s);
if (rc < 0)
return rc;
ucontrol->value.integer.value[0] =
(s & TP_EC_AUDIO_MUTESW_MSK) ? 0 : 1;
return 0;
}
static int volume_alsa_mute_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
tpacpi_disclose_usertask("ALSA", "%smute\n",
ucontrol->value.integer.value[0] ?
"un" : "");
return volume_alsa_set_mute(!ucontrol->value.integer.value[0]);
}
static void volume_suspend(void)
{
tpacpi_volume_checkpoint_nvram();
}
static void volume_resume(void)
{
volume_alsa_notify_change();
}
static void volume_shutdown(void)
{
tpacpi_volume_checkpoint_nvram();
}
static void volume_exit(void)
{
if (alsa_card) {
snd_card_free(alsa_card);
alsa_card = NULL;
}
tpacpi_volume_checkpoint_nvram();
}
static int __init volume_create_alsa_mixer(void)
{
struct snd_card *card;
struct tpacpi_alsa_data *data;
struct snd_kcontrol *ctl_vol;
struct snd_kcontrol *ctl_mute;
int rc;
rc = snd_card_create(alsa_index, alsa_id, THIS_MODULE,
sizeof(struct tpacpi_alsa_data), &card);
if (rc < 0 || !card) {
pr_err("Failed to create ALSA card structures: %d\n", rc);
return 1;
}
BUG_ON(!card->private_data);
data = card->private_data;
data->card = card;
strlcpy(card->driver, TPACPI_ALSA_DRVNAME,
sizeof(card->driver));
strlcpy(card->shortname, TPACPI_ALSA_SHRTNAME,
sizeof(card->shortname));
snprintf(card->mixername, sizeof(card->mixername), "ThinkPad EC %s",
(thinkpad_id.ec_version_str) ?
thinkpad_id.ec_version_str : "(unknown)");
snprintf(card->longname, sizeof(card->longname),
"%s at EC reg 0x%02x, fw %s", card->shortname, TP_EC_AUDIO,
(thinkpad_id.ec_version_str) ?
thinkpad_id.ec_version_str : "unknown");
if (volume_control_allowed) {
volume_alsa_control_vol.put = volume_alsa_vol_put;
volume_alsa_control_vol.access =
SNDRV_CTL_ELEM_ACCESS_READWRITE;
volume_alsa_control_mute.put = volume_alsa_mute_put;
volume_alsa_control_mute.access =
SNDRV_CTL_ELEM_ACCESS_READWRITE;
}
if (!tp_features.mixer_no_level_control) {
ctl_vol = snd_ctl_new1(&volume_alsa_control_vol, NULL);
rc = snd_ctl_add(card, ctl_vol);
if (rc < 0) {
pr_err("Failed to create ALSA volume control: %d\n",
rc);
goto err_exit;
}
data->ctl_vol_id = &ctl_vol->id;
}
ctl_mute = snd_ctl_new1(&volume_alsa_control_mute, NULL);
rc = snd_ctl_add(card, ctl_mute);
if (rc < 0) {
pr_err("Failed to create ALSA mute control: %d\n", rc);
goto err_exit;
}
data->ctl_mute_id = &ctl_mute->id;
snd_card_set_dev(card, &tpacpi_pdev->dev);
rc = snd_card_register(card);
if (rc < 0) {
pr_err("Failed to register ALSA card: %d\n", rc);
goto err_exit;
}
alsa_card = card;
return 0;
err_exit:
snd_card_free(card);
return 1;
}
static int __init volume_init(struct ibm_init_struct *iibm)
{
unsigned long quirks;
int rc;
vdbg_printk(TPACPI_DBG_INIT, "initializing volume subdriver\n");
mutex_init(&volume_mutex);
if (volume_mode > TPACPI_VOL_MODE_MAX)
return -EINVAL;
if (volume_mode == TPACPI_VOL_MODE_UCMS_STEP) {
pr_err("UCMS step volume mode not implemented, "
"please contact %s\n", TPACPI_MAIL);
return 1;
}
if (volume_capabilities >= TPACPI_VOL_CAP_MAX)
return -EINVAL;
if (!alsa_enable) {
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_MIXER,
"ALSA mixer disabled by parameter, "
"not loading volume subdriver...\n");
return 1;
}
quirks = tpacpi_check_quirks(volume_quirk_table,
ARRAY_SIZE(volume_quirk_table));
switch (volume_capabilities) {
case TPACPI_VOL_CAP_AUTO:
if (quirks & TPACPI_VOL_Q_MUTEONLY)
tp_features.mixer_no_level_control = 1;
else if (quirks & TPACPI_VOL_Q_LEVEL)
tp_features.mixer_no_level_control = 0;
else
return 1;
break;
case TPACPI_VOL_CAP_VOLMUTE:
tp_features.mixer_no_level_control = 0;
break;
case TPACPI_VOL_CAP_MUTEONLY:
tp_features.mixer_no_level_control = 1;
break;
default:
return 1;
}
if (volume_capabilities != TPACPI_VOL_CAP_AUTO)
dbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_MIXER,
"using user-supplied volume_capabilities=%d\n",
volume_capabilities);
if (volume_mode == TPACPI_VOL_MODE_AUTO ||
volume_mode == TPACPI_VOL_MODE_MAX) {
volume_mode = TPACPI_VOL_MODE_ECNVRAM;
dbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_MIXER,
"driver auto-selected volume_mode=%d\n",
volume_mode);
} else {
dbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_MIXER,
"using user-supplied volume_mode=%d\n",
volume_mode);
}
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_MIXER,
"mute is supported, volume control is %s\n",
str_supported(!tp_features.mixer_no_level_control));
rc = volume_create_alsa_mixer();
if (rc) {
pr_err("Could not create the ALSA mixer interface\n");
return rc;
}
pr_info("Console audio control enabled, mode: %s\n",
(volume_control_allowed) ?
"override (read/write)" :
"monitor (read only)");
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_MIXER,
"registering volume hotkeys as change notification\n");
tpacpi_hotkey_driver_mask_set(hotkey_driver_mask
| TP_ACPI_HKEY_VOLUP_MASK
| TP_ACPI_HKEY_VOLDWN_MASK
| TP_ACPI_HKEY_MUTE_MASK);
return 0;
}
static int volume_read(struct seq_file *m)
{
u8 status;
if (volume_get_status(&status) < 0) {
seq_printf(m, "level:\t\tunreadable\n");
} else {
if (tp_features.mixer_no_level_control)
seq_printf(m, "level:\t\tunsupported\n");
else
seq_printf(m, "level:\t\t%d\n",
status & TP_EC_AUDIO_LVL_MSK);
seq_printf(m, "mute:\t\t%s\n",
onoff(status, TP_EC_AUDIO_MUTESW));
if (volume_control_allowed) {
seq_printf(m, "commands:\tunmute, mute\n");
if (!tp_features.mixer_no_level_control) {
seq_printf(m,
"commands:\tup, down\n");
seq_printf(m,
"commands:\tlevel <level>"
" (<level> is 0-%d)\n",
TP_EC_VOLUME_MAX);
}
}
}
return 0;
}
static int volume_write(char *buf)
{
u8 s;
u8 new_level, new_mute;
int l;
char *cmd;
int rc;
if (!volume_control_allowed && tpacpi_lifecycle != TPACPI_LIFE_INIT) {
if (unlikely(!tp_warned.volume_ctrl_forbidden)) {
tp_warned.volume_ctrl_forbidden = 1;
pr_notice("Console audio control in monitor mode, "
"changes are not allowed\n");
pr_notice("Use the volume_control=1 module parameter "
"to enable volume control\n");
}
return -EPERM;
}
rc = volume_get_status(&s);
if (rc < 0)
return rc;
new_level = s & TP_EC_AUDIO_LVL_MSK;
new_mute = s & TP_EC_AUDIO_MUTESW_MSK;
while ((cmd = next_cmd(&buf))) {
if (!tp_features.mixer_no_level_control) {
if (strlencmp(cmd, "up") == 0) {
if (new_mute)
new_mute = 0;
else if (new_level < TP_EC_VOLUME_MAX)
new_level++;
continue;
} else if (strlencmp(cmd, "down") == 0) {
if (new_mute)
new_mute = 0;
else if (new_level > 0)
new_level--;
continue;
} else if (sscanf(cmd, "level %u", &l) == 1 &&
l >= 0 && l <= TP_EC_VOLUME_MAX) {
new_level = l;
continue;
}
}
if (strlencmp(cmd, "mute") == 0)
new_mute = TP_EC_AUDIO_MUTESW_MSK;
else if (strlencmp(cmd, "unmute") == 0)
new_mute = 0;
else
return -EINVAL;
}
if (tp_features.mixer_no_level_control) {
tpacpi_disclose_usertask("procfs volume", "%smute\n",
new_mute ? "" : "un");
rc = volume_set_mute(!!new_mute);
} else {
tpacpi_disclose_usertask("procfs volume",
"%smute and set level to %d\n",
new_mute ? "" : "un", new_level);
rc = volume_set_status(new_mute | new_level);
}
volume_alsa_notify_change();
return (rc == -EINTR) ? -ERESTARTSYS : rc;
}
static void inline volume_alsa_notify_change(void)
{
}
static int __init volume_init(struct ibm_init_struct *iibm)
{
pr_info("volume: disabled as there is no ALSA support in this kernel\n");
return 1;
}
static void fan_quirk1_setup(void)
{
if (fan_control_initial_status == 0x07) {
pr_notice("fan_init: initial fan status is unknown, "
"assuming it is in auto mode\n");
tp_features.fan_ctrl_status_undef = 1;
}
}
static void fan_quirk1_handle(u8 *fan_status)
{
if (unlikely(tp_features.fan_ctrl_status_undef)) {
if (*fan_status != fan_control_initial_status) {
tp_features.fan_ctrl_status_undef = 0;
} else {
*fan_status = TP_EC_FAN_AUTO;
}
}
}
static bool fan_select_fan1(void)
{
if (tp_features.second_fan) {
u8 val;
if (ec_read(fan_select_offset, &val) < 0)
return false;
val &= 0xFEU;
if (ec_write(fan_select_offset, val) < 0)
return false;
}
return true;
}
static bool fan_select_fan2(void)
{
u8 val;
if (!tp_features.second_fan)
return false;
if (ec_read(fan_select_offset, &val) < 0)
return false;
val |= 0x01U;
if (ec_write(fan_select_offset, val) < 0)
return false;
return true;
}
static void fan_update_desired_level(u8 status)
{
if ((status &
(TP_EC_FAN_AUTO | TP_EC_FAN_FULLSPEED)) == 0) {
if (status > 7)
fan_control_desired_level = 7;
else
fan_control_desired_level = status;
}
}
static int fan_get_status(u8 *status)
{
u8 s;
switch (fan_status_access_mode) {
case TPACPI_FAN_RD_ACPI_GFAN: {
int res;
if (unlikely(!acpi_evalf(gfan_handle, &res, NULL, "d")))
return -EIO;
if (likely(status))
*status = res & 0x07;
break;
}
case TPACPI_FAN_RD_TPEC:
if (unlikely(!acpi_ec_read(fan_status_offset, &s)))
return -EIO;
if (likely(status)) {
*status = s;
fan_quirk1_handle(status);
}
break;
default:
return -ENXIO;
}
return 0;
}
static int fan_get_status_safe(u8 *status)
{
int rc;
u8 s;
if (mutex_lock_killable(&fan_mutex))
return -ERESTARTSYS;
rc = fan_get_status(&s);
if (!rc)
fan_update_desired_level(s);
mutex_unlock(&fan_mutex);
if (status)
*status = s;
return rc;
}
static int fan_get_speed(unsigned int *speed)
{
u8 hi, lo;
switch (fan_status_access_mode) {
case TPACPI_FAN_RD_TPEC:
if (unlikely(!fan_select_fan1()))
return -EIO;
if (unlikely(!acpi_ec_read(fan_rpm_offset, &lo) ||
!acpi_ec_read(fan_rpm_offset + 1, &hi)))
return -EIO;
if (likely(speed))
*speed = (hi << 8) | lo;
break;
default:
return -ENXIO;
}
return 0;
}
static int fan2_get_speed(unsigned int *speed)
{
u8 hi, lo;
bool rc;
switch (fan_status_access_mode) {
case TPACPI_FAN_RD_TPEC:
if (unlikely(!fan_select_fan2()))
return -EIO;
rc = !acpi_ec_read(fan_rpm_offset, &lo) ||
!acpi_ec_read(fan_rpm_offset + 1, &hi);
fan_select_fan1();
if (rc)
return -EIO;
if (likely(speed))
*speed = (hi << 8) | lo;
break;
default:
return -ENXIO;
}
return 0;
}
static int fan_set_level(int level)
{
if (!fan_control_allowed)
return -EPERM;
switch (fan_control_access_mode) {
case TPACPI_FAN_WR_ACPI_SFAN:
if (level >= 0 && level <= 7) {
if (!acpi_evalf(sfan_handle, NULL, NULL, "vd", level))
return -EIO;
} else
return -EINVAL;
break;
case TPACPI_FAN_WR_ACPI_FANS:
case TPACPI_FAN_WR_TPEC:
if (!(level & TP_EC_FAN_AUTO) &&
!(level & TP_EC_FAN_FULLSPEED) &&
((level < 0) || (level > 7)))
return -EINVAL;
if (level & TP_EC_FAN_FULLSPEED)
level |= 7;
else if (level & TP_EC_FAN_AUTO)
level |= 4;
if (!acpi_ec_write(fan_status_offset, level))
return -EIO;
else
tp_features.fan_ctrl_status_undef = 0;
break;
default:
return -ENXIO;
}
vdbg_printk(TPACPI_DBG_FAN,
"fan control: set fan control register to 0x%02x\n", level);
return 0;
}
static int fan_set_level_safe(int level)
{
int rc;
if (!fan_control_allowed)
return -EPERM;
if (mutex_lock_killable(&fan_mutex))
return -ERESTARTSYS;
if (level == TPACPI_FAN_LAST_LEVEL)
level = fan_control_desired_level;
rc = fan_set_level(level);
if (!rc)
fan_update_desired_level(level);
mutex_unlock(&fan_mutex);
return rc;
}
static int fan_set_enable(void)
{
u8 s;
int rc;
if (!fan_control_allowed)
return -EPERM;
if (mutex_lock_killable(&fan_mutex))
return -ERESTARTSYS;
switch (fan_control_access_mode) {
case TPACPI_FAN_WR_ACPI_FANS:
case TPACPI_FAN_WR_TPEC:
rc = fan_get_status(&s);
if (rc < 0)
break;
if (s != 7) {
s &= 0x07;
s |= TP_EC_FAN_AUTO | 4;
}
if (!acpi_ec_write(fan_status_offset, s))
rc = -EIO;
else {
tp_features.fan_ctrl_status_undef = 0;
rc = 0;
}
break;
case TPACPI_FAN_WR_ACPI_SFAN:
rc = fan_get_status(&s);
if (rc < 0)
break;
s &= 0x07;
s |= 4;
if (!acpi_evalf(sfan_handle, NULL, NULL, "vd", s))
rc = -EIO;
else
rc = 0;
break;
default:
rc = -ENXIO;
}
mutex_unlock(&fan_mutex);
if (!rc)
vdbg_printk(TPACPI_DBG_FAN,
"fan control: set fan control register to 0x%02x\n",
s);
return rc;
}
static int fan_set_disable(void)
{
int rc;
if (!fan_control_allowed)
return -EPERM;
if (mutex_lock_killable(&fan_mutex))
return -ERESTARTSYS;
rc = 0;
switch (fan_control_access_mode) {
case TPACPI_FAN_WR_ACPI_FANS:
case TPACPI_FAN_WR_TPEC:
if (!acpi_ec_write(fan_status_offset, 0x00))
rc = -EIO;
else {
fan_control_desired_level = 0;
tp_features.fan_ctrl_status_undef = 0;
}
break;
case TPACPI_FAN_WR_ACPI_SFAN:
if (!acpi_evalf(sfan_handle, NULL, NULL, "vd", 0x00))
rc = -EIO;
else
fan_control_desired_level = 0;
break;
default:
rc = -ENXIO;
}
if (!rc)
vdbg_printk(TPACPI_DBG_FAN,
"fan control: set fan control register to 0\n");
mutex_unlock(&fan_mutex);
return rc;
}
static int fan_set_speed(int speed)
{
int rc;
if (!fan_control_allowed)
return -EPERM;
if (mutex_lock_killable(&fan_mutex))
return -ERESTARTSYS;
rc = 0;
switch (fan_control_access_mode) {
case TPACPI_FAN_WR_ACPI_FANS:
if (speed >= 0 && speed <= 65535) {
if (!acpi_evalf(fans_handle, NULL, NULL, "vddd",
speed, speed, speed))
rc = -EIO;
} else
rc = -EINVAL;
break;
default:
rc = -ENXIO;
}
mutex_unlock(&fan_mutex);
return rc;
}
static void fan_watchdog_reset(void)
{
if (fan_control_access_mode == TPACPI_FAN_WR_NONE)
return;
if (fan_watchdog_maxinterval > 0 &&
tpacpi_lifecycle != TPACPI_LIFE_EXITING)
mod_delayed_work(tpacpi_wq, &fan_watchdog_task,
msecs_to_jiffies(fan_watchdog_maxinterval * 1000));
else
cancel_delayed_work(&fan_watchdog_task);
}
static void fan_watchdog_fire(struct work_struct *ignored)
{
int rc;
if (tpacpi_lifecycle != TPACPI_LIFE_RUNNING)
return;
pr_notice("fan watchdog: enabling fan\n");
rc = fan_set_enable();
if (rc < 0) {
pr_err("fan watchdog: error %d while enabling fan, "
"will try again later...\n", -rc);
fan_watchdog_reset();
}
}
static ssize_t fan_pwm1_enable_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int res, mode;
u8 status;
res = fan_get_status_safe(&status);
if (res)
return res;
if (status & TP_EC_FAN_FULLSPEED) {
mode = 0;
} else if (status & TP_EC_FAN_AUTO) {
mode = 2;
} else
mode = 1;
return snprintf(buf, PAGE_SIZE, "%d\n", mode);
}
static ssize_t fan_pwm1_enable_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned long t;
int res, level;
if (parse_strtoul(buf, 2, &t))
return -EINVAL;
tpacpi_disclose_usertask("hwmon pwm1_enable",
"set fan mode to %lu\n", t);
switch (t) {
case 0:
level = TP_EC_FAN_FULLSPEED;
break;
case 1:
level = TPACPI_FAN_LAST_LEVEL;
break;
case 2:
level = TP_EC_FAN_AUTO;
break;
case 3:
return -ENOSYS;
default:
return -EINVAL;
}
res = fan_set_level_safe(level);
if (res == -ENXIO)
return -EINVAL;
else if (res < 0)
return res;
fan_watchdog_reset();
return count;
}
static ssize_t fan_pwm1_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int res;
u8 status;
res = fan_get_status_safe(&status);
if (res)
return res;
if ((status &
(TP_EC_FAN_AUTO | TP_EC_FAN_FULLSPEED)) != 0)
status = fan_control_desired_level;
if (status > 7)
status = 7;
return snprintf(buf, PAGE_SIZE, "%u\n", (status * 255) / 7);
}
static ssize_t fan_pwm1_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned long s;
int rc;
u8 status, newlevel;
if (parse_strtoul(buf, 255, &s))
return -EINVAL;
tpacpi_disclose_usertask("hwmon pwm1",
"set fan speed to %lu\n", s);
newlevel = (s >> 5) & 0x07;
if (mutex_lock_killable(&fan_mutex))
return -ERESTARTSYS;
rc = fan_get_status(&status);
if (!rc && (status &
(TP_EC_FAN_AUTO | TP_EC_FAN_FULLSPEED)) == 0) {
rc = fan_set_level(newlevel);
if (rc == -ENXIO)
rc = -EINVAL;
else if (!rc) {
fan_update_desired_level(newlevel);
fan_watchdog_reset();
}
}
mutex_unlock(&fan_mutex);
return (rc)? rc : count;
}
static ssize_t fan_fan1_input_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int res;
unsigned int speed;
res = fan_get_speed(&speed);
if (res < 0)
return res;
return snprintf(buf, PAGE_SIZE, "%u\n", speed);
}
static ssize_t fan_fan2_input_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int res;
unsigned int speed;
res = fan2_get_speed(&speed);
if (res < 0)
return res;
return snprintf(buf, PAGE_SIZE, "%u\n", speed);
}
static ssize_t fan_fan_watchdog_show(struct device_driver *drv,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%u\n", fan_watchdog_maxinterval);
}
static ssize_t fan_fan_watchdog_store(struct device_driver *drv,
const char *buf, size_t count)
{
unsigned long t;
if (parse_strtoul(buf, 120, &t))
return -EINVAL;
if (!fan_control_allowed)
return -EPERM;
fan_watchdog_maxinterval = t;
fan_watchdog_reset();
tpacpi_disclose_usertask("fan_watchdog", "set to %lu\n", t);
return count;
}
static int __init fan_init(struct ibm_init_struct *iibm)
{
int rc;
unsigned long quirks;
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_FAN,
"initializing fan subdriver\n");
mutex_init(&fan_mutex);
fan_status_access_mode = TPACPI_FAN_NONE;
fan_control_access_mode = TPACPI_FAN_WR_NONE;
fan_control_commands = 0;
fan_watchdog_maxinterval = 0;
tp_features.fan_ctrl_status_undef = 0;
tp_features.second_fan = 0;
fan_control_desired_level = 7;
if (tpacpi_is_ibm()) {
TPACPI_ACPIHANDLE_INIT(fans);
TPACPI_ACPIHANDLE_INIT(gfan);
TPACPI_ACPIHANDLE_INIT(sfan);
}
quirks = tpacpi_check_quirks(fan_quirk_table,
ARRAY_SIZE(fan_quirk_table));
if (gfan_handle) {
fan_status_access_mode = TPACPI_FAN_RD_ACPI_GFAN;
} else {
if (likely(acpi_ec_read(fan_status_offset,
&fan_control_initial_status))) {
fan_status_access_mode = TPACPI_FAN_RD_TPEC;
if (quirks & TPACPI_FAN_Q1)
fan_quirk1_setup();
if (quirks & TPACPI_FAN_2FAN) {
tp_features.second_fan = 1;
dbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_FAN,
"secondary fan support enabled\n");
}
} else {
pr_err("ThinkPad ACPI EC access misbehaving, "
"fan status and control unavailable\n");
return 1;
}
}
if (sfan_handle) {
fan_control_access_mode = TPACPI_FAN_WR_ACPI_SFAN;
fan_control_commands |=
TPACPI_FAN_CMD_LEVEL | TPACPI_FAN_CMD_ENABLE;
} else {
if (!gfan_handle) {
if (fans_handle) {
fan_control_access_mode =
TPACPI_FAN_WR_ACPI_FANS;
fan_control_commands |=
TPACPI_FAN_CMD_SPEED |
TPACPI_FAN_CMD_LEVEL |
TPACPI_FAN_CMD_ENABLE;
} else {
fan_control_access_mode = TPACPI_FAN_WR_TPEC;
fan_control_commands |=
TPACPI_FAN_CMD_LEVEL |
TPACPI_FAN_CMD_ENABLE;
}
}
}
vdbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_FAN,
"fan is %s, modes %d, %d\n",
str_supported(fan_status_access_mode != TPACPI_FAN_NONE ||
fan_control_access_mode != TPACPI_FAN_WR_NONE),
fan_status_access_mode, fan_control_access_mode);
if (!fan_control_allowed) {
fan_control_access_mode = TPACPI_FAN_WR_NONE;
fan_control_commands = 0;
dbg_printk(TPACPI_DBG_INIT | TPACPI_DBG_FAN,
"fan control features disabled by parameter\n");
}
if (fan_status_access_mode != TPACPI_FAN_NONE)
fan_get_status_safe(NULL);
if (fan_status_access_mode != TPACPI_FAN_NONE ||
fan_control_access_mode != TPACPI_FAN_WR_NONE) {
if (tp_features.second_fan) {
fan_attributes[ARRAY_SIZE(fan_attributes)-2] =
&dev_attr_fan_fan2_input.attr;
}
rc = sysfs_create_group(&tpacpi_sensors_pdev->dev.kobj,
&fan_attr_group);
if (rc < 0)
return rc;
rc = driver_create_file(&tpacpi_hwmon_pdriver.driver,
&driver_attr_fan_watchdog);
if (rc < 0) {
sysfs_remove_group(&tpacpi_sensors_pdev->dev.kobj,
&fan_attr_group);
return rc;
}
return 0;
} else
return 1;
}
static void fan_exit(void)
{
vdbg_printk(TPACPI_DBG_EXIT | TPACPI_DBG_FAN,
"cancelling any pending fan watchdog tasks\n");
sysfs_remove_group(&tpacpi_sensors_pdev->dev.kobj, &fan_attr_group);
driver_remove_file(&tpacpi_hwmon_pdriver.driver,
&driver_attr_fan_watchdog);
cancel_delayed_work(&fan_watchdog_task);
flush_workqueue(tpacpi_wq);
}
static void fan_suspend(void)
{
int rc;
if (!fan_control_allowed)
return;
fan_control_resume_level = 0;
rc = fan_get_status_safe(&fan_control_resume_level);
if (rc < 0)
pr_notice("failed to read fan level for later "
"restore during resume: %d\n", rc);
if (tp_features.fan_ctrl_status_undef)
fan_control_resume_level = 0;
}
static void fan_resume(void)
{
u8 current_level = 7;
bool do_set = false;
int rc;
tp_features.fan_ctrl_status_undef = 0;
if (!fan_control_allowed ||
!fan_control_resume_level ||
(fan_get_status_safe(&current_level) < 0))
return;
switch (fan_control_access_mode) {
case TPACPI_FAN_WR_ACPI_SFAN:
do_set = (fan_control_resume_level > current_level);
break;
case TPACPI_FAN_WR_ACPI_FANS:
case TPACPI_FAN_WR_TPEC:
if (fan_control_resume_level != 7 &&
!(fan_control_resume_level & TP_EC_FAN_FULLSPEED))
return;
else
do_set = !(current_level & TP_EC_FAN_FULLSPEED) &&
(current_level != fan_control_resume_level);
break;
default:
return;
}
if (do_set) {
pr_notice("restoring fan level to 0x%02x\n",
fan_control_resume_level);
rc = fan_set_level_safe(fan_control_resume_level);
if (rc < 0)
pr_notice("failed to restore fan level: %d\n", rc);
}
}
static int fan_read(struct seq_file *m)
{
int rc;
u8 status;
unsigned int speed = 0;
switch (fan_status_access_mode) {
case TPACPI_FAN_RD_ACPI_GFAN:
rc = fan_get_status_safe(&status);
if (rc < 0)
return rc;
seq_printf(m, "status:\t\t%s\n"
"level:\t\t%d\n",
(status != 0) ? "enabled" : "disabled", status);
break;
case TPACPI_FAN_RD_TPEC:
rc = fan_get_status_safe(&status);
if (rc < 0)
return rc;
seq_printf(m, "status:\t\t%s\n",
(status != 0) ? "enabled" : "disabled");
rc = fan_get_speed(&speed);
if (rc < 0)
return rc;
seq_printf(m, "speed:\t\t%d\n", speed);
if (status & TP_EC_FAN_FULLSPEED)
seq_printf(m, "level:\t\tdisengaged\n");
else if (status & TP_EC_FAN_AUTO)
seq_printf(m, "level:\t\tauto\n");
else
seq_printf(m, "level:\t\t%d\n", status);
break;
case TPACPI_FAN_NONE:
default:
seq_printf(m, "status:\t\tnot supported\n");
}
if (fan_control_commands & TPACPI_FAN_CMD_LEVEL) {
seq_printf(m, "commands:\tlevel <level>");
switch (fan_control_access_mode) {
case TPACPI_FAN_WR_ACPI_SFAN:
seq_printf(m, " (<level> is 0-7)\n");
break;
default:
seq_printf(m, " (<level> is 0-7, "
"auto, disengaged, full-speed)\n");
break;
}
}
if (fan_control_commands & TPACPI_FAN_CMD_ENABLE)
seq_printf(m, "commands:\tenable, disable\n"
"commands:\twatchdog <timeout> (<timeout> "
"is 0 (off), 1-120 (seconds))\n");
if (fan_control_commands & TPACPI_FAN_CMD_SPEED)
seq_printf(m, "commands:\tspeed <speed>"
" (<speed> is 0-65535)\n");
return 0;
}
static int fan_write_cmd_level(const char *cmd, int *rc)
{
int level;
if (strlencmp(cmd, "level auto") == 0)
level = TP_EC_FAN_AUTO;
else if ((strlencmp(cmd, "level disengaged") == 0) |
(strlencmp(cmd, "level full-speed") == 0))
level = TP_EC_FAN_FULLSPEED;
else if (sscanf(cmd, "level %d", &level) != 1)
return 0;
*rc = fan_set_level_safe(level);
if (*rc == -ENXIO)
pr_err("level command accepted for unsupported access mode %d\n",
fan_control_access_mode);
else if (!*rc)
tpacpi_disclose_usertask("procfs fan",
"set level to %d\n", level);
return 1;
}
static int fan_write_cmd_enable(const char *cmd, int *rc)
{
if (strlencmp(cmd, "enable") != 0)
return 0;
*rc = fan_set_enable();
if (*rc == -ENXIO)
pr_err("enable command accepted for unsupported access mode %d\n",
fan_control_access_mode);
else if (!*rc)
tpacpi_disclose_usertask("procfs fan", "enable\n");
return 1;
}
static int fan_write_cmd_disable(const char *cmd, int *rc)
{
if (strlencmp(cmd, "disable") != 0)
return 0;
*rc = fan_set_disable();
if (*rc == -ENXIO)
pr_err("disable command accepted for unsupported access mode %d\n",
fan_control_access_mode);
else if (!*rc)
tpacpi_disclose_usertask("procfs fan", "disable\n");
return 1;
}
static int fan_write_cmd_speed(const char *cmd, int *rc)
{
int speed;
if (sscanf(cmd, "speed %d", &speed) != 1)
return 0;
*rc = fan_set_speed(speed);
if (*rc == -ENXIO)
pr_err("speed command accepted for unsupported access mode %d\n",
fan_control_access_mode);
else if (!*rc)
tpacpi_disclose_usertask("procfs fan",
"set speed to %d\n", speed);
return 1;
}
static int fan_write_cmd_watchdog(const char *cmd, int *rc)
{
int interval;
if (sscanf(cmd, "watchdog %d", &interval) != 1)
return 0;
if (interval < 0 || interval > 120)
*rc = -EINVAL;
else {
fan_watchdog_maxinterval = interval;
tpacpi_disclose_usertask("procfs fan",
"set watchdog timer to %d\n",
interval);
}
return 1;
}
static int fan_write(char *buf)
{
char *cmd;
int rc = 0;
while (!rc && (cmd = next_cmd(&buf))) {
if (!((fan_control_commands & TPACPI_FAN_CMD_LEVEL) &&
fan_write_cmd_level(cmd, &rc)) &&
!((fan_control_commands & TPACPI_FAN_CMD_ENABLE) &&
(fan_write_cmd_enable(cmd, &rc) ||
fan_write_cmd_disable(cmd, &rc) ||
fan_write_cmd_watchdog(cmd, &rc))) &&
!((fan_control_commands & TPACPI_FAN_CMD_SPEED) &&
fan_write_cmd_speed(cmd, &rc))
)
rc = -EINVAL;
else if (!rc)
fan_watchdog_reset();
}
return rc;
}
static int mute_led_on_off(struct tp_led_table *t, bool state)
{
acpi_handle temp;
int output;
if (!ACPI_SUCCESS(acpi_get_handle(hkey_handle, t->name, &temp))) {
pr_warn("Thinkpad ACPI has no %s interface.\n", t->name);
return -EIO;
}
if (!acpi_evalf(hkey_handle, &output, t->name, "dd",
state ? t->on_value : t->off_value))
return -EIO;
t->state = state;
return state;
}
int tpacpi_led_set(int whichled, bool on)
{
struct tp_led_table *t;
if (whichled < 0 || whichled >= TPACPI_LED_MAX)
return -EINVAL;
t = &led_tables[whichled];
if (t->state < 0 || t->state == on)
return t->state;
return mute_led_on_off(t, on);
}
static int mute_led_init(struct ibm_init_struct *iibm)
{
acpi_handle temp;
int i;
for (i = 0; i < TPACPI_LED_MAX; i++) {
struct tp_led_table *t = &led_tables[i];
if (ACPI_SUCCESS(acpi_get_handle(hkey_handle, t->name, &temp)))
mute_led_on_off(t, false);
else
t->state = -ENODEV;
}
return 0;
}
static void mute_led_exit(void)
{
int i;
for (i = 0; i < TPACPI_LED_MAX; i++)
tpacpi_led_set(i, false);
}
static void tpacpi_driver_event(const unsigned int hkey_event)
{
if (ibm_backlight_device) {
switch (hkey_event) {
case TP_HKEY_EV_BRGHT_UP:
case TP_HKEY_EV_BRGHT_DOWN:
tpacpi_brightness_notify_change();
}
}
if (alsa_card) {
switch (hkey_event) {
case TP_HKEY_EV_VOL_UP:
case TP_HKEY_EV_VOL_DOWN:
case TP_HKEY_EV_VOL_MUTE:
volume_alsa_notify_change();
}
}
}
static void hotkey_driver_event(const unsigned int scancode)
{
tpacpi_driver_event(TP_HKEY_EV_HOTKEY_BASE + scancode);
}
static ssize_t thinkpad_acpi_pdev_name_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", TPACPI_NAME);
}
static const char * __init str_supported(int is_supported)
{
static char text_unsupported[] __initdata = "not supported";
return (is_supported)? &text_unsupported[4] : &text_unsupported[0];
}
static void ibm_exit(struct ibm_struct *ibm)
{
dbg_printk(TPACPI_DBG_EXIT, "removing %s\n", ibm->name);
list_del_init(&ibm->all_drivers);
if (ibm->flags.acpi_notify_installed) {
dbg_printk(TPACPI_DBG_EXIT,
"%s: acpi_remove_notify_handler\n", ibm->name);
BUG_ON(!ibm->acpi);
acpi_remove_notify_handler(*ibm->acpi->handle,
ibm->acpi->type,
dispatch_acpi_notify);
ibm->flags.acpi_notify_installed = 0;
}
if (ibm->flags.proc_created) {
dbg_printk(TPACPI_DBG_EXIT,
"%s: remove_proc_entry\n", ibm->name);
remove_proc_entry(ibm->name, proc_dir);
ibm->flags.proc_created = 0;
}
if (ibm->flags.acpi_driver_registered) {
dbg_printk(TPACPI_DBG_EXIT,
"%s: acpi_bus_unregister_driver\n", ibm->name);
BUG_ON(!ibm->acpi);
acpi_bus_unregister_driver(ibm->acpi->driver);
kfree(ibm->acpi->driver);
ibm->acpi->driver = NULL;
ibm->flags.acpi_driver_registered = 0;
}
if (ibm->flags.init_called && ibm->exit) {
ibm->exit();
ibm->flags.init_called = 0;
}
dbg_printk(TPACPI_DBG_INIT, "finished removing %s\n", ibm->name);
}
static int __init ibm_init(struct ibm_init_struct *iibm)
{
int ret;
struct ibm_struct *ibm = iibm->data;
struct proc_dir_entry *entry;
BUG_ON(ibm == NULL);
INIT_LIST_HEAD(&ibm->all_drivers);
if (ibm->flags.experimental && !experimental)
return 0;
dbg_printk(TPACPI_DBG_INIT,
"probing for %s\n", ibm->name);
if (iibm->init) {
ret = iibm->init(iibm);
if (ret > 0)
return 0;
if (ret)
return ret;
ibm->flags.init_called = 1;
}
if (ibm->acpi) {
if (ibm->acpi->hid) {
ret = register_tpacpi_subdriver(ibm);
if (ret)
goto err_out;
}
if (ibm->acpi->notify) {
ret = setup_acpi_notify(ibm);
if (ret == -ENODEV) {
pr_notice("disabling subdriver %s\n",
ibm->name);
ret = 0;
goto err_out;
}
if (ret < 0)
goto err_out;
}
}
dbg_printk(TPACPI_DBG_INIT,
"%s installed\n", ibm->name);
if (ibm->read) {
umode_t mode = iibm->base_procfs_mode;
if (!mode)
mode = S_IRUGO;
if (ibm->write)
mode |= S_IWUSR;
entry = proc_create_data(ibm->name, mode, proc_dir,
&dispatch_proc_fops, ibm);
if (!entry) {
pr_err("unable to create proc entry %s\n", ibm->name);
ret = -ENODEV;
goto err_out;
}
ibm->flags.proc_created = 1;
}
list_add_tail(&ibm->all_drivers, &tpacpi_all_drivers);
return 0;
err_out:
dbg_printk(TPACPI_DBG_INIT,
"%s: at error exit path with result %d\n",
ibm->name, ret);
ibm_exit(ibm);
return (ret < 0)? ret : 0;
}
static bool __pure __init tpacpi_is_fw_digit(const char c)
{
return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z');
}
static bool __pure __init tpacpi_is_valid_fw_id(const char* const s,
const char t)
{
return s && strlen(s) >= 8 &&
tpacpi_is_fw_digit(s[0]) &&
tpacpi_is_fw_digit(s[1]) &&
s[2] == t &&
(s[3] == 'T' || s[3] == 'N') &&
tpacpi_is_fw_digit(s[4]) &&
tpacpi_is_fw_digit(s[5]);
}
static int __must_check __init get_thinkpad_model_data(
struct thinkpad_id_data *tp)
{
const struct dmi_device *dev = NULL;
char ec_fw_string[18];
char const *s;
if (!tp)
return -EINVAL;
memset(tp, 0, sizeof(*tp));
if (dmi_name_in_vendors("IBM"))
tp->vendor = PCI_VENDOR_ID_IBM;
else if (dmi_name_in_vendors("LENOVO"))
tp->vendor = PCI_VENDOR_ID_LENOVO;
else
return 0;
s = dmi_get_system_info(DMI_BIOS_VERSION);
tp->bios_version_str = kstrdup(s, GFP_KERNEL);
if (s && !tp->bios_version_str)
return -ENOMEM;
if (!(tpacpi_is_valid_fw_id(tp->bios_version_str, 'E') ||
tpacpi_is_valid_fw_id(tp->bios_version_str, 'C')))
return 0;
tp->bios_model = tp->bios_version_str[0]
| (tp->bios_version_str[1] << 8);
tp->bios_release = (tp->bios_version_str[4] << 8)
| tp->bios_version_str[5];
while ((dev = dmi_find_device(DMI_DEV_TYPE_OEM_STRING, NULL, dev))) {
if (sscanf(dev->name,
"IBM ThinkPad Embedded Controller -[%17c",
ec_fw_string) == 1) {
ec_fw_string[sizeof(ec_fw_string) - 1] = 0;
ec_fw_string[strcspn(ec_fw_string, " ]")] = 0;
tp->ec_version_str = kstrdup(ec_fw_string, GFP_KERNEL);
if (!tp->ec_version_str)
return -ENOMEM;
if (tpacpi_is_valid_fw_id(ec_fw_string, 'H')) {
tp->ec_model = ec_fw_string[0]
| (ec_fw_string[1] << 8);
tp->ec_release = (ec_fw_string[4] << 8)
| ec_fw_string[5];
} else {
pr_notice("ThinkPad firmware release %s "
"doesn't match the known patterns\n",
ec_fw_string);
pr_notice("please report this to %s\n",
TPACPI_MAIL);
}
break;
}
}
s = dmi_get_system_info(DMI_PRODUCT_VERSION);
if (s && !(strnicmp(s, "ThinkPad", 8) && strnicmp(s, "Lenovo", 6))) {
tp->model_str = kstrdup(s, GFP_KERNEL);
if (!tp->model_str)
return -ENOMEM;
} else {
s = dmi_get_system_info(DMI_BIOS_VENDOR);
if (s && !(strnicmp(s, "Lenovo", 6))) {
tp->model_str = kstrdup(s, GFP_KERNEL);
if (!tp->model_str)
return -ENOMEM;
}
}
s = dmi_get_system_info(DMI_PRODUCT_NAME);
tp->nummodel_str = kstrdup(s, GFP_KERNEL);
if (s && !tp->nummodel_str)
return -ENOMEM;
return 0;
}
static int __init probe_for_thinkpad(void)
{
int is_thinkpad;
if (acpi_disabled)
return -ENODEV;
if (!tpacpi_is_ibm() && !tpacpi_is_lenovo())
return -ENODEV;
is_thinkpad = (thinkpad_id.model_str != NULL) ||
(thinkpad_id.ec_model != 0) ||
tpacpi_is_fw_known();
tpacpi_acpi_handle_locate("ec", TPACPI_ACPI_EC_HID, &ec_handle);
if (!ec_handle) {
if (is_thinkpad)
pr_err("Not yet supported ThinkPad detected!\n");
return -ENODEV;
}
if (!is_thinkpad && !force_load)
return -ENODEV;
return 0;
}
static void __init thinkpad_acpi_init_banner(void)
{
pr_info("%s v%s\n", TPACPI_DESC, TPACPI_VERSION);
pr_info("%s\n", TPACPI_URL);
pr_info("ThinkPad BIOS %s, EC %s\n",
(thinkpad_id.bios_version_str) ?
thinkpad_id.bios_version_str : "unknown",
(thinkpad_id.ec_version_str) ?
thinkpad_id.ec_version_str : "unknown");
BUG_ON(!thinkpad_id.vendor);
if (thinkpad_id.model_str)
pr_info("%s %s, model %s\n",
(thinkpad_id.vendor == PCI_VENDOR_ID_IBM) ?
"IBM" : ((thinkpad_id.vendor ==
PCI_VENDOR_ID_LENOVO) ?
"Lenovo" : "Unknown vendor"),
thinkpad_id.model_str,
(thinkpad_id.nummodel_str) ?
thinkpad_id.nummodel_str : "unknown");
}
static int __init set_ibm_param(const char *val, struct kernel_param *kp)
{
unsigned int i;
struct ibm_struct *ibm;
if (!kp || !kp->name || !val)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(ibms_init); i++) {
ibm = ibms_init[i].data;
WARN_ON(ibm == NULL);
if (!ibm || !ibm->name)
continue;
if (strcmp(ibm->name, kp->name) == 0 && ibm->write) {
if (strlen(val) > sizeof(ibms_init[i].param) - 2)
return -ENOSPC;
strcpy(ibms_init[i].param, val);
strcat(ibms_init[i].param, ",");
return 0;
}
}
return -EINVAL;
}
static void thinkpad_acpi_module_exit(void)
{
struct ibm_struct *ibm, *itmp;
tpacpi_lifecycle = TPACPI_LIFE_EXITING;
list_for_each_entry_safe_reverse(ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
ibm_exit(ibm);
}
dbg_printk(TPACPI_DBG_INIT, "finished subdriver exit path...\n");
if (tpacpi_inputdev) {
if (tp_features.input_device_registered)
input_unregister_device(tpacpi_inputdev);
else
input_free_device(tpacpi_inputdev);
kfree(hotkey_keycode_map);
}
if (tpacpi_hwmon)
hwmon_device_unregister(tpacpi_hwmon);
if (tp_features.sensors_pdev_attrs_registered)
device_remove_file(&tpacpi_sensors_pdev->dev,
&dev_attr_thinkpad_acpi_pdev_name);
if (tpacpi_sensors_pdev)
platform_device_unregister(tpacpi_sensors_pdev);
if (tpacpi_pdev)
platform_device_unregister(tpacpi_pdev);
if (tp_features.sensors_pdrv_attrs_registered)
tpacpi_remove_driver_attributes(&tpacpi_hwmon_pdriver.driver);
if (tp_features.platform_drv_attrs_registered)
tpacpi_remove_driver_attributes(&tpacpi_pdriver.driver);
if (tp_features.sensors_pdrv_registered)
platform_driver_unregister(&tpacpi_hwmon_pdriver);
if (tp_features.platform_drv_registered)
platform_driver_unregister(&tpacpi_pdriver);
if (proc_dir)
remove_proc_entry(TPACPI_PROC_DIR, acpi_root_dir);
if (tpacpi_wq)
destroy_workqueue(tpacpi_wq);
kfree(thinkpad_id.bios_version_str);
kfree(thinkpad_id.ec_version_str);
kfree(thinkpad_id.model_str);
kfree(thinkpad_id.nummodel_str);
}
static int __init thinkpad_acpi_module_init(void)
{
int ret, i;
tpacpi_lifecycle = TPACPI_LIFE_INIT;
ret = get_thinkpad_model_data(&thinkpad_id);
if (ret) {
pr_err("unable to get DMI data: %d\n", ret);
thinkpad_acpi_module_exit();
return ret;
}
ret = probe_for_thinkpad();
if (ret) {
thinkpad_acpi_module_exit();
return ret;
}
thinkpad_acpi_init_banner();
tpacpi_check_outdated_fw();
TPACPI_ACPIHANDLE_INIT(ecrd);
TPACPI_ACPIHANDLE_INIT(ecwr);
tpacpi_wq = create_singlethread_workqueue(TPACPI_WORKQUEUE_NAME);
if (!tpacpi_wq) {
thinkpad_acpi_module_exit();
return -ENOMEM;
}
proc_dir = proc_mkdir(TPACPI_PROC_DIR, acpi_root_dir);
if (!proc_dir) {
pr_err("unable to create proc dir " TPACPI_PROC_DIR "\n");
thinkpad_acpi_module_exit();
return -ENODEV;
}
ret = platform_driver_register(&tpacpi_pdriver);
if (ret) {
pr_err("unable to register main platform driver\n");
thinkpad_acpi_module_exit();
return ret;
}
tp_features.platform_drv_registered = 1;
ret = platform_driver_register(&tpacpi_hwmon_pdriver);
if (ret) {
pr_err("unable to register hwmon platform driver\n");
thinkpad_acpi_module_exit();
return ret;
}
tp_features.sensors_pdrv_registered = 1;
ret = tpacpi_create_driver_attributes(&tpacpi_pdriver.driver);
if (!ret) {
tp_features.platform_drv_attrs_registered = 1;
ret = tpacpi_create_driver_attributes(
&tpacpi_hwmon_pdriver.driver);
}
if (ret) {
pr_err("unable to create sysfs driver attributes\n");
thinkpad_acpi_module_exit();
return ret;
}
tp_features.sensors_pdrv_attrs_registered = 1;
tpacpi_pdev = platform_device_register_simple(TPACPI_DRVR_NAME, -1,
NULL, 0);
if (IS_ERR(tpacpi_pdev)) {
ret = PTR_ERR(tpacpi_pdev);
tpacpi_pdev = NULL;
pr_err("unable to register platform device\n");
thinkpad_acpi_module_exit();
return ret;
}
tpacpi_sensors_pdev = platform_device_register_simple(
TPACPI_HWMON_DRVR_NAME,
-1, NULL, 0);
if (IS_ERR(tpacpi_sensors_pdev)) {
ret = PTR_ERR(tpacpi_sensors_pdev);
tpacpi_sensors_pdev = NULL;
pr_err("unable to register hwmon platform device\n");
thinkpad_acpi_module_exit();
return ret;
}
ret = device_create_file(&tpacpi_sensors_pdev->dev,
&dev_attr_thinkpad_acpi_pdev_name);
if (ret) {
pr_err("unable to create sysfs hwmon device attributes\n");
thinkpad_acpi_module_exit();
return ret;
}
tp_features.sensors_pdev_attrs_registered = 1;
tpacpi_hwmon = hwmon_device_register(&tpacpi_sensors_pdev->dev);
if (IS_ERR(tpacpi_hwmon)) {
ret = PTR_ERR(tpacpi_hwmon);
tpacpi_hwmon = NULL;
pr_err("unable to register hwmon device\n");
thinkpad_acpi_module_exit();
return ret;
}
mutex_init(&tpacpi_inputdev_send_mutex);
tpacpi_inputdev = input_allocate_device();
if (!tpacpi_inputdev) {
thinkpad_acpi_module_exit();
return -ENOMEM;
} else {
tpacpi_inputdev->name = "ThinkPad Extra Buttons";
tpacpi_inputdev->phys = TPACPI_DRVR_NAME "/input0";
tpacpi_inputdev->id.bustype = BUS_HOST;
tpacpi_inputdev->id.vendor = thinkpad_id.vendor;
tpacpi_inputdev->id.product = TPACPI_HKEY_INPUT_PRODUCT;
tpacpi_inputdev->id.version = TPACPI_HKEY_INPUT_VERSION;
tpacpi_inputdev->dev.parent = &tpacpi_pdev->dev;
}
tpacpi_detect_brightness_capabilities();
for (i = 0; i < ARRAY_SIZE(ibms_init); i++) {
ret = ibm_init(&ibms_init[i]);
if (ret >= 0 && *ibms_init[i].param)
ret = ibms_init[i].data->write(ibms_init[i].param);
if (ret < 0) {
thinkpad_acpi_module_exit();
return ret;
}
}
tpacpi_lifecycle = TPACPI_LIFE_RUNNING;
ret = input_register_device(tpacpi_inputdev);
if (ret < 0) {
pr_err("unable to register input device\n");
thinkpad_acpi_module_exit();
return ret;
} else {
tp_features.input_device_registered = 1;
}
return 0;
}
