static int T_1 F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < 8 ; V_1 ++ ) {
F_2 ( 0x0 , V_2 + V_3 +
V_1 * V_4 ) ;
F_2 ( 0x0 , V_2 + V_5 +
V_1 * V_4 ) ;
}
return 0 ;
}
static int T_1 F_3 ( void )
{
T_2 V_6 = 0x3e000000 ;
if ( F_4 () || F_5 () )
V_2 = F_6 ( V_7 ) ;
else
F_7 () ;
F_1 () ;
if ( F_5 () )
V_6 |= ( 0x4 << V_8 ) ;
else
V_6 |= ( 0x3 << V_8 ) ;
if ( F_8 () )
F_9 ( V_6 , 0xc0000fff ) ;
else
F_10 ( V_2 , V_6 , 0xc0000fff ) ;
V_9 . V_10 = NULL ;
return 0 ;
}
