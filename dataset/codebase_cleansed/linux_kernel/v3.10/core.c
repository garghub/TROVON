static void shark_restart(char mode, const char *cmd)
{
short temp;
outw(0x09,0x24);
temp=inw(0x26);
temp = temp | (1<<3) | (1<<10);
outw(0x09,0x24);
outw(temp,0x26);
}
static int __init shark_init(void)
{
int ret;
if (machine_is_shark())
{
ret = platform_device_register(&rtc_device);
if (ret) printk(KERN_ERR "Unable to register RTC device: %d\n", ret);
ret = platform_device_register(&serial_device);
if (ret) printk(KERN_ERR "Unable to register Serial device: %d\n", ret);
}
return 0;
}
static irqreturn_t
shark_timer_interrupt(int irq, void *dev_id)
{
timer_tick();
return IRQ_HANDLED;
}
static void __init shark_timer_init(void)
{
outb(0x34, 0x43);
outb(HZ_TIME & 0xff, 0x40);
outb(HZ_TIME >> 8, 0x40);
setup_irq(IRQ_TIMER, &shark_timer_irq);
}
static void shark_init_early(void)
{
cpu_idle_poll_ctrl(true);
}
