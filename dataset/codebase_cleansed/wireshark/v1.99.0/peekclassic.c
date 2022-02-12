int peekclassic_open(wtap *wth, int *err, gchar **err_info)
{
peekclassic_header_t ep_hdr;
struct timeval reference_time;
int file_encap;
peekclassic_t *peekclassic;
g_assert(sizeof(ep_hdr.master) == PEEKCLASSIC_MASTER_HDR_SIZE);
if (!wtap_read_bytes(wth->fh, &ep_hdr.master,
(int)sizeof(ep_hdr.master), err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
ep_hdr.master.version &= ~0x80;
switch (ep_hdr.master.version) {
case 5:
case 6:
case 7:
g_assert(sizeof(ep_hdr.secondary.v567) ==
PEEKCLASSIC_V567_HDR_SIZE);
if (!wtap_read_bytes(wth->fh, &ep_hdr.secondary.v567,
(int)sizeof(ep_hdr.secondary.v567), err, err_info)) {
if (*err == WTAP_ERR_SHORT_READ) {
return 0;
}
return -1;
}
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
peekclassic = (peekclassic_t *)g_malloc(sizeof(peekclassic_t));
wth->priv = (void *)peekclassic;
peekclassic->reference_time = reference_time;
switch (ep_hdr.master.version) {
case 5:
case 6:
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_PEEKCLASSIC_V56;
wth->file_encap = WTAP_ENCAP_PER_PACKET;
wth->subtype_read = peekclassic_read_v56;
wth->subtype_seek_read = peekclassic_seek_read_v56;
break;
case 7:
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_PEEKCLASSIC_V7;
wth->file_encap = file_encap;
wth->subtype_read = peekclassic_read_v7;
wth->subtype_seek_read = peekclassic_seek_read_v7;
break;
default:
g_assert_not_reached();
}
wth->snapshot_length = 0;
wth->file_tsprec = WTAP_TSPREC_USEC;
return 1;
}
static gboolean peekclassic_read_v7(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
int sliceLength;
*data_offset = file_tell(wth->fh);
sliceLength = peekclassic_read_packet_v7(wth, wth->fh, &wth->phdr,
wth->frame_buffer, err, err_info);
if (sliceLength < 0)
return FALSE;
if ((guint32)sliceLength > wth->phdr.caplen) {
if (!file_skip(wth->fh, sliceLength - wth->phdr.caplen, err))
return FALSE;
}
if (sliceLength & 0x01) {
if (!file_skip(wth->fh, 1, err))
return FALSE;
}
return TRUE;
}
static gboolean peekclassic_seek_read_v7(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (peekclassic_read_packet_v7(wth, wth->random_fh, phdr, buf,
err, err_info) == -1) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static int peekclassic_read_packet_v7(wtap *wth, FILE_T fh,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
guint8 ep_pkt[PEEKCLASSIC_V7_PKT_SIZE];
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
if (!wtap_read_bytes_or_eof(fh, ep_pkt, sizeof(ep_pkt), err, err_info))
return -1;
#if 0
protoNum = pntoh16(&ep_pkt[PEEKCLASSIC_V7_PROTONUM_OFFSET]);
#endif
length = pntoh16(&ep_pkt[PEEKCLASSIC_V7_LENGTH_OFFSET]);
sliceLength = pntoh16(&ep_pkt[PEEKCLASSIC_V7_SLICE_LENGTH_OFFSET]);
#if 0
flags = ep_pkt[PEEKCLASSIC_V7_FLAGS_OFFSET];
#endif
status = ep_pkt[PEEKCLASSIC_V7_STATUS_OFFSET];
timestamp = pntoh64(&ep_pkt[PEEKCLASSIC_V7_TIMESTAMP_OFFSET]);
if (0 == sliceLength) {
sliceLength = length;
}
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
tsecs = (time_t) (timestamp/1000000);
tusecs = (guint32) (timestamp - tsecs*1000000);
phdr->ts.secs = tsecs - mac2unix;
phdr->ts.nsecs = tusecs * 1000;
phdr->len = length;
phdr->caplen = sliceLength;
switch (wth->file_encap) {
case WTAP_ENCAP_IEEE_802_11_AIROPEEK:
phdr->pseudo_header.ieee_802_11.fcs_len = 0;
phdr->pseudo_header.ieee_802_11.decrypted = FALSE;
if (phdr->len < 4 || phdr->caplen < 4) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("peekclassic: 802.11 packet has length < 4");
return -1;
}
phdr->len -= 4;
phdr->caplen -= 4;
break;
case WTAP_ENCAP_ETHERNET:
phdr->pseudo_header.eth.fcs_len = (status & 0x01) ? 0 : 4;
break;
}
if (!wtap_read_packet_bytes(fh, buf, phdr->caplen, err, err_info))
return -1;
return sliceLength;
}
static gboolean peekclassic_read_v56(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
*data_offset = file_tell(wth->fh);
if (!peekclassic_read_packet_v56(wth, wth->fh, &wth->phdr,
wth->frame_buffer, err, err_info))
return FALSE;
return TRUE;
}
static gboolean peekclassic_seek_read_v56(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!peekclassic_read_packet_v56(wth, wth->random_fh, phdr, buf,
err, err_info)) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static gboolean peekclassic_read_packet_v56(wtap *wth, FILE_T fh,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
peekclassic_t *peekclassic = (peekclassic_t *)wth->priv;
guint8 ep_pkt[PEEKCLASSIC_V56_PKT_SIZE];
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
#if 0
char protoStr[8];
#endif
unsigned int i;
if (!wtap_read_bytes_or_eof(fh, ep_pkt, sizeof(ep_pkt), err, err_info))
return FALSE;
length = pntoh16(&ep_pkt[PEEKCLASSIC_V56_LENGTH_OFFSET]);
sliceLength = pntoh16(&ep_pkt[PEEKCLASSIC_V56_SLICE_LENGTH_OFFSET]);
#if 0
flags = ep_pkt[PEEKCLASSIC_V56_FLAGS_OFFSET];
status = ep_pkt[PEEKCLASSIC_V56_STATUS_OFFSET];
#endif
timestamp = pntoh32(&ep_pkt[PEEKCLASSIC_V56_TIMESTAMP_OFFSET]);
#if 0
destNum = pntoh16(&ep_pkt[PEEKCLASSIC_V56_DESTNUM_OFFSET]);
srcNum = pntoh16(&ep_pkt[PEEKCLASSIC_V56_SRCNUM_OFFSET]);
#endif
protoNum = pntoh16(&ep_pkt[PEEKCLASSIC_V56_PROTONUM_OFFSET]);
#if 0
memcpy(protoStr, &ep_pkt[PEEKCLASSIC_V56_PROTOSTR_OFFSET],
sizeof protoStr);
#endif
if (0 == sliceLength) {
sliceLength = length;
}
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
phdr->ts.secs = peekclassic->reference_time.tv_sec
+ (timestamp / 1000);
phdr->ts.nsecs = 1000 * (timestamp % 1000) * 1000;
phdr->len = length;
phdr->caplen = sliceLength;
phdr->pkt_encap = WTAP_ENCAP_UNKNOWN;
for (i=0; i<NUM_PEEKCLASSIC_ENCAPS; i++) {
if (peekclassic_encap[i].protoNum == protoNum) {
phdr->pkt_encap = peekclassic_encap[i].encap;
}
}
switch (phdr->pkt_encap) {
case WTAP_ENCAP_ETHERNET:
phdr->pseudo_header.eth.fcs_len = 0;
break;
}
return wtap_read_packet_bytes(fh, buf, sliceLength, err, err_info);
}
