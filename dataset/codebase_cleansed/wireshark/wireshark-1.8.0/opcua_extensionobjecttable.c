void dispatchExtensionObjectType(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int TypeId)
{
gint iOffset = *pOffset;
int index = 0;
int bFound = 0;
gint32 iLen = 0;
iLen = tvb_get_letohl(tvb, iOffset);
iOffset += 4;
while (index < g_NumTypes)
{
if (g_arExtensionObjectParserTable[index].iRequestId == TypeId)
{
bFound = 1;
(*g_arExtensionObjectParserTable[index].pParser)(tree, tvb, &iOffset, g_arExtensionObjectParserTable[index].typeName);
break;
}
index++;
}
if (bFound == 0)
{
if (iLen == -1)
{
proto_tree_add_text(tree, tvb, iOffset, 0, "[OpcUa Null ByteString]");
}
else if (iLen >= 0)
{
proto_tree_add_item(tree, hf_opcua_ByteString, tvb, iOffset, iLen, ENC_NA);
iOffset += iLen;
}
else
{
char *szValue = ep_strdup_printf("[Invalid ByteString] Invalid length: %d", iLen);
proto_tree_add_text(tree, tvb, iOffset, 0, "%s", szValue);
}
}
*pOffset = iOffset;
}
