void
mtp3_pc_to_str_buf(const guint32 pc, gchar *buf, int buf_len)
{
switch (mtp3_standard)
{
case ITU_STANDARD:
switch (itu_pc_structure) {
case ITU_PC_STRUCTURE_NONE:
g_snprintf(buf, buf_len, "%u", pc);
break;
case ITU_PC_STRUCTURE_3_8_3:
g_snprintf(buf, buf_len, "%u-%u-%u", (pc & 0x3800)>>11, (pc & 0x7f8) >> 3, (pc & 0x07) >> 0);
break;
case ITU_PC_STRUCTURE_4_3_4_3:
g_snprintf(buf, buf_len, "%u-%u-%u-%u", (pc & 0x3c00) >>10, (pc & 0x0380) >> 7, (pc & 0x0078) >> 3, (pc & 0x0007) >> 0);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
break;
case ANSI_STANDARD:
case CHINESE_ITU_STANDARD:
g_snprintf(buf, buf_len, "%u-%u-%u", (pc & ANSI_NETWORK_MASK) >> 16, (pc & ANSI_CLUSTER_MASK) >> 8, (pc & ANSI_MEMBER_MASK));
break;
case JAPAN_STANDARD:
switch (japan_pc_structure) {
case JAPAN_PC_STRUCTURE_NONE:
g_snprintf(buf, buf_len, "%u", pc);
break;
case JAPAN_PC_STRUCTURE_7_4_5:
g_snprintf(buf, buf_len, "%u-%u-%u", (pc & 0xfe00)>>9, (pc & 0x1e0)>>5, (pc & 0x1f));
break;
case JAPAN_PC_STRUCTURE_3_4_4_5:
g_snprintf(buf, buf_len, "%u-%u-%u-%u", (pc & 0xe000)>>13, (pc & 0x1e00)>>9, (pc & 0x1e0)>>5, (pc & 0x1f));
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
}
gchar *
mtp3_pc_to_str(const guint32 pc)
{
gchar *str;
str=(gchar *)wmem_alloc(wmem_packet_scope(), MAX_STRUCTURED_PC_LENGTH);
mtp3_pc_to_str_buf(pc, str, MAX_STRUCTURED_PC_LENGTH);
return str;
}
gboolean
mtp3_pc_structured(void)
{
if ((mtp3_standard == ITU_STANDARD) && (itu_pc_structure == ITU_PC_STRUCTURE_NONE))
return FALSE;
else if ((mtp3_standard == JAPAN_STANDARD) && (japan_pc_structure == JAPAN_PC_STRUCTURE_NONE))
return FALSE;
else
return TRUE;
}
void
mtp3_addr_to_str_buf(const mtp3_addr_pc_t *addr_pc_p,
gchar *buf, int buf_len)
{
switch (mtp3_addr_fmt)
{
case MTP3_ADDR_FMT_DEC:
switch (addr_pc_p->type)
{
case ITU_STANDARD:
g_snprintf(buf, buf_len, "%u", addr_pc_p->pc & ITU_PC_MASK);
break;
case JAPAN_STANDARD:
g_snprintf(buf, buf_len, "%u", addr_pc_p->pc & JAPAN_PC_MASK);
break;
default:
g_snprintf(buf, buf_len, "%u", addr_pc_p->pc & ANSI_PC_MASK);
break;
}
break;
case MTP3_ADDR_FMT_HEX:
switch (addr_pc_p->type)
{
case ITU_STANDARD:
g_snprintf(buf, buf_len, "%x", addr_pc_p->pc & ITU_PC_MASK);
break;
case JAPAN_STANDARD:
g_snprintf(buf, buf_len, "%x", addr_pc_p->pc & JAPAN_PC_MASK);
break;
default:
g_snprintf(buf, buf_len, "%x", addr_pc_p->pc & ANSI_PC_MASK);
break;
}
break;
case MTP3_ADDR_FMT_NI_DEC:
switch (addr_pc_p->type)
{
case ITU_STANDARD:
g_snprintf(buf, buf_len, "%u:%u", addr_pc_p->ni, addr_pc_p->pc & ITU_PC_MASK);
break;
case JAPAN_STANDARD:
g_snprintf(buf, buf_len, "%u:%u", addr_pc_p->ni, addr_pc_p->pc & JAPAN_PC_MASK);
break;
default:
g_snprintf(buf, buf_len, "%u:%u", addr_pc_p->ni, addr_pc_p->pc & ANSI_PC_MASK);
break;
}
break;
case MTP3_ADDR_FMT_NI_HEX:
switch (addr_pc_p->type)
{
case ITU_STANDARD:
g_snprintf(buf, buf_len, "%u:%x", addr_pc_p->ni, addr_pc_p->pc & ITU_PC_MASK);
break;
case JAPAN_STANDARD:
g_snprintf(buf, buf_len, "%u:%x", addr_pc_p->ni, addr_pc_p->pc & JAPAN_PC_MASK);
break;
default:
g_snprintf(buf, buf_len, "%u:%x", addr_pc_p->ni, addr_pc_p->pc & ANSI_PC_MASK);
break;
}
break;
default:
case MTP3_ADDR_FMT_DASHED:
mtp3_pc_to_str_buf(addr_pc_p->pc, buf, buf_len);
break;
}
}
guint32
mtp3_pc_hash(const mtp3_addr_pc_t *addr_pc_p) {
guint32 pc;
switch (addr_pc_p->type)
{
case ITU_STANDARD:
pc = (addr_pc_p->pc & ITU_PC_MASK) | ((addr_pc_p->ni % 4) << 14) ;
break;
default:
pc = (addr_pc_p->pc & ANSI_PC_MASK) | ((addr_pc_p->ni) << 24) ;
break;
}
return pc;
}
void
dissect_mtp3_3byte_pc(tvbuff_t *tvb, guint offset, proto_tree *tree, gint ett_pc, int hf_pc_string, int hf_pc_network,
int hf_pc_cluster, int hf_pc_member, int hf_dpc, int hf_pc)
{
guint32 pc;
proto_item *pc_item, *hidden_item;
proto_tree *pc_tree;
char pc_string[MAX_STRUCTURED_PC_LENGTH];
pc = tvb_get_letoh24(tvb, offset);
mtp3_pc_to_str_buf(pc, pc_string, sizeof(pc_string));
pc_item = proto_tree_add_string(tree, hf_pc_string, tvb, offset, ANSI_PC_LENGTH, pc_string);
g_snprintf(pc_string, sizeof(pc_string), "%u", pc);
proto_item_append_text(pc_item, " (%s)", pc_string);
hidden_item = proto_tree_add_string(tree, hf_pc_string, tvb, offset, ANSI_PC_LENGTH, pc_string);
PROTO_ITEM_SET_HIDDEN(hidden_item);
g_snprintf(pc_string, sizeof(pc_string), "0x%x", pc);
proto_item_append_text(pc_item, " (%s)", pc_string);
hidden_item = proto_tree_add_string(tree, hf_pc_string, tvb, offset, ANSI_PC_LENGTH, pc_string);
PROTO_ITEM_SET_HIDDEN(hidden_item);
pc_tree = proto_item_add_subtree(pc_item, ett_pc);
proto_tree_add_uint(pc_tree, hf_pc_network, tvb, offset + ANSI_NETWORK_OFFSET, ANSI_NCM_LENGTH, pc);
proto_tree_add_uint(pc_tree, hf_pc_cluster, tvb, offset + ANSI_CLUSTER_OFFSET, ANSI_NCM_LENGTH, pc);
proto_tree_add_uint(pc_tree, hf_pc_member, tvb, offset + ANSI_MEMBER_OFFSET, ANSI_NCM_LENGTH, pc);
if (hf_dpc) {
hidden_item = proto_tree_add_uint(pc_tree, hf_dpc, tvb, offset, ANSI_PC_LENGTH, pc);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if (hf_pc) {
hidden_item = proto_tree_add_uint(pc_tree, hf_pc, tvb, offset, ANSI_PC_LENGTH, pc);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
static void
dissect_mtp3_sio(tvbuff_t *tvb, proto_tree *mtp3_tree,
mtp3_addr_pc_t *mtp3_addr_opc, mtp3_addr_pc_t *mtp3_addr_dpc)
{
guint8 sio;
proto_item *sio_item;
proto_tree *sio_tree;
sio_item = proto_tree_add_text(mtp3_tree, tvb, SIO_OFFSET, SIO_LENGTH, "Service information octet");
sio_tree = proto_item_add_subtree(sio_item, ett_mtp3_sio);
sio = tvb_get_guint8(tvb, SIO_OFFSET);
proto_tree_add_uint(sio_tree, hf_mtp3_network_indicator, tvb, SIO_OFFSET, SIO_LENGTH, sio);
mtp3_addr_opc->ni = (sio & NETWORK_INDICATOR_MASK) >> 6;
mtp3_addr_dpc->ni = (sio & NETWORK_INDICATOR_MASK) >> 6;
switch(mtp3_standard){
case ANSI_STANDARD:
proto_tree_add_uint(sio_tree, hf_mtp3_ansi_priority, tvb, SIO_OFFSET, SIO_LENGTH, sio);
break;
case ITU_STANDARD:
case CHINESE_ITU_STANDARD:
if (mtp3_show_itu_priority)
proto_tree_add_uint(sio_tree, hf_mtp3_itu_priority, tvb, SIO_OFFSET, SIO_LENGTH, sio);
else
proto_tree_add_uint(sio_tree, hf_mtp3_itu_spare, tvb, SIO_OFFSET, SIO_LENGTH, sio);
break;
case JAPAN_STANDARD:
proto_tree_add_uint(sio_tree, hf_mtp3_itu_spare, tvb, SIO_OFFSET, SIO_LENGTH, sio);
break;
}
proto_tree_add_uint(sio_tree, hf_mtp3_service_indicator, tvb, SIO_OFFSET, SIO_LENGTH, sio);
}
static void
dissect_mtp3_routing_label(tvbuff_t *tvb, packet_info *pinfo, proto_tree *mtp3_tree,
mtp3_addr_pc_t *mtp3_addr_opc, mtp3_addr_pc_t *mtp3_addr_dpc)
{
guint32 label, dpc, opc;
proto_item *label_item, *label_dpc_item, *label_opc_item;
proto_item *hidden_item;
proto_tree *label_tree;
proto_tree *pc_subtree;
int hf_dpc_string;
int hf_opc_string;
switch (mtp3_standard) {
case ITU_STANDARD:
label_item = proto_tree_add_text(mtp3_tree, tvb, ROUTING_LABEL_OFFSET, ITU_ROUTING_LABEL_LENGTH, "Routing label");
label_tree = proto_item_add_subtree(label_item, ett_mtp3_label);
label = tvb_get_letohl(tvb, ROUTING_LABEL_OFFSET);
opc = (label & ITU_OPC_MASK) >> 14;
dpc = label & ITU_DPC_MASK;
hidden_item = proto_tree_add_uint(label_tree, hf_mtp3_itu_pc, tvb, ROUTING_LABEL_OFFSET, ITU_ROUTING_LABEL_LENGTH, opc);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_uint(label_tree, hf_mtp3_itu_pc, tvb, ROUTING_LABEL_OFFSET, ITU_ROUTING_LABEL_LENGTH, dpc);
PROTO_ITEM_SET_HIDDEN(hidden_item);
label_dpc_item = proto_tree_add_uint(label_tree, hf_mtp3_itu_dpc, tvb, ROUTING_LABEL_OFFSET, ITU_ROUTING_LABEL_LENGTH, label);
if (mtp3_pc_structured())
proto_item_append_text(label_dpc_item, " (%s)", mtp3_pc_to_str(dpc));
if(mtp3_addr_dpc->ni == MTP3_NI_INT0) {
pc_subtree = proto_item_add_subtree(label_dpc_item, ett_mtp3_label_dpc);
analyze_q708_ispc(tvb, pc_subtree, ROUTING_LABEL_OFFSET, ITU_ROUTING_LABEL_LENGTH, dpc);
}
label_opc_item = proto_tree_add_uint(label_tree, hf_mtp3_itu_opc, tvb, ROUTING_LABEL_OFFSET, ITU_ROUTING_LABEL_LENGTH, label);
if (mtp3_pc_structured())
proto_item_append_text(label_opc_item, " (%s)", mtp3_pc_to_str(opc));
if(mtp3_addr_opc->ni == MTP3_NI_INT0) {
pc_subtree = proto_item_add_subtree(label_opc_item, ett_mtp3_label_opc);
analyze_q708_ispc(tvb, pc_subtree, ROUTING_LABEL_OFFSET, ITU_ROUTING_LABEL_LENGTH, opc);
}
proto_tree_add_uint(label_tree, hf_mtp3_itu_sls, tvb, ROUTING_LABEL_OFFSET, ITU_ROUTING_LABEL_LENGTH, label);
break;
case ANSI_STANDARD:
case CHINESE_ITU_STANDARD:
if (mtp3_standard == ANSI_STANDARD)
{
hf_dpc_string = hf_mtp3_ansi_dpc;
hf_opc_string = hf_mtp3_ansi_opc;
} else {
hf_dpc_string = hf_mtp3_chinese_dpc;
hf_opc_string = hf_mtp3_chinese_opc;
}
label_item = proto_tree_add_text(mtp3_tree, tvb, ROUTING_LABEL_OFFSET, ANSI_ROUTING_LABEL_LENGTH, "Routing label");
label_tree = proto_item_add_subtree(label_item, ett_mtp3_label);
dissect_mtp3_3byte_pc(tvb, ANSI_DPC_OFFSET, label_tree, ett_mtp3_label_dpc, hf_dpc_string, hf_mtp3_dpc_network,
hf_mtp3_dpc_cluster, hf_mtp3_dpc_member, hf_mtp3_24bit_dpc, hf_mtp3_24bit_pc);
dpc = tvb_get_letoh24(tvb, ANSI_DPC_OFFSET);
dissect_mtp3_3byte_pc(tvb, ANSI_OPC_OFFSET, label_tree, ett_mtp3_label_opc, hf_opc_string, hf_mtp3_opc_network,
hf_mtp3_opc_cluster, hf_mtp3_opc_member, hf_mtp3_24bit_opc, hf_mtp3_24bit_pc);
opc = tvb_get_letoh24(tvb, ANSI_OPC_OFFSET);
if (mtp3_standard == ANSI_STANDARD) {
if (mtp3_use_ansi_5_bit_sls)
proto_tree_add_item(label_tree, hf_mtp3_ansi_5_bit_sls, tvb, ANSI_SLS_OFFSET, SLS_LENGTH, ENC_NA);
else
proto_tree_add_item(label_tree, hf_mtp3_ansi_8_bit_sls, tvb, ANSI_SLS_OFFSET, SLS_LENGTH, ENC_NA);
} else {
proto_tree_add_item(label_tree, hf_mtp3_chinese_itu_sls, tvb, ANSI_SLS_OFFSET, SLS_LENGTH, ENC_NA);
}
break;
case JAPAN_STANDARD:
label_item = proto_tree_add_text(mtp3_tree, tvb, ROUTING_LABEL_OFFSET, JAPAN_ROUTING_LABEL_LENGTH, "Routing label");
label_tree = proto_item_add_subtree(label_item, ett_mtp3_label);
label_dpc_item = proto_tree_add_item(label_tree, hf_mtp3_japan_dpc, tvb, ROUTING_LABEL_OFFSET, JAPAN_PC_LENGTH, ENC_LITTLE_ENDIAN);
dpc = tvb_get_letohs(tvb, ROUTING_LABEL_OFFSET);
if (mtp3_pc_structured()) {
proto_item_append_text(label_dpc_item, " (%s)", mtp3_pc_to_str(dpc));
}
label_opc_item = proto_tree_add_item(label_tree, hf_mtp3_japan_opc, tvb, JAPAN_OPC_OFFSET, JAPAN_PC_LENGTH, ENC_LITTLE_ENDIAN);
opc = tvb_get_letohs(tvb, JAPAN_OPC_OFFSET);
if (mtp3_pc_structured()) {
proto_item_append_text(label_opc_item, " (%s)", mtp3_pc_to_str(opc));
}
hidden_item = proto_tree_add_item(label_tree, hf_mtp3_japan_pc, tvb, ROUTING_LABEL_OFFSET, JAPAN_PC_LENGTH, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item(label_tree, hf_mtp3_japan_pc, tvb, JAPAN_OPC_OFFSET, JAPAN_PC_LENGTH, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (mtp3_use_japan_5_bit_sls) {
proto_tree_add_item(label_tree, hf_mtp3_japan_5_bit_sls, tvb, JAPAN_SLS_OFFSET, JAPAN_SLS_SPARE_LENGTH, ENC_NA);
proto_tree_add_item(label_tree, hf_mtp3_japan_5_bit_sls_spare, tvb, JAPAN_SLS_OFFSET, JAPAN_SLS_SPARE_LENGTH, ENC_NA);
} else {
proto_tree_add_item(label_tree, hf_mtp3_japan_4_bit_sls, tvb, JAPAN_SLS_OFFSET, JAPAN_SLS_SPARE_LENGTH, ENC_NA);
proto_tree_add_item(label_tree, hf_mtp3_japan_4_bit_sls_spare, tvb, JAPAN_SLS_OFFSET, JAPAN_SLS_SPARE_LENGTH, ENC_NA);
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
mtp3_addr_opc->type = (Standard_Type)mtp3_standard;
mtp3_addr_opc->pc = opc;
SET_ADDRESS(&pinfo->src, AT_SS7PC, sizeof(mtp3_addr_pc_t), (guint8 *) mtp3_addr_opc);
mtp3_addr_dpc->type = (Standard_Type)mtp3_standard;
mtp3_addr_dpc->pc = dpc;
SET_ADDRESS(&pinfo->dst, AT_SS7PC, sizeof(mtp3_addr_pc_t), (guint8 *) mtp3_addr_dpc);
}
static void
dissect_mtp3_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 sio;
guint8 service_indicator;
tvbuff_t *payload_tvb = NULL;
sio = tvb_get_guint8(tvb, SIO_OFFSET);
service_indicator = sio & SERVICE_INDICATOR_MASK;
switch (mtp3_standard) {
case ITU_STANDARD:
payload_tvb = tvb_new_subset_remaining(tvb, ITU_MTP_PAYLOAD_OFFSET);
break;
case ANSI_STANDARD:
case CHINESE_ITU_STANDARD:
payload_tvb = tvb_new_subset_remaining(tvb, ANSI_MTP_PAYLOAD_OFFSET);
break;
case JAPAN_STANDARD:
payload_tvb = tvb_new_subset_remaining(tvb, JAPAN_MTP_PAYLOAD_OFFSET);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
col_set_str(pinfo->cinfo, COL_INFO, "DATA ");
if (!dissector_try_uint(mtp3_sio_dissector_table, service_indicator, payload_tvb, pinfo, tree))
call_dissector(data_handle, payload_tvb, pinfo, tree);
}
static guint
heur_mtp3_standard(tvbuff_t *tvb, packet_info *pinfo, guint8 si)
{
guint32 len;
tvbuff_t *payload;
len = tvb_length(tvb);
switch (si) {
case MTP_SI_SCCP:
{
payload = tvb_new_subset(tvb, ITU_HEADER_LENGTH, len-ITU_HEADER_LENGTH, len-ITU_HEADER_LENGTH);
if (looks_like_valid_sccp(PINFO_FD_NUM(pinfo), payload, ITU_STANDARD)) {
return ITU_STANDARD;
}
payload = tvb_new_subset(tvb, ANSI_HEADER_LENGTH, len-ANSI_HEADER_LENGTH, len-ANSI_HEADER_LENGTH);
if (looks_like_valid_sccp(PINFO_FD_NUM(pinfo), payload, ANSI_STANDARD)) {
return ANSI_STANDARD;
}
payload = tvb_new_subset(tvb, ANSI_HEADER_LENGTH, len-ANSI_HEADER_LENGTH, len-ANSI_HEADER_LENGTH);
if (looks_like_valid_sccp(PINFO_FD_NUM(pinfo), payload, CHINESE_ITU_STANDARD)) {
return CHINESE_ITU_STANDARD;
}
payload = tvb_new_subset(tvb, JAPAN_HEADER_LENGTH, len-JAPAN_HEADER_LENGTH, len-JAPAN_HEADER_LENGTH);
if (looks_like_valid_sccp(PINFO_FD_NUM(pinfo), payload, JAPAN_STANDARD)) {
return JAPAN_STANDARD;
}
return HEURISTIC_FAILED_STANDARD;
}
default:
return HEURISTIC_FAILED_STANDARD;
}
}
static void
reset_mtp3_standard(void)
{
mtp3_standard = pref_mtp3_standard;
}
static void
dissect_mtp3(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
mtp3_tap_rec_t* tap_rec = wmem_new0(wmem_packet_scope(), mtp3_tap_rec_t);
gint heuristic_standard;
guint8 si;
mtp3_addr_pc_t* mtp3_addr_dpc;
mtp3_addr_pc_t* mtp3_addr_opc;
proto_item *mtp3_item = NULL, *gen_item;
proto_tree *mtp3_tree = NULL;
pref_mtp3_standard = mtp3_standard;
mtp3_item = proto_tree_add_item(tree, proto_mtp3, tvb, 0, 0, ENC_NA);
si = tvb_get_guint8(tvb, SIO_OFFSET) & SERVICE_INDICATOR_MASK;
if (mtp3_heuristic_standard) {
heuristic_standard = heur_mtp3_standard(tvb, pinfo, si);
if (heuristic_standard == HEURISTIC_FAILED_STANDARD) {
gen_item = proto_tree_add_text(tree, tvb, 0, 0, "Could not determine Heuristic using %s", val_to_str_const(mtp3_standard, mtp3_standard_vals, "unknown"));
} else {
gen_item = proto_tree_add_text(tree, tvb, 0, 0, "%s", val_to_str_const(heuristic_standard, mtp3_standard_vals, "unknown"));
mtp3_standard = heuristic_standard;
register_frame_end_routine(pinfo, reset_mtp3_standard);
}
PROTO_ITEM_SET_GENERATED(gen_item);
}
switch(mtp3_standard) {
case ITU_STANDARD:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MTP3 (Int. ITU)");
proto_item_set_len(mtp3_item, ITU_HEADER_LENGTH);
break;
case ANSI_STANDARD:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MTP3 (ANSI)");
proto_item_set_len(mtp3_item, ANSI_HEADER_LENGTH);
break;
case CHINESE_ITU_STANDARD:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MTP3 (Chin. ITU)");
proto_item_set_len(mtp3_item, ANSI_HEADER_LENGTH);
break;
case JAPAN_STANDARD:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MTP3 (Japan)");
proto_item_set_len(mtp3_item, JAPAN_HEADER_LENGTH);
break;
};
if (tree) {
mtp3_tree = proto_item_add_subtree(mtp3_item, ett_mtp3);
}
mtp3_addr_opc = (mtp3_addr_pc_t *)wmem_alloc0(pinfo->pool, sizeof(mtp3_addr_pc_t));
mtp3_addr_dpc = (mtp3_addr_pc_t *)wmem_alloc0(pinfo->pool, sizeof(mtp3_addr_pc_t));
dissect_mtp3_sio(tvb, mtp3_tree, mtp3_addr_opc, mtp3_addr_dpc);
dissect_mtp3_routing_label(tvb, pinfo, mtp3_tree, mtp3_addr_opc, mtp3_addr_dpc);
memcpy(&(tap_rec->addr_opc), mtp3_addr_opc, sizeof(mtp3_addr_pc_t));
memcpy(&(tap_rec->addr_dpc), mtp3_addr_dpc, sizeof(mtp3_addr_pc_t));
tap_rec->si_code = (tvb_get_guint8(tvb, SIO_OFFSET) & SERVICE_INDICATOR_MASK);
tap_rec->size = tvb_length(tvb);
tap_queue_packet(mtp3_tap, pinfo, tap_rec);
dissect_mtp3_payload(tvb, pinfo, tree);
mtp3_standard = pref_mtp3_standard;
}
void
proto_register_mtp3(void)
{
static hf_register_info hf[] = {
{ &hf_mtp3_service_indicator, { "Service indicator", "mtp3.service_indicator", FT_UINT8, BASE_HEX, VALS(mtp3_service_indicator_code_vals), SERVICE_INDICATOR_MASK, NULL, HFILL }},
{ &hf_mtp3_network_indicator, { "Network indicator", "mtp3.network_indicator", FT_UINT8, BASE_HEX, VALS(mtp3_network_indicator_vals), NETWORK_INDICATOR_MASK, NULL, HFILL }},
{ &hf_mtp3_itu_spare, { "Spare", "mtp3.spare", FT_UINT8, BASE_HEX, NULL, SPARE_MASK, NULL, HFILL }},
{ &hf_mtp3_itu_priority, { "ITU priority", "mtp3.priority", FT_UINT8, BASE_DEC, NULL, SPARE_MASK, NULL, HFILL }},
{ &hf_mtp3_ansi_priority, { "ANSI Priority", "mtp3.priority", FT_UINT8, BASE_DEC, NULL, ANSI_PRIORITY_MASK, NULL, HFILL }},
{ &hf_mtp3_itu_opc, { "OPC", "mtp3.opc", FT_UINT32, BASE_DEC, NULL, ITU_OPC_MASK, NULL, HFILL }},
{ &hf_mtp3_itu_pc, { "PC", "mtp3.pc", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_mtp3_24bit_pc, { "PC", "mtp3.pc", FT_UINT32, BASE_DEC, NULL, ANSI_PC_MASK, NULL, HFILL }},
{ &hf_mtp3_24bit_opc, { "OPC", "mtp3.opc", FT_UINT32, BASE_DEC, NULL, ANSI_PC_MASK, NULL, HFILL }},
{ &hf_mtp3_ansi_opc, { "OPC", "mtp3.ansi_opc", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mtp3_chinese_opc, { "OPC", "mtp3.chinese_opc", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mtp3_opc_network, { "OPC Network", "mtp3.opc.network", FT_UINT24, BASE_DEC, NULL, ANSI_NETWORK_MASK, NULL, HFILL }},
{ &hf_mtp3_opc_cluster, { "OPC Cluster", "mtp3.opc.cluster", FT_UINT24, BASE_DEC, NULL, ANSI_CLUSTER_MASK, NULL, HFILL }},
{ &hf_mtp3_opc_member, { "OPC Member", "mtp3.opc.member", FT_UINT24, BASE_DEC, NULL, ANSI_MEMBER_MASK, NULL, HFILL }},
{ &hf_mtp3_japan_opc, { "OPC", "mtp3.opc", FT_UINT16, BASE_DEC, NULL, JAPAN_PC_MASK, NULL, HFILL }},
{ &hf_mtp3_japan_pc, { "PC", "mtp3.pc", FT_UINT16, BASE_DEC, NULL, JAPAN_PC_MASK, NULL, HFILL }},
{ &hf_mtp3_itu_dpc, { "DPC", "mtp3.dpc", FT_UINT32, BASE_DEC, NULL, ITU_DPC_MASK, NULL, HFILL }},
{ &hf_mtp3_24bit_dpc, { "DPC", "mtp3.dpc", FT_UINT32, BASE_DEC, NULL, ANSI_PC_MASK, NULL, HFILL }},
{ &hf_mtp3_ansi_dpc, { "DPC", "mtp3.ansi_dpc", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mtp3_chinese_dpc, { "DPC", "mtp3.chinese_dpc", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mtp3_dpc_network, { "DPC Network", "mtp3.dpc.network", FT_UINT24, BASE_DEC, NULL, ANSI_NETWORK_MASK, NULL, HFILL }},
{ &hf_mtp3_dpc_cluster, { "DPC Cluster", "mtp3.dpc.cluster", FT_UINT24, BASE_DEC, NULL, ANSI_CLUSTER_MASK, NULL, HFILL }},
{ &hf_mtp3_dpc_member, { "DPC Member", "mtp3.dpc.member", FT_UINT24, BASE_DEC, NULL, ANSI_MEMBER_MASK, NULL, HFILL }},
{ &hf_mtp3_japan_dpc, { "DPC", "mtp3.dpc", FT_UINT16, BASE_DEC, NULL, JAPAN_PC_MASK, NULL, HFILL }},
{ &hf_mtp3_itu_sls, { "Signalling Link Selector", "mtp3.sls", FT_UINT32, BASE_DEC, NULL, ITU_SLS_MASK, NULL, HFILL }},
{ &hf_mtp3_japan_4_bit_sls, { "Signalling Link Selector", "mtp3.sls", FT_UINT8, BASE_DEC, NULL, JAPAN_4_BIT_SLS_MASK, NULL, HFILL }},
{ &hf_mtp3_japan_4_bit_sls_spare, { "SLS Spare", "mtp3.sls_spare", FT_UINT8, BASE_HEX, NULL, JAPAN_4_BIT_SLS_SPARE_MASK, NULL, HFILL }},
{ &hf_mtp3_japan_5_bit_sls, { "Signalling Link Selector", "mtp3.sls", FT_UINT8, BASE_DEC, NULL, JAPAN_5_BIT_SLS_MASK, NULL, HFILL }},
{ &hf_mtp3_japan_5_bit_sls_spare, { "SLS Spare", "mtp3.sls_spare", FT_UINT8, BASE_HEX, NULL, JAPAN_5_BIT_SLS_SPARE_MASK, NULL, HFILL }},
{ &hf_mtp3_ansi_5_bit_sls, { "Signalling Link Selector", "mtp3.sls", FT_UINT8, BASE_DEC, NULL, ANSI_5BIT_SLS_MASK, NULL, HFILL }},
{ &hf_mtp3_ansi_8_bit_sls, { "Signalling Link Selector", "mtp3.sls", FT_UINT8, BASE_DEC, NULL, ANSI_8BIT_SLS_MASK, NULL, HFILL }},
{ &hf_mtp3_chinese_itu_sls, { "Signalling Link Selector", "mtp3.sls", FT_UINT8, BASE_DEC, NULL, CHINESE_ITU_SLS_MASK, NULL, HFILL }}
};
static gint *ett[] = {
&ett_mtp3,
&ett_mtp3_sio,
&ett_mtp3_label,
&ett_mtp3_label_dpc,
&ett_mtp3_label_opc
};
static const enum_val_t mtp3_options[] = {
{ "itu", "ITU", ITU_STANDARD },
{ "ansi", "ANSI", ANSI_STANDARD },
{ "chinese-itu", "Chinese ITU", CHINESE_ITU_STANDARD },
{ "japan", "Japan", JAPAN_STANDARD },
{ NULL, NULL, 0 }
};
static const enum_val_t mtp3_addr_fmt_str_e[] = {
{ "decimal", "Decimal", MTP3_ADDR_FMT_DEC },
{ "hexadecimal", "Hexadecimal", MTP3_ADDR_FMT_HEX },
{ "ni-decimal", "NI-Decimal", MTP3_ADDR_FMT_NI_DEC },
{ "ni-hexadecimal", "NI-Hexadecimal", MTP3_ADDR_FMT_NI_HEX },
{ "dashed", "Dashed", MTP3_ADDR_FMT_DASHED },
{ NULL, NULL, 0 }
};
static const enum_val_t itu_pc_structures[] = {
{ "unstructured", "Unstructured", ITU_PC_STRUCTURE_NONE},
{ "3-8-3", "3-8-3", ITU_PC_STRUCTURE_3_8_3 },
{ "4-3-4-3", "4-3-4-3", ITU_PC_STRUCTURE_4_3_4_3 },
{ NULL, NULL, 0 }
};
static const enum_val_t japan_pc_structures[] = {
{ "unstructured", "Unstructured", JAPAN_PC_STRUCTURE_NONE},
{ "7-4-5", "7-4-5", JAPAN_PC_STRUCTURE_7_4_5 },
{ "3-4-4-5", "3-4-4-5", JAPAN_PC_STRUCTURE_3_4_4_5 },
{ NULL, NULL, 0 }
};
proto_mtp3 = proto_register_protocol("Message Transfer Part Level 3",
"MTP3", "mtp3");
register_dissector("mtp3", dissect_mtp3, proto_mtp3);
proto_register_field_array(proto_mtp3, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
mtp3_sio_dissector_table = register_dissector_table("mtp3.service_indicator",
"MTP3 Service indicator",
FT_UINT8, BASE_HEX);
mtp3_tap = register_tap("mtp3");
mtp3_module = prefs_register_protocol(proto_mtp3, NULL);
prefs_register_bool_preference(mtp3_module, "heuristic_standard",
"Try to determine the MTP3 standard heuristically",
"This only works for SCCP traffic for now",
&mtp3_heuristic_standard);
prefs_register_enum_preference(mtp3_module, "standard", "MTP3 standard",
"The SS7 standard used in MTP3 packets",
&mtp3_standard, mtp3_options, FALSE);
prefs_register_enum_preference(mtp3_module, "itu_pc_structure", "ITU Pointcode structure",
"The structure of the pointcodes in ITU networks",
&itu_pc_structure, itu_pc_structures, FALSE);
prefs_register_enum_preference(mtp3_module, "japan_pc_structure", "Japan Pointcode structure",
"The structure of the pointcodes in Japan networks",
&japan_pc_structure, japan_pc_structures, FALSE);
prefs_register_bool_preference(mtp3_module, "ansi_5_bit_sls",
"Use 5-bit SLS (ANSI only)",
"Use 5-bit (instead of 8-bit) SLS in ANSI MTP3 packets",
&mtp3_use_ansi_5_bit_sls);
prefs_register_bool_preference(mtp3_module, "japan_5_bit_sls",
"Use 5-bit SLS (Japan only)",
"Use 5-bit (instead of 4-bit) SLS in Japan MTP3 packets",
&mtp3_use_japan_5_bit_sls);
prefs_register_enum_preference(mtp3_module, "addr_format", "Address Format",
"Format for point code in the address columns",
&mtp3_addr_fmt, mtp3_addr_fmt_str_e, FALSE);
prefs_register_bool_preference(mtp3_module, "itu_priority",
"Show MSU priority (national option, ITU and China ITU only)",
"Decode the spare bits of the SIO as the MSU priority (a national option in ITU)",
&mtp3_show_itu_priority);
}
void
proto_reg_handoff_mtp3(void)
{
dissector_handle_t mtp3_handle;
mtp3_handle = find_dissector("mtp3");
dissector_add_uint("wtap_encap", WTAP_ENCAP_MTP3, mtp3_handle);
dissector_add_string("tali.opcode", "mtp3", mtp3_handle);
data_handle = find_dissector("data");
}
