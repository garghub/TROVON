static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
T_1 V_8 [ 2 ] ;
V_8 [ 0 ] = V_4 ;
V_8 [ 1 ] = V_5 ;
F_5 ( 1 , V_9 , V_3 , L_1 , V_4 , V_5 ) ;
if ( F_6 ( V_7 , V_8 , 2 ) != 2 )
F_7 ( V_3 , L_2 , V_4 , V_5 ) ;
}
static T_1 F_8 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
T_1 V_8 [ 7 ] ;
if ( V_4 >= sizeof( V_8 ) )
return 0xff ;
F_9 ( V_7 , V_8 , sizeof( V_8 ) ) ;
return V_8 [ V_4 ] ;
}
static int F_10 ( struct V_2 * V_3 ,
T_2 V_10 , T_2 V_11 , T_2 V_12 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_1 V_14 , V_15 ;
if ( V_10 > 7 || ( V_10 & 6 ) == 6 )
return - V_16 ;
V_13 -> V_17 = ( V_10 & 3 ) << 6 ;
V_13 -> V_18 = ( V_10 & V_19 ) << 3 ;
V_14 = ( V_13 -> V_20 [ V_21 ] & ~ ( 3 << 6 ) ) | V_13 -> V_17 ;
V_15 = ( V_13 -> V_20 [ V_22 ] & ~ ( 1 << 5 ) ) | V_13 -> V_18 ;
F_3 ( V_3 , V_21 , V_14 ) ;
F_3 ( V_3 , V_22 , V_15 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , struct V_23 * V_4 )
{
V_4 -> V_5 = F_8 ( V_3 , V_4 -> V_4 & 0xff ) ;
V_4 -> V_24 = 1 ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , const struct V_23 * V_4 )
{
F_3 ( V_3 , V_4 -> V_4 & 0xff , V_4 -> V_5 & 0xff ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
T_1 V_8 [ 7 ] ;
F_9 ( V_7 , V_8 , 7 ) ;
F_14 ( V_3 , L_3
L_4 ,
V_8 [ 0 ] , V_8 [ 1 ] , V_8 [ 2 ] , V_8 [ 3 ] , V_8 [ 4 ] , V_8 [ 5 ] , V_8 [ 6 ] ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 ,
const struct V_25 * V_26 )
{
struct V_1 * V_13 ;
struct V_2 * V_3 ;
int V_27 ;
if ( ! F_16 ( V_7 -> V_28 , V_29 ) )
return - V_30 ;
F_17 ( V_7 , L_5 ,
V_7 -> V_31 << 1 , V_7 -> V_28 -> V_32 ) ;
V_13 = F_18 ( & V_7 -> V_33 , sizeof( * V_13 ) , V_34 ) ;
if ( V_13 == NULL )
return - V_35 ;
V_3 = & V_13 -> V_3 ;
F_19 ( V_3 , V_7 , & V_36 ) ;
V_13 -> V_17 = 0 ;
V_13 -> V_18 = ( 1 << 5 ) ;
memcpy ( V_13 -> V_20 , V_37 , V_38 ) ;
for ( V_27 = 0 ; V_27 < V_38 ; V_27 ++ )
F_3 ( V_3 , V_27 , V_13 -> V_20 [ V_27 ] ) ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_21 ( V_7 ) ;
F_22 ( V_3 ) ;
return 0 ;
}
