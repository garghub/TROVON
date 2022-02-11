static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_2 -> V_4 -> V_5 ( V_2 -> V_6 , V_3 ) ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_8 , T_2 * V_9 )
{
return V_2 -> V_4 -> V_10 ( V_2 -> V_6 , V_7 , V_8 , V_9 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_11 )
{
return V_2 -> V_4 -> V_12 ( V_2 -> V_6 , V_3 , V_11 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_13 * V_13 = V_2 -> V_14 ;
unsigned V_15 ;
T_2 V_16 , V_17 , V_18 , V_19 ;
V_16 = V_2 -> V_20 [ V_21 ] & V_22 ;
V_17 = V_2 -> V_20 [ V_23 ] & V_22 ;
V_18 = V_2 -> V_20 [ V_24 ] & V_22 ;
V_19 = V_2 -> V_20 [ V_25 ] & V_22 ;
if ( V_2 -> V_26 )
F_5 ( V_16 , V_17 ) ;
if ( F_6 ( V_16 && V_18 ) ) {
V_15 = ( V_19 - V_18 ) * V_16 * V_2 -> V_27 ;
V_15 /= V_18 ;
V_15 = ( V_15 + 2047 ) >> 12 ;
if ( V_15 > F_7 ( V_13 , V_28 ) )
return - V_29 ;
if ( F_8 ( & V_2 -> V_30 ) ) {
F_9 ( V_13 , V_31 , 1 ) ;
F_10 ( V_13 , V_32 , V_2 -> V_16 ) ;
F_10 ( V_13 , V_33 , V_2 -> V_17 ) ;
F_10 ( V_13 , V_28 , V_2 -> V_15 ) ;
F_11 ( V_13 ) ;
}
V_2 -> V_16 = V_16 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_15 = V_15 ;
return 0 ;
}
return - V_29 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_13 * V_13 = V_2 -> V_14 ;
F_10 ( V_13 , V_28 , 0 ) ;
F_9 ( V_13 , V_31 , 0 ) ;
F_11 ( V_13 ) ;
}
static void F_13 ( unsigned long V_34 )
{
struct V_1 * V_2 = ( void * ) V_34 ;
F_12 ( V_2 ) ;
}
static T_3 F_14 ( int V_35 , void * V_34 )
{
struct V_1 * V_2 = V_34 ;
F_2 ( V_2 , V_36 , V_37 , V_2 -> V_20 ) ;
if ( ! F_4 ( V_2 ) )
F_15 ( & V_2 -> V_30 , V_38 + V_39 ) ;
return V_40 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_41 , V_2 -> V_42 ) ;
F_3 ( V_2 , V_43 , V_2 -> V_44 ) ;
F_3 ( V_2 , V_45 , V_2 -> V_46 ) ;
F_17 ( V_2 -> V_35 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_2 V_3 = ( V_2 -> V_42 & ~ F_19 ( - 1 ) ) |
F_19 ( V_47 ) ;
F_20 ( V_2 -> V_35 ) ;
if ( F_21 ( & V_2 -> V_30 ) )
F_12 ( V_2 ) ;
F_3 ( V_2 , V_41 , V_3 ) ;
}
static int F_22 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_23 ( V_14 ) ;
if ( ! V_2 -> V_48 && ! V_2 -> V_49 )
F_16 ( V_2 ) ;
return 0 ;
}
static void F_24 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_23 ( V_14 ) ;
if ( ! V_2 -> V_48 && ! V_2 -> V_49 )
F_18 ( V_2 ) ;
}
static int T_4 F_25 ( struct V_50 * V_6 )
{
struct V_1 * V_2 = F_26 ( V_6 ) ;
F_27 ( & V_2 -> V_14 -> V_51 ) ;
if ( ! V_2 -> V_49 && ! V_2 -> V_48 && V_2 -> V_14 -> V_52 )
F_18 ( V_2 ) ;
V_2 -> V_49 = true ;
F_28 ( & V_2 -> V_14 -> V_51 ) ;
return 0 ;
}
static int T_4 F_29 ( struct V_50 * V_6 )
{
struct V_1 * V_2 = F_26 ( V_6 ) ;
F_27 ( & V_2 -> V_14 -> V_51 ) ;
if ( V_2 -> V_49 && ! V_2 -> V_48 && V_2 -> V_14 -> V_52 )
F_16 ( V_2 ) ;
V_2 -> V_49 = false ;
F_28 ( & V_2 -> V_14 -> V_51 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 , bool V_53 )
{
F_27 ( & V_2 -> V_14 -> V_51 ) ;
if ( ! V_2 -> V_49 && V_2 -> V_14 -> V_52 != 0 ) {
if ( V_53 ) {
if ( V_2 -> V_48 )
F_16 ( V_2 ) ;
} else {
if ( ! V_2 -> V_48 )
F_18 ( V_2 ) ;
}
}
V_2 -> V_48 = V_53 ;
F_28 ( & V_2 -> V_14 -> V_51 ) ;
}
static T_5 F_31 ( struct V_50 * V_6 ,
struct V_54 * V_55 , char * V_9 )
{
struct V_1 * V_2 = F_26 ( V_6 ) ;
return sprintf ( V_9 , L_1 , V_2 -> V_48 ) ;
}
static T_5 F_32 ( struct V_50 * V_6 ,
struct V_54 * V_55 ,
const char * V_9 , T_6 V_8 )
{
struct V_1 * V_2 = F_26 ( V_6 ) ;
unsigned int V_11 ;
int error ;
error = F_33 ( V_9 , 10 , & V_11 ) ;
if ( error )
return error ;
F_30 ( V_2 , V_11 ) ;
return V_8 ;
}
static int F_34 ( struct V_56 * V_57 ,
unsigned V_58 )
{
struct V_1 * V_2 = F_35 ( V_57 ) ;
int V_59 ;
F_27 ( & V_2 -> V_51 ) ;
V_2 -> V_42 |= V_60 | V_61 | V_62 ;
V_59 = F_3 ( V_2 , V_41 , V_2 -> V_42 ) ;
F_28 ( & V_2 -> V_51 ) ;
return V_59 ;
}
static int F_36 ( struct V_56 * V_57 ,
unsigned V_58 , int V_63 )
{
struct V_1 * V_2 = F_35 ( V_57 ) ;
int V_59 ;
F_27 ( & V_2 -> V_51 ) ;
V_2 -> V_42 &= ~ V_61 ;
V_2 -> V_42 |= V_60 | V_62 ;
if ( V_63 )
V_2 -> V_42 |= V_64 ;
else
V_2 -> V_42 &= ~ V_64 ;
V_59 = F_3 ( V_2 , V_41 , V_2 -> V_42 ) ;
F_28 ( & V_2 -> V_51 ) ;
return V_59 ;
}
static int F_37 ( struct V_56 * V_57 , unsigned V_58 )
{
struct V_1 * V_2 = F_35 ( V_57 ) ;
T_2 V_11 ;
F_27 ( & V_2 -> V_51 ) ;
V_11 = F_1 ( V_2 , V_41 ) ;
F_28 ( & V_2 -> V_51 ) ;
return ! ! ( V_11 & V_64 ) ;
}
static void F_38 ( struct V_56 * V_57 ,
unsigned V_58 , int V_65 )
{
struct V_1 * V_2 = F_35 ( V_57 ) ;
F_27 ( & V_2 -> V_51 ) ;
if ( V_65 )
V_2 -> V_42 |= V_64 ;
else
V_2 -> V_42 &= ~ V_64 ;
F_3 ( V_2 , V_41 , V_2 -> V_42 ) ;
F_28 ( & V_2 -> V_51 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
const struct V_66 * V_67 )
{
int V_68 = 0 ;
F_40 ( & V_2 -> V_51 ) ;
if ( V_67 -> V_69 ) {
V_2 -> V_70 . V_71 = F_34 ;
V_2 -> V_70 . V_72 = F_36 ;
V_2 -> V_70 . V_73 = F_37 ;
V_2 -> V_70 . V_74 = F_38 ;
V_2 -> V_70 . V_75 = 1 ;
V_2 -> V_70 . V_76 = V_67 -> V_77 ;
V_2 -> V_70 . V_78 = 1 ;
V_2 -> V_70 . V_79 = L_2 ;
V_2 -> V_70 . V_80 = V_81 ;
V_2 -> V_70 . V_82 = V_2 -> V_6 ;
V_68 = F_41 ( & V_2 -> V_70 , V_2 ) ;
if ( V_68 )
F_42 ( V_2 -> V_6 , L_3 ,
V_2 -> V_70 . V_76 ) ;
}
return V_68 ;
}
static void F_43 ( struct V_1 * V_2 )
{
const struct V_66 * V_67 = F_44 ( V_2 -> V_6 ) ;
if ( V_67 && V_67 -> V_69 )
F_45 ( & V_2 -> V_70 ) ;
}
static inline int F_39 ( struct V_1 * V_2 ,
const struct V_66 * V_67 )
{
return 0 ;
}
static inline void F_43 ( struct V_1 * V_2 )
{
}
static int F_46 ( struct V_50 * V_6 , struct V_1 * V_2 )
{
int V_59 ;
T_7 V_83 ;
V_59 = F_47 ( V_6 , L_4 , & V_83 ) ;
if ( V_59 ) {
F_42 ( V_6 , L_5 ) ;
return V_59 ;
}
V_2 -> V_27 = ( T_2 ) V_83 ;
F_48 ( V_6 , L_6 ,
& V_2 -> V_84 ) ;
F_48 ( V_6 , L_7 ,
& V_2 -> V_85 ) ;
F_48 ( V_6 , L_8 , & V_2 -> V_86 ) ;
F_48 ( V_6 , L_9 , & V_2 -> V_87 ) ;
F_48 ( V_6 , L_10 ,
& V_2 -> V_88 ) ;
V_2 -> V_26 = F_49 ( V_6 , L_11 ) ;
return 0 ;
}
struct V_1 * F_50 ( struct V_50 * V_6 , T_1 V_89 , unsigned int V_35 ,
const struct V_90 * V_4 )
{
struct V_66 * V_67 = F_44 ( V_6 ) ;
struct V_1 * V_2 ;
struct V_13 * V_13 ;
int V_59 ;
T_2 V_91 ;
if ( ! V_35 ) {
F_42 ( V_6 , L_12 ) ;
return F_51 ( - V_29 ) ;
}
V_2 = F_52 ( V_6 , sizeof( * V_2 ) , V_92 ) ;
if ( ! V_2 )
return F_51 ( - V_93 ) ;
if ( V_67 ) {
V_2 -> V_26 = ! V_67 -> V_26 ;
V_2 -> V_27 = V_67 -> V_27 ? : 400 ;
V_2 -> V_84 = V_67 -> V_84 ;
V_2 -> V_85 = V_67 -> V_85 ;
V_2 -> V_87 = V_67 -> V_87 ;
V_2 -> V_88 = V_67 -> V_88 ;
V_2 -> V_86 = V_67 -> V_86 ;
} else if ( V_6 -> V_94 ) {
F_46 ( V_6 , V_2 ) ;
} else {
F_42 ( V_6 , L_13 ) ;
return F_51 ( - V_29 ) ;
}
V_13 = F_53 ( V_6 ) ;
if ( ! V_13 ) {
F_42 ( V_6 , L_14 ) ;
return F_51 ( - V_93 ) ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_14 = V_13 ;
V_2 -> V_35 = V_35 ;
F_54 ( & V_2 -> V_30 , F_13 , ( unsigned long ) V_2 ) ;
snprintf ( V_2 -> V_95 , sizeof( V_2 -> V_95 ) , L_15 , F_55 ( V_6 ) ) ;
V_13 -> V_96 = L_16 ;
V_13 -> V_95 = V_2 -> V_95 ;
V_13 -> V_6 . V_82 = V_6 ;
V_13 -> V_97 . V_98 = V_4 -> V_98 ;
V_13 -> V_99 = F_22 ;
V_13 -> V_100 = F_24 ;
F_56 ( V_13 , V_2 ) ;
F_57 ( V_101 , V_13 -> V_102 ) ;
F_57 ( V_32 , V_13 -> V_103 ) ;
F_57 ( V_33 , V_13 -> V_103 ) ;
F_57 ( V_28 , V_13 -> V_103 ) ;
F_57 ( V_104 , V_13 -> V_102 ) ;
F_57 ( V_31 , V_13 -> V_105 ) ;
if ( V_67 ) {
F_58 ( V_13 , V_32 ,
V_67 -> V_106 ? : 0 ,
V_67 -> V_107 ? : V_22 ,
0 , 0 ) ;
F_58 ( V_13 , V_33 ,
V_67 -> V_108 ? : 0 ,
V_67 -> V_109 ? : V_22 ,
0 , 0 ) ;
F_58 ( V_13 , V_28 ,
V_67 -> V_110 ,
V_67 -> V_111 ? : ~ 0 ,
0 , 0 ) ;
} else {
F_58 ( V_13 , V_32 , 0 , V_22 , 0 , 0 ) ;
F_58 ( V_13 , V_33 , 0 , V_22 , 0 , 0 ) ;
F_59 ( V_13 , false , NULL ) ;
if ( ! F_7 ( V_13 , V_28 ) ) {
F_42 ( V_6 , L_17 ) ;
return F_51 ( - V_29 ) ;
}
}
V_59 = F_3 ( V_2 , V_41 , V_112 ) ;
if ( V_59 < 0 ) {
F_42 ( V_6 , L_18 , V_13 -> V_96 ) ;
return F_51 ( V_59 ) ;
}
V_91 = F_1 ( V_2 , V_113 ) ;
V_13 -> V_97 . V_114 = ( V_91 & 0xff ) ;
V_13 -> V_97 . V_115 = V_91 >> 8 ;
if ( V_13 -> V_97 . V_114 != V_89 ) {
F_42 ( V_6 , L_19 ,
V_13 -> V_96 , V_89 , V_91 ) ;
return F_51 ( - V_116 ) ;
}
V_2 -> V_44 = V_117 |
V_118 |
V_119 |
V_120 |
V_121 |
V_122 |
V_123 ;
V_2 -> V_42 = F_19 ( V_124 ) | V_125 |
F_60 ( V_2 -> V_87 ) |
F_61 ( V_2 -> V_86 ) |
F_62 ( V_2 -> V_84 ) ;
V_2 -> V_46 = V_126 | V_127 |
F_63 ( V_2 -> V_85 ) |
F_64 ( V_2 -> V_88 ) ;
V_59 = F_65 ( V_6 , V_2 -> V_35 , NULL , F_14 ,
V_128 | V_129 ,
F_55 ( V_6 ) , V_2 ) ;
if ( V_59 ) {
F_42 ( V_6 , L_20 , V_59 ) ;
return F_51 ( V_59 ) ;
}
F_18 ( V_2 ) ;
V_59 = F_66 ( & V_6 -> V_130 , & V_131 ) ;
if ( V_59 )
goto V_132;
if ( V_67 ) {
V_59 = F_39 ( V_2 , V_67 ) ;
if ( V_59 )
goto V_133;
}
V_59 = F_67 ( V_13 ) ;
if ( V_59 )
goto V_134;
return V_2 ;
V_134:
F_43 ( V_2 ) ;
V_133:
F_68 ( & V_6 -> V_130 , & V_131 ) ;
V_132:
return F_51 ( V_59 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
F_68 ( & V_2 -> V_6 -> V_130 , & V_131 ) ;
}
