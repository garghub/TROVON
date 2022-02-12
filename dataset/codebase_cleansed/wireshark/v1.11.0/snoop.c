int snoop_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
char magic[sizeof snoop_magic];
struct snoop_hdr hdr;
struct snooprec_hdr rec_hdr;
guint padbytes;
gboolean is_shomiti;
static const int snoop_encap[] = {
WTAP_ENCAP_ETHERNET,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_TOKEN_RING,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_ETHERNET,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_FDDI_BITSWAPPED,
WTAP_ENCAP_NULL,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_NULL,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_IP_OVER_FC,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_ATM_PDUS,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_IP_OVER_IB,
};
#define NUM_SNOOP_ENCAPS (sizeof snoop_encap / sizeof snoop_encap[0])
#define SNOOP_PRIVATE_BIT 0x80000000
static const int snoop_private_encap[] = {
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_IPNET,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
};
#define NUM_SNOOP_PRIVATE_ENCAPS (sizeof snoop_private_encap / sizeof snoop_private_encap[0])
static const int shomiti_encap[] = {
WTAP_ENCAP_ETHERNET,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_TOKEN_RING,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_ETHERNET,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_FDDI_BITSWAPPED,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_ETHERNET,
WTAP_ENCAP_TOKEN_RING,
WTAP_ENCAP_ETHERNET,
WTAP_ENCAP_TOKEN_RING,
WTAP_ENCAP_TOKEN_RING,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_IEEE_802_11_WITH_RADIO,
WTAP_ENCAP_ETHERNET,
};
#define NUM_SHOMITI_ENCAPS (sizeof shomiti_encap / sizeof shomiti_encap[0])
int file_encap;
gint64 saved_offset;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(magic, sizeof magic, wth->fh);
if (bytes_read != sizeof magic) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if (memcmp(magic, snoop_magic, sizeof snoop_magic) != 0) {
return 0;
}
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&hdr, sizeof hdr, wth->fh);
if (bytes_read != sizeof hdr) {
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return -1;
}
hdr.version = g_ntohl(hdr.version);
switch (hdr.version) {
case 2:
case 3:
case 4:
case 5:
break;
default:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("snoop: version %u unsupported", hdr.version);
return -1;
}
is_shomiti = FALSE;
saved_offset = file_tell(wth->fh);
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&rec_hdr, sizeof rec_hdr, wth->fh);
if (bytes_read != sizeof rec_hdr) {
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return -1;
} else {
if (g_ntohl(rec_hdr.rec_len) >
(sizeof rec_hdr + g_ntohl(rec_hdr.incl_len))) {
padbytes = g_ntohl(rec_hdr.rec_len) -
((guint)sizeof rec_hdr + g_ntohl(rec_hdr.incl_len));
is_shomiti =
(padbytes >= sizeof (struct shomiti_trailer));
}
}
if (file_seek(wth->fh, saved_offset, SEEK_SET, err) == -1)
return -1;
hdr.network = g_ntohl(hdr.network);
if (is_shomiti) {
if (hdr.network >= NUM_SHOMITI_ENCAPS
|| shomiti_encap[hdr.network] == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("snoop: Shomiti network type %u unknown or unsupported",
hdr.network);
return -1;
}
file_encap = shomiti_encap[hdr.network];
wth->file_type = WTAP_FILE_SHOMITI;
} else if (hdr.network & SNOOP_PRIVATE_BIT) {
if ((hdr.network^SNOOP_PRIVATE_BIT) >= NUM_SNOOP_PRIVATE_ENCAPS
|| snoop_private_encap[hdr.network^SNOOP_PRIVATE_BIT] == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("snoop: private network type %u unknown or unsupported",
hdr.network);
return -1;
}
file_encap = snoop_private_encap[hdr.network^SNOOP_PRIVATE_BIT];
wth->file_type = WTAP_FILE_SNOOP;
} else {
if (hdr.network >= NUM_SNOOP_ENCAPS
|| snoop_encap[hdr.network] == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("snoop: network type %u unknown or unsupported",
hdr.network);
return -1;
}
file_encap = snoop_encap[hdr.network];
wth->file_type = WTAP_FILE_SNOOP;
}
wth->subtype_read = snoop_read;
wth->subtype_seek_read = snoop_seek_read;
wth->file_encap = file_encap;
wth->snapshot_length = 0;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
return 1;
}
static gboolean snoop_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
int padbytes;
int bytes_read;
char padbuf[4];
int bytes_to_read;
*data_offset = file_tell(wth->fh);
padbytes = snoop_read_packet(wth, wth->fh, &wth->phdr,
wth->frame_buffer, err, err_info);
if (padbytes == -1)
return FALSE;
while (padbytes != 0) {
bytes_to_read = padbytes;
if ((unsigned)bytes_to_read > sizeof padbuf)
bytes_to_read = sizeof padbuf;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(padbuf, bytes_to_read, wth->fh);
if (bytes_read != bytes_to_read) {
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
padbytes -= bytes_read;
}
return TRUE;
}
static gboolean
snoop_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int length _U_,
int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (snoop_read_packet(wth, wth->random_fh, phdr, buf, err, err_info) == -1) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static int
snoop_read_packet(wtap *wth, FILE_T fh, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
struct snooprec_hdr hdr;
int bytes_read;
guint32 rec_size;
guint32 packet_size;
guint32 orig_size;
int header_size;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&hdr, sizeof hdr, fh);
if (bytes_read != sizeof hdr) {
*err = file_error(fh, err_info);
if (*err == 0 && bytes_read != 0)
*err = WTAP_ERR_SHORT_READ;
return -1;
}
rec_size = g_ntohl(hdr.rec_len);
orig_size = g_ntohl(hdr.orig_len);
packet_size = g_ntohl(hdr.incl_len);
if (orig_size > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("snoop: File has %u-byte original length, bigger than maximum of %u",
orig_size, WTAP_MAX_PACKET_SIZE);
return -1;
}
if (packet_size > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("snoop: File has %u-byte packet, bigger than maximum of %u",
packet_size, WTAP_MAX_PACKET_SIZE);
return -1;
}
if (packet_size > rec_size) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("snoop: File has %u-byte packet, bigger than record size %u",
packet_size, rec_size);
return -1;
}
switch (wth->file_encap) {
case WTAP_ENCAP_ATM_PDUS:
if (packet_size < sizeof (struct snoop_atm_hdr)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("snoop: atmsnoop file has a %u-byte packet, too small to have even an ATM pseudo-header",
packet_size);
return -1;
}
if (!snoop_read_atm_pseudoheader(fh, &phdr->pseudo_header,
err, err_info))
return -1;
rec_size -= (guint32)sizeof (struct snoop_atm_hdr);
orig_size -= (guint32)sizeof (struct snoop_atm_hdr);
packet_size -= (guint32)sizeof (struct snoop_atm_hdr);
break;
case WTAP_ENCAP_ETHERNET:
if (wth->file_type == WTAP_FILE_SHOMITI)
phdr->pseudo_header.eth.fcs_len = 4;
else
phdr->pseudo_header.eth.fcs_len = 0;
break;
case WTAP_ENCAP_IEEE_802_11_WITH_RADIO:
if (packet_size < sizeof (shomiti_wireless_header)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("snoop: Shomiti wireless file has a %u-byte packet, too small to have even a wireless pseudo-header",
packet_size);
return -1;
}
if (!snoop_read_shomiti_wireless_pseudoheader(fh,
&phdr->pseudo_header, err, err_info, &header_size))
return -1;
rec_size -= header_size;
orig_size -= header_size;
packet_size -= header_size;
break;
}
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
phdr->ts.secs = g_ntohl(hdr.ts_sec);
phdr->ts.nsecs = g_ntohl(hdr.ts_usec) * 1000;
phdr->caplen = packet_size;
phdr->len = orig_size;
if (rec_size < (sizeof hdr + packet_size)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("snoop: File has %u-byte record with packet size of %u",
rec_size, packet_size);
return -1;
}
if (!wtap_read_packet_bytes(fh, buf, packet_size, err, err_info))
return -1;
if (wth->file_encap == WTAP_ENCAP_ATM_PDUS &&
phdr->pseudo_header.atm.type == TRAF_LANE) {
atm_guess_lane_type(buffer_start_ptr(buf), packet_size,
&phdr->pseudo_header);
}
return rec_size - ((guint)sizeof hdr + packet_size);
}
static gboolean
snoop_read_atm_pseudoheader(FILE_T fh, union wtap_pseudo_header *pseudo_header,
int *err, gchar **err_info)
{
struct snoop_atm_hdr atm_phdr;
int bytes_read;
guint8 vpi;
guint16 vci;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&atm_phdr, sizeof (struct snoop_atm_hdr), fh);
if (bytes_read != sizeof (struct snoop_atm_hdr)) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
vpi = atm_phdr.vpi;
vci = pntohs(&atm_phdr.vci);
switch (atm_phdr.flags & 0x0F) {
case 0x01:
pseudo_header->atm.aal = AAL_5;
pseudo_header->atm.type = TRAF_LANE;
break;
case 0x02:
pseudo_header->atm.aal = AAL_5;
pseudo_header->atm.type = TRAF_LLCMX;
break;
case 0x05:
pseudo_header->atm.aal = AAL_5;
pseudo_header->atm.type = TRAF_ILMI;
break;
case 0x06:
pseudo_header->atm.aal = AAL_SIGNALLING;
pseudo_header->atm.type = TRAF_UNKNOWN;
break;
case 0x03:
pseudo_header->atm.aal = AAL_5;
pseudo_header->atm.type = TRAF_UNKNOWN;
break;
case 0x04:
pseudo_header->atm.aal = AAL_5;
pseudo_header->atm.type = TRAF_UNKNOWN;
break;
default:
if (vpi == 0 && vci == 5)
pseudo_header->atm.aal = AAL_SIGNALLING;
else
pseudo_header->atm.aal = AAL_5;
pseudo_header->atm.type = TRAF_UNKNOWN;
break;
}
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
pseudo_header->atm.vpi = vpi;
pseudo_header->atm.vci = vci;
pseudo_header->atm.channel = (atm_phdr.flags & 0x80) ? 0 : 1;
pseudo_header->atm.flags = 0;
pseudo_header->atm.cells = 0;
pseudo_header->atm.aal5t_u2u = 0;
pseudo_header->atm.aal5t_len = 0;
pseudo_header->atm.aal5t_chksum = 0;
return TRUE;
}
static gboolean
snoop_read_shomiti_wireless_pseudoheader(FILE_T fh,
union wtap_pseudo_header *pseudo_header, int *err, gchar **err_info,
int *header_size)
{
shomiti_wireless_header whdr;
int bytes_read;
int rsize;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&whdr, sizeof (shomiti_wireless_header), fh);
if (bytes_read != sizeof (shomiti_wireless_header)) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
if (whdr.pad[3] < 8) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("snoop: Header length in Surveyor record is %u, less than minimum of 8",
whdr.pad[3]);
return FALSE;
}
rsize = ((int) whdr.pad[3]) - 8;
if (file_seek(fh, rsize, SEEK_CUR, err) == -1)
return FALSE;
pseudo_header->ieee_802_11.fcs_len = 4;
pseudo_header->ieee_802_11.channel = whdr.channel;
pseudo_header->ieee_802_11.data_rate = whdr.rate;
pseudo_header->ieee_802_11.signal_level = whdr.signal;
*header_size = rsize + 8 + 4;
return TRUE;
}
int snoop_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_PER_PACKET)
return WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED;
if (encap < 0 || (unsigned)encap >= NUM_WTAP_ENCAPS || wtap_encap[encap] == -1)
return WTAP_ERR_UNSUPPORTED_ENCAP;
return 0;
}
gboolean snoop_dump_open(wtap_dumper *wdh, int *err)
{
struct snoop_hdr file_hdr;
wdh->subtype_write = snoop_dump;
wdh->subtype_close = NULL;
if (!wtap_dump_file_write(wdh, &snoop_magic, sizeof snoop_magic, err))
return FALSE;
file_hdr.version = g_htonl(2);
file_hdr.network = g_htonl(wtap_encap[wdh->encap]);
if (!wtap_dump_file_write(wdh, &file_hdr, sizeof file_hdr, err))
return FALSE;
return TRUE;
}
static gboolean snoop_dump(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err)
{
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
struct snooprec_hdr rec_hdr;
int reclen;
guint padlen;
static const char zeroes[4] = {0};
struct snoop_atm_hdr atm_hdr;
int atm_hdrsize;
if (wdh->encap == WTAP_ENCAP_ATM_PDUS)
atm_hdrsize = sizeof (struct snoop_atm_hdr);
else
atm_hdrsize = 0;
reclen = (int)sizeof rec_hdr + phdr->caplen + atm_hdrsize;
padlen = ((reclen + 3) & ~3) - reclen;
reclen += padlen;
rec_hdr.orig_len = g_htonl(phdr->len + atm_hdrsize);
rec_hdr.incl_len = g_htonl(phdr->caplen + atm_hdrsize);
rec_hdr.rec_len = g_htonl(reclen);
rec_hdr.cum_drops = 0;
rec_hdr.ts_sec = g_htonl(phdr->ts.secs);
rec_hdr.ts_usec = g_htonl(phdr->ts.nsecs / 1000);
if (!wtap_dump_file_write(wdh, &rec_hdr, sizeof rec_hdr, err))
return FALSE;
if (wdh->encap == WTAP_ENCAP_ATM_PDUS) {
atm_hdr.flags =
(pseudo_header->atm.channel == 0) ? 0x80 : 0x00;
switch (pseudo_header->atm.aal) {
case AAL_SIGNALLING:
atm_hdr.flags |= 0x06;
break;
case AAL_5:
switch (pseudo_header->atm.type) {
case TRAF_LANE:
atm_hdr.flags |= 0x01;
break;
case TRAF_LLCMX:
atm_hdr.flags |= 0x02;
break;
case TRAF_ILMI:
atm_hdr.flags |= 0x05;
break;
}
break;
}
atm_hdr.vpi = (guint8) pseudo_header->atm.vpi;
atm_hdr.vci = g_htons(pseudo_header->atm.vci);
if (!wtap_dump_file_write(wdh, &atm_hdr, sizeof atm_hdr, err))
return FALSE;
}
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
if (!wtap_dump_file_write(wdh, zeroes, padlen, err))
return FALSE;
return TRUE;
}
