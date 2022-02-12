static void
dissect_rrc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *rrc_item = NULL;
proto_tree *rrc_tree = NULL;
struct rrc_info *rrcinf;
top_tree = tree;
rrcinf = p_get_proto_data(pinfo->fd, proto_rrc);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RRC");
rrc_item = proto_tree_add_item(tree, proto_rrc, tvb, 0, -1, ENC_NA);
rrc_tree = proto_item_add_subtree(rrc_item, ett_rrc);
if (rrcinf) {
switch (rrcinf->msgtype[pinfo->fd->subnum]) {
case RRC_MESSAGE_TYPE_PCCH:
call_dissector(rrc_pcch_handle, tvb, pinfo, rrc_tree);
break;
case RRC_MESSAGE_TYPE_UL_CCCH:
call_dissector(rrc_ul_ccch_handle, tvb, pinfo, rrc_tree);
break;
case RRC_MESSAGE_TYPE_DL_CCCH:
call_dissector(rrc_dl_ccch_handle, tvb, pinfo, rrc_tree);
break;
case RRC_MESSAGE_TYPE_UL_DCCH:
call_dissector(rrc_ul_dcch_handle, tvb, pinfo, rrc_tree);
break;
case RRC_MESSAGE_TYPE_DL_DCCH:
call_dissector(rrc_dl_dcch_handle, tvb, pinfo, rrc_tree);
break;
default:
;
}
}
}
void proto_register_rrc(void) {
static hf_register_info hf[] = {
#include "packet-rrc-hfarr.c"
{ &hf_test,
{ "RAB Test", "rrc.RAB.test",
FT_UINT8, BASE_DEC, NULL, 0,
"rrc.RAB_Info_r6", HFILL }},
{ &hf_rrc_eutra_feat_group_ind_1,
{ "Indicator 1", "rrc.eutra_feat_group_ind_1",
FT_BOOLEAN, BASE_NONE, TFS(&rrc_eutra_feat_group_ind_1_val), 0,
"EUTRA Feature Group Indicator 1", HFILL }},
{ &hf_rrc_eutra_feat_group_ind_2,
{ "Indicator 2", "rrc.eutra_feat_group_ind_2",
FT_BOOLEAN, BASE_NONE, TFS(&rrc_eutra_feat_group_ind_2_val), 0,
"EUTRA Feature Group Indicator 2", HFILL }},
{ &hf_rrc_eutra_feat_group_ind_3,
{ "Indicator 3", "rrc.eutra_feat_group_ind_3",
FT_BOOLEAN, BASE_NONE, TFS(&rrc_eutra_feat_group_ind_3_val), 0,
"EUTRA Feature Group Indicator 3", HFILL }},
{ &hf_rrc_eutra_feat_group_ind_4,
{ "Indicator 4", "rrc.eutra_feat_group_ind_4",
FT_BOOLEAN, BASE_NONE, TFS(&rrc_eutra_feat_group_ind_4_val), 0,
"EUTRA Feature Group Indicator 4", HFILL }},
};
static gint *ett[] = {
&ett_rrc,
#include "packet-rrc-ettarr.c"
&ett_rrc_eutraFeatureGroupIndicators,
&ett_rrc_cn_CommonGSM_MAP_NAS_SysInfo,
};
proto_rrc = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_rrc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("rrc", dissect_rrc, proto_rrc);
#include "packet-rrc-dis-reg.c"
}
void
proto_reg_handoff_rrc(void)
{
gsm_a_dtap_handle = find_dissector("gsm_a_dtap");
rrc_pcch_handle = find_dissector("rrc.pcch");
rrc_ul_ccch_handle = find_dissector("rrc.ul.ccch");
rrc_dl_ccch_handle = find_dissector("rrc.dl.ccch");
rrc_ul_dcch_handle = find_dissector("rrc.ul.dcch");
rrc_dl_dcch_handle = find_dissector("rrc.dl.dcch");
rrc_ue_radio_access_cap_info_handle = find_dissector("rrc.ue_radio_access_cap_info");
rrc_dl_dcch_handle = find_dissector("rrc.dl.dcch");
lte_rrc_ue_eutra_cap_handle = find_dissector("lte-rrc.ue_eutra_cap");
lte_rrc_dl_dcch_handle = find_dissector("lte-rrc.dl.dcch");
}
