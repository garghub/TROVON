void parseServiceFault(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_ServiceFault, &ti, "ServiceFault");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseFindServersRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_FindServersRequest, &ti, "FindServersRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_EndpointUrl);
parseArraySimple(subtree, tvb, pinfo, pOffset, "LocaleIds", "String", hf_opcua_LocaleIds, parseString, ett_opcua_array_String);
parseArraySimple(subtree, tvb, pinfo, pOffset, "ServerUris", "String", hf_opcua_ServerUris, parseString, ett_opcua_array_String);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseFindServersResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_FindServersResponse, &ti, "FindServersResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Servers", "ApplicationDescription", parseApplicationDescription, ett_opcua_array_ApplicationDescription);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseFindServersOnNetworkRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_FindServersOnNetworkRequest, &ti, "FindServersOnNetworkRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_StartingRecordId);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxRecordsToReturn);
parseArraySimple(subtree, tvb, pinfo, pOffset, "ServerCapabilityFilter", "String", hf_opcua_ServerCapabilityFilter, parseString, ett_opcua_array_String);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseFindServersOnNetworkResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_FindServersOnNetworkResponse, &ti, "FindServersOnNetworkResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseDateTime(subtree, tvb, pinfo, pOffset, hf_opcua_LastCounterResetTime);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Servers", "ServerOnNetwork", parseServerOnNetwork, ett_opcua_array_ServerOnNetwork);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseGetEndpointsRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_GetEndpointsRequest, &ti, "GetEndpointsRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_EndpointUrl);
parseArraySimple(subtree, tvb, pinfo, pOffset, "LocaleIds", "String", hf_opcua_LocaleIds, parseString, ett_opcua_array_String);
parseArraySimple(subtree, tvb, pinfo, pOffset, "ProfileUris", "String", hf_opcua_ProfileUris, parseString, ett_opcua_array_String);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseGetEndpointsResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_GetEndpointsResponse, &ti, "GetEndpointsResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Endpoints", "EndpointDescription", parseEndpointDescription, ett_opcua_array_EndpointDescription);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRegisterServerRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_RegisterServerRequest, &ti, "RegisterServerRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseRegisteredServer(subtree, tvb, pinfo, pOffset, "Server");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRegisterServerResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_RegisterServerResponse, &ti, "RegisterServerResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRegisterServer2Request(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_RegisterServer2Request, &ti, "RegisterServer2Request");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseRegisteredServer(subtree, tvb, pinfo, pOffset, "Server");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiscoveryConfiguration", "ExtensionObject", parseExtensionObject, ett_opcua_array_ExtensionObject);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRegisterServer2Response(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_RegisterServer2Response, &ti, "RegisterServer2Response");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pinfo, pOffset, "ConfigurationResults", "StatusCode", hf_opcua_ConfigurationResults, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseOpenSecureChannelRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_OpenSecureChannelRequest, &ti, "OpenSecureChannelRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ClientProtocolVersion);
parseSecurityTokenRequestType(subtree, tvb, pinfo, pOffset);
parseMessageSecurityMode(subtree, tvb, pinfo, pOffset);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ClientNonce);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RequestedLifetime);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseOpenSecureChannelResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_OpenSecureChannelResponse, &ti, "OpenSecureChannelResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_ServerProtocolVersion);
parseChannelSecurityToken(subtree, tvb, pinfo, pOffset, "SecurityToken");
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ServerNonce);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCloseSecureChannelRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_CloseSecureChannelRequest, &ti, "CloseSecureChannelRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCloseSecureChannelResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_CloseSecureChannelResponse, &ti, "CloseSecureChannelResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCreateSessionRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_CreateSessionRequest, &ti, "CreateSessionRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseApplicationDescription(subtree, tvb, pinfo, pOffset, "ClientDescription");
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_ServerUri);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_EndpointUrl);
parseString(subtree, tvb, pinfo, pOffset, hf_opcua_SessionName);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ClientNonce);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ClientCertificate);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_RequestedSessionTimeout);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxResponseMessageSize);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCreateSessionResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_CreateSessionResponse, &ti, "CreateSessionResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseNodeId(subtree, tvb, pinfo, pOffset, "SessionId");
parseNodeId(subtree, tvb, pinfo, pOffset, "AuthenticationToken");
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_RevisedSessionTimeout);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ServerNonce);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ServerCertificate);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "ServerEndpoints", "EndpointDescription", parseEndpointDescription, ett_opcua_array_EndpointDescription);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "ServerSoftwareCertificates", "SignedSoftwareCertificate", parseSignedSoftwareCertificate, ett_opcua_array_SignedSoftwareCertificate);
parseSignatureData(subtree, tvb, pinfo, pOffset, "ServerSignature");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxRequestMessageSize);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseActivateSessionRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_ActivateSessionRequest, &ti, "ActivateSessionRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseSignatureData(subtree, tvb, pinfo, pOffset, "ClientSignature");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "ClientSoftwareCertificates", "SignedSoftwareCertificate", parseSignedSoftwareCertificate, ett_opcua_array_SignedSoftwareCertificate);
parseArraySimple(subtree, tvb, pinfo, pOffset, "LocaleIds", "String", hf_opcua_LocaleIds, parseString, ett_opcua_array_String);
parseExtensionObject(subtree, tvb, pinfo, pOffset, "UserIdentityToken");
parseSignatureData(subtree, tvb, pinfo, pOffset, "UserTokenSignature");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseActivateSessionResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_ActivateSessionResponse, &ti, "ActivateSessionResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ServerNonce);
parseArraySimple(subtree, tvb, pinfo, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCloseSessionRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_CloseSessionRequest, &ti, "CloseSessionRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_DeleteSubscriptions);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCloseSessionResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_CloseSessionResponse, &ti, "CloseSessionResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCancelRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_CancelRequest, &ti, "CancelRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RequestHandle);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCancelResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_CancelResponse, &ti, "CancelResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_CancelCount);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAddNodesRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_AddNodesRequest, &ti, "AddNodesRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "NodesToAdd", "AddNodesItem", parseAddNodesItem, ett_opcua_array_AddNodesItem);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAddNodesResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_AddNodesResponse, &ti, "AddNodesResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Results", "AddNodesResult", parseAddNodesResult, ett_opcua_array_AddNodesResult);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAddReferencesRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_AddReferencesRequest, &ti, "AddReferencesRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "ReferencesToAdd", "AddReferencesItem", parseAddReferencesItem, ett_opcua_array_AddReferencesItem);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAddReferencesResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_AddReferencesResponse, &ti, "AddReferencesResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pinfo, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteNodesRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_DeleteNodesRequest, &ti, "DeleteNodesRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "NodesToDelete", "DeleteNodesItem", parseDeleteNodesItem, ett_opcua_array_DeleteNodesItem);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteNodesResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_DeleteNodesResponse, &ti, "DeleteNodesResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pinfo, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteReferencesRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_DeleteReferencesRequest, &ti, "DeleteReferencesRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "ReferencesToDelete", "DeleteReferencesItem", parseDeleteReferencesItem, ett_opcua_array_DeleteReferencesItem);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteReferencesResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_DeleteReferencesResponse, &ti, "DeleteReferencesResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pinfo, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowseRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_BrowseRequest, &ti, "BrowseRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseViewDescription(subtree, tvb, pinfo, pOffset, "View");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RequestedMaxReferencesPerNode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "NodesToBrowse", "BrowseDescription", parseBrowseDescription, ett_opcua_array_BrowseDescription);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowseResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_BrowseResponse, &ti, "BrowseResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Results", "BrowseResult", parseBrowseResult, ett_opcua_array_BrowseResult);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowseNextRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_BrowseNextRequest, &ti, "BrowseNextRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_ReleaseContinuationPoints);
parseArraySimple(subtree, tvb, pinfo, pOffset, "ContinuationPoints", "ByteString", hf_opcua_ContinuationPoints, parseByteString, ett_opcua_array_ByteString);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowseNextResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_BrowseNextResponse, &ti, "BrowseNextResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Results", "BrowseResult", parseBrowseResult, ett_opcua_array_BrowseResult);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTranslateBrowsePathsToNodeIdsRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_TranslateBrowsePathsToNodeIdsRequest, &ti, "TranslateBrowsePathsToNodeIdsRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "BrowsePaths", "BrowsePath", parseBrowsePath, ett_opcua_array_BrowsePath);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTranslateBrowsePathsToNodeIdsResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_TranslateBrowsePathsToNodeIdsResponse, &ti, "TranslateBrowsePathsToNodeIdsResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Results", "BrowsePathResult", parseBrowsePathResult, ett_opcua_array_BrowsePathResult);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRegisterNodesRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_RegisterNodesRequest, &ti, "RegisterNodesRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "NodesToRegister", "NodeId", parseNodeId, ett_opcua_array_NodeId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRegisterNodesResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_RegisterNodesResponse, &ti, "RegisterNodesResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "RegisteredNodeIds", "NodeId", parseNodeId, ett_opcua_array_NodeId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUnregisterNodesRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_UnregisterNodesRequest, &ti, "UnregisterNodesRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "NodesToUnregister", "NodeId", parseNodeId, ett_opcua_array_NodeId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUnregisterNodesResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_UnregisterNodesResponse, &ti, "UnregisterNodesResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseQueryFirstRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_QueryFirstRequest, &ti, "QueryFirstRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseViewDescription(subtree, tvb, pinfo, pOffset, "View");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "NodeTypes", "NodeTypeDescription", parseNodeTypeDescription, ett_opcua_array_NodeTypeDescription);
parseContentFilter(subtree, tvb, pinfo, pOffset, "Filter");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxDataSetsToReturn);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxReferencesToReturn);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseQueryFirstResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_QueryFirstResponse, &ti, "QueryFirstResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "QueryDataSets", "QueryDataSet", parseQueryDataSet, ett_opcua_array_QueryDataSet);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ContinuationPoint);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "ParsingResults", "ParsingResult", parseParsingResult, ett_opcua_array_ParsingResult);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
parseContentFilterResult(subtree, tvb, pinfo, pOffset, "FilterResult");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseQueryNextRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_QueryNextRequest, &ti, "QueryNextRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_ReleaseContinuationPoint);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_ContinuationPoint);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseQueryNextResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_QueryNextResponse, &ti, "QueryNextResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "QueryDataSets", "QueryDataSet", parseQueryDataSet, ett_opcua_array_QueryDataSet);
parseByteString(subtree, tvb, pinfo, pOffset, hf_opcua_RevisedContinuationPoint);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReadRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_ReadRequest, &ti, "ReadRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_MaxAge);
parseTimestampsToReturn(subtree, tvb, pinfo, pOffset);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "NodesToRead", "ReadValueId", parseReadValueId, ett_opcua_array_ReadValueId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReadResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_ReadResponse, &ti, "ReadResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Results", "DataValue", parseDataValue, ett_opcua_array_DataValue);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryReadRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_HistoryReadRequest, &ti, "HistoryReadRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseExtensionObject(subtree, tvb, pinfo, pOffset, "HistoryReadDetails");
parseTimestampsToReturn(subtree, tvb, pinfo, pOffset);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_ReleaseContinuationPoints);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "NodesToRead", "HistoryReadValueId", parseHistoryReadValueId, ett_opcua_array_HistoryReadValueId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryReadResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_HistoryReadResponse, &ti, "HistoryReadResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Results", "HistoryReadResult", parseHistoryReadResult, ett_opcua_array_HistoryReadResult);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseWriteRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_WriteRequest, &ti, "WriteRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "NodesToWrite", "WriteValue", parseWriteValue, ett_opcua_array_WriteValue);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseWriteResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_WriteResponse, &ti, "WriteResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pinfo, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryUpdateRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_HistoryUpdateRequest, &ti, "HistoryUpdateRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "HistoryUpdateDetails", "ExtensionObject", parseExtensionObject, ett_opcua_array_ExtensionObject);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryUpdateResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_HistoryUpdateResponse, &ti, "HistoryUpdateResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Results", "HistoryUpdateResult", parseHistoryUpdateResult, ett_opcua_array_HistoryUpdateResult);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCallRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_CallRequest, &ti, "CallRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "MethodsToCall", "CallMethodRequest", parseCallMethodRequest, ett_opcua_array_CallMethodRequest);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCallResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_CallResponse, &ti, "CallResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Results", "CallMethodResult", parseCallMethodResult, ett_opcua_array_CallMethodResult);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCreateMonitoredItemsRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_CreateMonitoredItemsRequest, &ti, "CreateMonitoredItemsRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SubscriptionId);
parseTimestampsToReturn(subtree, tvb, pinfo, pOffset);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "ItemsToCreate", "MonitoredItemCreateRequest", parseMonitoredItemCreateRequest, ett_opcua_array_MonitoredItemCreateRequest);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCreateMonitoredItemsResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_CreateMonitoredItemsResponse, &ti, "CreateMonitoredItemsResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Results", "MonitoredItemCreateResult", parseMonitoredItemCreateResult, ett_opcua_array_MonitoredItemCreateResult);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseModifyMonitoredItemsRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_ModifyMonitoredItemsRequest, &ti, "ModifyMonitoredItemsRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SubscriptionId);
parseTimestampsToReturn(subtree, tvb, pinfo, pOffset);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "ItemsToModify", "MonitoredItemModifyRequest", parseMonitoredItemModifyRequest, ett_opcua_array_MonitoredItemModifyRequest);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseModifyMonitoredItemsResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_ModifyMonitoredItemsResponse, &ti, "ModifyMonitoredItemsResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Results", "MonitoredItemModifyResult", parseMonitoredItemModifyResult, ett_opcua_array_MonitoredItemModifyResult);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSetMonitoringModeRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_SetMonitoringModeRequest, &ti, "SetMonitoringModeRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SubscriptionId);
parseMonitoringMode(subtree, tvb, pinfo, pOffset);
parseArraySimple(subtree, tvb, pinfo, pOffset, "MonitoredItemIds", "UInt32", hf_opcua_MonitoredItemIds, parseUInt32, ett_opcua_array_UInt32);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSetMonitoringModeResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_SetMonitoringModeResponse, &ti, "SetMonitoringModeResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pinfo, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSetTriggeringRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_SetTriggeringRequest, &ti, "SetTriggeringRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SubscriptionId);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_TriggeringItemId);
parseArraySimple(subtree, tvb, pinfo, pOffset, "LinksToAdd", "UInt32", hf_opcua_LinksToAdd, parseUInt32, ett_opcua_array_UInt32);
parseArraySimple(subtree, tvb, pinfo, pOffset, "LinksToRemove", "UInt32", hf_opcua_LinksToRemove, parseUInt32, ett_opcua_array_UInt32);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSetTriggeringResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_SetTriggeringResponse, &ti, "SetTriggeringResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pinfo, pOffset, "AddResults", "StatusCode", hf_opcua_AddResults, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "AddDiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
parseArraySimple(subtree, tvb, pinfo, pOffset, "RemoveResults", "StatusCode", hf_opcua_RemoveResults, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "RemoveDiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteMonitoredItemsRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_DeleteMonitoredItemsRequest, &ti, "DeleteMonitoredItemsRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SubscriptionId);
parseArraySimple(subtree, tvb, pinfo, pOffset, "MonitoredItemIds", "UInt32", hf_opcua_MonitoredItemIds, parseUInt32, ett_opcua_array_UInt32);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteMonitoredItemsResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_DeleteMonitoredItemsResponse, &ti, "DeleteMonitoredItemsResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pinfo, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCreateSubscriptionRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_CreateSubscriptionRequest, &ti, "CreateSubscriptionRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_RequestedPublishingInterval);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RequestedLifetimeCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RequestedMaxKeepAliveCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxNotificationsPerPublish);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_PublishingEnabled);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_Priority);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCreateSubscriptionResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_CreateSubscriptionResponse, &ti, "CreateSubscriptionResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SubscriptionId);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_RevisedPublishingInterval);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RevisedLifetimeCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RevisedMaxKeepAliveCount);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseModifySubscriptionRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_ModifySubscriptionRequest, &ti, "ModifySubscriptionRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SubscriptionId);
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_RequestedPublishingInterval);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RequestedLifetimeCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RequestedMaxKeepAliveCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_MaxNotificationsPerPublish);
parseByte(subtree, tvb, pinfo, pOffset, hf_opcua_Priority);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseModifySubscriptionResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_ModifySubscriptionResponse, &ti, "ModifySubscriptionResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseDouble(subtree, tvb, pinfo, pOffset, hf_opcua_RevisedPublishingInterval);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RevisedLifetimeCount);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RevisedMaxKeepAliveCount);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSetPublishingModeRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_SetPublishingModeRequest, &ti, "SetPublishingModeRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_PublishingEnabled);
parseArraySimple(subtree, tvb, pinfo, pOffset, "SubscriptionIds", "UInt32", hf_opcua_SubscriptionIds, parseUInt32, ett_opcua_array_UInt32);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSetPublishingModeResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_SetPublishingModeResponse, &ti, "SetPublishingModeResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pinfo, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parsePublishRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_PublishRequest, &ti, "PublishRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "SubscriptionAcknowledgements", "SubscriptionAcknowledgement", parseSubscriptionAcknowledgement, ett_opcua_array_SubscriptionAcknowledgement);
proto_item_set_end(ti, tvb, *pOffset);
}
void parsePublishResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_PublishResponse, &ti, "PublishResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SubscriptionId);
parseArraySimple(subtree, tvb, pinfo, pOffset, "AvailableSequenceNumbers", "UInt32", hf_opcua_AvailableSequenceNumbers, parseUInt32, ett_opcua_array_UInt32);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_MoreNotifications);
parseNotificationMessage(subtree, tvb, pinfo, pOffset, "NotificationMessage");
parseArraySimple(subtree, tvb, pinfo, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRepublishRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_RepublishRequest, &ti, "RepublishRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_SubscriptionId);
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_RetransmitSequenceNumber);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRepublishResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_RepublishResponse, &ti, "RepublishResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseNotificationMessage(subtree, tvb, pinfo, pOffset, "NotificationMessage");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTransferSubscriptionsRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_TransferSubscriptionsRequest, &ti, "TransferSubscriptionsRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseArraySimple(subtree, tvb, pinfo, pOffset, "SubscriptionIds", "UInt32", hf_opcua_SubscriptionIds, parseUInt32, ett_opcua_array_UInt32);
parseBoolean(subtree, tvb, pinfo, pOffset, hf_opcua_SendInitialValues);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTransferSubscriptionsResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_TransferSubscriptionsResponse, &ti, "TransferSubscriptionsResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pinfo, pOffset, "Results", "TransferResult", parseTransferResult, ett_opcua_array_TransferResult);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteSubscriptionsRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_DeleteSubscriptionsRequest, &ti, "DeleteSubscriptionsRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseArraySimple(subtree, tvb, pinfo, pOffset, "SubscriptionIds", "UInt32", hf_opcua_SubscriptionIds, parseUInt32, ett_opcua_array_UInt32);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteSubscriptionsResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_DeleteSubscriptionsResponse, &ti, "DeleteSubscriptionsResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pinfo, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pinfo, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTestStackRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_TestStackRequest, &ti, "TestStackRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_TestId);
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_Iteration);
parseVariant(subtree, tvb, pinfo, pOffset, "Input");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTestStackResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_TestStackResponse, &ti, "TestStackResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseVariant(subtree, tvb, pinfo, pOffset, "Output");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTestStackExRequest(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_TestStackExRequest, &ti, "TestStackExRequest");
parseRequestHeader(subtree, tvb, pinfo, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pinfo, pOffset, hf_opcua_TestId);
parseInt32(subtree, tvb, pinfo, pOffset, hf_opcua_Iteration);
parseCompositeTestType(subtree, tvb, pinfo, pOffset, "Input");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTestStackExResponse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset)
{
proto_item *ti;
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_TestStackExResponse, &ti, "TestStackExResponse");
parseResponseHeader(subtree, tvb, pinfo, pOffset, "ResponseHeader");
parseCompositeTestType(subtree, tvb, pinfo, pOffset, "Output");
proto_item_set_end(ti, tvb, *pOffset);
}
void registerServiceTypes(void)
{
proto_register_subtree_array(ett, array_length(ett));
}
