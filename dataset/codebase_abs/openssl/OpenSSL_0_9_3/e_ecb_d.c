T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static void F_2 ( T_2 * V_2 , unsigned char * V_3 ,
unsigned char * V_4 , int V_5 )
{
T_3 * V_6 = ( T_3 * ) V_3 ;
if ( V_6 != NULL )
F_3 ( V_6 , V_2 -> V_7 . V_8 ) ;
}
static void F_4 ( T_2 * V_2 , unsigned char * V_9 ,
unsigned char * V_10 , unsigned int V_11 )
{
unsigned int V_12 ;
T_3 * V_13 ;
T_3 * V_14 ;
if ( V_11 < 8 ) return;
V_11 -= 8 ;
for ( V_12 = 0 ; V_12 <= V_11 ; V_12 += 8 )
{
V_13 = ( T_3 * ) ( V_9 + V_12 ) ;
V_14 = ( T_3 * ) ( V_10 + V_12 ) ;
F_5 ( V_14 , V_13 , V_2 -> V_7 . V_8 , V_2 -> V_15 ) ;
}
}
