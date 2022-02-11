T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static void F_2 ( T_2 * V_2 , unsigned char * V_3 ,
unsigned char * V_4 , int V_5 )
{
if ( V_3 != NULL )
F_3 ( & ( V_2 -> V_6 . V_7 ) , F_4 ( V_2 ) ,
V_3 , F_4 ( V_2 ) * 8 ) ;
}
static void F_5 ( T_2 * V_2 , unsigned char * V_8 ,
unsigned char * V_9 , unsigned int V_10 )
{
unsigned int V_11 ;
if ( V_10 < 8 ) return;
V_10 -= 8 ;
for ( V_11 = 0 ; V_11 <= V_10 ; V_11 += 8 )
{
F_6 (
& ( V_9 [ V_11 ] ) , & ( V_8 [ V_11 ] ) ,
& ( V_2 -> V_6 . V_7 ) , V_2 -> V_12 ) ;
}
}
