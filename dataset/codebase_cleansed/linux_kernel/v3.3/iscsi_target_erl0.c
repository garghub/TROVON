void iscsit_set_dataout_sequence_values(
struct iscsi_cmd *cmd)
{
struct iscsi_conn *conn = cmd->conn;
if (cmd->unsolicited_data) {
cmd->seq_start_offset = cmd->write_data_done;
cmd->seq_end_offset = (cmd->write_data_done +
(cmd->data_length >
conn->sess->sess_ops->FirstBurstLength) ?
conn->sess->sess_ops->FirstBurstLength : cmd->data_length);
return;
}
if (!conn->sess->sess_ops->DataSequenceInOrder)
return;
if (!cmd->seq_start_offset && !cmd->seq_end_offset) {
cmd->seq_start_offset = cmd->write_data_done;
cmd->seq_end_offset = (cmd->data_length >
conn->sess->sess_ops->MaxBurstLength) ?
(cmd->write_data_done +
conn->sess->sess_ops->MaxBurstLength) : cmd->data_length;
} else {
cmd->seq_start_offset = cmd->seq_end_offset;
cmd->seq_end_offset = ((cmd->seq_end_offset +
conn->sess->sess_ops->MaxBurstLength) >=
cmd->data_length) ? cmd->data_length :
(cmd->seq_end_offset +
conn->sess->sess_ops->MaxBurstLength);
}
}
static int iscsit_dataout_within_command_recovery_check(
struct iscsi_cmd *cmd,
unsigned char *buf)
{
struct iscsi_conn *conn = cmd->conn;
struct iscsi_data *hdr = (struct iscsi_data *) buf;
u32 payload_length = ntoh24(hdr->dlength);
if (conn->sess->sess_ops->DataSequenceInOrder) {
if ((cmd->cmd_flags & ICF_WITHIN_COMMAND_RECOVERY) &&
(cmd->write_data_done != hdr->offset))
goto dump;
cmd->cmd_flags &= ~ICF_WITHIN_COMMAND_RECOVERY;
} else {
struct iscsi_seq *seq;
seq = iscsit_get_seq_holder(cmd, hdr->offset, payload_length);
if (!seq)
return DATAOUT_CANNOT_RECOVER;
cmd->seq_ptr = seq;
if (conn->sess->sess_ops->DataPDUInOrder) {
if ((seq->status ==
DATAOUT_SEQUENCE_WITHIN_COMMAND_RECOVERY) &&
((seq->offset != hdr->offset) ||
(seq->data_sn != hdr->datasn)))
goto dump;
} else {
if ((seq->status ==
DATAOUT_SEQUENCE_WITHIN_COMMAND_RECOVERY) &&
(seq->data_sn != hdr->datasn))
goto dump;
}
if (seq->status == DATAOUT_SEQUENCE_COMPLETE)
goto dump;
if (seq->status != DATAOUT_SEQUENCE_COMPLETE)
seq->status = 0;
}
return DATAOUT_NORMAL;
dump:
pr_err("Dumping DataOUT PDU Offset: %u Length: %d DataSN:"
" 0x%08x\n", hdr->offset, payload_length, hdr->datasn);
return iscsit_dump_data_payload(conn, payload_length, 1);
}
static int iscsit_dataout_check_unsolicited_sequence(
struct iscsi_cmd *cmd,
unsigned char *buf)
{
u32 first_burst_len;
struct iscsi_conn *conn = cmd->conn;
struct iscsi_data *hdr = (struct iscsi_data *) buf;
u32 payload_length = ntoh24(hdr->dlength);
if ((hdr->offset < cmd->seq_start_offset) ||
((hdr->offset + payload_length) > cmd->seq_end_offset)) {
pr_err("Command ITT: 0x%08x with Offset: %u,"
" Length: %u outside of Unsolicited Sequence %u:%u while"
" DataSequenceInOrder=Yes.\n", cmd->init_task_tag,
hdr->offset, payload_length, cmd->seq_start_offset,
cmd->seq_end_offset);
return DATAOUT_CANNOT_RECOVER;
}
first_burst_len = (cmd->first_burst_len + payload_length);
if (first_burst_len > conn->sess->sess_ops->FirstBurstLength) {
pr_err("Total %u bytes exceeds FirstBurstLength: %u"
" for this Unsolicited DataOut Burst.\n",
first_burst_len, conn->sess->sess_ops->FirstBurstLength);
transport_send_check_condition_and_sense(&cmd->se_cmd,
TCM_INCORRECT_AMOUNT_OF_DATA, 0);
return DATAOUT_CANNOT_RECOVER;
}
if (hdr->flags & ISCSI_FLAG_CMD_FINAL) {
if (!conn->sess->sess_ops->DataPDUInOrder)
goto out;
if ((first_burst_len != cmd->data_length) &&
(first_burst_len != conn->sess->sess_ops->FirstBurstLength)) {
pr_err("Unsolicited non-immediate data"
" received %u does not equal FirstBurstLength: %u, and"
" does not equal ExpXferLen %u.\n", first_burst_len,
conn->sess->sess_ops->FirstBurstLength,
cmd->data_length);
transport_send_check_condition_and_sense(&cmd->se_cmd,
TCM_INCORRECT_AMOUNT_OF_DATA, 0);
return DATAOUT_CANNOT_RECOVER;
}
} else {
if (first_burst_len == conn->sess->sess_ops->FirstBurstLength) {
pr_err("Command ITT: 0x%08x reached"
" FirstBurstLength: %u, but ISCSI_FLAG_CMD_FINAL is not set. protocol"
" error.\n", cmd->init_task_tag,
conn->sess->sess_ops->FirstBurstLength);
return DATAOUT_CANNOT_RECOVER;
}
if (first_burst_len == cmd->data_length) {
pr_err("Command ITT: 0x%08x reached"
" ExpXferLen: %u, but ISCSI_FLAG_CMD_FINAL is not set. protocol"
" error.\n", cmd->init_task_tag, cmd->data_length);
return DATAOUT_CANNOT_RECOVER;
}
}
out:
return DATAOUT_NORMAL;
}
static int iscsit_dataout_check_sequence(
struct iscsi_cmd *cmd,
unsigned char *buf)
{
u32 next_burst_len;
struct iscsi_conn *conn = cmd->conn;
struct iscsi_seq *seq = NULL;
struct iscsi_data *hdr = (struct iscsi_data *) buf;
u32 payload_length = ntoh24(hdr->dlength);
if (conn->sess->sess_ops->DataSequenceInOrder) {
if ((hdr->offset < cmd->seq_start_offset) ||
((hdr->offset + payload_length) > cmd->seq_end_offset)) {
pr_err("Command ITT: 0x%08x with Offset: %u,"
" Length: %u outside of Sequence %u:%u while"
" DataSequenceInOrder=Yes.\n", cmd->init_task_tag,
hdr->offset, payload_length, cmd->seq_start_offset,
cmd->seq_end_offset);
if (iscsit_dump_data_payload(conn, payload_length, 1) < 0)
return DATAOUT_CANNOT_RECOVER;
return DATAOUT_WITHIN_COMMAND_RECOVERY;
}
next_burst_len = (cmd->next_burst_len + payload_length);
} else {
seq = iscsit_get_seq_holder(cmd, hdr->offset, payload_length);
if (!seq)
return DATAOUT_CANNOT_RECOVER;
cmd->seq_ptr = seq;
if (seq->status == DATAOUT_SEQUENCE_COMPLETE) {
if (iscsit_dump_data_payload(conn, payload_length, 1) < 0)
return DATAOUT_CANNOT_RECOVER;
return DATAOUT_WITHIN_COMMAND_RECOVERY;
}
next_burst_len = (seq->next_burst_len + payload_length);
}
if (next_burst_len > conn->sess->sess_ops->MaxBurstLength) {
pr_err("Command ITT: 0x%08x, NextBurstLength: %u and"
" Length: %u exceeds MaxBurstLength: %u. protocol"
" error.\n", cmd->init_task_tag,
(next_burst_len - payload_length),
payload_length, conn->sess->sess_ops->MaxBurstLength);
return DATAOUT_CANNOT_RECOVER;
}
if (hdr->flags & ISCSI_FLAG_CMD_FINAL) {
if (!conn->sess->sess_ops->DataPDUInOrder)
goto out;
if (conn->sess->sess_ops->DataSequenceInOrder) {
if ((next_burst_len <
conn->sess->sess_ops->MaxBurstLength) &&
((cmd->write_data_done + payload_length) <
cmd->data_length)) {
pr_err("Command ITT: 0x%08x set ISCSI_FLAG_CMD_FINAL"
" before end of DataOUT sequence, protocol"
" error.\n", cmd->init_task_tag);
return DATAOUT_CANNOT_RECOVER;
}
} else {
if (next_burst_len < seq->xfer_len) {
pr_err("Command ITT: 0x%08x set ISCSI_FLAG_CMD_FINAL"
" before end of DataOUT sequence, protocol"
" error.\n", cmd->init_task_tag);
return DATAOUT_CANNOT_RECOVER;
}
}
} else {
if (conn->sess->sess_ops->DataSequenceInOrder) {
if (next_burst_len ==
conn->sess->sess_ops->MaxBurstLength) {
pr_err("Command ITT: 0x%08x reached"
" MaxBurstLength: %u, but ISCSI_FLAG_CMD_FINAL is"
" not set, protocol error.", cmd->init_task_tag,
conn->sess->sess_ops->MaxBurstLength);
return DATAOUT_CANNOT_RECOVER;
}
if ((cmd->write_data_done + payload_length) ==
cmd->data_length) {
pr_err("Command ITT: 0x%08x reached"
" last DataOUT PDU in sequence but ISCSI_FLAG_"
"CMD_FINAL is not set, protocol error.\n",
cmd->init_task_tag);
return DATAOUT_CANNOT_RECOVER;
}
} else {
if (next_burst_len == seq->xfer_len) {
pr_err("Command ITT: 0x%08x reached"
" last DataOUT PDU in sequence but ISCSI_FLAG_"
"CMD_FINAL is not set, protocol error.\n",
cmd->init_task_tag);
return DATAOUT_CANNOT_RECOVER;
}
}
}
out:
return DATAOUT_NORMAL;
}
static int iscsit_dataout_check_datasn(
struct iscsi_cmd *cmd,
unsigned char *buf)
{
int dump = 0, recovery = 0;
u32 data_sn = 0;
struct iscsi_conn *conn = cmd->conn;
struct iscsi_data *hdr = (struct iscsi_data *) buf;
u32 payload_length = ntoh24(hdr->dlength);
if (conn->sess->sess_ops->DataSequenceInOrder)
data_sn = cmd->data_sn;
else {
struct iscsi_seq *seq = cmd->seq_ptr;
data_sn = seq->data_sn;
}
if (hdr->datasn > data_sn) {
pr_err("Command ITT: 0x%08x, received DataSN: 0x%08x"
" higher than expected 0x%08x.\n", cmd->init_task_tag,
hdr->datasn, data_sn);
recovery = 1;
goto recover;
} else if (hdr->datasn < data_sn) {
pr_err("Command ITT: 0x%08x, received DataSN: 0x%08x"
" lower than expected 0x%08x, discarding payload.\n",
cmd->init_task_tag, hdr->datasn, data_sn);
dump = 1;
goto dump;
}
return DATAOUT_NORMAL;
recover:
if (!conn->sess->sess_ops->ErrorRecoveryLevel) {
pr_err("Unable to perform within-command recovery"
" while ERL=0.\n");
return DATAOUT_CANNOT_RECOVER;
}
dump:
if (iscsit_dump_data_payload(conn, payload_length, 1) < 0)
return DATAOUT_CANNOT_RECOVER;
return (recovery || dump) ? DATAOUT_WITHIN_COMMAND_RECOVERY :
DATAOUT_NORMAL;
}
static int iscsit_dataout_pre_datapduinorder_yes(
struct iscsi_cmd *cmd,
unsigned char *buf)
{
int dump = 0, recovery = 0;
struct iscsi_conn *conn = cmd->conn;
struct iscsi_data *hdr = (struct iscsi_data *) buf;
u32 payload_length = ntoh24(hdr->dlength);
if (conn->sess->sess_ops->DataSequenceInOrder) {
if (hdr->offset != cmd->write_data_done) {
pr_err("Command ITT: 0x%08x, received offset"
" %u different than expected %u.\n", cmd->init_task_tag,
hdr->offset, cmd->write_data_done);
recovery = 1;
goto recover;
}
} else {
struct iscsi_seq *seq = cmd->seq_ptr;
if (hdr->offset > seq->offset) {
pr_err("Command ITT: 0x%08x, received offset"
" %u greater than expected %u.\n", cmd->init_task_tag,
hdr->offset, seq->offset);
recovery = 1;
goto recover;
} else if (hdr->offset < seq->offset) {
pr_err("Command ITT: 0x%08x, received offset"
" %u less than expected %u, discarding payload.\n",
cmd->init_task_tag, hdr->offset, seq->offset);
dump = 1;
goto dump;
}
}
return DATAOUT_NORMAL;
recover:
if (!conn->sess->sess_ops->ErrorRecoveryLevel) {
pr_err("Unable to perform within-command recovery"
" while ERL=0.\n");
return DATAOUT_CANNOT_RECOVER;
}
dump:
if (iscsit_dump_data_payload(conn, payload_length, 1) < 0)
return DATAOUT_CANNOT_RECOVER;
return (recovery) ? iscsit_recover_dataout_sequence(cmd,
hdr->offset, payload_length) :
(dump) ? DATAOUT_WITHIN_COMMAND_RECOVERY : DATAOUT_NORMAL;
}
static int iscsit_dataout_pre_datapduinorder_no(
struct iscsi_cmd *cmd,
unsigned char *buf)
{
struct iscsi_pdu *pdu;
struct iscsi_data *hdr = (struct iscsi_data *) buf;
u32 payload_length = ntoh24(hdr->dlength);
pdu = iscsit_get_pdu_holder(cmd, hdr->offset, payload_length);
if (!pdu)
return DATAOUT_CANNOT_RECOVER;
cmd->pdu_ptr = pdu;
switch (pdu->status) {
case ISCSI_PDU_NOT_RECEIVED:
case ISCSI_PDU_CRC_FAILED:
case ISCSI_PDU_TIMED_OUT:
break;
case ISCSI_PDU_RECEIVED_OK:
pr_err("Command ITT: 0x%08x received already gotten"
" Offset: %u, Length: %u\n", cmd->init_task_tag,
hdr->offset, payload_length);
return iscsit_dump_data_payload(cmd->conn, payload_length, 1);
default:
return DATAOUT_CANNOT_RECOVER;
}
return DATAOUT_NORMAL;
}
static int iscsit_dataout_update_r2t(struct iscsi_cmd *cmd, u32 offset, u32 length)
{
struct iscsi_r2t *r2t;
if (cmd->unsolicited_data)
return 0;
r2t = iscsit_get_r2t_for_eos(cmd, offset, length);
if (!r2t)
return -1;
spin_lock_bh(&cmd->r2t_lock);
r2t->seq_complete = 1;
cmd->outstanding_r2ts--;
spin_unlock_bh(&cmd->r2t_lock);
return 0;
}
static int iscsit_dataout_update_datapduinorder_no(
struct iscsi_cmd *cmd,
u32 data_sn,
int f_bit)
{
int ret = 0;
struct iscsi_pdu *pdu = cmd->pdu_ptr;
pdu->data_sn = data_sn;
switch (pdu->status) {
case ISCSI_PDU_NOT_RECEIVED:
pdu->status = ISCSI_PDU_RECEIVED_OK;
break;
case ISCSI_PDU_CRC_FAILED:
pdu->status = ISCSI_PDU_RECEIVED_OK;
break;
case ISCSI_PDU_TIMED_OUT:
pdu->status = ISCSI_PDU_RECEIVED_OK;
break;
default:
return DATAOUT_CANNOT_RECOVER;
}
if (f_bit) {
ret = iscsit_dataout_datapduinorder_no_fbit(cmd, pdu);
if (ret == DATAOUT_CANNOT_RECOVER)
return ret;
}
return DATAOUT_NORMAL;
}
static int iscsit_dataout_post_crc_passed(
struct iscsi_cmd *cmd,
unsigned char *buf)
{
int ret, send_r2t = 0;
struct iscsi_conn *conn = cmd->conn;
struct iscsi_seq *seq = NULL;
struct iscsi_data *hdr = (struct iscsi_data *) buf;
u32 payload_length = ntoh24(hdr->dlength);
if (cmd->unsolicited_data) {
if ((cmd->first_burst_len + payload_length) ==
conn->sess->sess_ops->FirstBurstLength) {
if (iscsit_dataout_update_r2t(cmd, hdr->offset,
payload_length) < 0)
return DATAOUT_CANNOT_RECOVER;
send_r2t = 1;
}
if (!conn->sess->sess_ops->DataPDUInOrder) {
ret = iscsit_dataout_update_datapduinorder_no(cmd,
hdr->datasn, (hdr->flags & ISCSI_FLAG_CMD_FINAL));
if (ret == DATAOUT_CANNOT_RECOVER)
return ret;
}
cmd->first_burst_len += payload_length;
if (conn->sess->sess_ops->DataSequenceInOrder)
cmd->data_sn++;
else {
seq = cmd->seq_ptr;
seq->data_sn++;
seq->offset += payload_length;
}
if (send_r2t) {
if (seq)
seq->status = DATAOUT_SEQUENCE_COMPLETE;
cmd->first_burst_len = 0;
cmd->unsolicited_data = 0;
}
} else {
if (conn->sess->sess_ops->DataSequenceInOrder) {
if ((cmd->next_burst_len + payload_length) ==
conn->sess->sess_ops->MaxBurstLength) {
if (iscsit_dataout_update_r2t(cmd, hdr->offset,
payload_length) < 0)
return DATAOUT_CANNOT_RECOVER;
send_r2t = 1;
}
if (!conn->sess->sess_ops->DataPDUInOrder) {
ret = iscsit_dataout_update_datapduinorder_no(
cmd, hdr->datasn,
(hdr->flags & ISCSI_FLAG_CMD_FINAL));
if (ret == DATAOUT_CANNOT_RECOVER)
return ret;
}
cmd->next_burst_len += payload_length;
cmd->data_sn++;
if (send_r2t)
cmd->next_burst_len = 0;
} else {
seq = cmd->seq_ptr;
if ((seq->next_burst_len + payload_length) ==
seq->xfer_len) {
if (iscsit_dataout_update_r2t(cmd, hdr->offset,
payload_length) < 0)
return DATAOUT_CANNOT_RECOVER;
send_r2t = 1;
}
if (!conn->sess->sess_ops->DataPDUInOrder) {
ret = iscsit_dataout_update_datapduinorder_no(
cmd, hdr->datasn,
(hdr->flags & ISCSI_FLAG_CMD_FINAL));
if (ret == DATAOUT_CANNOT_RECOVER)
return ret;
}
seq->data_sn++;
seq->offset += payload_length;
seq->next_burst_len += payload_length;
if (send_r2t) {
seq->next_burst_len = 0;
seq->status = DATAOUT_SEQUENCE_COMPLETE;
}
}
}
if (send_r2t && conn->sess->sess_ops->DataSequenceInOrder)
cmd->data_sn = 0;
cmd->write_data_done += payload_length;
return (cmd->write_data_done == cmd->data_length) ?
DATAOUT_SEND_TO_TRANSPORT : (send_r2t) ?
DATAOUT_SEND_R2T : DATAOUT_NORMAL;
}
static int iscsit_dataout_post_crc_failed(
struct iscsi_cmd *cmd,
unsigned char *buf)
{
struct iscsi_conn *conn = cmd->conn;
struct iscsi_pdu *pdu;
struct iscsi_data *hdr = (struct iscsi_data *) buf;
u32 payload_length = ntoh24(hdr->dlength);
if (conn->sess->sess_ops->DataPDUInOrder)
goto recover;
pdu = cmd->pdu_ptr;
switch (pdu->status) {
case ISCSI_PDU_NOT_RECEIVED:
pdu->status = ISCSI_PDU_CRC_FAILED;
break;
case ISCSI_PDU_CRC_FAILED:
break;
case ISCSI_PDU_TIMED_OUT:
pdu->status = ISCSI_PDU_CRC_FAILED;
break;
default:
return DATAOUT_CANNOT_RECOVER;
}
recover:
return iscsit_recover_dataout_sequence(cmd, hdr->offset, payload_length);
}
extern int iscsit_check_pre_dataout(
struct iscsi_cmd *cmd,
unsigned char *buf)
{
int ret;
struct iscsi_conn *conn = cmd->conn;
ret = iscsit_dataout_within_command_recovery_check(cmd, buf);
if ((ret == DATAOUT_WITHIN_COMMAND_RECOVERY) ||
(ret == DATAOUT_CANNOT_RECOVER))
return ret;
ret = iscsit_dataout_check_datasn(cmd, buf);
if ((ret == DATAOUT_WITHIN_COMMAND_RECOVERY) ||
(ret == DATAOUT_CANNOT_RECOVER))
return ret;
if (cmd->unsolicited_data) {
ret = iscsit_dataout_check_unsolicited_sequence(cmd, buf);
if ((ret == DATAOUT_WITHIN_COMMAND_RECOVERY) ||
(ret == DATAOUT_CANNOT_RECOVER))
return ret;
} else {
ret = iscsit_dataout_check_sequence(cmd, buf);
if ((ret == DATAOUT_WITHIN_COMMAND_RECOVERY) ||
(ret == DATAOUT_CANNOT_RECOVER))
return ret;
}
return (conn->sess->sess_ops->DataPDUInOrder) ?
iscsit_dataout_pre_datapduinorder_yes(cmd, buf) :
iscsit_dataout_pre_datapduinorder_no(cmd, buf);
}
int iscsit_check_post_dataout(
struct iscsi_cmd *cmd,
unsigned char *buf,
u8 data_crc_failed)
{
struct iscsi_conn *conn = cmd->conn;
cmd->dataout_timeout_retries = 0;
if (!data_crc_failed)
return iscsit_dataout_post_crc_passed(cmd, buf);
else {
if (!conn->sess->sess_ops->ErrorRecoveryLevel) {
pr_err("Unable to recover from DataOUT CRC"
" failure while ERL=0, closing session.\n");
iscsit_add_reject_from_cmd(ISCSI_REASON_DATA_DIGEST_ERROR,
1, 0, buf, cmd);
return DATAOUT_CANNOT_RECOVER;
}
iscsit_add_reject_from_cmd(ISCSI_REASON_DATA_DIGEST_ERROR,
0, 0, buf, cmd);
return iscsit_dataout_post_crc_failed(cmd, buf);
}
}
static void iscsit_handle_time2retain_timeout(unsigned long data)
{
struct iscsi_session *sess = (struct iscsi_session *) data;
struct iscsi_portal_group *tpg = ISCSI_TPG_S(sess);
struct se_portal_group *se_tpg = &tpg->tpg_se_tpg;
spin_lock_bh(&se_tpg->session_lock);
if (sess->time2retain_timer_flags & ISCSI_TF_STOP) {
spin_unlock_bh(&se_tpg->session_lock);
return;
}
if (atomic_read(&sess->session_reinstatement)) {
pr_err("Exiting Time2Retain handler because"
" session_reinstatement=1\n");
spin_unlock_bh(&se_tpg->session_lock);
return;
}
sess->time2retain_timer_flags |= ISCSI_TF_EXPIRED;
pr_err("Time2Retain timer expired for SID: %u, cleaning up"
" iSCSI session.\n", sess->sid);
{
struct iscsi_tiqn *tiqn = tpg->tpg_tiqn;
if (tiqn) {
spin_lock(&tiqn->sess_err_stats.lock);
strcpy(tiqn->sess_err_stats.last_sess_fail_rem_name,
(void *)sess->sess_ops->InitiatorName);
tiqn->sess_err_stats.last_sess_failure_type =
ISCSI_SESS_ERR_CXN_TIMEOUT;
tiqn->sess_err_stats.cxn_timeout_errors++;
sess->conn_timeout_errors++;
spin_unlock(&tiqn->sess_err_stats.lock);
}
}
spin_unlock_bh(&se_tpg->session_lock);
iscsit_close_session(sess);
}
extern void iscsit_start_time2retain_handler(struct iscsi_session *sess)
{
int tpg_active;
spin_lock(&ISCSI_TPG_S(sess)->tpg_state_lock);
tpg_active = (ISCSI_TPG_S(sess)->tpg_state == TPG_STATE_ACTIVE);
spin_unlock(&ISCSI_TPG_S(sess)->tpg_state_lock);
if (!tpg_active)
return;
if (sess->time2retain_timer_flags & ISCSI_TF_RUNNING)
return;
pr_debug("Starting Time2Retain timer for %u seconds on"
" SID: %u\n", sess->sess_ops->DefaultTime2Retain, sess->sid);
init_timer(&sess->time2retain_timer);
sess->time2retain_timer.expires =
(get_jiffies_64() + sess->sess_ops->DefaultTime2Retain * HZ);
sess->time2retain_timer.data = (unsigned long)sess;
sess->time2retain_timer.function = iscsit_handle_time2retain_timeout;
sess->time2retain_timer_flags &= ~ISCSI_TF_STOP;
sess->time2retain_timer_flags |= ISCSI_TF_RUNNING;
add_timer(&sess->time2retain_timer);
}
extern int iscsit_stop_time2retain_timer(struct iscsi_session *sess)
{
struct iscsi_portal_group *tpg = ISCSI_TPG_S(sess);
struct se_portal_group *se_tpg = &tpg->tpg_se_tpg;
if (sess->time2retain_timer_flags & ISCSI_TF_EXPIRED)
return -1;
if (!(sess->time2retain_timer_flags & ISCSI_TF_RUNNING))
return 0;
sess->time2retain_timer_flags |= ISCSI_TF_STOP;
spin_unlock_bh(&se_tpg->session_lock);
del_timer_sync(&sess->time2retain_timer);
spin_lock_bh(&se_tpg->session_lock);
sess->time2retain_timer_flags &= ~ISCSI_TF_RUNNING;
pr_debug("Stopped Time2Retain Timer for SID: %u\n",
sess->sid);
return 0;
}
void iscsit_connection_reinstatement_rcfr(struct iscsi_conn *conn)
{
spin_lock_bh(&conn->state_lock);
if (atomic_read(&conn->connection_exit)) {
spin_unlock_bh(&conn->state_lock);
goto sleep;
}
if (atomic_read(&conn->transport_failed)) {
spin_unlock_bh(&conn->state_lock);
goto sleep;
}
spin_unlock_bh(&conn->state_lock);
iscsi_thread_set_force_reinstatement(conn);
sleep:
wait_for_completion(&conn->conn_wait_rcfr_comp);
complete(&conn->conn_post_wait_comp);
}
void iscsit_cause_connection_reinstatement(struct iscsi_conn *conn, int sleep)
{
spin_lock_bh(&conn->state_lock);
if (atomic_read(&conn->connection_exit)) {
spin_unlock_bh(&conn->state_lock);
return;
}
if (atomic_read(&conn->transport_failed)) {
spin_unlock_bh(&conn->state_lock);
return;
}
if (atomic_read(&conn->connection_reinstatement)) {
spin_unlock_bh(&conn->state_lock);
return;
}
if (iscsi_thread_set_force_reinstatement(conn) < 0) {
spin_unlock_bh(&conn->state_lock);
return;
}
atomic_set(&conn->connection_reinstatement, 1);
if (!sleep) {
spin_unlock_bh(&conn->state_lock);
return;
}
atomic_set(&conn->sleep_on_conn_wait_comp, 1);
spin_unlock_bh(&conn->state_lock);
wait_for_completion(&conn->conn_wait_comp);
complete(&conn->conn_post_wait_comp);
}
void iscsit_fall_back_to_erl0(struct iscsi_session *sess)
{
pr_debug("Falling back to ErrorRecoveryLevel=0 for SID:"
" %u\n", sess->sid);
atomic_set(&sess->session_fall_back_to_erl0, 1);
}
static void iscsit_handle_connection_cleanup(struct iscsi_conn *conn)
{
struct iscsi_session *sess = conn->sess;
if ((sess->sess_ops->ErrorRecoveryLevel == 2) &&
!atomic_read(&sess->session_reinstatement) &&
!atomic_read(&sess->session_fall_back_to_erl0))
iscsit_connection_recovery_transport_reset(conn);
else {
pr_debug("Performing cleanup for failed iSCSI"
" Connection ID: %hu from %s\n", conn->cid,
sess->sess_ops->InitiatorName);
iscsit_close_connection(conn);
}
}
extern void iscsit_take_action_for_connection_exit(struct iscsi_conn *conn)
{
spin_lock_bh(&conn->state_lock);
if (atomic_read(&conn->connection_exit)) {
spin_unlock_bh(&conn->state_lock);
return;
}
atomic_set(&conn->connection_exit, 1);
if (conn->conn_state == TARG_CONN_STATE_IN_LOGOUT) {
spin_unlock_bh(&conn->state_lock);
iscsit_close_connection(conn);
return;
}
if (conn->conn_state == TARG_CONN_STATE_CLEANUP_WAIT) {
spin_unlock_bh(&conn->state_lock);
return;
}
pr_debug("Moving to TARG_CONN_STATE_CLEANUP_WAIT.\n");
conn->conn_state = TARG_CONN_STATE_CLEANUP_WAIT;
spin_unlock_bh(&conn->state_lock);
iscsit_handle_connection_cleanup(conn);
}
int iscsit_recover_from_unknown_opcode(struct iscsi_conn *conn)
{
if (conn->of_marker > (conn->conn_ops->OFMarkInt * 4)) {
pr_err("Remaining bytes to OFMarker: %u exceeds"
" OFMarkInt bytes: %u.\n", conn->of_marker,
conn->conn_ops->OFMarkInt * 4);
return -1;
}
pr_debug("Advancing %u bytes in TCP stream to get to the"
" next OFMarker.\n", conn->of_marker);
if (iscsit_dump_data_payload(conn, conn->of_marker, 0) < 0)
return -1;
if (conn->of_marker_offset > (ISCSI_HDR_LEN + (ISCSI_CRC_LEN * 2) +
conn->conn_ops->MaxRecvDataSegmentLength)) {
pr_err("OfMarker offset value: %u exceeds limit.\n",
conn->of_marker_offset);
return -1;
}
pr_debug("Discarding %u bytes of TCP stream to get to the"
" next iSCSI Opcode.\n", conn->of_marker_offset);
if (iscsit_dump_data_payload(conn, conn->of_marker_offset, 0) < 0)
return -1;
return 0;
}
