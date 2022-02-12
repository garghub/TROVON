static void vp3054_bit_setscl(void *data, int state)
{
struct cx8802_dev *dev = data;
struct cx88_core *core = dev->core;
struct vp3054_i2c_state *vp3054_i2c = dev->vp3054;
if (state) {
vp3054_i2c->state |= 0x0001;
vp3054_i2c->state &= ~0x0100;
} else {
vp3054_i2c->state &= ~0x0001;
vp3054_i2c->state |= 0x0100;
}
cx_write(MO_GP0_IO, 0x010000 | vp3054_i2c->state);
cx_read(MO_GP0_IO);
}
static void vp3054_bit_setsda(void *data, int state)
{
struct cx8802_dev *dev = data;
struct cx88_core *core = dev->core;
struct vp3054_i2c_state *vp3054_i2c = dev->vp3054;
if (state) {
vp3054_i2c->state |= 0x0002;
vp3054_i2c->state &= ~0x0200;
} else {
vp3054_i2c->state &= ~0x0002;
vp3054_i2c->state |= 0x0200;
}
cx_write(MO_GP0_IO, 0x020000 | vp3054_i2c->state);
cx_read(MO_GP0_IO);
}
static int vp3054_bit_getscl(void *data)
{
struct cx8802_dev *dev = data;
struct cx88_core *core = dev->core;
u32 state;
state = cx_read(MO_GP0_IO);
return (state & 0x01) ? 1 : 0;
}
static int vp3054_bit_getsda(void *data)
{
struct cx8802_dev *dev = data;
struct cx88_core *core = dev->core;
u32 state;
state = cx_read(MO_GP0_IO);
return (state & 0x02) ? 1 : 0;
}
int vp3054_i2c_probe(struct cx8802_dev *dev)
{
struct cx88_core *core = dev->core;
struct vp3054_i2c_state *vp3054_i2c;
int rc;
if (core->boardnr != CX88_BOARD_DNTV_LIVE_DVB_T_PRO)
return 0;
vp3054_i2c = kzalloc(sizeof(*vp3054_i2c), GFP_KERNEL);
if (!vp3054_i2c)
return -ENOMEM;
dev->vp3054 = vp3054_i2c;
vp3054_i2c->algo = vp3054_i2c_algo_template;
vp3054_i2c->adap.dev.parent = &dev->pci->dev;
strlcpy(vp3054_i2c->adap.name, core->name,
sizeof(vp3054_i2c->adap.name));
vp3054_i2c->adap.owner = THIS_MODULE;
vp3054_i2c->algo.data = dev;
i2c_set_adapdata(&vp3054_i2c->adap, dev);
vp3054_i2c->adap.algo_data = &vp3054_i2c->algo;
vp3054_bit_setscl(dev, 1);
vp3054_bit_setsda(dev, 1);
rc = i2c_bit_add_bus(&vp3054_i2c->adap);
if (rc != 0) {
pr_err("vp3054_i2c register FAILED\n");
kfree(dev->vp3054);
dev->vp3054 = NULL;
}
return rc;
}
void vp3054_i2c_remove(struct cx8802_dev *dev)
{
struct vp3054_i2c_state *vp3054_i2c = dev->vp3054;
if (!vp3054_i2c ||
dev->core->boardnr != CX88_BOARD_DNTV_LIVE_DVB_T_PRO)
return;
i2c_del_adapter(&vp3054_i2c->adap);
kfree(vp3054_i2c);
}
