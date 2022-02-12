int
dbl_fcmp (dbl_floating_point * leftptr, dbl_floating_point * rightptr,
unsigned int cond, unsigned int *status)
{
register unsigned int leftp1, leftp2, rightp1, rightp2;
register int xorresult;
Dbl_copyfromptr(leftptr,leftp1,leftp2);
Dbl_copyfromptr(rightptr,rightp1,rightp2);
if( (Dbl_exponent(leftp1) == DBL_INFINITY_EXPONENT)
|| (Dbl_exponent(rightp1) == DBL_INFINITY_EXPONENT) )
{
if( ((Dbl_exponent(leftp1) == DBL_INFINITY_EXPONENT)
&& Dbl_isnotzero_mantissa(leftp1,leftp2)
&& (Exception(cond) || Dbl_isone_signaling(leftp1)))
||
((Dbl_exponent(rightp1) == DBL_INFINITY_EXPONENT)
&& Dbl_isnotzero_mantissa(rightp1,rightp2)
&& (Exception(cond) || Dbl_isone_signaling(rightp1))) )
{
if( Is_invalidtrap_enabled() ) {
Set_status_cbit(Unordered(cond));
return(INVALIDEXCEPTION);
}
else Set_invalidflag();
Set_status_cbit(Unordered(cond));
return(NOEXCEPTION);
}
else if( ((Dbl_exponent(leftp1) == DBL_INFINITY_EXPONENT)
&& Dbl_isnotzero_mantissa(leftp1,leftp2))
||
((Dbl_exponent(rightp1) == DBL_INFINITY_EXPONENT)
&& Dbl_isnotzero_mantissa(rightp1,rightp2)) )
{
Set_status_cbit(Unordered(cond));
return(NOEXCEPTION);
}
}
Dbl_xortointp1(leftp1,rightp1,xorresult);
if( xorresult < 0 )
{
if( Dbl_iszero_exponentmantissa(leftp1,leftp2)
&& Dbl_iszero_exponentmantissa(rightp1,rightp2) )
{
Set_status_cbit(Equal(cond));
}
else if( Dbl_isone_sign(leftp1) )
{
Set_status_cbit(Lessthan(cond));
}
else
{
Set_status_cbit(Greaterthan(cond));
}
}
else if(Dbl_isequal(leftp1,leftp2,rightp1,rightp2))
{
Set_status_cbit(Equal(cond));
}
else if( Dbl_iszero_sign(leftp1) )
{
if( Dbl_allp1(leftp1) < Dbl_allp1(rightp1) )
{
Set_status_cbit(Lessthan(cond));
}
else if( Dbl_allp1(leftp1) > Dbl_allp1(rightp1) )
{
Set_status_cbit(Greaterthan(cond));
}
else
{
if( Dbl_allp2(leftp2) < Dbl_allp2(rightp2) )
{
Set_status_cbit(Lessthan(cond));
}
else
{
Set_status_cbit(Greaterthan(cond));
}
}
}
else
{
if( Dbl_allp1(leftp1) > Dbl_allp1(rightp1) )
{
Set_status_cbit(Lessthan(cond));
}
else if( Dbl_allp1(leftp1) < Dbl_allp1(rightp1) )
{
Set_status_cbit(Greaterthan(cond));
}
else
{
if( Dbl_allp2(leftp2) > Dbl_allp2(rightp2) )
{
Set_status_cbit(Lessthan(cond));
}
else
{
Set_status_cbit(Greaterthan(cond));
}
}
}
return(NOEXCEPTION);
}
