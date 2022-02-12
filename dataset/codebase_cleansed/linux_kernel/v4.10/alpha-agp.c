static int alpha_core_agp_vm_fault(struct vm_area_struct *vma,
struct vm_fault *vmf)
{
alpha_agp_info *agp = agp_bridge->dev_private_data;
dma_addr_t dma_addr;
unsigned long pa;
struct page *page;
dma_addr = vmf->address - vma->vm_start + agp->aperture.bus_base;
pa = agp->ops->translate(agp, dma_addr);
if (pa == (unsigned long)-EINVAL)
return VM_FAULT_SIGBUS;
page = virt_to_page(__va(pa));
get_page(page);
vmf->page = page;
return 0;
}
static int alpha_core_agp_fetch_size(void)
{
return alpha_core_agp_sizes[0].size;
}
static int alpha_core_agp_configure(void)
{
alpha_agp_info *agp = agp_bridge->dev_private_data;
agp_bridge->gart_bus_addr = agp->aperture.bus_base;
return 0;
}
static void alpha_core_agp_cleanup(void)
{
alpha_agp_info *agp = agp_bridge->dev_private_data;
agp->ops->cleanup(agp);
}
static void alpha_core_agp_tlbflush(struct agp_memory *mem)
{
alpha_agp_info *agp = agp_bridge->dev_private_data;
alpha_mv.mv_pci_tbi(agp->hose, 0, -1);
}
static void alpha_core_agp_enable(struct agp_bridge_data *bridge, u32 mode)
{
alpha_agp_info *agp = bridge->dev_private_data;
agp->mode.lw = agp_collect_device_status(bridge, mode,
agp->capability.lw);
agp->mode.bits.enable = 1;
agp->ops->configure(agp);
agp_device_command(agp->mode.lw, false);
}
static int alpha_core_agp_insert_memory(struct agp_memory *mem, off_t pg_start,
int type)
{
alpha_agp_info *agp = agp_bridge->dev_private_data;
int num_entries, status;
void *temp;
if (type >= AGP_USER_TYPES || mem->type >= AGP_USER_TYPES)
return -EINVAL;
temp = agp_bridge->current_size;
num_entries = A_SIZE_FIX(temp)->num_entries;
if ((pg_start + mem->page_count) > num_entries)
return -EINVAL;
status = agp->ops->bind(agp, pg_start, mem);
mb();
alpha_core_agp_tlbflush(mem);
return status;
}
static int alpha_core_agp_remove_memory(struct agp_memory *mem, off_t pg_start,
int type)
{
alpha_agp_info *agp = agp_bridge->dev_private_data;
int status;
status = agp->ops->unbind(agp, pg_start, mem);
alpha_core_agp_tlbflush(mem);
return status;
}
static int alpha_core_agp_create_free_gatt_table(struct agp_bridge_data *a)
{
return 0;
}
int __init
alpha_core_agp_setup(void)
{
alpha_agp_info *agp = alpha_mv.agp_info();
struct pci_dev *pdev;
struct aper_size_info_fixed *aper_size;
if (!agp)
return -ENODEV;
if (agp->ops->setup(agp))
return -ENODEV;
aper_size = alpha_core_agp_sizes;
aper_size->size = agp->aperture.size / (1024 * 1024);
aper_size->num_entries = agp->aperture.size / PAGE_SIZE;
aper_size->page_order = __ffs(aper_size->num_entries / 1024);
pdev = pci_alloc_dev(NULL);
if (!pdev)
return -ENOMEM;
pdev->vendor = 0xffff;
pdev->device = 0xffff;
pdev->sysdata = agp->hose;
alpha_bridge = agp_alloc_bridge();
if (!alpha_bridge)
goto fail;
alpha_bridge->driver = &alpha_core_agp_driver;
alpha_bridge->vm_ops = &alpha_core_agp_vm_ops;
alpha_bridge->current_size = aper_size;
alpha_bridge->dev_private_data = agp;
alpha_bridge->dev = pdev;
alpha_bridge->mode = agp->capability.lw;
printk(KERN_INFO PFX "Detected AGP on hose %d\n", agp->hose->index);
return agp_add_bridge(alpha_bridge);
fail:
kfree(pdev);
return -ENOMEM;
}
static int __init agp_alpha_core_init(void)
{
if (agp_off)
return -EINVAL;
if (alpha_mv.agp_info)
return alpha_core_agp_setup();
return -ENODEV;
}
static void __exit agp_alpha_core_cleanup(void)
{
agp_remove_bridge(alpha_bridge);
agp_put_bridge(alpha_bridge);
}
