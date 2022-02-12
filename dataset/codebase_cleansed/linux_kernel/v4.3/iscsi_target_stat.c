static ssize_t iscsi_stat_instance_show_attr_inst(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
return snprintf(page, PAGE_SIZE, "%u\n", tiqn->tiqn_index);
}
static ssize_t iscsi_stat_instance_show_attr_min_ver(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
return snprintf(page, PAGE_SIZE, "%u\n", ISCSI_DRAFT20_VERSION);
}
static ssize_t iscsi_stat_instance_show_attr_max_ver(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
return snprintf(page, PAGE_SIZE, "%u\n", ISCSI_DRAFT20_VERSION);
}
static ssize_t iscsi_stat_instance_show_attr_portals(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
return snprintf(page, PAGE_SIZE, "%u\n", tiqn->tiqn_num_tpg_nps);
}
static ssize_t iscsi_stat_instance_show_attr_nodes(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
return snprintf(page, PAGE_SIZE, "%u\n", ISCSI_INST_NUM_NODES);
}
static ssize_t iscsi_stat_instance_show_attr_sessions(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
return snprintf(page, PAGE_SIZE, "%u\n", tiqn->tiqn_nsessions);
}
static ssize_t iscsi_stat_instance_show_attr_fail_sess(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_sess_err_stats *sess_err = &tiqn->sess_err_stats;
u32 sess_err_count;
spin_lock_bh(&sess_err->lock);
sess_err_count = (sess_err->digest_errors +
sess_err->cxn_timeout_errors +
sess_err->pdu_format_errors);
spin_unlock_bh(&sess_err->lock);
return snprintf(page, PAGE_SIZE, "%u\n", sess_err_count);
}
static ssize_t iscsi_stat_instance_show_attr_fail_type(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_sess_err_stats *sess_err = &tiqn->sess_err_stats;
return snprintf(page, PAGE_SIZE, "%u\n",
sess_err->last_sess_failure_type);
}
static ssize_t iscsi_stat_instance_show_attr_fail_rem_name(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_sess_err_stats *sess_err = &tiqn->sess_err_stats;
return snprintf(page, PAGE_SIZE, "%s\n",
sess_err->last_sess_fail_rem_name[0] ?
sess_err->last_sess_fail_rem_name : NONE);
}
static ssize_t iscsi_stat_instance_show_attr_disc_time(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
return snprintf(page, PAGE_SIZE, "%u\n", ISCSI_DISCONTINUITY_TIME);
}
static ssize_t iscsi_stat_instance_show_attr_description(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
return snprintf(page, PAGE_SIZE, "%s\n", ISCSI_INST_DESCR);
}
static ssize_t iscsi_stat_instance_show_attr_vendor(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
return snprintf(page, PAGE_SIZE, "Datera, Inc. iSCSI-Target\n");
}
static ssize_t iscsi_stat_instance_show_attr_version(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
return snprintf(page, PAGE_SIZE, "%s\n", ISCSIT_VERSION);
}
static ssize_t iscsi_stat_sess_err_show_attr_inst(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
return snprintf(page, PAGE_SIZE, "%u\n", tiqn->tiqn_index);
}
static ssize_t iscsi_stat_sess_err_show_attr_digest_errors(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_sess_err_stats *sess_err = &tiqn->sess_err_stats;
return snprintf(page, PAGE_SIZE, "%u\n", sess_err->digest_errors);
}
static ssize_t iscsi_stat_sess_err_show_attr_cxn_errors(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_sess_err_stats *sess_err = &tiqn->sess_err_stats;
return snprintf(page, PAGE_SIZE, "%u\n", sess_err->cxn_timeout_errors);
}
static ssize_t iscsi_stat_sess_err_show_attr_format_errors(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_sess_err_stats *sess_err = &tiqn->sess_err_stats;
return snprintf(page, PAGE_SIZE, "%u\n", sess_err->pdu_format_errors);
}
static ssize_t iscsi_stat_tgt_attr_show_attr_inst(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
return snprintf(page, PAGE_SIZE, "%u\n", tiqn->tiqn_index);
}
static ssize_t iscsi_stat_tgt_attr_show_attr_indx(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
return snprintf(page, PAGE_SIZE, "%u\n", ISCSI_NODE_INDEX);
}
static ssize_t iscsi_stat_tgt_attr_show_attr_login_fails(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_login_stats *lstat = &tiqn->login_stats;
u32 fail_count;
spin_lock(&lstat->lock);
fail_count = (lstat->redirects + lstat->authorize_fails +
lstat->authenticate_fails + lstat->negotiate_fails +
lstat->other_fails);
spin_unlock(&lstat->lock);
return snprintf(page, PAGE_SIZE, "%u\n", fail_count);
}
static ssize_t iscsi_stat_tgt_attr_show_attr_last_fail_time(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_login_stats *lstat = &tiqn->login_stats;
u32 last_fail_time;
spin_lock(&lstat->lock);
last_fail_time = lstat->last_fail_time ?
(u32)(((u32)lstat->last_fail_time -
INITIAL_JIFFIES) * 100 / HZ) : 0;
spin_unlock(&lstat->lock);
return snprintf(page, PAGE_SIZE, "%u\n", last_fail_time);
}
static ssize_t iscsi_stat_tgt_attr_show_attr_last_fail_type(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_login_stats *lstat = &tiqn->login_stats;
u32 last_fail_type;
spin_lock(&lstat->lock);
last_fail_type = lstat->last_fail_type;
spin_unlock(&lstat->lock);
return snprintf(page, PAGE_SIZE, "%u\n", last_fail_type);
}
static ssize_t iscsi_stat_tgt_attr_show_attr_fail_intr_name(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_login_stats *lstat = &tiqn->login_stats;
unsigned char buf[224];
spin_lock(&lstat->lock);
snprintf(buf, 224, "%s", lstat->last_intr_fail_name[0] ?
lstat->last_intr_fail_name : NONE);
spin_unlock(&lstat->lock);
return snprintf(page, PAGE_SIZE, "%s\n", buf);
}
static ssize_t iscsi_stat_tgt_attr_show_attr_fail_intr_addr_type(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_login_stats *lstat = &tiqn->login_stats;
int ret;
spin_lock(&lstat->lock);
if (lstat->last_intr_fail_ip_family == AF_INET6)
ret = snprintf(page, PAGE_SIZE, "ipv6\n");
else
ret = snprintf(page, PAGE_SIZE, "ipv4\n");
spin_unlock(&lstat->lock);
return ret;
}
static ssize_t iscsi_stat_tgt_attr_show_attr_fail_intr_addr(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_login_stats *lstat = &tiqn->login_stats;
int ret;
spin_lock(&lstat->lock);
ret = snprintf(page, PAGE_SIZE, "%pISc\n", &lstat->last_intr_fail_sockaddr);
spin_unlock(&lstat->lock);
return ret;
}
static ssize_t iscsi_stat_login_show_attr_inst(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
return snprintf(page, PAGE_SIZE, "%u\n", tiqn->tiqn_index);
}
static ssize_t iscsi_stat_login_show_attr_indx(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
return snprintf(page, PAGE_SIZE, "%u\n", ISCSI_NODE_INDEX);
}
static ssize_t iscsi_stat_login_show_attr_accepts(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_login_stats *lstat = &tiqn->login_stats;
ssize_t ret;
spin_lock(&lstat->lock);
ret = snprintf(page, PAGE_SIZE, "%u\n", lstat->accepts);
spin_unlock(&lstat->lock);
return ret;
}
static ssize_t iscsi_stat_login_show_attr_other_fails(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_login_stats *lstat = &tiqn->login_stats;
ssize_t ret;
spin_lock(&lstat->lock);
ret = snprintf(page, PAGE_SIZE, "%u\n", lstat->other_fails);
spin_unlock(&lstat->lock);
return ret;
}
static ssize_t iscsi_stat_login_show_attr_redirects(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_login_stats *lstat = &tiqn->login_stats;
ssize_t ret;
spin_lock(&lstat->lock);
ret = snprintf(page, PAGE_SIZE, "%u\n", lstat->redirects);
spin_unlock(&lstat->lock);
return ret;
}
static ssize_t iscsi_stat_login_show_attr_authorize_fails(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_login_stats *lstat = &tiqn->login_stats;
ssize_t ret;
spin_lock(&lstat->lock);
ret = snprintf(page, PAGE_SIZE, "%u\n", lstat->authorize_fails);
spin_unlock(&lstat->lock);
return ret;
}
static ssize_t iscsi_stat_login_show_attr_authenticate_fails(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_login_stats *lstat = &tiqn->login_stats;
ssize_t ret;
spin_lock(&lstat->lock);
ret = snprintf(page, PAGE_SIZE, "%u\n", lstat->authenticate_fails);
spin_unlock(&lstat->lock);
return ret;
}
static ssize_t iscsi_stat_login_show_attr_negotiate_fails(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_login_stats *lstat = &tiqn->login_stats;
ssize_t ret;
spin_lock(&lstat->lock);
ret = snprintf(page, PAGE_SIZE, "%u\n", lstat->negotiate_fails);
spin_unlock(&lstat->lock);
return ret;
}
static ssize_t iscsi_stat_logout_show_attr_inst(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
return snprintf(page, PAGE_SIZE, "%u\n", tiqn->tiqn_index);
}
static ssize_t iscsi_stat_logout_show_attr_indx(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
return snprintf(page, PAGE_SIZE, "%u\n", ISCSI_NODE_INDEX);
}
static ssize_t iscsi_stat_logout_show_attr_normal_logouts(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_logout_stats *lstats = &tiqn->logout_stats;
return snprintf(page, PAGE_SIZE, "%u\n", lstats->normal_logouts);
}
static ssize_t iscsi_stat_logout_show_attr_abnormal_logouts(
struct iscsi_wwn_stat_grps *igrps, char *page)
{
struct iscsi_tiqn *tiqn = container_of(igrps,
struct iscsi_tiqn, tiqn_stat_grps);
struct iscsi_logout_stats *lstats = &tiqn->logout_stats;
return snprintf(page, PAGE_SIZE, "%u\n", lstats->abnormal_logouts);
}
static ssize_t iscsi_stat_sess_show_attr_inst(
struct iscsi_node_stat_grps *igrps, char *page)
{
struct iscsi_node_acl *acl = container_of(igrps,
struct iscsi_node_acl, node_stat_grps);
struct se_wwn *wwn = acl->se_node_acl.se_tpg->se_tpg_wwn;
struct iscsi_tiqn *tiqn = container_of(wwn,
struct iscsi_tiqn, tiqn_wwn);
return snprintf(page, PAGE_SIZE, "%u\n", tiqn->tiqn_index);
}
static ssize_t iscsi_stat_sess_show_attr_node(
struct iscsi_node_stat_grps *igrps, char *page)
{
struct iscsi_node_acl *acl = container_of(igrps,
struct iscsi_node_acl, node_stat_grps);
struct se_node_acl *se_nacl = &acl->se_node_acl;
struct iscsi_session *sess;
struct se_session *se_sess;
ssize_t ret = 0;
spin_lock_bh(&se_nacl->nacl_sess_lock);
se_sess = se_nacl->nacl_sess;
if (se_sess) {
sess = se_sess->fabric_sess_ptr;
if (sess)
ret = snprintf(page, PAGE_SIZE, "%u\n",
sess->sess_ops->SessionType ? 0 : ISCSI_NODE_INDEX);
}
spin_unlock_bh(&se_nacl->nacl_sess_lock);
return ret;
}
static ssize_t iscsi_stat_sess_show_attr_indx(
struct iscsi_node_stat_grps *igrps, char *page)
{
struct iscsi_node_acl *acl = container_of(igrps,
struct iscsi_node_acl, node_stat_grps);
struct se_node_acl *se_nacl = &acl->se_node_acl;
struct iscsi_session *sess;
struct se_session *se_sess;
ssize_t ret = 0;
spin_lock_bh(&se_nacl->nacl_sess_lock);
se_sess = se_nacl->nacl_sess;
if (se_sess) {
sess = se_sess->fabric_sess_ptr;
if (sess)
ret = snprintf(page, PAGE_SIZE, "%u\n",
sess->session_index);
}
spin_unlock_bh(&se_nacl->nacl_sess_lock);
return ret;
}
static ssize_t iscsi_stat_sess_show_attr_cmd_pdus(
struct iscsi_node_stat_grps *igrps, char *page)
{
struct iscsi_node_acl *acl = container_of(igrps,
struct iscsi_node_acl, node_stat_grps);
struct se_node_acl *se_nacl = &acl->se_node_acl;
struct iscsi_session *sess;
struct se_session *se_sess;
ssize_t ret = 0;
spin_lock_bh(&se_nacl->nacl_sess_lock);
se_sess = se_nacl->nacl_sess;
if (se_sess) {
sess = se_sess->fabric_sess_ptr;
if (sess)
ret = snprintf(page, PAGE_SIZE, "%lu\n",
atomic_long_read(&sess->cmd_pdus));
}
spin_unlock_bh(&se_nacl->nacl_sess_lock);
return ret;
}
static ssize_t iscsi_stat_sess_show_attr_rsp_pdus(
struct iscsi_node_stat_grps *igrps, char *page)
{
struct iscsi_node_acl *acl = container_of(igrps,
struct iscsi_node_acl, node_stat_grps);
struct se_node_acl *se_nacl = &acl->se_node_acl;
struct iscsi_session *sess;
struct se_session *se_sess;
ssize_t ret = 0;
spin_lock_bh(&se_nacl->nacl_sess_lock);
se_sess = se_nacl->nacl_sess;
if (se_sess) {
sess = se_sess->fabric_sess_ptr;
if (sess)
ret = snprintf(page, PAGE_SIZE, "%lu\n",
atomic_long_read(&sess->rsp_pdus));
}
spin_unlock_bh(&se_nacl->nacl_sess_lock);
return ret;
}
static ssize_t iscsi_stat_sess_show_attr_txdata_octs(
struct iscsi_node_stat_grps *igrps, char *page)
{
struct iscsi_node_acl *acl = container_of(igrps,
struct iscsi_node_acl, node_stat_grps);
struct se_node_acl *se_nacl = &acl->se_node_acl;
struct iscsi_session *sess;
struct se_session *se_sess;
ssize_t ret = 0;
spin_lock_bh(&se_nacl->nacl_sess_lock);
se_sess = se_nacl->nacl_sess;
if (se_sess) {
sess = se_sess->fabric_sess_ptr;
if (sess)
ret = snprintf(page, PAGE_SIZE, "%lu\n",
atomic_long_read(&sess->tx_data_octets));
}
spin_unlock_bh(&se_nacl->nacl_sess_lock);
return ret;
}
static ssize_t iscsi_stat_sess_show_attr_rxdata_octs(
struct iscsi_node_stat_grps *igrps, char *page)
{
struct iscsi_node_acl *acl = container_of(igrps,
struct iscsi_node_acl, node_stat_grps);
struct se_node_acl *se_nacl = &acl->se_node_acl;
struct iscsi_session *sess;
struct se_session *se_sess;
ssize_t ret = 0;
spin_lock_bh(&se_nacl->nacl_sess_lock);
se_sess = se_nacl->nacl_sess;
if (se_sess) {
sess = se_sess->fabric_sess_ptr;
if (sess)
ret = snprintf(page, PAGE_SIZE, "%lu\n",
atomic_long_read(&sess->rx_data_octets));
}
spin_unlock_bh(&se_nacl->nacl_sess_lock);
return ret;
}
static ssize_t iscsi_stat_sess_show_attr_conn_digest_errors(
struct iscsi_node_stat_grps *igrps, char *page)
{
struct iscsi_node_acl *acl = container_of(igrps,
struct iscsi_node_acl, node_stat_grps);
struct se_node_acl *se_nacl = &acl->se_node_acl;
struct iscsi_session *sess;
struct se_session *se_sess;
ssize_t ret = 0;
spin_lock_bh(&se_nacl->nacl_sess_lock);
se_sess = se_nacl->nacl_sess;
if (se_sess) {
sess = se_sess->fabric_sess_ptr;
if (sess)
ret = snprintf(page, PAGE_SIZE, "%lu\n",
atomic_long_read(&sess->conn_digest_errors));
}
spin_unlock_bh(&se_nacl->nacl_sess_lock);
return ret;
}
static ssize_t iscsi_stat_sess_show_attr_conn_timeout_errors(
struct iscsi_node_stat_grps *igrps, char *page)
{
struct iscsi_node_acl *acl = container_of(igrps,
struct iscsi_node_acl, node_stat_grps);
struct se_node_acl *se_nacl = &acl->se_node_acl;
struct iscsi_session *sess;
struct se_session *se_sess;
ssize_t ret = 0;
spin_lock_bh(&se_nacl->nacl_sess_lock);
se_sess = se_nacl->nacl_sess;
if (se_sess) {
sess = se_sess->fabric_sess_ptr;
if (sess)
ret = snprintf(page, PAGE_SIZE, "%lu\n",
atomic_long_read(&sess->conn_timeout_errors));
}
spin_unlock_bh(&se_nacl->nacl_sess_lock);
return ret;
}
