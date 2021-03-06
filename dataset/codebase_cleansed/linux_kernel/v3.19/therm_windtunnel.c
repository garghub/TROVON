static void
print_temp( const char *s, int temp )
{
printk("%s%d.%d C", s ? s : "", temp>>8, (temp & 255)*10/256 );
}
static ssize_t
show_cpu_temperature( struct device *dev, struct device_attribute *attr, char *buf )
{
return sprintf(buf, "%d.%d\n", x.temp>>8, (x.temp & 255)*10/256 );
}
static ssize_t
show_case_temperature( struct device *dev, struct device_attribute *attr, char *buf )
{
return sprintf(buf, "%d.%d\n", x.casetemp>>8, (x.casetemp & 255)*10/256 );
}
static int
write_reg( struct i2c_client *cl, int reg, int data, int len )
{
u8 tmp[3];
if( len < 1 || len > 2 || data < 0 )
return -EINVAL;
tmp[0] = reg;
tmp[1] = (len == 1) ? data : (data >> 8);
tmp[2] = data;
len++;
if( i2c_master_send(cl, tmp, len) != len )
return -ENODEV;
return 0;
}
static int
read_reg( struct i2c_client *cl, int reg, int len )
{
u8 buf[2];
if( len != 1 && len != 2 )
return -EINVAL;
buf[0] = reg;
if( i2c_master_send(cl, buf, 1) != 1 )
return -ENODEV;
if( i2c_master_recv(cl, buf, len) != len )
return -ENODEV;
return (len == 2)? ((unsigned int)buf[0] << 8) | buf[1] : buf[0];
}
static void
tune_fan( int fan_setting )
{
int val = (fan_setting << 3) | 7;
write_reg( x.fan, 0x25, val, 1 );
write_reg( x.fan, 0x20, 0, 1 );
print_temp("CPU-temp: ", x.temp );
if( x.casetemp )
print_temp(", Case: ", x.casetemp );
printk(", Fan: %d (tuned %+d)\n", 11-fan_setting, x.fan_level-fan_setting );
x.fan_level = fan_setting;
}
static void
poll_temp( void )
{
int temp, i, level, casetemp;
temp = read_reg( x.thermostat, 0, 2 );
if( temp < 0 )
return;
casetemp = read_reg(x.fan, 0x0b, 1) << 8;
casetemp |= (read_reg(x.fan, 0x06, 1) & 0x7) << 5;
if( LOG_TEMP && x.temp != temp ) {
print_temp("CPU-temp: ", temp );
print_temp(", Case: ", casetemp );
printk(", Fan: %d\n", 11-x.fan_level );
}
x.temp = temp;
x.casetemp = casetemp;
level = -1;
for( i=0; (temp & 0xffff) > fan_table[i].temp ; i++ )
;
if( i < x.downind )
level = fan_table[i].fan_down_setting;
x.downind = i;
for( i=0; (temp & 0xffff) >= fan_table[i+1].temp ; i++ )
;
if( x.upind < i )
level = fan_table[i].fan_up_setting;
x.upind = i;
if( level >= 0 )
tune_fan( level );
}
static void
setup_hardware( void )
{
int val;
int err;
x.r0 = read_reg( x.fan, 0x00, 1 );
x.r1 = read_reg( x.fan, 0x01, 1 );
x.r20 = read_reg( x.fan, 0x20, 1 );
x.r23 = read_reg( x.fan, 0x23, 1 );
x.r25 = read_reg( x.fan, 0x25, 1 );
if( (val=read_reg(x.thermostat, 1, 1)) >= 0 ) {
val |= 0x60;
if( write_reg( x.thermostat, 1, val, 1 ) )
printk("Failed writing config register\n");
}
write_reg( x.fan, 0x01, 0x01, 1 );
write_reg( x.fan, 0x23, 0x91, 1 );
write_reg( x.fan, 0x00, 0x95, 1 );
if( x.overheat_temp == (80 << 8) ) {
x.overheat_temp = 75 << 8;
x.overheat_hyst = 70 << 8;
write_reg( x.thermostat, 2, x.overheat_hyst, 2 );
write_reg( x.thermostat, 3, x.overheat_temp, 2 );
print_temp("Reducing overheating limit to ", x.overheat_temp );
print_temp(" (Hyst: ", x.overheat_hyst );
printk(")\n");
}
x.downind = 0xffff;
x.upind = -1;
err = device_create_file( &x.of_dev->dev, &dev_attr_cpu_temperature );
err |= device_create_file( &x.of_dev->dev, &dev_attr_case_temperature );
if (err)
printk(KERN_WARNING
"Failed to create temperature attribute file(s).\n");
}
static void
restore_regs( void )
{
device_remove_file( &x.of_dev->dev, &dev_attr_cpu_temperature );
device_remove_file( &x.of_dev->dev, &dev_attr_case_temperature );
write_reg( x.fan, 0x01, x.r1, 1 );
write_reg( x.fan, 0x20, x.r20, 1 );
write_reg( x.fan, 0x23, x.r23, 1 );
write_reg( x.fan, 0x25, x.r25, 1 );
write_reg( x.fan, 0x00, x.r0, 1 );
}
static int control_loop(void *dummy)
{
mutex_lock(&x.lock);
setup_hardware();
mutex_unlock(&x.lock);
for (;;) {
msleep_interruptible(8000);
if (kthread_should_stop())
break;
mutex_lock(&x.lock);
poll_temp();
mutex_unlock(&x.lock);
}
mutex_lock(&x.lock);
restore_regs();
mutex_unlock(&x.lock);
return 0;
}
static int
do_attach( struct i2c_adapter *adapter )
{
static const unsigned short scan_ds1775[] = {
0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
I2C_CLIENT_END
};
static const unsigned short scan_adm1030[] = {
0x2c, 0x2d, 0x2e, 0x2f,
I2C_CLIENT_END
};
if( strncmp(adapter->name, "uni-n", 5) )
return 0;
if( !x.running ) {
struct i2c_board_info info;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "therm_ds1775", I2C_NAME_SIZE);
i2c_new_probed_device(adapter, &info, scan_ds1775, NULL);
strlcpy(info.type, "therm_adm1030", I2C_NAME_SIZE);
i2c_new_probed_device(adapter, &info, scan_adm1030, NULL);
if( x.thermostat && x.fan ) {
x.running = 1;
x.poll_task = kthread_run(control_loop, NULL, "g4fand");
}
}
return 0;
}
static int
do_remove(struct i2c_client *client)
{
if (x.running) {
x.running = 0;
kthread_stop(x.poll_task);
x.poll_task = NULL;
}
if (client == x.thermostat)
x.thermostat = NULL;
else if (client == x.fan)
x.fan = NULL;
else
printk(KERN_ERR "g4fan: bad client\n");
return 0;
}
static int
attach_fan( struct i2c_client *cl )
{
if( x.fan )
goto out;
if( read_reg(cl, 0x3d, 1) != 0x30 || read_reg(cl, 0x3e, 1) != 0x41 )
goto out;
printk("ADM1030 fan controller [@%02x]\n", cl->addr );
x.fan = cl;
out:
return 0;
}
static int
attach_thermostat( struct i2c_client *cl )
{
int hyst_temp, os_temp, temp;
if( x.thermostat )
goto out;
if( (temp=read_reg(cl, 0, 2)) < 0 )
goto out;
if( temp < 0x1600 || temp > 0x3c00 )
goto out;
hyst_temp = read_reg(cl, 2, 2);
os_temp = read_reg(cl, 3, 2);
if( hyst_temp < 0 || os_temp < 0 )
goto out;
printk("DS1775 digital thermometer [@%02x]\n", cl->addr );
print_temp("Temp: ", temp );
print_temp(" Hyst: ", hyst_temp );
print_temp(" OS: ", os_temp );
printk("\n");
x.temp = temp;
x.overheat_temp = os_temp;
x.overheat_hyst = hyst_temp;
x.thermostat = cl;
out:
return 0;
}
static int
do_probe(struct i2c_client *cl, const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = cl->adapter;
if( !i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA
| I2C_FUNC_SMBUS_WRITE_BYTE) )
return 0;
switch (id->driver_data) {
case adm1030:
return attach_fan( cl );
case ds1775:
return attach_thermostat(cl);
}
return 0;
}
static int therm_of_probe(struct platform_device *dev)
{
return i2c_add_driver( &g4fan_driver );
}
static int
therm_of_remove( struct platform_device *dev )
{
i2c_del_driver( &g4fan_driver );
return 0;
}
static int __init
g4fan_init( void )
{
const struct apple_thermal_info *info;
struct device_node *np;
mutex_init(&x.lock);
if( !(np=of_find_node_by_name(NULL, "power-mgt")) )
return -ENODEV;
info = of_get_property(np, "thermal-info", NULL);
of_node_put(np);
if( !info || !of_machine_is_compatible("PowerMac3,6") )
return -ENODEV;
if( info->id != 3 ) {
printk(KERN_ERR "therm_windtunnel: unsupported thermal design %d\n", info->id );
return -ENODEV;
}
if( !(np=of_find_node_by_name(NULL, "fan")) )
return -ENODEV;
x.of_dev = of_platform_device_create(np, "temperature", NULL);
of_node_put( np );
if( !x.of_dev ) {
printk(KERN_ERR "Can't register fan controller!\n");
return -ENODEV;
}
platform_driver_register( &therm_of_driver );
return 0;
}
static void __exit
g4fan_exit( void )
{
platform_driver_unregister( &therm_of_driver );
if( x.of_dev )
of_device_unregister( x.of_dev );
}
