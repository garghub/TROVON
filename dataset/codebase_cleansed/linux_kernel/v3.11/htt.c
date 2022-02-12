static int ath10k_htt_htc_attach(struct ath10k_htt *htt)
{
struct ath10k_htc_svc_conn_req conn_req;
struct ath10k_htc_svc_conn_resp conn_resp;
int status;
memset(&conn_req, 0, sizeof(conn_req));
memset(&conn_resp, 0, sizeof(conn_resp));
conn_req.ep_ops.ep_tx_complete = ath10k_htt_htc_tx_complete;
conn_req.ep_ops.ep_rx_complete = ath10k_htt_t2h_msg_handler;
conn_req.service_id = ATH10K_HTC_SVC_ID_HTT_DATA_MSG;
status = ath10k_htc_connect_service(htt->ar->htc, &conn_req,
&conn_resp);
if (status)
return status;
htt->eid = conn_resp.eid;
return 0;
}
struct ath10k_htt *ath10k_htt_attach(struct ath10k *ar)
{
struct ath10k_htt *htt;
int ret;
htt = kzalloc(sizeof(*htt), GFP_KERNEL);
if (!htt)
return NULL;
htt->ar = ar;
htt->max_throughput_mbps = 800;
if (ath10k_htt_htc_attach(htt))
goto err_htc_attach;
ret = ath10k_htt_tx_attach(htt);
if (ret) {
ath10k_err("could not attach htt tx (%d)\n", ret);
goto err_htc_attach;
}
if (ath10k_htt_rx_attach(htt))
goto err_rx_attach;
htt->prefetch_len =
36 +
4 +
8 +
2;
return htt;
err_rx_attach:
ath10k_htt_tx_detach(htt);
err_htc_attach:
kfree(htt);
return NULL;
}
static int ath10k_htt_verify_version(struct ath10k_htt *htt)
{
ath10k_dbg(ATH10K_DBG_HTT,
"htt target version %d.%d; host version %d.%d\n",
htt->target_version_major,
htt->target_version_minor,
HTT_CURRENT_VERSION_MAJOR,
HTT_CURRENT_VERSION_MINOR);
if (htt->target_version_major != HTT_CURRENT_VERSION_MAJOR) {
ath10k_err("htt major versions are incompatible!\n");
return -ENOTSUPP;
}
if (htt->target_version_minor != HTT_CURRENT_VERSION_MINOR)
ath10k_warn("htt minor version differ but still compatible\n");
return 0;
}
int ath10k_htt_attach_target(struct ath10k_htt *htt)
{
int status;
init_completion(&htt->target_version_received);
status = ath10k_htt_h2t_ver_req_msg(htt);
if (status)
return status;
status = wait_for_completion_timeout(&htt->target_version_received,
HTT_TARGET_VERSION_TIMEOUT_HZ);
if (status <= 0) {
ath10k_warn("htt version request timed out\n");
return -ETIMEDOUT;
}
status = ath10k_htt_verify_version(htt);
if (status)
return status;
return ath10k_htt_send_rx_ring_cfg_ll(htt);
}
void ath10k_htt_detach(struct ath10k_htt *htt)
{
ath10k_htt_rx_detach(htt);
ath10k_htt_tx_detach(htt);
kfree(htt);
}
