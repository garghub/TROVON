wtap_open_return_val visual_open(wtap *wth, int *err, gchar **err_info)
{
char magic[sizeof visual_magic];
struct visual_file_hdr vfile_hdr;
struct visual_read_info * visual;
int encap;
if (!wtap_read_bytes(wth->fh, magic, sizeof magic, err, err_info))
{
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if (memcmp(magic, visual_magic, sizeof visual_magic) != 0)
{
return WTAP_OPEN_NOT_MINE;
}
if (!wtap_read_bytes(wth->fh, &vfile_hdr, sizeof vfile_hdr, err, err_info))
{
return WTAP_OPEN_ERROR;
}
vfile_hdr.file_version = pletoh16(&vfile_hdr.file_version);
if (vfile_hdr.file_version != 1)
{
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("visual: file version %u unsupported", vfile_hdr.file_version);
return WTAP_OPEN_ERROR;
}
switch (pletoh16(&vfile_hdr.media_type))
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
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("visual: network type %u unknown or unsupported",
vfile_hdr.media_type);
return WTAP_OPEN_ERROR;
}
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_VISUAL_NETWORKS;
wth->file_encap = encap;
wth->snapshot_length = pletoh16(&vfile_hdr.max_length);
wth->subtype_read = visual_read;
wth->subtype_seek_read = visual_seek_read;
wth->file_tsprec = WTAP_TSPREC_MSEC;
visual = (struct visual_read_info *)g_malloc(sizeof(struct visual_read_info));
wth->priv = (void *)visual;
visual->num_pkts = pletoh32(&vfile_hdr.num_pkts);
visual->start_time = pletoh32(&vfile_hdr.start_time);
visual->current_pkt = 1;
return WTAP_OPEN_MINE;
}
static gboolean visual_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
struct visual_read_info *visual = (struct visual_read_info *)wth->priv;
if (visual->current_pkt > visual->num_pkts)
{
*err = 0;
return FALSE;
}
visual->current_pkt++;
*data_offset = file_tell(wth->fh);
return visual_read_packet(wth, wth->fh, &wth->phdr, wth->frame_buffer,
err, err_info);
}
static gboolean visual_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!visual_read_packet(wth, wth->random_fh, phdr, buf, err, err_info)) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static gboolean
visual_read_packet(wtap *wth, FILE_T fh, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
struct visual_read_info *visual = (struct visual_read_info *)wth->priv;
struct visual_pkt_hdr vpkt_hdr;
guint32 packet_size;
struct visual_atm_hdr vatm_hdr;
guint32 relmsecs;
guint32 packet_status;
guint8 *pd;
if (!wtap_read_bytes_or_eof(fh, &vpkt_hdr, (unsigned int)sizeof vpkt_hdr, err, err_info))
{
return FALSE;
}
packet_size = pletoh16(&vpkt_hdr.incl_len);
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
relmsecs = pletoh32(&vpkt_hdr.ts_delta);
phdr->ts.secs = visual->start_time + relmsecs/1000;
phdr->ts.nsecs = (relmsecs % 1000)*1000000;
phdr->len = pletoh16(&vpkt_hdr.orig_len);
packet_status = pletoh32(&vpkt_hdr.status);
switch (wth->file_encap)
{
case WTAP_ENCAP_ETHERNET:
if (phdr->len < 4)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("visual: Ethernet packet has %u-byte original packet, less than the FCS length",
phdr->len);
return FALSE;
}
phdr->len -= 4;
phdr->pseudo_header.eth.fcs_len = -1;
break;
case WTAP_ENCAP_CHDLC_WITH_PHDR:
if (phdr->len < 2)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("visual: Cisco HDLC packet has %u-byte original packet, less than the FCS length",
phdr->len);
return FALSE;
}
phdr->len -= 2;
phdr->pseudo_header.p2p.sent = (packet_status & PS_SENT) ? TRUE : FALSE;
break;
case WTAP_ENCAP_PPP_WITH_PHDR:
phdr->pseudo_header.p2p.sent = (packet_status & PS_SENT) ? TRUE : FALSE;
break;
case WTAP_ENCAP_FRELAY_WITH_PHDR:
if (phdr->len < 2)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("visual: Frame Relay packet has %u-byte original packet, less than the FCS length",
phdr->len);
return FALSE;
}
phdr->len -= 2;
phdr->pseudo_header.x25.flags =
(packet_status & PS_SENT) ? 0x00 : FROM_DCE;
break;
case WTAP_ENCAP_LAPB:
if (phdr->len < 2)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("visual: Frame Relay packet has %u-byte original packet, less than the FCS length",
phdr->len);
return FALSE;
}
phdr->len -= 2;
phdr->pseudo_header.x25.flags =
(packet_status & PS_SENT) ? 0x00 : FROM_DCE;
break;
case WTAP_ENCAP_ATM_PDUS:
if (!wtap_read_bytes(fh, &vatm_hdr, (unsigned int)sizeof vatm_hdr, err, err_info))
{
return FALSE;
}
packet_size -= (guint32)sizeof vatm_hdr;
phdr->pseudo_header.atm.type = TRAF_UNKNOWN;
phdr->pseudo_header.atm.subtype = TRAF_ST_UNKNOWN;
phdr->pseudo_header.atm.aal5t_len = 0;
phdr->pseudo_header.atm.aal5t_u2u = 0;
phdr->pseudo_header.atm.aal5t_chksum = 0;
phdr->pseudo_header.atm.flags = 0;
phdr->pseudo_header.atm.aal2_cid = 0;
switch(vatm_hdr.category & VN_CAT_TYPE_MASK )
{
case VN_AAL1:
phdr->pseudo_header.atm.aal = AAL_1;
break;
case VN_AAL2:
phdr->pseudo_header.atm.aal = AAL_2;
break;
case VN_AAL34:
phdr->pseudo_header.atm.aal = AAL_3_4;
break;
case VN_AAL5:
phdr->pseudo_header.atm.aal = AAL_5;
phdr->pseudo_header.atm.type = TRAF_LLCMX;
phdr->pseudo_header.atm.aal5t_len = pntoh32(&vatm_hdr.data_length);
break;
case VN_OAM:
case VN_O191:
case VN_IDLE:
case VN_RM:
phdr->pseudo_header.atm.aal = AAL_OAMCELL;
break;
case VN_UNKNOWN:
default:
phdr->pseudo_header.atm.aal = AAL_UNKNOWN;
break;
}
phdr->pseudo_header.atm.vpi = pntoh16(&vatm_hdr.vpi) & 0x0FFF;
phdr->pseudo_header.atm.vci = pntoh16(&vatm_hdr.vci);
phdr->pseudo_header.atm.cells = pntoh16(&vatm_hdr.cell_count);
phdr->pseudo_header.atm.channel = vatm_hdr.info & FROM_NETWORK;
break;
case WTAP_ENCAP_TOKEN_RING:
default:
break;
}
phdr->caplen = packet_size;
if (packet_size > WTAP_MAX_PACKET_SIZE)
{
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("visual: File has %u-byte packet, bigger than maximum of %u",
packet_size, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
if (!wtap_read_packet_bytes(fh, buf, packet_size, err, err_info))
return FALSE;
if (wth->file_encap == WTAP_ENCAP_CHDLC_WITH_PHDR)
{
pd = ws_buffer_start_ptr(buf);
if (vpkt_hdr.encap_hint == 14)
{
if (packet_size >= 3 &&
(0xfe == pd[0]) && (0xfe == pd[1]) && (0x03 == pd[2]))
{
phdr->pkt_encap = WTAP_ENCAP_ATM_RFC1483;
}
else
{
phdr->pkt_encap = WTAP_ENCAP_PPP_WITH_PHDR;
}
}
else
{
if (packet_size >= 2 && (0xff == pd[0]) && (0x03 == pd[1]))
{
phdr->pkt_encap = WTAP_ENCAP_PPP_WITH_PHDR;
}
}
}
return TRUE;
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
return WTAP_ERR_UNWRITABLE_ENCAP;
}
gboolean visual_dump_open(wtap_dumper *wdh, int *err)
{
struct visual_write_info *visual;
wdh->subtype_write = visual_dump;
wdh->subtype_finish = visual_dump_finish;
visual = (struct visual_write_info *)g_malloc(sizeof(struct visual_write_info));
wdh->priv = (void *)visual;
visual->index_table_index = 0;
visual->index_table_size = 1024;
visual->index_table = 0;
visual->next_offset = CAPTUREFILE_HEADER_SIZE;
if (wtap_dump_file_seek(wdh, CAPTUREFILE_HEADER_SIZE, SEEK_SET, err) == -1)
return FALSE;
return TRUE;
}
static gboolean visual_dump(wtap_dumper *wdh, const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err, gchar **err_info _U_)
{
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
struct visual_write_info * visual = (struct visual_write_info *)wdh->priv;
struct visual_pkt_hdr vpkt_hdr;
size_t hdr_size = sizeof vpkt_hdr;
guint delta_msec;
guint32 packet_status;
if (phdr->rec_type != REC_TYPE_PACKET) {
*err = WTAP_ERR_UNWRITABLE_REC_TYPE;
return FALSE;
}
if (phdr->caplen > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
if (visual == 0)
return FALSE;
memset(&vpkt_hdr, 0, hdr_size);
if (visual->index_table_index == 0)
{
visual->start_time = phdr->ts.secs;
visual->index_table = (guint32 *)g_malloc(1024 * sizeof *visual->index_table);
visual->index_table_size = 1024;
}
delta_msec = phdr->ts.nsecs / 1000000;
delta_msec += (guint32)((phdr->ts.secs - visual->start_time) * 1000);
vpkt_hdr.ts_delta = GUINT32_TO_LE(delta_msec);
vpkt_hdr.orig_len = GUINT16_TO_LE(phdr->len);
vpkt_hdr.incl_len = GUINT16_TO_LE(phdr->caplen);
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
vpkt_hdr.status = GUINT32_TO_LE(packet_status);
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
visual->index_table[visual->index_table_index] = GUINT32_TO_LE(visual->next_offset);
visual->index_table_index++;
visual->next_offset += (guint32) hdr_size + phdr->caplen;
return TRUE;
}
static gboolean visual_dump_finish(wtap_dumper *wdh, int *err)
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
if (wtap_dump_file_seek(wdh, 0, SEEK_SET, err) == -1)
return FALSE;
magicp = visual_magic;
magic_size = sizeof visual_magic;
if (!wtap_dump_file_write(wdh, magicp, magic_size, err))
{
visual_dump_free(wdh);
return FALSE;
}
memset(&vfile_hdr, '\0', sizeof vfile_hdr);
vfile_hdr.num_pkts = GUINT32_TO_LE(visual->index_table_index);
vfile_hdr.start_time = GUINT32_TO_LE(visual->start_time);
vfile_hdr.max_length = GUINT16_TO_LE(65535);
vfile_hdr.file_flags = GUINT16_TO_LE(1);
vfile_hdr.file_version = GUINT16_TO_LE(1);
g_strlcpy(vfile_hdr.description, "Wireshark file", 64);
switch (wdh->encap)
{
case WTAP_ENCAP_ETHERNET:
vfile_hdr.media_type = GUINT16_TO_LE(6);
break;
case WTAP_ENCAP_TOKEN_RING:
vfile_hdr.media_type = GUINT16_TO_LE(9);
break;
case WTAP_ENCAP_LAPB:
vfile_hdr.media_type = GUINT16_TO_LE(16);
break;
case WTAP_ENCAP_PPP:
case WTAP_ENCAP_PPP_WITH_PHDR:
case WTAP_ENCAP_CHDLC_WITH_PHDR:
vfile_hdr.media_type = GUINT16_TO_LE(22);
break;
case WTAP_ENCAP_FRELAY_WITH_PHDR:
vfile_hdr.media_type = GUINT16_TO_LE(32);
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
