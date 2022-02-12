void parseNode(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: Node", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_Node);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pOffset);
parseQualifiedName(subtree, tvb, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseInstanceNode(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: InstanceNode", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_InstanceNode);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pOffset);
parseQualifiedName(subtree, tvb, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTypeNode(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: TypeNode", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TypeNode);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pOffset);
parseQualifiedName(subtree, tvb, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseObjectNode(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ObjectNode", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ObjectNode);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pOffset);
parseQualifiedName(subtree, tvb, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseByte(subtree, tvb, pOffset, hf_opcua_EventNotifier);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseObjectTypeNode(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ObjectTypeNode", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ObjectTypeNode);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pOffset);
parseQualifiedName(subtree, tvb, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsAbstract);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseVariableNode(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: VariableNode", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_VariableNode);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pOffset);
parseQualifiedName(subtree, tvb, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseVariant(subtree, tvb, pOffset, "Value");
parseNodeId(subtree, tvb, pOffset, "DataType");
parseInt32(subtree, tvb, pOffset, hf_opcua_ValueRank);
parseArraySimple(subtree, tvb, pOffset, "ArrayDimensions", "UInt32", hf_opcua_ArrayDimensions, parseUInt32, ett_opcua_array_UInt32);
parseByte(subtree, tvb, pOffset, hf_opcua_AccessLevel);
parseByte(subtree, tvb, pOffset, hf_opcua_UserAccessLevel);
parseDouble(subtree, tvb, pOffset, hf_opcua_MinimumSamplingInterval);
parseBoolean(subtree, tvb, pOffset, hf_opcua_Historizing);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseVariableTypeNode(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: VariableTypeNode", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_VariableTypeNode);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pOffset);
parseQualifiedName(subtree, tvb, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseVariant(subtree, tvb, pOffset, "Value");
parseNodeId(subtree, tvb, pOffset, "DataType");
parseInt32(subtree, tvb, pOffset, hf_opcua_ValueRank);
parseArraySimple(subtree, tvb, pOffset, "ArrayDimensions", "UInt32", hf_opcua_ArrayDimensions, parseUInt32, ett_opcua_array_UInt32);
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsAbstract);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReferenceTypeNode(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ReferenceTypeNode", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ReferenceTypeNode);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pOffset);
parseQualifiedName(subtree, tvb, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsAbstract);
parseBoolean(subtree, tvb, pOffset, hf_opcua_Symmetric);
parseLocalizedText(subtree, tvb, pOffset, "InverseName");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMethodNode(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: MethodNode", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_MethodNode);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pOffset);
parseQualifiedName(subtree, tvb, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseBoolean(subtree, tvb, pOffset, hf_opcua_Executable);
parseBoolean(subtree, tvb, pOffset, hf_opcua_UserExecutable);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseViewNode(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ViewNode", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ViewNode);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pOffset);
parseQualifiedName(subtree, tvb, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseBoolean(subtree, tvb, pOffset, hf_opcua_ContainsNoLoops);
parseByte(subtree, tvb, pOffset, hf_opcua_EventNotifier);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDataTypeNode(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: DataTypeNode", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DataTypeNode);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseNodeClass(subtree, tvb, pOffset);
parseQualifiedName(subtree, tvb, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseArrayComplex(subtree, tvb, pOffset, "References", "ReferenceNode", parseReferenceNode, ett_opcua_array_ReferenceNode);
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsAbstract);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReferenceNode(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ReferenceNode", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ReferenceNode);
parseNodeId(subtree, tvb, pOffset, "ReferenceTypeId");
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsInverse);
parseExpandedNodeId(subtree, tvb, pOffset, "TargetId");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseArgument(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: Argument", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_Argument);
parseString(subtree, tvb, pOffset, hf_opcua_Name);
parseNodeId(subtree, tvb, pOffset, "DataType");
parseInt32(subtree, tvb, pOffset, hf_opcua_ValueRank);
parseArraySimple(subtree, tvb, pOffset, "ArrayDimensions", "UInt32", hf_opcua_ArrayDimensions, parseUInt32, ett_opcua_array_UInt32);
parseLocalizedText(subtree, tvb, pOffset, "Description");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEnumValueType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: EnumValueType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_EnumValueType);
parseInt64(subtree, tvb, pOffset, hf_opcua_Value);
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTimeZoneDataType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: TimeZoneDataType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TimeZoneDataType);
parseInt16(subtree, tvb, pOffset, hf_opcua_Offset);
parseBoolean(subtree, tvb, pOffset, hf_opcua_DaylightSavingInOffset);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseApplicationDescription(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ApplicationDescription", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ApplicationDescription);
parseString(subtree, tvb, pOffset, hf_opcua_ApplicationUri);
parseString(subtree, tvb, pOffset, hf_opcua_ProductUri);
parseLocalizedText(subtree, tvb, pOffset, "ApplicationName");
parseApplicationType(subtree, tvb, pOffset);
parseString(subtree, tvb, pOffset, hf_opcua_GatewayServerUri);
parseString(subtree, tvb, pOffset, hf_opcua_DiscoveryProfileUri);
parseArraySimple(subtree, tvb, pOffset, "DiscoveryUrls", "String", hf_opcua_DiscoveryUrls, parseString, ett_opcua_array_String);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRequestHeader(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: RequestHeader", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RequestHeader);
parseNodeId(subtree, tvb, pOffset, "AuthenticationToken");
parseDateTime(subtree, tvb, pOffset, hf_opcua_Timestamp);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestHandle);
parseUInt32(subtree, tvb, pOffset, hf_opcua_ReturnDiagnostics);
parseString(subtree, tvb, pOffset, hf_opcua_AuditEntryId);
parseUInt32(subtree, tvb, pOffset, hf_opcua_TimeoutHint);
parseExtensionObject(subtree, tvb, pOffset, "AdditionalHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseResponseHeader(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ResponseHeader", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ResponseHeader);
parseDateTime(subtree, tvb, pOffset, hf_opcua_Timestamp);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestHandle);
parseStatusCode(subtree, tvb, pOffset, hf_opcua_ServiceResult);
parseDiagnosticInfo(subtree, tvb, pOffset, "ServiceDiagnostics");
parseArraySimple(subtree, tvb, pOffset, "StringTable", "String", hf_opcua_StringTable, parseString, ett_opcua_array_String);
parseExtensionObject(subtree, tvb, pOffset, "AdditionalHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUserTokenPolicy(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: UserTokenPolicy", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_UserTokenPolicy);
parseString(subtree, tvb, pOffset, hf_opcua_PolicyId);
parseUserTokenType(subtree, tvb, pOffset);
parseString(subtree, tvb, pOffset, hf_opcua_IssuedTokenType);
parseString(subtree, tvb, pOffset, hf_opcua_IssuerEndpointUrl);
parseString(subtree, tvb, pOffset, hf_opcua_SecurityPolicyUri);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEndpointDescription(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: EndpointDescription", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_EndpointDescription);
parseString(subtree, tvb, pOffset, hf_opcua_EndpointUrl);
parseApplicationDescription(subtree, tvb, pOffset, "Server");
parseByteString(subtree, tvb, pOffset, hf_opcua_ServerCertificate);
parseMessageSecurityMode(subtree, tvb, pOffset);
parseString(subtree, tvb, pOffset, hf_opcua_SecurityPolicyUri);
parseArrayComplex(subtree, tvb, pOffset, "UserIdentityTokens", "UserTokenPolicy", parseUserTokenPolicy, ett_opcua_array_UserTokenPolicy);
parseString(subtree, tvb, pOffset, hf_opcua_TransportProfileUri);
parseByte(subtree, tvb, pOffset, hf_opcua_SecurityLevel);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRegisteredServer(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: RegisteredServer", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RegisteredServer);
parseString(subtree, tvb, pOffset, hf_opcua_ServerUri);
parseString(subtree, tvb, pOffset, hf_opcua_ProductUri);
parseArrayComplex(subtree, tvb, pOffset, "ServerNames", "LocalizedText", parseLocalizedText, ett_opcua_array_LocalizedText);
parseApplicationType(subtree, tvb, pOffset);
parseString(subtree, tvb, pOffset, hf_opcua_GatewayServerUri);
parseArraySimple(subtree, tvb, pOffset, "DiscoveryUrls", "String", hf_opcua_DiscoveryUrls, parseString, ett_opcua_array_String);
parseString(subtree, tvb, pOffset, hf_opcua_SemaphoreFilePath);
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsOnline);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseChannelSecurityToken(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ChannelSecurityToken", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ChannelSecurityToken);
parseUInt32(subtree, tvb, pOffset, hf_opcua_ChannelId);
parseUInt32(subtree, tvb, pOffset, hf_opcua_TokenId);
parseDateTime(subtree, tvb, pOffset, hf_opcua_CreatedAt);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RevisedLifetime);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSignedSoftwareCertificate(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: SignedSoftwareCertificate", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SignedSoftwareCertificate);
parseByteString(subtree, tvb, pOffset, hf_opcua_CertificateData);
parseByteString(subtree, tvb, pOffset, hf_opcua_Signature);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSignatureData(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: SignatureData", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SignatureData);
parseString(subtree, tvb, pOffset, hf_opcua_Algorithm);
parseByteString(subtree, tvb, pOffset, hf_opcua_Signature);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUserIdentityToken(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: UserIdentityToken", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_UserIdentityToken);
parseString(subtree, tvb, pOffset, hf_opcua_PolicyId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAnonymousIdentityToken(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: AnonymousIdentityToken", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AnonymousIdentityToken);
parseString(subtree, tvb, pOffset, hf_opcua_PolicyId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUserNameIdentityToken(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: UserNameIdentityToken", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_UserNameIdentityToken);
parseString(subtree, tvb, pOffset, hf_opcua_PolicyId);
parseString(subtree, tvb, pOffset, hf_opcua_UserName);
parseByteString(subtree, tvb, pOffset, hf_opcua_Password);
parseString(subtree, tvb, pOffset, hf_opcua_EncryptionAlgorithm);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseX509IdentityToken(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: X509IdentityToken", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_X509IdentityToken);
parseString(subtree, tvb, pOffset, hf_opcua_PolicyId);
parseByteString(subtree, tvb, pOffset, hf_opcua_CertificateData);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseIssuedIdentityToken(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: IssuedIdentityToken", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_IssuedIdentityToken);
parseString(subtree, tvb, pOffset, hf_opcua_PolicyId);
parseByteString(subtree, tvb, pOffset, hf_opcua_TokenData);
parseString(subtree, tvb, pOffset, hf_opcua_EncryptionAlgorithm);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseNodeAttributes(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: NodeAttributes", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_NodeAttributes);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseObjectAttributes(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ObjectAttributes", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ObjectAttributes);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseByte(subtree, tvb, pOffset, hf_opcua_EventNotifier);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseVariableAttributes(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: VariableAttributes", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_VariableAttributes);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseVariant(subtree, tvb, pOffset, "Value");
parseNodeId(subtree, tvb, pOffset, "DataType");
parseInt32(subtree, tvb, pOffset, hf_opcua_ValueRank);
parseArraySimple(subtree, tvb, pOffset, "ArrayDimensions", "UInt32", hf_opcua_ArrayDimensions, parseUInt32, ett_opcua_array_UInt32);
parseByte(subtree, tvb, pOffset, hf_opcua_AccessLevel);
parseByte(subtree, tvb, pOffset, hf_opcua_UserAccessLevel);
parseDouble(subtree, tvb, pOffset, hf_opcua_MinimumSamplingInterval);
parseBoolean(subtree, tvb, pOffset, hf_opcua_Historizing);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMethodAttributes(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: MethodAttributes", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_MethodAttributes);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseBoolean(subtree, tvb, pOffset, hf_opcua_Executable);
parseBoolean(subtree, tvb, pOffset, hf_opcua_UserExecutable);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseObjectTypeAttributes(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ObjectTypeAttributes", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ObjectTypeAttributes);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsAbstract);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseVariableTypeAttributes(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: VariableTypeAttributes", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_VariableTypeAttributes);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseVariant(subtree, tvb, pOffset, "Value");
parseNodeId(subtree, tvb, pOffset, "DataType");
parseInt32(subtree, tvb, pOffset, hf_opcua_ValueRank);
parseArraySimple(subtree, tvb, pOffset, "ArrayDimensions", "UInt32", hf_opcua_ArrayDimensions, parseUInt32, ett_opcua_array_UInt32);
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsAbstract);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReferenceTypeAttributes(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ReferenceTypeAttributes", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ReferenceTypeAttributes);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsAbstract);
parseBoolean(subtree, tvb, pOffset, hf_opcua_Symmetric);
parseLocalizedText(subtree, tvb, pOffset, "InverseName");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDataTypeAttributes(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: DataTypeAttributes", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DataTypeAttributes);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsAbstract);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseViewAttributes(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ViewAttributes", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ViewAttributes);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SpecifiedAttributes);
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
parseUInt32(subtree, tvb, pOffset, hf_opcua_WriteMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UserWriteMask);
parseBoolean(subtree, tvb, pOffset, hf_opcua_ContainsNoLoops);
parseByte(subtree, tvb, pOffset, hf_opcua_EventNotifier);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAddNodesItem(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: AddNodesItem", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AddNodesItem);
parseExpandedNodeId(subtree, tvb, pOffset, "ParentNodeId");
parseNodeId(subtree, tvb, pOffset, "ReferenceTypeId");
parseExpandedNodeId(subtree, tvb, pOffset, "RequestedNewNodeId");
parseQualifiedName(subtree, tvb, pOffset, "BrowseName");
parseNodeClass(subtree, tvb, pOffset);
parseExtensionObject(subtree, tvb, pOffset, "NodeAttributes");
parseExpandedNodeId(subtree, tvb, pOffset, "TypeDefinition");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAddNodesResult(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: AddNodesResult", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AddNodesResult);
parseStatusCode(subtree, tvb, pOffset, hf_opcua_StatusCode);
parseNodeId(subtree, tvb, pOffset, "AddedNodeId");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAddReferencesItem(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: AddReferencesItem", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AddReferencesItem);
parseNodeId(subtree, tvb, pOffset, "SourceNodeId");
parseNodeId(subtree, tvb, pOffset, "ReferenceTypeId");
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsForward);
parseString(subtree, tvb, pOffset, hf_opcua_TargetServerUri);
parseExpandedNodeId(subtree, tvb, pOffset, "TargetNodeId");
parseNodeClass(subtree, tvb, pOffset);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteNodesItem(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: DeleteNodesItem", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteNodesItem);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseBoolean(subtree, tvb, pOffset, hf_opcua_DeleteTargetReferences);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteReferencesItem(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: DeleteReferencesItem", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteReferencesItem);
parseNodeId(subtree, tvb, pOffset, "SourceNodeId");
parseNodeId(subtree, tvb, pOffset, "ReferenceTypeId");
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsForward);
parseExpandedNodeId(subtree, tvb, pOffset, "TargetNodeId");
parseBoolean(subtree, tvb, pOffset, hf_opcua_DeleteBidirectional);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseViewDescription(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ViewDescription", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ViewDescription);
parseNodeId(subtree, tvb, pOffset, "ViewId");
parseDateTime(subtree, tvb, pOffset, hf_opcua_Timestamp);
parseUInt32(subtree, tvb, pOffset, hf_opcua_ViewVersion);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowseDescription(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: BrowseDescription", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_BrowseDescription);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseBrowseDirection(subtree, tvb, pOffset);
parseNodeId(subtree, tvb, pOffset, "ReferenceTypeId");
parseBoolean(subtree, tvb, pOffset, hf_opcua_IncludeSubtypes);
parseUInt32(subtree, tvb, pOffset, hf_opcua_NodeClassMask);
parseUInt32(subtree, tvb, pOffset, hf_opcua_ResultMask);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReferenceDescription(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ReferenceDescription", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ReferenceDescription);
parseNodeId(subtree, tvb, pOffset, "ReferenceTypeId");
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsForward);
parseExpandedNodeId(subtree, tvb, pOffset, "NodeId");
parseQualifiedName(subtree, tvb, pOffset, "BrowseName");
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseNodeClass(subtree, tvb, pOffset);
parseExpandedNodeId(subtree, tvb, pOffset, "TypeDefinition");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowseResult(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: BrowseResult", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_BrowseResult);
parseStatusCode(subtree, tvb, pOffset, hf_opcua_StatusCode);
parseByteString(subtree, tvb, pOffset, hf_opcua_ContinuationPoint);
parseArrayComplex(subtree, tvb, pOffset, "References", "ReferenceDescription", parseReferenceDescription, ett_opcua_array_ReferenceDescription);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRelativePathElement(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: RelativePathElement", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RelativePathElement);
parseNodeId(subtree, tvb, pOffset, "ReferenceTypeId");
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsInverse);
parseBoolean(subtree, tvb, pOffset, hf_opcua_IncludeSubtypes);
parseQualifiedName(subtree, tvb, pOffset, "TargetName");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRelativePath(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: RelativePath", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RelativePath);
parseArrayComplex(subtree, tvb, pOffset, "Elements", "RelativePathElement", parseRelativePathElement, ett_opcua_array_RelativePathElement);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowsePath(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: BrowsePath", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_BrowsePath);
parseNodeId(subtree, tvb, pOffset, "StartingNode");
parseRelativePath(subtree, tvb, pOffset, "RelativePath");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowsePathTarget(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: BrowsePathTarget", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_BrowsePathTarget);
parseExpandedNodeId(subtree, tvb, pOffset, "TargetId");
parseUInt32(subtree, tvb, pOffset, hf_opcua_RemainingPathIndex);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowsePathResult(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: BrowsePathResult", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_BrowsePathResult);
parseStatusCode(subtree, tvb, pOffset, hf_opcua_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "Targets", "BrowsePathTarget", parseBrowsePathTarget, ett_opcua_array_BrowsePathTarget);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEndpointConfiguration(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: EndpointConfiguration", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_EndpointConfiguration);
parseInt32(subtree, tvb, pOffset, hf_opcua_OperationTimeout);
parseBoolean(subtree, tvb, pOffset, hf_opcua_UseBinaryEncoding);
parseInt32(subtree, tvb, pOffset, hf_opcua_MaxStringLength);
parseInt32(subtree, tvb, pOffset, hf_opcua_MaxByteStringLength);
parseInt32(subtree, tvb, pOffset, hf_opcua_MaxArrayLength);
parseInt32(subtree, tvb, pOffset, hf_opcua_MaxMessageSize);
parseInt32(subtree, tvb, pOffset, hf_opcua_MaxBufferSize);
parseInt32(subtree, tvb, pOffset, hf_opcua_ChannelLifetime);
parseInt32(subtree, tvb, pOffset, hf_opcua_SecurityTokenLifetime);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSupportedProfile(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: SupportedProfile", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SupportedProfile);
parseString(subtree, tvb, pOffset, hf_opcua_OrganizationUri);
parseString(subtree, tvb, pOffset, hf_opcua_ProfileId);
parseString(subtree, tvb, pOffset, hf_opcua_ComplianceTool);
parseDateTime(subtree, tvb, pOffset, hf_opcua_ComplianceDate);
parseComplianceLevel(subtree, tvb, pOffset);
parseArraySimple(subtree, tvb, pOffset, "UnsupportedUnitIds", "String", hf_opcua_UnsupportedUnitIds, parseString, ett_opcua_array_String);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSoftwareCertificate(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: SoftwareCertificate", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SoftwareCertificate);
parseString(subtree, tvb, pOffset, hf_opcua_ProductName);
parseString(subtree, tvb, pOffset, hf_opcua_ProductUri);
parseString(subtree, tvb, pOffset, hf_opcua_VendorName);
parseByteString(subtree, tvb, pOffset, hf_opcua_VendorProductCertificate);
parseString(subtree, tvb, pOffset, hf_opcua_SoftwareVersion);
parseString(subtree, tvb, pOffset, hf_opcua_BuildNumber);
parseDateTime(subtree, tvb, pOffset, hf_opcua_BuildDate);
parseString(subtree, tvb, pOffset, hf_opcua_IssuedBy);
parseDateTime(subtree, tvb, pOffset, hf_opcua_IssueDate);
parseArrayComplex(subtree, tvb, pOffset, "SupportedProfiles", "SupportedProfile", parseSupportedProfile, ett_opcua_array_SupportedProfile);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseQueryDataDescription(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: QueryDataDescription", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_QueryDataDescription);
parseRelativePath(subtree, tvb, pOffset, "RelativePath");
parseUInt32(subtree, tvb, pOffset, hf_opcua_AttributeId);
parseString(subtree, tvb, pOffset, hf_opcua_IndexRange);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseNodeTypeDescription(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: NodeTypeDescription", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_NodeTypeDescription);
parseExpandedNodeId(subtree, tvb, pOffset, "TypeDefinitionNode");
parseBoolean(subtree, tvb, pOffset, hf_opcua_IncludeSubTypes);
parseArrayComplex(subtree, tvb, pOffset, "DataToReturn", "QueryDataDescription", parseQueryDataDescription, ett_opcua_array_QueryDataDescription);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseQueryDataSet(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: QueryDataSet", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_QueryDataSet);
parseExpandedNodeId(subtree, tvb, pOffset, "NodeId");
parseExpandedNodeId(subtree, tvb, pOffset, "TypeDefinitionNode");
parseArrayComplex(subtree, tvb, pOffset, "Values", "Variant", parseVariant, ett_opcua_array_Variant);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseNodeReference(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: NodeReference", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_NodeReference);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseNodeId(subtree, tvb, pOffset, "ReferenceTypeId");
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsForward);
parseArrayComplex(subtree, tvb, pOffset, "ReferencedNodeIds", "NodeId", parseNodeId, ett_opcua_array_NodeId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseContentFilterElement(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ContentFilterElement", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ContentFilterElement);
parseFilterOperator(subtree, tvb, pOffset);
parseArrayComplex(subtree, tvb, pOffset, "FilterOperands", "ExtensionObject", parseExtensionObject, ett_opcua_array_ExtensionObject);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseContentFilter(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ContentFilter", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ContentFilter);
parseArrayComplex(subtree, tvb, pOffset, "Elements", "ContentFilterElement", parseContentFilterElement, ett_opcua_array_ContentFilterElement);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseElementOperand(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ElementOperand", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ElementOperand);
parseUInt32(subtree, tvb, pOffset, hf_opcua_Index);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseLiteralOperand(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: LiteralOperand", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_LiteralOperand);
parseVariant(subtree, tvb, pOffset, "Value");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAttributeOperand(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: AttributeOperand", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AttributeOperand);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseString(subtree, tvb, pOffset, hf_opcua_Alias);
parseRelativePath(subtree, tvb, pOffset, "BrowsePath");
parseUInt32(subtree, tvb, pOffset, hf_opcua_AttributeId);
parseString(subtree, tvb, pOffset, hf_opcua_IndexRange);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSimpleAttributeOperand(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: SimpleAttributeOperand", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SimpleAttributeOperand);
parseNodeId(subtree, tvb, pOffset, "TypeDefinitionId");
parseArrayComplex(subtree, tvb, pOffset, "BrowsePath", "QualifiedName", parseQualifiedName, ett_opcua_array_QualifiedName);
parseUInt32(subtree, tvb, pOffset, hf_opcua_AttributeId);
parseString(subtree, tvb, pOffset, hf_opcua_IndexRange);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseContentFilterElementResult(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ContentFilterElementResult", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ContentFilterElementResult);
parseStatusCode(subtree, tvb, pOffset, hf_opcua_StatusCode);
parseArraySimple(subtree, tvb, pOffset, "OperandStatusCodes", "StatusCode", hf_opcua_OperandStatusCodes, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "OperandDiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseContentFilterResult(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ContentFilterResult", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ContentFilterResult);
parseArrayComplex(subtree, tvb, pOffset, "ElementResults", "ContentFilterElementResult", parseContentFilterElementResult, ett_opcua_array_ContentFilterElementResult);
parseArrayComplex(subtree, tvb, pOffset, "ElementDiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseParsingResult(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ParsingResult", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ParsingResult);
parseStatusCode(subtree, tvb, pOffset, hf_opcua_StatusCode);
parseArraySimple(subtree, tvb, pOffset, "DataStatusCodes", "StatusCode", hf_opcua_DataStatusCodes, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DataDiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReadValueId(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ReadValueId", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ReadValueId);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseUInt32(subtree, tvb, pOffset, hf_opcua_AttributeId);
parseString(subtree, tvb, pOffset, hf_opcua_IndexRange);
parseQualifiedName(subtree, tvb, pOffset, "DataEncoding");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryReadValueId(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: HistoryReadValueId", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryReadValueId);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseString(subtree, tvb, pOffset, hf_opcua_IndexRange);
parseQualifiedName(subtree, tvb, pOffset, "DataEncoding");
parseByteString(subtree, tvb, pOffset, hf_opcua_ContinuationPoint);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryReadResult(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: HistoryReadResult", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryReadResult);
parseStatusCode(subtree, tvb, pOffset, hf_opcua_StatusCode);
parseByteString(subtree, tvb, pOffset, hf_opcua_ContinuationPoint);
parseExtensionObject(subtree, tvb, pOffset, "HistoryData");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReadEventDetails(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ReadEventDetails", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ReadEventDetails);
parseUInt32(subtree, tvb, pOffset, hf_opcua_NumValuesPerNode);
parseDateTime(subtree, tvb, pOffset, hf_opcua_StartTime);
parseDateTime(subtree, tvb, pOffset, hf_opcua_EndTime);
parseEventFilter(subtree, tvb, pOffset, "Filter");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReadRawModifiedDetails(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ReadRawModifiedDetails", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ReadRawModifiedDetails);
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsReadModified);
parseDateTime(subtree, tvb, pOffset, hf_opcua_StartTime);
parseDateTime(subtree, tvb, pOffset, hf_opcua_EndTime);
parseUInt32(subtree, tvb, pOffset, hf_opcua_NumValuesPerNode);
parseBoolean(subtree, tvb, pOffset, hf_opcua_ReturnBounds);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReadProcessedDetails(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ReadProcessedDetails", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ReadProcessedDetails);
parseDateTime(subtree, tvb, pOffset, hf_opcua_StartTime);
parseDateTime(subtree, tvb, pOffset, hf_opcua_EndTime);
parseDouble(subtree, tvb, pOffset, hf_opcua_ProcessingInterval);
parseArrayComplex(subtree, tvb, pOffset, "AggregateType", "NodeId", parseNodeId, ett_opcua_array_NodeId);
parseAggregateConfiguration(subtree, tvb, pOffset, "AggregateConfiguration");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReadAtTimeDetails(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ReadAtTimeDetails", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ReadAtTimeDetails);
parseArraySimple(subtree, tvb, pOffset, "ReqTimes", "DateTime", hf_opcua_ReqTimes, parseDateTime, ett_opcua_array_DateTime);
parseBoolean(subtree, tvb, pOffset, hf_opcua_UseSimpleBounds);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryData(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: HistoryData", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryData);
parseArrayComplex(subtree, tvb, pOffset, "DataValues", "DataValue", parseDataValue, ett_opcua_array_DataValue);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseModificationInfo(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ModificationInfo", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ModificationInfo);
parseDateTime(subtree, tvb, pOffset, hf_opcua_ModificationTime);
parseHistoryUpdateType(subtree, tvb, pOffset);
parseString(subtree, tvb, pOffset, hf_opcua_UserName);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryModifiedData(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: HistoryModifiedData", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryModifiedData);
parseArrayComplex(subtree, tvb, pOffset, "DataValues", "DataValue", parseDataValue, ett_opcua_array_DataValue);
parseArrayComplex(subtree, tvb, pOffset, "ModificationInfos", "ModificationInfo", parseModificationInfo, ett_opcua_array_ModificationInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryEvent(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: HistoryEvent", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryEvent);
parseArrayComplex(subtree, tvb, pOffset, "Events", "HistoryEventFieldList", parseHistoryEventFieldList, ett_opcua_array_HistoryEventFieldList);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseWriteValue(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: WriteValue", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_WriteValue);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseUInt32(subtree, tvb, pOffset, hf_opcua_AttributeId);
parseString(subtree, tvb, pOffset, hf_opcua_IndexRange);
parseDataValue(subtree, tvb, pOffset, "Value");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryUpdateDetails(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: HistoryUpdateDetails", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryUpdateDetails);
parseNodeId(subtree, tvb, pOffset, "NodeId");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUpdateDataDetails(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: UpdateDataDetails", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_UpdateDataDetails);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parsePerformUpdateType(subtree, tvb, pOffset);
parseArrayComplex(subtree, tvb, pOffset, "UpdateValues", "DataValue", parseDataValue, ett_opcua_array_DataValue);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUpdateStructureDataDetails(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: UpdateStructureDataDetails", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_UpdateStructureDataDetails);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parsePerformUpdateType(subtree, tvb, pOffset);
parseArrayComplex(subtree, tvb, pOffset, "UpdateValues", "DataValue", parseDataValue, ett_opcua_array_DataValue);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUpdateEventDetails(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: UpdateEventDetails", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_UpdateEventDetails);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parsePerformUpdateType(subtree, tvb, pOffset);
parseEventFilter(subtree, tvb, pOffset, "Filter");
parseArrayComplex(subtree, tvb, pOffset, "EventData", "HistoryEventFieldList", parseHistoryEventFieldList, ett_opcua_array_HistoryEventFieldList);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteRawModifiedDetails(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: DeleteRawModifiedDetails", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteRawModifiedDetails);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseBoolean(subtree, tvb, pOffset, hf_opcua_IsDeleteModified);
parseDateTime(subtree, tvb, pOffset, hf_opcua_StartTime);
parseDateTime(subtree, tvb, pOffset, hf_opcua_EndTime);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteAtTimeDetails(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: DeleteAtTimeDetails", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteAtTimeDetails);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseArraySimple(subtree, tvb, pOffset, "ReqTimes", "DateTime", hf_opcua_ReqTimes, parseDateTime, ett_opcua_array_DateTime);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteEventDetails(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: DeleteEventDetails", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteEventDetails);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseArraySimple(subtree, tvb, pOffset, "EventIds", "ByteString", hf_opcua_EventIds, parseByteString, ett_opcua_array_ByteString);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryUpdateResult(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: HistoryUpdateResult", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryUpdateResult);
parseStatusCode(subtree, tvb, pOffset, hf_opcua_StatusCode);
parseArraySimple(subtree, tvb, pOffset, "OperationResults", "StatusCode", hf_opcua_OperationResults, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCallMethodRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: CallMethodRequest", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CallMethodRequest);
parseNodeId(subtree, tvb, pOffset, "ObjectId");
parseNodeId(subtree, tvb, pOffset, "MethodId");
parseArrayComplex(subtree, tvb, pOffset, "InputArguments", "Variant", parseVariant, ett_opcua_array_Variant);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCallMethodResult(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: CallMethodResult", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CallMethodResult);
parseStatusCode(subtree, tvb, pOffset, hf_opcua_StatusCode);
parseArraySimple(subtree, tvb, pOffset, "InputArgumentResults", "StatusCode", hf_opcua_InputArgumentResults, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "InputArgumentDiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
parseArrayComplex(subtree, tvb, pOffset, "OutputArguments", "Variant", parseVariant, ett_opcua_array_Variant);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDataChangeFilter(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: DataChangeFilter", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DataChangeFilter);
parseDataChangeTrigger(subtree, tvb, pOffset);
parseUInt32(subtree, tvb, pOffset, hf_opcua_DeadbandType);
parseDouble(subtree, tvb, pOffset, hf_opcua_DeadbandValue);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEventFilter(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: EventFilter", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_EventFilter);
parseArrayComplex(subtree, tvb, pOffset, "SelectClauses", "SimpleAttributeOperand", parseSimpleAttributeOperand, ett_opcua_array_SimpleAttributeOperand);
parseContentFilter(subtree, tvb, pOffset, "WhereClause");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAggregateConfiguration(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: AggregateConfiguration", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AggregateConfiguration);
parseBoolean(subtree, tvb, pOffset, hf_opcua_UseServerCapabilitiesDefaults);
parseBoolean(subtree, tvb, pOffset, hf_opcua_TreatUncertainAsBad);
parseByte(subtree, tvb, pOffset, hf_opcua_PercentDataBad);
parseByte(subtree, tvb, pOffset, hf_opcua_PercentDataGood);
parseBoolean(subtree, tvb, pOffset, hf_opcua_UseSlopedExtrapolation);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAggregateFilter(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: AggregateFilter", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AggregateFilter);
parseDateTime(subtree, tvb, pOffset, hf_opcua_StartTime);
parseNodeId(subtree, tvb, pOffset, "AggregateType");
parseDouble(subtree, tvb, pOffset, hf_opcua_ProcessingInterval);
parseAggregateConfiguration(subtree, tvb, pOffset, "AggregateConfiguration");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEventFilterResult(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: EventFilterResult", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_EventFilterResult);
parseArraySimple(subtree, tvb, pOffset, "SelectClauseResults", "StatusCode", hf_opcua_SelectClauseResults, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "SelectClauseDiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
parseContentFilterResult(subtree, tvb, pOffset, "WhereClauseResult");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAggregateFilterResult(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: AggregateFilterResult", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AggregateFilterResult);
parseDateTime(subtree, tvb, pOffset, hf_opcua_RevisedStartTime);
parseDouble(subtree, tvb, pOffset, hf_opcua_RevisedProcessingInterval);
parseAggregateConfiguration(subtree, tvb, pOffset, "RevisedAggregateConfiguration");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMonitoringParameters(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: MonitoringParameters", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_MonitoringParameters);
parseUInt32(subtree, tvb, pOffset, hf_opcua_ClientHandle);
parseDouble(subtree, tvb, pOffset, hf_opcua_SamplingInterval);
parseExtensionObject(subtree, tvb, pOffset, "Filter");
parseUInt32(subtree, tvb, pOffset, hf_opcua_QueueSize);
parseBoolean(subtree, tvb, pOffset, hf_opcua_DiscardOldest);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMonitoredItemCreateRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: MonitoredItemCreateRequest", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_MonitoredItemCreateRequest);
parseReadValueId(subtree, tvb, pOffset, "ItemToMonitor");
parseMonitoringMode(subtree, tvb, pOffset);
parseMonitoringParameters(subtree, tvb, pOffset, "RequestedParameters");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMonitoredItemCreateResult(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: MonitoredItemCreateResult", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_MonitoredItemCreateResult);
parseStatusCode(subtree, tvb, pOffset, hf_opcua_StatusCode);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MonitoredItemId);
parseDouble(subtree, tvb, pOffset, hf_opcua_RevisedSamplingInterval);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RevisedQueueSize);
parseExtensionObject(subtree, tvb, pOffset, "FilterResult");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMonitoredItemModifyRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: MonitoredItemModifyRequest", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_MonitoredItemModifyRequest);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MonitoredItemId);
parseMonitoringParameters(subtree, tvb, pOffset, "RequestedParameters");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMonitoredItemModifyResult(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: MonitoredItemModifyResult", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_MonitoredItemModifyResult);
parseStatusCode(subtree, tvb, pOffset, hf_opcua_StatusCode);
parseDouble(subtree, tvb, pOffset, hf_opcua_RevisedSamplingInterval);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RevisedQueueSize);
parseExtensionObject(subtree, tvb, pOffset, "FilterResult");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseNotificationMessage(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: NotificationMessage", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_NotificationMessage);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SequenceNumber);
parseDateTime(subtree, tvb, pOffset, hf_opcua_PublishTime);
parseArrayComplex(subtree, tvb, pOffset, "NotificationData", "ExtensionObject", parseExtensionObject, ett_opcua_array_ExtensionObject);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDataChangeNotification(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: DataChangeNotification", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DataChangeNotification);
parseArrayComplex(subtree, tvb, pOffset, "MonitoredItems", "MonitoredItemNotification", parseMonitoredItemNotification, ett_opcua_array_MonitoredItemNotification);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseMonitoredItemNotification(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: MonitoredItemNotification", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_MonitoredItemNotification);
parseUInt32(subtree, tvb, pOffset, hf_opcua_ClientHandle);
parseDataValue(subtree, tvb, pOffset, "Value");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEventNotificationList(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: EventNotificationList", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_EventNotificationList);
parseArrayComplex(subtree, tvb, pOffset, "Events", "EventFieldList", parseEventFieldList, ett_opcua_array_EventFieldList);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEventFieldList(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: EventFieldList", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_EventFieldList);
parseUInt32(subtree, tvb, pOffset, hf_opcua_ClientHandle);
parseArrayComplex(subtree, tvb, pOffset, "EventFields", "Variant", parseVariant, ett_opcua_array_Variant);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryEventFieldList(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: HistoryEventFieldList", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryEventFieldList);
parseArrayComplex(subtree, tvb, pOffset, "EventFields", "Variant", parseVariant, ett_opcua_array_Variant);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseStatusChangeNotification(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: StatusChangeNotification", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_StatusChangeNotification);
parseStatusCode(subtree, tvb, pOffset, hf_opcua_Status);
parseDiagnosticInfo(subtree, tvb, pOffset, "DiagnosticInfo");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSubscriptionAcknowledgement(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: SubscriptionAcknowledgement", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SubscriptionAcknowledgement);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SequenceNumber);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTransferResult(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: TransferResult", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TransferResult);
parseStatusCode(subtree, tvb, pOffset, hf_opcua_StatusCode);
parseArraySimple(subtree, tvb, pOffset, "AvailableSequenceNumbers", "UInt32", hf_opcua_AvailableSequenceNumbers, parseUInt32, ett_opcua_array_UInt32);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseScalarTestType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ScalarTestType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ScalarTestType);
parseBoolean(subtree, tvb, pOffset, hf_opcua_Boolean);
parseSByte(subtree, tvb, pOffset, hf_opcua_SByte);
parseByte(subtree, tvb, pOffset, hf_opcua_Byte);
parseInt16(subtree, tvb, pOffset, hf_opcua_Int16);
parseUInt16(subtree, tvb, pOffset, hf_opcua_UInt16);
parseInt32(subtree, tvb, pOffset, hf_opcua_Int32);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UInt32);
parseInt64(subtree, tvb, pOffset, hf_opcua_Int64);
parseUInt64(subtree, tvb, pOffset, hf_opcua_UInt64);
parseFloat(subtree, tvb, pOffset, hf_opcua_Float);
parseDouble(subtree, tvb, pOffset, hf_opcua_Double);
parseString(subtree, tvb, pOffset, hf_opcua_String);
parseDateTime(subtree, tvb, pOffset, hf_opcua_DateTime);
parseGuid(subtree, tvb, pOffset, hf_opcua_Guid);
parseByteString(subtree, tvb, pOffset, hf_opcua_ByteString);
parseXmlElement(subtree, tvb, pOffset, hf_opcua_XmlElement);
parseNodeId(subtree, tvb, pOffset, "NodeId");
parseExpandedNodeId(subtree, tvb, pOffset, "ExpandedNodeId");
parseStatusCode(subtree, tvb, pOffset, hf_opcua_StatusCode);
parseDiagnosticInfo(subtree, tvb, pOffset, "DiagnosticInfo");
parseQualifiedName(subtree, tvb, pOffset, "QualifiedName");
parseLocalizedText(subtree, tvb, pOffset, "LocalizedText");
parseExtensionObject(subtree, tvb, pOffset, "ExtensionObject");
parseDataValue(subtree, tvb, pOffset, "DataValue");
parseEnumeratedTestType(subtree, tvb, pOffset);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseArrayTestType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ArrayTestType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ArrayTestType);
parseArraySimple(subtree, tvb, pOffset, "Booleans", "Boolean", hf_opcua_Booleans, parseBoolean, ett_opcua_array_Boolean);
parseArraySimple(subtree, tvb, pOffset, "SBytes", "SByte", hf_opcua_SBytes, parseSByte, ett_opcua_array_SByte);
parseArraySimple(subtree, tvb, pOffset, "Int16s", "Int16", hf_opcua_Int16s, parseInt16, ett_opcua_array_Int16);
parseArraySimple(subtree, tvb, pOffset, "UInt16s", "UInt16", hf_opcua_UInt16s, parseUInt16, ett_opcua_array_UInt16);
parseArraySimple(subtree, tvb, pOffset, "Int32s", "Int32", hf_opcua_Int32s, parseInt32, ett_opcua_array_Int32);
parseArraySimple(subtree, tvb, pOffset, "UInt32s", "UInt32", hf_opcua_UInt32s, parseUInt32, ett_opcua_array_UInt32);
parseArraySimple(subtree, tvb, pOffset, "Int64s", "Int64", hf_opcua_Int64s, parseInt64, ett_opcua_array_Int64);
parseArraySimple(subtree, tvb, pOffset, "UInt64s", "UInt64", hf_opcua_UInt64s, parseUInt64, ett_opcua_array_UInt64);
parseArraySimple(subtree, tvb, pOffset, "Floats", "Float", hf_opcua_Floats, parseFloat, ett_opcua_array_Float);
parseArraySimple(subtree, tvb, pOffset, "Doubles", "Double", hf_opcua_Doubles, parseDouble, ett_opcua_array_Double);
parseArraySimple(subtree, tvb, pOffset, "Strings", "String", hf_opcua_Strings, parseString, ett_opcua_array_String);
parseArraySimple(subtree, tvb, pOffset, "DateTimes", "DateTime", hf_opcua_DateTimes, parseDateTime, ett_opcua_array_DateTime);
parseArraySimple(subtree, tvb, pOffset, "Guids", "Guid", hf_opcua_Guids, parseGuid, ett_opcua_array_Guid);
parseArraySimple(subtree, tvb, pOffset, "ByteStrings", "ByteString", hf_opcua_ByteStrings, parseByteString, ett_opcua_array_ByteString);
parseArraySimple(subtree, tvb, pOffset, "XmlElements", "XmlElement", hf_opcua_XmlElements, parseXmlElement, ett_opcua_array_XmlElement);
parseArrayComplex(subtree, tvb, pOffset, "NodeIds", "NodeId", parseNodeId, ett_opcua_array_NodeId);
parseArrayComplex(subtree, tvb, pOffset, "ExpandedNodeIds", "ExpandedNodeId", parseExpandedNodeId, ett_opcua_array_ExpandedNodeId);
parseArraySimple(subtree, tvb, pOffset, "StatusCodes", "StatusCode", hf_opcua_StatusCodes, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
parseArrayComplex(subtree, tvb, pOffset, "QualifiedNames", "QualifiedName", parseQualifiedName, ett_opcua_array_QualifiedName);
parseArrayComplex(subtree, tvb, pOffset, "LocalizedTexts", "LocalizedText", parseLocalizedText, ett_opcua_array_LocalizedText);
parseArrayComplex(subtree, tvb, pOffset, "ExtensionObjects", "ExtensionObject", parseExtensionObject, ett_opcua_array_ExtensionObject);
parseArrayComplex(subtree, tvb, pOffset, "DataValues", "DataValue", parseDataValue, ett_opcua_array_DataValue);
parseArrayComplex(subtree, tvb, pOffset, "Variants", "Variant", parseVariant, ett_opcua_array_Variant);
parseArrayEnum(subtree, tvb, pOffset, "EnumeratedValues", "EnumeratedTestType", parseEnumeratedTestType, ett_opcua_array_EnumeratedTestType);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCompositeTestType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: CompositeTestType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CompositeTestType);
parseScalarTestType(subtree, tvb, pOffset, "Field1");
parseArrayTestType(subtree, tvb, pOffset, "Field2");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBuildInfo(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: BuildInfo", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_BuildInfo);
parseString(subtree, tvb, pOffset, hf_opcua_ProductUri);
parseString(subtree, tvb, pOffset, hf_opcua_ManufacturerName);
parseString(subtree, tvb, pOffset, hf_opcua_ProductName);
parseString(subtree, tvb, pOffset, hf_opcua_SoftwareVersion);
parseString(subtree, tvb, pOffset, hf_opcua_BuildNumber);
parseDateTime(subtree, tvb, pOffset, hf_opcua_BuildDate);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRedundantServerDataType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: RedundantServerDataType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RedundantServerDataType);
parseString(subtree, tvb, pOffset, hf_opcua_ServerId);
parseByte(subtree, tvb, pOffset, hf_opcua_ServiceLevel);
parseServerState(subtree, tvb, pOffset);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEndpointUrlListDataType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: EndpointUrlListDataType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_EndpointUrlListDataType);
parseArraySimple(subtree, tvb, pOffset, "EndpointUrlList", "String", hf_opcua_EndpointUrlList, parseString, ett_opcua_array_String);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseNetworkGroupDataType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: NetworkGroupDataType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_NetworkGroupDataType);
parseString(subtree, tvb, pOffset, hf_opcua_ServerUri);
parseArrayComplex(subtree, tvb, pOffset, "NetworkPaths", "EndpointUrlListDataType", parseEndpointUrlListDataType, ett_opcua_array_EndpointUrlListDataType);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSamplingIntervalDiagnosticsDataType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: SamplingIntervalDiagnosticsDataType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SamplingIntervalDiagnosticsDataType);
parseDouble(subtree, tvb, pOffset, hf_opcua_SamplingInterval);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MonitoredItemCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxMonitoredItemCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_DisabledMonitoredItemCount);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseServerDiagnosticsSummaryDataType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ServerDiagnosticsSummaryDataType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ServerDiagnosticsSummaryDataType);
parseUInt32(subtree, tvb, pOffset, hf_opcua_ServerViewCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_CurrentSessionCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_CumulatedSessionCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SecurityRejectedSessionCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RejectedSessionCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SessionTimeoutCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SessionAbortCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_CurrentSubscriptionCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_CumulatedSubscriptionCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_PublishingIntervalCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_SecurityRejectedRequestsCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RejectedRequestsCount);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseServerStatusDataType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ServerStatusDataType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ServerStatusDataType);
parseDateTime(subtree, tvb, pOffset, hf_opcua_StartTime);
parseDateTime(subtree, tvb, pOffset, hf_opcua_CurrentTime);
parseServerState(subtree, tvb, pOffset);
parseBuildInfo(subtree, tvb, pOffset, "BuildInfo");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SecondsTillShutdown);
parseLocalizedText(subtree, tvb, pOffset, "ShutdownReason");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSessionDiagnosticsDataType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: SessionDiagnosticsDataType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SessionDiagnosticsDataType);
parseNodeId(subtree, tvb, pOffset, "SessionId");
parseString(subtree, tvb, pOffset, hf_opcua_SessionName);
parseApplicationDescription(subtree, tvb, pOffset, "ClientDescription");
parseString(subtree, tvb, pOffset, hf_opcua_ServerUri);
parseString(subtree, tvb, pOffset, hf_opcua_EndpointUrl);
parseArraySimple(subtree, tvb, pOffset, "LocaleIds", "String", hf_opcua_LocaleIds, parseString, ett_opcua_array_String);
parseDouble(subtree, tvb, pOffset, hf_opcua_ActualSessionTimeout);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxResponseMessageSize);
parseDateTime(subtree, tvb, pOffset, hf_opcua_ClientConnectionTime);
parseDateTime(subtree, tvb, pOffset, hf_opcua_ClientLastContactTime);
parseUInt32(subtree, tvb, pOffset, hf_opcua_CurrentSubscriptionsCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_CurrentMonitoredItemsCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_CurrentPublishRequestsInQueue);
parseServiceCounterDataType(subtree, tvb, pOffset, "TotalRequestCount");
parseUInt32(subtree, tvb, pOffset, hf_opcua_UnauthorizedRequestCount);
parseServiceCounterDataType(subtree, tvb, pOffset, "ReadCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "HistoryReadCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "WriteCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "HistoryUpdateCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "CallCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "CreateMonitoredItemsCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "ModifyMonitoredItemsCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "SetMonitoringModeCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "SetTriggeringCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "DeleteMonitoredItemsCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "CreateSubscriptionCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "ModifySubscriptionCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "SetPublishingModeCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "PublishCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "RepublishCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "TransferSubscriptionsCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "DeleteSubscriptionsCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "AddNodesCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "AddReferencesCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "DeleteNodesCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "DeleteReferencesCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "BrowseCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "BrowseNextCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "TranslateBrowsePathsToNodeIdsCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "QueryFirstCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "QueryNextCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "RegisterNodesCount");
parseServiceCounterDataType(subtree, tvb, pOffset, "UnregisterNodesCount");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSessionSecurityDiagnosticsDataType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: SessionSecurityDiagnosticsDataType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SessionSecurityDiagnosticsDataType);
parseNodeId(subtree, tvb, pOffset, "SessionId");
parseString(subtree, tvb, pOffset, hf_opcua_ClientUserIdOfSession);
parseArraySimple(subtree, tvb, pOffset, "ClientUserIdHistory", "String", hf_opcua_ClientUserIdHistory, parseString, ett_opcua_array_String);
parseString(subtree, tvb, pOffset, hf_opcua_AuthenticationMechanism);
parseString(subtree, tvb, pOffset, hf_opcua_Encoding);
parseString(subtree, tvb, pOffset, hf_opcua_TransportProtocol);
parseMessageSecurityMode(subtree, tvb, pOffset);
parseString(subtree, tvb, pOffset, hf_opcua_SecurityPolicyUri);
parseByteString(subtree, tvb, pOffset, hf_opcua_ClientCertificate);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseServiceCounterDataType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ServiceCounterDataType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ServiceCounterDataType);
parseUInt32(subtree, tvb, pOffset, hf_opcua_TotalCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_ErrorCount);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseStatusResult(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: StatusResult", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_StatusResult);
parseStatusCode(subtree, tvb, pOffset, hf_opcua_StatusCode);
parseDiagnosticInfo(subtree, tvb, pOffset, "DiagnosticInfo");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSubscriptionDiagnosticsDataType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: SubscriptionDiagnosticsDataType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SubscriptionDiagnosticsDataType);
parseNodeId(subtree, tvb, pOffset, "SessionId");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseByte(subtree, tvb, pOffset, hf_opcua_Priority);
parseDouble(subtree, tvb, pOffset, hf_opcua_PublishingInterval);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxKeepAliveCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxLifetimeCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxNotificationsPerPublish);
parseBoolean(subtree, tvb, pOffset, hf_opcua_PublishingEnabled);
parseUInt32(subtree, tvb, pOffset, hf_opcua_ModifyCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_EnableCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_DisableCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RepublishRequestCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RepublishMessageRequestCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RepublishMessageCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_TransferRequestCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_TransferredToAltClientCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_TransferredToSameClientCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_PublishRequestCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_DataChangeNotificationsCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_EventNotificationsCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_NotificationsCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_LatePublishRequestCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_CurrentKeepAliveCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_CurrentLifetimeCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_UnacknowledgedMessageCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_DiscardedMessageCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MonitoredItemCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_DisabledMonitoredItemCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MonitoringQueueOverflowCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_NextSequenceNumber);
parseUInt32(subtree, tvb, pOffset, hf_opcua_EventQueueOverFlowCount);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseModelChangeStructureDataType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ModelChangeStructureDataType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ModelChangeStructureDataType);
parseNodeId(subtree, tvb, pOffset, "Affected");
parseNodeId(subtree, tvb, pOffset, "AffectedType");
parseByte(subtree, tvb, pOffset, hf_opcua_Verb);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSemanticChangeStructureDataType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: SemanticChangeStructureDataType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SemanticChangeStructureDataType);
parseNodeId(subtree, tvb, pOffset, "Affected");
parseNodeId(subtree, tvb, pOffset, "AffectedType");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRange(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: Range", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_Range);
parseDouble(subtree, tvb, pOffset, hf_opcua_Low);
parseDouble(subtree, tvb, pOffset, hf_opcua_High);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseEUInformation(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: EUInformation", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_EUInformation);
parseString(subtree, tvb, pOffset, hf_opcua_NamespaceUri);
parseInt32(subtree, tvb, pOffset, hf_opcua_UnitId);
parseLocalizedText(subtree, tvb, pOffset, "DisplayName");
parseLocalizedText(subtree, tvb, pOffset, "Description");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseComplexNumberType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ComplexNumberType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ComplexNumberType);
parseFloat(subtree, tvb, pOffset, hf_opcua_Real);
parseFloat(subtree, tvb, pOffset, hf_opcua_Imaginary);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDoubleComplexNumberType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: DoubleComplexNumberType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DoubleComplexNumberType);
parseDouble(subtree, tvb, pOffset, hf_opcua_Real);
parseDouble(subtree, tvb, pOffset, hf_opcua_Imaginary);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAxisInformation(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: AxisInformation", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AxisInformation);
parseEUInformation(subtree, tvb, pOffset, "EngineeringUnits");
parseRange(subtree, tvb, pOffset, "EURange");
parseLocalizedText(subtree, tvb, pOffset, "Title");
parseAxisScaleEnumeration(subtree, tvb, pOffset);
parseArraySimple(subtree, tvb, pOffset, "AxisSteps", "Double", hf_opcua_AxisSteps, parseDouble, ett_opcua_array_Double);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseXVType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: XVType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_XVType);
parseDouble(subtree, tvb, pOffset, hf_opcua_X);
parseFloat(subtree, tvb, pOffset, hf_opcua_Value);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseProgramDiagnosticDataType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ProgramDiagnosticDataType", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ProgramDiagnosticDataType);
parseNodeId(subtree, tvb, pOffset, "CreateSessionId");
parseString(subtree, tvb, pOffset, hf_opcua_CreateClientName);
parseDateTime(subtree, tvb, pOffset, hf_opcua_InvocationCreationTime);
parseDateTime(subtree, tvb, pOffset, hf_opcua_LastTransitionTime);
parseString(subtree, tvb, pOffset, hf_opcua_LastMethodCall);
parseNodeId(subtree, tvb, pOffset, "LastMethodSessionId");
parseArrayComplex(subtree, tvb, pOffset, "LastMethodInputArguments", "Argument", parseArgument, ett_opcua_array_Argument);
parseArrayComplex(subtree, tvb, pOffset, "LastMethodOutputArguments", "Argument", parseArgument, ett_opcua_array_Argument);
parseDateTime(subtree, tvb, pOffset, hf_opcua_LastMethodCallTime);
parseStatusResult(subtree, tvb, pOffset, "LastMethodReturnStatus");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAnnotation(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: Annotation", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_Annotation);
parseString(subtree, tvb, pOffset, hf_opcua_Message);
parseString(subtree, tvb, pOffset, hf_opcua_UserName);
parseDateTime(subtree, tvb, pOffset, hf_opcua_AnnotationTime);
proto_item_set_end(ti, tvb, *pOffset);
}
void registerComplexTypes(void)
{
proto_register_subtree_array(ett, array_length(ett));
}
