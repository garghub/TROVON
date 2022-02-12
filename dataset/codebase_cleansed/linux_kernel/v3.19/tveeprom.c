static int hasRadioTuner(int tunerType)
{
switch (tunerType) {
case 18:
case 23:
case 38:
case 16:
case 19:
case 21:
case 24:
case 17:
case 22:
case 20:
case 25:
case 33:
case 42:
case 52:
case 54:
case 44:
case 31:
case 30:
case 46:
case 47:
case 49:
case 60:
case 57:
case 59:
case 58:
case 68:
case 61:
case 78:
case 89:
case 92:
case 105:
return 1;
}
return 0;
}
void tveeprom_hauppauge_analog(struct i2c_client *c, struct tveeprom *tvee,
unsigned char *eeprom_data)
{
int i, j, len, done, beenhere, tag, start;
int tuner1 = 0, t_format1 = 0, audioic = -1;
const char *t_name1 = NULL;
const char *t_fmt_name1[8] = { " none", "", "", "", "", "", "", "" };
int tuner2 = 0, t_format2 = 0;
const char *t_name2 = NULL;
const char *t_fmt_name2[8] = { " none", "", "", "", "", "", "", "" };
memset(tvee, 0, sizeof(*tvee));
tvee->tuner_type = TUNER_ABSENT;
tvee->tuner2_type = TUNER_ABSENT;
done = len = beenhere = 0;
if (eeprom_data[0] == 0x1a &&
eeprom_data[1] == 0xeb &&
eeprom_data[2] == 0x67 &&
eeprom_data[3] == 0x95)
start = 0xa0;
else if ((eeprom_data[0] & 0xe1) == 0x01 &&
eeprom_data[1] == 0x00 &&
eeprom_data[2] == 0x00 &&
eeprom_data[8] == 0x84)
start = 8;
else if (eeprom_data[1] == 0x70 &&
eeprom_data[2] == 0x00 &&
eeprom_data[4] == 0x74 &&
eeprom_data[8] == 0x84)
start = 8;
else
start = 0;
for (i = start; !done && i < 256; i += len) {
if (eeprom_data[i] == 0x84) {
len = eeprom_data[i + 1] + (eeprom_data[i + 2] << 8);
i += 3;
} else if ((eeprom_data[i] & 0xf0) == 0x70) {
if (eeprom_data[i] & 0x08) {
done = 1;
break;
}
len = eeprom_data[i] & 0x07;
++i;
} else {
tveeprom_warn("Encountered bad packet header [%02x]. "
"Corrupt or not a Hauppauge eeprom.\n",
eeprom_data[i]);
return;
}
if (debug) {
tveeprom_info("Tag [%02x] + %d bytes:",
eeprom_data[i], len - 1);
for (j = 1; j < len; j++)
printk(KERN_CONT " %02x", eeprom_data[i + j]);
printk(KERN_CONT "\n");
}
tag = eeprom_data[i];
switch (tag) {
case 0x00:
tuner1 = eeprom_data[i+6];
t_format1 = eeprom_data[i+5];
tvee->has_radio = eeprom_data[i+len-1];
tvee->has_ir = 0;
tvee->model =
eeprom_data[i+8] +
(eeprom_data[i+9] << 8);
tvee->revision = eeprom_data[i+10] +
(eeprom_data[i+11] << 8) +
(eeprom_data[i+12] << 16);
break;
case 0x01:
tvee->serial_number =
eeprom_data[i+6] +
(eeprom_data[i+7] << 8) +
(eeprom_data[i+8] << 16);
break;
case 0x02:
audioic = eeprom_data[i+2] & 0x7f;
if (audioic < ARRAY_SIZE(audio_ic))
tvee->audio_processor = audio_ic[audioic].id;
else
tvee->audio_processor = TVEEPROM_AUDPROC_OTHER;
break;
case 0x04:
tvee->serial_number =
eeprom_data[i+5] +
(eeprom_data[i+6] << 8) +
(eeprom_data[i+7] << 16)+
(eeprom_data[i+8] << 24);
if (eeprom_data[i + 8] == 0xf0) {
tvee->MAC_address[0] = 0x00;
tvee->MAC_address[1] = 0x0D;
tvee->MAC_address[2] = 0xFE;
tvee->MAC_address[3] = eeprom_data[i + 7];
tvee->MAC_address[4] = eeprom_data[i + 6];
tvee->MAC_address[5] = eeprom_data[i + 5];
tvee->has_MAC_address = 1;
}
break;
case 0x05:
audioic = eeprom_data[i+1] & 0x7f;
if (audioic < ARRAY_SIZE(audio_ic))
tvee->audio_processor = audio_ic[audioic].id;
else
tvee->audio_processor = TVEEPROM_AUDPROC_OTHER;
break;
case 0x06:
tvee->model =
eeprom_data[i + 1] +
(eeprom_data[i + 2] << 8) +
(eeprom_data[i + 3] << 16) +
(eeprom_data[i + 4] << 24);
tvee->revision =
eeprom_data[i + 5] +
(eeprom_data[i + 6] << 8) +
(eeprom_data[i + 7] << 16);
break;
case 0x07:
break;
case 0x09:
tvee->decoder_processor = eeprom_data[i + 1];
break;
case 0x0a:
if (beenhere == 0) {
tuner1 = eeprom_data[i + 2];
t_format1 = eeprom_data[i + 1];
beenhere = 1;
} else {
tuner2 = eeprom_data[i + 2];
t_format2 = eeprom_data[i + 1];
if (t_format2 == 0)
tvee->has_radio = 1;
}
break;
case 0x0b:
break;
case 0x0e:
tvee->has_radio = eeprom_data[i+1];
break;
case 0x0f:
tvee->has_ir = 1 | (eeprom_data[i+1] << 1);
break;
default:
tveeprom_dbg("Not sure what to do with tag [%02x]\n",
tag);
}
}
if (!done) {
tveeprom_warn("Ran out of data!\n");
return;
}
if (tvee->revision != 0) {
tvee->rev_str[0] = 32 + ((tvee->revision >> 18) & 0x3f);
tvee->rev_str[1] = 32 + ((tvee->revision >> 12) & 0x3f);
tvee->rev_str[2] = 32 + ((tvee->revision >> 6) & 0x3f);
tvee->rev_str[3] = 32 + (tvee->revision & 0x3f);
tvee->rev_str[4] = 0;
}
if (hasRadioTuner(tuner1) && !tvee->has_radio) {
tveeprom_info("The eeprom says no radio is present, but the tuner type\n");
tveeprom_info("indicates otherwise. I will assume that radio is present.\n");
tvee->has_radio = 1;
}
if (tuner1 < ARRAY_SIZE(hauppauge_tuner)) {
tvee->tuner_type = hauppauge_tuner[tuner1].id;
t_name1 = hauppauge_tuner[tuner1].name;
} else {
t_name1 = "unknown";
}
if (tuner2 < ARRAY_SIZE(hauppauge_tuner)) {
tvee->tuner2_type = hauppauge_tuner[tuner2].id;
t_name2 = hauppauge_tuner[tuner2].name;
} else {
t_name2 = "unknown";
}
tvee->tuner_hauppauge_model = tuner1;
tvee->tuner2_hauppauge_model = tuner2;
tvee->tuner_formats = 0;
tvee->tuner2_formats = 0;
for (i = j = 0; i < 8; i++) {
if (t_format1 & (1 << i)) {
tvee->tuner_formats |= hauppauge_tuner_fmt[i].id;
t_fmt_name1[j++] = hauppauge_tuner_fmt[i].name;
}
}
for (i = j = 0; i < 8; i++) {
if (t_format2 & (1 << i)) {
tvee->tuner2_formats |= hauppauge_tuner_fmt[i].id;
t_fmt_name2[j++] = hauppauge_tuner_fmt[i].name;
}
}
tveeprom_info("Hauppauge model %d, rev %s, serial# %u\n",
tvee->model, tvee->rev_str, tvee->serial_number);
if (tvee->has_MAC_address == 1)
tveeprom_info("MAC address is %pM\n", tvee->MAC_address);
tveeprom_info("tuner model is %s (idx %d, type %d)\n",
t_name1, tuner1, tvee->tuner_type);
tveeprom_info("TV standards%s%s%s%s%s%s%s%s (eeprom 0x%02x)\n",
t_fmt_name1[0], t_fmt_name1[1], t_fmt_name1[2],
t_fmt_name1[3], t_fmt_name1[4], t_fmt_name1[5],
t_fmt_name1[6], t_fmt_name1[7], t_format1);
if (tuner2)
tveeprom_info("second tuner model is %s (idx %d, type %d)\n",
t_name2, tuner2, tvee->tuner2_type);
if (t_format2)
tveeprom_info("TV standards%s%s%s%s%s%s%s%s (eeprom 0x%02x)\n",
t_fmt_name2[0], t_fmt_name2[1], t_fmt_name2[2],
t_fmt_name2[3], t_fmt_name2[4], t_fmt_name2[5],
t_fmt_name2[6], t_fmt_name2[7], t_format2);
if (audioic < 0) {
tveeprom_info("audio processor is unknown (no idx)\n");
tvee->audio_processor = TVEEPROM_AUDPROC_OTHER;
} else {
if (audioic < ARRAY_SIZE(audio_ic))
tveeprom_info("audio processor is %s (idx %d)\n",
audio_ic[audioic].name, audioic);
else
tveeprom_info("audio processor is unknown (idx %d)\n",
audioic);
}
if (tvee->decoder_processor)
tveeprom_info("decoder processor is %s (idx %d)\n",
STRM(decoderIC, tvee->decoder_processor),
tvee->decoder_processor);
if (tvee->has_ir)
tveeprom_info("has %sradio, has %sIR receiver, has %sIR transmitter\n",
tvee->has_radio ? "" : "no ",
(tvee->has_ir & 2) ? "" : "no ",
(tvee->has_ir & 4) ? "" : "no ");
else
tveeprom_info("has %sradio\n",
tvee->has_radio ? "" : "no ");
}
int tveeprom_read(struct i2c_client *c, unsigned char *eedata, int len)
{
unsigned char buf;
int err;
buf = 0;
err = i2c_master_send(c, &buf, 1);
if (err != 1) {
tveeprom_info("Huh, no eeprom present (err=%d)?\n", err);
return -1;
}
err = i2c_master_recv(c, eedata, len);
if (err != len) {
tveeprom_warn("i2c eeprom read error (err=%d)\n", err);
return -1;
}
if (debug) {
int i;
tveeprom_info("full 256-byte eeprom dump:\n");
for (i = 0; i < len; i++) {
if (0 == (i % 16))
tveeprom_info("%02x:", i);
printk(KERN_CONT " %02x", eedata[i]);
if (15 == (i % 16))
printk(KERN_CONT "\n");
}
}
return 0;
}
