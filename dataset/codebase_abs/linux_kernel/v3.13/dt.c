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
default:
V_1 = V_10 ;
break;
}
}
V_11 = V_1 ;
return V_1 ;
}
void T_1 F_5 ( void )
{
F_6 ( V_11 ) ;
F_7 ( V_12 , V_13 , V_14 ) ;
}
void T_1 F_8 ( void )
{
unsigned long V_15 , V_16 ;
struct V_17 * V_1 = V_11 ;
if ( ! V_1 )
return;
V_15 = F_9 ( V_1 ) ;
V_16 = F_10 ( V_1 -> V_18 ) ;
F_11 ( V_15 , V_16 , V_19 ) ;
F_12 () ;
F_13 ( V_15 , V_16 ) ;
}
int T_1 F_14 ( void )
{
if ( ! F_15 () )
return 0 ;
return F_16 ( NULL , V_20 , NULL ) ;
}
