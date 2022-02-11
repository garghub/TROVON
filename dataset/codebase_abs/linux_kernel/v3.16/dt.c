void T_1 * F_1 ( void * V_1 )
{
if ( ! V_1 ) {
switch ( V_2 . V_3 & V_4 ) {
#ifdef F_2
case V_5 :
case V_6 :
V_1 = V_7 ;
break;
#endif
#ifdef F_3
case V_8 :
V_1 = V_9 ;
break;
#endif
#ifdef F_4
case V_10 :
V_1 = V_11 ;
break;
#endif
#ifdef F_5
case V_12 :
V_1 = V_13 ;
break;
#endif
default:
V_1 = V_14 ;
break;
}
}
V_15 = V_1 ;
return V_1 ;
}
void T_1 F_6 ( void )
{
F_7 ( V_15 ) ;
F_8 ( V_16 , V_17 , V_18 ) ;
}
void T_1 F_9 ( void )
{
F_10 () ;
}
int T_1 F_11 ( void )
{
if ( ! F_12 () )
return 0 ;
return F_13 ( NULL , V_19 , NULL ) ;
}
