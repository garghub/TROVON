static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static inline struct V_1 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_1 , V_4 ) ;
}
static int F_4 ( struct V_2 * V_3 , unsigned V_8 , unsigned V_9 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_11 * V_12 = V_3 -> V_13 -> V_12 ;
if ( V_8 == V_10 -> V_14 ) {
if ( V_9 != 0 )
goto V_15;
F_5 ( V_12 , L_1 , V_10 -> V_16 ) ;
} else if ( V_8 == V_10 -> V_17 ) {
if ( V_9 > 1 )
goto V_15;
if ( V_10 -> V_4 . V_18 -> V_19 ) {
F_5 ( V_12 , L_2 , V_10 -> V_16 ) ;
F_6 ( & V_10 -> V_4 ) ;
}
if ( ! V_10 -> V_4 . V_18 -> V_20 || ! V_10 -> V_4 . V_21 -> V_20 ) {
F_5 ( V_12 , L_3 , V_10 -> V_16 ) ;
if ( F_7 ( V_12 -> V_22 , V_3 ,
V_10 -> V_4 . V_18 ) ||
F_7 ( V_12 -> V_22 , V_3 ,
V_10 -> V_4 . V_21 ) ) {
V_10 -> V_4 . V_21 -> V_20 = NULL ;
V_10 -> V_4 . V_18 -> V_20 = NULL ;
goto V_15;
}
}
if ( V_9 == 1 ) {
F_5 ( V_12 , L_4 , V_10 -> V_16 ) ;
F_8 ( & V_10 -> V_4 , V_10 -> V_16 ) ;
}
} else
goto V_15;
return 0 ;
V_15:
return - V_23 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_8 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( V_8 == V_10 -> V_14 )
return 0 ;
return V_10 -> V_4 . V_18 -> V_19 ? 1 : 0 ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_11 * V_12 = V_3 -> V_13 -> V_12 ;
F_5 ( V_12 , L_5 , V_10 -> V_16 ) ;
F_6 ( & V_10 -> V_4 ) ;
}
static void F_11 ( struct V_6 * V_24 )
{
struct V_1 * V_10 = F_3 ( V_24 ) ;
struct V_11 * V_12 = V_24 -> V_5 . V_13 -> V_12 ;
int V_25 ;
if ( ! V_10 -> V_26 )
return;
V_25 = F_12 ( & V_24 -> V_5 ) ;
if ( V_25 )
F_5 ( V_12 , L_6 ,
V_10 -> V_16 , V_25 ) ;
}
static void F_13 ( struct V_6 * V_24 )
{
struct V_1 * V_10 = F_3 ( V_24 ) ;
struct V_11 * V_12 = V_24 -> V_5 . V_13 -> V_12 ;
int V_25 ;
if ( ! V_10 -> V_26 )
return;
V_25 = F_14 ( & V_24 -> V_5 ) ;
if ( V_25 )
F_5 ( V_12 , L_7 ,
V_10 -> V_16 , V_25 ) ;
}
static int T_1
F_15 ( struct V_27 * V_28 , struct V_2 * V_3 )
{
struct V_11 * V_12 = V_28 -> V_12 ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_25 ;
struct V_29 * V_30 ;
V_25 = F_16 ( V_28 , V_3 ) ;
if ( V_25 < 0 )
goto V_15;
V_10 -> V_14 = V_25 ;
V_31 . V_32 = V_25 ;
V_33 . V_34 = V_25 ;
V_25 = F_16 ( V_28 , V_3 ) ;
if ( V_25 < 0 )
goto V_15;
V_10 -> V_17 = V_25 ;
V_35 . V_32 = V_25 ;
V_36 . V_32 = V_25 ;
V_33 . V_37 = V_25 ;
V_30 = F_17 ( V_12 -> V_22 , & V_38 ) ;
if ( ! V_30 )
goto V_15;
V_10 -> V_4 . V_18 = V_30 ;
V_30 -> V_19 = V_12 ;
V_30 = F_17 ( V_12 -> V_22 , & V_39 ) ;
if ( ! V_30 )
goto V_15;
V_10 -> V_4 . V_21 = V_30 ;
V_30 -> V_19 = V_12 ;
V_40 . V_41 =
V_38 . V_41 ;
V_42 . V_41 =
V_39 . V_41 ;
V_25 = F_18 ( V_3 , V_43 , V_44 , NULL ) ;
if ( V_25 )
goto V_15;
V_25 = F_14 ( V_3 ) ;
if ( V_25 < 0 )
F_19 ( V_12 , L_8 ,
V_10 -> V_16 , V_25 ) ;
else
V_10 -> V_26 = true ;
F_5 ( V_12 , L_9 ,
V_10 -> V_16 ,
F_20 ( V_28 -> V_12 -> V_22 ) ? L_10 : L_11 ,
V_10 -> V_4 . V_18 -> V_45 , V_10 -> V_4 . V_21 -> V_45 ) ;
return 0 ;
V_15:
F_21 ( V_3 ) ;
if ( V_10 -> V_4 . V_21 )
V_10 -> V_4 . V_21 -> V_19 = NULL ;
if ( V_10 -> V_4 . V_18 )
V_10 -> V_4 . V_18 -> V_19 = NULL ;
ERROR ( V_12 , L_12 , V_3 -> V_45 , V_3 , V_25 ) ;
return V_25 ;
}
static void
F_22 ( struct V_27 * V_28 , struct V_2 * V_3 )
{
V_46 [ V_47 ] . V_48 = 0 ;
F_21 ( V_3 ) ;
F_23 ( F_1 ( V_3 ) ) ;
}
static inline bool F_24 ( struct V_27 * V_28 )
{
if ( ! F_25 ( V_28 -> V_12 -> V_22 ) )
return false ;
return true ;
}
int T_1 F_26 ( struct V_27 * V_28 , T_2 V_16 )
{
struct V_1 * V_10 ;
int V_25 ;
if ( ! F_24 ( V_28 ) )
return - V_23 ;
if ( V_46 [ V_47 ] . V_48 == 0 ) {
V_25 = F_27 ( V_28 -> V_12 , V_46 ) ;
if ( V_25 < 0 )
return V_25 ;
V_31 . V_49 =
V_46 [ V_47 ] . V_48 ;
V_25 = V_46 [ V_50 ] . V_48 ;
V_35 . V_49 = V_25 ;
V_36 . V_49 = V_25 ;
}
V_10 = F_28 ( sizeof *V_10 , V_51 ) ;
if ( ! V_10 )
return - V_52 ;
V_10 -> V_16 = V_16 ;
V_10 -> V_4 . V_53 = F_11 ;
V_10 -> V_4 . V_54 = F_13 ;
V_10 -> V_4 . V_5 . V_45 = L_13 ;
V_10 -> V_4 . V_5 . V_55 = V_56 ;
V_10 -> V_4 . V_5 . V_57 = F_15 ;
V_10 -> V_4 . V_5 . V_58 = F_22 ;
V_10 -> V_4 . V_5 . V_59 = F_4 ;
V_10 -> V_4 . V_5 . V_60 = F_9 ;
V_10 -> V_4 . V_5 . V_61 = F_10 ;
V_25 = F_29 ( V_28 , & V_10 -> V_4 . V_5 ) ;
if ( V_25 )
F_23 ( V_10 ) ;
return V_25 ;
}
