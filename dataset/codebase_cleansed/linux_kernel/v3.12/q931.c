void
iecpy(u_char *dest, u_char *iestart, int ieoffset)
{
u_char *p;
int l;
p = iestart + ieoffset + 2;
l = iestart[1] - ieoffset;
while (l--)
*dest++ = *p++;
*dest++ = '\0';
}
static int
prbits(char *dest, u_char b, int start, int len)
{
char *dp = dest;
b = b << (8 - start);
while (len--) {
if (b & 0x80)
*dp++ = '1';
else
*dp++ = '0';
b = b << 1;
}
return (dp - dest);
}
static
u_char *
skipext(u_char *p)
{
while (!(*p++ & 0x80));
return (p);
}
static
int
prcause(char *dest, u_char *p)
{
u_char *end;
char *dp = dest;
int i, cause;
end = p + p[1] + 1;
p += 2;
dp += sprintf(dp, " coding ");
dp += prbits(dp, *p, 7, 2);
dp += sprintf(dp, " location ");
dp += prbits(dp, *p, 4, 4);
*dp++ = '\n';
p = skipext(p);
cause = 0x7f & *p++;
for (i = 0; i < CVSIZE; i++)
if (cvlist[i].nr == cause)
break;
if (i == CVSIZE)
dp += sprintf(dp, "Unknown cause type %x!\n", cause);
else
dp += sprintf(dp, " cause value %x : %s \n", cause, cvlist[i].edescr);
while (!0) {
if (p > end)
break;
dp += sprintf(dp, " diag attribute %d ", *p++ & 0x7f);
dp += sprintf(dp, " rej %d ", *p & 0x7f);
if (*p & 0x80) {
*dp++ = '\n';
break;
} else
dp += sprintf(dp, " av %d\n", (*++p) & 0x7f);
}
return (dp - dest);
}
static int
prcause_1tr6(char *dest, u_char *p)
{
char *dp = dest;
int i, cause;
p++;
if (0 == *p) {
dp += sprintf(dp, " OK (cause length=0)\n");
return (dp - dest);
} else if (*p > 1) {
dp += sprintf(dp, " coding ");
dp += prbits(dp, p[2], 7, 2);
dp += sprintf(dp, " location ");
dp += prbits(dp, p[2], 4, 4);
*dp++ = '\n';
}
p++;
cause = 0x7f & *p;
for (i = 0; i < cause_1tr6_len; i++)
if (cause_1tr6[i].nr == cause)
break;
if (i == cause_1tr6_len)
dp += sprintf(dp, "Unknown cause type %x!\n", cause);
else
dp += sprintf(dp, " cause value %x : %s \n", cause, cause_1tr6[i].descr);
return (dp - dest);
}
static int
prchident(char *dest, u_char *p)
{
char *dp = dest;
p += 2;
dp += sprintf(dp, " octet 3 ");
dp += prbits(dp, *p, 8, 8);
*dp++ = '\n';
return (dp - dest);
}
static int
prcalled(char *dest, u_char *p)
{
int l;
char *dp = dest;
p++;
l = *p++ - 1;
dp += sprintf(dp, " octet 3 ");
dp += prbits(dp, *p++, 8, 8);
*dp++ = '\n';
dp += sprintf(dp, " number digits ");
while (l--)
*dp++ = *p++;
*dp++ = '\n';
return (dp - dest);
}
static int
prcalling(char *dest, u_char *p)
{
int l;
char *dp = dest;
p++;
l = *p++ - 1;
dp += sprintf(dp, " octet 3 ");
dp += prbits(dp, *p, 8, 8);
*dp++ = '\n';
if (!(*p & 0x80)) {
dp += sprintf(dp, " octet 3a ");
dp += prbits(dp, *++p, 8, 8);
*dp++ = '\n';
l--;
};
p++;
dp += sprintf(dp, " number digits ");
while (l--)
*dp++ = *p++;
*dp++ = '\n';
return (dp - dest);
}
static
int
prbearer(char *dest, u_char *p)
{
char *dp = dest, ch;
p += 2;
dp += sprintf(dp, " octet 3 ");
dp += prbits(dp, *p++, 8, 8);
*dp++ = '\n';
dp += sprintf(dp, " octet 4 ");
dp += prbits(dp, *p, 8, 8);
*dp++ = '\n';
if ((*p++ & 0x1f) == 0x18) {
dp += sprintf(dp, " octet 4.1 ");
dp += prbits(dp, *p++, 8, 8);
*dp++ = '\n';
}
if ((*p & 0x60) == 0x20) {
ch = ' ';
do {
dp += sprintf(dp, " octet 5%c ", ch);
dp += prbits(dp, *p, 8, 8);
*dp++ = '\n';
if (ch == ' ')
ch = 'a';
else
ch++;
}
while (!(*p++ & 0x80));
}
if ((*p & 0x60) == 0x40) {
dp += sprintf(dp, " octet 6 ");
dp += prbits(dp, *p++, 8, 8);
*dp++ = '\n';
}
if ((*p & 0x60) == 0x60) {
dp += sprintf(dp, " octet 7 ");
dp += prbits(dp, *p++, 8, 8);
*dp++ = '\n';
}
return (dp - dest);
}
static
int
prbearer_ni1(char *dest, u_char *p)
{
char *dp = dest;
u_char len;
p++;
len = *p++;
dp += sprintf(dp, " octet 3 ");
dp += prbits(dp, *p, 8, 8);
switch (*p++) {
case 0x80:
dp += sprintf(dp, " Speech");
break;
case 0x88:
dp += sprintf(dp, " Unrestricted digital information");
break;
case 0x90:
dp += sprintf(dp, " 3.1 kHz audio");
break;
default:
dp += sprintf(dp, " Unknown information-transfer capability");
}
*dp++ = '\n';
dp += sprintf(dp, " octet 4 ");
dp += prbits(dp, *p, 8, 8);
switch (*p++) {
case 0x90:
dp += sprintf(dp, " 64 kbps, circuit mode");
break;
case 0xc0:
dp += sprintf(dp, " Packet mode");
break;
default:
dp += sprintf(dp, " Unknown transfer mode");
}
*dp++ = '\n';
if (len > 2) {
dp += sprintf(dp, " octet 5 ");
dp += prbits(dp, *p, 8, 8);
switch (*p++) {
case 0x21:
dp += sprintf(dp, " Rate adaption\n");
dp += sprintf(dp, " octet 5a ");
dp += prbits(dp, *p, 8, 8);
break;
case 0xa2:
dp += sprintf(dp, " u-law");
break;
default:
dp += sprintf(dp, " Unknown UI layer 1 protocol");
}
*dp++ = '\n';
}
return (dp - dest);
}
static int
general(char *dest, u_char *p)
{
char *dp = dest;
char ch = ' ';
int l, octet = 3;
p++;
l = *p++;
while (l--) {
dp += sprintf(dp, " octet %d%c ", octet, ch);
dp += prbits(dp, *p++, 8, 8);
*dp++ = '\n';
if (*p & 0x80) {
octet++;
ch = ' ';
} else if (ch == ' ')
ch = 'a';
else
ch++;
}
return (dp - dest);
}
static int
general_ni1(char *dest, u_char *p)
{
char *dp = dest;
char ch = ' ';
int l, octet = 3;
p++;
l = *p++;
while (l--) {
dp += sprintf(dp, " octet %d%c ", octet, ch);
dp += prbits(dp, *p, 8, 8);
*dp++ = '\n';
if (*p++ & 0x80) {
octet++;
ch = ' ';
} else if (ch == ' ')
ch = 'a';
else
ch++;
}
return (dp - dest);
}
static int
prcharge(char *dest, u_char *p)
{
char *dp = dest;
int l;
p++;
l = *p++ - 1;
dp += sprintf(dp, " GEA ");
dp += prbits(dp, *p++, 8, 8);
dp += sprintf(dp, " Anzahl: ");
while (l--)
*dp++ = *p++;
*dp++ = '\n';
return (dp - dest);
}
static int
prtext(char *dest, u_char *p)
{
char *dp = dest;
int l;
p++;
l = *p++;
dp += sprintf(dp, " ");
while (l--)
*dp++ = *p++;
*dp++ = '\n';
return (dp - dest);
}
static int
prfeatureind(char *dest, u_char *p)
{
char *dp = dest;
p += 2;
dp += sprintf(dp, " octet 3 ");
dp += prbits(dp, *p, 8, 8);
*dp++ = '\n';
if (!(*p++ & 80)) {
dp += sprintf(dp, " octet 4 ");
dp += prbits(dp, *p++, 8, 8);
*dp++ = '\n';
}
dp += sprintf(dp, " Status: ");
switch (*p) {
case 0:
dp += sprintf(dp, "Idle");
break;
case 1:
dp += sprintf(dp, "Active");
break;
case 2:
dp += sprintf(dp, "Prompt");
break;
case 3:
dp += sprintf(dp, "Pending");
break;
default:
dp += sprintf(dp, "(Reserved)");
break;
}
*dp++ = '\n';
return (dp - dest);
}
static int
disptext_ni1(char *dest, u_char *p)
{
char *dp = dest;
int l, tag, len, i;
p++;
l = *p++ - 1;
if (*p++ != 0x80) {
dp += sprintf(dp, " Unknown display type\n");
return (dp - dest);
}
while (l > 0) {
tag = *p++;
len = *p++;
l -= len + 2;
if ((tag == 0x80) || (tag == 0x81)) p++;
else {
for (i = 0; i < DTAGSIZE; i++)
if (tag == dtaglist[i].nr)
break;
if (i != DTAGSIZE) {
dp += sprintf(dp, " %s: ", dtaglist[i].descr);
while (len--)
*dp++ = *p++;
} else {
dp += sprintf(dp, " (unknown display tag %2x): ", tag);
while (len--)
*dp++ = *p++;
}
dp += sprintf(dp, "\n");
}
}
return (dp - dest);
}
static int
display(char *dest, u_char *p)
{
char *dp = dest;
char ch = ' ';
int l, octet = 3;
p++;
l = *p++;
dp += sprintf(dp, " \"");
while (l--) {
dp += sprintf(dp, "%c", *p++);
if (*p & 0x80) {
octet++;
ch = ' ';
} else if (ch == ' ')
ch = 'a';
else
ch++;
}
*dp++ = '\"';
*dp++ = '\n';
return (dp - dest);
}
static int
prfacility(char *dest, u_char *p)
{
char *dp = dest;
int l, l2;
p++;
l = *p++;
dp += sprintf(dp, " octet 3 ");
dp += prbits(dp, *p++, 8, 8);
dp += sprintf(dp, "\n");
l -= 1;
while (l > 0) {
dp += sprintf(dp, " octet 4 ");
dp += prbits(dp, *p++, 8, 8);
dp += sprintf(dp, "\n");
dp += sprintf(dp, " octet 5 %d\n", l2 = *p++ & 0x7f);
l -= 2;
dp += sprintf(dp, " contents ");
while (l2--) {
dp += sprintf(dp, "%2x ", *p++);
l--;
}
dp += sprintf(dp, "\n");
}
return (dp - dest);
}
int
QuickHex(char *txt, u_char *p, int cnt)
{
register int i;
register char *t = txt;
for (i = 0; i < cnt; i++) {
*t++ = ' ';
*t++ = hex_asc_hi(p[i]);
*t++ = hex_asc_lo(p[i]);
}
*t++ = 0;
return (t - txt);
}
void
LogFrame(struct IsdnCardState *cs, u_char *buf, int size)
{
char *dp;
if (size < 1)
return;
dp = cs->dlog;
if (size < MAX_DLOG_SPACE / 3 - 10) {
*dp++ = 'H';
*dp++ = 'E';
*dp++ = 'X';
*dp++ = ':';
dp += QuickHex(dp, buf, size);
dp--;
*dp++ = '\n';
*dp = 0;
HiSax_putstatus(cs, NULL, "%s", cs->dlog);
} else
HiSax_putstatus(cs, "LogFrame: ", "warning Frame too big (%d)", size);
}
void
dlogframe(struct IsdnCardState *cs, struct sk_buff *skb, int dir)
{
u_char *bend, *buf;
char *dp;
unsigned char pd, cr_l, cr, mt;
unsigned char sapi, tei, ftyp;
int i, cset = 0, cs_old = 0, cs_fest = 0;
int size, finish = 0;
if (skb->len < 3)
return;
dp = cs->dlog;
dp += jiftime(dp, jiffies);
*dp++ = ' ';
sapi = skb->data[0] >> 2;
tei = skb->data[1] >> 1;
ftyp = skb->data[2];
buf = skb->data;
dp += sprintf(dp, "frame %s ", dir ? "network->user" : "user->network");
size = skb->len;
if (tei == GROUP_TEI) {
if (sapi == CTRL_SAPI) {
if (ftyp == 3) {
dp += sprintf(dp, "broadcast\n");
buf += 3;
size -= 3;
} else {
dp += sprintf(dp, "no UI broadcast\n");
finish = 1;
}
} else if (sapi == TEI_SAPI) {
dp += sprintf(dp, "tei management\n");
finish = 1;
} else {
dp += sprintf(dp, "unknown sapi %d broadcast\n", sapi);
finish = 1;
}
} else {
if (sapi == CTRL_SAPI) {
if (!(ftyp & 1)) {
dp += sprintf(dp, "with tei %d\n", tei);
buf += 4;
size -= 4;
} else {
dp += sprintf(dp, "SFrame with tei %d\n", tei);
finish = 1;
}
} else {
dp += sprintf(dp, "unknown sapi %d tei %d\n", sapi, tei);
finish = 1;
}
}
bend = skb->data + skb->len;
if (buf >= bend) {
dp += sprintf(dp, "frame too short\n");
finish = 1;
}
if (finish) {
*dp = 0;
HiSax_putstatus(cs, NULL, "%s", cs->dlog);
return;
}
if ((0xfe & buf[0]) == PROTO_DIS_N0) {
pd = *buf++;
cr_l = *buf++;
if (cr_l)
cr = *buf++;
else
cr = 0;
mt = *buf++;
if (pd == PROTO_DIS_N0) {
for (i = 0; i < MT_N0_LEN; i++)
if (mt_n0[i].nr == mt)
break;
if (i == MT_N0_LEN)
dp += sprintf(dp, "callref %d %s size %d unknown message type N0 %x!\n",
cr & 0x7f, (cr & 0x80) ? "called" : "caller",
size, mt);
else
dp += sprintf(dp, "callref %d %s size %d message type %s\n",
cr & 0x7f, (cr & 0x80) ? "called" : "caller",
size, mt_n0[i].descr);
} else {
for (i = 0; i < MT_N1_LEN; i++)
if (mt_n1[i].nr == mt)
break;
if (i == MT_N1_LEN)
dp += sprintf(dp, "callref %d %s size %d unknown message type N1 %x!\n",
cr & 0x7f, (cr & 0x80) ? "called" : "caller",
size, mt);
else
dp += sprintf(dp, "callref %d %s size %d message type %s\n",
cr & 0x7f, (cr & 0x80) ? "called" : "caller",
size, mt_n1[i].descr);
}
while (buf < bend) {
if (*buf & 0x80) {
switch ((*buf >> 4) & 7) {
case 1:
dp += sprintf(dp, " Shift %x\n", *buf & 0xf);
cs_old = cset;
cset = *buf & 7;
cs_fest = *buf & 8;
break;
case 3:
dp += sprintf(dp, " Congestion level %x\n", *buf & 0xf);
break;
case 2:
if (*buf == 0xa0) {
dp += sprintf(dp, " More data\n");
break;
}
if (*buf == 0xa1) {
dp += sprintf(dp, " Sending complete\n");
}
break;
default:
dp += sprintf(dp, " Reserved %x\n", *buf);
break;
}
buf++;
continue;
}
if (cset == 0) {
for (i = 0; i < WE_0_LEN; i++)
if (*buf == we_0[i].nr)
break;
if (i != WE_0_LEN) {
dp += sprintf(dp, " %s\n", we_0[i].descr);
dp += we_0[i].f(dp, buf);
} else
dp += sprintf(dp, " Codeset %d attribute %x attribute size %d\n", cset, *buf, buf[1]);
} else if (cset == 6) {
for (i = 0; i < WE_6_LEN; i++)
if (*buf == we_6[i].nr)
break;
if (i != WE_6_LEN) {
dp += sprintf(dp, " %s\n", we_6[i].descr);
dp += we_6[i].f(dp, buf);
} else
dp += sprintf(dp, " Codeset %d attribute %x attribute size %d\n", cset, *buf, buf[1]);
} else
dp += sprintf(dp, " Unknown Codeset %d attribute %x attribute size %d\n", cset, *buf, buf[1]);
if (cs_fest == 8) {
cset = cs_old;
cs_old = 0;
cs_fest = 0;
}
buf += buf[1] + 2;
}
} else if ((buf[0] == 8) && (cs->protocol == ISDN_PTYPE_NI1)) {
buf++;
cr_l = *buf++;
if (cr_l)
cr = *buf++;
else
cr = 0;
mt = *buf++;
for (i = 0; i < MTSIZE; i++)
if (mtlist[i].nr == mt)
break;
if (i == MTSIZE)
dp += sprintf(dp, "callref %d %s size %d unknown message type %x!\n",
cr & 0x7f, (cr & 0x80) ? "called" : "caller",
size, mt);
else
dp += sprintf(dp, "callref %d %s size %d message type %s\n",
cr & 0x7f, (cr & 0x80) ? "called" : "caller",
size, mtlist[i].descr);
while (buf < bend) {
if (*buf & 0x80) {
switch ((*buf >> 4) & 7) {
case 1:
dp += sprintf(dp, " Shift %x\n", *buf & 0xf);
cs_old = cset;
cset = *buf & 7;
cs_fest = *buf & 8;
break;
default:
dp += sprintf(dp, " Unknown single-octet IE %x\n", *buf);
break;
}
buf++;
continue;
}
if (cset == 0) {
for (i = 0; i < IESIZE_NI1; i++)
if (*buf == ielist_ni1[i].nr)
break;
if (i != IESIZE_NI1) {
dp += sprintf(dp, " %s\n", ielist_ni1[i].descr);
dp += ielist_ni1[i].f(dp, buf);
} else
dp += sprintf(dp, " attribute %x attribute size %d\n", *buf, buf[1]);
} else if (cset == 5) {
for (i = 0; i < IESIZE_NI1_CS5; i++)
if (*buf == ielist_ni1_cs5[i].nr)
break;
if (i != IESIZE_NI1_CS5) {
dp += sprintf(dp, " %s\n", ielist_ni1_cs5[i].descr);
dp += ielist_ni1_cs5[i].f(dp, buf);
} else
dp += sprintf(dp, " attribute %x attribute size %d\n", *buf, buf[1]);
} else if (cset == 6) {
for (i = 0; i < IESIZE_NI1_CS6; i++)
if (*buf == ielist_ni1_cs6[i].nr)
break;
if (i != IESIZE_NI1_CS6) {
dp += sprintf(dp, " %s\n", ielist_ni1_cs6[i].descr);
dp += ielist_ni1_cs6[i].f(dp, buf);
} else
dp += sprintf(dp, " attribute %x attribute size %d\n", *buf, buf[1]);
} else
dp += sprintf(dp, " Unknown Codeset %d attribute %x attribute size %d\n", cset, *buf, buf[1]);
if (cs_fest == 8) {
cset = cs_old;
cs_old = 0;
cs_fest = 0;
}
buf += buf[1] + 2;
}
} else if ((buf[0] == 8) && (cs->protocol == ISDN_PTYPE_EURO)) {
buf++;
cr_l = *buf++;
if (cr_l)
cr = *buf++;
else
cr = 0;
mt = *buf++;
for (i = 0; i < MTSIZE; i++)
if (mtlist[i].nr == mt)
break;
if (i == MTSIZE)
dp += sprintf(dp, "callref %d %s size %d unknown message type %x!\n",
cr & 0x7f, (cr & 0x80) ? "called" : "caller",
size, mt);
else
dp += sprintf(dp, "callref %d %s size %d message type %s\n",
cr & 0x7f, (cr & 0x80) ? "called" : "caller",
size, mtlist[i].descr);
while (buf < bend) {
if (*buf & 0x80) {
switch ((*buf >> 4) & 7) {
case 1:
dp += sprintf(dp, " Shift %x\n", *buf & 0xf);
break;
case 3:
dp += sprintf(dp, " Congestion level %x\n", *buf & 0xf);
break;
case 5:
dp += sprintf(dp, " Repeat indicator %x\n", *buf & 0xf);
break;
case 2:
if (*buf == 0xa0) {
dp += sprintf(dp, " More data\n");
break;
}
if (*buf == 0xa1) {
dp += sprintf(dp, " Sending complete\n");
}
break;
default:
dp += sprintf(dp, " Reserved %x\n", *buf);
break;
}
buf++;
continue;
}
for (i = 0; i < IESIZE; i++)
if (*buf == ielist[i].nr)
break;
if (i != IESIZE) {
dp += sprintf(dp, " %s\n", ielist[i].descr);
dp += ielist[i].f(dp, buf);
} else
dp += sprintf(dp, " attribute %x attribute size %d\n", *buf, buf[1]);
buf += buf[1] + 2;
}
} else {
dp += sprintf(dp, "Unknown protocol %x!", buf[0]);
}
*dp = 0;
HiSax_putstatus(cs, NULL, "%s", cs->dlog);
}
