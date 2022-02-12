static struct se_device *to_stat_dev(struct config_item *item)
{
struct se_dev_stat_grps *sgrps = container_of(to_config_group(item),
struct se_dev_stat_grps, scsi_dev_group);
return container_of(sgrps, struct se_device, dev_stat_grps);
}
static ssize_t target_stat_inst_show(struct config_item *item, char *page)
{
struct se_hba *hba = to_stat_dev(item)->se_hba;
return snprintf(page, PAGE_SIZE, "%u\n", hba->hba_index);
}
static ssize_t target_stat_indx_show(struct config_item *item, char *page)
{
return snprintf(page, PAGE_SIZE, "%u\n", to_stat_dev(item)->dev_index);
}
static ssize_t target_stat_role_show(struct config_item *item, char *page)
{
return snprintf(page, PAGE_SIZE, "Target\n");
}
static ssize_t target_stat_ports_show(struct config_item *item, char *page)
{
return snprintf(page, PAGE_SIZE, "%u\n", to_stat_dev(item)->export_count);
}
static struct se_device *to_stat_tgt_dev(struct config_item *item)
{
struct se_dev_stat_grps *sgrps = container_of(to_config_group(item),
struct se_dev_stat_grps, scsi_tgt_dev_group);
return container_of(sgrps, struct se_device, dev_stat_grps);
}
static ssize_t target_stat_tgt_inst_show(struct config_item *item, char *page)
{
struct se_hba *hba = to_stat_tgt_dev(item)->se_hba;
return snprintf(page, PAGE_SIZE, "%u\n", hba->hba_index);
}
static ssize_t target_stat_tgt_indx_show(struct config_item *item, char *page)
{
return snprintf(page, PAGE_SIZE, "%u\n", to_stat_tgt_dev(item)->dev_index);
}
static ssize_t target_stat_tgt_num_lus_show(struct config_item *item,
char *page)
{
return snprintf(page, PAGE_SIZE, "%u\n", LU_COUNT);
}
static ssize_t target_stat_tgt_status_show(struct config_item *item,
char *page)
{
if (to_stat_tgt_dev(item)->export_count)
return snprintf(page, PAGE_SIZE, "activated");
else
return snprintf(page, PAGE_SIZE, "deactivated");
}
static ssize_t target_stat_tgt_non_access_lus_show(struct config_item *item,
char *page)
{
int non_accessible_lus;
if (to_stat_tgt_dev(item)->export_count)
non_accessible_lus = 0;
else
non_accessible_lus = 1;
return snprintf(page, PAGE_SIZE, "%u\n", non_accessible_lus);
}
static ssize_t target_stat_tgt_resets_show(struct config_item *item,
char *page)
{
return snprintf(page, PAGE_SIZE, "%lu\n",
atomic_long_read(&to_stat_tgt_dev(item)->num_resets));
}
static ssize_t target_stat_tgt_aborts_complete_show(struct config_item *item,
char *page)
{
return snprintf(page, PAGE_SIZE, "%lu\n",
atomic_long_read(&to_stat_tgt_dev(item)->aborts_complete));
}
static ssize_t target_stat_tgt_aborts_no_task_show(struct config_item *item,
char *page)
{
return snprintf(page, PAGE_SIZE, "%lu\n",
atomic_long_read(&to_stat_tgt_dev(item)->aborts_no_task));
}
static struct se_device *to_stat_lu_dev(struct config_item *item)
{
struct se_dev_stat_grps *sgrps = container_of(to_config_group(item),
struct se_dev_stat_grps, scsi_lu_group);
return container_of(sgrps, struct se_device, dev_stat_grps);
}
static ssize_t target_stat_lu_inst_show(struct config_item *item, char *page)
{
struct se_hba *hba = to_stat_lu_dev(item)->se_hba;
return snprintf(page, PAGE_SIZE, "%u\n", hba->hba_index);
}
static ssize_t target_stat_lu_dev_show(struct config_item *item, char *page)
{
return snprintf(page, PAGE_SIZE, "%u\n",
to_stat_lu_dev(item)->dev_index);
}
static ssize_t target_stat_lu_indx_show(struct config_item *item, char *page)
{
return snprintf(page, PAGE_SIZE, "%u\n", SCSI_LU_INDEX);
}
static ssize_t target_stat_lu_lun_show(struct config_item *item, char *page)
{
return snprintf(page, PAGE_SIZE, "%llu\n", (unsigned long long)0);
}
static ssize_t target_stat_lu_lu_name_show(struct config_item *item, char *page)
{
struct se_device *dev = to_stat_lu_dev(item);
return snprintf(page, PAGE_SIZE, "%s\n",
(strlen(dev->t10_wwn.unit_serial)) ?
dev->t10_wwn.unit_serial : "None");
}
static ssize_t target_stat_lu_vend_show(struct config_item *item, char *page)
{
struct se_device *dev = to_stat_lu_dev(item);
int i;
char str[sizeof(dev->t10_wwn.vendor)+1];
for (i = 0; i < sizeof(dev->t10_wwn.vendor); i++)
str[i] = ISPRINT(dev->t10_wwn.vendor[i]) ?
dev->t10_wwn.vendor[i] : ' ';
str[i] = '\0';
return snprintf(page, PAGE_SIZE, "%s\n", str);
}
static ssize_t target_stat_lu_prod_show(struct config_item *item, char *page)
{
struct se_device *dev = to_stat_lu_dev(item);
int i;
char str[sizeof(dev->t10_wwn.model)+1];
for (i = 0; i < sizeof(dev->t10_wwn.model); i++)
str[i] = ISPRINT(dev->t10_wwn.model[i]) ?
dev->t10_wwn.model[i] : ' ';
str[i] = '\0';
return snprintf(page, PAGE_SIZE, "%s\n", str);
}
static ssize_t target_stat_lu_rev_show(struct config_item *item, char *page)
{
struct se_device *dev = to_stat_lu_dev(item);
int i;
char str[sizeof(dev->t10_wwn.revision)+1];
for (i = 0; i < sizeof(dev->t10_wwn.revision); i++)
str[i] = ISPRINT(dev->t10_wwn.revision[i]) ?
dev->t10_wwn.revision[i] : ' ';
str[i] = '\0';
return snprintf(page, PAGE_SIZE, "%s\n", str);
}
static ssize_t target_stat_lu_dev_type_show(struct config_item *item, char *page)
{
struct se_device *dev = to_stat_lu_dev(item);
return snprintf(page, PAGE_SIZE, "%u\n",
dev->transport->get_device_type(dev));
}
static ssize_t target_stat_lu_status_show(struct config_item *item, char *page)
{
struct se_device *dev = to_stat_lu_dev(item);
return snprintf(page, PAGE_SIZE, "%s\n",
(dev->export_count) ? "available" : "notavailable");
}
static ssize_t target_stat_lu_state_bit_show(struct config_item *item,
char *page)
{
return snprintf(page, PAGE_SIZE, "exposed\n");
}
static ssize_t target_stat_lu_num_cmds_show(struct config_item *item,
char *page)
{
struct se_device *dev = to_stat_lu_dev(item);
return snprintf(page, PAGE_SIZE, "%lu\n",
atomic_long_read(&dev->num_cmds));
}
static ssize_t target_stat_lu_read_mbytes_show(struct config_item *item,
char *page)
{
struct se_device *dev = to_stat_lu_dev(item);
return snprintf(page, PAGE_SIZE, "%lu\n",
atomic_long_read(&dev->read_bytes) >> 20);
}
static ssize_t target_stat_lu_write_mbytes_show(struct config_item *item,
char *page)
{
struct se_device *dev = to_stat_lu_dev(item);
return snprintf(page, PAGE_SIZE, "%lu\n",
atomic_long_read(&dev->write_bytes) >> 20);
}
static ssize_t target_stat_lu_resets_show(struct config_item *item, char *page)
{
struct se_device *dev = to_stat_lu_dev(item);
return snprintf(page, PAGE_SIZE, "%lu\n",
atomic_long_read(&dev->num_resets));
}
static ssize_t target_stat_lu_full_stat_show(struct config_item *item,
char *page)
{
return snprintf(page, PAGE_SIZE, "%u\n", 0);
}
static ssize_t target_stat_lu_hs_num_cmds_show(struct config_item *item,
char *page)
{
return snprintf(page, PAGE_SIZE, "%u\n", 0);
}
static ssize_t target_stat_lu_creation_time_show(struct config_item *item,
char *page)
{
struct se_device *dev = to_stat_lu_dev(item);
return snprintf(page, PAGE_SIZE, "%u\n", (u32)(((u32)dev->creation_time -
INITIAL_JIFFIES) * 100 / HZ));
}
void target_stat_setup_dev_default_groups(struct se_device *dev)
{
config_group_init_type_name(&dev->dev_stat_grps.scsi_dev_group,
"scsi_dev", &target_stat_scsi_dev_cit);
configfs_add_default_group(&dev->dev_stat_grps.scsi_dev_group,
&dev->dev_stat_grps.stat_group);
config_group_init_type_name(&dev->dev_stat_grps.scsi_tgt_dev_group,
"scsi_tgt_dev", &target_stat_scsi_tgt_dev_cit);
configfs_add_default_group(&dev->dev_stat_grps.scsi_tgt_dev_group,
&dev->dev_stat_grps.stat_group);
config_group_init_type_name(&dev->dev_stat_grps.scsi_lu_group,
"scsi_lu", &target_stat_scsi_lu_cit);
configfs_add_default_group(&dev->dev_stat_grps.scsi_lu_group,
&dev->dev_stat_grps.stat_group);
}
static struct se_lun *to_stat_port(struct config_item *item)
{
struct se_port_stat_grps *pgrps = container_of(to_config_group(item),
struct se_port_stat_grps, scsi_port_group);
return container_of(pgrps, struct se_lun, port_stat_grps);
}
static ssize_t target_stat_port_inst_show(struct config_item *item, char *page)
{
struct se_lun *lun = to_stat_port(item);
struct se_device *dev;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev)
ret = snprintf(page, PAGE_SIZE, "%u\n", dev->hba_index);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_port_dev_show(struct config_item *item, char *page)
{
struct se_lun *lun = to_stat_port(item);
struct se_device *dev;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev)
ret = snprintf(page, PAGE_SIZE, "%u\n", dev->dev_index);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_port_indx_show(struct config_item *item, char *page)
{
struct se_lun *lun = to_stat_port(item);
struct se_device *dev;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev)
ret = snprintf(page, PAGE_SIZE, "%u\n", lun->lun_rtpi);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_port_role_show(struct config_item *item, char *page)
{
struct se_lun *lun = to_stat_port(item);
struct se_device *dev;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev)
ret = snprintf(page, PAGE_SIZE, "%s%u\n", "Device", dev->dev_index);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_port_busy_count_show(struct config_item *item,
char *page)
{
struct se_lun *lun = to_stat_port(item);
struct se_device *dev;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev) {
ret = snprintf(page, PAGE_SIZE, "%u\n", 0);
}
rcu_read_unlock();
return ret;
}
static struct se_lun *to_stat_tgt_port(struct config_item *item)
{
struct se_port_stat_grps *pgrps = container_of(to_config_group(item),
struct se_port_stat_grps, scsi_tgt_port_group);
return container_of(pgrps, struct se_lun, port_stat_grps);
}
static ssize_t target_stat_tgt_port_inst_show(struct config_item *item,
char *page)
{
struct se_lun *lun = to_stat_tgt_port(item);
struct se_device *dev;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev)
ret = snprintf(page, PAGE_SIZE, "%u\n", dev->hba_index);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_tgt_port_dev_show(struct config_item *item,
char *page)
{
struct se_lun *lun = to_stat_tgt_port(item);
struct se_device *dev;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev)
ret = snprintf(page, PAGE_SIZE, "%u\n", dev->dev_index);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_tgt_port_indx_show(struct config_item *item,
char *page)
{
struct se_lun *lun = to_stat_tgt_port(item);
struct se_device *dev;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev)
ret = snprintf(page, PAGE_SIZE, "%u\n", lun->lun_rtpi);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_tgt_port_name_show(struct config_item *item,
char *page)
{
struct se_lun *lun = to_stat_tgt_port(item);
struct se_portal_group *tpg = lun->lun_tpg;
struct se_device *dev;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev)
ret = snprintf(page, PAGE_SIZE, "%sPort#%u\n",
tpg->se_tpg_tfo->get_fabric_name(),
lun->lun_rtpi);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_tgt_port_port_index_show(struct config_item *item,
char *page)
{
struct se_lun *lun = to_stat_tgt_port(item);
struct se_portal_group *tpg = lun->lun_tpg;
struct se_device *dev;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev)
ret = snprintf(page, PAGE_SIZE, "%s%s%d\n",
tpg->se_tpg_tfo->tpg_get_wwn(tpg), "+t+",
tpg->se_tpg_tfo->tpg_get_tag(tpg));
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_tgt_port_in_cmds_show(struct config_item *item,
char *page)
{
struct se_lun *lun = to_stat_tgt_port(item);
struct se_device *dev;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev)
ret = snprintf(page, PAGE_SIZE, "%lu\n",
atomic_long_read(&lun->lun_stats.cmd_pdus));
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_tgt_port_write_mbytes_show(struct config_item *item,
char *page)
{
struct se_lun *lun = to_stat_tgt_port(item);
struct se_device *dev;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev)
ret = snprintf(page, PAGE_SIZE, "%u\n",
(u32)(atomic_long_read(&lun->lun_stats.rx_data_octets) >> 20));
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_tgt_port_read_mbytes_show(struct config_item *item,
char *page)
{
struct se_lun *lun = to_stat_tgt_port(item);
struct se_device *dev;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev)
ret = snprintf(page, PAGE_SIZE, "%u\n",
(u32)(atomic_long_read(&lun->lun_stats.tx_data_octets) >> 20));
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_tgt_port_hs_in_cmds_show(struct config_item *item,
char *page)
{
struct se_lun *lun = to_stat_tgt_port(item);
struct se_device *dev;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev) {
ret = snprintf(page, PAGE_SIZE, "%u\n", 0);
}
rcu_read_unlock();
return ret;
}
static struct se_lun *to_transport_stat(struct config_item *item)
{
struct se_port_stat_grps *pgrps = container_of(to_config_group(item),
struct se_port_stat_grps, scsi_transport_group);
return container_of(pgrps, struct se_lun, port_stat_grps);
}
static ssize_t target_stat_transport_inst_show(struct config_item *item,
char *page)
{
struct se_lun *lun = to_transport_stat(item);
struct se_device *dev;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev)
ret = snprintf(page, PAGE_SIZE, "%u\n", dev->hba_index);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_transport_device_show(struct config_item *item,
char *page)
{
struct se_lun *lun = to_transport_stat(item);
struct se_device *dev;
struct se_portal_group *tpg = lun->lun_tpg;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev) {
ret = snprintf(page, PAGE_SIZE, "scsiTransport%s\n",
tpg->se_tpg_tfo->get_fabric_name());
}
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_transport_indx_show(struct config_item *item,
char *page)
{
struct se_lun *lun = to_transport_stat(item);
struct se_device *dev;
struct se_portal_group *tpg = lun->lun_tpg;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev)
ret = snprintf(page, PAGE_SIZE, "%u\n",
tpg->se_tpg_tfo->tpg_get_inst_index(tpg));
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_transport_dev_name_show(struct config_item *item,
char *page)
{
struct se_lun *lun = to_transport_stat(item);
struct se_device *dev;
struct se_portal_group *tpg = lun->lun_tpg;
struct t10_wwn *wwn;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev) {
wwn = &dev->t10_wwn;
ret = snprintf(page, PAGE_SIZE, "%s+%s\n",
tpg->se_tpg_tfo->tpg_get_wwn(tpg),
(strlen(wwn->unit_serial)) ? wwn->unit_serial :
wwn->vendor);
}
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_transport_proto_id_show(struct config_item *item,
char *page)
{
struct se_lun *lun = to_transport_stat(item);
struct se_device *dev;
struct se_portal_group *tpg = lun->lun_tpg;
ssize_t ret = -ENODEV;
rcu_read_lock();
dev = rcu_dereference(lun->lun_se_dev);
if (dev)
ret = snprintf(page, PAGE_SIZE, "%u\n", tpg->proto_id);
rcu_read_unlock();
return ret;
}
void target_stat_setup_port_default_groups(struct se_lun *lun)
{
config_group_init_type_name(&lun->port_stat_grps.scsi_port_group,
"scsi_port", &target_stat_scsi_port_cit);
configfs_add_default_group(&lun->port_stat_grps.scsi_port_group,
&lun->port_stat_grps.stat_group);
config_group_init_type_name(&lun->port_stat_grps.scsi_tgt_port_group,
"scsi_tgt_port", &target_stat_scsi_tgt_port_cit);
configfs_add_default_group(&lun->port_stat_grps.scsi_tgt_port_group,
&lun->port_stat_grps.stat_group);
config_group_init_type_name(&lun->port_stat_grps.scsi_transport_group,
"scsi_transport", &target_stat_scsi_transport_cit);
configfs_add_default_group(&lun->port_stat_grps.scsi_transport_group,
&lun->port_stat_grps.stat_group);
}
static struct se_lun_acl *auth_to_lacl(struct config_item *item)
{
struct se_ml_stat_grps *lgrps = container_of(to_config_group(item),
struct se_ml_stat_grps, scsi_auth_intr_group);
return container_of(lgrps, struct se_lun_acl, ml_stat_grps);
}
static ssize_t target_stat_auth_inst_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = auth_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
struct se_portal_group *tpg;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
tpg = nacl->se_tpg;
ret = snprintf(page, PAGE_SIZE, "%u\n",
tpg->se_tpg_tfo->tpg_get_inst_index(tpg));
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_auth_dev_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = auth_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
struct se_lun *lun;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
lun = rcu_dereference(deve->se_lun);
ret = snprintf(page, PAGE_SIZE, "%u\n", lun->lun_index);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_auth_port_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = auth_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
struct se_portal_group *tpg;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
tpg = nacl->se_tpg;
ret = snprintf(page, PAGE_SIZE, "%u\n", tpg->se_tpg_tfo->tpg_get_tag(tpg));
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_auth_indx_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = auth_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", nacl->acl_index);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_auth_dev_or_port_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = auth_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", 1);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_auth_intr_name_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = auth_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%s\n", nacl->initiatorname);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_auth_map_indx_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = auth_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", 0);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_auth_att_count_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = auth_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", deve->attach_count);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_auth_num_cmds_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = auth_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%lu\n",
atomic_long_read(&deve->total_cmds));
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_auth_read_mbytes_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = auth_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n",
(u32)(atomic_long_read(&deve->read_bytes) >> 20));
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_auth_write_mbytes_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = auth_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n",
(u32)(atomic_long_read(&deve->write_bytes) >> 20));
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_auth_hs_num_cmds_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = auth_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", 0);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_auth_creation_time_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = auth_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", (u32)(((u32)deve->creation_time -
INITIAL_JIFFIES) * 100 / HZ));
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_auth_row_status_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = auth_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "Ready\n");
rcu_read_unlock();
return ret;
}
static struct se_lun_acl *iport_to_lacl(struct config_item *item)
{
struct se_ml_stat_grps *lgrps = container_of(to_config_group(item),
struct se_ml_stat_grps, scsi_att_intr_port_group);
return container_of(lgrps, struct se_lun_acl, ml_stat_grps);
}
static ssize_t target_stat_iport_inst_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = iport_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
struct se_portal_group *tpg;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
tpg = nacl->se_tpg;
ret = snprintf(page, PAGE_SIZE, "%u\n",
tpg->se_tpg_tfo->tpg_get_inst_index(tpg));
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_iport_dev_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = iport_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
struct se_lun *lun;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
lun = rcu_dereference(deve->se_lun);
ret = snprintf(page, PAGE_SIZE, "%u\n", lun->lun_index);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_iport_port_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = iport_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
struct se_portal_group *tpg;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
tpg = nacl->se_tpg;
ret = snprintf(page, PAGE_SIZE, "%u\n", tpg->se_tpg_tfo->tpg_get_tag(tpg));
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_iport_indx_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = iport_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_session *se_sess;
struct se_portal_group *tpg;
ssize_t ret;
spin_lock_irq(&nacl->nacl_sess_lock);
se_sess = nacl->nacl_sess;
if (!se_sess) {
spin_unlock_irq(&nacl->nacl_sess_lock);
return -ENODEV;
}
tpg = nacl->se_tpg;
ret = snprintf(page, PAGE_SIZE, "%u\n",
tpg->se_tpg_tfo->sess_get_index(se_sess));
spin_unlock_irq(&nacl->nacl_sess_lock);
return ret;
}
static ssize_t target_stat_iport_port_auth_indx_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = iport_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
rcu_read_lock();
deve = target_nacl_find_deve(nacl, lacl->mapped_lun);
if (!deve) {
rcu_read_unlock();
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", nacl->acl_index);
rcu_read_unlock();
return ret;
}
static ssize_t target_stat_iport_port_ident_show(struct config_item *item,
char *page)
{
struct se_lun_acl *lacl = iport_to_lacl(item);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_session *se_sess;
struct se_portal_group *tpg;
ssize_t ret;
unsigned char buf[64];
spin_lock_irq(&nacl->nacl_sess_lock);
se_sess = nacl->nacl_sess;
if (!se_sess) {
spin_unlock_irq(&nacl->nacl_sess_lock);
return -ENODEV;
}
tpg = nacl->se_tpg;
memset(buf, 0, 64);
if (tpg->se_tpg_tfo->sess_get_initiator_sid != NULL)
tpg->se_tpg_tfo->sess_get_initiator_sid(se_sess, buf, 64);
ret = snprintf(page, PAGE_SIZE, "%s+i+%s\n", nacl->initiatorname, buf);
spin_unlock_irq(&nacl->nacl_sess_lock);
return ret;
}
void target_stat_setup_mappedlun_default_groups(struct se_lun_acl *lacl)
{
config_group_init_type_name(&lacl->ml_stat_grps.scsi_auth_intr_group,
"scsi_auth_intr", &target_stat_scsi_auth_intr_cit);
configfs_add_default_group(&lacl->ml_stat_grps.scsi_auth_intr_group,
&lacl->ml_stat_grps.stat_group);
config_group_init_type_name(&lacl->ml_stat_grps.scsi_att_intr_port_group,
"scsi_att_intr_port", &target_stat_scsi_att_intr_port_cit);
configfs_add_default_group(&lacl->ml_stat_grps.scsi_att_intr_port_group,
&lacl->ml_stat_grps.stat_group);
}
