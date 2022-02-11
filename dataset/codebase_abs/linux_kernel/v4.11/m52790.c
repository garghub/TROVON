static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = F_4 ( V_3 ) ;
T_1 V_7 = ( V_4 -> V_8 | V_4 -> V_9 ) & 0xff ;
T_1 V_10 = ( V_4 -> V_8 | V_4 -> V_9 ) >> 8 ;
return F_5 ( V_6 , V_7 , V_10 ) ;
}
static int F_6 ( struct V_2 * V_3 ,
T_2 V_8 , T_2 V_9 , T_2 V_11 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_8 = V_8 ;
V_4 -> V_9 = V_9 ;
F_3 ( V_3 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_13 -> V_13 != 0 )
return - V_14 ;
V_13 -> V_15 = 1 ;
V_13 -> V_16 = V_4 -> V_8 | V_4 -> V_9 ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , const struct V_12 * V_13 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_13 -> V_13 != 0 )
return - V_14 ;
V_4 -> V_8 = V_13 -> V_16 & 0x0303 ;
V_4 -> V_9 = V_13 -> V_16 & ~ 0x0303 ;
F_3 ( V_3 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_10 ( V_3 , L_1 ,
( V_4 -> V_8 | V_4 -> V_9 ) & 0xff ) ;
F_10 ( V_3 , L_2 ,
( V_4 -> V_8 | V_4 -> V_9 ) >> 8 ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 ,
const struct V_17 * V_18 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
if ( ! F_12 ( V_6 -> V_19 , V_20 ) )
return - V_21 ;
F_13 ( V_6 , L_3 ,
V_6 -> V_22 << 1 , V_6 -> V_19 -> V_23 ) ;
V_4 = F_14 ( & V_6 -> V_24 , sizeof( * V_4 ) , V_25 ) ;
if ( V_4 == NULL )
return - V_26 ;
V_3 = & V_4 -> V_3 ;
F_15 ( V_3 , V_6 , & V_27 ) ;
V_4 -> V_8 = V_28 ;
V_4 -> V_9 = V_29 ;
F_3 ( V_3 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_17 ( V_6 ) ;
F_18 ( V_3 ) ;
return 0 ;
}
