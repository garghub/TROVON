static struct fc_rport_priv *fc_rport_lookup(const struct fc_lport *lport,
u32 port_id)
{
struct fc_rport_priv *rdata;
list_for_each_entry_rcu(rdata, &lport->disc.rports, peers)
if (rdata->ids.port_id == port_id)
return rdata;
return NULL;
}
static struct fc_rport_priv *fc_rport_create(struct fc_lport *lport,
u32 port_id)
{
struct fc_rport_priv *rdata;
rdata = lport->tt.rport_lookup(lport, port_id);
if (rdata)
return rdata;
rdata = kzalloc(sizeof(*rdata) + lport->rport_priv_size, GFP_KERNEL);
if (!rdata)
return NULL;
rdata->ids.node_name = -1;
rdata->ids.port_name = -1;
rdata->ids.port_id = port_id;
rdata->ids.roles = FC_RPORT_ROLE_UNKNOWN;
kref_init(&rdata->kref);
mutex_init(&rdata->rp_mutex);
rdata->local_port = lport;
rdata->rp_state = RPORT_ST_INIT;
rdata->event = RPORT_EV_NONE;
rdata->flags = FC_RP_FLAGS_REC_SUPPORTED;
rdata->e_d_tov = lport->e_d_tov;
rdata->r_a_tov = lport->r_a_tov;
rdata->maxframe_size = FC_MIN_MAX_PAYLOAD;
INIT_DELAYED_WORK(&rdata->retry_work, fc_rport_timeout);
INIT_WORK(&rdata->event_work, fc_rport_work);
if (port_id != FC_FID_DIR_SERV) {
rdata->lld_event_callback = lport->tt.rport_event_callback;
list_add_rcu(&rdata->peers, &lport->disc.rports);
}
return rdata;
}
static void fc_rport_destroy(struct kref *kref)
{
struct fc_rport_priv *rdata;
rdata = container_of(kref, struct fc_rport_priv, kref);
kfree_rcu(rdata, rcu);
}
static const char *fc_rport_state(struct fc_rport_priv *rdata)
{
const char *cp;
cp = fc_rport_state_names[rdata->rp_state];
if (!cp)
cp = "Unknown";
return cp;
}
void fc_set_rport_loss_tmo(struct fc_rport *rport, u32 timeout)
{
if (timeout)
rport->dev_loss_tmo = timeout;
else
rport->dev_loss_tmo = 1;
}
static unsigned int fc_plogi_get_maxframe(struct fc_els_flogi *flp,
unsigned int maxval)
{
unsigned int mfs;
mfs = ntohs(flp->fl_csp.sp_bb_data) & FC_SP_BB_DATA_MASK;
if (mfs >= FC_SP_MIN_MAX_PAYLOAD && mfs < maxval)
maxval = mfs;
mfs = ntohs(flp->fl_cssp[3 - 1].cp_rdfs);
if (mfs >= FC_SP_MIN_MAX_PAYLOAD && mfs < maxval)
maxval = mfs;
return maxval;
}
static void fc_rport_state_enter(struct fc_rport_priv *rdata,
enum fc_rport_state new)
{
if (rdata->rp_state != new)
rdata->retries = 0;
rdata->rp_state = new;
}
static void fc_rport_work(struct work_struct *work)
{
u32 port_id;
struct fc_rport_priv *rdata =
container_of(work, struct fc_rport_priv, event_work);
struct fc_rport_libfc_priv *rpriv;
enum fc_rport_event event;
struct fc_lport *lport = rdata->local_port;
struct fc_rport_operations *rport_ops;
struct fc_rport_identifiers ids;
struct fc_rport *rport;
struct fc4_prov *prov;
u8 type;
mutex_lock(&rdata->rp_mutex);
event = rdata->event;
rport_ops = rdata->ops;
rport = rdata->rport;
FC_RPORT_DBG(rdata, "work event %u\n", event);
switch (event) {
case RPORT_EV_READY:
ids = rdata->ids;
rdata->event = RPORT_EV_NONE;
rdata->major_retries = 0;
kref_get(&rdata->kref);
mutex_unlock(&rdata->rp_mutex);
if (!rport)
rport = fc_remote_port_add(lport->host, 0, &ids);
if (!rport) {
FC_RPORT_DBG(rdata, "Failed to add the rport\n");
lport->tt.rport_logoff(rdata);
kref_put(&rdata->kref, lport->tt.rport_destroy);
return;
}
mutex_lock(&rdata->rp_mutex);
if (rdata->rport)
FC_RPORT_DBG(rdata, "rport already allocated\n");
rdata->rport = rport;
rport->maxframe_size = rdata->maxframe_size;
rport->supported_classes = rdata->supported_classes;
rpriv = rport->dd_data;
rpriv->local_port = lport;
rpriv->rp_state = rdata->rp_state;
rpriv->flags = rdata->flags;
rpriv->e_d_tov = rdata->e_d_tov;
rpriv->r_a_tov = rdata->r_a_tov;
mutex_unlock(&rdata->rp_mutex);
if (rport_ops && rport_ops->event_callback) {
FC_RPORT_DBG(rdata, "callback ev %d\n", event);
rport_ops->event_callback(lport, rdata, event);
}
if (rdata->lld_event_callback) {
FC_RPORT_DBG(rdata, "lld callback ev %d\n", event);
rdata->lld_event_callback(lport, rdata, event);
}
kref_put(&rdata->kref, lport->tt.rport_destroy);
break;
case RPORT_EV_FAILED:
case RPORT_EV_LOGO:
case RPORT_EV_STOP:
if (rdata->prli_count) {
mutex_lock(&fc_prov_mutex);
for (type = 1; type < FC_FC4_PROV_SIZE; type++) {
prov = fc_passive_prov[type];
if (prov && prov->prlo)
prov->prlo(rdata);
}
mutex_unlock(&fc_prov_mutex);
}
port_id = rdata->ids.port_id;
mutex_unlock(&rdata->rp_mutex);
if (rport_ops && rport_ops->event_callback) {
FC_RPORT_DBG(rdata, "callback ev %d\n", event);
rport_ops->event_callback(lport, rdata, event);
}
if (rdata->lld_event_callback) {
FC_RPORT_DBG(rdata, "lld callback ev %d\n", event);
rdata->lld_event_callback(lport, rdata, event);
}
cancel_delayed_work_sync(&rdata->retry_work);
lport->tt.exch_mgr_reset(lport, 0, port_id);
lport->tt.exch_mgr_reset(lport, port_id, 0);
if (rport) {
rpriv = rport->dd_data;
rpriv->rp_state = RPORT_ST_DELETE;
mutex_lock(&rdata->rp_mutex);
rdata->rport = NULL;
mutex_unlock(&rdata->rp_mutex);
fc_remote_port_delete(rport);
}
mutex_lock(&lport->disc.disc_mutex);
mutex_lock(&rdata->rp_mutex);
if (rdata->rp_state == RPORT_ST_DELETE) {
if (port_id == FC_FID_DIR_SERV) {
rdata->event = RPORT_EV_NONE;
mutex_unlock(&rdata->rp_mutex);
kref_put(&rdata->kref, lport->tt.rport_destroy);
} else if ((rdata->flags & FC_RP_STARTED) &&
rdata->major_retries <
lport->max_rport_retry_count) {
rdata->major_retries++;
rdata->event = RPORT_EV_NONE;
FC_RPORT_DBG(rdata, "work restart\n");
fc_rport_enter_flogi(rdata);
mutex_unlock(&rdata->rp_mutex);
} else {
FC_RPORT_DBG(rdata, "work delete\n");
list_del_rcu(&rdata->peers);
mutex_unlock(&rdata->rp_mutex);
kref_put(&rdata->kref, lport->tt.rport_destroy);
}
} else {
rdata->event = RPORT_EV_NONE;
if (rdata->rp_state == RPORT_ST_READY)
fc_rport_enter_ready(rdata);
mutex_unlock(&rdata->rp_mutex);
}
mutex_unlock(&lport->disc.disc_mutex);
break;
default:
mutex_unlock(&rdata->rp_mutex);
break;
}
}
static int fc_rport_login(struct fc_rport_priv *rdata)
{
mutex_lock(&rdata->rp_mutex);
rdata->flags |= FC_RP_STARTED;
switch (rdata->rp_state) {
case RPORT_ST_READY:
FC_RPORT_DBG(rdata, "ADISC port\n");
fc_rport_enter_adisc(rdata);
break;
case RPORT_ST_DELETE:
FC_RPORT_DBG(rdata, "Restart deleted port\n");
break;
default:
FC_RPORT_DBG(rdata, "Login to port\n");
fc_rport_enter_flogi(rdata);
break;
}
mutex_unlock(&rdata->rp_mutex);
return 0;
}
static void fc_rport_enter_delete(struct fc_rport_priv *rdata,
enum fc_rport_event event)
{
if (rdata->rp_state == RPORT_ST_DELETE)
return;
FC_RPORT_DBG(rdata, "Delete port\n");
fc_rport_state_enter(rdata, RPORT_ST_DELETE);
if (rdata->event == RPORT_EV_NONE)
queue_work(rport_event_queue, &rdata->event_work);
rdata->event = event;
}
static int fc_rport_logoff(struct fc_rport_priv *rdata)
{
mutex_lock(&rdata->rp_mutex);
FC_RPORT_DBG(rdata, "Remove port\n");
rdata->flags &= ~FC_RP_STARTED;
if (rdata->rp_state == RPORT_ST_DELETE) {
FC_RPORT_DBG(rdata, "Port in Delete state, not removing\n");
goto out;
}
fc_rport_enter_logo(rdata);
fc_rport_enter_delete(rdata, RPORT_EV_STOP);
out:
mutex_unlock(&rdata->rp_mutex);
return 0;
}
static void fc_rport_enter_ready(struct fc_rport_priv *rdata)
{
fc_rport_state_enter(rdata, RPORT_ST_READY);
FC_RPORT_DBG(rdata, "Port is Ready\n");
if (rdata->event == RPORT_EV_NONE)
queue_work(rport_event_queue, &rdata->event_work);
rdata->event = RPORT_EV_READY;
}
static void fc_rport_timeout(struct work_struct *work)
{
struct fc_rport_priv *rdata =
container_of(work, struct fc_rport_priv, retry_work.work);
mutex_lock(&rdata->rp_mutex);
switch (rdata->rp_state) {
case RPORT_ST_FLOGI:
fc_rport_enter_flogi(rdata);
break;
case RPORT_ST_PLOGI:
fc_rport_enter_plogi(rdata);
break;
case RPORT_ST_PRLI:
fc_rport_enter_prli(rdata);
break;
case RPORT_ST_RTV:
fc_rport_enter_rtv(rdata);
break;
case RPORT_ST_ADISC:
fc_rport_enter_adisc(rdata);
break;
case RPORT_ST_PLOGI_WAIT:
case RPORT_ST_READY:
case RPORT_ST_INIT:
case RPORT_ST_DELETE:
break;
}
mutex_unlock(&rdata->rp_mutex);
}
static void fc_rport_error(struct fc_rport_priv *rdata, struct fc_frame *fp)
{
FC_RPORT_DBG(rdata, "Error %ld in state %s, retries %d\n",
IS_ERR(fp) ? -PTR_ERR(fp) : 0,
fc_rport_state(rdata), rdata->retries);
switch (rdata->rp_state) {
case RPORT_ST_FLOGI:
case RPORT_ST_PLOGI:
rdata->flags &= ~FC_RP_STARTED;
fc_rport_enter_delete(rdata, RPORT_EV_FAILED);
break;
case RPORT_ST_RTV:
fc_rport_enter_ready(rdata);
break;
case RPORT_ST_PRLI:
case RPORT_ST_ADISC:
fc_rport_enter_logo(rdata);
break;
case RPORT_ST_PLOGI_WAIT:
case RPORT_ST_DELETE:
case RPORT_ST_READY:
case RPORT_ST_INIT:
break;
}
}
static void fc_rport_error_retry(struct fc_rport_priv *rdata,
struct fc_frame *fp)
{
unsigned long delay = msecs_to_jiffies(FC_DEF_E_D_TOV);
if (PTR_ERR(fp) == -FC_EX_CLOSED)
goto out;
if (rdata->retries < rdata->local_port->max_rport_retry_count) {
FC_RPORT_DBG(rdata, "Error %ld in state %s, retrying\n",
PTR_ERR(fp), fc_rport_state(rdata));
rdata->retries++;
if (PTR_ERR(fp) == -FC_EX_TIMEOUT)
delay = 0;
schedule_delayed_work(&rdata->retry_work, delay);
return;
}
out:
fc_rport_error(rdata, fp);
}
static int fc_rport_login_complete(struct fc_rport_priv *rdata,
struct fc_frame *fp)
{
struct fc_lport *lport = rdata->local_port;
struct fc_els_flogi *flogi;
unsigned int e_d_tov;
u16 csp_flags;
flogi = fc_frame_payload_get(fp, sizeof(*flogi));
if (!flogi)
return -EINVAL;
csp_flags = ntohs(flogi->fl_csp.sp_features);
if (fc_frame_payload_op(fp) == ELS_FLOGI) {
if (csp_flags & FC_SP_FT_FPORT) {
FC_RPORT_DBG(rdata, "Fabric bit set in FLOGI\n");
return -EINVAL;
}
} else {
e_d_tov = ntohl(flogi->fl_csp.sp_e_d_tov);
if (csp_flags & FC_SP_FT_EDTR)
e_d_tov /= 1000000;
if (e_d_tov > rdata->e_d_tov)
rdata->e_d_tov = e_d_tov;
}
rdata->maxframe_size = fc_plogi_get_maxframe(flogi, lport->mfs);
return 0;
}
static void fc_rport_flogi_resp(struct fc_seq *sp, struct fc_frame *fp,
void *rp_arg)
{
struct fc_rport_priv *rdata = rp_arg;
struct fc_lport *lport = rdata->local_port;
struct fc_els_flogi *flogi;
unsigned int r_a_tov;
FC_RPORT_DBG(rdata, "Received a FLOGI %s\n", fc_els_resp_type(fp));
if (fp == ERR_PTR(-FC_EX_CLOSED))
goto put;
mutex_lock(&rdata->rp_mutex);
if (rdata->rp_state != RPORT_ST_FLOGI) {
FC_RPORT_DBG(rdata, "Received a FLOGI response, but in state "
"%s\n", fc_rport_state(rdata));
if (IS_ERR(fp))
goto err;
goto out;
}
if (IS_ERR(fp)) {
fc_rport_error(rdata, fp);
goto err;
}
if (fc_frame_payload_op(fp) != ELS_LS_ACC)
goto bad;
if (fc_rport_login_complete(rdata, fp))
goto bad;
flogi = fc_frame_payload_get(fp, sizeof(*flogi));
if (!flogi)
goto bad;
r_a_tov = ntohl(flogi->fl_csp.sp_r_a_tov);
if (r_a_tov > rdata->r_a_tov)
rdata->r_a_tov = r_a_tov;
if (rdata->ids.port_name < lport->wwpn)
fc_rport_enter_plogi(rdata);
else
fc_rport_state_enter(rdata, RPORT_ST_PLOGI_WAIT);
out:
fc_frame_free(fp);
err:
mutex_unlock(&rdata->rp_mutex);
put:
kref_put(&rdata->kref, rdata->local_port->tt.rport_destroy);
return;
bad:
FC_RPORT_DBG(rdata, "Bad FLOGI response\n");
fc_rport_error_retry(rdata, fp);
goto out;
}
static void fc_rport_enter_flogi(struct fc_rport_priv *rdata)
{
struct fc_lport *lport = rdata->local_port;
struct fc_frame *fp;
if (!lport->point_to_multipoint)
return fc_rport_enter_plogi(rdata);
FC_RPORT_DBG(rdata, "Entered FLOGI state from %s state\n",
fc_rport_state(rdata));
fc_rport_state_enter(rdata, RPORT_ST_FLOGI);
fp = fc_frame_alloc(lport, sizeof(struct fc_els_flogi));
if (!fp)
return fc_rport_error_retry(rdata, fp);
if (!lport->tt.elsct_send(lport, rdata->ids.port_id, fp, ELS_FLOGI,
fc_rport_flogi_resp, rdata,
2 * lport->r_a_tov))
fc_rport_error_retry(rdata, NULL);
else
kref_get(&rdata->kref);
}
static void fc_rport_recv_flogi_req(struct fc_lport *lport,
struct fc_frame *rx_fp)
{
struct fc_disc *disc;
struct fc_els_flogi *flp;
struct fc_rport_priv *rdata;
struct fc_frame *fp = rx_fp;
struct fc_seq_els_data rjt_data;
u32 sid;
sid = fc_frame_sid(fp);
FC_RPORT_ID_DBG(lport, sid, "Received FLOGI request\n");
disc = &lport->disc;
mutex_lock(&disc->disc_mutex);
if (!lport->point_to_multipoint) {
rjt_data.reason = ELS_RJT_UNSUP;
rjt_data.explan = ELS_EXPL_NONE;
goto reject;
}
flp = fc_frame_payload_get(fp, sizeof(*flp));
if (!flp) {
rjt_data.reason = ELS_RJT_LOGIC;
rjt_data.explan = ELS_EXPL_INV_LEN;
goto reject;
}
rdata = lport->tt.rport_lookup(lport, sid);
if (!rdata) {
rjt_data.reason = ELS_RJT_FIP;
rjt_data.explan = ELS_EXPL_NOT_NEIGHBOR;
goto reject;
}
mutex_lock(&rdata->rp_mutex);
FC_RPORT_DBG(rdata, "Received FLOGI in %s state\n",
fc_rport_state(rdata));
switch (rdata->rp_state) {
case RPORT_ST_INIT:
if (lport->point_to_multipoint)
break;
case RPORT_ST_DELETE:
mutex_unlock(&rdata->rp_mutex);
rjt_data.reason = ELS_RJT_FIP;
rjt_data.explan = ELS_EXPL_NOT_NEIGHBOR;
goto reject;
case RPORT_ST_FLOGI:
case RPORT_ST_PLOGI_WAIT:
case RPORT_ST_PLOGI:
break;
case RPORT_ST_PRLI:
case RPORT_ST_RTV:
case RPORT_ST_READY:
case RPORT_ST_ADISC:
fc_rport_enter_delete(rdata, RPORT_EV_LOGO);
mutex_unlock(&rdata->rp_mutex);
rjt_data.reason = ELS_RJT_BUSY;
rjt_data.explan = ELS_EXPL_NONE;
goto reject;
}
if (fc_rport_login_complete(rdata, fp)) {
mutex_unlock(&rdata->rp_mutex);
rjt_data.reason = ELS_RJT_LOGIC;
rjt_data.explan = ELS_EXPL_NONE;
goto reject;
}
fp = fc_frame_alloc(lport, sizeof(*flp));
if (!fp)
goto out;
fc_flogi_fill(lport, fp);
flp = fc_frame_payload_get(fp, sizeof(*flp));
flp->fl_cmd = ELS_LS_ACC;
fc_fill_reply_hdr(fp, rx_fp, FC_RCTL_ELS_REP, 0);
lport->tt.frame_send(lport, fp);
if (rdata->ids.port_name < lport->wwpn)
fc_rport_enter_plogi(rdata);
else
fc_rport_state_enter(rdata, RPORT_ST_PLOGI_WAIT);
out:
mutex_unlock(&rdata->rp_mutex);
mutex_unlock(&disc->disc_mutex);
fc_frame_free(rx_fp);
return;
reject:
mutex_unlock(&disc->disc_mutex);
lport->tt.seq_els_rsp_send(rx_fp, ELS_LS_RJT, &rjt_data);
fc_frame_free(rx_fp);
}
static void fc_rport_plogi_resp(struct fc_seq *sp, struct fc_frame *fp,
void *rdata_arg)
{
struct fc_rport_priv *rdata = rdata_arg;
struct fc_lport *lport = rdata->local_port;
struct fc_els_flogi *plp = NULL;
u16 csp_seq;
u16 cssp_seq;
u8 op;
mutex_lock(&rdata->rp_mutex);
FC_RPORT_DBG(rdata, "Received a PLOGI %s\n", fc_els_resp_type(fp));
if (rdata->rp_state != RPORT_ST_PLOGI) {
FC_RPORT_DBG(rdata, "Received a PLOGI response, but in state "
"%s\n", fc_rport_state(rdata));
if (IS_ERR(fp))
goto err;
goto out;
}
if (IS_ERR(fp)) {
fc_rport_error_retry(rdata, fp);
goto err;
}
op = fc_frame_payload_op(fp);
if (op == ELS_LS_ACC &&
(plp = fc_frame_payload_get(fp, sizeof(*plp))) != NULL) {
rdata->ids.port_name = get_unaligned_be64(&plp->fl_wwpn);
rdata->ids.node_name = get_unaligned_be64(&plp->fl_wwnn);
rdata->sp_features = ntohs(plp->fl_csp.sp_features);
if (lport->point_to_multipoint)
fc_rport_login_complete(rdata, fp);
csp_seq = ntohs(plp->fl_csp.sp_tot_seq);
cssp_seq = ntohs(plp->fl_cssp[3 - 1].cp_con_seq);
if (cssp_seq < csp_seq)
csp_seq = cssp_seq;
rdata->max_seq = csp_seq;
rdata->maxframe_size = fc_plogi_get_maxframe(plp, lport->mfs);
fc_rport_enter_prli(rdata);
} else
fc_rport_error_retry(rdata, fp);
out:
fc_frame_free(fp);
err:
mutex_unlock(&rdata->rp_mutex);
kref_put(&rdata->kref, rdata->local_port->tt.rport_destroy);
}
static void fc_rport_enter_plogi(struct fc_rport_priv *rdata)
{
struct fc_lport *lport = rdata->local_port;
struct fc_frame *fp;
FC_RPORT_DBG(rdata, "Port entered PLOGI state from %s state\n",
fc_rport_state(rdata));
fc_rport_state_enter(rdata, RPORT_ST_PLOGI);
rdata->maxframe_size = FC_MIN_MAX_PAYLOAD;
fp = fc_frame_alloc(lport, sizeof(struct fc_els_flogi));
if (!fp) {
FC_RPORT_DBG(rdata, "%s frame alloc failed\n", __func__);
fc_rport_error_retry(rdata, fp);
return;
}
rdata->e_d_tov = lport->e_d_tov;
if (!lport->tt.elsct_send(lport, rdata->ids.port_id, fp, ELS_PLOGI,
fc_rport_plogi_resp, rdata,
2 * lport->r_a_tov))
fc_rport_error_retry(rdata, NULL);
else
kref_get(&rdata->kref);
}
static void fc_rport_prli_resp(struct fc_seq *sp, struct fc_frame *fp,
void *rdata_arg)
{
struct fc_rport_priv *rdata = rdata_arg;
struct {
struct fc_els_prli prli;
struct fc_els_spp spp;
} *pp;
struct fc_els_spp temp_spp;
struct fc4_prov *prov;
u32 roles = FC_RPORT_ROLE_UNKNOWN;
u32 fcp_parm = 0;
u8 op;
u8 resp_code = 0;
mutex_lock(&rdata->rp_mutex);
FC_RPORT_DBG(rdata, "Received a PRLI %s\n", fc_els_resp_type(fp));
if (rdata->rp_state != RPORT_ST_PRLI) {
FC_RPORT_DBG(rdata, "Received a PRLI response, but in state "
"%s\n", fc_rport_state(rdata));
if (IS_ERR(fp))
goto err;
goto out;
}
if (IS_ERR(fp)) {
fc_rport_error_retry(rdata, fp);
goto err;
}
rdata->ids.roles = FC_RPORT_ROLE_UNKNOWN;
op = fc_frame_payload_op(fp);
if (op == ELS_LS_ACC) {
pp = fc_frame_payload_get(fp, sizeof(*pp));
if (!pp)
goto out;
resp_code = (pp->spp.spp_flags & FC_SPP_RESP_MASK);
FC_RPORT_DBG(rdata, "PRLI spp_flags = 0x%x\n",
pp->spp.spp_flags);
rdata->spp_type = pp->spp.spp_type;
if (resp_code != FC_SPP_RESP_ACK) {
if (resp_code == FC_SPP_RESP_CONF)
fc_rport_error(rdata, fp);
else
fc_rport_error_retry(rdata, fp);
goto out;
}
if (pp->prli.prli_spp_len < sizeof(pp->spp))
goto out;
fcp_parm = ntohl(pp->spp.spp_params);
if (fcp_parm & FCP_SPPF_RETRY)
rdata->flags |= FC_RP_FLAGS_RETRY;
if (fcp_parm & FCP_SPPF_CONF_COMPL)
rdata->flags |= FC_RP_FLAGS_CONF_REQ;
prov = fc_passive_prov[FC_TYPE_FCP];
if (prov) {
memset(&temp_spp, 0, sizeof(temp_spp));
prov->prli(rdata, pp->prli.prli_spp_len,
&pp->spp, &temp_spp);
}
rdata->supported_classes = FC_COS_CLASS3;
if (fcp_parm & FCP_SPPF_INIT_FCN)
roles |= FC_RPORT_ROLE_FCP_INITIATOR;
if (fcp_parm & FCP_SPPF_TARG_FCN)
roles |= FC_RPORT_ROLE_FCP_TARGET;
rdata->ids.roles = roles;
fc_rport_enter_rtv(rdata);
} else {
FC_RPORT_DBG(rdata, "Bad ELS response for PRLI command\n");
fc_rport_error_retry(rdata, fp);
}
out:
fc_frame_free(fp);
err:
mutex_unlock(&rdata->rp_mutex);
kref_put(&rdata->kref, rdata->local_port->tt.rport_destroy);
}
static void fc_rport_enter_prli(struct fc_rport_priv *rdata)
{
struct fc_lport *lport = rdata->local_port;
struct {
struct fc_els_prli prli;
struct fc_els_spp spp;
} *pp;
struct fc_frame *fp;
struct fc4_prov *prov;
if (rdata->ids.port_id >= FC_FID_DOM_MGR) {
fc_rport_enter_ready(rdata);
return;
}
FC_RPORT_DBG(rdata, "Port entered PRLI state from %s state\n",
fc_rport_state(rdata));
fc_rport_state_enter(rdata, RPORT_ST_PRLI);
fp = fc_frame_alloc(lport, sizeof(*pp));
if (!fp) {
fc_rport_error_retry(rdata, fp);
return;
}
fc_prli_fill(lport, fp);
prov = fc_passive_prov[FC_TYPE_FCP];
if (prov) {
pp = fc_frame_payload_get(fp, sizeof(*pp));
prov->prli(rdata, sizeof(pp->spp), NULL, &pp->spp);
}
fc_fill_fc_hdr(fp, FC_RCTL_ELS_REQ, rdata->ids.port_id,
fc_host_port_id(lport->host), FC_TYPE_ELS,
FC_FC_FIRST_SEQ | FC_FC_END_SEQ | FC_FC_SEQ_INIT, 0);
if (!lport->tt.exch_seq_send(lport, fp, fc_rport_prli_resp,
NULL, rdata, 2 * lport->r_a_tov))
fc_rport_error_retry(rdata, NULL);
else
kref_get(&rdata->kref);
}
static void fc_rport_rtv_resp(struct fc_seq *sp, struct fc_frame *fp,
void *rdata_arg)
{
struct fc_rport_priv *rdata = rdata_arg;
u8 op;
mutex_lock(&rdata->rp_mutex);
FC_RPORT_DBG(rdata, "Received a RTV %s\n", fc_els_resp_type(fp));
if (rdata->rp_state != RPORT_ST_RTV) {
FC_RPORT_DBG(rdata, "Received a RTV response, but in state "
"%s\n", fc_rport_state(rdata));
if (IS_ERR(fp))
goto err;
goto out;
}
if (IS_ERR(fp)) {
fc_rport_error(rdata, fp);
goto err;
}
op = fc_frame_payload_op(fp);
if (op == ELS_LS_ACC) {
struct fc_els_rtv_acc *rtv;
u32 toq;
u32 tov;
rtv = fc_frame_payload_get(fp, sizeof(*rtv));
if (rtv) {
toq = ntohl(rtv->rtv_toq);
tov = ntohl(rtv->rtv_r_a_tov);
if (tov == 0)
tov = 1;
rdata->r_a_tov = tov;
tov = ntohl(rtv->rtv_e_d_tov);
if (toq & FC_ELS_RTV_EDRES)
tov /= 1000000;
if (tov == 0)
tov = 1;
rdata->e_d_tov = tov;
}
}
fc_rport_enter_ready(rdata);
out:
fc_frame_free(fp);
err:
mutex_unlock(&rdata->rp_mutex);
kref_put(&rdata->kref, rdata->local_port->tt.rport_destroy);
}
static void fc_rport_enter_rtv(struct fc_rport_priv *rdata)
{
struct fc_frame *fp;
struct fc_lport *lport = rdata->local_port;
FC_RPORT_DBG(rdata, "Port entered RTV state from %s state\n",
fc_rport_state(rdata));
fc_rport_state_enter(rdata, RPORT_ST_RTV);
fp = fc_frame_alloc(lport, sizeof(struct fc_els_rtv));
if (!fp) {
fc_rport_error_retry(rdata, fp);
return;
}
if (!lport->tt.elsct_send(lport, rdata->ids.port_id, fp, ELS_RTV,
fc_rport_rtv_resp, rdata,
2 * lport->r_a_tov))
fc_rport_error_retry(rdata, NULL);
else
kref_get(&rdata->kref);
}
static void fc_rport_logo_resp(struct fc_seq *sp, struct fc_frame *fp,
void *lport_arg)
{
struct fc_lport *lport = lport_arg;
FC_RPORT_ID_DBG(lport, fc_seq_exch(sp)->did,
"Received a LOGO %s\n", fc_els_resp_type(fp));
if (IS_ERR(fp))
return;
fc_frame_free(fp);
}
static void fc_rport_enter_logo(struct fc_rport_priv *rdata)
{
struct fc_lport *lport = rdata->local_port;
struct fc_frame *fp;
FC_RPORT_DBG(rdata, "Port sending LOGO from %s state\n",
fc_rport_state(rdata));
fp = fc_frame_alloc(lport, sizeof(struct fc_els_logo));
if (!fp)
return;
(void)lport->tt.elsct_send(lport, rdata->ids.port_id, fp, ELS_LOGO,
fc_rport_logo_resp, lport, 0);
}
static void fc_rport_adisc_resp(struct fc_seq *sp, struct fc_frame *fp,
void *rdata_arg)
{
struct fc_rport_priv *rdata = rdata_arg;
struct fc_els_adisc *adisc;
u8 op;
mutex_lock(&rdata->rp_mutex);
FC_RPORT_DBG(rdata, "Received a ADISC response\n");
if (rdata->rp_state != RPORT_ST_ADISC) {
FC_RPORT_DBG(rdata, "Received a ADISC resp but in state %s\n",
fc_rport_state(rdata));
if (IS_ERR(fp))
goto err;
goto out;
}
if (IS_ERR(fp)) {
fc_rport_error(rdata, fp);
goto err;
}
op = fc_frame_payload_op(fp);
adisc = fc_frame_payload_get(fp, sizeof(*adisc));
if (op != ELS_LS_ACC || !adisc ||
ntoh24(adisc->adisc_port_id) != rdata->ids.port_id ||
get_unaligned_be64(&adisc->adisc_wwpn) != rdata->ids.port_name ||
get_unaligned_be64(&adisc->adisc_wwnn) != rdata->ids.node_name) {
FC_RPORT_DBG(rdata, "ADISC error or mismatch\n");
fc_rport_enter_flogi(rdata);
} else {
FC_RPORT_DBG(rdata, "ADISC OK\n");
fc_rport_enter_ready(rdata);
}
out:
fc_frame_free(fp);
err:
mutex_unlock(&rdata->rp_mutex);
kref_put(&rdata->kref, rdata->local_port->tt.rport_destroy);
}
static void fc_rport_enter_adisc(struct fc_rport_priv *rdata)
{
struct fc_lport *lport = rdata->local_port;
struct fc_frame *fp;
FC_RPORT_DBG(rdata, "sending ADISC from %s state\n",
fc_rport_state(rdata));
fc_rport_state_enter(rdata, RPORT_ST_ADISC);
fp = fc_frame_alloc(lport, sizeof(struct fc_els_adisc));
if (!fp) {
fc_rport_error_retry(rdata, fp);
return;
}
if (!lport->tt.elsct_send(lport, rdata->ids.port_id, fp, ELS_ADISC,
fc_rport_adisc_resp, rdata,
2 * lport->r_a_tov))
fc_rport_error_retry(rdata, NULL);
else
kref_get(&rdata->kref);
}
static void fc_rport_recv_adisc_req(struct fc_rport_priv *rdata,
struct fc_frame *in_fp)
{
struct fc_lport *lport = rdata->local_port;
struct fc_frame *fp;
struct fc_els_adisc *adisc;
struct fc_seq_els_data rjt_data;
FC_RPORT_DBG(rdata, "Received ADISC request\n");
adisc = fc_frame_payload_get(in_fp, sizeof(*adisc));
if (!adisc) {
rjt_data.reason = ELS_RJT_PROT;
rjt_data.explan = ELS_EXPL_INV_LEN;
lport->tt.seq_els_rsp_send(in_fp, ELS_LS_RJT, &rjt_data);
goto drop;
}
fp = fc_frame_alloc(lport, sizeof(*adisc));
if (!fp)
goto drop;
fc_adisc_fill(lport, fp);
adisc = fc_frame_payload_get(fp, sizeof(*adisc));
adisc->adisc_cmd = ELS_LS_ACC;
fc_fill_reply_hdr(fp, in_fp, FC_RCTL_ELS_REP, 0);
lport->tt.frame_send(lport, fp);
drop:
fc_frame_free(in_fp);
}
static void fc_rport_recv_rls_req(struct fc_rport_priv *rdata,
struct fc_frame *rx_fp)
{
struct fc_lport *lport = rdata->local_port;
struct fc_frame *fp;
struct fc_els_rls *rls;
struct fc_els_rls_resp *rsp;
struct fc_els_lesb *lesb;
struct fc_seq_els_data rjt_data;
struct fc_host_statistics *hst;
FC_RPORT_DBG(rdata, "Received RLS request while in state %s\n",
fc_rport_state(rdata));
rls = fc_frame_payload_get(rx_fp, sizeof(*rls));
if (!rls) {
rjt_data.reason = ELS_RJT_PROT;
rjt_data.explan = ELS_EXPL_INV_LEN;
goto out_rjt;
}
fp = fc_frame_alloc(lport, sizeof(*rsp));
if (!fp) {
rjt_data.reason = ELS_RJT_UNAB;
rjt_data.explan = ELS_EXPL_INSUF_RES;
goto out_rjt;
}
rsp = fc_frame_payload_get(fp, sizeof(*rsp));
memset(rsp, 0, sizeof(*rsp));
rsp->rls_cmd = ELS_LS_ACC;
lesb = &rsp->rls_lesb;
if (lport->tt.get_lesb) {
lport->tt.get_lesb(lport, lesb);
} else {
fc_get_host_stats(lport->host);
hst = &lport->host_stats;
lesb->lesb_link_fail = htonl(hst->link_failure_count);
lesb->lesb_sync_loss = htonl(hst->loss_of_sync_count);
lesb->lesb_sig_loss = htonl(hst->loss_of_signal_count);
lesb->lesb_prim_err = htonl(hst->prim_seq_protocol_err_count);
lesb->lesb_inv_word = htonl(hst->invalid_tx_word_count);
lesb->lesb_inv_crc = htonl(hst->invalid_crc_count);
}
fc_fill_reply_hdr(fp, rx_fp, FC_RCTL_ELS_REP, 0);
lport->tt.frame_send(lport, fp);
goto out;
out_rjt:
lport->tt.seq_els_rsp_send(rx_fp, ELS_LS_RJT, &rjt_data);
out:
fc_frame_free(rx_fp);
}
static void fc_rport_recv_els_req(struct fc_lport *lport, struct fc_frame *fp)
{
struct fc_rport_priv *rdata;
struct fc_seq_els_data els_data;
mutex_lock(&lport->disc.disc_mutex);
rdata = lport->tt.rport_lookup(lport, fc_frame_sid(fp));
if (!rdata) {
mutex_unlock(&lport->disc.disc_mutex);
goto reject;
}
mutex_lock(&rdata->rp_mutex);
mutex_unlock(&lport->disc.disc_mutex);
switch (rdata->rp_state) {
case RPORT_ST_PRLI:
case RPORT_ST_RTV:
case RPORT_ST_READY:
case RPORT_ST_ADISC:
break;
default:
mutex_unlock(&rdata->rp_mutex);
goto reject;
}
switch (fc_frame_payload_op(fp)) {
case ELS_PRLI:
fc_rport_recv_prli_req(rdata, fp);
break;
case ELS_PRLO:
fc_rport_recv_prlo_req(rdata, fp);
break;
case ELS_ADISC:
fc_rport_recv_adisc_req(rdata, fp);
break;
case ELS_RRQ:
lport->tt.seq_els_rsp_send(fp, ELS_RRQ, NULL);
fc_frame_free(fp);
break;
case ELS_REC:
lport->tt.seq_els_rsp_send(fp, ELS_REC, NULL);
fc_frame_free(fp);
break;
case ELS_RLS:
fc_rport_recv_rls_req(rdata, fp);
break;
default:
fc_frame_free(fp);
break;
}
mutex_unlock(&rdata->rp_mutex);
return;
reject:
els_data.reason = ELS_RJT_UNAB;
els_data.explan = ELS_EXPL_PLOGI_REQD;
lport->tt.seq_els_rsp_send(fp, ELS_LS_RJT, &els_data);
fc_frame_free(fp);
}
static void fc_rport_recv_req(struct fc_lport *lport, struct fc_frame *fp)
{
struct fc_seq_els_data els_data;
switch (fc_frame_payload_op(fp)) {
case ELS_FLOGI:
fc_rport_recv_flogi_req(lport, fp);
break;
case ELS_PLOGI:
fc_rport_recv_plogi_req(lport, fp);
break;
case ELS_LOGO:
fc_rport_recv_logo_req(lport, fp);
break;
case ELS_PRLI:
case ELS_PRLO:
case ELS_ADISC:
case ELS_RRQ:
case ELS_REC:
case ELS_RLS:
fc_rport_recv_els_req(lport, fp);
break;
default:
els_data.reason = ELS_RJT_UNSUP;
els_data.explan = ELS_EXPL_NONE;
lport->tt.seq_els_rsp_send(fp, ELS_LS_RJT, &els_data);
fc_frame_free(fp);
break;
}
}
static void fc_rport_recv_plogi_req(struct fc_lport *lport,
struct fc_frame *rx_fp)
{
struct fc_disc *disc;
struct fc_rport_priv *rdata;
struct fc_frame *fp = rx_fp;
struct fc_els_flogi *pl;
struct fc_seq_els_data rjt_data;
u32 sid;
sid = fc_frame_sid(fp);
FC_RPORT_ID_DBG(lport, sid, "Received PLOGI request\n");
pl = fc_frame_payload_get(fp, sizeof(*pl));
if (!pl) {
FC_RPORT_ID_DBG(lport, sid, "Received PLOGI too short\n");
rjt_data.reason = ELS_RJT_PROT;
rjt_data.explan = ELS_EXPL_INV_LEN;
goto reject;
}
disc = &lport->disc;
mutex_lock(&disc->disc_mutex);
rdata = lport->tt.rport_create(lport, sid);
if (!rdata) {
mutex_unlock(&disc->disc_mutex);
rjt_data.reason = ELS_RJT_UNAB;
rjt_data.explan = ELS_EXPL_INSUF_RES;
goto reject;
}
mutex_lock(&rdata->rp_mutex);
mutex_unlock(&disc->disc_mutex);
rdata->ids.port_name = get_unaligned_be64(&pl->fl_wwpn);
rdata->ids.node_name = get_unaligned_be64(&pl->fl_wwnn);
switch (rdata->rp_state) {
case RPORT_ST_INIT:
FC_RPORT_DBG(rdata, "Received PLOGI in INIT state\n");
break;
case RPORT_ST_PLOGI_WAIT:
FC_RPORT_DBG(rdata, "Received PLOGI in PLOGI_WAIT state\n");
break;
case RPORT_ST_PLOGI:
FC_RPORT_DBG(rdata, "Received PLOGI in PLOGI state\n");
if (rdata->ids.port_name < lport->wwpn) {
mutex_unlock(&rdata->rp_mutex);
rjt_data.reason = ELS_RJT_INPROG;
rjt_data.explan = ELS_EXPL_NONE;
goto reject;
}
break;
case RPORT_ST_PRLI:
case RPORT_ST_RTV:
case RPORT_ST_READY:
case RPORT_ST_ADISC:
FC_RPORT_DBG(rdata, "Received PLOGI in logged-in state %d "
"- ignored for now\n", rdata->rp_state);
break;
case RPORT_ST_FLOGI:
case RPORT_ST_DELETE:
FC_RPORT_DBG(rdata, "Received PLOGI in state %s - send busy\n",
fc_rport_state(rdata));
mutex_unlock(&rdata->rp_mutex);
rjt_data.reason = ELS_RJT_BUSY;
rjt_data.explan = ELS_EXPL_NONE;
goto reject;
}
rdata->maxframe_size = fc_plogi_get_maxframe(pl, lport->mfs);
fp = fc_frame_alloc(lport, sizeof(*pl));
if (!fp)
goto out;
fc_plogi_fill(lport, fp, ELS_LS_ACC);
fc_fill_reply_hdr(fp, rx_fp, FC_RCTL_ELS_REP, 0);
lport->tt.frame_send(lport, fp);
fc_rport_enter_prli(rdata);
out:
mutex_unlock(&rdata->rp_mutex);
fc_frame_free(rx_fp);
return;
reject:
lport->tt.seq_els_rsp_send(fp, ELS_LS_RJT, &rjt_data);
fc_frame_free(fp);
}
static void fc_rport_recv_prli_req(struct fc_rport_priv *rdata,
struct fc_frame *rx_fp)
{
struct fc_lport *lport = rdata->local_port;
struct fc_frame *fp;
struct {
struct fc_els_prli prli;
struct fc_els_spp spp;
} *pp;
struct fc_els_spp *rspp;
struct fc_els_spp *spp;
unsigned int len;
unsigned int plen;
enum fc_els_spp_resp resp;
enum fc_els_spp_resp passive;
struct fc_seq_els_data rjt_data;
struct fc4_prov *prov;
FC_RPORT_DBG(rdata, "Received PRLI request while in state %s\n",
fc_rport_state(rdata));
len = fr_len(rx_fp) - sizeof(struct fc_frame_header);
pp = fc_frame_payload_get(rx_fp, sizeof(*pp));
if (!pp)
goto reject_len;
plen = ntohs(pp->prli.prli_len);
if ((plen % 4) != 0 || plen > len || plen < 16)
goto reject_len;
if (plen < len)
len = plen;
plen = pp->prli.prli_spp_len;
if ((plen % 4) != 0 || plen < sizeof(*spp) ||
plen > len || len < sizeof(*pp) || plen < 12)
goto reject_len;
rspp = &pp->spp;
fp = fc_frame_alloc(lport, len);
if (!fp) {
rjt_data.reason = ELS_RJT_UNAB;
rjt_data.explan = ELS_EXPL_INSUF_RES;
goto reject;
}
pp = fc_frame_payload_get(fp, len);
WARN_ON(!pp);
memset(pp, 0, len);
pp->prli.prli_cmd = ELS_LS_ACC;
pp->prli.prli_spp_len = plen;
pp->prli.prli_len = htons(len);
len -= sizeof(struct fc_els_prli);
spp = &pp->spp;
mutex_lock(&fc_prov_mutex);
while (len >= plen) {
rdata->spp_type = rspp->spp_type;
spp->spp_type = rspp->spp_type;
spp->spp_type_ext = rspp->spp_type_ext;
resp = 0;
if (rspp->spp_type < FC_FC4_PROV_SIZE) {
prov = fc_active_prov[rspp->spp_type];
if (prov)
resp = prov->prli(rdata, plen, rspp, spp);
prov = fc_passive_prov[rspp->spp_type];
if (prov) {
passive = prov->prli(rdata, plen, rspp, spp);
if (!resp || passive == FC_SPP_RESP_ACK)
resp = passive;
}
}
if (!resp) {
if (spp->spp_flags & FC_SPP_EST_IMG_PAIR)
resp |= FC_SPP_RESP_CONF;
else
resp |= FC_SPP_RESP_INVL;
}
spp->spp_flags |= resp;
len -= plen;
rspp = (struct fc_els_spp *)((char *)rspp + plen);
spp = (struct fc_els_spp *)((char *)spp + plen);
}
mutex_unlock(&fc_prov_mutex);
fc_fill_reply_hdr(fp, rx_fp, FC_RCTL_ELS_REP, 0);
lport->tt.frame_send(lport, fp);
switch (rdata->rp_state) {
case RPORT_ST_PRLI:
fc_rport_enter_ready(rdata);
break;
default:
break;
}
goto drop;
reject_len:
rjt_data.reason = ELS_RJT_PROT;
rjt_data.explan = ELS_EXPL_INV_LEN;
reject:
lport->tt.seq_els_rsp_send(rx_fp, ELS_LS_RJT, &rjt_data);
drop:
fc_frame_free(rx_fp);
}
static void fc_rport_recv_prlo_req(struct fc_rport_priv *rdata,
struct fc_frame *rx_fp)
{
struct fc_lport *lport = rdata->local_port;
struct fc_frame *fp;
struct {
struct fc_els_prlo prlo;
struct fc_els_spp spp;
} *pp;
struct fc_els_spp *rspp;
struct fc_els_spp *spp;
unsigned int len;
unsigned int plen;
struct fc_seq_els_data rjt_data;
FC_RPORT_DBG(rdata, "Received PRLO request while in state %s\n",
fc_rport_state(rdata));
len = fr_len(rx_fp) - sizeof(struct fc_frame_header);
pp = fc_frame_payload_get(rx_fp, sizeof(*pp));
if (!pp)
goto reject_len;
plen = ntohs(pp->prlo.prlo_len);
if (plen != 20)
goto reject_len;
if (plen < len)
len = plen;
rspp = &pp->spp;
fp = fc_frame_alloc(lport, len);
if (!fp) {
rjt_data.reason = ELS_RJT_UNAB;
rjt_data.explan = ELS_EXPL_INSUF_RES;
goto reject;
}
pp = fc_frame_payload_get(fp, len);
WARN_ON(!pp);
memset(pp, 0, len);
pp->prlo.prlo_cmd = ELS_LS_ACC;
pp->prlo.prlo_obs = 0x10;
pp->prlo.prlo_len = htons(len);
spp = &pp->spp;
spp->spp_type = rspp->spp_type;
spp->spp_type_ext = rspp->spp_type_ext;
spp->spp_flags = FC_SPP_RESP_ACK;
fc_rport_enter_delete(rdata, RPORT_EV_LOGO);
fc_fill_reply_hdr(fp, rx_fp, FC_RCTL_ELS_REP, 0);
lport->tt.frame_send(lport, fp);
goto drop;
reject_len:
rjt_data.reason = ELS_RJT_PROT;
rjt_data.explan = ELS_EXPL_INV_LEN;
reject:
lport->tt.seq_els_rsp_send(rx_fp, ELS_LS_RJT, &rjt_data);
drop:
fc_frame_free(rx_fp);
}
static void fc_rport_recv_logo_req(struct fc_lport *lport, struct fc_frame *fp)
{
struct fc_rport_priv *rdata;
u32 sid;
lport->tt.seq_els_rsp_send(fp, ELS_LS_ACC, NULL);
sid = fc_frame_sid(fp);
mutex_lock(&lport->disc.disc_mutex);
rdata = lport->tt.rport_lookup(lport, sid);
if (rdata) {
mutex_lock(&rdata->rp_mutex);
FC_RPORT_DBG(rdata, "Received LOGO request while in state %s\n",
fc_rport_state(rdata));
fc_rport_enter_delete(rdata, RPORT_EV_LOGO);
mutex_unlock(&rdata->rp_mutex);
} else
FC_RPORT_ID_DBG(lport, sid,
"Received LOGO from non-logged-in port\n");
mutex_unlock(&lport->disc.disc_mutex);
fc_frame_free(fp);
}
static void fc_rport_flush_queue(void)
{
flush_workqueue(rport_event_queue);
}
int fc_rport_init(struct fc_lport *lport)
{
if (!lport->tt.rport_lookup)
lport->tt.rport_lookup = fc_rport_lookup;
if (!lport->tt.rport_create)
lport->tt.rport_create = fc_rport_create;
if (!lport->tt.rport_login)
lport->tt.rport_login = fc_rport_login;
if (!lport->tt.rport_logoff)
lport->tt.rport_logoff = fc_rport_logoff;
if (!lport->tt.rport_recv_req)
lport->tt.rport_recv_req = fc_rport_recv_req;
if (!lport->tt.rport_flush_queue)
lport->tt.rport_flush_queue = fc_rport_flush_queue;
if (!lport->tt.rport_destroy)
lport->tt.rport_destroy = fc_rport_destroy;
return 0;
}
static int fc_rport_fcp_prli(struct fc_rport_priv *rdata, u32 spp_len,
const struct fc_els_spp *rspp,
struct fc_els_spp *spp)
{
struct fc_lport *lport = rdata->local_port;
u32 fcp_parm;
fcp_parm = ntohl(rspp->spp_params);
rdata->ids.roles = FC_RPORT_ROLE_UNKNOWN;
if (fcp_parm & FCP_SPPF_INIT_FCN)
rdata->ids.roles |= FC_RPORT_ROLE_FCP_INITIATOR;
if (fcp_parm & FCP_SPPF_TARG_FCN)
rdata->ids.roles |= FC_RPORT_ROLE_FCP_TARGET;
if (fcp_parm & FCP_SPPF_RETRY)
rdata->flags |= FC_RP_FLAGS_RETRY;
rdata->supported_classes = FC_COS_CLASS3;
if (!(lport->service_params & FCP_SPPF_INIT_FCN))
return 0;
spp->spp_flags |= rspp->spp_flags & FC_SPP_EST_IMG_PAIR;
fcp_parm = ntohl(spp->spp_params);
spp->spp_params = htonl(fcp_parm | lport->service_params);
return FC_SPP_RESP_ACK;
}
static int fc_rport_t0_prli(struct fc_rport_priv *rdata, u32 spp_len,
const struct fc_els_spp *rspp,
struct fc_els_spp *spp)
{
if (rspp->spp_flags & FC_SPP_EST_IMG_PAIR)
return FC_SPP_RESP_INVL;
return FC_SPP_RESP_ACK;
}
int fc_setup_rport(void)
{
rport_event_queue = create_singlethread_workqueue("fc_rport_eq");
if (!rport_event_queue)
return -ENOMEM;
return 0;
}
void fc_destroy_rport(void)
{
destroy_workqueue(rport_event_queue);
}
void fc_rport_terminate_io(struct fc_rport *rport)
{
struct fc_rport_libfc_priv *rpriv = rport->dd_data;
struct fc_lport *lport = rpriv->local_port;
lport->tt.exch_mgr_reset(lport, 0, rport->port_id);
lport->tt.exch_mgr_reset(lport, rport->port_id, 0);
}
