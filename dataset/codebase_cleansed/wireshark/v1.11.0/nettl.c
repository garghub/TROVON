int nettl_open(wtap *wth, int *err, gchar **err_info)
{
struct nettl_file_hdr file_hdr;
guint16 dummy[2];
int subsys;
int bytes_read;
nettl_t *nettl;
memset(&file_hdr, 0, sizeof(file_hdr));
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(file_hdr.magic, MAGIC_SIZE, wth->fh);
if (bytes_read != MAGIC_SIZE) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if (memcmp(file_hdr.magic, nettl_magic_hpux9, MAGIC_SIZE) &&
memcmp(file_hdr.magic, nettl_magic_hpux10, MAGIC_SIZE)) {
return 0;
}
bytes_read = file_read(file_hdr.file_name, FILE_HDR_SIZE - MAGIC_SIZE,
wth->fh);
if (bytes_read != FILE_HDR_SIZE - MAGIC_SIZE) {
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return -1;
}
wth->file_type = WTAP_FILE_NETTL;
nettl = g_new(nettl_t,1);
wth->priv = (void *)nettl;
if (file_hdr.os_vers[2] == '1' && file_hdr.os_vers[3] == '1')
nettl->is_hpux_11 = TRUE;
else
nettl->is_hpux_11 = FALSE;
wth->subtype_read = nettl_read;
wth->subtype_seek_read = nettl_seek_read;
wth->snapshot_length = 0;
bytes_read = file_read(dummy, 4, wth->fh);
if (bytes_read != 4) {
if (*err != 0) {
return -1;
}
if (bytes_read != 0) {
*err = WTAP_ERR_SHORT_READ;
return -1;
}
return 0;
}
subsys = g_ntohs(dummy[1]);
switch (subsys) {
case NETTL_SUBSYS_HPPB_FDDI :
case NETTL_SUBSYS_EISA_FDDI :
case NETTL_SUBSYS_PCI_FDDI :
case NETTL_SUBSYS_HSC_FDDI :
wth->file_encap = WTAP_ENCAP_NETTL_FDDI;
break;
case NETTL_SUBSYS_TOKEN :
case NETTL_SUBSYS_PCI_TR :
wth->file_encap = WTAP_ENCAP_NETTL_TOKEN_RING;
break;
case NETTL_SUBSYS_NS_LS_IP :
case NETTL_SUBSYS_NS_LS_LOOPBACK :
case NETTL_SUBSYS_NS_LS_TCP :
case NETTL_SUBSYS_NS_LS_UDP :
case NETTL_SUBSYS_NS_LS_IPV6 :
wth->file_encap = WTAP_ENCAP_NETTL_RAW_IP;
break;
case NETTL_SUBSYS_NS_LS_ICMP :
wth->file_encap = WTAP_ENCAP_NETTL_RAW_ICMP;
break;
case NETTL_SUBSYS_NS_LS_ICMPV6 :
wth->file_encap = WTAP_ENCAP_NETTL_RAW_ICMPV6;
break;
case NETTL_SUBSYS_NS_LS_TELNET :
wth->file_encap = WTAP_ENCAP_NETTL_RAW_TELNET;
break;
default:
wth->file_encap = WTAP_ENCAP_NETTL_ETHERNET;
}
if (file_seek(wth->fh, FILE_HDR_SIZE, SEEK_SET, err) == -1) {
return -1;
}
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
return 1;
}
static gboolean nettl_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
*data_offset = file_tell(wth->fh);
if (!nettl_read_rec(wth, wth->fh, &wth->phdr, wth->frame_buffer,
err, err_info)) {
return FALSE;
}
if (wth->file_encap == WTAP_ENCAP_UNKNOWN)
wth->file_encap = wth->phdr.pkt_encap;
else {
if (wth->file_encap != wth->phdr.pkt_encap)
wth->file_encap = WTAP_ENCAP_PER_PACKET;
}
return TRUE;
}
static gboolean
nettl_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr,
Buffer *buf, int length _U_, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!nettl_read_rec(wth, wth->random_fh, phdr, buf, err, err_info)) {
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
return TRUE;
}
static gboolean
nettl_read_rec(wtap *wth, FILE_T fh, struct wtap_pkthdr *phdr, Buffer *buf,
int *err, gchar **err_info)
{
union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
nettl_t *nettl = (nettl_t *)wth->priv;
gboolean fddihack = FALSE;
int bytes_read;
struct nettlrec_hdr rec_hdr;
guint16 hdr_len;
struct nettlrec_ns_ls_drv_eth_hdr drv_eth_hdr;
guint32 length, caplen;
int subsys;
guint padlen;
int datalen;
guint8 dummyc[16];
int bytes_to_read;
guint8 *pd;
guint8 dummy[3];
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&rec_hdr.hdr_len, sizeof rec_hdr.hdr_len, fh);
if (bytes_read != sizeof rec_hdr.hdr_len) {
*err = file_error(fh, err_info);
if (*err == 0 && bytes_read != 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
hdr_len = g_ntohs(rec_hdr.hdr_len);
if (hdr_len < NETTL_REC_HDR_LEN) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("nettl: record header length %u too short",
hdr_len);
return FALSE;
}
bytes_read = file_read(&rec_hdr.subsys, NETTL_REC_HDR_LEN - 2, fh);
if (bytes_read != NETTL_REC_HDR_LEN - 2) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
subsys = g_ntohs(rec_hdr.subsys);
hdr_len -= NETTL_REC_HDR_LEN;
if (file_seek(fh, hdr_len, SEEK_CUR, err) == -1)
return FALSE;
if ( (pntohl(&rec_hdr.kind) & NETTL_HDR_PDU_MASK) == 0 ) {
phdr->pkt_encap = WTAP_ENCAP_NETTL_RAW_IP;
length = pntohl(&rec_hdr.length);
caplen = pntohl(&rec_hdr.caplen);
padlen = 0;
} else switch (subsys) {
case NETTL_SUBSYS_LAN100 :
case NETTL_SUBSYS_EISA100BT :
case NETTL_SUBSYS_BASE100 :
case NETTL_SUBSYS_GSC100BT :
case NETTL_SUBSYS_PCI100BT :
case NETTL_SUBSYS_SPP100BT :
case NETTL_SUBSYS_100VG :
case NETTL_SUBSYS_GELAN :
case NETTL_SUBSYS_BTLAN :
case NETTL_SUBSYS_INTL100 :
case NETTL_SUBSYS_IGELAN :
case NETTL_SUBSYS_IETHER :
case NETTL_SUBSYS_IXGBE :
case NETTL_SUBSYS_HSSN :
case NETTL_SUBSYS_IGSSN :
case NETTL_SUBSYS_ICXGBE :
case NETTL_SUBSYS_IEXGBE :
case NETTL_SUBSYS_IOCXGBE :
case NETTL_SUBSYS_IQXGBE :
case NETTL_SUBSYS_HPPB_FDDI :
case NETTL_SUBSYS_EISA_FDDI :
case NETTL_SUBSYS_PCI_FDDI :
case NETTL_SUBSYS_HSC_FDDI :
case NETTL_SUBSYS_TOKEN :
case NETTL_SUBSYS_PCI_TR :
case NETTL_SUBSYS_NS_LS_IP :
case NETTL_SUBSYS_NS_LS_LOOPBACK :
case NETTL_SUBSYS_NS_LS_TCP :
case NETTL_SUBSYS_NS_LS_UDP :
case NETTL_SUBSYS_HP_APAPORT :
case NETTL_SUBSYS_HP_APALACP :
case NETTL_SUBSYS_NS_LS_IPV6 :
case NETTL_SUBSYS_NS_LS_ICMPV6 :
case NETTL_SUBSYS_NS_LS_ICMP :
case NETTL_SUBSYS_NS_LS_TELNET :
case NETTL_SUBSYS_NS_LS_SCTP :
if( (subsys == NETTL_SUBSYS_NS_LS_IP)
|| (subsys == NETTL_SUBSYS_NS_LS_LOOPBACK)
|| (subsys == NETTL_SUBSYS_NS_LS_UDP)
|| (subsys == NETTL_SUBSYS_NS_LS_TCP)
|| (subsys == NETTL_SUBSYS_NS_LS_SCTP)
|| (subsys == NETTL_SUBSYS_NS_LS_IPV6)) {
phdr->pkt_encap = WTAP_ENCAP_NETTL_RAW_IP;
} else if (subsys == NETTL_SUBSYS_NS_LS_ICMP) {
phdr->pkt_encap = WTAP_ENCAP_NETTL_RAW_ICMP;
} else if (subsys == NETTL_SUBSYS_NS_LS_ICMPV6) {
phdr->pkt_encap = WTAP_ENCAP_NETTL_RAW_ICMPV6;
} else if (subsys == NETTL_SUBSYS_NS_LS_TELNET) {
phdr->pkt_encap = WTAP_ENCAP_NETTL_RAW_TELNET;
} else if( (subsys == NETTL_SUBSYS_HPPB_FDDI)
|| (subsys == NETTL_SUBSYS_EISA_FDDI)
|| (subsys == NETTL_SUBSYS_PCI_FDDI)
|| (subsys == NETTL_SUBSYS_HSC_FDDI) ) {
phdr->pkt_encap = WTAP_ENCAP_NETTL_FDDI;
} else if( (subsys == NETTL_SUBSYS_PCI_TR)
|| (subsys == NETTL_SUBSYS_TOKEN) ) {
phdr->pkt_encap = WTAP_ENCAP_NETTL_TOKEN_RING;
} else {
phdr->pkt_encap = WTAP_ENCAP_NETTL_ETHERNET;
}
length = pntohl(&rec_hdr.length);
caplen = pntohl(&rec_hdr.caplen);
if (subsys == NETTL_SUBSYS_HPPB_FDDI) {
if (pntohl(&rec_hdr.kind) == NETTL_HDR_PDUIN) {
fddihack=TRUE;
padlen = 0;
} else {
bytes_read = file_read(dummyc, 9, fh);
if (bytes_read != 9) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
padlen = (int)dummyc[8];
if (file_seek(fh, padlen, SEEK_CUR, err) == -1)
return FALSE;
padlen += 9;
}
} else if ( (subsys == NETTL_SUBSYS_PCI_FDDI)
|| (subsys == NETTL_SUBSYS_EISA_FDDI)
|| (subsys == NETTL_SUBSYS_HSC_FDDI) ) {
if (file_seek(fh, 3, SEEK_CUR, err) == -1)
return FALSE;
padlen = 3;
} else if (subsys == NETTL_SUBSYS_NS_LS_LOOPBACK) {
if (file_seek(fh, 26, SEEK_CUR, err) == -1)
return FALSE;
padlen = 26;
} else if (subsys == NETTL_SUBSYS_NS_LS_SCTP) {
if (file_seek(fh, 8, SEEK_CUR, err) == -1)
return FALSE;
padlen = 8;
} else {
padlen = 0;
}
break;
case NETTL_SUBSYS_NS_LS_DRIVER :
phdr->pkt_encap = WTAP_ENCAP_NETTL_ETHERNET;
bytes_read = file_read(&drv_eth_hdr, NS_LS_DRV_ETH_HDR_LEN, fh);
if (bytes_read != NS_LS_DRV_ETH_HDR_LEN) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
length = pntohs(&drv_eth_hdr.length);
caplen = pntohs(&drv_eth_hdr.caplen);
if (nettl->is_hpux_11) {
if (file_seek(fh, 2, SEEK_CUR, err) == -1) return FALSE;
}
padlen = 0;
break;
case NETTL_SUBSYS_SX25L2:
case NETTL_SUBSYS_SX25L3:
phdr->pkt_encap = WTAP_ENCAP_NETTL_X25;
length = pntohl(&rec_hdr.length);
caplen = pntohl(&rec_hdr.caplen);
padlen = 24;
if (file_seek(fh, padlen, SEEK_CUR, err) == -1)
return FALSE;
break;
default:
wth->file_encap = WTAP_ENCAP_PER_PACKET;
phdr->pkt_encap = WTAP_ENCAP_NETTL_ETHERNET;
length = pntohl(&rec_hdr.length);
caplen = pntohl(&rec_hdr.caplen);
padlen = 0;
break;
}
if (length < padlen) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("nettl: packet length %u in record header too short, less than %u",
length, padlen);
return FALSE;
}
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
phdr->len = length - padlen;
if (caplen < padlen) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("nettl: captured length %u in record header too short, less than %u",
caplen, padlen);
return FALSE;
}
datalen = caplen - padlen;
phdr->caplen = datalen;
phdr->ts.secs = pntohl(&rec_hdr.sec);
phdr->ts.nsecs = pntohl(&rec_hdr.usec) * 1000;
pseudo_header->nettl.subsys = subsys;
pseudo_header->nettl.devid = pntohl(&rec_hdr.devid);
pseudo_header->nettl.kind = pntohl(&rec_hdr.kind);
pseudo_header->nettl.pid = pntohl(&rec_hdr.pid);
pseudo_header->nettl.uid = pntohs(&rec_hdr.uid);
if (phdr->caplen > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("nettl: File has %u-byte packet, bigger than maximum of %u",
phdr->caplen, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
buffer_assure_space(buf, datalen);
pd = buffer_start_ptr(buf);
errno = WTAP_ERR_CANT_READ;
if (fddihack) {
bytes_to_read = 15;
if (bytes_to_read > datalen)
bytes_to_read = datalen;
bytes_read = file_read(pd, bytes_to_read, fh);
if (bytes_read != bytes_to_read) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
datalen -= bytes_read;
if (datalen == 0) {
return TRUE;
}
if (pd[13] == 0xAA) {
bytes_to_read = 3;
if (bytes_to_read > datalen)
bytes_to_read = datalen;
bytes_read = file_read(dummy, bytes_to_read, fh);
if (bytes_read != bytes_to_read) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
datalen -= bytes_read;
if (datalen == 0) {
return TRUE;
}
}
bytes_read = file_read(pd + 15, datalen, fh);
} else
bytes_read = file_read(pd, datalen, fh);
if (bytes_read != datalen) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
int nettl_dump_can_write_encap(int encap)
{
switch (encap) {
case WTAP_ENCAP_ETHERNET:
case WTAP_ENCAP_FDDI_BITSWAPPED:
case WTAP_ENCAP_TOKEN_RING:
case WTAP_ENCAP_NETTL_ETHERNET:
case WTAP_ENCAP_NETTL_FDDI:
case WTAP_ENCAP_NETTL_TOKEN_RING:
case WTAP_ENCAP_NETTL_RAW_IP:
case WTAP_ENCAP_NETTL_RAW_ICMP:
case WTAP_ENCAP_NETTL_RAW_ICMPV6:
case WTAP_ENCAP_NETTL_RAW_TELNET:
case WTAP_ENCAP_PER_PACKET:
case WTAP_ENCAP_UNKNOWN:
case WTAP_ENCAP_NETTL_UNKNOWN:
return 0;
default:
return WTAP_ERR_UNSUPPORTED_ENCAP;
}
}
gboolean nettl_dump_open(wtap_dumper *wdh, int *err)
{
struct nettl_file_hdr file_hdr;
wdh->subtype_write = nettl_dump;
wdh->subtype_close = NULL;
memset(&file_hdr,0,sizeof(file_hdr));
memcpy(file_hdr.magic,nettl_magic_hpux10,sizeof(file_hdr.magic));
g_strlcpy(file_hdr.file_name,"/tmp/wireshark.TRC000",NETTL_FILENAME_SIZE);
g_strlcpy(file_hdr.tz,"UTC",20);
g_strlcpy(file_hdr.host_name,"",9);
g_strlcpy(file_hdr.os_vers,"B.11.11",9);
file_hdr.os_v=0x55;
g_strlcpy(file_hdr.model,"9000/800",11);
file_hdr.unknown=g_htons(0x406);
if (!wtap_dump_file_write(wdh, &file_hdr, sizeof file_hdr, err))
return FALSE;
wdh->bytes_dumped += sizeof(file_hdr);
return TRUE;
}
static gboolean nettl_dump(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err)
{
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
struct nettlrec_hdr rec_hdr;
guint8 dummyc[24];
memset(&rec_hdr,0,sizeof(rec_hdr));
rec_hdr.hdr_len = g_htons(sizeof(rec_hdr) + 4);
rec_hdr.kind = g_htonl(NETTL_HDR_PDUIN);
rec_hdr.sec = g_htonl(phdr->ts.secs);
rec_hdr.usec = g_htonl(phdr->ts.nsecs/1000);
rec_hdr.caplen = g_htonl(phdr->caplen);
rec_hdr.length = g_htonl(phdr->len);
rec_hdr.devid = -1;
rec_hdr.pid = -1;
rec_hdr.uid = -1;
switch (phdr->pkt_encap) {
case WTAP_ENCAP_NETTL_FDDI:
rec_hdr.caplen = g_htonl(phdr->caplen + 3);
rec_hdr.length = g_htonl(phdr->len + 3);
case WTAP_ENCAP_NETTL_ETHERNET:
case WTAP_ENCAP_NETTL_TOKEN_RING:
case WTAP_ENCAP_NETTL_RAW_IP:
case WTAP_ENCAP_NETTL_RAW_ICMP:
case WTAP_ENCAP_NETTL_RAW_ICMPV6:
case WTAP_ENCAP_NETTL_RAW_TELNET:
case WTAP_ENCAP_NETTL_UNKNOWN:
rec_hdr.subsys = g_htons(pseudo_header->nettl.subsys);
rec_hdr.devid = g_htonl(pseudo_header->nettl.devid);
rec_hdr.kind = g_htonl(pseudo_header->nettl.kind);
rec_hdr.pid = g_htonl(pseudo_header->nettl.pid);
rec_hdr.uid = g_htons(pseudo_header->nettl.uid);
break;
case WTAP_ENCAP_RAW_IP:
rec_hdr.subsys = g_htons(NETTL_SUBSYS_NS_LS_IP);
break;
case WTAP_ENCAP_ETHERNET:
rec_hdr.subsys = g_htons(NETTL_SUBSYS_BTLAN);
break;
case WTAP_ENCAP_FDDI_BITSWAPPED:
rec_hdr.subsys = g_htons(NETTL_SUBSYS_PCI_FDDI);
rec_hdr.caplen = g_htonl(phdr->caplen + 3);
rec_hdr.length = g_htonl(phdr->len + 3);
break;
case WTAP_ENCAP_TOKEN_RING:
rec_hdr.subsys = g_htons(NETTL_SUBSYS_PCI_TR);
break;
default:
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
return FALSE;
}
if (!wtap_dump_file_write(wdh, &rec_hdr, sizeof(rec_hdr), err))
return FALSE;
wdh->bytes_dumped += sizeof(rec_hdr);
memset(dummyc, 0, sizeof dummyc);
if (!wtap_dump_file_write(wdh, dummyc, 4, err))
return FALSE;
wdh->bytes_dumped += 4;
if ((phdr->pkt_encap == WTAP_ENCAP_FDDI_BITSWAPPED) ||
(phdr->pkt_encap == WTAP_ENCAP_NETTL_FDDI)) {
if (!wtap_dump_file_write(wdh, dummyc, 3, err))
return FALSE;
wdh->bytes_dumped += 3;
}
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
wdh->bytes_dumped += phdr->caplen;
return TRUE;
}
