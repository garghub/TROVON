void iscsit_determine_maxcmdsn(struct iscsi_session *sess)
{
struct se_node_acl *se_nacl;
if (sess->sess_ops->SessionType)
return;
se_nacl = sess->se_sess->se_node_acl;
sess->cmdsn_window = se_nacl->queue_depth;
sess->max_cmd_sn = (sess->max_cmd_sn + se_nacl->queue_depth) - 1;
}
void iscsit_increment_maxcmdsn(struct iscsi_cmd *cmd, struct iscsi_session *sess)
{
if (cmd->immediate_cmd || cmd->maxcmdsn_inc)
return;
cmd->maxcmdsn_inc = 1;
if (!mutex_trylock(&sess->cmdsn_mutex)) {
sess->max_cmd_sn += 1;
pr_debug("Updated MaxCmdSN to 0x%08x\n", sess->max_cmd_sn);
return;
}
sess->max_cmd_sn += 1;
pr_debug("Updated MaxCmdSN to 0x%08x\n", sess->max_cmd_sn);
mutex_unlock(&sess->cmdsn_mutex);
}
