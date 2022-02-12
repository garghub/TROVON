int rio_mport_send_doorbell(struct rio_mport *mport, u16 destid, u16 data)
{
return mport->ops->dsend(mport, mport->id, destid, data);
}
