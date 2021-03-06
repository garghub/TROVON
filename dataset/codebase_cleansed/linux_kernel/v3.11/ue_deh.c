static void mmu_fault_dpc(unsigned long data)
{
struct deh_mgr *deh = (void *)data;
if (!deh)
return;
bridge_deh_notify(deh, DSP_MMUFAULT, 0);
}
static irqreturn_t mmu_fault_isr(int irq, void *data)
{
struct deh_mgr *deh = data;
struct cfg_hostres *resources;
u32 event;
if (!deh)
return IRQ_HANDLED;
resources = deh->bridge_context->resources;
if (!resources) {
dev_dbg(bridge, "%s: Failed to get Host Resources\n",
__func__);
return IRQ_HANDLED;
}
hw_mmu_event_status(resources->dmmu_base, &event);
if (event == HW_MMU_TRANSLATION_FAULT) {
hw_mmu_fault_addr_read(resources->dmmu_base, &fault_addr);
dev_dbg(bridge, "%s: event=0x%x, fault_addr=0x%x\n", __func__,
event, fault_addr);
tasklet_schedule(&deh->dpc_tasklet);
hw_mmu_event_disable(resources->dmmu_base,
HW_MMU_TRANSLATION_FAULT);
} else {
hw_mmu_event_disable(resources->dmmu_base,
HW_MMU_ALL_INTERRUPTS);
}
return IRQ_HANDLED;
}
int bridge_deh_create(struct deh_mgr **ret_deh,
struct dev_object *hdev_obj)
{
int status;
struct deh_mgr *deh;
struct bridge_dev_context *hbridge_context = NULL;
dev_get_bridge_context(hdev_obj, &hbridge_context);
deh = kzalloc(sizeof(*deh), GFP_KERNEL);
if (!deh) {
status = -ENOMEM;
goto err;
}
deh->ntfy_obj = kmalloc(sizeof(struct ntfy_object), GFP_KERNEL);
if (!deh->ntfy_obj) {
status = -ENOMEM;
goto err;
}
ntfy_init(deh->ntfy_obj);
tasklet_init(&deh->dpc_tasklet, mmu_fault_dpc, (u32) deh);
deh->bridge_context = hbridge_context;
status = request_irq(INT_DSP_MMU_IRQ, mmu_fault_isr, 0,
"DspBridge\tiommu fault", deh);
if (status < 0)
goto err;
*ret_deh = deh;
return 0;
err:
bridge_deh_destroy(deh);
*ret_deh = NULL;
return status;
}
int bridge_deh_destroy(struct deh_mgr *deh)
{
if (!deh)
return -EFAULT;
if (deh->ntfy_obj) {
ntfy_delete(deh->ntfy_obj);
kfree(deh->ntfy_obj);
}
free_irq(INT_DSP_MMU_IRQ, deh);
tasklet_kill(&deh->dpc_tasklet);
kfree(deh);
return 0;
}
int bridge_deh_register_notify(struct deh_mgr *deh, u32 event_mask,
u32 notify_type,
struct dsp_notification *hnotification)
{
if (!deh)
return -EFAULT;
if (event_mask)
return ntfy_register(deh->ntfy_obj, hnotification,
event_mask, notify_type);
else
return ntfy_unregister(deh->ntfy_obj, hnotification);
}
static void mmu_fault_print_stack(struct bridge_dev_context *dev_context)
{
struct cfg_hostres *resources;
struct hw_mmu_map_attrs_t map_attrs = {
.endianism = HW_LITTLE_ENDIAN,
.element_size = HW_ELEM_SIZE16BIT,
.mixed_size = HW_MMU_CPUES,
};
void *dummy_va_addr;
resources = dev_context->resources;
dummy_va_addr = (void *)__get_free_page(GFP_ATOMIC);
hw_mmu_twl_disable(resources->dmmu_base);
hw_mmu_tlb_flush_all(resources->dmmu_base);
hw_mmu_tlb_add(resources->dmmu_base,
virt_to_phys(dummy_va_addr), fault_addr,
HW_PAGE_SIZE4KB, 1,
&map_attrs, HW_SET, HW_SET);
dsp_clk_enable(DSP_CLK_GPT8);
dsp_gpt_wait_overflow(DSP_CLK_GPT8, 0xfffffffe);
hw_mmu_event_ack(resources->dmmu_base,
HW_MMU_TRANSLATION_FAULT);
dump_dsp_stack(dev_context);
dsp_clk_disable(DSP_CLK_GPT8);
hw_mmu_disable(resources->dmmu_base);
free_page((unsigned long)dummy_va_addr);
}
static inline const char *event_to_string(int event)
{
switch (event) {
case DSP_SYSERROR: return "DSP_SYSERROR"; break;
case DSP_MMUFAULT: return "DSP_MMUFAULT"; break;
case DSP_PWRERROR: return "DSP_PWRERROR"; break;
case DSP_WDTOVERFLOW: return "DSP_WDTOVERFLOW"; break;
default: return "unknown event"; break;
}
}
void bridge_deh_notify(struct deh_mgr *deh, int event, int info)
{
struct bridge_dev_context *dev_context;
const char *str = event_to_string(event);
if (!deh)
return;
dev_dbg(bridge, "%s: device exception", __func__);
dev_context = deh->bridge_context;
switch (event) {
case DSP_SYSERROR:
dev_err(bridge, "%s: %s, info=0x%x", __func__,
str, info);
#ifdef CONFIG_TIDSPBRIDGE_BACKTRACE
dump_dl_modules(dev_context);
dump_dsp_stack(dev_context);
#endif
break;
case DSP_MMUFAULT:
dev_err(bridge, "%s: %s, addr=0x%x", __func__,
str, fault_addr);
#ifdef CONFIG_TIDSPBRIDGE_BACKTRACE
print_dsp_trace_buffer(dev_context);
dump_dl_modules(dev_context);
mmu_fault_print_stack(dev_context);
#endif
break;
default:
dev_err(bridge, "%s: %s", __func__, str);
break;
}
if (dev_context->brd_state != BRD_ERROR) {
ntfy_notify(deh->ntfy_obj, event);
#ifdef CONFIG_TIDSPBRIDGE_RECOVERY
bridge_recover_schedule();
#endif
}
dev_context->brd_state = BRD_ERROR;
dsp_clock_disable_all(dev_context->dsp_per_clks);
dsp_wdt_enable(false);
}
