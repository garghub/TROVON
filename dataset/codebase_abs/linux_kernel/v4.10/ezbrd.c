static int T_1 F_1 ( void )
{
F_2 ( V_1 L_1 , V_2 ) ;
F_3 ( 0 , V_3 ,
F_4 ( V_3 ) ) ;
F_5 ( V_4 , F_4 ( V_4 ) ) ;
F_6 ( V_5 , F_4 ( V_5 ) ) ;
F_7 ( V_6 , L_2 ) ;
#if ! F_8 ( V_7 )
F_7 ( V_8 , L_2 ) ;
#endif
return 0 ;
}
void T_1 F_9 ( void )
{
F_2 ( V_1 L_3 ) ;
F_10 ( V_9 ,
F_4 ( V_9 ) ) ;
}
void F_11 ( char * V_10 )
{
if ( ( F_12 () & 0x7 ) == 0x3 )
F_13 ( V_11 ) ;
}
int F_14 ( char * V_12 )
{
T_2 V_13 ;
T_3 V_14 ;
T_2 (* F_15)( T_2 V_15 , T_2 V_16 , T_3 * V_17 ) = ( void * ) 0xEF00001A ;
V_13 = F_15 ( 0xDF , 0x00 , & V_14 ) ;
if ( ! ( V_13 & 0x1 ) ) {
char * V_18 = ( char * ) & V_14 ;
for ( V_13 = 0 ; V_13 < 6 ; ++ V_13 )
V_12 [ V_13 ] = V_18 [ 5 - V_13 ] ;
}
return 0 ;
}
