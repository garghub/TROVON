int
wtap_pcap_encap_to_wtap_encap(int encap)
{
unsigned int i;
for (i = 0; i < NUM_PCAP_ENCAPS; i++) {
if (pcap_to_wtap_map[i].linktype_value == encap)
return pcap_to_wtap_map[i].wtap_encap_value;
}
return WTAP_ENCAP_UNKNOWN;
}
int
wtap_wtap_encap_to_pcap_encap(int encap)
{
unsigned int i;
switch (encap) {
case WTAP_ENCAP_FDDI:
case WTAP_ENCAP_FDDI_BITSWAPPED:
return 10;
case WTAP_ENCAP_NETTL_FDDI:
return 10;
case WTAP_ENCAP_FRELAY_WITH_PHDR:
return 107;
case WTAP_ENCAP_IEEE_802_11_WITH_RADIO:
return 105;
}
for (i = 0; i < NUM_PCAP_ENCAPS; i++) {
if (pcap_to_wtap_map[i].wtap_encap_value == encap)
return pcap_to_wtap_map[i].linktype_value;
}
return -1;
}
guint
wtap_max_snaplen_for_encap(int wtap_encap)
{
if (wtap_encap == WTAP_ENCAP_DBUS)
return WTAP_MAX_PACKET_SIZE_DBUS;
else
return WTAP_MAX_PACKET_SIZE_STANDARD;
}
gboolean
wtap_encap_requires_phdr(int wtap_encap)
{
switch (wtap_encap) {
case WTAP_ENCAP_ATM_PDUS:
case WTAP_ENCAP_IRDA:
case WTAP_ENCAP_MTP2_WITH_PHDR:
case WTAP_ENCAP_LINUX_LAPD:
case WTAP_ENCAP_SITA:
case WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR:
case WTAP_ENCAP_BLUETOOTH_LINUX_MONITOR:
case WTAP_ENCAP_NFC_LLCP:
case WTAP_ENCAP_PPP_WITH_PHDR:
case WTAP_ENCAP_ERF:
case WTAP_ENCAP_I2C:
return TRUE;
}
return FALSE;
}
static gboolean
pcap_read_sunatm_pseudoheader(FILE_T fh,
union wtap_pseudo_header *pseudo_header, int *err, gchar **err_info)
{
guint8 atm_phdr[SUNATM_LEN];
guint8 vpi;
guint16 vci;
if (!wtap_read_bytes(fh, atm_phdr, SUNATM_LEN, err, err_info))
return FALSE;
vpi = atm_phdr[SUNATM_VPI];
vci = pntoh16(&atm_phdr[SUNATM_VCI]);
switch (atm_phdr[SUNATM_FLAGS] & 0x0F) {
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
pseudo_header->atm.channel = (atm_phdr[SUNATM_FLAGS] & 0x80) ? 0 : 1;
pseudo_header->atm.flags = 0;
pseudo_header->atm.cells = 0;
pseudo_header->atm.aal5t_u2u = 0;
pseudo_header->atm.aal5t_len = 0;
pseudo_header->atm.aal5t_chksum = 0;
return TRUE;
}
static gboolean
pcap_read_nokiaatm_pseudoheader(FILE_T fh,
union wtap_pseudo_header *pseudo_header, int *err, gchar **err_info)
{
guint8 atm_phdr[NOKIAATM_LEN];
guint8 vpi;
guint16 vci;
if (!wtap_read_bytes(fh, atm_phdr, NOKIAATM_LEN, err, err_info))
return FALSE;
vpi = atm_phdr[NOKIAATM_VPI];
vci = pntoh16(&atm_phdr[NOKIAATM_VCI]);
pseudo_header->atm.vpi = vpi;
pseudo_header->atm.vci = vci;
pseudo_header->atm.channel = (atm_phdr[NOKIAATM_FLAGS] & 0x80) ? 0 : 1;
pseudo_header->atm.flags = 0;
pseudo_header->atm.cells = 0;
pseudo_header->atm.aal5t_u2u = 0;
pseudo_header->atm.aal5t_len = 0;
pseudo_header->atm.aal5t_chksum = 0;
return TRUE;
}
static gboolean
pcap_read_nokia_pseudoheader(FILE_T fh,
union wtap_pseudo_header *pseudo_header, int *err, gchar **err_info)
{
guint8 phdr[NOKIA_LEN];
if (file_seek(fh, -NOKIA_LEN, SEEK_CUR, err) == -1)
{
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
if (!wtap_read_bytes(fh, phdr, NOKIA_LEN, err, err_info))
return FALSE;
memcpy(pseudo_header->nokia.stuff, phdr, NOKIA_LEN);
return TRUE;
}
static gboolean
pcap_read_irda_pseudoheader(FILE_T fh, union wtap_pseudo_header *pseudo_header,
int *err, gchar **err_info)
{
guint8 irda_phdr[IRDA_SLL_LEN];
if (!wtap_read_bytes(fh, irda_phdr, IRDA_SLL_LEN, err, err_info))
return FALSE;
if (pntoh16(&irda_phdr[IRDA_SLL_PROTOCOL_OFFSET]) != 0x0017) {
*err = WTAP_ERR_BAD_FILE;
if (err_info != NULL)
*err_info = g_strdup("libpcap: IrDA capture has a packet with an invalid sll_protocol field");
return FALSE;
}
pseudo_header->irda.pkttype = pntoh16(&irda_phdr[IRDA_SLL_PKTTYPE_OFFSET]);
return TRUE;
}
static gboolean
pcap_read_mtp2_pseudoheader(FILE_T fh, union wtap_pseudo_header *pseudo_header, int *err, gchar **err_info)
{
guint8 mtp2_hdr[MTP2_HDR_LEN];
if (!wtap_read_bytes(fh, mtp2_hdr, MTP2_HDR_LEN, err, err_info))
return FALSE;
pseudo_header->mtp2.sent = mtp2_hdr[MTP2_SENT_OFFSET];
pseudo_header->mtp2.annex_a_used = mtp2_hdr[MTP2_ANNEX_A_USED_OFFSET];
pseudo_header->mtp2.link_number = pntoh16(&mtp2_hdr[MTP2_LINK_NUMBER_OFFSET]);
return TRUE;
}
static gboolean
pcap_read_lapd_pseudoheader(FILE_T fh, union wtap_pseudo_header *pseudo_header,
int *err, gchar **err_info)
{
guint8 lapd_phdr[LAPD_SLL_LEN];
if (!wtap_read_bytes(fh, lapd_phdr, LAPD_SLL_LEN, err, err_info))
return FALSE;
if (pntoh16(&lapd_phdr[LAPD_SLL_PROTOCOL_OFFSET]) != ETH_P_LAPD) {
*err = WTAP_ERR_BAD_FILE;
if (err_info != NULL)
*err_info = g_strdup("libpcap: LAPD capture has a packet with an invalid sll_protocol field");
return FALSE;
}
pseudo_header->lapd.pkttype = pntoh16(&lapd_phdr[LAPD_SLL_PKTTYPE_OFFSET]);
pseudo_header->lapd.we_network = !!lapd_phdr[LAPD_SLL_ADDR_OFFSET+0];
return TRUE;
}
static gboolean
pcap_read_sita_pseudoheader(FILE_T fh, union wtap_pseudo_header *pseudo_header, int *err, gchar **err_info)
{
guint8 sita_phdr[SITA_HDR_LEN];
if (!wtap_read_bytes(fh, sita_phdr, SITA_HDR_LEN, err, err_info))
return FALSE;
pseudo_header->sita.sita_flags = sita_phdr[SITA_FLAGS_OFFSET];
pseudo_header->sita.sita_signals = sita_phdr[SITA_SIGNALS_OFFSET];
pseudo_header->sita.sita_errors1 = sita_phdr[SITA_ERRORS1_OFFSET];
pseudo_header->sita.sita_errors2 = sita_phdr[SITA_ERRORS2_OFFSET];
pseudo_header->sita.sita_proto = sita_phdr[SITA_PROTO_OFFSET];
return TRUE;
}
static void
pcap_byteswap_linux_sll_pseudoheader(struct wtap_pkthdr *phdr, guint8 *pd)
{
guint packet_size;
guint16 protocol;
struct can_socketcan_hdr *can_socketcan_phdr;
packet_size = phdr->caplen;
if (packet_size > phdr->len)
packet_size = phdr->len;
if (packet_size < LINUX_SLL_LEN) {
return;
}
protocol = pntoh16(&pd[LINUX_SLL_PROTOCOL_OFFSET]);
if (protocol != LINUX_SLL_P_CAN && protocol != LINUX_SLL_P_CANFD) {
return;
}
can_socketcan_phdr = (struct can_socketcan_hdr *)(void *)(pd + LINUX_SLL_LEN);
if (packet_size < LINUX_SLL_LEN + sizeof(can_socketcan_phdr->can_id)) {
return;
}
PBSWAP32((guint8 *)&can_socketcan_phdr->can_id);
}
static void
pcap_byteswap_linux_usb_pseudoheader(struct wtap_pkthdr *phdr, guint8 *pd,
gboolean header_len_64_bytes)
{
guint packet_size;
struct linux_usb_phdr *usb_phdr;
struct linux_usb_isodesc *pisodesc;
gint32 iso_numdesc, i;
packet_size = phdr->caplen;
if (packet_size > phdr->len)
packet_size = phdr->len;
usb_phdr = (struct linux_usb_phdr *)(void *)pd;
CHECK_AND_SWAP64(&usb_phdr->id);
CHECK_AND_SWAP16(&usb_phdr->bus_id);
CHECK_AND_SWAP64(&usb_phdr->ts_sec);
CHECK_AND_SWAP32(&usb_phdr->ts_usec);
CHECK_AND_SWAP32(&usb_phdr->status);
CHECK_AND_SWAP32(&usb_phdr->urb_len);
CHECK_AND_SWAP32(&usb_phdr->data_len);
if (usb_phdr->transfer_type == URB_ISOCHRONOUS) {
CHECK_AND_SWAP32(&usb_phdr->s.iso.error_count);
CHECK_AND_SWAP32(&usb_phdr->s.iso.numdesc);
}
if (header_len_64_bytes) {
CHECK_AND_SWAP32(&usb_phdr->interval);
CHECK_AND_SWAP32(&usb_phdr->start_frame);
CHECK_AND_SWAP32(&usb_phdr->xfer_flags);
CHECK_AND_SWAP32(&usb_phdr->ndesc);
}
if (usb_phdr->transfer_type == URB_ISOCHRONOUS) {
if (header_len_64_bytes) {
pisodesc = (struct linux_usb_isodesc*)(void *)(pd + 64);
} else {
pisodesc = (struct linux_usb_isodesc*)(void *)(pd + 48);
}
iso_numdesc = usb_phdr->s.iso.numdesc;
for (i = 0; i < iso_numdesc; i++) {
CHECK_AND_SWAP32(&pisodesc->iso_status);
CHECK_AND_SWAP32(&pisodesc->iso_off);
CHECK_AND_SWAP32(&pisodesc->iso_len);
CHECK_AND_SWAP32(&pisodesc->_pad);
pisodesc++;
}
}
}
static void
pcap_byteswap_nflog_pseudoheader(struct wtap_pkthdr *phdr, guint8 *pd)
{
guint packet_size;
guint8 *p;
struct nflog_hdr *nfhdr;
struct nflog_tlv *tlv;
guint size;
packet_size = phdr->caplen;
if (packet_size > phdr->len)
packet_size = phdr->len;
if (packet_size < sizeof(struct nflog_hdr)) {
return;
}
p = pd;
nfhdr = (struct nflog_hdr *)pd;
if (nfhdr->nflog_version != 0) {
return;
}
packet_size -= (guint)sizeof(struct nflog_hdr);
p += sizeof(struct nflog_hdr);
while (packet_size >= sizeof(struct nflog_tlv)) {
tlv = (struct nflog_tlv *) p;
PBSWAP16((guint8 *)&tlv->tlv_type);
PBSWAP16((guint8 *)&tlv->tlv_length);
size = tlv->tlv_length;
if (size % 4 != 0)
size += 4 - size % 4;
if (size < sizeof(struct nflog_tlv)) {
return;
}
if (packet_size < size) {
return;
}
packet_size -= size;
p += size;
}
}
static gboolean
pcap_read_bt_pseudoheader(FILE_T fh,
union wtap_pseudo_header *pseudo_header, int *err, gchar **err_info)
{
struct libpcap_bt_phdr phdr;
if (!wtap_read_bytes(fh, &phdr, sizeof (struct libpcap_bt_phdr),
err, err_info))
return FALSE;
pseudo_header->p2p.sent = ((g_ntohl(phdr.direction) & LIBPCAP_BT_PHDR_RECV) == 0)? TRUE: FALSE;
return TRUE;
}
static gboolean
pcap_read_bt_monitor_pseudoheader(FILE_T fh,
union wtap_pseudo_header *pseudo_header, int *err, gchar **err_info)
{
struct libpcap_bt_monitor_phdr phdr;
if (!wtap_read_bytes(fh, &phdr, sizeof (struct libpcap_bt_monitor_phdr),
err, err_info))
return FALSE;
pseudo_header->btmon.adapter_id = g_ntohs(phdr.adapter_id);
pseudo_header->btmon.opcode = g_ntohs(phdr.opcode);
return TRUE;
}
static gboolean
pcap_read_llcp_pseudoheader(FILE_T fh,
union wtap_pseudo_header *pseudo_header, int *err, gchar **err_info)
{
guint8 phdr[LLCP_HEADER_LEN];
if (!wtap_read_bytes(fh, phdr, LLCP_HEADER_LEN, err, err_info))
return FALSE;
pseudo_header->llcp.adapter = phdr[LLCP_ADAPTER_OFFSET];
pseudo_header->llcp.flags = phdr[LLCP_FLAGS_OFFSET];
return TRUE;
}
static gboolean
pcap_read_ppp_pseudoheader(FILE_T fh,
union wtap_pseudo_header *pseudo_header, int *err, gchar **err_info)
{
struct libpcap_ppp_phdr phdr;
if (!wtap_read_bytes(fh, &phdr, sizeof (struct libpcap_ppp_phdr),
err, err_info))
return FALSE;
pseudo_header->p2p.sent = (phdr.direction == LIBPCAP_PPP_PHDR_SENT) ? TRUE: FALSE;
return TRUE;
}
static gboolean
pcap_read_erf_pseudoheader(FILE_T fh, struct wtap_pkthdr *whdr,
union wtap_pseudo_header *pseudo_header, int *err, gchar **err_info)
{
guint8 erf_hdr[sizeof(struct erf_phdr)];
if (!wtap_read_bytes(fh, erf_hdr, sizeof(struct erf_phdr), err, err_info))
return FALSE;
pseudo_header->erf.phdr.ts = pletoh64(&erf_hdr[0]);
pseudo_header->erf.phdr.type = erf_hdr[8];
pseudo_header->erf.phdr.flags = erf_hdr[9];
pseudo_header->erf.phdr.rlen = pntoh16(&erf_hdr[10]);
pseudo_header->erf.phdr.lctr = pntoh16(&erf_hdr[12]);
pseudo_header->erf.phdr.wlen = pntoh16(&erf_hdr[14]);
if (whdr) {
guint64 ts = pseudo_header->erf.phdr.ts;
whdr->ts.secs = (guint32) (ts >> 32);
ts = ((ts & 0xffffffff) * 1000 * 1000 * 1000);
ts += (ts & 0x80000000) << 1;
whdr->ts.nsecs = ((guint32) (ts >> 32));
if ( whdr->ts.nsecs >= 1000000000) {
whdr->ts.nsecs -= 1000000000;
whdr->ts.secs += 1;
}
}
return TRUE;
}
static gboolean
pcap_read_erf_exheader(FILE_T fh, union wtap_pseudo_header *pseudo_header,
int *err, gchar **err_info, guint * psize)
{
guint8 erf_exhdr[8];
guint64 erf_exhdr_sw;
int i = 0, max = sizeof(pseudo_header->erf.ehdr_list)/sizeof(struct erf_ehdr);
guint8 type;
*psize = 0;
if (pseudo_header->erf.phdr.type & 0x80){
do{
if (!wtap_read_bytes(fh, erf_exhdr, 8, err, err_info))
return FALSE;
type = erf_exhdr[0];
erf_exhdr_sw = pntoh64(erf_exhdr);
if (i < max)
memcpy(&pseudo_header->erf.ehdr_list[i].ehdr, &erf_exhdr_sw, sizeof(erf_exhdr_sw));
*psize += 8;
i++;
} while (type & 0x80);
}
return TRUE;
}
static gboolean
pcap_read_erf_subheader(FILE_T fh, union wtap_pseudo_header *pseudo_header,
int *err, gchar **err_info, guint * psize)
{
guint8 erf_subhdr[sizeof(union erf_subhdr)];
*psize=0;
switch(pseudo_header->erf.phdr.type & 0x7F) {
case ERF_TYPE_MC_HDLC:
case ERF_TYPE_MC_RAW:
case ERF_TYPE_MC_ATM:
case ERF_TYPE_MC_RAW_CHANNEL:
case ERF_TYPE_MC_AAL5:
case ERF_TYPE_MC_AAL2:
case ERF_TYPE_COLOR_MC_HDLC_POS:
if (!wtap_read_bytes(fh, erf_subhdr, sizeof(erf_mc_header_t), err, err_info))
return FALSE;
pseudo_header->erf.subhdr.mc_hdr = pntoh32(&erf_subhdr[0]);
*psize = sizeof(erf_mc_header_t);
break;
case ERF_TYPE_AAL2:
if (!wtap_read_bytes(fh, erf_subhdr, sizeof(erf_aal2_header_t), err, err_info))
return FALSE;
pseudo_header->erf.subhdr.aal2_hdr = pntoh32(&erf_subhdr[0]);
*psize = sizeof(erf_aal2_header_t);
break;
case ERF_TYPE_ETH:
case ERF_TYPE_COLOR_ETH:
case ERF_TYPE_DSM_COLOR_ETH:
case ERF_TYPE_COLOR_HASH_ETH:
if (!wtap_read_bytes(fh, erf_subhdr, sizeof(erf_eth_header_t), err, err_info))
return FALSE;
memcpy(&pseudo_header->erf.subhdr.eth_hdr, erf_subhdr, sizeof pseudo_header->erf.subhdr.eth_hdr);
*psize = sizeof(erf_eth_header_t);
break;
default:
break;
}
return TRUE;
}
static gboolean
pcap_read_i2c_pseudoheader(FILE_T fh, union wtap_pseudo_header *pseudo_header, int *err, gchar **err_info)
{
struct i2c_file_hdr i2c_hdr;
if (!wtap_read_bytes(fh, &i2c_hdr, sizeof (i2c_hdr), err, err_info))
return FALSE;
pseudo_header->i2c.is_event = i2c_hdr.bus & 0x80 ? 1 : 0;
pseudo_header->i2c.bus = i2c_hdr.bus & 0x7f;
pseudo_header->i2c.flags = pntoh32(&i2c_hdr.flags);
return TRUE;
}
int
pcap_process_pseudo_header(FILE_T fh, int file_type, int wtap_encap,
guint packet_size, gboolean check_packet_size,
struct wtap_pkthdr *phdr, int *err, gchar **err_info)
{
int phdr_len = 0;
guint size;
switch (wtap_encap) {
case WTAP_ENCAP_ATM_PDUS:
if (file_type == WTAP_FILE_TYPE_SUBTYPE_PCAP_NOKIA) {
if (check_packet_size && packet_size < NOKIAATM_LEN) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("pcap: Nokia IPSO ATM file has a %u-byte packet, too small to have even an ATM pseudo-header",
packet_size);
return -1;
}
if (!pcap_read_nokiaatm_pseudoheader(fh,
&phdr->pseudo_header, err, err_info))
return -1;
phdr_len = NOKIAATM_LEN;
} else {
if (check_packet_size && packet_size < SUNATM_LEN) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("pcap: SunATM file has a %u-byte packet, too small to have even an ATM pseudo-header",
packet_size);
return -1;
}
if (!pcap_read_sunatm_pseudoheader(fh,
&phdr->pseudo_header, err, err_info))
return -1;
phdr_len = SUNATM_LEN;
}
break;
case WTAP_ENCAP_ETHERNET:
if (file_type == WTAP_FILE_TYPE_SUBTYPE_PCAP_NOKIA) {
if (!pcap_read_nokia_pseudoheader(fh, &phdr->pseudo_header, err, err_info))
return -1;
}
phdr->pseudo_header.eth.fcs_len = -1;
break;
case WTAP_ENCAP_IEEE_802_11:
case WTAP_ENCAP_IEEE_802_11_PRISM:
case WTAP_ENCAP_IEEE_802_11_RADIOTAP:
case WTAP_ENCAP_IEEE_802_11_AVS:
memset(&phdr->pseudo_header.ieee_802_11, 0, sizeof(phdr->pseudo_header.ieee_802_11));
phdr->pseudo_header.ieee_802_11.fcs_len = -1;
phdr->pseudo_header.ieee_802_11.decrypted = FALSE;
phdr->pseudo_header.ieee_802_11.datapad = FALSE;
break;
case WTAP_ENCAP_IRDA:
if (check_packet_size && packet_size < IRDA_SLL_LEN) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("pcap: IrDA file has a %u-byte packet, too small to have even an IrDA pseudo-header",
packet_size);
return -1;
}
if (!pcap_read_irda_pseudoheader(fh, &phdr->pseudo_header,
err, err_info))
return -1;
phdr_len = IRDA_SLL_LEN;
break;
case WTAP_ENCAP_MTP2_WITH_PHDR:
if (check_packet_size && packet_size < MTP2_HDR_LEN) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("pcap: MTP2 file has a %u-byte packet, too small to have even an MTP2 pseudo-header",
packet_size);
return -1;
}
if (!pcap_read_mtp2_pseudoheader(fh, &phdr->pseudo_header,
err, err_info))
return -1;
phdr_len = MTP2_HDR_LEN;
break;
case WTAP_ENCAP_LINUX_LAPD:
if (check_packet_size && packet_size < LAPD_SLL_LEN) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("pcap: LAPD file has a %u-byte packet, too small to have even a LAPD pseudo-header",
packet_size);
return -1;
}
if (!pcap_read_lapd_pseudoheader(fh, &phdr->pseudo_header,
err, err_info))
return -1;
phdr_len = LAPD_SLL_LEN;
break;
case WTAP_ENCAP_SITA:
if (check_packet_size && packet_size < SITA_HDR_LEN) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("pcap: SITA file has a %u-byte packet, too small to have even a SITA pseudo-header",
packet_size);
return -1;
}
if (!pcap_read_sita_pseudoheader(fh, &phdr->pseudo_header,
err, err_info))
return -1;
phdr_len = SITA_HDR_LEN;
break;
case WTAP_ENCAP_BLUETOOTH_H4:
phdr->pseudo_header.p2p.sent = FALSE;
break;
case WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR:
if (check_packet_size &&
packet_size < sizeof (struct libpcap_bt_phdr)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("pcap: libpcap bluetooth file has a %u-byte packet, too small to have even a pseudo-header",
packet_size);
return -1;
}
if (!pcap_read_bt_pseudoheader(fh,
&phdr->pseudo_header, err, err_info))
return -1;
phdr_len = (int)sizeof (struct libpcap_bt_phdr);
break;
case WTAP_ENCAP_BLUETOOTH_LINUX_MONITOR:
if (check_packet_size &&
packet_size < sizeof (struct libpcap_bt_monitor_phdr)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("pcap: libpcap bluetooth monitor file has a %u-byte packet, too small to have even a pseudo-header",
packet_size);
return -1;
}
if (!pcap_read_bt_monitor_pseudoheader(fh,
&phdr->pseudo_header, err, err_info))
return -1;
phdr_len = (int)sizeof (struct libpcap_bt_monitor_phdr);
break;
case WTAP_ENCAP_NFC_LLCP:
if (check_packet_size && packet_size < LLCP_HEADER_LEN) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("pcap: libpcap llcp file too short");
return -1;
}
if (!pcap_read_llcp_pseudoheader(fh, &phdr->pseudo_header, err, err_info))
return -1;
phdr_len = LLCP_HEADER_LEN;
break;
case WTAP_ENCAP_PPP_WITH_PHDR:
if (check_packet_size &&
packet_size < sizeof (struct libpcap_ppp_phdr)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("pcap: libpcap ppp file has a %u-byte packet, too small to have even a pseudo-header",
packet_size);
return -1;
}
if (!pcap_read_ppp_pseudoheader(fh,
&phdr->pseudo_header, err, err_info))
return -1;
phdr_len = (int)sizeof (struct libpcap_ppp_phdr);
break;
case WTAP_ENCAP_ERF:
if (check_packet_size &&
packet_size < sizeof(struct erf_phdr) ) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("pcap: ERF file has a %u-byte packet, too small to have even an ERF pseudo-header",
packet_size);
return -1;
}
if (!pcap_read_erf_pseudoheader(fh, phdr, &phdr->pseudo_header,
err, err_info))
return -1;
phdr_len = (int)sizeof(struct erf_phdr);
if (!pcap_read_erf_exheader(fh, &phdr->pseudo_header, err, err_info,
&size))
return -1;
phdr_len += size;
if (!pcap_read_erf_subheader(fh, &phdr->pseudo_header, err, err_info,
&size))
return -1;
phdr_len += size;
if (check_packet_size &&
packet_size < (guint)phdr_len) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("pcap: ERF file has a %u-byte packet, too small for a pseudo-header with ex- and sub-headers (%d)",
packet_size, phdr_len);
return -1;
}
break;
case WTAP_ENCAP_I2C:
if (check_packet_size &&
packet_size < sizeof (struct i2c_file_hdr)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("pcap: I2C file has a %u-byte packet, too small to have even a I2C pseudo-header",
packet_size);
return -1;
}
if (!pcap_read_i2c_pseudoheader(fh, &phdr->pseudo_header,
err, err_info))
return -1;
phdr_len = (int)sizeof (struct i2c_file_hdr);
break;
}
return phdr_len;
}
void
pcap_read_post_process(int file_type, int wtap_encap,
struct wtap_pkthdr *phdr, guint8 *pd, gboolean bytes_swapped, int fcs_len)
{
switch (wtap_encap) {
case WTAP_ENCAP_ATM_PDUS:
if (file_type == WTAP_FILE_TYPE_SUBTYPE_PCAP_NOKIA) {
atm_guess_traffic_type(phdr, pd);
} else {
if (phdr->pseudo_header.atm.type == TRAF_LANE)
atm_guess_lane_type(phdr, pd);
}
break;
case WTAP_ENCAP_ETHERNET:
phdr->pseudo_header.eth.fcs_len = fcs_len;
break;
case WTAP_ENCAP_SLL:
if (bytes_swapped)
pcap_byteswap_linux_sll_pseudoheader(phdr, pd);
break;
case WTAP_ENCAP_USB_LINUX:
if (bytes_swapped)
pcap_byteswap_linux_usb_pseudoheader(phdr, pd, FALSE);
break;
case WTAP_ENCAP_USB_LINUX_MMAPPED:
if (bytes_swapped)
pcap_byteswap_linux_usb_pseudoheader(phdr, pd, TRUE);
break;
case WTAP_ENCAP_NETANALYZER:
phdr->pseudo_header.eth.fcs_len = 4;
break;
case WTAP_ENCAP_NFLOG:
if (bytes_swapped)
pcap_byteswap_nflog_pseudoheader(phdr, pd);
break;
case WTAP_ENCAP_ERF:
phdr->len = phdr->pseudo_header.erf.phdr.wlen;
phdr->caplen = MIN(phdr->len, phdr->caplen);
break;
default:
break;
}
}
int
pcap_get_phdr_size(int encap, const union wtap_pseudo_header *pseudo_header)
{
int hdrsize;
switch (encap) {
case WTAP_ENCAP_ATM_PDUS:
hdrsize = SUNATM_LEN;
break;
case WTAP_ENCAP_IRDA:
hdrsize = IRDA_SLL_LEN;
break;
case WTAP_ENCAP_MTP2_WITH_PHDR:
hdrsize = MTP2_HDR_LEN;
break;
case WTAP_ENCAP_LINUX_LAPD:
hdrsize = LAPD_SLL_LEN;
break;
case WTAP_ENCAP_SITA:
hdrsize = SITA_HDR_LEN;
break;
case WTAP_ENCAP_ERF:
hdrsize = (int)sizeof (struct erf_phdr);
switch (pseudo_header->erf.phdr.type & 0x7F) {
case ERF_TYPE_MC_HDLC:
case ERF_TYPE_MC_RAW:
case ERF_TYPE_MC_ATM:
case ERF_TYPE_MC_RAW_CHANNEL:
case ERF_TYPE_MC_AAL5:
case ERF_TYPE_MC_AAL2:
case ERF_TYPE_COLOR_MC_HDLC_POS:
hdrsize += (int)sizeof(struct erf_mc_hdr);
break;
case ERF_TYPE_AAL2:
hdrsize += (int)sizeof(struct erf_aal2_hdr);
break;
case ERF_TYPE_ETH:
case ERF_TYPE_COLOR_ETH:
case ERF_TYPE_DSM_COLOR_ETH:
case ERF_TYPE_COLOR_HASH_ETH:
hdrsize += (int)sizeof(struct erf_eth_hdr);
break;
default:
break;
}
if (pseudo_header->erf.phdr.type & 0x80) {
int i = 0, max = sizeof(pseudo_header->erf.ehdr_list)/sizeof(struct erf_ehdr);
guint8 erf_exhdr[8];
guint8 type;
do {
phtonll(erf_exhdr, pseudo_header->erf.ehdr_list[i].ehdr);
type = erf_exhdr[0];
hdrsize += 8;
i++;
} while (type & 0x80 && i < max);
}
break;
case WTAP_ENCAP_I2C:
hdrsize = (int)sizeof (struct i2c_file_hdr);
break;
case WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR:
hdrsize = (int)sizeof (struct libpcap_bt_phdr);
break;
case WTAP_ENCAP_PPP_WITH_PHDR:
hdrsize = (int)sizeof (struct libpcap_ppp_phdr);
break;
case WTAP_ENCAP_BLUETOOTH_LINUX_MONITOR:
hdrsize = (int)sizeof (struct libpcap_bt_monitor_phdr);
break;
default:
hdrsize = 0;
break;
}
return hdrsize;
}
gboolean
pcap_write_phdr(wtap_dumper *wdh, int encap, const union wtap_pseudo_header *pseudo_header,
int *err)
{
guint8 atm_hdr[SUNATM_LEN];
guint8 irda_hdr[IRDA_SLL_LEN];
guint8 lapd_hdr[LAPD_SLL_LEN];
guint8 mtp2_hdr[MTP2_HDR_LEN];
guint8 sita_hdr[SITA_HDR_LEN];
guint8 erf_hdr[ sizeof(struct erf_mc_phdr)];
guint8 erf_subhdr[sizeof(union erf_subhdr)];
struct i2c_file_hdr i2c_hdr;
struct libpcap_bt_phdr bt_hdr;
struct libpcap_bt_monitor_phdr bt_monitor_hdr;
struct libpcap_ppp_phdr ppp_hdr;
size_t size;
size_t subhdr_size = 0;
switch (encap) {
case WTAP_ENCAP_ATM_PDUS:
atm_hdr[SUNATM_FLAGS] =
(pseudo_header->atm.channel == 0) ? 0x80 : 0x00;
switch (pseudo_header->atm.aal) {
case AAL_SIGNALLING:
atm_hdr[SUNATM_FLAGS] |= 0x06;
break;
case AAL_5:
switch (pseudo_header->atm.type) {
case TRAF_LANE:
atm_hdr[SUNATM_FLAGS] |= 0x01;
break;
case TRAF_LLCMX:
atm_hdr[SUNATM_FLAGS] |= 0x02;
break;
case TRAF_ILMI:
atm_hdr[SUNATM_FLAGS] |= 0x05;
break;
}
break;
}
atm_hdr[SUNATM_VPI] = (guint8)pseudo_header->atm.vpi;
phtons(&atm_hdr[SUNATM_VCI], pseudo_header->atm.vci);
if (!wtap_dump_file_write(wdh, atm_hdr, sizeof(atm_hdr), err))
return FALSE;
wdh->bytes_dumped += sizeof(atm_hdr);
break;
case WTAP_ENCAP_IRDA:
memset(irda_hdr, 0, sizeof(irda_hdr));
phtons(&irda_hdr[IRDA_SLL_PKTTYPE_OFFSET],
pseudo_header->irda.pkttype);
phtons(&irda_hdr[IRDA_SLL_PROTOCOL_OFFSET], 0x0017);
if (!wtap_dump_file_write(wdh, irda_hdr, sizeof(irda_hdr), err))
return FALSE;
wdh->bytes_dumped += sizeof(irda_hdr);
break;
case WTAP_ENCAP_MTP2_WITH_PHDR:
memset(&mtp2_hdr, 0, sizeof(mtp2_hdr));
mtp2_hdr[MTP2_SENT_OFFSET] = pseudo_header->mtp2.sent;
mtp2_hdr[MTP2_ANNEX_A_USED_OFFSET] = pseudo_header->mtp2.annex_a_used;
phtons(&mtp2_hdr[MTP2_LINK_NUMBER_OFFSET],
pseudo_header->mtp2.link_number);
if (!wtap_dump_file_write(wdh, mtp2_hdr, sizeof(mtp2_hdr), err))
return FALSE;
wdh->bytes_dumped += sizeof(mtp2_hdr);
break;
case WTAP_ENCAP_LINUX_LAPD:
memset(&lapd_hdr, 0, sizeof(lapd_hdr));
phtons(&lapd_hdr[LAPD_SLL_PKTTYPE_OFFSET],
pseudo_header->lapd.pkttype);
phtons(&lapd_hdr[LAPD_SLL_PROTOCOL_OFFSET], ETH_P_LAPD);
lapd_hdr[LAPD_SLL_ADDR_OFFSET + 0] =
pseudo_header->lapd.we_network?0x01:0x00;
if (!wtap_dump_file_write(wdh, lapd_hdr, sizeof(lapd_hdr), err))
return FALSE;
wdh->bytes_dumped += sizeof(lapd_hdr);
break;
case WTAP_ENCAP_SITA:
memset(&sita_hdr, 0, sizeof(sita_hdr));
sita_hdr[SITA_FLAGS_OFFSET] = pseudo_header->sita.sita_flags;
sita_hdr[SITA_SIGNALS_OFFSET] = pseudo_header->sita.sita_signals;
sita_hdr[SITA_ERRORS1_OFFSET] = pseudo_header->sita.sita_errors1;
sita_hdr[SITA_ERRORS2_OFFSET] = pseudo_header->sita.sita_errors2;
sita_hdr[SITA_PROTO_OFFSET] = pseudo_header->sita.sita_proto;
if (!wtap_dump_file_write(wdh, sita_hdr, sizeof(sita_hdr), err))
return FALSE;
wdh->bytes_dumped += sizeof(sita_hdr);
break;
case WTAP_ENCAP_ERF:
memset(&erf_hdr, 0, sizeof(erf_hdr));
phtolell(&erf_hdr[0], pseudo_header->erf.phdr.ts);
erf_hdr[8] = pseudo_header->erf.phdr.type;
erf_hdr[9] = pseudo_header->erf.phdr.flags;
phtons(&erf_hdr[10],
MIN(pseudo_header->erf.phdr.rlen, pseudo_header->erf.phdr.wlen + pcap_get_phdr_size(WTAP_ENCAP_ERF, pseudo_header)));
phtons(&erf_hdr[12], pseudo_header->erf.phdr.lctr);
phtons(&erf_hdr[14], pseudo_header->erf.phdr.wlen);
size = sizeof(struct erf_phdr);
switch(pseudo_header->erf.phdr.type & 0x7F) {
case ERF_TYPE_MC_HDLC:
case ERF_TYPE_MC_RAW:
case ERF_TYPE_MC_ATM:
case ERF_TYPE_MC_RAW_CHANNEL:
case ERF_TYPE_MC_AAL5:
case ERF_TYPE_MC_AAL2:
case ERF_TYPE_COLOR_MC_HDLC_POS:
phtonl(&erf_subhdr[0], pseudo_header->erf.subhdr.mc_hdr);
subhdr_size += (int)sizeof(struct erf_mc_hdr);
break;
case ERF_TYPE_AAL2:
phtonl(&erf_subhdr[0], pseudo_header->erf.subhdr.aal2_hdr);
subhdr_size += (int)sizeof(struct erf_aal2_hdr);
break;
case ERF_TYPE_ETH:
case ERF_TYPE_COLOR_ETH:
case ERF_TYPE_DSM_COLOR_ETH:
case ERF_TYPE_COLOR_HASH_ETH:
memcpy(&erf_subhdr[0], &pseudo_header->erf.subhdr.eth_hdr, sizeof pseudo_header->erf.subhdr.eth_hdr);
subhdr_size += (int)sizeof(struct erf_eth_hdr);
break;
default:
break;
}
if (!wtap_dump_file_write(wdh, erf_hdr, size, err))
return FALSE;
wdh->bytes_dumped += size;
if (pseudo_header->erf.phdr.type & 0x80) {
int i = 0, max = sizeof(pseudo_header->erf.ehdr_list)/sizeof(struct erf_ehdr);
guint8 erf_exhdr[8];
guint8 type;
do {
phtonll(erf_exhdr, pseudo_header->erf.ehdr_list[i].ehdr);
type = erf_exhdr[0];
if(i == max-1)
erf_exhdr[0] = erf_exhdr[0] & 0x7F;
if (!wtap_dump_file_write(wdh, erf_exhdr, 8, err))
return FALSE;
wdh->bytes_dumped += 8;
i++;
} while (type & 0x80 && i < max);
}
if(!wtap_dump_file_write(wdh, erf_subhdr, subhdr_size, err))
return FALSE;
wdh->bytes_dumped += subhdr_size;
break;
case WTAP_ENCAP_I2C:
memset(&i2c_hdr, 0, sizeof(i2c_hdr));
i2c_hdr.bus = pseudo_header->i2c.bus |
(pseudo_header->i2c.is_event ? 0x80 : 0x00);
phtonl((guint8 *)&i2c_hdr.flags, pseudo_header->i2c.flags);
if (!wtap_dump_file_write(wdh, &i2c_hdr, sizeof(i2c_hdr), err))
return FALSE;
wdh->bytes_dumped += sizeof(i2c_hdr);
break;
case WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR:
bt_hdr.direction = GUINT32_TO_BE(pseudo_header->p2p.sent ? LIBPCAP_BT_PHDR_SENT : LIBPCAP_BT_PHDR_RECV);
if (!wtap_dump_file_write(wdh, &bt_hdr, sizeof bt_hdr, err))
return FALSE;
wdh->bytes_dumped += sizeof bt_hdr;
break;
case WTAP_ENCAP_BLUETOOTH_LINUX_MONITOR:
bt_monitor_hdr.adapter_id = GUINT16_TO_BE(pseudo_header->btmon.adapter_id);
bt_monitor_hdr.opcode = GUINT16_TO_BE(pseudo_header->btmon.opcode);
if (!wtap_dump_file_write(wdh, &bt_monitor_hdr, sizeof bt_monitor_hdr, err))
return FALSE;
wdh->bytes_dumped += sizeof bt_monitor_hdr;
break;
case WTAP_ENCAP_PPP_WITH_PHDR:
ppp_hdr.direction = (pseudo_header->p2p.sent ? LIBPCAP_PPP_PHDR_SENT : LIBPCAP_PPP_PHDR_RECV);
if (!wtap_dump_file_write(wdh, &ppp_hdr, sizeof ppp_hdr, err))
return FALSE;
wdh->bytes_dumped += sizeof ppp_hdr;
break;
}
return TRUE;
}
