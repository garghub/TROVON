exp_pdu_data_t *
load_export_pdu_tags(packet_info *pinfo, const char* proto_name, int wtap_encap _U_,
guint8 *wanted_exp_tags, guint16 wanted_exp_tags_len)
{
exp_pdu_data_t *exp_pdu_data;
int tag_buf_size = 0;
int str_len = 0;
int tag_str_len = 0;
int i = 0;
gboolean port_type_defined = FALSE;
exp_pdu_data = (exp_pdu_data_t *)g_malloc(sizeof(exp_pdu_data_t));
if(proto_name){
str_len = (int)strlen(proto_name);
tag_str_len = (str_len + 3) & 0xfffffffc;
tag_buf_size = tag_str_len + 4;
}
if (wanted_exp_tags_len >= 1) {
if((wanted_exp_tags[0] & EXP_PDU_TAG_IP_SRC_BIT) == EXP_PDU_TAG_IP_SRC_BIT){
if(pinfo->net_src.type == AT_IPv4){
tag_buf_size += 4 + EXP_PDU_TAG_IPV4_SRC_LEN;
}else if(pinfo->net_src.type == AT_IPv6){
tag_buf_size += 4 + EXP_PDU_TAG_IPV6_SRC_LEN;
}
}
if((wanted_exp_tags[0] & EXP_PDU_TAG_IP_DST_BIT) == EXP_PDU_TAG_IP_DST_BIT){
if(pinfo->net_dst.type == AT_IPv4){
tag_buf_size += 4 + EXP_PDU_TAG_IPV4_DST_LEN;
}else if(pinfo->net_dst.type == AT_IPv6){
tag_buf_size += 4 + EXP_PDU_TAG_IPV6_DST_LEN;
}
}
if((wanted_exp_tags[0] & EXP_PDU_TAG_SRC_PORT_BIT) == EXP_PDU_TAG_SRC_PORT_BIT){
if (!port_type_defined) {
tag_buf_size= tag_buf_size + EXP_PDU_TAG_PORT_TYPE_LEN + 4;
port_type_defined = TRUE;
}
tag_buf_size= tag_buf_size + EXP_PDU_TAG_SRC_PORT_LEN + 4;
}
if((wanted_exp_tags[0] & EXP_PDU_TAG_DST_PORT_BIT) == EXP_PDU_TAG_DST_PORT_BIT){
if (!port_type_defined) {
tag_buf_size= tag_buf_size + EXP_PDU_TAG_PORT_TYPE_LEN + 4;
}
tag_buf_size= tag_buf_size + EXP_PDU_TAG_DST_PORT_LEN + 4;
}
if((wanted_exp_tags[0] & EXP_PDU_TAG_SS7_OPC_BIT) == EXP_PDU_TAG_SS7_OPC_BIT){
if(pinfo->src.type == AT_SS7PC){
tag_buf_size += 4 + EXP_PDU_TAG_SS7_OPC_LEN;
}
}
if((wanted_exp_tags[0] & EXP_PDU_TAG_SS7_DPC_BIT) == EXP_PDU_TAG_SS7_DPC_BIT){
if(pinfo->dst.type == AT_SS7PC){
tag_buf_size += 4 + EXP_PDU_TAG_SS7_DPC_LEN;
}
}
if((wanted_exp_tags[0] & EXP_PDU_TAG_ORIG_FNO_BIT) == EXP_PDU_TAG_ORIG_FNO_BIT){
tag_buf_size= tag_buf_size + EXP_PDU_TAG_ORIG_FNO_LEN + 4;
}
}
if (wanted_exp_tags_len >= 2) {
if((wanted_exp_tags[1] & EXP_PDU_TAG_DVBCI_EVT_BIT) == EXP_PDU_TAG_DVBCI_EVT_BIT){
tag_buf_size= tag_buf_size + EXP_PDU_TAG_DVBCI_EVT_LEN + 4;
}
}
tag_buf_size+=4;
exp_pdu_data->tlv_buffer = (guint8 *)g_malloc0(tag_buf_size);
exp_pdu_data->tlv_buffer_len = tag_buf_size;
port_type_defined = FALSE;
if(proto_name){
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_PROTO_NAME;
i++;
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = tag_str_len;
i++;
memcpy(exp_pdu_data->tlv_buffer+i, proto_name, str_len);
i = i + tag_str_len;
}
if (wanted_exp_tags_len >= 1) {
if((wanted_exp_tags[0] & EXP_PDU_TAG_IP_SRC_BIT) == EXP_PDU_TAG_IP_SRC_BIT){
if(pinfo->net_src.type == AT_IPv4){
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_IPV4_SRC;
i++;
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_IPV4_SRC_LEN;
i++;
memcpy(exp_pdu_data->tlv_buffer+i, pinfo->net_src.data, EXP_PDU_TAG_IPV4_SRC_LEN);
i += EXP_PDU_TAG_IPV4_SRC_LEN;
}else if(pinfo->net_src.type == AT_IPv6){
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_IPV6_SRC;
i++;
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_IPV6_SRC_LEN;
i++;
memcpy(exp_pdu_data->tlv_buffer+i, pinfo->net_src.data, EXP_PDU_TAG_IPV6_SRC_LEN);
i += EXP_PDU_TAG_IPV6_SRC_LEN;
}
}
if((wanted_exp_tags[0] & EXP_PDU_TAG_IP_DST_BIT) == EXP_PDU_TAG_IP_DST_BIT){
if(pinfo->net_dst.type == AT_IPv4){
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_IPV4_DST;
i++;
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_IPV4_DST_LEN;
i++;
memcpy(exp_pdu_data->tlv_buffer+i, pinfo->net_dst.data, EXP_PDU_TAG_IPV4_DST_LEN);
i += EXP_PDU_TAG_IPV4_DST_LEN;
}else if(pinfo->net_dst.type == AT_IPv6){
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_IPV6_DST;
i++;
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_IPV6_DST_LEN;
i++;
memcpy(exp_pdu_data->tlv_buffer+i, pinfo->net_dst.data, EXP_PDU_TAG_IPV6_DST_LEN);
i += EXP_PDU_TAG_IPV6_DST_LEN;
}
}
if((wanted_exp_tags[0] & EXP_PDU_TAG_SRC_PORT_BIT) == EXP_PDU_TAG_SRC_PORT_BIT){
if (!port_type_defined) {
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_PORT_TYPE;
i++;
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_PORT_TYPE_LEN;
i++;
exp_pdu_data->tlv_buffer[i] = (pinfo->ptype & 0xff000000) >> 24;
exp_pdu_data->tlv_buffer[i+1] = (pinfo->ptype & 0x00ff0000) >> 16;
exp_pdu_data->tlv_buffer[i+2] = (pinfo->ptype & 0x0000ff00) >> 8;
exp_pdu_data->tlv_buffer[i+3] = (pinfo->ptype & 0x000000ff);
i = i +EXP_PDU_TAG_PORT_TYPE_LEN;
port_type_defined = TRUE;
}
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_SRC_PORT;
i++;
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_SRC_PORT_LEN;
i++;
exp_pdu_data->tlv_buffer[i] = (pinfo->srcport & 0xff000000) >> 24;
exp_pdu_data->tlv_buffer[i+1] = (pinfo->srcport & 0x00ff0000) >> 16;
exp_pdu_data->tlv_buffer[i+2] = (pinfo->srcport & 0x0000ff00) >> 8;
exp_pdu_data->tlv_buffer[i+3] = (pinfo->srcport & 0x000000ff);
i = i +EXP_PDU_TAG_SRC_PORT_LEN;
}
if((wanted_exp_tags[0] & EXP_PDU_TAG_DST_PORT_BIT) == EXP_PDU_TAG_DST_PORT_BIT){
if (!port_type_defined) {
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_PORT_TYPE;
i++;
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_PORT_TYPE_LEN;
i++;
exp_pdu_data->tlv_buffer[i] = (pinfo->ptype & 0xff000000) >> 24;
exp_pdu_data->tlv_buffer[i+1] = (pinfo->ptype & 0x00ff0000) >> 16;
exp_pdu_data->tlv_buffer[i+2] = (pinfo->ptype & 0x0000ff00) >> 8;
exp_pdu_data->tlv_buffer[i+3] = (pinfo->ptype & 0x000000ff);
i = i +EXP_PDU_TAG_PORT_TYPE_LEN;
}
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_DST_PORT;
i++;
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_DST_PORT_LEN;
i++;
exp_pdu_data->tlv_buffer[i] = (pinfo->destport & 0xff000000) >> 24;
exp_pdu_data->tlv_buffer[i+1] = (pinfo->destport & 0x00ff0000) >> 16;
exp_pdu_data->tlv_buffer[i+2] = (pinfo->destport & 0x0000ff00) >> 8;
exp_pdu_data->tlv_buffer[i+3] = (pinfo->destport & 0x000000ff);
i = i +EXP_PDU_TAG_DST_PORT_LEN;
}
if((wanted_exp_tags[0] & EXP_PDU_TAG_SS7_OPC_BIT) == EXP_PDU_TAG_SS7_OPC_BIT){
if(pinfo->src.type == AT_SS7PC){
const mtp3_addr_pc_t *mtp3_addr = (const mtp3_addr_pc_t *)(pinfo->src.data);
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_SS7_OPC;
i++;
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_SS7_OPC_LEN;
i++;
exp_pdu_data->tlv_buffer[i] = (mtp3_addr->pc & 0xff000000) >> 24;
exp_pdu_data->tlv_buffer[i+1] = (mtp3_addr->pc & 0x00ff0000) >> 16;
exp_pdu_data->tlv_buffer[i+2] = (mtp3_addr->pc & 0x0000ff00) >> 8;
exp_pdu_data->tlv_buffer[i+3] = (mtp3_addr->pc & 0x000000ff);
exp_pdu_data->tlv_buffer[i+4] = (mtp3_addr->type & 0xff00) >> 8;
exp_pdu_data->tlv_buffer[i+5] = (mtp3_addr->type & 0x00ff);
exp_pdu_data->tlv_buffer[i+6] = mtp3_addr->ni;
i += EXP_PDU_TAG_SS7_OPC_LEN;
}
}
if((wanted_exp_tags[0] & EXP_PDU_TAG_SS7_DPC_BIT) == EXP_PDU_TAG_SS7_DPC_BIT){
if(pinfo->dst.type == AT_SS7PC){
const mtp3_addr_pc_t *mtp3_addr = (const mtp3_addr_pc_t *)(pinfo->dst.data);
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_SS7_DPC;
i++;
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_SS7_DPC_LEN;
i++;
exp_pdu_data->tlv_buffer[i] = (mtp3_addr->pc & 0xff000000) >> 24;
exp_pdu_data->tlv_buffer[i+1] = (mtp3_addr->pc & 0x00ff0000) >> 16;
exp_pdu_data->tlv_buffer[i+2] = (mtp3_addr->pc & 0x0000ff00) >> 8;
exp_pdu_data->tlv_buffer[i+3] = (mtp3_addr->pc & 0x000000ff);
exp_pdu_data->tlv_buffer[i+4] = (mtp3_addr->type & 0xff00) >> 8;
exp_pdu_data->tlv_buffer[i+5] = (mtp3_addr->type & 0x00ff);
exp_pdu_data->tlv_buffer[i+6] = mtp3_addr->ni;
i += EXP_PDU_TAG_SS7_DPC_LEN;
}
}
if((wanted_exp_tags[0] & EXP_PDU_TAG_ORIG_FNO_BIT) == EXP_PDU_TAG_ORIG_FNO_BIT){
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_ORIG_FNO;
i++;
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_ORIG_FNO_LEN;
i++;
exp_pdu_data->tlv_buffer[i] = (pinfo->fd->num & 0xff000000) >> 24;
exp_pdu_data->tlv_buffer[i+1] = (pinfo->fd->num & 0x00ff0000) >> 16;
exp_pdu_data->tlv_buffer[i+2] = (pinfo->fd->num & 0x0000ff00) >> 8;
exp_pdu_data->tlv_buffer[i+3] = (pinfo->fd->num & 0x000000ff);
}
}
if (wanted_exp_tags_len >= 2) {
if((wanted_exp_tags[1] & EXP_PDU_TAG_DVBCI_EVT_BIT) == EXP_PDU_TAG_DVBCI_EVT_BIT){
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_DVBCI_EVT;
i++;
exp_pdu_data->tlv_buffer[i] = 0;
i++;
exp_pdu_data->tlv_buffer[i] = EXP_PDU_TAG_DVBCI_EVT_LEN;
i++;
exp_pdu_data->tlv_buffer[i] = dvbci_get_evt_from_addrs(pinfo);
}
}
return exp_pdu_data;
}
gint
register_export_pdu_tap(const char *name)
{
gchar *tap_name = g_strdup(name);
export_pdu_tap_name_list = g_slist_prepend(export_pdu_tap_name_list, tap_name);
return register_tap(tap_name);
}
static
gint sort_pdu_tap_name_list(gconstpointer a, gconstpointer b)
{
return g_strcmp0((const char *)a, (const char*)b);
}
GSList *
get_export_pdu_tap_list(void)
{
export_pdu_tap_name_list = g_slist_sort(export_pdu_tap_name_list, sort_pdu_tap_name_list);
return export_pdu_tap_name_list;
}
