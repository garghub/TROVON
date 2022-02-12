static int aac_rkt_select_comm(struct aac_dev *dev, int comm)
{
int retval;
retval = aac_rx_select_comm(dev, comm);
if (comm == AAC_COMM_MESSAGE) {
if (dev->scsi_host_ptr->can_queue > AAC_NUM_IO_FIB_RKT) {
dev->init->MaxIoCommands =
cpu_to_le32(AAC_NUM_IO_FIB_RKT + AAC_NUM_MGT_FIB);
dev->scsi_host_ptr->can_queue = AAC_NUM_IO_FIB_RKT;
}
}
return retval;
}
static int aac_rkt_ioremap(struct aac_dev * dev, u32 size)
{
if (!size) {
iounmap(dev->regs.rkt);
return 0;
}
dev->base = dev->regs.rkt = ioremap(dev->base_start, size);
if (dev->base == NULL)
return -1;
dev->IndexRegs = &dev->regs.rkt->IndexRegs;
return 0;
}
int aac_rkt_init(struct aac_dev *dev)
{
dev->a_ops.adapter_ioremap = aac_rkt_ioremap;
dev->a_ops.adapter_comm = aac_rkt_select_comm;
return _aac_rx_init(dev);
}
