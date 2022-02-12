unsigned int
dbl_fsqrt(
dbl_floating_point *srcptr,
unsigned int *nullptr,
dbl_floating_point *dstptr,
unsigned int *status)
{
register unsigned int srcp1, srcp2, resultp1, resultp2;
register unsigned int newbitp1, newbitp2, sump1, sump2;
register int src_exponent;
register boolean guardbit = FALSE, even_exponent;
Dbl_copyfromptr(srcptr,srcp1,srcp2);
if ((src_exponent = Dbl_exponent(srcp1)) == DBL_INFINITY_EXPONENT) {
if (Dbl_isone_signaling(srcp1)) {
if (Is_invalidtrap_enabled()) return(INVALIDEXCEPTION);
Set_invalidflag();
Dbl_set_quiet(srcp1);
}
if (Dbl_iszero_sign(srcp1) ||
Dbl_isnotzero_mantissa(srcp1,srcp2)) {
Dbl_copytoptr(srcp1,srcp2,dstptr);
return(NOEXCEPTION);
}
}
if (Dbl_iszero_exponentmantissa(srcp1,srcp2)) {
Dbl_copytoptr(srcp1,srcp2,dstptr);
return(NOEXCEPTION);
}
if (Dbl_isone_sign(srcp1)) {
if (Is_invalidtrap_enabled()) return(INVALIDEXCEPTION);
Set_invalidflag();
Dbl_makequietnan(srcp1,srcp2);
Dbl_copytoptr(srcp1,srcp2,dstptr);
return(NOEXCEPTION);
}
if (src_exponent > 0) {
even_exponent = Dbl_hidden(srcp1);
Dbl_clear_signexponent_set_hidden(srcp1);
}
else {
Dbl_clear_signexponent(srcp1);
src_exponent++;
Dbl_normalize(srcp1,srcp2,src_exponent);
even_exponent = src_exponent & 1;
}
if (even_exponent) {
Dbl_leftshiftby1(srcp1,srcp2);
}
Dbl_setzero(resultp1,resultp2);
Dbl_allp1(newbitp1) = 1 << (DBL_P - 32);
Dbl_setzero_mantissap2(newbitp2);
while (Dbl_isnotzero(newbitp1,newbitp2) && Dbl_isnotzero(srcp1,srcp2)) {
Dbl_addition(resultp1,resultp2,newbitp1,newbitp2,sump1,sump2);
if(Dbl_isnotgreaterthan(sump1,sump2,srcp1,srcp2)) {
Dbl_leftshiftby1(newbitp1,newbitp2);
Dbl_addition(resultp1,resultp2,newbitp1,newbitp2,
resultp1,resultp2);
Dbl_subtract(srcp1,srcp2,sump1,sump2,srcp1,srcp2);
Dbl_rightshiftby2(newbitp1,newbitp2);
}
else {
Dbl_rightshiftby1(newbitp1,newbitp2);
}
Dbl_leftshiftby1(srcp1,srcp2);
}
if (even_exponent) {
Dbl_rightshiftby1(resultp1,resultp2);
}
if (Dbl_isnotzero(srcp1,srcp2)) {
if (!even_exponent && Dbl_islessthan(resultp1,resultp2,srcp1,srcp2)) {
Dbl_increment(resultp1,resultp2);
}
guardbit = Dbl_lowmantissap2(resultp2);
Dbl_rightshiftby1(resultp1,resultp2);
switch (Rounding_mode()) {
case ROUNDPLUS:
Dbl_increment(resultp1,resultp2);
break;
case ROUNDNEAREST:
if (guardbit) {
Dbl_increment(resultp1,resultp2);
}
break;
}
if (Dbl_isone_hiddenoverflow(resultp1)) src_exponent+=2;
if (Is_inexacttrap_enabled()) {
Dbl_set_exponent(resultp1,
((src_exponent-DBL_BIAS)>>1)+DBL_BIAS);
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(INEXACTEXCEPTION);
}
else Set_inexactflag();
}
else {
Dbl_rightshiftby1(resultp1,resultp2);
}
Dbl_set_exponent(resultp1,((src_exponent-DBL_BIAS)>>1)+DBL_BIAS);
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
