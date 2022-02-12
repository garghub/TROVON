static int __init mop500_uib_setup(char *str)
{
int i;
for (i = 0; i < ARRAY_SIZE(mop500_uibs); i++) {
struct uib *uib = &mop500_uibs[i];
if (!strcmp(str, uib->option)) {
mop500_uib = uib;
break;
}
}
if (i == ARRAY_SIZE(mop500_uibs))
pr_err("invalid uib= option (%s)\n", str);
return 1;
}
void mop500_uib_i2c_add(int busnum, struct i2c_board_info *info,
unsigned n)
{
struct i2c_adapter *adap;
struct i2c_client *client;
int i;
adap = i2c_get_adapter(busnum);
if (!adap) {
pr_err("failed to get adapter i2c%d\n", busnum);
return;
}
for (i = 0; i < n; i++) {
client = i2c_new_device(adap, &info[i]);
if (!client)
pr_err("failed to register %s to i2c%d\n",
info[i].type, busnum);
}
i2c_put_adapter(adap);
}
static void __init __mop500_uib_init(struct uib *uib, const char *why)
{
pr_info("%s (%s)\n", uib->name, why);
uib->init();
}
static int __init mop500_uib_init(void)
{
struct uib *uib = mop500_uib;
struct i2c_adapter *i2c0;
int ret;
if (!cpu_is_u8500())
return -ENODEV;
if (uib) {
__mop500_uib_init(uib, "from uib= boot argument");
return 0;
}
i2c0 = i2c_get_adapter(0);
if (!i2c0) {
__mop500_uib_init(&mop500_uibs[STUIB],
"fallback, could not get i2c0");
return -ENODEV;
}
ret = i2c_smbus_xfer(i2c0, 0x44, 0, I2C_SMBUS_WRITE, 0,
I2C_SMBUS_QUICK, NULL);
i2c_put_adapter(i2c0);
if (ret == 0)
uib = &mop500_uibs[U8500UIB];
else
uib = &mop500_uibs[STUIB];
__mop500_uib_init(uib, "detected");
return 0;
}
