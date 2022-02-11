static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static T_1 F_3 ( struct V_4 * V_5 )
{
T_2 V_6 [ 4 ] ;
int V_7 = F_4 ( V_5 , V_6 , sizeof( V_6 ) ) ;
if ( V_7 == sizeof( V_6 ) )
return V_6 [ 3 ] << 8 ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
if ( V_9 -> V_10 > 0 )
return - V_11 ;
F_6 ( V_9 -> V_12 , L_1 , sizeof( V_9 -> V_12 ) ) ;
V_9 -> type = V_13 ;
V_9 -> V_14 = V_15 ;
V_9 -> V_16 = V_17 ;
V_9 -> V_18 = V_19 ;
V_9 -> V_20 = V_21 ;
V_9 -> V_22 = V_23 ;
V_9 -> signal = F_3 ( F_7 ( V_3 ) ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , const struct V_8 * V_9 )
{
return V_9 -> V_10 ? - V_11 : 0 ;
}
static int F_9 ( struct V_2 * V_3 , const struct V_24 * V_25 )
{
struct V_1 * V_26 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_7 ( V_3 ) ;
unsigned V_27 = V_25 -> V_28 ;
T_1 V_29 ;
T_2 V_30 [ 3 ] ;
int V_7 ;
if ( V_25 -> V_31 != 0 )
return - V_11 ;
V_27 = F_10 ( V_27 , V_15 , V_17 ) ;
V_29 = 1964 + ( ( V_27 - V_15 ) * 20 ) / V_32 ;
V_30 [ 0 ] = ( V_33 << V_34 ) | V_35 ;
V_30 [ 1 ] = ( V_29 >> 8 ) & 0xff ;
V_30 [ 2 ] = V_29 & 0xff ;
V_7 = F_11 ( V_5 , V_30 , sizeof( V_30 ) ) ;
if ( V_7 != sizeof( V_30 ) )
return V_7 < 0 ? V_7 : - V_36 ;
V_26 -> V_27 = V_27 ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
struct V_1 * V_26 = F_1 ( V_3 ) ;
if ( V_25 -> V_31 != 0 )
return - V_11 ;
V_25 -> type = V_13 ;
V_25 -> V_28 = V_26 -> V_27 ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 ,
const struct V_37 * V_38 )
{
struct V_1 * V_26 ;
struct V_2 * V_3 ;
if ( ! F_14 ( V_5 -> V_39 , V_40 ) )
return - V_36 ;
F_15 ( V_5 , L_2 ,
V_5 -> V_41 << 1 , V_5 -> V_39 -> V_12 ) ;
V_26 = F_16 ( sizeof( struct V_1 ) , V_42 ) ;
if ( V_26 == NULL )
return - V_43 ;
V_26 -> V_27 = V_15 ;
V_3 = & V_26 -> V_3 ;
F_17 ( V_3 , V_5 , & V_44 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_19 ( V_5 ) ;
F_20 ( V_3 ) ;
F_21 ( F_1 ( V_3 ) ) ;
return 0 ;
}
