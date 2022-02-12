void sas_queue_work(struct sas_ha_struct *ha, struct sas_work *sw)
{
if (!test_bit(SAS_HA_REGISTERED, &ha->state))
return;
if (test_bit(SAS_HA_DRAINING, &ha->state)) {
if (list_empty(&sw->drain_node))
list_add(&sw->drain_node, &ha->defer_q);
} else
scsi_queue_work(ha->core.shost, &sw->work);
}
static void sas_queue_event(int event, unsigned long *pending,
struct sas_work *work,
struct sas_ha_struct *ha)
{
if (!test_and_set_bit(event, pending)) {
unsigned long flags;
spin_lock_irqsave(&ha->lock, flags);
sas_queue_work(ha, work);
spin_unlock_irqrestore(&ha->lock, flags);
}
}
void __sas_drain_work(struct sas_ha_struct *ha)
{
struct workqueue_struct *wq = ha->core.shost->work_q;
struct sas_work *sw, *_sw;
set_bit(SAS_HA_DRAINING, &ha->state);
spin_lock_irq(&ha->lock);
spin_unlock_irq(&ha->lock);
drain_workqueue(wq);
spin_lock_irq(&ha->lock);
clear_bit(SAS_HA_DRAINING, &ha->state);
list_for_each_entry_safe(sw, _sw, &ha->defer_q, drain_node) {
list_del_init(&sw->drain_node);
sas_queue_work(ha, sw);
}
spin_unlock_irq(&ha->lock);
}
int sas_drain_work(struct sas_ha_struct *ha)
{
int err;
err = mutex_lock_interruptible(&ha->drain_mutex);
if (err)
return err;
if (test_bit(SAS_HA_REGISTERED, &ha->state))
__sas_drain_work(ha);
mutex_unlock(&ha->drain_mutex);
return 0;
}
void sas_disable_revalidation(struct sas_ha_struct *ha)
{
mutex_lock(&ha->disco_mutex);
set_bit(SAS_HA_ATA_EH_ACTIVE, &ha->state);
mutex_unlock(&ha->disco_mutex);
}
void sas_enable_revalidation(struct sas_ha_struct *ha)
{
int i;
mutex_lock(&ha->disco_mutex);
clear_bit(SAS_HA_ATA_EH_ACTIVE, &ha->state);
for (i = 0; i < ha->num_phys; i++) {
struct asd_sas_port *port = ha->sas_port[i];
const int ev = DISCE_REVALIDATE_DOMAIN;
struct sas_discovery *d = &port->disc;
if (!test_and_clear_bit(ev, &d->pending))
continue;
sas_queue_event(ev, &d->pending, &d->disc_work[ev].work, ha);
}
mutex_unlock(&ha->disco_mutex);
}
static void notify_ha_event(struct sas_ha_struct *sas_ha, enum ha_event event)
{
BUG_ON(event >= HA_NUM_EVENTS);
sas_queue_event(event, &sas_ha->pending,
&sas_ha->ha_events[event].work, sas_ha);
}
static void notify_port_event(struct asd_sas_phy *phy, enum port_event event)
{
struct sas_ha_struct *ha = phy->ha;
BUG_ON(event >= PORT_NUM_EVENTS);
sas_queue_event(event, &phy->port_events_pending,
&phy->port_events[event].work, ha);
}
void sas_notify_phy_event(struct asd_sas_phy *phy, enum phy_event event)
{
struct sas_ha_struct *ha = phy->ha;
BUG_ON(event >= PHY_NUM_EVENTS);
sas_queue_event(event, &phy->phy_events_pending,
&phy->phy_events[event].work, ha);
}
int sas_init_events(struct sas_ha_struct *sas_ha)
{
static const work_func_t sas_ha_event_fns[HA_NUM_EVENTS] = {
[HAE_RESET] = sas_hae_reset,
};
int i;
for (i = 0; i < HA_NUM_EVENTS; i++) {
INIT_SAS_WORK(&sas_ha->ha_events[i].work, sas_ha_event_fns[i]);
sas_ha->ha_events[i].ha = sas_ha;
}
sas_ha->notify_ha_event = notify_ha_event;
sas_ha->notify_port_event = notify_port_event;
sas_ha->notify_phy_event = sas_notify_phy_event;
return 0;
}
