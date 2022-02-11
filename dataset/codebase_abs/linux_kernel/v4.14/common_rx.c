static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = ( void * ) V_6 -> V_9 ;
F_3 ( V_2 , L_1 ,
F_4 ( V_8 -> V_10 ) ,
F_4 ( V_8 -> V_11 ) ) ;
}
void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 V_12 = F_6 ( V_6 -> V_13 . V_14 , V_6 -> V_13 . V_12 ) ;
switch ( V_12 ) {
case F_6 ( V_15 , V_16 ) :
F_1 ( V_2 , V_4 ) ;
break;
default:
break;
}
}
