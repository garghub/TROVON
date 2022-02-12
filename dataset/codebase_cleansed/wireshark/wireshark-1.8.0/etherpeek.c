int etherpeek_open(wtap *wth, int *err, gchar **err_info)
{
etherpeek_header_t ep_hdr;
struct timeval reference_time;
int file_encap;
etherpeek_t *etherpeek;
g_assert(sizeof(ep_hdr.master) == ETHERPEEK_MASTER_HDR_SIZE);
wtap_file_read_unknown_bytes(
&ep_hdr.master, sizeof(ep_hdr.master), wth->fh, err, err_info);
ep_hdr.master.version &= ~0x80;
switch (ep_hdr.master.version) {
case 5:
case 6:
case 7:
g_assert(sizeof(ep_hdr.secondary.v567) ==
ETHERPEEK_V567_HDR_SIZE);
wtap_file_read_unknown_bytes(
&ep_hdr.secondary.v567,
sizeof(ep_hdr.secondary.v567), wth->fh, err, err_info);
if ((0 != ep_hdr.secondary.v567.reserved[0]) ||
(0 != ep_hdr.secondary.v567.reserved[1]) ||
(0 != ep_hdr.secondary.v567.reserved[2])) {
return 0;
}
ep_hdr.secondary.v567.mediaType =
g_ntohl(ep_hdr.secondary.v567.mediaType);
ep_hdr.secondary.v567.physMedium =
g_ntohl(ep_hdr.secondary.v567.physMedium);
switch (ep_hdr.secondary.v567.physMedium) {
case 0:
switch (ep_hdr.secondary.v567.mediaType) {
case 0:
file_encap = WTAP_ENCAP_ETHERNET;
break;
case 1:
file_encap = WTAP_ENCAP_TOKEN_RING;
break;
default:
return 0;
}
break;
case 1:
switch (ep_hdr.secondary.v567.mediaType) {
case 0:
file_encap = WTAP_ENCAP_IEEE_802_11_AIROPEEK;
break;
default:
return 0;
}
break;
default:
return 0;
}
ep_hdr.secondary.v567.filelength =
g_ntohl(ep_hdr.secondary.v567.filelength);
ep_hdr.secondary.v567.numPackets =
g_ntohl(ep_hdr.secondary.v567.numPackets);
ep_hdr.secondary.v567.timeDate =
g_ntohl(ep_hdr.secondary.v567.timeDate);
ep_hdr.secondary.v567.timeStart =
g_ntohl(ep_hdr.secondary.v567.timeStart);
ep_hdr.secondary.v567.timeStop =
g_ntohl(ep_hdr.secondary.v567.timeStop);
ep_hdr.secondary.v567.appVers =
g_ntohl(ep_hdr.secondary.v567.appVers);
ep_hdr.secondary.v567.linkSpeed =
g_ntohl(ep_hdr.secondary.v567.linkSpeed);
reference_time.tv_sec =
ep_hdr.secondary.v567.timeDate - mac2unix;
reference_time.tv_usec = 0;
break;
default:
return 0;
}
etherpeek = (etherpeek_t *)g_malloc(sizeof(etherpeek_t));
wth->priv = (void *)etherpeek;
etherpeek->reference_time = reference_time;
switch (ep_hdr.master.version) {
case 5:
case 6:
wth->file_type = WTAP_FILE_ETHERPEEK_V56;
wth->file_encap = WTAP_ENCAP_PER_PACKET;
wth->subtype_read = etherpeek_read_v56;
wth->subtype_seek_read = etherpeek_seek_read_v56;
break;
case 7:
wth->file_type = WTAP_FILE_ETHERPEEK_V7;
wth->file_encap = file_encap;
wth->subtype_read = etherpeek_read_v7;
wth->subtype_seek_read = etherpeek_seek_read_v7;
break;
default:
g_assert_not_reached();
}
wth->snapshot_length = 0;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
return 1;
}
static gboolean etherpeek_read_v7(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
guint8 ep_pkt[ETHERPEEK_V7_PKT_SIZE];
#if 0
guint16 protoNum;
#endif
guint16 length;
guint16 sliceLength;
#if 0
guint8 flags;
#endif
guint8 status;
guint64 timestamp;
time_t tsecs;
guint32 tusecs;
*data_offset = file_tell(wth->fh);
wtap_file_read_expected_bytes(ep_pkt, sizeof(ep_pkt), wth->fh, err,
err_info);
#if 0
protoNum = pntohs(&ep_pkt[ETHERPEEK_V7_PROTONUM_OFFSET]);
#endif
length = pntohs(&ep_pkt[ETHERPEEK_V7_LENGTH_OFFSET]);
sliceLength = pntohs(&ep_pkt[ETHERPEEK_V7_SLICE_LENGTH_OFFSET]);
#if 0
flags = ep_pkt[ETHERPEEK_V7_FLAGS_OFFSET];
#endif
status = ep_pkt[ETHERPEEK_V7_STATUS_OFFSET];
timestamp = pntohll(&ep_pkt[ETHERPEEK_V7_TIMESTAMP_OFFSET]);
if (0 == sliceLength) {
sliceLength = length;
}
wth->phdr.presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
wth->phdr.len = length;
wth->phdr.caplen = sliceLength;
if (sliceLength % 2)
sliceLength++;
switch (wth->file_encap) {
case WTAP_ENCAP_IEEE_802_11_AIROPEEK:
wth->pseudo_header.ieee_802_11.fcs_len = 0;
break;
case WTAP_ENCAP_ETHERNET:
wth->pseudo_header.eth.fcs_len = (status & 0x01) ? 0 : 4;
break;
}
buffer_assure_space(wth->frame_buffer, sliceLength);
wtap_file_read_expected_bytes(buffer_start_ptr(wth->frame_buffer),
sliceLength, wth->fh, err, err_info);
tsecs = (time_t) (timestamp/1000000);
tusecs = (guint32) (timestamp - tsecs*1000000);
wth->phdr.ts.secs = tsecs - mac2unix;
wth->phdr.ts.nsecs = tusecs * 1000;
if (wth->file_encap == WTAP_ENCAP_IEEE_802_11_AIROPEEK) {
wth->phdr.len -= 4;
wth->phdr.caplen -= 4;
}
return TRUE;
}
static gboolean
etherpeek_seek_read_v7(wtap *wth, gint64 seek_off,
union wtap_pseudo_header *pseudo_header, guint8 *pd, int length,
int *err, gchar **err_info)
{
guint8 ep_pkt[ETHERPEEK_V7_PKT_SIZE];
guint8 status;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
wtap_file_read_expected_bytes(ep_pkt, sizeof(ep_pkt), wth->random_fh,
err, err_info);
status = ep_pkt[ETHERPEEK_V7_STATUS_OFFSET];
switch (wth->file_encap) {
case WTAP_ENCAP_IEEE_802_11_AIROPEEK:
pseudo_header->ieee_802_11.fcs_len = 0;
break;
case WTAP_ENCAP_ETHERNET:
pseudo_header->eth.fcs_len = (status & 0x01) ? 0 : 4;
break;
}
errno = WTAP_ERR_CANT_READ;
wtap_file_read_expected_bytes(pd, length, wth->random_fh, err,
err_info);
return TRUE;
}
static gboolean etherpeek_read_v56(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
etherpeek_t *etherpeek = (etherpeek_t *)wth->priv;
guint8 ep_pkt[ETHERPEEK_V56_PKT_SIZE];
guint16 length;
guint16 sliceLength;
#if 0
guint8 flags;
guint8 status;
#endif
guint32 timestamp;
#if 0
guint16 destNum;
guint16 srcNum;
#endif
guint16 protoNum;
char protoStr[8];
unsigned int i;
*data_offset = file_tell(wth->fh);
wtap_file_read_expected_bytes(ep_pkt, sizeof(ep_pkt), wth->fh, err,
err_info);
length = pntohs(&ep_pkt[ETHERPEEK_V56_LENGTH_OFFSET]);
sliceLength = pntohs(&ep_pkt[ETHERPEEK_V56_SLICE_LENGTH_OFFSET]);
#if 0
flags = ep_pkt[ETHERPEEK_V56_FLAGS_OFFSET];
status = ep_pkt[ETHERPEEK_V56_STATUS_OFFSET];
#endif
timestamp = pntohl(&ep_pkt[ETHERPEEK_V56_TIMESTAMP_OFFSET]);
#if 0
destNum = pntohs(&ep_pkt[ETHERPEEK_V56_DESTNUM_OFFSET]);
srcNum = pntohs(&ep_pkt[ETHERPEEK_V56_SRCNUM_OFFSET]);
#endif
protoNum = pntohs(&ep_pkt[ETHERPEEK_V56_PROTONUM_OFFSET]);
memcpy(protoStr, &ep_pkt[ETHERPEEK_V56_PROTOSTR_OFFSET],
sizeof protoStr);
if (0 == sliceLength) {
sliceLength = length;
}
buffer_assure_space(wth->frame_buffer, sliceLength);
wtap_file_read_expected_bytes(buffer_start_ptr(wth->frame_buffer),
sliceLength, wth->fh, err, err_info);
wth->phdr.len = length;
wth->phdr.caplen = sliceLength;
wth->phdr.ts.secs = etherpeek->reference_time.tv_sec
+ (timestamp / 1000);
wth->phdr.ts.nsecs = 1000 * (timestamp % 1000) * 1000;
wth->phdr.pkt_encap = WTAP_ENCAP_UNKNOWN;
for (i=0; i<NUM_ETHERPEEK_ENCAPS; i++) {
if (etherpeek_encap[i].protoNum == protoNum) {
wth->phdr.pkt_encap = etherpeek_encap[i].encap;
}
}
switch (wth->phdr.pkt_encap) {
case WTAP_ENCAP_ETHERNET:
wth->pseudo_header.eth.fcs_len = 0;
break;
}
return TRUE;
}
static gboolean
etherpeek_seek_read_v56(wtap *wth, gint64 seek_off,
union wtap_pseudo_header *pseudo_header, guint8 *pd, int length,
int *err, gchar **err_info)
{
guint8 ep_pkt[ETHERPEEK_V56_PKT_SIZE];
int pkt_encap;
guint16 protoNum;
unsigned int i;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
wtap_file_read_expected_bytes(ep_pkt, sizeof(ep_pkt), wth->random_fh,
err, err_info);
protoNum = pntohs(&ep_pkt[ETHERPEEK_V56_PROTONUM_OFFSET]);
pkt_encap = WTAP_ENCAP_UNKNOWN;
for (i=0; i<NUM_ETHERPEEK_ENCAPS; i++) {
if (etherpeek_encap[i].protoNum == protoNum) {
pkt_encap = etherpeek_encap[i].encap;
}
}
switch (pkt_encap) {
case WTAP_ENCAP_ETHERNET:
pseudo_header->eth.fcs_len = 0;
break;
}
errno = WTAP_ERR_CANT_READ;
wtap_file_read_expected_bytes(pd, length, wth->random_fh, err,
err_info);
return TRUE;
}
