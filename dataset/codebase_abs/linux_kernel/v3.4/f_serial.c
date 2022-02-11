static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_6 , unsigned V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_11 -> V_10 ;
if ( V_8 -> V_4 . V_12 -> V_13 ) {
F_4 ( V_10 , L_1 , V_8 -> V_14 ) ;
F_5 ( & V_8 -> V_4 ) ;
}
if ( ! V_8 -> V_4 . V_12 -> V_15 || ! V_8 -> V_4 . V_16 -> V_15 ) {
F_4 ( V_10 , L_2 , V_8 -> V_14 ) ;
if ( F_6 ( V_10 -> V_17 , V_3 , V_8 -> V_4 . V_12 ) ||
F_6 ( V_10 -> V_17 , V_3 , V_8 -> V_4 . V_16 ) ) {
V_8 -> V_4 . V_12 -> V_15 = NULL ;
V_8 -> V_4 . V_16 -> V_15 = NULL ;
return - V_18 ;
}
}
F_7 ( & V_8 -> V_4 , V_8 -> V_14 ) ;
return 0 ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_11 -> V_10 ;
F_4 ( V_10 , L_3 , V_8 -> V_14 ) ;
F_5 ( & V_8 -> V_4 ) ;
}
static int T_1
F_9 ( struct V_19 * V_20 , struct V_2 * V_3 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_21 ;
struct V_22 * V_23 ;
V_21 = F_10 ( V_20 , V_3 ) ;
if ( V_21 < 0 )
goto V_24;
V_8 -> V_25 = V_21 ;
V_26 . V_27 = V_21 ;
V_21 = - V_28 ;
V_23 = F_11 ( V_10 -> V_17 , & V_29 ) ;
if ( ! V_23 )
goto V_24;
V_8 -> V_4 . V_12 = V_23 ;
V_23 -> V_13 = V_10 ;
V_23 = F_11 ( V_10 -> V_17 , & V_30 ) ;
if ( ! V_23 )
goto V_24;
V_8 -> V_4 . V_16 = V_23 ;
V_23 -> V_13 = V_10 ;
V_3 -> V_31 = F_12 ( V_32 ) ;
if ( F_13 ( V_20 -> V_10 -> V_17 ) ) {
V_33 . V_34 =
V_29 . V_34 ;
V_35 . V_34 =
V_30 . V_34 ;
V_3 -> V_36 = F_12 ( V_37 ) ;
}
if ( F_14 ( V_20 -> V_10 -> V_17 ) ) {
V_38 . V_34 =
V_29 . V_34 ;
V_39 . V_34 =
V_30 . V_34 ;
V_3 -> V_40 = F_12 ( V_41 ) ;
if ( ! V_3 -> V_40 )
goto V_24;
}
F_4 ( V_10 , L_4 ,
V_8 -> V_14 ,
F_14 ( V_20 -> V_10 -> V_17 ) ? L_5 :
F_13 ( V_20 -> V_10 -> V_17 ) ? L_6 : L_7 ,
V_8 -> V_4 . V_12 -> V_42 , V_8 -> V_4 . V_16 -> V_42 ) ;
return 0 ;
V_24:
if ( V_8 -> V_4 . V_16 )
V_8 -> V_4 . V_16 -> V_13 = NULL ;
if ( V_8 -> V_4 . V_12 )
V_8 -> V_4 . V_12 -> V_13 = NULL ;
ERROR ( V_10 , L_8 , V_3 -> V_42 , V_21 ) ;
return V_21 ;
}
static void
F_15 ( struct V_19 * V_20 , struct V_2 * V_3 )
{
if ( F_13 ( V_20 -> V_10 -> V_17 ) )
F_16 ( V_3 -> V_36 ) ;
if ( F_14 ( V_20 -> V_10 -> V_17 ) )
F_16 ( V_3 -> V_40 ) ;
F_16 ( V_3 -> V_31 ) ;
F_17 ( F_1 ( V_3 ) ) ;
}
int T_1 F_18 ( struct V_19 * V_20 , T_2 V_14 )
{
struct V_1 * V_8 ;
int V_21 ;
if ( V_43 [ 0 ] . V_44 == 0 ) {
V_21 = F_19 ( V_20 -> V_10 ) ;
if ( V_21 < 0 )
return V_21 ;
V_43 [ 0 ] . V_44 = V_21 ;
}
V_8 = F_20 ( sizeof *V_8 , V_45 ) ;
if ( ! V_8 )
return - V_46 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_4 . V_5 . V_42 = L_9 ;
V_8 -> V_4 . V_5 . V_47 = V_48 ;
V_8 -> V_4 . V_5 . V_49 = F_9 ;
V_8 -> V_4 . V_5 . V_50 = F_15 ;
V_8 -> V_4 . V_5 . V_51 = F_3 ;
V_8 -> V_4 . V_5 . V_52 = F_8 ;
V_21 = F_21 ( V_20 , & V_8 -> V_4 . V_5 ) ;
if ( V_21 )
F_17 ( V_8 ) ;
return V_21 ;
}
