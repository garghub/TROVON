static int uea_send_modem_cmd(struct usb_device *usb,
u16 addr, u16 size, const u8 *buff)
{
int ret = -ENOMEM;
u8 *xfer_buff;
xfer_buff = kmemdup(buff, size, GFP_KERNEL);
if (xfer_buff) {
ret = usb_control_msg(usb,
usb_sndctrlpipe(usb, 0),
LOAD_INTERNAL,
USB_DIR_OUT | USB_TYPE_VENDOR |
USB_RECIP_DEVICE, addr, 0, xfer_buff,
size, CTRL_TIMEOUT);
kfree(xfer_buff);
}
if (ret < 0)
return ret;
return (ret == size) ? 0 : -EIO;
}
static void uea_upload_pre_firmware(const struct firmware *fw_entry,
void *context)
{
struct usb_device *usb = context;
const u8 *pfw;
u8 value;
u32 crc = 0;
int ret, size;
uea_enters(usb);
if (!fw_entry) {
uea_err(usb, "firmware is not available\n");
goto err;
}
pfw = fw_entry->data;
size = fw_entry->size;
if (size < 4)
goto err_fw_corrupted;
crc = get_unaligned_le32(pfw);
pfw += 4;
size -= 4;
if (crc32_be(0, pfw, size) != crc)
goto err_fw_corrupted;
value = 1;
ret = uea_send_modem_cmd(usb, F8051_USBCS, sizeof(value), &value);
if (ret < 0) {
uea_err(usb, "modem reset failed with error %d\n", ret);
goto err;
}
while (size > 3) {
u8 len = FW_GET_BYTE(pfw);
u16 add = get_unaligned_le16(pfw + 1);
size -= len + 3;
if (size < 0)
goto err_fw_corrupted;
ret = uea_send_modem_cmd(usb, add, len, pfw + 3);
if (ret < 0) {
uea_err(usb, "uploading firmware data failed "
"with error %d\n", ret);
goto err;
}
pfw += len + 3;
}
if (size != 0)
goto err_fw_corrupted;
value = 0;
ret = uea_send_modem_cmd(usb, F8051_USBCS, 1, &value);
if (ret < 0)
uea_err(usb, "modem de-assert failed with error %d\n", ret);
else
uea_info(usb, "firmware uploaded\n");
goto err;
err_fw_corrupted:
uea_err(usb, "firmware is corrupted\n");
err:
release_firmware(fw_entry);
uea_leaves(usb);
}
static int uea_load_firmware(struct usb_device *usb, unsigned int ver)
{
int ret;
char *fw_name = FW_DIR "eagle.fw";
uea_enters(usb);
uea_info(usb, "pre-firmware device, uploading firmware\n");
switch (ver) {
case ADI930:
fw_name = FW_DIR "adi930.fw";
break;
case EAGLE_I:
fw_name = FW_DIR "eagleI.fw";
break;
case EAGLE_II:
fw_name = FW_DIR "eagleII.fw";
break;
case EAGLE_III:
fw_name = FW_DIR "eagleIII.fw";
break;
case EAGLE_IV:
fw_name = FW_DIR "eagleIV.fw";
break;
}
ret = request_firmware_nowait(THIS_MODULE, 1, fw_name, &usb->dev,
GFP_KERNEL, usb,
uea_upload_pre_firmware);
if (ret)
uea_err(usb, "firmware %s is not available\n", fw_name);
else
uea_info(usb, "loading firmware %s\n", fw_name);
uea_leaves(usb);
return ret;
}
static int check_dsp_e1(const u8 *dsp, unsigned int len)
{
u8 pagecount, blockcount;
u16 blocksize;
u32 pageoffset;
unsigned int i, j, p, pp;
pagecount = FW_GET_BYTE(dsp);
p = 1;
if (p + 4 * pagecount > len)
return 1;
for (i = 0; i < pagecount; i++) {
pageoffset = get_unaligned_le32(dsp + p);
p += 4;
if (pageoffset == 0)
continue;
if (pageoffset >= len)
return 1;
pp = pageoffset;
blockcount = FW_GET_BYTE(dsp + pp);
pp += 1;
for (j = 0; j < blockcount; j++) {
if (pp + 4 > len)
return 1;
pp += 2;
blocksize = get_unaligned_le16(dsp + pp);
pp += 2;
if (pp + blocksize > len)
return 1;
pp += blocksize;
}
}
return 0;
}
static int check_dsp_e4(const u8 *dsp, int len)
{
int i;
struct l1_code *p = (struct l1_code *) dsp;
unsigned int sum = p->code - dsp;
if (len < sum)
return 1;
if (strcmp("STRATIPHY ANEXA", p->string_header) != 0 &&
strcmp("STRATIPHY ANEXB", p->string_header) != 0)
return 1;
for (i = 0; i < E4_MAX_PAGE_NUMBER; i++) {
struct block_index *blockidx;
u8 blockno = p->page_number_to_block_index[i];
if (blockno >= E4_NO_SWAPPAGE_HEADERS)
continue;
do {
u64 l;
if (blockno >= E4_NO_SWAPPAGE_HEADERS)
return 1;
blockidx = &p->page_header[blockno++];
if ((u8 *)(blockidx + 1) - dsp >= len)
return 1;
if (le16_to_cpu(blockidx->PageNumber) != i)
return 1;
l = E4_PAGE_BYTES(blockidx->PageSize);
sum += l;
l += le32_to_cpu(blockidx->PageOffset);
if (l > len)
return 1;
} while (blockidx->NotLastBlock);
}
return (sum == len) ? 0 : 1;
}
static int uea_idma_write(struct uea_softc *sc, const void *data, u32 size)
{
int ret = -ENOMEM;
u8 *xfer_buff;
int bytes_read;
xfer_buff = kmemdup(data, size, GFP_KERNEL);
if (!xfer_buff) {
uea_err(INS_TO_USBDEV(sc), "can't allocate xfer_buff\n");
return ret;
}
ret = usb_bulk_msg(sc->usb_dev,
usb_sndbulkpipe(sc->usb_dev, UEA_IDMA_PIPE),
xfer_buff, size, &bytes_read, BULK_TIMEOUT);
kfree(xfer_buff);
if (ret < 0)
return ret;
if (size != bytes_read) {
uea_err(INS_TO_USBDEV(sc), "size != bytes_read %d %d\n", size,
bytes_read);
return -EIO;
}
return 0;
}
static int request_dsp(struct uea_softc *sc)
{
int ret;
char *dsp_name;
if (UEA_CHIP_VERSION(sc) == EAGLE_IV) {
if (IS_ISDN(sc))
dsp_name = FW_DIR "DSP4i.bin";
else
dsp_name = FW_DIR "DSP4p.bin";
} else if (UEA_CHIP_VERSION(sc) == ADI930) {
if (IS_ISDN(sc))
dsp_name = FW_DIR "DSP9i.bin";
else
dsp_name = FW_DIR "DSP9p.bin";
} else {
if (IS_ISDN(sc))
dsp_name = FW_DIR "DSPei.bin";
else
dsp_name = FW_DIR "DSPep.bin";
}
ret = request_firmware(&sc->dsp_firm, dsp_name, &sc->usb_dev->dev);
if (ret < 0) {
uea_err(INS_TO_USBDEV(sc),
"requesting firmware %s failed with error %d\n",
dsp_name, ret);
return ret;
}
if (UEA_CHIP_VERSION(sc) == EAGLE_IV)
ret = check_dsp_e4(sc->dsp_firm->data, sc->dsp_firm->size);
else
ret = check_dsp_e1(sc->dsp_firm->data, sc->dsp_firm->size);
if (ret) {
uea_err(INS_TO_USBDEV(sc), "firmware %s is corrupted\n",
dsp_name);
release_firmware(sc->dsp_firm);
sc->dsp_firm = NULL;
return -EILSEQ;
}
return 0;
}
static void uea_load_page_e1(struct work_struct *work)
{
struct uea_softc *sc = container_of(work, struct uea_softc, task);
u16 pageno = sc->pageno;
u16 ovl = sc->ovl;
struct block_info_e1 bi;
const u8 *p;
u8 pagecount, blockcount;
u16 blockaddr, blocksize;
u32 pageoffset;
int i;
if (ovl == 0 && pageno == 0 && sc->dsp_firm) {
release_firmware(sc->dsp_firm);
sc->dsp_firm = NULL;
}
if (sc->dsp_firm == NULL && request_dsp(sc) < 0)
return;
p = sc->dsp_firm->data;
pagecount = FW_GET_BYTE(p);
p += 1;
if (pageno >= pagecount)
goto bad1;
p += 4 * pageno;
pageoffset = get_unaligned_le32(p);
if (pageoffset == 0)
goto bad1;
p = sc->dsp_firm->data + pageoffset;
blockcount = FW_GET_BYTE(p);
p += 1;
uea_dbg(INS_TO_USBDEV(sc),
"sending %u blocks for DSP page %u\n", blockcount, pageno);
bi.wHdr = cpu_to_le16(UEA_BIHDR);
bi.wOvl = cpu_to_le16(ovl);
bi.wOvlOffset = cpu_to_le16(ovl | 0x8000);
for (i = 0; i < blockcount; i++) {
blockaddr = get_unaligned_le16(p);
p += 2;
blocksize = get_unaligned_le16(p);
p += 2;
bi.wSize = cpu_to_le16(blocksize);
bi.wAddress = cpu_to_le16(blockaddr);
bi.wLast = cpu_to_le16((i == blockcount - 1) ? 1 : 0);
if (uea_idma_write(sc, &bi, E1_BLOCK_INFO_SIZE))
goto bad2;
if (uea_idma_write(sc, p, blocksize))
goto bad2;
p += blocksize;
}
return;
bad2:
uea_err(INS_TO_USBDEV(sc), "sending DSP block %u failed\n", i);
return;
bad1:
uea_err(INS_TO_USBDEV(sc), "invalid DSP page %u requested\n", pageno);
}
static void __uea_load_page_e4(struct uea_softc *sc, u8 pageno, int boot)
{
struct block_info_e4 bi;
struct block_index *blockidx;
struct l1_code *p = (struct l1_code *) sc->dsp_firm->data;
u8 blockno = p->page_number_to_block_index[pageno];
bi.wHdr = cpu_to_be16(UEA_BIHDR);
bi.bBootPage = boot;
bi.bPageNumber = pageno;
bi.wReserved = cpu_to_be16(UEA_RESERVED);
do {
const u8 *blockoffset;
unsigned int blocksize;
blockidx = &p->page_header[blockno];
blocksize = E4_PAGE_BYTES(blockidx->PageSize);
blockoffset = sc->dsp_firm->data + le32_to_cpu(
blockidx->PageOffset);
bi.dwSize = cpu_to_be32(blocksize);
bi.dwAddress = cpu_to_be32(le32_to_cpu(blockidx->PageAddress));
uea_dbg(INS_TO_USBDEV(sc),
"sending block %u for DSP page "
"%u size %u address %x\n",
blockno, pageno, blocksize,
le32_to_cpu(blockidx->PageAddress));
if (uea_idma_write(sc, &bi, E4_BLOCK_INFO_SIZE))
goto bad;
if (uea_idma_write(sc, blockoffset, blocksize))
goto bad;
blockno++;
} while (blockidx->NotLastBlock);
return;
bad:
uea_err(INS_TO_USBDEV(sc), "sending DSP block %u failed\n", blockno);
return;
}
static void uea_load_page_e4(struct work_struct *work)
{
struct uea_softc *sc = container_of(work, struct uea_softc, task);
u8 pageno = sc->pageno;
int i;
struct block_info_e4 bi;
struct l1_code *p;
uea_dbg(INS_TO_USBDEV(sc), "sending DSP page %u\n", pageno);
if (pageno == 0 && sc->dsp_firm) {
release_firmware(sc->dsp_firm);
sc->dsp_firm = NULL;
}
if (sc->dsp_firm == NULL && request_dsp(sc) < 0)
return;
p = (struct l1_code *) sc->dsp_firm->data;
if (pageno >= le16_to_cpu(p->page_header[0].PageNumber)) {
uea_err(INS_TO_USBDEV(sc), "invalid DSP "
"page %u requested\n", pageno);
return;
}
if (pageno != 0) {
__uea_load_page_e4(sc, pageno, 0);
return;
}
uea_dbg(INS_TO_USBDEV(sc),
"sending Main DSP page %u\n", p->page_header[0].PageNumber);
for (i = 0; i < le16_to_cpu(p->page_header[0].PageNumber); i++) {
if (E4_IS_BOOT_PAGE(p->page_header[i].PageSize))
__uea_load_page_e4(sc, i, 1);
}
uea_dbg(INS_TO_USBDEV(sc) , "sending start bi\n");
bi.wHdr = cpu_to_be16(UEA_BIHDR);
bi.bBootPage = 0;
bi.bPageNumber = 0xff;
bi.wReserved = cpu_to_be16(UEA_RESERVED);
bi.dwSize = cpu_to_be32(E4_PAGE_BYTES(p->page_header[0].PageSize));
bi.dwAddress = cpu_to_be32(le32_to_cpu(p->page_header[0].PageAddress));
if (uea_idma_write(sc, &bi, E4_BLOCK_INFO_SIZE))
uea_err(INS_TO_USBDEV(sc), "sending DSP start bi failed\n");
}
static inline void wake_up_cmv_ack(struct uea_softc *sc)
{
BUG_ON(sc->cmv_ack);
sc->cmv_ack = 1;
wake_up(&sc->sync_q);
}
static inline int wait_cmv_ack(struct uea_softc *sc)
{
int ret = uea_wait(sc, sc->cmv_ack , ACK_TIMEOUT);
sc->cmv_ack = 0;
uea_dbg(INS_TO_USBDEV(sc), "wait_event_timeout : %d ms\n",
jiffies_to_msecs(ret));
if (ret < 0)
return ret;
return (ret == 0) ? -ETIMEDOUT : 0;
}
static int uea_request(struct uea_softc *sc,
u16 value, u16 index, u16 size, const void *data)
{
u8 *xfer_buff;
int ret = -ENOMEM;
xfer_buff = kmemdup(data, size, GFP_KERNEL);
if (!xfer_buff) {
uea_err(INS_TO_USBDEV(sc), "can't allocate xfer_buff\n");
return ret;
}
ret = usb_control_msg(sc->usb_dev, usb_sndctrlpipe(sc->usb_dev, 0),
UCDC_SEND_ENCAPSULATED_COMMAND,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, xfer_buff, size, CTRL_TIMEOUT);
kfree(xfer_buff);
if (ret < 0) {
uea_err(INS_TO_USBDEV(sc), "usb_control_msg error %d\n", ret);
return ret;
}
if (ret != size) {
uea_err(INS_TO_USBDEV(sc),
"usb_control_msg send only %d bytes (instead of %d)\n",
ret, size);
return -EIO;
}
return 0;
}
static int uea_cmv_e1(struct uea_softc *sc,
u8 function, u32 address, u16 offset, u32 data)
{
struct cmv_e1 cmv;
int ret;
uea_enters(INS_TO_USBDEV(sc));
uea_vdbg(INS_TO_USBDEV(sc), "Function : %d-%d, Address : %c%c%c%c, "
"offset : 0x%04x, data : 0x%08x\n",
E1_FUNCTION_TYPE(function),
E1_FUNCTION_SUBTYPE(function),
E1_GETSA1(address), E1_GETSA2(address),
E1_GETSA3(address),
E1_GETSA4(address), offset, data);
sc->cmv_dsc.e1.function = function | 0x2;
sc->cmv_dsc.e1.idx++;
sc->cmv_dsc.e1.address = address;
sc->cmv_dsc.e1.offset = offset;
cmv.wPreamble = cpu_to_le16(E1_PREAMBLE);
cmv.bDirection = E1_HOSTTOMODEM;
cmv.bFunction = function;
cmv.wIndex = cpu_to_le16(sc->cmv_dsc.e1.idx);
put_unaligned_le32(address, &cmv.dwSymbolicAddress);
cmv.wOffsetAddress = cpu_to_le16(offset);
put_unaligned_le32(data >> 16 | data << 16, &cmv.dwData);
ret = uea_request(sc, UEA_E1_SET_BLOCK, UEA_MPTX_START,
sizeof(cmv), &cmv);
if (ret < 0)
return ret;
ret = wait_cmv_ack(sc);
uea_leaves(INS_TO_USBDEV(sc));
return ret;
}
static int uea_cmv_e4(struct uea_softc *sc,
u16 function, u16 group, u16 address, u16 offset, u32 data)
{
struct cmv_e4 cmv;
int ret;
uea_enters(INS_TO_USBDEV(sc));
memset(&cmv, 0, sizeof(cmv));
uea_vdbg(INS_TO_USBDEV(sc), "Function : %d-%d, Group : 0x%04x, "
"Address : 0x%04x, offset : 0x%04x, data : 0x%08x\n",
E4_FUNCTION_TYPE(function), E4_FUNCTION_SUBTYPE(function),
group, address, offset, data);
sc->cmv_dsc.e4.function = function | (0x1 << 4);
sc->cmv_dsc.e4.offset = offset;
sc->cmv_dsc.e4.address = address;
sc->cmv_dsc.e4.group = group;
cmv.wFunction = cpu_to_be16(function);
cmv.wGroup = cpu_to_be16(group);
cmv.wAddress = cpu_to_be16(address);
cmv.wOffset = cpu_to_be16(offset);
cmv.dwData[0] = cpu_to_be32(data);
ret = uea_request(sc, UEA_E4_SET_BLOCK, UEA_MPTX_START,
sizeof(cmv), &cmv);
if (ret < 0)
return ret;
ret = wait_cmv_ack(sc);
uea_leaves(INS_TO_USBDEV(sc));
return ret;
}
static inline int uea_read_cmv_e1(struct uea_softc *sc,
u32 address, u16 offset, u32 *data)
{
int ret = uea_cmv_e1(sc, E1_MAKEFUNCTION(E1_MEMACCESS, E1_REQUESTREAD),
address, offset, 0);
if (ret < 0)
uea_err(INS_TO_USBDEV(sc),
"reading cmv failed with error %d\n", ret);
else
*data = sc->data;
return ret;
}
static inline int uea_read_cmv_e4(struct uea_softc *sc,
u8 size, u16 group, u16 address, u16 offset, u32 *data)
{
int ret = uea_cmv_e4(sc, E4_MAKEFUNCTION(E4_MEMACCESS,
E4_REQUESTREAD, size),
group, address, offset, 0);
if (ret < 0)
uea_err(INS_TO_USBDEV(sc),
"reading cmv failed with error %d\n", ret);
else {
*data = sc->data;
if (size > 2)
*(data + 1) = sc->data1;
}
return ret;
}
static inline int uea_write_cmv_e1(struct uea_softc *sc,
u32 address, u16 offset, u32 data)
{
int ret = uea_cmv_e1(sc, E1_MAKEFUNCTION(E1_MEMACCESS, E1_REQUESTWRITE),
address, offset, data);
if (ret < 0)
uea_err(INS_TO_USBDEV(sc),
"writing cmv failed with error %d\n", ret);
return ret;
}
static inline int uea_write_cmv_e4(struct uea_softc *sc,
u8 size, u16 group, u16 address, u16 offset, u32 data)
{
int ret = uea_cmv_e4(sc, E4_MAKEFUNCTION(E4_MEMACCESS,
E4_REQUESTWRITE, size),
group, address, offset, data);
if (ret < 0)
uea_err(INS_TO_USBDEV(sc),
"writing cmv failed with error %d\n", ret);
return ret;
}
static void uea_set_bulk_timeout(struct uea_softc *sc, u32 dsrate)
{
int ret;
u16 timeout;
if (UEA_CHIP_VERSION(sc) == ADI930 ||
altsetting[sc->modem_index] > 0 ||
sc->stats.phy.dsrate == dsrate)
return;
timeout = (dsrate <= 1024*1024) ? 0 : 1;
ret = uea_request(sc, UEA_SET_TIMEOUT, timeout, 0, NULL);
uea_info(INS_TO_USBDEV(sc), "setting new timeout %d%s\n",
timeout, ret < 0 ? " failed" : "");
}
static int uea_stat_e1(struct uea_softc *sc)
{
u32 data;
int ret;
uea_enters(INS_TO_USBDEV(sc));
data = sc->stats.phy.state;
ret = uea_read_cmv_e1(sc, E1_SA_STAT, 0, &sc->stats.phy.state);
if (ret < 0)
return ret;
switch (GET_STATUS(sc->stats.phy.state)) {
case 0:
uea_dbg(INS_TO_USBDEV(sc),
"modem not yet synchronized\n");
return 0;
case 1:
uea_dbg(INS_TO_USBDEV(sc), "modem initializing\n");
return 0;
case 2:
uea_vdbg(INS_TO_USBDEV(sc), "modem operational\n");
break;
case 3:
uea_info(INS_TO_USBDEV(sc), "modem synchronization failed"
" (may be try other cmv/dsp)\n");
return -EAGAIN;
case 4 ... 6:
uea_warn(INS_TO_USBDEV(sc),
"modem in test mode - not supported\n");
return -EAGAIN;
case 7:
uea_info(INS_TO_USBDEV(sc), "modem in fast-retain mode\n");
return 0;
default:
uea_err(INS_TO_USBDEV(sc), "modem invalid SW mode %d\n",
GET_STATUS(sc->stats.phy.state));
return -EAGAIN;
}
if (GET_STATUS(data) != 2) {
uea_request(sc, UEA_SET_MODE, UEA_LOOPBACK_OFF, 0, NULL);
uea_info(INS_TO_USBDEV(sc), "modem operational\n");
if (sc->dsp_firm) {
release_firmware(sc->dsp_firm);
sc->dsp_firm = NULL;
}
}
UPDATE_ATM_SIGNAL(ATM_PHY_SIG_FOUND);
wake_up(&sc->sync_q);
ret = uea_read_cmv_e1(sc, E1_SA_DIAG, 2, &sc->stats.phy.flags);
if (ret < 0)
return ret;
sc->stats.phy.mflags |= sc->stats.phy.flags;
if (sc->stats.phy.flags) {
uea_dbg(INS_TO_USBDEV(sc), "Stat flag = 0x%x\n",
sc->stats.phy.flags);
return 0;
}
ret = uea_read_cmv_e1(sc, E1_SA_RATE, 0, &data);
if (ret < 0)
return ret;
uea_set_bulk_timeout(sc, (data >> 16) * 32);
sc->stats.phy.dsrate = (data >> 16) * 32;
sc->stats.phy.usrate = (data & 0xffff) * 32;
UPDATE_ATM_STAT(link_rate, sc->stats.phy.dsrate * 1000 / 424);
ret = uea_read_cmv_e1(sc, E1_SA_DIAG, 23, &data);
if (ret < 0)
return ret;
sc->stats.phy.dsattenuation = (data & 0xff) / 2;
ret = uea_read_cmv_e1(sc, E1_SA_DIAG, 47, &data);
if (ret < 0)
return ret;
sc->stats.phy.usattenuation = (data & 0xff) / 2;
ret = uea_read_cmv_e1(sc, E1_SA_DIAG, 25, &sc->stats.phy.dsmargin);
if (ret < 0)
return ret;
ret = uea_read_cmv_e1(sc, E1_SA_DIAG, 49, &sc->stats.phy.usmargin);
if (ret < 0)
return ret;
ret = uea_read_cmv_e1(sc, E1_SA_DIAG, 51, &sc->stats.phy.rxflow);
if (ret < 0)
return ret;
ret = uea_read_cmv_e1(sc, E1_SA_DIAG, 52, &sc->stats.phy.txflow);
if (ret < 0)
return ret;
ret = uea_read_cmv_e1(sc, E1_SA_DIAG, 54, &sc->stats.phy.dsunc);
if (ret < 0)
return ret;
ret = uea_read_cmv_e1(sc, E1_SA_DIAG, 58, &sc->stats.phy.usunc);
if (ret < 0)
return ret;
ret = uea_read_cmv_e1(sc, E1_SA_DIAG, 53, &sc->stats.phy.dscorr);
if (ret < 0)
return ret;
ret = uea_read_cmv_e1(sc, E1_SA_DIAG, 57, &sc->stats.phy.uscorr);
if (ret < 0)
return ret;
ret = uea_read_cmv_e1(sc, E1_SA_INFO, 8, &sc->stats.phy.vidco);
if (ret < 0)
return ret;
ret = uea_read_cmv_e1(sc, E1_SA_INFO, 13, &sc->stats.phy.vidcpe);
if (ret < 0)
return ret;
return 0;
}
static int uea_stat_e4(struct uea_softc *sc)
{
u32 data;
u32 tmp_arr[2];
int ret;
uea_enters(INS_TO_USBDEV(sc));
data = sc->stats.phy.state;
ret = uea_read_cmv_e4(sc, 1, E4_SA_STAT, 0, 0, &sc->stats.phy.state);
if (ret < 0)
return ret;
switch (sc->stats.phy.state) {
case 0x0:
case 0x1:
case 0x3:
case 0x4:
uea_dbg(INS_TO_USBDEV(sc), "modem not yet "
"synchronized\n");
return 0;
case 0x5:
case 0x6:
case 0x9:
case 0xa:
uea_dbg(INS_TO_USBDEV(sc), "modem initializing\n");
return 0;
case 0x2:
uea_info(INS_TO_USBDEV(sc), "modem synchronization "
"failed (may be try other cmv/dsp)\n");
return -EAGAIN;
case 0x7:
break;
default:
uea_warn(INS_TO_USBDEV(sc), "unknown state: %x\n",
sc->stats.phy.state);
return 0;
}
if (data != 7) {
uea_request(sc, UEA_SET_MODE, UEA_LOOPBACK_OFF, 0, NULL);
uea_info(INS_TO_USBDEV(sc), "modem operational\n");
if (sc->dsp_firm) {
release_firmware(sc->dsp_firm);
sc->dsp_firm = NULL;
}
}
UPDATE_ATM_SIGNAL(ATM_PHY_SIG_FOUND);
wake_up(&sc->sync_q);
ret = uea_read_cmv_e4(sc, 1, E4_SA_DIAG, 0, 0, &sc->stats.phy.flags);
if (ret < 0)
return ret;
sc->stats.phy.mflags |= sc->stats.phy.flags;
if (sc->stats.phy.flags) {
uea_dbg(INS_TO_USBDEV(sc), "Stat flag = 0x%x\n",
sc->stats.phy.flags);
if (sc->stats.phy.flags & 1)
return -EAGAIN;
if (sc->stats.phy.flags & 0x4000)
return -EAGAIN;
return 0;
}
ret = uea_read_cmv_e4(sc, 4, E4_SA_RATE, 0, 0, tmp_arr);
if (ret < 0)
return ret;
data = (tmp_arr[0]) ? tmp_arr[0] : tmp_arr[1];
sc->stats.phy.usrate = data / 1000;
ret = uea_read_cmv_e4(sc, 4, E4_SA_RATE, 1, 0, tmp_arr);
if (ret < 0)
return ret;
data = (tmp_arr[0]) ? tmp_arr[0] : tmp_arr[1];
uea_set_bulk_timeout(sc, data / 1000);
sc->stats.phy.dsrate = data / 1000;
UPDATE_ATM_STAT(link_rate, sc->stats.phy.dsrate * 1000 / 424);
ret = uea_read_cmv_e4(sc, 1, E4_SA_INFO, 68, 1, &data);
if (ret < 0)
return ret;
sc->stats.phy.dsattenuation = data / 10;
ret = uea_read_cmv_e4(sc, 1, E4_SA_INFO, 69, 1, &data);
if (ret < 0)
return ret;
sc->stats.phy.usattenuation = data / 10;
ret = uea_read_cmv_e4(sc, 1, E4_SA_INFO, 68, 3, &data);
if (ret < 0)
return ret;
sc->stats.phy.dsmargin = data / 2;
ret = uea_read_cmv_e4(sc, 1, E4_SA_INFO, 69, 3, &data);
if (ret < 0)
return ret;
sc->stats.phy.usmargin = data / 10;
return 0;
}
static void cmvs_file_name(struct uea_softc *sc, char *const cmv_name, int ver)
{
char file_arr[] = "CMVxy.bin";
char *file;
kparam_block_sysfs_write(cmv_file);
if (cmv_file[sc->modem_index] == NULL) {
if (UEA_CHIP_VERSION(sc) == ADI930)
file_arr[3] = '9';
else if (UEA_CHIP_VERSION(sc) == EAGLE_IV)
file_arr[3] = '4';
else
file_arr[3] = 'e';
file_arr[4] = IS_ISDN(sc) ? 'i' : 'p';
file = file_arr;
} else
file = cmv_file[sc->modem_index];
strcpy(cmv_name, FW_DIR);
strlcat(cmv_name, file, UEA_FW_NAME_MAX);
if (ver == 2)
strlcat(cmv_name, ".v2", UEA_FW_NAME_MAX);
kparam_unblock_sysfs_write(cmv_file);
}
static int request_cmvs_old(struct uea_softc *sc,
void **cmvs, const struct firmware **fw)
{
int ret, size;
u8 *data;
char cmv_name[UEA_FW_NAME_MAX];
cmvs_file_name(sc, cmv_name, 1);
ret = request_firmware(fw, cmv_name, &sc->usb_dev->dev);
if (ret < 0) {
uea_err(INS_TO_USBDEV(sc),
"requesting firmware %s failed with error %d\n",
cmv_name, ret);
return ret;
}
data = (u8 *) (*fw)->data;
size = (*fw)->size;
if (size < 1)
goto err_fw_corrupted;
if (size != *data * sizeof(struct uea_cmvs_v1) + 1)
goto err_fw_corrupted;
*cmvs = (void *)(data + 1);
return *data;
err_fw_corrupted:
uea_err(INS_TO_USBDEV(sc), "firmware %s is corrupted\n", cmv_name);
release_firmware(*fw);
return -EILSEQ;
}
static int request_cmvs(struct uea_softc *sc,
void **cmvs, const struct firmware **fw, int *ver)
{
int ret, size;
u32 crc;
u8 *data;
char cmv_name[UEA_FW_NAME_MAX];
cmvs_file_name(sc, cmv_name, 2);
ret = request_firmware(fw, cmv_name, &sc->usb_dev->dev);
if (ret < 0) {
if (*ver == 1) {
uea_warn(INS_TO_USBDEV(sc), "requesting "
"firmware %s failed, "
"try to get older cmvs\n", cmv_name);
return request_cmvs_old(sc, cmvs, fw);
}
uea_err(INS_TO_USBDEV(sc),
"requesting firmware %s failed with error %d\n",
cmv_name, ret);
return ret;
}
size = (*fw)->size;
data = (u8 *) (*fw)->data;
if (size < 4 || strncmp(data, "cmv2", 4) != 0) {
if (*ver == 1) {
uea_warn(INS_TO_USBDEV(sc), "firmware %s is corrupted,"
" try to get older cmvs\n", cmv_name);
release_firmware(*fw);
return request_cmvs_old(sc, cmvs, fw);
}
goto err_fw_corrupted;
}
*ver = 2;
data += 4;
size -= 4;
if (size < 5)
goto err_fw_corrupted;
crc = get_unaligned_le32(data);
data += 4;
size -= 4;
if (crc32_be(0, data, size) != crc)
goto err_fw_corrupted;
if (size != *data * sizeof(struct uea_cmvs_v2) + 1)
goto err_fw_corrupted;
*cmvs = (void *) (data + 1);
return *data;
err_fw_corrupted:
uea_err(INS_TO_USBDEV(sc), "firmware %s is corrupted\n", cmv_name);
release_firmware(*fw);
return -EILSEQ;
}
static int uea_send_cmvs_e1(struct uea_softc *sc)
{
int i, ret, len;
void *cmvs_ptr;
const struct firmware *cmvs_fw;
int ver = 1;
ret = uea_write_cmv_e1(sc, E1_SA_CNTL, 0, 1);
if (ret < 0)
return ret;
ret = uea_read_cmv_e1(sc, E1_SA_INFO, 10, &sc->stats.phy.firmid);
if (ret < 0)
return ret;
uea_info(INS_TO_USBDEV(sc), "ATU-R firmware version : %x\n",
sc->stats.phy.firmid);
ret = len = request_cmvs(sc, &cmvs_ptr, &cmvs_fw, &ver);
if (ret < 0)
return ret;
if (ver == 1) {
struct uea_cmvs_v1 *cmvs_v1 = cmvs_ptr;
uea_warn(INS_TO_USBDEV(sc), "use deprecated cmvs version, "
"please update your firmware\n");
for (i = 0; i < len; i++) {
ret = uea_write_cmv_e1(sc,
get_unaligned_le32(&cmvs_v1[i].address),
get_unaligned_le16(&cmvs_v1[i].offset),
get_unaligned_le32(&cmvs_v1[i].data));
if (ret < 0)
goto out;
}
} else if (ver == 2) {
struct uea_cmvs_v2 *cmvs_v2 = cmvs_ptr;
for (i = 0; i < len; i++) {
ret = uea_write_cmv_e1(sc,
get_unaligned_le32(&cmvs_v2[i].address),
(u16) get_unaligned_le32(&cmvs_v2[i].offset),
get_unaligned_le32(&cmvs_v2[i].data));
if (ret < 0)
goto out;
}
} else {
uea_err(INS_TO_USBDEV(sc), "bad cmvs version %d\n", ver);
goto out;
}
ret = uea_write_cmv_e1(sc, E1_SA_CNTL, 0, 2);
uea_vdbg(INS_TO_USBDEV(sc), "Entering in R-ACT-REQ state\n");
uea_info(INS_TO_USBDEV(sc), "modem started, waiting "
"synchronization...\n");
out:
release_firmware(cmvs_fw);
return ret;
}
static int uea_send_cmvs_e4(struct uea_softc *sc)
{
int i, ret, len;
void *cmvs_ptr;
const struct firmware *cmvs_fw;
int ver = 2;
ret = uea_write_cmv_e4(sc, 1, E4_SA_CNTL, 0, 0, 1);
if (ret < 0)
return ret;
ret = uea_read_cmv_e4(sc, 2, E4_SA_INFO, 55, 0, &sc->stats.phy.firmid);
if (ret < 0)
return ret;
uea_info(INS_TO_USBDEV(sc), "ATU-R firmware version : %x\n",
sc->stats.phy.firmid);
ret = len = request_cmvs(sc, &cmvs_ptr, &cmvs_fw, &ver);
if (ret < 0)
return ret;
if (ver == 2) {
struct uea_cmvs_v2 *cmvs_v2 = cmvs_ptr;
for (i = 0; i < len; i++) {
ret = uea_write_cmv_e4(sc, 1,
get_unaligned_le32(&cmvs_v2[i].group),
get_unaligned_le32(&cmvs_v2[i].address),
get_unaligned_le32(&cmvs_v2[i].offset),
get_unaligned_le32(&cmvs_v2[i].data));
if (ret < 0)
goto out;
}
} else {
uea_err(INS_TO_USBDEV(sc), "bad cmvs version %d\n", ver);
goto out;
}
ret = uea_write_cmv_e4(sc, 1, E4_SA_CNTL, 0, 0, 2);
uea_vdbg(INS_TO_USBDEV(sc), "Entering in R-ACT-REQ state\n");
uea_info(INS_TO_USBDEV(sc), "modem started, waiting "
"synchronization...\n");
out:
release_firmware(cmvs_fw);
return ret;
}
static int uea_start_reset(struct uea_softc *sc)
{
u16 zero = 0;
int ret;
uea_enters(INS_TO_USBDEV(sc));
uea_info(INS_TO_USBDEV(sc), "(re)booting started\n");
sc->booting = 1;
sc->cmv_ack = 0;
UPDATE_ATM_SIGNAL(ATM_PHY_SIG_LOST);
memset(&sc->stats, 0, sizeof(struct uea_stats));
uea_request(sc, UEA_SET_MODE, UEA_LOOPBACK_ON, 0, NULL);
uea_request(sc, UEA_SET_MODE, UEA_BOOT_IDMA, 0, NULL);
uea_request(sc, UEA_SET_MODE, UEA_START_RESET, 0, NULL);
ret = uea_wait(sc, 0, msecs_to_jiffies(100));
if (ret < 0)
return ret;
uea_request(sc, UEA_SET_MODE, UEA_END_RESET, 0, NULL);
if (UEA_CHIP_VERSION(sc) != EAGLE_IV) {
uea_request(sc, UEA_SET_2183_DATA, UEA_MPTX_MAILBOX, 2, &zero);
uea_request(sc, UEA_SET_2183_DATA, UEA_MPRX_MAILBOX, 2, &zero);
uea_request(sc, UEA_SET_2183_DATA, UEA_SWAP_MAILBOX, 2, &zero);
}
ret = uea_wait(sc, 0, msecs_to_jiffies(1000));
if (ret < 0)
return ret;
if (UEA_CHIP_VERSION(sc) == EAGLE_IV)
sc->cmv_dsc.e4.function = E4_MAKEFUNCTION(E4_ADSLDIRECTIVE,
E4_MODEMREADY, 1);
else
sc->cmv_dsc.e1.function = E1_MAKEFUNCTION(E1_ADSLDIRECTIVE,
E1_MODEMREADY);
sc->booting = 0;
sc->pageno = 0;
sc->ovl = 0;
schedule_work(&sc->task);
ret = wait_cmv_ack(sc);
if (ret < 0)
return ret;
uea_vdbg(INS_TO_USBDEV(sc), "Ready CMV received\n");
ret = sc->send_cmvs(sc);
if (ret < 0)
return ret;
sc->reset = 0;
uea_leaves(INS_TO_USBDEV(sc));
return ret;
}
static int uea_kthread(void *data)
{
struct uea_softc *sc = data;
int ret = -EAGAIN;
set_freezable();
uea_enters(INS_TO_USBDEV(sc));
while (!kthread_should_stop()) {
if (ret < 0 || sc->reset)
ret = uea_start_reset(sc);
if (!ret)
ret = sc->stat(sc);
if (ret != -EAGAIN)
uea_wait(sc, 0, msecs_to_jiffies(1000));
try_to_freeze();
}
uea_leaves(INS_TO_USBDEV(sc));
return ret;
}
static int load_XILINX_firmware(struct uea_softc *sc)
{
const struct firmware *fw_entry;
int ret, size, u, ln;
const u8 *pfw;
u8 value;
char *fw_name = FW_DIR "930-fpga.bin";
uea_enters(INS_TO_USBDEV(sc));
ret = request_firmware(&fw_entry, fw_name, &sc->usb_dev->dev);
if (ret) {
uea_err(INS_TO_USBDEV(sc), "firmware %s is not available\n",
fw_name);
goto err0;
}
pfw = fw_entry->data;
size = fw_entry->size;
if (size != 0x577B) {
uea_err(INS_TO_USBDEV(sc), "firmware %s is corrupted\n",
fw_name);
ret = -EILSEQ;
goto err1;
}
for (u = 0; u < size; u += ln) {
ln = min(size - u, 64);
ret = uea_request(sc, 0xe, 0, ln, pfw + u);
if (ret < 0) {
uea_err(INS_TO_USBDEV(sc),
"elsa download data failed (%d)\n", ret);
goto err1;
}
}
ret = uea_request(sc, 0xe, 1, 0, NULL);
if (ret < 0) {
uea_err(INS_TO_USBDEV(sc),
"elsa download data failed (%d)\n", ret);
goto err1;
}
value = 0;
ret = uea_send_modem_cmd(sc->usb_dev, 0xe, 1, &value);
if (ret < 0)
uea_err(sc->usb_dev, "elsa de-assert failed with error"
" %d\n", ret);
err1:
release_firmware(fw_entry);
err0:
uea_leaves(INS_TO_USBDEV(sc));
return ret;
}
static void uea_dispatch_cmv_e1(struct uea_softc *sc, struct intr_pkt *intr)
{
struct cmv_dsc_e1 *dsc = &sc->cmv_dsc.e1;
struct cmv_e1 *cmv = &intr->u.e1.s2.cmv;
uea_enters(INS_TO_USBDEV(sc));
if (le16_to_cpu(cmv->wPreamble) != E1_PREAMBLE)
goto bad1;
if (cmv->bDirection != E1_MODEMTOHOST)
goto bad1;
if (cmv->bFunction != dsc->function) {
if (UEA_CHIP_VERSION(sc) == ADI930
&& cmv->bFunction == E1_MAKEFUNCTION(2, 2)) {
cmv->wIndex = cpu_to_le16(dsc->idx);
put_unaligned_le32(dsc->address,
&cmv->dwSymbolicAddress);
cmv->wOffsetAddress = cpu_to_le16(dsc->offset);
} else
goto bad2;
}
if (cmv->bFunction == E1_MAKEFUNCTION(E1_ADSLDIRECTIVE,
E1_MODEMREADY)) {
wake_up_cmv_ack(sc);
uea_leaves(INS_TO_USBDEV(sc));
return;
}
if (le16_to_cpu(cmv->wIndex) != dsc->idx ||
get_unaligned_le32(&cmv->dwSymbolicAddress) != dsc->address ||
le16_to_cpu(cmv->wOffsetAddress) != dsc->offset)
goto bad2;
sc->data = get_unaligned_le32(&cmv->dwData);
sc->data = sc->data << 16 | sc->data >> 16;
wake_up_cmv_ack(sc);
uea_leaves(INS_TO_USBDEV(sc));
return;
bad2:
uea_err(INS_TO_USBDEV(sc), "unexpected cmv received, "
"Function : %d, Subfunction : %d\n",
E1_FUNCTION_TYPE(cmv->bFunction),
E1_FUNCTION_SUBTYPE(cmv->bFunction));
uea_leaves(INS_TO_USBDEV(sc));
return;
bad1:
uea_err(INS_TO_USBDEV(sc), "invalid cmv received, "
"wPreamble %d, bDirection %d\n",
le16_to_cpu(cmv->wPreamble), cmv->bDirection);
uea_leaves(INS_TO_USBDEV(sc));
}
static void uea_dispatch_cmv_e4(struct uea_softc *sc, struct intr_pkt *intr)
{
struct cmv_dsc_e4 *dsc = &sc->cmv_dsc.e4;
struct cmv_e4 *cmv = &intr->u.e4.s2.cmv;
uea_enters(INS_TO_USBDEV(sc));
uea_dbg(INS_TO_USBDEV(sc), "cmv %x %x %x %x %x %x\n",
be16_to_cpu(cmv->wGroup), be16_to_cpu(cmv->wFunction),
be16_to_cpu(cmv->wOffset), be16_to_cpu(cmv->wAddress),
be32_to_cpu(cmv->dwData[0]), be32_to_cpu(cmv->dwData[1]));
if (be16_to_cpu(cmv->wFunction) != dsc->function)
goto bad2;
if (be16_to_cpu(cmv->wFunction) == E4_MAKEFUNCTION(E4_ADSLDIRECTIVE,
E4_MODEMREADY, 1)) {
wake_up_cmv_ack(sc);
uea_leaves(INS_TO_USBDEV(sc));
return;
}
if (be16_to_cpu(cmv->wOffset) != dsc->offset ||
be16_to_cpu(cmv->wGroup) != dsc->group ||
be16_to_cpu(cmv->wAddress) != dsc->address)
goto bad2;
sc->data = be32_to_cpu(cmv->dwData[0]);
sc->data1 = be32_to_cpu(cmv->dwData[1]);
wake_up_cmv_ack(sc);
uea_leaves(INS_TO_USBDEV(sc));
return;
bad2:
uea_err(INS_TO_USBDEV(sc), "unexpected cmv received, "
"Function : %d, Subfunction : %d\n",
E4_FUNCTION_TYPE(cmv->wFunction),
E4_FUNCTION_SUBTYPE(cmv->wFunction));
uea_leaves(INS_TO_USBDEV(sc));
return;
}
static void uea_schedule_load_page_e1(struct uea_softc *sc,
struct intr_pkt *intr)
{
sc->pageno = intr->e1_bSwapPageNo;
sc->ovl = intr->e1_bOvl >> 4 | intr->e1_bOvl << 4;
schedule_work(&sc->task);
}
static void uea_schedule_load_page_e4(struct uea_softc *sc,
struct intr_pkt *intr)
{
sc->pageno = intr->e4_bSwapPageNo;
schedule_work(&sc->task);
}
static void uea_intr(struct urb *urb)
{
struct uea_softc *sc = urb->context;
struct intr_pkt *intr = urb->transfer_buffer;
int status = urb->status;
uea_enters(INS_TO_USBDEV(sc));
if (unlikely(status < 0)) {
uea_err(INS_TO_USBDEV(sc), "uea_intr() failed with %d\n",
status);
return;
}
if (intr->bType != 0x08 || sc->booting) {
uea_err(INS_TO_USBDEV(sc), "wrong interrupt\n");
goto resubmit;
}
switch (le16_to_cpu(intr->wInterrupt)) {
case INT_LOADSWAPPAGE:
sc->schedule_load_page(sc, intr);
break;
case INT_INCOMINGCMV:
sc->dispatch_cmv(sc, intr);
break;
default:
uea_err(INS_TO_USBDEV(sc), "unknown interrupt %u\n",
le16_to_cpu(intr->wInterrupt));
}
resubmit:
usb_submit_urb(sc->urb_int, GFP_ATOMIC);
}
static int uea_boot(struct uea_softc *sc)
{
int ret, size;
struct intr_pkt *intr;
uea_enters(INS_TO_USBDEV(sc));
if (UEA_CHIP_VERSION(sc) == EAGLE_IV) {
size = E4_INTR_PKT_SIZE;
sc->dispatch_cmv = uea_dispatch_cmv_e4;
sc->schedule_load_page = uea_schedule_load_page_e4;
sc->stat = uea_stat_e4;
sc->send_cmvs = uea_send_cmvs_e4;
INIT_WORK(&sc->task, uea_load_page_e4);
} else {
size = E1_INTR_PKT_SIZE;
sc->dispatch_cmv = uea_dispatch_cmv_e1;
sc->schedule_load_page = uea_schedule_load_page_e1;
sc->stat = uea_stat_e1;
sc->send_cmvs = uea_send_cmvs_e1;
INIT_WORK(&sc->task, uea_load_page_e1);
}
init_waitqueue_head(&sc->sync_q);
if (UEA_CHIP_VERSION(sc) == ADI930)
load_XILINX_firmware(sc);
intr = kmalloc(size, GFP_KERNEL);
if (!intr) {
uea_err(INS_TO_USBDEV(sc),
"cannot allocate interrupt package\n");
goto err0;
}
sc->urb_int = usb_alloc_urb(0, GFP_KERNEL);
if (!sc->urb_int) {
uea_err(INS_TO_USBDEV(sc), "cannot allocate interrupt URB\n");
goto err1;
}
usb_fill_int_urb(sc->urb_int, sc->usb_dev,
usb_rcvintpipe(sc->usb_dev, UEA_INTR_PIPE),
intr, size, uea_intr, sc,
sc->usb_dev->actconfig->interface[0]->altsetting[0].
endpoint[0].desc.bInterval);
ret = usb_submit_urb(sc->urb_int, GFP_KERNEL);
if (ret < 0) {
uea_err(INS_TO_USBDEV(sc),
"urb submition failed with error %d\n", ret);
goto err1;
}
sc->kthread = kthread_create(uea_kthread, sc, "ueagle-atm");
if (IS_ERR(sc->kthread)) {
uea_err(INS_TO_USBDEV(sc), "failed to create thread\n");
goto err2;
}
uea_leaves(INS_TO_USBDEV(sc));
return 0;
err2:
usb_kill_urb(sc->urb_int);
err1:
usb_free_urb(sc->urb_int);
sc->urb_int = NULL;
kfree(intr);
err0:
uea_leaves(INS_TO_USBDEV(sc));
return -ENOMEM;
}
static void uea_stop(struct uea_softc *sc)
{
int ret;
uea_enters(INS_TO_USBDEV(sc));
ret = kthread_stop(sc->kthread);
uea_dbg(INS_TO_USBDEV(sc), "kthread finish with status %d\n", ret);
uea_request(sc, UEA_SET_MODE, UEA_LOOPBACK_ON, 0, NULL);
usb_kill_urb(sc->urb_int);
kfree(sc->urb_int->transfer_buffer);
usb_free_urb(sc->urb_int);
flush_work_sync(&sc->task);
if (sc->dsp_firm)
release_firmware(sc->dsp_firm);
uea_leaves(INS_TO_USBDEV(sc));
}
static struct uea_softc *dev_to_uea(struct device *dev)
{
struct usb_interface *intf;
struct usbatm_data *usbatm;
intf = to_usb_interface(dev);
if (!intf)
return NULL;
usbatm = usb_get_intfdata(intf);
if (!usbatm)
return NULL;
return usbatm->driver_data;
}
static ssize_t read_status(struct device *dev, struct device_attribute *attr,
char *buf)
{
int ret = -ENODEV;
struct uea_softc *sc;
mutex_lock(&uea_mutex);
sc = dev_to_uea(dev);
if (!sc)
goto out;
ret = snprintf(buf, 10, "%08x\n", sc->stats.phy.state);
out:
mutex_unlock(&uea_mutex);
return ret;
}
static ssize_t reboot(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int ret = -ENODEV;
struct uea_softc *sc;
mutex_lock(&uea_mutex);
sc = dev_to_uea(dev);
if (!sc)
goto out;
sc->reset = 1;
ret = count;
out:
mutex_unlock(&uea_mutex);
return ret;
}
static ssize_t read_human_status(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret = -ENODEV;
int modem_state;
struct uea_softc *sc;
mutex_lock(&uea_mutex);
sc = dev_to_uea(dev);
if (!sc)
goto out;
if (UEA_CHIP_VERSION(sc) == EAGLE_IV) {
switch (sc->stats.phy.state) {
case 0x0:
case 0x1:
case 0x3:
case 0x4:
modem_state = 0;
break;
case 0x5:
case 0x6:
case 0x9:
case 0xa:
modem_state = 1;
break;
case 0x7:
modem_state = 2;
break;
case 0x2:
modem_state = 3;
break;
default:
modem_state = 4;
break;
}
} else
modem_state = GET_STATUS(sc->stats.phy.state);
switch (modem_state) {
case 0:
ret = sprintf(buf, "Modem is booting\n");
break;
case 1:
ret = sprintf(buf, "Modem is initializing\n");
break;
case 2:
ret = sprintf(buf, "Modem is operational\n");
break;
case 3:
ret = sprintf(buf, "Modem synchronization failed\n");
break;
default:
ret = sprintf(buf, "Modem state is unknown\n");
break;
}
out:
mutex_unlock(&uea_mutex);
return ret;
}
static ssize_t read_delin(struct device *dev, struct device_attribute *attr,
char *buf)
{
int ret = -ENODEV;
struct uea_softc *sc;
char *delin = "GOOD";
mutex_lock(&uea_mutex);
sc = dev_to_uea(dev);
if (!sc)
goto out;
if (UEA_CHIP_VERSION(sc) == EAGLE_IV) {
if (sc->stats.phy.flags & 0x4000)
delin = "RESET";
else if (sc->stats.phy.flags & 0x0001)
delin = "LOSS";
} else {
if (sc->stats.phy.flags & 0x0C00)
delin = "ERROR";
else if (sc->stats.phy.flags & 0x0030)
delin = "LOSS";
}
ret = sprintf(buf, "%s\n", delin);
out:
mutex_unlock(&uea_mutex);
return ret;
}
static int uea_getesi(struct uea_softc *sc, u_char * esi)
{
unsigned char mac_str[2 * ETH_ALEN + 1];
int i;
if (usb_string
(sc->usb_dev, sc->usb_dev->descriptor.iSerialNumber, mac_str,
sizeof(mac_str)) != 2 * ETH_ALEN)
return 1;
for (i = 0; i < ETH_ALEN; i++)
esi[i] = hex_to_bin(mac_str[2 * i]) * 16 +
hex_to_bin(mac_str[2 * i + 1]);
return 0;
}
static int uea_atm_open(struct usbatm_data *usbatm, struct atm_dev *atm_dev)
{
struct uea_softc *sc = usbatm->driver_data;
return uea_getesi(sc, atm_dev->esi);
}
static int uea_heavy(struct usbatm_data *usbatm, struct usb_interface *intf)
{
struct uea_softc *sc = usbatm->driver_data;
wait_event_interruptible(sc->sync_q, IS_OPERATIONAL(sc));
return 0;
}
static int claim_interface(struct usb_device *usb_dev,
struct usbatm_data *usbatm, int ifnum)
{
int ret;
struct usb_interface *intf = usb_ifnum_to_if(usb_dev, ifnum);
if (!intf) {
uea_err(usb_dev, "interface %d not found\n", ifnum);
return -ENODEV;
}
ret = usb_driver_claim_interface(&uea_driver, intf, usbatm);
if (ret != 0)
uea_err(usb_dev, "can't claim interface %d, error %d\n", ifnum,
ret);
return ret;
}
static int uea_bind(struct usbatm_data *usbatm, struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *usb = interface_to_usbdev(intf);
struct uea_softc *sc;
int ret, ifnum = intf->altsetting->desc.bInterfaceNumber;
unsigned int alt;
uea_enters(usb);
if (ifnum != UEA_INTR_IFACE_NO)
return -ENODEV;
usbatm->flags = (sync_wait[modem_index] ? 0 : UDSL_SKIP_HEAVY_INIT);
ret = claim_interface(usb, usbatm, UEA_US_IFACE_NO);
if (ret < 0)
return ret;
if (UEA_CHIP_VERSION(id) != ADI930) {
ret = claim_interface(usb, usbatm, UEA_DS_IFACE_NO);
if (ret < 0)
return ret;
}
sc = kzalloc(sizeof(struct uea_softc), GFP_KERNEL);
if (!sc) {
uea_err(usb, "uea_init: not enough memory !\n");
return -ENOMEM;
}
sc->usb_dev = usb;
usbatm->driver_data = sc;
sc->usbatm = usbatm;
sc->modem_index = (modem_index < NB_MODEM) ? modem_index++ : 0;
sc->driver_info = id->driver_info;
if (annex[sc->modem_index] == 1)
sc->annex = ANNEXA;
else if (annex[sc->modem_index] == 2)
sc->annex = ANNEXB;
else if (sc->driver_info & AUTO_ANNEX_A)
sc->annex = ANNEXA;
else if (sc->driver_info & AUTO_ANNEX_B)
sc->annex = ANNEXB;
else
sc->annex = (le16_to_cpu
(sc->usb_dev->descriptor.bcdDevice) & 0x80) ? ANNEXB : ANNEXA;
alt = altsetting[sc->modem_index];
if (UEA_CHIP_VERSION(id) != ADI930 && alt > 0) {
if (alt <= 8 &&
usb_set_interface(usb, UEA_DS_IFACE_NO, alt) == 0) {
uea_dbg(usb, "set alternate %u for 2 interface\n", alt);
uea_info(usb, "using iso mode\n");
usbatm->flags |= UDSL_USE_ISOC | UDSL_IGNORE_EILSEQ;
} else {
uea_err(usb, "setting alternate %u failed for "
"2 interface, using bulk mode\n", alt);
}
}
ret = sysfs_create_group(&intf->dev.kobj, &attr_grp);
if (ret < 0)
goto error;
ret = uea_boot(sc);
if (ret < 0)
goto error_rm_grp;
return 0;
error_rm_grp:
sysfs_remove_group(&intf->dev.kobj, &attr_grp);
error:
kfree(sc);
return ret;
}
static void uea_unbind(struct usbatm_data *usbatm, struct usb_interface *intf)
{
struct uea_softc *sc = usbatm->driver_data;
sysfs_remove_group(&intf->dev.kobj, &attr_grp);
uea_stop(sc);
kfree(sc);
}
static int uea_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
struct usb_device *usb = interface_to_usbdev(intf);
int ret;
uea_enters(usb);
uea_info(usb, "ADSL device founded vid (%#X) pid (%#X) Rev (%#X): %s\n",
le16_to_cpu(usb->descriptor.idVendor),
le16_to_cpu(usb->descriptor.idProduct),
le16_to_cpu(usb->descriptor.bcdDevice),
chip_name[UEA_CHIP_VERSION(id)]);
usb_reset_device(usb);
if (UEA_IS_PREFIRM(id))
return uea_load_firmware(usb, UEA_CHIP_VERSION(id));
ret = usbatm_usb_probe(intf, id, &uea_usbatm_driver);
if (ret == 0) {
struct usbatm_data *usbatm = usb_get_intfdata(intf);
struct uea_softc *sc = usbatm->driver_data;
UPDATE_ATM_SIGNAL(ATM_PHY_SIG_LOST);
wake_up_process(sc->kthread);
}
return ret;
}
static void uea_disconnect(struct usb_interface *intf)
{
struct usb_device *usb = interface_to_usbdev(intf);
int ifnum = intf->altsetting->desc.bInterfaceNumber;
uea_enters(usb);
if (usb->config->desc.bNumInterfaces != 1 && ifnum == 0) {
mutex_lock(&uea_mutex);
usbatm_usb_disconnect(intf);
mutex_unlock(&uea_mutex);
uea_info(usb, "ADSL device removed\n");
}
uea_leaves(usb);
}
static int __init uea_init(void)
{
printk(KERN_INFO "[ueagle-atm] driver " EAGLEUSBVERSION " loaded\n");
usb_register(&uea_driver);
return 0;
}
static void __exit uea_exit(void)
{
usb_deregister(&uea_driver);
printk(KERN_INFO "[ueagle-atm] driver unloaded\n");
}
