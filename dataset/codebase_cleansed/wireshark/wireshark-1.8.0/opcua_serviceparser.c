void parseTestStackRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "TestStackRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TestStackRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_TestId);
parseInt32(subtree, tvb, pOffset, hf_opcua_Iteration);
parseVariant(subtree, tvb, pOffset, "Input");
}
void parseTestStackResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "TestStackResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TestStackResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseVariant(subtree, tvb, pOffset, "Output");
}
void parseTestStackExRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "TestStackExRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TestStackExRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_TestId);
parseInt32(subtree, tvb, pOffset, hf_opcua_Iteration);
parseCompositeTestType(subtree, tvb, pOffset, "Input");
}
void parseTestStackExResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "TestStackExResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TestStackExResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseCompositeTestType(subtree, tvb, pOffset, "Output");
}
void parseFindServersRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "FindServersRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_FindServersRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseString(subtree, tvb, pOffset, hf_opcua_EndpointUrl);
parseArraySimple(subtree, tvb, pOffset, hf_opcua_LocaleIds, parseString);
parseArraySimple(subtree, tvb, pOffset, hf_opcua_ServerUris, parseString);
}
void parseFindServersResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "FindServersResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_FindServersResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Servers", parseApplicationDescription);
}
void parseGetEndpointsRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "GetEndpointsRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_GetEndpointsRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseString(subtree, tvb, pOffset, hf_opcua_EndpointUrl);
parseArraySimple(subtree, tvb, pOffset, hf_opcua_LocaleIds, parseString);
parseArraySimple(subtree, tvb, pOffset, hf_opcua_ProfileUris, parseString);
}
void parseGetEndpointsResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "GetEndpointsResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_GetEndpointsResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Endpoints", parseEndpointDescription);
}
void parseRegisterServerRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "RegisterServerRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RegisterServerRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseRegisteredServer(subtree, tvb, pOffset, "Server");
}
void parseRegisterServerResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "RegisterServerResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RegisterServerResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
}
void parseOpenSecureChannelRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "OpenSecureChannelRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_OpenSecureChannelRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_ClientProtocolVersion);
parseSecurityTokenRequestType(subtree, tvb, pOffset);
parseMessageSecurityMode(subtree, tvb, pOffset);
parseByteString(subtree, tvb, pOffset, hf_opcua_ClientNonce);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestedLifetime);
}
void parseOpenSecureChannelResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "OpenSecureChannelResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_OpenSecureChannelResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_ServerProtocolVersion);
parseChannelSecurityToken(subtree, tvb, pOffset, "SecurityToken");
parseByteString(subtree, tvb, pOffset, hf_opcua_ServerNonce);
}
void parseCloseSecureChannelRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "CloseSecureChannelRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CloseSecureChannelRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
}
void parseCloseSecureChannelResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "CloseSecureChannelResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CloseSecureChannelResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
}
void parseCreateSessionRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "CreateSessionRequest");
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
}
void parseCreateSessionResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "CreateSessionResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CreateSessionResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseNodeId(subtree, tvb, pOffset, "SessionId");
parseNodeId(subtree, tvb, pOffset, "AuthenticationToken");
parseDouble(subtree, tvb, pOffset, hf_opcua_RevisedSessionTimeout);
parseByteString(subtree, tvb, pOffset, hf_opcua_ServerNonce);
parseByteString(subtree, tvb, pOffset, hf_opcua_ServerCertificate);
parseArrayComplex(subtree, tvb, pOffset, "ServerEndpoints", parseEndpointDescription);
parseArrayComplex(subtree, tvb, pOffset, "ServerSoftwareCertificates", parseSignedSoftwareCertificate);
parseSignatureData(subtree, tvb, pOffset, "ServerSignature");
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxRequestMessageSize);
}
void parseActivateSessionRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "ActivateSessionRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ActivateSessionRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseSignatureData(subtree, tvb, pOffset, "ClientSignature");
parseArrayComplex(subtree, tvb, pOffset, "ClientSoftwareCertificates", parseSignedSoftwareCertificate);
parseArraySimple(subtree, tvb, pOffset, hf_opcua_LocaleIds, parseString);
parseExtensionObject(subtree, tvb, pOffset, "UserIdentityToken");
parseSignatureData(subtree, tvb, pOffset, "UserTokenSignature");
}
void parseActivateSessionResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "ActivateSessionResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ActivateSessionResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseByteString(subtree, tvb, pOffset, hf_opcua_ServerNonce);
parseArraySimple(subtree, tvb, pOffset, hf_opcua_Results, parseStatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseCloseSessionRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "CloseSessionRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CloseSessionRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseBoolean(subtree, tvb, pOffset, hf_opcua_DeleteSubscriptions);
}
void parseCloseSessionResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "CloseSessionResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CloseSessionResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
}
void parseCancelRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "CancelRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CancelRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestHandle);
}
void parseCancelResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "CancelResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CancelResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_CancelCount);
}
void parseAddNodesRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "AddNodesRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AddNodesRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "NodesToAdd", parseAddNodesItem);
}
void parseAddNodesResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "AddNodesResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AddNodesResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", parseAddNodesResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseAddReferencesRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "AddReferencesRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AddReferencesRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "ReferencesToAdd", parseAddReferencesItem);
}
void parseAddReferencesResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "AddReferencesResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_AddReferencesResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, hf_opcua_Results, parseStatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseDeleteNodesRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "DeleteNodesRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteNodesRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "NodesToDelete", parseDeleteNodesItem);
}
void parseDeleteNodesResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "DeleteNodesResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteNodesResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, hf_opcua_Results, parseStatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseDeleteReferencesRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "DeleteReferencesRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteReferencesRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "ReferencesToDelete", parseDeleteReferencesItem);
}
void parseDeleteReferencesResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "DeleteReferencesResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteReferencesResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, hf_opcua_Results, parseStatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseBrowseRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "BrowseRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_BrowseRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseViewDescription(subtree, tvb, pOffset, "View");
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestedMaxReferencesPerNode);
parseArrayComplex(subtree, tvb, pOffset, "NodesToBrowse", parseBrowseDescription);
}
void parseBrowseResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "BrowseResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_BrowseResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", parseBrowseResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseBrowseNextRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "BrowseNextRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_BrowseNextRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseBoolean(subtree, tvb, pOffset, hf_opcua_ReleaseContinuationPoints);
parseArraySimple(subtree, tvb, pOffset, hf_opcua_ContinuationPoints, parseByteString);
}
void parseBrowseNextResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "BrowseNextResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_BrowseNextResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", parseBrowseResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseTranslateBrowsePathsToNodeIdsRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "TranslateBrowsePathsToNodeIdsRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TranslateBrowsePathsToNodeIdsRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "BrowsePaths", parseBrowsePath);
}
void parseTranslateBrowsePathsToNodeIdsResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "TranslateBrowsePathsToNodeIdsResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TranslateBrowsePathsToNodeIdsResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", parseBrowsePathResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseRegisterNodesRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "RegisterNodesRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RegisterNodesRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "NodesToRegister", parseNodeId);
}
void parseRegisterNodesResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "RegisterNodesResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RegisterNodesResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "RegisteredNodeIds", parseNodeId);
}
void parseUnregisterNodesRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "UnregisterNodesRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_UnregisterNodesRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "NodesToUnregister", parseNodeId);
}
void parseUnregisterNodesResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "UnregisterNodesResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_UnregisterNodesResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
}
void parseQueryFirstRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "QueryFirstRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_QueryFirstRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseViewDescription(subtree, tvb, pOffset, "View");
parseArrayComplex(subtree, tvb, pOffset, "NodeTypes", parseNodeTypeDescription);
parseContentFilter(subtree, tvb, pOffset, "Filter");
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxDataSetsToReturn);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxReferencesToReturn);
}
void parseQueryFirstResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "QueryFirstResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_QueryFirstResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "QueryDataSets", parseQueryDataSet);
parseByteString(subtree, tvb, pOffset, hf_opcua_ContinuationPoint);
parseArrayComplex(subtree, tvb, pOffset, "ParsingResults", parseParsingResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
parseContentFilterResult(subtree, tvb, pOffset, "FilterResult");
}
void parseQueryNextRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "QueryNextRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_QueryNextRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseBoolean(subtree, tvb, pOffset, hf_opcua_ReleaseContinuationPoint);
parseByteString(subtree, tvb, pOffset, hf_opcua_ContinuationPoint);
}
void parseQueryNextResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "QueryNextResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_QueryNextResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "QueryDataSets", parseQueryDataSet);
parseByteString(subtree, tvb, pOffset, hf_opcua_RevisedContinuationPoint);
}
void parseReadRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "ReadRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ReadRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseDouble(subtree, tvb, pOffset, hf_opcua_MaxAge);
parseTimestampsToReturn(subtree, tvb, pOffset);
parseArrayComplex(subtree, tvb, pOffset, "NodesToRead", parseReadValueId);
}
void parseReadResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "ReadResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ReadResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", parseDataValue);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseHistoryReadRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "HistoryReadRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryReadRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseExtensionObject(subtree, tvb, pOffset, "HistoryReadDetails");
parseTimestampsToReturn(subtree, tvb, pOffset);
parseBoolean(subtree, tvb, pOffset, hf_opcua_ReleaseContinuationPoints);
parseArrayComplex(subtree, tvb, pOffset, "NodesToRead", parseHistoryReadValueId);
}
void parseHistoryReadResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "HistoryReadResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryReadResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", parseHistoryReadResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseWriteRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "WriteRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_WriteRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "NodesToWrite", parseWriteValue);
}
void parseWriteResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "WriteResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_WriteResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, hf_opcua_Results, parseStatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseHistoryUpdateRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "HistoryUpdateRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryUpdateRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "HistoryUpdateDetails", parseExtensionObject);
}
void parseHistoryUpdateResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "HistoryUpdateResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_HistoryUpdateResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", parseHistoryUpdateResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseCallRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "CallRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CallRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "MethodsToCall", parseCallMethodRequest);
}
void parseCallResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "CallResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CallResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", parseCallMethodResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseCreateMonitoredItemsRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "CreateMonitoredItemsRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CreateMonitoredItemsRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseTimestampsToReturn(subtree, tvb, pOffset);
parseArrayComplex(subtree, tvb, pOffset, "ItemsToCreate", parseMonitoredItemCreateRequest);
}
void parseCreateMonitoredItemsResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "CreateMonitoredItemsResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CreateMonitoredItemsResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", parseMonitoredItemCreateResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseModifyMonitoredItemsRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "ModifyMonitoredItemsRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ModifyMonitoredItemsRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseTimestampsToReturn(subtree, tvb, pOffset);
parseArrayComplex(subtree, tvb, pOffset, "ItemsToModify", parseMonitoredItemModifyRequest);
}
void parseModifyMonitoredItemsResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "ModifyMonitoredItemsResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ModifyMonitoredItemsResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", parseMonitoredItemModifyResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseSetMonitoringModeRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "SetMonitoringModeRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SetMonitoringModeRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseMonitoringMode(subtree, tvb, pOffset);
parseArraySimple(subtree, tvb, pOffset, hf_opcua_MonitoredItemIds, parseUInt32);
}
void parseSetMonitoringModeResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "SetMonitoringModeResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SetMonitoringModeResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, hf_opcua_Results, parseStatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseSetTriggeringRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "SetTriggeringRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SetTriggeringRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseUInt32(subtree, tvb, pOffset, hf_opcua_TriggeringItemId);
parseArraySimple(subtree, tvb, pOffset, hf_opcua_LinksToAdd, parseUInt32);
parseArraySimple(subtree, tvb, pOffset, hf_opcua_LinksToRemove, parseUInt32);
}
void parseSetTriggeringResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "SetTriggeringResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SetTriggeringResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, hf_opcua_AddResults, parseStatusCode);
parseArrayComplex(subtree, tvb, pOffset, "AddDiagnosticInfos", parseDiagnosticInfo);
parseArraySimple(subtree, tvb, pOffset, hf_opcua_RemoveResults, parseStatusCode);
parseArrayComplex(subtree, tvb, pOffset, "RemoveDiagnosticInfos", parseDiagnosticInfo);
}
void parseDeleteMonitoredItemsRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "DeleteMonitoredItemsRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteMonitoredItemsRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseArraySimple(subtree, tvb, pOffset, hf_opcua_MonitoredItemIds, parseUInt32);
}
void parseDeleteMonitoredItemsResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "DeleteMonitoredItemsResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteMonitoredItemsResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, hf_opcua_Results, parseStatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseCreateSubscriptionRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "CreateSubscriptionRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CreateSubscriptionRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseDouble(subtree, tvb, pOffset, hf_opcua_RequestedPublishingInterval);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestedLifetimeCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestedMaxKeepAliveCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxNotificationsPerPublish);
parseBoolean(subtree, tvb, pOffset, hf_opcua_PublishingEnabled);
parseByte(subtree, tvb, pOffset, hf_opcua_Priority);
}
void parseCreateSubscriptionResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "CreateSubscriptionResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_CreateSubscriptionResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseDouble(subtree, tvb, pOffset, hf_opcua_RevisedPublishingInterval);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RevisedLifetimeCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RevisedMaxKeepAliveCount);
}
void parseModifySubscriptionRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "ModifySubscriptionRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ModifySubscriptionRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseDouble(subtree, tvb, pOffset, hf_opcua_RequestedPublishingInterval);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestedLifetimeCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RequestedMaxKeepAliveCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_MaxNotificationsPerPublish);
parseByte(subtree, tvb, pOffset, hf_opcua_Priority);
}
void parseModifySubscriptionResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "ModifySubscriptionResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_ModifySubscriptionResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseDouble(subtree, tvb, pOffset, hf_opcua_RevisedPublishingInterval);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RevisedLifetimeCount);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RevisedMaxKeepAliveCount);
}
void parseSetPublishingModeRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "SetPublishingModeRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SetPublishingModeRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseBoolean(subtree, tvb, pOffset, hf_opcua_PublishingEnabled);
parseArraySimple(subtree, tvb, pOffset, hf_opcua_SubscriptionIds, parseUInt32);
}
void parseSetPublishingModeResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "SetPublishingModeResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_SetPublishingModeResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, hf_opcua_Results, parseStatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parsePublishRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "PublishRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_PublishRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArrayComplex(subtree, tvb, pOffset, "SubscriptionAcknowledgements", parseSubscriptionAcknowledgement);
}
void parsePublishResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "PublishResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_PublishResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseArraySimple(subtree, tvb, pOffset, hf_opcua_AvailableSequenceNumbers, parseUInt32);
parseBoolean(subtree, tvb, pOffset, hf_opcua_MoreNotifications);
parseNotificationMessage(subtree, tvb, pOffset, "NotificationMessage");
parseArraySimple(subtree, tvb, pOffset, hf_opcua_Results, parseStatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseRepublishRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "RepublishRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RepublishRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseUInt32(subtree, tvb, pOffset, hf_opcua_SubscriptionId);
parseUInt32(subtree, tvb, pOffset, hf_opcua_RetransmitSequenceNumber);
}
void parseRepublishResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "RepublishResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_RepublishResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseNotificationMessage(subtree, tvb, pOffset, "NotificationMessage");
}
void parseTransferSubscriptionsRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "TransferSubscriptionsRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TransferSubscriptionsRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArraySimple(subtree, tvb, pOffset, hf_opcua_SubscriptionIds, parseUInt32);
parseBoolean(subtree, tvb, pOffset, hf_opcua_SendInitialValues);
}
void parseTransferSubscriptionsResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "TransferSubscriptionsResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_TransferSubscriptionsResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArrayComplex(subtree, tvb, pOffset, "Results", parseTransferResult);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void parseDeleteSubscriptionsRequest(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "DeleteSubscriptionsRequest");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteSubscriptionsRequest);
parseRequestHeader(subtree, tvb, pOffset, "RequestHeader");
parseArraySimple(subtree, tvb, pOffset, hf_opcua_SubscriptionIds, parseUInt32);
}
void parseDeleteSubscriptionsResponse(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti = proto_tree_add_text(tree, tvb, 0, -1, "DeleteSubscriptionsResponse");
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_DeleteSubscriptionsResponse);
parseResponseHeader(subtree, tvb, pOffset, "ResponseHeader");
parseArraySimple(subtree, tvb, pOffset, hf_opcua_Results, parseStatusCode);
parseArrayComplex(subtree, tvb, pOffset, "DiagnosticInfos", parseDiagnosticInfo);
}
void registerServiceTypes(void)
{
proto_register_subtree_array(ett, array_length(ett));
}
