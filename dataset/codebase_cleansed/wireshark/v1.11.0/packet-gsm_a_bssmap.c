static guint16
be_cic(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string, int string_len)
{
guint32 curr_offset;
guint32 value;
curr_offset = offset;
value = tvb_get_ntohs(tvb, curr_offset);
other_decode_bitfield_value(a_bigbuf, value, 0xffe0, 16);
proto_tree_add_text(tree,
tvb, curr_offset, 2,
"%s = PCM Multiplexer: %u",
a_bigbuf,
(value & 0xffe0) >> 5);
other_decode_bitfield_value(a_bigbuf, value, 0x001f, 16);
proto_tree_add_text(tree,
tvb, curr_offset, 2,
"%s = Timeslot: %u",
a_bigbuf,
value & 0x001f);
curr_offset += 2;
if (add_string)
g_snprintf(add_string, string_len, " - (%u) (0x%04x)", value, value);
return(curr_offset - offset);
}
static guint16
be_res_avail(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint16 value;
int i;
curr_offset = offset;
for (i=0; i < 5; i++) {
value = tvb_get_ntohl(tvb, curr_offset);
proto_tree_add_text(tree, tvb, curr_offset, len, "Number of full rate channels available in band %u %u",i+1,value);
curr_offset+=2;
proto_tree_add_text(tree, tvb, curr_offset, len, "Number of half rate channels available in band %u %u",i+1, value);
curr_offset+=2;
}
return(len);
}
static guint16
be_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string, int string_len)
{
guint8 oct;
guint32 value;
guint32 curr_offset;
const gchar *str = NULL;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_gsm_a_bssmap_cause_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
if (oct & 0x80)
{
if ((oct & 0x0f) == 0x00)
{
switch ((oct & 0x70) >> 4)
{
case 0: str = "Normal Event"; break;
case 1: str = "Normal Event"; break;
case 2: str = "Resource Unavailable"; break;
case 3: str = "Service or option not available"; break;
case 4: str = "Service or option not implemented"; break;
case 5: str = "Invalid message (e.g., parameter out of range)"; break;
case 6: str = "Protocol error"; break;
default:
str = "Interworking";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x70, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Cause Class: %s",
a_bigbuf,
str);
other_decode_bitfield_value(a_bigbuf, oct, 0x0f, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = National Cause",
a_bigbuf);
curr_offset++;
proto_tree_add_text(tree, tvb, curr_offset, 1,
"Cause Value");
curr_offset++;
if (add_string)
g_snprintf(add_string, string_len, " - (National Cause)");
}
else
{
value = tvb_get_guint8(tvb, curr_offset + 1);
other_decode_bitfield_value(a_bigbuf, oct, 0x7f, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Cause (MSB): %u",
a_bigbuf,
((oct & 0x7f) << 8) | value);
curr_offset++;
other_decode_bitfield_value(a_bigbuf, value, 0xff, 8);
proto_tree_add_text(tree, tvb, curr_offset, 1,
"%s = Cause (LSB)",
a_bigbuf);
curr_offset++;
}
}
else
{
switch (oct)
{
case 0x00: str = "Radio interface message failure"; break;
case 0x01: str = "Radio interface failure"; break;
case 0x02: str = "Uplink quality"; break;
case 0x03: str = "Uplink strength"; break;
case 0x04: str = "Downlink quality"; break;
case 0x05: str = "Downlink strength"; break;
case 0x06: str = "Distance"; break;
case 0x07: str = "O and M intervention"; break;
case 0x08: str = "Response to MSC invocation"; break;
case 0x09: str = "Call control"; break;
case 0x0a: str = "Radio interface failure, reversion to old channel"; break;
case 0x0b: str = "Handover successful"; break;
case 0x0c: str = "Better Cell"; break;
case 0x0d: str = "Directed Retry"; break;
case 0x0e: str = "Joined group call channel"; break;
case 0x0f: str = "Traffic"; break;
case 0x10: str = "Reduce load in serving cell"; break;
case 0x11: str = "Traffic load in target cell higher than in source cell"; break;
case 0x12: str = "Relocation triggered"; break;
case 0x14: str = "Requested option not authorised"; break;
case 0x15: str = "Alternative channel configuration requested "; break;
case 0x16: str = "Call Identifier already allocated"; break;
case 0x17: str = "INTERNAL HANDOVER ENQUIRY reject"; break;
case 0x18: str = "Redundancy Level not adequate"; break;
case 0x20: str = "Equipment failure"; break;
case 0x21: str = "No radio resource available"; break;
case 0x22: str = "Requested terrestrial resource unavailable"; break;
case 0x23: str = "CCCH overload"; break;
case 0x24: str = "Processor overload"; break;
case 0x25: str = "BSS not equipped"; break;
case 0x26: str = "MS not equipped"; break;
case 0x27: str = "Invalid cell"; break;
case 0x28: str = "Traffic Load"; break;
case 0x29: str = "Preemption"; break;
case 0x2a: str = "DTM Handover - SGSN Failure"; break;
case 0x2b: str = "DTM Handover - PS Allocation failure"; break;
case 0x30: str = "Requested transcoding/rate adaption unavailable"; break;
case 0x31: str = "Circuit pool mismatch"; break;
case 0x32: str = "Switch circuit pool"; break;
case 0x33: str = "Requested speech version unavailable"; break;
case 0x34: str = "LSA not allowed"; break;
case 0x35: str = "Requested Codec Type or Codec Configuration unavailable"; break;
case 0x36: str = "Requested A-Interface Type unavailable"; break;
case 0x37: str = "Invalid CSG cell"; break;
case 0x3f: str = "Requested Redundancy Level not available"; break;
case 0x40: str = "Ciphering algorithm not supported"; break;
case 0x41: str = "GERAN Iu-mode failure"; break;
case 0x42: str = "Incoming Relocation Not Supported Due To PUESBINE Feature"; break;
case 0x43: str = "Access Restricted Due to Shared Networks"; break;
case 0x44: str = "Requested Codec Type or Codec Configuration not supported"; break;
case 0x45: str = "Requested A-Interface Type not supported"; break;
case 0x46: str = "Requested Redundancy Level not supported"; break;
case 0x47: str = "Reserved for international use"; break;
case 0x50: str = "Terrestrial circuit already allocated"; break;
case 0x51: str = "Invalid message contents"; break;
case 0x52: str = "Information element or field missing"; break;
case 0x53: str = "Incorrect value"; break;
case 0x54: str = "Unknown Message type"; break;
case 0x55: str = "Unknown Information Element"; break;
case 0x56: str = "DTM Handover - Invalid PS Indication"; break;
case 0x57: str = "Call Identifier already allocated"; break;
case 0x60: str = "Protocol Error between BSS and MSC"; break;
case 0x61: str = "VGCS/VBS call non existent"; break;
case 0x62: str = "DTM Handover - Timer Expiry"; break;
default:
if ((oct >= 0x19) && (oct <= 0x1f)) { str = "Reserved for national use"; }
else if ((oct >= 0x2c) && (oct <= 0x2f)) { str = "Reserved for national use"; }
else if ((oct >= 0x38) && (oct <= 0x3e)) { str = "Reserved for international use"; }
else if ((oct >= 0x48) && (oct <= 0x4f)) { str = "Reserved for national use"; }
else if ((oct >= 0x58) && (oct <= 0x5f)) { str = "Reserved for national use"; }
else if ((oct >= 0x63) && (oct <= 0x67)) { str = "Reserved for international use"; }
else if ((oct >= 0x68) && (oct <= 0x6f)) { str = "Reserved for national use"; }
else if ((oct >= 0x70) && (oct <= 0x77)) { str = "Reserved for international use"; }
else if ((oct >= 0x78) && (oct <= 0x7f)) { str = "Reserved for national use"; }
else { str = "Unknown"; }
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x7f, 8);
proto_tree_add_uint_format(tree, hf_gsm_a_bssmap_cause,
tvb, curr_offset, 1, oct & 0x7f,
"%s = Cause: (%u) %s",
a_bigbuf,
oct & 0x7f,
str);
curr_offset++;
if (add_string)
g_snprintf(add_string, string_len, " - (%u) %s", oct & 0x7f, str);
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
be_tmsi(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string, int string_len)
{
guint32 curr_offset;
guint32 value;
curr_offset = offset;
value = tvb_get_ntohl(tvb, curr_offset);
proto_tree_add_uint(tree, hf_gsm_a_tmsi,
tvb, curr_offset, 4,
value);
if (add_string)
g_snprintf(add_string, string_len, " - (0x%04x)", value);
curr_offset += 4;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
be_num_ms(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_num_ms, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
be_l3_header_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_L3_protocol_discriminator, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x08, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = TI flag: %s",
a_bigbuf,
((oct & 0x08) ? "allocated by receiver" : "allocated by sender"));
other_decode_bitfield_value(a_bigbuf, oct, 0x07, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = TIO: %u",
a_bigbuf,
oct & 0x07);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
be_enc_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint8 mask;
guint8 alg_id;
guint32 curr_offset;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
mask = 0x80;
alg_id = 7;
do
{
other_decode_bitfield_value(a_bigbuf, oct, mask, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = GSM A5/%u: %spermitted",
a_bigbuf,
alg_id,
(mask & oct) ? "" : "not ");
mask >>= 1;
alg_id--;
}
while (mask != 0x01);
other_decode_bitfield_value(a_bigbuf, oct, mask, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = No encryption: %spermitted",
a_bigbuf,
(mask & oct) ? "" : "not ");
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_text(tree,
tvb, curr_offset, len - (curr_offset - offset),
"Key: %s",
tvb_bytes_to_str(tvb, curr_offset, len-(curr_offset-offset) ));
curr_offset += len - (curr_offset - offset);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
guint16
be_chan_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string, int string_len)
{
guint8 oct;
guint8 sdi;
guint8 num_chan;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
sdi = oct & 0x0f;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_speech_data_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
if (add_string)
g_snprintf(add_string, string_len, " - (%s)", val_to_str_const(tvb_get_guint8(tvb, curr_offset) & 0x0f,
gsm_a_bssap_speech_data_ind_vals,
"Unknown"));
curr_offset++;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
if ((sdi == 0x01)||(sdi == 0x04))
{
proto_tree_add_item(tree, hf_gsm_a_bssmap_channel_rate_and_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
do
{
proto_tree_add_item(tree, hf_gsm_a_bssmap_chan_type_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_perm_speech_v_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
}
while ((len - (curr_offset - offset)) > 0);
}
else if (sdi == 0x02)
{
num_chan = 0;
switch (oct)
{
case 0x00: str = "SDCCH or Full rate TCH channel Bm or Half rate TCH channel Lm"; break;
case 0x01: str = "SDCCH "; break;
case 0x02: str = "SDCCH or Full rate TCH channel Bm"; break;
case 0x03: str = "Half rate TCH channel Lm"; break;
case 0x08: str = "Full rate TCH channel Bm"; break;
case 0x09: str = "Half rate TCH channel Lm"; break;
case 0x0a: str = "Full or Half rate TCH channel, Full rate preferred, changes allowed also after first channel allocation as a result of the request"; break;
case 0x0b: str = "Full or Half rate TCH channel, Half rate preferred, changes allowed also after first channel allocation as a result of the request"; break;
case 0x1a: str = "Full or Half rate TCH channel, Full rate preferred, changes not allowed after first channel allocation as a result of the request"; break;
case 0x1b: str = "Full or Half rate TCH channel. Half rate preferred, changes not allowed after first channel allocation as a result of the request"; break;
default:
if ((oct >= 0x20) && (oct <= 0x27))
{
str = "Full rate TCH channels in a multislot configuration, changes by the BSS of the the number of TCHs and if applicable the used radio interface rate per channel allowed after first channel allocation as a result of the request";
num_chan = (oct - 0x20) + 1;
}
else if ((oct >= 0x30) && (oct <= 0x37))
{
str = "Full rate TCH channels in a multislot configuration, changes by the BSS of the number of TCHs or the used radio interface rate per channel not allowed after first channel allocation as a result of the request";
num_chan = (oct - 0x30) + 1;
}
else
{
str = "Reserved";
}
break;
}
if (num_chan > 0)
{
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Channel Rate and Type: Max channels %u, %s",
num_chan,
str);
}
else
{
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Channel Rate and Type: %s",
str);
}
curr_offset++;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_gsm_a_bssmap_chan_type_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x40, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = %sTransparent service",
a_bigbuf,
(oct & 0x40) ? "Non-" : "");
if (num_chan == 0)
{
if (oct & 0x40)
{
switch (oct & 0x3f)
{
case 0x00: str = "12 kbit/s if the channel is a full rate TCH, or 6 kbit/s if the channel is a half rate TCH"; break;
case 0x18: str = "14.5 kbit/s"; break;
case 0x10: str = "12 kbits/s"; break;
case 0x11: str = "6 kbits/s"; break;
case 0x31: str = "29 kbit/s"; break;
case 0x34: str = "43,5 kbit/s"; break;
default:
str = "Reserved";
break;
}
}
else
{
switch (oct & 0x3f)
{
case 0x18: str = "14.4 kbit/s"; break;
case 0x10: str = "9.6kbit/s"; break;
case 0x11: str = "4.8kbit/s"; break;
case 0x12: str = "2.4kbit/s"; break;
case 0x13: str = "1.2Kbit/s"; break;
case 0x14: str = "600 bit/s"; break;
case 0x15: str = "1200/75 bit/s (1200 network-to-MS / 75 MS-to-network)"; break;
case 0x39: str = "28,8 kbit/s"; break;
case 0x3a: str = "32,0 kbit/s"; break;
default:
str = "Reserved";
break;
}
}
}
else
{
if (oct & 0x40)
{
switch (oct & 0x3f)
{
case 0x16: str = "58 kbit/s (4x14.5 kbit/s)"; break;
case 0x14: str = "48.0 / 43.5 kbit/s (4x12 kbit/s or 3x14.5 kbit/s)"; break;
case 0x13: str = "36.0 / 29.0 kbit/s (3x12 kbit/s or 2x14.5 kbit/s)"; break;
case 0x12: str = "24.0 / 24.0 (4x6 kbit/s or 2x12 kbit/s)"; break;
case 0x11: str = "18.0 / 14.5 kbit/s (3x6 kbit/s or 1x14.5 kbit/s)"; break;
case 0x10: str = "12.0 / 12.0 kbit/s (2x6 kbit/s or 1x12 kbit/s)"; break;
default:
str = "Reserved";
break;
}
}
else
{
switch (oct & 0x3f)
{
case 0x1f: str = "64 kbit/s, bit transparent"; break;
case 0x1e: str = "56 kbit/s, bit transparent"; break;
case 0x1d: str = "56 kbit/s"; break;
case 0x1c: str = "48 kbit/s"; break;
case 0x1b: str = "38.4 kbit/s"; break;
case 0x1a: str = "28.8 kbit/s"; break;
case 0x19: str = "19.2 kbit/s"; break;
case 0x18: str = "14.4 kbit/s"; break;
case 0x10: str = "9.6 kbit/s"; break;
default:
str = "Reserved";
break;
}
}
}
other_decode_bitfield_value(a_bigbuf, oct, 0x3f, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Rate: %s",
a_bigbuf,
str);
curr_offset++;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_gsm_a_bssmap_chan_type_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, (curr_offset<<3)+1, 3, ENC_BIG_ENDIAN);
if (num_chan == 0)
{
other_decode_bitfield_value(a_bigbuf, oct, 0x08, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = 14.5 kbit/s (TCH/F14.4) %sallowed",
a_bigbuf,
(oct & 0x08) ? "" : "not ");
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, (curr_offset<<3)+6, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x02, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = 12.0 kbit/s (TCH F/9.6) %sallowed",
a_bigbuf,
(oct & 0x02) ? "" : "not ");
other_decode_bitfield_value(a_bigbuf, oct, 0x01, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = 6.0 kbit/s (TCH F/4.8) %sallowed",
a_bigbuf,
(oct & 0x01) ? "" : "not ");
}
else
{
other_decode_bitfield_value(a_bigbuf, oct, 0x08, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = 14.5/14.4 kbit/s (TCH/F14.4) %sallowed",
a_bigbuf,
(oct & 0x08) ? "" : "not ");
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, (curr_offset<<3)+6, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x02, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = 12.0/9.6 kbit/s (TCH F/9.6) %sallowed",
a_bigbuf,
(oct & 0x02) ? "" : "not ");
other_decode_bitfield_value(a_bigbuf, oct, 0x01, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = 6.0/4.8 kbit/s (TCH F/4.8) %sallowed",
a_bigbuf,
(oct & 0x01) ? "" : "not ");
}
curr_offset++;
}
else if (sdi == 0x03)
{
switch (oct)
{
case 0x00: str = "SDCCH or Full rate TCH channel Bm or Half rate TCH channel Lm"; break;
case 0x01: str = "SDCCH"; break;
case 0x02: str = "SDCCH or Full rate TCH channel Bm"; break;
case 0x03: str = "SDCCH or Half rate TCH channel Lm"; break;
case 0x08: str = "Full rate TCH channel Bm"; break;
case 0x09: str = "Half rate TCH channel Lm"; break;
case 0x0a: str = "Full or Half rate TCH channel, Full rate preferred, changes allowed also after first channel allocation as a result of the request"; break;
case 0x0b: str = "Full or Half rate TCH channel, Half rate preferred, changes allowed also after first channel allocation as a result of the request"; break;
case 0x1a: str = "Full or Half rate TCH channel, Full rate preferred, changes not allowed after first channel allocation as a result of the request"; break;
case 0x1b: str = "Full or Half rate TCH channel. Half rate preferred, changes not allowed after first channel allocation as a result of the request"; break;
default:
str = "Reserved";
break;
}
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Channel Rate and Type: %s",
str);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_text(tree,
tvb, curr_offset, len - (curr_offset - offset),
"Spare");
curr_offset += len - (curr_offset - offset);
}
else
{
proto_tree_add_text(tree,
tvb, curr_offset, len - (curr_offset - offset),
"Unknown format");
curr_offset += len - (curr_offset - offset);
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
be_periodicity(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_periodicity, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_ext_res_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 6, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_sm, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_tarr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_tot_res_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_tot_no_of_fullr_ch, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
proto_tree_add_item(tree, hf_gsm_a_bssmap_tot_no_of_hr_ch, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
return(len);
}
static guint16
be_lsa_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_lsa_id, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
return(len);
}
static guint16
be_lsa_id_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 7, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_ep, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
while (curr_offset-offset < len) {
proto_tree_add_item(tree, hf_gsm_a_bssmap_lsa_id, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
curr_offset+=3;
}
return(len);
}
guint16
be_cell_id_aux(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len, guint8 disc)
{
guint32 value;
guint32 curr_offset;
if (add_string)
add_string[0] = '\0';
curr_offset = offset;
switch (disc)
{
case 0x00:
case 0x04:
case 0x08:
case 0xb:
case 0x0c:
if (disc != 0x0b)
curr_offset = dissect_e212_mcc_mnc(tvb, pinfo, tree, curr_offset, TRUE);
else
curr_offset = dissect_e212_mcc_mnc(tvb, pinfo, tree, curr_offset, FALSE);
case 0x01:
case 0x05:
case 0x0a:
value = tvb_get_ntohs(tvb, curr_offset);
proto_tree_add_item(tree, hf_gsm_a_bssmap_cell_lac, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
if (add_string)
g_snprintf(add_string, string_len, " - LAC (0x%04x)", value);
if (disc == 0x0b) {
proto_tree_add_item(tree, hf_gsm_a_bssmap_sac, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
break;
}
case 0x09:
if ((disc == 0x08) ||(disc == 0x09) || (disc == 0x0a)|| (disc == 0x0c)) {
value = tvb_get_ntohs(tvb, curr_offset);
proto_tree_add_item(tree, hf_gsm_a_bssmap_be_rnc_id, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
if (add_string)
{
if (add_string[0] == '\0')
{
g_snprintf(add_string, string_len, " - RNC-ID (%u)", value);
}
else
{
g_snprintf(add_string, string_len, "%s/RNC-ID (%u)", add_string, value);
}
}
break;
}
if ((disc == 0x04) || (disc == 0x05) || (disc == 0x08)) break;
case 0x02:
value = tvb_get_ntohs(tvb, curr_offset);
proto_tree_add_uint(tree, hf_gsm_a_bssmap_cell_ci, tvb,
curr_offset, 2, value);
curr_offset += 2;
if (add_string)
{
if (add_string[0] == '\0')
{
g_snprintf(add_string, string_len, " - CI (%u)", value);
}
else
{
g_snprintf(add_string, string_len, "%s/CI (%u)", add_string, value);
}
}
break;
default:
proto_tree_add_text(tree, tvb, curr_offset, len,
"Cell ID - Unknown format");
curr_offset += (len);
break;
}
return(curr_offset - offset);
}
static guint16
be_cell_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string, int string_len)
{
guint8 oct;
guint8 disc;
guint32 curr_offset;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_be_cell_id_disc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
disc = oct&0x0f;
cell_discriminator = disc;
curr_offset++;
NO_MORE_DATA_CHECK(len);
curr_offset +=
be_cell_id_aux(tvb, tree, pinfo, curr_offset, len - (curr_offset - offset), add_string, string_len, disc);
return(curr_offset - offset);
}
guint16
be_prio(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string, int string_len)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_gsm_a_b8spare, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_pci, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
switch ((oct & 0x3c) >> 2)
{
case 0x00: str = "Spare"; break;
case 0x0f: str = "priority not used"; break;
default:
str = "1 is highest";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x3c, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Priority Level: (%u) %s",
a_bigbuf,
(oct & 0x3c) >> 2,
str);
if (add_string)
g_snprintf(add_string, string_len, " - (%u)", (oct & 0x3c) >> 2);
proto_tree_add_item(tree, hf_gsm_a_bssmap_qa, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_pvi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_int_band(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_interference_bands, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_lsa_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 7, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_lsa_only, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
while (curr_offset-offset < len) {
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_act, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_pref, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_lsa_inf_prio, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_gsm_a_bssmap_lsa_id, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
curr_offset+=3;
}
return(len);
}
static guint16
be_l3_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
tvbuff_t *l3_tvb;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len,
"Layer 3 Information value");
l3_tvb = tvb_new_subset(tvb, curr_offset, len, len);
if ( cell_discriminator == 0xFF)
{
proto_tree_add_text(tree, l3_tvb, curr_offset, len, "Cell Discriminator not initialised, try enabling the SCCP protocol option [Trace Associations], \n or maybe the file does not contain the PDUs needed for SCCP trace");
}
else if ((cell_discriminator & 0x0f) < 8) {
call_dissector(dtap_handle, l3_tvb, pinfo, g_tree);
}
else if ((cell_discriminator & 0x0f) < 13) {
dissect_rrc_HandoverToUTRANCommand_PDU(l3_tvb, pinfo, g_tree, NULL);
}
else{
proto_tree_add_text(tree, l3_tvb, curr_offset, len, "Unrecognised Cell Discriminator %x",cell_discriminator);
}
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
be_dlci(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint32 curr_offset;
proto_item *item = NULL;
proto_tree *subtree = NULL;
curr_offset = offset;
item =
proto_tree_add_text(tree, tvb, curr_offset, 1,
"Data Link Connection Identifier");
subtree = proto_item_add_subtree(item, ett_dlci);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint(subtree, hf_gsm_a_bssmap_dlci_cc, tvb, curr_offset, 1, oct);
proto_tree_add_uint(subtree, hf_gsm_a_bssmap_dlci_spare, tvb, curr_offset, 1, oct);
proto_tree_add_uint(subtree, hf_gsm_a_bssmap_dlci_sapi, tvb, curr_offset, 1, oct);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_down_dtx_flag(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint oct;
guint32 curr_offset;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 7, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x01, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = BSS is %s to activate DTX in the downlink direction",
a_bigbuf,
(oct & 0x01) ? "forbidden" : "allowed");
curr_offset++;
return(curr_offset - offset);
}
guint16
be_cell_id_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len)
{
guint8 oct;
guint16 consumed;
guint8 disc;
guint8 num_cells;
guint32 curr_offset;
proto_item *item = NULL;
proto_tree *subtree = NULL;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
disc = oct & 0x0f;
cell_discriminator = disc;
proto_tree_add_item(tree, hf_gsm_a_bssmap_be_cell_id_disc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
num_cells = 0;
do
{
item =
proto_tree_add_text(tree,
tvb, curr_offset, -1,
"Cell %u",
num_cells + 1);
subtree = proto_item_add_subtree(item, ett_cell_list);
if (add_string)
add_string[0] = '\0';
consumed =
be_cell_id_aux(tvb, subtree, pinfo, curr_offset, len - (curr_offset - offset), add_string, string_len, disc);
if (add_string && add_string[0] != '\0')
proto_item_append_text(item, "%s", add_string);
proto_item_set_len(item, consumed);
curr_offset += consumed;
num_cells++;
}
while ((len - (curr_offset - offset)) > 0 && consumed > 0);
if (add_string) {
g_snprintf(add_string, string_len, " - %u cell%s",
num_cells, plurality(num_cells, "", "s"));
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
be_cell_id_list_seg(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_seq_len, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_seq_no, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssap_cell_id_list_seg_cell_id_disc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_text(tree, tvb, curr_offset, len-2, "Not decoded yet");
return(len);
}
static guint16
be_cell_id_lst_seg_f_est_cells(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssap_cell_id_list_seg_cell_id_disc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_text(tree, tvb, curr_offset, len-1, "Not decoded yet");
return(len);
}
static guint16
be_cell_id_lst_seg_f_cell_tb_est(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssap_cell_id_list_seg_cell_id_disc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_text(tree, tvb, curr_offset, len-1, "Not decoded yet");
return(len);
}
static guint16
be_cell_id_lst_seg_f_rel_cell(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssap_cell_id_list_seg_cell_id_disc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_text(tree, tvb, curr_offset, len-1, "Not decoded yet");
return(len);
}
static guint16
be_cell_id_lst_seg_f_not_est_cell(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssap_cell_id_list_seg_cell_id_disc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_text(tree, tvb, curr_offset, len-1, "Not decoded yet");
return(len);
}
static guint16
be_res_ind_method(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssap_res_ind_method, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(len);
}
static guint16
be_cic_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssap_cic_list_range, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssap_cic_list_status, tvb, (curr_offset+1), (len-1), ENC_NA);
return(len);
}
static guint16
be_diag(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len , gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssap_diag_error_pointer, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_gsm_a_bssap_diag_msg_rcv, tvb, curr_offset, (len-2), ENC_NA);
return(len);
}
static guint16
be_chosen_chan(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_ch_mode, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_channel, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_ciph_resp_mode(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 7, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x01, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = IMEISV must %sbe included by the mobile station",
a_bigbuf,
(oct & 0x01) ? "" : "not ");
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_l3_msg(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *l3_tvb;
proto_tree_add_text(tree, tvb, offset, len,
"Layer 3 Message Contents");
l3_tvb = tvb_new_subset(tvb, offset, len, len);
call_dissector(dtap_handle, l3_tvb, pinfo, g_tree);
return(len);
}
static guint16
be_cha_needed(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_chnl_needed_ch1, tvb, (curr_offset<<3)+6, 2, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_trace_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
gint bit_offset;
bit_offset = (offset<<3);
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_trace_priority_indication, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset ++;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset ++;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_trace_bss_record_type, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_trace_msc_record_type, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_trace_invoking_event, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_trace_trigger_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_trace_trigger_id, tvb, curr_offset, len, ENC_ASCII|ENC_NA);
curr_offset += len;
return(curr_offset - offset);
}
static guint16
be_trace_reference(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_trace_reference, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset +=2;
return(curr_offset - offset);
}
static guint16
be_trace_transaction_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
if (len == 1)
{
proto_tree_add_item(tree, hf_gsm_a_bssmap_trace_reference, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset ++;
}
else
{
proto_tree_add_item(tree, hf_gsm_a_bssmap_trace_reference, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset +=2;
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
be_trace_omc_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_trace_omc_id, tvb, curr_offset, len, ENC_ASCII|ENC_NA);
curr_offset += len;
return(curr_offset - offset);
}
static guint16
be_for_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint32 curr_offset;
const gchar *str = NULL;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
switch (oct & 0x0f)
{
case 1: str = "forward to subsequent BSS, no trace at MSC"; break;
case 2: str = "forward to subsequent BSS, and trace at MSC"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x0f, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = %s",
a_bigbuf,
str);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_chosen_enc_alg(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string, int string_len)
{
guint8 oct;
guint32 curr_offset;
const gchar *str = NULL;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct)
{
case 0x01: str = "No encryption used"; break;
case 0x02: str = "GSM A5/1"; break;
case 0x03: str = "GSM A5/2"; break;
case 0x04: str = "GSM A5/3"; break;
case 0x05: str = "GSM A5/4"; break;
case 0x06: str = "GSM A5/5"; break;
case 0x07: str = "GSM A5/6"; break;
case 0x08: str = "GSM A5/7"; break;
default:
str = "Reserved";
break;
}
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Algorithm Identifier: %s",
str);
curr_offset++;
if (add_string)
g_snprintf(add_string, string_len, " - %s", str);
return(curr_offset - offset);
}
static guint16
be_cct_pool(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string, int string_len)
{
guint8 oct;
guint32 curr_offset;
const gchar *str = NULL;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
if (oct <= 50)
{
str = "";
}
else if ((oct >= 0x80) && (oct <= 0x8f))
{
str = ", for national/local use";
}
else
{
str = ", reserved for future international use";
}
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Circuit pool number: %u%s",
oct,
str);
curr_offset++;
if (add_string)
g_snprintf(add_string, string_len, " - (%u)", oct);
return(curr_offset - offset);
}
static guint16
be_curr_chan_1(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_cur_ch_mode, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_channel, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_que_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 6, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x02, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = qri: it is recommended %sto allow queuing",
a_bigbuf,
(oct & 0x02) ? "" : "not ");
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, (curr_offset<<3)+7, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_speech_ver(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string, int string_len)
{
guint8 oct;
guint32 curr_offset;
const gchar *str = NULL;
const gchar *short_str = NULL;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_gsm_a_b8spare, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
switch (oct & 0x7f)
{
case 0x01: str = "GSM speech full rate version 1"; short_str = "FR1"; break;
case 0x11: str = "GSM speech full rate version 2"; short_str = "FR2"; break;
case 0x21: str = "GSM speech full rate version 3 (AMR)"; short_str = "FR3 (AMR)"; break;
case 0x05: str = "GSM speech half rate version 1"; short_str = "HR1"; break;
case 0x15: str = "GSM speech half rate version 2"; short_str = "HR2"; break;
case 0x25: str = "GSM speech half rate version 3 (AMR)"; short_str = "HR3 (AMR)"; break;
case 0x41: str = "GSM speech full rate version 4";short_str = "OFR AMR-WB"; break;
case 0x42: str = "GSM speech full rate version 5";short_str = "FR AMR-WB"; break;
case 0x46: str = "GSM speech half rate version 4";short_str = "OHR AMR-WB"; break;
case 0x45: str = "GSM speech half rate version 6";short_str = "OHR AMR"; break;
default:
str = "Reserved";
short_str = str;
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x7f, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Speech version identifier: %s",
a_bigbuf,
str);
curr_offset++;
if (add_string)
g_snprintf(add_string, string_len, " - (%s)", short_str);
return(curr_offset - offset);
}
static guint16
be_ass_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len, "Not decoded yet");
return(len);
}
guint16
be_emlpp_prio(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, offset << 3, 5, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_emlpp_prio, tvb, offset, 1, ENC_BIG_ENDIAN);
return 1;
}
static guint16
be_conf_evo_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_smi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
void
bssmap_old_bss_to_new_bss_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo)
{
guint16 len;
if (!tree) {
return;
}
g_tree = tree;
len = tvb_length(tvb);
be_field_element_dissect(tvb, tree, pinfo, 0, len, NULL, 0);
g_tree = NULL;
}
static guint16
be_lcs_prio(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_lcs_pri, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_loc_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 location_information;
curr_offset = offset;
location_information = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gsm_a_bssmap_location_type_location_information, tvb, offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if (location_information == 1 || location_information == 2)
{
proto_tree_add_item(tree, hf_gsm_a_bssmap_location_type_positioning_method, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
}
return(curr_offset - offset);
}
static guint16
be_loc_est(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *data_tvb;
guint32 curr_offset;
curr_offset = offset;
data_tvb = tvb_new_subset(tvb, curr_offset, len, len);
dissect_geographical_description(data_tvb, pinfo, tree);
return(len);
}
static guint16
be_pos_data(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 i;
guint64 pos_data_disc;
gint bit_offset;
curr_offset = offset;
bit_offset = (offset<<3);
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_ret_val(tree, hf_gsm_a_bssmap_positioning_data_discriminator, tvb, bit_offset, 4, &pos_data_disc, ENC_BIG_ENDIAN);
bit_offset += 4;
curr_offset++;
if (pos_data_disc == 0)
{
for (i = 0; i < len-1; i++)
{
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_positioning_method, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_positioning_method_usage, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
curr_offset++;
}
}
return(curr_offset - offset);
}
static guint16
be_apdu(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 apdu_protocol_id;
tvbuff_t *APDU_tvb;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len, "APDU");
apdu_protocol_id = tvb_get_guint8(tvb,curr_offset);
proto_tree_add_item(tree, hf_gsm_a_bssmap_apdu_protocol_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
len--;
switch (apdu_protocol_id) {
case 1:
APDU_tvb = tvb_new_subset(tvb, curr_offset, len, len);
if (gsm_bsslap_handle)
call_dissector(gsm_bsslap_handle, APDU_tvb, pinfo, g_tree);
break;
case 2:
break;
case 3:
break;
default:
break;
}
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
be_gps_assist_data(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len , "Not decoded yet");
return(len);
}
static guint16
be_ret_err_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len , "Not decoded yet");
return(len);
}
static guint16
be_ret_err_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len , "Not decoded yet");
return(len);
}
static guint16
be_seg(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len , "Not decoded yet");
return(len);
}
static guint16
be_serv_ho(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 5, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_serv_ho_inf, tvb, curr_offset+1, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(len);
}
static guint16
be_src_rnc_to_tar_rnc_umts(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *container_tvb;
guint32 curr_offset;
curr_offset = offset;
container_tvb = tvb_new_subset(tvb, curr_offset, len, len);
dissect_ranap_SourceRNC_ToTargetRNC_TransparentContainer_PDU(container_tvb, pinfo, tree, NULL);
return(len);
}
static guint16
be_src_rnc_to_tar_rnc_cdma(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len , "Not decoded yet");
return(len);
}
static guint16
be_geran_cls_m(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
if (len > 2) {
de_sup_codec_list(tvb, tree, pinfo, curr_offset, (len-2), NULL, 0);
}
curr_offset += len-2;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 5, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_max_nb_traffic_chan, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_acceptable_chan_coding_bit5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_acceptable_chan_coding_bit4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_acceptable_chan_coding_bit3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_acceptable_chan_coding_bit2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_acceptable_chan_coding_bit1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
return(len);
}
static guint16
be_geran_bsc_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssap_speech_codec, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_gsm_a_bssmap_allowed_data_rate_bit8, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_allowed_data_rate_bit7, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_allowed_data_rate_bit6, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_allowed_data_rate_bit5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_allowed_data_rate_bit4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_max_nb_traffic_chan, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
return(len);
}
void
bssmap_new_bss_to_old_bss_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo)
{
guint16 len;
if (!tree) {
return;
}
g_tree = tree;
len = tvb_length(tvb);
be_field_element_dissect(tvb, tree, pinfo, 0, len, NULL, 0);
g_tree = NULL;
}
static guint16
be_inter_sys_inf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *new_tvb;
new_tvb = tvb_new_subset(tvb, offset, len, len);
if (new_tvb) {
dissect_ranap_InterSystemInformation_TransparentContainer_PDU(new_tvb, pinfo, tree, NULL);
}
return(len);
}
static guint16
be_sna_acc_inf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len , "Not decoded yet");
return(len);
}
static guint16
be_vstk_rand_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint64 vstk_rand;
curr_offset = offset;
vstk_rand = tvb_get_ntoh40(tvb, curr_offset);
vstk_rand >>= 4;
proto_tree_add_uint64(tree, hf_gsm_a_bssmap_vstk_rand, tvb, curr_offset, 5, vstk_rand);
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, (((curr_offset+4)<<3)+4), 4, ENC_BIG_ENDIAN);
return(len);
}
static guint16
be_vstk_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_item(tree, hf_gsm_a_bssmap_vstk, tvb, offset, 16, ENC_NA);
return(len);
}
static guint16
be_paging_inf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 5, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_paging_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_paging_inf_flg, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
be_vel_est(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len)
{
dissect_description_of_velocity(tvb, tree, pinfo, offset, len, add_string, string_len);
return(len);
}
static guint16
be_vgcs_feat_flg(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_tcp, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_bss_res, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_asind_b3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_asind_b2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_tpind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
static guint16
be_talker_pri(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_talker_pri, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
be_talker_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, curr_offset<<3, 5, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_filler_bits, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_text(tree, tvb, curr_offset, len-1, "Talker Identity field");
return(len);
}
static guint16
be_sms_to_vgcs(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
rp_data_n_ms(tvb, tree, pinfo, offset, len);
return(len);
}
static guint16
be_vgcs_talker_mode(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_rr_mode, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_group_cipher_key_nb, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, ((curr_offset<<3)+6), 2, ENC_BIG_ENDIAN);
return(len);
}
static guint16
be_vgcs_vbs_cell_status(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, (curr_offset<<3), 5, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_vgcs_vbs_cell_status, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
return(len);
}
guint16
be_ganss_ass_dta(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len, "Not decoded yet");
return(len);
}
guint16
be_ganss_pos_dta(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_method, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_ganss_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_usage, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset-offset);
}
guint16
be_ganss_loc_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len, "Not decoded yet");
return(len);
}
guint16
be_app_data(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len, "Not decoded yet");
return(len);
}
guint16
be_app_data_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_item(tree, hf_gsm_a_bssmap_data_id, tvb, offset, 1, ENC_BIG_ENDIAN);
return(len);
}
static guint16
be_app_data_inf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, (curr_offset<<3), 7, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_bt_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
return(len);
}
static guint16
be_msisdn(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *new_tvb;
new_tvb = tvb_new_subset(tvb, offset, len, len);
if (new_tvb) {
dissect_gsm_map_msisdn(new_tvb, pinfo , tree);
}
return len;
}
static guint16
be_aoip_trans_lay_add(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 addr_type;
guint32 rtp_ipv4_address;
guint16 rtp_port;
address rtp_dst_addr;
struct e_in6_addr rtp_addr_ipv6;
curr_offset = offset;
switch (len) {
case 6:
addr_type = 1;
proto_tree_add_item(tree, hf_gsm_a_bssmap_aoip_trans_ipv4, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
rtp_ipv4_address = tvb_get_ipv4(tvb, curr_offset);
curr_offset+=4;
break;
case 18:
addr_type = 2;
proto_tree_add_item(tree, hf_gsm_a_bssmap_aoip_trans_ipv6, tvb, curr_offset, 16, ENC_NA);
tvb_get_ipv6(tvb, offset + 5, &rtp_addr_ipv6);
curr_offset+=16;
break;
default:
proto_tree_add_text(tree, tvb, curr_offset, len, "Bogus length %u",len);
return(len);
}
proto_tree_add_item(tree, hf_gsm_a_bssmap_aoip_trans_port, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
rtp_port = tvb_get_ntohs(tvb,curr_offset);
curr_offset+=2;
switch (addr_type) {
case 1:
rtp_dst_addr.type = AT_IPv4;
rtp_dst_addr.len = 4;
rtp_dst_addr.data = (guint8 *)&rtp_ipv4_address;
break;
case 2:
rtp_dst_addr.type = AT_IPv6;
rtp_dst_addr.len = 16;
rtp_dst_addr.data = (guint8 *)&rtp_addr_ipv6;
break;
}
if ((!pinfo->fd->flags.visited) && rtp_port != 0 && rtp_handle) {
rtp_add_address(pinfo, &rtp_dst_addr, rtp_port, 0, "BSS MAP", pinfo->fd->num, FALSE, 0);
rtcp_add_address(pinfo, &rtp_dst_addr, rtp_port+1, 0, "BSS MAP", pinfo->fd->num);
}
return(curr_offset - offset);
}
static guint16
be_speech_codec_lst(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, consumed = 0;
guint8 codec;
guint8 number = 0;
proto_item *item = NULL;
proto_tree *subtree = NULL;
curr_offset = offset;
while (curr_offset-offset < len) {
number++;
consumed = 0;
item = proto_tree_add_text(tree, tvb, curr_offset, 1, "Speech Codec Element %u",number);
subtree = proto_item_add_subtree(item, ett_codec_lst);
codec = tvb_get_guint8(tvb,curr_offset)&0x0f;
switch (codec) {
case 0:
case 1:
case 2:
proto_tree_add_item(subtree, hf_gsm_a_bssmap_fi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pt, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_tf, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssap_speech_codec, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, " - %s",
val_to_str_const(tvb_get_guint8(tvb, curr_offset) & 0x0f,
bssap_speech_codec_values,
"Unknown"));
curr_offset++;
consumed++;
break;
case 3:
case 4:
case 0xb:
proto_tree_add_item(subtree, hf_gsm_a_bssmap_fi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pt, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_tf, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssap_speech_codec, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, " - %s",
val_to_str_const(tvb_get_guint8(tvb, curr_offset) & 0x0f,
bssap_speech_codec_values,
"Unknown"));
curr_offset++;
consumed++;
proto_tree_add_text(subtree, tvb, curr_offset, 2, "S0 - S15");
curr_offset+=2;
consumed+=2;
break;
case 0x9:
case 0xc:
case 0xd:
proto_tree_add_item(subtree, hf_gsm_a_bssmap_fi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pt, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_tf, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssap_speech_codec, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, " - %s",
val_to_str_const(tvb_get_guint8(tvb, curr_offset) & 0x0f,
bssap_speech_codec_values,
"Unknown"));
curr_offset++;
consumed++;
proto_tree_add_text(subtree, tvb, curr_offset, 1, "S0 - S7");
curr_offset++;
consumed++;
break;
case 0xf:
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pt, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssap_speech_codec, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
consumed++;
proto_tree_add_item(subtree, hf_gsm_a_bssap_extended_codec, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, " - %s",
val_to_str_const(tvb_get_guint8(tvb, curr_offset),
bssap_extended_codec_values,
"Unknown"));
curr_offset++;
consumed++;
proto_tree_add_item(subtree, hf_gsm_a_bssap_extended_codec_r2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssap_extended_codec_r3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
consumed++;
break;
default:
proto_tree_add_text(subtree, tvb, curr_offset, 2,"Unknown codec - the rest of the dissection my be suspect");
curr_offset+=2;
consumed+=2;
break;
}
}
proto_item_set_len(item, consumed);
return(len);
}
static guint16
be_speech_codec(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, consumed = 0;
guint8 codec;
guint8 number = 0;
proto_item *item = NULL;
proto_tree *subtree = NULL;
curr_offset = offset;
while (curr_offset-offset < len) {
number++;
consumed = 0;
item = proto_tree_add_text(tree, tvb, curr_offset, 1, "Speech Codec Element %u",number);
subtree = proto_item_add_subtree(item, ett_codec_lst);
codec = tvb_get_guint8(tvb,curr_offset)&0x0f;
switch (codec) {
case 0:
case 1:
case 2:
proto_tree_add_item(subtree, hf_gsm_a_bssmap_fi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pt, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_tf, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssap_speech_codec, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, " - %s",
val_to_str_const(tvb_get_guint8(tvb, curr_offset) & 0x0f,
bssap_speech_codec_values,
"Unknown"));
curr_offset++;
consumed++;
break;
case 3:
case 4:
case 0xb:
proto_tree_add_item(subtree, hf_gsm_a_bssmap_fi2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pi2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pt2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_tf2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssap_speech_codec, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, " - %s",
val_to_str_const(tvb_get_guint8(tvb, curr_offset) & 0x0f,
bssap_speech_codec_values,
"Unknown"));
curr_offset++;
consumed++;
proto_tree_add_text(subtree, tvb, curr_offset, 2, "S0 - S15");
curr_offset+=2;
consumed+=2;
break;
case 0x9:
case 0xc:
case 0xd:
proto_tree_add_item(subtree, hf_gsm_a_bssmap_fi2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pi2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pt2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_tf2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssap_speech_codec, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, " - %s",
val_to_str_const(tvb_get_guint8(tvb, curr_offset) & 0x0f,
bssap_speech_codec_values,
"Unknown"));
curr_offset++;
consumed++;
proto_tree_add_text(subtree, tvb, curr_offset, 1, "S0 - S7");
curr_offset++;
consumed++;
break;
case 0xf:
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssmap_pt, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssap_speech_codec, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
consumed++;
proto_tree_add_item(subtree, hf_gsm_a_bssap_extended_codec, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
consumed++;
proto_tree_add_item(subtree, hf_gsm_a_bssap_extended_codec_r2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_bssap_extended_codec_r3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
consumed++;
break;
default:
proto_tree_add_text(subtree, tvb, curr_offset, 2, "Unknown codec - the rest of the dissection my be suspect");
curr_offset+=2;
consumed+=2;
break;
}
}
proto_item_set_len(item, consumed);
return(len);
}
static guint16
be_call_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_call_id, tvb, curr_offset, 4, ENC_LITTLE_ENDIAN);
curr_offset+=4;
return(curr_offset - offset);
}
static guint16
be_call_id_lst(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
if (len==0) {
proto_tree_add_text(tree, tvb, curr_offset, len, "all resources and references associated to all Call Identifiers in use between the BSC and the MSC need to be released");
}
while (curr_offset-offset < len) {
proto_tree_add_item(tree, hf_gsm_a_bssmap_call_id, tvb, curr_offset, 4, ENC_LITTLE_ENDIAN);
curr_offset+=4;
}
return(len);
}
static guint16
be_a_itf_sel_for_reset(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, (curr_offset<<3), 6, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_rip, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_bssmap_rtd, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_kc128(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_kc128, tvb, curr_offset, 16, ENC_NA);
curr_offset+=16;
return(curr_offset - offset);
}
static guint16
be_csg_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 bit_offset;
bit_offset = offset<<3;
proto_tree_add_split_bits_item_ret_val(tree, hf_gsm_a_bssmap_csg_id, tvb, bit_offset, gsm_a_bssmap_csg_id_crumbs, NULL);
bit_offset += 32;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_spare_bits, tvb, bit_offset, 7, ENC_BIG_ENDIAN);
bit_offset += 7;
proto_tree_add_bits_item(tree, hf_gsm_a_bssmap_cell_access_mode, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
return(len);
}
static guint16
be_reroute_rej_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_reroute_rej_cause, tvb, curr_offset, 1, ENC_NA);
curr_offset+=1;
return(curr_offset - offset);
}
static guint16
be_send_seqn(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_send_seqn, tvb, curr_offset, 1, ENC_NA);
curr_offset+=1;
return(curr_offset - offset);
}
static guint16
be_reroute_outcome(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_reroute_outcome, tvb, curr_offset, 1, ENC_NA);
curr_offset+=1;
return(curr_offset - offset);
}
static guint16
be_global_call_ref(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len, "Field Element not decoded yet");
return len;
}
static guint16
be_lcls_conf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_lcls_conf, tvb, curr_offset, 1, ENC_NA);
curr_offset+=1;
return(curr_offset - offset);
}
static guint16
be_lcls_con_status_control(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_lcls_con_status_control, tvb, curr_offset, 1, ENC_NA);
curr_offset+=1;
return(curr_offset - offset);
}
static guint16
be_lcls_bss_status(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_bssmap_lcls_bss_status, tvb, curr_offset, 1, ENC_NA);
curr_offset+=1;
return(curr_offset - offset);
}
static guint16
be_selected_plmn_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_string(tree, hf_gsm_a_bssmap_selected_plmn_id, tvb, offset, 3, dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, offset, TRUE));
return 3;
}
static guint16
be_fe_extra_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_fe_extra_info_prec, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fe_extra_info_lcs, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fe_extra_info_ue_prob, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fe_extra_info_spare, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_fe_cur_chan_type2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_fe_cur_chan_type2_chan_mode, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fe_cur_chan_type2_chan_mode_spare, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_fe_cur_chan_type2_chan_field, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fe_cur_chan_type2_chan_field_spare, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_fe_target_radio_cell_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_fe_target_radio_cell_info_rxlev_ncell, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fe_target_radio_cell_info_rxlev_ncell_spare, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_fe_gprs_suspend_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset = offset;
bssgp_suspend_ack(tvb, tree, pinfo, offset, len);
curr_offset += len;
return(curr_offset - offset);
}
static guint16
be_fe_dual_transfer_mode_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_fe_dtm_info_dtm_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fe_dtm_info_sto_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fe_dtm_info_egprs_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fe_dtm_info_spare_bits, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_fe_inter_rat_handover_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *container_tvb;
container_tvb = tvb_new_subset(tvb, offset, len, len);
dissect_rrc_InterRATHandoverInfo_PDU(container_tvb, pinfo, tree, NULL);
return len;
}
static guint16
be_fe_cell_load_info_group(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
curr_offset += be_cell_id(tvb, tree, pinfo, curr_offset, len, NULL, 0);
curr_offset += be_field_element_dissect(tvb, tree, pinfo, curr_offset, len + offset - curr_offset, NULL, 0);
return(curr_offset - offset);
}
static guint16
be_fe_cell_load_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_fe_cell_load_info_cell_capacity_class, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_fe_cell_load_info_load_value, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_fe_cell_load_info_rt_load_value, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_fe_cell_load_info_nrt_load_information_value, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_fe_ps_indication(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_fe_ps_indication, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_fe_dtm_ho_command_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_fe_dtm_ho_command_ind_spare, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
be_field_element_dissect(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, ie_len, fe_start_offset;
gint idx;
const gchar *str;
proto_item *item = NULL;
proto_tree * bss_to_bss_tree = NULL;
curr_offset = offset;
while (curr_offset - offset + 2 < len) {
guint8 oct;
oct = tvb_get_guint8(tvb, curr_offset++);
str = try_val_to_str_idx((guint32) oct, bssmap_field_element_ids, &idx);
ie_len = tvb_get_guint8(tvb, curr_offset++);
if (!str)
str = "Unknown";
item = proto_tree_add_uint_format(tree, hf_gsm_a_bssmap_field_elem_id,
tvb, curr_offset - 2, ie_len + 2, oct, "%s (%X)", str, oct);
bss_to_bss_tree = proto_item_add_subtree(item, ett_bss_to_bss_info);
fe_start_offset = curr_offset;
if (idx < 0 || idx >= NUM_BSS_ELEMENT_FCNS ||
(bssmap_bss_to_bss_element_fcn[idx] == NULL))
{
proto_tree_add_text(bss_to_bss_tree,
tvb, curr_offset, ie_len,
"Field Element not decoded");
curr_offset += ie_len;
}
else
{
curr_offset += (*bssmap_bss_to_bss_element_fcn[idx])(tvb, bss_to_bss_tree, pinfo, curr_offset, ie_len, NULL, 0);
EXTRANEOUS_DATA_CHECK_EXPERT(ie_len, curr_offset - fe_start_offset, pinfo, &ei_gsm_a_bssmap_extraneous_data);
}
}
return len;
}
static void
bssmap_ass_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CHAN_TYPE, GSM_A_PDU_TYPE_BSSMAP, BE_CHAN_TYPE, NULL);
ELEM_OPT_TLV(BE_L3_HEADER_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_L3_HEADER_INFO, NULL);
ELEM_OPT_TLV(BE_PRIO, GSM_A_PDU_TYPE_BSSMAP, BE_PRIO, NULL);
ELEM_OPT_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
ELEM_OPT_TV(BE_DOWN_DTX_FLAG, GSM_A_PDU_TYPE_BSSMAP, BE_DOWN_DTX_FLAG, NULL);
ELEM_OPT_TV(BE_INT_BAND, GSM_A_PDU_TYPE_BSSMAP, BE_INT_BAND, NULL);
ELEM_OPT_TLV(BE_CM_INFO_2, GSM_A_PDU_TYPE_BSSMAP, BE_CM_INFO_2, NULL);
ELEM_OPT_TLV(BE_GROUP_CALL_REF, GSM_A_PDU_TYPE_BSSMAP, BE_GROUP_CALL_REF, NULL);
ELEM_OPT_T(BE_TALKER_FLAG, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_FLAG, NULL);
ELEM_OPT_TV(BE_CONF_EVO_IND, GSM_A_PDU_TYPE_BSSMAP, BE_CONF_EVO_IND, NULL);
ELEM_OPT_TV(BE_LSA_ACC_CTRL, GSM_A_PDU_TYPE_BSSMAP, BE_LSA_ACC_CTRL, NULL);
ELEM_OPT_TLV(BE_SERV_HO, GSM_A_PDU_TYPE_BSSMAP, BE_SERV_HO, NULL);
ELEM_OPT_TLV(BE_ENC_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_ENC_INFO, NULL);
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
ELEM_OPT_TLV(BE_AOIP_TRANS_LAY_ADD, GSM_A_PDU_TYPE_BSSMAP, BE_AOIP_TRANS_LAY_ADD, NULL);
ELEM_OPT_TLV(BE_SPEECH_CODEC_LST, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC_LST, "(MSC Preferred)");
ELEM_OPT_TV(BE_CALL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CALL_ID, NULL);
ELEM_OPT_TV(BE_KC128, GSM_A_PDU_TYPE_BSSMAP, BE_KC128, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ass_complete(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TV(BE_RR_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_RR_CAUSE, NULL);
ELEM_OPT_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
ELEM_OPT_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_OPT_TV(BE_CHOSEN_CHAN, GSM_A_PDU_TYPE_BSSMAP, BE_CHOSEN_CHAN, NULL);
ELEM_OPT_TV(BE_CHOSEN_ENC_ALG, GSM_A_PDU_TYPE_BSSMAP, BE_CHOSEN_ENC_ALG, NULL);
ELEM_OPT_TV(BE_CCT_POOL, GSM_A_PDU_TYPE_BSSMAP, BE_CCT_POOL, NULL);
ELEM_OPT_TV(BE_SPEECH_VER, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_VER, " (Chosen)");
ELEM_OPT_TLV(BE_LSA_ID, GSM_A_PDU_TYPE_BSSMAP, BE_LSA_ID, NULL);
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
ELEM_OPT_TLV(BE_AOIP_TRANS_LAY_ADD, GSM_A_PDU_TYPE_BSSMAP, BE_AOIP_TRANS_LAY_ADD, NULL);
ELEM_OPT_TLV(BE_SPEECH_CODEC, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC, "(Chosen)");
ELEM_OPT_TLV(BE_SPEECH_CODEC_LST, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC_LST, "(BSS Supported)");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ass_failure(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_OPT_TV(BE_RR_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_RR_CAUSE, NULL);
ELEM_OPT_TV(BE_CCT_POOL, GSM_A_PDU_TYPE_BSSMAP, BE_CCT_POOL, NULL);
ELEM_OPT_TLV(BE_CCT_POOL_LIST, GSM_A_PDU_TYPE_BSSMAP, BE_CCT_POOL_LIST, NULL);
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
ELEM_OPT_TLV(BE_SPEECH_CODEC_LST, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC_LST, "(BSS Supported)");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_block(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_OPT_T(BE_CONN_REL_REQ, GSM_A_PDU_TYPE_BSSMAP, BE_CONN_REL_REQ, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_block_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_unblock(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_unblock_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ho_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CHAN_TYPE, GSM_A_PDU_TYPE_BSSMAP, BE_CHAN_TYPE, NULL);
ELEM_MAND_TLV(BE_ENC_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_ENC_INFO, NULL);
ELEM_OPT_TV(BE_CM_INFO_1, GSM_A_PDU_TYPE_BSSMAP, BE_CM_INFO_1, NULL);
ELEM_OPT_TLV(BE_CM_INFO_2, GSM_A_PDU_TYPE_BSSMAP, BE_CM_INFO_2, NULL);
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, " (Serving)");
ELEM_OPT_TLV(BE_PRIO, GSM_A_PDU_TYPE_BSSMAP, BE_PRIO, NULL);
ELEM_OPT_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
ELEM_OPT_TV(BE_DOWN_DTX_FLAG, GSM_A_PDU_TYPE_BSSMAP, BE_DOWN_DTX_FLAG, NULL);
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, " (Target)");
ELEM_OPT_TV(BE_INT_BAND, GSM_A_PDU_TYPE_BSSMAP, BE_INT_BAND, NULL);
ELEM_OPT_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_OPT_TLV(BE_CM_INFO_3, GSM_A_PDU_TYPE_BSSMAP, BE_CM_INFO_3, NULL);
ELEM_OPT_TV(BE_CURR_CHAN_1, GSM_A_PDU_TYPE_BSSMAP, BE_CURR_CHAN_1, NULL);
ELEM_OPT_TV(BE_SPEECH_VER, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_VER, " (Used)");
ELEM_OPT_TLV(BE_GROUP_CALL_REF, GSM_A_PDU_TYPE_BSSMAP, BE_GROUP_CALL_REF, NULL);
ELEM_OPT_T(BE_TALKER_FLAG, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_FLAG, NULL);
ELEM_OPT_TV(BE_CONF_EVO_IND, GSM_A_PDU_TYPE_BSSMAP, BE_CONF_EVO_IND, NULL);
ELEM_OPT_TV(BE_CHOSEN_ENC_ALG, GSM_A_PDU_TYPE_BSSMAP, BE_CHOSEN_ENC_ALG, " (Serving)");
ELEM_OPT_TLV(BE_OLD2NEW_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_OLD2NEW_INFO, NULL);
ELEM_OPT_TLV(BE_LSA_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_LSA_INFO, NULL);
ELEM_OPT_TV(BE_LSA_ACC_CTRL, GSM_A_PDU_TYPE_BSSMAP, BE_LSA_ACC_CTRL, NULL);
ELEM_OPT_TLV(BE_SERV_HO, GSM_A_PDU_TYPE_BSSMAP, BE_SERV_HO, NULL);
ELEM_OPT_TLV(BE_IMSI, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_OPT_TLV(BE_SRC_RNC_TO_TAR_RNC_UMTS, GSM_A_PDU_TYPE_BSSMAP, BE_SRC_RNC_TO_TAR_RNC_UMTS, NULL);
ELEM_OPT_TLV(BE_SRC_RNC_TO_TAR_RNC_CDMA, GSM_A_PDU_TYPE_BSSMAP, BE_SRC_RNC_TO_TAR_RNC_CDMA, NULL);
ELEM_OPT_TLV(BE_SNA_ACC_INF, GSM_A_PDU_TYPE_BSSMAP, BE_SNA_ACC_INF, NULL);
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
ELEM_OPT_TLV(BE_AOIP_TRANS_LAY_ADD, GSM_A_PDU_TYPE_BSSMAP, BE_AOIP_TRANS_LAY_ADD, NULL);
ELEM_OPT_TLV(BE_SPEECH_CODEC_LST, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC_LST, "(MSC Preferred)");
ELEM_OPT_TV(BE_CALL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CALL_ID, NULL);
ELEM_OPT_TV(BE_KC128, GSM_A_PDU_TYPE_BSSMAP, BE_KC128, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ho_reqd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_OPT_T(BE_RESP_REQ, GSM_A_PDU_TYPE_BSSMAP, BE_RESP_REQ, NULL);
ELEM_MAND_TLV(BE_CELL_ID_LIST, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID_LIST, " (Preferred)");
ELEM_OPT_TLV(BE_CCT_POOL_LIST, GSM_A_PDU_TYPE_BSSMAP, BE_CCT_POOL_LIST, NULL);
ELEM_OPT_TV(BE_CURR_CHAN_1, GSM_A_PDU_TYPE_BSSMAP, BE_CURR_CHAN_1, NULL);
ELEM_OPT_TV(BE_SPEECH_VER, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_VER, " (Used)");
ELEM_OPT_TV(BE_QUE_IND, GSM_A_PDU_TYPE_BSSMAP, BE_QUE_IND, NULL);
ELEM_OPT_TLV(BE_OLD2NEW_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_OLD2NEW_INFO, NULL);
ELEM_OPT_TLV(BE_SRC_RNC_TO_TAR_RNC_UMTS, GSM_A_PDU_TYPE_BSSMAP, BE_SRC_RNC_TO_TAR_RNC_UMTS, NULL);
ELEM_OPT_TLV(BE_SRC_RNC_TO_TAR_RNC_CDMA, GSM_A_PDU_TYPE_BSSMAP, BE_SRC_RNC_TO_TAR_RNC_CDMA, NULL);
ELEM_OPT_TLV(BE_GERAN_CLS_M, GSM_A_PDU_TYPE_BSSMAP, BE_GERAN_CLS_M, NULL);
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
ELEM_OPT_TLV(BE_SPEECH_CODEC, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC, "(Used)");
ELEM_OPT_TLV(BE_CSG_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CSG_ID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ho_req_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_L3_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_L3_INFO, NULL);
ELEM_OPT_TV(BE_CHOSEN_CHAN, GSM_A_PDU_TYPE_BSSMAP, BE_CHOSEN_CHAN, NULL);
ELEM_OPT_TV(BE_CHOSEN_ENC_ALG, GSM_A_PDU_TYPE_BSSMAP, BE_CHOSEN_ENC_ALG, NULL);
ELEM_OPT_TV(BE_CCT_POOL, GSM_A_PDU_TYPE_BSSMAP, BE_CCT_POOL, NULL);
ELEM_OPT_TV(BE_SPEECH_VER, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_VER, " (Chosen)");
ELEM_OPT_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
ELEM_OPT_TLV(BE_LSA_ID, GSM_A_PDU_TYPE_BSSMAP, BE_LSA_ID, NULL);
ELEM_OPT_TLV(BE_NEW_BSS_TO_OLD_BSS_INF, GSM_A_PDU_TYPE_BSSMAP, BE_NEW_BSS_TO_OLD_BSS_INF, NULL);
ELEM_OPT_TLV(BE_INTER_SYS_INF, GSM_A_PDU_TYPE_BSSMAP, BE_INTER_SYS_INF, NULL);
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
ELEM_OPT_TLV(BE_AOIP_TRANS_LAY_ADD, GSM_A_PDU_TYPE_BSSMAP, BE_AOIP_TRANS_LAY_ADD, NULL);
ELEM_OPT_TLV(BE_SPEECH_CODEC_LST, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC_LST, "(BSS Supported)");
ELEM_OPT_TLV(BE_SPEECH_CODEC, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC, "(Chosen)");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ho_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_L3_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_L3_INFO, NULL);
ELEM_OPT_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_OPT_TLV(BE_NEW_BSS_TO_OLD_BSS_INF, GSM_A_PDU_TYPE_BSSMAP, BE_NEW_BSS_TO_OLD_BSS_INF, NULL);
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ho_complete(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TV(BE_RR_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_RR_CAUSE, NULL);
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
ELEM_OPT_TLV(BE_SPEECH_CODEC, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC, "(Chosen)");
ELEM_OPT_TV(BE_CHOSEN_ENC_ALG, GSM_A_PDU_TYPE_BSSMAP, BE_CHOSEN_ENC_ALG, NULL);
ELEM_OPT_TV(BE_CHOSEN_CHAN, GSM_A_PDU_TYPE_BSSMAP, BE_CHOSEN_CHAN, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ho_succ(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ho_cand_enq(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_NUM_MS, GSM_A_PDU_TYPE_BSSMAP, BE_NUM_MS, NULL);
ELEM_MAND_TLV(BE_CELL_ID_LIST, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID_LIST, NULL);
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ho_cand_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_NUM_MS, GSM_A_PDU_TYPE_BSSMAP, BE_NUM_MS, NULL);
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ho_failure(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_OPT_TV(BE_RR_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_RR_CAUSE, NULL);
ELEM_OPT_TV(BE_CCT_POOL, GSM_A_PDU_TYPE_BSSMAP, BE_CCT_POOL, NULL);
ELEM_OPT_TLV(BE_CCT_POOL_LIST, GSM_A_PDU_TYPE_BSSMAP, BE_CCT_POOL_LIST, NULL);
ELEM_OPT_TLV(BE_GERAN_CLS_M, GSM_A_PDU_TYPE_BSSMAP, BE_GERAN_CLS_M, NULL);
ELEM_OPT_TLV(BE_NEW_BSS_TO_OLD_BSS_INF, GSM_A_PDU_TYPE_BSSMAP, BE_NEW_BSS_TO_OLD_BSS_INF, NULL);
ELEM_OPT_TLV(BE_INTER_SYS_INF, GSM_A_PDU_TYPE_BSSMAP, BE_INTER_SYS_INF, NULL);
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
ELEM_OPT_TLV(BE_SPEECH_CODEC_LST, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC_LST, "(BSS Supported)");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_res_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_PERIODICITY, GSM_A_PDU_TYPE_BSSMAP, BE_PERIODICITY, NULL);
ELEM_MAND_TV(BE_RES_IND_METHOD, GSM_A_PDU_TYPE_BSSMAP, BE_RES_IND_METHOD, NULL);
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_MAND_TV(BE_EXT_RES_IND, GSM_A_PDU_TYPE_BSSMAP, BE_EXT_RES_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_res_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_RES_IND_METHOD, GSM_A_PDU_TYPE_BSSMAP, BE_RES_IND_METHOD, NULL);
ELEM_MAND_TV(BE_RES_AVAIL, GSM_A_PDU_TYPE_BSSMAP, BE_RES_AVAIL, NULL);
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_MAND_TV(BE_TOT_RES_ACC, GSM_A_PDU_TYPE_BSSMAP, BE_TOT_RES_ACC, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_paging(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_IMSI, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_OPT_TLV(BE_TMSI, GSM_A_PDU_TYPE_BSSMAP, BE_TMSI, NULL);
ELEM_MAND_TLV(BE_CELL_ID_LIST, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID_LIST, NULL);
ELEM_OPT_TV(BE_CHAN_NEEDED, GSM_A_PDU_TYPE_BSSMAP, BE_CHAN_NEEDED, NULL);
ELEM_OPT_TV(BE_EMLPP_PRIO, GSM_A_PDU_TYPE_BSSMAP, BE_EMLPP_PRIO, NULL);
ELEM_OPT_TV(BE_PAGING_INF, GSM_A_PDU_TYPE_BSSMAP, BE_PAGING_INF, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_clear_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_clear_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(BE_L3_HEADER_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_L3_HEADER_INFO, NULL);
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_OPT_T(BE_CSFB_IND, GSM_A_PDU_TYPE_BSSMAP, BE_CSFB_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
void
bssmap_reset(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_OPT_TV(BE_A_ITF_SEL_FOR_RESET, GSM_A_PDU_TYPE_BSSMAP, BE_A_ITF_SEL_FOR_RESET, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
void
bssmap_reset_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TV(BE_A_ITF_SEL_FOR_RESET, GSM_A_PDU_TYPE_BSSMAP, BE_A_ITF_SEL_FOR_RESET, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ho_performed(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_OPT_TV(BE_CHOSEN_CHAN, GSM_A_PDU_TYPE_BSSMAP, BE_CHOSEN_CHAN, NULL);
ELEM_OPT_TV(BE_CHOSEN_ENC_ALG, GSM_A_PDU_TYPE_BSSMAP, BE_CHOSEN_ENC_ALG, NULL);
ELEM_OPT_TV(BE_SPEECH_VER, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_VER, " (Chosen)");
ELEM_OPT_TLV(BE_LSA_ID, GSM_A_PDU_TYPE_BSSMAP, BE_LSA_ID, NULL);
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
ELEM_OPT_TLV(BE_SPEECH_CODEC_LST, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC_LST, "(BSS Supported)");
ELEM_OPT_TLV(BE_SPEECH_CODEC, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC, "(Chosen)");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_overload(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_OPT_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_msc_invoke_trace(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_TRACE_TYPE, GSM_A_PDU_TYPE_BSSMAP, BE_TRACE_TYPE, NULL);
ELEM_OPT_TLV(BE_TRIGGERID, GSM_A_PDU_TYPE_BSSMAP, BE_TRIGGERID, NULL);
ELEM_MAND_TV(BE_TRACE_REF, GSM_A_PDU_TYPE_BSSMAP, BE_TRACE_REF, NULL);
ELEM_OPT_TLV(BE_TRANSID, GSM_A_PDU_TYPE_BSSMAP, BE_TRANSID, NULL);
ELEM_OPT_TLV(BE_MID, GSM_A_PDU_TYPE_BSSMAP, BE_MID, NULL);
ELEM_OPT_TLV(BE_OMCID, GSM_A_PDU_TYPE_BSSMAP, BE_OMCID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_bss_invoke_trace(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_TRACE_TYPE, GSM_A_PDU_TYPE_BSSMAP, BE_TRACE_TYPE, NULL);
ELEM_OPT_TV(BE_FOR_IND, GSM_A_PDU_TYPE_BSSMAP, BE_FOR_IND, NULL);
ELEM_OPT_TLV(BE_TRIGGERID, GSM_A_PDU_TYPE_BSSMAP, BE_TRIGGERID, NULL);
ELEM_MAND_TV(BE_TRACE_REF, GSM_A_PDU_TYPE_BSSMAP, BE_TRACE_REF, NULL);
ELEM_OPT_TLV(BE_TRANSID, GSM_A_PDU_TYPE_BSSMAP, BE_TRANSID, NULL);
ELEM_OPT_TLV(BE_OMCID, GSM_A_PDU_TYPE_BSSMAP, BE_OMCID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_cm_upd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CM_INFO_2, GSM_A_PDU_TYPE_BSSMAP, BE_CM_INFO_2, NULL);
ELEM_OPT_TLV(BE_CM_INFO_3, GSM_A_PDU_TYPE_BSSMAP, BE_CM_INFO_3, NULL);
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ciph_mode_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(BE_L3_HEADER_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_L3_HEADER_INFO, NULL);
ELEM_MAND_TLV(BE_ENC_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_ENC_INFO, NULL);
ELEM_OPT_TV(BE_CIPH_RESP_MODE, GSM_A_PDU_TYPE_BSSMAP, BE_CIPH_RESP_MODE, NULL);
ELEM_OPT_TV(BE_KC128, GSM_A_PDU_TYPE_BSSMAP, BE_KC128, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ciph_mode_complete(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(BE_L3_MSG, GSM_A_PDU_TYPE_BSSMAP, BE_L3_MSG, NULL);
ELEM_OPT_TV(BE_CHOSEN_ENC_ALG, GSM_A_PDU_TYPE_BSSMAP, BE_CHOSEN_ENC_ALG, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_cl3_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 consumed;
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_MAND_TLV(BE_L3_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_L3_INFO, NULL);
ELEM_OPT_TV(BE_CHOSEN_CHAN, GSM_A_PDU_TYPE_BSSMAP, BE_CHOSEN_CHAN, NULL);
ELEM_OPT_TLV(BE_LSA_ID_LIST, GSM_A_PDU_TYPE_BSSMAP, BE_LSA_ID_LIST, NULL);
ELEM_OPT_TLV_E(BE_APDU, GSM_A_PDU_TYPE_BSSMAP, BE_APDU, NULL);
ELEM_OPT_TLV(BE_SPEECH_CODEC_LST, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC_LST, "(BSS Supported)");
ELEM_OPT_T(BE_REDIR_ATT_FLG, GSM_A_PDU_TYPE_BSSMAP, BE_REDIR_ATT_FLG, NULL);
ELEM_OPT_TV(BE_SEND_SEQN, GSM_A_PDU_TYPE_BSSMAP, BE_SEND_SEQN, NULL);
ELEM_OPT_TLV(BE_IMSI, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_sapi_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 consumed;
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_DLCI, GSM_A_PDU_TYPE_BSSMAP, BE_DLCI, NULL);
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ho_reqd_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_OPT_TLV(BE_NEW_BSS_TO_OLD_BSS_INF, GSM_A_PDU_TYPE_BSSMAP, BE_NEW_BSS_TO_OLD_BSS_INF, NULL);
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_reset_cct(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_reset_cct_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ho_det(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_cct_group_block(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_MAND_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
ELEM_MAND_TLV(BE_CIC_LIST, GSM_A_PDU_TYPE_BSSMAP, BE_CIC_LIST, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_cct_group_block_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
ELEM_MAND_TLV(BE_CIC_LIST, GSM_A_PDU_TYPE_BSSMAP, BE_CIC_LIST, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_cct_group_unblock(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
ELEM_MAND_TLV(BE_CIC_LIST, GSM_A_PDU_TYPE_BSSMAP, BE_CIC_LIST, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_cct_group_unblock_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
ELEM_MAND_TLV(BE_CIC_LIST, GSM_A_PDU_TYPE_BSSMAP, BE_CIC_LIST, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_confusion(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_MAND_TLV(BE_DIAG, GSM_A_PDU_TYPE_BSSMAP, BE_DIAG, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_cls_m_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_unequipped_cct(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
ELEM_OPT_TLV(BE_CIC_LIST, GSM_A_PDU_TYPE_BSSMAP, BE_CIC_LIST, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_ciph_mode_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_load_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_TIME_IND, GSM_A_PDU_TYPE_BSSMAP, BE_TIME_IND, NULL);
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_MAND_TLV(BE_CELL_ID_LIST, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID_LIST, " (Target)");
ELEM_OPT_TLV(BE_RES_SIT, GSM_A_PDU_TYPE_BSSMAP, BE_RES_SIT, NULL);
ELEM_OPT_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_vgcs_vbs_setup(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_GROUP_CALL_REF, GSM_A_PDU_TYPE_BSSMAP, BE_GROUP_CALL_REF, NULL);
ELEM_OPT_TLV(BE_PRIO, GSM_A_PDU_TYPE_BSSMAP, BE_PRIO, NULL);
ELEM_OPT_TLV(BE_VGCS_FEAT_FLG, GSM_A_PDU_TYPE_BSSMAP, BE_VGCS_FEAT_FLG, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_vgcs_vbs_setup_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(BE_VGCS_FEAT_FLG, GSM_A_PDU_TYPE_BSSMAP, BE_VGCS_FEAT_FLG, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_vgcs_vbs_setup_refuse(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_vgcs_vbs_ass_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_CURR_CHAN_1, GSM_A_PDU_TYPE_BSSMAP, BE_CURR_CHAN_1, NULL);
ELEM_MAND_TV(BE_ASS_REQ, GSM_A_PDU_TYPE_BSSMAP, BE_ASS_REQ, NULL);
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_MAND_TLV(BE_GROUP_CALL_REF, GSM_A_PDU_TYPE_BSSMAP, BE_GROUP_CALL_REF, NULL);
ELEM_OPT_TLV(BE_PRIO, GSM_A_PDU_TYPE_BSSMAP, BE_PRIO, NULL);
ELEM_OPT_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
ELEM_OPT_TV(BE_DOWN_DTX_FLAG, GSM_A_PDU_TYPE_BSSMAP, BE_DOWN_DTX_FLAG, NULL);
ELEM_OPT_TLV(BE_ENC_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_ENC_INFO, NULL);
ELEM_OPT_TLV(BE_VSTK_RAND_INF, GSM_A_PDU_TYPE_BSSMAP, BE_VSTK_RAND_INF, NULL);
ELEM_OPT_TLV(BE_VSTK_INF, GSM_A_PDU_TYPE_BSSMAP, BE_VSTK_INF, NULL);
ELEM_OPT_TLV(BE_CELL_ID_LIST_SEG, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID_LIST_SEG, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_vgcs_vbs_ass_res(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TV(BE_CURR_CHAN_1, GSM_A_PDU_TYPE_BSSMAP, BE_CURR_CHAN_1, NULL);
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_OPT_TV(BE_CHOSEN_CHAN, GSM_A_PDU_TYPE_BSSMAP, BE_CHOSEN_CHAN, NULL);
ELEM_OPT_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
ELEM_OPT_TV(BE_CCT_POOL, GSM_A_PDU_TYPE_BSSMAP, BE_CCT_POOL, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_vgcs_vbs_ass_fail(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_OPT_TV(BE_CCT_POOL, GSM_A_PDU_TYPE_BSSMAP, BE_CCT_POOL, NULL);
ELEM_OPT_TLV(BE_CCT_POOL_LIST, GSM_A_PDU_TYPE_BSSMAP, BE_CCT_POOL_LIST, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_uplink_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_OPT_TLV(BE_L3_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_L3_INFO, NULL);
ELEM_OPT_TLV(BE_MID, GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_uplink_req_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
ELEM_OPT_T(BE_EMRG_SET_IND, GSM_A_PDU_TYPE_BSSMAP, BE_EMRG_SET_IND, NULL);
ELEM_MAND_TLV(BE_TALKER_ID, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_ID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_uplink_req_conf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_OPT_TLV(BE_TALKER_ID, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_ID, NULL);
ELEM_MAND_TLV(BE_L3_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_L3_INFO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_uplink_app_data(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_MAND_TLV(BE_L3_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_L3_INFO, NULL);
ELEM_MAND_TLV(BE_APP_DATA_INF, GSM_A_PDU_TYPE_BSSMAP, BE_APP_DATA_INF, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_uplink_rel_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_uplink_rej_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, "Current");
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, "Rejected");
ELEM_OPT_TLV(BE_TALKER_ID, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_ID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_uplink_rel_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_uplink_seized_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_OPT_TV(BE_TALKER_PRI, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_PRI, NULL);
ELEM_OPT_T(BE_EMRG_SET_IND, GSM_A_PDU_TYPE_BSSMAP, BE_EMRG_SET_IND, NULL);
ELEM_MAND_TLV(BE_TALKER_ID, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_ID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_sus(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_DLCI, GSM_A_PDU_TYPE_BSSMAP, BE_DLCI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_res(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_DLCI, GSM_A_PDU_TYPE_BSSMAP, BE_DLCI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_change_cct(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_change_cct_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_common_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_IMSI, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_OPT_TLV(BE_SNA_ACC_INF, GSM_A_PDU_TYPE_BSSMAP, BE_SNA_ACC_INF, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_lsa_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_LSA_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_LSA_INFO, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
void
bssmap_conn_oriented(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV_E(BE_APDU, GSM_A_PDU_TYPE_BSSMAP, BE_APDU, NULL);
ELEM_OPT_TLV(BE_SEG, GSM_A_PDU_TYPE_BSSMAP, BE_SEG, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_perf_loc_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_LOC_TYPE, GSM_A_PDU_TYPE_BSSMAP, BE_LOC_TYPE , NULL);
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_OPT_TLV(BE_CM_INFO_3, GSM_A_PDU_TYPE_BSSMAP, BE_CM_INFO_3, NULL);
ELEM_OPT_TLV(BE_LCS_CLIENT, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_LCS_CLIENT_TYPE, NULL);
ELEM_OPT_TV(BE_CHOSEN_CHAN, GSM_A_PDU_TYPE_BSSMAP, BE_CHOSEN_CHAN, NULL);
ELEM_OPT_TLV(BE_LCS_PRIO, GSM_A_PDU_TYPE_BSSMAP, BE_LCS_PRIO, NULL);
ELEM_OPT_TLV(BE_LCS_QOS, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_LCSQOS, NULL);
ELEM_OPT_TLV(BE_GPS_ASSIST_DATA, GSM_A_PDU_TYPE_BSSMAP, BE_GPS_ASSIST_DATA, NULL);
ELEM_OPT_TLV_E(BE_APDU, GSM_A_PDU_TYPE_BSSMAP, BE_APDU, NULL);
ELEM_OPT_TLV(BE_IMSI, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
ELEM_OPT_TLV(BE_IMEI, GSM_A_PDU_TYPE_BSSMAP, BE_IMEI, NULL);
ELEM_OPT_TLV(BE_GANSS_LOC_TYP, GSM_A_PDU_TYPE_BSSMAP, BE_GANSS_LOC_TYP, NULL);
ELEM_OPT_TLV(BE_GANSS_ASS_DTA, GSM_A_PDU_TYPE_BSSMAP, BE_GANSS_ASS_DTA, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_perf_loc_res(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(BE_LOC_EST, GSM_A_PDU_TYPE_BSSMAP, BE_LOC_EST, NULL);
ELEM_OPT_TLV(BE_POS_DATA, GSM_A_PDU_TYPE_BSSMAP, BE_POS_DATA, NULL);
ELEM_OPT_TLV(BE_DECIPH_KEYS, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_DECIPH_KEYS, NULL);
ELEM_OPT_TLV(BE_LCS_CAUSE, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_LCS_CAUSE, NULL);
ELEM_OPT_TLV(BE_VEL_EST, GSM_A_PDU_TYPE_BSSMAP, BE_VEL_EST, NULL);
ELEM_OPT_TLV(BE_GANSS_POS_DTA, GSM_A_PDU_TYPE_BSSMAP, BE_GANSS_POS_DTA, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
void
bssmap_perf_loc_abort(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(BE_LCS_CAUSE, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_LCS_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_chan_mod_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_vgcs_add_inf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_TALKER_ID, GSM_A_PDU_TYPE_BSSMAP, BE_TALKER_ID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_vgcs_vbs_area_cell_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(BE_CELL_ID_LIST_SEG, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID_LIST_SEG, NULL);
ELEM_MAND_TV(BE_ASS_REQ, GSM_A_PDU_TYPE_BSSMAP, BE_ASS_REQ, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_vgcs_vbs_assign_status(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(BE_CELL_ID_LST_SEG_F_EST_CELLS, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID_LST_SEG_F_EST_CELLS, NULL);
ELEM_OPT_TLV(BE_CELL_ID_LST_SEG_F_CELL_TB_EST, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID_LST_SEG_F_CELL_TB_EST, NULL);
ELEM_OPT_TLV(BE_CELL_ID_LST_SEG_F_REL_CELL, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID_LST_SEG_F_REL_CELL, NULL);
ELEM_OPT_TLV(BE_CELL_ID_LST_SEG_F_NOT_EST_CELL, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID_LST_SEG_F_NOT_EST_CELL, NULL);
ELEM_OPT_TLV(BE_VGS_VBS_CELL_STAT, GSM_A_PDU_TYPE_BSSMAP, BE_VGS_VBS_CELL_STAT, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_vgcs_sms(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_SMS_TO_VGCS, GSM_A_PDU_TYPE_BSSMAP, BE_SMS_TO_VGCS, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_notification_data(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_APP_DATA_INF, GSM_A_PDU_TYPE_BSSMAP, BE_APP_DATA_INF, NULL);
ELEM_MAND_TLV(BE_DATA_ID, GSM_A_PDU_TYPE_BSSMAP, BE_DATA_ID, NULL);
ELEM_MAND_TLV(BE_MSISDN, GSM_A_PDU_TYPE_BSSMAP, BE_MSISDN, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_int_ho_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_MAND_TLV(BE_CELL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_OPT_TLV(BE_AOIP_TRANS_LAY_ADD, GSM_A_PDU_TYPE_BSSMAP, BE_AOIP_TRANS_LAY_ADD, NULL);
ELEM_OPT_TLV(BE_SPEECH_CODEC_LST, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC_LST, "(BSS Supported)");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_int_ho_req_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_OPT_TLV(BE_SPEECH_CODEC_LST, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC_LST, "(BSS Supported)");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_int_ho_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(BE_SPEECH_CODEC, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC, "(Chosen)");
ELEM_OPT_TV(BE_CIC, GSM_A_PDU_TYPE_BSSMAP, BE_CIC, NULL);
ELEM_OPT_TLV(BE_AOIP_TRANS_LAY_ADD, GSM_A_PDU_TYPE_BSSMAP, BE_AOIP_TRANS_LAY_ADD, NULL);
ELEM_OPT_TV(BE_CALL_ID, GSM_A_PDU_TYPE_BSSMAP, BE_CALL_ID, NULL);
ELEM_OPT_TV(BE_DOWN_DTX_FLAG, GSM_A_PDU_TYPE_BSSMAP, BE_DOWN_DTX_FLAG, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_int_ho_enq(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(BE_SPEECH_CODEC, GSM_A_PDU_TYPE_BSSMAP, BE_SPEECH_CODEC, "(Chosen)");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_reset_ip_res(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_CAUSE, NULL);
ELEM_OPT_TLV(BE_CALL_ID_LST, GSM_A_PDU_TYPE_BSSMAP, BE_CALL_ID_LST, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_reset_ip_res_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(BE_CALL_ID_LST, GSM_A_PDU_TYPE_BSSMAP, BE_CALL_ID_LST, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_reroute_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BE_L3_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_L3_INFO, " (Initial)");
ELEM_MAND_TV(BE_REROUTE_REJ_CAUSE, GSM_A_PDU_TYPE_BSSMAP, BE_REROUTE_REJ_CAUSE, NULL);
ELEM_OPT_TLV(BE_L3_INFO, GSM_A_PDU_TYPE_BSSMAP, BE_L3_INFO, NULL);
ELEM_OPT_TV(BE_SEND_SEQN, GSM_A_PDU_TYPE_BSSMAP, BE_SEND_SEQN, NULL);
ELEM_OPT_TLV(BE_IMSI, GSM_A_PDU_TYPE_BSSMAP, BE_IMSI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_reroute_complete(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(BE_REROUTE_OUTCOME, GSM_A_PDU_TYPE_BSSMAP, BE_REROUTE_OUTCOME, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
void
dissect_bssmap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
static gsm_a_tap_rec_t tap_rec[4];
static gsm_a_tap_rec_t *tap_p;
static guint tap_current = 0;
guint8 oct;
guint32 offset, saved_offset;
guint32 len;
gint idx;
proto_item *bssmap_item = NULL;
proto_tree *bssmap_tree = NULL;
const gchar *str;
sccp_msg_info_t* sccp_msg_p;
sccp_msg_p = pinfo->sccp_info;
if (!(sccp_msg_p && sccp_msg_p->data.co.assoc)) {
sccp_msg_p = NULL;
}
col_append_str(pinfo->cinfo, COL_INFO, "(BSSMAP) ");
tap_current++;
if (tap_current >= 4)
{
tap_current = 0;
}
tap_p = &tap_rec[tap_current];
offset = 0;
saved_offset = offset;
g_tree = tree;
len = tvb_length(tvb);
oct = tvb_get_guint8(tvb, offset++);
str = try_val_to_str_idx_ext((guint32) oct, &gsm_a_bssmap_msg_strings_ext, &idx);
if (sccp_msg_p && !sccp_msg_p->data.co.label) {
sccp_msg_p->data.co.label = wmem_strdup(wmem_file_scope(),
val_to_str_ext((guint32)oct,
&gsm_a_bssmap_msg_strings_ext,
"BSSMAP (0x%02x)"));
}
if (str == NULL || idx < 0 || idx >= NUM_GSM_BSSMAP_MSG)
{
bssmap_item =
proto_tree_add_protocol_format(tree, proto_a_bssmap, tvb, 0, len,
"GSM A-I/F BSSMAP - Unknown BSSMAP Message Type (0x%02x)",
oct);
bssmap_tree = proto_item_add_subtree(bssmap_item, ett_bssmap_msg);
}
else
{
bssmap_item =
proto_tree_add_protocol_format(tree, proto_a_bssmap, tvb, 0, -1,
"GSM A-I/F BSSMAP - %s",
str);
bssmap_tree = proto_item_add_subtree(bssmap_item, ett_gsm_bssmap_msg[idx]);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", str);
proto_tree_add_uint_format(bssmap_tree, hf_gsm_a_bssmap_msg_type,
tvb, saved_offset, 1, oct, "Message Type %s",str);
}
tap_p->pdu_type = GSM_A_PDU_TYPE_BSSMAP;
tap_p->message_type = oct;
tap_queue_packet(gsm_a_tap, pinfo, tap_p);
if (str == NULL) return;
if ((len - offset) <= 0) return;
if (idx < 0 || idx >= NUM_BSSMAP_MSG_FCNS || bssmap_msg_fcn[idx] == NULL) {
proto_tree_add_text(bssmap_tree,
tvb, offset, len - offset,
"Message Elements");
}else{
if (sccp_msg_p && ((sccp_msg_p->data.co.assoc->app_info & 0xCD00) == 0xCD00)) {
cell_discriminator = sccp_msg_p->data.co.assoc->app_info & 0xFF;
}else{
cell_discriminator = 0xFF;
}
(*bssmap_msg_fcn[idx])(tvb, bssmap_tree, pinfo, offset, len - offset);
if (sccp_msg_p) {
sccp_msg_p->data.co.assoc->app_info = cell_discriminator | 0xCDF0;
}
}
g_tree = NULL;
}
void
proto_register_gsm_a_bssmap(void)
{
guint i;
guint last_offset;
static hf_register_info hf[] =
{
{ &hf_gsm_a_bssmap_msg_type,
{ "BSSMAP Message Type", "gsm_a.bssmap.msgtype",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &gsm_a_bssmap_msg_strings_ext, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_elem_id,
{ "Element ID", "gsm_a.bssmap.elem_id",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_field_elem_id,
{ "Field Element ID", "gsm_a.bssmap.field_elem_id",
FT_UINT8, BASE_HEX, VALS(bssmap_field_element_ids), 0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_cell_ci,
{ "Cell CI", "gsm_a.bssmap.cell_ci",
FT_UINT16, BASE_HEX_DEC, 0, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_cell_lac,
{ "Cell LAC", "gsm_a.bssmap.cell_lac",
FT_UINT16, BASE_HEX_DEC, 0, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_sac,
{ "SAC", "gsm_a.bssmap.sac",
FT_UINT16, BASE_HEX, 0, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_dlci_cc,
{ "Control Channel", "gsm_a.bssmap.dlci.cc",
FT_UINT8, BASE_HEX, VALS(bssap_cc_values), 0xc0,
NULL, HFILL}
},
{ &hf_gsm_a_bssmap_dlci_spare,
{ "Spare", "gsm_a.bssmap.dlci.spare",
FT_UINT8, BASE_HEX, NULL, 0x38,
NULL, HFILL}
},
{ &hf_gsm_a_bssmap_dlci_sapi,
{ "SAPI", "gsm_a.bssmap.dlci.sapi",
FT_UINT8, BASE_HEX, VALS(bssap_sapi_values), 0x07,
NULL, HFILL}
},
{ &hf_gsm_a_bssmap_cause,
{ "BSSMAP Cause", "gsm_a.bssmap.cause",
FT_UINT8, BASE_HEX, 0, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_be_cell_id_disc,
{ "Cell identification discriminator","gsm_a.bssmap.be.cell_id_disc",
FT_UINT8,BASE_DEC|BASE_EXT_STRING, &gsm_a_be_cell_id_disc_vals_ext, 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_pci,
{ "Preemption Capability indicator(PCI)","gsm_a.bssmap.pci",
FT_BOOLEAN,8, TFS(&bssmap_pci_value), 0x40,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_qa,
{ "Queuing Allowed Indicator(QA)","gsm_a.bssmap.qa",
FT_BOOLEAN,8, TFS(&tfs_allowed_not_allowed), 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_pvi,
{ "Preemption Vulnerability Indicator(PVI)","gsm_a.bssmap.pvi",
FT_BOOLEAN,8, TFS(&bssmap_pvi_value), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_interference_bands,
{ "Acceptable interference bands","gsm_a.bssmap.interference_bands",
FT_UINT8, BASE_HEX, NULL, 0x01f,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_lsa_only,
{ "LSA only","gsm_a.bssmap.lsa_only",
FT_BOOLEAN,8, TFS(&bssmap_lsa_only_value), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_act,
{ "Active mode support","gsm_a.bssmap.act",
FT_BOOLEAN,8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_pref,
{ "Preferential access","gsm_a.bssmap.pref",
FT_BOOLEAN,8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_lsa_inf_prio,
{ "Priority","gsm_a.bssmap.lsa_inf_prio",
FT_UINT8,BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_seq_len,
{ "Sequence Length","gsm_a.bssmap.seq_len",
FT_UINT8,BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_seq_no,
{ "Sequence Number","gsm_a.bssmap.seq_no",
FT_UINT8,BASE_DEC, NULL, 0xf,
NULL, HFILL }
},
{ &hf_gsm_a_bssap_cell_id_list_seg_cell_id_disc,
{ "Cell identification discriminator","gsm_a.bssmap.cell_id_list_seg_cell_id_disc",
FT_UINT8,BASE_DEC, VALS(gsm_a_bssap_cell_id_list_seg_cell_id_disc_vals), 0xf,
NULL, HFILL }
},
{ &hf_gsm_a_bssap_res_ind_method,
{ "Resource indication method","gsm_a.bssmap.res_ind_method",
FT_UINT8,BASE_DEC, VALS(gsm_a_bssap_resource_indication_vals), 0xf,
NULL, HFILL }
},
{ &hf_gsm_a_bssap_cic_list_range,
{ "Range","gsm_a.bssmap.cic_list_range",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_bssap_cic_list_status,
{ "Status","gsm_a.bssmap.cic_list_status",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_bssap_diag_error_pointer,
{ "Error pointer","gsm_a.bssmap.diag_error_pointer",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_bssap_diag_msg_rcv,
{ "Message received","gsm_a.bssmap.cic_list_status",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_ch_mode,
{ "Channel mode","gsm_a.bssmap.cch_mode",
FT_UINT8,BASE_DEC, VALS(gsm_a_bssmap_ch_mode_vals), 0xf0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_cur_ch_mode,
{ "Channel Mode", "gsm_a.bssmap.fe_cur_chan_type2.chan_mode",
FT_UINT8, BASE_HEX, VALS(chan_mode_vals), 0xf0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_channel,
{ "Channel","gsm_a.bssmap.channel",
FT_UINT8,BASE_DEC, VALS(gsm_a_bssmap_channel_vals), 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_trace_trigger_id,
{ "Priority Indication","gsm_a.bssmap.trace_trigger_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_trace_priority_indication,
{ "Priority Indication","gsm_a.bssmap.trace_priority_indication",
FT_UINT8,BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_trace_bss_record_type,
{ "BSS Record Type","gsm_a.bssmap.bss_record__type",
FT_UINT8,BASE_DEC, VALS(gsm_a_bssmap_trace_bss_record_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_trace_msc_record_type,
{ "MSC Record Type","gsm_a.bssmap.msc_record_type",
FT_UINT8,BASE_DEC, VALS(gsm_a_bssmap_trace_msc_record_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_trace_invoking_event,
{ "Invoking Event","gsm_a.bssmap.trace_invoking_event",
FT_UINT8,BASE_DEC, VALS(gsm_a_bssmap_trace_invoking_event_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_trace_reference,
{ "Trace Reference","gsm_a.bssmap.trace_id",
FT_UINT16,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_trace_omc_id,
{ "OMC ID","gsm_a.bssmap.trace_omc_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_be_rnc_id,
{ "RNC-ID","gsm_a.bssmap.be.rnc_id",
FT_UINT16,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_apdu_protocol_id,
{ "Protocol ID", "gsm_a.bssmap.apdu_protocol_id",
FT_UINT8, BASE_DEC, VALS(gsm_a_apdu_protocol_id_strings), 0x0,
"APDU embedded protocol id", HFILL }
},
{ &hf_gsm_a_bssmap_periodicity,
{ "Periodicity", "gsm_a.bssmap.periodicity",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_sm,
{ "Subsequent Mode","gsm_a.bssmap.sm",
FT_BOOLEAN,8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_tarr,
{ "Total Accessible Resource Requested","gsm_a.bssmap.tarr",
FT_BOOLEAN,8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_tot_no_of_fullr_ch,
{ "Total number of accessible full rate channels", "gsm_a.bssmap.tot_no_of_fullr_ch",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_tot_no_of_hr_ch,
{ "Total number of accessible half rate channels", "gsm_a.bssmap.tot_no_of_hr_ch",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_lsa_id,
{ "Identification of Localised Service Area", "gsm_a.bssmap.lsa_id",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_ep,
{ "EP", "gsm_a.bssmap.ep",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_smi,
{ "Subsequent Modification Indication(SMI)", "gsm_a.bssmap.smi",
FT_UINT8, BASE_DEC, VALS(gsm_a_bssmap_smi_vals), 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_lcs_pri,
{ "Periodicity", "gsm_a.bssmap.lcs_pri",
FT_UINT8, BASE_DEC, VALS(lcs_priority_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_num_ms,
{ "Number of handover candidates", "gsm_a.bssmap.num_ms",
FT_UINT8, BASE_DEC,NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_talker_pri,
{ "Priority", "gsm_a.bssmap.talker_pri",
FT_UINT8, BASE_DEC,VALS(gsm_a_bssmap_talker_pri_vals), 0x03,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_rr_mode,
{ "RR mode", "gsm_a.bssmap.rr_mode",
FT_UINT8, BASE_DEC, VALS(gsm_a_bssmap_rr_mode_vals), 0xc0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_group_cipher_key_nb,
{ "Group cipher key number", "gsm_a.bssmap.group_cipher_key_nb",
FT_UINT8, BASE_DEC, VALS(gsm_a_bssmap_group_cipher_key_nb_vals), 0x3c,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_vgcs_vbs_cell_status,
{ "Status", "gsm_a.bssmap.vgcs_vbs_cell_status",
FT_UINT8, BASE_DEC, VALS(gsm_a_bssmap_vgcs_vbs_cell_status_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_paging_cause,
{ "Paging Cause", "gsm_a.bssmap.paging_cause",
FT_UINT8, BASE_DEC,VALS(gsm_a_bssmap_paging_cause_vals), 0x06,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_paging_inf_flg,
{ "VGCS/VBS flag","gsm_a.bssmap.paging_inf_flg",
FT_BOOLEAN,8, TFS(&bssmap_paging_inf_flg_value), 0x01,
"If 1, a member of a VGCS/VBS-group", HFILL }
},
{ &hf_gsm_a_bssmap_serv_ho_inf,
{ "Service Handover information", "gsm_a.bssmap.serv_ho_inf",
FT_UINT8, BASE_HEX, NULL, 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_max_nb_traffic_chan,
{ "Maximum Number of Traffic Channels", "gsm_a.bssmap.max_nb_traffic_chan",
FT_UINT8, BASE_DEC, VALS(gsm_a_max_nb_traffic_chan_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_acceptable_chan_coding_bit5,
{ "TCH/F43.2", "gsm_a.bssmap.acceptable_chan_coding_bit5",
FT_BOOLEAN, 8, TFS(&gsm_a_bssmap_accept_not_accept_vals), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_acceptable_chan_coding_bit4,
{ "TCH/F43.2", "gsm_a.bssmap.acceptable_chan_coding_bit4",
FT_BOOLEAN, 8, TFS(&gsm_a_bssmap_accept_not_accept_vals), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_acceptable_chan_coding_bit3,
{ "TCH/F43.2", "gsm_a.bssmap.acceptable_chan_coding_bit3",
FT_BOOLEAN, 8, TFS(&gsm_a_bssmap_accept_not_accept_vals), 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_acceptable_chan_coding_bit2,
{ "TCH/F43.2", "gsm_a.bssmap.acceptable_chan_coding_bit2",
FT_BOOLEAN, 8, TFS(&gsm_a_bssmap_accept_not_accept_vals), 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_acceptable_chan_coding_bit1,
{ "TCH/F43.2", "gsm_a.bssmap.acceptable_chan_coding_bit1",
FT_BOOLEAN, 8, TFS(&gsm_a_bssmap_accept_not_accept_vals), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_allowed_data_rate_bit8,
{ "43.5 kbit/s (TCH/F43.2)", "gsm_a.bssmap.allowed_data_rate_bit8",
FT_BOOLEAN, 8, TFS(&tfs_allowed_not_allowed), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_allowed_data_rate_bit7,
{ "32.0 kbit/s (TCH/F32.0)", "gsm_a.bssmap.allowed_data_rate_bit7",
FT_BOOLEAN, 8, TFS(&tfs_allowed_not_allowed), 0x40,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_allowed_data_rate_bit6,
{ "29.0 kbit/s (TCH/F28.8)", "gsm_a.bssmap.allowed_data_rate_bit6",
FT_BOOLEAN, 8, TFS(&tfs_allowed_not_allowed), 0x20,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_allowed_data_rate_bit5,
{ "14.5/14.4 kbit/s (TCH/F14.4)", "gsm_a.bssmap.allowed_data_rate_bit5",
FT_BOOLEAN, 8, TFS(&tfs_allowed_not_allowed), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_allowed_data_rate_bit4,
{ "12.0/9.6 kbit/s (TCH F/9.6)", "gsm_a.bssmap.allowed_data_rate_bit4",
FT_BOOLEAN, 8, TFS(&tfs_allowed_not_allowed), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_vstk_rand,
{ "VSTK_RAND", "gsm_a.bssmap.vstk_rand",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_vstk,
{ "VSTK", "gsm_a.bssmap.vstk",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_spare_bits,
{ "Spare bit(s)", "gsm_a.bssmap.spare_bits",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_tpind,
{ "Talker priority indicator (TP Ind)","gsm_a.bssmap.tpind",
FT_BOOLEAN,8, TFS(&gsm_bssmap_tpind_vals), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_asind_b2,
{ "A-interface resource sharing indicator (AS Ind) bit 2","gsm_a.bssmap.asind_b2",
FT_BOOLEAN,8, TFS(&gsm_bssmap_asind_b2_vals), 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_asind_b3,
{ "A-interface resource sharing indicator (AS Ind) bit 3","gsm_a.bssmap.asind_b3",
FT_BOOLEAN,8, TFS(&gsm_bssmap_asind_b3_vals), 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_bss_res,
{ "Group or broadcast call re-establishment by the BSS indicator","gsm_a.bssmap.bss_res",
FT_BOOLEAN,8, TFS(&gsm_bssmap_bss_res_vals), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_tcp,
{ "Talker Channel Parameter (TCP)","gsm_a.bssmap.tcp",
FT_BOOLEAN,8, TFS(&gsm_bssmap_bss_tcp_vals), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_filler_bits,
{ "Filler Bits","gsm_a.bssmap.filler_bits",
FT_UINT8, BASE_DEC,NULL, 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_method,
{ "Method","gsm_a.bssmap.method",
FT_UINT8, BASE_DEC,VALS(gsm_a_bssmap_method_vals), 0xc0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_ganss_id,
{ "GANSS Id","gsm_a.bssmap.ganss_id",
FT_UINT8, BASE_DEC,VALS(gsm_a_bssmap_ganss_id_vals), 0x38,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_usage,
{ "Usage","gsm_a.bssmap.usage",
FT_UINT8, BASE_DEC,VALS(gsm_a_bssmap_usage_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_data_id,
{ "Data Identity","gsm_a.bssmap.data_id",
FT_UINT8, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_bt_ind,
{ "BT Ind","gsm_a.bssmap.bt_ind",
FT_BOOLEAN, 8, TFS(&gsm_a_bssmap_bt_ind_val), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_aoip_trans_ipv4,
{ "Transport Layer Address (IPv4)","gsm_a.bssmap.aoip_trans_ipv4",
FT_IPv4,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_aoip_trans_ipv6,
{ "Transport Layer Address (IPv6)","gsm_a.bssmap.aoip_trans_ipv6",
FT_IPv6,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_aoip_trans_port,
{ "UDP Port","gsm_a.bssmap.aoip_trans_port",
FT_UINT16, BASE_DEC,NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_fi,
{ "FI(Full IP)","gsm_a.bssmap.fi",
FT_BOOLEAN,8, TFS(&bssmap_fi_vals), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_pi,
{ "PI","gsm_a.bssmap.pi",
FT_BOOLEAN,8, TFS(&bssmap_pi_vals), 0x40,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_pt,
{ "PT","gsm_a.bssmap.pt",
FT_BOOLEAN,8, TFS(&bssmap_pt_vals), 0x20,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_tf,
{ "TF","gsm_a.bssmap.tf",
FT_BOOLEAN,8, TFS(&bssmap_tf_vals), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_bssap_speech_codec,
{ "Codec Type","gsm_a.bssmap.speech_codec",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &bssap_speech_codec_values_ext, 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_bssap_extended_codec,
{ "Extended Codec Type","gsm_a.bssmap.extended_codec",
FT_UINT8, BASE_DEC, VALS(bssap_extended_codec_values), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssap_extended_codec_r2,
{ "Redundancy Level 2","gsm_a.bssmap.r2",
FT_BOOLEAN,8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_bssap_extended_codec_r3,
{ "Redundancy Level 3","gsm_a.bssmap.r3",
FT_BOOLEAN,8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_fi2,
{ "FI(Full IP)","gsm_a.bssmap.fi2",
FT_BOOLEAN,8, TFS(&bssmap_fi2_vals), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_pi2,
{ "PI","gsm_a.bssmap.pi2",
FT_BOOLEAN,8, TFS(&bssmap_pi2_vals), 0x40,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_pt2,
{ "PT","gsm_a.bssmap.pt2",
FT_BOOLEAN,8, TFS(&bssmap_pt2_vals), 0x20,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_tf2,
{ "TF","gsm_a.bssmap.tf2",
FT_BOOLEAN,8, TFS(&bssmap_tf2_vals), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_call_id,
{ "Call Identifier","gsm_a.bssmap.callid",
FT_UINT32, BASE_DEC,NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_spare,
{ "Spare", "gsm_a.bssmap.spare",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_bssmap_positioning_data_discriminator,
{ "Positioning Data Discriminator", "gsm_a.bssmap.posData.discriminator",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_positioning_method,
{ "Positioning method", "gsm_a.bssmap.posData.method",
FT_UINT8, BASE_HEX, VALS(bssmap_positioning_methods), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_positioning_method_usage,
{ "Usage", "gsm_a.bssmap.posData.usage",
FT_UINT8, BASE_HEX, VALS(bssmap_positioning_methods_usage), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_location_type_location_information,
{ "Location Information", "gsm_a.bssmap.locationType.locationInformation",
FT_UINT8, BASE_HEX, VALS(bssmap_location_information_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_location_type_positioning_method,
{ "Positioning Method", "gsm_a.bssmap.locationType.positioningMethod",
FT_UINT8, BASE_HEX, VALS(bssmap_positioning_method_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_chan_type_extension,
{ "Extension", "gsm_a.bssmap.chanType.permittedIndicator.extension",
FT_BOOLEAN, 8, TFS(&bssmap_chan_type_extension_value), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_cause_extension,
{ "Extension", "gsm_a.bssmap.causeType.extension",
FT_BOOLEAN, 8, TFS(&bssmap_cause_extension_value), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_emlpp_prio,
{ "eMLPP Priority", "gsm_a.bssmap.emlpp_priority",
FT_UINT8, BASE_HEX, VALS(gsm_a_bssmap_call_priority_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_rip,
{ "RIP", "gsm_a.bssmap.rip",
FT_BOOLEAN, 8, TFS(&gsm_a_bssmap_rip_value), 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_rtd,
{ "RTD", "gsm_a.bssmap.rtd",
FT_BOOLEAN, 8, TFS(&gsm_a_bssmap_rtd_value), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_kc128,
{ "Kc128", "gsm_a.bssmap.kc128",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_csg_id,
{ "CSG Identity", "gsm_a.bssmap.csg_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_cell_access_mode,
{ "Cell Access Mode", "gsm_a.bssmap.cell_access_mode",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_bssmap_cell_access_mode_value), 0,
NULL, HFILL }
},
{ &hf_fe_extra_info_prec,
{ "Pre-emption Recommendation", "gsm_a.bssmap.fe_extra_info.prec",
FT_UINT8, BASE_DEC, VALS(fe_extra_info_prec_vals), 0x01,
NULL, HFILL }
},
{ &hf_fe_extra_info_lcs,
{ "LCS Information", "gsm_a.bssmap.fe_extra_info.lcs",
FT_UINT8, BASE_DEC, VALS(fe_extra_info_lcs_vals), 0x02,
NULL, HFILL }
},
{ &hf_fe_extra_info_ue_prob,
{ "UE support of UMTS", "gsm_a.bssmap.fe_extra_info.ue_prob",
FT_UINT8, BASE_DEC, VALS(fe_extra_info_ue_prob_vals), 0x04,
NULL, HFILL }
},
{ &hf_fe_extra_info_spare,
{ "Extra Information Spare bits", "gsm_a.bssmap.fe_extra_info.spare",
FT_UINT8, BASE_HEX, NULL, 0xf8,
NULL, HFILL }
},
{ &hf_fe_cur_chan_type2_chan_mode,
{ "Channel Mode", "gsm_a.bssmap.fe_cur_chan_type2.chan_mode",
FT_UINT8, BASE_HEX, VALS(chan_mode_vals), 0x0f,
NULL, HFILL }
},
{ &hf_fe_cur_chan_type2_chan_mode_spare,
{ "Channel Mode Spare bits", "gsm_a.bssmap.fe_cur_chan_type2_chan_mode.spare",
FT_UINT8, BASE_HEX, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_fe_cur_chan_type2_chan_field,
{ "Channel Field", "gsm_a.bssmap.fe_cur_chan_type2.chan_field",
FT_UINT8, BASE_HEX, VALS(fe_cur_chan_type2_chan_field_vals),0x0f,
NULL, HFILL }
},
{ &hf_fe_cur_chan_type2_chan_field_spare,
{ "Channel field Spare bits", "gsm_a.bssmap.fe_cur_chan_type2_chan_field.spare",
FT_UINT8, BASE_HEX, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_fe_target_radio_cell_info_rxlev_ncell,
{ "RXLEV-NCELL", "gsm_a.bssmap.fe_target_radio_cell_info.rxlev_ncell",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &gsm_a_rr_rxlev_vals_ext, 0x3f,
NULL, HFILL }
},
{ &hf_fe_target_radio_cell_info_rxlev_ncell_spare,
{ "RXLEV-NCELL Spare bits", "gsm_a.bssmap.fe_target_radio_cell_info.rxlev_ncell_spare",
FT_UINT8, BASE_HEX, NULL, 0xc0,
NULL, HFILL }
},
{ &hf_fe_dtm_info_dtm_ind,
{ "DTM indicator", "gsm_a.bssmap.fe_dtm_info.dtm_ind",
FT_UINT8, BASE_HEX, VALS(gsm_a_bssmap_dtm_info_dtm_ind_vals), 0x01,
NULL, HFILL }
},
{ &hf_fe_dtm_info_sto_ind,
{ "Time Slot Operation indicator", "gsm_a.bssmap.fe_dtm_info.sto_ind",
FT_UINT8, BASE_HEX, VALS(gsm_a_bssmap_dtm_info_sto_ind_vals), 0x02,
NULL, HFILL }
},
{ &hf_fe_dtm_info_egprs_ind,
{ "EGPRS indicator", "gsm_a.bssmap.fe_dtm_info.egprs_ind",
FT_UINT8, BASE_HEX, VALS(gsm_a_bssmap_dtm_info_egprs_ind_vals), 0x04,
NULL, HFILL }
},
{ &hf_fe_dtm_info_spare_bits,
{ "DTM Info Spare bits", "gsm_a.bssmap.fe_dtm_info.spare_bits",
FT_UINT8, BASE_HEX, NULL, 0xf8,
NULL, HFILL }
},
{ &hf_fe_cell_load_info_cell_capacity_class,
{ "Cell capacity class", "gsm_a.bssmap.fe_cell_load_info.cell_capacity_class",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_fe_cell_load_info_load_value,
{ "Load value", "gsm_a.bssmap.fe_cell_load_info.load_info",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_fe_cell_load_info_rt_load_value,
{ "Realtime load value", "gsm_a.bssmap.fe_cell_load_info.rt_load_value",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_fe_cell_load_info_nrt_load_information_value,
{ "Non-Realtime load information value", "gsm_a.bssmap.fe_cell_load_info.nrt_load_info_value",
FT_UINT8, BASE_HEX, VALS(gsm_a_bssmap_cell_load_nrt_vals), 0,
NULL, HFILL }
},
{ &hf_fe_ps_indication,
{ "PS Indication", "gsm_a.bssmap.fe_ps_indication.value",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_fe_dtm_ho_command_ind_spare,
{ "Spare octet", "gsm_a.bssmap.fe_dtm_ho_command_ind.spare",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_speech_data_ind,
{ "Speech/Data Indicator", "gsm_a.bssmap.speech_data_ind",
FT_UINT8, BASE_DEC, VALS(gsm_a_bssap_speech_data_ind_vals), 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_channel_rate_and_type,
{ "Channel Rate and Type", "gsm_a.bssmap.perm_speech_v_ind",
FT_UINT8, BASE_DEC, VALS(gsm_a_bssap_channel_rate_and_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_perm_speech_v_ind,
{ "Permitted speech version indication", "gsm_a.bssmap.perm_speech_v_ind",
FT_UINT8, BASE_HEX, VALS(gsm_a_bssap_perm_speech_v_ind_vals), 0x7f,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_reroute_rej_cause,
{ "Reroute Reject cause", "gsm_a.bssmap.reroute_rej_cause",
FT_UINT8, BASE_HEX, VALS(gsm_a_bssap_reroute_rej_cause_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_send_seqn,
{ "Send Sequence Number", "gsm_a.bssmap.reroute_rej_cause",
FT_UINT8, BASE_HEX, NULL, 0xc0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_reroute_outcome,
{ "Outcome", "gsm_a.bssmap.reroute_outcome",
FT_UINT8, BASE_HEX, VALS(gsm_a_bssap_reroute_outcome_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_lcls_conf,
{ "LCLS-Configuration", "gsm_a.bssmap.lcls_conf",
FT_UINT8, BASE_HEX, VALS(gsm_a_bssap_lcls_conf_vals), 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_lcls_con_status_control,
{ "LCLS-Connection-Status-Control", "gsm_a.bssmap.lcls_con_status_control",
FT_UINT8, BASE_HEX, VALS(gsm_a_bssap_lcls_con_status_control_vals), 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_lcls_bss_status,
{ "LCLS-BSS-Status", "gsm_a.bssmap.lcls_bss_status",
FT_UINT8, BASE_HEX, VALS(gsm_a_bssmap_lcls_bss_status_vals), 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_bssmap_selected_plmn_id,
{ "Selected PLMN ID", "gsm_a.bssmap.selected_plmn_id",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
};
expert_module_t* expert_gsm_a_bssmap;
static ei_register_info ei[] = {
{ &ei_gsm_a_bssmap_extraneous_data, { "gsm_a_bssmap.extraneous_data", PI_PROTOCOL, PI_NOTE, "Extraneous Data, dissector bug or later version spec(report to wireshark.org)", EXPFILL }},
};
#define NUM_INDIVIDUAL_ELEMS 5
gint *ett[NUM_INDIVIDUAL_ELEMS + NUM_GSM_BSSMAP_MSG +
NUM_GSM_BSSMAP_ELEM];
ett[0] = &ett_bssmap_msg;
ett[1] = &ett_cell_list;
ett[2] = &ett_dlci;
ett[3] = &ett_codec_lst,
ett[4] = &ett_bss_to_bss_info,
last_offset = NUM_INDIVIDUAL_ELEMS;
for (i=0; i < NUM_GSM_BSSMAP_MSG; i++, last_offset++)
{
ett_gsm_bssmap_msg[i] = -1;
ett[last_offset] = &ett_gsm_bssmap_msg[i];
}
for (i=0; i < NUM_GSM_BSSMAP_ELEM; i++, last_offset++)
{
ett_gsm_bssmap_elem[i] = -1;
ett[last_offset] = &ett_gsm_bssmap_elem[i];
}
proto_a_bssmap =
proto_register_protocol("GSM A-I/F BSSMAP", "GSM BSSMAP", "gsm_a.bssmap");
proto_register_field_array(proto_a_bssmap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_gsm_a_bssmap = expert_register_protocol(proto_a_bssmap);
expert_register_field_array(expert_gsm_a_bssmap, ei, array_length(ei));
register_dissector("gsm_a_bssmap", dissect_bssmap, proto_a_bssmap);
}
void
proto_reg_handoff_gsm_a_bssmap(void)
{
dissector_handle_t bssmap_handle;
bssmap_handle = find_dissector("gsm_a_bssmap");
dissector_add_uint("bssap.pdu_type", GSM_A_PDU_TYPE_BSSMAP, bssmap_handle);
dtap_handle = find_dissector("gsm_a_dtap");
gsm_bsslap_handle = find_dissector("gsm_bsslap");
bssgp_handle = find_dissector ("bssgp");
rrc_handle = find_dissector ("rrc");
rtp_handle = find_dissector("rtp");
}
