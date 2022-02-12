static int target_fabric_mappedlun_link(
struct config_item *lun_acl_ci,
struct config_item *lun_ci)
{
struct se_dev_entry *deve;
struct se_lun *lun = container_of(to_config_group(lun_ci),
struct se_lun, lun_group);
struct se_lun_acl *lacl = container_of(to_config_group(lun_acl_ci),
struct se_lun_acl, se_lun_group);
struct se_portal_group *se_tpg;
struct config_item *nacl_ci, *tpg_ci, *tpg_ci_s, *wwn_ci, *wwn_ci_s;
int ret = 0, lun_access;
if (lun->lun_link_magic != SE_LUN_LINK_MAGIC) {
pr_err("Bad lun->lun_link_magic, not a valid lun_ci pointer:"
" %p to struct lun: %p\n", lun_ci, lun);
return -EFAULT;
}
if (!lun->lun_sep || !lun->lun_sep->sep_tpg) {
pr_err("Source se_lun->lun_sep or lun->lun_sep->sep"
"_tpg does not exist\n");
return -EINVAL;
}
se_tpg = lun->lun_sep->sep_tpg;
nacl_ci = &lun_acl_ci->ci_parent->ci_group->cg_item;
tpg_ci = &nacl_ci->ci_group->cg_item;
wwn_ci = &tpg_ci->ci_group->cg_item;
tpg_ci_s = &lun_ci->ci_parent->ci_group->cg_item;
wwn_ci_s = &tpg_ci_s->ci_group->cg_item;
if (strcmp(config_item_name(wwn_ci), config_item_name(wwn_ci_s))) {
pr_err("Illegal Initiator ACL SymLink outside of %s\n",
config_item_name(wwn_ci));
return -EINVAL;
}
if (strcmp(config_item_name(tpg_ci), config_item_name(tpg_ci_s))) {
pr_err("Illegal Initiator ACL Symlink outside of %s"
" TPGT: %s\n", config_item_name(wwn_ci),
config_item_name(tpg_ci));
return -EINVAL;
}
spin_lock_irq(&lacl->se_lun_nacl->device_list_lock);
deve = lacl->se_lun_nacl->device_list[lacl->mapped_lun];
if (deve->lun_flags & TRANSPORT_LUNFLAGS_INITIATOR_ACCESS)
lun_access = deve->lun_flags;
else
lun_access =
(se_tpg->se_tpg_tfo->tpg_check_prod_mode_write_protect(
se_tpg)) ? TRANSPORT_LUNFLAGS_READ_ONLY :
TRANSPORT_LUNFLAGS_READ_WRITE;
spin_unlock_irq(&lacl->se_lun_nacl->device_list_lock);
ret = core_dev_add_initiator_node_lun_acl(se_tpg, lacl,
lun->unpacked_lun, lun_access);
return (ret < 0) ? -EINVAL : 0;
}
static int target_fabric_mappedlun_unlink(
struct config_item *lun_acl_ci,
struct config_item *lun_ci)
{
struct se_lun *lun;
struct se_lun_acl *lacl = container_of(to_config_group(lun_acl_ci),
struct se_lun_acl, se_lun_group);
struct se_node_acl *nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve = nacl->device_list[lacl->mapped_lun];
struct se_portal_group *se_tpg;
if (!deve->se_lun)
return 0;
lun = container_of(to_config_group(lun_ci), struct se_lun, lun_group);
se_tpg = lun->lun_sep->sep_tpg;
core_dev_del_initiator_node_lun_acl(se_tpg, lun, lacl);
return 0;
}
static ssize_t target_fabric_mappedlun_show_write_protect(
struct se_lun_acl *lacl,
char *page)
{
struct se_node_acl *se_nacl = lacl->se_lun_nacl;
struct se_dev_entry *deve;
ssize_t len;
spin_lock_irq(&se_nacl->device_list_lock);
deve = se_nacl->device_list[lacl->mapped_lun];
len = sprintf(page, "%d\n",
(deve->lun_flags & TRANSPORT_LUNFLAGS_READ_ONLY) ?
1 : 0);
spin_unlock_irq(&se_nacl->device_list_lock);
return len;
}
static ssize_t target_fabric_mappedlun_store_write_protect(
struct se_lun_acl *lacl,
const char *page,
size_t count)
{
struct se_node_acl *se_nacl = lacl->se_lun_nacl;
struct se_portal_group *se_tpg = se_nacl->se_tpg;
unsigned long op;
int ret;
ret = kstrtoul(page, 0, &op);
if (ret)
return ret;
if ((op != 1) && (op != 0))
return -EINVAL;
core_update_device_list_access(lacl->mapped_lun, (op) ?
TRANSPORT_LUNFLAGS_READ_ONLY :
TRANSPORT_LUNFLAGS_READ_WRITE,
lacl->se_lun_nacl);
pr_debug("%s_ConfigFS: Changed Initiator ACL: %s"
" Mapped LUN: %u Write Protect bit to %s\n",
se_tpg->se_tpg_tfo->get_fabric_name(),
lacl->initiatorname, lacl->mapped_lun, (op) ? "ON" : "OFF");
return count;
}
static void target_fabric_mappedlun_release(struct config_item *item)
{
struct se_lun_acl *lacl = container_of(to_config_group(item),
struct se_lun_acl, se_lun_group);
struct se_portal_group *se_tpg = lacl->se_lun_nacl->se_tpg;
core_dev_free_initiator_node_lun_acl(se_tpg, lacl);
}
static struct config_group *target_core_mappedlun_stat_mkdir(
struct config_group *group,
const char *name)
{
return ERR_PTR(-ENOSYS);
}
static void target_core_mappedlun_stat_rmdir(
struct config_group *group,
struct config_item *item)
{
return;
}
static struct config_group *target_fabric_make_mappedlun(
struct config_group *group,
const char *name)
{
struct se_node_acl *se_nacl = container_of(group,
struct se_node_acl, acl_group);
struct se_portal_group *se_tpg = se_nacl->se_tpg;
struct target_fabric_configfs *tf = se_tpg->se_tpg_wwn->wwn_tf;
struct se_lun_acl *lacl;
struct config_item *acl_ci;
struct config_group *lacl_cg = NULL, *ml_stat_grp = NULL;
char *buf;
unsigned long mapped_lun;
int ret = 0;
acl_ci = &group->cg_item;
if (!acl_ci) {
pr_err("Unable to locatel acl_ci\n");
return NULL;
}
buf = kzalloc(strlen(name) + 1, GFP_KERNEL);
if (!buf) {
pr_err("Unable to allocate memory for name buf\n");
return ERR_PTR(-ENOMEM);
}
snprintf(buf, strlen(name) + 1, "%s", name);
if (strstr(buf, "lun_") != buf) {
pr_err("Unable to locate \"lun_\" from buf: %s"
" name: %s\n", buf, name);
ret = -EINVAL;
goto out;
}
ret = kstrtoul(buf + 4, 0, &mapped_lun);
if (ret)
goto out;
if (mapped_lun > UINT_MAX) {
ret = -EINVAL;
goto out;
}
if (mapped_lun > (TRANSPORT_MAX_LUNS_PER_TPG-1)) {
pr_err("Mapped LUN: %lu exceeds TRANSPORT_MAX_LUNS_PER_TPG"
"-1: %u for Target Portal Group: %u\n", mapped_lun,
TRANSPORT_MAX_LUNS_PER_TPG-1,
se_tpg->se_tpg_tfo->tpg_get_tag(se_tpg));
ret = -EINVAL;
goto out;
}
lacl = core_dev_init_initiator_node_lun_acl(se_tpg, se_nacl,
mapped_lun, &ret);
if (!lacl) {
ret = -EINVAL;
goto out;
}
lacl_cg = &lacl->se_lun_group;
lacl_cg->default_groups = kmalloc(sizeof(struct config_group *) * 2,
GFP_KERNEL);
if (!lacl_cg->default_groups) {
pr_err("Unable to allocate lacl_cg->default_groups\n");
ret = -ENOMEM;
goto out;
}
config_group_init_type_name(&lacl->se_lun_group, name,
&TF_CIT_TMPL(tf)->tfc_tpg_mappedlun_cit);
config_group_init_type_name(&lacl->ml_stat_grps.stat_group,
"statistics", &TF_CIT_TMPL(tf)->tfc_tpg_mappedlun_stat_cit);
lacl_cg->default_groups[0] = &lacl->ml_stat_grps.stat_group;
lacl_cg->default_groups[1] = NULL;
ml_stat_grp = &lacl->ml_stat_grps.stat_group;
ml_stat_grp->default_groups = kmalloc(sizeof(struct config_group *) * 3,
GFP_KERNEL);
if (!ml_stat_grp->default_groups) {
pr_err("Unable to allocate ml_stat_grp->default_groups\n");
ret = -ENOMEM;
goto out;
}
target_stat_setup_mappedlun_default_groups(lacl);
kfree(buf);
return &lacl->se_lun_group;
out:
if (lacl_cg)
kfree(lacl_cg->default_groups);
kfree(buf);
return ERR_PTR(ret);
}
static void target_fabric_drop_mappedlun(
struct config_group *group,
struct config_item *item)
{
struct se_lun_acl *lacl = container_of(to_config_group(item),
struct se_lun_acl, se_lun_group);
struct config_item *df_item;
struct config_group *lacl_cg = NULL, *ml_stat_grp = NULL;
int i;
ml_stat_grp = &lacl->ml_stat_grps.stat_group;
for (i = 0; ml_stat_grp->default_groups[i]; i++) {
df_item = &ml_stat_grp->default_groups[i]->cg_item;
ml_stat_grp->default_groups[i] = NULL;
config_item_put(df_item);
}
kfree(ml_stat_grp->default_groups);
lacl_cg = &lacl->se_lun_group;
for (i = 0; lacl_cg->default_groups[i]; i++) {
df_item = &lacl_cg->default_groups[i]->cg_item;
lacl_cg->default_groups[i] = NULL;
config_item_put(df_item);
}
kfree(lacl_cg->default_groups);
config_item_put(item);
}
static void target_fabric_nacl_base_release(struct config_item *item)
{
struct se_node_acl *se_nacl = container_of(to_config_group(item),
struct se_node_acl, acl_group);
struct se_portal_group *se_tpg = se_nacl->se_tpg;
struct target_fabric_configfs *tf = se_tpg->se_tpg_wwn->wwn_tf;
tf->tf_ops.fabric_drop_nodeacl(se_nacl);
}
static struct config_group *target_fabric_make_nodeacl(
struct config_group *group,
const char *name)
{
struct se_portal_group *se_tpg = container_of(group,
struct se_portal_group, tpg_acl_group);
struct target_fabric_configfs *tf = se_tpg->se_tpg_wwn->wwn_tf;
struct se_node_acl *se_nacl;
struct config_group *nacl_cg;
if (!tf->tf_ops.fabric_make_nodeacl) {
pr_err("tf->tf_ops.fabric_make_nodeacl is NULL\n");
return ERR_PTR(-ENOSYS);
}
se_nacl = tf->tf_ops.fabric_make_nodeacl(se_tpg, group, name);
if (IS_ERR(se_nacl))
return ERR_CAST(se_nacl);
nacl_cg = &se_nacl->acl_group;
nacl_cg->default_groups = se_nacl->acl_default_groups;
nacl_cg->default_groups[0] = &se_nacl->acl_attrib_group;
nacl_cg->default_groups[1] = &se_nacl->acl_auth_group;
nacl_cg->default_groups[2] = &se_nacl->acl_param_group;
nacl_cg->default_groups[3] = &se_nacl->acl_fabric_stat_group;
nacl_cg->default_groups[4] = NULL;
config_group_init_type_name(&se_nacl->acl_group, name,
&TF_CIT_TMPL(tf)->tfc_tpg_nacl_base_cit);
config_group_init_type_name(&se_nacl->acl_attrib_group, "attrib",
&TF_CIT_TMPL(tf)->tfc_tpg_nacl_attrib_cit);
config_group_init_type_name(&se_nacl->acl_auth_group, "auth",
&TF_CIT_TMPL(tf)->tfc_tpg_nacl_auth_cit);
config_group_init_type_name(&se_nacl->acl_param_group, "param",
&TF_CIT_TMPL(tf)->tfc_tpg_nacl_param_cit);
config_group_init_type_name(&se_nacl->acl_fabric_stat_group,
"fabric_statistics",
&TF_CIT_TMPL(tf)->tfc_tpg_nacl_stat_cit);
return &se_nacl->acl_group;
}
static void target_fabric_drop_nodeacl(
struct config_group *group,
struct config_item *item)
{
struct se_node_acl *se_nacl = container_of(to_config_group(item),
struct se_node_acl, acl_group);
struct config_item *df_item;
struct config_group *nacl_cg;
int i;
nacl_cg = &se_nacl->acl_group;
for (i = 0; nacl_cg->default_groups[i]; i++) {
df_item = &nacl_cg->default_groups[i]->cg_item;
nacl_cg->default_groups[i] = NULL;
config_item_put(df_item);
}
config_item_put(item);
}
static void target_fabric_np_base_release(struct config_item *item)
{
struct se_tpg_np *se_tpg_np = container_of(to_config_group(item),
struct se_tpg_np, tpg_np_group);
struct se_portal_group *se_tpg = se_tpg_np->tpg_np_parent;
struct target_fabric_configfs *tf = se_tpg->se_tpg_wwn->wwn_tf;
tf->tf_ops.fabric_drop_np(se_tpg_np);
}
static struct config_group *target_fabric_make_np(
struct config_group *group,
const char *name)
{
struct se_portal_group *se_tpg = container_of(group,
struct se_portal_group, tpg_np_group);
struct target_fabric_configfs *tf = se_tpg->se_tpg_wwn->wwn_tf;
struct se_tpg_np *se_tpg_np;
if (!tf->tf_ops.fabric_make_np) {
pr_err("tf->tf_ops.fabric_make_np is NULL\n");
return ERR_PTR(-ENOSYS);
}
se_tpg_np = tf->tf_ops.fabric_make_np(se_tpg, group, name);
if (!se_tpg_np || IS_ERR(se_tpg_np))
return ERR_PTR(-EINVAL);
se_tpg_np->tpg_np_parent = se_tpg;
config_group_init_type_name(&se_tpg_np->tpg_np_group, name,
&TF_CIT_TMPL(tf)->tfc_tpg_np_base_cit);
return &se_tpg_np->tpg_np_group;
}
static void target_fabric_drop_np(
struct config_group *group,
struct config_item *item)
{
config_item_put(item);
}
static ssize_t target_fabric_port_show_attr_alua_tg_pt_gp(
struct se_lun *lun,
char *page)
{
if (!lun || !lun->lun_sep)
return -ENODEV;
return core_alua_show_tg_pt_gp_info(lun->lun_sep, page);
}
static ssize_t target_fabric_port_store_attr_alua_tg_pt_gp(
struct se_lun *lun,
const char *page,
size_t count)
{
if (!lun || !lun->lun_sep)
return -ENODEV;
return core_alua_store_tg_pt_gp_info(lun->lun_sep, page, count);
}
static ssize_t target_fabric_port_show_attr_alua_tg_pt_offline(
struct se_lun *lun,
char *page)
{
if (!lun || !lun->lun_sep)
return -ENODEV;
return core_alua_show_offline_bit(lun, page);
}
static ssize_t target_fabric_port_store_attr_alua_tg_pt_offline(
struct se_lun *lun,
const char *page,
size_t count)
{
if (!lun || !lun->lun_sep)
return -ENODEV;
return core_alua_store_offline_bit(lun, page, count);
}
static ssize_t target_fabric_port_show_attr_alua_tg_pt_status(
struct se_lun *lun,
char *page)
{
if (!lun || !lun->lun_sep)
return -ENODEV;
return core_alua_show_secondary_status(lun, page);
}
static ssize_t target_fabric_port_store_attr_alua_tg_pt_status(
struct se_lun *lun,
const char *page,
size_t count)
{
if (!lun || !lun->lun_sep)
return -ENODEV;
return core_alua_store_secondary_status(lun, page, count);
}
static ssize_t target_fabric_port_show_attr_alua_tg_pt_write_md(
struct se_lun *lun,
char *page)
{
if (!lun || !lun->lun_sep)
return -ENODEV;
return core_alua_show_secondary_write_metadata(lun, page);
}
static ssize_t target_fabric_port_store_attr_alua_tg_pt_write_md(
struct se_lun *lun,
const char *page,
size_t count)
{
if (!lun || !lun->lun_sep)
return -ENODEV;
return core_alua_store_secondary_write_metadata(lun, page, count);
}
static int target_fabric_port_link(
struct config_item *lun_ci,
struct config_item *se_dev_ci)
{
struct config_item *tpg_ci;
struct se_lun *lun = container_of(to_config_group(lun_ci),
struct se_lun, lun_group);
struct se_lun *lun_p;
struct se_portal_group *se_tpg;
struct se_device *dev =
container_of(to_config_group(se_dev_ci), struct se_device, dev_group);
struct target_fabric_configfs *tf;
int ret;
if (dev->dev_link_magic != SE_DEV_LINK_MAGIC) {
pr_err("Bad dev->dev_link_magic, not a valid se_dev_ci pointer:"
" %p to struct se_device: %p\n", se_dev_ci, dev);
return -EFAULT;
}
if (!(dev->dev_flags & DF_CONFIGURED)) {
pr_err("se_device not configured yet, cannot port link\n");
return -ENODEV;
}
tpg_ci = &lun_ci->ci_parent->ci_group->cg_item;
se_tpg = container_of(to_config_group(tpg_ci),
struct se_portal_group, tpg_group);
tf = se_tpg->se_tpg_wwn->wwn_tf;
if (lun->lun_se_dev != NULL) {
pr_err("Port Symlink already exists\n");
return -EEXIST;
}
lun_p = core_dev_add_lun(se_tpg, dev, lun->unpacked_lun);
if (IS_ERR(lun_p)) {
pr_err("core_dev_add_lun() failed\n");
ret = PTR_ERR(lun_p);
goto out;
}
if (tf->tf_ops.fabric_post_link) {
tf->tf_ops.fabric_post_link(se_tpg, lun);
}
return 0;
out:
return ret;
}
static int target_fabric_port_unlink(
struct config_item *lun_ci,
struct config_item *se_dev_ci)
{
struct se_lun *lun = container_of(to_config_group(lun_ci),
struct se_lun, lun_group);
struct se_portal_group *se_tpg = lun->lun_sep->sep_tpg;
struct target_fabric_configfs *tf = se_tpg->se_tpg_wwn->wwn_tf;
if (tf->tf_ops.fabric_pre_unlink) {
tf->tf_ops.fabric_pre_unlink(se_tpg, lun);
}
core_dev_del_lun(se_tpg, lun->unpacked_lun);
return 0;
}
static struct config_group *target_core_port_stat_mkdir(
struct config_group *group,
const char *name)
{
return ERR_PTR(-ENOSYS);
}
static void target_core_port_stat_rmdir(
struct config_group *group,
struct config_item *item)
{
return;
}
static struct config_group *target_fabric_make_lun(
struct config_group *group,
const char *name)
{
struct se_lun *lun;
struct se_portal_group *se_tpg = container_of(group,
struct se_portal_group, tpg_lun_group);
struct target_fabric_configfs *tf = se_tpg->se_tpg_wwn->wwn_tf;
struct config_group *lun_cg = NULL, *port_stat_grp = NULL;
unsigned long unpacked_lun;
int errno;
if (strstr(name, "lun_") != name) {
pr_err("Unable to locate \'_\" in"
" \"lun_$LUN_NUMBER\"\n");
return ERR_PTR(-EINVAL);
}
errno = kstrtoul(name + 4, 0, &unpacked_lun);
if (errno)
return ERR_PTR(errno);
if (unpacked_lun > UINT_MAX)
return ERR_PTR(-EINVAL);
lun = core_get_lun_from_tpg(se_tpg, unpacked_lun);
if (!lun)
return ERR_PTR(-EINVAL);
lun_cg = &lun->lun_group;
lun_cg->default_groups = kmalloc(sizeof(struct config_group *) * 2,
GFP_KERNEL);
if (!lun_cg->default_groups) {
pr_err("Unable to allocate lun_cg->default_groups\n");
return ERR_PTR(-ENOMEM);
}
config_group_init_type_name(&lun->lun_group, name,
&TF_CIT_TMPL(tf)->tfc_tpg_port_cit);
config_group_init_type_name(&lun->port_stat_grps.stat_group,
"statistics", &TF_CIT_TMPL(tf)->tfc_tpg_port_stat_cit);
lun_cg->default_groups[0] = &lun->port_stat_grps.stat_group;
lun_cg->default_groups[1] = NULL;
port_stat_grp = &lun->port_stat_grps.stat_group;
port_stat_grp->default_groups = kzalloc(sizeof(struct config_group) * 3,
GFP_KERNEL);
if (!port_stat_grp->default_groups) {
pr_err("Unable to allocate port_stat_grp->default_groups\n");
errno = -ENOMEM;
goto out;
}
target_stat_setup_port_default_groups(lun);
return &lun->lun_group;
out:
if (lun_cg)
kfree(lun_cg->default_groups);
return ERR_PTR(errno);
}
static void target_fabric_drop_lun(
struct config_group *group,
struct config_item *item)
{
struct se_lun *lun = container_of(to_config_group(item),
struct se_lun, lun_group);
struct config_item *df_item;
struct config_group *lun_cg, *port_stat_grp;
int i;
port_stat_grp = &lun->port_stat_grps.stat_group;
for (i = 0; port_stat_grp->default_groups[i]; i++) {
df_item = &port_stat_grp->default_groups[i]->cg_item;
port_stat_grp->default_groups[i] = NULL;
config_item_put(df_item);
}
kfree(port_stat_grp->default_groups);
lun_cg = &lun->lun_group;
for (i = 0; lun_cg->default_groups[i]; i++) {
df_item = &lun_cg->default_groups[i]->cg_item;
lun_cg->default_groups[i] = NULL;
config_item_put(df_item);
}
kfree(lun_cg->default_groups);
config_item_put(item);
}
static void target_fabric_tpg_release(struct config_item *item)
{
struct se_portal_group *se_tpg = container_of(to_config_group(item),
struct se_portal_group, tpg_group);
struct se_wwn *wwn = se_tpg->se_tpg_wwn;
struct target_fabric_configfs *tf = wwn->wwn_tf;
tf->tf_ops.fabric_drop_tpg(se_tpg);
}
static struct config_group *target_fabric_make_tpg(
struct config_group *group,
const char *name)
{
struct se_wwn *wwn = container_of(group, struct se_wwn, wwn_group);
struct target_fabric_configfs *tf = wwn->wwn_tf;
struct se_portal_group *se_tpg;
if (!tf->tf_ops.fabric_make_tpg) {
pr_err("tf->tf_ops.fabric_make_tpg is NULL\n");
return ERR_PTR(-ENOSYS);
}
se_tpg = tf->tf_ops.fabric_make_tpg(wwn, group, name);
if (!se_tpg || IS_ERR(se_tpg))
return ERR_PTR(-EINVAL);
se_tpg->tpg_group.default_groups = se_tpg->tpg_default_groups;
se_tpg->tpg_group.default_groups[0] = &se_tpg->tpg_lun_group;
se_tpg->tpg_group.default_groups[1] = &se_tpg->tpg_np_group;
se_tpg->tpg_group.default_groups[2] = &se_tpg->tpg_acl_group;
se_tpg->tpg_group.default_groups[3] = &se_tpg->tpg_attrib_group;
se_tpg->tpg_group.default_groups[4] = &se_tpg->tpg_auth_group;
se_tpg->tpg_group.default_groups[5] = &se_tpg->tpg_param_group;
se_tpg->tpg_group.default_groups[6] = NULL;
config_group_init_type_name(&se_tpg->tpg_group, name,
&TF_CIT_TMPL(tf)->tfc_tpg_base_cit);
config_group_init_type_name(&se_tpg->tpg_lun_group, "lun",
&TF_CIT_TMPL(tf)->tfc_tpg_lun_cit);
config_group_init_type_name(&se_tpg->tpg_np_group, "np",
&TF_CIT_TMPL(tf)->tfc_tpg_np_cit);
config_group_init_type_name(&se_tpg->tpg_acl_group, "acls",
&TF_CIT_TMPL(tf)->tfc_tpg_nacl_cit);
config_group_init_type_name(&se_tpg->tpg_attrib_group, "attrib",
&TF_CIT_TMPL(tf)->tfc_tpg_attrib_cit);
config_group_init_type_name(&se_tpg->tpg_auth_group, "auth",
&TF_CIT_TMPL(tf)->tfc_tpg_auth_cit);
config_group_init_type_name(&se_tpg->tpg_param_group, "param",
&TF_CIT_TMPL(tf)->tfc_tpg_param_cit);
return &se_tpg->tpg_group;
}
static void target_fabric_drop_tpg(
struct config_group *group,
struct config_item *item)
{
struct se_portal_group *se_tpg = container_of(to_config_group(item),
struct se_portal_group, tpg_group);
struct config_group *tpg_cg = &se_tpg->tpg_group;
struct config_item *df_item;
int i;
for (i = 0; tpg_cg->default_groups[i]; i++) {
df_item = &tpg_cg->default_groups[i]->cg_item;
tpg_cg->default_groups[i] = NULL;
config_item_put(df_item);
}
config_item_put(item);
}
static void target_fabric_release_wwn(struct config_item *item)
{
struct se_wwn *wwn = container_of(to_config_group(item),
struct se_wwn, wwn_group);
struct target_fabric_configfs *tf = wwn->wwn_tf;
tf->tf_ops.fabric_drop_wwn(wwn);
}
static struct config_group *target_fabric_make_wwn(
struct config_group *group,
const char *name)
{
struct target_fabric_configfs *tf = container_of(group,
struct target_fabric_configfs, tf_group);
struct se_wwn *wwn;
if (!tf->tf_ops.fabric_make_wwn) {
pr_err("tf->tf_ops.fabric_make_wwn is NULL\n");
return ERR_PTR(-ENOSYS);
}
wwn = tf->tf_ops.fabric_make_wwn(tf, group, name);
if (!wwn || IS_ERR(wwn))
return ERR_PTR(-EINVAL);
wwn->wwn_tf = tf;
wwn->wwn_group.default_groups = wwn->wwn_default_groups;
wwn->wwn_group.default_groups[0] = &wwn->fabric_stat_group;
wwn->wwn_group.default_groups[1] = NULL;
config_group_init_type_name(&wwn->wwn_group, name,
&TF_CIT_TMPL(tf)->tfc_tpg_cit);
config_group_init_type_name(&wwn->fabric_stat_group, "fabric_statistics",
&TF_CIT_TMPL(tf)->tfc_wwn_fabric_stats_cit);
return &wwn->wwn_group;
}
static void target_fabric_drop_wwn(
struct config_group *group,
struct config_item *item)
{
struct se_wwn *wwn = container_of(to_config_group(item),
struct se_wwn, wwn_group);
struct config_item *df_item;
struct config_group *cg = &wwn->wwn_group;
int i;
for (i = 0; cg->default_groups[i]; i++) {
df_item = &cg->default_groups[i]->cg_item;
cg->default_groups[i] = NULL;
config_item_put(df_item);
}
config_item_put(item);
}
int target_fabric_setup_cits(struct target_fabric_configfs *tf)
{
target_fabric_setup_discovery_cit(tf);
target_fabric_setup_wwn_cit(tf);
target_fabric_setup_wwn_fabric_stats_cit(tf);
target_fabric_setup_tpg_cit(tf);
target_fabric_setup_tpg_base_cit(tf);
target_fabric_setup_tpg_port_cit(tf);
target_fabric_setup_tpg_port_stat_cit(tf);
target_fabric_setup_tpg_lun_cit(tf);
target_fabric_setup_tpg_np_cit(tf);
target_fabric_setup_tpg_np_base_cit(tf);
target_fabric_setup_tpg_attrib_cit(tf);
target_fabric_setup_tpg_auth_cit(tf);
target_fabric_setup_tpg_param_cit(tf);
target_fabric_setup_tpg_nacl_cit(tf);
target_fabric_setup_tpg_nacl_base_cit(tf);
target_fabric_setup_tpg_nacl_attrib_cit(tf);
target_fabric_setup_tpg_nacl_auth_cit(tf);
target_fabric_setup_tpg_nacl_param_cit(tf);
target_fabric_setup_tpg_nacl_stat_cit(tf);
target_fabric_setup_tpg_mappedlun_cit(tf);
target_fabric_setup_tpg_mappedlun_stat_cit(tf);
return 0;
}
