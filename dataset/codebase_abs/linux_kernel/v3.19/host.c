static int F_1 ( struct V_1 * V_2 , int V_3 , bool V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = (struct V_7 * ) V_6 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 . V_12 ;
struct V_13 * V_14 = F_3 ( V_10 ) ;
int V_15 = 0 ;
int V_16 = F_4 ( V_6 -> V_17 ) ;
if ( V_8 -> V_18 && ! F_5 ( V_14 ) ) {
if ( V_16 > 1 ) {
F_6 ( V_10 ,
L_1 ) ;
return 0 ;
}
if ( V_4 )
V_15 = F_7 ( V_8 -> V_18 ) ;
else
V_15 = F_8 ( V_8 -> V_18 ) ;
if ( V_15 ) {
F_9 ( V_10 ,
L_2 ,
V_4 ? L_3 : L_4 , V_15 ) ;
return V_15 ;
}
}
return 0 ;
}
static T_1 F_10 ( struct V_13 * V_14 )
{
return F_11 ( V_14 -> V_19 , V_14 -> V_2 ) ;
}
static int F_12 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_15 ;
if ( F_13 () )
return - V_20 ;
V_2 = F_14 ( & V_21 , V_14 -> V_10 , F_15 ( V_14 -> V_10 ) ) ;
if ( ! V_2 )
return - V_22 ;
F_16 ( V_14 -> V_10 , V_14 ) ;
V_2 -> V_23 = V_14 -> V_24 . V_25 ;
V_2 -> V_26 = V_14 -> V_24 . V_27 ;
V_2 -> V_28 = V_14 -> V_24 . abs ;
V_2 -> V_29 = 1 ;
V_2 -> V_30 = V_14 -> V_31 -> V_30 ;
V_2 -> V_32 = V_14 -> V_31 -> V_32 ;
if ( V_14 -> V_33 )
V_2 -> V_33 = V_14 -> V_33 ;
else
V_2 -> V_34 = V_14 -> V_34 ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_35 = V_14 -> V_24 . V_36 ;
V_6 -> V_37 = V_14 -> V_24 . V_38 ;
V_6 -> V_39 = V_14 -> V_24 . V_38 ;
V_6 -> V_40 = V_14 -> V_40 ;
V_8 = (struct V_7 * ) V_6 -> V_8 ;
V_8 -> V_18 = NULL ;
if ( V_14 -> V_31 -> V_18 )
V_8 -> V_18 = V_14 -> V_31 -> V_18 ;
V_15 = F_17 ( V_2 , 0 , 0 ) ;
if ( V_15 ) {
goto V_41;
} else {
struct V_42 * V_43 = & V_14 -> V_43 ;
V_14 -> V_2 = V_2 ;
if ( F_5 ( V_14 ) ) {
V_43 -> V_44 = & V_2 -> V_11 ;
V_2 -> V_11 . V_45 = 1 ;
}
}
if ( V_14 -> V_31 -> V_46 & V_47 )
F_18 ( V_14 , V_48 , V_49 , V_49 ) ;
return V_15 ;
V_41:
F_19 ( V_2 ) ;
return V_15 ;
}
static void F_20 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
if ( V_2 ) {
F_21 ( V_2 ) ;
F_19 ( V_2 ) ;
}
}
void F_22 ( struct V_13 * V_14 )
{
if ( V_14 -> V_50 == V_51 && V_14 -> V_2 )
F_20 ( V_14 ) ;
}
int F_23 ( struct V_13 * V_14 )
{
struct V_52 * V_53 ;
if ( ! F_24 ( V_14 , V_54 , V_55 ) )
return - V_56 ;
V_53 = F_25 ( V_14 -> V_10 , sizeof( struct V_52 ) , V_57 ) ;
if ( ! V_53 )
return - V_22 ;
V_53 -> V_58 = F_12 ;
V_53 -> V_59 = F_20 ;
V_53 -> V_19 = F_10 ;
V_53 -> V_60 = L_5 ;
V_14 -> V_61 [ V_51 ] = V_53 ;
F_26 ( & V_21 , & V_62 ) ;
return 0 ;
}
