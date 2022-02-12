guint get_service_type( void )
{
return scheduling_service_type;
}
static void set_service_type( guint set_to )
{
if( seen_a_service_type == 0 ){
scheduling_service_type = set_to;
seen_a_service_type = 1;
}
}
void proto_register_wimax_utility_decoders(void)
{
static hf_register_info hf_sfe[] =
{
{
&hf_sfe_sf_id,
{"Service Flow ID", "wmx.sfe.sf_id", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_cid,
{"CID", "wmx.sfe.cid", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_service_class_name,
{"Service Class Name", "wmx.sfe.service_class_name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_mbs_service,
{"MBS Service", "wmx.sfe.mbs_service", FT_UINT8, BASE_DEC, VALS(vals_mbs_service), 0x0, NULL, HFILL}
},
{
&hf_sfe_qos_params_set,
{"QoS Parameter Set Type", "wmx.sfe.qos_params_set", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_set_provisioned,
{"Provisioned Set", "wmx.sfe.qos_params_set.provisioned", FT_BOOLEAN, 8, NULL, SFE_QOS_PARAMS_SET_PROVISIONED_SET, NULL, HFILL}
},
{
&hf_sfe_set_admitted,
{"Admitted Set", "wmx.sfe.qos_params_set.admitted", FT_BOOLEAN, 8, NULL, SFE_QOS_PARAMS_SET_ADMITTED_SET, NULL, HFILL}
},
{
&hf_sfe_set_active,
{"Active Set", "wmx.sfe.qos_params_set.active", FT_BOOLEAN, 8, NULL, SFE_QOS_PARAMS_SET_ACTIVE_SET, NULL, HFILL}
},
{
&hf_sfe_set_rsvd,
{"Reserved", "wmx.sfe.qos_params_set.rsvd", FT_UINT8, BASE_HEX, NULL, SFE_QOS_PARAMS_SET_RESERVED, NULL, HFILL}
},
{
&hf_sfe_traffic_priority,
{"Traffic Priority", "wmx.sfe.traffic_priority", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_max_str,
{"Maximum Sustained Traffic Rate", "wmx.sfe.msr", FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &wimax_units_bit_sec, 0x0, NULL, HFILL}
},
{
&hf_sfe_max_traffic_burst,
{"Maximum Traffic Burst", "wmx.sfe.max_traffic_burst", FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &wimax_units_byte_bytes, 0x0, NULL, HFILL}
},
{
&hf_sfe_min_rtr,
{"Minimum Reserved Traffic Rate", "wmx.sfe.mrr", FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &wimax_units_bit_sec, 0x0, NULL, HFILL}
},
{
&hf_sfe_reserved_10,
{"Reserved", "wmx.sfe.reserved_10", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
#if 0
{
&hf_sfe_mtr,
{"Minimum tolerable traffic rate", "wmx.sfe.mtr", FT_UINT32, BASE_HEX, NULL, 0x0, "", HFILL}
},
#endif
{
&hf_sfe_ul_grant_scheduling,
{"Uplink Grant Scheduling Type", "wmx.sfe.uplink_grant_scheduling", FT_UINT8, BASE_DEC, VALS(vals_ul_grant_scheduling), 0x0, NULL, HFILL}
},
{
&hf_sfe_req_tx_policy,
{"Request/Transmission Policy", "wmx.sfe.req_tx_policy", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_policy_broadcast_bwr,
{"The Service Flow Shall Not Use Broadcast Bandwidth Request Opportunities", "wmx.sfe.policy.broadcast_bwr", FT_BOOLEAN, 8, NULL, SFE_REQ_TX_POLICY_BROADCAST_BWR, NULL, HFILL}
},
{
&hf_sfe_policy_multicast_bwr,
{"The Service Flow Shall Not Use Multicast Bandwidth Request Opportunities", "wmx.sfe.policy.bit1", FT_BOOLEAN, 8, NULL, SFE_REQ_TX_POLICY_MULTICAST_BWR, NULL, HFILL}
},
{
&hf_sfe_policy_piggyback,
{"The Service Flow Shall Not Piggyback Requests With Data", "wmx.sfe.policy.piggyback", FT_BOOLEAN, 8, NULL, SFE_REQ_TX_POLICY_PIGGYBACK, NULL, HFILL}
},
{
&hf_sfe_policy_fragment,
{"The Service Flow Shall Not Fragment Data", "wmx.sfe.policy.fragment", FT_BOOLEAN, 8, NULL, SFE_REQ_TX_POLICY_FRAGMENT_DATA, NULL, HFILL}
},
{
&hf_sfe_policy_headers,
{"The Service Flow Shall Not Suppress Payload Headers", "wmx.sfe.policy.headers", FT_BOOLEAN, 8, NULL, SFE_REQ_TX_POLICY_PAYLOAD_HEADER, NULL, HFILL}
},
{
&hf_sfe_policy_packing,
{"The Service Flow Shall Not Pack Multiple SDUs (Or Fragments) Into Single MAC PDUs", "wmx.sfe.policy.packing", FT_BOOLEAN, 8, NULL, SFE_REQ_TX_POLICY_PACKINGS, NULL, HFILL}
},
{
&hf_sfe_policy_crc,
{"The Service Flow Shall Not Include CRC In The MAC PDU", "wmx.sfe.policy.crc", FT_BOOLEAN, 8, NULL, SFE_REQ_TX_POLICY_CRC, NULL, HFILL}
},
{
&hf_sfe_policy_rsvd1,
{"Reserved", "wmx.sfe.policy.rsvd1", FT_UINT8, BASE_HEX, NULL, SFE_REQ_TX_POLICY_RESERVED, NULL, HFILL}
},
{
&hf_sfe_jitter,
{"Tolerated Jitter", "wmx.sfe.jitter", FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &wimax_units_ms, 0x0, NULL, HFILL}
},
{
&hf_sfe_max_latency,
{"Maximum Latency", "wmx.sfe.max_latency", FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &wimax_units_ms, 0x0, NULL, HFILL}
},
{
&hf_sfe_fixed_len_sdu,
{"Fixed/Variable Length SDU", "wmx.sfe.fixed_len_sdu", FT_UINT8, BASE_DEC, VALS(vals_fixed_len_sdu), 0x0, NULL, HFILL}
},
{
&hf_sfe_sdu_size,
{"SDU Size", "wmx.sfe.sdu_size", FT_UINT8, BASE_DEC|BASE_UNIT_STRING, &wimax_units_byte_bytes, 0x0, NULL, HFILL}
},
{
&hf_sfe_target_said,
{"SAID Onto Which SF Is Mapped", "wmx.sfe.target_said", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_arq_enable,
{"ARQ Enable", "wmx.arq.enable", FT_UINT8, BASE_DEC, VALS(vals_arq_enable), 0x0, NULL, HFILL}
},
{
&hf_sfe_arq_window_size,
{"ARQ Window Size", "wmx.arq.window_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_arq_transmitter_delay,
{"ARQ Transmitter Delay (10us granularity)", "wmx.arq.transmitter_delay", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_arq_receiver_delay,
{"ARQ Receiver Delay (10us granularity)", "wmx.arq.receiver_delay", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_arq_block_lifetime,
{"ARQ Block Lifetime (10us granularity)", "wmx.arq.block_lifetime", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_arq_sync_loss_timeout,
{"ARQ Sync Loss Timeout (10us granularity)", "wmx.arq.sync_loss_timeout", FT_UINT16, BASE_DEC, VALS(vals_arq_sync_loss_timeout), 0x0, NULL, HFILL}
},
{
&hf_sfe_arq_transmitter_delay_cor2,
{"ARQ Transmitter Delay (100us granularity)", "wmx.arq.transmitter_delay", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_arq_receiver_delay_cor2,
{"ARQ Receiver Delay (100us granularity)", "wmx.arq.receiver_delay", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_arq_block_lifetime_cor2,
{"ARQ Block Lifetime (100us granularity)", "wmx.arq.block_lifetime", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_arq_sync_loss_timeout_cor2,
{"ARQ Sync Loss Timeout (100us granularity)", "wmx.arq.sync_loss_timeout", FT_UINT16, BASE_DEC, VALS(vals_arq_sync_loss_timeout), 0x0, NULL, HFILL}
},
{
&hf_sfe_arq_deliver_in_order,
{"ARQ Deliver In Order", "wmx.arq.deliver_in_order", FT_UINT8, BASE_DEC, VALS(vals_arq_deliver_in_order), 0x0, NULL, HFILL}
},
{
&hf_sfe_arq_rx_purge_timeout,
{"ARQ RX Purge Timeout (100us granularity)", "wmx.arq.rx_purge_timeout", FT_UINT16, BASE_DEC, VALS(vals_arq_rx_purge_timeout), 0x0, NULL, HFILL}
},
{
&hf_sfe_arq_block_size,
{"ARQ Block Size", "wmx.arq.block_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_arq_block_size_cor2,
{"ARQ Block Size", "wmx.arq.block_size", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_arq_min_block_size,
{"ARQ Minimum Block Size", "wmx.arq.min_block_size", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL}
},
{
&hf_sfe_arq_max_block_size,
{"ARQ Maximum Block Size", "wmx.arq.max_block_size", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL}
},
{
&hf_sfe_cs_specification,
{"CS Specification", "wmx.sfe.cs_specification", FT_UINT8, BASE_DEC, VALS(vals_cs_specification), 0x0, NULL, HFILL}
},
{
&hf_sfe_type_of_data_delivery_services,
{"Type of Data Delivery Services", "wmx.sfe.type_of_data_delivery_services", FT_UINT8, BASE_DEC, VALS(vals_type_of_data_delivery_services), 0x0, NULL, HFILL}
},
{
&hf_sfe_sdu_inter_arrival_interval,
{"SDU Inter-Arrival Interval (in the resolution of 0.5 ms)", "wmx.sfe.sdu_inter_arrival_interval", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_time_base,
{"Time Base", "wmx.sfe.time_base", FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &wimax_units_ms, 0x0, NULL, HFILL}
},
{
&hf_sfe_paging_preference,
{"Paging Preference", "wmx.sfe.paging_preference", FT_UINT8, BASE_DEC, VALS(vals_paging_preference), 0x0, NULL, HFILL}
},
{
&hf_sfe_mbs_zone_identifier_assignment,
{"MBS Zone Identifier", "wmx.sfe.mbs_zone_identifier", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_reserved_34,
{"Reserved", "wmx.sfe.reserved_34", FT_UINT8, BASE_DEC, NULL , 0x0, NULL, HFILL}
},
{
&hf_sfe_global_service_class_name,
{"Global Service Class Name", "wmx.sfe.global_service_class_name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_reserved_36,
{"Reserved", "wmx.sfe.reserved_36", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_sn_feedback_enabled,
{"SN Feedback", "wmx.sfe.sn_feedback_enabled", FT_UINT8, BASE_DEC, VALS(vals_sn_fb_enable), 0x0, NULL, HFILL}
},
{
&hf_sfe_fsn_size,
{"FSN Size", "wmx.sfe.fsn_size", FT_UINT8, BASE_DEC, VALS(vals_fsn_size), 0x0, NULL, HFILL}
},
#if 0
{
&hf_sfe_cid_alloc_for_active_bs,
{"CID Allocation For Active BSs", "wmx.sfe.cid_alloc_for_active_bs", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#endif
{
&hf_sfe_cid_alloc_for_active_bs_cid,
{"CID", "wmx.sfe.cid_alloc_for_active_bs_cid", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_unsolicited_grant_interval,
{"Unsolicited Grant Interval", "wmx.sfe.unsolicited_grant_interval", FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &wimax_units_ms, 0x0, NULL, HFILL}
},
{
&hf_sfe_unsolicited_polling_interval,
{"Unsolicited Polling Interval", "wmx.sfe.unsolicited_polling_interval", FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &wimax_units_ms, 0x0, NULL, HFILL}
},
{
&hf_sfe_pdu_sn_ext_subheader_reorder,
{"PDU SN Extended Subheader For HARQ Reordering", "wmx.sfe.pdu_sn_ext_subheader_reorder", FT_UINT8, BASE_DEC, VALS(vals_pdu_sn_ext_subheader), 0x0, NULL, HFILL}
},
{
&hf_sfe_mbs_contents_ids,
{"MBS contents IDs", "wmx.sfe.mbs_contents_ids", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_mbs_contents_ids_id,
{"MBS Contents ID", "wmx.sfe.mbs_contents_ids_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_harq_service_flows,
{"HARQ Service Flows", "wmx.sfe.harq_service_flows", FT_UINT8, BASE_DEC, VALS(vals_harq), 0x0, NULL, HFILL}
},
{
&hf_sfe_authorization_token,
{"Authorization Token", "wmx.sfe.authorization_token", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#if 0
{
&hf_sfe_harq_channel_mapping,
{"HARQ Channel Mapping", "wmx.sfe.harq_channel_mapping", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#endif
{
&hf_sfe_harq_channel_mapping_index,
{"HARQ Channel Index", "wmx.sfe.harq_channel_mapping.index", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_sfe_unknown_type,
{"Unknown SFE TLV type", "wmx.sfe.unknown_type", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
}
};
static hf_register_info hf_csper[] =
{
{
&hf_cst_classifier_dsc_action,
{"Classifier DSC Action", "wmx.cst.classifier_action", FT_UINT8, BASE_DEC, VALS(vals_cst_classifier_action), 0x0, NULL, HFILL}
},
{
&hf_cst_error_set_errored_param,
{"Errored Parameter", "wmx.cst.error_set.errored_param", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_error_set_error_code,
{"Error Code", "wmx.cst.error_set.error_code", FT_UINT8, BASE_HEX, VALS(vals_cc), 0x0, NULL, HFILL}
},
{
&hf_cst_error_set_error_msg,
{"Error Message", "wmx.cst.error_set.error_msg", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule,
{"Packet Classification Rule", "wmx.cst.pkt_class_rule", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_priority,
{"Classification Rule Priority", "wmx.cst.pkt_class_rule.priority", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_range_mask,
{"ToS/Differentiated Services Codepoint (DSCP) Range And Mask", "wmx.cst.pkt_class_rule.range_mask", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_tos_low,
{"ToS-Low", "wmx.cst.pkt_class_rule.tos-low", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_tos_high,
{"ToS-High", "wmx.cst.pkt_class_rule.tos-high", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_tos_mask,
{"ToS-Mask", "wmx.cst.pkt_class_rule.tos-mask", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_protocol,
{"Protocol", "wmx.cst.pkt_class_rule.protocol", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
#if 0
{
&hf_cst_pkt_class_rule_protocol,
{"Protocol", "wmx.cst.pkt_class_rule.protocol", FT_BYTES, BASE_HEX, NULL, 0x0, "", HFILL}
},
{
&hf_cst_pkt_class_rule_protocol_number,
{"Protocol Number", "wmx.cst.pkt_class_rule.protocol.number", FT_UINT8, BASE_DEC, NULL, 0x0, "", HFILL}
},
#endif
{
&hf_cst_pkt_class_rule_ip_masked_src_address,
{"IP Masked Source Address", "wmx.cst.pkt_class_rule.ip_masked_src_address", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_ip_masked_dest_address,
{"IP Masked Destination Address", "wmx.cst.pkt_class_rule.ip_masked_dest_address", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_src_ipv4,
{"IPv4 Source Address", "wmx.cst.pkt_class_rule.src_ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_dest_ipv4,
{"IPv4 Destination Address", "wmx.cst.pkt_class_rule.dst_ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_mask_ipv4,
{"IPv4 Mask", "wmx.cst.pkt_class_rule.mask_ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_src_ipv6,
{"IPv6 Source Address", "wmx.cst.pkt_class_rule.src_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_dest_ipv6,
{"IPv6 Destination Address", "wmx.cst.pkt_class_rule.dst_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_mask_ipv6,
{"IPv6 Mask", "wmx.cst.pkt_class_rule.mask_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_prot_src_port_range,
{"Protocol Source Port Range", "wmx.cst.pkt_class_rule.prot_src_port_range", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_src_port_low,
{"Src-Port Low", "wmx.cst.pkt_class_rule.src_port_low", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_src_port_high,
{"Src-Port High", "wmx.cst.pkt_class_rule.src_port_high", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_prot_dest_port_range,
{"Protocol Destination Port Range", "wmx.cst.pkt_class_rule.prot_dest_port_range", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_dest_port_low,
{"Dst-Port Low", "wmx.cst.pkt_class_rule.dst_port_low", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_dest_port_high,
{"Dst-Port High", "wmx.cst.pkt_class_rule.dst_port_high", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_dest_mac_address,
{"802.3/Ethernet Destination MAC Address", "wmx.cst.pkt_class_rule.dest_mac_address", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_dest_mac,
{"Destination MAC Address", "wmx.cst.pkt_class_rule.dst_mac", FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_src_mac_address,
{"802.3/Ethernet Source MAC Address", "wmx.cst.pkt_class_rule.src_mac_address", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_src_mac,
{"Source MAC Address", "wmx.cst.pkt_class_rule.src_mac", FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_mask_mac,
{"MAC Address Mask", "wmx.cst.pkt_class_rule.mask_mac", FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_ethertype,
{"Ethertype/IEEE Std 802.2-1998 SAP", "wmx.cst.pkt_class_rule.ethertype", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_etype,
{"Ethertype", "wmx.cst.pkt_class_rule.etype", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_eprot1,
{"Eprot1", "wmx.cst.pkt_class_rule.eprot1", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_eprot2,
{"Eprot2", "wmx.cst.pkt_class_rule.eprot2", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_user_priority,
{"IEEE Std 802.1D-1998 User_Priority", "wmx.cst.pkt_class_rule.user_priority", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_pri_low,
{"Pri-Low", "wmx.cst.pkt_class_rule.pri-low", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_pri_high,
{"Pri-High", "wmx.cst.pkt_class_rule.pri-high", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_vlan_id,
{"IEEE Std 802.1Q-1998 VLAN_ID", "wmx.cst.pkt_class_rule.vlan_id", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_vlan_id1,
{"Vlan_Id1", "wmx.cst.pkt_class_rule.vlan_id1", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_vlan_id2,
{"Vlan_Id2", "wmx.cst.pkt_class_rule.vlan_id2", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_phsi,
{"Associated PHSI", "wmx.cst.pkt_class_rule.phsi", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_index,
{"Packet Classifier Rule Index (PCRI)", "wmx.cst.pkt_class_rule.index", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_large_context_id,
{"Large Context ID", "wmx.cst.large_context_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_short_format_context_id,
{"Short-Format Context ID", "wmx.cst.short_format_context_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_vendor_spec,
{"Vendor-Specific Classifier Parameters", "wmx.cst.pkt_class_rule.vendor_spec", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_classifier_action_rule,
{"Classifier Action Rule", "wmx.cst.pkt_class_rule.classifier.action.rule", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_classifier_action_rule_bit0,
{"Bit #0", "wmx.cst.pkt_class_rule.classifier.action.rule.bit0", FT_UINT8, BASE_HEX, VALS(vals_classification_action_rule), CST_PKT_CLASS_RULE_CLASSIFIER_ACTION_RULE_BIT0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_classifier_action_rule_bit1,
{"Reserved", "wmx.cst.pkt_class_rule.classifier.action.rule.reserved", FT_UINT8, BASE_HEX, NULL, CST_PKT_CLASS_RULE_CLASSIFIER_ACTION_RULE_RSV, NULL, HFILL}
},
{
&hf_cst_phs_dsc_action,
{"PHS DSC action", "wmx.cst.phs_dsc_action", FT_UINT8, BASE_DEC, VALS(vals_cst_phs_dsc_action), 0x0, NULL, HFILL}
},
{
&hf_cst_phs_rule,
{"PHS Rule", "wmx.cst.phs_rule", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_phs_phsi,
{"PHSI", "wmx.cst.phs_rule.phsi", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_phs_phsf,
{"PHSF", "wmx.cst.phs_rule.phsf", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_phs_phsm,
{"PHSM (bit x: 0-don't suppress the (x+1) byte; 1-suppress the (x+1) byte)", "wmx.cst.phs_rule.phsm", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_phs_phss,
{"PHSS", "wmx.cst.phs_rule.phss", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_phs_phsv,
{"PHSV", "wmx.cst.phs_rule.phsv", FT_UINT8, BASE_DEC, VALS(vals_verify), 0x0, NULL, HFILL}
},
{
&hf_cst_phs_vendor_spec,
{"Vendor-Specific PHS Parameters", "wmx.cst.phs.vendor_spec", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_pkt_class_rule_ipv6_flow_label,
{"IPv6 Flow Label", "wmx.cst.pkt_class_rule.ipv6_flow_label", FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_csper_atm_switching_encoding,
{"ATM Switching Encoding", "wmx.csper.atm_switching_encoding", FT_UINT8, BASE_DEC, VALS(vals_atm_switching_encodings), 0x0, NULL, HFILL}
},
{
&hf_csper_atm_classifier,
{"ATM Classifier TLV", "wmx.csper.atm_classifier", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_csper_atm_classifier_vpi,
{"VPI Classifier", "wmx.csper.atm_classifier_vpi", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_csper_atm_classifier_vci,
{"VCI Classifier", "wmx.csper.atm_classifier_vci", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_csper_atm_classifier_id,
{"Classifier ID", "wmx.csper.atm_classifier_tlv", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_csper_unknown_type,
{"Unknown CSPER TLV type", "wmx.csper.unknown_type", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cst_invalid_tlv,
{"Invalid TLV", "wmx.cst.invalid_tlv", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
}
};
static hf_register_info hf_xmac[] =
{
{
&hf_xmac_tuple_rsvd,
{"Reserved", "wmx.xmac_tuple.reserved", FT_UINT8, BASE_HEX, NULL, XMAC_TUPLE_RESERVED, NULL, HFILL}
},
{
&hf_xmac_tuple_key_seq_num,
{"Key Sequence Number", "wmx.xmac_tuple.key_sn", FT_UINT8, BASE_DEC, NULL, XMAC_TUPLE_KEY_SEQ_NUM, NULL, HFILL}
},
{
&hf_hmac_tuple_hmac_digest,
{"HMAC Digest", "wmx.xmac_tuple.hmac_digest", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cmac_tuple_bsid,
{"BSID", "wmx.cmac_tuple.bsid", FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cmac_tuple_cmac_value,
{"CMAC Value", "wmx.cmac_tuple.cmac.value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_packet_number_counter,
{"Packet Number Counter", "wmx.xmac_tuple.packet_number_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
}
};
static hf_register_info hf_snp[] =
{
{
&hf_snp_pkm_version_support,
{"PKM Version Support", "wmx.security_negotiation_parameters.pkm_version_support",FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_snp_pkm_version_support_bit0,
{"PKM version 1", "wmx.security_negotiation_parameters.pkm_version_support.bit0",FT_BOOLEAN, 8, TFS(&tfs_supported), SNP_PKM_VERSION_SUPPORT_BIT0, NULL, HFILL}
},
{
&hf_snp_pkm_version_support_bit1,
{"PKM version 2", "wmx.security_negotiation_parameters.pkm_version_support.bit1",FT_BOOLEAN, 8, TFS(&tfs_supported), SNP_PKM_VERSION_SUPPORT_BIT1, NULL, HFILL}
},
{
&hf_snp_pkm_version_support_reserved,
{"Reserved", "wmx.security_negotiation_parameters.pkm_version_support.reserved",FT_UINT8, BASE_HEX, NULL, SNP_PKM_VERSION_SUPPORT_RSV, NULL, HFILL}
},
{
&hf_snp_auth_policy_support,
{"Authorization Policy Support", "wmx.security_negotiation_parameters.auth_policy_support",FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_snp_auth_policy_support_bit0,
{"RSA-based Authorization At The Initial Network Entry", "wmx.security_negotiation_parameters.auth_policy_support.bit0",FT_BOOLEAN, 8, TFS(&tfs_supported), SNP_AUTH_POLICY_SUPPORT_BIT0, NULL, HFILL}
},
{
&hf_snp_auth_policy_support_bit1,
{"EAP-based Authorization At The Initial Network Entry", "wmx.security_negotiation_parameters.auth_policy_support.bit1",FT_BOOLEAN, 8, TFS(&tfs_supported), SNP_AUTH_POLICY_SUPPORT_BIT1, NULL, HFILL}
},
{
&hf_snp_auth_policy_support_bit2,
{"Authenticated EAP-based Authorization At The Initial Network Entry", "wmx.security_negotiation_parameters.auth_policy_support.bit2",FT_BOOLEAN, 8, TFS(&tfs_supported), SNP_AUTH_POLICY_SUPPORT_BIT2, NULL, HFILL}
},
{
&hf_snp_auth_policy_support_bit3,
{"Reserved", "wmx.security_negotiation_parameters.auth_policy_support.bit3",FT_UINT8, BASE_HEX, NULL, SNP_AUTH_POLICY_SUPPORT_BIT3, NULL, HFILL}
},
{
&hf_snp_auth_policy_support_bit4,
{"RSA-based Authorization At Re-entry", "wmx.security_negotiation_parameters.auth_policy_support.bit4",FT_BOOLEAN, 8, TFS(&tfs_supported), SNP_AUTH_POLICY_SUPPORT_BIT4, NULL, HFILL}
},
{
&hf_snp_auth_policy_support_bit5,
{"EAP-based Authorization At Re-entry", "wmx.security_negotiation_parameters.auth_policy_support.bit5",FT_BOOLEAN, 8, TFS(&tfs_supported), SNP_AUTH_POLICY_SUPPORT_BIT5, NULL, HFILL}
},
{
&hf_snp_auth_policy_support_bit6,
{"Authenticated EAP-based Authorization At Re-entry", "wmx.security_negotiation_parameters.auth_policy_support.bit6",FT_BOOLEAN, 8, TFS(&tfs_supported), SNP_AUTH_POLICY_SUPPORT_BIT6, NULL, HFILL}
},
{
&hf_snp_auth_policy_support_bit7,
{"Reserved", "wmx.security_negotiation_parameters.auth_policy_support.bit7",FT_UINT8, BASE_HEX, NULL, SNP_AUTH_POLICY_SUPPORT_BIT7, NULL, HFILL}
},
{
&hf_snp_mac_mode,
{"MAC (Message Authentication Code) Mode", "wmx.security_negotiation_parameters.mac_mode",FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_snp_mac_mode_bit0,
{"HMAC", "wmx.security_negotiation_parameters.mac_mode.bit0",FT_BOOLEAN, 8, TFS(&tfs_supported), SNP_MAC_MODE_BIT0, NULL, HFILL}
},
{
&hf_snp_mac_mode_bit1,
{"CMAC", "wmx.security_negotiation_parameters.mac_mode.bit1",FT_BOOLEAN, 8, TFS(&tfs_supported), SNP_MAC_MODE_BIT1, NULL, HFILL}
},
{
&hf_snp_mac_mode_bit1_rsvd,
{"Reserved", "wmx.security_negotiation_parameters.mac_mode.bit1_rsvd",FT_BOOLEAN, 8, TFS(&tfs_supported), SNP_MAC_MODE_BIT1, NULL, HFILL}
},
{
&hf_snp_mac_mode_bit2,
{"64-bit Short-HMAC", "wmx.security_negotiation_parameters.mac_mode.bit2",FT_BOOLEAN, 8, TFS(&tfs_supported), SNP_MAC_MODE_BIT2, NULL, HFILL}
},
{
&hf_snp_mac_mode_bit3,
{"80-bit Short-HMAC", "wmx.security_negotiation_parameters.mac_mode.bit3",FT_BOOLEAN, 8, TFS(&tfs_supported), SNP_MAC_MODE_BIT3, NULL, HFILL}
},
{
&hf_snp_mac_mode_bit4,
{"96-bit Short-HMAC", "wmx.security_negotiation_parameters.mac_mode.bit4",FT_BOOLEAN, 8, TFS(&tfs_supported), SNP_MAC_MODE_BIT4, NULL, HFILL}
},
{
&hf_snp_mac_mode_bit5,
{"CMAC", "wmx.security_negotiation_parameters.mac_mode.bit5",FT_BOOLEAN, 8, TFS(&tfs_supported), SNP_MAC_MODE_BIT5, NULL, HFILL}
},
{
&hf_snp_mac_mode_reserved,
{"Reserved", "wmx.security_negotiation_parameters.mac_mode.reserved",FT_UINT8, BASE_HEX, NULL, SNP_MAC_MODE_RSV, NULL, HFILL}
},
{
&hf_snp_mac_mode_reserved1,
{"Reserved", "wmx.security_negotiation_parameters.mac_mode.reserved",FT_UINT8, BASE_HEX, NULL, SNP_MAC_MODE_RSV1, NULL, HFILL}
},
{
&hf_snp_pn_window_size,
{"PN Window Size", "wmx.security_negotiation_parameters.pn_window_size",FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_snp_max_conc_transactions,
{"Maximum concurrent transactions (0 indicates no limit)", "wmx.security_negotiation_parameters.max_conc_transactions",FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_snp_max_suppt_sec_assns,
{"Maximum number of security associations supported by the SS", "wmx.security_negotiation_parameters.max_suppt_sec_assns",FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_snp_unknown_type,
{"Unknown Security Negotiation Parameter type", "wmx.security_negotiation_parameters.unknown.type",FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
}
};
static hf_register_info hf_pkm[] =
{
{
&hf_pkm_msg_attr_display,
{"Display String", "wmx.pkm_msg.pkm_attr.display_string", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_msg_attr_auth_key,
{"Auth Key", "wmx.pkm_msg.pkm_attr.auth_key", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_msg_attr_tek,
{"TEK", "wmx.pkm_msg.pkm_attr.tek", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_msg_attr_key_life_time,
{"Key Lifetime", "wmx.pkm_msg.pkm_attr.key_life_time", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_msg_attr_key_seq_num,
{"Key Sequence Number", "wmx.pkm_msg.pkm_attr.key_seq_num", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_msg_attr_hmac_digest,
{"HMAC-Digest", "wmx.pkm_msg.pkm_attr.hmac_digest", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_msg_attr_said,
{"SAID", "wmx.pkm_msg.pkm_attr.said", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
#if 0
{
&hf_pkm_msg_attr_tek_param,
{"TEK Parameters", "wmx.pkm_msg.pkm_attr.tek_parameters", FT_BYTES, BASE_HEX, NULL, 0x0, "", HFILL}
},
#endif
{
&hf_pkm_msg_attr_cbc_iv,
{"CBC IV", "wmx.pkm_msg.pkm_attr.cbc_iv", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_msg_attr_error_code,
{"Error Code", "wmx.pkm_msg.pkm_attr.error_code", FT_UINT8, BASE_DEC, VALS(vals_pkm_attr_error_codes), 0x0, NULL, HFILL}
},
{
&hf_pkm_msg_attr_ca_certificate,
{"CA Certificate", "wmx.pkm_msg.pkm_attr.ca_certificate", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_msg_attr_ss_certificate,
{"SS Certificate", "wmx.pkm_msg.pkm_attr.ss_certificate", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#if 0
{
&hf_pkm_msg_attr_security_capabilities,
{"Security Capabilities", "wmx.pkm_msg.pkm_attr.security_capabilities", FT_BYTES, BASE_HEX, NULL, 0x0, "", HFILL}
},
#endif
{
&hf_pkm_msg_crypto_suite,
{"Cryptography", "wmx.pkm_msg.pkm_attr.crypto_suite", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_msg_crypto_suite_msb,
{"Data Encryption Algorithm Identifiers", "wmx.pkm_msg.pkm_attr.crypto_suite.msb", FT_UINT8, BASE_DEC, VALS(vals_data_encryption_ids), 0x0, NULL, HFILL}
},
{
&hf_pkm_msg_crypto_suite_middle,
{"Data Authentication Algorithm Identifiers", "wmx.pkm_msg.pkm_attr.crypto_suite.middle", FT_UINT8, BASE_DEC, VALS(vals_data_authentication_ids), 0x0, NULL, HFILL}
},
{
&hf_pkm_msg_crypto_suite_lsb,
{"TEK Encryption Algorithm Identifiers", "wmx.pkm_msg.pkm_attr.crypto_suite.lsb", FT_UINT8, BASE_DEC, VALS(vals_tek_encryption_ids), 0x0, NULL, HFILL}
},
#if 0
{
&hf_pkm_msg_crypto_list,
{"Cryptographic-Suite List", "wmx.pkm_msg.pkm_attr.crypto_suite_list", FT_BYTES, BASE_HEX, NULL, 0x0, "", HFILL}
},
#endif
#if 0
{
&hf_pkm_msg_version,
{"Reserved ", "wmx.pkm_msg.pkm_attr.version", FT_UINT8, BASE_HEX, NULL, 0x0, "", HFILL}
},
#endif
#if 0
{
&hf_pkm_msg_sa_descriptor,
{"SA Descriptor", "wmx.pkm_msg.pkm_attr.sa_descriptor", FT_BYTES, BASE_HEX, NULL, 0x0, "", HFILL}
},
#endif
{
&hf_pkm_sa_type,
{"SA Type", "wmx.pkm_msg.pkm_attr.sa_type", FT_UINT8, BASE_DEC, VALS(vs_sa_type), 0x0, NULL, HFILL}
},
#if 0
{
&hf_pkm_attr_security_negotiation_parameters,
{"Security Negotiation Parameters", "wmx.pkm_msg.pkm_attr.security_negotiation_parameters", FT_BYTES, BASE_HEX, NULL, 0x0, "", HFILL}
},
#endif
#if 0
{
&hf_pkm_attr_config_settings,
{"PKM Configuration Settings", "wmx.pkm_msg.pkm_attr.config_settings", FT_BYTES, BASE_HEX, NULL, 0x0, "", HFILL}
},
#endif
{
&hf_pkm_config_settings_authorize_waitout,
{"Authorize Wait Timeout (in seconds)", "wmx.pkm_msg.pkm_attr.config_settings.authorize_waitout", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_config_settings_reauthorize_waitout,
{"Reauthorize Wait Timeout (in seconds)", "wmx.pkm_msg.pkm_attr.config_settings.reauthorize_waitout", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_config_settings_grace_time,
{"Authorization Grace Time (in seconds)", "wmx.pkm_msg.pkm_attr.config_settings.grace_time", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_config_settings_operational_waittime,
{"Operational Wait Timeout (in seconds)", "wmx.pkm_msg.pkm_attr.config_settings.operational_wait_timeout", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_config_settings_rekey_wait_timeout,
{"Rekey Wait Timeout (in seconds)", "wmx.pkm_msg.pkm_attr.config_settings.rekey_wait_timeout", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_config_settings_tek_grace_time,
{"TEK Grace Time (in seconds)", "wmx.pkm_msg.pkm_attr.config_settings.tek_grace_time", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_config_settings_authorize_reject_wait_timeout,
{"Authorize Reject Wait Timeout(in seconds)", "wmx.pkm_msg.pkm_attr.config_settings.authorize_reject_wait_timeout", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_nonce,
{"Nonce", "wmx.pkm_msg.pkm_attr.nonce", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_ss_random,
{"SS_RANDOM", "wmx.pkm_msg.pkm_attr.ss_random", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_bs_random,
{"BS_RANDOM", "wmx.pkm_msg.pkm_attr.bs_random", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_pre_pak,
{"Pre-PAK", "wmx.pkm_msg.pkm_attr.pre_pak", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#if 0
{
&hf_pkm_attr_pak_ak_seq_number,
{"PAK/AK Sequence Number", "wmx.pkm_msg.pkm_attr.pak_ak_seq_number", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#endif
{
&hf_pkm_attr_bs_certificate,
{"BS Certificate", "wmx.pkm_msg.pkm_attr.bs_certificate", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_sig_bs,
{"SigBS", "wmx.pkm_msg.pkm_attr.sig_bs",FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_ms_mac_address,
{"MS-MAC Address", "wmx.pkm_msg.pkm_attr.ms_mac_address",FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_cmac_digest,
{"CMAC Digest", "wmx.pkm_msg.pkm_attr.cmac_digest",FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_cmac_digest_pn,
{"CMAC Packet Number counter, CMAC_PN_*", "wmx.pkm_msg.pkm_attr.cmac_digest.pn",FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_cmac_digest_value,
{"CMAC Value", "wmx.pkm_msg.pkm_attr.cmac_digest.value",FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_push_modes,
{"Key Push Modes", "wmx.pkm_msg.pkm_attr.key_push_modes",FT_UINT8, BASE_DEC, VALS(va_key_push_modes), 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_key_push_counter,
{"Key Push Counter", "wmx.pkm_msg.pkm_attr.key_push_counter",FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_gkek,
{"GKEK", "wmx.pkm_msg.pkm_attr.gkek",FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_sig_ss,
{"SigSS", "wmx.pkm_msg.pkm_attr.sig_ss",FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_akid,
{"AKID", "wmx.pkm_msg.pkm_attr.akid",FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_eap_payload,
{"EAP Payload", "wmx.pkm_msg.pkm_attr.eap_payload", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_auth_result_code,
{"Auth Result Code", "wmx.pkm_msg.pkm_attr.auth_result_code", FT_UINT8, BASE_DEC, VALS(vs_success_reject), 0x0, NULL, HFILL}
},
{
&hf_pkm_attr_sa_service_type,
{"SA Service Type", "wmx.pkm_msg.pkm_attr.sa_service_type", FT_UINT8, BASE_DEC, VALS(vs_sa_service_type), 0x0, NULL, HFILL}
},
#if 0
{
&hf_pkm_attr_config_settings,
{"PKMv2 Configuration Settings", "wmx.pkm_msg.pkm_attr.config_settings", FT_BYTES, BASE_HEX, NULL, 0x0, "", HFILL}
},
#endif
{
&hf_pkm_attr_frame_number,
{"Frame Number", "wmx.pkm_msg.pkm_attr.frame_number", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
#if 1
{
&hf_pkm_attr_associated_gkek_seq_number,
{"Associated GKEK Sequence Number", "wmx.pkm_msg.pkm_attr.associated_gkek_seq_number",FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#endif
#if 0
{
&hf_pkm_attr_gkek_params,
{"GKEK Parameters", "wmx.pkm_msg.pkm_attr.gkek_params",FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#endif
{
&hf_pkm_msg_unknown_type,
{"Unknown Type", "wmx.pkm.unknown.type", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
}
};
static hf_register_info hf_common_tlv[] =
{
{
&hf_common_tlv_mac_version,
{ "MAC Version", "wmx.common_tlv.mac_version", FT_UINT8, BASE_DEC, VALS(vals_dcd_mac_version), 0x0, NULL, HFILL}
},
{
&hf_common_tlv_vendor_id,
{ "Vendor ID Encoding", "wmx.common_tlv.vendor_id_encoding", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_common_tlv_vendor_specific_type,
{ "Vendor Specific Type", "wmx.common_tlv.vendor_specific_type", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_common_tlv_vendor_specific_length_size,
{
"Vendor Specific Length Size", "wmx.common_tlv.vendor_specific_length_size",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_common_tlv_vendor_specific_length,
{ "Vendor Specific Length", "wmx.common_tlv.vendor_specific_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_common_tlv_vendor_specific_value,
{ "Vendor Specific Value", "wmx.common_tlv.vendor_specific_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_common_current_transmitted_power,
{ "Current Transmitted Power", "wmx.common_tlv.current_transmitted_power", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#if 0
{
&hf_common_tlv_unknown_type,
{"Unknown Common TLV Type", "wmx.common_tlv.unknown_type", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
}
#endif
};
static ei_register_info ei[] = {
{ &ei_common_tlv_info, { "wmx.common_tlv.invalid", PI_PROTOCOL, PI_WARN, "Invalid TLV info", EXPFILL }},
};
expert_module_t* expert_wimax_utility;
if(proto_wimax_utility_decoders == -1)
{
proto_wimax_utility_decoders = proto_register_protocol (
"WiMax Sub-TLV Messages",
"WiMax Sub-TLV (sub)",
"wmx.sub"
);
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_wimax_utility_decoders, hf_sfe, array_length(hf_sfe));
proto_register_field_array(proto_wimax_utility_decoders, hf_csper, array_length(hf_csper));
proto_register_field_array(proto_wimax_utility_decoders, hf_xmac, array_length(hf_xmac));
proto_register_field_array(proto_wimax_utility_decoders, hf_snp, array_length(hf_snp));
proto_register_field_array(proto_wimax_utility_decoders, hf_pkm, array_length(hf_pkm));
proto_register_field_array(proto_wimax_utility_decoders, hf_common_tlv, array_length(hf_common_tlv));
expert_wimax_utility = expert_register_protocol(proto_wimax_utility_decoders);
expert_register_field_array(expert_wimax_utility, ei, array_length(ei));
eap_handle = find_dissector("eap");
}
}
void wimax_error_parameter_set_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset;
guint tvb_len, tlv_len;
gint tlv_type;
proto_item *ceps_item = NULL;
proto_tree *ceps_tree = NULL;
tlv_info_t tlv_info;
tvb_len = tvb_reported_length(tvb);
offset = 0;
ceps_item = proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, offset, tvb_len, "Error Parameter Set (%u bytes)", tvb_len);
ceps_tree = proto_item_add_subtree(ceps_item, ett_wimax_error_parameter_set);
if(!tvb_len)
return;
if(tvb_len < 2)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Invalid Error Parameter Set");
return;
}
while(offset < tvb_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "EPS TLV error");
proto_tree_add_item(ceps_tree, hf_cst_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
#ifdef DEBUG
proto_tree_add_protocol_format(ceps_tree, proto_wimax_utility_decoders, tvb, offset, (tlv_len+2+get_tlv_size_of_length(&tlv_info)), "EPS TLV Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, tlv_len, offset, tvb_len);
#endif
switch (tlv_type)
{
case CST_ERROR_SET_ERRORED_PARAM:
add_tlv_subtree(&tlv_info, ceps_tree, hf_cst_error_set_errored_param, tvb, offset, ENC_NA);
break;
case CST_ERROR_SET_ERROR_CODE:
add_tlv_subtree(&tlv_info, ceps_tree, hf_cst_error_set_error_code, tvb, offset, ENC_BIG_ENDIAN);
break;
case CST_ERROR_SET_ERROR_MSG:
add_tlv_subtree(&tlv_info, ceps_tree, hf_cst_error_set_error_msg, tvb, offset, ENC_ASCII|ENC_NA);
break;
}
offset += (tlv_len+get_tlv_value_offset(&tlv_info));
}
}
void wimax_convengence_service_parameter_encoding_rules_decoder(guint sfe_type, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset, tlv_offset;
guint tvb_len, tlv_len, length;
gint tlv_type;
proto_item *csper_item;
proto_tree *csper_tree;
proto_tree *tlv_tree, *ti_tree;
proto_item *tlv_item, *ti_item;
tlv_info_t tlv_info;
gboolean ipv6 = ((sfe_type == SFE_CSPER_PACKET_IPV6) || (sfe_type == SFE_CSPER_PACKET_IPV6_802_3) || (sfe_type == SFE_CSPER_PACKET_IPV6_802_1Q));
if((sfe_type < SFE_CSPER_ATM) || (sfe_type > SFE_CSPER_PACKET_IP_802_3_ECRTP_COMPRESSION))
return;
tvb_len = tvb_reported_length(tvb);
offset = 0;
csper_item = proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, offset, tvb_len, "Convergence Service Parameter Encoding Rules (%u bytes)", tvb_len);
csper_tree = proto_item_add_subtree(csper_item, ett_wimax_cst_encoding_rules);
if(!tvb_len)
return;
if(tvb_len < 2)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Invalid Convergence Service Parameter Encoding Rules");
return;
}
while(offset < tvb_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "CSPER TLV error");
proto_tree_add_item(csper_tree, hf_cst_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
#ifdef DEBUG
proto_tree_add_protocol_format(csper_tree, proto_wimax_utility_decoders, tvb, offset, (tlv_len+2+get_tlv_size_of_length(&tlv_info)), "CSPER TLV Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, tlv_len, offset, tvb_len);
#endif
offset += get_tlv_value_offset(&tlv_info);
if(sfe_type == SFE_CSPER_ATM)
{
switch (tlv_type)
{
case CST_ATM_SWITCHING:
add_tlv_subtree(&tlv_info, csper_tree, hf_csper_atm_switching_encoding, tvb, offset-get_tlv_value_offset(&tlv_info), ENC_BIG_ENDIAN);
break;
case CST_ATM_CLASSIFIER:
tlv_item = add_tlv_subtree(&tlv_info, csper_tree, hf_csper_atm_classifier, tvb, offset-get_tlv_value_offset(&tlv_info), ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_wimax_cst_encoding_rules);
tlv_offset = offset;
while(tlv_offset < (tlv_len + offset))
{
init_tlv_info(&tlv_info, tvb, tlv_offset);
tlv_type = get_tlv_type(&tlv_info);
length = get_tlv_length(&tlv_info);
if(tlv_type == -1 || length > MAX_TLV_LEN || length < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "ATM Classifier TLV error");
proto_tree_add_item(tlv_tree, hf_cst_invalid_tlv, tvb, offset, (tlv_len - tlv_offset), ENC_NA);
break;
}
#ifdef DEBUG
proto_tree_add_protocol_format(csper_tree, proto_wimax_utility_decoders, tvb, offset, (tlv_len+2+get_tlv_size_of_length(&tlv_info)), "ATM Classifier TLV Type: %u (%u bytes, offset=%u, tlv_len=%u)", tlv_type, length, offset, tlv_len);
#endif
switch (tlv_type)
{
case ATM_VPI_CLASSIFIER:
add_tlv_subtree(&tlv_info, tlv_tree, hf_csper_atm_classifier_vpi, tvb, tlv_offset, ENC_BIG_ENDIAN);
break;
case ATM_VCI_CLASSIFIER:
add_tlv_subtree(&tlv_info, tlv_tree, hf_csper_atm_classifier_vci, tvb, tlv_offset, ENC_BIG_ENDIAN);
break;
case ATM_CLASSIFIER_ID:
add_tlv_subtree(&tlv_info, tlv_tree, hf_csper_atm_classifier_id, tvb, tlv_offset, ENC_BIG_ENDIAN);
break;
default:
break;
}
tlv_offset += (length + get_tlv_value_offset(&tlv_info));
}
break;
case CST_ATM_CLASSIFIER_DSC_ACTION:
add_tlv_subtree(&tlv_info, csper_tree, hf_cst_classifier_dsc_action, tvb, offset-get_tlv_value_offset(&tlv_info), ENC_BIG_ENDIAN);
break;
case CST_ATM_CLASSIFIER_ERROR_PARAMETER_SET:
tlv_tree = add_protocol_subtree(&tlv_info, ett_wimax_cst_encoding_rules, csper_tree, proto_wimax_utility_decoders, tvb, offset-get_tlv_value_offset(&tlv_info), tlv_len, "Classifier Error Parameter Set");
wimax_error_parameter_set_decoder(tvb_new_subset_length(tvb, offset, tlv_len), pinfo, tlv_tree);
break;
default:
add_tlv_subtree(&tlv_info, csper_tree, hf_csper_unknown_type, tvb, offset-get_tlv_value_offset(&tlv_info), ENC_NA);
break;
}
}
else
{
switch (tlv_type)
{
case CST_CLASSIFIER_ACTION:
add_tlv_subtree(&tlv_info, csper_tree, hf_cst_classifier_dsc_action, tvb, offset-get_tlv_value_offset(&tlv_info), ENC_BIG_ENDIAN);
break;
case CST_CLASSIFIER_ERROR_PARAM_SET:
case CST_PHS_ERROR_PARAM_SET:
tlv_tree = add_protocol_subtree(&tlv_info, ett_wimax_cst_encoding_rules, csper_tree, proto_wimax_utility_decoders, tvb, offset-get_tlv_value_offset(&tlv_info), tlv_len, "Classifier Error Parameter Set");
wimax_error_parameter_set_decoder(tvb_new_subset_length(tvb, offset, tlv_len), pinfo, tlv_tree);
break;
case CST_PACKET_CLASSIFICATION_RULE:
{
tlv_item = add_tlv_subtree(&tlv_info, csper_tree, hf_cst_pkt_class_rule, tvb, offset-get_tlv_value_offset(&tlv_info), ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_wimax_cst_encoding_rules);
tlv_offset = offset;
while(tlv_offset < (tlv_len + offset))
{
init_tlv_info(&tlv_info, tvb, tlv_offset);
tlv_type = get_tlv_type(&tlv_info);
length = get_tlv_length(&tlv_info);
if(tlv_type == -1 || length > MAX_TLV_LEN || length < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Packet Classification Rule TLV error");
proto_tree_add_item(tlv_tree, hf_cst_invalid_tlv, tvb, offset, (tlv_len - tlv_offset), ENC_NA);
break;
}
#ifdef DEBUG
proto_tree_add_protocol_format(csper_tree, proto_wimax_utility_decoders, tvb, tlv_offset, (length + get_tlv_value_offset(&tlv_info)), "Packet Classification Rule TLV Type: %u (%u bytes, offset=%u, tlv_len=%u)", tlv_type, length, tlv_offset, tlv_len);
#endif
tlv_offset += get_tlv_value_offset(&tlv_info);
switch (tlv_type)
{
case CST_PKT_CLASS_RULE_PRIORITY:
add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_priority, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_BIG_ENDIAN);
break;
case CST_PKT_CLASS_RULE_RANGE_MASK:
ti_item = add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_range_mask, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_NA);
ti_tree = proto_item_add_subtree(ti_item, ett_wimax_cst_encoding_rules);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_tos_low, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_tos_high, tvb, tlv_offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_tos_mask, tvb, tlv_offset + 2, 1, ENC_BIG_ENDIAN);
break;
case CST_PKT_CLASS_RULE_PROTOCOL:
add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_protocol, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_BIG_ENDIAN);
break;
case CST_PKT_CLASS_RULE_SRC_IP:
ti_item = add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_ip_masked_src_address, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_NA);
ti_tree = proto_item_add_subtree(ti_item, ett_wimax_cst_encoding_rules);
if(ipv6)
{
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_src_ipv6, tvb, tlv_offset, 16, ENC_NA);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_mask_ipv6, tvb, tlv_offset + 16, 16, ENC_NA);
}
else
{
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_src_ipv4, tvb, tlv_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_mask_ipv4, tvb, tlv_offset + 4, 4, ENC_BIG_ENDIAN);
}
break;
case CST_PKT_CLASS_RULE_DST_IP:
ti_item = add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_ip_masked_dest_address, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_NA);
ti_tree = proto_item_add_subtree(ti_item, ett_wimax_cst_encoding_rules);
if(ipv6)
{
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_dest_ipv6, tvb, tlv_offset, 16, ENC_NA);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_mask_ipv6, tvb, tlv_offset + 16, 16, ENC_NA);
}
else
{
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_dest_ipv4, tvb, tlv_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_mask_ipv4, tvb, tlv_offset + 4, 4, ENC_BIG_ENDIAN);
}
break;
case CST_PKT_CLASS_RULE_SRCPORT_RANGE:
ti_item = add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_prot_src_port_range, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_NA);
ti_tree = proto_item_add_subtree(ti_item, ett_wimax_cst_encoding_rules);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_src_port_low, tvb, tlv_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_src_port_high, tvb, tlv_offset + 2, 2, ENC_BIG_ENDIAN);
break;
case CST_PKT_CLASS_RULE_DSTPORT_RANGE:
ti_item = add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_prot_dest_port_range, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_NA);
ti_tree = proto_item_add_subtree(ti_item, ett_wimax_cst_encoding_rules);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_dest_port_low, tvb, tlv_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_dest_port_high, tvb, tlv_offset + 2, 2, ENC_BIG_ENDIAN);
break;
case CST_PKT_CLASS_RULE_DST_MAC:
ti_item = add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_dest_mac_address, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_NA);
ti_tree = proto_item_add_subtree(ti_item, ett_wimax_cst_encoding_rules);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_dest_mac, tvb, tlv_offset, 6, ENC_NA);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_mask_mac, tvb, tlv_offset + 6, 6, ENC_NA);
break;
case CST_PKT_CLASS_RULE_SRC_MAC:
ti_item = add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_src_mac_address, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_NA);
ti_tree = proto_item_add_subtree(ti_item, ett_wimax_cst_encoding_rules);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_src_mac, tvb, tlv_offset, 6, ENC_NA);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_mask_mac, tvb, tlv_offset + 6, 6, ENC_NA);
break;
case CST_PKT_CLASS_RULE_ETHERTYPE:
ti_item = add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_ethertype, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_NA);
ti_tree = proto_item_add_subtree(ti_item, ett_wimax_cst_encoding_rules);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_etype, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_eprot1, tvb, tlv_offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_eprot2, tvb, tlv_offset + 2, 1, ENC_BIG_ENDIAN);
break;
case CST_PKT_CLASS_RULE_USER_PRIORITY:
ti_item = add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_user_priority, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_NA);
ti_tree = proto_item_add_subtree(ti_item, ett_wimax_cst_encoding_rules);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_pri_low, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_pri_high, tvb, tlv_offset + 1, 1, ENC_BIG_ENDIAN);
break;
case CST_PKT_CLASS_RULE_VLAN_ID:
ti_item = add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_vlan_id, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_NA);
ti_tree = proto_item_add_subtree(ti_item, ett_wimax_cst_encoding_rules);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_vlan_id1, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_vlan_id2, tvb, tlv_offset + 1, 1, ENC_BIG_ENDIAN);
break;
case CST_PKT_CLASS_RULE_PHSI:
add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_phsi, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_BIG_ENDIAN);
break;
case CST_PKT_CLASS_RULE_INDEX:
add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_index, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_BIG_ENDIAN);
break;
case CST_PKT_CLASS_RULE_IPv6_FLOW_LABEL:
add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_ipv6_flow_label, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_BIG_ENDIAN);
break;
case CST_PKT_CLASS_RULE_VENDOR_SPEC:
add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_vendor_spec, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_NA);
break;
case CST_CLASSIFIER_ACTION_RULE:
ti_item = add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_pkt_class_rule_classifier_action_rule, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_BIG_ENDIAN);
ti_tree = proto_item_add_subtree(ti_item, ett_wimax_cst_encoding_rules);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_classifier_action_rule_bit0, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_cst_pkt_class_rule_classifier_action_rule_bit1, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
break;
case CST_PKT_CLASS_RULE_LARGE_CONTEXT_ID:
add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_large_context_id, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_BIG_ENDIAN);
break;
case CST_PKT_CLASS_RULE_SHORT_FORMAT_CONTEXT_ID:
add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_short_format_context_id, tvb, tlv_offset-get_tlv_value_offset(&tlv_info), ENC_BIG_ENDIAN);
break;
default:
break;
}
tlv_offset += length;
}
break;
}
case CST_PHS_DSC_ACTION:
add_tlv_subtree(&tlv_info, csper_tree, hf_cst_phs_dsc_action, tvb, offset-get_tlv_value_offset(&tlv_info), ENC_BIG_ENDIAN);
break;
case CST_PHS_RULE:
{
tlv_item = add_tlv_subtree(&tlv_info, csper_tree, hf_cst_phs_rule, tvb, offset-get_tlv_value_offset(&tlv_info), ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_wimax_cst_encoding_rules);
tlv_offset = offset;
while(tlv_offset < (tlv_len + offset))
{
init_tlv_info(&tlv_info, tvb, tlv_offset);
tlv_type = get_tlv_type(&tlv_info);
length = get_tlv_length(&tlv_info);
if(tlv_type == -1 || length > MAX_TLV_LEN || length < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "PHS n Rule TLV error");
proto_tree_add_item(tlv_tree, hf_cst_invalid_tlv, tvb, offset, (tlv_len - tlv_offset), ENC_NA);
break;
}
#ifdef DEBUG
proto_tree_add_protocol_format(csper_tree, proto_wimax_utility_decoders, tvb, offset, (tlv_len+2+get_tlv_size_of_length(&tlv_info)), "PHS Rule TLV Type: %u (%u bytes, offset=%u, tlv_len=%u)", tlv_type, length, offset, tlv_len);
#endif
switch (tlv_type)
{
case CST_PHS_PHSI:
add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_phs_phsi, tvb, tlv_offset, ENC_BIG_ENDIAN);
break;
case CST_PHS_PHSF:
add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_phs_phsf, tvb, tlv_offset, ENC_NA);
break;
case CST_PHS_PHSM:
add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_phs_phsm, tvb, tlv_offset, ENC_NA);
break;
case CST_PHS_PHSS:
add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_phs_phss, tvb, tlv_offset, ENC_BIG_ENDIAN);
break;
case CST_PHS_PHSV:
add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_phs_phsv, tvb, tlv_offset, ENC_BIG_ENDIAN);
break;
case CST_PHS_VENDOR_SPEC:
add_tlv_subtree(&tlv_info, tlv_tree, hf_cst_phs_vendor_spec, tvb, tlv_offset, ENC_NA);
break;
}
tlv_offset += (length+get_tlv_value_offset(&tlv_info));
}
break;
}
default:
add_tlv_subtree(&tlv_info, tree, hf_csper_unknown_type, tvb, offset-get_tlv_value_offset(&tlv_info), ENC_NA);
break;
}
}
offset += tlv_len;
}
}
void wimax_service_flow_encodings_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset, i;
guint tvb_len, tlv_len, tlv_value_offset, tlv_value;
gint tlv_type;
guint value;
proto_item *tlv_item = NULL;
proto_tree *tlv_tree = NULL;
tlv_info_t tlv_info;
tvb_len = tvb_reported_length(tvb);
#ifdef DEBUG
proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, 0, tvb_len, "WiMax Service Flow Encodings (%u bytes)", tvb_len);
#endif
offset = 0;
if(!tvb_len)
return;
if(tvb_len < 2)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Invalid Service Flow Encodings");
return;
}
while(offset < tvb_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Service Flow Encodings TLV error");
proto_tree_add_item(tree, hf_cst_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, offset, (tlv_len + tlv_value_offset), "Service Flow Encodings TLV Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, tlv_len, offset, tvb_len);
#endif
offset += tlv_value_offset;
switch (tlv_type)
{
case SFE_SF_ID:
add_tlv_subtree(&tlv_info, tree, hf_sfe_sf_id, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_CID:
add_tlv_subtree(&tlv_info, tree, hf_sfe_cid, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_SERVICE_CLASS_NAME:
add_tlv_subtree(&tlv_info, tree, hf_sfe_service_class_name, tvb, offset-tlv_value_offset, ENC_ASCII|ENC_NA);
break;
case SFE_MBS_SERVICE:
add_tlv_subtree(&tlv_info, tree, hf_sfe_mbs_service, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_QOS_PARAMS_SET:
tlv_item = add_tlv_subtree(&tlv_info, tree, hf_sfe_qos_params_set, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_wimax_service_flow_encodings);
proto_tree_add_item(tlv_tree, hf_sfe_set_provisioned, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sfe_set_admitted, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sfe_set_active, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sfe_set_rsvd, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SFE_TRAFFIC_PRIORITY:
tlv_item = add_tlv_subtree(&tlv_info, tree, hf_sfe_traffic_priority, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item, " (allowed values are 0-7)");
break;
case SFE_MAX_STR:
add_tlv_subtree(&tlv_info, tree, hf_sfe_max_str, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_MAX_TRAFFIC_BURST:
add_tlv_subtree(&tlv_info, tree, hf_sfe_max_traffic_burst, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_MIN_RTR:
add_tlv_subtree(&tlv_info, tree, hf_sfe_min_rtr, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_RESERVED_10:
add_tlv_subtree(&tlv_info, tree, hf_sfe_reserved_10, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_UL_SCHEDULING:
tlv_value = tvb_get_guint8(tvb, offset);
set_service_type( tlv_value );
add_tlv_subtree(&tlv_info, tree, hf_sfe_ul_grant_scheduling, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_TX_POLICY:
tlv_item = add_tlv_subtree(&tlv_info, tree, hf_sfe_req_tx_policy, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_wimax_service_flow_encodings);
proto_tree_add_item(tlv_tree, hf_sfe_policy_broadcast_bwr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sfe_policy_multicast_bwr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sfe_policy_piggyback, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sfe_policy_fragment, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sfe_policy_headers, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sfe_policy_packing, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sfe_policy_crc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sfe_policy_rsvd1, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SFE_TOLERATED_JITTER:
add_tlv_subtree(&tlv_info, tree, hf_sfe_jitter, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_MAX_LATENCY:
add_tlv_subtree(&tlv_info, tree, hf_sfe_max_latency, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_FIXED_LEN_SDU:
add_tlv_subtree(&tlv_info, tree, hf_sfe_fixed_len_sdu, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_SDU_SIZE:
mac_sdu_length = tvb_get_guint8(tvb, offset);
add_tlv_subtree(&tlv_info, tree, hf_sfe_sdu_size, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_TARGET_SAID:
add_tlv_subtree(&tlv_info, tree, hf_sfe_target_said, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_ARQ_ENABLE:
add_tlv_subtree(&tlv_info, tree, hf_sfe_arq_enable, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_ARQ_WINDOW_SIZE:
add_tlv_subtree(&tlv_info, tree, hf_sfe_arq_window_size, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_ARQ_TRANSMITTER_DELAY:
if (include_cor2_changes)
{
add_tlv_subtree(&tlv_info, tree, hf_sfe_arq_transmitter_delay_cor2, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
}
else
{
add_tlv_subtree(&tlv_info, tree, hf_sfe_arq_transmitter_delay, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
}
break;
case SFE_ARQ_RECEIVER_DELAY:
if (include_cor2_changes)
{
add_tlv_subtree(&tlv_info, tree, hf_sfe_arq_receiver_delay_cor2, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
}
else
{
add_tlv_subtree(&tlv_info, tree, hf_sfe_arq_receiver_delay, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
}
break;
case SFE_ARQ_BLOCK_LIFETIME:
if (include_cor2_changes)
{
add_tlv_subtree(&tlv_info, tree, hf_sfe_arq_block_lifetime_cor2, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
}
else
{
add_tlv_subtree(&tlv_info, tree, hf_sfe_arq_block_lifetime, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
}
break;
case SFE_ARQ_SYNC_LOSS_TIMEOUT:
if (include_cor2_changes)
{
add_tlv_subtree(&tlv_info, tree, hf_sfe_arq_sync_loss_timeout_cor2, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
}
else
{
add_tlv_subtree(&tlv_info, tree, hf_sfe_arq_sync_loss_timeout, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
}
break;
case SFE_ARQ_DELIVER_IN_ORDER:
add_tlv_subtree(&tlv_info, tree, hf_sfe_arq_deliver_in_order, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_ARQ_RX_PURGE_TIMEOUT:
add_tlv_subtree(&tlv_info, tree, hf_sfe_arq_rx_purge_timeout, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_ARQ_BLOCK_SIZE:
if (include_cor2_changes)
{
tlv_item = add_tlv_subtree(&tlv_info, tree, hf_sfe_arq_block_size_cor2, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_wimax_service_flow_encodings);
value = tvb_get_guint8(tvb, offset);
tlv_item = proto_tree_add_item(tlv_tree, hf_sfe_arq_min_block_size, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item, " ( %d bytes )", 0x10 << (value & 0x0F));
tlv_item = proto_tree_add_item(tlv_tree, hf_sfe_arq_max_block_size, tvb, offset, 1, ENC_BIG_ENDIAN);
if (value & 0xF0)
proto_item_append_text(tlv_item, " ( %d bytes )", 0x10 << ((value & 0xF0) >> 4));
}
else
{
add_tlv_subtree(&tlv_info, tree, hf_sfe_arq_block_size, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
}
break;
case SFE_CS_SPECIFICATION:
add_tlv_subtree(&tlv_info, tree, hf_sfe_cs_specification, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_TYPE_OF_DATA_DELIVERY_SERVICES:
add_tlv_subtree(&tlv_info, tree, hf_sfe_type_of_data_delivery_services, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_SDU_INTER_ARRIVAL_INTERVAL:
add_tlv_subtree(&tlv_info, tree, hf_sfe_sdu_inter_arrival_interval, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_TIME_BASE:
add_tlv_subtree(&tlv_info, tree, hf_sfe_time_base, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_PAGING_PREFERENCE:
add_tlv_subtree(&tlv_info, tree, hf_sfe_paging_preference, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_MBS_ZONE_IDENTIFIER_ASSIGNMENT:
add_tlv_subtree(&tlv_info, tree, hf_sfe_mbs_zone_identifier_assignment, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_RESERVED_34:
add_tlv_subtree(&tlv_info, tree, hf_sfe_reserved_34, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_GLOBAL_SERVICE_CLASS_NAME:
add_tlv_subtree(&tlv_info, tree, hf_sfe_global_service_class_name, tvb, offset-tlv_value_offset, ENC_ASCII|ENC_NA);
break;
case SFE_RESERVED_36:
add_tlv_subtree(&tlv_info, tree, hf_sfe_reserved_36, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_SN_FEEDBACK_ENABLED:
add_tlv_subtree(&tlv_info, tree, hf_sfe_sn_feedback_enabled, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_FSN_SIZE:
add_tlv_subtree(&tlv_info, tree, hf_sfe_fsn_size, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_CID_ALLOCATION_FOR_ACTIVE_BS:
tlv_item = add_tlv_subtree(&tlv_info, tree, hf_sfe_cid_alloc_for_active_bs_cid, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_wimax_service_flow_encodings);
for(i = 0; i < tlv_len; i+=2)
proto_tree_add_item(tlv_tree, hf_sfe_cid_alloc_for_active_bs_cid, tvb, (offset+i), 2, ENC_BIG_ENDIAN);
break;
case SFE_UNSOLICITED_GRANT_INTERVAL:
add_tlv_subtree(&tlv_info, tree, hf_sfe_unsolicited_grant_interval, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_UNSOLOCITED_POLLING_INTERVAL:
add_tlv_subtree(&tlv_info, tree, hf_sfe_unsolicited_polling_interval, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_PDU_SN_EXT_SUBHEADER_HARQ_REORDER:
add_tlv_subtree(&tlv_info, tree, hf_sfe_pdu_sn_ext_subheader_reorder, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_MBS_CONTENTS_ID:
tlv_item = add_tlv_subtree(&tlv_info, tree, hf_sfe_mbs_contents_ids, tvb, offset-tlv_value_offset, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_wimax_service_flow_encodings);
for(i = 0; i < tlv_len; i+=2)
proto_tree_add_item(tlv_tree, hf_sfe_mbs_contents_ids_id, tvb, (offset+i), 2, ENC_BIG_ENDIAN);
break;
case SFE_HARQ_SERVICE_FLOWS:
add_tlv_subtree(&tlv_info, tree, hf_sfe_harq_service_flows, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case SFE_AUTHORIZATION_TOKEN:
add_tlv_subtree(&tlv_info, tree, hf_sfe_authorization_token, tvb, offset-tlv_value_offset, ENC_NA);
break;
case SFE_HARQ_CHANNEL_MAPPING:
tlv_item = add_tlv_subtree(&tlv_info, tree, hf_sfe_harq_channel_mapping_index, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_wimax_service_flow_encodings);
for(i = 0; i < tlv_len; i++)
proto_tree_add_item(tlv_tree, hf_sfe_harq_channel_mapping_index, tvb, (offset+i), 1, ENC_BIG_ENDIAN);
break;
case SFE_CSPER_ATM:
case SFE_CSPER_PACKET_IPV4:
case SFE_CSPER_PACKET_IPV6:
case SFE_CSPER_PACKET_802_3:
case SFE_CSPER_PACKET_802_1Q:
case SFE_CSPER_PACKET_IPV4_802_3:
case SFE_CSPER_PACKET_IPV6_802_3:
case SFE_CSPER_PACKET_IPV4_802_1Q:
case SFE_CSPER_PACKET_IPV6_802_1Q:
case SFE_CSPER_PACKET_IP_ROCH_COMPRESSION:
case SFE_CSPER_PACKET_IP_ECRTP_COMPRESSION:
case SFE_CSPER_PACKET_IP_802_3_ROCH_COMPRESSION:
case SFE_CSPER_PACKET_IP_802_3_ECRTP_COMPRESSION:
tlv_tree = add_protocol_subtree(&tlv_info, ett_wimax_service_flow_encodings, tree, proto_wimax_utility_decoders, tvb, offset-tlv_value_offset, tlv_len, "CS Parameter Encoding Rules");
wimax_convengence_service_parameter_encoding_rules_decoder(tlv_type, tvb_new_subset_length(tvb, offset, tlv_len), pinfo, tlv_tree);
break;
default:
add_tlv_subtree(&tlv_info, tree, hf_sfe_unknown_type, tvb, offset-tlv_value_offset, ENC_NA);
break;
}
offset += tlv_len;
}
}
void wimax_hmac_tuple_decoder(proto_tree *tree, tvbuff_t *tvb, guint offset, guint length)
{
guint hmac_offset;
proto_item *hmac_item = NULL;
proto_tree *hmac_tree = NULL;
hmac_item = proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, offset, length, "HMAC Tuple (%u bytes)", length);
hmac_tree = proto_item_add_subtree(hmac_item, ett_wimax_hmac_tuple);
hmac_offset = offset;
proto_tree_add_item(hmac_tree, hf_xmac_tuple_rsvd, tvb, hmac_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(hmac_tree, hf_xmac_tuple_key_seq_num, tvb, hmac_offset, 1, ENC_BIG_ENDIAN);
hmac_offset++;
proto_tree_add_item(hmac_tree, hf_hmac_tuple_hmac_digest, tvb, hmac_offset, (length-1), ENC_NA);
}
void wimax_cmac_tuple_decoder(proto_tree *tree, tvbuff_t *tvb, guint offset, guint length)
{
guint cmac_offset;
proto_item *cmac_item = NULL;
proto_tree *cmac_tree = NULL;
cmac_item = proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, offset, length, "CMAC Tuple (%u bytes)", length);
cmac_tree = proto_item_add_subtree(cmac_item, ett_wimax_cmac_tuple);
cmac_offset = offset;
proto_tree_add_item(cmac_tree, hf_xmac_tuple_rsvd, tvb, cmac_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cmac_tree, hf_xmac_tuple_key_seq_num, tvb, cmac_offset, 1, ENC_BIG_ENDIAN);
cmac_offset++;
if(length > 13)
{
proto_tree_add_item(cmac_tree, hf_cmac_tuple_bsid, tvb, cmac_offset, 6, ENC_NA);
cmac_offset += 6;
}
proto_tree_add_item(cmac_tree, hf_packet_number_counter, tvb, cmac_offset, 4, ENC_BIG_ENDIAN);
cmac_offset += 4;
proto_tree_add_item(cmac_tree, hf_cmac_tuple_cmac_value, tvb, cmac_offset, 8, ENC_NA);
}
void wimax_short_hmac_tuple_decoder(proto_tree *tree, tvbuff_t *tvb, guint offset, guint length)
{
guint hmac_offset;
proto_item *hmac_item = NULL;
proto_tree *hmac_tree = NULL;
hmac_item = proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, offset, length, "Short-HMAC Tuple (%u bytes)", length);
hmac_tree = proto_item_add_subtree(hmac_item, ett_wimax_short_hmac_tuple);
hmac_offset = offset;
proto_tree_add_item(hmac_tree, hf_xmac_tuple_rsvd, tvb, hmac_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(hmac_tree, hf_xmac_tuple_key_seq_num, tvb, hmac_offset, 1, ENC_BIG_ENDIAN);
hmac_offset++;
proto_tree_add_item(hmac_tree, hf_packet_number_counter, tvb, hmac_offset, 4, ENC_BIG_ENDIAN);
hmac_offset += 4;
proto_tree_add_item(hmac_tree, hf_hmac_tuple_hmac_digest, tvb, hmac_offset, length - offset - 3, ENC_NA);
}
void wimax_security_negotiation_parameters_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset;
guint tvb_len, tlv_len, tlv_value_offset;
gint tlv_type;
proto_tree *tlv_tree;
proto_item *tlv_item;
tlv_info_t tlv_info;
tvb_len = tvb_reported_length(tvb);
if(!tvb_len)
return;
if(tvb_len < 2)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Invalid Security Negotiation Parameters");
return;
}
for(offset = 0; offset < tvb_len; )
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Security Negotiation Params TLV error");
proto_tree_add_item(tree, hf_cst_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, offset, (tlv_len + tlv_value_offset), "Security Negotiation Parameters Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, (tlv_len + tlv_value_offset), offset, tvb_len);
#endif
offset += tlv_value_offset;
switch (tlv_type)
{
case PKM_ATTR_SECURITY_NEGOTIATION_PARAMETER_SUB_PKM_VERSION_SUPPORT:
tlv_item = add_tlv_subtree(&tlv_info, tree, hf_snp_pkm_version_support, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_security_negotiation_parameters);
proto_tree_add_item(tlv_tree, hf_snp_pkm_version_support_bit0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_snp_pkm_version_support_bit1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_snp_pkm_version_support_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_SECURITY_NEGOTIATION_PARAMETER_SUB_AUTHORIZATION_POLICY_SUPPORT:
tlv_item = add_tlv_subtree(&tlv_info, tree, hf_snp_auth_policy_support, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_security_negotiation_parameters);
proto_tree_add_item(tlv_tree, hf_snp_auth_policy_support_bit0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_snp_auth_policy_support_bit1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_snp_auth_policy_support_bit2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_snp_auth_policy_support_bit3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_snp_auth_policy_support_bit4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_snp_auth_policy_support_bit5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_snp_auth_policy_support_bit6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_snp_auth_policy_support_bit7, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_SECURITY_NEGOTIATION_PARAMETER_SUB_MESSAGE_AUTHENTICATION_CODE:
tlv_item = add_tlv_subtree(&tlv_info, tree, hf_snp_mac_mode, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_security_negotiation_parameters);
proto_tree_add_item(tlv_tree, hf_snp_mac_mode_bit0, tvb, offset, 1, ENC_BIG_ENDIAN);
if (include_cor2_changes)
{
proto_tree_add_item(tlv_tree, hf_snp_mac_mode_bit1_rsvd, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tlv_tree, hf_snp_mac_mode_bit1, tvb, offset, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tlv_tree, hf_snp_mac_mode_bit2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_snp_mac_mode_bit3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_snp_mac_mode_bit4, tvb, offset, 1, ENC_BIG_ENDIAN);
if (include_cor2_changes)
{
proto_tree_add_item(tlv_tree, hf_snp_mac_mode_bit5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_snp_mac_mode_reserved1, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tlv_tree, hf_snp_mac_mode_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
}
break;
case PKM_ATTR_SECURITY_NEGOTIATION_PARAMETER_SUB_PN_WINDOW_SIZE:
add_tlv_subtree(&tlv_info, tree, hf_snp_pn_window_size, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_SECURITY_NEGOTIATION_PARAMETER_SUB_PKM_FLOW_CONTROL:
add_tlv_subtree(&tlv_info, tree, hf_snp_max_conc_transactions, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_SECURITY_NEGOTIATION_PARAMETER_SUB_MAX_SUPPT_SECURITY_ASSNS:
add_tlv_subtree(&tlv_info, tree, hf_snp_max_suppt_sec_assns, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
default:
add_tlv_subtree(&tlv_info, tree, hf_snp_unknown_type, tvb, offset-tlv_value_offset, ENC_NA);
break;
}
offset += tlv_len;
}
}
void wimax_cryptographic_suite_list_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset;
guint tvb_len, tlv_len, tlv_value_offset;
gint tlv_type;
proto_tree *tlv_tree;
proto_item *tlv_item;
tlv_info_t tlv_info;
tvb_len = tvb_reported_length(tvb);
if(!tvb_len)
return;
if(tvb_len < 2)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Invalid Crypto Suite List");
return;
}
for(offset = 0; offset < tvb_len; )
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Crypto Suite List TLV error");
proto_tree_add_item(tree, hf_cst_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, offset, (tlv_len + tlv_value_offset), "Cryptographic Suite List TLV Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, (tlv_len + tlv_value_offset), offset, tvb_len);
#endif
offset += tlv_value_offset;
switch (tlv_type)
{
case PKM_ATTR_CRYPTO_SUITE:
tlv_item = add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_crypto_suite, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_cryptographic_suite_list_decoder);
proto_tree_add_item(tlv_tree, hf_pkm_msg_crypto_suite_msb, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_pkm_msg_crypto_suite_middle, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_pkm_msg_crypto_suite_lsb, tvb, offset+2, 1, ENC_BIG_ENDIAN);
break;
default:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_unknown_type, tvb, offset-tlv_value_offset, ENC_NA);
break;
}
offset += tlv_len;
}
}
void wimax_pkm_tlv_encoded_attributes_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset;
guint tvb_len, tlv_len, tlv_value_offset;
gint tlv_type;
proto_tree *tlv_tree;
proto_item *tlv_item;
tlv_info_t tlv_info;
tvb_len = tvb_reported_length(tvb);
if(!tvb_len)
return;
if(tvb_len < 2)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Invalid PKM TLV");
return;
}
for(offset = 0; offset < tvb_len; )
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "PKM TLV error");
proto_tree_add_item(tree, hf_cst_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, offset, (tlv_len + tlv_value_offset), "PKM TLV Encoded Attributes TLV Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, (tlv_len + tlv_value_offset), offset, tvb_len);
#endif
offset += tlv_value_offset;
switch (tlv_type)
{
case PKM_ATTR_DISPLAY_STRING:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_display, tvb, offset-tlv_value_offset, ENC_ASCII|ENC_NA);
break;
case PKM_ATTR_AUTH_KEY:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_auth_key, tvb, offset-tlv_value_offset, ENC_NA);
break;
case PKM_ATTR_TEK:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_tek, tvb, offset-tlv_value_offset, ENC_NA);
break;
case PKM_ATTR_KEY_LIFE_TIME:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_key_life_time, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_KEY_SEQ_NUM:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_key_seq_num, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_HMAC_DIGEST:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_hmac_digest, tvb, offset-tlv_value_offset, ENC_NA);
break;
case PKM_ATTR_SAID:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_said, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_TEK_PARAM:
tlv_tree = add_protocol_subtree(&tlv_info, ett_pkm_tlv_encoded_attributes_decoder, tree, proto_wimax_utility_decoders, tvb, offset-tlv_value_offset, tlv_len, "TEK Parameters");
wimax_tek_parameters_decoder(tvb_new_subset_length(tvb, offset, tlv_len), pinfo, tlv_tree);
break;
case PKM_ATTR_CBC_IV:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_cbc_iv, tvb, offset-tlv_value_offset, ENC_NA);
break;
case PKM_ATTR_ERROR_CODE:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_error_code, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_CA_CERTIFICATE:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_ca_certificate, tvb, offset-tlv_value_offset, ENC_NA);
break;
case PKM_ATTR_SS_CERTIFICATE:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_ss_certificate, tvb, offset-tlv_value_offset, ENC_NA);
break;
case PKM_ATTR_SECURITY_CAPABILITIES:
tlv_tree = add_protocol_subtree(&tlv_info, ett_pkm_tlv_encoded_attributes_decoder, tree, proto_wimax_utility_decoders, tvb, offset-tlv_value_offset, tlv_len, "Security Capabilities");
wimax_security_capabilities_decoder(tvb_new_subset_length(tvb, offset, tlv_len), pinfo, tlv_tree);
break;
case PKM_ATTR_CRYPTO_SUITE:
tlv_item = add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_crypto_suite, tvb, offset-tlv_value_offset, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_pkm_tlv_encoded_attributes_decoder);
proto_tree_add_item(tlv_tree, hf_pkm_msg_crypto_suite_msb, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_pkm_msg_crypto_suite_middle, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_pkm_msg_crypto_suite_lsb, tvb, offset+2, 1, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_CRYPTO_LIST:
tlv_tree = add_protocol_subtree(&tlv_info, ett_pkm_tlv_encoded_attributes_decoder, tree, proto_wimax_utility_decoders, tvb, offset-tlv_value_offset, tlv_len, "Cryptographic-Suite List");
wimax_cryptographic_suite_list_decoder(tvb_new_subset_length(tvb, offset, tlv_len), pinfo, tlv_tree);
break;
#if 0
case PKM_ATTR_VERSION:
proto_tree_add_item(tree, hf_pkm_msg_version, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
#endif
case PKM_ATTR_SA_DESCRIPTOR:
tlv_tree = add_protocol_subtree(&tlv_info, ett_pkm_tlv_encoded_attributes_decoder, tree, proto_wimax_utility_decoders, tvb, offset-tlv_value_offset, tlv_len, "SA-Descriptor");
wimax_sa_descriptor_decoder(tvb_new_subset_length(tvb, offset, tlv_len), pinfo, tlv_tree);
break;
case PKM_ATTR_SA_TYPE:
add_tlv_subtree(&tlv_info, tree, hf_pkm_sa_type, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_SECURITY_NEGOTIATION_PARAMETERS:
tlv_tree = add_protocol_subtree(&tlv_info, ett_pkm_tlv_encoded_attributes_decoder, tree, proto_wimax_utility_decoders, tvb, offset-tlv_value_offset, tlv_len, "Security Negotiation Parameters");
wimax_security_negotiation_parameters_decoder(tvb_new_subset_length(tvb, offset, tlv_len), pinfo, tlv_tree);
break;
case PKM_ATTR_PKM_CONFIG_SETTINGS:
tlv_tree = add_protocol_subtree(&tlv_info, ett_pkm_tlv_encoded_attributes_decoder, tree, proto_wimax_utility_decoders, tvb, offset-tlv_value_offset, tlv_len, "PKM Configuration Settings");
wimax_pkm_configuration_settings_decoder(tvb_new_subset_length(tvb, offset, tlv_len), pinfo, tlv_tree);
break;
case PKM_ATTR_PKM_EAP_PAYLOAD:
tlv_item = add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_eap_payload, tvb, offset-tlv_value_offset, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_pkm_tlv_encoded_attributes_decoder);
if (eap_handle)
call_dissector(eap_handle, tvb_new_subset_length(tvb, offset, tlv_len), pinfo, tlv_tree);
break;
case PKM_ATTR_PKM_NONCE:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_nonce, tvb, offset-tlv_value_offset, ENC_NA);
break;
case PKM_ATTR_AUTH_RESULT_CODE:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_auth_result_code, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_SA_SERVICE_TYPE:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_sa_service_type, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_FRAME_NUMBER:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_frame_number, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_SS_RANDOM:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_ss_random, tvb, offset-tlv_value_offset, ENC_NA);
break;
case PKM_ATTR_BS_RANDOM:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_bs_random, tvb, offset-tlv_value_offset, ENC_NA);
break;
case PKM_ATTR_PRE_PAK:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_pre_pak, tvb, offset-tlv_value_offset, ENC_NA);
break;
case PKM_ATTR_BS_CERTIFICATE:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_bs_certificate, tvb, offset-tlv_value_offset, ENC_NA);
break;
case PKM_ATTR_SIG_BS:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_sig_bs, tvb, offset-tlv_value_offset, ENC_NA);
break;
case PKM_ATTR_MS_MAC_ADDRESS:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_ms_mac_address, tvb, offset-tlv_value_offset, ENC_NA);
break;
case PKM_ATTR_CMAC_DIGEST:
tlv_item = add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_cmac_digest, tvb, offset-tlv_value_offset, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_pkm_tlv_encoded_attributes_decoder);
proto_tree_add_item(tlv_tree, hf_pkm_attr_cmac_digest_pn, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_pkm_attr_cmac_digest_value, tvb, (offset + 4), 8, ENC_NA);
break;
case PKM_ATTR_KEY_PUSH_MODES:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_push_modes, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_KEY_PUSH_COUNTER:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_key_push_counter, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_GKEK:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_gkek, tvb, offset-tlv_value_offset, ENC_NA);
break;
case PKM_ATTR_SIG_SS:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_sig_ss, tvb, offset-tlv_value_offset, ENC_NA);
break;
case PKM_ATTR_AKID:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_akid, tvb, offset-tlv_value_offset, ENC_NA);
break;
default:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_unknown_type, tvb, offset-tlv_value_offset, ENC_NA);
break;
}
offset += tlv_len;
}
}
void wimax_tek_parameters_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset;
guint tvb_len, tlv_len, tlv_value_offset;
gint tlv_type;
tlv_info_t tlv_info;
tvb_len = tvb_reported_length(tvb);
if(!tvb_len)
return;
if(tvb_len < 2)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Invalid TEK Params");
return;
}
for(offset = 0; offset < tvb_len; )
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "TEK Param TLV error");
proto_tree_add_item(tree, hf_cst_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, offset, (tlv_len + tlv_value_offset), "TEK Parameters Subattributes TLV Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, (tlv_len + tlv_value_offset), offset, tvb_len);
#endif
switch (tlv_type)
{
case PKM_ATTR_TEK:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_tek, tvb, offset, ENC_NA);
break;
case PKM_ATTR_KEY_LIFE_TIME:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_key_life_time, tvb, offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_KEY_SEQ_NUM:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_key_seq_num, tvb, offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_CBC_IV:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_cbc_iv, tvb, offset, ENC_NA);
break;
case PKM_ATTR_ASSOCIATED_GKEK_SEQ_NUM:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_associated_gkek_seq_number, tvb, offset, ENC_NA);
break;
default:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_unknown_type, tvb, offset, ENC_NA);
break;
}
offset += (tlv_len+tlv_value_offset);
}
}
void wimax_pkm_configuration_settings_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset;
guint tvb_len, tlv_len, tlv_value_offset;
gint tlv_type;
tlv_info_t tlv_info;
tvb_len = tvb_reported_length(tvb);
if(!tvb_len)
return;
if(tvb_len < 2)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Invalid PKM Config Settings");
return;
}
for(offset = 0; offset < tvb_len; )
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "PKM Config Settings TLV error");
proto_tree_add_item(tree, hf_cst_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, offset, (tlv_len + tlv_value_offset), "PKM Configuration Settings TLV Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, (tlv_len + tlv_value_offset), offset, tvb_len);
#endif
switch (tlv_type)
{
case PKM_ATTR_PKM_CONFIG_SETTINGS_AUTHORIZE_WAIT_TIMEOUT:
add_tlv_subtree(&tlv_info, tree, hf_pkm_config_settings_authorize_waitout, tvb, offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_PKM_CONFIG_SETTINGS_REAUTHORIZE_WAIT_TIMEOUT:
add_tlv_subtree(&tlv_info, tree, hf_pkm_config_settings_reauthorize_waitout, tvb, offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_PKM_CONFIG_SETTINGS_AUTHORIZATION_GRACE_TIME:
add_tlv_subtree(&tlv_info, tree, hf_pkm_config_settings_grace_time, tvb, offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_PKM_CONFIG_SETTINGS_OPERATIONAL_WAIT_TIMEOUT:
add_tlv_subtree(&tlv_info, tree, hf_pkm_config_settings_operational_waittime, tvb, offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_PKM_CONFIG_SETTINGS_REKEY_WAIT_TIMEOUT:
add_tlv_subtree(&tlv_info, tree, hf_pkm_config_settings_rekey_wait_timeout, tvb, offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_PKM_CONFIG_SETTINGS_TEK_GRACE_TIME:
add_tlv_subtree(&tlv_info, tree, hf_pkm_config_settings_tek_grace_time, tvb, offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_PKM_CONFIG_SETTINGS_AUTHORIZE_REJECT_WAIT_TIMEOUT:
add_tlv_subtree(&tlv_info, tree, hf_pkm_config_settings_authorize_reject_wait_timeout, tvb, offset, ENC_BIG_ENDIAN);
break;
default:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_unknown_type, tvb, offset, ENC_NA);
break;
}
offset += (tlv_len+tlv_value_offset);
}
}
void wimax_sa_descriptor_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset;
guint tvb_len, tlv_len, tlv_value_offset;
gint tlv_type;
proto_tree *tlv_tree;
proto_item *tlv_item;
tlv_info_t tlv_info;
tvb_len = tvb_reported_length(tvb);
if(!tvb_len)
return;
if(tvb_len < 2)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Invalid SA-Descriptor");
return;
}
for(offset = 0; offset < tvb_len; )
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "SA-Descriptor TLV error");
proto_tree_add_item(tree, hf_cst_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, offset, (tlv_len + tlv_value_offset), "SA-Descriptor TLV Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, (tlv_len + tlv_value_offset), offset, tvb_len);
#endif
offset += tlv_value_offset;
switch (tlv_type)
{
case PKM_ATTR_SAID:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_attr_said, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_SA_TYPE:
add_tlv_subtree(&tlv_info, tree, hf_pkm_sa_type, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_SA_SERVICE_TYPE:
add_tlv_subtree(&tlv_info, tree, hf_pkm_attr_sa_service_type, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_CRYPTO_SUITE:
tlv_item = add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_crypto_suite, tvb, offset-tlv_value_offset, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_sa_descriptor_decoder);
proto_tree_add_item(tlv_tree, hf_pkm_msg_crypto_suite_msb, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_pkm_msg_crypto_suite_middle, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_pkm_msg_crypto_suite_lsb, tvb, offset+2, 1, ENC_BIG_ENDIAN);
break;
default:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_unknown_type, tvb, offset-tlv_value_offset, ENC_NA);
break;
}
offset += tlv_len;
}
}
void wimax_security_capabilities_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset;
guint tvb_len, tlv_len, tlv_value_offset;
gint tlv_type;
proto_tree *tlv_tree = NULL;
tlv_info_t tlv_info;
tvb_len = tvb_reported_length(tvb);
if(!tvb_len)
return;
if(tvb_len < 2)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Invalid Security Capabilities");
return;
}
for(offset = 0; offset < tvb_len; )
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Security Capabilities TLV error");
proto_tree_add_item(tree, hf_cst_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, offset, (tlv_len + tlv_value_offset), "Security Capabilities TLV Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, (tlv_len + tlv_value_offset), offset, tvb_len);
#endif
switch (tlv_type)
{
case PKM_ATTR_CRYPTO_LIST:
tlv_tree = add_protocol_subtree(&tlv_info, ett_security_capabilities_decoder, tree, proto_wimax_utility_decoders, tvb, offset, tlv_len, "Cryptographic-Suite List");
wimax_cryptographic_suite_list_decoder(tvb_new_subset_length(tvb, offset, tlv_len), pinfo, tlv_tree);
break;
default:
add_tlv_subtree(&tlv_info, tree, hf_pkm_msg_unknown_type, tvb, offset, ENC_NA);
break;
}
offset += (tlv_len+tlv_value_offset);
}
}
void wimax_vendor_specific_information_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset;
guint tvb_len, tlv_len, tlv_value_offset;
gint tlv_type;
tlv_info_t tlv_info;
tvb_len = tvb_reported_length(tvb);
if(!tvb_len)
return;
if(tvb_len < 2)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Invalid Vendor Specific Info");
proto_tree_add_expert(tree, pinfo, &ei_common_tlv_info, tvb, 0, tvb_len);
return;
}
for(offset = 0; offset < tvb_len; )
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Vendor Specific Info TLV error");
proto_tree_add_item(tree, hf_cst_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, offset, (tlv_len + tlv_value_offset), "Vendor Specific Info TLV Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, (tlv_len + tlv_value_offset), offset, tvb_len);
#endif
if(tlv_type == VENDOR_ID_ENCODING)
{
add_tlv_subtree(&tlv_info, tree, hf_common_tlv_vendor_id, tvb, offset, ENC_NA);
}
else
{
proto_tree_add_item(tree, hf_common_tlv_vendor_specific_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if(get_tlv_length_type(&tlv_info) == 0)
{
proto_tree_add_item(tree, hf_common_tlv_vendor_specific_length, tvb, (offset + 1), 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_common_tlv_vendor_specific_length_size, tvb, (offset + 1), 1, ENC_BIG_ENDIAN);
if(get_tlv_size_of_length(&tlv_info))
{
proto_tree_add_uint(tree, hf_common_tlv_vendor_specific_length, tvb, (offset + 2), 1, get_tlv_size_of_length(&tlv_info));
}
else
{
continue;
}
}
proto_tree_add_item(tree, hf_common_tlv_vendor_specific_value, tvb, (offset + tlv_value_offset), tlv_len, ENC_NA);
}
offset += tlv_value_offset + tlv_len;
}
}
guint wimax_common_tlv_encoding_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset, value;
guint tvb_len, tlv_len, tlv_value_offset;
gint tlv_type;
proto_tree *tlv_tree = NULL;
tlv_info_t tlv_info;
gfloat current_power;
tvb_len = tvb_reported_length(tvb);
if(!tvb_len)
return 0;
if(tvb_len < 2)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Invalid Common TLV encoding");
proto_tree_add_item(tree, hf_cst_invalid_tlv, tvb, 0, tvb_len, ENC_NA);
return 0;
}
for(offset = 0; offset < tvb_len; )
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Common TLV encoding TLV error");
proto_tree_add_item(tree, hf_cst_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(tree, proto_wimax_utility_decoders, tvb, offset, (tlv_len + tlv_value_offset), "Common TLV Encoding TLV Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, (tlv_len + tlv_value_offset), offset, tvb_len);
#endif
offset += tlv_value_offset;
switch (tlv_type)
{
case VENDOR_SPECIFIC_INFO:
tlv_tree = add_protocol_subtree(&tlv_info, ett_vendor_specific_info_decoder, tree, proto_wimax_utility_decoders, tvb, offset-tlv_value_offset, tlv_len, "Vendor-Specific Information");
wimax_vendor_specific_information_decoder(tvb_new_subset_length(tvb, offset, tlv_len), pinfo, tlv_tree);
break;
case VENDOR_ID_ENCODING:
add_tlv_subtree(&tlv_info, tree, hf_common_tlv_vendor_id, tvb, offset-tlv_value_offset, ENC_NA);
break;
case DSx_UPLINK_FLOW:
tlv_tree = add_protocol_subtree(&tlv_info, ett_ul_service_flow_decoder, tree, proto_wimax_utility_decoders, tvb, offset-tlv_value_offset, tlv_len, "Uplink Service Flow Encodings");
wimax_service_flow_encodings_decoder(tvb_new_subset_length(tvb, offset, tlv_len), pinfo, tlv_tree);
break;
case DSx_DOWNLINK_FLOW:
tlv_tree = add_protocol_subtree(&tlv_info, ett_dl_service_flow_decoder, tree, proto_wimax_utility_decoders, tvb, offset-tlv_value_offset, tlv_len, "Downlink Service Flow Encodings");
wimax_service_flow_encodings_decoder(tvb_new_subset_length(tvb,offset, tlv_len), pinfo, tlv_tree);
break;
case CURRENT_TX_POWER:
tlv_tree = add_tlv_subtree_no_item(&tlv_info, tree, hf_common_current_transmitted_power, tvb, offset-tlv_value_offset);
value = tvb_get_guint8(tvb, offset);
current_power = (gfloat)((value - 128) / 2.0);
proto_tree_add_float_format_value(tlv_tree, hf_common_current_transmitted_power, tvb, offset, tvb_len, current_power, "%.2f dBm (Value: 0x%x)", current_power, value);
break;
case MAC_VERSION_ENCODING:
add_tlv_subtree(&tlv_info, tree, hf_common_tlv_mac_version, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
case HMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_vendor_specific_info_decoder, tree, proto_wimax_utility_decoders, tvb, offset-tlv_value_offset, tlv_len, "HMAC Tuple");
wimax_hmac_tuple_decoder(tlv_tree, tvb, offset, tlv_len);
break;
case CMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_vendor_specific_info_decoder, tree, proto_wimax_utility_decoders, tvb, offset-tlv_value_offset, tlv_len, "CMAC Tuple");
wimax_cmac_tuple_decoder(tlv_tree, tvb, offset, tlv_len);
break;
default:
return offset - tlv_value_offset;
break;
}
offset += tlv_len;
}
return offset;
}
