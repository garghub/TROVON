static struct fw_device *target_device(struct sbp2_target *tgt)
{
return fw_parent_device(tgt->unit);
}
static void free_orb(struct kref *kref)
{
struct sbp2_orb *orb = container_of(kref, struct sbp2_orb, kref);
kfree(orb);
}
static void sbp2_status_write(struct fw_card *card, struct fw_request *request,
int tcode, int destination, int source,
int generation, unsigned long long offset,
void *payload, size_t length, void *callback_data)
{
struct sbp2_logical_unit *lu = callback_data;
struct sbp2_orb *orb;
struct sbp2_status status;
unsigned long flags;
if (tcode != TCODE_WRITE_BLOCK_REQUEST ||
length < 8 || length > sizeof(status)) {
fw_send_response(card, request, RCODE_TYPE_ERROR);
return;
}
status.status = be32_to_cpup(payload);
status.orb_low = be32_to_cpup(payload + 4);
memset(status.data, 0, sizeof(status.data));
if (length > 8)
memcpy(status.data, payload + 8, length - 8);
if (STATUS_GET_SOURCE(status) == 2 || STATUS_GET_SOURCE(status) == 3) {
fw_notify("non-orb related status write, not handled\n");
fw_send_response(card, request, RCODE_COMPLETE);
return;
}
spin_lock_irqsave(&card->lock, flags);
list_for_each_entry(orb, &lu->orb_list, link) {
if (STATUS_GET_ORB_HIGH(status) == 0 &&
STATUS_GET_ORB_LOW(status) == orb->request_bus) {
orb->rcode = RCODE_COMPLETE;
list_del(&orb->link);
break;
}
}
spin_unlock_irqrestore(&card->lock, flags);
if (&orb->link != &lu->orb_list) {
orb->callback(orb, &status);
kref_put(&orb->kref, free_orb);
} else {
fw_error("status write for unknown orb\n");
}
fw_send_response(card, request, RCODE_COMPLETE);
}
static void complete_transaction(struct fw_card *card, int rcode,
void *payload, size_t length, void *data)
{
struct sbp2_orb *orb = data;
unsigned long flags;
spin_lock_irqsave(&card->lock, flags);
if (orb->rcode == -1)
orb->rcode = rcode;
if (orb->rcode != RCODE_COMPLETE) {
list_del(&orb->link);
spin_unlock_irqrestore(&card->lock, flags);
orb->callback(orb, NULL);
kref_put(&orb->kref, free_orb);
} else {
spin_unlock_irqrestore(&card->lock, flags);
}
kref_put(&orb->kref, free_orb);
}
static void sbp2_send_orb(struct sbp2_orb *orb, struct sbp2_logical_unit *lu,
int node_id, int generation, u64 offset)
{
struct fw_device *device = target_device(lu->tgt);
struct sbp2_pointer orb_pointer;
unsigned long flags;
orb_pointer.high = 0;
orb_pointer.low = cpu_to_be32(orb->request_bus);
spin_lock_irqsave(&device->card->lock, flags);
list_add_tail(&orb->link, &lu->orb_list);
spin_unlock_irqrestore(&device->card->lock, flags);
kref_get(&orb->kref);
kref_get(&orb->kref);
fw_send_request(device->card, &orb->t, TCODE_WRITE_BLOCK_REQUEST,
node_id, generation, device->max_speed, offset,
&orb_pointer, 8, complete_transaction, orb);
}
static int sbp2_cancel_orbs(struct sbp2_logical_unit *lu)
{
struct fw_device *device = target_device(lu->tgt);
struct sbp2_orb *orb, *next;
struct list_head list;
unsigned long flags;
int retval = -ENOENT;
INIT_LIST_HEAD(&list);
spin_lock_irqsave(&device->card->lock, flags);
list_splice_init(&lu->orb_list, &list);
spin_unlock_irqrestore(&device->card->lock, flags);
list_for_each_entry_safe(orb, next, &list, link) {
retval = 0;
if (fw_cancel_transaction(device->card, &orb->t) == 0)
continue;
orb->rcode = RCODE_CANCELLED;
orb->callback(orb, NULL);
kref_put(&orb->kref, free_orb);
}
return retval;
}
static void complete_management_orb(struct sbp2_orb *base_orb,
struct sbp2_status *status)
{
struct sbp2_management_orb *orb =
container_of(base_orb, struct sbp2_management_orb, base);
if (status)
memcpy(&orb->status, status, sizeof(*status));
complete(&orb->done);
}
static int sbp2_send_management_orb(struct sbp2_logical_unit *lu, int node_id,
int generation, int function,
int lun_or_login_id, void *response)
{
struct fw_device *device = target_device(lu->tgt);
struct sbp2_management_orb *orb;
unsigned int timeout;
int retval = -ENOMEM;
if (function == SBP2_LOGOUT_REQUEST && fw_device_is_shutdown(device))
return 0;
orb = kzalloc(sizeof(*orb), GFP_ATOMIC);
if (orb == NULL)
return -ENOMEM;
kref_init(&orb->base.kref);
orb->response_bus =
dma_map_single(device->card->device, &orb->response,
sizeof(orb->response), DMA_FROM_DEVICE);
if (dma_mapping_error(device->card->device, orb->response_bus))
goto fail_mapping_response;
orb->request.response.high = 0;
orb->request.response.low = cpu_to_be32(orb->response_bus);
orb->request.misc = cpu_to_be32(
MANAGEMENT_ORB_NOTIFY |
MANAGEMENT_ORB_FUNCTION(function) |
MANAGEMENT_ORB_LUN(lun_or_login_id));
orb->request.length = cpu_to_be32(
MANAGEMENT_ORB_RESPONSE_LENGTH(sizeof(orb->response)));
orb->request.status_fifo.high =
cpu_to_be32(lu->address_handler.offset >> 32);
orb->request.status_fifo.low =
cpu_to_be32(lu->address_handler.offset);
if (function == SBP2_LOGIN_REQUEST) {
orb->request.misc |= cpu_to_be32(
MANAGEMENT_ORB_RECONNECT(2) |
MANAGEMENT_ORB_EXCLUSIVE(sbp2_param_exclusive_login));
timeout = lu->tgt->mgt_orb_timeout;
} else {
timeout = SBP2_ORB_TIMEOUT;
}
init_completion(&orb->done);
orb->base.callback = complete_management_orb;
orb->base.request_bus =
dma_map_single(device->card->device, &orb->request,
sizeof(orb->request), DMA_TO_DEVICE);
if (dma_mapping_error(device->card->device, orb->base.request_bus))
goto fail_mapping_request;
sbp2_send_orb(&orb->base, lu, node_id, generation,
lu->tgt->management_agent_address);
wait_for_completion_timeout(&orb->done, msecs_to_jiffies(timeout));
retval = -EIO;
if (sbp2_cancel_orbs(lu) == 0) {
fw_error("%s: orb reply timed out, rcode=0x%02x\n",
lu->tgt->bus_id, orb->base.rcode);
goto out;
}
if (orb->base.rcode != RCODE_COMPLETE) {
fw_error("%s: management write failed, rcode 0x%02x\n",
lu->tgt->bus_id, orb->base.rcode);
goto out;
}
if (STATUS_GET_RESPONSE(orb->status) != 0 ||
STATUS_GET_SBP_STATUS(orb->status) != 0) {
fw_error("%s: error status: %d:%d\n", lu->tgt->bus_id,
STATUS_GET_RESPONSE(orb->status),
STATUS_GET_SBP_STATUS(orb->status));
goto out;
}
retval = 0;
out:
dma_unmap_single(device->card->device, orb->base.request_bus,
sizeof(orb->request), DMA_TO_DEVICE);
fail_mapping_request:
dma_unmap_single(device->card->device, orb->response_bus,
sizeof(orb->response), DMA_FROM_DEVICE);
fail_mapping_response:
if (response)
memcpy(response, orb->response, sizeof(orb->response));
kref_put(&orb->base.kref, free_orb);
return retval;
}
static void sbp2_agent_reset(struct sbp2_logical_unit *lu)
{
struct fw_device *device = target_device(lu->tgt);
__be32 d = 0;
fw_run_transaction(device->card, TCODE_WRITE_QUADLET_REQUEST,
lu->tgt->node_id, lu->generation, device->max_speed,
lu->command_block_agent_address + SBP2_AGENT_RESET,
&d, 4);
}
static void complete_agent_reset_write_no_wait(struct fw_card *card,
int rcode, void *payload, size_t length, void *data)
{
kfree(data);
}
static void sbp2_agent_reset_no_wait(struct sbp2_logical_unit *lu)
{
struct fw_device *device = target_device(lu->tgt);
struct fw_transaction *t;
static __be32 d;
t = kmalloc(sizeof(*t), GFP_ATOMIC);
if (t == NULL)
return;
fw_send_request(device->card, t, TCODE_WRITE_QUADLET_REQUEST,
lu->tgt->node_id, lu->generation, device->max_speed,
lu->command_block_agent_address + SBP2_AGENT_RESET,
&d, 4, complete_agent_reset_write_no_wait, t);
}
static inline void sbp2_allow_block(struct sbp2_logical_unit *lu)
{
--lu->tgt->dont_block;
}
static void sbp2_conditionally_block(struct sbp2_logical_unit *lu)
{
struct sbp2_target *tgt = lu->tgt;
struct fw_card *card = target_device(tgt)->card;
struct Scsi_Host *shost =
container_of((void *)tgt, struct Scsi_Host, hostdata[0]);
unsigned long flags;
spin_lock_irqsave(&card->lock, flags);
if (!tgt->dont_block && !lu->blocked &&
lu->generation != card->generation) {
lu->blocked = true;
if (++tgt->blocked == 1)
scsi_block_requests(shost);
}
spin_unlock_irqrestore(&card->lock, flags);
}
static void sbp2_conditionally_unblock(struct sbp2_logical_unit *lu)
{
struct sbp2_target *tgt = lu->tgt;
struct fw_card *card = target_device(tgt)->card;
struct Scsi_Host *shost =
container_of((void *)tgt, struct Scsi_Host, hostdata[0]);
unsigned long flags;
bool unblock = false;
spin_lock_irqsave(&card->lock, flags);
if (lu->blocked && lu->generation == card->generation) {
lu->blocked = false;
unblock = --tgt->blocked == 0;
}
spin_unlock_irqrestore(&card->lock, flags);
if (unblock)
scsi_unblock_requests(shost);
}
static void sbp2_unblock(struct sbp2_target *tgt)
{
struct fw_card *card = target_device(tgt)->card;
struct Scsi_Host *shost =
container_of((void *)tgt, struct Scsi_Host, hostdata[0]);
unsigned long flags;
spin_lock_irqsave(&card->lock, flags);
++tgt->dont_block;
spin_unlock_irqrestore(&card->lock, flags);
scsi_unblock_requests(shost);
}
static int sbp2_lun2int(u16 lun)
{
struct scsi_lun eight_bytes_lun;
memset(&eight_bytes_lun, 0, sizeof(eight_bytes_lun));
eight_bytes_lun.scsi_lun[0] = (lun >> 8) & 0xff;
eight_bytes_lun.scsi_lun[1] = lun & 0xff;
return scsilun_to_int(&eight_bytes_lun);
}
static void sbp2_release_target(struct kref *kref)
{
struct sbp2_target *tgt = container_of(kref, struct sbp2_target, kref);
struct sbp2_logical_unit *lu, *next;
struct Scsi_Host *shost =
container_of((void *)tgt, struct Scsi_Host, hostdata[0]);
struct scsi_device *sdev;
struct fw_device *device = target_device(tgt);
sbp2_unblock(tgt);
list_for_each_entry_safe(lu, next, &tgt->lu_list, link) {
sdev = scsi_device_lookup(shost, 0, 0, sbp2_lun2int(lu->lun));
if (sdev) {
scsi_remove_device(sdev);
scsi_device_put(sdev);
}
if (lu->login_id != INVALID_LOGIN_ID) {
int generation, node_id;
generation = device->generation;
smp_rmb();
node_id = device->node_id;
sbp2_send_management_orb(lu, node_id, generation,
SBP2_LOGOUT_REQUEST,
lu->login_id, NULL);
}
fw_core_remove_address_handler(&lu->address_handler);
list_del(&lu->link);
kfree(lu);
}
scsi_remove_host(shost);
fw_notify("released %s, target %d:0:0\n", tgt->bus_id, shost->host_no);
fw_unit_put(tgt->unit);
scsi_host_put(shost);
fw_device_put(device);
}
static void sbp2_target_get(struct sbp2_target *tgt)
{
kref_get(&tgt->kref);
}
static void sbp2_target_put(struct sbp2_target *tgt)
{
kref_put(&tgt->kref, sbp2_release_target);
}
static void sbp2_queue_work(struct sbp2_logical_unit *lu, unsigned long delay)
{
sbp2_target_get(lu->tgt);
if (!queue_delayed_work(fw_workqueue, &lu->work, delay))
sbp2_target_put(lu->tgt);
}
static void sbp2_set_busy_timeout(struct sbp2_logical_unit *lu)
{
struct fw_device *device = target_device(lu->tgt);
__be32 d = cpu_to_be32(SBP2_CYCLE_LIMIT | SBP2_RETRY_LIMIT);
fw_run_transaction(device->card, TCODE_WRITE_QUADLET_REQUEST,
lu->tgt->node_id, lu->generation, device->max_speed,
CSR_REGISTER_BASE + CSR_BUSY_TIMEOUT, &d, 4);
}
static void sbp2_login(struct work_struct *work)
{
struct sbp2_logical_unit *lu =
container_of(work, struct sbp2_logical_unit, work.work);
struct sbp2_target *tgt = lu->tgt;
struct fw_device *device = target_device(tgt);
struct Scsi_Host *shost;
struct scsi_device *sdev;
struct sbp2_login_response response;
int generation, node_id, local_node_id;
if (fw_device_is_shutdown(device))
goto out;
generation = device->generation;
smp_rmb();
node_id = device->node_id;
local_node_id = device->card->node_id;
if (lu->has_sdev)
sbp2_send_management_orb(lu, device->node_id, generation,
SBP2_LOGOUT_REQUEST, lu->login_id, NULL);
if (sbp2_send_management_orb(lu, node_id, generation,
SBP2_LOGIN_REQUEST, lu->lun, &response) < 0) {
if (lu->retries++ < 5) {
sbp2_queue_work(lu, DIV_ROUND_UP(HZ, 5));
} else {
fw_error("%s: failed to login to LUN %04x\n",
tgt->bus_id, lu->lun);
sbp2_unblock(lu->tgt);
}
goto out;
}
tgt->node_id = node_id;
tgt->address_high = local_node_id << 16;
smp_wmb();
lu->generation = generation;
lu->command_block_agent_address =
((u64)(be32_to_cpu(response.command_block_agent.high) & 0xffff)
<< 32) | be32_to_cpu(response.command_block_agent.low);
lu->login_id = be32_to_cpu(response.misc) & 0xffff;
fw_notify("%s: logged in to LUN %04x (%d retries)\n",
tgt->bus_id, lu->lun, lu->retries);
sbp2_set_busy_timeout(lu);
PREPARE_DELAYED_WORK(&lu->work, sbp2_reconnect);
sbp2_agent_reset(lu);
if (lu->has_sdev) {
sbp2_cancel_orbs(lu);
sbp2_conditionally_unblock(lu);
goto out;
}
if (lu->tgt->workarounds & SBP2_WORKAROUND_DELAY_INQUIRY)
ssleep(SBP2_INQUIRY_DELAY);
shost = container_of((void *)tgt, struct Scsi_Host, hostdata[0]);
sdev = __scsi_add_device(shost, 0, 0, sbp2_lun2int(lu->lun), lu);
if (IS_ERR(sdev))
goto out_logout_login;
smp_rmb();
if (generation != device->card->generation) {
scsi_remove_device(sdev);
scsi_device_put(sdev);
goto out_logout_login;
}
lu->has_sdev = true;
scsi_device_put(sdev);
sbp2_allow_block(lu);
goto out;
out_logout_login:
smp_rmb();
generation = device->generation;
smp_rmb();
sbp2_send_management_orb(lu, device->node_id, generation,
SBP2_LOGOUT_REQUEST, lu->login_id, NULL);
PREPARE_DELAYED_WORK(&lu->work, sbp2_login);
out:
sbp2_target_put(tgt);
}
static int sbp2_add_logical_unit(struct sbp2_target *tgt, int lun_entry)
{
struct sbp2_logical_unit *lu;
lu = kmalloc(sizeof(*lu), GFP_KERNEL);
if (!lu)
return -ENOMEM;
lu->address_handler.length = 0x100;
lu->address_handler.address_callback = sbp2_status_write;
lu->address_handler.callback_data = lu;
if (fw_core_add_address_handler(&lu->address_handler,
&fw_high_memory_region) < 0) {
kfree(lu);
return -ENOMEM;
}
lu->tgt = tgt;
lu->lun = lun_entry & 0xffff;
lu->login_id = INVALID_LOGIN_ID;
lu->retries = 0;
lu->has_sdev = false;
lu->blocked = false;
++tgt->dont_block;
INIT_LIST_HEAD(&lu->orb_list);
INIT_DELAYED_WORK(&lu->work, sbp2_login);
list_add_tail(&lu->link, &tgt->lu_list);
return 0;
}
static int sbp2_scan_logical_unit_dir(struct sbp2_target *tgt,
const u32 *directory)
{
struct fw_csr_iterator ci;
int key, value;
fw_csr_iterator_init(&ci, directory);
while (fw_csr_iterator_next(&ci, &key, &value))
if (key == SBP2_CSR_LOGICAL_UNIT_NUMBER &&
sbp2_add_logical_unit(tgt, value) < 0)
return -ENOMEM;
return 0;
}
static int sbp2_scan_unit_dir(struct sbp2_target *tgt, const u32 *directory,
u32 *model, u32 *firmware_revision)
{
struct fw_csr_iterator ci;
int key, value;
fw_csr_iterator_init(&ci, directory);
while (fw_csr_iterator_next(&ci, &key, &value)) {
switch (key) {
case CSR_DEPENDENT_INFO | CSR_OFFSET:
tgt->management_agent_address =
CSR_REGISTER_BASE + 4 * value;
break;
case CSR_DIRECTORY_ID:
tgt->directory_id = value;
break;
case CSR_MODEL:
*model = value;
break;
case SBP2_CSR_FIRMWARE_REVISION:
*firmware_revision = value;
break;
case SBP2_CSR_UNIT_CHARACTERISTICS:
tgt->mgt_orb_timeout = (value >> 8 & 0xff) * 500;
break;
case SBP2_CSR_LOGICAL_UNIT_NUMBER:
if (sbp2_add_logical_unit(tgt, value) < 0)
return -ENOMEM;
break;
case SBP2_CSR_LOGICAL_UNIT_DIRECTORY:
if (sbp2_scan_logical_unit_dir(tgt, ci.p - 1 + value) < 0)
return -ENOMEM;
break;
}
}
return 0;
}
static void sbp2_clamp_management_orb_timeout(struct sbp2_target *tgt)
{
unsigned int timeout = tgt->mgt_orb_timeout;
if (timeout > 40000)
fw_notify("%s: %ds mgt_ORB_timeout limited to 40s\n",
tgt->bus_id, timeout / 1000);
tgt->mgt_orb_timeout = clamp_val(timeout, 5000, 40000);
}
static void sbp2_init_workarounds(struct sbp2_target *tgt, u32 model,
u32 firmware_revision)
{
int i;
unsigned int w = sbp2_param_workarounds;
if (w)
fw_notify("Please notify linux1394-devel@lists.sourceforge.net "
"if you need the workarounds parameter for %s\n",
tgt->bus_id);
if (w & SBP2_WORKAROUND_OVERRIDE)
goto out;
for (i = 0; i < ARRAY_SIZE(sbp2_workarounds_table); i++) {
if (sbp2_workarounds_table[i].firmware_revision !=
(firmware_revision & 0xffffff00))
continue;
if (sbp2_workarounds_table[i].model != model &&
sbp2_workarounds_table[i].model != SBP2_ROM_VALUE_WILDCARD)
continue;
w |= sbp2_workarounds_table[i].workarounds;
break;
}
out:
if (w)
fw_notify("Workarounds for %s: 0x%x "
"(firmware_revision 0x%06x, model_id 0x%06x)\n",
tgt->bus_id, w, firmware_revision, model);
tgt->workarounds = w;
}
static int sbp2_probe(struct device *dev)
{
struct fw_unit *unit = fw_unit(dev);
struct fw_device *device = fw_parent_device(unit);
struct sbp2_target *tgt;
struct sbp2_logical_unit *lu;
struct Scsi_Host *shost;
u32 model, firmware_revision;
if (dma_get_max_seg_size(device->card->device) > SBP2_MAX_SEG_SIZE)
BUG_ON(dma_set_max_seg_size(device->card->device,
SBP2_MAX_SEG_SIZE));
shost = scsi_host_alloc(&scsi_driver_template, sizeof(*tgt));
if (shost == NULL)
return -ENOMEM;
tgt = (struct sbp2_target *)shost->hostdata;
dev_set_drvdata(&unit->device, tgt);
tgt->unit = unit;
kref_init(&tgt->kref);
INIT_LIST_HEAD(&tgt->lu_list);
tgt->bus_id = dev_name(&unit->device);
tgt->guid = (u64)device->config_rom[3] << 32 | device->config_rom[4];
if (fw_device_enable_phys_dma(device) < 0)
goto fail_shost_put;
shost->max_cmd_len = SBP2_MAX_CDB_SIZE;
if (scsi_add_host(shost, &unit->device) < 0)
goto fail_shost_put;
fw_device_get(device);
fw_unit_get(unit);
tgt->directory_id = ((unit->directory - device->config_rom) * 4
+ CSR_CONFIG_ROM) & 0xffffff;
firmware_revision = SBP2_ROM_VALUE_MISSING;
model = SBP2_ROM_VALUE_MISSING;
if (sbp2_scan_unit_dir(tgt, unit->directory, &model,
&firmware_revision) < 0)
goto fail_tgt_put;
sbp2_clamp_management_orb_timeout(tgt);
sbp2_init_workarounds(tgt, model, firmware_revision);
tgt->max_payload = min(device->max_speed + 7, 10U);
tgt->max_payload = min(tgt->max_payload, device->card->max_receive - 1);
list_for_each_entry(lu, &tgt->lu_list, link)
sbp2_queue_work(lu, DIV_ROUND_UP(HZ, 5));
return 0;
fail_tgt_put:
sbp2_target_put(tgt);
return -ENOMEM;
fail_shost_put:
scsi_host_put(shost);
return -ENOMEM;
}
static int sbp2_remove(struct device *dev)
{
struct fw_unit *unit = fw_unit(dev);
struct sbp2_target *tgt = dev_get_drvdata(&unit->device);
struct sbp2_logical_unit *lu;
list_for_each_entry(lu, &tgt->lu_list, link)
cancel_delayed_work_sync(&lu->work);
sbp2_target_put(tgt);
return 0;
}
static void sbp2_reconnect(struct work_struct *work)
{
struct sbp2_logical_unit *lu =
container_of(work, struct sbp2_logical_unit, work.work);
struct sbp2_target *tgt = lu->tgt;
struct fw_device *device = target_device(tgt);
int generation, node_id, local_node_id;
if (fw_device_is_shutdown(device))
goto out;
generation = device->generation;
smp_rmb();
node_id = device->node_id;
local_node_id = device->card->node_id;
if (sbp2_send_management_orb(lu, node_id, generation,
SBP2_RECONNECT_REQUEST,
lu->login_id, NULL) < 0) {
smp_rmb();
if (generation == device->card->generation ||
lu->retries++ >= 5) {
fw_error("%s: failed to reconnect\n", tgt->bus_id);
lu->retries = 0;
PREPARE_DELAYED_WORK(&lu->work, sbp2_login);
}
sbp2_queue_work(lu, DIV_ROUND_UP(HZ, 5));
goto out;
}
tgt->node_id = node_id;
tgt->address_high = local_node_id << 16;
smp_wmb();
lu->generation = generation;
fw_notify("%s: reconnected to LUN %04x (%d retries)\n",
tgt->bus_id, lu->lun, lu->retries);
sbp2_agent_reset(lu);
sbp2_cancel_orbs(lu);
sbp2_conditionally_unblock(lu);
out:
sbp2_target_put(tgt);
}
static void sbp2_update(struct fw_unit *unit)
{
struct sbp2_target *tgt = dev_get_drvdata(&unit->device);
struct sbp2_logical_unit *lu;
fw_device_enable_phys_dma(fw_parent_device(unit));
list_for_each_entry(lu, &tgt->lu_list, link) {
sbp2_conditionally_block(lu);
lu->retries = 0;
sbp2_queue_work(lu, 0);
}
}
static void sbp2_unmap_scatterlist(struct device *card_device,
struct sbp2_command_orb *orb)
{
if (scsi_sg_count(orb->cmd))
dma_unmap_sg(card_device, scsi_sglist(orb->cmd),
scsi_sg_count(orb->cmd),
orb->cmd->sc_data_direction);
if (orb->request.misc & cpu_to_be32(COMMAND_ORB_PAGE_TABLE_PRESENT))
dma_unmap_single(card_device, orb->page_table_bus,
sizeof(orb->page_table), DMA_TO_DEVICE);
}
static unsigned int sbp2_status_to_sense_data(u8 *sbp2_status, u8 *sense_data)
{
int sam_status;
sense_data[0] = 0x70;
sense_data[1] = 0x0;
sense_data[2] = sbp2_status[1];
sense_data[3] = sbp2_status[4];
sense_data[4] = sbp2_status[5];
sense_data[5] = sbp2_status[6];
sense_data[6] = sbp2_status[7];
sense_data[7] = 10;
sense_data[8] = sbp2_status[8];
sense_data[9] = sbp2_status[9];
sense_data[10] = sbp2_status[10];
sense_data[11] = sbp2_status[11];
sense_data[12] = sbp2_status[2];
sense_data[13] = sbp2_status[3];
sense_data[14] = sbp2_status[12];
sense_data[15] = sbp2_status[13];
sam_status = sbp2_status[0] & 0x3f;
switch (sam_status) {
case SAM_STAT_GOOD:
case SAM_STAT_CHECK_CONDITION:
case SAM_STAT_CONDITION_MET:
case SAM_STAT_BUSY:
case SAM_STAT_RESERVATION_CONFLICT:
case SAM_STAT_COMMAND_TERMINATED:
return DID_OK << 16 | sam_status;
default:
return DID_ERROR << 16;
}
}
static void complete_command_orb(struct sbp2_orb *base_orb,
struct sbp2_status *status)
{
struct sbp2_command_orb *orb =
container_of(base_orb, struct sbp2_command_orb, base);
struct fw_device *device = target_device(orb->lu->tgt);
int result;
if (status != NULL) {
if (STATUS_GET_DEAD(*status))
sbp2_agent_reset_no_wait(orb->lu);
switch (STATUS_GET_RESPONSE(*status)) {
case SBP2_STATUS_REQUEST_COMPLETE:
result = DID_OK << 16;
break;
case SBP2_STATUS_TRANSPORT_FAILURE:
result = DID_BUS_BUSY << 16;
break;
case SBP2_STATUS_ILLEGAL_REQUEST:
case SBP2_STATUS_VENDOR_DEPENDENT:
default:
result = DID_ERROR << 16;
break;
}
if (result == DID_OK << 16 && STATUS_GET_LEN(*status) > 1)
result = sbp2_status_to_sense_data(STATUS_GET_DATA(*status),
orb->cmd->sense_buffer);
} else {
result = DID_BUS_BUSY << 16;
sbp2_conditionally_block(orb->lu);
}
dma_unmap_single(device->card->device, orb->base.request_bus,
sizeof(orb->request), DMA_TO_DEVICE);
sbp2_unmap_scatterlist(device->card->device, orb);
orb->cmd->result = result;
orb->cmd->scsi_done(orb->cmd);
}
static int sbp2_map_scatterlist(struct sbp2_command_orb *orb,
struct fw_device *device, struct sbp2_logical_unit *lu)
{
struct scatterlist *sg = scsi_sglist(orb->cmd);
int i, n;
n = dma_map_sg(device->card->device, sg, scsi_sg_count(orb->cmd),
orb->cmd->sc_data_direction);
if (n == 0)
goto fail;
if (n == 1) {
orb->request.data_descriptor.high =
cpu_to_be32(lu->tgt->address_high);
orb->request.data_descriptor.low =
cpu_to_be32(sg_dma_address(sg));
orb->request.misc |=
cpu_to_be32(COMMAND_ORB_DATA_SIZE(sg_dma_len(sg)));
return 0;
}
for_each_sg(sg, sg, n, i) {
orb->page_table[i].high = cpu_to_be32(sg_dma_len(sg) << 16);
orb->page_table[i].low = cpu_to_be32(sg_dma_address(sg));
}
orb->page_table_bus =
dma_map_single(device->card->device, orb->page_table,
sizeof(orb->page_table), DMA_TO_DEVICE);
if (dma_mapping_error(device->card->device, orb->page_table_bus))
goto fail_page_table;
orb->request.data_descriptor.high = cpu_to_be32(lu->tgt->address_high);
orb->request.data_descriptor.low = cpu_to_be32(orb->page_table_bus);
orb->request.misc |= cpu_to_be32(COMMAND_ORB_PAGE_TABLE_PRESENT |
COMMAND_ORB_DATA_SIZE(n));
return 0;
fail_page_table:
dma_unmap_sg(device->card->device, scsi_sglist(orb->cmd),
scsi_sg_count(orb->cmd), orb->cmd->sc_data_direction);
fail:
return -ENOMEM;
}
static int sbp2_scsi_queuecommand(struct Scsi_Host *shost,
struct scsi_cmnd *cmd)
{
struct sbp2_logical_unit *lu = cmd->device->hostdata;
struct fw_device *device = target_device(lu->tgt);
struct sbp2_command_orb *orb;
int generation, retval = SCSI_MLQUEUE_HOST_BUSY;
if (cmd->sc_data_direction == DMA_BIDIRECTIONAL) {
fw_error("Can't handle DMA_BIDIRECTIONAL, rejecting command\n");
cmd->result = DID_ERROR << 16;
cmd->scsi_done(cmd);
return 0;
}
orb = kzalloc(sizeof(*orb), GFP_ATOMIC);
if (orb == NULL) {
fw_notify("failed to alloc orb\n");
return SCSI_MLQUEUE_HOST_BUSY;
}
orb->base.rcode = -1;
kref_init(&orb->base.kref);
orb->lu = lu;
orb->cmd = cmd;
orb->request.next.high = cpu_to_be32(SBP2_ORB_NULL);
orb->request.misc = cpu_to_be32(
COMMAND_ORB_MAX_PAYLOAD(lu->tgt->max_payload) |
COMMAND_ORB_SPEED(device->max_speed) |
COMMAND_ORB_NOTIFY);
if (cmd->sc_data_direction == DMA_FROM_DEVICE)
orb->request.misc |= cpu_to_be32(COMMAND_ORB_DIRECTION);
generation = device->generation;
smp_rmb();
if (scsi_sg_count(cmd) && sbp2_map_scatterlist(orb, device, lu) < 0)
goto out;
memcpy(orb->request.command_block, cmd->cmnd, cmd->cmd_len);
orb->base.callback = complete_command_orb;
orb->base.request_bus =
dma_map_single(device->card->device, &orb->request,
sizeof(orb->request), DMA_TO_DEVICE);
if (dma_mapping_error(device->card->device, orb->base.request_bus)) {
sbp2_unmap_scatterlist(device->card->device, orb);
goto out;
}
sbp2_send_orb(&orb->base, lu, lu->tgt->node_id, generation,
lu->command_block_agent_address + SBP2_ORB_POINTER);
retval = 0;
out:
kref_put(&orb->base.kref, free_orb);
return retval;
}
static int sbp2_scsi_slave_alloc(struct scsi_device *sdev)
{
struct sbp2_logical_unit *lu = sdev->hostdata;
if (!lu)
return -ENOSYS;
sdev->allow_restart = 1;
blk_queue_update_dma_alignment(sdev->request_queue, 4 - 1);
if (lu->tgt->workarounds & SBP2_WORKAROUND_INQUIRY_36)
sdev->inquiry_len = 36;
return 0;
}
static int sbp2_scsi_slave_configure(struct scsi_device *sdev)
{
struct sbp2_logical_unit *lu = sdev->hostdata;
sdev->use_10_for_rw = 1;
if (sbp2_param_exclusive_login)
sdev->manage_start_stop = 1;
if (sdev->type == TYPE_ROM)
sdev->use_10_for_ms = 1;
if (sdev->type == TYPE_DISK &&
lu->tgt->workarounds & SBP2_WORKAROUND_MODE_SENSE_8)
sdev->skip_ms_page_8 = 1;
if (lu->tgt->workarounds & SBP2_WORKAROUND_FIX_CAPACITY)
sdev->fix_capacity = 1;
if (lu->tgt->workarounds & SBP2_WORKAROUND_POWER_CONDITION)
sdev->start_stop_pwr_cond = 1;
if (lu->tgt->workarounds & SBP2_WORKAROUND_128K_MAX_TRANS)
blk_queue_max_hw_sectors(sdev->request_queue, 128 * 1024 / 512);
blk_queue_max_segment_size(sdev->request_queue, SBP2_MAX_SEG_SIZE);
return 0;
}
static int sbp2_scsi_abort(struct scsi_cmnd *cmd)
{
struct sbp2_logical_unit *lu = cmd->device->hostdata;
fw_notify("%s: sbp2_scsi_abort\n", lu->tgt->bus_id);
sbp2_agent_reset(lu);
sbp2_cancel_orbs(lu);
return SUCCESS;
}
static ssize_t sbp2_sysfs_ieee1394_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct scsi_device *sdev = to_scsi_device(dev);
struct sbp2_logical_unit *lu;
if (!sdev)
return 0;
lu = sdev->hostdata;
return sprintf(buf, "%016llx:%06x:%04x\n",
(unsigned long long)lu->tgt->guid,
lu->tgt->directory_id, lu->lun);
}
static int __init sbp2_init(void)
{
return driver_register(&sbp2_driver.driver);
}
static void __exit sbp2_cleanup(void)
{
driver_unregister(&sbp2_driver.driver);
}
