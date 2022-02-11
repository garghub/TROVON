T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static void F_2 ( T_2 * V_2 , unsigned char * V_3 ,
unsigned char * V_4 , int V_5 )
{
if ( V_3 != NULL )
F_3 ( & ( V_2 -> V_6 . V_7 ) , V_8 , V_3 ) ;
}
static void F_4 ( T_2 * V_2 , unsigned char * V_9 ,
unsigned char * V_10 , unsigned int V_11 )
{
unsigned int V_12 ;
if ( V_11 < 8 ) return;
V_11 -= 8 ;
for ( V_12 = 0 ; V_12 <= V_11 ; V_12 += 8 )
{
F_5 (
& ( V_10 [ V_12 ] ) , & ( V_9 [ V_12 ] ) ,
& ( V_2 -> V_6 . V_7 ) , V_2 -> V_13 ) ;
}
}
