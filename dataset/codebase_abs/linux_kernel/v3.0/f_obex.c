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
if ( ! V_10 -> V_4 . V_20 ) {
F_5 ( V_12 , L_3 , V_10 -> V_16 ) ;
V_10 -> V_4 . V_20 = F_7 ( V_12 -> V_21 ,
V_10 -> V_22 . V_23 , V_10 -> V_24 . V_23 ) ;
V_10 -> V_4 . V_25 = F_7 ( V_12 -> V_21 ,
V_10 -> V_22 . V_26 , V_10 -> V_24 . V_26 ) ;
}
if ( V_9 == 1 ) {
F_5 ( V_12 , L_4 , V_10 -> V_16 ) ;
F_8 ( & V_10 -> V_4 , V_10 -> V_16 ) ;
}
} else
goto V_15;
return 0 ;
V_15:
return - V_27 ;
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
static void F_11 ( struct V_6 * V_28 )
{
struct V_1 * V_10 = F_3 ( V_28 ) ;
struct V_11 * V_12 = V_28 -> V_5 . V_13 -> V_12 ;
int V_29 ;
if ( ! V_10 -> V_30 )
return;
V_29 = F_12 ( & V_28 -> V_5 ) ;
if ( V_29 )
F_5 ( V_12 , L_6 ,
V_10 -> V_16 , V_29 ) ;
}
static void F_13 ( struct V_6 * V_28 )
{
struct V_1 * V_10 = F_3 ( V_28 ) ;
struct V_11 * V_12 = V_28 -> V_5 . V_13 -> V_12 ;
int V_29 ;
if ( ! V_10 -> V_30 )
return;
V_29 = F_14 ( & V_28 -> V_5 ) ;
if ( V_29 )
F_5 ( V_12 , L_7 ,
V_10 -> V_16 , V_29 ) ;
}
static int T_1
F_15 ( struct V_31 * V_32 , struct V_2 * V_3 )
{
struct V_11 * V_12 = V_32 -> V_12 ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_29 ;
struct V_33 * V_34 ;
V_29 = F_16 ( V_32 , V_3 ) ;
if ( V_29 < 0 )
goto V_15;
V_10 -> V_14 = V_29 ;
V_35 . V_36 = V_29 ;
V_37 . V_38 = V_29 ;
V_29 = F_16 ( V_32 , V_3 ) ;
if ( V_29 < 0 )
goto V_15;
V_10 -> V_17 = V_29 ;
V_39 . V_36 = V_29 ;
V_40 . V_36 = V_29 ;
V_37 . V_41 = V_29 ;
V_34 = F_17 ( V_12 -> V_21 , & V_42 ) ;
if ( ! V_34 )
goto V_15;
V_10 -> V_4 . V_18 = V_34 ;
V_34 -> V_19 = V_12 ;
V_34 = F_17 ( V_12 -> V_21 , & V_43 ) ;
if ( ! V_34 )
goto V_15;
V_10 -> V_4 . V_44 = V_34 ;
V_34 -> V_19 = V_12 ;
V_3 -> V_45 = F_18 ( V_46 ) ;
V_10 -> V_24 . V_23 = F_19 ( V_46 ,
V_3 -> V_45 , & V_42 ) ;
V_10 -> V_24 . V_26 = F_19 ( V_46 ,
V_3 -> V_45 , & V_43 ) ;
if ( F_20 ( V_32 -> V_12 -> V_21 ) ) {
V_47 . V_48 =
V_42 . V_48 ;
V_49 . V_48 =
V_43 . V_48 ;
V_3 -> V_50 = F_18 ( V_51 ) ;
V_10 -> V_22 . V_23 = F_19 ( V_51 ,
V_3 -> V_50 , & V_47 ) ;
V_10 -> V_22 . V_26 = F_19 ( V_51 ,
V_3 -> V_50 , & V_49 ) ;
}
V_29 = F_14 ( V_3 ) ;
if ( V_29 < 0 )
F_21 ( V_12 , L_8 ,
V_10 -> V_16 , V_29 ) ;
else
V_10 -> V_30 = true ;
F_5 ( V_12 , L_9 ,
V_10 -> V_16 ,
F_20 ( V_32 -> V_12 -> V_21 ) ? L_10 : L_11 ,
V_10 -> V_4 . V_18 -> V_52 , V_10 -> V_4 . V_44 -> V_52 ) ;
return 0 ;
V_15:
if ( V_10 -> V_4 . V_44 )
V_10 -> V_4 . V_44 -> V_19 = NULL ;
if ( V_10 -> V_4 . V_18 )
V_10 -> V_4 . V_18 -> V_19 = NULL ;
ERROR ( V_12 , L_12 , V_3 -> V_52 , V_3 , V_29 ) ;
return V_29 ;
}
static void
F_22 ( struct V_31 * V_32 , struct V_2 * V_3 )
{
if ( F_20 ( V_32 -> V_12 -> V_21 ) )
F_23 ( V_3 -> V_50 ) ;
F_23 ( V_3 -> V_45 ) ;
F_24 ( F_1 ( V_3 ) ) ;
}
static inline bool F_25 ( struct V_31 * V_32 )
{
if ( ! F_26 ( V_32 -> V_12 -> V_21 ) )
return false ;
return true ;
}
int T_1 F_27 ( struct V_31 * V_32 , T_2 V_16 )
{
struct V_1 * V_10 ;
int V_29 ;
if ( ! F_25 ( V_32 ) )
return - V_27 ;
if ( V_53 [ V_54 ] . V_55 == 0 ) {
V_29 = F_28 ( V_32 -> V_12 ) ;
if ( V_29 < 0 )
return V_29 ;
V_53 [ V_54 ] . V_55 = V_29 ;
V_35 . V_56 = V_29 ;
V_29 = F_28 ( V_32 -> V_12 ) ;
if ( V_29 < 0 )
return V_29 ;
V_53 [ V_57 ] . V_55 = V_29 ;
V_39 . V_56 =
V_40 . V_56 = V_29 ;
}
V_10 = F_29 ( sizeof *V_10 , V_58 ) ;
if ( ! V_10 )
return - V_59 ;
V_10 -> V_16 = V_16 ;
V_10 -> V_4 . V_60 = F_11 ;
V_10 -> V_4 . V_61 = F_13 ;
V_10 -> V_4 . V_5 . V_52 = L_13 ;
V_10 -> V_4 . V_5 . V_62 = V_63 ;
V_10 -> V_4 . V_5 . V_64 = F_15 ;
V_10 -> V_4 . V_5 . V_65 = F_22 ;
V_10 -> V_4 . V_5 . V_66 = F_4 ;
V_10 -> V_4 . V_5 . V_67 = F_9 ;
V_10 -> V_4 . V_5 . V_68 = F_10 ;
V_29 = F_30 ( V_32 , & V_10 -> V_4 . V_5 ) ;
if ( V_29 )
F_24 ( V_10 ) ;
return V_29 ;
}
