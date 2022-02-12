static s32 pm121_correct(s32 new_setpoint,
unsigned int control_id,
s32 min)
{
s32 new_min;
struct pm121_correction *correction;
correction = &corrections[control_id][pm121_mach_model - 2];
new_min = (average_power * correction->slope) >> 16;
new_min += correction->offset;
new_min = (new_min >> 16) + min;
return max3(new_setpoint, new_min, 0);
}
static s32 pm121_connect(unsigned int control_id, s32 setpoint)
{
s32 new_min, value, new_setpoint;
if (pm121_connection->control_id == control_id) {
controls[control_id]->ops->get_value(controls[control_id],
&value);
new_min = value * pm121_connection->correction.slope;
new_min += pm121_connection->correction.offset;
if (new_min > 0) {
new_setpoint = max(setpoint, (new_min >> 16));
if (new_setpoint != setpoint) {
pr_debug("pm121: %s depending on %s, "
"corrected from %d to %d RPM\n",
controls[control_id]->name,
controls[pm121_connection->ref_id]->name,
(int) setpoint, (int) new_setpoint);
}
} else
new_setpoint = setpoint;
}
else
new_setpoint = setpoint;
return new_setpoint;
}
static void pm121_create_sys_fans(int loop_id)
{
struct pm121_sys_param *param = NULL;
struct wf_pid_param pid_param;
struct wf_control *control = NULL;
int i;
for (i = 0; i < PM121_NUM_CONFIGS; i++) {
if (pm121_sys_all_params[loop_id][i].model_id == pm121_mach_model) {
param = &(pm121_sys_all_params[loop_id][i]);
break;
}
}
if (param == NULL) {
printk(KERN_WARNING "pm121: %s fan config not found "
" for this machine model\n",
loop_names[loop_id]);
goto fail;
}
control = controls[param->control_id];
pm121_sys_state[loop_id] = kmalloc(sizeof(struct pm121_sys_state),
GFP_KERNEL);
if (pm121_sys_state[loop_id] == NULL) {
printk(KERN_WARNING "pm121: Memory allocation error\n");
goto fail;
}
pm121_sys_state[loop_id]->ticks = 1;
pid_param.gd = PM121_SYS_GD;
pid_param.gp = param->gp;
pid_param.gr = PM121_SYS_GR;
pid_param.interval = PM121_SYS_INTERVAL;
pid_param.history_len = PM121_SYS_HISTORY_SIZE;
pid_param.itarget = param->itarget;
pid_param.min = control->ops->get_min(control);
pid_param.max = control->ops->get_max(control);
wf_pid_init(&pm121_sys_state[loop_id]->pid, &pid_param);
pr_debug("pm121: %s Fan control loop initialized.\n"
" itarged=%d.%03d, min=%d RPM, max=%d RPM\n",
loop_names[loop_id], FIX32TOPRINT(pid_param.itarget),
pid_param.min, pid_param.max);
return;
fail:
printk(KERN_WARNING "pm121: failed to set up %s loop "
"setting \"%s\" to max speed.\n",
loop_names[loop_id], control->name);
if (control)
wf_control_set_max(control);
}
static void pm121_sys_fans_tick(int loop_id)
{
struct pm121_sys_param *param;
struct pm121_sys_state *st;
struct wf_sensor *sensor;
struct wf_control *control;
s32 temp, new_setpoint;
int rc;
param = &(pm121_sys_all_params[loop_id][pm121_mach_model-2]);
st = pm121_sys_state[loop_id];
sensor = *(param->sensor);
control = controls[param->control_id];
if (--st->ticks != 0) {
if (pm121_readjust)
goto readjust;
return;
}
st->ticks = PM121_SYS_INTERVAL;
rc = sensor->ops->get_value(sensor, &temp);
if (rc) {
printk(KERN_WARNING "windfarm: %s sensor error %d\n",
sensor->name, rc);
pm121_failure_state |= FAILURE_SENSOR;
return;
}
pr_debug("pm121: %s Fan tick ! %s: %d.%03d\n",
loop_names[loop_id], sensor->name,
FIX32TOPRINT(temp));
new_setpoint = wf_pid_run(&st->pid, temp);
new_setpoint = pm121_correct(new_setpoint,
param->control_id,
st->pid.param.min);
new_setpoint = pm121_connect(param->control_id, new_setpoint);
if (new_setpoint == st->setpoint)
return;
st->setpoint = new_setpoint;
pr_debug("pm121: %s corrected setpoint: %d RPM\n",
control->name, (int)new_setpoint);
readjust:
if (control && pm121_failure_state == 0) {
rc = control->ops->set_value(control, st->setpoint);
if (rc) {
printk(KERN_WARNING "windfarm: %s fan error %d\n",
control->name, rc);
pm121_failure_state |= FAILURE_FAN;
}
}
}
static void pm121_create_cpu_fans(void)
{
struct wf_cpu_pid_param pid_param;
const struct smu_sdbp_header *hdr;
struct smu_sdbp_cpupiddata *piddata;
struct smu_sdbp_fvt *fvt;
struct wf_control *fan_cpu;
s32 tmax, tdelta, maxpow, powadj;
fan_cpu = controls[FAN_CPU];
hdr = smu_get_sdb_partition(SMU_SDB_CPUPIDDATA_ID, NULL);
if (hdr == 0) {
printk(KERN_WARNING "pm121: CPU PID fan config not found.\n");
goto fail;
}
piddata = (struct smu_sdbp_cpupiddata *)&hdr[1];
hdr = smu_get_sdb_partition(SMU_SDB_FVT_ID, NULL);
if (hdr) {
fvt = (struct smu_sdbp_fvt *)&hdr[1];
tmax = ((s32)fvt->maxtemp) << 16;
} else
tmax = 0x5e0000;
pm121_cpu_state = kmalloc(sizeof(struct pm121_cpu_state),
GFP_KERNEL);
if (pm121_cpu_state == NULL)
goto fail;
pm121_cpu_state->ticks = 1;
pid_param.interval = PM121_CPU_INTERVAL;
pid_param.history_len = piddata->history_len;
if (pid_param.history_len > WF_CPU_PID_MAX_HISTORY) {
printk(KERN_WARNING "pm121: History size overflow on "
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
pid_param.min = fan_cpu->ops->get_min(fan_cpu);
pid_param.max = fan_cpu->ops->get_max(fan_cpu);
wf_cpu_pid_init(&pm121_cpu_state->pid, &pid_param);
pr_debug("pm121: CPU Fan control initialized.\n");
pr_debug(" ttarged=%d.%03d, tmax=%d.%03d, min=%d RPM, max=%d RPM,\n",
FIX32TOPRINT(pid_param.ttarget), FIX32TOPRINT(pid_param.tmax),
pid_param.min, pid_param.max);
return;
fail:
printk(KERN_WARNING "pm121: CPU fan config not found, max fan speed\n");
if (controls[CPUFREQ])
wf_control_set_max(controls[CPUFREQ]);
if (fan_cpu)
wf_control_set_max(fan_cpu);
}
static void pm121_cpu_fans_tick(struct pm121_cpu_state *st)
{
s32 new_setpoint, temp, power;
struct wf_control *fan_cpu = NULL;
int rc;
if (--st->ticks != 0) {
if (pm121_readjust)
goto readjust;
return;
}
st->ticks = PM121_CPU_INTERVAL;
fan_cpu = controls[FAN_CPU];
rc = sensor_cpu_temp->ops->get_value(sensor_cpu_temp, &temp);
if (rc) {
printk(KERN_WARNING "pm121: CPU temp sensor error %d\n",
rc);
pm121_failure_state |= FAILURE_SENSOR;
return;
}
rc = sensor_cpu_power->ops->get_value(sensor_cpu_power, &power);
if (rc) {
printk(KERN_WARNING "pm121: CPU power sensor error %d\n",
rc);
pm121_failure_state |= FAILURE_SENSOR;
return;
}
pr_debug("pm121: CPU Fans tick ! CPU temp: %d.%03dÃ&#8218;Â°C, power: %d.%03d\n",
FIX32TOPRINT(temp), FIX32TOPRINT(power));
if (temp > st->pid.param.tmax)
pm121_failure_state |= FAILURE_OVERTEMP;
new_setpoint = wf_cpu_pid_run(&st->pid, power, temp);
new_setpoint = pm121_correct(new_setpoint,
FAN_CPU,
st->pid.param.min);
new_setpoint = pm121_connect(FAN_CPU, new_setpoint);
if (st->setpoint == new_setpoint)
return;
st->setpoint = new_setpoint;
pr_debug("pm121: CPU corrected setpoint: %d RPM\n", (int)new_setpoint);
readjust:
if (fan_cpu && pm121_failure_state == 0) {
rc = fan_cpu->ops->set_value(fan_cpu, st->setpoint);
if (rc) {
printk(KERN_WARNING "pm121: %s fan error %d\n",
fan_cpu->name, rc);
pm121_failure_state |= FAILURE_FAN;
}
}
}
static void pm121_tick(void)
{
unsigned int last_failure = pm121_failure_state;
unsigned int new_failure;
s32 total_power;
int i;
if (!pm121_started) {
pr_debug("pm121: creating control loops !\n");
for (i = 0; i < N_LOOPS; i++)
pm121_create_sys_fans(i);
pm121_create_cpu_fans();
pm121_started = 1;
}
if (pm121_skipping && --pm121_skipping)
return;
total_power = 0;
for (i = 0; i < pm121_cpu_state->pid.param.history_len; i++)
total_power += pm121_cpu_state->pid.powers[i];
average_power = total_power / pm121_cpu_state->pid.param.history_len;
pm121_failure_state = 0;
for (i = 0 ; i < N_LOOPS; i++) {
if (pm121_sys_state[i])
pm121_sys_fans_tick(i);
}
if (pm121_cpu_state)
pm121_cpu_fans_tick(pm121_cpu_state);
pm121_readjust = 0;
new_failure = pm121_failure_state & ~last_failure;
if (pm121_failure_state && !last_failure) {
for (i = 0; i < N_CONTROLS; i++) {
if (controls[i])
wf_control_set_max(controls[i]);
}
}
if (!pm121_failure_state && last_failure) {
if (controls[CPUFREQ])
wf_control_set_min(controls[CPUFREQ]);
pm121_readjust = 1;
}
if (new_failure & FAILURE_OVERTEMP) {
wf_set_overtemp();
pm121_skipping = 2;
pm121_overtemp = true;
}
if (!pm121_failure_state && pm121_overtemp) {
wf_clear_overtemp();
pm121_overtemp = false;
}
}
static struct wf_control* pm121_register_control(struct wf_control *ct,
const char *match,
unsigned int id)
{
if (controls[id] == NULL && !strcmp(ct->name, match)) {
if (wf_get_control(ct) == 0)
controls[id] = ct;
}
return controls[id];
}
static void pm121_new_control(struct wf_control *ct)
{
int all = 1;
if (pm121_all_controls_ok)
return;
all = pm121_register_control(ct, "optical-drive-fan", FAN_OD) && all;
all = pm121_register_control(ct, "hard-drive-fan", FAN_HD) && all;
all = pm121_register_control(ct, "cpu-fan", FAN_CPU) && all;
all = pm121_register_control(ct, "cpufreq-clamp", CPUFREQ) && all;
if (all)
pm121_all_controls_ok = 1;
}
static struct wf_sensor* pm121_register_sensor(struct wf_sensor *sensor,
const char *match,
struct wf_sensor **var)
{
if (*var == NULL && !strcmp(sensor->name, match)) {
if (wf_get_sensor(sensor) == 0)
*var = sensor;
}
return *var;
}
static void pm121_new_sensor(struct wf_sensor *sr)
{
int all = 1;
if (pm121_all_sensors_ok)
return;
all = pm121_register_sensor(sr, "cpu-temp",
&sensor_cpu_temp) && all;
all = pm121_register_sensor(sr, "cpu-current",
&sensor_cpu_current) && all;
all = pm121_register_sensor(sr, "cpu-voltage",
&sensor_cpu_voltage) && all;
all = pm121_register_sensor(sr, "cpu-power",
&sensor_cpu_power) && all;
all = pm121_register_sensor(sr, "hard-drive-temp",
&sensor_hard_drive_temp) && all;
all = pm121_register_sensor(sr, "optical-drive-temp",
&sensor_optical_drive_temp) && all;
all = pm121_register_sensor(sr, "incoming-air-temp",
&sensor_incoming_air_temp) && all;
all = pm121_register_sensor(sr, "north-bridge-temp",
&sensor_north_bridge_temp) && all;
all = pm121_register_sensor(sr, "gpu-temp",
&sensor_gpu_temp) && all;
if (all)
pm121_all_sensors_ok = 1;
}
static int pm121_notify(struct notifier_block *self,
unsigned long event, void *data)
{
switch (event) {
case WF_EVENT_NEW_CONTROL:
pr_debug("pm121: new control %s detected\n",
((struct wf_control *)data)->name);
pm121_new_control(data);
break;
case WF_EVENT_NEW_SENSOR:
pr_debug("pm121: new sensor %s detected\n",
((struct wf_sensor *)data)->name);
pm121_new_sensor(data);
break;
case WF_EVENT_TICK:
if (pm121_all_controls_ok && pm121_all_sensors_ok)
pm121_tick();
break;
}
return 0;
}
static int pm121_init_pm(void)
{
const struct smu_sdbp_header *hdr;
hdr = smu_get_sdb_partition(SMU_SDB_SENSORTREE_ID, NULL);
if (hdr != 0) {
struct smu_sdbp_sensortree *st =
(struct smu_sdbp_sensortree *)&hdr[1];
pm121_mach_model = st->model_id;
}
pm121_connection = &pm121_connections[pm121_mach_model - 2];
printk(KERN_INFO "pm121: Initializing for iMac G5 iSight model ID %d\n",
pm121_mach_model);
return 0;
}
static int pm121_probe(struct platform_device *ddev)
{
wf_register_client(&pm121_events);
return 0;
}
static int pm121_remove(struct platform_device *ddev)
{
wf_unregister_client(&pm121_events);
return 0;
}
static int __init pm121_init(void)
{
int rc = -ENODEV;
if (of_machine_is_compatible("PowerMac12,1"))
rc = pm121_init_pm();
if (rc == 0) {
request_module("windfarm_smu_controls");
request_module("windfarm_smu_sensors");
request_module("windfarm_smu_sat");
request_module("windfarm_lm75_sensor");
request_module("windfarm_max6690_sensor");
request_module("windfarm_cpufreq_clamp");
platform_driver_register(&pm121_driver);
}
return rc;
}
static void __exit pm121_exit(void)
{
platform_driver_unregister(&pm121_driver);
}
