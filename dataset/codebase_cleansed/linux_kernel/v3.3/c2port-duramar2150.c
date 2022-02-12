static void duramar2150_c2port_access(struct c2port_device *dev, int status)
{
u8 v;
mutex_lock(&update_lock);
v = inb(DIR_PORT);
if (status)
outb(v | (C2D | C2CK), DIR_PORT);
else
outb(v & ~(C2D | C2CK), DIR_PORT);
mutex_unlock(&update_lock);
}
static void duramar2150_c2port_c2d_dir(struct c2port_device *dev, int dir)
{
u8 v;
mutex_lock(&update_lock);
v = inb(DIR_PORT);
if (dir)
outb(v & ~C2D, DIR_PORT);
else
outb(v | C2D, DIR_PORT);
mutex_unlock(&update_lock);
}
static int duramar2150_c2port_c2d_get(struct c2port_device *dev)
{
return inb(DATA_PORT) & C2D;
}
static void duramar2150_c2port_c2d_set(struct c2port_device *dev, int status)
{
u8 v;
mutex_lock(&update_lock);
v = inb(DATA_PORT);
if (status)
outb(v | C2D, DATA_PORT);
else
outb(v & ~C2D, DATA_PORT);
mutex_unlock(&update_lock);
}
static void duramar2150_c2port_c2ck_set(struct c2port_device *dev, int status)
{
u8 v;
mutex_lock(&update_lock);
v = inb(DATA_PORT);
if (status)
outb(v | C2CK, DATA_PORT);
else
outb(v & ~C2CK, DATA_PORT);
mutex_unlock(&update_lock);
}
static int __init duramar2150_c2port_init(void)
{
struct resource *res;
int ret = 0;
res = request_region(0x325, 2, "c2port");
if (!res)
return -EBUSY;
duramar2150_c2port_dev = c2port_device_register("uc",
&duramar2150_c2port_ops, NULL);
if (!duramar2150_c2port_dev) {
ret = -ENODEV;
goto free_region;
}
return 0;
free_region:
release_region(0x325, 2);
return ret;
}
static void __exit duramar2150_c2port_exit(void)
{
duramar2150_c2port_access(duramar2150_c2port_dev, 0);
c2port_device_unregister(duramar2150_c2port_dev);
release_region(0x325, 2);
}
