static void ioc_setscl(void *data, int state)
{
u_int ioc_control = ioc_readb(IOC_CONTROL) & ~(SCL | SDA);
u_int ones = force_ones;
if (state)
ones |= SCL;
else
ones &= ~SCL;
force_ones = ones;
ioc_writeb(ioc_control | ones, IOC_CONTROL);
}
static void ioc_setsda(void *data, int state)
{
u_int ioc_control = ioc_readb(IOC_CONTROL) & ~(SCL | SDA);
u_int ones = force_ones;
if (state)
ones |= SDA;
else
ones &= ~SDA;
force_ones = ones;
ioc_writeb(ioc_control | ones, IOC_CONTROL);
}
static int ioc_getscl(void *data)
{
return (ioc_readb(IOC_CONTROL) & SCL) != 0;
}
static int ioc_getsda(void *data)
{
return (ioc_readb(IOC_CONTROL) & SDA) != 0;
}
static int __init i2c_ioc_init(void)
{
force_ones = FORCE_ONES | SCL | SDA;
return i2c_bit_add_numbered_bus(&ioc_ops);
}
