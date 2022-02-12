int
sgl_to_dbl_fcnvff(
sgl_floating_point *srcptr,
unsigned int *nullptr,
dbl_floating_point *dstptr,
unsigned int *status)
{
register unsigned int src, resultp1, resultp2;
register int src_exponent;
src = *srcptr;
src_exponent = Sgl_exponent(src);
Dbl_allp1(resultp1) = Sgl_all(src);
if (src_exponent == SGL_INFINITY_EXPONENT) {
if (Sgl_iszero_mantissa(src)) {
Dbl_setinfinity_exponentmantissa(resultp1,resultp2);
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
else {
if (Sgl_isone_signaling(src)) {
if (Is_invalidtrap_enabled())
return(INVALIDEXCEPTION);
else {
Set_invalidflag();
Sgl_set_quiet(src);
}
}
Dbl_setinfinity_exponent(resultp1);
Sgl_to_dbl_mantissa(src,resultp1,resultp2);
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
}
if (src_exponent == 0) {
if (Sgl_isnotzero_mantissa(src)) {
Sgl_clear_signexponent(src);
Sgl_leftshiftby1(src);
Sgl_normalize(src,src_exponent);
Sgl_to_dbl_exponent(src_exponent,resultp1);
Sgl_to_dbl_mantissa(src,resultp1,resultp2);
}
else {
Dbl_setzero_exponentmantissa(resultp1,resultp2);
}
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
Sgl_to_dbl_exponent(src_exponent, resultp1);
Sgl_to_dbl_mantissa(Sgl_mantissa(src), resultp1,resultp2);
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
int
dbl_to_sgl_fcnvff(
dbl_floating_point *srcptr,
unsigned int *nullptr,
sgl_floating_point *dstptr,
unsigned int *status)
{
register unsigned int srcp1, srcp2, result;
register int src_exponent, dest_exponent, dest_mantissa;
register boolean inexact = FALSE, guardbit = FALSE, stickybit = FALSE;
register boolean lsb_odd = FALSE;
boolean is_tiny;
Dbl_copyfromptr(srcptr,srcp1,srcp2);
src_exponent = Dbl_exponent(srcp1);
Sgl_all(result) = Dbl_allp1(srcp1);
if (src_exponent == DBL_INFINITY_EXPONENT) {
if (Dbl_iszero_mantissa(srcp1,srcp2)) {
Sgl_setinfinity_exponentmantissa(result);
*dstptr = result;
return(NOEXCEPTION);
}
if (Dbl_isone_signaling(srcp1)) {
if (Is_invalidtrap_enabled()) return(INVALIDEXCEPTION);
else {
Set_invalidflag();
Dbl_set_quiet(srcp1);
}
}
Sgl_setinfinity_exponent(result);
Sgl_set_mantissa(result,Dallp1(srcp1)<<3 | Dallp2(srcp2)>>29);
if (Sgl_iszero_mantissa(result)) Sgl_set_quiet(result);
*dstptr = result;
return(NOEXCEPTION);
}
Dbl_to_sgl_exponent(src_exponent,dest_exponent);
if (dest_exponent > 0) {
Dbl_to_sgl_mantissa(srcp1,srcp2,dest_mantissa,inexact,guardbit,
stickybit,lsb_odd);
}
else {
if (Dbl_iszero_exponentmantissa(srcp1,srcp2)){
Sgl_setzero_exponentmantissa(result);
*dstptr = result;
return(NOEXCEPTION);
}
if (Is_underflowtrap_enabled()) {
Dbl_to_sgl_mantissa(srcp1,srcp2,dest_mantissa,inexact,
guardbit,stickybit,lsb_odd);
}
else {
Dbl_to_sgl_denormalized(srcp1,srcp2,dest_exponent,
dest_mantissa,inexact,guardbit,stickybit,lsb_odd,
is_tiny);
}
}
if (inexact) {
switch (Rounding_mode()) {
case ROUNDPLUS:
if (Sgl_iszero_sign(result)) dest_mantissa++;
break;
case ROUNDMINUS:
if (Sgl_isone_sign(result)) dest_mantissa++;
break;
case ROUNDNEAREST:
if (guardbit) {
if (stickybit || lsb_odd) dest_mantissa++;
}
}
}
Sgl_set_exponentmantissa(result,dest_mantissa);
if ((dest_exponent>0 || Is_underflowtrap_enabled()) &&
Sgl_isone_hidden(result)) dest_exponent++;
if (dest_exponent >= SGL_INFINITY_EXPONENT) {
if (Is_overflowtrap_enabled()) {
if (dest_exponent >= SGL_INFINITY_EXPONENT+SGL_WRAP)
return(UNIMPLEMENTEDEXCEPTION);
Sgl_setwrapped_exponent(result,dest_exponent,ovfl);
*dstptr = result;
if (inexact)
if (Is_inexacttrap_enabled())
return(OVERFLOWEXCEPTION|INEXACTEXCEPTION);
else Set_inexactflag();
return(OVERFLOWEXCEPTION);
}
Set_overflowflag();
inexact = TRUE;
Sgl_setoverflow(result);
}
else if (dest_exponent <= 0) {
if (Is_underflowtrap_enabled()) {
if (dest_exponent <= -(SGL_WRAP))
return(UNIMPLEMENTEDEXCEPTION);
Sgl_setwrapped_exponent(result,dest_exponent,unfl);
*dstptr = result;
if (inexact)
if (Is_inexacttrap_enabled())
return(UNDERFLOWEXCEPTION|INEXACTEXCEPTION);
else Set_inexactflag();
return(UNDERFLOWEXCEPTION);
}
if (inexact && is_tiny) Set_underflowflag();
}
else Sgl_set_exponent(result,dest_exponent);
*dstptr = result;
if (inexact)
if (Is_inexacttrap_enabled()) return(INEXACTEXCEPTION);
else Set_inexactflag();
return(NOEXCEPTION);
}
