static void dissect_wreth(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint16 packet_type,functionCode;
guint8 fragmented;
proto_item *mi, *ti;
proto_tree *pWrethTree ;
guint8 Offset = 0 ;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Wreth");
col_clear(pinfo->cinfo,COL_INFO);
packet_type = tvb_get_ntohs(tvb,0);
if(packet_type != WSE_RETH_SUBTYPE) return;
mi = proto_tree_add_protocol_format(tree, wreth_proto, tvb, Offset, -1, "WSE remote ethernet");
pWrethTree = proto_item_add_subtree(mi, ett_wreth);
functionCode = tvb_get_letohs(tvb,4);
fragmented = tvb_get_guint8(tvb,10);
if(fragmented > 2)
{
col_set_str(pinfo->cinfo, COL_INFO, "Invalid fragmented byte");
return;
}
if (tree)
{
proto_tree_add_item(pWrethTree, hf_Wreth_Subtype, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(pWrethTree, hf_Wreth_Size, tvb, Offset + 2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(pWrethTree, hf_Wreth_FunctionCode, tvb, Offset + 4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(pWrethTree, hf_Wreth_FrameId, tvb, Offset + 6, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(pWrethTree, hf_Wreth_ErrorCode, tvb, Offset + 8, 2, ENC_LITTLE_ENDIAN);
}
if(fragmented == 2)
{
ti = proto_tree_add_item(pWrethTree, hf_Wreth_Fragmented, tvb, Offset + 10, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, ": second fragment");
proto_tree_add_item(pWrethTree, hf_Wreth_Retry, tvb, Offset + 11, 1, ENC_LITTLE_ENDIAN);
WrethMailDissection(tvb, Offset + 12, pinfo, pWrethTree, fragmented);
return;
}
ti = proto_tree_add_item(pWrethTree, hf_Wreth_Fragmented, tvb, Offset + 10, 1, ENC_LITTLE_ENDIAN);
if(fragmented == 1)
{
proto_item_append_text(ti, ": first fragment");
}else
proto_item_append_text(ti, ": no");
proto_tree_add_item(pWrethTree, hf_Wreth_Retry, tvb, Offset + 11, 1, ENC_LITTLE_ENDIAN);
switch(functionCode)
{
case WRETH_IDENT:
WrethIdentPacket(tvb, Offset + 12, pinfo, pWrethTree);
break;
case WRETH_CONNECT:
WrethConnectPacket(tvb, Offset + 12, pinfo, pWrethTree);
break;
case WRETH_ACK:
WrethAckPacket(tvb, Offset + 12, pinfo, pWrethTree);
break;
case WRETH_NACK:
WrethNackPacket(tvb, Offset + 12, pinfo, pWrethTree);
break;
case WRETH_DISCONNECT:
WrethDisconnectPacket(tvb, Offset + 12, pinfo, pWrethTree);
break;
case WRETH_MAIL:
WrethMailPacket(tvb, Offset + 12, pinfo, pWrethTree);
break;
case WRETH_BLINKY:
WrethBlinkyPacket(tvb, Offset + 12, pinfo, pWrethTree);
break;
case WRETH_GET_VALUE:
WrethGetValuePacket(tvb, Offset + 12, pinfo, pWrethTree);
break;
case WRETH_SET_VALUE:
WrethSetValuePacket(tvb, Offset + 12, pinfo, pWrethTree);
break;
case WRETH_BOOST:
WrethBoostPacket(tvb, Offset + 12, pinfo, pWrethTree);
break;
default:
break;
}
}
gint WrethIdentPacket(tvbuff_t *tvb, guint8 Offset, packet_info * pInfo, proto_tree * pWrethTree)
{
guint16 Size;
Size = tvb_get_letohs(tvb, 2);
if((Size != 0)&&(Size != 19))
{
col_set_str(pInfo->cinfo, COL_INFO, "Invalid identification frame");
return 0;
}
if(Size == 0)
{
col_set_str(pInfo->cinfo, COL_INFO, "Identification question");
return 0;
}
proto_tree_add_item(pWrethTree, hf_Wreth_IdentificationBiosVersion, tvb, Offset, 6, ENC_ASCII|ENC_NA);
proto_tree_add_item(pWrethTree, hf_Wreth_IdentificationBoardNumber, tvb, Offset + 6, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(pWrethTree, hf_Wreth_IdentificationProtocolVersion, tvb, Offset + 8, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(pWrethTree, hf_Wreth_IdentificationBoardId, tvb, Offset + 10, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(pWrethTree, hf_Wreth_IdentificationState, tvb, Offset + 12, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(pWrethTree, hf_Wreth_IdentificationMacAddr, tvb, Offset + 13, 6, ENC_BIG_ENDIAN);
col_set_str(pInfo->cinfo, COL_INFO, "Identification response");
return Offset;
}
gint WrethConnectPacket(tvbuff_t *tvb, guint8 Offset, packet_info * pInfo, proto_tree * pWrethTree _U_)
{
guint16 Size;
Size = tvb_get_letohs(tvb,2);
if(Size != 4)
{
col_set_str(pInfo->cinfo, COL_INFO, "Invalid connection frame");
return 0;
}
col_set_str(pInfo->cinfo, COL_INFO, "Connection");
proto_tree_add_item(pWrethTree, hf_Wreth_ConnectProtocolVersion, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(pWrethTree, hf_Wreth_ConnectTimeout, tvb, Offset + 2, 2, ENC_LITTLE_ENDIAN);
return Offset;
}
gint WrethDisconnectPacket(tvbuff_t *tvb, guint8 Offset, packet_info * pInfo, proto_tree * pWrethTree _U_)
{
guint16 Size;
Size = tvb_get_letohs(tvb,2);
if(Size != 0)
{
col_set_str(pInfo->cinfo, COL_INFO, "Invalid disconnection frame");
return 0;
}
col_set_str(pInfo->cinfo, COL_INFO, "Disconnection");
return Offset;
}
gint WrethBlinkyPacket(tvbuff_t *tvb, guint8 Offset, packet_info * pInfo, proto_tree * pWrethTree)
{
guint16 Size;
Size = tvb_get_letohs(tvb,2);
if(Size != 2)
{
col_set_str(pInfo->cinfo, COL_INFO, "Invalid blinky frame");
return 0;
}
col_set_str(pInfo->cinfo, COL_INFO, "Blinky");
proto_tree_add_item(pWrethTree, hf_Wreth_BlinkyPeriod, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
return Offset;
}
gint WrethGetValuePacket(tvbuff_t *tvb, guint8 Offset, packet_info * pInfo, proto_tree * pWrethTree)
{
guint16 Size;
Size = tvb_get_letohs(tvb,2);
switch(Size)
{
case 0:
col_set_str(pInfo->cinfo, COL_INFO, "Get value question");
break;
case 1:
proto_tree_add_item(pWrethTree, hf_Wreth_GetValueVal, tvb, Offset, 1, ENC_LITTLE_ENDIAN);
col_set_str(pInfo->cinfo, COL_INFO, "Get value response");
break;
default:
col_set_str(pInfo->cinfo, COL_INFO, "Invalid get value frame");
break;
}
return Offset;
}
gint WrethSetValuePacket(tvbuff_t *tvb, guint8 Offset, packet_info * pInfo, proto_tree * pWrethTree)
{
guint16 Size;
Size = tvb_get_letohs(tvb,2);
if(Size != 0)
{
col_set_str(pInfo->cinfo, COL_INFO, "Invalid set value frame");
}
proto_tree_add_item(pWrethTree, hf_Wreth_SetValueVal, tvb, Offset, 1, ENC_LITTLE_ENDIAN);
col_set_str(pInfo->cinfo, COL_INFO, "Set value question");
return Offset;
}
gint WrethBoostPacket(tvbuff_t *tvb, guint8 Offset, packet_info * pInfo, proto_tree * pWrethTree)
{
guint16 Size;
Size = tvb_get_letohs(tvb,2);
if(Size != 2)
{
col_set_str(pInfo->cinfo, COL_INFO, "Invalid boost frame");
return 0;
}
col_set_str(pInfo->cinfo, COL_INFO, "Boost");
proto_tree_add_item(pWrethTree, hf_Wreth_BoostValue, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
return Offset;
}
gint WrethAckPacket(tvbuff_t *tvb, guint8 Offset, packet_info * pInfo, proto_tree * pWrethTree _U_)
{
guint16 Size;
Size = tvb_get_letohs(tvb,2);
if(Size != 0)
{
col_set_str(pInfo->cinfo, COL_INFO, "Invalid acknowledge frame");
return 0;
}
col_set_str(pInfo->cinfo, COL_INFO, "Acknowledge");
return Offset;
}
gint WrethNackPacket(tvbuff_t *tvb, guint8 Offset, packet_info * pInfo, proto_tree * pWrethTree)
{
guint16 Size;
guint16 ErrorCode;
Size = tvb_get_letohs(tvb,2);
ErrorCode = tvb_get_letohs(tvb,2);
if((Size != 0)&&(Size != 6))
{
col_set_str(pInfo->cinfo, COL_INFO, "Invalid non acknowledge frame");
return 0;
}
col_add_str(pInfo->cinfo, COL_INFO, val_to_str_ext(ErrorCode, &ErrorCode_vals_ext, "Unknown 0x%04x"));
if(Size == 6)
{
proto_tree_add_item(pWrethTree, hf_Wreth_IdentificationMacAddr, tvb, Offset, 6, ENC_BIG_ENDIAN);
}
return Offset;
}
gint WrethMailPacket(tvbuff_t *tvb, guint8 Offset, packet_info * pInfo, proto_tree * pWrethTree)
{
proto_tree_add_item(pWrethTree, hf_Wreth_MailDestTic, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(pWrethTree, hf_Wreth_MailReserved, tvb, Offset + 2, 4, ENC_LITTLE_ENDIAN);
col_set_str(pInfo->cinfo, COL_INFO, "Mail");
WrethMailDissection(tvb, Offset+6, pInfo, pWrethTree,0);
return Offset;
}
gint WrethMailDissection(tvbuff_t *tvb, guint8 Offset, packet_info * pInfo, proto_tree * pWrethTree, guint8 fragmented)
{
proto_item *mi;
proto_tree *pWrethMailboxTree;
gint Nb = 0;
guint16 Codef = 0;
mi = proto_tree_add_protocol_format(pWrethTree, wreth_proto, tvb, Offset, -1, "MailBox");
pWrethMailboxTree = proto_item_add_subtree(mi, ett_wreth);
if (2 != fragmented)
{
guint16 Card, Chan;
gint Status;
Codef = tvb_get_letohs(tvb,Offset);
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_Codef, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
Status = (gint16)tvb_get_letohs(tvb,Offset);
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_Status, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_TicUser_Root, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_PidUser, tvb, Offset, 4, ENC_LITTLE_ENDIAN);
Offset += 4;
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_Mode, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_Time, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_Stop, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_Nfonc, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
Card = tvb_get_letohs(tvb,Offset);
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_Ncard, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
Chan = tvb_get_letohs(tvb,Offset);
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_Nchan, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_Nes, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
Nb = (gint)tvb_get_letohs(tvb,Offset);
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_Nb, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_TypVar, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_Adr, tvb, Offset, 4, ENC_LITTLE_ENDIAN);
Offset += 4;
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_TicUser_DispCyc, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_Nb_Max_Size_Mail, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_User_ThreadID, tvb, Offset, 4, ENC_LITTLE_ENDIAN);
Offset += 4;
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_DispCyc_Version, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_DifUserParam, tvb, Offset, 4, ENC_LITTLE_ENDIAN);
Offset += 4;
proto_tree_add_item(pWrethMailboxTree, hf_Wreth_Mail_Filler, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
col_add_fstr(pInfo->cinfo, COL_INFO, "Mail : Codef = Ox%X (%s), Status = %02d (%s), Card = %d, Chan = %d" ,
Codef,
val_to_str_ext(Codef, &tabCodef_ext, "Unknown 0x%04x%"),
Status,
val_to_str_ext(Status, &tabStatus_ext, "Unknown %d"),
Card,
Chan);
}
else
{
col_set_str(pInfo->cinfo, COL_INFO, "Mail : Data Second Fragment ");
}
if (0 != Nb)
{
switch(Codef)
{
case 0x1002:
WrethCodefMasterInfoDissection(tvb, Offset, pInfo, pWrethMailboxTree);
break;
case 0x1079:
WrethCodefEquipmentInfoDissection(tvb, Offset, pInfo, pWrethMailboxTree);
break;
default:
proto_tree_add_protocol_format(pWrethMailboxTree, wreth_proto, tvb, Offset, -1, "Data");
break;
}
}
return Offset;
}
gint WrethCodefMasterInfoDissection(tvbuff_t *tvb, guint8 Offset, packet_info * pInfo _U_, proto_tree * pWrethMailboxTree)
{
proto_item *mi;
proto_tree *pWrethMailboxDataTree;
mi = proto_tree_add_protocol_format(pWrethMailboxTree, wreth_proto, tvb, Offset, -1, "Data");
pWrethMailboxDataTree = proto_item_add_subtree(mi, ett_wreth);
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Mastinf_Version, tvb, Offset, 1, ENC_LITTLE_ENDIAN);
Offset += 1;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Mastinf_Release, tvb, Offset, 1, ENC_LITTLE_ENDIAN);
Offset += 1;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Mastinf_Protocol, tvb, Offset, 1, ENC_LITTLE_ENDIAN);
Offset += 1;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Mastinf_CyclicFlux, tvb, Offset, 1, ENC_LITTLE_ENDIAN);
Offset += 1;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Mastinf_szProtocolName, tvb, Offset, 16, ENC_ASCII|ENC_NA);
Offset += 16;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Mastinf_MaxTypeEquipment, tvb, Offset, 1, ENC_LITTLE_ENDIAN);
Offset += 1;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Mastinf_MinEquipmentNumber, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Mastinf_MaxEquipmentNumber, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
return Offset;
}
gint WrethCodefEquipmentInfoDissection(tvbuff_t *tvb, guint8 Offset, packet_info * pInfo _U_, proto_tree * pWrethMailboxTree)
{
proto_item *mi;
proto_tree *pWrethMailboxDataTree;
mi = proto_tree_add_protocol_format(pWrethMailboxTree, wreth_proto, tvb, Offset, -1, "Data");
pWrethMailboxDataTree = proto_item_add_subtree(mi, ett_wreth);
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_Version, tvb, Offset, 1, ENC_LITTLE_ENDIAN);
Offset += 1;
Offset += 1;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_Release, tvb, Offset, 1, ENC_LITTLE_ENDIAN);
Offset += 1;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_Network, tvb, Offset, 1, ENC_LITTLE_ENDIAN);
Offset += 1;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_Protocol, tvb, Offset, 1, ENC_LITTLE_ENDIAN);
Offset += 1;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_Messaging, tvb, Offset, 1, ENC_LITTLE_ENDIAN);
Offset += 1;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_Equipment, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_Flux, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
Offset += 10;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_IncWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_IncDWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_IncFWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
Offset += 4;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Mastinf_DllItemName, tvb, Offset, 14, ENC_ASCII|ENC_NA);
Offset += 14;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Mastinf_szEquipmentName, tvb, Offset, 16, ENC_ASCII|ENC_NA);
Offset += 16;
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxWriteBit, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxReadBit, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_BreakBit, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxWriteIBit, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxReadIBit, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_BreakIBit, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxWriteQBit, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxReadQBit, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_BreakQBit, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxWriteByte, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxReadByte, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_BreakByte, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxWriteIByte, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxReadIByte, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_BreakIByte, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxWriteQByte, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxReadQByte, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_BreakQByte, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxWriteWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxReadWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_BreakWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxWriteIWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxReadIWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_BreakIWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxWriteQWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxReadQWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_BreakQWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxWriteDWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxReadDWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_BreakDWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxWriteFWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_MaxReadFWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_BreakFWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_ReadFactorWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_ReadFactorIWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_ReadFactorQWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_ReadFactorDWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_ReadFactorFWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_WriteFactorWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_WriteFactorIWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_WriteFactorQWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_WriteFactorDWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_WriteFactorFWord, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
proto_tree_add_item(pWrethMailboxDataTree, hf_Wreth_Mail_Equinf_DataFormat, tvb, Offset, 2, ENC_LITTLE_ENDIAN);
Offset += 2;
return Offset;
}
void proto_register_wreth(void)
{
static hf_register_info hf[] =
{
{ &hf_Wreth_Subtype,
{ "Subtype", "wreth.Subtype",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Size,
{ "Size", "wreth.Size",
FT_UINT16, BASE_DEC, NULL, 0x0,
"", HFILL }
},
{ &hf_Wreth_FunctionCode,
{ "Function code","wreth.FunctionCode",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &FunctionCodes_ext, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_FrameId,
{ "FrameId", "wreth.FrameId",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_ErrorCode,
{ "Error code", "wreth.ErrorCode",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &ErrorCode_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Fragmented,
{ "Fragmented", "wreth.Fragmented",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Retry,
{ "Retry", "wreth.Retry",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_IdentificationBiosVersion,
{ "Bios version", "wreth.IdentBiosVersion",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_IdentificationBoardNumber,
{ "Board number", "wreth.IdentBoardNumber",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_IdentificationProtocolVersion,
{ "Protocol version", "wreth.IdentProtocolVersion",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_IdentificationBoardId,
{ "Board Id", "wreth.IdentBoardId",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_IdentificationState,
{ "State", "wreth.IdentState",
FT_UINT8, BASE_DEC, VALS(IdentState), 0x0,
NULL, HFILL }
},
{ &hf_Wreth_IdentificationMacAddr,
{ "Client MAC address :", "wreth.IdentClientMacAddr",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_ConnectProtocolVersion,
{ "Protocol version", "wreth.ConnectProtocolVersion",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_ConnectTimeout,
{ "Connect timeout", "wreth.ConnectTimeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_BlinkyPeriod,
{ "Period", "wreth.BlinkyPeriod",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_GetValueVal,
{ "Value", "wreth.GetValue",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_SetValueVal,
{ "Value", "wreth.SetValue",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_BoostValue,
{ "Boost", "wreth.BoostStatus",
FT_UINT16, BASE_DEC, VALS(BoostValue), 0x0,
NULL, HFILL }
},
{ &hf_Wreth_MailDestTic,
{ "Dest tic", "wreth.MailDestTic",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_MailReserved,
{ "Reserved", "wreth.MailReserved",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Codef,
{ "Codef", "wreth.Mail.Codef",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &tabCodef_ext, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Status,
{ "Status", "wreth.Mail.Status",
FT_INT16, BASE_DEC | BASE_EXT_STRING, &tabStatus_ext, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_TicUser_Root,
{ "TicUser Root", "wreth.Mail.TicUserRoot",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_PidUser,
{ "PidUser", "wreth.Mail.PidUser",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Mode,
{ "Mode", "wreth.Mail.Mode",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Time,
{ "Time", "wreth.Mail.Time",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Stop,
{ "Stop", "wreth.Mail.Stop",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Nfonc,
{ "Nfonc", "wreth.Mail.Nfonc",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Ncard,
{ "Ncard", "wreth.Mail.Ncard",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Nchan,
{ "Nchan", "wreth.Mail.Nchan",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Nes,
{ "Nes", "wreth.Mail.Nes",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Nb,
{ "Nb", "wreth.Mail.Nb",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_TypVar,
{ "TypVar", "wreth.Mail.TypVar",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Adr,
{ "Adr", "wreth.Mail.Adr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_TicUser_DispCyc,
{ "TicUser DispCyc", "wreth.Mail.TicUser.DispCyc",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Nb_Max_Size_Mail,
{ "Nb Max Size Mail", "wreth.Mail.TicUser.Nb.Max.Size.Mail",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_User_ThreadID,
{ "User ThreadID", "wreth.Mail.User.ThreadID",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_DispCyc_Version,
{ "DispCyc Version", "wreth.Mail.DispCyc.Version",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_DifUserParam,
{ "DifUserParam", "wreth.Mail.DifUserParam",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Filler,
{ "Filler", "wreth.Mail.Filler",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_Wreth_Mail_Data,
{ "Data", "wreth.Mail.Data",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_Wreth_Mail_Mastinf_Version,
{ "Version", "wreth.Mail.Mastinf.Version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Mastinf_Release,
{ "Release", "wreth.Mail.Mastinf.Release",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Mastinf_Protocol,
{ "Protocol", "wreth.Mail.Mastinf.Protocol",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Mastinf_CyclicFlux,
{ "CyclicFlux", "wreth.Mail.Mastinf.CyclicFlux",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Mastinf_szProtocolName,
{ "ProtocolName", "wreth.Mail.Mastinf.ProtocolName",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Mastinf_MaxTypeEquipment,
{ "MaxTypeEquipment", "wreth.Mail.Mastinf.MaxTypeEquipment",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Mastinf_MinEquipmentNumber,
{ "MinEquipmentNumber", "wreth.Mail.Mastinf.MinEquipmentNumber",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Mastinf_MaxEquipmentNumber,
{ "MaxEquipmentNumber", "wreth.Mail.Mastinf.MaxEquipmentNumber",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_Version,
{ "Version", "wreth.Mail.Equinf.Version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_Release,
{ "Release", "wreth.Mail.Equinf.Release",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_Network,
{ "Network", "wreth.Mail.Equinf.Network",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_Protocol,
{ "Protocol", "wreth.Mail.Equinf.Protocol",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_Messaging,
{ "Messaging", "wreth.Mail.Equinf.Messaging",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_Equipment,
{ "Equipment", "wreth.Mail.Equinf.Equipment",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_Flux,
{ "Flux", "wreth.Mail.Equinf.Flux",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_IncWord,
{ "IncWord", "wreth.Mail.Equinf.IncWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_IncDWord,
{ "IncDWord", "wreth.Mail.Equinf.IncDWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_IncFWord,
{ "IncFWord", "wreth.Mail.Equinf.IncFWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Mastinf_DllItemName,
{ "DllItemName", "wreth.Mail.Equinf.DllItemName",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Mastinf_szEquipmentName,
{ "EquipmentName", "wreth.Mail.Equinf.EquipmentName",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxWriteBit,
{ "MaxWriteBit", "wreth.Mail.Equinf.MaxWriteBit",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxReadBit,
{ "MaxReadBit", "wreth.Mail.Equinf.MaxReadBit",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_BreakBit,
{ "BreakBit", "wreth.Mail.Equinf.BreakBit",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxWriteIBit,
{ "MaxWriteIBit", "wreth.Mail.Equinf.MaxWriteIBit",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxReadIBit,
{ "MaxReadIBit", "wreth.Mail.Equinf.MaxReadIBit",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxWriteQBit,
{ "MaxWriteQBit", "wreth.Mail.Equinf.MaxWriteQBit",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxReadQBit,
{ "MaxReadQBit", "wreth.Mail.Equinf.MaxReadQBit",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_BreakQBit,
{ "BreakQBit", "wreth.Mail.Equinf.BreakQBit",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxWriteByte,
{ "MaxWriteByte", "wreth.Mail.Equinf.MaxWriteByte",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxReadByte,
{ "MaxReadByte", "wreth.Mail.Equinf.MaxReadByte",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_BreakByte,
{ "BreakByte", "wreth.Mail.Equinf.BreakByte",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxWriteIByte,
{ "MaxWriteIByte", "wreth.Mail.Equinf.MaxWriteIByte",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxReadIByte,
{ "MaxReadIByte", "wreth.Mail.Equinf.MaxReadIByte",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_BreakIByte,
{ "BreakIByte", "wreth.Mail.Equinf.BreakIByte",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxWriteQByte,
{ "MaxWriteQByte", "wreth.Mail.Equinf.MaxWriteQByte",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxReadQByte,
{ "MaxReadQByte", "wreth.Mail.Equinf.MaxReadQByte",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
}
,
{ &hf_Wreth_Mail_Equinf_BreakQByte ,
{ "BreakQByte", "wreth.Mail.Equinf.BreakQByte",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxWriteWord ,
{ "MaxWriteWord", "wreth.Mail.Equinf.MaxWriteWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxReadWord ,
{ "MaxReadWord", "wreth.Mail.Equinf.MaxReadWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_BreakWord ,
{ "BreakWord", "wreth.Mail.Equinf.BreakWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxWriteIWord ,
{ "MaxWriteIWord", "wreth.Mail.Equinf.MaxWriteIWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxReadIWord ,
{ "MaxReadIWord", "wreth.Mail.Equinf.MaxReadIWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_BreakIWord ,
{ "BreakIWord", "wreth.Mail.Equinf.BreakIWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxReadQWord ,
{ "MaxReadQWord", "wreth.Mail.Equinf.MaxReadQWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxWriteQWord ,
{ "MaxWriteQWord", "wreth.Mail.Equinf.MaxWriteQWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_BreakQWord ,
{ "BreakQWord", "wreth.Mail.Equinf.BreakQWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxWriteDWord ,
{ "MaxWriteDWord", "wreth.Mail.Equinf.MaxWriteDWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxReadDWord ,
{ "MaxReadDWord", "wreth.Mail.Equinf.MaxReadDWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_BreakDWord ,
{ "BreakDWord", "wreth.Mail.Equinf.BreakDWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxWriteFWord ,
{ "MaxWriteFWord", "wreth.Mail.Equinf.MaxWriteFWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_MaxReadFWord ,
{ "MaxReadFWord", "wreth.Mail.Equinf.MaxReadFWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_BreakFWord ,
{ "BreakFWord", "wreth.Mail.Equinf.BreakFWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_ReadFactorWord ,
{ "ReadFactorWord", "wreth.Mail.Equinf.ReadFactorWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_ReadFactorIWord ,
{ "ReadFactorIWord", "wreth.Mail.Equinf.ReadFactorIWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_ReadFactorQWord ,
{ "ReadFactorQWord", "wreth.Mail.Equinf.ReadFactorQWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_ReadFactorDWord ,
{ "ReadFactorDWord", "wreth.Mail.Equinf.ReadFactorDWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_ReadFactorFWord ,
{ "ReadFactorFWord", "wreth.Mail.Equinf.ReadFactorFWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_WriteFactorWord ,
{ "WriteFactorWord", "wreth.Mail.Equinf.WriteFactorWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_WriteFactorIWord ,
{ "WriteFactorIWord", "wreth.Mail.Equinf.WriteFactorIWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_WriteFactorQWord ,
{ "WriteFactorQWord", "wreth.Mail.Equinf.WriteFactorQWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_WriteFactorDWord ,
{ "WriteFactorDWord", "wreth.Mail.Equinf.WriteFactorDWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_WriteFactorFWord ,
{ "WriteFactorFWord", "wreth.Mail.Equinf.WriteFactorFWord",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_DataFormat ,
{ "DataFormat", "wreth.Mail.Equinf.DataFormat",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_Wreth_Mail_Equinf_BreakIBit ,
{ "BreakIBit", "wreth.Mail.Equinf.BreakIBit",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_wreth
};
wreth_proto = proto_register_protocol (
"WSE remote ethernet",
"WRETH",
"wreth"
);
proto_register_field_array(wreth_proto, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_wreth(void)
{
static dissector_handle_t wreth_handle;
wreth_handle = create_dissector_handle(dissect_wreth, wreth_proto);
dissector_add_uint("ethertype", WRETH_PORT, wreth_handle);
}
