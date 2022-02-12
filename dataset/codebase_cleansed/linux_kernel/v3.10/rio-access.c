int rio_mport_send_doorbell(struct rio_mport *mport, u16 destid, u16 data)
{
int res;
unsigned long flags;
spin_lock_irqsave(&rio_doorbell_lock, flags);
res = mport->ops->dsend(mport, mport->id, destid, data);
spin_unlock_irqrestore(&rio_doorbell_lock, flags);
return res;
}
