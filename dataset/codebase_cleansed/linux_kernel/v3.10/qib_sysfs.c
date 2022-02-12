static ssize_t show_hrtbt_enb(struct qib_pportdata *ppd, char *buf)
{
struct qib_devdata *dd = ppd->dd;
int ret;
ret = dd->f_get_ib_cfg(ppd, QIB_IB_CFG_HRTBT);
ret = scnprintf(buf, PAGE_SIZE, "%d\n", ret);
return ret;
}
static ssize_t store_hrtbt_enb(struct qib_pportdata *ppd, const char *buf,
size_t count)
{
struct qib_devdata *dd = ppd->dd;
int ret;
u16 val;
ret = kstrtou16(buf, 0, &val);
if (ret) {
qib_dev_err(dd, "attempt to set invalid Heartbeat enable\n");
return ret;
}
ret = dd->f_set_ib_cfg(ppd, QIB_IB_CFG_HRTBT, val);
return ret < 0 ? ret : count;
}
static ssize_t store_loopback(struct qib_pportdata *ppd, const char *buf,
size_t count)
{
struct qib_devdata *dd = ppd->dd;
int ret = count, r;
r = dd->f_set_ib_loopback(ppd, buf);
if (r < 0)
ret = r;
return ret;
}
static ssize_t store_led_override(struct qib_pportdata *ppd, const char *buf,
size_t count)
{
struct qib_devdata *dd = ppd->dd;
int ret;
u16 val;
ret = kstrtou16(buf, 0, &val);
if (ret) {
qib_dev_err(dd, "attempt to set invalid LED override\n");
return ret;
}
qib_set_led_override(ppd, val);
return count;
}
static ssize_t show_status(struct qib_pportdata *ppd, char *buf)
{
ssize_t ret;
if (!ppd->statusp)
ret = -EINVAL;
else
ret = scnprintf(buf, PAGE_SIZE, "0x%llx\n",
(unsigned long long) *(ppd->statusp));
return ret;
}
static ssize_t show_status_str(struct qib_pportdata *ppd, char *buf)
{
int i, any;
u64 s;
ssize_t ret;
if (!ppd->statusp) {
ret = -EINVAL;
goto bail;
}
s = *(ppd->statusp);
*buf = '\0';
for (any = i = 0; s && qib_status_str[i]; i++) {
if (s & 1) {
if (any && strlcat(buf, " ", PAGE_SIZE) >= PAGE_SIZE)
break;
if (strlcat(buf, qib_status_str[i], PAGE_SIZE) >=
PAGE_SIZE)
break;
any = 1;
}
s >>= 1;
}
if (any)
strlcat(buf, "\n", PAGE_SIZE);
ret = strlen(buf);
bail:
return ret;
}
static ssize_t read_cc_table_bin(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t count)
{
int ret;
struct qib_pportdata *ppd =
container_of(kobj, struct qib_pportdata, pport_cc_kobj);
if (!qib_cc_table_size || !ppd->ccti_entries_shadow)
return -EINVAL;
ret = ppd->total_cct_entry * sizeof(struct ib_cc_table_entry_shadow)
+ sizeof(__be16);
if (pos > ret)
return -EINVAL;
if (count > ret - pos)
count = ret - pos;
if (!count)
return count;
spin_lock(&ppd->cc_shadow_lock);
memcpy(buf, ppd->ccti_entries_shadow, count);
spin_unlock(&ppd->cc_shadow_lock);
return count;
}
static void qib_port_release(struct kobject *kobj)
{
}
static ssize_t read_cc_setting_bin(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t count)
{
int ret;
struct qib_pportdata *ppd =
container_of(kobj, struct qib_pportdata, pport_cc_kobj);
if (!qib_cc_table_size || !ppd->congestion_entries_shadow)
return -EINVAL;
ret = sizeof(struct ib_cc_congestion_setting_attr_shadow);
if (pos > ret)
return -EINVAL;
if (count > ret - pos)
count = ret - pos;
if (!count)
return count;
spin_lock(&ppd->cc_shadow_lock);
memcpy(buf, ppd->congestion_entries_shadow, count);
spin_unlock(&ppd->cc_shadow_lock);
return count;
}
static ssize_t qib_portattr_show(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct qib_port_attr *pattr =
container_of(attr, struct qib_port_attr, attr);
struct qib_pportdata *ppd =
container_of(kobj, struct qib_pportdata, pport_kobj);
return pattr->show(ppd, buf);
}
static ssize_t qib_portattr_store(struct kobject *kobj,
struct attribute *attr, const char *buf, size_t len)
{
struct qib_port_attr *pattr =
container_of(attr, struct qib_port_attr, attr);
struct qib_pportdata *ppd =
container_of(kobj, struct qib_pportdata, pport_kobj);
return pattr->store(ppd, buf, len);
}
static ssize_t sl2vl_attr_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct qib_sl2vl_attr *sattr =
container_of(attr, struct qib_sl2vl_attr, attr);
struct qib_pportdata *ppd =
container_of(kobj, struct qib_pportdata, sl2vl_kobj);
struct qib_ibport *qibp = &ppd->ibport_data;
return sprintf(buf, "%u\n", qibp->sl_to_vl[sattr->sl]);
}
static ssize_t diagc_attr_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct qib_diagc_attr *dattr =
container_of(attr, struct qib_diagc_attr, attr);
struct qib_pportdata *ppd =
container_of(kobj, struct qib_pportdata, diagc_kobj);
struct qib_ibport *qibp = &ppd->ibport_data;
return sprintf(buf, "%u\n", *(u32 *)((char *)qibp + dattr->counter));
}
static ssize_t diagc_attr_store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t size)
{
struct qib_diagc_attr *dattr =
container_of(attr, struct qib_diagc_attr, attr);
struct qib_pportdata *ppd =
container_of(kobj, struct qib_pportdata, diagc_kobj);
struct qib_ibport *qibp = &ppd->ibport_data;
u32 val;
int ret;
ret = kstrtou32(buf, 0, &val);
if (ret)
return ret;
*(u32 *)((char *) qibp + dattr->counter) = val;
return size;
}
static ssize_t show_rev(struct device *device, struct device_attribute *attr,
char *buf)
{
struct qib_ibdev *dev =
container_of(device, struct qib_ibdev, ibdev.dev);
return sprintf(buf, "%x\n", dd_from_dev(dev)->minrev);
}
static ssize_t show_hca(struct device *device, struct device_attribute *attr,
char *buf)
{
struct qib_ibdev *dev =
container_of(device, struct qib_ibdev, ibdev.dev);
struct qib_devdata *dd = dd_from_dev(dev);
int ret;
if (!dd->boardname)
ret = -EINVAL;
else
ret = scnprintf(buf, PAGE_SIZE, "%s\n", dd->boardname);
return ret;
}
static ssize_t show_version(struct device *device,
struct device_attribute *attr, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%s", (char *)ib_qib_version);
}
static ssize_t show_boardversion(struct device *device,
struct device_attribute *attr, char *buf)
{
struct qib_ibdev *dev =
container_of(device, struct qib_ibdev, ibdev.dev);
struct qib_devdata *dd = dd_from_dev(dev);
return scnprintf(buf, PAGE_SIZE, "%s", dd->boardversion);
}
static ssize_t show_localbus_info(struct device *device,
struct device_attribute *attr, char *buf)
{
struct qib_ibdev *dev =
container_of(device, struct qib_ibdev, ibdev.dev);
struct qib_devdata *dd = dd_from_dev(dev);
return scnprintf(buf, PAGE_SIZE, "%s", dd->lbus_info);
}
static ssize_t show_nctxts(struct device *device,
struct device_attribute *attr, char *buf)
{
struct qib_ibdev *dev =
container_of(device, struct qib_ibdev, ibdev.dev);
struct qib_devdata *dd = dd_from_dev(dev);
return scnprintf(buf, PAGE_SIZE, "%u\n",
(dd->first_user_ctxt > dd->cfgctxts) ? 0 :
(dd->cfgctxts - dd->first_user_ctxt));
}
static ssize_t show_nfreectxts(struct device *device,
struct device_attribute *attr, char *buf)
{
struct qib_ibdev *dev =
container_of(device, struct qib_ibdev, ibdev.dev);
struct qib_devdata *dd = dd_from_dev(dev);
return scnprintf(buf, PAGE_SIZE, "%u\n", dd->freectxts);
}
static ssize_t show_serial(struct device *device,
struct device_attribute *attr, char *buf)
{
struct qib_ibdev *dev =
container_of(device, struct qib_ibdev, ibdev.dev);
struct qib_devdata *dd = dd_from_dev(dev);
buf[sizeof dd->serial] = '\0';
memcpy(buf, dd->serial, sizeof dd->serial);
strcat(buf, "\n");
return strlen(buf);
}
static ssize_t store_chip_reset(struct device *device,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct qib_ibdev *dev =
container_of(device, struct qib_ibdev, ibdev.dev);
struct qib_devdata *dd = dd_from_dev(dev);
int ret;
if (count < 5 || memcmp(buf, "reset", 5) || !dd->diag_client) {
ret = -EINVAL;
goto bail;
}
ret = qib_reset_device(dd->unit);
bail:
return ret < 0 ? ret : count;
}
static ssize_t show_logged_errs(struct device *device,
struct device_attribute *attr, char *buf)
{
struct qib_ibdev *dev =
container_of(device, struct qib_ibdev, ibdev.dev);
struct qib_devdata *dd = dd_from_dev(dev);
int idx, count;
if (qib_update_eeprom_log(dd) != 0)
return -ENXIO;
count = 0;
for (idx = 0; idx < QIB_EEP_LOG_CNT; ++idx) {
count += scnprintf(buf + count, PAGE_SIZE - count, "%d%c",
dd->eep_st_errs[idx],
idx == (QIB_EEP_LOG_CNT - 1) ? '\n' : ' ');
}
return count;
}
static ssize_t show_tempsense(struct device *device,
struct device_attribute *attr, char *buf)
{
struct qib_ibdev *dev =
container_of(device, struct qib_ibdev, ibdev.dev);
struct qib_devdata *dd = dd_from_dev(dev);
int ret;
int idx;
u8 regvals[8];
ret = -ENXIO;
for (idx = 0; idx < 8; ++idx) {
if (idx == 6)
continue;
ret = dd->f_tempsense_rd(dd, idx);
if (ret < 0)
break;
regvals[idx] = ret;
}
if (idx == 8)
ret = scnprintf(buf, PAGE_SIZE, "%d %d %02X %02X %d %d\n",
*(signed char *)(regvals),
*(signed char *)(regvals + 1),
regvals[2], regvals[3],
*(signed char *)(regvals + 5),
*(signed char *)(regvals + 7));
return ret;
}
int qib_create_port_files(struct ib_device *ibdev, u8 port_num,
struct kobject *kobj)
{
struct qib_pportdata *ppd;
struct qib_devdata *dd = dd_from_ibdev(ibdev);
int ret;
if (!port_num || port_num > dd->num_pports) {
qib_dev_err(dd,
"Skipping infiniband class with invalid port %u\n",
port_num);
ret = -ENODEV;
goto bail;
}
ppd = &dd->pport[port_num - 1];
ret = kobject_init_and_add(&ppd->pport_kobj, &qib_port_ktype, kobj,
"linkcontrol");
if (ret) {
qib_dev_err(dd,
"Skipping linkcontrol sysfs info, (err %d) port %u\n",
ret, port_num);
goto bail;
}
kobject_uevent(&ppd->pport_kobj, KOBJ_ADD);
ret = kobject_init_and_add(&ppd->sl2vl_kobj, &qib_sl2vl_ktype, kobj,
"sl2vl");
if (ret) {
qib_dev_err(dd,
"Skipping sl2vl sysfs info, (err %d) port %u\n",
ret, port_num);
goto bail_link;
}
kobject_uevent(&ppd->sl2vl_kobj, KOBJ_ADD);
ret = kobject_init_and_add(&ppd->diagc_kobj, &qib_diagc_ktype, kobj,
"diag_counters");
if (ret) {
qib_dev_err(dd,
"Skipping diag_counters sysfs info, (err %d) port %u\n",
ret, port_num);
goto bail_sl;
}
kobject_uevent(&ppd->diagc_kobj, KOBJ_ADD);
if (!qib_cc_table_size || !ppd->congestion_entries_shadow)
return 0;
ret = kobject_init_and_add(&ppd->pport_cc_kobj, &qib_port_cc_ktype,
kobj, "CCMgtA");
if (ret) {
qib_dev_err(dd,
"Skipping Congestion Control sysfs info, (err %d) port %u\n",
ret, port_num);
goto bail_diagc;
}
kobject_uevent(&ppd->pport_cc_kobj, KOBJ_ADD);
ret = sysfs_create_bin_file(&ppd->pport_cc_kobj,
&cc_setting_bin_attr);
if (ret) {
qib_dev_err(dd,
"Skipping Congestion Control setting sysfs info, (err %d) port %u\n",
ret, port_num);
goto bail_cc;
}
ret = sysfs_create_bin_file(&ppd->pport_cc_kobj,
&cc_table_bin_attr);
if (ret) {
qib_dev_err(dd,
"Skipping Congestion Control table sysfs info, (err %d) port %u\n",
ret, port_num);
goto bail_cc_entry_bin;
}
qib_devinfo(dd->pcidev,
"IB%u: Congestion Control Agent enabled for port %d\n",
dd->unit, port_num);
return 0;
bail_cc_entry_bin:
sysfs_remove_bin_file(&ppd->pport_cc_kobj, &cc_setting_bin_attr);
bail_cc:
kobject_put(&ppd->pport_cc_kobj);
bail_diagc:
kobject_put(&ppd->diagc_kobj);
bail_sl:
kobject_put(&ppd->sl2vl_kobj);
bail_link:
kobject_put(&ppd->pport_kobj);
bail:
return ret;
}
int qib_verbs_register_sysfs(struct qib_devdata *dd)
{
struct ib_device *dev = &dd->verbs_dev.ibdev;
int i, ret;
for (i = 0; i < ARRAY_SIZE(qib_attributes); ++i) {
ret = device_create_file(&dev->dev, qib_attributes[i]);
if (ret)
goto bail;
}
return 0;
bail:
for (i = 0; i < ARRAY_SIZE(qib_attributes); ++i)
device_remove_file(&dev->dev, qib_attributes[i]);
return ret;
}
void qib_verbs_unregister_sysfs(struct qib_devdata *dd)
{
struct qib_pportdata *ppd;
int i;
for (i = 0; i < dd->num_pports; i++) {
ppd = &dd->pport[i];
if (qib_cc_table_size &&
ppd->congestion_entries_shadow) {
sysfs_remove_bin_file(&ppd->pport_cc_kobj,
&cc_setting_bin_attr);
sysfs_remove_bin_file(&ppd->pport_cc_kobj,
&cc_table_bin_attr);
kobject_put(&ppd->pport_cc_kobj);
}
kobject_put(&ppd->sl2vl_kobj);
kobject_put(&ppd->pport_kobj);
}
}
