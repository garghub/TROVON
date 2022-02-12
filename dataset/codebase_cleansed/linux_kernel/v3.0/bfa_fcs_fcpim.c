static void
bfa_fcs_itnim_sm_offline(struct bfa_fcs_itnim_s *itnim,
enum bfa_fcs_itnim_event event)
{
bfa_trc(itnim->fcs, itnim->rport->pwwn);
bfa_trc(itnim->fcs, event);
switch (event) {
case BFA_FCS_ITNIM_SM_ONLINE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_prli_send);
itnim->prli_retries = 0;
bfa_fcs_itnim_send_prli(itnim, NULL);
break;
case BFA_FCS_ITNIM_SM_OFFLINE:
bfa_sm_send_event(itnim->rport, RPSM_EVENT_FC4_OFFLINE);
break;
case BFA_FCS_ITNIM_SM_INITIATOR:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_initiator);
break;
case BFA_FCS_ITNIM_SM_DELETE:
bfa_fcs_itnim_free(itnim);
break;
default:
bfa_sm_fault(itnim->fcs, event);
}
}
static void
bfa_fcs_itnim_sm_prli_send(struct bfa_fcs_itnim_s *itnim,
enum bfa_fcs_itnim_event event)
{
bfa_trc(itnim->fcs, itnim->rport->pwwn);
bfa_trc(itnim->fcs, event);
switch (event) {
case BFA_FCS_ITNIM_SM_FRMSENT:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_prli);
break;
case BFA_FCS_ITNIM_SM_INITIATOR:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_initiator);
bfa_fcxp_walloc_cancel(itnim->fcs->bfa, &itnim->fcxp_wqe);
break;
case BFA_FCS_ITNIM_SM_OFFLINE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_offline);
bfa_fcxp_walloc_cancel(itnim->fcs->bfa, &itnim->fcxp_wqe);
bfa_sm_send_event(itnim->rport, RPSM_EVENT_FC4_OFFLINE);
break;
case BFA_FCS_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_offline);
bfa_fcxp_walloc_cancel(itnim->fcs->bfa, &itnim->fcxp_wqe);
bfa_fcs_itnim_free(itnim);
break;
default:
bfa_sm_fault(itnim->fcs, event);
}
}
static void
bfa_fcs_itnim_sm_prli(struct bfa_fcs_itnim_s *itnim,
enum bfa_fcs_itnim_event event)
{
bfa_trc(itnim->fcs, itnim->rport->pwwn);
bfa_trc(itnim->fcs, event);
switch (event) {
case BFA_FCS_ITNIM_SM_RSP_OK:
if (itnim->rport->scsi_function == BFA_RPORT_INITIATOR) {
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_initiator);
} else {
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_hcb_online);
bfa_itnim_online(itnim->bfa_itnim, itnim->seq_rec);
}
break;
case BFA_FCS_ITNIM_SM_RSP_ERROR:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_prli_retry);
bfa_timer_start(itnim->fcs->bfa, &itnim->timer,
bfa_fcs_itnim_timeout, itnim,
BFA_FCS_RETRY_TIMEOUT);
break;
case BFA_FCS_ITNIM_SM_OFFLINE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_offline);
bfa_fcxp_discard(itnim->fcxp);
bfa_sm_send_event(itnim->rport, RPSM_EVENT_FC4_OFFLINE);
break;
case BFA_FCS_ITNIM_SM_INITIATOR:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_initiator);
bfa_fcxp_discard(itnim->fcxp);
break;
case BFA_FCS_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_offline);
bfa_fcxp_discard(itnim->fcxp);
bfa_fcs_itnim_free(itnim);
break;
default:
bfa_sm_fault(itnim->fcs, event);
}
}
static void
bfa_fcs_itnim_sm_prli_retry(struct bfa_fcs_itnim_s *itnim,
enum bfa_fcs_itnim_event event)
{
bfa_trc(itnim->fcs, itnim->rport->pwwn);
bfa_trc(itnim->fcs, event);
switch (event) {
case BFA_FCS_ITNIM_SM_TIMEOUT:
if (itnim->prli_retries < BFA_FCS_RPORT_MAX_RETRIES) {
itnim->prli_retries++;
bfa_trc(itnim->fcs, itnim->prli_retries);
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_prli_send);
bfa_fcs_itnim_send_prli(itnim, NULL);
} else {
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_offline);
bfa_sm_send_event(itnim->rport, RPSM_EVENT_LOGO_IMP);
}
break;
case BFA_FCS_ITNIM_SM_OFFLINE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_offline);
bfa_timer_stop(&itnim->timer);
bfa_sm_send_event(itnim->rport, RPSM_EVENT_FC4_OFFLINE);
break;
case BFA_FCS_ITNIM_SM_INITIATOR:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_initiator);
bfa_timer_stop(&itnim->timer);
break;
case BFA_FCS_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_offline);
bfa_timer_stop(&itnim->timer);
bfa_fcs_itnim_free(itnim);
break;
default:
bfa_sm_fault(itnim->fcs, event);
}
}
static void
bfa_fcs_itnim_sm_hcb_online(struct bfa_fcs_itnim_s *itnim,
enum bfa_fcs_itnim_event event)
{
struct bfad_s *bfad = (struct bfad_s *)itnim->fcs->bfad;
char lpwwn_buf[BFA_STRING_32];
char rpwwn_buf[BFA_STRING_32];
bfa_trc(itnim->fcs, itnim->rport->pwwn);
bfa_trc(itnim->fcs, event);
switch (event) {
case BFA_FCS_ITNIM_SM_HCB_ONLINE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_online);
bfa_fcb_itnim_online(itnim->itnim_drv);
wwn2str(lpwwn_buf, bfa_fcs_lport_get_pwwn(itnim->rport->port));
wwn2str(rpwwn_buf, itnim->rport->pwwn);
BFA_LOG(KERN_INFO, bfad, bfa_log_level,
"Target (WWN = %s) is online for initiator (WWN = %s)\n",
rpwwn_buf, lpwwn_buf);
break;
case BFA_FCS_ITNIM_SM_OFFLINE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_offline);
bfa_itnim_offline(itnim->bfa_itnim);
bfa_sm_send_event(itnim->rport, RPSM_EVENT_FC4_OFFLINE);
break;
case BFA_FCS_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_offline);
bfa_fcs_itnim_free(itnim);
break;
default:
bfa_sm_fault(itnim->fcs, event);
}
}
static void
bfa_fcs_itnim_sm_online(struct bfa_fcs_itnim_s *itnim,
enum bfa_fcs_itnim_event event)
{
struct bfad_s *bfad = (struct bfad_s *)itnim->fcs->bfad;
char lpwwn_buf[BFA_STRING_32];
char rpwwn_buf[BFA_STRING_32];
bfa_trc(itnim->fcs, itnim->rport->pwwn);
bfa_trc(itnim->fcs, event);
switch (event) {
case BFA_FCS_ITNIM_SM_OFFLINE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_hcb_offline);
bfa_fcb_itnim_offline(itnim->itnim_drv);
bfa_itnim_offline(itnim->bfa_itnim);
wwn2str(lpwwn_buf, bfa_fcs_lport_get_pwwn(itnim->rport->port));
wwn2str(rpwwn_buf, itnim->rport->pwwn);
if (bfa_fcs_lport_is_online(itnim->rport->port) == BFA_TRUE)
BFA_LOG(KERN_ERR, bfad, bfa_log_level,
"Target (WWN = %s) connectivity lost for "
"initiator (WWN = %s)\n", rpwwn_buf, lpwwn_buf);
else
BFA_LOG(KERN_INFO, bfad, bfa_log_level,
"Target (WWN = %s) offlined by initiator (WWN = %s)\n",
rpwwn_buf, lpwwn_buf);
break;
case BFA_FCS_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_offline);
bfa_fcs_itnim_free(itnim);
break;
default:
bfa_sm_fault(itnim->fcs, event);
}
}
static void
bfa_fcs_itnim_sm_hcb_offline(struct bfa_fcs_itnim_s *itnim,
enum bfa_fcs_itnim_event event)
{
bfa_trc(itnim->fcs, itnim->rport->pwwn);
bfa_trc(itnim->fcs, event);
switch (event) {
case BFA_FCS_ITNIM_SM_HCB_OFFLINE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_offline);
bfa_sm_send_event(itnim->rport, RPSM_EVENT_FC4_OFFLINE);
break;
case BFA_FCS_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_offline);
bfa_fcs_itnim_free(itnim);
break;
default:
bfa_sm_fault(itnim->fcs, event);
}
}
static void
bfa_fcs_itnim_sm_initiator(struct bfa_fcs_itnim_s *itnim,
enum bfa_fcs_itnim_event event)
{
bfa_trc(itnim->fcs, itnim->rport->pwwn);
bfa_trc(itnim->fcs, event);
switch (event) {
case BFA_FCS_ITNIM_SM_OFFLINE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_offline);
bfa_sm_send_event(itnim->rport, RPSM_EVENT_FC4_OFFLINE);
break;
case BFA_FCS_ITNIM_SM_RSP_ERROR:
case BFA_FCS_ITNIM_SM_ONLINE:
case BFA_FCS_ITNIM_SM_INITIATOR:
break;
case BFA_FCS_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_offline);
bfa_fcs_itnim_free(itnim);
break;
default:
bfa_sm_fault(itnim->fcs, event);
}
}
static void
bfa_fcs_itnim_send_prli(void *itnim_cbarg, struct bfa_fcxp_s *fcxp_alloced)
{
struct bfa_fcs_itnim_s *itnim = itnim_cbarg;
struct bfa_fcs_rport_s *rport = itnim->rport;
struct bfa_fcs_lport_s *port = rport->port;
struct fchs_s fchs;
struct bfa_fcxp_s *fcxp;
int len;
bfa_trc(itnim->fcs, itnim->rport->pwwn);
fcxp = fcxp_alloced ? fcxp_alloced : bfa_fcs_fcxp_alloc(port->fcs);
if (!fcxp) {
itnim->stats.fcxp_alloc_wait++;
bfa_fcs_fcxp_alloc_wait(port->fcs->bfa, &itnim->fcxp_wqe,
bfa_fcs_itnim_send_prli, itnim);
return;
}
itnim->fcxp = fcxp;
len = fc_prli_build(&fchs, bfa_fcxp_get_reqbuf(fcxp),
itnim->rport->pid, bfa_fcs_lport_get_fcid(port), 0);
bfa_fcxp_send(fcxp, rport->bfa_rport, port->fabric->vf_id, port->lp_tag,
BFA_FALSE, FC_CLASS_3, len, &fchs,
bfa_fcs_itnim_prli_response, (void *)itnim,
FC_MAX_PDUSZ, FC_ELS_TOV);
itnim->stats.prli_sent++;
bfa_sm_send_event(itnim, BFA_FCS_ITNIM_SM_FRMSENT);
}
static void
bfa_fcs_itnim_prli_response(void *fcsarg, struct bfa_fcxp_s *fcxp, void *cbarg,
bfa_status_t req_status, u32 rsp_len,
u32 resid_len, struct fchs_s *rsp_fchs)
{
struct bfa_fcs_itnim_s *itnim = (struct bfa_fcs_itnim_s *) cbarg;
struct fc_els_cmd_s *els_cmd;
struct fc_prli_s *prli_resp;
struct fc_ls_rjt_s *ls_rjt;
struct fc_prli_params_s *sparams;
bfa_trc(itnim->fcs, req_status);
if (req_status != BFA_STATUS_OK) {
itnim->stats.prli_rsp_err++;
bfa_sm_send_event(itnim, BFA_FCS_ITNIM_SM_RSP_ERROR);
return;
}
els_cmd = (struct fc_els_cmd_s *) BFA_FCXP_RSP_PLD(fcxp);
if (els_cmd->els_code == FC_ELS_ACC) {
prli_resp = (struct fc_prli_s *) els_cmd;
if (fc_prli_rsp_parse(prli_resp, rsp_len) != FC_PARSE_OK) {
bfa_trc(itnim->fcs, rsp_len);
if (prli_resp->parampage.servparams.initiator) {
bfa_trc(itnim->fcs, prli_resp->parampage.type);
itnim->rport->scsi_function =
BFA_RPORT_INITIATOR;
itnim->stats.prli_rsp_acc++;
bfa_sm_send_event(itnim,
BFA_FCS_ITNIM_SM_RSP_OK);
return;
}
itnim->stats.prli_rsp_parse_err++;
return;
}
itnim->rport->scsi_function = BFA_RPORT_TARGET;
sparams = &prli_resp->parampage.servparams;
itnim->seq_rec = sparams->retry;
itnim->rec_support = sparams->rec_support;
itnim->task_retry_id = sparams->task_retry_id;
itnim->conf_comp = sparams->confirm;
itnim->stats.prli_rsp_acc++;
bfa_sm_send_event(itnim, BFA_FCS_ITNIM_SM_RSP_OK);
} else {
ls_rjt = (struct fc_ls_rjt_s *) BFA_FCXP_RSP_PLD(fcxp);
bfa_trc(itnim->fcs, ls_rjt->reason_code);
bfa_trc(itnim->fcs, ls_rjt->reason_code_expl);
itnim->stats.prli_rsp_rjt++;
bfa_sm_send_event(itnim, BFA_FCS_ITNIM_SM_RSP_ERROR);
}
}
static void
bfa_fcs_itnim_timeout(void *arg)
{
struct bfa_fcs_itnim_s *itnim = (struct bfa_fcs_itnim_s *) arg;
itnim->stats.timeout++;
bfa_sm_send_event(itnim, BFA_FCS_ITNIM_SM_TIMEOUT);
}
static void
bfa_fcs_itnim_free(struct bfa_fcs_itnim_s *itnim)
{
bfa_itnim_delete(itnim->bfa_itnim);
bfa_fcb_itnim_free(itnim->fcs->bfad, itnim->itnim_drv);
}
struct bfa_fcs_itnim_s *
bfa_fcs_itnim_create(struct bfa_fcs_rport_s *rport)
{
struct bfa_fcs_lport_s *port = rport->port;
struct bfa_fcs_itnim_s *itnim;
struct bfad_itnim_s *itnim_drv;
struct bfa_itnim_s *bfa_itnim;
bfa_fcb_itnim_alloc(port->fcs->bfad, &itnim, &itnim_drv);
if (itnim == NULL) {
bfa_trc(port->fcs, rport->pwwn);
return NULL;
}
itnim->rport = rport;
itnim->fcs = rport->fcs;
itnim->itnim_drv = itnim_drv;
bfa_itnim =
bfa_itnim_create(port->fcs->bfa, rport->bfa_rport, itnim);
if (bfa_itnim == NULL) {
bfa_trc(port->fcs, rport->pwwn);
bfa_fcb_itnim_free(port->fcs->bfad, itnim_drv);
WARN_ON(1);
return NULL;
}
itnim->bfa_itnim = bfa_itnim;
itnim->seq_rec = BFA_FALSE;
itnim->rec_support = BFA_FALSE;
itnim->conf_comp = BFA_FALSE;
itnim->task_retry_id = BFA_FALSE;
bfa_sm_set_state(itnim, bfa_fcs_itnim_sm_offline);
return itnim;
}
void
bfa_fcs_itnim_delete(struct bfa_fcs_itnim_s *itnim)
{
bfa_trc(itnim->fcs, itnim->rport->pid);
bfa_sm_send_event(itnim, BFA_FCS_ITNIM_SM_DELETE);
}
void
bfa_fcs_itnim_rport_online(struct bfa_fcs_itnim_s *itnim)
{
itnim->stats.onlines++;
if (!BFA_FCS_PID_IS_WKA(itnim->rport->pid)) {
bfa_sm_send_event(itnim, BFA_FCS_ITNIM_SM_ONLINE);
} else {
itnim->stats.initiator++;
bfa_sm_send_event(itnim, BFA_FCS_ITNIM_SM_INITIATOR);
}
}
void
bfa_fcs_itnim_rport_offline(struct bfa_fcs_itnim_s *itnim)
{
itnim->stats.offlines++;
bfa_sm_send_event(itnim, BFA_FCS_ITNIM_SM_OFFLINE);
}
void
bfa_fcs_itnim_is_initiator(struct bfa_fcs_itnim_s *itnim)
{
bfa_trc(itnim->fcs, itnim->rport->pid);
itnim->stats.initiator++;
bfa_sm_send_event(itnim, BFA_FCS_ITNIM_SM_INITIATOR);
}
bfa_status_t
bfa_fcs_itnim_get_online_state(struct bfa_fcs_itnim_s *itnim)
{
bfa_trc(itnim->fcs, itnim->rport->pid);
switch (bfa_sm_to_state(itnim_sm_table, itnim->sm)) {
case BFA_ITNIM_ONLINE:
case BFA_ITNIM_INITIATIOR:
return BFA_STATUS_OK;
default:
return BFA_STATUS_NO_FCPIM_NEXUS;
}
}
void
bfa_cb_itnim_online(void *cbarg)
{
struct bfa_fcs_itnim_s *itnim = (struct bfa_fcs_itnim_s *) cbarg;
bfa_trc(itnim->fcs, itnim->rport->pwwn);
bfa_sm_send_event(itnim, BFA_FCS_ITNIM_SM_HCB_ONLINE);
}
void
bfa_cb_itnim_offline(void *cb_arg)
{
struct bfa_fcs_itnim_s *itnim = (struct bfa_fcs_itnim_s *) cb_arg;
bfa_trc(itnim->fcs, itnim->rport->pwwn);
bfa_sm_send_event(itnim, BFA_FCS_ITNIM_SM_HCB_OFFLINE);
}
void
bfa_cb_itnim_tov_begin(void *cb_arg)
{
struct bfa_fcs_itnim_s *itnim = (struct bfa_fcs_itnim_s *) cb_arg;
bfa_trc(itnim->fcs, itnim->rport->pwwn);
}
void
bfa_cb_itnim_tov(void *cb_arg)
{
struct bfa_fcs_itnim_s *itnim = (struct bfa_fcs_itnim_s *) cb_arg;
struct bfad_itnim_s *itnim_drv = itnim->itnim_drv;
bfa_trc(itnim->fcs, itnim->rport->pwwn);
itnim_drv->state = ITNIM_STATE_TIMEOUT;
}
void
bfa_cb_itnim_sler(void *cb_arg)
{
struct bfa_fcs_itnim_s *itnim = (struct bfa_fcs_itnim_s *) cb_arg;
itnim->stats.sler++;
bfa_trc(itnim->fcs, itnim->rport->pwwn);
bfa_sm_send_event(itnim->rport, RPSM_EVENT_LOGO_IMP);
}
struct bfa_fcs_itnim_s *
bfa_fcs_itnim_lookup(struct bfa_fcs_lport_s *port, wwn_t rpwwn)
{
struct bfa_fcs_rport_s *rport;
rport = bfa_fcs_rport_lookup(port, rpwwn);
if (!rport)
return NULL;
WARN_ON(rport->itnim == NULL);
return rport->itnim;
}
bfa_status_t
bfa_fcs_itnim_attr_get(struct bfa_fcs_lport_s *port, wwn_t rpwwn,
struct bfa_itnim_attr_s *attr)
{
struct bfa_fcs_itnim_s *itnim = NULL;
itnim = bfa_fcs_itnim_lookup(port, rpwwn);
if (itnim == NULL)
return BFA_STATUS_NO_FCPIM_NEXUS;
attr->state = bfa_sm_to_state(itnim_sm_table, itnim->sm);
attr->retry = itnim->seq_rec;
attr->rec_support = itnim->rec_support;
attr->conf_comp = itnim->conf_comp;
attr->task_retry_id = itnim->task_retry_id;
return BFA_STATUS_OK;
}
bfa_status_t
bfa_fcs_itnim_stats_get(struct bfa_fcs_lport_s *port, wwn_t rpwwn,
struct bfa_itnim_stats_s *stats)
{
struct bfa_fcs_itnim_s *itnim = NULL;
WARN_ON(port == NULL);
itnim = bfa_fcs_itnim_lookup(port, rpwwn);
if (itnim == NULL)
return BFA_STATUS_NO_FCPIM_NEXUS;
memcpy(stats, &itnim->stats, sizeof(struct bfa_itnim_stats_s));
return BFA_STATUS_OK;
}
bfa_status_t
bfa_fcs_itnim_stats_clear(struct bfa_fcs_lport_s *port, wwn_t rpwwn)
{
struct bfa_fcs_itnim_s *itnim = NULL;
WARN_ON(port == NULL);
itnim = bfa_fcs_itnim_lookup(port, rpwwn);
if (itnim == NULL)
return BFA_STATUS_NO_FCPIM_NEXUS;
memset(&itnim->stats, 0, sizeof(struct bfa_itnim_stats_s));
return BFA_STATUS_OK;
}
void
bfa_fcs_fcpim_uf_recv(struct bfa_fcs_itnim_s *itnim,
struct fchs_s *fchs, u16 len)
{
struct fc_els_cmd_s *els_cmd;
bfa_trc(itnim->fcs, fchs->type);
if (fchs->type != FC_TYPE_ELS)
return;
els_cmd = (struct fc_els_cmd_s *) (fchs + 1);
bfa_trc(itnim->fcs, els_cmd->els_code);
switch (els_cmd->els_code) {
case FC_ELS_PRLO:
bfa_fcs_rport_prlo(itnim->rport, fchs->ox_id);
break;
default:
WARN_ON(1);
}
}
