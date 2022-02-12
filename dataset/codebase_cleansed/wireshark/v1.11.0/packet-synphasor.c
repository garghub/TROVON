static config_frame* config_frame_fast(tvbuff_t *tvb)
{
guint16 idcode, num_pmu;
gint offset;
config_frame *frame;
frame = g_slice_new(config_frame);
frame->config_blocks = g_array_new(FALSE, TRUE, sizeof(config_block));
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
block.phasors = g_array_new(FALSE, TRUE, sizeof(phasor_info));
block.analogs = g_array_new(FALSE, TRUE, sizeof(analog_info));
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
g_array_append_val(block.phasors, pi);
}
for (i = 0; i != num_an; i++) {
analog_info ai;
guint32 conv;
tvb_memcpy(tvb, ai.name, offset, CHNAM_LEN); offset += CHNAM_LEN;
ai.name[CHNAM_LEN] = '\0';
conv = tvb_get_ntohl(tvb, anunit + 4 * i);
ai.conv = conv;
g_array_append_val(block.analogs, ai);
}
block.fnom = tvb_get_ntohs(tvb, fnom) & 0x0001 ? 50 : 60;
offset = fnom + 2;
offset += 2;
g_array_append_val(frame->config_blocks, block);
num_pmu--;
}
return frame;
}
static void config_frame_free(config_frame *frame)
{
int i = frame->config_blocks->len;
while (i--) {
config_block *block;
block = &g_array_index(frame->config_blocks, config_block, i);
g_array_free(block->phasors, TRUE);
g_array_free(block->analogs, TRUE);
}
g_array_free(frame->config_blocks, TRUE);
g_slice_free1(sizeof(config_frame), frame);
}
static void synphasor_init(void)
{
if (config_frame_list) {
g_slist_foreach(config_frame_list, (GFunc) config_frame_free, NULL);
g_slist_free(config_frame_list);
config_frame_list = NULL;
}
}
static int dissect_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
dissect_common(tvb, pinfo, tree);
return tvb_length(tvb);
}
static guint get_pdu_length(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return tvb_get_ntohs(tvb, offset + 2);
}
static int dissect_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 4, get_pdu_length, dissect_common);
return tvb_length(tvb);
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
static void dissect_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 frame_type;
guint16 crc;
guint tvbsize = tvb_length(tvb);
if (tvbsize < 17
|| tvb_get_guint8(tvb, 0) != 0xAA)
return;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTOCOL_SHORT_NAME);
frame_type = tvb_get_guint8(tvb, 1) >> 4;
col_clear(pinfo->cinfo, COL_INFO);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_const(frame_type, typenames, "invalid packet type"));
if (!pinfo->fd->flags.visited) {
if (CFG2 == frame_type &&
check_crc(tvb, &crc)) {
conversation_t *conversation;
config_frame *frame = config_frame_fast(tvb);
frame->fnum = pinfo->fd->num;
config_frame_list = g_slist_append(config_frame_list, frame);
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
p_add_proto_data(pinfo->fd, proto_synphasor, 0, conf);
}
}
}
if (tree) {
proto_tree *synphasor_tree = NULL;
proto_item *temp_item = NULL;
proto_item *sub_item = NULL;
gint offset;
guint16 framesize;
tvbuff_t *sub_tvb;
temp_item = proto_tree_add_item(tree, proto_synphasor, tvb, 0, -1, ENC_NA);
proto_item_append_text(temp_item, ", %s", val_to_str_const(frame_type, typenames,
", invalid packet type"));
synphasor_tree = proto_item_add_subtree(temp_item, ett_synphasor);
framesize = dissect_header(tvb, synphasor_tree);
offset = 14;
sub_item = proto_tree_add_text(synphasor_tree, tvb, offset , tvbsize - 16, "Data" );
temp_item = proto_tree_add_text(synphasor_tree, tvb, tvbsize - 2, 2 , "Checksum:");
if (!check_crc(tvb, &crc)) {
proto_item_append_text(sub_item, ", not dissected because of wrong checksum");
proto_item_append_text(temp_item, " 0x%04x [incorrect]", crc);
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
proto_item_append_text(temp_item, " 0x%04x [correct]", crc);
}
}
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
{
char buf[20];
struct tm* t;
time_t soc = tvb_get_ntohl(tvb, offset);
t = gmtime(&soc);
strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", t);
proto_tree_add_string(tree, hf_soc, tvb, offset, 4, buf);
offset += 4;
}
temp_item = proto_tree_add_text(tree, tvb, offset, 1, "Time quality flags");
temp_tree = proto_item_add_subtree(temp_item, ett_timequal);
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
proto_tree *config_tree = NULL;
proto_item *temp_item = NULL;
proto_tree *temp_tree = NULL;
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
proto_item *station_item = NULL;
proto_tree *station_tree = NULL;
char *str;
gint oldoffset = offset;
str = tvb_get_string(wmem_packet_scope(), tvb, offset, CHNAM_LEN);
station_item = proto_tree_add_text(config_tree, tvb, offset, CHNAM_LEN, "Station #%i: \"%s\"", j + 1, str);
station_tree = proto_item_add_subtree(station_item, ett_conf_station);
offset += CHNAM_LEN;
proto_tree_add_item(station_tree, hf_idcode, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
temp_item = proto_tree_add_text(station_tree, tvb, offset, 2, "Data format in data frame");
temp_tree = proto_item_add_subtree(temp_item, ett_conf_format);
proto_tree_add_item(temp_tree, hf_conf_formatb3, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_conf_formatb2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_conf_formatb1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_conf_formatb0, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
num_ph = tvb_get_ntohs(tvb, offset );
num_an = tvb_get_ntohs(tvb, offset + 2);
num_dg = tvb_get_ntohs(tvb, offset + 4);
proto_tree_add_text(station_tree, tvb, offset , 2, "Number of phasors: %u", num_ph);
proto_tree_add_text(station_tree, tvb, offset + 2, 2, "Number of analog values: %u", num_an);
proto_tree_add_text(station_tree, tvb, offset + 4, 2, "Number of digital status words: %u", num_dg);
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
temp_item = proto_tree_add_text(config_tree, tvb, offset, 2, "Rate of transmission: "); offset += 2;
if (tmp > 0)
proto_item_append_text(temp_item, "%"G_GINT16_FORMAT" frame(s) per second", tmp);
else
proto_item_append_text(temp_item, "1 frame per %"G_GINT16_FORMAT" second(s)", (gint16)-tmp);
}
return offset;
}
static int dissect_data_frame(tvbuff_t *tvb,
proto_item *data_item,
packet_info *pinfo)
{
proto_tree *data_tree = NULL;
gint offset = 0;
guint i;
config_frame *conf;
proto_item_set_text(data_item, "Measurement data");
data_tree = proto_item_add_subtree(data_item, ett_data);
{
gboolean config_found = FALSE;
conf = (config_frame *)p_get_proto_data(pinfo->fd, proto_synphasor, 0);
if (conf) {
size_t reported_size = 0;
for (i = 0; i < conf->config_blocks->len; i++) {
config_block *block = &g_array_index(conf->config_blocks, config_block, i);
reported_size += BLOCKSIZE(*block);
}
if (tvb_length(tvb) == reported_size) {
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
for (i = 0; i < conf->config_blocks->len; i++) {
config_block *block = &g_array_index(conf->config_blocks, config_block, i);
proto_item *block_item = proto_tree_add_text(data_tree, tvb, offset, BLOCKSIZE(*block),
"Station: \"%s\"", block->name);
proto_tree *block_tree = proto_item_add_subtree(block_item, ett_data_block);
proto_item *temp_item = proto_tree_add_text(block_tree, tvb, offset, 2, "Flags");
proto_tree *temp_tree = proto_item_add_subtree(temp_item, ett_data_stat);
proto_tree_add_item(temp_tree, hf_data_statb15, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_data_statb14, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_data_statb13, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_data_statb12, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_data_statb11, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_data_statb10, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_data_statb05to04, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(temp_tree, hf_data_statb03to00, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = dissect_PHASORS(tvb, block_item, block, offset);
offset = dissect_DFREQ (tvb, block_item, block, offset);
offset = dissect_ANALOG (tvb, block_item, block, offset);
offset = dissect_DIGITAL(tvb, block_item, block, offset);
}
return offset;
}
static int dissect_command_frame(tvbuff_t *tvb,
proto_item *command_item,
packet_info *pinfo)
{
proto_tree *command_tree = NULL;
guint tvbsize = tvb_length(tvb);
const char *s;
proto_item_set_text(command_item, "Command data");
command_tree = proto_item_add_subtree(command_item, ett_command);
proto_tree_add_item(command_tree, hf_command, tvb, 0, 2, ENC_BIG_ENDIAN);
s = val_to_str_const(tvb_get_ntohs(tvb, 0), command_names, "invalid command");
col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_append_str(pinfo->cinfo, COL_INFO, s);
if (tvbsize > 2) {
if (tvb_get_ntohs(tvb, 0) == 0x0008) {
proto_item* i = proto_tree_add_text(command_tree, tvb, 2, tvbsize - 2, "Extended frame data");
if (tvbsize % 2)
proto_item_append_text(i, ", but size not multiple of 16-bit word");
}
else
proto_tree_add_text(command_tree, tvb, 2, tvbsize - 2, "Unknown data");
}
return tvbsize;
}
static int dissect_single_phasor(tvbuff_t *tvb, int offset,
double* mag, double* phase,
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
proto_item *temp_item = NULL;
proto_tree *phasor_tree = NULL;
guint length;
gint j,
cnt = block->phasors->len;
if (0 == cnt)
return offset;
length = block->phasors->len * (floating_point == block->format_ph ? 8 : 4);
temp_item = proto_tree_add_text(tree, tvb, offset, length, "Phasors (%u)", cnt);
phasor_tree = proto_item_add_subtree(temp_item, ett_data_phasors);
for (j = 0; j < cnt; j++) {
double mag, phase;
phasor_info *pi;
pi = &g_array_index(block->phasors, phasor_info, j);
temp_item = proto_tree_add_text(phasor_tree, tvb, offset,
floating_point == block->format_ph ? 8 : 4,
"Phasor #%u: \"%s\"", j + 1, pi->name);
offset += dissect_single_phasor(tvb, offset,
&mag, &phase,
block->format_ph,
block->phasor_notation);
if (integer == block->format_ph)
mag = (mag * pi->conv) * 0.00001;
#define ANGLE "/_"
#define DEGREE "\xC2\xB0"
proto_item_append_text(temp_item, ", %10.2f%c" ANGLE "%7.2f" DEGREE,
mag,
V == pi->unit ? 'V' : 'A',
phase *180.0/G_PI);
#undef ANGLE
#undef DEGREE
}
return offset;
}
static gint dissect_DFREQ(tvbuff_t *tvb, proto_tree *tree, config_block *block, gint offset)
{
if (floating_point == block->format_fr) {
gfloat tmp;
tmp = tvb_get_ntohieee_float(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Actual frequency value: %fHz", tmp); offset += 4;
tmp = tvb_get_ntohieee_float(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Rate of change of frequency: %fHz/s", tmp); offset += 4;
}
else {
gint16 tmp;
tmp = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2,
"Frequency deviation from nominal: %" G_GINT16_FORMAT "mHz (actual frequency: %.3fHz)",
tmp, block->fnom + (tmp / 1000.0));
offset += 2;
tmp = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Rate of change of frequency: %.3fHz/s", tmp / 100.0); offset += 2;
}
return offset;
}
static gint dissect_ANALOG(tvbuff_t *tvb, proto_tree *tree, config_block *block, gint offset)
{
proto_tree *analog_tree = NULL;
proto_item *temp_item = NULL;
guint length;
gint j,
cnt = block->analogs->len;
if (0 == cnt)
return offset;
length = block->analogs->len * (floating_point == block->format_an ? 4 : 2);
temp_item = proto_tree_add_text(tree, tvb, offset, length, "Analog values (%u)", cnt);
analog_tree = proto_item_add_subtree(temp_item, ett_data_analog);
for (j = 0; j < cnt; j++) {
analog_info *ai = &g_array_index(block->analogs, analog_info, j);
temp_item = proto_tree_add_text(analog_tree, tvb, offset,
floating_point == block->format_an ? 4 : 2,
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
proto_item *digital_item = NULL;
gint j,
cnt = block->num_dg;
if (0 == cnt)
return offset;
digital_item = proto_tree_add_text(tree, tvb, offset, cnt * 2, "Digital status words (%u)", cnt);
tree = proto_item_add_subtree(digital_item, ett_data_digital);
for (j = 0; j < cnt; j++) {
guint16 tmp = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Digital status word #%u: 0x%04x", j + 1, tmp);
offset += 2;
}
return offset;
}
static gint dissect_PHUNIT(tvbuff_t *tvb, proto_tree *tree, gint offset, gint cnt)
{
proto_item *temp_item = NULL;
proto_tree *temp_tree = NULL;
int i;
if (0 == cnt)
return offset;
temp_item = proto_tree_add_text(tree, tvb, offset, 4 * cnt, "Phasor conversation factors (%u)", cnt);
temp_tree = proto_item_add_subtree(temp_item, ett_conf_phconv);
for (i = 0; i < cnt; i++) {
guint32 tmp = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(temp_tree, tvb, offset, 4,
"#%u factor: %u * 10^-5, unit: %s",
i + 1,
tmp & 0x00FFFFFF,
tmp & 0xFF000000 ? "Ampere" : "Volt");
offset += 4;
}
return offset;
}
static gint dissect_ANUNIT(tvbuff_t *tvb, proto_tree *tree, gint offset, gint cnt)
{
proto_item *temp_item = NULL;
proto_tree *temp_tree = NULL;
int i;
if (0 == cnt)
return offset;
temp_item = proto_tree_add_text(tree, tvb, offset, 4 * cnt, "Analog values conversation factors (%u)", cnt);
temp_tree = proto_item_add_subtree(temp_item, ett_conf_anconv);
for (i = 0; i < cnt; i++) {
gint32 tmp = tvb_get_ntohl(tvb, offset);
temp_item = proto_tree_add_text(temp_tree, tvb, offset, 4,
"Factor for analog value #%i: %s",
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
proto_item *temp_item = NULL;
proto_tree *temp_tree = NULL;
int i;
if (0 == cnt)
return offset;
temp_item = proto_tree_add_text(tree, tvb, offset, 4 * cnt, "Masks for digital status words (%u)", cnt);
temp_tree = proto_item_add_subtree(temp_item, ett_conf_dgmask);
for (i = 0; i < cnt; i++) {
guint32 tmp = tvb_get_ntohl(tvb, offset);
temp_item = proto_tree_add_text(temp_tree, tvb, offset, 4, "Mask for status word #%u: ", i + 1);
proto_item_append_text(temp_item, "normal state: 0x%04"G_GINT16_MODIFIER"x", (guint16)((tmp & 0xFFFF0000) >> 16));
proto_item_append_text(temp_item, ", valid bits: 0x%04"G_GINT16_MODIFIER"x", (guint16)( tmp & 0x0000FFFF));
offset += 4;
}
return offset;
}
static gint dissect_CHNAM(tvbuff_t *tvb, proto_tree *tree, gint offset, gint cnt, const char *prefix)
{
proto_item *temp_item = NULL;
proto_tree *temp_tree = NULL;
int i;
if (0 == cnt)
return offset;
temp_item = proto_tree_add_text(tree, tvb, offset, CHNAM_LEN * cnt, "%ss (%u)", prefix, cnt);
temp_tree = proto_item_add_subtree(temp_item, ett_conf_phnam);
for (i = 0; i < cnt; i++) {
char *str;
str = tvb_get_string(wmem_packet_scope(), tvb, offset, CHNAM_LEN);
proto_tree_add_text(temp_tree, tvb, offset, CHNAM_LEN,
"%s #%i: \"%s\"", prefix, i+1, str);
offset += CHNAM_LEN;
}
return offset;
}
void proto_register_synphasor(void)
{
static hf_register_info hf[] = {
{ &hf_sync,
{ "Synchronization word", PROTOCOL_ABBREV ".sync", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_sync_frtype,
{ "Frame Type", PROTOCOL_ABBREV ".frtype", FT_UINT16, BASE_HEX,
VALS(typenames), 0x0070, NULL, HFILL }},
{ &hf_sync_version,
{ "Version", PROTOCOL_ABBREV ".version", FT_UINT16, BASE_DEC,
VALS(versionnames), 0x000F, NULL, HFILL }},
{ &hf_frsize,
{ "Framesize", PROTOCOL_ABBREV ".frsize", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_idcode,
{ "PMU/DC ID number", PROTOCOL_ABBREV ".idcode", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_soc,
{ "SOC time stamp (UTC)", PROTOCOL_ABBREV ".soc", FT_STRINGZ, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_timeqal_lsdir,
{ "Leap second direction", PROTOCOL_ABBREV ".timeqal.lsdir", FT_BOOLEAN, 8,
NULL, 0x40, NULL, HFILL }},
{ &hf_timeqal_lsocc,
{ "Leap second occurred", PROTOCOL_ABBREV ".timeqal.lsocc", FT_BOOLEAN, 8,
NULL, 0x20, NULL, HFILL }},
{ &hf_timeqal_lspend,
{ "Leap second pending", PROTOCOL_ABBREV ".timeqal.lspend", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL }},
{ &hf_timeqal_timequalindic,
{ "Time Quality indicator code", PROTOCOL_ABBREV ".timeqal.timequalindic", FT_UINT8, BASE_HEX,
VALS(timequalcodes), 0x0F, NULL, HFILL }},
{ &hf_fracsec,
{ "Fraction of second (raw)", PROTOCOL_ABBREV ".fracsec", FT_UINT24, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_conf_timebase,
{ "Resolution of fractional second time stamp", PROTOCOL_ABBREV ".conf.timebase", FT_UINT24, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_conf_numpmu,
{ "Number of PMU blocks included in the frame", PROTOCOL_ABBREV ".conf.numpmu", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_conf_formatb3,
{ "FREQ/DFREQ format", PROTOCOL_ABBREV ".conf.dfreq_format", FT_BOOLEAN, 16,
TFS(&conf_formatb123names), 0x8, NULL, HFILL }},
{ &hf_conf_formatb2,
{ "Analog values format", PROTOCOL_ABBREV ".conf.analog_format", FT_BOOLEAN, 16,
TFS(&conf_formatb123names), 0x4, NULL, HFILL }},
{ &hf_conf_formatb1,
{ "Phasor format", PROTOCOL_ABBREV ".conf.phasor_format", FT_BOOLEAN, 16,
TFS(&conf_formatb123names), 0x2, NULL, HFILL }},
{ &hf_conf_formatb0,
{ "Phasor notation", PROTOCOL_ABBREV ".conf.phasor_notation", FT_BOOLEAN, 16,
TFS(&conf_formatb0names), 0x1, NULL, HFILL }},
{ &hf_conf_fnom,
{ "Nominal line freqency", PROTOCOL_ABBREV ".conf.fnom", FT_BOOLEAN, 16,
TFS(&conf_fnomnames), 0x0001, NULL, HFILL }},
{ &hf_conf_cfgcnt,
{ "Configuration change count", PROTOCOL_ABBREV ".conf.cfgcnt", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_data_statb15,
{ "Data valid", PROTOCOL_ABBREV ".data.valid", FT_BOOLEAN, 16,
TFS(&data_statb15names), 0x8000, NULL, HFILL }},
{ &hf_data_statb14,
{ "PMU error", PROTOCOL_ABBREV ".data.PMUerror", FT_BOOLEAN, 16,
TFS(&data_statb14names), 0x4000, NULL, HFILL }},
{ &hf_data_statb13,
{ "Time synchronized", PROTOCOL_ABBREV ".data.sync", FT_BOOLEAN, 16,
TFS(&data_statb13names), 0x2000, NULL, HFILL }},
{ &hf_data_statb12,
{ "Data sorting", PROTOCOL_ABBREV ".data.sorting", FT_BOOLEAN, 16,
TFS(&data_statb12names), 0x1000, NULL, HFILL }},
{ &hf_data_statb11,
{ "Trigger detected", PROTOCOL_ABBREV ".data.trigger", FT_BOOLEAN, 16,
TFS(&data_statb11names), 0x0800, NULL, HFILL }},
{ &hf_data_statb10,
{ "Configuration changed", PROTOCOL_ABBREV ".data.CFGchange", FT_BOOLEAN, 16,
TFS(&data_statb10names), 0x0400, NULL, HFILL }},
{ &hf_data_statb05to04,
{ "Unlocked time", PROTOCOL_ABBREV ".data.t_unlock", FT_UINT16, BASE_HEX,
VALS(data_statb05to04names), 0x0030, NULL, HFILL }},
{ &hf_data_statb03to00,
{ "Trigger reason", PROTOCOL_ABBREV ".data.trigger_reason", FT_UINT16, BASE_HEX,
VALS(data_statb03to00names), 0x000F, NULL, HFILL }},
{ &hf_command,
{ "Command", PROTOCOL_ABBREV ".command", FT_UINT16, BASE_HEX,
VALS(command_names), 0x000F, NULL, HFILL }}
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
&ett_command
};
module_t *synphasor_module;
proto_synphasor = proto_register_protocol(PROTOCOL_NAME,
PROTOCOL_SHORT_NAME,
PROTOCOL_ABBREV);
synphasor_udp_handle = new_register_dissector("synphasor", dissect_udp, proto_synphasor);
proto_register_field_array(proto_synphasor, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
synphasor_module = prefs_register_protocol(proto_synphasor, proto_reg_handoff_synphasor);
prefs_register_uint_preference(synphasor_module, "udp_port", "Synchrophasor UDP port",
"Set the port number for synchrophasor frames over UDP" \
"(if other than the default of 4713)",
10, &global_pref_udp_port);
prefs_register_uint_preference(synphasor_module, "tcp_port", "Synchrophasor TCP port",
"Set the port number for synchrophasor frames over TCP" \
"(if other than the default of 4712)",
10, &global_pref_tcp_port);
register_init_routine(&synphasor_init);
}
void proto_reg_handoff_synphasor(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t synphasor_tcp_handle;
static guint current_udp_port;
static guint current_tcp_port;
if (!initialized) {
synphasor_tcp_handle = new_create_dissector_handle(dissect_tcp, proto_synphasor);
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
