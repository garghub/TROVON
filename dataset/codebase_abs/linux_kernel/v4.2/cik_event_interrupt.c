static bool F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 )
{
unsigned int V_4 ;
const struct V_5 * V_6 =
( const struct V_5 * ) V_3 ;
V_4 = ( V_6 -> V_7 & 0xffff0000 ) >> 16 ;
return ( V_4 != 0 ) &&
( V_6 -> V_8 == V_9 ||
V_6 -> V_8 == V_10 ||
V_6 -> V_8 == V_11 ) ;
}
static void F_2 ( struct V_1 * V_2 ,
const T_1 * V_3 )
{
unsigned int V_4 ;
const struct V_5 * V_6 =
( const struct V_5 * ) V_3 ;
V_4 = ( V_6 -> V_7 & 0xffff0000 ) >> 16 ;
if ( V_4 == 0 )
return;
if ( V_6 -> V_8 == V_9 )
F_3 ( V_4 , 0 , 0 ) ;
else if ( V_6 -> V_8 == V_10 )
F_3 ( V_4 , V_6 -> V_12 & 0xFF , 8 ) ;
else if ( V_6 -> V_8 == V_11 )
F_4 ( V_4 ) ;
}
