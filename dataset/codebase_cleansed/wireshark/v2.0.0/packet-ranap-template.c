static int
dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int ret = 0;
int key;
switch(ProcedureCode){
case id_RelocationPreparation:
if((ProtocolIE_ID == id_Source_ToTarget_TransparentContainer)||(ProtocolIE_ID == id_Target_ToSource_TransparentContainer)){
key = SPECIAL | ProtocolIE_ID;
ret = (dissector_try_uint_new(ranap_ies_dissector_table, key, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
break;
}
default:
ret = (dissector_try_uint_new(ranap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
if (ret == 0) {
key = pdu_type | ProtocolIE_ID;
ret = (dissector_try_uint_new(ranap_ies_dissector_table, key, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
break;
}
return ret;
}
static int
dissect_ProtocolIEFieldPairFirstValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(ranap_ies_p1_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_ProtocolIEFieldPairSecondValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(ranap_ies_p2_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(ranap_extension_dissector_table, ProtocolExtensionID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gboolean ret;
pdu_type = IMSG;
ret = dissector_try_uint_new(ranap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL);
pdu_type = 0;
return ret ? tvb_captured_length(tvb) : 0;
}
static int
dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gboolean ret;
pdu_type = SOUT;
ret = dissector_try_uint_new(ranap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL);
pdu_type = 0;
return ret ? tvb_captured_length(tvb) : 0;
}
static int
dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(ranap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_OutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(ranap_proc_out_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_ranap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_item *ranap_item = NULL;
proto_tree *ranap_tree = NULL;
sccp_msg_info_t *sccp_msg_lcl = (sccp_msg_info_t *)data;
pdu_type = 0;
ProtocolIE_ID = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RANAP");
ranap_item = proto_tree_add_item(tree, proto_ranap, tvb, 0, -1, ENC_NA);
ranap_tree = proto_item_add_subtree(ranap_item, ett_ranap);
p_add_proto_data(pinfo->pool, pinfo, proto_ranap, pinfo->curr_layer_num, data);
dissect_RANAP_PDU_PDU(tvb, pinfo, ranap_tree, NULL);
if (sccp_msg_lcl) {
if (sccp_msg_lcl->data.co.assoc)
sccp_msg_lcl->data.co.assoc->payload = SCCP_PLOAD_RANAP;
if (! sccp_msg_lcl->data.co.label && ProcedureCode != 0xFFFFFFFF) {
const gchar* str = val_to_str(ProcedureCode, ranap_ProcedureCode_vals,"Unknown RANAP");
sccp_msg_lcl->data.co.label = wmem_strdup(wmem_file_scope(), str);
}
}
return tvb_reported_length(tvb);
}
static gboolean
dissect_sccp_ranap_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint8 temp;
guint16 word;
asn1_ctx_t asn1_ctx;
guint length;
int offset;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
#define LENGTH_OFFSET 3
#define MSG_TYPE_OFFSET 1
if (tvb_captured_length(tvb) < RANAP_MSG_MIN_LENGTH) { return FALSE; }
offset = dissect_per_length_determinant(tvb, LENGTH_OFFSET<<3, &asn1_ctx, tree, -1, &length);
offset = offset>>3;
if (length!= (tvb_reported_length(tvb) - offset)){
return FALSE;
}
temp = tvb_get_guint8(tvb, MSG_TYPE_OFFSET);
if (temp > RANAP_MAX_PC) { return FALSE; }
word = tvb_get_ntohs(tvb, offset + 1);
if (word > 0x1ff){
return FALSE;
}
dissect_ranap(tvb, pinfo, tree, data);
return TRUE;
}
void proto_register_ranap(void) {
module_t *ranap_module;
static hf_register_info hf[] = {
{ &hf_ranap_transportLayerAddress_ipv4,
{ "transportLayerAddress IPv4", "ranap.transportLayerAddress_ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_transportLayerAddress_ipv6,
{ "transportLayerAddress IPv6", "ranap.transportLayerAddress_ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ranap_transportLayerAddress_nsap,
{ "transportLayerAddress NSAP", "ranap.transportLayerAddress_NSAP",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
#include "packet-ranap-hfarr.c"
};
static gint *ett[] = {
&ett_ranap,
&ett_ranap_TransportLayerAddress,
&ett_ranap_TransportLayerAddress_nsap,
#include "packet-ranap-ettarr.c"
};
proto_ranap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_ranap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("ranap", dissect_ranap, proto_ranap);
ranap_ies_dissector_table = register_dissector_table("ranap.ies", "RANAP-PROTOCOL-IES", FT_UINT32, BASE_DEC);
ranap_ies_p1_dissector_table = register_dissector_table("ranap.ies.pair.first", "RANAP-PROTOCOL-IES-PAIR FirstValue", FT_UINT32, BASE_DEC);
ranap_ies_p2_dissector_table = register_dissector_table("ranap.ies.pair.second", "RANAP-PROTOCOL-IES-PAIR SecondValue", FT_UINT32, BASE_DEC);
ranap_extension_dissector_table = register_dissector_table("ranap.extension", "RANAP-PROTOCOL-EXTENSION", FT_UINT32, BASE_DEC);
ranap_proc_imsg_dissector_table = register_dissector_table("ranap.proc.imsg", "RANAP-ELEMENTARY-PROCEDURE InitiatingMessage", FT_UINT32, BASE_DEC);
ranap_proc_sout_dissector_table = register_dissector_table("ranap.proc.sout", "RANAP-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_UINT32, BASE_DEC);
ranap_proc_uout_dissector_table = register_dissector_table("ranap.proc.uout", "RANAP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_UINT32, BASE_DEC);
ranap_proc_out_dissector_table = register_dissector_table("ranap.proc.out", "RANAP-ELEMENTARY-PROCEDURE Outcome", FT_UINT32, BASE_DEC);
nas_pdu_dissector_table = register_dissector_table("ranap.nas_pdu", "RANAP NAS PDU", FT_UINT8, BASE_DEC);
ranap_module = prefs_register_protocol(proto_ranap, proto_reg_handoff_ranap);
prefs_register_uint_preference(ranap_module, "sccp_ssn", "SCCP SSN for RANAP",
"The SCCP SubSystem Number for RANAP (default 142)", 10,
&global_ranap_sccp_ssn);
prefs_register_bool_preference(ranap_module, "dissect_rrc_container",
"Attempt to dissect RRC-Container",
"Attempt to dissect RRC message embedded in RRC-Container IE",
&glbl_dissect_container);
}
void
proto_reg_handoff_ranap(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t ranap_handle;
static gint local_ranap_sccp_ssn;
if (!initialized) {
ranap_handle = find_dissector("ranap");
rrc_s_to_trnc_handle = find_dissector("rrc.s_to_trnc_cont");
rrc_t_to_srnc_handle = find_dissector("rrc.t_to_srnc_cont");
rrc_ho_to_utran_cmd = find_dissector("rrc.irat.ho_to_utran_cmd");
initialized = TRUE;
#include "packet-ranap-dis-tab.c"
} else {
dissector_delete_uint("sccp.ssn", local_ranap_sccp_ssn, ranap_handle);
}
dissector_add_uint("sccp.ssn", global_ranap_sccp_ssn, ranap_handle);
local_ranap_sccp_ssn = global_ranap_sccp_ssn;
heur_dissector_add("sccp", dissect_sccp_ranap_heur, "RANAP over SCCP", "ranap_sccp", proto_ranap, HEURISTIC_ENABLE);
heur_dissector_add("sua", dissect_sccp_ranap_heur, "RANAP over SUA", "ranap_sua", proto_ranap, HEURISTIC_ENABLE);
}
