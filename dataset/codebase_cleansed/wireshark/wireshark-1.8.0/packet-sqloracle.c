static void ParseSqlStatement( UI8_P pSqlData, UI16_T dataLen)
{
char *pSqlModifyData = (I8_P)m_pCurQuery;
int i = 0;
while (*pSqlData != '\1' && *pSqlData != '\0' && i < dataLen)
{
if (*pSqlData < ' ')
{
*pSqlModifyData = ' ';
}
else
{
*pSqlModifyData = *pSqlData;
}
pSqlModifyData++;
pSqlData++;
i++;
}
*pSqlModifyData = '\0';
#if 0
appMsg = (I8_P)m_pCurQuery;
#endif
if (g_ascii_strncasecmp((I8_P)m_pCurQuery, "update", 6) == 0)
{
m_numOfUpdate++;
#if 0
pSummaryStat->m_numOfUpdate++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfUpdate++;
#endif
}
else if (g_ascii_strncasecmp((I8_P)m_pCurQuery, "select", 6) == 0)
{
m_numOfSelect++;
#if 0
pSummaryStat->m_numOfSelect++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfSelect++;
#endif
}
else if (g_ascii_strncasecmp((I8_P)m_pCurQuery, "insert", 6) == 0)
{
m_numOfInsert++;
#if 0
pSummaryStat->m_numOfInsert++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfInsert++;
#endif
}
else if (g_ascii_strncasecmp((I8_P)m_pCurQuery, "delete", 6) == 0)
{
m_numOfDelete++;
#if 0
pSummaryStat->m_numOfDelete++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfDelete++;
#endif
}
else if (g_ascii_strncasecmp((I8_P)m_pCurQuery, "rollback", 8) == 0)
{
m_numOfRollback++;
#if 0
pSummaryStat->m_numOfRollback++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfRollback++;
#endif
}
else if (g_ascii_strncasecmp((I8_P)m_pCurQuery, "set", 3) == 0)
{
m_numOfSet++;
#if 0
pSummaryStat->m_numOfSet++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfSet++;
#endif
}
else if (g_ascii_strncasecmp((I8_P)m_pCurQuery, "start", 5) == 0)
{
m_numOfStart++;
#if 0
pSummaryStat->m_numOfStart++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfStart++;
#endif
}
else if (g_ascii_strncasecmp((I8_P)m_pCurQuery, "commit", 6) == 0)
{
m_numOfCommit++;
#if 0
pSummaryStat->m_numOfCommit++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfCommit++;
#endif
}
else
{
m_numOfOtherStatement++;
#if 0
pSummaryStat->m_numOfOtherStatement++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfOtherStatement++;
#endif
}
m_numOfTransaction++;
#if 0
m_pSummaryStat->m_numOfTransaction++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfTransaction++;
#endif
}
static gboolean FindBeginningSQLString(UI8_P *pBuf, UI16_T *pDataLen, int lookSize)
{
UI8_P pString = *pBuf;
gboolean bAlpha1 = isalpha(pString[0]) != 0;
gboolean bAlpha2 = isalpha(pString[1]) != 0;
gboolean bAlpha3 = isalpha(pString[2]) != 0;
gboolean bAlpha4 = isalpha(pString[3]) != 0;
gboolean bComment = FALSE;
UI16_T dataLen = *pDataLen;
while ( (dataLen > 2) && (lookSize > 0) && ((bAlpha1 == FALSE) || (bAlpha2 == FALSE) || (bAlpha3 == FALSE) || (bAlpha4 == FALSE)))
{
if (bComment)
{
if (*((UI16_P)pString) == 0x2F2A)
{
bComment = FALSE;
pString ++;
dataLen --;
}
pString ++;
dataLen --;
}
else
{
if (*((UI16_P)pString) == 0x2A2F)
{
bComment = TRUE;
dataLen -= 2;
pString += 2;
bAlpha2 = isalpha(pString[1]) != 0;
bAlpha3 = isalpha(pString[2]) != 0;
bAlpha4 = isalpha(pString[3]) != 0;
continue;
}
pString++;
bAlpha1 = bAlpha2;
bAlpha2 = isalpha(pString[1]) != 0;
bAlpha3 = isalpha(pString[2]) != 0;
bAlpha4 = isalpha(pString[3]) != 0;
dataLen --;
if (*((UI8_P)pString) != 0x0)
lookSize--;
}
}
if (bAlpha1 && bAlpha2 && bAlpha3 && bAlpha4)
{
*pBuf = pString;
*pDataLen = dataLen;
return TRUE;
}
else
return FALSE;
}
static gboolean ParseCommand(proto_tree *tree,tvbuff_t *tvb, int offset, packet_info *pinfo,UI16_T dataLen)
{
UI8_T pAddress[1024];
UI16_T SQLDataLen = dataLen;
int i;
UI8_P pAddr;
for (i=0; i<1024;i++)
{
pAddress[i] = '\0';
}
tvb_memcpy (tvb, pAddress,offset, dataLen);
pAddr = (UI8_P)pAddress;
if (FindBeginningSQLString((UI8_P*)&pAddr, &SQLDataLen, 0x30) == TRUE)
{
ParseSqlStatement( pAddr, dataLen);
if (tree)
proto_tree_add_text(tree, tvb, offset+dataLen-SQLDataLen, SQLDataLen,
"SQL statement = %s",m_pCurQuery);
col_clear(pinfo->cinfo, COL_INFO);
if (check_col(pinfo->cinfo, COL_INFO))
col_add_str(pinfo->cinfo, COL_INFO, m_pCurQuery );
return TRUE;
}
return FALSE;
}
static void
dissect_sqloracle(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *sqloracle_tree = NULL;
int offset = 0,dataLen,nocol,numItersThisTime,flag,iterNum,uacBufLength;
guint8 header_operation,func_type=0;
m_pCurQuery[0] = '0';
pinfo->current_proto = "SQLORACLE";
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SQL");
col_clear(pinfo->cinfo, COL_INFO);
header_operation = tvb_get_guint8(tvb, offset);
dataLen = tvb_reported_length_remaining(tvb, offset);
if (header_operation != NET8_TYPE_FUNCCOMPLETE)
func_type = tvb_get_guint8(tvb, offset+1);
if ( check_col(pinfo->cinfo, COL_INFO))
{
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(header_operation, sqloracle_operation_type, ""));
}
if ( tree )
{
ti = proto_tree_add_item(tree, proto_sqloracle, tvb, 0, -1, ENC_NA);
sqloracle_tree = proto_item_add_subtree(ti, ett_sqloracle);
proto_tree_add_uint(sqloracle_tree, hf_sqloracle_operation, tvb, offset, 1,header_operation);
if (func_type && header_operation !=NET8_TYPE_ROWTRANSFER)
proto_tree_add_uint(sqloracle_tree, hf_sqloracle_func_type, tvb, offset+1, 1,func_type);
}
switch (header_operation)
{
case NET8_TYPE_USERTOSERVER:
if ( check_col(pinfo->cinfo, COL_INFO))
{
col_append_fstr(pinfo->cinfo, COL_INFO, ":%s ", val_to_str(func_type, sql_func_type, ""));
}
switch (func_type)
{
case NET8_USER_FUNC_PARSE:
ParseCommand(sqloracle_tree,tvb,offset+0x0B,pinfo,dataLen-0x0B);
break;
case NET8_USER_FUNC_OALL:
case NET8_USER_FUNC_OALL8:
if (dataLen > (0x19 + 8))
{
if (ParseCommand(sqloracle_tree,tvb, offset+0x12, pinfo,dataLen - 0x12) == TRUE)
break;
}
break;
case NET8_USER_FUNC_OSQL7:
if (dataLen > (0x2A + 8))
{
if (ParseCommand(sqloracle_tree,tvb, offset + 0x2A , pinfo,dataLen - 0x2A ) == TRUE)
break;
}
break;
case NET8_USER_FUNC_OALL7:
if (dataLen > (0x2A + 8))
{
if (ParseCommand(sqloracle_tree,tvb, offset + 0x14, pinfo,dataLen - 0x14) == TRUE)
{
if (check_col(pinfo->cinfo, COL_INFO))
col_add_str(pinfo->cinfo, COL_INFO, m_pCurQuery );
break;
}
else
if (ParseCommand(sqloracle_tree,tvb, offset + 0x30, pinfo,dataLen - 0x30) == TRUE)
break;
}
break;
}
break;
case NET8_TYPE_ROWTRANSFER:
flag = func_type;
proto_tree_add_uint(sqloracle_tree, hf_sqloracle_flag, tvb, offset+1, 1,flag);
nocol = tvb_get_guint8(tvb, offset+2);
iterNum = tvb_get_guint8(tvb, offset+3);
numItersThisTime = tvb_get_ntohs(tvb, offset+5);
uacBufLength = tvb_get_ntohs(tvb, offset+7);
proto_tree_add_uint(sqloracle_tree, hf_sqloracle_num_column, tvb, offset+2, 1,nocol);
proto_tree_add_uint(sqloracle_tree, hf_sqloracle_itemNum, tvb, offset+3, 1,iterNum);
proto_tree_add_uint(sqloracle_tree, hf_sqloracle_numItersThisTime, tvb, offset+5, 2,numItersThisTime);
proto_tree_add_uint(sqloracle_tree, hf_sqloracle_uacBufLength, tvb, offset+7, 2,uacBufLength);
break;
default:
return;
break;
}
}
void
proto_register_sqloracle(void)
{
static hf_register_info hf[] =
{
{ &hf_sqloracle_operation,
{ "Basic Operation", "sqloracle.operation", FT_UINT8, BASE_DEC, VALS(sqloracle_operation_type), 0x0, NULL, HFILL }
},
{ &hf_sqloracle_func_type,
{ "Function Type", "sqloracle.type", FT_UINT8, BASE_DEC, VALS(sql_func_type), 0x0, NULL, HFILL }
},
{ &hf_sqloracle_flag,
{ "flag", "sqloracle.flag", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_sqloracle_num_column,
{ "Number of Columns", "sqloracle.nocolumn", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_sqloracle_itemNum,
{ "Iteration Number", "sqloracle.itemNum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_sqloracle_numItersThisTime,
{ "# of iterations this time", "sqloracle.numItersThisTime", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_sqloracle_uacBufLength,
{ "user access buffer length", "sqloracle.uacBufLength", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_sqloracle_stmt,
{ "SQL statement", "sqloracle.stmt", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] =
{
&ett_sqloracle,
&ett_sqloracle_operation,
};
proto_sqloracle = proto_register_protocol("SQL -Net8 Data", "SQL", "sqloracle");
proto_register_field_array(proto_sqloracle, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("sqloracle", dissect_sqloracle, proto_sqloracle);
}
void
proto_reg_handoff_sqloracle(void)
{
dissector_handle_t sqloracle_handle;
sqloracle_handle = find_dissector("sqloracle");
dissector_add_uint("tns.port", TCP_PORT_TNS, sqloracle_handle);
}
