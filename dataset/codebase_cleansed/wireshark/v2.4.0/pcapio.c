static gboolean
write_to_file(FILE* pfile, const guint8* data, size_t data_length,
guint64 *bytes_written, int *err)
{
size_t nwritten;
nwritten = fwrite(data, data_length, 1, pfile);
if (nwritten != 1) {
if (ferror(pfile)) {
*err = errno;
} else {
*err = 0;
}
return FALSE;
}
(*bytes_written) += data_length;
return TRUE;
}
gboolean
libpcap_write_file_header(FILE* pfile, int linktype, int snaplen, gboolean ts_nsecs, guint64 *bytes_written, int *err)
{
struct pcap_hdr file_hdr;
file_hdr.magic = ts_nsecs ? PCAP_NSEC_MAGIC : PCAP_MAGIC;
file_hdr.version_major = 2;
file_hdr.version_minor = 4;
file_hdr.thiszone = 0;
file_hdr.sigfigs = 0;
file_hdr.snaplen = snaplen;
file_hdr.network = linktype;
return write_to_file(pfile, (const guint8*)&file_hdr, sizeof(file_hdr), bytes_written, err);
}
gboolean
libpcap_write_packet(FILE* pfile,
time_t sec, guint32 usec,
guint32 caplen, guint32 len,
const guint8 *pd,
guint64 *bytes_written, int *err)
{
struct pcaprec_hdr rec_hdr;
rec_hdr.ts_sec = (guint32)sec;
rec_hdr.ts_usec = usec;
rec_hdr.incl_len = caplen;
rec_hdr.orig_len = len;
if (!write_to_file(pfile, (const guint8*)&rec_hdr, sizeof(rec_hdr), bytes_written, err))
return FALSE;
return write_to_file(pfile, pd, caplen, bytes_written, err);
}
static guint32
pcapng_count_string_option(const char *option_value)
{
if ((option_value != NULL) && (strlen(option_value) > 0) && (strlen(option_value) < G_MAXUINT16)) {
return (guint32)(sizeof(struct option) +
(guint16)ADD_PADDING(strlen(option_value)));
}
return 0;
}
static gboolean
pcapng_write_string_option(FILE* pfile,
guint16 option_type, const char *option_value,
guint64 *bytes_written, int *err)
{
size_t option_value_length;
struct option option;
const guint32 padding = 0;
if (option_value == NULL)
return TRUE;
option_value_length = strlen(option_value);
if ((option_value_length > 0) && (option_value_length < G_MAXUINT16)) {
option.type = option_type;
option.value_length = (guint16)option_value_length;
if (!write_to_file(pfile, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_to_file(pfile, (const guint8*)option_value, (int) option_value_length, bytes_written, err))
return FALSE;
if (option_value_length % 4) {
if (!write_to_file(pfile, (const guint8*)&padding, 4 - option_value_length % 4, bytes_written, err))
return FALSE;
}
}
return TRUE;
}
gboolean
pcapng_write_session_header_block(FILE* pfile,
const char *comment,
const char *hw,
const char *os,
const char *appname,
guint64 section_length,
guint64 *bytes_written,
int *err)
{
struct shb shb;
struct option option;
guint32 block_total_length;
guint32 options_length;
block_total_length = sizeof(struct shb) +
sizeof(guint32);
options_length = 0;
options_length += pcapng_count_string_option(comment);
options_length += pcapng_count_string_option(hw);
options_length += pcapng_count_string_option(os);
options_length += pcapng_count_string_option(appname);
if (options_length != 0) {
options_length += (guint32)sizeof(struct option);
}
block_total_length += options_length;
shb.block_type = SECTION_HEADER_BLOCK_TYPE;
shb.block_total_length = block_total_length;
shb.byte_order_magic = PCAPNG_MAGIC;
shb.major_version = PCAPNG_MAJOR_VERSION;
shb.minor_version = PCAPNG_MINOR_VERSION;
shb.section_length = section_length;
if (!write_to_file(pfile, (const guint8*)&shb, sizeof(struct shb), bytes_written, err))
return FALSE;
if (!pcapng_write_string_option(pfile, OPT_COMMENT, comment,
bytes_written, err))
return FALSE;
if (!pcapng_write_string_option(pfile, SHB_HARDWARE, hw,
bytes_written, err))
return FALSE;
if (!pcapng_write_string_option(pfile, SHB_OS, os,
bytes_written, err))
return FALSE;
if (!pcapng_write_string_option(pfile, SHB_USERAPPL, appname,
bytes_written, err))
return FALSE;
if (options_length != 0) {
option.type = OPT_ENDOFOPT;
option.value_length = 0;
if (!write_to_file(pfile, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
}
return write_to_file(pfile, (const guint8*)&block_total_length, sizeof(guint32), bytes_written, err);
}
gboolean
pcapng_write_interface_description_block(FILE* pfile,
const char *comment,
const char *name,
const char *descr,
const char *filter,
const char *os,
int link_type,
int snap_len,
guint64 *bytes_written,
guint64 if_speed,
guint8 tsresol,
int *err)
{
struct idb idb;
struct option option;
guint32 block_total_length;
guint32 options_length;
const guint32 padding = 0;
block_total_length = (guint32)(sizeof(struct idb) + sizeof(guint32));
options_length = 0;
options_length += pcapng_count_string_option(comment);
options_length += pcapng_count_string_option(name);
options_length += pcapng_count_string_option(descr);
if (if_speed != 0) {
options_length += (guint32)(sizeof(struct option) +
sizeof(guint64));
}
if (tsresol != 0) {
options_length += (guint32)(sizeof(struct option) +
sizeof(struct option));
}
if ((filter != NULL) && (strlen(filter) > 0) && (strlen(filter) < G_MAXUINT16)) {
options_length += (guint32)(sizeof(struct option) +
(guint16)(ADD_PADDING(strlen(filter)+ 1)));
}
options_length += pcapng_count_string_option(os);
if (options_length != 0) {
options_length += (guint32)sizeof(struct option);
}
block_total_length += options_length;
idb.block_type = INTERFACE_DESCRIPTION_BLOCK_TYPE;
idb.block_total_length = block_total_length;
idb.link_type = link_type;
idb.reserved = 0;
idb.snap_len = snap_len;
if (!write_to_file(pfile, (const guint8*)&idb, sizeof(struct idb), bytes_written, err))
return FALSE;
if (!pcapng_write_string_option(pfile, OPT_COMMENT, comment,
bytes_written, err))
return FALSE;
if (!pcapng_write_string_option(pfile, IDB_NAME, name,
bytes_written, err))
return FALSE;
if (!pcapng_write_string_option(pfile, IDB_DESCRIPTION, descr,
bytes_written, err))
return FALSE;
if (if_speed != 0) {
option.type = IDB_IF_SPEED;
option.value_length = sizeof(guint64);
if (!write_to_file(pfile, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_to_file(pfile, (const guint8*)&if_speed, sizeof(guint64), bytes_written, err))
return FALSE;
}
if (tsresol != 0) {
option.type = IDB_TSRESOL;
option.value_length = sizeof(guint8);
if (!write_to_file(pfile, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_to_file(pfile, (const guint8*)&tsresol, sizeof(guint8), bytes_written, err))
return FALSE;
if (!write_to_file(pfile, (const guint8*)&padding, 3, bytes_written, err))
return FALSE;
}
if ((filter != NULL) && (strlen(filter) > 0) && (strlen(filter) < G_MAXUINT16 - 1)) {
option.type = IDB_FILTER;
option.value_length = (guint16)(strlen(filter) + 1 );
if (!write_to_file(pfile, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_to_file(pfile, (const guint8*)&padding, 1, bytes_written, err))
return FALSE;
if (!write_to_file(pfile, (const guint8*)filter, (int) strlen(filter), bytes_written, err))
return FALSE;
if ((strlen(filter) + 1) % 4) {
if (!write_to_file(pfile, (const guint8*)&padding, 4 - (strlen(filter) + 1) % 4, bytes_written, err))
return FALSE;
}
}
if (!pcapng_write_string_option(pfile, IDB_OS, os,
bytes_written, err))
return FALSE;
if (options_length != 0) {
option.type = OPT_ENDOFOPT;
option.value_length = 0;
if (!write_to_file(pfile, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
}
return write_to_file(pfile, (const guint8*)&block_total_length, sizeof(guint32), bytes_written, err);
}
gboolean
pcapng_write_enhanced_packet_block(FILE* pfile,
const char *comment,
time_t sec, guint32 usec,
guint32 caplen, guint32 len,
guint32 interface_id,
guint ts_mul,
const guint8 *pd,
guint32 flags,
guint64 *bytes_written,
int *err)
{
struct epb epb;
struct option option;
guint32 block_total_length;
guint64 timestamp;
guint32 options_length;
const guint32 padding = 0;
guint8 buff[8];
guint8 i;
guint8 pad_len = 0;
block_total_length = (guint32)(sizeof(struct epb) +
ADD_PADDING(caplen) +
sizeof(guint32));
options_length = 0;
options_length += pcapng_count_string_option(comment);
if (flags != 0) {
options_length += (guint32)(sizeof(struct option) +
sizeof(guint32));
}
if (options_length != 0) {
options_length += (guint32)sizeof(struct option);
}
block_total_length += options_length;
timestamp = (guint64)sec * ts_mul + (guint64)usec;
epb.block_type = ENHANCED_PACKET_BLOCK_TYPE;
epb.block_total_length = block_total_length;
epb.interface_id = interface_id;
epb.timestamp_high = (guint32)((timestamp>>32) & 0xffffffff);
epb.timestamp_low = (guint32)(timestamp & 0xffffffff);
epb.captured_len = caplen;
epb.packet_len = len;
if (!write_to_file(pfile, (const guint8*)&epb, sizeof(struct epb), bytes_written, err))
return FALSE;
if (!write_to_file(pfile, pd, caplen, bytes_written, err))
return FALSE;
if(caplen % 4) {
pad_len = 4 - (caplen % 4);
}
if(!comment && flags == 0 && options_length==0){
for (i = 0; i < pad_len; i++) {
buff[i] = 0;
}
buff[i] = (block_total_length & 0x000000ff);
i++;
buff[i] = (block_total_length & 0x0000ff00) >> 8;
i++;
buff[i] = (block_total_length & 0x00ff0000) >> 16;
i++;
buff[i] = (block_total_length & 0xff000000) >> 24;
i++;
return write_to_file(pfile, (const guint8*)&buff, i, bytes_written, err);
}
if (pad_len) {
if (!write_to_file(pfile, (const guint8*)&padding, pad_len, bytes_written, err))
return FALSE;
}
if (!pcapng_write_string_option(pfile, OPT_COMMENT, comment,
bytes_written, err))
return FALSE;
if (flags != 0) {
option.type = EPB_FLAGS;
option.value_length = sizeof(guint32);
if (!write_to_file(pfile, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_to_file(pfile, (const guint8*)&flags, sizeof(guint32), bytes_written, err))
return FALSE;
}
if (options_length != 0) {
option.type = OPT_ENDOFOPT;
option.value_length = 0;
if (!write_to_file(pfile, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
}
return write_to_file(pfile, (const guint8*)&block_total_length, sizeof(guint32), bytes_written, err);
}
gboolean
pcapng_write_interface_statistics_block(FILE* pfile,
guint32 interface_id,
guint64 *bytes_written,
const char *comment,
guint64 isb_starttime,
guint64 isb_endtime,
guint64 isb_ifrecv,
guint64 isb_ifdrop,
int *err)
{
struct isb isb;
#ifdef _WIN32
FILETIME now;
#else
struct timeval now;
#endif
struct option option;
guint32 block_total_length;
guint32 options_length;
guint64 timestamp;
#ifdef _WIN32
GetSystemTimeAsFileTime(&now);
timestamp = (((guint64)(guint32)now.dwHighDateTime) << 32) +
(guint32)now.dwLowDateTime;
timestamp /= 10;
timestamp -= G_GUINT64_CONSTANT(11644473600000000);
#else
gettimeofday(&now, NULL);
timestamp = (guint64)(now.tv_sec) * 1000000 +
(guint64)(now.tv_usec);
#endif
block_total_length = (guint32)(sizeof(struct isb) + sizeof(guint32));
options_length = 0;
if (isb_ifrecv != G_MAXUINT64) {
options_length += (guint32)(sizeof(struct option) +
sizeof(guint64));
}
if (isb_ifdrop != G_MAXUINT64) {
options_length += (guint32)(sizeof(struct option) +
sizeof(guint64));
}
options_length += pcapng_count_string_option(comment);
if (isb_starttime !=0) {
options_length += (guint32)(sizeof(struct option) +
sizeof(guint64));
}
if (isb_endtime !=0) {
options_length += (guint32)(sizeof(struct option) +
sizeof(guint64));
}
if (options_length != 0) {
options_length += (guint32)sizeof(struct option);
}
block_total_length += options_length;
isb.block_type = INTERFACE_STATISTICS_BLOCK_TYPE;
isb.block_total_length = block_total_length;
isb.interface_id = interface_id;
isb.timestamp_high = (guint32)((timestamp>>32) & 0xffffffff);
isb.timestamp_low = (guint32)(timestamp & 0xffffffff);
if (!write_to_file(pfile, (const guint8*)&isb, sizeof(struct isb), bytes_written, err))
return FALSE;
if (!pcapng_write_string_option(pfile, OPT_COMMENT, comment,
bytes_written, err))
return FALSE;
if (isb_starttime !=0) {
guint32 high, low;
option.type = ISB_STARTTIME;
option.value_length = sizeof(guint64);
high = (guint32)((isb_starttime>>32) & 0xffffffff);
low = (guint32)(isb_starttime & 0xffffffff);
if (!write_to_file(pfile, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_to_file(pfile, (const guint8*)&high, sizeof(guint32), bytes_written, err))
return FALSE;
if (!write_to_file(pfile, (const guint8*)&low, sizeof(guint32), bytes_written, err))
return FALSE;
}
if (isb_endtime !=0) {
guint32 high, low;
option.type = ISB_ENDTIME;
option.value_length = sizeof(guint64);
high = (guint32)((isb_endtime>>32) & 0xffffffff);
low = (guint32)(isb_endtime & 0xffffffff);
if (!write_to_file(pfile, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_to_file(pfile, (const guint8*)&high, sizeof(guint32), bytes_written, err))
return FALSE;
if (!write_to_file(pfile, (const guint8*)&low, sizeof(guint32), bytes_written, err))
return FALSE;
}
if (isb_ifrecv != G_MAXUINT64) {
option.type = ISB_IFRECV;
option.value_length = sizeof(guint64);
if (!write_to_file(pfile, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_to_file(pfile, (const guint8*)&isb_ifrecv, sizeof(guint64), bytes_written, err))
return FALSE;
}
if (isb_ifdrop != G_MAXUINT64) {
option.type = ISB_IFDROP;
option.value_length = sizeof(guint64);
if (!write_to_file(pfile, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_to_file(pfile, (const guint8*)&isb_ifdrop, sizeof(guint64), bytes_written, err))
return FALSE;
}
if (options_length != 0) {
option.type = OPT_ENDOFOPT;
option.value_length = 0;
if (!write_to_file(pfile, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
}
return write_to_file(pfile, (const guint8*)&block_total_length, sizeof(guint32), bytes_written, err);
}
