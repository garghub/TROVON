void F_1 ( void )
{
const unsigned V_1 = ( ( V_2 + ( 8 * 19200 ) ) / ( 16 * 19200 ) ) ;
F_2 ( L_1 , V_3 ) ;
F_3 ( 0x83 , F_4 ( V_4 ) ) ;
F_3 ( V_1 & 0xff , F_4 ( V_5 ) ) ;
F_3 ( ( V_1 >> 8 ) & 0xff , F_4 ( V_6 ) ) ;
F_3 ( 0x03 , F_4 ( V_4 ) ) ;
F_3 ( 0x00 , F_4 ( V_7 ) ) ;
F_3 ( 0x00 , F_4 ( V_8 ) ) ;
F_3 ( 0x00 , F_4 ( V_9 ) ) ;
F_3 ( 'A' , F_4 ( V_10 ) ) ;
}
static int T_1 F_5 ( const char * V_11 )
{
T_2 V_12 [ 6 ] ;
if ( ! F_6 ( V_11 , V_12 ) )
return - 1 ;
F_7 ( V_13 L_2 , V_12 ) ;
memcpy ( V_14 . V_15 , V_12 , 6 ) ;
return 0 ;
}
void T_1 F_8 ( T_3 V_16 , T_3 V_17 )
{
unsigned long V_12 ;
for ( V_12 = V_16 ; V_12 < ( V_16 + V_17 ) ; V_12 += 1024 ) {
void T_4 * V_18 ;
int V_19 = 0 ;
V_18 = F_9 ( V_12 , 1024 ) ;
if ( V_18 != NULL ) {
V_19 = F_5 ( ( V_20 const char * ) V_18 ) ;
F_10 ( V_18 ) ;
}
if ( V_19 == 0 )
break;
}
}
