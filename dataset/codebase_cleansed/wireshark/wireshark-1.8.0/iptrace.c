int iptrace_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
char name[12];
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(name, 11, wth->fh);
if (bytes_read != 11) {
*err = file_error(wth->fh, err_info);
if (*err != 0)
return -1;
return 0;
}
name[11] = 0;
if (strcmp(name, "iptrace 1.0") == 0) {
wth->file_type = WTAP_FILE_IPTRACE_1_0;
wth->subtype_read = iptrace_read_1_0;
wth->subtype_seek_read = iptrace_seek_read_1_0;
wth->tsprecision = WTAP_FILE_TSPREC_SEC;
}
else if (strcmp(name, "iptrace 2.0") == 0) {
wth->file_type = WTAP_FILE_IPTRACE_2_0;
wth->subtype_read = iptrace_read_2_0;
wth->subtype_seek_read = iptrace_seek_read_2_0;
wth->tsprecision = WTAP_FILE_TSPREC_NSEC;
}
else {
return 0;
}
return 1;
}
static gboolean iptrace_read_1_0(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
int ret;
guint32 packet_size;
guint8 header[IPTRACE_1_0_PHDR_SIZE];
guint8 *data_ptr;
iptrace_1_0_phdr pkt_hdr;
guint8 fddi_padding[3];
*data_offset = file_tell(wth->fh);
ret = iptrace_read_rec_header(wth->fh, header, IPTRACE_1_0_PHDR_SIZE,
err, err_info);
if (ret <= 0) {
return FALSE;
}
pkt_hdr.if_type = header[28];
wth->phdr.pkt_encap = wtap_encap_ift(pkt_hdr.if_type);
packet_size = pntohl(&header[0]);
if (packet_size < IPTRACE_1_0_PDATA_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("iptrace: file has a %u-byte record, too small to have even a packet meta-data header",
packet_size);
return FALSE;
}
packet_size -= IPTRACE_1_0_PDATA_SIZE;
if (wth->phdr.pkt_encap == WTAP_ENCAP_FDDI_BITSWAPPED) {
if (packet_size < 3) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("iptrace: file has a %u-byte record, too small to have even a packet meta-data header",
packet_size + IPTRACE_1_0_PDATA_SIZE);
return FALSE;
}
packet_size -= 3;
if (!iptrace_read_rec_data(wth->fh, fddi_padding, 3, err,
err_info))
return FALSE;
}
if (packet_size > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("iptrace: File has %u-byte packet, bigger than maximum of %u",
packet_size, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
buffer_assure_space( wth->frame_buffer, packet_size );
data_ptr = buffer_start_ptr( wth->frame_buffer );
if (!iptrace_read_rec_data(wth->fh, data_ptr, packet_size, err,
err_info))
return FALSE;
wth->phdr.presence_flags = WTAP_HAS_TS;
wth->phdr.len = packet_size;
wth->phdr.caplen = packet_size;
wth->phdr.ts.secs = pntohl(&header[4]);
wth->phdr.ts.nsecs = 0;
if (wth->phdr.pkt_encap == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("iptrace: interface type IFT=0x%02x unknown or unsupported",
pkt_hdr.if_type);
return FALSE;
}
fill_in_pseudo_header(wth->phdr.pkt_encap, data_ptr, wth->phdr.caplen,
&wth->pseudo_header, header);
if (wth->file_encap == WTAP_ENCAP_UNKNOWN)
wth->file_encap = wth->phdr.pkt_encap;
else {
if (wth->file_encap != wth->phdr.pkt_encap)
wth->file_encap = WTAP_ENCAP_PER_PACKET;
}
return TRUE;
}
static gboolean iptrace_seek_read_1_0(wtap *wth, gint64 seek_off,
union wtap_pseudo_header *pseudo_header, guint8 *pd, int packet_size,
int *err, gchar **err_info)
{
int ret;
guint8 header[IPTRACE_1_0_PHDR_SIZE];
int pkt_encap;
guint8 fddi_padding[3];
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
ret = iptrace_read_rec_header(wth->random_fh, header,
IPTRACE_1_0_PHDR_SIZE, err, err_info);
if (ret <= 0) {
if (ret == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
pkt_encap = wtap_encap_ift(header[28]);
if (pkt_encap == WTAP_ENCAP_FDDI_BITSWAPPED) {
if (!iptrace_read_rec_data(wth->random_fh, fddi_padding, 3,
err, err_info))
return FALSE;
}
if (!iptrace_read_rec_data(wth->random_fh, pd, packet_size, err,
err_info))
return FALSE;
fill_in_pseudo_header(pkt_encap, pd, packet_size, pseudo_header,
header);
return TRUE;
}
static gboolean iptrace_read_2_0(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
int ret;
guint32 packet_size;
guint8 header[IPTRACE_2_0_PHDR_SIZE];
guint8 *data_ptr;
iptrace_2_0_phdr pkt_hdr;
guint8 fddi_padding[3];
*data_offset = file_tell(wth->fh);
ret = iptrace_read_rec_header(wth->fh, header, IPTRACE_2_0_PHDR_SIZE,
err, err_info);
if (ret <= 0) {
return FALSE;
}
pkt_hdr.if_type = header[28];
wth->phdr.pkt_encap = wtap_encap_ift(pkt_hdr.if_type);
packet_size = pntohl(&header[0]);
if (packet_size < IPTRACE_2_0_PDATA_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("iptrace: file has a %u-byte record, too small to have even a packet meta-data header",
packet_size);
return FALSE;
}
packet_size -= IPTRACE_2_0_PDATA_SIZE;
if (wth->phdr.pkt_encap == WTAP_ENCAP_FDDI_BITSWAPPED) {
if (packet_size < 3) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("iptrace: file has a %u-byte record, too small to have even a packet meta-data header",
packet_size + IPTRACE_2_0_PDATA_SIZE);
return FALSE;
}
packet_size -= 3;
if (!iptrace_read_rec_data(wth->fh, fddi_padding, 3, err,
err_info))
return FALSE;
}
if (packet_size > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("iptrace: File has %u-byte packet, bigger than maximum of %u",
packet_size, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
buffer_assure_space( wth->frame_buffer, packet_size );
data_ptr = buffer_start_ptr( wth->frame_buffer );
if (!iptrace_read_rec_data(wth->fh, data_ptr, packet_size, err,
err_info))
return FALSE;
wth->phdr.presence_flags = WTAP_HAS_TS;
wth->phdr.len = packet_size;
wth->phdr.caplen = packet_size;
wth->phdr.ts.secs = pntohl(&header[32]);
wth->phdr.ts.nsecs = pntohl(&header[36]);
if (wth->phdr.pkt_encap == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("iptrace: interface type IFT=0x%02x unknown or unsupported",
pkt_hdr.if_type);
return FALSE;
}
fill_in_pseudo_header(wth->phdr.pkt_encap, data_ptr, wth->phdr.caplen,
&wth->pseudo_header, header);
if (wth->file_encap == WTAP_ENCAP_UNKNOWN)
wth->file_encap = wth->phdr.pkt_encap;
else {
if (wth->file_encap != wth->phdr.pkt_encap)
wth->file_encap = WTAP_ENCAP_PER_PACKET;
}
return TRUE;
}
static gboolean iptrace_seek_read_2_0(wtap *wth, gint64 seek_off,
union wtap_pseudo_header *pseudo_header, guint8 *pd, int packet_size,
int *err, gchar **err_info)
{
int ret;
guint8 header[IPTRACE_2_0_PHDR_SIZE];
int pkt_encap;
guint8 fddi_padding[3];
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
ret = iptrace_read_rec_header(wth->random_fh, header,
IPTRACE_2_0_PHDR_SIZE, err, err_info);
if (ret <= 0) {
if (ret == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
pkt_encap = wtap_encap_ift(header[28]);
if (pkt_encap == WTAP_ENCAP_FDDI_BITSWAPPED) {
if (!iptrace_read_rec_data(wth->random_fh, fddi_padding, 3,
err, err_info))
return FALSE;
}
if (!iptrace_read_rec_data(wth->random_fh, pd, packet_size, err,
err_info))
return FALSE;
fill_in_pseudo_header(pkt_encap, pd, packet_size, pseudo_header,
header);
return TRUE;
}
static int
iptrace_read_rec_header(FILE_T fh, guint8 *header, int header_len, int *err,
gchar **err_info)
{
int bytes_read;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(header, header_len, fh);
if (bytes_read != header_len) {
*err = file_error(fh, err_info);
if (*err != 0)
return -1;
if (bytes_read != 0) {
*err = WTAP_ERR_SHORT_READ;
return -1;
}
return 0;
}
return 1;
}
static gboolean
iptrace_read_rec_data(FILE_T fh, guint8 *data_ptr, int packet_size, int *err,
gchar **err_info)
{
int bytes_read;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read( data_ptr, packet_size, fh );
if (bytes_read != packet_size) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static void
fill_in_pseudo_header(int encap, const guint8 *pd, guint32 len,
union wtap_pseudo_header *pseudo_header, guint8 *header)
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
atm_guess_traffic_type(pd, len, pseudo_header);
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
return WTAP_ENCAP_UNKNOWN;
}
}
