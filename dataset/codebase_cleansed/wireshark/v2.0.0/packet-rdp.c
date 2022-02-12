static rdp_conv_info_t *
rdp_get_conversation_data(packet_info *pinfo)
{
conversation_t *conversation;
rdp_conv_info_t *rdp_info;
conversation = find_or_create_conversation(pinfo);
rdp_info = (rdp_conv_info_t *)conversation_get_proto_data(conversation, proto_rdp);
if (rdp_info == NULL) {
rdp_info = wmem_new0(wmem_file_scope(), rdp_conv_info_t);
rdp_info->staticChannelId = -1;
rdp_info->encryptionMethod = 0;
rdp_info->encryptionLevel = 0;
rdp_info->licenseAgreed = 0;
rdp_info->maxChannels = 0;
conversation_add_proto_data(conversation, proto_rdp, rdp_info);
}
return rdp_info;
}
static int
dissect_rdp_fields(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, const rdp_field_info_t *fields, int totlen)
{
const rdp_field_info_t *c;
gint len;
int base_offset = offset;
guint32 info_flags = 0;
guint encoding;
while (((c = fields++)->pfield) != NULL) {
if ((c->fixedLength == 0) && (c->variableLength)) {
len = *(c->variableLength);
} else {
len = c->fixedLength;
if ((c->variableLength) && (c->fixedLength <= 4)) {
switch (c->fixedLength) {
case 1:
*(c->variableLength) = tvb_get_guint8(tvb, offset);
break;
case 2:
*(c->variableLength) = tvb_get_letohs(tvb, offset);
break;
case 4:
*(c->variableLength) = tvb_get_letohl(tvb, offset);
break;
default:
REPORT_DISSECTOR_BUG("Invalid length");
}
*(c->variableLength) += c->offsetOrTree;
}
}
if (len) {
proto_item *pi;
if (c->flags & RDP_FI_STRING) {
if (c->flags & RDP_FI_UNICODE)
encoding = ENC_UTF_16|ENC_LITTLE_ENDIAN;
else if (c->flags & RDP_FI_ANSI)
encoding = ENC_ASCII|ENC_NA;
else {
encoding = (info_flags & INFO_UNICODE) ? ENC_UTF_16|ENC_LITTLE_ENDIAN : ENC_ASCII|ENC_NA;
}
} else
encoding = ENC_LITTLE_ENDIAN;
pi = proto_tree_add_item(tree, *c->pfield, tvb, offset, len, encoding);
if (c->flags & RDP_FI_INFO_FLAGS) {
DISSECTOR_ASSERT(len == 4);
info_flags = tvb_get_letohl(tvb, offset);
}
if (c->flags & RDP_FI_SUBTREE) {
proto_tree *next_tree;
if (c->offsetOrTree != -1)
next_tree = proto_item_add_subtree(pi, c->offsetOrTree);
else
REPORT_DISSECTOR_BUG("Tree Error!!");
if (c->subfields)
dissect_rdp_fields(tvb, offset, pinfo, next_tree, c->subfields, 0);
}
if (!(c->flags & RDP_FI_NOINCOFFSET))
offset += len;
}
if ((totlen > 0) && ((offset-base_offset) >= totlen))
break;
}
return offset;
}
static int
dissect_rdp_nyi(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, const char *info)
{
rdp_field_info_t nyi_fields[] = {
{&hf_rdp_notYetImplemented, -1, NULL, 0, 0, NULL },
FI_TERMINATOR
};
offset = dissect_rdp_fields(tvb, offset, pinfo, tree, nyi_fields, 0);
if ((tree != NULL) && (info != NULL))
proto_item_append_text(tree->last_child, " (%s)", info);
return offset;
}
static int
dissect_rdp_encrypted(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, const char *info)
{
rdp_field_info_t enc_fields[] = {
{&hf_rdp_encrypted, -1, NULL, 0, 0, NULL },
FI_TERMINATOR
};
offset = dissect_rdp_fields(tvb, offset,pinfo, tree, enc_fields, 0);
if ((tree != NULL) && (info != NULL))
proto_item_append_text(tree->last_child, " (%s)", info);
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", "[Encrypted]");
return offset;
}
static int
dissect_rdp_clientNetworkData(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint length, rdp_conv_info_t *rdp_info)
{
proto_tree *next_tree;
proto_item *pi;
guint32 channelCount = 0;
rdp_field_info_t net_fields[] = {
{&hf_rdp_headerType, 2, NULL, 0, 0, NULL },
{&hf_rdp_headerLength, 2, NULL, 0, 0, NULL },
FI_VALUE(&hf_rdp_channelCount, 4, channelCount),
FI_TERMINATOR
};
rdp_field_info_t option_fields[] = {
{&hf_rdp_optionsInitialized, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_optionsEncryptRDP, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_optionsEncryptSC, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_optionsEncryptCS, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_optionsPriHigh, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_optionsPriMed, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_optionsPriLow, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_optionsCompressRDP, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_optionsCompress, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_optionsShowProtocol, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_optionsRemoteControlPersistent, 4, NULL, 0, 0, NULL },
FI_TERMINATOR,
};
rdp_field_info_t channel_fields[] = {
FI_FIXEDLEN_ANSI_STRING(&hf_rdp_name, 8),
FI_SUBTREE(&hf_rdp_options, 4, ett_rdp_options, option_fields),
FI_TERMINATOR
};
rdp_field_info_t def_fields[] = {
FI_SUBTREE(&hf_rdp_channelDef, 12, ett_rdp_channelDef, channel_fields),
FI_TERMINATOR
};
pi = proto_tree_add_item(tree, hf_rdp_clientNetworkData, tvb, offset, length, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_clientNetworkData);
offset = dissect_rdp_fields(tvb, offset, pinfo, next_tree, net_fields, 0);
if (channelCount > 0) {
guint i;
pi = proto_tree_add_item(next_tree, hf_rdp_channelDefArray, tvb, offset, channelCount * 12, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_channelDefArray);
if (rdp_info)
rdp_info->maxChannels = MIN(channelCount, MAX_CHANNELS);
for (i = 0; i < MIN(channelCount, MAX_CHANNELS); i++) {
if (rdp_info) {
rdp_info->channels[i].value = -1;
rdp_info->channels[i].strptr = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 8, ENC_ASCII);
}
offset = dissect_rdp_fields(tvb, offset, pinfo, next_tree, def_fields, 0);
}
if (rdp_info) {
rdp_info->channels[i].value = 0;
rdp_info->channels[i].strptr = NULL;
}
}
return offset;
}
static int
dissect_rdp_basicSecurityHeader(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint32 *flags_ptr) {
guint32 flags = 0;
rdp_field_info_t secFlags_fields[] = {
{&hf_rdp_flagsPkt, 2, &flags, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_flagsEncrypt, 2, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_flagsResetSeqno, 2, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_flagsIgnoreSeqno, 2, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_flagsLicenseEncrypt,2, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_flagsSecureChecksum,2, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_flagsFlagsHiValid, 2, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
FI_TERMINATOR
};
rdp_field_info_t flags_fields[] = {
FI_SUBTREE(&hf_rdp_flags, 2, ett_rdp_flags, secFlags_fields),
FI_FIXEDLEN(&hf_rdp_flagsHi, 2),
FI_TERMINATOR
};
offset = dissect_rdp_fields(tvb, offset, pinfo, tree, flags_fields, 0);
if (flags_ptr)
*flags_ptr = flags;
return offset;
}
static int
dissect_rdp_securityHeader(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, rdp_conv_info_t *rdp_info, gboolean alwaysBasic, guint32 *flags_ptr) {
rdp_field_info_t fips_fields[] = {
{&hf_rdp_fipsLength, 2, NULL, 0, 0, NULL },
{&hf_rdp_fipsVersion, 1, NULL, 0, 0, NULL },
{&hf_rdp_padlen, 1, NULL, 0, 0, NULL },
{&hf_rdp_dataSignature, 8, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t enc_fields[] = {
{&hf_rdp_dataSignature, 8, NULL, 0, 0, NULL },
FI_TERMINATOR
};
const rdp_field_info_t *fields = NULL;
if (rdp_info) {
if (alwaysBasic || (rdp_info->encryptionLevel != ENCRYPTION_LEVEL_NONE))
offset = dissect_rdp_basicSecurityHeader(tvb, offset, pinfo, tree, flags_ptr);
if (rdp_info->encryptionMethod &
(ENCRYPTION_METHOD_40BIT |
ENCRYPTION_METHOD_128BIT |
ENCRYPTION_METHOD_56BIT)) {
fields = enc_fields;
} else if (rdp_info->encryptionMethod == ENCRYPTION_METHOD_FIPS) {
fields = fips_fields;
}
if (fields)
offset = dissect_rdp_fields(tvb, offset, pinfo, tree, fields, 0);
}
return offset;
}
static int
dissect_rdp_channelPDU(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree) {
guint32 length = 0;
rdp_field_info_t flag_fields[] = {
{&hf_rdp_channelFlagFirst, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_channelFlagLast, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_channelFlagShowProtocol, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_channelFlagSuspend, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_channelFlagResume, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_channelPacketCompressed, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_channelPacketAtFront, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_channelPacketFlushed, 4, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_channelPacketCompressionType, 4, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t channel_fields[] = {
FI_VALUE(&hf_rdp_length, 4, length),
FI_SUBTREE(&hf_rdp_channelFlags, 4, ett_rdp_channelFlags, flag_fields),
FI_TERMINATOR
};
rdp_field_info_t channelPDU_fields[] = {
FI_SUBTREE(&hf_rdp_channelPDUHeader, 8, ett_rdp_channelPDUHeader, channel_fields),
FI_FIXEDLEN(&hf_rdp_virtualChannelData, -1),
FI_TERMINATOR
};
offset = dissect_rdp_fields(tvb, offset, pinfo, tree, channelPDU_fields, 0);
return offset;
}
static int
dissect_rdp_shareDataHeader(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree) {
guint32 pduType2 = 0;
guint32 compressedType;
guint32 action = 0;
rdp_field_info_t compressed_fields[] = {
{&hf_rdp_compressedTypeType, 1, &compressedType, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_compressedTypeCompressed, 1, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_compressedTypeAtFront, 1, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_compressedTypeFlushed, 1, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t share_fields[] = {
{&hf_rdp_shareId, 4, NULL, 0, 0, NULL },
{&hf_rdp_pad1, 1, NULL, 0, 0, NULL },
{&hf_rdp_streamId, 1, NULL, 0, 0, NULL },
{&hf_rdp_uncompressedLength, 2, NULL, 0, 0, NULL },
{&hf_rdp_pduType2, 1, &pduType2, 0, 0, NULL },
FI_SUBTREE(&hf_rdp_compressedType, 1, ett_rdp_compressedType, compressed_fields),
{&hf_rdp_compressedLength, 2, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t control_fields[] = {
{&hf_rdp_action, 2, &action, 0, 0, NULL },
{&hf_rdp_grantId, 2, NULL, 0, 0, NULL },
{&hf_rdp_controlId, 4, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t sync_fields[] = {
{&hf_rdp_messageType, 2, NULL, 0, 0, NULL },
{&hf_rdp_targetUser, 2, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t mapflags_fields[] = {
{&hf_rdp_fontMapFirst, 2, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_fontMapLast, 2, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
FI_TERMINATOR
};
rdp_field_info_t fontmap_fields[] = {
{&hf_rdp_numberEntries, 2, NULL, 0, 0, NULL },
{&hf_rdp_totalNumberEntries, 2, NULL, 0, 0, NULL },
FI_SUBTREE(&hf_rdp_mapFlags, 2, ett_rdp_mapFlags, mapflags_fields),
{&hf_rdp_entrySize, 2, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t persistent_fields[] = {
{&hf_rdp_numEntriesCache0, 2, NULL, 0, 0, NULL },
{&hf_rdp_numEntriesCache1, 2, NULL, 0, 0, NULL },
{&hf_rdp_numEntriesCache2, 2, NULL, 0, 0, NULL },
{&hf_rdp_numEntriesCache3, 2, NULL, 0, 0, NULL },
{&hf_rdp_numEntriesCache4, 2, NULL, 0, 0, NULL },
{&hf_rdp_totalEntriesCache0, 2, NULL, 0, 0, NULL },
{&hf_rdp_totalEntriesCache1, 2, NULL, 0, 0, NULL },
{&hf_rdp_totalEntriesCache2, 2, NULL, 0, 0, NULL },
{&hf_rdp_totalEntriesCache3, 2, NULL, 0, 0, NULL },
{&hf_rdp_totalEntriesCache4, 2, NULL, 0, 0, NULL },
{&hf_rdp_bBitMask, 1, NULL, 0, 0, NULL },
{&hf_rdp_Pad2, 1, NULL, 0, 0, NULL },
{&hf_rdp_Pad3, 2, NULL, 0, 0, NULL },
FI_TERMINATOR
};
const rdp_field_info_t *fields;
offset = dissect_rdp_fields(tvb, offset, pinfo, tree, share_fields, 0);
if (pduType2 != PDUTYPE2_CONTROL)
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", val_to_str_const(pduType2, rdp_pduType2_vals, "Unknown"));
fields = NULL;
switch(pduType2) {
case PDUTYPE2_UPDATE:
break;
case PDUTYPE2_CONTROL:
fields = control_fields;
break;
case PDUTYPE2_POINTER:
break;
case PDUTYPE2_INPUT:
break;
case PDUTYPE2_SYNCHRONIZE:
fields = sync_fields;
break;
case PDUTYPE2_REFRESH_RECT:
break;
case PDUTYPE2_PLAY_SOUND:
break;
case PDUTYPE2_SUPPRESS_OUTPUT:
break;
case PDUTYPE2_SHUTDOWN_REQUEST:
break;
case PDUTYPE2_SHUTDOWN_DENIED:
break;
case PDUTYPE2_SAVE_SESSION_INFO:
break;
case PDUTYPE2_FONTLIST:
break;
case PDUTYPE2_FONTMAP:
fields = fontmap_fields;
break;
case PDUTYPE2_SET_KEYBOARD_INDICATORS:
break;
case PDUTYPE2_BITMAPCACHE_PERSISTENT_LIST:
fields = persistent_fields;
break;
case PDUTYPE2_BITMAPCACHE_ERROR_PDU:
break;
case PDUTYPE2_SET_KEYBOARD_IME_STATUS:
break;
case PDUTYPE2_OFFSCRCACHE_ERROR_PDU:
break;
case PDUTYPE2_SET_ERROR_INFO_PDU:
break;
case PDUTYPE2_DRAWNINEGRID_ERROR_PDU:
break;
case PDUTYPE2_DRAWGDIPLUS_ERROR_PDU:
break;
case PDUTYPE2_ARC_STATUS_PDU:
break;
case PDUTYPE2_STATUS_INFO_PDU:
break;
case PDUTYPE2_MONITOR_LAYOUT_PDU:
break;
default:
break;
}
if (fields) {
offset = dissect_rdp_fields(tvb, offset, pinfo, tree, fields, 0);
}
if (pduType2 == PDUTYPE2_CONTROL)
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", val_to_str_const(action, rdp_action_vals, "Unknown"));
return offset;
}
static int
dissect_rdp_capabilitySets(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint32 numberCapabilities) {
guint i;
guint32 lengthCapability;
rdp_field_info_t cs_fields[] = {
{&hf_rdp_capabilitySetType, 2, NULL, 0, 0, NULL },
{&hf_rdp_lengthCapability, 2, &lengthCapability, -4, 0, NULL },
{&hf_rdp_capabilityData, 0, &lengthCapability, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t set_fields[] = {
FI_SUBTREE(&hf_rdp_capabilitySet, 0, ett_rdp_capabilitySet, cs_fields),
FI_TERMINATOR
};
for (i = 0; i < numberCapabilities; i++) {
offset = dissect_rdp_fields(tvb, offset, pinfo, tree, set_fields, 0);
}
return offset;
}
static int
dissect_rdp_demandActivePDU(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree) {
guint32 lengthSourceDescriptor;
guint32 numberCapabilities = 0;
rdp_field_info_t fields[] = {
{&hf_rdp_shareId, 4, NULL, 0, 0, NULL },
{&hf_rdp_lengthSourceDescriptor, 2, &lengthSourceDescriptor, 0, 0, NULL },
{&hf_rdp_lengthCombinedCapabilities, 2, NULL, 0, 0, NULL },
{&hf_rdp_sourceDescriptor, 0, &lengthSourceDescriptor, 0, RDP_FI_STRING|RDP_FI_ANSI, NULL },
{&hf_rdp_numberCapabilities, 2, &numberCapabilities, 0, 0, NULL },
{&hf_rdp_pad2Octets, 2, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t final_fields[] = {
{&hf_rdp_sessionId, 4, NULL, 0, 0, NULL },
FI_TERMINATOR
};
offset = dissect_rdp_fields(tvb, offset, pinfo, tree, fields, 0);
offset = dissect_rdp_capabilitySets(tvb, offset, pinfo, tree, numberCapabilities);
offset = dissect_rdp_fields(tvb, offset, pinfo, tree, final_fields, 0);
return offset;
}
static int
dissect_rdp_confirmActivePDU(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree) {
guint32 lengthSourceDescriptor;
guint32 numberCapabilities = 0;
rdp_field_info_t fields[] = {
{&hf_rdp_shareId, 4, NULL, 0, 0, NULL },
{&hf_rdp_originatorId, 2, NULL, 0, 0, NULL },
{&hf_rdp_lengthSourceDescriptor, 2, &lengthSourceDescriptor, 0, 0, NULL },
{&hf_rdp_lengthCombinedCapabilities, 2, NULL, 0, 0, NULL },
{&hf_rdp_sourceDescriptor, 0, &lengthSourceDescriptor, 0, 0, NULL },
{&hf_rdp_numberCapabilities, 2, &numberCapabilities, 0, 0, NULL },
{&hf_rdp_pad2Octets, 2, NULL, 0, 0, NULL },
FI_TERMINATOR
};
offset = dissect_rdp_fields(tvb, offset, pinfo, tree, fields, 0);
offset = dissect_rdp_capabilitySets(tvb, offset, pinfo, tree, numberCapabilities);
return offset;
}
static proto_tree *
dissect_rdp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item *item;
proto_tree *tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RDP");
col_clear(pinfo->cinfo, COL_INFO);
item = proto_tree_add_item(parent_tree, proto_rdp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_rdp);
return tree;
}
static void
dissect_rdp_SendData(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
proto_item *pi;
int offset = 0;
guint32 flags = 0;
guint32 cbDomain, cbUserName, cbPassword, cbAlternateShell, cbWorkingDir,
cbClientAddress, cbClientDir, cbAutoReconnectLen, wBlobLen, pduType = 0;
guint32 bMsgType = 0xffffffff;
guint32 encryptedLen = 0;
conversation_t *conversation;
rdp_conv_info_t *rdp_info;
rdp_field_info_t secFlags_fields[] = {
{&hf_rdp_flagsPkt, 2, &flags, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_flagsEncrypt, 2, NULL , 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_flagsResetSeqno, 2, NULL , 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_flagsIgnoreSeqno, 2, NULL , 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_flagsLicenseEncrypt,2, NULL , 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_flagsSecureChecksum,2, NULL , 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_flagsFlagsHiValid, 2, NULL , 0, RDP_FI_NOINCOFFSET, NULL },
FI_TERMINATOR
};
rdp_field_info_t se_fields[] = {
FI_SUBTREE(&hf_rdp_flags, 2, ett_rdp_flags, secFlags_fields),
FI_FIXEDLEN(&hf_rdp_flagsHi, 2),
{&hf_rdp_length, 4, &encryptedLen, 0, 0, NULL },
{&hf_rdp_encryptedClientRandom, 0, &encryptedLen, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t systime_fields [] = {
FI_FIXEDLEN(&hf_rdp_wYear , 2),
FI_FIXEDLEN(&hf_rdp_wMonth , 2),
FI_FIXEDLEN(&hf_rdp_wDayOfWeek , 2),
FI_FIXEDLEN(&hf_rdp_wDay , 2),
FI_FIXEDLEN(&hf_rdp_wHour , 2),
FI_FIXEDLEN(&hf_rdp_wMinute , 2),
FI_FIXEDLEN(&hf_rdp_wSecond , 2),
FI_FIXEDLEN(&hf_rdp_wMilliseconds, 2),
FI_TERMINATOR,
};
rdp_field_info_t tz_info_fields [] = {
FI_FIXEDLEN(&hf_rdp_Bias, 4),
{&hf_rdp_StandardName, 64, NULL, 0, RDP_FI_STRING|RDP_FI_UNICODE, NULL },
FI_SUBTREE(&hf_rdp_StandardDate, 16, ett_rdp_StandardDate, systime_fields),
FI_FIXEDLEN(&hf_rdp_StandardBias, 4),
{&hf_rdp_DaylightName, 64, NULL, 0, RDP_FI_STRING|RDP_FI_UNICODE, NULL },
FI_SUBTREE(&hf_rdp_DaylightDate, 16, ett_rdp_DaylightDate, systime_fields),
FI_FIXEDLEN(&hf_rdp_DaylightBias, 4),
FI_TERMINATOR,
};
rdp_field_info_t ue_fields[] = {
{&hf_rdp_codePage, 4, NULL, 0, 0, NULL },
{&hf_rdp_optionFlags, 4, NULL, 0, RDP_FI_INFO_FLAGS, NULL },
{&hf_rdp_cbDomain, 2, &cbDomain, 2, 0, NULL },
{&hf_rdp_cbUserName, 2, &cbUserName, 2, 0, NULL },
{&hf_rdp_cbPassword, 2, &cbPassword, 2, 0, NULL },
{&hf_rdp_cbAlternateShell, 2, &cbAlternateShell, 2, 0, NULL },
{&hf_rdp_cbWorkingDir, 2, &cbWorkingDir, 2, 0, NULL },
{&hf_rdp_domain, 0, &cbDomain, 0, RDP_FI_STRING, NULL },
{&hf_rdp_userName, 0, &cbUserName, 0, RDP_FI_STRING, NULL },
{&hf_rdp_password, 0, &cbPassword, 0, RDP_FI_STRING, NULL },
{&hf_rdp_alternateShell, 0, &cbAlternateShell, 0, RDP_FI_STRING, NULL },
{&hf_rdp_workingDir, 0, &cbWorkingDir, 0, RDP_FI_STRING, NULL },
{&hf_rdp_clientAddressFamily,2, NULL, 0, 0, NULL },
{&hf_rdp_cbClientAddress, 2, &cbClientAddress, 0, 0, NULL },
{&hf_rdp_clientAddress, 0, &cbClientAddress, 0, RDP_FI_STRING, NULL },
{&hf_rdp_cbClientDir, 2, &cbClientDir, 0, 0, NULL },
{&hf_rdp_clientDir, 0, &cbClientDir, 0, RDP_FI_STRING, NULL },
FI_SUBTREE(&hf_rdp_clientTimeZone, 172, ett_rdp_clientTimeZone, tz_info_fields),
{&hf_rdp_clientSessionId, 4, NULL, 0, 0, NULL },
{&hf_rdp_performanceFlags, 4, NULL, 0, 0, NULL },
{&hf_rdp_cbAutoReconnectLen, 2, &cbAutoReconnectLen, 0, 0, NULL },
{&hf_rdp_autoReconnectCookie,0, &cbAutoReconnectLen, 0, 0, NULL },
{&hf_rdp_reserved1, 2, NULL, 0, 0, NULL },
{&hf_rdp_reserved2, 2, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t msg_fields[] = {
{&hf_rdp_bMsgType, 1, &bMsgType, 0, 0, NULL },
{&hf_rdp_bVersion, 1, NULL, 0, 0, NULL },
{&hf_rdp_wMsgSize, 2, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t error_fields[] = {
{&hf_rdp_wErrorCode, 4, NULL, 0, 0, NULL },
{&hf_rdp_wStateTransition, 4, NULL, 0, 0, NULL },
{&hf_rdp_wBlobType, 2, NULL, 0, 0, NULL },
{&hf_rdp_wBlobLen, 2, &wBlobLen, 0, 0, NULL },
{&hf_rdp_blobData, 0, &wBlobLen, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t pdu_fields[] = {
{&hf_rdp_pduTypeType, 2, &pduType, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_pduTypeVersionLow, 2, NULL, 0, RDP_FI_NOINCOFFSET, NULL },
{&hf_rdp_pduTypeVersionHigh, 2, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t ctrl_fields[] = {
{&hf_rdp_totalLength, 2, NULL, 0, 0, NULL },
{&hf_rdp_pduType, 2, NULL, ett_rdp_pduType, RDP_FI_SUBTREE,
pdu_fields },
{&hf_rdp_pduSource, 2, NULL, 0, 0, NULL },
FI_TERMINATOR
};
tree = dissect_rdp(tvb, pinfo, tree);
pi = proto_tree_add_item(tree, hf_rdp_SendData, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(pi, ett_rdp_SendData);
conversation = find_or_create_conversation(pinfo);
rdp_info = (rdp_conv_info_t *)conversation_get_proto_data(conversation, proto_rdp);
if (rdp_info &&
((rdp_info->licenseAgreed == 0) ||
(pinfo->fd->num <= rdp_info->licenseAgreed))) {
proto_tree *next_tree;
flags = tvb_get_letohs(tvb, offset);
switch(flags & SEC_PKT_MASK) {
case SEC_EXCHANGE_PKT:
pi = proto_tree_add_item(tree, hf_rdp_securityExchangePDU, tvb, offset, -1, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_securityExchangePDU);
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "SecurityExchange");
dissect_rdp_fields(tvb, offset, pinfo, next_tree, se_fields, 0);
break;
case SEC_INFO_PKT:
pi = proto_tree_add_item(tree, hf_rdp_clientInfoPDU, tvb, offset, -1, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_clientInfoPDU);
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "ClientInfo");
offset = dissect_rdp_securityHeader(tvb, offset, pinfo, next_tree, rdp_info, TRUE, NULL);
if (!(flags & SEC_ENCRYPT)) {
dissect_rdp_fields(tvb, offset, pinfo, next_tree, ue_fields, 0);
} else {
dissect_rdp_encrypted(tvb, offset, pinfo, next_tree, NULL);
}
break;
case SEC_LICENSE_PKT:
pi = proto_tree_add_item(tree, hf_rdp_validClientLicenseData, tvb, offset, -1, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_validClientLicenseData);
offset = dissect_rdp_securityHeader(tvb, offset, pinfo, next_tree, rdp_info, TRUE, NULL);
if (!(flags & SEC_ENCRYPT)) {
offset = dissect_rdp_fields(tvb, offset, pinfo, next_tree, msg_fields, 0);
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", val_to_str_const(bMsgType, rdp_bMsgType_vals, "Unknown"));
switch(bMsgType) {
case LICENSE_REQUEST:
case PLATFORM_CHALLENGE:
case NEW_LICENSE:
case UPGRADE_LICENSE:
case LICENSE_INFO:
case NEW_LICENSE_REQUEST:
case PLATFORM_CHALLENGE_RESPONSE:
dissect_rdp_nyi(tvb, offset, pinfo, next_tree, "RDPELE not implemented");
break;
case ERROR_ALERT:
dissect_rdp_fields(tvb, offset, pinfo, next_tree, error_fields, 0);
rdp_info->licenseAgreed = pinfo->fd->num;
break;
default:
break;
}
} else {
dissect_rdp_encrypted(tvb, offset, pinfo, next_tree, NULL);
rdp_info->licenseAgreed = pinfo->fd->num;
}
break;
case SEC_REDIRECTION_PKT:
break;
default:
break;
}
return;
}
if (rdp_info && (t124_get_last_channelId() == rdp_info->staticChannelId)) {
offset = dissect_rdp_securityHeader(tvb, offset, pinfo, tree, rdp_info, FALSE, &flags);
if (!(flags & SEC_ENCRYPT)) {
proto_tree *next_tree;
pi = proto_tree_add_item(tree, hf_rdp_shareControlHeader, tvb, offset, -1, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_shareControlHeader);
offset = dissect_rdp_fields(tvb, offset, pinfo, next_tree, ctrl_fields, 0);
pduType &= PDUTYPE_TYPE_MASK;
if (pduType != PDUTYPE_DATAPDU)
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", val_to_str_const(pduType, rdp_pduTypeType_vals, "Unknown"));
switch(pduType) {
case PDUTYPE_DEMANDACTIVEPDU:
dissect_rdp_demandActivePDU(tvb, offset, pinfo, next_tree);
break;
case PDUTYPE_CONFIRMACTIVEPDU:
dissect_rdp_confirmActivePDU(tvb, offset, pinfo, next_tree);
break;
case PDUTYPE_DEACTIVATEALLPDU:
break;
case PDUTYPE_DATAPDU:
dissect_rdp_shareDataHeader(tvb, offset, pinfo, next_tree);
break;
case PDUTYPE_SERVER_REDIR_PKT:
break;
default:
break;
}
} else {
dissect_rdp_encrypted(tvb, offset, pinfo, tree, NULL);
}
col_set_fence(pinfo->cinfo, COL_INFO);
return;
}
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "Virtual Channel PDU");
offset = dissect_rdp_securityHeader(tvb, offset, pinfo, tree, rdp_info, FALSE, &flags);
if (!(flags & SEC_ENCRYPT))
dissect_rdp_channelPDU(tvb, offset, pinfo, tree);
else
dissect_rdp_encrypted(tvb, offset, pinfo, tree, "Channel PDU");
}
static void
dissect_rdp_ClientData(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
int offset = 0;
proto_item *pi;
proto_tree *next_tree;
guint16 type;
guint length;
rdp_conv_info_t *rdp_info;
rdp_field_info_t header_fields[] = {
{&hf_rdp_headerType, 2, NULL, 0, 0, NULL },
{&hf_rdp_headerLength, 2, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t core_fields[] = {
{&hf_rdp_headerType, 2, NULL, 0, 0, NULL },
{&hf_rdp_headerLength, 2, NULL, 0, 0, NULL },
{&hf_rdp_versionMajor, 2, NULL, 0, 0, NULL },
{&hf_rdp_versionMinor, 2, NULL, 0, 0, NULL },
{&hf_rdp_desktopWidth, 2, NULL, 0, 0, NULL },
{&hf_rdp_desktopHeight, 2, NULL, 0, 0, NULL },
{&hf_rdp_colorDepth, 2, NULL, 0, 0, NULL },
{&hf_rdp_SASSequence, 2, NULL, 0, 0, NULL },
{&hf_rdp_keyboardLayout, 4, NULL, 0, 0, NULL },
{&hf_rdp_clientBuild, 4, NULL, 0, 0, NULL },
{&hf_rdp_clientName, 32, NULL, 0, RDP_FI_STRING|RDP_FI_UNICODE, NULL },
{&hf_rdp_keyboardType, 4, NULL, 0, 0, NULL },
{&hf_rdp_keyboardSubType, 4, NULL, 0, 0, NULL },
{&hf_rdp_keyboardFunctionKey, 4, NULL, 0, 0, NULL },
{&hf_rdp_imeFileName, 64, NULL, 0, 0, NULL },
{&hf_rdp_postBeta2ColorDepth, 2, NULL, 0, 0, NULL },
{&hf_rdp_clientProductId, 2, NULL, 0, 0, NULL },
{&hf_rdp_serialNumber, 4, NULL, 0, 0, NULL },
{&hf_rdp_highColorDepth, 2, NULL, 0, 0, NULL },
{&hf_rdp_supportedColorDepths, 2, NULL, 0, 0, NULL },
{&hf_rdp_earlyCapabilityFlags, 2, NULL, 0, 0, NULL },
{&hf_rdp_clientDigProductId, 64, NULL, 0, RDP_FI_STRING|RDP_FI_UNICODE, NULL },
{&hf_rdp_connectionType, 1, NULL, 0, 0, NULL },
{&hf_rdp_pad1octet, 1, NULL, 0, 0, NULL },
{&hf_rdp_serverSelectedProtocol, 4, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t security_fields[] = {
{&hf_rdp_headerType, 2, NULL, 0, 0, NULL },
{&hf_rdp_headerLength, 2, NULL, 0, 0, NULL },
{&hf_rdp_encryptionMethods, 4, NULL, 0, 0, NULL },
{&hf_rdp_extEncryptionMethods, 4, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t cluster_fields[] = {
{&hf_rdp_headerType, 2, NULL, 0, 0, NULL },
{&hf_rdp_headerLength, 2, NULL, 0, 0, NULL },
{&hf_rdp_cluster_flags, 4, NULL, 0, 0, NULL },
{&hf_rdp_redirectedSessionId, 4, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t msgchannel_fields[] = {
{&hf_rdp_headerType, 2, NULL, 0, 0, NULL },
{&hf_rdp_headerLength, 2, NULL, 0, 0, NULL },
{&hf_rdp_msgChannelFlags, 4, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t monitor_fields[] = {
{&hf_rdp_headerType, 2, NULL, 0, 0, NULL },
{&hf_rdp_headerLength, 2, NULL, 0, 0, NULL },
{&hf_rdp_monitorCount, 4, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t monitorex_fields[] = {
{&hf_rdp_headerType, 2, NULL, 0, 0, NULL },
{&hf_rdp_headerLength, 2, NULL, 0, 0, NULL },
{&hf_rdp_monitorExFlags, 4, NULL, 0, 0, NULL },
{&hf_rdp_monitorAttributeSize, 4, NULL, 0, 0, NULL },
{&hf_rdp_monitorCount, 4, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t multitransport_fields[] = {
{&hf_rdp_headerType, 2, NULL, 0, 0, NULL },
{&hf_rdp_headerLength, 2, NULL, 0, 0, NULL },
{&hf_rdp_multiTransportFlags, 4, NULL, 0, 0, NULL },
FI_TERMINATOR
};
tree = dissect_rdp(tvb, pinfo, tree);
rdp_info = rdp_get_conversation_data(pinfo);
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "ClientData");
pi = proto_tree_add_item(tree, hf_rdp_ClientData, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(pi, ett_rdp_ClientData);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
type = tvb_get_letohs(tvb, offset);
length = tvb_get_letohs(tvb, offset+2);
#if 0
printf("offset=%d, type=%x, length=%d, remaining=%d\n",
offset, type, length, tvb_captured_length_remaining(tvb, offset));
#endif
switch(type) {
case CS_CORE:
pi = proto_tree_add_item(tree, hf_rdp_clientCoreData, tvb, offset, length, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_clientCoreData);
dissect_rdp_fields(tvb, offset, pinfo, next_tree, core_fields, length);
break;
case CS_SECURITY:
pi = proto_tree_add_item(tree, hf_rdp_clientSecurityData, tvb, offset, length, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_clientSecurityData);
dissect_rdp_fields(tvb, offset, pinfo, next_tree, security_fields, 0);
break;
case CS_NET:
dissect_rdp_clientNetworkData(tvb, offset, pinfo, tree, length, rdp_info);
break;
case CS_CLUSTER:
pi = proto_tree_add_item(tree, hf_rdp_clientClusterData, tvb, offset, length, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_clientClusterData);
dissect_rdp_fields(tvb, offset, pinfo, next_tree, cluster_fields, 0);
break;
case CS_MONITOR:
pi = proto_tree_add_item(tree, hf_rdp_clientMonitorData, tvb, offset, length, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_clientMonitorData);
dissect_rdp_fields(tvb, offset, pinfo, next_tree, monitor_fields, 0);
break;
case CS_MONITOR_EX:
pi = proto_tree_add_item(tree, hf_rdp_clientMonitorExData, tvb, offset, length, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_clientMonitorExData);
dissect_rdp_fields(tvb, offset, pinfo, next_tree, monitorex_fields, 0);
break;
case CS_MCS_MSGCHANNEL:
pi = proto_tree_add_item(tree, hf_rdp_clientMsgChannelData, tvb, offset, length, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_clientMsgChannelData);
dissect_rdp_fields(tvb, offset, pinfo, next_tree, msgchannel_fields, 0);
break;
case CS_MULTITRANSPORT:
pi = proto_tree_add_item(tree, hf_rdp_clientMultiTransportData, tvb, offset, length, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_clientMultiTransportData);
dissect_rdp_fields(tvb, offset, pinfo, next_tree, multitransport_fields, 0);
break;
default:
pi = proto_tree_add_item(tree, hf_rdp_clientUnknownData, tvb, offset, length, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_clientUnknownData);
dissect_rdp_fields(tvb, offset, pinfo, next_tree, header_fields, 0);
break;
}
offset += MAX(4, length);
}
}
static void
dissect_rdp_ServerData(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
int offset = 0;
proto_item *pi;
proto_tree *next_tree;
guint16 type;
guint length;
guint32 serverRandomLen = 0;
guint32 serverCertLen = 0;
guint32 encryptionMethod = 0;
guint32 encryptionLevel = 0;
guint32 channelCount = 0;
guint32 channelId = 0;
guint i;
rdp_conv_info_t *rdp_info;
rdp_field_info_t header_fields[] = {
{&hf_rdp_headerType, 2, NULL, 0, 0, NULL },
{&hf_rdp_headerLength, 2, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t sc_fields[] = {
{&hf_rdp_headerType, 2, NULL, 0, 0, NULL },
{&hf_rdp_headerLength, 2, NULL, 0, 0, NULL },
{&hf_rdp_versionMajor, 2, NULL, 0, 0, NULL },
{&hf_rdp_versionMinor, 2, NULL, 0, 0, NULL },
{&hf_rdp_clientRequestedProtocols, 4, NULL, 0, 0, NULL },
{&hf_rdp_earlyCapabilityFlags, 2, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t ss_fields[] = {
{&hf_rdp_headerType, 2, NULL, 0, 0, NULL },
{&hf_rdp_headerLength, 2, NULL, 0, 0, NULL },
{&hf_rdp_encryptionMethod, 4, &encryptionMethod, 0, 0, NULL },
{&hf_rdp_encryptionLevel, 4, &encryptionLevel, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t encryption_fields[] = {
{&hf_rdp_serverRandomLen, 4, &serverRandomLen, 0, 0, NULL },
{&hf_rdp_serverCertLen, 4, &serverCertLen, 0, 0, NULL },
{&hf_rdp_serverRandom, 0, &serverRandomLen, 0, 0, NULL },
{&hf_rdp_serverCertificate, 0, &serverCertLen, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t sn_fields[] = {
{&hf_rdp_headerType, 2, NULL, 0, 0, NULL },
{&hf_rdp_headerLength, 2, NULL, 0, 0, NULL },
{&hf_rdp_MCSChannelId, 2, &channelId, 0, 0, NULL },
{&hf_rdp_channelCount, 2, &channelCount, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t array_fields[] = {
{&hf_rdp_channelIdArray, 0 , NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t channel_fields[] = {
{&hf_rdp_MCSChannelId, 2, &channelId, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t pad_fields[] = {
{&hf_rdp_Pad, 2, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t msgchannel_fields[] = {
{&hf_rdp_headerType, 2, NULL, 0, 0, NULL },
{&hf_rdp_headerLength, 2, NULL, 0, 0, NULL },
{&hf_rdp_msgChannelId, 2, NULL, 0, 0, NULL },
FI_TERMINATOR
};
rdp_field_info_t multitransport_fields[] = {
{&hf_rdp_headerType, 2, NULL, 0, 0, NULL },
{&hf_rdp_headerLength, 2, NULL, 0, 0, NULL },
{&hf_rdp_multiTransportFlags, 4, NULL, 0, 0, NULL },
FI_TERMINATOR
};
tree = dissect_rdp(tvb, pinfo, tree);
rdp_info = rdp_get_conversation_data(pinfo);
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "ServerData");
pi = proto_tree_add_item(tree, hf_rdp_ServerData, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(pi, ett_rdp_ServerData);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
type = tvb_get_letohs(tvb, offset);
length = tvb_get_letohs(tvb, offset+2);
switch(type) {
case SC_CORE:
pi = proto_tree_add_item(tree, hf_rdp_serverCoreData, tvb, offset, length, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_serverCoreData);
dissect_rdp_fields(tvb, offset, pinfo, next_tree, sc_fields, length);
break;
case SC_SECURITY: {
gint lcl_offset;
pi = proto_tree_add_item(tree, hf_rdp_serverSecurityData, tvb, offset, length, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_serverSecurityData);
lcl_offset = dissect_rdp_fields(tvb, offset, pinfo, next_tree, ss_fields, 0);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "Encryption: %s (%s)",
val_to_str_const(encryptionMethod, rdp_encryptionMethod_vals, "Unknown"),
val_to_str_const(encryptionLevel, rdp_encryptionLevel_vals, "Unknown"));
if ((encryptionLevel != 0) || (encryptionMethod != 0)) {
dissect_rdp_fields(tvb, lcl_offset, pinfo, next_tree, encryption_fields, 0);
}
rdp_info->encryptionMethod = encryptionMethod;
rdp_info->encryptionLevel = encryptionLevel;
break;
}
case SC_NET: {
gint lcl_offset;
pi = proto_tree_add_item(tree, hf_rdp_serverNetworkData, tvb, offset, length, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_serverNetworkData);
lcl_offset = dissect_rdp_fields(tvb, offset, pinfo, next_tree, sn_fields, 0);
rdp_info->staticChannelId = channelId;
register_t124_sd_dissector(pinfo, channelId, dissect_rdp_SendData, proto_rdp);
if (channelCount > 0) {
array_fields[0].fixedLength = channelCount * 2;
dissect_rdp_fields(tvb, lcl_offset, pinfo, next_tree, array_fields, 0);
if (next_tree)
next_tree = proto_item_add_subtree(next_tree->last_child, ett_rdp_channelIdArray);
for (i = 0; i < channelCount; i++) {
lcl_offset = dissect_rdp_fields(tvb, lcl_offset, pinfo, next_tree, channel_fields, 0);
if (i < MAX_CHANNELS)
rdp_info->channels[i].value = channelId;
register_t124_sd_dissector(pinfo, channelId, dissect_rdp_SendData, proto_rdp);
}
if (channelCount % 2)
dissect_rdp_fields(tvb, lcl_offset, pinfo, next_tree, pad_fields, 0);
}
break;
}
case SC_MCS_MSGCHANNEL:
pi = proto_tree_add_item(tree, hf_rdp_serverMsgChannelData, tvb, offset, length, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_serverMsgChannelData);
dissect_rdp_fields(tvb, offset, pinfo, next_tree, msgchannel_fields, length);
break;
case SC_MULTITRANSPORT:
pi = proto_tree_add_item(tree, hf_rdp_serverMultiTransportData, tvb, offset, length, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_serverMultiTransportData);
dissect_rdp_fields(tvb, offset, pinfo, next_tree, multitransport_fields, length);
break;
default:
pi = proto_tree_add_item(tree, hf_rdp_serverUnknownData, tvb, offset, length, ENC_NA);
next_tree = proto_item_add_subtree(pi, ett_rdp_serverUnknownData);
dissect_rdp_fields(tvb, offset, pinfo, next_tree, header_fields, 0);
break;
}
offset += MAX(4, length);
}
}
void
proto_register_rdp(void) {
static hf_register_info hf[] = {
{ &hf_rdp_ClientData,
{ "ClientData", "rdp.clientData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_SendData,
{ "SendData", "rdp.sendData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientCoreData,
{ "clientCoreData", "rdp.client.coreData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientSecurityData,
{ "clientSecurityData", "rdp.client.securityData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientNetworkData,
{ "clientNetworkData", "rdp.client.networkData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientClusterData,
{ "clientClusterData", "rdp.client.clusterData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientMonitorData,
{ "clientMonitorData", "rdp.client.monitorData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientMsgChannelData,
{ "clientMsgChannelData", "rdp.client.msgChannelData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientMonitorExData,
{ "clientMonitorExData", "rdp.client.monitorExData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientMultiTransportData,
{ "clientMultiTransportData", "rdp.client.multiTransportData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientUnknownData,
{ "clientUnknownData", "rdp.unknownData.client",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_ServerData,
{ "ServerData", "rdp.serverData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_serverCoreData,
{ "serverCoreData", "rdp.server.coreData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_serverSecurityData,
{ "serverSecurityData", "rdp.server.securityData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_serverNetworkData,
{ "serverNetworkData", "rdp.server.networkData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_serverMsgChannelData,
{ "serverMsgChannelData", "rdp.server.msgChannelData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_serverMultiTransportData,
{ "serverMultiTransportData", "rdp.server.multiTransportData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_serverUnknownData,
{ "serverUnknownData", "rdp.unknownData.server",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_securityExchangePDU,
{ "securityExchangePDU", "rdp.securityExchangePDU",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientInfoPDU,
{ "clientInfoPDU", "rdp.clientInfoPDU",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_validClientLicenseData,
{ "validClientLicenseData", "rdp.validClientLicenseData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_headerType,
{ "headerType", "rdp.header.type",
FT_UINT16, BASE_HEX, VALS(rdp_headerType_vals), 0,
NULL, HFILL }},
{ &hf_rdp_headerLength,
{ "headerLength", "rdp.header.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_versionMajor,
{ "versionMajor", "rdp.version.major",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_versionMinor,
{ "versionMinor", "rdp.version.minor",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_desktopWidth,
{ "desktopWidth", "rdp.desktop.width",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_desktopHeight,
{ "desktopHeight", "rdp.desktop.height",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_colorDepth,
{ "colorDepth", "rdp.colorDepth",
FT_UINT16, BASE_HEX, VALS(rdp_colorDepth_vals), 0,
NULL, HFILL }},
{ &hf_rdp_SASSequence,
{ "SASSequence", "rdp.SASSequence",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_keyboardLayout,
{ "keyboardLayout", "rdp.keyboardLayout",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientBuild,
{ "clientBuild", "rdp.client.build",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientName,
{ "clientName", "rdp.client.name",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_keyboardType,
{ "keyboardType", "rdp.keyboard.type",
FT_UINT32, BASE_DEC, VALS(rdp_keyboardType_vals), 0,
NULL, HFILL }},
{ &hf_rdp_keyboardSubType,
{ "keyboardSubType", "rdp.keyboard.subtype",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_keyboardFunctionKey,
{ "keyboardFunctionKey", "rdp.keyboard.functionkey",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_imeFileName,
{ "imeFileName", "rdp.imeFileName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_postBeta2ColorDepth,
{ "postBeta2ColorDepth", "rdp.postBeta2ColorDepth",
FT_UINT16, BASE_HEX, VALS(rdp_colorDepth_vals), 0,
NULL, HFILL }},
{ &hf_rdp_clientProductId,
{ "clientProductId", "rdp.client.productId",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_serialNumber,
{ "serialNumber", "rdp.serialNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_highColorDepth,
{ "highColorDepth", "rdp.highColorDepth",
FT_UINT16, BASE_HEX, VALS(rdp_highColorDepth_vals), 0,
NULL, HFILL }},
{ &hf_rdp_supportedColorDepths,
{ "supportedColorDepths", "rdp.supportedColorDepths",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_earlyCapabilityFlags,
{ "earlyCapabilityFlags", "rdp.earlyCapabilityFlags",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientDigProductId,
{ "clientDigProductId", "rdp.client.digProductId",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_connectionType,
{ "connectionType", "rdp.connectionType",
FT_UINT8, BASE_DEC, VALS(rdp_connectionType_vals), 0,
NULL, HFILL }},
{ &hf_rdp_pad1octet,
{ "pad1octet", "rdp.pad1octet",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_serverSelectedProtocol,
{ "serverSelectedProtocol", "rdp.serverSelectedProtocol",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_encryptionMethods,
{ "encryptionMethods", "rdp.encryptionMethods",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_extEncryptionMethods,
{ "extEncryptionMethods", "rdp.extEncryptionMethods",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_cluster_flags,
{ "clusterFlags", "rdp.clusterFlags",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_redirectedSessionId,
{ "redirectedSessionId", "rdp.redirectedSessionId",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_msgChannelFlags,
{ "msgChannelFlags", "rdp.msgChannelFlags",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_msgChannelId,
{ "msgChannelId", "rdp.msgChannelId",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_monitorExFlags,
{ "monitorExFlags", "rdp.monitorExFlags",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_monitorAttributeSize,
{ "monitorAttributeSize", "rdp.monitorAttributeSize",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_monitorCount,
{ "monitorCount", "rdp.monitorCount",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_multiTransportFlags,
{ "multiTransportFlags", "rdp.multiTransportFlags",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_encryptionMethod,
{ "encryptionMethod", "rdp.encryptionMethod",
FT_UINT32, BASE_HEX, VALS(rdp_encryptionMethod_vals), 0,
NULL, HFILL }},
{ &hf_rdp_encryptionLevel,
{ "encryptionLevel", "rdp.encryptionLevel",
FT_UINT32, BASE_HEX, VALS(rdp_encryptionLevel_vals), 0,
NULL, HFILL }},
{ &hf_rdp_serverRandomLen,
{ "serverRandomLen", "rdp.serverRandomLen",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_serverCertLen,
{ "serverCertLen", "rdp.serverCertLen",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_serverRandom,
{ "serverRandom", "rdp.serverRandom",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_serverCertificate,
{ "serverCertificate", "rdp.serverCertificate",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientRequestedProtocols,
{ "clientRequestedProtocols", "rdp.client.requestedProtocols",
FT_UINT32, BASE_HEX, VALS(rdp_requestedProtocols_vals), 0,
NULL, HFILL }},
{ &hf_rdp_MCSChannelId,
{ "MCSChannelId", "rdp.MCSChannelId",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_channelCount,
{ "channelCount", "rdp.channelCount",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_channelIdArray,
{ "channelIdArray", "rdp.channelIdArray",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_Pad,
{ "Pad", "rdp.Pad",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_flags,
{ "flags", "rdp.flags",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_channelFlags,
{ "channelFlags", "rdp.channelFlags",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_flagsPkt,
{ "flagsPkt", "rdp.flags.pkt",
FT_UINT16, BASE_HEX, VALS(rdp_flagsPkt_vals), SEC_PKT_MASK,
NULL, HFILL }},
{ &hf_rdp_flagsEncrypt,
{ "flagsEncrypt", "rdp.flags.encrypt",
FT_UINT16, BASE_HEX, NULL, SEC_ENCRYPT,
NULL, HFILL }},
{ &hf_rdp_flagsResetSeqno,
{ "flagsResetSeqno", "rdp.flags.resetseqno",
FT_UINT16, BASE_HEX, NULL, SEC_RESET_SEQNO,
NULL, HFILL }},
{ &hf_rdp_flagsIgnoreSeqno,
{ "flagsIgnoreSeqno", "rdp.flags.ignoreseqno",
FT_UINT16, BASE_HEX, NULL, SEC_IGNORE_SEQNO,
NULL, HFILL }},
{ &hf_rdp_flagsLicenseEncrypt,
{ "flagsLicenseEncrypt", "rdp.flags.licenseencrypt",
FT_UINT16, BASE_HEX, NULL, SEC_LICENSE_ENCRYPT_CS,
NULL, HFILL }},
{ &hf_rdp_flagsSecureChecksum,
{ "flagsSecureChecksum", "rdp.flags.securechecksum",
FT_UINT16, BASE_HEX, NULL, SEC_SECURE_CHECKSUM,
NULL, HFILL }},
{ &hf_rdp_flagsFlagsHiValid,
{ "flagsHiValid", "rdp.flags.flagshivalid",
FT_UINT16, BASE_HEX, NULL, SEC_FLAGSHI_VALID,
NULL, HFILL }},
{ &hf_rdp_flagsHi,
{ "flagsHi", "rdp.flagsHi",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_length,
{ "length", "rdp.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_encryptedClientRandom,
{ "encryptedClientRandom", "rdp.encryptedClientRandom",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_dataSignature,
{ "dataSignature", "rdp.dataSignature",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_fipsLength,
{ "fipsLength", "rdp.fipsLength",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_fipsVersion,
{ "fipsVersion", "rdp.fipsVersion",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_padlen,
{ "padlen", "rdp.padlen",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_codePage,
{ "codePage", "rdp.codePage",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_optionFlags,
{ "optionFlags", "rdp.optionFlags",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_cbDomain,
{ "cbDomain", "rdp.domain.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_cbUserName,
{ "cbUserName", "rdp.userName.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_cbPassword,
{ "cbPassword", "rdp.password.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_cbAlternateShell,
{ "cbAlternateShell", "rdp.alternateShell.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_cbWorkingDir,
{ "cbWorkingDir", "rdp.workingDir.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_cbClientAddress,
{ "cbClientAddress", "rdp.client.address.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_cbClientDir,
{ "cbClientDir", "rdp.client.dir.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_cbAutoReconnectLen,
{ "cbAutoReconnectLen", "rdp.autoReconnectCookie.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_domain,
{ "domain", "rdp.domain",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_userName,
{ "userName", "rdp.userName",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_password,
{ "password", "rdp.password",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_alternateShell,
{ "alternateShell", "rdp.alternateShell",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_workingDir,
{ "workingDir", "rdp.workingDir",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientAddressFamily,
{ "clientAddressFamily", "rdp.client.addressFamily",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientAddress,
{ "clientAddress", "rdp.client.address",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientDir,
{ "clientDir", "rdp.client.dir",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientTimeZone,
{ "clientTimeZone", "rdp.client.timeZone",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_clientSessionId,
{ "clientSessionId", "rdp.client.sessionId",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_performanceFlags,
{ "performanceFlags", "rdp.performanceFlags",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_autoReconnectCookie,
{ "autoReconnectCookie", "rdp.autoReconnectCookie",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_reserved1,
{ "reserved1", "rdp.reserved1",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_reserved2,
{ "reserved2", "rdp.reserved2",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_bMsgType,
{ "bMsgType", "rdp.bMsgType",
FT_UINT8, BASE_HEX, VALS(rdp_bMsgType_vals), 0,
NULL, HFILL }},
{ &hf_rdp_bVersion,
{ "bVersion", "rdp.bVersion",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_wMsgSize,
{ "wMsgSize", "rdp.wMsgSize",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_wBlobType,
{ "wBlobType", "rdp.wBlobType",
FT_UINT16, BASE_DEC, VALS(rdp_wBlobType_vals), 0,
NULL, HFILL }},
{ &hf_rdp_wBlobLen,
{ "wBlobLen", "rdp.wBlobLen",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_blobData,
{ "blobData", "rdp.blobData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_shareControlHeader,
{ "shareControlHeader", "rdp.shareControlHeader",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_channelPDUHeader,
{ "channelPDUHeader", "rdp.channelPDUHeader",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_virtualChannelData,
{ "virtualChannelData", "rdp.virtualChannelData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_totalLength,
{ "totalLength", "rdp.totalLength",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_pduType,
{ "pduType", "rdp.pduType",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_pduTypeType,
{ "pduTypeType", "rdp.pduType.type",
FT_UINT16, BASE_HEX, VALS(rdp_pduTypeType_vals), PDUTYPE_TYPE_MASK,
NULL, HFILL }},
{ &hf_rdp_pduTypeVersionLow,
{ "pduTypeVersionLow", "rdp.pduType.versionLow",
FT_UINT16, BASE_DEC, NULL, PDUTYPE_VERSIONLOW_MASK,
NULL, HFILL }},
{ &hf_rdp_pduTypeVersionHigh,
{ "pduTypeVersionHigh", "rdp.pduType.versionHigh",
FT_UINT16, BASE_DEC, NULL, PDUTYPE_VERSIONHIGH_MASK,
NULL, HFILL }},
{ &hf_rdp_pduSource,
{ "pduSource", "rdp.pduSource",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_shareId,
{ "shareId", "rdp.shareId",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_pad1,
{ "pad1", "rdp.pad1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_streamId,
{ "streamId", "rdp.streamId",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_uncompressedLength,
{ "uncompressedLength", "rdp.uncompressedLength",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_pduType2,
{ "pduType2", "rdp.pduType2",
FT_UINT8, BASE_DEC, VALS(rdp_pduType2_vals), 0,
NULL, HFILL }},
{ &hf_rdp_compressedType,
{ "compressedType", "rdp.compressedType",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_compressedTypeType,
{ "compressedTypeType", "rdp.compressedType.type",
FT_UINT8, BASE_HEX, VALS(rdp_compressionType_vals),
PacketCompressionTypeMask,
NULL, HFILL }},
{ &hf_rdp_compressedTypeCompressed,
{ "compressedTypeCompressed", "rdp.compressedType.compressed",
FT_UINT8, BASE_HEX, NULL, PACKET_COMPRESSED,
NULL, HFILL }},
{ &hf_rdp_compressedTypeAtFront,
{ "compressedTypeAtFront", "rdp.compressedType.atFront",
FT_UINT8, BASE_HEX, NULL, PACKET_AT_FRONT,
NULL, HFILL }},
{ &hf_rdp_compressedTypeFlushed,
{ "compressedTypeFlushed", "rdp.compressedType.flushed",
FT_UINT8, BASE_HEX, NULL, PACKET_FLUSHED,
NULL, HFILL }},
{ &hf_rdp_compressedLength,
{ "compressedLength", "rdp.compressedLength",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_wErrorCode,
{ "errorCode", "rdp.errorCode",
FT_UINT32, BASE_DEC, VALS(rdp_wErrorCode_vals), 0,
NULL, HFILL }},
{ &hf_rdp_wStateTransition,
{ "stateTransition", "rdp.stateTransition",
FT_UINT32, BASE_DEC, VALS(rdp_wStateTransition_vals), 0,
NULL, HFILL }},
{ &hf_rdp_numberEntries,
{ "numberEntries", "rdp.numberEntries",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_totalNumberEntries,
{ "totalNumberEntries", "rdp.totalNumberEntries",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_mapFlags,
{ "mapFlags", "rdp.mapFlags",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_fontMapFirst,
{ "fontMapFirst", "rdp.mapFlags.fontMapFirst",
FT_UINT16, BASE_HEX, NULL, FONTMAP_FIRST,
NULL, HFILL }},
{ &hf_rdp_fontMapLast,
{ "fontMapLast", "rdp.mapFlags.fontMapLast",
FT_UINT16, BASE_HEX, NULL, FONTMAP_LAST,
NULL, HFILL }},
{ &hf_rdp_entrySize,
{ "entrySize", "rdp.entrySize",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_action,
{ "action", "rdp.action",
FT_UINT16, BASE_HEX, VALS(rdp_action_vals),
0,
NULL, HFILL }},
{ &hf_rdp_grantId,
{ "grantId", "rdp.grantId",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_controlId,
{ "controlId", "rdp.controlId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_messageType,
{ "messageType", "rdp.messageType",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_targetUser,
{ "targetUser", "rdp.targetUser",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_numEntriesCache0,
{ "numEntriesCache0", "rdp.numEntriesCache0",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_numEntriesCache1,
{ "numEntriesCache1", "rdp.numEntriesCache1",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_numEntriesCache2,
{ "numEntriesCache2", "rdp.numEntriesCache2",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_numEntriesCache3,
{ "numEntriesCache3", "rdp.numEntriesCache3",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_numEntriesCache4,
{ "numEntriesCache4", "rdp.numEntriesCache4",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_totalEntriesCache0,
{ "totalEntriesCache0", "rdp.totalEntriesCache0",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_totalEntriesCache1,
{ "totalEntriesCache1", "rdp.totalEntriesCache1",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_totalEntriesCache2,
{ "totalEntriesCache2", "rdp.totalEntriesCache2",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_totalEntriesCache3,
{ "totalEntriesCache3", "rdp.totalEntriesCache3",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_totalEntriesCache4,
{ "totalEntriesCache4", "rdp.totalEntriesCache4",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_bBitMask,
{ "bBitMask", "rdp.bBitMask",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_Pad2,
{ "Pad2", "rdp.Pad2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_Pad3,
{ "Pad3", "rdp.Pad3",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
#if 0
{ &hf_rdp_Key1,
{ "Key1", "rdp.Key1",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
#endif
#if 0
{ &hf_rdp_Key2,
{ "Key2", "rdp.Key2",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
#endif
{ &hf_rdp_originatorId,
{ "originatorId", "rdp.OriginatorId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_lengthSourceDescriptor,
{ "lengthSourceDescriptor", "rdp.lengthSourceDescriptor",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_lengthCombinedCapabilities,
{ "lengthCombinedCapabilities", "rdp.lengthCombinedCapabilities",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_sourceDescriptor,
{ "sourceDescriptor", "rdp.sourceDescriptor",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_numberCapabilities,
{ "numberCapabilities", "rdp.numberCapabilities",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_pad2Octets,
{ "pad2Octets", "rdp.pad2Octets",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_capabilitySetType,
{ "capabilitySetType", "rdp.capabilitySetType",
FT_UINT16, BASE_HEX, VALS(rdp_capabilityType_vals), 0,
NULL, HFILL }},
{ &hf_rdp_capabilitySet,
{ "capabilitySet", "rdp.capabilitySet",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_lengthCapability,
{ "lengthCapability", "rdp.lengthCapability",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_capabilityData,
{ "capabilityData", "rdp.capabilityData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#if 0
{ &hf_rdp_unknownData,
{ "unknownData", "rdp.unknownData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#endif
{ &hf_rdp_notYetImplemented,
{ "notYetImplemented", "rdp.notYetImplemented",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_encrypted,
{ "encryptedData", "rdp.encryptedData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#if 0
{ &hf_rdp_compressed,
{ "compressedData", "rdp.compressedData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#endif
{ &hf_rdp_sessionId,
{ "sessionId", "rdp.sessionId",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_channelDefArray,
{ "channelDefArray", "rdp.channelDefArray",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_channelDef,
{ "channelDef", "rdp.channelDef",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_name,
{ "name", "rdp.name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_options,
{ "options", "rdp.options",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_optionsInitialized,
{ "optionsInitialized", "rdp.options.initialized",
FT_UINT32, BASE_HEX, NULL, CHANNEL_OPTION_INITIALIZED,
NULL, HFILL }},
{ &hf_rdp_optionsEncryptRDP,
{ "encryptRDP", "rdp.options.encrypt.rdp",
FT_UINT32, BASE_HEX, NULL, CHANNEL_OPTION_ENCRYPT_RDP,
NULL, HFILL }},
{ &hf_rdp_optionsEncryptSC,
{ "encryptSC", "rdp.options.encrypt.sc",
FT_UINT32, BASE_HEX, NULL, CHANNEL_OPTION_ENCRYPT_SC,
NULL, HFILL }},
{ &hf_rdp_optionsEncryptCS,
{ "encryptCS", "rdp.options.encrypt.cs",
FT_UINT32, BASE_HEX, NULL, CHANNEL_OPTION_ENCRYPT_CS,
NULL, HFILL }},
{ &hf_rdp_optionsPriHigh,
{ "priorityHigh", "rdp.options.priority.high",
FT_UINT32, BASE_HEX, NULL, CHANNEL_OPTION_PRI_HIGH,
NULL, HFILL }},
{ &hf_rdp_optionsPriMed,
{ "priorityMed", "rdp.options.priority.med",
FT_UINT32, BASE_HEX, NULL, CHANNEL_OPTION_PRI_MED,
NULL, HFILL }},
{ &hf_rdp_optionsPriLow,
{ "priorityLow", "rdp.options.priority.low",
FT_UINT32, BASE_HEX, NULL, CHANNEL_OPTION_PRI_LOW,
NULL, HFILL }},
{ &hf_rdp_optionsCompressRDP,
{ "compressRDP", "rdp.options.compress.rdp",
FT_UINT32, BASE_HEX, NULL, CHANNEL_OPTION_COMPRESS_RDP,
NULL, HFILL }},
{ &hf_rdp_optionsCompress,
{ "compress", "rdp.options.compress",
FT_UINT32, BASE_HEX, NULL, CHANNEL_OPTION_COMPRESS,
NULL, HFILL }},
{ &hf_rdp_optionsShowProtocol,
{ "showProtocol", "rdp.options.showprotocol",
FT_UINT32, BASE_HEX, NULL, CHANNEL_OPTION_SHOW_PROTOCOL,
NULL, HFILL }},
{ &hf_rdp_optionsRemoteControlPersistent,
{ "remoteControlPersistent", "rdp.options.remotecontrolpersistent",
FT_UINT32, BASE_HEX, NULL, CHANNEL_OPTION_REMOTE_CONTROL_PERSISTENT,
NULL, HFILL }},
{ &hf_rdp_channelFlagFirst,
{ "channelFlagFirst", "rdp.channelFlag.first",
FT_UINT32, BASE_HEX, NULL, CHANNEL_FLAG_FIRST,
NULL, HFILL }},
{ &hf_rdp_channelFlagLast,
{ "channelFlagLast", "rdp.channelFlag.last",
FT_UINT32, BASE_HEX, NULL, CHANNEL_FLAG_LAST,
NULL, HFILL }},
{ &hf_rdp_channelFlagShowProtocol,
{ "channelFlagShowProtocol", "rdp.channelFlag.showProtocol",
FT_UINT32, BASE_HEX, NULL, CHANNEL_FLAG_SHOW_PROTOCOL,
NULL, HFILL }},
{ &hf_rdp_channelFlagSuspend,
{ "channelFlagSuspend", "rdp.channelFlag.suspend",
FT_UINT32, BASE_HEX, NULL, CHANNEL_FLAG_SUSPEND,
NULL, HFILL }},
{ &hf_rdp_channelFlagResume,
{ "channelFlagResume", "rdp.channelFlag.resume",
FT_UINT32, BASE_HEX, NULL, CHANNEL_FLAG_RESUME,
NULL, HFILL }},
{ &hf_rdp_channelPacketCompressed,
{ "channelPacketCompressed", "rdp.channelPacket.compressed",
FT_UINT32, BASE_HEX, NULL, CHANNEL_PACKET_COMPRESSED,
NULL, HFILL }},
{ &hf_rdp_channelPacketAtFront,
{ "channelPacketAtFront", "rdp.channelPacket.atFront",
FT_UINT32, BASE_HEX, NULL, CHANNEL_PACKET_AT_FRONT,
NULL, HFILL }},
{ &hf_rdp_channelPacketFlushed,
{ "channelPacketFlushed", "rdp.channelPacket.flushed",
FT_UINT32, BASE_HEX, NULL, CHANNEL_PACKET_FLUSHED,
NULL, HFILL }},
{ &hf_rdp_channelPacketCompressionType,
{ "channelPacketCompresssionType", "rdp.channelPacket.compressionType",
FT_UINT32, BASE_HEX, VALS(rdp_channelCompressionType_vals), ChannelCompressionTypeMask,
NULL, HFILL }},
{ &hf_rdp_wYear,
{ "wYear", "rdp.wYear",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_wMonth,
{ "wMonth", "rdp.wMonth",
FT_UINT16, BASE_DEC, VALS(rdp_wMonth_vals), 0,
NULL, HFILL }},
{ &hf_rdp_wDayOfWeek,
{ "wDayOfWeek", "rdp.wDayOfWeek",
FT_UINT16, BASE_DEC, VALS(rdp_wDayOfWeek_vals), 0,
NULL, HFILL }},
{ &hf_rdp_wDay,
{ "wDay", "rdp.wDay",
FT_UINT16, BASE_DEC, VALS(rdp_wDay_vals), 0,
NULL, HFILL }},
{ &hf_rdp_wHour,
{ "wHour", "rdp.wHour",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_wMinute,
{ "wMinute", "rdp.wMinute",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_wSecond,
{ "wSecond", "rdp.wSecond",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_wMilliseconds,
{ "wMilliseconds", "rdp.wMilliseconds",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_Bias,
{ "Bias", "rdp.Bias",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_StandardBias,
{ "StandardBias", "rdp.Bias.standard",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_DaylightBias,
{ "DaylightBias", "rdp.Bias.daylight",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_StandardName,
{ "StandardName", "rdp.Name.Standard",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_StandardDate,
{ "StandardDate", "rdp.Date.Standard",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_DaylightName,
{ "DaylightName", "rdp.Name.Daylight",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_DaylightDate,
{ "DaylightDate", "rdp.Date.Daylight",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rdp_unused,
{ "Unused", "rdp.unused",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_rdp,
&ett_rdp_ClientData,
&ett_rdp_ServerData,
&ett_rdp_SendData,
&ett_rdp_capabilitySet,
&ett_rdp_channelDef,
&ett_rdp_channelDefArray,
&ett_rdp_channelFlags,
&ett_rdp_channelIdArray,
&ett_rdp_channelPDUHeader,
&ett_rdp_clientClusterData,
&ett_rdp_clientCoreData,
&ett_rdp_clientInfoPDU,
&ett_rdp_clientMonitorData,
&ett_rdp_clientMonitorExData,
&ett_rdp_clientMsgChannelData,
&ett_rdp_clientMultiTransportData,
&ett_rdp_clientNetworkData,
&ett_rdp_clientSecurityData,
&ett_rdp_clientUnknownData,
&ett_rdp_compressedType,
&ett_rdp_flags,
&ett_rdp_mapFlags,
&ett_rdp_options,
&ett_rdp_pduType,
&ett_rdp_securityExchangePDU,
&ett_rdp_serverCoreData,
&ett_rdp_serverMsgChannelData,
&ett_rdp_serverMultiTransportData,
&ett_rdp_serverNetworkData,
&ett_rdp_serverSecurityData,
&ett_rdp_serverUnknownData,
&ett_rdp_shareControlHeader,
&ett_rdp_validClientLicenseData,
&ett_rdp_StandardDate,
&ett_rdp_DaylightDate,
&ett_rdp_clientTimeZone,
};
module_t *rdp_module;
proto_rdp = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_rdp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
rdp_module = prefs_register_protocol(proto_rdp, prefs_register_rdp);
prefs_register_uint_preference(rdp_module, "tcp.port", "RDP TCP Port",
"Set the port for RDP operations (if other"
" than the default of 3389)",
10, &global_rdp_tcp_port);
}
void
proto_reg_handoff_rdp(void)
{
tpkt_handle = find_dissector("tpkt");
prefs_register_rdp();
register_t124_ns_dissector("Duca", dissect_rdp_ClientData, proto_rdp);
register_t124_ns_dissector("McDn", dissect_rdp_ServerData, proto_rdp);
}
static void
prefs_register_rdp(void) {
static guint tcp_port = 0;
if ((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_delete_uint("tcp.port", tcp_port, tpkt_handle);
tcp_port = global_rdp_tcp_port;
if ((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_add_uint("tcp.port", tcp_port, tpkt_handle);
}
