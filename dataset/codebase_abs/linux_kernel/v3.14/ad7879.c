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
if ( V_15 > V_2 -> V_28 )
return - V_29 ;
if ( F_7 ( & V_2 -> V_30 ) ) {
F_8 ( V_13 , V_31 , 1 ) ;
F_9 ( V_13 , V_32 , V_2 -> V_16 ) ;
F_9 ( V_13 , V_33 , V_2 -> V_17 ) ;
F_9 ( V_13 , V_34 , V_2 -> V_15 ) ;
F_10 ( V_13 ) ;
}
V_2 -> V_16 = V_16 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_15 = V_15 ;
return 0 ;
}
return - V_29 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_13 * V_13 = V_2 -> V_14 ;
F_9 ( V_13 , V_34 , 0 ) ;
F_8 ( V_13 , V_31 , 0 ) ;
F_10 ( V_13 ) ;
}
static void F_12 ( unsigned long V_35 )
{
struct V_1 * V_2 = ( void * ) V_35 ;
F_11 ( V_2 ) ;
}
static T_3 F_13 ( int V_36 , void * V_35 )
{
struct V_1 * V_2 = V_35 ;
F_2 ( V_2 , V_37 , V_38 , V_2 -> V_20 ) ;
if ( ! F_4 ( V_2 ) )
F_14 ( & V_2 -> V_30 , V_39 + V_40 ) ;
return V_41 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_42 , V_2 -> V_43 ) ;
F_3 ( V_2 , V_44 , V_2 -> V_45 ) ;
F_3 ( V_2 , V_46 , V_2 -> V_47 ) ;
F_16 ( V_2 -> V_36 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_2 V_3 = ( V_2 -> V_43 & ~ F_18 ( - 1 ) ) |
F_18 ( V_48 ) ;
F_19 ( V_2 -> V_36 ) ;
if ( F_20 ( & V_2 -> V_30 ) )
F_11 ( V_2 ) ;
F_3 ( V_2 , V_42 , V_3 ) ;
}
static int F_21 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_22 ( V_14 ) ;
if ( ! V_2 -> V_49 && ! V_2 -> V_50 )
F_15 ( V_2 ) ;
return 0 ;
}
static void F_23 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_22 ( V_14 ) ;
if ( ! V_2 -> V_49 && ! V_2 -> V_50 )
F_17 ( V_2 ) ;
}
static int F_24 ( struct V_51 * V_6 )
{
struct V_1 * V_2 = F_25 ( V_6 ) ;
F_26 ( & V_2 -> V_14 -> V_52 ) ;
if ( ! V_2 -> V_50 && ! V_2 -> V_49 && V_2 -> V_14 -> V_53 )
F_17 ( V_2 ) ;
V_2 -> V_50 = true ;
F_27 ( & V_2 -> V_14 -> V_52 ) ;
return 0 ;
}
static int F_28 ( struct V_51 * V_6 )
{
struct V_1 * V_2 = F_25 ( V_6 ) ;
F_26 ( & V_2 -> V_14 -> V_52 ) ;
if ( V_2 -> V_50 && ! V_2 -> V_49 && V_2 -> V_14 -> V_53 )
F_15 ( V_2 ) ;
V_2 -> V_50 = false ;
F_27 ( & V_2 -> V_14 -> V_52 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 , bool V_54 )
{
F_26 ( & V_2 -> V_14 -> V_52 ) ;
if ( ! V_2 -> V_50 && V_2 -> V_14 -> V_53 != 0 ) {
if ( V_54 ) {
if ( V_2 -> V_49 )
F_15 ( V_2 ) ;
} else {
if ( ! V_2 -> V_49 )
F_17 ( V_2 ) ;
}
}
V_2 -> V_49 = V_54 ;
F_27 ( & V_2 -> V_14 -> V_52 ) ;
}
static T_4 F_30 ( struct V_51 * V_6 ,
struct V_55 * V_56 , char * V_9 )
{
struct V_1 * V_2 = F_25 ( V_6 ) ;
return sprintf ( V_9 , L_1 , V_2 -> V_49 ) ;
}
static T_4 F_31 ( struct V_51 * V_6 ,
struct V_55 * V_56 ,
const char * V_9 , T_5 V_8 )
{
struct V_1 * V_2 = F_25 ( V_6 ) ;
unsigned int V_11 ;
int error ;
error = F_32 ( V_9 , 10 , & V_11 ) ;
if ( error )
return error ;
F_29 ( V_2 , V_11 ) ;
return V_8 ;
}
static int F_33 ( struct V_57 * V_58 ,
unsigned V_59 )
{
struct V_1 * V_2 = F_34 ( V_58 , struct V_1 , V_60 ) ;
int V_61 ;
F_26 ( & V_2 -> V_52 ) ;
V_2 -> V_43 |= V_62 | V_63 | V_64 ;
V_61 = F_3 ( V_2 , V_42 , V_2 -> V_43 ) ;
F_27 ( & V_2 -> V_52 ) ;
return V_61 ;
}
static int F_35 ( struct V_57 * V_58 ,
unsigned V_59 , int V_65 )
{
struct V_1 * V_2 = F_34 ( V_58 , struct V_1 , V_60 ) ;
int V_61 ;
F_26 ( & V_2 -> V_52 ) ;
V_2 -> V_43 &= ~ V_63 ;
V_2 -> V_43 |= V_62 | V_64 ;
if ( V_65 )
V_2 -> V_43 |= V_66 ;
else
V_2 -> V_43 &= ~ V_66 ;
V_61 = F_3 ( V_2 , V_42 , V_2 -> V_43 ) ;
F_27 ( & V_2 -> V_52 ) ;
return V_61 ;
}
static int F_36 ( struct V_57 * V_58 , unsigned V_59 )
{
struct V_1 * V_2 = F_34 ( V_58 , struct V_1 , V_60 ) ;
T_2 V_11 ;
F_26 ( & V_2 -> V_52 ) ;
V_11 = F_1 ( V_2 , V_42 ) ;
F_27 ( & V_2 -> V_52 ) ;
return ! ! ( V_11 & V_66 ) ;
}
static void F_37 ( struct V_57 * V_58 ,
unsigned V_59 , int V_67 )
{
struct V_1 * V_2 = F_34 ( V_58 , struct V_1 , V_60 ) ;
F_26 ( & V_2 -> V_52 ) ;
if ( V_67 )
V_2 -> V_43 |= V_66 ;
else
V_2 -> V_43 &= ~ V_66 ;
F_3 ( V_2 , V_42 , V_2 -> V_43 ) ;
F_27 ( & V_2 -> V_52 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
const struct V_68 * V_69 )
{
int V_70 = 0 ;
F_39 ( & V_2 -> V_52 ) ;
if ( V_69 -> V_71 ) {
V_2 -> V_60 . V_72 = F_33 ;
V_2 -> V_60 . V_73 = F_35 ;
V_2 -> V_60 . V_74 = F_36 ;
V_2 -> V_60 . V_75 = F_37 ;
V_2 -> V_60 . V_76 = 1 ;
V_2 -> V_60 . V_77 = V_69 -> V_78 ;
V_2 -> V_60 . V_79 = 1 ;
V_2 -> V_60 . V_80 = L_2 ;
V_2 -> V_60 . V_81 = V_82 ;
V_2 -> V_60 . V_6 = V_2 -> V_6 ;
V_70 = F_40 ( & V_2 -> V_60 ) ;
if ( V_70 )
F_41 ( V_2 -> V_6 , L_3 ,
V_2 -> V_60 . V_77 ) ;
}
return V_70 ;
}
static void F_42 ( struct V_1 * V_2 )
{
const struct V_68 * V_69 = F_43 ( V_2 -> V_6 ) ;
int V_70 ;
if ( V_69 -> V_71 ) {
V_70 = F_44 ( & V_2 -> V_60 ) ;
if ( V_70 )
F_41 ( V_2 -> V_6 , L_4 ,
V_2 -> V_60 . V_77 ) ;
}
}
static inline int F_38 ( struct V_1 * V_2 ,
const struct V_68 * V_69 )
{
return 0 ;
}
static inline void F_42 ( struct V_1 * V_2 )
{
}
struct V_1 * F_45 ( struct V_51 * V_6 , T_1 V_83 , unsigned int V_36 ,
const struct V_84 * V_4 )
{
struct V_68 * V_69 = F_43 ( V_6 ) ;
struct V_1 * V_2 ;
struct V_13 * V_13 ;
int V_61 ;
T_2 V_85 ;
if ( ! V_36 ) {
F_41 ( V_6 , L_5 ) ;
V_61 = - V_29 ;
goto V_86;
}
if ( ! V_69 ) {
F_41 ( V_6 , L_6 ) ;
V_61 = - V_29 ;
goto V_86;
}
V_2 = F_46 ( sizeof( * V_2 ) , V_87 ) ;
V_13 = F_47 () ;
if ( ! V_2 || ! V_13 ) {
V_61 = - V_88 ;
goto V_89;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_14 = V_13 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_26 = V_69 -> V_26 ;
F_48 ( & V_2 -> V_30 , F_12 , ( unsigned long ) V_2 ) ;
V_2 -> V_27 = V_69 -> V_27 ? : 400 ;
V_2 -> V_28 = V_69 -> V_28 ? : ~ 0 ;
V_2 -> V_90 = V_69 -> V_90 ;
V_2 -> V_91 = V_69 -> V_91 ;
V_2 -> V_92 = V_69 -> V_92 ;
V_2 -> V_93 = V_69 -> V_93 ;
V_2 -> V_94 = V_69 -> V_94 ;
snprintf ( V_2 -> V_95 , sizeof( V_2 -> V_95 ) , L_7 , F_49 ( V_6 ) ) ;
V_13 -> V_96 = L_8 ;
V_13 -> V_95 = V_2 -> V_95 ;
V_13 -> V_6 . V_97 = V_6 ;
V_13 -> V_98 . V_99 = V_4 -> V_99 ;
V_13 -> V_100 = F_21 ;
V_13 -> V_101 = F_23 ;
F_50 ( V_13 , V_2 ) ;
F_51 ( V_102 , V_13 -> V_103 ) ;
F_51 ( V_32 , V_13 -> V_104 ) ;
F_51 ( V_33 , V_13 -> V_104 ) ;
F_51 ( V_34 , V_13 -> V_104 ) ;
F_51 ( V_105 , V_13 -> V_103 ) ;
F_51 ( V_31 , V_13 -> V_106 ) ;
F_52 ( V_13 , V_32 ,
V_69 -> V_107 ? : 0 ,
V_69 -> V_108 ? : V_22 ,
0 , 0 ) ;
F_52 ( V_13 , V_33 ,
V_69 -> V_109 ? : 0 ,
V_69 -> V_110 ? : V_22 ,
0 , 0 ) ;
F_52 ( V_13 , V_34 ,
V_69 -> V_111 , V_69 -> V_28 , 0 , 0 ) ;
V_61 = F_3 ( V_2 , V_42 , V_112 ) ;
if ( V_61 < 0 ) {
F_41 ( V_6 , L_9 , V_13 -> V_96 ) ;
goto V_89;
}
V_85 = F_1 ( V_2 , V_113 ) ;
V_13 -> V_98 . V_114 = ( V_85 & 0xff ) ;
V_13 -> V_98 . V_115 = V_85 >> 8 ;
if ( V_13 -> V_98 . V_114 != V_83 ) {
F_41 ( V_6 , L_10 ,
V_13 -> V_96 , V_83 , V_85 ) ;
V_61 = - V_116 ;
goto V_89;
}
V_2 -> V_45 = V_117 |
V_118 |
V_119 |
V_120 |
V_121 |
V_122 |
V_123 ;
V_2 -> V_43 = F_18 ( V_124 ) | V_125 |
F_53 ( V_2 -> V_92 ) |
F_54 ( V_2 -> V_94 ) |
F_55 ( V_2 -> V_90 ) ;
V_2 -> V_47 = V_126 | V_127 |
F_56 ( V_2 -> V_91 ) |
F_57 ( V_2 -> V_93 ) ;
V_61 = F_58 ( V_2 -> V_36 , NULL , F_13 ,
V_128 | V_129 ,
F_49 ( V_6 ) , V_2 ) ;
if ( V_61 ) {
F_41 ( V_6 , L_11 , V_2 -> V_36 ) ;
goto V_89;
}
F_17 ( V_2 ) ;
V_61 = F_59 ( & V_6 -> V_130 , & V_131 ) ;
if ( V_61 )
goto V_132;
V_61 = F_38 ( V_2 , V_69 ) ;
if ( V_61 )
goto V_133;
V_61 = F_60 ( V_13 ) ;
if ( V_61 )
goto V_134;
return V_2 ;
V_134:
F_42 ( V_2 ) ;
V_133:
F_61 ( & V_6 -> V_130 , & V_131 ) ;
V_132:
F_62 ( V_2 -> V_36 , V_2 ) ;
V_89:
F_63 ( V_13 ) ;
F_64 ( V_2 ) ;
V_86:
return F_65 ( V_61 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
F_61 ( & V_2 -> V_6 -> V_130 , & V_131 ) ;
F_62 ( V_2 -> V_36 , V_2 ) ;
F_67 ( V_2 -> V_14 ) ;
F_64 ( V_2 ) ;
}
