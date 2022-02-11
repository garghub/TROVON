static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
snprintf ( V_4 -> V_7 , sizeof( V_4 -> V_7 ) ,
L_1 , ( int ) ( V_6 -> V_8 -> V_9 . V_10 >> 32 ) ,
( int ) ( V_6 -> V_8 -> V_9 . V_10 >> 16 ) & 0xffff ,
( int ) V_6 -> V_8 -> V_9 . V_10 & 0xffff ) ;
F_3 ( V_4 -> V_11 , F_4 ( V_6 -> V_8 -> V_12 ) ,
sizeof( V_4 -> V_11 ) ) ;
F_3 ( V_4 -> V_13 , V_14 ,
sizeof( V_4 -> V_13 ) ) ;
F_3 ( V_4 -> V_15 , L_2 , sizeof( V_4 -> V_15 ) ) ;
}
static int F_5 ( struct V_1 * V_16 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_16 ) ;
V_18 -> V_19 = V_6 -> V_20 . V_21 ;
V_18 -> V_22 = V_6 -> V_20 . V_23 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_16 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_16 ) ;
int V_24 ;
if ( V_18 -> V_19 > 0xffff ||
V_18 -> V_22 > 0xffff )
return - V_25 ;
V_24 = F_7 ( V_6 -> V_26 , V_18 -> V_22 ,
V_18 -> V_19 ) ;
if ( V_24 && V_24 != - V_27 ) {
F_8 ( V_6 , L_3 , V_24 ) ;
return V_24 ;
}
V_6 -> V_20 . V_21 = V_18 -> V_19 ;
V_6 -> V_20 . V_23 = V_18 -> V_22 ;
return 0 ;
}
void F_9 ( struct V_1 * V_16 )
{
V_16 -> V_28 = & V_29 ;
}
