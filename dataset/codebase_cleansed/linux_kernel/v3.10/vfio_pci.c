static int vfio_pci_enable(struct vfio_pci_device *vdev)
{
struct pci_dev *pdev = vdev->pdev;
int ret;
u16 cmd;
u8 msix_pos;
ret = pci_enable_device(pdev);
if (ret)
return ret;
vdev->reset_works = (pci_reset_function(pdev) == 0);
pci_save_state(pdev);
vdev->pci_saved_state = pci_store_saved_state(pdev);
if (!vdev->pci_saved_state)
pr_debug("%s: Couldn't store %s saved state\n",
__func__, dev_name(&pdev->dev));
ret = vfio_config_init(vdev);
if (ret) {
pci_load_and_free_saved_state(pdev, &vdev->pci_saved_state);
pci_disable_device(pdev);
return ret;
}
if (likely(!nointxmask))
vdev->pci_2_3 = pci_intx_mask_supported(pdev);
pci_read_config_word(pdev, PCI_COMMAND, &cmd);
if (vdev->pci_2_3 && (cmd & PCI_COMMAND_INTX_DISABLE)) {
cmd &= ~PCI_COMMAND_INTX_DISABLE;
pci_write_config_word(pdev, PCI_COMMAND, cmd);
}
msix_pos = pdev->msix_cap;
if (msix_pos) {
u16 flags;
u32 table;
pci_read_config_word(pdev, msix_pos + PCI_MSIX_FLAGS, &flags);
pci_read_config_dword(pdev, msix_pos + PCI_MSIX_TABLE, &table);
vdev->msix_bar = table & PCI_MSIX_TABLE_BIR;
vdev->msix_offset = table & PCI_MSIX_TABLE_OFFSET;
vdev->msix_size = ((flags & PCI_MSIX_FLAGS_QSIZE) + 1) * 16;
} else
vdev->msix_bar = 0xFF;
#ifdef CONFIG_VFIO_PCI_VGA
if ((pdev->class >> 8) == PCI_CLASS_DISPLAY_VGA)
vdev->has_vga = true;
#endif
return 0;
}
static void vfio_pci_disable(struct vfio_pci_device *vdev)
{
struct pci_dev *pdev = vdev->pdev;
int bar;
pci_disable_device(pdev);
vfio_pci_set_irqs_ioctl(vdev, VFIO_IRQ_SET_DATA_NONE |
VFIO_IRQ_SET_ACTION_TRIGGER,
vdev->irq_type, 0, 0, NULL);
vdev->virq_disabled = false;
vfio_config_free(vdev);
for (bar = PCI_STD_RESOURCES; bar <= PCI_STD_RESOURCE_END; bar++) {
if (!vdev->barmap[bar])
continue;
pci_iounmap(pdev, vdev->barmap[bar]);
pci_release_selected_regions(pdev, 1 << bar);
vdev->barmap[bar] = NULL;
}
if (pci_load_and_free_saved_state(pdev, &vdev->pci_saved_state)) {
pr_info("%s: Couldn't reload %s saved state\n",
__func__, dev_name(&pdev->dev));
if (!vdev->reset_works)
return;
pci_save_state(pdev);
}
pci_write_config_word(pdev, PCI_COMMAND, PCI_COMMAND_INTX_DISABLE);
if (vdev->reset_works)
__pci_reset_function(pdev);
pci_restore_state(pdev);
}
static void vfio_pci_release(void *device_data)
{
struct vfio_pci_device *vdev = device_data;
if (atomic_dec_and_test(&vdev->refcnt))
vfio_pci_disable(vdev);
module_put(THIS_MODULE);
}
static int vfio_pci_open(void *device_data)
{
struct vfio_pci_device *vdev = device_data;
if (!try_module_get(THIS_MODULE))
return -ENODEV;
if (atomic_inc_return(&vdev->refcnt) == 1) {
int ret = vfio_pci_enable(vdev);
if (ret) {
module_put(THIS_MODULE);
return ret;
}
}
return 0;
}
static int vfio_pci_get_irq_count(struct vfio_pci_device *vdev, int irq_type)
{
if (irq_type == VFIO_PCI_INTX_IRQ_INDEX) {
u8 pin;
pci_read_config_byte(vdev->pdev, PCI_INTERRUPT_PIN, &pin);
if (pin)
return 1;
} else if (irq_type == VFIO_PCI_MSI_IRQ_INDEX) {
u8 pos;
u16 flags;
pos = vdev->pdev->msi_cap;
if (pos) {
pci_read_config_word(vdev->pdev,
pos + PCI_MSI_FLAGS, &flags);
return 1 << (flags & PCI_MSI_FLAGS_QMASK);
}
} else if (irq_type == VFIO_PCI_MSIX_IRQ_INDEX) {
u8 pos;
u16 flags;
pos = vdev->pdev->msix_cap;
if (pos) {
pci_read_config_word(vdev->pdev,
pos + PCI_MSIX_FLAGS, &flags);
return (flags & PCI_MSIX_FLAGS_QSIZE) + 1;
}
} else if (irq_type == VFIO_PCI_ERR_IRQ_INDEX)
if (pci_is_pcie(vdev->pdev))
return 1;
return 0;
}
static long vfio_pci_ioctl(void *device_data,
unsigned int cmd, unsigned long arg)
{
struct vfio_pci_device *vdev = device_data;
unsigned long minsz;
if (cmd == VFIO_DEVICE_GET_INFO) {
struct vfio_device_info info;
minsz = offsetofend(struct vfio_device_info, num_irqs);
if (copy_from_user(&info, (void __user *)arg, minsz))
return -EFAULT;
if (info.argsz < minsz)
return -EINVAL;
info.flags = VFIO_DEVICE_FLAGS_PCI;
if (vdev->reset_works)
info.flags |= VFIO_DEVICE_FLAGS_RESET;
info.num_regions = VFIO_PCI_NUM_REGIONS;
info.num_irqs = VFIO_PCI_NUM_IRQS;
return copy_to_user((void __user *)arg, &info, minsz);
} else if (cmd == VFIO_DEVICE_GET_REGION_INFO) {
struct pci_dev *pdev = vdev->pdev;
struct vfio_region_info info;
minsz = offsetofend(struct vfio_region_info, offset);
if (copy_from_user(&info, (void __user *)arg, minsz))
return -EFAULT;
if (info.argsz < minsz)
return -EINVAL;
switch (info.index) {
case VFIO_PCI_CONFIG_REGION_INDEX:
info.offset = VFIO_PCI_INDEX_TO_OFFSET(info.index);
info.size = pdev->cfg_size;
info.flags = VFIO_REGION_INFO_FLAG_READ |
VFIO_REGION_INFO_FLAG_WRITE;
break;
case VFIO_PCI_BAR0_REGION_INDEX ... VFIO_PCI_BAR5_REGION_INDEX:
info.offset = VFIO_PCI_INDEX_TO_OFFSET(info.index);
info.size = pci_resource_len(pdev, info.index);
if (!info.size) {
info.flags = 0;
break;
}
info.flags = VFIO_REGION_INFO_FLAG_READ |
VFIO_REGION_INFO_FLAG_WRITE;
if (pci_resource_flags(pdev, info.index) &
IORESOURCE_MEM && info.size >= PAGE_SIZE)
info.flags |= VFIO_REGION_INFO_FLAG_MMAP;
break;
case VFIO_PCI_ROM_REGION_INDEX:
{
void __iomem *io;
size_t size;
info.offset = VFIO_PCI_INDEX_TO_OFFSET(info.index);
info.flags = 0;
info.size = pci_resource_len(pdev, info.index);
if (!info.size)
break;
io = pci_map_rom(pdev, &size);
if (!io || !size) {
info.size = 0;
break;
}
pci_unmap_rom(pdev, io);
info.flags = VFIO_REGION_INFO_FLAG_READ;
break;
}
case VFIO_PCI_VGA_REGION_INDEX:
if (!vdev->has_vga)
return -EINVAL;
info.offset = VFIO_PCI_INDEX_TO_OFFSET(info.index);
info.size = 0xc0000;
info.flags = VFIO_REGION_INFO_FLAG_READ |
VFIO_REGION_INFO_FLAG_WRITE;
break;
default:
return -EINVAL;
}
return copy_to_user((void __user *)arg, &info, minsz);
} else if (cmd == VFIO_DEVICE_GET_IRQ_INFO) {
struct vfio_irq_info info;
minsz = offsetofend(struct vfio_irq_info, count);
if (copy_from_user(&info, (void __user *)arg, minsz))
return -EFAULT;
if (info.argsz < minsz || info.index >= VFIO_PCI_NUM_IRQS)
return -EINVAL;
switch (info.index) {
case VFIO_PCI_INTX_IRQ_INDEX ... VFIO_PCI_MSIX_IRQ_INDEX:
break;
case VFIO_PCI_ERR_IRQ_INDEX:
if (pci_is_pcie(vdev->pdev))
break;
default:
return -EINVAL;
}
info.flags = VFIO_IRQ_INFO_EVENTFD;
info.count = vfio_pci_get_irq_count(vdev, info.index);
if (info.index == VFIO_PCI_INTX_IRQ_INDEX)
info.flags |= (VFIO_IRQ_INFO_MASKABLE |
VFIO_IRQ_INFO_AUTOMASKED);
else
info.flags |= VFIO_IRQ_INFO_NORESIZE;
return copy_to_user((void __user *)arg, &info, minsz);
} else if (cmd == VFIO_DEVICE_SET_IRQS) {
struct vfio_irq_set hdr;
u8 *data = NULL;
int ret = 0;
minsz = offsetofend(struct vfio_irq_set, count);
if (copy_from_user(&hdr, (void __user *)arg, minsz))
return -EFAULT;
if (hdr.argsz < minsz || hdr.index >= VFIO_PCI_NUM_IRQS ||
hdr.flags & ~(VFIO_IRQ_SET_DATA_TYPE_MASK |
VFIO_IRQ_SET_ACTION_TYPE_MASK))
return -EINVAL;
if (!(hdr.flags & VFIO_IRQ_SET_DATA_NONE)) {
size_t size;
int max = vfio_pci_get_irq_count(vdev, hdr.index);
if (hdr.flags & VFIO_IRQ_SET_DATA_BOOL)
size = sizeof(uint8_t);
else if (hdr.flags & VFIO_IRQ_SET_DATA_EVENTFD)
size = sizeof(int32_t);
else
return -EINVAL;
if (hdr.argsz - minsz < hdr.count * size ||
hdr.start >= max || hdr.start + hdr.count > max)
return -EINVAL;
data = memdup_user((void __user *)(arg + minsz),
hdr.count * size);
if (IS_ERR(data))
return PTR_ERR(data);
}
mutex_lock(&vdev->igate);
ret = vfio_pci_set_irqs_ioctl(vdev, hdr.flags, hdr.index,
hdr.start, hdr.count, data);
mutex_unlock(&vdev->igate);
kfree(data);
return ret;
} else if (cmd == VFIO_DEVICE_RESET)
return vdev->reset_works ?
pci_reset_function(vdev->pdev) : -EINVAL;
return -ENOTTY;
}
static ssize_t vfio_pci_rw(void *device_data, char __user *buf,
size_t count, loff_t *ppos, bool iswrite)
{
unsigned int index = VFIO_PCI_OFFSET_TO_INDEX(*ppos);
struct vfio_pci_device *vdev = device_data;
if (index >= VFIO_PCI_NUM_REGIONS)
return -EINVAL;
switch (index) {
case VFIO_PCI_CONFIG_REGION_INDEX:
return vfio_pci_config_rw(vdev, buf, count, ppos, iswrite);
case VFIO_PCI_ROM_REGION_INDEX:
if (iswrite)
return -EINVAL;
return vfio_pci_bar_rw(vdev, buf, count, ppos, false);
case VFIO_PCI_BAR0_REGION_INDEX ... VFIO_PCI_BAR5_REGION_INDEX:
return vfio_pci_bar_rw(vdev, buf, count, ppos, iswrite);
case VFIO_PCI_VGA_REGION_INDEX:
return vfio_pci_vga_rw(vdev, buf, count, ppos, iswrite);
}
return -EINVAL;
}
static ssize_t vfio_pci_read(void *device_data, char __user *buf,
size_t count, loff_t *ppos)
{
if (!count)
return 0;
return vfio_pci_rw(device_data, buf, count, ppos, false);
}
static ssize_t vfio_pci_write(void *device_data, const char __user *buf,
size_t count, loff_t *ppos)
{
if (!count)
return 0;
return vfio_pci_rw(device_data, (char __user *)buf, count, ppos, true);
}
static int vfio_pci_mmap(void *device_data, struct vm_area_struct *vma)
{
struct vfio_pci_device *vdev = device_data;
struct pci_dev *pdev = vdev->pdev;
unsigned int index;
u64 phys_len, req_len, pgoff, req_start;
int ret;
index = vma->vm_pgoff >> (VFIO_PCI_OFFSET_SHIFT - PAGE_SHIFT);
if (vma->vm_end < vma->vm_start)
return -EINVAL;
if ((vma->vm_flags & VM_SHARED) == 0)
return -EINVAL;
if (index >= VFIO_PCI_ROM_REGION_INDEX)
return -EINVAL;
if (!(pci_resource_flags(pdev, index) & IORESOURCE_MEM))
return -EINVAL;
phys_len = pci_resource_len(pdev, index);
req_len = vma->vm_end - vma->vm_start;
pgoff = vma->vm_pgoff &
((1U << (VFIO_PCI_OFFSET_SHIFT - PAGE_SHIFT)) - 1);
req_start = pgoff << PAGE_SHIFT;
if (phys_len < PAGE_SIZE || req_start + req_len > phys_len)
return -EINVAL;
if (index == vdev->msix_bar) {
if (!(req_start >= vdev->msix_offset + vdev->msix_size ||
req_start + req_len <= vdev->msix_offset))
return -EINVAL;
}
if (!vdev->barmap[index]) {
ret = pci_request_selected_regions(pdev,
1 << index, "vfio-pci");
if (ret)
return ret;
vdev->barmap[index] = pci_iomap(pdev, index, 0);
}
vma->vm_private_data = vdev;
vma->vm_flags |= VM_IO | VM_DONTEXPAND | VM_DONTDUMP;
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
vma->vm_pgoff = (pci_resource_start(pdev, index) >> PAGE_SHIFT) + pgoff;
return remap_pfn_range(vma, vma->vm_start, vma->vm_pgoff,
req_len, vma->vm_page_prot);
}
static int vfio_pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
u8 type;
struct vfio_pci_device *vdev;
struct iommu_group *group;
int ret;
pci_read_config_byte(pdev, PCI_HEADER_TYPE, &type);
if ((type & PCI_HEADER_TYPE) != PCI_HEADER_TYPE_NORMAL)
return -EINVAL;
group = iommu_group_get(&pdev->dev);
if (!group)
return -EINVAL;
vdev = kzalloc(sizeof(*vdev), GFP_KERNEL);
if (!vdev) {
iommu_group_put(group);
return -ENOMEM;
}
vdev->pdev = pdev;
vdev->irq_type = VFIO_PCI_NUM_IRQS;
mutex_init(&vdev->igate);
spin_lock_init(&vdev->irqlock);
atomic_set(&vdev->refcnt, 0);
ret = vfio_add_group_dev(&pdev->dev, &vfio_pci_ops, vdev);
if (ret) {
iommu_group_put(group);
kfree(vdev);
}
return ret;
}
static void vfio_pci_remove(struct pci_dev *pdev)
{
struct vfio_pci_device *vdev;
vdev = vfio_del_group_dev(&pdev->dev);
if (!vdev)
return;
iommu_group_put(pdev->dev.iommu_group);
kfree(vdev);
}
static pci_ers_result_t vfio_pci_aer_err_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
struct vfio_pci_device *vdev;
struct vfio_device *device;
device = vfio_device_get_from_dev(&pdev->dev);
if (device == NULL)
return PCI_ERS_RESULT_DISCONNECT;
vdev = vfio_device_data(device);
if (vdev == NULL) {
vfio_device_put(device);
return PCI_ERS_RESULT_DISCONNECT;
}
if (vdev->err_trigger)
eventfd_signal(vdev->err_trigger, 1);
vfio_device_put(device);
return PCI_ERS_RESULT_CAN_RECOVER;
}
static void __exit vfio_pci_cleanup(void)
{
pci_unregister_driver(&vfio_pci_driver);
vfio_pci_virqfd_exit();
vfio_pci_uninit_perm_bits();
}
static int __init vfio_pci_init(void)
{
int ret;
ret = vfio_pci_init_perm_bits();
if (ret)
return ret;
ret = vfio_pci_virqfd_init();
if (ret)
goto out_virqfd;
ret = pci_register_driver(&vfio_pci_driver);
if (ret)
goto out_driver;
return 0;
out_driver:
vfio_pci_virqfd_exit();
out_virqfd:
vfio_pci_uninit_perm_bits();
return ret;
}
