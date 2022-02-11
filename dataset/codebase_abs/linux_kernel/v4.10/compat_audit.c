int F_1 ( int V_1 , unsigned V_2 )
{
switch ( V_2 ) {
#ifdef F_2
case F_2 :
return 2 ;
#endif
#ifdef F_3
case F_3 :
return 3 ;
#endif
#ifdef F_4
case F_4 :
return 4 ;
#endif
case V_3 :
return 5 ;
default:
return 1 ;
}
}
