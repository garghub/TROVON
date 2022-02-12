static config_frame *config_frame_fast(tvbuff_t *tvb)
{
guint16 idcode, num_pmu;
gint offset;
config_frame *frame;
frame = wmem_new(wmem_file_scope(), config_frame);
frame->config_blocks = wmem_array_new(wmem_file_scope(), sizeof(config_block));
idcode = tvb_get_ntohs(tvb, 4);
frame->id = idcode;
num_pmu = tvb_get_ntohs(tvb, 18);
offset = 20;
while (num_pmu) {
guint16 format_flags;
gint num_ph,
num_an,
num_dg;
gint i,
phunit,
anunit,
fnom;
config_block block;
block.phasors = wmem_array_new(wmem_file_scope(), sizeof(phasor_info));
block.analogs = wmem_array_new(wmem_file_scope(), sizeof(analog_info));
tvb_memcpy(tvb, block.name, offset, CHNAM_LEN); offset += CHNAM_LEN;
block.name[CHNAM_LEN] = '\0';
block.id = tvb_get_ntohs(tvb, offset); offset += 2;
format_flags = tvb_get_ntohs(tvb, offset); offset += 2;
block.format_fr = (format_flags & 0x0008) ? floating_point : integer;
block.format_an = (format_flags & 0x0004) ? floating_point : integer;
block.format_ph = (format_flags & 0x0002) ? floating_point : integer;
block.phasor_notation = (format_flags & 0x0001) ? polar : rect;
num_ph = tvb_get_ntohs(tvb, offset); offset += 2;
num_an = tvb_get_ntohs(tvb, offset); offset += 2;
num_dg = tvb_get_ntohs(tvb, offset); offset += 2;
block.num_dg = num_dg;
phunit = offset + (num_ph + num_an + num_dg * CHNAM_LEN) * CHNAM_LEN;
anunit = phunit + num_ph * 4;
fnom = anunit + num_an * 4 + num_dg * 4;
for (i = 0; i != num_ph; i++) {
phasor_info pi;
guint32 conv;
tvb_memcpy(tvb, pi.name, offset, CHNAM_LEN); offset += CHNAM_LEN;
pi.name[CHNAM_LEN] = '\0';
conv = tvb_get_ntohl(tvb, phunit + 4 * i);
pi.unit = conv & 0xFF000000 ? A : V;
pi.conv = conv & 0x00FFFFFF;
wmem_array_append_one(block.phasors, pi);
}
for (i = 0; i != num_an; i++) {
analog_info ai;
guint32 conv;
tvb_memcpy(tvb, ai.name, offset, CHNAM_LEN); offset += CHNAM_LEN;
ai.name[CHNAM_LEN] = '\0';
conv = tvb_get_ntohl(tvb, anunit + 4 * i);
ai.conv = conv;
wmem_array_append_one(block.analogs, ai);
}
block.fnom = tvb_get_ntohs(tvb, fnom) & 0x0001 ? 50 : 60;
offset = fnom + 2;
offset += 2;
wmem_array_append_one(frame->config_blocks, block);
num_pmu--;
}
return frame;
}
static gboolean check_crc(tvbuff_t *tvb, guint16 *computedcrc)
{
guint16 crc;
guint len = tvb_get_ntohs(tvb, 2);
crc = tvb_get_ntohs(tvb, len - 2);
*computedcrc = crc16_x25_ccitt_tvb(tvb, len - 2);
if (crc == *computedcrc)
return TRUE;
return FALSE;
}
static int dissect_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint8 frame_type;
guint16 crc;
guint tvbsize = tvb_reported_length(tvb);
if (tvbsize < 17
|| tvb_get_guint8(tvb, 0) != 0xAA)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTOCOL_SHORT_NAME);
frame_type = tvb_get_guint8(tvb, 1) >> 4;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_const(frame_type, typenames, "invalid packet type"));
if (!pinfo->fd->flags.visited) {
if (CFG2 == frame_type &&
check_crc(tvb, &crc)) {
conversation_t *conversation;
config_frame *frame = config_frame_fast(tvb);
frame->fnum = pinfo->fd->num;
conversation = find_or_create_conversation(pinfo);
if (conversation_get_proto_data(conversation, proto_synphasor))
conversation_delete_proto_data(conversation, proto_synphasor);
conversation_add_proto_data(conversation, proto_synphasor, frame);
}
else if (DATA == frame_type) {
conversation_t *conversation = find_conversation(pinfo->fd->num,
&pinfo->src, &pinfo->dst,
pinfo->ptype,
pinfo->srcport, pinfo->destport,
0);
if (conversation) {
config_frame *conf = (config_frame *)conversation_get_proto_data(conversation, proto_synphasor);
p_add_proto_data(wmem_file_scope(), pinfo, proto_synphasor, 0, conf);
}
}
}
{
proto_tree *synphasor_tree;
proto_item *temp_item;
proto_item *sub_item;
gint offset;
guint16 framesize;
tvbuff_t *sub_tvb;
gboolean crc_good;
temp_item = proto_tree_add_item(tree, proto_synphasor, tvb, 0, -1, ENC_NA);
proto_item_append_text(temp_item, ", %s", val_to_str_const(frame_type, typenames,
", invalid packet type"));
synphasor_tree = proto_item_add_subtree(temp_item, ett_synphasor);
framesize = dissect_header(tvb, synphasor_tree);
offset = 14;
sub_item = proto_tree_add_item(synphasor_tree, hf_synphasor_data, tvb, offset, tvbsize - 16, ENC_NA);
crc_good = check_crc(tvb, &crc);
temp_item = proto_tree_add_uint(synphasor_tree, hf_synphasor_checksum, tvb, tvbsize - 2, 2, crc);
if (!crc_good) {
proto_item_append_text(sub_item, ", not dissected because of wrong checksum");
proto_item_append_text(temp_item, " [incorrect]");
}
else {
sub_tvb = tvb_new_subset(tvb, offset, tvbsize - 16, framesize - 16);
switch (frame_type) {
case DATA:
dissect_data_frame(sub_tvb, sub_item, pinfo);
break;
case HEADER:
proto_item_append_text(sub_item, "Header Frame");
break;
case CFG1:
case CFG2:
dissect_config_frame(sub_tvb, sub_item);
break;
case CMD:
dissect_command_frame(sub_tvb, sub_item, pinfo);
break;
default:
proto_item_append_text(sub_item, " of unknown type");
}
proto_item_append_text(temp_item, " [correct]");
}
}
return tvb_reported_length(tvb);
}
static int dissect_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
return dissect_common(tvb, pinfo, tree, data);
}
static guint get_pdu_length(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
return tvb_get_ntohs(tvb, offset + 2);
}
static int dissect_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 4, get_pdu_length, dissect_common, data);
return tvb_reported_length(tvb);
}
static gint dissect_header(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree *temp_tree;
proto_item *temp_item;
gint offset = 0;
guint16 framesize;
temp_item = proto_tree_add_item(tree, hf_sync, tvb, offset, 2, ENC_BIG_ENDIAN);
temp_tree = proto_item_add_subtree(temp_item, ett_frtype);
proto_tree_add_item(temp_tree, hf_sync_frtype, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_sync_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_frsize, tvb, offset, 2, ENC_BIG_ENDIAN);
framesize = tvb_get_ntohs(tvb, offset); offset += 2;
proto_tree_add_item(tree, hf_idcode, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_soc, tvb, offset, 4, ENC_TIME_TIMESPEC | ENC_BIG_ENDIAN);
offset += 4;
temp_tree = proto_tree_add_subtree(tree, tvb, offset, 1, ett_timequal, NULL, "Time quality flags");
proto_tree_add_item(temp_tree, hf_timeqal_lsdir, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_timeqal_lsocc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_timeqal_lspend, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_timeqal_timequalindic, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_fracsec, tvb, offset, 3, ENC_BIG_ENDIAN);
return framesize;
}
static int dissect_config_frame(tvbuff_t *tvb, proto_item *config_item)
{
proto_tree *config_tree;
gint offset = 0, j;
guint16 num_pmu;
proto_item_set_text (config_item, "Configuration data");
config_tree = proto_item_add_subtree(config_item, ett_conf);
offset += 1;
proto_tree_add_item(config_tree, hf_conf_timebase, tvb, offset, 3, ENC_BIG_ENDIAN); offset += 3;
proto_tree_add_item(config_tree, hf_conf_numpmu, tvb, offset, 2, ENC_BIG_ENDIAN);
num_pmu = tvb_get_ntohs(tvb, offset); offset += 2;
proto_item_append_text(config_item, ", %"G_GUINT16_FORMAT" PMU(s) included", num_pmu);
for (j = 0; j < num_pmu; j++) {
guint16 num_ph, num_an, num_dg;
proto_item *station_item;
proto_tree *station_tree;
proto_tree *temp_tree;
char *str;
gint oldoffset = offset;
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, CHNAM_LEN, ENC_ASCII);
station_tree = proto_tree_add_subtree_format(config_tree, tvb, offset, CHNAM_LEN,
ett_conf_station, &station_item,
"Station #%i: \"%s\"", j + 1, str);
offset += CHNAM_LEN;
proto_tree_add_item(station_tree, hf_idcode, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
temp_tree = proto_tree_add_subtree(station_tree, tvb, offset, 2, ett_conf_format, NULL,
"Data format in data frame");
proto_tree_add_item(temp_tree, hf_conf_formatb3, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_conf_formatb2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_conf_formatb1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_conf_formatb0, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
num_ph = tvb_get_ntohs(tvb, offset );
num_an = tvb_get_ntohs(tvb, offset + 2);
num_dg = tvb_get_ntohs(tvb, offset + 4);
proto_tree_add_uint(station_tree, hf_synphasor_num_phasors, tvb, offset, 2, num_ph);
proto_tree_add_uint(station_tree, hf_synphasor_num_analog_values, tvb, offset + 2, 2, num_an);
proto_tree_add_uint(station_tree, hf_synphasor_num_digital_status_words, tvb, offset + 4, 2, num_dg);
offset += 6;
offset = dissect_CHNAM(tvb, station_tree, offset, num_ph , "Phasor name" );
offset = dissect_CHNAM(tvb, station_tree, offset, num_an , "Analog value" );
offset = dissect_CHNAM(tvb, station_tree, offset, num_dg * 16, "Digital status label");
offset = dissect_PHUNIT (tvb, station_tree, offset, num_ph);
offset = dissect_ANUNIT (tvb, station_tree, offset, num_an);
offset = dissect_DIGUNIT(tvb, station_tree, offset, num_dg);
proto_tree_add_item(station_tree, hf_conf_fnom, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(station_tree, hf_conf_cfgcnt, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_item_set_len(station_item, offset - oldoffset);
}
{
gint16 tmp = tvb_get_ntohs(tvb, offset);
if (tmp > 0)
proto_tree_add_int_format_value(config_tree, hf_synphasor_rate_of_transmission, tvb, offset, 2, tmp,
"%d frame(s) per second", tmp);
else
proto_tree_add_int_format_value(config_tree, hf_synphasor_rate_of_transmission, tvb, offset, 2, tmp,
"1 frame per %d second(s)", (gint16)-tmp);
offset += 2;
}
return offset;
}
static int dissect_data_frame(tvbuff_t *tvb,
proto_item *data_item,
packet_info *pinfo)
{
proto_tree *data_tree;
gint offset = 0;
guint i;
config_frame *conf;
proto_item_set_text(data_item, "Measurement data");
data_tree = proto_item_add_subtree(data_item, ett_data);
{
gboolean config_found = FALSE;
conf = (config_frame *)p_get_proto_data(wmem_file_scope(), pinfo, proto_synphasor, 0);
if (conf) {
size_t reported_size = 0;
for (i = 0; i < wmem_array_get_count(conf->config_blocks); i++) {
config_block *block = (config_block*)wmem_array_index(conf->config_blocks, i);
reported_size += SYNP_BLOCKSIZE(*block);
}
if (tvb_reported_length(tvb) == reported_size) {
proto_item_append_text(data_item, ", using frame number %"G_GUINT32_FORMAT" as configuration frame",
conf->fnum);
config_found = TRUE;
}
}
if (!config_found) {
proto_item_append_text(data_item, ", no configuration frame found");
return 0;
}
}
for (i = 0; i < wmem_array_get_count(conf->config_blocks); i++) {
config_block *block = (config_block*)wmem_array_index(conf->config_blocks, i);
proto_tree *block_tree = proto_tree_add_subtree_format(data_tree, tvb, offset, SYNP_BLOCKSIZE(*block),
ett_data_block, NULL,
"Station: \"%s\"", block->name);
proto_tree *temp_tree = proto_tree_add_subtree(block_tree, tvb, offset, 2, ett_data_stat, NULL, "Flags");
proto_tree_add_item(temp_tree, hf_data_statb15, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_data_statb14, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_data_statb13, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_data_statb12, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_data_statb11, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_data_statb10, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_data_statb05to04, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_data_statb03to00, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = dissect_PHASORS(tvb, block_tree, block, offset);
offset = dissect_DFREQ (tvb, block_tree, block, offset);
offset = dissect_ANALOG (tvb, block_tree, block, offset);
offset = dissect_DIGITAL(tvb, block_tree, block, offset);
}
return offset;
}
static int dissect_command_frame(tvbuff_t *tvb,
proto_item *command_item,
packet_info *pinfo)
{
proto_tree *command_tree;
guint tvbsize = tvb_reported_length(tvb);
const char *s;
proto_item_set_text(command_item, "Command data");
command_tree = proto_item_add_subtree(command_item, ett_command);
proto_tree_add_item(command_tree, hf_command, tvb, 0, 2, ENC_BIG_ENDIAN);
s = val_to_str_const(tvb_get_ntohs(tvb, 0), command_names, "invalid command");
col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_append_str(pinfo->cinfo, COL_INFO, s);
if (tvbsize > 2) {
if (tvb_get_ntohs(tvb, 0) == 0x0008) {
proto_item *ti = proto_tree_add_item(command_tree, hf_synphasor_extended_frame_data, tvb, 2, tvbsize - 2, ENC_NA);
if (tvbsize % 2)
expert_add_info(pinfo, ti, &ei_synphasor_extended_frame_data);
}
else
proto_tree_add_item(command_tree, hf_synphasor_unknown_data, tvb, 2, tvbsize - 2, ENC_NA);
}
return tvbsize;
}
static int dissect_single_phasor(tvbuff_t *tvb, int offset,
double *mag, double *phase,
data_format format,
phasor_notation_e notation)
{
if (floating_point == format) {
if (polar == notation) {
*mag = tvb_get_ntohieee_float(tvb, offset );
*phase = tvb_get_ntohieee_float(tvb, offset + 4);
}
else {
gfloat real, imag;
real = tvb_get_ntohieee_float(tvb, offset );
imag = tvb_get_ntohieee_float(tvb, offset + 4);
*mag = sqrt(pow(real, 2) + pow(imag, 2));
*phase = atan2(imag, real);
}
}
else {
if (polar == notation) {
*mag = (guint16)tvb_get_ntohs(tvb, offset );
*phase = (gint16) tvb_get_ntohs(tvb, offset + 2);
*phase /= 10000.0;
}
else {
gint16 real, imag;
real = tvb_get_ntohs(tvb, offset );
imag = tvb_get_ntohs(tvb, offset + 2);
*mag = sqrt(pow(real, 2) + pow(imag, 2));
*phase = atan2(imag, real);
}
}
return floating_point == format ? 8 : 4;
}
static gint dissect_PHASORS(tvbuff_t *tvb, proto_tree *tree, config_block *block, gint offset)
{
proto_tree *phasor_tree;
guint length;
gint j;
gint cnt = wmem_array_get_count(block->phasors);
if (0 == cnt)
return offset;
length = wmem_array_get_count(block->phasors) * (floating_point == block->format_ph ? 8 : 4);
phasor_tree = proto_tree_add_subtree_format(tree, tvb, offset, length, ett_data_phasors, NULL,
"Phasors (%u)", cnt);
for (j = 0; j < cnt; j++) {
proto_item *temp_item;
double mag, phase;
phasor_info *pi;
pi = (phasor_info *)wmem_array_index(block->phasors, j);
temp_item = proto_tree_add_string_format(phasor_tree, hf_synphasor_phasor, tvb, offset,
floating_point == block->format_ph ? 8 : 4, pi->name,
"Phasor #%u: \"%s\"", j + 1, pi->name);
offset += dissect_single_phasor(tvb, offset,
&mag, &phase,
block->format_ph,
block->phasor_notation);
if (integer == block->format_ph)
mag = (mag * pi->conv) * 0.00001;
#define SYNP_ANGLE "/_"
#define SYNP_DEGREE "\xC2\xB0"
proto_item_append_text(temp_item, ", %10.2f%c" SYNP_ANGLE "%7.2f" SYNP_DEGREE,
mag,
V == pi->unit ? 'V' : 'A',
phase *180.0/G_PI);
#undef SYNP_ANGLE
#undef SYNP_DEGREE
}
return offset;
}
static gint dissect_DFREQ(tvbuff_t *tvb, proto_tree *tree, config_block *block, gint offset)
{
if (floating_point == block->format_fr) {
gfloat tmp;
tmp = tvb_get_ntohieee_float(tvb, offset);
proto_tree_add_float_format_value(tree, hf_synphasor_actual_frequency_value, tvb, offset, 4, tmp, "%fHz", tmp); offset += 4;
tmp = tvb_get_ntohieee_float(tvb, offset);
proto_tree_add_float_format_value(tree, hf_synphasor_rate_change_frequency, tvb, offset, 4, tmp, "%fHz/s", tmp); offset += 4;
}
else {
gint16 tmp;
tmp = tvb_get_ntohs(tvb, offset);
proto_tree_add_int_format_value(tree, hf_synphasor_frequency_deviation_from_nominal, tvb, offset, 2, tmp,
"%dmHz (actual frequency: %.3fHz)", tmp, block->fnom + (tmp / 1000.0));
offset += 2;
tmp = tvb_get_ntohs(tvb, offset);
proto_tree_add_float_format_value(tree, hf_synphasor_rate_change_frequency, tvb, offset, 2, (gfloat)(tmp / 100.0), "%.3fHz/s", tmp / 100.0); offset += 2;
}
return offset;
}
static gint dissect_ANALOG(tvbuff_t *tvb, proto_tree *tree, config_block *block, gint offset)
{
proto_tree *analog_tree;
guint length;
gint j;
gint cnt = wmem_array_get_count(block->analogs);
if (0 == cnt)
return offset;
length = wmem_array_get_count(block->analogs) * (floating_point == block->format_an ? 4 : 2);
analog_tree = proto_tree_add_subtree_format(tree, tvb, offset, length, ett_data_analog, NULL,
"Analog values (%u)", cnt);
for (j = 0; j < cnt; j++) {
proto_item *temp_item;
analog_info *ai = (analog_info *)wmem_array_index(block->analogs, j);
temp_item = proto_tree_add_string_format(analog_tree, hf_synphasor_analog_value, tvb, offset,
floating_point == block->format_an ? 4 : 2, ai->name,
"Analog value #%u: \"%s\"", j + 1, ai->name);
if (floating_point == block->format_an) {
gfloat tmp = tvb_get_ntohieee_float(tvb, offset); offset += 4;
proto_item_append_text(temp_item, ", %.3f", tmp);
}
else {
gint16 tmp = tvb_get_ntohs(tvb, offset); offset += 2;
proto_item_append_text(temp_item, ", %" G_GINT16_FORMAT " (conversation factor: %#06x)",
tmp, ai->conv);
}
}
return offset;
}
static gint dissect_DIGITAL(tvbuff_t *tvb, proto_tree *tree, config_block *block, gint offset)
{
gint j;
gint cnt = block->num_dg;
if (0 == cnt)
return offset;
tree = proto_tree_add_subtree_format(tree, tvb, offset, cnt * 2, ett_data_digital, NULL,
"Digital status words (%u)", cnt);
for (j = 0; j < cnt; j++) {
guint16 tmp = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(tree, hf_synphasor_digital_status_word, tvb, offset, 2, tmp, "Digital status word #%u: 0x%04x", j + 1, tmp);
offset += 2;
}
return offset;
}
static gint dissect_PHUNIT(tvbuff_t *tvb, proto_tree *tree, gint offset, gint cnt)
{
proto_tree *temp_tree;
int i;
if (0 == cnt)
return offset;
temp_tree = proto_tree_add_subtree_format(tree, tvb, offset, 4 * cnt, ett_conf_phconv, NULL,
"Phasor conversation factors (%u)", cnt);
for (i = 0; i < cnt; i++) {
guint32 tmp = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format(temp_tree, hf_synphasor_conversion_factor, tvb, offset, 4,
tmp, "#%u factor: %u * 10^-5, unit: %s",
i + 1,
tmp & 0x00FFFFFF,
tmp & 0xFF000000 ? "Ampere" : "Volt");
offset += 4;
}
return offset;
}
static gint dissect_ANUNIT(tvbuff_t *tvb, proto_tree *tree, gint offset, gint cnt)
{
proto_item *temp_item;
proto_tree *temp_tree;
int i;
if (0 == cnt)
return offset;
temp_tree = proto_tree_add_subtree_format(tree, tvb, offset, 4 * cnt, ett_conf_anconv, NULL,
"Analog values conversation factors (%u)", cnt);
for (i = 0; i < cnt; i++) {
gint32 tmp = tvb_get_ntohl(tvb, offset);
temp_item = proto_tree_add_uint_format(temp_tree, hf_synphasor_factor_for_analog_value, tvb, offset, 4,
tmp, "Factor for analog value #%i: %s",
i + 1,
try_rval_to_str((tmp >> 24) & 0x000000FF, conf_anconvnames));
tmp &= 0x00FFFFFF;
if ( tmp & 0x00800000)
tmp |= 0xFF000000;
proto_item_append_text(temp_item, ", value: %" G_GINT32_FORMAT, tmp);
offset += 4;
}
return offset;
}
static gint dissect_DIGUNIT(tvbuff_t *tvb, proto_tree *tree, gint offset, gint cnt)
{
proto_tree *temp_tree, *mask_tree;
int i;
if (0 == cnt)
return offset;
temp_tree = proto_tree_add_subtree_format(tree, tvb, offset, 4 * cnt, ett_conf_dgmask, NULL,
"Masks for digital status words (%u)", cnt);
for (i = 0; i < cnt; i++) {
mask_tree = proto_tree_add_subtree_format(temp_tree, tvb, offset, 4, ett_status_word_mask, NULL, "Mask for status word #%u: ", i + 1);
proto_tree_add_item(mask_tree, hf_synphasor_status_word_mask_normal_state, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mask_tree, hf_synphasor_status_word_mask_valid_bits, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
return offset;
}
static gint dissect_CHNAM(tvbuff_t *tvb, proto_tree *tree, gint offset, gint cnt, const char *prefix)
{
proto_tree *temp_tree;
int i;
if (0 == cnt)
return offset;
temp_tree = proto_tree_add_subtree_format(tree, tvb, offset, CHNAM_LEN * cnt, ett_conf_phnam, NULL,
"%ss (%u)", prefix, cnt);
for (i = 0; i < cnt; i++) {
char *str;
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, CHNAM_LEN, ENC_ASCII);
proto_tree_add_string_format(temp_tree, hf_synphasor_channel_name, tvb, offset, CHNAM_LEN,
str, "%s #%i: \"%s\"", prefix, i+1, str);
offset += CHNAM_LEN;
}
return offset;
}
void proto_register_synphasor(void)
{
static hf_register_info hf[] = {
{ &hf_sync,
{ "Synchronization word", "synphasor.sync", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_sync_frtype,
{ "Frame Type", "synphasor.frtype", FT_UINT16, BASE_HEX,
VALS(typenames), 0x0070, NULL, HFILL }},
{ &hf_sync_version,
{ "Version", "synphasor.version", FT_UINT16, BASE_DEC,
VALS(versionnames), 0x000F, NULL, HFILL }},
{ &hf_frsize,
{ "Framesize", "synphasor.frsize", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_idcode,
{ "PMU/DC ID number", "synphasor.idcode", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_soc,
{ "SOC time stamp", "synphasor.soc", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC,
NULL, 0x0, NULL, HFILL }},
{ &hf_timeqal_lsdir,
{ "Leap second direction", "synphasor.timeqal.lsdir", FT_BOOLEAN, 8,
NULL, 0x40, NULL, HFILL }},
{ &hf_timeqal_lsocc,
{ "Leap second occurred", "synphasor.timeqal.lsocc", FT_BOOLEAN, 8,
NULL, 0x20, NULL, HFILL }},
{ &hf_timeqal_lspend,
{ "Leap second pending", "synphasor.timeqal.lspend", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL }},
{ &hf_timeqal_timequalindic,
{ "Time Quality indicator code", "synphasor.timeqal.timequalindic", FT_UINT8, BASE_HEX,
VALS(timequalcodes), 0x0F, NULL, HFILL }},
{ &hf_fracsec,
{ "Fraction of second (raw)", "synphasor.fracsec", FT_UINT24, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_conf_timebase,
{ "Resolution of fractional second time stamp", "synphasor.conf.timebase", FT_UINT24, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_conf_numpmu,
{ "Number of PMU blocks included in the frame", "synphasor.conf.numpmu", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_conf_formatb3,
{ "FREQ/DFREQ format", "synphasor.conf.dfreq_format", FT_BOOLEAN, 16,
TFS(&conf_formatb123names), 0x8, NULL, HFILL }},
{ &hf_conf_formatb2,
{ "Analog values format", "synphasor.conf.analog_format", FT_BOOLEAN, 16,
TFS(&conf_formatb123names), 0x4, NULL, HFILL }},
{ &hf_conf_formatb1,
{ "Phasor format", "synphasor.conf.phasor_format", FT_BOOLEAN, 16,
TFS(&conf_formatb123names), 0x2, NULL, HFILL }},
{ &hf_conf_formatb0,
{ "Phasor notation", "synphasor.conf.phasor_notation", FT_BOOLEAN, 16,
TFS(&conf_formatb0names), 0x1, NULL, HFILL }},
{ &hf_conf_fnom,
{ "Nominal line freqency", "synphasor.conf.fnom", FT_BOOLEAN, 16,
TFS(&conf_fnomnames), 0x0001, NULL, HFILL }},
{ &hf_conf_cfgcnt,
{ "Configuration change count", "synphasor.conf.cfgcnt", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_data_statb15,
{ "Data valid", "synphasor.data.valid", FT_BOOLEAN, 16,
TFS(&data_statb15names), 0x8000, NULL, HFILL }},
{ &hf_data_statb14,
{ "PMU error", "synphasor.data.PMUerror", FT_BOOLEAN, 16,
TFS(&data_statb14names), 0x4000, NULL, HFILL }},
{ &hf_data_statb13,
{ "Time synchronized", "synphasor.data.sync", FT_BOOLEAN, 16,
TFS(&data_statb13names), 0x2000, NULL, HFILL }},
{ &hf_data_statb12,
{ "Data sorting", "synphasor.data.sorting", FT_BOOLEAN, 16,
TFS(&data_statb12names), 0x1000, NULL, HFILL }},
{ &hf_data_statb11,
{ "Trigger detected", "synphasor.data.trigger", FT_BOOLEAN, 16,
TFS(&data_statb11names), 0x0800, NULL, HFILL }},
{ &hf_data_statb10,
{ "Configuration changed", "synphasor.data.CFGchange", FT_BOOLEAN, 16,
TFS(&data_statb10names), 0x0400, NULL, HFILL }},
{ &hf_data_statb05to04,
{ "Unlocked time", "synphasor.data.t_unlock", FT_UINT16, BASE_HEX,
VALS(data_statb05to04names), 0x0030, NULL, HFILL }},
{ &hf_data_statb03to00,
{ "Trigger reason", "synphasor.data.trigger_reason", FT_UINT16, BASE_HEX,
VALS(data_statb03to00names), 0x000F, NULL, HFILL }},
{ &hf_command,
{ "Command", "synphasor.command", FT_UINT16, BASE_HEX,
VALS(command_names), 0x000F, NULL, HFILL }},
{ &hf_synphasor_data, { "Data", "synphasor.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_checksum, { "Checksum", "synphasor.checksum", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_num_phasors, { "Number of phasors", "synphasor.num_phasors", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_num_analog_values, { "Number of analog values", "synphasor.num_analog_values", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_num_digital_status_words, { "Number of digital status words", "synphasor.num_digital_status_words", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_rate_of_transmission, { "Rate of transmission", "synphasor.rate_of_transmission", FT_INT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_phasor, { "Phasor", "synphasor.phasor", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_actual_frequency_value, { "Actual frequency value", "synphasor.actual_frequency_value", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_rate_change_frequency, { "Rate of change of frequency", "synphasor.rate_change_frequency", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_frequency_deviation_from_nominal, { "Frequency deviation from nominal", "synphasor.frequency_deviation_from_nominal", FT_INT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_analog_value, { "Analog value", "synphasor.analog_value", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_digital_status_word, { "Digital status word", "synphasor.digital_status_word", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_conversion_factor, { "conversion factor", "synphasor.conversion_factor", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_factor_for_analog_value, { "Factor for analog value", "synphasor.factor_for_analog_value", FT_UINT32, BASE_DEC, NULL, 0x000000FF, NULL, HFILL }},
{ &hf_synphasor_channel_name, { "Channel name", "synphasor.channel_name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_extended_frame_data, { "Extended frame data", "synphasor.extended_frame_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_unknown_data, { "Unknown data", "synphasor.data.unknown", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_synphasor_status_word_mask_normal_state, { "Normal state", "synphasor.status_word_mask.normal_state", FT_UINT32, BASE_HEX, NULL, 0xFFFF0000, NULL, HFILL }},
{ &hf_synphasor_status_word_mask_valid_bits, { "Valid bits", "synphasor.status_word_mask.valid_bits", FT_UINT32, BASE_HEX, NULL, 0x0000FFFF, NULL, HFILL }},
};
static gint *ett[] = {
&ett_synphasor,
&ett_frtype,
&ett_timequal,
&ett_conf,
&ett_conf_station,
&ett_conf_format,
&ett_conf_phnam,
&ett_conf_annam,
&ett_conf_dgnam,
&ett_conf_phconv,
&ett_conf_anconv,
&ett_conf_dgmask,
&ett_data,
&ett_data_block,
&ett_data_stat,
&ett_data_phasors,
&ett_data_analog,
&ett_data_digital,
&ett_command,
&ett_status_word_mask
};
static ei_register_info ei[] = {
{ &ei_synphasor_extended_frame_data, { "synphasor.extended_frame_data.unaligned", PI_PROTOCOL, PI_WARN, "Size not multiple of 16-bit word", EXPFILL }},
};
module_t *synphasor_module;
expert_module_t* expert_synphasor;
proto_synphasor = proto_register_protocol(PROTOCOL_NAME,
PROTOCOL_SHORT_NAME,
PROTOCOL_ABBREV);
synphasor_udp_handle = new_register_dissector("synphasor", dissect_udp, proto_synphasor);
proto_register_field_array(proto_synphasor, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_synphasor = expert_register_protocol(proto_synphasor);
expert_register_field_array(expert_synphasor, ei, array_length(ei));
synphasor_module = prefs_register_protocol(proto_synphasor, proto_reg_handoff_synphasor);
prefs_register_uint_preference(synphasor_module, "udp_port", "Synchrophasor UDP port",
"Set the port number for synchrophasor frames over UDP" \
"(if other than the default of 4713)",
10, &global_pref_udp_port);
prefs_register_uint_preference(synphasor_module, "tcp_port", "Synchrophasor TCP port",
"Set the port number for synchrophasor frames over TCP" \
"(if other than the default of 4712)",
10, &global_pref_tcp_port);
}
void proto_reg_handoff_synphasor(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t synphasor_tcp_handle;
static guint current_udp_port;
static guint current_tcp_port;
if (!initialized) {
synphasor_tcp_handle = new_create_dissector_handle(dissect_tcp, proto_synphasor);
dissector_add_for_decode_as("rtacser.data", synphasor_udp_handle);
initialized = TRUE;
}
else {
dissector_delete_uint("udp.port", current_udp_port, synphasor_udp_handle);
dissector_delete_uint("tcp.port", current_tcp_port, synphasor_tcp_handle);
}
current_udp_port = global_pref_udp_port;
current_tcp_port = global_pref_tcp_port;
dissector_add_uint("udp.port", current_udp_port, synphasor_udp_handle);
dissector_add_uint("tcp.port", current_tcp_port, synphasor_tcp_handle);
}
