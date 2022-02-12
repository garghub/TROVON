static inline struct se_hba *
item_to_hba(struct config_item *item)
{
return container_of(to_config_group(item), struct se_hba, hba_group);
}
static ssize_t target_core_attr_show(struct config_item *item,
struct configfs_attribute *attr,
char *page)
{
return sprintf(page, "Target Engine Core ConfigFS Infrastructure %s"
" on %s/%s on "UTS_RELEASE"\n", TARGET_CORE_VERSION,
utsname()->sysname, utsname()->machine);
}
static struct target_fabric_configfs *target_core_get_fabric(
const char *name)
{
struct target_fabric_configfs *tf;
if (!name)
return NULL;
mutex_lock(&g_tf_lock);
list_for_each_entry(tf, &g_tf_list, tf_list) {
if (!strcmp(tf->tf_ops->name, name)) {
atomic_inc(&tf->tf_access_cnt);
mutex_unlock(&g_tf_lock);
return tf;
}
}
mutex_unlock(&g_tf_lock);
return NULL;
}
static struct config_group *target_core_register_fabric(
struct config_group *group,
const char *name)
{
struct target_fabric_configfs *tf;
int ret;
pr_debug("Target_Core_ConfigFS: REGISTER -> group: %p name:"
" %s\n", group, name);
tf = target_core_get_fabric(name);
if (!tf) {
pr_debug("target_core_register_fabric() trying autoload for %s\n",
name);
if (!strncmp(name, "iscsi", 5)) {
ret = request_module("iscsi_target_mod");
if (ret < 0) {
pr_debug("request_module() failed for"
" iscsi_target_mod.ko: %d\n", ret);
return ERR_PTR(-EINVAL);
}
} else if (!strncmp(name, "loopback", 8)) {
ret = request_module("tcm_loop");
if (ret < 0) {
pr_debug("request_module() failed for"
" tcm_loop.ko: %d\n", ret);
return ERR_PTR(-EINVAL);
}
}
tf = target_core_get_fabric(name);
}
if (!tf) {
pr_debug("target_core_get_fabric() failed for %s\n",
name);
return ERR_PTR(-EINVAL);
}
pr_debug("Target_Core_ConfigFS: REGISTER -> Located fabric:"
" %s\n", tf->tf_ops->name);
pr_debug("Target_Core_ConfigFS: REGISTER tfc_wwn_cit -> %p\n",
&tf->tf_wwn_cit);
tf->tf_group.default_groups = tf->tf_default_groups;
tf->tf_group.default_groups[0] = &tf->tf_disc_group;
tf->tf_group.default_groups[1] = NULL;
config_group_init_type_name(&tf->tf_group, name, &tf->tf_wwn_cit);
config_group_init_type_name(&tf->tf_disc_group, "discovery_auth",
&tf->tf_discovery_cit);
pr_debug("Target_Core_ConfigFS: REGISTER -> Allocated Fabric:"
" %s\n", tf->tf_group.cg_item.ci_name);
return &tf->tf_group;
}
static void target_core_deregister_fabric(
struct config_group *group,
struct config_item *item)
{
struct target_fabric_configfs *tf = container_of(
to_config_group(item), struct target_fabric_configfs, tf_group);
struct config_group *tf_group;
struct config_item *df_item;
int i;
pr_debug("Target_Core_ConfigFS: DEREGISTER -> Looking up %s in"
" tf list\n", config_item_name(item));
pr_debug("Target_Core_ConfigFS: DEREGISTER -> located fabric:"
" %s\n", tf->tf_ops->name);
atomic_dec(&tf->tf_access_cnt);
pr_debug("Target_Core_ConfigFS: DEREGISTER -> Releasing ci"
" %s\n", config_item_name(item));
tf_group = &tf->tf_group;
for (i = 0; tf_group->default_groups[i]; i++) {
df_item = &tf_group->default_groups[i]->cg_item;
tf_group->default_groups[i] = NULL;
config_item_put(df_item);
}
config_item_put(item);
}
int target_depend_item(struct config_item *item)
{
return configfs_depend_item(&target_core_fabrics, item);
}
void target_undepend_item(struct config_item *item)
{
return configfs_undepend_item(&target_core_fabrics, item);
}
static int target_fabric_tf_ops_check(const struct target_core_fabric_ops *tfo)
{
if (!tfo->name) {
pr_err("Missing tfo->name\n");
return -EINVAL;
}
if (strlen(tfo->name) >= TARGET_FABRIC_NAME_SIZE) {
pr_err("Passed name: %s exceeds TARGET_FABRIC"
"_NAME_SIZE\n", tfo->name);
return -EINVAL;
}
if (!tfo->get_fabric_name) {
pr_err("Missing tfo->get_fabric_name()\n");
return -EINVAL;
}
if (!tfo->tpg_get_wwn) {
pr_err("Missing tfo->tpg_get_wwn()\n");
return -EINVAL;
}
if (!tfo->tpg_get_tag) {
pr_err("Missing tfo->tpg_get_tag()\n");
return -EINVAL;
}
if (!tfo->tpg_check_demo_mode) {
pr_err("Missing tfo->tpg_check_demo_mode()\n");
return -EINVAL;
}
if (!tfo->tpg_check_demo_mode_cache) {
pr_err("Missing tfo->tpg_check_demo_mode_cache()\n");
return -EINVAL;
}
if (!tfo->tpg_check_demo_mode_write_protect) {
pr_err("Missing tfo->tpg_check_demo_mode_write_protect()\n");
return -EINVAL;
}
if (!tfo->tpg_check_prod_mode_write_protect) {
pr_err("Missing tfo->tpg_check_prod_mode_write_protect()\n");
return -EINVAL;
}
if (!tfo->tpg_get_inst_index) {
pr_err("Missing tfo->tpg_get_inst_index()\n");
return -EINVAL;
}
if (!tfo->release_cmd) {
pr_err("Missing tfo->release_cmd()\n");
return -EINVAL;
}
if (!tfo->shutdown_session) {
pr_err("Missing tfo->shutdown_session()\n");
return -EINVAL;
}
if (!tfo->close_session) {
pr_err("Missing tfo->close_session()\n");
return -EINVAL;
}
if (!tfo->sess_get_index) {
pr_err("Missing tfo->sess_get_index()\n");
return -EINVAL;
}
if (!tfo->write_pending) {
pr_err("Missing tfo->write_pending()\n");
return -EINVAL;
}
if (!tfo->write_pending_status) {
pr_err("Missing tfo->write_pending_status()\n");
return -EINVAL;
}
if (!tfo->set_default_node_attributes) {
pr_err("Missing tfo->set_default_node_attributes()\n");
return -EINVAL;
}
if (!tfo->get_cmd_state) {
pr_err("Missing tfo->get_cmd_state()\n");
return -EINVAL;
}
if (!tfo->queue_data_in) {
pr_err("Missing tfo->queue_data_in()\n");
return -EINVAL;
}
if (!tfo->queue_status) {
pr_err("Missing tfo->queue_status()\n");
return -EINVAL;
}
if (!tfo->queue_tm_rsp) {
pr_err("Missing tfo->queue_tm_rsp()\n");
return -EINVAL;
}
if (!tfo->aborted_task) {
pr_err("Missing tfo->aborted_task()\n");
return -EINVAL;
}
if (!tfo->fabric_make_wwn) {
pr_err("Missing tfo->fabric_make_wwn()\n");
return -EINVAL;
}
if (!tfo->fabric_drop_wwn) {
pr_err("Missing tfo->fabric_drop_wwn()\n");
return -EINVAL;
}
if (!tfo->fabric_make_tpg) {
pr_err("Missing tfo->fabric_make_tpg()\n");
return -EINVAL;
}
if (!tfo->fabric_drop_tpg) {
pr_err("Missing tfo->fabric_drop_tpg()\n");
return -EINVAL;
}
return 0;
}
int target_register_template(const struct target_core_fabric_ops *fo)
{
struct target_fabric_configfs *tf;
int ret;
ret = target_fabric_tf_ops_check(fo);
if (ret)
return ret;
tf = kzalloc(sizeof(struct target_fabric_configfs), GFP_KERNEL);
if (!tf) {
pr_err("%s: could not allocate memory!\n", __func__);
return -ENOMEM;
}
INIT_LIST_HEAD(&tf->tf_list);
atomic_set(&tf->tf_access_cnt, 0);
tf->tf_ops = fo;
target_fabric_setup_cits(tf);
mutex_lock(&g_tf_lock);
list_add_tail(&tf->tf_list, &g_tf_list);
mutex_unlock(&g_tf_lock);
return 0;
}
void target_unregister_template(const struct target_core_fabric_ops *fo)
{
struct target_fabric_configfs *t;
mutex_lock(&g_tf_lock);
list_for_each_entry(t, &g_tf_list, tf_list) {
if (!strcmp(t->tf_ops->name, fo->name)) {
BUG_ON(atomic_read(&t->tf_access_cnt));
list_del(&t->tf_list);
mutex_unlock(&g_tf_lock);
rcu_barrier();
kfree(t);
return;
}
}
mutex_unlock(&g_tf_lock);
}
static void dev_set_t10_wwn_model_alias(struct se_device *dev)
{
const char *configname;
configname = config_item_name(&dev->dev_group.cg_item);
if (strlen(configname) >= 16) {
pr_warn("dev[%p]: Backstore name '%s' is too long for "
"INQUIRY_MODEL, truncating to 16 bytes\n", dev,
configname);
}
snprintf(&dev->t10_wwn.model[0], 16, "%s", configname);
}
static ssize_t store_emulate_model_alias(struct se_dev_attrib *da,
const char *page, size_t count)
{
struct se_device *dev = da->da_dev;
bool flag;
int ret;
if (dev->export_count) {
pr_err("dev[%p]: Unable to change model alias"
" while export_count is %d\n",
dev, dev->export_count);
return -EINVAL;
}
ret = strtobool(page, &flag);
if (ret < 0)
return ret;
if (flag) {
dev_set_t10_wwn_model_alias(dev);
} else {
strncpy(&dev->t10_wwn.model[0],
dev->transport->inquiry_prod, 16);
}
da->emulate_model_alias = flag;
return count;
}
static ssize_t store_emulate_write_cache(struct se_dev_attrib *da,
const char *page, size_t count)
{
bool flag;
int ret;
ret = strtobool(page, &flag);
if (ret < 0)
return ret;
if (flag && da->da_dev->transport->get_write_cache) {
pr_err("emulate_write_cache not supported for this device\n");
return -EINVAL;
}
da->emulate_write_cache = flag;
pr_debug("dev[%p]: SE Device WRITE_CACHE_EMULATION flag: %d\n",
da->da_dev, flag);
return count;
}
static ssize_t store_emulate_ua_intlck_ctrl(struct se_dev_attrib *da,
const char *page, size_t count)
{
u32 val;
int ret;
ret = kstrtou32(page, 0, &val);
if (ret < 0)
return ret;
if (val != 0 && val != 1 && val != 2) {
pr_err("Illegal value %d\n", val);
return -EINVAL;
}
if (da->da_dev->export_count) {
pr_err("dev[%p]: Unable to change SE Device"
" UA_INTRLCK_CTRL while export_count is %d\n",
da->da_dev, da->da_dev->export_count);
return -EINVAL;
}
da->emulate_ua_intlck_ctrl = val;
pr_debug("dev[%p]: SE Device UA_INTRLCK_CTRL flag: %d\n",
da->da_dev, val);
return count;
}
static ssize_t store_emulate_tas(struct se_dev_attrib *da,
const char *page, size_t count)
{
bool flag;
int ret;
ret = strtobool(page, &flag);
if (ret < 0)
return ret;
if (da->da_dev->export_count) {
pr_err("dev[%p]: Unable to change SE Device TAS while"
" export_count is %d\n",
da->da_dev, da->da_dev->export_count);
return -EINVAL;
}
da->emulate_tas = flag;
pr_debug("dev[%p]: SE Device TASK_ABORTED status bit: %s\n",
da->da_dev, flag ? "Enabled" : "Disabled");
return count;
}
static ssize_t store_emulate_tpu(struct se_dev_attrib *da,
const char *page, size_t count)
{
bool flag;
int ret;
ret = strtobool(page, &flag);
if (ret < 0)
return ret;
if (flag && !da->max_unmap_block_desc_count) {
pr_err("Generic Block Discard not supported\n");
return -ENOSYS;
}
da->emulate_tpu = flag;
pr_debug("dev[%p]: SE Device Thin Provisioning UNMAP bit: %d\n",
da->da_dev, flag);
return count;
}
static ssize_t store_emulate_tpws(struct se_dev_attrib *da,
const char *page, size_t count)
{
bool flag;
int ret;
ret = strtobool(page, &flag);
if (ret < 0)
return ret;
if (flag && !da->max_unmap_block_desc_count) {
pr_err("Generic Block Discard not supported\n");
return -ENOSYS;
}
da->emulate_tpws = flag;
pr_debug("dev[%p]: SE Device Thin Provisioning WRITE_SAME: %d\n",
da->da_dev, flag);
return count;
}
static ssize_t store_pi_prot_type(struct se_dev_attrib *da,
const char *page, size_t count)
{
int old_prot = da->pi_prot_type, ret;
struct se_device *dev = da->da_dev;
u32 flag;
ret = kstrtou32(page, 0, &flag);
if (ret < 0)
return ret;
if (flag != 0 && flag != 1 && flag != 2 && flag != 3) {
pr_err("Illegal value %d for pi_prot_type\n", flag);
return -EINVAL;
}
if (flag == 2) {
pr_err("DIF TYPE2 protection currently not supported\n");
return -ENOSYS;
}
if (da->hw_pi_prot_type) {
pr_warn("DIF protection enabled on underlying hardware,"
" ignoring\n");
return count;
}
if (!dev->transport->init_prot || !dev->transport->free_prot) {
if (flag == 0)
return count;
pr_err("DIF protection not supported by backend: %s\n",
dev->transport->name);
return -ENOSYS;
}
if (!(dev->dev_flags & DF_CONFIGURED)) {
pr_err("DIF protection requires device to be configured\n");
return -ENODEV;
}
if (dev->export_count) {
pr_err("dev[%p]: Unable to change SE Device PROT type while"
" export_count is %d\n", dev, dev->export_count);
return -EINVAL;
}
da->pi_prot_type = flag;
if (flag && !old_prot) {
ret = dev->transport->init_prot(dev);
if (ret) {
da->pi_prot_type = old_prot;
return ret;
}
} else if (!flag && old_prot) {
dev->transport->free_prot(dev);
}
pr_debug("dev[%p]: SE Device Protection Type: %d\n", dev, flag);
return count;
}
static ssize_t store_pi_prot_format(struct se_dev_attrib *da,
const char *page, size_t count)
{
struct se_device *dev = da->da_dev;
bool flag;
int ret;
ret = strtobool(page, &flag);
if (ret < 0)
return ret;
if (!flag)
return count;
if (!dev->transport->format_prot) {
pr_err("DIF protection format not supported by backend %s\n",
dev->transport->name);
return -ENOSYS;
}
if (!(dev->dev_flags & DF_CONFIGURED)) {
pr_err("DIF protection format requires device to be configured\n");
return -ENODEV;
}
if (dev->export_count) {
pr_err("dev[%p]: Unable to format SE Device PROT type while"
" export_count is %d\n", dev, dev->export_count);
return -EINVAL;
}
ret = dev->transport->format_prot(dev);
if (ret)
return ret;
pr_debug("dev[%p]: SE Device Protection Format complete\n", dev);
return count;
}
static ssize_t store_force_pr_aptpl(struct se_dev_attrib *da,
const char *page, size_t count)
{
bool flag;
int ret;
ret = strtobool(page, &flag);
if (ret < 0)
return ret;
if (da->da_dev->export_count) {
pr_err("dev[%p]: Unable to set force_pr_aptpl while"
" export_count is %d\n",
da->da_dev, da->da_dev->export_count);
return -EINVAL;
}
da->force_pr_aptpl = flag;
pr_debug("dev[%p]: SE Device force_pr_aptpl: %d\n", da->da_dev, flag);
return count;
}
static ssize_t store_emulate_rest_reord(struct se_dev_attrib *da,
const char *page, size_t count)
{
bool flag;
int ret;
ret = strtobool(page, &flag);
if (ret < 0)
return ret;
if (flag != 0) {
printk(KERN_ERR "dev[%p]: SE Device emulation of restricted"
" reordering not implemented\n", da->da_dev);
return -ENOSYS;
}
da->emulate_rest_reord = flag;
pr_debug("dev[%p]: SE Device emulate_rest_reord: %d\n",
da->da_dev, flag);
return count;
}
static ssize_t store_queue_depth(struct se_dev_attrib *da,
const char *page, size_t count)
{
struct se_device *dev = da->da_dev;
u32 val;
int ret;
ret = kstrtou32(page, 0, &val);
if (ret < 0)
return ret;
if (dev->export_count) {
pr_err("dev[%p]: Unable to change SE Device TCQ while"
" export_count is %d\n",
dev, dev->export_count);
return -EINVAL;
}
if (!val) {
pr_err("dev[%p]: Illegal ZERO value for queue_depth\n", dev);
return -EINVAL;
}
if (val > dev->dev_attrib.queue_depth) {
if (val > dev->dev_attrib.hw_queue_depth) {
pr_err("dev[%p]: Passed queue_depth:"
" %u exceeds TCM/SE_Device MAX"
" TCQ: %u\n", dev, val,
dev->dev_attrib.hw_queue_depth);
return -EINVAL;
}
}
da->queue_depth = dev->queue_depth = val;
pr_debug("dev[%p]: SE Device TCQ Depth changed to: %u\n", dev, val);
return count;
}
static ssize_t store_optimal_sectors(struct se_dev_attrib *da,
const char *page, size_t count)
{
u32 val;
int ret;
ret = kstrtou32(page, 0, &val);
if (ret < 0)
return ret;
if (da->da_dev->export_count) {
pr_err("dev[%p]: Unable to change SE Device"
" optimal_sectors while export_count is %d\n",
da->da_dev, da->da_dev->export_count);
return -EINVAL;
}
if (val > da->hw_max_sectors) {
pr_err("dev[%p]: Passed optimal_sectors %u cannot be"
" greater than hw_max_sectors: %u\n",
da->da_dev, val, da->hw_max_sectors);
return -EINVAL;
}
da->optimal_sectors = val;
pr_debug("dev[%p]: SE Device optimal_sectors changed to %u\n",
da->da_dev, val);
return count;
}
static ssize_t store_block_size(struct se_dev_attrib *da,
const char *page, size_t count)
{
u32 val;
int ret;
ret = kstrtou32(page, 0, &val);
if (ret < 0)
return ret;
if (da->da_dev->export_count) {
pr_err("dev[%p]: Unable to change SE Device block_size"
" while export_count is %d\n",
da->da_dev, da->da_dev->export_count);
return -EINVAL;
}
if (val != 512 && val != 1024 && val != 2048 && val != 4096) {
pr_err("dev[%p]: Illegal value for block_device: %u"
" for SE device, must be 512, 1024, 2048 or 4096\n",
da->da_dev, val);
return -EINVAL;
}
da->block_size = val;
if (da->max_bytes_per_io)
da->hw_max_sectors = da->max_bytes_per_io / val;
pr_debug("dev[%p]: SE Device block_size changed to %u\n",
da->da_dev, val);
return count;
}
static ssize_t target_core_dev_wwn_show_attr_vpd_unit_serial(
struct t10_wwn *t10_wwn,
char *page)
{
return sprintf(page, "T10 VPD Unit Serial Number: %s\n",
&t10_wwn->unit_serial[0]);
}
static ssize_t target_core_dev_wwn_store_attr_vpd_unit_serial(
struct t10_wwn *t10_wwn,
const char *page,
size_t count)
{
struct se_device *dev = t10_wwn->t10_dev;
unsigned char buf[INQUIRY_VPD_SERIAL_LEN];
if (dev->dev_flags & DF_FIRMWARE_VPD_UNIT_SERIAL) {
pr_err("Underlying SCSI device firmware provided VPD"
" Unit Serial, ignoring request\n");
return -EOPNOTSUPP;
}
if (strlen(page) >= INQUIRY_VPD_SERIAL_LEN) {
pr_err("Emulated VPD Unit Serial exceeds"
" INQUIRY_VPD_SERIAL_LEN: %d\n", INQUIRY_VPD_SERIAL_LEN);
return -EOVERFLOW;
}
if (dev->export_count) {
pr_err("Unable to set VPD Unit Serial while"
" active %d $FABRIC_MOD exports exist\n",
dev->export_count);
return -EINVAL;
}
memset(buf, 0, INQUIRY_VPD_SERIAL_LEN);
snprintf(buf, INQUIRY_VPD_SERIAL_LEN, "%s", page);
snprintf(dev->t10_wwn.unit_serial, INQUIRY_VPD_SERIAL_LEN,
"%s", strstrip(buf));
dev->dev_flags |= DF_EMULATED_VPD_UNIT_SERIAL;
pr_debug("Target_Core_ConfigFS: Set emulated VPD Unit Serial:"
" %s\n", dev->t10_wwn.unit_serial);
return count;
}
static ssize_t target_core_dev_wwn_show_attr_vpd_protocol_identifier(
struct t10_wwn *t10_wwn,
char *page)
{
struct t10_vpd *vpd;
unsigned char buf[VPD_TMP_BUF_SIZE];
ssize_t len = 0;
memset(buf, 0, VPD_TMP_BUF_SIZE);
spin_lock(&t10_wwn->t10_vpd_lock);
list_for_each_entry(vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if (!vpd->protocol_identifier_set)
continue;
transport_dump_vpd_proto_id(vpd, buf, VPD_TMP_BUF_SIZE);
if (len + strlen(buf) >= PAGE_SIZE)
break;
len += sprintf(page+len, "%s", buf);
}
spin_unlock(&t10_wwn->t10_vpd_lock);
return len;
}
static ssize_t target_core_dev_wwn_store_attr_vpd_protocol_identifier(
struct t10_wwn *t10_wwn,
const char *page,
size_t count)
{
return -ENOSYS;
}
static ssize_t target_core_dev_wwn_store_attr_vpd_assoc_logical_unit(
struct t10_wwn *t10_wwn,
const char *page,
size_t count)
{
return -ENOSYS;
}
static ssize_t target_core_dev_wwn_store_attr_vpd_assoc_target_port(
struct t10_wwn *t10_wwn,
const char *page,
size_t count)
{
return -ENOSYS;
}
static ssize_t target_core_dev_wwn_store_attr_vpd_assoc_scsi_target_device(
struct t10_wwn *t10_wwn,
const char *page,
size_t count)
{
return -ENOSYS;
}
static ssize_t target_core_dev_pr_show_spc3_res(struct se_device *dev,
char *page)
{
struct se_node_acl *se_nacl;
struct t10_pr_registration *pr_reg;
char i_buf[PR_REG_ISID_ID_LEN];
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
pr_reg = dev->dev_pr_res_holder;
if (!pr_reg)
return sprintf(page, "No SPC-3 Reservation holder\n");
se_nacl = pr_reg->pr_reg_nacl;
core_pr_dump_initiator_port(pr_reg, i_buf, PR_REG_ISID_ID_LEN);
return sprintf(page, "SPC-3 Reservation: %s Initiator: %s%s\n",
se_nacl->se_tpg->se_tpg_tfo->get_fabric_name(),
se_nacl->initiatorname, i_buf);
}
static ssize_t target_core_dev_pr_show_spc2_res(struct se_device *dev,
char *page)
{
struct se_node_acl *se_nacl;
ssize_t len;
se_nacl = dev->dev_reserved_node_acl;
if (se_nacl) {
len = sprintf(page,
"SPC-2 Reservation: %s Initiator: %s\n",
se_nacl->se_tpg->se_tpg_tfo->get_fabric_name(),
se_nacl->initiatorname);
} else {
len = sprintf(page, "No SPC-2 Reservation holder\n");
}
return len;
}
static ssize_t target_core_dev_pr_show_attr_res_holder(struct se_device *dev,
char *page)
{
int ret;
if (dev->transport->transport_flags & TRANSPORT_FLAG_PASSTHROUGH)
return sprintf(page, "Passthrough\n");
spin_lock(&dev->dev_reservation_lock);
if (dev->dev_reservation_flags & DRF_SPC2_RESERVATIONS)
ret = target_core_dev_pr_show_spc2_res(dev, page);
else
ret = target_core_dev_pr_show_spc3_res(dev, page);
spin_unlock(&dev->dev_reservation_lock);
return ret;
}
static ssize_t target_core_dev_pr_show_attr_res_pr_all_tgt_pts(
struct se_device *dev, char *page)
{
ssize_t len = 0;
spin_lock(&dev->dev_reservation_lock);
if (!dev->dev_pr_res_holder) {
len = sprintf(page, "No SPC-3 Reservation holder\n");
} else if (dev->dev_pr_res_holder->pr_reg_all_tg_pt) {
len = sprintf(page, "SPC-3 Reservation: All Target"
" Ports registration\n");
} else {
len = sprintf(page, "SPC-3 Reservation: Single"
" Target Port registration\n");
}
spin_unlock(&dev->dev_reservation_lock);
return len;
}
static ssize_t target_core_dev_pr_show_attr_res_pr_generation(
struct se_device *dev, char *page)
{
return sprintf(page, "0x%08x\n", dev->t10_pr.pr_generation);
}
static ssize_t target_core_dev_pr_show_attr_res_pr_holder_tg_port(
struct se_device *dev, char *page)
{
struct se_node_acl *se_nacl;
struct se_portal_group *se_tpg;
struct t10_pr_registration *pr_reg;
const struct target_core_fabric_ops *tfo;
ssize_t len = 0;
spin_lock(&dev->dev_reservation_lock);
pr_reg = dev->dev_pr_res_holder;
if (!pr_reg) {
len = sprintf(page, "No SPC-3 Reservation holder\n");
goto out_unlock;
}
se_nacl = pr_reg->pr_reg_nacl;
se_tpg = se_nacl->se_tpg;
tfo = se_tpg->se_tpg_tfo;
len += sprintf(page+len, "SPC-3 Reservation: %s"
" Target Node Endpoint: %s\n", tfo->get_fabric_name(),
tfo->tpg_get_wwn(se_tpg));
len += sprintf(page+len, "SPC-3 Reservation: Relative Port"
" Identifier Tag: %hu %s Portal Group Tag: %hu"
" %s Logical Unit: %llu\n", pr_reg->tg_pt_sep_rtpi,
tfo->get_fabric_name(), tfo->tpg_get_tag(se_tpg),
tfo->get_fabric_name(), pr_reg->pr_aptpl_target_lun);
out_unlock:
spin_unlock(&dev->dev_reservation_lock);
return len;
}
static ssize_t target_core_dev_pr_show_attr_res_pr_registered_i_pts(
struct se_device *dev, char *page)
{
const struct target_core_fabric_ops *tfo;
struct t10_pr_registration *pr_reg;
unsigned char buf[384];
char i_buf[PR_REG_ISID_ID_LEN];
ssize_t len = 0;
int reg_count = 0;
len += sprintf(page+len, "SPC-3 PR Registrations:\n");
spin_lock(&dev->t10_pr.registration_lock);
list_for_each_entry(pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
memset(buf, 0, 384);
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
tfo = pr_reg->pr_reg_nacl->se_tpg->se_tpg_tfo;
core_pr_dump_initiator_port(pr_reg, i_buf,
PR_REG_ISID_ID_LEN);
sprintf(buf, "%s Node: %s%s Key: 0x%016Lx PRgen: 0x%08x\n",
tfo->get_fabric_name(),
pr_reg->pr_reg_nacl->initiatorname, i_buf, pr_reg->pr_res_key,
pr_reg->pr_res_generation);
if (len + strlen(buf) >= PAGE_SIZE)
break;
len += sprintf(page+len, "%s", buf);
reg_count++;
}
spin_unlock(&dev->t10_pr.registration_lock);
if (!reg_count)
len += sprintf(page+len, "None\n");
return len;
}
static ssize_t target_core_dev_pr_show_attr_res_pr_type(
struct se_device *dev, char *page)
{
struct t10_pr_registration *pr_reg;
ssize_t len = 0;
spin_lock(&dev->dev_reservation_lock);
pr_reg = dev->dev_pr_res_holder;
if (pr_reg) {
len = sprintf(page, "SPC-3 Reservation Type: %s\n",
core_scsi3_pr_dump_type(pr_reg->pr_res_type));
} else {
len = sprintf(page, "No SPC-3 Reservation holder\n");
}
spin_unlock(&dev->dev_reservation_lock);
return len;
}
static ssize_t target_core_dev_pr_show_attr_res_type(
struct se_device *dev, char *page)
{
if (dev->transport->transport_flags & TRANSPORT_FLAG_PASSTHROUGH)
return sprintf(page, "SPC_PASSTHROUGH\n");
else if (dev->dev_reservation_flags & DRF_SPC2_RESERVATIONS)
return sprintf(page, "SPC2_RESERVATIONS\n");
else
return sprintf(page, "SPC3_PERSISTENT_RESERVATIONS\n");
}
static ssize_t target_core_dev_pr_show_attr_res_aptpl_active(
struct se_device *dev, char *page)
{
if (dev->transport->transport_flags & TRANSPORT_FLAG_PASSTHROUGH)
return 0;
return sprintf(page, "APTPL Bit Status: %s\n",
(dev->t10_pr.pr_aptpl_active) ? "Activated" : "Disabled");
}
static ssize_t target_core_dev_pr_show_attr_res_aptpl_metadata(
struct se_device *dev, char *page)
{
if (dev->transport->transport_flags & TRANSPORT_FLAG_PASSTHROUGH)
return 0;
return sprintf(page, "Ready to process PR APTPL metadata..\n");
}
static ssize_t target_core_dev_pr_store_attr_res_aptpl_metadata(
struct se_device *dev,
const char *page,
size_t count)
{
unsigned char *i_fabric = NULL, *i_port = NULL, *isid = NULL;
unsigned char *t_fabric = NULL, *t_port = NULL;
char *orig, *ptr, *opts;
substring_t args[MAX_OPT_ARGS];
unsigned long long tmp_ll;
u64 sa_res_key = 0;
u64 mapped_lun = 0, target_lun = 0;
int ret = -1, res_holder = 0, all_tg_pt = 0, arg, token;
u16 tpgt = 0;
u8 type = 0;
if (dev->transport->transport_flags & TRANSPORT_FLAG_PASSTHROUGH)
return count;
if (dev->dev_reservation_flags & DRF_SPC2_RESERVATIONS)
return count;
if (dev->export_count) {
pr_debug("Unable to process APTPL metadata while"
" active fabric exports exist\n");
return -EINVAL;
}
opts = kstrdup(page, GFP_KERNEL);
if (!opts)
return -ENOMEM;
orig = opts;
while ((ptr = strsep(&opts, ",\n")) != NULL) {
if (!*ptr)
continue;
token = match_token(ptr, tokens, args);
switch (token) {
case Opt_initiator_fabric:
i_fabric = match_strdup(args);
if (!i_fabric) {
ret = -ENOMEM;
goto out;
}
break;
case Opt_initiator_node:
i_port = match_strdup(args);
if (!i_port) {
ret = -ENOMEM;
goto out;
}
if (strlen(i_port) >= PR_APTPL_MAX_IPORT_LEN) {
pr_err("APTPL metadata initiator_node="
" exceeds PR_APTPL_MAX_IPORT_LEN: %d\n",
PR_APTPL_MAX_IPORT_LEN);
ret = -EINVAL;
break;
}
break;
case Opt_initiator_sid:
isid = match_strdup(args);
if (!isid) {
ret = -ENOMEM;
goto out;
}
if (strlen(isid) >= PR_REG_ISID_LEN) {
pr_err("APTPL metadata initiator_isid"
"= exceeds PR_REG_ISID_LEN: %d\n",
PR_REG_ISID_LEN);
ret = -EINVAL;
break;
}
break;
case Opt_sa_res_key:
ret = kstrtoull(args->from, 0, &tmp_ll);
if (ret < 0) {
pr_err("kstrtoull() failed for sa_res_key=\n");
goto out;
}
sa_res_key = (u64)tmp_ll;
break;
case Opt_res_holder:
ret = match_int(args, &arg);
if (ret)
goto out;
res_holder = arg;
break;
case Opt_res_type:
ret = match_int(args, &arg);
if (ret)
goto out;
type = (u8)arg;
break;
case Opt_res_scope:
ret = match_int(args, &arg);
if (ret)
goto out;
break;
case Opt_res_all_tg_pt:
ret = match_int(args, &arg);
if (ret)
goto out;
all_tg_pt = (int)arg;
break;
case Opt_mapped_lun:
ret = match_int(args, &arg);
if (ret)
goto out;
mapped_lun = (u64)arg;
break;
case Opt_target_fabric:
t_fabric = match_strdup(args);
if (!t_fabric) {
ret = -ENOMEM;
goto out;
}
break;
case Opt_target_node:
t_port = match_strdup(args);
if (!t_port) {
ret = -ENOMEM;
goto out;
}
if (strlen(t_port) >= PR_APTPL_MAX_TPORT_LEN) {
pr_err("APTPL metadata target_node="
" exceeds PR_APTPL_MAX_TPORT_LEN: %d\n",
PR_APTPL_MAX_TPORT_LEN);
ret = -EINVAL;
break;
}
break;
case Opt_tpgt:
ret = match_int(args, &arg);
if (ret)
goto out;
tpgt = (u16)arg;
break;
case Opt_port_rtpi:
ret = match_int(args, &arg);
if (ret)
goto out;
break;
case Opt_target_lun:
ret = match_int(args, &arg);
if (ret)
goto out;
target_lun = (u64)arg;
break;
default:
break;
}
}
if (!i_port || !t_port || !sa_res_key) {
pr_err("Illegal parameters for APTPL registration\n");
ret = -EINVAL;
goto out;
}
if (res_holder && !(type)) {
pr_err("Illegal PR type: 0x%02x for reservation"
" holder\n", type);
ret = -EINVAL;
goto out;
}
ret = core_scsi3_alloc_aptpl_registration(&dev->t10_pr, sa_res_key,
i_port, isid, mapped_lun, t_port, tpgt, target_lun,
res_holder, all_tg_pt, type);
out:
kfree(i_fabric);
kfree(i_port);
kfree(isid);
kfree(t_fabric);
kfree(t_port);
kfree(orig);
return (ret == 0) ? count : ret;
}
static ssize_t target_core_show_dev_info(void *p, char *page)
{
struct se_device *dev = p;
int bl = 0;
ssize_t read_bytes = 0;
transport_dump_dev_state(dev, page, &bl);
read_bytes += bl;
read_bytes += dev->transport->show_configfs_dev_params(dev,
page+read_bytes);
return read_bytes;
}
static ssize_t target_core_store_dev_control(
void *p,
const char *page,
size_t count)
{
struct se_device *dev = p;
return dev->transport->set_configfs_dev_params(dev, page, count);
}
static ssize_t target_core_show_dev_alias(void *p, char *page)
{
struct se_device *dev = p;
if (!(dev->dev_flags & DF_USING_ALIAS))
return 0;
return snprintf(page, PAGE_SIZE, "%s\n", dev->dev_alias);
}
static ssize_t target_core_store_dev_alias(
void *p,
const char *page,
size_t count)
{
struct se_device *dev = p;
struct se_hba *hba = dev->se_hba;
ssize_t read_bytes;
if (count > (SE_DEV_ALIAS_LEN-1)) {
pr_err("alias count: %d exceeds"
" SE_DEV_ALIAS_LEN-1: %u\n", (int)count,
SE_DEV_ALIAS_LEN-1);
return -EINVAL;
}
read_bytes = snprintf(&dev->dev_alias[0], SE_DEV_ALIAS_LEN, "%s", page);
if (!read_bytes)
return -EINVAL;
if (dev->dev_alias[read_bytes - 1] == '\n')
dev->dev_alias[read_bytes - 1] = '\0';
dev->dev_flags |= DF_USING_ALIAS;
pr_debug("Target_Core_ConfigFS: %s/%s set alias: %s\n",
config_item_name(&hba->hba_group.cg_item),
config_item_name(&dev->dev_group.cg_item),
dev->dev_alias);
return read_bytes;
}
static ssize_t target_core_show_dev_udev_path(void *p, char *page)
{
struct se_device *dev = p;
if (!(dev->dev_flags & DF_USING_UDEV_PATH))
return 0;
return snprintf(page, PAGE_SIZE, "%s\n", dev->udev_path);
}
static ssize_t target_core_store_dev_udev_path(
void *p,
const char *page,
size_t count)
{
struct se_device *dev = p;
struct se_hba *hba = dev->se_hba;
ssize_t read_bytes;
if (count > (SE_UDEV_PATH_LEN-1)) {
pr_err("udev_path count: %d exceeds"
" SE_UDEV_PATH_LEN-1: %u\n", (int)count,
SE_UDEV_PATH_LEN-1);
return -EINVAL;
}
read_bytes = snprintf(&dev->udev_path[0], SE_UDEV_PATH_LEN,
"%s", page);
if (!read_bytes)
return -EINVAL;
if (dev->udev_path[read_bytes - 1] == '\n')
dev->udev_path[read_bytes - 1] = '\0';
dev->dev_flags |= DF_USING_UDEV_PATH;
pr_debug("Target_Core_ConfigFS: %s/%s set udev_path: %s\n",
config_item_name(&hba->hba_group.cg_item),
config_item_name(&dev->dev_group.cg_item),
dev->udev_path);
return read_bytes;
}
static ssize_t target_core_show_dev_enable(void *p, char *page)
{
struct se_device *dev = p;
return snprintf(page, PAGE_SIZE, "%d\n", !!(dev->dev_flags & DF_CONFIGURED));
}
static ssize_t target_core_store_dev_enable(
void *p,
const char *page,
size_t count)
{
struct se_device *dev = p;
char *ptr;
int ret;
ptr = strstr(page, "1");
if (!ptr) {
pr_err("For dev_enable ops, only valid value"
" is \"1\"\n");
return -EINVAL;
}
ret = target_configure_device(dev);
if (ret)
return ret;
return count;
}
static ssize_t target_core_show_alua_lu_gp(void *p, char *page)
{
struct se_device *dev = p;
struct config_item *lu_ci;
struct t10_alua_lu_gp *lu_gp;
struct t10_alua_lu_gp_member *lu_gp_mem;
ssize_t len = 0;
lu_gp_mem = dev->dev_alua_lu_gp_mem;
if (!lu_gp_mem)
return 0;
spin_lock(&lu_gp_mem->lu_gp_mem_lock);
lu_gp = lu_gp_mem->lu_gp;
if (lu_gp) {
lu_ci = &lu_gp->lu_gp_group.cg_item;
len += sprintf(page, "LU Group Alias: %s\nLU Group ID: %hu\n",
config_item_name(lu_ci), lu_gp->lu_gp_id);
}
spin_unlock(&lu_gp_mem->lu_gp_mem_lock);
return len;
}
static ssize_t target_core_store_alua_lu_gp(
void *p,
const char *page,
size_t count)
{
struct se_device *dev = p;
struct se_hba *hba = dev->se_hba;
struct t10_alua_lu_gp *lu_gp = NULL, *lu_gp_new = NULL;
struct t10_alua_lu_gp_member *lu_gp_mem;
unsigned char buf[LU_GROUP_NAME_BUF];
int move = 0;
lu_gp_mem = dev->dev_alua_lu_gp_mem;
if (!lu_gp_mem)
return count;
if (count > LU_GROUP_NAME_BUF) {
pr_err("ALUA LU Group Alias too large!\n");
return -EINVAL;
}
memset(buf, 0, LU_GROUP_NAME_BUF);
memcpy(buf, page, count);
if (strcmp(strstrip(buf), "NULL")) {
lu_gp_new = core_alua_get_lu_gp_by_name(strstrip(buf));
if (!lu_gp_new)
return -ENODEV;
}
spin_lock(&lu_gp_mem->lu_gp_mem_lock);
lu_gp = lu_gp_mem->lu_gp;
if (lu_gp) {
if (!lu_gp_new) {
pr_debug("Target_Core_ConfigFS: Releasing %s/%s"
" from ALUA LU Group: core/alua/lu_gps/%s, ID:"
" %hu\n",
config_item_name(&hba->hba_group.cg_item),
config_item_name(&dev->dev_group.cg_item),
config_item_name(&lu_gp->lu_gp_group.cg_item),
lu_gp->lu_gp_id);
__core_alua_drop_lu_gp_mem(lu_gp_mem, lu_gp);
spin_unlock(&lu_gp_mem->lu_gp_mem_lock);
return count;
}
__core_alua_drop_lu_gp_mem(lu_gp_mem, lu_gp);
move = 1;
}
__core_alua_attach_lu_gp_mem(lu_gp_mem, lu_gp_new);
spin_unlock(&lu_gp_mem->lu_gp_mem_lock);
pr_debug("Target_Core_ConfigFS: %s %s/%s to ALUA LU Group:"
" core/alua/lu_gps/%s, ID: %hu\n",
(move) ? "Moving" : "Adding",
config_item_name(&hba->hba_group.cg_item),
config_item_name(&dev->dev_group.cg_item),
config_item_name(&lu_gp_new->lu_gp_group.cg_item),
lu_gp_new->lu_gp_id);
core_alua_put_lu_gp_from_name(lu_gp_new);
return count;
}
static ssize_t target_core_show_dev_lba_map(void *p, char *page)
{
struct se_device *dev = p;
struct t10_alua_lba_map *map;
struct t10_alua_lba_map_member *mem;
char *b = page;
int bl = 0;
char state;
spin_lock(&dev->t10_alua.lba_map_lock);
if (!list_empty(&dev->t10_alua.lba_map_list))
bl += sprintf(b + bl, "%u %u\n",
dev->t10_alua.lba_map_segment_size,
dev->t10_alua.lba_map_segment_multiplier);
list_for_each_entry(map, &dev->t10_alua.lba_map_list, lba_map_list) {
bl += sprintf(b + bl, "%llu %llu",
map->lba_map_first_lba, map->lba_map_last_lba);
list_for_each_entry(mem, &map->lba_map_mem_list,
lba_map_mem_list) {
switch (mem->lba_map_mem_alua_state) {
case ALUA_ACCESS_STATE_ACTIVE_OPTIMIZED:
state = 'O';
break;
case ALUA_ACCESS_STATE_ACTIVE_NON_OPTIMIZED:
state = 'A';
break;
case ALUA_ACCESS_STATE_STANDBY:
state = 'S';
break;
case ALUA_ACCESS_STATE_UNAVAILABLE:
state = 'U';
break;
default:
state = '.';
break;
}
bl += sprintf(b + bl, " %d:%c",
mem->lba_map_mem_alua_pg_id, state);
}
bl += sprintf(b + bl, "\n");
}
spin_unlock(&dev->t10_alua.lba_map_lock);
return bl;
}
static ssize_t target_core_store_dev_lba_map(
void *p,
const char *page,
size_t count)
{
struct se_device *dev = p;
struct t10_alua_lba_map *lba_map = NULL;
struct list_head lba_list;
char *map_entries, *ptr;
char state;
int pg_num = -1, pg;
int ret = 0, num = 0, pg_id, alua_state;
unsigned long start_lba = -1, end_lba = -1;
unsigned long segment_size = -1, segment_mult = -1;
map_entries = kstrdup(page, GFP_KERNEL);
if (!map_entries)
return -ENOMEM;
INIT_LIST_HEAD(&lba_list);
while ((ptr = strsep(&map_entries, "\n")) != NULL) {
if (!*ptr)
continue;
if (num == 0) {
if (sscanf(ptr, "%lu %lu\n",
&segment_size, &segment_mult) != 2) {
pr_err("Invalid line %d\n", num);
ret = -EINVAL;
break;
}
num++;
continue;
}
if (sscanf(ptr, "%lu %lu", &start_lba, &end_lba) != 2) {
pr_err("Invalid line %d\n", num);
ret = -EINVAL;
break;
}
ptr = strchr(ptr, ' ');
if (!ptr) {
pr_err("Invalid line %d, missing end lba\n", num);
ret = -EINVAL;
break;
}
ptr++;
ptr = strchr(ptr, ' ');
if (!ptr) {
pr_err("Invalid line %d, missing state definitions\n",
num);
ret = -EINVAL;
break;
}
ptr++;
lba_map = core_alua_allocate_lba_map(&lba_list,
start_lba, end_lba);
if (IS_ERR(lba_map)) {
ret = PTR_ERR(lba_map);
break;
}
pg = 0;
while (sscanf(ptr, "%d:%c", &pg_id, &state) == 2) {
switch (state) {
case 'O':
alua_state = ALUA_ACCESS_STATE_ACTIVE_OPTIMIZED;
break;
case 'A':
alua_state = ALUA_ACCESS_STATE_ACTIVE_NON_OPTIMIZED;
break;
case 'S':
alua_state = ALUA_ACCESS_STATE_STANDBY;
break;
case 'U':
alua_state = ALUA_ACCESS_STATE_UNAVAILABLE;
break;
default:
pr_err("Invalid ALUA state '%c'\n", state);
ret = -EINVAL;
goto out;
}
ret = core_alua_allocate_lba_map_mem(lba_map,
pg_id, alua_state);
if (ret) {
pr_err("Invalid target descriptor %d:%c "
"at line %d\n",
pg_id, state, num);
break;
}
pg++;
ptr = strchr(ptr, ' ');
if (ptr)
ptr++;
else
break;
}
if (pg_num == -1)
pg_num = pg;
else if (pg != pg_num) {
pr_err("Only %d from %d port groups definitions "
"at line %d\n", pg, pg_num, num);
ret = -EINVAL;
break;
}
num++;
}
out:
if (ret) {
core_alua_free_lba_map(&lba_list);
count = ret;
} else
core_alua_set_lba_map(dev, &lba_list,
segment_size, segment_mult);
kfree(map_entries);
return count;
}
static void target_core_dev_release(struct config_item *item)
{
struct config_group *dev_cg = to_config_group(item);
struct se_device *dev =
container_of(dev_cg, struct se_device, dev_group);
kfree(dev_cg->default_groups);
target_free_device(dev);
}
static ssize_t target_core_dev_show(struct config_item *item,
struct configfs_attribute *attr,
char *page)
{
struct config_group *dev_cg = to_config_group(item);
struct se_device *dev =
container_of(dev_cg, struct se_device, dev_group);
struct target_core_configfs_attribute *tc_attr = container_of(
attr, struct target_core_configfs_attribute, attr);
if (!tc_attr->show)
return -EINVAL;
return tc_attr->show(dev, page);
}
static ssize_t target_core_dev_store(struct config_item *item,
struct configfs_attribute *attr,
const char *page, size_t count)
{
struct config_group *dev_cg = to_config_group(item);
struct se_device *dev =
container_of(dev_cg, struct se_device, dev_group);
struct target_core_configfs_attribute *tc_attr = container_of(
attr, struct target_core_configfs_attribute, attr);
if (!tc_attr->store)
return -EINVAL;
return tc_attr->store(dev, page, count);
}
static ssize_t target_core_alua_lu_gp_show_attr_lu_gp_id(
struct t10_alua_lu_gp *lu_gp,
char *page)
{
if (!lu_gp->lu_gp_valid_id)
return 0;
return sprintf(page, "%hu\n", lu_gp->lu_gp_id);
}
static ssize_t target_core_alua_lu_gp_store_attr_lu_gp_id(
struct t10_alua_lu_gp *lu_gp,
const char *page,
size_t count)
{
struct config_group *alua_lu_gp_cg = &lu_gp->lu_gp_group;
unsigned long lu_gp_id;
int ret;
ret = kstrtoul(page, 0, &lu_gp_id);
if (ret < 0) {
pr_err("kstrtoul() returned %d for"
" lu_gp_id\n", ret);
return ret;
}
if (lu_gp_id > 0x0000ffff) {
pr_err("ALUA lu_gp_id: %lu exceeds maximum:"
" 0x0000ffff\n", lu_gp_id);
return -EINVAL;
}
ret = core_alua_set_lu_gp_id(lu_gp, (u16)lu_gp_id);
if (ret < 0)
return -EINVAL;
pr_debug("Target_Core_ConfigFS: Set ALUA Logical Unit"
" Group: core/alua/lu_gps/%s to ID: %hu\n",
config_item_name(&alua_lu_gp_cg->cg_item),
lu_gp->lu_gp_id);
return count;
}
static ssize_t target_core_alua_lu_gp_show_attr_members(
struct t10_alua_lu_gp *lu_gp,
char *page)
{
struct se_device *dev;
struct se_hba *hba;
struct t10_alua_lu_gp_member *lu_gp_mem;
ssize_t len = 0, cur_len;
unsigned char buf[LU_GROUP_NAME_BUF];
memset(buf, 0, LU_GROUP_NAME_BUF);
spin_lock(&lu_gp->lu_gp_lock);
list_for_each_entry(lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
dev = lu_gp_mem->lu_gp_mem_dev;
hba = dev->se_hba;
cur_len = snprintf(buf, LU_GROUP_NAME_BUF, "%s/%s\n",
config_item_name(&hba->hba_group.cg_item),
config_item_name(&dev->dev_group.cg_item));
cur_len++;
if ((cur_len + len) > PAGE_SIZE) {
pr_warn("Ran out of lu_gp_show_attr"
"_members buffer\n");
break;
}
memcpy(page+len, buf, cur_len);
len += cur_len;
}
spin_unlock(&lu_gp->lu_gp_lock);
return len;
}
static void target_core_alua_lu_gp_release(struct config_item *item)
{
struct t10_alua_lu_gp *lu_gp = container_of(to_config_group(item),
struct t10_alua_lu_gp, lu_gp_group);
core_alua_free_lu_gp(lu_gp);
}
static struct config_group *target_core_alua_create_lu_gp(
struct config_group *group,
const char *name)
{
struct t10_alua_lu_gp *lu_gp;
struct config_group *alua_lu_gp_cg = NULL;
struct config_item *alua_lu_gp_ci = NULL;
lu_gp = core_alua_allocate_lu_gp(name, 0);
if (IS_ERR(lu_gp))
return NULL;
alua_lu_gp_cg = &lu_gp->lu_gp_group;
alua_lu_gp_ci = &alua_lu_gp_cg->cg_item;
config_group_init_type_name(alua_lu_gp_cg, name,
&target_core_alua_lu_gp_cit);
pr_debug("Target_Core_ConfigFS: Allocated ALUA Logical Unit"
" Group: core/alua/lu_gps/%s\n",
config_item_name(alua_lu_gp_ci));
return alua_lu_gp_cg;
}
static void target_core_alua_drop_lu_gp(
struct config_group *group,
struct config_item *item)
{
struct t10_alua_lu_gp *lu_gp = container_of(to_config_group(item),
struct t10_alua_lu_gp, lu_gp_group);
pr_debug("Target_Core_ConfigFS: Releasing ALUA Logical Unit"
" Group: core/alua/lu_gps/%s, ID: %hu\n",
config_item_name(item), lu_gp->lu_gp_id);
config_item_put(item);
}
static ssize_t target_core_alua_tg_pt_gp_show_attr_alua_access_state(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
return sprintf(page, "%d\n",
atomic_read(&tg_pt_gp->tg_pt_gp_alua_access_state));
}
static ssize_t target_core_alua_tg_pt_gp_store_attr_alua_access_state(
struct t10_alua_tg_pt_gp *tg_pt_gp,
const char *page,
size_t count)
{
struct se_device *dev = tg_pt_gp->tg_pt_gp_dev;
unsigned long tmp;
int new_state, ret;
if (!tg_pt_gp->tg_pt_gp_valid_id) {
pr_err("Unable to do implicit ALUA on non valid"
" tg_pt_gp ID: %hu\n", tg_pt_gp->tg_pt_gp_valid_id);
return -EINVAL;
}
if (!(dev->dev_flags & DF_CONFIGURED)) {
pr_err("Unable to set alua_access_state while device is"
" not configured\n");
return -ENODEV;
}
ret = kstrtoul(page, 0, &tmp);
if (ret < 0) {
pr_err("Unable to extract new ALUA access state from"
" %s\n", page);
return ret;
}
new_state = (int)tmp;
if (!(tg_pt_gp->tg_pt_gp_alua_access_type & TPGS_IMPLICIT_ALUA)) {
pr_err("Unable to process implicit configfs ALUA"
" transition while TPGS_IMPLICIT_ALUA is disabled\n");
return -EINVAL;
}
if (tg_pt_gp->tg_pt_gp_alua_access_type & TPGS_EXPLICIT_ALUA &&
new_state == ALUA_ACCESS_STATE_LBA_DEPENDENT) {
pr_err("Unable to process implicit configfs ALUA transition"
" while explicit ALUA management is enabled\n");
return -EINVAL;
}
ret = core_alua_do_port_transition(tg_pt_gp, dev,
NULL, NULL, new_state, 0);
return (!ret) ? count : -EINVAL;
}
static ssize_t target_core_alua_tg_pt_gp_show_attr_alua_access_status(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
return sprintf(page, "%s\n",
core_alua_dump_status(tg_pt_gp->tg_pt_gp_alua_access_status));
}
static ssize_t target_core_alua_tg_pt_gp_store_attr_alua_access_status(
struct t10_alua_tg_pt_gp *tg_pt_gp,
const char *page,
size_t count)
{
unsigned long tmp;
int new_status, ret;
if (!tg_pt_gp->tg_pt_gp_valid_id) {
pr_err("Unable to do set ALUA access status on non"
" valid tg_pt_gp ID: %hu\n",
tg_pt_gp->tg_pt_gp_valid_id);
return -EINVAL;
}
ret = kstrtoul(page, 0, &tmp);
if (ret < 0) {
pr_err("Unable to extract new ALUA access status"
" from %s\n", page);
return ret;
}
new_status = (int)tmp;
if ((new_status != ALUA_STATUS_NONE) &&
(new_status != ALUA_STATUS_ALTERED_BY_EXPLICIT_STPG) &&
(new_status != ALUA_STATUS_ALTERED_BY_IMPLICIT_ALUA)) {
pr_err("Illegal ALUA access status: 0x%02x\n",
new_status);
return -EINVAL;
}
tg_pt_gp->tg_pt_gp_alua_access_status = new_status;
return count;
}
static ssize_t target_core_alua_tg_pt_gp_show_attr_alua_access_type(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
return core_alua_show_access_type(tg_pt_gp, page);
}
static ssize_t target_core_alua_tg_pt_gp_store_attr_alua_access_type(
struct t10_alua_tg_pt_gp *tg_pt_gp,
const char *page,
size_t count)
{
return core_alua_store_access_type(tg_pt_gp, page, count);
}
static ssize_t target_core_alua_tg_pt_gp_show_attr_alua_write_metadata(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
return sprintf(page, "%d\n", tg_pt_gp->tg_pt_gp_write_metadata);
}
static ssize_t target_core_alua_tg_pt_gp_store_attr_alua_write_metadata(
struct t10_alua_tg_pt_gp *tg_pt_gp,
const char *page,
size_t count)
{
unsigned long tmp;
int ret;
ret = kstrtoul(page, 0, &tmp);
if (ret < 0) {
pr_err("Unable to extract alua_write_metadata\n");
return ret;
}
if ((tmp != 0) && (tmp != 1)) {
pr_err("Illegal value for alua_write_metadata:"
" %lu\n", tmp);
return -EINVAL;
}
tg_pt_gp->tg_pt_gp_write_metadata = (int)tmp;
return count;
}
static ssize_t target_core_alua_tg_pt_gp_show_attr_nonop_delay_msecs(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
return core_alua_show_nonop_delay_msecs(tg_pt_gp, page);
}
static ssize_t target_core_alua_tg_pt_gp_store_attr_nonop_delay_msecs(
struct t10_alua_tg_pt_gp *tg_pt_gp,
const char *page,
size_t count)
{
return core_alua_store_nonop_delay_msecs(tg_pt_gp, page, count);
}
static ssize_t target_core_alua_tg_pt_gp_show_attr_trans_delay_msecs(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
return core_alua_show_trans_delay_msecs(tg_pt_gp, page);
}
static ssize_t target_core_alua_tg_pt_gp_store_attr_trans_delay_msecs(
struct t10_alua_tg_pt_gp *tg_pt_gp,
const char *page,
size_t count)
{
return core_alua_store_trans_delay_msecs(tg_pt_gp, page, count);
}
static ssize_t target_core_alua_tg_pt_gp_show_attr_implicit_trans_secs(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
return core_alua_show_implicit_trans_secs(tg_pt_gp, page);
}
static ssize_t target_core_alua_tg_pt_gp_store_attr_implicit_trans_secs(
struct t10_alua_tg_pt_gp *tg_pt_gp,
const char *page,
size_t count)
{
return core_alua_store_implicit_trans_secs(tg_pt_gp, page, count);
}
static ssize_t target_core_alua_tg_pt_gp_show_attr_preferred(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
return core_alua_show_preferred_bit(tg_pt_gp, page);
}
static ssize_t target_core_alua_tg_pt_gp_store_attr_preferred(
struct t10_alua_tg_pt_gp *tg_pt_gp,
const char *page,
size_t count)
{
return core_alua_store_preferred_bit(tg_pt_gp, page, count);
}
static ssize_t target_core_alua_tg_pt_gp_show_attr_tg_pt_gp_id(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
if (!tg_pt_gp->tg_pt_gp_valid_id)
return 0;
return sprintf(page, "%hu\n", tg_pt_gp->tg_pt_gp_id);
}
static ssize_t target_core_alua_tg_pt_gp_store_attr_tg_pt_gp_id(
struct t10_alua_tg_pt_gp *tg_pt_gp,
const char *page,
size_t count)
{
struct config_group *alua_tg_pt_gp_cg = &tg_pt_gp->tg_pt_gp_group;
unsigned long tg_pt_gp_id;
int ret;
ret = kstrtoul(page, 0, &tg_pt_gp_id);
if (ret < 0) {
pr_err("kstrtoul() returned %d for"
" tg_pt_gp_id\n", ret);
return ret;
}
if (tg_pt_gp_id > 0x0000ffff) {
pr_err("ALUA tg_pt_gp_id: %lu exceeds maximum:"
" 0x0000ffff\n", tg_pt_gp_id);
return -EINVAL;
}
ret = core_alua_set_tg_pt_gp_id(tg_pt_gp, (u16)tg_pt_gp_id);
if (ret < 0)
return -EINVAL;
pr_debug("Target_Core_ConfigFS: Set ALUA Target Port Group: "
"core/alua/tg_pt_gps/%s to ID: %hu\n",
config_item_name(&alua_tg_pt_gp_cg->cg_item),
tg_pt_gp->tg_pt_gp_id);
return count;
}
static ssize_t target_core_alua_tg_pt_gp_show_attr_members(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
struct se_lun *lun;
ssize_t len = 0, cur_len;
unsigned char buf[TG_PT_GROUP_NAME_BUF];
memset(buf, 0, TG_PT_GROUP_NAME_BUF);
spin_lock(&tg_pt_gp->tg_pt_gp_lock);
list_for_each_entry(lun, &tg_pt_gp->tg_pt_gp_lun_list,
lun_tg_pt_gp_link) {
struct se_portal_group *tpg = lun->lun_tpg;
cur_len = snprintf(buf, TG_PT_GROUP_NAME_BUF, "%s/%s/tpgt_%hu"
"/%s\n", tpg->se_tpg_tfo->get_fabric_name(),
tpg->se_tpg_tfo->tpg_get_wwn(tpg),
tpg->se_tpg_tfo->tpg_get_tag(tpg),
config_item_name(&lun->lun_group.cg_item));
cur_len++;
if ((cur_len + len) > PAGE_SIZE) {
pr_warn("Ran out of lu_gp_show_attr"
"_members buffer\n");
break;
}
memcpy(page+len, buf, cur_len);
len += cur_len;
}
spin_unlock(&tg_pt_gp->tg_pt_gp_lock);
return len;
}
static void target_core_alua_tg_pt_gp_release(struct config_item *item)
{
struct t10_alua_tg_pt_gp *tg_pt_gp = container_of(to_config_group(item),
struct t10_alua_tg_pt_gp, tg_pt_gp_group);
core_alua_free_tg_pt_gp(tg_pt_gp);
}
static struct config_group *target_core_alua_create_tg_pt_gp(
struct config_group *group,
const char *name)
{
struct t10_alua *alua = container_of(group, struct t10_alua,
alua_tg_pt_gps_group);
struct t10_alua_tg_pt_gp *tg_pt_gp;
struct config_group *alua_tg_pt_gp_cg = NULL;
struct config_item *alua_tg_pt_gp_ci = NULL;
tg_pt_gp = core_alua_allocate_tg_pt_gp(alua->t10_dev, name, 0);
if (!tg_pt_gp)
return NULL;
alua_tg_pt_gp_cg = &tg_pt_gp->tg_pt_gp_group;
alua_tg_pt_gp_ci = &alua_tg_pt_gp_cg->cg_item;
config_group_init_type_name(alua_tg_pt_gp_cg, name,
&target_core_alua_tg_pt_gp_cit);
pr_debug("Target_Core_ConfigFS: Allocated ALUA Target Port"
" Group: alua/tg_pt_gps/%s\n",
config_item_name(alua_tg_pt_gp_ci));
return alua_tg_pt_gp_cg;
}
static void target_core_alua_drop_tg_pt_gp(
struct config_group *group,
struct config_item *item)
{
struct t10_alua_tg_pt_gp *tg_pt_gp = container_of(to_config_group(item),
struct t10_alua_tg_pt_gp, tg_pt_gp_group);
pr_debug("Target_Core_ConfigFS: Releasing ALUA Target Port"
" Group: alua/tg_pt_gps/%s, ID: %hu\n",
config_item_name(item), tg_pt_gp->tg_pt_gp_id);
config_item_put(item);
}
static struct config_group *target_core_stat_mkdir(
struct config_group *group,
const char *name)
{
return ERR_PTR(-ENOSYS);
}
static void target_core_stat_rmdir(
struct config_group *group,
struct config_item *item)
{
return;
}
static struct config_group *target_core_make_subdev(
struct config_group *group,
const char *name)
{
struct t10_alua_tg_pt_gp *tg_pt_gp;
struct config_item *hba_ci = &group->cg_item;
struct se_hba *hba = item_to_hba(hba_ci);
struct target_backend *tb = hba->backend;
struct se_device *dev;
struct config_group *dev_cg = NULL, *tg_pt_gp_cg = NULL;
struct config_group *dev_stat_grp = NULL;
int errno = -ENOMEM, ret;
ret = mutex_lock_interruptible(&hba->hba_access_mutex);
if (ret)
return ERR_PTR(ret);
dev = target_alloc_device(hba, name);
if (!dev)
goto out_unlock;
dev_cg = &dev->dev_group;
dev_cg->default_groups = kmalloc(sizeof(struct config_group *) * 6,
GFP_KERNEL);
if (!dev_cg->default_groups)
goto out_free_device;
config_group_init_type_name(dev_cg, name, &tb->tb_dev_cit);
config_group_init_type_name(&dev->dev_attrib.da_group, "attrib",
&tb->tb_dev_attrib_cit);
config_group_init_type_name(&dev->dev_pr_group, "pr",
&tb->tb_dev_pr_cit);
config_group_init_type_name(&dev->t10_wwn.t10_wwn_group, "wwn",
&tb->tb_dev_wwn_cit);
config_group_init_type_name(&dev->t10_alua.alua_tg_pt_gps_group,
"alua", &tb->tb_dev_alua_tg_pt_gps_cit);
config_group_init_type_name(&dev->dev_stat_grps.stat_group,
"statistics", &tb->tb_dev_stat_cit);
dev_cg->default_groups[0] = &dev->dev_attrib.da_group;
dev_cg->default_groups[1] = &dev->dev_pr_group;
dev_cg->default_groups[2] = &dev->t10_wwn.t10_wwn_group;
dev_cg->default_groups[3] = &dev->t10_alua.alua_tg_pt_gps_group;
dev_cg->default_groups[4] = &dev->dev_stat_grps.stat_group;
dev_cg->default_groups[5] = NULL;
tg_pt_gp = core_alua_allocate_tg_pt_gp(dev, "default_tg_pt_gp", 1);
if (!tg_pt_gp)
goto out_free_dev_cg_default_groups;
dev->t10_alua.default_tg_pt_gp = tg_pt_gp;
tg_pt_gp_cg = &dev->t10_alua.alua_tg_pt_gps_group;
tg_pt_gp_cg->default_groups = kmalloc(sizeof(struct config_group *) * 2,
GFP_KERNEL);
if (!tg_pt_gp_cg->default_groups) {
pr_err("Unable to allocate tg_pt_gp_cg->"
"default_groups\n");
goto out_free_tg_pt_gp;
}
config_group_init_type_name(&tg_pt_gp->tg_pt_gp_group,
"default_tg_pt_gp", &target_core_alua_tg_pt_gp_cit);
tg_pt_gp_cg->default_groups[0] = &tg_pt_gp->tg_pt_gp_group;
tg_pt_gp_cg->default_groups[1] = NULL;
dev_stat_grp = &dev->dev_stat_grps.stat_group;
dev_stat_grp->default_groups = kmalloc(sizeof(struct config_group *) * 4,
GFP_KERNEL);
if (!dev_stat_grp->default_groups) {
pr_err("Unable to allocate dev_stat_grp->default_groups\n");
goto out_free_tg_pt_gp_cg_default_groups;
}
target_stat_setup_dev_default_groups(dev);
mutex_unlock(&hba->hba_access_mutex);
return dev_cg;
out_free_tg_pt_gp_cg_default_groups:
kfree(tg_pt_gp_cg->default_groups);
out_free_tg_pt_gp:
core_alua_free_tg_pt_gp(tg_pt_gp);
out_free_dev_cg_default_groups:
kfree(dev_cg->default_groups);
out_free_device:
target_free_device(dev);
out_unlock:
mutex_unlock(&hba->hba_access_mutex);
return ERR_PTR(errno);
}
static void target_core_drop_subdev(
struct config_group *group,
struct config_item *item)
{
struct config_group *dev_cg = to_config_group(item);
struct se_device *dev =
container_of(dev_cg, struct se_device, dev_group);
struct se_hba *hba;
struct config_item *df_item;
struct config_group *tg_pt_gp_cg, *dev_stat_grp;
int i;
hba = item_to_hba(&dev->se_hba->hba_group.cg_item);
mutex_lock(&hba->hba_access_mutex);
dev_stat_grp = &dev->dev_stat_grps.stat_group;
for (i = 0; dev_stat_grp->default_groups[i]; i++) {
df_item = &dev_stat_grp->default_groups[i]->cg_item;
dev_stat_grp->default_groups[i] = NULL;
config_item_put(df_item);
}
kfree(dev_stat_grp->default_groups);
tg_pt_gp_cg = &dev->t10_alua.alua_tg_pt_gps_group;
for (i = 0; tg_pt_gp_cg->default_groups[i]; i++) {
df_item = &tg_pt_gp_cg->default_groups[i]->cg_item;
tg_pt_gp_cg->default_groups[i] = NULL;
config_item_put(df_item);
}
kfree(tg_pt_gp_cg->default_groups);
dev->t10_alua.default_tg_pt_gp = NULL;
for (i = 0; dev_cg->default_groups[i]; i++) {
df_item = &dev_cg->default_groups[i]->cg_item;
dev_cg->default_groups[i] = NULL;
config_item_put(df_item);
}
config_item_put(item);
mutex_unlock(&hba->hba_access_mutex);
}
static ssize_t target_core_hba_show_attr_hba_info(
struct se_hba *hba,
char *page)
{
return sprintf(page, "HBA Index: %d plugin: %s version: %s\n",
hba->hba_id, hba->backend->ops->name,
TARGET_CORE_VERSION);
}
static ssize_t target_core_hba_show_attr_hba_mode(struct se_hba *hba,
char *page)
{
int hba_mode = 0;
if (hba->hba_flags & HBA_FLAGS_PSCSI_MODE)
hba_mode = 1;
return sprintf(page, "%d\n", hba_mode);
}
static ssize_t target_core_hba_store_attr_hba_mode(struct se_hba *hba,
const char *page, size_t count)
{
unsigned long mode_flag;
int ret;
if (hba->backend->ops->pmode_enable_hba == NULL)
return -EINVAL;
ret = kstrtoul(page, 0, &mode_flag);
if (ret < 0) {
pr_err("Unable to extract hba mode flag: %d\n", ret);
return ret;
}
if (hba->dev_count) {
pr_err("Unable to set hba_mode with active devices\n");
return -EINVAL;
}
ret = hba->backend->ops->pmode_enable_hba(hba, mode_flag);
if (ret < 0)
return -EINVAL;
if (ret > 0)
hba->hba_flags |= HBA_FLAGS_PSCSI_MODE;
else if (ret == 0)
hba->hba_flags &= ~HBA_FLAGS_PSCSI_MODE;
return count;
}
static void target_core_hba_release(struct config_item *item)
{
struct se_hba *hba = container_of(to_config_group(item),
struct se_hba, hba_group);
core_delete_hba(hba);
}
static struct config_group *target_core_call_addhbatotarget(
struct config_group *group,
const char *name)
{
char *se_plugin_str, *str, *str2;
struct se_hba *hba;
char buf[TARGET_CORE_NAME_MAX_LEN];
unsigned long plugin_dep_id = 0;
int ret;
memset(buf, 0, TARGET_CORE_NAME_MAX_LEN);
if (strlen(name) >= TARGET_CORE_NAME_MAX_LEN) {
pr_err("Passed *name strlen(): %d exceeds"
" TARGET_CORE_NAME_MAX_LEN: %d\n", (int)strlen(name),
TARGET_CORE_NAME_MAX_LEN);
return ERR_PTR(-ENAMETOOLONG);
}
snprintf(buf, TARGET_CORE_NAME_MAX_LEN, "%s", name);
str = strstr(buf, "_");
if (!str) {
pr_err("Unable to locate \"_\" for $SUBSYSTEM_PLUGIN_$HOST_ID\n");
return ERR_PTR(-EINVAL);
}
se_plugin_str = buf;
str2 = strstr(str+1, "_");
if (str2) {
*str2 = '\0';
str2++;
str = str2;
} else {
*str = '\0';
str++;
}
ret = kstrtoul(str, 0, &plugin_dep_id);
if (ret < 0) {
pr_err("kstrtoul() returned %d for"
" plugin_dep_id\n", ret);
return ERR_PTR(ret);
}
transport_subsystem_check_init();
hba = core_alloc_hba(se_plugin_str, plugin_dep_id, 0);
if (IS_ERR(hba))
return ERR_CAST(hba);
config_group_init_type_name(&hba->hba_group, name,
&target_core_hba_cit);
return &hba->hba_group;
}
static void target_core_call_delhbafromtarget(
struct config_group *group,
struct config_item *item)
{
config_item_put(item);
}
void target_setup_backend_cits(struct target_backend *tb)
{
target_core_setup_dev_cit(tb);
target_core_setup_dev_attrib_cit(tb);
target_core_setup_dev_pr_cit(tb);
target_core_setup_dev_wwn_cit(tb);
target_core_setup_dev_alua_tg_pt_gps_cit(tb);
target_core_setup_dev_stat_cit(tb);
}
static int __init target_core_init_configfs(void)
{
struct config_group *target_cg, *hba_cg = NULL, *alua_cg = NULL;
struct config_group *lu_gp_cg = NULL;
struct configfs_subsystem *subsys = &target_core_fabrics;
struct t10_alua_lu_gp *lu_gp;
int ret;
pr_debug("TARGET_CORE[0]: Loading Generic Kernel Storage"
" Engine: %s on %s/%s on "UTS_RELEASE"\n",
TARGET_CORE_VERSION, utsname()->sysname, utsname()->machine);
config_group_init(&subsys->su_group);
mutex_init(&subsys->su_mutex);
ret = init_se_kmem_caches();
if (ret < 0)
return ret;
target_cg = &subsys->su_group;
target_cg->default_groups = kmalloc(sizeof(struct config_group *) * 2,
GFP_KERNEL);
if (!target_cg->default_groups) {
pr_err("Unable to allocate target_cg->default_groups\n");
ret = -ENOMEM;
goto out_global;
}
config_group_init_type_name(&target_core_hbagroup,
"core", &target_core_cit);
target_cg->default_groups[0] = &target_core_hbagroup;
target_cg->default_groups[1] = NULL;
hba_cg = &target_core_hbagroup;
hba_cg->default_groups = kmalloc(sizeof(struct config_group *) * 2,
GFP_KERNEL);
if (!hba_cg->default_groups) {
pr_err("Unable to allocate hba_cg->default_groups\n");
ret = -ENOMEM;
goto out_global;
}
config_group_init_type_name(&alua_group,
"alua", &target_core_alua_cit);
hba_cg->default_groups[0] = &alua_group;
hba_cg->default_groups[1] = NULL;
alua_cg = &alua_group;
alua_cg->default_groups = kmalloc(sizeof(struct config_group *) * 2,
GFP_KERNEL);
if (!alua_cg->default_groups) {
pr_err("Unable to allocate alua_cg->default_groups\n");
ret = -ENOMEM;
goto out_global;
}
config_group_init_type_name(&alua_lu_gps_group,
"lu_gps", &target_core_alua_lu_gps_cit);
alua_cg->default_groups[0] = &alua_lu_gps_group;
alua_cg->default_groups[1] = NULL;
lu_gp = core_alua_allocate_lu_gp("default_lu_gp", 1);
if (IS_ERR(lu_gp)) {
ret = -ENOMEM;
goto out_global;
}
lu_gp_cg = &alua_lu_gps_group;
lu_gp_cg->default_groups = kmalloc(sizeof(struct config_group *) * 2,
GFP_KERNEL);
if (!lu_gp_cg->default_groups) {
pr_err("Unable to allocate lu_gp_cg->default_groups\n");
ret = -ENOMEM;
goto out_global;
}
config_group_init_type_name(&lu_gp->lu_gp_group, "default_lu_gp",
&target_core_alua_lu_gp_cit);
lu_gp_cg->default_groups[0] = &lu_gp->lu_gp_group;
lu_gp_cg->default_groups[1] = NULL;
default_lu_gp = lu_gp;
ret = configfs_register_subsystem(subsys);
if (ret < 0) {
pr_err("Error %d while registering subsystem %s\n",
ret, subsys->su_group.cg_item.ci_namebuf);
goto out_global;
}
pr_debug("TARGET_CORE[0]: Initialized ConfigFS Fabric"
" Infrastructure: "TARGET_CORE_VERSION" on %s/%s"
" on "UTS_RELEASE"\n", utsname()->sysname, utsname()->machine);
ret = rd_module_init();
if (ret < 0)
goto out;
ret = core_dev_setup_virtual_lun0();
if (ret < 0)
goto out;
ret = target_xcopy_setup_pt();
if (ret < 0)
goto out;
return 0;
out:
configfs_unregister_subsystem(subsys);
core_dev_release_virtual_lun0();
rd_module_exit();
out_global:
if (default_lu_gp) {
core_alua_free_lu_gp(default_lu_gp);
default_lu_gp = NULL;
}
if (lu_gp_cg)
kfree(lu_gp_cg->default_groups);
if (alua_cg)
kfree(alua_cg->default_groups);
if (hba_cg)
kfree(hba_cg->default_groups);
kfree(target_cg->default_groups);
release_se_kmem_caches();
return ret;
}
static void __exit target_core_exit_configfs(void)
{
struct config_group *hba_cg, *alua_cg, *lu_gp_cg;
struct config_item *item;
int i;
lu_gp_cg = &alua_lu_gps_group;
for (i = 0; lu_gp_cg->default_groups[i]; i++) {
item = &lu_gp_cg->default_groups[i]->cg_item;
lu_gp_cg->default_groups[i] = NULL;
config_item_put(item);
}
kfree(lu_gp_cg->default_groups);
lu_gp_cg->default_groups = NULL;
alua_cg = &alua_group;
for (i = 0; alua_cg->default_groups[i]; i++) {
item = &alua_cg->default_groups[i]->cg_item;
alua_cg->default_groups[i] = NULL;
config_item_put(item);
}
kfree(alua_cg->default_groups);
alua_cg->default_groups = NULL;
hba_cg = &target_core_hbagroup;
for (i = 0; hba_cg->default_groups[i]; i++) {
item = &hba_cg->default_groups[i]->cg_item;
hba_cg->default_groups[i] = NULL;
config_item_put(item);
}
kfree(hba_cg->default_groups);
hba_cg->default_groups = NULL;
configfs_unregister_subsystem(&target_core_fabrics);
kfree(target_core_fabrics.su_group.default_groups);
core_alua_free_lu_gp(default_lu_gp);
default_lu_gp = NULL;
pr_debug("TARGET_CORE[0]: Released ConfigFS Fabric"
" Infrastructure\n");
core_dev_release_virtual_lun0();
rd_module_exit();
target_xcopy_release_pt();
release_se_kmem_caches();
}
