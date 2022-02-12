static ssize_t target_stat_scsi_dev_show_attr_inst(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_hba *hba = se_subdev->se_dev_hba;
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", hba->hba_index);
}
static ssize_t target_stat_scsi_dev_show_attr_indx(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", dev->dev_index);
}
static ssize_t target_stat_scsi_dev_show_attr_role(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "Target\n");
}
static ssize_t target_stat_scsi_dev_show_attr_ports(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", dev->dev_port_count);
}
static ssize_t target_stat_scsi_tgt_dev_show_attr_inst(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_hba *hba = se_subdev->se_dev_hba;
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", hba->hba_index);
}
static ssize_t target_stat_scsi_tgt_dev_show_attr_indx(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", dev->dev_index);
}
static ssize_t target_stat_scsi_tgt_dev_show_attr_num_lus(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", LU_COUNT);
}
static ssize_t target_stat_scsi_tgt_dev_show_attr_status(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
char status[16];
if (!dev)
return -ENODEV;
switch (dev->dev_status) {
case TRANSPORT_DEVICE_ACTIVATED:
strcpy(status, "activated");
break;
case TRANSPORT_DEVICE_DEACTIVATED:
strcpy(status, "deactivated");
break;
case TRANSPORT_DEVICE_SHUTDOWN:
strcpy(status, "shutdown");
break;
case TRANSPORT_DEVICE_OFFLINE_ACTIVATED:
case TRANSPORT_DEVICE_OFFLINE_DEACTIVATED:
strcpy(status, "offline");
break;
default:
sprintf(status, "unknown(%d)", dev->dev_status);
break;
}
return snprintf(page, PAGE_SIZE, "%s\n", status);
}
static ssize_t target_stat_scsi_tgt_dev_show_attr_non_access_lus(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
int non_accessible_lus;
if (!dev)
return -ENODEV;
switch (dev->dev_status) {
case TRANSPORT_DEVICE_ACTIVATED:
non_accessible_lus = 0;
break;
case TRANSPORT_DEVICE_DEACTIVATED:
case TRANSPORT_DEVICE_SHUTDOWN:
case TRANSPORT_DEVICE_OFFLINE_ACTIVATED:
case TRANSPORT_DEVICE_OFFLINE_DEACTIVATED:
default:
non_accessible_lus = 1;
break;
}
return snprintf(page, PAGE_SIZE, "%u\n", non_accessible_lus);
}
static ssize_t target_stat_scsi_tgt_dev_show_attr_resets(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", dev->num_resets);
}
static ssize_t target_stat_scsi_lu_show_attr_inst(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_hba *hba = se_subdev->se_dev_hba;
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", hba->hba_index);
}
static ssize_t target_stat_scsi_lu_show_attr_dev(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", dev->dev_index);
}
static ssize_t target_stat_scsi_lu_show_attr_indx(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", SCSI_LU_INDEX);
}
static ssize_t target_stat_scsi_lu_show_attr_lun(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%llu\n", (unsigned long long)0);
}
static ssize_t target_stat_scsi_lu_show_attr_lu_name(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%s\n",
(strlen(dev->se_sub_dev->t10_wwn.unit_serial)) ?
dev->se_sub_dev->t10_wwn.unit_serial : "None");
}
static ssize_t target_stat_scsi_lu_show_attr_vend(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
int i;
char str[sizeof(dev->se_sub_dev->t10_wwn.vendor)+1];
if (!dev)
return -ENODEV;
for (i = 0; i < sizeof(dev->se_sub_dev->t10_wwn.vendor); i++)
str[i] = ISPRINT(dev->se_sub_dev->t10_wwn.vendor[i]) ?
dev->se_sub_dev->t10_wwn.vendor[i] : ' ';
str[i] = '\0';
return snprintf(page, PAGE_SIZE, "%s\n", str);
}
static ssize_t target_stat_scsi_lu_show_attr_prod(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
int i;
char str[sizeof(dev->se_sub_dev->t10_wwn.model)+1];
if (!dev)
return -ENODEV;
for (i = 0; i < sizeof(dev->se_sub_dev->t10_wwn.vendor); i++)
str[i] = ISPRINT(dev->se_sub_dev->t10_wwn.model[i]) ?
dev->se_sub_dev->t10_wwn.model[i] : ' ';
str[i] = '\0';
return snprintf(page, PAGE_SIZE, "%s\n", str);
}
static ssize_t target_stat_scsi_lu_show_attr_rev(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
int i;
char str[sizeof(dev->se_sub_dev->t10_wwn.revision)+1];
if (!dev)
return -ENODEV;
for (i = 0; i < sizeof(dev->se_sub_dev->t10_wwn.revision); i++)
str[i] = ISPRINT(dev->se_sub_dev->t10_wwn.revision[i]) ?
dev->se_sub_dev->t10_wwn.revision[i] : ' ';
str[i] = '\0';
return snprintf(page, PAGE_SIZE, "%s\n", str);
}
static ssize_t target_stat_scsi_lu_show_attr_dev_type(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n",
dev->transport->get_device_type(dev));
}
static ssize_t target_stat_scsi_lu_show_attr_status(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%s\n",
(dev->dev_status == TRANSPORT_DEVICE_ACTIVATED) ?
"available" : "notavailable");
}
static ssize_t target_stat_scsi_lu_show_attr_state_bit(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "exposed\n");
}
static ssize_t target_stat_scsi_lu_show_attr_num_cmds(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%llu\n",
(unsigned long long)dev->num_cmds);
}
static ssize_t target_stat_scsi_lu_show_attr_read_mbytes(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", (u32)(dev->read_bytes >> 20));
}
static ssize_t target_stat_scsi_lu_show_attr_write_mbytes(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", (u32)(dev->write_bytes >> 20));
}
static ssize_t target_stat_scsi_lu_show_attr_resets(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", dev->num_resets);
}
static ssize_t target_stat_scsi_lu_show_attr_full_stat(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", 0);
}
static ssize_t target_stat_scsi_lu_show_attr_hs_num_cmds(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", 0);
}
static ssize_t target_stat_scsi_lu_show_attr_creation_time(
struct se_dev_stat_grps *sgrps, char *page)
{
struct se_subsystem_dev *se_subdev = container_of(sgrps,
struct se_subsystem_dev, dev_stat_grps);
struct se_device *dev = se_subdev->se_dev_ptr;
if (!dev)
return -ENODEV;
return snprintf(page, PAGE_SIZE, "%u\n", (u32)(((u32)dev->creation_time -
INITIAL_JIFFIES) * 100 / HZ));
}
void target_stat_setup_dev_default_groups(struct se_subsystem_dev *se_subdev)
{
struct config_group *dev_stat_grp = &se_subdev->dev_stat_grps.stat_group;
config_group_init_type_name(&se_subdev->dev_stat_grps.scsi_dev_group,
"scsi_dev", &target_stat_scsi_dev_cit);
config_group_init_type_name(&se_subdev->dev_stat_grps.scsi_tgt_dev_group,
"scsi_tgt_dev", &target_stat_scsi_tgt_dev_cit);
config_group_init_type_name(&se_subdev->dev_stat_grps.scsi_lu_group,
"scsi_lu", &target_stat_scsi_lu_cit);
dev_stat_grp->default_groups[0] = &se_subdev->dev_stat_grps.scsi_dev_group;
dev_stat_grp->default_groups[1] = &se_subdev->dev_stat_grps.scsi_tgt_dev_group;
dev_stat_grp->default_groups[2] = &se_subdev->dev_stat_grps.scsi_lu_group;
dev_stat_grp->default_groups[3] = NULL;
}
static ssize_t target_stat_scsi_port_show_attr_inst(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_port *sep;
struct se_device *dev = lun->lun_se_dev;
struct se_hba *hba;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
hba = dev->se_hba;
ret = snprintf(page, PAGE_SIZE, "%u\n", hba->hba_index);
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_port_show_attr_dev(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_port *sep;
struct se_device *dev = lun->lun_se_dev;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", dev->dev_index);
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_port_show_attr_indx(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_port *sep;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", sep->sep_index);
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_port_show_attr_role(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_device *dev = lun->lun_se_dev;
struct se_port *sep;
ssize_t ret;
if (!dev)
return -ENODEV;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%s%u\n", "Device", dev->dev_index);
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_port_show_attr_busy_count(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_port *sep;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", 0);
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_tgt_port_show_attr_inst(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_device *dev = lun->lun_se_dev;
struct se_port *sep;
struct se_hba *hba;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
hba = dev->se_hba;
ret = snprintf(page, PAGE_SIZE, "%u\n", hba->hba_index);
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_tgt_port_show_attr_dev(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_device *dev = lun->lun_se_dev;
struct se_port *sep;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", dev->dev_index);
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_tgt_port_show_attr_indx(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_port *sep;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", sep->sep_index);
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_tgt_port_show_attr_name(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_port *sep;
struct se_portal_group *tpg;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
tpg = sep->sep_tpg;
ret = snprintf(page, PAGE_SIZE, "%sPort#%u\n",
tpg->se_tpg_tfo->get_fabric_name(), sep->sep_index);
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_tgt_port_show_attr_port_index(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_port *sep;
struct se_portal_group *tpg;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
tpg = sep->sep_tpg;
ret = snprintf(page, PAGE_SIZE, "%s%s%d\n",
tpg->se_tpg_tfo->tpg_get_wwn(tpg), "+t+",
tpg->se_tpg_tfo->tpg_get_tag(tpg));
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_tgt_port_show_attr_in_cmds(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_port *sep;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%llu\n", sep->sep_stats.cmd_pdus);
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_tgt_port_show_attr_write_mbytes(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_port *sep;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n",
(u32)(sep->sep_stats.rx_data_octets >> 20));
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_tgt_port_show_attr_read_mbytes(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_port *sep;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n",
(u32)(sep->sep_stats.tx_data_octets >> 20));
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_tgt_port_show_attr_hs_in_cmds(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_port *sep;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", 0);
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_transport_show_attr_inst(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_device *dev = lun->lun_se_dev;
struct se_port *sep;
struct se_hba *hba;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
hba = dev->se_hba;
ret = snprintf(page, PAGE_SIZE, "%u\n", hba->hba_index);
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_transport_show_attr_device(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_port *sep;
struct se_portal_group *tpg;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
tpg = sep->sep_tpg;
ret = snprintf(page, PAGE_SIZE, "scsiTransport%s\n",
tpg->se_tpg_tfo->get_fabric_name());
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_transport_show_attr_indx(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_port *sep;
struct se_portal_group *tpg;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
tpg = sep->sep_tpg;
ret = snprintf(page, PAGE_SIZE, "%u\n",
tpg->se_tpg_tfo->tpg_get_inst_index(tpg));
spin_unlock(&lun->lun_sep_lock);
return ret;
}
static ssize_t target_stat_scsi_transport_show_attr_dev_name(
struct se_port_stat_grps *pgrps, char *page)
{
struct se_lun *lun = container_of(pgrps, struct se_lun, port_stat_grps);
struct se_device *dev = lun->lun_se_dev;
struct se_port *sep;
struct se_portal_group *tpg;
struct t10_wwn *wwn;
ssize_t ret;
spin_lock(&lun->lun_sep_lock);
sep = lun->lun_sep;
if (!sep) {
spin_unlock(&lun->lun_sep_lock);
return -ENODEV;
}
tpg = sep->sep_tpg;
wwn = &dev->se_sub_dev->t10_wwn;
ret = snprintf(page, PAGE_SIZE, "%s+%s\n",
tpg->se_tpg_tfo->tpg_get_wwn(tpg),
(strlen(wwn->unit_serial)) ? wwn->unit_serial :
wwn->vendor);
spin_unlock(&lun->lun_sep_lock);
return ret;
}
void target_stat_setup_port_default_groups(struct se_lun *lun)
{
struct config_group *port_stat_grp = &lun->port_stat_grps.stat_group;
config_group_init_type_name(&lun->port_stat_grps.scsi_port_group,
"scsi_port", &target_stat_scsi_port_cit);
config_group_init_type_name(&lun->port_stat_grps.scsi_tgt_port_group,
"scsi_tgt_port", &target_stat_scsi_tgt_port_cit);
config_group_init_type_name(&lun->port_stat_grps.scsi_transport_group,
"scsi_transport", &target_stat_scsi_transport_cit);
port_stat_grp->default_groups[0] = &lun->port_stat_grps.scsi_port_group;
port_stat_grp->default_groups[1] = &lun->port_stat_grps.scsi_tgt_port_group;
port_stat_grp->default_groups[2] = &lun->port_stat_grps.scsi_transport_group;
port_stat_grp->default_groups[3] = NULL;
}
static ssize_t target_stat_scsi_auth_intr_show_attr_inst(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
struct se_portal_group *tpg;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
tpg = nacl->se_tpg;
ret = snprintf(page, PAGE_SIZE, "%u\n",
tpg->se_tpg_tfo->tpg_get_inst_index(tpg));
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_auth_intr_show_attr_dev(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
struct se_lun *lun;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
lun = deve->se_lun;
ret = snprintf(page, PAGE_SIZE, "%u\n", lun->lun_se_dev->dev_index);
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_auth_intr_show_attr_port(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
struct se_portal_group *tpg;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
tpg = nacl->se_tpg;
ret = snprintf(page, PAGE_SIZE, "%u\n", tpg->se_tpg_tfo->tpg_get_tag(tpg));
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_auth_intr_show_attr_indx(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", nacl->acl_index);
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_auth_intr_show_attr_dev_or_port(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", 1);
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_auth_intr_show_attr_intr_name(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%s\n", nacl->initiatorname);
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_auth_intr_show_attr_map_indx(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", 0);
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_auth_intr_show_attr_att_count(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", deve->attach_count);
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_auth_intr_show_attr_num_cmds(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", deve->total_cmds);
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_auth_intr_show_attr_read_mbytes(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", (u32)(deve->read_bytes >> 20));
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_auth_intr_show_attr_write_mbytes(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", (u32)(deve->write_bytes >> 20));
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_auth_intr_show_attr_hs_num_cmds(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", 0);
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_auth_intr_show_attr_creation_time(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", (u32)(((u32)deve->creation_time -
INITIAL_JIFFIES) * 100 / HZ));
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_auth_intr_show_attr_row_status(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "Ready\n");
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_att_intr_port_show_attr_inst(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
struct se_portal_group *tpg;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
tpg = nacl->se_tpg;
ret = snprintf(page, PAGE_SIZE, "%u\n",
tpg->se_tpg_tfo->tpg_get_inst_index(tpg));
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_att_intr_port_show_attr_dev(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
struct se_lun *lun;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
lun = deve->se_lun;
ret = snprintf(page, PAGE_SIZE, "%u\n", lun->lun_se_dev->dev_index);
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_att_intr_port_show_attr_port(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
struct se_portal_group *tpg;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
tpg = nacl->se_tpg;
ret = snprintf(page, PAGE_SIZE, "%u\n", tpg->se_tpg_tfo->tpg_get_tag(tpg));
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_att_intr_port_show_attr_indx(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
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
static ssize_t target_stat_scsi_att_intr_port_show_attr_port_auth_indx(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t ret;
spin_lock_irq(&nacl->device_list_lock);
deve = nacl->device_list[lacl->mapped_lun];
if (!deve->se_lun || !deve->se_lun_acl) {
spin_unlock_irq(&nacl->device_list_lock);
return -ENODEV;
}
ret = snprintf(page, PAGE_SIZE, "%u\n", nacl->acl_index);
spin_unlock_irq(&nacl->device_list_lock);
return ret;
}
static ssize_t target_stat_scsi_att_intr_port_show_attr_port_ident(
struct se_ml_stat_grps *lgrps, char *page)
{
struct se_lun_acl *lacl = container_of(lgrps,
struct se_lun_acl, ml_stat_grps);
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
struct config_group *ml_stat_grp = &lacl->ml_stat_grps.stat_group;
config_group_init_type_name(&lacl->ml_stat_grps.scsi_auth_intr_group,
"scsi_auth_intr", &target_stat_scsi_auth_intr_cit);
config_group_init_type_name(&lacl->ml_stat_grps.scsi_att_intr_port_group,
"scsi_att_intr_port", &target_stat_scsi_att_intr_port_cit);
ml_stat_grp->default_groups[0] = &lacl->ml_stat_grps.scsi_auth_intr_group;
ml_stat_grp->default_groups[1] = &lacl->ml_stat_grps.scsi_att_intr_port_group;
ml_stat_grp->default_groups[2] = NULL;
}
