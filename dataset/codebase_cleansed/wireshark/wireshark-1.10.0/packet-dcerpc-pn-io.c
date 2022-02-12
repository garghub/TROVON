static void
pnio_ar_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, pnio_ar_t *ar)
{
pinfo->profinet_conv = ar;
pinfo->profinet_type = 10;
if (tree) {
proto_item *item;
proto_item *sub_item;
proto_tree *sub_tree;
sub_item = proto_tree_add_text(tree, tvb, 0, 0,
"ARUUID:%s ContrMAC:%s ContrAlRef:0x%x DevMAC:%s DevAlRef:0x%x InCR:0x%x OutCR=0x%x",
guid_to_str((const e_guid_t*) &ar->aruuid),
ether_to_str((const guint8 *)ar->controllermac), ar->controlleralarmref,
ether_to_str((const guint8 *)ar->devicemac), ar->devicealarmref,
ar->inputframeid, ar->outputframeid);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_ar_info);
PROTO_ITEM_SET_GENERATED(sub_item);
item = proto_tree_add_guid(sub_tree, hf_pn_io_ar_uuid, tvb, 0, 0, (e_guid_t *) &ar->aruuid);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_ether(sub_tree, hf_pn_io_cminitiator_macadd, tvb, 0, 0, ar->controllermac);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_uint(sub_tree, hf_pn_io_localalarmref, tvb, 0, 0, ar->controlleralarmref);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_ether(sub_tree, hf_pn_io_cmresponder_macadd, tvb, 0, 0, ar->devicemac);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_uint(sub_tree, hf_pn_io_localalarmref, tvb, 0, 0, ar->devicealarmref);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_uint(sub_tree, hf_pn_io_frame_id, tvb, 0, 0, ar->inputframeid);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_uint(sub_tree, hf_pn_io_frame_id, tvb, 0, 0, ar->outputframeid);
PROTO_ITEM_SET_GENERATED(item);
}
}
static pnio_ar_t *
pnio_ar_find_by_aruuid(packet_info *pinfo _U_, e_uuid_t *aruuid)
{
GList *ars;
pnio_ar_t *ar;
for(ars = pnio_ars; ars != NULL; ars = g_list_next(ars)) {
ar = (pnio_ar_t *)ars->data;
if (memcmp(&ar->aruuid, aruuid, sizeof(e_uuid_t)) == 0) {
return ar;
}
}
return NULL;
}
static pnio_ar_t *
pnio_ar_new(e_uuid_t *aruuid)
{
pnio_ar_t *ar;
ar = (pnio_ar_t *)se_alloc0(sizeof(pnio_ar_t));
memcpy(&ar->aruuid, aruuid, sizeof(e_uuid_t));
ar->controlleralarmref = 0xffff;
ar->devicealarmref = 0xffff;
pnio_ars = g_list_append(pnio_ars, ar);
return ar;
}
static int
dissect_PNIO_status(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint8 u8ErrorCode;
guint8 u8ErrorDecode;
guint8 u8ErrorCode1;
guint8 u8ErrorCode2;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32SubStart;
int bytemask = (drep[0] & DREP_LITTLE_ENDIAN) ? 3 : 0;
const value_string *error_code1_vals;
const value_string *error_code2_vals = pn_io_error_code2;
sub_item = proto_tree_add_item(tree, hf_pn_io_status, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_status);
u32SubStart = offset;
dissect_dcerpc_uint8(tvb, offset+(0^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code, &u8ErrorCode);
dissect_dcerpc_uint8(tvb, offset+(1^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_decode, &u8ErrorDecode);
switch (u8ErrorDecode) {
case(0x80):
dissect_dcerpc_uint8(tvb, offset+(2^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code1_pniorw, &u8ErrorCode1);
error_code1_vals = pn_io_error_code1_pniorw;
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pniorw, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pniorw;
break;
case(0x81):
dissect_dcerpc_uint8(tvb, offset+(2^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code1_pnio, &u8ErrorCode1);
error_code1_vals = pn_io_error_code1_pnio;
switch (u8ErrorCode1) {
case(1):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_1, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_1;
break;
case(2):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_2, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_2;
break;
case(3):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_3, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_3;
break;
case(4):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_4, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_4;
break;
case(5):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_5, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_5;
break;
case(6):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_6, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_6;
break;
case(7):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_7, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_7;
break;
case(8):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_8, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_8;
break;
case(20):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_20, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_20;
break;
case(21):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_21, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_21;
break;
case(22):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_22, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_22;
break;
case(23):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_23, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_23;
break;
case(40):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_40, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_40;
break;
case(61):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_61, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_61;
break;
case(62):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_62, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_62;
break;
case(63):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_63, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_63;
break;
case(64):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_64, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_64;
break;
case(65):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_65, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_65;
break;
case(66):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_66, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_66;
break;
case(70):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_70, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_70;
break;
case(71):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_71, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_71;
break;
case(72):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_72, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_72;
break;
case(73):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_73, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_73;
break;
case(74):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_74, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_74;
break;
case(75):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_75, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_75;
break;
case(76):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_76, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_76;
break;
case(77):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_77, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_77;
break;
case(253):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_253, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_253;
break;
case(255):
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2_pnio_255, &u8ErrorCode2);
error_code2_vals = pn_io_error_code2_pnio_255;
break;
default:
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2, &u8ErrorCode2);
expert_add_info_format(pinfo, sub_item, PI_UNDECODED, PI_WARN,
"Unknown ErrorCode1 0x%x (for ErrorDecode==PNIO)", u8ErrorCode1);
break;
}
break;
default:
dissect_dcerpc_uint8(tvb, offset+(2^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code1, &u8ErrorCode1);
if (u8ErrorDecode!=0) {
expert_add_info_format(pinfo, sub_item, PI_UNDECODED, PI_WARN,
"Unknown ErrorDecode 0x%x", u8ErrorDecode);
}
error_code1_vals = pn_io_error_code1;
dissect_dcerpc_uint8(tvb, offset+(3^bytemask), pinfo, sub_tree, drep,
hf_pn_io_error_code2, &u8ErrorCode2);
if (u8ErrorDecode != 0) {
expert_add_info_format(pinfo, sub_item, PI_UNDECODED, PI_WARN,
"Unknown ErrorDecode 0x%x", u8ErrorDecode);
}
}
offset += 4;
if ((u8ErrorCode == 0) && (u8ErrorDecode == 0) && (u8ErrorCode1 == 0) && (u8ErrorCode2 == 0)) {
proto_item_append_text(sub_item, ": OK");
col_append_str(pinfo->cinfo, COL_INFO, ", OK");
} else {
proto_item_append_text(sub_item, ": Error: \"%s\", \"%s\", \"%s\", \"%s\"",
val_to_str(u8ErrorCode, pn_io_error_code, "(0x%x)"),
val_to_str(u8ErrorDecode, pn_io_error_decode, "(0x%x)"),
val_to_str(u8ErrorCode1, error_code1_vals, "(0x%x)"),
val_to_str(u8ErrorCode2, error_code2_vals, "(0x%x)"));
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: \"%s\", \"%s\", \"%s\", \"%s\"",
val_to_str(u8ErrorCode, pn_io_error_code, "(0x%x)"),
val_to_str(u8ErrorDecode, pn_io_error_decode, "(0x%x)"),
val_to_str(u8ErrorCode1, error_code1_vals, "(0x%x)"),
val_to_str(u8ErrorCode2, error_code2_vals, "(0x%x)"));
}
proto_item_set_len(sub_item, offset - u32SubStart);
return offset;
}
static int
dissect_Alarm_specifier(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint16 u16AlarmSpecifierSequence;
guint16 u16AlarmSpecifierChannel;
guint16 u16AlarmSpecifierManufacturer;
guint16 u16AlarmSpecifierSubmodule;
guint16 u16AlarmSpecifierAR;
proto_item *sub_item;
proto_tree *sub_tree;
sub_item = proto_tree_add_item(tree, hf_pn_io_alarm_specifier, tvb, offset, 2, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_pdu_type);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_alarm_specifier_sequence, &u16AlarmSpecifierSequence);
u16AlarmSpecifierSequence &= 0x07FF;
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_alarm_specifier_channel, &u16AlarmSpecifierChannel);
u16AlarmSpecifierChannel = (u16AlarmSpecifierChannel &0x0800) >> 11;
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_alarm_specifier_manufacturer, &u16AlarmSpecifierManufacturer);
u16AlarmSpecifierManufacturer = (u16AlarmSpecifierManufacturer &0x1000) >> 12;
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_alarm_specifier_submodule, &u16AlarmSpecifierSubmodule);
u16AlarmSpecifierSubmodule = (u16AlarmSpecifierSubmodule & 0x2000) >> 13;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_alarm_specifier_ardiagnosis, &u16AlarmSpecifierAR);
u16AlarmSpecifierAR = (u16AlarmSpecifierAR & 0x8000) >> 15;
proto_item_append_text(sub_item, ", Sequence: %u, Channel: %u, Manuf: %u, Submodule: %u AR: %u",
u16AlarmSpecifierSequence, u16AlarmSpecifierChannel,
u16AlarmSpecifierManufacturer, u16AlarmSpecifierSubmodule, u16AlarmSpecifierAR);
return offset;
}
static int
dissect_Alarm_header(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep)
{
guint16 u16AlarmType;
guint32 u32Api;
guint16 u16SlotNr;
guint16 u16SubslotNr;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_alarm_type, &u16AlarmType);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_api, &u32Api);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
proto_item_append_text(item, ", %s, API:%u, Slot:0x%x/0x%x",
val_to_str(u16AlarmType, pn_io_alarm_type, "(0x%x)"),
u32Api, u16SlotNr, u16SubslotNr);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s, Slot: 0x%x/0x%x",
val_to_str(u16AlarmType, pn_io_alarm_type, "(0x%x)"),
u16SlotNr, u16SubslotNr);
return offset;
}
static int
dissect_ChannelProperties(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep)
{
proto_item *sub_item;
proto_tree *sub_tree;
guint16 u16ChannelProperties;
sub_item = proto_tree_add_item(tree, hf_pn_io_channel_properties, tvb, offset, 2, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_channel_properties);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_channel_properties_direction, &u16ChannelProperties);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_channel_properties_specifier, &u16ChannelProperties);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_channel_properties_maintenance, &u16ChannelProperties);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_channel_properties_accumulative, &u16ChannelProperties);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_channel_properties_type, &u16ChannelProperties);
return offset;
}
static int
dissect_AlarmUserStructure(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep,
guint16 *body_length, guint16 u16UserStructureIdentifier)
{
guint16 u16ChannelNumber;
guint16 u16ChannelErrorType;
guint16 u16ExtChannelErrorType;
guint32 u32ExtChannelAddValue;
guint16 u16Index = 0;
guint32 u32RecDataLen;
pnio_ar_t *ar = NULL;
switch (u16UserStructureIdentifier) {
case(0x8000):
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_channel_number, &u16ChannelNumber);
offset = dissect_ChannelProperties(tvb, offset, pinfo, tree, item, drep);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_channel_error_type, &u16ChannelErrorType);
*body_length -= 6;
break;
case(0x8002):
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_channel_number, &u16ChannelNumber);
offset = dissect_ChannelProperties(tvb, offset, pinfo, tree, item, drep);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_channel_error_type, &u16ChannelErrorType);
if (u16ChannelErrorType < 0x7fff)
{
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ext_channel_error_type0, &u16ExtChannelErrorType);
}
else if (u16ChannelErrorType == 0x8000)
{
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ext_channel_error_type0x8000, &u16ExtChannelErrorType);
}
else if (u16ChannelErrorType == 0x8001)
{
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ext_channel_error_type0x8001, &u16ExtChannelErrorType);
}
else if (u16ChannelErrorType == 0x8002)
{
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ext_channel_error_type0x8002, &u16ExtChannelErrorType);
}
else if ((u16ChannelErrorType == 0x8003)||(u16ChannelErrorType == 0x8009))
{
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ext_channel_error_type0x8003, &u16ExtChannelErrorType);
}
else if (u16ChannelErrorType == 0x8004)
{
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ext_channel_error_type0x8004, &u16ExtChannelErrorType);
}
else if (u16ChannelErrorType == 0x8005)
{
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ext_channel_error_type0x8005, &u16ExtChannelErrorType);
}
else if (u16ChannelErrorType == 0x8007)
{
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ext_channel_error_type0x8007, &u16ExtChannelErrorType);
}
else if (u16ChannelErrorType == 0x8008)
{
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ext_channel_error_type0x8008, &u16ExtChannelErrorType);
}
else if (u16ChannelErrorType == 0x800A)
{
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ext_channel_error_type0x800A, &u16ExtChannelErrorType);
}
else if (u16ChannelErrorType == 0x800B)
{
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ext_channel_error_type0x800B, &u16ExtChannelErrorType);
}
else if (u16ChannelErrorType == 0x800C)
{
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ext_channel_error_type0x800C, &u16ExtChannelErrorType);
}
else
{
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ext_channel_error_type, &u16ExtChannelErrorType);
}
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_ext_channel_add_value, &u32ExtChannelAddValue);
*body_length -= 12;
break;
case(0x8100):
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
*body_length -= 12;
break;
case(0x8001):
case(0x8003):
default:
if (u16UserStructureIdentifier >= 0x8000) {
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, *body_length);
} else {
offset = dissect_pn_user_data(tvb, offset, pinfo, tree, *body_length, "UserData");
}
*body_length = 0;
}
return offset;
}
static int
dissect_AlarmNotification_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 body_length)
{
guint32 u32ModuleIdentNumber;
guint32 u32SubmoduleIdentNumber;
guint16 u16UserStructureIdentifier;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_Alarm_header(tvb, offset, pinfo, tree, item, drep);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_module_ident_number, &u32ModuleIdentNumber);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_submodule_ident_number, &u32SubmoduleIdentNumber);
offset = dissect_Alarm_specifier(tvb, offset, pinfo, tree, drep);
proto_item_append_text(item, ", Ident:0x%x, SubIdent:0x%x",
u32ModuleIdentNumber, u32SubmoduleIdentNumber);
body_length -= 20;
while (body_length) {
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_user_structure_identifier, &u16UserStructureIdentifier);
proto_item_append_text(item, ", USI:0x%x", u16UserStructureIdentifier);
body_length -= 2;
offset = dissect_AlarmUserStructure(tvb, offset, pinfo, tree, item, drep, &body_length, u16UserStructureIdentifier);
}
return offset;
}
static int
dissect_IandM0_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint8 u8VendorIDHigh;
guint8 u8VendorIDLow;
char *pOrderID;
char *pIMSerialNumber;
guint16 u16IMHardwareRevision;
guint8 u8SWRevisionPrefix;
guint8 u8IMSWRevisionFunctionalEnhancement;
guint8 u8IMSWRevisionBugFix;
guint8 u8IMSWRevisionInternalChange;
guint16 u16IMRevisionCounter;
guint16 u16IMProfileID;
guint16 u16IMProfileSpecificType;
guint8 u8IMVersionMajor;
guint8 u8IMVersionMinor;
guint16 u16IMSupported;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_vendor_id_high, &u8VendorIDHigh);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_vendor_id_low, &u8VendorIDLow);
pOrderID = (char *)ep_alloc(20+1);
tvb_memcpy(tvb, (guint8 *) pOrderID, offset, 20);
pOrderID[20] = '\0';
proto_tree_add_string (tree, hf_pn_io_order_id, tvb, offset, 20, pOrderID);
offset += 20;
pIMSerialNumber = (char *)ep_alloc(16+1);
tvb_memcpy(tvb, (guint8 *) pIMSerialNumber, offset, 16);
pIMSerialNumber[16] = '\0';
proto_tree_add_string (tree, hf_pn_io_im_serial_number, tvb, offset, 16, pIMSerialNumber);
offset += 16;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_im_hardware_revision, &u16IMHardwareRevision);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_im_revision_prefix, &u8SWRevisionPrefix);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_im_sw_revision_functional_enhancement, &u8IMSWRevisionFunctionalEnhancement);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_im_revision_bugfix, &u8IMSWRevisionBugFix);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_im_sw_revision_internal_change, &u8IMSWRevisionInternalChange);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_im_revision_counter, &u16IMRevisionCounter);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_im_profile_id, &u16IMProfileID);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_im_profile_specific_type, &u16IMProfileSpecificType);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_im_version_major, &u8IMVersionMajor);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_im_version_minor, &u8IMVersionMinor);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_im_supported, &u16IMSupported);
return offset;
}
static int
dissect_IandM1_block(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint8 *drep _U_, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
char *pTagFunction;
char *pTagLocation;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
pTagFunction = (char *)ep_alloc(32+1);
tvb_memcpy(tvb, (guint8 *) pTagFunction, offset, 32);
pTagFunction[32] = '\0';
proto_tree_add_string (tree, hf_pn_io_im_tag_function, tvb, offset, 32, pTagFunction);
offset += 32;
pTagLocation = (char *)ep_alloc(22+1);
tvb_memcpy(tvb, (guint8 *) pTagLocation, offset, 22);
pTagLocation[22] = '\0';
proto_tree_add_string (tree, hf_pn_io_im_tag_location, tvb, offset, 22, pTagLocation);
offset += 22;
proto_item_append_text(item, ": TagFunction:\"%s\", TagLocation:\"%s\"", pTagFunction, pTagLocation);
return offset;
}
static int
dissect_IandM2_block(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint8 *drep _U_, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
char *pDate;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
pDate = (char *)ep_alloc(16+1);
tvb_memcpy(tvb, (guint8 *) pDate, offset, 16);
pDate[16] = '\0';
proto_tree_add_string (tree, hf_pn_io_im_date, tvb, offset, 16, pDate);
offset += 16;
proto_item_append_text(item, ": Date:\"%s\"", pDate);
return offset;
}
static int
dissect_IandM3_block(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint8 *drep _U_, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
char *pDescriptor;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
pDescriptor = (char *)ep_alloc(54+1);
tvb_memcpy(tvb, (guint8 *) pDescriptor, offset, 54);
pDescriptor[54] = '\0';
proto_tree_add_string (tree, hf_pn_io_im_descriptor, tvb, offset, 54, pDescriptor);
offset += 54;
proto_item_append_text(item, ": Descriptor:\"%s\"", pDescriptor);
return offset;
}
static int
dissect_IandM4_block(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint8 *drep _U_, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
dissect_pn_user_data(tvb, offset, pinfo, tree, 54, "IM Signature");
return offset;
}
static int
dissect_IandM0FilterData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16NumberOfAPIs;
guint32 u32Api;
guint16 u16NumberOfModules;
guint16 u16SlotNr;
guint32 u32ModuleIdentNumber;
guint16 u16NumberOfSubmodules;
guint16 u16SubslotNr;
guint32 u32SubmoduleIdentNumber;
proto_item *subslot_item;
proto_tree *subslot_tree;
proto_item *module_item;
proto_tree *module_tree;
guint32 u32ModuleStart;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_number_of_apis, &u16NumberOfAPIs);
while (u16NumberOfAPIs--) {
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_api, &u32Api);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_number_of_modules, &u16NumberOfModules);
while (u16NumberOfModules--) {
module_item = proto_tree_add_item(tree, hf_pn_io_subslot, tvb, offset, 6, ENC_NA);
module_tree = proto_item_add_subtree(module_item, ett_pn_io_module);
u32ModuleStart = offset;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, module_tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, module_tree, drep,
hf_pn_io_module_ident_number, &u32ModuleIdentNumber);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, module_tree, drep,
hf_pn_io_number_of_submodules, &u16NumberOfSubmodules);
proto_item_append_text(module_item, ": Slot:%u, Ident:0x%x Submodules:%u",
u16SlotNr, u32ModuleIdentNumber, u16NumberOfSubmodules);
while (u16NumberOfSubmodules--) {
subslot_item = proto_tree_add_item(module_tree, hf_pn_io_subslot, tvb, offset, 6, ENC_NA);
subslot_tree = proto_item_add_subtree(subslot_item, ett_pn_io_subslot);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, subslot_tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, subslot_tree, drep,
hf_pn_io_submodule_ident_number, &u32SubmoduleIdentNumber);
proto_item_append_text(subslot_item, ": Number:0x%x, Ident:0x%x",
u16SubslotNr, u32SubmoduleIdentNumber);
}
proto_item_set_len(module_item, offset-u32ModuleStart);
}
}
return offset;
}
static int
dissect_IdentificationData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16NumberOfAPIs = 1;
guint32 u32Api;
guint16 u16NumberOfSlots;
guint16 u16SlotNr;
guint32 u32ModuleIdentNumber;
guint16 u16NumberOfSubslots;
guint32 u32SubmoduleIdentNumber;
guint16 u16SubslotNr;
proto_item *slot_item;
proto_tree *slot_tree;
guint32 u32SlotStart;
proto_item *subslot_item;
proto_tree *subslot_tree;
if (u8BlockVersionHigh != 1 || (u8BlockVersionLow != 0 && u8BlockVersionLow != 1)) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
if (u8BlockVersionLow == 1) {
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_number_of_apis, &u16NumberOfAPIs);
}
proto_item_append_text(item, ": APIs:%u", u16NumberOfAPIs);
while (u16NumberOfAPIs--) {
if (u8BlockVersionLow == 1) {
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_api, &u32Api);
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_number_of_slots, &u16NumberOfSlots);
proto_item_append_text(item, ", Slots:%u", u16NumberOfSlots);
while (u16NumberOfSlots--) {
slot_item = proto_tree_add_item(tree, hf_pn_io_slot, tvb, offset, 0, ENC_NA);
slot_tree = proto_item_add_subtree(slot_item, ett_pn_io_slot);
u32SlotStart = offset;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, slot_tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, slot_tree, drep,
hf_pn_io_module_ident_number, &u32ModuleIdentNumber);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, slot_tree, drep,
hf_pn_io_number_of_subslots, &u16NumberOfSubslots);
proto_item_append_text(slot_item, ": SlotNr:%u Ident:0x%x Subslots:%u",
u16SlotNr, u32ModuleIdentNumber, u16NumberOfSubslots);
while (u16NumberOfSubslots--) {
subslot_item = proto_tree_add_item(slot_tree, hf_pn_io_subslot, tvb, offset, 6, ENC_NA);
subslot_tree = proto_item_add_subtree(subslot_item, ett_pn_io_subslot);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, subslot_tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, subslot_tree, drep,
hf_pn_io_submodule_ident_number, &u32SubmoduleIdentNumber);
proto_item_append_text(subslot_item, ": Number:0x%x, Ident:0x%x",
u16SubslotNr, u32SubmoduleIdentNumber);
}
proto_item_set_len(slot_item, offset-u32SlotStart);
}
}
return offset;
}
static int
dissect_SubstituteValue_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 u16BodyLength)
{
guint16 u16SubstitutionMode;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_substitutionmode, &u16SubstitutionMode);
offset = dissect_PNIO_IOxS(tvb, offset, pinfo, tree, drep, hf_pn_io_iocs);
u16BodyLength -= 3;
dissect_pn_user_data_bytes(tvb, offset, pinfo, tree, u16BodyLength, SUBST_DATA);
return offset;
}
static int
dissect_RecordInputDataObjectElement_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint8 u8LengthIOCS;
guint8 u8LengthIOPS;
guint16 u16LengthData;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_length_iocs, &u8LengthIOCS);
offset = dissect_PNIO_IOxS(tvb, offset, pinfo, tree, drep, hf_pn_io_iocs);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_length_iops, &u8LengthIOPS);
offset = dissect_PNIO_IOxS(tvb, offset, pinfo, tree, drep, hf_pn_io_iops);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_length_data, &u16LengthData);
offset = dissect_pn_user_data(tvb, offset, pinfo, tree, u16LengthData, "Data");
return offset;
}
static int
dissect_RecordOutputDataObjectElement_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16SubstituteActiveFlag;
guint8 u8LengthIOCS;
guint8 u8LengthIOPS;
guint16 u16LengthData;
guint16 u16Index = 0;
guint32 u32RecDataLen;
pnio_ar_t *ar = NULL;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_substitute_active_flag, &u16SubstituteActiveFlag);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_length_iocs, &u8LengthIOCS);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_length_iops, &u8LengthIOPS);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_length_data, &u16LengthData);
offset = dissect_PNIO_IOxS(tvb, offset, pinfo, tree, drep, hf_pn_io_iocs);
offset = dissect_pn_user_data(tvb, offset, pinfo, tree, u16LengthData, "Data");
offset = dissect_PNIO_IOxS(tvb, offset, pinfo, tree, drep, hf_pn_io_iops);
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
return offset;
}
static int
dissect_Alarm_ack_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
col_append_str(pinfo->cinfo, COL_INFO, ", Alarm Ack");
offset = dissect_Alarm_header(tvb, offset, pinfo, tree, item, drep);
offset = dissect_Alarm_specifier(tvb, offset, pinfo, tree, drep);
offset = dissect_PNIO_status(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
dissect_Maintenance_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32MaintenanceStatus;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
sub_item = proto_tree_add_item(tree, hf_pn_io_maintenance_status, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_maintenance_status);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_maintenance_status_demanded, &u32MaintenanceStatus);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_maintenance_status_required, &u32MaintenanceStatus);
if (u32MaintenanceStatus & 0x0002) {
proto_item_append_text(item, ", Demanded");
proto_item_append_text(sub_item, ", Demanded");
}
if (u32MaintenanceStatus & 0x0001) {
proto_item_append_text(item, ", Required");
proto_item_append_text(sub_item, ", Required");
}
return offset;
}
static int
dissect_ReadWrite_header(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint16 *u16Index, e_uuid_t *aruuid)
{
guint32 u32Api;
guint16 u16SlotNr;
guint16 u16SubslotNr;
guint16 u16SeqNr;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_seq_number, &u16SeqNr);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_ar_uuid, aruuid);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_api, &u32Api);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 2);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_index, u16Index);
proto_item_append_text(item, ": Seq:%u, Api:0x%x, Slot:0x%x/0x%x",
u16SeqNr, u32Api, u16SlotNr, u16SubslotNr);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Api:0x%x, Slot:0x%x/0x%x, Index:%s",
u32Api, u16SlotNr, u16SubslotNr,
val_to_str(*u16Index, pn_io_index, "(0x%x)"));
return offset;
}
static int
dissect_IODWriteReqHeader_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 *u16Index, guint32 *u32RecDataLen, pnio_ar_t ** ar)
{
e_uuid_t aruuid;
e_uuid_t null_uuid;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_ReadWrite_header(tvb, offset, pinfo, tree, item, drep, u16Index, &aruuid);
*ar = pnio_ar_find_by_aruuid(pinfo, &aruuid);
if (*ar == NULL) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_NOTE, "IODWriteReq: AR information not found!");
}
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_record_data_length, u32RecDataLen);
memset(&null_uuid, 0, sizeof(e_uuid_t));
if (memcmp(&aruuid, &null_uuid, sizeof (e_uuid_t)) == 0) {
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_target_ar_uuid, &aruuid);
}
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 24);
proto_item_append_text(item, ", Len:%u", *u32RecDataLen);
if (*u32RecDataLen != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", %u bytes",
*u32RecDataLen);
return offset;
}
static int
dissect_IODReadReqHeader_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 *u16Index, guint32 *u32RecDataLen, pnio_ar_t **ar)
{
e_uuid_t aruuid;
e_uuid_t null_uuid;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_ReadWrite_header(tvb, offset, pinfo, tree, item, drep, u16Index, &aruuid);
*ar = pnio_ar_find_by_aruuid(pinfo, &aruuid);
if (*ar == NULL) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_NOTE, "IODReadReq: AR information not found!");
}
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_record_data_length, u32RecDataLen);
memset(&null_uuid, 0, sizeof(e_uuid_t));
if (memcmp(&aruuid, &null_uuid, sizeof (e_uuid_t)) == 0) {
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_target_ar_uuid, &aruuid);
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 8);
} else {
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 24);
}
proto_item_append_text(item, ", Len:%u", *u32RecDataLen);
if (*u32RecDataLen != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", %u bytes",
*u32RecDataLen);
return offset;
}
static int
dissect_IODWriteResHeader_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 *u16Index, guint32 *u32RecDataLen, pnio_ar_t **ar)
{
e_uuid_t aruuid;
guint16 u16AddVal1;
guint16 u16AddVal2;
guint32 u32Status;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_ReadWrite_header(tvb, offset, pinfo, tree, item, drep, u16Index, &aruuid);
*ar = pnio_ar_find_by_aruuid(pinfo, &aruuid);
if (*ar == NULL) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_NOTE, "IODWriteRes: AR information not found!");
}
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_record_data_length, u32RecDataLen);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_add_val1, &u16AddVal1);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_add_val2, &u16AddVal2);
u32Status = ((drep[0] & DREP_LITTLE_ENDIAN)
? tvb_get_letohl (tvb, offset)
: tvb_get_ntohl (tvb, offset));
offset = dissect_PNIO_status(tvb, offset, pinfo, tree, drep);
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 16);
proto_item_append_text(item, ", Len:%u, Index:0x%x, Status:0x%x, Val1:%u, Val2:%u",
*u32RecDataLen, *u16Index, u32Status, u16AddVal1, u16AddVal2);
if (*u32RecDataLen != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", %u bytes",
*u32RecDataLen);
return offset;
}
static int
dissect_IODReadResHeader_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 *u16Index, guint32 *u32RecDataLen, pnio_ar_t **ar)
{
e_uuid_t aruuid;
guint16 u16AddVal1;
guint16 u16AddVal2;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_ReadWrite_header(tvb, offset, pinfo, tree, item, drep, u16Index, &aruuid);
*ar = pnio_ar_find_by_aruuid(pinfo, &aruuid);
if (*ar == NULL) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_NOTE, "IODReadRes: AR information not found!");
}
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_record_data_length, u32RecDataLen);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_add_val1, &u16AddVal1);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_add_val2, &u16AddVal2);
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 20);
proto_item_append_text(item, ", Len:%u, AddVal1:%u, AddVal2:%u",
*u32RecDataLen, u16AddVal1, u16AddVal2);
if (*u32RecDataLen != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", %u bytes",
*u32RecDataLen);
return offset;
}
static int
dissect_ControlConnect_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
pnio_ar_t **ar)
{
e_uuid_t ar_uuid;
guint16 u16SessionKey;
proto_item *sub_item;
proto_tree *sub_tree;
guint16 u16Command;
guint16 u16Properties;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_reserved16, NULL);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_ar_uuid, &ar_uuid);
*ar = pnio_ar_find_by_aruuid(pinfo, &ar_uuid);
if (*ar == NULL) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_NOTE, "ControlConnect: AR information not found!");
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_sessionkey, &u16SessionKey);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_reserved16, NULL);
sub_item = proto_tree_add_item(tree, hf_pn_io_control_command, tvb, offset, 2, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_control_command);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_command_prmend, &u16Command);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_command_applready, &u16Command);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_command_release, &u16Command);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_command_done, &u16Command);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_command_ready_for_companion, &u16Command);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_command_ready_for_rt_class3, &u16Command);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_command_prmbegin, &u16Command);
if (u16Command & 0x0002) {
sub_item = proto_tree_add_item(tree, hf_pn_io_control_block_properties_applready, tvb, offset, 2, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_control_block_properties);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_block_properties_applready0, &u16Properties);
} else {
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_control_block_properties, &u16Properties);
}
proto_item_append_text(item, ": Session:%u, Command:", u16SessionKey);
if (u16Command & 0x0001) {
proto_item_append_text(sub_item, ", ParameterEnd");
proto_item_append_text(item, " ParameterEnd");
col_append_str(pinfo->cinfo, COL_INFO, ", Command: ParameterEnd");
}
if (u16Command & 0x0002) {
proto_item_append_text(sub_item, ", ApplicationReady");
proto_item_append_text(item, " ApplicationReady");
col_append_str(pinfo->cinfo, COL_INFO, ", Command: ApplicationReady");
}
if (u16Command & 0x0004) {
proto_item_append_text(sub_item, ", Release");
proto_item_append_text(item, " Release");
col_append_str(pinfo->cinfo, COL_INFO, ", Command: Release");
}
if (u16Command & 0x0008) {
proto_item_append_text(sub_item, ", Done");
proto_item_append_text(item, ", Done");
col_append_str(pinfo->cinfo, COL_INFO, ", Command: Done");
}
proto_item_append_text(item, ", Properties:0x%x", u16Properties);
return offset;
}
static int
dissect_ControlBlockPrmBegin(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow, guint32 u32RecDataLen,
pnio_ar_t **ar)
{
e_uuid_t ar_uuid;
guint16 u16SessionKey;
guint16 u16Command;
proto_item *sub_item;
proto_tree *sub_tree;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
if (u32RecDataLen != 28-2)
{
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block length of %u is invalid!", u32RecDataLen);
return offset;
}
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 2);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep, hf_pn_io_ar_uuid, &ar_uuid);
*ar = pnio_ar_find_by_aruuid(pinfo, &ar_uuid);
if (*ar == NULL) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_NOTE, "ControlBlockPrmBegin: AR information not found! (partial capture?)");
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep, hf_pn_io_sessionkey, &u16SessionKey);
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 2);
sub_item = proto_tree_add_item(tree, hf_pn_io_control_command, tvb, offset, 2, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_control_command);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_command_prmend, &u16Command);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_command_applready, &u16Command);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_command_release, &u16Command);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_command_done, &u16Command);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_command_ready_for_companion, &u16Command);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_command_ready_for_rt_class3, &u16Command);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_command_prmbegin, &u16Command);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_control_command_reserved_7_15, &u16Command);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep, hf_pn_io_control_command_reserved, NULL);
return offset;
}
static int
dissect_SubmoduleListBlock(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow, guint32 u32RecDataLen _U_,
pnio_ar_t **ar _U_)
{
guint16 u16Entries;
guint32 u32API;
guint16 u16SlotNumber;
guint16 u16SubSlotNumber;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep, hf_pn_io_SubmoduleListEntries, &u16Entries);
while (u16Entries --)
{
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_api, &u32API);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep, hf_pn_io_slot_nr, &u16SlotNumber);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep, hf_pn_io_subslot_nr, &u16SubSlotNumber);
}
return offset;
}
static int
dissect_PDevData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_blocks(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
dissect_AdjustPreambleLength_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16AdjustProperties;
guint16 u16PreambleLength;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_PreambleLength, &u16PreambleLength);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_adjust_properties, &u16AdjustProperties);
return offset;
}
static int
dissect_PDPortData_Adjust_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 u16BodyLength)
{
guint16 u16SlotNr;
guint16 u16SubslotNr;
tvbuff_t *new_tvb;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
proto_item_append_text(item, ": Slot:0x%x/0x%x", u16SlotNr, u16SubslotNr);
u16BodyLength -= 6;
new_tvb = tvb_new_subset(tvb, offset, u16BodyLength, u16BodyLength);
dissect_blocks(new_tvb, 0, pinfo, tree, drep);
offset += u16BodyLength;
return offset;
}
static int
dissect_PDPortData_Check_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 u16BodyLength)
{
guint16 u16SlotNr;
guint16 u16SubslotNr;
tvbuff_t *new_tvb;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
proto_item_append_text(item, ": Slot:0x%x/0x%x", u16SlotNr, u16SubslotNr);
u16BodyLength -= 6;
new_tvb = tvb_new_subset(tvb, offset, u16BodyLength, u16BodyLength);
dissect_blocks(new_tvb, 0, pinfo, tree, drep);
offset += u16BodyLength;
return offset;
}
static int
dissect_PDPortDataReal_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16SlotNr;
guint16 u16SubslotNr;
guint8 u8LengthOwnPortID;
char *pOwnPortID;
guint8 u8NumberOfPeers;
guint8 u8I;
guint8 u8LengthPeerPortID;
char *pPeerPortID;
guint8 u8LengthPeerChassisID;
char *pPeerChassisID;
guint32 u32LineDelay;
guint8 mac[6];
guint16 u16MAUType;
guint32 u32DomainBoundary;
guint32 u32MulticastBoundary;
guint16 u16PortState;
guint32 u32MediaType;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_length_own_port_id, &u8LengthOwnPortID);
pOwnPortID = (char *)ep_alloc(u8LengthOwnPortID+1);
tvb_memcpy(tvb, (guint8 *) pOwnPortID, offset, u8LengthOwnPortID);
pOwnPortID[u8LengthOwnPortID] = '\0';
proto_tree_add_string (tree, hf_pn_io_own_port_id, tvb, offset, u8LengthOwnPortID, pOwnPortID);
offset += u8LengthOwnPortID;
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_number_of_peers, &u8NumberOfPeers);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
u8I = u8NumberOfPeers;
while (u8I--) {
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_length_peer_port_id, &u8LengthPeerPortID);
pPeerPortID = (char *)ep_alloc(u8LengthPeerPortID+1);
tvb_memcpy(tvb, (guint8 *) pPeerPortID, offset, u8LengthPeerPortID);
pPeerPortID[u8LengthPeerPortID] = '\0';
proto_tree_add_string (tree, hf_pn_io_peer_port_id, tvb, offset, u8LengthPeerPortID, pPeerPortID);
offset += u8LengthPeerPortID;
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_length_peer_chassis_id, &u8LengthPeerChassisID);
pPeerChassisID = (char *)ep_alloc(u8LengthPeerChassisID+1);
tvb_memcpy(tvb, (guint8 *) pPeerChassisID, offset, u8LengthPeerChassisID);
pPeerChassisID[u8LengthPeerChassisID] = '\0';
proto_tree_add_string (tree, hf_pn_io_peer_chassis_id, tvb, offset, u8LengthPeerChassisID, pPeerChassisID);
offset += u8LengthPeerChassisID;
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_line_delay, &u32LineDelay);
offset = dissect_pn_mac(tvb, offset, pinfo, tree,
hf_pn_io_peer_macadd, mac);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mau_type, &u16MAUType);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_domain_boundary, &u32DomainBoundary);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_multicast_boundary, &u32MulticastBoundary);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_port_state, &u16PortState);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_media_type, &u32MediaType);
proto_item_append_text(item, ": Slot:0x%x/0x%x, OwnPortID:%s, Peers:%u PortState:%s MediaType:%s",
u16SlotNr, u16SubslotNr, pOwnPortID, u8NumberOfPeers,
val_to_str(u16PortState, pn_io_port_state, "0x%x"),
val_to_str(u32MediaType, pn_io_media_type, "0x%x"));
return offset;
}
static int
dissect_PDInterfaceMrpDataAdjust_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow, guint16 u16BodyLength)
{
e_uuid_t uuid;
guint16 u16Role;
guint8 u8LengthDomainName;
guint8 u8NumberOfMrpInstances;
char *pDomainName;
int iStartOffset = offset;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow > 1) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
if (u8BlockVersionLow == 0)
{
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_domain_uuid, &uuid);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_role, &u16Role);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_length_domain_name, &u8LengthDomainName);
pDomainName = (char *)ep_alloc(u8LengthDomainName+1);
tvb_memcpy(tvb, (guint8 *) pDomainName, offset, u8LengthDomainName);
pDomainName[u8LengthDomainName] = '\0';
proto_tree_add_string (tree, hf_pn_io_mrp_domain_name, tvb, offset, u8LengthDomainName, pDomainName);
offset += u8LengthDomainName;
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
if ((offset - iStartOffset) < u16BodyLength)
{
offset = dissect_blocks(tvb, offset, pinfo, tree, drep);
}
}
else if (u8BlockVersionLow == 1)
{
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 1);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_instances, &u8NumberOfMrpInstances);
if (u8NumberOfMrpInstances > 0xf) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Number of MrpInstances greater 0x0f is (0x%x)", u8NumberOfMrpInstances);
return offset;
}
while(u8NumberOfMrpInstances > 0)
{
offset = dissect_a_block(tvb, offset, pinfo, tree, drep);
u8NumberOfMrpInstances--;
}
}
return offset;
}
static int
dissect_PDInterfaceMrpDataReal_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow, guint16 u16BodyLength)
{
e_uuid_t uuid;
guint16 u16Role;
guint16 u16Version;
guint8 u8LengthDomainName;
guint8 u8NumberOfMrpInstances;
char *pDomainName;
int endoffset = offset + u16BodyLength;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow > 2) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
if (u8BlockVersionLow < 2)
{
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_domain_uuid, &uuid);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_role, &u16Role);
if (u8BlockVersionLow == 1) {
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_version, &u16Version);
}
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_length_domain_name, &u8LengthDomainName);
pDomainName = (char *)ep_alloc(u8LengthDomainName+1);
tvb_memcpy(tvb, (guint8 *) pDomainName, offset, u8LengthDomainName);
pDomainName[u8LengthDomainName] = '\0';
proto_tree_add_string (tree, hf_pn_io_mrp_domain_name, tvb, offset, u8LengthDomainName, pDomainName);
offset += u8LengthDomainName;
if (u8BlockVersionLow == 0) {
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_version, &u16Version);
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
while(endoffset > offset)
{
offset = dissect_a_block(tvb, offset, pinfo, tree, drep);
}
}
else if (u8BlockVersionLow == 2)
{
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 1);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_instances, &u8NumberOfMrpInstances);
if (u8NumberOfMrpInstances > 0xf) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Number of MrpInstances greater 0x0f is (0x%x)", u8NumberOfMrpInstances);
return offset;
}
while(u8NumberOfMrpInstances > 0)
{
offset = dissect_a_block(tvb, offset, pinfo, tree, drep);
u8NumberOfMrpInstances--;
}
}
return offset;
}
static int
dissect_PDInterfaceMrpDataCheck_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
e_uuid_t uuid;
guint32 u32Check;
guint8 u8NumberOfMrpInstances;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow > 1) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
if (u8BlockVersionLow == 0)
{
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_domain_uuid, &uuid);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_check, &u32Check);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_check_mrm, &u32Check);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_check_mrpdomain, &u32Check);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_check_reserved_1, &u32Check);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_check_reserved_2, &u32Check);
offset +=4;
}
else if (u8BlockVersionLow == 1)
{
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 1);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_instances, &u8NumberOfMrpInstances);
if (u8NumberOfMrpInstances > 0xf) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Number of MrpInstances greater 0x0f is (0x%x)", u8NumberOfMrpInstances);
return offset;
}
while(u8NumberOfMrpInstances > 0)
{
offset = dissect_a_block(tvb, offset, pinfo, tree, drep);
u8NumberOfMrpInstances--;
}
}
return offset;
}
static int
dissect_PDPortMrpData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
e_uuid_t uuid;
guint8 u8MrpInstance;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow > 1) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
if (u8BlockVersionLow == 0) {
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
}
else
{
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 1);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_instance, &u8MrpInstance);
}
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_domain_uuid, &uuid);
return offset;
}
static int
dissect_MrpManagerParams_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16Prio;
guint16 u16TOPchgT;
guint16 u16TOPNRmax;
guint16 u16TSTshortT;
guint16 u16TSTdefaultT;
guint16 u16TSTNRmax;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_prio, &u16Prio);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_topchgt, &u16TOPchgT);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_topnrmax, &u16TOPNRmax);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_tstshortt, &u16TSTshortT);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_tstdefaultt, &u16TSTdefaultT);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_tstnrmax, &u16TSTNRmax);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_MrpRTMode(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep)
{
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32RTMode;
sub_item = proto_tree_add_item(tree, hf_pn_io_mrp_rtmode, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_mrp_rtmode);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_mrp_rtmode_reserved2, &u32RTMode);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_mrp_rtmode_reserved1, &u32RTMode);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_mrp_rtmode_rtclass3, &u32RTMode);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_mrp_rtmode_rtclass12, &u32RTMode);
return offset;
}
static int
dissect_MrpRTModeManagerData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16TSTNRmax;
guint16 u16TSTdefaultT;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_tstnrmax, &u16TSTNRmax);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_tstdefaultt, &u16TSTdefaultT);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_MrpRTMode(tvb, offset, pinfo, tree, item, drep);
return offset;
}
static int
dissect_MrpRingStateData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16RingState;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_ring_state, &u16RingState);
return offset;
}
static int
dissect_MrpRTStateData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16RTState;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_rt_state, &u16RTState);
return offset;
}
static int
dissect_MrpClientParams_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16MRP_LNKdownT;
guint16 u16MRP_LNKupT;
guint16 u16MRP_LNKNRmax;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_lnkdownt, &u16MRP_LNKdownT);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_lnkupt, &u16MRP_LNKupT);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_lnknrmax, &u16MRP_LNKNRmax);
return offset;
}
static int
dissect_MrpRTModeClientData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_MrpRTMode(tvb, offset, pinfo, tree, item, drep);
return offset;
}
static int
dissect_CheckSyncDifference_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
proto_item *sub_item;
proto_tree *sub_tree;
guint16 u16CheckSyncMode;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
sub_item = proto_tree_add_item(tree, hf_pn_io_check_sync_mode, tvb, offset, 2, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_check_sync_mode);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_check_sync_mode_reserved, &u16CheckSyncMode);
dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_check_sync_mode_sync_master, &u16CheckSyncMode);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_check_sync_mode_cable_delay, &u16CheckSyncMode);
proto_item_append_text(sub_item, "CheckSyncMode: SyncMaster:%d, CableDelay:%d",
(u16CheckSyncMode >> 1) & 1, u16CheckSyncMode & 1);
proto_item_append_text(item, " : SyncMaster:%d, CableDelay:%d",
(u16CheckSyncMode >> 1) & 1, u16CheckSyncMode & 1);
return offset;
}
static int
dissect_CheckMAUTypeDifference_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16MAUTypeMode;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mau_type_mode, &u16MAUTypeMode);
proto_item_append_text(item, ": MAUTypeMode:%s",
val_to_str(u16MAUTypeMode, pn_io_mau_type_mode, "0x%x"));
return offset;
}
static int
dissect_AdjustDomainBoundary_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint32 u32DomainBoundary;
guint32 u32DomainBoundaryIngress;
guint32 u32DomainBoundaryEgress;
guint16 u16AdjustProperties;
if (u8BlockVersionHigh != 1 || (u8BlockVersionLow != 0 && u8BlockVersionLow != 1)) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
switch (u8BlockVersionLow) {
case(0):
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_domain_boundary, &u32DomainBoundary);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_adjust_properties, &u16AdjustProperties);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
proto_item_append_text(item, ": Boundary:0x%x, Properties:0x%x",
u32DomainBoundary, u16AdjustProperties);
break;
case(1):
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_domain_boundary_ingress, &u32DomainBoundaryIngress);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_domain_boundary_egress, &u32DomainBoundaryEgress);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_adjust_properties, &u16AdjustProperties);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
proto_item_append_text(item, ": BoundaryIngress:0x%x, BoundaryEgress:0x%x, Properties:0x%x",
u32DomainBoundaryIngress, u32DomainBoundaryEgress, u16AdjustProperties);
break;
default:
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
return offset;
}
static int
dissect_AdjustMulticastBoundary_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint32 u32MulticastBoundary;
guint16 u16AdjustProperties;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_multicast_boundary, &u32MulticastBoundary);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_adjust_properties, &u16AdjustProperties);
proto_item_append_text(item, ": Boundary:0x%x, Properties:0x%x",
u32MulticastBoundary, u16AdjustProperties);
return offset;
}
static int
dissect_AdjustMAUType_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16MAUType;
guint16 u16AdjustProperties;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mau_type, &u16MAUType);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_adjust_properties, &u16AdjustProperties);
proto_item_append_text(item, ": MAUType:%s, Properties:0x%x",
val_to_str(u16MAUType, pn_io_mau_type, "0x%x"),
u16AdjustProperties);
return offset;
}
static int
dissect_CheckMAUType_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16MAUType;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mau_type, &u16MAUType);
proto_item_append_text(item, ": MAUType:%s",
val_to_str(u16MAUType, pn_io_mau_type, "0x%x"));
return offset;
}
static int
dissect_CheckLineDelay_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint32 u32LineDelay;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_line_delay, &u32LineDelay);
proto_item_append_text(item, ": LineDelay:%uns", u32LineDelay);
return offset;
}
static int
dissect_CheckPeers_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint8 u8NumberOfPeers;
guint8 u8I;
guint8 u8LengthPeerPortID;
char *pPeerPortID;
guint8 u8LengthPeerChassisID;
char *pPeerChassisID;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_number_of_peers, &u8NumberOfPeers);
u8I = u8NumberOfPeers;
while (u8I--) {
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_length_peer_port_id, &u8LengthPeerPortID);
pPeerPortID = (char *)ep_alloc(u8LengthPeerPortID+1);
tvb_memcpy(tvb, (guint8 *) pPeerPortID, offset, u8LengthPeerPortID);
pPeerPortID[u8LengthPeerPortID] = '\0';
proto_tree_add_string (tree, hf_pn_io_peer_port_id, tvb, offset, u8LengthPeerPortID, pPeerPortID);
offset += u8LengthPeerPortID;
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_length_peer_chassis_id, &u8LengthPeerChassisID);
pPeerChassisID = (char *)ep_alloc(u8LengthPeerChassisID+1);
tvb_memcpy(tvb, (guint8 *) pPeerChassisID, offset, u8LengthPeerChassisID);
pPeerChassisID[u8LengthPeerChassisID] = '\0';
proto_tree_add_string (tree, hf_pn_io_peer_chassis_id, tvb, offset, u8LengthPeerChassisID, pPeerChassisID);
offset += u8LengthPeerChassisID;
}
proto_item_append_text(item, ": NumberOfPeers:%u", u8NumberOfPeers);
return offset;
}
static int
dissect_AdjustPortState_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16PortState;
guint16 u16AdjustProperties;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_port_state, &u16PortState);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_adjust_properties, &u16AdjustProperties);
proto_item_append_text(item, ": PortState:%s, Properties:0x%x",
val_to_str(u16PortState, pn_io_port_state, "0x%x"),
u16AdjustProperties);
return offset;
}
static int
dissect_CheckPortState_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16PortState;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_port_state, &u16PortState);
proto_item_append_text(item, ": %s",
val_to_str(u16PortState, pn_io_port_state, "0x%x"));
return offset;
}
static int
dissect_PDPortFODataReal_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 u16BodyLength)
{
guint32 u32FiberOpticType;
guint32 u32FiberOpticCableType;
guint16 u16Index = 0;
guint32 u32RecDataLen;
pnio_ar_t *ar = NULL;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_fiber_optic_type, &u32FiberOpticType);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_fiber_optic_cable_type, &u32FiberOpticCableType);
if (u16BodyLength != 10) {
dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
}
return offset;
}
static int
dissect_FiberOpticManufacturerSpecific_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 u16BodyLength)
{
guint8 u8VendorIDHigh;
guint8 u8VendorIDLow;
guint16 u16VendorBlockType;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_vendor_id_high, &u8VendorIDHigh);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_vendor_id_low, &u8VendorIDLow);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_vendor_block_type, &u16VendorBlockType);
offset = dissect_pn_user_data(tvb, offset, pinfo, tree, u16BodyLength-4, "Data");
return offset;
}
static int
dissect_PDPortFODataAdjust_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint32 u32FiberOpticType;
guint32 u32FiberOpticCableType;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_fiber_optic_type, &u32FiberOpticType);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_fiber_optic_cable_type, &u32FiberOpticCableType);
return offset;
}
static int
dissect_PDPortFODataCheck_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint32 u32FiberOpticPowerBudget;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_maintenance_required_power_budget, &u32FiberOpticPowerBudget);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_maintenance_demanded_power_budget, &u32FiberOpticPowerBudget);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_error_power_budget, &u32FiberOpticPowerBudget);
return offset;
}
static int
dissect_MrpInstanceDataAdjust_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow, guint16 u16BodyLength)
{
guint8 u8MrpInstance;
e_uuid_t uuid;
guint16 u16Role;
guint8 u8LengthDomainName;
char* pDomainName;
int endoffset = offset + u16BodyLength;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 1);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_instance, &u8MrpInstance);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_domain_uuid, &uuid);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_role, &u16Role);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_length_domain_name, &u8LengthDomainName);
pDomainName = (char *)ep_alloc(u8LengthDomainName+1);
tvb_memcpy(tvb, (guint8 *) pDomainName, offset, u8LengthDomainName);
pDomainName[u8LengthDomainName] = '\0';
proto_tree_add_string (tree, hf_pn_io_mrp_domain_name, tvb, offset, u8LengthDomainName, pDomainName);
offset += u8LengthDomainName;
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
while(endoffset > offset)
{
offset = dissect_a_block(tvb, offset, pinfo, tree, drep);
}
return offset;
}
static int
dissect_MrpInstanceDataReal_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow, guint16 u16BodyLength)
{
guint8 u8MrpInstance;
e_uuid_t uuid;
guint16 u16Role;
guint16 u16Version;
guint8 u8LengthDomainName;
char* pDomainName;
int endoffset = offset + u16BodyLength;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 1);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_instance, &u8MrpInstance);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_domain_uuid, &uuid);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_role, &u16Role);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_version, &u16Version);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_length_domain_name, &u8LengthDomainName);
pDomainName = (char *)ep_alloc(u8LengthDomainName+1);
tvb_memcpy(tvb, (guint8 *) pDomainName, offset, u8LengthDomainName);
pDomainName[u8LengthDomainName] = '\0';
proto_tree_add_string (tree, hf_pn_io_mrp_domain_name, tvb, offset, u8LengthDomainName, pDomainName);
offset += u8LengthDomainName;
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
while(endoffset > offset)
{
offset = dissect_a_block(tvb, offset, pinfo, tree, drep);
}
return offset;
}
static int
dissect_MrpInstanceDataCheck_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow, guint16 u16BodyLength _U_)
{
guint8 u8MrpInstance;
guint32 u32Check;
e_uuid_t uuid;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 1);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_instance, &u8MrpInstance);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_domain_uuid, &uuid);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_check, &u32Check);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_check_mrm, &u32Check);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_check_mrpdomain, &u32Check);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_check_reserved_1, &u32Check);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_mrp_check_reserved_2, &u32Check);
offset +=4;
return offset;
}
static int
dissect_PDInterfaceAdjust_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint32 u32SMultipleInterfaceMode;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_MultipleInterfaceMode_NameOfDevice, &u32SMultipleInterfaceMode);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_MultipleInterfaceMode_reserved_1, &u32SMultipleInterfaceMode);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_MultipleInterfaceMode_reserved_2, &u32SMultipleInterfaceMode);
return offset;
}
static int
dissect_PDPortStatistic_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint32 u32StatValue;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_pdportstatistic_ifInOctets, &u32StatValue);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_pdportstatistic_ifOutOctets, &u32StatValue);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_pdportstatistic_ifInDiscards, &u32StatValue);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_pdportstatistic_ifOutDiscards, &u32StatValue);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_pdportstatistic_ifInErrors, &u32StatValue);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_pdportstatistic_ifOutErrors, &u32StatValue);
return offset;
}
static int
dissect_PDInterfaceDataReal_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint8 u8LengthOwnChassisID;
char *pOwnChassisID;
guint8 mac[6];
guint32 ip;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_length_own_chassis_id, &u8LengthOwnChassisID);
pOwnChassisID = (char *)ep_alloc(u8LengthOwnChassisID+1);
tvb_memcpy(tvb, (guint8 *) pOwnChassisID, offset, u8LengthOwnChassisID);
pOwnChassisID[u8LengthOwnChassisID] = '\0';
proto_tree_add_string (tree, hf_pn_io_own_chassis_id, tvb, offset, u8LengthOwnChassisID, pOwnChassisID);
offset += u8LengthOwnChassisID;
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_pn_mac(tvb, offset, pinfo, tree, hf_pn_io_macadd, mac);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_pn_ipv4(tvb, offset, pinfo, tree, hf_pn_io_ip_address, &ip);
offset = dissect_pn_ipv4(tvb, offset, pinfo, tree, hf_pn_io_subnetmask, &ip);
offset = dissect_pn_ipv4(tvb, offset, pinfo, tree, hf_pn_io_standard_gateway, &ip);
return offset;
}
static int
dissect_PDSyncData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16SlotNr;
guint16 u16SubslotNr;
e_uuid_t uuid;
guint32 u32ReservedIntervalBegin;
guint32 u32ReservedIntervalEnd;
guint32 u32PLLWindow;
guint32 u32SyncSendFactor;
guint16 u16SendClockFactor;
guint16 u16SyncProperties;
guint16 u16SyncFrameAddress;
guint16 u16PTCPTimeoutFactor;
guint16 u16PTCPTakeoverTimeoutFactor;
guint16 u16PTCPMasterStartupTime;
guint8 u8MasterPriority1;
guint8 u8MasterPriority2;
guint8 u8LengthSubdomainName;
char *pSubdomainName;
if (u8BlockVersionHigh != 1) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
switch (u8BlockVersionLow) {
case(0):
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_ptcp_subdomain_id, &uuid);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_ir_data_id, &uuid);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_reserved_interval_begin, &u32ReservedIntervalBegin);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_reserved_interval_end, &u32ReservedIntervalEnd);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_pllwindow, &u32PLLWindow);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_sync_send_factor, &u32SyncSendFactor);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_send_clock_factor, &u16SendClockFactor);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_sync_properties, &u16SyncProperties);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_sync_frame_address, &u16SyncFrameAddress);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ptcp_timeout_factor, &u16PTCPTimeoutFactor);
proto_item_append_text(item, ": Slot:0x%x/0x%x, Interval:%u-%u, PLLWin:%u, Send:%u, Clock:%u",
u16SlotNr, u16SubslotNr, u32ReservedIntervalBegin, u32ReservedIntervalEnd,
u32PLLWindow, u32SyncSendFactor, u16SendClockFactor);
break;
case(2):
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_ptcp_subdomain_id, &uuid);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_reserved_interval_begin, &u32ReservedIntervalBegin);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_reserved_interval_end, &u32ReservedIntervalEnd);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_pllwindow, &u32PLLWindow);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_sync_send_factor, &u32SyncSendFactor);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_send_clock_factor, &u16SendClockFactor);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ptcp_timeout_factor, &u16PTCPTimeoutFactor);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ptcp_takeover_timeout_factor, &u16PTCPTakeoverTimeoutFactor);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ptcp_master_startup_time, &u16PTCPMasterStartupTime);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_sync_properties, &u16SyncProperties);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_ptcp_master_priority_1, &u8MasterPriority1);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_ptcp_master_priority_2, &u8MasterPriority2);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, tree, drep,
hf_pn_io_ptcp_length_subdomain_name, &u8LengthSubdomainName);
pSubdomainName = (char *)ep_alloc(u8LengthSubdomainName+1);
tvb_memcpy(tvb, (guint8 *) pSubdomainName, offset, u8LengthSubdomainName);
pSubdomainName[u8LengthSubdomainName] = '\0';
proto_tree_add_string (tree, hf_pn_io_ptcp_subdomain_name, tvb, offset, u8LengthSubdomainName, pSubdomainName);
offset += u8LengthSubdomainName;
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
proto_item_append_text(item, ": Interval:%u-%u, PLLWin:%u, Send:%u, Clock:%u",
u32ReservedIntervalBegin, u32ReservedIntervalEnd,
u32PLLWindow, u32SyncSendFactor, u16SendClockFactor);
break;
default:
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
}
return offset;
}
static int
dissect_PDIRData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16SlotNr;
guint16 u16SubslotNr;
guint16 u16Index = 0;
guint32 u32RecDataLen;
pnio_ar_t *ar = NULL;
if (u8BlockVersionHigh != 1 || (u8BlockVersionLow > 2 ) ) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
proto_item_append_text(item, ": Slot:0x%x/0x%x",
u16SlotNr, u16SubslotNr);
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
if (u8BlockVersionLow == 0) {
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
} else if (u8BlockVersionLow == 1) {
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
}else if (u8BlockVersionLow == 2) {
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
}
return offset;
}
static int
dissect_PDIRGlobalData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
e_uuid_t uuid;
guint32 u32MaxBridgeDelay;
guint32 u32NumberOfPorts;
guint32 u32MaxPortTxDelay;
guint32 u32MaxPortRxDelay;
guint32 u32MaxLineRxDelay;
guint32 u32YellowTime;
guint32 u32Tmp;
if (u8BlockVersionHigh != 1 || (u8BlockVersionLow > 2)) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_ir_data_id, &uuid);
if (u8BlockVersionLow <= 2) {
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_max_bridge_delay, &u32MaxBridgeDelay);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_number_of_ports, &u32NumberOfPorts);
u32Tmp = u32NumberOfPorts;
while (u32Tmp--) {
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_max_port_tx_delay, &u32MaxPortTxDelay);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_max_port_rx_delay, &u32MaxPortRxDelay);
if (u8BlockVersionLow >= 2) {
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_max_line_rx_delay, &u32MaxLineRxDelay);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_yellowtime, &u32YellowTime);
}
}
proto_item_append_text(item, ": MaxBridgeDelay:%u, NumberOfPorts:%u",
u32MaxBridgeDelay, u32NumberOfPorts);
}
return offset;
}
static int
dissect_PDIRFrameData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 u16BodyLength)
{
guint32 u32FrameSendOffset;
guint32 u32FrameDataProperties;
guint16 u16DataLength;
guint16 u16ReductionRatio;
guint16 u16Phase;
guint16 u16FrameID;
guint16 u16Ethertype;
guint8 u8RXPort;
guint8 u8FrameDetails;
guint8 u8NumberOfTxPortGroups;
guint8 u8TxPortGroupArray;
guint16 u16TxPortGroupArraySize;
guint16 u16EndOffset;
guint16 n = 0;
proto_item *sub_item;
proto_tree *sub_tree;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow > 1) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
u16EndOffset = offset + u16BodyLength -2;
if (u8BlockVersionLow > 0) {
sub_item = proto_tree_add_item(tree, hf_pn_io_frame_data_properties, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_FrameDataProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_frame_data_properties_forwarding_Mode, &u32FrameDataProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_frame_data_properties_FastForwardingMulticastMACAdd, &u32FrameDataProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_frame_data_properties_FragmentMode, &u32FrameDataProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_frame_data_properties_reserved_1, &u32FrameDataProperties);
offset =
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_frame_data_properties_reserved_2, &u32FrameDataProperties);
}
while (offset < u16EndOffset)
{
proto_item *ir_frame_data_sub_item;
proto_tree *ir_frame_data_tree;
n++;
ir_frame_data_sub_item = proto_tree_add_item(tree, hf_pn_io_ir_frame_data, tvb, offset, 17, ENC_NA);
ir_frame_data_tree = proto_item_add_subtree(ir_frame_data_sub_item, ett_pn_io_ir_frame_data);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, ir_frame_data_tree, drep,
hf_pn_io_frame_send_offset, &u32FrameSendOffset);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ir_frame_data_tree, drep,
hf_pn_io_data_length, &u16DataLength);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ir_frame_data_tree, drep,
hf_pn_io_reduction_ratio, &u16ReductionRatio);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ir_frame_data_tree, drep,
hf_pn_io_phase, &u16Phase);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ir_frame_data_tree, drep,
hf_pn_io_frame_id, &u16FrameID);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ir_frame_data_tree, drep,
hf_pn_io_ethertype, &u16Ethertype);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, ir_frame_data_tree, drep,
hf_pn_io_rx_port, &u8RXPort);
sub_item = proto_tree_add_item(ir_frame_data_tree, hf_pn_io_frame_details, tvb, offset, 1, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_frame_defails);
dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_frame_details_sync_frame, &u8FrameDetails);
dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_frame_details_meaning_frame_send_offset, &u8FrameDetails);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_frame_details_reserved, &u8FrameDetails);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, ir_frame_data_tree, drep,
hf_pn_io_nr_of_tx_port_groups, &u8NumberOfTxPortGroups);
if ((u8NumberOfTxPortGroups > 21) || ((u8NumberOfTxPortGroups & 0x1) !=1)) {
proto_tree_add_text(ir_frame_data_tree, tvb, offset -1, 1, "Not allowed value of NumberOfTxPortGroups");
}
u16TxPortGroupArraySize = (u8NumberOfTxPortGroups + 7 / 8);
sub_item = proto_tree_add_item(ir_frame_data_tree, hf_pn_io_TxPortGroupProperties,
tvb, offset, u16TxPortGroupArraySize, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_GroupProperties);
while (u16TxPortGroupArraySize > 0)
{
dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep, hf_pn_io_TxPortGroupProperties_bit0, &u8TxPortGroupArray);
dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep, hf_pn_io_TxPortGroupProperties_bit1, &u8TxPortGroupArray);
dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep, hf_pn_io_TxPortGroupProperties_bit2, &u8TxPortGroupArray);
dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep, hf_pn_io_TxPortGroupProperties_bit3, &u8TxPortGroupArray);
dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep, hf_pn_io_TxPortGroupProperties_bit4, &u8TxPortGroupArray);
dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep, hf_pn_io_TxPortGroupProperties_bit5, &u8TxPortGroupArray);
dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep, hf_pn_io_TxPortGroupProperties_bit6, &u8TxPortGroupArray);
dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep, hf_pn_io_TxPortGroupProperties_bit7, &u8TxPortGroupArray);
offset+=1;
u16TxPortGroupArraySize --;
}
offset = dissect_pn_align4(tvb, offset, pinfo, ir_frame_data_tree);
proto_item_append_text(ir_frame_data_tree, ": Offset:%u, Len:%u, Ratio:%u, Phase:%u, FrameID:0x%04x",
u32FrameSendOffset, u16DataLength, u16ReductionRatio, u16Phase, u16FrameID);
}
proto_item_append_text(item, ": Frames:%u", n);
return offset;
}
static int
dissect_PDIRBeginEndData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 u16BodyLength)
{
guint16 u16StartOfRedFrameID;
guint16 u16EndOfRedFrameID;
guint32 u32NumberOfPorts;
guint32 u32NumberOfAssignments;
guint32 u32NumberOfPhases;
guint32 u32RedOrangePeriodBegin;
guint32 u32OrangePeriodBegin;
guint32 u32GreenPeriodBegin;
guint16 u16TXPhaseAssignment;
guint16 u16RXPhaseAssignment;
guint32 u32SubStart;
guint32 u32Tmp;
guint32 u32Tmp2;
guint32 u32TxRedOrangePeriodBegin[0x11] = {0};
guint32 u32TxOrangePeriodBegin [0x11] = {0};
guint32 u32TxGreenPeriodBegin [0x11] = {0};
guint32 u32RxRedOrangePeriodBegin[0x11] = {0};
guint32 u32RxOrangePeriodBegin [0x11] = {0};
guint32 u32RxGreenPeriodBegin [0x11] = {0};
guint32 u32PortIndex;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_start_of_red_frame_id, &u16StartOfRedFrameID);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_end_of_red_frame_id, &u16EndOfRedFrameID);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_number_of_ports, &u32NumberOfPorts);
u32Tmp2 = u32NumberOfPorts;
while (u32Tmp2--) {
proto_item *ir_begin_end_port_sub_item;
proto_tree *ir_begin_end_port_tree;
ir_begin_end_port_sub_item = proto_tree_add_item(tree, hf_pn_io_ir_begin_end_port, tvb, offset, 0, ENC_NA);
ir_begin_end_port_tree = proto_item_add_subtree(ir_begin_end_port_sub_item, ett_pn_io_ir_begin_end_port);
u32SubStart = offset;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, ir_begin_end_port_tree, drep,
hf_pn_io_number_of_assignments, &u32NumberOfAssignments);
u32Tmp = u32NumberOfAssignments;
u32PortIndex = 0;
if (u32Tmp <= 0x10)
{
while (u32Tmp--) {
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, ir_begin_end_port_tree, drep,
hf_pn_io_red_orange_period_begin_tx, &u32RedOrangePeriodBegin);
u32TxRedOrangePeriodBegin[u32PortIndex] = u32RedOrangePeriodBegin;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, ir_begin_end_port_tree, drep,
hf_pn_io_orange_period_begin_tx, &u32OrangePeriodBegin);
u32TxOrangePeriodBegin[u32PortIndex]= u32OrangePeriodBegin;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, ir_begin_end_port_tree, drep,
hf_pn_io_green_period_begin_tx, &u32GreenPeriodBegin);
u32TxGreenPeriodBegin[u32PortIndex] = u32GreenPeriodBegin;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, ir_begin_end_port_tree, drep,
hf_pn_io_red_orange_period_begin_rx, &u32RedOrangePeriodBegin);
u32RxRedOrangePeriodBegin[u32PortIndex] = u32RedOrangePeriodBegin;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, ir_begin_end_port_tree, drep,
hf_pn_io_orange_period_begin_rx, &u32OrangePeriodBegin);
u32RxOrangePeriodBegin[u32PortIndex]= u32OrangePeriodBegin;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, ir_begin_end_port_tree, drep,
hf_pn_io_green_period_begin_rx, &u32GreenPeriodBegin);
u32RxGreenPeriodBegin[u32PortIndex] = u32GreenPeriodBegin;
u32PortIndex++;
}
}
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, ir_begin_end_port_tree, drep,
hf_pn_io_number_of_phases, &u32NumberOfPhases);
u32Tmp = u32NumberOfPhases;
if (u32Tmp <= 0x10)
{
while (u32Tmp--) {
proto_item *ir_begin_tx_phase_sub_item;
proto_tree *ir_begin_tx_phase_tree;
ir_begin_tx_phase_sub_item = proto_tree_add_item(ir_begin_end_port_tree,
hf_pn_ir_tx_phase_assignment, tvb, offset, 0, ENC_NA);
ir_begin_tx_phase_tree = proto_item_add_subtree(ir_begin_tx_phase_sub_item, ett_pn_io_ir_tx_phase);
dissect_dcerpc_uint16(tvb, offset, pinfo, ir_begin_tx_phase_tree, drep,
hf_pn_io_tx_phase_assignment_begin_value, &u16TXPhaseAssignment);
dissect_dcerpc_uint16(tvb, offset, pinfo, ir_begin_tx_phase_tree, drep,
hf_pn_io_tx_phase_assignment_orange_begin, &u16TXPhaseAssignment);
dissect_dcerpc_uint16(tvb, offset, pinfo, ir_begin_tx_phase_tree, drep,
hf_pn_io_tx_phase_assignment_end_reserved, &u16TXPhaseAssignment);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ir_begin_tx_phase_tree, drep,
hf_pn_io_tx_phase_assignment_reserved, &u16TXPhaseAssignment);
proto_item_append_text(ir_begin_tx_phase_sub_item,
": 0x%x, RedOrangePeriodBegin: %d, OrangePeriodBegin: %d, GreenPeriodBegin: %d",
u16TXPhaseAssignment,
u32TxRedOrangePeriodBegin[u16TXPhaseAssignment & 0x0F],
u32TxOrangePeriodBegin[(u16TXPhaseAssignment & 0x0F0) >> 4],
u32TxGreenPeriodBegin[(u16TXPhaseAssignment & 0x0F00)>> 8]);
ir_begin_tx_phase_sub_item = proto_tree_add_item(ir_begin_end_port_tree,
hf_pn_ir_rx_phase_assignment, tvb, offset, 0, ENC_NA);
ir_begin_tx_phase_tree = proto_item_add_subtree(ir_begin_tx_phase_sub_item, ett_pn_io_ir_rx_phase);
dissect_dcerpc_uint16(tvb, offset, pinfo, ir_begin_tx_phase_tree, drep,
hf_pn_io_tx_phase_assignment_begin_value, &u16RXPhaseAssignment);
dissect_dcerpc_uint16(tvb, offset, pinfo, ir_begin_tx_phase_tree, drep,
hf_pn_io_tx_phase_assignment_orange_begin, &u16RXPhaseAssignment);
dissect_dcerpc_uint16(tvb, offset, pinfo, ir_begin_tx_phase_tree, drep,
hf_pn_io_tx_phase_assignment_end_reserved, &u16RXPhaseAssignment);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ir_begin_tx_phase_tree, drep,
hf_pn_io_tx_phase_assignment_reserved, &u16RXPhaseAssignment);
proto_item_append_text(ir_begin_tx_phase_sub_item,
": 0x%x, RedOrangePeriodBegin: %d, OrangePeriodBegin: %d, GreenPeriodBegin: %d",
u16RXPhaseAssignment,
u32RxRedOrangePeriodBegin[u16RXPhaseAssignment & 0x0F],
u32RxOrangePeriodBegin[(u16RXPhaseAssignment & 0x0F0) >> 4],
u32RxGreenPeriodBegin[(u16RXPhaseAssignment & 0x0F00)>> 8]);
}
}
proto_item_append_text(ir_begin_end_port_sub_item, ": Assignments:%u, Phases:%u",
u32NumberOfAssignments, u32NumberOfPhases);
proto_item_set_len(ir_begin_end_port_sub_item, offset - u32SubStart);
}
proto_item_append_text(item, ": StartOfRedFrameID: 0x%x, EndOfRedFrameID: 0x%x, Ports: %u",
u16StartOfRedFrameID, u16EndOfRedFrameID, u32NumberOfPorts);
return offset+u16BodyLength;
}
static int
dissect_DiagnosisData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint8 *drep _U_, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 body_length)
{
guint32 u32Api;
guint16 u16SlotNr;
guint16 u16SubslotNr;
guint16 u16ChannelNumber;
guint16 u16UserStructureIdentifier;
if (u8BlockVersionHigh != 1 || (u8BlockVersionLow != 0 && u8BlockVersionLow != 1)) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
if (u8BlockVersionLow == 1) {
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_api, &u32Api);
body_length-=4;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_channel_number, &u16ChannelNumber);
offset = dissect_ChannelProperties(tvb, offset, pinfo, tree, item, drep);
body_length-=8;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_user_structure_identifier, &u16UserStructureIdentifier);
proto_item_append_text(item, ", USI:0x%x", u16UserStructureIdentifier);
body_length-=2;
while (body_length) {
offset = dissect_AlarmUserStructure(tvb, offset, pinfo, tree, item, drep,
&body_length, u16UserStructureIdentifier);
}
return offset;
}
static int
dissect_ARProperties(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint8 *drep _U_)
{
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32ARProperties;
sub_item = proto_tree_add_item(tree, hf_pn_io_ar_properties, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_ar_properties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_ar_properties_pull_module_alarm_allowed, &u32ARProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_arproperties_StartupMode, &u32ARProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_ar_properties_reserved, &u32ARProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_ar_properties_achnowledge_companion_ar, &u32ARProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_ar_properties_companion_ar, &u32ARProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_ar_properties_device_access, &u32ARProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_ar_properties_reserved_1, &u32ARProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_ar_properties_parametrization_server, &u32ARProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_ar_properties_supervisor_takeover_allowed, &u32ARProperties);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_ar_properties_state, &u32ARProperties);
return offset;
}
static int
dissect_IOCRProperties(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32IOCRProperties;
sub_item = proto_tree_add_item(tree, hf_pn_io_iocr_properties, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_iocr_properties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_iocr_properties_full_subframe_structure, &u32IOCRProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_iocr_properties_distributed_subframe_watchdog, &u32IOCRProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_iocr_properties_fast_forwarding_mac_adr, &u32IOCRProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_iocr_properties_reserved_3, &u32IOCRProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_iocr_properties_reserved_2, &u32IOCRProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_iocr_properties_media_redundancy, &u32IOCRProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_iocr_properties_reserved_1, &u32IOCRProperties);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_iocr_properties_rtclass, &u32IOCRProperties);
return offset;
}
static int
dissect_ARData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint8 *drep _U_, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow, guint16 u16BlockLength)
{
guint16 u16NumberOfARs;
guint16 u16NumberofEntries;
e_uuid_t aruuid;
e_uuid_t uuid;
guint16 u16ARType;
char *pStationName;
guint16 u16NameLength;
guint16 u16NumberOfIOCRs;
guint16 u16IOCRType;
guint16 u16FrameID;
guint16 u16CycleCounter;
guint8 u8DataStatus;
guint8 u8TransferStatus;
proto_item *ds_item;
proto_tree *ds_tree;
guint16 u16UDPRTPort;
guint16 u16AlarmCRType;
guint16 u16LocalAlarmReference;
guint16 u16RemoteAlarmReference;
guint16 u16NumberOfAPIs;
guint32 u32Api;
proto_item *iocr_item;
proto_tree *iocr_tree;
proto_item *ar_item;
proto_tree *ar_tree;
guint32 u32IOCRStart;
gint32 i32EndOffset;
guint32 u32ARDataStart;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow > 1) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
i32EndOffset = offset + u16BlockLength;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_number_of_ars, &u16NumberOfARs);
if (u8BlockVersionLow == 0) {
while (u16NumberOfARs--) {
ar_item = proto_tree_add_item(tree, hf_pn_io_ar_data, tvb, offset, 0, ENC_NA);
ar_tree = proto_item_add_subtree(ar_item, ett_pn_io_ar_data);
u32ARDataStart = offset;
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, ar_tree, drep,
hf_pn_io_ar_uuid, &aruuid);
proto_item_append_text(ar_item, "ARUUID:%s", guid_to_str((const e_guid_t*) &aruuid));
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep,
hf_pn_io_ar_type, &u16ARType);
offset = dissect_ARProperties(tvb, offset, pinfo, ar_tree, item, drep);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, ar_tree, drep,
hf_pn_io_cminitiator_objectuuid, &uuid);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep,
hf_pn_io_station_name_length, &u16NameLength);
pStationName = (char *)ep_alloc(u16NameLength+1);
tvb_memcpy(tvb, (guint8 *) pStationName, offset, u16NameLength);
pStationName[u16NameLength] = '\0';
proto_tree_add_string (ar_tree, hf_pn_io_cminitiator_station_name, tvb, offset, u16NameLength, pStationName);
offset += u16NameLength;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep,
hf_pn_io_number_of_iocrs, &u16NumberOfIOCRs);
while (u16NumberOfIOCRs--) {
iocr_item = proto_tree_add_item(ar_tree, hf_pn_io_iocr_tree, tvb, offset, 0, ENC_NA);
iocr_tree = proto_item_add_subtree(iocr_item, ett_pn_io_iocr);
u32IOCRStart = offset;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, iocr_tree, drep,
hf_pn_io_iocr_type, &u16IOCRType);
offset = dissect_IOCRProperties(tvb, offset, pinfo, iocr_tree, drep);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, iocr_tree, drep,
hf_pn_io_frame_id, &u16FrameID);
proto_item_append_text(iocr_item, ": FrameID:0x%x", u16FrameID);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, iocr_tree, drep,
hf_pn_io_cycle_counter, &u16CycleCounter);
u8DataStatus = tvb_get_guint8(tvb, offset);
u8TransferStatus = tvb_get_guint8(tvb, offset+1);
ds_item = proto_tree_add_uint_format(iocr_tree, hf_pn_io_data_status,
tvb, offset, 1, u8DataStatus,
"DataStatus: 0x%02x (Frame: %s and %s, Provider: %s and %s)",
u8DataStatus,
(u8DataStatus & 0x04) ? "Valid" : "Invalid",
(u8DataStatus & 0x01) ? "Primary" : "Backup",
(u8DataStatus & 0x20) ? "Ok" : "Problem",
(u8DataStatus & 0x10) ? "Run" : "Stop");
ds_tree = proto_item_add_subtree(ds_item, ett_pn_io_data_status);
proto_tree_add_uint(ds_tree, hf_pn_io_data_status_res67, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(ds_tree, hf_pn_io_data_status_ok, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(ds_tree, hf_pn_io_data_status_operate, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(ds_tree, hf_pn_io_data_status_res3, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(ds_tree, hf_pn_io_data_status_valid, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(ds_tree, hf_pn_io_data_status_res1, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(ds_tree, hf_pn_io_data_status_primary, tvb, offset, 1, u8DataStatus);
offset++;
if (u8TransferStatus) {
proto_tree_add_uint_format(iocr_tree, hf_pn_io_transfer_status, tvb,
offset, 1, u8TransferStatus,
"TransferStatus: 0x%02x (ignore this frame)", u8TransferStatus);
} else {
proto_tree_add_uint_format(iocr_tree, hf_pn_io_transfer_status, tvb,
offset, 1, u8TransferStatus,
"TransferStatus: 0x%02x (OK)", u8TransferStatus);
}
offset++;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, iocr_tree, drep,
hf_pn_io_cminitiator_udprtport, &u16UDPRTPort);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, iocr_tree, drep,
hf_pn_io_cmresponder_udprtport, &u16UDPRTPort);
proto_item_set_len(iocr_item, offset - u32IOCRStart);
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep,
hf_pn_io_alarmcr_type, &u16AlarmCRType);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep,
hf_pn_io_localalarmref, &u16LocalAlarmReference);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep,
hf_pn_io_remotealarmref, &u16RemoteAlarmReference);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, ar_tree, drep,
hf_pn_io_parameter_server_objectuuid, &uuid);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep,
hf_pn_io_station_name_length, &u16NameLength);
pStationName = (char *)ep_alloc(u16NameLength+1);
tvb_memcpy(tvb, (guint8 *) pStationName, offset, u16NameLength);
pStationName[u16NameLength] = '\0';
proto_tree_add_string (ar_tree, hf_pn_io_parameter_server_station_name, tvb, offset, u16NameLength, pStationName);
offset += u16NameLength;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep,
hf_pn_io_number_of_apis, &u16NumberOfAPIs);
if (u16NumberOfAPIs > 0) {
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, ar_tree, drep,
hf_pn_io_api, &u32Api);
}
proto_item_set_len(ar_item, offset - u32ARDataStart);
}
}
else
{
while (u16NumberOfARs--) {
ar_item = proto_tree_add_item(tree, hf_pn_io_ar_data, tvb, offset, 0, ENC_NA);
ar_tree = proto_item_add_subtree(ar_item, ett_pn_io_ar_data);
u32ARDataStart = offset;
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, ar_tree, drep, hf_pn_io_ar_uuid, &aruuid);
proto_item_append_text(ar_item, "ARUUID:%s", guid_to_str((const e_guid_t*) &aruuid));
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, ar_tree, drep, hf_pn_io_cminitiator_objectuuid, &uuid);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, ar_tree, drep, hf_pn_io_parameter_server_objectuuid, &uuid);
offset = dissect_ARProperties(tvb, offset, pinfo, ar_tree, item, drep);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep, hf_pn_io_ar_type, &u16ARType);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep, hf_pn_io_alarmcr_type, &u16AlarmCRType);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep, hf_pn_io_localalarmref, &u16LocalAlarmReference);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep, hf_pn_io_remotealarmref, &u16RemoteAlarmReference);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep, hf_pn_io_cminitiator_udprtport, &u16UDPRTPort);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep, hf_pn_io_cmresponder_udprtport, &u16UDPRTPort);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep, hf_pn_io_station_name_length, &u16NameLength);
pStationName = (char *)ep_alloc(u16NameLength+1);
tvb_memcpy(tvb, (guint8 *) pStationName, offset, u16NameLength);
pStationName[u16NameLength] = '\0';
proto_tree_add_string (ar_tree, hf_pn_io_cminitiator_station_name, tvb, offset, u16NameLength, pStationName);
offset += u16NameLength;
offset = dissect_pn_align4(tvb, offset, pinfo, ar_tree);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep, hf_pn_io_station_name_length, &u16NameLength);
if (u16NameLength != 0) {
pStationName = (char *)ep_alloc(u16NameLength+1);
tvb_memcpy(tvb, (guint8 *) pStationName, offset, u16NameLength);
pStationName[u16NameLength] = '\0';
proto_tree_add_string (ar_tree, hf_pn_io_parameter_server_station_name, tvb, offset, u16NameLength, pStationName);
offset += u16NameLength;
}
else
{
proto_tree_add_string (ar_tree, hf_pn_io_parameter_server_station_name, tvb, offset, u16NameLength, " <no ParameterServerStationName present>");
}
offset = dissect_pn_align4(tvb, offset, pinfo, ar_tree);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep, hf_pn_io_number_of_iocrs, &u16NumberOfIOCRs);
offset = dissect_pn_padding(tvb, offset, pinfo, ar_tree, 2);
while (u16NumberOfIOCRs--) {
iocr_item = proto_tree_add_item(ar_tree, hf_pn_io_iocr_tree, tvb, offset, 0, ENC_NA);
iocr_tree = proto_item_add_subtree(iocr_item, ett_pn_io_iocr);
u32IOCRStart = offset;
offset = dissect_IOCRProperties(tvb, offset, pinfo, iocr_tree, drep);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, iocr_tree, drep, hf_pn_io_iocr_type, &u16IOCRType);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, iocr_tree, drep, hf_pn_io_frame_id, &u16FrameID);
proto_item_append_text(iocr_item, ": FrameID:0x%x", u16FrameID);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, iocr_tree, drep,
hf_pn_io_cycle_counter, &u16CycleCounter);
u8DataStatus = tvb_get_guint8(tvb, offset);
u8TransferStatus = tvb_get_guint8(tvb, offset+1);
ds_item = proto_tree_add_uint_format(iocr_tree, hf_pn_io_data_status,
tvb, offset, 1, u8DataStatus,
"DataStatus: 0x%02x (Frame: %s and %s, Provider: %s and %s)",
u8DataStatus,
(u8DataStatus & 0x04) ? "Valid" : "Invalid",
(u8DataStatus & 0x01) ? "Primary" : "Backup",
(u8DataStatus & 0x20) ? "Ok" : "Problem",
(u8DataStatus & 0x10) ? "Run" : "Stop");
ds_tree = proto_item_add_subtree(ds_item, ett_pn_io_data_status);
proto_tree_add_uint(ds_tree, hf_pn_io_data_status_res67, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(ds_tree, hf_pn_io_data_status_ok, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(ds_tree, hf_pn_io_data_status_operate, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(ds_tree, hf_pn_io_data_status_res3, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(ds_tree, hf_pn_io_data_status_valid, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(ds_tree, hf_pn_io_data_status_res1, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(ds_tree, hf_pn_io_data_status_primary, tvb, offset, 1, u8DataStatus);
offset++;
if (u8TransferStatus) {
proto_tree_add_uint_format(iocr_tree, hf_pn_io_transfer_status, tvb,
offset, 1, u8TransferStatus,
"TransferStatus: 0x%02x (ignore this frame)", u8TransferStatus);
} else {
proto_tree_add_uint_format(iocr_tree, hf_pn_io_transfer_status, tvb,
offset, 1, u8TransferStatus,
"TransferStatus: 0x%02x (OK)", u8TransferStatus);
}
offset++;
proto_item_set_len(iocr_item, offset - u32IOCRStart);
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep, hf_pn_io_number_of_apis, &u16NumberOfAPIs);
offset = dissect_pn_padding(tvb, offset, pinfo, ar_tree, 2);
if (u16NumberOfAPIs > 0) {
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, ar_tree, drep, hf_pn_io_api, &u32Api);
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, ar_tree, drep, hf_pn_io_number_of_ARDATAInfo, &u16NumberofEntries);
offset = dissect_pn_padding(tvb, offset, pinfo, ar_tree, 2);
while ((offset < i32EndOffset) && (u16NumberofEntries > 0)) {
offset = dissect_a_block(tvb, offset, pinfo, ar_tree, drep);
u16NumberofEntries--;
}
proto_item_set_len(ar_item, offset - u32ARDataStart);
}
}
return offset;
}
static int
dissect_APIData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint8 *drep _U_, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16NumberOfAPIs;
guint32 u32Api;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_number_of_apis, &u16NumberOfAPIs);
while (u16NumberOfAPIs--) {
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_api, &u32Api);
}
return offset;
}
static int
dissect_SRLData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint8 *drep _U_, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 RedundancyInfo;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep, hf_pn_RedundancyInfo, &RedundancyInfo);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep, hf_pn_RedundancyInfo_reserved, &RedundancyInfo);
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 2);
return offset;
}
static int
dissect_LogData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint64 u64ActualLocaltimeStamp;
guint16 u16NumberOfLogEntries;
guint64 u64LocaltimeStamp;
e_uuid_t aruuid;
guint32 u32EntryDetail;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint64(tvb, offset, pinfo, tree, drep,
hf_pn_io_actual_local_time_stamp, &u64ActualLocaltimeStamp);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_number_of_log_entries, &u16NumberOfLogEntries);
while (u16NumberOfLogEntries--) {
offset = dissect_dcerpc_uint64(tvb, offset, pinfo, tree, drep,
hf_pn_io_local_time_stamp, &u64LocaltimeStamp);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_ar_uuid, &aruuid);
offset = dissect_PNIO_status(tvb, offset, pinfo, tree, drep);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_entry_detail, &u32EntryDetail);
}
return offset;
}
static int
dissect_FSHello_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint32 u32FSHelloMode;
guint32 u32FSHelloInterval;
guint32 u32FSHelloRetry;
guint32 u32FSHelloDelay;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_fs_hello_mode, &u32FSHelloMode);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_fs_hello_interval, &u32FSHelloInterval);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_fs_hello_retry, &u32FSHelloRetry);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_fs_hello_delay, &u32FSHelloDelay);
proto_item_append_text(item, ": Mode:%s, Interval:%ums, Retry:%u, Delay:%ums",
val_to_str(u32FSHelloMode, pn_io_fs_hello_mode_vals, "0x%x"),
u32FSHelloInterval, u32FSHelloRetry, u32FSHelloDelay);
return offset;
}
static int
dissect_FSParameter_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint32 u32FSParameterMode;
e_uuid_t FSParameterUUID;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_fs_parameter_mode, &u32FSParameterMode);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_fs_parameter_uuid, &FSParameterUUID);
proto_item_append_text(item, ": Mode:%s",
val_to_str(u32FSParameterMode, pn_io_fs_parameter_mode_vals, "0x%x"));
return offset;
}
static int
dissect_PDInterfaceFSUDataAdjust_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 u16BodyLength)
{
tvbuff_t *new_tvb;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 2);
u16BodyLength -= 2;
new_tvb = tvb_new_subset(tvb, offset, u16BodyLength, u16BodyLength);
dissect_blocks(new_tvb, 0, pinfo, tree, drep);
offset += u16BodyLength;
return offset;
}
static int
dissect_ARFSUDataAdjust_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 u16BodyLength)
{
tvbuff_t *new_tvb;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 2);
u16BodyLength -= 2;
new_tvb = tvb_new_subset(tvb, offset, u16BodyLength, u16BodyLength);
dissect_blocks(new_tvb, 0, pinfo, tree, drep);
offset += u16BodyLength;
return offset;
}
static const char* decode_ARType_spezial(guint16 ARType, guint16 ARAccess)
{
if (ARType == 0x0001)
return ("IO Controller AR");
else if (ARType == 0x0003)
return("IO Controller AR");
else if (ARType == 0x0010)
return("IO Controller AR (RT_CLASS_3)");
else if (ARType == 0x0020)
return("IO Controller AR (sysred/CiR)");
else if (ARType == 0x0006)
{
if (ARAccess)
return("DeviceAccess AR");
else
return("IO Supervisor AR");
}
else
return("reserved");
}
static int
dissect_ARBlockReq_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
pnio_ar_t ** ar)
{
guint16 u16ARType;
guint32 u32ARProperties;
e_uuid_t aruuid;
e_uuid_t uuid;
guint16 u16SessionKey;
guint8 mac[6];
guint16 u16TimeoutFactor;
guint16 u16UDPRTPort;
guint16 u16NameLength;
char *pStationName;
pnio_ar_t *par;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
u32ARProperties = ((drep[0] & DREP_LITTLE_ENDIAN)
? tvb_get_letohl (tvb, offset + 2 + 16 +2 + 6 +12)
: tvb_get_ntohl (tvb, offset + 2 + 16 +2 + 6 +12));
u16ARType = ((drep[0] & DREP_LITTLE_ENDIAN)
? tvb_get_letohs (tvb, offset)
: tvb_get_ntohs (tvb, offset));
if (tree) {
proto_tree_add_string_format(tree, hf_pn_io_artype_req, tvb, offset, 2,
"ARType", "ARType: (0x%04x) %s ",
u16ARType, decode_ARType_spezial(u16ARType, u32ARProperties));
}
offset = offset + 2;
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_ar_uuid, &aruuid);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_sessionkey, &u16SessionKey);
offset = dissect_pn_mac(tvb, offset, pinfo, tree,
hf_pn_io_cminitiator_macadd, mac);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_cminitiator_objectuuid, &uuid);
offset = dissect_ARProperties(tvb, offset, pinfo, tree, item, drep);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_cminitiator_activitytimeoutfactor, &u16TimeoutFactor);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_cminitiator_udprtport, &u16UDPRTPort);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_station_name_length, &u16NameLength);
pStationName = (char *)ep_alloc(u16NameLength+1);
tvb_memcpy(tvb, (guint8 *) pStationName, offset, u16NameLength);
pStationName[u16NameLength] = '\0';
proto_tree_add_string (tree, hf_pn_io_cminitiator_station_name, tvb, offset, u16NameLength, pStationName);
offset += u16NameLength;
proto_item_append_text(item, ": %s, Session:%u, MAC:%02x:%02x:%02x:%02x:%02x:%02x, Port:0x%x, Station:%s",
decode_ARType_spezial(u16ARType, u32ARProperties),
u16SessionKey,
mac[0], mac[1], mac[2], mac[3], mac[4], mac[5],
u16UDPRTPort,
pStationName);
par = pnio_ar_find_by_aruuid(pinfo, &aruuid);
if (par == NULL) {
par = pnio_ar_new(&aruuid);
memcpy( (void *) (&par->controllermac), mac, sizeof(par->controllermac));
par->arType = u16ARType;
} else {
}
*ar = par;
return offset;
}
static int
dissect_ARBlockRes_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
pnio_ar_t **ar)
{
guint16 u16ARType;
e_uuid_t uuid;
guint16 u16SessionKey;
guint8 mac[6];
guint16 u16UDPRTPort;
pnio_ar_t *par;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_ar_type, &u16ARType);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_ar_uuid, &uuid);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_sessionkey, &u16SessionKey);
offset = dissect_pn_mac(tvb, offset, pinfo, tree,
hf_pn_io_cmresponder_macadd, mac);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_cmresponder_udprtport, &u16UDPRTPort);
proto_item_append_text(item, ": %s, Session:%u, MAC:%02x:%02x:%02x:%02x:%02x:%02x, Port:0x%x",
val_to_str(u16ARType, pn_io_ar_type, "0x%x"),
u16SessionKey,
mac[0], mac[1], mac[2], mac[3], mac[4], mac[5],
u16UDPRTPort);
par = pnio_ar_find_by_aruuid(pinfo, &uuid);
if (par == NULL) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_NOTE, "ARBlockRes: AR information not found!");
} else {
memcpy( (void *) (&par->devicemac), mac, sizeof(par->controllermac));
}
*ar = par;
return offset;
}
static int
dissect_IOCRBlockReq_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
pnio_ar_t *ar)
{
guint16 u16IOCRType;
guint16 u16IOCRReference;
guint16 u16LT;
guint16 u16DataLength;
guint16 u16FrameID;
guint16 u16SendClockFactor;
guint16 u16ReductionRatio;
guint16 u16Phase;
guint16 u16Sequence;
guint32 u32FrameSendOffset;
guint16 u16WatchdogFactor;
guint16 u16DataHoldFactor;
guint16 u16IOCRTagHeader;
guint8 mac[6];
guint16 u16NumberOfAPIs;
guint32 u32Api;
guint16 u16NumberOfIODataObjects;
guint16 u16SlotNr;
guint16 u16SubslotNr;
guint16 u16IODataObjectFrameOffset;
guint16 u16NumberOfIOCS;
guint16 u16IOCSFrameOffset;
proto_item *api_item;
proto_tree *api_tree;
guint32 u32ApiStart;
guint16 u16Tmp;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32SubStart;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_iocr_type, &u16IOCRType);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_iocr_reference, &u16IOCRReference);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_lt, &u16LT);
offset = dissect_IOCRProperties(tvb, offset, pinfo, tree, drep);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_data_length, &u16DataLength);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_frame_id, &u16FrameID);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_send_clock_factor, &u16SendClockFactor);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_reduction_ratio, &u16ReductionRatio);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_phase, &u16Phase);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_sequence, &u16Sequence);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_frame_send_offset, &u32FrameSendOffset);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_watchdog_factor, &u16WatchdogFactor);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_data_hold_factor, &u16DataHoldFactor);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_iocr_tag_header, &u16IOCRTagHeader);
offset = dissect_pn_mac(tvb, offset, pinfo, tree,
hf_pn_io_iocr_multicast_mac_add, mac);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_number_of_apis, &u16NumberOfAPIs);
proto_item_append_text(item, ": %s, Ref:0x%x, Len:%u, FrameID:0x%x, Clock:%u, Ratio:%u, Phase:%u APIs:%u",
val_to_str(u16IOCRType, pn_io_iocr_type, "0x%x"),
u16IOCRReference, u16DataLength, u16FrameID,
u16SendClockFactor, u16ReductionRatio, u16Phase, u16NumberOfAPIs);
while (u16NumberOfAPIs--) {
api_item = proto_tree_add_item(tree, hf_pn_io_api_tree, tvb, offset, 0, ENC_NA);
api_tree = proto_item_add_subtree(api_item, ett_pn_io_api);
u32ApiStart = offset;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, api_tree, drep,
hf_pn_io_api, &u32Api);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, api_tree, drep,
hf_pn_io_number_of_io_data_objects, &u16NumberOfIODataObjects);
u16Tmp = u16NumberOfIODataObjects;
while (u16Tmp--) {
sub_item = proto_tree_add_item(api_tree, hf_pn_io_io_data_object, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_io_data_object);
u32SubStart = offset;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_io_data_object_frame_offset, &u16IODataObjectFrameOffset);
proto_item_append_text(sub_item, ": Slot: 0x%x, Subslot: 0x%x FrameOffset: %u",
u16SlotNr, u16SubslotNr, u16IODataObjectFrameOffset);
proto_item_set_len(sub_item, offset - u32SubStart);
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, api_tree, drep,
hf_pn_io_number_of_iocs, &u16NumberOfIOCS);
u16Tmp = u16NumberOfIOCS;
while (u16Tmp--) {
sub_item = proto_tree_add_item(api_tree, hf_pn_io_io_cs, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_io_cs);
u32SubStart = offset;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_iocs_frame_offset, &u16IOCSFrameOffset);
proto_item_append_text(sub_item, ": Slot: 0x%x, Subslot: 0x%x FrameOffset: %u",
u16SlotNr, u16SubslotNr, u16IOCSFrameOffset);
proto_item_set_len(sub_item, offset - u32SubStart);
}
proto_item_append_text(api_item, ": 0x%x, NumberOfIODataObjects: %u NumberOfIOCS: %u",
u32Api, u16NumberOfIODataObjects, u16NumberOfIOCS);
proto_item_set_len(api_item, offset - u32ApiStart);
}
if (ar != NULL) {
switch (u16IOCRType) {
case(1):
if (ar->inputframeid != 0 && ar->inputframeid != u16FrameID) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN, "IOCRBlockReq: input frameID changed from %u to %u!",
ar->inputframeid, u16FrameID);
}
ar->inputframeid = u16FrameID;
break;
case(2):
#if 0
if (ar->outputframeid != 0 && ar->outputframeid != u16FrameID) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN, "IOCRBlockReq: output frameID changed from %u to %u!",
ar->outputframeid, u16FrameID);
}
ar->outputframeid = u16FrameID;
#endif
break;
default:
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN, "IOCRBlockReq: IOCRType %u undecoded!", u16IOCRType);
}
} else {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN, "IOCRBlockReq: no corresponding AR found!");
}
return offset;
}
static int
dissect_AlarmCRBlockReq_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
pnio_ar_t *ar)
{
guint16 u16AlarmCRType;
guint16 u16LT;
guint32 u32AlarmCRProperties;
guint16 u16RTATimeoutFactor;
guint16 u16RTARetries;
guint16 u16LocalAlarmReference;
guint16 u16MaxAlarmDataLength;
guint16 u16AlarmCRTagHeaderHigh;
guint16 u16AlarmCRTagHeaderLow;
proto_item *sub_item;
proto_tree *sub_tree;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_alarmcr_type, &u16AlarmCRType);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_lt, &u16LT);
sub_item = proto_tree_add_item(tree, hf_pn_io_alarmcr_properties, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_alarmcr_properties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_alarmcr_properties_reserved, &u32AlarmCRProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_alarmcr_properties_transport, &u32AlarmCRProperties);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_alarmcr_properties_priority, &u32AlarmCRProperties);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_rta_timeoutfactor, &u16RTATimeoutFactor);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_rta_retries, &u16RTARetries);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_localalarmref, &u16LocalAlarmReference);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_maxalarmdatalength, &u16MaxAlarmDataLength);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_alarmcr_tagheaderhigh, &u16AlarmCRTagHeaderHigh);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_alarmcr_tagheaderlow, &u16AlarmCRTagHeaderLow);
proto_item_append_text(item, ": %s, LT:0x%x, TFactor:%u, Retries:%u, Ref:0x%x, Len:%u Tag:0x%x/0x%x",
val_to_str(u16AlarmCRType, pn_io_alarmcr_type, "0x%x"),
u16LT, u16RTATimeoutFactor, u16RTARetries, u16LocalAlarmReference, u16MaxAlarmDataLength,
u16AlarmCRTagHeaderHigh, u16AlarmCRTagHeaderLow);
if (ar != NULL) {
if (ar->controlleralarmref != 0xffff && ar->controlleralarmref != u16LocalAlarmReference) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN, "AlarmCRBlockReq: local alarm ref changed from %u to %u!",
ar->controlleralarmref, u16LocalAlarmReference);
}
ar->controlleralarmref = u16LocalAlarmReference;
} else {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN, "AlarmCRBlockReq: no corresponding AR found!");
}
return offset;
}
static int
dissect_AlarmCRBlockRes_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
pnio_ar_t *ar)
{
guint16 u16AlarmCRType;
guint16 u16LocalAlarmReference;
guint16 u16MaxAlarmDataLength;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_alarmcr_type, &u16AlarmCRType);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_localalarmref, &u16LocalAlarmReference);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_maxalarmdatalength, &u16MaxAlarmDataLength);
proto_item_append_text(item, ": %s, Ref:0x%04x, MaxDataLen:%u",
val_to_str(u16AlarmCRType, pn_io_alarmcr_type, "0x%x"),
u16LocalAlarmReference, u16MaxAlarmDataLength);
if (ar != NULL) {
if (ar->devicealarmref != 0xffff && ar->devicealarmref != u16LocalAlarmReference) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN, "AlarmCRBlockRes: local alarm ref changed from %u to %u!",
ar->devicealarmref, u16LocalAlarmReference);
}
ar->devicealarmref = u16LocalAlarmReference;
} else {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN, "AlarmCRBlockRes: no corresponding AR found!");
}
return offset;
}
static int
dissect_ARServerBlock(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
char *pStationName;
guint16 u16NameLength, u16padding;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_station_name_length, &u16NameLength);
pStationName = (char *)ep_alloc(u16NameLength+1);
tvb_memcpy(tvb, (guint8 *) pStationName, offset, u16NameLength);
pStationName[u16NameLength] = '\0';
proto_tree_add_string (tree, hf_pn_io_cminitiator_station_name, tvb, offset, u16NameLength, pStationName);
offset += u16NameLength;
u16padding = (u16NameLength-2) & 0x3;
if (u16padding >0)
offset = dissect_pn_padding(tvb, offset, pinfo, tree, u16padding);
return offset;
}
static int
dissect_IOCRBlockRes_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
pnio_ar_t *ar)
{
guint16 u16IOCRType;
guint16 u16IOCRReference;
guint16 u16FrameID;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_iocr_type, &u16IOCRType);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_iocr_reference, &u16IOCRReference);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_frame_id, &u16FrameID);
proto_item_append_text(item, ": %s, Ref:0x%04x, FrameID:0x%04x",
val_to_str(u16IOCRType, pn_io_iocr_type, "0x%x"),
u16IOCRReference, u16FrameID);
if (ar != NULL) {
switch (u16IOCRType) {
case(1):
if (ar->inputframeid != 0 && ar->inputframeid != u16FrameID) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN, "IOCRBlockRes: input frameID changed from %u to %u!",
ar->inputframeid, u16FrameID);
}
ar->inputframeid = u16FrameID;
break;
case(2):
if (ar->outputframeid != 0 && ar->outputframeid != u16FrameID) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN, "IOCRBlockRes: output frameID changed from %u to %u!",
ar->outputframeid, u16FrameID);
}
ar->outputframeid = u16FrameID;
break;
default:
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN, "IOCRBlockRes: IOCRType %u undecoded!", u16IOCRType);
}
} else {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN, "IOCRBlockRes: no corresponding AR found!");
}
return offset;
}
static int
dissect_MCRBlockReq_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16IOCRReference;
guint32 u32AddressResolutionProperties;
guint16 u16MCITimeoutFactor;
guint16 u16NameLength;
char *pStationName;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_iocr_reference, &u16IOCRReference);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_address_resolution_properties, &u32AddressResolutionProperties);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_mci_timeout_factor, &u16MCITimeoutFactor);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_station_name_length, &u16NameLength);
pStationName = (char *)ep_alloc(u16NameLength+1);
tvb_memcpy(tvb, (guint8 *) pStationName, offset, u16NameLength);
pStationName[u16NameLength] = '\0';
proto_tree_add_string (tree, hf_pn_io_provider_station_name, tvb, offset, u16NameLength, pStationName);
offset += u16NameLength;
proto_item_append_text(item, ", CRRef:%u, Properties:0x%x, TFactor:%u, Station:%s",
u16IOCRReference, u32AddressResolutionProperties, u16MCITimeoutFactor, pStationName);
return offset;
}
static int
dissect_SubFrameBlock_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 u16BodyLength)
{
guint16 u16IOCRReference;
guint8 mac[6];
guint32 u32SubFrameData;
guint16 u16Tmp;
proto_item *sub_item;
proto_tree *sub_tree;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 2);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_iocr_reference, &u16IOCRReference);
offset = dissect_pn_mac(tvb, offset, pinfo, tree,
hf_pn_io_cminitiator_macadd, mac);
u16BodyLength -= 10;
u16Tmp = u16BodyLength;
do {
sub_item = proto_tree_add_item(tree, hf_pn_io_subframe_data, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_subframe_data);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_subframe_data_reserved2, &u32SubFrameData);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_subframe_data_length, &u32SubFrameData);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_subframe_data_reserved1, &u32SubFrameData);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_subframe_data_position, &u32SubFrameData);
proto_item_append_text(sub_item, ", Length:%u, Pos:%u",
(u32SubFrameData & 0x0000FF00) >> 8, u32SubFrameData & 0x0000007F);
} while (u16Tmp -= 4);
proto_item_append_text(item, ", CRRef:%u, %u*Data",
u16IOCRReference, u16BodyLength/4);
return offset;
}
static int
dissect_PDSubFrameBlock_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint32 u32SFIOCRProperties;
guint32 u32SubFrameData;
guint16 u16FrameID;
proto_item *sub_item;
proto_tree *sub_tree;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep, hf_pn_io_frame_id, &u16FrameID);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_SFIOCRProperties, &u32SFIOCRProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_DistributedWatchDogFactor, &u32SFIOCRProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_RestartFactorForDistributedWD, &u32SFIOCRProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_SFIOCRProperties_DFPmode, &u32SFIOCRProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_SFIOCRProperties_reserved_1, &u32SFIOCRProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_SFIOCRProperties_reserved_2, &u32SFIOCRProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_SFIOCRProperties_DFPType, &u32SFIOCRProperties);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_SFIOCRProperties_DFPRedundantPathLayout, &u32SFIOCRProperties);
offset =
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_SFIOCRProperties_SFCRC16, &u32SFIOCRProperties);
while (tvb_bytes_exist(tvb, offset, 4))
{
sub_item = proto_tree_add_item(tree, hf_pn_io_subframe_data, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_subframe_data);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep, hf_pn_io_subframe_data_position, &u32SubFrameData);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep, hf_pn_io_subframe_reserved1, &u32SubFrameData);
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep, hf_pn_io_subframe_data_length, &u32SubFrameData);
offset =
dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep, hf_pn_io_subframe_reserved2, &u32SubFrameData);
}
return offset;
}
static int
dissect_IRInfoBlock_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 u16BodyLength _U_)
{
guint16 u16NumberOfIOCR;
guint16 u16SubframeOffset;
guint32 u32SubframeData;
guint16 u16IOCRReference;
e_uuid_t IRDataUUID;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 2);
offset = dissect_dcerpc_uuid_t(tvb, offset, pinfo, tree, drep,
hf_pn_io_IRData_uuid, &IRDataUUID);
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 2);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_number_of_iocrs, &u16NumberOfIOCR);
while (u16NumberOfIOCR--)
{
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep, hf_pn_io_iocr_reference, &u16IOCRReference);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep, hf_pn_io_iocr_SubframeOffset, &u16SubframeOffset);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_iocr_SubframeData, &u32SubframeData);
}
return offset;
}
static int
dissect_SRInfoBlock_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 u16BodyLength _U_)
{
guint16 u16RedundancyDataHoldFactor;
guint32 u32sr_properties;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep, hf_pn_io_RedundancyDataHoldFactor, &u16RedundancyDataHoldFactor);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_sr_properties, &u32sr_properties);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_sr_properties_InputValidOnBackupAR, &u32sr_properties);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_sr_properties_ActivateRedundancyAlarm, &u32sr_properties);
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_sr_properties_Reserved_1, &u32sr_properties);
offset =
dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep, hf_pn_io_sr_properties_Reserved_2, &u32sr_properties);
return offset;
}
static int
dissect_PDIRSubframeData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16NumberOfSubframeBlocks;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep, hf_pn_io_NumberOfSubframeBlocks, &u16NumberOfSubframeBlocks);
while (u16NumberOfSubframeBlocks --)
{
offset = dissect_a_block(tvb, offset, pinfo, tree, drep);
}
return offset;
}
static int
dissect_ARVendorBlockReq_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 u16BodyLength _U_)
{
guint16 APStructureIdentifier;
guint32 gu32API;
guint32 guDataBytes;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
APStructureIdentifier = ((drep[0] & DREP_LITTLE_ENDIAN)
? tvb_get_letohs(tvb, offset)
: tvb_get_ntohs(tvb, offset));
gu32API = ((drep[0] & DREP_LITTLE_ENDIAN)
? tvb_get_letohl(tvb, offset + 2)
: tvb_get_ntohl (tvb, offset + 2));
if (tree)
{
if (gu32API == 0)
{
if (APStructureIdentifier <0x8000)
{
proto_tree_add_item(tree, hf_pn_io_arvendor_strucidentifier_if0_low, tvb, offset, 2, DREP_ENC_INTEGER(drep));
}
else
{
if (APStructureIdentifier > 0x8000)
{
proto_tree_add_item(tree, hf_pn_io_arvendor_strucidentifier_if0_high, tvb, offset, 2, DREP_ENC_INTEGER(drep));
}
else
{
proto_tree_add_item(tree, hf_pn_io_arvendor_strucidentifier_if0_is8000, tvb, offset, 2, DREP_ENC_INTEGER(drep));
}
}
}
else
{
proto_tree_add_item(tree, hf_pn_io_arvendor_strucidentifier_not0, tvb, offset, 2, DREP_ENC_INTEGER(drep));
}
proto_tree_add_item(tree, hf_pn_io_api, tvb, offset + 2, 4, DREP_ENC_INTEGER(drep));
}
offset += 6;
if (u16BodyLength < 6 )
return offset;
guDataBytes = u16BodyLength - 6;
dissect_pn_user_data(tvb, offset, pinfo, tree, guDataBytes, "Data ");
return offset;
}
static int
dissect_DataDescription(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint16 u16DataDescription;
guint16 u16SubmoduleDataLength;
guint8 u8LengthIOCS;
guint8 u8LengthIOPS;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32SubStart;
sub_item = proto_tree_add_item(tree, hf_pn_io_data_description_tree, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_data_description);
u32SubStart = offset;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_data_description, &u16DataDescription);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_submodule_data_length, &u16SubmoduleDataLength);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_length_iocs, &u8LengthIOCS);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_length_iops, &u8LengthIOPS);
proto_item_append_text(sub_item, ": %s, SubmoduleDataLength: %u, LengthIOCS: %u, u8LengthIOPS: %u",
val_to_str(u16DataDescription, pn_io_data_description, "(0x%x)"),
u16SubmoduleDataLength, u8LengthIOCS, u8LengthIOPS);
proto_item_set_len(sub_item, offset - u32SubStart);
return offset;
}
static int
dissect_ExpectedSubmoduleBlockReq_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16NumberOfAPIs;
guint32 u32Api;
guint16 u16SlotNr;
guint32 u32ModuleIdentNumber;
guint16 u16ModuleProperties;
guint16 u16NumberOfSubmodules;
guint16 u16SubslotNr;
guint32 u32SubmoduleIdentNumber;
guint16 u16SubmoduleProperties;
proto_item *api_item;
proto_tree *api_tree;
guint32 u32ApiStart;
proto_item *sub_item;
proto_tree *sub_tree;
proto_item *submodule_item;
proto_tree *submodule_tree;
guint32 u32SubStart;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_number_of_apis, &u16NumberOfAPIs);
proto_item_append_text(item, ": APIs:%u", u16NumberOfAPIs);
while (u16NumberOfAPIs--) {
api_item = proto_tree_add_item(tree, hf_pn_io_api_tree, tvb, offset, 0, ENC_NA);
api_tree = proto_item_add_subtree(api_item, ett_pn_io_api);
u32ApiStart = offset;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, api_tree, drep,
hf_pn_io_api, &u32Api);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, api_tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, api_tree, drep,
hf_pn_io_module_ident_number, &u32ModuleIdentNumber);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, api_tree, drep,
hf_pn_io_module_properties, &u16ModuleProperties);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, api_tree, drep,
hf_pn_io_number_of_submodules, &u16NumberOfSubmodules);
proto_item_append_text(api_item, ": %u, Slot:0x%x, IdentNumber:0x%x Properties:0x%x Submodules:%u",
u32Api, u16SlotNr, u32ModuleIdentNumber, u16ModuleProperties, u16NumberOfSubmodules);
proto_item_append_text(item, ", Submodules:%u", u16NumberOfSubmodules);
while (u16NumberOfSubmodules--) {
sub_item = proto_tree_add_item(api_tree, hf_pn_io_submodule_tree, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_submodule);
u32SubStart = offset;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_submodule_ident_number, &u32SubmoduleIdentNumber);
submodule_item = proto_tree_add_item(sub_tree, hf_pn_io_submodule_properties, tvb, offset, 2, ENC_BIG_ENDIAN);
submodule_tree = proto_item_add_subtree(submodule_item, ett_pn_io_submodule_properties);
dissect_dcerpc_uint16(tvb, offset, pinfo, submodule_tree, drep,
hf_pn_io_submodule_properties_reserved, &u16SubmoduleProperties);
dissect_dcerpc_uint16(tvb, offset, pinfo, submodule_tree, drep,
hf_pn_io_submodule_properties_discard_ioxs, &u16SubmoduleProperties);
dissect_dcerpc_uint16(tvb, offset, pinfo, submodule_tree, drep,
hf_pn_io_submodule_properties_reduce_output_submodule_data_length, &u16SubmoduleProperties);
dissect_dcerpc_uint16(tvb, offset, pinfo, submodule_tree, drep,
hf_pn_io_submodule_properties_reduce_input_submodule_data_length, &u16SubmoduleProperties);
dissect_dcerpc_uint16(tvb, offset, pinfo, submodule_tree, drep,
hf_pn_io_submodule_properties_shared_input, &u16SubmoduleProperties);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, submodule_tree, drep,
hf_pn_io_submodule_properties_type, &u16SubmoduleProperties);
switch (u16SubmoduleProperties & 0x03) {
case(0x00):
offset = dissect_DataDescription(tvb, offset, pinfo, sub_tree, drep);
break;
case(0x01):
offset = dissect_DataDescription(tvb, offset, pinfo, sub_tree, drep);
break;
case(0x02):
offset = dissect_DataDescription(tvb, offset, pinfo, sub_tree, drep);
break;
case(0x03):
offset = dissect_DataDescription(tvb, offset, pinfo, sub_tree, drep);
offset = dissect_DataDescription(tvb, offset, pinfo, sub_tree, drep);
break;
}
proto_item_append_text(sub_item, ": Subslot:0x%x, Ident:0x%x Properties:0x%x",
u16SubslotNr, u32SubmoduleIdentNumber, u16SubmoduleProperties);
proto_item_set_len(sub_item, offset - u32SubStart);
}
proto_item_set_len(api_item, offset - u32ApiStart);
}
return offset;
}
static int
dissect_ModuleDiffBlock_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16NumberOfAPIs;
guint32 u32Api;
guint16 u16NumberOfModules;
guint16 u16SlotNr;
guint32 u32ModuleIdentNumber;
guint16 u16ModuleState;
guint16 u16NumberOfSubmodules;
guint16 u16SubslotNr;
guint32 u32SubmoduleIdentNumber;
guint16 u16SubmoduleState;
proto_item *api_item;
proto_tree *api_tree;
guint32 u32ApiStart;
proto_item *module_item;
proto_tree *module_tree;
guint32 u32ModuleStart;
proto_item *sub_item;
proto_tree *sub_tree;
proto_item *submodule_item;
proto_tree *submodule_tree;
guint32 u32SubStart;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_number_of_apis, &u16NumberOfAPIs);
proto_item_append_text(item, ": APIs:%u", u16NumberOfAPIs);
while (u16NumberOfAPIs--) {
api_item = proto_tree_add_item(tree, hf_pn_io_api_tree, tvb, offset, 0, ENC_NA);
api_tree = proto_item_add_subtree(api_item, ett_pn_io_api);
u32ApiStart = offset;
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, api_tree, drep,
hf_pn_io_api, &u32Api);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, api_tree, drep,
hf_pn_io_number_of_modules, &u16NumberOfModules);
proto_item_append_text(api_item, ": %u, Modules: %u",
u32Api, u16NumberOfModules);
proto_item_append_text(item, ", Modules:%u", u16NumberOfModules);
while (u16NumberOfModules--) {
module_item = proto_tree_add_item(api_tree, hf_pn_io_module_tree, tvb, offset, 0, ENC_NA);
module_tree = proto_item_add_subtree(module_item, ett_pn_io_module);
u32ModuleStart = offset;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, module_tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, module_tree, drep,
hf_pn_io_module_ident_number, &u32ModuleIdentNumber);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, module_tree, drep,
hf_pn_io_module_state, &u16ModuleState);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, module_tree, drep,
hf_pn_io_number_of_submodules, &u16NumberOfSubmodules);
proto_item_append_text(module_item, ": Slot 0x%x, Ident: 0x%x State: %s Submodules: %u",
u16SlotNr, u32ModuleIdentNumber,
val_to_str(u16ModuleState, pn_io_module_state, "(0x%x)"),
u16NumberOfSubmodules);
proto_item_append_text(item, ", Submodules:%u", u16NumberOfSubmodules);
while (u16NumberOfSubmodules--) {
sub_item = proto_tree_add_item(module_tree, hf_pn_io_submodule_tree, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_submodule);
u32SubStart = offset;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_submodule_ident_number, &u32SubmoduleIdentNumber);
submodule_item = proto_tree_add_item(sub_tree, hf_pn_io_submodule_state, tvb, offset, 2, ENC_BIG_ENDIAN);
submodule_tree = proto_item_add_subtree(submodule_item, ett_pn_io_submodule_state);
dissect_dcerpc_uint16(tvb, offset, pinfo, submodule_tree, drep,
hf_pn_io_submodule_state_format_indicator, &u16SubmoduleState);
if (u16SubmoduleState & 0x8000) {
dissect_dcerpc_uint16(tvb, offset, pinfo, submodule_tree, drep,
hf_pn_io_submodule_state_ident_info, &u16SubmoduleState);
dissect_dcerpc_uint16(tvb, offset, pinfo, submodule_tree, drep,
hf_pn_io_submodule_state_ar_info, &u16SubmoduleState);
dissect_dcerpc_uint16(tvb, offset, pinfo, submodule_tree, drep,
hf_pn_io_submodule_state_diag_info, &u16SubmoduleState);
dissect_dcerpc_uint16(tvb, offset, pinfo, submodule_tree, drep,
hf_pn_io_submodule_state_maintenance_demanded, &u16SubmoduleState);
dissect_dcerpc_uint16(tvb, offset, pinfo, submodule_tree, drep,
hf_pn_io_submodule_state_maintenance_required, &u16SubmoduleState);
dissect_dcerpc_uint16(tvb, offset, pinfo, submodule_tree, drep,
hf_pn_io_submodule_state_qualified_info, &u16SubmoduleState);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, submodule_tree, drep,
hf_pn_io_submodule_state_add_info, &u16SubmoduleState);
} else {
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, submodule_tree, drep,
hf_pn_io_submodule_state_detail, &u16SubmoduleState);
}
proto_item_append_text(sub_item, ": Subslot 0x%x, IdentNumber: 0x%x, State: 0x%x",
u16SubslotNr, u32SubmoduleIdentNumber, u16SubmoduleState);
proto_item_set_len(sub_item, offset - u32SubStart);
}
proto_item_set_len(module_item, offset - u32ModuleStart);
}
proto_item_set_len(api_item, offset - u32ApiStart);
}
return offset;
}
static int
dissect_IsochronousModeData_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow)
{
guint16 u16SlotNr;
guint16 u16SubslotNr;
guint16 u16ControllerApplicationCycleFactor;
guint16 u16TimeDataCycle;
guint32 u32TimeIOInput;
guint32 u32TimeIOOutput;
guint32 u32TimeIOInputValid;
guint32 u32TimeIOOutputValid;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_controller_appl_cycle_factor, &u16ControllerApplicationCycleFactor);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_time_data_cycle, &u16TimeDataCycle);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_time_io_input, &u32TimeIOInput);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_time_io_output, &u32TimeIOOutput);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_time_io_input_valid, &u32TimeIOInputValid);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_time_io_output_valid, &u32TimeIOOutputValid);
return offset+1;
}
static int
dissect_MultipleBlockHeader_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 *drep, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 u16BodyLength)
{
guint32 u32Api;
guint16 u16SlotNr;
guint16 u16SubslotNr;
tvbuff_t *new_tvb;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_api, &u32Api);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_slot_nr, &u16SlotNr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, tree, drep,
hf_pn_io_subslot_nr, &u16SubslotNr);
proto_item_append_text(item, ": Api:0x%x Slot:%u Subslot:0x%x",
u32Api, u16SlotNr, u16SubslotNr);
new_tvb = tvb_new_subset(tvb, offset, u16BodyLength-10, u16BodyLength-10);
offset = dissect_blocks(new_tvb, 0, pinfo, tree, drep);
return offset;
}
static const gchar *
indexReservedForProfiles(guint16 u16Index)
{
if (u16Index >= 0xb000 && u16Index <= 0xbfff) {
return "Reserved for Profiles (subslot specific)";
}
if (u16Index >= 0xd000 && u16Index <= 0xdfff) {
return "Reserved for Profiles (slot specific)";
}
if (u16Index >= 0xec00 && u16Index <= 0xefff) {
return "Reserved for Profiles (AR specific)";
}
if (u16Index >= 0xf400 && u16Index <= 0xf7ff) {
return "Reserved for Profiles (API specific)";
}
if (u16Index >= 0xfc00 ) {
return "Reserved for Profiles (device specific)";
}
return NULL;
}
static int
dissect_RecordDataReadQuery_block(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint8 *drep _U_, guint8 u8BlockVersionHigh, guint8 u8BlockVersionLow,
guint16 u16Index, guint16 u16BodyLength)
{
const gchar *userProfile;
if (u8BlockVersionHigh != 1 || u8BlockVersionLow != 0) {
expert_add_info_format(pinfo, item, PI_UNDECODED, PI_WARN,
"Block version %u.%u not implemented yet!", u8BlockVersionHigh, u8BlockVersionLow);
return offset;
}
if (u16Index < 0x8000) {
offset = dissect_pn_user_data(tvb, offset, pinfo, tree, u16BodyLength, "User Specified Data");
return offset;
}
userProfile = indexReservedForProfiles(u16Index);
if (userProfile != NULL) {
offset = dissect_pn_user_data(tvb, offset, pinfo, tree, u16BodyLength, userProfile);
return offset;
}
return dissect_pn_undecoded(tvb, offset, pinfo, tree, u16BodyLength);
}
static int
dissect_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep, guint16 *u16Index, guint32 *u32RecDataLen, pnio_ar_t **ar)
{
guint16 u16BlockType;
guint16 u16BlockLength;
guint8 u8BlockVersionHigh;
guint8 u8BlockVersionLow;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32SubStart;
guint16 u16BodyLength;
proto_item *header_item;
proto_tree *header_tree;
gint remainingBytes;
drep[0] &= ~DREP_LITTLE_ENDIAN;
sub_item = proto_tree_add_item(tree, hf_pn_io_block, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_block);
u32SubStart = offset;
header_item = proto_tree_add_item(sub_tree, hf_pn_io_block_header, tvb, offset, 6, ENC_NA);
header_tree = proto_item_add_subtree(header_item, ett_pn_io_block_header);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, header_tree, drep,
hf_pn_io_block_type, &u16BlockType);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, header_tree, drep,
hf_pn_io_block_length, &u16BlockLength);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, header_tree, drep,
hf_pn_io_block_version_high, &u8BlockVersionHigh);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, header_tree, drep,
hf_pn_io_block_version_low, &u8BlockVersionLow);
proto_item_append_text(header_item, ": Type=%s, Length=%u(+4), Version=%u.%u",
val_to_str(u16BlockType, pn_io_block_type, "Unknown (0x%04x)"),
u16BlockLength, u8BlockVersionHigh, u8BlockVersionLow);
proto_item_set_text(sub_item, "%s",
val_to_str(u16BlockType, pn_io_block_type, "Unknown (0x%04x)"));
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str(u16BlockType, pn_io_block_type, "Unknown"));
u16BodyLength = u16BlockLength - 2;
remainingBytes = tvb_reported_length_remaining(tvb, offset);
if (remainingBytes +2 < u16BodyLength)
{
proto_item_append_text(sub_item, " Block_Length: %d greater than remaining Bytes, trying with Blocklen = remaining (%d)", u16BodyLength, remainingBytes);
u16BodyLength = remainingBytes;
}
switch (u16BlockType) {
case(0x0001):
case(0x0002):
dissect_AlarmNotification_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow,
u16BodyLength);
break;
case(0x0008):
dissect_IODWriteReqHeader_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow,
u16Index, u32RecDataLen, ar);
break;
case(0x0009):
dissect_IODReadReqHeader_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow,
u16Index, u32RecDataLen, ar);
break;
case(0x0010):
dissect_DiagnosisData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow,
u16BodyLength);
break;
case(0x0012):
case(0x0013):
dissect_IdentificationData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0014):
dissect_SubstituteValue_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow,
u16BodyLength);
break;
case(0x0015):
dissect_RecordInputDataObjectElement_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0016):
dissect_RecordOutputDataObjectElement_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0018):
dissect_ARData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength);
break;
case(0x0019):
dissect_LogData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x001A):
dissect_APIData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x001B):
dissect_SRLData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0020):
dissect_IandM0_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0021):
dissect_IandM1_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0022):
dissect_IandM2_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0023):
dissect_IandM3_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0024):
dissect_IandM4_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0030):
dissect_IandM0FilterData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0031):
dissect_IandM0FilterData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0032):
dissect_IandM0FilterData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0101):
dissect_ARBlockReq_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow,
ar);
break;
case(0x0102):
dissect_IOCRBlockReq_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow,
*ar);
break;
case(0x0103):
dissect_AlarmCRBlockReq_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow,
*ar);
break;
case(0x0104):
dissect_ExpectedSubmoduleBlockReq_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0106):
dissect_MCRBlockReq_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0107):
dissect_SubFrameBlock_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength);
break;
case(0x0108):
case(0x8108):
dissect_ARVendorBlockReq_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength);
break;
case(0x0109):
dissect_IRInfoBlock_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength);
break;
case(0x010A):
dissect_SRInfoBlock_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength);
break;
case(0x0110):
case(0x0111):
case(0x0112):
case(0x0113):
case(0x0114):
case(0x0116):
case(0x0117):
dissect_ControlConnect_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, ar);
break;
case(0x0118):
dissect_ControlBlockPrmBegin(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength, ar);
break;
case(0x0119):
dissect_SubmoduleListBlock(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength, ar);
break;
case(0x0200):
dissect_PDPortData_Check_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow,
u16BodyLength);
break;
case(0x0201):
dissect_PDevData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0202):
dissect_PDPortData_Adjust_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow,
u16BodyLength);
break;
case(0x0203):
dissect_PDSyncData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0204):
dissect_IsochronousModeData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0205):
dissect_PDIRData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0206):
dissect_PDIRGlobalData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0207):
dissect_PDIRFrameData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow,
u16BodyLength);
break;
case(0x0208):
dissect_PDIRBeginEndData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow,
u16BodyLength);
break;
case(0x0209):
dissect_AdjustDomainBoundary_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x020A):
dissect_CheckPeers_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x020B):
dissect_CheckLineDelay_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x020C):
dissect_CheckMAUType_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x020E):
dissect_AdjustMAUType_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x020F):
dissect_PDPortDataReal_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0210):
dissect_AdjustMulticastBoundary_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0211):
dissect_PDInterfaceMrpDataAdjust_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength);
break;
case(0x0212):
dissect_PDInterfaceMrpDataReal_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength);
break;
case(0x0213):
dissect_PDInterfaceMrpDataCheck_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0214):
case(0x0215):
dissect_PDPortMrpData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0216):
dissect_MrpManagerParams_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0217):
dissect_MrpClientParams_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0218):
dissect_MrpRTModeManagerData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0219):
dissect_MrpRingStateData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x021A):
dissect_MrpRTStateData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x021B):
dissect_AdjustPortState_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x021C):
dissect_CheckPortState_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x021D):
dissect_MrpRTModeClientData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x021E):
dissect_CheckSyncDifference_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x021F):
dissect_CheckMAUTypeDifference_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0220):
dissect_PDPortFODataReal_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength);
break;
case(0x0221):
dissect_FiberOpticManufacturerSpecific_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength);
break;
case(0x0222):
dissect_PDPortFODataAdjust_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0223):
dissect_PDPortFODataCheck_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0226):
dissect_AdjustPreambleLength_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x022A):
dissect_PDIRSubframeData_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x022B):
dissect_PDSubFrameBlock_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0230):
dissect_PDPortFODataCheck_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0231):
dissect_MrpInstanceDataAdjust_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength);
break;
case(0x0232):
dissect_MrpInstanceDataReal_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength);
break;
case(0x0233):
dissect_MrpInstanceDataCheck_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength);
break;
case(0x0240):
dissect_PDInterfaceDataReal_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0250):
dissect_PDInterfaceAdjust_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0251):
dissect_PDPortStatistic_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0400):
dissect_MultipleBlockHeader_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength);
break;
case(0x0500):
dissect_RecordDataReadQuery_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, *u16Index, u16BodyLength);
break;
case(0x0600):
dissect_FSHello_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0601):
dissect_FSParameter_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x0608):
dissect_PDInterfaceFSUDataAdjust_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength);
break;
case(0x010B):
case(0x0609):
dissect_ARFSUDataAdjust_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, u16BodyLength);
break;
case(0x0f00):
dissect_Maintenance_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x8001):
case(0x8002):
dissect_Alarm_ack_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x8008):
dissect_IODWriteResHeader_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow,
u16Index, u32RecDataLen, ar);
break;
case(0x8009):
dissect_IODReadResHeader_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow,
u16Index, u32RecDataLen, ar);
break;
case(0x8101):
dissect_ARBlockRes_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, ar);
break;
case(0x8102):
dissect_IOCRBlockRes_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, *ar);
break;
case(0x8103):
dissect_AlarmCRBlockRes_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, *ar);
break;
case(0x8104):
dissect_ModuleDiffBlock_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x8106):
dissect_ARServerBlock(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow);
break;
case(0x8110):
case(0x8111):
case(0x8112):
case(0x8113):
case(0x8114):
case(0x8116):
case(0x8117):
case(0x8118):
dissect_ControlConnect_block(tvb, offset, pinfo, sub_tree, sub_item, drep, u8BlockVersionHigh, u8BlockVersionLow, ar);
break;
default:
dissect_pn_undecoded(tvb, offset, pinfo, sub_tree, u16BodyLength);
}
offset += u16BodyLength;
proto_item_set_len(sub_item, offset - u32SubStart);
return offset;
}
static int
dissect_a_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint16 u16Index = 0;
guint32 u32RecDataLen;
pnio_ar_t *ar = NULL;
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
if (ar != NULL) {
pnio_ar_info(tvb, pinfo, tree, ar);
}
return offset;
}
static int
dissect_blocks(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint16 u16Index = 0;
guint32 u32RecDataLen;
pnio_ar_t *ar = NULL;
while (tvb_length(tvb) > (guint) offset) {
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
u16Index++;
}
if (ar != NULL) {
pnio_ar_info(tvb, pinfo, tree, ar);
}
return offset;
}
static int
dissect_IPNIO_rqst_header(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32ArgsMax;
guint32 u32ArgsLen;
guint32 u32MaxCount;
guint32 u32Offset;
guint32 u32ArraySize;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32SubStart;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PNIO-CM");
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_args_max, &u32ArgsMax);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_args_len, &u32ArgsLen);
sub_item = proto_tree_add_item(tree, hf_pn_io_array, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io);
u32SubStart = offset;
offset = dissect_ndr_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_array_max_count, &u32MaxCount);
offset = dissect_ndr_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_array_offset, &u32Offset);
offset = dissect_ndr_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_array_act_count, &u32ArraySize);
proto_item_append_text(sub_item, ": Max: %u, Offset: %u, Size: %u",
u32MaxCount, u32Offset, u32ArraySize);
proto_item_set_len(sub_item, offset - u32SubStart);
return offset;
}
static int
dissect_IPNIO_resp_header(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32ArgsLen;
guint32 u32MaxCount;
guint32 u32Offset;
guint32 u32ArraySize;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32SubStart;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PNIO-CM");
offset = dissect_PNIO_status(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_pn_io_args_len, &u32ArgsLen);
sub_item = proto_tree_add_item(tree, hf_pn_io_array, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io);
u32SubStart = offset;
offset = dissect_ndr_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_array_max_count, &u32MaxCount);
offset = dissect_ndr_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_array_offset, &u32Offset);
offset = dissect_ndr_uint32(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_array_act_count, &u32ArraySize);
proto_item_append_text(sub_item, ": Max: %u, Offset: %u, Size: %u",
u32MaxCount, u32Offset, u32ArraySize);
proto_item_set_len(sub_item, offset - u32SubStart);
return offset;
}
static int
dissect_IPNIO_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_IPNIO_rqst_header(tvb, offset, pinfo, tree, drep);
offset = dissect_blocks(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
dissect_IPNIO_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_IPNIO_resp_header(tvb, offset, pinfo, tree, drep);
offset = dissect_blocks(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
dissect_ProfiDriveParameterRequest(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint8 request_reference;
guint8 request_id;
guint8 do_id;
guint8 no_of_parameters;
guint8 addr_idx;
proto_item *profidrive_item;
proto_tree *profidrive_tree;
profidrive_item = proto_tree_add_item(tree, hf_pn_io_block, tvb, offset, 0, ENC_NA);
profidrive_tree = proto_item_add_subtree(profidrive_item, ett_pn_io_profidrive_parameter_request);
proto_item_set_text(profidrive_item, "PROFIDrive Parameter Request: ");
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, profidrive_tree, drep,
hf_pn_io_profidrive_request_reference, &request_reference);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, profidrive_tree, drep,
hf_pn_io_profidrive_request_id, &request_id);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, profidrive_tree, drep,
hf_pn_io_profidrive_do_id, &do_id);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, profidrive_tree, drep,
hf_pn_io_profidrive_no_of_parameters, &no_of_parameters);
proto_item_append_text(profidrive_item, "ReqRef:0x%02x, ReqId:%s, DO:%u, NoOfParameters:%u",
request_reference, val_to_str(request_id, pn_io_profidrive_request_id_vals, "Unknown"),
do_id, no_of_parameters);
col_clear(pinfo->cinfo, COL_INFO);
col_append_fstr(pinfo->cinfo, COL_INFO, "PROFIDrive Write Request, ReqRef:0x%02x, %s DO:%u",
request_reference,
request_id==0x01 ? "Read" :
request_id==0x02 ? "Change" :
"",
do_id);
for(addr_idx=0; addr_idx<no_of_parameters; addr_idx++) {
guint8 attribute;
guint8 no_of_elems;
guint16 parameter;
guint16 idx;
proto_item *sub_item;
proto_tree *sub_tree;
sub_item = proto_tree_add_item(profidrive_tree, hf_pn_io_block, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_profidrive_parameter_address);
proto_item_set_text(sub_item, "Parameter Address %u: ", addr_idx+1);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_profidrive_param_attribute, &attribute);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_profidrive_param_no_of_elems, &no_of_elems);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_profidrive_param_number, &parameter);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_profidrive_param_subindex, &idx);
proto_item_append_text(sub_item, "Attr:%s, Elems:%u, Parameter:%u, Index:%u",
val_to_str(attribute, pn_io_profidrive_attribute_vals, "Unknown"), no_of_elems,
parameter, idx);
if (no_of_elems>1) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", P%d[%d..%d]", parameter, idx, idx+no_of_elems-1);
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, ", P%d[%d]", parameter, idx);
}
}
if (request_id == 0x02) {
for(addr_idx=0; addr_idx<no_of_parameters; addr_idx++) {
guint8 format;
guint8 no_of_vals;
proto_item *sub_item;
proto_tree *sub_tree;
sub_item = proto_tree_add_item(profidrive_tree, hf_pn_io_block, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_profidrive_parameter_value);
proto_item_set_text(sub_item, "Parameter Value %u: ", addr_idx+1);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_profidrive_param_format, &format);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_profidrive_param_no_of_values, &no_of_vals);
proto_item_append_text(sub_item, "Format:%s, NoOfVals:%u",
val_to_str(format, pn_io_profidrive_format_vals, "Unknown"), no_of_vals);
while (no_of_vals--) {
guint16 value;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_profidrive_param_value, &value);
}
}
}
return offset;
}
static int
dissect_ProfiDriveParameterResponse(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint8 request_reference;
guint8 response_id;
guint8 do_id;
guint8 no_of_parameters;
guint8 val_idx;
proto_item *profidrive_item;
proto_tree *profidrive_tree;
profidrive_item = proto_tree_add_item(tree, hf_pn_io_block, tvb, offset, 0, ENC_NA);
profidrive_tree = proto_item_add_subtree(profidrive_item, ett_pn_io_profidrive_parameter_response);
proto_item_set_text(profidrive_item, "PROFIDrive Parameter Response: ");
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, profidrive_tree, drep,
hf_pn_io_profidrive_request_reference, &request_reference);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, profidrive_tree, drep,
hf_pn_io_profidrive_response_id, &response_id);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, profidrive_tree, drep,
hf_pn_io_profidrive_do_id, &do_id);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, profidrive_tree, drep,
hf_pn_io_profidrive_no_of_parameters, &no_of_parameters);
proto_item_append_text(profidrive_item, "ReqRef:0x%02x, RspId:%s, DO:%u, NoOfParameters:%u",
request_reference, val_to_str(response_id, pn_io_profidrive_response_id_vals, "Unknown"),
do_id, no_of_parameters);
col_clear(pinfo->cinfo, COL_INFO);
col_append_fstr(pinfo->cinfo, COL_INFO, "PROFIDrive Read Response, ReqRef:0x%02x, RspId:%s",
request_reference,
val_to_str(response_id, pn_io_profidrive_response_id_vals, "Unknown response"));
val_idx = 1;
while (no_of_parameters--) {
guint8 format;
guint8 no_of_vals;
proto_item *sub_item;
proto_tree *sub_tree;
sub_item = proto_tree_add_item(profidrive_tree, hf_pn_io_block, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_profidrive_parameter_value);
proto_item_set_text(sub_item, "Parameter Value %u: ", val_idx++);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_profidrive_param_format, &format);
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_profidrive_param_no_of_values, &no_of_vals);
proto_item_append_text(sub_item, "Format:%s, NoOfVals:%u",
val_to_str(format, pn_io_profidrive_format_vals, "Unknown"), no_of_vals);
while (no_of_vals--) {
guint16 value;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_profidrive_param_value, &value);
}
}
return offset;
}
static int
dissect_RecordDataRead(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep, guint16 u16Index, guint32 u32RecDataLen)
{
const gchar *userProfile;
pnio_ar_t *ar = NULL;
if (u16Index < 0x8000) {
offset = dissect_pn_user_data(tvb, offset, pinfo, tree, u32RecDataLen, "User Specified Data");
return offset;
}
if (u16Index == 0xb02e || u16Index == 0xb02f) {
return dissect_ProfiDriveParameterResponse(tvb, offset, pinfo, tree, drep);
}
userProfile = indexReservedForProfiles(u16Index);
if (userProfile != NULL) {
offset = dissect_pn_user_data(tvb, offset, pinfo, tree, u32RecDataLen, userProfile);
return offset;
}
switch (u16Index) {
case(0x8010):
case(0x8011):
case(0x8012):
case(0x8013):
case(0x801e):
case(0x8028):
case(0x8029):
case(0x8050):
case(0x8051):
case(0x8052):
case(0x8053):
case(0x8054):
case(0x8060):
case(0x8061):
case(0x8062):
case(0x8070):
case(0x8071):
case(0x8080):
case(0x8090):
case(0xaff0):
case(0xaff1):
case(0xaff2):
case(0xaff3):
case(0xaff4):
case(0xaff5):
case(0xaff6):
case(0xaff7):
case(0xaff8):
case(0xaff9):
case(0xaffa):
case(0xaffb):
case(0xaffc):
case(0xaffd):
case(0xaffe):
case(0xafff):
case(0xc010):
case(0xc011):
case(0xc012):
case(0xc013):
case(0xe002):
case(0xe010):
case(0xe011):
case(0xe012):
case(0xe013):
case(0xf010):
case(0xf011):
case(0xf012):
case(0xf013):
case(0xf020):
case(0xf820):
case(0xf821):
case(0xf830):
case(0xf831):
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
break;
case(0xf840):
{
int end_offset = offset + u32RecDataLen;
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
if (end_offset > offset)
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
if (end_offset > offset)
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
}
break;
case(0xB050):
case(0xB051):
case(0xB060):
case(0xB061):
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
break;
case(0x8000):
case(0x8001):
case(0x800a):
case(0x800b):
case(0x800c):
case(0x802a):
case(0x802b):
case(0x802d):
case(0x802e):
case(0x802f):
case(0x8030):
case(0x8031):
case(0x8032):
case(0x8033):
case(0x8034):
case(0x8035):
case(0x8036):
case(0x8037):
case(0x8038):
case(0x8039):
case(0x803a):
case(0x803b):
case(0x803c):
case(0x803d):
case(0x803e):
case(0x803f):
case(0x8040):
case(0x8041):
case(0x8042):
case(0x8043):
case(0x8044):
case(0x8045):
case(0x8046):
case(0x8047):
case(0x8048):
case(0x8049):
case(0x804a):
case(0x804b):
case(0x804c):
case(0x804d):
case(0x804e):
case(0x804f):
case(0x8072):
case(0xc000):
case(0xc001):
case(0xc00a):
case(0xc00b):
case(0xc00c):
case(0xe000):
case(0xe001):
case(0xe00a):
case(0xe00b):
case(0xe00c):
case(0xe030):
case(0xf000):
case(0xf00a):
case(0xf00b):
case(0xf00c):
case(0xf80c):
case(0xf841):
case(0xf842):
offset = dissect_blocks(tvb, offset, pinfo, tree, drep);
break;
default:
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, u32RecDataLen);
}
return offset;
}
static int
dissect_IPNIO_Read_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint16 u16Index = 0;
guint32 u32RecDataLen = 0;
pnio_ar_t *ar = NULL;
offset = dissect_IPNIO_resp_header(tvb, offset, pinfo, tree, drep);
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
if (u32RecDataLen != 0) {
offset = dissect_RecordDataRead(tvb, offset, pinfo, tree, drep, u16Index, u32RecDataLen);
}
if (ar != NULL) {
pnio_ar_info(tvb, pinfo, tree, ar);
}
return offset;
}
static int
dissect_ProfiSafeParameterRequest(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
proto_item *f_item;
proto_tree *f_tree;
proto_item *flags1_item;
proto_tree *flags1_tree;
proto_item *flags2_item;
proto_tree *flags2_tree;
guint16 src_addr;
guint16 dst_addr;
guint16 wd_time;
guint16 par_crc;
guint8 prm_flag1;
guint8 prm_flag1_chck_seq;
guint8 prm_flag1_chck_ipar;
guint8 prm_flag1_sil;
guint8 prm_flag1_crc_len;
guint8 prm_flag1_reserved;
guint8 prm_flag2;
guint8 prm_flag2_reserved;
guint8 prm_flag2_f_block_id;
guint8 prm_flag2_f_par_version;
prm_flag1 = 0;
prm_flag2 = 0;
f_item = proto_tree_add_item(tree, hf_pn_io_block, tvb, offset, 0, ENC_NA);
f_tree = proto_item_add_subtree(f_item, ett_pn_io_profisafe_f_parameter);
proto_item_set_text(f_item, "F-Parameter: ");
flags1_item = proto_tree_add_item(f_tree, hf_pn_io_profisafe_f_prm_flag1, tvb, offset, 1, ENC_BIG_ENDIAN);
flags1_tree = proto_item_add_subtree(flags1_item, ett_pn_io_profisafe_f_parameter_prm_flag1);
dissect_dcerpc_uint8(tvb, offset, pinfo, flags1_tree, drep,
hf_pn_io_profisafe_f_prm_flag1_chck_seq, &prm_flag1_chck_seq);
dissect_dcerpc_uint8(tvb, offset, pinfo, flags1_tree, drep,
hf_pn_io_profisafe_f_prm_flag1_chck_ipar, &prm_flag1_chck_ipar);
dissect_dcerpc_uint8(tvb, offset, pinfo, flags1_tree, drep,
hf_pn_io_profisafe_f_prm_flag1_sil, &prm_flag1_sil);
dissect_dcerpc_uint8(tvb, offset, pinfo, flags1_tree, drep,
hf_pn_io_profisafe_f_prm_flag1_crc_len, &prm_flag1_crc_len);
dissect_dcerpc_uint8(tvb, offset, pinfo, flags1_tree, drep,
hf_pn_io_profisafe_f_prm_flag1_reserved, &prm_flag1_reserved);
prm_flag1 = prm_flag1_chck_seq|prm_flag1_chck_ipar|prm_flag1_sil|prm_flag1_reserved;
offset++;
flags2_item = proto_tree_add_item(f_tree, hf_pn_io_profisafe_f_prm_flag2, tvb, offset, 1, ENC_BIG_ENDIAN);
flags2_tree = proto_item_add_subtree(flags2_item, ett_pn_io_profisafe_f_parameter_prm_flag2);
dissect_dcerpc_uint8(tvb, offset, pinfo, flags2_tree, drep,
hf_pn_io_profisafe_f_prm_flag2_reserved, &prm_flag2_reserved);
dissect_dcerpc_uint8(tvb, offset, pinfo, flags2_tree, drep,
hf_pn_io_profisafe_f_prm_flag2_f_block_id, &prm_flag2_f_block_id);
dissect_dcerpc_uint8(tvb, offset, pinfo, flags2_tree, drep,
hf_pn_io_profisafe_f_prm_flag2_f_par_version, &prm_flag2_f_par_version);
prm_flag2 = prm_flag2_reserved|prm_flag2_f_block_id|prm_flag2_f_par_version;
offset++;
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, f_item, drep,
hf_pn_io_profisafe_f_src_addr, &src_addr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, f_item, drep,
hf_pn_io_profisafe_f_dst_addr, &dst_addr);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, f_item, drep,
hf_pn_io_profisafe_f_wd_time, &wd_time);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, f_item, drep,
hf_pn_io_profisafe_f_par_crc, &par_crc);
col_append_fstr(pinfo->cinfo, COL_INFO,
", F-Parameter record, prm_flag1:0x%02x, prm_flag2:0x%02x, src:0x%04x,"
" dst:0x%04x, wd_time:%d, crc:0x%04x",
prm_flag1, prm_flag2, src_addr, dst_addr, wd_time, par_crc);
proto_item_append_text(f_item, "prm_flag1:0x%02x, prm_flag2:0x%02x, src:0x%04x, dst:0x%04x, wd_time:%d, crc:0x%04x",
prm_flag1, prm_flag2, src_addr, dst_addr, wd_time, par_crc);
return offset;
}
static int
dissect_RecordDataWrite(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep, guint16 u16Index, guint32 u32RecDataLen)
{
const gchar *userProfile;
pnio_ar_t *ar = NULL;
if (u16Index == 0x0100) {
return dissect_ProfiSafeParameterRequest(tvb, offset, pinfo, tree, drep);
}
if (u16Index < 0x8000) {
return dissect_pn_user_data(tvb, offset, pinfo, tree, u32RecDataLen, "User Specified Data");
}
if (u16Index == 0xb02e || u16Index == 0xb02f) {
return dissect_ProfiDriveParameterRequest(tvb, offset, pinfo, tree, drep);
}
userProfile = indexReservedForProfiles(u16Index);
if (userProfile != NULL) {
offset = dissect_pn_user_data(tvb, offset, pinfo, tree, u32RecDataLen, userProfile);
return offset;
}
switch (u16Index) {
case(0x8020):
case(0x801e):
case(0x802b):
case(0x802c):
case(0x802d):
case(0x802e):
case(0x802f):
case(0x8030):
case(0x8051):
case(0x8052):
case(0x8053):
case(0x8061):
case(0x8062):
case(0x8070):
case(0x8071):
case(0x8090):
case(0xe030):
case(0xe050):
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
break;
default:
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, u32RecDataLen);
}
return offset;
}
static int
dissect_IODWriteReq(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep, pnio_ar_t **ar)
{
guint16 u16Index = 0;
guint32 u32RecDataLen;
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, ar);
if (u16Index == 0xe040) {
while (tvb_length_remaining(tvb, offset) > 0) {
offset = dissect_IODWriteReq(tvb, offset, pinfo, tree, drep, ar);
}
} else {
tvbuff_t *new_tvb = tvb_new_subset(tvb, offset, u32RecDataLen, u32RecDataLen);
offset += dissect_RecordDataWrite(new_tvb, 0, pinfo, tree, drep, u16Index, u32RecDataLen);
switch (offset % 4) {
case(3):
offset += 1;
break;
case(2):
offset += 2;
break;
case(1):
offset += 3;
break;
}
}
return offset;
}
static int
dissect_IPNIO_Write_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
pnio_ar_t *ar = NULL;
offset = dissect_IPNIO_rqst_header(tvb, offset, pinfo, tree, drep);
offset = dissect_IODWriteReq(tvb, offset, pinfo, tree, drep, &ar);
if (ar != NULL) {
pnio_ar_info(tvb, pinfo, tree, ar);
}
return offset;
}
static int
dissect_IODWriteRes(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint16 u16Index = 0;
guint32 u32RecDataLen;
pnio_ar_t *ar = NULL;
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
if (u16Index == 0xe040) {
while (tvb_length_remaining(tvb, offset) > 0) {
offset = dissect_block(tvb, offset, pinfo, tree, drep, &u16Index, &u32RecDataLen, &ar);
}
}
if (ar != NULL) {
pnio_ar_info(tvb, pinfo, tree, ar);
}
return offset;
}
static int
dissect_IPNIO_Write_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_IPNIO_resp_header(tvb, offset, pinfo, tree, drep);
offset = dissect_IODWriteRes(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
dissect_PNIO_IOxS(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, guint8 *drep _U_, int hfindex)
{
if (tree) {
guint8 u8IOxS;
proto_item *ioxs_item;
proto_tree *ioxs_tree;
u8IOxS = tvb_get_guint8(tvb, offset);
ioxs_item = proto_tree_add_uint(tree, hfindex, tvb, offset, 1, u8IOxS);
proto_item_append_text(ioxs_item,
" (%s%s)",
(u8IOxS & 0x01) ? "another IOxS follows " : "",
(u8IOxS & 0x80) ? "good" : "bad");
ioxs_tree = proto_item_add_subtree(ioxs_item, ett_pn_io_ioxs);
proto_tree_add_uint(ioxs_tree, hf_pn_io_ioxs_datastate, tvb, offset, 1, u8IOxS);
proto_tree_add_uint(ioxs_tree, hf_pn_io_ioxs_instance, tvb, offset, 1, u8IOxS);
proto_tree_add_uint(ioxs_tree, hf_pn_io_ioxs_res14, tvb, offset, 1, u8IOxS);
proto_tree_add_uint(ioxs_tree, hf_pn_io_ioxs_extension, tvb, offset, 1, u8IOxS);
}
return offset + 1;
}
static int
dissect_PNIO_C_SDU(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
proto_tree *data_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PNIO");
if (tree) {
proto_item *data_item;
data_item = proto_tree_add_protocol_format(tree, proto_pn_io, tvb, offset, tvb_length(tvb),
"PROFINET IO Cyclic Service Data Unit: %u bytes", tvb_length(tvb));
data_tree = proto_item_add_subtree(data_item, ett_pn_io_rtc);
}
if (!(dissect_CSF_SDU_heur(tvb, pinfo, data_tree, NULL) == FALSE))
return(tvb_length(tvb));
offset = dissect_PNIO_IOxS(tvb, offset, pinfo, data_tree, drep, hf_pn_io_ioxs);
offset = dissect_pn_user_data(tvb, offset, pinfo, tree, tvb_length_remaining(tvb, offset),
"User Data (including GAP and RTCPadding)");
return offset;
}
static int
dissect_PNIO_RTA(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint16 u16AlarmDstEndpoint;
guint16 u16AlarmSrcEndpoint;
guint8 u8PDUType;
guint8 u8PDUVersion;
guint8 u8WindowSize;
guint8 u8Tack;
guint16 u16SendSeqNum;
guint16 u16AckSeqNum;
guint16 u16VarPartLen;
int start_offset = offset;
guint16 u16Index = 0;
guint32 u32RecDataLen;
pnio_ar_t *ar = NULL;
proto_item *rta_item;
proto_tree *rta_tree;
proto_item *sub_item;
proto_tree *sub_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PNIO-AL");
rta_item = proto_tree_add_protocol_format(tree, proto_pn_io, tvb, offset, tvb_length(tvb),
"PROFINET IO Alarm");
rta_tree = proto_item_add_subtree(rta_item, ett_pn_io_rta);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, rta_tree, drep,
hf_pn_io_alarm_dst_endpoint, &u16AlarmDstEndpoint);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, rta_tree, drep,
hf_pn_io_alarm_src_endpoint, &u16AlarmSrcEndpoint);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Src: 0x%x, Dst: 0x%x",
u16AlarmSrcEndpoint, u16AlarmDstEndpoint);
sub_item = proto_tree_add_item(rta_tree, hf_pn_io_pdu_type, tvb, offset, 1, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_pdu_type);
dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_pdu_type_type, &u8PDUType);
u8PDUType &= 0x0F;
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_pdu_type_version, &u8PDUVersion);
u8PDUVersion >>= 4;
proto_item_append_text(sub_item, ", Type: %s, Version: %u",
val_to_str(u8PDUType, pn_io_pdu_type, "Unknown"),
u8PDUVersion);
sub_item = proto_tree_add_item(rta_tree, hf_pn_io_add_flags, tvb, offset, 1, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_io_add_flags);
dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_window_size, &u8WindowSize);
u8WindowSize &= 0x0F;
offset = dissect_dcerpc_uint8(tvb, offset, pinfo, sub_tree, drep,
hf_pn_io_tack, &u8Tack);
u8Tack >>= 4;
proto_item_append_text(sub_item, ", Window Size: %u, Tack: %u",
u8WindowSize, u8Tack);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, rta_tree, drep,
hf_pn_io_send_seq_num, &u16SendSeqNum);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, rta_tree, drep,
hf_pn_io_ack_seq_num, &u16AckSeqNum);
offset = dissect_dcerpc_uint16(tvb, offset, pinfo, rta_tree, drep,
hf_pn_io_var_part_len, &u16VarPartLen);
switch ( u8PDUType & 0x0F) {
case(1):
col_append_str(pinfo->cinfo, COL_INFO, ", Data-RTA");
offset = dissect_block(tvb, offset, pinfo, rta_tree, drep, &u16Index, &u32RecDataLen, &ar);
break;
case(2):
col_append_str(pinfo->cinfo, COL_INFO, ", NACK-RTA");
break;
case(3):
col_append_str(pinfo->cinfo, COL_INFO, ", ACK-RTA");
break;
case(4):
col_append_str(pinfo->cinfo, COL_INFO, ", ERR-RTA");
offset = dissect_PNIO_status(tvb, offset, pinfo, rta_tree, drep);
break;
default:
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, tvb_length(tvb));
}
proto_item_set_len(rta_item, offset - start_offset);
return offset;
}
static gboolean
dissect_PNIO_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
guint8 drep_data = 0;
guint8 *drep = &drep_data;
guint8 u8CBAVersion;
guint16 u16FrameID;
if (dissector_try_heuristic(heur_pn_subdissector_list, tvb, pinfo, tree, NULL))
return TRUE;
u16FrameID = GPOINTER_TO_UINT(pinfo->private_data);
u8CBAVersion = tvb_get_guint8 (tvb, 0);
if ((u16FrameID >= 0x0100 && u16FrameID <= 0x6FF ) ||
(u16FrameID >= 0x700 && u16FrameID <= 0x0fff)) {
dissect_PNIO_C_SDU(tvb, 0, pinfo, tree, drep);
return TRUE;
}
if ((
(u16FrameID >= 0x5000 && u16FrameID <= 0x57ff) ||
(u16FrameID >= 0x6000 && u16FrameID <= 0x67ff) ||
(u16FrameID >= 0x7000 && u16FrameID <= 0x77ff) ||
(u16FrameID >= 0x8000 && u16FrameID <= 0xbfff))
&& u8CBAVersion != 0x11) {
dissect_PNIO_C_SDU(tvb, 0, pinfo, tree, drep);
return TRUE;
}
if (u16FrameID >= 0xc000 && u16FrameID < 0xfbff && u8CBAVersion != 0x11) {
dissect_PNIO_C_SDU(tvb, 0, pinfo, tree, drep);
return TRUE;
}
if (u16FrameID == 0xfc01) {
col_set_str(pinfo->cinfo, COL_INFO, "Alarm High");
dissect_PNIO_RTA(tvb, 0, pinfo, tree, drep);
return TRUE;
}
if (u16FrameID == 0xfe01) {
col_set_str(pinfo->cinfo, COL_INFO, "Alarm Low");
dissect_PNIO_RTA(tvb, 0, pinfo, tree, drep);
return TRUE;
}
return FALSE;
}
static gboolean
pn_io_ar_conv_valid(packet_info *pinfo)
{
return (pinfo->profinet_type == 10);
}
static const gchar *
pn_io_ar_conv_filter(packet_info *pinfo)
{
pnio_ar_t *ar = (pnio_ar_t *)pinfo->profinet_conv;
char *buf;
if (pinfo->profinet_type != 10) {
return NULL;
}
buf = g_strdup_printf(
"pn_io.ar_uuid == %s || "
"(pn_io.alarm_src_endpoint == 0x%x && eth.src == %s) || "
"(pn_io.alarm_src_endpoint == 0x%x && eth.src == %s)",
guid_to_str((const e_guid_t*) &ar->aruuid),
ar->controlleralarmref, ether_to_str((const guint8 *)ar->controllermac),
ar->devicealarmref, ether_to_str((const guint8 *)ar->devicemac));
return buf;
}
static const gchar *
pn_io_ar_conv_data_filter(packet_info *pinfo)
{
pnio_ar_t *ar = (pnio_ar_t *)pinfo->profinet_conv;
char *buf;
if (pinfo->profinet_type != 10) {
return NULL;
}
if (ar->arType == 0x0010)
{
buf = g_strdup_printf(
"pn_io.ar_uuid == %s || "
"(pn_rt.frame_id == 0x%x) || (pn_rt.frame_id == 0x%x) || "
"(pn_io.alarm_src_endpoint == 0x%x && eth.src == %s) || "
"(pn_io.alarm_src_endpoint == 0x%x && eth.src == %s)",
guid_to_str((const e_guid_t*) &ar->aruuid),
ar->inputframeid, ar->outputframeid,
ar->controlleralarmref, ether_to_str((const guint8 *)ar->controllermac),
ar->devicealarmref, ether_to_str((const guint8 *)ar->devicemac));
}
else
{
buf = g_strdup_printf(
"pn_io.ar_uuid == %s || "
"(pn_rt.frame_id == 0x%x && eth.src == %s && eth.dst == %s) || "
"(pn_rt.frame_id == 0x%x && eth.src == %s && eth.dst == %s) || "
"(pn_io.alarm_src_endpoint == 0x%x && eth.src == %s) || "
"(pn_io.alarm_src_endpoint == 0x%x && eth.src == %s)",
guid_to_str((const e_guid_t*) &ar->aruuid),
ar->inputframeid, ether_to_str((const guint8 *)ar->devicemac), ether_to_str((const guint8 *)ar->controllermac),
ar->outputframeid, ether_to_str((const guint8 *)ar->controllermac), ether_to_str((const guint8 *)ar->devicemac),
ar->controlleralarmref, ether_to_str((const guint8 *)ar->controllermac),
ar->devicealarmref, ether_to_str((const guint8 *)ar->devicemac));
}
return buf;
}
static void
pnio_reinit( void) {
pnio_ars = NULL;
}
void
proto_register_pn_io (void)
{
static hf_register_info hf[] = {
{ &hf_pn_io_opnum,
{ "Operation", "pn_io.opnum",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_reserved16,
{ "Reserved", "pn_io.reserved16",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_array,
{ "Array", "pn_io.array",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_status,
{ "Status", "pn_io.status",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_args_max,
{ "ArgsMaximum", "pn_io.args_max",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_args_len,
{ "ArgsLength", "pn_io.args_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_array_max_count,
{ "MaximumCount", "pn_io.array_max_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_array_offset,
{ "Offset", "pn_io.array_offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_array_act_count,
{ "ActualCount", "pn_io.array_act_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ar_data,
{ "ARDATA for AR:", "pn_io.ar_data",
FT_NONE, BASE_NONE, 0x0, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ar_type,
{ "ARType", "pn_io.ar_type",
FT_UINT16, BASE_HEX, VALS(pn_io_ar_type), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_cminitiator_macadd,
{ "CMInitiatorMacAdd", "pn_io.cminitiator_mac_add",
FT_ETHER, BASE_NONE, 0x0, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_cminitiator_objectuuid,
{ "CMInitiatorObjectUUID", "pn_io.cminitiator_uuid",
FT_GUID, BASE_NONE, 0x0, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_parameter_server_objectuuid,
{ "ParameterServerObjectUUID", "pn_io.parameter_server_objectuuid",
FT_GUID, BASE_NONE, 0x0, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ar_properties,
{ "ARProperties", "pn_io.ar_properties",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ar_properties_state,
{ "State", "pn_io.ar_properties.state",
FT_UINT32, BASE_HEX, VALS(pn_io_arproperties_state), 0x00000007,
NULL, HFILL }
},
{ &hf_pn_io_ar_properties_supervisor_takeover_allowed,
{ "SupervisorTakeoverAllowed", "pn_io.ar_properties.supervisor_takeover_allowed",
FT_UINT32, BASE_HEX, VALS(pn_io_arproperties_supervisor_takeover_allowed), 0x00000008,
NULL, HFILL }
},
{ &hf_pn_io_ar_properties_parametrization_server,
{ "ParametrizationServer", "pn_io.ar_properties.parametrization_server",
FT_UINT32, BASE_HEX, VALS(pn_io_arproperties_parametrization_server), 0x00000010,
NULL, HFILL }
},
{ &hf_pn_io_artype_req,
{ "ARType", "pn_io.artype_req",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_io_ar_properties_companion_ar,
{ "CompanionAR", "pn_io.ar_properties.companion_ar",
FT_UINT32, BASE_HEX, VALS(pn_io_arproperties_companion_ar), 0x00000600,
NULL, HFILL }
},
{ &hf_pn_io_ar_properties_achnowledge_companion_ar,
{ "AcknowledgeCompanionAR", "pn_io.ar_properties.acknowledge_companion_ar",
FT_UINT32, BASE_HEX, VALS(pn_io_arproperties_acknowldege_companion_ar), 0x00000800,
NULL, HFILL }
},
{ &hf_pn_io_arproperties_StartupMode,
{ "StartupMode", "pn_io.ar_properties.StartupMode",
FT_UINT32, BASE_HEX, VALS(pn_io_arpropertiesStartupMode), 0x40000000,
NULL, HFILL }
},
{ &hf_pn_io_ar_properties_reserved,
{ "Reserved", "pn_io.ar_properties.reserved",
FT_UINT32, BASE_HEX, NULL, 0x3FFFF000,
NULL, HFILL }
},
{ &hf_pn_io_ar_properties_pull_module_alarm_allowed,
{ "PullModuleAlarmAllowed", "pn_io.ar_properties.pull_module_alarm_allowed",
FT_UINT32, BASE_HEX, VALS(pn_io_arproperties_pull_module_alarm_allowed), 0x80000000,
NULL, HFILL }
},
{ &hf_pn_RedundancyInfo,
{ "RedundancyInfo.EndPoint", "pn_io.srl_data.redundancyInfo",
FT_UINT16, BASE_HEX, VALS(pn_io_RedundancyInfo), 0x0000003,
NULL, HFILL }
},
{ &hf_pn_RedundancyInfo_reserved,
{ "RedundancyInfo.reserved", "pn_io.srl_data.redundancyInfoReserved",
FT_UINT16, BASE_HEX, NULL, 0xFFFFFFFC,
NULL, HFILL }
},
{ &hf_pn_io_number_of_ARDATAInfo,
{ "ARDataInfo.NumberOfEntries", "pn_io.number_of_ARDATAInfo",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_cminitiator_activitytimeoutfactor,
{ "CMInitiatorActivityTimeoutFactor", "pn_io.cminitiator_activitytimeoutfactor",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_cminitiator_udprtport,
{ "CMInitiatorUDPRTPort", "pn_io.cminitiator_udprtport",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_station_name_length,
{ "StationNameLength", "pn_io.station_name_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_cminitiator_station_name,
{ "CMInitiatorStationName", "pn_io.cminitiator_station_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_pn_io_responder_station_name,
{ "CMResponderrStationName", "pn_io.cmresponder_station_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_pn_io_parameter_server_station_name,
{ "ParameterServerStationName", "pn_io.parameter_server_station_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_cmresponder_macadd,
{ "CMResponderMacAdd", "pn_io.cmresponder_macadd",
FT_ETHER, BASE_NONE, 0x0, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_cmresponder_udprtport,
{ "CMResponderUDPRTPort", "pn_io.cmresponder_udprtport",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_number_of_iocrs,
{ "NumberOfIOCRs", "pn_io.number_of_iocrs",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_iocr_tree,
{ "IOCR", "pn_io.iocr_tree",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_iocr_type,
{ "IOCRType", "pn_io.iocr_type",
FT_UINT16, BASE_HEX, VALS(pn_io_iocr_type), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_iocr_reference,
{ "IOCRReference", "pn_io.iocr_reference",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_pn_io_iocr_txports_port,
{ "IOCRTxPorts.Port", "pn_io.iocr_txports_port",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
#if 0
{ &hf_pn_io_iocr_txports_redundantport,
{ "IOCRTxPorts.RedundantPort", "pn_io.iocr_txports_redundantport",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_pn_io_iocr_SubframeOffset,
{ "SubframeOffset", "pn_io.subframe_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_iocr_SubframeData,
{ "SubframeData", "pn_io.subframe_data",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_RedundancyDataHoldFactor,
{ "RedundancyDataHoldFactor", "pn_io.RedundancyDataHoldFactor",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_sr_properties,
{ "SRProperties", "pn_io.sr_properties",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_sr_properties_InputValidOnBackupAR,
{ "InputValidOnBackupAR", "pn_io.sr_properties.InputValidOnBackupAR",
FT_UINT32, BASE_HEX, VALS(pn_io_sr_properties_BackupAR), 0x01,
NULL, HFILL }
},
{ &hf_pn_io_sr_properties_ActivateRedundancyAlarm,
{ "ActivateRedundancyAlarm", "pn_io.sr_properties.ActivateRedundancyAlarm",
FT_UINT32, BASE_HEX, VALS(pn_io_sr_properties_ActivateRedundancyAlarm), 0x02,
NULL, HFILL }
},
{ &hf_pn_io_sr_properties_Reserved_1,
{ "Reserved_1", "pn_io.sr_properties.Reserved_1",
FT_UINT32, BASE_HEX, NULL, 0x0FFFC,
NULL, HFILL }
},
{ &hf_pn_io_sr_properties_Reserved_2,
{ "Reserved_2", "pn_io.sr_properties.Reserved_2",
FT_UINT32, BASE_HEX, NULL, 0x0FFFF0000,
NULL, HFILL }
},
{ &hf_pn_io_arvendor_strucidentifier_if0_low,
{ "APStructureIdentifier: Vendor specific", "pn_io.structidentifier_api_0_low",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_arvendor_strucidentifier_if0_high,
{ "APStructureIdentifier: Administrative number for common profiles", "pn_io.structidentifier_api_0_high",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_arvendor_strucidentifier_if0_is8000,
{ "APStructureIdentifier: Extended identification rules", "pn_io.tructidentifier_api_0_is8000",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_arvendor_strucidentifier_not0,
{ "APStructureIdentifier: Administrative number for application profiles", "pn_io.tructidentifier_api_not_0",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_lt,
{ "LT", "pn_io.lt",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_iocr_properties,
{ "IOCRProperties", "pn_io.iocr_properties",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_iocr_properties_rtclass,
{ "RTClass", "pn_io.iocr_properties.rtclass",
FT_UINT32, BASE_HEX, VALS(pn_io_iocr_properties_rtclass), 0x0000000F,
NULL, HFILL }
},
{ &hf_pn_io_iocr_properties_reserved_1,
{ "Reserved1", "pn_io.iocr_properties.reserved1",
FT_UINT32, BASE_HEX, NULL, 0x000007F0,
NULL, HFILL }
},
{ &hf_pn_io_iocr_properties_media_redundancy,
{ "MediaRedundancy", "pn_io.iocr_properties.media_redundancy",
FT_UINT32, BASE_HEX, VALS(pn_io_iocr_properties_media_redundancy), 0x00000800,
NULL, HFILL }
},
{ &hf_pn_io_iocr_properties_reserved_2,
{ "Reserved2", "pn_io.iocr_properties.reserved2",
FT_UINT32, BASE_HEX, NULL, 0x00FFF000,
NULL, HFILL }
},
{ &hf_pn_io_iocr_properties_reserved_3,
{ "Reserved3", "pn_io.iocr_properties.reserved3",
FT_UINT32, BASE_HEX, NULL, 0x1F000000,
NULL, HFILL }
},
{ &hf_pn_io_iocr_properties_fast_forwarding_mac_adr,
{ "FastForwardingMACAdr", "pn_io.iocr_properties.fast_forwarding_mac_adr",
FT_UINT32, BASE_HEX, NULL, 0x20000000,
NULL, HFILL }
},
{ &hf_pn_io_iocr_properties_distributed_subframe_watchdog,
{ "DistributedSubFrameWatchDog", "pn_io.iocr_properties.distributed_subframe_watchdog",
FT_UINT32, BASE_HEX, NULL, 0x40000000,
NULL, HFILL }
},
{ &hf_pn_io_iocr_properties_full_subframe_structure,
{ "FullSubFrameStructure", "pn_io.iocr_properties.full_subframe_structure",
FT_UINT32, BASE_HEX, NULL, 0x80000000,
NULL, HFILL }
},
{ &hf_pn_io_SFIOCRProperties,
{ "SFIOCRProperties", "pn_io.SFIOCRProperties",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_DistributedWatchDogFactor,
{ "SFIOCRProperties.DistributedWatchDogFactor", "pn_io.SFIOCRProperties.DistributedWatchDogFactor",
FT_UINT32, BASE_HEX, NULL, 0x0FF,
NULL, HFILL }
},
{ &hf_pn_io_RestartFactorForDistributedWD,
{ "SFIOCRProperties.RestartFactorForDistributedWD", "pn_io.SFIOCRProperties.RestartFactorForDistributedWD",
FT_UINT32, BASE_HEX, NULL, 0xff00,
NULL, HFILL }
},
{ &hf_pn_io_SFIOCRProperties_DFPmode,
{ "SFIOCRProperties.DFPmode", "pn_io.SFIOCRProperties.DFPmode",
FT_UINT32, BASE_HEX, NULL, 0xFF0000,
NULL, HFILL }
},
{ &hf_pn_io_SFIOCRProperties_reserved_1,
{ "SFIOCRProperties.reserved_1", "pn_io.SFIOCRProperties.reserved_1",
FT_UINT32, BASE_HEX, NULL, 0x0F000000,
NULL, HFILL }
},
{ &hf_pn_io_SFIOCRProperties_reserved_2,
{ "SFIOCRProperties.reserved_2", "pn_io.SFIOCRProperties.reserved_2",
FT_UINT32, BASE_HEX, NULL, 0x010000000,
NULL, HFILL }
},
{ &hf_pn_io_SFIOCRProperties_DFPType,
{ "SFIOCRProperties.DFPType", "pn_io.SFIOCRProperties.DFPType",
FT_UINT32, BASE_HEX, VALS(pn_io_SFIOCRProperties_DFPType_vals), 0x020000000,
NULL, HFILL }
},
{ &hf_pn_io_SFIOCRProperties_DFPRedundantPathLayout,
{ "SFIOCRProperties.DFPRedundantPathLayout", "pn_io.SFIOCRProperties.DFPRedundantPathLayout",
FT_UINT32, BASE_HEX, VALS(pn_io_DFPRedundantPathLayout_decode), 0x040000000,
NULL, HFILL }
},
{ &hf_pn_io_SFIOCRProperties_SFCRC16,
{ "SFIOCRProperties.SFCRC16", "pn_io.SFIOCRProperties.SFCRC16",
FT_UINT32, BASE_HEX, VALS(pn_io_SFCRC16_Decode), 0x080000000,
NULL, HFILL }
},
{ &hf_pn_io_data_length,
{ "DataLength", "pn_io.data_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ir_frame_data,
{ "Frame data", "pn_io.ir_frame_data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_frame_id,
{ "FrameID", "pn_io.frame_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_send_clock_factor,
{ "SendClockFactor", "pn_io.send_clock_factor",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_reduction_ratio,
{ "ReductionRatio", "pn_io.reduction_ratio",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_phase,
{ "Phase", "pn_io.phase",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_sequence,
{ "Sequence", "pn_io.sequence",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_frame_send_offset,
{ "FrameSendOffset", "pn_io.frame_send_offset",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_frame_data_properties,
{ "FrameDataProperties", "pn_io.frame_data_properties",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_frame_data_properties_forwarding_Mode,
{ "ForwardingMode", "pn_io.frame_data_properties_forwardingMode",
FT_UINT32, BASE_HEX, VALS(hf_pn_io_frame_data_properties_forwardingMode), 0x01,
NULL, HFILL }
},
{ &hf_pn_io_frame_data_properties_FastForwardingMulticastMACAdd,
{ "FastForwardingMulticastMACAdd", "pn_io.frame_data_properties_MulticastMACAdd",
FT_UINT32, BASE_HEX, VALS(hf_pn_io_frame_data_properties_FFMulticastMACAdd), 0x06,
NULL, HFILL }
},
{ &hf_pn_io_frame_data_properties_FragmentMode,
{ "FragmentationMode", "pn_io.frame_data_properties_FragMode",
FT_UINT32, BASE_HEX, VALS(hf_pn_io_frame_data_properties_FragMode), 0x18,
NULL, HFILL }
},
{ &hf_pn_io_frame_data_properties_reserved_1,
{ "Reserved_1", "pn_io.frame_data.reserved_1",
FT_UINT32, BASE_HEX, NULL, 0x0000FFE0,
NULL, HFILL }
},
{ &hf_pn_io_frame_data_properties_reserved_2,
{ "Reserved_2", "pn_io.frame_data.reserved_2",
FT_UINT32, BASE_HEX, NULL, 0xFFFF0000,
NULL, HFILL }
},
{ &hf_pn_io_watchdog_factor,
{ "WatchdogFactor", "pn_io.watchdog_factor",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_data_hold_factor,
{ "DataHoldFactor", "pn_io.data_hold_factor",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_iocr_tag_header,
{ "IOCRTagHeader", "pn_io.iocr_tag_header",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_iocr_multicast_mac_add,
{ "IOCRMulticastMACAdd", "pn_io.iocr_multicast_mac_add",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_number_of_apis,
{ "NumberOfAPIs", "pn_io.number_of_apis",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_number_of_io_data_objects,
{ "NumberOfIODataObjects", "pn_io.number_of_io_data_objects",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_io_data_object_frame_offset,
{ "IODataObjectFrameOffset", "pn_io.io_data_object_frame_offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_number_of_iocs,
{ "NumberOfIOCS", "pn_io.number_of_iocs",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_iocs_frame_offset,
{ "IOCSFrameOffset", "pn_io.iocs_frame_offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_alarmcr_type,
{ "AlarmCRType", "pn_io.alarmcr_type",
FT_UINT16, BASE_HEX, VALS(pn_io_alarmcr_type), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_alarmcr_properties,
{ "AlarmCRProperties", "pn_io.alarmcr_properties",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_alarmcr_properties_priority,
{ "priority", "pn_io.alarmcr_properties.priority",
FT_UINT32, BASE_HEX, VALS(pn_io_alarmcr_properties_priority), 0x00000001,
NULL, HFILL }
},
{ &hf_pn_io_alarmcr_properties_transport,
{ "Transport", "pn_io.alarmcr_properties.transport",
FT_UINT32, BASE_HEX, VALS(pn_io_alarmcr_properties_transport), 0x00000002,
NULL, HFILL }
},
{ &hf_pn_io_alarmcr_properties_reserved,
{ "Reserved", "pn_io.alarmcr_properties.reserved",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFC,
NULL, HFILL }
},
{ &hf_pn_io_rta_timeoutfactor,
{ "RTATimeoutFactor", "pn_io.rta_timeoutfactor",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_rta_retries,
{ "RTARetries", "pn_io.rta_retries",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_localalarmref,
{ "LocalAlarmReference", "pn_io.localalarmref",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_remotealarmref,
{ "RemoteAlarmReference", "pn_io.remotealarmref",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_maxalarmdatalength,
{ "MaxAlarmDataLength", "pn_io.maxalarmdatalength",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_alarmcr_tagheaderhigh,
{ "AlarmCRTagHeaderHigh", "pn_io.alarmcr_tagheaderhigh",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_alarmcr_tagheaderlow,
{ "AlarmCRTagHeaderLow", "pn_io.alarmcr_tagheaderlow",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_api_tree,
{ "API", "pn_io.api",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_module_tree,
{ "Module", "pn_io.module",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_submodule_tree,
{ "Submodule", "pn_io.submodule",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_io_data_object,
{ "IODataObject", "pn_io.io_data_object",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_io_cs,
{ "IOCS", "pn_io.io_cs",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_substitutionmode,
{ "Substitutionmode", "pn_io.substitutionmode",
FT_UINT16, BASE_HEX, VALS(pn_io_substitutionmode), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_IRData_uuid,
{ "IRDataUUID", "pn_io.IRData_uuid",
FT_GUID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ar_uuid,
{ "ARUUID", "pn_io.ar_uuid",
FT_GUID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_target_ar_uuid,
{ "TargetARUUID", "pn_io.target_ar_uuid",
FT_GUID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_api,
{ "API", "pn_io.api",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_slot_nr,
{ "SlotNumber", "pn_io.slot_nr",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_subslot_nr,
{ "SubslotNumber", "pn_io.subslot_nr",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_index,
{ "Index", "pn_io.index",
FT_UINT16, BASE_HEX, VALS(pn_io_index), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_seq_number,
{ "SeqNumber", "pn_io.seq_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_record_data_length,
{ "RecordDataLength", "pn_io.record_data_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_add_val1,
{ "AdditionalValue1", "pn_io.add_val1",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_add_val2,
{ "AdditionalValue2", "pn_io.add_val2",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_block_header,
{ "BlockHeader", "pn_io.block_header",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_block_type,
{ "BlockType", "pn_io.block_type",
FT_UINT16, BASE_HEX, VALS(pn_io_block_type), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_block_length,
{ "BlockLength", "pn_io.block_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_block_version_high,
{ "BlockVersionHigh", "pn_io.block_version_high",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_block_version_low,
{ "BlockVersionLow", "pn_io.block_version_low",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_sessionkey,
{ "SessionKey", "pn_io.session_key",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_control_command,
{ "ControlCommand", "pn_io.control_command",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_control_command_reserved,
{ "ControlBlockProperties.reserved", "pn_io.control_properties_reserved",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_control_command_prmend,
{ "PrmEnd", "pn_io.control_command.prmend",
FT_UINT16, BASE_DEC, NULL, 0x0001,
NULL, HFILL }
},
{ &hf_pn_io_control_command_applready,
{ "ApplicationReady", "pn_io.control_command.applready",
FT_UINT16, BASE_DEC, NULL, 0x0002,
NULL, HFILL }
},
{ &hf_pn_io_control_command_release,
{ "Release", "pn_io.control_command.release",
FT_UINT16, BASE_DEC, NULL, 0x0004,
NULL, HFILL }
},
{ &hf_pn_io_control_command_done,
{ "Done", "pn_io.control_command.done",
FT_UINT16, BASE_DEC, NULL, 0x0008,
NULL, HFILL }
},
{ &hf_pn_io_control_command_ready_for_companion,
{ "ReadyForCompanion", "pn_io.control_command.ready_for_companion",
FT_UINT16, BASE_DEC, NULL, 0x0010,
NULL, HFILL }
},
{ &hf_pn_io_control_command_ready_for_rt_class3,
{ "ReadyForRT Class 3", "pn_io.control_command.ready_for_rt_class3",
FT_UINT16, BASE_DEC, NULL, 0x0020,
NULL, HFILL }
},
{ &hf_pn_io_control_command_prmbegin,
{ "PrmBegin", "pn_io.control_command.prmbegin",
FT_UINT16, BASE_DEC, VALS(pn_io_control_properties_prmbegin_vals), 0x0040,
NULL, HFILL }
},
{ &hf_pn_io_control_command_reserved_7_15,
{ "ControlBlockProperties.reserved", "pn_io.control_properties_reserved_7_15",
FT_UINT16, BASE_HEX, NULL, 0x0FF80,
NULL, HFILL }
},
{ &hf_pn_io_control_block_properties,
{ "ControlBlockProperties", "pn_io.control_block_properties",
FT_UINT16, BASE_HEX, VALS(pn_io_control_properties_vals), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_control_block_properties_applready,
{ "ControlBlockProperties", "pn_io.control_block_properties.appl_ready",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_control_block_properties_applready0,
{ "ApplicationReady", "pn_io.control_block_properties.appl_ready0",
FT_UINT16, BASE_HEX, VALS(pn_io_control_properties_application_ready_vals), 0x0001,
NULL, HFILL }
},
#if 0
{ &hf_pn_io_AlarmSequenceNumber,
{ "AlarmSequenceNumber", "pn_io.AlarmSequenceNumber",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_pn_io_SubmoduleListEntries,
{ "NumberOfEntries", "pn_io.SubmoduleListEntries",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code,
{ "ErrorCode", "pn_io.error_code",
FT_UINT8, BASE_HEX, VALS(pn_io_error_code), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_decode,
{ "ErrorDecode", "pn_io.error_decode",
FT_UINT8, BASE_HEX, VALS(pn_io_error_decode), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code1,
{ "ErrorCode1", "pn_io.error_code1",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code1), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code1_pniorw,
{ "ErrorCode1", "pn_io.error_code1",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code1_pniorw), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pniorw,
{ "ErrorCode2 for PNIORW is user specified!", "pn_io.error_code2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code1_pnio,
{ "ErrorCode1", "pn_io.error_code1",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code1_pnio), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_1,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_1), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_2,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_2), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_3,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_3), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_4,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_4), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_5,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_5), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_6,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_6), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_7,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_7), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_8,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_8), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_20,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_20), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_21,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_21), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_22,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_22), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_23,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_23), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_40,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_40), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_61,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_61), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_62,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_62), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_63,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_63), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_64,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_64), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_65,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_65), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_66,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_66), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_70,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_70), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_71,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_71), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_72,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_72), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_73,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_73), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_74,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_74), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_75,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_75), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_76,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_76), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_77,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_77), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_253,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_253), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_code2_pnio_255,
{ "ErrorCode2", "pn_io.error_code2",
FT_UINT8, BASE_DEC, VALS(pn_io_error_code2_pnio_255), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_block,
{ "Block", "pn_io.block",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_alarm_type,
{ "AlarmType", "pn_io.alarm_type",
FT_UINT16, BASE_HEX, VALS(pn_io_alarm_type), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_alarm_specifier,
{ "AlarmSpecifier", "pn_io.alarm_specifier",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_alarm_specifier_sequence,
{ "SequenceNumber", "pn_io.alarm_specifier.sequence",
FT_UINT16, BASE_HEX, NULL, 0x07FF,
NULL, HFILL }
},
{ &hf_pn_io_alarm_specifier_channel,
{ "ChannelDiagnosis", "pn_io.alarm_specifier.channel",
FT_UINT16, BASE_HEX, NULL, 0x0800,
NULL, HFILL }
},
{ &hf_pn_io_alarm_specifier_manufacturer,
{ "ManufacturerSpecificDiagnosis", "pn_io.alarm_specifier.manufacturer",
FT_UINT16, BASE_HEX, NULL, 0x1000,
NULL, HFILL }
},
{ &hf_pn_io_alarm_specifier_submodule,
{ "SubmoduleDiagnosisState", "pn_io.alarm_specifier.submodule",
FT_UINT16, BASE_HEX, NULL, 0x2000,
NULL, HFILL }
},
{ &hf_pn_io_alarm_specifier_ardiagnosis,
{ "ARDiagnosisState", "pn_io.alarm_specifier.ardiagnosis",
FT_UINT16, BASE_HEX, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_pn_io_alarm_dst_endpoint,
{ "AlarmDstEndpoint", "pn_io.alarm_dst_endpoint",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_alarm_src_endpoint,
{ "AlarmSrcEndpoint", "pn_io.alarm_src_endpoint",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_pdu_type,
{ "PDUType", "pn_io.pdu_type",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_pdu_type_type,
{ "Type", "pn_io.pdu_type.type",
FT_UINT8, BASE_HEX, VALS(pn_io_pdu_type), 0x0F,
NULL, HFILL }
},
{ &hf_pn_io_pdu_type_version,
{ "Version", "pn_io.pdu_type.version",
FT_UINT8, BASE_HEX, NULL, 0xF0,
NULL, HFILL }
},
{ &hf_pn_io_add_flags,
{ "AddFlags", "pn_io.add_flags",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_window_size,
{ "WindowSize", "pn_io.window_size",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_pn_io_tack,
{ "TACK", "pn_io.tack",
FT_UINT8, BASE_HEX, NULL, 0xF0,
NULL, HFILL }
},
{ &hf_pn_io_send_seq_num,
{ "SendSeqNum", "pn_io.send_seq_num",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ack_seq_num,
{ "AckSeqNum", "pn_io.ack_seq_num",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_var_part_len,
{ "VarPartLen", "pn_io.var_part_len",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_module_ident_number,
{ "ModuleIdentNumber", "pn_io.module_ident_number",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_submodule_ident_number,
{ "SubmoduleIdentNumber", "pn_io.submodule_ident_number",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_number_of_modules,
{ "NumberOfModules", "pn_io.number_of_modules",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_module_properties,
{ "ModuleProperties", "pn_io.module_properties",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_module_state,
{ "ModuleState", "pn_io.module_state",
FT_UINT16, BASE_HEX, VALS(pn_io_module_state), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_number_of_submodules,
{ "NumberOfSubmodules", "pn_io.number_of_submodules",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_submodule_properties,
{ "SubmoduleProperties", "pn_io.submodule_properties",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_submodule_properties_type,
{ "Type", "pn_io.submodule_properties.type",
FT_UINT16, BASE_HEX, VALS(pn_io_submodule_properties_type), 0x0003,
NULL, HFILL }
},
{ &hf_pn_io_submodule_properties_shared_input,
{ "SharedInput", "pn_io.submodule_properties.shared_input",
FT_UINT16, BASE_HEX, VALS(pn_io_submodule_properties_shared_input), 0x0004,
NULL, HFILL }
},
{ &hf_pn_io_submodule_properties_reduce_input_submodule_data_length,
{ "ReduceInputSubmoduleDataLength", "pn_io.submodule_properties.reduce_input_submodule_data_length",
FT_UINT16, BASE_HEX, VALS(pn_io_submodule_properties_reduce_input_submodule_data_length), 0x0008,
NULL, HFILL }
},
{ &hf_pn_io_submodule_properties_reduce_output_submodule_data_length,
{ "ReduceOutputSubmoduleDataLength", "pn_io.submodule_properties.reduce_output_submodule_data_length",
FT_UINT16, BASE_HEX, VALS(pn_io_submodule_properties_reduce_output_submodule_data_length), 0x0010,
NULL, HFILL }
},
{ &hf_pn_io_submodule_properties_discard_ioxs,
{ "DiscardIOXS", "pn_io.submodule_properties.discard_ioxs",
FT_UINT16, BASE_HEX, VALS(pn_io_submodule_properties_discard_ioxs), 0x0020,
NULL, HFILL }
},
{ &hf_pn_io_submodule_properties_reserved,
{ "Reserved", "pn_io.submodule_properties.reserved",
FT_UINT16, BASE_HEX, NULL, 0xFFC0,
NULL, HFILL }
},
{ &hf_pn_io_submodule_state,
{ "SubmoduleState", "pn_io.submodule_state",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_submodule_state_format_indicator,
{ "FormatIndicator", "pn_io.submodule_state.format_indicator",
FT_UINT16, BASE_HEX, VALS(pn_io_submodule_state_format_indicator), 0x8000,
NULL, HFILL }
},
{ &hf_pn_io_submodule_state_add_info,
{ "AddInfo", "pn_io.submodule_state.add_info",
FT_UINT16, BASE_HEX, VALS(pn_io_submodule_state_add_info), 0x0007,
NULL, HFILL }
},
{ &hf_pn_io_submodule_state_qualified_info,
{ "QualifiedInfo", "pn_io.submodule_state.qualified_info",
FT_UINT16, BASE_HEX, VALS(pn_io_submodule_state_qualified_info), 0x0008,
NULL, HFILL }
},
{ &hf_pn_io_submodule_state_maintenance_required,
{ "MaintenanceRequired", "pn_io.submodule_state.maintenance_required",
FT_UINT16, BASE_HEX, VALS(pn_io_submodule_state_maintenance_required), 0x0010,
NULL, HFILL }
},
{ &hf_pn_io_submodule_state_maintenance_demanded,
{ "MaintenanceDemanded", "pn_io.submodule_state.maintenance_demanded",
FT_UINT16, BASE_HEX, VALS(pn_io_submodule_state_maintenance_demanded), 0x0020,
NULL, HFILL }
},
{ &hf_pn_io_submodule_state_diag_info,
{ "DiagInfo", "pn_io.submodule_state.diag_info",
FT_UINT16, BASE_HEX, VALS(pn_io_submodule_state_diag_info), 0x0040,
NULL, HFILL }
},
{ &hf_pn_io_submodule_state_ar_info,
{ "ARInfo", "pn_io.submodule_state.ar_info",
FT_UINT16, BASE_HEX, VALS(pn_io_submodule_state_ar_info), 0x0780,
NULL, HFILL }
},
{ &hf_pn_io_submodule_state_ident_info,
{ "IdentInfo", "pn_io.submodule_state.ident_info",
FT_UINT16, BASE_HEX, VALS(pn_io_submodule_state_ident_info), 0x7800,
NULL, HFILL }
},
{ &hf_pn_io_submodule_state_detail,
{ "Detail", "pn_io.submodule_state.detail",
FT_UINT16, BASE_HEX, VALS(pn_io_submodule_state_detail), 0x7FFF,
NULL, HFILL }
},
{ &hf_pn_io_data_description_tree,
{ "DataDescription", "pn_io.data_description",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_data_description,
{ "DataDescription", "pn_io.data_description",
FT_UINT16, BASE_HEX, VALS(pn_io_data_description), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_submodule_data_length,
{ "SubmoduleDataLength", "pn_io.submodule_data_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_length_iocs,
{ "LengthIOCS", "pn_io.length_iocs",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_length_iops,
{ "LengthIOPS", "pn_io.length_iops",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_iocs,
{ "IOCS", "pn_io.ioxs",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_iops,
{ "IOPS", "pn_io.ioxs",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ioxs,
{ "IOxS", "pn_io.ioxs",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ioxs_extension,
{ "Extension (1:another IOxS follows/0:no IOxS follows)", "pn_io.ioxs.extension",
FT_UINT8, BASE_HEX, NULL, 0x01,
NULL, HFILL }
},
{ &hf_pn_io_ioxs_res14,
{ "Reserved (should be zero)", "pn_io.ioxs.res14",
FT_UINT8, BASE_HEX, NULL, 0x1E,
NULL, HFILL }
},
{ &hf_pn_io_ioxs_instance,
{ "Instance (only valid, if DataState is bad)",
"pn_io.ioxs.instance", FT_UINT8, BASE_HEX, VALS(pn_io_ioxs),
0x60, NULL, HFILL }
},
{ &hf_pn_io_ioxs_datastate,
{ "DataState (1:good/0:bad)", "pn_io.ioxs.datastate",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL }
},
{ &hf_pn_io_address_resolution_properties,
{ "AddressResolutionProperties", "pn_io.address_resolution_properties",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mci_timeout_factor,
{ "MCITimeoutFactor", "pn_io.mci_timeout_factor",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_provider_station_name,
{ "ProviderStationName", "pn_io.provider_station_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_user_structure_identifier,
{ "UserStructureIdentifier", "pn_io.user_structure_identifier",
FT_UINT16, BASE_HEX, VALS(pn_io_user_structure_identifier), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ar_properties_reserved_1,
{ "Reserved_1", "pn_io.ar_properties.reserved_1",
FT_UINT32, BASE_HEX, NULL, 0x000000E0,
NULL, HFILL }},
{ &hf_pn_io_ar_properties_device_access,
{ "DeviceAccess", "pn_io.ar_properties.device_access",
FT_UINT32, BASE_HEX, VALS(pn_io_arproperties_DeviceAccess), 0x00000100,
NULL, HFILL }},
{ &hf_pn_io_subframe_data,
{ "SubFrameData", "pn_io.subframe_data",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_subframe_reserved2,
{ "Reserved1", "pn_io.subframe_data.reserved2",
FT_UINT32, BASE_HEX, NULL, 0xFFFF0000,
NULL, HFILL }
},
{ &hf_pn_io_subframe_data_length,
{ "DataLength", "pn_io.subframe_data.data_length",
FT_UINT32, BASE_HEX, NULL, 0x0000FF00,
NULL, HFILL }
},
{ &hf_pn_io_subframe_reserved1,
{ "Reserved1", "pn_io.subframe_data.reserved1",
FT_UINT32, BASE_HEX, NULL, 0x00000080,
NULL, HFILL }
},
{ &hf_pn_io_subframe_data_position,
{ "DataPosition", "pn_io.subframe_data.position",
FT_UINT32, BASE_HEX, NULL, 0x0000007F,
NULL, HFILL }
},
{ &hf_pn_io_subframe_data_reserved1,
{ "Reserved1", "pn_io.subframe_data.reserved_1",
FT_UINT32, BASE_HEX, NULL, 0x00000080,
NULL, HFILL }
},
{ &hf_pn_io_subframe_data_reserved2,
{ "Reserved1", "pn_io.subframe_data.reserved_2",
FT_UINT32, BASE_HEX, NULL, 0xFFFF0000,
NULL, HFILL }
},
{ &hf_pn_io_channel_number,
{ "ChannelNumber", "pn_io.channel_number",
FT_UINT16, BASE_HEX, VALS(pn_io_channel_number), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_channel_properties,
{ "ChannelProperties", "pn_io.channel_properties",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_channel_properties_type,
{ "Type", "pn_io.channel_properties.type",
FT_UINT16, BASE_HEX, VALS(pn_io_channel_properties_type), 0x00FF,
NULL, HFILL }
},
{ &hf_pn_io_channel_properties_accumulative,
{ "Accumulative", "pn_io.channel_properties.accumulative",
FT_UINT16, BASE_HEX, NULL, 0x0100,
NULL, HFILL }
},
{ &hf_pn_io_NumberOfSubframeBlocks,
{ "NumberOfSubframeBlocks", "pn_io.NumberOfSubframeBlocks",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_channel_properties_maintenance,
{ "Maintenance", "pn_io.channel_properties.maintenance",
FT_UINT16, BASE_HEX, VALS(pn_io_channel_properties_maintenance), 0x0600,
NULL, HFILL }
},
{ &hf_pn_io_channel_properties_specifier,
{ "Specifier", "pn_io.channel_properties.specifier",
FT_UINT16, BASE_HEX, VALS(pn_io_channel_properties_specifier), 0x1800,
NULL, HFILL }
},
{ &hf_pn_io_channel_properties_direction,
{ "Direction", "pn_io.channel_properties.direction",
FT_UINT16, BASE_HEX, VALS(pn_io_channel_properties_direction), 0xE000,
NULL, HFILL }
},
{ &hf_pn_io_channel_error_type,
{ "ChannelErrorType", "pn_io.channel_error_type",
FT_UINT16, BASE_HEX, VALS(pn_io_channel_error_type), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ext_channel_error_type0,
{ "ExtChannelErrorType", "pn_io.ext_channel_error_type0",
FT_UINT16, BASE_HEX, VALS(pn_io_ext_channel_error_type0), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ext_channel_error_type0x8000,
{ "ExtChannelErrorType", "pn_io.ext_channel_error_type0800",
FT_UINT16, BASE_HEX, VALS(pn_io_ext_channel_error_type0x8000), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ext_channel_error_type0x8001,
{ "ExtChannelErrorType", "pn_io.ext_channel_error_type8001",
FT_UINT16, BASE_HEX, VALS(pn_io_ext_channel_error_type0x8001), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ext_channel_error_type0x8002,
{ "ExtChannelErrorType", "pn_io.ext_channel_error_type8002",
FT_UINT16, BASE_HEX, VALS(pn_io_ext_channel_error_type0x8002), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ext_channel_error_type0x8003,
{ "ExtChannelErrorType", "pn_io.ext_channel_error_type8003",
FT_UINT16, BASE_HEX, VALS(pn_io_ext_channel_error_type0x8003), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ext_channel_error_type0x8004,
{ "ExtChannelErrorType", "pn_io.ext_channel_error_type8004",
FT_UINT16, BASE_HEX, VALS(pn_io_ext_channel_error_type0x8004), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ext_channel_error_type0x8005,
{ "ExtChannelErrorType", "pn_io.ext_channel_error_type8005",
FT_UINT16, BASE_HEX, VALS(pn_io_ext_channel_error_type0x8005), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ext_channel_error_type0x8007,
{ "ExtChannelErrorType", "pn_io.ext_channel_error_type8007",
FT_UINT16, BASE_HEX, VALS(pn_io_ext_channel_error_type0x8007), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ext_channel_error_type0x8008,
{ "ExtChannelErrorType", "pn_io.ext_channel_error_type8008",
FT_UINT16, BASE_HEX, VALS(pn_io_ext_channel_error_type0x8008), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ext_channel_error_type0x800A,
{ "ExtChannelErrorType", "pn_io.ext_channel_error_type800A",
FT_UINT16, BASE_HEX, VALS(pn_io_ext_channel_error_type0x800A), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ext_channel_error_type0x800B,
{ "ExtChannelErrorType", "pn_io.ext_channel_error_type800B",
FT_UINT16, BASE_HEX, VALS(pn_io_ext_channel_error_type0x800B), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ext_channel_error_type0x800C,
{ "ExtChannelErrorType", "pn_io.ext_channel_error_type800C",
FT_UINT16, BASE_HEX, VALS(pn_io_ext_channel_error_type0x800C), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ext_channel_error_type,
{ "ExtChannelErrorType", "pn_io.ext_channel_error_type",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ext_channel_add_value,
{ "ExtChannelAddValue", "pn_io.ext_channel_add_value",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ptcp_subdomain_id,
{ "PTCPSubdomainID", "pn_io.ptcp_subdomain_id",
FT_GUID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ir_data_id,
{ "IRDataID", "pn_io.ir_data_id",
FT_GUID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_max_bridge_delay,
{ "MaxBridgeDelay", "pn_io.max_bridge_delay",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_number_of_ports,
{ "NumberOfPorts", "pn_io.number_of_ports",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_max_port_tx_delay,
{ "MaxPortTxDelay", "pn_io.max_port_tx_delay",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_max_port_rx_delay,
{ "MaxPortRxDelay", "pn_io.max_port_rx_delay",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_max_line_rx_delay,
{ "MaxLineRxDelay", "pn_io.max_line_rx_delay",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_yellowtime,
{ "YellowTime", "pn_io.yellowtime",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_reserved_interval_begin,
{ "ReservedIntervalBegin", "pn_io.reserved_interval_begin",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_reserved_interval_end,
{ "ReservedIntervalEnd", "pn_io.reserved_interval_end",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_pllwindow,
{ "PLLWindow", "pn_io.pllwindow",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_sync_send_factor,
{ "SyncSendFactor", "pn_io.sync_send_factor",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_sync_properties,
{ "SyncProperties", "pn_io.sync_properties",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_sync_frame_address,
{ "SyncFrameAddress", "pn_io.sync_frame_address",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ptcp_timeout_factor,
{ "PTCPTimeoutFactor", "pn_io.ptcp_timeout_factor",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ptcp_takeover_timeout_factor,
{ "PTCPTakeoverTimeoutFactor", "pn_io.ptcp_takeover_timeout_factor",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ptcp_master_startup_time,
{ "PTCPMasterStartupTime", "pn_io.ptcp_master_startup_time",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ptcp_master_priority_1,
{ "PTCP_MasterPriority1", "pn_io.ptcp_master_priority_1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ptcp_master_priority_2,
{ "PTCP_MasterPriority2", "pn_io.ptcp_master_priority_2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ptcp_length_subdomain_name,
{ "PTCPLengthSubdomainName", "pn_io.ptcp_length_subdomain_name",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ptcp_subdomain_name,
{ "PTCPSubdomainName", "pn_io.ptcp_subdomain_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_MultipleInterfaceMode_NameOfDevice,
{ "MultipleInterfaceMode.NameOfDevice", "pn_io.MultipleInterfaceMode_NameOfDevice", FT_UINT32, BASE_HEX, VALS(pn_io_MultipleInterfaceMode_NameOfDevice), 0x01, NULL, HFILL }},
{ &hf_pn_io_MultipleInterfaceMode_reserved_1,
{ "MultipleInterfaceMode.Reserved_1", "pn_io.MultipleInterfaceMode_reserved_1", FT_UINT32, BASE_HEX, NULL, 0xFFFE, NULL, HFILL }},
{ &hf_pn_io_MultipleInterfaceMode_reserved_2,
{ "MultipleInterfaceMode.Reserved_2", "pn_io.MultipleInterfaceMode_reserved_2", FT_UINT32, BASE_HEX, NULL, 0xFFFF0000, NULL, HFILL }},
{ &hf_pn_io_pdportstatistic_ifInOctets,
{ "ifInOctets", "pn_io.ifInOctets",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_pdportstatistic_ifOutOctets,
{ "ifOutOctets", "pn_io.ifOutOctets",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_pdportstatistic_ifInDiscards,
{ "ifInDiscards", "pn_io.ifInDiscards",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_pdportstatistic_ifOutDiscards,
{ "ifOutDiscards", "pn_io.ifOutDiscards",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_pdportstatistic_ifInErrors,
{ "ifInErrors", "pn_io.ifInErrors",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_pdportstatistic_ifOutErrors,
{ "ifOutErrors", "pn_io.ifOutErrors",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_domain_boundary,
{ "DomainBoundary", "pn_io.domain_boundary",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_domain_boundary_ingress,
{ "DomainBoundaryIngress", "pn_io.domain_boundary.ingress",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_domain_boundary_egress,
{ "DomainBoundaryEgress", "pn_io.domain_boundary.egress",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_multicast_boundary,
{ "MulticastBoundary", "pn_io.multicast_boundary",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_adjust_properties,
{ "AdjustProperties", "pn_io.adjust_properties",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_PreambleLength,
{ "Preamble Length", "pn_io.preamble_length",
FT_UINT16, BASE_HEX, VALS(pn_io_preamble_length), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mau_type,
{ "MAUType", "pn_io.mau_type",
FT_UINT16, BASE_HEX, VALS(pn_io_mau_type), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mau_type_mode,
{ "MAUTypeMode", "pn_io.mau_type_mode",
FT_UINT16, BASE_HEX, VALS(pn_io_mau_type_mode), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_port_state,
{ "PortState", "pn_io.port_state",
FT_UINT16, BASE_HEX, VALS(pn_io_port_state), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_line_delay,
{ "LineDelay", "pn_io.line_delay",
FT_UINT32, BASE_DEC, NULL, 0x0,
"LineDelay in nanoseconds", HFILL }
},
{ &hf_pn_io_number_of_peers,
{ "NumberOfPeers", "pn_io.number_of_peers",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_length_peer_port_id,
{ "LengthPeerPortID", "pn_io.length_peer_port_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_peer_port_id,
{ "PeerPortID", "pn_io.peer_port_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_length_peer_chassis_id,
{ "LengthPeerChassisID", "pn_io.length_peer_chassis_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_peer_chassis_id,
{ "PeerChassisID", "pn_io.peer_chassis_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_length_own_chassis_id,
{ "LengthOwnChassisID", "pn_io.length_own_chassis_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_own_chassis_id,
{ "OwnChassisID", "pn_io.own_chassis_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_length_own_port_id,
{ "LengthOwnPortID", "pn_io.length_own_port_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_own_port_id,
{ "OwnPortID", "pn_io.own_port_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_peer_macadd,
{ "PeerMACAddress", "pn_io.peer_macadd",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_macadd,
{ "MACAddress", "pn_io.macadd",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_media_type,
{ "MediaType", "pn_io.media_type",
FT_UINT32, BASE_HEX, VALS(pn_io_media_type), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ethertype,
{ "Ethertype", "pn_io.ethertype",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_rx_port,
{ "RXPort", "pn_io.rx_port",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_frame_details,
{ "FrameDetails", "pn_io.frame_details",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_frame_details_sync_frame,
{ "SyncFrame", "pn_io.frame_details.sync_frame",
FT_UINT8, BASE_HEX, VALS(pn_io_frame_details_sync_master_vals), 0x03,
NULL, HFILL }
},
{ &hf_pn_io_frame_details_meaning_frame_send_offset,
{ "Meaning", "pn_io.frame_details.meaning_frame_send_offset",
FT_UINT8, BASE_HEX, VALS(pn_io_frame_details_meaning_frame_send_offset_vals), 0x0C,
NULL, HFILL }
},
{ &hf_pn_io_frame_details_reserved,
{ "Reserved", "pn_io.frame_details.reserved",
FT_UINT8, BASE_HEX, NULL, 0xF0,
NULL, HFILL }
},
{ &hf_pn_io_nr_of_tx_port_groups,
{ "NumberOfTxPortGroups", "pn_io.nr_of_tx_port_groups",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_TxPortGroupProperties,
{ "TxPortGroupProperties", "pn_io.tx_port_properties",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_TxPortGroupProperties_bit0,
{ "TxPortLocal", "pn_io.tx_port_properties_bit_0",
FT_UINT8, BASE_HEX, VALS(pn_io_txgroup_state), 0x01,
NULL, HFILL }
},
{ &hf_pn_io_TxPortGroupProperties_bit1,
{ "TxPort_1", "pn_io.tx_port_properties_bit_1",
FT_UINT8, BASE_HEX, VALS(pn_io_txgroup_state), 0x02,
NULL, HFILL }
},
{ &hf_pn_io_TxPortGroupProperties_bit2,
{ "TxPort_2", "pn_io.tx_port_properties_bit_2",
FT_UINT8, BASE_HEX, VALS(pn_io_txgroup_state), 0x04,
NULL, HFILL }
},
{ &hf_pn_io_TxPortGroupProperties_bit3,
{ "TxPort_3", "pn_io.tx_port_properties_bit_3",
FT_UINT8, BASE_HEX, VALS(pn_io_txgroup_state), 0x08,
NULL, HFILL }
},
{ &hf_pn_io_TxPortGroupProperties_bit4,
{ "TxPort_4", "pn_io.tx_port_properties_bit_4",
FT_UINT8, BASE_HEX, VALS(pn_io_txgroup_state), 0x10,
NULL, HFILL }
},
{ &hf_pn_io_TxPortGroupProperties_bit5,
{ "TxPort_5", "pn_io.tx_port_properties_bit_5",
FT_UINT8, BASE_HEX, VALS(pn_io_txgroup_state), 0x20,
NULL, HFILL }
},
{ &hf_pn_io_TxPortGroupProperties_bit6,
{ "TxPort_6", "pn_io.tx_port_properties_bit_6",
FT_UINT8, BASE_HEX, VALS(pn_io_txgroup_state), 0x40,
NULL, HFILL }
},
{ &hf_pn_io_TxPortGroupProperties_bit7,
{ "TxPort_7", "pn_io.tx_port_properties_bit_7",
FT_UINT8, BASE_HEX, VALS(pn_io_txgroup_state), 0x80,
NULL, HFILL }
},
{ &hf_pn_io_start_of_red_frame_id,
{ "StartOfRedFrameID", "pn_io.start_of_red_frame_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_end_of_red_frame_id,
{ "EndOfRedFrameID", "pn_io.end_of_red_frame_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ir_begin_end_port,
{ "Port", "pn_io.ir_begin_end_port",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_number_of_assignments,
{ "NumberOfAssignments", "pn_io.number_of_assignments",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_number_of_phases,
{ "NumberOfPhases", "pn_io.number_of_phases",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_red_orange_period_begin_tx,
{ "RedOrangePeriodBegin [TX]", "pn_io.red_orange_period_begin_tx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_orange_period_begin_tx,
{ "OrangePeriodBegin [TX]", "pn_io.orange_period_begin_tx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_green_period_begin_tx,
{ "GreenPeriodBegin [TX]", "pn_io.green_period_begin_tx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_red_orange_period_begin_rx,
{ "RedOrangePeriodBegin [RX]", "pn_io.red_orange_period_begin_rx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_orange_period_begin_rx,
{ "OrangePeriodBegin [RX]", "pn_io.orange_period_begin_rx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_green_period_begin_rx,
{ "GreenPeriodBegin [RX]", "pn_io.green_period_begin_rx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_pn_io_tx_phase_assignment,
{ "TXPhaseAssignment", "pn_io.tx_phase_assignment",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_pn_ir_tx_phase_assignment,
{ "TXPhaseAssignment", "pn_io.tx_phase_assignment_sub",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_tx_phase_assignment_begin_value,
{ "AssignedValueForReservedBegin", "pn_io.tx_phase_assignment_begin_value",
FT_UINT16, BASE_DEC, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_pn_io_tx_phase_assignment_orange_begin,
{ "AssignedValueForOrangeBegin", "pn_io.tx_phase_assignment_orange_begin",
FT_UINT16, BASE_DEC, NULL, 0x0F0,
NULL, HFILL }
},
{ &hf_pn_io_tx_phase_assignment_end_reserved,
{ "AssignedValueForReservedEnd", "pn_io.tx_phase_assignment_end_reserved",
FT_UINT16, BASE_DEC, NULL, 0x0F00,
NULL, HFILL }
},
{ &hf_pn_io_tx_phase_assignment_reserved,
{ "Reserved should be 0", "pn_io.tx_phase_assignment_reserved",
FT_UINT16, BASE_DEC, NULL, 0x0F000,
NULL, HFILL }
},
{ &hf_pn_ir_rx_phase_assignment,
{ "RXPhaseAssignment", "pn_io.rx_phase_assignment_sub",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_pn_io_rx_phase_assignment,
{ "RXPhaseAssignment", "pn_io.rx_phase_assignment",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_pn_io_slot,
{ "Slot", "pn_io.slot",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_subslot,
{ "Subslot", "pn_io.subslot",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_number_of_slots,
{ "NumberOfSlots", "pn_io.number_of_slots",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_number_of_subslots,
{ "NumberOfSubslots", "pn_io.number_of_subslots",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_pn_io_maintenance_required_drop_budget,
{ "MaintenanceRequiredDropBudget", "pn_io.maintenance_required_drop_budget",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#endif
#if 0
{ &hf_pn_io_maintenance_demanded_drop_budget,
{ "MaintenanceDemandedDropBudget", "pn_io.maintenance_demanded_drop_budget",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#endif
#if 0
{ &hf_pn_io_error_drop_budget,
{ "ErrorDropBudget", "pn_io.error_drop_budget",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_pn_io_maintenance_required_power_budget,
{ "MaintenanceRequiredPowerBudget", "pn_io.maintenance_required_power_budget",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_maintenance_demanded_power_budget,
{ "MaintenanceDemandedPowerBudget", "pn_io.maintenance_demanded_power_budget",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_error_power_budget,
{ "ErrorPowerBudget", "pn_io.error_power_budget",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_fiber_optic_type,
{ "FiberOpticType", "pn_io.fiber_optic_type",
FT_UINT32, BASE_HEX, VALS(pn_io_fiber_optic_type), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_fiber_optic_cable_type,
{ "FiberOpticCableType", "pn_io.fiber_optic_cable_type",
FT_UINT32, BASE_HEX, VALS(pn_io_fiber_optic_cable_type), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_controller_appl_cycle_factor,
{ "ControllerApplicationCycleFactor", "pn_io.controller_appl_cycle_factor",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_time_data_cycle,
{ "TimeDataCycle", "pn_io.time_data_cycle",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_time_io_input,
{ "TimeIOInput", "pn_io.time_io_input",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_time_io_output,
{ "TimeIOOutput", "pn_io.time_io_output",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_time_io_input_valid,
{ "TimeIOInputValid", "pn_io.time_io_input_valid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_time_io_output_valid,
{ "TimeIOOutputValid", "pn_io.time_io_output_valid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_maintenance_status,
{ "MaintenanceStatus", "pn_io.maintenance_status",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_maintenance_status_required,
{ "Required", "pn_io.maintenance_status_required",
FT_UINT32, BASE_HEX, NULL, 0x0001,
NULL, HFILL }
},
{ &hf_pn_io_maintenance_status_demanded,
{ "Demanded", "pn_io.maintenance_status_demanded",
FT_UINT32, BASE_HEX, NULL, 0x0002,
NULL, HFILL }
},
{ &hf_pn_io_vendor_id_high,
{ "VendorIDHigh", "pn_io.vendor_id_high",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_vendor_id_low,
{ "VendorIDLow", "pn_io.vendor_id_low",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_vendor_block_type,
{ "VendorBlockType", "pn_io.vendor_block_type",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_order_id,
{ "OrderID", "pn_io.order_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_serial_number,
{ "IMSerialNumber", "pn_io.im_serial_number",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_hardware_revision,
{ "IMHardwareRevision", "pn_io.im_hardware_revision",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_revision_prefix,
{ "IMRevisionPrefix", "pn_io.im_revision_prefix",
FT_UINT8, BASE_HEX, VALS(pn_io_im_revision_prefix_vals), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_sw_revision_functional_enhancement,
{ "IMSWRevisionFunctionalEnhancement", "pn_io.im_sw_revision_functional_enhancement",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_revision_bugfix,
{ "IM_SWRevisionBugFix", "pn_io.im_revision_bugfix",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_sw_revision_internal_change,
{ "IMSWRevisionInternalChange", "pn_io.im_sw_revision_internal_change",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_revision_counter,
{ "IMRevisionCounter", "pn_io.im_revision_counter",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_profile_id,
{ "IMProfileID", "pn_io.im_profile_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_profile_specific_type,
{ "IMProfileSpecificType", "pn_io.im_profile_specific_type",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_version_major,
{ "IMVersionMajor", "pn_io.im_version_major",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_version_minor,
{ "IMVersionMinor", "pn_io.im_version_minor",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_supported,
{ "IM_Supported", "pn_io.im_supported",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_number_of_ars,
{ "NumberOfARs", "pn_io.number_of_ars",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_cycle_counter,
{ "CycleCounter", "pn_io.cycle_counter",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_data_status,
{ "DataStatus", "pn_io.ds",
FT_UINT8, BASE_HEX, 0, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_data_status_res67,
{ "Reserved (should be zero)", "pn_io.ds_res67",
FT_UINT8, BASE_HEX, 0, 0xc0,
NULL, HFILL }
},
{ &hf_pn_io_data_status_ok,
{ "StationProblemIndicator (1:Ok/0:Problem)", "pn_io.ds_ok",
FT_UINT8, BASE_HEX, 0, 0x20,
NULL, HFILL }
},
{ &hf_pn_io_data_status_operate,
{ "ProviderState (1:Run/0:Stop)", "pn_io.ds_operate",
FT_UINT8, BASE_HEX, 0, 0x10,
NULL, HFILL }
},
{ &hf_pn_io_data_status_res3,
{ "Reserved (should be zero)", "pn_io.ds_res3",
FT_UINT8, BASE_HEX, 0, 0x08,
NULL, HFILL }
},
{ &hf_pn_io_data_status_valid,
{ "DataValid (1:Valid/0:Invalid)", "pn_io.ds_valid",
FT_UINT8, BASE_HEX, 0, 0x04,
NULL, HFILL }
},
{ &hf_pn_io_data_status_res1,
{ "primary AR of a given AR-set is present (0:One/ 1:None)", "pn_io.ds_res1",
FT_UINT8, BASE_HEX, 0, 0x02,
NULL, HFILL }
},
{ &hf_pn_io_data_status_primary,
{ "State (1:Primary/0:Backup)", "pn_io.ds_primary",
FT_UINT8, BASE_HEX, 0, 0x01,
NULL, HFILL }
},
{ &hf_pn_io_transfer_status,
{ "TransferStatus", "pn_io.transfer_status",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_actual_local_time_stamp,
{ "ActualLocalTimeStamp", "pn_io.actual_local_time_stamp",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_local_time_stamp,
{ "LocalTimeStamp", "pn_io.local_time_stamp",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_number_of_log_entries,
{ "NumberOfLogEntries", "pn_io.number_of_log_entries",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_entry_detail,
{ "EntryDetail", "pn_io.entry_detail",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ip_address,
{ "IPAddress", "pn_io.ip_address",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_subnetmask,
{ "Subnetmask", "pn_io.subnetmask",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_standard_gateway,
{ "StandardGateway", "pn_io.standard_gateway",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mrp_domain_uuid,
{ "MRP_DomainUUID", "pn_io.mrp_domain_uuid",
FT_GUID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mrp_role,
{ "MRP_Role", "pn_io.mrp_role",
FT_UINT16, BASE_HEX, VALS(pn_io_mrp_role_vals), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mrp_length_domain_name,
{ "MRP_LengthDomainName", "pn_io.mrp_length_domain_name",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mrp_domain_name,
{ "MRP_DomainName", "pn_io.mrp_domain_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mrp_instances,
{ "NumberOfMrpInstances", "pn_io.mrp_Number_MrpInstances",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mrp_instance,
{ "Mrp_Instance", "pn_io.mrp_MrpInstance",
FT_UINT8, BASE_DEC, VALS(pn_io_mrp_instance_no), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mrp_prio,
{ "MRP_Prio", "pn_io.mrp_prio",
FT_UINT16, BASE_HEX, VALS(pn_io_mrp_prio_vals), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mrp_topchgt,
{ "MRP_TOPchgT", "pn_io.mrp_topchgt",
FT_UINT16, BASE_DEC, NULL, 0x0,
"time base 10ms", HFILL }
},
{ &hf_pn_io_mrp_topnrmax,
{ "MRP_TOPNRmax", "pn_io.mrp_topnrmax",
FT_UINT16, BASE_DEC, NULL, 0x0,
"number of iterations", HFILL }
},
{ &hf_pn_io_mrp_tstshortt,
{ "MRP_TSTshortT", "pn_io.mrp_tstshortt",
FT_UINT16, BASE_DEC, NULL, 0x0,
"time base 1 ms", HFILL }
},
{ &hf_pn_io_mrp_tstdefaultt,
{ "MRP_TSTdefaultT", "pn_io.mrp_tstdefaultt",
FT_UINT16, BASE_DEC, NULL, 0x0,
"time base 1ms", HFILL }
},
{ &hf_pn_io_mrp_tstnrmax,
{ "MRP_TSTNRmax", "pn_io.mrp_tstnrmax",
FT_UINT16, BASE_DEC, NULL, 0x0,
"number of outstanding test indications causes ring failure", HFILL }
},
{ &hf_pn_io_mrp_check,
{ "MRP_Check", "pn_io.mrp_check",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mrp_check_mrm,
{ "MRP_Check.MediaRedundancyManager", "pn_io.mrp_check.mrm",
FT_UINT32, BASE_HEX, VALS(pn_io_mrp_mrm_on), 0x01,
NULL, HFILL }
},
{ &hf_pn_io_mrp_check_mrpdomain,
{ "MRP_Check.MRP_DomainUUID", "pn_io.mrp_check.domainUUID",
FT_UINT32, BASE_HEX, VALS(pn_io_mrp_checkUUID), 0x02,
NULL, HFILL }
},
{ &hf_pn_io_mrp_check_reserved_1,
{ "MRP_Check.reserved_1", "pn_io.mrp_check_reserved_1",
FT_UINT32, BASE_HEX, NULL, 0x0FFFFFC,
NULL, HFILL }
},
{ &hf_pn_io_mrp_check_reserved_2,
{ "MRP_Check.reserved_2", "pn_io.mrp_check_reserved_2",
FT_UINT32, BASE_HEX, NULL, 0x0FF000000,
NULL, HFILL }
},
{ &hf_pn_io_mrp_rtmode,
{ "MRP_RTMode", "pn_io.mrp_rtmode",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mrp_rtmode_rtclass12,
{ "RTClass1_2", "pn_io.mrp_rtmode.class1_2",
FT_UINT32, BASE_HEX, VALS(pn_io_mrp_rtmode_rtclass12_vals), 0x00000001,
NULL, HFILL }
},
{ &hf_pn_io_mrp_rtmode_rtclass3,
{ "RTClass1_3", "pn_io.mrp_rtmode.class3",
FT_UINT32, BASE_HEX, VALS(pn_io_mrp_rtmode_rtclass3_vals), 0x00000002,
NULL, HFILL }
},
{ &hf_pn_io_mrp_rtmode_reserved1,
{ "Reserved_1", "pn_io.mrp_rtmode.reserved_1",
FT_UINT32, BASE_HEX, NULL, 0x00fffffc,
NULL, HFILL }
},
{ &hf_pn_io_mrp_rtmode_reserved2,
{ "Reserved_2", "pn_io.mrp_rtmode.reserved_2",
FT_UINT32, BASE_HEX, NULL, 0xff000000,
NULL, HFILL }
},
{ &hf_pn_io_mrp_lnkdownt,
{ "MRP_LNKdownT", "pn_io.mrp_lnkdownt",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Link down Interval in ms", HFILL }
},
{ &hf_pn_io_mrp_lnkupt,
{ "MRP_LNKupT", "pn_io.mrp_lnkupt",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Link up Interval in ms", HFILL }
},
{ &hf_pn_io_mrp_lnknrmax,
{ "MRP_LNKNRmax", "pn_io.mrp_lnknrmax",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mrp_version,
{ "MRP_Version", "pn_io.mrp_version",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_substitute_active_flag,
{ "SubstituteActiveFlag", "pn_io.substitute_active_flag",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_length_data,
{ "LengthData", "pn_io.length_data",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mrp_ring_state,
{ "MRP_RingState", "pn_io.mrp_ring_state",
FT_UINT16, BASE_HEX, VALS(pn_io_mrp_ring_state_vals), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_mrp_rt_state,
{ "MRP_RTState", "pn_io.mrp_rt_state",
FT_UINT16, BASE_HEX, VALS(pn_io_mrp_rt_state_vals), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_tag_function,
{ "IM_Tag_Function", "pn_io.im_tag_function",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_tag_location,
{ "IM_Tag_Location", "pn_io.im_tag_location",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_date,
{ "IM_Date", "pn_io.im_date",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_im_descriptor,
{ "IM_Descriptor", "pn_io.im_descriptor",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_fs_hello_mode,
{ "FSHelloMode", "pn_io.fs_hello_mode",
FT_UINT32, BASE_HEX, VALS(pn_io_fs_hello_mode_vals), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_fs_hello_interval,
{ "FSHelloInterval", "pn_io.fs_hello_interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
"ms before conveying a second DCP_Hello.req", HFILL }
},
{ &hf_pn_io_fs_hello_retry,
{ "FSHelloRetry", "pn_io.fs_hello_retry",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_fs_hello_delay,
{ "FSHelloDelay", "pn_io.fs_hello_delay",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_fs_parameter_mode,
{ "FSParameterMode", "pn_io.fs_parameter_mode",
FT_UINT32, BASE_HEX, VALS(pn_io_fs_parameter_mode_vals), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_fs_parameter_uuid,
{ "FSParameterUUID", "pn_io.fs_parameter_uuid",
FT_GUID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_check_sync_mode,
{ "CheckSyncMode", "pn_io.check_sync_mode",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_check_sync_mode_reserved,
{ "Reserved", "pn_io.check_sync_mode.reserved",
FT_UINT16, BASE_HEX, NULL, 0xFFFC,
NULL, HFILL }
},
{ &hf_pn_io_check_sync_mode_sync_master,
{ "SyncMaster", "pn_io.check_sync_mode.sync_master",
FT_UINT16, BASE_HEX, NULL, 0x0002,
NULL, HFILL }
},
{ &hf_pn_io_check_sync_mode_cable_delay,
{ "CableDelay", "pn_io.check_sync_mode.cable_delay",
FT_UINT16, BASE_HEX, NULL, 0x0001,
NULL, HFILL }
},
{ &hf_pn_io_profisafe_f_prm_flag1,
{ "F_Prm_Flag1", "pn_io.profisafe.f_prm_flag1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profisafe_f_prm_flag1_chck_seq,
{ "F_Check_SeqNr", "pn_io.profisafe.f_prm_flag1.f_check_seqnr",
FT_UINT8, BASE_HEX, VALS(pn_io_f_check_seqnr), 0x01,
NULL, HFILL }
},
{ &hf_pn_io_profisafe_f_prm_flag1_chck_ipar,
{ "F_Check_iPar", "pn_io.profisafe.f_prm_flag1.f_check_ipar",
FT_UINT8, BASE_HEX, VALS(pn_io_f_check_ipar), 0x02,
NULL, HFILL }
},
{ &hf_pn_io_profisafe_f_prm_flag1_sil,
{ "F_SIL", "pn_io.profisafe.f_prm_flag1.f_sil",
FT_UINT8, BASE_HEX, VALS(pn_io_f_sil), 0xc,
NULL, HFILL }
},
{ &hf_pn_io_profisafe_f_prm_flag1_crc_len,
{ "F_CRC_Length", "pn_io.profisafe.f_prm_flag1.f_crc_len",
FT_UINT8, BASE_HEX, VALS(pn_io_f_crc_len), 0x30,
NULL, HFILL }
},
{ &hf_pn_io_profisafe_f_prm_flag1_reserved,
{ "Reserved", "pn_io.profisafe.f_prm_flag1.reserved",
FT_UINT8, BASE_HEX, NULL, 0xC0,
NULL, HFILL }
},
{ &hf_pn_io_profisafe_f_prm_flag2,
{ "F_Prm_Flag2", "pn_io.profisafe.f_prm_flag2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profisafe_f_prm_flag2_reserved,
{ "Reserved", "pn_io.profisafe.f_prm_flag2.reserved",
FT_UINT8, BASE_HEX, NULL, 0x07,
NULL, HFILL }
},
{ &hf_pn_io_profisafe_f_prm_flag2_f_block_id,
{ "F_BlockId", "pn_io.profisafe.f_prm_flag2.f_block_id",
FT_UINT8, BASE_HEX, VALS(pn_io_f_block_id), 0x38,
NULL, HFILL }
},
{ &hf_pn_io_profisafe_f_prm_flag2_f_par_version,
{ "F_ParVersion", "pn_io.profisafe.f_prm_flag2.f_par_version",
FT_UINT8, BASE_HEX, VALS(pn_io_f_par_version), 0xC0,
NULL, HFILL }
},
{ &hf_pn_io_profisafe_f_src_addr,
{ "F_Source_Address", "pn_io.profisafe.f_src_addr",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profisafe_f_dst_addr,
{ "F_Destination_Address", "pn_io.profisafe.f_dst_addr",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profisafe_f_wd_time,
{ "F_WD_Time", "pn_io.profisafe._f_wd_time",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profisafe_f_par_crc,
{ "F_Par_CRC", "pn_io.profisafe._f_par_crc",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profidrive_request_reference,
{ "RequestReference", "pn_io.profidrive.parameter.request_reference",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profidrive_request_id,
{ "RequestID", "pn_io.profidrive.parameter.request_id",
FT_UINT8, BASE_HEX, VALS(pn_io_profidrive_request_id_vals), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profidrive_do_id,
{ "DO", "pn_io.profidrive.parameter.do",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profidrive_no_of_parameters,
{ "NoOfParameters", "pn_io.profidrive.parameter.no_of_parameters",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profidrive_param_attribute,
{ "Attribute", "pn_io.profidrive.parameter.attribute",
FT_UINT8, BASE_HEX, VALS(pn_io_profidrive_attribute_vals), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profidrive_param_no_of_elems,
{ "NoOfElements", "pn_io.profidrive.parameter.no_of_elems",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profidrive_param_number,
{ "Parameter", "pn_io.profidrive.parameter.number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profidrive_param_subindex,
{ "Index", "pn_io.profidrive.parameter.index",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profidrive_response_id,
{ "ResponseID", "pn_io.profidrive.parameter.response_id",
FT_UINT8, BASE_HEX, VALS(pn_io_profidrive_response_id_vals), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profidrive_param_format,
{ "Format", "pn_io.profidrive.parameter.format",
FT_UINT8, BASE_HEX, VALS(pn_io_profidrive_format_vals), 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profidrive_param_no_of_values,
{ "NoOfValues", "pn_io.profidrive.parameter.no_of_values",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_profidrive_param_value,
{ "Value", "pn_io.profidrive.parameter.value",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_pn_io_packedframe_SFCRC,
{ "SFCRC16", "pn_io.packedframe.sfcrc",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
}
#endif
};
static gint *ett[] = {
&ett_pn_io,
&ett_pn_io_block,
&ett_pn_io_block_header,
&ett_pn_io_status,
&ett_pn_io_rtc,
&ett_pn_io_rta,
&ett_pn_io_pdu_type,
&ett_pn_io_add_flags,
&ett_pn_io_control_command,
&ett_pn_io_ioxs,
&ett_pn_io_api,
&ett_pn_io_data_description,
&ett_pn_io_module,
&ett_pn_io_submodule,
&ett_pn_io_io_data_object,
&ett_pn_io_io_cs,
&ett_pn_io_ar_properties,
&ett_pn_io_iocr_properties,
&ett_pn_io_submodule_properties,
&ett_pn_io_alarmcr_properties,
&ett_pn_io_submodule_state,
&ett_pn_io_channel_properties,
&ett_pn_io_slot,
&ett_pn_io_subslot,
&ett_pn_io_maintenance_status,
&ett_pn_io_data_status,
&ett_pn_io_iocr,
&ett_pn_io_mrp_rtmode,
&ett_pn_io_control_block_properties,
&ett_pn_io_check_sync_mode,
&ett_pn_io_ir_frame_data,
&ett_pn_FrameDataProperties,
&ett_pn_io_ar_info,
&ett_pn_io_ar_data,
&ett_pn_io_ir_begin_end_port,
&ett_pn_io_ir_tx_phase,
&ett_pn_io_ir_rx_phase,
&ett_pn_io_subframe_data,
&ett_pn_io_frame_defails,
&ett_pn_io_profisafe_f_parameter,
&ett_pn_io_profisafe_f_parameter_prm_flag1,
&ett_pn_io_profisafe_f_parameter_prm_flag2,
&ett_pn_io_profidrive_parameter_request,
&ett_pn_io_profidrive_parameter_response,
&ett_pn_io_profidrive_parameter_address,
&ett_pn_io_profidrive_parameter_value,
&ett_pn_io_GroupProperties
};
proto_pn_io = proto_register_protocol ("PROFINET IO", "PNIO", "pn_io");
proto_register_field_array (proto_pn_io, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
new_register_dissector("pn_io", dissect_PNIO_heur, proto_pn_io);
register_heur_dissector_list("pn_io", &heur_pn_subdissector_list);
register_init_routine(pnio_reinit);
register_dissector_filter("PN-IO AR", pn_io_ar_conv_valid, pn_io_ar_conv_filter);
register_dissector_filter("PN-IO AR (with data)", pn_io_ar_conv_valid, pn_io_ar_conv_data_filter);
}
void
proto_reg_handoff_pn_io (void)
{
dcerpc_init_uuid (proto_pn_io, ett_pn_io, &uuid_pn_io_device, ver_pn_io_device, pn_io_dissectors, hf_pn_io_opnum);
dcerpc_init_uuid (proto_pn_io, ett_pn_io, &uuid_pn_io_controller, ver_pn_io_controller, pn_io_dissectors, hf_pn_io_opnum);
dcerpc_init_uuid (proto_pn_io, ett_pn_io, &uuid_pn_io_supervisor, ver_pn_io_supervisor, pn_io_dissectors, hf_pn_io_opnum);
dcerpc_init_uuid (proto_pn_io, ett_pn_io, &uuid_pn_io_parameterserver, ver_pn_io_parameterserver, pn_io_dissectors, hf_pn_io_opnum);
heur_dissector_add("pn_rt", dissect_PNIO_heur, proto_pn_io);
}
