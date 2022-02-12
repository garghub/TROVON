static void
dissect_tte_pcf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *tte_pcf_root_item;
proto_tree *tte_pcf_tree;
guint8 sync_priority = 0;
guint8 sync_domain = 0;
if (tvb_length(tvb) < TTE_PCF_LENGTH )
{
return;
}
sync_priority = tvb_get_guint8(tvb, TTE_PCF_IC_LENGTH+TTE_PCF_MN_LENGTH+
TTE_PCF_RES0_LENGTH);
sync_domain = tvb_get_guint8(tvb, TTE_PCF_IC_LENGTH+TTE_PCF_MN_LENGTH+
TTE_PCF_RES0_LENGTH+TTE_PCF_SP_LENGTH);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PCF");
col_add_fstr(pinfo->cinfo, COL_INFO,
"Sync Domain: 0x%02X Sync Priority: 0x%02X",
sync_domain, sync_priority);
if (tree) {
tte_pcf_root_item = proto_tree_add_item(tree, proto_tte_pcf, tvb, 0,
TTE_PCF_LENGTH, ENC_NA);
tte_pcf_tree = proto_item_add_subtree(tte_pcf_root_item, ett_tte_pcf);
proto_tree_add_item(tte_pcf_tree,
hf_tte_pcf_ic, tvb, 0, TTE_PCF_IC_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(tte_pcf_tree,
hf_tte_pcf_mn, tvb, TTE_PCF_IC_LENGTH, TTE_PCF_MN_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(tte_pcf_tree,
hf_tte_pcf_sp, tvb, TTE_PCF_IC_LENGTH+TTE_PCF_MN_LENGTH+
TTE_PCF_RES0_LENGTH, TTE_PCF_SP_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(tte_pcf_tree,
hf_tte_pcf_sd, tvb, TTE_PCF_IC_LENGTH+TTE_PCF_MN_LENGTH+
TTE_PCF_RES0_LENGTH+TTE_PCF_SP_LENGTH, TTE_PCF_SD_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(tte_pcf_tree,
hf_tte_pcf_type, tvb, TTE_PCF_IC_LENGTH+TTE_PCF_MN_LENGTH+
TTE_PCF_RES0_LENGTH+TTE_PCF_SP_LENGTH+TTE_PCF_SD_LENGTH,
TTE_PCF_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(tte_pcf_tree,
hf_tte_pcf_tc, tvb, TTE_PCF_IC_LENGTH+TTE_PCF_MN_LENGTH+
TTE_PCF_RES0_LENGTH+TTE_PCF_SP_LENGTH+TTE_PCF_SD_LENGTH+
TTE_PCF_TYPE_LENGTH+TTE_PCF_RES1_LENGTH, TTE_PCF_TC_LENGTH, ENC_BIG_ENDIAN);
}
}
void
proto_register_tte_pcf(void)
{
static hf_register_info hf[] = {
#if 0
{ &hf_tte_pcf,
{ "Protocol Control Frame", "tte.pcf",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_tte_pcf_ic,
{ "Integration Cycle", "tte.pcf.ic",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tte_pcf_mn,
{ "Membership New", "tte.pcf.mn",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_tte_pcf_res0,
{ "Reserved 0", "tte.pcf.res0",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_tte_pcf_sp,
{ "Sync Priority", "tte.pcf.sp",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tte_pcf_sd,
{ "Sync Domain", "tte.pcf.sd",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tte_pcf_type,
{ "Type", "tte.pcf.type",
FT_UINT8, BASE_HEX, VALS(pcf_type_str_vals), 0x0F,
NULL, HFILL }
},
#if 0
{ &hf_tte_pcf_res1,
{ "Reserved 1", "tte.pcf.res1",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_tte_pcf_tc,
{ "Transparent Clock", "tte.pcf.tc",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_tte_pcf
};
proto_tte_pcf = proto_register_protocol("TTEthernet Protocol Control Frame",
"TTE PCF", "tte_pcf");
proto_register_field_array(proto_tte_pcf, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("tte_pcf", dissect_tte_pcf, proto_tte_pcf);
}
void
proto_reg_handoff_tte_pcf(void)
{
dissector_handle_t tte_pcf_handle;
tte_pcf_handle = find_dissector("tte_pcf");
dissector_add_uint("ethertype", ETHERTYPE_TTE_PCF, tte_pcf_handle);
}
