static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
F_5 ( V_5 ) ;
F_6 ( V_5 -> V_8 ) ;
F_7 ( V_5 ) ;
return 0 ;
}
static void F_8 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_1 * V_9 = F_1 ( F_9 ( V_5 ) ) ;
F_10 ( & V_9 -> V_10 ) ;
F_11 ( & V_7 -> V_11 ) ;
F_12 ( & V_9 -> V_10 ) ;
F_13 ( V_5 ) ;
}
static int F_14 ( struct V_12 * V_13 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_14 * V_15 = V_7 -> V_15 ;
unsigned int V_16 = V_13 -> V_16 ;
int V_17 = F_15 ( V_15 , V_13 , V_15 -> V_18 ) ;
if ( F_16 ( V_17 == V_19 ) ) {
F_17 ( V_16 , & V_7 -> V_20 ) ;
F_18 ( & V_7 -> V_21 ) ;
} else {
F_18 ( & V_7 -> V_22 ) ;
}
return V_23 ;
}
static void F_19 ( struct V_4 * V_5 ,
struct V_24 * V_25 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
V_25 -> V_20 = F_20 ( & V_7 -> V_20 ) ;
V_25 -> V_21 = F_20 ( & V_7 -> V_21 ) ;
V_25 -> V_22 = F_20 ( & V_7 -> V_22 ) ;
V_25 -> V_26 = F_20 ( & V_7 -> V_26 ) ;
V_25 -> V_27 = F_20 ( & V_7 -> V_27 ) ;
V_25 -> V_28 = F_20 ( & V_7 -> V_28 ) ;
}
static void F_21 ( struct V_4 * V_5 )
{
F_22 ( V_5 ) ;
V_5 -> V_29 &= ~ V_30 ;
V_5 -> V_31 |= V_32 ;
V_5 -> V_33 = & V_34 ;
V_5 -> V_35 = V_36 ;
}
static void F_23 ( struct V_14 * V_15 , struct V_12 * V_13 , int V_37 )
{
struct V_38 * V_39 = F_24 ( V_15 ) ;
struct V_4 * V_5 = V_39 -> V_5 ;
struct V_6 * V_7 = F_4 ( V_5 ) ;
if ( V_15 -> V_40 & V_41 ) {
unsigned int V_42 ;
V_42 = F_25 ( 32u , V_13 -> V_16 ) ;
if ( ! F_26 ( V_13 , V_42 ) )
goto error;
F_27 ( L_1 , V_15 -> V_43 ) ;
F_28 ( L_2 , V_44 , V_13 -> V_45 , V_42 ) ;
}
if ( ! F_26 ( V_13 , V_46 ) )
goto error;
F_29 ( V_13 ) ;
V_13 -> V_47 = V_48 ;
F_30 ( V_13 ) ;
F_31 ( V_13 ) ;
if ( F_32 ( V_5 , V_13 ) == V_49 ) {
F_18 ( & V_7 -> V_27 ) ;
F_17 ( V_37 , & V_7 -> V_26 ) ;
} else {
F_18 ( & V_7 -> V_28 ) ;
}
return;
error:
F_18 ( & V_7 -> V_28 ) ;
F_33 ( V_13 ) ;
}
static void F_34 ( struct V_14 * V_15 )
{
struct V_38 * V_39 ;
struct V_4 * V_5 ;
if ( V_15 ) {
V_39 = F_24 ( V_15 ) ;
V_5 = V_39 -> V_5 ;
if ( V_5 ) {
F_35 ( V_5 ) ;
V_39 -> V_5 = NULL ;
F_36 ( V_50 ) ;
}
}
}
static void F_37 ( struct V_51 * V_52 , void * V_53 )
{
struct V_14 * V_15 = V_53 ;
struct V_38 * V_39 = F_24 ( V_15 ) ;
struct V_4 * V_5 = V_39 -> V_5 ;
F_38 ( V_52 , L_3 , V_5 -> V_43 ) ;
}
static int F_39 ( struct V_2 * V_2 , T_1 V_54 , T_1 V_55 , T_1 V_56 , struct V_57 * V_58 )
{
struct V_4 * V_5 ;
char V_43 [ V_59 ] ;
struct V_60 * V_61 ;
struct V_14 * V_15 ;
struct V_6 * V_7 ;
struct V_38 * V_39 ;
int V_62 ;
struct V_1 * V_9 ;
V_61 = F_40 ( V_2 , V_54 ) ;
if ( ! V_61 ) {
V_62 = - V_63 ;
goto V_64;
}
if ( V_58 -> V_65 ) {
V_5 = F_41 ( V_2 , V_58 -> V_65 ) ;
if ( V_5 ) {
F_13 ( V_5 ) ;
V_62 = - V_66 ;
goto V_64;
}
F_42 ( V_43 , V_58 -> V_65 , V_59 ) ;
} else
strcpy ( V_43 , V_67 ) ;
V_15 = F_43 ( sizeof( * V_39 ) , V_61 , V_55 ,
V_56 , V_58 ) ;
if ( F_44 ( V_15 ) ) {
V_62 = F_45 ( V_15 ) ;
goto V_64;
}
V_5 = F_46 ( sizeof( * V_7 ) , V_43 , V_68 ,
F_21 ) ;
if ( ! V_5 ) {
V_62 = - V_69 ;
goto V_70;
}
F_47 ( V_5 , V_2 ) ;
if ( V_15 -> V_71 == 0 )
V_15 -> V_71 = V_5 -> V_71 - V_15 -> V_18 ;
V_5 -> V_71 = V_15 -> V_71 ;
V_5 -> V_72 += V_15 -> V_18 ;
V_5 -> V_73 = 0 ;
V_5 -> V_74 = V_75 ;
V_7 = F_4 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_15 = V_15 ;
F_48 ( & V_7 -> V_11 ) ;
V_7 -> V_76 = V_61 -> V_77 ;
V_15 -> V_78 = F_23 ;
V_15 -> V_79 = F_34 ;
#if F_49 ( V_80 )
V_15 -> V_81 = F_37 ;
#endif
V_39 = F_24 ( V_15 ) ;
V_39 -> V_5 = V_5 ;
V_62 = F_50 ( V_5 ) ;
if ( V_62 < 0 )
goto V_82;
F_51 ( V_50 ) ;
F_42 ( V_15 -> V_65 , V_5 -> V_43 , V_59 ) ;
F_52 ( V_5 ) ;
V_9 = F_1 ( F_9 ( V_5 ) ) ;
F_10 ( & V_9 -> V_10 ) ;
F_53 ( & V_7 -> V_11 , & V_9 -> V_83 ) ;
F_12 ( & V_9 -> V_10 ) ;
return 0 ;
V_82:
V_36 ( V_5 ) ;
V_39 -> V_5 = NULL ;
V_70:
F_54 ( V_15 ) ;
V_64:
return V_62 ;
}
static T_2 int F_55 ( struct V_2 * V_2 )
{
struct V_1 * V_9 = F_2 ( V_2 , V_3 ) ;
F_48 ( & V_9 -> V_83 ) ;
F_56 ( & V_9 -> V_10 ) ;
return 0 ;
}
static int T_3 F_57 ( void )
{
int V_84 = 0 ;
V_84 = F_58 ( V_85 , & V_86 ) ;
if ( V_84 )
goto V_64;
V_84 = F_59 ( & V_87 ) ;
if ( V_84 )
goto V_88;
F_60 ( L_4 ) ;
return 0 ;
V_88:
F_61 ( V_85 ) ;
V_64:
return V_84 ;
}
static void T_4 F_62 ( void )
{
F_63 ( & V_87 ) ;
F_61 ( V_85 ) ;
}
