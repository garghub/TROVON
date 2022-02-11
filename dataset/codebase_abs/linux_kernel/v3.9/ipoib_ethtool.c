static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
V_8 = F_3 ( sizeof( * V_8 ) , V_9 ) ;
if ( V_8 && ! F_4 ( V_6 -> V_10 , V_8 ) )
snprintf ( V_4 -> V_11 , sizeof( V_4 -> V_11 ) ,
L_1 , ( int ) ( V_8 -> V_12 >> 32 ) ,
( int ) ( V_8 -> V_12 >> 16 ) & 0xffff ,
( int ) V_8 -> V_12 & 0xffff ) ;
F_5 ( V_8 ) ;
F_6 ( V_4 -> V_13 , F_7 ( V_6 -> V_10 -> V_14 ) ,
sizeof( V_4 -> V_13 ) ) ;
F_6 ( V_4 -> V_15 , V_16 ,
sizeof( V_4 -> V_15 ) ) ;
F_6 ( V_4 -> V_17 , L_2 , sizeof( V_4 -> V_17 ) ) ;
}
static int F_8 ( struct V_1 * V_18 ,
struct V_19 * V_20 )
{
struct V_5 * V_6 = F_2 ( V_18 ) ;
V_20 -> V_21 = V_6 -> V_22 . V_23 ;
V_20 -> V_24 = V_6 -> V_22 . V_25 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_18 ,
struct V_19 * V_20 )
{
struct V_5 * V_6 = F_2 ( V_18 ) ;
int V_26 ;
if ( V_20 -> V_21 > 0xffff ||
V_20 -> V_24 > 0xffff )
return - V_27 ;
V_26 = F_10 ( V_6 -> V_28 , V_20 -> V_24 ,
V_20 -> V_21 ) ;
if ( V_26 && V_26 != - V_29 ) {
F_11 ( V_6 , L_3 , V_26 ) ;
return V_26 ;
}
V_6 -> V_22 . V_23 = V_20 -> V_21 ;
V_6 -> V_22 . V_25 = V_20 -> V_24 ;
return 0 ;
}
void F_12 ( struct V_1 * V_18 )
{
F_13 ( V_18 , & V_30 ) ;
}
