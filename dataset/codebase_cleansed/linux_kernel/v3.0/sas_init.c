void sas_hash_addr(u8 *hashed, const u8 *sas_addr)
{
const u32 poly = 0x00DB2777;
u32 r = 0;
int i;
for (i = 0; i < 8; i++) {
int b;
for (b = 7; b >= 0; b--) {
r <<= 1;
if ((1 << b) & sas_addr[i]) {
if (!(r & 0x01000000))
r ^= poly;
} else if (r & 0x01000000)
r ^= poly;
}
}
hashed[0] = (r >> 16) & 0xFF;
hashed[1] = (r >> 8) & 0xFF ;
hashed[2] = r & 0xFF;
}
void sas_hae_reset(struct work_struct *work)
{
struct sas_ha_event *ev =
container_of(work, struct sas_ha_event, work);
struct sas_ha_struct *ha = ev->ha;
sas_begin_event(HAE_RESET, &ha->event_lock,
&ha->pending);
}
int sas_register_ha(struct sas_ha_struct *sas_ha)
{
int error = 0;
spin_lock_init(&sas_ha->phy_port_lock);
sas_hash_addr(sas_ha->hashed_sas_addr, sas_ha->sas_addr);
if (sas_ha->lldd_queue_size == 0)
sas_ha->lldd_queue_size = 1;
else if (sas_ha->lldd_queue_size == -1)
sas_ha->lldd_queue_size = 128;
sas_ha->state = SAS_HA_REGISTERED;
spin_lock_init(&sas_ha->state_lock);
error = sas_register_phys(sas_ha);
if (error) {
printk(KERN_NOTICE "couldn't register sas phys:%d\n", error);
return error;
}
error = sas_register_ports(sas_ha);
if (error) {
printk(KERN_NOTICE "couldn't register sas ports:%d\n", error);
goto Undo_phys;
}
error = sas_init_events(sas_ha);
if (error) {
printk(KERN_NOTICE "couldn't start event thread:%d\n", error);
goto Undo_ports;
}
if (sas_ha->lldd_max_execute_num > 1) {
error = sas_init_queue(sas_ha);
if (error) {
printk(KERN_NOTICE "couldn't start queue thread:%d, "
"running in direct mode\n", error);
sas_ha->lldd_max_execute_num = 1;
}
}
INIT_LIST_HEAD(&sas_ha->eh_done_q);
return 0;
Undo_ports:
sas_unregister_ports(sas_ha);
Undo_phys:
return error;
}
int sas_unregister_ha(struct sas_ha_struct *sas_ha)
{
unsigned long flags;
spin_lock_irqsave(&sas_ha->state_lock, flags);
sas_ha->state = SAS_HA_UNREGISTERED;
spin_unlock_irqrestore(&sas_ha->state_lock, flags);
scsi_flush_work(sas_ha->core.shost);
sas_unregister_ports(sas_ha);
if (sas_ha->lldd_max_execute_num > 1) {
sas_shutdown_queue(sas_ha);
sas_ha->lldd_max_execute_num = 1;
}
return 0;
}
static int sas_get_linkerrors(struct sas_phy *phy)
{
if (scsi_is_sas_phy_local(phy))
return -EINVAL;
return sas_smp_get_phy_events(phy);
}
int sas_phy_enable(struct sas_phy *phy, int enable)
{
int ret;
enum phy_func command;
if (enable)
command = PHY_FUNC_LINK_RESET;
else
command = PHY_FUNC_DISABLE;
if (scsi_is_sas_phy_local(phy)) {
struct Scsi_Host *shost = dev_to_shost(phy->dev.parent);
struct sas_ha_struct *sas_ha = SHOST_TO_SAS_HA(shost);
struct asd_sas_phy *asd_phy = sas_ha->sas_phy[phy->number];
struct sas_internal *i =
to_sas_internal(sas_ha->core.shost->transportt);
if (!enable) {
sas_phy_disconnected(asd_phy);
sas_ha->notify_phy_event(asd_phy, PHYE_LOSS_OF_SIGNAL);
}
ret = i->dft->lldd_control_phy(asd_phy, command, NULL);
} else {
struct sas_rphy *rphy = dev_to_rphy(phy->dev.parent);
struct domain_device *ddev = sas_find_dev_by_rphy(rphy);
ret = sas_smp_phy_control(ddev, phy->number, command, NULL);
}
return ret;
}
int sas_phy_reset(struct sas_phy *phy, int hard_reset)
{
int ret;
enum phy_func reset_type;
if (hard_reset)
reset_type = PHY_FUNC_HARD_RESET;
else
reset_type = PHY_FUNC_LINK_RESET;
if (scsi_is_sas_phy_local(phy)) {
struct Scsi_Host *shost = dev_to_shost(phy->dev.parent);
struct sas_ha_struct *sas_ha = SHOST_TO_SAS_HA(shost);
struct asd_sas_phy *asd_phy = sas_ha->sas_phy[phy->number];
struct sas_internal *i =
to_sas_internal(sas_ha->core.shost->transportt);
ret = i->dft->lldd_control_phy(asd_phy, reset_type, NULL);
} else {
struct sas_rphy *rphy = dev_to_rphy(phy->dev.parent);
struct domain_device *ddev = sas_find_dev_by_rphy(rphy);
ret = sas_smp_phy_control(ddev, phy->number, reset_type, NULL);
}
return ret;
}
int sas_set_phy_speed(struct sas_phy *phy,
struct sas_phy_linkrates *rates)
{
int ret;
if ((rates->minimum_linkrate &&
rates->minimum_linkrate > phy->maximum_linkrate) ||
(rates->maximum_linkrate &&
rates->maximum_linkrate < phy->minimum_linkrate))
return -EINVAL;
if (rates->minimum_linkrate &&
rates->minimum_linkrate < phy->minimum_linkrate_hw)
rates->minimum_linkrate = phy->minimum_linkrate_hw;
if (rates->maximum_linkrate &&
rates->maximum_linkrate > phy->maximum_linkrate_hw)
rates->maximum_linkrate = phy->maximum_linkrate_hw;
if (scsi_is_sas_phy_local(phy)) {
struct Scsi_Host *shost = dev_to_shost(phy->dev.parent);
struct sas_ha_struct *sas_ha = SHOST_TO_SAS_HA(shost);
struct asd_sas_phy *asd_phy = sas_ha->sas_phy[phy->number];
struct sas_internal *i =
to_sas_internal(sas_ha->core.shost->transportt);
ret = i->dft->lldd_control_phy(asd_phy, PHY_FUNC_SET_LINK_RATE,
rates);
} else {
struct sas_rphy *rphy = dev_to_rphy(phy->dev.parent);
struct domain_device *ddev = sas_find_dev_by_rphy(rphy);
ret = sas_smp_phy_control(ddev, phy->number,
PHY_FUNC_LINK_RESET, rates);
}
return ret;
}
struct scsi_transport_template *
sas_domain_attach_transport(struct sas_domain_function_template *dft)
{
struct scsi_transport_template *stt = sas_attach_transport(&sft);
struct sas_internal *i;
if (!stt)
return stt;
i = to_sas_internal(stt);
i->dft = dft;
stt->create_work_queue = 1;
stt->eh_timed_out = sas_scsi_timed_out;
stt->eh_strategy_handler = sas_scsi_recover_host;
return stt;
}
void sas_domain_release_transport(struct scsi_transport_template *stt)
{
sas_release_transport(stt);
}
static int __init sas_class_init(void)
{
sas_task_cache = kmem_cache_create("sas_task", sizeof(struct sas_task),
0, SLAB_HWCACHE_ALIGN, NULL);
if (!sas_task_cache)
return -ENOMEM;
return 0;
}
static void __exit sas_class_exit(void)
{
kmem_cache_destroy(sas_task_cache);
}
