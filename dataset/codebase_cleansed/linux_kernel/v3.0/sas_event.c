static void notify_ha_event(struct sas_ha_struct *sas_ha, enum ha_event event)
{
BUG_ON(event >= HA_NUM_EVENTS);
sas_queue_event(event, &sas_ha->event_lock, &sas_ha->pending,
&sas_ha->ha_events[event].work, sas_ha);
}
static void notify_port_event(struct asd_sas_phy *phy, enum port_event event)
{
struct sas_ha_struct *ha = phy->ha;
BUG_ON(event >= PORT_NUM_EVENTS);
sas_queue_event(event, &ha->event_lock, &phy->port_events_pending,
&phy->port_events[event].work, ha);
}
static void notify_phy_event(struct asd_sas_phy *phy, enum phy_event event)
{
struct sas_ha_struct *ha = phy->ha;
BUG_ON(event >= PHY_NUM_EVENTS);
sas_queue_event(event, &ha->event_lock, &phy->phy_events_pending,
&phy->phy_events[event].work, ha);
}
int sas_init_events(struct sas_ha_struct *sas_ha)
{
static const work_func_t sas_ha_event_fns[HA_NUM_EVENTS] = {
[HAE_RESET] = sas_hae_reset,
};
int i;
spin_lock_init(&sas_ha->event_lock);
for (i = 0; i < HA_NUM_EVENTS; i++) {
INIT_WORK(&sas_ha->ha_events[i].work, sas_ha_event_fns[i]);
sas_ha->ha_events[i].ha = sas_ha;
}
sas_ha->notify_ha_event = notify_ha_event;
sas_ha->notify_port_event = notify_port_event;
sas_ha->notify_phy_event = notify_phy_event;
return 0;
}
