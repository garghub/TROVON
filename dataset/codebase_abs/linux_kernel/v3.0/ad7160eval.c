static int T_1 F_1 ( void )
{
F_2 ( V_1 L_1 , V_2 ) ;
F_3 ( 0 , V_3 ,
F_4 ( V_3 ) ) ;
F_5 ( V_4 , F_4 ( V_4 ) ) ;
F_6 ( V_5 , F_4 ( V_5 ) ) ;
return 0 ;
}
void T_1 F_7 ( void )
{
F_2 ( V_1 L_2 ) ;
F_8 ( V_6 ,
F_4 ( V_6 ) ) ;
}
void F_9 ( char * V_7 )
{
if ( ( F_10 () & 0x7 ) == 0x3 )
F_11 ( V_8 ) ;
}
void F_12 ( char * V_9 )
{
T_2 V_10 ;
T_3 V_11 ;
T_2 (* F_13)( T_2 V_12 , T_2 V_13 , T_3 * V_14 ) = ( void * ) 0xEF00001A ;
V_10 = F_13 ( 0xDF , 0x00 , & V_11 ) ;
if ( ! ( V_10 & 0x1 ) ) {
char * V_15 = ( char * ) & V_11 ;
for ( V_10 = 0 ; V_10 < 6 ; ++ V_10 )
V_9 [ V_10 ] = V_15 [ 5 - V_10 ] ;
}
}
