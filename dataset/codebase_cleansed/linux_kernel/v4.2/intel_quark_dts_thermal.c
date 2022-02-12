static int soc_dts_enable(struct thermal_zone_device *tzd)
{
u32 out;
struct soc_sensor_entry *aux_entry = tzd->devdata;
int ret;
ret = iosf_mbi_read(QRK_MBI_UNIT_RMU, QRK_MBI_RMU_READ,
QRK_DTS_REG_OFFSET_ENABLE, &out);
if (ret)
return ret;
if (out & QRK_DTS_ENABLE_BIT) {
aux_entry->mode = THERMAL_DEVICE_ENABLED;
return 0;
}
if (!aux_entry->locked) {
out |= QRK_DTS_ENABLE_BIT;
ret = iosf_mbi_write(QRK_MBI_UNIT_RMU, QRK_MBI_RMU_WRITE,
QRK_DTS_REG_OFFSET_ENABLE, out);
if (ret)
return ret;
aux_entry->mode = THERMAL_DEVICE_ENABLED;
} else {
aux_entry->mode = THERMAL_DEVICE_DISABLED;
pr_info("DTS is locked. Cannot enable DTS\n");
ret = -EPERM;
}
return ret;
}
static int soc_dts_disable(struct thermal_zone_device *tzd)
{
u32 out;
struct soc_sensor_entry *aux_entry = tzd->devdata;
int ret;
ret = iosf_mbi_read(QRK_MBI_UNIT_RMU, QRK_MBI_RMU_READ,
QRK_DTS_REG_OFFSET_ENABLE, &out);
if (ret)
return ret;
if (!(out & QRK_DTS_ENABLE_BIT)) {
aux_entry->mode = THERMAL_DEVICE_DISABLED;
return 0;
}
if (!aux_entry->locked) {
out &= ~QRK_DTS_ENABLE_BIT;
ret = iosf_mbi_write(QRK_MBI_UNIT_RMU, QRK_MBI_RMU_WRITE,
QRK_DTS_REG_OFFSET_ENABLE, out);
if (ret)
return ret;
aux_entry->mode = THERMAL_DEVICE_DISABLED;
} else {
aux_entry->mode = THERMAL_DEVICE_ENABLED;
pr_info("DTS is locked. Cannot disable DTS\n");
ret = -EPERM;
}
return ret;
}
static int _get_trip_temp(int trip, unsigned long *temp)
{
int status;
u32 out;
mutex_lock(&dts_update_mutex);
status = iosf_mbi_read(QRK_MBI_UNIT_RMU, QRK_MBI_RMU_READ,
QRK_DTS_REG_OFFSET_PTPS, &out);
mutex_unlock(&dts_update_mutex);
if (status)
return status;
*temp = (out >> (trip * QRK_DTS_SHIFT_TP)) & QRK_DTS_MASK_TP_THRES;
*temp -= QRK_DTS_TEMP_BASE;
return 0;
}
static inline int sys_get_trip_temp(struct thermal_zone_device *tzd,
int trip, unsigned long *temp)
{
return _get_trip_temp(trip, temp);
}
static inline int sys_get_crit_temp(struct thermal_zone_device *tzd,
unsigned long *temp)
{
return _get_trip_temp(QRK_DTS_ID_TP_CRITICAL, temp);
}
static int update_trip_temp(struct soc_sensor_entry *aux_entry,
int trip, unsigned long temp)
{
u32 out;
u32 temp_out;
u32 store_ptps;
int ret;
mutex_lock(&dts_update_mutex);
if (aux_entry->locked) {
ret = -EPERM;
goto failed;
}
ret = iosf_mbi_read(QRK_MBI_UNIT_RMU, QRK_MBI_RMU_READ,
QRK_DTS_REG_OFFSET_PTPS, &store_ptps);
if (ret)
goto failed;
if (temp > QRK_DTS_SAFE_TP_THRES)
temp = QRK_DTS_SAFE_TP_THRES;
temp_out = temp + QRK_DTS_TEMP_BASE;
out = (store_ptps & ~(QRK_DTS_MASK_TP_THRES <<
(trip * QRK_DTS_SHIFT_TP)));
out |= (temp_out & QRK_DTS_MASK_TP_THRES) <<
(trip * QRK_DTS_SHIFT_TP);
ret = iosf_mbi_write(QRK_MBI_UNIT_RMU, QRK_MBI_RMU_WRITE,
QRK_DTS_REG_OFFSET_PTPS, out);
failed:
mutex_unlock(&dts_update_mutex);
return ret;
}
static inline int sys_set_trip_temp(struct thermal_zone_device *tzd, int trip,
unsigned long temp)
{
return update_trip_temp(tzd->devdata, trip, temp);
}
static int sys_get_trip_type(struct thermal_zone_device *thermal,
int trip, enum thermal_trip_type *type)
{
if (trip)
*type = THERMAL_TRIP_HOT;
else
*type = THERMAL_TRIP_CRITICAL;
return 0;
}
static int sys_get_curr_temp(struct thermal_zone_device *tzd,
unsigned long *temp)
{
u32 out;
int ret;
mutex_lock(&dts_update_mutex);
ret = iosf_mbi_read(QRK_MBI_UNIT_RMU, QRK_MBI_RMU_READ,
QRK_DTS_REG_OFFSET_TEMP, &out);
mutex_unlock(&dts_update_mutex);
if (ret)
return ret;
out = (out >> QRK_DTS_OFFSET_TEMP) & QRK_DTS_MASK_TEMP;
*temp = out - QRK_DTS_TEMP_BASE;
return 0;
}
static int sys_get_mode(struct thermal_zone_device *tzd,
enum thermal_device_mode *mode)
{
struct soc_sensor_entry *aux_entry = tzd->devdata;
*mode = aux_entry->mode;
return 0;
}
static int sys_set_mode(struct thermal_zone_device *tzd,
enum thermal_device_mode mode)
{
int ret;
mutex_lock(&dts_update_mutex);
if (mode == THERMAL_DEVICE_ENABLED)
ret = soc_dts_enable(tzd);
else
ret = soc_dts_disable(tzd);
mutex_unlock(&dts_update_mutex);
return ret;
}
static void free_soc_dts(struct soc_sensor_entry *aux_entry)
{
if (aux_entry) {
if (!aux_entry->locked) {
mutex_lock(&dts_update_mutex);
iosf_mbi_write(QRK_MBI_UNIT_RMU, QRK_MBI_RMU_WRITE,
QRK_DTS_REG_OFFSET_ENABLE,
aux_entry->store_dts_enable);
iosf_mbi_write(QRK_MBI_UNIT_RMU, QRK_MBI_RMU_WRITE,
QRK_DTS_REG_OFFSET_PTPS,
aux_entry->store_ptps);
mutex_unlock(&dts_update_mutex);
}
thermal_zone_device_unregister(aux_entry->tzone);
kfree(aux_entry);
}
}
static struct soc_sensor_entry *alloc_soc_dts(void)
{
struct soc_sensor_entry *aux_entry;
int err;
u32 out;
int wr_mask;
aux_entry = kzalloc(sizeof(*aux_entry), GFP_KERNEL);
if (!aux_entry) {
err = -ENOMEM;
return ERR_PTR(-ENOMEM);
}
err = iosf_mbi_read(QRK_MBI_UNIT_RMU, QRK_MBI_RMU_READ,
QRK_DTS_REG_OFFSET_LOCK,
&out);
if (err)
goto err_ret;
if (out & QRK_DTS_LOCK_BIT) {
aux_entry->locked = true;
wr_mask = QRK_DTS_WR_MASK_CLR;
} else {
aux_entry->locked = false;
wr_mask = QRK_DTS_WR_MASK_SET;
}
if (!aux_entry->locked) {
err = iosf_mbi_read(QRK_MBI_UNIT_RMU, QRK_MBI_RMU_READ,
QRK_DTS_REG_OFFSET_ENABLE,
&aux_entry->store_dts_enable);
if (err)
goto err_ret;
err = iosf_mbi_read(QRK_MBI_UNIT_RMU, QRK_MBI_RMU_READ,
QRK_DTS_REG_OFFSET_PTPS,
&aux_entry->store_ptps);
if (err)
goto err_ret;
}
aux_entry->tzone = thermal_zone_device_register("quark_dts",
QRK_MAX_DTS_TRIPS,
wr_mask,
aux_entry, &tzone_ops, NULL, 0, polling_delay);
if (IS_ERR(aux_entry->tzone)) {
err = PTR_ERR(aux_entry->tzone);
goto err_ret;
}
mutex_lock(&dts_update_mutex);
err = soc_dts_enable(aux_entry->tzone);
mutex_unlock(&dts_update_mutex);
if (err)
goto err_aux_status;
return aux_entry;
err_aux_status:
thermal_zone_device_unregister(aux_entry->tzone);
err_ret:
kfree(aux_entry);
return ERR_PTR(err);
}
static int __init intel_quark_thermal_init(void)
{
int err = 0;
if (!x86_match_cpu(qrk_thermal_ids) || !iosf_mbi_available())
return -ENODEV;
soc_dts = alloc_soc_dts();
if (IS_ERR(soc_dts)) {
err = PTR_ERR(soc_dts);
goto err_free;
}
return 0;
err_free:
free_soc_dts(soc_dts);
return err;
}
static void __exit intel_quark_thermal_exit(void)
{
free_soc_dts(soc_dts);
}
