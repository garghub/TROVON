static int
dissect_ns_ha(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint32 offset = 0, master_state=0;
proto_item *ti;
proto_tree *ns_ha_tree;
guint32 version, state;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NS-HA");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_protocol_format(tree, proto_ns_ha, tvb, 0, -1, "NS HA Protocol");
ns_ha_tree = proto_item_add_subtree(ti, ett_nsha);
proto_tree_add_item(ns_ha_tree, hf_nsha_signature, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(ns_ha_tree, hf_nsha_version, tvb, offset, 1, ENC_LITTLE_ENDIAN, &version);
offset += 1;
proto_tree_add_item(ns_ha_tree, hf_nsha_app, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(ns_ha_tree, hf_nsha_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item_ret_uint(ns_ha_tree, hf_nsha_state, tvb, offset, 1, ENC_LITTLE_ENDIAN, &state);
offset += 1;
switch(version) {
case 10:
proto_tree_add_item(ns_ha_tree, hf_nsha_startime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item_ret_uint(ns_ha_tree, hf_nsha_masterstate, tvb, offset, 4, ENC_LITTLE_ENDIAN, &master_state);
offset += 4;
proto_tree_add_item(ns_ha_tree, hf_nsha_release, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(ns_ha_tree, tvb, offset, hf_nsha_flags, ett_nsha_flags, ha_flags, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ns_ha_tree, hf_nsha_inc, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ns_ha_tree, hf_nsha_syncstate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 96;
proto_tree_add_item(ns_ha_tree, hf_nsha_drinc, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case 8:
case 9:
proto_tree_add_item(ns_ha_tree, hf_nsha_startime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item_ret_uint(ns_ha_tree, hf_nsha_masterstate, tvb, offset, 4, ENC_LITTLE_ENDIAN, &master_state);
offset += 4;
proto_tree_add_item(ns_ha_tree, hf_nsha_inc, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ns_ha_tree, hf_nsha_syncstate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(ns_ha_tree, tvb, offset, hf_nsha_flags, ett_nsha_flags, ha_flags, ENC_LITTLE_ENDIAN);
if (version == 9) {
offset += 4;
offset += 96;
proto_tree_add_item(ns_ha_tree, hf_nsha_drinc, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
break;
case 3:
case 4:
offset += 8;
proto_tree_add_item_ret_uint(ns_ha_tree, hf_nsha_masterstate, tvb, offset, 4, ENC_LITTLE_ENDIAN, &master_state);
offset += 4;
proto_tree_add_item(ns_ha_tree, hf_nsha_inc, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
default:
break;
}
col_add_fstr(pinfo->cinfo, COL_INFO, "Node state: %s Master State: %s",
val_to_str(state, ns_ha_state_vals, "Unknown (%u)"),
val_to_str(master_state, ns_ha_masterstate_vals, "Unknown(%u)"));
return tvb_captured_length(tvb);
}
void
proto_register_ns_ha(void)
{
static hf_register_info hf_nsha[] = {
{ &hf_nsha_signature,
{ "Signature", "nstrace.ha.signature", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_nsha_version,
{ "Version", "nstrace.ha.version", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_nsha_app,
{ "App", "nstrace.ha.app", FT_UINT8, BASE_DEC, VALS(ns_ha_app_vals), 0x0,
NULL, HFILL }},
{ &hf_nsha_type,
{ "Type", "nstrace.ha.type", FT_UINT8, BASE_DEC, VALS(ns_ha_type_vals), 0x0,
NULL, HFILL }},
{ &hf_nsha_state,
{ "State", "nstrace.ha.state", FT_UINT8, BASE_DEC, VALS(ns_ha_state_vals), 0x0,
NULL, HFILL }},
{ &hf_nsha_startime,
{ "Start Time", "nstrace.ha.startime", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_nsha_masterstate,
{ "Master State", "nstrace.ha.masterstate", FT_UINT32, BASE_DEC, VALS(ns_ha_masterstate_vals), 0x0,
NULL, HFILL }},
{ &hf_nsha_release,
{ "Release", "nstrace.ha.release", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_nsha_inc,
{ "Incarnation Number", "nstrace.ha.inc", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_nsha_syncstate,
{ "Sync State", "nstrace.ha.syncstate", FT_UINT32, BASE_DEC, VALS(ns_ha_syncstate_vals), 0x0,
NULL, HFILL }},
{ &hf_nsha_drinc,
{ "DR Incarnation Number", "nstrace.ha.drinc", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_nsha_flags,
{ "Flags", "nstrace.ha.flags", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_nsha_flags_vm,
{ "Version Mismatch", "nstrace.ha.flags.versionmismatch", FT_BOOLEAN, 32, TFS(&tfs_yes_no), NSAHA_VERSION_MISMATCH,
NULL, HFILL }},
{ &hf_nsha_flags_sp,
{ "Stay Primary", "nstrace.ha.flags.stayprimary", FT_BOOLEAN, 32, TFS(&tfs_yes_no), NSAHA_STAY_PRIMARY,
NULL, HFILL }},
{ &hf_nsha_flags_propdis,
{ "Propagation Disabled", "nstrace.ha.flags.propdis", FT_BOOLEAN, 32, TFS(&tfs_yes_no), NSAHA_PROP_DISABLED,
NULL, HFILL }},
{ &hf_nsha_flags_inc,
{ "INC Enabled", "nstrace.ha.flags.inc", FT_BOOLEAN, 32, TFS(&tfs_yes_no), NSAHA_INC_STATE,
NULL, HFILL }},
{ &hf_nsha_flags_sslfail,
{ "SSL Card Failure", "nstrace.ha.flags.sslfail", FT_BOOLEAN, 32, TFS(&tfs_yes_no), NSAHA_SSLCARD_DOWN,
NULL, HFILL }},
{ &hf_nsha_flags_nossl,
{ "SSL Card Absent", "nstrace.ha.flags.nossl", FT_BOOLEAN, 32, TFS(&tfs_yes_no), NSAHA_NO_DEVICES,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_nsha,
&ett_nsha_flags,
};
proto_ns_ha = proto_register_protocol("NetScaler HA Protocol", "NetScaler HA", "nstrace.ha");
proto_register_field_array(proto_ns_ha, hf_nsha, array_length(hf_nsha));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_ns_ha(void)
{
dissector_handle_t nsha_handle;
nsha_handle = create_dissector_handle(dissect_ns_ha, proto_ns_ha);
dissector_add_for_decode_as("udp.port", nsha_handle);
}
