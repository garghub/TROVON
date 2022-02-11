static int T_1 F_1 ( char * V_1 )
{
if ( ! V_1 )
return - V_2 ;
if ( ! strncmp ( V_1 , L_1 , 2 ) ) {
V_3 = 0 ;
} else if ( ! strncmp ( V_1 , L_2 , 3 ) ) {
V_3 = 1 ;
}
F_2 () ;
return 0 ;
}
void F_2 ( void )
{
if ( F_3 ( V_4 ) && ! V_3 )
V_5 |= V_6 ;
else
V_5 &= ~ V_6 ;
}
void T_1 F_4 ( void )
{
if ( ! F_3 ( V_4 ) ) {
F_5 ( V_7 L_3
L_4 ) ;
} else {
#if F_6 ( V_8 ) || F_6 ( V_9 )
if ( V_3 ) {
F_5 ( V_10 L_5
L_6 ) ;
} else {
F_5 ( V_10 L_5
L_7 ) ;
}
#else
F_5 ( V_7 L_3
L_8 ) ;
#endif
}
}
