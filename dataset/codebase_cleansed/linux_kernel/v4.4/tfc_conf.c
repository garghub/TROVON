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
static ssize_t ft_nacl_port_name_show(struct config_item *item, char *page)
{
struct se_node_acl *se_nacl = acl_to_nacl(item);
struct ft_node_acl *acl = container_of(se_nacl,
struct ft_node_acl, se_node_acl);
return ft_wwn_show(&acl->node_auth.port_name, page);
}
static ssize_t ft_nacl_port_name_store(struct config_item *item,
const char *page, size_t count)
{
struct se_node_acl *se_nacl = acl_to_nacl(item);
struct ft_node_acl *acl = container_of(se_nacl,
struct ft_node_acl, se_node_acl);
return ft_wwn_store(&acl->node_auth.port_name, page, count);
}
static ssize_t ft_nacl_node_name_show(struct config_item *item,
char *page)
{
struct se_node_acl *se_nacl = acl_to_nacl(item);
struct ft_node_acl *acl = container_of(se_nacl,
struct ft_node_acl, se_node_acl);
return ft_wwn_show(&acl->node_auth.node_name, page);
}
static ssize_t ft_nacl_node_name_store(struct config_item *item,
const char *page, size_t count)
{
struct se_node_acl *se_nacl = acl_to_nacl(item);
struct ft_node_acl *acl = container_of(se_nacl,
struct ft_node_acl, se_node_acl);
return ft_wwn_store(&acl->node_auth.node_name, page, count);
}
static int ft_init_nodeacl(struct se_node_acl *nacl, const char *name)
{
struct ft_node_acl *acl =
container_of(nacl, struct ft_node_acl, se_node_acl);
u64 wwpn;
if (ft_parse_wwn(name, &wwpn, 1) < 0)
return -EINVAL;
acl->node_auth.port_name = wwpn;
return 0;
}
struct ft_node_acl *ft_acl_get(struct ft_tpg *tpg, struct fc_rport_priv *rdata)
{
struct ft_node_acl *found = NULL;
struct ft_node_acl *acl;
struct se_portal_group *se_tpg = &tpg->se_tpg;
struct se_node_acl *se_acl;
mutex_lock(&se_tpg->acl_node_mutex);
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
mutex_unlock(&se_tpg->acl_node_mutex);
return found;
}
static struct se_portal_group *ft_add_tpg(
struct se_wwn *wwn,
struct config_group *group,
const char *name)
{
struct ft_lport_wwn *ft_wwn;
struct ft_tpg *tpg;
struct workqueue_struct *wq;
unsigned long index;
int ret;
pr_debug("tcm_fc: add tpg %s\n", name);
if (strstr(name, "tpgt_") != name)
return NULL;
ret = kstrtoul(name + 5, 10, &index);
if (ret)
return NULL;
if (index > UINT_MAX)
return NULL;
if ((index != 1)) {
pr_err("Error, a single TPG=1 is used for HW port mappings\n");
return ERR_PTR(-ENOSYS);
}
ft_wwn = container_of(wwn, struct ft_lport_wwn, se_wwn);
tpg = kzalloc(sizeof(*tpg), GFP_KERNEL);
if (!tpg)
return NULL;
tpg->index = index;
tpg->lport_wwn = ft_wwn;
INIT_LIST_HEAD(&tpg->lun_list);
wq = alloc_workqueue("tcm_fc", 0, 1);
if (!wq) {
kfree(tpg);
return NULL;
}
ret = core_tpg_register(wwn, &tpg->se_tpg, SCSI_PROTOCOL_FCP);
if (ret < 0) {
destroy_workqueue(wq);
kfree(tpg);
return NULL;
}
tpg->workqueue = wq;
mutex_lock(&ft_lport_lock);
ft_wwn->tpg = tpg;
mutex_unlock(&ft_lport_lock);
return &tpg->se_tpg;
}
static void ft_del_tpg(struct se_portal_group *se_tpg)
{
struct ft_tpg *tpg = container_of(se_tpg, struct ft_tpg, se_tpg);
struct ft_lport_wwn *ft_wwn = tpg->lport_wwn;
pr_debug("del tpg %s\n",
config_item_name(&tpg->se_tpg.tpg_group.cg_item));
destroy_workqueue(tpg->workqueue);
synchronize_rcu();
mutex_lock(&ft_lport_lock);
ft_wwn->tpg = NULL;
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
struct ft_lport_wwn *ft_wwn;
list_for_each_entry(ft_wwn, &ft_wwn_list, ft_wwn_node) {
if (ft_wwn->wwpn == lport->wwpn)
return ft_wwn->tpg;
}
return NULL;
}
static struct se_wwn *ft_add_wwn(
struct target_fabric_configfs *tf,
struct config_group *group,
const char *name)
{
struct ft_lport_wwn *ft_wwn;
struct ft_lport_wwn *old_ft_wwn;
u64 wwpn;
pr_debug("add wwn %s\n", name);
if (ft_parse_wwn(name, &wwpn, 1) < 0)
return NULL;
ft_wwn = kzalloc(sizeof(*ft_wwn), GFP_KERNEL);
if (!ft_wwn)
return NULL;
ft_wwn->wwpn = wwpn;
mutex_lock(&ft_lport_lock);
list_for_each_entry(old_ft_wwn, &ft_wwn_list, ft_wwn_node) {
if (old_ft_wwn->wwpn == wwpn) {
mutex_unlock(&ft_lport_lock);
kfree(ft_wwn);
return NULL;
}
}
list_add_tail(&ft_wwn->ft_wwn_node, &ft_wwn_list);
ft_format_wwn(ft_wwn->name, sizeof(ft_wwn->name), wwpn);
mutex_unlock(&ft_lport_lock);
return &ft_wwn->se_wwn;
}
static void ft_del_wwn(struct se_wwn *wwn)
{
struct ft_lport_wwn *ft_wwn = container_of(wwn,
struct ft_lport_wwn, se_wwn);
pr_debug("del wwn %s\n", ft_wwn->name);
mutex_lock(&ft_lport_lock);
list_del(&ft_wwn->ft_wwn_node);
mutex_unlock(&ft_lport_lock);
kfree(ft_wwn);
}
static ssize_t ft_wwn_version_show(struct config_item *item, char *page)
{
return sprintf(page, "TCM FC " FT_VERSION " on %s/%s on "
""UTS_RELEASE"\n", utsname()->sysname, utsname()->machine);
}
static inline struct ft_tpg *ft_tpg(struct se_portal_group *se_tpg)
{
return container_of(se_tpg, struct ft_tpg, se_tpg);
}
static char *ft_get_fabric_name(void)
{
return "fc";
}
static char *ft_get_fabric_wwn(struct se_portal_group *se_tpg)
{
return ft_tpg(se_tpg)->lport_wwn->name;
}
static u16 ft_get_tag(struct se_portal_group *se_tpg)
{
return ft_tpg(se_tpg)->index;
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
return ft_tpg(se_tpg)->index;
}
static int __init ft_init(void)
{
int ret;
ret = target_register_template(&ft_fabric_ops);
if (ret)
goto out;
ret = fc_fc4_register_provider(FC_TYPE_FCP, &ft_prov);
if (ret)
goto out_unregister_template;
blocking_notifier_chain_register(&fc_lport_notifier_head, &ft_notifier);
fc_lport_iterate(ft_lport_add, NULL);
return 0;
out_unregister_template:
target_unregister_template(&ft_fabric_ops);
out:
return ret;
}
static void __exit ft_exit(void)
{
blocking_notifier_chain_unregister(&fc_lport_notifier_head,
&ft_notifier);
fc_fc4_deregister_provider(FC_TYPE_FCP, &ft_prov);
fc_lport_iterate(ft_lport_del, NULL);
target_unregister_template(&ft_fabric_ops);
synchronize_rcu();
}
