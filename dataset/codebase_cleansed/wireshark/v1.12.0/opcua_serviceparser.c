void parseServiceFault(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "ServiceFault");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ServiceFault);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseFindServersRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "FindServersRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_FindServersRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseString(subtree, tvb, pOffset, hf_opcua_EndpointUrl);
parseArraySimple(subtree, tvb, pOffset, "LocaleIds", "String", hf_opcua_LocaleIds, parseString, ett_opcua_array_String);
parseArraySimple(subtree, tvb, pOffset, "ServerUris", "String", hf_opcua_ServerUris, parseString, ett_opcua_array_String);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseFindServersResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "FindServersResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_FindServersResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Servers", "ApplicationDescription", parseApplicationDescription, ett_opcua_array_ApplicationDescription);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseGetEndpointsRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "GetEndpointsRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_GetEndpointsRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseString(subtree, tvb, pOffset, hf_opcua_EndpointUrl);
parseArraySimple(subtree, tvb, pOffset, "LocaleIds", "String", hf_opcua_LocaleIds, parseString, ett_opcua_array_String);
parseArraySimple(subtree, tvb, pOffset, "ProfileUris", "String", hf_opcua_ProfileUris, parseString, ett_opcua_array_String);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseGetEndpointsResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "GetEndpointsResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_GetEndpointsResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Endpoints", "EndpointDescription", parseEndpointDescription, ett_opcua_array_EndpointDescription);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRegisterServerRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "RegisterServerRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RegisterServerRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseRegisteredServer(subtree, tvb, pOffset, "Server");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRegisterServerResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "RegisterServerResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RegisterServerResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseOpenSecureChannelRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "OpenSecureChannelRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_OpenSecureChannelRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_ClientProtocolVersion);
parseSecurityTokenRequestType(subtree, tvb, pOffset);
parseMessageSecurityMode(subtree, tvb, pOffset);
parseByteString(subtree, tvb, pOffset, hf_opcua_ClientNonce);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestedLifetime);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseOpenSecureChannelResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "OpenSecureChannelResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_OpenSecureChannelResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_ServerProtocolVersion);
parseChannelSecurityToken(subtree, tvb, pOffset, "SecurityToken");
parseByteString(subtree, tvb, pOffset, hf_opcua_ServerNonce);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCloseSecureChannelRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "CloseSecureChannelRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CloseSecureChannelRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCloseSecureChannelResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "CloseSecureChannelResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CloseSecureChannelResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCreateSessionRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "CreateSessionRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CreateSessionRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseApplicationDescription(subtree, tvb, pOffset, "ClientDescription");
parseString(subtree, tvb, pOffset, hf_opcua_ServerUri);
parseString(subtree, tvb, pOffset, hf_opcua_EndpointUrl);
parseString(subtree, tvb, pOffset, hf_opcua_SessionName);
parseByteString(subtree, tvb, pOffset, hf_opcua_ClientNonce);
parseByteString(subtree, tvb, pOffset, hf_opcua_ClientCertificate);
parseDouble(subtree, tvb, pOffset, hf_opcua_RequestedSessionTimeout);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxResponseMessageSize);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCreateSessionResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "CreateSessionResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CreateSessionResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseNodeId(subtree, tvb, pOffset, "SessionId");
parseNodeId(subtree, tvb, pOffset, "AuthenticationToken");
parseDouble(subtree, tvb, pOffset, hf_opcua_RevisedSessionTimeout);
parseByteString(subtree, tvb, pOffset, hf_opcua_ServerNonce);
parseByteString(subtree, tvb, pOffset, hf_opcua_ServerCertificate);
parseArrayComplex(subtree, tvb, pOffset, "ServerEndpoints", "EndpointDescription", parseEndpointDescription, ett_opcua_array_EndpointDescription);
parseArrayComplex(subtree, tvb, pOffset, "ServerSoftwareCertificates", "SignedSoftwareCertificate", parseSignedSoftwareCertificate, ett_opcua_array_SignedSoftwareCertificate);
parseSignatureData(subtree, tvb, pOffset, "ServerSignature");
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxRequestMessageSize);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseActivateSessionRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "ActivateSessionRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ActivateSessionRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseSignatureData(subtree, tvb, pOffset, "ClientSignature");
parseArrayComplex(subtree, tvb, pOffset, "ClientSoftwareCertificates", "SignedSoftwareCertificate", parseSignedSoftwareCertificate, ett_opcua_array_SignedSoftwareCertificate);
parseArraySimple(subtree, tvb, pOffset, "LocaleIds", "String", hf_opcua_LocaleIds, parseString, ett_opcua_array_String);
parseExtensionObject(subtree, tvb, pOffset, "UserIdentityToken");
parseSignatureData(subtree, tvb, pOffset, "UserTokenSignature");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseActivateSessionResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "ActivateSessionResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ActivateSessionResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseByteString(subtree, tvb, pOffset, hf_opcua_ServerNonce);
parseArraySimple(subtree, tvb, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCloseSessionRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "CloseSessionRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CloseSessionRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseBoolean(subtree, tvb, pOffset, hf_opcua_DeleteSubscriptions);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCloseSessionResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "CloseSessionResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CloseSessionResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCancelRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "CancelRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CancelRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestHandle);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCancelResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "CancelResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CancelResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_CancelCount);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAddNodesRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "AddNodesRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AddNodesRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "NodesToAdd", "AddNodesItem", parseAddNodesItem, ett_opcua_array_AddNodesItem);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAddNodesResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "AddNodesResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AddNodesResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", "AddNodesResult", parseAddNodesResult, ett_opcua_array_AddNodesResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAddReferencesRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "AddReferencesRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AddReferencesRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "ReferencesToAdd", "AddReferencesItem", parseAddReferencesItem, ett_opcua_array_AddReferencesItem);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseAddReferencesResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "AddReferencesResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AddReferencesResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteNodesRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "DeleteNodesRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteNodesRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "NodesToDelete", "DeleteNodesItem", parseDeleteNodesItem, ett_opcua_array_DeleteNodesItem);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteNodesResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "DeleteNodesResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteNodesResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteReferencesRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "DeleteReferencesRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteReferencesRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "ReferencesToDelete", "DeleteReferencesItem", parseDeleteReferencesItem, ett_opcua_array_DeleteReferencesItem);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteReferencesResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "DeleteReferencesResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteReferencesResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowseRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "BrowseRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_BrowseRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseViewDescription(subtree, tvb, pOffset, "View");
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestedMaxReferencesPerNode);
parseArrayComplex(subtree, tvb, pOffset, "NodesToBrowse", "BrowseDescription", parseBrowseDescription, ett_opcua_array_BrowseDescription);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowseResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "BrowseResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_BrowseResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", "BrowseResult", parseBrowseResult, ett_opcua_array_BrowseResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowseNextRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "BrowseNextRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_BrowseNextRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseBoolean(subtree, tvb, pOffset, hf_opcua_ReleaseContinuationPoints);
parseArraySimple(subtree, tvb, pOffset, "ContinuationPoints", "ByteString", hf_opcua_ContinuationPoints, parseByteString, ett_opcua_array_ByteString);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseBrowseNextResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "BrowseNextResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_BrowseNextResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", "BrowseResult", parseBrowseResult, ett_opcua_array_BrowseResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTranslateBrowsePathsToNodeIdsRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "TranslateBrowsePathsToNodeIdsRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TranslateBrowsePathsToNodeIdsRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "BrowsePaths", "BrowsePath", parseBrowsePath, ett_opcua_array_BrowsePath);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTranslateBrowsePathsToNodeIdsResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "TranslateBrowsePathsToNodeIdsResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TranslateBrowsePathsToNodeIdsResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", "BrowsePathResult", parseBrowsePathResult, ett_opcua_array_BrowsePathResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRegisterNodesRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "RegisterNodesRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RegisterNodesRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "NodesToRegister", "NodeId", parseNodeId, ett_opcua_array_NodeId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRegisterNodesResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "RegisterNodesResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RegisterNodesResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "RegisteredNodeIds", "NodeId", parseNodeId, ett_opcua_array_NodeId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUnregisterNodesRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "UnregisterNodesRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_UnregisterNodesRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "NodesToUnregister", "NodeId", parseNodeId, ett_opcua_array_NodeId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseUnregisterNodesResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "UnregisterNodesResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_UnregisterNodesResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseQueryFirstRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "QueryFirstRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_QueryFirstRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseViewDescription(subtree, tvb, pOffset, "View");
parseArrayComplex(subtree, tvb, pOffset, "NodeTypes", "NodeTypeDescription", parseNodeTypeDescription, ett_opcua_array_NodeTypeDescription);
parseContentFilter(subtree, tvb, pOffset, "Filter");
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxDataSetsToReturn);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxReferencesToReturn);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseQueryFirstResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "QueryFirstResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_QueryFirstResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "QueryDataSets", "QueryDataSet", parseQueryDataSet, ett_opcua_array_QueryDataSet);
parseByteString(subtree, tvb, pOffset, hf_opcua_ContinuationPoint);
parseArrayComplex(subtree, tvb, pOffset, "ParsingResults", "ParsingResult", parseParsingResult, ett_opcua_array_ParsingResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
parseContentFilterResult(subtree, tvb, pOffset, "FilterResult");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseQueryNextRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "QueryNextRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_QueryNextRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseBoolean(subtree, tvb, pOffset, hf_opcua_ReleaseContinuationPoint);
parseByteString(subtree, tvb, pOffset, hf_opcua_ContinuationPoint);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseQueryNextResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "QueryNextResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_QueryNextResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "QueryDataSets", "QueryDataSet", parseQueryDataSet, ett_opcua_array_QueryDataSet);
parseByteString(subtree, tvb, pOffset, hf_opcua_RevisedContinuationPoint);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReadRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "ReadRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ReadRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseDouble(subtree, tvb, pOffset, hf_opcua_MaxAge);
parseTimestampsToReturn(subtree, tvb, pOffset);
parseArrayComplex(subtree, tvb, pOffset, "NodesToRead", "ReadValueId", parseReadValueId, ett_opcua_array_ReadValueId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseReadResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "ReadResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ReadResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", "DataValue", parseDataValue, ett_opcua_array_DataValue);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryReadRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "HistoryReadRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryReadRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseExtensionObject(subtree, tvb, pOffset, "HistoryReadDetails");
parseTimestampsToReturn(subtree, tvb, pOffset);
parseBoolean(subtree, tvb, pOffset, hf_opcua_ReleaseContinuationPoints);
parseArrayComplex(subtree, tvb, pOffset, "NodesToRead", "HistoryReadValueId", parseHistoryReadValueId, ett_opcua_array_HistoryReadValueId);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryReadResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "HistoryReadResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryReadResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", "HistoryReadResult", parseHistoryReadResult, ett_opcua_array_HistoryReadResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseWriteRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "WriteRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_WriteRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "NodesToWrite", "WriteValue", parseWriteValue, ett_opcua_array_WriteValue);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseWriteResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "WriteResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_WriteResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryUpdateRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "HistoryUpdateRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryUpdateRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "HistoryUpdateDetails", "ExtensionObject", parseExtensionObject, ett_opcua_array_ExtensionObject);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseHistoryUpdateResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "HistoryUpdateResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryUpdateResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", "HistoryUpdateResult", parseHistoryUpdateResult, ett_opcua_array_HistoryUpdateResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCallRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "CallRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CallRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "MethodsToCall", "CallMethodRequest", parseCallMethodRequest, ett_opcua_array_CallMethodRequest);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCallResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "CallResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CallResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", "CallMethodResult", parseCallMethodResult, ett_opcua_array_CallMethodResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCreateMonitoredItemsRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "CreateMonitoredItemsRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CreateMonitoredItemsRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseTimestampsToReturn(subtree, tvb, pOffset);
parseArrayComplex(subtree, tvb, pOffset, "ItemsToCreate", "MonitoredItemCreateRequest", parseMonitoredItemCreateRequest, ett_opcua_array_MonitoredItemCreateRequest);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCreateMonitoredItemsResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "CreateMonitoredItemsResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CreateMonitoredItemsResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", "MonitoredItemCreateResult", parseMonitoredItemCreateResult, ett_opcua_array_MonitoredItemCreateResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseModifyMonitoredItemsRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "ModifyMonitoredItemsRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ModifyMonitoredItemsRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseTimestampsToReturn(subtree, tvb, pOffset);
parseArrayComplex(subtree, tvb, pOffset, "ItemsToModify", "MonitoredItemModifyRequest", parseMonitoredItemModifyRequest, ett_opcua_array_MonitoredItemModifyRequest);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseModifyMonitoredItemsResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "ModifyMonitoredItemsResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ModifyMonitoredItemsResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", "MonitoredItemModifyResult", parseMonitoredItemModifyResult, ett_opcua_array_MonitoredItemModifyResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSetMonitoringModeRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "SetMonitoringModeRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SetMonitoringModeRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseMonitoringMode(subtree, tvb, pOffset);
parseArraySimple(subtree, tvb, pOffset, "MonitoredItemIds", "UInt32", hf_opcua_MonitoredItemIds, parseUInt32, ett_opcua_array_UInt32);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSetMonitoringModeResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "SetMonitoringModeResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SetMonitoringModeResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSetTriggeringRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "SetTriggeringRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SetTriggeringRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseUInt32(subtree, tvb, pOffset, hf_opcua_TriggeringItemId);
parseArraySimple(subtree, tvb, pOffset, "LinksToAdd", "UInt32", hf_opcua_LinksToAdd, parseUInt32, ett_opcua_array_UInt32);
parseArraySimple(subtree, tvb, pOffset, "LinksToRemove", "UInt32", hf_opcua_LinksToRemove, parseUInt32, ett_opcua_array_UInt32);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSetTriggeringResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "SetTriggeringResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SetTriggeringResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, "AddResults", "StatusCode", hf_opcua_AddResults, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "AddDiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
parseArraySimple(subtree, tvb, pOffset, "RemoveResults", "StatusCode", hf_opcua_RemoveResults, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "RemoveDiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteMonitoredItemsRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "DeleteMonitoredItemsRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteMonitoredItemsRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseArraySimple(subtree, tvb, pOffset, "MonitoredItemIds", "UInt32", hf_opcua_MonitoredItemIds, parseUInt32, ett_opcua_array_UInt32);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteMonitoredItemsResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "DeleteMonitoredItemsResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteMonitoredItemsResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCreateSubscriptionRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "CreateSubscriptionRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CreateSubscriptionRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseDouble(subtree, tvb, pOffset, hf_opcua_RequestedPublishingInterval);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestedLifetimeCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestedMaxKeepAliveCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxNotificationsPerPublish);
parseBoolean(subtree, tvb, pOffset, hf_opcua_PublishingEnabled);
parseByte(subtree, tvb, pOffset, hf_opcua_Priority);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseCreateSubscriptionResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "CreateSubscriptionResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CreateSubscriptionResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseDouble(subtree, tvb, pOffset, hf_opcua_RevisedPublishingInterval);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RevisedLifetimeCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RevisedMaxKeepAliveCount);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseModifySubscriptionRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "ModifySubscriptionRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ModifySubscriptionRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseDouble(subtree, tvb, pOffset, hf_opcua_RequestedPublishingInterval);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestedLifetimeCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestedMaxKeepAliveCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxNotificationsPerPublish);
parseByte(subtree, tvb, pOffset, hf_opcua_Priority);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseModifySubscriptionResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "ModifySubscriptionResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ModifySubscriptionResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseDouble(subtree, tvb, pOffset, hf_opcua_RevisedPublishingInterval);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RevisedLifetimeCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RevisedMaxKeepAliveCount);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSetPublishingModeRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "SetPublishingModeRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SetPublishingModeRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseBoolean(subtree, tvb, pOffset, hf_opcua_PublishingEnabled);
parseArraySimple(subtree, tvb, pOffset, "SubscriptionIds", "UInt32", hf_opcua_SubscriptionIds, parseUInt32, ett_opcua_array_UInt32);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseSetPublishingModeResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "SetPublishingModeResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SetPublishingModeResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parsePublishRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "PublishRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_PublishRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "SubscriptionAcknowledgements", "SubscriptionAcknowledgement", parseSubscriptionAcknowledgement, ett_opcua_array_SubscriptionAcknowledgement);
proto_item_set_end(ti, tvb, *pOffset);
}
void parsePublishResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "PublishResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_PublishResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseArraySimple(subtree, tvb, pOffset, "AvailableSequenceNumbers", "UInt32", hf_opcua_AvailableSequenceNumbers, parseUInt32, ett_opcua_array_UInt32);
parseBoolean(subtree, tvb, pOffset, hf_opcua_MoreNotifications);
parseNotificationMessage(subtree, tvb, pOffset, "NotificationMessage");
parseArraySimple(subtree, tvb, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRepublishRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "RepublishRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RepublishRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RetransmitSequenceNumber);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseRepublishResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "RepublishResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RepublishResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseNotificationMessage(subtree, tvb, pOffset, "NotificationMessage");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTransferSubscriptionsRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "TransferSubscriptionsRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TransferSubscriptionsRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArraySimple(subtree, tvb, pOffset, "SubscriptionIds", "UInt32", hf_opcua_SubscriptionIds, parseUInt32, ett_opcua_array_UInt32);
parseBoolean(subtree, tvb, pOffset, hf_opcua_SendInitialValues);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTransferSubscriptionsResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "TransferSubscriptionsResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TransferSubscriptionsResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", "TransferResult", parseTransferResult, ett_opcua_array_TransferResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteSubscriptionsRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "DeleteSubscriptionsRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteSubscriptionsRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArraySimple(subtree, tvb, pOffset, "SubscriptionIds", "UInt32", hf_opcua_SubscriptionIds, parseUInt32, ett_opcua_array_UInt32);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDeleteSubscriptionsResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "DeleteSubscriptionsResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteSubscriptionsResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, "Results", "StatusCode", hf_opcua_Results, parseStatusCode, ett_opcua_array_StatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTestStackRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "TestStackRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TestStackRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_TestId);
parseInt32(subtree, tvb, pOffset, hf_opcua_Iteration);
parseVariant(subtree, tvb, pOffset, "Input");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTestStackResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "TestStackResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TestStackResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseVariant(subtree, tvb, pOffset, "Output");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTestStackExRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "TestStackExRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TestStackExRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_TestId);
parseInt32(subtree, tvb, pOffset, hf_opcua_Iteration);
parseCompositeTestType(subtree, tvb, pOffset, "Input");
proto_item_set_end(ti, tvb, *pOffset);
}
void parseTestStackExResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "TestStackExResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TestStackExResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseCompositeTestType(subtree, tvb, pOffset, "Output");
proto_item_set_end(ti, tvb, *pOffset);
}
void registerServiceTypes(void)
{
proto_register_subtree_array(ett, array_length(ett));
}
