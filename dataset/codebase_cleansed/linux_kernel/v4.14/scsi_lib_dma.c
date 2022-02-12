int scsi_dma_map(struct scsi_cmnd *cmd)
{
int nseg = 0;
if (scsi_sg_count(cmd)) {
struct device *dev = cmd->device->host->dma_dev;
nseg = dma_map_sg(dev, scsi_sglist(cmd), scsi_sg_count(cmd),
cmd->sc_data_direction);
if (unlikely(!nseg))
return -ENOMEM;
}
return nseg;
}
void scsi_dma_unmap(struct scsi_cmnd *cmd)
{
if (scsi_sg_count(cmd)) {
struct device *dev = cmd->device->host->dma_dev;
dma_unmap_sg(dev, scsi_sglist(cmd), scsi_sg_count(cmd),
cmd->sc_data_direction);
}
}
