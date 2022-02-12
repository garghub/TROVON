void dispatchService(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int ServiceId)
{
int indx = 0;
while (indx < g_NumServices)
{
if (g_arParserTable[indx].iRequestId == ServiceId)
{
(*g_arParserTable[indx].pParser)(tree, tvb, pOffset);
break;
}
indx++;
}
}
