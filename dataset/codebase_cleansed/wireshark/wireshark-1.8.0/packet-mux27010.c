static void
getExtendedHeader(tvbuff_t *tvb, proto_tree *field_tree){
sizeMuxPPPHeader = tvb_get_guint8(tvb, offset);
proto_tree_add_item(field_tree, hf_mux27010_extended_header_size, tvb, offset, 1, ENC_BIG_ENDIAN);
if (sizeMuxPPPHeader > 0){
int tmpOffset = 1;
guint16 tmpStartByte = 0;
guint16 tmpLastByte = 0;
for (i=0; i < sizeMuxPPPHeader/7; i++){
switch(i){
case(0) :
proto_tree_add_item(field_tree, hf_mux27010_extended_header_msg_number_I, tvb, offset+tmpOffset, 2, ENC_BIG_ENDIAN);
tmpOffset+=2;
proto_tree_add_item(field_tree, hf_mux27010_extended_header_freq_number_I, tvb, offset+tmpOffset, 2, ENC_BIG_ENDIAN);
tmpOffset+=2;
tmpStartByte = tvb_get_guint8(tvb, tmpOffset) + sizeMuxPPPHeader + 1;
proto_tree_add_item(field_tree, hf_mux27010_extended_header_start_pos_I, tvb, offset+tmpOffset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mux27010_extended_header_start_byte_I, tvb, tmpStartByte, 1, ENC_BIG_ENDIAN);
tmpOffset+=1;
tmpLastByte = tvb_get_guint8(tvb, tmpOffset) + sizeMuxPPPHeader + 1;
proto_tree_add_item(field_tree, hf_mux27010_extended_header_end_pos_I, tvb, offset+tmpOffset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mux27010_extended_header_end_byte_I, tvb, tmpLastByte, 1, ENC_BIG_ENDIAN);
tmpOffset+=1;
proto_tree_add_item(field_tree, hf_mux27010_extended_header_flag_ended_I, tvb, offset+tmpOffset, 1, ENC_BIG_ENDIAN);
if ((tvb_get_guint8(tvb, tmpOffset) & MUX27010_EXTENDED_HEADER_NOT_ENDED) == MUX27010_EXTENDED_HEADER_NOT_ENDED)
proto_tree_add_uint_format(field_tree, hf_mux27010_extended_header_flag_ended_I, tvb, offset+tmpOffset, 1, 1, "Not Last Packet in Frequence");
else
proto_tree_add_uint_format(field_tree, hf_mux27010_extended_header_flag_ended_I, tvb, offset+tmpOffset, 1, 1, "Last Packet in Frequence");
break;
case(1) :
tmpOffset+=1;
proto_tree_add_item(field_tree, hf_mux27010_extended_header_msg_number_II, tvb, offset+tmpOffset, 2, ENC_BIG_ENDIAN);
tmpOffset+=2;
proto_tree_add_item(field_tree, hf_mux27010_extended_header_freq_number_II, tvb, offset+tmpOffset, 2, ENC_BIG_ENDIAN);
tmpOffset+=2;
tmpStartByte = tvb_get_guint8(tvb, tmpOffset) + sizeMuxPPPHeader + 1;
proto_tree_add_item(field_tree, hf_mux27010_extended_header_start_pos_II, tvb, offset+tmpOffset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mux27010_extended_header_start_byte_II, tvb, tmpStartByte, 1, ENC_BIG_ENDIAN);
tmpOffset+=1;
tmpLastByte = tvb_get_guint8(tvb, tmpOffset) + sizeMuxPPPHeader + 1;
proto_tree_add_item(field_tree, hf_mux27010_extended_header_end_pos_II, tvb, offset+tmpOffset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mux27010_extended_header_end_byte_II, tvb, tmpLastByte, 1, ENC_BIG_ENDIAN);
tmpOffset+=1;
proto_tree_add_item(field_tree, hf_mux27010_extended_header_flag_ended_II, tvb, offset+tmpOffset, 1, ENC_BIG_ENDIAN);
if ((tvb_get_guint8(tvb, tmpOffset) & MUX27010_EXTENDED_HEADER_NOT_ENDED) == MUX27010_EXTENDED_HEADER_NOT_ENDED)
proto_tree_add_uint_format(field_tree, hf_mux27010_extended_header_flag_ended_II, tvb, offset+tmpOffset, 1, 1, "Not Last Packet in Frequence");
else
proto_tree_add_uint_format(field_tree, hf_mux27010_extended_header_flag_ended_II, tvb, offset+tmpOffset, 1, 1, "Last Packet in Frequence");
break;
case(2) :
tmpOffset+=1;
proto_tree_add_item(field_tree, hf_mux27010_extended_header_msg_number_III, tvb, offset+tmpOffset, 2, ENC_BIG_ENDIAN);
tmpOffset+=2;
proto_tree_add_item(field_tree, hf_mux27010_extended_header_freq_number_III, tvb, offset+tmpOffset, 2, ENC_BIG_ENDIAN);
tmpOffset+=2;
tmpStartByte = tvb_get_guint8(tvb, tmpOffset) + sizeMuxPPPHeader + 1;
proto_tree_add_item(field_tree, hf_mux27010_extended_header_start_pos_III, tvb, offset+tmpOffset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mux27010_extended_header_start_byte_III, tvb, tmpStartByte, 1, ENC_BIG_ENDIAN);
tmpOffset+=1;
tmpLastByte = tvb_get_guint8(tvb, tmpOffset) + sizeMuxPPPHeader + 1;
proto_tree_add_item(field_tree, hf_mux27010_extended_header_end_pos_III, tvb, offset+tmpOffset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mux27010_extended_header_end_byte_III, tvb, tmpLastByte, 1, ENC_BIG_ENDIAN);
tmpOffset+=1;
proto_tree_add_item(field_tree, hf_mux27010_extended_header_flag_ended_III, tvb, offset+tmpOffset, 1, ENC_BIG_ENDIAN);
if ((tvb_get_guint8(tvb, tmpOffset) & MUX27010_EXTENDED_HEADER_NOT_ENDED) == MUX27010_EXTENDED_HEADER_NOT_ENDED)
proto_tree_add_uint_format(field_tree, hf_mux27010_extended_header_flag_ended_III, tvb, offset+tmpOffset, 1, 1, "Not Last Packet in Frequence");
else
proto_tree_add_uint_format(field_tree, hf_mux27010_extended_header_flag_ended_III, tvb, offset+tmpOffset, 1, 1, "Last Packet in Frequence");
break;
}
}
}
offset = offset + sizeMuxPPPHeader;
}
static void
getFrameDirection(tvbuff_t *tvb, proto_tree *field_tree){
direction_in_out = tvb_get_guint8(tvb, offset);
colInfoText[0] = 0;
switch (direction_in_out) {
case (0):
g_snprintf(colSourceText,sizeof(colSourceText),"Application DLCI ");
g_snprintf(colDestText,sizeof(colDestText),"Module");
proto_tree_add_uint_format(field_tree, hf_mux27010_direction, tvb, offset, 1, 0, "Direction: Application => Module");
break;
case (1):
g_snprintf(colSourceText,sizeof(colSourceText), "Module DLCI ");
g_snprintf(colDestText,sizeof(colDestText), "Application");
proto_tree_add_uint_format(field_tree, hf_mux27010_direction, tvb, offset, 1, 1, "Direction: Module => Application");
break;
default:
g_snprintf(colSourceText,sizeof(colSourceText),"Direction not valid ");
g_snprintf(colDestText,sizeof(colDestText),"Direction not valid ");
proto_tree_add_uint_format(field_tree, hf_mux27010_direction, tvb, offset, 1, 2, "Direction not valid");
break;
}
offset++;
}
static void
getFrameAddress(tvbuff_t *tvb, proto_tree *field_tree_addr){
dlci_number = tvb_get_guint8(tvb, offset);
dlci_number = dlci_number & MUX27010_DLCI_ADDRESS_FLAG;
dlci_number = dlci_number >> 2;
dlci_char[0] = dlci_number+48;
dlci_char[1] = ' ';
dlci_char[2] = '\0';
g_snprintf(colSourceText,sizeof(colSourceText),"%s %s", colSourceText, dlci_char);
proto_tree_add_item(field_tree_addr, hf_mux27010_eaaddressflag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_addr, hf_mux27010_craddressflag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_addr, hf_mux27010_dlciaddressflag, tvb, offset, 1, ENC_BIG_ENDIAN);
command_or_response = tvb_get_guint8(tvb, offset);
command_or_response = command_or_response & MUX27010_CR_ADDRESS_FLAG;
offset += 1;
}
static void
getFrameControlData(tvbuff_t *tvb, proto_tree *field_tree){
frame_type = tvb_get_guint8(tvb, offset);
frame_type = frame_type & MUX27010_FRAMETYPE_CONTROL_FLAG;
known_frame_type = 0;
switch (frame_type) {
case (MUX27010_FRAMETYPE_CONTROL_FLAG_SABM):
proto_tree_add_uint_format(field_tree, hf_mux27010_controlframetype, tvb, offset, 1, MUX27010_FRAMETYPE_CONTROL_FLAG_SABM, "Frame Type= SABM");
g_snprintf(frameTypeText,sizeof(frameTypeText),"SABM");
break;
case (MUX27010_FRAMETYPE_CONTROL_FLAG_UA):
proto_tree_add_uint_format(field_tree, hf_mux27010_controlframetype, tvb, offset, 1, MUX27010_FRAMETYPE_CONTROL_FLAG_UA, "Frame Type= UA");
g_snprintf(frameTypeText,sizeof(frameTypeText),"UA");
break;
case (MUX27010_FRAMETYPE_CONTROL_FLAG_DM):
proto_tree_add_uint_format(field_tree, hf_mux27010_controlframetype, tvb, offset, 1, MUX27010_FRAMETYPE_CONTROL_FLAG_DM, "Frame Type= DM");
g_snprintf(frameTypeText,sizeof(frameTypeText),"DM");
break;
case (MUX27010_FRAMETYPE_CONTROL_FLAG_DISC):
proto_tree_add_uint_format(field_tree, hf_mux27010_controlframetype, tvb, offset, 1, MUX27010_FRAMETYPE_CONTROL_FLAG_DISC, "Frame Type= DISC");
g_snprintf(frameTypeText,sizeof(frameTypeText),"DISC");
break;
case (MUX27010_FRAMETYPE_CONTROL_FLAG_UIH):
proto_tree_add_uint_format(field_tree, hf_mux27010_controlframetype, tvb, offset, 1, MUX27010_FRAMETYPE_CONTROL_FLAG_UIH, "Frame Type= UIH");
g_snprintf(frameTypeText,sizeof(frameTypeText),"UIH");
break;
default:
if ((MUX27010_FRAMETYPE_CONTROL_FLAG_UIH_E | MUX27010_FRAMETYPE_CONTROL_FLAG_NS | MUX27010_FRAMETYPE_CONTROL_FLAG_NR) == (frame_type | MUX27010_FRAMETYPE_CONTROL_FLAG_NS | MUX27010_FRAMETYPE_CONTROL_FLAG_NR)) {
proto_tree_add_uint_format(field_tree, hf_mux27010_controlframetype, tvb, offset, 1, MUX27010_FRAMETYPE_CONTROL_FLAG_UIH_E, "Frame Type= UIH_E");
proto_tree_add_item(field_tree, hf_mux27010_controlframetypens, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mux27010_controlframetypenr, tvb, offset, 1, ENC_BIG_ENDIAN);
g_snprintf(frameTypeText,sizeof(frameTypeText),"UIH_E");
known_frame_type = 1;
}
if ((MUX27010_FRAMETYPE_CONTROL_FLAG_RR | MUX27010_FRAMETYPE_CONTROL_FLAG_NR) == (frame_type | MUX27010_FRAMETYPE_CONTROL_FLAG_NR)) {
proto_tree_add_uint_format(field_tree, hf_mux27010_controlframetype, tvb, offset, 1, MUX27010_FRAMETYPE_CONTROL_FLAG_RR, "Frame Type= Receive Ready");
proto_tree_add_item(field_tree, hf_mux27010_controlframetypenr, tvb, offset, 1, ENC_BIG_ENDIAN);
g_snprintf(frameTypeText,sizeof(frameTypeText),"RR");
known_frame_type = 1;
}
if ((MUX27010_FRAMETYPE_CONTROL_FLAG_RNR | MUX27010_FRAMETYPE_CONTROL_FLAG_NR) == (frame_type | MUX27010_FRAMETYPE_CONTROL_FLAG_NR)) {
proto_tree_add_uint_format(field_tree, hf_mux27010_controlframetype, tvb, offset, 1, MUX27010_FRAMETYPE_CONTROL_FLAG_RNR, "Frame Type= Receive Not Ready");
proto_tree_add_item(field_tree, hf_mux27010_controlframetypenr, tvb, offset, 1, ENC_BIG_ENDIAN);
g_snprintf(frameTypeText,sizeof(frameTypeText),"RNR");
known_frame_type = 1;
}
if ((MUX27010_FRAMETYPE_CONTROL_FLAG_REJ | MUX27010_FRAMETYPE_CONTROL_FLAG_NR) == (frame_type | MUX27010_FRAMETYPE_CONTROL_FLAG_NR)) {
proto_tree_add_uint_format(field_tree, hf_mux27010_controlframetype, tvb, offset, 1, MUX27010_FRAMETYPE_CONTROL_FLAG_REJ, "Frame Type= Reject");
proto_tree_add_item(field_tree, hf_mux27010_controlframetypenr, tvb, offset, 1, ENC_BIG_ENDIAN);
g_snprintf(frameTypeText,sizeof(frameTypeText),"REJ");
known_frame_type = 1;
}
if (known_frame_type == 0) {
proto_tree_add_uint_format(field_tree, hf_mux27010_controlframetype, tvb, offset, 1, frame_type, "Frame Type= Unknown");
g_snprintf(frameTypeText,sizeof(frameTypeText),"Unknown");
}
}
g_snprintf(colInfoText,sizeof(colInfoText),"%s(", colInfoText);
g_snprintf(colInfoText,sizeof(colInfoText),"%s%s", colInfoText, frameTypeText);
g_snprintf(colInfoText,sizeof(colInfoText),"%s)", colInfoText);
proto_tree_add_item(field_tree, hf_mux27010_controlframetype, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_mux27010_pfcontrolflag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
static void
getFrameLength(tvbuff_t *tvb, proto_tree *field_tree){
length_ea = tvb_get_guint8(tvb, offset);
length_ea = length_ea & MUX27010_EA_LENGTH_FLAG;
if (length_ea == 1) {
length_info = tvb_get_guint8(tvb, offset);
length_info = length_info & MUX27010_FRAMESIZE_LENGTH_FLAG;
length_info = length_info >> 1;
proto_tree_add_item(field_tree, hf_mux27010_ealengthflag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint_format(field_tree, hf_mux27010_lengthframesize, tvb, offset, 1, length_info, "Info length: %i", length_info);
}
else {
length_info = tvb_get_guint8(tvb, offset);
length_info = length_info & MUX27010_FRAMESIZE_LENGTH_FLAG;
length_info = length_info >> 1;
offset++;
length_info_second_byte = tvb_get_guint8(tvb, offset);
length_info_second_byte = length_info_second_byte << 7;
length_info = length_info | length_info_second_byte;
offset--;
proto_tree_add_item(field_tree, hf_mux27010_ealengthflag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint_format(field_tree, hf_mux27010_lengthframesize_ea, tvb, offset, 2, length_info, "Info length: %i", length_info);
offset++;
}
offset += 1;
}
static void
getControlChannelFrameType(tvbuff_t *tvb, proto_tree *field_tree_ctr){
controlchannel_type_ea = tvb_get_guint8(tvb, offset);
controlchannel_type_ea = controlchannel_type_ea & MUX27010_EA_CONTROLCHANNEL_FRAMETYPE_FLAG;
number_of_type_frames = 0;
if (controlchannel_type_ea == 1) number_of_type_frames++;
while (controlchannel_type_ea == 0){
number_of_type_frames++;
controlchannel_type_ea = tvb_get_guint8(tvb, offset+number_of_type_frames);
controlchannel_type_ea = controlchannel_type_ea & MUX27010_EA_CONTROLCHANNEL_FRAMETYPE_FLAG;
}
controlchannel_type_cr = tvb_get_guint8(tvb, offset);
controlchannel_type_cr = controlchannel_type_cr & MUX27010_CR_CONTROLCHANNEL_FRAMETYPE_FLAG;
controlchannel_type_cr = controlchannel_type_cr >> 1;
controlchannel_type_command = tvb_get_guint8(tvb, offset);
controlchannel_type_command = controlchannel_type_command & MUX27010_COMMAND_CONTROLCHANNEL_FRAMETYPE_FLAG;
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneleaframetype, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchannelcrframetype, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchannelframetypecommand, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((controlchannel_type_command | MUX27010_EA_CONTROLCHANNEL_FRAMETYPE_FLAG | MUX27010_CR_CONTROLCHANNEL_FRAMETYPE_FLAG) == MUX27010_COMMAND_MULTIPLEXER_CLOSEDOWN){
proto_tree_add_uint_format(field_tree_ctr, hf_mux27010_controlchannelframetypecommand, tvb, offset, 1, controlchannel_type_command, "Command = Multiplexer Close Down");
g_snprintf(colInfoText,sizeof(colInfoText),"%s Multiplexer Close Down", colInfoText);
}
if ((controlchannel_type_command | MUX27010_EA_CONTROLCHANNEL_FRAMETYPE_FLAG | MUX27010_CR_CONTROLCHANNEL_FRAMETYPE_FLAG) == MUX27010_COMMAND_TEST_COMMAND){
proto_tree_add_uint_format(field_tree_ctr, hf_mux27010_controlchannelframetypecommand, tvb, offset, 1, controlchannel_type_command, "Command = Test Command");
g_snprintf(colInfoText,sizeof(colInfoText),"%s Test Command", colInfoText);
}
if ((controlchannel_type_command | MUX27010_EA_CONTROLCHANNEL_FRAMETYPE_FLAG | MUX27010_CR_CONTROLCHANNEL_FRAMETYPE_FLAG) == MUX27010_COMMAND_POWER_SAVING_CONTROL){
proto_tree_add_uint_format(field_tree_ctr, hf_mux27010_controlchannelframetypecommand, tvb, offset, 1, controlchannel_type_command, "Command = Power Saving Control");
g_snprintf(colInfoText,sizeof(colInfoText),"%s Power Saving Control", colInfoText);
}
if ((controlchannel_type_command | MUX27010_EA_CONTROLCHANNEL_FRAMETYPE_FLAG | MUX27010_CR_CONTROLCHANNEL_FRAMETYPE_FLAG) == MUX27010_COMMAND_NON_SUPPORTED_COMMAND_REPSONSE){
proto_tree_add_uint_format(field_tree_ctr, hf_mux27010_controlchannelframetypecommand, tvb, offset, 1, controlchannel_type_command, "Command = Non-supported Command Response");
g_snprintf(colInfoText,sizeof(colInfoText),"%s Non-supported Command Response", colInfoText);
}
if ((controlchannel_type_command | MUX27010_EA_CONTROLCHANNEL_FRAMETYPE_FLAG | MUX27010_CR_CONTROLCHANNEL_FRAMETYPE_FLAG) == MUX27010_COMMAND_MODEM_STATUS_COMMAND){
proto_tree_add_uint_format(field_tree_ctr, hf_mux27010_controlchannelframetypecommand, tvb, offset, 1, controlchannel_type_command, "Command = Modem Status Command");
g_snprintf(colInfoText,sizeof(colInfoText),"%s Modem Status Command", colInfoText);
}
if ((controlchannel_type_command | MUX27010_EA_CONTROLCHANNEL_FRAMETYPE_FLAG | MUX27010_CR_CONTROLCHANNEL_FRAMETYPE_FLAG) == MUX27010_COMMAND_PARAMETER_NEGOTIATION){
proto_tree_add_uint_format(field_tree_ctr, hf_mux27010_controlchannelframetypecommand, tvb, offset, 1, controlchannel_type_command, "Command = Parameter Negotiation");
g_snprintf(colInfoText,sizeof(colInfoText),"%s Parameter Negotiation", colInfoText);
}
if (controlchannel_type_cr == 1) {
g_snprintf(colInfoText,sizeof(colInfoText),"%s (Command)", colInfoText);
}
else{
g_snprintf(colInfoText,sizeof(colInfoText),"%s (Response)", colInfoText);
}
offset +=number_of_type_frames;
}
static void
getControlChannelLength(tvbuff_t *tvb, proto_tree *field_tree_ctr) {
controlchannel_length_ea = tvb_get_guint8(tvb, offset);
controlchannel_length_ea = controlchannel_length_ea & MUX27010_EA_CONTROLCHANNEL_LENGTH_FLAG;
number_of_length_frames = 0;
if (controlchannel_length_ea == 1) number_of_length_frames++;
while (controlchannel_length_ea == 0){
number_of_length_frames++;
controlchannel_length_ea = tvb_get_guint8(tvb, offset+number_of_length_frames);
controlchannel_length_ea = controlchannel_length_ea & MUX27010_EA_CONTROLCHANNEL_LENGTH_FLAG;
}
controlchannel_length_value = tvb_get_guint8(tvb, offset);
controlchannel_length_value = controlchannel_length_value & MUX27010_LENGTHFIELD_CONTROLCHANNEL_LENGTH_FLAG;
controlchannel_length_value = controlchannel_length_value >> 1;
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchannelealength, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchannellengthfield, tvb, offset, 1, ENC_BIG_ENDIAN);
offset +=number_of_length_frames;
}
static void
getControlChannelValues(tvbuff_t *tvb, proto_tree *field_tree_ctr){
if ((controlchannel_type_command | MUX27010_EA_CONTROLCHANNEL_FRAMETYPE_FLAG | MUX27010_CR_CONTROLCHANNEL_FRAMETYPE_FLAG) == MUX27010_COMMAND_TEST_COMMAND){
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluetestcommandversion, tvb, offset, 1, ENC_BIG_ENDIAN);
controlchannel_iei = tvb_get_guint8(tvb, offset);
if (controlchannel_iei == MUX27010_VALUE_CONTROLCHANNEL_TEST_IEI_TE) {
proto_tree_add_uint_format(field_tree_ctr, hf_mux27010_controlchannelvalue, tvb, offset, 1, controlchannel_value, "IEI coding: TEMUX_VERSION");
}
if (controlchannel_iei == MUX27010_VALUE_CONTROLCHANNEL_TEST_IEI_MS){
proto_tree_add_uint_format(field_tree_ctr, hf_mux27010_controlchannelvalue, tvb, offset, 1, controlchannel_value, "IEI coding: MSMUX_VERSION");
}
proto_tree_add_uint_format(field_tree_ctr, hf_mux27010_controlchannelvalue, tvb, offset+1, controlchannel_length_value-1, controlchannel_value, "Value (ASCII): %s", tvb_get_ephemeral_string(tvb, offset+1,controlchannel_length_value-1));
}
if ((controlchannel_type_command | MUX27010_EA_CONTROLCHANNEL_FRAMETYPE_FLAG | MUX27010_CR_CONTROLCHANNEL_FRAMETYPE_FLAG) == MUX27010_COMMAND_POWER_SAVING_CONTROL){
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvalue, tvb, offset, 1, ENC_BIG_ENDIAN);
controlchannel_psc = tvb_get_guint8(tvb, offset);
if (controlchannel_type_cr == 0 && controlchannel_psc == 0)
proto_tree_add_uint_format(field_tree_ctr, hf_mux27010_controlchanneldetailedvalue, tvb, offset, controlchannel_length_value, controlchannel_value, "Response: Failure");
if (controlchannel_type_cr == 0 && controlchannel_psc == 1)
proto_tree_add_uint_format(field_tree_ctr, hf_mux27010_controlchanneldetailedvalue, tvb, offset, controlchannel_length_value, controlchannel_value, "Response: Success");
}
if ((controlchannel_type_command | MUX27010_EA_CONTROLCHANNEL_FRAMETYPE_FLAG | MUX27010_CR_CONTROLCHANNEL_FRAMETYPE_FLAG) == MUX27010_COMMAND_NON_SUPPORTED_COMMAND_REPSONSE){
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvalue, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint_format(field_tree_ctr, hf_mux27010_controlchanneldetailedvalue, tvb, offset, controlchannel_length_value, controlchannel_value, "Non-supported Command");
}
if ((controlchannel_type_command | MUX27010_EA_CONTROLCHANNEL_FRAMETYPE_FLAG | MUX27010_CR_CONTROLCHANNEL_FRAMETYPE_FLAG) == MUX27010_COMMAND_MODEM_STATUS_COMMAND){
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluemscdlci, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluemscv24fc, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluemscv24rtc, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluemscv24rtr, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluemscv24ring, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluemscv24dcd, tvb, offset+1, 1, ENC_BIG_ENDIAN);
if (controlchannel_length_value == 3) {
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluemscbreak, tvb, offset+2, 1, ENC_BIG_ENDIAN);
}
}
if ((controlchannel_type_command | MUX27010_EA_CONTROLCHANNEL_FRAMETYPE_FLAG | MUX27010_CR_CONTROLCHANNEL_FRAMETYPE_FLAG) == MUX27010_COMMAND_PARAMETER_NEGOTIATION){
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluepndlci, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluepnframetype, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluepncl, tvb, offset+1, 1, ENC_BIG_ENDIAN);
controlchannel_cl = tvb_get_guint8(tvb, offset+1);
controlchannel_cl = controlchannel_cl & MUX27010_VALUE_CONTROLCHANNEL_PN_CL;
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluepnprio, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluepntimer, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluepnframesize, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluepnna, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree_ctr, hf_mux27010_controlchanneldetailedvaluepnwinsize, tvb, offset+7, 1, ENC_BIG_ENDIAN);
}
offset += controlchannel_length_value;
}
static void
getFrameInformation(tvbuff_t *tvb, proto_tree *field_tree){
char information_field_content[52];
char *information_field, *save_information_field_ptr;
information_field = tvb_get_string(tvb,offset,length_info);
save_information_field_ptr = information_field;
tmp = 0;
for (i = 0; i<length_info && i<(sizeof(information_field_content)-1); i++) {
if (*information_field != 0x0a && *information_field != 0x0d){
information_field_content[i] = *information_field;
}
else {
information_field_content[i] =' ';
}
information_field++;
}
information_field_content[i] = '\0';
g_snprintf(colInfoText,sizeof(colInfoText),"%s %s", colInfoText, information_field_content);
information_field = save_information_field_ptr;
proto_tree_add_uint_format(field_tree, hf_mux27010_information, tvb, offset, length_info, controlchannel_type_command, "Information: %s",information_field);
g_free(information_field);
offset +=length_info;
}
static void
dissect_mux27010(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_item *tf = NULL, *tf_extended_header, *tf_addr, *tf_ctr;
proto_tree *mux27010_tree = NULL;
proto_tree *field_tree, *field_tree_extended_header, *field_tree_addr, *field_tree_ctr;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_MUX27010);
col_clear(pinfo->cinfo,COL_INFO);
col_add_fstr(pinfo->cinfo, COL_INFO, "%d > %d Info Type:[]",pinfo->srcport, pinfo->destport);
offset = 0;
colInfoText[0] = 0;
colDestText[0] = 0;
colSourceText[0] = 0;
frameTypeText[0] = 0;
ti = proto_tree_add_item(tree, proto_mux27010, tvb, 0, -1, ENC_NA);
mux27010_tree = proto_item_add_subtree(ti, ett_mux27010);
sizeOfOneMuxPPPHeader = 7;
tf_extended_header = proto_tree_add_item(mux27010_tree, hf_mux27010_extended_header, tvb, offset, 1, ENC_BIG_ENDIAN);
field_tree_extended_header = proto_item_add_subtree(tf_extended_header, ett_mux27010_extended_header);
getExtendedHeader(tvb, field_tree_extended_header);
offset++;
getFrameDirection(tvb, mux27010_tree);
proto_tree_add_item(mux27010_tree, hf_mux27010, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
tf_addr = proto_tree_add_item(mux27010_tree, hf_mux27010_address, tvb, offset, 1, ENC_BIG_ENDIAN);
field_tree_addr = proto_item_add_subtree(tf_addr, ett_mux27010_address);
getFrameAddress(tvb, field_tree_addr);
tf = proto_tree_add_item(mux27010_tree, hf_mux27010_control, tvb, offset, 1, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(tf, ett_mux27010_control);
getFrameControlData(tvb, field_tree);
length_info = 0;
if (strcmp(frameTypeText,"RR")!= 0 && strcmp(frameTypeText,"RNR")!= 0 && strcmp(frameTypeText,"REJ")!= 0){
tf = proto_tree_add_item(mux27010_tree, hf_mux27010_length, tvb, offset, 1, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(tf, ett_mux27010_length);
getFrameLength(tvb, field_tree);
}
if (dlci_number == 0) {
if (length_info > 0) {
tf = proto_tree_add_item(mux27010_tree, hf_mux27010_controlchannel, tvb, offset, 1, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(tf, ett_mux27010_controlchannel);
tf_ctr = proto_tree_add_item(field_tree, hf_mux27010_controlchannelframetype, tvb, offset, number_of_type_frames, ENC_BIG_ENDIAN);
field_tree_ctr = proto_item_add_subtree(tf_ctr, ett_mux27010_controlchannelframetype);
getControlChannelFrameType(tvb, field_tree_ctr);
tf_ctr = proto_tree_add_item(field_tree, hf_mux27010_controlchannellength, tvb, offset, number_of_length_frames, ENC_BIG_ENDIAN);
field_tree_ctr = proto_item_add_subtree(tf_ctr, ett_mux27010_controlchannellength);
getControlChannelLength(tvb, field_tree_ctr);
if (controlchannel_length_value > 0) {
tf_ctr = proto_tree_add_uint_format(field_tree, hf_mux27010_controlchannelvalue, tvb, offset, controlchannel_length_value, controlchannel_value, "Data: %i Byte(s)", controlchannel_length_value);
field_tree_ctr = proto_item_add_subtree(tf_ctr, ett_mux27010_controlchannelvalue);
getControlChannelValues(tvb, field_tree_ctr);
}
}
}
if (dlci_number != 0 && length_info > 0) {
tf = proto_tree_add_item(mux27010_tree, hf_mux27010_information, tvb, offset, 1, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(tf, ett_mux27010_information);
if (sizeMuxPPPHeader > 0){
guint16 tmpOffset = 1;
guint16 tmpOffsetBegin = 1;
guint16 tmpOffsetEnd = 1;
guint16 msg_seqid;
guint16 msg_num;
guint8 msg_start;
guint8 msg_end;
guint8 msg_flag;
fragment_data *frag_msg = NULL;
tvbuff_t *new_tvb = NULL;
tvbuff_t *next_tvb2 = NULL;
packet_info pinfo_tmp;
for (i = 0; i < sizeMuxPPPHeader/7; i++){
tmpOffset = 7;
tmpOffset = (i * tmpOffset)+1;
msg_seqid = tvb_get_ntohs(tvb, tmpOffset); tmpOffset += 2;
msg_num = tvb_get_ntohs(tvb, tmpOffset); tmpOffset += 2;
msg_start = tvb_get_guint8(tvb, tmpOffset); tmpOffset += 1;
msg_end = tvb_get_guint8(tvb, tmpOffset); tmpOffset += 1;
msg_flag = tvb_get_guint8(tvb, tmpOffset); tmpOffset += 1;
if (msg_end <= msg_start) {
proto_item *pi;
pi = proto_tree_add_text(field_tree, tvb, tmpOffset-3, 2,
"Message start and end are illogical, aborting dissection");
expert_add_info_format(pinfo, pi, PI_MALFORMED, PI_ERROR,
"Message start and end are illogical");
continue;
}
tmpOffsetBegin = sizeMuxPPPHeader + 1 + msg_start;
tmpOffsetEnd = sizeMuxPPPHeader + 1 + msg_end;
pinfo->fragmented = TRUE;
memcpy(&pinfo_tmp, pinfo, sizeof(*pinfo));
frag_msg = fragment_add_seq_check(tvb, tmpOffsetBegin, pinfo,
msg_seqid,
msg_fragment_table,
msg_reassembled_table,
msg_num,
(tmpOffsetEnd-tmpOffsetBegin)+1,
msg_flag);
new_tvb = process_reassembled_data(tvb, tmpOffsetBegin, pinfo,
"Reassembled Message", frag_msg, &msg_frag_items,
NULL, mux27010_tree);
if (!frag_msg) {
g_snprintf(colInfoText, sizeof(colInfoText), "%s [Splitted Msg]", colInfoText);
}
if (new_tvb) {
next_tvb2 = tvb_new_subset_remaining(new_tvb, 1);
call_dissector(ppp_handle, next_tvb2, pinfo, tree);
}
pinfo = &pinfo_tmp;
}
}
getFrameInformation(tvb, field_tree);
}
tf = proto_tree_add_item(mux27010_tree, hf_mux27010_checksum, tvb, offset, 1, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(tf, ett_mux27010_checksum);
if (check_fcs(tvb,offset-sizeMuxPPPHeader-3-length_info, sizeMuxPPPHeader+3, tvb_get_guint8(tvb, offset))){
checksum_validation = 1;
proto_tree_add_uint_format(field_tree, hf_mux27010_checksum, tvb, offset, 1, checksum_validation, "Checksum: correct");
}
else{
checksum_validation = -1;
proto_tree_add_uint_format(field_tree, hf_mux27010_checksum, tvb, offset, 1, checksum_validation, "Checksum: incorrect!");
}
col_add_str(pinfo->cinfo, COL_INFO, colInfoText);
col_add_str(pinfo->cinfo, COL_DEF_SRC, colSourceText);
col_add_str(pinfo->cinfo, COL_DEF_DST, colDestText);
}
static void
mux27010_init(void)
{
fragment_table_init(&msg_fragment_table);
reassembled_table_init(&msg_reassembled_table);
}
void
proto_register_mux27010 (void)
{
static hf_register_info hf[] = {
{&hf_mux27010_extended_header,
{ "Extended Header", "mux27010.ext_header",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_size,
{ "Header Size", "mux27010.ext_header.size",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_msg_number_I,
{ "Message Number I", "mux27010.ext_header.msg_number_I",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_freq_number_I,
{ "Frequenz Number I", "mux27010.ext_header.frequenz_number_I",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_start_pos_I,
{ "Start Position I", "mux27010.ext_header.start_pos_I",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_start_byte_I,
{ "Start Byte I", "mux27010.ext_header.start_byte_I",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_end_pos_I,
{ "End Position I", "mux27010.ext_header.end_pos_I",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_end_byte_I,
{ "End Byte I", "mux27010.ext_header.end_byte_I",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_flag_ended_I,
{ "Flag Ended I", "mux27010.ext_header.flag_ended_I",
FT_UINT8, BASE_HEX, NULL, MUX27010_EXTENDED_HEADER_NOT_ENDED, NULL, HFILL }},
{&hf_mux27010_extended_header_msg_number_II,
{ "Message Number II", "mux27010.ext_header.msg_number_II",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_freq_number_II,
{ "Frequenz Number II", "mux27010.ext_header.frequenz_number_II",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_start_pos_II,
{ "Start Position II", "mux27010.ext_header.start_pos_II",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_start_byte_II,
{ "Start Byte II", "mux27010.ext_header.start_byte_II",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_end_pos_II,
{ "End Position II", "mux27010.ext_header.end_pos_II",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_end_byte_II,
{ "End Byte II", "mux27010.ext_header.end_byte_II",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_flag_ended_II,
{ "Flag Ended II", "mux27010.ext_header.flag_ended_II",
FT_UINT8, BASE_HEX, NULL, MUX27010_EXTENDED_HEADER_NOT_ENDED, NULL, HFILL }},
{&hf_mux27010_extended_header_msg_number_III,
{ "Message Number III", "mux27010.ext_header.msg_number_III",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_freq_number_III,
{ "Frequenz Number III", "mux27010.ext_header.frequenz_number_III",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_start_pos_III,
{ "Start Position III", "mux27010.ext_header.start_pos_III",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_start_byte_III,
{ "Start Byte III", "mux27010.ext_header.start_byte_III",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_end_pos_III,
{ "End Position III", "mux27010.ext_header.end_pos_III",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_end_byte_III,
{ "End Byte III", "mux27010.ext_header.end_byte_III",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010_extended_header_flag_ended_III,
{ "Flag Ended III", "mux27010.ext_header.flag_ended_III",
FT_UINT8, BASE_HEX, NULL, MUX27010_EXTENDED_HEADER_NOT_ENDED, NULL, HFILL }},
{&hf_mux27010_direction,
{ "Direction", "mux27010.direction",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_mux27010,
{ "Flag", "mux27010.flag",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_mux27010_address,
{ "Address field", "mux27010.address",
FT_UINT8, BASE_HEX, NULL, 0x0,NULL, HFILL }},
{ &hf_mux27010_dlciaddressflag,
{ "DLCI number (decimal)", "mux27010.address.dlciaddress",
FT_UINT8, BASE_DEC, NULL, MUX27010_DLCI_ADDRESS_FLAG, NULL, HFILL }},
{ &hf_mux27010_eaaddressflag,
{ "EA Address Flag", "mux27010.address.eaaddress",
FT_BOOLEAN, 8, NULL, MUX27010_EA_ADDRESS_FLAG, NULL, HFILL }},
{ &hf_mux27010_craddressflag,
{ "C/R Address Flag", "mux27010.address.craddress",
FT_BOOLEAN, 8, NULL, MUX27010_CR_ADDRESS_FLAG, NULL, HFILL }},
{ &hf_mux27010_addressdirection,
{ "Direction", "mux27010.address.direction",
FT_UINT8, BASE_HEX, NULL, MUX27010_CR_ADDRESS_FLAG, NULL, HFILL }},
{ &hf_mux27010_control,
{ "Control field", "mux27010.control",
FT_UINT8, BASE_HEX, NULL, 0x0,NULL, HFILL }},
{ &hf_mux27010_controlframetype,
{ "Frame Type", "mux27010.control.frametype",
FT_UINT8, BASE_HEX, NULL, MUX27010_FRAMETYPE_CONTROL_FLAG, NULL, HFILL }},
{ &hf_mux27010_controlframetypens,
{ "N(S) Sequence Number", "mux27010.control.frametype.ns",
FT_UINT8, BASE_DEC, NULL, MUX27010_FRAMETYPE_CONTROL_FLAG_NS, NULL, HFILL }},
{ &hf_mux27010_controlframetypenr,
{ "N(R) Receive Number", "mux27010.control.frametype.nr",
FT_UINT8, BASE_DEC, NULL, MUX27010_FRAMETYPE_CONTROL_FLAG_NR, NULL, HFILL }},
{ &hf_mux27010_pfcontrolflag,
{ "Poll/Final bit", "mux27010.control.pfcontrol",
FT_UINT8, BASE_DEC, NULL, MUX27010_PF_CONTROL_FLAG, NULL, HFILL }},
{ &hf_mux27010_length,
{ "Length field", "mux27010.length",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_mux27010_ealengthflag,
{ "E/A Flag", "mux27010.length.ealength",
FT_BOOLEAN, 8, NULL, MUX27010_EA_LENGTH_FLAG, NULL, HFILL }},
{ &hf_mux27010_lengthframesize_ea,
{ "Frame Size", "mux27010.length.framesize_ea",
FT_UINT16, BASE_DEC, NULL, MUX27010_FRAMESIZE_LENGTH_FLAG_EA, NULL, HFILL }},
{ &hf_mux27010_lengthframesize,
{ "Frame Size", "mux27010.length.framesize",
FT_UINT8, BASE_DEC, NULL, MUX27010_FRAMESIZE_LENGTH_FLAG, NULL, HFILL }},
{ &hf_mux27010_controlchannel,
{ "Control Channel", "mux27010.controlchannel",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_mux27010_controlchannelframetype,
{ "Frame Type", "mux27010.controlchannel.frametype",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_mux27010_controlchanneleaframetype,
{ "EA Flag", "mux27010.controlchannel.frametype.eatype",
FT_BOOLEAN, 8, NULL, MUX27010_EA_CONTROLCHANNEL_FRAMETYPE_FLAG, NULL, HFILL }},
{ &hf_mux27010_controlchannelcrframetype,
{ "C/R Flag", "mux27010.controlchannel.frametype.crtype",
FT_BOOLEAN, 8, NULL, MUX27010_CR_CONTROLCHANNEL_FRAMETYPE_FLAG, NULL, HFILL }},
{ &hf_mux27010_controlchannelframetypecommand,
{ "Command Type", "mux27010.controlchannel.frametype.command",
FT_UINT8, BASE_HEX, NULL, MUX27010_COMMAND_CONTROLCHANNEL_FRAMETYPE_FLAG, NULL, HFILL }},
{ &hf_mux27010_controlchannellength,
{ "Length", "mux27010.controlchannel.length",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_mux27010_controlchannelealength,
{ "EA Flag", "mux27010.controlchannel.length.ealength",
FT_BOOLEAN, 8, NULL, MUX27010_EA_CONTROLCHANNEL_LENGTH_FLAG, NULL, HFILL }},
{ &hf_mux27010_controlchannellengthfield,
{ "Length field", "mux27010.controlchannel.length.length",
FT_UINT8, BASE_DEC, NULL, MUX27010_LENGTHFIELD_CONTROLCHANNEL_LENGTH_FLAG, NULL, HFILL }},
{ &hf_mux27010_controlchannelvalue,
{ "Value", "mux27010.controlchannel.value",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvalue,
{ "Detailed Values", "mux27010.controlchannel.value.detailedvalues",
FT_UINT8, BASE_HEX, NULL, 0xFF, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluetestcommandversion,
{ "Version", "mux27010.controlchannel.value.detailedvaluetestcommandversion",
FT_UINT8, BASE_HEX, NULL, MUX27010_VALUE_CONTROLCHANNEL_TEST_VERSION, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluemscdlci,
{ "DLCI number (decimal)", "mux27010.controlchannel.value.detailedvaluemscdlci",
FT_UINT8, BASE_DEC, NULL, MUX27010_VALUE_CONTROLCHANNEL_MSC_DCLI, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluemscv24,
{ "V.24 Signal", "mux27010.controlchannel.value.detailedvaluemscv24",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluemscv24fc,
{ "FC", "mux27010.controlchannel.value.detailedvaluemscv24.fc",
FT_BOOLEAN, 8, NULL, MUX27010_VALUE_CONTROLCHANNEL_MSC_V24_FC, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluemscv24rtc,
{ "RTC", "mux27010.controlchannel.value.detailedvaluemscv24.rtc",
FT_BOOLEAN, 8, NULL, MUX27010_VALUE_CONTROLCHANNEL_MSC_V24_RTC, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluemscv24rtr,
{ "RTR", "mux27010.controlchannel.value.detailedvaluemscv24.rtr",
FT_BOOLEAN, 8, NULL, MUX27010_VALUE_CONTROLCHANNEL_MSC_V24_RTR, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluemscv24ring,
{ "RING", "mux27010.controlchannel.value.detailedvaluemscv24.ring",
FT_BOOLEAN, 8, NULL, MUX27010_VALUE_CONTROLCHANNEL_MSC_V24_RING, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluemscv24dcd,
{ "DCD", "mux27010.controlchannel.value.detailedvaluemscv24.dcd",
FT_BOOLEAN, 8, NULL, MUX27010_VALUE_CONTROLCHANNEL_MSC_V24_DCD, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluemscbreak,
{ "Break Signal", "mux27010.controlchannel.value.detailedvaluemscbreak",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluepndlci,
{ "DLCI", "mux27010.controlchannel.value.detailedvaluepndlci",
FT_UINT8, BASE_DEC, NULL, MUX27010_VALUE_CONTROLCHANNEL_PN_DLCI, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluepnframetype,
{ "Frame Type", "mux27010.controlchannel.value.detailedvaluepnframetype",
FT_UINT8, BASE_HEX, NULL, MUX27010_VALUE_CONTROLCHANNEL_PN_FRAMETYPE, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluepncl,
{ "Convergence Layer", "mux27010.controlchannel.value.detailedvaluepncl",
FT_UINT8, BASE_DEC, NULL, MUX27010_VALUE_CONTROLCHANNEL_PN_CL, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluepnprio,
{ "Priority", "mux27010.controlchannel.value.detailedvaluepnprio",
FT_UINT8, BASE_DEC, NULL, MUX27010_VALUE_CONTROLCHANNEL_PN_PRIO, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluepntimer,
{ "Acknowledgment Timer (ms)", "mux27010.controlchannel.value.detailedvaluepntimer",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluepnframesize,
{ "Max. Frame Size", "mux27010.controlchannel.value.detailedvaluepnframesize",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluepnna,
{ "Max. Number of Retransmissions", "mux27010.controlchannel.value.detailedvaluepnna",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_mux27010_controlchanneldetailedvaluepnwinsize,
{ "Window Size for Error Recovery Mode", "mux27010.controlchannel.value.detailedvaluepnwinsize",
FT_UINT8, BASE_DEC, NULL, MUX27010_VALUE_CONTROLCHANNEL_PN_WINSIZE, NULL, HFILL }},
{ &hf_mux27010_information,
{ "Information field", "mux27010.information",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_mux27010_checksum,
{ "Checksum", "mux27010.checksum",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_msg_fragments,
{"Message fragments", "mux27010.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_fragment,
{"Message fragment", "mux27010.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_fragment_overlap,
{"Message fragment overlap", "mux27010.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_fragment_overlap_conflicts,
{"Message fragment overlapping with conflicting data",
"mux27010.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_fragment_multiple_tails,
{"Message has multiple tail fragments",
"mux27010.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_fragment_too_long_fragment,
{"Message fragment too long", "mux27010.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_fragment_error,
{"Message defragmentation error", "mux27010.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_fragment_count,
{"Message fragment count", "mux27010.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{&hf_msg_reassembled_in,
{"Reassembled in", "mux27010.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_reassembled_length,
{"Reassembled length", "mux27010.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
};
static gint *ett[] = {
&ett_mux27010_extended_header,
&ett_mux27010,
&ett_mux27010_address,
&ett_mux27010_control,
&ett_mux27010_length,
&ett_mux27010_controlchannel,
&ett_mux27010_controlchannelframetype,
&ett_mux27010_controlchannellength,
&ett_mux27010_controlchannelvalue,
&ett_mux27010_information,
&ett_mux27010_checksum,
&ett_msg_fragment,
&ett_msg_fragments
};
proto_mux27010 = proto_register_protocol ("MUX27010 Protocol", "MUX27010", "mux27010");
proto_register_field_array (proto_mux27010, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector("mux27010", dissect_mux27010, proto_mux27010);
register_init_routine(mux27010_init);
}
void
proto_reg_handoff_mux27010(void)
{
dissector_handle_t mux27010_handle;
mux27010_handle = create_dissector_handle(dissect_mux27010, proto_mux27010);
dissector_add_uint("wtap_encap", WTAP_ENCAP_MUX27010, mux27010_handle);
ppp_handle = find_dissector("ppp");
}
