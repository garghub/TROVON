static int qib_parse_ushort(const char *str, unsigned short *valp)
{
unsigned long val;
char *end;
int ret;
if (!isdigit(str[0])) {
ret = -EINVAL;
goto bail;
}
val = simple_strtoul(str, &end, 0);
if (val > 0xffff) {
ret = -EINVAL;
goto bail;
}
*valp = val;
ret = end + 1 - str;
if (ret == 0)
ret = -EINVAL;
bail:
return ret;
}
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
ret = qib_parse_ushort(buf, &val);
if (ret >= 0)
ret = dd->f_set_ib_cfg(ppd, QIB_IB_CFG_HRTBT, val);
if (ret < 0)
qib_dev_err(dd, "attempt to set invalid Heartbeat enable\n");
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
ret = qib_parse_ushort(buf, &val);
if (ret > 0)
qib_set_led_override(ppd, val);
else
qib_dev_err(dd, "attempt to set invalid LED override\n");
return ret < 0 ? ret : count;
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
static void qib_port_release(struct kobject *kobj)
{
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
char *endp;
long val = simple_strtol(buf, &endp, 0);
if (val < 0 || endp == buf)
return -EINVAL;
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
return scnprintf(buf, PAGE_SIZE, "%u\n", dd->cfgctxts -
dd->first_user_ctxt);
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
qib_dev_err(dd, "Skipping infiniband class with "
"invalid port %u\n", port_num);
ret = -ENODEV;
goto bail;
}
ppd = &dd->pport[port_num - 1];
ret = kobject_init_and_add(&ppd->pport_kobj, &qib_port_ktype, kobj,
"linkcontrol");
if (ret) {
qib_dev_err(dd, "Skipping linkcontrol sysfs info, "
"(err %d) port %u\n", ret, port_num);
goto bail;
}
kobject_uevent(&ppd->pport_kobj, KOBJ_ADD);
ret = kobject_init_and_add(&ppd->sl2vl_kobj, &qib_sl2vl_ktype, kobj,
"sl2vl");
if (ret) {
qib_dev_err(dd, "Skipping sl2vl sysfs info, "
"(err %d) port %u\n", ret, port_num);
goto bail_sl;
}
kobject_uevent(&ppd->sl2vl_kobj, KOBJ_ADD);
ret = kobject_init_and_add(&ppd->diagc_kobj, &qib_diagc_ktype, kobj,
"diag_counters");
if (ret) {
qib_dev_err(dd, "Skipping diag_counters sysfs info, "
"(err %d) port %u\n", ret, port_num);
goto bail_diagc;
}
kobject_uevent(&ppd->diagc_kobj, KOBJ_ADD);
return 0;
bail_diagc:
kobject_put(&ppd->sl2vl_kobj);
bail_sl:
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
return ret;
}
return 0;
}
void qib_verbs_unregister_sysfs(struct qib_devdata *dd)
{
struct qib_pportdata *ppd;
int i;
for (i = 0; i < dd->num_pports; i++) {
ppd = &dd->pport[i];
kobject_put(&ppd->pport_kobj);
kobject_put(&ppd->sl2vl_kobj);
}
}
