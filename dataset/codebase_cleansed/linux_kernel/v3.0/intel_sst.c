static irqreturn_t intel_sst_interrupt(int irq, void *context)
{
union interrupt_reg isr;
union ipc_header header;
union interrupt_reg imr;
struct intel_sst_drv *drv = (struct intel_sst_drv *) context;
unsigned int size = 0, str_id;
struct stream_info *stream ;
if (drv->sst_state == SST_SUSPENDED)
return IRQ_NONE;
isr.full = sst_shim_read(drv->shim, SST_ISRX);
if (isr.part.busy_interrupt) {
header.full = sst_shim_read(drv->shim, SST_IPCD);
if (header.part.msg_id == IPC_SST_PERIOD_ELAPSED) {
sst_clear_interrupt();
str_id = header.part.str_id;
stream = &sst_drv_ctx->streams[str_id];
if (stream->period_elapsed)
stream->period_elapsed(stream->pcm_substream);
return IRQ_HANDLED;
}
if (header.part.large)
size = header.part.data;
if (header.part.msg_id & REPLY_MSG) {
sst_drv_ctx->ipc_process_msg.header = header;
memcpy_fromio(sst_drv_ctx->ipc_process_msg.mailbox,
drv->mailbox + SST_MAILBOX_RCV, size);
queue_work(sst_drv_ctx->process_msg_wq,
&sst_drv_ctx->ipc_process_msg.wq);
} else {
sst_drv_ctx->ipc_process_reply.header = header;
memcpy_fromio(sst_drv_ctx->ipc_process_reply.mailbox,
drv->mailbox + SST_MAILBOX_RCV, size);
queue_work(sst_drv_ctx->process_reply_wq,
&sst_drv_ctx->ipc_process_reply.wq);
}
imr.full = sst_shim_read(drv->shim, SST_IMRX);
imr.part.busy_interrupt = 1;
sst_shim_write(sst_drv_ctx->shim, SST_IMRX, imr.full);
return IRQ_HANDLED;
} else if (isr.part.done_interrupt) {
header.full = sst_shim_read(drv->shim, SST_IPCX);
header.part.done = 0;
sst_shim_write(sst_drv_ctx->shim, SST_IPCX, header.full);
;
isr.part.done_interrupt = 1;
sst_shim_write(sst_drv_ctx->shim, SST_ISRX, isr.full);
queue_work(sst_drv_ctx->post_msg_wq,
&sst_drv_ctx->ipc_post_msg.wq);
return IRQ_HANDLED;
} else
return IRQ_NONE;
}
static int __devinit intel_sst_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
int i, ret = 0;
pr_debug("Probe for DID %x\n", pci->device);
mutex_lock(&drv_ctx_lock);
if (sst_drv_ctx) {
pr_err("Only one sst handle is supported\n");
mutex_unlock(&drv_ctx_lock);
return -EBUSY;
}
sst_drv_ctx = kzalloc(sizeof(*sst_drv_ctx), GFP_KERNEL);
if (!sst_drv_ctx) {
pr_err("malloc fail\n");
mutex_unlock(&drv_ctx_lock);
return -ENOMEM;
}
mutex_unlock(&drv_ctx_lock);
sst_drv_ctx->pci_id = pci->device;
mutex_init(&sst_drv_ctx->stream_lock);
mutex_init(&sst_drv_ctx->sst_lock);
sst_drv_ctx->pmic_state = SND_MAD_UN_INIT;
sst_drv_ctx->stream_cnt = 0;
sst_drv_ctx->encoded_cnt = 0;
sst_drv_ctx->am_cnt = 0;
sst_drv_ctx->pb_streams = 0;
sst_drv_ctx->cp_streams = 0;
sst_drv_ctx->unique_id = 0;
sst_drv_ctx->pmic_port_instance = SST_DEFAULT_PMIC_PORT;
INIT_LIST_HEAD(&sst_drv_ctx->ipc_dispatch_list);
INIT_WORK(&sst_drv_ctx->ipc_post_msg.wq, sst_post_message);
INIT_WORK(&sst_drv_ctx->ipc_process_msg.wq, sst_process_message);
INIT_WORK(&sst_drv_ctx->ipc_process_reply.wq, sst_process_reply);
INIT_WORK(&sst_drv_ctx->mad_ops.wq, sst_process_mad_ops);
init_waitqueue_head(&sst_drv_ctx->wait_queue);
sst_drv_ctx->mad_wq = create_workqueue("sst_mad_wq");
if (!sst_drv_ctx->mad_wq)
goto do_free_drv_ctx;
sst_drv_ctx->post_msg_wq = create_workqueue("sst_post_msg_wq");
if (!sst_drv_ctx->post_msg_wq)
goto free_mad_wq;
sst_drv_ctx->process_msg_wq = create_workqueue("sst_process_msg_wqq");
if (!sst_drv_ctx->process_msg_wq)
goto free_post_msg_wq;
sst_drv_ctx->process_reply_wq = create_workqueue("sst_proces_reply_wq");
if (!sst_drv_ctx->process_reply_wq)
goto free_process_msg_wq;
for (i = 0; i < MAX_ACTIVE_STREAM; i++) {
sst_drv_ctx->alloc_block[i].sst_id = BLOCK_UNINIT;
sst_drv_ctx->alloc_block[i].ops_block.condition = false;
}
spin_lock_init(&sst_drv_ctx->list_spin_lock);
sst_drv_ctx->max_streams = pci_id->driver_data;
pr_debug("Got drv data max stream %d\n",
sst_drv_ctx->max_streams);
for (i = 1; i <= sst_drv_ctx->max_streams; i++) {
struct stream_info *stream = &sst_drv_ctx->streams[i];
INIT_LIST_HEAD(&stream->bufs);
mutex_init(&stream->lock);
spin_lock_init(&stream->pcm_lock);
}
if (sst_drv_ctx->pci_id == SST_MRST_PCI_ID) {
sst_drv_ctx->mmap_mem = NULL;
sst_drv_ctx->mmap_len = SST_MMAP_PAGES * PAGE_SIZE;
while (sst_drv_ctx->mmap_len > 0) {
sst_drv_ctx->mmap_mem =
kzalloc(sst_drv_ctx->mmap_len, GFP_KERNEL);
if (sst_drv_ctx->mmap_mem) {
pr_debug("Got memory %p size 0x%x\n",
sst_drv_ctx->mmap_mem,
sst_drv_ctx->mmap_len);
break;
}
if (sst_drv_ctx->mmap_len < (SST_MMAP_STEP*PAGE_SIZE)) {
pr_err("mem alloc fail...abort!!\n");
ret = -ENOMEM;
goto free_process_reply_wq;
}
sst_drv_ctx->mmap_len -= (SST_MMAP_STEP * PAGE_SIZE);
pr_debug("mem alloc failed...trying %d\n",
sst_drv_ctx->mmap_len);
}
}
ret = pci_enable_device(pci);
if (ret) {
pr_err("device can't be enabled\n");
goto do_free_mem;
}
sst_drv_ctx->pci = pci_dev_get(pci);
ret = pci_request_regions(pci, SST_DRV_NAME);
if (ret)
goto do_disable_device;
sst_drv_ctx->shim_phy_add = pci_resource_start(pci, 1);
sst_drv_ctx->shim = pci_ioremap_bar(pci, 1);
if (!sst_drv_ctx->shim)
goto do_release_regions;
pr_debug("SST Shim Ptr %p\n", sst_drv_ctx->shim);
sst_drv_ctx->mailbox = pci_ioremap_bar(pci, 2);
if (!sst_drv_ctx->mailbox)
goto do_unmap_shim;
pr_debug("SRAM Ptr %p\n", sst_drv_ctx->mailbox);
sst_drv_ctx->iram = pci_ioremap_bar(pci, 3);
if (!sst_drv_ctx->iram)
goto do_unmap_sram;
pr_debug("IRAM Ptr %p\n", sst_drv_ctx->iram);
sst_drv_ctx->dram = pci_ioremap_bar(pci, 4);
if (!sst_drv_ctx->dram)
goto do_unmap_iram;
pr_debug("DRAM Ptr %p\n", sst_drv_ctx->dram);
mutex_lock(&sst_drv_ctx->sst_lock);
sst_drv_ctx->sst_state = SST_UN_INIT;
mutex_unlock(&sst_drv_ctx->sst_lock);
ret = request_irq(pci->irq, intel_sst_interrupt,
IRQF_SHARED, SST_DRV_NAME, sst_drv_ctx);
if (ret)
goto do_unmap_dram;
pr_debug("Registered IRQ 0x%x\n", pci->irq);
ret = misc_register(&lpe_ctrl);
if (ret) {
pr_err("couldn't register control device\n");
goto do_free_irq;
}
if (sst_drv_ctx->pci_id == SST_MRST_PCI_ID) {
ret = misc_register(&lpe_dev);
if (ret) {
pr_err("couldn't register LPE device\n");
goto do_free_misc;
}
} else if (sst_drv_ctx->pci_id == SST_MFLD_PCI_ID) {
u32 csr;
sst_drv_ctx->fw_cntx = kzalloc(FW_CONTEXT_MEM, GFP_KERNEL);
if (!sst_drv_ctx->fw_cntx) {
ret = -ENOMEM;
goto do_free_misc;
}
sst_drv_ctx->fw_cntx_size = 0;
csr = sst_shim_read(sst_drv_ctx->shim, SST_CSR);
csr |= 0x30060;
sst_shim_write(sst_drv_ctx->shim, SST_CSR, csr);
}
sst_drv_ctx->lpe_stalled = 0;
pci_set_drvdata(pci, sst_drv_ctx);
pm_runtime_allow(&pci->dev);
pm_runtime_put_noidle(&pci->dev);
pr_debug("...successfully done!!!\n");
return ret;
do_free_misc:
misc_deregister(&lpe_ctrl);
do_free_irq:
free_irq(pci->irq, sst_drv_ctx);
do_unmap_dram:
iounmap(sst_drv_ctx->dram);
do_unmap_iram:
iounmap(sst_drv_ctx->iram);
do_unmap_sram:
iounmap(sst_drv_ctx->mailbox);
do_unmap_shim:
iounmap(sst_drv_ctx->shim);
do_release_regions:
pci_release_regions(pci);
do_disable_device:
pci_disable_device(pci);
do_free_mem:
kfree(sst_drv_ctx->mmap_mem);
free_process_reply_wq:
destroy_workqueue(sst_drv_ctx->process_reply_wq);
free_process_msg_wq:
destroy_workqueue(sst_drv_ctx->process_msg_wq);
free_post_msg_wq:
destroy_workqueue(sst_drv_ctx->post_msg_wq);
free_mad_wq:
destroy_workqueue(sst_drv_ctx->mad_wq);
do_free_drv_ctx:
kfree(sst_drv_ctx);
sst_drv_ctx = NULL;
pr_err("Probe failed with %d\n", ret);
return ret;
}
static void __devexit intel_sst_remove(struct pci_dev *pci)
{
pm_runtime_get_noresume(&pci->dev);
pm_runtime_forbid(&pci->dev);
pci_dev_put(sst_drv_ctx->pci);
mutex_lock(&sst_drv_ctx->sst_lock);
sst_drv_ctx->sst_state = SST_UN_INIT;
mutex_unlock(&sst_drv_ctx->sst_lock);
misc_deregister(&lpe_ctrl);
free_irq(pci->irq, sst_drv_ctx);
iounmap(sst_drv_ctx->dram);
iounmap(sst_drv_ctx->iram);
iounmap(sst_drv_ctx->mailbox);
iounmap(sst_drv_ctx->shim);
sst_drv_ctx->pmic_state = SND_MAD_UN_INIT;
if (sst_drv_ctx->pci_id == SST_MRST_PCI_ID) {
misc_deregister(&lpe_dev);
kfree(sst_drv_ctx->mmap_mem);
} else
kfree(sst_drv_ctx->fw_cntx);
flush_scheduled_work();
destroy_workqueue(sst_drv_ctx->process_reply_wq);
destroy_workqueue(sst_drv_ctx->process_msg_wq);
destroy_workqueue(sst_drv_ctx->post_msg_wq);
destroy_workqueue(sst_drv_ctx->mad_wq);
kfree(pci_get_drvdata(pci));
sst_drv_ctx = NULL;
pci_release_regions(pci);
pci_disable_device(pci);
pci_set_drvdata(pci, NULL);
}
void sst_save_dsp_context(void)
{
struct snd_sst_ctxt_params fw_context;
unsigned int pvt_id, i;
struct ipc_post *msg = NULL;
if (sst_drv_ctx->pci_id != SST_MFLD_PCI_ID)
return;
if (sst_drv_ctx->sst_state != SST_FW_RUNNING) {
pr_debug("fw not running no context save ...\n");
return;
}
if (sst_create_large_msg(&msg))
return;
pvt_id = sst_assign_pvt_id(sst_drv_ctx);
i = sst_get_block_stream(sst_drv_ctx);
sst_drv_ctx->alloc_block[i].sst_id = pvt_id;
sst_fill_header(&msg->header, IPC_IA_GET_FW_CTXT, 1, pvt_id);
msg->header.part.data = sizeof(fw_context) + sizeof(u32);
fw_context.address = virt_to_phys((void *)sst_drv_ctx->fw_cntx);
fw_context.size = FW_CONTEXT_MEM;
memcpy(msg->mailbox_data, &msg->header, sizeof(u32));
memcpy(msg->mailbox_data + sizeof(u32),
&fw_context, sizeof(fw_context));
spin_lock(&sst_drv_ctx->list_spin_lock);
list_add_tail(&msg->node, &sst_drv_ctx->ipc_dispatch_list);
spin_unlock(&sst_drv_ctx->list_spin_lock);
sst_post_message(&sst_drv_ctx->ipc_post_msg_wq);
if (sst_wait_timeout(sst_drv_ctx, &sst_drv_ctx->alloc_block[i]))
pr_debug("err fw context save timeout ...\n");
sst_drv_ctx->alloc_block[i].sst_id = BLOCK_UNINIT;
pr_debug("fw context saved ...\n");
return;
}
int intel_sst_suspend(struct pci_dev *pci, pm_message_t state)
{
union config_status_reg csr;
pr_debug("intel_sst_suspend called\n");
if (sst_drv_ctx->stream_cnt) {
pr_err("active streams,not able to suspend\n");
return -EBUSY;
}
sst_save_dsp_context();
csr.full = sst_shim_read(sst_drv_ctx->shim, SST_CSR);
csr.full = csr.full | 0x2;
mutex_lock(&sst_drv_ctx->sst_lock);
sst_drv_ctx->sst_state = SST_SUSPENDED;
sst_shim_write(sst_drv_ctx->shim, SST_CSR, csr.full);
mutex_unlock(&sst_drv_ctx->sst_lock);
pci_set_drvdata(pci, sst_drv_ctx);
pci_save_state(pci);
pci_disable_device(pci);
pci_set_power_state(pci, PCI_D3hot);
return 0;
}
int intel_sst_resume(struct pci_dev *pci)
{
int ret = 0;
pr_debug("intel_sst_resume called\n");
if (sst_drv_ctx->sst_state != SST_SUSPENDED) {
pr_err("SST is not in suspended state\n");
return 0;
}
sst_drv_ctx = pci_get_drvdata(pci);
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
ret = pci_enable_device(pci);
if (ret)
pr_err("device can't be enabled\n");
mutex_lock(&sst_drv_ctx->sst_lock);
sst_drv_ctx->sst_state = SST_UN_INIT;
mutex_unlock(&sst_drv_ctx->sst_lock);
return 0;
}
static int intel_sst_runtime_suspend(struct device *dev)
{
union config_status_reg csr;
pr_debug("intel_sst_runtime_suspend called\n");
if (sst_drv_ctx->stream_cnt) {
pr_err("active streams,not able to suspend\n");
return -EBUSY;
}
sst_save_dsp_context();
csr.full = sst_shim_read(sst_drv_ctx->shim, SST_CSR);
csr.full = csr.full | 0x2;
mutex_lock(&sst_drv_ctx->sst_lock);
sst_drv_ctx->sst_state = SST_SUSPENDED;
sst_shim_write(sst_drv_ctx->shim, SST_CSR, csr.full);
mutex_unlock(&sst_drv_ctx->sst_lock);
return 0;
}
static int intel_sst_runtime_resume(struct device *dev)
{
pr_debug("intel_sst_runtime_resume called\n");
if (sst_drv_ctx->sst_state != SST_SUSPENDED) {
pr_err("SST is not in suspended state\n");
return 0;
}
mutex_lock(&sst_drv_ctx->sst_lock);
sst_drv_ctx->sst_state = SST_UN_INIT;
mutex_unlock(&sst_drv_ctx->sst_lock);
return 0;
}
static int intel_sst_runtime_idle(struct device *dev)
{
pr_debug("runtime_idle called\n");
if (sst_drv_ctx->stream_cnt == 0 && sst_drv_ctx->am_cnt == 0)
pm_schedule_suspend(dev, SST_SUSPEND_DELAY);
return -EBUSY;
}
static int __init intel_sst_init(void)
{
int ret = 0;
pr_debug("INFO: ******** SST DRIVER loading.. Ver: %s\n",
SST_DRIVER_VERSION);
mutex_init(&drv_ctx_lock);
ret = pci_register_driver(&driver);
if (ret)
pr_err("PCI register failed\n");
return ret;
}
static void __exit intel_sst_exit(void)
{
pci_unregister_driver(&driver);
pr_debug("driver unloaded\n");
sst_drv_ctx = NULL;
return;
}
