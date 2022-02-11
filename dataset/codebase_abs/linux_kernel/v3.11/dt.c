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
default:
V_1 = V_8 ;
break;
}
}
V_9 = V_1 ;
return V_1 ;
}
void T_1 F_4 ( void )
{
unsigned long V_10 , V_11 ;
if ( ! V_9 )
return;
V_10 = F_5 ( ( void * ) V_9 ) ;
V_11 = F_6 ( V_9 -> V_12 ) ;
F_7 ( V_10 , V_11 , V_13 ) ;
F_8 () ;
F_9 ( V_10 , V_11 ) ;
}
int T_1 F_10 ( void )
{
if ( ! F_11 () )
return 0 ;
return F_12 ( NULL , V_14 , NULL ) ;
}
