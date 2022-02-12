void olpc_xo1_pm_wakeup_set(u16 value)
{
wakeup_mask |= value;
}
void olpc_xo1_pm_wakeup_clear(u16 value)
{
wakeup_mask &= ~value;
}
static int xo1_power_state_enter(suspend_state_t pm_state)
{
unsigned long saved_sci_mask;
if (pm_state != PM_SUSPEND_MEM)
return -EINVAL;
saved_sci_mask = inl(acpi_base + CS5536_PM1_STS);
saved_sci_mask &= 0xffff0000;
do_olpc_suspend_lowlevel();
outl(saved_sci_mask, acpi_base + CS5536_PM1_STS);
return 0;
}
asmlinkage __visible int xo1_do_sleep(u8 sleep_state)
{
void *pgd_addr = __va(read_cr3());
outl(wakeup_mask << 16, acpi_base + CS5536_PM1_STS);
__asm__("movl %0,%%eax" : : "r" (pgd_addr));
__asm__("call *(%%edi); cld"
: : "D" (&ofw_bios_entry));
__asm__("movb $0x34, %al\n\t"
"outb %al, $0x70\n\t"
"movb $0x30, %al\n\t"
"outb %al, $0x71\n\t");
return 0;
}
static void xo1_power_off(void)
{
printk(KERN_INFO "OLPC XO-1 power off sequence...\n");
outl(0x40000000, pms_base + CS5536_PM_SCLK);
outl(0x40000000, pms_base + CS5536_PM_IN_SLPCTL);
outl(0x40000000, pms_base + CS5536_PM_WKXD);
outl(0x40000000, pms_base + CS5536_PM_WKD);
outl(0x0002ffff, pms_base + CS5536_PM_SSC);
outl(0xffffffff, acpi_base + CS5536_PM_GPE0_STS);
outl(0x00002000, acpi_base + CS5536_PM1_CNT);
}
static int xo1_power_state_valid(suspend_state_t pm_state)
{
return pm_state == PM_SUSPEND_MEM;
}
static int xo1_pm_probe(struct platform_device *pdev)
{
struct resource *res;
int err;
if (!machine_is_olpc())
return -ENODEV;
err = mfd_cell_enable(pdev);
if (err)
return err;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!res) {
dev_err(&pdev->dev, "can't fetch device resource info\n");
return -EIO;
}
if (strcmp(pdev->name, "cs5535-pms") == 0)
pms_base = res->start;
else if (strcmp(pdev->name, "olpc-xo1-pm-acpi") == 0)
acpi_base = res->start;
if (pms_base && acpi_base) {
suspend_set_ops(&xo1_suspend_ops);
pm_power_off = xo1_power_off;
printk(KERN_INFO "OLPC XO-1 support registered\n");
}
return 0;
}
static int xo1_pm_remove(struct platform_device *pdev)
{
mfd_cell_disable(pdev);
if (strcmp(pdev->name, "cs5535-pms") == 0)
pms_base = 0;
else if (strcmp(pdev->name, "olpc-xo1-pm-acpi") == 0)
acpi_base = 0;
pm_power_off = NULL;
return 0;
}
static int __init xo1_pm_init(void)
{
int r;
r = platform_driver_register(&cs5535_pms_driver);
if (r)
return r;
r = platform_driver_register(&cs5535_acpi_driver);
if (r)
platform_driver_unregister(&cs5535_pms_driver);
return r;
}
