static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = F_3 ( V_2 -> V_7 . V_10 ) ;
T_3 V_11 ;
V_6 -> V_4 = 0 ;
if ( V_4 <= 2 )
return - V_12 ;
V_11 = F_4 ( V_9 , V_3 , V_4 ) ;
F_5 ( & V_2 -> V_7 ,
L_1 , V_13 ,
( int ) F_6 ( T_2 , 64 , V_4 ) , V_3 , V_4 , V_11 ) ;
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_14 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = F_3 ( V_2 -> V_7 . V_10 ) ;
struct V_15 * V_16 =
(struct V_15 * ) V_6 -> V_17 ;
T_4 V_18 ;
int V_19 ;
if ( V_6 -> V_4 == 0 )
return - V_12 ;
V_18 = F_8 ( V_16 -> V_20 ) ;
if ( V_18 > V_14 )
return - V_21 ;
if ( V_6 -> V_4 >= V_18 ) {
F_5 ( & V_2 -> V_7 ,
L_2 , V_13 ,
( int ) F_6 ( T_2 , 64 , V_18 ) , V_3 , V_14 ,
V_18 ) ;
memcpy ( V_3 , V_6 -> V_17 , V_18 ) ;
return V_18 ;
}
V_19 = F_9 ( V_9 , V_3 , V_18 ) ;
F_5 ( & V_2 -> V_7 ,
L_3 , V_13 ,
( int ) F_6 ( T_2 , 64 , V_18 ) , V_3 , V_14 ,
V_18 ) ;
return V_19 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_7 , L_4 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = F_3 ( V_2 -> V_7 . V_10 ) ;
int V_19 ;
V_6 -> V_4 = 0 ;
memset ( V_6 -> V_17 , 0 , sizeof( V_6 -> V_17 ) ) ;
V_19 = F_9 ( V_9 , V_6 -> V_17 , sizeof( V_6 -> V_17 ) ) ;
F_5 ( & V_2 -> V_7 ,
L_5 , V_13 , V_19 ) ;
if ( V_19 <= 0 )
return 0 ;
V_6 -> V_4 = V_19 ;
return V_22 ;
}
static bool F_13 ( struct V_1 * V_2 , T_1 V_11 )
{
return false ;
}
static int F_14 ( struct V_8 * V_9 ,
const struct V_23 * V_24 )
{
struct V_1 * V_2 ;
struct V_25 * V_7 = & V_9 -> V_7 ;
struct V_5 * V_6 ;
if ( ! F_15 ( V_9 -> V_26 , V_27 ) )
return - V_28 ;
V_2 = F_16 ( V_7 , & V_29 ) ;
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
V_6 = F_19 ( V_7 , sizeof( struct V_5 ) , V_30 ) ;
if ( ! V_6 )
return - V_21 ;
V_2 -> V_31 = F_20 ( V_32 ) ;
V_2 -> V_33 = F_20 ( V_34 ) ;
V_2 -> V_35 = F_20 ( V_32 ) ;
V_2 -> V_36 = F_20 ( V_32 ) ;
F_21 ( & V_2 -> V_7 , V_6 ) ;
return F_22 ( V_2 ) ;
}
static int F_23 ( struct V_8 * V_9 )
{
struct V_25 * V_7 = & ( V_9 -> V_7 ) ;
struct V_1 * V_2 = F_2 ( V_7 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
