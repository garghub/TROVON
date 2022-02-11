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
V_8 -> V_4 . V_16 = F_6 ( V_10 -> V_17 ,
V_8 -> V_18 . V_16 , V_8 -> V_19 . V_16 ) ;
V_8 -> V_4 . V_20 = F_6 ( V_10 -> V_17 ,
V_8 -> V_18 . V_20 , V_8 -> V_19 . V_20 ) ;
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
F_11 ( struct V_21 * V_22 , struct V_2 * V_3 )
{
struct V_9 * V_10 = V_22 -> V_10 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_23 ;
struct V_24 * V_25 ;
V_23 = F_12 ( V_22 , V_3 ) ;
if ( V_23 < 0 )
goto V_26;
V_27 . V_28 = V_23 ;
V_23 = - V_29 ;
V_25 = F_13 ( V_10 -> V_17 , & V_30 ) ;
if ( ! V_25 )
goto V_26;
V_8 -> V_4 . V_14 = V_25 ;
V_25 -> V_15 = V_10 ;
V_25 = F_13 ( V_10 -> V_17 , & V_31 ) ;
if ( ! V_25 )
goto V_26;
V_8 -> V_4 . V_32 = V_25 ;
V_25 -> V_15 = V_10 ;
V_3 -> V_33 = F_14 ( V_34 ) ;
V_8 -> V_19 . V_16 = F_15 ( V_34 ,
V_3 -> V_33 , & V_30 ) ;
V_8 -> V_19 . V_20 = F_15 ( V_34 ,
V_3 -> V_33 , & V_31 ) ;
if ( F_16 ( V_22 -> V_10 -> V_17 ) ) {
V_35 . V_36 =
V_30 . V_36 ;
V_37 . V_36 =
V_31 . V_36 ;
V_3 -> V_38 = F_14 ( V_39 ) ;
V_8 -> V_18 . V_16 = F_15 ( V_39 ,
V_3 -> V_38 , & V_35 ) ;
V_8 -> V_18 . V_20 = F_15 ( V_39 ,
V_3 -> V_38 , & V_37 ) ;
}
F_4 ( V_10 , L_4 ,
F_16 ( V_22 -> V_10 -> V_17 ) ? L_5 : L_6 ,
V_8 -> V_4 . V_14 -> V_40 , V_8 -> V_4 . V_32 -> V_40 ) ;
return 0 ;
V_26:
if ( V_8 -> V_4 . V_20 )
V_8 -> V_4 . V_32 -> V_15 = NULL ;
if ( V_8 -> V_4 . V_16 )
V_8 -> V_4 . V_14 -> V_15 = NULL ;
ERROR ( V_10 , L_7 , V_3 -> V_40 , V_23 ) ;
return V_23 ;
}
static void
F_17 ( struct V_21 * V_22 , struct V_2 * V_3 )
{
if ( F_16 ( V_22 -> V_10 -> V_17 ) )
F_18 ( V_3 -> V_38 ) ;
F_18 ( V_3 -> V_33 ) ;
V_41 [ 1 ] . V_42 = NULL ;
F_19 ( F_1 ( V_3 ) ) ;
}
int T_1 F_20 ( struct V_21 * V_22 , T_2 V_43 [ V_44 ] )
{
struct V_1 * V_8 ;
int V_23 ;
if ( ! V_43 )
return - V_45 ;
if ( V_41 [ 0 ] . V_46 == 0 ) {
V_23 = F_21 ( V_22 -> V_10 ) ;
if ( V_23 < 0 )
return V_23 ;
V_41 [ 0 ] . V_46 = V_23 ;
V_27 . V_47 = V_23 ;
V_23 = F_21 ( V_22 -> V_10 ) ;
if ( V_23 < 0 )
return V_23 ;
V_41 [ 1 ] . V_46 = V_23 ;
V_48 . V_49 = V_23 ;
}
V_8 = F_22 ( sizeof *V_8 , V_50 ) ;
if ( ! V_8 )
return - V_51 ;
snprintf ( V_8 -> V_43 , sizeof V_8 -> V_43 ,
L_8 ,
V_43 [ 0 ] , V_43 [ 1 ] , V_43 [ 2 ] ,
V_43 [ 3 ] , V_43 [ 4 ] , V_43 [ 5 ] ) ;
V_41 [ 1 ] . V_42 = V_8 -> V_43 ;
V_8 -> V_4 . V_52 = V_53 ;
V_8 -> V_4 . V_5 . V_40 = L_9 ;
V_8 -> V_4 . V_5 . V_54 = V_55 ;
V_8 -> V_4 . V_5 . V_56 = F_11 ;
V_8 -> V_4 . V_5 . V_57 = F_17 ;
V_8 -> V_4 . V_5 . V_58 = F_3 ;
V_8 -> V_4 . V_5 . V_59 = F_10 ;
V_23 = F_23 ( V_22 , & V_8 -> V_4 . V_5 ) ;
if ( V_23 ) {
V_41 [ 1 ] . V_42 = NULL ;
F_19 ( V_8 ) ;
}
return V_23 ;
}
