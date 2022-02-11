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
if ( F_5 ( V_16 && V_18 ) ) {
V_15 = ( V_19 - V_18 ) * V_16 * V_2 -> V_26 ;
V_15 /= V_18 ;
V_15 = ( V_15 + 2047 ) >> 12 ;
if ( V_15 > V_2 -> V_27 )
return - V_28 ;
if ( F_6 ( & V_2 -> V_29 ) ) {
F_7 ( V_13 , V_30 , 1 ) ;
F_8 ( V_13 , V_31 , V_2 -> V_16 ) ;
F_8 ( V_13 , V_32 , V_2 -> V_17 ) ;
F_8 ( V_13 , V_33 , V_2 -> V_15 ) ;
F_9 ( V_13 ) ;
}
V_2 -> V_16 = V_16 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_15 = V_15 ;
return 0 ;
}
return - V_28 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_13 * V_13 = V_2 -> V_14 ;
F_8 ( V_13 , V_33 , 0 ) ;
F_7 ( V_13 , V_30 , 0 ) ;
F_9 ( V_13 ) ;
}
static void F_11 ( unsigned long V_34 )
{
struct V_1 * V_2 = ( void * ) V_34 ;
F_10 ( V_2 ) ;
}
static T_3 F_12 ( int V_35 , void * V_34 )
{
struct V_1 * V_2 = V_34 ;
F_2 ( V_2 , V_36 , V_37 , V_2 -> V_20 ) ;
if ( ! F_4 ( V_2 ) )
F_13 ( & V_2 -> V_29 , V_38 + V_39 ) ;
return V_40 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_41 , V_2 -> V_42 ) ;
F_3 ( V_2 , V_43 , V_2 -> V_44 ) ;
F_3 ( V_2 , V_45 , V_2 -> V_46 ) ;
F_15 ( V_2 -> V_35 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_35 ) ;
if ( F_18 ( & V_2 -> V_29 ) )
F_10 ( V_2 ) ;
F_3 ( V_2 , V_41 , F_19 ( V_47 ) ) ;
}
static int F_20 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_21 ( V_14 ) ;
if ( ! V_2 -> V_48 && ! V_2 -> V_49 )
F_14 ( V_2 ) ;
return 0 ;
}
static void F_22 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_21 ( V_14 ) ;
if ( ! V_2 -> V_48 && ! V_2 -> V_49 )
F_16 ( V_2 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_24 ( & V_2 -> V_14 -> V_50 ) ;
if ( ! V_2 -> V_49 && ! V_2 -> V_48 && V_2 -> V_14 -> V_51 )
F_16 ( V_2 ) ;
V_2 -> V_49 = true ;
F_25 ( & V_2 -> V_14 -> V_50 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_24 ( & V_2 -> V_14 -> V_50 ) ;
if ( V_2 -> V_49 && ! V_2 -> V_48 && V_2 -> V_14 -> V_51 )
F_14 ( V_2 ) ;
V_2 -> V_49 = false ;
F_25 ( & V_2 -> V_14 -> V_50 ) ;
}
static void F_27 ( struct V_1 * V_2 , bool V_52 )
{
F_24 ( & V_2 -> V_14 -> V_50 ) ;
if ( ! V_2 -> V_49 && V_2 -> V_14 -> V_51 != 0 ) {
if ( V_52 ) {
if ( V_2 -> V_48 )
F_14 ( V_2 ) ;
} else {
if ( ! V_2 -> V_48 )
F_16 ( V_2 ) ;
}
}
V_2 -> V_48 = V_52 ;
F_25 ( & V_2 -> V_14 -> V_50 ) ;
}
static T_4 F_28 ( struct V_53 * V_6 ,
struct V_54 * V_55 , char * V_9 )
{
struct V_1 * V_2 = F_29 ( V_6 ) ;
return sprintf ( V_9 , L_1 , V_2 -> V_48 ) ;
}
static T_4 F_30 ( struct V_53 * V_6 ,
struct V_54 * V_55 ,
const char * V_9 , T_5 V_8 )
{
struct V_1 * V_2 = F_29 ( V_6 ) ;
unsigned long V_11 ;
int error ;
error = F_31 ( V_9 , 10 , & V_11 ) ;
if ( error )
return error ;
F_27 ( V_2 , V_11 ) ;
return V_8 ;
}
static int F_32 ( struct V_56 * V_57 ,
unsigned V_58 )
{
struct V_1 * V_2 = F_33 ( V_57 , struct V_1 , V_59 ) ;
int V_60 ;
F_24 ( & V_2 -> V_50 ) ;
V_2 -> V_42 |= V_61 | V_62 | V_63 ;
V_60 = F_3 ( V_2 , V_41 , V_2 -> V_42 ) ;
F_25 ( & V_2 -> V_50 ) ;
return V_60 ;
}
static int F_34 ( struct V_56 * V_57 ,
unsigned V_58 , int V_64 )
{
struct V_1 * V_2 = F_33 ( V_57 , struct V_1 , V_59 ) ;
int V_60 ;
F_24 ( & V_2 -> V_50 ) ;
V_2 -> V_42 &= ~ V_62 ;
V_2 -> V_42 |= V_61 | V_63 ;
if ( V_64 )
V_2 -> V_42 |= V_65 ;
else
V_2 -> V_42 &= ~ V_65 ;
V_60 = F_3 ( V_2 , V_41 , V_2 -> V_42 ) ;
F_25 ( & V_2 -> V_50 ) ;
return V_60 ;
}
static int F_35 ( struct V_56 * V_57 , unsigned V_58 )
{
struct V_1 * V_2 = F_33 ( V_57 , struct V_1 , V_59 ) ;
T_2 V_11 ;
F_24 ( & V_2 -> V_50 ) ;
V_11 = F_1 ( V_2 , V_41 ) ;
F_25 ( & V_2 -> V_50 ) ;
return ! ! ( V_11 & V_65 ) ;
}
static void F_36 ( struct V_56 * V_57 ,
unsigned V_58 , int V_66 )
{
struct V_1 * V_2 = F_33 ( V_57 , struct V_1 , V_59 ) ;
F_24 ( & V_2 -> V_50 ) ;
if ( V_66 )
V_2 -> V_42 |= V_65 ;
else
V_2 -> V_42 &= ~ V_65 ;
F_3 ( V_2 , V_41 , V_2 -> V_42 ) ;
F_25 ( & V_2 -> V_50 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_67 * V_68 )
{
int V_69 = 0 ;
F_38 ( & V_2 -> V_50 ) ;
if ( V_68 -> V_70 ) {
V_2 -> V_59 . V_71 = F_32 ;
V_2 -> V_59 . V_72 = F_34 ;
V_2 -> V_59 . V_73 = F_35 ;
V_2 -> V_59 . V_74 = F_36 ;
V_2 -> V_59 . V_75 = 1 ;
V_2 -> V_59 . V_76 = V_68 -> V_77 ;
V_2 -> V_59 . V_78 = 1 ;
V_2 -> V_59 . V_79 = L_2 ;
V_2 -> V_59 . V_80 = V_81 ;
V_2 -> V_59 . V_6 = V_2 -> V_6 ;
V_69 = F_39 ( & V_2 -> V_59 ) ;
if ( V_69 )
F_40 ( V_2 -> V_6 , L_3 ,
V_2 -> V_59 . V_76 ) ;
}
return V_69 ;
}
static void F_41 ( struct V_1 * V_2 )
{
const struct V_67 * V_68 = V_2 -> V_6 -> V_82 ;
int V_69 ;
if ( V_68 -> V_70 ) {
V_69 = F_42 ( & V_2 -> V_59 ) ;
if ( V_69 )
F_40 ( V_2 -> V_6 , L_4 ,
V_2 -> V_59 . V_76 ) ;
}
}
static inline int F_37 ( struct V_1 * V_2 ,
const struct V_67 * V_68 )
{
return 0 ;
}
static inline void F_41 ( struct V_1 * V_2 )
{
}
struct V_1 * F_43 ( struct V_53 * V_6 , T_1 V_83 , unsigned int V_35 ,
const struct V_84 * V_4 )
{
struct V_67 * V_68 = V_6 -> V_82 ;
struct V_1 * V_2 ;
struct V_13 * V_13 ;
int V_60 ;
T_2 V_85 ;
if ( ! V_35 ) {
F_40 ( V_6 , L_5 ) ;
V_60 = - V_28 ;
goto V_86;
}
if ( ! V_68 ) {
F_40 ( V_6 , L_6 ) ;
V_60 = - V_28 ;
goto V_86;
}
V_2 = F_44 ( sizeof( * V_2 ) , V_87 ) ;
V_13 = F_45 () ;
if ( ! V_2 || ! V_13 ) {
V_60 = - V_88 ;
goto V_89;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_14 = V_13 ;
V_2 -> V_35 = V_35 ;
F_46 ( & V_2 -> V_29 , F_11 , ( unsigned long ) V_2 ) ;
V_2 -> V_26 = V_68 -> V_26 ? : 400 ;
V_2 -> V_27 = V_68 -> V_27 ? : ~ 0 ;
V_2 -> V_90 = V_68 -> V_90 ;
V_2 -> V_91 = V_68 -> V_91 ;
V_2 -> V_92 = V_68 -> V_92 ;
V_2 -> V_93 = V_68 -> V_93 ;
V_2 -> V_94 = V_68 -> V_94 ;
snprintf ( V_2 -> V_95 , sizeof( V_2 -> V_95 ) , L_7 , F_47 ( V_6 ) ) ;
V_13 -> V_96 = L_8 ;
V_13 -> V_95 = V_2 -> V_95 ;
V_13 -> V_6 . V_97 = V_6 ;
V_13 -> V_98 . V_99 = V_4 -> V_99 ;
V_13 -> V_100 = F_20 ;
V_13 -> V_101 = F_22 ;
F_48 ( V_13 , V_2 ) ;
F_49 ( V_102 , V_13 -> V_103 ) ;
F_49 ( V_31 , V_13 -> V_104 ) ;
F_49 ( V_32 , V_13 -> V_104 ) ;
F_49 ( V_33 , V_13 -> V_104 ) ;
F_49 ( V_105 , V_13 -> V_103 ) ;
F_49 ( V_30 , V_13 -> V_106 ) ;
F_50 ( V_13 , V_31 ,
V_68 -> V_107 ? : 0 ,
V_68 -> V_108 ? : V_22 ,
0 , 0 ) ;
F_50 ( V_13 , V_32 ,
V_68 -> V_109 ? : 0 ,
V_68 -> V_110 ? : V_22 ,
0 , 0 ) ;
F_50 ( V_13 , V_33 ,
V_68 -> V_111 , V_68 -> V_27 , 0 , 0 ) ;
V_60 = F_3 ( V_2 , V_41 , V_112 ) ;
if ( V_60 < 0 ) {
F_40 ( V_6 , L_9 , V_13 -> V_96 ) ;
goto V_89;
}
V_85 = F_1 ( V_2 , V_113 ) ;
V_13 -> V_98 . V_114 = ( V_85 & 0xff ) ;
V_13 -> V_98 . V_115 = V_85 >> 8 ;
if ( V_13 -> V_98 . V_114 != V_83 ) {
F_40 ( V_6 , L_10 ,
V_13 -> V_96 , V_83 , V_85 ) ;
V_60 = - V_116 ;
goto V_89;
}
V_2 -> V_44 = V_117 |
V_118 |
V_119 |
V_120 |
V_121 |
V_122 |
V_123 ;
V_2 -> V_42 = F_19 ( V_124 ) | V_125 |
F_51 ( V_2 -> V_92 ) |
F_52 ( V_2 -> V_94 ) |
F_53 ( V_2 -> V_90 ) ;
V_2 -> V_46 = V_126 | V_127 |
F_54 ( V_2 -> V_91 ) |
F_55 ( V_2 -> V_93 ) ;
V_60 = F_56 ( V_2 -> V_35 , NULL , F_12 ,
V_128 ,
F_47 ( V_6 ) , V_2 ) ;
if ( V_60 ) {
F_40 ( V_6 , L_11 , V_2 -> V_35 ) ;
goto V_89;
}
F_16 ( V_2 ) ;
V_60 = F_57 ( & V_6 -> V_129 , & V_130 ) ;
if ( V_60 )
goto V_131;
V_60 = F_37 ( V_2 , V_68 ) ;
if ( V_60 )
goto V_132;
V_60 = F_58 ( V_13 ) ;
if ( V_60 )
goto V_133;
return V_2 ;
V_133:
F_41 ( V_2 ) ;
V_132:
F_59 ( & V_6 -> V_129 , & V_130 ) ;
V_131:
F_60 ( V_2 -> V_35 , V_2 ) ;
V_89:
F_61 ( V_13 ) ;
F_62 ( V_2 ) ;
V_86:
return F_63 ( V_60 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
F_41 ( V_2 ) ;
F_59 ( & V_2 -> V_6 -> V_129 , & V_130 ) ;
F_60 ( V_2 -> V_35 , V_2 ) ;
F_65 ( V_2 -> V_14 ) ;
F_62 ( V_2 ) ;
}
