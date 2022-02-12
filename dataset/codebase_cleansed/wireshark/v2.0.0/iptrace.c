wtap_open_return_val iptrace_open(wtap *wth, int *err, gchar **err_info)
{
char name[NAME_SIZE+1];
if (!wtap_read_bytes(wth->fh, name, NAME_SIZE, err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
name[NAME_SIZE] = '\0';
if (strcmp(name, "iptrace 1.0") == 0) {
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_IPTRACE_1_0;
wth->subtype_read = iptrace_read_1_0;
wth->subtype_seek_read = iptrace_seek_read_1_0;
wth->file_tsprec = WTAP_TSPREC_SEC;
}
else if (strcmp(name, "iptrace 2.0") == 0) {
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_IPTRACE_2_0;
wth->subtype_read = iptrace_read_2_0;
wth->subtype_seek_read = iptrace_seek_read_2_0;
wth->file_tsprec = WTAP_TSPREC_NSEC;
}
else {
return WTAP_OPEN_NOT_MINE;
}
return WTAP_OPEN_MINE;
}
static gboolean
iptrace_read_rec_1_0(FILE_T fh, struct wtap_pkthdr *phdr, Buffer *buf,
int *err, gchar **err_info)
{
guint8 header[IPTRACE_1_0_PHDR_SIZE];
iptrace_1_0_phdr pkt_hdr;
guint32 packet_size;
if (!wtap_read_bytes_or_eof(fh, header, sizeof header, err, err_info)) {
return FALSE;
}
pkt_hdr.if_type = header[28];
phdr->pkt_encap = wtap_encap_ift(pkt_hdr.if_type);
if (phdr->pkt_encap == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("iptrace: interface type IFT=0x%02x unknown or unsupported",
pkt_hdr.if_type);
return FALSE;
}
packet_size = pntoh32(&header[0]);
if (packet_size < IPTRACE_1_0_PDATA_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("iptrace: file has a %u-byte record, too small to have even a packet meta-data header",
packet_size);
return FALSE;
}
packet_size -= IPTRACE_1_0_PDATA_SIZE;
if (phdr->pkt_encap == WTAP_ENCAP_FDDI_BITSWAPPED) {
if (packet_size < 3) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("iptrace: file has a %u-byte record, too small to have even a packet meta-data header",
packet_size + IPTRACE_1_0_PDATA_SIZE);
return FALSE;
}
packet_size -= 3;
if (!file_skip(fh, 3, err))
return FALSE;
}
if (packet_size > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("iptrace: File has %u-byte packet, bigger than maximum of %u",
packet_size, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
phdr->len = packet_size;
phdr->caplen = packet_size;
phdr->ts.secs = pntoh32(&header[4]);
phdr->ts.nsecs = 0;
fill_in_pseudo_header(phdr->pkt_encap, &phdr->pseudo_header, header);
return iptrace_read_rec_data(fh, buf, phdr, err, err_info);
}
static gboolean iptrace_read_1_0(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
*data_offset = file_tell(wth->fh);
if (!iptrace_read_rec_1_0(wth->fh, &wth->phdr, wth->frame_buffer,
err, err_info)) {
return FALSE;
}
if (wth->file_encap == WTAP_ENCAP_UNKNOWN)
wth->file_encap = wth->phdr.pkt_encap;
else {
if (wth->file_encap != wth->phdr.pkt_encap)
wth->file_encap = WTAP_ENCAP_PER_PACKET;
}
return TRUE;
}
static gboolean iptrace_seek_read_1_0(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!iptrace_read_rec_1_0(wth->random_fh, phdr, buf, err, err_info)) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static gboolean
iptrace_read_rec_2_0(FILE_T fh, struct wtap_pkthdr *phdr, Buffer *buf,
int *err, gchar **err_info)
{
guint8 header[IPTRACE_2_0_PHDR_SIZE];
iptrace_2_0_phdr pkt_hdr;
guint32 packet_size;
if (!wtap_read_bytes_or_eof(fh, header, sizeof header, err, err_info)) {
return FALSE;
}
pkt_hdr.if_type = header[28];
phdr->pkt_encap = wtap_encap_ift(pkt_hdr.if_type);
#if 0
if (phdr->pkt_encap == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("iptrace: interface type IFT=0x%02x unknown or unsupported",
pkt_hdr.if_type);
return FALSE;
}
#endif
packet_size = pntoh32(&header[0]);
if (packet_size < IPTRACE_2_0_PDATA_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("iptrace: file has a %u-byte record, too small to have even a packet meta-data header",
packet_size);
return FALSE;
}
packet_size -= IPTRACE_2_0_PDATA_SIZE;
if (phdr->pkt_encap == WTAP_ENCAP_FDDI_BITSWAPPED) {
if (packet_size < 3) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("iptrace: file has a %u-byte record, too small to have even a packet meta-data header",
packet_size + IPTRACE_2_0_PDATA_SIZE);
return FALSE;
}
packet_size -= 3;
if (!file_skip(fh, 3, err))
return FALSE;
}
if (packet_size > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("iptrace: File has %u-byte packet, bigger than maximum of %u",
packet_size, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
phdr->len = packet_size;
phdr->caplen = packet_size;
phdr->ts.secs = pntoh32(&header[32]);
phdr->ts.nsecs = pntoh32(&header[36]);
fill_in_pseudo_header(phdr->pkt_encap, &phdr->pseudo_header, header);
return iptrace_read_rec_data(fh, buf, phdr, err, err_info);
}
static gboolean iptrace_read_2_0(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
*data_offset = file_tell(wth->fh);
if (!iptrace_read_rec_2_0(wth->fh, &wth->phdr, wth->frame_buffer,
err, err_info)) {
return FALSE;
}
if (wth->file_encap == WTAP_ENCAP_UNKNOWN)
wth->file_encap = wth->phdr.pkt_encap;
else {
if (wth->file_encap != wth->phdr.pkt_encap)
wth->file_encap = WTAP_ENCAP_PER_PACKET;
}
return TRUE;
}
static gboolean iptrace_seek_read_2_0(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!iptrace_read_rec_2_0(wth->random_fh, phdr, buf, err, err_info)) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static gboolean
iptrace_read_rec_data(FILE_T fh, Buffer *buf, struct wtap_pkthdr *phdr,
int *err, gchar **err_info)
{
if (!wtap_read_packet_bytes(fh, buf, phdr->caplen, err, err_info))
return FALSE;
if (phdr->pkt_encap == WTAP_ENCAP_ATM_PDUS) {
atm_guess_traffic_type(phdr, ws_buffer_start_ptr(buf));
}
return TRUE;
}
static void
fill_in_pseudo_header(int encap, union wtap_pseudo_header *pseudo_header,
guint8 *header)
{
char if_text[9];
char *decimal;
int Vpi = 0;
int Vci = 0;
switch (encap) {
case WTAP_ENCAP_ATM_PDUS:
memcpy(if_text, &header[20], 8);
if_text[8] = '\0';
decimal = strchr(if_text, '.');
if (decimal) {
*decimal = '\0';
Vpi = (int)strtoul(if_text, NULL, 10);
decimal++;
Vci = (int)strtoul(decimal, NULL, 10);
}
pseudo_header->atm.channel = header[29];
pseudo_header->atm.vpi = Vpi;
pseudo_header->atm.vci = Vci;
pseudo_header->atm.flags = 0;
pseudo_header->atm.cells = 0;
pseudo_header->atm.aal5t_u2u = 0;
pseudo_header->atm.aal5t_len = 0;
pseudo_header->atm.aal5t_chksum = 0;
break;
case WTAP_ENCAP_ETHERNET:
pseudo_header->eth.fcs_len = 0;
break;
}
}
static int
wtap_encap_ift(unsigned int ift)
{
static const int ift_encap[] = {
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_RAW_IP,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_ETHERNET,
WTAP_ENCAP_ETHERNET,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_TOKEN_RING,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_RAW_IP,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_FDDI_BITSWAPPED,
WTAP_ENCAP_LAPB,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_RAW_IP,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_ATM_PDUS,
};
#define NUM_IFT_ENCAPS (sizeof ift_encap / sizeof ift_encap[0])
if (ift < NUM_IFT_ENCAPS) {
return ift_encap[ift];
}
else {
switch(ift) {
case IPTRACE_IFT_IB:
return WTAP_ENCAP_INFINIBAND;
break;
case IPTRACE_IFT_HF:
return WTAP_ENCAP_RAW_IP;
break;
default:
return WTAP_ENCAP_UNKNOWN;
}
}
}
