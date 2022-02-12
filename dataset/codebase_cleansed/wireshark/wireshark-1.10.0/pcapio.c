gboolean libpcap_write_to_file(void* write_data_info,
const guint8* data,
long data_length,
guint64 *bytes_written,
int *err)
{
size_t nwritten;
FILE* pFile = (FILE*)write_data_info;
nwritten = fwrite(data, data_length, 1, pFile);
if (nwritten != 1) {
if (ferror(pFile)) {
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
libpcap_write_file_header(libpcap_write_t write_func, void* write_data_info, int linktype, int snaplen, gboolean ts_nsecs, guint64 *bytes_written, int *err)
{
struct pcap_hdr file_hdr;
file_hdr.magic = ts_nsecs ? PCAP_NSEC_MAGIC : PCAP_MAGIC;
file_hdr.version_major = 2;
file_hdr.version_minor = 4;
file_hdr.thiszone = 0;
file_hdr.sigfigs = 0;
file_hdr.snaplen = snaplen;
file_hdr.network = linktype;
return write_func(write_data_info, (const guint8*)&file_hdr, sizeof(file_hdr), bytes_written, err);
}
gboolean
libpcap_write_packet(libpcap_write_t write_func, void* write_data_info,
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
if (!write_func(write_data_info, (const guint8*)&rec_hdr, sizeof(rec_hdr), bytes_written, err))
return FALSE;
return write_func(write_data_info, pd, caplen, bytes_written, err);
}
gboolean
libpcap_write_session_header_block(libpcap_write_t write_func, void* write_data_info,
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
const guint32 padding = 0;
gboolean have_options = FALSE;
block_total_length = sizeof(struct shb) +
sizeof(guint32);
if ((comment != NULL) && (strlen(comment) > 0) && (strlen(comment) < G_MAXUINT16)) {
block_total_length += (guint32)(sizeof(struct option) +
(guint16)ADD_PADDING(strlen(comment)));
have_options = TRUE;
}
if ((hw != NULL) && (strlen(hw) > 0) && (strlen(hw) < G_MAXUINT16)) {
block_total_length += (guint32)(sizeof(struct option) +
(guint16)ADD_PADDING(strlen(hw)));
have_options = TRUE;
}
if ((os != NULL) && (strlen(os) > 0) && (strlen(os) < G_MAXUINT16)) {
block_total_length += (guint32)(sizeof(struct option) +
(guint16)ADD_PADDING(strlen(os)));
have_options = TRUE;
}
if ((appname != NULL) && (strlen(appname) > 0) && (strlen(appname) < G_MAXUINT16)) {
block_total_length += (guint32)(sizeof(struct option) +
(guint16)ADD_PADDING(strlen(appname)));
have_options = TRUE;
}
if (have_options) {
block_total_length += (guint32)sizeof(struct option);
}
shb.block_type = SECTION_HEADER_BLOCK_TYPE;
shb.block_total_length = block_total_length;
shb.byte_order_magic = PCAPNG_MAGIC;
shb.major_version = PCAPNG_MAJOR_VERSION;
shb.minor_version = PCAPNG_MINOR_VERSION;
shb.section_length = section_length;
if (!write_func(write_data_info, (const guint8*)&shb, sizeof(struct shb), bytes_written, err))
return FALSE;
if ((comment != NULL) && (strlen(comment) > 0) && (strlen(comment) < G_MAXUINT16)) {
option.type = OPT_COMMENT;
option.value_length = (guint16)strlen(comment);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)comment, (int) strlen(comment), bytes_written, err))
return FALSE;
if (strlen(comment) % 4) {
if (!write_func(write_data_info, (const guint8*)&padding, 4 - strlen(comment) % 4, bytes_written, err))
return FALSE;
}
}
if ((hw != NULL) && (strlen(hw) > 0) && (strlen(hw) < G_MAXUINT16)) {
option.type = SHB_HARDWARE;
option.value_length = (guint16)strlen(hw);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)hw, (int) strlen(hw), bytes_written, err))
return FALSE;
if ((strlen(hw) + 1) % 4) {
if (!write_func(write_data_info, (const guint8*)&padding, 4 - strlen(hw) % 4, bytes_written, err))
return FALSE;
}
}
if ((os != NULL) && (strlen(os) > 0) && (strlen(os) < G_MAXUINT16)) {
option.type = SHB_OS;
option.value_length = (guint16)strlen(os);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)os, (int) strlen(os), bytes_written, err))
return FALSE;
if (strlen(os) % 4) {
if (!write_func(write_data_info, (const guint8*)&padding, 4 - strlen(os) % 4, bytes_written, err))
return FALSE;
}
}
if ((appname != NULL) && (strlen(appname) > 0) && (strlen(appname) < G_MAXUINT16)) {
option.type = SHB_USERAPPL;
option.value_length = (guint16)strlen(appname);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)appname, (int) strlen(appname), bytes_written, err))
return FALSE;
if (strlen(appname) % 4) {
if (!write_func(write_data_info, (const guint8*)&padding, 4 - strlen(appname) % 4, bytes_written, err))
return FALSE;
}
}
if (have_options) {
option.type = OPT_ENDOFOPT;
option.value_length = 0;
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
}
return write_func(write_data_info, (const guint8*)&block_total_length, sizeof(guint32), bytes_written, err);
}
gboolean
libpcap_write_interface_description_block(libpcap_write_t write_func, void* write_data_info,
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
const guint32 padding = 0;
gboolean have_options = FALSE;
block_total_length = (guint32)(sizeof(struct idb) + sizeof(guint32));
if ((comment != NULL) && (strlen(comment) > 0) && (strlen(comment) < G_MAXUINT16)) {
block_total_length += (guint32)(sizeof(struct option) +
(guint16)ADD_PADDING(strlen(comment)));
have_options = TRUE;
}
if ((name != NULL) && (strlen(name) > 0) && (strlen(name) < G_MAXUINT16)) {
block_total_length += (guint32)(sizeof(struct option) +
(guint16)ADD_PADDING(strlen(name)));
have_options = TRUE;
}
if ((descr != NULL) && (strlen(descr) > 0) && (strlen(descr) < G_MAXUINT16)) {
block_total_length += (guint32)(sizeof(struct option) +
(guint16)ADD_PADDING(strlen(descr)));
have_options = TRUE;
}
if (if_speed != 0) {
block_total_length += (guint32)(sizeof(struct option) +
sizeof(guint64));
have_options = TRUE;
}
if (tsresol != 0) {
block_total_length += (guint32)(sizeof(struct option) +
sizeof(struct option));
have_options = TRUE;
}
if ((filter != NULL) && (strlen(filter) > 0) && (strlen(filter) < G_MAXUINT16)) {
block_total_length += (guint32)(sizeof(struct option) +
(guint16)(ADD_PADDING(strlen(filter)+ 1)));
have_options = TRUE;
}
if ((os != NULL) && (strlen(os) > 0) && (strlen(os) < G_MAXUINT16)) {
block_total_length += (guint32)(sizeof(struct option) +
(guint16)ADD_PADDING(strlen(os)));
have_options = TRUE;
}
if (have_options) {
block_total_length += (guint32)sizeof(struct option);
}
idb.block_type = INTERFACE_DESCRIPTION_BLOCK_TYPE;
idb.block_total_length = block_total_length;
idb.link_type = link_type;
idb.reserved = 0;
idb.snap_len = snap_len;
if (!write_func(write_data_info, (const guint8*)&idb, sizeof(struct idb), bytes_written, err))
return FALSE;
if ((comment != NULL) && (strlen(comment) > 0) && (strlen(comment) < G_MAXUINT16)) {
option.type = OPT_COMMENT;
option.value_length = (guint16)strlen(comment);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)comment, (int) strlen(comment), bytes_written, err))
return FALSE;
if (strlen(comment) % 4) {
if (!write_func(write_data_info, (const guint8*)&padding, 4 - strlen(comment) % 4, bytes_written, err))
return FALSE;
}
}
if ((name != NULL) && (strlen(name) > 0) && (strlen(name) < G_MAXUINT16)) {
option.type = IDB_NAME;
option.value_length = (guint16)strlen(name);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)name, (int) strlen(name), bytes_written, err))
return FALSE;
if (strlen(name) % 4) {
if (!write_func(write_data_info, (const guint8*)&padding, 4 - strlen(name) % 4, bytes_written, err))
return FALSE;
}
}
if ((descr != NULL) && (strlen(descr) > 0) && (strlen(descr) < G_MAXUINT16)) {
option.type = IDB_DESCRIPTION;
option.value_length = (guint16)strlen(descr);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)descr, (int) strlen(descr), bytes_written, err))
return FALSE;
if (strlen(descr) % 4) {
if (!write_func(write_data_info, (const guint8*)&padding, 4 - strlen(descr) % 4, bytes_written, err))
return FALSE;
}
}
if (if_speed != 0) {
option.type = IDB_IF_SPEED;
option.value_length = sizeof(guint64);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)&if_speed, sizeof(guint64), bytes_written, err))
return FALSE;
}
if (tsresol != 0) {
option.type = IDB_TSRESOL;
option.value_length = sizeof(guint8);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)&tsresol, sizeof(guint8), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)&padding, 3, bytes_written, err))
return FALSE;
}
if ((filter != NULL) && (strlen(filter) > 0) && (strlen(filter) < G_MAXUINT16)) {
option.type = IDB_FILTER;
option.value_length = (guint16)(strlen(filter) + 1 );
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)&padding, 1, bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)filter, (int) strlen(filter), bytes_written, err))
return FALSE;
if ((strlen(filter) + 1) % 4) {
if (!write_func(write_data_info, (const guint8*)&padding, 4 - (strlen(filter) + 1) % 4, bytes_written, err))
return FALSE;
}
}
if ((os != NULL) && (strlen(os) > 0) && (strlen(os) < G_MAXUINT16)) {
option.type = IDB_OS;
option.value_length = (guint16)strlen(os);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)os, (int) strlen(os), bytes_written, err))
return FALSE;
if (strlen(os) % 4) {
if (!write_func(write_data_info, (const guint8*)&padding, 4 - strlen(os) % 4, bytes_written, err))
return FALSE;
}
}
if (have_options) {
option.type = OPT_ENDOFOPT;
option.value_length = 0;
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
}
return write_func(write_data_info, (const guint8*)&block_total_length, sizeof(guint32), bytes_written, err);
}
gboolean
libpcap_write_enhanced_packet_block(libpcap_write_t write_func, void* write_data_info,
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
gboolean have_options = FALSE;
const guint32 padding = 0;
block_total_length = (guint32)(sizeof(struct epb) +
ADD_PADDING(caplen) +
sizeof(guint32));
if ((comment != NULL) && (strlen(comment) > 0) && (strlen(comment) < G_MAXUINT16)) {
block_total_length += (guint32)(sizeof(struct option) +
(guint16)ADD_PADDING(strlen(comment)));
have_options = TRUE;
}
if (flags != 0) {
block_total_length += (guint32)(sizeof(struct option) +
sizeof(guint32));
have_options = TRUE;
}
if (have_options) {
block_total_length += (guint32)sizeof(struct option);
}
timestamp = (guint64)sec * ts_mul + (guint64)usec;
epb.block_type = ENHANCED_PACKET_BLOCK_TYPE;
epb.block_total_length = block_total_length;
epb.interface_id = interface_id;
epb.timestamp_high = (guint32)((timestamp>>32) & 0xffffffff);
epb.timestamp_low = (guint32)(timestamp & 0xffffffff);
epb.captured_len = caplen;
epb.packet_len = len;
if (!write_func(write_data_info, (const guint8*)&epb, sizeof(struct epb), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, pd, caplen, bytes_written, err))
return FALSE;
if (caplen % 4) {
if (!write_func(write_data_info, (const guint8*)&padding, 4 - caplen % 4, bytes_written, err))
return FALSE;
}
if ((comment != NULL) && (strlen(comment) > 0) && (strlen(comment) < G_MAXUINT16)) {
option.type = OPT_COMMENT;
option.value_length = (guint16)strlen(comment);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)comment, (int) strlen(comment), bytes_written, err))
return FALSE;
if (strlen(comment) % 4) {
if (!write_func(write_data_info, (const guint8*)&padding, 4 - strlen(comment) % 4, bytes_written, err))
return FALSE;
}
}
if (flags != 0) {
option.type = EPB_FLAGS;
option.value_length = sizeof(guint32);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)&flags, sizeof(guint32), bytes_written, err))
return FALSE;
option.type = OPT_ENDOFOPT;
option.value_length = 0;
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
}
return write_func(write_data_info, (const guint8*)&block_total_length, sizeof(guint32), bytes_written, err);
}
gboolean
libpcap_write_interface_statistics_block(libpcap_write_t write_func, void* write_data_info,
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
guint64 timestamp;
gboolean have_options = FALSE;
const guint32 padding = 0;
#ifdef _WIN32
GetSystemTimeAsFileTime(&now);
timestamp = (((guint64)(guint32)now.dwHighDateTime) << 32) +
(guint32)now.dwLowDateTime;
timestamp /= 10;
timestamp -= G_GINT64_CONSTANT(11644473600000000U);
#else
gettimeofday(&now, NULL);
timestamp = (guint64)(now.tv_sec) * 1000000 +
(guint64)(now.tv_usec);
#endif
block_total_length = (guint32)(sizeof(struct isb) + sizeof(guint32));
if (isb_ifrecv != G_MAXUINT64) {
block_total_length += (guint32)(sizeof(struct option) +
sizeof(guint64));
have_options = TRUE;
}
if (isb_ifdrop != G_MAXUINT64) {
block_total_length += (guint32)(sizeof(struct option) +
sizeof(guint64));
have_options = TRUE;
}
if ((comment != NULL) && (strlen(comment) > 0) && (strlen(comment) < G_MAXUINT16)) {
block_total_length += (guint32)(sizeof(struct option) +
(guint16)ADD_PADDING(strlen(comment)));
have_options = TRUE;
}
if (isb_starttime !=0) {
block_total_length += (guint32)(sizeof(struct option) +
sizeof(guint64));
have_options = TRUE;
}
if (isb_endtime !=0) {
block_total_length += (guint32)(sizeof(struct option) +
sizeof(guint64));
have_options = TRUE;
}
if (have_options) {
block_total_length += (guint32)sizeof(struct option);
}
isb.block_type = INTERFACE_STATISTICS_BLOCK_TYPE;
isb.block_total_length = block_total_length;
isb.interface_id = interface_id;
isb.timestamp_high = (guint32)((timestamp>>32) & 0xffffffff);
isb.timestamp_low = (guint32)(timestamp & 0xffffffff);
if (!write_func(write_data_info, (const guint8*)&isb, sizeof(struct isb), bytes_written, err))
return FALSE;
if ((comment != NULL) && (strlen(comment) > 0) && (strlen(comment) < G_MAXUINT16)) {
option.type = OPT_COMMENT;
option.value_length = (guint16)strlen(comment);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)comment, (int) strlen(comment), bytes_written, err))
return FALSE;
if (strlen(comment) % 4) {
if (!write_func(write_data_info, (const guint8*)&padding, 4 - strlen(comment) % 4, bytes_written, err))
return FALSE;
}
}
if (isb_starttime !=0) {
guint32 high, low;
option.type = ISB_STARTTIME;
option.value_length = sizeof(guint64);
high = (guint32)((isb_starttime>>32) & 0xffffffff);
low = (guint32)(isb_starttime & 0xffffffff);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)&high, sizeof(guint32), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)&low, sizeof(guint32), bytes_written, err))
return FALSE;
}
if (isb_endtime !=0) {
guint32 high, low;
option.type = ISB_ENDTIME;
option.value_length = sizeof(guint64);
high = (guint32)((isb_endtime>>32) & 0xffffffff);
low = (guint32)(isb_endtime & 0xffffffff);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)&high, sizeof(guint32), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)&low, sizeof(guint32), bytes_written, err))
return FALSE;
}
if (isb_ifrecv != G_MAXUINT64) {
option.type = ISB_IFRECV;
option.value_length = sizeof(guint64);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)&isb_ifrecv, sizeof(guint64), bytes_written, err))
return FALSE;
}
if (isb_ifdrop != G_MAXUINT64) {
option.type = ISB_IFDROP;
option.value_length = sizeof(guint64);
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
if (!write_func(write_data_info, (const guint8*)&isb_ifdrop, sizeof(guint64), bytes_written, err))
return FALSE;
}
if (have_options) {
option.type = OPT_ENDOFOPT;
option.value_length = 0;
if (!write_func(write_data_info, (const guint8*)&option, sizeof(struct option), bytes_written, err))
return FALSE;
}
return write_func(write_data_info, (const guint8*)&block_total_length, sizeof(guint32), bytes_written, err);
}
