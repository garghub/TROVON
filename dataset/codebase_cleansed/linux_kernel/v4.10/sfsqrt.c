unsigned int
sgl_fsqrt(
sgl_floating_point *srcptr,
unsigned int *nullptr,
sgl_floating_point *dstptr,
unsigned int *status)
{
register unsigned int src, result;
register int src_exponent;
register unsigned int newbit, sum;
register boolean guardbit = FALSE, even_exponent;
src = *srcptr;
if ((src_exponent = Sgl_exponent(src)) == SGL_INFINITY_EXPONENT) {
if (Sgl_isone_signaling(src)) {
if (Is_invalidtrap_enabled()) return(INVALIDEXCEPTION);
Set_invalidflag();
Sgl_set_quiet(src);
}
if (Sgl_iszero_sign(src) || Sgl_isnotzero_mantissa(src)) {
*dstptr = src;
return(NOEXCEPTION);
}
}
if (Sgl_iszero_exponentmantissa(src)) {
*dstptr = src;
return(NOEXCEPTION);
}
if (Sgl_isone_sign(src)) {
if (Is_invalidtrap_enabled()) return(INVALIDEXCEPTION);
Set_invalidflag();
Sgl_makequietnan(src);
*dstptr = src;
return(NOEXCEPTION);
}
if (src_exponent > 0) {
even_exponent = Sgl_hidden(src);
Sgl_clear_signexponent_set_hidden(src);
}
else {
Sgl_clear_signexponent(src);
src_exponent++;
Sgl_normalize(src,src_exponent);
even_exponent = src_exponent & 1;
}
if (even_exponent) {
Sgl_leftshiftby1(src);
}
Sgl_setzero(result);
newbit = 1 << SGL_P;
while (newbit && Sgl_isnotzero(src)) {
Sgl_addition(result,newbit,sum);
if(sum <= Sgl_all(src)) {
Sgl_addition(result,(newbit<<1),result);
Sgl_subtract(src,sum,src);
}
Sgl_rightshiftby1(newbit);
Sgl_leftshiftby1(src);
}
if (even_exponent) {
Sgl_rightshiftby1(result);
}
if (Sgl_isnotzero(src)) {
if (!even_exponent && Sgl_islessthan(result,src))
Sgl_increment(result);
guardbit = Sgl_lowmantissa(result);
Sgl_rightshiftby1(result);
switch (Rounding_mode()) {
case ROUNDPLUS:
Sgl_increment(result);
break;
case ROUNDNEAREST:
if (guardbit) {
Sgl_increment(result);
}
break;
}
if (Sgl_isone_hiddenoverflow(result)) src_exponent+=2;
if (Is_inexacttrap_enabled()) {
Sgl_set_exponent(result,
((src_exponent-SGL_BIAS)>>1)+SGL_BIAS);
*dstptr = result;
return(INEXACTEXCEPTION);
}
else Set_inexactflag();
}
else {
Sgl_rightshiftby1(result);
}
Sgl_set_exponent(result,((src_exponent-SGL_BIAS)>>1)+SGL_BIAS);
*dstptr = result;
return(NOEXCEPTION);
}
