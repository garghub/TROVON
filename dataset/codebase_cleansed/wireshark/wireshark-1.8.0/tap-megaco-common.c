static gboolean
megacostat_is_duplicate_reply(const gcp_cmd_t* cmd)
{
switch (cmd->type) {
GCP_CMD_REPLY_CASE
{
gcp_cmd_msg_t *cmd_msg;
for (cmd_msg = cmd->trx->cmds;
(cmd_msg != NULL) && (cmd_msg->cmd->msg->framenum != cmd->msg->framenum);
cmd_msg = cmd_msg->next) {
if (cmd_msg->cmd->type == cmd->type)
return TRUE;
}
return FALSE;
}
break;
default:
return FALSE;
break;
}
}
static gboolean
megacostat_had_request(const gcp_cmd_t* cmd)
{
switch (cmd->type) {
GCP_CMD_REPLY_CASE
{
gcp_cmd_msg_t *cmd_msg;
for (cmd_msg = cmd->trx->cmds;
(cmd_msg != NULL) && (cmd_msg->cmd->msg->framenum != cmd->msg->framenum);
cmd_msg = cmd_msg->next) {
switch (cmd_msg->cmd->type) {
GCP_CMD_REQ_CASE
return TRUE;
break;
default:
return FALSE;
break;
}
}
return FALSE;
}
break;
default:
return FALSE;
break;
}
}
int
megacostat_packet(void *pms, packet_info *pinfo, epan_dissect_t *edt _U_, const void *pmi)
{
megacostat_t *ms=(megacostat_t *)pms;
const gcp_cmd_t *mi=(const gcp_cmd_t*)pmi;
nstime_t delta;
int ret = 0;
switch (mi->type) {
GCP_CMD_REQ_CASE
if(!mi->trx->initial) {
return 0;
}
else if(mi->trx->initial->framenum != mi->msg->framenum){
ms->req_dup_num++;
}
else {
ms->open_req_num++;
}
break;
GCP_CMD_REPLY_CASE
if(megacostat_is_duplicate_reply(mi)){
ms->rsp_dup_num++;
}
else if (!megacostat_had_request(mi)) {
ms->disc_rsp_num++;
}
else {
ms->open_req_num--;
nstime_delta(&delta, &pinfo->fd->abs_ts, &mi->trx->initial->time);
switch(mi->type) {
case GCP_CMD_ADD_REPLY:
time_stat_update(&(ms->rtd[0]),&delta, pinfo);
break;
case GCP_CMD_MOVE_REPLY:
time_stat_update(&(ms->rtd[1]),&delta, pinfo);
break;
case GCP_CMD_MOD_REPLY:
time_stat_update(&(ms->rtd[2]),&delta, pinfo);
break;
case GCP_CMD_SUB_REPLY:
time_stat_update(&(ms->rtd[3]),&delta, pinfo);
break;
case GCP_CMD_AUDITCAP_REPLY:
time_stat_update(&(ms->rtd[4]),&delta, pinfo);
break;
case GCP_CMD_AUDITVAL_REPLY:
time_stat_update(&(ms->rtd[5]),&delta, pinfo);
break;
case GCP_CMD_NOTIFY_REPLY:
time_stat_update(&(ms->rtd[6]),&delta, pinfo);
break;
case GCP_CMD_SVCCHG_REPLY:
time_stat_update(&(ms->rtd[7]),&delta, pinfo);
break;
case GCP_CMD_TOPOLOGY_REPLY:
time_stat_update(&(ms->rtd[8]),&delta, pinfo);
break;
case GCP_CMD_REPLY:
time_stat_update(&(ms->rtd[9]),&delta, pinfo);
break;
default:
time_stat_update(&(ms->rtd[11]),&delta, pinfo);
}
time_stat_update(&(ms->rtd[10]),&delta, pinfo);
ret = 1;
}
break;
default:
break;
}
return ret;
}
