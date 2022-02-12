static ssize_t ft_parse_wwn(const char *name, u64 *wwn, int strict)
{
const char *cp;
char c;
u32 byte = 0;
u32 pos = 0;
u32 err;
int val;
*wwn = 0;
for (cp = name; cp < &name[FT_NAMELEN - 1]; cp++) {
c = *cp;
if (c == '\n' && cp[1] == '\0')
continue;
if (strict && pos++ == 2 && byte++ < 7) {
pos = 0;
if (c == ':')
continue;
err = 1;
goto fail;
}
if (c == '\0') {
err = 2;
if (strict && byte != 8)
goto fail;
return cp - name;
}
err = 3;
val = hex_to_bin(c);
if (val < 0 || (strict && isupper(c)))
goto fail;
*wwn = (*wwn << 4) | val;
}
err = 4;
fail:
pr_debug("err %u len %zu pos %u byte %u\n",
err, cp - name, pos, byte);
return -1;
}
ssize_t ft_format_wwn(char *buf, size_t len, u64 wwn)
{
u8 b[8];
put_unaligned_be64(wwn, b);
return snprintf(buf, len,
"%2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x",
b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7]);
}
static ssize_t ft_wwn_show(void *arg, char *buf)
{
u64 *wwn = arg;
ssize_t len;
len = ft_format_wwn(buf, PAGE_SIZE - 2, *wwn);
buf[len++] = '\n';
return len;
}
static ssize_t ft_wwn_store(void *arg, const char *buf, size_t len)
{
ssize_t ret;
u64 wwn;
ret = ft_parse_wwn(buf, &wwn, 0);
if (ret > 0)
*(u64 *)arg = wwn;
return ret;
}
static ssize_t ft_nacl_show_port_name(
struct se_node_acl *se_nacl,
char *page)
{
struct ft_node_acl *acl = container_of(se_nacl,
struct ft_node_acl, se_node_acl);
return ft_wwn_show(&acl->node_auth.port_name, page);
}
static ssize_t ft_nacl_store_port_name(
struct se_node_acl *se_nacl,
const char *page,
size_t count)
{
struct ft_node_acl *acl = container_of(se_nacl,
struct ft_node_acl, se_node_acl);
return ft_wwn_store(&acl->node_auth.port_name, page, count);
}
static ssize_t ft_nacl_show_node_name(
struct se_node_acl *se_nacl,
char *page)
{
struct ft_node_acl *acl = container_of(se_nacl,
struct ft_node_acl, se_node_acl);
return ft_wwn_show(&acl->node_auth.node_name, page);
}
static ssize_t ft_nacl_store_node_name(
struct se_node_acl *se_nacl,
const char *page,
size_t count)
{
struct ft_node_acl *acl = container_of(se_nacl,
struct ft_node_acl, se_node_acl);
return ft_wwn_store(&acl->node_auth.node_name, page, count);
}
static struct se_node_acl *ft_add_acl(
struct se_portal_group *se_tpg,
struct config_group *group,
const char *name)
{
struct ft_node_acl *acl;
struct ft_tpg *tpg;
u64 wwpn;
u32 q_depth;
pr_debug("add acl %s\n", name);
tpg = container_of(se_tpg, struct ft_tpg, se_tpg);
if (ft_parse_wwn(name, &wwpn, 1) < 0)
return ERR_PTR(-EINVAL);
acl = kzalloc(sizeof(struct ft_node_acl), GFP_KERNEL);
if (!acl)
return ERR_PTR(-ENOMEM);
acl->node_auth.port_name = wwpn;
q_depth = 32;
return core_tpg_add_initiator_node_acl(&tpg->se_tpg,
&acl->se_node_acl, name, q_depth);
}
static void ft_del_acl(struct se_node_acl *se_acl)
{
struct se_portal_group *se_tpg = se_acl->se_tpg;
struct ft_tpg *tpg;
struct ft_node_acl *acl = container_of(se_acl,
struct ft_node_acl, se_node_acl);
pr_debug("del acl %s\n",
config_item_name(&se_acl->acl_group.cg_item));
tpg = container_of(se_tpg, struct ft_tpg, se_tpg);
pr_debug("del acl %p se_acl %p tpg %p se_tpg %p\n",
acl, se_acl, tpg, &tpg->se_tpg);
core_tpg_del_initiator_node_acl(&tpg->se_tpg, se_acl, 1);
kfree(acl);
}
struct ft_node_acl *ft_acl_get(struct ft_tpg *tpg, struct fc_rport_priv *rdata)
{
struct ft_node_acl *found = NULL;
struct ft_node_acl *acl;
struct se_portal_group *se_tpg = &tpg->se_tpg;
struct se_node_acl *se_acl;
spin_lock_irq(&se_tpg->acl_node_lock);
list_for_each_entry(se_acl, &se_tpg->acl_node_list, acl_list) {
acl = container_of(se_acl, struct ft_node_acl, se_node_acl);
pr_debug("acl %p port_name %llx\n",
acl, (unsigned long long)acl->node_auth.port_name);
if (acl->node_auth.port_name == rdata->ids.port_name ||
acl->node_auth.node_name == rdata->ids.node_name) {
pr_debug("acl %p port_name %llx matched\n", acl,
(unsigned long long)rdata->ids.port_name);
found = acl;
break;
}
}
spin_unlock_irq(&se_tpg->acl_node_lock);
return found;
}
struct se_node_acl *ft_tpg_alloc_fabric_acl(struct se_portal_group *se_tpg)
{
struct ft_node_acl *acl;
acl = kzalloc(sizeof(*acl), GFP_KERNEL);
if (!acl) {
pr_err("Unable to allocate struct ft_node_acl\n");
return NULL;
}
pr_debug("acl %p\n", acl);
return &acl->se_node_acl;
}
static void ft_tpg_release_fabric_acl(struct se_portal_group *se_tpg,
struct se_node_acl *se_acl)
{
struct ft_node_acl *acl = container_of(se_acl,
struct ft_node_acl, se_node_acl);
pr_debug("acl %p\n", acl);
kfree(acl);
}
static struct se_portal_group *ft_add_tpg(
struct se_wwn *wwn,
struct config_group *group,
const char *name)
{
struct ft_lport_acl *lacl;
struct ft_tpg *tpg;
struct workqueue_struct *wq;
unsigned long index;
int ret;
pr_debug("tcm_fc: add tpg %s\n", name);
if (strstr(name, "tpgt_") != name)
return NULL;
if (strict_strtoul(name + 5, 10, &index) || index > UINT_MAX)
return NULL;
lacl = container_of(wwn, struct ft_lport_acl, fc_lport_wwn);
tpg = kzalloc(sizeof(*tpg), GFP_KERNEL);
if (!tpg)
return NULL;
tpg->index = index;
tpg->lport_acl = lacl;
INIT_LIST_HEAD(&tpg->lun_list);
wq = alloc_workqueue("tcm_fc", 0, 1);
if (!wq) {
kfree(tpg);
return NULL;
}
ret = core_tpg_register(&ft_configfs->tf_ops, wwn, &tpg->se_tpg,
tpg, TRANSPORT_TPG_TYPE_NORMAL);
if (ret < 0) {
destroy_workqueue(wq);
kfree(tpg);
return NULL;
}
tpg->workqueue = wq;
mutex_lock(&ft_lport_lock);
list_add_tail(&tpg->list, &lacl->tpg_list);
mutex_unlock(&ft_lport_lock);
return &tpg->se_tpg;
}
static void ft_del_tpg(struct se_portal_group *se_tpg)
{
struct ft_tpg *tpg = container_of(se_tpg, struct ft_tpg, se_tpg);
pr_debug("del tpg %s\n",
config_item_name(&tpg->se_tpg.tpg_group.cg_item));
destroy_workqueue(tpg->workqueue);
synchronize_rcu();
mutex_lock(&ft_lport_lock);
list_del(&tpg->list);
if (tpg->tport) {
tpg->tport->tpg = NULL;
tpg->tport = NULL;
}
mutex_unlock(&ft_lport_lock);
core_tpg_deregister(se_tpg);
kfree(tpg);
}
struct ft_tpg *ft_lport_find_tpg(struct fc_lport *lport)
{
struct ft_lport_acl *lacl;
struct ft_tpg *tpg;
list_for_each_entry(lacl, &ft_lport_list, list) {
if (lacl->wwpn == lport->wwpn) {
list_for_each_entry(tpg, &lacl->tpg_list, list)
return tpg;
return NULL;
}
}
return NULL;
}
static struct se_wwn *ft_add_lport(
struct target_fabric_configfs *tf,
struct config_group *group,
const char *name)
{
struct ft_lport_acl *lacl;
struct ft_lport_acl *old_lacl;
u64 wwpn;
pr_debug("add lport %s\n", name);
if (ft_parse_wwn(name, &wwpn, 1) < 0)
return NULL;
lacl = kzalloc(sizeof(*lacl), GFP_KERNEL);
if (!lacl)
return NULL;
lacl->wwpn = wwpn;
INIT_LIST_HEAD(&lacl->tpg_list);
mutex_lock(&ft_lport_lock);
list_for_each_entry(old_lacl, &ft_lport_list, list) {
if (old_lacl->wwpn == wwpn) {
mutex_unlock(&ft_lport_lock);
kfree(lacl);
return NULL;
}
}
list_add_tail(&lacl->list, &ft_lport_list);
ft_format_wwn(lacl->name, sizeof(lacl->name), wwpn);
mutex_unlock(&ft_lport_lock);
return &lacl->fc_lport_wwn;
}
static void ft_del_lport(struct se_wwn *wwn)
{
struct ft_lport_acl *lacl = container_of(wwn,
struct ft_lport_acl, fc_lport_wwn);
pr_debug("del lport %s\n", lacl->name);
mutex_lock(&ft_lport_lock);
list_del(&lacl->list);
mutex_unlock(&ft_lport_lock);
kfree(lacl);
}
static ssize_t ft_wwn_show_attr_version(
struct target_fabric_configfs *tf,
char *page)
{
return sprintf(page, "TCM FC " FT_VERSION " on %s/%s on "
""UTS_RELEASE"\n", utsname()->sysname, utsname()->machine);
}
static char *ft_get_fabric_name(void)
{
return "fc";
}
static char *ft_get_fabric_wwn(struct se_portal_group *se_tpg)
{
struct ft_tpg *tpg = se_tpg->se_tpg_fabric_ptr;
return tpg->lport_acl->name;
}
static u16 ft_get_tag(struct se_portal_group *se_tpg)
{
struct ft_tpg *tpg = se_tpg->se_tpg_fabric_ptr;
return tpg->index;
}
static u32 ft_get_default_depth(struct se_portal_group *se_tpg)
{
return 1;
}
static int ft_check_false(struct se_portal_group *se_tpg)
{
return 0;
}
static void ft_set_default_node_attr(struct se_node_acl *se_nacl)
{
}
static u32 ft_tpg_get_inst_index(struct se_portal_group *se_tpg)
{
struct ft_tpg *tpg = se_tpg->se_tpg_fabric_ptr;
return tpg->index;
}
int ft_register_configfs(void)
{
struct target_fabric_configfs *fabric;
int ret;
fabric = target_fabric_configfs_init(THIS_MODULE, "fc");
if (IS_ERR(fabric)) {
pr_err("%s: target_fabric_configfs_init() failed!\n",
__func__);
return PTR_ERR(fabric);
}
fabric->tf_ops = ft_fabric_ops;
TF_CIT_TMPL(fabric)->tfc_wwn_cit.ct_attrs = ft_wwn_attrs;
TF_CIT_TMPL(fabric)->tfc_tpg_base_cit.ct_attrs = NULL;
TF_CIT_TMPL(fabric)->tfc_tpg_attrib_cit.ct_attrs = NULL;
TF_CIT_TMPL(fabric)->tfc_tpg_param_cit.ct_attrs = NULL;
TF_CIT_TMPL(fabric)->tfc_tpg_np_base_cit.ct_attrs = NULL;
TF_CIT_TMPL(fabric)->tfc_tpg_nacl_base_cit.ct_attrs =
ft_nacl_base_attrs;
TF_CIT_TMPL(fabric)->tfc_tpg_nacl_attrib_cit.ct_attrs = NULL;
TF_CIT_TMPL(fabric)->tfc_tpg_nacl_auth_cit.ct_attrs = NULL;
TF_CIT_TMPL(fabric)->tfc_tpg_nacl_param_cit.ct_attrs = NULL;
ret = target_fabric_configfs_register(fabric);
if (ret < 0) {
pr_debug("target_fabric_configfs_register() for"
" FC Target failed!\n");
target_fabric_configfs_free(fabric);
return -1;
}
ft_configfs = fabric;
return 0;
}
void ft_deregister_configfs(void)
{
if (!ft_configfs)
return;
target_fabric_configfs_deregister(ft_configfs);
ft_configfs = NULL;
}
static int __init ft_init(void)
{
if (ft_register_configfs())
return -1;
if (fc_fc4_register_provider(FC_TYPE_FCP, &ft_prov)) {
ft_deregister_configfs();
return -1;
}
blocking_notifier_chain_register(&fc_lport_notifier_head, &ft_notifier);
fc_lport_iterate(ft_lport_add, NULL);
return 0;
}
static void __exit ft_exit(void)
{
blocking_notifier_chain_unregister(&fc_lport_notifier_head,
&ft_notifier);
fc_fc4_deregister_provider(FC_TYPE_FCP, &ft_prov);
fc_lport_iterate(ft_lport_del, NULL);
ft_deregister_configfs();
synchronize_rcu();
}
