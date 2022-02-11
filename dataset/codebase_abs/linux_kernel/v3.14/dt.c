void T_1 * F_1 ( void * V_1 )
{
if ( ! V_1 ) {
switch ( V_2 . V_3 & 0xff00 ) {
#ifdef F_2
case V_4 :
V_1 = V_5 ;
break;
#endif
#ifdef F_3
case V_6 :
V_1 = V_7 ;
break;
#endif
#ifdef F_4
case V_8 :
V_1 = V_9 ;
break;
#endif
#ifdef F_5
case V_10 :
V_1 = V_11 ;
break;
#endif
default:
V_1 = V_12 ;
break;
}
}
V_13 = V_1 ;
return V_1 ;
}
void T_1 F_6 ( void )
{
F_7 ( V_13 ) ;
F_8 ( V_14 , V_15 , V_16 ) ;
}
void T_1 F_9 ( void )
{
unsigned long V_17 , V_18 ;
struct V_19 * V_1 = V_13 ;
if ( ! V_1 )
return;
V_17 = F_10 ( V_1 ) ;
V_18 = F_11 ( V_1 -> V_20 ) ;
F_12 ( V_17 , V_18 , V_21 ) ;
F_13 () ;
F_14 ( V_17 , V_18 ) ;
}
int T_1 F_15 ( void )
{
if ( ! F_16 () )
return 0 ;
return F_17 ( NULL , V_22 , NULL ) ;
}
