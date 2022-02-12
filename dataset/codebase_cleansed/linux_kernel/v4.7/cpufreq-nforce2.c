static int nforce2_calc_fsb(int pll)
{
unsigned char mul, div;
mul = (pll >> 8) & 0xff;
div = pll & 0xff;
if (div > 0)
return NFORCE2_XTAL * mul / div;
return 0;
}
static int nforce2_calc_pll(unsigned int fsb)
{
unsigned char xmul, xdiv;
unsigned char mul = 0, div = 0;
int tried = 0;
while (((mul == 0) || (div == 0)) && (tried <= 3)) {
for (xdiv = 2; xdiv <= 0x80; xdiv++)
for (xmul = 1; xmul <= 0xfe; xmul++)
if (nforce2_calc_fsb(NFORCE2_PLL(xmul, xdiv)) ==
fsb + tried) {
mul = xmul;
div = xdiv;
}
tried++;
}
if ((mul == 0) || (div == 0))
return -1;
return NFORCE2_PLL(mul, div);
}
static void nforce2_write_pll(int pll)
{
int temp;
pci_write_config_dword(nforce2_dev, NFORCE2_PLLADR, 0);
for (temp = 0; temp <= 0x3f; temp++)
pci_write_config_dword(nforce2_dev, NFORCE2_PLLREG, pll);
return;
}
static unsigned int nforce2_fsb_read(int bootfsb)
{
struct pci_dev *nforce2_sub5;
u32 fsb, temp = 0;
nforce2_sub5 = pci_get_subsys(PCI_VENDOR_ID_NVIDIA, 0x01EF,
PCI_ANY_ID, PCI_ANY_ID, NULL);
if (!nforce2_sub5)
return 0;
pci_read_config_dword(nforce2_sub5, NFORCE2_BOOTFSB, &fsb);
fsb /= 1000000;
pci_read_config_byte(nforce2_dev, NFORCE2_PLLENABLE, (u8 *)&temp);
if (bootfsb || !temp)
return fsb;
pci_read_config_dword(nforce2_dev, NFORCE2_PLLREG, &temp);
fsb = nforce2_calc_fsb(temp);
return fsb;
}
static int nforce2_set_fsb(unsigned int fsb)
{
u32 temp = 0;
unsigned int tfsb;
int diff;
int pll = 0;
if ((fsb > max_fsb) || (fsb < NFORCE2_MIN_FSB)) {
pr_err("FSB %d is out of range!\n", fsb);
return -EINVAL;
}
tfsb = nforce2_fsb_read(0);
if (!tfsb) {
pr_err("Error while reading the FSB\n");
return -EINVAL;
}
pci_read_config_byte(nforce2_dev, NFORCE2_PLLENABLE, (u8 *)&temp);
if (!temp) {
pll = nforce2_calc_pll(tfsb);
if (pll < 0)
return -EINVAL;
nforce2_write_pll(pll);
}
temp = 0x01;
pci_write_config_byte(nforce2_dev, NFORCE2_PLLENABLE, (u8)temp);
diff = tfsb - fsb;
if (!diff)
return 0;
while ((tfsb != fsb) && (tfsb <= max_fsb) && (tfsb >= min_fsb)) {
if (diff < 0)
tfsb++;
else
tfsb--;
pll = nforce2_calc_pll(tfsb);
if (pll == -1)
return -EINVAL;
nforce2_write_pll(pll);
#ifdef NFORCE2_DELAY
mdelay(NFORCE2_DELAY);
#endif
}
temp = 0x40;
pci_write_config_byte(nforce2_dev, NFORCE2_PLLADR, (u8)temp);
return 0;
}
static unsigned int nforce2_get(unsigned int cpu)
{
if (cpu)
return 0;
return nforce2_fsb_read(0) * fid * 100;
}
static int nforce2_target(struct cpufreq_policy *policy,
unsigned int target_freq, unsigned int relation)
{
struct cpufreq_freqs freqs;
unsigned int target_fsb;
if ((target_freq > policy->max) || (target_freq < policy->min))
return -EINVAL;
target_fsb = target_freq / (fid * 100);
freqs.old = nforce2_get(policy->cpu);
freqs.new = target_fsb * fid * 100;
if (freqs.old == freqs.new)
return 0;
pr_debug("Old CPU frequency %d kHz, new %d kHz\n",
freqs.old, freqs.new);
cpufreq_freq_transition_begin(policy, &freqs);
if (nforce2_set_fsb(target_fsb) < 0)
pr_err("Changing FSB to %d failed\n", target_fsb);
else
pr_debug("Changed FSB successfully to %d\n",
target_fsb);
cpufreq_freq_transition_end(policy, &freqs, 0);
return 0;
}
static int nforce2_verify(struct cpufreq_policy *policy)
{
unsigned int fsb_pol_max;
fsb_pol_max = policy->max / (fid * 100);
if (policy->min < (fsb_pol_max * fid * 100))
policy->max = (fsb_pol_max + 1) * fid * 100;
cpufreq_verify_within_cpu_limits(policy);
return 0;
}
static int nforce2_cpu_init(struct cpufreq_policy *policy)
{
unsigned int fsb;
unsigned int rfid;
if (policy->cpu != 0)
return -ENODEV;
fsb = nforce2_fsb_read(0);
if (!fsb)
return -EIO;
if (!fid) {
if (!cpu_khz) {
pr_warn("cpu_khz not set, can't calculate multiplier!\n");
return -ENODEV;
}
fid = cpu_khz / (fsb * 100);
rfid = fid % 5;
if (rfid) {
if (rfid > 2)
fid += 5 - rfid;
else
fid -= rfid;
}
}
pr_info("FSB currently at %i MHz, FID %d.%d\n",
fsb, fid / 10, fid % 10);
max_fsb = nforce2_fsb_read(1);
if (!max_fsb)
return -EIO;
if (!min_fsb)
min_fsb = max_fsb - NFORCE2_SAFE_DISTANCE;
if (min_fsb < NFORCE2_MIN_FSB)
min_fsb = NFORCE2_MIN_FSB;
policy->min = policy->cpuinfo.min_freq = min_fsb * fid * 100;
policy->max = policy->cpuinfo.max_freq = max_fsb * fid * 100;
policy->cpuinfo.transition_latency = CPUFREQ_ETERNAL;
return 0;
}
static int nforce2_cpu_exit(struct cpufreq_policy *policy)
{
return 0;
}
static int nforce2_detect_chipset(void)
{
nforce2_dev = pci_get_subsys(PCI_VENDOR_ID_NVIDIA,
PCI_DEVICE_ID_NVIDIA_NFORCE2,
PCI_ANY_ID, PCI_ANY_ID, NULL);
if (nforce2_dev == NULL)
return -ENODEV;
pr_info("Detected nForce2 chipset revision %X\n",
nforce2_dev->revision);
pr_info("FSB changing is maybe unstable and can lead to crashes and data loss\n");
return 0;
}
static int __init nforce2_init(void)
{
if (nforce2_detect_chipset()) {
pr_info("No nForce2 chipset\n");
return -ENODEV;
}
return cpufreq_register_driver(&nforce2_driver);
}
static void __exit nforce2_exit(void)
{
cpufreq_unregister_driver(&nforce2_driver);
}
