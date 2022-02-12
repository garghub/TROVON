static int esc_read(guint8 *buf, int len, FILE_T fh)
{
int i;
int value;
for(i=0; i<len; i++) {
value=file_getc(fh);
if(value==-1)
return -2;
if(value==0xff)
return -1;
if(value==0xfe) {
value=file_getc(fh);
if(value==-1)
return -2;
value+=2;
}
buf[i]=value;
}
return i;
}
static gint64 eyesdn_seek_next_packet(wtap *wth, int *err, gchar **err_info)
{
int byte;
gint64 cur_off;
while ((byte = file_getc(wth->fh)) != EOF) {
if (byte == 0xff) {
cur_off = file_tell(wth->fh);
if (cur_off == -1) {
*err = file_error(wth->fh, err_info);
return -1;
}
return cur_off;
}
}
*err = file_error(wth->fh, err_info);
return -1;
}
int eyesdn_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
char magic[EYESDN_HDR_MAGIC_SIZE];
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&magic, sizeof magic, wth->fh);
if (bytes_read != sizeof magic) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if (memcmp(magic, eyesdn_hdr_magic, EYESDN_HDR_MAGIC_SIZE) != 0)
return 0;
wth->file_encap = WTAP_ENCAP_PER_PACKET;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_EYESDN;
wth->snapshot_length = 0;
wth->subtype_read = eyesdn_read;
wth->subtype_seek_read = eyesdn_seek_read;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
return 1;
}
static gboolean eyesdn_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
gint64 offset;
offset = eyesdn_seek_next_packet(wth, err, err_info);
if (offset < 1)
return FALSE;
*data_offset = offset;
return read_eyesdn_rec(wth->fh, &wth->phdr, wth->frame_buffer,
err, err_info);
}
static gboolean
eyesdn_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
return read_eyesdn_rec(wth->random_fh, phdr, buf, err, err_info);
}
static gboolean
read_eyesdn_rec(FILE_T fh, struct wtap_pkthdr *phdr, Buffer *buf, int *err,
gchar **err_info)
{
union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
guint8 hdr[EYESDN_HDR_LENGTH];
time_t secs;
int usecs;
int pkt_len;
guint8 channel, direction;
int bytes_read;
guint8 *pd;
if (esc_read(hdr, EYESDN_HDR_LENGTH, fh) != EYESDN_HDR_LENGTH) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
usecs = pntoh24(&hdr[0]);
#ifdef TV64BITS
secs = hdr[3];
#else
secs = 0;
#endif
secs = (secs << 8) | hdr[4];
secs = (secs << 8) | hdr[5];
secs = (secs << 8) | hdr[6];
secs = (secs << 8) | hdr[7];
channel = hdr[8];
direction = hdr[9];
pkt_len = pntoh16(&hdr[10]);
switch(direction >> 1) {
default:
case EYESDN_ENCAP_ISDN:
pseudo_header->isdn.uton = direction & 1;
pseudo_header->isdn.channel = channel;
if(channel) {
phdr->pkt_encap = WTAP_ENCAP_ISDN;
pseudo_header->isdn.uton=!pseudo_header->isdn.uton;
} else {
phdr->pkt_encap = WTAP_ENCAP_ISDN;
}
break;
case EYESDN_ENCAP_MSG:
phdr->pkt_encap = WTAP_ENCAP_LAYER1_EVENT;
pseudo_header->l1event.uton = (direction & 1);
break;
case EYESDN_ENCAP_LAPB:
phdr->pkt_encap = WTAP_ENCAP_LAPB;
pseudo_header->x25.flags = (direction & 1) ? 0 : 0x80;
break;
case EYESDN_ENCAP_ATM: {
#define CELL_LEN 53
unsigned char cell[CELL_LEN];
gint64 cur_off;
if(pkt_len != CELL_LEN) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf(
"eyesdn: ATM cell has a length != 53 (%u)",
pkt_len);
return FALSE;
}
cur_off = file_tell(fh);
if (esc_read(cell, CELL_LEN, fh) != CELL_LEN) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
if (file_seek(fh, cur_off, SEEK_SET, err) == -1)
return FALSE;
phdr->pkt_encap = WTAP_ENCAP_ATM_PDUS_UNTRUNCATED;
pseudo_header->atm.flags=ATM_RAW_CELL;
pseudo_header->atm.aal=AAL_UNKNOWN;
pseudo_header->atm.type=TRAF_UMTS_FP;
pseudo_header->atm.subtype=TRAF_ST_UNKNOWN;
pseudo_header->atm.vpi=((cell[0]&0xf)<<4) + (cell[0]&0xf);
pseudo_header->atm.vci=((cell[0]&0xf)<<4) + cell[0];
pseudo_header->atm.channel=direction & 1;
}
break;
case EYESDN_ENCAP_MTP2:
pseudo_header->mtp2.sent = direction & 1;
pseudo_header->mtp2.annex_a_used = MTP2_ANNEX_A_USED_UNKNOWN;
pseudo_header->mtp2.link_number = channel;
phdr->pkt_encap = WTAP_ENCAP_MTP2_WITH_PHDR;
break;
case EYESDN_ENCAP_DPNSS:
pseudo_header->isdn.uton = direction & 1;
pseudo_header->isdn.channel = channel;
phdr->pkt_encap = WTAP_ENCAP_DPNSS;
break;
case EYESDN_ENCAP_DASS2:
pseudo_header->isdn.uton = direction & 1;
pseudo_header->isdn.channel = channel;
phdr->pkt_encap = WTAP_ENCAP_DPNSS;
break;
case EYESDN_ENCAP_BACNET:
pseudo_header->isdn.uton = direction & 1;
pseudo_header->isdn.channel = channel;
phdr->pkt_encap = WTAP_ENCAP_BACNET_MS_TP_WITH_PHDR;
break;
case EYESDN_ENCAP_V5_EF:
pseudo_header->isdn.uton = direction & 1;
pseudo_header->isdn.channel = channel;
phdr->pkt_encap = WTAP_ENCAP_V5_EF;
break;
}
if(pkt_len > EYESDN_MAX_PACKET_LEN) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("eyesdn: File has %u-byte packet, bigger than maximum of %u",
pkt_len, EYESDN_MAX_PACKET_LEN);
return FALSE;
}
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
phdr->ts.secs = secs;
phdr->ts.nsecs = usecs * 1000;
phdr->caplen = pkt_len;
phdr->len = pkt_len;
buffer_assure_space(buf, EYESDN_MAX_PACKET_LEN);
errno = WTAP_ERR_CANT_READ;
pd = buffer_start_ptr(buf);
bytes_read = esc_read(pd, pkt_len, fh);
if (bytes_read != pkt_len) {
if (bytes_read == -2) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
} else if (bytes_read == -1) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("eyesdn: No flag character seen in frame");
} else
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static gboolean
esc_write(wtap_dumper *wdh, const guint8 *buf, int len, int *err)
{
int i;
guint8 byte;
static const guint8 esc = 0xfe;
for(i=0; i<len; i++) {
byte=buf[i];
if(byte == 0xff || byte == 0xfe) {
if (!wtap_dump_file_write(wdh, &esc, sizeof esc, err))
return FALSE;
byte-=2;
}
if (!wtap_dump_file_write(wdh, &byte, sizeof byte, err))
return FALSE;
}
return TRUE;
}
gboolean eyesdn_dump_open(wtap_dumper *wdh, int *err)
{
wdh->subtype_write=eyesdn_dump;
wdh->subtype_close=NULL;
if (!wtap_dump_file_write(wdh, eyesdn_hdr_magic,
EYESDN_HDR_MAGIC_SIZE, err))
return FALSE;
wdh->bytes_dumped += EYESDN_HDR_MAGIC_SIZE;
*err=0;
return TRUE;
}
int eyesdn_dump_can_write_encap(int encap)
{
switch (encap) {
case WTAP_ENCAP_ISDN:
case WTAP_ENCAP_LAYER1_EVENT:
case WTAP_ENCAP_DPNSS:
case WTAP_ENCAP_ATM_PDUS_UNTRUNCATED:
case WTAP_ENCAP_LAPB:
case WTAP_ENCAP_MTP2_WITH_PHDR:
case WTAP_ENCAP_BACNET_MS_TP_WITH_PHDR:
case WTAP_ENCAP_PER_PACKET:
return 0;
default:
return WTAP_ERR_UNSUPPORTED_ENCAP;
}
}
static gboolean eyesdn_dump(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err)
{
static const guint8 start_flag = 0xff;
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
guint8 buf[EYESDN_HDR_LENGTH];
int usecs;
time_t secs;
int channel;
int origin;
int protocol;
int size;
if (phdr->rec_type != REC_TYPE_PACKET) {
*err = WTAP_ERR_REC_TYPE_UNSUPPORTED;
return FALSE;
}
if (phdr->caplen > 65535) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
usecs=phdr->ts.nsecs/1000;
secs=phdr->ts.secs;
size=phdr->caplen;
origin = pseudo_header->isdn.uton;
channel = pseudo_header->isdn.channel;
switch(phdr->pkt_encap) {
case WTAP_ENCAP_ISDN:
protocol=EYESDN_ENCAP_ISDN;
break;
case WTAP_ENCAP_LAYER1_EVENT:
protocol=EYESDN_ENCAP_MSG;
break;
case WTAP_ENCAP_DPNSS:
protocol=EYESDN_ENCAP_DPNSS;
break;
#if 0
case WTAP_ENCAP_DASS2:
protocol=EYESDN_ENCAP_DASS2;
break;
#endif
case WTAP_ENCAP_ATM_PDUS_UNTRUNCATED:
protocol=EYESDN_ENCAP_ATM;
channel=0x80;
break;
case WTAP_ENCAP_LAPB:
protocol=EYESDN_ENCAP_LAPB;
break;
case WTAP_ENCAP_MTP2_WITH_PHDR:
protocol=EYESDN_ENCAP_MTP2;
break;
case WTAP_ENCAP_BACNET_MS_TP_WITH_PHDR:
protocol=EYESDN_ENCAP_BACNET;
break;
case WTAP_ENCAP_V5_EF:
protocol=EYESDN_ENCAP_V5_EF;
break;
default:
*err=WTAP_ERR_UNSUPPORTED_ENCAP;
return FALSE;
}
phton24(&buf[0], usecs);
buf[3] = (guint8)0;
buf[4] = (guint8)(0xff & (secs >> 24));
buf[5] = (guint8)(0xff & (secs >> 16));
buf[6] = (guint8)(0xff & (secs >> 8));
buf[7] = (guint8)(0xff & (secs >> 0));
buf[8] = (guint8) channel;
buf[9] = (guint8) (origin?1:0) + (protocol << 1);
phtons(&buf[10], size);
if (!wtap_dump_file_write(wdh, &start_flag, sizeof start_flag, err))
return FALSE;
if (!esc_write(wdh, buf, 12, err))
return FALSE;
if (!esc_write(wdh, pd, size, err))
return FALSE;
return TRUE;
}
