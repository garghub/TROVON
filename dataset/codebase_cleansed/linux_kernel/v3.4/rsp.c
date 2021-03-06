static void nci_core_reset_rsp_packet(struct nci_dev *ndev, struct sk_buff *skb)
{
struct nci_core_reset_rsp *rsp = (void *) skb->data;
pr_debug("status 0x%x\n", rsp->status);
if (rsp->status == NCI_STATUS_OK) {
ndev->nci_ver = rsp->nci_ver;
pr_debug("nci_ver 0x%x, config_status 0x%x\n",
rsp->nci_ver, rsp->config_status);
}
nci_req_complete(ndev, rsp->status);
}
static void nci_core_init_rsp_packet(struct nci_dev *ndev, struct sk_buff *skb)
{
struct nci_core_init_rsp_1 *rsp_1 = (void *) skb->data;
struct nci_core_init_rsp_2 *rsp_2;
pr_debug("status 0x%x\n", rsp_1->status);
if (rsp_1->status != NCI_STATUS_OK)
goto exit;
ndev->nfcc_features = __le32_to_cpu(rsp_1->nfcc_features);
ndev->num_supported_rf_interfaces = rsp_1->num_supported_rf_interfaces;
if (ndev->num_supported_rf_interfaces >
NCI_MAX_SUPPORTED_RF_INTERFACES) {
ndev->num_supported_rf_interfaces =
NCI_MAX_SUPPORTED_RF_INTERFACES;
}
memcpy(ndev->supported_rf_interfaces,
rsp_1->supported_rf_interfaces,
ndev->num_supported_rf_interfaces);
rsp_2 = (void *) (skb->data + 6 + rsp_1->num_supported_rf_interfaces);
ndev->max_logical_connections = rsp_2->max_logical_connections;
ndev->max_routing_table_size =
__le16_to_cpu(rsp_2->max_routing_table_size);
ndev->max_ctrl_pkt_payload_len =
rsp_2->max_ctrl_pkt_payload_len;
ndev->max_size_for_large_params =
__le16_to_cpu(rsp_2->max_size_for_large_params);
ndev->manufact_id =
rsp_2->manufact_id;
ndev->manufact_specific_info =
__le32_to_cpu(rsp_2->manufact_specific_info);
pr_debug("nfcc_features 0x%x\n",
ndev->nfcc_features);
pr_debug("num_supported_rf_interfaces %d\n",
ndev->num_supported_rf_interfaces);
pr_debug("supported_rf_interfaces[0] 0x%x\n",
ndev->supported_rf_interfaces[0]);
pr_debug("supported_rf_interfaces[1] 0x%x\n",
ndev->supported_rf_interfaces[1]);
pr_debug("supported_rf_interfaces[2] 0x%x\n",
ndev->supported_rf_interfaces[2]);
pr_debug("supported_rf_interfaces[3] 0x%x\n",
ndev->supported_rf_interfaces[3]);
pr_debug("max_logical_connections %d\n",
ndev->max_logical_connections);
pr_debug("max_routing_table_size %d\n",
ndev->max_routing_table_size);
pr_debug("max_ctrl_pkt_payload_len %d\n",
ndev->max_ctrl_pkt_payload_len);
pr_debug("max_size_for_large_params %d\n",
ndev->max_size_for_large_params);
pr_debug("manufact_id 0x%x\n",
ndev->manufact_id);
pr_debug("manufact_specific_info 0x%x\n",
ndev->manufact_specific_info);
exit:
nci_req_complete(ndev, rsp_1->status);
}
static void nci_rf_disc_map_rsp_packet(struct nci_dev *ndev,
struct sk_buff *skb)
{
__u8 status = skb->data[0];
pr_debug("status 0x%x\n", status);
nci_req_complete(ndev, status);
}
static void nci_rf_disc_rsp_packet(struct nci_dev *ndev, struct sk_buff *skb)
{
__u8 status = skb->data[0];
pr_debug("status 0x%x\n", status);
if (status == NCI_STATUS_OK)
atomic_set(&ndev->state, NCI_DISCOVERY);
nci_req_complete(ndev, status);
}
static void nci_rf_disc_select_rsp_packet(struct nci_dev *ndev,
struct sk_buff *skb)
{
__u8 status = skb->data[0];
pr_debug("status 0x%x\n", status);
if (status != NCI_STATUS_OK)
nci_req_complete(ndev, status);
}
static void nci_rf_deactivate_rsp_packet(struct nci_dev *ndev,
struct sk_buff *skb)
{
__u8 status = skb->data[0];
pr_debug("status 0x%x\n", status);
if ((status != NCI_STATUS_OK) ||
(atomic_read(&ndev->state) != NCI_POLL_ACTIVE)) {
nci_clear_target_list(ndev);
atomic_set(&ndev->state, NCI_IDLE);
nci_req_complete(ndev, status);
}
}
void nci_rsp_packet(struct nci_dev *ndev, struct sk_buff *skb)
{
__u16 rsp_opcode = nci_opcode(skb->data);
del_timer(&ndev->cmd_timer);
pr_debug("NCI RX: MT=rsp, PBF=%d, GID=0x%x, OID=0x%x, plen=%d\n",
nci_pbf(skb->data),
nci_opcode_gid(rsp_opcode),
nci_opcode_oid(rsp_opcode),
nci_plen(skb->data));
skb_pull(skb, NCI_CTRL_HDR_SIZE);
switch (rsp_opcode) {
case NCI_OP_CORE_RESET_RSP:
nci_core_reset_rsp_packet(ndev, skb);
break;
case NCI_OP_CORE_INIT_RSP:
nci_core_init_rsp_packet(ndev, skb);
break;
case NCI_OP_RF_DISCOVER_MAP_RSP:
nci_rf_disc_map_rsp_packet(ndev, skb);
break;
case NCI_OP_RF_DISCOVER_RSP:
nci_rf_disc_rsp_packet(ndev, skb);
break;
case NCI_OP_RF_DISCOVER_SELECT_RSP:
nci_rf_disc_select_rsp_packet(ndev, skb);
break;
case NCI_OP_RF_DEACTIVATE_RSP:
nci_rf_deactivate_rsp_packet(ndev, skb);
break;
default:
pr_err("unknown rsp opcode 0x%x\n", rsp_opcode);
break;
}
kfree_skb(skb);
atomic_set(&ndev->cmd_cnt, 1);
if (!skb_queue_empty(&ndev->cmd_q))
queue_work(ndev->cmd_wq, &ndev->cmd_work);
}
