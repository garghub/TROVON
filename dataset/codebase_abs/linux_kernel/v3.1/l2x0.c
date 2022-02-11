static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
void T_2 * V_3 ;
V_2 = F_2 ( NULL , V_4 ) ;
if ( ! V_2 )
F_3 ( L_1 ) ;
V_3 = F_4 ( V_2 , 0 ) ;
if ( ! V_3 )
F_3 ( L_2 ) ;
F_5 ( V_2 ) ;
if ( ! ( F_6 ( V_3 + V_5 ) & 1 ) ) {
F_7 ( V_6 + 1024 * 1024 * 1024 ,
V_3 + V_7 ) ;
F_7 ( V_6 | 0x1 ,
V_3 + V_8 ) ;
F_7 ( 0 ,
V_3 + V_9 ) ;
F_7 ( 0 ,
V_3 + V_10 ) ;
}
F_8 ( ( void T_2 * ) V_3 , 0x00040000 ,
0x00000000 ) ;
return 0 ;
}
