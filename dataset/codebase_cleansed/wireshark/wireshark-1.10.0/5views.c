int _5views_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
t_5VW_Capture_Header Capture_Header;
int encap = WTAP_ENCAP_UNKNOWN;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&Capture_Header.Info_Header, sizeof(t_5VW_Info_Header), wth->fh);
if (bytes_read != sizeof(t_5VW_Info_Header)) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if(Capture_Header.Info_Header.Signature != CST_5VW_INFO_HEADER_KEY)
{
return 0;
}
Capture_Header.Info_Header.Version =
pletohl(&Capture_Header.Info_Header.Version);
switch (Capture_Header.Info_Header.Version) {
case CST_5VW_INFO_RECORD_VERSION:
break;
default:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("5views: header version %u unsupported", Capture_Header.Info_Header.Version);
return -1;
}
Capture_Header.Info_Header.FileType =
pletohl(&Capture_Header.Info_Header.FileType);
if((Capture_Header.Info_Header.FileType & CST_5VW_CAPTURE_FILE_TYPE_MASK) != CST_5VW_CAPTURE_FILEID)
{
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("5views: file is not a capture file (filetype is %u)", Capture_Header.Info_Header.Version);
return -1;
}
switch (Capture_Header.Info_Header.FileType) {
case CST_5VW_CAPTURE_ETH_FILEID:
encap = WTAP_ENCAP_ETHERNET;
break;
default:
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("5views: network type %u unknown or unsupported",
Capture_Header.Info_Header.FileType);
return -1;
}
bytes_read = file_read(&Capture_Header.HeaderDateCreation, sizeof (t_5VW_Capture_Header) - sizeof(t_5VW_Info_Header), wth->fh);
if (bytes_read != sizeof (t_5VW_Capture_Header)- sizeof(t_5VW_Info_Header) ) {
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return -1;
}
wth->file_type = WTAP_FILE_5VIEWS;
wth->subtype_read = _5views_read;
wth->subtype_seek_read = _5views_seek_read;
wth->file_encap = encap;
wth->snapshot_length = 0;
wth->tsprecision = WTAP_FILE_TSPREC_NSEC;
return 1;
}
static gboolean
_5views_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
t_5VW_TimeStamped_Header TimeStamped_Header;
int bytes_read;
guint packet_size;
guint orig_size;
do
{
bytes_read = _5views_read_header(wth, wth->fh, &TimeStamped_Header, err, err_info);
if (bytes_read == -1) {
return FALSE;
}
TimeStamped_Header.Key = pletohl(&TimeStamped_Header.Key);
if(TimeStamped_Header.Key != CST_5VW_RECORDS_HEADER_KEY) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("5views: Time-stamped header has bad key value 0x%08X",
TimeStamped_Header.Key);
return FALSE;
}
TimeStamped_Header.RecSubType =
pletohl(&TimeStamped_Header.RecSubType);
TimeStamped_Header.RecSize =
pletohl(&TimeStamped_Header.RecSize);
if(TimeStamped_Header.RecSubType != CST_5VW_FRAME_RECORD) {
if (file_seek(wth->fh, TimeStamped_Header.RecSize, SEEK_CUR, err) == -1)
return FALSE;
} else
break;
} while (1);
packet_size = TimeStamped_Header.RecSize;
orig_size = TimeStamped_Header.RecSize;
if (packet_size > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("5views: File has %u-byte packet, bigger than maximum of %u",
packet_size, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
*data_offset = file_tell(wth->fh);
buffer_assure_space(wth->frame_buffer, packet_size);
if (!_5views_read_rec_data(wth->fh, buffer_start_ptr(wth->frame_buffer),
packet_size, err, err_info))
return FALSE;
TimeStamped_Header.Utc = pletohl(&TimeStamped_Header.Utc);
TimeStamped_Header.NanoSecondes =
pletohl(&TimeStamped_Header.NanoSecondes);
wth->phdr.presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
wth->phdr.ts.secs = TimeStamped_Header.Utc;
wth->phdr.ts.nsecs = TimeStamped_Header.NanoSecondes;
wth->phdr.caplen = packet_size;
wth->phdr.len = orig_size;
switch (wth->file_encap) {
case WTAP_ENCAP_ETHERNET:
wth->phdr.pseudo_header.eth.fcs_len = 0;
break;
}
return TRUE;
}
static gboolean
_5views_read_rec_data(FILE_T fh, guint8 *pd, int length, int *err,
gchar **err_info)
{
int bytes_read;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(pd, length, fh);
if (bytes_read != length) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static int
_5views_read_header(wtap *wth _U_, FILE_T fh, t_5VW_TimeStamped_Header *hdr, int *err, gchar **err_info)
{
int bytes_read, bytes_to_read;
bytes_to_read = sizeof(t_5VW_TimeStamped_Header);
bytes_read = file_read(hdr, bytes_to_read, fh);
if (bytes_read != bytes_to_read) {
*err = file_error(fh, err_info);
if (*err == 0 && bytes_read != 0) {
*err = WTAP_ERR_SHORT_READ;
}
return -1;
}
return bytes_read;
}
static gboolean
_5views_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, guint8 *pd, int length,
int *err, gchar **err_info)
{
union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!_5views_read_rec_data(wth->random_fh, pd, length, err, err_info))
return FALSE;
switch (wth->file_encap) {
case WTAP_ENCAP_ETHERNET:
pseudo_header->eth.fcs_len = 0;
break;
}
return TRUE;
}
int _5views_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_PER_PACKET)
return WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED;
if (encap < 0 || (unsigned) encap >= NUM_WTAP_ENCAPS || wtap_encap[encap] == -1)
return WTAP_ERR_UNSUPPORTED_ENCAP;
return 0;
}
gboolean _5views_dump_open(wtap_dumper *wdh, int *err)
{
_5views_dump_t *_5views;
if (wtap_dump_file_seek(wdh, sizeof(t_5VW_Capture_Header), SEEK_SET, err) == -1)
return FALSE;
wdh->subtype_write = _5views_dump;
wdh->subtype_close = _5views_dump_close;
_5views = (_5views_dump_t *)g_malloc(sizeof(_5views_dump_t));
wdh->priv = (void *)_5views;
_5views->nframes = 0;
return TRUE;
}
static gboolean _5views_dump(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err)
{
_5views_dump_t *_5views = (_5views_dump_t *)wdh->priv;
static t_5VW_TimeStamped_Header HeaderFrame;
HeaderFrame.Key = htolel(CST_5VW_RECORDS_HEADER_KEY);
HeaderFrame.HeaderSize = htoles(sizeof(t_5VW_TimeStamped_Header));
HeaderFrame.HeaderType = htoles(CST_5VW_TIMESTAMPED_HEADER_TYPE);
HeaderFrame.RecType = htolel(CST_5VW_CAPTURES_RECORD | CST_5VW_SYSTEM_RECORD);
HeaderFrame.RecSubType = htolel(CST_5VW_FRAME_RECORD);
HeaderFrame.RecNb = htolel(1);
HeaderFrame.Utc = htolel(phdr->ts.secs);
HeaderFrame.NanoSecondes = htolel(phdr->ts.nsecs);
HeaderFrame.RecSize = htolel(phdr->len);
HeaderFrame.RecInfo = htolel(0);
if (!wtap_dump_file_write(wdh, &HeaderFrame,
sizeof(t_5VW_TimeStamped_Header), err))
return FALSE;
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
_5views->nframes ++;
return TRUE;
}
static gboolean _5views_dump_close(wtap_dumper *wdh, int *err)
{
_5views_dump_t *_5views = (_5views_dump_t *)wdh->priv;
t_5VW_Capture_Header file_hdr;
if (wtap_dump_file_seek(wdh, 0, SEEK_SET, err) == -1)
return FALSE;
file_hdr.Info_Header.Signature = htolel(CST_5VW_INFO_HEADER_KEY);
file_hdr.Info_Header.Size = htolel(sizeof(t_5VW_Info_Header));
file_hdr.Info_Header.Version = htolel(CST_5VW_INFO_RECORD_VERSION);
file_hdr.Info_Header.DataSize = htolel(sizeof(t_5VW_Attributes_Header)
+ sizeof(guint32)
+ sizeof(t_5VW_Attributes_Header)
+ sizeof(guint32));
file_hdr.Info_Header.FileType = htolel(wtap_encap[wdh->encap]);
file_hdr.Info_Header.Reserved[0] = 0;
file_hdr.Info_Header.Reserved[1] = 0;
file_hdr.Info_Header.Reserved[2] = 0;
file_hdr.HeaderDateCreation.Type = htolel(CST_5VW_IA_DATE_CREATION);
file_hdr.HeaderDateCreation.Size = htoles(sizeof(guint32));
file_hdr.HeaderDateCreation.Nb = htoles(1);
#ifdef _WIN32
_tzset();
#endif
file_hdr.Time = htolel(time(NULL));
file_hdr.HeaderNbFrames.Type = htolel(CST_5VW_IA_CAP_INF_NB_TRAMES_STOCKEES);
file_hdr.HeaderNbFrames.Size = htoles(sizeof(guint32));
file_hdr.HeaderNbFrames.Nb = htoles(1);
file_hdr.TramesStockeesInFile = htolel(_5views->nframes);
if (!wtap_dump_file_write(wdh, &file_hdr, sizeof(t_5VW_Capture_Header),
err))
return FALSE;
return TRUE;
}
