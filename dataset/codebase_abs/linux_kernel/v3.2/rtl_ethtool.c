static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
strcpy ( V_4 -> V_7 , V_8 ) ;
strcpy ( V_4 -> V_9 , V_10 ) ;
strcpy ( V_4 -> V_11 , F_3 ( V_6 -> V_12 ) ) ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return ( ( V_6 -> V_13 -> V_14 == V_15 ) ||
( V_6 -> V_13 -> V_14 == V_16 ) ) ;
}
