static int ipxotp_status(void *oh)
{
otpinfo_t *oi = (otpinfo_t *) oh;
return (int)(oi->status);
}
static int ipxotp_size(void *oh)
{
otpinfo_t *oi = (otpinfo_t *) oh;
return (int)oi->wsize * 2;
}
static u16 ipxotp_otpr(void *oh, chipcregs_t *cc, uint wn)
{
otpinfo_t *oi;
oi = (otpinfo_t *) oh;
return R_REG(&cc->sromotp[wn]);
}
static u16 ipxotp_read_bit(void *oh, chipcregs_t *cc, uint off)
{
otpinfo_t *oi = (otpinfo_t *) oh;
uint k, row, col;
u32 otpp, st;
row = off / oi->cols;
col = off % oi->cols;
otpp = OTPP_START_BUSY |
((OTPPOC_READ << OTPP_OC_SHIFT) & OTPP_OC_MASK) |
((row << OTPP_ROW_SHIFT) & OTPP_ROW_MASK) |
((col << OTPP_COL_SHIFT) & OTPP_COL_MASK);
W_REG(&cc->otpprog, otpp);
for (k = 0;
((st = R_REG(&cc->otpprog)) & OTPP_START_BUSY)
&& (k < OTPP_TRIES); k++)
;
if (k >= OTPP_TRIES) {
return 0xffff;
}
if (st & OTPP_READERR) {
return 0xffff;
}
st = (st & OTPP_VALUE_MASK) >> OTPP_VALUE_SHIFT;
return (int)st;
}
static int ipxotp_max_rgnsz(si_t *sih, int osizew)
{
int ret = 0;
switch (sih->chip) {
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
ret = osizew * 2 - OTP_SZ_FU_72 - OTP_SZ_CHECKSUM;
break;
case BCM4313_CHIP_ID:
ret = osizew * 2 - OTP_SZ_FU_72 - OTP_SZ_CHECKSUM;
break;
default:
break;
}
return ret;
}
static void _ipxotp_init(otpinfo_t *oi, chipcregs_t *cc)
{
uint k;
u32 otpp, st;
if (oi->sih->ccrev == 21 || oi->sih->ccrev == 24
|| oi->sih->ccrev == 27) {
oi->otpgu_base = REVA4_OTPGU_BASE;
} else if (oi->sih->ccrev == 36) {
if (oi->wsize >= 128)
oi->otpgu_base = REVB8_OTPGU_BASE;
else
oi->otpgu_base = REV36_OTPGU_BASE;
} else if (oi->sih->ccrev == 23 || oi->sih->ccrev >= 25) {
oi->otpgu_base = REVB8_OTPGU_BASE;
}
otpp =
OTPP_START_BUSY | ((OTPPOC_INIT << OTPP_OC_SHIFT) & OTPP_OC_MASK);
W_REG(&cc->otpprog, otpp);
for (k = 0;
((st = R_REG(&cc->otpprog)) & OTPP_START_BUSY)
&& (k < OTPP_TRIES); k++)
;
if (k >= OTPP_TRIES) {
return;
}
oi->status = R_REG(&cc->otpstatus);
if ((oi->sih->chip == BCM43224_CHIP_ID)
|| (oi->sih->chip == BCM43225_CHIP_ID)) {
u32 p_bits;
p_bits =
(ipxotp_otpr(oi, cc, oi->otpgu_base + OTPGU_P_OFF) &
OTPGU_P_MSK)
>> OTPGU_P_SHIFT;
oi->status |= (p_bits << OTPS_GUP_SHIFT);
}
oi->hwbase = oi->otpgu_base + OTPGU_SROM_OFF;
oi->hwlim = oi->wsize;
if (oi->status & OTPS_GUP_HW) {
oi->hwlim =
ipxotp_otpr(oi, cc, oi->otpgu_base + OTPGU_HSB_OFF) / 16;
oi->swbase = oi->hwlim;
} else
oi->swbase = oi->hwbase;
oi->swlim = ipxotp_max_rgnsz(oi->sih, oi->wsize) / 2;
if (oi->status & OTPS_GUP_SW) {
oi->swlim =
ipxotp_otpr(oi, cc, oi->otpgu_base + OTPGU_SFB_OFF) / 16;
oi->fbase = oi->swlim;
} else
oi->fbase = oi->swbase;
oi->flim = oi->wsize;
}
static void *ipxotp_init(si_t *sih)
{
uint idx;
chipcregs_t *cc;
otpinfo_t *oi;
if (!OTPTYPE_IPX(sih->ccrev))
return NULL;
if (ai_is_otp_disabled(sih))
return NULL;
if (!ai_is_otp_powered(sih))
return NULL;
oi = &otpinfo;
switch ((sih->cccaps & CC_CAP_OTPSIZE) >> CC_CAP_OTPSIZE_SHIFT) {
case 0:
return NULL;
case 1:
oi->rows = 32;
oi->cols = 64;
oi->wsize = 128;
break;
case 2:
oi->rows = 64;
oi->cols = 64;
oi->wsize = 256;
break;
case 5:
oi->rows = 96;
oi->cols = 64;
oi->wsize = 384;
break;
case 7:
oi->rows = 16;
oi->cols = 64;
oi->wsize = 64;
break;
default:
return NULL;
}
idx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
_ipxotp_init(oi, cc);
ai_setcoreidx(sih, idx);
return (void *)oi;
}
static int ipxotp_read_region(void *oh, int region, u16 *data, uint *wlen)
{
otpinfo_t *oi = (otpinfo_t *) oh;
uint idx;
chipcregs_t *cc;
uint base, i, sz;
switch (region) {
case OTP_HW_RGN:
sz = (uint) oi->hwlim - oi->hwbase;
if (!(oi->status & OTPS_GUP_HW)) {
*wlen = sz;
return -ENODATA;
}
if (*wlen < sz) {
*wlen = sz;
return -EOVERFLOW;
}
base = oi->hwbase;
break;
case OTP_SW_RGN:
sz = ((uint) oi->swlim - oi->swbase);
if (!(oi->status & OTPS_GUP_SW)) {
*wlen = sz;
return -ENODATA;
}
if (*wlen < sz) {
*wlen = sz;
return -EOVERFLOW;
}
base = oi->swbase;
break;
case OTP_CI_RGN:
sz = OTPGU_CI_SZ;
if (!(oi->status & OTPS_GUP_CI)) {
*wlen = sz;
return -ENODATA;
}
if (*wlen < sz) {
*wlen = sz;
return -EOVERFLOW;
}
base = oi->otpgu_base + OTPGU_CI_OFF;
break;
case OTP_FUSE_RGN:
sz = (uint) oi->flim - oi->fbase;
if (!(oi->status & OTPS_GUP_FUSE)) {
*wlen = sz;
return -ENODATA;
}
if (*wlen < sz) {
*wlen = sz;
return -EOVERFLOW;
}
base = oi->fbase;
break;
case OTP_ALL_RGN:
sz = ((uint) oi->flim - oi->hwbase);
if (!(oi->status & (OTPS_GUP_HW | OTPS_GUP_SW))) {
*wlen = sz;
return -ENODATA;
}
if (*wlen < sz) {
*wlen = sz;
return -EOVERFLOW;
}
base = oi->hwbase;
break;
default:
return -EINVAL;
}
idx = ai_coreidx(oi->sih);
cc = ai_setcoreidx(oi->sih, SI_CC_IDX);
for (i = 0; i < sz; i++)
data[i] = ipxotp_otpr(oh, cc, base + i);
ai_setcoreidx(oi->sih, idx);
*wlen = sz;
return 0;
}
static int ipxotp_nvread(void *oh, char *data, uint *len)
{
return -ENOTSUPP;
}
static int hndotp_status(void *oh)
{
otpinfo_t *oi = (otpinfo_t *) oh;
return (int)(oi->hwprot | oi->signvalid);
}
static int hndotp_size(void *oh)
{
otpinfo_t *oi = (otpinfo_t *) oh;
return (int)(oi->size);
}
static u16 hndotp_otpr(void *oh, chipcregs_t *cc, uint wn)
{
volatile u16 *ptr;
ptr = (volatile u16 *)((volatile char *)cc + CC_SROM_OTP);
return R_REG(&ptr[wn]);
}
static u16 hndotp_otproff(void *oh, chipcregs_t *cc, int woff)
{
otpinfo_t *oi = (otpinfo_t *) oh;
volatile u16 *ptr;
ptr = (volatile u16 *)((volatile char *)cc + CC_SROM_OTP);
return R_REG(&ptr[(oi->size / 2) + woff]);
}
static u16 hndotp_read_bit(void *oh, chipcregs_t *cc, uint idx)
{
uint k, row, col;
u32 otpp, st;
row = idx / 65;
col = idx % 65;
otpp = OTPP_START_BUSY | OTPP_READ |
((row << OTPP_ROW_SHIFT) & OTPP_ROW_MASK) | (col & OTPP_COL_MASK);
W_REG(&cc->otpprog, otpp);
st = R_REG(&cc->otpprog);
for (k = 0;
((st & OTPP_START_BUSY) == OTPP_START_BUSY) && (k < OTPP_TRIES);
k++)
st = R_REG(&cc->otpprog);
if (k >= OTPP_TRIES) {
return 0xffff;
}
if (st & OTPP_READERR) {
return 0xffff;
}
st = (st & OTPP_VALUE_MASK) >> OTPP_VALUE_SHIFT;
return (u16) st;
}
static void *hndotp_init(si_t *sih)
{
uint idx;
chipcregs_t *cc;
otpinfo_t *oi;
u32 cap = 0, clkdiv, otpdiv = 0;
void *ret = NULL;
oi = &otpinfo;
idx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
if (cc != NULL) {
cap = R_REG(&cc->capabilities);
if ((cap & CC_CAP_OTPSIZE) == 0) {
goto out;
}
if (!((oi->ccrev == 12) || (oi->ccrev == 17)
|| (oi->ccrev == 22)))
return NULL;
oi->size =
1 << (((cap & CC_CAP_OTPSIZE) >> CC_CAP_OTPSIZE_SHIFT)
+ CC_CAP_OTPSIZE_BASE);
if (oi->ccrev >= 18)
oi->size -= ((OTP_RC0_OFF - OTP_BOUNDARY_OFF) * 2);
oi->hwprot = (int)(R_REG(&cc->otpstatus) & OTPS_PROTECT);
oi->boundary = -1;
if (hndotp_otproff(oi, cc, OTP_HWSIGN_OFF) == OTP_SIGNATURE) {
oi->signvalid |= OTP_HW_REGION;
oi->boundary = hndotp_otproff(oi, cc, OTP_BOUNDARY_OFF);
}
if (hndotp_otproff(oi, cc, OTP_SWSIGN_OFF) == OTP_SIGNATURE)
oi->signvalid |= OTP_SW_REGION;
if (hndotp_otproff(oi, cc, OTP_CIDSIGN_OFF) == OTP_SIGNATURE)
oi->signvalid |= OTP_CID_REGION;
if (oi->ccrev == 22)
otpdiv = 12;
if (otpdiv) {
clkdiv = R_REG(&cc->clkdiv);
clkdiv =
(clkdiv & ~CLKD_OTP) | (otpdiv << CLKD_OTP_SHIFT);
W_REG(&cc->clkdiv, clkdiv);
}
udelay(10);
ret = (void *)oi;
}
out:
ai_setcoreidx(sih, idx);
return ret;
}
static int hndotp_read_region(void *oh, int region, u16 *data, uint *wlen)
{
otpinfo_t *oi = (otpinfo_t *) oh;
u32 idx, st;
chipcregs_t *cc;
int i;
if (region != OTP_HW_REGION) {
return -ENOTSUPP;
}
st = oi->hwprot | oi->signvalid;
if ((st & region) == 0)
return -ENODATA;
*wlen =
((int)*wlen < oi->boundary / 2) ? *wlen : (uint) oi->boundary / 2;
idx = ai_coreidx(oi->sih);
cc = ai_setcoreidx(oi->sih, SI_CC_IDX);
for (i = 0; i < (int)*wlen; i++)
data[i] = hndotp_otpr(oh, cc, i);
ai_setcoreidx(oi->sih, idx);
return 0;
}
static int hndotp_nvread(void *oh, char *data, uint *len)
{
int rc = 0;
otpinfo_t *oi = (otpinfo_t *) oh;
u32 base, bound, lim = 0, st;
int i, chunk, gchunks, tsz = 0;
u32 idx;
chipcregs_t *cc;
uint offset;
u16 *rawotp = NULL;
idx = ai_coreidx(oi->sih);
cc = ai_setcoreidx(oi->sih, SI_CC_IDX);
st = hndotp_status(oh);
if (!(st & (OTP_HW_REGION | OTP_SW_REGION))) {
rc = -1;
goto out;
}
lim = hndotp_size(oh);
rawotp = kmalloc(lim, GFP_ATOMIC);
if (rawotp == NULL) {
rc = -2;
goto out;
}
for (i = 0; i < (int)(lim / 2); i++)
rawotp[i] = hndotp_otpr(oh, cc, i);
if ((st & OTP_HW_REGION) == 0) {
for (i = 0; i < (int)(lim / 2); i++)
if (rawotp[i] == OTP_MAGIC)
break;
if (i < (int)(lim / 2)) {
base = i;
bound = (i * 2) + rawotp[i + 1];
} else {
rc = -3;
goto out;
}
} else {
bound = rawotp[(lim / 2) + OTP_BOUNDARY_OFF];
if (rawotp[0] == OTP_MAGIC) {
base = 0;
} else
base = bound;
}
chunk = 0;
gchunks = 0;
i = base / 2;
offset = 0;
while ((i < (int)(lim / 2)) && (rawotp[i] == OTP_MAGIC)) {
int dsz, rsz = rawotp[i + 1];
if (((i * 2) + rsz) >= (int)lim) {
rsz = 6;
}
if (crc_ccitt(CRC16_INIT_VALUE, (u8 *) &rawotp[i], rsz) ==
CRC16_GOOD_VALUE) {
gchunks++;
dsz = rsz - 6;
tsz += dsz;
if (offset + dsz >= *len) {
goto out;
}
memcpy(&data[offset], &rawotp[i + 2], dsz);
offset += dsz;
while (offset > 1 &&
data[offset - 1] == 0 && data[offset - 2] == 0)
offset--;
i += rsz / 2;
} else {
if (rawotp[i + (rsz / 2)] == OTP_MAGIC) {
i += rsz / 2;
} else {
while (++i < (int)(lim / 2))
if (rawotp[i] == OTP_MAGIC)
break;
}
}
chunk++;
}
*len = offset;
out:
kfree(rawotp);
ai_setcoreidx(oi->sih, idx);
return rc;
}
int otp_status(void *oh)
{
otpinfo_t *oi = (otpinfo_t *) oh;
return oi->fn->status(oh);
}
int otp_size(void *oh)
{
otpinfo_t *oi = (otpinfo_t *) oh;
return oi->fn->size(oh);
}
u16 otp_read_bit(void *oh, uint offset)
{
otpinfo_t *oi = (otpinfo_t *) oh;
uint idx = ai_coreidx(oi->sih);
chipcregs_t *cc = ai_setcoreidx(oi->sih, SI_CC_IDX);
u16 readBit = (u16) oi->fn->read_bit(oh, cc, offset);
ai_setcoreidx(oi->sih, idx);
return readBit;
}
void *otp_init(si_t *sih)
{
otpinfo_t *oi;
void *ret = NULL;
oi = &otpinfo;
memset(oi, 0, sizeof(otpinfo_t));
oi->ccrev = sih->ccrev;
#ifdef BCMIPXOTP
if (OTPTYPE_IPX(oi->ccrev))
oi->fn = &ipxotp_fn;
#endif
#ifdef BCMHNDOTP
if (OTPTYPE_HND(oi->ccrev))
oi->fn = &hndotp_fn;
#endif
if (oi->fn == NULL) {
return NULL;
}
oi->sih = sih;
ret = (oi->fn->init) (sih);
return ret;
}
int
otp_read_region(si_t *sih, int region, u16 *data,
uint *wlen) {
bool wasup = false;
void *oh;
int err = 0;
wasup = ai_is_otp_powered(sih);
if (!wasup)
ai_otp_power(sih, true);
if (!ai_is_otp_powered(sih) || ai_is_otp_disabled(sih)) {
err = -EPERM;
goto out;
}
oh = otp_init(sih);
if (oh == NULL) {
err = -EBADE;
goto out;
}
err = (((otpinfo_t *) oh)->fn->read_region) (oh, region, data, wlen);
out:
if (!wasup)
ai_otp_power(sih, false);
return err;
}
int otp_nvread(void *oh, char *data, uint *len)
{
otpinfo_t *oi = (otpinfo_t *) oh;
return oi->fn->nvread(oh, data, len);
}
