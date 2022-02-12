int visual_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
char magic[sizeof visual_magic];
struct visual_file_hdr vfile_hdr;
struct visual_read_info * visual;
int encap;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(magic, sizeof magic, wth->fh);
if (bytes_read != sizeof magic)
{
*err = file_error(wth->fh, err_info);
if (*err != 0)
return -1;
return 0;
}
if (memcmp(magic, visual_magic, sizeof visual_magic) != 0)
{
return 0;
}
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&vfile_hdr, sizeof vfile_hdr, wth->fh);
if (bytes_read != sizeof vfile_hdr)
{
*err = file_error(wth->fh, err_info);
if (*err != 0)
return -1;
return 0;
}
vfile_hdr.file_version = pletohs(&vfile_hdr.file_version);
if (vfile_hdr.file_version != 1)
{
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("visual: file version %u unsupported", vfile_hdr.file_version);
return -1;
}
switch (pletohs(&vfile_hdr.media_type))
{
case 6:
encap = WTAP_ENCAP_ETHERNET;
break;
case 9:
encap = WTAP_ENCAP_TOKEN_RING;
break;
case 16:
encap = WTAP_ENCAP_LAPB;
break;
case 22:
case 118:
encap = WTAP_ENCAP_CHDLC_WITH_PHDR;
break;
case 32:
encap = WTAP_ENCAP_FRELAY_WITH_PHDR;
break;
case 37:
encap = WTAP_ENCAP_ATM_PDUS;
break;
default:
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("visual: network type %u unknown or unsupported",
vfile_hdr.media_type);
return -1;
}
wth->file_type = WTAP_FILE_VISUAL_NETWORKS;
wth->file_encap = encap;
wth->snapshot_length = pletohs(&vfile_hdr.max_length);
wth->subtype_read = visual_read;
wth->subtype_seek_read = visual_seek_read;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
visual = (struct visual_read_info *)g_malloc(sizeof(struct visual_read_info));
wth->priv = (void *)visual;
visual->num_pkts = pletohl(&vfile_hdr.num_pkts);
visual->start_time = ((double) pletohl(&vfile_hdr.start_time)) * 1000000;
visual->current_pkt = 1;
return 1;
}
static gboolean visual_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
struct visual_read_info *visual = (struct visual_read_info *)wth->priv;
guint32 packet_size = 0;
int bytes_read;
struct visual_pkt_hdr vpkt_hdr;
struct visual_atm_hdr vatm_hdr;
int phdr_size = sizeof(vpkt_hdr);
int ahdr_size = sizeof(vatm_hdr);
time_t secs;
guint32 usecs;
double t;
if (visual->current_pkt > visual->num_pkts)
{
*err = 0;
return FALSE;
}
visual->current_pkt++;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&vpkt_hdr, phdr_size, wth->fh);
if (bytes_read != phdr_size)
{
*err = file_error(wth->fh, err_info);
if (*err == 0 && bytes_read != 0)
{
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
packet_size = pletohs(&vpkt_hdr.incl_len);
if (wth->file_encap == WTAP_ENCAP_ATM_PDUS)
{
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&vatm_hdr, ahdr_size, wth->fh);
if (bytes_read != ahdr_size)
{
*err = file_error(wth->fh, err_info);
if (*err == 0 && bytes_read != 0)
{
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
packet_size -= ahdr_size;
}
if (packet_size > WTAP_MAX_PACKET_SIZE)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("visual: File has %u-byte packet, bigger than maximum of %u",
packet_size, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
buffer_assure_space(wth->frame_buffer, packet_size);
*data_offset = file_tell(wth->fh);
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(buffer_start_ptr(wth->frame_buffer),
packet_size, wth->fh);
if (bytes_read != (int) packet_size)
{
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
wth->phdr.presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
t = visual->start_time;
t += ((double)pletohl(&vpkt_hdr.ts_delta))*1000;
secs = (time_t)(t/1000000);
usecs = (guint32)(t - secs*1000000);
wth->phdr.ts.secs = secs;
wth->phdr.ts.nsecs = usecs * 1000;
wth->phdr.caplen = packet_size;
wth->phdr.len = pletohs(&vpkt_hdr.orig_len);
switch (wth->file_encap)
{
case WTAP_ENCAP_ETHERNET:
wth->phdr.len -= 4;
break;
case WTAP_ENCAP_FRELAY_WITH_PHDR:
case WTAP_ENCAP_CHDLC_WITH_PHDR:
case WTAP_ENCAP_LAPB:
wth->phdr.len -= 2;
break;
case WTAP_ENCAP_ATM_PDUS:
case WTAP_ENCAP_TOKEN_RING:
default:
break;
}
if (wth->phdr.len > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("visual: File has %u-byte original packet, bigger than maximum of %u",
wth->phdr.len, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
if (wth->phdr.len < wth->phdr.caplen)
{
wth->phdr.len = wth->phdr.caplen;
}
visual_set_pseudo_header(wth->file_encap, &vpkt_hdr, &vatm_hdr, &wth->pseudo_header);
if (wth->file_encap == WTAP_ENCAP_CHDLC_WITH_PHDR)
{
if (vpkt_hdr.encap_hint == 14)
{
guint8 *buf = buffer_start_ptr(wth->frame_buffer);
if ((0xfe == buf[0]) && (0xfe == buf[1]) && (0x03 == buf[2]))
{
wth->phdr.pkt_encap = WTAP_ENCAP_ATM_RFC1483;
}
else
{
wth->phdr.pkt_encap = WTAP_ENCAP_PPP_WITH_PHDR;
}
}
else
{
guint8 *buf = buffer_start_ptr(wth->frame_buffer);
if ((0xff == buf[0]) && (0x03 == buf[1]))
{
wth->phdr.pkt_encap = WTAP_ENCAP_PPP_WITH_PHDR;
}
}
}
return TRUE;
}
static gboolean visual_seek_read (wtap *wth, gint64 seek_off,
union wtap_pseudo_header *pseudo_header, guint8 *pd, int len,
int *err, gchar **err_info)
{
struct visual_pkt_hdr vpkt_hdr;
struct visual_atm_hdr vatm_hdr;
int phdr_size = sizeof(vpkt_hdr);
int ahdr_size = sizeof(vatm_hdr);
int bytes_read;
int header_size;
header_size = sizeof(struct visual_pkt_hdr);
if (wth->file_encap == WTAP_ENCAP_ATM_PDUS)
{
header_size += (int)sizeof(struct visual_atm_hdr);
}
if (file_seek(wth->random_fh, seek_off - header_size,
SEEK_SET, err) == -1)
return FALSE;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&vpkt_hdr, phdr_size, wth->random_fh);
if (bytes_read != phdr_size) {
*err = file_error(wth->random_fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
if (wth->file_encap == WTAP_ENCAP_ATM_PDUS)
{
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&vatm_hdr, ahdr_size, wth->random_fh);
if (bytes_read != ahdr_size)
{
*err = file_error(wth->fh, err_info);
if (*err == 0 && bytes_read != 0)
{
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
}
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(pd, len, wth->random_fh);
if (bytes_read != len) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
visual_set_pseudo_header(wth->file_encap, &vpkt_hdr, &vatm_hdr, pseudo_header);
return TRUE;
}
static void visual_set_pseudo_header(int encap, struct visual_pkt_hdr *vpkt_hdr,
struct visual_atm_hdr *vatm_hdr, union wtap_pseudo_header *pseudo_header)
{
guint32 packet_status;
packet_status = pletohl(&vpkt_hdr->status);
switch (encap)
{
case WTAP_ENCAP_ETHERNET:
pseudo_header->eth.fcs_len = -1;
break;
case WTAP_ENCAP_CHDLC_WITH_PHDR:
case WTAP_ENCAP_PPP_WITH_PHDR:
pseudo_header->p2p.sent = (packet_status & PS_SENT) ? TRUE : FALSE;
break;
case WTAP_ENCAP_FRELAY_WITH_PHDR:
case WTAP_ENCAP_LAPB:
pseudo_header->x25.flags =
(packet_status & PS_SENT) ? 0x00 : FROM_DCE;
break;
case WTAP_ENCAP_ATM_PDUS:
pseudo_header->atm.type = TRAF_UNKNOWN;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
pseudo_header->atm.aal5t_len = 0;
pseudo_header->atm.aal5t_u2u = 0;
pseudo_header->atm.aal5t_chksum = 0;
pseudo_header->atm.flags = 0;
pseudo_header->atm.aal2_cid = 0;
switch(vatm_hdr->category & VN_CAT_TYPE_MASK )
{
case VN_AAL1:
pseudo_header->atm.aal = AAL_1;
break;
case VN_AAL2:
pseudo_header->atm.aal = AAL_2;
break;
case VN_AAL34:
pseudo_header->atm.aal = AAL_3_4;
break;
case VN_AAL5:
pseudo_header->atm.aal = AAL_5;
pseudo_header->atm.type = TRAF_LLCMX;
pseudo_header->atm.aal5t_len = pntohl(&vatm_hdr->data_length);
break;
case VN_OAM:
case VN_O191:
case VN_IDLE:
case VN_RM:
pseudo_header->atm.aal = AAL_OAMCELL;
break;
case VN_UNKNOWN:
default:
pseudo_header->atm.aal = AAL_UNKNOWN;
break;
}
pseudo_header->atm.vpi = pntohs(&vatm_hdr->vpi) & 0x0FFF;
pseudo_header->atm.vci = pntohs(&vatm_hdr->vci);
pseudo_header->atm.cells = pntohs(&vatm_hdr->cell_count);
pseudo_header->atm.channel = vatm_hdr->info & FROM_NETWORK;
break;
}
}
int visual_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_PER_PACKET)
return WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED;
switch (encap)
{
case WTAP_ENCAP_ETHERNET:
case WTAP_ENCAP_TOKEN_RING:
case WTAP_ENCAP_LAPB:
case WTAP_ENCAP_CHDLC_WITH_PHDR:
case WTAP_ENCAP_FRELAY_WITH_PHDR:
case WTAP_ENCAP_PPP:
case WTAP_ENCAP_PPP_WITH_PHDR:
return 0;
}
return WTAP_ERR_UNSUPPORTED_ENCAP;
}
gboolean visual_dump_open(wtap_dumper *wdh, int *err)
{
struct visual_write_info *visual;
wdh->subtype_write = visual_dump;
wdh->subtype_close = visual_dump_close;
visual = (struct visual_write_info *)g_malloc(sizeof(struct visual_write_info));
wdh->priv = (void *)visual;
visual->index_table_index = 0;
visual->index_table_size = 1024;
visual->index_table = 0;
visual->next_offset = CAPTUREFILE_HEADER_SIZE;
if (fseek(wdh->fh, CAPTUREFILE_HEADER_SIZE, SEEK_SET) == -1) {
*err = errno;
return FALSE;
}
return TRUE;
}
static gboolean visual_dump(wtap_dumper *wdh, const struct wtap_pkthdr *phdr,
const union wtap_pseudo_header *pseudo_header, const guint8 *pd, int *err)
{
struct visual_write_info * visual = (struct visual_write_info *)wdh->priv;
struct visual_pkt_hdr vpkt_hdr;
size_t hdr_size = sizeof vpkt_hdr;
unsigned delta_msec;
guint32 packet_status;
if (visual == 0)
return FALSE;
memset(&vpkt_hdr, 0, hdr_size);
if (visual->index_table_index == 0)
{
visual->start_time = (guint32) phdr->ts.secs;
visual->index_table = (guint32 *)g_malloc(1024 * sizeof *visual->index_table);
visual->index_table_size = 1024;
}
delta_msec = phdr->ts.nsecs / 1000000;
delta_msec += ( (guint32) phdr->ts.secs - visual->start_time) * 1000;
vpkt_hdr.ts_delta = htolel(delta_msec);
vpkt_hdr.orig_len = htoles(phdr->len);
vpkt_hdr.incl_len = htoles(phdr->caplen);
switch (wdh->encap)
{
case WTAP_ENCAP_ETHERNET:
vpkt_hdr.encap_hint = 2;
break;
case WTAP_ENCAP_TOKEN_RING:
vpkt_hdr.encap_hint = 3;
break;
case WTAP_ENCAP_PPP:
case WTAP_ENCAP_PPP_WITH_PHDR:
vpkt_hdr.encap_hint = 14;
break;
case WTAP_ENCAP_CHDLC_WITH_PHDR:
vpkt_hdr.encap_hint = 13;
break;
case WTAP_ENCAP_FRELAY_WITH_PHDR:
vpkt_hdr.encap_hint = 12;
break;
case WTAP_ENCAP_LAPB:
default:
vpkt_hdr.encap_hint = 1;
break;
}
packet_status = 0;
switch (wdh->encap)
{
case WTAP_ENCAP_CHDLC_WITH_PHDR:
packet_status |= (pseudo_header->p2p.sent ? PS_SENT : 0x00);
break;
case WTAP_ENCAP_FRELAY_WITH_PHDR:
case WTAP_ENCAP_LAPB:
packet_status |=
((pseudo_header->x25.flags & FROM_DCE) ? 0x00 : PS_SENT);
break;
}
vpkt_hdr.status = htolel(packet_status);
if (!wtap_dump_file_write(wdh, &vpkt_hdr, hdr_size, err))
return FALSE;
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
if (visual->index_table_index >= visual->index_table_size)
{
visual->index_table_size *= 2;
visual->index_table = (guint32 *)g_realloc(visual->index_table,
visual->index_table_size * sizeof *visual->index_table);
}
visual->index_table[visual->index_table_index] = htolel(visual->next_offset);
visual->index_table_index++;
visual->next_offset += (guint32) hdr_size + phdr->caplen;
return TRUE;
}
static gboolean visual_dump_close(wtap_dumper *wdh, int *err)
{
struct visual_write_info * visual = (struct visual_write_info *)wdh->priv;
size_t n_to_write;
struct visual_file_hdr vfile_hdr;
const char *magicp;
size_t magic_size;
if (visual == 0)
return FALSE;
if (visual->index_table)
{
n_to_write = visual->index_table_index * sizeof *visual->index_table;
if (!wtap_dump_file_write(wdh, visual->index_table, n_to_write, err))
{
visual_dump_free(wdh);
return FALSE;
}
}
fseek(wdh->fh, 0, SEEK_SET);
magicp = visual_magic;
magic_size = sizeof visual_magic;
if (!wtap_dump_file_write(wdh, magicp, magic_size, err))
{
visual_dump_free(wdh);
return FALSE;
}
memset(&vfile_hdr, '\0', sizeof vfile_hdr);
vfile_hdr.num_pkts = htolel(visual->index_table_index);
vfile_hdr.start_time = htolel(visual->start_time);
vfile_hdr.max_length = htoles(65535);
vfile_hdr.file_flags = htoles(1);
vfile_hdr.file_version = htoles(1);
g_strlcpy(vfile_hdr.description, "Wireshark file", 64);
switch (wdh->encap)
{
case WTAP_ENCAP_ETHERNET:
vfile_hdr.media_type = htoles(6);
break;
case WTAP_ENCAP_TOKEN_RING:
vfile_hdr.media_type = htoles(9);
break;
case WTAP_ENCAP_LAPB:
vfile_hdr.media_type = htoles(16);
break;
case WTAP_ENCAP_PPP:
case WTAP_ENCAP_PPP_WITH_PHDR:
case WTAP_ENCAP_CHDLC_WITH_PHDR:
vfile_hdr.media_type = htoles(22);
break;
case WTAP_ENCAP_FRELAY_WITH_PHDR:
vfile_hdr.media_type = htoles(32);
break;
}
if (!wtap_dump_file_write(wdh, &vfile_hdr, sizeof vfile_hdr, err))
{
visual_dump_free(wdh);
return FALSE;
}
visual_dump_free(wdh);
return TRUE;
}
static void visual_dump_free(wtap_dumper *wdh)
{
struct visual_write_info * visual = (struct visual_write_info *)wdh->priv;
if (visual)
{
if (visual->index_table)
g_free(visual->index_table);
}
}
