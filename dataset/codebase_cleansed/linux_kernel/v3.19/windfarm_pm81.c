static void wf_smu_create_sys_fans(void)
{
struct wf_smu_sys_fans_param *param = NULL;
struct wf_pid_param pid_param;
int i;
for (i = 0; i < WF_SMU_SYS_FANS_NUM_CONFIGS; i++)
if (wf_smu_sys_all_params[i].model_id == wf_smu_mach_model) {
param = &wf_smu_sys_all_params[i];
break;
}
if (param == NULL) {
printk(KERN_WARNING "windfarm: System fan config not found "
"for this machine model, max fan speed\n");
goto fail;
}
wf_smu_sys_fans = kmalloc(sizeof(struct wf_smu_sys_fans_state),
GFP_KERNEL);
if (wf_smu_sys_fans == NULL) {
printk(KERN_WARNING "windfarm: Memory allocation error"
" max fan speed\n");
goto fail;
}
wf_smu_sys_fans->ticks = 1;
wf_smu_sys_fans->scale0 = param->scale0;
wf_smu_sys_fans->offset0 = param->offset0;
wf_smu_sys_fans->scale1 = param->scale1;
wf_smu_sys_fans->offset1 = param->offset1;
pid_param.gd = param->gd;
pid_param.gp = param->gp;
pid_param.gr = param->gr;
pid_param.interval = WF_SMU_SYS_FANS_INTERVAL;
pid_param.history_len = WF_SMU_SYS_FANS_HISTORY_SIZE;
pid_param.itarget = param->itarget;
pid_param.min = wf_control_get_min(fan_system);
pid_param.max = wf_control_get_max(fan_system);
if (fan_hd) {
pid_param.min =
max(pid_param.min, wf_control_get_min(fan_hd));
pid_param.max =
min(pid_param.max, wf_control_get_max(fan_hd));
}
wf_pid_init(&wf_smu_sys_fans->pid, &pid_param);
DBG("wf: System Fan control initialized.\n");
DBG(" itarged=%d.%03d, min=%d RPM, max=%d RPM\n",
FIX32TOPRINT(pid_param.itarget), pid_param.min, pid_param.max);
return;
fail:
if (fan_system)
wf_control_set_max(fan_system);
if (fan_hd)
wf_control_set_max(fan_hd);
}
static void wf_smu_sys_fans_tick(struct wf_smu_sys_fans_state *st)
{
s32 new_setpoint, temp, scaled, cputarget;
int rc;
if (--st->ticks != 0) {
if (wf_smu_readjust)
goto readjust;
return;
}
st->ticks = WF_SMU_SYS_FANS_INTERVAL;
rc = wf_sensor_get(sensor_hd_temp, &temp);
if (rc) {
printk(KERN_WARNING "windfarm: HD temp sensor error %d\n",
rc);
wf_smu_failure_state |= FAILURE_SENSOR;
return;
}
DBG("wf_smu: System Fans tick ! HD temp: %d.%03d\n",
FIX32TOPRINT(temp));
if (temp > (st->pid.param.itarget + 0x50000))
wf_smu_failure_state |= FAILURE_OVERTEMP;
new_setpoint = wf_pid_run(&st->pid, temp);
DBG("wf_smu: new_setpoint: %d RPM\n", (int)new_setpoint);
scaled = ((((s64)new_setpoint) * (s64)st->scale0) >> 12) + st->offset0;
DBG("wf_smu: scaled setpoint: %d RPM\n", (int)scaled);
cputarget = wf_smu_cpu_fans ? wf_smu_cpu_fans->pid.target : 0;
cputarget = ((((s64)cputarget) * (s64)st->scale1) >> 12) + st->offset1;
scaled = max(scaled, cputarget);
scaled = max(scaled, st->pid.param.min);
scaled = min(scaled, st->pid.param.max);
DBG("wf_smu: adjusted setpoint: %d RPM\n", (int)scaled);
if (st->sys_setpoint == scaled && new_setpoint == st->hd_setpoint)
return;
st->sys_setpoint = scaled;
st->hd_setpoint = new_setpoint;
readjust:
if (fan_system && wf_smu_failure_state == 0) {
rc = wf_control_set(fan_system, st->sys_setpoint);
if (rc) {
printk(KERN_WARNING "windfarm: Sys fan error %d\n",
rc);
wf_smu_failure_state |= FAILURE_FAN;
}
}
if (fan_hd && wf_smu_failure_state == 0) {
rc = wf_control_set(fan_hd, st->hd_setpoint);
if (rc) {
printk(KERN_WARNING "windfarm: HD fan error %d\n",
rc);
wf_smu_failure_state |= FAILURE_FAN;
}
}
}
static void wf_smu_create_cpu_fans(void)
{
struct wf_cpu_pid_param pid_param;
const struct smu_sdbp_header *hdr;
struct smu_sdbp_cpupiddata *piddata;
struct smu_sdbp_fvt *fvt;
s32 tmax, tdelta, maxpow, powadj;
hdr = smu_get_sdb_partition(SMU_SDB_CPUPIDDATA_ID, NULL);
if (hdr == 0) {
printk(KERN_WARNING "windfarm: CPU PID fan config not found "
"max fan speed\n");
goto fail;
}
piddata = (struct smu_sdbp_cpupiddata *)&hdr[1];
hdr = smu_get_sdb_partition(SMU_SDB_FVT_ID, NULL);
if (hdr) {
fvt = (struct smu_sdbp_fvt *)&hdr[1];
tmax = ((s32)fvt->maxtemp) << 16;
} else
tmax = 0x5e0000;
wf_smu_cpu_fans = kmalloc(sizeof(struct wf_smu_cpu_fans_state),
GFP_KERNEL);
if (wf_smu_cpu_fans == NULL)
goto fail;
wf_smu_cpu_fans->ticks = 1;
wf_smu_cpu_fans->scale = WF_SMU_CPU_FANS_SIBLING_SCALE;
wf_smu_cpu_fans->offset = WF_SMU_CPU_FANS_SIBLING_OFFSET;
pid_param.interval = WF_SMU_CPU_FANS_INTERVAL;
pid_param.history_len = piddata->history_len;
if (pid_param.history_len > WF_CPU_PID_MAX_HISTORY) {
printk(KERN_WARNING "windfarm: History size overflow on "
"CPU control loop (%d)\n", piddata->history_len);
pid_param.history_len = WF_CPU_PID_MAX_HISTORY;
}
pid_param.gd = piddata->gd;
pid_param.gp = piddata->gp;
pid_param.gr = piddata->gr / pid_param.history_len;
tdelta = ((s32)piddata->target_temp_delta) << 16;
maxpow = ((s32)piddata->max_power) << 16;
powadj = ((s32)piddata->power_adj) << 16;
pid_param.tmax = tmax;
pid_param.ttarget = tmax - tdelta;
pid_param.pmaxadj = maxpow - powadj;
pid_param.min = wf_control_get_min(fan_cpu_main);
pid_param.max = wf_control_get_max(fan_cpu_main);
wf_cpu_pid_init(&wf_smu_cpu_fans->pid, &pid_param);
DBG("wf: CPU Fan control initialized.\n");
DBG(" ttarged=%d.%03d, tmax=%d.%03d, min=%d RPM, max=%d RPM\n",
FIX32TOPRINT(pid_param.ttarget), FIX32TOPRINT(pid_param.tmax),
pid_param.min, pid_param.max);
return;
fail:
printk(KERN_WARNING "windfarm: CPU fan config not found\n"
"for this machine model, max fan speed\n");
if (cpufreq_clamp)
wf_control_set_max(cpufreq_clamp);
if (fan_cpu_main)
wf_control_set_max(fan_cpu_main);
}
static void wf_smu_cpu_fans_tick(struct wf_smu_cpu_fans_state *st)
{
s32 new_setpoint, temp, power, systarget;
int rc;
if (--st->ticks != 0) {
if (wf_smu_readjust)
goto readjust;
return;
}
st->ticks = WF_SMU_CPU_FANS_INTERVAL;
rc = wf_sensor_get(sensor_cpu_temp, &temp);
if (rc) {
printk(KERN_WARNING "windfarm: CPU temp sensor error %d\n",
rc);
wf_smu_failure_state |= FAILURE_SENSOR;
return;
}
rc = wf_sensor_get(sensor_cpu_power, &power);
if (rc) {
printk(KERN_WARNING "windfarm: CPU power sensor error %d\n",
rc);
wf_smu_failure_state |= FAILURE_SENSOR;
return;
}
DBG("wf_smu: CPU Fans tick ! CPU temp: %d.%03d, power: %d.%03d\n",
FIX32TOPRINT(temp), FIX32TOPRINT(power));
#ifdef HACKED_OVERTEMP
if (temp > 0x4a0000)
wf_smu_failure_state |= FAILURE_OVERTEMP;
#else
if (temp > st->pid.param.tmax)
wf_smu_failure_state |= FAILURE_OVERTEMP;
#endif
new_setpoint = wf_cpu_pid_run(&st->pid, power, temp);
DBG("wf_smu: new_setpoint: %d RPM\n", (int)new_setpoint);
systarget = wf_smu_sys_fans ? wf_smu_sys_fans->pid.target : 0;
systarget = ((((s64)systarget) * (s64)st->scale) >> 12)
+ st->offset;
new_setpoint = max(new_setpoint, systarget);
new_setpoint = max(new_setpoint, st->pid.param.min);
new_setpoint = min(new_setpoint, st->pid.param.max);
DBG("wf_smu: adjusted setpoint: %d RPM\n", (int)new_setpoint);
if (st->cpu_setpoint == new_setpoint)
return;
st->cpu_setpoint = new_setpoint;
readjust:
if (fan_cpu_main && wf_smu_failure_state == 0) {
rc = wf_control_set(fan_cpu_main, st->cpu_setpoint);
if (rc) {
printk(KERN_WARNING "windfarm: CPU main fan"
" error %d\n", rc);
wf_smu_failure_state |= FAILURE_FAN;
}
}
}
static void wf_smu_tick(void)
{
unsigned int last_failure = wf_smu_failure_state;
unsigned int new_failure;
if (!wf_smu_started) {
DBG("wf: creating control loops !\n");
wf_smu_create_sys_fans();
wf_smu_create_cpu_fans();
wf_smu_started = 1;
}
if (wf_smu_skipping && --wf_smu_skipping)
return;
wf_smu_failure_state = 0;
if (wf_smu_sys_fans)
wf_smu_sys_fans_tick(wf_smu_sys_fans);
if (wf_smu_cpu_fans)
wf_smu_cpu_fans_tick(wf_smu_cpu_fans);
wf_smu_readjust = 0;
new_failure = wf_smu_failure_state & ~last_failure;
if (wf_smu_failure_state && !last_failure) {
if (cpufreq_clamp)
wf_control_set_max(cpufreq_clamp);
if (fan_system)
wf_control_set_max(fan_system);
if (fan_cpu_main)
wf_control_set_max(fan_cpu_main);
if (fan_hd)
wf_control_set_max(fan_hd);
}
if (!wf_smu_failure_state && last_failure) {
if (cpufreq_clamp)
wf_control_set_min(cpufreq_clamp);
wf_smu_readjust = 1;
}
if (new_failure & FAILURE_OVERTEMP) {
wf_set_overtemp();
wf_smu_skipping = 2;
wf_smu_overtemp = true;
}
if (!wf_smu_failure_state && wf_smu_overtemp) {
wf_clear_overtemp();
wf_smu_overtemp = false;
}
}
static void wf_smu_new_control(struct wf_control *ct)
{
if (wf_smu_all_controls_ok)
return;
if (fan_cpu_main == NULL && !strcmp(ct->name, "cpu-fan")) {
if (wf_get_control(ct) == 0)
fan_cpu_main = ct;
}
if (fan_system == NULL && !strcmp(ct->name, "system-fan")) {
if (wf_get_control(ct) == 0)
fan_system = ct;
}
if (cpufreq_clamp == NULL && !strcmp(ct->name, "cpufreq-clamp")) {
if (wf_get_control(ct) == 0)
cpufreq_clamp = ct;
}
if (wf_smu_mach_model > 3) {
if (fan_system && fan_cpu_main && cpufreq_clamp)
wf_smu_all_controls_ok = 1;
return;
}
if (fan_hd == NULL && !strcmp(ct->name, "drive-bay-fan")) {
if (wf_get_control(ct) == 0)
fan_hd = ct;
}
if (fan_system && fan_hd && fan_cpu_main && cpufreq_clamp)
wf_smu_all_controls_ok = 1;
}
static void wf_smu_new_sensor(struct wf_sensor *sr)
{
if (wf_smu_all_sensors_ok)
return;
if (sensor_cpu_power == NULL && !strcmp(sr->name, "cpu-power")) {
if (wf_get_sensor(sr) == 0)
sensor_cpu_power = sr;
}
if (sensor_cpu_temp == NULL && !strcmp(sr->name, "cpu-temp")) {
if (wf_get_sensor(sr) == 0)
sensor_cpu_temp = sr;
}
if (sensor_hd_temp == NULL && !strcmp(sr->name, "hd-temp")) {
if (wf_get_sensor(sr) == 0)
sensor_hd_temp = sr;
}
if (sensor_cpu_power && sensor_cpu_temp && sensor_hd_temp)
wf_smu_all_sensors_ok = 1;
}
static int wf_smu_notify(struct notifier_block *self,
unsigned long event, void *data)
{
switch(event) {
case WF_EVENT_NEW_CONTROL:
DBG("wf: new control %s detected\n",
((struct wf_control *)data)->name);
wf_smu_new_control(data);
wf_smu_readjust = 1;
break;
case WF_EVENT_NEW_SENSOR:
DBG("wf: new sensor %s detected\n",
((struct wf_sensor *)data)->name);
wf_smu_new_sensor(data);
break;
case WF_EVENT_TICK:
if (wf_smu_all_controls_ok && wf_smu_all_sensors_ok)
wf_smu_tick();
}
return 0;
}
static int wf_init_pm(void)
{
const struct smu_sdbp_header *hdr;
hdr = smu_get_sdb_partition(SMU_SDB_SENSORTREE_ID, NULL);
if (hdr != 0) {
struct smu_sdbp_sensortree *st =
(struct smu_sdbp_sensortree *)&hdr[1];
wf_smu_mach_model = st->model_id;
}
printk(KERN_INFO "windfarm: Initializing for iMacG5 model ID %d\n",
wf_smu_mach_model);
return 0;
}
static int wf_smu_probe(struct platform_device *ddev)
{
wf_register_client(&wf_smu_events);
return 0;
}
static int wf_smu_remove(struct platform_device *ddev)
{
wf_unregister_client(&wf_smu_events);
msleep(1000);
if (sensor_cpu_power)
wf_put_sensor(sensor_cpu_power);
if (sensor_cpu_temp)
wf_put_sensor(sensor_cpu_temp);
if (sensor_hd_temp)
wf_put_sensor(sensor_hd_temp);
if (fan_cpu_main)
wf_put_control(fan_cpu_main);
if (fan_hd)
wf_put_control(fan_hd);
if (fan_system)
wf_put_control(fan_system);
if (cpufreq_clamp)
wf_put_control(cpufreq_clamp);
kfree(wf_smu_sys_fans);
kfree(wf_smu_cpu_fans);
return 0;
}
static int __init wf_smu_init(void)
{
int rc = -ENODEV;
if (of_machine_is_compatible("PowerMac8,1") ||
of_machine_is_compatible("PowerMac8,2"))
rc = wf_init_pm();
if (rc == 0) {
#ifdef MODULE
request_module("windfarm_smu_controls");
request_module("windfarm_smu_sensors");
request_module("windfarm_lm75_sensor");
request_module("windfarm_cpufreq_clamp");
#endif
platform_driver_register(&wf_smu_driver);
}
return rc;
}
static void __exit wf_smu_exit(void)
{
platform_driver_unregister(&wf_smu_driver);
}
