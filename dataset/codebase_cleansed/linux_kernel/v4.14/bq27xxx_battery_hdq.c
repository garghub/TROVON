static int w1_bq27000_read(struct w1_slave *sl, unsigned int reg)
{
u8 val;
mutex_lock(&sl->master->bus_mutex);
w1_write_8(sl->master, HDQ_CMD_READ | reg);
val = w1_read_8(sl->master);
mutex_unlock(&sl->master->bus_mutex);
return val;
}
static int bq27xxx_battery_hdq_read(struct bq27xxx_device_info *di, u8 reg,
bool single)
{
struct w1_slave *sl = dev_to_w1_slave(di->dev);
unsigned int timeout = 3;
int upper, lower;
int temp;
if (!single) {
upper = w1_bq27000_read(sl, reg + 1);
do {
temp = upper;
if (upper < 0)
return upper;
lower = w1_bq27000_read(sl, reg);
if (lower < 0)
return lower;
upper = w1_bq27000_read(sl, reg + 1);
} while (temp != upper && --timeout);
if (timeout == 0)
return -EIO;
return (upper << 8) | lower;
}
return w1_bq27000_read(sl, reg);
}
static int bq27xxx_battery_hdq_add_slave(struct w1_slave *sl)
{
struct bq27xxx_device_info *di;
di = devm_kzalloc(&sl->dev, sizeof(*di), GFP_KERNEL);
if (!di)
return -ENOMEM;
dev_set_drvdata(&sl->dev, di);
di->dev = &sl->dev;
di->chip = BQ27000;
di->name = "bq27000-battery";
di->bus.read = bq27xxx_battery_hdq_read;
return bq27xxx_battery_setup(di);
}
static void bq27xxx_battery_hdq_remove_slave(struct w1_slave *sl)
{
struct bq27xxx_device_info *di = dev_get_drvdata(&sl->dev);
bq27xxx_battery_teardown(di);
}
static int __init bq27xxx_battery_hdq_init(void)
{
if (F_ID)
bq27xxx_battery_hdq_family.fid = F_ID;
return w1_register_family(&bq27xxx_battery_hdq_family);
}
static void __exit bq27xxx_battery_hdq_exit(void)
{
w1_unregister_family(&bq27xxx_battery_hdq_family);
}
