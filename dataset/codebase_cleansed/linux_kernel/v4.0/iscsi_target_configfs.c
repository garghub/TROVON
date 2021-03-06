static ssize_t lio_target_np_show_sctp(
struct se_tpg_np *se_tpg_np,
char *page)
{
struct iscsi_tpg_np *tpg_np = container_of(se_tpg_np,
struct iscsi_tpg_np, se_tpg_np);
struct iscsi_tpg_np *tpg_np_sctp;
ssize_t rb;
tpg_np_sctp = iscsit_tpg_locate_child_np(tpg_np, ISCSI_SCTP_TCP);
if (tpg_np_sctp)
rb = sprintf(page, "1\n");
else
rb = sprintf(page, "0\n");
return rb;
}
static ssize_t lio_target_np_store_sctp(
struct se_tpg_np *se_tpg_np,
const char *page,
size_t count)
{
struct iscsi_np *np;
struct iscsi_portal_group *tpg;
struct iscsi_tpg_np *tpg_np = container_of(se_tpg_np,
struct iscsi_tpg_np, se_tpg_np);
struct iscsi_tpg_np *tpg_np_sctp = NULL;
u32 op;
int ret;
ret = kstrtou32(page, 0, &op);
if (ret)
return ret;
if ((op != 1) && (op != 0)) {
pr_err("Illegal value for tpg_enable: %u\n", op);
return -EINVAL;
}
np = tpg_np->tpg_np;
if (!np) {
pr_err("Unable to locate struct iscsi_np from"
" struct iscsi_tpg_np\n");
return -EINVAL;
}
tpg = tpg_np->tpg;
if (iscsit_get_tpg(tpg) < 0)
return -EINVAL;
if (op) {
tpg_np_sctp = iscsit_tpg_add_network_portal(tpg, &np->np_sockaddr,
np->np_ip, tpg_np, ISCSI_SCTP_TCP);
if (!tpg_np_sctp || IS_ERR(tpg_np_sctp))
goto out;
} else {
tpg_np_sctp = iscsit_tpg_locate_child_np(tpg_np, ISCSI_SCTP_TCP);
if (!tpg_np_sctp)
goto out;
ret = iscsit_tpg_del_network_portal(tpg, tpg_np_sctp);
if (ret < 0)
goto out;
}
iscsit_put_tpg(tpg);
return count;
out:
iscsit_put_tpg(tpg);
return -EINVAL;
}
static ssize_t lio_target_np_show_iser(
struct se_tpg_np *se_tpg_np,
char *page)
{
struct iscsi_tpg_np *tpg_np = container_of(se_tpg_np,
struct iscsi_tpg_np, se_tpg_np);
struct iscsi_tpg_np *tpg_np_iser;
ssize_t rb;
tpg_np_iser = iscsit_tpg_locate_child_np(tpg_np, ISCSI_INFINIBAND);
if (tpg_np_iser)
rb = sprintf(page, "1\n");
else
rb = sprintf(page, "0\n");
return rb;
}
static ssize_t lio_target_np_store_iser(
struct se_tpg_np *se_tpg_np,
const char *page,
size_t count)
{
struct iscsi_np *np;
struct iscsi_portal_group *tpg;
struct iscsi_tpg_np *tpg_np = container_of(se_tpg_np,
struct iscsi_tpg_np, se_tpg_np);
struct iscsi_tpg_np *tpg_np_iser = NULL;
char *endptr;
u32 op;
int rc = 0;
op = simple_strtoul(page, &endptr, 0);
if ((op != 1) && (op != 0)) {
pr_err("Illegal value for tpg_enable: %u\n", op);
return -EINVAL;
}
np = tpg_np->tpg_np;
if (!np) {
pr_err("Unable to locate struct iscsi_np from"
" struct iscsi_tpg_np\n");
return -EINVAL;
}
tpg = tpg_np->tpg;
if (iscsit_get_tpg(tpg) < 0)
return -EINVAL;
if (op) {
rc = request_module("ib_isert");
if (rc != 0) {
pr_warn("Unable to request_module for ib_isert\n");
rc = 0;
}
tpg_np_iser = iscsit_tpg_add_network_portal(tpg, &np->np_sockaddr,
np->np_ip, tpg_np, ISCSI_INFINIBAND);
if (IS_ERR(tpg_np_iser)) {
rc = PTR_ERR(tpg_np_iser);
goto out;
}
} else {
tpg_np_iser = iscsit_tpg_locate_child_np(tpg_np, ISCSI_INFINIBAND);
if (tpg_np_iser) {
rc = iscsit_tpg_del_network_portal(tpg, tpg_np_iser);
if (rc < 0)
goto out;
}
}
iscsit_put_tpg(tpg);
return count;
out:
iscsit_put_tpg(tpg);
return rc;
}
static struct se_tpg_np *lio_target_call_addnptotpg(
struct se_portal_group *se_tpg,
struct config_group *group,
const char *name)
{
struct iscsi_portal_group *tpg;
struct iscsi_tpg_np *tpg_np;
char *str, *str2, *ip_str, *port_str;
struct __kernel_sockaddr_storage sockaddr;
struct sockaddr_in *sock_in;
struct sockaddr_in6 *sock_in6;
unsigned long port;
int ret;
char buf[MAX_PORTAL_LEN + 1];
if (strlen(name) > MAX_PORTAL_LEN) {
pr_err("strlen(name): %d exceeds MAX_PORTAL_LEN: %d\n",
(int)strlen(name), MAX_PORTAL_LEN);
return ERR_PTR(-EOVERFLOW);
}
memset(buf, 0, MAX_PORTAL_LEN + 1);
snprintf(buf, MAX_PORTAL_LEN + 1, "%s", name);
memset(&sockaddr, 0, sizeof(struct __kernel_sockaddr_storage));
str = strstr(buf, "[");
if (str) {
const char *end;
str2 = strstr(str, "]");
if (!str2) {
pr_err("Unable to locate trailing \"]\""
" in IPv6 iSCSI network portal address\n");
return ERR_PTR(-EINVAL);
}
str++;
*str2 = '\0';
str2++;
port_str = strstr(str2, ":");
if (!port_str) {
pr_err("Unable to locate \":port\""
" in IPv6 iSCSI network portal address\n");
return ERR_PTR(-EINVAL);
}
*port_str = '\0';
port_str++;
ret = kstrtoul(port_str, 0, &port);
if (ret < 0) {
pr_err("kstrtoul() failed for port_str: %d\n", ret);
return ERR_PTR(ret);
}
sock_in6 = (struct sockaddr_in6 *)&sockaddr;
sock_in6->sin6_family = AF_INET6;
sock_in6->sin6_port = htons((unsigned short)port);
ret = in6_pton(str, IPV6_ADDRESS_SPACE,
(void *)&sock_in6->sin6_addr.in6_u, -1, &end);
if (ret <= 0) {
pr_err("in6_pton returned: %d\n", ret);
return ERR_PTR(-EINVAL);
}
} else {
str = ip_str = &buf[0];
port_str = strstr(ip_str, ":");
if (!port_str) {
pr_err("Unable to locate \":port\""
" in IPv4 iSCSI network portal address\n");
return ERR_PTR(-EINVAL);
}
*port_str = '\0';
port_str++;
ret = kstrtoul(port_str, 0, &port);
if (ret < 0) {
pr_err("kstrtoul() failed for port_str: %d\n", ret);
return ERR_PTR(ret);
}
sock_in = (struct sockaddr_in *)&sockaddr;
sock_in->sin_family = AF_INET;
sock_in->sin_port = htons((unsigned short)port);
sock_in->sin_addr.s_addr = in_aton(ip_str);
}
tpg = container_of(se_tpg, struct iscsi_portal_group, tpg_se_tpg);
ret = iscsit_get_tpg(tpg);
if (ret < 0)
return ERR_PTR(-EINVAL);
pr_debug("LIO_Target_ConfigFS: REGISTER -> %s TPGT: %hu"
" PORTAL: %s\n",
config_item_name(&se_tpg->se_tpg_wwn->wwn_group.cg_item),
tpg->tpgt, name);
tpg_np = iscsit_tpg_add_network_portal(tpg, &sockaddr, str, NULL,
ISCSI_TCP);
if (IS_ERR(tpg_np)) {
iscsit_put_tpg(tpg);
return ERR_CAST(tpg_np);
}
pr_debug("LIO_Target_ConfigFS: addnptotpg done!\n");
iscsit_put_tpg(tpg);
return &tpg_np->se_tpg_np;
}
static void lio_target_call_delnpfromtpg(
struct se_tpg_np *se_tpg_np)
{
struct iscsi_portal_group *tpg;
struct iscsi_tpg_np *tpg_np;
struct se_portal_group *se_tpg;
int ret;
tpg_np = container_of(se_tpg_np, struct iscsi_tpg_np, se_tpg_np);
tpg = tpg_np->tpg;
ret = iscsit_get_tpg(tpg);
if (ret < 0)
return;
se_tpg = &tpg->tpg_se_tpg;
pr_debug("LIO_Target_ConfigFS: DEREGISTER -> %s TPGT: %hu"
" PORTAL: %s:%hu\n", config_item_name(&se_tpg->se_tpg_wwn->wwn_group.cg_item),
tpg->tpgt, tpg_np->tpg_np->np_ip, tpg_np->tpg_np->np_port);
ret = iscsit_tpg_del_network_portal(tpg, tpg_np);
if (ret < 0)
goto out;
pr_debug("LIO_Target_ConfigFS: delnpfromtpg done!\n");
out:
iscsit_put_tpg(tpg);
}
static ssize_t lio_target_nacl_show_info(
struct se_node_acl *se_nacl,
char *page)
{
struct iscsi_session *sess;
struct iscsi_conn *conn;
struct se_session *se_sess;
ssize_t rb = 0;
spin_lock_bh(&se_nacl->nacl_sess_lock);
se_sess = se_nacl->nacl_sess;
if (!se_sess) {
rb += sprintf(page+rb, "No active iSCSI Session for Initiator"
" Endpoint: %s\n", se_nacl->initiatorname);
} else {
sess = se_sess->fabric_sess_ptr;
rb += sprintf(page+rb, "InitiatorName: %s\n",
sess->sess_ops->InitiatorName);
rb += sprintf(page+rb, "InitiatorAlias: %s\n",
sess->sess_ops->InitiatorAlias);
rb += sprintf(page+rb,
"LIO Session ID: %u ISID: 0x%6ph TSIH: %hu ",
sess->sid, sess->isid, sess->tsih);
rb += sprintf(page+rb, "SessionType: %s\n",
(sess->sess_ops->SessionType) ?
"Discovery" : "Normal");
rb += sprintf(page+rb, "Session State: ");
switch (sess->session_state) {
case TARG_SESS_STATE_FREE:
rb += sprintf(page+rb, "TARG_SESS_FREE\n");
break;
case TARG_SESS_STATE_ACTIVE:
rb += sprintf(page+rb, "TARG_SESS_STATE_ACTIVE\n");
break;
case TARG_SESS_STATE_LOGGED_IN:
rb += sprintf(page+rb, "TARG_SESS_STATE_LOGGED_IN\n");
break;
case TARG_SESS_STATE_FAILED:
rb += sprintf(page+rb, "TARG_SESS_STATE_FAILED\n");
break;
case TARG_SESS_STATE_IN_CONTINUE:
rb += sprintf(page+rb, "TARG_SESS_STATE_IN_CONTINUE\n");
break;
default:
rb += sprintf(page+rb, "ERROR: Unknown Session"
" State!\n");
break;
}
rb += sprintf(page+rb, "---------------------[iSCSI Session"
" Values]-----------------------\n");
rb += sprintf(page+rb, " CmdSN/WR : CmdSN/WC : ExpCmdSN"
" : MaxCmdSN : ITT : TTT\n");
rb += sprintf(page+rb, " 0x%08x 0x%08x 0x%08x 0x%08x"
" 0x%08x 0x%08x\n",
sess->cmdsn_window,
(sess->max_cmd_sn - sess->exp_cmd_sn) + 1,
sess->exp_cmd_sn, sess->max_cmd_sn,
sess->init_task_tag, sess->targ_xfer_tag);
rb += sprintf(page+rb, "----------------------[iSCSI"
" Connections]-------------------------\n");
spin_lock(&sess->conn_lock);
list_for_each_entry(conn, &sess->sess_conn_list, conn_list) {
rb += sprintf(page+rb, "CID: %hu Connection"
" State: ", conn->cid);
switch (conn->conn_state) {
case TARG_CONN_STATE_FREE:
rb += sprintf(page+rb,
"TARG_CONN_STATE_FREE\n");
break;
case TARG_CONN_STATE_XPT_UP:
rb += sprintf(page+rb,
"TARG_CONN_STATE_XPT_UP\n");
break;
case TARG_CONN_STATE_IN_LOGIN:
rb += sprintf(page+rb,
"TARG_CONN_STATE_IN_LOGIN\n");
break;
case TARG_CONN_STATE_LOGGED_IN:
rb += sprintf(page+rb,
"TARG_CONN_STATE_LOGGED_IN\n");
break;
case TARG_CONN_STATE_IN_LOGOUT:
rb += sprintf(page+rb,
"TARG_CONN_STATE_IN_LOGOUT\n");
break;
case TARG_CONN_STATE_LOGOUT_REQUESTED:
rb += sprintf(page+rb,
"TARG_CONN_STATE_LOGOUT_REQUESTED\n");
break;
case TARG_CONN_STATE_CLEANUP_WAIT:
rb += sprintf(page+rb,
"TARG_CONN_STATE_CLEANUP_WAIT\n");
break;
default:
rb += sprintf(page+rb,
"ERROR: Unknown Connection State!\n");
break;
}
rb += sprintf(page+rb, " Address %s %s", conn->login_ip,
(conn->network_transport == ISCSI_TCP) ?
"TCP" : "SCTP");
rb += sprintf(page+rb, " StatSN: 0x%08x\n",
conn->stat_sn);
}
spin_unlock(&sess->conn_lock);
}
spin_unlock_bh(&se_nacl->nacl_sess_lock);
return rb;
}
static ssize_t lio_target_nacl_show_cmdsn_depth(
struct se_node_acl *se_nacl,
char *page)
{
return sprintf(page, "%u\n", se_nacl->queue_depth);
}
static ssize_t lio_target_nacl_store_cmdsn_depth(
struct se_node_acl *se_nacl,
const char *page,
size_t count)
{
struct se_portal_group *se_tpg = se_nacl->se_tpg;
struct iscsi_portal_group *tpg = container_of(se_tpg,
struct iscsi_portal_group, tpg_se_tpg);
struct config_item *acl_ci, *tpg_ci, *wwn_ci;
u32 cmdsn_depth = 0;
int ret;
ret = kstrtou32(page, 0, &cmdsn_depth);
if (ret)
return ret;
if (cmdsn_depth > TA_DEFAULT_CMDSN_DEPTH_MAX) {
pr_err("Passed cmdsn_depth: %u exceeds"
" TA_DEFAULT_CMDSN_DEPTH_MAX: %u\n", cmdsn_depth,
TA_DEFAULT_CMDSN_DEPTH_MAX);
return -EINVAL;
}
acl_ci = &se_nacl->acl_group.cg_item;
if (!acl_ci) {
pr_err("Unable to locatel acl_ci\n");
return -EINVAL;
}
tpg_ci = &acl_ci->ci_parent->ci_group->cg_item;
if (!tpg_ci) {
pr_err("Unable to locate tpg_ci\n");
return -EINVAL;
}
wwn_ci = &tpg_ci->ci_group->cg_item;
if (!wwn_ci) {
pr_err("Unable to locate config_item wwn_ci\n");
return -EINVAL;
}
if (iscsit_get_tpg(tpg) < 0)
return -EINVAL;
ret = iscsit_tpg_set_initiator_node_queue_depth(tpg,
config_item_name(acl_ci), cmdsn_depth, 1);
pr_debug("LIO_Target_ConfigFS: %s/%s Set CmdSN Window: %u for"
"InitiatorName: %s\n", config_item_name(wwn_ci),
config_item_name(tpg_ci), cmdsn_depth,
config_item_name(acl_ci));
iscsit_put_tpg(tpg);
return (!ret) ? count : (ssize_t)ret;
}
static ssize_t lio_target_nacl_show_tag(
struct se_node_acl *se_nacl,
char *page)
{
return snprintf(page, PAGE_SIZE, "%s", se_nacl->acl_tag);
}
static ssize_t lio_target_nacl_store_tag(
struct se_node_acl *se_nacl,
const char *page,
size_t count)
{
int ret;
ret = core_tpg_set_initiator_node_tag(se_nacl->se_tpg, se_nacl, page);
if (ret < 0)
return ret;
return count;
}
static struct se_node_acl *lio_tpg_alloc_fabric_acl(
struct se_portal_group *se_tpg)
{
struct iscsi_node_acl *acl;
acl = kzalloc(sizeof(struct iscsi_node_acl), GFP_KERNEL);
if (!acl) {
pr_err("Unable to allocate memory for struct iscsi_node_acl\n");
return NULL;
}
return &acl->se_node_acl;
}
static struct se_node_acl *lio_target_make_nodeacl(
struct se_portal_group *se_tpg,
struct config_group *group,
const char *name)
{
struct config_group *stats_cg;
struct iscsi_node_acl *acl;
struct se_node_acl *se_nacl_new, *se_nacl;
struct iscsi_portal_group *tpg = container_of(se_tpg,
struct iscsi_portal_group, tpg_se_tpg);
u32 cmdsn_depth;
se_nacl_new = lio_tpg_alloc_fabric_acl(se_tpg);
if (!se_nacl_new)
return ERR_PTR(-ENOMEM);
cmdsn_depth = tpg->tpg_attrib.default_cmdsn_depth;
se_nacl = core_tpg_add_initiator_node_acl(se_tpg, se_nacl_new,
name, cmdsn_depth);
if (IS_ERR(se_nacl))
return se_nacl;
acl = container_of(se_nacl, struct iscsi_node_acl, se_node_acl);
stats_cg = &se_nacl->acl_fabric_stat_group;
stats_cg->default_groups = kmalloc(sizeof(struct config_group *) * 2,
GFP_KERNEL);
if (!stats_cg->default_groups) {
pr_err("Unable to allocate memory for"
" stats_cg->default_groups\n");
core_tpg_del_initiator_node_acl(se_tpg, se_nacl, 1);
kfree(acl);
return ERR_PTR(-ENOMEM);
}
stats_cg->default_groups[0] = &acl->node_stat_grps.iscsi_sess_stats_group;
stats_cg->default_groups[1] = NULL;
config_group_init_type_name(&acl->node_stat_grps.iscsi_sess_stats_group,
"iscsi_sess_stats", &iscsi_stat_sess_cit);
return se_nacl;
}
static void lio_target_drop_nodeacl(
struct se_node_acl *se_nacl)
{
struct se_portal_group *se_tpg = se_nacl->se_tpg;
struct iscsi_node_acl *acl = container_of(se_nacl,
struct iscsi_node_acl, se_node_acl);
struct config_item *df_item;
struct config_group *stats_cg;
int i;
stats_cg = &acl->se_node_acl.acl_fabric_stat_group;
for (i = 0; stats_cg->default_groups[i]; i++) {
df_item = &stats_cg->default_groups[i]->cg_item;
stats_cg->default_groups[i] = NULL;
config_item_put(df_item);
}
kfree(stats_cg->default_groups);
core_tpg_del_initiator_node_acl(se_tpg, se_nacl, 1);
kfree(acl);
}
static ssize_t lio_target_tpg_show_enable(
struct se_portal_group *se_tpg,
char *page)
{
struct iscsi_portal_group *tpg = container_of(se_tpg,
struct iscsi_portal_group, tpg_se_tpg);
ssize_t len;
spin_lock(&tpg->tpg_state_lock);
len = sprintf(page, "%d\n",
(tpg->tpg_state == TPG_STATE_ACTIVE) ? 1 : 0);
spin_unlock(&tpg->tpg_state_lock);
return len;
}
static ssize_t lio_target_tpg_store_enable(
struct se_portal_group *se_tpg,
const char *page,
size_t count)
{
struct iscsi_portal_group *tpg = container_of(se_tpg,
struct iscsi_portal_group, tpg_se_tpg);
u32 op;
int ret;
ret = kstrtou32(page, 0, &op);
if (ret)
return ret;
if ((op != 1) && (op != 0)) {
pr_err("Illegal value for tpg_enable: %u\n", op);
return -EINVAL;
}
ret = iscsit_get_tpg(tpg);
if (ret < 0)
return -EINVAL;
if (op) {
ret = iscsit_tpg_enable_portal_group(tpg);
if (ret < 0)
goto out;
} else {
ret = iscsit_tpg_disable_portal_group(tpg, 1);
if (ret < 0)
goto out;
}
iscsit_put_tpg(tpg);
return count;
out:
iscsit_put_tpg(tpg);
return -EINVAL;
}
static struct se_portal_group *lio_target_tiqn_addtpg(
struct se_wwn *wwn,
struct config_group *group,
const char *name)
{
struct iscsi_portal_group *tpg;
struct iscsi_tiqn *tiqn;
char *tpgt_str;
int ret;
u16 tpgt;
tiqn = container_of(wwn, struct iscsi_tiqn, tiqn_wwn);
tpgt_str = strstr(name, "tpgt_");
if (!tpgt_str) {
pr_err("Unable to locate \"tpgt_#\" directory"
" group\n");
return NULL;
}
tpgt_str += 5;
ret = kstrtou16(tpgt_str, 0, &tpgt);
if (ret)
return NULL;
tpg = iscsit_alloc_portal_group(tiqn, tpgt);
if (!tpg)
return NULL;
ret = core_tpg_register(
&lio_target_fabric_configfs->tf_ops,
wwn, &tpg->tpg_se_tpg, tpg,
TRANSPORT_TPG_TYPE_NORMAL);
if (ret < 0)
return NULL;
ret = iscsit_tpg_add_portal_group(tiqn, tpg);
if (ret != 0)
goto out;
pr_debug("LIO_Target_ConfigFS: REGISTER -> %s\n", tiqn->tiqn);
pr_debug("LIO_Target_ConfigFS: REGISTER -> Allocated TPG: %s\n",
name);
return &tpg->tpg_se_tpg;
out:
core_tpg_deregister(&tpg->tpg_se_tpg);
kfree(tpg);
return NULL;
}
static void lio_target_tiqn_deltpg(struct se_portal_group *se_tpg)
{
struct iscsi_portal_group *tpg;
struct iscsi_tiqn *tiqn;
tpg = container_of(se_tpg, struct iscsi_portal_group, tpg_se_tpg);
tiqn = tpg->tpg_tiqn;
pr_debug("LIO_Target_ConfigFS: DEREGISTER -> Releasing TPG\n");
iscsit_tpg_del_portal_group(tiqn, tpg, 1);
}
static ssize_t lio_target_wwn_show_attr_lio_version(
struct target_fabric_configfs *tf,
char *page)
{
return sprintf(page, "Datera Inc. iSCSI Target "ISCSIT_VERSION"\n");
}
static struct se_wwn *lio_target_call_coreaddtiqn(
struct target_fabric_configfs *tf,
struct config_group *group,
const char *name)
{
struct config_group *stats_cg;
struct iscsi_tiqn *tiqn;
tiqn = iscsit_add_tiqn((unsigned char *)name);
if (IS_ERR(tiqn))
return ERR_CAST(tiqn);
stats_cg = &tiqn->tiqn_wwn.fabric_stat_group;
stats_cg->default_groups = kmalloc(sizeof(struct config_group *) * 6,
GFP_KERNEL);
if (!stats_cg->default_groups) {
pr_err("Unable to allocate memory for"
" stats_cg->default_groups\n");
iscsit_del_tiqn(tiqn);
return ERR_PTR(-ENOMEM);
}
stats_cg->default_groups[0] = &tiqn->tiqn_stat_grps.iscsi_instance_group;
stats_cg->default_groups[1] = &tiqn->tiqn_stat_grps.iscsi_sess_err_group;
stats_cg->default_groups[2] = &tiqn->tiqn_stat_grps.iscsi_tgt_attr_group;
stats_cg->default_groups[3] = &tiqn->tiqn_stat_grps.iscsi_login_stats_group;
stats_cg->default_groups[4] = &tiqn->tiqn_stat_grps.iscsi_logout_stats_group;
stats_cg->default_groups[5] = NULL;
config_group_init_type_name(&tiqn->tiqn_stat_grps.iscsi_instance_group,
"iscsi_instance", &iscsi_stat_instance_cit);
config_group_init_type_name(&tiqn->tiqn_stat_grps.iscsi_sess_err_group,
"iscsi_sess_err", &iscsi_stat_sess_err_cit);
config_group_init_type_name(&tiqn->tiqn_stat_grps.iscsi_tgt_attr_group,
"iscsi_tgt_attr", &iscsi_stat_tgt_attr_cit);
config_group_init_type_name(&tiqn->tiqn_stat_grps.iscsi_login_stats_group,
"iscsi_login_stats", &iscsi_stat_login_cit);
config_group_init_type_name(&tiqn->tiqn_stat_grps.iscsi_logout_stats_group,
"iscsi_logout_stats", &iscsi_stat_logout_cit);
pr_debug("LIO_Target_ConfigFS: REGISTER -> %s\n", tiqn->tiqn);
pr_debug("LIO_Target_ConfigFS: REGISTER -> Allocated Node:"
" %s\n", name);
return &tiqn->tiqn_wwn;
}
static void lio_target_call_coredeltiqn(
struct se_wwn *wwn)
{
struct iscsi_tiqn *tiqn = container_of(wwn, struct iscsi_tiqn, tiqn_wwn);
struct config_item *df_item;
struct config_group *stats_cg;
int i;
stats_cg = &tiqn->tiqn_wwn.fabric_stat_group;
for (i = 0; stats_cg->default_groups[i]; i++) {
df_item = &stats_cg->default_groups[i]->cg_item;
stats_cg->default_groups[i] = NULL;
config_item_put(df_item);
}
kfree(stats_cg->default_groups);
pr_debug("LIO_Target_ConfigFS: DEREGISTER -> %s\n",
tiqn->tiqn);
iscsit_del_tiqn(tiqn);
}
static ssize_t iscsi_disc_show_enforce_discovery_auth(
struct target_fabric_configfs *tf,
char *page)
{
struct iscsi_node_auth *discovery_auth = &iscsit_global->discovery_acl.node_auth;
return sprintf(page, "%d\n", discovery_auth->enforce_discovery_auth);
}
static ssize_t iscsi_disc_store_enforce_discovery_auth(
struct target_fabric_configfs *tf,
const char *page,
size_t count)
{
struct iscsi_param *param;
struct iscsi_portal_group *discovery_tpg = iscsit_global->discovery_tpg;
u32 op;
int err;
err = kstrtou32(page, 0, &op);
if (err)
return -EINVAL;
if ((op != 1) && (op != 0)) {
pr_err("Illegal value for enforce_discovery_auth:"
" %u\n", op);
return -EINVAL;
}
if (!discovery_tpg) {
pr_err("iscsit_global->discovery_tpg is NULL\n");
return -EINVAL;
}
param = iscsi_find_param_from_key(AUTHMETHOD,
discovery_tpg->param_list);
if (!param)
return -EINVAL;
if (op) {
if (iscsi_update_param_value(param, CHAP) < 0)
return -EINVAL;
discovery_tpg->tpg_attrib.authentication = 1;
iscsit_global->discovery_acl.node_auth.enforce_discovery_auth = 1;
pr_debug("LIO-CORE[0] Successfully enabled"
" authentication enforcement for iSCSI"
" Discovery TPG\n");
} else {
if (iscsi_update_param_value(param, "CHAP,None") < 0)
return -EINVAL;
discovery_tpg->tpg_attrib.authentication = 0;
iscsit_global->discovery_acl.node_auth.enforce_discovery_auth = 0;
pr_debug("LIO-CORE[0] Successfully disabled"
" authentication enforcement for iSCSI"
" Discovery TPG\n");
}
return count;
}
static char *iscsi_get_fabric_name(void)
{
return "iSCSI";
}
static u32 iscsi_get_task_tag(struct se_cmd *se_cmd)
{
struct iscsi_cmd *cmd = container_of(se_cmd, struct iscsi_cmd, se_cmd);
return (__force u32)cmd->init_task_tag;
}
static int iscsi_get_cmd_state(struct se_cmd *se_cmd)
{
struct iscsi_cmd *cmd = container_of(se_cmd, struct iscsi_cmd, se_cmd);
return cmd->i_state;
}
static u32 lio_sess_get_index(struct se_session *se_sess)
{
struct iscsi_session *sess = se_sess->fabric_sess_ptr;
return sess->session_index;
}
static u32 lio_sess_get_initiator_sid(
struct se_session *se_sess,
unsigned char *buf,
u32 size)
{
struct iscsi_session *sess = se_sess->fabric_sess_ptr;
return snprintf(buf, size, "%6phN", sess->isid);
}
static int lio_queue_data_in(struct se_cmd *se_cmd)
{
struct iscsi_cmd *cmd = container_of(se_cmd, struct iscsi_cmd, se_cmd);
cmd->i_state = ISTATE_SEND_DATAIN;
cmd->conn->conn_transport->iscsit_queue_data_in(cmd->conn, cmd);
return 0;
}
static int lio_write_pending(struct se_cmd *se_cmd)
{
struct iscsi_cmd *cmd = container_of(se_cmd, struct iscsi_cmd, se_cmd);
struct iscsi_conn *conn = cmd->conn;
if (!cmd->immediate_data && !cmd->unsolicited_data)
return conn->conn_transport->iscsit_get_dataout(conn, cmd, false);
return 0;
}
static int lio_write_pending_status(struct se_cmd *se_cmd)
{
struct iscsi_cmd *cmd = container_of(se_cmd, struct iscsi_cmd, se_cmd);
int ret;
spin_lock_bh(&cmd->istate_lock);
ret = !(cmd->cmd_flags & ICF_GOT_LAST_DATAOUT);
spin_unlock_bh(&cmd->istate_lock);
return ret;
}
static int lio_queue_status(struct se_cmd *se_cmd)
{
struct iscsi_cmd *cmd = container_of(se_cmd, struct iscsi_cmd, se_cmd);
cmd->i_state = ISTATE_SEND_STATUS;
if (cmd->se_cmd.scsi_status || cmd->sense_reason) {
iscsit_add_cmd_to_response_queue(cmd, cmd->conn, cmd->i_state);
return 0;
}
cmd->conn->conn_transport->iscsit_queue_status(cmd->conn, cmd);
return 0;
}
static void lio_queue_tm_rsp(struct se_cmd *se_cmd)
{
struct iscsi_cmd *cmd = container_of(se_cmd, struct iscsi_cmd, se_cmd);
cmd->i_state = ISTATE_SEND_TASKMGTRSP;
iscsit_add_cmd_to_response_queue(cmd, cmd->conn, cmd->i_state);
}
static void lio_aborted_task(struct se_cmd *se_cmd)
{
struct iscsi_cmd *cmd = container_of(se_cmd, struct iscsi_cmd, se_cmd);
cmd->conn->conn_transport->iscsit_aborted_task(cmd->conn, cmd);
}
static char *lio_tpg_get_endpoint_wwn(struct se_portal_group *se_tpg)
{
struct iscsi_portal_group *tpg = se_tpg->se_tpg_fabric_ptr;
return &tpg->tpg_tiqn->tiqn[0];
}
static u16 lio_tpg_get_tag(struct se_portal_group *se_tpg)
{
struct iscsi_portal_group *tpg = se_tpg->se_tpg_fabric_ptr;
return tpg->tpgt;
}
static u32 lio_tpg_get_default_depth(struct se_portal_group *se_tpg)
{
struct iscsi_portal_group *tpg = se_tpg->se_tpg_fabric_ptr;
return tpg->tpg_attrib.default_cmdsn_depth;
}
static int lio_tpg_check_demo_mode(struct se_portal_group *se_tpg)
{
struct iscsi_portal_group *tpg = se_tpg->se_tpg_fabric_ptr;
return tpg->tpg_attrib.generate_node_acls;
}
static int lio_tpg_check_demo_mode_cache(struct se_portal_group *se_tpg)
{
struct iscsi_portal_group *tpg = se_tpg->se_tpg_fabric_ptr;
return tpg->tpg_attrib.cache_dynamic_acls;
}
static int lio_tpg_check_demo_mode_write_protect(
struct se_portal_group *se_tpg)
{
struct iscsi_portal_group *tpg = se_tpg->se_tpg_fabric_ptr;
return tpg->tpg_attrib.demo_mode_write_protect;
}
static int lio_tpg_check_prod_mode_write_protect(
struct se_portal_group *se_tpg)
{
struct iscsi_portal_group *tpg = se_tpg->se_tpg_fabric_ptr;
return tpg->tpg_attrib.prod_mode_write_protect;
}
static void lio_tpg_release_fabric_acl(
struct se_portal_group *se_tpg,
struct se_node_acl *se_acl)
{
struct iscsi_node_acl *acl = container_of(se_acl,
struct iscsi_node_acl, se_node_acl);
kfree(acl);
}
static int lio_tpg_shutdown_session(struct se_session *se_sess)
{
struct iscsi_session *sess = se_sess->fabric_sess_ptr;
spin_lock(&sess->conn_lock);
if (atomic_read(&sess->session_fall_back_to_erl0) ||
atomic_read(&sess->session_logout) ||
(sess->time2retain_timer_flags & ISCSI_TF_EXPIRED)) {
spin_unlock(&sess->conn_lock);
return 0;
}
atomic_set(&sess->session_reinstatement, 1);
spin_unlock(&sess->conn_lock);
iscsit_stop_time2retain_timer(sess);
iscsit_stop_session(sess, 1, 1);
return 1;
}
static void lio_tpg_close_session(struct se_session *se_sess)
{
struct iscsi_session *sess = se_sess->fabric_sess_ptr;
iscsit_close_session(sess);
}
static u32 lio_tpg_get_inst_index(struct se_portal_group *se_tpg)
{
struct iscsi_portal_group *tpg = se_tpg->se_tpg_fabric_ptr;
return tpg->tpg_tiqn->tiqn_index;
}
static void lio_set_default_node_attributes(struct se_node_acl *se_acl)
{
struct iscsi_node_acl *acl = container_of(se_acl, struct iscsi_node_acl,
se_node_acl);
struct se_portal_group *se_tpg = se_acl->se_tpg;
struct iscsi_portal_group *tpg = container_of(se_tpg,
struct iscsi_portal_group, tpg_se_tpg);
acl->node_attrib.nacl = acl;
iscsit_set_default_node_attribues(acl, tpg);
}
static int lio_check_stop_free(struct se_cmd *se_cmd)
{
return target_put_sess_cmd(se_cmd->se_sess, se_cmd);
}
static void lio_release_cmd(struct se_cmd *se_cmd)
{
struct iscsi_cmd *cmd = container_of(se_cmd, struct iscsi_cmd, se_cmd);
pr_debug("Entering lio_release_cmd for se_cmd: %p\n", se_cmd);
iscsit_release_cmd(cmd);
}
int iscsi_target_register_configfs(void)
{
struct target_fabric_configfs *fabric;
int ret;
lio_target_fabric_configfs = NULL;
fabric = target_fabric_configfs_init(THIS_MODULE, "iscsi");
if (IS_ERR(fabric)) {
pr_err("target_fabric_configfs_init() for"
" LIO-Target failed!\n");
return PTR_ERR(fabric);
}
fabric->tf_ops.get_fabric_name = &iscsi_get_fabric_name;
fabric->tf_ops.get_fabric_proto_ident = &iscsi_get_fabric_proto_ident;
fabric->tf_ops.tpg_get_wwn = &lio_tpg_get_endpoint_wwn;
fabric->tf_ops.tpg_get_tag = &lio_tpg_get_tag;
fabric->tf_ops.tpg_get_default_depth = &lio_tpg_get_default_depth;
fabric->tf_ops.tpg_get_pr_transport_id = &iscsi_get_pr_transport_id;
fabric->tf_ops.tpg_get_pr_transport_id_len =
&iscsi_get_pr_transport_id_len;
fabric->tf_ops.tpg_parse_pr_out_transport_id =
&iscsi_parse_pr_out_transport_id;
fabric->tf_ops.tpg_check_demo_mode = &lio_tpg_check_demo_mode;
fabric->tf_ops.tpg_check_demo_mode_cache =
&lio_tpg_check_demo_mode_cache;
fabric->tf_ops.tpg_check_demo_mode_write_protect =
&lio_tpg_check_demo_mode_write_protect;
fabric->tf_ops.tpg_check_prod_mode_write_protect =
&lio_tpg_check_prod_mode_write_protect;
fabric->tf_ops.tpg_alloc_fabric_acl = &lio_tpg_alloc_fabric_acl;
fabric->tf_ops.tpg_release_fabric_acl = &lio_tpg_release_fabric_acl;
fabric->tf_ops.tpg_get_inst_index = &lio_tpg_get_inst_index;
fabric->tf_ops.check_stop_free = &lio_check_stop_free,
fabric->tf_ops.release_cmd = &lio_release_cmd;
fabric->tf_ops.shutdown_session = &lio_tpg_shutdown_session;
fabric->tf_ops.close_session = &lio_tpg_close_session;
fabric->tf_ops.sess_get_index = &lio_sess_get_index;
fabric->tf_ops.sess_get_initiator_sid = &lio_sess_get_initiator_sid;
fabric->tf_ops.write_pending = &lio_write_pending;
fabric->tf_ops.write_pending_status = &lio_write_pending_status;
fabric->tf_ops.set_default_node_attributes =
&lio_set_default_node_attributes;
fabric->tf_ops.get_task_tag = &iscsi_get_task_tag;
fabric->tf_ops.get_cmd_state = &iscsi_get_cmd_state;
fabric->tf_ops.queue_data_in = &lio_queue_data_in;
fabric->tf_ops.queue_status = &lio_queue_status;
fabric->tf_ops.queue_tm_rsp = &lio_queue_tm_rsp;
fabric->tf_ops.aborted_task = &lio_aborted_task;
fabric->tf_ops.fabric_make_wwn = &lio_target_call_coreaddtiqn;
fabric->tf_ops.fabric_drop_wwn = &lio_target_call_coredeltiqn;
fabric->tf_ops.fabric_make_tpg = &lio_target_tiqn_addtpg;
fabric->tf_ops.fabric_drop_tpg = &lio_target_tiqn_deltpg;
fabric->tf_ops.fabric_post_link = NULL;
fabric->tf_ops.fabric_pre_unlink = NULL;
fabric->tf_ops.fabric_make_np = &lio_target_call_addnptotpg;
fabric->tf_ops.fabric_drop_np = &lio_target_call_delnpfromtpg;
fabric->tf_ops.fabric_make_nodeacl = &lio_target_make_nodeacl;
fabric->tf_ops.fabric_drop_nodeacl = &lio_target_drop_nodeacl;
fabric->tf_cit_tmpl.tfc_discovery_cit.ct_attrs = lio_target_discovery_auth_attrs;
fabric->tf_cit_tmpl.tfc_wwn_cit.ct_attrs = lio_target_wwn_attrs;
fabric->tf_cit_tmpl.tfc_tpg_base_cit.ct_attrs = lio_target_tpg_attrs;
fabric->tf_cit_tmpl.tfc_tpg_attrib_cit.ct_attrs = lio_target_tpg_attrib_attrs;
fabric->tf_cit_tmpl.tfc_tpg_auth_cit.ct_attrs = lio_target_tpg_auth_attrs;
fabric->tf_cit_tmpl.tfc_tpg_param_cit.ct_attrs = lio_target_tpg_param_attrs;
fabric->tf_cit_tmpl.tfc_tpg_np_base_cit.ct_attrs = lio_target_portal_attrs;
fabric->tf_cit_tmpl.tfc_tpg_nacl_base_cit.ct_attrs = lio_target_initiator_attrs;
fabric->tf_cit_tmpl.tfc_tpg_nacl_attrib_cit.ct_attrs = lio_target_nacl_attrib_attrs;
fabric->tf_cit_tmpl.tfc_tpg_nacl_auth_cit.ct_attrs = lio_target_nacl_auth_attrs;
fabric->tf_cit_tmpl.tfc_tpg_nacl_param_cit.ct_attrs = lio_target_nacl_param_attrs;
ret = target_fabric_configfs_register(fabric);
if (ret < 0) {
pr_err("target_fabric_configfs_register() for"
" LIO-Target failed!\n");
target_fabric_configfs_free(fabric);
return ret;
}
lio_target_fabric_configfs = fabric;
pr_debug("LIO_TARGET[0] - Set fabric ->"
" lio_target_fabric_configfs\n");
return 0;
}
void iscsi_target_deregister_configfs(void)
{
if (!lio_target_fabric_configfs)
return;
if (iscsit_global->discovery_tpg)
iscsit_tpg_disable_portal_group(iscsit_global->discovery_tpg, 1);
target_fabric_configfs_deregister(lio_target_fabric_configfs);
lio_target_fabric_configfs = NULL;
pr_debug("LIO_TARGET[0] - Cleared"
" lio_target_fabric_configfs\n");
}
