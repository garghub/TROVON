u8 inline jornada_ssp_reverse(u8 byte)
{
return
((0x80 & byte) >> 7) |
((0x40 & byte) >> 5) |
((0x20 & byte) >> 3) |
((0x10 & byte) >> 1) |
((0x08 & byte) << 1) |
((0x04 & byte) << 3) |
((0x02 & byte) << 5) |
((0x01 & byte) << 7);
}
int jornada_ssp_byte(u8 byte)
{
int timeout = 400000;
u16 ret;
while ((GPLR & GPIO_GPIO10)) {
if (!--timeout) {
printk(KERN_WARNING "SSP: timeout while waiting for transmit\n");
return -ETIMEDOUT;
}
cpu_relax();
}
ret = jornada_ssp_reverse(byte) << 8;
ssp_write_word(ret);
ssp_read_word(&ret);
return jornada_ssp_reverse(ret);
}
int jornada_ssp_inout(u8 byte)
{
int ret, i;
if (byte != TXDUMMY) {
ret = jornada_ssp_byte(byte);
if (ret != TXDUMMY) {
for (i = 0; i < 256; i++)
if (jornada_ssp_byte(TXDUMMY) == -1)
break;
return -ETIMEDOUT;
}
} else
ret = jornada_ssp_byte(TXDUMMY);
return ret;
}
void jornada_ssp_start(void)
{
spin_lock_irqsave(&jornada_ssp_lock, jornada_ssp_flags);
GPCR = GPIO_GPIO25;
udelay(50);
return;
}
void jornada_ssp_end(void)
{
GPSR = GPIO_GPIO25;
spin_unlock_irqrestore(&jornada_ssp_lock, jornada_ssp_flags);
return;
}
static int jornada_ssp_probe(struct platform_device *dev)
{
int ret;
GPSR = GPIO_GPIO25;
ret = ssp_init();
if (!ret) {
printk(KERN_INFO "SSP: device initialized with irq\n");
return ret;
}
printk(KERN_WARNING "SSP: initialization failed, trying non-irq solution \n");
Ser4MCCR0 = 0;
Ser4SSCR0 = 0x0387;
Ser4SSCR1 = 0x18;
ssp_flush();
jornada_ssp_start();
ret = jornada_ssp_inout(GETBRIGHTNESS);
if (ret == TXDUMMY)
jornada_ssp_inout(TXDUMMY);
jornada_ssp_end();
if (ret == -ETIMEDOUT) {
printk(KERN_WARNING "SSP: attempts failed, bailing\n");
ssp_exit();
return -ENODEV;
}
printk(KERN_INFO "SSP: device initialized\n");
return 0;
}
static int jornada_ssp_remove(struct platform_device *dev)
{
GPSR = GPIO_GPIO25;
ssp_exit();
return 0;
}
static int __init jornada_ssp_init(void)
{
return platform_driver_register(&jornadassp_driver);
}
