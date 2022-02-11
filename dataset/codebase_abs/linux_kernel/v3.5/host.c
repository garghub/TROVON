static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_2 -> V_6 = 1 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_4 ( V_4 , 0 ) ;
return V_5 ;
}
static T_1 F_5 ( struct V_7 * V_8 )
{
return F_6 ( V_8 -> V_9 , V_8 -> V_2 ) ;
}
static int F_7 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_5 ;
if ( F_8 () )
return - V_10 ;
V_2 = F_9 ( & V_11 , V_8 -> V_12 , F_10 ( V_8 -> V_12 ) ) ;
if ( ! V_2 )
return - V_13 ;
F_11 ( V_8 -> V_12 , V_8 ) ;
V_2 -> V_14 = V_8 -> V_15 . V_16 ;
V_2 -> V_17 = V_8 -> V_15 . V_18 ;
V_2 -> V_19 = V_8 -> V_15 . abs ;
V_2 -> V_6 = 1 ;
V_2 -> V_20 = V_8 -> V_21 -> V_20 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_22 = V_8 -> V_15 . V_23 ;
V_4 -> V_24 = V_8 -> V_15 . V_25 ;
V_5 = F_12 ( V_2 , 0 , 0 ) ;
if ( V_5 )
F_13 ( V_2 ) ;
else
V_8 -> V_2 = V_2 ;
return V_5 ;
}
static void F_14 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_15 ( V_2 ) ;
F_13 ( V_2 ) ;
}
int F_16 ( struct V_7 * V_8 )
{
struct V_26 * V_27 ;
if ( ! F_17 ( V_8 , V_28 , V_29 ) )
return - V_30 ;
V_27 = F_18 ( V_8 -> V_12 , sizeof( struct V_26 ) , V_31 ) ;
if ( ! V_27 )
return - V_13 ;
V_27 -> V_32 = F_7 ;
V_27 -> V_33 = F_14 ;
V_27 -> V_9 = F_5 ;
V_27 -> V_34 = L_1 ;
V_8 -> V_35 [ V_36 ] = V_27 ;
return 0 ;
}
