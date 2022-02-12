char *capi_info2str(u16 reason)
{
return "..";
}
char *capi_info2str(u16 reason)
{
switch (reason) {
case 0x0001:
return "NCPI not supported by current protocol, NCPI ignored";
case 0x0002:
return "Flags not supported by current protocol, flags ignored";
case 0x0003:
return "Alert already sent by another application";
case 0x1001:
return "Too many applications";
case 0x1002:
return "Logical block size too small, must be at least 128 Bytes";
case 0x1003:
return "Buffer exceeds 64 kByte";
case 0x1004:
return "Message buffer size too small, must be at least 1024 Bytes";
case 0x1005:
return "Max. number of logical connections not supported";
case 0x1006:
return "Reserved";
case 0x1007:
return "The message could not be accepted because of an internal busy condition";
case 0x1008:
return "OS resource error (no memory ?)";
case 0x1009:
return "CAPI not installed";
case 0x100A:
return "Controller does not support external equipment";
case 0x100B:
return "Controller does only support external equipment";
case 0x1101:
return "Illegal application number";
case 0x1102:
return "Illegal command or subcommand or message length less than 12 bytes";
case 0x1103:
return "The message could not be accepted because of a queue full condition !! The error code does not imply that CAPI cannot receive messages directed to another controller, PLCI or NCCI";
case 0x1104:
return "Queue is empty";
case 0x1105:
return "Queue overflow, a message was lost !! This indicates a configuration error. The only recovery from this error is to perform a CAPI_RELEASE";
case 0x1106:
return "Unknown notification parameter";
case 0x1107:
return "The Message could not be accepted because of an internal busy condition";
case 0x1108:
return "OS Resource error (no memory ?)";
case 0x1109:
return "CAPI not installed";
case 0x110A:
return "Controller does not support external equipment";
case 0x110B:
return "Controller does only support external equipment";
case 0x2001:
return "Message not supported in current state";
case 0x2002:
return "Illegal Controller / PLCI / NCCI";
case 0x2003:
return "Out of PLCI";
case 0x2004:
return "Out of NCCI";
case 0x2005:
return "Out of LISTEN";
case 0x2006:
return "Out of FAX resources (protocol T.30)";
case 0x2007:
return "Illegal message parameter coding";
case 0x3001:
return "B1 protocol not supported";
case 0x3002:
return "B2 protocol not supported";
case 0x3003:
return "B3 protocol not supported";
case 0x3004:
return "B1 protocol parameter not supported";
case 0x3005:
return "B2 protocol parameter not supported";
case 0x3006:
return "B3 protocol parameter not supported";
case 0x3007:
return "B protocol combination not supported";
case 0x3008:
return "NCPI not supported";
case 0x3009:
return "CIP Value unknown";
case 0x300A:
return "Flags not supported (reserved bits)";
case 0x300B:
return "Facility not supported";
case 0x300C:
return "Data length not supported by current protocol";
case 0x300D:
return "Reset procedure not supported by current protocol";
case 0x3301:
return "Protocol error layer 1 (broken line or B-channel removed by signalling protocol)";
case 0x3302:
return "Protocol error layer 2";
case 0x3303:
return "Protocol error layer 3";
case 0x3304:
return "Another application got that call";
case 0x3311:
return "Connecting not successful (remote station is no FAX G3 machine)";
case 0x3312:
return "Connecting not successful (training error)";
case 0x3313:
return "Disconnected before transfer (remote station does not support transfer mode, e.g. resolution)";
case 0x3314:
return "Disconnected during transfer (remote abort)";
case 0x3315:
return "Disconnected during transfer (remote procedure error, e.g. unsuccessful repetition of T.30 commands)";
case 0x3316:
return "Disconnected during transfer (local tx data underrun)";
case 0x3317:
return "Disconnected during transfer (local rx data overflow)";
case 0x3318:
return "Disconnected during transfer (local abort)";
case 0x3319:
return "Illegal parameter coding (e.g. SFF coding error)";
case 0x3481: return "Unallocated (unassigned) number";
case 0x3482: return "No route to specified transit network";
case 0x3483: return "No route to destination";
case 0x3486: return "Channel unacceptable";
case 0x3487:
return "Call awarded and being delivered in an established channel";
case 0x3490: return "Normal call clearing";
case 0x3491: return "User busy";
case 0x3492: return "No user responding";
case 0x3493: return "No answer from user (user alerted)";
case 0x3495: return "Call rejected";
case 0x3496: return "Number changed";
case 0x349A: return "Non-selected user clearing";
case 0x349B: return "Destination out of order";
case 0x349C: return "Invalid number format";
case 0x349D: return "Facility rejected";
case 0x349E: return "Response to STATUS ENQUIRY";
case 0x349F: return "Normal, unspecified";
case 0x34A2: return "No circuit / channel available";
case 0x34A6: return "Network out of order";
case 0x34A9: return "Temporary failure";
case 0x34AA: return "Switching equipment congestion";
case 0x34AB: return "Access information discarded";
case 0x34AC: return "Requested circuit / channel not available";
case 0x34AF: return "Resources unavailable, unspecified";
case 0x34B1: return "Quality of service unavailable";
case 0x34B2: return "Requested facility not subscribed";
case 0x34B9: return "Bearer capability not authorized";
case 0x34BA: return "Bearer capability not presently available";
case 0x34BF: return "Service or option not available, unspecified";
case 0x34C1: return "Bearer capability not implemented";
case 0x34C2: return "Channel type not implemented";
case 0x34C5: return "Requested facility not implemented";
case 0x34C6: return "Only restricted digital information bearer capability is available";
case 0x34CF: return "Service or option not implemented, unspecified";
case 0x34D1: return "Invalid call reference value";
case 0x34D2: return "Identified channel does not exist";
case 0x34D3: return "A suspended call exists, but this call identity does not";
case 0x34D4: return "Call identity in use";
case 0x34D5: return "No call suspended";
case 0x34D6: return "Call having the requested call identity has been cleared";
case 0x34D8: return "Incompatible destination";
case 0x34DB: return "Invalid transit network selection";
case 0x34DF: return "Invalid message, unspecified";
case 0x34E0: return "Mandatory information element is missing";
case 0x34E1: return "Message type non-existent or not implemented";
case 0x34E2: return "Message not compatible with call state or message type non-existent or not implemented";
case 0x34E3: return "Information element non-existent or not implemented";
case 0x34E4: return "Invalid information element contents";
case 0x34E5: return "Message not compatible with call state";
case 0x34E6: return "Recovery on timer expiry";
case 0x34EF: return "Protocol error, unspecified";
case 0x34FF: return "Interworking, unspecified";
default: return "No additional information";
}
}
static unsigned command_2_index(unsigned c, unsigned sc)
{
if (c & 0x80)
c = 0x9 + (c & 0x0f);
else if (c <= 0x0f);
else if (c == 0x41)
c = 0x9 + 0x1;
else if (c == 0xff)
c = 0x00;
return (sc & 3) * (0x9 + 0x9) + c;
}
static void jumpcstruct(_cmsg * cmsg)
{
unsigned layer;
for (cmsg->p++, layer = 1; layer;) {
cmsg->p++;
switch (TYP) {
case _CMSTRUCT:
layer++;
break;
case _CEND:
layer--;
break;
}
}
}
static void pars_2_message(_cmsg * cmsg)
{
for (; TYP != _CEND; cmsg->p++) {
switch (TYP) {
case _CBYTE:
byteTLcpy(cmsg->m + cmsg->l, OFF);
cmsg->l++;
break;
case _CWORD:
wordTLcpy(cmsg->m + cmsg->l, OFF);
cmsg->l += 2;
break;
case _CDWORD:
dwordTLcpy(cmsg->m + cmsg->l, OFF);
cmsg->l += 4;
break;
case _CSTRUCT:
if (*(u8 **) OFF == NULL) {
*(cmsg->m + cmsg->l) = '\0';
cmsg->l++;
} else if (**(_cstruct *) OFF != 0xff) {
structTLcpy(cmsg->m + cmsg->l, *(_cstruct *) OFF, 1 + **(_cstruct *) OFF);
cmsg->l += 1 + **(_cstruct *) OFF;
} else {
_cstruct s = *(_cstruct *) OFF;
structTLcpy(cmsg->m + cmsg->l, s, 3 + *(u16 *) (s + 1));
cmsg->l += 3 + *(u16 *) (s + 1);
}
break;
case _CMSTRUCT:
if (*(_cmstruct *) OFF == CAPI_DEFAULT) {
*(cmsg->m + cmsg->l) = '\0';
cmsg->l++;
jumpcstruct(cmsg);
}
else {
unsigned _l = cmsg->l;
unsigned _ls;
cmsg->l++;
cmsg->p++;
pars_2_message(cmsg);
_ls = cmsg->l - _l - 1;
if (_ls < 255)
(cmsg->m + _l)[0] = (u8) _ls;
else {
structTLcpyovl(cmsg->m + _l + 3, cmsg->m + _l + 1, _ls);
(cmsg->m + _l)[0] = 0xff;
wordTLcpy(cmsg->m + _l + 1, &_ls);
}
}
break;
}
}
}
unsigned capi_cmsg2message(_cmsg * cmsg, u8 * msg)
{
cmsg->m = msg;
cmsg->l = 8;
cmsg->p = 0;
cmsg->par = cpars[command_2_index(cmsg->Command, cmsg->Subcommand)];
pars_2_message(cmsg);
wordTLcpy(msg + 0, &cmsg->l);
byteTLcpy(cmsg->m + 4, &cmsg->Command);
byteTLcpy(cmsg->m + 5, &cmsg->Subcommand);
wordTLcpy(cmsg->m + 2, &cmsg->ApplId);
wordTLcpy(cmsg->m + 6, &cmsg->Messagenumber);
return 0;
}
static void message_2_pars(_cmsg * cmsg)
{
for (; TYP != _CEND; cmsg->p++) {
switch (TYP) {
case _CBYTE:
byteTRcpy(cmsg->m + cmsg->l, OFF);
cmsg->l++;
break;
case _CWORD:
wordTRcpy(cmsg->m + cmsg->l, OFF);
cmsg->l += 2;
break;
case _CDWORD:
dwordTRcpy(cmsg->m + cmsg->l, OFF);
cmsg->l += 4;
break;
case _CSTRUCT:
*(u8 **) OFF = cmsg->m + cmsg->l;
if (cmsg->m[cmsg->l] != 0xff)
cmsg->l += 1 + cmsg->m[cmsg->l];
else
cmsg->l += 3 + *(u16 *) (cmsg->m + cmsg->l + 1);
break;
case _CMSTRUCT:
if (cmsg->m[cmsg->l] == '\0') {
*(_cmstruct *) OFF = CAPI_DEFAULT;
cmsg->l++;
jumpcstruct(cmsg);
} else {
unsigned _l = cmsg->l;
*(_cmstruct *) OFF = CAPI_COMPOSE;
cmsg->l = (cmsg->m + _l)[0] == 255 ? cmsg->l + 3 : cmsg->l + 1;
cmsg->p++;
message_2_pars(cmsg);
}
break;
}
}
}
unsigned capi_message2cmsg(_cmsg * cmsg, u8 * msg)
{
memset(cmsg, 0, sizeof(_cmsg));
cmsg->m = msg;
cmsg->l = 8;
cmsg->p = 0;
byteTRcpy(cmsg->m + 4, &cmsg->Command);
byteTRcpy(cmsg->m + 5, &cmsg->Subcommand);
cmsg->par = cpars[command_2_index(cmsg->Command, cmsg->Subcommand)];
message_2_pars(cmsg);
wordTRcpy(msg + 0, &cmsg->l);
wordTRcpy(cmsg->m + 2, &cmsg->ApplId);
wordTRcpy(cmsg->m + 6, &cmsg->Messagenumber);
return 0;
}
unsigned capi_cmsg_header(_cmsg * cmsg, u16 _ApplId,
u8 _Command, u8 _Subcommand,
u16 _Messagenumber, u32 _Controller)
{
memset(cmsg, 0, sizeof(_cmsg));
cmsg->ApplId = _ApplId;
cmsg->Command = _Command;
cmsg->Subcommand = _Subcommand;
cmsg->Messagenumber = _Messagenumber;
cmsg->adr.adrController = _Controller;
return 0;
}
char *capi_cmd2str(u8 cmd, u8 subcmd)
{
return mnames[command_2_index(cmd, subcmd)];
}
static _cdebbuf *bufprint(_cdebbuf *cdb, char *fmt,...)
{
va_list f;
size_t n,r;
if (!cdb)
return NULL;
va_start(f, fmt);
r = cdb->size - cdb->pos;
n = vsnprintf(cdb->p, r, fmt, f);
va_end(f);
if (n >= r) {
size_t ns = 2 * cdb->size;
u_char *nb;
while ((ns - cdb->pos) <= n)
ns *= 2;
nb = kmalloc(ns, GFP_ATOMIC);
if (!nb) {
cdebbuf_free(cdb);
return NULL;
}
memcpy(nb, cdb->buf, cdb->pos);
kfree(cdb->buf);
nb[cdb->pos] = 0;
cdb->buf = nb;
cdb->p = cdb->buf + cdb->pos;
cdb->size = ns;
va_start(f, fmt);
r = cdb->size - cdb->pos;
n = vsnprintf(cdb->p, r, fmt, f);
va_end(f);
}
cdb->p += n;
cdb->pos += n;
return cdb;
}
static _cdebbuf *printstructlen(_cdebbuf *cdb, u8 * m, unsigned len)
{
unsigned hex = 0;
if (!cdb)
return NULL;
for (; len; len--, m++)
if (isalnum(*m) || *m == ' ') {
if (hex)
cdb = bufprint(cdb, ">");
cdb = bufprint(cdb, "%c", *m);
hex = 0;
} else {
if (!hex)
cdb = bufprint(cdb, "<%02x", *m);
else
cdb = bufprint(cdb, " %02x", *m);
hex = 1;
}
if (hex)
cdb = bufprint(cdb, ">");
return cdb;
}
static _cdebbuf *printstruct(_cdebbuf *cdb, u8 * m)
{
unsigned len;
if (m[0] != 0xff) {
len = m[0];
m += 1;
} else {
len = ((u16 *) (m + 1))[0];
m += 3;
}
cdb = printstructlen(cdb, m, len);
return cdb;
}
static _cdebbuf *protocol_message_2_pars(_cdebbuf *cdb, _cmsg *cmsg, int level)
{
for (; TYP != _CEND; cmsg->p++) {
int slen = 29 + 3 - level;
int i;
if (!cdb)
return NULL;
cdb = bufprint(cdb, " ");
for (i = 0; i < level - 1; i++)
cdb = bufprint(cdb, " ");
switch (TYP) {
case _CBYTE:
cdb = bufprint(cdb, "%-*s = 0x%x\n", slen, NAME, *(u8 *) (cmsg->m + cmsg->l));
cmsg->l++;
break;
case _CWORD:
cdb = bufprint(cdb, "%-*s = 0x%x\n", slen, NAME, *(u16 *) (cmsg->m + cmsg->l));
cmsg->l += 2;
break;
case _CDWORD:
cdb = bufprint(cdb, "%-*s = 0x%lx\n", slen, NAME, *(u32 *) (cmsg->m + cmsg->l));
cmsg->l += 4;
break;
case _CSTRUCT:
cdb = bufprint(cdb, "%-*s = ", slen, NAME);
if (cmsg->m[cmsg->l] == '\0')
cdb = bufprint(cdb, "default");
else
cdb = printstruct(cdb, cmsg->m + cmsg->l);
cdb = bufprint(cdb, "\n");
if (cmsg->m[cmsg->l] != 0xff)
cmsg->l += 1 + cmsg->m[cmsg->l];
else
cmsg->l += 3 + *(u16 *) (cmsg->m + cmsg->l + 1);
break;
case _CMSTRUCT:
if (cmsg->m[cmsg->l] == '\0') {
cdb = bufprint(cdb, "%-*s = default\n", slen, NAME);
cmsg->l++;
jumpcstruct(cmsg);
} else {
char *name = NAME;
unsigned _l = cmsg->l;
cdb = bufprint(cdb, "%-*s\n", slen, name);
cmsg->l = (cmsg->m + _l)[0] == 255 ? cmsg->l + 3 : cmsg->l + 1;
cmsg->p++;
cdb = protocol_message_2_pars(cdb, cmsg, level + 1);
}
break;
}
}
return cdb;
}
static _cdebbuf *cdebbuf_alloc(void)
{
_cdebbuf *cdb;
if (likely(!test_and_set_bit(1, &g_debbuf_lock))) {
cdb = g_debbuf;
goto init;
} else
cdb = kmalloc(sizeof(_cdebbuf), GFP_ATOMIC);
if (!cdb)
return NULL;
cdb->buf = kmalloc(CDEBUG_SIZE, GFP_ATOMIC);
if (!cdb->buf) {
kfree(cdb);
return NULL;
}
cdb->size = CDEBUG_SIZE;
init:
cdb->buf[0] = 0;
cdb->p = cdb->buf;
cdb->pos = 0;
return cdb;
}
void cdebbuf_free(_cdebbuf *cdb)
{
if (likely(cdb == g_debbuf)) {
test_and_clear_bit(1, &g_debbuf_lock);
return;
}
if (likely(cdb))
kfree(cdb->buf);
kfree(cdb);
}
_cdebbuf *capi_message2str(u8 * msg)
{
_cdebbuf *cdb;
_cmsg *cmsg;
cdb = cdebbuf_alloc();
if (unlikely(!cdb))
return NULL;
if (likely(cdb == g_debbuf))
cmsg = g_cmsg;
else
cmsg = kmalloc(sizeof(_cmsg), GFP_ATOMIC);
if (unlikely(!cmsg)) {
cdebbuf_free(cdb);
return NULL;
}
cmsg->m = msg;
cmsg->l = 8;
cmsg->p = 0;
byteTRcpy(cmsg->m + 4, &cmsg->Command);
byteTRcpy(cmsg->m + 5, &cmsg->Subcommand);
cmsg->par = cpars[command_2_index(cmsg->Command, cmsg->Subcommand)];
cdb = bufprint(cdb, "%-26s ID=%03d #0x%04x LEN=%04d\n",
mnames[command_2_index(cmsg->Command, cmsg->Subcommand)],
((unsigned short *) msg)[1],
((unsigned short *) msg)[3],
((unsigned short *) msg)[0]);
cdb = protocol_message_2_pars(cdb, cmsg, 1);
if (unlikely(cmsg != g_cmsg))
kfree(cmsg);
return cdb;
}
_cdebbuf *capi_cmsg2str(_cmsg * cmsg)
{
_cdebbuf *cdb;
if (!cmsg->m)
return NULL;
cdb = cdebbuf_alloc();
if (!cdb)
return NULL;
cmsg->l = 8;
cmsg->p = 0;
cdb = bufprint(cdb, "%s ID=%03d #0x%04x LEN=%04d\n",
mnames[command_2_index(cmsg->Command, cmsg->Subcommand)],
((u16 *) cmsg->m)[1],
((u16 *) cmsg->m)[3],
((u16 *) cmsg->m)[0]);
cdb = protocol_message_2_pars(cdb, cmsg, 1);
return cdb;
}
int __init cdebug_init(void)
{
g_cmsg= kmalloc(sizeof(_cmsg), GFP_KERNEL);
if (!g_cmsg)
return -ENOMEM;
g_debbuf = kmalloc(sizeof(_cdebbuf), GFP_KERNEL);
if (!g_debbuf) {
kfree(g_cmsg);
return -ENOMEM;
}
g_debbuf->buf = kmalloc(CDEBUG_GSIZE, GFP_KERNEL);
if (!g_debbuf->buf) {
kfree(g_cmsg);
kfree(g_debbuf);
return -ENOMEM;
}
g_debbuf->size = CDEBUG_GSIZE;
g_debbuf->buf[0] = 0;
g_debbuf->p = g_debbuf->buf;
g_debbuf->pos = 0;
return 0;
}
void __exit cdebug_exit(void)
{
if (g_debbuf)
kfree(g_debbuf->buf);
kfree(g_debbuf);
kfree(g_cmsg);
}
_cdebbuf *capi_message2str(u8 * msg)
{
return &g_debbuf;
}
_cdebbuf *capi_cmsg2str(_cmsg * cmsg)
{
return &g_debbuf;
}
void cdebbuf_free(_cdebbuf *cdb)
{
}
int __init cdebug_init(void)
{
return 0;
}
void __exit cdebug_exit(void)
{
}
