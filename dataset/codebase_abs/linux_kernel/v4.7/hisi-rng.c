static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_6 ;
T_1 V_7 ;
F_3 ( & V_7 , sizeof( V_7 ) ) ;
F_4 ( V_7 , V_4 -> V_8 + V_9 ) ;
if ( V_10 == 1 )
V_5 |= V_11 | V_12 ;
F_4 ( V_5 , V_4 -> V_8 + V_13 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_4 ( 0 , V_4 -> V_8 + V_13 ) ;
}
static int F_6 ( struct V_1 * V_2 , void * V_14 , T_2 V_15 , bool V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 * V_17 = V_14 ;
* V_17 = F_7 ( V_4 -> V_8 + V_18 ) ;
return 4 ;
}
static int F_8 ( struct V_19 * V_20 )
{
struct V_3 * V_2 ;
struct V_21 * V_22 ;
int V_23 ;
V_2 = F_9 ( & V_20 -> V_24 , sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 )
return - V_26 ;
F_10 ( V_20 , V_2 ) ;
V_22 = F_11 ( V_20 , V_27 , 0 ) ;
V_2 -> V_8 = F_12 ( & V_20 -> V_24 , V_22 ) ;
if ( F_13 ( V_2 -> V_8 ) )
return F_14 ( V_2 -> V_8 ) ;
V_2 -> V_2 . V_28 = V_20 -> V_28 ;
V_2 -> V_2 . V_29 = F_1 ;
V_2 -> V_2 . V_30 = F_5 ;
V_2 -> V_2 . V_31 = F_6 ;
V_23 = F_15 ( & V_20 -> V_24 , & V_2 -> V_2 ) ;
if ( V_23 ) {
F_16 ( & V_20 -> V_24 , L_1 ) ;
return V_23 ;
}
return 0 ;
}
