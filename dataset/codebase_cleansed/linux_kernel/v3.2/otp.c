static u16
ipxotp_otpr(struct otpinfo *oi, struct chipcregs __iomem *cc, uint wn)
{
return R_REG(&cc->sromotp[wn]);
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
static void _ipxotp_init(struct otpinfo *oi, struct chipcregs __iomem *cc)
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
if (k >= OTPP_TRIES)
return;
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
static int ipxotp_init(struct si_pub *sih, struct otpinfo *oi)
{
uint idx;
struct chipcregs __iomem *cc;
if (!OTPTYPE_IPX(sih->ccrev))
return -EBADE;
if (ai_is_otp_disabled(sih))
return -EBADE;
switch ((sih->cccaps & CC_CAP_OTPSIZE) >> CC_CAP_OTPSIZE_SHIFT) {
case 0:
return -EBADE;
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
return -EBADE;
}
idx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
_ipxotp_init(oi, cc);
ai_setcoreidx(sih, idx);
return 0;
}
static int
ipxotp_read_region(struct otpinfo *oi, int region, u16 *data, uint *wlen)
{
uint idx;
struct chipcregs __iomem *cc;
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
data[i] = ipxotp_otpr(oi, cc, base + i);
ai_setcoreidx(oi->sih, idx);
*wlen = sz;
return 0;
}
static int otp_init(struct si_pub *sih, struct otpinfo *oi)
{
int ret;
memset(oi, 0, sizeof(struct otpinfo));
oi->ccrev = sih->ccrev;
if (OTPTYPE_IPX(oi->ccrev))
oi->fn = &ipxotp_fn;
if (oi->fn == NULL)
return -EBADE;
oi->sih = sih;
ret = (oi->fn->init) (sih, oi);
return ret;
}
int
otp_read_region(struct si_pub *sih, int region, u16 *data, uint *wlen) {
struct otpinfo otpinfo;
struct otpinfo *oi = &otpinfo;
int err = 0;
if (ai_is_otp_disabled(sih)) {
err = -EPERM;
goto out;
}
err = otp_init(sih, oi);
if (err)
goto out;
err = ((oi)->fn->read_region)(oi, region, data, wlen);
out:
return err;
}
