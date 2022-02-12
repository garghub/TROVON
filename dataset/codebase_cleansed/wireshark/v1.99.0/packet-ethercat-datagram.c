static const char* convertEcCmdToText(int cmd, const value_string ec_cmd[])
{
return val_to_str(cmd, ec_cmd, "<UNKNOWN: %d>");
}
static void init_EcParserHDR(EcParserHDR* pHdr, tvbuff_t *tvb, gint offset)
{
pHdr->cmd = tvb_get_guint8(tvb, offset++);
pHdr->idx = tvb_get_guint8(tvb, offset++);
pHdr->anAddrUnion.a.adp = tvb_get_letohs(tvb, offset); offset+=(int)sizeof(guint16);
pHdr->anAddrUnion.a.ado = tvb_get_letohs(tvb, offset); offset+=(int)sizeof(guint16);
pHdr->len = tvb_get_letohs(tvb, offset); offset+=(int)sizeof(guint16);
pHdr->intr = tvb_get_letohs(tvb, offset);
}
static void init_dc_measure(guint32* pDC, tvbuff_t *tvb, gint offset)
{
int i;
for ( i=0; i<4; i++ )
{
pDC[i] = tvb_get_letohl(tvb, offset);
offset+=(int)sizeof(guint32);
}
}
static guint16 get_wc(EcParserHDR* pHdr, tvbuff_t *tvb, gint offset)
{
return tvb_get_letohs(tvb, offset+EcParserHDR_Len+(pHdr->len&0x07ff));
}
static guint16 get_cmd_len(EcParserHDR* pHdr)
{
return (EcParserHDR_Len+(pHdr->len&0x07ff)+sizeof(guint16));
}
static void EcSummaryFormater(guint32 datalength, tvbuff_t *tvb, gint offset, char *szText, gint nMax)
{
guint nSub=0;
guint nLen=0;
guint8 nCmds[4];
guint nLens[4];
EcParserHDR ecFirst;
EcParserHDR ecParser;
guint suboffset=0;
init_EcParserHDR(&ecFirst, tvb, offset);
while ( suboffset < datalength )
{
PEcParserHDR pEcParser;
if ( nSub > 0 )
{
init_EcParserHDR(&ecParser, tvb, offset+suboffset);
pEcParser = &ecParser;
}
else
pEcParser = &ecFirst;
if ( nSub < 4 )
{
nCmds[nSub] = pEcParser->cmd;
nLens[nSub] = pEcParser->len&0x07ff;
}
nSub++;
nLen += (pEcParser->len&0x07ff);
if ( (pEcParser->len&0x8000) == 0 )
break;
suboffset+=get_cmd_len(pEcParser);
}
if ( nSub == 1 )
{
guint16 len = ecFirst.len&0x07ff;
guint16 cnt = get_wc(&ecFirst, tvb, offset);
g_snprintf ( szText, nMax, "'%s': Len: %d, Adp 0x%x, Ado 0x%x, Wc %d ",
convertEcCmdToText(ecFirst.cmd, EcCmdShort), len, ecFirst.anAddrUnion.a.adp, ecFirst.anAddrUnion.a.ado, cnt );
}
else if ( nSub == 2 )
{
g_snprintf ( szText, nMax, "%d Cmds, '%s': len %d, '%s': len %d ",
nSub, convertEcCmdToText(nCmds[0], EcCmdShort), nLens[0], convertEcCmdToText(nCmds[1], EcCmdShort), nLens[1]);
}
else if ( nSub == 3 )
{
g_snprintf ( szText, nMax, "%d Cmds, '%s': len %d, '%s': len %d, '%s': len %d",
nSub, convertEcCmdToText(nCmds[0], EcCmdShort), nLens[0], convertEcCmdToText(nCmds[1], EcCmdShort), nLens[1], convertEcCmdToText(nCmds[2], EcCmdShort), nLens[2]);
}
else if ( nSub == 4 )
{
g_snprintf ( szText, nMax, "%d Cmds, '%s': len %d, '%s': len %d, '%s': len %d, '%s': len %d",
nSub, convertEcCmdToText(nCmds[0], EcCmdShort), nLens[0], convertEcCmdToText(nCmds[1], EcCmdShort), nLens[1], convertEcCmdToText(nCmds[2], EcCmdShort), nLens[2], convertEcCmdToText(nCmds[3], EcCmdShort), nLens[3]);
}
else
g_snprintf ( szText, nMax, "%d Cmds, SumLen %d, '%s'... ",
nSub, nLen, convertEcCmdToText(ecFirst.cmd, EcCmdShort));
}
static void EcCmdFormatter(guint8 cmd, char *szText, gint nMax)
{
gint idx=0;
const gchar *szCmd = try_val_to_str_idx((guint32)cmd, EcCmdLong, &idx);
if ( idx != -1 )
g_snprintf(szText, nMax, "Cmd : %d (%s)", cmd, szCmd);
else
g_snprintf(szText, nMax, "Cmd : %d (Unknown command)", cmd);
}
static void EcSubFormatter(tvbuff_t *tvb, gint offset, char *szText, gint nMax)
{
EcParserHDR ecParser;
guint16 len, cnt;
init_EcParserHDR(&ecParser, tvb, offset);
len = ecParser.len&0x07ff;
cnt = get_wc(&ecParser, tvb, offset);
switch ( ecParser.cmd )
{
case EC_CMD_TYPE_NOP:
case EC_CMD_TYPE_APRD:
case EC_CMD_TYPE_APWR:
case EC_CMD_TYPE_APRW:
case EC_CMD_TYPE_FPRD:
case EC_CMD_TYPE_FPWR:
case EC_CMD_TYPE_FPRW:
case EC_CMD_TYPE_BRD:
case EC_CMD_TYPE_BWR:
case EC_CMD_TYPE_BRW:
case EC_CMD_TYPE_ARMW:
case EC_CMD_TYPE_FRMW:
g_snprintf ( szText, nMax, "EtherCAT datagram: Cmd: '%s' (%d), Len: %d, Adp 0x%x, Ado 0x%x, Cnt %d",
convertEcCmdToText(ecParser.cmd, EcCmdShort), ecParser.cmd, len, ecParser.anAddrUnion.a.adp, ecParser.anAddrUnion.a.ado, cnt);
break;
case EC_CMD_TYPE_LRD:
case EC_CMD_TYPE_LWR:
case EC_CMD_TYPE_LRW:
g_snprintf ( szText, nMax, "EtherCAT datagram: Cmd: '%s' (%d), Len: %d, Addr 0x%x, Cnt %d",
convertEcCmdToText(ecParser.cmd, EcCmdShort), ecParser.cmd, len, ecParser.anAddrUnion.addr, cnt);
break;
case EC_CMD_TYPE_EXT:
g_snprintf ( szText, nMax, "EtherCAT datagram: Cmd: 'EXT' (%d), Len: %d", ecParser.cmd, len);
break;
default:
g_snprintf ( szText, nMax, "EtherCAT datagram: Cmd: 'Unknown' (%d), Len: %d", ecParser.cmd, len);
}
}
static void dissect_ecat_datagram(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
proto_item *ti, *aitem = NULL;
proto_tree *ecat_datagrams_tree = NULL;
guint offset = 0;
char szText[200];
int nMax = sizeof(szText)-1;
guint b;
guint ecLength=0;
guint subCount = 0;
const guint datagram_length = tvb_length_remaining(tvb, offset);
guint datagram_padding_bytes = 0;
EcParserHDR ecHdr;
heur_dtbl_entry_t *hdtbl_entry;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ECAT");
col_clear(pinfo->cinfo, COL_INFO);
do
{
init_EcParserHDR(&ecHdr, tvb, ecLength);
ecLength += get_cmd_len(&ecHdr);
} while ((ecLength < datagram_length) &&
(ecHdr.len & 0x8000));
datagram_padding_bytes = datagram_length - ecLength;
EcSummaryFormater(ecLength, tvb, offset, szText, nMax);
col_append_str(pinfo->cinfo, COL_INFO, szText);
if( tree )
{
ti = proto_tree_add_item(tree, proto_ecat_datagram, tvb, 0, -1, ENC_NA);
ecat_datagrams_tree = proto_item_add_subtree(ti, ett_ecat);
proto_item_append_text(ti,": %s", szText);
}
do
{
proto_tree *ecat_datagram_tree = NULL, *ecat_header_tree = NULL, *ecat_fmmu_tree = NULL,
*ecat_fmmu_active_tree = NULL, *ecat_fmmu_type_tree = NULL, *ecat_syncman_tree = NULL,
*ecat_syncflag_tree = NULL, *ecat_dc_tree = NULL;
proto_item *hidden_item;
gint bMBox = FALSE;
guint32 subsize;
guint32 suboffset;
guint32 len;
ETHERCAT_MBOX_HEADER mbox;
suboffset = offset;
init_EcParserHDR(&ecHdr, tvb, suboffset);
subsize = get_cmd_len(&ecHdr);
len = ecHdr.len & 0x07ff;
if ( len >= sizeof(ETHERCAT_MBOX_HEADER_LEN) &&
(ecHdr.cmd==EC_CMD_TYPE_FPWR || ecHdr.cmd==EC_CMD_TYPE_FPRD || ecHdr.cmd==EC_CMD_TYPE_APWR || ecHdr.cmd==EC_CMD_TYPE_APRD) &&
ecHdr.anAddrUnion.a.ado>=0x1000
)
{
init_mbx_header(&mbox, tvb, suboffset+EcParserHDR_Len);
switch ( mbox.aControlUnion.v.Type )
{
case ETHERCAT_MBOX_TYPE_EOE:
case ETHERCAT_MBOX_TYPE_ADS:
case ETHERCAT_MBOX_TYPE_FOE:
case ETHERCAT_MBOX_TYPE_COE:
case ETHERCAT_MBOX_TYPE_SOE:
if ( mbox.Length <= 1500 )
{
bMBox = TRUE;
}
break;
}
}
if( tree )
{
EcSubFormatter(tvb, suboffset, szText, nMax);
ecat_datagram_tree = proto_tree_add_subtree(ecat_datagrams_tree, tvb, suboffset, subsize, ett_ecat_datagram_subtree, NULL, szText);
ecat_header_tree = proto_tree_add_subtree(ecat_datagram_tree, tvb, offset, EcParserHDR_Len, ett_ecat_header, NULL, "Header");
EcCmdFormatter(ecHdr.cmd, szText, nMax);
aitem = proto_tree_add_item(ecat_header_tree, hf_ecat_cmd, tvb, suboffset, sizeof(ecHdr.cmd), ENC_LITTLE_ENDIAN);
proto_item_set_text(aitem, "%s", szText);
if( subCount < 10 ){
aitem = proto_tree_add_item(ecat_header_tree, hf_ecat_sub_cmd[subCount], tvb, suboffset, sizeof(ecHdr.cmd), ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(aitem);
}
suboffset+= (int)sizeof(ecHdr.cmd);
proto_tree_add_item(ecat_header_tree, hf_ecat_idx, tvb, suboffset, sizeof(ecHdr.idx), ENC_LITTLE_ENDIAN);
if( subCount < 10 ){
aitem = proto_tree_add_item(ecat_header_tree, hf_ecat_sub_idx[subCount], tvb, suboffset, sizeof(ecHdr.idx), ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(aitem);
}
suboffset+= (int)sizeof(ecHdr.idx);
switch ( ecHdr.cmd )
{
case 10:
case 11:
case 12:
proto_tree_add_item(ecat_header_tree, hf_ecat_lad, tvb, suboffset, sizeof(ecHdr.anAddrUnion.a.adp)+sizeof(ecHdr.anAddrUnion.a.ado), ENC_LITTLE_ENDIAN);
if( subCount < 10 ){
aitem = proto_tree_add_item(ecat_header_tree, hf_ecat_sub_lad[subCount], tvb, suboffset, sizeof(ecHdr.anAddrUnion.a.adp)+sizeof(ecHdr.anAddrUnion.a.ado), ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(aitem);
}
suboffset += (int)((sizeof(ecHdr.anAddrUnion.a.adp)+sizeof(ecHdr.anAddrUnion.a.ado)));
break;
default:
proto_tree_add_item(ecat_header_tree, hf_ecat_adp, tvb, suboffset, sizeof(ecHdr.anAddrUnion.a.adp), ENC_LITTLE_ENDIAN);
if( subCount < 10 ){
aitem = proto_tree_add_item(ecat_header_tree, hf_ecat_sub_adp[subCount], tvb, suboffset, sizeof(ecHdr.anAddrUnion.a.adp), ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(aitem);
}
suboffset+= (int)sizeof(ecHdr.anAddrUnion.a.adp);
proto_tree_add_item(ecat_header_tree, hf_ecat_ado, tvb, suboffset, sizeof(ecHdr.anAddrUnion.a.ado), ENC_LITTLE_ENDIAN);
if( subCount < 10 ){
aitem = proto_tree_add_item(ecat_header_tree, hf_ecat_sub_ado[subCount], tvb, suboffset, sizeof(ecHdr.anAddrUnion.a.ado), ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(aitem);
}
suboffset+= (int)sizeof(ecHdr.anAddrUnion.a.ado);
}
{
proto_tree *length_sub_tree;
length_sub_tree = proto_tree_add_subtree_format(ecat_header_tree, tvb, suboffset, sizeof(ecHdr.len),
ett_ecat_length, NULL, "Length : %d (0x%x) - %s - %s",
len, len, ecHdr.len & 0x4000 ? "Roundtrip" : "No Roundtrip", ecHdr.len & 0x8000 ? "More Follows..." : "Last Sub Command");
proto_tree_add_item(length_sub_tree, hf_ecat_length_len, tvb, suboffset, sizeof(ecHdr.len), ENC_LITTLE_ENDIAN);
proto_tree_add_item(length_sub_tree, hf_ecat_length_r, tvb, suboffset, sizeof(ecHdr.len), ENC_LITTLE_ENDIAN);
proto_tree_add_item(length_sub_tree, hf_ecat_length_c, tvb, suboffset, sizeof(ecHdr.len), ENC_LITTLE_ENDIAN);
proto_tree_add_item(length_sub_tree, hf_ecat_length_m, tvb, suboffset, sizeof(ecHdr.len), ENC_LITTLE_ENDIAN);
suboffset+= (int)sizeof(ecHdr.len);
}
proto_tree_add_item(ecat_header_tree, hf_ecat_int, tvb, suboffset, sizeof(ecHdr.intr), ENC_LITTLE_ENDIAN);
suboffset+= (int)sizeof(ecHdr.intr);
}
else
{
suboffset+=EcParserHDR_Len;
}
if ( ecHdr.cmd>=1 && ecHdr.cmd<=9 && ecHdr.anAddrUnion.a.ado>=0x600 && ecHdr.anAddrUnion.a.ado<0x700 && (ecHdr.anAddrUnion.a.ado%16)==0 && (len%16)==0 )
{
if( tree )
{
for ( b=0; b < MIN(16, len/16); b++ )
{
aitem = proto_tree_add_item(ecat_datagram_tree, hf_ecat_fmmu, tvb, suboffset, 16, ENC_NA);
proto_item_set_text(aitem, "Fieldbus Memory Management Units (FMMU)");
ecat_fmmu_tree = proto_item_add_subtree(aitem, ett_ecat_fmmu);
proto_tree_add_item(ecat_fmmu_tree, hf_ecat_fmmu_lstart, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
suboffset += 4;
proto_tree_add_item(ecat_fmmu_tree, hf_ecat_fmmu_llen, tvb, suboffset, 2, ENC_LITTLE_ENDIAN);
suboffset += 2;
proto_tree_add_item(ecat_fmmu_tree, hf_ecat_fmmu_lstartbit, tvb, suboffset, 1, ENC_LITTLE_ENDIAN);
suboffset += 1;
proto_tree_add_item(ecat_fmmu_tree, hf_ecat_fmmu_lendbit, tvb, suboffset, 1, ENC_LITTLE_ENDIAN);
suboffset += 1;
proto_tree_add_item(ecat_fmmu_tree, hf_ecat_fmmu_pstart, tvb, suboffset, 2, ENC_LITTLE_ENDIAN);
suboffset += 2;
proto_tree_add_item(ecat_fmmu_tree, hf_ecat_fmmu_pstartbit, tvb, suboffset, 1, ENC_LITTLE_ENDIAN);
suboffset += 1;
aitem = proto_tree_add_item(ecat_fmmu_tree, hf_ecat_fmmu_type, tvb, suboffset, 1, ENC_LITTLE_ENDIAN);
ecat_fmmu_type_tree = proto_item_add_subtree(aitem, ett_ecat_fmmu_type);
proto_tree_add_item(ecat_fmmu_type_tree, hf_ecat_fmmu_typeread, tvb, suboffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_fmmu_type_tree, hf_ecat_fmmu_typewrite, tvb, suboffset, 1, ENC_LITTLE_ENDIAN);
suboffset += 1;
aitem = proto_tree_add_item(ecat_fmmu_tree, hf_ecat_fmmu_active, tvb, suboffset, 1, ENC_LITTLE_ENDIAN);
ecat_fmmu_active_tree = proto_item_add_subtree(aitem, ett_ecat_fmmu_active);
proto_tree_add_item(ecat_fmmu_active_tree, hf_ecat_fmmu_active0, tvb, suboffset, 1, ENC_LITTLE_ENDIAN);
suboffset += 4;
}
if ( len > 0x100 )
{
len -= 0x100;
for (b = 0; b < MIN(32, len / 8); b++)
{
aitem = proto_tree_add_item(ecat_datagram_tree, hf_ecat_syncman, tvb, suboffset, 8, ENC_NA);
proto_item_set_text(aitem, "SyncManager");
ecat_syncman_tree = proto_item_add_subtree(aitem, ett_ecat_syncman);
proto_tree_add_item(ecat_syncman_tree, hf_ecat_syncman_start, tvb, suboffset, 2, ENC_LITTLE_ENDIAN);
suboffset+=2;
proto_tree_add_item(ecat_syncman_tree, hf_ecat_syncman_len, tvb, suboffset, 2, ENC_LITTLE_ENDIAN);
suboffset+=2;
aitem = proto_tree_add_item(ecat_syncman_tree, hf_ecat_syncman_flags, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
ecat_syncflag_tree = proto_item_add_subtree(aitem, ett_ecat_syncflag);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag0, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag1, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag2, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag4, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag5, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag8, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag9, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag10, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag11, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag12, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag13, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag16, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
suboffset+=4;
}
}
}
}
else if ( ecHdr.cmd>=1 && ecHdr.cmd<=9 && ecHdr.anAddrUnion.a.ado>=0x800 && ecHdr.anAddrUnion.a.ado<0x880 && (ecHdr.anAddrUnion.a.ado%8)==0 && (len%8)==0 )
{
if( tree )
{
for (b = 0; b < MIN(32, len / 8); b++)
{
aitem = proto_tree_add_item(ecat_datagram_tree, hf_ecat_syncman, tvb, suboffset, 8, ENC_NA);
proto_item_set_text(aitem, "SyncManager");
ecat_syncman_tree = proto_item_add_subtree(aitem, ett_ecat_syncman);
proto_tree_add_item(ecat_syncman_tree, hf_ecat_syncman_start, tvb, suboffset, 2, ENC_LITTLE_ENDIAN);
suboffset+=2;
proto_tree_add_item(ecat_syncman_tree, hf_ecat_syncman_len, tvb, suboffset, 2, ENC_LITTLE_ENDIAN);
suboffset+=2;
aitem = proto_tree_add_item(ecat_syncman_tree, hf_ecat_syncman_flags, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
ecat_syncflag_tree = proto_item_add_subtree(aitem, ett_ecat_syncflag);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag0, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag1, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag2, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag4, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag5, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag8, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag9, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag10, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag11, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag12, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag13, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ecat_syncflag_tree, hf_ecat_syncman_flag16, tvb, suboffset, 4, ENC_LITTLE_ENDIAN);
suboffset+=4;
}
}
}
else if ( (ecHdr.cmd == 1 || ecHdr.cmd == 4) && ecHdr.anAddrUnion.a.ado == 0x900 && ecHdr.len >= 16 )
{
if (tree)
{
guint32 pDC[4];
init_dc_measure(pDC, tvb, suboffset);
if(!dissector_try_heuristic(heur_subdissector_list, tvb, pinfo, ecat_datagram_tree, &hdtbl_entry, NULL))
{
aitem = proto_tree_add_item(ecat_datagram_tree, hf_ecat_data, tvb, suboffset, ecHdr.len & 0x07ff, ENC_NA);
ecat_dc_tree = proto_item_add_subtree(aitem, ett_ecat_dc);
}
else
{
ecat_dc_tree = ecat_datagram_tree;
}
if( subCount < 10 ){
aitem = proto_tree_add_item(ecat_datagram_tree, hf_ecat_sub_data[subCount], tvb, offset + EcParserHDR_Len, ecHdr.len & 0x07ff, ENC_NA);
PROTO_ITEM_SET_HIDDEN(aitem);
}
if ( pDC[3] != 0 )
{
proto_tree_add_uint(ecat_dc_tree, hf_ecat_dc_diff_da, tvb, suboffset, 4, pDC[3] - pDC[0]);
if( subCount < 10 ){
hidden_item = proto_tree_add_uint(ecat_dc_tree, hf_ecat_sub_dc_diff_da[subCount], tvb, suboffset, 4, pDC[3] - pDC[0]);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if ( pDC[1] != 0 )
{
proto_tree_add_uint(ecat_dc_tree, hf_ecat_dc_diff_bd, tvb, suboffset, 4, pDC[1] - pDC[3]);
if( subCount < 10 ){
hidden_item = proto_tree_add_uint(ecat_dc_tree, hf_ecat_sub_dc_diff_bd[subCount], tvb, suboffset, 4, pDC[1] - pDC[3]);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
else if ( pDC[2] != 0 )
{
proto_tree_add_uint(ecat_dc_tree, hf_ecat_dc_diff_cd, tvb, suboffset, 4, pDC[2] - pDC[3]);
if( subCount < 10 ){
hidden_item = proto_tree_add_uint(ecat_dc_tree, hf_ecat_sub_dc_diff_cd[subCount], tvb, suboffset, 4, pDC[2] - pDC[3]);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
if ( pDC[1] != 0 )
{
proto_tree_add_uint(ecat_dc_tree, hf_ecat_dc_diff_ba, tvb, suboffset, 4, pDC[1] - pDC[0]);
if( subCount < 10 ){
hidden_item = proto_tree_add_uint(ecat_dc_tree, hf_ecat_sub_dc_diff_ba[subCount], tvb, suboffset, 4, pDC[1] - pDC[0]);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if ( pDC[2] != 0 )
{
proto_tree_add_uint(ecat_dc_tree, hf_ecat_dc_diff_cb, tvb, suboffset, 4, pDC[2] - pDC[1]);
if( subCount < 10 ){
hidden_item = proto_tree_add_uint(ecat_dc_tree, hf_ecat_sub_dc_diff_cb[subCount], tvb, suboffset, 4, pDC[2] - pDC[1]);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
else if ( pDC[2] != 0 )
{
proto_tree_add_uint(ecat_dc_tree, hf_ecat_dc_diff_ca, tvb, suboffset, 4, pDC[2] - pDC[0]);
if( subCount < 10 ){
hidden_item = proto_tree_add_uint(ecat_dc_tree, hf_ecat_sub_dc_diff_ca[subCount], tvb, suboffset, 4, pDC[2] - pDC[0]);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
}
else if ( bMBox )
{
const guint MBoxLength = mbox.Length + 6 ;
next_tvb = tvb_new_subset_length(tvb, suboffset, MBoxLength);
call_dissector(ecat_mailbox_handle, next_tvb, pinfo, ecat_datagram_tree);
if( tree )
{
const guint startOfData = offset + EcParserHDR_Len + MBoxLength;
const guint dataLength = (ecHdr.len & 0x7ff) - MBoxLength;
if ( dataLength > 0 )
{
if(!dissector_try_heuristic(heur_subdissector_list, tvb, pinfo, ecat_datagram_tree, &hdtbl_entry, NULL))
{
proto_tree_add_item(ecat_datagram_tree, hf_ecat_data, tvb, startOfData, dataLength, ENC_NA);
}
if( subCount < 10 ){
aitem = proto_tree_add_item(ecat_datagram_tree, hf_ecat_sub_data[subCount], tvb, startOfData, dataLength, ENC_NA);
PROTO_ITEM_SET_HIDDEN(aitem);
}
}
}
}
else
{
if( tree )
{
if(!dissector_try_heuristic(heur_subdissector_list, tvb, pinfo, ecat_datagram_tree, &hdtbl_entry, NULL))
{
proto_tree_add_item(ecat_datagram_tree, hf_ecat_data, tvb, suboffset, ecHdr.len & 0x07ff, ENC_NA);
}
if( subCount < 10 ){
aitem = proto_tree_add_item(ecat_datagram_tree, hf_ecat_sub_data[subCount], tvb, offset + EcParserHDR_Len, ecHdr.len & 0x07ff, ENC_NA);
PROTO_ITEM_SET_HIDDEN(aitem);
}
}
}
if( tree )
{
proto_tree_add_item(ecat_datagram_tree, hf_ecat_cnt, tvb, offset + EcParserHDR_Len + len , 2, ENC_LITTLE_ENDIAN);
if( subCount < 10 ){
aitem = proto_tree_add_item(ecat_datagram_tree, hf_ecat_sub_cnt[subCount], tvb, offset + EcParserHDR_Len + len , 2, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(aitem);
}
}
offset+=subsize;
subCount++;
} while((offset < datagram_length) &&
(ecHdr.len & 0x8000));
if(datagram_padding_bytes > 0)
{
proto_tree_add_item(tree, hf_ecat_padding, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
}
}
void proto_register_ecat(void)
{
static hf_register_info hf[] =
{
{ &hf_ecat_sub,
{ "EtherCAT Frame", "ecat.sub", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_ecat_header,
{ "eader", "ecat.header",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
#endif
{ &hf_ecat_sub_data[0],
{ "Data", "ecat.sub1.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_data[1],
{ "Data", "ecat.sub2.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_data[2],
{ "Data", "ecat.sub3.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_data[3],
{ "Data", "ecat.sub4.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_data[4],
{ "Data", "ecat.sub5.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_data[5],
{ "Data", "ecat.sub6.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_data[6],
{ "Data", "ecat.sub7.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_data[7],
{ "Data", "ecat.sub8.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_data[8],
{ "Data", "ecat.sub9.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_data[9],
{ "Data", "ecat.sub10.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_data,
{ "Data", "ecat.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_cnt,
{ "Working Cnt", "ecat.cnt",
FT_UINT16, BASE_DEC, NULL, 0x0, "The working counter is increased once for each addressed device if at least one byte/bit of the data was successfully read and/or written by that device, it is increased once for every operation made by that device - read/write/read and write", HFILL }
},
{ &hf_ecat_sub_cnt[0],
{ "Working Cnt", "ecat.sub1.cnt",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cnt[1],
{ "Working Cnt", "ecat.sub2.cnt",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cnt[2],
{ "Working Cnt", "ecat.sub3.cnt",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cnt[3],
{ "Working Cnt", "ecat.sub4.cnt",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cnt[4],
{ "Working Cnt", "ecat.sub5.cnt",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cnt[5],
{ "Working Cnt", "ecat.sub6.cnt",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cnt[6],
{ "Working Cnt", "ecat.sub7.cnt",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cnt[7],
{ "Working Cnt", "ecat.sub8.cnt",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cnt[8],
{ "Working Cnt", "ecat.sub9.cnt",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cnt[9],
{ "Working Cnt", "ecat.sub10.cnt",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_cmd,
{ "Command", "ecat.cmd",
FT_UINT8, BASE_HEX, VALS(EcCmdShort), 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cmd[0],
{ "Command", "ecat.sub1.cmd",
FT_UINT8, BASE_HEX, VALS(EcCmdShort), 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cmd[1],
{ "Command", "ecat.sub2.cmd",
FT_UINT8, BASE_HEX, VALS(EcCmdShort), 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cmd[2],
{ "Command", "ecat.sub3.cmd",
FT_UINT8, BASE_HEX, VALS(EcCmdShort), 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cmd[3],
{ "Command", "ecat.sub4.cmd",
FT_UINT8, BASE_HEX, VALS(EcCmdShort), 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cmd[4],
{ "Command", "ecat.sub5.cmd",
FT_UINT8, BASE_HEX, VALS(EcCmdShort), 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cmd[5],
{ "Command", "ecat.sub6.cmd",
FT_UINT8, BASE_HEX, VALS(EcCmdShort), 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cmd[6],
{ "Command", "ecat.sub7.cmd",
FT_UINT8, BASE_HEX, VALS(EcCmdShort), 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cmd[7],
{ "Command", "ecat.sub8.cmd",
FT_UINT8, BASE_HEX, VALS(EcCmdShort), 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cmd[8],
{ "Command", "ecat.sub9.cmd",
FT_UINT8, BASE_HEX, VALS(EcCmdShort), 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_cmd[9],
{ "Command", "ecat.sub10.cmd",
FT_UINT8, BASE_HEX, VALS(EcCmdShort), 0x0, NULL, HFILL }
},
{ &hf_ecat_idx,
{ "Index", "ecat.idx",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_idx[0],
{ "Index", "ecat.sub1.idx",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_idx[1],
{ "Index", "ecat.sub2.idx",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_idx[2],
{ "Index", "ecat.sub3.idx",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_idx[3],
{ "Index", "ecat.sub4.idx",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_idx[4],
{ "Index", "ecat.sub5.idx",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_idx[5],
{ "Index", "ecat.sub6.idx",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_idx[6],
{ "Index", "ecat.sub7.idx",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_idx[7],
{ "Index", "ecat.sub8.idx",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_idx[8],
{ "Index", "ecat.sub9.idx",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_idx[9],
{ "Index", "ecat.sub10.idx",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_adp,
{ "Slave Addr", "ecat.adp",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_adp[0],
{ "Slave Addr", "ecat.sub1.adp",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_adp[1],
{ "Slave Addr", "ecat.sub2.adp",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_adp[2],
{ "Slave Addr", "ecat.sub3.adp",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_adp[3],
{ "Slave Addr", "ecat.sub4.adp",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_adp[4],
{ "Slave Addr", "ecat.sub5.adp",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_adp[5],
{ "Slave Addr", "ecat.sub6.adp",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_adp[6],
{ "Slave Addr", "ecat.sub7.adp",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_adp[7],
{ "Slave Addr", "ecat.sub8.adp",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_adp[8],
{ "Slave Addr", "ecat.sub9.adp",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_adp[9],
{ "Slave Addr", "ecat.sub10.adp",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_ado,
{ "Offset Addr", "ecat.ado",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_ado[0],
{ "Offset Addr", "ecat.sub1.ado",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_ado[1],
{ "Offset Addr", "ecat.sub2.ado",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_ado[2],
{ "Offset Addr", "ecat.sub3.ado",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_ado[3],
{ "Offset Addr", "ecat.sub4.ado",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_ado[4],
{ "Offset Addr", "ecat.sub5.ado",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_ado[5],
{ "Offset Addr", "ecat.sub6.ado",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_ado[6],
{ "Offset Addr", "ecat.sub7.ado",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_ado[7],
{ "Offset Addr", "ecat.sub8.ado",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_ado[8],
{ "Offset Addr", "ecat.sub9.ado",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_ado[9],
{ "Offset Addr", "ecat.sub10.ado",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_lad,
{ "Log Addr", "ecat.lad",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_lad[0],
{ "Log Addr", "ecat.sub1.lad",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_lad[1],
{ "Log Addr", "ecat.sub2.lad",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_lad[2],
{ "Log Addr", "ecat.sub3.lad",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_lad[3],
{ "Log Addr", "ecat.sub4.lad",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_lad[4],
{ "Log Addr", "ecat.sub5.lad",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_lad[5],
{ "Log Addr", "ecat.sub6.lad",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_lad[6],
{ "Log Addr", "ecat.sub7.lad",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_lad[7],
{ "Log Addr", "ecat.sub8.lad",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_lad[8],
{ "Log Addr", "ecat.sub9.lad",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_lad[9],
{ "Log Addr", "ecat.sub10.lad",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_ecat_len,
{ "Length", "ecat.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_ecat_int,
{ "Interrupt", "ecat.int",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_syncman,
{ "SyncManager", "ecat.syncman",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_syncman_start,
{ "Start Addr", "ecat.syncman.start",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_syncman_len,
{ "SM Length", "ecat.syncman.len",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_syncman_flags,
{ "SM Flags", "ecat.syncman.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_syncman_flag0,
{ "SM Flag0", "ecat.syncman_flag0",
FT_BOOLEAN, 32, TFS(&tfs_ecat_syncman_flag0), 0x00000001,
NULL, HFILL }
},
{ &hf_ecat_syncman_flag1,
{ "SM Flag1", "ecat.syncman_flag1",
FT_BOOLEAN, 32, TFS(&tfs_ecat_syncman_flag1), 0x00000002,
NULL, HFILL }
},
{ &hf_ecat_syncman_flag2,
{ "SM Flag2", "ecat.syncman_flag2",
FT_BOOLEAN, 32, TFS(&tfs_ecat_syncman_flag2), 0x00000004,
NULL, HFILL }
},
{ &hf_ecat_syncman_flag4,
{ "SM Flag4", "ecat.syncman_flag4",
FT_BOOLEAN, 32, TFS(&tfs_ecat_syncman_flag4), 0x00000010,
NULL, HFILL }
},
{ &hf_ecat_syncman_flag5,
{ "SM Flag5", "ecat.syncman_flag5",
FT_BOOLEAN, 32, TFS(&tfs_ecat_syncman_flag5), 0x00000020,
NULL, HFILL }
},
{ &hf_ecat_syncman_flag8,
{ "SM Flag8", "ecat.syncman_flag8",
FT_BOOLEAN, 32, TFS(&tfs_ecat_syncman_flag8), 0x00000100,
NULL, HFILL }
},
{ &hf_ecat_syncman_flag9,
{ "SM Flag9", "ecat.syncman_flag9",
FT_BOOLEAN, 32, TFS(&tfs_ecat_syncman_flag9), 0x00000200,
NULL, HFILL }
},
{ &hf_ecat_syncman_flag10,
{ "SM Flag10", "ecat.syncman_flag10",
FT_BOOLEAN, 32, TFS(&tfs_ecat_syncman_flag10), 0x00000400,
NULL, HFILL }
},
{ &hf_ecat_syncman_flag11,
{ "SM Flag11", "ecat.syncman_flag11",
FT_BOOLEAN, 32, TFS(&tfs_ecat_syncman_flag11), 0x00000800,
NULL, HFILL }
},
{ &hf_ecat_syncman_flag12,
{ "SM Flag12", "ecat.syncman_flag12",
FT_BOOLEAN, 32, TFS(&tfs_ecat_syncman_flag12), 0x00001000,
NULL, HFILL }
},
{ &hf_ecat_syncman_flag13,
{ "SM Flag13", "ecat.syncman_flag13",
FT_BOOLEAN, 32, TFS(&tfs_ecat_syncman_flag13), 0x00002000,
NULL, HFILL }
},
{ &hf_ecat_syncman_flag16,
{ "SM Flag16", "ecat.syncman_flag16",
FT_BOOLEAN, 32, TFS(&tfs_ecat_syncman_flag16), 0x00010000,
NULL, HFILL }
},
{ &hf_ecat_fmmu,
{ "FMMU", "ecat.fmmu",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_fmmu_lstart,
{ "Log Start", "ecat.fmmu.lstart",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_fmmu_llen,
{ "Log Length", "ecat.fmmu.llen",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_fmmu_lstartbit,
{ "Log StartBit", "ecat.fmmu.lstartbit",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_fmmu_lendbit,
{ "Log EndBit", "ecat.fmmu.lendbit",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_fmmu_pstart,
{ "Phys Start", "ecat.fmmu.pstart",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_fmmu_pstartbit,
{ "Phys StartBit", "ecat.fmmu.pstartbit",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_fmmu_type,
{ "FMMU Type", "ecat.fmmu.type",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_fmmu_typeread,
{ "Type", "ecat.fmmu.typeread",
FT_BOOLEAN, 8, TFS(&tfs_ecat_fmmu_typeread), 0x01,
NULL, HFILL }
},
{ &hf_ecat_fmmu_typewrite,
{ "Type", "ecat.fmmu.typewrite",
FT_BOOLEAN, 8, TFS(&tfs_ecat_fmmu_typewrite), 0x02,
NULL, HFILL }
},
{ &hf_ecat_fmmu_active,
{ "FMMU Active", "ecat.fmmu.active",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_fmmu_active0,
{ "Active", "ecat.fmmu.active0",
FT_BOOLEAN, 8, TFS(&tfs_ecat_fmmu_active), 0x01,
NULL, HFILL }
},
{ &hf_ecat_dc_diff_da,
{ "DC D-A", "ecat.dc.dif.da",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_dc_diff_bd,
{ "DC B-D", "ecat.dc.dif.bd",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_dc_diff_cb,
{ "DC C-B", "ecat.dc.dif.cb",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_dc_diff_cd,
{ "DC C-D", "ecat.dc.dif.cd",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_dc_diff_ba,
{ "DC B-A", "ecat.dc.dif.ba",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_dc_diff_ca,
{ "DC C-A", "ecat.dc.dif.ca",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_da[0],
{ "DC D-A", "ecat.sub1.dc.dif.da",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_da[1],
{ "DC D-A", "ecat.sub2.dc.dif.da",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_da[2],
{ "DC D-A", "ecat.sub3.dc.dif.da",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_da[3],
{ "DC D-A", "ecat.sub4.dc.dif.da",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_da[4],
{ "DC D-A", "ecat.sub5.dc.dif.da",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_da[5],
{ "DC D-A", "ecat.sub6.dc.dif.da",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_da[6],
{ "DC D-A", "ecat.sub7.dc.dif.da",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_da[7],
{ "DC D-A", "ecat.sub8.dc.dif.da",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_da[8],
{ "DC D-A", "ecat.sub9.dc.dif.da",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_da[9],
{ "DC D-A", "ecat.sub10.dc.dif.da",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_bd[0],
{ "DC B-C", "ecat.sub1.dc.dif.bd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_bd[1],
{ "DC B-C", "ecat.sub2.dc.dif.bd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_bd[2],
{ "DC B-C", "ecat.sub3.dc.dif.bd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_bd[3],
{ "DC B-C", "ecat.sub4.dc.dif.bd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_bd[4],
{ "DC B-C", "ecat.sub5.dc.dif.bd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_bd[5],
{ "DC B-C", "ecat.sub6.dc.dif.bd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_bd[6],
{ "DC B-C", "ecat.sub7.dc.dif.bd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_bd[7],
{ "DC B-C", "ecat.sub8.dc.dif.bd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_bd[8],
{ "DC B-C", "ecat.sub9.dc.dif.bd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_bd[9],
{ "DC B-D", "ecat.sub10.dc.dif.bd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cb[0],
{ "DC C-B", "ecat.sub1.dc.dif.cb",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cb[1],
{ "DC C-B", "ecat.sub2.dc.dif.cb",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cb[2],
{ "DC C-B", "ecat.sub3.dc.dif.cb",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cb[3],
{ "DC C-B", "ecat.sub4.dc.dif.cb",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cb[4],
{ "DC C-B", "ecat.sub5.dc.dif.cb",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cb[5],
{ "DC C-B", "ecat.sub6.dc.dif.cb",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cb[6],
{ "DC C-B", "ecat.sub7.dc.dif.cb",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cb[7],
{ "DC C-B", "ecat.sub8.dc.dif.cb",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cb[8],
{ "DC C-B", "ecat.sub9.dc.dif.cb",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cb[9],
{ "DC C-B", "ecat.sub10.dc.dif.cb",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cd[0],
{ "DC C-D", "ecat.sub1.dc.dif.cd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cd[1],
{ "DC C-D", "ecat.sub2.dc.dif.cd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cd[2],
{ "DC C-D", "ecat.sub3.dc.dif.cd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cd[3],
{ "DC C-D", "ecat.sub4.dc.dif.cd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cd[4],
{ "DC C-D", "ecat.sub5.dc.dif.cd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cd[5],
{ "DC C-D", "ecat.sub6.dc.dif.cd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cd[6],
{ "DC C-D", "ecat.sub7.dc.dif.cd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cd[7],
{ "DC C-D", "ecat.sub8.dc.dif.cd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cd[8],
{ "DC C-D", "ecat.sub9.dc.dif.cd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_cd[9],
{ "DC C-D", "ecat.sub10.dc.dif.cd",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ba[0],
{ "DC B-A", "ecat.sub1.dc.dif.ba",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ba[1],
{ "DC B-A", "ecat.sub2.dc.dif.ba",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ba[2],
{ "DC B-A", "ecat.sub3.dc.dif.ba",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ba[3],
{ "DC B-A", "ecat.sub4.dc.dif.ba",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ba[4],
{ "DC B-A", "ecat.sub5.dc.dif.ba",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ba[5],
{ "DC B-A", "ecat.sub6.dc.dif.ba",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ba[6],
{ "DC B-A", "ecat.sub7.dc.dif.ba",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ba[7],
{ "DC B-A", "ecat.sub8.dc.dif.ba",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ba[8],
{ "DC B-A", "ecat.sub9.dc.dif.ba",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ba[9],
{ "DC B-A", "ecat.sub10.dc.dif.ba",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ca[0],
{ "DC C-A", "ecat.sub1.dc.dif.ca",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ca[1],
{ "DC C-A", "ecat.sub2.dc.dif.ca",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ca[2],
{ "DC C-A", "ecat.sub3.dc.dif.ca",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ca[3],
{ "DC C-A", "ecat.sub4.dc.dif.ca",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ca[4],
{ "DC C-A", "ecat.sub5.dc.dif.ca",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ca[5],
{ "DC C-A", "ecat.sub6.dc.dif.ca",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ca[6],
{ "DC C-A", "ecat.sub7.dc.dif.ca",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ca[7],
{ "DC C-A", "ecat.sub8.dc.dif.ca",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ca[8],
{ "DC C-A", "ecat.sub9.dc.dif.ca",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_sub_dc_diff_ca[9],
{ "DC C-A", "ecat.sub10.dc.dif.ca",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_ecat_length_len,
{ "Length", "ecat.subframe.length",
FT_UINT16, BASE_DEC, NULL, 0x07ff, NULL, HFILL}
},
{ &hf_ecat_length_r,
{ "Reserved", "ecat.subframe.reserved",
FT_UINT16, BASE_DEC, VALS(ecat_subframe_reserved_vals), 0x3800, NULL, HFILL}
},
{ &hf_ecat_length_c,
{ "Round trip", "ecat.subframe.circulating",
FT_UINT16, BASE_DEC, VALS(ecat_subframe_circulating_vals), 0x4000, NULL, HFILL}
},
{ &hf_ecat_length_m,
{ "Last indicator", "ecat.subframe.more",
FT_UINT16, BASE_DEC, VALS(ecat_subframe_more_vals), 0x8000, NULL, HFILL}
},
{ &hf_ecat_padding,
{ "Pad bytes", "ecat.subframe.pad_bytes",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
}
};
static gint *ett[] =
{
&ett_ecat,
&ett_ecat_header,
&ett_ecat_syncman,
&ett_ecat_syncflag,
&ett_ecat_fmmu,
&ett_ecat_fmmu_type,
&ett_ecat_fmmu_active,
&ett_ecat_dc,
&ett_ecat_length,
&ett_ecat_padding,
&ett_ecat_datagram_subtree
};
proto_ecat_datagram = proto_register_protocol("EtherCAT datagram(s)",
"ECAT", "ecat");
proto_register_field_array(proto_ecat_datagram, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_heur_dissector_list("ecat.data", &heur_subdissector_list);
}
void proto_reg_handoff_ecat(void)
{
dissector_handle_t ecat_handle;
ecat_handle = create_dissector_handle(dissect_ecat_datagram, proto_ecat_datagram);
dissector_add_uint("ecatf.type", 1 , ecat_handle);
ecat_mailbox_handle = find_dissector("ecat_mailbox");
}
