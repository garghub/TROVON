static void NetIdFormater(tvbuff_t *tvb, guint offset, char *szText, gint nMax)
{
g_snprintf ( szText, nMax, "%d.%d.%d.%d.%d.%d", tvb_get_guint8(tvb, offset),
tvb_get_guint8(tvb, offset+1),
tvb_get_guint8(tvb, offset+2),
tvb_get_guint8(tvb, offset+3),
tvb_get_guint8(tvb, offset+4),
tvb_get_guint8(tvb, offset+5)
);
}
static gint dissect_ams(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti, *anItem;
proto_tree *ams_tree = NULL, *ams_adstree, *ams_statetree;
gint offset = 0;
guint ams_length = tvb_reported_length(tvb);
guint16 stateflags = 0;
guint16 cmdId = 0;
guint32 cbdata = 0;
char szText[200];
int nMax = sizeof(szText)-1;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AMS");
col_clear(pinfo->cinfo, COL_INFO);
if( pinfo->ethertype != 0x88a4 )
{
if( TcpAdsParserHDR_Len > ams_length )
return offset;
ams_length -= TcpAdsParserHDR_Len;
offset = TcpAdsParserHDR_Len;
}
if( ams_length < AmsHead_Len )
return offset;
if (tree)
{
ti = proto_tree_add_item(tree, proto_ams, tvb, 0, -1, ENC_NA);
ams_tree = proto_item_add_subtree(ti, ett_ams);
NetIdFormater(tvb, offset, szText, nMax);
proto_tree_add_string(ams_tree, hf_ams_targetnetid, tvb, offset, AmsNetId_Len, szText);
offset += AmsNetId_Len;
proto_tree_add_item(ams_tree, hf_ams_targetport, tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
offset += sizeof(guint16);
NetIdFormater(tvb, offset, szText, nMax);
proto_tree_add_string(ams_tree, hf_ams_sendernetid, tvb, offset, AmsNetId_Len, szText);
offset += AmsNetId_Len;
proto_tree_add_item(ams_tree, hf_ams_senderport, tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
offset += sizeof(guint16);
proto_tree_add_item(ams_tree, hf_ams_cmdid, tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
cmdId = tvb_get_letohs(tvb, offset);
offset+=sizeof(guint16);
anItem = proto_tree_add_item(ams_tree, hf_ams_stateflags, tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
ams_statetree = proto_item_add_subtree(anItem, ett_ams_stateflags);
proto_tree_add_item(ams_statetree, hf_ams_stateresponse,tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
proto_tree_add_item(ams_statetree, hf_ams_statenoreturn,tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
proto_tree_add_item(ams_statetree, hf_ams_stateadscmd,tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
proto_tree_add_item(ams_statetree, hf_ams_statesyscmd,tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
proto_tree_add_item(ams_statetree, hf_ams_statehighprio,tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
proto_tree_add_item(ams_statetree, hf_ams_statetimestampadded,tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
proto_tree_add_item(ams_statetree, hf_ams_stateudp,tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
proto_tree_add_item(ams_statetree, hf_ams_stateinitcmd,tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
proto_tree_add_item(ams_statetree, hf_ams_statebroadcast,tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
stateflags = tvb_get_letohs(tvb, offset);
offset+=sizeof(guint16);
proto_tree_add_item(ams_tree, hf_ams_cbdata, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
cbdata = tvb_get_letohl(tvb,offset);
offset+=sizeof(guint32);
proto_tree_add_item(ams_tree, hf_ams_errorcode, tvb, offset, sizeof(guint32),ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_tree, hf_ams_invokeid, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
}
else
{
offset+=AmsHead_Len;
}
if ( (stateflags & AMSCMDSF_ADSCMD) != 0 )
{
if ( (stateflags & AMSCMDSF_RESPONSE) == 0 )
{
switch ( cmdId )
{
case ADSSRVID_READ:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Read Request");
if( tree )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adsreadrequest, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsReadReq_Len )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adsreadrequest);
proto_tree_add_item(ams_adstree, hf_ams_adsindexgroup, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adsindexoffset, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adscblength, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
}
}
}
break;
case ADSSRVID_WRITE:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Write Request");
if( tree )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adswriterequest, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsWriteReq_Len - sizeof(guint16) )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adswriterequest);
proto_tree_add_item(ams_adstree, hf_ams_adsindexgroup, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adsindexoffset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adscblength, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adsdata, tvb, offset, ams_length-offset, ENC_NA);
}
}
}
break;
case ADSSRVID_READWRITE:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Read Write Request");
if( tree )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adsreadwriterequest, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsReadWriteReq_Len - sizeof(guint16))
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adsreadwriterequest);
proto_tree_add_item(ams_adstree, hf_ams_adsindexgroup, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adsindexoffset, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adscbreadlength, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adscbwritelength, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adsdata, tvb, offset+16, ams_length-offset, ENC_NA);
}
}
}
break;
case ADSSRVID_READSTATE:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Read State Request");
if( tree && cbdata !=0 )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adsreadstaterequest, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsReadStateReq_Len )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adsreadstaterequest);
proto_tree_add_item(ams_adstree, hf_ams_adsinvokeid, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
}
}
}
break;
case ADSSRVID_WRITECTRL:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Write Control Request");
if( tree )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adswritectrlrequest, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsWriteControlReq_Len - sizeof(guint16) )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adswritectrlrequest);
proto_tree_add_item(ams_adstree, hf_ams_adsstate, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=sizeof(guint16);
proto_tree_add_item(ams_adstree, hf_ams_adsdevicestate, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=sizeof(guint16);
proto_tree_add_item(ams_adstree, hf_ams_adscblength, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adsdata, tvb, offset, ams_length-offset, ENC_NA);
}
}
}
break;
case ADSSRVID_READDEVICEINFO:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Read Device Info Request");
if( tree && cbdata !=0 )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adsreaddinforequest, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsReadDeviceInfoReq_Len )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adsreaddinforequest);
proto_tree_add_item(ams_adstree, hf_ams_adsresult, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
}
}
}
break;
case ADSSRVID_ADDDEVICENOTE:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Add Device Notification Request");
if( tree )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adsadddnrequest, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsAddDeviceNotificationReq_Len )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adsadddnrequest);
proto_tree_add_item(ams_adstree, hf_ams_adsindexgroup, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adsindexoffset, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adscblength, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adstransmode, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adsmaxdelay, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adscycletime, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
}
}
}
break;
case ADSSRVID_DELDEVICENOTE:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Delete Device Notification Request");
if( tree )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adsdeldnrequest, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsDelDeviceNotificationReq_Len )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adsdeldnrequest);
proto_tree_add_item(ams_adstree, hf_ams_adsnotificationhandle, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
}
}
}
break;
case ADSSRVID_DEVICENOTE:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Device Notification Request");
if( tree )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adsdnrequest, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsDeviceNotificationReq_Len )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adsdnrequest);
proto_tree_add_item(ams_adstree, hf_ams_adscblength, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adsnoteblocksstamps, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
}
}
}
break;
}
}
else
{
switch ( cmdId )
{
case ADSSRVID_READ:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Read Response");
if( tree )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adsreadresponse, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsReadRes_Len - sizeof(guint16) )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adsreadresponse);
proto_tree_add_item(ams_adstree, hf_ams_adsresult, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adscblength, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adsdata, tvb, offset, ams_length-offset, ENC_NA);
}
}
}
break;
case ADSSRVID_WRITE:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Write Response");
if( tree )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adswriteresponse, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsWriteRes_Len )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adswriteresponse);
proto_tree_add_item(ams_adstree, hf_ams_adsresult, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
}
}
}
break;
case ADSSRVID_READWRITE:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Read Write Response");
if( tree )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adsreadwriteresponse, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsReadWriteRes_Len - sizeof(guint16) )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adsreadwriteresponse);
proto_tree_add_item(ams_adstree, hf_ams_adsresult, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adscblength, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adsdata, tvb, offset, ams_length-offset, ENC_NA);
}
}
}
break;
case ADSSRVID_READSTATE:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Read State Response");
if( tree )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adsreadstateresponse, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsReadStateRes_Len )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adsreadstateresponse);
proto_tree_add_item(ams_adstree, hf_ams_adsresult, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adsstate, tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adsdevicestate, tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
}
}
}
break;
case ADSSRVID_WRITECTRL:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Write Control Response");
if( tree )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adswritectrlresponse, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsWriteControlRes_Len )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adswritectrlresponse);
proto_tree_add_item(ams_adstree, hf_ams_adsresult, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
}
}
}
break;
case ADSSRVID_READDEVICEINFO:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Read Device Info Response");
if( tree )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adsreaddinforesponse, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsReadDeviceInfoRes_Len )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adsreaddinforesponse);
proto_tree_add_item(ams_adstree, hf_ams_adsresult, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adsversionversion, tvb, offset++, sizeof(guint8), ENC_LITTLE_ENDIAN);
proto_tree_add_item(ams_adstree, hf_ams_adsversionrevision, tvb, offset++, sizeof(guint8), ENC_LITTLE_ENDIAN);
proto_tree_add_item(ams_adstree, hf_ams_adsversionbuild, tvb, offset, sizeof(guint16), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint16);
proto_tree_add_item(ams_adstree, hf_ams_adsdevicename, tvb, offset, ams_length-offset, ENC_ASCII|ENC_NA);
}
}
}
break;
case ADSSRVID_ADDDEVICENOTE:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Device Notification Response");
if( tree )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adsadddnresponse, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsAddDeviceNotificationRes_Len )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adsadddnresponse);
proto_tree_add_item(ams_adstree, hf_ams_adsresult, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
offset+=sizeof(guint32);
proto_tree_add_item(ams_adstree, hf_ams_adsnotificationhandle, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
}
}
}
break;
case ADSSRVID_DELDEVICENOTE:
{
col_append_str(pinfo->cinfo, COL_INFO, "ADS Delete Device Notification Response");
if( tree )
{
anItem = proto_tree_add_item(ams_tree, hf_ams_adsdeldnresponse, tvb, offset, ams_length-offset, ENC_NA);
if( ams_length-offset >= TAdsDelDeviceNotificationRes_Len )
{
ams_adstree = proto_item_add_subtree(anItem, ett_ams_adsdeldnresponse);
proto_tree_add_item(ams_adstree, hf_ams_adsresult, tvb, offset, sizeof(guint32), ENC_LITTLE_ENDIAN);
}
}
}
break;
}
}
}
else
{
if ( (stateflags & AMSCMDSF_RESPONSE) == 0 )
col_append_str(pinfo->cinfo, COL_INFO, "AMS Request");
else
col_append_str(pinfo->cinfo, COL_INFO, "AMS Response");
if( tree && ams_length-offset > 0 )
proto_tree_add_item(ams_tree, hf_ams_data, tvb, offset, ams_length-offset, ENC_NA);
}
return offset;
}
void proto_register_ams(void)
{
static const true_false_string flags_set_truth =
{
"Set",
"Not set"
};
static hf_register_info hf[] =
{
{ &hf_ams_sendernetid,
{ "AMS Sender Net Id", "ams.sendernetid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_senderport,
{ "AMS Sender port", "ams.senderport",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_targetnetid,
{ "AMS Target Net Id", "ams.targetnetid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_targetport,
{ "AMS Target port", "ams.targetport",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_cmdid,
{ "CmdId", "ams.cmdid",
FT_UINT16, BASE_DEC, VALS(AMS_CommandId_vals), 0x0,
NULL, HFILL }
},
{ &hf_ams_stateflags,
{ "StateFlags", "ams.stateflags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_stateresponse,
{ "RESPONSE", "ams.state_response",
FT_BOOLEAN, 16, TFS(&flags_set_truth), AMSCMDSF_RESPONSE,
NULL, HFILL }
},
{ &hf_ams_statenoreturn,
{ "NO RETURN", "ams.state_noreturn",
FT_BOOLEAN, 16, TFS(&flags_set_truth), AMSCMDSF_NORETURN,
NULL, HFILL }
},
{ &hf_ams_stateadscmd,
{ "ADS COMMAND", "ams.state_adscmd",
FT_BOOLEAN, 16, TFS(&flags_set_truth), AMSCMDSF_ADSCMD,
NULL, HFILL }
},
{ &hf_ams_statesyscmd,
{ "SYSTEM COMMAND", "ams.state_syscmd",
FT_BOOLEAN, 16, TFS(&flags_set_truth), AMSCMDSF_SYSCMD,
NULL, HFILL }
},
{ &hf_ams_statehighprio,
{ "HIGH PRIORITY COMMAND", "ams.state_highprio",
FT_BOOLEAN, 16, TFS(&flags_set_truth), AMSCMDSF_HIGHPRIO,
NULL, HFILL }
},
{ &hf_ams_statetimestampadded,
{ "TIMESTAMP ADDED", "ams.state_timestampadded",
FT_BOOLEAN, 16, TFS(&flags_set_truth), AMSCMDSF_TIMESTAMPADDED,
NULL, HFILL }
},
{ &hf_ams_stateudp,
{ "UDP COMMAND", "ams.state_udp",
FT_BOOLEAN, 16, TFS(&flags_set_truth), AMSCMDSF_UDP,
NULL, HFILL }
},
{ &hf_ams_stateinitcmd,
{ "INIT COMMAND", "ams.state_initcmd",
FT_BOOLEAN, 16, TFS(&flags_set_truth), AMSCMDSF_INITCMD,
NULL, HFILL }
},
{ &hf_ams_statebroadcast,
{ "BROADCAST", "ams.state_broadcast",
FT_BOOLEAN, 16, TFS(&flags_set_truth), AMSCMDSF_BROADCAST,
NULL, HFILL }
},
{ &hf_ams_cbdata,
{ "cbData", "ams.cbdata",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_errorcode,
{ "ErrorCode", "ams.errorcode",
FT_UINT32, BASE_HEX, VALS(ErrorCode), 0x0,
NULL, HFILL }
},
{ &hf_ams_invokeid,
{ "InvokeId", "ams.invokeid",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsdata,
{ "Data", "ams.ads_data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_data,
{ "Data", "ams.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsindexgroup,
{ "IndexGroup", "ams.ads_indexgroup",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsindexoffset,
{ "IndexOffset", "ams.ads_indexoffset",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adscblength,
{ "CbLength", "ams.ads_cblength",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsreadrequest,
{ "ADS Read Request", "ams.ads_read_req",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsreadresponse,
{ "ADS Read Response", "ams.ads_read_res",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsinvokeid,
{ "InvokeId", "ams.ads_invokeid",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsresult,
{ "Result", "ams.adsresult",
FT_UINT32, BASE_HEX, VALS(AdsErrorMode), 0x0,
NULL, HFILL }
},
{ &hf_ams_adswriterequest,
{ "ADS Write Request", "ams.ads_write_req",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adswriteresponse,
{ "ADS Write Response", "ams.ads_write_res",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsreadwriterequest,
{ "ADS ReadWrite Request", "ams.ads_readwrite_req",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsreadwriteresponse,
{ "ADS ReadWrite Response", "ams.ads_readwrite_res",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adscbreadlength,
{ "CBReadLength", "ams.ads_cbreadlength",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adscbwritelength,
{ "CBWriteLength", "ams.ads_cbwritelength",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsstate,
{ "AdsState", "ams.ads_state",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsdevicestate,
{ "DeviceState", "ams.ads_devicestate",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsnotificationhandle,
{ "NotificationHandle", "ams.ads_notificationhandle",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsreadstaterequest,
{ "ADS Read State Request", "ams.ads_readstate_req",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsreadstateresponse,
{ "ADS Read State Response", "ams.ads_readstate_res",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adswritectrlrequest,
{ "ADS Write Ctrl Request", "ams.ads_writectrl_req",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adswritectrlresponse,
{ "ADS Write Ctrl Response", "ams.ads_writectrl_res",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsreaddinforequest,
{ "ADS Read Device Info Request", "ams.ads_readdinfo_req",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsreaddinforesponse,
{ "ADS Read Device Info Response", "ams.ads_readdinfo_res",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsadddnrequest,
{ "ADS Add Device Notification Request", "ams.ads_adddn_req",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsadddnresponse,
{ "ADS Add Device Notification Response", "ams.ads_adddn_res",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsdeldnrequest,
{ "ADS Delete Device Notification Request", "ams.ads_deldn_req",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsdeldnresponse,
{ "ADS Delete Device Notification Response", "ams.ads_deldn_res",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsdnrequest,
{ "ADS Device Notification Request", "ams.ads_dn_req",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsdnresponse,
{ "ADS Device Notification Response", "ams.ads_dn_res",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsnoteattrib,
{ "InvokeId", "ams.ads_noteattrib",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsnoteblocks,
{ "InvokeId", "ams.ads_noteblocks",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsversion,
{ "ADS Version", "ams.ads_version",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsdevicename,
{ "Device Name","ams.ads_devicename",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsversionversion,
{ "ADS Major Version", "ams.ads_versionversion",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsversionrevision,
{ "ADS Minor Version", "ams.ads_versionrevision",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsversionbuild,
{ "ADS Version Build", "ams.ads_versionbuild",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsnoteblocksstamps,
{ "Count of Stamps", "ams.ads_noteblocksstamps",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsnoteblocksstamp,
{ "Notification Stamp", "ams.ads_noteblocksstamp",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adstimestamp,
{ "Time Stamp", "ams.ads_timestamp",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adssamplecnt,
{ "Count of Stamps", "ams.ads_samplecnt",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adsnoteblockssample,
{ "Notification Sample", "ams.ads_noteblockssample",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adstransmode,
{ "Trans Mode", "ams.ads_transmode",
FT_UINT32, BASE_DEC, VALS(TransMode), 0x0,
NULL, HFILL }
},
{ &hf_ams_adsmaxdelay,
{ "Max Delay", "ams.ads_maxdelay",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adscycletime,
{ "Cycle Time", "ams.ads_cycletime",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adscmpmax,
{ "Cmp Mad", "ams.ads_cmpmax",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ams_adscmpmin,
{ "Cmp Min", "ams.ads_cmpmin",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] =
{
&ett_ams,
&ett_ams_stateflags,
&ett_ams_adsreadrequest,
&ett_ams_adsreadresponse,
&ett_ams_adswriterequest,
&ett_ams_adswriteresponse,
&ett_ams_adsreadwriterequest,
&ett_ams_adsreadwriteresponse,
&ett_ams_adsreadstaterequest,
&ett_ams_adsreadstateresponse,
&ett_ams_adswritectrlrequest,
&ett_ams_adswritectrlresponse,
&ett_ams_adsreaddinforequest,
&ett_ams_adsreaddinforesponse,
&ett_ams_adsadddnrequest,
&ett_ams_adsadddnresponse,
&ett_ams_adsdeldnrequest,
&ett_ams_adsdeldnresponse,
&ett_ams_adsdnrequest
};
proto_ams = proto_register_protocol("AMS", "AMS", "ams");
proto_register_field_array(proto_ams, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("ams", dissect_ams, proto_ams);
}
void proto_reg_handoff_ams(void)
{
dissector_handle_t ams_handle;
ams_handle = find_dissector("ams");
dissector_add_uint("tcp.port", 0xbf02, ams_handle);
dissector_add_uint("ecatf.type", 2, ams_handle);
}
