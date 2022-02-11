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
int V_6 ;
T_1 V_7 ;
for ( V_6 = 0 ; V_6 < 50 ; V_6 ++ ) {
V_7 = F_1 ( V_2 , V_8 ) ;
if ( ! ( V_7 & V_9 ) )
break;
F_10 ( 1 ) ;
}
}
static T_3 F_11 ( int V_10 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
unsigned long V_12 = 0 ;
T_1 V_13 ;
V_13 = F_1 ( V_2 , V_8 ) ;
if ( V_13 & V_14 ) {
F_5 ( V_2 , V_8 , V_14 ) ;
V_12 |= V_15 | V_16 ;
}
if ( V_13 & V_17 )
V_12 |= V_15 | V_18 ;
F_12 ( V_2 -> V_2 , 1 , V_12 ) ;
return V_19 ;
}
static int F_13 ( struct V_20 * V_21 , unsigned int V_22 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
T_1 V_3 , V_23 = 0 ;
F_15 () ;
F_9 ( V_2 ) ;
V_3 = F_1 ( V_2 , V_24 ) ;
if ( V_2 -> type -> V_25 )
V_23 = F_1 ( V_2 , V_26 ) ;
if ( V_22 ) {
V_3 |= V_27 ;
V_23 |= V_28 ;
} else {
V_3 &= ~ V_27 ;
V_23 &= ~ V_28 ;
}
F_9 ( V_2 ) ;
F_5 ( V_2 , V_24 , V_3 ) ;
if ( V_2 -> type -> V_25 )
F_5 ( V_2 , V_26 , V_23 ) ;
F_16 () ;
return 0 ;
}
static int F_17 ( struct V_29 * V_30 )
{
if ( F_18 ( V_30 ) != 0 )
return - V_31 ;
V_30 -> V_32 = F_19 ( V_30 -> V_32 ) ;
V_30 -> V_33 = F_19 ( V_30 -> V_33 ) ;
V_30 -> V_34 = F_19 ( V_30 -> V_34 ) ;
V_30 -> V_35 = F_19 ( V_30 -> V_35 ) ;
V_30 -> V_36 = F_19 ( V_30 -> V_36 + 1 ) ;
if ( V_30 -> V_37 < 100 || V_30 -> V_37 > 199 )
return - V_31 ;
V_30 -> V_37 = F_19 ( V_30 -> V_37 - 100 ) ;
return 0 ;
}
static void F_20 ( struct V_29 * V_30 )
{
V_30 -> V_32 = F_21 ( V_30 -> V_32 ) ;
V_30 -> V_33 = F_21 ( V_30 -> V_33 ) ;
V_30 -> V_34 = F_21 ( V_30 -> V_34 ) ;
V_30 -> V_35 = F_21 ( V_30 -> V_35 ) ;
V_30 -> V_36 = F_21 ( V_30 -> V_36 ) - 1 ;
V_30 -> V_37 = F_21 ( V_30 -> V_37 ) + 100 ;
}
static void F_22 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
V_30 -> V_32 = F_1 ( V_2 , V_38 ) ;
V_30 -> V_33 = F_1 ( V_2 , V_39 ) ;
V_30 -> V_34 = F_1 ( V_2 , V_40 ) ;
V_30 -> V_35 = F_1 ( V_2 , V_41 ) ;
V_30 -> V_36 = F_1 ( V_2 , V_42 ) ;
V_30 -> V_37 = F_1 ( V_2 , V_43 ) ;
}
static int F_23 ( struct V_20 * V_21 , struct V_29 * V_30 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
F_15 () ;
F_9 ( V_2 ) ;
F_22 ( V_2 , V_30 ) ;
F_16 () ;
F_20 ( V_30 ) ;
return 0 ;
}
static int F_24 ( struct V_20 * V_21 , struct V_29 * V_30 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
if ( F_17 ( V_30 ) < 0 )
return - V_31 ;
F_15 () ;
F_9 ( V_2 ) ;
F_5 ( V_2 , V_43 , V_30 -> V_37 ) ;
F_5 ( V_2 , V_42 , V_30 -> V_36 ) ;
F_5 ( V_2 , V_41 , V_30 -> V_35 ) ;
F_5 ( V_2 , V_40 , V_30 -> V_34 ) ;
F_5 ( V_2 , V_39 , V_30 -> V_33 ) ;
F_5 ( V_2 , V_38 , V_30 -> V_32 ) ;
F_16 () ;
return 0 ;
}
static int F_25 ( struct V_20 * V_21 , struct V_44 * V_45 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
T_1 V_46 ;
F_15 () ;
F_9 ( V_2 ) ;
V_45 -> time . V_32 = F_1 ( V_2 , V_47 ) ;
V_45 -> time . V_33 = F_1 ( V_2 , V_48 ) ;
V_45 -> time . V_34 = F_1 ( V_2 , V_49 ) ;
V_45 -> time . V_35 = F_1 ( V_2 , V_50 ) ;
V_45 -> time . V_36 = F_1 ( V_2 , V_51 ) ;
V_45 -> time . V_37 = F_1 ( V_2 , V_52 ) ;
F_16 () ;
F_20 ( & V_45 -> time ) ;
V_46 = F_1 ( V_2 , V_24 ) ;
V_45 -> V_22 = ! ! ( V_46 & V_27 ) ;
return 0 ;
}
static int F_26 ( struct V_20 * V_21 , struct V_44 * V_45 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
T_1 V_3 , V_23 = 0 ;
if ( F_17 ( & V_45 -> time ) < 0 )
return - V_31 ;
F_15 () ;
F_9 ( V_2 ) ;
F_5 ( V_2 , V_52 , V_45 -> time . V_37 ) ;
F_5 ( V_2 , V_51 , V_45 -> time . V_36 ) ;
F_5 ( V_2 , V_50 , V_45 -> time . V_35 ) ;
F_5 ( V_2 , V_49 , V_45 -> time . V_34 ) ;
F_5 ( V_2 , V_48 , V_45 -> time . V_33 ) ;
F_5 ( V_2 , V_47 , V_45 -> time . V_32 ) ;
V_3 = F_1 ( V_2 , V_24 ) ;
if ( V_2 -> type -> V_25 )
V_23 = F_1 ( V_2 , V_26 ) ;
if ( V_45 -> V_22 ) {
V_3 |= V_27 ;
V_23 |= V_28 ;
} else {
V_3 &= ~ V_27 ;
V_23 &= ~ V_28 ;
}
F_5 ( V_2 , V_24 , V_3 ) ;
if ( V_2 -> type -> V_25 )
F_5 ( V_2 , V_26 , V_23 ) ;
F_16 () ;
return 0 ;
}
static void F_27 ( void )
{
struct V_1 * V_2 = V_53 ;
struct V_29 V_30 ;
unsigned long V_54 ;
T_2 V_5 ;
V_5 = F_3 ( V_2 , V_55 ) ;
F_7 ( V_2 , V_55 , V_5 | V_56 ) ;
F_22 ( V_2 , & V_30 ) ;
F_20 ( & V_30 ) ;
F_28 ( & V_30 , & V_54 ) ;
F_29 ( V_54 + 2 , & V_30 ) ;
if ( F_17 ( & V_30 ) < 0 ) {
F_30 ( & V_2 -> V_2 -> V_21 , L_1 ) ;
return;
}
F_9 ( V_2 ) ;
F_5 ( V_2 , V_57 , V_30 . V_32 ) ;
F_5 ( V_2 , V_58 , V_30 . V_33 ) ;
F_5 ( V_2 , V_59 , V_30 . V_34 ) ;
F_5 ( V_2 , V_60 , V_30 . V_35 ) ;
F_5 ( V_2 , V_61 , V_30 . V_36 ) ;
F_5 ( V_2 , V_62 , V_30 . V_37 ) ;
V_5 = F_1 ( V_2 , V_24 ) ;
F_7 ( V_2 , V_24 ,
V_5 | V_63 ) ;
F_31 ( 2500 ) ;
}
static int T_4 F_32 ( struct V_64 * V_65 )
{
struct V_1 * V_2 ;
struct V_66 * V_67 ;
T_1 V_3 , V_68 , V_69 ;
const struct V_70 * V_71 ;
const struct V_72 * V_73 ;
int V_74 ;
V_2 = F_33 ( & V_65 -> V_21 , sizeof( * V_2 ) , V_75 ) ;
if ( ! V_2 )
return - V_76 ;
V_73 = F_34 ( V_77 , & V_65 -> V_21 ) ;
if ( V_73 ) {
V_2 -> type = V_73 -> V_78 ;
V_2 -> V_79 = V_2 -> type -> V_80 &&
F_35 ( V_65 -> V_21 . V_81 ,
L_2 ) ;
} else {
V_71 = F_36 ( V_65 ) ;
V_2 -> type = ( void * ) V_71 -> V_82 ;
}
V_2 -> V_83 = F_37 ( V_65 , 0 ) ;
if ( V_2 -> V_83 <= 0 )
return - V_84 ;
V_2 -> V_85 = F_37 ( V_65 , 1 ) ;
if ( V_2 -> V_85 <= 0 )
return - V_84 ;
V_67 = F_38 ( V_65 , V_86 , 0 ) ;
V_2 -> V_4 = F_39 ( & V_65 -> V_21 , V_67 ) ;
if ( F_40 ( V_2 -> V_4 ) )
return F_41 ( V_2 -> V_4 ) ;
F_42 ( V_65 , V_2 ) ;
F_43 ( & V_65 -> V_21 ) ;
F_44 ( & V_65 -> V_21 ) ;
if ( V_2 -> type -> V_87 ) {
F_7 ( V_2 , V_88 , V_89 ) ;
F_7 ( V_2 , V_90 , V_91 ) ;
}
F_7 ( V_2 , V_24 , 0 ) ;
if ( V_2 -> type -> V_92 ) {
V_3 = F_1 ( V_2 , V_93 ) ;
F_7 ( V_2 , V_93 ,
V_3 | V_94 ) ;
}
V_3 = F_1 ( V_2 , V_8 ) ;
V_68 = V_14 ;
if ( V_2 -> type -> V_80 )
V_68 |= V_95 ;
if ( V_2 -> type -> V_96 ) {
V_68 |= V_97 ;
if ( V_3 & V_97 )
F_45 ( & V_65 -> V_21 , L_3 ) ;
}
if ( V_3 & V_68 )
F_5 ( V_2 , V_8 , V_3 & V_68 ) ;
V_3 = F_1 ( V_2 , V_98 ) ;
if ( V_3 & V_99 )
F_45 ( & V_65 -> V_21 , L_4 ) ;
V_69 = V_3 & ( V_100 | V_101 ) ;
V_69 |= V_99 ;
if ( V_69 & V_100 )
F_45 ( & V_65 -> V_21 , L_5 ) ;
if ( V_3 != V_69 )
F_5 ( V_2 , V_98 , V_69 ) ;
F_46 ( & V_65 -> V_21 , true ) ;
V_2 -> V_2 = F_47 ( & V_65 -> V_21 , V_65 -> V_102 ,
& V_103 , V_104 ) ;
if ( F_40 ( V_2 -> V_2 ) ) {
V_74 = F_41 ( V_2 -> V_2 ) ;
goto V_105;
}
V_74 = F_48 ( & V_65 -> V_21 , V_2 -> V_83 , F_11 , 0 ,
F_49 ( & V_2 -> V_2 -> V_21 ) , V_2 ) ;
if ( V_74 )
goto V_105;
if ( V_2 -> V_83 != V_2 -> V_85 ) {
V_74 = F_48 ( & V_65 -> V_21 , V_2 -> V_85 , F_11 , 0 ,
F_49 ( & V_2 -> V_2 -> V_21 ) , V_2 ) ;
if ( V_74 )
goto V_105;
}
if ( V_2 -> V_79 ) {
if ( ! V_106 ) {
V_53 = V_2 ;
V_106 = F_27 ;
}
}
return 0 ;
V_105:
F_46 ( & V_65 -> V_21 , false ) ;
if ( V_2 -> type -> V_87 )
F_7 ( V_2 , V_88 , 0 ) ;
F_50 ( & V_65 -> V_21 ) ;
F_51 ( & V_65 -> V_21 ) ;
return V_74 ;
}
static int T_5 F_52 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_53 ( V_65 ) ;
if ( V_106 == F_27 &&
V_53 == V_2 ) {
V_106 = NULL ;
V_53 = NULL ;
}
F_46 ( & V_65 -> V_21 , 0 ) ;
F_5 ( V_2 , V_24 , 0 ) ;
if ( V_2 -> type -> V_87 )
F_7 ( V_2 , V_88 , 0 ) ;
F_50 ( & V_65 -> V_21 ) ;
F_51 ( & V_65 -> V_21 ) ;
return 0 ;
}
static int F_54 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
V_2 -> V_107 = F_1 ( V_2 , V_24 ) ;
if ( F_55 ( V_21 ) )
F_56 ( V_2 -> V_85 ) ;
else
F_5 ( V_2 , V_24 , 0 ) ;
F_50 ( V_21 ) ;
return 0 ;
}
static int F_57 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
F_44 ( V_21 ) ;
if ( F_55 ( V_21 ) )
F_58 ( V_2 -> V_85 ) ;
else
F_5 ( V_2 , V_24 , V_2 -> V_107 ) ;
return 0 ;
}
static void F_59 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_53 ( V_65 ) ;
T_1 V_68 ;
V_68 = F_1 ( V_2 , V_24 ) ;
V_68 &= V_27 ;
F_5 ( V_2 , V_24 , V_68 ) ;
}
