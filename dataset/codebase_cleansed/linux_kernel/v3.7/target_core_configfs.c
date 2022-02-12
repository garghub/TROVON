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
" on %s/%s on "UTS_RELEASE"\n", TARGET_CORE_CONFIGFS_VERSION,
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
if (!strcmp(tf->tf_name, name)) {
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
if (!strncmp(name, "iscsi", 5)) {
ret = request_module("iscsi_target_mod");
if (ret < 0) {
pr_err("request_module() failed for"
" iscsi_target_mod.ko: %d\n", ret);
return ERR_PTR(-EINVAL);
}
} else if (!strncmp(name, "loopback", 8)) {
ret = request_module("tcm_loop");
if (ret < 0) {
pr_err("request_module() failed for"
" tcm_loop.ko: %d\n", ret);
return ERR_PTR(-EINVAL);
}
}
tf = target_core_get_fabric(name);
if (!tf) {
pr_err("target_core_get_fabric() failed for %s\n",
name);
return ERR_PTR(-EINVAL);
}
pr_debug("Target_Core_ConfigFS: REGISTER -> Located fabric:"
" %s\n", tf->tf_name);
pr_debug("Target_Core_ConfigFS: REGISTER tfc_wwn_cit -> %p\n",
&TF_CIT_TMPL(tf)->tfc_wwn_cit);
tf->tf_group.default_groups = tf->tf_default_groups;
tf->tf_group.default_groups[0] = &tf->tf_disc_group;
tf->tf_group.default_groups[1] = NULL;
config_group_init_type_name(&tf->tf_group, name,
&TF_CIT_TMPL(tf)->tfc_wwn_cit);
config_group_init_type_name(&tf->tf_disc_group, "discovery_auth",
&TF_CIT_TMPL(tf)->tfc_discovery_cit);
pr_debug("Target_Core_ConfigFS: REGISTER -> Allocated Fabric:"
" %s\n", tf->tf_group.cg_item.ci_name);
tf->tf_ops.tf_subsys = tf->tf_subsys;
tf->tf_fabric = &tf->tf_group.cg_item;
pr_debug("Target_Core_ConfigFS: REGISTER -> Set tf->tf_fabric"
" for %s\n", name);
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
" %s\n", tf->tf_name);
atomic_dec(&tf->tf_access_cnt);
pr_debug("Target_Core_ConfigFS: DEREGISTER -> Releasing"
" tf->tf_fabric for %s\n", tf->tf_name);
tf->tf_fabric = NULL;
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
struct target_fabric_configfs *target_fabric_configfs_init(
struct module *fabric_mod,
const char *name)
{
struct target_fabric_configfs *tf;
if (!(name)) {
pr_err("Unable to locate passed fabric name\n");
return ERR_PTR(-EINVAL);
}
if (strlen(name) >= TARGET_FABRIC_NAME_SIZE) {
pr_err("Passed name: %s exceeds TARGET_FABRIC"
"_NAME_SIZE\n", name);
return ERR_PTR(-EINVAL);
}
tf = kzalloc(sizeof(struct target_fabric_configfs), GFP_KERNEL);
if (!tf)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&tf->tf_list);
atomic_set(&tf->tf_access_cnt, 0);
tf->tf_module = fabric_mod;
target_fabric_setup_cits(tf);
tf->tf_subsys = target_core_subsystem[0];
snprintf(tf->tf_name, TARGET_FABRIC_NAME_SIZE, "%s", name);
mutex_lock(&g_tf_lock);
list_add_tail(&tf->tf_list, &g_tf_list);
mutex_unlock(&g_tf_lock);
pr_debug("<<<<<<<<<<<<<<<<<<<<<< BEGIN FABRIC API >>>>>>>>"
">>>>>>>>>>>>>>\n");
pr_debug("Initialized struct target_fabric_configfs: %p for"
" %s\n", tf, tf->tf_name);
return tf;
}
void target_fabric_configfs_free(
struct target_fabric_configfs *tf)
{
mutex_lock(&g_tf_lock);
list_del(&tf->tf_list);
mutex_unlock(&g_tf_lock);
kfree(tf);
}
static int target_fabric_tf_ops_check(
struct target_fabric_configfs *tf)
{
struct target_core_fabric_ops *tfo = &tf->tf_ops;
if (!tfo->get_fabric_name) {
pr_err("Missing tfo->get_fabric_name()\n");
return -EINVAL;
}
if (!tfo->get_fabric_proto_ident) {
pr_err("Missing tfo->get_fabric_proto_ident()\n");
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
if (!tfo->tpg_get_default_depth) {
pr_err("Missing tfo->tpg_get_default_depth()\n");
return -EINVAL;
}
if (!tfo->tpg_get_pr_transport_id) {
pr_err("Missing tfo->tpg_get_pr_transport_id()\n");
return -EINVAL;
}
if (!tfo->tpg_get_pr_transport_id_len) {
pr_err("Missing tfo->tpg_get_pr_transport_id_len()\n");
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
if (!tfo->tpg_alloc_fabric_acl) {
pr_err("Missing tfo->tpg_alloc_fabric_acl()\n");
return -EINVAL;
}
if (!tfo->tpg_release_fabric_acl) {
pr_err("Missing tfo->tpg_release_fabric_acl()\n");
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
if (!tfo->get_task_tag) {
pr_err("Missing tfo->get_task_tag()\n");
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
int target_fabric_configfs_register(
struct target_fabric_configfs *tf)
{
int ret;
if (!tf) {
pr_err("Unable to locate target_fabric_configfs"
" pointer\n");
return -EINVAL;
}
if (!tf->tf_subsys) {
pr_err("Unable to target struct config_subsystem"
" pointer\n");
return -EINVAL;
}
ret = target_fabric_tf_ops_check(tf);
if (ret < 0)
return ret;
pr_debug("<<<<<<<<<<<<<<<<<<<<<< END FABRIC API >>>>>>>>>>>>"
">>>>>>>>>>\n");
return 0;
}
void target_fabric_configfs_deregister(
struct target_fabric_configfs *tf)
{
struct configfs_subsystem *su;
if (!tf) {
pr_err("Unable to locate passed target_fabric_"
"configfs\n");
return;
}
su = tf->tf_subsys;
if (!su) {
pr_err("Unable to locate passed tf->tf_subsys"
" pointer\n");
return;
}
pr_debug("<<<<<<<<<<<<<<<<<<<<<< BEGIN FABRIC API >>>>>>>>>>"
">>>>>>>>>>>>\n");
mutex_lock(&g_tf_lock);
if (atomic_read(&tf->tf_access_cnt)) {
mutex_unlock(&g_tf_lock);
pr_err("Non zero tf->tf_access_cnt for fabric %s\n",
tf->tf_name);
BUG();
}
list_del(&tf->tf_list);
mutex_unlock(&g_tf_lock);
pr_debug("Target_Core_ConfigFS: DEREGISTER -> Releasing tf:"
" %s\n", tf->tf_name);
tf->tf_module = NULL;
tf->tf_subsys = NULL;
kfree(tf);
pr_debug("<<<<<<<<<<<<<<<<<<<<<< END FABRIC API >>>>>>>>>>>>>>>>>"
">>>>>\n");
}
static ssize_t target_core_dev_wwn_show_attr_vpd_unit_serial(
struct t10_wwn *t10_wwn,
char *page)
{
struct se_subsystem_dev *se_dev = t10_wwn->t10_sub_dev;
struct se_device *dev;
dev = se_dev->se_dev_ptr;
if (!dev)
return -ENODEV;
return sprintf(page, "T10 VPD Unit Serial Number: %s\n",
&t10_wwn->unit_serial[0]);
}
static ssize_t target_core_dev_wwn_store_attr_vpd_unit_serial(
struct t10_wwn *t10_wwn,
const char *page,
size_t count)
{
struct se_subsystem_dev *su_dev = t10_wwn->t10_sub_dev;
struct se_device *dev;
unsigned char buf[INQUIRY_VPD_SERIAL_LEN];
if (su_dev->su_dev_flags & SDF_FIRMWARE_VPD_UNIT_SERIAL) {
pr_err("Underlying SCSI device firmware provided VPD"
" Unit Serial, ignoring request\n");
return -EOPNOTSUPP;
}
if (strlen(page) >= INQUIRY_VPD_SERIAL_LEN) {
pr_err("Emulated VPD Unit Serial exceeds"
" INQUIRY_VPD_SERIAL_LEN: %d\n", INQUIRY_VPD_SERIAL_LEN);
return -EOVERFLOW;
}
dev = su_dev->se_dev_ptr;
if (dev) {
if (atomic_read(&dev->dev_export_obj.obj_access_count)) {
pr_err("Unable to set VPD Unit Serial while"
" active %d $FABRIC_MOD exports exist\n",
atomic_read(&dev->dev_export_obj.obj_access_count));
return -EINVAL;
}
}
memset(buf, 0, INQUIRY_VPD_SERIAL_LEN);
snprintf(buf, INQUIRY_VPD_SERIAL_LEN, "%s", page);
snprintf(su_dev->t10_wwn.unit_serial, INQUIRY_VPD_SERIAL_LEN,
"%s", strstrip(buf));
su_dev->su_dev_flags |= SDF_EMULATED_VPD_UNIT_SERIAL;
pr_debug("Target_Core_ConfigFS: Set emulated VPD Unit Serial:"
" %s\n", su_dev->t10_wwn.unit_serial);
return count;
}
static ssize_t target_core_dev_wwn_show_attr_vpd_protocol_identifier(
struct t10_wwn *t10_wwn,
char *page)
{
struct se_subsystem_dev *se_dev = t10_wwn->t10_sub_dev;
struct se_device *dev;
struct t10_vpd *vpd;
unsigned char buf[VPD_TMP_BUF_SIZE];
ssize_t len = 0;
dev = se_dev->se_dev_ptr;
if (!dev)
return -ENODEV;
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
static ssize_t target_core_dev_pr_show_spc3_res(
struct se_device *dev,
char *page,
ssize_t *len)
{
struct se_node_acl *se_nacl;
struct t10_pr_registration *pr_reg;
char i_buf[PR_REG_ISID_ID_LEN];
int prf_isid;
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
spin_lock(&dev->dev_reservation_lock);
pr_reg = dev->dev_pr_res_holder;
if (!pr_reg) {
*len += sprintf(page + *len, "No SPC-3 Reservation holder\n");
spin_unlock(&dev->dev_reservation_lock);
return *len;
}
se_nacl = pr_reg->pr_reg_nacl;
prf_isid = core_pr_dump_initiator_port(pr_reg, &i_buf[0],
PR_REG_ISID_ID_LEN);
*len += sprintf(page + *len, "SPC-3 Reservation: %s Initiator: %s%s\n",
se_nacl->se_tpg->se_tpg_tfo->get_fabric_name(),
se_nacl->initiatorname, (prf_isid) ? &i_buf[0] : "");
spin_unlock(&dev->dev_reservation_lock);
return *len;
}
static ssize_t target_core_dev_pr_show_spc2_res(
struct se_device *dev,
char *page,
ssize_t *len)
{
struct se_node_acl *se_nacl;
spin_lock(&dev->dev_reservation_lock);
se_nacl = dev->dev_reserved_node_acl;
if (!se_nacl) {
*len += sprintf(page + *len, "No SPC-2 Reservation holder\n");
spin_unlock(&dev->dev_reservation_lock);
return *len;
}
*len += sprintf(page + *len, "SPC-2 Reservation: %s Initiator: %s\n",
se_nacl->se_tpg->se_tpg_tfo->get_fabric_name(),
se_nacl->initiatorname);
spin_unlock(&dev->dev_reservation_lock);
return *len;
}
static ssize_t target_core_dev_pr_show_attr_res_holder(
struct se_subsystem_dev *su_dev,
char *page)
{
ssize_t len = 0;
if (!su_dev->se_dev_ptr)
return -ENODEV;
switch (su_dev->t10_pr.res_type) {
case SPC3_PERSISTENT_RESERVATIONS:
target_core_dev_pr_show_spc3_res(su_dev->se_dev_ptr,
page, &len);
break;
case SPC2_RESERVATIONS:
target_core_dev_pr_show_spc2_res(su_dev->se_dev_ptr,
page, &len);
break;
case SPC_PASSTHROUGH:
len += sprintf(page+len, "Passthrough\n");
break;
default:
len += sprintf(page+len, "Unknown\n");
break;
}
return len;
}
static ssize_t target_core_dev_pr_show_attr_res_pr_all_tgt_pts(
struct se_subsystem_dev *su_dev,
char *page)
{
struct se_device *dev;
struct t10_pr_registration *pr_reg;
ssize_t len = 0;
dev = su_dev->se_dev_ptr;
if (!dev)
return -ENODEV;
if (su_dev->t10_pr.res_type != SPC3_PERSISTENT_RESERVATIONS)
return len;
spin_lock(&dev->dev_reservation_lock);
pr_reg = dev->dev_pr_res_holder;
if (!pr_reg) {
len = sprintf(page, "No SPC-3 Reservation holder\n");
spin_unlock(&dev->dev_reservation_lock);
return len;
}
if (pr_reg->pr_reg_all_tg_pt)
len = sprintf(page, "SPC-3 Reservation: All Target"
" Ports registration\n");
else
len = sprintf(page, "SPC-3 Reservation: Single"
" Target Port registration\n");
spin_unlock(&dev->dev_reservation_lock);
return len;
}
static ssize_t target_core_dev_pr_show_attr_res_pr_generation(
struct se_subsystem_dev *su_dev,
char *page)
{
if (!su_dev->se_dev_ptr)
return -ENODEV;
if (su_dev->t10_pr.res_type != SPC3_PERSISTENT_RESERVATIONS)
return 0;
return sprintf(page, "0x%08x\n", su_dev->t10_pr.pr_generation);
}
static ssize_t target_core_dev_pr_show_attr_res_pr_holder_tg_port(
struct se_subsystem_dev *su_dev,
char *page)
{
struct se_device *dev;
struct se_node_acl *se_nacl;
struct se_lun *lun;
struct se_portal_group *se_tpg;
struct t10_pr_registration *pr_reg;
struct target_core_fabric_ops *tfo;
ssize_t len = 0;
dev = su_dev->se_dev_ptr;
if (!dev)
return -ENODEV;
if (su_dev->t10_pr.res_type != SPC3_PERSISTENT_RESERVATIONS)
return len;
spin_lock(&dev->dev_reservation_lock);
pr_reg = dev->dev_pr_res_holder;
if (!pr_reg) {
len = sprintf(page, "No SPC-3 Reservation holder\n");
spin_unlock(&dev->dev_reservation_lock);
return len;
}
se_nacl = pr_reg->pr_reg_nacl;
se_tpg = se_nacl->se_tpg;
lun = pr_reg->pr_reg_tg_pt_lun;
tfo = se_tpg->se_tpg_tfo;
len += sprintf(page+len, "SPC-3 Reservation: %s"
" Target Node Endpoint: %s\n", tfo->get_fabric_name(),
tfo->tpg_get_wwn(se_tpg));
len += sprintf(page+len, "SPC-3 Reservation: Relative Port"
" Identifier Tag: %hu %s Portal Group Tag: %hu"
" %s Logical Unit: %u\n", lun->lun_sep->sep_rtpi,
tfo->get_fabric_name(), tfo->tpg_get_tag(se_tpg),
tfo->get_fabric_name(), lun->unpacked_lun);
spin_unlock(&dev->dev_reservation_lock);
return len;
}
static ssize_t target_core_dev_pr_show_attr_res_pr_registered_i_pts(
struct se_subsystem_dev *su_dev,
char *page)
{
struct target_core_fabric_ops *tfo;
struct t10_pr_registration *pr_reg;
unsigned char buf[384];
char i_buf[PR_REG_ISID_ID_LEN];
ssize_t len = 0;
int reg_count = 0, prf_isid;
if (!su_dev->se_dev_ptr)
return -ENODEV;
if (su_dev->t10_pr.res_type != SPC3_PERSISTENT_RESERVATIONS)
return len;
len += sprintf(page+len, "SPC-3 PR Registrations:\n");
spin_lock(&su_dev->t10_pr.registration_lock);
list_for_each_entry(pr_reg, &su_dev->t10_pr.registration_list,
pr_reg_list) {
memset(buf, 0, 384);
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
tfo = pr_reg->pr_reg_nacl->se_tpg->se_tpg_tfo;
prf_isid = core_pr_dump_initiator_port(pr_reg, &i_buf[0],
PR_REG_ISID_ID_LEN);
sprintf(buf, "%s Node: %s%s Key: 0x%016Lx PRgen: 0x%08x\n",
tfo->get_fabric_name(),
pr_reg->pr_reg_nacl->initiatorname, (prf_isid) ?
&i_buf[0] : "", pr_reg->pr_res_key,
pr_reg->pr_res_generation);
if (len + strlen(buf) >= PAGE_SIZE)
break;
len += sprintf(page+len, "%s", buf);
reg_count++;
}
spin_unlock(&su_dev->t10_pr.registration_lock);
if (!reg_count)
len += sprintf(page+len, "None\n");
return len;
}
static ssize_t target_core_dev_pr_show_attr_res_pr_type(
struct se_subsystem_dev *su_dev,
char *page)
{
struct se_device *dev;
struct t10_pr_registration *pr_reg;
ssize_t len = 0;
dev = su_dev->se_dev_ptr;
if (!dev)
return -ENODEV;
if (su_dev->t10_pr.res_type != SPC3_PERSISTENT_RESERVATIONS)
return len;
spin_lock(&dev->dev_reservation_lock);
pr_reg = dev->dev_pr_res_holder;
if (!pr_reg) {
len = sprintf(page, "No SPC-3 Reservation holder\n");
spin_unlock(&dev->dev_reservation_lock);
return len;
}
len = sprintf(page, "SPC-3 Reservation Type: %s\n",
core_scsi3_pr_dump_type(pr_reg->pr_res_type));
spin_unlock(&dev->dev_reservation_lock);
return len;
}
static ssize_t target_core_dev_pr_show_attr_res_type(
struct se_subsystem_dev *su_dev,
char *page)
{
ssize_t len = 0;
if (!su_dev->se_dev_ptr)
return -ENODEV;
switch (su_dev->t10_pr.res_type) {
case SPC3_PERSISTENT_RESERVATIONS:
len = sprintf(page, "SPC3_PERSISTENT_RESERVATIONS\n");
break;
case SPC2_RESERVATIONS:
len = sprintf(page, "SPC2_RESERVATIONS\n");
break;
case SPC_PASSTHROUGH:
len = sprintf(page, "SPC_PASSTHROUGH\n");
break;
default:
len = sprintf(page, "UNKNOWN\n");
break;
}
return len;
}
static ssize_t target_core_dev_pr_show_attr_res_aptpl_active(
struct se_subsystem_dev *su_dev,
char *page)
{
if (!su_dev->se_dev_ptr)
return -ENODEV;
if (su_dev->t10_pr.res_type != SPC3_PERSISTENT_RESERVATIONS)
return 0;
return sprintf(page, "APTPL Bit Status: %s\n",
(su_dev->t10_pr.pr_aptpl_active) ? "Activated" : "Disabled");
}
static ssize_t target_core_dev_pr_show_attr_res_aptpl_metadata(
struct se_subsystem_dev *su_dev,
char *page)
{
if (!su_dev->se_dev_ptr)
return -ENODEV;
if (su_dev->t10_pr.res_type != SPC3_PERSISTENT_RESERVATIONS)
return 0;
return sprintf(page, "Ready to process PR APTPL metadata..\n");
}
static ssize_t target_core_dev_pr_store_attr_res_aptpl_metadata(
struct se_subsystem_dev *su_dev,
const char *page,
size_t count)
{
struct se_device *dev;
unsigned char *i_fabric = NULL, *i_port = NULL, *isid = NULL;
unsigned char *t_fabric = NULL, *t_port = NULL;
char *orig, *ptr, *arg_p, *opts;
substring_t args[MAX_OPT_ARGS];
unsigned long long tmp_ll;
u64 sa_res_key = 0;
u32 mapped_lun = 0, target_lun = 0;
int ret = -1, res_holder = 0, all_tg_pt = 0, arg, token;
u16 port_rpti = 0, tpgt = 0;
u8 type = 0, scope;
dev = su_dev->se_dev_ptr;
if (!dev)
return -ENODEV;
if (su_dev->t10_pr.res_type != SPC3_PERSISTENT_RESERVATIONS)
return 0;
if (atomic_read(&dev->dev_export_obj.obj_access_count)) {
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
i_fabric = match_strdup(&args[0]);
if (!i_fabric) {
ret = -ENOMEM;
goto out;
}
break;
case Opt_initiator_node:
i_port = match_strdup(&args[0]);
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
isid = match_strdup(&args[0]);
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
arg_p = match_strdup(&args[0]);
if (!arg_p) {
ret = -ENOMEM;
goto out;
}
ret = strict_strtoull(arg_p, 0, &tmp_ll);
if (ret < 0) {
pr_err("strict_strtoull() failed for"
" sa_res_key=\n");
goto out;
}
sa_res_key = (u64)tmp_ll;
break;
case Opt_res_holder:
match_int(args, &arg);
res_holder = arg;
break;
case Opt_res_type:
match_int(args, &arg);
type = (u8)arg;
break;
case Opt_res_scope:
match_int(args, &arg);
scope = (u8)arg;
break;
case Opt_res_all_tg_pt:
match_int(args, &arg);
all_tg_pt = (int)arg;
break;
case Opt_mapped_lun:
match_int(args, &arg);
mapped_lun = (u32)arg;
break;
case Opt_target_fabric:
t_fabric = match_strdup(&args[0]);
if (!t_fabric) {
ret = -ENOMEM;
goto out;
}
break;
case Opt_target_node:
t_port = match_strdup(&args[0]);
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
match_int(args, &arg);
tpgt = (u16)arg;
break;
case Opt_port_rtpi:
match_int(args, &arg);
port_rpti = (u16)arg;
break;
case Opt_target_lun:
match_int(args, &arg);
target_lun = (u32)arg;
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
ret = core_scsi3_alloc_aptpl_registration(&su_dev->t10_pr, sa_res_key,
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
struct se_subsystem_dev *se_dev = p;
struct se_hba *hba = se_dev->se_dev_hba;
struct se_subsystem_api *t = hba->transport;
int bl = 0;
ssize_t read_bytes = 0;
if (!se_dev->se_dev_ptr)
return -ENODEV;
transport_dump_dev_state(se_dev->se_dev_ptr, page, &bl);
read_bytes += bl;
read_bytes += t->show_configfs_dev_params(hba, se_dev, page+read_bytes);
return read_bytes;
}
static ssize_t target_core_store_dev_control(
void *p,
const char *page,
size_t count)
{
struct se_subsystem_dev *se_dev = p;
struct se_hba *hba = se_dev->se_dev_hba;
struct se_subsystem_api *t = hba->transport;
if (!se_dev->se_dev_su_ptr) {
pr_err("Unable to locate struct se_subsystem_dev>se"
"_dev_su_ptr\n");
return -EINVAL;
}
return t->set_configfs_dev_params(hba, se_dev, page, count);
}
static ssize_t target_core_show_dev_alias(void *p, char *page)
{
struct se_subsystem_dev *se_dev = p;
if (!(se_dev->su_dev_flags & SDF_USING_ALIAS))
return 0;
return snprintf(page, PAGE_SIZE, "%s\n", se_dev->se_dev_alias);
}
static ssize_t target_core_store_dev_alias(
void *p,
const char *page,
size_t count)
{
struct se_subsystem_dev *se_dev = p;
struct se_hba *hba = se_dev->se_dev_hba;
ssize_t read_bytes;
if (count > (SE_DEV_ALIAS_LEN-1)) {
pr_err("alias count: %d exceeds"
" SE_DEV_ALIAS_LEN-1: %u\n", (int)count,
SE_DEV_ALIAS_LEN-1);
return -EINVAL;
}
read_bytes = snprintf(&se_dev->se_dev_alias[0], SE_DEV_ALIAS_LEN,
"%s", page);
if (!read_bytes)
return -EINVAL;
if (se_dev->se_dev_alias[read_bytes - 1] == '\n')
se_dev->se_dev_alias[read_bytes - 1] = '\0';
se_dev->su_dev_flags |= SDF_USING_ALIAS;
pr_debug("Target_Core_ConfigFS: %s/%s set alias: %s\n",
config_item_name(&hba->hba_group.cg_item),
config_item_name(&se_dev->se_dev_group.cg_item),
se_dev->se_dev_alias);
return read_bytes;
}
static ssize_t target_core_show_dev_udev_path(void *p, char *page)
{
struct se_subsystem_dev *se_dev = p;
if (!(se_dev->su_dev_flags & SDF_USING_UDEV_PATH))
return 0;
return snprintf(page, PAGE_SIZE, "%s\n", se_dev->se_dev_udev_path);
}
static ssize_t target_core_store_dev_udev_path(
void *p,
const char *page,
size_t count)
{
struct se_subsystem_dev *se_dev = p;
struct se_hba *hba = se_dev->se_dev_hba;
ssize_t read_bytes;
if (count > (SE_UDEV_PATH_LEN-1)) {
pr_err("udev_path count: %d exceeds"
" SE_UDEV_PATH_LEN-1: %u\n", (int)count,
SE_UDEV_PATH_LEN-1);
return -EINVAL;
}
read_bytes = snprintf(&se_dev->se_dev_udev_path[0], SE_UDEV_PATH_LEN,
"%s", page);
if (!read_bytes)
return -EINVAL;
if (se_dev->se_dev_udev_path[read_bytes - 1] == '\n')
se_dev->se_dev_udev_path[read_bytes - 1] = '\0';
se_dev->su_dev_flags |= SDF_USING_UDEV_PATH;
pr_debug("Target_Core_ConfigFS: %s/%s set udev_path: %s\n",
config_item_name(&hba->hba_group.cg_item),
config_item_name(&se_dev->se_dev_group.cg_item),
se_dev->se_dev_udev_path);
return read_bytes;
}
static ssize_t target_core_store_dev_enable(
void *p,
const char *page,
size_t count)
{
struct se_subsystem_dev *se_dev = p;
struct se_device *dev;
struct se_hba *hba = se_dev->se_dev_hba;
struct se_subsystem_api *t = hba->transport;
char *ptr;
ptr = strstr(page, "1");
if (!ptr) {
pr_err("For dev_enable ops, only valid value"
" is \"1\"\n");
return -EINVAL;
}
if (se_dev->se_dev_ptr) {
pr_err("se_dev->se_dev_ptr already set for storage"
" object\n");
return -EEXIST;
}
if (t->check_configfs_dev_params(hba, se_dev) < 0)
return -EINVAL;
dev = t->create_virtdevice(hba, se_dev, se_dev->se_dev_su_ptr);
if (IS_ERR(dev))
return PTR_ERR(dev);
else if (!dev)
return -EINVAL;
se_dev->se_dev_ptr = dev;
pr_debug("Target_Core_ConfigFS: Registered se_dev->se_dev_ptr:"
" %p\n", se_dev->se_dev_ptr);
return count;
}
static ssize_t target_core_show_alua_lu_gp(void *p, char *page)
{
struct se_device *dev;
struct se_subsystem_dev *su_dev = p;
struct config_item *lu_ci;
struct t10_alua_lu_gp *lu_gp;
struct t10_alua_lu_gp_member *lu_gp_mem;
ssize_t len = 0;
dev = su_dev->se_dev_ptr;
if (!dev)
return -ENODEV;
if (su_dev->t10_alua.alua_type != SPC3_ALUA_EMULATED)
return len;
lu_gp_mem = dev->dev_alua_lu_gp_mem;
if (!lu_gp_mem) {
pr_err("NULL struct se_device->dev_alua_lu_gp_mem"
" pointer\n");
return -EINVAL;
}
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
struct se_device *dev;
struct se_subsystem_dev *su_dev = p;
struct se_hba *hba = su_dev->se_dev_hba;
struct t10_alua_lu_gp *lu_gp = NULL, *lu_gp_new = NULL;
struct t10_alua_lu_gp_member *lu_gp_mem;
unsigned char buf[LU_GROUP_NAME_BUF];
int move = 0;
dev = su_dev->se_dev_ptr;
if (!dev)
return -ENODEV;
if (su_dev->t10_alua.alua_type != SPC3_ALUA_EMULATED) {
pr_warn("SPC3_ALUA_EMULATED not enabled for %s/%s\n",
config_item_name(&hba->hba_group.cg_item),
config_item_name(&su_dev->se_dev_group.cg_item));
return -EINVAL;
}
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
lu_gp_mem = dev->dev_alua_lu_gp_mem;
if (!lu_gp_mem) {
if (lu_gp_new)
core_alua_put_lu_gp_from_name(lu_gp_new);
pr_err("NULL struct se_device->dev_alua_lu_gp_mem"
" pointer\n");
return -EINVAL;
}
spin_lock(&lu_gp_mem->lu_gp_mem_lock);
lu_gp = lu_gp_mem->lu_gp;
if (lu_gp) {
if (!lu_gp_new) {
pr_debug("Target_Core_ConfigFS: Releasing %s/%s"
" from ALUA LU Group: core/alua/lu_gps/%s, ID:"
" %hu\n",
config_item_name(&hba->hba_group.cg_item),
config_item_name(&su_dev->se_dev_group.cg_item),
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
config_item_name(&su_dev->se_dev_group.cg_item),
config_item_name(&lu_gp_new->lu_gp_group.cg_item),
lu_gp_new->lu_gp_id);
core_alua_put_lu_gp_from_name(lu_gp_new);
return count;
}
static void target_core_dev_release(struct config_item *item)
{
struct se_subsystem_dev *se_dev = container_of(to_config_group(item),
struct se_subsystem_dev, se_dev_group);
struct se_hba *hba = item_to_hba(&se_dev->se_dev_hba->hba_group.cg_item);
struct se_subsystem_api *t = hba->transport;
struct config_group *dev_cg = &se_dev->se_dev_group;
kfree(dev_cg->default_groups);
if (se_dev->se_dev_ptr) {
pr_debug("Target_Core_ConfigFS: Calling se_free_"
"virtual_device() for se_dev_ptr: %p\n",
se_dev->se_dev_ptr);
se_free_virtual_device(se_dev->se_dev_ptr, hba);
} else {
pr_debug("Target_Core_ConfigFS: Calling t->free_"
"device() for se_dev_su_ptr: %p\n",
se_dev->se_dev_su_ptr);
t->free_device(se_dev->se_dev_su_ptr);
}
pr_debug("Target_Core_ConfigFS: Deallocating se_subsystem"
"_dev_t: %p\n", se_dev);
kfree(se_dev);
}
static ssize_t target_core_dev_show(struct config_item *item,
struct configfs_attribute *attr,
char *page)
{
struct se_subsystem_dev *se_dev = container_of(
to_config_group(item), struct se_subsystem_dev,
se_dev_group);
struct target_core_configfs_attribute *tc_attr = container_of(
attr, struct target_core_configfs_attribute, attr);
if (!tc_attr->show)
return -EINVAL;
return tc_attr->show(se_dev, page);
}
static ssize_t target_core_dev_store(struct config_item *item,
struct configfs_attribute *attr,
const char *page, size_t count)
{
struct se_subsystem_dev *se_dev = container_of(
to_config_group(item), struct se_subsystem_dev,
se_dev_group);
struct target_core_configfs_attribute *tc_attr = container_of(
attr, struct target_core_configfs_attribute, attr);
if (!tc_attr->store)
return -EINVAL;
return tc_attr->store(se_dev, page, count);
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
ret = strict_strtoul(page, 0, &lu_gp_id);
if (ret < 0) {
pr_err("strict_strtoul() returned %d for"
" lu_gp_id\n", ret);
return -EINVAL;
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
struct se_subsystem_dev *su_dev;
struct t10_alua_lu_gp_member *lu_gp_mem;
ssize_t len = 0, cur_len;
unsigned char buf[LU_GROUP_NAME_BUF];
memset(buf, 0, LU_GROUP_NAME_BUF);
spin_lock(&lu_gp->lu_gp_lock);
list_for_each_entry(lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
dev = lu_gp_mem->lu_gp_mem_dev;
su_dev = dev->se_sub_dev;
hba = su_dev->se_dev_hba;
cur_len = snprintf(buf, LU_GROUP_NAME_BUF, "%s/%s\n",
config_item_name(&hba->hba_group.cg_item),
config_item_name(&su_dev->se_dev_group.cg_item));
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
struct se_subsystem_dev *su_dev = tg_pt_gp->tg_pt_gp_su_dev;
unsigned long tmp;
int new_state, ret;
if (!tg_pt_gp->tg_pt_gp_valid_id) {
pr_err("Unable to do implict ALUA on non valid"
" tg_pt_gp ID: %hu\n", tg_pt_gp->tg_pt_gp_valid_id);
return -EINVAL;
}
ret = strict_strtoul(page, 0, &tmp);
if (ret < 0) {
pr_err("Unable to extract new ALUA access state from"
" %s\n", page);
return -EINVAL;
}
new_state = (int)tmp;
if (!(tg_pt_gp->tg_pt_gp_alua_access_type & TPGS_IMPLICT_ALUA)) {
pr_err("Unable to process implict configfs ALUA"
" transition while TPGS_IMPLICT_ALUA is disabled\n");
return -EINVAL;
}
ret = core_alua_do_port_transition(tg_pt_gp, su_dev->se_dev_ptr,
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
ret = strict_strtoul(page, 0, &tmp);
if (ret < 0) {
pr_err("Unable to extract new ALUA access status"
" from %s\n", page);
return -EINVAL;
}
new_status = (int)tmp;
if ((new_status != ALUA_STATUS_NONE) &&
(new_status != ALUA_STATUS_ALTERED_BY_EXPLICT_STPG) &&
(new_status != ALUA_STATUS_ALTERED_BY_IMPLICT_ALUA)) {
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
ret = strict_strtoul(page, 0, &tmp);
if (ret < 0) {
pr_err("Unable to extract alua_write_metadata\n");
return -EINVAL;
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
static ssize_t target_core_alua_tg_pt_gp_show_attr_implict_trans_secs(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
return core_alua_show_implict_trans_secs(tg_pt_gp, page);
}
static ssize_t target_core_alua_tg_pt_gp_store_attr_implict_trans_secs(
struct t10_alua_tg_pt_gp *tg_pt_gp,
const char *page,
size_t count)
{
return core_alua_store_implict_trans_secs(tg_pt_gp, page, count);
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
ret = strict_strtoul(page, 0, &tg_pt_gp_id);
if (ret < 0) {
pr_err("strict_strtoul() returned %d for"
" tg_pt_gp_id\n", ret);
return -EINVAL;
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
struct se_port *port;
struct se_portal_group *tpg;
struct se_lun *lun;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
ssize_t len = 0, cur_len;
unsigned char buf[TG_PT_GROUP_NAME_BUF];
memset(buf, 0, TG_PT_GROUP_NAME_BUF);
spin_lock(&tg_pt_gp->tg_pt_gp_lock);
list_for_each_entry(tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
port = tg_pt_gp_mem->tg_pt;
tpg = port->sep_tpg;
lun = port->sep_lun;
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
struct se_subsystem_dev *su_dev = alua->t10_sub_dev;
struct config_group *alua_tg_pt_gp_cg = NULL;
struct config_item *alua_tg_pt_gp_ci = NULL;
tg_pt_gp = core_alua_allocate_tg_pt_gp(su_dev, name, 0);
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
struct se_subsystem_dev *se_dev;
struct se_subsystem_api *t;
struct config_item *hba_ci = &group->cg_item;
struct se_hba *hba = item_to_hba(hba_ci);
struct config_group *dev_cg = NULL, *tg_pt_gp_cg = NULL;
struct config_group *dev_stat_grp = NULL;
int errno = -ENOMEM, ret;
ret = mutex_lock_interruptible(&hba->hba_access_mutex);
if (ret)
return ERR_PTR(ret);
t = hba->transport;
se_dev = kzalloc(sizeof(struct se_subsystem_dev), GFP_KERNEL);
if (!se_dev) {
pr_err("Unable to allocate memory for"
" struct se_subsystem_dev\n");
goto unlock;
}
INIT_LIST_HEAD(&se_dev->t10_wwn.t10_vpd_list);
spin_lock_init(&se_dev->t10_wwn.t10_vpd_lock);
INIT_LIST_HEAD(&se_dev->t10_pr.registration_list);
INIT_LIST_HEAD(&se_dev->t10_pr.aptpl_reg_list);
spin_lock_init(&se_dev->t10_pr.registration_lock);
spin_lock_init(&se_dev->t10_pr.aptpl_reg_lock);
INIT_LIST_HEAD(&se_dev->t10_alua.tg_pt_gps_list);
spin_lock_init(&se_dev->t10_alua.tg_pt_gps_lock);
spin_lock_init(&se_dev->se_dev_lock);
se_dev->t10_pr.pr_aptpl_buf_len = PR_APTPL_BUF_LEN;
se_dev->t10_wwn.t10_sub_dev = se_dev;
se_dev->t10_alua.t10_sub_dev = se_dev;
se_dev->se_dev_attrib.da_sub_dev = se_dev;
se_dev->se_dev_hba = hba;
dev_cg = &se_dev->se_dev_group;
dev_cg->default_groups = kzalloc(sizeof(struct config_group) * 7,
GFP_KERNEL);
if (!dev_cg->default_groups)
goto out;
se_dev->se_dev_su_ptr = t->allocate_virtdevice(hba, name);
if (!se_dev->se_dev_su_ptr) {
pr_err("Unable to locate subsystem dependent pointer"
" from allocate_virtdevice()\n");
goto out;
}
config_group_init_type_name(&se_dev->se_dev_group, name,
&target_core_dev_cit);
config_group_init_type_name(&se_dev->se_dev_attrib.da_group, "attrib",
&target_core_dev_attrib_cit);
config_group_init_type_name(&se_dev->se_dev_pr_group, "pr",
&target_core_dev_pr_cit);
config_group_init_type_name(&se_dev->t10_wwn.t10_wwn_group, "wwn",
&target_core_dev_wwn_cit);
config_group_init_type_name(&se_dev->t10_alua.alua_tg_pt_gps_group,
"alua", &target_core_alua_tg_pt_gps_cit);
config_group_init_type_name(&se_dev->dev_stat_grps.stat_group,
"statistics", &target_core_stat_cit);
dev_cg->default_groups[0] = &se_dev->se_dev_attrib.da_group;
dev_cg->default_groups[1] = &se_dev->se_dev_pr_group;
dev_cg->default_groups[2] = &se_dev->t10_wwn.t10_wwn_group;
dev_cg->default_groups[3] = &se_dev->t10_alua.alua_tg_pt_gps_group;
dev_cg->default_groups[4] = &se_dev->dev_stat_grps.stat_group;
dev_cg->default_groups[5] = NULL;
tg_pt_gp = core_alua_allocate_tg_pt_gp(se_dev, "default_tg_pt_gp", 1);
if (!tg_pt_gp)
goto out;
tg_pt_gp_cg = &se_dev->t10_alua.alua_tg_pt_gps_group;
tg_pt_gp_cg->default_groups = kzalloc(sizeof(struct config_group) * 2,
GFP_KERNEL);
if (!tg_pt_gp_cg->default_groups) {
pr_err("Unable to allocate tg_pt_gp_cg->"
"default_groups\n");
goto out;
}
config_group_init_type_name(&tg_pt_gp->tg_pt_gp_group,
"default_tg_pt_gp", &target_core_alua_tg_pt_gp_cit);
tg_pt_gp_cg->default_groups[0] = &tg_pt_gp->tg_pt_gp_group;
tg_pt_gp_cg->default_groups[1] = NULL;
se_dev->t10_alua.default_tg_pt_gp = tg_pt_gp;
dev_stat_grp = &se_dev->dev_stat_grps.stat_group;
dev_stat_grp->default_groups = kzalloc(sizeof(struct config_group) * 4,
GFP_KERNEL);
if (!dev_stat_grp->default_groups) {
pr_err("Unable to allocate dev_stat_grp->default_groups\n");
goto out;
}
target_stat_setup_dev_default_groups(se_dev);
pr_debug("Target_Core_ConfigFS: Allocated struct se_subsystem_dev:"
" %p se_dev_su_ptr: %p\n", se_dev, se_dev->se_dev_su_ptr);
mutex_unlock(&hba->hba_access_mutex);
return &se_dev->se_dev_group;
out:
if (se_dev->t10_alua.default_tg_pt_gp) {
core_alua_free_tg_pt_gp(se_dev->t10_alua.default_tg_pt_gp);
se_dev->t10_alua.default_tg_pt_gp = NULL;
}
if (dev_stat_grp)
kfree(dev_stat_grp->default_groups);
if (tg_pt_gp_cg)
kfree(tg_pt_gp_cg->default_groups);
if (dev_cg)
kfree(dev_cg->default_groups);
if (se_dev->se_dev_su_ptr)
t->free_device(se_dev->se_dev_su_ptr);
kfree(se_dev);
unlock:
mutex_unlock(&hba->hba_access_mutex);
return ERR_PTR(errno);
}
static void target_core_drop_subdev(
struct config_group *group,
struct config_item *item)
{
struct se_subsystem_dev *se_dev = container_of(to_config_group(item),
struct se_subsystem_dev, se_dev_group);
struct se_hba *hba;
struct config_item *df_item;
struct config_group *dev_cg, *tg_pt_gp_cg, *dev_stat_grp;
int i;
hba = item_to_hba(&se_dev->se_dev_hba->hba_group.cg_item);
mutex_lock(&hba->hba_access_mutex);
dev_stat_grp = &se_dev->dev_stat_grps.stat_group;
for (i = 0; dev_stat_grp->default_groups[i]; i++) {
df_item = &dev_stat_grp->default_groups[i]->cg_item;
dev_stat_grp->default_groups[i] = NULL;
config_item_put(df_item);
}
kfree(dev_stat_grp->default_groups);
tg_pt_gp_cg = &se_dev->t10_alua.alua_tg_pt_gps_group;
for (i = 0; tg_pt_gp_cg->default_groups[i]; i++) {
df_item = &tg_pt_gp_cg->default_groups[i]->cg_item;
tg_pt_gp_cg->default_groups[i] = NULL;
config_item_put(df_item);
}
kfree(tg_pt_gp_cg->default_groups);
se_dev->t10_alua.default_tg_pt_gp = NULL;
dev_cg = &se_dev->se_dev_group;
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
hba->hba_id, hba->transport->name,
TARGET_CORE_CONFIGFS_VERSION);
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
struct se_subsystem_api *transport = hba->transport;
unsigned long mode_flag;
int ret;
if (transport->pmode_enable_hba == NULL)
return -EINVAL;
ret = strict_strtoul(page, 0, &mode_flag);
if (ret < 0) {
pr_err("Unable to extract hba mode flag: %d\n", ret);
return -EINVAL;
}
spin_lock(&hba->device_lock);
if (!list_empty(&hba->hba_dev_list)) {
pr_err("Unable to set hba_mode with active devices\n");
spin_unlock(&hba->device_lock);
return -EINVAL;
}
spin_unlock(&hba->device_lock);
ret = transport->pmode_enable_hba(hba, mode_flag);
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
ret = strict_strtoul(str, 0, &plugin_dep_id);
if (ret < 0) {
pr_err("strict_strtoul() returned %d for"
" plugin_dep_id\n", ret);
return ERR_PTR(-EINVAL);
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
static int __init target_core_init_configfs(void)
{
struct config_group *target_cg, *hba_cg = NULL, *alua_cg = NULL;
struct config_group *lu_gp_cg = NULL;
struct configfs_subsystem *subsys;
struct t10_alua_lu_gp *lu_gp;
int ret;
pr_debug("TARGET_CORE[0]: Loading Generic Kernel Storage"
" Engine: %s on %s/%s on "UTS_RELEASE"\n",
TARGET_CORE_VERSION, utsname()->sysname, utsname()->machine);
subsys = target_core_subsystem[0];
config_group_init(&subsys->su_group);
mutex_init(&subsys->su_mutex);
ret = init_se_kmem_caches();
if (ret < 0)
return ret;
target_cg = &subsys->su_group;
target_cg->default_groups = kzalloc(sizeof(struct config_group) * 2,
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
hba_cg->default_groups = kzalloc(sizeof(struct config_group) * 2,
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
alua_cg->default_groups = kzalloc(sizeof(struct config_group) * 2,
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
lu_gp_cg->default_groups = kzalloc(sizeof(struct config_group) * 2,
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
" Infrastructure: "TARGET_CORE_CONFIGFS_VERSION" on %s/%s"
" on "UTS_RELEASE"\n", utsname()->sysname, utsname()->machine);
ret = rd_module_init();
if (ret < 0)
goto out;
ret = core_dev_setup_virtual_lun0();
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
struct configfs_subsystem *subsys;
struct config_group *hba_cg, *alua_cg, *lu_gp_cg;
struct config_item *item;
int i;
subsys = target_core_subsystem[0];
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
configfs_unregister_subsystem(subsys);
kfree(subsys->su_group.default_groups);
core_alua_free_lu_gp(default_lu_gp);
default_lu_gp = NULL;
pr_debug("TARGET_CORE[0]: Released ConfigFS Fabric"
" Infrastructure\n");
core_dev_release_virtual_lun0();
rd_module_exit();
release_se_kmem_caches();
}
