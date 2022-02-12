static void cf_opa_snc_dw_to_b(gchar *buf, guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH, "%u DWORDS, %u Bytes", value, value * 4);
}
static void cf_opa_snc_qw_to_b(gchar *buf, guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH, "%u QWORDS, %u Bytes", value, value * 8);
}
static int dissect_opa_snc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
gboolean isBypass = TRUE;
guint8 Direction = tvb_get_guint8(tvb, offset + 1);
guint64 RHF_PBC;
proto_item *SnC_item;
proto_tree * SnC_tree,*PBC_tree,*RHF_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Omni-Path");
col_clear(pinfo->cinfo, COL_INFO);
tree = proto_tree_get_parent_tree(tree);
SnC_item = proto_tree_add_item(tree, proto_opa_snc, tvb, offset, 16, ENC_NA);
SnC_tree = proto_item_add_subtree(SnC_item, ett_snc);
proto_tree_add_item(SnC_tree, hf_opa_snc_portnumber, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(SnC_tree, hf_opa_snc_direction, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(SnC_tree, hf_opa_snc_Reserved16, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(SnC_tree, hf_opa_snc_Reserved32, tvb, offset, 4, ENC_NA);
offset += 4;
RHF_PBC = tvb_get_letoh64(tvb, offset);
switch (Direction) {
case 0:
PBC_tree = proto_tree_add_subtree(SnC_tree, tvb, offset, 8, ett_sncpbc, NULL, "PBC - Per Buffer Control");
proto_tree_add_bitmask_list(PBC_tree, tvb, offset + 4, 4, _snc_pbc_1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_list(PBC_tree, tvb, offset, 4, _snc_pbc_2, ENC_LITTLE_ENDIAN);
isBypass = (((RHF_PBC >> 28) & 1) == 1);
break;
case 1:
RHF_tree = proto_tree_add_subtree(SnC_tree, tvb, offset, 8, ett_sncrhf, NULL, "RHF - Receive Header Flags");
proto_tree_add_bitmask_list(RHF_tree, tvb, offset + 4, 4, _snc_rhf_1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_list(RHF_tree, tvb, offset, 4, _snc_rhf_2, ENC_LITTLE_ENDIAN);
isBypass = (((RHF_PBC >> 12) & 7) == 4);
break;
case 2:
proto_tree_add_item(SnC_tree, hf_opa_snc_Reserved64, tvb, offset, 8, ENC_NA);
isBypass = FALSE;
break;
default:
isBypass = FALSE;
}
offset += 8;
if (isBypass) {
expert_add_info(pinfo, NULL, &ei_opa_snc_nobypass);
} else {
call_dissector(opa_9b_handle, tvb_new_subset_remaining(tvb, offset), pinfo, tree);
}
return tvb_captured_length(tvb);
}
void proto_register_opa_snc(void)
{
expert_module_t *expert_opa_snc;
static hf_register_info hf[] = {
{ &hf_opa_snc_direction, {
"Direction", "opa.snc.direction",
FT_UINT8, BASE_HEX, VALS(vals_opa_snc_direction), 0x0, NULL, HFILL }
},
{ &hf_opa_snc_portnumber, {
"Port Number", "opa.snc.portnumber",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_opa_snc_Reserved32, {
"Reserved (32 bits)", "opa.snc.reserved32",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_opa_snc_Reserved64, {
"Reserved (64 bits)", "opa.snc.reserved64",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_opa_snc_Reserved16, {
"Reserved (16 bits)", "opa.snc.reserved16",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_opa_snc_pbc_reserved_63_48, {
"Reserved (16 bits)", "opa.snc.pbc.reserved_63_48",
FT_UINT32, BASE_HEX, NULL, 0xFFFF0000, NULL, HFILL }
},
{ &hf_opa_snc_pbc_pbcstaticratecontrolcnt, {
"Static Rate Control Counter", "opa.snc.pbc.pbcstaticratecontrolcnt",
FT_UINT32, BASE_HEX, NULL, 0x0000FFFF, NULL, HFILL }
},
{ &hf_opa_snc_pbc_pbcintr, {
"Interrupt", "opa.snc.pbc.pbcintr",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x80000000, NULL, HFILL }
},
{ &hf_opa_snc_pbc_pbcdcinfo, {
"DC Info", "opa.snc.pbc.pbcdcinfo",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x40000000, NULL, HFILL }
},
{ &hf_opa_snc_pbc_pbctestebp, {
"Test End Bad Packet", "opa.snc.pbc.pbctestebp",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x20000000, NULL, HFILL }
},
{ &hf_opa_snc_pbc_pbcpacketbypass, {
"Packet Type", "opa.snc.pbc.pbcpacketbypass",
FT_BOOLEAN, 32, TFS(&tfs_opa_snc_pbc_isBypass), 0x10000000, NULL, HFILL }
},
{ &hf_opa_snc_pbc_pbcinserthcrc, {
"Insert Hcrc", "opa.snc.pbc.pbcinserthcrc",
FT_UINT32, BASE_HEX, VALS(vals_opa_snc_pbc_insertHcrc), 0x0C000000, NULL, HFILL }
},
{ &hf_opa_snc_pbc_pbccreditreturn, {
"Request Credit Return", "opa.snc.pbc.pbccreditreturn",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x02000000, NULL, HFILL }
},
{ &hf_opa_snc_pbc_pbcinsertbypassicrc, {
"Insert ICRC for bypass packets", "opa.snc.pbc.pbcinsertbypassicrc",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x01000000, NULL, HFILL }
},
{ &hf_opa_snc_pbc_pbctestbadicrc, {
"Insert a bad ICRC", "opa.snc.pbc.pbctestbadicrc",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00800000, NULL, HFILL }
},
{ &hf_opa_snc_pbc_pbcfecn, {
"Set FECN bit", "opa.snc.pbc.pbcfecn",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00400000, NULL, HFILL }
},
{ &hf_opa_snc_pbc_reserved_21_16, {
"Reserved (6 bits)", "opa.snc.pbc.reserved_21_16",
FT_UINT32, BASE_HEX, NULL, 0x003F0000, NULL, HFILL }
},
{ &hf_opa_snc_pbc_pbcvl, {
"VL", "opa.snc.pbc.pbcvl",
FT_UINT32, BASE_DEC, NULL, 0x0000F000, NULL, HFILL }
},
{ &hf_opa_snc_pbc_pbclengthdws, {
"pbclengthdws", "opa.snc.pbc.pbclengthdws",
FT_UINT32, BASE_CUSTOM, CF_FUNC(cf_opa_snc_dw_to_b), 0x00000FFF, NULL, HFILL }
},
{ &hf_opa_snc_rhf_icrcerr, {
"ICRC error", "opa.snc.rhf.icrcerr",
FT_BOOLEAN, 32, TFS(&tfs_error_ok), 0x80000000, NULL, HFILL }
},
{ &hf_opa_snc_rhf_reserved_62, {
"Reserved (1 bit)", "opa.snc.rhf.reserved_62",
FT_UINT32, BASE_HEX, NULL, 0x40000000, NULL, HFILL }
},
{ &hf_opa_snc_rhf_eccerr, {
"Internal memory Uncorrectable error", "opa.snc.rhf.eccerr",
FT_BOOLEAN, 32, TFS(&tfs_error_ok), 0x200000000, NULL, HFILL }
},
{ &hf_opa_snc_rhf_lenerr, {
"Length Error", "opa.snc.rhf.lenerr",
FT_BOOLEAN, 32, TFS(&tfs_error_ok), 0x10000000, NULL, HFILL }
},
{ &hf_opa_snc_rhf_tiderr, {
"TID Error", "opa.snc.rhf.tiderr",
FT_BOOLEAN, 32, TFS(&tfs_error_ok), 0x08000000, NULL, HFILL }
},
{ &hf_opa_snc_rhf_rcvtypeerr, {
"Receive Type Error", "opa.snc.rhf.rcvtypeerr",
FT_UINT32, BASE_HEX, VALS(vals_opa_snc_rhf_rcvtypeerr), 0x07000000, NULL, HFILL }
},
{ &hf_opa_snc_rhf_dcerr, {
"End Bad Packet Error", "opa.snc.rhf.dcerr",
FT_BOOLEAN, 32, TFS(&tfs_error_ok), 0x00800000, NULL, HFILL }
},
{ &hf_opa_snc_rhf_dcuncerr, {
"Uncorrectable or parity error", "opa.snc.rhf.dcuncerr",
FT_BOOLEAN, 32, TFS(&tfs_error_ok), 0x00400000, NULL, HFILL }
},
{ &hf_opa_snc_rhf_khdrlenerr, {
"KDETH Length Error", "opa.snc.rhf.khdrlenerr",
FT_BOOLEAN, 32, TFS(&tfs_error_ok), 0x00200000, NULL, HFILL }
},
{ &hf_opa_snc_rhf_hdrqoffset, {
"Receive Header Offset", "opa.snc.rhf.hdrqoffset",
FT_UINT32, BASE_CUSTOM, CF_FUNC(cf_opa_snc_dw_to_b), 0x001FF000, NULL, HFILL }
},
{ &hf_opa_snc_rhf_egroffset, {
"Eager Buffer Offset", "opa.snc.rhf.egroffset",
FT_UINT32, BASE_CUSTOM, CF_FUNC(cf_opa_snc_qw_to_b), 0x00000FFF, NULL, HFILL }
},
{ &hf_opa_snc_rhf_rcvseq, {
"Receive Sequence", "opa.snc.rhf.rcvseq",
FT_UINT32, BASE_DEC, NULL, 0xF0000000, NULL, HFILL }
},
{ &hf_opa_snc_rhf_dcinfo, {
"DC Info", "opa.snc.rhf.dcinfo",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x08000000, NULL, HFILL }
},
{ &hf_opa_snc_rhf_egrindex, {
"Eager Buffer Index", "opa.snc.rhf.egrindex",
FT_UINT32, BASE_HEX, NULL, 0x07FF0000, NULL, HFILL }
},
{ &hf_opa_snc_rhf_useegrbfr, {
"Use Eager Buffer", "opa.snc.rhf.useegrbfr",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00008000, NULL, HFILL }
},
{ &hf_opa_snc_rhf_rcvtype, {
"Packet Receive Type", "opa.snc.rhf.rcvtype",
FT_UINT32, BASE_DEC_HEX, VALS(vals_opa_snc_rhf_rcvtype), 0x00007000, NULL, HFILL }
},
{ &hf_opa_snc_rhf_pktlen, {
"Packet Length", "opa.snc.rhf.pktlen",
FT_UINT32, BASE_CUSTOM, CF_FUNC(cf_opa_snc_dw_to_b), 0x00000FFF, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_snc,
&ett_sncpbc,
&ett_sncrhf,
};
static ei_register_info ei[] = {
{ &ei_opa_snc_nobypass, {
"opa.snc.nobypass", PI_PROTOCOL, PI_WARN,
"Bypass packets not implemented in this version", EXPFILL }
}
};
proto_opa_snc = proto_register_protocol(
"Intel Omni-Path SnC - Omni-Path Snoop and Capture MetaData Header",
"OPA SnC", "opa.snc");
opa_snc_handle = register_dissector("opa.snc", dissect_opa_snc, proto_opa_snc);
proto_register_field_array(proto_opa_snc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_opa_snc = expert_register_protocol(proto_opa_snc);
expert_register_field_array(expert_opa_snc, ei, array_length(ei));
}
void proto_reg_handoff_opa_snc(void)
{
opa_9b_handle = find_dissector("opa");
dissector_add_uint("erf.types.type", ERF_TYPE_OPA_SNC, opa_snc_handle);
}
