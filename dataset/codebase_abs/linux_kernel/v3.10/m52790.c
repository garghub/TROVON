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
struct V_5 * V_6 = F_4 ( V_3 ) ;
if ( ! F_8 ( V_6 , & V_13 -> V_14 ) )
return - V_15 ;
if ( ! F_9 ( V_16 ) )
return - V_17 ;
if ( V_13 -> V_13 != 0 )
return - V_15 ;
V_13 -> V_18 = 1 ;
V_13 -> V_19 = V_4 -> V_8 | V_4 -> V_9 ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , const struct V_12 * V_13 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = F_4 ( V_3 ) ;
if ( ! F_8 ( V_6 , & V_13 -> V_14 ) )
return - V_15 ;
if ( ! F_9 ( V_16 ) )
return - V_17 ;
if ( V_13 -> V_13 != 0 )
return - V_15 ;
V_4 -> V_8 = V_13 -> V_19 & 0x0303 ;
V_4 -> V_9 = V_13 -> V_19 & ~ 0x0303 ;
F_3 ( V_3 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
return F_12 ( V_6 , V_21 , V_22 , 0 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_14 ( V_3 , L_1 ,
( V_4 -> V_8 | V_4 -> V_9 ) & 0xff ) ;
F_14 ( V_3 , L_2 ,
( V_4 -> V_8 | V_4 -> V_9 ) >> 8 ) ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 ,
const struct V_23 * V_24 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
if ( ! F_16 ( V_6 -> V_25 , V_26 ) )
return - V_27 ;
F_17 ( V_6 , L_3 ,
V_6 -> V_28 << 1 , V_6 -> V_25 -> V_29 ) ;
V_4 = F_18 ( sizeof( struct V_1 ) , V_30 ) ;
if ( V_4 == NULL )
return - V_31 ;
V_3 = & V_4 -> V_3 ;
F_19 ( V_3 , V_6 , & V_32 ) ;
V_4 -> V_8 = V_33 ;
V_4 -> V_9 = V_34 ;
F_3 ( V_3 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_21 ( V_6 ) ;
F_22 ( V_3 ) ;
F_23 ( F_1 ( V_3 ) ) ;
return 0 ;
}
