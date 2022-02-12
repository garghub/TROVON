int ipath_parse_ushort(const char *str, unsigned short *valp)
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
static ssize_t show_version(struct device_driver *dev, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%s", ib_ipath_version);
}
static ssize_t show_num_units(struct device_driver *dev, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n",
ipath_count_units(NULL, NULL, NULL));
}
static ssize_t show_status(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
ssize_t ret;
if (!dd->ipath_statusp) {
ret = -EINVAL;
goto bail;
}
ret = scnprintf(buf, PAGE_SIZE, "0x%llx\n",
(unsigned long long) *(dd->ipath_statusp));
bail:
return ret;
}
static ssize_t show_status_str(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int i, any;
u64 s;
ssize_t ret;
if (!dd->ipath_statusp) {
ret = -EINVAL;
goto bail;
}
s = *(dd->ipath_statusp);
*buf = '\0';
for (any = i = 0; s && ipath_status_str[i]; i++) {
if (s & 1) {
if (any && strlcat(buf, " ", PAGE_SIZE) >=
PAGE_SIZE)
break;
if (strlcat(buf, ipath_status_str[i],
PAGE_SIZE) >= PAGE_SIZE)
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
static ssize_t show_boardversion(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%s", dd->ipath_boardversion);
}
static ssize_t show_localbus_info(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%s", dd->ipath_lbus_info);
}
static ssize_t show_lmc(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%u\n", dd->ipath_lmc);
}
static ssize_t store_lmc(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
u16 lmc = 0;
int ret;
ret = ipath_parse_ushort(buf, &lmc);
if (ret < 0)
goto invalid;
if (lmc > 7) {
ret = -EINVAL;
goto invalid;
}
ipath_set_lid(dd, dd->ipath_lid, lmc);
goto bail;
invalid:
ipath_dev_err(dd, "attempt to set invalid LMC %u\n", lmc);
bail:
return ret;
}
static ssize_t show_lid(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "0x%x\n", dd->ipath_lid);
}
static ssize_t store_lid(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
u16 lid = 0;
int ret;
ret = ipath_parse_ushort(buf, &lid);
if (ret < 0)
goto invalid;
if (lid == 0 || lid >= IPATH_MULTICAST_LID_BASE) {
ret = -EINVAL;
goto invalid;
}
ipath_set_lid(dd, lid, dd->ipath_lmc);
goto bail;
invalid:
ipath_dev_err(dd, "attempt to set invalid LID 0x%x\n", lid);
bail:
return ret;
}
static ssize_t show_mlid(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "0x%x\n", dd->ipath_mlid);
}
static ssize_t store_mlid(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
u16 mlid;
int ret;
ret = ipath_parse_ushort(buf, &mlid);
if (ret < 0 || mlid < IPATH_MULTICAST_LID_BASE)
goto invalid;
dd->ipath_mlid = mlid;
goto bail;
invalid:
ipath_dev_err(dd, "attempt to set invalid MLID\n");
bail:
return ret;
}
static ssize_t show_guid(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
u8 *guid;
guid = (u8 *) & (dd->ipath_guid);
return scnprintf(buf, PAGE_SIZE,
"%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x\n",
guid[0], guid[1], guid[2], guid[3],
guid[4], guid[5], guid[6], guid[7]);
}
static ssize_t store_guid(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
ssize_t ret;
unsigned short guid[8];
__be64 new_guid;
u8 *ng;
int i;
if (sscanf(buf, "%hx:%hx:%hx:%hx:%hx:%hx:%hx:%hx",
&guid[0], &guid[1], &guid[2], &guid[3],
&guid[4], &guid[5], &guid[6], &guid[7]) != 8)
goto invalid;
ng = (u8 *) &new_guid;
for (i = 0; i < 8; i++) {
if (guid[i] > 0xff)
goto invalid;
ng[i] = guid[i];
}
if (new_guid == 0)
goto invalid;
dd->ipath_guid = new_guid;
dd->ipath_nguid = 1;
if (dd->verbs_dev)
dd->verbs_dev->ibdev.node_guid = new_guid;
ret = strlen(buf);
goto bail;
invalid:
ipath_dev_err(dd, "attempt to set invalid GUID\n");
ret = -EINVAL;
bail:
return ret;
}
static ssize_t show_nguid(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%u\n", dd->ipath_nguid);
}
static ssize_t show_nports(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%u\n", dd->ipath_cfgports - 1);
}
static ssize_t show_serial(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
buf[sizeof dd->ipath_serial] = '\0';
memcpy(buf, dd->ipath_serial, sizeof dd->ipath_serial);
strcat(buf, "\n");
return strlen(buf);
}
static ssize_t show_unit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%u\n", dd->ipath_unit);
}
static ssize_t show_jint_max_packets(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%hu\n", dd->ipath_jint_max_packets);
}
static ssize_t store_jint_max_packets(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
u16 v = 0;
int ret;
ret = ipath_parse_ushort(buf, &v);
if (ret < 0)
ipath_dev_err(dd, "invalid jint_max_packets.\n");
else
dd->ipath_f_config_jint(dd, dd->ipath_jint_idle_ticks, v);
return ret;
}
static ssize_t show_jint_idle_ticks(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%hu\n", dd->ipath_jint_idle_ticks);
}
static ssize_t store_jint_idle_ticks(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
u16 v = 0;
int ret;
ret = ipath_parse_ushort(buf, &v);
if (ret < 0)
ipath_dev_err(dd, "invalid jint_idle_ticks.\n");
else
dd->ipath_f_config_jint(dd, v, dd->ipath_jint_max_packets);
return ret;
}
static ssize_t store_reset(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret;
if (count < 5 || memcmp(buf, "reset", 5)) {
ret = -EINVAL;
goto bail;
}
if (dd->ipath_flags & IPATH_DISABLED) {
dev_info(dev,"Unit %d is disabled, can't reset\n",
dd->ipath_unit);
ret = -EINVAL;
goto bail;
}
ret = ipath_reset_device(dd->ipath_unit);
bail:
return ret<0 ? ret : count;
}
static ssize_t store_link_state(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret, r;
u16 state;
ret = ipath_parse_ushort(buf, &state);
if (ret < 0)
goto invalid;
r = ipath_set_linkstate(dd, state);
if (r < 0) {
ret = r;
goto bail;
}
goto bail;
invalid:
ipath_dev_err(dd, "attempt to set invalid link state\n");
bail:
return ret;
}
static ssize_t show_mtu(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%u\n", dd->ipath_ibmtu);
}
static ssize_t store_mtu(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
ssize_t ret;
u16 mtu = 0;
int r;
ret = ipath_parse_ushort(buf, &mtu);
if (ret < 0)
goto invalid;
r = ipath_set_mtu(dd, mtu);
if (r < 0)
ret = r;
goto bail;
invalid:
ipath_dev_err(dd, "attempt to set invalid MTU\n");
bail:
return ret;
}
static ssize_t show_enabled(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%u\n",
(dd->ipath_flags & IPATH_DISABLED) ? 0 : 1);
}
static ssize_t store_enabled(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
ssize_t ret;
u16 enable = 0;
ret = ipath_parse_ushort(buf, &enable);
if (ret < 0) {
ipath_dev_err(dd, "attempt to use non-numeric on enable\n");
goto bail;
}
if (enable) {
if (!(dd->ipath_flags & IPATH_DISABLED))
goto bail;
dev_info(dev, "Enabling unit %d\n", dd->ipath_unit);
ret = ipath_init_chip(dd, 1);
if (ret)
ipath_dev_err(dd, "Failed to enable unit %d\n",
dd->ipath_unit);
else {
dd->ipath_flags &= ~IPATH_DISABLED;
*dd->ipath_statusp &= ~IPATH_STATUS_ADMIN_DISABLED;
}
} else if (!(dd->ipath_flags & IPATH_DISABLED)) {
dev_info(dev, "Disabling unit %d\n", dd->ipath_unit);
ipath_shutdown_device(dd);
dd->ipath_flags |= IPATH_DISABLED;
*dd->ipath_statusp |= IPATH_STATUS_ADMIN_DISABLED;
}
bail:
return ret;
}
static ssize_t store_rx_pol_inv(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret, r;
u16 val;
ret = ipath_parse_ushort(buf, &val);
if (ret < 0)
goto invalid;
r = ipath_set_rx_pol_inv(dd, val);
if (r < 0) {
ret = r;
goto bail;
}
goto bail;
invalid:
ipath_dev_err(dd, "attempt to set invalid Rx Polarity invert\n");
bail:
return ret;
}
static ssize_t store_led_override(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret;
u16 val;
ret = ipath_parse_ushort(buf, &val);
if (ret > 0)
ipath_set_led_override(dd, val);
else
ipath_dev_err(dd, "attempt to set invalid LED override\n");
return ret;
}
static ssize_t show_logged_errs(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int idx, count;
if (ipath_update_eeprom_log(dd) != 0)
return -ENXIO;
count = 0;
for (idx = 0; idx < IPATH_EEP_LOG_CNT; ++idx) {
count += scnprintf(buf + count, PAGE_SIZE - count, "%d%c",
dd->ipath_eep_st_errs[idx],
idx == (IPATH_EEP_LOG_CNT - 1) ? '\n' : ' ');
}
return count;
}
static ssize_t show_hrtbt_enb(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret;
ret = dd->ipath_f_get_ib_cfg(dd, IPATH_IB_CFG_HRTBT);
if (ret >= 0)
ret = scnprintf(buf, PAGE_SIZE, "%d\n", ret);
return ret;
}
static ssize_t store_hrtbt_enb(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret, r;
u16 val;
ret = ipath_parse_ushort(buf, &val);
if (ret >= 0 && val > 3)
ret = -EINVAL;
if (ret < 0) {
ipath_dev_err(dd, "attempt to set invalid Heartbeat enable\n");
goto bail;
}
r = dd->ipath_f_set_ib_cfg(dd, IPATH_IB_CFG_HRTBT, val);
if (r < 0)
ret = r;
else if (val == IPATH_IB_HRTBT_OFF)
dd->ipath_flags |= IPATH_NO_HRTBT;
else
dd->ipath_flags &= ~IPATH_NO_HRTBT;
bail:
return ret;
}
static ssize_t show_lwid_enb(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret;
ret = dd->ipath_f_get_ib_cfg(dd, IPATH_IB_CFG_LWID_ENB);
if (ret >= 0)
ret = scnprintf(buf, PAGE_SIZE, "%d\n", ret);
return ret;
}
static ssize_t store_lwid_enb(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret, r;
u16 val;
ret = ipath_parse_ushort(buf, &val);
if (ret >= 0 && (val == 0 || val > 3))
ret = -EINVAL;
if (ret < 0) {
ipath_dev_err(dd,
"attempt to set invalid Link Width (enable)\n");
goto bail;
}
r = dd->ipath_f_set_ib_cfg(dd, IPATH_IB_CFG_LWID_ENB, val);
if (r < 0)
ret = r;
bail:
return ret;
}
static ssize_t show_lwid(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret;
ret = dd->ipath_f_get_ib_cfg(dd, IPATH_IB_CFG_LWID);
if (ret >= 0)
ret = scnprintf(buf, PAGE_SIZE, "%d\n", ret);
return ret;
}
static ssize_t show_spd_enb(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret;
ret = dd->ipath_f_get_ib_cfg(dd, IPATH_IB_CFG_SPD_ENB);
if (ret >= 0)
ret = scnprintf(buf, PAGE_SIZE, "%d\n", ret);
return ret;
}
static ssize_t store_spd_enb(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret, r;
u16 val;
ret = ipath_parse_ushort(buf, &val);
if (ret >= 0 && (val == 0 || val > (IPATH_IB_SDR | IPATH_IB_DDR)))
ret = -EINVAL;
if (ret < 0) {
ipath_dev_err(dd,
"attempt to set invalid Link Speed (enable)\n");
goto bail;
}
r = dd->ipath_f_set_ib_cfg(dd, IPATH_IB_CFG_SPD_ENB, val);
if (r < 0)
ret = r;
bail:
return ret;
}
static ssize_t show_spd(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret;
ret = dd->ipath_f_get_ib_cfg(dd, IPATH_IB_CFG_SPD);
if (ret >= 0)
ret = scnprintf(buf, PAGE_SIZE, "%d\n", ret);
return ret;
}
static ssize_t show_rx_polinv_enb(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret;
ret = dd->ipath_f_get_ib_cfg(dd, IPATH_IB_CFG_RXPOL_ENB);
if (ret >= 0)
ret = scnprintf(buf, PAGE_SIZE, "%d\n", ret);
return ret;
}
static ssize_t store_rx_polinv_enb(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret, r;
u16 val;
ret = ipath_parse_ushort(buf, &val);
if (ret >= 0 && val > 1) {
ipath_dev_err(dd,
"attempt to set invalid Rx Polarity (enable)\n");
ret = -EINVAL;
goto bail;
}
r = dd->ipath_f_set_ib_cfg(dd, IPATH_IB_CFG_RXPOL_ENB, val);
if (r < 0)
ret = r;
bail:
return ret;
}
static ssize_t show_lanerev_enb(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret;
ret = dd->ipath_f_get_ib_cfg(dd, IPATH_IB_CFG_LREV_ENB);
if (ret >= 0)
ret = scnprintf(buf, PAGE_SIZE, "%d\n", ret);
return ret;
}
static ssize_t store_lanerev_enb(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret, r;
u16 val;
ret = ipath_parse_ushort(buf, &val);
if (ret >= 0 && val > 1) {
ret = -EINVAL;
ipath_dev_err(dd,
"attempt to set invalid Lane reversal (enable)\n");
goto bail;
}
r = dd->ipath_f_set_ib_cfg(dd, IPATH_IB_CFG_LREV_ENB, val);
if (r < 0)
ret = r;
bail:
return ret;
}
static ssize_t store_tempsense(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret, stat;
u16 val;
ret = ipath_parse_ushort(buf, &val);
if (ret <= 0) {
ipath_dev_err(dd, "attempt to set invalid tempsense config\n");
goto bail;
}
stat = ipath_tempsense_write(dd, 9, (val == 0x7f7f) ? 0x80 : 0);
if (stat) {
ipath_dev_err(dd, "Unable to set tempsense config\n");
ret = -1;
goto bail;
}
stat = ipath_tempsense_write(dd, 0xB, (u8) (val & 0xFF));
if (stat) {
ipath_dev_err(dd, "Unable to set local Tcrit\n");
ret = -1;
goto bail;
}
stat = ipath_tempsense_write(dd, 0xD, (u8) (val >> 8));
if (stat) {
ipath_dev_err(dd, "Unable to set remote Tcrit\n");
ret = -1;
goto bail;
}
bail:
return ret;
}
static ssize_t show_tempsense(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ipath_devdata *dd = dev_get_drvdata(dev);
int ret;
int idx;
u8 regvals[8];
ret = -ENXIO;
for (idx = 0; idx < 8; ++idx) {
if (idx == 6)
continue;
ret = ipath_tempsense_read(dd, idx);
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
int ipath_expose_reset(struct device *dev)
{
static int exposed;
int ret;
if (!exposed) {
ret = device_create_file(dev, &dev_attr_reset);
exposed = 1;
} else {
ret = 0;
}
return ret;
}
int ipath_device_create_group(struct device *dev, struct ipath_devdata *dd)
{
int ret;
ret = sysfs_create_group(&dev->kobj, &dev_attr_group);
if (ret)
goto bail;
ret = sysfs_create_group(&dev->kobj, &dev_counter_attr_group);
if (ret)
goto bail_attrs;
if (dd->ipath_flags & IPATH_HAS_MULT_IB_SPEED) {
ret = device_create_file(dev, &dev_attr_jint_idle_ticks);
if (ret)
goto bail_counter;
ret = device_create_file(dev, &dev_attr_jint_max_packets);
if (ret)
goto bail_idle;
ret = sysfs_create_group(&dev->kobj, &dev_ibcfg_attr_group);
if (ret)
goto bail_max;
}
return 0;
bail_max:
device_remove_file(dev, &dev_attr_jint_max_packets);
bail_idle:
device_remove_file(dev, &dev_attr_jint_idle_ticks);
bail_counter:
sysfs_remove_group(&dev->kobj, &dev_counter_attr_group);
bail_attrs:
sysfs_remove_group(&dev->kobj, &dev_attr_group);
bail:
return ret;
}
void ipath_device_remove_group(struct device *dev, struct ipath_devdata *dd)
{
sysfs_remove_group(&dev->kobj, &dev_counter_attr_group);
if (dd->ipath_flags & IPATH_HAS_MULT_IB_SPEED) {
sysfs_remove_group(&dev->kobj, &dev_ibcfg_attr_group);
device_remove_file(dev, &dev_attr_jint_idle_ticks);
device_remove_file(dev, &dev_attr_jint_max_packets);
}
sysfs_remove_group(&dev->kobj, &dev_attr_group);
device_remove_file(dev, &dev_attr_reset);
}
