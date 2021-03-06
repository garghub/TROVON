int
sgl_to_sgl_fcnvxf(
int *srcptr,
unsigned int *nullptr,
sgl_floating_point *dstptr,
unsigned int *status)
{
register int src, dst_exponent;
register unsigned int result = 0;
src = *srcptr;
if (src < 0) {
Sgl_setone_sign(result);
Int_negate(src);
}
else {
Sgl_setzero_sign(result);
if (src == 0) {
Sgl_setzero(result);
*dstptr = result;
return(NOEXCEPTION);
}
}
dst_exponent = 16;
Find_ms_one_bit(src,dst_exponent);
if (dst_exponent >= 0) src <<= dst_exponent;
else src = 1 << 30;
Sgl_set_mantissa(result, src >> (SGL_EXP_LENGTH-1));
Sgl_set_exponent(result, 30+SGL_BIAS - dst_exponent);
if (Int_isinexact_to_sgl(src)) {
switch (Rounding_mode()) {
case ROUNDPLUS:
if (Sgl_iszero_sign(result))
Sgl_increment(result);
break;
case ROUNDMINUS:
if (Sgl_isone_sign(result))
Sgl_increment(result);
break;
case ROUNDNEAREST:
Sgl_roundnearest_from_int(src,result);
}
if (Is_inexacttrap_enabled()) {
*dstptr = result;
return(INEXACTEXCEPTION);
}
else Set_inexactflag();
}
*dstptr = result;
return(NOEXCEPTION);
}
int
sgl_to_dbl_fcnvxf(
int *srcptr,
unsigned int *nullptr,
dbl_floating_point *dstptr,
unsigned int *status)
{
register int src, dst_exponent;
register unsigned int resultp1 = 0, resultp2 = 0;
src = *srcptr;
if (src < 0) {
Dbl_setone_sign(resultp1);
Int_negate(src);
}
else {
Dbl_setzero_sign(resultp1);
if (src == 0) {
Dbl_setzero(resultp1,resultp2);
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
}
dst_exponent = 16;
Find_ms_one_bit(src,dst_exponent);
if (dst_exponent >= 0) src <<= dst_exponent;
else src = 1 << 30;
Dbl_set_mantissap1(resultp1, src >> DBL_EXP_LENGTH - 1);
Dbl_set_mantissap2(resultp2, src << (33-DBL_EXP_LENGTH));
Dbl_set_exponent(resultp1, (30+DBL_BIAS) - dst_exponent);
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
int
dbl_to_sgl_fcnvxf(
dbl_integer *srcptr,
unsigned int *nullptr,
sgl_floating_point *dstptr,
unsigned int *status)
{
int dst_exponent, srcp1;
unsigned int result = 0, srcp2;
Dint_copyfromptr(srcptr,srcp1,srcp2);
if (srcp1 < 0) {
Sgl_setone_sign(result);
Dint_negate(srcp1,srcp2);
}
else {
Sgl_setzero_sign(result);
if (srcp1 == 0 && srcp2 == 0) {
Sgl_setzero(result);
*dstptr = result;
return(NOEXCEPTION);
}
}
dst_exponent = 16;
if (srcp1 == 0) {
Find_ms_one_bit(srcp2,dst_exponent);
if (dst_exponent >= 0) {
srcp1 = srcp2 << dst_exponent;
srcp2 = 0;
}
else {
srcp1 = srcp2 >> 1;
srcp2 <<= 31;
}
dst_exponent += 32;
}
else {
Find_ms_one_bit(srcp1,dst_exponent);
if (dst_exponent > 0) {
Variable_shift_double(srcp1,srcp2,(32-dst_exponent),
srcp1);
srcp2 <<= dst_exponent;
}
else srcp1 >>= -(dst_exponent);
}
Sgl_set_mantissa(result, srcp1 >> SGL_EXP_LENGTH - 1);
Sgl_set_exponent(result, (62+SGL_BIAS) - dst_exponent);
if (Dint_isinexact_to_sgl(srcp1,srcp2)) {
switch (Rounding_mode()) {
case ROUNDPLUS:
if (Sgl_iszero_sign(result))
Sgl_increment(result);
break;
case ROUNDMINUS:
if (Sgl_isone_sign(result))
Sgl_increment(result);
break;
case ROUNDNEAREST:
Sgl_roundnearest_from_dint(srcp1,srcp2,result);
}
if (Is_inexacttrap_enabled()) {
*dstptr = result;
return(INEXACTEXCEPTION);
}
else Set_inexactflag();
}
*dstptr = result;
return(NOEXCEPTION);
}
int
dbl_to_dbl_fcnvxf(
dbl_integer *srcptr,
unsigned int *nullptr,
dbl_floating_point *dstptr,
unsigned int *status)
{
register int srcp1, dst_exponent;
register unsigned int srcp2, resultp1 = 0, resultp2 = 0;
Dint_copyfromptr(srcptr,srcp1,srcp2);
if (srcp1 < 0) {
Dbl_setone_sign(resultp1);
Dint_negate(srcp1,srcp2);
}
else {
Dbl_setzero_sign(resultp1);
if (srcp1 == 0 && srcp2 ==0) {
Dbl_setzero(resultp1,resultp2);
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
}
dst_exponent = 16;
if (srcp1 == 0) {
Find_ms_one_bit(srcp2,dst_exponent);
if (dst_exponent >= 0) {
srcp1 = srcp2 << dst_exponent;
srcp2 = 0;
}
else {
srcp1 = srcp2 >> 1;
srcp2 <<= 31;
}
dst_exponent += 32;
}
else {
Find_ms_one_bit(srcp1,dst_exponent);
if (dst_exponent > 0) {
Variable_shift_double(srcp1,srcp2,(32-dst_exponent),
srcp1);
srcp2 <<= dst_exponent;
}
else srcp1 >>= -(dst_exponent);
}
Dbl_set_mantissap1(resultp1, srcp1 >> (DBL_EXP_LENGTH-1));
Shiftdouble(srcp1,srcp2,DBL_EXP_LENGTH-1,resultp2);
Dbl_set_exponent(resultp1, (62+DBL_BIAS) - dst_exponent);
if (Dint_isinexact_to_dbl(srcp2)) {
switch (Rounding_mode()) {
case ROUNDPLUS:
if (Dbl_iszero_sign(resultp1)) {
Dbl_increment(resultp1,resultp2);
}
break;
case ROUNDMINUS:
if (Dbl_isone_sign(resultp1)) {
Dbl_increment(resultp1,resultp2);
}
break;
case ROUNDNEAREST:
Dbl_roundnearest_from_dint(srcp2,resultp1,
resultp2);
}
if (Is_inexacttrap_enabled()) {
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(INEXACTEXCEPTION);
}
else Set_inexactflag();
}
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
