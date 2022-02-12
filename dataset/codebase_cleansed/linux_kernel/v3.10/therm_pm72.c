static struct i2c_client *attach_i2c_chip(int id, const char *name)
{
struct i2c_client *clt;
struct i2c_adapter *adap;
struct i2c_board_info info;
if (id & 0x200)
adap = k2;
else if (id & 0x100)
adap = u3_1;
else
adap = u3_0;
if (adap == NULL)
return NULL;
memset(&info, 0, sizeof(struct i2c_board_info));
info.addr = (id >> 1) & 0x7f;
strlcpy(info.type, "therm_pm72", I2C_NAME_SIZE);
clt = i2c_new_device(adap, &info);
if (!clt) {
printk(KERN_ERR "therm_pm72: Failed to attach to i2c ID 0x%x\n", id);
return NULL;
}
list_add_tail(&clt->detected, &therm_pm72_driver.clients);
return clt;
}
static void initialize_adc(struct cpu_pid_state *state)
{
int rc;
u8 buf[2];
buf[0] = 5;
buf[1] = 0;
i2c_master_send(state->monitor, buf, 2);
buf[0] = 1;
rc = i2c_master_send(state->monitor, buf, 1);
if (rc > 0) {
rc = i2c_master_recv(state->monitor, buf, 1);
if (rc > 0) {
state->adc_config = buf[0];
DBG("ADC config reg: %02x\n", state->adc_config);
state->adc_config &= 0xfe;
buf[0] = 1;
buf[1] = state->adc_config;
rc = i2c_master_send(state->monitor, buf, 2);
}
}
if (rc <= 0)
printk(KERN_ERR "therm_pm72: Error reading ADC config"
" register !\n");
}
static int read_smon_adc(struct cpu_pid_state *state, int chan)
{
int rc, data, tries = 0;
u8 buf[2];
for (;;) {
buf[0] = 1;
buf[1] = (state->adc_config & 0x1f) | (chan << 5);
rc = i2c_master_send(state->monitor, buf, 2);
if (rc <= 0)
goto error;
msleep(1);
buf[0] = 4;
rc = i2c_master_send(state->monitor, buf, 1);
if (rc <= 0)
goto error;
rc = i2c_master_recv(state->monitor, buf, 2);
if (rc < 0)
goto error;
data = ((u16)buf[0]) << 8 | (u16)buf[1];
return data >> 6;
error:
DBG("Error reading ADC, retrying...\n");
if (++tries > 10) {
printk(KERN_ERR "therm_pm72: Error reading ADC !\n");
return -1;
}
msleep(10);
}
}
static int read_lm87_reg(struct i2c_client * chip, int reg)
{
int rc, tries = 0;
u8 buf;
for (;;) {
buf = (u8)reg;
rc = i2c_master_send(chip, &buf, 1);
if (rc <= 0)
goto error;
rc = i2c_master_recv(chip, &buf, 1);
if (rc <= 0)
goto error;
return (int)buf;
error:
DBG("Error reading LM87, retrying...\n");
if (++tries > 10) {
printk(KERN_ERR "therm_pm72: Error reading LM87 !\n");
return -1;
}
msleep(10);
}
}
static int fan_read_reg(int reg, unsigned char *buf, int nb)
{
int tries, nr, nw;
buf[0] = reg;
tries = 0;
for (;;) {
nw = i2c_master_send(fcu, buf, 1);
if (nw > 0 || (nw < 0 && nw != -EIO) || tries >= 100)
break;
msleep(10);
++tries;
}
if (nw <= 0) {
printk(KERN_ERR "Failure writing address to FCU: %d", nw);
return -EIO;
}
tries = 0;
for (;;) {
nr = i2c_master_recv(fcu, buf, nb);
if (nr > 0 || (nr < 0 && nr != -ENODEV) || tries >= 100)
break;
msleep(10);
++tries;
}
if (nr <= 0)
printk(KERN_ERR "Failure reading data from FCU: %d", nw);
return nr;
}
static int fan_write_reg(int reg, const unsigned char *ptr, int nb)
{
int tries, nw;
unsigned char buf[16];
buf[0] = reg;
memcpy(buf+1, ptr, nb);
++nb;
tries = 0;
for (;;) {
nw = i2c_master_send(fcu, buf, nb);
if (nw > 0 || (nw < 0 && nw != -EIO) || tries >= 100)
break;
msleep(10);
++tries;
}
if (nw < 0)
printk(KERN_ERR "Failure writing to FCU: %d", nw);
return nw;
}
static int start_fcu(void)
{
unsigned char buf = 0xff;
int rc;
rc = fan_write_reg(0xe, &buf, 1);
if (rc < 0)
return -EIO;
rc = fan_write_reg(0x2e, &buf, 1);
if (rc < 0)
return -EIO;
rc = fan_read_reg(0, &buf, 1);
if (rc < 0)
return -EIO;
fcu_rpm_shift = (buf == 1) ? 2 : 3;
printk(KERN_DEBUG "FCU Initialized, RPM fan shift is %d\n",
fcu_rpm_shift);
return 0;
}
static int set_rpm_fan(int fan_index, int rpm)
{
unsigned char buf[2];
int rc, id, min, max;
if (fcu_fans[fan_index].type != FCU_FAN_RPM)
return -EINVAL;
id = fcu_fans[fan_index].id;
if (id == FCU_FAN_ABSENT_ID)
return -EINVAL;
min = 2400 >> fcu_rpm_shift;
max = 56000 >> fcu_rpm_shift;
if (rpm < min)
rpm = min;
else if (rpm > max)
rpm = max;
buf[0] = rpm >> (8 - fcu_rpm_shift);
buf[1] = rpm << fcu_rpm_shift;
rc = fan_write_reg(0x10 + (id * 2), buf, 2);
if (rc < 0)
return -EIO;
return 0;
}
static int get_rpm_fan(int fan_index, int programmed)
{
unsigned char failure;
unsigned char active;
unsigned char buf[2];
int rc, id, reg_base;
if (fcu_fans[fan_index].type != FCU_FAN_RPM)
return -EINVAL;
id = fcu_fans[fan_index].id;
if (id == FCU_FAN_ABSENT_ID)
return -EINVAL;
rc = fan_read_reg(0xb, &failure, 1);
if (rc != 1)
return -EIO;
if ((failure & (1 << id)) != 0)
return -EFAULT;
rc = fan_read_reg(0xd, &active, 1);
if (rc != 1)
return -EIO;
if ((active & (1 << id)) == 0)
return -ENXIO;
reg_base = programmed ? 0x10 : 0x11;
rc = fan_read_reg(reg_base + (id * 2), buf, 2);
if (rc != 2)
return -EIO;
return (buf[0] << (8 - fcu_rpm_shift)) | buf[1] >> fcu_rpm_shift;
}
static int set_pwm_fan(int fan_index, int pwm)
{
unsigned char buf[2];
int rc, id;
if (fcu_fans[fan_index].type != FCU_FAN_PWM)
return -EINVAL;
id = fcu_fans[fan_index].id;
if (id == FCU_FAN_ABSENT_ID)
return -EINVAL;
if (pwm < 10)
pwm = 10;
else if (pwm > 100)
pwm = 100;
pwm = (pwm * 2559) / 1000;
buf[0] = pwm;
rc = fan_write_reg(0x30 + (id * 2), buf, 1);
if (rc < 0)
return rc;
return 0;
}
static int get_pwm_fan(int fan_index)
{
unsigned char failure;
unsigned char active;
unsigned char buf[2];
int rc, id;
if (fcu_fans[fan_index].type != FCU_FAN_PWM)
return -EINVAL;
id = fcu_fans[fan_index].id;
if (id == FCU_FAN_ABSENT_ID)
return -EINVAL;
rc = fan_read_reg(0x2b, &failure, 1);
if (rc != 1)
return -EIO;
if ((failure & (1 << id)) != 0)
return -EFAULT;
rc = fan_read_reg(0x2d, &active, 1);
if (rc != 1)
return -EIO;
if ((active & (1 << id)) == 0)
return -ENXIO;
rc = fan_read_reg(0x30 + (id * 2), buf, 1);
if (rc != 1)
return -EIO;
return (buf[0] * 1000) / 2559;
}
static void tickle_fcu(void)
{
int pwm;
pwm = get_pwm_fan(SLOTS_FAN_PWM_INDEX);
DBG("FCU Tickle, slots fan is: %d\n", pwm);
if (pwm < 0)
pwm = 100;
if (!rackmac) {
pwm = SLOTS_FAN_DEFAULT_PWM;
} else if (pwm < SLOTS_PID_OUTPUT_MIN)
pwm = SLOTS_PID_OUTPUT_MIN;
set_pwm_fan(SLOTS_FAN_PWM_INDEX, pwm);
}
static int read_eeprom(int cpu, struct mpu_data *out)
{
struct device_node *np;
char nodename[64];
const u8 *data;
int len;
sprintf(nodename, "/u3@0,f8000000/i2c@f8001000/cpuid@a%d", cpu ? 2 : 0);
np = of_find_node_by_path(nodename);
if (np == NULL) {
printk(KERN_ERR "therm_pm72: Failed to retrieve cpuid node from device-tree\n");
return -ENODEV;
}
data = of_get_property(np, "cpuid", &len);
if (data == NULL) {
printk(KERN_ERR "therm_pm72: Failed to retrieve cpuid property from device-tree\n");
of_node_put(np);
return -ENODEV;
}
memcpy(out, data, sizeof(struct mpu_data));
of_node_put(np);
return 0;
}
static void fetch_cpu_pumps_minmax(void)
{
struct cpu_pid_state *state0 = &processor_state[0];
struct cpu_pid_state *state1 = &processor_state[1];
u16 pump_min = 0, pump_max = 0xffff;
u16 tmp[4];
memcpy(&tmp, &state0->mpu.processor_part_num, 8);
if (tmp[0] != 0xffff && tmp[1] != 0xffff) {
pump_min = max(pump_min, tmp[0]);
pump_max = min(pump_max, tmp[1]);
}
if (tmp[2] != 0xffff && tmp[3] != 0xffff) {
pump_min = max(pump_min, tmp[2]);
pump_max = min(pump_max, tmp[3]);
}
if (pump_min == pump_max || pump_min == 0 || pump_max == 0xffff) {
pump_min = CPU_PUMP_OUTPUT_MIN;
pump_max = CPU_PUMP_OUTPUT_MAX;
}
state0->pump_min = state1->pump_min = pump_min;
state0->pump_max = state1->pump_max = pump_max;
}
static int do_read_one_cpu_values(struct cpu_pid_state *state, s32 *temp, s32 *power)
{
s32 ltemp, volts, amps;
int index, rc = 0;
*temp = state->cur_temp;
*power = state->cur_power;
if (cpu_pid_type == CPU_PID_TYPE_RACKMAC)
index = (state->index == 0) ?
CPU_A1_FAN_RPM_INDEX : CPU_B1_FAN_RPM_INDEX;
else
index = (state->index == 0) ?
CPUA_EXHAUST_FAN_RPM_INDEX : CPUB_EXHAUST_FAN_RPM_INDEX;
rc = get_rpm_fan(index, !RPM_PID_USE_ACTUAL_SPEED);
if (rc < 0) {
DBG(" cpu %d, fan reading error !\n", state->index);
} else {
state->rpm = rc;
DBG(" cpu %d, exhaust RPM: %d\n", state->index, state->rpm);
}
ltemp = read_smon_adc(state, 1);
if (ltemp == -1) {
state->overtemp++;
if (rc == 0)
rc = -EIO;
DBG(" cpu %d, temp reading error !\n", state->index);
} else {
DBG(" cpu %d, temp raw: %04x, m_diode: %04x, b_diode: %04x\n",
state->index,
ltemp, state->mpu.mdiode, state->mpu.bdiode);
*temp = ((s32)ltemp * (s32)state->mpu.mdiode + ((s32)state->mpu.bdiode << 12)) >> 2;
state->last_temp = *temp;
DBG(" temp: %d.%03d\n", FIX32TOPRINT((*temp)));
}
volts = read_smon_adc(state, 3);
amps = read_smon_adc(state, 4);
volts *= ADC_CPU_VOLTAGE_SCALE;
amps *= ADC_CPU_CURRENT_SCALE;
*power = (((u64)volts) * ((u64)amps)) >> 16;
state->voltage = volts;
state->current_a = amps;
state->last_power = *power;
DBG(" cpu %d, current: %d.%03d, voltage: %d.%03d, power: %d.%03d W\n",
state->index, FIX32TOPRINT(state->current_a),
FIX32TOPRINT(state->voltage), FIX32TOPRINT(*power));
return 0;
}
static void do_cpu_pid(struct cpu_pid_state *state, s32 temp, s32 power)
{
s32 power_target, integral, derivative, proportional, adj_in_target, sval;
s64 integ_p, deriv_p, prop_p, sum;
int i;
power_target = ((u32)(state->mpu.pmaxh - state->mpu.padjmax)) << 16;
DBG(" power target: %d.%03d, error: %d.%03d\n",
FIX32TOPRINT(power_target), FIX32TOPRINT(power_target - power));
state->cur_temp = (state->cur_temp + 1) % CPU_TEMP_HISTORY_SIZE;
state->temp_history[state->cur_temp] = temp;
state->cur_power = (state->cur_power + 1) % state->count_power;
state->power_history[state->cur_power] = power;
state->error_history[state->cur_power] = power_target - power;
if (state->first) {
for (i = 0; i < (state->count_power - 1); i++) {
state->cur_power = (state->cur_power + 1) % state->count_power;
state->power_history[state->cur_power] = power;
state->error_history[state->cur_power] = power_target - power;
}
for (i = 0; i < (CPU_TEMP_HISTORY_SIZE - 1); i++) {
state->cur_temp = (state->cur_temp + 1) % CPU_TEMP_HISTORY_SIZE;
state->temp_history[state->cur_temp] = temp;
}
state->first = 0;
}
sum = 0;
integral = 0;
for (i = 0; i < state->count_power; i++)
integral += state->error_history[i];
integral *= CPU_PID_INTERVAL;
DBG(" integral: %08x\n", integral);
integ_p = ((s64)state->mpu.pid_gr) * (s64)integral;
DBG(" integ_p: %d\n", (int)(integ_p >> 36));
sval = (state->mpu.tmax << 16) - ((integ_p >> 20) & 0xffffffff);
adj_in_target = (state->mpu.ttarget << 16);
if (adj_in_target > sval)
adj_in_target = sval;
DBG(" adj_in_target: %d.%03d, ttarget: %d\n", FIX32TOPRINT(adj_in_target),
state->mpu.ttarget);
derivative = state->temp_history[state->cur_temp] -
state->temp_history[(state->cur_temp + CPU_TEMP_HISTORY_SIZE - 1)
% CPU_TEMP_HISTORY_SIZE];
derivative /= CPU_PID_INTERVAL;
deriv_p = ((s64)state->mpu.pid_gd) * (s64)derivative;
DBG(" deriv_p: %d\n", (int)(deriv_p >> 36));
sum += deriv_p;
proportional = temp - adj_in_target;
prop_p = ((s64)state->mpu.pid_gp) * (s64)proportional;
DBG(" prop_p: %d\n", (int)(prop_p >> 36));
sum += prop_p;
sum >>= 36;
DBG(" sum: %d\n", (int)sum);
state->rpm += (s32)sum;
}
static void do_monitor_cpu_combined(void)
{
struct cpu_pid_state *state0 = &processor_state[0];
struct cpu_pid_state *state1 = &processor_state[1];
s32 temp0, power0, temp1, power1;
s32 temp_combi, power_combi;
int rc, intake, pump;
rc = do_read_one_cpu_values(state0, &temp0, &power0);
if (rc < 0) {
}
state1->overtemp = 0;
rc = do_read_one_cpu_values(state1, &temp1, &power1);
if (rc < 0) {
}
if (state1->overtemp)
state0->overtemp++;
temp_combi = max(temp0, temp1);
power_combi = max(power0, power1);
if (temp_combi >= ((state0->mpu.tmax + 8) << 16)) {
printk(KERN_WARNING "Warning ! Temperature way above maximum (%d) !\n",
temp_combi >> 16);
state0->overtemp += CPU_MAX_OVERTEMP / 4;
} else if (temp_combi > (state0->mpu.tmax << 16)) {
state0->overtemp++;
printk(KERN_WARNING "Temperature %d above max %d. overtemp %d\n",
temp_combi >> 16, state0->mpu.tmax, state0->overtemp);
} else {
if (state0->overtemp)
printk(KERN_WARNING "Temperature back down to %d\n",
temp_combi >> 16);
state0->overtemp = 0;
}
if (state0->overtemp >= CPU_MAX_OVERTEMP)
critical_state = 1;
if (state0->overtemp > 0) {
state0->rpm = state0->mpu.rmaxn_exhaust_fan;
state0->intake_rpm = intake = state0->mpu.rmaxn_intake_fan;
pump = state0->pump_max;
goto do_set_fans;
}
do_cpu_pid(state0, temp_combi, power_combi);
state0->rpm = max(state0->rpm, (int)state0->mpu.rminn_exhaust_fan);
state0->rpm = min(state0->rpm, (int)state0->mpu.rmaxn_exhaust_fan);
intake = (state0->rpm * CPU_INTAKE_SCALE) >> 16;
intake = max(intake, (int)state0->mpu.rminn_intake_fan);
intake = min(intake, (int)state0->mpu.rmaxn_intake_fan);
state0->intake_rpm = intake;
pump = (state0->rpm * state0->pump_max) /
state0->mpu.rmaxn_exhaust_fan;
pump = min(pump, state0->pump_max);
pump = max(pump, state0->pump_min);
do_set_fans:
state1->rpm = state0->rpm;
state1->intake_rpm = state0->intake_rpm;
DBG("** CPU %d RPM: %d Ex, %d, Pump: %d, In, overtemp: %d\n",
state1->index, (int)state1->rpm, intake, pump, state1->overtemp);
set_rpm_fan(CPUA_INTAKE_FAN_RPM_INDEX, intake);
set_rpm_fan(CPUA_EXHAUST_FAN_RPM_INDEX, state0->rpm);
set_rpm_fan(CPUB_INTAKE_FAN_RPM_INDEX, intake);
set_rpm_fan(CPUB_EXHAUST_FAN_RPM_INDEX, state0->rpm);
if (fcu_fans[CPUA_PUMP_RPM_INDEX].id != FCU_FAN_ABSENT_ID)
set_rpm_fan(CPUA_PUMP_RPM_INDEX, pump);
if (fcu_fans[CPUB_PUMP_RPM_INDEX].id != FCU_FAN_ABSENT_ID)
set_rpm_fan(CPUB_PUMP_RPM_INDEX, pump);
}
static void do_monitor_cpu_split(struct cpu_pid_state *state)
{
s32 temp, power;
int rc, intake;
rc = do_read_one_cpu_values(state, &temp, &power);
if (rc < 0) {
}
if (temp >= ((state->mpu.tmax + 8) << 16)) {
printk(KERN_WARNING "Warning ! CPU %d temperature way above maximum"
" (%d) !\n",
state->index, temp >> 16);
state->overtemp += CPU_MAX_OVERTEMP / 4;
} else if (temp > (state->mpu.tmax << 16)) {
state->overtemp++;
printk(KERN_WARNING "CPU %d temperature %d above max %d. overtemp %d\n",
state->index, temp >> 16, state->mpu.tmax, state->overtemp);
} else {
if (state->overtemp)
printk(KERN_WARNING "CPU %d temperature back down to %d\n",
state->index, temp >> 16);
state->overtemp = 0;
}
if (state->overtemp >= CPU_MAX_OVERTEMP)
critical_state = 1;
if (state->overtemp > 0) {
state->rpm = state->mpu.rmaxn_exhaust_fan;
state->intake_rpm = intake = state->mpu.rmaxn_intake_fan;
goto do_set_fans;
}
do_cpu_pid(state, temp, power);
state->rpm = max(state->rpm, (int)state->mpu.rminn_exhaust_fan);
state->rpm = min(state->rpm, (int)state->mpu.rmaxn_exhaust_fan);
intake = (state->rpm * CPU_INTAKE_SCALE) >> 16;
intake = max(intake, (int)state->mpu.rminn_intake_fan);
intake = min(intake, (int)state->mpu.rmaxn_intake_fan);
state->intake_rpm = intake;
do_set_fans:
DBG("** CPU %d RPM: %d Ex, %d In, overtemp: %d\n",
state->index, (int)state->rpm, intake, state->overtemp);
if (state->index == 0) {
set_rpm_fan(CPUA_INTAKE_FAN_RPM_INDEX, intake);
set_rpm_fan(CPUA_EXHAUST_FAN_RPM_INDEX, state->rpm);
} else {
set_rpm_fan(CPUB_INTAKE_FAN_RPM_INDEX, intake);
set_rpm_fan(CPUB_EXHAUST_FAN_RPM_INDEX, state->rpm);
}
}
static void do_monitor_cpu_rack(struct cpu_pid_state *state)
{
s32 temp, power, fan_min;
int rc;
rc = do_read_one_cpu_values(state, &temp, &power);
if (rc < 0) {
}
if (temp >= ((state->mpu.tmax + 8) << 16)) {
printk(KERN_WARNING "Warning ! CPU %d temperature way above maximum"
" (%d) !\n",
state->index, temp >> 16);
state->overtemp = CPU_MAX_OVERTEMP / 4;
} else if (temp > (state->mpu.tmax << 16)) {
state->overtemp++;
printk(KERN_WARNING "CPU %d temperature %d above max %d. overtemp %d\n",
state->index, temp >> 16, state->mpu.tmax, state->overtemp);
} else {
if (state->overtemp)
printk(KERN_WARNING "CPU %d temperature back down to %d\n",
state->index, temp >> 16);
state->overtemp = 0;
}
if (state->overtemp >= CPU_MAX_OVERTEMP)
critical_state = 1;
if (state->overtemp > 0) {
state->rpm = state->intake_rpm = state->mpu.rmaxn_intake_fan;
goto do_set_fans;
}
do_cpu_pid(state, temp, power);
fan_min = dimm_output_clamp;
fan_min = max(fan_min, (int)state->mpu.rminn_intake_fan);
DBG(" CPU min mpu = %d, min dimm = %d\n",
state->mpu.rminn_intake_fan, dimm_output_clamp);
state->rpm = max(state->rpm, (int)fan_min);
state->rpm = min(state->rpm, (int)state->mpu.rmaxn_intake_fan);
state->intake_rpm = state->rpm;
do_set_fans:
DBG("** CPU %d RPM: %d overtemp: %d\n",
state->index, (int)state->rpm, state->overtemp);
if (state->index == 0) {
set_rpm_fan(CPU_A1_FAN_RPM_INDEX, state->rpm);
set_rpm_fan(CPU_A2_FAN_RPM_INDEX, state->rpm);
set_rpm_fan(CPU_A3_FAN_RPM_INDEX, state->rpm);
} else {
set_rpm_fan(CPU_B1_FAN_RPM_INDEX, state->rpm);
set_rpm_fan(CPU_B2_FAN_RPM_INDEX, state->rpm);
set_rpm_fan(CPU_B3_FAN_RPM_INDEX, state->rpm);
}
}
static int init_processor_state(struct cpu_pid_state *state, int index)
{
int err;
state->index = index;
state->first = 1;
state->rpm = (cpu_pid_type == CPU_PID_TYPE_RACKMAC) ? 4000 : 1000;
state->overtemp = 0;
state->adc_config = 0x00;
if (index == 0)
state->monitor = attach_i2c_chip(SUPPLY_MONITOR_ID, "CPU0_monitor");
else if (index == 1)
state->monitor = attach_i2c_chip(SUPPLY_MONITORB_ID, "CPU1_monitor");
if (state->monitor == NULL)
goto fail;
if (read_eeprom(index, &state->mpu))
goto fail;
state->count_power = state->mpu.tguardband;
if (state->count_power > CPU_POWER_HISTORY_SIZE) {
printk(KERN_WARNING "Warning ! too many power history slots\n");
state->count_power = CPU_POWER_HISTORY_SIZE;
}
DBG("CPU %d Using %d power history entries\n", index, state->count_power);
if (index == 0) {
err = device_create_file(&of_dev->dev, &dev_attr_cpu0_temperature);
err |= device_create_file(&of_dev->dev, &dev_attr_cpu0_voltage);
err |= device_create_file(&of_dev->dev, &dev_attr_cpu0_current);
err |= device_create_file(&of_dev->dev, &dev_attr_cpu0_exhaust_fan_rpm);
err |= device_create_file(&of_dev->dev, &dev_attr_cpu0_intake_fan_rpm);
} else {
err = device_create_file(&of_dev->dev, &dev_attr_cpu1_temperature);
err |= device_create_file(&of_dev->dev, &dev_attr_cpu1_voltage);
err |= device_create_file(&of_dev->dev, &dev_attr_cpu1_current);
err |= device_create_file(&of_dev->dev, &dev_attr_cpu1_exhaust_fan_rpm);
err |= device_create_file(&of_dev->dev, &dev_attr_cpu1_intake_fan_rpm);
}
if (err)
printk(KERN_WARNING "Failed to create some of the attribute"
"files for CPU %d\n", index);
return 0;
fail:
state->monitor = NULL;
return -ENODEV;
}
static void dispose_processor_state(struct cpu_pid_state *state)
{
if (state->monitor == NULL)
return;
if (state->index == 0) {
device_remove_file(&of_dev->dev, &dev_attr_cpu0_temperature);
device_remove_file(&of_dev->dev, &dev_attr_cpu0_voltage);
device_remove_file(&of_dev->dev, &dev_attr_cpu0_current);
device_remove_file(&of_dev->dev, &dev_attr_cpu0_exhaust_fan_rpm);
device_remove_file(&of_dev->dev, &dev_attr_cpu0_intake_fan_rpm);
} else {
device_remove_file(&of_dev->dev, &dev_attr_cpu1_temperature);
device_remove_file(&of_dev->dev, &dev_attr_cpu1_voltage);
device_remove_file(&of_dev->dev, &dev_attr_cpu1_current);
device_remove_file(&of_dev->dev, &dev_attr_cpu1_exhaust_fan_rpm);
device_remove_file(&of_dev->dev, &dev_attr_cpu1_intake_fan_rpm);
}
state->monitor = NULL;
}
static void do_monitor_backside(struct backside_pid_state *state)
{
s32 temp, integral, derivative, fan_min;
s64 integ_p, deriv_p, prop_p, sum;
int i, rc;
if (--state->ticks != 0)
return;
state->ticks = backside_params.interval;
DBG("backside:\n");
rc = get_pwm_fan(BACKSIDE_FAN_PWM_INDEX);
if (rc < 0) {
printk(KERN_WARNING "Error %d reading backside fan !\n", rc);
} else
state->pwm = rc;
DBG(" current pwm: %d\n", state->pwm);
temp = i2c_smbus_read_byte_data(state->monitor, MAX6690_EXT_TEMP) << 16;
state->last_temp = temp;
DBG(" temp: %d.%03d, target: %d.%03d\n", FIX32TOPRINT(temp),
FIX32TOPRINT(backside_params.input_target));
state->cur_sample = (state->cur_sample + 1) % BACKSIDE_PID_HISTORY_SIZE;
state->sample_history[state->cur_sample] = temp;
state->error_history[state->cur_sample] = temp - backside_params.input_target;
if (state->first) {
for (i = 0; i < (BACKSIDE_PID_HISTORY_SIZE - 1); i++) {
state->cur_sample = (state->cur_sample + 1) %
BACKSIDE_PID_HISTORY_SIZE;
state->sample_history[state->cur_sample] = temp;
state->error_history[state->cur_sample] =
temp - backside_params.input_target;
}
state->first = 0;
}
sum = 0;
integral = 0;
for (i = 0; i < BACKSIDE_PID_HISTORY_SIZE; i++)
integral += state->error_history[i];
integral *= backside_params.interval;
DBG(" integral: %08x\n", integral);
integ_p = ((s64)backside_params.G_r) * (s64)integral;
DBG(" integ_p: %d\n", (int)(integ_p >> 36));
sum += integ_p;
derivative = state->error_history[state->cur_sample] -
state->error_history[(state->cur_sample + BACKSIDE_PID_HISTORY_SIZE - 1)
% BACKSIDE_PID_HISTORY_SIZE];
derivative /= backside_params.interval;
deriv_p = ((s64)backside_params.G_d) * (s64)derivative;
DBG(" deriv_p: %d\n", (int)(deriv_p >> 36));
sum += deriv_p;
prop_p = ((s64)backside_params.G_p) * (s64)(state->error_history[state->cur_sample]);
DBG(" prop_p: %d\n", (int)(prop_p >> 36));
sum += prop_p;
sum >>= 36;
DBG(" sum: %d\n", (int)sum);
if (backside_params.additive)
state->pwm += (s32)sum;
else
state->pwm = sum;
fan_min = (dimm_output_clamp * 100) / 14000;
fan_min = max(fan_min, backside_params.output_min);
state->pwm = max(state->pwm, fan_min);
state->pwm = min(state->pwm, backside_params.output_max);
DBG("** BACKSIDE PWM: %d\n", (int)state->pwm);
set_pwm_fan(BACKSIDE_FAN_PWM_INDEX, state->pwm);
}
static int init_backside_state(struct backside_pid_state *state)
{
struct device_node *u3;
int u3h = 1;
int err;
u3 = of_find_node_by_path("/u3@0,f8000000");
if (u3 != NULL) {
const u32 *vers = of_get_property(u3, "device-rev", NULL);
if (vers)
if (((*vers) & 0x3f) < 0x34)
u3h = 0;
of_node_put(u3);
}
if (rackmac) {
backside_params.G_d = BACKSIDE_PID_RACK_G_d;
backside_params.input_target = BACKSIDE_PID_RACK_INPUT_TARGET;
backside_params.output_min = BACKSIDE_PID_U3H_OUTPUT_MIN;
backside_params.interval = BACKSIDE_PID_RACK_INTERVAL;
backside_params.G_p = BACKSIDE_PID_RACK_G_p;
backside_params.G_r = BACKSIDE_PID_G_r;
backside_params.output_max = BACKSIDE_PID_OUTPUT_MAX;
backside_params.additive = 0;
} else if (u3h) {
backside_params.G_d = BACKSIDE_PID_U3H_G_d;
backside_params.input_target = BACKSIDE_PID_U3H_INPUT_TARGET;
backside_params.output_min = BACKSIDE_PID_U3H_OUTPUT_MIN;
backside_params.interval = BACKSIDE_PID_INTERVAL;
backside_params.G_p = BACKSIDE_PID_G_p;
backside_params.G_r = BACKSIDE_PID_G_r;
backside_params.output_max = BACKSIDE_PID_OUTPUT_MAX;
backside_params.additive = 1;
} else {
backside_params.G_d = BACKSIDE_PID_U3_G_d;
backside_params.input_target = BACKSIDE_PID_U3_INPUT_TARGET;
backside_params.output_min = BACKSIDE_PID_U3_OUTPUT_MIN;
backside_params.interval = BACKSIDE_PID_INTERVAL;
backside_params.G_p = BACKSIDE_PID_G_p;
backside_params.G_r = BACKSIDE_PID_G_r;
backside_params.output_max = BACKSIDE_PID_OUTPUT_MAX;
backside_params.additive = 1;
}
state->ticks = 1;
state->first = 1;
state->pwm = 50;
state->monitor = attach_i2c_chip(BACKSIDE_MAX_ID, "backside_temp");
if (state->monitor == NULL)
return -ENODEV;
err = device_create_file(&of_dev->dev, &dev_attr_backside_temperature);
err |= device_create_file(&of_dev->dev, &dev_attr_backside_fan_pwm);
if (err)
printk(KERN_WARNING "Failed to create attribute file(s)"
" for backside fan\n");
return 0;
}
static void dispose_backside_state(struct backside_pid_state *state)
{
if (state->monitor == NULL)
return;
device_remove_file(&of_dev->dev, &dev_attr_backside_temperature);
device_remove_file(&of_dev->dev, &dev_attr_backside_fan_pwm);
state->monitor = NULL;
}
static void do_monitor_drives(struct drives_pid_state *state)
{
s32 temp, integral, derivative;
s64 integ_p, deriv_p, prop_p, sum;
int i, rc;
if (--state->ticks != 0)
return;
state->ticks = DRIVES_PID_INTERVAL;
DBG("drives:\n");
rc = get_rpm_fan(DRIVES_FAN_RPM_INDEX, !RPM_PID_USE_ACTUAL_SPEED);
if (rc < 0) {
printk(KERN_WARNING "Error %d reading drives fan !\n", rc);
} else
state->rpm = rc;
DBG(" current rpm: %d\n", state->rpm);
temp = le16_to_cpu(i2c_smbus_read_word_data(state->monitor,
DS1775_TEMP)) << 8;
state->last_temp = temp;
DBG(" temp: %d.%03d, target: %d.%03d\n", FIX32TOPRINT(temp),
FIX32TOPRINT(DRIVES_PID_INPUT_TARGET));
state->cur_sample = (state->cur_sample + 1) % DRIVES_PID_HISTORY_SIZE;
state->sample_history[state->cur_sample] = temp;
state->error_history[state->cur_sample] = temp - DRIVES_PID_INPUT_TARGET;
if (state->first) {
for (i = 0; i < (DRIVES_PID_HISTORY_SIZE - 1); i++) {
state->cur_sample = (state->cur_sample + 1) %
DRIVES_PID_HISTORY_SIZE;
state->sample_history[state->cur_sample] = temp;
state->error_history[state->cur_sample] =
temp - DRIVES_PID_INPUT_TARGET;
}
state->first = 0;
}
sum = 0;
integral = 0;
for (i = 0; i < DRIVES_PID_HISTORY_SIZE; i++)
integral += state->error_history[i];
integral *= DRIVES_PID_INTERVAL;
DBG(" integral: %08x\n", integral);
integ_p = ((s64)DRIVES_PID_G_r) * (s64)integral;
DBG(" integ_p: %d\n", (int)(integ_p >> 36));
sum += integ_p;
derivative = state->error_history[state->cur_sample] -
state->error_history[(state->cur_sample + DRIVES_PID_HISTORY_SIZE - 1)
% DRIVES_PID_HISTORY_SIZE];
derivative /= DRIVES_PID_INTERVAL;
deriv_p = ((s64)DRIVES_PID_G_d) * (s64)derivative;
DBG(" deriv_p: %d\n", (int)(deriv_p >> 36));
sum += deriv_p;
prop_p = ((s64)DRIVES_PID_G_p) * (s64)(state->error_history[state->cur_sample]);
DBG(" prop_p: %d\n", (int)(prop_p >> 36));
sum += prop_p;
sum >>= 36;
DBG(" sum: %d\n", (int)sum);
state->rpm += (s32)sum;
state->rpm = max(state->rpm, DRIVES_PID_OUTPUT_MIN);
state->rpm = min(state->rpm, DRIVES_PID_OUTPUT_MAX);
DBG("** DRIVES RPM: %d\n", (int)state->rpm);
set_rpm_fan(DRIVES_FAN_RPM_INDEX, state->rpm);
}
static int init_drives_state(struct drives_pid_state *state)
{
int err;
state->ticks = 1;
state->first = 1;
state->rpm = 1000;
state->monitor = attach_i2c_chip(DRIVES_DALLAS_ID, "drives_temp");
if (state->monitor == NULL)
return -ENODEV;
err = device_create_file(&of_dev->dev, &dev_attr_drives_temperature);
err |= device_create_file(&of_dev->dev, &dev_attr_drives_fan_rpm);
if (err)
printk(KERN_WARNING "Failed to create attribute file(s)"
" for drives bay fan\n");
return 0;
}
static void dispose_drives_state(struct drives_pid_state *state)
{
if (state->monitor == NULL)
return;
device_remove_file(&of_dev->dev, &dev_attr_drives_temperature);
device_remove_file(&of_dev->dev, &dev_attr_drives_fan_rpm);
state->monitor = NULL;
}
static void do_monitor_dimms(struct dimm_pid_state *state)
{
s32 temp, integral, derivative, fan_min;
s64 integ_p, deriv_p, prop_p, sum;
int i;
if (--state->ticks != 0)
return;
state->ticks = DIMM_PID_INTERVAL;
DBG("DIMM:\n");
DBG(" current value: %d\n", state->output);
temp = read_lm87_reg(state->monitor, LM87_INT_TEMP);
if (temp < 0)
return;
temp <<= 16;
state->last_temp = temp;
DBG(" temp: %d.%03d, target: %d.%03d\n", FIX32TOPRINT(temp),
FIX32TOPRINT(DIMM_PID_INPUT_TARGET));
state->cur_sample = (state->cur_sample + 1) % DIMM_PID_HISTORY_SIZE;
state->sample_history[state->cur_sample] = temp;
state->error_history[state->cur_sample] = temp - DIMM_PID_INPUT_TARGET;
if (state->first) {
for (i = 0; i < (DIMM_PID_HISTORY_SIZE - 1); i++) {
state->cur_sample = (state->cur_sample + 1) %
DIMM_PID_HISTORY_SIZE;
state->sample_history[state->cur_sample] = temp;
state->error_history[state->cur_sample] =
temp - DIMM_PID_INPUT_TARGET;
}
state->first = 0;
}
sum = 0;
integral = 0;
for (i = 0; i < DIMM_PID_HISTORY_SIZE; i++)
integral += state->error_history[i];
integral *= DIMM_PID_INTERVAL;
DBG(" integral: %08x\n", integral);
integ_p = ((s64)DIMM_PID_G_r) * (s64)integral;
DBG(" integ_p: %d\n", (int)(integ_p >> 36));
sum += integ_p;
derivative = state->error_history[state->cur_sample] -
state->error_history[(state->cur_sample + DIMM_PID_HISTORY_SIZE - 1)
% DIMM_PID_HISTORY_SIZE];
derivative /= DIMM_PID_INTERVAL;
deriv_p = ((s64)DIMM_PID_G_d) * (s64)derivative;
DBG(" deriv_p: %d\n", (int)(deriv_p >> 36));
sum += deriv_p;
prop_p = ((s64)DIMM_PID_G_p) * (s64)(state->error_history[state->cur_sample]);
DBG(" prop_p: %d\n", (int)(prop_p >> 36));
sum += prop_p;
sum >>= 36;
DBG(" sum: %d\n", (int)sum);
state->output = (s32)sum;
state->output = max(state->output, DIMM_PID_OUTPUT_MIN);
state->output = min(state->output, DIMM_PID_OUTPUT_MAX);
dimm_output_clamp = state->output;
DBG("** DIMM clamp value: %d\n", (int)state->output);
fan_min = (dimm_output_clamp * 100) / 14000;
fan_min = max(fan_min, backside_params.output_min);
if (backside_state.pwm < fan_min) {
backside_state.pwm = fan_min;
DBG(" -> applying clamp to backside fan now: %d !\n", fan_min);
set_pwm_fan(BACKSIDE_FAN_PWM_INDEX, fan_min);
}
}
static int init_dimms_state(struct dimm_pid_state *state)
{
state->ticks = 1;
state->first = 1;
state->output = 4000;
state->monitor = attach_i2c_chip(XSERVE_DIMMS_LM87, "dimms_temp");
if (state->monitor == NULL)
return -ENODEV;
if (device_create_file(&of_dev->dev, &dev_attr_dimms_temperature))
printk(KERN_WARNING "Failed to create attribute file"
" for DIMM temperature\n");
return 0;
}
static void dispose_dimms_state(struct dimm_pid_state *state)
{
if (state->monitor == NULL)
return;
device_remove_file(&of_dev->dev, &dev_attr_dimms_temperature);
state->monitor = NULL;
}
static void do_monitor_slots(struct slots_pid_state *state)
{
s32 temp, integral, derivative;
s64 integ_p, deriv_p, prop_p, sum;
int i, rc;
if (--state->ticks != 0)
return;
state->ticks = SLOTS_PID_INTERVAL;
DBG("slots:\n");
rc = get_pwm_fan(SLOTS_FAN_PWM_INDEX);
if (rc < 0) {
printk(KERN_WARNING "Error %d reading slots fan !\n", rc);
} else
state->pwm = rc;
DBG(" current pwm: %d\n", state->pwm);
temp = le16_to_cpu(i2c_smbus_read_word_data(state->monitor,
DS1775_TEMP)) << 8;
state->last_temp = temp;
DBG(" temp: %d.%03d, target: %d.%03d\n", FIX32TOPRINT(temp),
FIX32TOPRINT(SLOTS_PID_INPUT_TARGET));
state->cur_sample = (state->cur_sample + 1) % SLOTS_PID_HISTORY_SIZE;
state->sample_history[state->cur_sample] = temp;
state->error_history[state->cur_sample] = temp - SLOTS_PID_INPUT_TARGET;
if (state->first) {
for (i = 0; i < (SLOTS_PID_HISTORY_SIZE - 1); i++) {
state->cur_sample = (state->cur_sample + 1) %
SLOTS_PID_HISTORY_SIZE;
state->sample_history[state->cur_sample] = temp;
state->error_history[state->cur_sample] =
temp - SLOTS_PID_INPUT_TARGET;
}
state->first = 0;
}
sum = 0;
integral = 0;
for (i = 0; i < SLOTS_PID_HISTORY_SIZE; i++)
integral += state->error_history[i];
integral *= SLOTS_PID_INTERVAL;
DBG(" integral: %08x\n", integral);
integ_p = ((s64)SLOTS_PID_G_r) * (s64)integral;
DBG(" integ_p: %d\n", (int)(integ_p >> 36));
sum += integ_p;
derivative = state->error_history[state->cur_sample] -
state->error_history[(state->cur_sample + SLOTS_PID_HISTORY_SIZE - 1)
% SLOTS_PID_HISTORY_SIZE];
derivative /= SLOTS_PID_INTERVAL;
deriv_p = ((s64)SLOTS_PID_G_d) * (s64)derivative;
DBG(" deriv_p: %d\n", (int)(deriv_p >> 36));
sum += deriv_p;
prop_p = ((s64)SLOTS_PID_G_p) * (s64)(state->error_history[state->cur_sample]);
DBG(" prop_p: %d\n", (int)(prop_p >> 36));
sum += prop_p;
sum >>= 36;
DBG(" sum: %d\n", (int)sum);
state->pwm = (s32)sum;
state->pwm = max(state->pwm, SLOTS_PID_OUTPUT_MIN);
state->pwm = min(state->pwm, SLOTS_PID_OUTPUT_MAX);
DBG("** DRIVES PWM: %d\n", (int)state->pwm);
set_pwm_fan(SLOTS_FAN_PWM_INDEX, state->pwm);
}
static int init_slots_state(struct slots_pid_state *state)
{
int err;
state->ticks = 1;
state->first = 1;
state->pwm = 50;
state->monitor = attach_i2c_chip(XSERVE_SLOTS_LM75, "slots_temp");
if (state->monitor == NULL)
return -ENODEV;
err = device_create_file(&of_dev->dev, &dev_attr_slots_temperature);
err |= device_create_file(&of_dev->dev, &dev_attr_slots_fan_pwm);
if (err)
printk(KERN_WARNING "Failed to create attribute file(s)"
" for slots bay fan\n");
return 0;
}
static void dispose_slots_state(struct slots_pid_state *state)
{
if (state->monitor == NULL)
return;
device_remove_file(&of_dev->dev, &dev_attr_slots_temperature);
device_remove_file(&of_dev->dev, &dev_attr_slots_fan_pwm);
state->monitor = NULL;
}
static int call_critical_overtemp(void)
{
char *argv[] = { critical_overtemp_path, NULL };
static char *envp[] = { "HOME=/",
"TERM=linux",
"PATH=/sbin:/usr/sbin:/bin:/usr/bin",
NULL };
return call_usermodehelper(critical_overtemp_path,
argv, envp, UMH_WAIT_EXEC);
}
static int main_control_loop(void *x)
{
DBG("main_control_loop started\n");
mutex_lock(&driver_lock);
if (start_fcu() < 0) {
printk(KERN_ERR "kfand: failed to start FCU\n");
mutex_unlock(&driver_lock);
goto out;
}
if (!rackmac)
set_pwm_fan(SLOTS_FAN_PWM_INDEX, SLOTS_FAN_DEFAULT_PWM);
initialize_adc(&processor_state[0]);
if (processor_state[1].monitor != NULL)
initialize_adc(&processor_state[1]);
fcu_tickle_ticks = FCU_TICKLE_TICKS;
mutex_unlock(&driver_lock);
while (state == state_attached) {
unsigned long elapsed, start;
start = jiffies;
mutex_lock(&driver_lock);
if (--fcu_tickle_ticks < 0) {
fcu_tickle_ticks = FCU_TICKLE_TICKS;
tickle_fcu();
}
if (rackmac)
do_monitor_dimms(&dimms_state);
if (cpu_pid_type == CPU_PID_TYPE_COMBINED)
do_monitor_cpu_combined();
else if (cpu_pid_type == CPU_PID_TYPE_RACKMAC) {
do_monitor_cpu_rack(&processor_state[0]);
if (processor_state[1].monitor != NULL)
do_monitor_cpu_rack(&processor_state[1]);
} else {
do_monitor_cpu_split(&processor_state[0]);
if (processor_state[1].monitor != NULL)
do_monitor_cpu_split(&processor_state[1]);
}
do_monitor_backside(&backside_state);
if (rackmac)
do_monitor_slots(&slots_state);
else
do_monitor_drives(&drives_state);
mutex_unlock(&driver_lock);
if (critical_state == 1) {
printk(KERN_WARNING "Temperature control detected a critical condition\n");
printk(KERN_WARNING "Attempting to shut down...\n");
if (call_critical_overtemp()) {
printk(KERN_WARNING "Can't call %s, power off now!\n",
critical_overtemp_path);
machine_power_off();
}
}
if (critical_state > 0)
critical_state++;
if (critical_state > MAX_CRITICAL_STATE) {
printk(KERN_WARNING "Shutdown timed out, power off now !\n");
machine_power_off();
}
elapsed = jiffies - start;
if (elapsed < HZ)
schedule_timeout_interruptible(HZ - elapsed);
}
out:
DBG("main_control_loop ended\n");
ctrl_task = 0;
complete_and_exit(&ctrl_complete, 0);
}
static void dispose_control_loops(void)
{
dispose_processor_state(&processor_state[0]);
dispose_processor_state(&processor_state[1]);
dispose_backside_state(&backside_state);
dispose_drives_state(&drives_state);
dispose_slots_state(&slots_state);
dispose_dimms_state(&dimms_state);
}
static int create_control_loops(void)
{
struct device_node *np;
cpu_count = 0;
for (np = NULL; NULL != (np = of_find_node_by_type(np, "cpu"));)
cpu_count++;
DBG("counted %d CPUs in the device-tree\n", cpu_count);
if (rackmac)
cpu_pid_type = CPU_PID_TYPE_RACKMAC;
else if (of_machine_is_compatible("PowerMac7,3")
&& (cpu_count > 1)
&& fcu_fans[CPUA_PUMP_RPM_INDEX].id != FCU_FAN_ABSENT_ID
&& fcu_fans[CPUB_PUMP_RPM_INDEX].id != FCU_FAN_ABSENT_ID) {
printk(KERN_INFO "Liquid cooling pumps detected, using new algorithm !\n");
cpu_pid_type = CPU_PID_TYPE_COMBINED;
} else
cpu_pid_type = CPU_PID_TYPE_SPLIT;
if (init_processor_state(&processor_state[0], 0))
goto fail;
if (cpu_pid_type == CPU_PID_TYPE_COMBINED)
fetch_cpu_pumps_minmax();
if (cpu_count > 1 && init_processor_state(&processor_state[1], 1))
goto fail;
if (init_backside_state(&backside_state))
goto fail;
if (rackmac && init_dimms_state(&dimms_state))
goto fail;
if (rackmac && init_slots_state(&slots_state))
goto fail;
if (!rackmac && init_drives_state(&drives_state))
goto fail;
DBG("all control loops up !\n");
return 0;
fail:
DBG("failure creating control loops, disposing\n");
dispose_control_loops();
return -ENODEV;
}
static void start_control_loops(void)
{
init_completion(&ctrl_complete);
ctrl_task = kthread_run(main_control_loop, NULL, "kfand");
}
static void stop_control_loops(void)
{
if (ctrl_task)
wait_for_completion(&ctrl_complete);
}
static int attach_fcu(void)
{
fcu = attach_i2c_chip(FAN_CTRLER_ID, "fcu");
if (fcu == NULL)
return -ENODEV;
DBG("FCU attached\n");
return 0;
}
static void detach_fcu(void)
{
fcu = NULL;
}
static int therm_pm72_attach(struct i2c_adapter *adapter)
{
mutex_lock(&driver_lock);
if (state == state_detached)
state = state_attaching;
if (state != state_attaching) {
mutex_unlock(&driver_lock);
return 0;
}
if (u3_0 == NULL && !strcmp(adapter->name, "u3 0")) {
u3_0 = adapter;
DBG("found U3-0\n");
if (k2 || !rackmac)
if (create_control_loops())
u3_0 = NULL;
} else if (u3_1 == NULL && !strcmp(adapter->name, "u3 1")) {
u3_1 = adapter;
DBG("found U3-1, attaching FCU\n");
if (attach_fcu())
u3_1 = NULL;
} else if (k2 == NULL && !strcmp(adapter->name, "mac-io 0")) {
k2 = adapter;
DBG("Found K2\n");
if (u3_0 && rackmac)
if (create_control_loops())
k2 = NULL;
}
if (u3_0 != NULL && u3_1 != NULL && (k2 || !rackmac)) {
DBG("everything up, starting control loops\n");
state = state_attached;
start_control_loops();
}
mutex_unlock(&driver_lock);
return 0;
}
static int therm_pm72_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
return 0;
}
static int therm_pm72_remove(struct i2c_client *client)
{
struct i2c_adapter *adapter = client->adapter;
mutex_lock(&driver_lock);
if (state != state_detached)
state = state_detaching;
DBG("stopping control loops\n");
mutex_unlock(&driver_lock);
stop_control_loops();
mutex_lock(&driver_lock);
if (u3_0 != NULL && !strcmp(adapter->name, "u3 0")) {
DBG("lost U3-0, disposing control loops\n");
dispose_control_loops();
u3_0 = NULL;
}
if (u3_1 != NULL && !strcmp(adapter->name, "u3 1")) {
DBG("lost U3-1, detaching FCU\n");
detach_fcu();
u3_1 = NULL;
}
if (u3_0 == NULL && u3_1 == NULL)
state = state_detached;
mutex_unlock(&driver_lock);
return 0;
}
static int fan_check_loc_match(const char *loc, int fan)
{
char tmp[64];
char *c, *e;
strlcpy(tmp, fcu_fans[fan].loc, 64);
c = tmp;
for (;;) {
e = strchr(c, ',');
if (e)
*e = 0;
if (strcmp(loc, c) == 0)
return 1;
if (e == NULL)
break;
c = e + 1;
}
return 0;
}
static void fcu_lookup_fans(struct device_node *fcu_node)
{
struct device_node *np = NULL;
int i;
DBG("Looking up FCU controls in device-tree...\n");
while ((np = of_get_next_child(fcu_node, np)) != NULL) {
int type = -1;
const char *loc;
const u32 *reg;
DBG(" control: %s, type: %s\n", np->name, np->type);
if (!strcmp(np->type, "fan-rpm-control") ||
!strcmp(np->type, "fan-rpm"))
type = FCU_FAN_RPM;
if (!strcmp(np->type, "fan-pwm-control") ||
!strcmp(np->type, "fan-pwm"))
type = FCU_FAN_PWM;
if (type == -1)
continue;
loc = of_get_property(np, "location", NULL);
reg = of_get_property(np, "reg", NULL);
if (loc == NULL || reg == NULL)
continue;
DBG(" matching location: %s, reg: 0x%08x\n", loc, *reg);
for (i = 0; i < FCU_FAN_COUNT; i++) {
int fan_id;
if (!fan_check_loc_match(loc, i))
continue;
DBG(" location match, index: %d\n", i);
fcu_fans[i].id = FCU_FAN_ABSENT_ID;
if (type != fcu_fans[i].type) {
printk(KERN_WARNING "therm_pm72: Fan type mismatch "
"in device-tree for %s\n", np->full_name);
break;
}
if (type == FCU_FAN_RPM)
fan_id = ((*reg) - 0x10) / 2;
else
fan_id = ((*reg) - 0x30) / 2;
if (fan_id > 7) {
printk(KERN_WARNING "therm_pm72: Can't parse "
"fan ID in device-tree for %s\n", np->full_name);
break;
}
DBG(" fan id -> %d, type -> %d\n", fan_id, type);
fcu_fans[i].id = fan_id;
}
}
printk(KERN_INFO "Detected fan controls:\n");
for (i = 0; i < FCU_FAN_COUNT; i++) {
if (fcu_fans[i].id == FCU_FAN_ABSENT_ID)
continue;
printk(KERN_INFO " %d: %s fan, id %d, location: %s\n", i,
fcu_fans[i].type == FCU_FAN_RPM ? "RPM" : "PWM",
fcu_fans[i].id, fcu_fans[i].loc);
}
}
static int fcu_of_probe(struct platform_device* dev)
{
state = state_detached;
of_dev = dev;
dev_info(&dev->dev, "PowerMac G5 Thermal control driver %s\n", VERSION);
fcu_lookup_fans(dev->dev.of_node);
return i2c_add_driver(&therm_pm72_driver);
}
static int fcu_of_remove(struct platform_device* dev)
{
i2c_del_driver(&therm_pm72_driver);
return 0;
}
static int __init therm_pm72_init(void)
{
rackmac = of_machine_is_compatible("RackMac3,1");
if (!of_machine_is_compatible("PowerMac7,2") &&
!of_machine_is_compatible("PowerMac7,3") &&
!rackmac)
return -ENODEV;
return platform_driver_register(&fcu_of_platform_driver);
}
static void __exit therm_pm72_exit(void)
{
platform_driver_unregister(&fcu_of_platform_driver);
}
