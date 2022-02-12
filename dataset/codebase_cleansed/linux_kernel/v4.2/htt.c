int ath10k_htt_connect(struct ath10k_htt *htt)
{
struct ath10k_htc_svc_conn_req conn_req;
struct ath10k_htc_svc_conn_resp conn_resp;
int status;
memset(&conn_req, 0, sizeof(conn_req));
memset(&conn_resp, 0, sizeof(conn_resp));
conn_req.ep_ops.ep_tx_complete = ath10k_htt_htc_tx_complete;
conn_req.ep_ops.ep_rx_complete = ath10k_htt_t2h_msg_handler;
conn_req.service_id = ATH10K_HTC_SVC_ID_HTT_DATA_MSG;
status = ath10k_htc_connect_service(&htt->ar->htc, &conn_req,
&conn_resp);
if (status)
return status;
htt->eid = conn_resp.eid;
return 0;
}
int ath10k_htt_init(struct ath10k *ar)
{
struct ath10k_htt *htt = &ar->htt;
htt->ar = ar;
htt->prefetch_len =
36 +
4 +
8 +
2;
switch (ar->htt.op_version) {
case ATH10K_FW_HTT_OP_VERSION_10_1:
ar->htt.t2h_msg_types = htt_10x_t2h_msg_types;
ar->htt.t2h_msg_types_max = HTT_10X_T2H_NUM_MSGS;
break;
case ATH10K_FW_HTT_OP_VERSION_TLV:
ar->htt.t2h_msg_types = htt_tlv_t2h_msg_types;
ar->htt.t2h_msg_types_max = HTT_TLV_T2H_NUM_MSGS;
break;
case ATH10K_FW_HTT_OP_VERSION_MAIN:
ar->htt.t2h_msg_types = htt_main_t2h_msg_types;
ar->htt.t2h_msg_types_max = HTT_MAIN_T2H_NUM_MSGS;
break;
case ATH10K_FW_HTT_OP_VERSION_MAX:
case ATH10K_FW_HTT_OP_VERSION_UNSET:
WARN_ON(1);
return -EINVAL;
}
return 0;
}
static int ath10k_htt_verify_version(struct ath10k_htt *htt)
{
struct ath10k *ar = htt->ar;
ath10k_dbg(ar, ATH10K_DBG_BOOT, "htt target version %d.%d\n",
htt->target_version_major, htt->target_version_minor);
if (htt->target_version_major != 2 &&
htt->target_version_major != 3) {
ath10k_err(ar, "unsupported htt major version %d. supported versions are 2 and 3\n",
htt->target_version_major);
return -ENOTSUPP;
}
return 0;
}
int ath10k_htt_setup(struct ath10k_htt *htt)
{
struct ath10k *ar = htt->ar;
int status;
init_completion(&htt->target_version_received);
status = ath10k_htt_h2t_ver_req_msg(htt);
if (status)
return status;
status = wait_for_completion_timeout(&htt->target_version_received,
HTT_TARGET_VERSION_TIMEOUT_HZ);
if (status == 0) {
ath10k_warn(ar, "htt version request timed out\n");
return -ETIMEDOUT;
}
status = ath10k_htt_verify_version(htt);
if (status)
return status;
return ath10k_htt_send_rx_ring_cfg_ll(htt);
}
