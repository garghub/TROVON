static void dissect_siii_mst(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *subtree;
proto_tree *subtree2;
subtree = proto_tree_add_subtree(tree, tvb, 0, 6, ett_siii_mst, NULL, "MST");
subtree2 = proto_tree_add_subtree(subtree, tvb, 0, 1, ett_siii_mst_teltype, NULL, "Telegram Type");
proto_tree_add_item(subtree2, hf_siii_mst_channel, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree2, hf_siii_mst_type, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree2, hf_siii_mst_cyclecntvalid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree2, hf_siii_mst_telno, tvb, 0, 1, ENC_LITTLE_ENDIAN);
subtree2 = proto_tree_add_subtree(subtree, tvb, 1, 1, ett_siii_mst_phase, NULL, "Phase Field");
proto_tree_add_item(subtree2, hf_siii_mst_phase, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree2, hf_siii_mst_cyclecnt, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_siii_mst_crc32, tvb, 2, 4, ENC_LITTLE_ENDIAN);
}
static void dissect_siii_mdt_hp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *subtree;
static const int * ctrl_fields[] = {
&hf_siii_mdt_hotplug_control_svc_switch,
&hf_siii_mdt_hotplug_control_param,
NULL
};
subtree = proto_tree_add_subtree(tree, tvb, 0, 8, ett_siii_mdt_hp, NULL, "Hot-Plug");
proto_tree_add_item(subtree, hf_siii_mdt_hotplug_address, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(subtree, tvb, 2, hf_siii_mdt_hp_ctrl,
ett_siii_mdt_hp_ctrl, ctrl_fields, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_siii_mdt_hp_info, tvb, 4, 4, ENC_NA);
}
static void dissect_siii_mdt_devctrl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int * ctrl_fields[] = {
&hf_siii_at_dev_control_ident,
&hf_siii_mdt_dev_control_change_topology,
&hf_siii_mdt_dev_control_top_control,
NULL
};
proto_tree_add_bitmask(tree, tvb, 0, hf_siii_mdt_dev_control,
ett_siii_mdt_devctrl, ctrl_fields, ENC_LITTLE_ENDIAN);
}
static void dissect_siii_mdt_svc(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint devno _U_)
{
proto_tree *subtree;
proto_item *ti;
static const int * svch_fields[] = {
&hf_siii_mdt_svch_dbe,
&hf_siii_mdt_svch_eot,
&hf_siii_mdt_svch_rw,
&hf_siii_mdt_svch_mhs,
NULL
};
guint16 svc_ctrl = tvb_get_letohs(tvb, 0);
guint8 svc_dbe = (svc_ctrl>>3) & 7;
proto_tree_add_bitmask(tree, tvb, 0, hf_siii_mdt_svch_ctrl,
ett_siii_mdt_svcctrl, svch_fields, ENC_LITTLE_ENDIAN);
ti = proto_tree_add_item(tree, hf_siii_mdt_svch_info, tvb, 2, 4, ENC_NA);
if (1 == svc_dbe)
{
subtree = proto_item_add_subtree(ti, ett_siii_mdt_svcinfo);
proto_tree_add_item(subtree, hf_siii_idn_code, tvb, 2, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_siii_mdt_svch_idn, tvb, 2, 4, ENC_LITTLE_ENDIAN);
}
}
static void dissect_siii_mdt_cp0(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int * version_fields[] = {
&hf_siii_mdt_version_switch_off_sercos_telegrams,
&hf_siii_mdt_version_fast_cp_switch,
&hf_siii_mdt_version_transmission_of_communication_parameters_mdt0_cp0,
&hf_siii_mdt_version_num_mdt_at_cp1_2,
&hf_siii_mdt_version_initprocvers,
NULL
};
proto_tree_add_bitmask(tree, tvb, 0, hf_siii_mdt_version,
ett_siii_mdt_version, version_fields, ENC_LITTLE_ENDIAN);
}
static void dissect_siii_mdt_cp1_2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint telno)
{
guint devstart = telno * SERCOS_SLAVE_GROUP_SIZE;
tvbuff_t *tvb_n;
guint idx;
proto_tree *subtree;
proto_tree *subtree_svc;
proto_tree *subtree_devctrl;
subtree_svc = proto_tree_add_subtree(tree, tvb, 0, SERCOS_SLAVE_GROUP_SIZE * 6, ett_siii_mdt_svc, NULL, "Service Channels");
subtree_devctrl = proto_tree_add_subtree(tree, tvb, SERCOS_SLAVE_GROUP_SIZE * 6, 512, ett_siii_mdt_svc, NULL, "Device Control");
for (idx = 0; idx < SERCOS_SLAVE_GROUP_SIZE; ++idx)
{
tvb_n = tvb_new_subset_length(tvb, 6 * idx, 6);
subtree = proto_tree_add_subtree_format(subtree_svc, tvb_n, 0, 6, ett_siii_mdt_svc_channel, NULL, "Device %u", idx + devstart);
dissect_siii_mdt_svc(tvb_n, pinfo, subtree, idx + devstart);
tvb_n = tvb_new_subset_length(tvb, SERCOS_SLAVE_GROUP_SIZE * 6 + 4 * idx, 2);
subtree = proto_tree_add_subtree_format(subtree_devctrl, tvb_n, 0, 2, ett_siii_mdt_dev_control, NULL, "Device %u", idx + devstart);
dissect_siii_mdt_devctrl(tvb_n, pinfo, subtree);
}
}
static void dissect_siii_mdt_cp3_4(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint telno)
{
if (0 == telno)
dissect_siii_mdt_hp(tvb, pinfo, tree);
proto_tree_add_item(tree, hf_siii_service_channels, tvb, 0, 0, ENC_NA);
proto_tree_add_item(tree, hf_siii_device_controls, tvb, 0, 0, ENC_NA);
}
static void dissect_siii_mdt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *subtree;
tvbuff_t *tvb_n;
guint t_phase;
guint telno;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SIII MDT");
t_phase = (tvb_get_guint8(tvb, 1)&0x8F);
telno = (tvb_get_guint8(tvb, 0) & 0xF);
if (t_phase & 0x80)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " Phase=CP?s -> CP%u",
(t_phase&0x0f));
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, " Phase=CP%u",
(t_phase&0x0f));
}
subtree = proto_tree_add_subtree_format(tree, tvb, 0, -1, ett_siii_mdt, NULL, "MDT%u", telno);
dissect_siii_mst(tvb, pinfo, subtree);
switch (t_phase)
{
case COMMUNICATION_PHASE_0:
tvb_n = tvb_new_subset_length(tvb, 6, 40);
dissect_siii_mdt_cp0(tvb_n, pinfo, subtree);
break;
case COMMUNICATION_PHASE_1:
case COMMUNICATION_PHASE_2:
tvb_n = tvb_new_subset_length(tvb, 6, 1280);
dissect_siii_mdt_cp1_2(tvb_n, pinfo, subtree, telno);
break;
case COMMUNICATION_PHASE_3:
case COMMUNICATION_PHASE_4:
tvb_n = tvb_new_subset_remaining(tvb, 6);
dissect_siii_mdt_cp3_4(tvb_n, pinfo, subtree, telno);
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_siii_cp_unknown, tvb, 6, -1);
}
}
static void dissect_siii_at_svc(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint devno _U_)
{
static const int * svch_fields[] = {
&hf_siii_at_svch_valid,
&hf_siii_at_svch_error,
&hf_siii_at_svch_busy,
&hf_siii_at_svch_ahs,
NULL
};
proto_tree_add_bitmask(tree, tvb, 0, hf_siii_at_svch_stat,
ett_siii_at_svcstat, svch_fields, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_siii_at_svch_info, tvb, 2, 4, ENC_NA);
}
static void dissect_siii_at_devstat(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int * status[] = {
&hf_siii_at_dev_status_commwarning,
&hf_siii_at_dev_status_change_topology,
&hf_siii_at_dev_status_top_status,
&hf_siii_at_dev_status_inactive_port_status,
&hf_siii_at_dev_status_errorconnection,
&hf_siii_at_dev_status_slave_valid,
&hf_siii_at_dev_status_proc_command_change,
&hf_siii_at_dev_status_parameterization_level_active,
NULL
};
proto_tree_add_bitmask(tree, tvb, 0, hf_siii_at_dev_status,
ett_siii_at_devstatus, status, ENC_LITTLE_ENDIAN);
}
static void dissect_siii_at_hp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *subtree;
static const int * status[] = {
&hf_siii_at_hotplug_status_error,
&hf_siii_at_hotplug_status_hp0_finished,
&hf_siii_at_hotplug_status_param,
NULL
};
subtree = proto_tree_add_subtree(tree, tvb, 0, 8, ett_siii_at_hp, NULL, "Hot-Plug");
proto_tree_add_item(subtree, hf_siii_at_hotplug_address, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(subtree, tvb, 2, hf_siii_at_hp_stat, ett_siii_at_hp_stat, status, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_siii_at_hp_info, tvb, 4, 4, ENC_NA);
}
static void dissect_siii_at_cp0(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint16 seqcnt;
guint16 tfield;
guint16 i;
proto_tree *subtree, *subtree2;
proto_item* ti;
subtree = proto_tree_add_subtree(tree, tvb, 0, 1024, ett_siii_recognized_devices, NULL, "Recognized Devices");
seqcnt = tvb_get_letohs(tvb, 0);
proto_tree_add_uint(subtree, hf_siii_at_cp0_num_devices, tvb, 0, 2, (MAX_SERCOS_ADDRESS & seqcnt)-1);
for (i = 1; i < MAX_SERCOS_DEVICES; ++i)
{
tfield = tvb_get_letohs(tvb, i*2);
if (tfield == 0xFFFF)
{
proto_tree_add_uint_format(subtree, hf_siii_at_cp0_sercos_address, tvb, i*2, 2, 0xFFFF, "Sercos Address %u: No Device", i);
}
else
{
ti = proto_tree_add_uint_format(subtree, hf_siii_at_cp0_sercos_address, tvb, i*2, 2, (tfield & MAX_SERCOS_ADDRESS), "Sercos Address %u: %u", i, (tfield & MAX_SERCOS_ADDRESS));
subtree2 = proto_item_add_subtree(ti, ett_siii_at_sercos_address);
proto_tree_add_item(subtree2, hf_siii_at_cp0_support_functions, tvb, i*2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree2, hf_siii_at_cp0_device_address, tvb, i*2, 2, ENC_LITTLE_ENDIAN);
}
}
}
static void dissect_siii_at_cp1_2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint telno)
{
guint devstart = telno * SERCOS_SLAVE_GROUP_SIZE;
tvbuff_t *tvb_n;
guint idx;
proto_tree *subtree;
proto_tree *subtree_svc;
proto_tree *subtree_devstat;
subtree_svc = proto_tree_add_subtree(tree, tvb, 0, SERCOS_SLAVE_GROUP_SIZE * 6, ett_siii_at_svc, NULL, "Service Channel");
subtree_devstat = proto_tree_add_subtree(tree, tvb, SERCOS_SLAVE_GROUP_SIZE * 6, 512, ett_siii_at_devstats, NULL, "Device Status");
for (idx = 0; idx < SERCOS_SLAVE_GROUP_SIZE; ++idx)
{
tvb_n = tvb_new_subset_length(tvb, 6 * idx, 6);
subtree = proto_tree_add_subtree_format(subtree_svc, tvb_n, 0, 6, ett_siii_at_svc_channel, NULL, "Device %u", idx + devstart);
dissect_siii_at_svc(tvb_n, pinfo, subtree, idx + devstart);
tvb_n = tvb_new_subset_length(tvb, SERCOS_SLAVE_GROUP_SIZE * 6 + 4 * idx, 2);
subtree = proto_tree_add_subtree_format(subtree_devstat, tvb_n, 0, 2, ett_siii_at_dev_status, NULL, "Device %u", idx + devstart);
dissect_siii_at_devstat(tvb_n, pinfo, subtree);
}
}
static void dissect_siii_at_cp3_4(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint telno)
{
if (0 == telno)
dissect_siii_at_hp(tvb, pinfo, tree);
proto_tree_add_item(tree, hf_siii_service_channels, tvb, 0, 0, ENC_NA);
proto_tree_add_item(tree, hf_siii_device_status, tvb, 0, 0, ENC_NA);
}
static void dissect_siii_at(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *subtree;
tvbuff_t *tvb_n;
guint8 phase;
guint telno;
phase = (tvb_get_guint8(tvb, 1)&0x8F);
telno = (tvb_get_guint8(tvb, 0) & 0xF);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SIII AT");
if (phase & 0x80)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " Phase=CP?s -> CP%u",
(phase&0x0f));
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, " Phase=CP%u",
(phase&0x0f));
}
subtree = proto_tree_add_subtree_format(tree, tvb, 0, -1, ett_siii_at, NULL, "AT%u", telno);
dissect_siii_mst(tvb, pinfo, subtree);
switch (phase)
{
case COMMUNICATION_PHASE_0:
tvb_n = tvb_new_subset_length(tvb, 6, 1024);
dissect_siii_at_cp0(tvb_n, pinfo, subtree);
break;
case COMMUNICATION_PHASE_1:
case COMMUNICATION_PHASE_2:
tvb_n = tvb_new_subset_length(tvb, 6, 1280);
dissect_siii_at_cp1_2(tvb_n, pinfo, subtree, telno);
break;
case COMMUNICATION_PHASE_3:
case COMMUNICATION_PHASE_4:
tvb_n = tvb_new_subset_remaining(tvb, 6);
dissect_siii_at_cp3_4(tvb_n, pinfo, subtree, telno);
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_siii_cp_unknown, tvb, 6, -1);
break;
}
}
static int
dissect_siii(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *siii_tree;
guint type;
const char *tel_ch = "?";
const char *tel_type = "?";
guint tel_no = 0;
heur_dtbl_entry_t *hdtbl_entry;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SERCOS III V1.1");
col_clear(pinfo->cinfo, COL_INFO);
if (dissector_try_heuristic(heur_subdissector_list, tvb, pinfo, tree, &hdtbl_entry, NULL))
return tvb_captured_length(tvb);
type = tvb_get_guint8(tvb, 0);
if (type & 0x80)
tel_ch = "S";
else
tel_ch = "P";
if (type & 0x40)
tel_type = "AT ";
else
tel_type = "MDT";
tel_no = type &0xF;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s%u Channel=%s", tel_type, tel_no, tel_ch);
ti = proto_tree_add_item(tree, proto_siii, tvb, 0, -1, ENC_NA);
siii_tree = proto_item_add_subtree(ti, ett_siii);
if (type & 0x40)
dissect_siii_at(tvb, pinfo, siii_tree);
else
dissect_siii_mdt(tvb, pinfo, siii_tree);
return tvb_captured_length(tvb);
}
static void
sercosiii_idn_code_format( gchar *result, guint32 svc_info )
{
g_snprintf( result, ITEM_LABEL_LENGTH, "%c-%u-%04d.%d.%d",
((0xFFFF & svc_info)>>15)?'P':'S',
(svc_info>>12)&7,
(svc_info&4095),
(svc_info>>24) & 0xFF,
(svc_info>>16) & 0xFF);
}
void
proto_register_sercosiii(void)
{
static hf_register_info hf[] = {
{ &hf_siii_mdt_version,
{ "Communication Version", "siii.mdt.version",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_siii_mdt_version_num_mdt_at_cp1_2,
{ "Number of MDTs and ATS in CP1 and CP2", "siii.mdt.version.num_mdt_at_cp1_2",
FT_UINT32, BASE_HEX, VALS(siii_mdt_version_num_mdtat_cp1_2_text), 0x30000,
NULL, HFILL }
},
{ &hf_siii_mdt_version_transmission_of_communication_parameters_mdt0_cp0,
{ "Transmission of Communication parameters", "siii.mdt.version.mdt0_cp0_transm_comm_parameter",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x100000,
NULL, HFILL }
},
{ &hf_siii_mdt_version_fast_cp_switch,
{ "Fast CP switch", "siii.mdt.version.mdt0_cp0_fast_cp_switch",
FT_BOOLEAN, 32, TFS(&siii_mdt_version_fast_cp_switch_text), 0x200000,
NULL, HFILL }
},
{ &hf_siii_mdt_version_switch_off_sercos_telegrams,
{ "Switch off Sercos III telegrams", "siii.mdt.version.mdt0_cp0_switch_off_sercos_telegram",
FT_BOOLEAN, 32, TFS(&siii_switch_off_sercos_telegram_text), 0x400000,
NULL, HFILL }
},
{ &hf_siii_mdt_version_initprocvers,
{ "Initialization Procedure Version Number", "siii.mdt.version.initprocvers",
FT_BOOLEAN, 32, TFS(&siii_mdt_version_initprocvers_text), 0xFF00,
NULL, HFILL }
},
{ &hf_siii_mdt_dev_control_top_control,
{ "Topology Control", "siii.mdt.devcontrol.topcontrol",
FT_UINT16, BASE_DEC, VALS(siii_mdt_devcontrol_topcontrol_text), 3<<(12),
NULL, HFILL }
},
{ &hf_siii_at_dev_control_ident,
{ "Identification", "siii.mdt.devcontrol.identrequest",
FT_UINT16, BASE_DEC, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_siii_mdt_dev_control_change_topology,
{ "Changing Topology", "siii.mdt.devcontrol.topologychange",
FT_UINT16, BASE_DEC, NULL, 1<<14,
NULL, HFILL }
},
{ &hf_siii_mdt_dev_control,
{ "Word", "siii.mdt.devcontrol",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_siii_at_dev_status,
{ "Word", "siii.at.devstatus",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_siii_at_dev_status_commwarning,
{ "Communication Warning", "siii.at.devstatus.commwarning",
FT_UINT16, BASE_DEC, NULL, 1<<15,
NULL, HFILL }
},
{ &hf_siii_at_cp0_support_functions,
{ "Support of requested functions", "siii.at.supfunctions",
FT_BOOLEAN, 16, TFS(&siii_at_cp0_support_functions_text), 1<<15,
NULL, HFILL }
},
{ &hf_siii_at_cp0_device_address,
{ "Sercos Address", "siii.at.sercosaddress",
FT_UINT16, BASE_DEC, NULL, MAX_SERCOS_ADDRESS,
NULL, HFILL }
},
{ &hf_siii_at_dev_status_change_topology,
{ "Topology Change", "siii.at.devstatus.topologychanged",
FT_UINT16, BASE_DEC, NULL, 1<<14,
NULL, HFILL }
},
{ &hf_siii_at_dev_status_top_status,
{ "Topology Status", "siii.at.devstatus.topstatus",
FT_UINT16, BASE_DEC, VALS(siii_at_devstatus_topstatus_text), 0x3<<(12),
NULL, HFILL }
},
{ &hf_siii_at_dev_status_inactive_port_status,
{ "Port 1 Status", "siii.at.devstatus.inactportstatus",
FT_UINT16, BASE_DEC, VALS(siii_at_devstatus_inactiveportstatus_text), 0x3<<(10),
NULL, HFILL }
},
{ &hf_siii_at_dev_status_errorconnection,
{ "Topology Status", "siii.at.devstatus.errorconnection",
FT_UINT16, BASE_DEC, VALS(siii_at_devstatus_errorconnection_text), 1<<9,
NULL, HFILL }
},
{ &hf_siii_at_dev_status_slave_valid,
{ "Slave data valid", "siii.at.devstatus.slavevalid",
FT_UINT16, BASE_DEC, NULL, 1<<8,
NULL, HFILL }
},
{ &hf_siii_at_dev_status_proc_command_change,
{ "Procedure Command Change", "siii.at.devstatus.proccmdchange",
FT_UINT16, BASE_DEC, VALS(siii_at_dev_status_proc_command_change_text), 1<<5,
NULL, HFILL }
},
{ &hf_siii_at_dev_status_parameterization_level_active,
{ "Parameterization level active", "siii.at.devstatus.paralevelactive",
FT_UINT16, BASE_DEC, NULL, 1<<4,
NULL, HFILL }
},
{ &hf_siii_mdt_svch_ctrl,
{"SvcCtrl", "siii.mdt.svch.ctrl",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_siii_at_svch_stat,
{"SvcStat", "siii.mdt.svch.stat",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_siii_mdt_svch_info,
{"Svc Info", "siii.mdt.svch.info",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_siii_at_svch_info,
{"Svc Info", "siii.at.svch.info",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_siii_mdt_svch_idn,
{"IDN", "siii.mdt.svch.idn",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &siii_mdt_idn_text_ext, 0,
NULL, HFILL }
},
{ &hf_siii_mdt_svch_dbe,
{ "Data block element", "siii.mdt.svch.dbe",
FT_UINT16, BASE_DEC, VALS(siii_mdt_svch_dbe_text), 0x38,
NULL, HFILL }
},
{ &hf_siii_mdt_svch_eot,
{"End of element transmission", "siii.mdt.svch.eot",
FT_BOOLEAN, 16, TFS(&siii_mdt_svch_eot_text), 0x04,
NULL, HFILL }
},
{ &hf_siii_mdt_svch_rw,
{"Read/Write", "siii.mdt.svch.rw",
FT_BOOLEAN, 16, TFS(&siii_mdt_svch_rw_text), 0x02,
NULL, HFILL }
},
{ &hf_siii_mdt_svch_mhs,
{"Master Handshake", "siii.mdt.svch.mhs",
FT_UINT16, BASE_DEC, NULL, 0x01,
NULL, HFILL }
},
{ &hf_siii_at_svch_valid,
{ "SVC process", "siii.mdt.svch.proc",
FT_BOOLEAN, 16, TFS(&tfs_valid_not_valid), 0x08,
NULL, HFILL }
},
{ &hf_siii_at_svch_error,
{"SVC Error", "siii.mdt.svch.error",
FT_BOOLEAN, 16, TFS(&siii_at_svch_error_text), 0x04,
NULL, HFILL }
},
{ &hf_siii_at_svch_busy,
{"Busy", "siii.mdt.svch.busy",
FT_BOOLEAN, 16, TFS(&siii_at_svch_busy_text), 0x02,
NULL, HFILL }
},
{ &hf_siii_at_svch_ahs,
{"Handshake", "siii.at.svch.ahs",
FT_UINT16, BASE_DEC, NULL, 0x01,
NULL, HFILL }
},
#if 0
{ &hf_siii_svch_data_telofs_telno,
{"Telegram Number", "siii.mdt.svch.data.telassign.telno",
FT_UINT16, BASE_DEC, NULL, 0xF000,
NULL, HFILL }
},
#endif
#if 0
{ &hf_siii_svch_data_telofs_mdt_at,
{"Telegram Type", "siii.mdt.svch.data.telassign.mdt_at",
FT_UINT16, BASE_DEC, VALS(siii_svch_data_mdt_at_text), 0x0800,
NULL, HFILL }
},
#endif
#if 0
{ &hf_siii_svch_data_telofs_offset,
{"Telegram Offset", "siii.mdt.svch.data.telassign.offset",
FT_UINT16, BASE_DEC, NULL, 0x07FF,
NULL, HFILL }
},
#endif
#if 0
{ &hf_siii_svch_data_proccmd_proccmdexec,
{"Procedure Command Execution", "siii.mdt.svch.data.proccmd.interrupt",
FT_UINT16, BASE_DEC, VALS(siii_svch_data_proccmd_proccmdexec_text), 0x0002,
NULL, HFILL }
},
#endif
#if 0
{ &hf_siii_svch_data_proccmd_proccmd,
{"Procedure Command", "siii.mdt.svch.data.proccmd.set",
FT_UINT16, BASE_DEC, VALS(siii_svch_data_proccmd_proccmd_text), 0x0001,
NULL, HFILL }
},
#endif
{ &hf_siii_mst_channel,
{ "Channel", "siii.channel",
FT_UINT8, BASE_DEC, VALS(siii_mst_channel_text), 0x80,
NULL, HFILL }
},
{ &hf_siii_mst_type,
{ "Telegram Type" , "siii.type",
FT_UINT8, BASE_DEC, VALS(siii_mst_type_text), 0x40,
NULL, HFILL }
},
{ &hf_siii_mst_cyclecntvalid,
{ "Cycle Count Valid", "siii.cyclecntvalid",
FT_BOOLEAN, 8, TFS(&tfs_valid_invalid), 0x20,
NULL, HFILL }
},
{ &hf_siii_mst_telno,
{ "Telegram Number", "siii.telno",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_siii_mst_phase,
{ "Phase", "siii.mst.phase",
FT_UINT8, BASE_HEX, VALS(siii_mst_phase_text), 0x8F,
NULL, HFILL }
},
{ &hf_siii_mst_cyclecnt,
{ "Cycle Cnt", "siii.mst.cyclecnt",
FT_UINT8, BASE_DEC, NULL, 0x70,
NULL, HFILL }
},
{ &hf_siii_mst_crc32,
{ "CRC32", "siii.mst.crc32",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_siii_mdt_hotplug_address,
{"Sercos address", "siii.mdt.hp.sercosaddress",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_siii_mdt_hp_ctrl,
{"HP control", "siii.mdt.hp.ctrl",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_siii_mdt_hp_info,
{"HP info", "siii.mdt.hp.info",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_siii_at_hotplug_address,
{"Sercos address", "siii.at.hp.sercosaddress",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_siii_at_hp_stat,
{"HP status", "siii.mdt.hp.stat",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_siii_at_hp_info,
{"HP info", "siii.at.hp.info",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_siii_mdt_hotplug_control_param,
{"Parameter", "siii.mdt.hp.parameter",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &siii_mdt_hotplug_control_functioncode_text_ext, 0xFF,
NULL, HFILL }
},
{ &hf_siii_mdt_hotplug_control_svc_switch,
{"Switch to SVC", "siii.mdt.hp.switch",
FT_UINT16, BASE_DEC, VALS(siii_mdt_hotplug_control_svc_switch_text), 0x100,
NULL, HFILL }
},
{ &hf_siii_at_hotplug_status_param,
{"Parameter Received", "siii.at.hp.parameter",
FT_UINT16, BASE_DEC, VALS(siii_mdt_hotplug_status_ackcode_text), 0xFF,
NULL, HFILL }
},
{ &hf_siii_at_hotplug_status_hp0_finished,
{"HP/SVC", "siii.at.hp.hp0_finished",
FT_UINT16, BASE_DEC, NULL, 0x100,
NULL, HFILL }
},
{ &hf_siii_at_hotplug_status_error,
{"Error", "siii.at.hp.error",
FT_UINT16, BASE_DEC, VALS(siii_at_hotplug_status_error_text), 0x200,
NULL, HFILL }
},
{ &hf_siii_service_channels,
{"Service Channels", "siii.service_channels",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_siii_device_controls,
{"Device Controls", "siii.device_controls",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_siii_device_status,
{"Device Status", "siii.device_status",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_siii_idn_code,
{"IDN code", "siii.idn_code",
FT_UINT32, BASE_CUSTOM, CF_FUNC(sercosiii_idn_code_format), 0x0,
NULL, HFILL }
},
{ &hf_siii_at_cp0_num_devices,
{"Number of Devices", "siii.at.cp0.num_devices",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_siii_at_cp0_sercos_address,
{"Sercos Address", "siii.at.cp0.sercos_address",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_siii,
&ett_siii_header,
&ett_siii_mdt,
&ett_siii_mdt_version,
&ett_siii_mdt_svc,
&ett_siii_mdt_devctrls,
&ett_siii_mdt_svc_channel,
&ett_siii_mdt_dev_control,
&ett_siii_at,
&ett_siii_at_svc,
&ett_siii_at_sercos_address,
&ett_siii_at_devstats,
&ett_siii_at_svc_channel,
&ett_siii_at_dev_status,
&ett_siii_mdt_devctrl,
&ett_siii_at_devstatus,
&ett_siii_at_sercosaddress,
&ett_siii_mdt_svcctrl,
&ett_siii_mdt_svcinfo,
&ett_siii_at_svcstat,
&ett_siii_at_svcinfo,
&ett_siii_mdt_svch_data_error_info,
&ett_siii_mdt_svch_data,
&ett_siii_mst,
&ett_siii_mst_teltype,
&ett_siii_mst_phase,
&ett_siii_mdt_hp,
&ett_siii_at_hp,
&ett_siii_mdt_hp_ctrl,
&ett_siii_mdt_hp_info,
&ett_siii_at_hp_stat,
&ett_siii_at_hp_info,
&ett_siii_recognized_devices
};
static ei_register_info ei[] = {
{ &ei_siii_cp_unknown, { "siii.cp_unknown", PI_PROTOCOL, PI_WARN, "CP is unknown", EXPFILL }},
};
expert_module_t* expert_siii;
proto_siii = proto_register_protocol("SERCOS III V1.1",
"SERCOS III V1.1", "siii");
register_dissector("sercosiii", dissect_siii, proto_siii);
heur_subdissector_list = register_heur_dissector_list("sercosiii", proto_siii);
proto_register_field_array(proto_siii, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_siii = expert_register_protocol(proto_siii);
expert_register_field_array(expert_siii, ei, array_length(ei));
}
void
proto_reg_handoff_sercosiii(void)
{
dissector_handle_t siii_handle;
siii_handle = create_dissector_handle(dissect_siii, proto_siii);
dissector_add_uint("ethertype", ETHERTYPE_SERCOS, siii_handle);
}
