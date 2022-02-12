int
dbl_fmpyfadd(
dbl_floating_point *src1ptr,
dbl_floating_point *src2ptr,
dbl_floating_point *src3ptr,
unsigned int *status,
dbl_floating_point *dstptr)
{
unsigned int opnd1p1, opnd1p2, opnd2p1, opnd2p2, opnd3p1, opnd3p2;
register unsigned int tmpresp1, tmpresp2, tmpresp3, tmpresp4;
unsigned int rightp1, rightp2, rightp3, rightp4;
unsigned int resultp1, resultp2 = 0, resultp3 = 0, resultp4 = 0;
register int mpy_exponent, add_exponent, count;
boolean inexact = FALSE, is_tiny = FALSE;
unsigned int signlessleft1, signlessright1, save;
register int result_exponent, diff_exponent;
int sign_save, jumpsize;
Dbl_copyfromptr(src1ptr,opnd1p1,opnd1p2);
Dbl_copyfromptr(src2ptr,opnd2p1,opnd2p2);
Dbl_copyfromptr(src3ptr,opnd3p1,opnd3p2);
if (Dbl_sign(opnd1p1) ^ Dbl_sign(opnd2p1))
Dbl_setnegativezerop1(resultp1);
else Dbl_setzerop1(resultp1);
mpy_exponent = Dbl_exponent(opnd1p1) + Dbl_exponent(opnd2p1) - DBL_BIAS;
if (Dbl_isinfinity_exponent(opnd1p1)) {
if (Dbl_iszero_mantissa(opnd1p1,opnd1p2)) {
if (Dbl_isnotnan(opnd2p1,opnd2p2) &&
Dbl_isnotnan(opnd3p1,opnd3p2)) {
if (Dbl_iszero_exponentmantissa(opnd2p1,opnd2p2)) {
if (Is_invalidtrap_enabled())
return(OPC_2E_INVALIDEXCEPTION);
Set_invalidflag();
Dbl_makequietnan(resultp1,resultp2);
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
if (Dbl_isinfinity(opnd3p1,opnd3p2) &&
(Dbl_sign(resultp1) ^ Dbl_sign(opnd3p1))) {
if (Is_invalidtrap_enabled())
return(OPC_2E_INVALIDEXCEPTION);
Set_invalidflag();
Dbl_makequietnan(resultp1,resultp2);
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
Dbl_setinfinity_exponentmantissa(resultp1,resultp2);
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
}
else {
if (Dbl_isone_signaling(opnd1p1)) {
if (Is_invalidtrap_enabled())
return(OPC_2E_INVALIDEXCEPTION);
Set_invalidflag();
Dbl_set_quiet(opnd1p1);
}
else if (Dbl_is_signalingnan(opnd2p1)) {
if (Is_invalidtrap_enabled())
return(OPC_2E_INVALIDEXCEPTION);
Set_invalidflag();
Dbl_set_quiet(opnd2p1);
Dbl_copytoptr(opnd2p1,opnd2p2,dstptr);
return(NOEXCEPTION);
}
else if (Dbl_is_signalingnan(opnd3p1)) {
if (Is_invalidtrap_enabled())
return(OPC_2E_INVALIDEXCEPTION);
Set_invalidflag();
Dbl_set_quiet(opnd3p1);
Dbl_copytoptr(opnd3p1,opnd3p2,dstptr);
return(NOEXCEPTION);
}
Dbl_copytoptr(opnd1p1,opnd1p2,dstptr);
return(NOEXCEPTION);
}
}
if (Dbl_isinfinity_exponent(opnd2p1)) {
if (Dbl_iszero_mantissa(opnd2p1,opnd2p2)) {
if (Dbl_isnotnan(opnd3p1,opnd3p2)) {
if (Dbl_iszero_exponentmantissa(opnd1p1,opnd1p2)) {
if (Is_invalidtrap_enabled())
return(OPC_2E_INVALIDEXCEPTION);
Set_invalidflag();
Dbl_makequietnan(opnd2p1,opnd2p2);
Dbl_copytoptr(opnd2p1,opnd2p2,dstptr);
return(NOEXCEPTION);
}
if (Dbl_isinfinity(opnd3p1,opnd3p2) &&
(Dbl_sign(resultp1) ^ Dbl_sign(opnd3p1))) {
if (Is_invalidtrap_enabled())
return(OPC_2E_INVALIDEXCEPTION);
Set_invalidflag();
Dbl_makequietnan(resultp1,resultp2);
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
Dbl_setinfinity_exponentmantissa(resultp1,resultp2);
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
}
else {
if (Dbl_isone_signaling(opnd2p1)) {
if (Is_invalidtrap_enabled())
return(OPC_2E_INVALIDEXCEPTION);
Set_invalidflag();
Dbl_set_quiet(opnd2p1);
}
else if (Dbl_is_signalingnan(opnd3p1)) {
if (Is_invalidtrap_enabled())
return(OPC_2E_INVALIDEXCEPTION);
Set_invalidflag();
Dbl_set_quiet(opnd3p1);
Dbl_copytoptr(opnd3p1,opnd3p2,dstptr);
return(NOEXCEPTION);
}
Dbl_copytoptr(opnd2p1,opnd2p2,dstptr);
return(NOEXCEPTION);
}
}
if (Dbl_isinfinity_exponent(opnd3p1)) {
if (Dbl_iszero_mantissa(opnd3p1,opnd3p2)) {
Dbl_copytoptr(opnd3p1,opnd3p2,dstptr);
return(NOEXCEPTION);
} else {
if (Dbl_isone_signaling(opnd3p1)) {
if (Is_invalidtrap_enabled())
return(OPC_2E_INVALIDEXCEPTION);
Set_invalidflag();
Dbl_set_quiet(opnd3p1);
}
Dbl_copytoptr(opnd3p1,opnd3p2,dstptr);
return(NOEXCEPTION);
}
}
if (Dbl_isnotzero_exponent(opnd1p1)) {
Dbl_clear_signexponent_set_hidden(opnd1p1);
}
else {
if (Dbl_iszero_mantissa(opnd1p1,opnd1p2)) {
if (Dbl_iszero_exponentmantissa(opnd3p1,opnd3p2)) {
if (Is_rounding_mode(ROUNDMINUS)) {
Dbl_or_signs(opnd3p1,resultp1);
} else {
Dbl_and_signs(opnd3p1,resultp1);
}
}
else if (Dbl_iszero_exponent(opnd3p1) &&
Is_underflowtrap_enabled()) {
sign_save = Dbl_signextendedsign(opnd3p1);
result_exponent = 0;
Dbl_leftshiftby1(opnd3p1,opnd3p2);
Dbl_normalize(opnd3p1,opnd3p2,result_exponent);
Dbl_set_sign(opnd3p1,sign_save);
Dbl_setwrapped_exponent(opnd3p1,result_exponent,
unfl);
Dbl_copytoptr(opnd3p1,opnd3p2,dstptr);
return(OPC_2E_UNDERFLOWEXCEPTION);
}
Dbl_copytoptr(opnd3p1,opnd3p2,dstptr);
return(NOEXCEPTION);
}
Dbl_clear_signexponent(opnd1p1);
Dbl_leftshiftby1(opnd1p1,opnd1p2);
Dbl_normalize(opnd1p1,opnd1p2,mpy_exponent);
}
if (Dbl_isnotzero_exponent(opnd2p1)) {
Dbl_clear_signexponent_set_hidden(opnd2p1);
}
else {
if (Dbl_iszero_mantissa(opnd2p1,opnd2p2)) {
if (Dbl_iszero_exponentmantissa(opnd3p1,opnd3p2)) {
if (Is_rounding_mode(ROUNDMINUS)) {
Dbl_or_signs(opnd3p1,resultp1);
} else {
Dbl_and_signs(opnd3p1,resultp1);
}
}
else if (Dbl_iszero_exponent(opnd3p1) &&
Is_underflowtrap_enabled()) {
sign_save = Dbl_signextendedsign(opnd3p1);
result_exponent = 0;
Dbl_leftshiftby1(opnd3p1,opnd3p2);
Dbl_normalize(opnd3p1,opnd3p2,result_exponent);
Dbl_set_sign(opnd3p1,sign_save);
Dbl_setwrapped_exponent(opnd3p1,result_exponent,
unfl);
Dbl_copytoptr(opnd3p1,opnd3p2,dstptr);
return(OPC_2E_UNDERFLOWEXCEPTION);
}
Dbl_copytoptr(opnd3p1,opnd3p2,dstptr);
return(NOEXCEPTION);
}
Dbl_clear_signexponent(opnd2p1);
Dbl_leftshiftby1(opnd2p1,opnd2p2);
Dbl_normalize(opnd2p1,opnd2p2,mpy_exponent);
}
Dblext_setzero(tmpresp1,tmpresp2,tmpresp3,tmpresp4);
for (count = DBL_P-1; count >= 0; count -= 4) {
Dblext_rightshiftby4(tmpresp1,tmpresp2,tmpresp3,tmpresp4);
if (Dbit28p2(opnd1p2)) {
Fourword_add(tmpresp1, tmpresp2, tmpresp3, tmpresp4,
opnd2p1<<3 | opnd2p2>>29, opnd2p2<<3, 0, 0);
}
if (Dbit29p2(opnd1p2)) {
Fourword_add(tmpresp1, tmpresp2, tmpresp3, tmpresp4,
opnd2p1<<2 | opnd2p2>>30, opnd2p2<<2, 0, 0);
}
if (Dbit30p2(opnd1p2)) {
Fourword_add(tmpresp1, tmpresp2, tmpresp3, tmpresp4,
opnd2p1<<1 | opnd2p2>>31, opnd2p2<<1, 0, 0);
}
if (Dbit31p2(opnd1p2)) {
Fourword_add(tmpresp1, tmpresp2, tmpresp3, tmpresp4,
opnd2p1, opnd2p2, 0, 0);
}
Dbl_rightshiftby4(opnd1p1,opnd1p2);
}
if (Is_dexthiddenoverflow(tmpresp1)) {
mpy_exponent++;
Dblext_rightshiftby1(tmpresp1,tmpresp2,tmpresp3,tmpresp4);
}
Dblext_set_sign(tmpresp1,Dbl_sign(resultp1));
add_exponent = Dbl_exponent(opnd3p1);
if (add_exponent == 0) {
if (Dbl_iszero_mantissa(opnd3p1,opnd3p2)) {
result_exponent = mpy_exponent;
Dblext_copy(tmpresp1,tmpresp2,tmpresp3,tmpresp4,
resultp1,resultp2,resultp3,resultp4);
sign_save = Dbl_signextendedsign(resultp1);
goto round;
}
sign_save = Dbl_signextendedsign(opnd3p1);
Dbl_clear_signexponent(opnd3p1);
Dbl_leftshiftby1(opnd3p1,opnd3p2);
Dbl_normalize(opnd3p1,opnd3p2,add_exponent);
Dbl_set_sign(opnd3p1,sign_save);
} else {
Dbl_clear_exponent_set_hidden(opnd3p1);
}
Dbl_copyto_dblext(opnd3p1,opnd3p2,rightp1,rightp2,rightp3,rightp4);
Dblext_xortointp1(tmpresp1,rightp1,save);
Dblext_copytoint_exponentmantissap1(tmpresp1,signlessleft1);
Dblext_copytoint_exponentmantissap1(rightp1,signlessright1);
if (mpy_exponent < add_exponent || mpy_exponent == add_exponent &&
Dblext_ismagnitudeless(tmpresp2,rightp2,signlessleft1,signlessright1)){
Dblext_xorfromintp1(save,rightp1,rightp1);
Dblext_xorfromintp1(save,tmpresp1,tmpresp1);
Dblext_swap_lower(tmpresp2,tmpresp3,tmpresp4,
rightp2,rightp3,rightp4);
diff_exponent = add_exponent - mpy_exponent;
result_exponent = add_exponent;
} else {
diff_exponent = mpy_exponent - add_exponent;
result_exponent = mpy_exponent;
}
if (diff_exponent > DBLEXT_THRESHOLD) {
diff_exponent = DBLEXT_THRESHOLD;
}
Dblext_clear_sign(rightp1);
Dblext_right_align(rightp1,rightp2,rightp3,rightp4,
diff_exponent);
if ((int)save < 0) {
Dblext_subtract(tmpresp1,tmpresp2,tmpresp3,tmpresp4,
rightp1,rightp2,rightp3,rightp4,
resultp1,resultp2,resultp3,resultp4);
sign_save = Dbl_signextendedsign(resultp1);
if (Dbl_iszero_hidden(resultp1)) {
Dblext_leftshiftby1(resultp1,resultp2,resultp3,
resultp4);
if(Dblext_iszero(resultp1,resultp2,resultp3,resultp4)){
if (Is_rounding_mode(ROUNDMINUS))
Dbl_setone_sign(resultp1);
Dbl_copytoptr(resultp1,resultp2,dstptr);
return(NOEXCEPTION);
}
result_exponent--;
if (Dbl_isone_hidden(resultp1)) {
goto round;
}
while (Dbl_iszero_hiddenhigh7mantissa(resultp1)) {
Dblext_leftshiftby8(resultp1,resultp2,resultp3,resultp4);
result_exponent -= 8;
}
if (Dbl_iszero_hiddenhigh3mantissa(resultp1)) {
Dblext_leftshiftby4(resultp1,resultp2,resultp3,resultp4);
result_exponent -= 4;
}
jumpsize = Dbl_hiddenhigh3mantissa(resultp1);
if (jumpsize <= 7) switch(jumpsize) {
case 1:
Dblext_leftshiftby3(resultp1,resultp2,resultp3,
resultp4);
result_exponent -= 3;
break;
case 2:
case 3:
Dblext_leftshiftby2(resultp1,resultp2,resultp3,
resultp4);
result_exponent -= 2;
break;
case 4:
case 5:
case 6:
case 7:
Dblext_leftshiftby1(resultp1,resultp2,resultp3,
resultp4);
result_exponent -= 1;
break;
}
}
}
else {
Dblext_addition(tmpresp1,tmpresp2,tmpresp3,tmpresp4,
rightp1,rightp2,rightp3,rightp4,
resultp1,resultp2,resultp3,resultp4);
sign_save = Dbl_signextendedsign(resultp1);
if (Dbl_isone_hiddenoverflow(resultp1)) {
Dblext_arithrightshiftby1(resultp1,resultp2,resultp3,
resultp4);
result_exponent++;
}
}
round:
if (result_exponent <= 0 && !Is_underflowtrap_enabled()) {
Dblext_denormalize(resultp1,resultp2,resultp3,resultp4,
result_exponent,is_tiny);
}
Dbl_set_sign(resultp1,sign_save);
if (Dblext_isnotzero_mantissap3(resultp3) ||
Dblext_isnotzero_mantissap4(resultp4)) {
inexact = TRUE;
switch(Rounding_mode()) {
case ROUNDNEAREST:
if (Dblext_isone_highp3(resultp3)) {
if (Dblext_isnotzero_low31p3(resultp3) ||
Dblext_isnotzero_mantissap4(resultp4) ||
Dblext_isone_lowp2(resultp2)) {
Dbl_increment(resultp1,resultp2);
}
}
break;
case ROUNDPLUS:
if (Dbl_iszero_sign(resultp1)) {
Dbl_increment(resultp1,resultp2);
}
break;
case ROUNDMINUS:
if (Dbl_isone_sign(resultp1)) {
Dbl_increment(resultp1,resultp2);
}
case ROUNDZERO:;
}
if (Dbl_isone_hiddenoverflow(resultp1)) result_exponent++;
}
if (result_exponent >= DBL_INFINITY_EXPONENT) {
if (Is_overflowtrap_enabled()) {
Dbl_setwrapped_exponent(resultp1,result_exponent,ovfl);
Dbl_copytoptr(resultp1,resultp2,dstptr);
if (inexact)
if (Is_inexacttrap_enabled())
return (OPC_2E_OVERFLOWEXCEPTION |
OPC_2E_INEXACTEXCEPTION);
else Set_inexactflag();
return (OPC_2E_OVERFLOWEXCEPTION);
}
inexact = TRUE;
Set_overflowflag();
Dbl_setoverflow(resultp1,resultp2);
} else if (result_exponent <= 0) {
if (Is_underflowtrap_enabled()) {
Dbl_setwrapped_exponent(resultp1,result_exponent,unfl);
Dbl_copytoptr(resultp1,resultp2,dstptr);
if (inexact)
if (Is_inexacttrap_enabled())
return (OPC_2E_UNDERFLOWEXCEPTION |
OPC_2E_INEXACTEXCEPTION);
else Set_inexactflag();
return(OPC_2E_UNDERFLOWEXCEPTION);
}
else if (inexact && is_tiny) Set_underflowflag();
}
else Dbl_set_exponent(resultp1,result_exponent);
Dbl_copytoptr(resultp1,resultp2,dstptr);
if (inexact)
if (Is_inexacttrap_enabled()) return(OPC_2E_INEXACTEXCEPTION);
else Set_inexactflag();
return(NOEXCEPTION);
}
