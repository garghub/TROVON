static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(lppa_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(lppa_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(lppa_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(lppa_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
void proto_register_lppa(void) {
static hf_register_info hf[] = {
#include "packet-lppa-hfarr.c"
};
static gint *ett[] = {
&ett_lppa,
#include "packet-lppa-ettarr.c"
};
proto_lppa = proto_register_protocol(PNAME, PSNAME, PFNAME);
new_register_dissector("lppa", dissect_LPPA_PDU_PDU, proto_lppa);
proto_register_field_array(proto_lppa, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
lppa_ies_dissector_table = register_dissector_table("lppa.ies", "LPPA-PROTOCOL-IES", FT_UINT32, BASE_DEC);
lppa_proc_imsg_dissector_table = register_dissector_table("lppa.proc.imsg", "LPPA-ELEMENTARY-PROCEDURE InitiatingMessage", FT_UINT32, BASE_DEC);
lppa_proc_sout_dissector_table = register_dissector_table("lppa.proc.sout", "LPPA-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_UINT32, BASE_DEC);
lppa_proc_uout_dissector_table = register_dissector_table("lppa.proc.uout", "LPPA-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_UINT32, BASE_DEC);
}
void
proto_reg_handoff_lppa(void)
{
#include "packet-lppa-dis-tab.c"
}
