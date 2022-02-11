T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static void F_2 ( T_2 * V_2 , unsigned char * V_3 ,
unsigned char * V_4 , int V_5 )
{
if ( V_3 != NULL )
{
if ( V_5 )
F_3 ( V_3 , & ( V_2 -> V_6 . V_7 ) ) ;
else
{
T_3 V_8 ;
F_3 ( V_3 , & V_8 ) ;
F_4 ( & V_8 , & ( V_2 -> V_6 . V_7 ) ) ;
memset ( ( unsigned char * ) & V_8 , 0 ,
sizeof( T_3 ) ) ;
}
}
}
static void F_5 ( T_2 * V_2 , unsigned char * V_9 ,
unsigned char * V_10 , unsigned int V_11 )
{
unsigned int V_12 ;
if ( V_11 < 8 ) return;
V_11 -= 8 ;
for ( V_12 = 0 ; V_12 <= V_11 ; V_12 += 8 )
{
F_6 (
& ( V_10 [ V_12 ] ) , & ( V_9 [ V_12 ] ) , & ( V_2 -> V_6 . V_7 ) ) ;
}
}
