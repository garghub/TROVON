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
unsigned long V_12 , V_13 ;
if ( ! V_11 )
return;
V_12 = F_6 ( ( void * ) V_11 ) ;
V_13 = F_7 ( V_11 -> V_14 ) ;
F_8 ( V_12 , V_13 , V_15 ) ;
F_9 () ;
F_10 ( V_12 , V_13 ) ;
}
int T_1 F_11 ( void )
{
if ( ! F_12 () )
return 0 ;
return F_13 ( NULL , V_16 , NULL ) ;
}
