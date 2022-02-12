static guint32
parse_num (const char *str, int offset)
{
unsigned long num;
char *c;
num = strtoul(str, &c, offset ? offset_base : 16);
if (c==str) {
fprintf(stderr, "FATAL ERROR: Bad hex number? [%s]\n", str);
}
return (guint32)num;
}
static void
write_byte (const char *str)
{
guint32 num;
num = parse_num(str, FALSE);
packet_buf[curr_offset] = (guint8) num;
curr_offset ++;
if (curr_offset >= max_offset)
start_new_packet();
}
static void
unwrite_bytes (guint32 nbytes)
{
curr_offset -= nbytes;
}
static guint32
number_of_padding_bytes (guint32 length)
{
guint32 remainder;
remainder = length % 4;
if (remainder == 0)
return 0;
else
return 4 - remainder;
}
void
write_current_packet (void)
{
int prefix_length = 0;
int proto_length = 0;
int ip_length = 0;
int eth_trailer_length = 0;
int prefix_index = 0;
int i, padding_length;
if (curr_offset > 0) {
prefix_length = 0;
if (hdr_data_chunk) { prefix_length += (int)sizeof(HDR_DATA_CHUNK); }
if (hdr_sctp) { prefix_length += (int)sizeof(HDR_SCTP); }
if (hdr_udp) { prefix_length += (int)sizeof(HDR_UDP); proto_length = prefix_length + curr_offset; }
if (hdr_tcp) { prefix_length += (int)sizeof(HDR_TCP); proto_length = prefix_length + curr_offset; }
if (hdr_ip) {
prefix_length += (int)sizeof(HDR_IP);
ip_length = prefix_length + curr_offset + ((hdr_data_chunk) ? number_of_padding_bytes(curr_offset) : 0);
}
if (hdr_ethernet) { prefix_length += (int)sizeof(HDR_ETHERNET); }
memmove(&packet_buf[prefix_length], packet_buf, curr_offset);
if (hdr_ethernet) {
if (prefix_length + curr_offset < 60) {
eth_trailer_length = 60 - (prefix_length + curr_offset);
}
}
if (hdr_ethernet) {
HDR_ETHERNET.l3pid = g_htons(hdr_ethernet_proto);
memcpy(&packet_buf[prefix_index], &HDR_ETHERNET, sizeof(HDR_ETHERNET));
prefix_index += (int)sizeof(HDR_ETHERNET);
}
if (hdr_ip) {
vec_t cksum_vector[1];
HDR_IP.packet_length = g_htons(ip_length);
HDR_IP.protocol = (guint8) hdr_ip_proto;
HDR_IP.hdr_checksum = 0;
cksum_vector[0].ptr = (guint8 *)&HDR_IP; cksum_vector[0].len = sizeof(HDR_IP);
HDR_IP.hdr_checksum = in_cksum(cksum_vector, 1);
memcpy(&packet_buf[prefix_index], &HDR_IP, sizeof(HDR_IP));
prefix_index += (int)sizeof(HDR_IP);
}
pseudoh.src_addr = HDR_IP.src_addr;
pseudoh.dest_addr = HDR_IP.dest_addr;
pseudoh.zero = 0;
pseudoh.protocol = (guint8) hdr_ip_proto;
pseudoh.length = g_htons(proto_length);
if (hdr_udp) {
vec_t cksum_vector[3];
HDR_UDP.source_port = g_htons(hdr_src_port);
HDR_UDP.dest_port = g_htons(hdr_dest_port);
HDR_UDP.length = g_htons(proto_length);
HDR_UDP.checksum = 0;
cksum_vector[0].ptr = (guint8 *)&pseudoh; cksum_vector[0].len = sizeof(pseudoh);
cksum_vector[1].ptr = (guint8 *)&HDR_UDP; cksum_vector[1].len = sizeof(HDR_UDP);
cksum_vector[2].ptr = &packet_buf[prefix_length]; cksum_vector[2].len = curr_offset;
HDR_UDP.checksum = in_cksum(cksum_vector, 3);
memcpy(&packet_buf[prefix_index], &HDR_UDP, sizeof(HDR_UDP));
prefix_index += (int)sizeof(HDR_UDP);
}
if (hdr_tcp) {
vec_t cksum_vector[3];
HDR_TCP.source_port = g_htons(hdr_src_port);
HDR_TCP.dest_port = g_htons(hdr_dest_port);
HDR_TCP.window = g_htons(0x2000);
HDR_TCP.checksum = 0;
cksum_vector[0].ptr = (guint8 *)&pseudoh; cksum_vector[0].len = sizeof(pseudoh);
cksum_vector[1].ptr = (guint8 *)&HDR_TCP; cksum_vector[1].len = sizeof(HDR_TCP);
cksum_vector[2].ptr = &packet_buf[prefix_length]; cksum_vector[2].len = curr_offset;
HDR_TCP.checksum = in_cksum(cksum_vector, 3);
memcpy(&packet_buf[prefix_index], &HDR_TCP, sizeof(HDR_TCP));
prefix_index += (int)sizeof(HDR_TCP);
}
if (hdr_data_chunk) {
HDR_DATA_CHUNK.type = hdr_data_chunk_type;
HDR_DATA_CHUNK.bits = hdr_data_chunk_bits;
HDR_DATA_CHUNK.length = g_htons(curr_offset + sizeof(HDR_DATA_CHUNK));
HDR_DATA_CHUNK.tsn = g_htonl(hdr_data_chunk_tsn);
HDR_DATA_CHUNK.sid = g_htons(hdr_data_chunk_sid);
HDR_DATA_CHUNK.ssn = g_htons(hdr_data_chunk_ssn);
HDR_DATA_CHUNK.ppid = g_htonl(hdr_data_chunk_ppid);
padding_length = number_of_padding_bytes(curr_offset);
for (i=0; i<padding_length; i++)
packet_buf[prefix_length+curr_offset+i] = 0;
curr_offset += padding_length;
}
if (hdr_sctp) {
HDR_SCTP.src_port = g_htons(hdr_sctp_src);
HDR_SCTP.dest_port = g_htons(hdr_sctp_dest);
HDR_SCTP.tag = g_htonl(hdr_sctp_tag);
HDR_SCTP.checksum = g_htonl(0);
HDR_SCTP.checksum = crc32c_calculate(&HDR_SCTP, sizeof(HDR_SCTP), CRC32C_PRELOAD);
if (hdr_data_chunk)
HDR_SCTP.checksum = crc32c_calculate(&HDR_DATA_CHUNK, sizeof(HDR_DATA_CHUNK), HDR_SCTP.checksum);
HDR_SCTP.checksum = g_htonl(~crc32c_calculate(&packet_buf[prefix_length], curr_offset, HDR_SCTP.checksum));
memcpy(&packet_buf[prefix_index], &HDR_SCTP, sizeof(HDR_SCTP));
prefix_index += (int)sizeof(HDR_SCTP);
}
if (hdr_data_chunk) {
memcpy(&packet_buf[prefix_index], &HDR_DATA_CHUNK, sizeof(HDR_DATA_CHUNK));
}
if (hdr_ethernet && eth_trailer_length > 0) {
memset(&packet_buf[prefix_length+curr_offset], 0, eth_trailer_length);
}
HDR_TCP.seq_num = g_ntohl(HDR_TCP.seq_num) + curr_offset;
HDR_TCP.seq_num = g_htonl(HDR_TCP.seq_num);
{
struct wtap_pkthdr pkthdr;
int err;
memset(&pkthdr, 0, sizeof(struct wtap_pkthdr));
pkthdr.rec_type = REC_TYPE_PACKET;
pkthdr.ts.secs = (guint32)ts_sec;
pkthdr.ts.nsecs = ts_usec * 1000;
if (ts_fmt == NULL) { ts_usec++; }
pkthdr.caplen = pkthdr.len = prefix_length + curr_offset + eth_trailer_length;
pkthdr.pkt_encap = pcap_link_type;
pkthdr.pack_flags |= direction;
pkthdr.presence_flags = WTAP_HAS_CAP_LEN|WTAP_HAS_INTERFACE_ID|WTAP_HAS_TS|WTAP_HAS_PACK_FLAGS;
wtap_dump(wdh, &pkthdr, packet_buf, &err);
}
}
packet_start += curr_offset;
curr_offset = 0;
}
static void
append_to_preamble(char *str)
{
size_t toklen;
if (packet_preamble_len != 0) {
if (packet_preamble_len == PACKET_PREAMBLE_MAX_LEN)
return;
packet_preamble[packet_preamble_len++] = ' ';
}
toklen = strlen(str);
if (toklen != 0) {
if (packet_preamble_len + toklen > PACKET_PREAMBLE_MAX_LEN)
return;
g_strlcpy(&packet_preamble[packet_preamble_len], str, PACKET_PREAMBLE_MAX_LEN);
packet_preamble_len += (int) toklen;
if (debug >= 2) {
char *c;
char xs[PACKET_PREAMBLE_MAX_LEN];
g_strlcpy(xs, packet_preamble, PACKET_PREAMBLE_MAX_LEN);
while ((c = strchr(xs, '\r')) != NULL) *c=' ';
fprintf (stderr, "[[append_to_preamble: \"%s\"]]", xs);
}
}
}
static void
parse_preamble (void)
{
struct tm timecode;
char *subsecs;
char *p;
int subseclen;
int i;
packet_preamble[packet_preamble_len] = '\0';
if (has_direction) {
switch (packet_preamble[0]) {
case 'i':
case 'I':
direction = 0x00000001;
packet_preamble[0] = ' ';
break;
case 'o':
case 'O':
direction = 0x00000002;
packet_preamble[0] = ' ';
break;
default:
direction = 0x00000000;
break;
}
i = 0;
while (packet_preamble[i] == ' ' ||
packet_preamble[i] == '\r' ||
packet_preamble[i] == '\t') {
i++;
}
packet_preamble_len -= i;
memmove(packet_preamble, packet_preamble + i, packet_preamble_len + 1);
}
if (ts_fmt == NULL)
return;
timecode = timecode_default;
ts_usec = 0;
if ( strlen(packet_preamble) > 2 ) {
subsecs = strptime( packet_preamble, ts_fmt, &timecode );
if (subsecs != NULL) {
ts_sec = mktime( &timecode );
} else
ts_sec = -1;
if ( -1 == ts_sec )
{
char *c;
while ((c = strchr(packet_preamble, '\r')) != NULL) *c=' ';
fprintf (stderr, "Failure processing time \"%s\" using time format \"%s\"\n (defaulting to Jan 1,1970 00:00:00 GMT)\n",
packet_preamble, ts_fmt);
if (debug >= 2) {
fprintf(stderr, "timecode: %02d/%02d/%d %02d:%02d:%02d %d\n",
timecode.tm_mday, timecode.tm_mon, timecode.tm_year,
timecode.tm_hour, timecode.tm_min, timecode.tm_sec, timecode.tm_isdst);
}
ts_sec = 0;
ts_usec = 0;
}
else
{
ts_usec = (guint32)strtol(subsecs, &p, 10);
if (subsecs == p) {
ts_usec = 0;
} else {
subseclen = (int) (p - subsecs);
if (subseclen > 6) {
for (i = subseclen - 6; i != 0; i--)
ts_usec /= 10;
} else if (subseclen < 6) {
for (i = 6 - subseclen; i != 0; i--)
ts_usec *= 10;
}
}
}
}
if (debug >= 2) {
char *c;
while ((c = strchr(packet_preamble, '\r')) != NULL) *c=' ';
fprintf(stderr, "[[parse_preamble: \"%s\"]]\n", packet_preamble);
fprintf(stderr, "Format(%s), time(%u), subsecs(%u)\n", ts_fmt, (guint32)ts_sec, ts_usec);
}
packet_preamble_len = 0;
}
static void
start_new_packet (void)
{
if (debug>=1)
fprintf(stderr, "Start new packet\n");
write_current_packet();
parse_preamble();
}
static void
process_directive (char *str)
{
fprintf(stderr, "\n--- Directive [%s] currently unsupported ---\n", str+10);
}
void
parse_token (token_t token, char *str)
{
guint32 num;
if (debug>=2) {
char *c;
if (str!=NULL) { while ((c = strchr(str, '\r')) != NULL) *c=' '; }
fprintf(stderr, "(%s, %s \"%s\") -> (",
state_str[state], token_str[token], str ? str : "");
}
switch(state) {
case INIT:
switch(token) {
case T_TEXT:
append_to_preamble(str);
break;
case T_DIRECTIVE:
process_directive(str);
break;
case T_OFFSET:
num = parse_num(str, TRUE);
if (num==0) {
start_new_packet();
state = READ_OFFSET;
}
break;
default:
break;
}
break;
case START_OF_LINE:
switch(token) {
case T_TEXT:
append_to_preamble(str);
break;
case T_DIRECTIVE:
process_directive(str);
break;
case T_OFFSET:
num = parse_num(str, TRUE);
if (num==0) {
start_new_packet();
packet_start = 0;
state = READ_OFFSET;
} else if ((num - packet_start) != curr_offset) {
if (num < curr_offset) {
unwrite_bytes(curr_offset - num);
state = READ_OFFSET;
} else {
if (debug>=1)
fprintf(stderr, "Inconsistent offset. Expecting %0X, got %0X. Ignoring rest of packet\n",
curr_offset, num);
write_current_packet();
state = INIT;
}
} else
state = READ_OFFSET;
break;
default:
break;
}
break;
case READ_OFFSET:
switch(token) {
case T_BYTE:
state = READ_BYTE;
write_byte(str);
break;
case T_TEXT:
case T_DIRECTIVE:
case T_OFFSET:
state = READ_TEXT;
break;
case T_EOL:
state = START_OF_LINE;
break;
default:
break;
}
break;
case READ_BYTE:
switch(token) {
case T_BYTE:
write_byte(str);
break;
case T_TEXT:
case T_DIRECTIVE:
case T_OFFSET:
state = READ_TEXT;
break;
case T_EOL:
state = START_OF_LINE;
break;
default:
break;
}
break;
case READ_TEXT:
switch(token) {
case T_EOL:
state = START_OF_LINE;
break;
default:
break;
}
break;
default:
fprintf(stderr, "FATAL ERROR: Bad state (%d)", state);
exit(-1);
}
if (debug>=2)
fprintf(stderr, ", %s)\n", state_str[state]);
}
void
text_import_setup(text_import_info_t *info)
{
packet_buf = (guint8 *)g_malloc(sizeof(HDR_ETHERNET) + sizeof(HDR_IP) +
sizeof(HDR_SCTP) + sizeof(HDR_DATA_CHUNK) +
IMPORT_MAX_PACKET);
if (!packet_buf)
{
fprintf(stderr, "FATAL ERROR: no memory for packet buffer");
exit(-1);
}
state = INIT;
curr_offset = 0;
packet_start = 0;
packet_preamble_len = 0;
ts_sec = time(0);
timecode_default = *localtime(&ts_sec);
timecode_default.tm_isdst = -1;
ts_usec = 0;
hdr_ethernet = FALSE;
hdr_ip = FALSE;
hdr_udp = FALSE;
hdr_tcp = FALSE;
hdr_sctp = FALSE;
hdr_data_chunk = FALSE;
offset_base = (info->offset_type == OFFSET_HEX) ? 16 :
(info->offset_type == OFFSET_OCT) ? 8 :
(info->offset_type == OFFSET_DEC) ? 10 :
16;
has_direction = info->has_direction;
if (info->date_timestamp)
{
ts_fmt = info->date_timestamp_format;
}
pcap_link_type = info->encapsulation;
wdh = info->wdh;
switch (info->dummy_header_type)
{
case HEADER_ETH:
hdr_ethernet = TRUE;
hdr_ethernet_proto = info->pid;
break;
case HEADER_IPV4:
hdr_ip = TRUE;
hdr_ip_proto = info->protocol;
hdr_ethernet = TRUE;
hdr_ethernet_proto = 0x800;
break;
case HEADER_UDP:
hdr_udp = TRUE;
hdr_tcp = FALSE;
hdr_src_port = info->src_port;
hdr_dest_port = info->dst_port;
hdr_ip = TRUE;
hdr_ip_proto = 17;
hdr_ethernet = TRUE;
hdr_ethernet_proto = 0x800;
break;
case HEADER_TCP:
hdr_tcp = TRUE;
hdr_udp = FALSE;
hdr_src_port = info->src_port;
hdr_dest_port = info->dst_port;
hdr_ip = TRUE;
hdr_ip_proto = 6;
hdr_ethernet = TRUE;
hdr_ethernet_proto = 0x800;
break;
case HEADER_SCTP:
hdr_sctp = TRUE;
hdr_sctp_src = info->src_port;
hdr_sctp_dest = info->dst_port;
hdr_sctp_tag = info->tag;
hdr_ip = TRUE;
hdr_ip_proto = 132;
hdr_ethernet = TRUE;
hdr_ethernet_proto = 0x800;
break;
case HEADER_SCTP_DATA:
hdr_sctp = TRUE;
hdr_data_chunk = TRUE;
hdr_sctp_src = info->src_port;
hdr_sctp_dest = info->dst_port;
hdr_data_chunk_ppid = info->ppi;
hdr_ip = TRUE;
hdr_ip_proto = 132;
hdr_ethernet = TRUE;
hdr_ethernet_proto = 0x800;
break;
default:
break;
}
max_offset = info->max_frame_length;
}
void
text_import_cleanup(void)
{
g_free(packet_buf);
}
