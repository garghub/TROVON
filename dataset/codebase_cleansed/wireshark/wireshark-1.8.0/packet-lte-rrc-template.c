static void
dissect_lte_rrc_DL_CCCH(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE RRC DL_CCCH");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_DL_CCCH_Message_PDU(tvb, pinfo, lte_rrc_tree);
}
}
static void
dissect_lte_rrc_DL_DCCH(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE RRC DL_DCCH");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_DL_DCCH_Message_PDU(tvb, pinfo, lte_rrc_tree);
}
}
static void
dissect_lte_rrc_UL_CCCH(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE RRC UL_CCCH");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_UL_CCCH_Message_PDU(tvb, pinfo, lte_rrc_tree);
}
}
static void
dissect_lte_rrc_UL_DCCH(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE RRC UL_DCCH");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_UL_DCCH_Message_PDU(tvb, pinfo, lte_rrc_tree);
}
}
static void
dissect_lte_rrc_BCCH_BCH(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE RRC BCCH_BCH");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_BCCH_BCH_Message_PDU(tvb, pinfo, lte_rrc_tree);
}
}
static void
dissect_lte_rrc_BCCH_DL_SCH(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE RRC DL_SCH");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_BCCH_DL_SCH_Message_PDU(tvb, pinfo, lte_rrc_tree);
}
}
void proto_register_lte_rrc(void) {
static hf_register_info hf[] = {
#include "packet-lte-rrc-hfarr.c"
{ &hf_lte_rrc_eutra_cap_feat_group_ind_1,
{ "Indicator 1", "lte-rrc.eutra_cap_feat_group_ind_1",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_1_val), 0,
"EUTRA Feature Group Indicator 1", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_2,
{ "Indicator 2", "lte-rrc.eutra_cap_feat_group_ind_2",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_2_val), 0,
"EUTRA Feature Group Indicator 2", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_3,
{ "Indicator 3", "lte-rrc.eutra_cap_feat_group_ind_3",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_3_val), 0,
"EUTRA Feature Group Indicator 3", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_4,
{ "Indicator 4", "lte-rrc.eutra_cap_feat_group_ind_4",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_4_val), 0,
"EUTRA Feature Group Indicator 4", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_5,
{ "Indicator 5", "lte-rrc.eutra_cap_feat_group_ind_5",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_5_val), 0,
"EUTRA Feature Group Indicator 5", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_6,
{ "Indicator 6", "lte-rrc.eutra_cap_feat_group_ind_6",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_6_val), 0,
"EUTRA Feature Group Indicator 6", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_7,
{ "Indicator 7", "lte-rrc.eutra_cap_feat_group_ind_7",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_7_val), 0,
"EUTRA Feature Group Indicator 7", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_8,
{ "Indicator 8", "lte-rrc.eutra_cap_feat_group_ind_8",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_8_val), 0,
"EUTRA Feature Group Indicator 8", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_9,
{ "Indicator 9", "lte-rrc.eutra_cap_feat_group_ind_9",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_9_val), 0,
"EUTRA Feature Group Indicator 9", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_10,
{ "Indicator 10", "lte-rrc.eutra_cap_feat_group_ind_10",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_10_val), 0,
"EUTRA Feature Group Indicator 10", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_11,
{ "Indicator 11", "lte-rrc.eutra_cap_feat_group_ind_11",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_11_val), 0,
"EUTRA Feature Group Indicator 11", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_12,
{ "Indicator 12", "lte-rrc.eutra_cap_feat_group_ind_12",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_12_val), 0,
"EUTRA Feature Group Indicator 12", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_13,
{ "Indicator 13", "lte-rrc.eutra_cap_feat_group_ind_13",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_13_val), 0,
"EUTRA Feature Group Indicator", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_14,
{ "Indicator 14", "lte-rrc.eutra_cap_feat_group_ind_14",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_14_val), 0,
"EUTRA Feature Group Indicator 14", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_15,
{ "Indicator 15", "lte-rrc.eutra_cap_feat_group_ind_15",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_15_val), 0,
"EUTRA Feature Group Indicator 15", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_16,
{ "Indicator 16", "lte-rrc.eutra_cap_feat_group_ind_16",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_16_val), 0,
"EUTRA Feature Group Indicator 16", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_17,
{ "Indicator 17", "lte-rrc.eutra_cap_feat_group_ind_17",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_17_val), 0,
"EUTRA Feature Group Indicator 17", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_18,
{ "Indicator 18", "lte-rrc.eutra_cap_feat_group_ind_18",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_18_val), 0,
"EUTRA Feature Group Indicator 18", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_19,
{ "Indicator 19", "lte-rrc.eutra_cap_feat_group_ind_19",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_19_val), 0,
"EUTRA Feature Group Indicator 19", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_20,
{ "Indicator 20", "lte-rrc.eutra_cap_feat_group_ind_20",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_20_val), 0,
"EUTRA Feature Group Indicator 20", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_21,
{ "Indicator 21", "lte-rrc.eutra_cap_feat_group_ind_21",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_21_val), 0,
"EUTRA Feature Group Indicator 21", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_22,
{ "Indicator 22", "lte-rrc.eutra_cap_feat_group_ind_22",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_22_val), 0,
"EUTRA Feature Group Indicator 22", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_23,
{ "Indicator 23", "lte-rrc.eutra_cap_feat_group_ind_23",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_23_val), 0,
"EUTRA Feature Group Indicator 23", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_24,
{ "Indicator 24", "lte-rrc.eutra_cap_feat_group_ind_24",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_24_val), 0,
"EUTRA Feature Group Indicator 24", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_25,
{ "Indicator 25", "lte-rrc.eutra_cap_feat_group_ind_25",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_25_val), 0,
"EUTRA Feature Group Indicator 25", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_26,
{ "Indicator 26", "lte-rrc.eutra_cap_feat_group_ind_26",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_26_val), 0,
"EUTRA Feature Group Indicator 26", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_27,
{ "Indicator 27", "lte-rrc.eutra_cap_feat_group_ind_27",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_27_val), 0,
"EUTRA Feature Group Indicator 27", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_28,
{ "Indicator 28", "lte-rrc.eutra_cap_feat_group_ind_28",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_28_val), 0,
"EUTRA Feature Group Indicator 28", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_29,
{ "Indicator 29", "lte-rrc.eutra_cap_feat_group_ind_29",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_29_val), 0,
"EUTRA Feature Group Indicator 29", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_30,
{ "Indicator 30", "lte-rrc.eutra_cap_feat_group_ind_30",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_30_val), 0,
"EUTRA Feature Group Indicator 30", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_31,
{ "Indicator 31", "lte-rrc.eutra_cap_feat_group_ind_31",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_31_val), 0,
"EUTRA Feature Group Indicator 31", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_32,
{ "Indicator 32", "lte-rrc.eutra_cap_feat_group_ind_32",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_32_val), 0,
"EUTRA Feature Group Indicator 32", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_33,
{ "Indicator 33", "lte-rrc.eutra_cap_feat_group_ind_33",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_33_val), 0,
"EUTRA Feature Group Indicator 33", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_34,
{ "Indicator 34", "lte-rrc.eutra_cap_feat_group_ind_34",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_34_val), 0,
"EUTRA Feature Group Indicator 34", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_35,
{ "Indicator 35", "lte-rrc.eutra_cap_feat_group_ind_35",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_35_val), 0,
"EUTRA Feature Group Indicator 35", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_36,
{ "Indicator 36", "lte-rrc.eutra_cap_feat_group_ind_36",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_36_val), 0,
"EUTRA Feature Group Indicator 36", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_37,
{ "Indicator 37", "lte-rrc.eutra_cap_feat_group_ind_37",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_37_val), 0,
"EUTRA Feature Group Indicator 37", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_38,
{ "Indicator 38", "lte-rrc.eutra_cap_feat_group_ind_38",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_38_val), 0,
"EUTRA Feature Group Indicator 38", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_39,
{ "Indicator 39", "lte-rrc.eutra_cap_feat_group_ind_39",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_39_val), 0,
"EUTRA Feature Group Indicator 39", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_40,
{ "Indicator 40", "lte-rrc.eutra_cap_feat_group_ind_40",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_40_val), 0,
"EUTRA Feature Group Indicator 40", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_41,
{ "Indicator 41", "lte-rrc.eutra_cap_feat_group_ind_41",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_41_val), 0,
"EUTRA Feature Group Indicator 41", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_42,
{ "Indicator 42", "lte-rrc.eutra_cap_feat_group_ind_42",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_42_val), 0,
"EUTRA Feature Group Indicator 42", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_43,
{ "Indicator 43", "lte-rrc.eutra_cap_feat_group_ind_43",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_43_val), 0,
"EUTRA Feature Group Indicator 43", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_44,
{ "Indicator 44", "lte-rrc.eutra_cap_feat_group_ind_44",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_44_val), 0,
"EUTRA Feature Group Indicator 44", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_45,
{ "Indicator 45", "lte-rrc.eutra_cap_feat_group_ind_45",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_45_val), 0,
"EUTRA Feature Group Indicator 45", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_46,
{ "Indicator 46", "lte-rrc.eutra_cap_feat_group_ind_46",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_46_val), 0,
"EUTRA Feature Group Indicator 46", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_47,
{ "Indicator 47", "lte-rrc.eutra_cap_feat_group_ind_47",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_47_val), 0,
"EUTRA Feature Group Indicator 47", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_48,
{ "Indicator 48", "lte-rrc.eutra_cap_feat_group_ind_48",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_48_val), 0,
"EUTRA Feature Group Indicator 48", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_49,
{ "Indicator 49", "lte-rrc.eutra_cap_feat_group_ind_49",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_49_val), 0,
"EUTRA Feature Group Indicator 49", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_50,
{ "Indicator 50", "lte-rrc.eutra_cap_feat_group_ind_50",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_50_val), 0,
"EUTRA Feature Group Indicator 50", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_51,
{ "Indicator 51", "lte-rrc.eutra_cap_feat_group_ind_51",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_51_val), 0,
"EUTRA Feature Group Indicator 51", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_52,
{ "Indicator 52", "lte-rrc.eutra_cap_feat_group_ind_52",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_52_val), 0,
"EUTRA Feature Group Indicator 52", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_53,
{ "Indicator 53", "lte-rrc.eutra_cap_feat_group_ind_53",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_53_val), 0,
"EUTRA Feature Group Indicator 53", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_54,
{ "Indicator 54", "lte-rrc.eutra_cap_feat_group_ind_54",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_54_val), 0,
"EUTRA Feature Group Indicator 54", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_55,
{ "Indicator 55", "lte-rrc.eutra_cap_feat_group_ind_55",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_55_val), 0,
"EUTRA Feature Group Indicator 55", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_56,
{ "Indicator 56", "lte-rrc.eutra_cap_feat_group_ind_56",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_56_val), 0,
"EUTRA Feature Group Indicator 56", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_57,
{ "Indicator 57", "lte-rrc.eutra_cap_feat_group_ind_57",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_57_val), 0,
"EUTRA Feature Group Indicator 57", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_58,
{ "Indicator 58", "lte-rrc.eutra_cap_feat_group_ind_58",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_58_val), 0,
"EUTRA Feature Group Indicator 58", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_59,
{ "Indicator 59", "lte-rrc.eutra_cap_feat_group_ind_59",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_59_val), 0,
"EUTRA Feature Group Indicator 59", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_60,
{ "Indicator 60", "lte-rrc.eutra_cap_feat_group_ind_60",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_60_val), 0,
"EUTRA Feature Group Indicator 60", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_61,
{ "Indicator 61", "lte-rrc.eutra_cap_feat_group_ind_61",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_61_val), 0,
"EUTRA Feature Group Indicator 61", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_62,
{ "Indicator 62", "lte-rrc.eutra_cap_feat_group_ind_62",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_62_val), 0,
"EUTRA Feature Group Indicator 62", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_63,
{ "Indicator 63", "lte-rrc.eutra_cap_feat_group_ind_63",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_63_val), 0,
"EUTRA Feature Group Indicator 63", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_64,
{ "Indicator 64", "lte-rrc.eutra_cap_feat_group_ind_64",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_64_val), 0,
"EUTRA Feature Group Indicator 64", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_101,
{ "Indicator 101", "lte-rrc.eutra_cap_feat_group_ind_101",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_101_val), 0,
"EUTRA Feature Group Indicator 101", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_102,
{ "Indicator 102", "lte-rrc.eutra_cap_feat_group_ind_102",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_102_val), 0,
"EUTRA Feature Group Indicator 102", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_103,
{ "Indicator 103", "lte-rrc.eutra_cap_feat_group_ind_103",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_103_val), 0,
"EUTRA Feature Group Indicator 103", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_104,
{ "Indicator 104", "lte-rrc.eutra_cap_feat_group_ind_104",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_104_val), 0,
"EUTRA Feature Group Indicator 104", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_105,
{ "Indicator 105", "lte-rrc.eutra_cap_feat_group_ind_105",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_105_val), 0,
"EUTRA Feature Group Indicator 105", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_106,
{ "Indicator 106", "lte-rrc.eutra_cap_feat_group_ind_106",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_106_val), 0,
"EUTRA Feature Group Indicator 106", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_107,
{ "Indicator 107", "lte-rrc.eutra_cap_feat_group_ind_107",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_107_val), 0,
"EUTRA Feature Group Indicator 107", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_108,
{ "Indicator 108", "lte-rrc.eutra_cap_feat_group_ind_108",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_108_val), 0,
"EUTRA Feature Group Indicator 108", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_109,
{ "Indicator 109", "lte-rrc.eutra_cap_feat_group_ind_109",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_109_val), 0,
"EUTRA Feature Group Indicator 109", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_110,
{ "Indicator 110", "lte-rrc.eutra_cap_feat_group_ind_110",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_110_val), 0,
"EUTRA Feature Group Indicator 110", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_111,
{ "Indicator 111", "lte-rrc.eutra_cap_feat_group_ind_111",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_111_val), 0,
"EUTRA Feature Group Indicator 111", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_112,
{ "Indicator 112", "lte-rrc.eutra_cap_feat_group_ind_112",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_112_val), 0,
"EUTRA Feature Group Indicator 112", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_113,
{ "Indicator 113", "lte-rrc.eutra_cap_feat_group_ind_113",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_113_val), 0,
"EUTRA Feature Group Indicator 113", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_114,
{ "Indicator 114", "lte-rrc.eutra_cap_feat_group_ind_114",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_114_val), 0,
"EUTRA Feature Group Indicator 114", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_115,
{ "Indicator 115", "lte-rrc.eutra_cap_feat_group_ind_115",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_115_val), 0,
"EUTRA Feature Group Indicator 115", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_116,
{ "Indicator 116", "lte-rrc.eutra_cap_feat_group_ind_116",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_116_val), 0,
"EUTRA Feature Group Indicator 116", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_117,
{ "Indicator 117", "lte-rrc.eutra_cap_feat_group_ind_117",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_117_val), 0,
"EUTRA Feature Group Indicator 117", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_118,
{ "Indicator 118", "lte-rrc.eutra_cap_feat_group_ind_118",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_118_val), 0,
"EUTRA Feature Group Indicator 118", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_119,
{ "Indicator 119", "lte-rrc.eutra_cap_feat_group_ind_119",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_119_val), 0,
"EUTRA Feature Group Indicator 119", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_120,
{ "Indicator 120", "lte-rrc.eutra_cap_feat_group_ind_120",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_120_val), 0,
"EUTRA Feature Group Indicator 120", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_121,
{ "Indicator 121", "lte-rrc.eutra_cap_feat_group_ind_121",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_121_val), 0,
"EUTRA Feature Group Indicator 121", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_122,
{ "Indicator 122", "lte-rrc.eutra_cap_feat_group_ind_122",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_122_val), 0,
"EUTRA Feature Group Indicator 122", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_123,
{ "Indicator 123", "lte-rrc.eutra_cap_feat_group_ind_123",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_123_val), 0,
"EUTRA Feature Group Indicator 123", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_124,
{ "Indicator 124", "lte-rrc.eutra_cap_feat_group_ind_124",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_124_val), 0,
"EUTRA Feature Group Indicator 124", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_125,
{ "Indicator 125", "lte-rrc.eutra_cap_feat_group_ind_125",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_125_val), 0,
"EUTRA Feature Group Indicator 125", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_126,
{ "Indicator 126", "lte-rrc.eutra_cap_feat_group_ind_126",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_126_val), 0,
"EUTRA Feature Group Indicator 126", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_127,
{ "Indicator 127", "lte-rrc.eutra_cap_feat_group_ind_127",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_127_val), 0,
"EUTRA Feature Group Indicator 127", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_128,
{ "Indicator 128", "lte-rrc.eutra_cap_feat_group_ind_128",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_128_val), 0,
"EUTRA Feature Group Indicator 128", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_129,
{ "Indicator 129", "lte-rrc.eutra_cap_feat_group_ind_129",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_129_val), 0,
"EUTRA Feature Group Indicator 129", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_130,
{ "Indicator 130", "lte-rrc.eutra_cap_feat_group_ind_130",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_130_val), 0,
"EUTRA Feature Group Indicator 130", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_131,
{ "Indicator 131", "lte-rrc.eutra_cap_feat_group_ind_131",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_131_val), 0,
"EUTRA Feature Group Indicator 131", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_132,
{ "Indicator 132", "lte-rrc.eutra_cap_feat_group_ind_132",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_132_val), 0,
"EUTRA Feature Group Indicator 132", HFILL }},
};
static gint *ett[] = {
&ett_lte_rrc,
#include "packet-lte-rrc-ettarr.c"
&ett_lte_rrc_featureGroupIndicators,
&ett_lte_rrc_featureGroupIndRel9Add,
&ett_lte_rrc_featureGroupIndRel10,
&ett_lte_rrc_neighCellConfig,
&ett_lte_rrc_absTimeInfo,
};
proto_lte_rrc = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("lte_rrc.dl_ccch", dissect_lte_rrc_DL_CCCH, proto_lte_rrc);
register_dissector("lte_rrc.dl_dcch", dissect_lte_rrc_DL_DCCH, proto_lte_rrc);
register_dissector("lte_rrc.ul_ccch", dissect_lte_rrc_UL_CCCH, proto_lte_rrc);
register_dissector("lte_rrc.ul_dcch", dissect_lte_rrc_UL_DCCH, proto_lte_rrc);
register_dissector("lte_rrc.bcch_bch", dissect_lte_rrc_BCCH_BCH, proto_lte_rrc);
register_dissector("lte_rrc.bcch_dl_sch", dissect_lte_rrc_BCCH_DL_SCH, proto_lte_rrc);
proto_register_field_array(proto_lte_rrc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
#include "packet-lte-rrc-dis-reg.c"
}
void
proto_reg_handoff_lte_rrc(void)
{
static dissector_handle_t lte_rrc_dl_ccch_handle;
lte_rrc_dl_ccch_handle = find_dissector("lte_rrc.dl_ccch");
dissector_add_handle("udp.port", lte_rrc_dl_ccch_handle);
nas_eps_handle = find_dissector("nas-eps");
rrc_irat_ho_to_utran_cmd_handle = find_dissector("rrc.irat.ho_to_utran_cmd");
rrc_sys_info_cont_handle = find_dissector("rrc.sysinfo.cont");
gsm_a_dtap_handle = find_dissector("gsm_a_dtap");
gsm_rlcmac_dl_handle = find_dissector("gsm_rlcmac_dl");
}
