static int hex(unsigned char ch)
{
if (ch >= 'a' && ch <= 'f')
return ch-'a'+10;
if (ch >= '0' && ch <= '9')
return ch-'0';
if (ch >= 'A' && ch <= 'F')
return ch-'A'+10;
return -1;
}
void gdbstub_printk(const char *fmt, ...)
{
static char buf[1024];
va_list args;
int len;
va_start(args, fmt);
len = vsnprintf(buf, sizeof(buf), fmt, args);
va_end(args);
debug_to_serial(buf, len);
}
static inline char *gdbstub_strcpy(char *dst, const char *src)
{
int loop = 0;
while ((dst[loop] = src[loop]))
loop++;
return dst;
}
static void gdbstub_purge_cache(void)
{
asm volatile(" dcef @(gr0,gr0),#1 \n"
" icei @(gr0,gr0),#1 \n"
" membar \n"
" bar \n"
);
}
static void gdbstub_recv_packet(char *buffer)
{
unsigned char checksum;
unsigned char xmitcsum;
unsigned char ch;
int count, i, ret, error;
for (;;) {
do {
gdbstub_rx_char(&ch, 0);
} while (ch != '$');
checksum = 0;
xmitcsum = -1;
count = 0;
error = 0;
while (count < BUFMAX) {
ret = gdbstub_rx_char(&ch, 0);
if (ret < 0)
error = ret;
if (ch == '#')
break;
checksum += ch;
buffer[count] = ch;
count++;
}
if (error == -EIO) {
gdbstub_proto("### GDB Rx Error - Skipping packet ###\n");
gdbstub_proto("### GDB Tx NAK\n");
gdbstub_tx_char('-');
continue;
}
if (count >= BUFMAX || error)
continue;
buffer[count] = 0;
ret = gdbstub_rx_char(&ch, 0);
if (ret < 0)
error = ret;
xmitcsum = hex(ch) << 4;
ret = gdbstub_rx_char(&ch, 0);
if (ret < 0)
error = ret;
xmitcsum |= hex(ch);
if (error) {
if (error == -EIO)
gdbstub_proto("### GDB Rx Error - Skipping packet\n");
gdbstub_proto("### GDB Tx NAK\n");
gdbstub_tx_char('-');
continue;
}
if (checksum != xmitcsum) {
gdbstub_proto("### GDB Tx NAK\n");
gdbstub_tx_char('-');
continue;
}
gdbstub_proto("### GDB Rx '$%s#%02x' ###\n", buffer, checksum);
gdbstub_proto("### GDB Tx ACK\n");
gdbstub_tx_char('+');
if (buffer[2] == ':') {
gdbstub_tx_char(buffer[0]);
gdbstub_tx_char(buffer[1]);
count = 0;
while (buffer[count]) count++;
for (i=3; i <= count; i++)
buffer[i - 3] = buffer[i];
}
break;
}
}
static int gdbstub_send_packet(char *buffer)
{
unsigned char checksum;
int count;
unsigned char ch;
gdbstub_proto("### GDB Tx '%s' ###\n", buffer);
do {
gdbstub_tx_char('$');
checksum = 0;
count = 0;
while ((ch = buffer[count]) != 0) {
gdbstub_tx_char(ch);
checksum += ch;
count += 1;
}
gdbstub_tx_char('#');
gdbstub_tx_char(hex_asc_hi(checksum));
gdbstub_tx_char(hex_asc_lo(checksum));
} while (gdbstub_rx_char(&ch,0),
#ifdef GDBSTUB_DEBUG_PROTOCOL
ch=='-' && (gdbstub_proto("### GDB Rx NAK\n"),0),
ch!='-' && ch!='+' && (gdbstub_proto("### GDB Rx ??? %02x\n",ch),0),
#endif
ch!='+' && ch!='$');
if (ch=='+') {
gdbstub_proto("### GDB Rx ACK\n");
return 0;
}
gdbstub_proto("### GDB Tx Abandoned\n");
gdbstub_rx_unget = ch;
return 1;
}
static int hexToInt(char **ptr, unsigned long *_value)
{
int count = 0, ch;
*_value = 0;
while (**ptr) {
ch = hex(**ptr);
if (ch < 0)
break;
*_value = (*_value << 4) | ((uint8_t) ch & 0xf);
count++;
(*ptr)++;
}
return count;
}
static inline int gdbstub_addr_probe(const void *vaddr)
{
#ifdef CONFIG_MMU
unsigned long paddr;
asm("lrad %1,%0,#1,#0,#0" : "=r"(paddr) : "r"(vaddr));
if (!(paddr & xAMPRx_V))
return 0;
#endif
return 1;
}
static inline unsigned long gdbstub_virt_to_pte(unsigned long vaddr)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
unsigned long val, dampr5;
pgd = (pgd_t *) __get_DAMLR(3) + pgd_index(vaddr);
pud = pud_offset(pgd, vaddr);
pmd = pmd_offset(pud, vaddr);
if (pmd_bad(*pmd) || !pmd_present(*pmd))
return 0;
dampr5 = __get_DAMPR(5);
val = pmd_val(*pmd);
__set_DAMPR(5, val | xAMPRx_L | xAMPRx_SS_16Kb | xAMPRx_S | xAMPRx_C | xAMPRx_V);
pte = (pte_t *)__get_DAMLR(5) + __pte_index(vaddr);
if (pte_present(*pte))
val = pte_val(*pte);
else
val = 0;
__set_DAMPR(5, dampr5);
return val;
}
static inline int gdbstub_addr_map(const void *vaddr)
{
#ifdef CONFIG_MMU
unsigned long pte;
__saved_dampr = __get_DAMPR(2);
__saved_damlr = __get_DAMLR(2);
#endif
if (gdbstub_addr_probe(vaddr))
return 1;
#ifdef CONFIG_MMU
pte = gdbstub_virt_to_pte((unsigned long) vaddr);
if (pte) {
__set_DAMPR(2, pte);
__set_DAMLR(2, (unsigned long) vaddr & PAGE_MASK);
return 1;
}
#endif
return 0;
}
static inline void gdbstub_addr_unmap(void)
{
#ifdef CONFIG_MMU
__set_DAMPR(2, __saved_dampr);
__set_DAMLR(2, __saved_damlr);
#endif
}
static inline int gdbstub_read_dword(const void *addr, uint32_t *_res)
{
unsigned long brr;
uint32_t res;
if (!gdbstub_addr_map(addr))
return 0;
asm volatile(" movgs gr0,brr \n"
" ld%I2 %M2,%0 \n"
" movsg brr,%1 \n"
: "=r"(res), "=r"(brr)
: "m"(*(uint32_t *) addr));
*_res = res;
gdbstub_addr_unmap();
return likely(!brr);
}
static inline int gdbstub_write_dword(void *addr, uint32_t val)
{
unsigned long brr;
if (!gdbstub_addr_map(addr))
return 0;
asm volatile(" movgs gr0,brr \n"
" st%I2 %1,%M2 \n"
" movsg brr,%0 \n"
: "=r"(brr)
: "r"(val), "m"(*(uint32_t *) addr));
gdbstub_addr_unmap();
return likely(!brr);
}
static inline int gdbstub_read_word(const void *addr, uint16_t *_res)
{
unsigned long brr;
uint16_t res;
if (!gdbstub_addr_map(addr))
return 0;
asm volatile(" movgs gr0,brr \n"
" lduh%I2 %M2,%0 \n"
" movsg brr,%1 \n"
: "=r"(res), "=r"(brr)
: "m"(*(uint16_t *) addr));
*_res = res;
gdbstub_addr_unmap();
return likely(!brr);
}
static inline int gdbstub_write_word(void *addr, uint16_t val)
{
unsigned long brr;
if (!gdbstub_addr_map(addr))
return 0;
asm volatile(" movgs gr0,brr \n"
" sth%I2 %1,%M2 \n"
" movsg brr,%0 \n"
: "=r"(brr)
: "r"(val), "m"(*(uint16_t *) addr));
gdbstub_addr_unmap();
return likely(!brr);
}
static inline int gdbstub_read_byte(const void *addr, uint8_t *_res)
{
unsigned long brr;
uint8_t res;
if (!gdbstub_addr_map(addr))
return 0;
asm volatile(" movgs gr0,brr \n"
" ldub%I2 %M2,%0 \n"
" movsg brr,%1 \n"
: "=r"(res), "=r"(brr)
: "m"(*(uint8_t *) addr));
*_res = res;
gdbstub_addr_unmap();
return likely(!brr);
}
static inline int gdbstub_write_byte(void *addr, uint8_t val)
{
unsigned long brr;
if (!gdbstub_addr_map(addr))
return 0;
asm volatile(" movgs gr0,brr \n"
" stb%I2 %1,%M2 \n"
" movsg brr,%0 \n"
: "=r"(brr)
: "r"(val), "m"(*(uint8_t *) addr));
gdbstub_addr_unmap();
return likely(!brr);
}
static void __gdbstub_console_write(struct console *co, const char *p, unsigned n)
{
char outbuf[26];
int qty;
outbuf[0] = 'O';
while (n > 0) {
qty = 1;
while (n > 0 && qty < 20) {
mem2hex(p, outbuf + qty, 2, 0);
qty += 2;
if (*p == 0x0a) {
outbuf[qty++] = '0';
outbuf[qty++] = 'd';
}
p++;
n--;
}
outbuf[qty] = 0;
gdbstub_send_packet(outbuf);
}
}
static unsigned char *mem2hex(const void *_mem, char *buf, int count, int may_fault)
{
const uint8_t *mem = _mem;
uint8_t ch[4] __attribute__((aligned(4)));
if ((uint32_t)mem&1 && count>=1) {
if (!gdbstub_read_byte(mem,ch))
return NULL;
buf = pack_hex_byte(buf, ch[0]);
mem++;
count--;
}
if ((uint32_t)mem&3 && count>=2) {
if (!gdbstub_read_word(mem,(uint16_t *)ch))
return NULL;
buf = pack_hex_byte(buf, ch[0]);
buf = pack_hex_byte(buf, ch[1]);
mem += 2;
count -= 2;
}
while (count>=4) {
if (!gdbstub_read_dword(mem,(uint32_t *)ch))
return NULL;
buf = pack_hex_byte(buf, ch[0]);
buf = pack_hex_byte(buf, ch[1]);
buf = pack_hex_byte(buf, ch[2]);
buf = pack_hex_byte(buf, ch[3]);
mem += 4;
count -= 4;
}
if (count>=2) {
if (!gdbstub_read_word(mem,(uint16_t *)ch))
return NULL;
buf = pack_hex_byte(buf, ch[0]);
buf = pack_hex_byte(buf, ch[1]);
mem += 2;
count -= 2;
}
if (count>=1) {
if (!gdbstub_read_byte(mem,ch))
return NULL;
buf = pack_hex_byte(buf, ch[0]);
}
*buf = 0;
return buf;
}
static char *hex2mem(const char *buf, void *_mem, int count)
{
uint8_t *mem = _mem;
union {
uint32_t l;
uint16_t w;
uint8_t b[4];
} ch;
if ((u32)mem&1 && count>=1) {
ch.b[0] = hex(*buf++) << 4;
ch.b[0] |= hex(*buf++);
if (!gdbstub_write_byte(mem,ch.b[0]))
return NULL;
mem++;
count--;
}
if ((u32)mem&3 && count>=2) {
ch.b[0] = hex(*buf++) << 4;
ch.b[0] |= hex(*buf++);
ch.b[1] = hex(*buf++) << 4;
ch.b[1] |= hex(*buf++);
if (!gdbstub_write_word(mem,ch.w))
return NULL;
mem += 2;
count -= 2;
}
while (count>=4) {
ch.b[0] = hex(*buf++) << 4;
ch.b[0] |= hex(*buf++);
ch.b[1] = hex(*buf++) << 4;
ch.b[1] |= hex(*buf++);
ch.b[2] = hex(*buf++) << 4;
ch.b[2] |= hex(*buf++);
ch.b[3] = hex(*buf++) << 4;
ch.b[3] |= hex(*buf++);
if (!gdbstub_write_dword(mem,ch.l))
return NULL;
mem += 4;
count -= 4;
}
if (count>=2) {
ch.b[0] = hex(*buf++) << 4;
ch.b[0] |= hex(*buf++);
ch.b[1] = hex(*buf++) << 4;
ch.b[1] |= hex(*buf++);
if (!gdbstub_write_word(mem,ch.w))
return NULL;
mem += 2;
count -= 2;
}
if (count>=1) {
ch.b[0] = hex(*buf++) << 4;
ch.b[0] |= hex(*buf++);
if (!gdbstub_write_byte(mem,ch.b[0]))
return NULL;
}
return (char *) buf;
}
static inline int gdbstub_compute_signal(unsigned long brr)
{
const struct brr_to_sig_map *map;
unsigned long tbr = (brr & BRR_EBTT) >> 12;
for (map = brr_to_sig_map; map->brr_mask; map++)
if (map->brr_mask & brr)
if (!map->tbr_tt || map->tbr_tt == tbr)
break;
return map->signo;
}
static int gdbstub_set_breakpoint(unsigned long type, unsigned long addr, unsigned long len)
{
unsigned long tmp;
int bkpt, loop, xloop;
union {
struct {
unsigned long mask0, mask1;
};
uint8_t bytes[8];
} dbmr;
switch (type) {
case 0:
if (addr & 3 || len > 7*4)
return -EINVAL;
for (bkpt = 255; bkpt >= 0; bkpt--)
if (!gdbstub_bkpts[bkpt].addr)
break;
if (bkpt < 0)
return -ENOSPC;
for (loop = 0; loop < len/4; loop++)
if (!gdbstub_read_dword(&((uint32_t *) addr)[loop],
&gdbstub_bkpts[bkpt].originsns[loop]))
return -EFAULT;
for (loop = 0; loop < len/4; loop++)
if (!gdbstub_write_dword(&((uint32_t *) addr)[loop],
BREAK_INSN)
) {
for (xloop = 0; xloop < loop; xloop++)
gdbstub_write_dword(&((uint32_t *) addr)[xloop],
gdbstub_bkpts[bkpt].originsns[xloop]);
return -EFAULT;
}
gdbstub_bkpts[bkpt].addr = addr;
gdbstub_bkpts[bkpt].len = len;
#if 0
gdbstub_printk("Set BKPT[%02x]: %08lx #%d {%04x, %04x} -> { %04x, %04x }\n",
bkpt,
gdbstub_bkpts[bkpt].addr,
gdbstub_bkpts[bkpt].len,
gdbstub_bkpts[bkpt].originsns[0],
gdbstub_bkpts[bkpt].originsns[1],
((uint32_t *) addr)[0],
((uint32_t *) addr)[1]
);
#endif
return 0;
case 1:
if (addr & 3 || len != 4)
return -EINVAL;
if (!(__debug_regs->dcr & DCR_IBE0)) {
__debug_regs->dcr |= DCR_IBE0;
__debug_regs->ibar[0] = addr;
asm volatile("movgs %0,ibar0" : : "r"(addr));
return 0;
}
if (!(__debug_regs->dcr & DCR_IBE1)) {
__debug_regs->dcr |= DCR_IBE1;
__debug_regs->ibar[1] = addr;
asm volatile("movgs %0,ibar1" : : "r"(addr));
return 0;
}
if (!(__debug_regs->dcr & DCR_IBE2)) {
__debug_regs->dcr |= DCR_IBE2;
__debug_regs->ibar[2] = addr;
asm volatile("movgs %0,ibar2" : : "r"(addr));
return 0;
}
if (!(__debug_regs->dcr & DCR_IBE3)) {
__debug_regs->dcr |= DCR_IBE3;
__debug_regs->ibar[3] = addr;
asm volatile("movgs %0,ibar3" : : "r"(addr));
return 0;
}
return -ENOSPC;
case 2:
case 3:
case 4:
if ((addr & ~7) != ((addr + len - 1) & ~7))
return -EINVAL;
tmp = addr & 7;
memset(dbmr.bytes, 0xff, sizeof(dbmr.bytes));
for (loop = 0; loop < len; loop++)
dbmr.bytes[tmp + loop] = 0;
addr &= ~7;
if (!(__debug_regs->dcr & (DCR_DRBE0|DCR_DWBE0))) {
tmp = type==2 ? DCR_DWBE0 : type==3 ? DCR_DRBE0 : DCR_DRBE0|DCR_DWBE0;
__debug_regs->dcr |= tmp;
__debug_regs->dbar[0] = addr;
__debug_regs->dbmr[0][0] = dbmr.mask0;
__debug_regs->dbmr[0][1] = dbmr.mask1;
__debug_regs->dbdr[0][0] = 0;
__debug_regs->dbdr[0][1] = 0;
asm volatile(" movgs %0,dbar0 \n"
" movgs %1,dbmr00 \n"
" movgs %2,dbmr01 \n"
" movgs gr0,dbdr00 \n"
" movgs gr0,dbdr01 \n"
: : "r"(addr), "r"(dbmr.mask0), "r"(dbmr.mask1));
return 0;
}
if (!(__debug_regs->dcr & (DCR_DRBE1|DCR_DWBE1))) {
tmp = type==2 ? DCR_DWBE1 : type==3 ? DCR_DRBE1 : DCR_DRBE1|DCR_DWBE1;
__debug_regs->dcr |= tmp;
__debug_regs->dbar[1] = addr;
__debug_regs->dbmr[1][0] = dbmr.mask0;
__debug_regs->dbmr[1][1] = dbmr.mask1;
__debug_regs->dbdr[1][0] = 0;
__debug_regs->dbdr[1][1] = 0;
asm volatile(" movgs %0,dbar1 \n"
" movgs %1,dbmr10 \n"
" movgs %2,dbmr11 \n"
" movgs gr0,dbdr10 \n"
" movgs gr0,dbdr11 \n"
: : "r"(addr), "r"(dbmr.mask0), "r"(dbmr.mask1));
return 0;
}
return -ENOSPC;
default:
return -EINVAL;
}
}
int gdbstub_clear_breakpoint(unsigned long type, unsigned long addr, unsigned long len)
{
unsigned long tmp;
int bkpt, loop;
union {
struct {
unsigned long mask0, mask1;
};
uint8_t bytes[8];
} dbmr;
switch (type) {
case 0:
for (bkpt = 255; bkpt >= 0; bkpt--)
if (gdbstub_bkpts[bkpt].addr == addr && gdbstub_bkpts[bkpt].len == len)
break;
if (bkpt < 0)
return -ENOENT;
gdbstub_bkpts[bkpt].addr = 0;
for (loop = 0; loop < len/4; loop++)
if (!gdbstub_write_dword(&((uint32_t *) addr)[loop],
gdbstub_bkpts[bkpt].originsns[loop]))
return -EFAULT;
return 0;
case 1:
if (addr & 3 || len != 4)
return -EINVAL;
#define __get_ibar(X) ({ unsigned long x; asm volatile("movsg ibar"#X",%0" : "=r"(x)); x; })
if (__debug_regs->dcr & DCR_IBE0 && __get_ibar(0) == addr) {
__debug_regs->dcr &= ~DCR_IBE0;
__debug_regs->ibar[0] = 0;
asm volatile("movgs gr0,ibar0");
return 0;
}
if (__debug_regs->dcr & DCR_IBE1 && __get_ibar(1) == addr) {
__debug_regs->dcr &= ~DCR_IBE1;
__debug_regs->ibar[1] = 0;
asm volatile("movgs gr0,ibar1");
return 0;
}
if (__debug_regs->dcr & DCR_IBE2 && __get_ibar(2) == addr) {
__debug_regs->dcr &= ~DCR_IBE2;
__debug_regs->ibar[2] = 0;
asm volatile("movgs gr0,ibar2");
return 0;
}
if (__debug_regs->dcr & DCR_IBE3 && __get_ibar(3) == addr) {
__debug_regs->dcr &= ~DCR_IBE3;
__debug_regs->ibar[3] = 0;
asm volatile("movgs gr0,ibar3");
return 0;
}
return -EINVAL;
case 2:
case 3:
case 4:
if ((addr & ~7) != ((addr + len - 1) & ~7))
return -EINVAL;
tmp = addr & 7;
memset(dbmr.bytes, 0xff, sizeof(dbmr.bytes));
for (loop = 0; loop < len; loop++)
dbmr.bytes[tmp + loop] = 0;
addr &= ~7;
#define __get_dbar(X) ({ unsigned long x; asm volatile("movsg dbar"#X",%0" : "=r"(x)); x; })
#define __get_dbmr0(X) ({ unsigned long x; asm volatile("movsg dbmr"#X"0,%0" : "=r"(x)); x; })
#define __get_dbmr1(X) ({ unsigned long x; asm volatile("movsg dbmr"#X"1,%0" : "=r"(x)); x; })
tmp = type==2 ? DCR_DWBE0 : type==3 ? DCR_DRBE0 : DCR_DRBE0|DCR_DWBE0;
if ((__debug_regs->dcr & (DCR_DRBE0|DCR_DWBE0)) != tmp ||
__get_dbar(0) != addr ||
__get_dbmr0(0) != dbmr.mask0 ||
__get_dbmr1(0) != dbmr.mask1)
goto skip_dbar0;
__debug_regs->dcr &= ~(DCR_DRBE0|DCR_DWBE0);
__debug_regs->dbar[0] = 0;
__debug_regs->dbmr[0][0] = 0;
__debug_regs->dbmr[0][1] = 0;
__debug_regs->dbdr[0][0] = 0;
__debug_regs->dbdr[0][1] = 0;
asm volatile(" movgs gr0,dbar0 \n"
" movgs gr0,dbmr00 \n"
" movgs gr0,dbmr01 \n"
" movgs gr0,dbdr00 \n"
" movgs gr0,dbdr01 \n");
return 0;
skip_dbar0:
tmp = type==2 ? DCR_DWBE1 : type==3 ? DCR_DRBE1 : DCR_DRBE1|DCR_DWBE1;
if ((__debug_regs->dcr & (DCR_DRBE1|DCR_DWBE1)) != tmp ||
__get_dbar(1) != addr ||
__get_dbmr0(1) != dbmr.mask0 ||
__get_dbmr1(1) != dbmr.mask1)
goto skip_dbar1;
__debug_regs->dcr &= ~(DCR_DRBE1|DCR_DWBE1);
__debug_regs->dbar[1] = 0;
__debug_regs->dbmr[1][0] = 0;
__debug_regs->dbmr[1][1] = 0;
__debug_regs->dbdr[1][0] = 0;
__debug_regs->dbdr[1][1] = 0;
asm volatile(" movgs gr0,dbar1 \n"
" movgs gr0,dbmr10 \n"
" movgs gr0,dbmr11 \n"
" movgs gr0,dbdr10 \n"
" movgs gr0,dbdr11 \n");
return 0;
skip_dbar1:
return -ENOSPC;
default:
return -EINVAL;
}
}
static void gdbstub_check_breakpoint(void)
{
unsigned long addr = __debug_frame->pc - 4;
int bkpt;
for (bkpt = 255; bkpt >= 0; bkpt--)
if (gdbstub_bkpts[bkpt].addr == addr)
break;
if (bkpt >= 0)
__debug_frame->pc = addr;
}
static void __maybe_unused gdbstub_show_regs(void)
{
unsigned long *reg;
int loop;
gdbstub_printk("\n");
gdbstub_printk("Frame: @%p [%s]\n",
__debug_frame,
__debug_frame->psr & PSR_S ? "kernel" : "user");
reg = (unsigned long *) __debug_frame;
for (loop = 0; loop < NR_PT_REGS; loop++) {
printk("%s %08lx", regnames[loop + 0], reg[loop + 0]);
if (loop == NR_PT_REGS - 1 || loop % 5 == 4)
printk("\n");
else
printk(" | ");
}
gdbstub_printk("Process %s (pid: %d)\n", current->comm, current->pid);
}
static void __maybe_unused gdbstub_dump_debugregs(void)
{
gdbstub_printk("DCR %08lx ", __debug_status.dcr);
gdbstub_printk("BRR %08lx\n", __debug_status.brr);
gdbstub_printk("IBAR0 %08lx ", __get_ibar(0));
gdbstub_printk("IBAR1 %08lx ", __get_ibar(1));
gdbstub_printk("IBAR2 %08lx ", __get_ibar(2));
gdbstub_printk("IBAR3 %08lx\n", __get_ibar(3));
gdbstub_printk("DBAR0 %08lx ", __get_dbar(0));
gdbstub_printk("DBMR00 %08lx ", __get_dbmr0(0));
gdbstub_printk("DBMR01 %08lx\n", __get_dbmr1(0));
gdbstub_printk("DBAR1 %08lx ", __get_dbar(1));
gdbstub_printk("DBMR10 %08lx ", __get_dbmr0(1));
gdbstub_printk("DBMR11 %08lx\n", __get_dbmr1(1));
gdbstub_printk("\n");
}
void gdbstub_get_mmu_state(void)
{
asm volatile("movsg hsr0,%0" : "=r"(__debug_mmu.regs.hsr0));
asm volatile("movsg pcsr,%0" : "=r"(__debug_mmu.regs.pcsr));
asm volatile("movsg esr0,%0" : "=r"(__debug_mmu.regs.esr0));
asm volatile("movsg ear0,%0" : "=r"(__debug_mmu.regs.ear0));
asm volatile("movsg epcr0,%0" : "=r"(__debug_mmu.regs.epcr0));
__debug_mmu.iamr[0].L = __get_IAMLR(0);
__debug_mmu.iamr[0].P = __get_IAMPR(0);
__debug_mmu.iamr[1].L = __get_IAMLR(1);
__debug_mmu.iamr[1].P = __get_IAMPR(1);
__debug_mmu.iamr[2].L = __get_IAMLR(2);
__debug_mmu.iamr[2].P = __get_IAMPR(2);
__debug_mmu.iamr[3].L = __get_IAMLR(3);
__debug_mmu.iamr[3].P = __get_IAMPR(3);
__debug_mmu.iamr[4].L = __get_IAMLR(4);
__debug_mmu.iamr[4].P = __get_IAMPR(4);
__debug_mmu.iamr[5].L = __get_IAMLR(5);
__debug_mmu.iamr[5].P = __get_IAMPR(5);
__debug_mmu.iamr[6].L = __get_IAMLR(6);
__debug_mmu.iamr[6].P = __get_IAMPR(6);
__debug_mmu.iamr[7].L = __get_IAMLR(7);
__debug_mmu.iamr[7].P = __get_IAMPR(7);
__debug_mmu.iamr[8].L = __get_IAMLR(8);
__debug_mmu.iamr[8].P = __get_IAMPR(8);
__debug_mmu.iamr[9].L = __get_IAMLR(9);
__debug_mmu.iamr[9].P = __get_IAMPR(9);
__debug_mmu.iamr[10].L = __get_IAMLR(10);
__debug_mmu.iamr[10].P = __get_IAMPR(10);
__debug_mmu.iamr[11].L = __get_IAMLR(11);
__debug_mmu.iamr[11].P = __get_IAMPR(11);
__debug_mmu.iamr[12].L = __get_IAMLR(12);
__debug_mmu.iamr[12].P = __get_IAMPR(12);
__debug_mmu.iamr[13].L = __get_IAMLR(13);
__debug_mmu.iamr[13].P = __get_IAMPR(13);
__debug_mmu.iamr[14].L = __get_IAMLR(14);
__debug_mmu.iamr[14].P = __get_IAMPR(14);
__debug_mmu.iamr[15].L = __get_IAMLR(15);
__debug_mmu.iamr[15].P = __get_IAMPR(15);
__debug_mmu.damr[0].L = __get_DAMLR(0);
__debug_mmu.damr[0].P = __get_DAMPR(0);
__debug_mmu.damr[1].L = __get_DAMLR(1);
__debug_mmu.damr[1].P = __get_DAMPR(1);
__debug_mmu.damr[2].L = __get_DAMLR(2);
__debug_mmu.damr[2].P = __get_DAMPR(2);
__debug_mmu.damr[3].L = __get_DAMLR(3);
__debug_mmu.damr[3].P = __get_DAMPR(3);
__debug_mmu.damr[4].L = __get_DAMLR(4);
__debug_mmu.damr[4].P = __get_DAMPR(4);
__debug_mmu.damr[5].L = __get_DAMLR(5);
__debug_mmu.damr[5].P = __get_DAMPR(5);
__debug_mmu.damr[6].L = __get_DAMLR(6);
__debug_mmu.damr[6].P = __get_DAMPR(6);
__debug_mmu.damr[7].L = __get_DAMLR(7);
__debug_mmu.damr[7].P = __get_DAMPR(7);
__debug_mmu.damr[8].L = __get_DAMLR(8);
__debug_mmu.damr[8].P = __get_DAMPR(8);
__debug_mmu.damr[9].L = __get_DAMLR(9);
__debug_mmu.damr[9].P = __get_DAMPR(9);
__debug_mmu.damr[10].L = __get_DAMLR(10);
__debug_mmu.damr[10].P = __get_DAMPR(10);
__debug_mmu.damr[11].L = __get_DAMLR(11);
__debug_mmu.damr[11].P = __get_DAMPR(11);
__debug_mmu.damr[12].L = __get_DAMLR(12);
__debug_mmu.damr[12].P = __get_DAMPR(12);
__debug_mmu.damr[13].L = __get_DAMLR(13);
__debug_mmu.damr[13].P = __get_DAMPR(13);
__debug_mmu.damr[14].L = __get_DAMLR(14);
__debug_mmu.damr[14].P = __get_DAMPR(14);
__debug_mmu.damr[15].L = __get_DAMLR(15);
__debug_mmu.damr[15].P = __get_DAMPR(15);
#ifdef CONFIG_MMU
do {
struct __debug_amr *p;
int loop;
asm volatile("movsg tplr,%0" : "=r"(__debug_mmu.regs.tplr));
asm volatile("movsg tppr,%0" : "=r"(__debug_mmu.regs.tppr));
asm volatile("movsg tpxr,%0" : "=r"(__debug_mmu.regs.tpxr));
asm volatile("movsg cxnr,%0" : "=r"(__debug_mmu.regs.cxnr));
p = __debug_mmu.tlb;
asm volatile("movgs %0,tpxr" :: "r"(0 << TPXR_WAY_SHIFT));
for (loop = 0; loop < 64; loop++) {
asm volatile("tlbpr %0,gr0,#1,#0" :: "r"(loop << PAGE_SHIFT));
asm volatile("movsg tplr,%0" : "=r"(p->L));
asm volatile("movsg tppr,%0" : "=r"(p->P));
p++;
}
asm volatile("movgs %0,tpxr" :: "r"(1 << TPXR_WAY_SHIFT));
for (loop = 0; loop < 64; loop++) {
asm volatile("tlbpr %0,gr0,#1,#0" :: "r"(loop << PAGE_SHIFT));
asm volatile("movsg tplr,%0" : "=r"(p->L));
asm volatile("movsg tppr,%0" : "=r"(p->P));
p++;
}
asm volatile("movgs %0,tplr" :: "r"(__debug_mmu.regs.tplr));
asm volatile("movgs %0,tppr" :: "r"(__debug_mmu.regs.tppr));
asm volatile("movgs %0,tpxr" :: "r"(__debug_mmu.regs.tpxr));
} while(0);
#endif
}
static void gdbstub_handle_query(void)
{
if (strcmp(input_buffer, "qAttached") == 0) {
sprintf(output_buffer, "1");
return;
}
if (strcmp(input_buffer, "qC") == 0) {
sprintf(output_buffer, "QC 0");
return;
}
if (strcmp(input_buffer, "qOffsets") == 0) {
sprintf(output_buffer, "Text=0;Data=0;Bss=0");
return;
}
if (strcmp(input_buffer, "qSymbol::") == 0) {
sprintf(output_buffer, "OK");
return;
}
if (strcmp(input_buffer, "qSupported") == 0) {
sprintf(output_buffer, "PacketSize=%u;ReverseContinue-;ReverseStep-",
sizeof(input_buffer));
return;
}
gdbstub_strcpy(output_buffer,"E01");
}
void gdbstub(int sigval)
{
unsigned long addr, length, loop, dbar, temp, temp2, temp3;
uint32_t zero;
char *ptr;
int flush_cache = 0;
LEDS(0x5000);
if (sigval < 0) {
#ifndef CONFIG_GDBSTUB_IMMEDIATE
return;
#else
sigval = SIGINT;
#endif
}
save_user_regs(&__debug_frame0->uc);
#if 0
gdbstub_printk("--> gdbstub() %08x %p %08x %08x\n",
__debug_frame->pc,
__debug_frame,
__debug_regs->brr,
__debug_regs->bpsr);
#endif
LEDS(0x5001);
temp = (unsigned long) __entry_kerneltrap_table;
temp2 = (unsigned long) __entry_usertrap_table;
temp3 = __debug_frame->pc & ~15;
if (temp3 == temp + TBR_TT_INTERRUPT_15 ||
temp3 == temp2 + TBR_TT_INTERRUPT_15
) {
asm volatile("movsg pcsr,%0" : "=r"(__debug_frame->pc));
__debug_frame->psr |= PSR_ET;
__debug_frame->psr &= ~PSR_S;
if (__debug_frame->psr & PSR_PS)
__debug_frame->psr |= PSR_S;
__debug_status.brr = (__debug_frame->tbr & TBR_TT) << 12;
__debug_status.brr |= BRR_EB;
sigval = SIGINT;
}
if (temp3 == temp + TBR_TT_DECREMENT_TIMER ||
temp3 == temp2 + TBR_TT_DECREMENT_TIMER
) {
asm volatile("movgs %0,timerd" :: "r"(10000000));
asm volatile("movsg pcsr,%0" : "=r"(__debug_frame->pc));
__debug_frame->psr |= PSR_ET;
__debug_frame->psr &= ~PSR_S;
if (__debug_frame->psr & PSR_PS)
__debug_frame->psr |= PSR_S;
__debug_status.brr = (__debug_frame->tbr & TBR_TT) << 12;
__debug_status.brr |= BRR_EB;
sigval = SIGXCPU;
}
LEDS(0x5002);
if (__debug_status.brr & BRR_SB)
gdbstub_check_breakpoint();
LEDS(0x5003);
if (__debug_frame->pc == (unsigned long) gdbstub_console_write + 4) {
__gdbstub_console_write((struct console *) __debug_frame->gr8,
(const char *) __debug_frame->gr9,
(unsigned) __debug_frame->gr10);
goto done;
}
if (gdbstub_rx_unget) {
sigval = SIGINT;
goto packet_waiting;
}
if (!sigval)
sigval = gdbstub_compute_signal(__debug_status.brr);
LEDS(0x5004);
if (sigval != SIGINT && sigval != SIGTRAP && sigval != SIGILL) {
static const char title[] = "Break ";
static const char crlf[] = "\r\n";
unsigned long brr = __debug_status.brr;
char hx;
ptr = output_buffer;
*ptr++ = 'O';
ptr = mem2hex(title, ptr, sizeof(title) - 1,0);
hx = hex_asc_hi(brr >> 24);
ptr = pack_hex_byte(ptr, hx);
hx = hex_asc_lo(brr >> 24);
ptr = pack_hex_byte(ptr, hx);
hx = hex_asc_hi(brr >> 16);
ptr = pack_hex_byte(ptr, hx);
hx = hex_asc_lo(brr >> 16);
ptr = pack_hex_byte(ptr, hx);
hx = hex_asc_hi(brr >> 8);
ptr = pack_hex_byte(ptr, hx);
hx = hex_asc_lo(brr >> 8);
ptr = pack_hex_byte(ptr, hx);
hx = hex_asc_hi(brr);
ptr = pack_hex_byte(ptr, hx);
hx = hex_asc_lo(brr);
ptr = pack_hex_byte(ptr, hx);
ptr = mem2hex(crlf, ptr, sizeof(crlf) - 1, 0);
*ptr = 0;
gdbstub_send_packet(output_buffer);
}
LEDS(0x5005);
ptr = output_buffer;
*ptr++ = 'T';
ptr = pack_hex_byte(ptr, sigval);
ptr = pack_hex_byte(ptr, GDB_REG_PC);
*ptr++ = ':';
ptr = mem2hex(&__debug_frame->pc, ptr, 4, 0);
*ptr++ = ';';
ptr = pack_hex_byte(ptr, GDB_REG_FP);
*ptr++ = ':';
ptr = mem2hex(&__debug_frame->fp, ptr, 4, 0);
*ptr++ = ';';
ptr = pack_hex_byte(ptr, GDB_REG_SP);
*ptr++ = ':';
ptr = mem2hex(&__debug_frame->sp, ptr, 4, 0);
*ptr++ = ';';
*ptr++ = 0;
gdbstub_send_packet(output_buffer);
LEDS(0x5006);
packet_waiting:
gdbstub_get_mmu_state();
while (1) {
output_buffer[0] = 0;
LEDS(0x5007);
gdbstub_recv_packet(input_buffer);
LEDS(0x5600 | input_buffer[0]);
switch (input_buffer[0]) {
case '?':
output_buffer[0] = 'S';
output_buffer[1] = hex_asc_hi(sigval);
output_buffer[2] = hex_asc_lo(sigval);
output_buffer[3] = 0;
break;
case 'd':
break;
case 'g':
zero = 0;
ptr = output_buffer;
ptr = mem2hex(&zero, ptr, 4, 0);
for (loop = 1; loop <= 27; loop++)
ptr = mem2hex(&__debug_user_context->i.gr[loop], ptr, 4, 0);
temp = (unsigned long) __frame;
ptr = mem2hex(&temp, ptr, 4, 0);
ptr = mem2hex(&__debug_user_context->i.gr[29], ptr, 4, 0);
ptr = mem2hex(&__debug_user_context->i.gr[30], ptr, 4, 0);
#ifdef CONFIG_MMU
ptr = mem2hex(&__debug_user_context->i.gr[31], ptr, 4, 0);
#else
temp = (unsigned long) __debug_frame;
ptr = mem2hex(&temp, ptr, 4, 0);
#endif
for (loop = 32; loop <= 63; loop++)
ptr = mem2hex(&__debug_user_context->i.gr[loop], ptr, 4, 0);
for (loop = 0; loop <= 63; loop++)
ptr = mem2hex(&__debug_user_context->f.fr[loop], ptr, 4, 0);
ptr = mem2hex(&__debug_frame->pc, ptr, 4, 0);
ptr = mem2hex(&__debug_frame->psr, ptr, 4, 0);
ptr = mem2hex(&__debug_frame->ccr, ptr, 4, 0);
ptr = mem2hex(&__debug_frame->cccr, ptr, 4, 0);
ptr = mem2hex(&zero, ptr, 4, 0);
ptr = mem2hex(&zero, ptr, 4, 0);
ptr = mem2hex(&zero, ptr, 4, 0);
ptr = mem2hex(&__debug_frame->tbr, ptr, 4, 0);
ptr = mem2hex(&__debug_status.brr , ptr, 4, 0);
asm volatile("movsg dbar0,%0" : "=r"(dbar));
ptr = mem2hex(&dbar, ptr, 4, 0);
asm volatile("movsg dbar1,%0" : "=r"(dbar));
ptr = mem2hex(&dbar, ptr, 4, 0);
asm volatile("movsg dbar2,%0" : "=r"(dbar));
ptr = mem2hex(&dbar, ptr, 4, 0);
asm volatile("movsg dbar3,%0" : "=r"(dbar));
ptr = mem2hex(&dbar, ptr, 4, 0);
asm volatile("movsg scr0,%0" : "=r"(dbar));
ptr = mem2hex(&dbar, ptr, 4, 0);
asm volatile("movsg scr1,%0" : "=r"(dbar));
ptr = mem2hex(&dbar, ptr, 4, 0);
asm volatile("movsg scr2,%0" : "=r"(dbar));
ptr = mem2hex(&dbar, ptr, 4, 0);
asm volatile("movsg scr3,%0" : "=r"(dbar));
ptr = mem2hex(&dbar, ptr, 4, 0);
ptr = mem2hex(&__debug_frame->lr, ptr, 4, 0);
ptr = mem2hex(&__debug_frame->lcr, ptr, 4, 0);
ptr = mem2hex(&__debug_frame->iacc0, ptr, 8, 0);
ptr = mem2hex(&__debug_user_context->f.fsr[0], ptr, 4, 0);
for (loop = 0; loop <= 7; loop++)
ptr = mem2hex(&__debug_user_context->f.acc[loop], ptr, 4, 0);
ptr = mem2hex(&__debug_user_context->f.accg, ptr, 8, 0);
for (loop = 0; loop <= 1; loop++)
ptr = mem2hex(&__debug_user_context->f.msr[loop], ptr, 4, 0);
ptr = mem2hex(&__debug_frame->gner0, ptr, 4, 0);
ptr = mem2hex(&__debug_frame->gner1, ptr, 4, 0);
ptr = mem2hex(&__debug_user_context->f.fner[0], ptr, 4, 0);
ptr = mem2hex(&__debug_user_context->f.fner[1], ptr, 4, 0);
break;
case 'G':
ptr = &input_buffer[1];
ptr = hex2mem(ptr, &temp, 4);
for (loop = 1; loop <= 27; loop++)
ptr = hex2mem(ptr, &__debug_user_context->i.gr[loop], 4);
ptr = hex2mem(ptr, &temp, 4);
__frame = (struct pt_regs *) temp;
ptr = hex2mem(ptr, &__debug_frame->gr29, 4);
ptr = hex2mem(ptr, &__debug_frame->gr30, 4);
#ifdef CONFIG_MMU
ptr = hex2mem(ptr, &__debug_frame->gr31, 4);
#else
ptr = hex2mem(ptr, &temp, 4);
#endif
for (loop = 32; loop <= 63; loop++)
ptr = hex2mem(ptr, &__debug_user_context->i.gr[loop], 4);
for (loop = 0; loop <= 63; loop++)
ptr = mem2hex(&__debug_user_context->f.fr[loop], ptr, 4, 0);
ptr = hex2mem(ptr, &__debug_frame->pc, 4);
ptr = hex2mem(ptr, &__debug_frame->psr, 4);
ptr = hex2mem(ptr, &__debug_frame->ccr, 4);
ptr = hex2mem(ptr, &__debug_frame->cccr,4);
for (loop = 132; loop <= 140; loop++)
ptr = hex2mem(ptr, &temp, 4);
ptr = hex2mem(ptr, &temp, 4);
asm volatile("movgs %0,scr0" :: "r"(temp));
ptr = hex2mem(ptr, &temp, 4);
asm volatile("movgs %0,scr1" :: "r"(temp));
ptr = hex2mem(ptr, &temp, 4);
asm volatile("movgs %0,scr2" :: "r"(temp));
ptr = hex2mem(ptr, &temp, 4);
asm volatile("movgs %0,scr3" :: "r"(temp));
ptr = hex2mem(ptr, &__debug_frame->lr, 4);
ptr = hex2mem(ptr, &__debug_frame->lcr, 4);
ptr = hex2mem(ptr, &__debug_frame->iacc0, 8);
ptr = hex2mem(ptr, &__debug_user_context->f.fsr[0], 4);
for (loop = 0; loop <= 7; loop++)
ptr = hex2mem(ptr, &__debug_user_context->f.acc[loop], 4);
ptr = hex2mem(ptr, &__debug_user_context->f.accg, 8);
for (loop = 0; loop <= 1; loop++)
ptr = hex2mem(ptr, &__debug_user_context->f.msr[loop], 4);
ptr = hex2mem(ptr, &__debug_frame->gner0, 4);
ptr = hex2mem(ptr, &__debug_frame->gner1, 4);
ptr = hex2mem(ptr, &__debug_user_context->f.fner[0], 4);
ptr = hex2mem(ptr, &__debug_user_context->f.fner[1], 4);
gdbstub_strcpy(output_buffer,"OK");
break;
case 'm':
ptr = &input_buffer[1];
if (hexToInt(&ptr, &addr) &&
*ptr++ == ',' &&
hexToInt(&ptr, &length)
) {
if (mem2hex((char *)addr, output_buffer, length, 1))
break;
gdbstub_strcpy (output_buffer, "E03");
}
else {
gdbstub_strcpy(output_buffer,"E01");
}
break;
case 'M':
ptr = &input_buffer[1];
if (hexToInt(&ptr, &addr) &&
*ptr++ == ',' &&
hexToInt(&ptr, &length) &&
*ptr++ == ':'
) {
if (hex2mem(ptr, (char *)addr, length)) {
gdbstub_strcpy(output_buffer, "OK");
}
else {
gdbstub_strcpy(output_buffer, "E03");
}
}
else
gdbstub_strcpy(output_buffer, "E02");
flush_cache = 1;
break;
case 'p':
break;
case 'P':
ptr = &input_buffer[1];
if (!hexToInt(&ptr, &addr) ||
*ptr++ != '=' ||
!hexToInt(&ptr, &temp)
) {
gdbstub_strcpy(output_buffer, "E01");
break;
}
temp2 = 1;
switch (addr) {
case GDB_REG_GR(0):
break;
case GDB_REG_GR(1) ... GDB_REG_GR(63):
__debug_user_context->i.gr[addr - GDB_REG_GR(0)] = temp;
break;
case GDB_REG_FR(0) ... GDB_REG_FR(63):
__debug_user_context->f.fr[addr - GDB_REG_FR(0)] = temp;
break;
case GDB_REG_PC:
__debug_user_context->i.pc = temp;
break;
case GDB_REG_PSR:
__debug_user_context->i.psr = temp;
break;
case GDB_REG_CCR:
__debug_user_context->i.ccr = temp;
break;
case GDB_REG_CCCR:
__debug_user_context->i.cccr = temp;
break;
case GDB_REG_BRR:
__debug_status.brr = temp;
break;
case GDB_REG_LR:
__debug_user_context->i.lr = temp;
break;
case GDB_REG_LCR:
__debug_user_context->i.lcr = temp;
break;
case GDB_REG_FSR0:
__debug_user_context->f.fsr[0] = temp;
break;
case GDB_REG_ACC(0) ... GDB_REG_ACC(7):
__debug_user_context->f.acc[addr - GDB_REG_ACC(0)] = temp;
break;
case GDB_REG_ACCG(0):
*(uint32_t *) &__debug_user_context->f.accg[0] = temp;
break;
case GDB_REG_ACCG(4):
*(uint32_t *) &__debug_user_context->f.accg[4] = temp;
break;
case GDB_REG_MSR(0) ... GDB_REG_MSR(1):
__debug_user_context->f.msr[addr - GDB_REG_MSR(0)] = temp;
break;
case GDB_REG_GNER(0) ... GDB_REG_GNER(1):
__debug_user_context->i.gner[addr - GDB_REG_GNER(0)] = temp;
break;
case GDB_REG_FNER(0) ... GDB_REG_FNER(1):
__debug_user_context->f.fner[addr - GDB_REG_FNER(0)] = temp;
break;
default:
temp2 = 0;
break;
}
if (temp2) {
gdbstub_strcpy(output_buffer, "OK");
}
else {
gdbstub_strcpy(output_buffer, "E02");
}
break;
case 'c':
ptr = &input_buffer[1];
if (hexToInt(&ptr, &addr))
__debug_frame->pc = addr;
goto done;
case 'k' :
goto done;
case 'D':
gdbstub_strcpy(output_buffer, "OK");
break;
case 'r':
break;
case 's':
__debug_regs->dcr |= DCR_SE;
__debug_status.dcr |= DCR_SE;
goto done;
case 'v':
if (strcmp(input_buffer, "vCont?") == 0) {
output_buffer[0] = 0;
break;
}
goto unsupported_cmd;
case 'b':
ptr = &input_buffer[1];
if (!hexToInt(&ptr, &temp)) {
gdbstub_strcpy(output_buffer,"B01");
break;
}
if (temp) {
gdbstub_send_packet("OK");
gdbstub_set_baud(temp);
}
break;
case 'Z':
ptr = &input_buffer[1];
if (!hexToInt(&ptr,&temp) || *ptr++ != ',' ||
!hexToInt(&ptr,&addr) || *ptr++ != ',' ||
!hexToInt(&ptr,&length)
) {
gdbstub_strcpy(output_buffer,"E01");
break;
}
if (temp >= 5) {
gdbstub_strcpy(output_buffer,"E03");
break;
}
if (gdbstub_set_breakpoint(temp, addr, length) < 0) {
gdbstub_strcpy(output_buffer,"E03");
break;
}
if (temp == 0)
flush_cache = 1;
gdbstub_strcpy(output_buffer,"OK");
break;
case 'z':
ptr = &input_buffer[1];
if (!hexToInt(&ptr,&temp) || *ptr++ != ',' ||
!hexToInt(&ptr,&addr) || *ptr++ != ',' ||
!hexToInt(&ptr,&length)
) {
gdbstub_strcpy(output_buffer,"E01");
break;
}
if (temp >= 5) {
gdbstub_strcpy(output_buffer,"E03");
break;
}
if (gdbstub_clear_breakpoint(temp, addr, length) < 0) {
gdbstub_strcpy(output_buffer,"E03");
break;
}
if (temp == 0)
flush_cache = 1;
gdbstub_strcpy(output_buffer,"OK");
break;
case 'H':
gdbstub_strcpy(output_buffer, "OK");
break;
case 'q':
gdbstub_handle_query();
break;
default:
unsupported_cmd:
gdbstub_proto("### GDB Unsupported Cmd '%s'\n",input_buffer);
gdbstub_strcpy(output_buffer,"E01");
break;
}
LEDS(0x5009);
gdbstub_send_packet(output_buffer);
}
done:
restore_user_regs(&__debug_frame0->uc);
if (flush_cache)
gdbstub_purge_cache();
LEDS(0x5666);
}
void __init gdbstub_init(void)
{
#ifdef CONFIG_GDBSTUB_IMMEDIATE
unsigned char ch;
int ret;
#endif
gdbstub_printk("%s", gdbstub_banner);
gdbstub_io_init();
gdbstub_proto("### GDB Tx ACK\n");
gdbstub_tx_char('+');
#ifdef CONFIG_GDBSTUB_IMMEDIATE
gdbstub_printk("GDB Stub waiting for packet\n");
do { gdbstub_rx_char(&ch, 0); } while (ch != '$');
do { gdbstub_rx_char(&ch, 0); } while (ch != '#');
do { ret = gdbstub_rx_char(&ch, 0); } while (ret != 0);
do { ret = gdbstub_rx_char(&ch, 0); } while (ret != 0);
gdbstub_proto("### GDB Tx NAK\n");
gdbstub_tx_char('-');
#else
gdbstub_printk("GDB Stub set\n");
#endif
#if 0
ptr = output_buffer;
*ptr++ = 'O';
ptr = mem2hex(gdbstub_banner, ptr, sizeof(gdbstub_banner) - 1, 0);
gdbstub_send_packet(output_buffer);
#endif
#if defined(CONFIG_GDB_CONSOLE) && defined(CONFIG_GDBSTUB_IMMEDIATE)
register_console(&gdbstub_console);
#endif
}
static int __init gdbstub_postinit(void)
{
printk("registering console\n");
register_console(&gdbstub_console);
return 0;
}
void gdbstub_exit(int status)
{
unsigned char checksum;
int count;
unsigned char ch;
sprintf(output_buffer,"W%02x",status&0xff);
gdbstub_tx_char('$');
checksum = 0;
count = 0;
while ((ch = output_buffer[count]) != 0) {
gdbstub_tx_char(ch);
checksum += ch;
count += 1;
}
gdbstub_tx_char('#');
gdbstub_tx_char(hex_asc_hi(checksum));
gdbstub_tx_char(hex_asc_lo(checksum));
gdbstub_tx_char('-');
gdbstub_tx_flush();
}
static void *malloc(size_t size)
{
return kmalloc(size, GFP_ATOMIC);
}
static void free(void *p)
{
kfree(p);
}
static uint32_t ___get_HSR0(void)
{
return __get_HSR(0);
}
static uint32_t ___set_HSR0(uint32_t x)
{
__set_HSR(0, x);
return __get_HSR(0);
}
