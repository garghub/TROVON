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
static inline bool F_15 ( struct V_27 * V_28 )
{
if ( ! F_16 ( V_28 -> V_12 -> V_22 ) )
return false ;
return true ;
}
static int F_17 ( struct V_27 * V_28 , struct V_2 * V_3 )
{
struct V_11 * V_12 = V_28 -> V_12 ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_25 ;
struct V_29 * V_30 ;
if ( ! F_15 ( V_28 ) )
return - V_23 ;
if ( V_31 [ V_32 ] . V_33 == 0 ) {
V_25 = F_18 ( V_28 -> V_12 , V_31 ) ;
if ( V_25 < 0 )
return V_25 ;
V_34 . V_35 =
V_31 [ V_32 ] . V_33 ;
V_25 = V_31 [ V_36 ] . V_33 ;
V_37 . V_35 = V_25 ;
V_38 . V_35 = V_25 ;
}
V_25 = F_19 ( V_28 , V_3 ) ;
if ( V_25 < 0 )
goto V_15;
V_10 -> V_14 = V_25 ;
V_34 . V_39 = V_25 ;
V_40 . V_41 = V_25 ;
V_25 = F_19 ( V_28 , V_3 ) ;
if ( V_25 < 0 )
goto V_15;
V_10 -> V_17 = V_25 ;
V_37 . V_39 = V_25 ;
V_38 . V_39 = V_25 ;
V_40 . V_42 = V_25 ;
V_25 = - V_43 ;
V_30 = F_20 ( V_12 -> V_22 , & V_44 ) ;
if ( ! V_30 )
goto V_15;
V_10 -> V_4 . V_18 = V_30 ;
V_30 -> V_19 = V_12 ;
V_30 = F_20 ( V_12 -> V_22 , & V_45 ) ;
if ( ! V_30 )
goto V_15;
V_10 -> V_4 . V_21 = V_30 ;
V_30 -> V_19 = V_12 ;
V_46 . V_47 =
V_44 . V_47 ;
V_48 . V_47 =
V_45 . V_47 ;
V_25 = F_21 ( V_3 , V_49 , V_50 , NULL ) ;
if ( V_25 )
goto V_15;
V_25 = F_14 ( V_3 ) ;
if ( V_25 < 0 )
F_22 ( V_12 , L_8 ,
V_10 -> V_16 , V_25 ) ;
else
V_10 -> V_26 = true ;
F_5 ( V_12 , L_9 ,
V_10 -> V_16 ,
F_23 ( V_28 -> V_12 -> V_22 ) ? L_10 : L_11 ,
V_10 -> V_4 . V_18 -> V_51 , V_10 -> V_4 . V_21 -> V_51 ) ;
return 0 ;
V_15:
F_24 ( V_3 ) ;
if ( V_10 -> V_4 . V_21 )
V_10 -> V_4 . V_21 -> V_19 = NULL ;
if ( V_10 -> V_4 . V_18 )
V_10 -> V_4 . V_18 -> V_19 = NULL ;
ERROR ( V_12 , L_12 , V_3 -> V_51 , V_3 , V_25 ) ;
return V_25 ;
}
static void
F_25 ( struct V_27 * V_28 , struct V_2 * V_3 )
{
V_31 [ V_32 ] . V_33 = 0 ;
F_24 ( V_3 ) ;
F_26 ( F_1 ( V_3 ) ) ;
}
int T_1 F_27 ( struct V_27 * V_28 , T_2 V_16 )
{
struct V_1 * V_10 ;
int V_25 ;
V_10 = F_28 ( sizeof *V_10 , V_52 ) ;
if ( ! V_10 )
return - V_53 ;
V_10 -> V_16 = V_16 ;
V_10 -> V_4 . V_54 = F_11 ;
V_10 -> V_4 . V_55 = F_13 ;
V_10 -> V_4 . V_5 . V_51 = L_13 ;
V_10 -> V_4 . V_5 . V_56 = V_57 ;
V_10 -> V_4 . V_5 . V_58 = F_17 ;
V_10 -> V_4 . V_5 . V_59 = F_25 ;
V_10 -> V_4 . V_5 . V_60 = F_4 ;
V_10 -> V_4 . V_5 . V_61 = F_9 ;
V_10 -> V_4 . V_5 . V_62 = F_10 ;
V_25 = F_29 ( V_28 , & V_10 -> V_4 . V_5 ) ;
if ( V_25 )
F_26 ( V_10 ) ;
return V_25 ;
}
static inline struct V_63 * F_30 ( struct V_64 * V_65 )
{
return F_2 ( F_31 ( V_65 ) , struct V_63 ,
V_66 . V_67 ) ;
}
static T_3 F_32 ( struct V_64 * V_65 ,
struct V_68 * V_69 ,
char * V_70 )
{
struct V_63 * V_71 = F_30 ( V_65 ) ;
struct V_72 * V_73 =
F_2 ( V_69 , struct V_72 , V_69 ) ;
T_3 V_74 = 0 ;
if ( V_73 -> V_75 )
V_74 = V_73 -> V_75 ( V_71 , V_70 ) ;
return V_74 ;
}
static void F_33 ( struct V_64 * V_65 )
{
struct V_63 * V_71 = F_30 ( V_65 ) ;
F_34 ( & V_71 -> V_66 ) ;
}
static T_3 F_35 ( struct V_63 * V_71 , char * V_70 )
{
return sprintf ( V_70 , L_14 , V_71 -> V_16 ) ;
}
static void F_36 ( struct V_76 * V_3 )
{
struct V_63 * V_71 ;
V_71 = F_2 ( V_3 , struct V_63 , V_66 ) ;
F_37 ( V_71 -> V_16 ) ;
F_26 ( V_71 ) ;
}
static struct V_76 * F_38 ( void )
{
struct V_63 * V_71 ;
int V_74 ;
V_71 = F_28 ( sizeof( * V_71 ) , V_52 ) ;
if ( ! V_71 )
return F_39 ( - V_53 ) ;
V_71 -> V_66 . V_77 = F_36 ;
V_74 = F_40 ( & V_71 -> V_16 ) ;
if ( V_74 ) {
F_26 ( V_71 ) ;
return F_39 ( V_74 ) ;
}
F_41 ( & V_71 -> V_66 . V_67 , L_15 ,
& V_78 ) ;
return & V_71 -> V_66 ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_10 ;
V_10 = F_1 ( V_3 ) ;
F_26 ( V_10 ) ;
}
static void F_43 ( struct V_27 * V_28 , struct V_2 * V_3 )
{
V_31 [ V_32 ] . V_33 = 0 ;
F_24 ( V_3 ) ;
}
struct V_2 * F_44 ( struct V_76 * V_79 )
{
struct V_1 * V_10 ;
struct V_63 * V_71 ;
V_10 = F_28 ( sizeof( * V_10 ) , V_52 ) ;
if ( ! V_10 )
return F_39 ( - V_53 ) ;
V_71 = F_2 ( V_79 , struct V_63 , V_66 ) ;
V_10 -> V_16 = V_71 -> V_16 ;
V_10 -> V_4 . V_54 = F_11 ;
V_10 -> V_4 . V_55 = F_13 ;
V_10 -> V_4 . V_5 . V_51 = L_13 ;
V_10 -> V_4 . V_5 . V_56 = V_57 ;
V_10 -> V_4 . V_5 . V_58 = F_17 ;
V_10 -> V_4 . V_5 . V_59 = F_43 ;
V_10 -> V_4 . V_5 . V_60 = F_4 ;
V_10 -> V_4 . V_5 . V_61 = F_9 ;
V_10 -> V_4 . V_5 . V_62 = F_10 ;
V_10 -> V_4 . V_5 . V_80 = F_42 ;
return & V_10 -> V_4 . V_5 ;
}
