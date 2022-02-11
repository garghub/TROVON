static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_10 . V_11 ;
bool V_12 = false ;
V_4 = F_2 ( sizeof( * V_4 ) , V_13 ) ;
if ( ! V_4 )
return NULL ;
if ( V_12 ) {
F_3 ( V_3 -> V_3 , L_1 ) ;
V_4 -> V_14 = ( V_9 -> V_15 << 8 ) | V_9 -> V_16 ;
V_4 -> V_17 = ( V_9 -> V_18 << 8 ) | V_9 -> V_19 ;
V_4 -> V_20 = V_4 -> V_14 + \
( ( V_9 -> V_21 << 8 ) | \
V_9 -> V_22 ) ;
V_4 -> V_23 = V_4 -> V_20 + \
( ( V_9 -> V_24 << 8 ) | \
V_9 -> V_25 ) ;
V_4 -> V_26 = V_4 -> V_14 + ( ( V_9 -> V_27 << 8 ) | \
V_9 -> V_28 ) ;
V_4 -> V_29 = \
V_4 -> V_17 + ( ( V_9 -> V_30 << 8 ) | \
V_9 -> V_31 ) ;
V_4 -> V_32 = \
V_4 -> V_29 + ( ( V_9 -> V_33 << 8 ) | \
V_9 -> V_34 ) ;
V_4 -> V_35 = V_4 -> V_17 + \
( ( V_9 -> V_36 << 8 ) | V_9 -> V_37 ) ;
V_4 -> clock = V_9 -> V_38 * 10 ;
F_3 ( V_3 -> V_3 , L_2 , V_4 -> V_14 ) ;
F_3 ( V_3 -> V_3 , L_3 , V_4 -> V_17 ) ;
F_3 ( V_3 -> V_3 , L_4 , V_4 -> V_20 ) ;
F_3 ( V_3 -> V_3 , L_5 , V_4 -> V_23 ) ;
F_3 ( V_3 -> V_3 , L_6 , V_4 -> V_26 ) ;
F_3 ( V_3 -> V_3 , L_7 , V_4 -> V_29 ) ;
F_3 ( V_3 -> V_3 , L_8 , V_4 -> V_32 ) ;
F_3 ( V_3 -> V_3 , L_9 , V_4 -> V_35 ) ;
F_3 ( V_3 -> V_3 , L_10 , V_4 -> clock ) ;
} else {
V_4 -> V_14 = 864 ;
V_4 -> V_17 = 480 ;
V_4 -> V_20 = 872 ;
V_4 -> V_23 = 876 ;
V_4 -> V_26 = 884 ;
V_4 -> V_29 = 482 ;
V_4 -> V_32 = 494 ;
V_4 -> V_35 = 486 ;
V_4 -> clock = 25777 ;
}
F_4 ( V_4 ) ;
F_5 ( V_4 , 0 ) ;
V_4 -> type |= V_39 ;
return V_4 ;
}
static bool F_6 ( struct V_40 * V_41 ,
struct V_1 * V_4 ,
struct V_1 * V_42 )
{
struct V_2 * V_3 = V_41 -> V_3 ;
struct V_1 * V_43 = F_1 ( V_3 ) ;
if ( V_43 ) {
V_42 -> V_14 = V_43 -> V_14 ;
V_42 -> V_20 = V_43 -> V_20 ;
V_42 -> V_23 = V_43 -> V_23 ;
V_42 -> V_26 = V_43 -> V_26 ;
V_42 -> V_17 = V_43 -> V_17 ;
V_42 -> V_29 = V_43 -> V_29 ;
V_42 -> V_32 = V_43 -> V_32 ;
V_42 -> V_35 = V_43 -> V_35 ;
V_42 -> clock = V_43 -> clock ;
F_5 ( V_42 , V_44 ) ;
F_7 ( V_43 ) ;
}
return true ;
}
static void F_8 ( struct V_40 * V_41 , bool V_45 )
{
int V_46 = 0 ;
struct V_47 * V_48 = F_9 ( V_41 ) ;
struct V_49 * V_50 =
F_10 ( V_48 ) ;
struct V_51 * V_52 =
F_11 ( V_48 ) ;
struct V_53 * V_54 =
F_12 ( V_48 ) ;
struct V_2 * V_3 = V_41 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_7 ;
T_1 V_55 = 0 ;
int V_56 = ( V_50 -> V_57 == 0 ) ? 0 : 2 ;
T_1 V_58 = 0 ;
F_3 ( V_3 -> V_3 , L_11 ,
V_56 , V_45 ? L_12 : L_13 ,
V_50 -> V_59 ? L_14 : L_15 ) ;
if ( V_56 == 2 ) {
if ( V_45 )
V_6 -> V_60 = true ;
else
V_6 -> V_60 = false ;
V_55 = V_61 ;
} else {
if ( ! V_45 )
V_6 -> V_60 = false ;
}
if ( ! F_13 ( V_3 , true ) ) {
F_14 ( V_3 -> V_3 , L_16 ) ;
return;
}
if ( V_45 ) {
if ( V_50 -> V_59 )
goto V_62;
V_46 = F_15 ( V_50 , V_63 ) ;
if ( V_46 ) {
F_14 ( V_3 -> V_3 , L_17 ) ;
goto V_62;
}
V_50 -> V_59 = true ;
if ( V_56 == 2 )
V_6 -> V_64 = true ;
else
V_6 -> V_59 = true ;
F_16 ( V_3 , V_56 ) ;
} else {
if ( ! V_50 -> V_59 && ! V_50 -> V_65 )
goto V_62;
V_50 -> V_59 = false ;
V_50 -> V_65 = false ;
if ( V_56 == 2 )
V_6 -> V_64 = false ;
else
V_6 -> V_59 = false ;
F_17 ( V_3 , V_56 ) ;
V_46 = F_15 ( V_50 , V_66 ) ;
if ( V_46 ) {
F_14 ( V_3 -> V_3 , L_17 ) ;
goto V_62;
}
}
F_18 ( V_52 ,
& V_58 ,
V_67 ) ;
if ( V_45 && V_58 && ! ( V_58 & ( 1 << 7 ) ) ) {
F_19 ( V_54 ,
V_68 ,
NULL ,
0 ,
V_69 ,
V_70 ) ;
if ( V_50 -> V_71 -> V_72 )
V_50 -> V_71 -> V_72 ( V_52 ,
V_56 ) ;
}
V_62:
F_20 ( V_3 ) ;
if ( V_46 )
F_14 ( V_3 -> V_3 , L_18 ) ;
}
static void F_21 ( struct V_40 * V_41 ,
struct V_1 * V_4 ,
struct V_1 * V_42 )
{
int V_46 = 0 ;
struct V_2 * V_3 = V_41 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_47 * V_48 = F_9 ( V_41 ) ;
struct V_49 * V_73 =
F_10 ( V_48 ) ;
struct V_51 * V_52 =
F_11 ( V_48 ) ;
struct V_74 * V_75 = V_52 -> V_76 ;
int V_56 = V_75 -> V_56 ;
T_2 V_77 = 0 ;
T_1 V_78 = V_79 ;
T_1 V_80 = V_81 ;
T_1 V_82 = V_83 ;
T_1 V_55 = 0 ;
T_1 V_84 = V_6 -> V_85 ;
T_1 V_86 = V_6 -> V_87 ;
T_1 V_88 = V_4 -> V_14 ;
T_1 V_89 = V_4 -> V_17 ;
T_1 V_90 ;
V_90 = ( V_91 | V_92 |
V_93 ) ;
F_3 ( V_3 -> V_3 , L_19 , V_90 ) ;
F_3 ( V_3 -> V_3 , L_20 , ( V_56 == 2 ) ? L_21 : L_22 ) ;
F_3 ( V_3 -> V_3 , L_23 , V_4 -> V_14 , V_4 -> V_17 ) ;
if ( V_56 == 2 ) {
V_78 = V_94 ;
V_80 = V_95 ;
V_82 = V_96 ;
V_55 = V_61 ;
V_84 = V_6 -> V_97 ;
V_86 = V_6 -> V_98 ;
} else {
V_90 |= 0x2 ;
}
if ( ! F_13 ( V_3 , true ) ) {
F_14 ( V_3 -> V_3 , L_16 ) ;
return;
}
F_22 ( V_80 , V_84 ) ;
F_23 ( V_80 ) ;
F_24 ( 20 ) ;
V_46 = F_25 ( V_73 , V_99 ,
NULL , 0 , V_100 ) ;
if ( V_46 ) {
F_14 ( V_3 -> V_3 , L_24 ) ;
goto V_62;
}
V_46 = F_25 ( V_73 , V_101 ,
& V_77 , 1 , V_100 ) ;
if ( V_46 ) {
F_14 ( V_3 -> V_3 , L_25 , V_102 ) ;
goto V_62;
}
F_22 ( V_82 , V_86 | V_103 ) ;
F_23 ( V_82 ) ;
if ( V_56 == 2 )
V_6 -> V_98 |= V_103 ;
else
V_6 -> V_87 |= V_103 ;
F_3 ( V_3 -> V_3 , L_26 , F_23 ( V_82 ) ) ;
V_46 = F_26 ( V_73 , 0 , 0 ,
V_88 - 1 , V_89 - 1 ) ;
if ( V_46 ) {
F_14 ( V_3 -> V_3 , L_27 ) ;
goto V_62;
}
V_62:
F_20 ( V_3 ) ;
if ( V_46 )
F_14 ( V_3 -> V_3 , L_28 ) ;
}
static void F_27 ( struct V_40 * V_41 )
{
struct V_47 * V_48 = F_9 ( V_41 ) ;
struct V_49 * V_50
= F_10 ( V_48 ) ;
V_50 -> V_104 |= V_105 ;
V_50 -> V_104 &= ~ V_106 ;
F_8 ( V_41 , false ) ;
}
static void F_28 ( struct V_40 * V_41 )
{
struct V_47 * V_48 = F_9 ( V_41 ) ;
struct V_49 * V_50 =
F_10 ( V_48 ) ;
struct V_2 * V_3 = V_50 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_107 V_108 ;
F_8 ( V_41 , true ) ;
V_50 -> V_104 &= ~ V_105 ;
V_108 . V_109 = V_108 . V_110 = 0 ;
V_108 . V_111 = 864 ;
V_108 . V_112 = 480 ;
if ( V_50 -> V_57 == 1 ) {
V_6 -> V_113 |= V_114 ;
F_29 ( V_3 , V_115 , & V_108 ) ;
} else {
V_6 -> V_113 |= V_116 ;
F_29 ( V_3 , V_117 , & V_108 ) ;
}
V_50 -> V_104 |= V_106 ;
}
static void F_30 ( struct V_40 * V_41 , int V_4 )
{
struct V_47 * V_48 = F_9 ( V_41 ) ;
struct V_49 * V_50
= F_10 ( V_48 ) ;
struct V_2 * V_3 = V_50 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_7 ;
static bool V_118 ;
F_3 ( V_3 -> V_3 , L_29 , ( V_4 == V_63 ? L_30 : L_31 ) ) ;
if ( V_4 == V_63 ) {
if ( V_118 ) {
F_31 ( V_3 , V_119 ) ;
V_118 = false ;
V_6 -> V_120 = true ;
}
F_8 ( V_41 , true ) ;
} else {
V_118 = true ;
V_6 -> V_120 = false ;
F_8 ( V_41 , false ) ;
}
}
static void F_32 ( struct V_49 * V_50 ,
int V_56 )
{
struct V_53 * V_54 =
F_12 ( & V_50 -> V_121 ) ;
struct V_2 * V_3 = V_50 -> V_3 ;
struct V_122 * V_123 = V_50 -> V_121 . V_121 . V_123 ;
struct V_124 * V_125 = ( V_123 ) ?
F_33 ( V_123 ) : NULL ;
T_1 V_126 = V_127 ;
T_1 V_80 = V_81 ;
T_1 V_82 = V_83 ;
T_1 V_128 = V_129 ;
T_1 V_130 = V_131 ;
T_1 V_55 = 0 ;
if ( ( V_50 -> V_104 & V_132 ) ||
( V_125 && V_125 -> V_104 & V_132 ) ||
! ( V_50 -> V_104 & V_106 ) )
return;
if ( V_56 == 2 ) {
V_80 = V_95 ;
V_82 = V_96 ;
V_128 = V_133 ;
V_130 = V_134 ;
V_55 = V_61 ;
}
if ( ! F_13 ( V_3 , true ) ) {
F_14 ( V_3 -> V_3 , L_16 ) ;
return;
}
if ( ! ( F_23 ( V_126 ) & V_135 ) ||
! ( F_23 ( V_80 ) & V_136 ) ||
! ( F_23 ( V_82 ) & V_136 ) )
goto V_137;
F_22 ( V_128 , F_23 ( V_128 ) ) ;
F_22 ( V_130 , F_23 ( V_130 ) ) ;
F_23 ( V_130 ) ;
F_19 ( V_54 ,
V_138 ,
NULL ,
0 ,
V_69 ,
V_70 ) ;
V_50 -> V_139 = true ;
V_137:
F_20 ( V_3 ) ;
}
static int F_34 ( struct V_2 * V_3 ,
int V_56 ,
struct V_140 * V_141 )
{
if ( ! V_3 || ! V_141 )
return - V_142 ;
V_141 -> V_143 = V_144 ;
V_141 -> V_145 = V_146 ;
return 0 ;
}
void F_35 ( struct V_2 * V_3 , struct V_147 * V_71 )
{
V_71 -> V_148 = & V_149 ;
V_71 -> V_150 = & V_151 ;
V_71 -> V_152 = & F_1 ;
V_71 -> V_153 = F_32 ;
V_71 -> V_154 = F_34 ;
V_71 -> V_155 = V_156 ;
V_71 -> V_72 = V_157 ;
}
