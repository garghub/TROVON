FILE *
libpcap_fdopen(int fd, int *err)
{
FILE *fp;
fp = fdopen(fd, "wb");
if (fp == NULL) {
*err = errno;
}
return fp;
}
gboolean
libpcap_write_file_header(FILE *fp, int linktype, int snaplen, gboolean ts_nsecs, long *bytes_written, int *err)
{
struct pcap_hdr file_hdr;
size_t nwritten;
file_hdr.magic = ts_nsecs ? PCAP_NSEC_MAGIC : PCAP_MAGIC;
file_hdr.version_major = 2;
file_hdr.version_minor = 4;
file_hdr.thiszone = 0;
file_hdr.sigfigs = 0;
file_hdr.snaplen = snaplen;
file_hdr.network = linktype;
nwritten = fwrite(&file_hdr, 1, sizeof(file_hdr), fp);
if (nwritten != sizeof(file_hdr)) {
if (nwritten == 0 && ferror(fp))
*err = errno;
else
*err = 0;
return FALSE;
}
*bytes_written += sizeof(file_hdr);
return TRUE;
}
gboolean
libpcap_write_packet(FILE *fp, const struct pcap_pkthdr *phdr, const u_char *pd,
long *bytes_written, int *err)
{
struct pcaprec_hdr rec_hdr;
size_t nwritten;
rec_hdr.ts_sec = phdr->ts.tv_sec;
rec_hdr.ts_usec = phdr->ts.tv_usec;
rec_hdr.incl_len = phdr->caplen;
rec_hdr.orig_len = phdr->len;
nwritten = fwrite(&rec_hdr, 1, sizeof rec_hdr, fp);
if (nwritten != sizeof rec_hdr) {
if (nwritten == 0 && ferror(fp))
*err = errno;
else
*err = 0;
return FALSE;
}
*bytes_written += sizeof rec_hdr;
nwritten = fwrite(pd, 1, phdr->caplen, fp);
if (nwritten != phdr->caplen) {
if (nwritten == 0 && ferror(fp))
*err = errno;
else
*err = 0;
return FALSE;
}
*bytes_written += phdr->caplen;
return TRUE;
}
gboolean
libpcap_write_session_header_block(FILE *fp,
const char *comment,
const char *hw,
const char *os,
const char *appname,
guint64 section_length,
long *bytes_written,
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
block_total_length += sizeof(struct option) +
(guint16)ADD_PADDING(strlen(comment));
have_options = TRUE;
}
if ((hw != NULL) && (strlen(hw) > 0) && (strlen(hw) < G_MAXUINT16)) {
block_total_length += sizeof(struct option) +
(guint16)ADD_PADDING(strlen(hw));
have_options = TRUE;
}
if ((os != NULL) && (strlen(os) > 0) && (strlen(os) < G_MAXUINT16)) {
block_total_length += sizeof(struct option) +
(guint16)ADD_PADDING(strlen(os));
have_options = TRUE;
}
if ((appname != NULL) && (strlen(appname) > 0) && (strlen(appname) < G_MAXUINT16)) {
block_total_length += sizeof(struct option) +
(guint16)ADD_PADDING(strlen(appname));
have_options = TRUE;
}
if (have_options) {
block_total_length += sizeof(struct option);
}
shb.block_type = SECTION_HEADER_BLOCK_TYPE;
shb.block_total_length = block_total_length;
shb.byte_order_magic = PCAPNG_MAGIC;
shb.major_version = PCAPNG_MAJOR_VERSION;
shb.minor_version = PCAPNG_MINOR_VERSION;
shb.section_length = section_length;
WRITE_DATA(fp, &shb, sizeof(struct shb), *bytes_written, err);
if ((comment != NULL) && (strlen(comment) > 0) && (strlen(comment) < G_MAXUINT16)) {
option.type = OPT_COMMENT;
option.value_length = (guint16)strlen(comment);
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, comment, strlen(comment), *bytes_written, err);
if (strlen(comment) % 4) {
WRITE_DATA(fp, &padding, 4 - strlen(comment) % 4, *bytes_written, err);
}
}
if ((hw != NULL) && (strlen(hw) > 0) && (strlen(hw) < G_MAXUINT16)) {
option.type = SHB_HARDWARE;
option.value_length = (guint16)strlen(hw);
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, hw, strlen(hw), *bytes_written, err);
if ((strlen(hw) + 1) % 4) {
WRITE_DATA(fp, &padding, 4 - strlen(hw) % 4, *bytes_written, err);
}
}
if ((os != NULL) && (strlen(os) > 0) && (strlen(os) < G_MAXUINT16)) {
option.type = SHB_OS;
option.value_length = (guint16)strlen(os);
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, os, strlen(os), *bytes_written, err);
if (strlen(os) % 4) {
WRITE_DATA(fp, &padding, 4 - strlen(os) % 4, *bytes_written, err);
}
}
if ((appname != NULL) && (strlen(appname) > 0) && (strlen(appname) < G_MAXUINT16)) {
option.type = SHB_USERAPPL;
option.value_length = (guint16)strlen(appname);
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, appname, strlen(appname), *bytes_written, err);
if (strlen(appname) % 4) {
WRITE_DATA(fp, &padding, 4 - strlen(appname) % 4, *bytes_written, err);
}
}
if (have_options) {
option.type = OPT_ENDOFOPT;
option.value_length = 0;
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
}
WRITE_DATA(fp, &block_total_length, sizeof(guint32), *bytes_written, err);
return TRUE;
}
gboolean
libpcap_write_interface_description_block(FILE *fp,
const char *comment,
const char *name,
const char *descr,
const char *filter,
const char *os,
int link_type,
int snap_len,
long *bytes_written,
guint64 if_speed,
guint8 tsresol,
int *err)
{
struct idb idb;
struct option option;
guint32 block_total_length;
const guint32 padding = 0;
gboolean have_options = FALSE;
block_total_length = sizeof(struct idb) + sizeof(guint32);
if ((comment != NULL) && (strlen(comment) > 0) && (strlen(comment) < G_MAXUINT16)) {
block_total_length += sizeof(struct option) +
(guint16)ADD_PADDING(strlen(comment));
have_options = TRUE;
}
if ((name != NULL) && (strlen(name) > 0) && (strlen(name) < G_MAXUINT16)) {
block_total_length += sizeof(struct option) +
(guint16)ADD_PADDING(strlen(name));
have_options = TRUE;
}
if ((descr != NULL) && (strlen(descr) > 0) && (strlen(descr) < G_MAXUINT16)) {
block_total_length += sizeof(struct option) +
(guint16)ADD_PADDING(strlen(descr));
have_options = TRUE;
}
if (if_speed != 0) {
block_total_length += sizeof(struct option) + sizeof(guint64);
have_options = TRUE;
}
if (tsresol != 0) {
block_total_length += sizeof(struct option) + sizeof(struct option);
have_options = TRUE;
}
if ((filter != NULL) && (strlen(filter) > 0) && (strlen(filter) < G_MAXUINT16)) {
block_total_length += sizeof(struct option) +
(guint16)(ADD_PADDING(strlen(filter)+ 1));
have_options = TRUE;
}
if ((os != NULL) && (strlen(os) > 0) && (strlen(os) < G_MAXUINT16)) {
block_total_length += sizeof(struct option) +
(guint16)ADD_PADDING(strlen(os));
have_options = TRUE;
}
if (have_options) {
block_total_length += sizeof(struct option);
}
idb.block_type = INTERFACE_DESCRIPTION_BLOCK_TYPE;
idb.block_total_length = block_total_length;
idb.link_type = link_type;
idb.reserved = 0;
idb.snap_len = snap_len;
WRITE_DATA(fp, &idb, sizeof(struct idb), *bytes_written, err);
if ((comment != NULL) && (strlen(comment) > 0) && (strlen(comment) < G_MAXUINT16)) {
option.type = OPT_COMMENT;
option.value_length = (guint16)strlen(comment);
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, comment, strlen(comment), *bytes_written, err);
if (strlen(comment) % 4) {
WRITE_DATA(fp, &padding, 4 - strlen(comment) % 4 , *bytes_written, err);
}
}
if ((name != NULL) && (strlen(name) > 0) && (strlen(name) < G_MAXUINT16)) {
option.type = IDB_NAME;
option.value_length = (guint16)strlen(name);
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, name, strlen(name), *bytes_written, err);
if (strlen(name) % 4) {
WRITE_DATA(fp, &padding, 4 - strlen(name) % 4 , *bytes_written, err);
}
}
if ((descr != NULL) && (strlen(descr) > 0) && (strlen(descr) < G_MAXUINT16)) {
option.type = IDB_DESCRIPTION;
option.value_length = (guint16)strlen(descr);
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, descr, strlen(descr), *bytes_written, err);
if (strlen(descr) % 4) {
WRITE_DATA(fp, &padding, 4 - strlen(descr) % 4 , *bytes_written, err);
}
}
if (if_speed != 0) {
option.type = IDB_IF_SPEED;
option.value_length = sizeof(guint64);
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, &if_speed, sizeof(guint64), *bytes_written, err);
}
if (tsresol != 0) {
option.type = IDB_TSRESOL;
option.value_length = sizeof(guint8);
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, &tsresol, sizeof(guint8), *bytes_written, err);
WRITE_DATA(fp, &padding, 3 , *bytes_written, err);
}
if ((filter != NULL) && (strlen(filter) > 0) && (strlen(filter) < G_MAXUINT16)) {
option.type = IDB_FILTER;
option.value_length = (guint16)(strlen(filter) + 1 );
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, &padding, 1, *bytes_written, err);
WRITE_DATA(fp, filter, strlen(filter), *bytes_written, err);
if ((strlen(filter) + 1) % 4) {
WRITE_DATA(fp, &padding, 4 - (strlen(filter) + 1) % 4 , *bytes_written, err);
}
}
if ((os != NULL) && (strlen(os) > 0) && (strlen(os) < G_MAXUINT16)) {
option.type = IDB_OS;
option.value_length = (guint16)strlen(os);
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, os, strlen(os), *bytes_written, err);
if (strlen(os) % 4) {
WRITE_DATA(fp, &padding, 4 - strlen(os) % 4 , *bytes_written, err);
}
}
if (have_options) {
option.type = OPT_ENDOFOPT;
option.value_length = 0;
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
}
WRITE_DATA(fp, &block_total_length, sizeof(guint32), *bytes_written, err);
return TRUE;
}
gboolean
libpcap_write_enhanced_packet_block(FILE *fp,
const struct pcap_pkthdr *phdr,
guint32 interface_id,
guint ts_mul,
const u_char *pd,
long *bytes_written,
int *err)
{
struct epb epb;
guint32 block_total_length;
guint64 timestamp;
const guint32 padding = 0;
block_total_length = sizeof(struct epb) +
ADD_PADDING(phdr->caplen) +
sizeof(guint32);
timestamp = (guint64)(phdr->ts.tv_sec) * ts_mul +
(guint64)(phdr->ts.tv_usec);
epb.block_type = ENHANCED_PACKET_BLOCK_TYPE;
epb.block_total_length = block_total_length;
epb.interface_id = interface_id;
epb.timestamp_high = (guint32)((timestamp>>32) & 0xffffffff);
epb.timestamp_low = (guint32)(timestamp & 0xffffffff);
epb.captured_len = phdr->caplen;
epb.packet_len = phdr->len;
WRITE_DATA(fp, &epb, sizeof(struct epb), *bytes_written, err);
WRITE_DATA(fp, pd, phdr->caplen, *bytes_written, err);
if (phdr->caplen % 4) {
WRITE_DATA(fp, &padding, 4 - phdr->caplen % 4, *bytes_written, err);
}
WRITE_DATA(fp, &block_total_length, sizeof(guint32), *bytes_written, err);
return TRUE;
}
gboolean
libpcap_write_interface_statistics_block(FILE *fp,
guint32 interface_id,
long *bytes_written,
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
block_total_length = sizeof(struct isb) + sizeof(guint32);
if (isb_ifrecv != G_MAXUINT64) {
block_total_length += sizeof(struct option) + sizeof(guint64);
have_options = TRUE;
}
if (isb_ifdrop != G_MAXUINT64) {
block_total_length += sizeof(struct option) + sizeof(guint64);
have_options = TRUE;
}
if ((comment != NULL) && (strlen(comment) > 0) && (strlen(comment) < G_MAXUINT16)) {
block_total_length += sizeof(struct option) +
(guint16)ADD_PADDING(strlen(comment));
have_options = TRUE;
}
if (isb_starttime !=0) {
block_total_length += sizeof(struct option) + sizeof(guint64);
have_options = TRUE;
}
if (isb_endtime !=0) {
block_total_length += sizeof(struct option) + sizeof(guint64);
have_options = TRUE;
}
if (have_options) {
block_total_length += sizeof(struct option);
}
isb.block_type = INTERFACE_STATISTICS_BLOCK_TYPE;
isb.block_total_length = block_total_length;
isb.interface_id = interface_id;
isb.timestamp_high = (guint32)((timestamp>>32) & 0xffffffff);
isb.timestamp_low = (guint32)(timestamp & 0xffffffff);
WRITE_DATA(fp, &isb, sizeof(struct isb), *bytes_written, err);
if ((comment != NULL) && (strlen(comment) > 0) && (strlen(comment) < G_MAXUINT16)) {
option.type = OPT_COMMENT;
option.value_length = (guint16)strlen(comment);
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, comment, strlen(comment), *bytes_written, err);
if (strlen(comment) % 4) {
WRITE_DATA(fp, &padding, 4 - strlen(comment) % 4 , *bytes_written, err);
}
}
if (isb_starttime !=0) {
guint32 high, low;
option.type = ISB_STARTTIME;
option.value_length = sizeof(guint64);
high = (guint32)((isb_starttime>>32) & 0xffffffff);
low = (guint32)(isb_starttime & 0xffffffff);
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, &high, sizeof(guint32), *bytes_written, err);
WRITE_DATA(fp, &low, sizeof(guint32), *bytes_written, err);
}
if (isb_endtime !=0) {
guint32 high, low;
option.type = ISB_ENDTIME;
option.value_length = sizeof(guint64);
high = (guint32)((isb_endtime>>32) & 0xffffffff);
low = (guint32)(isb_endtime & 0xffffffff);
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, &high, sizeof(guint32), *bytes_written, err);
WRITE_DATA(fp, &low, sizeof(guint32), *bytes_written, err);
}
if (isb_ifrecv != G_MAXUINT64) {
option.type = ISB_IFRECV;
option.value_length = sizeof(guint64);
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, &isb_ifrecv, sizeof(guint64), *bytes_written, err);
}
if (isb_ifdrop != G_MAXUINT64) {
option.type = ISB_IFDROP;
option.value_length = sizeof(guint64);
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
WRITE_DATA(fp, &isb_ifdrop, sizeof(guint64), *bytes_written, err);
}
if (have_options) {
option.type = OPT_ENDOFOPT;
option.value_length = 0;
WRITE_DATA(fp, &option, sizeof(struct option), *bytes_written, err);
}
WRITE_DATA(fp, &block_total_length, sizeof(guint32), *bytes_written, err);
return TRUE;
}
gboolean
libpcap_dump_flush(FILE *pd, int *err)
{
if (fflush(pd) == EOF) {
if (err != NULL)
*err = errno;
return FALSE;
}
return TRUE;
}
gboolean
libpcap_dump_close(FILE *pd, int *err)
{
if (fclose(pd) == EOF) {
if (err != NULL)
*err = errno;
return FALSE;
}
return TRUE;
}
