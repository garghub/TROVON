int iscsit_get_lun_for_tmr(
struct iscsi_cmd *cmd,
u64 lun)
{
u32 unpacked_lun = scsilun_to_int((struct scsi_lun *)&lun);
return transport_lookup_tmr_lun(&cmd->se_cmd, unpacked_lun);
}
int iscsit_get_lun_for_cmd(
struct iscsi_cmd *cmd,
unsigned char *cdb,
u64 lun)
{
u32 unpacked_lun = scsilun_to_int((struct scsi_lun *)&lun);
return transport_lookup_cmd_lun(&cmd->se_cmd, unpacked_lun);
}
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
mutex_lock(&sess->cmdsn_mutex);
sess->max_cmd_sn += 1;
pr_debug("Updated MaxCmdSN to 0x%08x\n", sess->max_cmd_sn);
mutex_unlock(&sess->cmdsn_mutex);
}
