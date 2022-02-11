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
struct V_29 * V_30 ;
int V_25 ;
struct V_31 * V_32 ;
if ( ! F_15 ( V_28 ) )
return - V_23 ;
V_30 = F_18 ( V_12 , V_33 ,
F_19 ( V_34 ) ) ;
if ( F_20 ( V_30 ) )
return F_21 ( V_30 ) ;
V_35 . V_36 = V_30 [ V_37 ] . V_38 ;
V_39 . V_36 = V_30 [ V_40 ] . V_38 ;
V_41 . V_36 = V_30 [ V_40 ] . V_38 ;
V_25 = F_22 ( V_28 , V_3 ) ;
if ( V_25 < 0 )
goto V_15;
V_10 -> V_14 = V_25 ;
V_35 . V_42 = V_25 ;
V_43 . V_44 = V_25 ;
V_25 = F_22 ( V_28 , V_3 ) ;
if ( V_25 < 0 )
goto V_15;
V_10 -> V_17 = V_25 ;
V_39 . V_42 = V_25 ;
V_41 . V_42 = V_25 ;
V_43 . V_45 = V_25 ;
V_25 = - V_46 ;
V_32 = F_23 ( V_12 -> V_22 , & V_47 ) ;
if ( ! V_32 )
goto V_15;
V_10 -> V_4 . V_18 = V_32 ;
V_32 -> V_19 = V_12 ;
V_32 = F_23 ( V_12 -> V_22 , & V_48 ) ;
if ( ! V_32 )
goto V_15;
V_10 -> V_4 . V_21 = V_32 ;
V_32 -> V_19 = V_12 ;
V_49 . V_50 =
V_47 . V_50 ;
V_51 . V_50 =
V_48 . V_50 ;
V_25 = F_24 ( V_3 , V_52 , V_53 , NULL ) ;
if ( V_25 )
goto V_15;
V_25 = F_14 ( V_3 ) ;
if ( V_25 < 0 )
F_25 ( V_12 , L_8 ,
V_10 -> V_16 , V_25 ) ;
else
V_10 -> V_26 = true ;
F_5 ( V_12 , L_9 ,
V_10 -> V_16 ,
F_26 ( V_28 -> V_12 -> V_22 ) ? L_10 : L_11 ,
V_10 -> V_4 . V_18 -> V_54 , V_10 -> V_4 . V_21 -> V_54 ) ;
return 0 ;
V_15:
F_27 ( V_3 ) ;
if ( V_10 -> V_4 . V_21 )
V_10 -> V_4 . V_21 -> V_19 = NULL ;
if ( V_10 -> V_4 . V_18 )
V_10 -> V_4 . V_18 -> V_19 = NULL ;
ERROR ( V_12 , L_12 , V_3 -> V_54 , V_3 , V_25 ) ;
return V_25 ;
}
static inline struct V_55 * F_28 ( struct V_56 * V_57 )
{
return F_2 ( F_29 ( V_57 ) , struct V_55 ,
V_58 . V_59 ) ;
}
static T_1 F_30 ( struct V_56 * V_57 ,
struct V_60 * V_61 ,
char * V_62 )
{
struct V_55 * V_63 = F_28 ( V_57 ) ;
struct V_64 * V_65 =
F_2 ( V_61 , struct V_64 , V_61 ) ;
T_1 V_66 = 0 ;
if ( V_65 -> V_67 )
V_66 = V_65 -> V_67 ( V_63 , V_62 ) ;
return V_66 ;
}
static void F_31 ( struct V_56 * V_57 )
{
struct V_55 * V_63 = F_28 ( V_57 ) ;
F_32 ( & V_63 -> V_58 ) ;
}
static T_1 F_33 ( struct V_55 * V_63 , char * V_62 )
{
return sprintf ( V_62 , L_13 , V_63 -> V_16 ) ;
}
static void F_34 ( struct V_68 * V_3 )
{
struct V_55 * V_63 ;
V_63 = F_2 ( V_3 , struct V_55 , V_58 ) ;
F_35 ( V_63 -> V_16 ) ;
F_36 ( V_63 ) ;
}
static struct V_68 * F_37 ( void )
{
struct V_55 * V_63 ;
int V_66 ;
V_63 = F_38 ( sizeof( * V_63 ) , V_69 ) ;
if ( ! V_63 )
return F_39 ( - V_70 ) ;
V_63 -> V_58 . V_71 = F_34 ;
V_66 = F_40 ( & V_63 -> V_16 ) ;
if ( V_66 ) {
F_36 ( V_63 ) ;
return F_39 ( V_66 ) ;
}
F_41 ( & V_63 -> V_58 . V_59 , L_14 ,
& V_72 ) ;
return & V_63 -> V_58 ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_10 ;
V_10 = F_1 ( V_3 ) ;
F_36 ( V_10 ) ;
}
static void F_43 ( struct V_27 * V_28 , struct V_2 * V_3 )
{
F_27 ( V_3 ) ;
}
struct V_2 * F_44 ( struct V_68 * V_73 )
{
struct V_1 * V_10 ;
struct V_55 * V_63 ;
V_10 = F_38 ( sizeof( * V_10 ) , V_69 ) ;
if ( ! V_10 )
return F_39 ( - V_70 ) ;
V_63 = F_2 ( V_73 , struct V_55 , V_58 ) ;
V_10 -> V_16 = V_63 -> V_16 ;
V_10 -> V_4 . V_74 = F_11 ;
V_10 -> V_4 . V_75 = F_13 ;
V_10 -> V_4 . V_5 . V_54 = L_15 ;
V_10 -> V_4 . V_5 . V_76 = F_17 ;
V_10 -> V_4 . V_5 . V_77 = F_43 ;
V_10 -> V_4 . V_5 . V_78 = F_4 ;
V_10 -> V_4 . V_5 . V_79 = F_9 ;
V_10 -> V_4 . V_5 . V_80 = F_10 ;
V_10 -> V_4 . V_5 . V_81 = F_42 ;
return & V_10 -> V_4 . V_5 ;
}
