static inline void viafb_mmio_write(int reg, u32 v)
{
iowrite32(v, global_dev.engine_mmio + reg);
}
static inline int viafb_mmio_read(int reg)
{
return ioread32(global_dev.engine_mmio + reg);
}
static void viafb_int_init(void)
{
viafb_enabled_ints = 0;
viafb_mmio_write(VDE_INTERRUPT, 0);
}
void viafb_irq_enable(u32 mask)
{
viafb_enabled_ints |= mask;
viafb_mmio_write(VDE_INTERRUPT, viafb_enabled_ints | VDE_I_ENABLE);
}
void viafb_irq_disable(u32 mask)
{
viafb_enabled_ints &= ~mask;
if (viafb_enabled_ints == 0)
viafb_mmio_write(VDE_INTERRUPT, 0);
else
viafb_mmio_write(VDE_INTERRUPT,
viafb_enabled_ints | VDE_I_ENABLE);
}
static irqreturn_t viafb_dma_irq(int irq, void *data)
{
int csr;
irqreturn_t ret = IRQ_NONE;
spin_lock(&global_dev.reg_lock);
csr = viafb_mmio_read(VDMA_CSR0);
if (csr & VDMA_C_DONE) {
viafb_mmio_write(VDMA_CSR0, VDMA_C_DONE);
complete(&viafb_dma_completion);
ret = IRQ_HANDLED;
}
spin_unlock(&global_dev.reg_lock);
return ret;
}
int viafb_request_dma(void)
{
int ret = 0;
if (global_dev.chip_type != UNICHROME_VX855)
return -ENODEV;
mutex_lock(&viafb_dma_lock);
viafb_dma_users++;
if (viafb_dma_users == 1) {
ret = request_irq(global_dev.pdev->irq, viafb_dma_irq,
IRQF_SHARED, "via-dma", &viafb_dma_users);
if (ret)
viafb_dma_users--;
else
viafb_irq_enable(VDE_I_DMA0TDEN);
}
mutex_unlock(&viafb_dma_lock);
return ret;
}
void viafb_release_dma(void)
{
mutex_lock(&viafb_dma_lock);
viafb_dma_users--;
if (viafb_dma_users == 0) {
viafb_irq_disable(VDE_I_DMA0TDEN);
free_irq(global_dev.pdev->irq, &viafb_dma_users);
}
mutex_unlock(&viafb_dma_lock);
}
int viafb_dma_copy_out_sg(unsigned int offset, struct scatterlist *sg, int nsg)
{
struct viafb_vx855_dma_descr *descr;
void *descrpages;
dma_addr_t descr_handle;
unsigned long flags;
int i;
struct scatterlist *sgentry;
dma_addr_t nextdesc;
descrpages = dma_alloc_coherent(&global_dev.pdev->dev,
nsg*sizeof(struct viafb_vx855_dma_descr),
&descr_handle, GFP_KERNEL);
if (descrpages == NULL) {
dev_err(&global_dev.pdev->dev, "Unable to get descr page.\n");
return -ENOMEM;
}
mutex_lock(&viafb_dma_lock);
descr = descrpages;
nextdesc = descr_handle + sizeof(struct viafb_vx855_dma_descr);
for_each_sg(sg, sgentry, nsg, i) {
dma_addr_t paddr = sg_dma_address(sgentry);
descr->addr_low = paddr & 0xfffffff0;
descr->addr_high = ((u64) paddr >> 32) & 0x0fff;
descr->fb_offset = offset;
descr->seg_size = sg_dma_len(sgentry) >> 4;
descr->tile_mode = 0;
descr->next_desc_low = (nextdesc&0xfffffff0) | VIAFB_DMA_MAGIC;
descr->next_desc_high = ((u64) nextdesc >> 32) & 0x0fff;
descr->pad = 0xffffffff;
offset += sg_dma_len(sgentry);
nextdesc += sizeof(struct viafb_vx855_dma_descr);
descr++;
}
descr[-1].next_desc_low = VIAFB_DMA_FINAL_SEGMENT|VIAFB_DMA_MAGIC;
spin_lock_irqsave(&global_dev.reg_lock, flags);
init_completion(&viafb_dma_completion);
viafb_mmio_write(VDMA_DQWCR0, 0);
viafb_mmio_write(VDMA_CSR0, VDMA_C_ENABLE|VDMA_C_DONE);
viafb_mmio_write(VDMA_MR0, VDMA_MR_TDIE | VDMA_MR_CHAIN);
viafb_mmio_write(VDMA_DPRL0, descr_handle | VIAFB_DMA_MAGIC);
viafb_mmio_write(VDMA_DPRH0,
(((u64)descr_handle >> 32) & 0x0fff) | 0xf0000);
(void) viafb_mmio_read(VDMA_CSR0);
viafb_mmio_write(VDMA_CSR0, VDMA_C_ENABLE|VDMA_C_START);
spin_unlock_irqrestore(&global_dev.reg_lock, flags);
wait_for_completion_timeout(&viafb_dma_completion, 1);
msleep(1);
if ((viafb_mmio_read(VDMA_CSR0)&VDMA_C_DONE) == 0)
printk(KERN_ERR "VIA DMA timeout!\n");
viafb_mmio_write(VDMA_CSR0, VDMA_C_DONE);
viafb_mmio_write(VDMA_MR0, 0);
mutex_unlock(&viafb_dma_lock);
dma_free_coherent(&global_dev.pdev->dev,
nsg*sizeof(struct viafb_vx855_dma_descr), descrpages,
descr_handle);
return 0;
}
static int viafb_get_fb_size_from_pci(int chip_type)
{
int i;
u8 offset = 0;
u32 FBSize;
u32 VideoMemSize;
for (i = 0; i < ARRAY_SIZE(via_function3); i++) {
struct pci_dev *pdev;
pdev = pci_get_device(PCI_VENDOR_ID_VIA, via_function3[i],
NULL);
if (!pdev)
continue;
DEBUG_MSG(KERN_INFO "Device ID = %x\n", pdev->device);
switch (pdev->device) {
case CLE266_FUNCTION3:
case KM400_FUNCTION3:
offset = 0xE0;
break;
case CN400_FUNCTION3:
case CN700_FUNCTION3:
case CX700_FUNCTION3:
case KM800_FUNCTION3:
case KM890_FUNCTION3:
case P4M890_FUNCTION3:
case P4M900_FUNCTION3:
case VX800_FUNCTION3:
case VX855_FUNCTION3:
case VX900_FUNCTION3:
offset = 0xA0;
break;
}
if (!offset)
break;
pci_read_config_dword(pdev, offset, &FBSize);
pci_dev_put(pdev);
}
if (!offset) {
printk(KERN_ERR "cannot determine framebuffer size\n");
return -EIO;
}
FBSize = FBSize & 0x00007000;
DEBUG_MSG(KERN_INFO "FB Size = %x\n", FBSize);
if (chip_type < UNICHROME_CX700) {
switch (FBSize) {
case 0x00004000:
VideoMemSize = (16 << 20);
break;
case 0x00005000:
VideoMemSize = (32 << 20);
break;
case 0x00006000:
VideoMemSize = (64 << 20);
break;
default:
VideoMemSize = (32 << 20);
break;
}
} else {
switch (FBSize) {
case 0x00001000:
VideoMemSize = (8 << 20);
break;
case 0x00002000:
VideoMemSize = (16 << 20);
break;
case 0x00003000:
VideoMemSize = (32 << 20);
break;
case 0x00004000:
VideoMemSize = (64 << 20);
break;
case 0x00005000:
VideoMemSize = (128 << 20);
break;
case 0x00006000:
VideoMemSize = (256 << 20);
break;
case 0x00007000:
VideoMemSize = (512 << 20);
break;
default:
VideoMemSize = (32 << 20);
break;
}
}
return VideoMemSize;
}
static int via_pci_setup_mmio(struct viafb_dev *vdev)
{
int ret;
vdev->engine_start = pci_resource_start(vdev->pdev, 1);
vdev->engine_len = pci_resource_len(vdev->pdev, 1);
vdev->engine_mmio = ioremap_nocache(vdev->engine_start,
vdev->engine_len);
if (vdev->engine_mmio == NULL)
dev_err(&vdev->pdev->dev,
"Unable to map engine MMIO; operation will be "
"slow and crippled.\n");
if (vdev->chip_type == UNICHROME_VX900)
vdev->fbmem_start = pci_resource_start(vdev->pdev, 2);
else
vdev->fbmem_start = pci_resource_start(vdev->pdev, 0);
ret = vdev->fbmem_len = viafb_get_fb_size_from_pci(vdev->chip_type);
if (ret < 0)
goto out_unmap;
for (; vdev->fbmem_len >= 8 << 20; vdev->fbmem_len /= 2) {
vdev->fbmem = ioremap_wc(vdev->fbmem_start, vdev->fbmem_len);
if (vdev->fbmem)
break;
}
if (vdev->fbmem == NULL) {
ret = -ENOMEM;
goto out_unmap;
}
return 0;
out_unmap:
iounmap(vdev->engine_mmio);
return ret;
}
static void via_pci_teardown_mmio(struct viafb_dev *vdev)
{
iounmap(vdev->fbmem);
iounmap(vdev->engine_mmio);
}
static int via_create_subdev(struct viafb_dev *vdev,
struct viafb_subdev_info *info)
{
int ret;
info->platdev = platform_device_alloc(info->name, -1);
if (!info->platdev) {
dev_err(&vdev->pdev->dev, "Unable to allocate pdev %s\n",
info->name);
return -ENOMEM;
}
info->platdev->dev.parent = &vdev->pdev->dev;
info->platdev->dev.platform_data = vdev;
ret = platform_device_add(info->platdev);
if (ret) {
dev_err(&vdev->pdev->dev, "Unable to add pdev %s\n",
info->name);
platform_device_put(info->platdev);
info->platdev = NULL;
}
return ret;
}
static int via_setup_subdevs(struct viafb_dev *vdev)
{
int i;
for (i = 0; i < N_SUBDEVS; i++)
via_create_subdev(vdev, viafb_subdevs + i);
return 0;
}
static void via_teardown_subdevs(void)
{
int i;
for (i = 0; i < N_SUBDEVS; i++)
if (viafb_subdevs[i].platdev) {
viafb_subdevs[i].platdev->dev.platform_data = NULL;
platform_device_unregister(viafb_subdevs[i].platdev);
}
}
void viafb_pm_register(struct viafb_pm_hooks *hooks)
{
INIT_LIST_HEAD(&hooks->list);
mutex_lock(&viafb_pm_hooks_lock);
list_add_tail(&hooks->list, &viafb_pm_hooks);
mutex_unlock(&viafb_pm_hooks_lock);
}
void viafb_pm_unregister(struct viafb_pm_hooks *hooks)
{
mutex_lock(&viafb_pm_hooks_lock);
list_del(&hooks->list);
mutex_unlock(&viafb_pm_hooks_lock);
}
static int via_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct viafb_pm_hooks *hooks;
if (state.event != PM_EVENT_SUSPEND)
return 0;
mutex_lock(&viafb_pm_hooks_lock);
list_for_each_entry_reverse(hooks, &viafb_pm_hooks, list)
hooks->suspend(hooks->private);
mutex_unlock(&viafb_pm_hooks_lock);
pci_save_state(pdev);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int via_resume(struct pci_dev *pdev)
{
struct viafb_pm_hooks *hooks;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
if (pci_enable_device(pdev))
return 0;
pci_set_master(pdev);
mutex_lock(&viafb_pm_hooks_lock);
list_for_each_entry(hooks, &viafb_pm_hooks, list)
hooks->resume(hooks->private);
mutex_unlock(&viafb_pm_hooks_lock);
return 0;
}
static int via_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int ret;
ret = pci_enable_device(pdev);
if (ret)
return ret;
memset(&global_dev, 0, sizeof(global_dev));
global_dev.pdev = pdev;
global_dev.chip_type = ent->driver_data;
global_dev.port_cfg = adap_configs;
if (machine_is_olpc())
global_dev.port_cfg = olpc_adap_configs;
spin_lock_init(&global_dev.reg_lock);
ret = via_pci_setup_mmio(&global_dev);
if (ret)
goto out_disable;
viafb_int_init();
via_setup_subdevs(&global_dev);
ret = via_fb_pci_probe(&global_dev);
if (ret)
goto out_subdevs;
return 0;
out_subdevs:
via_teardown_subdevs();
via_pci_teardown_mmio(&global_dev);
out_disable:
pci_disable_device(pdev);
return ret;
}
static void via_pci_remove(struct pci_dev *pdev)
{
via_teardown_subdevs();
via_fb_pci_remove(pdev);
via_pci_teardown_mmio(&global_dev);
pci_disable_device(pdev);
}
static int __init via_core_init(void)
{
int ret;
ret = viafb_init();
if (ret)
return ret;
viafb_i2c_init();
viafb_gpio_init();
return pci_register_driver(&via_driver);
}
static void __exit via_core_exit(void)
{
pci_unregister_driver(&via_driver);
viafb_gpio_exit();
viafb_i2c_exit();
viafb_exit();
}
