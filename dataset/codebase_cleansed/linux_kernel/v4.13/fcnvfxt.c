int
sgl_to_sgl_fcnvfxt(
sgl_floating_point *srcptr,
unsigned int *nullptr,
int *dstptr,
unsigned int *status)
{
register unsigned int src, temp;
register int src_exponent, result;
src = *srcptr;
src_exponent = Sgl_exponent(src) - SGL_BIAS;
if (src_exponent > SGL_FX_MAX_EXP) {
if ((src_exponent > SGL_FX_MAX_EXP + 1) ||
Sgl_isnotzero_mantissa(src) || Sgl_iszero_sign(src)) {
if (Sgl_iszero_sign(src)) result = 0x7fffffff;
else result = 0x80000000;
if (Is_invalidtrap_enabled()) {
return(INVALIDEXCEPTION);
}
Set_invalidflag();
*dstptr = result;
return(NOEXCEPTION);
}
}
if (src_exponent >= 0) {
temp = src;
Sgl_clear_signexponent_set_hidden(temp);
Int_from_sgl_mantissa(temp,src_exponent);
if (Sgl_isone_sign(src)) result = -Sgl_all(temp);
else result = Sgl_all(temp);
*dstptr = result;
if (Sgl_isinexact_to_fix(src,src_exponent)) {
if (Is_inexacttrap_enabled()) return(INEXACTEXCEPTION);
else Set_inexactflag();
}
}
else {
*dstptr = 0;
if (Sgl_isnotzero_exponentmantissa(src)) {
if (Is_inexacttrap_enabled()) return(INEXACTEXCEPTION);
else Set_inexactflag();
}
}
return(NOEXCEPTION);
}
int
sgl_to_dbl_fcnvfxt(
sgl_floating_point *srcptr,
unsigned int *nullptr,
dbl_integer *dstptr,
unsigned int *status)
{
register int src_exponent, resultp1;
register unsigned int src, temp, resultp2;
src = *srcptr;
src_exponent = Sgl_exponent(src) - SGL_BIAS;
if (src_exponent > DBL_FX_MAX_EXP) {
if ((src_exponent > DBL_FX_MAX_EXP + 1) ||
Sgl_isnotzero_mantissa(src) || Sgl_iszero_sign(src)) {
if (Sgl_iszero_sign(src)) {
resultp1 = 0x7fffffff;
resultp2 = 0xffffffff;
}
else {
resultp1 = 0x80000000;
resultp2 = 0;
}
if (Is_invalidtrap_enabled()) {
return(INVALIDEXCEPTION);
}
Set_invalidflag();
Dint_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
Dint_set_minint(resultp1,resultp2);
Dint_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
if (src_exponent >= 0) {
temp = src;
Sgl_clear_signexponent_set_hidden(temp);
Dint_from_sgl_mantissa(temp,src_exponent,resultp1,resultp2);
if (Sgl_isone_sign(src)) {
Dint_setone_sign(resultp1,resultp2);
}
Dint_copytoptr(resultp1,resultp2,dstptr);
if (Sgl_isinexact_to_fix(src,src_exponent)) {
if (Is_inexacttrap_enabled()) return(INEXACTEXCEPTION);
else Set_inexactflag();
}
}
else {
Dint_setzero(resultp1,resultp2);
Dint_copytoptr(resultp1,resultp2,dstptr);
if (Sgl_isnotzero_exponentmantissa(src)) {
if (Is_inexacttrap_enabled()) return(INEXACTEXCEPTION);
else Set_inexactflag();
}
}
return(NOEXCEPTION);
}
int
dbl_to_sgl_fcnvfxt(
dbl_floating_point *srcptr,
unsigned int *nullptr,
int *dstptr,
unsigned int *status)
{
register unsigned int srcp1, srcp2, tempp1, tempp2;
register int src_exponent, result;
Dbl_copyfromptr(srcptr,srcp1,srcp2);
src_exponent = Dbl_exponent(srcp1) - DBL_BIAS;
if (src_exponent > SGL_FX_MAX_EXP) {
if (Dbl_isoverflow_to_int(src_exponent,srcp1,srcp2)) {
if (Dbl_iszero_sign(srcp1)) result = 0x7fffffff;
else result = 0x80000000;
if (Is_invalidtrap_enabled()) {
return(INVALIDEXCEPTION);
}
Set_invalidflag();
*dstptr = result;
return(NOEXCEPTION);
}
}
if (src_exponent >= 0) {
tempp1 = srcp1;
tempp2 = srcp2;
Dbl_clear_signexponent_set_hidden(tempp1);
Int_from_dbl_mantissa(tempp1,tempp2,src_exponent);
if (Dbl_isone_sign(srcp1) && (src_exponent <= SGL_FX_MAX_EXP))
result = -Dbl_allp1(tempp1);
else result = Dbl_allp1(tempp1);
*dstptr = result;
if (Dbl_isinexact_to_fix(srcp1,srcp2,src_exponent)) {
if (Is_inexacttrap_enabled()) return(INEXACTEXCEPTION);
else Set_inexactflag();
}
}
else {
*dstptr = 0;
if (Dbl_isnotzero_exponentmantissa(srcp1,srcp2)) {
if (Is_inexacttrap_enabled()) return(INEXACTEXCEPTION);
else Set_inexactflag();
}
}
return(NOEXCEPTION);
}
int
dbl_to_dbl_fcnvfxt(
dbl_floating_point *srcptr,
unsigned int *nullptr,
dbl_integer *dstptr,
unsigned int *status)
{
register int src_exponent, resultp1;
register unsigned int srcp1, srcp2, tempp1, tempp2, resultp2;
Dbl_copyfromptr(srcptr,srcp1,srcp2);
src_exponent = Dbl_exponent(srcp1) - DBL_BIAS;
if (src_exponent > DBL_FX_MAX_EXP) {
if ((src_exponent > DBL_FX_MAX_EXP + 1) ||
Dbl_isnotzero_mantissa(srcp1,srcp2) || Dbl_iszero_sign(srcp1)) {
if (Dbl_iszero_sign(srcp1)) {
resultp1 = 0x7fffffff;
resultp2 = 0xffffffff;
}
else {
resultp1 = 0x80000000;
resultp2 = 0;
}
if (Is_invalidtrap_enabled()) {
return(INVALIDEXCEPTION);
}
Set_invalidflag();
Dint_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
}
if (src_exponent >= 0) {
tempp1 = srcp1;
tempp2 = srcp2;
Dbl_clear_signexponent_set_hidden(tempp1);
Dint_from_dbl_mantissa(tempp1,tempp2,src_exponent,
resultp1,resultp2);
if (Dbl_isone_sign(srcp1)) {
Dint_setone_sign(resultp1,resultp2);
}
Dint_copytoptr(resultp1,resultp2,dstptr);
if (Dbl_isinexact_to_fix(srcp1,srcp2,src_exponent)) {
if (Is_inexacttrap_enabled()) return(INEXACTEXCEPTION);
else Set_inexactflag();
}
}
else {
Dint_setzero(resultp1,resultp2);
Dint_copytoptr(resultp1,resultp2,dstptr);
if (Dbl_isnotzero_exponentmantissa(srcp1,srcp2)) {
if (Is_inexacttrap_enabled()) return(INEXACTEXCEPTION);
else Set_inexactflag();
}
}
return(NOEXCEPTION);
}
