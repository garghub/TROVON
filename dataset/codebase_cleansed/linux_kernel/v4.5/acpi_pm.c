static inline u32 read_pmtmr(void)
{
return inl(pmtmr_ioport) & ACPI_PM_MASK;
}
u32 acpi_pm_read_verified(void)
{
u32 v1 = 0, v2 = 0, v3 = 0;
do {
v1 = read_pmtmr();
v2 = read_pmtmr();
v3 = read_pmtmr();
} while (unlikely((v1 > v2 && v1 < v3) || (v2 > v3 && v2 < v1)
|| (v3 > v1 && v3 < v2)));
return v2;
}
static cycle_t acpi_pm_read(struct clocksource *cs)
{
return (cycle_t)read_pmtmr();
}
static int __init acpi_pm_good_setup(char *__str)
{
acpi_pm_good = 1;
return 1;
}
static cycle_t acpi_pm_read_slow(struct clocksource *cs)
{
return (cycle_t)acpi_pm_read_verified();
}
static inline void acpi_pm_need_workaround(void)
{
clocksource_acpi_pm.read = acpi_pm_read_slow;
clocksource_acpi_pm.rating = 120;
}
static void acpi_pm_check_blacklist(struct pci_dev *dev)
{
if (acpi_pm_good)
return;
if (dev->revision < 3) {
pr_warn("* Found PM-Timer Bug on the chipset. Due to workarounds for a bug,\n"
"* this clock source is slow. Consider trying other clock sources\n");
acpi_pm_need_workaround();
}
}
static void acpi_pm_check_graylist(struct pci_dev *dev)
{
if (acpi_pm_good)
return;
pr_warn("* The chipset may have PM-Timer Bug. Due to workarounds for a bug,\n"
"* this clock source is slow. If you are sure your timer does not have\n"
"* this bug, please use \"acpi_pm_good\" to disable the workaround\n");
acpi_pm_need_workaround();
}
static int verify_pmtmr_rate(void)
{
cycle_t value1, value2;
unsigned long count, delta;
mach_prepare_counter();
value1 = clocksource_acpi_pm.read(&clocksource_acpi_pm);
mach_countup(&count);
value2 = clocksource_acpi_pm.read(&clocksource_acpi_pm);
delta = (value2 - value1) & ACPI_PM_MASK;
if (delta < (PMTMR_EXPECTED_RATE * 19) / 20 ||
delta > (PMTMR_EXPECTED_RATE * 21) / 20) {
pr_info("PM-Timer running at invalid rate: %lu%% of normal - aborting.\n",
100UL * delta / PMTMR_EXPECTED_RATE);
return -1;
}
return 0;
}
static int __init init_acpi_pm_clocksource(void)
{
cycle_t value1, value2;
unsigned int i, j = 0;
if (!pmtmr_ioport)
return -ENODEV;
for (j = 0; j < ACPI_PM_MONOTONICITY_CHECKS; j++) {
udelay(100 * j);
value1 = clocksource_acpi_pm.read(&clocksource_acpi_pm);
for (i = 0; i < ACPI_PM_READ_CHECKS; i++) {
value2 = clocksource_acpi_pm.read(&clocksource_acpi_pm);
if (value2 == value1)
continue;
if (value2 > value1)
break;
if ((value2 < value1) && ((value2) < 0xFFF))
break;
pr_info("PM-Timer had inconsistent results: %#llx, %#llx - aborting.\n",
value1, value2);
pmtmr_ioport = 0;
return -EINVAL;
}
if (i == ACPI_PM_READ_CHECKS) {
pr_info("PM-Timer failed consistency check (%#llx) - aborting.\n",
value1);
pmtmr_ioport = 0;
return -ENODEV;
}
}
if (verify_pmtmr_rate() != 0){
pmtmr_ioport = 0;
return -ENODEV;
}
return clocksource_register_hz(&clocksource_acpi_pm,
PMTMR_TICKS_PER_SEC);
}
static int __init parse_pmtmr(char *arg)
{
unsigned int base;
int ret;
ret = kstrtouint(arg, 16, &base);
if (ret)
return ret;
pr_info("PMTMR IOPort override: 0x%04x -> 0x%04x\n", pmtmr_ioport,
base);
pmtmr_ioport = base;
return 1;
}
