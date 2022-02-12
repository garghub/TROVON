int stdma_try_lock(irq_handler_t handler, void *data)
{
unsigned long flags;
local_irq_save(flags);
if (stdma_locked) {
local_irq_restore(flags);
return 0;
}
stdma_locked = 1;
stdma_isr = handler;
stdma_isr_data = data;
local_irq_restore(flags);
return 1;
}
void stdma_lock(irq_handler_t handler, void *data)
{
wait_event(stdma_wait, stdma_try_lock(handler, data));
}
void stdma_release(void)
{
unsigned long flags;
local_irq_save(flags);
stdma_locked = 0;
stdma_isr = NULL;
stdma_isr_data = NULL;
wake_up(&stdma_wait);
local_irq_restore(flags);
}
int stdma_is_locked_by(irq_handler_t handler)
{
unsigned long flags;
int result;
local_irq_save(flags);
result = stdma_locked && (stdma_isr == handler);
local_irq_restore(flags);
return result;
}
int stdma_islocked(void)
{
return stdma_locked;
}
void __init stdma_init(void)
{
stdma_isr = NULL;
if (request_irq(IRQ_MFP_FDC, stdma_int, IRQ_TYPE_SLOW | IRQF_SHARED,
"ST-DMA floppy,ACSI,IDE,Falcon-SCSI", stdma_int))
pr_err("Couldn't register ST-DMA interrupt\n");
}
static irqreturn_t stdma_int(int irq, void *dummy)
{
if (stdma_isr)
(*stdma_isr)(irq, stdma_isr_data);
return IRQ_HANDLED;
}
