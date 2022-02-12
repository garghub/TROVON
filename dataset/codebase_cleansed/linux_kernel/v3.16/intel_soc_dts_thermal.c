static int get_tj_max(u32 *tj_max)
{
u32 eax, edx;
u32 val;
int err;
err = rdmsr_safe(MSR_IA32_TEMPERATURE_TARGET, &eax, &edx);
if (err)
goto err_ret;
else {
val = (eax >> 16) & 0xff;
if (val)
*tj_max = val * 1000;
else {
err = -EINVAL;
goto err_ret;
}
}
return 0;
err_ret:
*tj_max = 0;
return err;
}
static int sys_get_trip_temp(struct thermal_zone_device *tzd,
int trip, unsigned long *temp)
{
int status;
u32 out;
struct soc_sensor_entry *aux_entry;
aux_entry = tzd->devdata;
if (!trip) {
*temp = aux_entry->tj_max - crit_offset;
return 0;
}
mutex_lock(&aux_update_mutex);
status = iosf_mbi_read(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_READ,
SOC_DTS_OFFSET_PTPS, &out);
mutex_unlock(&aux_update_mutex);
if (status)
return status;
out = (out >> (trip * 8)) & SOC_DTS_TJMAX_ENCODING;
if (!out)
*temp = 0;
else
*temp = aux_entry->tj_max - out * 1000;
return 0;
}
static int update_trip_temp(struct soc_sensor_entry *aux_entry,
int thres_index, unsigned long temp)
{
int status;
u32 temp_out;
u32 out;
u32 store_ptps;
u32 store_ptmc;
u32 store_te_out;
u32 te_out;
u32 int_enable_bit = SOC_DTS_TE_APICA_ENABLE |
SOC_DTS_TE_MSI_ENABLE;
temp_out = (aux_entry->tj_max - temp) / 1000;
status = iosf_mbi_read(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_READ,
SOC_DTS_OFFSET_PTPS, &store_ptps);
if (status)
return status;
out = (store_ptps & ~(0xFF << (thres_index * 8)));
out |= (temp_out & 0xFF) << (thres_index * 8);
status = iosf_mbi_write(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_WRITE,
SOC_DTS_OFFSET_PTPS, out);
if (status)
return status;
pr_debug("update_trip_temp PTPS = %x\n", out);
status = iosf_mbi_read(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_READ,
SOC_DTS_OFFSET_PTMC, &out);
if (status)
goto err_restore_ptps;
store_ptmc = out;
status = iosf_mbi_read(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_READ,
SOC_DTS_TE_AUX0 + thres_index,
&te_out);
if (status)
goto err_restore_ptmc;
store_te_out = te_out;
out |= (SOC_DTS_CPU_MODULE0_ENABLE_BIT |
SOC_DTS_CPU_MODULE1_ENABLE_BIT);
if (temp) {
if (thres_index)
out |= SOC_DTS_AUX1_ENABLE_BIT;
else
out |= SOC_DTS_AUX0_ENABLE_BIT;
te_out |= int_enable_bit;
} else {
if (thres_index)
out &= ~SOC_DTS_AUX1_ENABLE_BIT;
else
out &= ~SOC_DTS_AUX0_ENABLE_BIT;
te_out &= ~int_enable_bit;
}
status = iosf_mbi_write(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_WRITE,
SOC_DTS_OFFSET_PTMC, out);
if (status)
goto err_restore_te_out;
status = iosf_mbi_write(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_WRITE,
SOC_DTS_TE_AUX0 + thres_index,
te_out);
if (status)
goto err_restore_te_out;
return 0;
err_restore_te_out:
iosf_mbi_write(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_WRITE,
SOC_DTS_OFFSET_PTMC, store_te_out);
err_restore_ptmc:
iosf_mbi_write(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_WRITE,
SOC_DTS_OFFSET_PTMC, store_ptmc);
err_restore_ptps:
iosf_mbi_write(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_WRITE,
SOC_DTS_OFFSET_PTPS, store_ptps);
return status;
}
static int sys_set_trip_temp(struct thermal_zone_device *tzd, int trip,
unsigned long temp)
{
struct soc_sensor_entry *aux_entry = tzd->devdata;
int status;
if (temp > (aux_entry->tj_max - crit_offset))
return -EINVAL;
mutex_lock(&aux_update_mutex);
status = update_trip_temp(tzd->devdata, trip, temp);
mutex_unlock(&aux_update_mutex);
return status;
}
static int sys_get_trip_type(struct thermal_zone_device *thermal,
int trip, enum thermal_trip_type *type)
{
if (trip)
*type = THERMAL_TRIP_PASSIVE;
else
*type = THERMAL_TRIP_CRITICAL;
return 0;
}
static int sys_get_curr_temp(struct thermal_zone_device *tzd,
unsigned long *temp)
{
int status;
u32 out;
struct soc_sensor_entry *aux_entry;
aux_entry = tzd->devdata;
status = iosf_mbi_read(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_READ,
SOC_DTS_OFFSET_TEMP, &out);
if (status)
return status;
out = (out & aux_entry->temp_mask) >> aux_entry->temp_shift;
out -= SOC_DTS_TJMAX_ENCODING;
*temp = aux_entry->tj_max - out * 1000;
return 0;
}
static void free_soc_dts(struct soc_sensor_entry *aux_entry)
{
if (aux_entry) {
iosf_mbi_write(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_WRITE,
SOC_DTS_OFFSET_ENABLE, aux_entry->store_status);
thermal_zone_device_unregister(aux_entry->tzone);
kfree(aux_entry);
}
}
static int soc_dts_enable(int id)
{
u32 out;
int ret;
ret = iosf_mbi_read(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_READ,
SOC_DTS_OFFSET_ENABLE, &out);
if (ret)
return ret;
if (!(out & BIT(id))) {
out |= BIT(id);
ret = iosf_mbi_write(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_WRITE,
SOC_DTS_OFFSET_ENABLE, out);
if (ret)
return ret;
}
return ret;
}
static struct soc_sensor_entry *alloc_soc_dts(int id, u32 tj_max)
{
struct soc_sensor_entry *aux_entry;
char name[10];
int err;
aux_entry = kzalloc(sizeof(*aux_entry), GFP_KERNEL);
if (!aux_entry) {
err = -ENOMEM;
return ERR_PTR(-ENOMEM);
}
err = iosf_mbi_read(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_READ,
SOC_DTS_OFFSET_ENABLE,
&aux_entry->store_status);
if (err)
goto err_ret;
aux_entry->id = id;
aux_entry->tj_max = tj_max;
aux_entry->temp_mask = 0x00FF << (id * 8);
aux_entry->temp_shift = id * 8;
snprintf(name, sizeof(name), "soc_dts%d", id);
aux_entry->tzone = thermal_zone_device_register(name,
SOC_MAX_DTS_TRIPS,
0x02,
aux_entry, &tzone_ops, NULL, 0, 0);
if (IS_ERR(aux_entry->tzone)) {
err = PTR_ERR(aux_entry->tzone);
goto err_ret;
}
err = soc_dts_enable(id);
if (err)
goto err_aux_status;
return aux_entry;
err_aux_status:
thermal_zone_device_unregister(aux_entry->tzone);
err_ret:
kfree(aux_entry);
return ERR_PTR(err);
}
static void proc_thermal_interrupt(void)
{
u32 sticky_out;
int status;
u32 ptmc_out;
status = iosf_mbi_read(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_READ,
SOC_DTS_OFFSET_PTMC, &ptmc_out);
ptmc_out |= SOC_DTS_PTMC_APIC_DEASSERT_BIT;
status = iosf_mbi_write(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_WRITE,
SOC_DTS_OFFSET_PTMC, ptmc_out);
status = iosf_mbi_read(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_READ,
SOC_DTS_OFFSET_PTTSS, &sticky_out);
pr_debug("status %d PTTSS %x\n", status, sticky_out);
if (sticky_out & SOC_DTS_TRIP_MASK) {
int i;
status = iosf_mbi_write(BT_MBI_UNIT_PMC, BT_MBI_BUNIT_WRITE,
SOC_DTS_OFFSET_PTTSS, sticky_out);
for (i = 0; i < SOC_MAX_DTS_SENSORS; ++i) {
pr_debug("TZD update for zone %d\n", i);
thermal_zone_device_update(soc_dts[i]->tzone);
}
}
}
static irqreturn_t soc_irq_thread_fn(int irq, void *dev_data)
{
unsigned long flags;
spin_lock_irqsave(&intr_notify_lock, flags);
proc_thermal_interrupt();
spin_unlock_irqrestore(&intr_notify_lock, flags);
pr_debug("proc_thermal_interrupt\n");
return IRQ_HANDLED;
}
static int __init intel_soc_thermal_init(void)
{
u32 tj_max;
int err = 0;
int i;
const struct x86_cpu_id *match_cpu;
match_cpu = x86_match_cpu(soc_thermal_ids);
if (!match_cpu)
return -ENODEV;
if (get_tj_max(&tj_max))
return -EINVAL;
for (i = 0; i < SOC_MAX_DTS_SENSORS; ++i) {
soc_dts[i] = alloc_soc_dts(i, tj_max);
if (IS_ERR(soc_dts[i])) {
err = PTR_ERR(soc_dts[i]);
goto err_free;
}
}
spin_lock_init(&intr_notify_lock);
soc_dts_thres_irq = (int)match_cpu->driver_data;
err = request_threaded_irq(soc_dts_thres_irq, NULL,
soc_irq_thread_fn,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"soc_dts", soc_dts);
if (err) {
pr_err("request_threaded_irq ret %d\n", err);
goto err_free;
}
for (i = 0; i < SOC_MAX_DTS_SENSORS; ++i) {
err = update_trip_temp(soc_dts[i], 0, tj_max - crit_offset);
if (err)
goto err_trip_temp;
}
return 0;
err_trip_temp:
i = SOC_MAX_DTS_SENSORS;
free_irq(soc_dts_thres_irq, soc_dts);
err_free:
while (--i >= 0)
free_soc_dts(soc_dts[i]);
return err;
}
static void __exit intel_soc_thermal_exit(void)
{
int i;
for (i = 0; i < SOC_MAX_DTS_SENSORS; ++i)
update_trip_temp(soc_dts[i], 0, 0);
free_irq(soc_dts_thres_irq, soc_dts);
for (i = 0; i < SOC_MAX_DTS_SENSORS; ++i)
free_soc_dts(soc_dts[i]);
}
