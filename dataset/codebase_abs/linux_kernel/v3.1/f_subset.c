static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_6 , unsigned V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_11 -> V_10 ;
struct V_12 * V_13 ;
if ( V_8 -> V_4 . V_14 -> V_15 ) {
F_4 ( V_10 , L_1 ) ;
F_5 ( & V_8 -> V_4 ) ;
}
F_4 ( V_10 , L_2 ) ;
if ( F_6 ( V_10 -> V_16 , V_3 , V_8 -> V_4 . V_14 ) ||
F_6 ( V_10 -> V_16 , V_3 , V_8 -> V_4 . V_17 ) ) {
V_8 -> V_4 . V_14 -> V_18 = NULL ;
V_8 -> V_4 . V_17 -> V_18 = NULL ;
return - V_19 ;
}
V_13 = F_7 ( & V_8 -> V_4 ) ;
return F_8 ( V_13 ) ? F_9 ( V_13 ) : 0 ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_11 -> V_10 ;
F_4 ( V_10 , L_3 ) ;
F_5 ( & V_8 -> V_4 ) ;
}
static int T_1
F_11 ( struct V_20 * V_21 , struct V_2 * V_3 )
{
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_22 ;
struct V_23 * V_24 ;
V_22 = F_12 ( V_21 , V_3 ) ;
if ( V_22 < 0 )
goto V_25;
V_26 . V_27 = V_22 ;
V_22 = - V_28 ;
V_24 = F_13 ( V_10 -> V_16 , & V_29 ) ;
if ( ! V_24 )
goto V_25;
V_8 -> V_4 . V_14 = V_24 ;
V_24 -> V_15 = V_10 ;
V_24 = F_13 ( V_10 -> V_16 , & V_30 ) ;
if ( ! V_24 )
goto V_25;
V_8 -> V_4 . V_17 = V_24 ;
V_24 -> V_15 = V_10 ;
V_3 -> V_31 = F_14 ( V_32 ) ;
if ( ! V_3 -> V_31 )
goto V_25;
if ( F_15 ( V_21 -> V_10 -> V_16 ) ) {
V_33 . V_34 =
V_29 . V_34 ;
V_35 . V_34 =
V_30 . V_34 ;
V_3 -> V_36 = F_14 ( V_37 ) ;
if ( ! V_3 -> V_36 )
goto V_25;
}
if ( F_16 ( V_21 -> V_10 -> V_16 ) ) {
V_38 . V_34 =
V_29 . V_34 ;
V_39 . V_34 =
V_30 . V_34 ;
V_3 -> V_40 = F_14 ( V_41 ) ;
if ( ! V_3 -> V_40 )
goto V_25;
}
F_4 ( V_10 , L_4 ,
F_16 ( V_21 -> V_10 -> V_16 ) ? L_5 :
F_15 ( V_21 -> V_10 -> V_16 ) ? L_6 : L_7 ,
V_8 -> V_4 . V_14 -> V_42 , V_8 -> V_4 . V_17 -> V_42 ) ;
return 0 ;
V_25:
if ( V_3 -> V_31 )
F_17 ( V_3 -> V_31 ) ;
if ( V_3 -> V_36 )
F_17 ( V_3 -> V_36 ) ;
if ( V_8 -> V_4 . V_17 -> V_18 )
V_8 -> V_4 . V_17 -> V_15 = NULL ;
if ( V_8 -> V_4 . V_14 -> V_18 )
V_8 -> V_4 . V_14 -> V_15 = NULL ;
ERROR ( V_10 , L_8 , V_3 -> V_42 , V_22 ) ;
return V_22 ;
}
static void
F_18 ( struct V_20 * V_21 , struct V_2 * V_3 )
{
if ( F_16 ( V_21 -> V_10 -> V_16 ) )
F_17 ( V_3 -> V_40 ) ;
if ( F_15 ( V_21 -> V_10 -> V_16 ) )
F_17 ( V_3 -> V_36 ) ;
F_17 ( V_3 -> V_31 ) ;
V_43 [ 1 ] . V_44 = NULL ;
F_19 ( F_1 ( V_3 ) ) ;
}
int T_1 F_20 ( struct V_20 * V_21 , T_2 V_45 [ V_46 ] )
{
struct V_1 * V_8 ;
int V_22 ;
if ( ! V_45 )
return - V_19 ;
if ( V_43 [ 0 ] . V_47 == 0 ) {
V_22 = F_21 ( V_21 -> V_10 ) ;
if ( V_22 < 0 )
return V_22 ;
V_43 [ 0 ] . V_47 = V_22 ;
V_26 . V_48 = V_22 ;
V_22 = F_21 ( V_21 -> V_10 ) ;
if ( V_22 < 0 )
return V_22 ;
V_43 [ 1 ] . V_47 = V_22 ;
V_49 . V_50 = V_22 ;
}
V_8 = F_22 ( sizeof *V_8 , V_51 ) ;
if ( ! V_8 )
return - V_52 ;
snprintf ( V_8 -> V_45 , sizeof V_8 -> V_45 ,
L_9 ,
V_45 [ 0 ] , V_45 [ 1 ] , V_45 [ 2 ] ,
V_45 [ 3 ] , V_45 [ 4 ] , V_45 [ 5 ] ) ;
V_43 [ 1 ] . V_44 = V_8 -> V_45 ;
V_8 -> V_4 . V_53 = V_54 ;
V_8 -> V_4 . V_5 . V_42 = L_10 ;
V_8 -> V_4 . V_5 . V_55 = V_56 ;
V_8 -> V_4 . V_5 . V_57 = F_11 ;
V_8 -> V_4 . V_5 . V_58 = F_18 ;
V_8 -> V_4 . V_5 . V_59 = F_3 ;
V_8 -> V_4 . V_5 . V_60 = F_10 ;
V_22 = F_23 ( V_21 , & V_8 -> V_4 . V_5 ) ;
if ( V_22 ) {
V_43 [ 1 ] . V_44 = NULL ;
F_19 ( V_8 ) ;
}
return V_22 ;
}
