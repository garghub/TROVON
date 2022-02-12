static void varbuf_init(varbuf_t *b, char *buf, uint size)
{
b->size = size;
b->base = b->buf = buf;
}
static int varbuf_append(varbuf_t *b, const char *fmt, ...)
{
va_list ap;
int r;
size_t len;
char *s;
if (b->size < 2)
return 0;
va_start(ap, fmt);
r = vsnprintf(b->buf, b->size, fmt, ap);
va_end(ap);
if ((r == -1) || (r > (int)(b->size - 2))) {
b->size = 0;
return 0;
}
s = strchr(b->buf, '=');
if (s != NULL) {
len = (size_t) (s - b->buf);
for (s = b->base; s < b->buf;) {
if ((memcmp(s, b->buf, len) == 0) && s[len] == '=') {
len = strlen(s) + 1;
memmove(s, (s + len),
((b->buf + r + 1) - (s + len)));
b->buf -= len;
b->size += (unsigned int)len;
break;
}
while (*s++)
;
}
}
r++;
b->size -= r;
b->buf += r;
return r;
}
int srom_var_init(si_t *sih, uint bustype, void *curmap,
char **vars, uint *count)
{
uint len;
len = 0;
if (vars == NULL || count == NULL)
return 0;
*vars = NULL;
*count = 0;
switch (bustype) {
case SI_BUS:
case JTAG_BUS:
return initvars_srom_si(sih, curmap, vars, count);
case PCI_BUS:
if (curmap == NULL)
return -1;
return initvars_srom_pci(sih, curmap, vars, count);
default:
break;
}
return -1;
}
static u16
srom_cc_cmd(si_t *sih, void *ccregs, u32 cmd,
uint wordoff, u16 data)
{
chipcregs_t *cc = (chipcregs_t *) ccregs;
uint wait_cnt = 1000;
if ((cmd == SRC_OP_READ) || (cmd == SRC_OP_WRITE)) {
W_REG(&cc->sromaddress, wordoff * 2);
if (cmd == SRC_OP_WRITE)
W_REG(&cc->sromdata, data);
}
W_REG(&cc->sromcontrol, SRC_START | cmd);
while (wait_cnt--) {
if ((R_REG(&cc->sromcontrol) & SRC_BUSY) == 0)
break;
}
if (!wait_cnt) {
return 0xffff;
}
if (cmd == SRC_OP_READ)
return (u16) R_REG(&cc->sromdata);
else
return 0xffff;
}
static inline void ltoh16_buf(u16 *buf, unsigned int size)
{
for (size /= 2; size; size--)
*(buf + size) = le16_to_cpu(*(buf + size));
}
static inline void htol16_buf(u16 *buf, unsigned int size)
{
for (size /= 2; size; size--)
*(buf + size) = cpu_to_le16(*(buf + size));
}
static int
sprom_read_pci(si_t *sih, u16 *sprom, uint wordoff,
u16 *buf, uint nwords, bool check_crc)
{
int err = 0;
uint i;
void *ccregs = NULL;
for (i = 0; i < nwords; i++) {
if (sih->ccrev > 31 && ISSIM_ENAB(sih)) {
if ((sih->cccaps & CC_CAP_SROM) == 0)
return 1;
ccregs = (void *)((u8 *) sprom - CC_SROM_OTP);
buf[i] =
srom_cc_cmd(sih, ccregs, SRC_OP_READ,
wordoff + i, 0);
} else {
if (ISSIM_ENAB(sih))
buf[i] = R_REG(&sprom[wordoff + i]);
buf[i] = R_REG(&sprom[wordoff + i]);
}
}
if (ISSIM_ENAB(sih))
return err;
if (check_crc) {
if (buf[0] == 0xffff) {
return 1;
}
htol16_buf(buf, nwords * 2);
if (bcm_crc8((u8 *) buf, nwords * 2, CRC8_INIT_VALUE) !=
CRC8_GOOD_VALUE) {
err = 1;
}
ltoh16_buf(buf, nwords * 2);
}
return err;
}
static int otp_read_pci(si_t *sih, u16 *buf, uint bufsz)
{
u8 *otp;
uint sz = OTP_SZ_MAX / 2;
int err = 0;
otp = kzalloc(OTP_SZ_MAX, GFP_ATOMIC);
if (otp == NULL) {
return -EBADE;
}
err = otp_read_region(sih, OTP_HW_RGN, (u16 *) otp, &sz);
memcpy(buf, otp, bufsz);
kfree(otp);
if (buf[0] == 0xffff) {
return 1;
}
htol16_buf(buf, bufsz);
if (bcm_crc8((u8 *) buf, SROM4_WORDS * 2, CRC8_INIT_VALUE) !=
CRC8_GOOD_VALUE) {
err = 1;
}
ltoh16_buf(buf, bufsz);
return err;
}
static int initvars_table(char *start, char *end,
char **vars, uint *count)
{
int c = (int)(end - start);
if (c > 1) {
char *vp = kmalloc(c, GFP_ATOMIC);
if (!vp)
return -ENOMEM;
memcpy(vp, start, c);
*vars = vp;
*count = c;
} else {
*vars = NULL;
*count = 0;
}
return 0;
}
static int initvars_flash(si_t *sih, char **base, uint len)
{
char *vp = *base;
char *flash;
int err;
char *s;
uint l, dl, copy_len;
char devpath[SI_DEVPATH_BUFSZ];
flash = kmalloc(NVRAM_SPACE, GFP_ATOMIC);
if (!flash)
return -ENOMEM;
err = nvram_getall(flash, NVRAM_SPACE);
if (err)
goto exit;
ai_devpath(sih, devpath, sizeof(devpath));
dl = strlen(devpath);
for (s = flash; s && *s; s += l + 1) {
l = strlen(s);
if (strncmp(s, devpath, dl))
continue;
copy_len = l - dl + 1;
if (len < copy_len) {
err = -EOVERFLOW;
goto exit;
}
strncpy(vp, &s[dl], copy_len);
vp += copy_len;
len -= copy_len;
}
if (len < 1) {
err = -EOVERFLOW;
goto exit;
}
*vp++ = '\0';
*base = vp;
exit: kfree(flash);
return err;
}
static int initvars_flash_si(si_t *sih, char **vars, uint *count)
{
char *vp, *base;
int err;
base = vp = kmalloc(MAXSZ_NVRAM_VARS, GFP_ATOMIC);
if (!vp)
return -ENOMEM;
err = initvars_flash(sih, &vp, MAXSZ_NVRAM_VARS);
if (err == 0)
err = initvars_table(base, vp, vars, count);
kfree(base);
return err;
}
static uint mask_shift(u16 mask)
{
uint i;
for (i = 0; i < (sizeof(mask) << 3); i++) {
if (mask & (1 << i))
return i;
}
return 0;
}
static uint mask_width(u16 mask)
{
int i;
for (i = (sizeof(mask) << 3) - 1; i >= 0; i--) {
if (mask & (1 << i))
return (uint) (i - mask_shift(mask) + 1);
}
return 0;
}
static void _initvars_srom_pci(u8 sromrev, u16 *srom, uint off, varbuf_t *b)
{
u16 w;
u32 val;
const sromvar_t *srv;
uint width;
uint flags;
u32 sr = (1 << sromrev);
varbuf_append(b, "sromrev=%d", sromrev);
for (srv = pci_sromvars; srv->name != NULL; srv++) {
const char *name;
if ((srv->revmask & sr) == 0)
continue;
if (srv->off < off)
continue;
flags = srv->flags;
name = srv->name;
if (flags & SRFL_NOVAR)
continue;
if (flags & SRFL_ETHADDR) {
u8 ea[ETH_ALEN];
ea[0] = (srom[srv->off - off] >> 8) & 0xff;
ea[1] = srom[srv->off - off] & 0xff;
ea[2] = (srom[srv->off + 1 - off] >> 8) & 0xff;
ea[3] = srom[srv->off + 1 - off] & 0xff;
ea[4] = (srom[srv->off + 2 - off] >> 8) & 0xff;
ea[5] = srom[srv->off + 2 - off] & 0xff;
varbuf_append(b, "%s=%pM", name, ea);
} else {
w = srom[srv->off - off];
val = (w & srv->mask) >> mask_shift(srv->mask);
width = mask_width(srv->mask);
while (srv->flags & SRFL_MORE) {
srv++;
if (srv->off == 0 || srv->off < off)
continue;
w = srom[srv->off - off];
val +=
((w & srv->mask) >> mask_shift(srv->
mask)) <<
width;
width += mask_width(srv->mask);
}
if ((flags & SRFL_NOFFS)
&& ((int)val == (1 << width) - 1))
continue;
if (flags & SRFL_CCODE) {
if (val == 0)
varbuf_append(b, "ccode=");
else
varbuf_append(b, "ccode=%c%c",
(val >> 8), (val & 0xff));
}
else if (flags & SRFL_LEDDC) {
u32 w32 = (((val >> 8) & 0xff) << 24) |
(((val & 0xff)) << 8);
varbuf_append(b, "leddc=%d", w32);
} else if (flags & SRFL_PRHEX)
varbuf_append(b, "%s=0x%x", name, val);
else if ((flags & SRFL_PRSIGN)
&& (val & (1 << (width - 1))))
varbuf_append(b, "%s=%d", name,
(int)(val | (~0 << width)));
else
varbuf_append(b, "%s=%u", name, val);
}
}
if (sromrev >= 4) {
uint p, pb, psz;
if (sromrev >= 8) {
pb = SROM8_PATH0;
psz = SROM8_PATH1 - SROM8_PATH0;
} else {
pb = SROM4_PATH0;
psz = SROM4_PATH1 - SROM4_PATH0;
}
for (p = 0; p < MAX_PATH_SROM; p++) {
for (srv = perpath_pci_sromvars; srv->name != NULL;
srv++) {
if ((srv->revmask & sr) == 0)
continue;
if (pb + srv->off < off)
continue;
if (srv->flags & SRFL_NOVAR)
continue;
w = srom[pb + srv->off - off];
val = (w & srv->mask) >> mask_shift(srv->mask);
width = mask_width(srv->mask);
if ((srv->flags & SRFL_NOFFS)
&& ((int)val == (1 << width) - 1))
continue;
if (srv->flags & SRFL_PRHEX)
varbuf_append(b, "%s%d=0x%x", srv->name,
p, val);
else
varbuf_append(b, "%s%d=%d", srv->name,
p, val);
}
pb += psz;
}
}
}
static int initvars_srom_pci(si_t *sih, void *curmap, char **vars, uint *count)
{
u16 *srom, *sromwindow;
u8 sromrev = 0;
u32 sr;
varbuf_t b;
char *vp, *base = NULL;
bool flash = false;
int err = 0;
srom = kmalloc(SROM_MAX, GFP_ATOMIC);
if (!srom)
return -2;
sromwindow = (u16 *) SROM_OFFSET(sih);
if (ai_is_sprom_available(sih)) {
err =
sprom_read_pci(sih, sromwindow, 0, srom, SROM_WORDS,
true);
if ((srom[SROM4_SIGN] == SROM4_SIGNATURE) ||
(((sih->buscoretype == PCIE_CORE_ID)
&& (sih->buscorerev >= 6))
|| ((sih->buscoretype == PCI_CORE_ID)
&& (sih->buscorerev >= 0xe)))) {
err =
sprom_read_pci(sih, sromwindow, 0, srom,
SROM4_WORDS, true);
sromrev = srom[SROM4_CRCREV] & 0xff;
} else if (err == 0) {
sromrev = srom[SROM_CRCREV] & 0xff;
if (sromrev == 0x10)
sromrev = 1;
}
}
#if defined(BCMNVRAMR)
else {
err = otp_read_pci(sih, srom, SROM_MAX);
if (err == 0)
sromrev = srom[SROM4_CRCREV] & 0xff;
else
err = 1;
}
#else
else
err = 1;
#endif
if (err) {
char *value;
u32 val;
val = 0;
value = ai_getdevpathvar(sih, "sromrev");
if (value) {
sromrev = (u8) simple_strtoul(value, NULL, 0);
flash = true;
goto varscont;
}
value = ai_getnvramflvar(sih, "sromrev");
if (value) {
err = 0;
goto errout;
}
{
err = -1;
goto errout;
}
}
varscont:
sr = 1 << sromrev;
if ((sr & 0x33e) == 0) {
err = -2;
goto errout;
}
base = vp = kmalloc(MAXSZ_NVRAM_VARS, GFP_ATOMIC);
if (!vp) {
err = -2;
goto errout;
}
if (flash) {
err = initvars_flash(sih, &vp, MAXSZ_NVRAM_VARS);
if (err)
goto errout;
goto varsdone;
}
varbuf_init(&b, base, MAXSZ_NVRAM_VARS);
_initvars_srom_pci(sromrev, srom, 0, &b);
vp = b.buf;
*vp++ = '\0';
varsdone:
err = initvars_table(base, vp, vars, count);
errout:
if (base)
kfree(base);
kfree(srom);
return err;
}
static int initvars_srom_si(si_t *sih, void *curmap, char **vars, uint *varsz)
{
return initvars_flash_si(sih, vars, varsz);
}
