static void sclp_sync_callback(struct sclp_req *req, void *data)
{
struct completion *completion = data;
complete(completion);
}
int sclp_sync_request(sclp_cmdw_t cmd, void *sccb)
{
return sclp_sync_request_timeout(cmd, sccb, 0);
}
int sclp_sync_request_timeout(sclp_cmdw_t cmd, void *sccb, int timeout)
{
struct completion completion;
struct sclp_req *request;
int rc;
request = kzalloc(sizeof(*request), GFP_KERNEL);
if (!request)
return -ENOMEM;
if (timeout)
request->queue_timeout = timeout;
request->command = cmd;
request->sccb = sccb;
request->status = SCLP_REQ_FILLED;
request->callback = sclp_sync_callback;
request->callback_data = &completion;
init_completion(&completion);
rc = sclp_add_request(request);
if (rc)
goto out;
wait_for_completion(&completion);
if (request->status != SCLP_REQ_DONE) {
pr_warn("sync request failed (cmd=0x%08x, status=0x%02x)\n",
cmd, request->status);
rc = -EIO;
}
out:
kfree(request);
return rc;
}
static void sclp_fill_core_info(struct sclp_core_info *info,
struct read_cpu_info_sccb *sccb)
{
char *page = (char *) sccb;
memset(info, 0, sizeof(*info));
info->configured = sccb->nr_configured;
info->standby = sccb->nr_standby;
info->combined = sccb->nr_configured + sccb->nr_standby;
memcpy(&info->core, page + sccb->offset_configured,
info->combined * sizeof(struct sclp_core_entry));
}
int sclp_get_core_info(struct sclp_core_info *info)
{
int rc;
struct read_cpu_info_sccb *sccb;
if (!SCLP_HAS_CPU_INFO)
return -EOPNOTSUPP;
sccb = (void *) get_zeroed_page(GFP_KERNEL | GFP_DMA);
if (!sccb)
return -ENOMEM;
sccb->header.length = sizeof(*sccb);
rc = sclp_sync_request_timeout(SCLP_CMDW_READ_CPU_INFO, sccb,
SCLP_QUEUE_INTERVAL);
if (rc)
goto out;
if (sccb->header.response_code != 0x0010) {
pr_warn("readcpuinfo failed (response=0x%04x)\n",
sccb->header.response_code);
rc = -EIO;
goto out;
}
sclp_fill_core_info(info, sccb);
out:
free_page((unsigned long) sccb);
return rc;
}
static int do_core_configure(sclp_cmdw_t cmd)
{
struct cpu_configure_sccb *sccb;
int rc;
if (!SCLP_HAS_CPU_RECONFIG)
return -EOPNOTSUPP;
sccb = kzalloc(sizeof(*sccb), GFP_KERNEL | GFP_DMA);
if (!sccb)
return -ENOMEM;
sccb->header.length = sizeof(*sccb);
rc = sclp_sync_request_timeout(cmd, sccb, SCLP_QUEUE_INTERVAL);
if (rc)
goto out;
switch (sccb->header.response_code) {
case 0x0020:
case 0x0120:
break;
default:
pr_warn("configure cpu failed (cmd=0x%08x, response=0x%04x)\n",
cmd, sccb->header.response_code);
rc = -EIO;
break;
}
out:
kfree(sccb);
return rc;
}
int sclp_core_configure(u8 core)
{
return do_core_configure(SCLP_CMDW_CONFIGURE_CPU | core << 8);
}
int sclp_core_deconfigure(u8 core)
{
return do_core_configure(SCLP_CMDW_DECONFIGURE_CPU | core << 8);
}
int arch_get_memory_phys_device(unsigned long start_pfn)
{
if (!sclp.rzm)
return 0;
return PFN_PHYS(start_pfn) >> ilog2(sclp.rzm);
}
static unsigned long long rn2addr(u16 rn)
{
return (unsigned long long) (rn - 1) * sclp.rzm;
}
static int do_assign_storage(sclp_cmdw_t cmd, u16 rn)
{
struct assign_storage_sccb *sccb;
int rc;
sccb = (void *) get_zeroed_page(GFP_KERNEL | GFP_DMA);
if (!sccb)
return -ENOMEM;
sccb->header.length = PAGE_SIZE;
sccb->rn = rn;
rc = sclp_sync_request_timeout(cmd, sccb, SCLP_QUEUE_INTERVAL);
if (rc)
goto out;
switch (sccb->header.response_code) {
case 0x0020:
case 0x0120:
break;
default:
pr_warn("assign storage failed (cmd=0x%08x, response=0x%04x, rn=0x%04x)\n",
cmd, sccb->header.response_code, rn);
rc = -EIO;
break;
}
out:
free_page((unsigned long) sccb);
return rc;
}
static int sclp_assign_storage(u16 rn)
{
unsigned long long start;
int rc;
rc = do_assign_storage(0x000d0001, rn);
if (rc)
return rc;
start = rn2addr(rn);
storage_key_init_range(start, start + sclp.rzm);
return 0;
}
static int sclp_unassign_storage(u16 rn)
{
return do_assign_storage(0x000c0001, rn);
}
static int sclp_attach_storage(u8 id)
{
struct attach_storage_sccb *sccb;
int rc;
int i;
sccb = (void *) get_zeroed_page(GFP_KERNEL | GFP_DMA);
if (!sccb)
return -ENOMEM;
sccb->header.length = PAGE_SIZE;
rc = sclp_sync_request_timeout(0x00080001 | id << 8, sccb,
SCLP_QUEUE_INTERVAL);
if (rc)
goto out;
switch (sccb->header.response_code) {
case 0x0020:
set_bit(id, sclp_storage_ids);
for (i = 0; i < sccb->assigned; i++) {
if (sccb->entries[i])
sclp_unassign_storage(sccb->entries[i] >> 16);
}
break;
default:
rc = -EIO;
break;
}
out:
free_page((unsigned long) sccb);
return rc;
}
static int sclp_mem_change_state(unsigned long start, unsigned long size,
int online)
{
struct memory_increment *incr;
unsigned long long istart;
int rc = 0;
list_for_each_entry(incr, &sclp_mem_list, list) {
istart = rn2addr(incr->rn);
if (start + size - 1 < istart)
break;
if (start > istart + sclp.rzm - 1)
continue;
if (online)
rc |= sclp_assign_storage(incr->rn);
else
sclp_unassign_storage(incr->rn);
if (rc == 0)
incr->standby = online ? 0 : 1;
}
return rc ? -EIO : 0;
}
static bool contains_standby_increment(unsigned long start, unsigned long end)
{
struct memory_increment *incr;
unsigned long istart;
list_for_each_entry(incr, &sclp_mem_list, list) {
istart = rn2addr(incr->rn);
if (end - 1 < istart)
continue;
if (start > istart + sclp.rzm - 1)
continue;
if (incr->standby)
return true;
}
return false;
}
static int sclp_mem_notifier(struct notifier_block *nb,
unsigned long action, void *data)
{
unsigned long start, size;
struct memory_notify *arg;
unsigned char id;
int rc = 0;
arg = data;
start = arg->start_pfn << PAGE_SHIFT;
size = arg->nr_pages << PAGE_SHIFT;
mutex_lock(&sclp_mem_mutex);
for_each_clear_bit(id, sclp_storage_ids, sclp_max_storage_id + 1)
sclp_attach_storage(id);
switch (action) {
case MEM_GOING_OFFLINE:
if (contains_standby_increment(start, start + size))
rc = -EPERM;
break;
case MEM_ONLINE:
case MEM_CANCEL_OFFLINE:
break;
case MEM_GOING_ONLINE:
rc = sclp_mem_change_state(start, size, 1);
break;
case MEM_CANCEL_ONLINE:
sclp_mem_change_state(start, size, 0);
break;
case MEM_OFFLINE:
sclp_mem_change_state(start, size, 0);
break;
default:
rc = -EINVAL;
break;
}
if (!rc)
sclp_mem_state_changed = 1;
mutex_unlock(&sclp_mem_mutex);
return rc ? NOTIFY_BAD : NOTIFY_OK;
}
static void __init align_to_block_size(unsigned long long *start,
unsigned long long *size,
unsigned long long alignment)
{
unsigned long long start_align, size_align;
start_align = roundup(*start, alignment);
size_align = rounddown(*start + *size, alignment) - start_align;
pr_info("Standby memory at 0x%llx (%lluM of %lluM usable)\n",
*start, size_align >> 20, *size >> 20);
*start = start_align;
*size = size_align;
}
static void __init add_memory_merged(u16 rn)
{
unsigned long long start, size, addr, block_size;
static u16 first_rn, num;
if (rn && first_rn && (first_rn + num == rn)) {
num++;
return;
}
if (!first_rn)
goto skip_add;
start = rn2addr(first_rn);
size = (unsigned long long) num * sclp.rzm;
if (start >= VMEM_MAX_PHYS)
goto skip_add;
if (start + size > VMEM_MAX_PHYS)
size = VMEM_MAX_PHYS - start;
if (memory_end_set && (start >= memory_end))
goto skip_add;
if (memory_end_set && (start + size > memory_end))
size = memory_end - start;
block_size = memory_block_size_bytes();
align_to_block_size(&start, &size, block_size);
if (!size)
goto skip_add;
for (addr = start; addr < start + size; addr += block_size)
add_memory(numa_pfn_to_nid(PFN_DOWN(addr)), addr, block_size);
skip_add:
first_rn = rn;
num = 1;
}
static void __init sclp_add_standby_memory(void)
{
struct memory_increment *incr;
list_for_each_entry(incr, &sclp_mem_list, list)
if (incr->standby)
add_memory_merged(incr->rn);
add_memory_merged(0);
}
static void __init insert_increment(u16 rn, int standby, int assigned)
{
struct memory_increment *incr, *new_incr;
struct list_head *prev;
u16 last_rn;
new_incr = kzalloc(sizeof(*new_incr), GFP_KERNEL);
if (!new_incr)
return;
new_incr->rn = rn;
new_incr->standby = standby;
last_rn = 0;
prev = &sclp_mem_list;
list_for_each_entry(incr, &sclp_mem_list, list) {
if (assigned && incr->rn > rn)
break;
if (!assigned && incr->rn - last_rn > 1)
break;
last_rn = incr->rn;
prev = &incr->list;
}
if (!assigned)
new_incr->rn = last_rn + 1;
if (new_incr->rn > sclp.rnmax) {
kfree(new_incr);
return;
}
list_add(&new_incr->list, prev);
}
static int sclp_mem_freeze(struct device *dev)
{
if (!sclp_mem_state_changed)
return 0;
pr_err("Memory hotplug state changed, suspend refused.\n");
return -EPERM;
}
static int __init sclp_detect_standby_memory(void)
{
struct platform_device *sclp_pdev;
struct read_storage_sccb *sccb;
int i, id, assigned, rc;
if (OLDMEM_BASE)
return 0;
if ((sclp.facilities & 0xe00000000000ULL) != 0xe00000000000ULL)
return 0;
rc = -ENOMEM;
sccb = (void *) __get_free_page(GFP_KERNEL | GFP_DMA);
if (!sccb)
goto out;
assigned = 0;
for (id = 0; id <= sclp_max_storage_id; id++) {
memset(sccb, 0, PAGE_SIZE);
sccb->header.length = PAGE_SIZE;
rc = sclp_sync_request(0x00040001 | id << 8, sccb);
if (rc)
goto out;
switch (sccb->header.response_code) {
case 0x0010:
set_bit(id, sclp_storage_ids);
for (i = 0; i < sccb->assigned; i++) {
if (!sccb->entries[i])
continue;
assigned++;
insert_increment(sccb->entries[i] >> 16, 0, 1);
}
break;
case 0x0310:
break;
case 0x0410:
for (i = 0; i < sccb->assigned; i++) {
if (!sccb->entries[i])
continue;
assigned++;
insert_increment(sccb->entries[i] >> 16, 1, 1);
}
break;
default:
rc = -EIO;
break;
}
if (!rc)
sclp_max_storage_id = sccb->max_id;
}
if (rc || list_empty(&sclp_mem_list))
goto out;
for (i = 1; i <= sclp.rnmax - assigned; i++)
insert_increment(0, 1, 0);
rc = register_memory_notifier(&sclp_mem_nb);
if (rc)
goto out;
rc = platform_driver_register(&sclp_mem_pdrv);
if (rc)
goto out;
sclp_pdev = platform_device_register_simple("sclp_mem", -1, NULL, 0);
rc = PTR_ERR_OR_ZERO(sclp_pdev);
if (rc)
goto out_driver;
sclp_add_standby_memory();
goto out;
out_driver:
platform_driver_unregister(&sclp_mem_pdrv);
out:
free_page((unsigned long) sccb);
return rc;
}
static int do_pci_configure(sclp_cmdw_t cmd, u32 fid)
{
struct pci_cfg_sccb *sccb;
int rc;
if (!SCLP_HAS_PCI_RECONFIG)
return -EOPNOTSUPP;
sccb = (struct pci_cfg_sccb *) get_zeroed_page(GFP_KERNEL | GFP_DMA);
if (!sccb)
return -ENOMEM;
sccb->header.length = PAGE_SIZE;
sccb->atype = SCLP_RECONFIG_PCI_ATPYE;
sccb->aid = fid;
rc = sclp_sync_request(cmd, sccb);
if (rc)
goto out;
switch (sccb->header.response_code) {
case 0x0020:
case 0x0120:
break;
default:
pr_warn("configure PCI I/O adapter failed: cmd=0x%08x response=0x%04x\n",
cmd, sccb->header.response_code);
rc = -EIO;
break;
}
out:
free_page((unsigned long) sccb);
return rc;
}
int sclp_pci_configure(u32 fid)
{
return do_pci_configure(SCLP_CMDW_CONFIGURE_PCI, fid);
}
int sclp_pci_deconfigure(u32 fid)
{
return do_pci_configure(SCLP_CMDW_DECONFIGURE_PCI, fid);
}
static int do_chp_configure(sclp_cmdw_t cmd)
{
struct chp_cfg_sccb *sccb;
int rc;
if (!SCLP_HAS_CHP_RECONFIG)
return -EOPNOTSUPP;
sccb = (struct chp_cfg_sccb *) get_zeroed_page(GFP_KERNEL | GFP_DMA);
if (!sccb)
return -ENOMEM;
sccb->header.length = sizeof(*sccb);
rc = sclp_sync_request(cmd, sccb);
if (rc)
goto out;
switch (sccb->header.response_code) {
case 0x0020:
case 0x0120:
case 0x0440:
case 0x0450:
break;
default:
pr_warn("configure channel-path failed (cmd=0x%08x, response=0x%04x)\n",
cmd, sccb->header.response_code);
rc = -EIO;
break;
}
out:
free_page((unsigned long) sccb);
return rc;
}
int sclp_chp_configure(struct chp_id chpid)
{
return do_chp_configure(SCLP_CMDW_CONFIGURE_CHPATH | chpid.id << 8);
}
int sclp_chp_deconfigure(struct chp_id chpid)
{
return do_chp_configure(SCLP_CMDW_DECONFIGURE_CHPATH | chpid.id << 8);
}
int sclp_chp_read_info(struct sclp_chp_info *info)
{
struct chp_info_sccb *sccb;
int rc;
if (!SCLP_HAS_CHP_INFO)
return -EOPNOTSUPP;
sccb = (struct chp_info_sccb *) get_zeroed_page(GFP_KERNEL | GFP_DMA);
if (!sccb)
return -ENOMEM;
sccb->header.length = sizeof(*sccb);
rc = sclp_sync_request(SCLP_CMDW_READ_CHPATH_INFORMATION, sccb);
if (rc)
goto out;
if (sccb->header.response_code != 0x0010) {
pr_warn("read channel-path info failed (response=0x%04x)\n",
sccb->header.response_code);
rc = -EIO;
goto out;
}
memcpy(info->recognized, sccb->recognized, SCLP_CHP_INFO_MASK_SIZE);
memcpy(info->standby, sccb->standby, SCLP_CHP_INFO_MASK_SIZE);
memcpy(info->configured, sccb->configured, SCLP_CHP_INFO_MASK_SIZE);
out:
free_page((unsigned long) sccb);
return rc;
}
