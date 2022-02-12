wtap_open_return_val libpcap_open(wtap *wth, int *err, gchar **err_info)
{
guint32 magic;
struct pcap_hdr hdr;
gboolean byte_swapped;
gboolean modified;
gboolean aix;
int file_encap;
gint64 first_packet_offset;
libpcap_t *libpcap;
static const int subtypes_modified[] = {
WTAP_FILE_TYPE_SUBTYPE_PCAP_SS991029,
WTAP_FILE_TYPE_SUBTYPE_PCAP_SS990915
};
#define N_SUBTYPES_MODIFIED G_N_ELEMENTS(subtypes_modified)
static const int subtypes_standard[] = {
WTAP_FILE_TYPE_SUBTYPE_PCAP,
WTAP_FILE_TYPE_SUBTYPE_PCAP_SS990417,
WTAP_FILE_TYPE_SUBTYPE_PCAP_NOKIA
};
#define N_SUBTYPES_STANDARD G_N_ELEMENTS(subtypes_standard)
static const int subtypes_nsec[] = {
WTAP_FILE_TYPE_SUBTYPE_PCAP_NSEC
};
#define N_SUBTYPES_NSEC G_N_ELEMENTS(subtypes_nsec)
#define MAX_FIGURES_OF_MERIT \
MAX(MAX(N_SUBTYPES_MODIFIED, N_SUBTYPES_STANDARD), N_SUBTYPES_NSEC)
int figures_of_merit[MAX_FIGURES_OF_MERIT];
const int *subtypes;
int n_subtypes;
int best_subtype;
int i;
if (!wtap_read_bytes(wth->fh, &magic, sizeof magic, err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
switch (magic) {
case PCAP_MAGIC:
byte_swapped = FALSE;
modified = FALSE;
wth->file_tsprec = WTAP_TSPREC_USEC;
break;
case PCAP_MODIFIED_MAGIC:
byte_swapped = FALSE;
modified = TRUE;
wth->file_tsprec = WTAP_TSPREC_USEC;
break;
case PCAP_SWAPPED_MAGIC:
byte_swapped = TRUE;
modified = FALSE;
wth->file_tsprec = WTAP_TSPREC_USEC;
break;
case PCAP_SWAPPED_MODIFIED_MAGIC:
byte_swapped = TRUE;
modified = TRUE;
wth->file_tsprec = WTAP_TSPREC_USEC;
break;
case PCAP_NSEC_MAGIC:
byte_swapped = FALSE;
modified = FALSE;
wth->file_tsprec = WTAP_TSPREC_NSEC;
break;
case PCAP_SWAPPED_NSEC_MAGIC:
byte_swapped = TRUE;
modified = FALSE;
wth->file_tsprec = WTAP_TSPREC_NSEC;
break;
default:
return WTAP_OPEN_NOT_MINE;
}
if (!wtap_read_bytes(wth->fh, &hdr, sizeof hdr, err, err_info))
return WTAP_OPEN_ERROR;
if (byte_swapped) {
hdr.version_major = GUINT16_SWAP_LE_BE(hdr.version_major);
hdr.version_minor = GUINT16_SWAP_LE_BE(hdr.version_minor);
hdr.snaplen = GUINT32_SWAP_LE_BE(hdr.snaplen);
hdr.network = GUINT32_SWAP_LE_BE(hdr.network);
}
if (hdr.version_major < 2) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("pcap: major version %u unsupported",
hdr.version_major);
return WTAP_OPEN_ERROR;
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
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("pcap: network type %u unknown or unsupported",
hdr.network);
return WTAP_OPEN_ERROR;
}
libpcap = (libpcap_t *)g_malloc(sizeof(libpcap_t));
libpcap->byte_swapped = byte_swapped;
libpcap->version_major = hdr.version_major;
libpcap->version_minor = hdr.version_minor;
libpcap->encap_priv = NULL;
wth->priv = (void *)libpcap;
wth->subtype_read = libpcap_read;
wth->subtype_seek_read = libpcap_seek_read;
wth->subtype_close = libpcap_close;
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
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_PCAP_AIX;
wth->file_tsprec = WTAP_TSPREC_NSEC;
return WTAP_OPEN_MINE;
}
if (modified) {
subtypes = subtypes_modified;
n_subtypes = N_SUBTYPES_MODIFIED;
} else {
if (wth->file_tsprec == WTAP_TSPREC_NSEC) {
subtypes = subtypes_nsec;
n_subtypes = N_SUBTYPES_NSEC;
} else {
subtypes = subtypes_standard;
n_subtypes = N_SUBTYPES_STANDARD;
}
}
first_packet_offset = file_tell(wth->fh);
for (i = 0; i < n_subtypes; i++) {
wth->file_type_subtype = subtypes[i];
figures_of_merit[i] = libpcap_try(wth, err, err_info);
if (figures_of_merit[i] == -1) {
return WTAP_OPEN_ERROR;
}
if (figures_of_merit[i] == 0) {
if (file_seek(wth->fh, first_packet_offset, SEEK_SET, err) == -1) {
return WTAP_OPEN_ERROR;
}
goto done;
}
if (file_seek(wth->fh, first_packet_offset, SEEK_SET, err) == -1) {
return WTAP_OPEN_ERROR;
}
}
best_subtype = INT_MAX;
for (i = 0; i < n_subtypes; i++) {
if (figures_of_merit[i] < best_subtype) {
wth->file_type_subtype = subtypes[i];
best_subtype = figures_of_merit[i];
}
}
done:
if (wth->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_PCAP_NOKIA &&
hdr.network == 13)
wth->file_encap = WTAP_ENCAP_ATM_PDUS;
if (wth->file_encap == WTAP_ENCAP_ERF) {
libpcap->encap_priv = erf_priv_create();
}
return WTAP_OPEN_MINE;
}
static int libpcap_try(wtap *wth, int *err, gchar **err_info)
{
int ret;
struct pcaprec_ss990915_hdr first_rec_hdr, second_rec_hdr;
ret = libpcap_try_header(wth, wth->fh, err, err_info, &first_rec_hdr);
if (ret == -1) {
if (*err == 0 || *err == WTAP_ERR_SHORT_READ) {
return 0;
}
return ret;
}
if (ret != 0) {
return ret;
}
if (!wtap_read_bytes(wth->fh, NULL, first_rec_hdr.hdr.incl_len, err, err_info))
return -1;
ret = libpcap_try_header(wth, wth->fh, err, err_info, &second_rec_hdr);
if (ret == -1) {
if (*err == 0 || *err == WTAP_ERR_SHORT_READ) {
return 0;
}
return ret;
}
return ret;
}
static int libpcap_try_header(wtap *wth, FILE_T fh, int *err, gchar **err_info,
struct pcaprec_ss990915_hdr *hdr)
{
int ret;
if (!libpcap_read_header(wth, fh, err, err_info, hdr))
return -1;
ret = 0;
switch (wth->file_type_subtype) {
case WTAP_FILE_TYPE_SUBTYPE_PCAP_NSEC:
case WTAP_FILE_TYPE_SUBTYPE_PCAP_AIX:
if (hdr->hdr.ts_usec >= 1000000000)
ret++;
break;
default:
if (hdr->hdr.ts_usec >= 1000000)
ret++;
break;
}
if (hdr->hdr.incl_len > wtap_max_snaplen_for_encap(wth->file_encap)) {
ret++;
}
if (hdr->hdr.orig_len > 128*1024*1024) {
ret++;
}
if (hdr->hdr.incl_len > wth->snapshot_length) {
ret++;
}
if (hdr->hdr.incl_len > hdr->hdr.orig_len) {
ret++;
}
return ret;
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
Buffer *buf, int *err, gchar **err_info)
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
int phdr_len;
libpcap_t *libpcap;
libpcap = (libpcap_t *)wth->priv;
if (!libpcap_read_header(wth, fh, err, err_info, &hdr))
return FALSE;
if (hdr.hdr.incl_len > wtap_max_snaplen_for_encap(wth->file_encap)) {
*err = WTAP_ERR_BAD_FILE;
if (err_info != NULL) {
*err_info = g_strdup_printf("pcap: File has %u-byte packet, bigger than maximum of %u",
hdr.hdr.incl_len,
wtap_max_snaplen_for_encap(wth->file_encap));
}
return FALSE;
}
packet_size = hdr.hdr.incl_len;
orig_size = hdr.hdr.orig_len;
if (wth->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_PCAP_AIX &&
(wth->file_encap == WTAP_ENCAP_FDDI ||
wth->file_encap == WTAP_ENCAP_FDDI_BITSWAPPED)) {
packet_size -= 3;
orig_size -= 3;
if (!wtap_read_bytes(fh, NULL, 3, err, err_info))
return FALSE;
}
phdr_len = pcap_process_pseudo_header(fh, wth->file_type_subtype,
wth->file_encap, packet_size, TRUE, phdr, err, err_info);
if (phdr_len < 0)
return FALSE;
orig_size -= phdr_len;
packet_size -= phdr_len;
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
if (wth->file_encap != WTAP_ENCAP_ERF) {
phdr->ts.secs = hdr.hdr.ts_sec;
if (wth->file_tsprec == WTAP_TSPREC_NSEC)
phdr->ts.nsecs = hdr.hdr.ts_usec;
else
phdr->ts.nsecs = hdr.hdr.ts_usec * 1000;
} else {
int interface_id;
phdr->presence_flags |= WTAP_HAS_INTERFACE_ID;
if ((interface_id = erf_populate_interface_from_header((erf_t*) libpcap->encap_priv, wth, &phdr->pseudo_header)) < 0)
return FALSE;
phdr->interface_id = (guint) interface_id;
}
phdr->caplen = packet_size;
phdr->len = orig_size;
if (!wtap_read_packet_bytes(fh, buf, packet_size, err, err_info))
return FALSE;
pcap_read_post_process(wth->file_type_subtype, wth->file_encap,
phdr, ws_buffer_start_ptr(buf), libpcap->byte_swapped, -1);
return TRUE;
}
static int libpcap_read_header(wtap *wth, FILE_T fh, int *err, gchar **err_info,
struct pcaprec_ss990915_hdr *hdr)
{
int bytes_to_read;
guint32 temp;
libpcap_t *libpcap;
switch (wth->file_type_subtype) {
case WTAP_FILE_TYPE_SUBTYPE_PCAP:
case WTAP_FILE_TYPE_SUBTYPE_PCAP_AIX:
case WTAP_FILE_TYPE_SUBTYPE_PCAP_NSEC:
bytes_to_read = sizeof (struct pcaprec_hdr);
break;
case WTAP_FILE_TYPE_SUBTYPE_PCAP_SS990417:
case WTAP_FILE_TYPE_SUBTYPE_PCAP_SS991029:
bytes_to_read = sizeof (struct pcaprec_modified_hdr);
break;
case WTAP_FILE_TYPE_SUBTYPE_PCAP_SS990915:
bytes_to_read = sizeof (struct pcaprec_ss990915_hdr);
break;
case WTAP_FILE_TYPE_SUBTYPE_PCAP_NOKIA:
bytes_to_read = sizeof (struct pcaprec_nokia_hdr);
break;
default:
g_assert_not_reached();
bytes_to_read = 0;
}
if (!wtap_read_bytes_or_eof(fh, hdr, bytes_to_read, err, err_info))
return FALSE;
libpcap = (libpcap_t *)wth->priv;
if (libpcap->byte_swapped) {
hdr->hdr.ts_sec = GUINT32_SWAP_LE_BE(hdr->hdr.ts_sec);
hdr->hdr.ts_usec = GUINT32_SWAP_LE_BE(hdr->hdr.ts_usec);
hdr->hdr.incl_len = GUINT32_SWAP_LE_BE(hdr->hdr.incl_len);
hdr->hdr.orig_len = GUINT32_SWAP_LE_BE(hdr->hdr.orig_len);
}
switch (libpcap->lengths_swapped) {
case NOT_SWAPPED:
break;
case MAYBE_SWAPPED:
if (hdr->hdr.incl_len <= hdr->hdr.orig_len) {
break;
}
case SWAPPED:
temp = hdr->hdr.orig_len;
hdr->hdr.orig_len = hdr->hdr.incl_len;
hdr->hdr.incl_len = temp;
break;
}
return TRUE;
}
int libpcap_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_PER_PACKET)
return WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED;
if (wtap_wtap_encap_to_pcap_encap(encap) == -1)
return WTAP_ERR_UNWRITABLE_ENCAP;
return 0;
}
gboolean libpcap_dump_open(wtap_dumper *wdh, int *err)
{
guint32 magic;
struct pcap_hdr file_hdr;
wdh->subtype_write = libpcap_dump;
switch (wdh->file_type_subtype) {
case WTAP_FILE_TYPE_SUBTYPE_PCAP:
case WTAP_FILE_TYPE_SUBTYPE_PCAP_SS990417:
case WTAP_FILE_TYPE_SUBTYPE_PCAP_NOKIA:
magic = PCAP_MAGIC;
break;
case WTAP_FILE_TYPE_SUBTYPE_PCAP_SS990915:
case WTAP_FILE_TYPE_SUBTYPE_PCAP_SS991029:
magic = PCAP_MODIFIED_MAGIC;
break;
case WTAP_FILE_TYPE_SUBTYPE_PCAP_NSEC:
magic = PCAP_NSEC_MAGIC;
break;
default:
*err = WTAP_ERR_UNWRITABLE_FILE_TYPE;
return FALSE;
}
if (!wtap_dump_file_write(wdh, &magic, sizeof magic, err))
return FALSE;
wdh->bytes_dumped += sizeof magic;
file_hdr.version_major = 2;
file_hdr.version_minor = 4;
file_hdr.thiszone = 0;
file_hdr.sigfigs = 0;
file_hdr.snaplen = (wdh->snaplen != 0) ? (guint)wdh->snaplen :
wtap_max_snaplen_for_encap(wdh->encap);
file_hdr.network = wtap_wtap_encap_to_pcap_encap(wdh->encap);
if (!wtap_dump_file_write(wdh, &file_hdr, sizeof file_hdr, err))
return FALSE;
wdh->bytes_dumped += sizeof file_hdr;
return TRUE;
}
static gboolean libpcap_dump(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err, gchar **err_info _U_)
{
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
struct pcaprec_ss990915_hdr rec_hdr;
size_t hdr_size;
int phdrsize;
phdrsize = pcap_get_phdr_size(wdh->encap, pseudo_header);
if (phdr->rec_type != REC_TYPE_PACKET) {
*err = WTAP_ERR_UNWRITABLE_REC_TYPE;
return FALSE;
}
if ((guint64)phdr->caplen + phdrsize > wtap_max_snaplen_for_encap(wdh->encap)) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
rec_hdr.hdr.incl_len = phdr->caplen + phdrsize;
rec_hdr.hdr.orig_len = phdr->len + phdrsize;
switch (wdh->file_type_subtype) {
case WTAP_FILE_TYPE_SUBTYPE_PCAP:
rec_hdr.hdr.ts_sec = (guint32) phdr->ts.secs;
rec_hdr.hdr.ts_usec = phdr->ts.nsecs / 1000;
hdr_size = sizeof (struct pcaprec_hdr);
break;
case WTAP_FILE_TYPE_SUBTYPE_PCAP_NSEC:
rec_hdr.hdr.ts_sec = (guint32) phdr->ts.secs;
rec_hdr.hdr.ts_usec = phdr->ts.nsecs;
hdr_size = sizeof (struct pcaprec_hdr);
break;
case WTAP_FILE_TYPE_SUBTYPE_PCAP_SS990417:
case WTAP_FILE_TYPE_SUBTYPE_PCAP_SS991029:
rec_hdr.hdr.ts_sec = (guint32) phdr->ts.secs;
rec_hdr.hdr.ts_usec = phdr->ts.nsecs / 1000;
rec_hdr.ifindex = 0;
rec_hdr.protocol = 0;
rec_hdr.pkt_type = 0;
hdr_size = sizeof (struct pcaprec_modified_hdr);
break;
case WTAP_FILE_TYPE_SUBTYPE_PCAP_SS990915:
rec_hdr.hdr.ts_sec = (guint32) phdr->ts.secs;
rec_hdr.hdr.ts_usec = phdr->ts.nsecs / 1000;
rec_hdr.ifindex = 0;
rec_hdr.protocol = 0;
rec_hdr.pkt_type = 0;
rec_hdr.cpu1 = 0;
rec_hdr.cpu2 = 0;
hdr_size = sizeof (struct pcaprec_ss990915_hdr);
break;
case WTAP_FILE_TYPE_SUBTYPE_PCAP_NOKIA:
rec_hdr.hdr.ts_sec = (guint32) phdr->ts.secs;
rec_hdr.hdr.ts_usec = phdr->ts.nsecs / 1000;
memcpy(&rec_hdr.ifindex, pseudo_header->nokia.stuff, 4);
rec_hdr.protocol = 0;
rec_hdr.pkt_type = 0;
rec_hdr.cpu1 = 0;
rec_hdr.cpu2 = 0;
hdr_size = sizeof (struct pcaprec_nokia_hdr);
break;
default:
g_assert_not_reached();
*err = WTAP_ERR_UNWRITABLE_FILE_TYPE;
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
static void libpcap_close(wtap *wth)
{
libpcap_t *libpcap = (libpcap_t *)wth->priv;
if (libpcap->encap_priv) {
switch (wth->file_encap) {
case WTAP_ENCAP_ERF:
erf_priv_free((erf_t*) libpcap->encap_priv);
break;
default:
g_free(libpcap->encap_priv);
break;
}
}
}
