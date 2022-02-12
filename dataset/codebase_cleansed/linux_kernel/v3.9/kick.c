void kick_register_func(struct kick_irq_handler *kh)
{
unsigned long flags;
spin_lock_irqsave(&kick_handlers_lock, flags);
list_add_tail(&kh->list, &kick_handlers_list);
spin_unlock_irqrestore(&kick_handlers_lock, flags);
}
void kick_unregister_func(struct kick_irq_handler *kh)
{
unsigned long flags;
spin_lock_irqsave(&kick_handlers_lock, flags);
list_del(&kh->list);
spin_unlock_irqrestore(&kick_handlers_lock, flags);
}
TBIRES
kick_handler(TBIRES State, int SigNum, int Triggers, int Inst, PTBI pTBI)
{
struct kick_irq_handler *kh;
struct list_head *lh;
int handled = 0;
TBIRES ret;
head_end(State, ~INTS_OFF_MASK);
if (State.Sig.SaveMask & TBICTX_PRIV_BIT)
restart_critical_section(State);
trace_hardirqs_off();
spin_lock(&kick_handlers_lock);
list_for_each(lh, &kick_handlers_list) {
kh = list_entry(lh, struct kick_irq_handler, list);
ret = kh->func(State, SigNum, Triggers, Inst, pTBI, &handled);
if (handled)
break;
}
spin_unlock(&kick_handlers_lock);
WARN_ON(!handled);
return tail_end(ret);
}
