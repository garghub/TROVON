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
static int T_1 F_5 ( char V_11 )
{
if ( V_11 >= '0' && V_11 <= '9' )
return V_11 - '0' ;
if ( V_11 >= 'A' && V_11 <= 'F' )
return V_11 - 'A' + 10 ;
if ( V_11 >= 'a' && V_11 <= 'f' )
return V_11 - 'a' + 10 ;
return - 1 ;
}
static int T_1 F_6 ( const char * V_12 )
{
int V_13 ;
int V_14 ;
V_13 = F_5 ( V_12 [ 0 ] ) ;
V_14 = F_5 ( V_12 [ 1 ] ) ;
if ( V_13 < 0 || V_14 < 0 )
return - 1 ;
return ( V_13 << 4 ) | V_14 ;
}
static int T_1 F_7 ( const char * V_15 )
{
T_2 V_16 [ 6 ] ;
int V_17 ;
for ( V_17 = 0 ; V_17 < 6 ; V_17 ++ ) {
int V_18 ;
if ( V_15 [ ( V_17 * 3 ) + 2 ] != ( ( V_17 < 5 ) ? ':' : '\n' ) )
return - 1 ;
V_18 = F_6 ( V_15 + ( V_17 * 3 ) ) ;
if ( V_18 < 0 )
return - 1 ;
V_16 [ V_17 ] = V_18 ;
}
F_8 ( V_19 L_2 , V_16 ) ;
memcpy ( V_20 . V_21 , V_16 , 6 ) ;
return 0 ;
}
void T_1 F_9 ( T_3 V_22 , T_3 V_23 )
{
unsigned long V_16 ;
for ( V_16 = V_22 ; V_16 < ( V_22 + V_23 ) ; V_16 += 1024 ) {
char * V_24 ;
int V_25 = 0 ;
V_24 = F_10 ( V_16 , 1024 ) ;
if ( V_24 != NULL ) {
V_25 = F_7 ( V_24 ) ;
F_11 ( V_24 ) ;
}
if ( V_25 == 0 )
break;
}
}
