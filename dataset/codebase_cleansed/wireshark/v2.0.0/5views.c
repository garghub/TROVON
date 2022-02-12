wtap_open_return_val
_5views_open(wtap *wth, int *err, gchar **err_info)
{
t_5VW_Capture_Header Capture_Header;
int encap = WTAP_ENCAP_UNKNOWN;
if (!wtap_read_bytes(wth->fh, &Capture_Header.Info_Header,
sizeof(t_5VW_Info_Header), err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if(Capture_Header.Info_Header.Signature != CST_5VW_INFO_HEADER_KEY)
{
return WTAP_OPEN_NOT_MINE;
}
Capture_Header.Info_Header.Version =
pletoh32(&Capture_Header.Info_Header.Version);
switch (Capture_Header.Info_Header.Version) {
case CST_5VW_INFO_RECORD_VERSION:
break;
default:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("5views: header version %u unsupported", Capture_Header.Info_Header.Version);
return WTAP_OPEN_ERROR;
}
Capture_Header.Info_Header.FileType =
pletoh32(&Capture_Header.Info_Header.FileType);
if((Capture_Header.Info_Header.FileType & CST_5VW_CAPTURE_FILE_TYPE_MASK) != CST_5VW_CAPTURE_FILEID)
{
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("5views: file is not a capture file (filetype is %u)", Capture_Header.Info_Header.Version);
return WTAP_OPEN_ERROR;
}
switch (Capture_Header.Info_Header.FileType) {
case CST_5VW_CAPTURE_ETH_FILEID:
encap = WTAP_ENCAP_ETHERNET;
break;
default:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("5views: network type %u unknown or unsupported",
Capture_Header.Info_Header.FileType);
return WTAP_OPEN_ERROR;
}
if (!wtap_read_bytes(wth->fh, &Capture_Header.HeaderDateCreation,
sizeof (t_5VW_Capture_Header) - sizeof(t_5VW_Info_Header), err, err_info))
return WTAP_OPEN_ERROR;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_5VIEWS;
wth->subtype_read = _5views_read;
wth->subtype_seek_read = _5views_seek_read;
wth->file_encap = encap;
wth->snapshot_length = 0;
wth->file_tsprec = WTAP_TSPREC_NSEC;
return WTAP_OPEN_MINE;
}
static gboolean
_5views_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
t_5VW_TimeStamped_Header TimeStamped_Header;
do
{
*data_offset = file_tell(wth->fh);
if (!_5views_read_header(wth, wth->fh, &TimeStamped_Header,
&wth->phdr, err, err_info))
return FALSE;
if (TimeStamped_Header.RecSubType == CST_5VW_FRAME_RECORD) {
break;
}
if (file_seek(wth->fh, TimeStamped_Header.RecSize, SEEK_CUR, err) == -1)
return FALSE;
} while (1);
if (wth->phdr.caplen > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("5views: File has %u-byte packet, bigger than maximum of %u",
wth->phdr.caplen, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
return wtap_read_packet_bytes(wth->fh, wth->frame_buffer,
wth->phdr.caplen, err, err_info);
}
static gboolean
_5views_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
t_5VW_TimeStamped_Header TimeStamped_Header;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!_5views_read_header(wth, wth->random_fh, &TimeStamped_Header,
phdr, err, err_info)) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return wtap_read_packet_bytes(wth->random_fh, buf, phdr->caplen,
err, err_info);
}
static gboolean
_5views_read_header(wtap *wth, FILE_T fh, t_5VW_TimeStamped_Header *hdr,
struct wtap_pkthdr *phdr, int *err, gchar **err_info)
{
if (!wtap_read_bytes_or_eof(fh, hdr, (unsigned int)sizeof(t_5VW_TimeStamped_Header),
err, err_info))
return FALSE;
hdr->Key = pletoh32(&hdr->Key);
if (hdr->Key != CST_5VW_RECORDS_HEADER_KEY) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("5views: Time-stamped header has bad key value 0x%08X",
hdr->Key);
return FALSE;
}
hdr->RecSubType = pletoh32(&hdr->RecSubType);
hdr->RecSize = pletoh32(&hdr->RecSize);
hdr->Utc = pletoh32(&hdr->Utc);
hdr->NanoSecondes = pletoh32(&hdr->NanoSecondes);
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
phdr->ts.secs = hdr->Utc;
phdr->ts.nsecs = hdr->NanoSecondes;
phdr->caplen = hdr->RecSize;
phdr->len = hdr->RecSize;
switch (wth->file_encap) {
case WTAP_ENCAP_ETHERNET:
phdr->pseudo_header.eth.fcs_len = 0;
break;
}
return TRUE;
}
int _5views_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_PER_PACKET)
return WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED;
if (encap < 0 || (unsigned int) encap >= NUM_WTAP_ENCAPS || wtap_encap[encap] == -1)
return WTAP_ERR_UNWRITABLE_ENCAP;
return 0;
}
gboolean _5views_dump_open(wtap_dumper *wdh, int *err)
{
_5views_dump_t *_5views;
if (wtap_dump_file_seek(wdh, sizeof(t_5VW_Capture_Header), SEEK_SET, err) == -1)
return FALSE;
wdh->subtype_write = _5views_dump;
wdh->subtype_finish = _5views_dump_finish;
_5views = (_5views_dump_t *)g_malloc(sizeof(_5views_dump_t));
wdh->priv = (void *)_5views;
_5views->nframes = 0;
return TRUE;
}
static gboolean _5views_dump(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err, gchar **err_info _U_)
{
_5views_dump_t *_5views = (_5views_dump_t *)wdh->priv;
t_5VW_TimeStamped_Header HeaderFrame;
if (phdr->rec_type != REC_TYPE_PACKET) {
*err = WTAP_ERR_UNWRITABLE_REC_TYPE;
return FALSE;
}
if (phdr->caplen > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
HeaderFrame.Key = GUINT32_TO_LE(CST_5VW_RECORDS_HEADER_KEY);
HeaderFrame.HeaderSize = GUINT16_TO_LE(sizeof(t_5VW_TimeStamped_Header));
HeaderFrame.HeaderType = GUINT16_TO_LE(CST_5VW_TIMESTAMPED_HEADER_TYPE);
HeaderFrame.RecType = GUINT32_TO_LE(CST_5VW_CAPTURES_RECORD | CST_5VW_SYSTEM_RECORD);
HeaderFrame.RecSubType = GUINT32_TO_LE(CST_5VW_FRAME_RECORD);
HeaderFrame.RecNb = GUINT32_TO_LE(1);
HeaderFrame.Utc = GUINT32_TO_LE(phdr->ts.secs);
HeaderFrame.NanoSecondes = GUINT32_TO_LE(phdr->ts.nsecs);
HeaderFrame.RecSize = GUINT32_TO_LE(phdr->len);
HeaderFrame.RecInfo = GUINT32_TO_LE(0);
if (!wtap_dump_file_write(wdh, &HeaderFrame,
sizeof(t_5VW_TimeStamped_Header), err))
return FALSE;
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
_5views->nframes ++;
return TRUE;
}
static gboolean _5views_dump_finish(wtap_dumper *wdh, int *err)
{
_5views_dump_t *_5views = (_5views_dump_t *)wdh->priv;
t_5VW_Capture_Header file_hdr;
if (wtap_dump_file_seek(wdh, 0, SEEK_SET, err) == -1)
return FALSE;
file_hdr.Info_Header.Signature = GUINT32_TO_LE(CST_5VW_INFO_HEADER_KEY);
file_hdr.Info_Header.Size = GUINT32_TO_LE(sizeof(t_5VW_Info_Header));
file_hdr.Info_Header.Version = GUINT32_TO_LE(CST_5VW_INFO_RECORD_VERSION);
file_hdr.Info_Header.DataSize = GUINT32_TO_LE(sizeof(t_5VW_Attributes_Header)
+ sizeof(guint32)
+ sizeof(t_5VW_Attributes_Header)
+ sizeof(guint32));
file_hdr.Info_Header.FileType = GUINT32_TO_LE(wtap_encap[wdh->encap]);
file_hdr.Info_Header.Reserved[0] = 0;
file_hdr.Info_Header.Reserved[1] = 0;
file_hdr.Info_Header.Reserved[2] = 0;
file_hdr.HeaderDateCreation.Type = GUINT32_TO_LE(CST_5VW_IA_DATE_CREATION);
file_hdr.HeaderDateCreation.Size = GUINT16_TO_LE(sizeof(guint32));
file_hdr.HeaderDateCreation.Nb = GUINT16_TO_LE(1);
#ifdef _WIN32
_tzset();
#endif
file_hdr.Time = GUINT32_TO_LE(time(NULL));
file_hdr.HeaderNbFrames.Type = GUINT32_TO_LE(CST_5VW_IA_CAP_INF_NB_TRAMES_STOCKEES);
file_hdr.HeaderNbFrames.Size = GUINT16_TO_LE(sizeof(guint32));
file_hdr.HeaderNbFrames.Nb = GUINT16_TO_LE(1);
file_hdr.TramesStockeesInFile = GUINT32_TO_LE(_5views->nframes);
if (!wtap_dump_file_write(wdh, &file_hdr, sizeof(t_5VW_Capture_Header),
err))
return FALSE;
return TRUE;
}
