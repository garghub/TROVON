static inline void update_last_devid(u16 devid)
{
if (devid > amd_iommu_last_bdf)
amd_iommu_last_bdf = devid;
}
static inline unsigned long tbl_size(int entry_size)
{
unsigned shift = PAGE_SHIFT +
get_order(((int)amd_iommu_last_bdf + 1) * entry_size);
return 1UL << shift;
}
static u32 iommu_read_l1(struct amd_iommu *iommu, u16 l1, u8 address)
{
u32 val;
pci_write_config_dword(iommu->dev, 0xf8, (address | l1 << 16));
pci_read_config_dword(iommu->dev, 0xfc, &val);
return val;
}
static void iommu_write_l1(struct amd_iommu *iommu, u16 l1, u8 address, u32 val)
{
pci_write_config_dword(iommu->dev, 0xf8, (address | l1 << 16 | 1 << 31));
pci_write_config_dword(iommu->dev, 0xfc, val);
pci_write_config_dword(iommu->dev, 0xf8, (address | l1 << 16));
}
static u32 iommu_read_l2(struct amd_iommu *iommu, u8 address)
{
u32 val;
pci_write_config_dword(iommu->dev, 0xf0, address);
pci_read_config_dword(iommu->dev, 0xf4, &val);
return val;
}
static void iommu_write_l2(struct amd_iommu *iommu, u8 address, u32 val)
{
pci_write_config_dword(iommu->dev, 0xf0, (address | 1 << 8));
pci_write_config_dword(iommu->dev, 0xf4, val);
}
static void iommu_set_exclusion_range(struct amd_iommu *iommu)
{
u64 start = iommu->exclusion_start & PAGE_MASK;
u64 limit = (start + iommu->exclusion_length) & PAGE_MASK;
u64 entry;
if (!iommu->exclusion_start)
return;
entry = start | MMIO_EXCL_ENABLE_MASK;
memcpy_toio(iommu->mmio_base + MMIO_EXCL_BASE_OFFSET,
&entry, sizeof(entry));
entry = limit;
memcpy_toio(iommu->mmio_base + MMIO_EXCL_LIMIT_OFFSET,
&entry, sizeof(entry));
}
static void iommu_set_device_table(struct amd_iommu *iommu)
{
u64 entry;
BUG_ON(iommu->mmio_base == NULL);
entry = virt_to_phys(amd_iommu_dev_table);
entry |= (dev_table_size >> 12) - 1;
memcpy_toio(iommu->mmio_base + MMIO_DEV_TABLE_OFFSET,
&entry, sizeof(entry));
}
static void iommu_feature_enable(struct amd_iommu *iommu, u8 bit)
{
u32 ctrl;
ctrl = readl(iommu->mmio_base + MMIO_CONTROL_OFFSET);
ctrl |= (1 << bit);
writel(ctrl, iommu->mmio_base + MMIO_CONTROL_OFFSET);
}
static void iommu_feature_disable(struct amd_iommu *iommu, u8 bit)
{
u32 ctrl;
ctrl = readl(iommu->mmio_base + MMIO_CONTROL_OFFSET);
ctrl &= ~(1 << bit);
writel(ctrl, iommu->mmio_base + MMIO_CONTROL_OFFSET);
}
static void iommu_set_inv_tlb_timeout(struct amd_iommu *iommu, int timeout)
{
u32 ctrl;
ctrl = readl(iommu->mmio_base + MMIO_CONTROL_OFFSET);
ctrl &= ~CTRL_INV_TO_MASK;
ctrl |= (timeout << CONTROL_INV_TIMEOUT) & CTRL_INV_TO_MASK;
writel(ctrl, iommu->mmio_base + MMIO_CONTROL_OFFSET);
}
static void iommu_enable(struct amd_iommu *iommu)
{
iommu_feature_enable(iommu, CONTROL_IOMMU_EN);
}
static void iommu_disable(struct amd_iommu *iommu)
{
iommu_feature_disable(iommu, CONTROL_CMDBUF_EN);
iommu_feature_disable(iommu, CONTROL_EVT_INT_EN);
iommu_feature_disable(iommu, CONTROL_EVT_LOG_EN);
iommu_feature_disable(iommu, CONTROL_IOMMU_EN);
}
static u8 __iomem * __init iommu_map_mmio_space(u64 address, u64 end)
{
if (!request_mem_region(address, end, "amd_iommu")) {
pr_err("AMD-Vi: Can not reserve memory region %llx-%llx for mmio\n",
address, end);
pr_err("AMD-Vi: This is a BIOS bug. Please contact your hardware vendor\n");
return NULL;
}
return (u8 __iomem *)ioremap_nocache(address, end);
}
static void __init iommu_unmap_mmio_space(struct amd_iommu *iommu)
{
if (iommu->mmio_base)
iounmap(iommu->mmio_base);
release_mem_region(iommu->mmio_phys, iommu->mmio_phys_end);
}
static inline int ivhd_entry_length(u8 *ivhd)
{
return 0x04 << (*ivhd >> 6);
}
static int __init find_last_devid_on_pci(int bus, int dev, int fn, int cap_ptr)
{
u32 cap;
cap = read_pci_config(bus, dev, fn, cap_ptr+MMIO_RANGE_OFFSET);
update_last_devid(PCI_DEVID(MMIO_GET_BUS(cap), MMIO_GET_LD(cap)));
return 0;
}
static int __init find_last_devid_from_ivhd(struct ivhd_header *h)
{
u8 *p = (void *)h, *end = (void *)h;
struct ivhd_entry *dev;
p += sizeof(*h);
end += h->length;
find_last_devid_on_pci(PCI_BUS_NUM(h->devid),
PCI_SLOT(h->devid),
PCI_FUNC(h->devid),
h->cap_ptr);
while (p < end) {
dev = (struct ivhd_entry *)p;
switch (dev->type) {
case IVHD_DEV_SELECT:
case IVHD_DEV_RANGE_END:
case IVHD_DEV_ALIAS:
case IVHD_DEV_EXT_SELECT:
update_last_devid(dev->devid);
break;
default:
break;
}
p += ivhd_entry_length(p);
}
WARN_ON(p != end);
return 0;
}
static int __init find_last_devid_acpi(struct acpi_table_header *table)
{
int i;
u8 checksum = 0, *p = (u8 *)table, *end = (u8 *)table;
struct ivhd_header *h;
for (i = 0; i < table->length; ++i)
checksum += p[i];
if (checksum != 0)
return -ENODEV;
p += IVRS_HEADER_LENGTH;
end += table->length;
while (p < end) {
h = (struct ivhd_header *)p;
switch (h->type) {
case ACPI_IVHD_TYPE:
find_last_devid_from_ivhd(h);
break;
default:
break;
}
p += h->length;
}
WARN_ON(p != end);
return 0;
}
static u8 * __init alloc_command_buffer(struct amd_iommu *iommu)
{
u8 *cmd_buf = (u8 *)__get_free_pages(GFP_KERNEL | __GFP_ZERO,
get_order(CMD_BUFFER_SIZE));
if (cmd_buf == NULL)
return NULL;
iommu->cmd_buf_size = CMD_BUFFER_SIZE | CMD_BUFFER_UNINITIALIZED;
return cmd_buf;
}
void amd_iommu_reset_cmd_buffer(struct amd_iommu *iommu)
{
iommu_feature_disable(iommu, CONTROL_CMDBUF_EN);
writel(0x00, iommu->mmio_base + MMIO_CMD_HEAD_OFFSET);
writel(0x00, iommu->mmio_base + MMIO_CMD_TAIL_OFFSET);
iommu_feature_enable(iommu, CONTROL_CMDBUF_EN);
}
static void iommu_enable_command_buffer(struct amd_iommu *iommu)
{
u64 entry;
BUG_ON(iommu->cmd_buf == NULL);
entry = (u64)virt_to_phys(iommu->cmd_buf);
entry |= MMIO_CMD_SIZE_512;
memcpy_toio(iommu->mmio_base + MMIO_CMD_BUF_OFFSET,
&entry, sizeof(entry));
amd_iommu_reset_cmd_buffer(iommu);
iommu->cmd_buf_size &= ~(CMD_BUFFER_UNINITIALIZED);
}
static void __init free_command_buffer(struct amd_iommu *iommu)
{
free_pages((unsigned long)iommu->cmd_buf,
get_order(iommu->cmd_buf_size & ~(CMD_BUFFER_UNINITIALIZED)));
}
static u8 * __init alloc_event_buffer(struct amd_iommu *iommu)
{
iommu->evt_buf = (u8 *)__get_free_pages(GFP_KERNEL | __GFP_ZERO,
get_order(EVT_BUFFER_SIZE));
if (iommu->evt_buf == NULL)
return NULL;
iommu->evt_buf_size = EVT_BUFFER_SIZE;
return iommu->evt_buf;
}
static void iommu_enable_event_buffer(struct amd_iommu *iommu)
{
u64 entry;
BUG_ON(iommu->evt_buf == NULL);
entry = (u64)virt_to_phys(iommu->evt_buf) | EVT_LEN_MASK;
memcpy_toio(iommu->mmio_base + MMIO_EVT_BUF_OFFSET,
&entry, sizeof(entry));
writel(0x00, iommu->mmio_base + MMIO_EVT_HEAD_OFFSET);
writel(0x00, iommu->mmio_base + MMIO_EVT_TAIL_OFFSET);
iommu_feature_enable(iommu, CONTROL_EVT_LOG_EN);
}
static void __init free_event_buffer(struct amd_iommu *iommu)
{
free_pages((unsigned long)iommu->evt_buf, get_order(EVT_BUFFER_SIZE));
}
static u8 * __init alloc_ppr_log(struct amd_iommu *iommu)
{
iommu->ppr_log = (u8 *)__get_free_pages(GFP_KERNEL | __GFP_ZERO,
get_order(PPR_LOG_SIZE));
if (iommu->ppr_log == NULL)
return NULL;
return iommu->ppr_log;
}
static void iommu_enable_ppr_log(struct amd_iommu *iommu)
{
u64 entry;
if (iommu->ppr_log == NULL)
return;
entry = (u64)virt_to_phys(iommu->ppr_log) | PPR_LOG_SIZE_512;
memcpy_toio(iommu->mmio_base + MMIO_PPR_LOG_OFFSET,
&entry, sizeof(entry));
writel(0x00, iommu->mmio_base + MMIO_PPR_HEAD_OFFSET);
writel(0x00, iommu->mmio_base + MMIO_PPR_TAIL_OFFSET);
iommu_feature_enable(iommu, CONTROL_PPFLOG_EN);
iommu_feature_enable(iommu, CONTROL_PPR_EN);
}
static void __init free_ppr_log(struct amd_iommu *iommu)
{
if (iommu->ppr_log == NULL)
return;
free_pages((unsigned long)iommu->ppr_log, get_order(PPR_LOG_SIZE));
}
static void iommu_enable_gt(struct amd_iommu *iommu)
{
if (!iommu_feature(iommu, FEATURE_GT))
return;
iommu_feature_enable(iommu, CONTROL_GT_EN);
}
static void set_dev_entry_bit(u16 devid, u8 bit)
{
int i = (bit >> 6) & 0x03;
int _bit = bit & 0x3f;
amd_iommu_dev_table[devid].data[i] |= (1UL << _bit);
}
static int get_dev_entry_bit(u16 devid, u8 bit)
{
int i = (bit >> 6) & 0x03;
int _bit = bit & 0x3f;
return (amd_iommu_dev_table[devid].data[i] & (1UL << _bit)) >> _bit;
}
void amd_iommu_apply_erratum_63(u16 devid)
{
int sysmgt;
sysmgt = get_dev_entry_bit(devid, DEV_ENTRY_SYSMGT1) |
(get_dev_entry_bit(devid, DEV_ENTRY_SYSMGT2) << 1);
if (sysmgt == 0x01)
set_dev_entry_bit(devid, DEV_ENTRY_IW);
}
static void __init set_iommu_for_device(struct amd_iommu *iommu, u16 devid)
{
amd_iommu_rlookup_table[devid] = iommu;
}
static void __init set_dev_entry_from_acpi(struct amd_iommu *iommu,
u16 devid, u32 flags, u32 ext_flags)
{
if (flags & ACPI_DEVFLAG_INITPASS)
set_dev_entry_bit(devid, DEV_ENTRY_INIT_PASS);
if (flags & ACPI_DEVFLAG_EXTINT)
set_dev_entry_bit(devid, DEV_ENTRY_EINT_PASS);
if (flags & ACPI_DEVFLAG_NMI)
set_dev_entry_bit(devid, DEV_ENTRY_NMI_PASS);
if (flags & ACPI_DEVFLAG_SYSMGT1)
set_dev_entry_bit(devid, DEV_ENTRY_SYSMGT1);
if (flags & ACPI_DEVFLAG_SYSMGT2)
set_dev_entry_bit(devid, DEV_ENTRY_SYSMGT2);
if (flags & ACPI_DEVFLAG_LINT0)
set_dev_entry_bit(devid, DEV_ENTRY_LINT0_PASS);
if (flags & ACPI_DEVFLAG_LINT1)
set_dev_entry_bit(devid, DEV_ENTRY_LINT1_PASS);
amd_iommu_apply_erratum_63(devid);
set_iommu_for_device(iommu, devid);
}
static int __init add_special_device(u8 type, u8 id, u16 *devid, bool cmd_line)
{
struct devid_map *entry;
struct list_head *list;
if (type == IVHD_SPECIAL_IOAPIC)
list = &ioapic_map;
else if (type == IVHD_SPECIAL_HPET)
list = &hpet_map;
else
return -EINVAL;
list_for_each_entry(entry, list, list) {
if (!(entry->id == id && entry->cmd_line))
continue;
pr_info("AMD-Vi: Command-line override present for %s id %d - ignoring\n",
type == IVHD_SPECIAL_IOAPIC ? "IOAPIC" : "HPET", id);
*devid = entry->devid;
return 0;
}
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
return -ENOMEM;
entry->id = id;
entry->devid = *devid;
entry->cmd_line = cmd_line;
list_add_tail(&entry->list, list);
return 0;
}
static int __init add_early_maps(void)
{
int i, ret;
for (i = 0; i < early_ioapic_map_size; ++i) {
ret = add_special_device(IVHD_SPECIAL_IOAPIC,
early_ioapic_map[i].id,
&early_ioapic_map[i].devid,
early_ioapic_map[i].cmd_line);
if (ret)
return ret;
}
for (i = 0; i < early_hpet_map_size; ++i) {
ret = add_special_device(IVHD_SPECIAL_HPET,
early_hpet_map[i].id,
&early_hpet_map[i].devid,
early_hpet_map[i].cmd_line);
if (ret)
return ret;
}
return 0;
}
static void __init set_device_exclusion_range(u16 devid, struct ivmd_header *m)
{
struct amd_iommu *iommu = amd_iommu_rlookup_table[devid];
if (!(m->flags & IVMD_FLAG_EXCL_RANGE))
return;
if (iommu) {
set_dev_entry_bit(devid, DEV_ENTRY_EX);
iommu->exclusion_start = m->range_start;
iommu->exclusion_length = m->range_length;
}
}
static int __init init_iommu_from_acpi(struct amd_iommu *iommu,
struct ivhd_header *h)
{
u8 *p = (u8 *)h;
u8 *end = p, flags = 0;
u16 devid = 0, devid_start = 0, devid_to = 0;
u32 dev_i, ext_flags = 0;
bool alias = false;
struct ivhd_entry *e;
int ret;
ret = add_early_maps();
if (ret)
return ret;
iommu->acpi_flags = h->flags;
p += sizeof(struct ivhd_header);
end += h->length;
while (p < end) {
e = (struct ivhd_entry *)p;
switch (e->type) {
case IVHD_DEV_ALL:
DUMP_printk(" DEV_ALL\t\t\t first devid: %02x:%02x.%x"
" last device %02x:%02x.%x flags: %02x\n",
PCI_BUS_NUM(iommu->first_device),
PCI_SLOT(iommu->first_device),
PCI_FUNC(iommu->first_device),
PCI_BUS_NUM(iommu->last_device),
PCI_SLOT(iommu->last_device),
PCI_FUNC(iommu->last_device),
e->flags);
for (dev_i = iommu->first_device;
dev_i <= iommu->last_device; ++dev_i)
set_dev_entry_from_acpi(iommu, dev_i,
e->flags, 0);
break;
case IVHD_DEV_SELECT:
DUMP_printk(" DEV_SELECT\t\t\t devid: %02x:%02x.%x "
"flags: %02x\n",
PCI_BUS_NUM(e->devid),
PCI_SLOT(e->devid),
PCI_FUNC(e->devid),
e->flags);
devid = e->devid;
set_dev_entry_from_acpi(iommu, devid, e->flags, 0);
break;
case IVHD_DEV_SELECT_RANGE_START:
DUMP_printk(" DEV_SELECT_RANGE_START\t "
"devid: %02x:%02x.%x flags: %02x\n",
PCI_BUS_NUM(e->devid),
PCI_SLOT(e->devid),
PCI_FUNC(e->devid),
e->flags);
devid_start = e->devid;
flags = e->flags;
ext_flags = 0;
alias = false;
break;
case IVHD_DEV_ALIAS:
DUMP_printk(" DEV_ALIAS\t\t\t devid: %02x:%02x.%x "
"flags: %02x devid_to: %02x:%02x.%x\n",
PCI_BUS_NUM(e->devid),
PCI_SLOT(e->devid),
PCI_FUNC(e->devid),
e->flags,
PCI_BUS_NUM(e->ext >> 8),
PCI_SLOT(e->ext >> 8),
PCI_FUNC(e->ext >> 8));
devid = e->devid;
devid_to = e->ext >> 8;
set_dev_entry_from_acpi(iommu, devid , e->flags, 0);
set_dev_entry_from_acpi(iommu, devid_to, e->flags, 0);
amd_iommu_alias_table[devid] = devid_to;
break;
case IVHD_DEV_ALIAS_RANGE:
DUMP_printk(" DEV_ALIAS_RANGE\t\t "
"devid: %02x:%02x.%x flags: %02x "
"devid_to: %02x:%02x.%x\n",
PCI_BUS_NUM(e->devid),
PCI_SLOT(e->devid),
PCI_FUNC(e->devid),
e->flags,
PCI_BUS_NUM(e->ext >> 8),
PCI_SLOT(e->ext >> 8),
PCI_FUNC(e->ext >> 8));
devid_start = e->devid;
flags = e->flags;
devid_to = e->ext >> 8;
ext_flags = 0;
alias = true;
break;
case IVHD_DEV_EXT_SELECT:
DUMP_printk(" DEV_EXT_SELECT\t\t devid: %02x:%02x.%x "
"flags: %02x ext: %08x\n",
PCI_BUS_NUM(e->devid),
PCI_SLOT(e->devid),
PCI_FUNC(e->devid),
e->flags, e->ext);
devid = e->devid;
set_dev_entry_from_acpi(iommu, devid, e->flags,
e->ext);
break;
case IVHD_DEV_EXT_SELECT_RANGE:
DUMP_printk(" DEV_EXT_SELECT_RANGE\t devid: "
"%02x:%02x.%x flags: %02x ext: %08x\n",
PCI_BUS_NUM(e->devid),
PCI_SLOT(e->devid),
PCI_FUNC(e->devid),
e->flags, e->ext);
devid_start = e->devid;
flags = e->flags;
ext_flags = e->ext;
alias = false;
break;
case IVHD_DEV_RANGE_END:
DUMP_printk(" DEV_RANGE_END\t\t devid: %02x:%02x.%x\n",
PCI_BUS_NUM(e->devid),
PCI_SLOT(e->devid),
PCI_FUNC(e->devid));
devid = e->devid;
for (dev_i = devid_start; dev_i <= devid; ++dev_i) {
if (alias) {
amd_iommu_alias_table[dev_i] = devid_to;
set_dev_entry_from_acpi(iommu,
devid_to, flags, ext_flags);
}
set_dev_entry_from_acpi(iommu, dev_i,
flags, ext_flags);
}
break;
case IVHD_DEV_SPECIAL: {
u8 handle, type;
const char *var;
u16 devid;
int ret;
handle = e->ext & 0xff;
devid = (e->ext >> 8) & 0xffff;
type = (e->ext >> 24) & 0xff;
if (type == IVHD_SPECIAL_IOAPIC)
var = "IOAPIC";
else if (type == IVHD_SPECIAL_HPET)
var = "HPET";
else
var = "UNKNOWN";
DUMP_printk(" DEV_SPECIAL(%s[%d])\t\tdevid: %02x:%02x.%x\n",
var, (int)handle,
PCI_BUS_NUM(devid),
PCI_SLOT(devid),
PCI_FUNC(devid));
ret = add_special_device(type, handle, &devid, false);
if (ret)
return ret;
set_dev_entry_from_acpi(iommu, devid, e->flags, 0);
break;
}
default:
break;
}
p += ivhd_entry_length(p);
}
return 0;
}
static int __init init_iommu_devices(struct amd_iommu *iommu)
{
u32 i;
for (i = iommu->first_device; i <= iommu->last_device; ++i)
set_iommu_for_device(iommu, i);
return 0;
}
static void __init free_iommu_one(struct amd_iommu *iommu)
{
free_command_buffer(iommu);
free_event_buffer(iommu);
free_ppr_log(iommu);
iommu_unmap_mmio_space(iommu);
}
static void __init free_iommu_all(void)
{
struct amd_iommu *iommu, *next;
for_each_iommu_safe(iommu, next) {
list_del(&iommu->list);
free_iommu_one(iommu);
kfree(iommu);
}
}
static void amd_iommu_erratum_746_workaround(struct amd_iommu *iommu)
{
u32 value;
if ((boot_cpu_data.x86 != 0x15) ||
(boot_cpu_data.x86_model < 0x10) ||
(boot_cpu_data.x86_model > 0x1f))
return;
pci_write_config_dword(iommu->dev, 0xf0, 0x90);
pci_read_config_dword(iommu->dev, 0xf4, &value);
if (value & BIT(2))
return;
pci_write_config_dword(iommu->dev, 0xf0, 0x90 | (1 << 8));
pci_write_config_dword(iommu->dev, 0xf4, value | 0x4);
pr_info("AMD-Vi: Applying erratum 746 workaround for IOMMU at %s\n",
dev_name(&iommu->dev->dev));
pci_write_config_dword(iommu->dev, 0xf0, 0x90);
}
static int __init init_iommu_one(struct amd_iommu *iommu, struct ivhd_header *h)
{
int ret;
spin_lock_init(&iommu->lock);
list_add_tail(&iommu->list, &amd_iommu_list);
iommu->index = amd_iommus_present++;
if (unlikely(iommu->index >= MAX_IOMMUS)) {
WARN(1, "AMD-Vi: System has more IOMMUs than supported by this driver\n");
return -ENOSYS;
}
amd_iommus[iommu->index] = iommu;
iommu->devid = h->devid;
iommu->cap_ptr = h->cap_ptr;
iommu->pci_seg = h->pci_seg;
iommu->mmio_phys = h->mmio_phys;
if ((h->efr != 0) &&
((h->efr & (0xF << 13)) != 0) &&
((h->efr & (0x3F << 17)) != 0)) {
iommu->mmio_phys_end = MMIO_REG_END_OFFSET;
} else {
iommu->mmio_phys_end = MMIO_CNTR_CONF_OFFSET;
}
iommu->mmio_base = iommu_map_mmio_space(iommu->mmio_phys,
iommu->mmio_phys_end);
if (!iommu->mmio_base)
return -ENOMEM;
iommu->cmd_buf = alloc_command_buffer(iommu);
if (!iommu->cmd_buf)
return -ENOMEM;
iommu->evt_buf = alloc_event_buffer(iommu);
if (!iommu->evt_buf)
return -ENOMEM;
iommu->int_enabled = false;
ret = init_iommu_from_acpi(iommu, h);
if (ret)
return ret;
ret = amd_iommu_create_irq_domain(iommu);
if (ret)
return ret;
amd_iommu_rlookup_table[iommu->devid] = NULL;
init_iommu_devices(iommu);
return 0;
}
static int __init init_iommu_all(struct acpi_table_header *table)
{
u8 *p = (u8 *)table, *end = (u8 *)table;
struct ivhd_header *h;
struct amd_iommu *iommu;
int ret;
end += table->length;
p += IVRS_HEADER_LENGTH;
while (p < end) {
h = (struct ivhd_header *)p;
switch (*p) {
case ACPI_IVHD_TYPE:
DUMP_printk("device: %02x:%02x.%01x cap: %04x "
"seg: %d flags: %01x info %04x\n",
PCI_BUS_NUM(h->devid), PCI_SLOT(h->devid),
PCI_FUNC(h->devid), h->cap_ptr,
h->pci_seg, h->flags, h->info);
DUMP_printk(" mmio-addr: %016llx\n",
h->mmio_phys);
iommu = kzalloc(sizeof(struct amd_iommu), GFP_KERNEL);
if (iommu == NULL)
return -ENOMEM;
ret = init_iommu_one(iommu, h);
if (ret)
return ret;
break;
default:
break;
}
p += h->length;
}
WARN_ON(p != end);
return 0;
}
static void init_iommu_perf_ctr(struct amd_iommu *iommu)
{
u64 val = 0xabcd, val2 = 0;
if (!iommu_feature(iommu, FEATURE_PC))
return;
amd_iommu_pc_present = true;
if ((0 != amd_iommu_pc_get_set_reg_val(0, 0, 0, 0, &val, true)) ||
(0 != amd_iommu_pc_get_set_reg_val(0, 0, 0, 0, &val2, false)) ||
(val != val2)) {
pr_err("AMD-Vi: Unable to write to IOMMU perf counter.\n");
amd_iommu_pc_present = false;
return;
}
pr_info("AMD-Vi: IOMMU performance counters supported\n");
val = readl(iommu->mmio_base + MMIO_CNTR_CONF_OFFSET);
iommu->max_banks = (u8) ((val >> 12) & 0x3f);
iommu->max_counters = (u8) ((val >> 7) & 0xf);
}
static ssize_t amd_iommu_show_cap(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct amd_iommu *iommu = dev_get_drvdata(dev);
return sprintf(buf, "%x\n", iommu->cap);
}
static ssize_t amd_iommu_show_features(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct amd_iommu *iommu = dev_get_drvdata(dev);
return sprintf(buf, "%llx\n", iommu->features);
}
static int iommu_init_pci(struct amd_iommu *iommu)
{
int cap_ptr = iommu->cap_ptr;
u32 range, misc, low, high;
iommu->dev = pci_get_bus_and_slot(PCI_BUS_NUM(iommu->devid),
iommu->devid & 0xff);
if (!iommu->dev)
return -ENODEV;
pci_read_config_dword(iommu->dev, cap_ptr + MMIO_CAP_HDR_OFFSET,
&iommu->cap);
pci_read_config_dword(iommu->dev, cap_ptr + MMIO_RANGE_OFFSET,
&range);
pci_read_config_dword(iommu->dev, cap_ptr + MMIO_MISC_OFFSET,
&misc);
iommu->first_device = PCI_DEVID(MMIO_GET_BUS(range),
MMIO_GET_FD(range));
iommu->last_device = PCI_DEVID(MMIO_GET_BUS(range),
MMIO_GET_LD(range));
if (!(iommu->cap & (1 << IOMMU_CAP_IOTLB)))
amd_iommu_iotlb_sup = false;
low = readl(iommu->mmio_base + MMIO_EXT_FEATURES);
high = readl(iommu->mmio_base + MMIO_EXT_FEATURES + 4);
iommu->features = ((u64)high << 32) | low;
if (iommu_feature(iommu, FEATURE_GT)) {
int glxval;
u32 max_pasid;
u64 pasmax;
pasmax = iommu->features & FEATURE_PASID_MASK;
pasmax >>= FEATURE_PASID_SHIFT;
max_pasid = (1 << (pasmax + 1)) - 1;
amd_iommu_max_pasid = min(amd_iommu_max_pasid, max_pasid);
BUG_ON(amd_iommu_max_pasid & ~PASID_MASK);
glxval = iommu->features & FEATURE_GLXVAL_MASK;
glxval >>= FEATURE_GLXVAL_SHIFT;
if (amd_iommu_max_glx_val == -1)
amd_iommu_max_glx_val = glxval;
else
amd_iommu_max_glx_val = min(amd_iommu_max_glx_val, glxval);
}
if (iommu_feature(iommu, FEATURE_GT) &&
iommu_feature(iommu, FEATURE_PPR)) {
iommu->is_iommu_v2 = true;
amd_iommu_v2_present = true;
}
if (iommu_feature(iommu, FEATURE_PPR)) {
iommu->ppr_log = alloc_ppr_log(iommu);
if (!iommu->ppr_log)
return -ENOMEM;
}
if (iommu->cap & (1UL << IOMMU_CAP_NPCACHE))
amd_iommu_np_cache = true;
init_iommu_perf_ctr(iommu);
if (is_rd890_iommu(iommu->dev)) {
int i, j;
iommu->root_pdev = pci_get_bus_and_slot(iommu->dev->bus->number,
PCI_DEVFN(0, 0));
pci_read_config_dword(iommu->dev, iommu->cap_ptr + 4,
&iommu->stored_addr_lo);
pci_read_config_dword(iommu->dev, iommu->cap_ptr + 8,
&iommu->stored_addr_hi);
iommu->stored_addr_lo &= ~1;
for (i = 0; i < 6; i++)
for (j = 0; j < 0x12; j++)
iommu->stored_l1[i][j] = iommu_read_l1(iommu, i, j);
for (i = 0; i < 0x83; i++)
iommu->stored_l2[i] = iommu_read_l2(iommu, i);
}
amd_iommu_erratum_746_workaround(iommu);
iommu->iommu_dev = iommu_device_create(&iommu->dev->dev, iommu,
amd_iommu_groups, "ivhd%d",
iommu->index);
return pci_enable_device(iommu->dev);
}
static void print_iommu_info(void)
{
static const char * const feat_str[] = {
"PreF", "PPR", "X2APIC", "NX", "GT", "[5]",
"IA", "GA", "HE", "PC"
};
struct amd_iommu *iommu;
for_each_iommu(iommu) {
int i;
pr_info("AMD-Vi: Found IOMMU at %s cap 0x%hx\n",
dev_name(&iommu->dev->dev), iommu->cap_ptr);
if (iommu->cap & (1 << IOMMU_CAP_EFR)) {
pr_info("AMD-Vi: Extended features: ");
for (i = 0; i < ARRAY_SIZE(feat_str); ++i) {
if (iommu_feature(iommu, (1ULL << i)))
pr_cont(" %s", feat_str[i]);
}
pr_cont("\n");
}
}
if (irq_remapping_enabled)
pr_info("AMD-Vi: Interrupt remapping enabled\n");
}
static int __init amd_iommu_init_pci(void)
{
struct amd_iommu *iommu;
int ret = 0;
for_each_iommu(iommu) {
ret = iommu_init_pci(iommu);
if (ret)
break;
}
init_device_table_dma();
for_each_iommu(iommu)
iommu_flush_all_caches(iommu);
ret = amd_iommu_init_api();
if (!ret)
print_iommu_info();
return ret;
}
static int iommu_setup_msi(struct amd_iommu *iommu)
{
int r;
r = pci_enable_msi(iommu->dev);
if (r)
return r;
r = request_threaded_irq(iommu->dev->irq,
amd_iommu_int_handler,
amd_iommu_int_thread,
0, "AMD-Vi",
iommu);
if (r) {
pci_disable_msi(iommu->dev);
return r;
}
iommu->int_enabled = true;
return 0;
}
static int iommu_init_msi(struct amd_iommu *iommu)
{
int ret;
if (iommu->int_enabled)
goto enable_faults;
if (iommu->dev->msi_cap)
ret = iommu_setup_msi(iommu);
else
ret = -ENODEV;
if (ret)
return ret;
enable_faults:
iommu_feature_enable(iommu, CONTROL_EVT_INT_EN);
if (iommu->ppr_log != NULL)
iommu_feature_enable(iommu, CONTROL_PPFINT_EN);
return 0;
}
static void __init free_unity_maps(void)
{
struct unity_map_entry *entry, *next;
list_for_each_entry_safe(entry, next, &amd_iommu_unity_map, list) {
list_del(&entry->list);
kfree(entry);
}
}
static int __init init_exclusion_range(struct ivmd_header *m)
{
int i;
switch (m->type) {
case ACPI_IVMD_TYPE:
set_device_exclusion_range(m->devid, m);
break;
case ACPI_IVMD_TYPE_ALL:
for (i = 0; i <= amd_iommu_last_bdf; ++i)
set_device_exclusion_range(i, m);
break;
case ACPI_IVMD_TYPE_RANGE:
for (i = m->devid; i <= m->aux; ++i)
set_device_exclusion_range(i, m);
break;
default:
break;
}
return 0;
}
static int __init init_unity_map_range(struct ivmd_header *m)
{
struct unity_map_entry *e = NULL;
char *s;
e = kzalloc(sizeof(*e), GFP_KERNEL);
if (e == NULL)
return -ENOMEM;
switch (m->type) {
default:
kfree(e);
return 0;
case ACPI_IVMD_TYPE:
s = "IVMD_TYPEi\t\t\t";
e->devid_start = e->devid_end = m->devid;
break;
case ACPI_IVMD_TYPE_ALL:
s = "IVMD_TYPE_ALL\t\t";
e->devid_start = 0;
e->devid_end = amd_iommu_last_bdf;
break;
case ACPI_IVMD_TYPE_RANGE:
s = "IVMD_TYPE_RANGE\t\t";
e->devid_start = m->devid;
e->devid_end = m->aux;
break;
}
e->address_start = PAGE_ALIGN(m->range_start);
e->address_end = e->address_start + PAGE_ALIGN(m->range_length);
e->prot = m->flags >> 1;
DUMP_printk("%s devid_start: %02x:%02x.%x devid_end: %02x:%02x.%x"
" range_start: %016llx range_end: %016llx flags: %x\n", s,
PCI_BUS_NUM(e->devid_start), PCI_SLOT(e->devid_start),
PCI_FUNC(e->devid_start), PCI_BUS_NUM(e->devid_end),
PCI_SLOT(e->devid_end), PCI_FUNC(e->devid_end),
e->address_start, e->address_end, m->flags);
list_add_tail(&e->list, &amd_iommu_unity_map);
return 0;
}
static int __init init_memory_definitions(struct acpi_table_header *table)
{
u8 *p = (u8 *)table, *end = (u8 *)table;
struct ivmd_header *m;
end += table->length;
p += IVRS_HEADER_LENGTH;
while (p < end) {
m = (struct ivmd_header *)p;
if (m->flags & IVMD_FLAG_EXCL_RANGE)
init_exclusion_range(m);
else if (m->flags & IVMD_FLAG_UNITY_MAP)
init_unity_map_range(m);
p += m->length;
}
return 0;
}
static void init_device_table_dma(void)
{
u32 devid;
for (devid = 0; devid <= amd_iommu_last_bdf; ++devid) {
set_dev_entry_bit(devid, DEV_ENTRY_VALID);
set_dev_entry_bit(devid, DEV_ENTRY_TRANSLATION);
}
}
static void __init uninit_device_table_dma(void)
{
u32 devid;
for (devid = 0; devid <= amd_iommu_last_bdf; ++devid) {
amd_iommu_dev_table[devid].data[0] = 0ULL;
amd_iommu_dev_table[devid].data[1] = 0ULL;
}
}
static void init_device_table(void)
{
u32 devid;
if (!amd_iommu_irq_remap)
return;
for (devid = 0; devid <= amd_iommu_last_bdf; ++devid)
set_dev_entry_bit(devid, DEV_ENTRY_IRQ_TBL_EN);
}
static void iommu_init_flags(struct amd_iommu *iommu)
{
iommu->acpi_flags & IVHD_FLAG_HT_TUN_EN_MASK ?
iommu_feature_enable(iommu, CONTROL_HT_TUN_EN) :
iommu_feature_disable(iommu, CONTROL_HT_TUN_EN);
iommu->acpi_flags & IVHD_FLAG_PASSPW_EN_MASK ?
iommu_feature_enable(iommu, CONTROL_PASSPW_EN) :
iommu_feature_disable(iommu, CONTROL_PASSPW_EN);
iommu->acpi_flags & IVHD_FLAG_RESPASSPW_EN_MASK ?
iommu_feature_enable(iommu, CONTROL_RESPASSPW_EN) :
iommu_feature_disable(iommu, CONTROL_RESPASSPW_EN);
iommu->acpi_flags & IVHD_FLAG_ISOC_EN_MASK ?
iommu_feature_enable(iommu, CONTROL_ISOC_EN) :
iommu_feature_disable(iommu, CONTROL_ISOC_EN);
iommu_feature_enable(iommu, CONTROL_COHERENT_EN);
iommu_set_inv_tlb_timeout(iommu, CTRL_INV_TO_1S);
}
static void iommu_apply_resume_quirks(struct amd_iommu *iommu)
{
int i, j;
u32 ioc_feature_control;
struct pci_dev *pdev = iommu->root_pdev;
if (!is_rd890_iommu(iommu->dev) || !pdev)
return;
pci_write_config_dword(pdev, 0x60, 0x75 | (1 << 7));
pci_read_config_dword(pdev, 0x64, &ioc_feature_control);
if (!(ioc_feature_control & 0x1))
pci_write_config_dword(pdev, 0x64, ioc_feature_control | 1);
pci_write_config_dword(iommu->dev, iommu->cap_ptr + 4,
iommu->stored_addr_lo);
pci_write_config_dword(iommu->dev, iommu->cap_ptr + 8,
iommu->stored_addr_hi);
for (i = 0; i < 6; i++)
for (j = 0; j < 0x12; j++)
iommu_write_l1(iommu, i, j, iommu->stored_l1[i][j]);
for (i = 0; i < 0x83; i++)
iommu_write_l2(iommu, i, iommu->stored_l2[i]);
pci_write_config_dword(iommu->dev, iommu->cap_ptr + 4,
iommu->stored_addr_lo | 1);
}
static void early_enable_iommus(void)
{
struct amd_iommu *iommu;
for_each_iommu(iommu) {
iommu_disable(iommu);
iommu_init_flags(iommu);
iommu_set_device_table(iommu);
iommu_enable_command_buffer(iommu);
iommu_enable_event_buffer(iommu);
iommu_set_exclusion_range(iommu);
iommu_enable(iommu);
iommu_flush_all_caches(iommu);
}
}
static void enable_iommus_v2(void)
{
struct amd_iommu *iommu;
for_each_iommu(iommu) {
iommu_enable_ppr_log(iommu);
iommu_enable_gt(iommu);
}
}
static void enable_iommus(void)
{
early_enable_iommus();
enable_iommus_v2();
}
static void disable_iommus(void)
{
struct amd_iommu *iommu;
for_each_iommu(iommu)
iommu_disable(iommu);
}
static void amd_iommu_resume(void)
{
struct amd_iommu *iommu;
for_each_iommu(iommu)
iommu_apply_resume_quirks(iommu);
enable_iommus();
amd_iommu_enable_interrupts();
}
static int amd_iommu_suspend(void)
{
disable_iommus();
return 0;
}
static void __init free_on_init_error(void)
{
free_pages((unsigned long)irq_lookup_table,
get_order(rlookup_table_size));
if (amd_iommu_irq_cache) {
kmem_cache_destroy(amd_iommu_irq_cache);
amd_iommu_irq_cache = NULL;
}
free_pages((unsigned long)amd_iommu_rlookup_table,
get_order(rlookup_table_size));
free_pages((unsigned long)amd_iommu_alias_table,
get_order(alias_table_size));
free_pages((unsigned long)amd_iommu_dev_table,
get_order(dev_table_size));
free_iommu_all();
#ifdef CONFIG_GART_IOMMU
gart_iommu_init();
#endif
}
static bool __init check_ioapic_information(void)
{
const char *fw_bug = FW_BUG;
bool ret, has_sb_ioapic;
int idx;
has_sb_ioapic = false;
ret = false;
if (cmdline_maps)
fw_bug = "";
for (idx = 0; idx < nr_ioapics; idx++) {
int devid, id = mpc_ioapic_id(idx);
devid = get_ioapic_devid(id);
if (devid < 0) {
pr_err("%sAMD-Vi: IOAPIC[%d] not in IVRS table\n",
fw_bug, id);
ret = false;
} else if (devid == IOAPIC_SB_DEVID) {
has_sb_ioapic = true;
ret = true;
}
}
if (!has_sb_ioapic) {
pr_err("%sAMD-Vi: No southbridge IOAPIC found\n", fw_bug);
}
if (!ret)
pr_err("AMD-Vi: Disabling interrupt remapping\n");
return ret;
}
static void __init free_dma_resources(void)
{
free_pages((unsigned long)amd_iommu_pd_alloc_bitmap,
get_order(MAX_DOMAIN_ID/8));
free_unity_maps();
}
static int __init early_amd_iommu_init(void)
{
struct acpi_table_header *ivrs_base;
acpi_size ivrs_size;
acpi_status status;
int i, ret = 0;
if (!amd_iommu_detected)
return -ENODEV;
status = acpi_get_table_with_size("IVRS", 0, &ivrs_base, &ivrs_size);
if (status == AE_NOT_FOUND)
return -ENODEV;
else if (ACPI_FAILURE(status)) {
const char *err = acpi_format_exception(status);
pr_err("AMD-Vi: IVRS table error: %s\n", err);
return -EINVAL;
}
ret = find_last_devid_acpi(ivrs_base);
if (ret)
goto out;
dev_table_size = tbl_size(DEV_TABLE_ENTRY_SIZE);
alias_table_size = tbl_size(ALIAS_TABLE_ENTRY_SIZE);
rlookup_table_size = tbl_size(RLOOKUP_TABLE_ENTRY_SIZE);
ret = -ENOMEM;
amd_iommu_dev_table = (void *)__get_free_pages(GFP_KERNEL | __GFP_ZERO,
get_order(dev_table_size));
if (amd_iommu_dev_table == NULL)
goto out;
amd_iommu_alias_table = (void *)__get_free_pages(GFP_KERNEL,
get_order(alias_table_size));
if (amd_iommu_alias_table == NULL)
goto out;
amd_iommu_rlookup_table = (void *)__get_free_pages(
GFP_KERNEL | __GFP_ZERO,
get_order(rlookup_table_size));
if (amd_iommu_rlookup_table == NULL)
goto out;
amd_iommu_pd_alloc_bitmap = (void *)__get_free_pages(
GFP_KERNEL | __GFP_ZERO,
get_order(MAX_DOMAIN_ID/8));
if (amd_iommu_pd_alloc_bitmap == NULL)
goto out;
for (i = 0; i <= amd_iommu_last_bdf; ++i)
amd_iommu_alias_table[i] = i;
amd_iommu_pd_alloc_bitmap[0] = 1;
spin_lock_init(&amd_iommu_pd_lock);
ret = init_iommu_all(ivrs_base);
if (ret)
goto out;
if (amd_iommu_irq_remap)
amd_iommu_irq_remap = check_ioapic_information();
if (amd_iommu_irq_remap) {
ret = -ENOMEM;
amd_iommu_irq_cache = kmem_cache_create("irq_remap_cache",
MAX_IRQS_PER_TABLE * sizeof(u32),
IRQ_TABLE_ALIGNMENT,
0, NULL);
if (!amd_iommu_irq_cache)
goto out;
irq_lookup_table = (void *)__get_free_pages(
GFP_KERNEL | __GFP_ZERO,
get_order(rlookup_table_size));
if (!irq_lookup_table)
goto out;
}
ret = init_memory_definitions(ivrs_base);
if (ret)
goto out;
init_device_table();
out:
early_acpi_os_unmap_memory((char __iomem *)ivrs_base, ivrs_size);
ivrs_base = NULL;
return ret;
}
static int amd_iommu_enable_interrupts(void)
{
struct amd_iommu *iommu;
int ret = 0;
for_each_iommu(iommu) {
ret = iommu_init_msi(iommu);
if (ret)
goto out;
}
out:
return ret;
}
static bool detect_ivrs(void)
{
struct acpi_table_header *ivrs_base;
acpi_size ivrs_size;
acpi_status status;
status = acpi_get_table_with_size("IVRS", 0, &ivrs_base, &ivrs_size);
if (status == AE_NOT_FOUND)
return false;
else if (ACPI_FAILURE(status)) {
const char *err = acpi_format_exception(status);
pr_err("AMD-Vi: IVRS table error: %s\n", err);
return false;
}
early_acpi_os_unmap_memory((char __iomem *)ivrs_base, ivrs_size);
pci_request_acs();
return true;
}
static int __init state_next(void)
{
int ret = 0;
switch (init_state) {
case IOMMU_START_STATE:
if (!detect_ivrs()) {
init_state = IOMMU_NOT_FOUND;
ret = -ENODEV;
} else {
init_state = IOMMU_IVRS_DETECTED;
}
break;
case IOMMU_IVRS_DETECTED:
ret = early_amd_iommu_init();
init_state = ret ? IOMMU_INIT_ERROR : IOMMU_ACPI_FINISHED;
break;
case IOMMU_ACPI_FINISHED:
early_enable_iommus();
register_syscore_ops(&amd_iommu_syscore_ops);
x86_platform.iommu_shutdown = disable_iommus;
init_state = IOMMU_ENABLED;
break;
case IOMMU_ENABLED:
ret = amd_iommu_init_pci();
init_state = ret ? IOMMU_INIT_ERROR : IOMMU_PCI_INIT;
enable_iommus_v2();
break;
case IOMMU_PCI_INIT:
ret = amd_iommu_enable_interrupts();
init_state = ret ? IOMMU_INIT_ERROR : IOMMU_INTERRUPTS_EN;
break;
case IOMMU_INTERRUPTS_EN:
ret = amd_iommu_init_dma_ops();
init_state = ret ? IOMMU_INIT_ERROR : IOMMU_DMA_OPS;
break;
case IOMMU_DMA_OPS:
init_state = IOMMU_INITIALIZED;
break;
case IOMMU_INITIALIZED:
break;
case IOMMU_NOT_FOUND:
case IOMMU_INIT_ERROR:
ret = -EINVAL;
break;
default:
BUG();
}
return ret;
}
static int __init iommu_go_to_state(enum iommu_init_state state)
{
int ret = 0;
while (init_state != state) {
ret = state_next();
if (init_state == IOMMU_NOT_FOUND ||
init_state == IOMMU_INIT_ERROR)
break;
}
return ret;
}
int __init amd_iommu_prepare(void)
{
int ret;
amd_iommu_irq_remap = true;
ret = iommu_go_to_state(IOMMU_ACPI_FINISHED);
if (ret)
return ret;
return amd_iommu_irq_remap ? 0 : -ENODEV;
}
int __init amd_iommu_enable(void)
{
int ret;
ret = iommu_go_to_state(IOMMU_ENABLED);
if (ret)
return ret;
irq_remapping_enabled = 1;
return 0;
}
void amd_iommu_disable(void)
{
amd_iommu_suspend();
}
int amd_iommu_reenable(int mode)
{
amd_iommu_resume();
return 0;
}
int __init amd_iommu_enable_faulting(void)
{
return 0;
}
static int __init amd_iommu_init(void)
{
int ret;
ret = iommu_go_to_state(IOMMU_INITIALIZED);
if (ret) {
free_dma_resources();
if (!irq_remapping_enabled) {
disable_iommus();
free_on_init_error();
} else {
struct amd_iommu *iommu;
uninit_device_table_dma();
for_each_iommu(iommu)
iommu_flush_all_caches(iommu);
}
}
return ret;
}
int __init amd_iommu_detect(void)
{
int ret;
if (no_iommu || (iommu_detected && !gart_iommu_aperture))
return -ENODEV;
if (amd_iommu_disabled)
return -ENODEV;
ret = iommu_go_to_state(IOMMU_IVRS_DETECTED);
if (ret)
return ret;
amd_iommu_detected = true;
iommu_detected = 1;
x86_init.iommu.iommu_init = amd_iommu_init;
return 0;
}
static int __init parse_amd_iommu_dump(char *str)
{
amd_iommu_dump = true;
return 1;
}
static int __init parse_amd_iommu_options(char *str)
{
for (; *str; ++str) {
if (strncmp(str, "fullflush", 9) == 0)
amd_iommu_unmap_flush = true;
if (strncmp(str, "off", 3) == 0)
amd_iommu_disabled = true;
if (strncmp(str, "force_isolation", 15) == 0)
amd_iommu_force_isolation = true;
}
return 1;
}
static int __init parse_ivrs_ioapic(char *str)
{
unsigned int bus, dev, fn;
int ret, id, i;
u16 devid;
ret = sscanf(str, "[%d]=%x:%x.%x", &id, &bus, &dev, &fn);
if (ret != 4) {
pr_err("AMD-Vi: Invalid command line: ivrs_ioapic%s\n", str);
return 1;
}
if (early_ioapic_map_size == EARLY_MAP_SIZE) {
pr_err("AMD-Vi: Early IOAPIC map overflow - ignoring ivrs_ioapic%s\n",
str);
return 1;
}
devid = ((bus & 0xff) << 8) | ((dev & 0x1f) << 3) | (fn & 0x7);
cmdline_maps = true;
i = early_ioapic_map_size++;
early_ioapic_map[i].id = id;
early_ioapic_map[i].devid = devid;
early_ioapic_map[i].cmd_line = true;
return 1;
}
static int __init parse_ivrs_hpet(char *str)
{
unsigned int bus, dev, fn;
int ret, id, i;
u16 devid;
ret = sscanf(str, "[%d]=%x:%x.%x", &id, &bus, &dev, &fn);
if (ret != 4) {
pr_err("AMD-Vi: Invalid command line: ivrs_hpet%s\n", str);
return 1;
}
if (early_hpet_map_size == EARLY_MAP_SIZE) {
pr_err("AMD-Vi: Early HPET map overflow - ignoring ivrs_hpet%s\n",
str);
return 1;
}
devid = ((bus & 0xff) << 8) | ((dev & 0x1f) << 3) | (fn & 0x7);
cmdline_maps = true;
i = early_hpet_map_size++;
early_hpet_map[i].id = id;
early_hpet_map[i].devid = devid;
early_hpet_map[i].cmd_line = true;
return 1;
}
bool amd_iommu_v2_supported(void)
{
return amd_iommu_v2_present;
}
u8 amd_iommu_pc_get_max_banks(u16 devid)
{
struct amd_iommu *iommu;
u8 ret = 0;
iommu = amd_iommu_rlookup_table[devid];
if (iommu)
ret = iommu->max_banks;
return ret;
}
bool amd_iommu_pc_supported(void)
{
return amd_iommu_pc_present;
}
u8 amd_iommu_pc_get_max_counters(u16 devid)
{
struct amd_iommu *iommu;
u8 ret = 0;
iommu = amd_iommu_rlookup_table[devid];
if (iommu)
ret = iommu->max_counters;
return ret;
}
int amd_iommu_pc_get_set_reg_val(u16 devid, u8 bank, u8 cntr, u8 fxn,
u64 *value, bool is_write)
{
struct amd_iommu *iommu;
u32 offset;
u32 max_offset_lim;
if (!amd_iommu_pc_present)
return -ENODEV;
iommu = amd_iommu_rlookup_table[devid];
if (WARN_ON((iommu == NULL) || (fxn > 0x28) || (fxn & 7)))
return -ENODEV;
offset = (u32)(((0x40|bank) << 12) | (cntr << 8) | fxn);
max_offset_lim = (u32)(((0x40|iommu->max_banks) << 12) |
(iommu->max_counters << 8) | 0x28);
if ((offset < MMIO_CNTR_REG_OFFSET) ||
(offset > max_offset_lim))
return -EINVAL;
if (is_write) {
writel((u32)*value, iommu->mmio_base + offset);
writel((*value >> 32), iommu->mmio_base + offset + 4);
} else {
*value = readl(iommu->mmio_base + offset + 4);
*value <<= 32;
*value = readl(iommu->mmio_base + offset);
}
return 0;
}
