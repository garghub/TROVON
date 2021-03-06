void parseTrustListDataType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_TrustListDataType, &ti, "%s: TrustListDataType", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SpecifiedLists);
parseArraySimple(subtree, tvb, pinfo, pOffset, "TrustedCertificates", "ByteString", hf_opcua_TrustedCertificates, parseByteString, ett_opcua_array_ByteString);
parseArraySimple(subtree, tvb, pinfo, pOffset, "TrustedCrls", "ByteString", hf_opcua_TrustedCrls, parseByteString, ett_opcua_array_ByteString);
parseArraySimple(subtree, tvb, pinfo, pOffset, "IssuerCertificates", "ByteString", hf_opcua_IssuerCertificates, parseByteString, ett_opcua_array_ByteString);
parseArraySimple(subtree, tvb, pinfo, pOffset, "IssuerCrls", "ByteString", hf_opcua_IssuerCrls, parseByteString, ett_opcua_array_ByteString);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseNode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_Node, &ti, "%s: Node", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pinfo, pOffset);
parseQualifiedName(subtree, tvb, pinfo, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseInstanceNode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_InstanceNode, &ti, "%s: InstanceNode", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pinfo, pOffset);
parseQualifiedName(subtree, tvb, pinfo, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTypeNode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_TypeNode, &ti, "%s: TypeNode", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pinfo, pOffset);
parseQualifiedName(subtree, tvb, pinfo, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseObjectNode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ObjectNode, &ti, "%s: ObjectNode", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pinfo, pOffset);
parseQualifiedName(subtree, tvb, pinfo, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_EventNotifier);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseObjectTypeNode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ObjectTypeNode, &ti, "%s: ObjectTypeNode", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pinfo, pOffset);
parseQualifiedName(subtree, tvb, pinfo, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsAbstract);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseVariableNode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_VariableNode, &ti, "%s: VariableNode", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pinfo, pOffset);
parseQualifiedName(subtree, tvb, pinfo, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseVariant(subtree, tvb, pinfo, pOffset, "Value");
parseNodeId(subtree, tvb, pinfo, pOffset, "DataType");
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ValueRank);
parseArraySimple(subtree, tvb, pinfo, pOffset, "ArrayDimensions", "UInt32", hf_opcua_ArrayDimensions, parseUInt32, ett_opcua_array_UInt32);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_AccessLevel);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_UserAccessLevel);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_MinimumSamplingInterval);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_Historizing);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseVariableTypeNode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_VariableTypeNode, &ti, "%s: VariableTypeNode", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pinfo, pOffset);
parseQualifiedName(subtree, tvb, pinfo, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseVariant(subtree, tvb, pinfo, pOffset, "Value");
parseNodeId(subtree, tvb, pinfo, pOffset, "DataType");
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ValueRank);
parseArraySimple(subtree, tvb, pinfo, pOffset, "ArrayDimensions", "UInt32", hf_opcua_ArrayDimensions, parseUInt32, ett_opcua_array_UInt32);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsAbstract);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReferenceTypeNode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ReferenceTypeNode, &ti, "%s: ReferenceTypeNode", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pinfo, pOffset);
parseQualifiedName(subtree, tvb, pinfo, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsAbstract);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_Symmetric);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "InverseName");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMethodNode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_MethodNode, &ti, "%s: MethodNode", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pinfo, pOffset);
parseQualifiedName(subtree, tvb, pinfo, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_Executable);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_UserExecutable);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseViewNode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ViewNode, &ti, "%s: ViewNode", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pinfo, pOffset);
parseQualifiedName(subtree, tvb, pinfo, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_ContainsNoLoops);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_EventNotifier);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDataTypeNode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_DataTypeNode, &ti, "%s: DataTypeNode", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pinfo, pOffset);
parseQualifiedName(subtree, tvb, pinfo, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsAbstract);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReferenceNode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ReferenceNode, &ti, "%s: ReferenceNode", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "ReferenceTypeId");
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsInverse);
parseExpandedNodeId(subtree, tvb, pinfo, pOffset, "TargetId");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseArgument(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_Argument, &ti, "%s: Argument", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_Name);
parseNodeId(subtree, tvb, pinfo, pOffset, "DataType");
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ValueRank);
parseArraySimple(subtree, tvb, pinfo, pOffset, "ArrayDimensions", "UInt32", hf_opcua_ArrayDimensions, parseUInt32, ett_opcua_array_UInt32);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEnumValueType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_EnumValueType, &ti, "%s: EnumValueType", szFieldName);
parseInt64(subtree, tvb, pinfo, pOffset, hf_opcua_Value);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseOptionSet(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_OptionSet, &ti, "%s: OptionSet", szFieldName);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_Value);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ValidBits);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTimeZoneDataType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_TimeZoneDataType, &ti, "%s: TimeZoneDataType", szFieldName);
parseInt16(subtree, tvb, pinfo, pOffset, hf_opcua_Offset);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_DaylightSavingInOffset);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseApplicationDescription(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ApplicationDescription, &ti, "%s: ApplicationDescription", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ApplicationUri);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ProductUri);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "ApplicationName");
parseApplicationType(subtree, tvb, pinfo, pOffset);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_GatewayServerUri);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_DiscoveryProfileUri);
parseArraySimple(subtree, tvb, pinfo, pOffset, "DiscoveryUrls", "String", hf_opcua_DiscoveryUrls, parseString, ett_opcua_array_String);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRequestHeader(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_RequestHeader, &ti, "%s: RequestHeader", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "AuthenticationToken");
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_Timestamp);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RequestHandle);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ReturnDiagnostics);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_AuditEntryId);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_TimeoutHint);
parseExtensionObject(subtree, tvb, pinfo, pOffset, "AdditionalHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseResponseHeader(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ResponseHeader, &ti, "%s: ResponseHeader", szFieldName);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_Timestamp);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RequestHandle);
parseStatusCode(subtree, tvb, pinfo, pOffset, hf_opcua_ServiceResult);
parseDiagnosticInfo(subtree, tvb, pinfo, pOffset, "ServiceDiagnostics");
parseArraySimple(subtree, tvb, pinfo, pOffset, "StringTable", "String", hf_opcua_StringTable, parseString, ett_opcua_array_String);
parseExtensionObject(subtree, tvb, pinfo, pOffset, "AdditionalHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseServerOnNetwork(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ServerOnNetwork, &ti, "%s: ServerOnNetwork", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RecordId);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ServerName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_DiscoveryUrl);
parseArraySimple(subtree, tvb, pinfo, pOffset, "ServerCapabilities", "String", hf_opcua_ServerCapabilities, parseString, ett_opcua_array_String);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUserTokenPolicy(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_UserTokenPolicy, &ti, "%s: UserTokenPolicy", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_PolicyId);
parseUserTokenType(subtree, tvb, pinfo, pOffset);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_IssuedTokenType);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_IssuerEndpointUrl);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_SecurityPolicyUri);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEndpointDescription(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_EndpointDescription, &ti, "%s: EndpointDescription", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_EndpointUrl);
parseApplicationDescription(subtree, tvb, pinfo, pOffset, "Server");
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ServerCertificate);
parseMessageSecurityMode(subtree, tvb, pinfo, pOffset);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_SecurityPolicyUri);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "UserIdentityTokens", "UserTokenPolicy", parseUserTokenPolicy, ett_opcua_array_UserTokenPolicy);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_TransportProfileUri);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_SecurityLevel);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRegisteredServer(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_RegisteredServer, &ti, "%s: RegisteredServer", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ServerUri);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ProductUri);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "ServerNames", "LocalizedText", parseLocalizedText, ett_opcua_array_LocalizedText);
parseApplicationType(subtree, tvb, pinfo, pOffset);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_GatewayServerUri);
parseArraySimple(subtree, tvb, pinfo, pOffset, "DiscoveryUrls", "String", hf_opcua_DiscoveryUrls, parseString, ett_opcua_array_String);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_SemaphoreFilePath);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsOnline);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMdnsDiscoveryConfiguration(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_MdnsDiscoveryConfiguration, &ti, "%s: MdnsDiscoveryConfiguration", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_MdnsServerName);
parseArraySimple(subtree, tvb, pinfo, pOffset, "ServerCapabilities", "String", hf_opcua_ServerCapabilities, parseString, ett_opcua_array_String);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseChannelSecurityToken(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ChannelSecurityToken, &ti, "%s: ChannelSecurityToken", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ChannelId);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_TokenId);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_CreatedAt);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RevisedLifetime);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSignedSoftwareCertificate(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_SignedSoftwareCertificate, &ti, "%s: SignedSoftwareCertificate", szFieldName);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_CertificateData);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_Signature);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSignatureData(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_SignatureData, &ti, "%s: SignatureData", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_Algorithm);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_Signature);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUserIdentityToken(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_UserIdentityToken, &ti, "%s: UserIdentityToken", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_PolicyId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAnonymousIdentityToken(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_AnonymousIdentityToken, &ti, "%s: AnonymousIdentityToken", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_PolicyId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUserNameIdentityToken(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_UserNameIdentityToken, &ti, "%s: UserNameIdentityToken", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_PolicyId);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_UserName);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_Password);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_EncryptionAlgorithm);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseX509IdentityToken(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_X509IdentityToken, &ti, "%s: X509IdentityToken", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_PolicyId);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_CertificateData);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseKerberosIdentityToken(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_KerberosIdentityToken, &ti, "%s: KerberosIdentityToken", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_PolicyId);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_TicketData);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseIssuedIdentityToken(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_IssuedIdentityToken, &ti, "%s: IssuedIdentityToken", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_PolicyId);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_TokenData);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_EncryptionAlgorithm);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseNodeAttributes(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_NodeAttributes, &ti, "%s: NodeAttributes", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseObjectAttributes(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ObjectAttributes, &ti, "%s: ObjectAttributes", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_EventNotifier);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseVariableAttributes(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_VariableAttributes, &ti, "%s: VariableAttributes", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseVariant(subtree, tvb, pinfo, pOffset, "Value");
parseNodeId(subtree, tvb, pinfo, pOffset, "DataType");
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ValueRank);
parseArraySimple(subtree, tvb, pinfo, pOffset, "ArrayDimensions", "UInt32", hf_opcua_ArrayDimensions, parseUInt32, ett_opcua_array_UInt32);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_AccessLevel);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_UserAccessLevel);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_MinimumSamplingInterval);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_Historizing);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMethodAttributes(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_MethodAttributes, &ti, "%s: MethodAttributes", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_Executable);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_UserExecutable);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseObjectTypeAttributes(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ObjectTypeAttributes, &ti, "%s: ObjectTypeAttributes", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsAbstract);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseVariableTypeAttributes(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_VariableTypeAttributes, &ti, "%s: VariableTypeAttributes", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseVariant(subtree, tvb, pinfo, pOffset, "Value");
parseNodeId(subtree, tvb, pinfo, pOffset, "DataType");
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ValueRank);
parseArraySimple(subtree, tvb, pinfo, pOffset, "ArrayDimensions", "UInt32", hf_opcua_ArrayDimensions, parseUInt32, ett_opcua_array_UInt32);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsAbstract);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReferenceTypeAttributes(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ReferenceTypeAttributes, &ti, "%s: ReferenceTypeAttributes", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsAbstract);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_Symmetric);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "InverseName");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDataTypeAttributes(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_DataTypeAttributes, &ti, "%s: DataTypeAttributes", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsAbstract);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseViewAttributes(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ViewAttributes, &ti, "%s: ViewAttributes", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UserWriteMask);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_ContainsNoLoops);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_EventNotifier);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAddNodesItem(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_AddNodesItem, &ti, "%s: AddNodesItem", szFieldName);
parseExpandedNodeId(subtree, tvb, pinfo, pOffset, "ParentNodeId");
parseNodeId(subtree, tvb, pinfo, pOffset, "ReferenceTypeId");
parseExpandedNodeId(subtree, tvb, pinfo, pOffset, "RequestedNewNodeId");
parseQualifiedName(subtree, tvb, pinfo, pOffset, "BrowseName");
parseNodeClass(subtree, tvb, pinfo, pOffset);
parseExtensionObject(subtree, tvb, pinfo, pOffset, "NodeAttributes");
parseExpandedNodeId(subtree, tvb, pinfo, pOffset, "TypeDefinition");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAddNodesResult(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_AddNodesResult, &ti, "%s: AddNodesResult", szFieldName);
parseStatusCode(subtree, tvb, pinfo, pOffset, hf_opcua_StatusCode);
parseNodeId(subtree, tvb, pinfo, pOffset, "AddedNodeId");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAddReferencesItem(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_AddReferencesItem, &ti, "%s: AddReferencesItem", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "SourceNodeId");
parseNodeId(subtree, tvb, pinfo, pOffset, "ReferenceTypeId");
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsForward);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_TargetServerUri);
parseExpandedNodeId(subtree, tvb, pinfo, pOffset, "TargetNodeId");
parseNodeClass(subtree, tvb, pinfo, pOffset);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteNodesItem(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_DeleteNodesItem, &ti, "%s: DeleteNodesItem", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_DeleteTargetReferences);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteReferencesItem(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_DeleteReferencesItem, &ti, "%s: DeleteReferencesItem", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "SourceNodeId");
parseNodeId(subtree, tvb, pinfo, pOffset, "ReferenceTypeId");
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsForward);
parseExpandedNodeId(subtree, tvb, pinfo, pOffset, "TargetNodeId");
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_DeleteBidirectional);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseViewDescription(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ViewDescription, &ti, "%s: ViewDescription", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "ViewId");
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_Timestamp);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ViewVersion);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowseDescription(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_BrowseDescription, &ti, "%s: BrowseDescription", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseBrowseDirection(subtree, tvb, pinfo, pOffset);
parseNodeId(subtree, tvb, pinfo, pOffset, "ReferenceTypeId");
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IncludeSubtypes);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_NodeClassMask);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ResultMask);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReferenceDescription(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ReferenceDescription, &ti, "%s: ReferenceDescription", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "ReferenceTypeId");
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsForward);
parseExpandedNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseQualifiedName(subtree, tvb, pinfo, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseNodeClass(subtree, tvb, pinfo, pOffset);
parseExpandedNodeId(subtree, tvb, pinfo, pOffset, "TypeDefinition");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowseResult(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_BrowseResult, &ti, "%s: BrowseResult", szFieldName);
parseStatusCode(subtree, tvb, pinfo, pOffset, hf_opcua_StatusCode);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ContinuationPoint);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "References", "ReferenceDescription", parseReferenceDescription, ett_opcua_array_ReferenceDescription);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRelativePathElement(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_RelativePathElement, &ti, "%s: RelativePathElement", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "ReferenceTypeId");
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsInverse);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IncludeSubtypes);
parseQualifiedName(subtree, tvb, pinfo, pOffset, "TargetName");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRelativePath(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_RelativePath, &ti, "%s: RelativePath", szFieldName);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Elements", "RelativePathElement", parseRelativePathElement, ett_opcua_array_RelativePathElement);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowsePath(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_BrowsePath, &ti, "%s: BrowsePath", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "StartingNode");
parseRelativePath(subtree, tvb, pinfo, pOffset, "RelativePath");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowsePathTarget(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_BrowsePathTarget, &ti, "%s: BrowsePathTarget", szFieldName);
parseExpandedNodeId(subtree, tvb, pinfo, pOffset, "TargetId");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RemainingPathIndex);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowsePathResult(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_BrowsePathResult, &ti, "%s: BrowsePathResult", szFieldName);
parseStatusCode(subtree, tvb, pinfo, pOffset, hf_opcua_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Targets", "BrowsePathTarget", parseBrowsePathTarget, ett_opcua_array_BrowsePathTarget);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEndpointConfiguration(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_EndpointConfiguration, &ti, "%s: EndpointConfiguration", szFieldName);
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_OperationTimeout);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_UseBinaryEncoding);
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxStringLength);
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxByteStringLength);
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxArrayLength);
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxMessageSize);
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxBufferSize);
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ChannelLifetime);
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SecurityTokenLifetime);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSupportedProfile(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_SupportedProfile, &ti, "%s: SupportedProfile", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_OrganizationUri);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ProfileId);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ComplianceTool);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_ComplianceDate);
parseComplianceLevel(subtree, tvb, pinfo, pOffset);
parseArraySimple(subtree, tvb, pinfo, pOffset, "UnsupportedUnitIds", "String", hf_opcua_UnsupportedUnitIds, parseString, ett_opcua_array_String);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSoftwareCertificate(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_SoftwareCertificate, &ti, "%s: SoftwareCertificate", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ProductName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ProductUri);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_VendorName);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_VendorProductCertificate);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_SoftwareVersion);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_BuildNumber);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_BuildDate);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_IssuedBy);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_IssueDate);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "SupportedProfiles", "SupportedProfile", parseSupportedProfile, ett_opcua_array_SupportedProfile);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseQueryDataDescription(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_QueryDataDescription, &ti, "%s: QueryDataDescription", szFieldName);
parseRelativePath(subtree, tvb, pinfo, pOffset, "RelativePath");
parseAttributeId(subtree, tvb, pinfo, pOffset);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_IndexRange);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseNodeTypeDescription(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_NodeTypeDescription, &ti, "%s: NodeTypeDescription", szFieldName);
parseExpandedNodeId(subtree, tvb, pinfo, pOffset, "TypeDefinitionNode");
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IncludeSubTypes);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DataToReturn", "QueryDataDescription", parseQueryDataDescription, ett_opcua_array_QueryDataDescription);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseQueryDataSet(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_QueryDataSet, &ti, "%s: QueryDataSet", szFieldName);
parseExpandedNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseExpandedNodeId(subtree, tvb, pinfo, pOffset, "TypeDefinitionNode");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Values", "Variant", parseVariant, ett_opcua_array_Variant);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseNodeReference(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_NodeReference, &ti, "%s: NodeReference", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseNodeId(subtree, tvb, pinfo, pOffset, "ReferenceTypeId");
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsForward);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "ReferencedNodeIds", "NodeId", parseNodeId, ett_opcua_array_NodeId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseContentFilterElement(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ContentFilterElement, &ti, "%s: ContentFilterElement", szFieldName);
parseFilterOperator(subtree, tvb, pinfo, pOffset);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "FilterOperands", "ExtensionObject", parseExtensionObject, ett_opcua_array_ExtensionObject);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseContentFilter(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ContentFilter, &ti, "%s: ContentFilter", szFieldName);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Elements", "ContentFilterElement", parseContentFilterElement, ett_opcua_array_ContentFilterElement);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseElementOperand(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ElementOperand, &ti, "%s: ElementOperand", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_Index);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseLiteralOperand(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_LiteralOperand, &ti, "%s: LiteralOperand", szFieldName);
parseVariant(subtree, tvb, pinfo, pOffset, "Value");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAttributeOperand(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_AttributeOperand, &ti, "%s: AttributeOperand", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_Alias);
parseRelativePath(subtree, tvb, pinfo, pOffset, "BrowsePath");
parseAttributeId(subtree, tvb, pinfo, pOffset);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_IndexRange);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSimpleAttributeOperand(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_SimpleAttributeOperand, &ti, "%s: SimpleAttributeOperand", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "TypeDefinitionId");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "BrowsePath", "QualifiedName", parseQualifiedName, ett_opcua_array_QualifiedName);
parseAttributeId(subtree, tvb, pinfo, pOffset);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_IndexRange);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseContentFilterElementResult(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ContentFilterElementResult, &ti, "%s: ContentFilterElementResult", szFieldName);
parseStatusCode(subtree, tvb, pinfo, pOffset, hf_opcua_StatusCode);
parseArraySimple(subtree, tvb, pinfo, pOffset, "OperandStatusCodes", "StatusCode", hf_opcua_OperandStatusCodes, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "OperandDiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseContentFilterResult(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ContentFilterResult, &ti, "%s: ContentFilterResult", szFieldName);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "ElementResults", "ContentFilterElementResult", parseContentFilterElementResult, ett_opcua_array_ContentFilterElementResult);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "ElementDiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseParsingResult(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ParsingResult, &ti, "%s: ParsingResult", szFieldName);
parseStatusCode(subtree, tvb, pinfo, pOffset, hf_opcua_StatusCode);
parseArraySimple(subtree, tvb, pinfo, pOffset, "DataStatusCodes", "StatusCode", hf_opcua_DataStatusCodes, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DataDiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReadValueId(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ReadValueId, &ti, "%s: ReadValueId", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseAttributeId(subtree, tvb, pinfo, pOffset);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_IndexRange);
parseQualifiedName(subtree, tvb, pinfo, pOffset, "DataEncoding");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryReadValueId(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_HistoryReadValueId, &ti, "%s: HistoryReadValueId", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_IndexRange);
parseQualifiedName(subtree, tvb, pinfo, pOffset, "DataEncoding");
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ContinuationPoint);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryReadResult(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_HistoryReadResult, &ti, "%s: HistoryReadResult", szFieldName);
parseStatusCode(subtree, tvb, pinfo, pOffset, hf_opcua_StatusCode);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ContinuationPoint);
parseExtensionObject(subtree, tvb, pinfo, pOffset, "HistoryData");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReadEventDetails(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ReadEventDetails, &ti, "%s: ReadEventDetails", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_NumValuesPerNode);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_StartTime);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_EndTime);
parseEventFilter(subtree, tvb, pinfo, pOffset, "Filter");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReadRawModifiedDetails(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ReadRawModifiedDetails, &ti, "%s: ReadRawModifiedDetails", szFieldName);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsReadModified);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_StartTime);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_EndTime);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_NumValuesPerNode);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_ReturnBounds);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReadProcessedDetails(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ReadProcessedDetails, &ti, "%s: ReadProcessedDetails", szFieldName);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_StartTime);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_EndTime);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_ProcessingInterval);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "AggregateType", "NodeId", parseNodeId, ett_opcua_array_NodeId);
parseAggregateConfiguration(subtree, tvb, pinfo, pOffset, "AggregateConfiguration");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReadAtTimeDetails(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ReadAtTimeDetails, &ti, "%s: ReadAtTimeDetails", szFieldName);
parseArraySimple(subtree, tvb, pinfo, pOffset, "ReqTimes", "DateTime", hf_opcua_ReqTimes, parseDateTime, ett_opcua_array_DateTime);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_UseSimpleBounds);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryData(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_HistoryData, &ti, "%s: HistoryData", szFieldName);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DataValues", "DataValue", parseDataValue, ett_opcua_array_DataValue);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseModificationInfo(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ModificationInfo, &ti, "%s: ModificationInfo", szFieldName);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_ModificationTime);
parseHistoryUpdateType(subtree, tvb, pinfo, pOffset);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_UserName);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryModifiedData(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_HistoryModifiedData, &ti, "%s: HistoryModifiedData", szFieldName);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DataValues", "DataValue", parseDataValue, ett_opcua_array_DataValue);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "ModificationInfos", "ModificationInfo", parseModificationInfo, ett_opcua_array_ModificationInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryEvent(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_HistoryEvent, &ti, "%s: HistoryEvent", szFieldName);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Events", "HistoryEventFieldList", parseHistoryEventFieldList, ett_opcua_array_HistoryEventFieldList);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseWriteValue(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_WriteValue, &ti, "%s: WriteValue", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseAttributeId(subtree, tvb, pinfo, pOffset);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_IndexRange);
parseDataValue(subtree, tvb, pinfo, pOffset, "Value");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryUpdateDetails(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_HistoryUpdateDetails, &ti, "%s: HistoryUpdateDetails", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUpdateDataDetails(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_UpdateDataDetails, &ti, "%s: UpdateDataDetails", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parsePerformUpdateType(subtree, tvb, pinfo, pOffset);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "UpdateValues", "DataValue", parseDataValue, ett_opcua_array_DataValue);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUpdateStructureDataDetails(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_UpdateStructureDataDetails, &ti, "%s: UpdateStructureDataDetails", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parsePerformUpdateType(subtree, tvb, pinfo, pOffset);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "UpdateValues", "DataValue", parseDataValue, ett_opcua_array_DataValue);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUpdateEventDetails(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_UpdateEventDetails, &ti, "%s: UpdateEventDetails", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parsePerformUpdateType(subtree, tvb, pinfo, pOffset);
parseEventFilter(subtree, tvb, pinfo, pOffset, "Filter");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "EventData", "HistoryEventFieldList", parseHistoryEventFieldList, ett_opcua_array_HistoryEventFieldList);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteRawModifiedDetails(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_DeleteRawModifiedDetails, &ti, "%s: DeleteRawModifiedDetails", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_IsDeleteModified);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_StartTime);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_EndTime);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteAtTimeDetails(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_DeleteAtTimeDetails, &ti, "%s: DeleteAtTimeDetails", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseArraySimple(subtree, tvb, pinfo, pOffset, "ReqTimes", "DateTime", hf_opcua_ReqTimes, parseDateTime, ett_opcua_array_DateTime);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteEventDetails(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_DeleteEventDetails, &ti, "%s: DeleteEventDetails", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseArraySimple(subtree, tvb, pinfo, pOffset, "EventIds", "ByteString", hf_opcua_EventIds, parseByteString, ett_opcua_array_ByteString);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryUpdateResult(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_HistoryUpdateResult, &ti, "%s: HistoryUpdateResult", szFieldName);
parseStatusCode(subtree, tvb, pinfo, pOffset, hf_opcua_StatusCode);
parseArraySimple(subtree, tvb, pinfo, pOffset, "OperationResults", "StatusCode", hf_opcua_OperationResults, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCallMethodRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_CallMethodRequest, &ti, "%s: CallMethodRequest", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "ObjectId");
parseNodeId(subtree, tvb, pinfo, pOffset, "MethodId");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "InputArguments", "Variant", parseVariant, ett_opcua_array_Variant);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCallMethodResult(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_CallMethodResult, &ti, "%s: CallMethodResult", szFieldName);
parseStatusCode(subtree, tvb, pinfo, pOffset, hf_opcua_StatusCode);
parseArraySimple(subtree, tvb, pinfo, pOffset, "InputArgumentResults", "StatusCode", hf_opcua_InputArgumentResults, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "InputArgumentDiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "OutputArguments", "Variant", parseVariant, ett_opcua_array_Variant);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDataChangeFilter(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_DataChangeFilter, &ti, "%s: DataChangeFilter", szFieldName);
parseDataChangeTrigger(subtree, tvb, pinfo, pOffset);
parseDeadbandType(subtree, tvb, pinfo, pOffset);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_DeadbandValue);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEventFilter(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_EventFilter, &ti, "%s: EventFilter", szFieldName);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "SelectClauses", "SimpleAttributeOperand", parseSimpleAttributeOperand, ett_opcua_array_SimpleAttributeOperand);
parseContentFilter(subtree, tvb, pinfo, pOffset, "WhereClause");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAggregateConfiguration(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_AggregateConfiguration, &ti, "%s: AggregateConfiguration", szFieldName);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_UseServerCapabilitiesDefaults);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_TreatUncertainAsBad);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_PercentDataBad);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_PercentDataGood);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_UseSlopedExtrapolation);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAggregateFilter(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_AggregateFilter, &ti, "%s: AggregateFilter", szFieldName);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_StartTime);
parseNodeId(subtree, tvb, pinfo, pOffset, "AggregateType");
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_ProcessingInterval);
parseAggregateConfiguration(subtree, tvb, pinfo, pOffset, "AggregateConfiguration");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEventFilterResult(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_EventFilterResult, &ti, "%s: EventFilterResult", szFieldName);
parseArraySimple(subtree, tvb, pinfo, pOffset, "SelectClauseResults", "StatusCode", hf_opcua_SelectClauseResults, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "SelectClauseDiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
parseContentFilterResult(subtree, tvb, pinfo, pOffset, "WhereClauseResult");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAggregateFilterResult(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_AggregateFilterResult, &ti, "%s: AggregateFilterResult", szFieldName);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_RevisedStartTime);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_RevisedProcessingInterval);
parseAggregateConfiguration(subtree, tvb, pinfo, pOffset, "RevisedAggregateConfiguration");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMonitoringParameters(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_MonitoringParameters, &ti, "%s: MonitoringParameters", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ClientHandle);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_SamplingInterval);
parseExtensionObject(subtree, tvb, pinfo, pOffset, "Filter");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_QueueSize);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_DiscardOldest);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMonitoredItemCreateRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_MonitoredItemCreateRequest, &ti, "%s: MonitoredItemCreateRequest", szFieldName);
parseReadValueId(subtree, tvb, pinfo, pOffset, "ItemToMonitor");
parseMonitoringMode(subtree, tvb, pinfo, pOffset);
parseMonitoringParameters(subtree, tvb, pinfo, pOffset, "RequestedParameters");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMonitoredItemCreateResult(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_MonitoredItemCreateResult, &ti, "%s: MonitoredItemCreateResult", szFieldName);
parseStatusCode(subtree, tvb, pinfo, pOffset, hf_opcua_StatusCode);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MonitoredItemId);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_RevisedSamplingInterval);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RevisedQueueSize);
parseExtensionObject(subtree, tvb, pinfo, pOffset, "FilterResult");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMonitoredItemModifyRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_MonitoredItemModifyRequest, &ti, "%s: MonitoredItemModifyRequest", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MonitoredItemId);
parseMonitoringParameters(subtree, tvb, pinfo, pOffset, "RequestedParameters");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMonitoredItemModifyResult(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_MonitoredItemModifyResult, &ti, "%s: MonitoredItemModifyResult", szFieldName);
parseStatusCode(subtree, tvb, pinfo, pOffset, hf_opcua_StatusCode);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_RevisedSamplingInterval);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RevisedQueueSize);
parseExtensionObject(subtree, tvb, pinfo, pOffset, "FilterResult");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseNotificationMessage(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_NotificationMessage, &ti, "%s: NotificationMessage", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SequenceNumber);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_PublishTime);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "NotificationData", "ExtensionObject", parseExtensionObject, ett_opcua_array_ExtensionObject);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDataChangeNotification(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_DataChangeNotification, &ti, "%s: DataChangeNotification", szFieldName);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "MonitoredItems", "MonitoredItemNotification", parseMonitoredItemNotification, ett_opcua_array_MonitoredItemNotification);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMonitoredItemNotification(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_MonitoredItemNotification, &ti, "%s: MonitoredItemNotification", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ClientHandle);
parseDataValue(subtree, tvb, pinfo, pOffset, "Value");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEventNotificationList(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_EventNotificationList, &ti, "%s: EventNotificationList", szFieldName);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Events", "EventFieldList", parseEventFieldList, ett_opcua_array_EventFieldList);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEventFieldList(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_EventFieldList, &ti, "%s: EventFieldList", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ClientHandle);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "EventFields", "Variant", parseVariant, ett_opcua_array_Variant);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryEventFieldList(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_HistoryEventFieldList, &ti, "%s: HistoryEventFieldList", szFieldName);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "EventFields", "Variant", parseVariant, ett_opcua_array_Variant);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseStatusChangeNotification(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_StatusChangeNotification, &ti, "%s: StatusChangeNotification", szFieldName);
parseStatusCode(subtree, tvb, pinfo, pOffset, hf_opcua_Status);
parseDiagnosticInfo(subtree, tvb, pinfo, pOffset, "DiagnosticInfo");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSubscriptionAcknowledgement(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_SubscriptionAcknowledgement, &ti, "%s: SubscriptionAcknowledgement", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SubscriptionId);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SequenceNumber);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTransferResult(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_TransferResult, &ti, "%s: TransferResult", szFieldName);
parseStatusCode(subtree, tvb, pinfo, pOffset, hf_opcua_StatusCode);
parseArraySimple(subtree, tvb, pinfo, pOffset, "AvailableSequenceNumbers", "UInt32", hf_opcua_AvailableSequenceNumbers, parseUInt32, ett_opcua_array_UInt32);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseScalarTestType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ScalarTestType, &ti, "%s: ScalarTestType", szFieldName);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_Boolean);
parseSByte(subtree, tvb, pinfo, pOffset, hf_opcua_SByte);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_Byte);
parseInt16(subtree, tvb, pinfo, pOffset, hf_opcua_Int16);
parseUInt16(subtree, tvb, pinfo, pOffset, hf_opcua_UInt16);
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_Int32);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UInt32);
parseInt64(subtree, tvb, pinfo, pOffset, hf_opcua_Int64);
parseUInt64(subtree, tvb, pinfo, pOffset, hf_opcua_UInt64);
parseFloat(subtree, tvb, pinfo, pOffset, hf_opcua_Float);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_Double);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_String);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_DateTime);
parseGuid(subtree, tvb, pinfo, pOffset, hf_opcua_Guid);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ByteString);
parseXmlElement(subtree, tvb, pinfo, pOffset, hf_opcua_XmlElement);
parseNodeId(subtree, tvb, pinfo, pOffset, "NodeId");
parseExpandedNodeId(subtree, tvb, pinfo, pOffset, "ExpandedNodeId");
parseStatusCode(subtree, tvb, pinfo, pOffset, hf_opcua_StatusCode);
parseDiagnosticInfo(subtree, tvb, pinfo, pOffset, "DiagnosticInfo");
parseQualifiedName(subtree, tvb, pinfo, pOffset, "QualifiedName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "LocalizedText");
parseExtensionObject(subtree, tvb, pinfo, pOffset, "ExtensionObject");
parseDataValue(subtree, tvb, pinfo, pOffset, "DataValue");
parseEnumeratedTestType(subtree, tvb, pinfo, pOffset);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseArrayTestType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ArrayTestType, &ti, "%s: ArrayTestType", szFieldName);
parseArraySimple(subtree, tvb, pinfo, pOffset, "Booleans", "Boolean", hf_opcua_Booleans, parseBoolean, ett_opcua_array_Boolean);
parseArraySimple(subtree, tvb, pinfo, pOffset, "SBytes", "SByte", hf_opcua_SBytes, parseSByte, ett_opcua_array_SByte);
parseArraySimple(subtree, tvb, pinfo, pOffset, "Int16s", "Int16", hf_opcua_Int16s, parseInt16, ett_opcua_array_Int16);
parseArraySimple(subtree, tvb, pinfo, pOffset, "UInt16s", "UInt16", hf_opcua_UInt16s, parseUInt16, ett_opcua_array_UInt16);
parseArraySimple(subtree, tvb, pinfo, pOffset, "Int32s", "Int32", hf_opcua_Int32s, parseInt32, ett_opcua_array_Int32);
parseArraySimple(subtree, tvb, pinfo, pOffset, "UInt32s", "UInt32", hf_opcua_UInt32s, parseUInt32, ett_opcua_array_UInt32);
parseArraySimple(subtree, tvb, pinfo, pOffset, "Int64s", "Int64", hf_opcua_Int64s, parseInt64, ett_opcua_array_Int64);
parseArraySimple(subtree, tvb, pinfo, pOffset, "UInt64s", "UInt64", hf_opcua_UInt64s, parseUInt64, ett_opcua_array_UInt64);
parseArraySimple(subtree, tvb, pinfo, pOffset, "Floats", "Float", hf_opcua_Floats, parseFloat, ett_opcua_array_Float);
parseArraySimple(subtree, tvb, pinfo, pOffset, "Doubles", "Double", hf_opcua_Doubles, parseDouble, ett_opcua_array_Double);
parseArraySimple(subtree, tvb, pinfo, pOffset, "Strings", "String", hf_opcua_Strings, parseString, ett_opcua_array_String);
parseArraySimple(subtree, tvb, pinfo, pOffset, "DateTimes", "DateTime", hf_opcua_DateTimes, parseDateTime, ett_opcua_array_DateTime);
parseArraySimple(subtree, tvb, pinfo, pOffset, "Guids", "Guid", hf_opcua_Guids, parseGuid, ett_opcua_array_Guid);
parseArraySimple(subtree, tvb, pinfo, pOffset, "ByteStrings", "ByteString", hf_opcua_ByteStrings, parseByteString, ett_opcua_array_ByteString);
parseArraySimple(subtree, tvb, pinfo, pOffset, "XmlElements", "XmlElement", hf_opcua_XmlElements, parseXmlElement, ett_opcua_array_XmlElement);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "NodeIds", "NodeId", parseNodeId, ett_opcua_array_NodeId);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "ExpandedNodeIds", "ExpandedNodeId", parseExpandedNodeId, ett_opcua_array_ExpandedNodeId);
parseArraySimple(subtree, tvb, pinfo, pOffset, "StatusCodes", "StatusCode", hf_opcua_StatusCodes, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "QualifiedNames", "QualifiedName", parseQualifiedName, ett_opcua_array_QualifiedName);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "LocalizedTexts", "LocalizedText", parseLocalizedText, ett_opcua_array_LocalizedText);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "ExtensionObjects", "ExtensionObject", parseExtensionObject, ett_opcua_array_ExtensionObject);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DataValues", "DataValue", parseDataValue, ett_opcua_array_DataValue);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Variants", "Variant", parseVariant, ett_opcua_array_Variant);
parseArrayEnum(subtree, tvb, pinfo, pOffset, "EnumeratedValues", "EnumeratedTestType", parseEnumeratedTestType, ett_opcua_array_EnumeratedTestType);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCompositeTestType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_CompositeTestType, &ti, "%s: CompositeTestType", szFieldName);
parseScalarTestType(subtree, tvb, pinfo, pOffset, "Field1");
parseArrayTestType(subtree, tvb, pinfo, pOffset, "Field2");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBuildInfo(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_BuildInfo, &ti, "%s: BuildInfo", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ProductUri);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ManufacturerName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ProductName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_SoftwareVersion);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_BuildNumber);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_BuildDate);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRedundantServerDataType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_RedundantServerDataType, &ti, "%s: RedundantServerDataType", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ServerId);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_ServiceLevel);
parseServerState(subtree, tvb, pinfo, pOffset);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEndpointUrlListDataType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_EndpointUrlListDataType, &ti, "%s: EndpointUrlListDataType", szFieldName);
parseArraySimple(subtree, tvb, pinfo, pOffset, "EndpointUrlList", "String", hf_opcua_EndpointUrlList, parseString, ett_opcua_array_String);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseNetworkGroupDataType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_NetworkGroupDataType, &ti, "%s: NetworkGroupDataType", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ServerUri);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "NetworkPaths", "EndpointUrlListDataType", parseEndpointUrlListDataType, ett_opcua_array_EndpointUrlListDataType);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSamplingIntervalDiagnosticsDataType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_SamplingIntervalDiagnosticsDataType, &ti, "%s: SamplingIntervalDiagnosticsDataType", szFieldName);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_SamplingInterval);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MonitoredItemCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxMonitoredItemCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_DisabledMonitoredItemCount);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseServerDiagnosticsSummaryDataType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ServerDiagnosticsSummaryDataType, &ti, "%s: ServerDiagnosticsSummaryDataType", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ServerViewCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_CurrentSessionCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_CumulatedSessionCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SecurityRejectedSessionCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RejectedSessionCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SessionTimeoutCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SessionAbortCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_CurrentSubscriptionCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_CumulatedSubscriptionCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_PublishingIntervalCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SecurityRejectedRequestsCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RejectedRequestsCount);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseServerStatusDataType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ServerStatusDataType, &ti, "%s: ServerStatusDataType", szFieldName);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_StartTime);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_CurrentTime);
parseServerState(subtree, tvb, pinfo, pOffset);
parseBuildInfo(subtree, tvb, pinfo, pOffset, "BuildInfo");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SecondsTillShutdown);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "ShutdownReason");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSessionDiagnosticsDataType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_SessionDiagnosticsDataType, &ti, "%s: SessionDiagnosticsDataType", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "SessionId");
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_SessionName);
parseApplicationDescription(subtree, tvb, pinfo, pOffset, "ClientDescription");
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ServerUri);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_EndpointUrl);
parseArraySimple(subtree, tvb, pinfo, pOffset, "LocaleIds", "String", hf_opcua_LocaleIds, parseString, ett_opcua_array_String);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_ActualSessionTimeout);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxResponseMessageSize);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_ClientConnectionTime);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_ClientLastContactTime);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_CurrentSubscriptionsCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_CurrentMonitoredItemsCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_CurrentPublishRequestsInQueue);
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "TotalRequestCount");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UnauthorizedRequestCount);
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "ReadCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "HistoryReadCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "WriteCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "HistoryUpdateCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "CallCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "CreateMonitoredItemsCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "ModifyMonitoredItemsCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "SetMonitoringModeCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "SetTriggeringCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "DeleteMonitoredItemsCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "CreateSubscriptionCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "ModifySubscriptionCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "SetPublishingModeCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "PublishCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "RepublishCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "TransferSubscriptionsCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "DeleteSubscriptionsCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "AddNodesCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "AddReferencesCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "DeleteNodesCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "DeleteReferencesCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "BrowseCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "BrowseNextCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "TranslateBrowsePathsToNodeIdsCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "QueryFirstCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "QueryNextCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "RegisterNodesCount");
parseServiceCounterDataType(subtree, tvb, pinfo, pOffset, "UnregisterNodesCount");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSessionSecurityDiagnosticsDataType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_SessionSecurityDiagnosticsDataType, &ti, "%s: SessionSecurityDiagnosticsDataType", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "SessionId");
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ClientUserIdOfSession);
parseArraySimple(subtree, tvb, pinfo, pOffset, "ClientUserIdHistory", "String", hf_opcua_ClientUserIdHistory, parseString, ett_opcua_array_String);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_AuthenticationMechanism);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_Encoding);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_TransportProtocol);
parseMessageSecurityMode(subtree, tvb, pinfo, pOffset);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_SecurityPolicyUri);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ClientCertificate);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseServiceCounterDataType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ServiceCounterDataType, &ti, "%s: ServiceCounterDataType", szFieldName);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_TotalCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ErrorCount);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseStatusResult(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_StatusResult, &ti, "%s: StatusResult", szFieldName);
parseStatusCode(subtree, tvb, pinfo, pOffset, hf_opcua_StatusCode);
parseDiagnosticInfo(subtree, tvb, pinfo, pOffset, "DiagnosticInfo");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSubscriptionDiagnosticsDataType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_SubscriptionDiagnosticsDataType, &ti, "%s: SubscriptionDiagnosticsDataType", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "SessionId");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SubscriptionId);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_Priority);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_PublishingInterval);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxKeepAliveCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxLifetimeCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxNotificationsPerPublish);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_PublishingEnabled);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ModifyCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_EnableCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_DisableCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RepublishRequestCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RepublishMessageRequestCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RepublishMessageCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_TransferRequestCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_TransferredToAltClientCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_TransferredToSameClientCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_PublishRequestCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_DataChangeNotificationsCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_EventNotificationsCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_NotificationsCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_LatePublishRequestCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_CurrentKeepAliveCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_CurrentLifetimeCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UnacknowledgedMessageCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_DiscardedMessageCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MonitoredItemCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_DisabledMonitoredItemCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MonitoringQueueOverflowCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_NextSequenceNumber);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_EventQueueOverFlowCount);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseModelChangeStructureDataType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ModelChangeStructureDataType, &ti, "%s: ModelChangeStructureDataType", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "Affected");
parseNodeId(subtree, tvb, pinfo, pOffset, "AffectedType");
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_Verb);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSemanticChangeStructureDataType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_SemanticChangeStructureDataType, &ti, "%s: SemanticChangeStructureDataType", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "Affected");
parseNodeId(subtree, tvb, pinfo, pOffset, "AffectedType");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRange(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_Range, &ti, "%s: Range", szFieldName);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_Low);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_High);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEUInformation(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_EUInformation, &ti, "%s: EUInformation", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_NamespaceUri);
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_UnitId);
parseLocalizedText(subtree, tvb, pinfo, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Description");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseComplexNumberType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ComplexNumberType, &ti, "%s: ComplexNumberType", szFieldName);
parseFloat(subtree, tvb, pinfo, pOffset, hf_opcua_Real);
parseFloat(subtree, tvb, pinfo, pOffset, hf_opcua_Imaginary);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDoubleComplexNumberType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_DoubleComplexNumberType, &ti, "%s: DoubleComplexNumberType", szFieldName);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_Real);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_Imaginary);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAxisInformation(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_AxisInformation, &ti, "%s: AxisInformation", szFieldName);
parseEUInformation(subtree, tvb, pinfo, pOffset, "EngineeringUnits");
parseRange(subtree, tvb, pinfo, pOffset, "EURange");
parseLocalizedText(subtree, tvb, pinfo, pOffset, "Title");
parseAxisScaleEnumeration(subtree, tvb, pinfo, pOffset);
parseArraySimple(subtree, tvb, pinfo, pOffset, "AxisSteps", "Double", hf_opcua_AxisSteps, parseDouble, ett_opcua_array_Double);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseXVType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_XVType, &ti, "%s: XVType", szFieldName);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_X);
parseFloat(subtree, tvb, pinfo, pOffset, hf_opcua_Value);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseProgramDiagnosticDataType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_ProgramDiagnosticDataType, &ti, "%s: ProgramDiagnosticDataType", szFieldName);
parseNodeId(subtree, tvb, pinfo, pOffset, "CreateSessionId");
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_CreateClientName);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_InvocationCreationTime);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_LastTransitionTime);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_LastMethodCall);
parseNodeId(subtree, tvb, pinfo, pOffset, "LastMethodSessionId");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "LastMethodInputArguments", "Argument", parseArgument, ett_opcua_array_Argument);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "LastMethodOutputArguments", "Argument", parseArgument, ett_opcua_array_Argument);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_LastMethodCallTime);
parseStatusResult(subtree, tvb, pinfo, pOffset, "LastMethodReturnStatus");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAnnotation(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, const char *szFieldName)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, *pOffset, -1, ett_opcua_Annotation, &ti, "%s: Annotation", szFieldName);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_Message);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_UserName);
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_AnnotationTime);
proto_item_set_end(ti, tvb, *pOffset);
}
void registerComplexTypes(void)
{
proto_register_subtree_array(ett, array_length(ett));
}
