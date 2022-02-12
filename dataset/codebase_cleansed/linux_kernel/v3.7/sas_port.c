static bool phy_is_wideport_member(struct asd_sas_port *port, struct asd_sas_phy *phy)
{
struct sas_ha_struct *sas_ha = phy->ha;
if (memcmp(port->attached_sas_addr, phy->attached_sas_addr,
SAS_ADDR_SIZE) != 0 || (sas_ha->strict_wide_ports &&
memcmp(port->sas_addr, phy->sas_addr, SAS_ADDR_SIZE) != 0))
return false;
return true;
}
static void sas_resume_port(struct asd_sas_phy *phy)
{
struct domain_device *dev;
struct asd_sas_port *port = phy->port;
struct sas_ha_struct *sas_ha = phy->ha;
struct sas_internal *si = to_sas_internal(sas_ha->core.shost->transportt);
if (si->dft->lldd_port_formed)
si->dft->lldd_port_formed(phy);
if (port->suspended)
port->suspended = 0;
else {
return;
}
list_for_each_entry(dev, &port->dev_list, dev_list_node) {
int i, rc;
rc = sas_notify_lldd_dev_found(dev);
if (rc) {
sas_unregister_dev(port, dev);
continue;
}
if (dev->dev_type == EDGE_DEV || dev->dev_type == FANOUT_DEV) {
dev->ex_dev.ex_change_count = -1;
for (i = 0; i < dev->ex_dev.num_phys; i++) {
struct ex_phy *phy = &dev->ex_dev.ex_phy[i];
phy->phy_change_count = -1;
}
}
}
sas_discover_event(port, DISCE_RESUME);
}
static void sas_form_port(struct asd_sas_phy *phy)
{
int i;
struct sas_ha_struct *sas_ha = phy->ha;
struct asd_sas_port *port = phy->port;
struct sas_internal *si =
to_sas_internal(sas_ha->core.shost->transportt);
unsigned long flags;
if (port) {
if (!phy_is_wideport_member(port, phy))
sas_deform_port(phy, 0);
else if (phy->suspended) {
phy->suspended = 0;
sas_resume_port(phy);
wake_up(&sas_ha->eh_wait_q);
return;
} else {
SAS_DPRINTK("%s: phy%d belongs to port%d already(%d)!\n",
__func__, phy->id, phy->port->id,
phy->port->num_phys);
return;
}
}
spin_lock_irqsave(&sas_ha->phy_port_lock, flags);
for (i = 0; i < sas_ha->num_phys; i++) {
port = sas_ha->sas_port[i];
spin_lock(&port->phy_list_lock);
if (*(u64 *) port->sas_addr &&
phy_is_wideport_member(port, phy) && port->num_phys > 0) {
SAS_DPRINTK("phy%d matched wide port%d\n", phy->id,
port->id);
break;
}
spin_unlock(&port->phy_list_lock);
}
if (i == sas_ha->num_phys) {
for (i = 0; i < sas_ha->num_phys; i++) {
port = sas_ha->sas_port[i];
spin_lock(&port->phy_list_lock);
if (*(u64 *)port->sas_addr == 0
&& port->num_phys == 0) {
memcpy(port->sas_addr, phy->sas_addr,
SAS_ADDR_SIZE);
break;
}
spin_unlock(&port->phy_list_lock);
}
}
if (i >= sas_ha->num_phys) {
printk(KERN_NOTICE "%s: couldn't find a free port, bug?\n",
__func__);
spin_unlock_irqrestore(&sas_ha->phy_port_lock, flags);
return;
}
list_add_tail(&phy->port_phy_el, &port->phy_list);
sas_phy_set_target(phy, port->port_dev);
phy->port = port;
port->num_phys++;
port->phy_mask |= (1U << phy->id);
if (*(u64 *)port->attached_sas_addr == 0) {
port->class = phy->class;
memcpy(port->attached_sas_addr, phy->attached_sas_addr,
SAS_ADDR_SIZE);
port->iproto = phy->iproto;
port->tproto = phy->tproto;
port->oob_mode = phy->oob_mode;
port->linkrate = phy->linkrate;
} else
port->linkrate = max(port->linkrate, phy->linkrate);
spin_unlock(&port->phy_list_lock);
spin_unlock_irqrestore(&sas_ha->phy_port_lock, flags);
if (!port->port) {
port->port = sas_port_alloc(phy->phy->dev.parent, port->id);
BUG_ON(!port->port);
sas_port_add(port->port);
}
sas_port_add_phy(port->port, phy->phy);
SAS_DPRINTK("%s added to %s, phy_mask:0x%x (%16llx)\n",
dev_name(&phy->phy->dev), dev_name(&port->port->dev),
port->phy_mask,
SAS_ADDR(port->attached_sas_addr));
if (port->port_dev)
port->port_dev->pathways = port->num_phys;
if (si->dft->lldd_port_formed)
si->dft->lldd_port_formed(phy);
sas_discover_event(phy->port, DISCE_DISCOVER_DOMAIN);
}
void sas_deform_port(struct asd_sas_phy *phy, int gone)
{
struct sas_ha_struct *sas_ha = phy->ha;
struct asd_sas_port *port = phy->port;
struct sas_internal *si =
to_sas_internal(sas_ha->core.shost->transportt);
struct domain_device *dev;
unsigned long flags;
if (!port)
return;
dev = port->port_dev;
if (dev)
dev->pathways--;
if (port->num_phys == 1) {
sas_unregister_domain_devices(port, gone);
sas_port_delete(port->port);
port->port = NULL;
} else {
sas_port_delete_phy(port->port, phy->phy);
sas_device_set_phy(dev, port->port);
}
if (si->dft->lldd_port_deformed)
si->dft->lldd_port_deformed(phy);
spin_lock_irqsave(&sas_ha->phy_port_lock, flags);
spin_lock(&port->phy_list_lock);
list_del_init(&phy->port_phy_el);
sas_phy_set_target(phy, NULL);
phy->port = NULL;
port->num_phys--;
port->phy_mask &= ~(1U << phy->id);
if (port->num_phys == 0) {
INIT_LIST_HEAD(&port->phy_list);
memset(port->sas_addr, 0, SAS_ADDR_SIZE);
memset(port->attached_sas_addr, 0, SAS_ADDR_SIZE);
port->class = 0;
port->iproto = 0;
port->tproto = 0;
port->oob_mode = 0;
port->phy_mask = 0;
}
spin_unlock(&port->phy_list_lock);
spin_unlock_irqrestore(&sas_ha->phy_port_lock, flags);
return;
}
void sas_porte_bytes_dmaed(struct work_struct *work)
{
struct asd_sas_event *ev = to_asd_sas_event(work);
struct asd_sas_phy *phy = ev->phy;
clear_bit(PORTE_BYTES_DMAED, &phy->port_events_pending);
sas_form_port(phy);
}
void sas_porte_broadcast_rcvd(struct work_struct *work)
{
struct asd_sas_event *ev = to_asd_sas_event(work);
struct asd_sas_phy *phy = ev->phy;
unsigned long flags;
u32 prim;
clear_bit(PORTE_BROADCAST_RCVD, &phy->port_events_pending);
spin_lock_irqsave(&phy->sas_prim_lock, flags);
prim = phy->sas_prim;
spin_unlock_irqrestore(&phy->sas_prim_lock, flags);
SAS_DPRINTK("broadcast received: %d\n", prim);
sas_discover_event(phy->port, DISCE_REVALIDATE_DOMAIN);
}
void sas_porte_link_reset_err(struct work_struct *work)
{
struct asd_sas_event *ev = to_asd_sas_event(work);
struct asd_sas_phy *phy = ev->phy;
clear_bit(PORTE_LINK_RESET_ERR, &phy->port_events_pending);
sas_deform_port(phy, 1);
}
void sas_porte_timer_event(struct work_struct *work)
{
struct asd_sas_event *ev = to_asd_sas_event(work);
struct asd_sas_phy *phy = ev->phy;
clear_bit(PORTE_TIMER_EVENT, &phy->port_events_pending);
sas_deform_port(phy, 1);
}
void sas_porte_hard_reset(struct work_struct *work)
{
struct asd_sas_event *ev = to_asd_sas_event(work);
struct asd_sas_phy *phy = ev->phy;
clear_bit(PORTE_HARD_RESET, &phy->port_events_pending);
sas_deform_port(phy, 1);
}
static void sas_init_port(struct asd_sas_port *port,
struct sas_ha_struct *sas_ha, int i)
{
memset(port, 0, sizeof(*port));
port->id = i;
INIT_LIST_HEAD(&port->dev_list);
INIT_LIST_HEAD(&port->disco_list);
INIT_LIST_HEAD(&port->destroy_list);
spin_lock_init(&port->phy_list_lock);
INIT_LIST_HEAD(&port->phy_list);
port->ha = sas_ha;
spin_lock_init(&port->dev_list_lock);
}
int sas_register_ports(struct sas_ha_struct *sas_ha)
{
int i;
for (i = 0; i < sas_ha->num_phys; i++) {
struct asd_sas_port *port = sas_ha->sas_port[i];
sas_init_port(port, sas_ha, i);
sas_init_disc(&port->disc, port);
}
return 0;
}
void sas_unregister_ports(struct sas_ha_struct *sas_ha)
{
int i;
for (i = 0; i < sas_ha->num_phys; i++)
if (sas_ha->sas_phy[i]->port)
sas_deform_port(sas_ha->sas_phy[i], 0);
}
