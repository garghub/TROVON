static int T_1 F_1 ( void )
{
F_2 ( V_1 L_1 , V_2 ) ;
F_3 ( 0 , V_3 ,
F_4 ( V_3 ) ) ;
F_5 ( V_4 , F_4 ( V_4 ) ) ;
F_6 ( V_5 , F_4 ( V_5 ) ) ;
F_7 ( V_6 , L_2 ) ;
#if ! F_8 ( V_7 ) && ! F_8 ( V_8 )
F_7 ( V_9 , L_2 ) ;
#endif
return 0 ;
}
void T_1 F_9 ( void )
{
F_2 ( V_1 L_3 ) ;
F_10 ( V_10 ,
F_4 ( V_10 ) ) ;
}
void F_11 ( char * V_11 )
{
if ( ( F_12 () & 0x7 ) == 0x3 )
F_13 ( V_12 ) ;
}
void F_14 ( char * V_13 )
{
T_2 V_14 ;
T_3 V_15 ;
T_2 (* F_15)( T_2 V_16 , T_2 V_17 , T_3 * V_18 ) = ( void * ) 0xEF00001A ;
V_14 = F_15 ( 0xDF , 0x00 , & V_15 ) ;
if ( ! ( V_14 & 0x1 ) ) {
char * V_19 = ( char * ) & V_15 ;
for ( V_14 = 0 ; V_14 < 6 ; ++ V_14 )
V_13 [ V_14 ] = V_19 [ 5 - V_14 ] ;
}
}
