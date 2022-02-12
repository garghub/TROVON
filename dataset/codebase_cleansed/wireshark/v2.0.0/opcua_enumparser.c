void parseNodeIdType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_NodeIdType, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseNamingRuleType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_NamingRuleType, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseOpenFileMode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_OpenFileMode, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseTrustListMasks(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_TrustListMasks, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseIdType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_IdType, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseNodeClass(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_NodeClass, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseApplicationType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_ApplicationType, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseMessageSecurityMode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_MessageSecurityMode, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseUserTokenType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_UserTokenType, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseSecurityTokenRequestType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_SecurityTokenRequestType, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseNodeAttributesMask(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_NodeAttributesMask, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseAttributeWriteMask(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_AttributeWriteMask, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseBrowseDirection(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_BrowseDirection, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseBrowseResultMask(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_BrowseResultMask, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseComplianceLevel(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_ComplianceLevel, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseFilterOperator(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_FilterOperator, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseTimestampsToReturn(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_TimestampsToReturn, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseHistoryUpdateType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_HistoryUpdateType, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parsePerformUpdateType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_PerformUpdateType, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseMonitoringMode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_MonitoringMode, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseDataChangeTrigger(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_DataChangeTrigger, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseDeadbandType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_DeadbandType, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseEnumeratedTestType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_EnumeratedTestType, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseRedundancySupport(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_RedundancySupport, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseServerState(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_ServerState, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseModelChangeStructureVerbMask(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_ModelChangeStructureVerbMask, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseAxisScaleEnumeration(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_AxisScaleEnumeration, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseExceptionDeviationFormat(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_ExceptionDeviationFormat, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseAttributeId(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_AttributeId, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset += 4;
}
void registerEnumTypes(int proto)
{
static hf_register_info hf[] =
{
{ &hf_opcua_NodeIdType,
{ "NodeIdType", "opcua.NodeIdType", FT_UINT32, BASE_HEX, VALS(g_NodeIdTypeTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_NamingRuleType,
{ "NamingRuleType", "opcua.NamingRuleType", FT_UINT32, BASE_HEX, VALS(g_NamingRuleTypeTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_OpenFileMode,
{ "OpenFileMode", "opcua.OpenFileMode", FT_UINT32, BASE_HEX, VALS(g_OpenFileModeTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_TrustListMasks,
{ "TrustListMasks", "opcua.TrustListMasks", FT_UINT32, BASE_HEX, VALS(g_TrustListMasksTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_IdType,
{ "IdType", "opcua.IdType", FT_UINT32, BASE_HEX, VALS(g_IdTypeTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_NodeClass,
{ "NodeClass", "opcua.NodeClass", FT_UINT32, BASE_HEX, VALS(g_NodeClassTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_ApplicationType,
{ "ApplicationType", "opcua.ApplicationType", FT_UINT32, BASE_HEX, VALS(g_ApplicationTypeTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_MessageSecurityMode,
{ "MessageSecurityMode", "opcua.MessageSecurityMode", FT_UINT32, BASE_HEX, VALS(g_MessageSecurityModeTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_UserTokenType,
{ "UserTokenType", "opcua.UserTokenType", FT_UINT32, BASE_HEX, VALS(g_UserTokenTypeTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_SecurityTokenRequestType,
{ "SecurityTokenRequestType", "opcua.SecurityTokenRequestType", FT_UINT32, BASE_HEX, VALS(g_SecurityTokenRequestTypeTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_NodeAttributesMask,
{ "NodeAttributesMask", "opcua.NodeAttributesMask", FT_UINT32, BASE_HEX, VALS(g_NodeAttributesMaskTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_AttributeWriteMask,
{ "AttributeWriteMask", "opcua.AttributeWriteMask", FT_UINT32, BASE_HEX, VALS(g_AttributeWriteMaskTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_BrowseDirection,
{ "BrowseDirection", "opcua.BrowseDirection", FT_UINT32, BASE_HEX, VALS(g_BrowseDirectionTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_BrowseResultMask,
{ "BrowseResultMask", "opcua.BrowseResultMask", FT_UINT32, BASE_HEX, VALS(g_BrowseResultMaskTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_ComplianceLevel,
{ "ComplianceLevel", "opcua.ComplianceLevel", FT_UINT32, BASE_HEX, VALS(g_ComplianceLevelTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_FilterOperator,
{ "FilterOperator", "opcua.FilterOperator", FT_UINT32, BASE_HEX, VALS(g_FilterOperatorTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_TimestampsToReturn,
{ "TimestampsToReturn", "opcua.TimestampsToReturn", FT_UINT32, BASE_HEX, VALS(g_TimestampsToReturnTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_HistoryUpdateType,
{ "HistoryUpdateType", "opcua.HistoryUpdateType", FT_UINT32, BASE_HEX, VALS(g_HistoryUpdateTypeTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_PerformUpdateType,
{ "PerformUpdateType", "opcua.PerformUpdateType", FT_UINT32, BASE_HEX, VALS(g_PerformUpdateTypeTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_MonitoringMode,
{ "MonitoringMode", "opcua.MonitoringMode", FT_UINT32, BASE_HEX, VALS(g_MonitoringModeTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_DataChangeTrigger,
{ "DataChangeTrigger", "opcua.DataChangeTrigger", FT_UINT32, BASE_HEX, VALS(g_DataChangeTriggerTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_DeadbandType,
{ "DeadbandType", "opcua.DeadbandType", FT_UINT32, BASE_HEX, VALS(g_DeadbandTypeTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_EnumeratedTestType,
{ "EnumeratedTestType", "opcua.EnumeratedTestType", FT_UINT32, BASE_HEX, VALS(g_EnumeratedTestTypeTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_RedundancySupport,
{ "RedundancySupport", "opcua.RedundancySupport", FT_UINT32, BASE_HEX, VALS(g_RedundancySupportTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_ServerState,
{ "ServerState", "opcua.ServerState", FT_UINT32, BASE_HEX, VALS(g_ServerStateTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_ModelChangeStructureVerbMask,
{ "ModelChangeStructureVerbMask", "opcua.ModelChangeStructureVerbMask", FT_UINT32, BASE_HEX, VALS(g_ModelChangeStructureVerbMaskTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_AxisScaleEnumeration,
{ "AxisScaleEnumeration", "opcua.AxisScaleEnumeration", FT_UINT32, BASE_HEX, VALS(g_AxisScaleEnumerationTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_ExceptionDeviationFormat,
{ "ExceptionDeviationFormat", "opcua.ExceptionDeviationFormat", FT_UINT32, BASE_HEX, VALS(g_ExceptionDeviationFormatTable), 0x0, NULL, HFILL }
},
{ &hf_opcua_AttributeId,
{ "AttributeId", "opcua.AttributeId", FT_UINT32, BASE_HEX, VALS(g_AttributeIdTable), 0x0, NULL, HFILL }
},
};
proto_register_field_array(proto, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
