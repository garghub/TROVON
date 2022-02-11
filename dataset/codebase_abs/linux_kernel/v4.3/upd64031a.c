static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static T_1 F_3 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
T_1 V_7 [ 2 ] ;
if ( V_4 >= sizeof( V_7 ) )
return 0xff ;
F_5 ( V_6 , V_7 , 2 ) ;
return V_7 [ V_4 ] ;
}
static void F_6 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_8 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_4 ;
V_7 [ 1 ] = V_8 ;
F_7 ( 1 , V_9 , V_3 , L_1 , V_4 , V_8 ) ;
if ( F_8 ( V_6 , V_7 , 2 ) != 2 )
F_9 ( V_3 , L_2 , V_4 , V_8 ) ;
}
static int F_10 ( struct V_2 * V_3 , const struct V_10 * V_11 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_4 = V_12 -> V_13 [ V_14 ] ;
F_7 ( 1 , V_9 , V_3 , L_3 ) ;
F_6 ( V_3 , V_14 , V_4 | 0x10 ) ;
F_6 ( V_3 , V_14 , V_4 & ~ 0x10 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 ,
T_2 V_15 , T_2 V_16 , T_2 V_17 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_18 , V_19 , V_20 ;
V_12 -> V_21 = ( V_15 & 3 ) << 6 ;
V_12 -> V_22 = ( V_15 & 0xc ) << 4 ;
V_12 -> V_23 =
( V_15 & V_24 ) << 1 ;
V_12 -> V_25 =
( V_15 & V_26 ) << 2 ;
V_18 = ( V_12 -> V_13 [ V_14 ] & ~ V_27 ) | V_12 -> V_21 ;
V_19 = ( V_12 -> V_13 [ V_14 ] & ~ V_28 ) |
V_12 -> V_23 | V_12 -> V_25 ;
V_20 = ( V_12 -> V_13 [ V_29 ] & ~ V_30 ) |
V_12 -> V_22 ;
F_6 ( V_3 , V_14 , V_18 ) ;
F_6 ( V_3 , V_31 , V_19 ) ;
F_6 ( V_3 , V_29 , V_20 ) ;
return F_10 ( V_3 , NULL ) ;
}
static int F_12 ( struct V_2 * V_3 )
{
F_13 ( V_3 , L_4 ,
F_3 ( V_3 , 0 ) , F_3 ( V_3 , 1 ) ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , struct V_32 * V_4 )
{
V_4 -> V_8 = F_3 ( V_3 , V_4 -> V_4 & 0xff ) ;
V_4 -> V_33 = 1 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , const struct V_32 * V_4 )
{
F_6 ( V_3 , V_4 -> V_4 & 0xff , V_4 -> V_8 & 0xff ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
const struct V_34 * V_35 )
{
struct V_1 * V_12 ;
struct V_2 * V_3 ;
int V_36 ;
if ( ! F_17 ( V_6 -> V_37 , V_38 ) )
return - V_39 ;
F_18 ( V_6 , L_5 ,
V_6 -> V_40 << 1 , V_6 -> V_37 -> V_41 ) ;
V_12 = F_19 ( & V_6 -> V_42 , sizeof( * V_12 ) , V_43 ) ;
if ( V_12 == NULL )
return - V_44 ;
V_3 = & V_12 -> V_3 ;
F_20 ( V_3 , V_6 , & V_45 ) ;
memcpy ( V_12 -> V_13 , V_46 , sizeof( V_12 -> V_13 ) ) ;
V_12 -> V_21 = V_47 << 6 ;
V_12 -> V_22 = V_48 << 4 ;
V_12 -> V_23 = V_12 -> V_25 = 0 ;
for ( V_36 = 0 ; V_36 < V_49 ; V_36 ++ )
F_6 ( V_3 , V_36 , V_12 -> V_13 [ V_36 ] ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_22 ( V_6 ) ;
F_23 ( V_3 ) ;
return 0 ;
}
