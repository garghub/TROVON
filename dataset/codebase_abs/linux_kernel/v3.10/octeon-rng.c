static int F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
V_4 . V_8 = 0 ;
V_4 . V_9 . V_10 = 1 ;
V_4 . V_9 . V_11 = 1 ;
F_3 ( ( V_8 ) V_6 -> V_12 , V_4 . V_8 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
V_4 . V_8 = 0 ;
F_3 ( ( V_8 ) V_6 -> V_12 , V_4 . V_8 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
* V_13 = F_6 ( ( V_8 ) V_6 -> V_14 ) ;
return sizeof( T_1 ) ;
}
static int F_7 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_17 * V_19 ;
struct V_5 * V_2 ;
int V_20 ;
struct V_1 V_7 = {
. V_21 = L_1 ,
. V_22 = F_1 ,
. V_23 = F_4 ,
. V_24 = F_5
} ;
V_2 = F_8 ( & V_16 -> V_25 , sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 )
return - V_27 ;
V_18 = F_9 ( V_16 , V_28 , 0 ) ;
if ( ! V_18 )
return - V_29 ;
V_19 = F_9 ( V_16 , V_28 , 1 ) ;
if ( ! V_19 )
return - V_29 ;
V_2 -> V_12 = F_10 ( & V_16 -> V_25 ,
V_18 -> V_30 ,
sizeof( V_8 ) ) ;
if ( ! V_2 -> V_12 )
return - V_29 ;
V_2 -> V_14 = F_10 ( & V_16 -> V_25 ,
V_19 -> V_30 ,
sizeof( V_8 ) ) ;
if ( ! V_2 -> V_14 )
return - V_29 ;
V_2 -> V_7 = V_7 ;
F_11 ( & V_16 -> V_25 , & V_2 -> V_7 ) ;
V_20 = F_12 ( & V_2 -> V_7 ) ;
if ( V_20 )
return - V_29 ;
F_13 ( & V_16 -> V_25 , L_2 ) ;
return 0 ;
}
static int T_2 F_14 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( & V_16 -> V_25 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
