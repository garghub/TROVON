static int
hv_uio_mmap(struct uio_info *info, struct vm_area_struct *vma)
{
int mi;
if (vma->vm_pgoff >= MAX_UIO_MAPS)
return -EINVAL;
if (info->mem[vma->vm_pgoff].size == 0)
return -EINVAL;
mi = (int)vma->vm_pgoff;
return remap_pfn_range(vma, vma->vm_start,
info->mem[mi].addr >> PAGE_SHIFT,
vma->vm_end - vma->vm_start, vma->vm_page_prot);
}
static int
hv_uio_irqcontrol(struct uio_info *info, s32 irq_state)
{
struct hv_uio_private_data *pdata = info->priv;
struct hv_device *dev = pdata->device;
dev->channel->inbound.ring_buffer->interrupt_mask = !irq_state;
virt_mb();
return 0;
}
static void hv_uio_channel_cb(void *context)
{
struct hv_uio_private_data *pdata = context;
struct hv_device *dev = pdata->device;
dev->channel->inbound.ring_buffer->interrupt_mask = 1;
virt_mb();
uio_event_notify(&pdata->info);
}
static int
hv_uio_probe(struct hv_device *dev,
const struct hv_vmbus_device_id *dev_id)
{
struct hv_uio_private_data *pdata;
int ret;
pdata = kzalloc(sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
ret = vmbus_open(dev->channel, HV_RING_SIZE * PAGE_SIZE,
HV_RING_SIZE * PAGE_SIZE, NULL, 0,
hv_uio_channel_cb, pdata);
if (ret)
goto fail;
dev->channel->inbound.ring_buffer->interrupt_mask = 1;
set_channel_read_mode(dev->channel, HV_CALL_DIRECT);
pdata->info.name = "uio_hv_generic";
pdata->info.version = DRIVER_VERSION;
pdata->info.irqcontrol = hv_uio_irqcontrol;
pdata->info.mmap = hv_uio_mmap;
pdata->info.irq = UIO_IRQ_CUSTOM;
pdata->info.mem[TXRX_RING_MAP].name = "txrx_rings";
pdata->info.mem[TXRX_RING_MAP].addr
= virt_to_phys(dev->channel->ringbuffer_pages);
pdata->info.mem[TXRX_RING_MAP].size
= dev->channel->ringbuffer_pagecount * PAGE_SIZE;
pdata->info.mem[TXRX_RING_MAP].memtype = UIO_MEM_LOGICAL;
pdata->info.mem[INT_PAGE_MAP].name = "int_page";
pdata->info.mem[INT_PAGE_MAP].addr =
virt_to_phys(vmbus_connection.int_page);
pdata->info.mem[INT_PAGE_MAP].size = PAGE_SIZE;
pdata->info.mem[INT_PAGE_MAP].memtype = UIO_MEM_LOGICAL;
pdata->info.mem[MON_PAGE_MAP].name = "monitor_pages";
pdata->info.mem[MON_PAGE_MAP].addr =
virt_to_phys(vmbus_connection.monitor_pages[1]);
pdata->info.mem[MON_PAGE_MAP].size = PAGE_SIZE;
pdata->info.mem[MON_PAGE_MAP].memtype = UIO_MEM_LOGICAL;
pdata->info.priv = pdata;
pdata->device = dev;
ret = uio_register_device(&dev->device, &pdata->info);
if (ret) {
dev_err(&dev->device, "hv_uio register failed\n");
goto fail_close;
}
hv_set_drvdata(dev, pdata);
return 0;
fail_close:
vmbus_close(dev->channel);
fail:
kfree(pdata);
return ret;
}
static int
hv_uio_remove(struct hv_device *dev)
{
struct hv_uio_private_data *pdata = hv_get_drvdata(dev);
if (!pdata)
return 0;
uio_unregister_device(&pdata->info);
hv_set_drvdata(dev, NULL);
vmbus_close(dev->channel);
kfree(pdata);
return 0;
}
static int __init
hyperv_module_init(void)
{
return vmbus_driver_register(&hv_uio_drv);
}
static void __exit
hyperv_module_exit(void)
{
vmbus_driver_unregister(&hv_uio_drv);
}
