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
struct V_6 * V_7 = F_4 ( V_3 ) ;
if ( ! F_12 ( V_7 , & V_4 -> V_24 ) )
return - V_16 ;
if ( ! F_13 ( V_25 ) )
return - V_26 ;
V_4 -> V_5 = F_8 ( V_3 , V_4 -> V_4 & 0xff ) ;
V_4 -> V_27 = 1 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , struct V_23 * V_4 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
if ( ! F_12 ( V_7 , & V_4 -> V_24 ) )
return - V_16 ;
if ( ! F_13 ( V_25 ) )
return - V_26 ;
F_3 ( V_3 , V_4 -> V_4 & 0xff , V_4 -> V_5 & 0xff ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , struct V_28 * V_29 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
return F_16 ( V_7 , V_29 , V_30 , 0 ) ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
T_1 V_8 [ 7 ] ;
F_9 ( V_7 , V_8 , 7 ) ;
F_18 ( V_3 , L_3
L_4 ,
V_8 [ 0 ] , V_8 [ 1 ] , V_8 [ 2 ] , V_8 [ 3 ] , V_8 [ 4 ] , V_8 [ 5 ] , V_8 [ 6 ] ) ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 ,
const struct V_31 * V_32 )
{
struct V_1 * V_13 ;
struct V_2 * V_3 ;
int V_33 ;
if ( ! F_20 ( V_7 -> V_34 , V_35 ) )
return - V_36 ;
F_21 ( V_7 , L_5 ,
V_7 -> V_37 << 1 , V_7 -> V_34 -> V_38 ) ;
V_13 = F_22 ( sizeof( struct V_1 ) , V_39 ) ;
if ( V_13 == NULL )
return - V_40 ;
V_3 = & V_13 -> V_3 ;
F_23 ( V_3 , V_7 , & V_41 ) ;
V_13 -> V_17 = 0 ;
V_13 -> V_18 = ( 1 << 5 ) ;
memcpy ( V_13 -> V_20 , V_42 , V_43 ) ;
for ( V_33 = 0 ; V_33 < V_43 ; V_33 ++ )
F_3 ( V_3 , V_33 , V_13 -> V_20 [ V_33 ] ) ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_25 ( V_7 ) ;
F_26 ( V_3 ) ;
F_27 ( F_1 ( V_3 ) ) ;
return 0 ;
}
static T_3 int F_28 ( void )
{
return F_29 ( & V_44 ) ;
}
static T_4 void F_30 ( void )
{
F_31 ( & V_44 ) ;
}
