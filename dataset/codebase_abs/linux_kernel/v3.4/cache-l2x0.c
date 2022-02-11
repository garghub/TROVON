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
if ( F_4 () )
V_2 = F_5 ( V_6 ) ;
else if ( F_6 () )
V_2 = F_5 ( V_7 ) ;
else
F_7 () ;
F_1 () ;
if ( F_8 () )
F_9 ( 0x3e060000 , 0xc0000fff ) ;
else
F_10 ( V_2 , 0x3e060000 , 0xc0000fff ) ;
V_8 . V_9 = NULL ;
return 0 ;
}
