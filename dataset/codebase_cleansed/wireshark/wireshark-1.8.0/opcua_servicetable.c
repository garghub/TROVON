void dispatchService(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int ServiceId)
{
int index = 0;
while (index < g_NumServices)
{
if (g_arParserTable[index].iRequestId == ServiceId)
{
(*g_arParserTable[index].pParser)(tree, tvb, pOffset);
break;
}
index++;
}
}
