void dissect_mac_mgmt_msg_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, message_type;
dissector_handle_t mgt_msg_handle;
proto_item *parent_item = NULL;
proto_item *message_item = NULL;
proto_tree *message_tree = NULL;
{
tvb_len = tvb_reported_length(tvb);
if(!tvb_len)
{
proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "Error: Mac payload tvb is empty ! (%u bytes)", tvb_len);
return;
}
message_type = tvb_get_guint8(tvb, offset);
if(message_type < MAC_MGMT_MSG_TYPE_MAX)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", mgt_msg_abbrv[message_type]);
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, "Unknown message type,");
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "Unknown message type: %u (%u bytes)", message_type, tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
return;
}
parent_item = proto_tree_get_parent(tree);
proto_item_append_text(parent_item, ", %s", mgt_msg_abbrv[message_type]);
switch (message_type)
{
case MAC_MGMT_MSG_UCD:
dissect_mac_mgmt_msg_ucd_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_DCD:
dissect_mac_mgmt_msg_dcd_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_DL_MAP:
dissect_mac_mgmt_msg_dlmap_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_UL_MAP:
dissect_mac_mgmt_msg_ulmap_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_RNG_REQ:
dissect_mac_mgmt_msg_rng_req_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_RNG_RSP:
dissect_mac_mgmt_msg_rng_rsp_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_REG_REQ:
dissect_mac_mgmt_msg_reg_req_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_REG_RSP:
dissect_mac_mgmt_msg_reg_rsp_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_PKM_REQ:
dissect_mac_mgmt_msg_pkm_req_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_PKM_RSP:
dissect_mac_mgmt_msg_pkm_rsp_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_DSA_REQ:
dissect_mac_mgmt_msg_dsa_req_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_DSA_RSP:
dissect_mac_mgmt_msg_dsa_rsp_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_DSA_ACK:
dissect_mac_mgmt_msg_dsa_ack_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_DSC_REQ:
dissect_mac_mgmt_msg_dsc_req_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_DSC_RSP:
dissect_mac_mgmt_msg_dsc_rsp_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_DSC_ACK:
dissect_mac_mgmt_msg_dsc_ack_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_DSD_REQ:
dissect_mac_mgmt_msg_dsd_req_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_DSD_RSP:
dissect_mac_mgmt_msg_dsd_rsp_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_MCA_REQ:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mca_req_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MCA_RSP:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mca_rsp_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_DBPC_REQ:
mgt_msg_handle = find_dissector("mac_mgmt_msg_dbpc_req_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_DBPC_RSP:
mgt_msg_handle = find_dissector("mac_mgmt_msg_dbpc_rsp_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_RES_CMD:
dissect_mac_mgmt_msg_res_cmd_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_SBC_REQ:
dissect_mac_mgmt_msg_sbc_req_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_SBC_RSP:
dissect_mac_mgmt_msg_sbc_rsp_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_CLK_CMP:
dissect_mac_mgmt_msg_clk_cmp_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_DREG_CMD:
dissect_mac_mgmt_msg_dreg_cmd_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_DSX_RVD:
dissect_mac_mgmt_msg_dsx_rvd_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_TFTP_CPLT:
mgt_msg_handle = find_dissector("mac_mgmt_msg_tftp_cplt_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_TFTP_RSP:
mgt_msg_handle = find_dissector("mac_mgmt_msg_tftp_rsp_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_ARQ_FEEDBACK:
dissect_mac_mgmt_msg_arq_feedback_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_ARQ_DISCARD:
dissect_mac_mgmt_msg_arq_discard_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_ARQ_RESET:
dissect_mac_mgmt_msg_arq_reset_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_REP_REQ:
dissect_mac_mgmt_msg_rep_req_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_REP_RSP:
dissect_mac_mgmt_msg_rep_rsp_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_FPC:
dissect_mac_mgmt_msg_fpc_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_MSH_NCFG:
mgt_msg_handle = find_dissector("mac_mgmt_msg_ncfg_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MSH_NENT:
mgt_msg_handle = find_dissector("mac_mgmt_msg_nent_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MSH_DSCH:
mgt_msg_handle = find_dissector("mac_mgmt_msg_dsch_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MSH_CSCH:
mgt_msg_handle = find_dissector("mac_mgmt_msg_csch_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MSH_CSCF:
mgt_msg_handle = find_dissector("mac_mgmt_msg_cscf_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_AAS_FBCK_REQ:
dissect_mac_mgmt_msg_aas_fbck_req_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_AAS_FBCK_RSP:
dissect_mac_mgmt_msg_aas_fbck_rsp_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_AAS_BEAM_SELECT:
dissect_mac_mgmt_msg_aas_beam_select_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_AAS_BEAM_REQ:
mgt_msg_handle = find_dissector("mac_mgmt_msg_aas_beam_req_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_AAS_BEAM_RSP:
mgt_msg_handle = find_dissector("mac_mgmt_msg_aas_beam_rsp_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_DREG_REQ:
dissect_mac_mgmt_msg_dreg_req_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_MOB_SLP_REQ:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mob_slp_req_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MOB_SLP_RSP:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mob_slp_rsp_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MOB_TRF_IND:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mob_trf_ind_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MOB_NBR_ADV:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mob_nbr_adv_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MOB_SCN_REQ:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mob_scn_req_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MOB_SCN_RSP:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mob_scn_rsp_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MOB_BSHO_REQ:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mob_bsho_req_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MOB_MSHO_REQ:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mob_msho_req_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MOB_BSHO_RSP:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mob_bsho_rsp_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MOB_HO_IND:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mob_ho_ind_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MOB_SCN_REP:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mob_scn_rep_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MOB_PAG_ADV:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mob_pag_adv_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_MBS_MAP:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mbs_map_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
case MAC_MGMT_MSG_PMC_REQ:
dissect_mac_mgmt_msg_pmc_req_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_PMC_RSP:
dissect_mac_mgmt_msg_pmc_rsp_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_PRC_LT_CTRL:
dissect_mac_mgmt_msg_prc_lt_ctrl_decoder(tvb, pinfo, tree);
break;
case MAC_MGMT_MSG_MOB_ASC_REP:
mgt_msg_handle = find_dissector("mac_mgmt_msg_mob_asc_rep_handler");
if(mgt_msg_handle)
call_dissector(mgt_msg_handle, tvb, pinfo, tree);
else
{
message_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_decoder, tvb, offset, tvb_len, "%s (%u bytes)", mgt_msg_abbrv[message_type], tvb_len);
message_tree = proto_item_add_subtree(message_item, ett_mac_mgmt_msg_decoder);
proto_tree_add_item(message_tree, hf_mac_mgmt_msg_values, tvb, offset, tvb_len, ENC_NA);
}
break;
default:
proto_tree_add_item(tree, hf_mac_mgmt_msg_unknown_type, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
}
}
void proto_register_mac_mgmt_msg(void)
{
static hf_register_info hf[] =
{
{
&hf_mac_mgmt_msg_values,
{
"Values", "wmx.values",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_mgmt_msg_unknown_type,
{
"Unknown MAC Message Type", "wmx.unknown_type",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_mac_mgmt_msg_decoder,
};
proto_mac_mgmt_msg_decoder = proto_wimax;
#if 0
proto_mac_mgmt_msg_decoder = proto_register_protocol (
"WiMax MAC Management Message",
"MGMT MSG",
"wmx.mgmtmsg"
);
#endif
proto_register_field_array(proto_mac_mgmt_msg_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("wmx_mac_mgmt_msg_decoder", dissect_mac_mgmt_msg_decoder,
proto_mac_mgmt_msg_decoder);
proto_register_mac_mgmt_msg_dcd();
proto_register_mac_mgmt_msg_ucd();
proto_register_mac_mgmt_msg_dlmap();
proto_register_mac_mgmt_msg_ulmap();
proto_register_mac_mgmt_msg_rng_req();
proto_register_mac_mgmt_msg_rng_rsp();
proto_register_mac_mgmt_msg_reg_req();
proto_register_mac_mgmt_msg_reg_rsp();
proto_register_mac_mgmt_msg_dsa();
proto_register_mac_mgmt_msg_dsc();
proto_register_mac_mgmt_msg_dsd();
proto_register_mac_mgmt_msg_arq_feedback();
proto_register_mac_mgmt_msg_arq_discard();
proto_register_mac_mgmt_msg_arq_reset();
proto_register_mac_mgmt_msg_dreg_req();
proto_register_mac_mgmt_msg_dreg_cmd();
proto_register_mac_mgmt_msg_fpc();
proto_register_mac_mgmt_msg_sbc();
proto_register_mac_mgmt_msg_pkm();
proto_register_mac_mgmt_msg_pmc_req();
proto_register_mac_mgmt_msg_pmc_rsp();
proto_register_mac_mgmt_msg_prc_lt_ctrl();
proto_register_mac_mgmt_msg_aas_fbck();
proto_register_mac_mgmt_msg_aas_beam();
proto_register_mac_mgmt_msg_res_cmd();
proto_register_mac_mgmt_msg_rep();
proto_register_mac_mgmt_msg_clk_cmp();
proto_register_mac_mgmt_msg_dsx_rvd();
proto_register_wimax_utility_decoders();
}
