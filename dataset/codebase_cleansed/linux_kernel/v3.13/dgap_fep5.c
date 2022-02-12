void dgap_do_config_load(uchar __user *uaddr, int len)
{
int orig_len = len;
char *to_addr;
uchar __user *from_addr = uaddr;
char buf[U2BSIZE];
int n;
to_addr = dgap_config_buf = dgap_driver_kzmalloc(len + 1, GFP_ATOMIC);
if (!dgap_config_buf) {
DPR_INIT(("dgap_do_config_load - unable to allocate memory for file\n"));
dgap_driver_state = DRIVER_NEED_CONFIG_LOAD;
return;
}
n = U2BSIZE;
while (len) {
if (n > len)
n = len;
if (copy_from_user((char *) &buf, from_addr, n) == -1 )
return;
memcpy(to_addr, buf, n);
len -= n;
to_addr += n;
from_addr += n;
n = U2BSIZE;
}
dgap_config_buf[orig_len] = '\0';
to_addr = dgap_config_buf;
dgap_parsefile(&to_addr, TRUE);
DPR_INIT(("dgap_config_load() finish\n"));
return;
}
int dgap_after_config_loaded(void)
{
int i = 0;
int rc = 0;
for (i = 0; i < dgap_NumBoards; ++i) {
init_waitqueue_head(&(dgap_Board[i]->kme_wait));
dgap_Board[i]->flipbuf = dgap_driver_kzmalloc(MYFLIPLEN, GFP_ATOMIC);
dgap_Board[i]->flipflagbuf = dgap_driver_kzmalloc(MYFLIPLEN, GFP_ATOMIC);
}
return rc;
}
static int dgap_usertoboard(struct board_t *brd, char *to_addr, char __user *from_addr, int len)
{
char buf[U2BSIZE];
int n = U2BSIZE;
if (!brd || brd->magic != DGAP_BOARD_MAGIC)
return -EFAULT;
while (len) {
if (n > len)
n = len;
if (copy_from_user((char *) &buf, from_addr, n) == -1 ) {
return -EFAULT;
}
memcpy_toio(to_addr, buf, n);
len -= n;
to_addr += n;
from_addr += n;
n = U2BSIZE;
}
return 0;
}
void dgap_do_bios_load(struct board_t *brd, uchar __user *ubios, int len)
{
uchar *addr;
uint offset;
int i;
if (!brd || (brd->magic != DGAP_BOARD_MAGIC) || !brd->re_map_membase)
return;
DPR_INIT(("dgap_do_bios_load() start\n"));
addr = brd->re_map_membase;
for (i = 0; i < 16; i++)
writeb(0, addr + POSTAREA + i);
offset = 0x1000;
if (dgap_usertoboard(brd, addr + offset, ubios, len) == -1 ) {
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
return;
}
writel(0x0bf00401, addr);
writel(0, (addr + 4));
writeb(FEPCLR, brd->re_map_port);
brd->state = WAIT_BIOS_LOAD;
}
static void dgap_do_wait_for_bios(struct board_t *brd)
{
uchar *addr;
u16 word;
if (!brd || (brd->magic != DGAP_BOARD_MAGIC) || !brd->re_map_membase)
return;
addr = brd->re_map_membase;
word = readw(addr + POSTAREA);
if (word == *(u16 *) "GD") {
DPR_INIT(("GOT GD in memory, moving states.\n"));
brd->state = FINISHED_BIOS_LOAD;
return;
}
if (brd->wait_for_bios++ > 5000) {
u16 err1 = readw(addr + SEQUENCE);
u16 err2 = readw(addr + ERROR);
APR(("***WARNING*** %s failed diagnostics. Error #(%x,%x).\n",
brd->name, err1, err2));
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
}
}
void dgap_do_fep_load(struct board_t *brd, uchar __user *ufep, int len)
{
uchar *addr;
uint offset;
if (!brd || (brd->magic != DGAP_BOARD_MAGIC) || !brd->re_map_membase)
return;
addr = brd->re_map_membase;
DPR_INIT(("dgap_do_fep_load() for board %s : start\n", brd->name));
offset = 0x1000;
if (dgap_usertoboard(brd, addr + offset, ufep, len) == -1 ) {
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
return;
}
if ((brd->type == PCX) || (brd->type == PEPC)) {
uchar string[100];
uchar *config, *xconfig;
int i = 0;
xconfig = dgap_create_config_string(brd, string);
config = addr + CONFIG;
for (; i < CONFIGSIZE; i++, config++, xconfig++) {
writeb(*xconfig, config);
if ((*xconfig & 0xff) == 0xff)
break;
}
}
writel(0xbfc01004, (addr + 0xc34));
writel(0x3, (addr + 0xc30));
brd->state = WAIT_FEP_LOAD;
DPR_INIT(("dgap_do_fep_load() for board %s : finish\n", brd->name));
}
static void dgap_do_wait_for_fep(struct board_t *brd)
{
uchar *addr;
u16 word;
if (!brd || (brd->magic != DGAP_BOARD_MAGIC) || !brd->re_map_membase)
return;
addr = brd->re_map_membase;
DPR_INIT(("dgap_do_wait_for_fep() for board %s : start. addr: %p\n", brd->name, addr));
word = readw(addr + FEPSTAT);
if (word == *(u16 *) "OS") {
DPR_INIT(("GOT OS in memory for board %s, moving states.\n", brd->name));
brd->state = FINISHED_FEP_LOAD;
word = readw(addr + FEP5_PLUS);
if (word == *(u16 *) "5A") {
DPR_INIT(("GOT 5A in memory for board %s, board supports extended FEP5 commands.\n", brd->name));
brd->bd_flags |= BD_FEP5PLUS;
}
return;
}
if (brd->wait_for_fep++ > 5000) {
u16 err1 = readw(addr + SEQUENCE);
u16 err2 = readw(addr + ERROR);
APR(("***WARNING*** FEPOS for %s not functioning. Error #(%x,%x).\n",
brd->name, err1, err2));
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
}
DPR_INIT(("dgap_do_wait_for_fep() for board %s : finish\n", brd->name));
}
static void dgap_do_reset_board(struct board_t *brd)
{
uchar check;
u32 check1;
u32 check2;
int i = 0;
if (!brd || (brd->magic != DGAP_BOARD_MAGIC) || !brd->re_map_membase || !brd->re_map_port) {
DPR_INIT(("dgap_do_reset_board() start. bad values. brd: %p mem: %p io: %p\n",
brd, brd ? brd->re_map_membase : 0, brd ? brd->re_map_port : 0));
return;
}
DPR_INIT(("dgap_do_reset_board() start. io: %p\n", brd->re_map_port));
writeb(FEPRST, brd->re_map_port);
for (i = 0; i <= 1000; i++) {
check = readb(brd->re_map_port) & 0xe;
if (check == FEPRST)
break;
udelay(10);
}
if (i > 1000) {
APR(("*** WARNING *** Board not resetting... Failing board.\n"));
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
goto failed;
}
writel(0xa55a3cc3, (brd->re_map_membase + LOWMEM));
writel(0x5aa5c33c, (brd->re_map_membase + HIGHMEM));
check1 = readl(brd->re_map_membase + LOWMEM);
check2 = readl(brd->re_map_membase + HIGHMEM);
if ((check1 != 0xa55a3cc3) || (check2 != 0x5aa5c33c)) {
APR(("*** Warning *** No memory at %p for board.\n", brd->re_map_membase));
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
goto failed;
}
if (brd->state != BOARD_FAILED)
brd->state = FINISHED_RESET;
failed:
DPR_INIT(("dgap_do_reset_board() finish\n"));
}
void dgap_do_conc_load(struct board_t *brd, uchar *uaddr, int len)
{
char *vaddr;
u16 offset = 0;
struct downld_t *to_dp;
if (!brd || (brd->magic != DGAP_BOARD_MAGIC) || !brd->re_map_membase)
return;
vaddr = brd->re_map_membase;
offset = readw((u16 *) (vaddr + DOWNREQ));
to_dp = (struct downld_t *) (vaddr + (int) offset);
memcpy_toio((char *) to_dp, uaddr, sizeof(struct downld_t));
writew(0, vaddr + (DOWNREQ));
brd->conc_dl_status = NO_PENDING_CONCENTRATOR_REQUESTS;
}
static void dgap_get_vpd(struct board_t *brd)
{
u32 magic;
u32 base_offset;
u16 rom_offset;
u16 vpd_offset;
u16 image_length;
u16 i;
uchar byte1;
uchar byte2;
magic = FEP5_ROM_MAGIC;
pci_write_config_dword(brd->pdev, PCI_ROM_ADDRESS, magic);
pci_read_config_dword(brd->pdev, PCI_ROM_ADDRESS, &magic);
if (!magic)
return;
magic = brd->membase | 0x01;
pci_write_config_dword(brd->pdev, PCI_ROM_ADDRESS, magic);
pci_read_config_dword(brd->pdev, PCI_ROM_ADDRESS, &magic);
byte1 = readb(brd->re_map_membase);
byte2 = readb(brd->re_map_membase + 1);
if (byte1 == 0x55 && byte2 == 0xAA) {
base_offset = 0;
while (base_offset <= EXPANSION_ROM_SIZE) {
rom_offset = readw(brd->re_map_membase + base_offset + 0x18);
image_length = readw(brd->re_map_membase + rom_offset + 0x10) * 512;
vpd_offset = readw(brd->re_map_membase + rom_offset + 0x08);
if (vpd_offset)
break;
base_offset += image_length;
byte1 = readb(brd->re_map_membase + base_offset);
byte2 = readb(brd->re_map_membase + base_offset + 1);
if (byte1 != 0x55 || byte2 != 0xAA)
break;
}
if (vpd_offset) {
brd->bd_flags |= BD_HAS_VPD;
for (i = 0; i < VPDSIZE; i++)
brd->vpd[i] = readb(brd->re_map_membase + vpd_offset + i);
}
}
magic = FEP5_ROM_MAGIC;
pci_write_config_dword(brd->pdev, PCI_ROM_ADDRESS, magic);
}
void dgap_poll_tasklet(unsigned long data)
{
struct board_t *bd = (struct board_t *) data;
ulong lock_flags;
ulong lock_flags2;
char *vaddr;
u16 head, tail;
u16 *chk_addr;
u16 check = 0;
if (!bd || (bd->magic != DGAP_BOARD_MAGIC)) {
APR(("dgap_poll_tasklet() - NULL or bad bd.\n"));
return;
}
if (bd->inhibit_poller)
return;
DGAP_LOCK(bd->bd_lock, lock_flags);
vaddr = bd->re_map_membase;
if (bd->state == BOARD_READY) {
struct ev_t *eaddr = NULL;
if (!bd->re_map_membase) {
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return;
}
if (!bd->re_map_port) {
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return;
}
if (!bd->nasync) {
goto out;
}
if ((bd->type == PCX) || (bd->type == PEPC)) {
chk_addr = (u16 *) (vaddr + DOWNREQ);
check = readw(chk_addr);
if (check) {
if (bd->conc_dl_status == NO_PENDING_CONCENTRATOR_REQUESTS)
bd->conc_dl_status = NEED_CONCENTRATOR;
DGAP_LOCK(dgap_dl_lock, lock_flags2);
if (dgap_dl_action != 1) {
dgap_dl_action = 1;
wake_up_interruptible(&dgap_dl_wait);
}
DGAP_UNLOCK(dgap_dl_lock, lock_flags2);
}
}
eaddr = (struct ev_t *) (vaddr + EVBUF);
head = readw(&(eaddr->ev_head));
tail = readw(&(eaddr->ev_tail));
if (head != tail) {
DGAP_UNLOCK(bd->bd_lock, lock_flags);
dgap_event(bd);
DGAP_LOCK(bd->bd_lock, lock_flags);
}
out:
if (bd && bd->intr_running) {
readb(bd->re_map_port + 2);
}
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return;
}
if (bd->state == NEED_RESET) {
dgap_get_vpd(bd);
dgap_do_reset_board(bd);
}
if (bd->state == FINISHED_RESET) {
bd->state = NEED_CONFIG;
}
if (bd->state == NEED_CONFIG) {
bd->bd_config = dgap_find_config(bd->type, bd->pci_bus, bd->pci_slot);
if (bd->type == PAPORT8 && !bd->bd_config) {
bd->bd_config = dgap_find_config(PAPORT4, bd->pci_bus, bd->pci_slot);
}
if (bd->bd_config) {
bd->state = FINISHED_CONFIG;
}
else {
bd->state = CONFIG_NOT_FOUND;
}
}
if (bd->state == FINISHED_CONFIG) {
bd->state = NEED_DEVICE_CREATION;
}
if (bd->state == NEED_DEVICE_CREATION) {
DGAP_LOCK(dgap_dl_lock, lock_flags2);
if (dgap_dl_action != 1) {
dgap_dl_action = 1;
wake_up_interruptible(&dgap_dl_wait);
}
DGAP_UNLOCK(dgap_dl_lock, lock_flags2);
}
if (bd->state == FINISHED_DEVICE_CREATION) {
bd->state = NEED_BIOS_LOAD;
}
if (bd->state == NEED_BIOS_LOAD) {
DGAP_LOCK(dgap_dl_lock, lock_flags2);
if (dgap_dl_action != 1) {
dgap_dl_action = 1;
wake_up_interruptible(&dgap_dl_wait);
}
DGAP_UNLOCK(dgap_dl_lock, lock_flags2);
}
if (bd->state == WAIT_BIOS_LOAD) {
dgap_do_wait_for_bios(bd);
}
if (bd->state == FINISHED_BIOS_LOAD) {
bd->state = NEED_FEP_LOAD;
DGAP_LOCK(dgap_dl_lock, lock_flags2);
if (dgap_dl_action != 1) {
dgap_dl_action = 1;
wake_up_interruptible(&dgap_dl_wait);
}
DGAP_UNLOCK(dgap_dl_lock, lock_flags2);
}
if (bd->state == WAIT_FEP_LOAD) {
dgap_do_wait_for_fep(bd);
}
if (bd->state == FINISHED_FEP_LOAD) {
int rc = dgap_tty_init(bd);
if (rc < 0) {
dgap_tty_uninit(bd);
APR(("Can't init tty devices (%d)\n", rc));
bd->state = BOARD_FAILED;
bd->dpastatus = BD_NOFEP;
}
else {
bd->state = NEED_PROC_CREATION;
DGAP_LOCK(dgap_dl_lock, lock_flags2);
if (dgap_dl_action != 1) {
dgap_dl_action = 1;
wake_up_interruptible(&dgap_dl_wait);
}
DGAP_UNLOCK(dgap_dl_lock, lock_flags2);
}
}
if (bd->state == FINISHED_PROC_CREATION) {
bd->state = BOARD_READY;
bd->dpastatus = BD_RUNNING;
if (bd->intr_used) {
writew(1, (bd->re_map_membase + ENABLE_INTR));
writew(FEPPOLL_MIN, (bd->re_map_membase + FEPPOLL));
bd->intr_running = 1;
}
wake_up_interruptible(&bd->state_wait);
}
DGAP_UNLOCK(bd->bd_lock, lock_flags);
}
void dgap_cmdb(struct channel_t *ch, uchar cmd, uchar byte1, uchar byte2, uint ncmds)
{
char *vaddr = NULL;
struct cm_t *cm_addr = NULL;
uint count;
uint n;
u16 head;
u16 tail;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
if (ch->ch_bd->state == BOARD_FAILED) {
DPR_CORE(("%s:%d board is in failed state.\n", __FILE__, __LINE__));
return;
}
vaddr = ch->ch_bd->re_map_membase;
if (!vaddr)
return;
cm_addr = (struct cm_t *) (vaddr + CMDBUF);
head = readw(&(cm_addr->cm_head));
if (head >= (CMDMAX - CMDSTART) || (head & 03)) {
DPR_CORE(("%s:%d pointers out of range, failing board!\n", __FILE__, __LINE__));
ch->ch_bd->state = BOARD_FAILED;
return;
}
writeb(cmd, (char *) (vaddr + head + CMDSTART + 0));
writeb((uchar) ch->ch_portnum, (char *) (vaddr + head + CMDSTART + 1));
writeb(byte1, (char *) (vaddr + head + CMDSTART + 2));
writeb(byte2, (char *) (vaddr + head + CMDSTART + 3));
head = (head + 4) & (CMDMAX - CMDSTART - 4);
writew(head, &(cm_addr->cm_head));
for (count = dgap_count ;;) {
head = readw(&(cm_addr->cm_head));
tail = readw(&(cm_addr->cm_tail));
n = (head - tail) & (CMDMAX - CMDSTART - 4);
if (n <= ncmds * sizeof(struct cm_t))
break;
if (--count == 0) {
DPR_CORE(("%s:%d failing board.\n",__FILE__, __LINE__));
ch->ch_bd->state = BOARD_FAILED;
return;
}
udelay(10);
}
}
void dgap_cmdw(struct channel_t *ch, uchar cmd, u16 word, uint ncmds)
{
char *vaddr = NULL;
struct cm_t *cm_addr = NULL;
uint count;
uint n;
u16 head;
u16 tail;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
if (ch->ch_bd->state == BOARD_FAILED) {
DPR_CORE(("%s:%d board is failed!\n", __FILE__, __LINE__));
return;
}
vaddr = ch->ch_bd->re_map_membase;
if (!vaddr)
return;
cm_addr = (struct cm_t *) (vaddr + CMDBUF);
head = readw(&(cm_addr->cm_head));
if (head >= (CMDMAX - CMDSTART) || (head & 03)) {
DPR_CORE(("%s:%d Pointers out of range. Failing board.\n",__FILE__, __LINE__));
ch->ch_bd->state = BOARD_FAILED;
return;
}
writeb(cmd, (char *) (vaddr + head + CMDSTART + 0));
writeb((uchar) ch->ch_portnum, (char *) (vaddr + head + CMDSTART + 1));
writew((u16) word, (char *) (vaddr + head + CMDSTART + 2));
head = (head + 4) & (CMDMAX - CMDSTART - 4);
writew(head, &(cm_addr->cm_head));
for (count = dgap_count ;;) {
head = readw(&(cm_addr->cm_head));
tail = readw(&(cm_addr->cm_tail));
n = (head - tail) & (CMDMAX - CMDSTART - 4);
if (n <= ncmds * sizeof(struct cm_t))
break;
if (--count == 0) {
DPR_CORE(("%s:%d Failing board.\n",__FILE__, __LINE__));
ch->ch_bd->state = BOARD_FAILED;
return;
}
udelay(10);
}
}
static void dgap_cmdw_ext(struct channel_t *ch, u16 cmd, u16 word, uint ncmds)
{
char *vaddr = NULL;
struct cm_t *cm_addr = NULL;
uint count;
uint n;
u16 head;
u16 tail;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
if (ch->ch_bd->state == BOARD_FAILED) {
DPR_CORE(("%s:%d board is failed!\n", __FILE__, __LINE__));
return;
}
vaddr = ch->ch_bd->re_map_membase;
if (!vaddr)
return;
cm_addr = (struct cm_t *) (vaddr + CMDBUF);
head = readw(&(cm_addr->cm_head));
if (head >= (CMDMAX - CMDSTART) || (head & 03)) {
DPR_CORE(("%s:%d Pointers out of range. Failing board.\n",__FILE__, __LINE__));
ch->ch_bd->state = BOARD_FAILED;
return;
}
writeb((uchar) 0xff, (char *) (vaddr + head + CMDSTART + 0));
writeb((uchar) ch->ch_portnum, (uchar *) (vaddr + head + CMDSTART + 1));
writew((u16) cmd, (char *) (vaddr + head + CMDSTART + 2));
if (((head + 4) >= ((CMDMAX - CMDSTART)) || (head & 03))) {
writew((u16) word, (char *) (vaddr + CMDSTART));
} else {
writew((u16) word, (char *) (vaddr + head + CMDSTART + 4));
}
head = (head + 8) & (CMDMAX - CMDSTART - 4);
writew(head, &(cm_addr->cm_head));
for (count = dgap_count ;;) {
head = readw(&(cm_addr->cm_head));
tail = readw(&(cm_addr->cm_tail));
n = (head - tail) & (CMDMAX - CMDSTART - 4);
if (n <= ncmds * sizeof(struct cm_t))
break;
if (--count == 0) {
DPR_CORE(("%s:%d Failing board.\n",__FILE__, __LINE__));
ch->ch_bd->state = BOARD_FAILED;
return;
}
udelay(10);
}
}
void dgap_wmove(struct channel_t *ch, char *buf, uint cnt)
{
int n;
char *taddr;
struct bs_t *bs;
u16 head;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bs = ch->ch_bs;
head = readw(&(bs->tx_head));
if ((cnt > ch->ch_tsize) || (unsigned)(head - ch->ch_tstart) >= ch->ch_tsize) {
DPR_CORE(("%s:%d pointer out of range", __FILE__, __LINE__));
return;
}
n = ch->ch_tstart + ch->ch_tsize - head;
if (cnt >= n) {
cnt -= n;
taddr = ch->ch_taddr + head;
memcpy_toio(taddr, buf, n);
head = ch->ch_tstart;
buf += n;
}
taddr = ch->ch_taddr + head;
n = cnt;
memcpy_toio(taddr, buf, n);
head += cnt;
writew(head, &(bs->tx_head));
}
uint dgap_get_custom_baud(struct channel_t *ch)
{
uchar *vaddr;
ulong offset = 0;
uint value = 0;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC) {
return 0;
}
if (!ch->ch_bd || ch->ch_bd->magic != DGAP_BOARD_MAGIC) {
return 0;
}
if (!(ch->ch_bd->bd_flags & BD_FEP5PLUS))
return 0;
vaddr = ch->ch_bd->re_map_membase;
if (!vaddr)
return 0;
offset = ((((*(unsigned short *)(vaddr + ECS_SEG)) << 4) +
(ch->ch_portnum * 0x28) + LINE_SPEED));
value = readw(vaddr + offset);
return value;
}
void dgap_firmware_reset_port(struct channel_t *ch)
{
dgap_cmdb(ch, CHRESET, 0, 0, 0);
ch->ch_fepiflag = 0;
ch->ch_fepcflag = 0;
ch->ch_fepoflag = 0;
ch->ch_fepstartc = 0;
ch->ch_fepstopc = 0;
ch->ch_fepastartc = 0;
ch->ch_fepastopc = 0;
ch->ch_mostat = 0;
ch->ch_hflow = 0;
}
int dgap_param(struct tty_struct *tty)
{
struct ktermios *ts;
struct board_t *bd;
struct channel_t *ch;
struct bs_t *bs;
struct un_t *un;
u16 head;
u16 cflag;
u16 iflag;
uchar mval;
uchar hflow;
if (!tty || tty->magic != TTY_MAGIC)
return -ENXIO;
un = (struct un_t *) tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return -ENXIO;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return -ENXIO;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return -ENXIO;
bs = ch->ch_bs;
if (!bs)
return -ENXIO;
DPR_PARAM(("param start: tdev: %x cflags: %x oflags: %x iflags: %x\n",
ch->ch_tun.un_dev, ch->ch_c_cflag, ch->ch_c_oflag, ch->ch_c_iflag));
ts = &tty->termios;
if ((ch->ch_c_cflag & (CBAUD)) == 0) {
head = readw(&(ch->ch_bs->rx_head));
writew(head, &(ch->ch_bs->rx_tail));
head = readw(&(ch->ch_bs->tx_head));
writew(head, &(ch->ch_bs->tx_tail));
ch->ch_flags |= (CH_BAUD0);
ch->ch_mval &= ~(D_RTS(ch)|D_DTR(ch));
mval = D_DTR(ch) | D_RTS(ch);
ch->ch_baud_info = 0;
} else if (ch->ch_custom_speed && (bd->bd_flags & BD_FEP5PLUS)) {
DPR_PARAM(("param: Want %d speed\n", ch->ch_custom_speed));
dgap_cmdw_ext(ch, 0xff01, ch->ch_custom_speed, 0);
ch->ch_baud_info = ch->ch_custom_speed = dgap_get_custom_baud(ch);
DPR_PARAM(("param: Got %d speed\n", ch->ch_custom_speed));
if (ch->ch_flags & CH_BAUD0) {
ch->ch_flags &= ~(CH_BAUD0);
ch->ch_mval |= (D_RTS(ch)|D_DTR(ch));
}
mval = D_DTR(ch) | D_RTS(ch);
} else {
int iindex = 0;
int jindex = 0;
int baud = 0;
ulong bauds[4][16] = {
{
0, 50, 75, 110,
134, 150, 200, 300,
600, 1200, 1800, 2400,
4800, 9600, 19200, 38400 },
{
0, 57600, 115200, 230400,
460800, 150, 200, 921600,
600, 1200, 1800, 2400,
4800, 9600, 19200, 38400 },
{
0, 57600, 76800, 115200,
14400, 57600, 230400, 76800,
115200, 230400, 28800, 460800,
921600, 9600, 19200, 38400 },
{
0, 57600, 115200, 230400,
460800, 150, 200, 921600,
600, 1200, 1800, 2400,
4800, 9600, 19200, 38400 }
};
if (!(ch->ch_tun.un_flags & UN_ISOPEN) && (un->un_type == DGAP_PRINT))
baud = C_BAUD(ch->ch_pun.un_tty) & 0xff;
else
baud = C_BAUD(ch->ch_tun.un_tty) & 0xff;
if (ch->ch_c_cflag & CBAUDEX)
iindex = 1;
if (ch->ch_digi.digi_flags & DIGI_FAST)
iindex += 2;
jindex = baud;
if ((iindex >= 0) && (iindex < 4) && (jindex >= 0) && (jindex < 16)) {
baud = bauds[iindex][jindex];
} else {
DPR_IOCTL(("baud indices were out of range (%d)(%d)",
iindex, jindex));
baud = 0;
}
if (baud == 0)
baud = 9600;
ch->ch_baud_info = baud;
cflag = ch->ch_c_cflag & ((CBAUD ^ CBAUDEX) | PARODD | PARENB | CSTOPB | CSIZE);
if ((ch->ch_digi.digi_flags & DIGI_FAST) || (ch->ch_c_cflag & CBAUDEX))
cflag |= HUPCL;
if ((ch->ch_c_cflag & CBAUDEX) && !(ch->ch_digi.digi_flags & DIGI_FAST)) {
tcflag_t tcflag = (ch->ch_c_cflag & CBAUD) | CBAUDEX;
int baudpart = 0;
switch (tcflag) {
case B57600 :
baudpart = 1;
break;
#ifdef B76800
case B76800 :
baudpart = 2;
break;
#endif
case B115200 :
baudpart = 3;
break;
case B230400 :
baudpart = 9;
break;
case B460800 :
baudpart = 11;
break;
#ifdef B921600
case B921600 :
baudpart = 12;
break;
#endif
default:
baudpart = 0;
}
if (baudpart)
cflag = (cflag & ~(CBAUD | CBAUDEX)) | baudpart;
}
cflag &= 0xffff;
if (cflag != ch->ch_fepcflag) {
ch->ch_fepcflag = (u16) (cflag & 0xffff);
dgap_cmdw(ch, SCFLAG, (u16) cflag, 0);
}
if (ch->ch_flags & CH_BAUD0) {
ch->ch_flags &= ~(CH_BAUD0);
ch->ch_mval |= (D_RTS(ch)|D_DTR(ch));
}
mval = D_DTR(ch) | D_RTS(ch);
}
iflag = ch->ch_c_iflag & (IGNBRK | BRKINT | IGNPAR | PARMRK | INPCK | ISTRIP | IXON | IXANY | IXOFF);
if ((ch->ch_startc == _POSIX_VDISABLE) || (ch->ch_stopc == _POSIX_VDISABLE)) {
iflag &= ~(IXON | IXOFF);
ch->ch_c_iflag &= ~(IXON | IXOFF);
}
if (bd->device == PCI_DEVICE_XR_IBM_DID) {
if (ch->ch_digi.digi_flags & DIGI_422)
dgap_cmdb(ch, SCOMMODE, MODE_422, 0, 0);
else
dgap_cmdb(ch, SCOMMODE, MODE_232, 0, 0);
}
if (ch->ch_digi.digi_flags & DIGI_ALTPIN)
iflag |= IALTPIN ;
if (iflag != ch->ch_fepiflag) {
ch->ch_fepiflag = iflag;
dgap_cmdw(ch, SIFLAG, (u16) ch->ch_fepiflag, 0);
}
hflow = 0;
if (ch->ch_c_cflag & CRTSCTS) {
hflow |= (D_RTS(ch) | D_CTS(ch));
}
if (ch->ch_digi.digi_flags & RTSPACE)
hflow |= D_RTS(ch);
if (ch->ch_digi.digi_flags & DTRPACE)
hflow |= D_DTR(ch);
if (ch->ch_digi.digi_flags & CTSPACE)
hflow |= D_CTS(ch);
if (ch->ch_digi.digi_flags & DSRPACE)
hflow |= D_DSR(ch);
if (ch->ch_digi.digi_flags & DCDPACE)
hflow |= D_CD(ch);
if (hflow != ch->ch_hflow) {
ch->ch_hflow = hflow;
dgap_cmdb(ch, SHFLOW, (uchar) hflow, 0xff, 0);
}
if (bd->bd_flags & BD_FEP5PLUS) {
u16 hflow2 = 0;
if (ch->ch_digi.digi_flags & DIGI_RTS_TOGGLE) {
hflow2 |= (D_RTS(ch));
}
if (ch->ch_digi.digi_flags & DIGI_DTR_TOGGLE) {
hflow2 |= (D_DTR(ch));
}
dgap_cmdw_ext(ch, 0xff03, hflow2, 0);
}
mval ^= ch->ch_mforce & (mval ^ ch->ch_mval);
DPR_PARAM(("dgap_param: mval: %x ch_mforce: %x ch_mval: %x ch_mostat: %x\n",
mval, ch->ch_mforce, ch->ch_mval, ch->ch_mostat));
if (ch->ch_mostat ^ mval) {
ch->ch_mostat = mval;
DPR_PARAM(("dgap_param: Sending SMODEM mval: %x\n", mval));
dgap_cmdb(ch, SMODEM, (uchar) mval, D_RTS(ch)|D_DTR(ch), 0);
}
ch->ch_mistat = readb(&(bs->m_stat));
dgap_carrier(ch);
if (ch->ch_startc != ch->ch_fepstartc || ch->ch_stopc != ch->ch_fepstopc) {
ch->ch_fepstartc = ch->ch_startc;
ch->ch_fepstopc = ch->ch_stopc;
dgap_cmdb(ch, SFLOWC, ch->ch_fepstartc, ch->ch_fepstopc, 0);
}
if (ch->ch_astartc != ch->ch_fepastartc || ch->ch_astopc != ch->ch_fepastopc) {
ch->ch_fepastartc = ch->ch_astartc;
ch->ch_fepastopc = ch->ch_astopc;
dgap_cmdb(ch, SAFLOWC, ch->ch_fepastartc, ch->ch_fepastopc, 0);
}
DPR_PARAM(("param finish\n"));
return 0;
}
void dgap_parity_scan(struct channel_t *ch, unsigned char *cbuf, unsigned char *fbuf, int *len)
{
int l = *len;
int count = 0;
unsigned char *in, *cout, *fout;
unsigned char c;
in = cbuf;
cout = cbuf;
fout = fbuf;
DPR_PSCAN(("dgap_parity_scan start\n"));
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
while (l--) {
c = *in++;
switch (ch->pscan_state) {
default:
ch->pscan_state = 0;
case 0:
if (c == (unsigned char) '\377') {
ch->pscan_state = 1;
} else {
*cout++ = c;
*fout++ = TTY_NORMAL;
count += 1;
}
break;
case 1:
if (c == (unsigned char) '\377') {
*cout++ = c;
*fout++ = TTY_NORMAL;
count += 1;
ch->pscan_state = 0;
} else {
ch->pscan_savechar = c;
ch->pscan_state = 2;
}
break;
case 2:
*cout++ = c;
if (ch->pscan_savechar == 0x0) {
if (c == 0x0) {
DPR_PSCAN(("dgap_parity_scan in 3rd char of ff seq. c: %x setting break.\n", c));
ch->ch_err_break++;
*fout++ = TTY_BREAK;
}
else {
DPR_PSCAN(("dgap_parity_scan in 3rd char of ff seq. c: %x setting parity.\n", c));
ch->ch_err_parity++;
*fout++ = TTY_PARITY;
}
}
else {
DPR_PSCAN(("%s:%d Logic Error.\n", __FILE__, __LINE__));
}
count += 1;
ch->pscan_state = 0;
}
}
*len = count;
DPR_PSCAN(("dgap_parity_scan finish\n"));
}
static int dgap_event(struct board_t *bd)
{
struct channel_t *ch;
ulong lock_flags;
ulong lock_flags2;
struct bs_t *bs;
uchar *event;
uchar *vaddr = NULL;
struct ev_t *eaddr = NULL;
uint head;
uint tail;
int port;
int reason;
int modem;
int b1;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return -ENXIO;
DGAP_LOCK(bd->bd_lock, lock_flags);
vaddr = bd->re_map_membase;
if (!vaddr) {
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return -ENXIO;
}
eaddr = (struct ev_t *) (vaddr + EVBUF);
head = readw(&(eaddr->ev_head));
tail = readw(&(eaddr->ev_tail));
if (head >= EVMAX - EVSTART || tail >= EVMAX - EVSTART ||
(head | tail) & 03) {
DPR_EVENT(("should be calling xxfail %d\n", __LINE__));
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return -ENXIO;
}
while (tail != head) {
event = bd->re_map_membase + tail + EVSTART;
port = event[0];
reason = event[1];
modem = event[2];
b1 = event[3];
DPR_EVENT(("event: jiffies: %ld port: %d reason: %x modem: %x\n",
jiffies, port, reason, modem));
if ( port >= bd->nasync) {
goto next;
}
if (!(reason & (IFMODEM | IFBREAK | IFTLW | IFTEM | IFDATA))) {
goto next;
}
ch = bd->channels[port];
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC) {
goto next;
}
DGAP_LOCK(ch->ch_lock, lock_flags2);
bs = ch->ch_bs;
if (!bs) {
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
goto next;
}
if (reason & IFDATA) {
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
dgap_input(ch);
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
if (ch->ch_flags & CH_RACTIVE)
ch->ch_flags |= CH_RENABLE;
else
writeb(1, &(bs->idata));
if (ch->ch_flags & CH_RWAIT) {
ch->ch_flags &= ~CH_RWAIT;
wake_up_interruptible(&ch->ch_tun.un_flags_wait);
}
}
if (reason & IFMODEM) {
ch->ch_mistat = modem;
dgap_carrier(ch);
}
if (reason & IFBREAK) {
DPR_EVENT(("got IFBREAK\n"));
if (ch->ch_tun.un_tty) {
ch->ch_err_break++;
tty_buffer_request_room(ch->ch_tun.un_tty->port, 1);
tty_insert_flip_char(ch->ch_tun.un_tty->port, 0, TTY_BREAK);
tty_flip_buffer_push(ch->ch_tun.un_tty->port);
}
}
if (reason & IFTLW) {
DPR_EVENT(("event: got low event\n"));
if (ch->ch_tun.un_flags & UN_LOW) {
ch->ch_tun.un_flags &= ~UN_LOW;
if (ch->ch_tun.un_flags & UN_ISOPEN) {
if ((ch->ch_tun.un_tty->flags &
(1 << TTY_DO_WRITE_WAKEUP)) &&
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,31)
ch->ch_tun.un_tty->ldisc->ops->write_wakeup)
#else
ch->ch_tun.un_tty->ldisc.ops->write_wakeup)
#endif
{
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,31)
(ch->ch_tun.un_tty->ldisc->ops->write_wakeup)(ch->ch_tun.un_tty);
#else
(ch->ch_tun.un_tty->ldisc.ops->write_wakeup)(ch->ch_tun.un_tty);
#endif
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
}
wake_up_interruptible(&ch->ch_tun.un_tty->write_wait);
wake_up_interruptible(&ch->ch_tun.un_flags_wait);
DPR_EVENT(("event: Got low event. jiffies: %lu\n", jiffies));
}
}
if (ch->ch_pun.un_flags & UN_LOW) {
ch->ch_pun.un_flags &= ~UN_LOW;
if (ch->ch_pun.un_flags & UN_ISOPEN) {
if ((ch->ch_pun.un_tty->flags &
(1 << TTY_DO_WRITE_WAKEUP)) &&
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,31)
ch->ch_pun.un_tty->ldisc->ops->write_wakeup)
#else
ch->ch_pun.un_tty->ldisc.ops->write_wakeup)
#endif
{
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,31)
(ch->ch_pun.un_tty->ldisc->ops->write_wakeup)(ch->ch_pun.un_tty);
#else
(ch->ch_pun.un_tty->ldisc.ops->write_wakeup)(ch->ch_pun.un_tty);
#endif
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
}
wake_up_interruptible(&ch->ch_pun.un_tty->write_wait);
wake_up_interruptible(&ch->ch_pun.un_flags_wait);
}
}
if (ch->ch_flags & CH_WLOW) {
ch->ch_flags &= ~CH_WLOW;
wake_up_interruptible(&ch->ch_flags_wait);
}
}
