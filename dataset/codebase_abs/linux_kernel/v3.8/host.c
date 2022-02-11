static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_2 -> V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_4 ;
struct V_6 * V_7 ;
int V_8 ;
if ( F_4 () )
return - V_9 ;
V_4 = F_5 ( & V_10 , V_2 -> V_11 , F_6 ( V_2 -> V_11 ) ) ;
if ( ! V_4 )
return - V_12 ;
F_7 ( V_2 -> V_11 , V_2 ) ;
V_4 -> V_13 = V_2 -> V_14 . V_15 ;
V_4 -> V_16 = V_2 -> V_14 . V_17 ;
V_4 -> V_18 = V_2 -> V_14 . abs ;
V_4 -> V_19 = 1 ;
V_4 -> V_20 = V_2 -> V_21 -> V_20 ;
V_4 -> V_22 = V_2 -> V_23 ;
V_7 = F_8 ( V_4 ) ;
V_7 -> V_24 = V_2 -> V_14 . V_25 ;
V_7 -> V_26 = V_2 -> V_14 . V_27 ;
V_8 = F_9 ( V_4 , 0 , 0 ) ;
if ( V_8 )
F_10 ( V_4 ) ;
else
V_2 -> V_4 = V_4 ;
if ( V_2 -> V_21 -> V_28 & V_29 )
F_11 ( V_2 , V_30 , V_31 , V_31 ) ;
return V_8 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_4 = V_2 -> V_4 ;
F_13 ( V_4 ) ;
F_10 ( V_4 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
if ( ! F_15 ( V_2 , V_34 , V_35 ) )
return - V_36 ;
V_33 = F_16 ( V_2 -> V_11 , sizeof( struct V_32 ) , V_37 ) ;
if ( ! V_33 )
return - V_12 ;
V_33 -> V_38 = F_3 ;
V_33 -> V_39 = F_12 ;
V_33 -> V_3 = F_1 ;
V_33 -> V_40 = L_1 ;
V_2 -> V_41 [ V_42 ] = V_33 ;
F_17 ( & V_10 , NULL ) ;
return 0 ;
}
