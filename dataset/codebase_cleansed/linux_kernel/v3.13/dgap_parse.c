int dgap_parsefile(char **in, int Remove)
{
struct cnode *p, *brd, *line, *conc;
int rc;
char *s = NULL, *s2 = NULL;
int linecnt = 0;
p = &dgap_head;
brd = line = conc = NULL;
while (p->next != NULL) {
p = p->next;
}
while ( (rc = dgap_gettok(in,p)) != BEGIN ) {
if (rc == 0) {
dgap_err("unexpected EOF");
return(-1);
}
}
for (; ; ) {
rc = dgap_gettok(in,p);
if (rc == 0) {
dgap_err("unexpected EOF");
return(-1);
}
switch (rc) {
case 0:
dgap_err("unexpected end of file");
return(-1);
case BEGIN:
dgap_err("unexpected config_begin\n");
return(-1);
case END:
return(0);
case BOARD:
if (dgap_checknode(p))
return(-1);
if ( (p->next = dgap_newnode(BNODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
p->u.board.status = dgap_savestring("No");
line = conc = NULL;
brd = p;
linecnt = -1;
break;
case APORT2_920P:
if (p->type != BNODE) {
dgap_err("unexpected Digi_2r_920 string");
return(-1);
}
p->u.board.type = APORT2_920P;
p->u.board.v_type = 1;
DPR_INIT(("Adding Digi_2r_920 PCI to config...\n"));
break;
case APORT4_920P:
if (p->type != BNODE) {
dgap_err("unexpected Digi_4r_920 string");
return(-1);
}
p->u.board.type = APORT4_920P;
p->u.board.v_type = 1;
DPR_INIT(("Adding Digi_4r_920 PCI to config...\n"));
break;
case APORT8_920P:
if (p->type != BNODE) {
dgap_err("unexpected Digi_8r_920 string");
return(-1);
}
p->u.board.type = APORT8_920P;
p->u.board.v_type = 1;
DPR_INIT(("Adding Digi_8r_920 PCI to config...\n"));
break;
case PAPORT4:
if (p->type != BNODE) {
dgap_err("unexpected Digi_4r(PCI) string");
return(-1);
}
p->u.board.type = PAPORT4;
p->u.board.v_type = 1;
DPR_INIT(("Adding Digi_4r PCI to config...\n"));
break;
case PAPORT8:
if (p->type != BNODE) {
dgap_err("unexpected Digi_8r string");
return(-1);
}
p->u.board.type = PAPORT8;
p->u.board.v_type = 1;
DPR_INIT(("Adding Digi_8r PCI to config...\n"));
break;
case PCX:
if (p->type != BNODE) {
dgap_err("unexpected Digi_C/X_(PCI) string");
return(-1);
}
p->u.board.type = PCX;
p->u.board.v_type = 1;
p->u.board.conc1 = 0;
p->u.board.conc2 = 0;
p->u.board.module1 = 0;
p->u.board.module2 = 0;
DPR_INIT(("Adding PCI C/X to config...\n"));
break;
case PEPC:
if (p->type != BNODE) {
dgap_err("unexpected \"Digi_EPC/X_(PCI)\" string");
return(-1);
}
p->u.board.type = PEPC;
p->u.board.v_type = 1;
p->u.board.conc1 = 0;
p->u.board.conc2 = 0;
p->u.board.module1 = 0;
p->u.board.module2 = 0;
DPR_INIT(("Adding PCI EPC/X to config...\n"));
break;
case PPCM:
if (p->type != BNODE) {
dgap_err("unexpected PCI/Xem string");
return(-1);
}
p->u.board.type = PPCM;
p->u.board.v_type = 1;
p->u.board.conc1 = 0;
p->u.board.conc2 = 0;
DPR_INIT(("Adding PCI XEM to config...\n"));
break;
case IO:
if (p->type != BNODE) {
dgap_err("IO port only vaild for boards");
return(-1);
}
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.board.portstr = dgap_savestring(s);
p->u.board.port = (short)simple_strtol(s, &s2, 0);
if ((short)strlen(s) > (short)(s2 - s)) {
dgap_err("bad number for IO port");
return(-1);
}
p->u.board.v_port = 1;
DPR_INIT(("Adding IO (%s) to config...\n", s));
break;
case MEM:
if (p->type != BNODE) {
dgap_err("memory address only vaild for boards");
return(-1);
}
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.board.addrstr = dgap_savestring(s);
p->u.board.addr = simple_strtoul(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for memory address");
return(-1);
}
p->u.board.v_addr = 1;
DPR_INIT(("Adding MEM (%s) to config...\n", s));
break;
case PCIINFO:
if (p->type != BNODE) {
dgap_err("memory address only vaild for boards");
return(-1);
}
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.board.pcibusstr = dgap_savestring(s);
p->u.board.pcibus = simple_strtoul(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for pci bus");
return(-1);
}
p->u.board.v_pcibus = 1;
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.board.pcislotstr = dgap_savestring(s);
p->u.board.pcislot = simple_strtoul(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for pci slot");
return(-1);
}
p->u.board.v_pcislot = 1;
DPR_INIT(("Adding PCIINFO (%s %s) to config...\n", p->u.board.pcibusstr,
p->u.board.pcislotstr));
break;
case METHOD:
if (p->type != BNODE) {
dgap_err("install method only vaild for boards");
return(-1);
}
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.board.method = dgap_savestring(s);
p->u.board.v_method = 1;
DPR_INIT(("Adding METHOD (%s) to config...\n", s));
break;
case STATUS:
if (p->type != BNODE) {
dgap_err("config status only vaild for boards");
return(-1);
}
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.board.status = dgap_savestring(s);
DPR_INIT(("Adding STATUS (%s) to config...\n", s));
break;
case NPORTS:
if (p->type == BNODE) {
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.board.nport = (char)simple_strtol(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for number of ports");
return(-1);
}
p->u.board.v_nport = 1;
} else if (p->type == CNODE) {
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.conc.nport = (char)simple_strtol(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for number of ports");
return(-1);
}
p->u.conc.v_nport = 1;
} else if (p->type == MNODE) {
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.module.nport = (char)simple_strtol(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for number of ports");
return(-1);
}
p->u.module.v_nport = 1;
} else {
dgap_err("nports only valid for concentrators or modules");
return(-1);
}
DPR_INIT(("Adding NPORTS (%s) to config...\n", s));
break;
case ID:
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.board.status = dgap_savestring(s);
if (p->type == CNODE) {
p->u.conc.id = dgap_savestring(s);
p->u.conc.v_id = 1;
} else if (p->type == MNODE) {
p->u.module.id = dgap_savestring(s);
p->u.module.v_id = 1;
} else {
dgap_err("id only valid for concentrators or modules");
return(-1);
}
DPR_INIT(("Adding ID (%s) to config...\n", s));
break;
case STARTO:
if (p->type == BNODE) {
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.board.start = simple_strtol(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for start of tty count");
return(-1);
}
p->u.board.v_start = 1;
} else if (p->type == CNODE) {
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.conc.start = simple_strtol(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for start of tty count");
return(-1);
}
p->u.conc.v_start = 1;
} else if (p->type == MNODE) {
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.module.start = simple_strtol(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for start of tty count");
return(-1);
}
p->u.module.v_start = 1;
} else {
dgap_err("start only valid for concentrators or modules");
return(-1);
}
DPR_INIT(("Adding START (%s) to config...\n", s));
break;
case TTYN:
if (dgap_checknode(p))
return(-1);
if ( (p->next = dgap_newnode(TNODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
if ( (s = dgap_getword(in)) == NULL ) {
dgap_err("unexpeced end of file");
return(-1);
}
if ( (p->u.ttyname = dgap_savestring(s)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
DPR_INIT(("Adding TTY (%s) to config...\n", s));
break;
case CU:
if (dgap_checknode(p))
return(-1);
if ( (p->next = dgap_newnode(CUNODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
if ( (s = dgap_getword(in)) == NULL ) {
dgap_err("unexpeced end of file");
return(-1);
}
if ( (p->u.cuname = dgap_savestring(s)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
DPR_INIT(("Adding CU (%s) to config...\n", s));
break;
case LINE:
if (dgap_checknode(p))
return(-1);
if (brd == NULL) {
dgap_err("must specify board before line info");
return(-1);
}
switch (brd->u.board.type) {
case PPCM:
dgap_err("line not vaild for PC/em");
return(-1);
}
if ( (p->next = dgap_newnode(LNODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
conc = NULL;
line = p;
linecnt++;
DPR_INIT(("Adding LINE to config...\n"));
break;
case CONC:
if (dgap_checknode(p))
return(-1);
if (line == NULL) {
dgap_err("must specify line info before concentrator");
return(-1);
}
if ( (p->next = dgap_newnode(CNODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
conc = p;
if (linecnt)
brd->u.board.conc2++;
else
brd->u.board.conc1++;
DPR_INIT(("Adding CONC to config...\n"));
break;
case CX:
if (p->type != CNODE) {
dgap_err("cx only valid for concentrators");
return(-1);
}
p->u.conc.type = CX;
p->u.conc.v_type = 1;
DPR_INIT(("Adding CX to config...\n"));
break;
case EPC:
if (p->type != CNODE) {
dgap_err("cx only valid for concentrators");
return(-1);
}
p->u.conc.type = EPC;
p->u.conc.v_type = 1;
DPR_INIT(("Adding EPC to config...\n"));
break;
case MOD:
if (dgap_checknode(p))
return(-1);
if (brd == NULL) {
dgap_err("must specify board info before EBI modules");
return(-1);
}
switch (brd->u.board.type) {
case PPCM:
linecnt = 0;
break;
default:
if (conc == NULL) {
dgap_err("must specify concentrator info before EBI module");
return(-1);
}
}
if ( (p->next = dgap_newnode(MNODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
if (linecnt)
brd->u.board.module2++;
else
brd->u.board.module1++;
DPR_INIT(("Adding MOD to config...\n"));
break;
case PORTS:
if (p->type != MNODE) {
dgap_err("ports only valid for EBI modules");
return(-1);
}
p->u.module.type = PORTS;
p->u.module.v_type = 1;
DPR_INIT(("Adding PORTS to config...\n"));
break;
case MODEM:
if (p->type != MNODE) {
dgap_err("modem only valid for modem modules");
return(-1);
}
p->u.module.type = MODEM;
p->u.module.v_type = 1;
DPR_INIT(("Adding MODEM to config...\n"));
break;
case CABLE:
if (p->type == LNODE) {
if ((s = dgap_getword(in)) == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.line.cable = dgap_savestring(s);
p->u.line.v_cable = 1;
}
DPR_INIT(("Adding CABLE (%s) to config...\n", s));
break;
case SPEED:
if (p->type == LNODE) {
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.line.speed = (char)simple_strtol(s, &s2, 0);
if ((short)strlen(s) > (short)(s2 - s)) {
dgap_err("bad number for line speed");
return(-1);
}
p->u.line.v_speed = 1;
} else if (p->type == CNODE) {
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.conc.speed = (char)simple_strtol(s, &s2, 0);
if ((short)strlen(s) > (short)(s2 - s)) {
dgap_err("bad number for line speed");
return(-1);
}
p->u.conc.v_speed = 1;
} else {
dgap_err("speed valid only for lines or concentrators.");
return(-1);
}
DPR_INIT(("Adding SPEED (%s) to config...\n", s));
break;
case CONNECT:
if (p->type == CNODE) {
if ((s = dgap_getword(in)) == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.conc.connect = dgap_savestring(s);
p->u.conc.v_connect = 1;
}
DPR_INIT(("Adding CONNECT (%s) to config...\n", s));
break;
case PRINT:
if (dgap_checknode(p))
return(-1);
if ( (p->next = dgap_newnode(PNODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
if ( (s = dgap_getword(in)) == NULL ) {
dgap_err("unexpeced end of file");
return(-1);
}
if ( (p->u.printname = dgap_savestring(s)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
DPR_INIT(("Adding PRINT (%s) to config...\n", s));
break;
case CMAJOR:
if (dgap_checknode(p))
return(-1);
if ( (p->next = dgap_newnode(JNODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.majornumber = simple_strtol(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for major number");
return(-1);
}
DPR_INIT(("Adding CMAJOR (%s) to config...\n", s));
break;
case ALTPIN:
if (dgap_checknode(p))
return(-1);
if ( (p->next = dgap_newnode(ANODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.altpin = simple_strtol(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for altpin");
return(-1);
}
DPR_INIT(("Adding ALTPIN (%s) to config...\n", s));
break;
case USEINTR:
if (dgap_checknode(p))
return(-1);
if ( (p->next = dgap_newnode(INTRNODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.useintr = simple_strtol(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for useintr");
return(-1);
}
DPR_INIT(("Adding USEINTR (%s) to config...\n", s));
break;
case TTSIZ:
if (dgap_checknode(p))
return(-1);
if ( (p->next = dgap_newnode(TSNODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.ttysize = simple_strtol(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for ttysize");
return(-1);
}
DPR_INIT(("Adding TTSIZ (%s) to config...\n", s));
break;
case CHSIZ:
if (dgap_checknode(p))
return(-1);
if ( (p->next = dgap_newnode(CSNODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.chsize = simple_strtol(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for chsize");
return(-1);
}
DPR_INIT(("Adding CHSIZE (%s) to config...\n", s));
break;
case BSSIZ:
if (dgap_checknode(p))
return(-1);
if ( (p->next = dgap_newnode(BSNODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.bssize = simple_strtol(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for bssize");
return(-1);
}
DPR_INIT(("Adding BSSIZ (%s) to config...\n", s));
break;
case UNTSIZ:
if (dgap_checknode(p))
return(-1);
if ( (p->next = dgap_newnode(USNODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.unsize = simple_strtol(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for schedsize");
return(-1);
}
DPR_INIT(("Adding UNTSIZ (%s) to config...\n", s));
break;
case F2SIZ:
if (dgap_checknode(p))
return(-1);
if ( (p->next = dgap_newnode(FSNODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.f2size = simple_strtol(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for f2200size");
return(-1);
}
DPR_INIT(("Adding F2SIZ (%s) to config...\n", s));
break;
case VPSIZ:
if (dgap_checknode(p))
return(-1);
if ( (p->next = dgap_newnode(VSNODE)) == NULL ) {
dgap_err("out of memory");
return(-1);
}
p = p->next;
s = dgap_getword(in);
if (s == NULL) {
dgap_err("unexpected end of file");
return(-1);
}
p->u.vpixsize = simple_strtol(s, &s2, 0);
if ((int)strlen(s) > (int)(s2 - s)) {
dgap_err("bad number for vpixsize");
return(-1);
}
DPR_INIT(("Adding VPSIZ (%s) to config...\n", s));
break;
}
}
}
static char *dgap_sindex (char *string, char *group)
{
char *ptr;
if (!string || !group)
return (char *) NULL;
if (*group == '^') {
group++;
for (; *string; string++) {
for (ptr = group; *ptr; ptr++) {
if (*ptr == *string)
break;
}
if (*ptr == '\0')
return string;
}
}
else {
for (; *string; string++) {
for (ptr = group; *ptr; ptr++) {
if (*ptr == *string)
return string;
}
}
}
return (char *) NULL;
}
static int dgap_gettok(char **in, struct cnode *p)
{
char *w;
struct toklist *t;
if (strstr(dgap_cword, "boar")) {
w = dgap_getword(in);
snprintf(dgap_cword, MAXCWORD, "%s", w);
for (t = dgap_tlist; t->token != 0; t++) {
if ( !strcmp(w, t->string)) {
return(t->token);
}
}
dgap_err("board !!type not specified");
return(1);
}
else {
while ( (w = dgap_getword(in)) != NULL ) {
snprintf(dgap_cword, MAXCWORD, "%s", w);
for (t = dgap_tlist; t->token != 0; t++) {
if ( !strcmp(w, t->string) )
return(t->token);
}
}
return(0);
}
}
static char *dgap_getword(char **in)
{
char *ret_ptr = *in;
char *ptr = dgap_sindex(*in, " \t\n");
if (!ptr)
return NULL;
*ptr = '\0';
*in = ptr + 1;
while (*in && **in && ((**in == ' ') || (**in == '\t') || (**in == '\n'))) {
**in = '\0';
*in = *in + 1;
}
return ret_ptr;
}
static void dgap_err(char *s)
{
printk("DGAP: parse: %s\n", s);
}
static struct cnode *dgap_newnode(int t)
{
struct cnode *n;
n = kmalloc(sizeof(struct cnode), GFP_ATOMIC);
if (n != NULL) {
memset((char *)n, 0, sizeof(struct cnode));
n->type = t;
}
return(n);
}
static int dgap_checknode(struct cnode *p)
{
switch (p->type) {
case BNODE:
if (p->u.board.v_type == 0) {
dgap_err("board type !not specified");
return(1);
}
return(0);
case LNODE:
if (p->u.line.v_speed == 0) {
dgap_err("line speed not specified");
return(1);
}
return(0);
case CNODE:
if (p->u.conc.v_type == 0) {
dgap_err("concentrator type not specified");
return(1);
}
if (p->u.conc.v_speed == 0) {
dgap_err("concentrator line speed not specified");
return(1);
}
if (p->u.conc.v_nport == 0) {
dgap_err("number of ports on concentrator not specified");
return(1);
}
if (p->u.conc.v_id == 0) {
dgap_err("concentrator id letter not specified");
return(1);
}
return(0);
case MNODE:
if (p->u.module.v_type == 0) {
dgap_err("EBI module type not specified");
return(1);
}
if (p->u.module.v_nport == 0) {
dgap_err("number of ports on EBI module not specified");
return(1);
}
if (p->u.module.v_id == 0) {
dgap_err("EBI module id letter not specified");
return(1);
}
return(0);
}
return(0);
}
static char *dgap_savestring(char *s)
{
char *p;
if ( (p = kmalloc(strlen(s) + 1, GFP_ATOMIC) ) != NULL) {
strcpy(p, s);
}
return(p);
}
uint dgap_config_get_useintr(struct board_t *bd)
{
struct cnode *p = NULL;
if (!bd)
return(0);
for (p = bd->bd_config; p; p = p->next) {
switch (p->type) {
case INTRNODE:
return p->u.useintr;
default:
break;
}
}
return 0;
}
uint dgap_config_get_altpin(struct board_t *bd)
{
struct cnode *p = NULL;
if (!bd)
return(0);
for (p = bd->bd_config; p; p = p->next) {
switch (p->type) {
case ANODE:
return p->u.altpin;
default:
break;
}
}
return 0;
}
struct cnode *dgap_find_config(int type, int bus, int slot)
{
struct cnode *p, *prev = NULL, *prev2 = NULL, *found = NULL;
p = &dgap_head;
while (p->next != NULL) {
prev = p;
p = p->next;
if (p->type == BNODE) {
if (p->u.board.type == type) {
if (p->u.board.v_pcibus && p->u.board.pcibus != bus) {
DPR(("Found matching board, but wrong bus position. System says bus %d, we want bus %ld\n",
bus, p->u.board.pcibus));
continue;
}
if (p->u.board.v_pcislot && p->u.board.pcislot != slot) {
DPR_INIT(("Found matching board, but wrong slot position. System says slot %d, we want slot %ld\n",
slot, p->u.board.pcislot));
continue;
}
DPR_INIT(("Matched type in config file\n"));
found = p;
while (p->next != NULL) {
prev2 = p;
p = p->next;
if (p->type == BNODE) {
prev2->next = NULL;
prev->next = p;
return found;
}
}
prev->next = NULL;
return found;
}
}
}
return NULL;
}
uint dgap_config_get_number_of_ports(struct board_t *bd)
{
int count = 0;
struct cnode *p = NULL;
if (!bd)
return(0);
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
return (count);
}
char *dgap_create_config_string(struct board_t *bd, char *string)
{
char *ptr = string;
struct cnode *p = NULL;
struct cnode *q = NULL;
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
if ((q != NULL) && (q->type == MNODE) ) {
*ptr = (p->u.conc.nport + 0x80);
ptr++;
p = q;
while ((q->next != NULL) && (q->next->type) == MNODE) {
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
char *dgap_get_config_letters(struct board_t *bd, char *string)
{
int found = FALSE;
char *ptr = string;
struct cnode *cptr = NULL;
int len = 0;
int left = MAXTTYNAMELEN;
if (!bd) {
return "<NULL>";
}
for (cptr = bd->bd_config; cptr; cptr = cptr->next) {
if ((cptr->type == BNODE) &&
((cptr->u.board.type == APORT2_920P) || (cptr->u.board.type == APORT4_920P) ||
(cptr->u.board.type == APORT8_920P) || (cptr->u.board.type == PAPORT4) ||
(cptr->u.board.type == PAPORT8))) {
found = TRUE;
}
if (cptr->type == TNODE && found == TRUE) {
char *ptr1;
if (strstr(cptr->u.ttyname, "tty")) {
ptr1 = cptr->u.ttyname;
ptr1 += 3;
}
else {
ptr1 = cptr->u.ttyname;
}
if (ptr1) {
len = snprintf(ptr, left, "%s", ptr1);
left -= len;
ptr += len;
if (left <= 0)
break;
}
}
if (cptr->type == CNODE) {
if (cptr->u.conc.id) {
len = snprintf(ptr, left, "%s", cptr->u.conc.id);
left -= len;
ptr += len;
if (left <= 0)
break;
}
}
if (cptr->type == MNODE) {
if (cptr->u.module.id) {
len = snprintf(ptr, left, "%s", cptr->u.module.id);
left -= len;
ptr += len;
if (left <= 0)
break;
}
}
}
return string;
}
