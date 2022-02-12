static void n411_set_ctl(struct hecubafb_par *par, unsigned char bit, unsigned
char state)
{
switch (bit) {
case HCB_CD_BIT:
if (state)
ctl &= ~(HCB_CD_BIT);
else
ctl |= HCB_CD_BIT;
break;
case HCB_DS_BIT:
if (state)
ctl &= ~(HCB_DS_BIT);
else
ctl |= HCB_DS_BIT;
break;
}
outb(ctl, cio_addr);
}
static unsigned char n411_get_ctl(struct hecubafb_par *par)
{
return inb(c2io_addr);
}
static void n411_set_data(struct hecubafb_par *par, unsigned char value)
{
outb(value, dio_addr);
}
static void n411_wait_for_ack(struct hecubafb_par *par, int clear)
{
int timeout;
unsigned char tmp;
timeout = 500;
do {
tmp = n411_get_ctl(par);
if ((tmp & HCB_ACK_BIT) && (!clear))
return;
else if (!(tmp & HCB_ACK_BIT) && (clear))
return;
udelay(1);
} while (timeout--);
printk(KERN_ERR "timed out waiting for ack\n");
}
static int n411_init_control(struct hecubafb_par *par)
{
unsigned char tmp;
ctl = HCB_WUP_BIT | HCB_RW_BIT | HCB_CD_BIT ;
n411_set_ctl(par, HCB_DS_BIT, 1);
tmp = n411_get_ctl(par);
if (tmp & HCB_ACK_BIT) {
printk(KERN_ERR "Fail because ACK is already low\n");
return -ENXIO;
}
return 0;
}
static int n411_init_board(struct hecubafb_par *par)
{
int retval;
retval = n411_init_control(par);
if (retval)
return retval;
par->send_command(par, APOLLO_INIT_DISPLAY);
par->send_data(par, 0x81);
udelay(1000);
if (!nosplash) {
par->send_command(par, APOLLO_ERASE_DISPLAY);
par->send_data(par, splashval);
}
return 0;
}
static int __init n411_init(void)
{
int ret;
if (!dio_addr || !cio_addr || !c2io_addr) {
printk(KERN_WARNING "no IO addresses supplied\n");
return -EINVAL;
}
request_module("hecubafb");
n411_device = platform_device_alloc("hecubafb", -1);
if (!n411_device)
return -ENOMEM;
ret = platform_device_add_data(n411_device, &n411_board,
sizeof(n411_board));
if (ret)
goto put_plat_device;
ret = platform_device_add(n411_device);
if (ret)
goto put_plat_device;
return 0;
put_plat_device:
platform_device_put(n411_device);
return ret;
}
static void __exit n411_exit(void)
{
platform_device_unregister(n411_device);
}
