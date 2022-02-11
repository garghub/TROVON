static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 . V_6 [ 0 ] = 0x1b ;
V_4 -> V_5 . V_7 [ 0 ] = 0x14 ;
V_4 -> V_8 = 1 ;
V_4 -> V_9 = V_10 ;
}
static void F_2 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
switch ( V_11 >> 26 ) {
case V_12 :
F_4 ( V_2 ) ;
break;
default:
F_6 ( V_2 , V_11 ) ;
break;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 . V_6 [ 0 ] = 0x15 ;
V_4 -> V_5 . V_7 [ 0 ] = 0x14 ;
V_4 -> V_8 = 1 ;
V_4 -> V_9 = V_10 ;
}
