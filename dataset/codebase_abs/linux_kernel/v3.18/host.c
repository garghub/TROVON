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
V_4 -> V_24 = V_2 -> V_21 -> V_24 ;
V_7 = F_8 ( V_4 ) ;
V_7 -> V_25 = V_2 -> V_14 . V_26 ;
V_7 -> V_27 = V_2 -> V_14 . V_28 ;
V_7 -> V_29 = V_2 -> V_14 . V_28 ;
V_7 -> V_30 = V_2 -> V_30 ;
if ( V_2 -> V_21 -> V_31 && ! F_9 ( V_2 ) ) {
V_8 = F_10 ( V_2 -> V_21 -> V_31 ) ;
if ( V_8 ) {
F_11 ( V_2 -> V_11 ,
L_1 ,
V_8 ) ;
goto V_32;
}
}
V_8 = F_12 ( V_4 , 0 , 0 ) ;
if ( V_8 ) {
goto V_33;
} else {
struct V_34 * V_35 = V_2 -> V_23 -> V_35 ;
V_2 -> V_4 = V_4 ;
if ( V_35 ) {
V_35 -> V_36 = & V_4 -> V_37 ;
V_4 -> V_37 . V_38 = 1 ;
}
}
if ( V_2 -> V_21 -> V_39 & V_40 )
F_13 ( V_2 , V_41 , V_42 , V_42 ) ;
return V_8 ;
V_33:
if ( V_2 -> V_21 -> V_31 && ! F_9 ( V_2 ) )
F_14 ( V_2 -> V_21 -> V_31 ) ;
V_32:
F_15 ( V_4 ) ;
return V_8 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_4 = V_2 -> V_4 ;
if ( V_4 ) {
F_17 ( V_4 ) ;
F_15 ( V_4 ) ;
if ( V_2 -> V_21 -> V_31 && ! F_9 ( V_2 ) )
F_14 ( V_2 -> V_21 -> V_31 ) ;
}
}
void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_43 == V_44 && V_2 -> V_4 )
F_16 ( V_2 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_45 * V_46 ;
if ( ! F_20 ( V_2 , V_47 , V_48 ) )
return - V_49 ;
V_46 = F_21 ( V_2 -> V_11 , sizeof( struct V_45 ) , V_50 ) ;
if ( ! V_46 )
return - V_12 ;
V_46 -> V_51 = F_3 ;
V_46 -> V_52 = F_16 ;
V_46 -> V_3 = F_1 ;
V_46 -> V_53 = L_2 ;
V_2 -> V_54 [ V_44 ] = V_46 ;
F_22 ( & V_10 , NULL ) ;
return 0 ;
}
