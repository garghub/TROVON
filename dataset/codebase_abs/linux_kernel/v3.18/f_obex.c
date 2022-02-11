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
F_5 ( & V_12 -> V_16 -> V_17 ,
L_1 , V_10 -> V_18 ) ;
} else if ( V_8 == V_10 -> V_19 ) {
if ( V_9 > 1 )
goto V_15;
if ( V_10 -> V_4 . V_20 -> V_21 ) {
F_5 ( & V_12 -> V_16 -> V_17 ,
L_2 , V_10 -> V_18 ) ;
F_6 ( & V_10 -> V_4 ) ;
}
if ( ! V_10 -> V_4 . V_20 -> V_22 || ! V_10 -> V_4 . V_23 -> V_22 ) {
F_5 ( & V_12 -> V_16 -> V_17 ,
L_3 , V_10 -> V_18 ) ;
if ( F_7 ( V_12 -> V_16 , V_3 ,
V_10 -> V_4 . V_20 ) ||
F_7 ( V_12 -> V_16 , V_3 ,
V_10 -> V_4 . V_23 ) ) {
V_10 -> V_4 . V_23 -> V_22 = NULL ;
V_10 -> V_4 . V_20 -> V_22 = NULL ;
goto V_15;
}
}
if ( V_9 == 1 ) {
F_5 ( & V_12 -> V_16 -> V_17 ,
L_4 , V_10 -> V_18 ) ;
F_8 ( & V_10 -> V_4 , V_10 -> V_18 ) ;
}
} else
goto V_15;
V_10 -> V_24 = V_9 ;
return 0 ;
V_15:
return - V_25 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_8 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
return V_10 -> V_24 ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_11 * V_12 = V_3 -> V_13 -> V_12 ;
F_5 ( & V_12 -> V_16 -> V_17 , L_5 , V_10 -> V_18 ) ;
F_6 ( & V_10 -> V_4 ) ;
}
static void F_11 ( struct V_6 * V_26 )
{
struct V_1 * V_10 = F_3 ( V_26 ) ;
struct V_11 * V_12 = V_26 -> V_5 . V_13 -> V_12 ;
int V_27 ;
if ( ! V_10 -> V_28 )
return;
V_27 = F_12 ( & V_26 -> V_5 ) ;
if ( V_27 )
F_5 ( & V_12 -> V_16 -> V_17 ,
L_6 ,
V_10 -> V_18 , V_27 ) ;
}
static void F_13 ( struct V_6 * V_26 )
{
struct V_1 * V_10 = F_3 ( V_26 ) ;
struct V_11 * V_12 = V_26 -> V_5 . V_13 -> V_12 ;
int V_27 ;
if ( ! V_10 -> V_28 )
return;
V_27 = F_14 ( & V_26 -> V_5 ) ;
if ( V_27 )
F_5 ( & V_12 -> V_16 -> V_17 ,
L_7 ,
V_10 -> V_18 , V_27 ) ;
}
static inline bool F_15 ( struct V_29 * V_30 )
{
if ( ! F_16 ( V_30 -> V_12 -> V_16 ) )
return false ;
return true ;
}
static int F_17 ( struct V_29 * V_30 , struct V_2 * V_3 )
{
struct V_11 * V_12 = V_30 -> V_12 ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_31 * V_32 ;
int V_27 ;
struct V_33 * V_34 ;
if ( ! F_15 ( V_30 ) )
return - V_25 ;
V_32 = F_18 ( V_12 , V_35 ,
F_19 ( V_36 ) ) ;
if ( F_20 ( V_32 ) )
return F_21 ( V_32 ) ;
V_37 . V_38 = V_32 [ V_39 ] . V_40 ;
V_41 . V_38 = V_32 [ V_42 ] . V_40 ;
V_43 . V_38 = V_32 [ V_42 ] . V_40 ;
V_27 = F_22 ( V_30 , V_3 ) ;
if ( V_27 < 0 )
goto V_15;
V_10 -> V_14 = V_27 ;
V_37 . V_44 = V_27 ;
V_45 . V_46 = V_27 ;
V_27 = F_22 ( V_30 , V_3 ) ;
if ( V_27 < 0 )
goto V_15;
V_10 -> V_19 = V_27 ;
V_41 . V_44 = V_27 ;
V_43 . V_44 = V_27 ;
V_45 . V_47 = V_27 ;
V_27 = - V_48 ;
V_34 = F_23 ( V_12 -> V_16 , & V_49 ) ;
if ( ! V_34 )
goto V_15;
V_10 -> V_4 . V_20 = V_34 ;
V_34 -> V_21 = V_12 ;
V_34 = F_23 ( V_12 -> V_16 , & V_50 ) ;
if ( ! V_34 )
goto V_15;
V_10 -> V_4 . V_23 = V_34 ;
V_34 -> V_21 = V_12 ;
V_51 . V_52 =
V_49 . V_52 ;
V_53 . V_52 =
V_50 . V_52 ;
V_27 = F_24 ( V_3 , V_54 , V_55 , NULL ) ;
if ( V_27 )
goto V_15;
V_27 = F_14 ( V_3 ) ;
if ( V_27 < 0 )
F_25 ( V_12 , L_8 ,
V_10 -> V_18 , V_27 ) ;
else
V_10 -> V_28 = true ;
F_5 ( & V_12 -> V_16 -> V_17 , L_9 ,
V_10 -> V_18 ,
F_26 ( V_30 -> V_12 -> V_16 ) ? L_10 : L_11 ,
V_10 -> V_4 . V_20 -> V_56 , V_10 -> V_4 . V_23 -> V_56 ) ;
return 0 ;
V_15:
if ( V_10 -> V_4 . V_23 )
V_10 -> V_4 . V_23 -> V_21 = NULL ;
if ( V_10 -> V_4 . V_20 )
V_10 -> V_4 . V_20 -> V_21 = NULL ;
ERROR ( V_12 , L_12 , V_3 -> V_56 , V_3 , V_27 ) ;
return V_27 ;
}
static inline struct V_57 * F_27 ( struct V_58 * V_59 )
{
return F_2 ( F_28 ( V_59 ) , struct V_57 ,
V_60 . V_61 ) ;
}
static T_1 F_29 ( struct V_58 * V_59 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_57 * V_65 = F_27 ( V_59 ) ;
struct V_66 * V_67 =
F_2 ( V_63 , struct V_66 , V_63 ) ;
T_1 V_68 = 0 ;
if ( V_67 -> V_69 )
V_68 = V_67 -> V_69 ( V_65 , V_64 ) ;
return V_68 ;
}
static void F_30 ( struct V_58 * V_59 )
{
struct V_57 * V_65 = F_27 ( V_59 ) ;
F_31 ( & V_65 -> V_60 ) ;
}
static T_1 F_32 ( struct V_57 * V_65 , char * V_64 )
{
return sprintf ( V_64 , L_13 , V_65 -> V_18 ) ;
}
static void F_33 ( struct V_70 * V_3 )
{
struct V_57 * V_65 ;
V_65 = F_2 ( V_3 , struct V_57 , V_60 ) ;
F_34 ( V_65 -> V_18 ) ;
F_35 ( V_65 ) ;
}
static struct V_70 * F_36 ( void )
{
struct V_57 * V_65 ;
int V_68 ;
V_65 = F_37 ( sizeof( * V_65 ) , V_71 ) ;
if ( ! V_65 )
return F_38 ( - V_72 ) ;
V_65 -> V_60 . V_73 = F_33 ;
V_68 = F_39 ( & V_65 -> V_18 ) ;
if ( V_68 ) {
F_35 ( V_65 ) ;
return F_38 ( V_68 ) ;
}
F_40 ( & V_65 -> V_60 . V_61 , L_14 ,
& V_74 ) ;
return & V_65 -> V_60 ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_10 ;
V_10 = F_1 ( V_3 ) ;
F_35 ( V_10 ) ;
}
static void F_42 ( struct V_29 * V_30 , struct V_2 * V_3 )
{
F_43 ( V_3 ) ;
}
static struct V_2 * F_44 ( struct V_70 * V_75 )
{
struct V_1 * V_10 ;
struct V_57 * V_65 ;
V_10 = F_37 ( sizeof( * V_10 ) , V_71 ) ;
if ( ! V_10 )
return F_38 ( - V_72 ) ;
V_65 = F_2 ( V_75 , struct V_57 , V_60 ) ;
V_10 -> V_18 = V_65 -> V_18 ;
V_10 -> V_4 . V_76 = F_11 ;
V_10 -> V_4 . V_77 = F_13 ;
V_10 -> V_4 . V_5 . V_56 = L_15 ;
V_10 -> V_4 . V_5 . V_78 = F_17 ;
V_10 -> V_4 . V_5 . V_79 = F_42 ;
V_10 -> V_4 . V_5 . V_80 = F_4 ;
V_10 -> V_4 . V_5 . V_81 = F_9 ;
V_10 -> V_4 . V_5 . V_82 = F_10 ;
V_10 -> V_4 . V_5 . V_83 = F_41 ;
return & V_10 -> V_4 . V_5 ;
}
