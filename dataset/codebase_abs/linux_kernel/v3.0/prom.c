static void F_1 ( const char * string , int V_1 , int V_2 )
{
}
static void F_2 ( void )
{
}
static void F_3 ( char V_3 )
{
}
void F_4 ( char V_3 )
{
F_5 ( V_3 ) ;
}
static void F_6 ( void )
{
T_1 V_4 = * ( T_1 * ) ( V_5 + 0x90 ) ;
if ( V_4 >= 307 ) {
V_6 = ( void * ) V_7 ;
F_5 = ( void * ) V_8 ;
V_9 = ( void * ) V_10 ;
}
F_7 ( V_11 L_1 ) ;
}
void T_2 F_8 ( void )
{
int V_12 = V_13 ;
char * * V_14 = ( char * * ) V_15 ;
F_6 () ;
if ( F_9 () ) {
F_7 ( V_16 L_2 ) ;
V_17 = V_18 ;
V_19 = & V_20 [ 1 ] ;
} else {
F_7 ( V_16 L_3 ) ;
V_17 = V_21 ;
V_19 = & V_20 [ 0 ] ;
}
F_10 () ;
if ( V_12 > 0 ) {
strncpy ( V_22 , V_14 [ 0 ] , V_23 - 1 ) ;
V_22 [ V_23 - 1 ] = '\0' ;
}
F_11 ( V_24 ) ;
V_25 . V_26 = 0 ;
V_25 . V_27 = 0xffffffff ;
F_12 ( 0 , V_28 . V_29 , V_30 ) ;
}
void T_2 F_13 ( void )
{
}
const char * F_14 ( void )
{
return V_28 . V_31 ;
}
