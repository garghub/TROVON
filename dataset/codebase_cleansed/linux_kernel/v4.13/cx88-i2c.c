static void cx8800_bit_setscl(void *data, int state)
{
struct cx88_core *core = data;
if (state)
core->i2c_state |= 0x02;
else
core->i2c_state &= ~0x02;
cx_write(MO_I2C, core->i2c_state);
cx_read(MO_I2C);
}
static void cx8800_bit_setsda(void *data, int state)
{
struct cx88_core *core = data;
if (state)
core->i2c_state |= 0x01;
else
core->i2c_state &= ~0x01;
cx_write(MO_I2C, core->i2c_state);
cx_read(MO_I2C);
}
static int cx8800_bit_getscl(void *data)
{
struct cx88_core *core = data;
u32 state;
state = cx_read(MO_I2C);
return state & 0x02 ? 1 : 0;
}
static int cx8800_bit_getsda(void *data)
{
struct cx88_core *core = data;
u32 state;
state = cx_read(MO_I2C);
return state & 0x01;
}
static void do_i2c_scan(const char *name, struct i2c_client *c)
{
unsigned char buf;
int i, rc;
for (i = 0; i < ARRAY_SIZE(i2c_devs); i++) {
c->addr = i;
rc = i2c_master_recv(c, &buf, 0);
if (rc < 0)
continue;
pr_info("i2c scan: found device @ 0x%x [%s]\n",
i << 1, i2c_devs[i] ? i2c_devs[i] : "???");
}
}
int cx88_i2c_init(struct cx88_core *core, struct pci_dev *pci)
{
if (i2c_udelay < 5)
i2c_udelay = 5;
core->i2c_algo = cx8800_i2c_algo_template;
core->i2c_adap.dev.parent = &pci->dev;
strlcpy(core->i2c_adap.name, core->name, sizeof(core->i2c_adap.name));
core->i2c_adap.owner = THIS_MODULE;
core->i2c_algo.udelay = i2c_udelay;
core->i2c_algo.data = core;
i2c_set_adapdata(&core->i2c_adap, &core->v4l2_dev);
core->i2c_adap.algo_data = &core->i2c_algo;
core->i2c_client.adapter = &core->i2c_adap;
strlcpy(core->i2c_client.name, "cx88xx internal", I2C_NAME_SIZE);
cx8800_bit_setscl(core, 1);
cx8800_bit_setsda(core, 1);
core->i2c_rc = i2c_bit_add_bus(&core->i2c_adap);
if (core->i2c_rc == 0) {
static u8 tuner_data[] = {
0x0b, 0xdc, 0x86, 0x52 };
static struct i2c_msg tuner_msg = {
.flags = 0,
.addr = 0xc2 >> 1,
.buf = tuner_data,
.len = 4
};
dprintk(1, "i2c register ok\n");
switch (core->boardnr) {
case CX88_BOARD_HAUPPAUGE_HVR1300:
case CX88_BOARD_HAUPPAUGE_HVR3000:
case CX88_BOARD_HAUPPAUGE_HVR4000:
pr_info("i2c init: enabling analog demod on HVR1300/3000/4000 tuner\n");
i2c_transfer(core->i2c_client.adapter, &tuner_msg, 1);
break;
default:
break;
}
if (i2c_scan)
do_i2c_scan(core->name, &core->i2c_client);
} else
pr_err("i2c register FAILED\n");
return core->i2c_rc;
}
