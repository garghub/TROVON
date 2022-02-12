static void cpu_max_all_fans(void)
{
int i;
if (cpufreq_clamp)
wf_control_set_max(cpufreq_clamp);
for (i = 0; i < nr_chips; i++) {
if (cpu_fans[i][0])
wf_control_set_max(cpu_fans[i][0]);
if (cpu_fans[i][1])
wf_control_set_max(cpu_fans[i][1]);
if (cpu_fans[i][2])
wf_control_set_max(cpu_fans[i][2]);
}
}
static int cpu_check_overtemp(s32 temp)
{
int new_state = 0;
s32 t_avg, t_old;
static bool first = true;
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
if (first) {
int i;
cpu_thist_total = 0;
for (i = 0; i < CPU_TEMP_HIST_SIZE; i++) {
cpu_thist[i] = temp;
cpu_thist_total += temp;
}
first = false;
}
t_old = cpu_thist[cpu_thist_pt];
cpu_thist[cpu_thist_pt] = temp;
cpu_thist_pt = (cpu_thist_pt + 1) % CPU_TEMP_HIST_SIZE;
cpu_thist_total -= t_old;
cpu_thist_total += temp;
t_avg = cpu_thist_total / CPU_TEMP_HIST_SIZE;
DBG_LOTS(" t_avg = %d.%03d (out: %d.%03d, in: %d.%03d)\n",
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
static int read_one_cpu_vals(int cpu, s32 *temp, s32 *power)
{
s32 dtemp, volts, amps;
int rc;
rc = wf_sensor_get(sens_cpu_temp[cpu], &dtemp);
if (rc) {
DBG(" CPU%d: temp reading error !\n", cpu);
return -EIO;
}
DBG_LOTS(" CPU%d: temp = %d.%03d\n", cpu, FIX32TOPRINT((dtemp)));
*temp = dtemp;
rc = wf_sensor_get(sens_cpu_volts[cpu], &volts);
if (rc) {
DBG(" CPU%d, volts reading error !\n", cpu);
return -EIO;
}
DBG_LOTS(" CPU%d: volts = %d.%03d\n", cpu, FIX32TOPRINT((volts)));
rc = wf_sensor_get(sens_cpu_amps[cpu], &amps);
if (rc) {
DBG(" CPU%d, current reading error !\n", cpu);
return -EIO;
}
DBG_LOTS(" CPU%d: amps = %d.%03d\n", cpu, FIX32TOPRINT((amps)));
*power = (((u64)volts) * ((u64)amps)) >> 16;
DBG_LOTS(" CPU%d: power = %d.%03d\n", cpu, FIX32TOPRINT((*power)));
return 0;
}
static void cpu_fans_tick(void)
{
int err, cpu, i;
s32 speed, temp, power, t_max = 0;
DBG_LOTS("* cpu fans_tick_split()\n");
for (cpu = 0; cpu < nr_chips; ++cpu) {
struct wf_cpu_pid_state *sp = &cpu_pid[cpu];
wf_control_get(cpu_fans[cpu][0], &sp->target);
err = read_one_cpu_vals(cpu, &temp, &power);
if (err) {
failure_state |= FAILURE_SENSOR;
cpu_max_all_fans();
return;
}
t_max = max(t_max, temp);
if (cpu_check_overtemp(t_max))
return;
wf_cpu_pid_run(sp, power, temp);
DBG_LOTS(" CPU%d: target = %d RPM\n", cpu, sp->target);
speed = max(sp->target, dimms_output_clamp);
for (i = 0; i < 3; i++) {
err = wf_control_set(cpu_fans[cpu][i], speed);
if (err) {
pr_warning("wf_rm31: Fan %s reports error %d\n",
cpu_fans[cpu][i]->name, err);
failure_state |= FAILURE_FAN;
}
}
}
}
static int cpu_setup_pid(int cpu)
{
struct wf_cpu_pid_param pid;
const struct mpu_data *mpu = cpu_mpu_data[cpu];
s32 tmax, ttarget, ptarget;
int fmin, fmax, hsize;
tmax = mpu->tmax << 16;
ttarget = mpu->ttarget << 16;
ptarget = ((s32)(mpu->pmaxh - mpu->padjmax)) << 16;
DBG("wf_72: CPU%d ttarget = %d.%03d, tmax = %d.%03d\n",
cpu, FIX32TOPRINT(ttarget), FIX32TOPRINT(tmax));
if (tmax < cpu_all_tmax)
cpu_all_tmax = tmax;
fmin = wf_control_get_min(cpu_fans[cpu][0]);
fmax = wf_control_get_max(cpu_fans[cpu][0]);
DBG("wf_72: CPU%d max RPM range = [%d..%d]\n", cpu, fmin, fmax);
hsize = min_t(int, mpu->tguardband, WF_PID_MAX_HISTORY);
DBG("wf_72: CPU%d history size = %d\n", cpu, hsize);
pid.interval = 1;
pid.history_len = hsize;
pid.gd = mpu->pid_gd;
pid.gp = mpu->pid_gp;
pid.gr = mpu->pid_gr;
pid.tmax = tmax;
pid.ttarget = ttarget;
pid.pmaxadj = ptarget;
pid.min = fmin;
pid.max = fmax;
wf_cpu_pid_init(&cpu_pid[cpu], &pid);
cpu_pid[cpu].target = 4000;
return 0;
}
static void backside_fan_tick(void)
{
s32 temp, dtemp;
int speed, dspeed, fan_min;
int err;
if (!backside_fan || !backside_temp || !dimms_temp || !backside_tick)
return;
if (--backside_tick > 0)
return;
backside_tick = backside_pid.param.interval;
DBG_LOTS("* backside fans tick\n");
err = wf_control_get(backside_fan, &speed);
if (!err)
backside_pid.target = speed;
err = wf_sensor_get(backside_temp, &temp);
if (err) {
printk(KERN_WARNING "windfarm: U3 temp sensor error %d\n",
err);
failure_state |= FAILURE_SENSOR;
wf_control_set_max(backside_fan);
return;
}
speed = wf_pid_run(&backside_pid, temp);
DBG_LOTS("backside PID temp=%d.%.3d speed=%d\n",
FIX32TOPRINT(temp), speed);
err = wf_sensor_get(dimms_temp, &dtemp);
if (err) {
printk(KERN_WARNING "windfarm: DIMMs temp sensor error %d\n",
err);
failure_state |= FAILURE_SENSOR;
wf_control_set_max(backside_fan);
return;
}
dspeed = wf_pid_run(&dimms_pid, dtemp);
dimms_output_clamp = dspeed;
fan_min = (dspeed * 100) / 14000;
fan_min = max(fan_min, backside_param.min);
speed = max(speed, fan_min);
err = wf_control_set(backside_fan, speed);
if (err) {
printk(KERN_WARNING "windfarm: backside fan error %d\n", err);
failure_state |= FAILURE_FAN;
}
}
static void backside_setup_pid(void)
{
s32 fmin = wf_control_get_min(backside_fan);
s32 fmax = wf_control_get_max(backside_fan);
struct wf_pid_param param;
param = backside_param;
param.min = max(param.min, fmin);
param.max = min(param.max, fmax);
wf_pid_init(&backside_pid, &param);
param = dimms_param;
wf_pid_init(&dimms_pid, &param);
backside_tick = 1;
pr_info("wf_rm31: Backside control loop started.\n");
}
static void slots_fan_tick(void)
{
s32 temp;
int speed;
int err;
if (!slots_fan || !slots_temp || !slots_tick)
return;
if (--slots_tick > 0)
return;
slots_tick = slots_pid.param.interval;
DBG_LOTS("* slots fans tick\n");
err = wf_sensor_get(slots_temp, &temp);
if (err) {
pr_warning("wf_rm31: slots temp sensor error %d\n", err);
failure_state |= FAILURE_SENSOR;
wf_control_set_max(slots_fan);
return;
}
speed = wf_pid_run(&slots_pid, temp);
DBG_LOTS("slots PID temp=%d.%.3d speed=%d\n",
FIX32TOPRINT(temp), speed);
slots_speed = speed;
err = wf_control_set(slots_fan, speed);
if (err) {
printk(KERN_WARNING "windfarm: slots bay fan error %d\n", err);
failure_state |= FAILURE_FAN;
}
}
static void slots_setup_pid(void)
{
s32 fmin = wf_control_get_min(slots_fan);
s32 fmax = wf_control_get_max(slots_fan);
struct wf_pid_param param = slots_param;
param.min = max(param.min, fmin);
param.max = min(param.max, fmax);
wf_pid_init(&slots_pid, &param);
slots_tick = 1;
pr_info("wf_rm31: Slots control loop started.\n");
}
static void set_fail_state(void)
{
cpu_max_all_fans();
if (backside_fan)
wf_control_set_max(backside_fan);
if (slots_fan)
wf_control_set_max(slots_fan);
}
static void rm31_tick(void)
{
int i, last_failure;
if (!started) {
started = 1;
printk(KERN_INFO "windfarm: CPUs control loops started.\n");
for (i = 0; i < nr_chips; ++i) {
if (cpu_setup_pid(i) < 0) {
failure_state = FAILURE_PERM;
set_fail_state();
break;
}
}
DBG_LOTS("cpu_all_tmax=%d.%03d\n", FIX32TOPRINT(cpu_all_tmax));
backside_setup_pid();
slots_setup_pid();
#ifdef HACKED_OVERTEMP
cpu_all_tmax = 60 << 16;
#endif
}
if (failure_state & FAILURE_PERM)
return;
last_failure = failure_state;
failure_state &= FAILURE_LOW_OVERTEMP;
backside_fan_tick();
slots_fan_tick();
cpu_fans_tick();
DBG_LOTS(" last_failure: 0x%x, failure_state: %x\n",
last_failure, failure_state);
if (failure_state && last_failure == 0 && cpufreq_clamp)
wf_control_set_max(cpufreq_clamp);
if (failure_state == 0 && last_failure && cpufreq_clamp)
wf_control_set_min(cpufreq_clamp);
}
static void rm31_new_control(struct wf_control *ct)
{
bool all_controls;
if (!strcmp(ct->name, "cpu-fan-a-0"))
cpu_fans[0][0] = ct;
else if (!strcmp(ct->name, "cpu-fan-b-0"))
cpu_fans[0][1] = ct;
else if (!strcmp(ct->name, "cpu-fan-c-0"))
cpu_fans[0][2] = ct;
else if (!strcmp(ct->name, "cpu-fan-a-1"))
cpu_fans[1][0] = ct;
else if (!strcmp(ct->name, "cpu-fan-b-1"))
cpu_fans[1][1] = ct;
else if (!strcmp(ct->name, "cpu-fan-c-1"))
cpu_fans[1][2] = ct;
else if (!strcmp(ct->name, "backside-fan"))
backside_fan = ct;
else if (!strcmp(ct->name, "slots-fan"))
slots_fan = ct;
else if (!strcmp(ct->name, "cpufreq-clamp"))
cpufreq_clamp = ct;
all_controls =
cpu_fans[0][0] &&
cpu_fans[0][1] &&
cpu_fans[0][2] &&
backside_fan &&
slots_fan;
if (nr_chips > 1)
all_controls &=
cpu_fans[1][0] &&
cpu_fans[1][1] &&
cpu_fans[1][2];
have_all_controls = all_controls;
}
static void rm31_new_sensor(struct wf_sensor *sr)
{
bool all_sensors;
if (!strcmp(sr->name, "cpu-diode-temp-0"))
sens_cpu_temp[0] = sr;
else if (!strcmp(sr->name, "cpu-diode-temp-1"))
sens_cpu_temp[1] = sr;
else if (!strcmp(sr->name, "cpu-voltage-0"))
sens_cpu_volts[0] = sr;
else if (!strcmp(sr->name, "cpu-voltage-1"))
sens_cpu_volts[1] = sr;
else if (!strcmp(sr->name, "cpu-current-0"))
sens_cpu_amps[0] = sr;
else if (!strcmp(sr->name, "cpu-current-1"))
sens_cpu_amps[1] = sr;
else if (!strcmp(sr->name, "backside-temp"))
backside_temp = sr;
else if (!strcmp(sr->name, "slots-temp"))
slots_temp = sr;
else if (!strcmp(sr->name, "dimms-temp"))
dimms_temp = sr;
all_sensors =
sens_cpu_temp[0] &&
sens_cpu_volts[0] &&
sens_cpu_amps[0] &&
backside_temp &&
slots_temp &&
dimms_temp;
if (nr_chips > 1)
all_sensors &=
sens_cpu_temp[1] &&
sens_cpu_volts[1] &&
sens_cpu_amps[1];
have_all_sensors = all_sensors;
}
static int rm31_wf_notify(struct notifier_block *self,
unsigned long event, void *data)
{
switch (event) {
case WF_EVENT_NEW_SENSOR:
rm31_new_sensor(data);
break;
case WF_EVENT_NEW_CONTROL:
rm31_new_control(data);
break;
case WF_EVENT_TICK:
if (have_all_controls && have_all_sensors)
rm31_tick();
}
return 0;
}
static int wf_rm31_probe(struct platform_device *dev)
{
wf_register_client(&rm31_events);
return 0;
}
static int __devexit wf_rm31_remove(struct platform_device *dev)
{
wf_unregister_client(&rm31_events);
return 0;
}
static int __init wf_rm31_init(void)
{
struct device_node *cpu;
int i;
if (!of_machine_is_compatible("RackMac3,1"))
return -ENODEV;
nr_chips = 0;
for (cpu = NULL; (cpu = of_find_node_by_type(cpu, "cpu")) != NULL; )
++nr_chips;
if (nr_chips > NR_CHIPS)
nr_chips = NR_CHIPS;
pr_info("windfarm: Initializing for desktop G5 with %d chips\n",
nr_chips);
for (i = 0; i < nr_chips; i++) {
cpu_mpu_data[i] = wf_get_mpu(i);
if (!cpu_mpu_data[i]) {
pr_err("wf_rm31: Failed to find MPU data for CPU %d\n", i);
return -ENXIO;
}
}
#ifdef MODULE
request_module("windfarm_fcu_controls");
request_module("windfarm_lm75_sensor");
request_module("windfarm_lm87_sensor");
request_module("windfarm_ad7417_sensor");
request_module("windfarm_max6690_sensor");
request_module("windfarm_cpufreq_clamp");
#endif
platform_driver_register(&wf_rm31_driver);
return 0;
}
static void __exit wf_rm31_exit(void)
{
platform_driver_unregister(&wf_rm31_driver);
}
