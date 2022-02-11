static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static int T_1 F_3 ( unsigned long V_2 ,
const char * V_3 ,
T_2 V_4 )
{
const T_2 V_5 = 0x00010000 ;
const char * V_6 ;
const char * V_7 ;
const char * V_8 ;
char V_9 [ 64 ] ;
if ( V_10 ) {
F_4 ( V_11 L_1
L_2 ,
V_12 ) ;
return 1 ;
}
V_6 = F_5 ( V_2 ) ;
V_7 = V_6 + V_5 - ( V_4 + 2 ) ;
for ( V_8 = V_6 ; V_8 < V_7 ; V_8 ++ ) {
const char * V_13 ;
char * V_14 ;
if ( memcmp ( V_8 , V_3 , V_4 ) != 0 )
continue;
memcpy ( V_9 , V_8 , sizeof( V_9 ) ) ;
V_14 = strchr ( V_9 , '\0' ) ;
if ( V_14 )
* V_14 = ' ' ;
V_14 = strchr ( V_9 , '\r' ) ;
if ( V_14 )
* V_14 = '\0' ;
V_13 = V_8 + V_4 ;
if ( ( V_13 [ 0 ] == '2' || V_13 [ 0 ] == '3' ) ) {
F_4 ( V_15
L_3 ,
V_12 , V_9 ) ;
return 1 ;
}
}
return 0 ;
}
static int T_1 F_6 ( void )
{
const char V_16 [] = L_4 ;
const char V_17 [] = L_5 ;
if ( ! F_7 () )
return 0 ;
if ( F_3 ( 0xf0000 , V_16 , sizeof( V_16 ) - 1 ) ||
F_3 ( 0x500 , V_17 , sizeof( V_17 ) - 1 ) )
F_1 () ;
return 0 ;
}
