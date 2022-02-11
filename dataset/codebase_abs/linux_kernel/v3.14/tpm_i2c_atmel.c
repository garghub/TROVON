static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 ) ;
T_3 V_11 ;
V_6 -> V_4 = 0 ;
if ( V_4 <= 2 )
return - V_12 ;
V_11 = F_3 ( V_9 , V_3 , V_4 ) ;
F_4 ( V_2 -> V_10 ,
L_1 , V_13 ,
( int ) F_5 ( T_2 , 64 , V_4 ) , V_3 , V_4 , V_11 ) ;
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 ) ;
struct V_15 * V_16 =
(struct V_15 * ) V_6 -> V_17 ;
T_4 V_18 ;
int V_19 ;
if ( V_6 -> V_4 == 0 )
return - V_12 ;
V_18 = F_7 ( V_16 -> V_20 ) ;
if ( V_18 > V_14 )
return - V_21 ;
if ( V_6 -> V_4 >= V_18 ) {
F_4 ( V_2 -> V_10 ,
L_2 , V_13 ,
( int ) F_5 ( T_2 , 64 , V_18 ) , V_3 , V_14 ,
V_18 ) ;
memcpy ( V_3 , V_6 -> V_17 , V_18 ) ;
return V_18 ;
}
V_19 = F_8 ( V_9 , V_3 , V_18 ) ;
F_4 ( V_2 -> V_10 ,
L_3 , V_13 ,
( int ) F_5 ( T_2 , 64 , V_18 ) , V_3 , V_14 ,
V_18 ) ;
return V_19 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_10 , L_4 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 ) ;
int V_19 ;
V_6 -> V_4 = 0 ;
memset ( V_6 -> V_17 , 0 , sizeof( V_6 -> V_17 ) ) ;
V_19 = F_8 ( V_9 , V_6 -> V_17 , sizeof( V_6 -> V_17 ) ) ;
F_4 ( V_2 -> V_10 ,
L_5 , V_13 , V_19 ) ;
if ( V_19 <= 0 )
return 0 ;
V_6 -> V_4 = V_19 ;
return V_22 ;
}
static bool F_12 ( struct V_1 * V_2 , T_1 V_11 )
{
return false ;
}
static int F_13 ( struct V_8 * V_9 ,
const struct V_23 * V_24 )
{
int V_19 ;
struct V_1 * V_2 ;
struct V_25 * V_10 = & V_9 -> V_10 ;
if ( ! F_14 ( V_9 -> V_26 , V_27 ) )
return - V_28 ;
V_2 = F_15 ( V_10 , & V_29 ) ;
if ( ! V_2 ) {
F_10 ( V_10 , L_6 , V_13 ) ;
return - V_28 ;
}
V_2 -> V_7 . V_6 = F_16 ( V_10 , sizeof( struct V_5 ) ,
V_30 ) ;
V_2 -> V_7 . V_31 = F_17 ( V_32 ) ;
V_2 -> V_7 . V_33 = F_17 ( V_34 ) ;
V_2 -> V_7 . V_35 = F_17 ( V_32 ) ;
V_2 -> V_7 . V_36 = F_17 ( V_32 ) ;
V_2 -> V_7 . V_37 = 0 ;
if ( F_18 ( V_2 ) ) {
V_19 = - V_28 ;
goto V_38;
}
if ( F_19 ( V_2 ) ) {
V_19 = - V_28 ;
goto V_38;
}
return 0 ;
V_38:
F_20 ( V_2 ) ;
F_21 ( V_2 -> V_10 ) ;
return V_19 ;
}
static int F_22 ( struct V_8 * V_9 )
{
struct V_25 * V_10 = & ( V_9 -> V_10 ) ;
struct V_1 * V_2 = F_23 ( V_10 ) ;
if ( V_2 )
F_20 ( V_2 ) ;
F_21 ( V_10 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
