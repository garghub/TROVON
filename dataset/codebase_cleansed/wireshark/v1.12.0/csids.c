int csids_open(wtap *wth, int *err, gchar **err_info)
{
int tmp,iplen,bytesRead;
gboolean byteswap = FALSE;
struct csids_header hdr;
csids_t *csids;
bytesRead = file_read( &hdr, sizeof( struct csids_header), wth->fh );
if( bytesRead != sizeof( struct csids_header) ) {
*err = file_error( wth->fh, err_info );
if( *err != 0 && *err != WTAP_ERR_SHORT_READ ) {
return -1;
}
return 0;
}
if( hdr.zeropad != 0 || hdr.caplen == 0 ) {
return 0;
}
hdr.seconds = pntoh32( &hdr.seconds );
hdr.caplen = pntoh16( &hdr.caplen );
bytesRead = file_read( &tmp, 2, wth->fh );
if( bytesRead != 2 ) {
*err = file_error( wth->fh, err_info );
if( *err != 0 && *err != WTAP_ERR_SHORT_READ ) {
return -1;
}
return 0;
}
bytesRead = file_read( &iplen, 2, wth->fh );
if( bytesRead != 2 ) {
*err = file_error( wth->fh, err_info );
if( *err != 0 && *err != WTAP_ERR_SHORT_READ ) {
return -1;
}
return 0;
}
iplen = pntoh16(&iplen);
if ( iplen == 0 )
return 0;
if( iplen > hdr.caplen ) {
iplen = GUINT16_SWAP_LE_BE(iplen);
if( iplen <= hdr.caplen ) {
byteswap = TRUE;
} else {
return 0;
}
} else {
byteswap = FALSE;
}
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return -1;
csids = (csids_t *)g_malloc(sizeof(csids_t));
wth->priv = (void *)csids;
csids->byteswapped = byteswap;
wth->file_encap = WTAP_ENCAP_RAW_IP;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_CSIDS;
wth->snapshot_length = 0;
wth->subtype_read = csids_read;
wth->subtype_seek_read = csids_seek_read;
wth->tsprecision = WTAP_FILE_TSPREC_SEC;
return 1;
}
static gboolean csids_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
csids_t *csids = (csids_t *)wth->priv;
*data_offset = file_tell(wth->fh);
return csids_read_packet( wth->fh, csids, &wth->phdr, wth->frame_buffer,
err, err_info );
}
static gboolean
csids_seek_read(wtap *wth,
gint64 seek_off,
struct wtap_pkthdr *phdr,
Buffer *buf,
int *err,
gchar **err_info)
{
csids_t *csids = (csids_t *)wth->priv;
if( file_seek( wth->random_fh, seek_off, SEEK_SET, err ) == -1 )
return FALSE;
if( !csids_read_packet( wth->random_fh, csids, phdr, buf, err, err_info ) ) {
if( *err == 0 )
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static gboolean
csids_read_packet(FILE_T fh, csids_t *csids, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
struct csids_header hdr;
int bytesRead = 0;
guint8 *pd;
bytesRead = file_read( &hdr, sizeof( struct csids_header), fh );
if( bytesRead != sizeof( struct csids_header) ) {
*err = file_error( fh, err_info );
if (*err == 0 && bytesRead != 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
hdr.seconds = pntoh32(&hdr.seconds);
hdr.caplen = pntoh16(&hdr.caplen);
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
phdr->len = hdr.caplen;
phdr->caplen = hdr.caplen;
phdr->ts.secs = hdr.seconds;
phdr->ts.nsecs = 0;
if( !wtap_read_packet_bytes( fh, buf, phdr->caplen, err, err_info ) )
return FALSE;
pd = buffer_start_ptr( buf );
if( csids->byteswapped ) {
if( phdr->caplen >= 2 ) {
PBSWAP16(pd);
if( phdr->caplen >= 4 ) {
PBSWAP16(pd+2);
if( phdr->caplen >= 6 )
PBSWAP16(pd+4);
}
}
}
return TRUE;
}
