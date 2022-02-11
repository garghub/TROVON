void F_1 ( char V_1 )
{
F_2 ( V_1 ) ;
}
char * F_3 ( char * V_2 )
{
return F_4 ( V_2 ) ;
}
void * F_5 ( void )
{
T_1 V_3 = F_6 () ;
if ( V_3 == 0xffffffff )
return NULL ;
return ( void * ) F_7 ( V_3 ) ;
}
void T_2 F_8 ( void )
{
}
const char * F_9 ( void )
{
return V_4 ;
}
static void T_2 F_10 ( void )
{
int V_5 , V_6 ;
struct V_7 {
T_1 V_8 ;
T_1 V_9 ;
T_1 V_10 ;
T_1 V_11 ;
T_1 V_12 ;
} V_13 [ 8 ] ;
int V_14 = * ( unsigned char * ) V_15 ;
V_6 = * ( ( unsigned char * ) V_16 ) * 16 ;
F_11 ( L_1 , V_6 ) ;
F_12 ( & V_13 ) ;
F_11 ( L_2 ) ;
for ( V_5 = 0 ; V_5 < 8 && V_13 [ V_5 ] . V_8 ; V_5 ++ ) {
if ( V_14 == V_17 ||
V_14 == V_18 ) {
if ( V_13 [ V_5 ] . V_9 >= 0x20000000 &&
V_13 [ V_5 ] . V_9 < 0x30000000 )
V_13 [ V_5 ] . V_9 -= 0x20000000 ;
}
F_11 ( L_3 , V_5 ,
V_13 [ V_5 ] . V_8 , V_13 [ V_5 ] . V_9 ) ;
F_13 ( V_13 [ V_5 ] . V_9 , V_13 [ V_5 ] . V_8 ,
V_19 ) ;
}
}
void T_2 F_14 ( void )
{
int V_20 = V_21 ;
T_1 * V_22 = ( T_1 * ) F_15 ( V_23 ) ;
int V_5 ;
F_10 () ;
for ( V_5 = 1 ; V_5 < V_20 ; V_5 ++ ) {
strcat ( V_24 , ( char * ) F_15 ( V_22 [ V_5 ] ) ) ;
if ( V_5 < ( V_20 - 1 ) )
strcat ( V_24 , L_4 ) ;
}
}
