static inline T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline T_2 F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_4 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , unsigned int V_3 , T_1 V_5 )
{
F_6 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , unsigned int V_3 , T_2 V_5 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_6 , V_7 ) ;
F_7 ( V_2 , V_8 , V_9 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_6 , 0 ) ;
F_7 ( V_2 , V_8 , 0 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
}
static void F_12 ( struct V_1 * V_2 )
{
}
static void F_13 ( struct V_1 * V_2 )
{
int V_10 ;
T_1 V_11 ;
for ( V_10 = 0 ; V_10 < 50 ; V_10 ++ ) {
V_11 = F_1 ( V_2 , V_12 ) ;
if ( ! ( V_11 & V_13 ) )
break;
F_14 ( 1 ) ;
}
}
static T_3 F_15 ( int V_14 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
unsigned long V_16 = 0 ;
T_1 V_17 ;
V_17 = F_1 ( V_2 , V_12 ) ;
if ( V_17 & V_18 ) {
V_2 -> type -> V_19 ( V_2 ) ;
F_5 ( V_2 , V_12 , V_18 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
V_16 |= V_21 | V_22 ;
}
if ( V_17 & V_23 )
V_16 |= V_21 | V_24 ;
F_16 ( V_2 -> V_2 , 1 , V_16 ) ;
return V_25 ;
}
static int F_17 ( struct V_26 * V_27 , unsigned int V_28 )
{
struct V_1 * V_2 = F_18 ( V_27 ) ;
T_1 V_3 , V_29 = 0 ;
F_19 () ;
F_13 ( V_2 ) ;
V_3 = F_1 ( V_2 , V_30 ) ;
if ( V_2 -> type -> V_31 )
V_29 = F_1 ( V_2 , V_32 ) ;
if ( V_28 ) {
V_3 |= V_33 ;
V_29 |= V_34 ;
} else {
V_3 &= ~ V_33 ;
V_29 &= ~ V_34 ;
}
F_13 ( V_2 ) ;
V_2 -> type -> V_19 ( V_2 ) ;
F_5 ( V_2 , V_30 , V_3 ) ;
if ( V_2 -> type -> V_31 )
F_5 ( V_2 , V_32 , V_29 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
F_20 () ;
return 0 ;
}
static int F_21 ( struct V_35 * V_36 )
{
if ( F_22 ( V_36 ) != 0 )
return - V_37 ;
V_36 -> V_38 = F_23 ( V_36 -> V_38 ) ;
V_36 -> V_39 = F_23 ( V_36 -> V_39 ) ;
V_36 -> V_40 = F_23 ( V_36 -> V_40 ) ;
V_36 -> V_41 = F_23 ( V_36 -> V_41 ) ;
V_36 -> V_42 = F_23 ( V_36 -> V_42 + 1 ) ;
if ( V_36 -> V_43 < 100 || V_36 -> V_43 > 199 )
return - V_37 ;
V_36 -> V_43 = F_23 ( V_36 -> V_43 - 100 ) ;
return 0 ;
}
static void F_24 ( struct V_35 * V_36 )
{
V_36 -> V_38 = F_25 ( V_36 -> V_38 ) ;
V_36 -> V_39 = F_25 ( V_36 -> V_39 ) ;
V_36 -> V_40 = F_25 ( V_36 -> V_40 ) ;
V_36 -> V_41 = F_25 ( V_36 -> V_41 ) ;
V_36 -> V_42 = F_25 ( V_36 -> V_42 ) - 1 ;
V_36 -> V_43 = F_25 ( V_36 -> V_43 ) + 100 ;
}
static void F_26 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
V_36 -> V_38 = F_1 ( V_2 , V_44 ) ;
V_36 -> V_39 = F_1 ( V_2 , V_45 ) ;
V_36 -> V_40 = F_1 ( V_2 , V_46 ) ;
V_36 -> V_41 = F_1 ( V_2 , V_47 ) ;
V_36 -> V_42 = F_1 ( V_2 , V_48 ) ;
V_36 -> V_43 = F_1 ( V_2 , V_49 ) ;
}
static int F_27 ( struct V_26 * V_27 , struct V_35 * V_36 )
{
struct V_1 * V_2 = F_18 ( V_27 ) ;
F_19 () ;
F_13 ( V_2 ) ;
F_26 ( V_2 , V_36 ) ;
F_20 () ;
F_24 ( V_36 ) ;
return 0 ;
}
static int F_28 ( struct V_26 * V_27 , struct V_35 * V_36 )
{
struct V_1 * V_2 = F_18 ( V_27 ) ;
if ( F_21 ( V_36 ) < 0 )
return - V_37 ;
F_19 () ;
F_13 ( V_2 ) ;
V_2 -> type -> V_19 ( V_2 ) ;
F_5 ( V_2 , V_49 , V_36 -> V_43 ) ;
F_5 ( V_2 , V_48 , V_36 -> V_42 ) ;
F_5 ( V_2 , V_47 , V_36 -> V_41 ) ;
F_5 ( V_2 , V_46 , V_36 -> V_40 ) ;
F_5 ( V_2 , V_45 , V_36 -> V_39 ) ;
F_5 ( V_2 , V_44 , V_36 -> V_38 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
F_20 () ;
return 0 ;
}
static int F_29 ( struct V_26 * V_27 , struct V_50 * V_51 )
{
struct V_1 * V_2 = F_18 ( V_27 ) ;
T_1 V_52 ;
F_19 () ;
F_13 ( V_2 ) ;
V_51 -> time . V_38 = F_1 ( V_2 , V_53 ) ;
V_51 -> time . V_39 = F_1 ( V_2 , V_54 ) ;
V_51 -> time . V_40 = F_1 ( V_2 , V_55 ) ;
V_51 -> time . V_41 = F_1 ( V_2 , V_56 ) ;
V_51 -> time . V_42 = F_1 ( V_2 , V_57 ) ;
V_51 -> time . V_43 = F_1 ( V_2 , V_58 ) ;
F_20 () ;
F_24 ( & V_51 -> time ) ;
V_52 = F_1 ( V_2 , V_30 ) ;
V_51 -> V_28 = ! ! ( V_52 & V_33 ) ;
return 0 ;
}
static int F_30 ( struct V_26 * V_27 , struct V_50 * V_51 )
{
struct V_1 * V_2 = F_18 ( V_27 ) ;
T_1 V_3 , V_29 = 0 ;
if ( F_21 ( & V_51 -> time ) < 0 )
return - V_37 ;
F_19 () ;
F_13 ( V_2 ) ;
V_2 -> type -> V_19 ( V_2 ) ;
F_5 ( V_2 , V_58 , V_51 -> time . V_43 ) ;
F_5 ( V_2 , V_57 , V_51 -> time . V_42 ) ;
F_5 ( V_2 , V_56 , V_51 -> time . V_41 ) ;
F_5 ( V_2 , V_55 , V_51 -> time . V_40 ) ;
F_5 ( V_2 , V_54 , V_51 -> time . V_39 ) ;
F_5 ( V_2 , V_53 , V_51 -> time . V_38 ) ;
V_3 = F_1 ( V_2 , V_30 ) ;
if ( V_2 -> type -> V_31 )
V_29 = F_1 ( V_2 , V_32 ) ;
if ( V_51 -> V_28 ) {
V_3 |= V_33 ;
V_29 |= V_34 ;
} else {
V_3 &= ~ V_33 ;
V_29 &= ~ V_34 ;
}
F_5 ( V_2 , V_30 , V_3 ) ;
if ( V_2 -> type -> V_31 )
F_5 ( V_2 , V_32 , V_29 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
F_20 () ;
return 0 ;
}
static void F_31 ( void )
{
struct V_1 * V_2 = V_59 ;
struct V_35 V_36 ;
unsigned long V_60 ;
T_2 V_5 ;
V_2 -> type -> V_19 ( V_2 ) ;
V_5 = F_3 ( V_2 , V_61 ) ;
F_7 ( V_2 , V_61 , V_5 | V_62 ) ;
F_26 ( V_2 , & V_36 ) ;
F_24 ( & V_36 ) ;
F_32 ( & V_36 , & V_60 ) ;
F_33 ( V_60 + 2 , & V_36 ) ;
if ( F_21 ( & V_36 ) < 0 ) {
F_34 ( & V_2 -> V_2 -> V_27 , L_1 ) ;
return;
}
F_13 ( V_2 ) ;
F_5 ( V_2 , V_63 , V_36 . V_38 ) ;
F_5 ( V_2 , V_64 , V_36 . V_39 ) ;
F_5 ( V_2 , V_65 , V_36 . V_40 ) ;
F_5 ( V_2 , V_66 , V_36 . V_41 ) ;
F_5 ( V_2 , V_67 , V_36 . V_42 ) ;
F_5 ( V_2 , V_68 , V_36 . V_43 ) ;
V_5 = F_1 ( V_2 , V_30 ) ;
F_7 ( V_2 , V_30 ,
V_5 | V_69 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
F_35 ( 2500 ) ;
}
static int F_36 ( struct V_70 * V_71 )
{
struct V_1 * V_2 ;
struct V_72 * V_73 ;
T_1 V_3 , V_74 , V_75 ;
const struct V_76 * V_77 ;
const struct V_78 * V_79 ;
int V_80 ;
V_2 = F_37 ( & V_71 -> V_27 , sizeof( * V_2 ) , V_81 ) ;
if ( ! V_2 )
return - V_82 ;
V_79 = F_38 ( V_83 , & V_71 -> V_27 ) ;
if ( V_79 ) {
V_2 -> type = V_79 -> V_84 ;
V_2 -> V_85 = V_2 -> type -> V_86 &&
F_39 ( V_71 -> V_27 . V_87 ,
L_2 ) ;
} else {
V_77 = F_40 ( V_71 ) ;
V_2 -> type = ( void * ) V_77 -> V_88 ;
}
V_2 -> V_89 = F_41 ( V_71 , 0 ) ;
if ( V_2 -> V_89 <= 0 )
return - V_90 ;
V_2 -> V_91 = F_41 ( V_71 , 1 ) ;
if ( V_2 -> V_91 <= 0 )
return - V_90 ;
V_73 = F_42 ( V_71 , V_92 , 0 ) ;
V_2 -> V_4 = F_43 ( & V_71 -> V_27 , V_73 ) ;
if ( F_44 ( V_2 -> V_4 ) )
return F_45 ( V_2 -> V_4 ) ;
F_46 ( V_71 , V_2 ) ;
F_47 ( & V_71 -> V_27 ) ;
F_48 ( & V_71 -> V_27 ) ;
V_2 -> type -> V_19 ( V_2 ) ;
F_7 ( V_2 , V_30 , 0 ) ;
if ( V_2 -> type -> V_93 ) {
V_3 = F_1 ( V_2 , V_94 ) ;
F_7 ( V_2 , V_94 ,
V_3 | V_95 ) ;
}
V_3 = F_1 ( V_2 , V_12 ) ;
V_74 = V_18 ;
if ( V_2 -> type -> V_86 )
V_74 |= V_96 ;
if ( V_2 -> type -> V_97 ) {
V_74 |= V_98 ;
if ( V_3 & V_98 )
F_49 ( & V_71 -> V_27 , L_3 ) ;
}
if ( V_3 & V_74 )
F_5 ( V_2 , V_12 , V_3 & V_74 ) ;
V_3 = F_1 ( V_2 , V_99 ) ;
if ( V_3 & V_100 )
F_49 ( & V_71 -> V_27 , L_4 ) ;
V_75 = V_3 & ( V_101 | V_102 ) ;
V_75 |= V_100 ;
if ( V_75 & V_101 )
F_49 ( & V_71 -> V_27 , L_5 ) ;
if ( V_3 != V_75 )
F_5 ( V_2 , V_99 , V_75 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
F_50 ( & V_71 -> V_27 , true ) ;
V_2 -> V_2 = F_51 ( & V_71 -> V_27 , V_71 -> V_103 ,
& V_104 , V_105 ) ;
if ( F_44 ( V_2 -> V_2 ) ) {
V_80 = F_45 ( V_2 -> V_2 ) ;
goto V_106;
}
V_80 = F_52 ( & V_71 -> V_27 , V_2 -> V_89 , F_15 , 0 ,
F_53 ( & V_2 -> V_2 -> V_27 ) , V_2 ) ;
if ( V_80 )
goto V_106;
if ( V_2 -> V_89 != V_2 -> V_91 ) {
V_80 = F_52 ( & V_71 -> V_27 , V_2 -> V_91 , F_15 , 0 ,
F_53 ( & V_2 -> V_2 -> V_27 ) , V_2 ) ;
if ( V_80 )
goto V_106;
}
if ( V_2 -> V_85 ) {
if ( ! V_107 ) {
V_59 = V_2 ;
V_107 = F_31 ;
}
}
return 0 ;
V_106:
F_50 ( & V_71 -> V_27 , false ) ;
V_2 -> type -> V_20 ( V_2 ) ;
F_54 ( & V_71 -> V_27 ) ;
F_55 ( & V_71 -> V_27 ) ;
return V_80 ;
}
static int T_4 F_56 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = F_57 ( V_71 ) ;
if ( V_107 == F_31 &&
V_59 == V_2 ) {
V_107 = NULL ;
V_59 = NULL ;
}
F_50 ( & V_71 -> V_27 , 0 ) ;
V_2 -> type -> V_19 ( V_2 ) ;
F_5 ( V_2 , V_30 , 0 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
F_54 ( & V_71 -> V_27 ) ;
F_55 ( & V_71 -> V_27 ) ;
return 0 ;
}
static int F_58 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_18 ( V_27 ) ;
V_2 -> V_108 = F_1 ( V_2 , V_30 ) ;
V_2 -> type -> V_19 ( V_2 ) ;
if ( F_59 ( V_27 ) )
F_60 ( V_2 -> V_91 ) ;
else
F_5 ( V_2 , V_30 , 0 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
F_54 ( V_27 ) ;
return 0 ;
}
static int F_61 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_18 ( V_27 ) ;
F_48 ( V_27 ) ;
V_2 -> type -> V_19 ( V_2 ) ;
if ( F_59 ( V_27 ) )
F_62 ( V_2 -> V_91 ) ;
else
F_5 ( V_2 , V_30 , V_2 -> V_108 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
return 0 ;
}
static void F_63 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = F_57 ( V_71 ) ;
T_1 V_74 ;
V_2 -> type -> V_19 ( V_2 ) ;
V_74 = F_1 ( V_2 , V_30 ) ;
V_74 &= V_33 ;
F_5 ( V_2 , V_30 , V_74 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
}
