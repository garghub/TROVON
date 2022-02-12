static void iwl_fwrt_fseq_ver_mismatch(struct iwl_fw_runtime *fwrt,
struct iwl_rx_cmd_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_fseq_ver_mismatch_ntf *fseq = (void *)pkt->data;
IWL_ERR(fwrt, "FSEQ version mismatch (aux: %d, wifi: %d)\n",
__le32_to_cpu(fseq->aux_read_fseq_ver),
__le32_to_cpu(fseq->wifi_fseq_ver));
}
void iwl_fwrt_handle_notification(struct iwl_fw_runtime *fwrt,
struct iwl_rx_cmd_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
u32 cmd = WIDE_ID(pkt->hdr.group_id, pkt->hdr.cmd);
switch (cmd) {
case WIDE_ID(SYSTEM_GROUP, FSEQ_VER_MISMATCH_NTF):
iwl_fwrt_fseq_ver_mismatch(fwrt, rxb);
break;
default:
break;
}
}
