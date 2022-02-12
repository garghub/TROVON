int netxray_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
char magic[MAGIC_SIZE];
gboolean is_old;
struct netxray_hdr hdr;
guint network_type;
double ticks_per_sec;
int version_major, version_minor;
int file_type;
double start_timestamp;
static const int netxray_encap[] = {
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_ETHERNET,
WTAP_ENCAP_TOKEN_RING,
WTAP_ENCAP_FDDI_BITSWAPPED,
WTAP_ENCAP_ETHERNET,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_ATM_PDUS_UNTRUNCATED,
WTAP_ENCAP_IEEE_802_11_WITH_RADIO,
WTAP_ENCAP_UNKNOWN
};
#define NUM_NETXRAY_ENCAPS (sizeof netxray_encap / sizeof netxray_encap[0])
int file_encap;
guint isdn_type = 0;
netxray_t *netxray;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(magic, MAGIC_SIZE, wth->fh);
if (bytes_read != MAGIC_SIZE) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if (memcmp(magic, netxray_magic, MAGIC_SIZE) == 0) {
is_old = FALSE;
} else if (memcmp(magic, old_netxray_magic, MAGIC_SIZE) == 0) {
is_old = TRUE;
} else {
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
if (is_old) {
version_major = 0;
version_minor = 0;
file_type = WTAP_FILE_NETXRAY_OLD;
} else {
if (memcmp(hdr.version, vers_1_0, sizeof vers_1_0) == 0) {
version_major = 1;
version_minor = 0;
file_type = WTAP_FILE_NETXRAY_1_0;
} else if (memcmp(hdr.version, vers_1_1, sizeof vers_1_1) == 0) {
version_major = 1;
version_minor = 1;
file_type = WTAP_FILE_NETXRAY_1_1;
} else if (memcmp(hdr.version, vers_2_000, sizeof vers_2_000) == 0) {
version_major = 2;
version_minor = 0;
file_type = WTAP_FILE_NETXRAY_2_00x;
} else if (memcmp(hdr.version, vers_2_001, sizeof vers_2_001) == 0) {
version_major = 2;
version_minor = 1;
file_type = WTAP_FILE_NETXRAY_2_00x;
} else if (memcmp(hdr.version, vers_2_002, sizeof vers_2_002) == 0) {
version_major = 2;
version_minor = 2;
file_type = WTAP_FILE_NETXRAY_2_00x;
} else if (memcmp(hdr.version, vers_2_003, sizeof vers_2_003) == 0) {
version_major = 2;
version_minor = 3;
file_type = WTAP_FILE_NETXRAY_2_00x;
} else {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("netxray: version \"%.8s\" unsupported", hdr.version);
return -1;
}
}
switch (hdr.network_plus) {
case 0:
network_type = hdr.network + 1;
break;
case 2:
network_type = hdr.network;
break;
default:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("netxray: the byte after the network type has the value %u, which I don't understand",
hdr.network_plus);
return -1;
}
if (network_type >= NUM_NETXRAY_ENCAPS
|| netxray_encap[network_type] == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("netxray: network type %u (%u) unknown or unsupported",
network_type, hdr.network_plus);
return -1;
}
start_timestamp = (double)pletohl(&hdr.timelo)
+ (double)pletohl(&hdr.timehi)*4294967296.0;
switch (file_type) {
case WTAP_FILE_NETXRAY_OLD:
ticks_per_sec = 1000.0;
wth->tsprecision = WTAP_FILE_TSPREC_MSEC;
break;
case WTAP_FILE_NETXRAY_1_0:
ticks_per_sec = 1000.0;
wth->tsprecision = WTAP_FILE_TSPREC_MSEC;
break;
case WTAP_FILE_NETXRAY_1_1:
ticks_per_sec = 1000000.0;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
break;
case WTAP_FILE_NETXRAY_2_00x:
switch (network_type) {
case 1:
switch (hdr.captype) {
case CAPTYPE_NDIS:
if (hdr.timeunit >= NUM_NETXRAY_TIMEUNITS) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf(
"netxray: Unknown timeunit %u for Ethernet/CAPTYPE_NDIS version %.8s capture",
hdr.timeunit, hdr.version);
return -1;
}
if (hdr.timeunit == 2) {
ticks_per_sec = pletohl(hdr.realtick);
}
else {
ticks_per_sec = TpS[hdr.timeunit];
}
break;
case ETH_CAPTYPE_GIGPOD:
if (hdr.timeunit >= NUM_NETXRAY_TIMEUNITS_GIGPOD
|| TpS_gigpod[hdr.timeunit] == 0.0) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf(
"netxray: Unknown timeunit %u for Ethernet/ETH_CAPTYPE_GIGPOD version %.8s capture",
hdr.timeunit, hdr.version);
return -1;
}
ticks_per_sec = TpS_gigpod[hdr.timeunit];
if (version_minor == 2 || version_minor == 3)
start_timestamp = 0.0;
break;
case ETH_CAPTYPE_OTHERPOD:
if (hdr.timeunit >= NUM_NETXRAY_TIMEUNITS_OTHERPOD
|| TpS_otherpod[hdr.timeunit] == 0.0) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf(
"netxray: Unknown timeunit %u for Ethernet/ETH_CAPTYPE_OTHERPOD version %.8s capture",
hdr.timeunit, hdr.version);
return -1;
}
ticks_per_sec = TpS_otherpod[hdr.timeunit];
if (version_minor == 2 || version_minor == 3)
start_timestamp = 0.0;
break;
case ETH_CAPTYPE_OTHERPOD2:
if (hdr.timeunit >= NUM_NETXRAY_TIMEUNITS_OTHERPOD2
|| TpS_otherpod2[hdr.timeunit] == 0.0) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf(
"netxray: Unknown timeunit %u for Ethernet/ETH_CAPTYPE_OTHERPOD2 version %.8s capture",
hdr.timeunit, hdr.version);
return -1;
}
ticks_per_sec = TpS_otherpod2[hdr.timeunit];
if (version_minor == 2 || version_minor == 3)
start_timestamp = 0.0;
break;
case ETH_CAPTYPE_GIGPOD2:
if (hdr.timeunit >= NUM_NETXRAY_TIMEUNITS_GIGPOD2
|| TpS_gigpod2[hdr.timeunit] == 0.0) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf(
"netxray: Unknown timeunit %u for Ethernet/ETH_CAPTYPE_GIGPOD2 version %.8s capture",
hdr.timeunit, hdr.version);
return -1;
}
ticks_per_sec = TpS_gigpod2[hdr.timeunit];
if (version_minor == 2 || version_minor == 3)
start_timestamp = 0.0;
break;
default:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf(
"netxray: Unknown capture type %u for Ethernet version %.8s capture",
hdr.captype, hdr.version);
return -1;
}
break;
default:
if (hdr.timeunit >= NUM_NETXRAY_TIMEUNITS) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf(
"netxray: Unknown timeunit %u for %u/%u version %.8s capture",
hdr.timeunit, network_type, hdr.captype,
hdr.version);
return -1;
}
ticks_per_sec = TpS[hdr.timeunit];
break;
}
if (ticks_per_sec >= 1e7)
wth->tsprecision = WTAP_FILE_TSPREC_NSEC;
else
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
break;
default:
g_assert_not_reached();
ticks_per_sec = 0.0;
}
start_timestamp = start_timestamp/ticks_per_sec;
if (network_type == 4) {
if (version_major == 2) {
switch (hdr.captype) {
case WAN_CAPTYPE_PPP:
file_encap = WTAP_ENCAP_PPP_WITH_PHDR;
break;
case WAN_CAPTYPE_FRELAY:
file_encap = WTAP_ENCAP_FRELAY_WITH_PHDR;
break;
case WAN_CAPTYPE_HDLC:
case WAN_CAPTYPE_HDLC2:
switch (hdr.wan_hdlc_subsub_captype) {
case 0:
file_encap = WTAP_ENCAP_LAPB;
break;
case 1:
case 2:
case 3:
file_encap = WTAP_ENCAP_ISDN;
isdn_type = hdr.wan_hdlc_subsub_captype;
break;
default:
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("netxray: WAN HDLC capture subsubtype 0x%02x unknown or unsupported",
hdr.wan_hdlc_subsub_captype);
return -1;
}
break;
case WAN_CAPTYPE_SDLC:
file_encap = WTAP_ENCAP_SDLC;
break;
case WAN_CAPTYPE_CHDLC:
file_encap = WTAP_ENCAP_CHDLC_WITH_PHDR;
break;
default:
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("netxray: WAN capture subtype 0x%02x unknown or unsupported",
hdr.captype);
return -1;
}
} else
file_encap = WTAP_ENCAP_ETHERNET;
} else
file_encap = netxray_encap[network_type];
wth->file_type = file_type;
netxray = (netxray_t *)g_malloc(sizeof(netxray_t));
wth->priv = (void *)netxray;
wth->subtype_read = netxray_read;
wth->subtype_seek_read = netxray_seek_read;
wth->file_encap = file_encap;
wth->snapshot_length = 0;
netxray->start_time = pletohl(&hdr.start_time);
netxray->ticks_per_sec = ticks_per_sec;
netxray->start_timestamp = start_timestamp;
netxray->version_major = version_major;
netxray->fcs_valid = FALSE;
switch (file_encap) {
case WTAP_ENCAP_ETHERNET:
case WTAP_ENCAP_IEEE_802_11_WITH_RADIO:
case WTAP_ENCAP_ISDN:
case WTAP_ENCAP_LAPB:
if (version_major == 2) {
if (hdr.realtick[1] == 0x34 && hdr.realtick[2] == 0x12)
netxray->fcs_valid = TRUE;
}
break;
}
netxray->isdn_type = isdn_type;
netxray->wrapped = FALSE;
netxray->nframes = pletohl(&hdr.nframes);
netxray->start_offset = pletohl(&hdr.start_offset);
netxray->end_offset = pletohl(&hdr.end_offset);
if (file_seek(wth->fh, netxray->start_offset, SEEK_SET, err) == -1) {
return -1;
}
return 1;
}
static gboolean netxray_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
netxray_t *netxray = (netxray_t *)wth->priv;
guint32 packet_size;
union netxrayrec_hdr hdr;
int hdr_size;
reread:
*data_offset = file_tell(wth->fh);
if (*data_offset == netxray->end_offset) {
*err = 0;
return FALSE;
}
hdr_size = netxray_read_rec_header(wth, wth->fh, &hdr, err, err_info);
if (hdr_size == 0) {
if (*err != 0) {
return FALSE;
}
if (netxray->start_offset < netxray->end_offset) {
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
if (!netxray->wrapped) {
netxray->wrapped = TRUE;
if (file_seek(wth->fh, CAPTUREFILE_HEADER_SIZE,
SEEK_SET, err) == -1)
return FALSE;
goto reread;
}
return FALSE;
}
if (netxray->version_major == 0)
packet_size = pletohs(&hdr.old_hdr.len);
else
packet_size = pletohs(&hdr.hdr_1_x.incl_len);
if (!wtap_read_packet_bytes(wth->fh, wth->frame_buffer, packet_size,
err, err_info))
return FALSE;
netxray_set_phdr(wth, wth->frame_buffer, packet_size, &wth->phdr, &hdr);
return TRUE;
}
static gboolean
netxray_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int length,
int *err, gchar **err_info)
{
union netxrayrec_hdr hdr;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!netxray_read_rec_header(wth, wth->random_fh, &hdr, err,
err_info)) {
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
if (!wtap_read_packet_bytes(wth->random_fh, buf, length, err, err_info))
return FALSE;
netxray_set_phdr(wth, buf, length, phdr, &hdr);
return TRUE;
}
static int
netxray_read_rec_header(wtap *wth, FILE_T fh, union netxrayrec_hdr *hdr,
int *err, gchar **err_info)
{
netxray_t *netxray = (netxray_t *)wth->priv;
int bytes_read;
int hdr_size = 0;
switch (netxray->version_major) {
case 0:
hdr_size = sizeof (struct old_netxrayrec_hdr);
break;
case 1:
hdr_size = sizeof (struct netxrayrec_1_x_hdr);
break;
case 2:
hdr_size = sizeof (struct netxrayrec_2_x_hdr);
break;
}
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(hdr, hdr_size, fh);
if (bytes_read != hdr_size) {
*err = file_error(wth->fh, err_info);
if (*err != 0)
return 0;
if (bytes_read != 0) {
*err = WTAP_ERR_SHORT_READ;
return 0;
}
return 0;
}
return hdr_size;
}
static void
netxray_set_phdr(wtap *wth, Buffer *buf, int len,
struct wtap_pkthdr *phdr, union netxrayrec_hdr *hdr)
{
netxray_t *netxray = (netxray_t *)wth->priv;
double t;
guint32 packet_size;
guint padding = 0;
const guint8 *pd;
switch (netxray->version_major) {
case 1:
switch (wth->file_encap) {
case WTAP_ENCAP_ETHERNET:
phdr->pseudo_header.eth.fcs_len = 0;
break;
}
break;
case 2:
switch (wth->file_encap) {
case WTAP_ENCAP_ETHERNET:
if (hdr->hdr_2_x.xxx[2] == 0xff &&
hdr->hdr_2_x.xxx[3] == 0xff) {
if (netxray->fcs_valid) {
phdr->pseudo_header.eth.fcs_len = 4;
} else {
padding = 4;
}
} else
phdr->pseudo_header.eth.fcs_len = 0;
break;
case WTAP_ENCAP_IEEE_802_11_WITH_RADIO:
if (hdr->hdr_2_x.xxx[2] == 0xff &&
hdr->hdr_2_x.xxx[3] == 0xff) {
if (netxray->fcs_valid) {
phdr->pseudo_header.ieee_802_11.fcs_len = 4;
} else {
padding = 4;
}
} else
phdr->pseudo_header.ieee_802_11.fcs_len = 0;
phdr->pseudo_header.ieee_802_11.decrypted = FALSE;
phdr->pseudo_header.ieee_802_11.channel =
hdr->hdr_2_x.xxx[12];
phdr->pseudo_header.ieee_802_11.data_rate =
hdr->hdr_2_x.xxx[13];
phdr->pseudo_header.ieee_802_11.signal_level =
hdr->hdr_2_x.xxx[14];
break;
case WTAP_ENCAP_ISDN:
phdr->pseudo_header.isdn.uton =
(hdr->hdr_2_x.xxx[12] & 0x01);
phdr->pseudo_header.isdn.channel =
hdr->hdr_2_x.xxx[13] & 0x1F;
switch (netxray->isdn_type) {
case 1:
if (phdr->pseudo_header.isdn.channel == 16)
phdr->pseudo_header.isdn.channel = 0;
else if (phdr->pseudo_header.isdn.channel > 16)
phdr->pseudo_header.isdn.channel -= 1;
break;
case 2:
if (phdr->pseudo_header.isdn.channel == 24)
phdr->pseudo_header.isdn.channel = 0;
else if (phdr->pseudo_header.isdn.channel > 24)
phdr->pseudo_header.isdn.channel -= 1;
break;
}
if (hdr->hdr_2_x.xxx[2] == 0xff &&
hdr->hdr_2_x.xxx[3] == 0xff) {
padding = 4;
}
break;
case WTAP_ENCAP_LAPB:
case WTAP_ENCAP_FRELAY_WITH_PHDR:
phdr->pseudo_header.x25.flags =
(hdr->hdr_2_x.xxx[12] & 0x01) ? 0x00 : FROM_DCE;
if (hdr->hdr_2_x.xxx[2] == 0xff &&
hdr->hdr_2_x.xxx[3] == 0xff) {
padding = 4;
}
break;
case WTAP_ENCAP_PPP_WITH_PHDR:
case WTAP_ENCAP_SDLC:
case WTAP_ENCAP_CHDLC_WITH_PHDR:
phdr->pseudo_header.p2p.sent =
(hdr->hdr_2_x.xxx[12] & 0x01) ? TRUE : FALSE;
break;
case WTAP_ENCAP_ATM_PDUS_UNTRUNCATED:
pd = buffer_start_ptr(buf);
phdr->pseudo_header.atm.flags = 0;
if (hdr->hdr_2_x.xxx[9] & 0x04)
phdr->pseudo_header.atm.flags |= ATM_RAW_CELL;
phdr->pseudo_header.atm.vpi = hdr->hdr_2_x.xxx[11];
phdr->pseudo_header.atm.vci = pletohs(&hdr->hdr_2_x.xxx[12]);
phdr->pseudo_header.atm.channel =
(hdr->hdr_2_x.xxx[15] & 0x10)? 1 : 0;
phdr->pseudo_header.atm.cells = 0;
switch (hdr->hdr_2_x.xxx[0] & 0xF0) {
case 0x00:
atm_guess_traffic_type(pd, len,
&phdr->pseudo_header);
break;
case 0x50:
phdr->pseudo_header.atm.aal = AAL_5;
switch (hdr->hdr_2_x.xxx[0] & 0x0F) {
case 0x09:
case 0x0a:
phdr->pseudo_header.atm.aal = AAL_SIGNALLING;
phdr->pseudo_header.atm.type = TRAF_UNKNOWN;
phdr->pseudo_header.atm.subtype = TRAF_ST_UNKNOWN;
break;
case 0x0b:
phdr->pseudo_header.atm.type = TRAF_ILMI;
phdr->pseudo_header.atm.subtype = TRAF_ST_UNKNOWN;
break;
case 0x0c:
phdr->pseudo_header.atm.type = TRAF_LANE;
phdr->pseudo_header.atm.subtype = TRAF_ST_LANE_LE_CTRL;
break;
case 0x0d:
phdr->pseudo_header.atm.type = TRAF_LANE;
atm_guess_lane_type(pd, len,
&phdr->pseudo_header);
break;
case 0x0f:
phdr->pseudo_header.atm.type = TRAF_LLCMX;
phdr->pseudo_header.atm.subtype = TRAF_ST_UNKNOWN;
break;
default:
phdr->pseudo_header.atm.type = TRAF_UNKNOWN;
phdr->pseudo_header.atm.subtype = TRAF_ST_UNKNOWN;
break;
}
break;
default:
phdr->pseudo_header.atm.aal = AAL_UNKNOWN;
phdr->pseudo_header.atm.type = TRAF_UNKNOWN;
phdr->pseudo_header.atm.subtype = TRAF_ST_UNKNOWN;
break;
}
break;
}
break;
}
if (netxray->version_major == 0) {
phdr->presence_flags = WTAP_HAS_TS;
t = (double)pletohl(&hdr->old_hdr.timelo)
+ (double)pletohl(&hdr->old_hdr.timehi)*4294967296.0;
t /= netxray->ticks_per_sec;
t -= netxray->start_timestamp;
phdr->ts.secs = netxray->start_time + (long)t;
phdr->ts.nsecs = (int)((t-(double)(unsigned long)(t))
*1.0e9);
packet_size = pletohs(&hdr->old_hdr.len);
phdr->caplen = packet_size - padding;
phdr->len = phdr->caplen;
} else {
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
t = (double)pletohl(&hdr->hdr_1_x.timelo)
+ (double)pletohl(&hdr->hdr_1_x.timehi)*4294967296.0;
t /= netxray->ticks_per_sec;
t -= netxray->start_timestamp;
phdr->ts.secs = netxray->start_time + (time_t)t;
phdr->ts.nsecs = (int)((t-(double)(unsigned long)(t))
*1.0e9);
packet_size = pletohs(&hdr->hdr_1_x.incl_len);
phdr->caplen = packet_size - padding;
phdr->len = pletohs(&hdr->hdr_1_x.orig_len) - padding;
}
}
static int
wtap_encap_to_netxray_1_1_encap(int encap)
{
unsigned int i;
for (i = 0; i < NUM_WTAP_ENCAPS_1_1; i++) {
if (encap == wtap_encap_1_1[i].wtap_encap_value)
return wtap_encap_1_1[i].ndis_value;
}
return -1;
}
int netxray_dump_can_write_encap_1_1(int encap)
{
if (encap == WTAP_ENCAP_PER_PACKET)
return WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED;
if (wtap_encap_to_netxray_1_1_encap(encap) == -1)
return WTAP_ERR_UNSUPPORTED_ENCAP;
return 0;
}
gboolean netxray_dump_open_1_1(wtap_dumper *wdh, int *err)
{
netxray_dump_t *netxray;
wdh->subtype_write = netxray_dump_1_1;
wdh->subtype_close = netxray_dump_close_1_1;
if (wtap_dump_file_seek(wdh, CAPTUREFILE_HEADER_SIZE, SEEK_SET, err) == -1)
return FALSE;
wdh->bytes_dumped += CAPTUREFILE_HEADER_SIZE;
netxray = (netxray_dump_t *)g_malloc(sizeof(netxray_dump_t));
wdh->priv = (void *)netxray;
netxray->first_frame = TRUE;
netxray->start.secs = 0;
netxray->start.nsecs = 0;
netxray->nframes = 0;
return TRUE;
}
static gboolean netxray_dump_1_1(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err)
{
netxray_dump_t *netxray = (netxray_dump_t *)wdh->priv;
guint64 timestamp;
guint32 t32;
struct netxrayrec_1_x_hdr rec_hdr;
if (netxray->first_frame) {
netxray->first_frame = FALSE;
netxray->start = phdr->ts;
}
memset(&rec_hdr, '\0', sizeof(rec_hdr));
timestamp = ((guint64)phdr->ts.secs - (guint64)netxray->start.secs)*1000000
+ ((guint64)phdr->ts.nsecs)/1000;
t32 = (guint32)(timestamp%G_GINT64_CONSTANT(4294967296));
rec_hdr.timelo = htolel(t32);
t32 = (guint32)(timestamp/G_GINT64_CONSTANT(4294967296));
rec_hdr.timehi = htolel(t32);
rec_hdr.orig_len = htoles(phdr->len);
rec_hdr.incl_len = htoles(phdr->caplen);
if (!wtap_dump_file_write(wdh, &rec_hdr, sizeof(rec_hdr), err))
return FALSE;
wdh->bytes_dumped += sizeof(rec_hdr);
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
wdh->bytes_dumped += phdr->caplen;
netxray->nframes++;
return TRUE;
}
static gboolean netxray_dump_close_1_1(wtap_dumper *wdh, int *err)
{
char hdr_buf[CAPTUREFILE_HEADER_SIZE - sizeof(netxray_magic)];
netxray_dump_t *netxray = (netxray_dump_t *)wdh->priv;
gint64 filelen;
struct netxray_hdr file_hdr;
if (-1 == (filelen = wtap_dump_file_tell(wdh, err)))
return FALSE;
if (wtap_dump_file_seek(wdh, 0, SEEK_SET, err) == -1)
return FALSE;
if (!wtap_dump_file_write(wdh, netxray_magic, sizeof netxray_magic, err))
return FALSE;
memset(&file_hdr, '\0', sizeof file_hdr);
memcpy(file_hdr.version, vers_1_1, sizeof vers_1_1);
file_hdr.start_time = htolel(netxray->start.secs);
file_hdr.nframes = htolel(netxray->nframes);
file_hdr.start_offset = htolel(CAPTUREFILE_HEADER_SIZE);
file_hdr.end_offset = htolel((guint32)filelen);
file_hdr.network = wtap_encap_to_netxray_1_1_encap(wdh->encap);
file_hdr.timelo = htolel(0);
file_hdr.timehi = htolel(0);
memset(hdr_buf, '\0', sizeof hdr_buf);
memcpy(hdr_buf, &file_hdr, sizeof(file_hdr));
if (!wtap_dump_file_write(wdh, hdr_buf, sizeof hdr_buf, err))
return FALSE;
return TRUE;
}
static int
wtap_encap_to_netxray_2_0_encap(int encap)
{
unsigned int i;
for (i = 0; i < NUM_WTAP_ENCAPS_2_0; i++) {
if (encap == wtap_encap_2_0[i].wtap_encap_value)
return wtap_encap_2_0[i].ndis_value;
}
return -1;
}
int netxray_dump_can_write_encap_2_0(int encap)
{
if (encap == WTAP_ENCAP_PER_PACKET)
return WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED;
if (wtap_encap_to_netxray_2_0_encap(encap) == -1)
return WTAP_ERR_UNSUPPORTED_ENCAP;
return 0;
}
gboolean netxray_dump_open_2_0(wtap_dumper *wdh, int *err)
{
netxray_dump_t *netxray;
wdh->subtype_write = netxray_dump_2_0;
wdh->subtype_close = netxray_dump_close_2_0;
if (wtap_dump_file_seek(wdh, CAPTUREFILE_HEADER_SIZE, SEEK_SET, err) == -1)
return FALSE;
wdh->bytes_dumped += CAPTUREFILE_HEADER_SIZE;
netxray = (netxray_dump_t *)g_malloc(sizeof(netxray_dump_t));
wdh->priv = (void *)netxray;
netxray->first_frame = TRUE;
netxray->start.secs = 0;
netxray->start.nsecs = 0;
netxray->nframes = 0;
return TRUE;
}
static gboolean netxray_dump_2_0(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err)
{
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
netxray_dump_t *netxray = (netxray_dump_t *)wdh->priv;
guint64 timestamp;
guint32 t32;
struct netxrayrec_2_x_hdr rec_hdr;
if (netxray->first_frame) {
netxray->first_frame = FALSE;
netxray->start = phdr->ts;
}
memset(&rec_hdr, '\0', sizeof(rec_hdr));
timestamp = ((guint64)phdr->ts.secs - (guint64)netxray->start.secs)*1000000
+ ((guint64)phdr->ts.nsecs)/1000;
t32 = (guint32)(timestamp%G_GINT64_CONSTANT(4294967296));
rec_hdr.timelo = htolel(t32);
t32 = (guint32)(timestamp/G_GINT64_CONSTANT(4294967296));
rec_hdr.timehi = htolel(t32);
rec_hdr.orig_len = htoles(phdr->len);
rec_hdr.incl_len = htoles(phdr->caplen);
switch (phdr->pkt_encap) {
case WTAP_ENCAP_IEEE_802_11_WITH_RADIO:
rec_hdr.xxx[12] = pseudo_header->ieee_802_11.channel;
rec_hdr.xxx[13] = (guint8)pseudo_header->ieee_802_11.data_rate;
rec_hdr.xxx[14] = pseudo_header->ieee_802_11.signal_level;
break;
case WTAP_ENCAP_PPP_WITH_PHDR:
case WTAP_ENCAP_SDLC:
rec_hdr.xxx[12] |= pseudo_header->p2p.sent ? 0x01 : 0x00;
break;
case WTAP_ENCAP_FRELAY_WITH_PHDR:
rec_hdr.xxx[12] |= (pseudo_header->x25.flags & FROM_DCE) ? 0x00 : 0x01;
break;
}
if (!wtap_dump_file_write(wdh, &rec_hdr, sizeof(rec_hdr), err))
return FALSE;
wdh->bytes_dumped += sizeof(rec_hdr);
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
wdh->bytes_dumped += phdr->caplen;
netxray->nframes++;
return TRUE;
}
static gboolean netxray_dump_close_2_0(wtap_dumper *wdh, int *err)
{
char hdr_buf[CAPTUREFILE_HEADER_SIZE - sizeof(netxray_magic)];
netxray_dump_t *netxray = (netxray_dump_t *)wdh->priv;
gint64 filelen;
struct netxray_hdr file_hdr;
if (-1 == (filelen = wtap_dump_file_tell(wdh, err)))
return FALSE;
if (wtap_dump_file_seek(wdh, 0, SEEK_SET, err) == -1)
return FALSE;
if (!wtap_dump_file_write(wdh, netxray_magic, sizeof netxray_magic, err))
return FALSE;
memset(&file_hdr, '\0', sizeof file_hdr);
memcpy(file_hdr.version, vers_2_001, sizeof vers_2_001);
file_hdr.start_time = htolel(netxray->start.secs);
file_hdr.nframes = htolel(netxray->nframes);
file_hdr.start_offset = htolel(CAPTUREFILE_HEADER_SIZE);
file_hdr.end_offset = htolel((guint32)filelen);
file_hdr.network = wtap_encap_to_netxray_2_0_encap(wdh->encap);
file_hdr.timelo = htolel(0);
file_hdr.timehi = htolel(0);
switch (wdh->encap) {
case WTAP_ENCAP_PPP_WITH_PHDR:
file_hdr.captype = WAN_CAPTYPE_PPP;
break;
case WTAP_ENCAP_FRELAY_WITH_PHDR:
file_hdr.captype = WAN_CAPTYPE_FRELAY;
break;
case WTAP_ENCAP_LAPB:
file_hdr.captype = WAN_CAPTYPE_HDLC;
file_hdr.wan_hdlc_subsub_captype = 0;
break;
case WTAP_ENCAP_SDLC:
file_hdr.captype = WAN_CAPTYPE_SDLC;
break;
default:
file_hdr.captype = CAPTYPE_NDIS;
break;
}
memset(hdr_buf, '\0', sizeof hdr_buf);
memcpy(hdr_buf, &file_hdr, sizeof(file_hdr));
if (!wtap_dump_file_write(wdh, hdr_buf, sizeof hdr_buf, err))
return FALSE;
return TRUE;
}
