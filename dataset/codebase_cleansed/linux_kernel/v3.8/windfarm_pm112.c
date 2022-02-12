static int create_cpu_loop(int cpu)
{
int chip = cpu / 2;
int core = cpu & 1;
struct smu_sdbp_header *hdr;
struct smu_sdbp_cpupiddata *piddata;
struct wf_cpu_pid_param pid;
struct wf_control *main_fan = cpu_fans[0];
s32 tmax;
int fmin;
hdr = smu_sat_get_sdb_partition(chip, 0xC8 + core, NULL);
if (hdr == NULL) {
printk(KERN_WARNING"windfarm: can't get CPU PID fan config\n");
return -EINVAL;
}
piddata = (struct smu_sdbp_cpupiddata *)&hdr[1];
hdr = smu_sat_get_sdb_partition(chip, 0xC4 + core, NULL);
if (hdr) {
struct smu_sdbp_fvt *fvt = (struct smu_sdbp_fvt *)&hdr[1];
tmax = fvt->maxtemp << 16;
} else
tmax = 95 << 16;
if (tmax < cpu_all_tmax)
cpu_all_tmax = tmax;
fmin = (nr_cores > 2) ? 750 : 515;
pid.interval = 1;
pid.history_len = piddata->history_len;
pid.gd = piddata->gd;
pid.gp = piddata->gp;
pid.gr = piddata->gr / piddata->history_len;
pid.pmaxadj = (piddata->max_power << 16) - (piddata->power_adj << 8);
pid.ttarget = tmax - (piddata->target_temp_delta << 16);
pid.tmax = tmax;
pid.min = main_fan->ops->get_min(main_fan);
pid.max = main_fan->ops->get_max(main_fan);
if (pid.min < fmin)
pid.min = fmin;
wf_cpu_pid_init(&cpu_pid[cpu], &pid);
return 0;
}
static void cpu_max_all_fans(void)
{
int i;
if (cpufreq_clamp)
wf_control_set_max(cpufreq_clamp);
for (i = 0; i < NR_CPU_FANS; ++i)
if (cpu_fans[i])
wf_control_set_max(cpu_fans[i]);
}
static int cpu_check_overtemp(s32 temp)
{
int new_state = 0;
s32 t_avg, t_old;
if (temp >= (cpu_all_tmax + LOW_OVER_IMMEDIATE)) {
new_state |= FAILURE_LOW_OVERTEMP;
if ((failure_state & FAILURE_LOW_OVERTEMP) == 0)
printk(KERN_ERR "windfarm: Overtemp due to immediate CPU"
" temperature !\n");
}
if (temp >= (cpu_all_tmax + HIGH_OVER_IMMEDIATE)) {
new_state |= FAILURE_HIGH_OVERTEMP;
if ((failure_state & FAILURE_HIGH_OVERTEMP) == 0)
printk(KERN_ERR "windfarm: Critical overtemp due to"
" immediate CPU temperature !\n");
}
t_old = cpu_thist[cpu_thist_pt];
cpu_thist[cpu_thist_pt] = temp;
cpu_thist_pt = (cpu_thist_pt + 1) % CPU_TEMP_HIST_SIZE;
cpu_thist_total -= t_old;
cpu_thist_total += temp;
t_avg = cpu_thist_total / CPU_TEMP_HIST_SIZE;
DBG_LOTS("t_avg = %d.%03d (out: %d.%03d, in: %d.%03d)\n",
FIX32TOPRINT(t_avg), FIX32TOPRINT(t_old), FIX32TOPRINT(temp));
if (t_avg >= (cpu_all_tmax + LOW_OVER_AVERAGE)) {
new_state |= FAILURE_LOW_OVERTEMP;
if ((failure_state & FAILURE_LOW_OVERTEMP) == 0)
printk(KERN_ERR "windfarm: Overtemp due to average CPU"
" temperature !\n");
}
if (t_avg >= (cpu_all_tmax + HIGH_OVER_AVERAGE)) {
new_state |= FAILURE_HIGH_OVERTEMP;
if ((failure_state & FAILURE_HIGH_OVERTEMP) == 0)
printk(KERN_ERR "windfarm: Critical overtemp due to"
" average CPU temperature !\n");
}
if (new_state) {
if (new_state & FAILURE_HIGH_OVERTEMP)
machine_power_off();
if ((failure_state & new_state) != new_state)
cpu_max_all_fans();
failure_state |= new_state;
} else if ((failure_state & FAILURE_LOW_OVERTEMP) &&
(temp < (cpu_all_tmax + LOW_OVER_CLEAR))) {
printk(KERN_ERR "windfarm: Overtemp condition cleared !\n");
failure_state &= ~FAILURE_LOW_OVERTEMP;
}
return failure_state & (FAILURE_LOW_OVERTEMP | FAILURE_HIGH_OVERTEMP);
}
static void cpu_fans_tick(void)
{
int err, cpu;
s32 greatest_delta = 0;
s32 temp, power, t_max = 0;
int i, t, target = 0;
struct wf_sensor *sr;
struct wf_control *ct;
struct wf_cpu_pid_state *sp;
DBG_LOTS(KERN_DEBUG);
for (cpu = 0; cpu < nr_cores; ++cpu) {
sr = sens_cpu_temp[cpu];
err = sr->ops->get_value(sr, &temp);
if (err) {
DBG("\n");
printk(KERN_WARNING "windfarm: CPU %d temperature "
"sensor error %d\n", cpu, err);
failure_state |= FAILURE_SENSOR;
cpu_max_all_fans();
return;
}
t_max = max(t_max, temp);
sr = sens_cpu_power[cpu];
err = sr->ops->get_value(sr, &power);
if (err) {
DBG("\n");
printk(KERN_WARNING "windfarm: CPU %d power "
"sensor error %d\n", cpu, err);
failure_state |= FAILURE_SENSOR;
cpu_max_all_fans();
return;
}
sp = &cpu_pid[cpu];
t = wf_cpu_pid_run(sp, power, temp);
if (cpu == 0 || sp->last_delta > greatest_delta) {
greatest_delta = sp->last_delta;
target = t;
}
DBG_LOTS("[%d] P=%d.%.3d T=%d.%.3d ",
cpu, FIX32TOPRINT(power), FIX32TOPRINT(temp));
}
DBG_LOTS("fans = %d, t_max = %d.%03d\n", target, FIX32TOPRINT(t_max));
if (target < (cpu_last_target - 20))
target = cpu_last_target - 20;
cpu_last_target = target;
for (cpu = 0; cpu < nr_cores; ++cpu)
cpu_pid[cpu].target = target;
if (cpu_check_overtemp(t_max))
return;
for (i = 0; i < NR_CPU_FANS; ++i) {
ct = cpu_fans[i];
if (ct == NULL)
continue;
err = ct->ops->set_value(ct, target * cpu_fan_scale[i] / 100);
if (err) {
printk(KERN_WARNING "windfarm: fan %s reports "
"error %d\n", ct->name, err);
failure_state |= FAILURE_FAN;
break;
}
}
}
static void backside_fan_tick(void)
{
s32 temp;
int speed;
int err;
if (!backside_fan || !u4_temp)
return;
if (!backside_tick) {
printk(KERN_INFO "windfarm: Backside control loop started.\n");
backside_param.min = backside_fan->ops->get_min(backside_fan);
backside_param.max = backside_fan->ops->get_max(backside_fan);
wf_pid_init(&backside_pid, &backside_param);
backside_tick = 1;
}
if (--backside_tick > 0)
return;
backside_tick = backside_pid.param.interval;
err = u4_temp->ops->get_value(u4_temp, &temp);
if (err) {
printk(KERN_WARNING "windfarm: U4 temp sensor error %d\n",
err);
failure_state |= FAILURE_SENSOR;
wf_control_set_max(backside_fan);
return;
}
speed = wf_pid_run(&backside_pid, temp);
DBG_LOTS("backside PID temp=%d.%.3d speed=%d\n",
FIX32TOPRINT(temp), speed);
err = backside_fan->ops->set_value(backside_fan, speed);
if (err) {
printk(KERN_WARNING "windfarm: backside fan error %d\n", err);
failure_state |= FAILURE_FAN;
}
}
static void drive_bay_fan_tick(void)
{
s32 temp;
int speed;
int err;
if (!drive_bay_fan || !hd_temp)
return;
if (!drive_bay_tick) {
printk(KERN_INFO "windfarm: Drive bay control loop started.\n");
drive_bay_prm.min = drive_bay_fan->ops->get_min(drive_bay_fan);
drive_bay_prm.max = drive_bay_fan->ops->get_max(drive_bay_fan);
wf_pid_init(&drive_bay_pid, &drive_bay_prm);
drive_bay_tick = 1;
}
if (--drive_bay_tick > 0)
return;
drive_bay_tick = drive_bay_pid.param.interval;
err = hd_temp->ops->get_value(hd_temp, &temp);
if (err) {
printk(KERN_WARNING "windfarm: drive bay temp sensor "
"error %d\n", err);
failure_state |= FAILURE_SENSOR;
wf_control_set_max(drive_bay_fan);
return;
}
speed = wf_pid_run(&drive_bay_pid, temp);
DBG_LOTS("drive_bay PID temp=%d.%.3d speed=%d\n",
FIX32TOPRINT(temp), speed);
err = drive_bay_fan->ops->set_value(drive_bay_fan, speed);
if (err) {
printk(KERN_WARNING "windfarm: drive bay fan error %d\n", err);
failure_state |= FAILURE_FAN;
}
}
static void slots_fan_tick(void)
{
s32 power;
int speed;
int err;
if (!slots_fan || !slots_power)
return;
if (!slots_started) {
printk(KERN_INFO "windfarm: Slots control loop started.\n");
wf_pid_init(&slots_pid, &slots_param);
slots_started = 1;
}
err = slots_power->ops->get_value(slots_power, &power);
if (err) {
printk(KERN_WARNING "windfarm: slots power sensor error %d\n",
err);
failure_state |= FAILURE_SENSOR;
wf_control_set_max(slots_fan);
return;
}
speed = wf_pid_run(&slots_pid, power);
DBG_LOTS("slots PID power=%d.%.3d speed=%d\n",
FIX32TOPRINT(power), speed);
err = slots_fan->ops->set_value(slots_fan, speed);
if (err) {
printk(KERN_WARNING "windfarm: slots fan error %d\n", err);
failure_state |= FAILURE_FAN;
}
}
static void set_fail_state(void)
{
int i;
if (cpufreq_clamp)
wf_control_set_max(cpufreq_clamp);
for (i = 0; i < NR_CPU_FANS; ++i)
if (cpu_fans[i])
wf_control_set_max(cpu_fans[i]);
if (backside_fan)
wf_control_set_max(backside_fan);
if (slots_fan)
wf_control_set_max(slots_fan);
if (drive_bay_fan)
wf_control_set_max(drive_bay_fan);
}
static void pm112_tick(void)
{
int i, last_failure;
if (!started) {
started = 1;
printk(KERN_INFO "windfarm: CPUs control loops started.\n");
for (i = 0; i < nr_cores; ++i) {
if (create_cpu_loop(i) < 0) {
failure_state = FAILURE_PERM;
set_fail_state();
break;
}
}
DBG_LOTS("cpu_all_tmax=%d.%03d\n", FIX32TOPRINT(cpu_all_tmax));
#ifdef HACKED_OVERTEMP
cpu_all_tmax = 60 << 16;
#endif
}
if (failure_state & FAILURE_PERM)
return;
last_failure = failure_state;
failure_state &= FAILURE_LOW_OVERTEMP;
cpu_fans_tick();
backside_fan_tick();
slots_fan_tick();
drive_bay_fan_tick();
DBG_LOTS("last_failure: 0x%x, failure_state: %x\n",
last_failure, failure_state);
if (failure_state && last_failure == 0 && cpufreq_clamp)
wf_control_set_max(cpufreq_clamp);
if (failure_state == 0 && last_failure && cpufreq_clamp)
wf_control_set_min(cpufreq_clamp);
}
static void pm112_new_control(struct wf_control *ct)
{
int i, max_exhaust;
if (cpufreq_clamp == NULL && !strcmp(ct->name, "cpufreq-clamp")) {
if (wf_get_control(ct) == 0)
cpufreq_clamp = ct;
}
for (i = 0; i < NR_CPU_FANS; ++i) {
if (!strcmp(ct->name, cpu_fan_names[i])) {
if (cpu_fans[i] == NULL && wf_get_control(ct) == 0)
cpu_fans[i] = ct;
break;
}
}
if (i >= NR_CPU_FANS) {
if (!strcmp(ct->name, "backside-fan")) {
if (backside_fan == NULL && wf_get_control(ct) == 0)
backside_fan = ct;
} else if (!strcmp(ct->name, "slots-fan")) {
if (slots_fan == NULL && wf_get_control(ct) == 0)
slots_fan = ct;
} else if (!strcmp(ct->name, "drive-bay-fan")) {
if (drive_bay_fan == NULL && wf_get_control(ct) == 0)
drive_bay_fan = ct;
}
return;
}
for (i = 0; i < CPU_FANS_REQD; ++i)
if (cpu_fans[i] == NULL)
return;
max_exhaust = cpu_fans[0]->ops->get_max(cpu_fans[0]);
for (i = FIRST_PUMP; i <= LAST_PUMP; ++i)
if ((ct = cpu_fans[i]) != NULL)
cpu_fan_scale[i] =
ct->ops->get_max(ct) * 100 / max_exhaust;
have_all_controls = 1;
}
static void pm112_new_sensor(struct wf_sensor *sr)
{
unsigned int i;
if (!strncmp(sr->name, "cpu-temp-", 9)) {
i = sr->name[9] - '0';
if (sr->name[10] == 0 && i < NR_CORES &&
sens_cpu_temp[i] == NULL && wf_get_sensor(sr) == 0)
sens_cpu_temp[i] = sr;
} else if (!strncmp(sr->name, "cpu-power-", 10)) {
i = sr->name[10] - '0';
if (sr->name[11] == 0 && i < NR_CORES &&
sens_cpu_power[i] == NULL && wf_get_sensor(sr) == 0)
sens_cpu_power[i] = sr;
} else if (!strcmp(sr->name, "hd-temp")) {
if (hd_temp == NULL && wf_get_sensor(sr) == 0)
hd_temp = sr;
} else if (!strcmp(sr->name, "slots-power")) {
if (slots_power == NULL && wf_get_sensor(sr) == 0)
slots_power = sr;
} else if (!strcmp(sr->name, "backside-temp")) {
if (u4_temp == NULL && wf_get_sensor(sr) == 0)
u4_temp = sr;
} else
return;
for (i = 0; i < nr_cores; ++i)
if (sens_cpu_temp[i] == NULL || sens_cpu_power[i] == NULL)
return;
have_all_sensors = 1;
}
static int pm112_wf_notify(struct notifier_block *self,
unsigned long event, void *data)
{
switch (event) {
case WF_EVENT_NEW_SENSOR:
pm112_new_sensor(data);
break;
case WF_EVENT_NEW_CONTROL:
pm112_new_control(data);
break;
case WF_EVENT_TICK:
if (have_all_controls && have_all_sensors)
pm112_tick();
}
return 0;
}
static int wf_pm112_probe(struct platform_device *dev)
{
wf_register_client(&pm112_events);
return 0;
}
static int wf_pm112_remove(struct platform_device *dev)
{
wf_unregister_client(&pm112_events);
return 0;
}
static int __init wf_pm112_init(void)
{
struct device_node *cpu;
if (!of_machine_is_compatible("PowerMac11,2"))
return -ENODEV;
nr_cores = 0;
for (cpu = NULL; (cpu = of_find_node_by_type(cpu, "cpu")) != NULL; )
++nr_cores;
printk(KERN_INFO "windfarm: initializing for dual-core desktop G5\n");
#ifdef MODULE
request_module("windfarm_smu_controls");
request_module("windfarm_smu_sensors");
request_module("windfarm_smu_sat");
request_module("windfarm_lm75_sensor");
request_module("windfarm_max6690_sensor");
request_module("windfarm_cpufreq_clamp");
#endif
platform_driver_register(&wf_pm112_driver);
return 0;
}
static void __exit wf_pm112_exit(void)
{
platform_driver_unregister(&wf_pm112_driver);
}
