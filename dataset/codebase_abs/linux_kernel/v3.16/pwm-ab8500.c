static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 )
{
int V_7 = 0 ;
unsigned int V_8 , V_9 ;
T_1 V_10 ;
V_9 = V_5 & 0x00FF ;
V_8 = ( ( V_5 & 0x0300 ) >> 8 ) ;
V_10 = V_11 + ( ( V_2 -> V_12 - 1 ) * 2 ) ;
V_7 = F_2 ( V_2 -> V_13 , V_14 ,
V_10 , ( T_1 ) V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_2 ( V_2 -> V_13 , V_14 ,
( V_10 + 1 ) , ( T_1 ) V_8 ) ;
return V_7 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_7 ;
V_7 = F_4 ( V_2 -> V_13 ,
V_14 , V_15 ,
1 << ( V_2 -> V_12 - 1 ) , 1 << ( V_2 -> V_12 - 1 ) ) ;
if ( V_7 < 0 )
F_5 ( V_2 -> V_13 , L_1 ,
V_4 -> V_16 , V_7 ) ;
return V_7 ;
}
static void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_7 ;
V_7 = F_4 ( V_2 -> V_13 ,
V_14 , V_15 ,
1 << ( V_2 -> V_12 - 1 ) , 0 ) ;
if ( V_7 < 0 )
F_5 ( V_2 -> V_13 , L_2 ,
V_4 -> V_16 , V_7 ) ;
}
static int F_7 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
int V_21 ;
V_20 = F_8 ( & V_18 -> V_13 , sizeof( * V_20 ) , V_22 ) ;
if ( V_20 == NULL )
return - V_23 ;
V_20 -> V_2 . V_13 = & V_18 -> V_13 ;
V_20 -> V_2 . V_24 = & V_25 ;
V_20 -> V_2 . V_12 = V_18 -> V_26 ;
V_20 -> V_2 . V_27 = 1 ;
V_21 = F_9 ( & V_20 -> V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
F_10 ( & V_18 -> V_13 , L_3 ) ;
F_11 ( V_18 , V_20 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_13 ( V_18 ) ;
int V_21 ;
V_21 = F_14 ( & V_20 -> V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
F_10 ( & V_18 -> V_13 , L_4 ) ;
return 0 ;
}
