static inline u16 get_device_id(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
return calc_devid(pdev->bus->number, pdev->devfn);
}
static struct iommu_dev_data *get_dev_data(struct device *dev)
{
return dev->archdata.iommu;
}
static struct dma_ops_domain *find_protection_domain(u16 devid)
{
struct dma_ops_domain *entry, *ret = NULL;
unsigned long flags;
u16 alias = amd_iommu_alias_table[devid];
if (list_empty(&iommu_pd_list))
return NULL;
spin_lock_irqsave(&iommu_pd_list_lock, flags);
list_for_each_entry(entry, &iommu_pd_list, list) {
if (entry->target_dev == devid ||
entry->target_dev == alias) {
ret = entry;
break;
}
}
spin_unlock_irqrestore(&iommu_pd_list_lock, flags);
return ret;
}
static bool check_device(struct device *dev)
{
u16 devid;
if (!dev || !dev->dma_mask)
return false;
if (dev->bus != &pci_bus_type)
return false;
devid = get_device_id(dev);
if (devid > amd_iommu_last_bdf)
return false;
if (amd_iommu_rlookup_table[devid] == NULL)
return false;
return true;
}
static int iommu_init_device(struct device *dev)
{
struct iommu_dev_data *dev_data;
struct pci_dev *pdev;
u16 devid, alias;
if (dev->archdata.iommu)
return 0;
dev_data = kzalloc(sizeof(*dev_data), GFP_KERNEL);
if (!dev_data)
return -ENOMEM;
dev_data->dev = dev;
devid = get_device_id(dev);
alias = amd_iommu_alias_table[devid];
pdev = pci_get_bus_and_slot(PCI_BUS(alias), alias & 0xff);
if (pdev)
dev_data->alias = &pdev->dev;
else {
kfree(dev_data);
return -ENOTSUPP;
}
atomic_set(&dev_data->bind, 0);
dev->archdata.iommu = dev_data;
return 0;
}
static void iommu_ignore_device(struct device *dev)
{
u16 devid, alias;
devid = get_device_id(dev);
alias = amd_iommu_alias_table[devid];
memset(&amd_iommu_dev_table[devid], 0, sizeof(struct dev_table_entry));
memset(&amd_iommu_dev_table[alias], 0, sizeof(struct dev_table_entry));
amd_iommu_rlookup_table[devid] = NULL;
amd_iommu_rlookup_table[alias] = NULL;
}
static void iommu_uninit_device(struct device *dev)
{
kfree(dev->archdata.iommu);
}
void __init amd_iommu_uninit_devices(void)
{
struct pci_dev *pdev = NULL;
for_each_pci_dev(pdev) {
if (!check_device(&pdev->dev))
continue;
iommu_uninit_device(&pdev->dev);
}
}
int __init amd_iommu_init_devices(void)
{
struct pci_dev *pdev = NULL;
int ret = 0;
for_each_pci_dev(pdev) {
if (!check_device(&pdev->dev))
continue;
ret = iommu_init_device(&pdev->dev);
if (ret == -ENOTSUPP)
iommu_ignore_device(&pdev->dev);
else if (ret)
goto out_free;
}
return 0;
out_free:
amd_iommu_uninit_devices();
return ret;
}
static void amd_iommu_stats_add(struct __iommu_counter *cnt)
{
if (stats_dir == NULL)
return;
cnt->dent = debugfs_create_u64(cnt->name, 0444, stats_dir,
&cnt->value);
}
static void amd_iommu_stats_init(void)
{
stats_dir = debugfs_create_dir("amd-iommu", NULL);
if (stats_dir == NULL)
return;
de_fflush = debugfs_create_bool("fullflush", 0444, stats_dir,
(u32 *)&amd_iommu_unmap_flush);
amd_iommu_stats_add(&compl_wait);
amd_iommu_stats_add(&cnt_map_single);
amd_iommu_stats_add(&cnt_unmap_single);
amd_iommu_stats_add(&cnt_map_sg);
amd_iommu_stats_add(&cnt_unmap_sg);
amd_iommu_stats_add(&cnt_alloc_coherent);
amd_iommu_stats_add(&cnt_free_coherent);
amd_iommu_stats_add(&cross_page);
amd_iommu_stats_add(&domain_flush_single);
amd_iommu_stats_add(&domain_flush_all);
amd_iommu_stats_add(&alloced_io_mem);
amd_iommu_stats_add(&total_map_requests);
}
static void dump_dte_entry(u16 devid)
{
int i;
for (i = 0; i < 8; ++i)
pr_err("AMD-Vi: DTE[%d]: %08x\n", i,
amd_iommu_dev_table[devid].data[i]);
}
static void dump_command(unsigned long phys_addr)
{
struct iommu_cmd *cmd = phys_to_virt(phys_addr);
int i;
for (i = 0; i < 4; ++i)
pr_err("AMD-Vi: CMD[%d]: %08x\n", i, cmd->data[i]);
}
static void iommu_print_event(struct amd_iommu *iommu, void *__evt)
{
u32 *event = __evt;
int type = (event[1] >> EVENT_TYPE_SHIFT) & EVENT_TYPE_MASK;
int devid = (event[0] >> EVENT_DEVID_SHIFT) & EVENT_DEVID_MASK;
int domid = (event[1] >> EVENT_DOMID_SHIFT) & EVENT_DOMID_MASK;
int flags = (event[1] >> EVENT_FLAGS_SHIFT) & EVENT_FLAGS_MASK;
u64 address = (u64)(((u64)event[3]) << 32) | event[2];
printk(KERN_ERR "AMD-Vi: Event logged [");
switch (type) {
case EVENT_TYPE_ILL_DEV:
printk("ILLEGAL_DEV_TABLE_ENTRY device=%02x:%02x.%x "
"address=0x%016llx flags=0x%04x]\n",
PCI_BUS(devid), PCI_SLOT(devid), PCI_FUNC(devid),
address, flags);
dump_dte_entry(devid);
break;
case EVENT_TYPE_IO_FAULT:
printk("IO_PAGE_FAULT device=%02x:%02x.%x "
"domain=0x%04x address=0x%016llx flags=0x%04x]\n",
PCI_BUS(devid), PCI_SLOT(devid), PCI_FUNC(devid),
domid, address, flags);
break;
case EVENT_TYPE_DEV_TAB_ERR:
printk("DEV_TAB_HARDWARE_ERROR device=%02x:%02x.%x "
"address=0x%016llx flags=0x%04x]\n",
PCI_BUS(devid), PCI_SLOT(devid), PCI_FUNC(devid),
address, flags);
break;
case EVENT_TYPE_PAGE_TAB_ERR:
printk("PAGE_TAB_HARDWARE_ERROR device=%02x:%02x.%x "
"domain=0x%04x address=0x%016llx flags=0x%04x]\n",
PCI_BUS(devid), PCI_SLOT(devid), PCI_FUNC(devid),
domid, address, flags);
break;
case EVENT_TYPE_ILL_CMD:
printk("ILLEGAL_COMMAND_ERROR address=0x%016llx]\n", address);
dump_command(address);
break;
case EVENT_TYPE_CMD_HARD_ERR:
printk("COMMAND_HARDWARE_ERROR address=0x%016llx "
"flags=0x%04x]\n", address, flags);
break;
case EVENT_TYPE_IOTLB_INV_TO:
printk("IOTLB_INV_TIMEOUT device=%02x:%02x.%x "
"address=0x%016llx]\n",
PCI_BUS(devid), PCI_SLOT(devid), PCI_FUNC(devid),
address);
break;
case EVENT_TYPE_INV_DEV_REQ:
printk("INVALID_DEVICE_REQUEST device=%02x:%02x.%x "
"address=0x%016llx flags=0x%04x]\n",
PCI_BUS(devid), PCI_SLOT(devid), PCI_FUNC(devid),
address, flags);
break;
default:
printk(KERN_ERR "UNKNOWN type=0x%02x]\n", type);
}
}
static void iommu_poll_events(struct amd_iommu *iommu)
{
u32 head, tail;
unsigned long flags;
spin_lock_irqsave(&iommu->lock, flags);
head = readl(iommu->mmio_base + MMIO_EVT_HEAD_OFFSET);
tail = readl(iommu->mmio_base + MMIO_EVT_TAIL_OFFSET);
while (head != tail) {
iommu_print_event(iommu, iommu->evt_buf + head);
head = (head + EVENT_ENTRY_SIZE) % iommu->evt_buf_size;
}
writel(head, iommu->mmio_base + MMIO_EVT_HEAD_OFFSET);
spin_unlock_irqrestore(&iommu->lock, flags);
}
irqreturn_t amd_iommu_int_thread(int irq, void *data)
{
struct amd_iommu *iommu;
for_each_iommu(iommu)
iommu_poll_events(iommu);
return IRQ_HANDLED;
}
irqreturn_t amd_iommu_int_handler(int irq, void *data)
{
return IRQ_WAKE_THREAD;
}
static int wait_on_sem(volatile u64 *sem)
{
int i = 0;
while (*sem == 0 && i < LOOP_TIMEOUT) {
udelay(1);
i += 1;
}
if (i == LOOP_TIMEOUT) {
pr_alert("AMD-Vi: Completion-Wait loop timed out\n");
return -EIO;
}
return 0;
}
static void copy_cmd_to_buffer(struct amd_iommu *iommu,
struct iommu_cmd *cmd,
u32 tail)
{
u8 *target;
target = iommu->cmd_buf + tail;
tail = (tail + sizeof(*cmd)) % iommu->cmd_buf_size;
memcpy(target, cmd, sizeof(*cmd));
writel(tail, iommu->mmio_base + MMIO_CMD_TAIL_OFFSET);
}
static void build_completion_wait(struct iommu_cmd *cmd, u64 address)
{
WARN_ON(address & 0x7ULL);
memset(cmd, 0, sizeof(*cmd));
cmd->data[0] = lower_32_bits(__pa(address)) | CMD_COMPL_WAIT_STORE_MASK;
cmd->data[1] = upper_32_bits(__pa(address));
cmd->data[2] = 1;
CMD_SET_TYPE(cmd, CMD_COMPL_WAIT);
}
static void build_inv_dte(struct iommu_cmd *cmd, u16 devid)
{
memset(cmd, 0, sizeof(*cmd));
cmd->data[0] = devid;
CMD_SET_TYPE(cmd, CMD_INV_DEV_ENTRY);
}
static void build_inv_iommu_pages(struct iommu_cmd *cmd, u64 address,
size_t size, u16 domid, int pde)
{
u64 pages;
int s;
pages = iommu_num_pages(address, size, PAGE_SIZE);
s = 0;
if (pages > 1) {
address = CMD_INV_IOMMU_ALL_PAGES_ADDRESS;
s = 1;
}
address &= PAGE_MASK;
memset(cmd, 0, sizeof(*cmd));
cmd->data[1] |= domid;
cmd->data[2] = lower_32_bits(address);
cmd->data[3] = upper_32_bits(address);
CMD_SET_TYPE(cmd, CMD_INV_IOMMU_PAGES);
if (s)
cmd->data[2] |= CMD_INV_IOMMU_PAGES_SIZE_MASK;
if (pde)
cmd->data[2] |= CMD_INV_IOMMU_PAGES_PDE_MASK;
}
static void build_inv_iotlb_pages(struct iommu_cmd *cmd, u16 devid, int qdep,
u64 address, size_t size)
{
u64 pages;
int s;
pages = iommu_num_pages(address, size, PAGE_SIZE);
s = 0;
if (pages > 1) {
address = CMD_INV_IOMMU_ALL_PAGES_ADDRESS;
s = 1;
}
address &= PAGE_MASK;
memset(cmd, 0, sizeof(*cmd));
cmd->data[0] = devid;
cmd->data[0] |= (qdep & 0xff) << 24;
cmd->data[1] = devid;
cmd->data[2] = lower_32_bits(address);
cmd->data[3] = upper_32_bits(address);
CMD_SET_TYPE(cmd, CMD_INV_IOTLB_PAGES);
if (s)
cmd->data[2] |= CMD_INV_IOMMU_PAGES_SIZE_MASK;
}
static void build_inv_all(struct iommu_cmd *cmd)
{
memset(cmd, 0, sizeof(*cmd));
CMD_SET_TYPE(cmd, CMD_INV_ALL);
}
static int iommu_queue_command(struct amd_iommu *iommu, struct iommu_cmd *cmd)
{
u32 left, tail, head, next_tail;
unsigned long flags;
WARN_ON(iommu->cmd_buf_size & CMD_BUFFER_UNINITIALIZED);
again:
spin_lock_irqsave(&iommu->lock, flags);
head = readl(iommu->mmio_base + MMIO_CMD_HEAD_OFFSET);
tail = readl(iommu->mmio_base + MMIO_CMD_TAIL_OFFSET);
next_tail = (tail + sizeof(*cmd)) % iommu->cmd_buf_size;
left = (head - next_tail) % iommu->cmd_buf_size;
if (left <= 2) {
struct iommu_cmd sync_cmd;
volatile u64 sem = 0;
int ret;
build_completion_wait(&sync_cmd, (u64)&sem);
copy_cmd_to_buffer(iommu, &sync_cmd, tail);
spin_unlock_irqrestore(&iommu->lock, flags);
if ((ret = wait_on_sem(&sem)) != 0)
return ret;
goto again;
}
copy_cmd_to_buffer(iommu, cmd, tail);
iommu->need_sync = true;
spin_unlock_irqrestore(&iommu->lock, flags);
return 0;
}
static int iommu_completion_wait(struct amd_iommu *iommu)
{
struct iommu_cmd cmd;
volatile u64 sem = 0;
int ret;
if (!iommu->need_sync)
return 0;
build_completion_wait(&cmd, (u64)&sem);
ret = iommu_queue_command(iommu, &cmd);
if (ret)
return ret;
return wait_on_sem(&sem);
}
static int iommu_flush_dte(struct amd_iommu *iommu, u16 devid)
{
struct iommu_cmd cmd;
build_inv_dte(&cmd, devid);
return iommu_queue_command(iommu, &cmd);
}
static void iommu_flush_dte_all(struct amd_iommu *iommu)
{
u32 devid;
for (devid = 0; devid <= 0xffff; ++devid)
iommu_flush_dte(iommu, devid);
iommu_completion_wait(iommu);
}
static void iommu_flush_tlb_all(struct amd_iommu *iommu)
{
u32 dom_id;
for (dom_id = 0; dom_id <= 0xffff; ++dom_id) {
struct iommu_cmd cmd;
build_inv_iommu_pages(&cmd, 0, CMD_INV_IOMMU_ALL_PAGES_ADDRESS,
dom_id, 1);
iommu_queue_command(iommu, &cmd);
}
iommu_completion_wait(iommu);
}
static void iommu_flush_all(struct amd_iommu *iommu)
{
struct iommu_cmd cmd;
build_inv_all(&cmd);
iommu_queue_command(iommu, &cmd);
iommu_completion_wait(iommu);
}
void iommu_flush_all_caches(struct amd_iommu *iommu)
{
if (iommu_feature(iommu, FEATURE_IA)) {
iommu_flush_all(iommu);
} else {
iommu_flush_dte_all(iommu);
iommu_flush_tlb_all(iommu);
}
}
static int device_flush_iotlb(struct device *dev, u64 address, size_t size)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct amd_iommu *iommu;
struct iommu_cmd cmd;
u16 devid;
int qdep;
qdep = pci_ats_queue_depth(pdev);
devid = get_device_id(dev);
iommu = amd_iommu_rlookup_table[devid];
build_inv_iotlb_pages(&cmd, devid, qdep, address, size);
return iommu_queue_command(iommu, &cmd);
}
static int device_flush_dte(struct device *dev)
{
struct amd_iommu *iommu;
struct pci_dev *pdev;
u16 devid;
int ret;
pdev = to_pci_dev(dev);
devid = get_device_id(dev);
iommu = amd_iommu_rlookup_table[devid];
ret = iommu_flush_dte(iommu, devid);
if (ret)
return ret;
if (pci_ats_enabled(pdev))
ret = device_flush_iotlb(dev, 0, ~0UL);
return ret;
}
static void __domain_flush_pages(struct protection_domain *domain,
u64 address, size_t size, int pde)
{
struct iommu_dev_data *dev_data;
struct iommu_cmd cmd;
int ret = 0, i;
build_inv_iommu_pages(&cmd, address, size, domain->id, pde);
for (i = 0; i < amd_iommus_present; ++i) {
if (!domain->dev_iommu[i])
continue;
ret |= iommu_queue_command(amd_iommus[i], &cmd);
}
list_for_each_entry(dev_data, &domain->dev_list, list) {
struct pci_dev *pdev = to_pci_dev(dev_data->dev);
if (!pci_ats_enabled(pdev))
continue;
ret |= device_flush_iotlb(dev_data->dev, address, size);
}
WARN_ON(ret);
}
static void domain_flush_pages(struct protection_domain *domain,
u64 address, size_t size)
{
__domain_flush_pages(domain, address, size, 0);
}
static void domain_flush_tlb(struct protection_domain *domain)
{
__domain_flush_pages(domain, 0, CMD_INV_IOMMU_ALL_PAGES_ADDRESS, 0);
}
static void domain_flush_tlb_pde(struct protection_domain *domain)
{
__domain_flush_pages(domain, 0, CMD_INV_IOMMU_ALL_PAGES_ADDRESS, 1);
}
static void domain_flush_complete(struct protection_domain *domain)
{
int i;
for (i = 0; i < amd_iommus_present; ++i) {
if (!domain->dev_iommu[i])
continue;
iommu_completion_wait(amd_iommus[i]);
}
}
static void domain_flush_devices(struct protection_domain *domain)
{
struct iommu_dev_data *dev_data;
unsigned long flags;
spin_lock_irqsave(&domain->lock, flags);
list_for_each_entry(dev_data, &domain->dev_list, list)
device_flush_dte(dev_data->dev);
spin_unlock_irqrestore(&domain->lock, flags);
}
static bool increase_address_space(struct protection_domain *domain,
gfp_t gfp)
{
u64 *pte;
if (domain->mode == PAGE_MODE_6_LEVEL)
return false;
pte = (void *)get_zeroed_page(gfp);
if (!pte)
return false;
*pte = PM_LEVEL_PDE(domain->mode,
virt_to_phys(domain->pt_root));
domain->pt_root = pte;
domain->mode += 1;
domain->updated = true;
return true;
}
static u64 *alloc_pte(struct protection_domain *domain,
unsigned long address,
unsigned long page_size,
u64 **pte_page,
gfp_t gfp)
{
int level, end_lvl;
u64 *pte, *page;
BUG_ON(!is_power_of_2(page_size));
while (address > PM_LEVEL_SIZE(domain->mode))
increase_address_space(domain, gfp);
level = domain->mode - 1;
pte = &domain->pt_root[PM_LEVEL_INDEX(level, address)];
address = PAGE_SIZE_ALIGN(address, page_size);
end_lvl = PAGE_SIZE_LEVEL(page_size);
while (level > end_lvl) {
if (!IOMMU_PTE_PRESENT(*pte)) {
page = (u64 *)get_zeroed_page(gfp);
if (!page)
return NULL;
*pte = PM_LEVEL_PDE(level, virt_to_phys(page));
}
if (PM_PTE_LEVEL(*pte) != level)
return NULL;
level -= 1;
pte = IOMMU_PTE_PAGE(*pte);
if (pte_page && level == end_lvl)
*pte_page = pte;
pte = &pte[PM_LEVEL_INDEX(level, address)];
}
return pte;
}
static u64 *fetch_pte(struct protection_domain *domain, unsigned long address)
{
int level;
u64 *pte;
if (address > PM_LEVEL_SIZE(domain->mode))
return NULL;
level = domain->mode - 1;
pte = &domain->pt_root[PM_LEVEL_INDEX(level, address)];
while (level > 0) {
if (!IOMMU_PTE_PRESENT(*pte))
return NULL;
if (PM_PTE_LEVEL(*pte) == 0x07) {
unsigned long pte_mask, __pte;
pte_mask = PTE_PAGE_SIZE(*pte);
pte_mask = ~((PAGE_SIZE_PTE_COUNT(pte_mask) << 3) - 1);
__pte = ((unsigned long)pte) & pte_mask;
return (u64 *)__pte;
}
if (PM_PTE_LEVEL(*pte) != level)
return NULL;
level -= 1;
pte = IOMMU_PTE_PAGE(*pte);
pte = &pte[PM_LEVEL_INDEX(level, address)];
}
return pte;
}
static int iommu_map_page(struct protection_domain *dom,
unsigned long bus_addr,
unsigned long phys_addr,
int prot,
unsigned long page_size)
{
u64 __pte, *pte;
int i, count;
if (!(prot & IOMMU_PROT_MASK))
return -EINVAL;
bus_addr = PAGE_ALIGN(bus_addr);
phys_addr = PAGE_ALIGN(phys_addr);
count = PAGE_SIZE_PTE_COUNT(page_size);
pte = alloc_pte(dom, bus_addr, page_size, NULL, GFP_KERNEL);
for (i = 0; i < count; ++i)
if (IOMMU_PTE_PRESENT(pte[i]))
return -EBUSY;
if (page_size > PAGE_SIZE) {
__pte = PAGE_SIZE_PTE(phys_addr, page_size);
__pte |= PM_LEVEL_ENC(7) | IOMMU_PTE_P | IOMMU_PTE_FC;
} else
__pte = phys_addr | IOMMU_PTE_P | IOMMU_PTE_FC;
if (prot & IOMMU_PROT_IR)
__pte |= IOMMU_PTE_IR;
if (prot & IOMMU_PROT_IW)
__pte |= IOMMU_PTE_IW;
for (i = 0; i < count; ++i)
pte[i] = __pte;
update_domain(dom);
return 0;
}
static unsigned long iommu_unmap_page(struct protection_domain *dom,
unsigned long bus_addr,
unsigned long page_size)
{
unsigned long long unmap_size, unmapped;
u64 *pte;
BUG_ON(!is_power_of_2(page_size));
unmapped = 0;
while (unmapped < page_size) {
pte = fetch_pte(dom, bus_addr);
if (!pte) {
unmap_size = PAGE_SIZE;
} else if (PM_PTE_LEVEL(*pte) == 0) {
unmap_size = PAGE_SIZE;
*pte = 0ULL;
} else {
int count, i;
unmap_size = PTE_PAGE_SIZE(*pte);
count = PAGE_SIZE_PTE_COUNT(unmap_size);
for (i = 0; i < count; i++)
pte[i] = 0ULL;
}
bus_addr = (bus_addr & ~(unmap_size - 1)) + unmap_size;
unmapped += unmap_size;
}
BUG_ON(!is_power_of_2(unmapped));
return unmapped;
}
static int iommu_for_unity_map(struct amd_iommu *iommu,
struct unity_map_entry *entry)
{
u16 bdf, i;
for (i = entry->devid_start; i <= entry->devid_end; ++i) {
bdf = amd_iommu_alias_table[i];
if (amd_iommu_rlookup_table[bdf] == iommu)
return 1;
}
return 0;
}
static int dma_ops_unity_map(struct dma_ops_domain *dma_dom,
struct unity_map_entry *e)
{
u64 addr;
int ret;
for (addr = e->address_start; addr < e->address_end;
addr += PAGE_SIZE) {
ret = iommu_map_page(&dma_dom->domain, addr, addr, e->prot,
PAGE_SIZE);
if (ret)
return ret;
if (addr < dma_dom->aperture_size)
__set_bit(addr >> PAGE_SHIFT,
dma_dom->aperture[0]->bitmap);
}
return 0;
}
static int iommu_init_unity_mappings(struct amd_iommu *iommu)
{
struct unity_map_entry *entry;
int ret;
list_for_each_entry(entry, &amd_iommu_unity_map, list) {
if (!iommu_for_unity_map(iommu, entry))
continue;
ret = dma_ops_unity_map(iommu->default_dom, entry);
if (ret)
return ret;
}
return 0;
}
static int init_unity_mappings_for_device(struct dma_ops_domain *dma_dom,
u16 devid)
{
struct unity_map_entry *e;
int ret;
list_for_each_entry(e, &amd_iommu_unity_map, list) {
if (!(devid >= e->devid_start && devid <= e->devid_end))
continue;
ret = dma_ops_unity_map(dma_dom, e);
if (ret)
return ret;
}
return 0;
}
static void dma_ops_reserve_addresses(struct dma_ops_domain *dom,
unsigned long start_page,
unsigned int pages)
{
unsigned int i, last_page = dom->aperture_size >> PAGE_SHIFT;
if (start_page + pages > last_page)
pages = last_page - start_page;
for (i = start_page; i < start_page + pages; ++i) {
int index = i / APERTURE_RANGE_PAGES;
int page = i % APERTURE_RANGE_PAGES;
__set_bit(page, dom->aperture[index]->bitmap);
}
}
static int alloc_new_range(struct dma_ops_domain *dma_dom,
bool populate, gfp_t gfp)
{
int index = dma_dom->aperture_size >> APERTURE_RANGE_SHIFT;
struct amd_iommu *iommu;
unsigned long i;
#ifdef CONFIG_IOMMU_STRESS
populate = false;
#endif
if (index >= APERTURE_MAX_RANGES)
return -ENOMEM;
dma_dom->aperture[index] = kzalloc(sizeof(struct aperture_range), gfp);
if (!dma_dom->aperture[index])
return -ENOMEM;
dma_dom->aperture[index]->bitmap = (void *)get_zeroed_page(gfp);
if (!dma_dom->aperture[index]->bitmap)
goto out_free;
dma_dom->aperture[index]->offset = dma_dom->aperture_size;
if (populate) {
unsigned long address = dma_dom->aperture_size;
int i, num_ptes = APERTURE_RANGE_PAGES / 512;
u64 *pte, *pte_page;
for (i = 0; i < num_ptes; ++i) {
pte = alloc_pte(&dma_dom->domain, address, PAGE_SIZE,
&pte_page, gfp);
if (!pte)
goto out_free;
dma_dom->aperture[index]->pte_pages[i] = pte_page;
address += APERTURE_RANGE_SIZE / 64;
}
}
dma_dom->aperture_size += APERTURE_RANGE_SIZE;
for_each_iommu(iommu) {
if (iommu->exclusion_start &&
iommu->exclusion_start >= dma_dom->aperture[index]->offset
&& iommu->exclusion_start < dma_dom->aperture_size) {
unsigned long startpage;
int pages = iommu_num_pages(iommu->exclusion_start,
iommu->exclusion_length,
PAGE_SIZE);
startpage = iommu->exclusion_start >> PAGE_SHIFT;
dma_ops_reserve_addresses(dma_dom, startpage, pages);
}
}
for (i = dma_dom->aperture[index]->offset;
i < dma_dom->aperture_size;
i += PAGE_SIZE) {
u64 *pte = fetch_pte(&dma_dom->domain, i);
if (!pte || !IOMMU_PTE_PRESENT(*pte))
continue;
dma_ops_reserve_addresses(dma_dom, i << PAGE_SHIFT, 1);
}
update_domain(&dma_dom->domain);
return 0;
out_free:
update_domain(&dma_dom->domain);
free_page((unsigned long)dma_dom->aperture[index]->bitmap);
kfree(dma_dom->aperture[index]);
dma_dom->aperture[index] = NULL;
return -ENOMEM;
}
static unsigned long dma_ops_area_alloc(struct device *dev,
struct dma_ops_domain *dom,
unsigned int pages,
unsigned long align_mask,
u64 dma_mask,
unsigned long start)
{
unsigned long next_bit = dom->next_address % APERTURE_RANGE_SIZE;
int max_index = dom->aperture_size >> APERTURE_RANGE_SHIFT;
int i = start >> APERTURE_RANGE_SHIFT;
unsigned long boundary_size;
unsigned long address = -1;
unsigned long limit;
next_bit >>= PAGE_SHIFT;
boundary_size = ALIGN(dma_get_seg_boundary(dev) + 1,
PAGE_SIZE) >> PAGE_SHIFT;
for (;i < max_index; ++i) {
unsigned long offset = dom->aperture[i]->offset >> PAGE_SHIFT;
if (dom->aperture[i]->offset >= dma_mask)
break;
limit = iommu_device_max_index(APERTURE_RANGE_PAGES, offset,
dma_mask >> PAGE_SHIFT);
address = iommu_area_alloc(dom->aperture[i]->bitmap,
limit, next_bit, pages, 0,
boundary_size, align_mask);
if (address != -1) {
address = dom->aperture[i]->offset +
(address << PAGE_SHIFT);
dom->next_address = address + (pages << PAGE_SHIFT);
break;
}
next_bit = 0;
}
return address;
}
static unsigned long dma_ops_alloc_addresses(struct device *dev,
struct dma_ops_domain *dom,
unsigned int pages,
unsigned long align_mask,
u64 dma_mask)
{
unsigned long address;
#ifdef CONFIG_IOMMU_STRESS
dom->next_address = 0;
dom->need_flush = true;
#endif
address = dma_ops_area_alloc(dev, dom, pages, align_mask,
dma_mask, dom->next_address);
if (address == -1) {
dom->next_address = 0;
address = dma_ops_area_alloc(dev, dom, pages, align_mask,
dma_mask, 0);
dom->need_flush = true;
}
if (unlikely(address == -1))
address = DMA_ERROR_CODE;
WARN_ON((address + (PAGE_SIZE*pages)) > dom->aperture_size);
return address;
}
static void dma_ops_free_addresses(struct dma_ops_domain *dom,
unsigned long address,
unsigned int pages)
{
unsigned i = address >> APERTURE_RANGE_SHIFT;
struct aperture_range *range = dom->aperture[i];
BUG_ON(i >= APERTURE_MAX_RANGES || range == NULL);
#ifdef CONFIG_IOMMU_STRESS
if (i < 4)
return;
#endif
if (address >= dom->next_address)
dom->need_flush = true;
address = (address % APERTURE_RANGE_SIZE) >> PAGE_SHIFT;
bitmap_clear(range->bitmap, address, pages);
}
static void add_domain_to_list(struct protection_domain *domain)
{
unsigned long flags;
spin_lock_irqsave(&amd_iommu_pd_lock, flags);
list_add(&domain->list, &amd_iommu_pd_list);
spin_unlock_irqrestore(&amd_iommu_pd_lock, flags);
}
static void del_domain_from_list(struct protection_domain *domain)
{
unsigned long flags;
spin_lock_irqsave(&amd_iommu_pd_lock, flags);
list_del(&domain->list);
spin_unlock_irqrestore(&amd_iommu_pd_lock, flags);
}
static u16 domain_id_alloc(void)
{
unsigned long flags;
int id;
write_lock_irqsave(&amd_iommu_devtable_lock, flags);
id = find_first_zero_bit(amd_iommu_pd_alloc_bitmap, MAX_DOMAIN_ID);
BUG_ON(id == 0);
if (id > 0 && id < MAX_DOMAIN_ID)
__set_bit(id, amd_iommu_pd_alloc_bitmap);
else
id = 0;
write_unlock_irqrestore(&amd_iommu_devtable_lock, flags);
return id;
}
static void domain_id_free(int id)
{
unsigned long flags;
write_lock_irqsave(&amd_iommu_devtable_lock, flags);
if (id > 0 && id < MAX_DOMAIN_ID)
__clear_bit(id, amd_iommu_pd_alloc_bitmap);
write_unlock_irqrestore(&amd_iommu_devtable_lock, flags);
}
static void free_pagetable(struct protection_domain *domain)
{
int i, j;
u64 *p1, *p2, *p3;
p1 = domain->pt_root;
if (!p1)
return;
for (i = 0; i < 512; ++i) {
if (!IOMMU_PTE_PRESENT(p1[i]))
continue;
p2 = IOMMU_PTE_PAGE(p1[i]);
for (j = 0; j < 512; ++j) {
if (!IOMMU_PTE_PRESENT(p2[j]))
continue;
p3 = IOMMU_PTE_PAGE(p2[j]);
free_page((unsigned long)p3);
}
free_page((unsigned long)p2);
}
free_page((unsigned long)p1);
domain->pt_root = NULL;
}
static void dma_ops_domain_free(struct dma_ops_domain *dom)
{
int i;
if (!dom)
return;
del_domain_from_list(&dom->domain);
free_pagetable(&dom->domain);
for (i = 0; i < APERTURE_MAX_RANGES; ++i) {
if (!dom->aperture[i])
continue;
free_page((unsigned long)dom->aperture[i]->bitmap);
kfree(dom->aperture[i]);
}
kfree(dom);
}
static struct dma_ops_domain *dma_ops_domain_alloc(void)
{
struct dma_ops_domain *dma_dom;
dma_dom = kzalloc(sizeof(struct dma_ops_domain), GFP_KERNEL);
if (!dma_dom)
return NULL;
spin_lock_init(&dma_dom->domain.lock);
dma_dom->domain.id = domain_id_alloc();
if (dma_dom->domain.id == 0)
goto free_dma_dom;
INIT_LIST_HEAD(&dma_dom->domain.dev_list);
dma_dom->domain.mode = PAGE_MODE_2_LEVEL;
dma_dom->domain.pt_root = (void *)get_zeroed_page(GFP_KERNEL);
dma_dom->domain.flags = PD_DMA_OPS_MASK;
dma_dom->domain.priv = dma_dom;
if (!dma_dom->domain.pt_root)
goto free_dma_dom;
dma_dom->need_flush = false;
dma_dom->target_dev = 0xffff;
add_domain_to_list(&dma_dom->domain);
if (alloc_new_range(dma_dom, true, GFP_KERNEL))
goto free_dma_dom;
dma_dom->aperture[0]->bitmap[0] = 1;
dma_dom->next_address = 0;
return dma_dom;
free_dma_dom:
dma_ops_domain_free(dma_dom);
return NULL;
}
static bool dma_ops_domain(struct protection_domain *domain)
{
return domain->flags & PD_DMA_OPS_MASK;
}
static void set_dte_entry(u16 devid, struct protection_domain *domain, bool ats)
{
u64 pte_root = virt_to_phys(domain->pt_root);
u32 flags = 0;
pte_root |= (domain->mode & DEV_ENTRY_MODE_MASK)
<< DEV_ENTRY_MODE_SHIFT;
pte_root |= IOMMU_PTE_IR | IOMMU_PTE_IW | IOMMU_PTE_P | IOMMU_PTE_TV;
if (ats)
flags |= DTE_FLAG_IOTLB;
amd_iommu_dev_table[devid].data[3] |= flags;
amd_iommu_dev_table[devid].data[2] = domain->id;
amd_iommu_dev_table[devid].data[1] = upper_32_bits(pte_root);
amd_iommu_dev_table[devid].data[0] = lower_32_bits(pte_root);
}
static void clear_dte_entry(u16 devid)
{
amd_iommu_dev_table[devid].data[0] = IOMMU_PTE_P | IOMMU_PTE_TV;
amd_iommu_dev_table[devid].data[1] = 0;
amd_iommu_dev_table[devid].data[2] = 0;
amd_iommu_apply_erratum_63(devid);
}
static void do_attach(struct device *dev, struct protection_domain *domain)
{
struct iommu_dev_data *dev_data;
struct amd_iommu *iommu;
struct pci_dev *pdev;
bool ats = false;
u16 devid;
devid = get_device_id(dev);
iommu = amd_iommu_rlookup_table[devid];
dev_data = get_dev_data(dev);
pdev = to_pci_dev(dev);
if (amd_iommu_iotlb_sup)
ats = pci_ats_enabled(pdev);
dev_data->domain = domain;
list_add(&dev_data->list, &domain->dev_list);
set_dte_entry(devid, domain, ats);
domain->dev_iommu[iommu->index] += 1;
domain->dev_cnt += 1;
device_flush_dte(dev);
}
static void do_detach(struct device *dev)
{
struct iommu_dev_data *dev_data;
struct amd_iommu *iommu;
u16 devid;
devid = get_device_id(dev);
iommu = amd_iommu_rlookup_table[devid];
dev_data = get_dev_data(dev);
dev_data->domain->dev_iommu[iommu->index] -= 1;
dev_data->domain->dev_cnt -= 1;
dev_data->domain = NULL;
list_del(&dev_data->list);
clear_dte_entry(devid);
device_flush_dte(dev);
}
static int __attach_device(struct device *dev,
struct protection_domain *domain)
{
struct iommu_dev_data *dev_data, *alias_data;
int ret;
dev_data = get_dev_data(dev);
alias_data = get_dev_data(dev_data->alias);
if (!alias_data)
return -EINVAL;
spin_lock(&domain->lock);
ret = -EBUSY;
if (alias_data->domain != NULL &&
alias_data->domain != domain)
goto out_unlock;
if (dev_data->domain != NULL &&
dev_data->domain != domain)
goto out_unlock;
if (dev_data->alias != dev) {
alias_data = get_dev_data(dev_data->alias);
if (alias_data->domain == NULL)
do_attach(dev_data->alias, domain);
atomic_inc(&alias_data->bind);
}
if (dev_data->domain == NULL)
do_attach(dev, domain);
atomic_inc(&dev_data->bind);
ret = 0;
out_unlock:
spin_unlock(&domain->lock);
return ret;
}
static int attach_device(struct device *dev,
struct protection_domain *domain)
{
struct pci_dev *pdev = to_pci_dev(dev);
unsigned long flags;
int ret;
if (amd_iommu_iotlb_sup)
pci_enable_ats(pdev, PAGE_SHIFT);
write_lock_irqsave(&amd_iommu_devtable_lock, flags);
ret = __attach_device(dev, domain);
write_unlock_irqrestore(&amd_iommu_devtable_lock, flags);
domain_flush_tlb_pde(domain);
return ret;
}
static void __detach_device(struct device *dev)
{
struct iommu_dev_data *dev_data = get_dev_data(dev);
struct iommu_dev_data *alias_data;
struct protection_domain *domain;
unsigned long flags;
BUG_ON(!dev_data->domain);
domain = dev_data->domain;
spin_lock_irqsave(&domain->lock, flags);
if (dev_data->alias != dev) {
alias_data = get_dev_data(dev_data->alias);
if (atomic_dec_and_test(&alias_data->bind))
do_detach(dev_data->alias);
}
if (atomic_dec_and_test(&dev_data->bind))
do_detach(dev);
spin_unlock_irqrestore(&domain->lock, flags);
if (iommu_pass_through &&
(dev_data->domain == NULL && domain != pt_domain))
__attach_device(dev, pt_domain);
}
static void detach_device(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
unsigned long flags;
write_lock_irqsave(&amd_iommu_devtable_lock, flags);
__detach_device(dev);
write_unlock_irqrestore(&amd_iommu_devtable_lock, flags);
if (amd_iommu_iotlb_sup && pci_ats_enabled(pdev))
pci_disable_ats(pdev);
}
static struct protection_domain *domain_for_device(struct device *dev)
{
struct protection_domain *dom;
struct iommu_dev_data *dev_data, *alias_data;
unsigned long flags;
u16 devid;
devid = get_device_id(dev);
dev_data = get_dev_data(dev);
alias_data = get_dev_data(dev_data->alias);
if (!alias_data)
return NULL;
read_lock_irqsave(&amd_iommu_devtable_lock, flags);
dom = dev_data->domain;
if (dom == NULL &&
alias_data->domain != NULL) {
__attach_device(dev, alias_data->domain);
dom = alias_data->domain;
}
read_unlock_irqrestore(&amd_iommu_devtable_lock, flags);
return dom;
}
static int device_change_notifier(struct notifier_block *nb,
unsigned long action, void *data)
{
struct device *dev = data;
u16 devid;
struct protection_domain *domain;
struct dma_ops_domain *dma_domain;
struct amd_iommu *iommu;
unsigned long flags;
if (!check_device(dev))
return 0;
devid = get_device_id(dev);
iommu = amd_iommu_rlookup_table[devid];
switch (action) {
case BUS_NOTIFY_UNBOUND_DRIVER:
domain = domain_for_device(dev);
if (!domain)
goto out;
if (iommu_pass_through)
break;
detach_device(dev);
break;
case BUS_NOTIFY_ADD_DEVICE:
iommu_init_device(dev);
domain = domain_for_device(dev);
dma_domain = find_protection_domain(devid);
if (dma_domain)
goto out;
dma_domain = dma_ops_domain_alloc();
if (!dma_domain)
goto out;
dma_domain->target_dev = devid;
spin_lock_irqsave(&iommu_pd_list_lock, flags);
list_add_tail(&dma_domain->list, &iommu_pd_list);
spin_unlock_irqrestore(&iommu_pd_list_lock, flags);
break;
case BUS_NOTIFY_DEL_DEVICE:
iommu_uninit_device(dev);
default:
goto out;
}
device_flush_dte(dev);
iommu_completion_wait(iommu);
out:
return 0;
}
void amd_iommu_init_notifier(void)
{
bus_register_notifier(&pci_bus_type, &device_nb);
}
static struct protection_domain *get_domain(struct device *dev)
{
struct protection_domain *domain;
struct dma_ops_domain *dma_dom;
u16 devid = get_device_id(dev);
if (!check_device(dev))
return ERR_PTR(-EINVAL);
domain = domain_for_device(dev);
if (domain != NULL && !dma_ops_domain(domain))
return ERR_PTR(-EBUSY);
if (domain != NULL)
return domain;
dma_dom = find_protection_domain(devid);
if (!dma_dom)
dma_dom = amd_iommu_rlookup_table[devid]->default_dom;
attach_device(dev, &dma_dom->domain);
DUMP_printk("Using protection domain %d for device %s\n",
dma_dom->domain.id, dev_name(dev));
return &dma_dom->domain;
}
static void update_device_table(struct protection_domain *domain)
{
struct iommu_dev_data *dev_data;
list_for_each_entry(dev_data, &domain->dev_list, list) {
struct pci_dev *pdev = to_pci_dev(dev_data->dev);
u16 devid = get_device_id(dev_data->dev);
set_dte_entry(devid, domain, pci_ats_enabled(pdev));
}
}
static void update_domain(struct protection_domain *domain)
{
if (!domain->updated)
return;
update_device_table(domain);
domain_flush_devices(domain);
domain_flush_tlb_pde(domain);
domain->updated = false;
}
static u64* dma_ops_get_pte(struct dma_ops_domain *dom,
unsigned long address)
{
struct aperture_range *aperture;
u64 *pte, *pte_page;
aperture = dom->aperture[APERTURE_RANGE_INDEX(address)];
if (!aperture)
return NULL;
pte = aperture->pte_pages[APERTURE_PAGE_INDEX(address)];
if (!pte) {
pte = alloc_pte(&dom->domain, address, PAGE_SIZE, &pte_page,
GFP_ATOMIC);
aperture->pte_pages[APERTURE_PAGE_INDEX(address)] = pte_page;
} else
pte += PM_LEVEL_INDEX(0, address);
update_domain(&dom->domain);
return pte;
}
static dma_addr_t dma_ops_domain_map(struct dma_ops_domain *dom,
unsigned long address,
phys_addr_t paddr,
int direction)
{
u64 *pte, __pte;
WARN_ON(address > dom->aperture_size);
paddr &= PAGE_MASK;
pte = dma_ops_get_pte(dom, address);
if (!pte)
return DMA_ERROR_CODE;
__pte = paddr | IOMMU_PTE_P | IOMMU_PTE_FC;
if (direction == DMA_TO_DEVICE)
__pte |= IOMMU_PTE_IR;
else if (direction == DMA_FROM_DEVICE)
__pte |= IOMMU_PTE_IW;
else if (direction == DMA_BIDIRECTIONAL)
__pte |= IOMMU_PTE_IR | IOMMU_PTE_IW;
WARN_ON(*pte);
*pte = __pte;
return (dma_addr_t)address;
}
static void dma_ops_domain_unmap(struct dma_ops_domain *dom,
unsigned long address)
{
struct aperture_range *aperture;
u64 *pte;
if (address >= dom->aperture_size)
return;
aperture = dom->aperture[APERTURE_RANGE_INDEX(address)];
if (!aperture)
return;
pte = aperture->pte_pages[APERTURE_PAGE_INDEX(address)];
if (!pte)
return;
pte += PM_LEVEL_INDEX(0, address);
WARN_ON(!*pte);
*pte = 0ULL;
}
static dma_addr_t __map_single(struct device *dev,
struct dma_ops_domain *dma_dom,
phys_addr_t paddr,
size_t size,
int dir,
bool align,
u64 dma_mask)
{
dma_addr_t offset = paddr & ~PAGE_MASK;
dma_addr_t address, start, ret;
unsigned int pages;
unsigned long align_mask = 0;
int i;
pages = iommu_num_pages(paddr, size, PAGE_SIZE);
paddr &= PAGE_MASK;
INC_STATS_COUNTER(total_map_requests);
if (pages > 1)
INC_STATS_COUNTER(cross_page);
if (align)
align_mask = (1UL << get_order(size)) - 1;
retry:
address = dma_ops_alloc_addresses(dev, dma_dom, pages, align_mask,
dma_mask);
if (unlikely(address == DMA_ERROR_CODE)) {
dma_dom->next_address = dma_dom->aperture_size;
if (alloc_new_range(dma_dom, false, GFP_ATOMIC))
goto out;
goto retry;
}
start = address;
for (i = 0; i < pages; ++i) {
ret = dma_ops_domain_map(dma_dom, start, paddr, dir);
if (ret == DMA_ERROR_CODE)
goto out_unmap;
paddr += PAGE_SIZE;
start += PAGE_SIZE;
}
address += offset;
ADD_STATS_COUNTER(alloced_io_mem, size);
if (unlikely(dma_dom->need_flush && !amd_iommu_unmap_flush)) {
domain_flush_tlb(&dma_dom->domain);
dma_dom->need_flush = false;
} else if (unlikely(amd_iommu_np_cache))
domain_flush_pages(&dma_dom->domain, address, size);
out:
return address;
out_unmap:
for (--i; i >= 0; --i) {
start -= PAGE_SIZE;
dma_ops_domain_unmap(dma_dom, start);
}
dma_ops_free_addresses(dma_dom, address, pages);
return DMA_ERROR_CODE;
}
static void __unmap_single(struct dma_ops_domain *dma_dom,
dma_addr_t dma_addr,
size_t size,
int dir)
{
dma_addr_t flush_addr;
dma_addr_t i, start;
unsigned int pages;
if ((dma_addr == DMA_ERROR_CODE) ||
(dma_addr + size > dma_dom->aperture_size))
return;
flush_addr = dma_addr;
pages = iommu_num_pages(dma_addr, size, PAGE_SIZE);
dma_addr &= PAGE_MASK;
start = dma_addr;
for (i = 0; i < pages; ++i) {
dma_ops_domain_unmap(dma_dom, start);
start += PAGE_SIZE;
}
SUB_STATS_COUNTER(alloced_io_mem, size);
dma_ops_free_addresses(dma_dom, dma_addr, pages);
if (amd_iommu_unmap_flush || dma_dom->need_flush) {
domain_flush_pages(&dma_dom->domain, flush_addr, size);
dma_dom->need_flush = false;
}
}
static dma_addr_t map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
unsigned long flags;
struct protection_domain *domain;
dma_addr_t addr;
u64 dma_mask;
phys_addr_t paddr = page_to_phys(page) + offset;
INC_STATS_COUNTER(cnt_map_single);
domain = get_domain(dev);
if (PTR_ERR(domain) == -EINVAL)
return (dma_addr_t)paddr;
else if (IS_ERR(domain))
return DMA_ERROR_CODE;
dma_mask = *dev->dma_mask;
spin_lock_irqsave(&domain->lock, flags);
addr = __map_single(dev, domain->priv, paddr, size, dir, false,
dma_mask);
if (addr == DMA_ERROR_CODE)
goto out;
domain_flush_complete(domain);
out:
spin_unlock_irqrestore(&domain->lock, flags);
return addr;
}
static void unmap_page(struct device *dev, dma_addr_t dma_addr, size_t size,
enum dma_data_direction dir, struct dma_attrs *attrs)
{
unsigned long flags;
struct protection_domain *domain;
INC_STATS_COUNTER(cnt_unmap_single);
domain = get_domain(dev);
if (IS_ERR(domain))
return;
spin_lock_irqsave(&domain->lock, flags);
__unmap_single(domain->priv, dma_addr, size, dir);
domain_flush_complete(domain);
spin_unlock_irqrestore(&domain->lock, flags);
}
static int map_sg_no_iommu(struct device *dev, struct scatterlist *sglist,
int nelems, int dir)
{
struct scatterlist *s;
int i;
for_each_sg(sglist, s, nelems, i) {
s->dma_address = (dma_addr_t)sg_phys(s);
s->dma_length = s->length;
}
return nelems;
}
static int map_sg(struct device *dev, struct scatterlist *sglist,
int nelems, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
unsigned long flags;
struct protection_domain *domain;
int i;
struct scatterlist *s;
phys_addr_t paddr;
int mapped_elems = 0;
u64 dma_mask;
INC_STATS_COUNTER(cnt_map_sg);
domain = get_domain(dev);
if (PTR_ERR(domain) == -EINVAL)
return map_sg_no_iommu(dev, sglist, nelems, dir);
else if (IS_ERR(domain))
return 0;
dma_mask = *dev->dma_mask;
spin_lock_irqsave(&domain->lock, flags);
for_each_sg(sglist, s, nelems, i) {
paddr = sg_phys(s);
s->dma_address = __map_single(dev, domain->priv,
paddr, s->length, dir, false,
dma_mask);
if (s->dma_address) {
s->dma_length = s->length;
mapped_elems++;
} else
goto unmap;
}
domain_flush_complete(domain);
out:
spin_unlock_irqrestore(&domain->lock, flags);
return mapped_elems;
unmap:
for_each_sg(sglist, s, mapped_elems, i) {
if (s->dma_address)
__unmap_single(domain->priv, s->dma_address,
s->dma_length, dir);
s->dma_address = s->dma_length = 0;
}
mapped_elems = 0;
goto out;
}
static void unmap_sg(struct device *dev, struct scatterlist *sglist,
int nelems, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
unsigned long flags;
struct protection_domain *domain;
struct scatterlist *s;
int i;
INC_STATS_COUNTER(cnt_unmap_sg);
domain = get_domain(dev);
if (IS_ERR(domain))
return;
spin_lock_irqsave(&domain->lock, flags);
for_each_sg(sglist, s, nelems, i) {
__unmap_single(domain->priv, s->dma_address,
s->dma_length, dir);
s->dma_address = s->dma_length = 0;
}
domain_flush_complete(domain);
spin_unlock_irqrestore(&domain->lock, flags);
}
static void *alloc_coherent(struct device *dev, size_t size,
dma_addr_t *dma_addr, gfp_t flag)
{
unsigned long flags;
void *virt_addr;
struct protection_domain *domain;
phys_addr_t paddr;
u64 dma_mask = dev->coherent_dma_mask;
INC_STATS_COUNTER(cnt_alloc_coherent);
domain = get_domain(dev);
if (PTR_ERR(domain) == -EINVAL) {
virt_addr = (void *)__get_free_pages(flag, get_order(size));
*dma_addr = __pa(virt_addr);
return virt_addr;
} else if (IS_ERR(domain))
return NULL;
dma_mask = dev->coherent_dma_mask;
flag &= ~(__GFP_DMA | __GFP_HIGHMEM | __GFP_DMA32);
flag |= __GFP_ZERO;
virt_addr = (void *)__get_free_pages(flag, get_order(size));
if (!virt_addr)
return NULL;
paddr = virt_to_phys(virt_addr);
if (!dma_mask)
dma_mask = *dev->dma_mask;
spin_lock_irqsave(&domain->lock, flags);
*dma_addr = __map_single(dev, domain->priv, paddr,
size, DMA_BIDIRECTIONAL, true, dma_mask);
if (*dma_addr == DMA_ERROR_CODE) {
spin_unlock_irqrestore(&domain->lock, flags);
goto out_free;
}
domain_flush_complete(domain);
spin_unlock_irqrestore(&domain->lock, flags);
return virt_addr;
out_free:
free_pages((unsigned long)virt_addr, get_order(size));
return NULL;
}
static void free_coherent(struct device *dev, size_t size,
void *virt_addr, dma_addr_t dma_addr)
{
unsigned long flags;
struct protection_domain *domain;
INC_STATS_COUNTER(cnt_free_coherent);
domain = get_domain(dev);
if (IS_ERR(domain))
goto free_mem;
spin_lock_irqsave(&domain->lock, flags);
__unmap_single(domain->priv, dma_addr, size, DMA_BIDIRECTIONAL);
domain_flush_complete(domain);
spin_unlock_irqrestore(&domain->lock, flags);
free_mem:
free_pages((unsigned long)virt_addr, get_order(size));
}
static int amd_iommu_dma_supported(struct device *dev, u64 mask)
{
return check_device(dev);
}
static void prealloc_protection_domains(void)
{
struct pci_dev *dev = NULL;
struct dma_ops_domain *dma_dom;
u16 devid;
for_each_pci_dev(dev) {
if (!check_device(&dev->dev))
continue;
if (domain_for_device(&dev->dev))
continue;
devid = get_device_id(&dev->dev);
dma_dom = dma_ops_domain_alloc();
if (!dma_dom)
continue;
init_unity_mappings_for_device(dma_dom, devid);
dma_dom->target_dev = devid;
attach_device(&dev->dev, &dma_dom->domain);
list_add_tail(&dma_dom->list, &iommu_pd_list);
}
}
static unsigned device_dma_ops_init(void)
{
struct pci_dev *pdev = NULL;
unsigned unhandled = 0;
for_each_pci_dev(pdev) {
if (!check_device(&pdev->dev)) {
unhandled += 1;
continue;
}
pdev->dev.archdata.dma_ops = &amd_iommu_dma_ops;
}
return unhandled;
}
void __init amd_iommu_init_api(void)
{
register_iommu(&amd_iommu_ops);
}
int __init amd_iommu_init_dma_ops(void)
{
struct amd_iommu *iommu;
int ret, unhandled;
for_each_iommu(iommu) {
iommu->default_dom = dma_ops_domain_alloc();
if (iommu->default_dom == NULL)
return -ENOMEM;
iommu->default_dom->domain.flags |= PD_DEFAULT_MASK;
ret = iommu_init_unity_mappings(iommu);
if (ret)
goto free_domains;
}
prealloc_protection_domains();
iommu_detected = 1;
swiotlb = 0;
unhandled = device_dma_ops_init();
if (unhandled && max_pfn > MAX_DMA32_PFN) {
swiotlb = 1;
}
amd_iommu_stats_init();
return 0;
free_domains:
for_each_iommu(iommu) {
if (iommu->default_dom)
dma_ops_domain_free(iommu->default_dom);
}
return ret;
}
static void cleanup_domain(struct protection_domain *domain)
{
struct iommu_dev_data *dev_data, *next;
unsigned long flags;
write_lock_irqsave(&amd_iommu_devtable_lock, flags);
list_for_each_entry_safe(dev_data, next, &domain->dev_list, list) {
struct device *dev = dev_data->dev;
__detach_device(dev);
atomic_set(&dev_data->bind, 0);
}
write_unlock_irqrestore(&amd_iommu_devtable_lock, flags);
}
static void protection_domain_free(struct protection_domain *domain)
{
if (!domain)
return;
del_domain_from_list(domain);
if (domain->id)
domain_id_free(domain->id);
kfree(domain);
}
static struct protection_domain *protection_domain_alloc(void)
{
struct protection_domain *domain;
domain = kzalloc(sizeof(*domain), GFP_KERNEL);
if (!domain)
return NULL;
spin_lock_init(&domain->lock);
mutex_init(&domain->api_lock);
domain->id = domain_id_alloc();
if (!domain->id)
goto out_err;
INIT_LIST_HEAD(&domain->dev_list);
add_domain_to_list(domain);
return domain;
out_err:
kfree(domain);
return NULL;
}
static int amd_iommu_domain_init(struct iommu_domain *dom)
{
struct protection_domain *domain;
domain = protection_domain_alloc();
if (!domain)
goto out_free;
domain->mode = PAGE_MODE_3_LEVEL;
domain->pt_root = (void *)get_zeroed_page(GFP_KERNEL);
if (!domain->pt_root)
goto out_free;
dom->priv = domain;
return 0;
out_free:
protection_domain_free(domain);
return -ENOMEM;
}
static void amd_iommu_domain_destroy(struct iommu_domain *dom)
{
struct protection_domain *domain = dom->priv;
if (!domain)
return;
if (domain->dev_cnt > 0)
cleanup_domain(domain);
BUG_ON(domain->dev_cnt != 0);
free_pagetable(domain);
protection_domain_free(domain);
dom->priv = NULL;
}
static void amd_iommu_detach_device(struct iommu_domain *dom,
struct device *dev)
{
struct iommu_dev_data *dev_data = dev->archdata.iommu;
struct amd_iommu *iommu;
u16 devid;
if (!check_device(dev))
return;
devid = get_device_id(dev);
if (dev_data->domain != NULL)
detach_device(dev);
iommu = amd_iommu_rlookup_table[devid];
if (!iommu)
return;
device_flush_dte(dev);
iommu_completion_wait(iommu);
}
static int amd_iommu_attach_device(struct iommu_domain *dom,
struct device *dev)
{
struct protection_domain *domain = dom->priv;
struct iommu_dev_data *dev_data;
struct amd_iommu *iommu;
int ret;
u16 devid;
if (!check_device(dev))
return -EINVAL;
dev_data = dev->archdata.iommu;
devid = get_device_id(dev);
iommu = amd_iommu_rlookup_table[devid];
if (!iommu)
return -EINVAL;
if (dev_data->domain)
detach_device(dev);
ret = attach_device(dev, domain);
iommu_completion_wait(iommu);
return ret;
}
static int amd_iommu_map(struct iommu_domain *dom, unsigned long iova,
phys_addr_t paddr, int gfp_order, int iommu_prot)
{
unsigned long page_size = 0x1000UL << gfp_order;
struct protection_domain *domain = dom->priv;
int prot = 0;
int ret;
if (iommu_prot & IOMMU_READ)
prot |= IOMMU_PROT_IR;
if (iommu_prot & IOMMU_WRITE)
prot |= IOMMU_PROT_IW;
mutex_lock(&domain->api_lock);
ret = iommu_map_page(domain, iova, paddr, prot, page_size);
mutex_unlock(&domain->api_lock);
return ret;
}
static int amd_iommu_unmap(struct iommu_domain *dom, unsigned long iova,
int gfp_order)
{
struct protection_domain *domain = dom->priv;
unsigned long page_size, unmap_size;
page_size = 0x1000UL << gfp_order;
mutex_lock(&domain->api_lock);
unmap_size = iommu_unmap_page(domain, iova, page_size);
mutex_unlock(&domain->api_lock);
domain_flush_tlb_pde(domain);
return get_order(unmap_size);
}
static phys_addr_t amd_iommu_iova_to_phys(struct iommu_domain *dom,
unsigned long iova)
{
struct protection_domain *domain = dom->priv;
unsigned long offset_mask;
phys_addr_t paddr;
u64 *pte, __pte;
pte = fetch_pte(domain, iova);
if (!pte || !IOMMU_PTE_PRESENT(*pte))
return 0;
if (PM_PTE_LEVEL(*pte) == 0)
offset_mask = PAGE_SIZE - 1;
else
offset_mask = PTE_PAGE_SIZE(*pte) - 1;
__pte = *pte & PM_ADDR_MASK;
paddr = (__pte & ~offset_mask) | (iova & offset_mask);
return paddr;
}
static int amd_iommu_domain_has_cap(struct iommu_domain *domain,
unsigned long cap)
{
switch (cap) {
case IOMMU_CAP_CACHE_COHERENCY:
return 1;
}
return 0;
}
int __init amd_iommu_init_passthrough(void)
{
struct amd_iommu *iommu;
struct pci_dev *dev = NULL;
u16 devid;
pt_domain = protection_domain_alloc();
if (!pt_domain)
return -ENOMEM;
pt_domain->mode |= PAGE_MODE_NONE;
for_each_pci_dev(dev) {
if (!check_device(&dev->dev))
continue;
devid = get_device_id(&dev->dev);
iommu = amd_iommu_rlookup_table[devid];
if (!iommu)
continue;
attach_device(&dev->dev, pt_domain);
}
pr_info("AMD-Vi: Initialized for Passthrough Mode\n");
return 0;
}
