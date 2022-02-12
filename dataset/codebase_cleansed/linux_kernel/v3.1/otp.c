static int ipxotp_status(void *oh)
{
struct otpinfo *oi = (struct otpinfo *) oh;
return (int)(oi->status);
}
static int ipxotp_size(void *oh)
{
struct otpinfo *oi = (struct otpinfo *) oh;
return (int)oi->wsize * 2;
}
static u16 ipxotp_otpr(void *oh, chipcregs_t *cc, uint wn)
{
struct otpinfo *oi;
oi = (struct otpinfo *) oh;
return R_REG(&cc->sromotp[wn]);
}
static u16 ipxotp_read_bit(void *oh, chipcregs_t *cc, uint off)
{
struct otpinfo *oi = (struct otpinfo *) oh;
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
static int ipxotp_max_rgnsz(struct si_pub *sih, int osizew)
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
static void _ipxotp_init(struct otpinfo *oi, chipcregs_t *cc)
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
static void *ipxotp_init(struct si_pub *sih)
{
uint idx;
chipcregs_t *cc;
struct otpinfo *oi;
if (!OTPTYPE_IPX(sih->ccrev))
return NULL;
if (ai_is_otp_disabled(sih))
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
struct otpinfo *oi = (struct otpinfo *) oh;
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
int otp_status(void *oh)
{
struct otpinfo *oi = (struct otpinfo *) oh;
return oi->fn->status(oh);
}
int otp_size(void *oh)
{
struct otpinfo *oi = (struct otpinfo *) oh;
return oi->fn->size(oh);
}
u16 otp_read_bit(void *oh, uint offset)
{
struct otpinfo *oi = (struct otpinfo *) oh;
uint idx = ai_coreidx(oi->sih);
chipcregs_t *cc = ai_setcoreidx(oi->sih, SI_CC_IDX);
u16 readBit = (u16) oi->fn->read_bit(oh, cc, offset);
ai_setcoreidx(oi->sih, idx);
return readBit;
}
void *otp_init(struct si_pub *sih)
{
struct otpinfo *oi;
void *ret = NULL;
oi = &otpinfo;
memset(oi, 0, sizeof(struct otpinfo));
oi->ccrev = sih->ccrev;
if (OTPTYPE_IPX(oi->ccrev))
oi->fn = &ipxotp_fn;
if (oi->fn == NULL) {
return NULL;
}
oi->sih = sih;
ret = (oi->fn->init) (sih);
return ret;
}
int
otp_read_region(struct si_pub *sih, int region, u16 *data,
uint *wlen) {
void *oh;
int err = 0;
if (ai_is_otp_disabled(sih)) {
err = -EPERM;
goto out;
}
oh = otp_init(sih);
if (oh == NULL) {
err = -EBADE;
goto out;
}
err = (((struct otpinfo *) oh)->fn->read_region)
(oh, region, data, wlen);
out:
return err;
}
int otp_nvread(void *oh, char *data, uint *len)
{
struct otpinfo *oi = (struct otpinfo *) oh;
return oi->fn->nvread(oh, data, len);
}
