static unsigned long
parse_num (const char *str, int offset)
{
unsigned long num;
char *c;
num = strtoul(str, &c, offset ? offset_base : 16);
if (c==str) {
fprintf(stderr, "FATAL ERROR: Bad hex number? [%s]\n", str);
exit(-1);
}
return num;
}
static void
write_byte (const char *str)
{
unsigned long num;
num = parse_num(str, FALSE);
packet_buf[curr_offset] = (unsigned char) num;
curr_offset ++;
if (curr_offset >= max_offset)
start_new_packet();
}
static void
unwrite_bytes (unsigned long nbytes)
{
curr_offset -= nbytes;
}
static guint16
in_checksum (void *buf, unsigned long count)
{
unsigned long sum = 0;
guint16 *addr = buf;
while( count > 1 ) {
sum += g_ntohs(* (guint16 *) addr);
addr++;
count -= 2;
}
if( count > 0 )
sum += g_ntohs(* (guint8 *) addr);
while (sum>>16)
sum = (sum & 0xffff) + (sum >> 16);
sum = ~sum;
return g_htons(sum);
}
static guint32
crc32c(const guint8* buf, unsigned int len, guint32 crc32_init)
{
unsigned int i;
guint32 crc32;
crc32 = crc32_init;
for (i = 0; i < len; i++)
CRC32C(crc32, buf[i]);
return ( crc32 );
}
static guint32
finalize_crc32c(guint32 crc32)
{
guint32 result;
guint8 byte0,byte1,byte2,byte3;
result = ~crc32;
byte0 = result & 0xff;
byte1 = (result>>8) & 0xff;
byte2 = (result>>16) & 0xff;
byte3 = (result>>24) & 0xff;
result = ((byte0 << 24) | (byte1 << 16) | (byte2 << 8) | byte3);
return ( result );
}
static unsigned long
number_of_padding_bytes (unsigned long length)
{
unsigned long remainder;
remainder = length % 4;
if (remainder == 0)
return 0;
else
return 4 - remainder;
}
static void
write_current_packet (void)
{
int length = 0;
int proto_length = 0;
int ip_length = 0;
int eth_trailer_length = 0;
int i, padding_length;
guint32 u;
struct pcaprec_hdr ph;
if (curr_offset > 0) {
length = curr_offset;
if (hdr_data_chunk) { length += sizeof(HDR_DATA_CHUNK) + number_of_padding_bytes(curr_offset); }
if (hdr_sctp) { length += sizeof(HDR_SCTP); }
if (hdr_udp) { length += sizeof(HDR_UDP); proto_length = length; }
if (hdr_tcp) { length += sizeof(HDR_TCP); proto_length = length; }
if (hdr_ip) { length += sizeof(HDR_IP); ip_length = length; }
if (hdr_ethernet) {
length += sizeof(HDR_ETHERNET);
if (length < 60) {
eth_trailer_length = 60 - length;
length = 60;
}
}
ph.ts_sec = (guint32)ts_sec;
ph.ts_usec = ts_usec;
if (ts_fmt == NULL) { ts_usec++; }
ph.incl_len = length;
ph.orig_len = length;
if (fwrite(&ph, sizeof(ph), 1, output_file) != 1)
goto write_current_packet_err;
if (hdr_ethernet) {
HDR_ETHERNET.l3pid = g_htons(hdr_ethernet_proto);
if (fwrite(&HDR_ETHERNET, sizeof(HDR_ETHERNET), 1, output_file) != 1)
goto write_current_packet_err;
}
if (hdr_ip) {
HDR_IP.packet_length = g_htons(ip_length);
HDR_IP.protocol = (guint8) hdr_ip_proto;
HDR_IP.hdr_checksum = 0;
HDR_IP.hdr_checksum = in_checksum(&HDR_IP, sizeof(HDR_IP));
if (fwrite(&HDR_IP, sizeof(HDR_IP), 1, output_file) != 1)
goto write_current_packet_err;
}
pseudoh.src_addr = HDR_IP.src_addr;
pseudoh.dest_addr = HDR_IP.dest_addr;
pseudoh.zero = 0;
pseudoh.protocol = (guint8) hdr_ip_proto;
pseudoh.length = g_htons(proto_length);
if (hdr_udp) {
guint16 x16;
HDR_UDP.source_port = g_htons(hdr_src_port);
HDR_UDP.dest_port = g_htons(hdr_dest_port);
HDR_UDP.length = g_htons(proto_length);
HDR_UDP.checksum = 0;
x16 = in_checksum(&pseudoh, sizeof(pseudoh));
u = g_ntohs(x16);
x16 = in_checksum(&HDR_UDP, sizeof(HDR_UDP));
u += g_ntohs(x16);
x16 = in_checksum(packet_buf, curr_offset);
u += g_ntohs(x16);
x16 = (u & 0xffff) + (u>>16);
HDR_UDP.checksum = g_htons(x16);
if (HDR_UDP.checksum == 0)
HDR_UDP.checksum = g_htons(1);
if (fwrite(&HDR_UDP, sizeof(HDR_UDP), 1, output_file) != 1)
goto write_current_packet_err;
}
if (hdr_tcp) {
guint16 x16;
HDR_TCP.source_port = g_htons(hdr_src_port);
HDR_TCP.dest_port = g_htons(hdr_dest_port);
HDR_TCP.window = g_htons(0x2000);
HDR_TCP.checksum = 0;
x16 = in_checksum(&pseudoh, sizeof(pseudoh));
u = g_ntohs(x16);
x16 = in_checksum(&HDR_TCP, sizeof(HDR_TCP));
u += g_ntohs(x16);
x16 = in_checksum(packet_buf, curr_offset);
u += g_ntohs(x16);
x16 = (u & 0xffff) + (u>>16);
HDR_TCP.checksum = g_htons(x16);
if (HDR_TCP.checksum == 0)
HDR_TCP.checksum = g_htons(1);
if (fwrite(&HDR_TCP, sizeof(HDR_TCP), 1, output_file) != 1)
goto write_current_packet_err;
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
write_byte("0");
}
if (hdr_sctp) {
guint32 x32;
HDR_SCTP.src_port = g_htons(hdr_sctp_src);
HDR_SCTP.dest_port = g_htons(hdr_sctp_dest);
HDR_SCTP.tag = g_htonl(hdr_sctp_tag);
HDR_SCTP.checksum = g_htonl(0);
HDR_SCTP.checksum = crc32c((guint8 *)&HDR_SCTP, sizeof(HDR_SCTP), ~0L);
if (hdr_data_chunk)
HDR_SCTP.checksum = crc32c((guint8 *)&HDR_DATA_CHUNK, sizeof(HDR_DATA_CHUNK), HDR_SCTP.checksum);
x32 = finalize_crc32c(crc32c(packet_buf, curr_offset, HDR_SCTP.checksum));
HDR_SCTP.checksum = g_htonl(x32);
if (fwrite(&HDR_SCTP, sizeof(HDR_SCTP), 1, output_file) != 1)
goto write_current_packet_err;
}
if (hdr_data_chunk) {
if (fwrite(&HDR_DATA_CHUNK, sizeof(HDR_DATA_CHUNK), 1, output_file) != 1)
goto write_current_packet_err;
}
if (fwrite(packet_buf, curr_offset, 1, output_file) != 1)
goto write_current_packet_err;
if (hdr_ethernet && eth_trailer_length > 0) {
memset(tempbuf, 0, eth_trailer_length);
if (fwrite(tempbuf, eth_trailer_length, 1, output_file) != 1)
goto write_current_packet_err;
}
if (!quiet)
fprintf(stderr, "Wrote packet of %lu bytes at %u\n", curr_offset, g_ntohl(HDR_TCP.seq_num));
num_packets_written ++;
}
HDR_TCP.seq_num = g_ntohl(HDR_TCP.seq_num) + curr_offset;
HDR_TCP.seq_num = g_htonl(HDR_TCP.seq_num);
packet_start += curr_offset;
curr_offset = 0;
return;
write_current_packet_err:
fprintf(stderr, "File write error [%s] : %s\n",
output_filename, g_strerror(errno));
exit(-1);
}
static void
write_file_header (void)
{
struct pcap_hdr fh;
fh.magic = PCAP_MAGIC;
fh.version_major = 2;
fh.version_minor = 4;
fh.thiszone = 0;
fh.sigfigs = 0;
fh.snaplen = 102400;
fh.network = pcap_link_type;
if (fwrite(&fh, sizeof(fh), 1, output_file) != 1) {
fprintf(stderr, "File write error [%s] : %s\n",
output_filename, g_strerror(errno));
exit(-1);
}
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
if (ts_fmt == NULL)
return;
timecode = timecode_default;
ts_usec = 0;
packet_preamble[packet_preamble_len] = '\0';
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
ts_usec = strtol(subsecs, &p, 10);
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
num_packets_read ++;
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
unsigned long num;
int by_eol;
int rollback = 0;
int line_size;
int i;
char* s2;
char tmp_str[3];
if (debug>=2) {
char *c;
if (str!=NULL) { while ((c = strchr(str, '\r')) != NULL) *c=' '; }
fprintf(stderr, "(%s, %s \"%s\") -> (",
state_str[state], token_str[token], str ? str : "");
}
if (state == INIT || state == START_OF_LINE) {
if (ts_fmt != NULL && new_date_fmt) {
token = T_TEXT;
}
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
pkt_lnstart = packet_buf + num;
}
break;
case T_EOL:
state = START_OF_LINE;
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
fprintf(stderr, "Inconsistent offset. Expecting %0lX, got %0lX. Ignoring rest of packet\n",
curr_offset, num);
write_current_packet();
state = INIT;
}
} else
state = READ_OFFSET;
pkt_lnstart = packet_buf + num;
break;
case T_EOL:
state = START_OF_LINE;
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
case T_EOL:
by_eol = 0;
state = READ_TEXT;
if (token == T_EOL) {
by_eol = 1;
state = START_OF_LINE;
}
if (identify_ascii) {
rollback = 0;
line_size = curr_offset-(int)(pkt_lnstart-packet_buf);
s2 = (char*)g_malloc((line_size+1)/4+1);
for(i=0; i<(line_size+1)/4; i++) {
tmp_str[0] = pkt_lnstart[i*3];
tmp_str[1] = pkt_lnstart[i*3+1];
tmp_str[2] = '\0';
if (!isxdigit(tmp_str[0]) || !isxdigit(tmp_str[0])) {
break;
}
s2[i] = (char)strtoul(tmp_str, (char **)NULL, 16);
rollback++;
if (!(pkt_lnstart[i*3+2] == ' ')) {
if (by_eol != 1)
rollback--;
break;
}
}
if (rollback > 0) {
if (strncmp(pkt_lnstart+line_size-rollback, s2, rollback) == 0) {
unwrite_bytes(rollback);
}
else {
unwrite_bytes(line_size);
}
}
g_free(s2);
}
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
static void
usage (void)
{
fprintf(stderr,
"Text2pcap %s"
#ifdef SVNVERSION
" (" SVNVERSION " from " SVNPATH ")"
#endif
"\n"
"Generate a capture file from an ASCII hexdump of packets.\n"
"See http://www.wireshark.org for more information.\n"
"\n"
"Usage: text2pcap [options] <infile> <outfile>\n"
"\n"
"where <infile> specifies input filename (use - for standard input)\n"
" <outfile> specifies output filename (use - for standard output)\n"
"\n"
"Input:\n"
" -o hex|oct|dec parse offsets as (h)ex, (o)ctal or (d)ecimal;\n"
" default is hex.\n"
" -t <timefmt> treat the text before the packet as a date/time code;\n"
" the specified argument is a format string of the sort\n"
" supported by strptime.\n"
" Example: The time \"10:15:14.5476\" has the format code\n"
" \"%%H:%%M:%%S.\"\n"
" NOTE: The subsecond component delimiter, '.', must be\n"
" given, but no pattern is required; the remaining\n"
" number is assumed to be fractions of a second.\n"
" NOTE: Date/time fields from the current date/time are\n"
" used as the default for unspecified fields.\n"
" -a enable ASCII text dump identification.\n"
" It allows to identify the start of the ASCII text\n"
" dump and not include it in the packet even if it\n"
" looks like HEX dump.\n"
" NOTE: Do not enable it if the input file does not\n"
" contain the ASCII text dump.\n"
"\n"
"Output:\n"
" -l <typenum> link-layer type number; default is 1 (Ethernet).\n"
" See the file net/bpf.h for list of numbers.\n"
" Use this option if your dump is a complete hex dump\n"
" of an encapsulated packet and you wish to specify\n"
" the exact type of encapsulation.\n"
" Example: -l 7 for ARCNet packets.\n"
" -m <max-packet> max packet length in output; default is %d\n"
"\n"
"Prepend dummy header:\n"
" -e <l3pid> prepend dummy Ethernet II header with specified L3PID\n"
" (in HEX).\n"
" Example: -e 0x806 to specify an ARP packet.\n"
" -i <proto> prepend dummy IP header with specified IP protocol\n"
" (in DECIMAL).\n"
" Automatically prepends Ethernet header as well.\n"
" Example: -i 46\n"
" -u <srcp>,<destp> prepend dummy UDP header with specified\n"
" dest and source ports (in DECIMAL).\n"
" Automatically prepends Ethernet & IP headers as well.\n"
" Example: -u 1000,69 to make the packets look like\n"
" TFTP/UDP packets.\n"
" -T <srcp>,<destp> prepend dummy TCP header with specified\n"
" dest and source ports (in DECIMAL).\n"
" Automatically prepends Ethernet & IP headers as well.\n"
" Example: -T 50,60\n"
" -s <srcp>,<dstp>,<tag> prepend dummy SCTP header with specified\n"
" dest/source ports and verification tag (in DECIMAL).\n"
" Automatically prepends Ethernet & IP headers as well.\n"
" Example: -s 30,40,34\n"
" -S <srcp>,<dstp>,<ppi> prepend dummy SCTP header with specified\n"
" dest/source ports and verification tag 0.\n"
" Automatically prepends a dummy SCTP DATA\n"
" chunk header with payload protocol identifier ppi.\n"
" Example: -S 30,40,34\n"
"\n"
"Miscellaneous:\n"
" -h display this help and exit.\n"
" -d show detailed debug of parser states.\n"
" -q generate no output at all (automatically turns off -d).\n"
"",
VERSION, MAX_PACKET);
exit(-1);
}
static void
parse_options (int argc, char *argv[])
{
int c;
char *p;
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
#endif
while ((c = getopt(argc, argv, "Ddhqe:i:l:m:o:u:s:S:t:T:a")) != -1) {
switch(c) {
case '?': usage(); break;
case 'h': usage(); break;
case 'D': new_date_fmt = 1; break;
case 'd': if (!quiet) debug++; break;
case 'q': quiet = TRUE; debug = FALSE; break;
case 'l': pcap_link_type = strtol(optarg, NULL, 0); break;
case 'm': max_offset = strtol(optarg, NULL, 0); break;
case 'o':
if (optarg[0]!='h' && optarg[0] != 'o' && optarg[0] != 'd') {
fprintf(stderr, "Bad argument for '-o': %s\n", optarg);
usage();
}
switch(optarg[0]) {
case 'o': offset_base = 8; break;
case 'h': offset_base = 16; break;
case 'd': offset_base = 10; break;
}
break;
case 'e':
hdr_ethernet = TRUE;
if (sscanf(optarg, "%lx", &hdr_ethernet_proto) < 1) {
fprintf(stderr, "Bad argument for '-e': %s\n", optarg);
usage();
}
break;
case 'i':
hdr_ip = TRUE;
hdr_ip_proto = strtol(optarg, &p, 10);
if (p == optarg || *p != '\0' || hdr_ip_proto < 0 ||
hdr_ip_proto > 255) {
fprintf(stderr, "Bad argument for '-i': %s\n", optarg);
usage();
}
hdr_ethernet = TRUE;
hdr_ethernet_proto = 0x800;
break;
case 's':
hdr_sctp = TRUE;
hdr_sctp_src = strtol(optarg, &p, 10);
if (p == optarg || (*p != ',' && *p != '\0')) {
fprintf(stderr, "Bad src port for '-%c'\n", c);
usage();
}
if (*p == '\0') {
fprintf(stderr, "No dest port specified for '-%c'\n", c);
usage();
}
p++;
optarg = p;
hdr_sctp_dest = strtol(optarg, &p, 10);
if (p == optarg || (*p != ',' && *p != '\0')) {
fprintf(stderr, "Bad dest port for '-s'\n");
usage();
}
if (*p == '\0') {
fprintf(stderr, "No tag specified for '-%c'\n", c);
usage();
}
p++;
optarg = p;
hdr_sctp_tag = strtol(optarg, &p, 10);
if (p == optarg || *p != '\0') {
fprintf(stderr, "Bad tag for '-%c'\n", c);
usage();
}
hdr_ip = TRUE;
hdr_ip_proto = 132;
hdr_ethernet = TRUE;
hdr_ethernet_proto = 0x800;
break;
case 'S':
hdr_sctp = TRUE;
hdr_data_chunk = TRUE;
hdr_sctp_src = strtol(optarg, &p, 10);
if (p == optarg || (*p != ',' && *p != '\0')) {
fprintf(stderr, "Bad src port for '-%c'\n", c);
usage();
}
if (*p == '\0') {
fprintf(stderr, "No dest port specified for '-%c'\n", c);
usage();
}
p++;
optarg = p;
hdr_sctp_dest = strtol(optarg, &p, 10);
if (p == optarg || (*p != ',' && *p != '\0')) {
fprintf(stderr, "Bad dest port for '-s'\n");
usage();
}
if (*p == '\0') {
fprintf(stderr, "No ppi specified for '-%c'\n", c);
usage();
}
p++;
optarg = p;
hdr_data_chunk_ppid = strtoul(optarg, &p, 10);
if (p == optarg || *p != '\0') {
fprintf(stderr, "Bad ppi for '-%c'\n", c);
usage();
}
hdr_ip = TRUE;
hdr_ip_proto = 132;
hdr_ethernet = TRUE;
hdr_ethernet_proto = 0x800;
break;
case 't':
ts_fmt = optarg;
break;
case 'u':
hdr_udp = TRUE;
hdr_tcp = FALSE;
hdr_src_port = strtol(optarg, &p, 10);
if (p == optarg || (*p != ',' && *p != '\0')) {
fprintf(stderr, "Bad src port for '-u'\n");
usage();
}
if (*p == '\0') {
fprintf(stderr, "No dest port specified for '-u'\n");
usage();
}
p++;
optarg = p;
hdr_dest_port = strtol(optarg, &p, 10);
if (p == optarg || *p != '\0') {
fprintf(stderr, "Bad dest port for '-u'\n");
usage();
}
hdr_ip = TRUE;
hdr_ip_proto = 17;
hdr_ethernet = TRUE;
hdr_ethernet_proto = 0x800;
break;
case 'T':
hdr_tcp = TRUE;
hdr_udp = FALSE;
hdr_src_port = strtol(optarg, &p, 10);
if (p == optarg || (*p != ',' && *p != '\0')) {
fprintf(stderr, "Bad src port for '-T'\n");
usage();
}
if (*p == '\0') {
fprintf(stderr, "No dest port specified for '-u'\n");
usage();
}
p++;
optarg = p;
hdr_dest_port = strtol(optarg, &p, 10);
if (p == optarg || *p != '\0') {
fprintf(stderr, "Bad dest port for '-T'\n");
usage();
}
hdr_ip = TRUE;
hdr_ip_proto = 6;
hdr_ethernet = TRUE;
hdr_ethernet_proto = 0x800;
break;
case 'a':
identify_ascii = TRUE;
break;
default:
usage();
}
}
if (optind >= argc || argc-optind < 2) {
fprintf(stderr, "Must specify input and output filename\n");
usage();
}
if (strcmp(argv[optind], "-")) {
input_filename = g_strdup(argv[optind]);
input_file = ws_fopen(input_filename, "rb");
if (!input_file) {
fprintf(stderr, "Cannot open file [%s] for reading: %s\n",
input_filename, g_strerror(errno));
exit(-1);
}
} else {
input_filename = "Standard input";
input_file = stdin;
}
if (strcmp(argv[optind+1], "-")) {
output_filename = g_strdup(argv[optind+1]);
output_file = ws_fopen(output_filename, "wb");
if (!output_file) {
fprintf(stderr, "Cannot open file [%s] for writing: %s\n",
output_filename, g_strerror(errno));
exit(-1);
}
} else {
output_filename = "Standard output";
output_file = stdout;
}
if (pcap_link_type != 1 && hdr_ethernet) {
fprintf(stderr, "Dummy headers (-e, -i, -u, -s, -S -T) cannot be specified with link type override (-l)\n");
exit(-1);
}
if (!input_file) {
input_file = stdin;
input_filename = "Standard input";
}
if (!output_file) {
output_file = stdout;
output_filename = "Standard output";
}
ts_sec = time(0);
timecode_default = *localtime(&ts_sec);
timecode_default.tm_isdst = -1;
if (!quiet) {
fprintf(stderr, "Input from: %s\n", input_filename);
fprintf(stderr, "Output to: %s\n", output_filename);
if (hdr_ethernet) fprintf(stderr, "Generate dummy Ethernet header: Protocol: 0x%0lX\n",
hdr_ethernet_proto);
if (hdr_ip) fprintf(stderr, "Generate dummy IP header: Protocol: %ld\n",
hdr_ip_proto);
if (hdr_udp) fprintf(stderr, "Generate dummy UDP header: Source port: %ld. Dest port: %ld\n",
hdr_src_port, hdr_dest_port);
if (hdr_tcp) fprintf(stderr, "Generate dummy TCP header: Source port: %ld. Dest port: %ld\n",
hdr_src_port, hdr_dest_port);
if (hdr_sctp) fprintf(stderr, "Generate dummy SCTP header: Source port: %ld. Dest port: %ld. Tag: %ld\n",
hdr_sctp_src, hdr_sctp_dest, hdr_sctp_tag);
if (hdr_data_chunk) fprintf(stderr, "Generate dummy DATA chunk header: TSN: %lu. SID: %d. SSN: %d. PPID: %lu\n",
hdr_data_chunk_tsn, hdr_data_chunk_sid, hdr_data_chunk_ssn, hdr_data_chunk_ppid);
}
}
int
main(int argc, char *argv[])
{
parse_options(argc, argv);
assert(input_file != NULL);
assert(output_file != NULL);
write_file_header();
yyin = input_file;
yylex();
write_current_packet();
fclose(input_file);
fclose(output_file);
if (debug)
fprintf(stderr, "\n-------------------------\n");
if (!quiet) {
fprintf(stderr, "Read %ld potential packet%s, wrote %ld packet%s\n",
num_packets_read, (num_packets_read==1) ?"":"s",
num_packets_written, (num_packets_written==1)?"":"s");
}
return 0;
}
