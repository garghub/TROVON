static void
s1ap_Threshold_RSRP_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%ddBm (%u)", (gint32)v-140, v);
}
static void
s1ap_Threshold_RSRQ_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%.1fdB (%u)", ((float)v/2)-20, v);
}
static void
s1ap_Time_UE_StayedInCell_EnhancedGranularity_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%.1fs", ((float)v)/10);
}
static void
dissect_s1ap_warningMessageContents(tvbuff_t *warning_msg_tvb, proto_tree *tree, packet_info *pinfo, guint8 dcs)
{
guint32 offset;
guint8 nb_of_pages, length, *str;
proto_item *ti;
tvbuff_t *cb_data_page_tvb, *cb_data_tvb;
int i;
nb_of_pages = tvb_get_guint8(warning_msg_tvb, 0);
ti = proto_tree_add_uint(tree, hf_s1ap_WarningMessageContents_nb_pages, warning_msg_tvb, 0, 1, nb_of_pages);
if (nb_of_pages > 15) {
expert_add_info_format(pinfo, ti, &ei_s1ap_number_pages_le15,
"Number of pages should be <=15 (found %u)", nb_of_pages);
nb_of_pages = 15;
}
for (i = 0, offset = 1; i < nb_of_pages; i++) {
length = tvb_get_guint8(warning_msg_tvb, offset+82);
cb_data_page_tvb = tvb_new_subset_length(warning_msg_tvb, offset, length);
cb_data_tvb = dissect_cbs_data(dcs, cb_data_page_tvb, tree, pinfo, 0);
if (cb_data_tvb) {
str = tvb_get_string_enc(wmem_packet_scope(), cb_data_tvb, 0, tvb_reported_length(cb_data_tvb), ENC_UTF_8|ENC_NA);
proto_tree_add_string_format(tree, hf_s1ap_WarningMessageContents_decoded_page, warning_msg_tvb, offset, 83,
str, "Decoded Page %u: %s", i+1, str);
}
offset += 83;
}
}
static void
s1ap_EUTRANRoundTripDelayEstimationInfo_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%uTs (%u)", 16*v, v);
}
static struct s1ap_private_data*
s1ap_get_private_data(packet_info *pinfo)
{
struct s1ap_private_data *s1ap_data = (struct s1ap_private_data*)p_get_proto_data(pinfo->pool, pinfo, proto_s1ap, 0);
if (!s1ap_data) {
s1ap_data = wmem_new0(pinfo->pool, struct s1ap_private_data);
p_add_proto_data(pinfo->pool, pinfo, proto_s1ap, 0, s1ap_data);
}
return s1ap_data;
}
static gboolean
s1ap_is_nbiot_ue(packet_info *pinfo)
{
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(pinfo);
if (s1ap_data->s1ap_conv) {
wmem_tree_key_t tree_key[3];
guint32 *id;
guint32 enb_ue_s1ap_id = s1ap_data->enb_ue_s1ap_id;
tree_key[0].length = 1;
tree_key[0].key = &enb_ue_s1ap_id;
tree_key[1].length = 1;
tree_key[1].key = &pinfo->num;
tree_key[2].length = 0;
tree_key[2].key = NULL;
id = (guint32*)wmem_tree_lookup32_array_le(s1ap_data->s1ap_conv->nbiot_enb_ue_s1ap_id, tree_key);
if (id && (*id == enb_ue_s1ap_id)) {
return TRUE;
}
}
return FALSE;
}
static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
s1ap_ctx_t s1ap_ctx;
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(pinfo);
s1ap_ctx.message_type = s1ap_data->message_type;
s1ap_ctx.ProcedureCode = s1ap_data->procedure_code;
s1ap_ctx.ProtocolIE_ID = s1ap_data->protocol_ie_id;
s1ap_ctx.ProtocolExtensionID = s1ap_data->protocol_extension_id;
return (dissector_try_uint_new(s1ap_ies_dissector_table, s1ap_data->protocol_ie_id, tvb, pinfo, tree, TRUE, &s1ap_ctx)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
s1ap_ctx_t s1ap_ctx;
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(pinfo);
s1ap_ctx.message_type = s1ap_data->message_type;
s1ap_ctx.ProcedureCode = s1ap_data->procedure_code;
s1ap_ctx.ProtocolIE_ID = s1ap_data->protocol_ie_id;
s1ap_ctx.ProtocolExtensionID = s1ap_data->protocol_extension_id;
return (dissector_try_uint_new(s1ap_extension_dissector_table, s1ap_data->protocol_extension_id, tvb, pinfo, tree, TRUE, &s1ap_ctx)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(pinfo);
return (dissector_try_uint_new(s1ap_proc_imsg_dissector_table, s1ap_data->procedure_code, tvb, pinfo, tree, TRUE, data)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(pinfo);
return (dissector_try_uint_new(s1ap_proc_sout_dissector_table, s1ap_data->procedure_code, tvb, pinfo, tree, TRUE, data)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
struct s1ap_private_data *s1ap_data = s1ap_get_private_data(pinfo);
return (dissector_try_uint_new(s1ap_proc_uout_dissector_table, s1ap_data->procedure_code, tvb, pinfo, tree, TRUE, data)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_s1ap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *s1ap_item = NULL;
proto_tree *s1ap_tree = NULL;
conversation_t *conversation;
struct s1ap_private_data* s1ap_data;
wmem_list_frame_t *prev_layer;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "S1AP");
prev_layer = wmem_list_frame_prev(wmem_list_tail(pinfo->layers));
if (prev_layer && GPOINTER_TO_INT(wmem_list_frame_data(prev_layer)) != proto_s1ap)
col_clear_fence(pinfo->cinfo, COL_INFO);
col_clear(pinfo->cinfo, COL_INFO);
s1ap_item = proto_tree_add_item(tree, proto_s1ap, tvb, 0, -1, ENC_NA);
s1ap_tree = proto_item_add_subtree(s1ap_item, ett_s1ap);
s1ap_data = s1ap_get_private_data(pinfo);
conversation = find_or_create_conversation(pinfo);
s1ap_data->s1ap_conv = (struct s1ap_conv_info *)conversation_get_proto_data(conversation, proto_s1ap);
if (!s1ap_data->s1ap_conv) {
s1ap_data->s1ap_conv = wmem_new(wmem_file_scope(), struct s1ap_conv_info);
s1ap_data->s1ap_conv->nbiot_ta = wmem_map_new(wmem_file_scope(), wmem_int64_hash, g_int64_equal);
s1ap_data->s1ap_conv->nbiot_enb_ue_s1ap_id = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_s1ap, s1ap_data->s1ap_conv);
}
dissect_S1AP_PDU_PDU(tvb, pinfo, s1ap_tree, NULL);
return tvb_captured_length(tvb);
}
void
proto_reg_handoff_s1ap(void)
{
static gboolean Initialized=FALSE;
static guint SctpPort;
gcsna_handle = find_dissector_add_dependency("gcsna", proto_s1ap);
if (!Initialized) {
nas_eps_handle = find_dissector_add_dependency("nas-eps", proto_s1ap);
lppa_handle = find_dissector_add_dependency("lppa", proto_s1ap);
bssgp_handle = find_dissector_add_dependency("bssgp", proto_s1ap);
dissector_add_for_decode_as("sctp.port", s1ap_handle);
dissector_add_uint("sctp.ppi", S1AP_PAYLOAD_PROTOCOL_ID, s1ap_handle);
Initialized=TRUE;
#include "packet-s1ap-dis-tab.c"
} else {
if (SctpPort != 0) {
dissector_delete_uint("sctp.port", SctpPort, s1ap_handle);
}
}
SctpPort=gbl_s1apSctpPort;
if (SctpPort != 0) {
dissector_add_uint("sctp.port", SctpPort, s1ap_handle);
}
}
void proto_register_s1ap(void) {
static hf_register_info hf[] = {
{ &hf_s1ap_transportLayerAddressIPv4,
{ "transportLayerAddress(IPv4)", "s1ap.transportLayerAddressIPv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_transportLayerAddressIPv6,
{ "transportLayerAddress(IPv6)", "s1ap.transportLayerAddressIPv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_UTRAN_Trace_ID_TraceID,
{ "TraceID", "s1ap.E_UTRAN_Trace_ID.TraceID",
FT_UINT24, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_E_UTRAN_Trace_ID_TraceRecordingSessionReference,
{ "TraceRecordingSessionReference", "s1ap.E_UTRAN_Trace_ID.TraceRecordingSessionReference",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_interfacesToTrace_S1_MME,
{ "S1-MME", "s1ap.interfacesToTrace.S1_MME",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_interfacesToTrace), 0x80,
NULL, HFILL }},
{ &hf_s1ap_interfacesToTrace_X2,
{ "X2", "s1ap.interfacesToTrace.X2",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_interfacesToTrace), 0x40,
NULL, HFILL }},
{ &hf_s1ap_interfacesToTrace_Uu,
{ "Uu", "s1ap.interfacesToTrace.Uu",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_interfacesToTrace), 0x20,
NULL, HFILL }},
{ &hf_s1ap_interfacesToTrace_Reserved,
{ "Reserved", "s1ap.interfacesToTrace.Reserved",
FT_UINT8, BASE_HEX, NULL, 0x1f,
NULL, HFILL }},
{ &hf_s1ap_encryptionAlgorithms_EEA1,
{ "128-EEA1", "s1ap.encryptionAlgorithms.EEA1",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x8000,
NULL, HFILL }},
{ &hf_s1ap_encryptionAlgorithms_EEA2,
{ "128-EEA2", "s1ap.encryptionAlgorithms.EEA2",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x4000,
NULL, HFILL }},
{ &hf_s1ap_encryptionAlgorithms_EEA3,
{ "128-EEA3", "s1ap.encryptionAlgorithms.EEA3",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x2000,
NULL, HFILL }},
{ &hf_s1ap_encryptionAlgorithms_Reserved,
{ "Reserved", "s1ap.encryptionAlgorithms.Reserved",
FT_UINT16, BASE_HEX, NULL, 0x1fff,
NULL, HFILL }},
{ &hf_s1ap_integrityProtectionAlgorithms_EIA1,
{ "128-EIA1", "s1ap.integrityProtectionAlgorithms.EIA1",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x8000,
NULL, HFILL }},
{ &hf_s1ap_integrityProtectionAlgorithms_EIA2,
{ "128-EIA2", "s1ap.integrityProtectionAlgorithms.EIA2",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x4000,
NULL, HFILL }},
{ &hf_s1ap_integrityProtectionAlgorithms_EIA3,
{ "128-EIA3", "s1ap.integrityProtectionAlgorithms.EIA3",
FT_BOOLEAN, 16, TFS(&tfs_supported_not_supported), 0x2000,
NULL, HFILL }},
{ &hf_s1ap_integrityProtectionAlgorithms_Reserved,
{ "Reserved", "s1ap.integrityProtectionAlgorithms.Reserved",
FT_UINT16, BASE_HEX, NULL, 0x1fff,
NULL, HFILL }},
{ &hf_s1ap_SerialNumber_gs,
{ "Geographical Scope", "s1ap.SerialNumber.gs",
FT_UINT16, BASE_DEC, VALS(s1ap_serialNumber_gs_vals), 0xc000,
NULL, HFILL }},
{ &hf_s1ap_SerialNumber_msg_code,
{ "Message Code", "s1ap.SerialNumber.msg_code",
FT_UINT16, BASE_DEC, NULL, 0x3ff0,
NULL, HFILL }},
{ &hf_s1ap_SerialNumber_upd_nb,
{ "Update Number", "s1ap.SerialNumber.upd_nb",
FT_UINT16, BASE_DEC, NULL, 0x000f,
NULL, HFILL }},
{ &hf_s1ap_WarningType_value,
{ "Warning Type Value", "s1ap.WarningType.value",
FT_UINT16, BASE_DEC, VALS(s1ap_warningType_vals), 0xfe00,
NULL, HFILL }},
{ &hf_s1ap_WarningType_emergency_user_alert,
{ "Emergency User Alert", "s1ap.WarningType.emergency_user_alert",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0100,
NULL, HFILL }},
{ &hf_s1ap_WarningType_popup,
{ "Popup", "s1ap.WarningType.popup",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0080,
NULL, HFILL }},
{ &hf_s1ap_WarningMessageContents_nb_pages,
{ "Number of Pages", "s1ap.WarningMessageContents.nb_pages",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_WarningMessageContents_decoded_page,
{ "Decoded Page", "lte-rrc.WarningMessageContents.decoded_page",
FT_STRING, STR_UNICODE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_M1,
{ "M1", "s1ap.measurementsToActivate.M1",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x80,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_M2,
{ "M2", "s1ap.measurementsToActivate.M2",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x40,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_M3,
{ "M3", "s1ap.measurementsToActivate.M3",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x20,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_M4,
{ "M4", "s1ap.measurementsToActivate.M4",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x10,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_M5,
{ "M5", "s1ap.measurementsToActivate.M5",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x08,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_LoggingM1FromEventTriggered,
{ "LoggingOfM1FromEventTriggeredMeasurementReports", "s1ap.measurementsToActivate.LoggingM1FromEventTriggered",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x04,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_M6,
{ "M6", "s1ap.measurementsToActivate.M6",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x02,
NULL, HFILL }},
{ &hf_s1ap_measurementsToActivate_M7,
{ "M7", "s1ap.measurementsToActivate.M7",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x01,
NULL, HFILL }},
{ &hf_s1ap_MDT_Location_Info_GNSS,
{ "GNSS", "s1ap.MDT_Location_Info.GNSS",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x80,
NULL, HFILL }},
{ &hf_s1ap_MDT_Location_Info_E_CID,
{ "E-CID", "s1ap.MDT_Location_Info.E_CID",
FT_BOOLEAN, 8, TFS(&s1ap_tfs_activate_do_not_activate), 0x40,
NULL, HFILL }},
{ &hf_s1ap_MDT_Location_Info_Reserved,
{ "Reserved", "s1ap.MDT_Location_Info.Reserved",
FT_UINT8, BASE_HEX, NULL, 0x3f,
NULL, HFILL }},
#include "packet-s1ap-hfarr.c"
};
static gint *ett[] = {
&ett_s1ap,
&ett_s1ap_TransportLayerAddress,
&ett_s1ap_ToTargetTransparentContainer,
&ett_s1ap_ToSourceTransparentContainer,
&ett_s1ap_RRCContainer,
&ett_s1ap_UERadioCapability,
&ett_s1ap_RIMInformation,
&ett_s1ap_Cdma2000PDU,
&ett_s1ap_Cdma2000SectorID,
&ett_s1ap_UERadioPagingInformation,
&ett_s1ap_UE_HistoryInformationFromTheUE,
&ett_s1ap_CELevel,
&ett_s1ap_UE_RLF_Report_Container,
&ett_s1ap_UE_RLF_Report_Container_for_extended_bands,
&ett_s1ap_S1_Message,
&ett_s1ap_E_UTRAN_Trace_ID,
&ett_s1ap_InterfacesToTrace,
&ett_s1ap_EncryptionAlgorithms,
&ett_s1ap_IntegrityProtectionAlgorithms,
&ett_s1ap_LastVisitedUTRANCellInformation,
&ett_s1ap_SerialNumber,
&ett_s1ap_WarningType,
&ett_s1ap_DataCodingScheme,
&ett_s1ap_WarningMessageContents,
&ett_s1ap_MSClassmark,
&ett_s1ap_MeasurementsToActivate,
&ett_s1ap_MDT_Location_Info,
&ett_s1ap_IMSI,
&ett_s1ap_NASSecurityParameters,
#include "packet-s1ap-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_s1ap_number_pages_le15, { "s1ap.number_pages_le15", PI_MALFORMED, PI_ERROR, "Number of pages should be <=15", EXPFILL }}
};
module_t *s1ap_module;
expert_module_t* expert_s1ap;
proto_s1ap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_s1ap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_s1ap = expert_register_protocol(proto_s1ap);
expert_register_field_array(expert_s1ap, ei, array_length(ei));
s1ap_handle = register_dissector("s1ap", dissect_s1ap, proto_s1ap);
s1ap_ies_dissector_table = register_dissector_table("s1ap.ies", "S1AP-PROTOCOL-IES", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_ies_p1_dissector_table = register_dissector_table("s1ap.ies.pair.first", "S1AP-PROTOCOL-IES-PAIR FirstValue", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_ies_p2_dissector_table = register_dissector_table("s1ap.ies.pair.second", "S1AP-PROTOCOL-IES-PAIR SecondValue", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_extension_dissector_table = register_dissector_table("s1ap.extension", "S1AP-PROTOCOL-EXTENSION", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_proc_imsg_dissector_table = register_dissector_table("s1ap.proc.imsg", "S1AP-ELEMENTARY-PROCEDURE InitiatingMessage", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_proc_sout_dissector_table = register_dissector_table("s1ap.proc.sout", "S1AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_proc_uout_dissector_table = register_dissector_table("s1ap.proc.uout", "S1AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_module = prefs_register_protocol(proto_s1ap, proto_reg_handoff_s1ap);
prefs_register_uint_preference(s1ap_module, "sctp.port",
"S1AP SCTP Port",
"Set the SCTP port for S1AP messages",
10,
&gbl_s1apSctpPort);
prefs_register_bool_preference(s1ap_module, "dissect_container", "Dissect TransparentContainer", "Dissect TransparentContainers that are opaque to S1AP", &g_s1ap_dissect_container);
prefs_register_enum_preference(s1ap_module, "dissect_lte_container_as", "Dissect LTE TransparentContainer as",
"Select whether LTE TransparentContainer should be dissected as NB-IOT or legacy LTE",
&g_s1ap_dissect_lte_container_as, s1ap_lte_container_vals, FALSE);
}
