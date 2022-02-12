bool cxllib_slot_is_supported(struct pci_dev *dev, unsigned long flags)
{
int rc;
u32 phb_index;
u64 chip_id, capp_unit_id;
if (flags)
return false;
if (!cpu_has_feature(CPU_FTR_HVMODE))
return false;
if (!cxl_is_power9())
return false;
if (cxl_slot_is_switched(dev))
return false;
rc = cxl_calc_capp_routing(dev, &chip_id, &phb_index, &capp_unit_id);
if (rc)
return false;
return true;
}
static int allocate_dummy_read_buf(void)
{
u64 buf, vaddr;
size_t buf_size;
buf_size = CXL_DUMMY_READ_SIZE + (1ull << CXL_DUMMY_READ_ALIGN);
buf = (u64) kzalloc(buf_size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
vaddr = (buf + (1ull << CXL_DUMMY_READ_ALIGN) - 1) &
(~0ull << CXL_DUMMY_READ_ALIGN);
WARN((vaddr + CXL_DUMMY_READ_SIZE) > (buf + buf_size),
"Dummy read buffer alignment issue");
dummy_read_addr = virt_to_phys((void *) vaddr);
return 0;
}
int cxllib_get_xsl_config(struct pci_dev *dev, struct cxllib_xsl_config *cfg)
{
int rc;
u32 phb_index;
u64 chip_id, capp_unit_id;
if (!cpu_has_feature(CPU_FTR_HVMODE))
return -EINVAL;
mutex_lock(&dra_mutex);
if (dummy_read_addr == CXL_INVALID_DRA) {
rc = allocate_dummy_read_buf();
if (rc) {
mutex_unlock(&dra_mutex);
return rc;
}
}
mutex_unlock(&dra_mutex);
rc = cxl_calc_capp_routing(dev, &chip_id, &phb_index, &capp_unit_id);
if (rc)
return rc;
rc = cxl_get_xsl9_dsnctl(capp_unit_id, &cfg->dsnctl);
if (rc)
return rc;
if (cpu_has_feature(CPU_FTR_POWER9_DD1)) {
cfg->dsnctl |= ((u64)0x02 << (63-47));
}
cfg->version = CXL_XSL_CONFIG_CURRENT_VERSION;
cfg->log_bar_size = CXL_CAPI_WINDOW_LOG_SIZE;
cfg->bar_addr = CXL_CAPI_WINDOW_START;
cfg->dra = dummy_read_addr;
return 0;
}
int cxllib_switch_phb_mode(struct pci_dev *dev, enum cxllib_mode mode,
unsigned long flags)
{
int rc = 0;
if (!cpu_has_feature(CPU_FTR_HVMODE))
return -EINVAL;
switch (mode) {
case CXL_MODE_PCI:
rc = pnv_phb_to_cxl_mode(dev, OPAL_PHB_CAPI_MODE_SNOOP_OFF);
if (rc)
rc = -EBUSY;
else
rc = -EPERM;
break;
case CXL_MODE_CXL:
if (flags != CXL_MODE_DMA_TVT1)
return -EINVAL;
rc = pnv_phb_to_cxl_mode(dev, OPAL_PHB_CAPI_MODE_DMA_TVT1);
if (rc)
return rc;
rc = pnv_phb_to_cxl_mode(dev, OPAL_PHB_CAPI_MODE_SNOOP_ON);
break;
default:
rc = -EINVAL;
}
return rc;
}
int cxllib_set_device_dma(struct pci_dev *dev, unsigned long flags)
{
int rc;
if (flags)
return -EINVAL;
rc = dma_set_mask(&dev->dev, DMA_BIT_MASK(64));
return rc;
}
int cxllib_get_PE_attributes(struct task_struct *task,
unsigned long translation_mode,
struct cxllib_pe_attributes *attr)
{
struct mm_struct *mm = NULL;
if (translation_mode != CXL_TRANSLATED_MODE &&
translation_mode != CXL_REAL_MODE)
return -EINVAL;
attr->sr = cxl_calculate_sr(false,
task == NULL,
translation_mode == CXL_REAL_MODE,
true);
attr->lpid = mfspr(SPRN_LPID);
if (task) {
mm = get_task_mm(task);
if (mm == NULL)
return -EINVAL;
attr->pid = mm->context.id;
mmput(mm);
} else {
attr->pid = 0;
}
attr->tid = 0;
return 0;
}
int cxllib_handle_fault(struct mm_struct *mm, u64 addr, u64 size, u64 flags)
{
int rc;
u64 dar;
struct vm_area_struct *vma = NULL;
unsigned long page_size;
if (mm == NULL)
return -EFAULT;
down_read(&mm->mmap_sem);
for (dar = addr; dar < addr + size; dar += page_size) {
if (!vma || dar < vma->vm_start || dar > vma->vm_end) {
vma = find_vma(mm, addr);
if (!vma) {
pr_err("Can't find vma for addr %016llx\n", addr);
rc = -EFAULT;
goto out;
}
page_size = vma_kernel_pagesize(vma);
}
rc = cxl_handle_mm_fault(mm, flags, dar);
if (rc) {
pr_err("cxl_handle_mm_fault failed %d", rc);
rc = -EFAULT;
goto out;
}
}
rc = 0;
out:
up_read(&mm->mmap_sem);
return rc;
}
