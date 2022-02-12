u16 amd_nb_num(void)
{
return amd_northbridges.num;
}
bool amd_nb_has_feature(unsigned int feature)
{
return ((amd_northbridges.flags & feature) == feature);
}
struct amd_northbridge *node_to_amd_nb(int node)
{
return (node < amd_northbridges.num) ? &amd_northbridges.nb[node] : NULL;
}
static struct pci_dev *next_northbridge(struct pci_dev *dev,
const struct pci_device_id *ids)
{
do {
dev = pci_get_device(PCI_ANY_ID, PCI_ANY_ID, dev);
if (!dev)
break;
} while (!pci_match_id(ids, dev));
return dev;
}
static int __amd_smn_rw(u16 node, u32 address, u32 *value, bool write)
{
struct pci_dev *root;
int err = -ENODEV;
if (node >= amd_northbridges.num)
goto out;
root = node_to_amd_nb(node)->root;
if (!root)
goto out;
mutex_lock(&smn_mutex);
err = pci_write_config_dword(root, 0x60, address);
if (err) {
pr_warn("Error programming SMN address 0x%x.\n", address);
goto out_unlock;
}
err = (write ? pci_write_config_dword(root, 0x64, *value)
: pci_read_config_dword(root, 0x64, value));
if (err)
pr_warn("Error %s SMN address 0x%x.\n",
(write ? "writing to" : "reading from"), address);
out_unlock:
mutex_unlock(&smn_mutex);
out:
return err;
}
int amd_smn_read(u16 node, u32 address, u32 *value)
{
return __amd_smn_rw(node, address, value, false);
}
int amd_smn_write(u16 node, u32 address, u32 value)
{
return __amd_smn_rw(node, address, &value, true);
}
int amd_df_indirect_read(u16 node, u8 func, u16 reg, u8 instance_id, u32 *lo)
{
struct pci_dev *F4;
u32 ficaa;
int err = -ENODEV;
if (node >= amd_northbridges.num)
goto out;
F4 = node_to_amd_nb(node)->link;
if (!F4)
goto out;
ficaa = 1;
ficaa |= reg & 0x3FC;
ficaa |= (func & 0x7) << 11;
ficaa |= instance_id << 16;
mutex_lock(&smn_mutex);
err = pci_write_config_dword(F4, 0x5C, ficaa);
if (err) {
pr_warn("Error writing DF Indirect FICAA, FICAA=0x%x\n", ficaa);
goto out_unlock;
}
err = pci_read_config_dword(F4, 0x98, lo);
if (err)
pr_warn("Error reading DF Indirect FICAD LO, FICAA=0x%x.\n", ficaa);
out_unlock:
mutex_unlock(&smn_mutex);
out:
return err;
}
int amd_cache_northbridges(void)
{
u16 i = 0;
struct amd_northbridge *nb;
struct pci_dev *root, *misc, *link;
if (amd_northbridges.num)
return 0;
misc = NULL;
while ((misc = next_northbridge(misc, amd_nb_misc_ids)) != NULL)
i++;
if (!i)
return -ENODEV;
nb = kcalloc(i, sizeof(struct amd_northbridge), GFP_KERNEL);
if (!nb)
return -ENOMEM;
amd_northbridges.nb = nb;
amd_northbridges.num = i;
link = misc = root = NULL;
for (i = 0; i != amd_northbridges.num; i++) {
node_to_amd_nb(i)->root = root =
next_northbridge(root, amd_root_ids);
node_to_amd_nb(i)->misc = misc =
next_northbridge(misc, amd_nb_misc_ids);
node_to_amd_nb(i)->link = link =
next_northbridge(link, amd_nb_link_ids);
}
if (amd_gart_present())
amd_northbridges.flags |= AMD_NB_GART;
if (!cpuid_edx(0x80000006))
return 0;
if (boot_cpu_data.x86 == 0x10 &&
boot_cpu_data.x86_model >= 0x8 &&
(boot_cpu_data.x86_model > 0x9 ||
boot_cpu_data.x86_mask >= 0x1))
amd_northbridges.flags |= AMD_NB_L3_INDEX_DISABLE;
if (boot_cpu_data.x86 == 0x15)
amd_northbridges.flags |= AMD_NB_L3_INDEX_DISABLE;
if (boot_cpu_data.x86 == 0x15)
amd_northbridges.flags |= AMD_NB_L3_PARTITIONING;
return 0;
}
bool __init early_is_amd_nb(u32 device)
{
const struct pci_device_id *id;
u32 vendor = device & 0xffff;
device >>= 16;
for (id = amd_nb_misc_ids; id->vendor; id++)
if (vendor == id->vendor && device == id->device)
return true;
return false;
}
struct resource *amd_get_mmconfig_range(struct resource *res)
{
u32 address;
u64 base, msr;
unsigned int segn_busn_bits;
if (boot_cpu_data.x86_vendor != X86_VENDOR_AMD)
return NULL;
if (boot_cpu_data.x86 < 0x10)
return NULL;
address = MSR_FAM10H_MMIO_CONF_BASE;
rdmsrl(address, msr);
if (!(msr & FAM10H_MMIO_CONF_ENABLE))
return NULL;
base = msr & (FAM10H_MMIO_CONF_BASE_MASK<<FAM10H_MMIO_CONF_BASE_SHIFT);
segn_busn_bits = (msr >> FAM10H_MMIO_CONF_BUSRANGE_SHIFT) &
FAM10H_MMIO_CONF_BUSRANGE_MASK;
res->flags = IORESOURCE_MEM;
res->start = base;
res->end = base + (1ULL<<(segn_busn_bits + 20)) - 1;
return res;
}
int amd_get_subcaches(int cpu)
{
struct pci_dev *link = node_to_amd_nb(amd_get_nb_id(cpu))->link;
unsigned int mask;
if (!amd_nb_has_feature(AMD_NB_L3_PARTITIONING))
return 0;
pci_read_config_dword(link, 0x1d4, &mask);
return (mask >> (4 * cpu_data(cpu).cpu_core_id)) & 0xf;
}
int amd_set_subcaches(int cpu, unsigned long mask)
{
static unsigned int reset, ban;
struct amd_northbridge *nb = node_to_amd_nb(amd_get_nb_id(cpu));
unsigned int reg;
int cuid;
if (!amd_nb_has_feature(AMD_NB_L3_PARTITIONING) || mask > 0xf)
return -EINVAL;
if (reset == 0) {
pci_read_config_dword(nb->link, 0x1d4, &reset);
pci_read_config_dword(nb->misc, 0x1b8, &ban);
ban &= 0x180000;
}
if (mask != 0xf) {
pci_read_config_dword(nb->misc, 0x1b8, &reg);
pci_write_config_dword(nb->misc, 0x1b8, reg & ~0x180000);
}
cuid = cpu_data(cpu).cpu_core_id;
mask <<= 4 * cuid;
mask |= (0xf ^ (1 << cuid)) << 26;
pci_write_config_dword(nb->link, 0x1d4, mask);
pci_read_config_dword(nb->link, 0x1d4, &reg);
if (reg == reset) {
pci_read_config_dword(nb->misc, 0x1b8, &reg);
reg &= ~0x180000;
pci_write_config_dword(nb->misc, 0x1b8, reg | ban);
}
return 0;
}
static void amd_cache_gart(void)
{
u16 i;
if (!amd_nb_has_feature(AMD_NB_GART))
return;
flush_words = kmalloc_array(amd_northbridges.num, sizeof(u32), GFP_KERNEL);
if (!flush_words) {
amd_northbridges.flags &= ~AMD_NB_GART;
pr_notice("Cannot initialize GART flush words, GART support disabled\n");
return;
}
for (i = 0; i != amd_northbridges.num; i++)
pci_read_config_dword(node_to_amd_nb(i)->misc, 0x9c, &flush_words[i]);
}
void amd_flush_garts(void)
{
int flushed, i;
unsigned long flags;
static DEFINE_SPINLOCK(gart_lock);
if (!amd_nb_has_feature(AMD_NB_GART))
return;
spin_lock_irqsave(&gart_lock, flags);
flushed = 0;
for (i = 0; i < amd_northbridges.num; i++) {
pci_write_config_dword(node_to_amd_nb(i)->misc, 0x9c,
flush_words[i] | 1);
flushed++;
}
for (i = 0; i < amd_northbridges.num; i++) {
u32 w;
for (;;) {
pci_read_config_dword(node_to_amd_nb(i)->misc,
0x9c, &w);
if (!(w & 1))
break;
cpu_relax();
}
}
spin_unlock_irqrestore(&gart_lock, flags);
if (!flushed)
pr_notice("nothing to flush?\n");
}
static __init int init_amd_nbs(void)
{
amd_cache_northbridges();
amd_cache_gart();
return 0;
}
