static char *dgap_sindex(char *string, char *group)
{
char *ptr;
if (!string || !group)
return NULL;
for (; *string; string++) {
for (ptr = group; *ptr; ptr++) {
if (*ptr == *string)
return string;
}
}
return NULL;
}
static char *dgap_getword(char **in)
{
char *ret_ptr = *in;
char *ptr = dgap_sindex(*in, " \t\n");
if (!ptr)
return NULL;
*ptr = '\0';
*in = ptr + 1;
while (*in && **in && ((**in == ' ') ||
(**in == '\t') ||
(**in == '\n'))) {
**in = '\0';
*in = *in + 1;
}
return ret_ptr;
}
static int dgap_gettok(char **in)
{
char *w;
struct toklist *t;
if (strstr(dgap_cword, "board")) {
w = dgap_getword(in);
snprintf(dgap_cword, MAXCWORD, "%s", w);
for (t = dgap_brdtype; t->token != 0; t++) {
if (!strcmp(w, t->string))
return t->token;
}
} else {
while ((w = dgap_getword(in))) {
snprintf(dgap_cword, MAXCWORD, "%s", w);
for (t = dgap_tlist; t->token != 0; t++) {
if (!strcmp(w, t->string))
return t->token;
}
}
}
return 0;
}
static int dgap_checknode(struct cnode *p)
{
switch (p->type) {
case LNODE:
if (p->u.line.v_speed == 0) {
pr_err("line speed not specified");
return 1;
}
return 0;
case CNODE:
if (p->u.conc.v_speed == 0) {
pr_err("concentrator line speed not specified");
return 1;
}
if (p->u.conc.v_nport == 0) {
pr_err("number of ports on concentrator not specified");
return 1;
}
if (p->u.conc.v_id == 0) {
pr_err("concentrator id letter not specified");
return 1;
}
return 0;
case MNODE:
if (p->u.module.v_nport == 0) {
pr_err("number of ports on EBI module not specified");
return 1;
}
if (p->u.module.v_id == 0) {
pr_err("EBI module id letter not specified");
return 1;
}
return 0;
}
return 0;
}
static uint dgap_config_get_useintr(struct board_t *bd)
{
struct cnode *p;
if (!bd)
return 0;
for (p = bd->bd_config; p; p = p->next) {
if (p->type == INTRNODE) {
return p->u.useintr;
}
}
return 0;
}
static uint dgap_config_get_altpin(struct board_t *bd)
{
struct cnode *p;
if (!bd)
return 0;
for (p = bd->bd_config; p; p = p->next) {
if (p->type == ANODE) {
return p->u.altpin;
}
}
return 0;
}
static struct cnode *dgap_find_config(int type, int bus, int slot)
{
struct cnode *p, *prev, *prev2, *found;
p = &dgap_head;
while (p->next) {
prev = p;
p = p->next;
if (p->type != BNODE)
continue;
if (p->u.board.type != type)
continue;
if (p->u.board.v_pcibus &&
p->u.board.pcibus != bus)
continue;
if (p->u.board.v_pcislot &&
p->u.board.pcislot != slot)
continue;
found = p;
while (p->next) {
prev2 = p;
p = p->next;
if (p->type != BNODE)
continue;
prev2->next = NULL;
prev->next = p;
return found;
}
prev->next = NULL;
return found;
}
return NULL;
}
static uint dgap_config_get_num_prts(struct board_t *bd)
{
int count = 0;
struct cnode *p;
if (!bd)
return 0;
for (p = bd->bd_config; p; p = p->next) {
switch (p->type) {
case BNODE:
if (p->u.board.type > EPCFE)
count += p->u.board.nport;
break;
case CNODE:
count += p->u.conc.nport;
break;
case MNODE:
count += p->u.module.nport;
break;
}
}
return count;
}
static char *dgap_create_config_string(struct board_t *bd, char *string)
{
char *ptr = string;
struct cnode *p;
struct cnode *q;
int speed;
if (!bd) {
*ptr = 0xff;
return string;
}
for (p = bd->bd_config; p; p = p->next) {
switch (p->type) {
case LNODE:
*ptr = '\0';
ptr++;
*ptr = p->u.line.speed;
ptr++;
break;
case CNODE:
speed = p->u.conc.speed;
q = p->next;
if (q && (q->type == MNODE)) {
*ptr = (p->u.conc.nport + 0x80);
ptr++;
p = q;
while (q->next && (q->next->type) == MNODE) {
*ptr = (q->u.module.nport + 0x80);
ptr++;
p = q;
q = q->next;
}
*ptr = q->u.module.nport;
ptr++;
} else {
*ptr = p->u.conc.nport;
ptr++;
}
*ptr = speed;
ptr++;
break;
}
}
*ptr = 0xff;
return string;
}
static int dgap_parsefile(char **in)
{
struct cnode *p, *brd, *line, *conc;
int rc;
char *s;
int linecnt = 0;
p = &dgap_head;
brd = line = conc = NULL;
while (p->next)
p = p->next;
while ((rc = dgap_gettok(in)) != BEGIN) {
if (rc == 0) {
pr_err("unexpected EOF");
return -1;
}
}
for (; ;) {
int board_type = 0;
int conc_type = 0;
int module_type = 0;
rc = dgap_gettok(in);
if (rc == 0) {
pr_err("unexpected EOF");
return -1;
}
switch (rc) {
case BEGIN:
pr_err("unexpected config_begin\n");
return -1;
case END:
return 0;
case BOARD:
if (dgap_checknode(p))
return -1;
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = BNODE;
p->u.board.status = kstrdup("No", GFP_KERNEL);
line = conc = NULL;
brd = p;
linecnt = -1;
board_type = dgap_gettok(in);
if (board_type == 0) {
pr_err("board !!type not specified");
return -1;
}
p->u.board.type = board_type;
break;
case IO:
if (p->type != BNODE) {
pr_err("IO port only valid for boards");
return -1;
}
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
p->u.board.portstr = kstrdup(s, GFP_KERNEL);
if (kstrtol(s, 0, &p->u.board.port)) {
pr_err("bad number for IO port");
return -1;
}
p->u.board.v_port = 1;
break;
case MEM:
if (p->type != BNODE) {
pr_err("memory address only valid for boards");
return -1;
}
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
p->u.board.addrstr = kstrdup(s, GFP_KERNEL);
if (kstrtoul(s, 0, &p->u.board.addr)) {
pr_err("bad number for memory address");
return -1;
}
p->u.board.v_addr = 1;
break;
case PCIINFO:
if (p->type != BNODE) {
pr_err("memory address only valid for boards");
return -1;
}
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
p->u.board.pcibusstr = kstrdup(s, GFP_KERNEL);
if (kstrtoul(s, 0, &p->u.board.pcibus)) {
pr_err("bad number for pci bus");
return -1;
}
p->u.board.v_pcibus = 1;
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
p->u.board.pcislotstr = kstrdup(s, GFP_KERNEL);
if (kstrtoul(s, 0, &p->u.board.pcislot)) {
pr_err("bad number for pci slot");
return -1;
}
p->u.board.v_pcislot = 1;
break;
case METHOD:
if (p->type != BNODE) {
pr_err("install method only valid for boards");
return -1;
}
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
p->u.board.method = kstrdup(s, GFP_KERNEL);
p->u.board.v_method = 1;
break;
case STATUS:
if (p->type != BNODE) {
pr_err("config status only valid for boards");
return -1;
}
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
p->u.board.status = kstrdup(s, GFP_KERNEL);
break;
case NPORTS:
if (p->type == BNODE) {
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.board.nport)) {
pr_err("bad number for number of ports");
return -1;
}
p->u.board.v_nport = 1;
} else if (p->type == CNODE) {
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.conc.nport)) {
pr_err("bad number for number of ports");
return -1;
}
p->u.conc.v_nport = 1;
} else if (p->type == MNODE) {
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.module.nport)) {
pr_err("bad number for number of ports");
return -1;
}
p->u.module.v_nport = 1;
} else {
pr_err("nports only valid for concentrators or modules");
return -1;
}
break;
case ID:
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
p->u.board.status = kstrdup(s, GFP_KERNEL);
if (p->type == CNODE) {
p->u.conc.id = kstrdup(s, GFP_KERNEL);
p->u.conc.v_id = 1;
} else if (p->type == MNODE) {
p->u.module.id = kstrdup(s, GFP_KERNEL);
p->u.module.v_id = 1;
} else {
pr_err("id only valid for concentrators or modules");
return -1;
}
break;
case STARTO:
if (p->type == BNODE) {
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.board.start)) {
pr_err("bad number for start of tty count");
return -1;
}
p->u.board.v_start = 1;
} else if (p->type == CNODE) {
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.conc.start)) {
pr_err("bad number for start of tty count");
return -1;
}
p->u.conc.v_start = 1;
} else if (p->type == MNODE) {
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.module.start)) {
pr_err("bad number for start of tty count");
return -1;
}
p->u.module.v_start = 1;
} else {
pr_err("start only valid for concentrators or modules");
return -1;
}
break;
case TTYN:
if (dgap_checknode(p))
return -1;
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = TNODE;
s = dgap_getword(in);
if (!s) {
pr_err("unexpeced end of file");
return -1;
}
p->u.ttyname = kstrdup(s, GFP_KERNEL);
if (!p->u.ttyname)
return -1;
break;
case CU:
if (dgap_checknode(p))
return -1;
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = CUNODE;
s = dgap_getword(in);
if (!s) {
pr_err("unexpeced end of file");
return -1;
}
p->u.cuname = kstrdup(s, GFP_KERNEL);
if (!p->u.cuname)
return -1;
break;
case LINE:
if (dgap_checknode(p))
return -1;
if (!brd) {
pr_err("must specify board before line info");
return -1;
}
switch (brd->u.board.type) {
case PPCM:
pr_err("line not valid for PC/em");
return -1;
}
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = LNODE;
conc = NULL;
line = p;
linecnt++;
break;
case CONC:
if (dgap_checknode(p))
return -1;
if (!line) {
pr_err("must specify line info before concentrator");
return -1;
}
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = CNODE;
conc = p;
if (linecnt)
brd->u.board.conc2++;
else
brd->u.board.conc1++;
conc_type = dgap_gettok(in);
if (conc_type == 0 || (conc_type != CX &&
conc_type != EPC)) {
pr_err("failed to set a type of concentratros");
return -1;
}
p->u.conc.type = conc_type;
break;
case MOD:
if (dgap_checknode(p))
return -1;
if (!brd) {
pr_err("must specify board info before EBI modules");
return -1;
}
switch (brd->u.board.type) {
case PPCM:
linecnt = 0;
break;
default:
if (!conc) {
pr_err("must specify concentrator info before EBI module");
return -1;
}
}
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = MNODE;
if (linecnt)
brd->u.board.module2++;
else
brd->u.board.module1++;
module_type = dgap_gettok(in);
if (module_type == 0 || (module_type != PORTS &&
module_type != MODEM)) {
pr_err("failed to set a type of module");
return -1;
}
p->u.module.type = module_type;
break;
case CABLE:
if (p->type == LNODE) {
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
p->u.line.cable = kstrdup(s, GFP_KERNEL);
p->u.line.v_cable = 1;
}
break;
case SPEED:
if (p->type == LNODE) {
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.line.speed)) {
pr_err("bad number for line speed");
return -1;
}
p->u.line.v_speed = 1;
} else if (p->type == CNODE) {
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.conc.speed)) {
pr_err("bad number for line speed");
return -1;
}
p->u.conc.v_speed = 1;
} else {
pr_err("speed valid only for lines or concentrators.");
return -1;
}
break;
case CONNECT:
if (p->type == CNODE) {
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
p->u.conc.connect = kstrdup(s, GFP_KERNEL);
p->u.conc.v_connect = 1;
}
break;
case PRINT:
if (dgap_checknode(p))
return -1;
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = PNODE;
s = dgap_getword(in);
if (!s) {
pr_err("unexpeced end of file");
return -1;
}
p->u.printname = kstrdup(s, GFP_KERNEL);
if (!p->u.printname)
return -1;
break;
case CMAJOR:
if (dgap_checknode(p))
return -1;
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = JNODE;
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.majornumber)) {
pr_err("bad number for major number");
return -1;
}
break;
case ALTPIN:
if (dgap_checknode(p))
return -1;
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = ANODE;
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.altpin)) {
pr_err("bad number for altpin");
return -1;
}
break;
case USEINTR:
if (dgap_checknode(p))
return -1;
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = INTRNODE;
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.useintr)) {
pr_err("bad number for useintr");
return -1;
}
break;
case TTSIZ:
if (dgap_checknode(p))
return -1;
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = TSNODE;
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.ttysize)) {
pr_err("bad number for ttysize");
return -1;
}
break;
case CHSIZ:
if (dgap_checknode(p))
return -1;
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = CSNODE;
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.chsize)) {
pr_err("bad number for chsize");
return -1;
}
break;
case BSSIZ:
if (dgap_checknode(p))
return -1;
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = BSNODE;
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.bssize)) {
pr_err("bad number for bssize");
return -1;
}
break;
case UNTSIZ:
if (dgap_checknode(p))
return -1;
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = USNODE;
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.unsize)) {
pr_err("bad number for schedsize");
return -1;
}
break;
case F2SIZ:
if (dgap_checknode(p))
return -1;
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = FSNODE;
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.f2size)) {
pr_err("bad number for f2200size");
return -1;
}
break;
case VPSIZ:
if (dgap_checknode(p))
return -1;
p->next = kzalloc(sizeof(struct cnode), GFP_KERNEL);
if (!p->next)
return -1;
p = p->next;
p->type = VSNODE;
s = dgap_getword(in);
if (!s) {
pr_err("unexpected end of file");
return -1;
}
if (kstrtol(s, 0, &p->u.vpixsize)) {
pr_err("bad number for vpixsize");
return -1;
}
break;
}
}
}
static void dgap_cleanup_nodes(void)
{
struct cnode *p;
p = &dgap_head;
while (p) {
struct cnode *tmp = p->next;
if (p->type == NULLNODE) {
p = tmp;
continue;
}
switch (p->type) {
case BNODE:
kfree(p->u.board.portstr);
kfree(p->u.board.addrstr);
kfree(p->u.board.pcibusstr);
kfree(p->u.board.pcislotstr);
kfree(p->u.board.method);
break;
case CNODE:
kfree(p->u.conc.id);
kfree(p->u.conc.connect);
break;
case MNODE:
kfree(p->u.module.id);
break;
case TNODE:
kfree(p->u.ttyname);
break;
case CUNODE:
kfree(p->u.cuname);
break;
case LNODE:
kfree(p->u.line.cable);
break;
case PNODE:
kfree(p->u.printname);
break;
}
kfree(p->u.board.status);
kfree(p);
p = tmp;
}
}
static uint dgap_get_custom_baud(struct channel_t *ch)
{
u8 __iomem *vaddr;
ulong offset;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return 0;
if (!ch->ch_bd || ch->ch_bd->magic != DGAP_BOARD_MAGIC)
return 0;
if (!(ch->ch_bd->bd_flags & BD_FEP5PLUS))
return 0;
vaddr = ch->ch_bd->re_map_membase;
if (!vaddr)
return 0;
offset = (ioread16(vaddr + ECS_SEG) << 4) + (ch->ch_portnum * 0x28)
+ LINE_SPEED;
return readw(vaddr + offset);
}
static int dgap_remap(struct board_t *brd)
{
if (!brd || brd->magic != DGAP_BOARD_MAGIC)
return -EIO;
if (!request_mem_region(brd->membase, 0x200000, "dgap"))
return -ENOMEM;
if (!request_mem_region(brd->membase + PCI_IO_OFFSET, 0x200000,
"dgap"))
goto err_req_mem;
brd->re_map_membase = ioremap(brd->membase, 0x200000);
if (!brd->re_map_membase)
goto err_remap_mem;
brd->re_map_port = ioremap((brd->membase + PCI_IO_OFFSET), 0x200000);
if (!brd->re_map_port)
goto err_remap_port;
return 0;
err_remap_port:
iounmap(brd->re_map_membase);
err_remap_mem:
release_mem_region(brd->membase + PCI_IO_OFFSET, 0x200000);
err_req_mem:
release_mem_region(brd->membase, 0x200000);
return -ENOMEM;
}
static void dgap_unmap(struct board_t *brd)
{
iounmap(brd->re_map_port);
iounmap(brd->re_map_membase);
release_mem_region(brd->membase + PCI_IO_OFFSET, 0x200000);
release_mem_region(brd->membase, 0x200000);
}
static void dgap_parity_scan(struct channel_t *ch, unsigned char *cbuf,
unsigned char *fbuf, int *len)
{
int l = *len;
int count = 0;
unsigned char *in, *cout, *fout;
unsigned char c;
in = cbuf;
cout = cbuf;
fout = fbuf;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
while (l--) {
c = *in++;
switch (ch->pscan_state) {
default:
ch->pscan_state = 0;
case 0:
if (c == (unsigned char) '\377')
ch->pscan_state = 1;
else {
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
ch->ch_err_break++;
*fout++ = TTY_BREAK;
} else {
ch->ch_err_parity++;
*fout++ = TTY_PARITY;
}
}
count += 1;
ch->pscan_state = 0;
}
}
*len = count;
}
static void dgap_input(struct channel_t *ch)
{
struct board_t *bd;
struct bs_t __iomem *bs;
struct tty_struct *tp;
struct tty_ldisc *ld;
uint rmask;
uint head;
uint tail;
int data_len;
ulong lock_flags;
ulong lock_flags2;
int flip_len;
int len;
int n;
u8 *buf;
u8 tmpchar;
int s;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
tp = ch->ch_tun.un_tty;
bs = ch->ch_bs;
if (!bs)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
rmask = ch->ch_rsize - 1;
head = readw(&(bs->rx_head));
head &= rmask;
tail = readw(&(bs->rx_tail));
tail &= rmask;
data_len = (head - tail) & rmask;
if (data_len == 0) {
writeb(1, &(bs->idata));
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return;
}
if ((bd->state != BOARD_READY) || !tp ||
(tp->magic != TTY_MAGIC) ||
!(ch->ch_tun.un_flags & UN_ISOPEN) ||
!(tp->termios.c_cflag & CREAD) ||
(ch->ch_tun.un_flags & UN_CLOSING)) {
writew(head, &(bs->rx_tail));
writeb(1, &(bs->idata));
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return;
}
if (ch->ch_flags & CH_RXBLOCK) {
writeb(1, &(bs->idata));
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return;
}
tmpchar = readb(&(bs->orun));
if (tmpchar) {
ch->ch_err_overrun++;
writeb(0, &(bs->orun));
}
flip_len = TTY_FLIPBUF_SIZE;
len = min(data_len, flip_len);
len = min(len, (N_TTY_BUF_SIZE - 1));
ld = tty_ldisc_ref(tp);
#ifdef TTY_DONT_FLIP
if (test_bit(TTY_DONT_FLIP, &tp->flags))
len = 0;
#endif
if (!ld) {
len = 0;
} else {
if (!ld->ops->receive_buf) {
writew(head, &(bs->rx_tail));
len = 0;
}
}
if (len <= 0) {
writeb(1, &(bs->idata));
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
if (ld)
tty_ldisc_deref(ld);
return;
}
buf = ch->ch_bd->flipbuf;
n = len;
while (n) {
s = ((head >= tail) ? head : ch->ch_rsize) - tail;
s = min(s, n);
if (s <= 0)
break;
memcpy_fromio(buf, ch->ch_raddr + tail, s);
tail += s;
buf += s;
n -= s;
tail &= rmask;
}
writew(tail, &(bs->rx_tail));
writeb(1, &(bs->idata));
ch->ch_rxcount += len;
if (I_PARMRK(tp) || I_BRKINT(tp) || I_INPCK(tp)) {
dgap_parity_scan(ch, ch->ch_bd->flipbuf,
ch->ch_bd->flipflagbuf, &len);
len = tty_buffer_request_room(tp->port, len);
tty_insert_flip_string_flags(tp->port, ch->ch_bd->flipbuf,
ch->ch_bd->flipflagbuf, len);
} else {
len = tty_buffer_request_room(tp->port, len);
tty_insert_flip_string(tp->port, ch->ch_bd->flipbuf, len);
}
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
tty_flip_buffer_push(tp->port);
if (ld)
tty_ldisc_deref(ld);
}
static void dgap_write_wakeup(struct board_t *bd, struct channel_t *ch,
struct un_t *un, u32 mask,
unsigned long *irq_flags1,
unsigned long *irq_flags2)
{
if (!(un->un_flags & mask))
return;
un->un_flags &= ~mask;
if (!(un->un_flags & UN_ISOPEN))
return;
if ((un->un_tty->flags & (1 << TTY_DO_WRITE_WAKEUP)) &&
un->un_tty->ldisc->ops->write_wakeup) {
spin_unlock_irqrestore(&ch->ch_lock, *irq_flags2);
spin_unlock_irqrestore(&bd->bd_lock, *irq_flags1);
(un->un_tty->ldisc->ops->write_wakeup)(un->un_tty);
spin_lock_irqsave(&bd->bd_lock, *irq_flags1);
spin_lock_irqsave(&ch->ch_lock, *irq_flags2);
}
wake_up_interruptible(&un->un_tty->write_wait);
wake_up_interruptible(&un->un_flags_wait);
}
static void dgap_carrier(struct channel_t *ch)
{
struct board_t *bd;
int virt_carrier = 0;
int phys_carrier = 0;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
if (ch->ch_digi.digi_flags & DIGI_ALTPIN) {
ch->ch_dsr = DM_CD;
ch->ch_cd = DM_DSR;
} else {
ch->ch_dsr = DM_DSR;
ch->ch_cd = DM_CD;
}
if (ch->ch_mistat & D_CD(ch))
phys_carrier = 1;
if (ch->ch_digi.digi_flags & DIGI_FORCEDCD)
virt_carrier = 1;
if (ch->ch_c_cflag & CLOCAL)
virt_carrier = 1;
if (((ch->ch_flags & CH_FCAR) == 0) && (virt_carrier == 1)) {
if (waitqueue_active(&(ch->ch_flags_wait)))
wake_up_interruptible(&ch->ch_flags_wait);
}
if (((ch->ch_flags & CH_CD) == 0) && (phys_carrier == 1)) {
if (waitqueue_active(&(ch->ch_flags_wait)))
wake_up_interruptible(&ch->ch_flags_wait);
}
if ((virt_carrier == 0) &&
((ch->ch_flags & CH_CD) != 0) &&
(phys_carrier == 0)) {
if (waitqueue_active(&(ch->ch_flags_wait)))
wake_up_interruptible(&ch->ch_flags_wait);
if (ch->ch_tun.un_open_count > 0)
tty_hangup(ch->ch_tun.un_tty);
if (ch->ch_pun.un_open_count > 0)
tty_hangup(ch->ch_pun.un_tty);
}
if (virt_carrier == 1)
ch->ch_flags |= CH_FCAR;
else
ch->ch_flags &= ~CH_FCAR;
if (phys_carrier == 1)
ch->ch_flags |= CH_CD;
else
ch->ch_flags &= ~CH_CD;
}
static int dgap_event(struct board_t *bd)
{
struct channel_t *ch;
ulong lock_flags;
ulong lock_flags2;
struct bs_t __iomem *bs;
u8 __iomem *event;
u8 __iomem *vaddr;
struct ev_t __iomem *eaddr;
uint head;
uint tail;
int port;
int reason;
int modem;
int b1;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return -EIO;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
vaddr = bd->re_map_membase;
if (!vaddr) {
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return -EIO;
}
eaddr = (struct ev_t __iomem *) (vaddr + EVBUF);
head = readw(&(eaddr->ev_head));
tail = readw(&(eaddr->ev_tail));
if (head >= EVMAX - EVSTART || tail >= EVMAX - EVSTART ||
(head | tail) & 03) {
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return -EIO;
}
while (tail != head) {
event = bd->re_map_membase + tail + EVSTART;
port = ioread8(event);
reason = ioread8(event + 1);
modem = ioread8(event + 2);
b1 = ioread8(event + 3);
if (port >= bd->nasync)
goto next;
if (!(reason & (IFMODEM | IFBREAK | IFTLW | IFTEM | IFDATA)))
goto next;
ch = bd->channels[port];
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
goto next;
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
bs = ch->ch_bs;
if (!bs) {
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
goto next;
}
if (reason & IFDATA) {
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
dgap_input(ch);
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
if (ch->ch_flags & CH_RACTIVE)
ch->ch_flags |= CH_RENABLE;
else
writeb(1, &(bs->idata));
if (ch->ch_flags & CH_RWAIT) {
ch->ch_flags &= ~CH_RWAIT;
wake_up_interruptible
(&ch->ch_tun.un_flags_wait);
}
}
if (reason & IFMODEM) {
ch->ch_mistat = modem;
dgap_carrier(ch);
}
if (reason & IFBREAK) {
if (ch->ch_tun.un_tty) {
ch->ch_err_break++;
tty_buffer_request_room
(ch->ch_tun.un_tty->port, 1);
tty_insert_flip_char(ch->ch_tun.un_tty->port,
0, TTY_BREAK);
tty_flip_buffer_push(ch->ch_tun.un_tty->port);
}
}
if (reason & IFTLW) {
dgap_write_wakeup(bd, ch, &ch->ch_tun, UN_LOW,
&lock_flags, &lock_flags2);
dgap_write_wakeup(bd, ch, &ch->ch_pun, UN_LOW,
&lock_flags, &lock_flags2);
if (ch->ch_flags & CH_WLOW) {
ch->ch_flags &= ~CH_WLOW;
wake_up_interruptible(&ch->ch_flags_wait);
}
}
if (reason & IFTEM) {
dgap_write_wakeup(bd, ch, &ch->ch_tun, UN_EMPTY,
&lock_flags, &lock_flags2);
dgap_write_wakeup(bd, ch, &ch->ch_pun, UN_EMPTY,
&lock_flags, &lock_flags2);
if (ch->ch_flags & CH_WEMPTY) {
ch->ch_flags &= ~CH_WEMPTY;
wake_up_interruptible(&ch->ch_flags_wait);
}
}
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
next:
tail = (tail + 4) & (EVMAX - EVSTART - 4);
}
writew(tail, &(eaddr->ev_tail));
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return 0;
}
static void dgap_poll_tasklet(unsigned long data)
{
struct board_t *bd = (struct board_t *) data;
ulong lock_flags;
char __iomem *vaddr;
u16 head, tail;
if (!bd || (bd->magic != DGAP_BOARD_MAGIC))
return;
if (bd->inhibit_poller)
return;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
vaddr = bd->re_map_membase;
if (bd->state == BOARD_READY) {
struct ev_t __iomem *eaddr;
if (!bd->re_map_membase) {
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return;
}
if (!bd->re_map_port) {
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return;
}
if (!bd->nasync)
goto out;
eaddr = (struct ev_t __iomem *) (vaddr + EVBUF);
head = readw(&(eaddr->ev_head));
tail = readw(&(eaddr->ev_tail));
if (head != tail) {
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
dgap_event(bd);
spin_lock_irqsave(&bd->bd_lock, lock_flags);
}
out:
if (bd && bd->intr_running)
readb(bd->re_map_port + 2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return;
}
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
}
static struct board_t *dgap_found_board(struct pci_dev *pdev, int id,
int boardnum)
{
struct board_t *brd;
unsigned int pci_irq;
int i;
int ret;
brd = kzalloc(sizeof(struct board_t), GFP_KERNEL);
if (!brd)
return ERR_PTR(-ENOMEM);
brd->magic = DGAP_BOARD_MAGIC;
brd->boardnum = boardnum;
brd->vendor = dgap_pci_tbl[id].vendor;
brd->device = dgap_pci_tbl[id].device;
brd->pdev = pdev;
brd->pci_bus = pdev->bus->number;
brd->pci_slot = PCI_SLOT(pdev->devfn);
brd->name = dgap_ids[id].name;
brd->maxports = dgap_ids[id].maxports;
brd->type = dgap_ids[id].config_type;
brd->dpatype = dgap_ids[id].dpatype;
brd->dpastatus = BD_NOFEP;
init_waitqueue_head(&brd->state_wait);
spin_lock_init(&brd->bd_lock);
brd->inhibit_poller = FALSE;
brd->wait_for_bios = 0;
brd->wait_for_fep = 0;
for (i = 0; i < MAXPORTS; i++)
brd->channels[i] = NULL;
pci_read_config_word(pdev, PCI_SUBSYSTEM_VENDOR_ID, &brd->subvendor);
pci_read_config_word(pdev, PCI_SUBSYSTEM_ID, &brd->subdevice);
pci_read_config_byte(pdev, PCI_REVISION_ID, &brd->rev);
pci_irq = pdev->irq;
brd->irq = pci_irq;
if (brd->device == PCI_DEV_XRJ_DID || brd->device == PCI_DEV_EPCJ_DID) {
brd->membase = pci_resource_start(pdev, 2);
brd->membase_end = pci_resource_end(pdev, 2);
}
else {
brd->membase = pci_resource_start(pdev, 0);
brd->membase_end = pci_resource_end(pdev, 0);
}
if (!brd->membase) {
ret = -ENODEV;
goto free_brd;
}
if (brd->membase & 1)
brd->membase &= ~3;
else
brd->membase &= ~15;
brd->port = brd->membase + PCI_IO_OFFSET;
brd->port_end = brd->port + PCI_IO_SIZE_DGAP;
if (brd->device != PCI_DEV_XRJ_DID && brd->device != PCI_DEV_EPCJ_DID) {
unsigned short cmd;
pci_write_config_byte(pdev, 0x40, 0);
pci_write_config_byte(pdev, 0x46, 0);
pci_write_config_byte(pdev, 0x42, 1);
pci_read_config_word(pdev, PCI_COMMAND, &cmd);
cmd |= (PCI_COMMAND_IO | PCI_COMMAND_MEMORY);
pci_write_config_word(pdev, PCI_COMMAND, cmd);
}
tasklet_init(&brd->helper_tasklet, dgap_poll_tasklet,
(unsigned long) brd);
ret = dgap_remap(brd);
if (ret)
goto free_brd;
pr_info("dgap: board %d: %s (rev %d), irq %ld\n",
boardnum, brd->name, brd->rev, brd->irq);
return brd;
free_brd:
kfree(brd);
return ERR_PTR(ret);
}
static irqreturn_t dgap_intr(int irq, void *voidbrd)
{
struct board_t *brd = voidbrd;
if (!brd)
return IRQ_NONE;
if (brd->magic != DGAP_BOARD_MAGIC)
return IRQ_NONE;
brd->intr_count++;
tasklet_schedule(&brd->helper_tasklet);
return IRQ_HANDLED;
}
static void dgap_poll_handler(ulong dummy)
{
unsigned int i;
struct board_t *brd;
unsigned long lock_flags;
ulong new_time;
dgap_poll_counter++;
if (dgap_driver_state != DRIVER_READY)
goto schedule_poller;
if ((dgap_numboards == 1) || (num_online_cpus() <= 1)) {
for (i = 0; i < dgap_numboards; i++) {
brd = dgap_board[i];
if (brd->state == BOARD_FAILED)
continue;
if (!brd->intr_running)
dgap_poll_tasklet((unsigned long) brd);
}
} else {
for (i = 0; i < dgap_numboards; i++) {
brd = dgap_board[i];
if (!spin_trylock(&brd->bd_lock))
continue;
if (brd->state == BOARD_FAILED) {
spin_unlock(&brd->bd_lock);
continue;
}
if (!brd->intr_running)
tasklet_schedule(&brd->helper_tasklet);
spin_unlock(&brd->bd_lock);
}
}
schedule_poller:
spin_lock_irqsave(&dgap_poll_lock, lock_flags);
dgap_poll_time += dgap_jiffies_from_ms(dgap_poll_tick);
new_time = dgap_poll_time - jiffies;
if ((ulong) new_time >= 2 * dgap_poll_tick) {
dgap_poll_time =
jiffies + dgap_jiffies_from_ms(dgap_poll_tick);
}
dgap_poll_timer.function = dgap_poll_handler;
dgap_poll_timer.data = 0;
dgap_poll_timer.expires = dgap_poll_time;
spin_unlock_irqrestore(&dgap_poll_lock, lock_flags);
if (!dgap_poll_stop)
add_timer(&dgap_poll_timer);
}
static void dgap_cmdb(struct channel_t *ch, u8 cmd, u8 byte1,
u8 byte2, uint ncmds)
{
char __iomem *vaddr;
struct __iomem cm_t *cm_addr;
uint count;
uint n;
u16 head;
u16 tail;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
if (ch->ch_bd->state == BOARD_FAILED)
return;
vaddr = ch->ch_bd->re_map_membase;
if (!vaddr)
return;
cm_addr = (struct cm_t __iomem *) (vaddr + CMDBUF);
head = readw(&(cm_addr->cm_head));
if (head >= (CMDMAX - CMDSTART) || (head & 03)) {
ch->ch_bd->state = BOARD_FAILED;
return;
}
writeb(cmd, (vaddr + head + CMDSTART + 0));
writeb((u8) ch->ch_portnum, (vaddr + head + CMDSTART + 1));
writeb(byte1, (vaddr + head + CMDSTART + 2));
writeb(byte2, (vaddr + head + CMDSTART + 3));
head = (head + 4) & (CMDMAX - CMDSTART - 4);
writew(head, &(cm_addr->cm_head));
for (count = dgap_count ;;) {
head = readw(&(cm_addr->cm_head));
tail = readw(&(cm_addr->cm_tail));
n = (head - tail) & (CMDMAX - CMDSTART - 4);
if (n <= ncmds * sizeof(struct cm_t))
break;
if (--count == 0) {
ch->ch_bd->state = BOARD_FAILED;
return;
}
udelay(10);
}
}
static void dgap_cmdw(struct channel_t *ch, u8 cmd, u16 word, uint ncmds)
{
char __iomem *vaddr;
struct __iomem cm_t *cm_addr;
uint count;
uint n;
u16 head;
u16 tail;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
if (ch->ch_bd->state == BOARD_FAILED)
return;
vaddr = ch->ch_bd->re_map_membase;
if (!vaddr)
return;
cm_addr = (struct cm_t __iomem *) (vaddr + CMDBUF);
head = readw(&(cm_addr->cm_head));
if (head >= (CMDMAX - CMDSTART) || (head & 03)) {
ch->ch_bd->state = BOARD_FAILED;
return;
}
writeb(cmd, (vaddr + head + CMDSTART + 0));
writeb((u8) ch->ch_portnum, (vaddr + head + CMDSTART + 1));
writew((u16) word, (vaddr + head + CMDSTART + 2));
head = (head + 4) & (CMDMAX - CMDSTART - 4);
writew(head, &(cm_addr->cm_head));
for (count = dgap_count ;;) {
head = readw(&(cm_addr->cm_head));
tail = readw(&(cm_addr->cm_tail));
n = (head - tail) & (CMDMAX - CMDSTART - 4);
if (n <= ncmds * sizeof(struct cm_t))
break;
if (--count == 0) {
ch->ch_bd->state = BOARD_FAILED;
return;
}
udelay(10);
}
}
static void dgap_cmdw_ext(struct channel_t *ch, u16 cmd, u16 word, uint ncmds)
{
char __iomem *vaddr;
struct __iomem cm_t *cm_addr;
uint count;
uint n;
u16 head;
u16 tail;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
if (ch->ch_bd->state == BOARD_FAILED)
return;
vaddr = ch->ch_bd->re_map_membase;
if (!vaddr)
return;
cm_addr = (struct cm_t __iomem *) (vaddr + CMDBUF);
head = readw(&(cm_addr->cm_head));
if (head >= (CMDMAX - CMDSTART) || (head & 03)) {
ch->ch_bd->state = BOARD_FAILED;
return;
}
writeb((u8) 0xff, (vaddr + head + CMDSTART + 0));
writeb((u8) ch->ch_portnum, (vaddr + head + CMDSTART + 1));
writew((u16) cmd, (vaddr + head + CMDSTART + 2));
if (((head + 4) >= ((CMDMAX - CMDSTART)) || (head & 03)))
writew((u16) word, (vaddr + CMDSTART));
else
writew((u16) word, (vaddr + head + CMDSTART + 4));
head = (head + 8) & (CMDMAX - CMDSTART - 4);
writew(head, &(cm_addr->cm_head));
for (count = dgap_count ;;) {
head = readw(&(cm_addr->cm_head));
tail = readw(&(cm_addr->cm_tail));
n = (head - tail) & (CMDMAX - CMDSTART - 4);
if (n <= ncmds * sizeof(struct cm_t))
break;
if (--count == 0) {
ch->ch_bd->state = BOARD_FAILED;
return;
}
udelay(10);
}
}
static void dgap_wmove(struct channel_t *ch, char *buf, uint cnt)
{
int n;
char __iomem *taddr;
struct bs_t __iomem *bs;
u16 head;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bs = ch->ch_bs;
head = readw(&(bs->tx_head));
if ((cnt > ch->ch_tsize) ||
(unsigned)(head - ch->ch_tstart) >= ch->ch_tsize)
return;
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
static void dgap_firmware_reset_port(struct channel_t *ch)
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
static int dgap_param(struct channel_t *ch, struct board_t *bd, u32 un_type)
{
u16 head;
u16 cflag;
u16 iflag;
u8 mval;
u8 hflow;
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
dgap_cmdw_ext(ch, 0xff01, ch->ch_custom_speed, 0);
ch->ch_custom_speed = dgap_get_custom_baud(ch);
ch->ch_baud_info = ch->ch_custom_speed;
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
if (!(ch->ch_tun.un_flags & UN_ISOPEN) &&
un_type == DGAP_PRINT)
baud = C_BAUD(ch->ch_pun.un_tty) & 0xff;
else
baud = C_BAUD(ch->ch_tun.un_tty) & 0xff;
if (ch->ch_c_cflag & CBAUDEX)
iindex = 1;
if (ch->ch_digi.digi_flags & DIGI_FAST)
iindex += 2;
jindex = baud;
if ((iindex >= 0) && (iindex < 4) &&
(jindex >= 0) && (jindex < 16))
baud = bauds[iindex][jindex];
else
baud = 0;
if (baud == 0)
baud = 9600;
ch->ch_baud_info = baud;
cflag = ch->ch_c_cflag & ((CBAUD ^ CBAUDEX) | PARODD | PARENB |
CSTOPB | CSIZE);
if ((ch->ch_digi.digi_flags & DIGI_FAST) ||
(ch->ch_c_cflag & CBAUDEX))
cflag |= HUPCL;
if ((ch->ch_c_cflag & CBAUDEX) &&
!(ch->ch_digi.digi_flags & DIGI_FAST)) {
tcflag_t tcflag = (ch->ch_c_cflag & CBAUD) | CBAUDEX;
int baudpart = 0;
switch (tcflag) {
case B57600:
baudpart = 1;
break;
#ifdef B76800
case B76800:
baudpart = 2;
break;
#endif
case B115200:
baudpart = 3;
break;
case B230400:
baudpart = 9;
break;
case B460800:
baudpart = 11;
break;
#ifdef B921600
case B921600:
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
iflag = ch->ch_c_iflag & (IGNBRK | BRKINT | IGNPAR | PARMRK |
INPCK | ISTRIP | IXON | IXANY | IXOFF);
if ((ch->ch_startc == _POSIX_VDISABLE) ||
(ch->ch_stopc == _POSIX_VDISABLE)) {
iflag &= ~(IXON | IXOFF);
ch->ch_c_iflag &= ~(IXON | IXOFF);
}
if (bd->device == PCI_DEV_XR_IBM_DID) {
if (ch->ch_digi.digi_flags & DIGI_422)
dgap_cmdb(ch, SCOMMODE, MODE_422, 0, 0);
else
dgap_cmdb(ch, SCOMMODE, MODE_232, 0, 0);
}
if (ch->ch_digi.digi_flags & DIGI_ALTPIN)
iflag |= IALTPIN;
if (iflag != ch->ch_fepiflag) {
ch->ch_fepiflag = iflag;
dgap_cmdw(ch, SIFLAG, (u16) ch->ch_fepiflag, 0);
}
hflow = 0;
if (ch->ch_c_cflag & CRTSCTS)
hflow |= (D_RTS(ch) | D_CTS(ch));
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
dgap_cmdb(ch, SHFLOW, (u8) hflow, 0xff, 0);
}
if (bd->bd_flags & BD_FEP5PLUS) {
u16 hflow2 = 0;
if (ch->ch_digi.digi_flags & DIGI_RTS_TOGGLE)
hflow2 |= (D_RTS(ch));
if (ch->ch_digi.digi_flags & DIGI_DTR_TOGGLE)
hflow2 |= (D_DTR(ch));
dgap_cmdw_ext(ch, 0xff03, hflow2, 0);
}
mval ^= ch->ch_mforce & (mval ^ ch->ch_mval);
if (ch->ch_mostat ^ mval) {
ch->ch_mostat = mval;
dgap_cmdb(ch, SMODEM, (u8) mval, D_RTS(ch)|D_DTR(ch), 0);
}
ch->ch_mistat = readb(&(ch->ch_bs->m_stat));
dgap_carrier(ch);
if (ch->ch_startc != ch->ch_fepstartc ||
ch->ch_stopc != ch->ch_fepstopc) {
ch->ch_fepstartc = ch->ch_startc;
ch->ch_fepstopc = ch->ch_stopc;
dgap_cmdb(ch, SFLOWC, ch->ch_fepstartc, ch->ch_fepstopc, 0);
}
if (ch->ch_astartc != ch->ch_fepastartc ||
ch->ch_astopc != ch->ch_fepastopc) {
ch->ch_fepastartc = ch->ch_astartc;
ch->ch_fepastopc = ch->ch_astopc;
dgap_cmdb(ch, SAFLOWC, ch->ch_fepastartc, ch->ch_fepastopc, 0);
}
return 0;
}
static int dgap_block_til_ready(struct tty_struct *tty, struct file *file,
struct channel_t *ch)
{
int retval = 0;
struct un_t *un;
ulong lock_flags;
uint old_flags;
int sleep_on_un_flags;
if (!tty || tty->magic != TTY_MAGIC || !file || !ch ||
ch->magic != DGAP_CHANNEL_MAGIC)
return -EIO;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return -EIO;
spin_lock_irqsave(&ch->ch_lock, lock_flags);
ch->ch_wopen++;
while (1) {
sleep_on_un_flags = 0;
if (ch->ch_bd->state == BOARD_FAILED) {
retval = -EIO;
break;
}
if (tty_hung_up_p(file)) {
retval = -EAGAIN;
break;
}
if (!((ch->ch_tun.un_flags | ch->ch_pun.un_flags) &
UN_CLOSING)) {
if (file->f_flags & O_NONBLOCK)
break;
if (tty->flags & (1 << TTY_IO_ERROR))
break;
if (ch->ch_flags & CH_CD)
break;
if (ch->ch_flags & CH_FCAR)
break;
} else {
sleep_on_un_flags = 1;
}
if (signal_pending(current)) {
retval = -ERESTARTSYS;
break;
}
if (sleep_on_un_flags)
old_flags = ch->ch_tun.un_flags | ch->ch_pun.un_flags;
else
old_flags = ch->ch_flags;
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
if (sleep_on_un_flags) {
retval = wait_event_interruptible(un->un_flags_wait,
(old_flags != (ch->ch_tun.un_flags |
ch->ch_pun.un_flags)));
} else {
retval = wait_event_interruptible(ch->ch_flags_wait,
(old_flags != ch->ch_flags));
}
spin_lock_irqsave(&ch->ch_lock, lock_flags);
}
ch->ch_wopen--;
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
return retval;
}
static void dgap_tty_flush_buffer(struct tty_struct *tty)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
u16 head;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
ch->ch_flags &= ~CH_STOP;
head = readw(&(ch->ch_bs->tx_head));
dgap_cmdw(ch, FLUSHTX, (u16) head, 0);
dgap_cmdw(ch, RESUMETX, 0, 0);
if (ch->ch_tun.un_flags & (UN_LOW|UN_EMPTY)) {
ch->ch_tun.un_flags &= ~(UN_LOW|UN_EMPTY);
wake_up_interruptible(&ch->ch_tun.un_flags_wait);
}
if (ch->ch_pun.un_flags & (UN_LOW|UN_EMPTY)) {
ch->ch_pun.un_flags &= ~(UN_LOW|UN_EMPTY);
wake_up_interruptible(&ch->ch_pun.un_flags_wait);
}
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
if (waitqueue_active(&tty->write_wait))
wake_up_interruptible(&tty->write_wait);
tty_wakeup(tty);
}
static void dgap_tty_hangup(struct tty_struct *tty)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
dgap_tty_flush_buffer(tty);
}
static int dgap_tty_chars_in_buffer(struct tty_struct *tty)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
struct bs_t __iomem *bs;
u8 tbusy;
uint chars;
u16 thead, ttail, tmask, chead, ctail;
ulong lock_flags = 0;
ulong lock_flags2 = 0;
if (!tty)
return 0;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return 0;
bs = ch->ch_bs;
if (!bs)
return 0;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
tmask = (ch->ch_tsize - 1);
thead = readw(&(bs->tx_head)) & tmask;
ttail = readw(&(bs->tx_tail)) & tmask;
tbusy = readb(&(bs->tbusy));
chead = readw(&(ch->ch_cm->cm_head));
ctail = readw(&(ch->ch_cm->cm_tail));
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
if ((ttail == thead) && (tbusy == 0) && (chead == ctail)) {
chars = 0;
} else {
if (thead >= ttail)
chars = thead - ttail;
else
chars = thead - ttail + ch->ch_tsize;
if (chars == 0) {
if (tbusy != 0) {
spin_lock_irqsave(&ch->ch_lock, lock_flags);
un->un_flags |= UN_EMPTY;
writeb(1, &(bs->iempty));
spin_unlock_irqrestore(&ch->ch_lock,
lock_flags);
}
chars = 1;
}
}
return chars;
}
static int dgap_wait_for_drain(struct tty_struct *tty)
{
struct channel_t *ch;
struct un_t *un;
struct bs_t __iomem *bs;
int ret = 0;
uint count = 1;
ulong lock_flags = 0;
if (!tty || tty->magic != TTY_MAGIC)
return -EIO;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return -EIO;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return -EIO;
bs = ch->ch_bs;
if (!bs)
return -EIO;
while (count != 0) {
count = dgap_tty_chars_in_buffer(tty);
if (count == 0)
break;
spin_lock_irqsave(&ch->ch_lock, lock_flags);
un->un_flags |= UN_EMPTY;
writeb(1, &(bs->iempty));
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
ret = wait_event_interruptible(un->un_flags_wait,
((un->un_flags & UN_EMPTY) == 0));
if (ret)
break;
}
spin_lock_irqsave(&ch->ch_lock, lock_flags);
un->un_flags &= ~(UN_EMPTY);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
return ret;
}
static int dgap_maxcps_room(struct channel_t *ch, struct un_t *un,
int bytes_available)
{
if (un->un_type != DGAP_PRINT)
return bytes_available;
if (ch->ch_digi.digi_maxcps > 0 && ch->ch_digi.digi_bufsize > 0) {
int cps_limit = 0;
unsigned long current_time = jiffies;
unsigned long buffer_time = current_time +
(HZ * ch->ch_digi.digi_bufsize) /
ch->ch_digi.digi_maxcps;
if (ch->ch_cpstime < current_time) {
ch->ch_cpstime = current_time;
cps_limit = ch->ch_digi.digi_bufsize;
} else if (ch->ch_cpstime < buffer_time) {
cps_limit = ((buffer_time - ch->ch_cpstime) *
ch->ch_digi.digi_maxcps) / HZ;
} else {
cps_limit = 0;
}
bytes_available = min(cps_limit, bytes_available);
}
return bytes_available;
}
static inline void dgap_set_firmware_event(struct un_t *un, unsigned int event)
{
struct channel_t *ch;
struct bs_t __iomem *bs;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bs = ch->ch_bs;
if (!bs)
return;
if ((event & UN_LOW) != 0) {
if ((un->un_flags & UN_LOW) == 0) {
un->un_flags |= UN_LOW;
writeb(1, &(bs->ilow));
}
}
if ((event & UN_LOW) != 0) {
if ((un->un_flags & UN_EMPTY) == 0) {
un->un_flags |= UN_EMPTY;
writeb(1, &(bs->iempty));
}
}
}
static int dgap_tty_write_room(struct tty_struct *tty)
{
struct channel_t *ch;
struct un_t *un;
struct bs_t __iomem *bs;
u16 head, tail, tmask;
int ret;
ulong lock_flags = 0;
if (!tty)
return 0;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return 0;
bs = ch->ch_bs;
if (!bs)
return 0;
spin_lock_irqsave(&ch->ch_lock, lock_flags);
tmask = ch->ch_tsize - 1;
head = readw(&(bs->tx_head)) & tmask;
tail = readw(&(bs->tx_tail)) & tmask;
ret = tail - head - 1;
if (ret < 0)
ret += ch->ch_tsize;
ret = dgap_maxcps_room(ch, un, ret);
if (un->un_type == DGAP_PRINT) {
if (!(ch->ch_flags & CH_PRON))
ret -= ch->ch_digi.digi_onlen;
ret -= ch->ch_digi.digi_offlen;
} else {
if (ch->ch_flags & CH_PRON)
ret -= ch->ch_digi.digi_offlen;
}
if (ret < 0)
ret = 0;
dgap_set_firmware_event(un, UN_LOW | UN_EMPTY);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
return ret;
}
static int dgap_tty_write(struct tty_struct *tty, const unsigned char *buf,
int count)
{
struct channel_t *ch;
struct un_t *un;
struct bs_t __iomem *bs;
char __iomem *vaddr;
u16 head, tail, tmask, remain;
int bufcount, n;
ulong lock_flags;
if (!tty)
return 0;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return 0;
bs = ch->ch_bs;
if (!bs)
return 0;
if (!count)
return 0;
spin_lock_irqsave(&ch->ch_lock, lock_flags);
tmask = ch->ch_tsize - 1;
head = readw(&(bs->tx_head)) & tmask;
tail = readw(&(bs->tx_tail)) & tmask;
bufcount = tail - head - 1;
if (bufcount < 0)
bufcount += ch->ch_tsize;
bufcount = dgap_maxcps_room(ch, un, bufcount);
count = min(count, bufcount);
if (count <= 0) {
dgap_set_firmware_event(un, UN_LOW | UN_EMPTY);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
return 0;
}
if ((un->un_type == DGAP_PRINT) && !(ch->ch_flags & CH_PRON)) {
dgap_wmove(ch, ch->ch_digi.digi_onstr,
(int) ch->ch_digi.digi_onlen);
head = readw(&(bs->tx_head)) & tmask;
ch->ch_flags |= CH_PRON;
}
if ((un->un_type != DGAP_PRINT) && (ch->ch_flags & CH_PRON)) {
dgap_wmove(ch, ch->ch_digi.digi_offstr,
(int) ch->ch_digi.digi_offlen);
head = readw(&(bs->tx_head)) & tmask;
ch->ch_flags &= ~CH_PRON;
}
n = count;
remain = ch->ch_tstart + ch->ch_tsize - head;
if (n >= remain) {
n -= remain;
vaddr = ch->ch_taddr + head;
memcpy_toio(vaddr, (u8 *) buf, remain);
head = ch->ch_tstart;
buf += remain;
}
if (n > 0) {
vaddr = ch->ch_taddr + head;
remain = n;
memcpy_toio(vaddr, (u8 *) buf, remain);
head += remain;
}
if (count) {
ch->ch_txcount += count;
head &= tmask;
writew(head, &(bs->tx_head));
}
dgap_set_firmware_event(un, UN_LOW | UN_EMPTY);
if ((un->un_type == DGAP_PRINT) && (ch->ch_flags & CH_PRON)) {
tail = readw(&(bs->tx_tail)) & tmask;
if (tail != head) {
un->un_flags |= UN_EMPTY;
writeb(1, &(bs->iempty));
} else {
dgap_wmove(ch, ch->ch_digi.digi_offstr,
(int) ch->ch_digi.digi_offlen);
head = readw(&(bs->tx_head)) & tmask;
ch->ch_flags &= ~CH_PRON;
}
}
if ((un->un_type == DGAP_PRINT) && (ch->ch_digi.digi_maxcps > 0)
&& (ch->ch_digi.digi_bufsize > 0)) {
ch->ch_cpstime += (HZ * count) / ch->ch_digi.digi_maxcps;
}
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
return count;
}
static int dgap_tty_put_char(struct tty_struct *tty, unsigned char c)
{
dgap_tty_write(tty, &c, 1);
return 1;
}
static int dgap_tty_tiocmget(struct tty_struct *tty)
{
struct channel_t *ch;
struct un_t *un;
int result;
u8 mstat;
ulong lock_flags;
if (!tty || tty->magic != TTY_MAGIC)
return -EIO;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return -EIO;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return -EIO;
spin_lock_irqsave(&ch->ch_lock, lock_flags);
mstat = readb(&(ch->ch_bs->m_stat));
mstat |= ch->ch_mostat;
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
result = 0;
if (mstat & D_DTR(ch))
result |= TIOCM_DTR;
if (mstat & D_RTS(ch))
result |= TIOCM_RTS;
if (mstat & D_CTS(ch))
result |= TIOCM_CTS;
if (mstat & D_DSR(ch))
result |= TIOCM_DSR;
if (mstat & D_RI(ch))
result |= TIOCM_RI;
if (mstat & D_CD(ch))
result |= TIOCM_CD;
return result;
}
static int dgap_tty_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return -EIO;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return -EIO;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return -EIO;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return -EIO;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
if (set & TIOCM_RTS) {
ch->ch_mforce |= D_RTS(ch);
ch->ch_mval |= D_RTS(ch);
}
if (set & TIOCM_DTR) {
ch->ch_mforce |= D_DTR(ch);
ch->ch_mval |= D_DTR(ch);
}
if (clear & TIOCM_RTS) {
ch->ch_mforce |= D_RTS(ch);
ch->ch_mval &= ~(D_RTS(ch));
}
if (clear & TIOCM_DTR) {
ch->ch_mforce |= D_DTR(ch);
ch->ch_mval &= ~(D_DTR(ch));
}
dgap_param(ch, bd, un->un_type);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return 0;
}
static int dgap_tty_send_break(struct tty_struct *tty, int msec)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return -EIO;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return -EIO;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return -EIO;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return -EIO;
switch (msec) {
case -1:
msec = 0xFFFF;
break;
case 0:
msec = 1;
break;
default:
msec /= 10;
break;
}
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
#if 0
dgap_cmdw(ch, SBREAK, (u16) SBREAK_TIME, 0);
#endif
dgap_cmdw(ch, SBREAK, (u16) msec, 0);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return 0;
}
static void dgap_tty_wait_until_sent(struct tty_struct *tty, int timeout)
{
dgap_wait_for_drain(tty);
}
static void dgap_tty_send_xchar(struct tty_struct *tty, char c)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
#if 0
if (c == STOP_CHAR(tty))
dgap_cmdw(ch, RPAUSE, 0, 0);
else if (c == START_CHAR(tty))
dgap_cmdw(ch, RRESUME, 0, 0);
else
dgap_wmove(ch, &c, 1);
#else
dgap_wmove(ch, &c, 1);
#endif
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
}
static int dgap_get_modem_info(struct channel_t *ch, unsigned int __user *value)
{
int result;
u8 mstat;
ulong lock_flags;
spin_lock_irqsave(&ch->ch_lock, lock_flags);
mstat = readb(&(ch->ch_bs->m_stat));
mstat |= ch->ch_mostat;
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
result = 0;
if (mstat & D_DTR(ch))
result |= TIOCM_DTR;
if (mstat & D_RTS(ch))
result |= TIOCM_RTS;
if (mstat & D_CTS(ch))
result |= TIOCM_CTS;
if (mstat & D_DSR(ch))
result |= TIOCM_DSR;
if (mstat & D_RI(ch))
result |= TIOCM_RI;
if (mstat & D_CD(ch))
result |= TIOCM_CD;
return put_user(result, value);
}
static int dgap_set_modem_info(struct channel_t *ch, struct board_t *bd,
struct un_t *un, unsigned int command,
unsigned int __user *value)
{
int ret;
unsigned int arg;
ulong lock_flags;
ulong lock_flags2;
ret = get_user(arg, value);
if (ret)
return ret;
switch (command) {
case TIOCMBIS:
if (arg & TIOCM_RTS) {
ch->ch_mforce |= D_RTS(ch);
ch->ch_mval |= D_RTS(ch);
}
if (arg & TIOCM_DTR) {
ch->ch_mforce |= D_DTR(ch);
ch->ch_mval |= D_DTR(ch);
}
break;
case TIOCMBIC:
if (arg & TIOCM_RTS) {
ch->ch_mforce |= D_RTS(ch);
ch->ch_mval &= ~(D_RTS(ch));
}
if (arg & TIOCM_DTR) {
ch->ch_mforce |= D_DTR(ch);
ch->ch_mval &= ~(D_DTR(ch));
}
break;
case TIOCMSET:
ch->ch_mforce = D_DTR(ch)|D_RTS(ch);
if (arg & TIOCM_RTS)
ch->ch_mval |= D_RTS(ch);
else
ch->ch_mval &= ~(D_RTS(ch));
if (arg & TIOCM_DTR)
ch->ch_mval |= (D_DTR(ch));
else
ch->ch_mval &= ~(D_DTR(ch));
break;
default:
return -EINVAL;
}
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
dgap_param(ch, bd, un->un_type);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return 0;
}
static int dgap_tty_digigeta(struct channel_t *ch,
struct digi_t __user *retinfo)
{
struct digi_t tmp;
ulong lock_flags;
if (!retinfo)
return -EFAULT;
memset(&tmp, 0, sizeof(tmp));
spin_lock_irqsave(&ch->ch_lock, lock_flags);
memcpy(&tmp, &ch->ch_digi, sizeof(tmp));
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
if (copy_to_user(retinfo, &tmp, sizeof(*retinfo)))
return -EFAULT;
return 0;
}
static int dgap_tty_digiseta(struct channel_t *ch, struct board_t *bd,
struct un_t *un, struct digi_t __user *new_info)
{
struct digi_t new_digi;
ulong lock_flags = 0;
unsigned long lock_flags2;
if (copy_from_user(&new_digi, new_info, sizeof(struct digi_t)))
return -EFAULT;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
memcpy(&ch->ch_digi, &new_digi, sizeof(struct digi_t));
if (ch->ch_digi.digi_maxcps < 1)
ch->ch_digi.digi_maxcps = 1;
if (ch->ch_digi.digi_maxcps > 10000)
ch->ch_digi.digi_maxcps = 10000;
if (ch->ch_digi.digi_bufsize < 10)
ch->ch_digi.digi_bufsize = 10;
if (ch->ch_digi.digi_maxchar < 1)
ch->ch_digi.digi_maxchar = 1;
if (ch->ch_digi.digi_maxchar > ch->ch_digi.digi_bufsize)
ch->ch_digi.digi_maxchar = ch->ch_digi.digi_bufsize;
if (ch->ch_digi.digi_onlen > DIGI_PLEN)
ch->ch_digi.digi_onlen = DIGI_PLEN;
if (ch->ch_digi.digi_offlen > DIGI_PLEN)
ch->ch_digi.digi_offlen = DIGI_PLEN;
dgap_param(ch, bd, un->un_type);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return 0;
}
static int dgap_tty_digigetedelay(struct tty_struct *tty, int __user *retinfo)
{
struct channel_t *ch;
struct un_t *un;
int tmp;
ulong lock_flags;
if (!retinfo)
return -EFAULT;
if (!tty || tty->magic != TTY_MAGIC)
return -EFAULT;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return -EFAULT;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return -EFAULT;
memset(&tmp, 0, sizeof(tmp));
spin_lock_irqsave(&ch->ch_lock, lock_flags);
tmp = readw(&(ch->ch_bs->edelay));
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
if (copy_to_user(retinfo, &tmp, sizeof(*retinfo)))
return -EFAULT;
return 0;
}
static int dgap_tty_digisetedelay(struct channel_t *ch, struct board_t *bd,
struct un_t *un, int __user *new_info)
{
int new_digi;
ulong lock_flags;
ulong lock_flags2;
if (copy_from_user(&new_digi, new_info, sizeof(int)))
return -EFAULT;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
writew((u16) new_digi, &(ch->ch_bs->edelay));
dgap_param(ch, bd, un->un_type);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return 0;
}
static int dgap_tty_digigetcustombaud(struct channel_t *ch, struct un_t *un,
int __user *retinfo)
{
int tmp;
ulong lock_flags;
if (!retinfo)
return -EFAULT;
memset(&tmp, 0, sizeof(tmp));
spin_lock_irqsave(&ch->ch_lock, lock_flags);
tmp = dgap_get_custom_baud(ch);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
if (copy_to_user(retinfo, &tmp, sizeof(*retinfo)))
return -EFAULT;
return 0;
}
static int dgap_tty_digisetcustombaud(struct channel_t *ch, struct board_t *bd,
struct un_t *un, int __user *new_info)
{
uint new_rate;
ulong lock_flags;
ulong lock_flags2;
if (copy_from_user(&new_rate, new_info, sizeof(unsigned int)))
return -EFAULT;
if (bd->bd_flags & BD_FEP5PLUS) {
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
ch->ch_custom_speed = new_rate;
dgap_param(ch, bd, un->un_type);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
}
return 0;
}
static void dgap_tty_set_termios(struct tty_struct *tty,
struct ktermios *old_termios)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
unsigned long lock_flags;
unsigned long lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
ch->ch_c_cflag = tty->termios.c_cflag;
ch->ch_c_iflag = tty->termios.c_iflag;
ch->ch_c_oflag = tty->termios.c_oflag;
ch->ch_c_lflag = tty->termios.c_lflag;
ch->ch_startc = tty->termios.c_cc[VSTART];
ch->ch_stopc = tty->termios.c_cc[VSTOP];
dgap_carrier(ch);
dgap_param(ch, bd, un->un_type);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
}
static void dgap_tty_throttle(struct tty_struct *tty)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
ch->ch_flags |= (CH_RXBLOCK);
#if 1
dgap_cmdw(ch, RPAUSE, 0, 0);
#endif
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
}
static void dgap_tty_unthrottle(struct tty_struct *tty)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
ch->ch_flags &= ~(CH_RXBLOCK);
#if 1
dgap_cmdw(ch, RRESUME, 0, 0);
#endif
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
}
static struct board_t *find_board_by_major(unsigned int major)
{
unsigned int i;
for (i = 0; i < MAXBOARDS; i++) {
struct board_t *brd = dgap_board[i];
if (!brd)
return NULL;
if (major == brd->serial_driver->major ||
major == brd->print_driver->major)
return brd;
}
return NULL;
}
static int dgap_tty_open(struct tty_struct *tty, struct file *file)
{
struct board_t *brd;
struct channel_t *ch;
struct un_t *un;
struct bs_t __iomem *bs;
uint major;
uint minor;
int rc;
ulong lock_flags;
ulong lock_flags2;
u16 head;
major = MAJOR(tty_devnum(tty));
minor = MINOR(tty_devnum(tty));
brd = find_board_by_major(major);
if (!brd)
return -EIO;
rc = wait_event_interruptible(brd->state_wait,
(brd->state & BOARD_READY));
if (rc)
return rc;
spin_lock_irqsave(&brd->bd_lock, lock_flags);
if (brd->state != BOARD_READY) {
spin_unlock_irqrestore(&brd->bd_lock, lock_flags);
return -EIO;
}
if (MINOR(tty_devnum(tty)) > brd->nasync) {
spin_unlock_irqrestore(&brd->bd_lock, lock_flags);
return -EIO;
}
ch = brd->channels[minor];
if (!ch) {
spin_unlock_irqrestore(&brd->bd_lock, lock_flags);
return -EIO;
}
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
if (major == brd->serial_driver->major) {
un = &brd->channels[minor]->ch_tun;
un->un_type = DGAP_SERIAL;
} else if (major == brd->print_driver->major) {
un = &brd->channels[minor]->ch_pun;
un->un_type = DGAP_PRINT;
} else {
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&brd->bd_lock, lock_flags);
return -EIO;
}
tty->driver_data = un;
bs = ch->ch_bs;
if (!bs) {
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&brd->bd_lock, lock_flags);
return -EIO;
}
if (!(un->un_flags & UN_ISOPEN)) {
un->un_tty = tty;
}
if (!((ch->ch_tun.un_flags | ch->ch_pun.un_flags) & UN_ISOPEN)) {
ch->ch_mforce = 0;
ch->ch_mval = 0;
head = readw(&(bs->rx_head));
writew(head, &(bs->rx_tail));
ch->ch_flags = 0;
ch->pscan_state = 0;
ch->pscan_savechar = 0;
ch->ch_c_cflag = tty->termios.c_cflag;
ch->ch_c_iflag = tty->termios.c_iflag;
ch->ch_c_oflag = tty->termios.c_oflag;
ch->ch_c_lflag = tty->termios.c_lflag;
ch->ch_startc = tty->termios.c_cc[VSTART];
ch->ch_stopc = tty->termios.c_cc[VSTOP];
}
dgap_carrier(ch);
dgap_param(ch, brd, un->un_type);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&brd->bd_lock, lock_flags);
rc = dgap_block_til_ready(tty, file, ch);
if (!un->un_tty)
return -ENODEV;
spin_lock_irqsave(&ch->ch_lock, lock_flags);
ch->ch_open_count++;
un->un_open_count++;
un->un_flags |= (UN_ISOPEN);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
return rc;
}
static void dgap_tty_close(struct tty_struct *tty, struct file *file)
{
struct ktermios *ts;
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
ts = &tty->termios;
spin_lock_irqsave(&ch->ch_lock, lock_flags);
if ((tty->count == 1) && (un->un_open_count != 1)) {
un->un_open_count = 1;
}
if (--un->un_open_count < 0)
un->un_open_count = 0;
ch->ch_open_count--;
if (ch->ch_open_count && un->un_open_count) {
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
return;
}
un->un_flags |= UN_CLOSING;
tty->closing = 1;
if ((ch->ch_open_count == 0) &&
!(ch->ch_digi.digi_flags & DIGI_PRINTER)) {
ch->ch_flags &= ~(CH_RXBLOCK);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
dgap_wait_for_drain(tty);
dgap_tty_flush_buffer(tty);
tty_ldisc_flush(tty);
spin_lock_irqsave(&ch->ch_lock, lock_flags);
tty->closing = 0;
if (ch->ch_c_cflag & HUPCL) {
ch->ch_mostat &= ~(D_RTS(ch)|D_DTR(ch));
dgap_cmdb(ch, SMODEM, 0, D_DTR(ch)|D_RTS(ch), 0);
spin_unlock_irqrestore(&ch->ch_lock,
lock_flags);
schedule_timeout_interruptible(msecs_to_jiffies(250));
spin_lock_irqsave(&ch->ch_lock, lock_flags);
}
ch->pscan_state = 0;
ch->pscan_savechar = 0;
ch->ch_baud_info = 0;
}
if ((un->un_type == DGAP_PRINT) && (ch->ch_flags & CH_PRON)) {
dgap_wmove(ch, ch->ch_digi.digi_offstr,
(int) ch->ch_digi.digi_offlen);
ch->ch_flags &= ~CH_PRON;
}
un->un_tty = NULL;
un->un_flags &= ~(UN_ISOPEN | UN_CLOSING);
tty->driver_data = NULL;
wake_up_interruptible(&ch->ch_flags_wait);
wake_up_interruptible(&un->un_flags_wait);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
}
static void dgap_tty_start(struct tty_struct *tty)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
dgap_cmdw(ch, RESUMETX, 0, 0);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
}
static void dgap_tty_stop(struct tty_struct *tty)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
dgap_cmdw(ch, PAUSETX, 0, 0);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
}
static void dgap_tty_flush_chars(struct tty_struct *tty)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
}
static int dgap_tty_ioctl(struct tty_struct *tty, unsigned int cmd,
unsigned long arg)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
int rc;
u16 head;
ulong lock_flags = 0;
ulong lock_flags2 = 0;
void __user *uarg = (void __user *) arg;
if (!tty || tty->magic != TTY_MAGIC)
return -ENODEV;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return -ENODEV;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return -ENODEV;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return -ENODEV;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
if (un->un_open_count <= 0) {
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return -EIO;
}
switch (cmd) {
case TCSBRK:
rc = tty_check_change(tty);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
if (rc)
return rc;
rc = dgap_wait_for_drain(tty);
if (rc)
return -EINTR;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
if (((cmd == TCSBRK) && (!arg)) || (cmd == TCSBRKP))
dgap_cmdw(ch, SBREAK, (u16) SBREAK_TIME, 0);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return 0;
case TCSBRKP:
rc = tty_check_change(tty);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
if (rc)
return rc;
rc = dgap_wait_for_drain(tty);
if (rc)
return -EINTR;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
dgap_cmdw(ch, SBREAK, (u16) SBREAK_TIME, 0);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return 0;
case TIOCSBRK:
rc = tty_check_change(tty);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
if (rc)
return rc;
rc = dgap_wait_for_drain(tty);
if (rc)
return -EINTR;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
dgap_cmdw(ch, SBREAK, (u16) SBREAK_TIME, 0);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return 0;
case TIOCCBRK:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return 0;
case TIOCGSOFTCAR:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
rc = put_user(C_CLOCAL(tty) ? 1 : 0,
(unsigned long __user *) arg);
return rc;
case TIOCSSOFTCAR:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
rc = get_user(arg, (unsigned long __user *) arg);
if (rc)
return rc;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
tty->termios.c_cflag = ((tty->termios.c_cflag & ~CLOCAL) |
(arg ? CLOCAL : 0));
dgap_param(ch, bd, un->un_type);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return 0;
case TIOCMGET:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return dgap_get_modem_info(ch, uarg);
case TIOCMBIS:
case TIOCMBIC:
case TIOCMSET:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return dgap_set_modem_info(ch, bd, un, cmd, uarg);
case TCFLSH:
rc = tty_check_change(tty);
if (rc) {
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return rc;
}
if ((arg == TCIFLUSH) || (arg == TCIOFLUSH)) {
if (!(un->un_type == DGAP_PRINT)) {
head = readw(&(ch->ch_bs->rx_head));
writew(head, &(ch->ch_bs->rx_tail));
writeb(0, &(ch->ch_bs->orun));
}
}
if ((arg != TCOFLUSH) && (arg != TCIOFLUSH)) {
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return -ENOIOCTLCMD;
}
ch->ch_flags &= ~CH_STOP;
head = readw(&(ch->ch_bs->tx_head));
dgap_cmdw(ch, FLUSHTX, (u16) head, 0);
dgap_cmdw(ch, RESUMETX, 0, 0);
if (ch->ch_tun.un_flags & (UN_LOW|UN_EMPTY)) {
ch->ch_tun.un_flags &= ~(UN_LOW|UN_EMPTY);
wake_up_interruptible(&ch->ch_tun.un_flags_wait);
}
if (ch->ch_pun.un_flags & (UN_LOW|UN_EMPTY)) {
ch->ch_pun.un_flags &= ~(UN_LOW|UN_EMPTY);
wake_up_interruptible(&ch->ch_pun.un_flags_wait);
}
if (waitqueue_active(&tty->write_wait))
wake_up_interruptible(&tty->write_wait);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
tty_wakeup(tty);
return -ENOIOCTLCMD;
case TCSETSF:
case TCSETSW:
if (cmd == TCSETSF) {
ch->ch_flags &= ~CH_STOP;
head = readw(&(ch->ch_bs->rx_head));
writew(head, &(ch->ch_bs->rx_tail));
}
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
rc = dgap_wait_for_drain(tty);
if (rc)
return -EINTR;
return -ENOIOCTLCMD;
case TCSETAW:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
rc = dgap_wait_for_drain(tty);
if (rc)
return -EINTR;
return -ENOIOCTLCMD;
case TCXONC:
rc = tty_check_change(tty);
if (rc) {
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return rc;
}
switch (arg) {
case TCOON:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
dgap_tty_start(tty);
return 0;
case TCOOFF:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
dgap_tty_stop(tty);
return 0;
case TCION:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return -ENOIOCTLCMD;
case TCIOFF:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return -ENOIOCTLCMD;
default:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return -EINVAL;
}
case DIGI_GETA:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return dgap_tty_digigeta(ch, uarg);
case DIGI_SETAW:
case DIGI_SETAF:
if (cmd == (DIGI_SETAW)) {
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
rc = dgap_wait_for_drain(tty);
if (rc)
return -EINTR;
spin_lock_irqsave(&bd->bd_lock, lock_flags);
spin_lock_irqsave(&ch->ch_lock, lock_flags2);
} else
tty_ldisc_flush(tty);
case DIGI_SETA:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return dgap_tty_digiseta(ch, bd, un, uarg);
case DIGI_GEDELAY:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return dgap_tty_digigetedelay(tty, uarg);
case DIGI_SEDELAY:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return dgap_tty_digisetedelay(ch, bd, un, uarg);
case DIGI_GETCUSTOMBAUD:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return dgap_tty_digigetcustombaud(ch, un, uarg);
case DIGI_SETCUSTOMBAUD:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return dgap_tty_digisetcustombaud(ch, bd, un, uarg);
case DIGI_RESET_PORT:
dgap_firmware_reset_port(ch);
dgap_param(ch, bd, un->un_type);
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return 0;
default:
spin_unlock_irqrestore(&ch->ch_lock, lock_flags2);
spin_unlock_irqrestore(&bd->bd_lock, lock_flags);
return -ENOIOCTLCMD;
}
}
static int dgap_tty_register(struct board_t *brd)
{
int rc;
brd->serial_driver = tty_alloc_driver(MAXPORTS,
TTY_DRIVER_REAL_RAW |
TTY_DRIVER_DYNAMIC_DEV |
TTY_DRIVER_HARDWARE_BREAK);
if (IS_ERR(brd->serial_driver))
return PTR_ERR(brd->serial_driver);
snprintf(brd->serial_name, MAXTTYNAMELEN, "tty_dgap_%d_",
brd->boardnum);
brd->serial_driver->name = brd->serial_name;
brd->serial_driver->name_base = 0;
brd->serial_driver->major = 0;
brd->serial_driver->minor_start = 0;
brd->serial_driver->type = TTY_DRIVER_TYPE_SERIAL;
brd->serial_driver->subtype = SERIAL_TYPE_NORMAL;
brd->serial_driver->init_termios = dgap_default_termios;
brd->serial_driver->driver_name = DRVSTR;
tty_set_operations(brd->serial_driver, &dgap_tty_ops);
brd->print_driver = tty_alloc_driver(MAXPORTS,
TTY_DRIVER_REAL_RAW |
TTY_DRIVER_DYNAMIC_DEV |
TTY_DRIVER_HARDWARE_BREAK);
if (IS_ERR(brd->print_driver)) {
rc = PTR_ERR(brd->print_driver);
goto free_serial_drv;
}
snprintf(brd->print_name, MAXTTYNAMELEN, "pr_dgap_%d_",
brd->boardnum);
brd->print_driver->name = brd->print_name;
brd->print_driver->name_base = 0;
brd->print_driver->major = 0;
brd->print_driver->minor_start = 0;
brd->print_driver->type = TTY_DRIVER_TYPE_SERIAL;
brd->print_driver->subtype = SERIAL_TYPE_NORMAL;
brd->print_driver->init_termios = dgap_default_termios;
brd->print_driver->driver_name = DRVSTR;
tty_set_operations(brd->print_driver, &dgap_tty_ops);
rc = tty_register_driver(brd->serial_driver);
if (rc < 0)
goto free_print_drv;
rc = tty_register_driver(brd->print_driver);
if (rc < 0)
goto unregister_serial_drv;
return 0;
unregister_serial_drv:
tty_unregister_driver(brd->serial_driver);
free_print_drv:
put_tty_driver(brd->print_driver);
free_serial_drv:
put_tty_driver(brd->serial_driver);
return rc;
}
static void dgap_tty_unregister(struct board_t *brd)
{
tty_unregister_driver(brd->print_driver);
tty_unregister_driver(brd->serial_driver);
put_tty_driver(brd->print_driver);
put_tty_driver(brd->serial_driver);
}
static int dgap_alloc_flipbuf(struct board_t *brd)
{
brd->flipbuf = kmalloc(MYFLIPLEN, GFP_KERNEL);
if (!brd->flipbuf)
return -ENOMEM;
brd->flipflagbuf = kmalloc(MYFLIPLEN, GFP_KERNEL);
if (!brd->flipflagbuf) {
kfree(brd->flipbuf);
return -ENOMEM;
}
return 0;
}
static void dgap_free_flipbuf(struct board_t *brd)
{
kfree(brd->flipbuf);
kfree(brd->flipflagbuf);
}
static struct board_t *dgap_verify_board(struct device *p)
{
struct board_t *bd;
if (!p)
return NULL;
bd = dev_get_drvdata(p);
if (!bd || bd->magic != DGAP_BOARD_MAGIC || bd->state != BOARD_READY)
return NULL;
return bd;
}
static ssize_t dgap_ports_state_show(struct device *p,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
int count = 0;
unsigned int i;
bd = dgap_verify_board(p);
if (!bd)
return 0;
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count,
"%d %s\n", bd->channels[i]->ch_portnum,
bd->channels[i]->ch_open_count ? "Open" : "Closed");
}
return count;
}
static ssize_t dgap_ports_baud_show(struct device *p,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
int count = 0;
unsigned int i;
bd = dgap_verify_board(p);
if (!bd)
return 0;
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count, "%d %d\n",
bd->channels[i]->ch_portnum,
bd->channels[i]->ch_baud_info);
}
return count;
}
static ssize_t dgap_ports_msignals_show(struct device *p,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
int count = 0;
unsigned int i;
bd = dgap_verify_board(p);
if (!bd)
return 0;
for (i = 0; i < bd->nasync; i++) {
if (bd->channels[i]->ch_open_count)
count += snprintf(buf + count, PAGE_SIZE - count,
"%d %s %s %s %s %s %s\n",
bd->channels[i]->ch_portnum,
(bd->channels[i]->ch_mostat &
UART_MCR_RTS) ? "RTS" : "",
(bd->channels[i]->ch_mistat &
UART_MSR_CTS) ? "CTS" : "",
(bd->channels[i]->ch_mostat &
UART_MCR_DTR) ? "DTR" : "",
(bd->channels[i]->ch_mistat &
UART_MSR_DSR) ? "DSR" : "",
(bd->channels[i]->ch_mistat &
UART_MSR_DCD) ? "DCD" : "",
(bd->channels[i]->ch_mistat &
UART_MSR_RI) ? "RI" : "");
else
count += snprintf(buf + count, PAGE_SIZE - count,
"%d\n", bd->channels[i]->ch_portnum);
}
return count;
}
static ssize_t dgap_ports_iflag_show(struct device *p,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
int count = 0;
unsigned int i;
bd = dgap_verify_board(p);
if (!bd)
return 0;
for (i = 0; i < bd->nasync; i++)
count += snprintf(buf + count, PAGE_SIZE - count, "%d %x\n",
bd->channels[i]->ch_portnum,
bd->channels[i]->ch_c_iflag);
return count;
}
static ssize_t dgap_ports_cflag_show(struct device *p,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
int count = 0;
unsigned int i;
bd = dgap_verify_board(p);
if (!bd)
return 0;
for (i = 0; i < bd->nasync; i++)
count += snprintf(buf + count, PAGE_SIZE - count, "%d %x\n",
bd->channels[i]->ch_portnum,
bd->channels[i]->ch_c_cflag);
return count;
}
static ssize_t dgap_ports_oflag_show(struct device *p,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
int count = 0;
unsigned int i;
bd = dgap_verify_board(p);
if (!bd)
return 0;
for (i = 0; i < bd->nasync; i++)
count += snprintf(buf + count, PAGE_SIZE - count, "%d %x\n",
bd->channels[i]->ch_portnum,
bd->channels[i]->ch_c_oflag);
return count;
}
static ssize_t dgap_ports_lflag_show(struct device *p,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
int count = 0;
unsigned int i;
bd = dgap_verify_board(p);
if (!bd)
return 0;
for (i = 0; i < bd->nasync; i++)
count += snprintf(buf + count, PAGE_SIZE - count, "%d %x\n",
bd->channels[i]->ch_portnum,
bd->channels[i]->ch_c_lflag);
return count;
}
static ssize_t dgap_ports_digi_flag_show(struct device *p,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
int count = 0;
unsigned int i;
bd = dgap_verify_board(p);
if (!bd)
return 0;
for (i = 0; i < bd->nasync; i++)
count += snprintf(buf + count, PAGE_SIZE - count, "%d %x\n",
bd->channels[i]->ch_portnum,
bd->channels[i]->ch_digi.digi_flags);
return count;
}
static ssize_t dgap_ports_rxcount_show(struct device *p,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
int count = 0;
unsigned int i;
bd = dgap_verify_board(p);
if (!bd)
return 0;
for (i = 0; i < bd->nasync; i++)
count += snprintf(buf + count, PAGE_SIZE - count, "%d %ld\n",
bd->channels[i]->ch_portnum,
bd->channels[i]->ch_rxcount);
return count;
}
static ssize_t dgap_ports_txcount_show(struct device *p,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
int count = 0;
unsigned int i;
bd = dgap_verify_board(p);
if (!bd)
return 0;
for (i = 0; i < bd->nasync; i++)
count += snprintf(buf + count, PAGE_SIZE - count, "%d %ld\n",
bd->channels[i]->ch_portnum,
bd->channels[i]->ch_txcount);
return count;
}
static ssize_t dgap_tty_state_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%s", un->un_open_count ?
"Open" : "Closed");
}
static ssize_t dgap_tty_baud_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%d\n", ch->ch_baud_info);
}
static ssize_t dgap_tty_msignals_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
if (ch->ch_open_count) {
return snprintf(buf, PAGE_SIZE, "%s %s %s %s %s %s\n",
(ch->ch_mostat & UART_MCR_RTS) ? "RTS" : "",
(ch->ch_mistat & UART_MSR_CTS) ? "CTS" : "",
(ch->ch_mostat & UART_MCR_DTR) ? "DTR" : "",
(ch->ch_mistat & UART_MSR_DSR) ? "DSR" : "",
(ch->ch_mistat & UART_MSR_DCD) ? "DCD" : "",
(ch->ch_mistat & UART_MSR_RI) ? "RI" : "");
}
return 0;
}
static ssize_t dgap_tty_iflag_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%x\n", ch->ch_c_iflag);
}
static ssize_t dgap_tty_cflag_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%x\n", ch->ch_c_cflag);
}
static ssize_t dgap_tty_oflag_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%x\n", ch->ch_c_oflag);
}
static ssize_t dgap_tty_lflag_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%x\n", ch->ch_c_lflag);
}
static ssize_t dgap_tty_digi_flag_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%x\n", ch->ch_digi.digi_flags);
}
static ssize_t dgap_tty_rxcount_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%ld\n", ch->ch_rxcount);
}
static ssize_t dgap_tty_txcount_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%ld\n", ch->ch_txcount);
}
static ssize_t dgap_tty_name_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
int cn;
int bn;
struct cnode *cptr;
int found = FALSE;
int ncount = 0;
int starto = 0;
int i;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
bn = bd->boardnum;
cn = ch->ch_portnum;
for (cptr = bd->bd_config; cptr; cptr = cptr->next) {
if ((cptr->type == BNODE) &&
((cptr->u.board.type == APORT2_920P) ||
(cptr->u.board.type == APORT4_920P) ||
(cptr->u.board.type == APORT8_920P) ||
(cptr->u.board.type == PAPORT4) ||
(cptr->u.board.type == PAPORT8))) {
found = TRUE;
if (cptr->u.board.v_start)
starto = cptr->u.board.start;
else
starto = 1;
}
if (cptr->type == TNODE && found == TRUE) {
char *ptr1;
if (strstr(cptr->u.ttyname, "tty")) {
ptr1 = cptr->u.ttyname;
ptr1 += 3;
} else
ptr1 = cptr->u.ttyname;
for (i = 0; i < dgap_config_get_num_prts(bd); i++) {
if (cn != i)
continue;
return snprintf(buf, PAGE_SIZE, "%s%s%02d\n",
(un->un_type == DGAP_PRINT) ?
"pr" : "tty",
ptr1, i + starto);
}
}
if (cptr->type == CNODE) {
for (i = 0; i < cptr->u.conc.nport; i++) {
if (cn != (i + ncount))
continue;
return snprintf(buf, PAGE_SIZE, "%s%s%02ld\n",
(un->un_type == DGAP_PRINT) ?
"pr" : "tty",
cptr->u.conc.id,
i + (cptr->u.conc.v_start ?
cptr->u.conc.start : 1));
}
ncount += cptr->u.conc.nport;
}
if (cptr->type == MNODE) {
for (i = 0; i < cptr->u.module.nport; i++) {
if (cn != (i + ncount))
continue;
return snprintf(buf, PAGE_SIZE, "%s%s%02ld\n",
(un->un_type == DGAP_PRINT) ?
"pr" : "tty",
cptr->u.module.id,
i + (cptr->u.module.v_start ?
cptr->u.module.start : 1));
}
ncount += cptr->u.module.nport;
}
}
return snprintf(buf, PAGE_SIZE, "%s_dgap_%d_%d\n",
(un->un_type == DGAP_PRINT) ? "pr" : "tty", bn, cn);
}
static void dgap_create_ports_sysfiles(struct board_t *bd)
{
dev_set_drvdata(&bd->pdev->dev, bd);
device_create_file(&(bd->pdev->dev), &dev_attr_ports_state);
device_create_file(&(bd->pdev->dev), &dev_attr_ports_baud);
device_create_file(&(bd->pdev->dev), &dev_attr_ports_msignals);
device_create_file(&(bd->pdev->dev), &dev_attr_ports_iflag);
device_create_file(&(bd->pdev->dev), &dev_attr_ports_cflag);
device_create_file(&(bd->pdev->dev), &dev_attr_ports_oflag);
device_create_file(&(bd->pdev->dev), &dev_attr_ports_lflag);
device_create_file(&(bd->pdev->dev), &dev_attr_ports_digi_flag);
device_create_file(&(bd->pdev->dev), &dev_attr_ports_rxcount);
device_create_file(&(bd->pdev->dev), &dev_attr_ports_txcount);
}
static void dgap_remove_ports_sysfiles(struct board_t *bd)
{
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_state);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_baud);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_msignals);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_iflag);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_cflag);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_oflag);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_lflag);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_digi_flag);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_rxcount);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_txcount);
}
static void dgap_do_bios_load(struct board_t *brd, const u8 *ubios, int len)
{
u8 __iomem *addr;
uint offset;
unsigned int i;
if (!brd || (brd->magic != DGAP_BOARD_MAGIC) || !brd->re_map_membase)
return;
addr = brd->re_map_membase;
for (i = 0; i < 16; i++)
writeb(0, addr + POSTAREA + i);
offset = 0x1000;
memcpy_toio(addr + offset, ubios, len);
writel(0x0bf00401, addr);
writel(0, (addr + 4));
writeb(FEPCLR, brd->re_map_port);
}
static int dgap_test_bios(struct board_t *brd)
{
u8 __iomem *addr;
u16 word;
u16 err1;
u16 err2;
if (!brd || (brd->magic != DGAP_BOARD_MAGIC) || !brd->re_map_membase)
return -EINVAL;
addr = brd->re_map_membase;
word = readw(addr + POSTAREA);
brd->wait_for_bios = 0;
while (brd->wait_for_bios < 1000) {
if (word == *(u16 *) "GD")
return 0;
msleep_interruptible(10);
brd->wait_for_bios++;
word = readw(addr + POSTAREA);
}
err1 = readw(addr + SEQUENCE);
err2 = readw(addr + ERROR);
dev_warn(&brd->pdev->dev, "%s failed diagnostics. Error #(%x,%x).\n",
brd->name, err1, err2);
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOBIOS;
return -EIO;
}
static void dgap_do_fep_load(struct board_t *brd, const u8 *ufep, int len)
{
u8 __iomem *addr;
uint offset;
if (!brd || (brd->magic != DGAP_BOARD_MAGIC) || !brd->re_map_membase)
return;
addr = brd->re_map_membase;
offset = 0x1000;
memcpy_toio(addr + offset, ufep, len);
if ((brd->type == PCX) || (brd->type == PEPC)) {
u8 string[100];
u8 __iomem *config;
u8 *xconfig;
unsigned int i = 0;
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
}
static int dgap_test_fep(struct board_t *brd)
{
u8 __iomem *addr;
u16 word;
u16 err1;
u16 err2;
if (!brd || (brd->magic != DGAP_BOARD_MAGIC) || !brd->re_map_membase)
return -EINVAL;
addr = brd->re_map_membase;
word = readw(addr + FEPSTAT);
brd->wait_for_fep = 0;
while (brd->wait_for_fep < 500) {
if (word == *(u16 *) "OS") {
word = readw(addr + FEP5_PLUS);
if (word == *(u16 *) "5A")
brd->bd_flags |= BD_FEP5PLUS;
return 0;
}
msleep_interruptible(10);
brd->wait_for_fep++;
word = readw(addr + FEPSTAT);
}
err1 = readw(addr + SEQUENCE);
err2 = readw(addr + ERROR);
dev_warn(&brd->pdev->dev,
"FEPOS for %s not functioning. Error #(%x,%x).\n",
brd->name, err1, err2);
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
return -EIO;
}
static void dgap_do_reset_board(struct board_t *brd)
{
u8 check;
u32 check1;
u32 check2;
unsigned int i;
if (!brd || (brd->magic != DGAP_BOARD_MAGIC) ||
!brd->re_map_membase || !brd->re_map_port)
return;
writeb(FEPRST, brd->re_map_port);
for (i = 0; i <= 1000; i++) {
check = readb(brd->re_map_port) & 0xe;
if (check == FEPRST)
break;
udelay(10);
}
if (i > 1000) {
dev_warn(&brd->pdev->dev,
"dgap: Board not resetting... Failing board.\n");
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
return;
}
writel(0xa55a3cc3, (brd->re_map_membase + LOWMEM));
writel(0x5aa5c33c, (brd->re_map_membase + HIGHMEM));
check1 = readl(brd->re_map_membase + LOWMEM);
check2 = readl(brd->re_map_membase + HIGHMEM);
if ((check1 != 0xa55a3cc3) || (check2 != 0x5aa5c33c)) {
dev_warn(&brd->pdev->dev,
"No memory at %p for board.\n",
brd->re_map_membase);
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
return;
}
}
static void dgap_do_conc_load(struct board_t *brd, u8 *uaddr, int len)
{
char __iomem *vaddr;
u16 offset;
struct downld_t *to_dp;
if (!brd || (brd->magic != DGAP_BOARD_MAGIC) || !brd->re_map_membase)
return;
vaddr = brd->re_map_membase;
offset = readw((u16 *) (vaddr + DOWNREQ));
to_dp = (struct downld_t *) (vaddr + (int) offset);
memcpy_toio(to_dp, uaddr, len);
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
u8 byte1;
u8 byte2;
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
rom_offset = readw(brd->re_map_membase +
base_offset + 0x18);
image_length = readw(brd->re_map_membase +
rom_offset + 0x10) * 512;
vpd_offset = readw(brd->re_map_membase +
rom_offset + 0x08);
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
for (i = 0; i < VPDSIZE; i++) {
brd->vpd[i] = readb(brd->re_map_membase +
vpd_offset + i);
}
}
}
magic = FEP5_ROM_MAGIC;
pci_write_config_dword(brd->pdev, PCI_ROM_ADDRESS, magic);
}
static ssize_t dgap_driver_version_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", DG_PART);
}
static ssize_t dgap_driver_boards_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", dgap_numboards);
}
static ssize_t dgap_driver_maxboards_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", MAXBOARDS);
}
static ssize_t dgap_driver_pollcounter_show(struct device_driver *ddp,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%ld\n", dgap_poll_counter);
}
static ssize_t dgap_driver_pollrate_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%dms\n", dgap_poll_tick);
}
static ssize_t dgap_driver_pollrate_store(struct device_driver *ddp,
const char *buf, size_t count)
{
if (sscanf(buf, "%d\n", &dgap_poll_tick) != 1)
return -EINVAL;
return count;
}
static int dgap_create_driver_sysfiles(struct pci_driver *dgap_driver)
{
int rc = 0;
struct device_driver *driverfs = &dgap_driver->driver;
rc |= driver_create_file(driverfs, &driver_attr_version);
rc |= driver_create_file(driverfs, &driver_attr_boards);
rc |= driver_create_file(driverfs, &driver_attr_maxboards);
rc |= driver_create_file(driverfs, &driver_attr_pollrate);
rc |= driver_create_file(driverfs, &driver_attr_pollcounter);
return rc;
}
static void dgap_remove_driver_sysfiles(struct pci_driver *dgap_driver)
{
struct device_driver *driverfs = &dgap_driver->driver;
driver_remove_file(driverfs, &driver_attr_version);
driver_remove_file(driverfs, &driver_attr_boards);
driver_remove_file(driverfs, &driver_attr_maxboards);
driver_remove_file(driverfs, &driver_attr_pollrate);
driver_remove_file(driverfs, &driver_attr_pollcounter);
}
static void dgap_create_tty_sysfs(struct un_t *un, struct device *c)
{
int ret;
ret = sysfs_create_group(&c->kobj, &dgap_tty_attribute_group);
if (ret)
return;
dev_set_drvdata(c, un);
}
static void dgap_remove_tty_sysfs(struct device *c)
{
sysfs_remove_group(&c->kobj, &dgap_tty_attribute_group);
}
static int dgap_tty_register_ports(struct board_t *brd)
{
struct channel_t *ch;
int i;
int ret;
brd->serial_ports = kcalloc(brd->nasync, sizeof(*brd->serial_ports),
GFP_KERNEL);
if (!brd->serial_ports)
return -ENOMEM;
brd->printer_ports = kcalloc(brd->nasync, sizeof(*brd->printer_ports),
GFP_KERNEL);
if (!brd->printer_ports) {
ret = -ENOMEM;
goto free_serial_ports;
}
for (i = 0; i < brd->nasync; i++) {
tty_port_init(&brd->serial_ports[i]);
tty_port_init(&brd->printer_ports[i]);
}
ch = brd->channels[0];
for (i = 0; i < brd->nasync; i++, ch = brd->channels[i]) {
struct device *classp;
classp = tty_port_register_device(&brd->serial_ports[i],
brd->serial_driver,
i, NULL);
if (IS_ERR(classp)) {
ret = PTR_ERR(classp);
goto unregister_ttys;
}
dgap_create_tty_sysfs(&ch->ch_tun, classp);
ch->ch_tun.un_sysfs = classp;
classp = tty_port_register_device(&brd->printer_ports[i],
brd->print_driver,
i, NULL);
if (IS_ERR(classp)) {
ret = PTR_ERR(classp);
goto unregister_ttys;
}
dgap_create_tty_sysfs(&ch->ch_pun, classp);
ch->ch_pun.un_sysfs = classp;
}
dgap_create_ports_sysfiles(brd);
return 0;
unregister_ttys:
while (i >= 0) {
ch = brd->channels[i];
if (ch->ch_tun.un_sysfs) {
dgap_remove_tty_sysfs(ch->ch_tun.un_sysfs);
tty_unregister_device(brd->serial_driver, i);
}
if (ch->ch_pun.un_sysfs) {
dgap_remove_tty_sysfs(ch->ch_pun.un_sysfs);
tty_unregister_device(brd->print_driver, i);
}
i--;
}
for (i = 0; i < brd->nasync; i++) {
tty_port_destroy(&brd->serial_ports[i]);
tty_port_destroy(&brd->printer_ports[i]);
}
kfree(brd->printer_ports);
brd->printer_ports = NULL;
free_serial_ports:
kfree(brd->serial_ports);
brd->serial_ports = NULL;
return ret;
}
static void dgap_cleanup_tty(struct board_t *brd)
{
struct device *dev;
unsigned int i;
for (i = 0; i < brd->nasync; i++) {
tty_port_destroy(&brd->serial_ports[i]);
dev = brd->channels[i]->ch_tun.un_sysfs;
dgap_remove_tty_sysfs(dev);
tty_unregister_device(brd->serial_driver, i);
}
tty_unregister_driver(brd->serial_driver);
put_tty_driver(brd->serial_driver);
kfree(brd->serial_ports);
for (i = 0; i < brd->nasync; i++) {
tty_port_destroy(&brd->printer_ports[i]);
dev = brd->channels[i]->ch_pun.un_sysfs;
dgap_remove_tty_sysfs(dev);
tty_unregister_device(brd->print_driver, i);
}
tty_unregister_driver(brd->print_driver);
put_tty_driver(brd->print_driver);
kfree(brd->printer_ports);
}
static int dgap_request_irq(struct board_t *brd)
{
int rc;
if (!brd || brd->magic != DGAP_BOARD_MAGIC)
return -ENODEV;
if (dgap_config_get_useintr(brd) && brd->irq) {
rc = request_irq(brd->irq, dgap_intr, IRQF_SHARED, "DGAP", brd);
if (!rc)
brd->intr_used = 1;
}
return 0;
}
static void dgap_free_irq(struct board_t *brd)
{
if (brd->intr_used && brd->irq)
free_irq(brd->irq, brd);
}
static int dgap_firmware_load(struct pci_dev *pdev, int card_type,
struct board_t *brd)
{
const struct firmware *fw;
char *tmp_ptr;
int ret;
char *dgap_config_buf;
dgap_get_vpd(brd);
dgap_do_reset_board(brd);
if (fw_info[card_type].conf_name) {
ret = request_firmware(&fw, fw_info[card_type].conf_name,
&pdev->dev);
if (ret) {
dev_err(&pdev->dev, "config file %s not found\n",
fw_info[card_type].conf_name);
return ret;
}
dgap_config_buf = kzalloc(fw->size + 1, GFP_KERNEL);
if (!dgap_config_buf) {
release_firmware(fw);
return -ENOMEM;
}
memcpy(dgap_config_buf, fw->data, fw->size);
release_firmware(fw);
tmp_ptr = dgap_config_buf;
if (dgap_parsefile(&tmp_ptr) != 0) {
kfree(dgap_config_buf);
return -EINVAL;
}
kfree(dgap_config_buf);
}
brd->bd_config =
dgap_find_config(brd->type, brd->pci_bus, brd->pci_slot);
if (brd->type == PAPORT8 && !brd->bd_config)
brd->bd_config =
dgap_find_config(PAPORT4, brd->pci_bus, brd->pci_slot);
if (!brd->bd_config) {
dev_err(&pdev->dev, "No valid configuration found\n");
return -EINVAL;
}
if (fw_info[card_type].bios_name) {
ret = request_firmware(&fw, fw_info[card_type].bios_name,
&pdev->dev);
if (ret) {
dev_err(&pdev->dev, "bios file %s not found\n",
fw_info[card_type].bios_name);
return ret;
}
dgap_do_bios_load(brd, fw->data, fw->size);
release_firmware(fw);
ret = dgap_test_bios(brd);
if (ret)
return ret;
}
if (fw_info[card_type].fep_name) {
ret = request_firmware(&fw, fw_info[card_type].fep_name,
&pdev->dev);
if (ret) {
dev_err(&pdev->dev, "dgap: fep file %s not found\n",
fw_info[card_type].fep_name);
return ret;
}
dgap_do_fep_load(brd, fw->data, fw->size);
release_firmware(fw);
ret = dgap_test_fep(brd);
if (ret)
return ret;
}
#ifdef DIGI_CONCENTRATORS_SUPPORTED
if ((bd->type == PCX) || (bd->type == PEPC)) {
chk_addr = (u16 *) (vaddr + DOWNREQ);
check = readw(chk_addr);
vaddr = brd->re_map_membase;
}
if (fw_info[card_type].con_name && check && vaddr) {
ret = request_firmware(&fw, fw_info[card_type].con_name,
&pdev->dev);
if (ret) {
dev_err(&pdev->dev, "conc file %s not found\n",
fw_info[card_type].con_name);
return ret;
}
offset = readw((u16 *) (vaddr + DOWNREQ));
memcpy_toio(offset, fw->data, fw->size);
dgap_do_conc_load(brd, (char *)fw->data, fw->size)
release_firmware(fw);
}
#endif
return 0;
}
static int dgap_tty_init(struct board_t *brd)
{
int i;
int tlw;
uint true_count;
u8 __iomem *vaddr;
u8 modem;
struct channel_t *ch;
struct bs_t __iomem *bs;
struct cm_t __iomem *cm;
int ret;
vaddr = brd->re_map_membase;
true_count = readw((vaddr + NCHAN));
brd->nasync = dgap_config_get_num_prts(brd);
if (!brd->nasync)
brd->nasync = brd->maxports;
if (brd->nasync > brd->maxports)
brd->nasync = brd->maxports;
if (true_count != brd->nasync) {
dev_warn(&brd->pdev->dev,
"%s configured for %d ports, has %d ports.\n",
brd->name, brd->nasync, true_count);
if ((brd->type == PPCM) &&
(true_count == 64 || true_count == 0)) {
dev_warn(&brd->pdev->dev,
"Please make SURE the EBI cable running from the card\n");
dev_warn(&brd->pdev->dev,
"to each EM module is plugged into EBI IN!\n");
}
brd->nasync = true_count;
if (!brd->nasync) {
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
return -EIO;
}
}
for (i = 0; i < brd->nasync; i++) {
brd->channels[i] =
kzalloc(sizeof(struct channel_t), GFP_KERNEL);
if (!brd->channels[i]) {
ret = -ENOMEM;
goto free_chan;
}
}
ch = brd->channels[0];
vaddr = brd->re_map_membase;
bs = (struct bs_t __iomem *) ((ulong) vaddr + CHANBUF);
cm = (struct cm_t __iomem *) ((ulong) vaddr + CMDBUF);
brd->bd_bs = bs;
for (i = 0; i < brd->nasync; i++, ch = brd->channels[i], bs++) {
spin_lock_init(&ch->ch_lock);
ch->magic = DGAP_CHANNEL_MAGIC;
ch->ch_tun.magic = DGAP_UNIT_MAGIC;
ch->ch_tun.un_type = DGAP_SERIAL;
ch->ch_tun.un_ch = ch;
ch->ch_tun.un_dev = i;
ch->ch_pun.magic = DGAP_UNIT_MAGIC;
ch->ch_pun.un_type = DGAP_PRINT;
ch->ch_pun.un_ch = ch;
ch->ch_pun.un_dev = i;
ch->ch_vaddr = vaddr;
ch->ch_bs = bs;
ch->ch_cm = cm;
ch->ch_bd = brd;
ch->ch_portnum = i;
ch->ch_digi = dgap_digi_init;
if (dgap_config_get_altpin(brd)) {
ch->ch_dsr = DM_CD;
ch->ch_cd = DM_DSR;
ch->ch_digi.digi_flags |= DIGI_ALTPIN;
} else {
ch->ch_cd = DM_CD;
ch->ch_dsr = DM_DSR;
}
ch->ch_taddr = vaddr + (ioread16(&(ch->ch_bs->tx_seg)) << 4);
ch->ch_raddr = vaddr + (ioread16(&(ch->ch_bs->rx_seg)) << 4);
ch->ch_tx_win = 0;
ch->ch_rx_win = 0;
ch->ch_tsize = readw(&(ch->ch_bs->tx_max)) + 1;
ch->ch_rsize = readw(&(ch->ch_bs->rx_max)) + 1;
ch->ch_tstart = 0;
ch->ch_rstart = 0;
tlw = ch->ch_tsize >= 2000 ? ((ch->ch_tsize * 5) / 8) :
ch->ch_tsize / 2;
ch->ch_tlw = tlw;
dgap_cmdw(ch, STLOW, tlw, 0);
dgap_cmdw(ch, SRLOW, ch->ch_rsize / 2, 0);
dgap_cmdw(ch, SRHIGH, 7 * ch->ch_rsize / 8, 0);
ch->ch_mistat = readb(&(ch->ch_bs->m_stat));
init_waitqueue_head(&ch->ch_flags_wait);
init_waitqueue_head(&ch->ch_tun.un_flags_wait);
init_waitqueue_head(&ch->ch_pun.un_flags_wait);
modem = (DM_CD | DM_DSR | DM_CTS | DM_RI);
writeb(modem, &(ch->ch_bs->m_int));
if (brd->intr_used)
writew(0, &(ch->ch_bs->edelay));
else
writew(100, &(ch->ch_bs->edelay));
writeb(1, &(ch->ch_bs->idata));
}
return 0;
free_chan:
while (--i >= 0) {
kfree(brd->channels[i]);
brd->channels[i] = NULL;
}
return ret;
}
static void dgap_tty_free(struct board_t *brd)
{
int i;
for (i = 0; i < brd->nasync; i++)
kfree(brd->channels[i]);
}
static int dgap_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int rc;
struct board_t *brd;
if (dgap_numboards >= MAXBOARDS)
return -EPERM;
rc = pci_enable_device(pdev);
if (rc)
return -EIO;
brd = dgap_found_board(pdev, ent->driver_data, dgap_numboards);
if (IS_ERR(brd))
return PTR_ERR(brd);
rc = dgap_firmware_load(pdev, ent->driver_data, brd);
if (rc)
goto cleanup_brd;
rc = dgap_alloc_flipbuf(brd);
if (rc)
goto cleanup_brd;
rc = dgap_tty_register(brd);
if (rc)
goto free_flipbuf;
rc = dgap_request_irq(brd);
if (rc)
goto unregister_tty;
rc = dgap_tty_init(brd);
if (rc < 0)
goto free_irq;
rc = dgap_tty_register_ports(brd);
if (rc)
goto tty_free;
brd->state = BOARD_READY;
brd->dpastatus = BD_RUNNING;
dgap_board[dgap_numboards++] = brd;
return 0;
tty_free:
dgap_tty_free(brd);
free_irq:
dgap_free_irq(brd);
unregister_tty:
dgap_tty_unregister(brd);
free_flipbuf:
dgap_free_flipbuf(brd);
cleanup_brd:
dgap_cleanup_nodes();
dgap_unmap(brd);
kfree(brd);
return rc;
}
static void dgap_cleanup_board(struct board_t *brd)
{
unsigned int i;
if (!brd || brd->magic != DGAP_BOARD_MAGIC)
return;
dgap_free_irq(brd);
tasklet_kill(&brd->helper_tasklet);
dgap_unmap(brd);
for (i = 0; i < MAXPORTS ; i++)
kfree(brd->channels[i]);
kfree(brd->flipbuf);
kfree(brd->flipflagbuf);
dgap_board[brd->boardnum] = NULL;
kfree(brd);
}
static void dgap_remove_one(struct pci_dev *dev)
{
unsigned int i;
ulong lock_flags;
struct pci_driver *drv = to_pci_driver(dev->dev.driver);
spin_lock_irqsave(&dgap_poll_lock, lock_flags);
dgap_poll_stop = 1;
spin_unlock_irqrestore(&dgap_poll_lock, lock_flags);
del_timer_sync(&dgap_poll_timer);
dgap_remove_driver_sysfiles(drv);
device_destroy(dgap_class, MKDEV(DIGI_DGAP_MAJOR, 0));
class_destroy(dgap_class);
unregister_chrdev(DIGI_DGAP_MAJOR, "dgap");
for (i = 0; i < dgap_numboards; ++i) {
dgap_remove_ports_sysfiles(dgap_board[i]);
dgap_cleanup_tty(dgap_board[i]);
dgap_cleanup_board(dgap_board[i]);
}
dgap_cleanup_nodes();
}
static int dgap_start(void)
{
int rc;
unsigned long flags;
struct device *device;
dgap_numboards = 0;
pr_info("For the tools package please visit http://www.digi.com\n");
rc = register_chrdev(DIGI_DGAP_MAJOR, "dgap", &dgap_board_fops);
if (rc < 0)
return rc;
dgap_class = class_create(THIS_MODULE, "dgap_mgmt");
if (IS_ERR(dgap_class)) {
rc = PTR_ERR(dgap_class);
goto failed_class;
}
device = device_create(dgap_class, NULL,
MKDEV(DIGI_DGAP_MAJOR, 0),
NULL, "dgap_mgmt");
if (IS_ERR(device)) {
rc = PTR_ERR(device);
goto failed_device;
}
spin_lock_irqsave(&dgap_poll_lock, flags);
setup_timer(&dgap_poll_timer, dgap_poll_handler, 0);
dgap_poll_timer.data = 0;
dgap_poll_time = jiffies + dgap_jiffies_from_ms(dgap_poll_tick);
dgap_poll_timer.expires = dgap_poll_time;
spin_unlock_irqrestore(&dgap_poll_lock, flags);
add_timer(&dgap_poll_timer);
return rc;
failed_device:
class_destroy(dgap_class);
failed_class:
unregister_chrdev(DIGI_DGAP_MAJOR, "dgap");
return rc;
}
static void dgap_stop(void)
{
unsigned long lock_flags;
spin_lock_irqsave(&dgap_poll_lock, lock_flags);
dgap_poll_stop = 1;
spin_unlock_irqrestore(&dgap_poll_lock, lock_flags);
del_timer_sync(&dgap_poll_timer);
device_destroy(dgap_class, MKDEV(DIGI_DGAP_MAJOR, 0));
class_destroy(dgap_class);
unregister_chrdev(DIGI_DGAP_MAJOR, "dgap");
}
static int dgap_init_module(void)
{
int rc;
pr_info("%s, Digi International Part Number %s\n", DG_NAME, DG_PART);
rc = dgap_start();
if (rc)
return rc;
rc = pci_register_driver(&dgap_driver);
if (rc)
goto err_stop;
rc = dgap_create_driver_sysfiles(&dgap_driver);
if (rc)
goto err_unregister;
dgap_driver_state = DRIVER_READY;
return 0;
err_unregister:
pci_unregister_driver(&dgap_driver);
err_stop:
dgap_stop();
return rc;
}
static void dgap_cleanup_module(void)
{
if (dgap_numboards)
pci_unregister_driver(&dgap_driver);
}
