static void
dissect_lacp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint16 raw_word;
guint8 raw_octet;
guint8 flags;
proto_tree *lacpdu_tree;
proto_item *lacpdu_item;
proto_tree *actor_flags_tree;
proto_item *actor_flags_item;
proto_tree *partner_flags_tree;
proto_item *partner_flags_item;
const char *sep;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LACP");
col_set_str(pinfo->cinfo, COL_INFO, "Link Aggregation Control Protocol");
if (tree)
{
lacpdu_item = proto_tree_add_protocol_format(tree, proto_lacp, tvb,
0, -1, "Link Aggregation Control Protocol");
lacpdu_tree = proto_item_add_subtree(lacpdu_item, ett_lacp);
raw_octet = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "Version %d. ", raw_octet);
proto_tree_add_uint(lacpdu_tree, hf_lacp_version_number, tvb,
offset, 1, raw_octet);
offset += 1;
proto_tree_add_item(lacpdu_tree, hf_lacp_actor_type, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(lacpdu_tree, hf_lacp_actor_info_len, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(lacpdu_tree, hf_lacp_actor_sys_priority, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(lacpdu_tree, hf_lacp_actor_sys, tvb,
offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(lacpdu_tree, hf_lacp_actor_key, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(lacpdu_tree, hf_lacp_actor_port_priority, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
raw_word = tvb_get_ntohs(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "Actor Port = %d ", raw_word);
proto_tree_add_uint(lacpdu_tree, hf_lacp_actor_port, tvb,
offset, 2, raw_word);
offset += 2;
flags = tvb_get_guint8(tvb, offset);
actor_flags_item = proto_tree_add_uint(lacpdu_tree, hf_lacp_actor_state, tvb,
offset, 1, flags);
actor_flags_tree = proto_item_add_subtree(actor_flags_item, ett_lacp_a_flags);
sep = initial_sep;
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_ACTIVITY, actor_flags_item,
"%sActivity");
proto_tree_add_boolean(actor_flags_tree, hf_lacp_flags_a_activity, tvb,
offset, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_TIMEOUT, actor_flags_item,
"%sTimeout");
proto_tree_add_boolean(actor_flags_tree, hf_lacp_flags_a_timeout, tvb,
offset, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_AGGREGATION, actor_flags_item,
"%sAggregation");
proto_tree_add_boolean(actor_flags_tree, hf_lacp_flags_a_aggregation, tvb,
offset, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_SYNC, actor_flags_item,
"%sSynchronization");
proto_tree_add_boolean(actor_flags_tree, hf_lacp_flags_a_sync, tvb,
offset, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_COLLECTING, actor_flags_item,
"%sCollecting");
proto_tree_add_boolean(actor_flags_tree, hf_lacp_flags_a_collecting, tvb,
offset, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_DISTRIB, actor_flags_item,
"%sDistributing");
proto_tree_add_boolean(actor_flags_tree, hf_lacp_flags_a_distrib, tvb,
offset, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_DEFAULTED, actor_flags_item,
"%sDefaulted");
proto_tree_add_boolean(actor_flags_tree, hf_lacp_flags_a_defaulted, tvb,
offset, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_EXPIRED, actor_flags_item,
"%sExpired");
proto_tree_add_boolean(actor_flags_tree, hf_lacp_flags_a_expired, tvb,
offset, 1, flags);
if (sep != initial_sep)
{
proto_item_append_text(actor_flags_item, ")");
}
offset += 1;
proto_tree_add_item(lacpdu_tree, hf_lacp_actor_reserved, tvb,
offset, 3, ENC_NA);
offset += 3;
proto_tree_add_item(lacpdu_tree, hf_lacp_partner_type, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(lacpdu_tree, hf_lacp_partner_info_len, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(lacpdu_tree, hf_lacp_partner_sys_priority, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(lacpdu_tree, hf_lacp_partner_sys, tvb,
offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(lacpdu_tree, hf_lacp_partner_key, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(lacpdu_tree, hf_lacp_partner_port_priority, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
raw_word = tvb_get_ntohs(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "Partner Port = %d ", raw_word);
proto_tree_add_uint(lacpdu_tree, hf_lacp_partner_port, tvb,
offset, 2, raw_word);
offset += 2;
flags = tvb_get_guint8(tvb, offset);
partner_flags_item = proto_tree_add_uint(lacpdu_tree, hf_lacp_partner_state, tvb,
offset, 1, flags);
partner_flags_tree = proto_item_add_subtree(partner_flags_item, ett_lacp_p_flags);
sep = initial_sep;
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_ACTIVITY, partner_flags_item,
"%sActivity");
proto_tree_add_boolean(partner_flags_tree, hf_lacp_flags_p_activity, tvb,
offset, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_TIMEOUT, partner_flags_item,
"%sTimeout");
proto_tree_add_boolean(partner_flags_tree, hf_lacp_flags_p_timeout, tvb,
offset, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_AGGREGATION, partner_flags_item,
"%sAggregation");
proto_tree_add_boolean(partner_flags_tree, hf_lacp_flags_p_aggregation, tvb,
offset, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_SYNC, partner_flags_item,
"%sSynchronization");
proto_tree_add_boolean(partner_flags_tree, hf_lacp_flags_p_sync, tvb,
offset, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_COLLECTING, partner_flags_item,
"%sCollecting");
proto_tree_add_boolean(partner_flags_tree, hf_lacp_flags_p_collecting, tvb,
offset, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_DISTRIB, partner_flags_item,
"%sDistributing");
proto_tree_add_boolean(partner_flags_tree, hf_lacp_flags_p_distrib, tvb,
offset, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_DEFAULTED, partner_flags_item,
"%sDefaulted");
proto_tree_add_boolean(partner_flags_tree, hf_lacp_flags_p_defaulted, tvb,
offset, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_EXPIRED, partner_flags_item,
"%sExpired");
proto_tree_add_boolean(partner_flags_tree, hf_lacp_flags_p_expired, tvb,
offset, 1, flags);
if (sep != initial_sep)
{
proto_item_append_text(partner_flags_item, ")");
}
offset += 1;
proto_tree_add_item(lacpdu_tree, hf_lacp_partner_reserved, tvb,
offset, 3, ENC_NA);
offset += 3;
proto_tree_add_item(lacpdu_tree, hf_lacp_coll_type, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(lacpdu_tree, hf_lacp_coll_info_len, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(lacpdu_tree, hf_lacp_coll_max_delay, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(lacpdu_tree, hf_lacp_coll_reserved, tvb,
offset, 12, ENC_NA);
offset += 12;
proto_tree_add_item(lacpdu_tree, hf_lacp_term_type, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(lacpdu_tree, hf_lacp_term_len, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(lacpdu_tree, hf_lacp_term_reserved, tvb,
offset, 50, ENC_NA);
}
}
void
proto_register_lacp(void)
{
static hf_register_info hf[] = {
{ &hf_lacp_version_number,
{ "LACP Version Number", "lacp.version",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Identifies the LACP version", HFILL }},
{ &hf_lacp_actor_type,
{ "Actor Information", "lacp.actorInfo",
FT_UINT8, BASE_HEX, NULL, 0x0,
"TLV type = Actor", HFILL }},
{ &hf_lacp_actor_info_len,
{ "Actor Information Length", "lacp.actorInfoLen",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The length of the Actor TLV", HFILL }},
{ &hf_lacp_actor_sys_priority,
{ "Actor System Priority", "lacp.actorSysPriority",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The priority assigned to this System by management or admin", HFILL }},
{ &hf_lacp_actor_sys,
{ "Actor System", "lacp.actorSystem",
FT_ETHER, BASE_NONE, NULL, 0x0,
"The Actor's System ID encoded as a MAC address", HFILL }},
{ &hf_lacp_actor_key,
{ "Actor Key", "lacp.actorKey",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The operational Key value assigned to the port by the Actor", HFILL }},
{ &hf_lacp_actor_port_priority,
{ "Actor Port Priority", "lacp.actorPortPriority",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The priority assigned to the port by the Actor (via Management or Admin)", HFILL }},
{ &hf_lacp_actor_port,
{ "Actor Port", "lacp.actorPort",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The port number assigned to the port by the Actor (via Management or Admin)", HFILL }},
{ &hf_lacp_actor_state,
{ "Actor State", "lacp.actorState",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The Actor's state variables for the port, encoded as bits within a single octet", HFILL }},
{ &hf_lacp_flags_a_activity,
{ "LACP Activity", "lacp.actorState.activity",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_ACTIVITY,
"Activity control value for this link. Active = 1, Passive = 0", HFILL }},
{ &hf_lacp_flags_a_timeout,
{ "LACP Timeout", "lacp.actorState.timeout",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_TIMEOUT,
"Timeout control value for this link. Short Timeout = 1, Long Timeout = 0", HFILL }},
{ &hf_lacp_flags_a_aggregation,
{ "Aggregation", "lacp.actorState.aggregation",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_AGGREGATION,
"Aggregatable = 1, Individual = 0", HFILL }},
{ &hf_lacp_flags_a_sync,
{ "Synchronization", "lacp.actorState.synchronization",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_SYNC,
"In Sync = 1, Out of Sync = 0", HFILL }},
{ &hf_lacp_flags_a_collecting,
{ "Collecting", "lacp.actorState.collecting",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_COLLECTING,
"Collection of incoming frames is: Enabled = 1, Disabled = 0", HFILL }},
{ &hf_lacp_flags_a_distrib,
{ "Distributing", "lacp.actorState.distributing",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_DISTRIB,
"Distribution of outgoing frames is: Enabled = 1, Disabled = 0", HFILL }},
{ &hf_lacp_flags_a_defaulted,
{ "Defaulted", "lacp.actorState.defaulted",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_DEFAULTED,
"1 = Actor Rx machine is using DEFAULT Partner info, 0 = using info in Rx'd LACPDU", HFILL }},
{ &hf_lacp_flags_a_expired,
{ "Expired", "lacp.actorState.expired",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_EXPIRED,
"1 = Actor Rx machine is EXPIRED, 0 = is NOT EXPIRED", HFILL }},
{ &hf_lacp_actor_reserved,
{ "Reserved", "lacp.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_lacp_partner_type,
{ "Partner Information", "lacp.partnerInfo",
FT_UINT8, BASE_HEX, NULL, 0x0,
"TLV type = Partner", HFILL }},
{ &hf_lacp_partner_info_len,
{ "Partner Information Length", "lacp.partnerInfoLen",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The length of the Partner TLV", HFILL }},
{ &hf_lacp_partner_sys_priority,
{ "Partner System Priority", "lacp.partnerSysPriority",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The priority assigned to the Partner System by management or admin", HFILL }},
{ &hf_lacp_partner_sys,
{ "Partner System", "lacp.partnerSystem",
FT_ETHER, BASE_NONE, NULL, 0x0,
"The Partner's System ID encoded as a MAC address", HFILL }},
{ &hf_lacp_partner_key,
{ "Partner Key", "lacp.partnerKey",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The operational Key value assigned to the port associated with this link by the Partner", HFILL }},
{ &hf_lacp_partner_port_priority,
{ "Partner Port Priority", "lacp.partnerPortPriority",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The priority assigned to the port by the Partner (via Management or Admin)", HFILL }},
{ &hf_lacp_partner_port,
{ "Partner Port", "lacp.partnerPort",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The port number associated with this link assigned to the port by the Partner (via Management or Admin)", HFILL }},
{ &hf_lacp_partner_state,
{ "Partner State", "lacp.partnerState",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The Partner's state variables for the port, encoded as bits within a single octet", HFILL }},
{ &hf_lacp_flags_p_activity,
{ "LACP Activity", "lacp.partnerState.activity",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_ACTIVITY,
"Activity control value for this link. Active = 1, Passive = 0", HFILL }},
{ &hf_lacp_flags_p_timeout,
{ "LACP Timeout", "lacp.partnerState.timeout",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_TIMEOUT,
"Timeout control value for this link. Short Timeout = 1, Long Timeout = 0", HFILL }},
{ &hf_lacp_flags_p_aggregation,
{ "Aggregation", "lacp.partnerState.aggregation",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_AGGREGATION,
"Aggregatable = 1, Individual = 0", HFILL }},
{ &hf_lacp_flags_p_sync,
{ "Synchronization", "lacp.partnerState.synchronization",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_SYNC,
"In Sync = 1, Out of Sync = 0", HFILL }},
{ &hf_lacp_flags_p_collecting,
{ "Collecting", "lacp.partnerState.collecting",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_COLLECTING,
"Collection of incoming frames is: Enabled = 1, Disabled = 0", HFILL }},
{ &hf_lacp_flags_p_distrib,
{ "Distributing", "lacp.partnerState.distributing",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_DISTRIB,
"Distribution of outgoing frames is: Enabled = 1, Disabled = 0", HFILL }},
{ &hf_lacp_flags_p_defaulted,
{ "Defaulted", "lacp.partnerState.defaulted",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_DEFAULTED,
"1 = Actor Rx machine is using DEFAULT Partner info, 0 = using info in Rx'd LACPDU", HFILL }},
{ &hf_lacp_flags_p_expired,
{ "Expired", "lacp.partnerState.expired",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_EXPIRED,
"1 = Actor Rx machine is EXPIRED, 0 = is NOT EXPIRED", HFILL }},
{ &hf_lacp_partner_reserved,
{ "Reserved", "lacp.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_lacp_coll_type,
{ "Collector Information", "lacp.collectorInfo",
FT_UINT8, BASE_HEX, NULL, 0x0,
"TLV type = Collector", HFILL }},
{ &hf_lacp_coll_info_len,
{ "Collector Information Length", "lacp.collectorInfoLen",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The length of the Collector TLV", HFILL }},
{ &hf_lacp_coll_max_delay,
{ "Collector Max Delay", "lacp.collectorMaxDelay",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The max delay of the station tx'ing the LACPDU (in tens of usecs)", HFILL }},
{ &hf_lacp_coll_reserved,
{ "Reserved", "lacp.coll_reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_lacp_term_type,
{ "Terminator Information", "lacp.termInfo",
FT_UINT8, BASE_HEX, NULL, 0x0,
"TLV type = Terminator", HFILL }},
{ &hf_lacp_term_len,
{ "Terminator Length", "lacp.termLen",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The length of the Terminator TLV", HFILL }},
{ &hf_lacp_term_reserved,
{ "Reserved", "lacp.term_reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_lacp,
&ett_lacp_a_flags,
&ett_lacp_p_flags,
};
proto_lacp = proto_register_protocol("LACP", "Link Aggregation Control Protocol", "lacp");
proto_register_field_array(proto_lacp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_lacp(void)
{
dissector_handle_t lacp_handle;
lacp_handle = create_dissector_handle(dissect_lacp, proto_lacp);
dissector_add_uint("slow.subtype", LACP_SUBTYPE, lacp_handle);
}
