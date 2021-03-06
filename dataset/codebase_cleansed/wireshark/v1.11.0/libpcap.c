int libpcap_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
guint32 magic;
struct pcap_hdr hdr;
gboolean byte_swapped;
gboolean modified;
gboolean aix;
int file_encap;
gint64 first_packet_offset;
libpcap_t *libpcap;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&magic, sizeof magic, wth->fh);
if (bytes_read != sizeof magic) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
switch (magic) {
case PCAP_MAGIC:
byte_swapped = FALSE;
modified = FALSE;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
break;
case PCAP_MODIFIED_MAGIC:
byte_swapped = FALSE;
modified = TRUE;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
break;
case PCAP_SWAPPED_MAGIC:
byte_swapped = TRUE;
modified = FALSE;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
break;
case PCAP_SWAPPED_MODIFIED_MAGIC:
byte_swapped = TRUE;
modified = TRUE;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
break;
case PCAP_NSEC_MAGIC:
byte_swapped = FALSE;
modified = FALSE;
wth->tsprecision = WTAP_FILE_TSPREC_NSEC;
break;
case PCAP_SWAPPED_NSEC_MAGIC:
byte_swapped = TRUE;
modified = FALSE;
wth->tsprecision = WTAP_FILE_TSPREC_NSEC;
break;
default:
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
if (byte_swapped) {
hdr.version_major = BSWAP16(hdr.version_major);
hdr.version_minor = BSWAP16(hdr.version_minor);
hdr.snaplen = BSWAP32(hdr.snaplen);
hdr.network = BSWAP32(hdr.network);
}
if (hdr.version_major < 2) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("pcap: major version %u unsupported",
hdr.version_major);
return -1;
}
aix = FALSE;
if (hdr.version_major == 2 && hdr.version_minor == 2) {
switch (hdr.network) {
case 6:
hdr.network = 1;
aix = TRUE;
break;
case 9:
hdr.network = 6;
aix = TRUE;
break;
case 15:
hdr.network = 10;
aix = TRUE;
break;
case 24:
hdr.network = 0;
aix = TRUE;
break;
}
}
file_encap = wtap_pcap_encap_to_wtap_encap(hdr.network);
if (file_encap == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("pcap: network type %u unknown or unsupported",
hdr.network);
return -1;
}
libpcap = (libpcap_t *)g_malloc(sizeof(libpcap_t));
libpcap->byte_swapped = byte_swapped;
libpcap->version_major = hdr.version_major;
libpcap->version_minor = hdr.version_minor;
wth->priv = (void *)libpcap;
wth->subtype_read = libpcap_read;
wth->subtype_seek_read = libpcap_seek_read;
wth->file_encap = file_encap;
wth->snapshot_length = hdr.snaplen;
switch (hdr.version_major) {
case 2:
if (hdr.version_minor < 3)
libpcap->lengths_swapped = SWAPPED;
else if (hdr.version_minor == 3)
libpcap->lengths_swapped = MAYBE_SWAPPED;
else
libpcap->lengths_swapped = NOT_SWAPPED;
break;
case 543:
libpcap->lengths_swapped = SWAPPED;
break;
default:
libpcap->lengths_swapped = NOT_SWAPPED;
break;
}
if (aix) {
wth->file_type = WTAP_FILE_PCAP_AIX;
wth->tsprecision = WTAP_FILE_TSPREC_NSEC;
return 1;
}
if (modified) {
wth->file_type = WTAP_FILE_PCAP_SS991029;
first_packet_offset = file_tell(wth->fh);
switch (libpcap_try(wth, err)) {
case BAD_READ:
return -1;
case THIS_FORMAT:
if (file_seek(wth->fh, first_packet_offset, SEEK_SET, err) == -1) {
return -1;
}
goto done;
case OTHER_FORMAT:
break;
}
wth->file_type = WTAP_FILE_PCAP_SS990915;
if (file_seek(wth->fh, first_packet_offset, SEEK_SET, err) == -1) {
return -1;
}
} else {
if(wth->tsprecision == WTAP_FILE_TSPREC_NSEC) {
wth->file_type = WTAP_FILE_PCAP_NSEC;
} else {
wth->file_type = WTAP_FILE_PCAP;
}
first_packet_offset = file_tell(wth->fh);
switch (libpcap_try(wth, err)) {
case BAD_READ:
return -1;
case THIS_FORMAT:
if (file_seek(wth->fh, first_packet_offset, SEEK_SET, err) == -1) {
return -1;
}
goto done;
case OTHER_FORMAT:
break;
}
wth->file_type = WTAP_FILE_PCAP_SS990417;
if (file_seek(wth->fh, first_packet_offset, SEEK_SET, err) == -1) {
return -1;
}
switch (libpcap_try(wth, err)) {
case BAD_READ:
return -1;
case THIS_FORMAT:
if (file_seek(wth->fh, first_packet_offset, SEEK_SET, err) == -1) {
return -1;
}
goto done;
case OTHER_FORMAT:
break;
}
wth->file_type = WTAP_FILE_PCAP_NOKIA;
if (file_seek(wth->fh, first_packet_offset, SEEK_SET, err) == -1) {
return -1;
}
}
done:
if (wth->file_type == WTAP_FILE_PCAP_NOKIA && hdr.network == 13)
wth->file_encap = WTAP_ENCAP_ATM_PDUS;
if (wth->file_encap == WTAP_ENCAP_ERF) {
erf_populate_interfaces(wth);
}
return 1;
}
static libpcap_try_t libpcap_try(wtap *wth, int *err)
{
struct pcaprec_ss990915_hdr first_rec_hdr, second_rec_hdr;
if (libpcap_read_header(wth, wth->fh, err, NULL, &first_rec_hdr) == -1) {
if (*err == 0 || *err == WTAP_ERR_SHORT_READ) {
return THIS_FORMAT;
}
if (*err == WTAP_ERR_BAD_FILE) {
return THIS_FORMAT;
}
return BAD_READ;
}
if (file_seek(wth->fh, first_rec_hdr.hdr.incl_len, SEEK_CUR, err) == -1)
return BAD_READ;
if (libpcap_read_header(wth, wth->fh, err, NULL, &second_rec_hdr) == -1) {
if (*err == 0 || *err == WTAP_ERR_SHORT_READ) {
return THIS_FORMAT;
}
if (*err == WTAP_ERR_BAD_FILE) {
return OTHER_FORMAT;
}
return BAD_READ;
}
return THIS_FORMAT;
}
static gboolean libpcap_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
*data_offset = file_tell(wth->fh);
return libpcap_read_packet(wth, wth->fh, &wth->phdr,
wth->frame_buffer, err, err_info);
}
static gboolean
libpcap_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr,
Buffer *buf, int length _U_, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!libpcap_read_packet(wth, wth->random_fh, phdr, buf, err,
err_info)) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static gboolean
libpcap_read_packet(wtap *wth, FILE_T fh, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
struct pcaprec_ss990915_hdr hdr;
guint packet_size;
guint orig_size;
int bytes_read;
int phdr_len;
libpcap_t *libpcap;
bytes_read = libpcap_read_header(wth, fh, err, err_info, &hdr);
if (bytes_read == -1) {
return FALSE;
}
packet_size = hdr.hdr.incl_len;
orig_size = hdr.hdr.orig_len;
if (wth->file_type == WTAP_FILE_PCAP_AIX &&
(wth->file_encap == WTAP_ENCAP_FDDI ||
wth->file_encap == WTAP_ENCAP_FDDI_BITSWAPPED)) {
packet_size -= 3;
orig_size -= 3;
if (!file_skip(fh, 3, err))
return FALSE;
}
phdr_len = pcap_process_pseudo_header(fh, wth->file_type,
wth->file_encap, packet_size, TRUE, phdr, err, err_info);
if (phdr_len < 0)
return FALSE;
orig_size -= phdr_len;
packet_size -= phdr_len;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
if (wth->file_encap != WTAP_ENCAP_ERF) {
phdr->ts.secs = hdr.hdr.ts_sec;
if (wth->tsprecision == WTAP_FILE_TSPREC_NSEC)
phdr->ts.nsecs = hdr.hdr.ts_usec;
else
phdr->ts.nsecs = hdr.hdr.ts_usec * 1000;
} else {
phdr->presence_flags |= WTAP_HAS_INTERFACE_ID;
phdr->interface_id = phdr->pseudo_header.erf.phdr.flags & 0x03;
}
phdr->caplen = packet_size;
phdr->len = orig_size;
if (!wtap_read_packet_bytes(fh, buf, packet_size, err, err_info))
return FALSE;
libpcap = (libpcap_t *)wth->priv;
pcap_read_post_process(wth->file_type, wth->file_encap,
&phdr->pseudo_header, buffer_start_ptr(buf), packet_size,
libpcap->byte_swapped, -1);
return TRUE;
}
static int libpcap_read_header(wtap *wth, FILE_T fh, int *err, gchar **err_info,
struct pcaprec_ss990915_hdr *hdr)
{
int bytes_to_read, bytes_read;
errno = WTAP_ERR_CANT_READ;
switch (wth->file_type) {
case WTAP_FILE_PCAP:
case WTAP_FILE_PCAP_AIX:
case WTAP_FILE_PCAP_NSEC:
bytes_to_read = sizeof (struct pcaprec_hdr);
break;
case WTAP_FILE_PCAP_SS990417:
case WTAP_FILE_PCAP_SS991029:
bytes_to_read = sizeof (struct pcaprec_modified_hdr);
break;
case WTAP_FILE_PCAP_SS990915:
bytes_to_read = sizeof (struct pcaprec_ss990915_hdr);
break;
case WTAP_FILE_PCAP_NOKIA:
bytes_to_read = sizeof (struct pcaprec_nokia_hdr);
break;
default:
g_assert_not_reached();
bytes_to_read = 0;
}
bytes_read = file_read(hdr, bytes_to_read, fh);
if (bytes_read != bytes_to_read) {
*err = file_error(fh, err_info);
if (*err == 0 && bytes_read != 0) {
*err = WTAP_ERR_SHORT_READ;
}
return -1;
}
adjust_header(wth, &hdr->hdr);
if (hdr->hdr.incl_len > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
if (err_info != NULL) {
*err_info = g_strdup_printf("pcap: File has %u-byte packet, bigger than maximum of %u",
hdr->hdr.incl_len, WTAP_MAX_PACKET_SIZE);
}
return -1;
}
#if 0
if (hdr->hdr.incl_len > wth->snapshot_length) {
g_warning("pcap: File has packet larger than file's snapshot length.");
}
#endif
return bytes_read;
}
static void
adjust_header(wtap *wth, struct pcaprec_hdr *hdr)
{
guint32 temp;
libpcap_t *libpcap;
libpcap = (libpcap_t *)wth->priv;
if (libpcap->byte_swapped) {
hdr->ts_sec = BSWAP32(hdr->ts_sec);
hdr->ts_usec = BSWAP32(hdr->ts_usec);
hdr->incl_len = BSWAP32(hdr->incl_len);
hdr->orig_len = BSWAP32(hdr->orig_len);
}
switch (libpcap->lengths_swapped) {
case NOT_SWAPPED:
break;
case MAYBE_SWAPPED:
if (hdr->incl_len <= hdr->orig_len) {
break;
}
case SWAPPED:
temp = hdr->orig_len;
hdr->orig_len = hdr->incl_len;
hdr->incl_len = temp;
break;
}
}
int libpcap_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_PER_PACKET)
return WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED;
if (wtap_wtap_encap_to_pcap_encap(encap) == -1)
return WTAP_ERR_UNSUPPORTED_ENCAP;
return 0;
}
gboolean libpcap_dump_open(wtap_dumper *wdh, int *err)
{
guint32 magic;
struct pcap_hdr file_hdr;
wdh->subtype_write = libpcap_dump;
wdh->subtype_close = NULL;
switch (wdh->file_type) {
case WTAP_FILE_PCAP:
case WTAP_FILE_PCAP_SS990417:
case WTAP_FILE_PCAP_NOKIA:
magic = PCAP_MAGIC;
wdh->tsprecision = WTAP_FILE_TSPREC_USEC;
break;
case WTAP_FILE_PCAP_SS990915:
case WTAP_FILE_PCAP_SS991029:
magic = PCAP_MODIFIED_MAGIC;
wdh->tsprecision = WTAP_FILE_TSPREC_USEC;
break;
case WTAP_FILE_PCAP_NSEC:
magic = PCAP_NSEC_MAGIC;
wdh->tsprecision = WTAP_FILE_TSPREC_NSEC;
break;
default:
*err = WTAP_ERR_UNSUPPORTED_FILE_TYPE;
return FALSE;
}
if (!wtap_dump_file_write(wdh, &magic, sizeof magic, err))
return FALSE;
wdh->bytes_dumped += sizeof magic;
file_hdr.version_major = 2;
file_hdr.version_minor = 4;
file_hdr.thiszone = 0;
file_hdr.sigfigs = 0;
file_hdr.snaplen = (wdh->snaplen != 0) ? wdh->snaplen :
WTAP_MAX_PACKET_SIZE;
file_hdr.network = wtap_wtap_encap_to_pcap_encap(wdh->encap);
if (!wtap_dump_file_write(wdh, &file_hdr, sizeof file_hdr, err))
return FALSE;
wdh->bytes_dumped += sizeof file_hdr;
return TRUE;
}
static gboolean libpcap_dump(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err)
{
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
struct pcaprec_ss990915_hdr rec_hdr;
size_t hdr_size;
int phdrsize;
phdrsize = pcap_get_phdr_size(wdh->encap, pseudo_header);
rec_hdr.hdr.ts_sec = (guint32) phdr->ts.secs;
if(wdh->tsprecision == WTAP_FILE_TSPREC_NSEC) {
rec_hdr.hdr.ts_usec = phdr->ts.nsecs;
} else {
rec_hdr.hdr.ts_usec = phdr->ts.nsecs / 1000;
}
rec_hdr.hdr.incl_len = phdr->caplen + phdrsize;
rec_hdr.hdr.orig_len = phdr->len + phdrsize;
if (rec_hdr.hdr.incl_len > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
switch (wdh->file_type) {
case WTAP_FILE_PCAP:
case WTAP_FILE_PCAP_NSEC:
hdr_size = sizeof (struct pcaprec_hdr);
break;
case WTAP_FILE_PCAP_SS990417:
case WTAP_FILE_PCAP_SS991029:
rec_hdr.ifindex = 0;
rec_hdr.protocol = 0;
rec_hdr.pkt_type = 0;
hdr_size = sizeof (struct pcaprec_modified_hdr);
break;
case WTAP_FILE_PCAP_SS990915:
rec_hdr.ifindex = 0;
rec_hdr.protocol = 0;
rec_hdr.pkt_type = 0;
rec_hdr.cpu1 = 0;
rec_hdr.cpu2 = 0;
hdr_size = sizeof (struct pcaprec_ss990915_hdr);
break;
case WTAP_FILE_PCAP_NOKIA:
memcpy(&rec_hdr.ifindex, pseudo_header->nokia.stuff, 4);
rec_hdr.protocol = 0;
rec_hdr.pkt_type = 0;
rec_hdr.cpu1 = 0;
rec_hdr.cpu2 = 0;
hdr_size = sizeof (struct pcaprec_nokia_hdr);
break;
default:
g_assert_not_reached();
*err = WTAP_ERR_UNSUPPORTED_FILE_TYPE;
return FALSE;
}
if (!wtap_dump_file_write(wdh, &rec_hdr, hdr_size, err))
return FALSE;
wdh->bytes_dumped += hdr_size;
if (!pcap_write_phdr(wdh, wdh->encap, pseudo_header, err))
return FALSE;
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
wdh->bytes_dumped += phdr->caplen;
return TRUE;
}
