void dispatchExtensionObjectType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int TypeId)
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
(*g_arExtensionObjectParserTable[indx].pParser)(tree, tvb, &iOffset, g_arExtensionObjectParserTable[indx].typeName);
break;
}
indx++;
}
if (bFound == 0)
{
if (iLen == -1)
{
proto_tree_add_text(tree, tvb, *pOffset, 4, "[OpcUa Null ByteString]");
}
else if (iLen >= 0)
{
proto_tree_add_item(tree, hf_opcua_ByteString, tvb, iOffset, iLen, ENC_NA);
iOffset += iLen;
}
else
{
char *szValue = wmem_strdup_printf(wmem_packet_scope(), "[Invalid ByteString] Invalid length: %d", iLen);
proto_tree_add_text(tree, tvb, *pOffset, 4, "%s", szValue);
}
}
*pOffset = iOffset;
}
