static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(nbap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(nbap_extension_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (!ProcedureID) return 0;
return (dissector_try_string(nbap_proc_imsg_dissector_table, ProcedureID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (!ProcedureID) return 0;
return (dissector_try_string(nbap_proc_sout_dissector_table, ProcedureID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (!ProcedureID) return 0;
return (dissector_try_string(nbap_proc_uout_dissector_table, ProcedureID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static void add_hsdsch_bind(packet_info *pinfo){
address null_addr;
conversation_t *conversation = NULL;
umts_fp_conversation_info_t *umts_fp_conversation_info;
guint32 i;
if (pinfo->fd->flags.visited){
return;
}
SET_ADDRESS(&null_addr, AT_NONE, 0, NULL);
for (i = 0; i < maxNrOfMACdFlows; i++) {
if (nbap_hsdsch_channel_info[i].crnc_port != 0){
conversation = find_conversation(pinfo->fd->num, &(nbap_hsdsch_channel_info[i].crnc_address), &null_addr,
PT_UDP,
nbap_hsdsch_channel_info[i].crnc_port, 0, NO_ADDR_B);
if (conversation == NULL) {
conversation = conversation_new(pinfo->fd->num, &(nbap_hsdsch_channel_info[i].crnc_address),
&null_addr, PT_UDP, nbap_hsdsch_channel_info[i].crnc_port,
0, NO_ADDR2|NO_PORT2);
conversation_set_dissector(conversation, fp_handle);
if(pinfo->link_dir==P2P_DIR_DL){
umts_fp_conversation_info = wmem_new0(wmem_file_scope(), umts_fp_conversation_info_t);
umts_fp_conversation_info->iface_type = IuB_Interface;
umts_fp_conversation_info->division = Division_FDD;
umts_fp_conversation_info->channel = CHANNEL_HSDSCH;
umts_fp_conversation_info->dl_frame_number = 0;
umts_fp_conversation_info->ul_frame_number = pinfo->fd->num;
SE_COPY_ADDRESS(&(umts_fp_conversation_info->crnc_address), &nbap_hsdsch_channel_info[i].crnc_address);
umts_fp_conversation_info->crnc_port = nbap_hsdsch_channel_info[i].crnc_port;
umts_fp_conversation_info->hsdsch_macdflow_id = i ;
umts_fp_conversation_info->num_dch_in_flow++;
umts_fp_conversation_info->dchs_in_flow_list[umts_fp_conversation_info->num_dch_in_flow -1] = i;
if(nbap_hsdsch_channel_info[i].entity == entity_not_specified ){
expert_add_info(pinfo, NULL, &ei_nbap_hsdsch_entity_not_specified);
}else{
umts_fp_conversation_info->hsdsch_entity = (enum fp_hsdsch_entity)nbap_hsdsch_channel_info[i].entity;
}
umts_fp_conversation_info->rlc_mode = nbap_hsdsch_channel_info[i].rlc_mode;
set_umts_fp_conv_data(conversation, umts_fp_conversation_info);
}
}
}
}
}
static gint nbap_key_cmp(gconstpointer a_ptr, gconstpointer b_ptr, gpointer ignore _U_){
if( GPOINTER_TO_INT(a_ptr) > GPOINTER_TO_INT(b_ptr) ){
return -1;
}
return GPOINTER_TO_INT(a_ptr) < GPOINTER_TO_INT(b_ptr);
}
static void nbap_init(void){
guint8 i;
if(com_context_map){
g_tree_destroy(com_context_map);
}
com_context_map = g_tree_new_full(nbap_key_cmp,
NULL,
NULL,
g_free);
edch_flow_port_map = g_tree_new_full(nbap_key_cmp,
NULL,
NULL,
g_free);
for (i = 0; i < 15; i++) {
lchId_type_table[i+1] = *lch_contents[i];
}
}
static void
dissect_nbap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *nbap_item = NULL;
proto_tree *nbap_tree = NULL;
int i;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NBAP");
nbap_item = proto_tree_add_item(tree, proto_nbap, tvb, 0, -1, ENC_NA);
nbap_tree = proto_item_add_subtree(nbap_item, ett_nbap);
for (i = 0; i < maxNrOfMACdFlows; i++) {
nbap_hsdsch_channel_info[i].entity = hs;
}
dissect_NBAP_PDU_PDU(tvb, pinfo, nbap_tree);
}
void proto_register_nbap(void)
{
module_t *nbap_module;
guint8 i;
static hf_register_info hf[] = {
{ &hf_nbap_transportLayerAddress_ipv4,
{ "transportLayerAddress IPv4", "nbap.transportLayerAddress_ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_nbap_transportLayerAddress_ipv6,
{ "transportLayerAddress IPv6", "nbap.transportLayerAddress_ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_nbap_transportLayerAddress_nsap,
{ "transportLayerAddress NSAP", "nbap.transportLayerAddress_NSAP",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
#include "packet-nbap-hfarr.c"
};
static gint *ett[] = {
&ett_nbap,
&ett_nbap_TransportLayerAddress,
&ett_nbap_TransportLayerAddress_nsap,
&ett_nbap_ib_sg_data,
#include "packet-nbap-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_nbap_no_set_comm_context_id, { "nbap.no_set_comm_context_id", PI_MALFORMED, PI_WARN, "Couldn't not set Communication Context-ID, fragments over reconfigured channels might fail", EXPFILL }},
{ &ei_nbap_no_find_comm_context_id, { "nbap.no_find_comm_context_id", PI_MALFORMED, PI_WARN, "Couldn't not find Communication Context-ID, unable to reconfigure this E-DCH flow.", EXPFILL }},
{ &ei_nbap_no_find_port_info, { "nbap.no_find_port_info", PI_MALFORMED, PI_WARN, "Couldn't not find port information for reconfigured E-DCH flow, unable to reconfigure", EXPFILL }},
{ &ei_nbap_hsdsch_entity_not_specified, { "nbap.hsdsch_entity_not_specified", PI_MALFORMED,PI_ERROR, "HSDSCH Entity not specified!", EXPFILL }},
};
expert_module_t* expert_nbap;
proto_nbap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_nbap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_nbap = expert_register_protocol(proto_nbap);
expert_register_field_array(expert_nbap, ei, array_length(ei));
register_dissector("nbap", dissect_nbap, proto_nbap);
nbap_module = prefs_register_protocol(proto_nbap, NULL);
for (i = 0; i < 16; i++) {
prefs_register_enum_preference(nbap_module, ch_strings[i].name, ch_strings[i].title, ch_strings[i].description, lch_contents[i], content_types, FALSE);
}
nbap_ies_dissector_table = register_dissector_table("nbap.ies", "NBAP-PROTOCOL-IES", FT_UINT32, BASE_DEC);
nbap_extension_dissector_table = register_dissector_table("nbap.extension", "NBAP-PROTOCOL-EXTENSION", FT_UINT32, BASE_DEC);
nbap_proc_imsg_dissector_table = register_dissector_table("nbap.proc.imsg", "NBAP-ELEMENTARY-PROCEDURE InitiatingMessage", FT_STRING, BASE_NONE);
nbap_proc_sout_dissector_table = register_dissector_table("nbap.proc.sout", "NBAP-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_STRING, BASE_NONE);
nbap_proc_uout_dissector_table = register_dissector_table("nbap.proc.uout", "NBAP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_STRING, BASE_NONE);
register_init_routine(nbap_init);
}
void
proto_reg_handoff_nbap(void)
{
dissector_handle_t nbap_handle;
nbap_handle = find_dissector("nbap");
fp_handle = find_dissector("fp");
dissector_add_uint("sctp.ppi", NBAP_PAYLOAD_PROTOCOL_ID, nbap_handle);
#ifdef EXTRA_PPI
dissector_add_uint("sctp.ppi", 17, nbap_handle);
#endif
dissector_add_handle("sctp.port", nbap_handle);
#include "packet-nbap-dis-tab.c"
}
