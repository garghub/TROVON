void dispatchExtensionObjectType(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint *pOffset, int TypeId)
{
gint iOffset = *pOffset;
int indx = 0;
int bFound = 0;
gint32 iLen = 0;
iLen = tvb_get_letohl(tvb, iOffset);
iOffset += 4;
while (indx < g_NumTypes)
{
if (g_arExtensionObjectParserTable[indx].iRequestId == TypeId)
{
bFound = 1;
(*g_arExtensionObjectParserTable[indx].pParser)(tree, tvb, pinfo, &iOffset, g_arExtensionObjectParserTable[indx].typeName);
break;
}
indx++;
}
if (bFound == 0)
{
if (iLen == -1)
{
proto_tree_add_bytes_format_value(tree, hf_opcua_ByteString, tvb, *pOffset, 4, NULL, "[OpcUa Null ByteString]");
}
else if (iLen >= 0)
{
proto_tree_add_item(tree, hf_opcua_ByteString, tvb, iOffset, iLen, ENC_NA);
iOffset += iLen;
}
else
{
proto_tree_add_bytes_format_value(tree, hf_opcua_ByteString, tvb, *pOffset, 4, NULL, "[Invalid ByteString] Invalid length: %d", iLen);
}
}
*pOffset = iOffset;
}
