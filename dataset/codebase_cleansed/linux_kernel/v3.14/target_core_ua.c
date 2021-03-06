sense_reason_t
target_scsi3_ua_check(struct se_cmd *cmd)
{
struct se_dev_entry *deve;
struct se_session *sess = cmd->se_sess;
struct se_node_acl *nacl;
if (!sess)
return 0;
nacl = sess->se_node_acl;
if (!nacl)
return 0;
deve = nacl->device_list[cmd->orig_fe_lun];
if (!atomic_read(&deve->ua_count))
return 0;
switch (cmd->t_task_cdb[0]) {
case INQUIRY:
case REPORT_LUNS:
case REQUEST_SENSE:
return 0;
default:
return TCM_CHECK_CONDITION_UNIT_ATTENTION;
}
}
int core_scsi3_ua_allocate(
struct se_node_acl *nacl,
u32 unpacked_lun,
u8 asc,
u8 ascq)
{
struct se_dev_entry *deve;
struct se_ua *ua, *ua_p, *ua_tmp;
if (!nacl)
return -EINVAL;
ua = kmem_cache_zalloc(se_ua_cache, GFP_ATOMIC);
if (!ua) {
pr_err("Unable to allocate struct se_ua\n");
return -ENOMEM;
}
INIT_LIST_HEAD(&ua->ua_nacl_list);
ua->ua_nacl = nacl;
ua->ua_asc = asc;
ua->ua_ascq = ascq;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[unpacked_lun];
spin_lock(&deve->ua_lock);
list_for_each_entry_safe(ua_p, ua_tmp, &deve->ua_list, ua_nacl_list) {
if ((ua_p->ua_asc == asc) && (ua_p->ua_ascq == ascq)) {
spin_unlock(&deve->ua_lock);
spin_unlock_irq(&nacl->device_list_lock);
kmem_cache_free(se_ua_cache, ua);
return 0;
}
if (ua_p->ua_asc == 0x29) {
if ((asc == 0x29) && (ascq > ua_p->ua_ascq))
list_add(&ua->ua_nacl_list,
&deve->ua_list);
else
list_add_tail(&ua->ua_nacl_list,
&deve->ua_list);
} else if (ua_p->ua_asc == 0x2a) {
if ((asc == 0x29) || (ascq > ua_p->ua_asc))
list_add(&ua->ua_nacl_list,
&deve->ua_list);
else
list_add_tail(&ua->ua_nacl_list,
&deve->ua_list);
} else
list_add_tail(&ua->ua_nacl_list,
&deve->ua_list);
spin_unlock(&deve->ua_lock);
spin_unlock_irq(&nacl->device_list_lock);
atomic_inc(&deve->ua_count);
smp_mb__after_atomic_inc();
return 0;
}
list_add_tail(&ua->ua_nacl_list, &deve->ua_list);
spin_unlock(&deve->ua_lock);
spin_unlock_irq(&nacl->device_list_lock);
pr_debug("[%s]: Allocated UNIT ATTENTION, mapped LUN: %u, ASC:"
" 0x%02x, ASCQ: 0x%02x\n",
nacl->se_tpg->se_tpg_tfo->get_fabric_name(), unpacked_lun,
asc, ascq);
atomic_inc(&deve->ua_count);
smp_mb__after_atomic_inc();
return 0;
}
void core_scsi3_ua_release_all(
struct se_dev_entry *deve)
{
struct se_ua *ua, *ua_p;
spin_lock(&deve->ua_lock);
list_for_each_entry_safe(ua, ua_p, &deve->ua_list, ua_nacl_list) {
list_del(&ua->ua_nacl_list);
kmem_cache_free(se_ua_cache, ua);
atomic_dec(&deve->ua_count);
smp_mb__after_atomic_dec();
}
spin_unlock(&deve->ua_lock);
}
void core_scsi3_ua_for_check_condition(
struct se_cmd *cmd,
u8 *asc,
u8 *ascq)
{
struct se_device *dev = cmd->se_dev;
struct se_dev_entry *deve;
struct se_session *sess = cmd->se_sess;
struct se_node_acl *nacl;
struct se_ua *ua = NULL, *ua_p;
int head = 1;
if (!sess)
return;
nacl = sess->se_node_acl;
if (!nacl)
return;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[cmd->orig_fe_lun];
if (!atomic_read(&deve->ua_count)) {
spin_unlock_irq(&nacl->device_list_lock);
return;
}
spin_lock(&deve->ua_lock);
list_for_each_entry_safe(ua, ua_p, &deve->ua_list, ua_nacl_list) {
if (dev->dev_attrib.emulate_ua_intlck_ctrl != 0) {
*asc = ua->ua_asc;
*ascq = ua->ua_ascq;
break;
}
if (head) {
*asc = ua->ua_asc;
*ascq = ua->ua_ascq;
head = 0;
}
list_del(&ua->ua_nacl_list);
kmem_cache_free(se_ua_cache, ua);
atomic_dec(&deve->ua_count);
smp_mb__after_atomic_dec();
}
spin_unlock(&deve->ua_lock);
spin_unlock_irq(&nacl->device_list_lock);
pr_debug("[%s]: %s UNIT ATTENTION condition with"
" INTLCK_CTRL: %d, mapped LUN: %u, got CDB: 0x%02x"
" reported ASC: 0x%02x, ASCQ: 0x%02x\n",
nacl->se_tpg->se_tpg_tfo->get_fabric_name(),
(dev->dev_attrib.emulate_ua_intlck_ctrl != 0) ? "Reporting" :
"Releasing", dev->dev_attrib.emulate_ua_intlck_ctrl,
cmd->orig_fe_lun, cmd->t_task_cdb[0], *asc, *ascq);
}
int core_scsi3_ua_clear_for_request_sense(
struct se_cmd *cmd,
u8 *asc,
u8 *ascq)
{
struct se_dev_entry *deve;
struct se_session *sess = cmd->se_sess;
struct se_node_acl *nacl;
struct se_ua *ua = NULL, *ua_p;
int head = 1;
if (!sess)
return -EINVAL;
nacl = sess->se_node_acl;
if (!nacl)
return -EINVAL;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[cmd->orig_fe_lun];
if (!atomic_read(&deve->ua_count)) {
spin_unlock_irq(&nacl->device_list_lock);
return -EPERM;
}
spin_lock(&deve->ua_lock);
list_for_each_entry_safe(ua, ua_p, &deve->ua_list, ua_nacl_list) {
if (head) {
*asc = ua->ua_asc;
*ascq = ua->ua_ascq;
head = 0;
}
list_del(&ua->ua_nacl_list);
kmem_cache_free(se_ua_cache, ua);
atomic_dec(&deve->ua_count);
smp_mb__after_atomic_dec();
}
spin_unlock(&deve->ua_lock);
spin_unlock_irq(&nacl->device_list_lock);
pr_debug("[%s]: Released UNIT ATTENTION condition, mapped"
" LUN: %u, got REQUEST_SENSE reported ASC: 0x%02x,"
" ASCQ: 0x%02x\n", nacl->se_tpg->se_tpg_tfo->get_fabric_name(),
cmd->orig_fe_lun, *asc, *ascq);
return (head) ? -EPERM : 0;
}
