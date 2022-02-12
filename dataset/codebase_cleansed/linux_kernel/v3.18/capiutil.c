static unsigned command_2_index(unsigned c, unsigned sc)
{
if (c & 0x80)
c = 0x9 + (c & 0x0f);
else if (c == 0x41)
c = 0x9 + 0x1;
if (c > 0x18)
c = 0x00;
return (sc & 3) * (0x9 + 0x9) + c;
}
static unsigned char *capi_cmd2par(u8 cmd, u8 subcmd)
{
return cpars[command_2_index(cmd, subcmd)];
}
static void jumpcstruct(_cmsg *cmsg)
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
static void pars_2_message(_cmsg *cmsg)
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
unsigned capi_cmsg2message(_cmsg *cmsg, u8 *msg)
{
cmsg->m = msg;
cmsg->l = 8;
cmsg->p = 0;
cmsg->par = capi_cmd2par(cmsg->Command, cmsg->Subcommand);
if (!cmsg->par)
return 1;
pars_2_message(cmsg);
wordTLcpy(msg + 0, &cmsg->l);
byteTLcpy(cmsg->m + 4, &cmsg->Command);
byteTLcpy(cmsg->m + 5, &cmsg->Subcommand);
wordTLcpy(cmsg->m + 2, &cmsg->ApplId);
wordTLcpy(cmsg->m + 6, &cmsg->Messagenumber);
return 0;
}
static void message_2_pars(_cmsg *cmsg)
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
unsigned capi_message2cmsg(_cmsg *cmsg, u8 *msg)
{
memset(cmsg, 0, sizeof(_cmsg));
cmsg->m = msg;
cmsg->l = 8;
cmsg->p = 0;
byteTRcpy(cmsg->m + 4, &cmsg->Command);
byteTRcpy(cmsg->m + 5, &cmsg->Subcommand);
cmsg->par = capi_cmd2par(cmsg->Command, cmsg->Subcommand);
if (!cmsg->par)
return 1;
message_2_pars(cmsg);
wordTRcpy(msg + 0, &cmsg->l);
wordTRcpy(cmsg->m + 2, &cmsg->ApplId);
wordTRcpy(cmsg->m + 6, &cmsg->Messagenumber);
return 0;
}
unsigned capi_cmsg_header(_cmsg *cmsg, u16 _ApplId,
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
char *result;
result = mnames[command_2_index(cmd, subcmd)];
if (result == NULL)
result = "INVALID_COMMAND";
return result;
}
static _cdebbuf *bufprint(_cdebbuf *cdb, char *fmt, ...)
{
va_list f;
size_t n, r;
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
static _cdebbuf *printstructlen(_cdebbuf *cdb, u8 *m, unsigned len)
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
static _cdebbuf *printstruct(_cdebbuf *cdb, u8 *m)
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
if (!cmsg->par)
return NULL;
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
_cdebbuf *capi_message2str(u8 *msg)
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
cmsg->par = capi_cmd2par(cmsg->Command, cmsg->Subcommand);
cdb = bufprint(cdb, "%-26s ID=%03d #0x%04x LEN=%04d\n",
capi_cmd2str(cmsg->Command, cmsg->Subcommand),
((unsigned short *) msg)[1],
((unsigned short *) msg)[3],
((unsigned short *) msg)[0]);
cdb = protocol_message_2_pars(cdb, cmsg, 1);
if (unlikely(cmsg != g_cmsg))
kfree(cmsg);
return cdb;
}
_cdebbuf *capi_cmsg2str(_cmsg *cmsg)
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
capi_cmd2str(cmsg->Command, cmsg->Subcommand),
((u16 *) cmsg->m)[1],
((u16 *) cmsg->m)[3],
((u16 *) cmsg->m)[0]);
cdb = protocol_message_2_pars(cdb, cmsg, 1);
return cdb;
}
int __init cdebug_init(void)
{
g_cmsg = kmalloc(sizeof(_cmsg), GFP_KERNEL);
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
_cdebbuf *capi_message2str(u8 *msg)
{
return &g_debbuf;
}
_cdebbuf *capi_cmsg2str(_cmsg *cmsg)
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
