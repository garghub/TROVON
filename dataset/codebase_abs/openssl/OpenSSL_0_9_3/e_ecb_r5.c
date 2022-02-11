T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static void F_2 ( T_2 * V_2 , unsigned char * V_3 ,
unsigned char * V_4 , int V_5 )
{
if ( V_3 != NULL )
F_3 ( & ( V_2 -> V_6 . V_7 ) , V_8 , V_3 ,
V_9 ) ;
}
static void F_4 ( T_2 * V_2 , unsigned char * V_10 ,
unsigned char * V_11 , unsigned int V_12 )
{
unsigned int V_13 ;
if ( V_12 < 8 ) return;
V_12 -= 8 ;
for ( V_13 = 0 ; V_13 <= V_12 ; V_13 += 8 )
{
F_5 (
& ( V_11 [ V_13 ] ) , & ( V_10 [ V_13 ] ) ,
& ( V_2 -> V_6 . V_7 ) , V_2 -> V_14 ) ;
}
}
