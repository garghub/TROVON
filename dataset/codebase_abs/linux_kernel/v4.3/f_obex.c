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
V_27 = F_14 ( & V_26 -> V_5 ) ;
if ( V_27 )
F_5 ( & V_12 -> V_16 -> V_17 ,
L_7 ,
V_10 -> V_18 , V_27 ) ;
}
static inline bool F_15 ( struct V_28 * V_29 )
{
if ( ! F_16 ( V_29 -> V_12 -> V_16 ) )
return false ;
return true ;
}
static int F_17 ( struct V_28 * V_29 , struct V_2 * V_3 )
{
struct V_11 * V_12 = V_29 -> V_12 ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_30 * V_31 ;
int V_27 ;
struct V_32 * V_33 ;
if ( ! F_15 ( V_29 ) )
return - V_25 ;
V_31 = F_18 ( V_12 , V_34 ,
F_19 ( V_35 ) ) ;
if ( F_20 ( V_31 ) )
return F_21 ( V_31 ) ;
V_36 . V_37 = V_31 [ V_38 ] . V_39 ;
V_40 . V_37 = V_31 [ V_41 ] . V_39 ;
V_42 . V_37 = V_31 [ V_41 ] . V_39 ;
V_27 = F_22 ( V_29 , V_3 ) ;
if ( V_27 < 0 )
goto V_15;
V_10 -> V_14 = V_27 ;
V_36 . V_43 = V_27 ;
V_44 . V_45 = V_27 ;
V_27 = F_22 ( V_29 , V_3 ) ;
if ( V_27 < 0 )
goto V_15;
V_10 -> V_19 = V_27 ;
V_40 . V_43 = V_27 ;
V_42 . V_43 = V_27 ;
V_44 . V_46 = V_27 ;
V_27 = - V_47 ;
V_33 = F_23 ( V_12 -> V_16 , & V_48 ) ;
if ( ! V_33 )
goto V_15;
V_10 -> V_4 . V_20 = V_33 ;
V_33 -> V_21 = V_12 ;
V_33 = F_23 ( V_12 -> V_16 , & V_49 ) ;
if ( ! V_33 )
goto V_15;
V_10 -> V_4 . V_23 = V_33 ;
V_33 -> V_21 = V_12 ;
V_50 . V_51 =
V_48 . V_51 ;
V_52 . V_51 =
V_49 . V_51 ;
V_27 = F_24 ( V_3 , V_53 , V_54 , NULL ) ;
if ( V_27 )
goto V_15;
F_5 ( & V_12 -> V_16 -> V_17 , L_8 ,
V_10 -> V_18 ,
F_25 ( V_29 -> V_12 -> V_16 ) ? L_9 : L_10 ,
V_10 -> V_4 . V_20 -> V_55 , V_10 -> V_4 . V_23 -> V_55 ) ;
return 0 ;
V_15:
if ( V_10 -> V_4 . V_23 )
V_10 -> V_4 . V_23 -> V_21 = NULL ;
if ( V_10 -> V_4 . V_20 )
V_10 -> V_4 . V_20 -> V_21 = NULL ;
ERROR ( V_12 , L_11 , V_3 -> V_55 , V_3 , V_27 ) ;
return V_27 ;
}
static inline struct V_56 * F_26 ( struct V_57 * V_58 )
{
return F_2 ( F_27 ( V_58 ) , struct V_56 ,
V_59 . V_60 ) ;
}
static T_1 F_28 ( struct V_57 * V_58 ,
struct V_61 * V_62 ,
char * V_63 )
{
struct V_56 * V_64 = F_26 ( V_58 ) ;
struct V_65 * V_66 =
F_2 ( V_62 , struct V_65 , V_62 ) ;
T_1 V_67 = 0 ;
if ( V_66 -> V_68 )
V_67 = V_66 -> V_68 ( V_64 , V_63 ) ;
return V_67 ;
}
static void F_29 ( struct V_57 * V_58 )
{
struct V_56 * V_64 = F_26 ( V_58 ) ;
F_30 ( & V_64 -> V_59 ) ;
}
static T_1 F_31 ( struct V_56 * V_64 , char * V_63 )
{
return sprintf ( V_63 , L_12 , V_64 -> V_18 ) ;
}
static void F_32 ( struct V_69 * V_3 )
{
struct V_56 * V_64 ;
V_64 = F_2 ( V_3 , struct V_56 , V_59 ) ;
F_33 ( V_64 -> V_18 ) ;
F_34 ( V_64 ) ;
}
static struct V_69 * F_35 ( void )
{
struct V_56 * V_64 ;
int V_67 ;
V_64 = F_36 ( sizeof( * V_64 ) , V_70 ) ;
if ( ! V_64 )
return F_37 ( - V_71 ) ;
V_64 -> V_59 . V_72 = F_32 ;
V_67 = F_38 ( & V_64 -> V_18 ) ;
if ( V_67 ) {
F_34 ( V_64 ) ;
return F_37 ( V_67 ) ;
}
F_39 ( & V_64 -> V_59 . V_60 , L_13 ,
& V_73 ) ;
return & V_64 -> V_59 ;
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_10 ;
V_10 = F_1 ( V_3 ) ;
F_34 ( V_10 ) ;
}
static void F_41 ( struct V_28 * V_29 , struct V_2 * V_3 )
{
F_42 ( V_3 ) ;
}
static struct V_2 * F_43 ( struct V_69 * V_74 )
{
struct V_1 * V_10 ;
struct V_56 * V_64 ;
V_10 = F_36 ( sizeof( * V_10 ) , V_70 ) ;
if ( ! V_10 )
return F_37 ( - V_71 ) ;
V_64 = F_2 ( V_74 , struct V_56 , V_59 ) ;
V_10 -> V_18 = V_64 -> V_18 ;
V_10 -> V_4 . V_75 = F_11 ;
V_10 -> V_4 . V_76 = F_13 ;
V_10 -> V_4 . V_5 . V_55 = L_14 ;
V_10 -> V_4 . V_5 . V_77 = F_17 ;
V_10 -> V_4 . V_5 . V_78 = F_41 ;
V_10 -> V_4 . V_5 . V_79 = F_4 ;
V_10 -> V_4 . V_5 . V_80 = F_9 ;
V_10 -> V_4 . V_5 . V_81 = F_10 ;
V_10 -> V_4 . V_5 . V_82 = F_40 ;
V_10 -> V_4 . V_5 . V_83 = true ;
return & V_10 -> V_4 . V_5 ;
}
