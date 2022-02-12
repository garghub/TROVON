void sas_init_dev(struct domain_device *dev)
{
INIT_LIST_HEAD(&dev->siblings);
INIT_LIST_HEAD(&dev->dev_list_node);
switch (dev->dev_type) {
case SAS_END_DEV:
break;
case EDGE_DEV:
case FANOUT_DEV:
INIT_LIST_HEAD(&dev->ex_dev.children);
break;
case SATA_DEV:
case SATA_PM:
case SATA_PM_PORT:
INIT_LIST_HEAD(&dev->sata_dev.children);
break;
default:
break;
}
}
static int sas_get_port_device(struct asd_sas_port *port)
{
unsigned long flags;
struct asd_sas_phy *phy;
struct sas_rphy *rphy;
struct domain_device *dev;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
spin_lock_irqsave(&port->phy_list_lock, flags);
if (list_empty(&port->phy_list)) {
spin_unlock_irqrestore(&port->phy_list_lock, flags);
kfree(dev);
return -ENODEV;
}
phy = container_of(port->phy_list.next, struct asd_sas_phy, port_phy_el);
spin_lock(&phy->frame_rcvd_lock);
memcpy(dev->frame_rcvd, phy->frame_rcvd, min(sizeof(dev->frame_rcvd),
(size_t)phy->frame_rcvd_size));
spin_unlock(&phy->frame_rcvd_lock);
spin_unlock_irqrestore(&port->phy_list_lock, flags);
if (dev->frame_rcvd[0] == 0x34 && port->oob_mode == SATA_OOB_MODE) {
struct dev_to_host_fis *fis =
(struct dev_to_host_fis *) dev->frame_rcvd;
if (fis->interrupt_reason == 1 && fis->lbal == 1 &&
fis->byte_count_low==0x69 && fis->byte_count_high == 0x96
&& (fis->device & ~0x10) == 0)
dev->dev_type = SATA_PM;
else
dev->dev_type = SATA_DEV;
dev->tproto = SAS_PROTOCOL_SATA;
} else {
struct sas_identify_frame *id =
(struct sas_identify_frame *) dev->frame_rcvd;
dev->dev_type = id->dev_type;
dev->iproto = id->initiator_bits;
dev->tproto = id->target_bits;
}
sas_init_dev(dev);
switch (dev->dev_type) {
case SAS_END_DEV:
case SATA_DEV:
rphy = sas_end_device_alloc(port->port);
break;
case EDGE_DEV:
rphy = sas_expander_alloc(port->port,
SAS_EDGE_EXPANDER_DEVICE);
break;
case FANOUT_DEV:
rphy = sas_expander_alloc(port->port,
SAS_FANOUT_EXPANDER_DEVICE);
break;
default:
printk("ERROR: Unidentified device type %d\n", dev->dev_type);
rphy = NULL;
break;
}
if (!rphy) {
kfree(dev);
return -ENODEV;
}
rphy->identify.phy_identifier = phy->phy->identify.phy_identifier;
memcpy(dev->sas_addr, port->attached_sas_addr, SAS_ADDR_SIZE);
sas_fill_in_rphy(dev, rphy);
sas_hash_addr(dev->hashed_sas_addr, dev->sas_addr);
port->port_dev = dev;
dev->port = port;
dev->linkrate = port->linkrate;
dev->min_linkrate = port->linkrate;
dev->max_linkrate = port->linkrate;
dev->pathways = port->num_phys;
memset(port->disc.fanout_sas_addr, 0, SAS_ADDR_SIZE);
memset(port->disc.eeds_a, 0, SAS_ADDR_SIZE);
memset(port->disc.eeds_b, 0, SAS_ADDR_SIZE);
port->disc.max_level = 0;
dev->rphy = rphy;
spin_lock_irq(&port->dev_list_lock);
list_add_tail(&dev->dev_list_node, &port->dev_list);
spin_unlock_irq(&port->dev_list_lock);
return 0;
}
int sas_notify_lldd_dev_found(struct domain_device *dev)
{
int res = 0;
struct sas_ha_struct *sas_ha = dev->port->ha;
struct Scsi_Host *shost = sas_ha->core.shost;
struct sas_internal *i = to_sas_internal(shost->transportt);
if (i->dft->lldd_dev_found) {
res = i->dft->lldd_dev_found(dev);
if (res) {
printk("sas: driver on pcidev %s cannot handle "
"device %llx, error:%d\n",
dev_name(sas_ha->dev),
SAS_ADDR(dev->sas_addr), res);
}
}
return res;
}
void sas_notify_lldd_dev_gone(struct domain_device *dev)
{
struct sas_ha_struct *sas_ha = dev->port->ha;
struct Scsi_Host *shost = sas_ha->core.shost;
struct sas_internal *i = to_sas_internal(shost->transportt);
if (i->dft->lldd_dev_gone)
i->dft->lldd_dev_gone(dev);
}
int sas_discover_end_dev(struct domain_device *dev)
{
int res;
res = sas_notify_lldd_dev_found(dev);
if (res)
goto out_err2;
res = sas_rphy_add(dev->rphy);
if (res)
goto out_err;
return 0;
out_err:
sas_notify_lldd_dev_gone(dev);
out_err2:
return res;
}
static void sas_unregister_common_dev(struct asd_sas_port *port, struct domain_device *dev)
{
sas_notify_lldd_dev_gone(dev);
if (!dev->parent)
dev->port->port_dev = NULL;
else
list_del_init(&dev->siblings);
spin_lock_irq(&port->dev_list_lock);
list_del_init(&dev->dev_list_node);
spin_unlock_irq(&port->dev_list_lock);
}
void sas_unregister_dev(struct asd_sas_port *port, struct domain_device *dev)
{
if (dev->rphy) {
sas_remove_children(&dev->rphy->dev);
sas_rphy_delete(dev->rphy);
dev->rphy = NULL;
}
if (dev->dev_type == EDGE_DEV || dev->dev_type == FANOUT_DEV) {
kfree(dev->ex_dev.ex_phy);
dev->ex_dev.ex_phy = NULL;
}
sas_unregister_common_dev(port, dev);
}
void sas_unregister_domain_devices(struct asd_sas_port *port)
{
struct domain_device *dev, *n;
list_for_each_entry_safe_reverse(dev, n, &port->dev_list, dev_list_node)
sas_unregister_dev(port, dev);
port->port->rphy = NULL;
}
static void sas_discover_domain(struct work_struct *work)
{
struct domain_device *dev;
int error = 0;
struct sas_discovery_event *ev =
container_of(work, struct sas_discovery_event, work);
struct asd_sas_port *port = ev->port;
sas_begin_event(DISCE_DISCOVER_DOMAIN, &port->disc.disc_event_lock,
&port->disc.pending);
if (port->port_dev)
return;
error = sas_get_port_device(port);
if (error)
return;
dev = port->port_dev;
SAS_DPRINTK("DOING DISCOVERY on port %d, pid:%d\n", port->id,
task_pid_nr(current));
switch (dev->dev_type) {
case SAS_END_DEV:
error = sas_discover_end_dev(dev);
break;
case EDGE_DEV:
case FANOUT_DEV:
error = sas_discover_root_expander(dev);
break;
case SATA_DEV:
case SATA_PM:
#ifdef CONFIG_SCSI_SAS_ATA
error = sas_discover_sata(dev);
break;
#else
SAS_DPRINTK("ATA device seen but CONFIG_SCSI_SAS_ATA=N so cannot attach\n");
#endif
default:
error = -ENXIO;
SAS_DPRINTK("unhandled device %d\n", dev->dev_type);
break;
}
if (error) {
sas_rphy_free(dev->rphy);
dev->rphy = NULL;
spin_lock_irq(&port->dev_list_lock);
list_del_init(&dev->dev_list_node);
spin_unlock_irq(&port->dev_list_lock);
kfree(dev);
port->port_dev = NULL;
}
SAS_DPRINTK("DONE DISCOVERY on port %d, pid:%d, result:%d\n", port->id,
task_pid_nr(current), error);
}
static void sas_revalidate_domain(struct work_struct *work)
{
int res = 0;
struct sas_discovery_event *ev =
container_of(work, struct sas_discovery_event, work);
struct asd_sas_port *port = ev->port;
sas_begin_event(DISCE_REVALIDATE_DOMAIN, &port->disc.disc_event_lock,
&port->disc.pending);
SAS_DPRINTK("REVALIDATING DOMAIN on port %d, pid:%d\n", port->id,
task_pid_nr(current));
if (port->port_dev)
res = sas_ex_revalidate_domain(port->port_dev);
SAS_DPRINTK("done REVALIDATING DOMAIN on port %d, pid:%d, res 0x%x\n",
port->id, task_pid_nr(current), res);
}
int sas_discover_event(struct asd_sas_port *port, enum discover_event ev)
{
struct sas_discovery *disc;
if (!port)
return 0;
disc = &port->disc;
BUG_ON(ev >= DISC_NUM_EVENTS);
sas_queue_event(ev, &disc->disc_event_lock, &disc->pending,
&disc->disc_work[ev].work, port->ha);
return 0;
}
void sas_init_disc(struct sas_discovery *disc, struct asd_sas_port *port)
{
int i;
static const work_func_t sas_event_fns[DISC_NUM_EVENTS] = {
[DISCE_DISCOVER_DOMAIN] = sas_discover_domain,
[DISCE_REVALIDATE_DOMAIN] = sas_revalidate_domain,
};
spin_lock_init(&disc->disc_event_lock);
disc->pending = 0;
for (i = 0; i < DISC_NUM_EVENTS; i++) {
INIT_WORK(&disc->disc_work[i].work, sas_event_fns[i]);
disc->disc_work[i].port = port;
}
}
