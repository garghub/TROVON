void T_1 * F_1 ( void * V_1 )
{
if ( ! V_1 ) {
switch ( V_2 . V_3 & V_4 ) {
#ifdef F_2
case V_5 :
V_1 = V_6 ;
break;
#endif
#ifdef F_3
case V_7 :
V_1 = V_8 ;
break;
#endif
#ifdef F_4
case V_9 :
V_1 = V_10 ;
break;
#endif
#ifdef F_5
case V_11 :
V_1 = V_12 ;
break;
#endif
#ifdef F_6
case V_13 :
V_1 = V_14 ;
break;
#endif
default:
V_1 = V_15 ;
break;
}
}
V_16 = V_1 ;
return V_1 ;
}
void T_1 F_7 ( void )
{
F_8 ( V_16 ) ;
F_9 ( V_17 , V_18 , V_19 ) ;
}
void T_1 F_10 ( void )
{
F_11 () ;
}
int T_1 F_12 ( void )
{
if ( ! F_13 () )
return 0 ;
return F_14 ( NULL , V_20 , NULL ) ;
}
