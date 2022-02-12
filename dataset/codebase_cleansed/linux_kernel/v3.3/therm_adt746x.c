static int
write_reg(struct thermostat* th, int reg, u8 data)
{
u8 tmp[2];
int rc;
tmp[0] = reg;
tmp[1] = data;
rc = i2c_master_send(th->clt, (const char *)tmp, 2);
if (rc < 0)
return rc;
if (rc != 2)
return -ENODEV;
return 0;
}
static int
read_reg(struct thermostat* th, int reg)
{
u8 reg_addr, data;
int rc;
reg_addr = (u8)reg;
rc = i2c_master_send(th->clt, &reg_addr, 1);
if (rc < 0)
return rc;
if (rc != 1)
return -ENODEV;
rc = i2c_master_recv(th->clt, (char *)&data, 1);
if (rc < 0)
return rc;
return data;
}
static int
attach_thermostat(struct i2c_adapter *adapter)
{
unsigned long bus_no;
struct i2c_board_info info;
struct i2c_client *client;
if (strncmp(adapter->name, "uni-n", 5))
return -ENODEV;
bus_no = simple_strtoul(adapter->name + 6, NULL, 10);
if (bus_no != therm_bus)
return -ENODEV;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "therm_adt746x", I2C_NAME_SIZE);
info.addr = therm_address;
client = i2c_new_device(adapter, &info);
if (!client)
return -ENODEV;
list_add_tail(&client->detected, &thermostat_driver.clients);
return 0;
}
static int
remove_thermostat(struct i2c_client *client)
{
struct thermostat *th = i2c_get_clientdata(client);
int i;
thermostat_remove_files();
if (thread_therm != NULL) {
kthread_stop(thread_therm);
}
printk(KERN_INFO "adt746x: Putting max temperatures back from "
"%d, %d, %d to %d, %d, %d\n",
th->limits[0], th->limits[1], th->limits[2],
th->initial_limits[0], th->initial_limits[1],
th->initial_limits[2]);
for (i = 0; i < 3; i++)
write_reg(th, LIMIT_REG[i], th->initial_limits[i]);
write_both_fan_speed(th, -1);
thermostat = NULL;
kfree(th);
return 0;
}
static int read_fan_speed(struct thermostat *th, u8 addr)
{
u8 tmp[2];
u16 res;
tmp[1] = read_reg(th, addr);
tmp[0] = read_reg(th, addr + 1);
res = tmp[1] + (tmp[0] << 8);
return (res == 0xffff ? 0 : (90000*60)/res);
}
static void write_both_fan_speed(struct thermostat *th, int speed)
{
write_fan_speed(th, speed, 0);
if (therm_type == ADT7460)
write_fan_speed(th, speed, 1);
}
static void write_fan_speed(struct thermostat *th, int speed, int fan)
{
u8 manual;
if (speed > 0xff)
speed = 0xff;
else if (speed < -1)
speed = 0;
if (therm_type == ADT7467 && fan == 1)
return;
if (th->last_speed[fan] != speed) {
if (verbose) {
if (speed == -1)
printk(KERN_DEBUG "adt746x: Setting speed to automatic "
"for %s fan.\n", sensor_location[fan+1]);
else
printk(KERN_DEBUG "adt746x: Setting speed to %d "
"for %s fan.\n", speed, sensor_location[fan+1]);
}
} else
return;
if (speed >= 0) {
manual = read_reg(th, MANUAL_MODE[fan]);
manual &= ~INVERT_MASK;
write_reg(th, MANUAL_MODE[fan],
manual | MANUAL_MASK | th->pwm_inv[fan]);
write_reg(th, FAN_SPD_SET[fan], speed);
} else {
if(therm_type == ADT7460) {
manual = read_reg(th,
MANUAL_MODE[fan]) & (~MANUAL_MASK);
manual &= ~INVERT_MASK;
manual |= th->pwm_inv[fan];
write_reg(th,
MANUAL_MODE[fan], manual|REM_CONTROL[fan]);
} else {
manual = read_reg(th, MANUAL_MODE[fan]);
manual &= ~INVERT_MASK;
manual |= th->pwm_inv[fan];
write_reg(th, MANUAL_MODE[fan], manual&(~AUTO_MASK));
}
}
th->last_speed[fan] = speed;
}
static void read_sensors(struct thermostat *th)
{
int i = 0;
for (i = 0; i < 3; i++)
th->temps[i] = read_reg(th, TEMP_REG[i]);
}
static void display_stats(struct thermostat *th)
{
if (th->temps[0] != th->cached_temp[0]
|| th->temps[1] != th->cached_temp[1]
|| th->temps[2] != th->cached_temp[2]) {
printk(KERN_INFO "adt746x: Temperature infos:"
" thermostats: %d,%d,%d;"
" limits: %d,%d,%d;"
" fan speed: %d RPM\n",
th->temps[0], th->temps[1], th->temps[2],
th->limits[0], th->limits[1], th->limits[2],
read_fan_speed(th, FAN_SPEED[0]));
}
th->cached_temp[0] = th->temps[0];
th->cached_temp[1] = th->temps[1];
th->cached_temp[2] = th->temps[2];
}
static void update_fans_speed (struct thermostat *th)
{
int lastvar = 0;
int i = 0;
for (i = 1; i < 3; i++) {
int started = 0;
int fan_number = (therm_type == ADT7460 && i == 2);
int var = th->temps[i] - th->limits[i];
if (var > -1) {
int step = (255 - fan_speed) / 7;
int new_speed = 0;
if (abs(var - th->last_var[fan_number]) < 2)
continue;
started = 1;
new_speed = fan_speed + ((var-1)*step);
if (new_speed < fan_speed)
new_speed = fan_speed;
if (new_speed > 255)
new_speed = 255;
if (verbose)
printk(KERN_DEBUG "adt746x: Setting fans speed to %d "
"(limit exceeded by %d on %s)\n",
new_speed, var,
sensor_location[fan_number+1]);
write_both_fan_speed(th, new_speed);
th->last_var[fan_number] = var;
} else if (var < -2) {
if (i == 2 && lastvar < -1) {
if (th->last_speed[fan_number] != 0)
if (verbose)
printk(KERN_DEBUG "adt746x: Stopping "
"fans.\n");
write_both_fan_speed(th, 0);
}
}
lastvar = var;
if (started)
return;
}
}
static int monitor_task(void *arg)
{
struct thermostat* th = arg;
set_freezable();
while(!kthread_should_stop()) {
try_to_freeze();
msleep_interruptible(2000);
#ifndef DEBUG
if (fan_speed != -1)
read_sensors(th);
#else
read_sensors(th);
#endif
if (fan_speed != -1)
update_fans_speed(th);
#ifdef DEBUG
display_stats(th);
#endif
}
return 0;
}
static void set_limit(struct thermostat *th, int i)
{
th->limits[i] = default_limits_chip[i] + limit_adjust;
write_reg(th, LIMIT_REG[i], th->limits[i]);
th->limits[i] = default_limits_local[i] + limit_adjust;
}
static int probe_thermostat(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct thermostat* th;
int rc;
int i;
if (thermostat)
return 0;
th = kzalloc(sizeof(struct thermostat), GFP_KERNEL);
if (!th)
return -ENOMEM;
i2c_set_clientdata(client, th);
th->clt = client;
rc = read_reg(th, CONFIG_REG);
if (rc < 0) {
dev_err(&client->dev, "Thermostat failed to read config!\n");
kfree(th);
return -ENODEV;
}
if (fan_speed == -1)
fan_speed = 64;
if(therm_type == ADT7460) {
printk(KERN_INFO "adt746x: ADT7460 initializing\n");
write_reg(th, CONFIG_REG, 1);
} else
printk(KERN_INFO "adt746x: ADT7467 initializing\n");
for (i = 0; i < 3; i++) {
th->initial_limits[i] = read_reg(th, LIMIT_REG[i]);
set_limit(th, i);
}
printk(KERN_INFO "adt746x: Lowering max temperatures from %d, %d, %d"
" to %d, %d, %d\n",
th->initial_limits[0], th->initial_limits[1],
th->initial_limits[2], th->limits[0], th->limits[1],
th->limits[2]);
thermostat = th;
th->pwm_inv[0] = read_reg(th, MANUAL_MODE[0]) & INVERT_MASK;
th->pwm_inv[1] = read_reg(th, MANUAL_MODE[1]) & INVERT_MASK;
th->last_speed[0] = -2;
th->last_speed[1] = -2;
th->last_var[0] = -80;
th->last_var[1] = -80;
if (fan_speed != -1) {
write_both_fan_speed(th, 0);
} else {
write_both_fan_speed(th, -1);
}
thread_therm = kthread_run(monitor_task, th, "kfand");
if (thread_therm == ERR_PTR(-ENOMEM)) {
printk(KERN_INFO "adt746x: Kthread creation failed\n");
thread_therm = NULL;
return -ENOMEM;
}
thermostat_create_files();
return 0;
}
static int __init
thermostat_init(void)
{
struct device_node* np;
const u32 *prop;
int i = 0, offset = 0;
np = of_find_node_by_name(NULL, "fan");
if (!np)
return -ENODEV;
if (of_device_is_compatible(np, "adt7460"))
therm_type = ADT7460;
else if (of_device_is_compatible(np, "adt7467"))
therm_type = ADT7467;
else {
of_node_put(np);
return -ENODEV;
}
prop = of_get_property(np, "hwsensor-params-version", NULL);
printk(KERN_INFO "adt746x: version %d (%ssupported)\n", *prop,
(*prop == 1)?"":"un");
if (*prop != 1) {
of_node_put(np);
return -ENODEV;
}
prop = of_get_property(np, "reg", NULL);
if (!prop) {
of_node_put(np);
return -ENODEV;
}
if (strstr(np->full_name, "/i2c-bus@") != NULL) {
const char *tmp_bus = (strstr(np->full_name, "/i2c-bus@") + 9);
therm_bus = tmp_bus[0]-'0';
} else {
therm_bus = ((*prop) >> 8) & 0x0f;
}
therm_address = ((*prop) & 0xff) >> 1;
printk(KERN_INFO "adt746x: Thermostat bus: %d, address: 0x%02x, "
"limit_adjust: %d, fan_speed: %d\n",
therm_bus, therm_address, limit_adjust, fan_speed);
if (of_get_property(np, "hwsensor-location", NULL)) {
for (i = 0; i < 3; i++) {
sensor_location[i] = of_get_property(np,
"hwsensor-location", NULL) + offset;
if (sensor_location[i] == NULL)
sensor_location[i] = "";
printk(KERN_INFO "sensor %d: %s\n", i, sensor_location[i]);
offset += strlen(sensor_location[i]) + 1;
}
} else {
sensor_location[0] = "?";
sensor_location[1] = "?";
sensor_location[2] = "?";
}
of_dev = of_platform_device_create(np, "temperatures", NULL);
of_node_put(np);
if (of_dev == NULL) {
printk(KERN_ERR "Can't register temperatures device !\n");
return -ENODEV;
}
#ifndef CONFIG_I2C_POWERMAC
request_module("i2c-powermac");
#endif
return i2c_add_driver(&thermostat_driver);
}
static void thermostat_create_files(void)
{
int err;
err = device_create_file(&of_dev->dev, &dev_attr_sensor1_temperature);
err |= device_create_file(&of_dev->dev, &dev_attr_sensor2_temperature);
err |= device_create_file(&of_dev->dev, &dev_attr_sensor1_limit);
err |= device_create_file(&of_dev->dev, &dev_attr_sensor2_limit);
err |= device_create_file(&of_dev->dev, &dev_attr_sensor1_location);
err |= device_create_file(&of_dev->dev, &dev_attr_sensor2_location);
err |= device_create_file(&of_dev->dev, &dev_attr_limit_adjust);
err |= device_create_file(&of_dev->dev, &dev_attr_specified_fan_speed);
err |= device_create_file(&of_dev->dev, &dev_attr_sensor1_fan_speed);
if(therm_type == ADT7460)
err |= device_create_file(&of_dev->dev, &dev_attr_sensor2_fan_speed);
if (err)
printk(KERN_WARNING
"Failed to create temperature attribute file(s).\n");
}
static void thermostat_remove_files(void)
{
if (of_dev) {
device_remove_file(&of_dev->dev, &dev_attr_sensor1_temperature);
device_remove_file(&of_dev->dev, &dev_attr_sensor2_temperature);
device_remove_file(&of_dev->dev, &dev_attr_sensor1_limit);
device_remove_file(&of_dev->dev, &dev_attr_sensor2_limit);
device_remove_file(&of_dev->dev, &dev_attr_sensor1_location);
device_remove_file(&of_dev->dev, &dev_attr_sensor2_location);
device_remove_file(&of_dev->dev, &dev_attr_limit_adjust);
device_remove_file(&of_dev->dev, &dev_attr_specified_fan_speed);
device_remove_file(&of_dev->dev, &dev_attr_sensor1_fan_speed);
if(therm_type == ADT7460)
device_remove_file(&of_dev->dev,
&dev_attr_sensor2_fan_speed);
}
}
static void __exit
thermostat_exit(void)
{
i2c_del_driver(&thermostat_driver);
of_device_unregister(of_dev);
}
