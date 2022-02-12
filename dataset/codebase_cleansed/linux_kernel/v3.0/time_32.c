unsigned long profile_pc(struct pt_regs *regs)
{
extern char __copy_user_begin[], __copy_user_end[];
extern char __atomic_begin[], __atomic_end[];
extern char __bzero_begin[], __bzero_end[];
unsigned long pc = regs->pc;
if (in_lock_functions(pc) ||
(pc >= (unsigned long) __copy_user_begin &&
pc < (unsigned long) __copy_user_end) ||
(pc >= (unsigned long) __atomic_begin &&
pc < (unsigned long) __atomic_end) ||
(pc >= (unsigned long) __bzero_begin &&
pc < (unsigned long) __bzero_end))
pc = regs->u_regs[UREG_RETPC];
return pc;
}
int update_persistent_clock(struct timespec now)
{
return set_rtc_mmss(now.tv_sec);
}
static irqreturn_t timer_interrupt(int dummy, void *dev_id)
{
#ifndef CONFIG_SMP
profile_tick(CPU_PROFILING);
#endif
clear_clock_irq();
xtime_update(1);
#ifndef CONFIG_SMP
update_process_times(user_mode(get_irq_regs()));
#endif
return IRQ_HANDLED;
}
static unsigned char mostek_read_byte(struct device *dev, u32 ofs)
{
struct platform_device *pdev = to_platform_device(dev);
struct m48t59_plat_data *pdata = pdev->dev.platform_data;
return readb(pdata->ioaddr + ofs);
}
static void mostek_write_byte(struct device *dev, u32 ofs, u8 val)
{
struct platform_device *pdev = to_platform_device(dev);
struct m48t59_plat_data *pdata = pdev->dev.platform_data;
writeb(val, pdata->ioaddr + ofs);
}
static int __devinit clock_probe(struct platform_device *op)
{
struct device_node *dp = op->dev.of_node;
const char *model = of_get_property(dp, "model", NULL);
if (!model)
return -ENODEV;
if (!of_find_property(dp, "address", NULL))
return -ENODEV;
m48t59_rtc.resource = &op->resource[0];
if (!strcmp(model, "mk48t02")) {
m48t59_data.ioaddr = of_ioremap(&op->resource[0], 0,
2048, "rtc-m48t59");
m48t59_data.type = M48T59RTC_TYPE_M48T02;
} else if (!strcmp(model, "mk48t08")) {
m48t59_data.ioaddr = of_ioremap(&op->resource[0], 0,
8192, "rtc-m48t59");
m48t59_data.type = M48T59RTC_TYPE_M48T08;
} else
return -ENODEV;
if (platform_device_register(&m48t59_rtc) < 0)
printk(KERN_ERR "Registering RTC device failed\n");
return 0;
}
static int __init clock_init(void)
{
return platform_driver_register(&clock_driver);
}
u32 sbus_do_gettimeoffset(void)
{
unsigned long val = *master_l10_counter;
unsigned long usec = (val >> 10) & 0x1fffff;
if (val & 0x80000000)
usec += 1000000 / HZ;
return usec * 1000;
}
u32 arch_gettimeoffset(void)
{
if (unlikely(!do_arch_gettimeoffset))
return 0;
return do_arch_gettimeoffset();
}
static void __init sbus_time_init(void)
{
do_arch_gettimeoffset = sbus_do_gettimeoffset;
btfixup();
sparc_irq_config.init_timers(timer_interrupt);
}
void __init time_init(void)
{
if (pcic_present())
pci_time_init();
else
sbus_time_init();
}
static int set_rtc_mmss(unsigned long secs)
{
struct rtc_device *rtc = rtc_class_open("rtc0");
int err = -1;
if (rtc) {
err = rtc_set_mmss(rtc, secs);
rtc_class_close(rtc);
}
return err;
}
