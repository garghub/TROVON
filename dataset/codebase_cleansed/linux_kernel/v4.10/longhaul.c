static char *print_speed(int speed)
{
if (speed < 1000) {
snprintf(speedbuffer, sizeof(speedbuffer), "%dMHz", speed);
return speedbuffer;
}
if (speed%1000 == 0)
snprintf(speedbuffer, sizeof(speedbuffer),
"%dGHz", speed/1000);
else
snprintf(speedbuffer, sizeof(speedbuffer),
"%d.%dGHz", speed/1000, (speed%1000)/100);
return speedbuffer;
}
static unsigned int calc_speed(int mult)
{
int khz;
khz = (mult/10)*fsb;
if (mult%10)
khz += fsb/2;
khz *= 1000;
return khz;
}
static int longhaul_get_cpu_mult(void)
{
unsigned long invalue = 0, lo, hi;
rdmsr(MSR_IA32_EBL_CR_POWERON, lo, hi);
invalue = (lo & (1<<22|1<<23|1<<24|1<<25))>>22;
if (longhaul_version == TYPE_LONGHAUL_V2 ||
longhaul_version == TYPE_POWERSAVER) {
if (lo & (1<<27))
invalue += 16;
}
return eblcr[invalue];
}
static void do_longhaul1(unsigned int mults_index)
{
union msr_bcr2 bcr2;
rdmsrl(MSR_VIA_BCR2, bcr2.val);
bcr2.bits.ESOFTBF = 1;
bcr2.bits.CLOCKMUL = mults_index & 0xff;
safe_halt();
wrmsrl(MSR_VIA_BCR2, bcr2.val);
ACPI_FLUSH_CPU_CACHE();
halt();
local_irq_disable();
rdmsrl(MSR_VIA_BCR2, bcr2.val);
bcr2.bits.ESOFTBF = 0;
wrmsrl(MSR_VIA_BCR2, bcr2.val);
}
static void do_powersaver(int cx_address, unsigned int mults_index,
unsigned int dir)
{
union msr_longhaul longhaul;
u32 t;
rdmsrl(MSR_VIA_LONGHAUL, longhaul.val);
if (!revid_errata)
longhaul.bits.RevisionKey = longhaul.bits.RevisionID;
else
longhaul.bits.RevisionKey = 0;
longhaul.bits.SoftBusRatio = mults_index & 0xf;
longhaul.bits.SoftBusRatio4 = (mults_index & 0x10) >> 4;
if (can_scale_voltage)
longhaul.bits.SoftVID = (mults_index >> 8) & 0x1f;
safe_halt();
if (can_scale_voltage && dir) {
longhaul.bits.EnableSoftVID = 1;
wrmsrl(MSR_VIA_LONGHAUL, longhaul.val);
if (!cx_address) {
ACPI_FLUSH_CPU_CACHE();
halt();
} else {
ACPI_FLUSH_CPU_CACHE();
inb(cx_address);
t = inl(acpi_gbl_FADT.xpm_timer_block.address);
}
longhaul.bits.EnableSoftVID = 0;
wrmsrl(MSR_VIA_LONGHAUL, longhaul.val);
}
longhaul.bits.EnableSoftBusRatio = 1;
wrmsrl(MSR_VIA_LONGHAUL, longhaul.val);
if (!cx_address) {
ACPI_FLUSH_CPU_CACHE();
halt();
} else {
ACPI_FLUSH_CPU_CACHE();
inb(cx_address);
t = inl(acpi_gbl_FADT.xpm_timer_block.address);
}
longhaul.bits.EnableSoftBusRatio = 0;
wrmsrl(MSR_VIA_LONGHAUL, longhaul.val);
if (can_scale_voltage && !dir) {
longhaul.bits.EnableSoftVID = 1;
wrmsrl(MSR_VIA_LONGHAUL, longhaul.val);
if (!cx_address) {
ACPI_FLUSH_CPU_CACHE();
halt();
} else {
ACPI_FLUSH_CPU_CACHE();
inb(cx_address);
t = inl(acpi_gbl_FADT.xpm_timer_block.address);
}
longhaul.bits.EnableSoftVID = 0;
wrmsrl(MSR_VIA_LONGHAUL, longhaul.val);
}
}
static int longhaul_setstate(struct cpufreq_policy *policy,
unsigned int table_index)
{
unsigned int mults_index;
int speed, mult;
struct cpufreq_freqs freqs;
unsigned long flags;
unsigned int pic1_mask, pic2_mask;
u16 bm_status = 0;
u32 bm_timeout = 1000;
unsigned int dir = 0;
mults_index = longhaul_table[table_index].driver_data;
mult = mults[mults_index & 0x1f];
if (mult == -1)
return -EINVAL;
speed = calc_speed(mult);
if ((speed > highest_speed) || (speed < lowest_speed))
return -EINVAL;
if (can_scale_voltage && longhaul_index < table_index)
dir = 1;
freqs.old = calc_speed(longhaul_get_cpu_mult());
freqs.new = speed;
pr_debug("Setting to FSB:%dMHz Mult:%d.%dx (%s)\n",
fsb, mult/10, mult%10, print_speed(speed/1000));
retry_loop:
preempt_disable();
local_irq_save(flags);
pic2_mask = inb(0xA1);
pic1_mask = inb(0x21);
outb(0xFF, 0xA1);
outb(0xFE, 0x21);
if (acpi_regs_addr && (longhaul_flags & USE_NORTHBRIDGE
|| ((pr != NULL) && pr->flags.bm_control))) {
bm_status = inw(acpi_regs_addr);
bm_status &= 1 << 4;
while (bm_status && bm_timeout) {
outw(1 << 4, acpi_regs_addr);
bm_timeout--;
bm_status = inw(acpi_regs_addr);
bm_status &= 1 << 4;
}
}
if (longhaul_flags & USE_NORTHBRIDGE) {
outb(3, 0x22);
} else if ((pr != NULL) && pr->flags.bm_control) {
acpi_write_bit_register(ACPI_BITREG_ARB_DISABLE, 1);
}
switch (longhaul_version) {
case TYPE_LONGHAUL_V1:
do_longhaul1(mults_index);
break;
case TYPE_LONGHAUL_V2:
case TYPE_POWERSAVER:
if (longhaul_flags & USE_ACPI_C3) {
acpi_write_bit_register(ACPI_BITREG_BUS_MASTER_RLD, 0);
do_powersaver(cx->address, mults_index, dir);
} else {
do_powersaver(0, mults_index, dir);
}
break;
}
if (longhaul_flags & USE_NORTHBRIDGE) {
outb(0, 0x22);
} else if ((pr != NULL) && pr->flags.bm_control) {
acpi_write_bit_register(ACPI_BITREG_ARB_DISABLE, 0);
}
outb(pic2_mask, 0xA1);
outb(pic1_mask, 0x21);
local_irq_restore(flags);
preempt_enable();
freqs.new = calc_speed(longhaul_get_cpu_mult());
if (unlikely(freqs.new != speed)) {
pr_info("Failed to set requested frequency!\n");
if (!revid_errata) {
pr_info("Enabling \"Ignore Revision ID\" option\n");
revid_errata = 1;
msleep(200);
goto retry_loop;
}
if (longhaul_flags & USE_ACPI_C3) {
pr_info("Disabling ACPI C3 support\n");
longhaul_flags &= ~USE_ACPI_C3;
if (revid_errata) {
pr_info("Disabling \"Ignore Revision ID\" option\n");
revid_errata = 0;
}
msleep(200);
goto retry_loop;
}
if (longhaul_version == TYPE_LONGHAUL_V2) {
pr_info("Switching to Longhaul ver. 1\n");
longhaul_version = TYPE_LONGHAUL_V1;
msleep(200);
goto retry_loop;
}
}
if (!bm_timeout) {
pr_info("Warning: Timeout while waiting for idle PCI bus\n");
return -EBUSY;
}
return 0;
}
static int guess_fsb(int mult)
{
int speed = cpu_khz / 1000;
int i;
int speeds[] = { 666, 1000, 1333, 2000 };
int f_max, f_min;
for (i = 0; i < 4; i++) {
f_max = ((speeds[i] * mult) + 50) / 100;
f_max += (ROUNDING / 2);
f_min = f_max - ROUNDING;
if ((speed <= f_max) && (speed >= f_min))
return speeds[i] / 10;
}
return 0;
}
static int longhaul_get_ranges(void)
{
unsigned int i, j, k = 0;
unsigned int ratio;
int mult;
mult = longhaul_get_cpu_mult();
if (mult == -1) {
pr_info("Invalid (reserved) multiplier!\n");
return -EINVAL;
}
fsb = guess_fsb(mult);
if (fsb == 0) {
pr_info("Invalid (reserved) FSB!\n");
return -EINVAL;
}
maxmult = mult;
switch (cpu_model) {
case CPU_NEHEMIAH:
minmult = 50;
break;
case CPU_NEHEMIAH_C:
minmult = 40;
break;
default:
minmult = 30;
break;
}
pr_debug("MinMult:%d.%dx MaxMult:%d.%dx\n",
minmult/10, minmult%10, maxmult/10, maxmult%10);
highest_speed = calc_speed(maxmult);
lowest_speed = calc_speed(minmult);
pr_debug("FSB:%dMHz Lowest speed: %s Highest speed:%s\n", fsb,
print_speed(lowest_speed/1000),
print_speed(highest_speed/1000));
if (lowest_speed == highest_speed) {
pr_info("highestspeed == lowest, aborting\n");
return -EINVAL;
}
if (lowest_speed > highest_speed) {
pr_info("nonsense! lowest (%d > %d) !\n",
lowest_speed, highest_speed);
return -EINVAL;
}
longhaul_table = kzalloc((numscales + 1) * sizeof(*longhaul_table),
GFP_KERNEL);
if (!longhaul_table)
return -ENOMEM;
for (j = 0; j < numscales; j++) {
ratio = mults[j];
if (ratio == -1)
continue;
if (ratio > maxmult || ratio < minmult)
continue;
longhaul_table[k].frequency = calc_speed(ratio);
longhaul_table[k].driver_data = j;
k++;
}
if (k <= 1) {
kfree(longhaul_table);
return -ENODEV;
}
for (j = 0; j < k - 1; j++) {
unsigned int min_f, min_i;
min_f = longhaul_table[j].frequency;
min_i = j;
for (i = j + 1; i < k; i++) {
if (longhaul_table[i].frequency < min_f) {
min_f = longhaul_table[i].frequency;
min_i = i;
}
}
if (min_i != j) {
swap(longhaul_table[j].frequency,
longhaul_table[min_i].frequency);
swap(longhaul_table[j].driver_data,
longhaul_table[min_i].driver_data);
}
}
longhaul_table[k].frequency = CPUFREQ_TABLE_END;
for (j = 0; j < k; j++) {
if (mults[longhaul_table[j].driver_data & 0x1f] == mult) {
longhaul_index = j;
break;
}
}
return 0;
}
static void longhaul_setup_voltagescaling(void)
{
struct cpufreq_frequency_table *freq_pos;
union msr_longhaul longhaul;
struct mV_pos minvid, maxvid, vid;
unsigned int j, speed, pos, kHz_step, numvscales;
int min_vid_speed;
rdmsrl(MSR_VIA_LONGHAUL, longhaul.val);
if (!(longhaul.bits.RevisionID & 1)) {
pr_info("Voltage scaling not supported by CPU\n");
return;
}
if (!longhaul.bits.VRMRev) {
pr_info("VRM 8.5\n");
vrm_mV_table = &vrm85_mV[0];
mV_vrm_table = &mV_vrm85[0];
} else {
pr_info("Mobile VRM\n");
if (cpu_model < CPU_NEHEMIAH)
return;
vrm_mV_table = &mobilevrm_mV[0];
mV_vrm_table = &mV_mobilevrm[0];
}
minvid = vrm_mV_table[longhaul.bits.MinimumVID];
maxvid = vrm_mV_table[longhaul.bits.MaximumVID];
if (minvid.mV == 0 || maxvid.mV == 0 || minvid.mV > maxvid.mV) {
pr_info("Bogus values Min:%d.%03d Max:%d.%03d - Voltage scaling disabled\n",
minvid.mV/1000, minvid.mV%1000,
maxvid.mV/1000, maxvid.mV%1000);
return;
}
if (minvid.mV == maxvid.mV) {
pr_info("Claims to support voltage scaling but min & max are both %d.%03d - Voltage scaling disabled\n",
maxvid.mV/1000, maxvid.mV%1000);
return;
}
numvscales = maxvid.pos - minvid.pos + 1;
pr_info("Max VID=%d.%03d Min VID=%d.%03d, %d possible voltage scales\n",
maxvid.mV/1000, maxvid.mV%1000,
minvid.mV/1000, minvid.mV%1000,
numvscales);
j = longhaul.bits.MinMHzBR;
if (longhaul.bits.MinMHzBR4)
j += 16;
min_vid_speed = eblcr[j];
if (min_vid_speed == -1)
return;
switch (longhaul.bits.MinMHzFSB) {
case 0:
min_vid_speed *= 13333;
break;
case 1:
min_vid_speed *= 10000;
break;
case 3:
min_vid_speed *= 6666;
break;
default:
return;
break;
}
if (min_vid_speed >= highest_speed)
return;
kHz_step = (highest_speed - min_vid_speed) / numvscales;
cpufreq_for_each_entry(freq_pos, longhaul_table) {
speed = freq_pos->frequency;
if (speed > min_vid_speed)
pos = (speed - min_vid_speed) / kHz_step + minvid.pos;
else
pos = minvid.pos;
freq_pos->driver_data |= mV_vrm_table[pos] << 8;
vid = vrm_mV_table[mV_vrm_table[pos]];
pr_info("f: %d kHz, index: %d, vid: %d mV\n",
speed, (int)(freq_pos - longhaul_table), vid.mV);
}
can_scale_voltage = 1;
pr_info("Voltage scaling enabled\n");
}
static int longhaul_target(struct cpufreq_policy *policy,
unsigned int table_index)
{
unsigned int i;
unsigned int dir = 0;
u8 vid, current_vid;
int retval = 0;
if (!can_scale_voltage)
retval = longhaul_setstate(policy, table_index);
else {
i = longhaul_index;
current_vid = (longhaul_table[longhaul_index].driver_data >> 8);
current_vid &= 0x1f;
if (table_index > longhaul_index)
dir = 1;
while (i != table_index) {
vid = (longhaul_table[i].driver_data >> 8) & 0x1f;
if (vid != current_vid) {
retval = longhaul_setstate(policy, i);
current_vid = vid;
msleep(200);
}
if (dir)
i++;
else
i--;
}
retval = longhaul_setstate(policy, table_index);
}
longhaul_index = table_index;
return retval;
}
static unsigned int longhaul_get(unsigned int cpu)
{
if (cpu)
return 0;
return calc_speed(longhaul_get_cpu_mult());
}
static acpi_status longhaul_walk_callback(acpi_handle obj_handle,
u32 nesting_level,
void *context, void **return_value)
{
struct acpi_device *d;
if (acpi_bus_get_device(obj_handle, &d))
return 0;
*return_value = acpi_driver_data(d);
return 1;
}
static int enable_arbiter_disable(void)
{
struct pci_dev *dev;
int status = 1;
int reg;
u8 pci_cmd;
reg = 0x78;
dev = pci_get_device(PCI_VENDOR_ID_VIA, PCI_DEVICE_ID_VIA_8601_0,
NULL);
if (dev == NULL)
dev = pci_get_device(PCI_VENDOR_ID_VIA,
PCI_DEVICE_ID_VIA_8605_0, NULL);
if (dev == NULL) {
reg = 0x76;
dev = pci_get_device(PCI_VENDOR_ID_VIA,
PCI_DEVICE_ID_VIA_862X_0, NULL);
if (dev == NULL)
dev = pci_get_device(PCI_VENDOR_ID_VIA, 0x7259, NULL);
}
if (dev != NULL) {
pci_read_config_byte(dev, reg, &pci_cmd);
if (!(pci_cmd & 1<<7)) {
pci_cmd |= 1<<7;
pci_write_config_byte(dev, reg, pci_cmd);
pci_read_config_byte(dev, reg, &pci_cmd);
if (!(pci_cmd & 1<<7)) {
pr_err("Can't enable access to port 0x22\n");
status = 0;
}
}
pci_dev_put(dev);
return status;
}
return 0;
}
static int longhaul_setup_southbridge(void)
{
struct pci_dev *dev;
u8 pci_cmd;
dev = pci_get_device(PCI_VENDOR_ID_VIA, PCI_DEVICE_ID_VIA_8235, NULL);
if (dev == NULL)
dev = pci_get_device(PCI_VENDOR_ID_VIA,
PCI_DEVICE_ID_VIA_8237, NULL);
if (dev != NULL) {
pci_read_config_byte(dev, 0xec, &pci_cmd);
pci_cmd &= ~(1 << 2);
pci_write_config_byte(dev, 0xec, pci_cmd);
pci_read_config_byte(dev, 0xe4, &pci_cmd);
pci_cmd &= ~(1 << 7);
pci_write_config_byte(dev, 0xe4, pci_cmd);
pci_read_config_byte(dev, 0xe5, &pci_cmd);
pci_cmd |= 1 << 7;
pci_write_config_byte(dev, 0xe5, pci_cmd);
pci_read_config_byte(dev, 0x81, &pci_cmd);
if (pci_cmd & 1 << 7) {
pci_read_config_dword(dev, 0x88, &acpi_regs_addr);
acpi_regs_addr &= 0xff00;
pr_info("ACPI I/O at 0x%x\n", acpi_regs_addr);
}
pci_dev_put(dev);
return 1;
}
return 0;
}
static int longhaul_cpu_init(struct cpufreq_policy *policy)
{
struct cpuinfo_x86 *c = &cpu_data(0);
char *cpuname = NULL;
int ret;
u32 lo, hi;
switch (c->x86_model) {
case 6:
cpu_model = CPU_SAMUEL;
cpuname = "C3 'Samuel' [C5A]";
longhaul_version = TYPE_LONGHAUL_V1;
memcpy(mults, samuel1_mults, sizeof(samuel1_mults));
memcpy(eblcr, samuel1_eblcr, sizeof(samuel1_eblcr));
break;
case 7:
switch (c->x86_mask) {
case 0:
longhaul_version = TYPE_LONGHAUL_V1;
cpu_model = CPU_SAMUEL2;
cpuname = "C3 'Samuel 2' [C5B]";
memcpy(mults, samuel1_mults, sizeof(samuel1_mults));
memcpy(eblcr, samuel2_eblcr, sizeof(samuel2_eblcr));
break;
case 1 ... 15:
longhaul_version = TYPE_LONGHAUL_V2;
if (c->x86_mask < 8) {
cpu_model = CPU_SAMUEL2;
cpuname = "C3 'Samuel 2' [C5B]";
} else {
cpu_model = CPU_EZRA;
cpuname = "C3 'Ezra' [C5C]";
}
memcpy(mults, ezra_mults, sizeof(ezra_mults));
memcpy(eblcr, ezra_eblcr, sizeof(ezra_eblcr));
break;
}
break;
case 8:
cpu_model = CPU_EZRA_T;
cpuname = "C3 'Ezra-T' [C5M]";
longhaul_version = TYPE_POWERSAVER;
numscales = 32;
memcpy(mults, ezrat_mults, sizeof(ezrat_mults));
memcpy(eblcr, ezrat_eblcr, sizeof(ezrat_eblcr));
break;
case 9:
longhaul_version = TYPE_POWERSAVER;
numscales = 32;
memcpy(mults, nehemiah_mults, sizeof(nehemiah_mults));
memcpy(eblcr, nehemiah_eblcr, sizeof(nehemiah_eblcr));
switch (c->x86_mask) {
case 0 ... 1:
cpu_model = CPU_NEHEMIAH;
cpuname = "C3 'Nehemiah A' [C5XLOE]";
break;
case 2 ... 4:
cpu_model = CPU_NEHEMIAH;
cpuname = "C3 'Nehemiah B' [C5XLOH]";
break;
case 5 ... 15:
cpu_model = CPU_NEHEMIAH_C;
cpuname = "C3 'Nehemiah C' [C5P]";
break;
}
break;
default:
cpuname = "Unknown";
break;
}
if (longhaul_version == TYPE_LONGHAUL_V2) {
rdmsr(MSR_VIA_LONGHAUL, lo, hi);
if (lo == 0 && hi == 0)
longhaul_version = TYPE_LONGHAUL_V1;
}
pr_info("VIA %s CPU detected. ", cpuname);
switch (longhaul_version) {
case TYPE_LONGHAUL_V1:
case TYPE_LONGHAUL_V2:
pr_cont("Longhaul v%d supported\n", longhaul_version);
break;
case TYPE_POWERSAVER:
pr_cont("Powersaver supported\n");
break;
};
longhaul_setup_southbridge();
acpi_walk_namespace(ACPI_TYPE_PROCESSOR, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, &longhaul_walk_callback, NULL,
NULL, (void *)&pr);
if (pr != NULL && longhaul_version == TYPE_POWERSAVER) {
cx = &pr->power.states[ACPI_STATE_C3];
if (cx->address > 0 && cx->latency <= 1000)
longhaul_flags |= USE_ACPI_C3;
}
if (disable_acpi_c3)
longhaul_flags &= ~USE_ACPI_C3;
if (enable_arbiter_disable())
longhaul_flags |= USE_NORTHBRIDGE;
if (!(longhaul_flags & USE_ACPI_C3
|| longhaul_flags & USE_NORTHBRIDGE)
&& ((pr == NULL) || !(pr->flags.bm_control))) {
pr_err("No ACPI support: Unsupported northbridge\n");
return -ENODEV;
}
if (longhaul_flags & USE_NORTHBRIDGE)
pr_info("Using northbridge support\n");
if (longhaul_flags & USE_ACPI_C3)
pr_info("Using ACPI support\n");
ret = longhaul_get_ranges();
if (ret != 0)
return ret;
if ((longhaul_version != TYPE_LONGHAUL_V1) && (scale_voltage != 0))
longhaul_setup_voltagescaling();
policy->cpuinfo.transition_latency = 200000;
return cpufreq_table_validate_and_show(policy, longhaul_table);
}
static int __init longhaul_init(void)
{
struct cpuinfo_x86 *c = &cpu_data(0);
if (!x86_match_cpu(longhaul_id))
return -ENODEV;
if (!enable) {
pr_err("Option \"enable\" not set - Aborting\n");
return -ENODEV;
}
#ifdef CONFIG_SMP
if (num_online_cpus() > 1) {
pr_err("More than 1 CPU detected, longhaul disabled\n");
return -ENODEV;
}
#endif
#ifdef CONFIG_X86_IO_APIC
if (boot_cpu_has(X86_FEATURE_APIC)) {
pr_err("APIC detected. Longhaul is currently broken in this configuration.\n");
return -ENODEV;
}
#endif
switch (c->x86_model) {
case 6 ... 9:
return cpufreq_register_driver(&longhaul_driver);
case 10:
pr_err("Use acpi-cpufreq driver for VIA C7\n");
default:
;
}
return -ENODEV;
}
static void __exit longhaul_exit(void)
{
struct cpufreq_policy *policy = cpufreq_cpu_get(0);
int i;
for (i = 0; i < numscales; i++) {
if (mults[i] == maxmult) {
struct cpufreq_freqs freqs;
freqs.old = policy->cur;
freqs.new = longhaul_table[i].frequency;
freqs.flags = 0;
cpufreq_freq_transition_begin(policy, &freqs);
longhaul_setstate(policy, i);
cpufreq_freq_transition_end(policy, &freqs, 0);
break;
}
}
cpufreq_cpu_put(policy);
cpufreq_unregister_driver(&longhaul_driver);
kfree(longhaul_table);
}
