int decode_syn(packet_info *pinfo _U_, proto_tree *tree _U_, PKT_INFO* pkt_info)
{
if (pkt_info->tcp_flags_ack)
pkt_info->rrpd.c2s = FALSE;
else
{
pkt_info->rrpd.c2s = TRUE;
pkt_info->rrpd.state = RRPD_STATE_4;
add_detected_tcp_svc(pkt_info->dstport);
}
pkt_info->rrpd.session_id = 1;
pkt_info->rrpd.msg_id = 1;
pkt_info->rrpd.suffix = 1;
pkt_info->rrpd.decode_based = TRUE;
pkt_info->rrpd.calculation = RTE_CALC_SYN;
pkt_info->pkt_of_interest = TRUE;
return 1;
}
int decode_dcerpc(packet_info *pinfo _U_, proto_tree *tree, PKT_INFO* pkt_info)
{
guint32 field_uint[MAX_RETURNED_ELEMENTS];
size_t field_value_count;
guint32 dcerpc_cn_ctx_id = 0;
if (!extract_uint(tree, hf_of_interest[HF_INTEREST_DCERPC_VER].hf, field_uint, &field_value_count))
{
if (field_value_count)
pkt_info->dcerpc_ver = field_uint[0];
}
if (!extract_uint(tree, hf_of_interest[HF_INTEREST_DCERPC_PKT_TYPE].hf, field_uint, &field_value_count))
{
if (field_value_count)
pkt_info->dcerpc_pkt_type = field_uint[0];
}
if (field_value_count)
{
if (!extract_uint(tree, hf_of_interest[HF_INTEREST_DCERPC_CN_CTX_ID].hf, field_uint, &field_value_count))
{
if (field_value_count)
dcerpc_cn_ctx_id = field_uint[0];
}
if (is_dcerpc_context_zero(pkt_info->dcerpc_pkt_type))
{
pkt_info->rrpd.session_id = 1;
}
else
{
if (dcerpc_cn_ctx_id)
pkt_info->rrpd.session_id = dcerpc_cn_ctx_id;
else
pkt_info->rrpd.session_id = 1;
}
if (!extract_uint(tree, hf_of_interest[HF_INTEREST_DCERPC_CN_CALL_ID].hf, field_uint, &field_value_count))
{
if (field_value_count)
pkt_info->rrpd.msg_id = field_uint[0];
}
}
else
{
pkt_info->rrpd.session_id = 0;
pkt_info->rrpd.msg_id = 0;
}
if (is_dcerpc_req_pkt_type(pkt_info->dcerpc_pkt_type))
{
pkt_info->rrpd.c2s = TRUE;
wmem_map_insert(preferences.tcp_svc_ports, GUINT_TO_POINTER(pkt_info->dstport), GUINT_TO_POINTER(RTE_CALC_DCERPC));
}
else
{
pkt_info->rrpd.c2s = FALSE;
wmem_map_insert(preferences.tcp_svc_ports, GUINT_TO_POINTER(pkt_info->srcport), GUINT_TO_POINTER(RTE_CALC_DCERPC));
}
pkt_info->rrpd.suffix = 1;
pkt_info->rrpd.decode_based = TRUE;
pkt_info->rrpd.calculation = RTE_CALC_DCERPC;
pkt_info->pkt_of_interest = TRUE;
return 1;
}
int decode_smb(packet_info *pinfo _U_, proto_tree *tree, PKT_INFO* pkt_info, PKT_INFO* subpackets)
{
guint32 field_uint[MAX_RETURNED_ELEMENTS];
size_t field_value_count;
guint64 ses_id[MAX_RETURNED_ELEMENTS];
size_t ses_id_count;
guint64 msg_id[MAX_RETURNED_ELEMENTS];
size_t msg_id_count;
if (pkt_info->dstport == 445)
pkt_info->rrpd.c2s = TRUE;
else
pkt_info->rrpd.c2s = FALSE;
if (!extract_uint(tree, hf_of_interest[HF_INTEREST_SMB_MID].hf, field_uint, &field_value_count))
{
if (field_value_count)
{
pkt_info->rrpd.calculation = RTE_CALC_SMB1;
pkt_info->pkt_of_interest = FALSE;
return 0;
}
}
pkt_info->rrpd.session_id = 0;
pkt_info->rrpd.msg_id = 0;
pkt_info->rrpd.suffix = 1;
pkt_info->rrpd.decode_based = TRUE;
pkt_info->rrpd.calculation = RTE_CALC_SMB2;
pkt_info->pkt_of_interest = TRUE;
extract_ui64(tree, hf_of_interest[HF_INTEREST_SMB2_MSG_ID].hf, msg_id, &msg_id_count);
if (msg_id_count)
{
extract_ui64(tree, hf_of_interest[HF_INTEREST_SMB2_SES_ID].hf, ses_id, &ses_id_count);
for (size_t i = 0; (i < msg_id_count) && (i < MAX_SUBPKTS_PER_PACKET); i++)
{
subpackets[i].rrpd.c2s = pkt_info->rrpd.c2s;
subpackets[i].rrpd.ip_proto = pkt_info->rrpd.ip_proto;
subpackets[i].rrpd.stream_no = pkt_info->rrpd.stream_no;
subpackets[i].rrpd.session_id = ses_id[i];
subpackets[i].rrpd.msg_id = msg_id[i];
subpackets[i].rrpd.suffix = 1;
subpackets[i].rrpd.decode_based = TRUE;
subpackets[i].rrpd.calculation = RTE_CALC_SMB2;
subpackets[i].pkt_of_interest = TRUE;
}
return (int)msg_id_count;
}
return 1;
}
int decode_gtcp(packet_info *pinfo, proto_tree *tree, PKT_INFO* pkt_info)
{
guint32 field_uint[MAX_RETURNED_ELEMENTS];
gboolean field_bool[MAX_RETURNED_ELEMENTS];
size_t field_value_count;
if (!extract_uint(tree, hf_of_interest[HF_INTEREST_TCP_STREAM].hf, field_uint, &field_value_count)) {
if (field_value_count)
pkt_info->rrpd.stream_no = field_uint[0];
}
pkt_info->srcport = pinfo->srcport;
pkt_info->dstport = pinfo->destport;
if (!extract_uint(tree, hf_of_interest[HF_INTEREST_TCP_LEN].hf, field_uint, &field_value_count)) {
if (field_value_count)
pkt_info->len = field_uint[0];
}
if (!extract_bool(tree, hf_of_interest[HF_INTEREST_TCP_FLAGS_SYN].hf, field_bool, &field_value_count)) {
if (field_value_count)
pkt_info->tcp_flags_syn = field_bool[0];
}
if (!extract_bool(tree, hf_of_interest[HF_INTEREST_TCP_FLAGS_ACK].hf, field_bool, &field_value_count)) {
if (field_value_count)
pkt_info->tcp_flags_ack = field_bool[0];
}
if (!extract_bool(tree, hf_of_interest[HF_INTEREST_TCP_FLAGS_RESET].hf, field_bool, &field_value_count)) {
if (field_value_count)
pkt_info->tcp_flags_reset = field_bool[0];
}
if (!extract_bool(tree, hf_of_interest[HF_INTEREST_TCP_RETRAN].hf, field_bool, &field_value_count)) {
if (field_value_count)
pkt_info->tcp_retran = field_bool[0];
}
if (!extract_bool(tree, hf_of_interest[HF_INTEREST_TCP_KEEP_ALIVE].hf, field_bool, &field_value_count)) {
if (field_value_count)
pkt_info->tcp_keep_alive = field_bool[0];
}
if (((wmem_map_lookup(preferences.tcp_svc_ports, GUINT_TO_POINTER(pkt_info->dstport)) != NULL) ||
(wmem_map_lookup(preferences.tcp_svc_ports, GUINT_TO_POINTER(pkt_info->srcport)) != NULL)) &&
(pkt_info->len > 0))
{
if (wmem_map_lookup(preferences.tcp_svc_ports, GUINT_TO_POINTER(pkt_info->dstport)) != NULL)
pkt_info->rrpd.c2s = TRUE;
pkt_info->rrpd.session_id = 1;
pkt_info->rrpd.msg_id = 1;
pkt_info->rrpd.calculation = RTE_CALC_GTCP;
pkt_info->rrpd.decode_based = FALSE;
pkt_info->pkt_of_interest = TRUE;
return 1;
}
return 0;
}
int decode_dns(packet_info *pinfo _U_, proto_tree *tree, PKT_INFO* pkt_info)
{
guint32 field_uint[MAX_RETURNED_ELEMENTS];
size_t field_value_count;
if (!extract_uint(tree, hf_of_interest[HF_INTEREST_DNS_ID].hf, field_uint, &field_value_count)) {
if (field_value_count)
pkt_info->rrpd.msg_id = field_uint[0];
}
pkt_info->rrpd.session_id = 1;
pkt_info->rrpd.suffix = 1;
pkt_info->rrpd.decode_based = TRUE;
pkt_info->rrpd.calculation = RTE_CALC_DNS;
pkt_info->pkt_of_interest = TRUE;
return 1;
}
int decode_gudp(packet_info *pinfo, proto_tree *tree, PKT_INFO* pkt_info)
{
guint32 field_uint[MAX_RETURNED_ELEMENTS];
size_t field_value_count;
pkt_info->srcport = pinfo->srcport;
pkt_info->dstport = pinfo->destport;
if (!extract_uint(tree, hf_of_interest[HF_INTEREST_UDP_STREAM].hf, field_uint, &field_value_count)) {
if (field_value_count)
pkt_info->rrpd.stream_no = field_uint[0];
}
if (!extract_uint(tree, hf_of_interest[HF_INTEREST_UDP_LENGTH].hf, field_uint, &field_value_count)) {
if (field_value_count)
pkt_info->len = field_uint[0];
}
if ((wmem_map_lookup(preferences.udp_svc_ports, GUINT_TO_POINTER(pkt_info->dstport)) != NULL) ||
(wmem_map_lookup(preferences.udp_svc_ports, GUINT_TO_POINTER(pkt_info->srcport)) != NULL))
{
if (wmem_map_lookup(preferences.udp_svc_ports, GUINT_TO_POINTER(pkt_info->dstport)) != NULL)
pkt_info->rrpd.c2s = TRUE;
pkt_info->rrpd.session_id = 1;
pkt_info->rrpd.msg_id = 1;
pkt_info->rrpd.suffix = 1;
pkt_info->rrpd.decode_based = FALSE;
pkt_info->rrpd.calculation = RTE_CALC_GUDP;
pkt_info->pkt_of_interest = TRUE;
}
return 1;
}
