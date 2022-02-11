static void F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned long V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , unsigned long V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static unsigned long F_5 ( struct V_1 * V_2 ,
unsigned long V_4 )
{
if ( V_2 -> V_6 )
V_4 += ( V_4 >= V_7 ) ? 0x10 : 0x40 ;
return V_4 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned long V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + F_5 ( V_2 , V_4 ) ) ;
if ( V_4 != V_7 )
F_4 ( V_2 -> V_5 + F_5 ( V_2 , V_4 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , unsigned long V_4 )
{
return F_4 ( V_2 -> V_5 + F_5 ( V_2 , V_4 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , void * V_8 ,
unsigned long V_4 , int V_9 )
{
F_9 ( V_2 -> V_5 + F_5 ( V_2 , V_4 ) , V_8 , V_9 ) ;
}
static void F_10 ( struct V_1 * V_2 , void * V_8 ,
unsigned long V_4 , int V_9 )
{
F_11 ( V_2 -> V_5 + F_5 ( V_2 , V_4 ) , V_8 , V_9 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_11 = F_7 ( V_2 , V_12 ) ;
V_11 &= ~ V_10 ;
F_6 ( V_2 , V_11 , V_12 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_11 = F_7 ( V_2 , V_12 ) ;
V_11 |= V_10 ;
F_6 ( V_2 , V_11 , V_12 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned long V_13 = V_14 + V_15 ;
T_1 V_3 = F_7 ( V_2 , V_16 ) ;
V_3 |= V_17 | V_18 ;
F_6 ( V_2 , V_3 , V_16 ) ;
while ( F_7 ( V_2 , V_16 ) &
( V_17 | V_18 ) ) {
if ( F_15 ( V_14 , V_13 ) ) {
F_16 ( V_2 -> V_19 , L_1 ) ;
return - V_20 ;
}
F_17 ( 1 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_21 ;
T_2 * V_22 = V_2 -> V_23 ;
T_3 V_24 = V_2 -> V_25 ;
int V_26 ;
V_3 = F_7 ( V_2 , V_27 ) ;
V_21 = ( V_3 & V_28 ) >>
V_29 ;
V_26 = V_24 / V_30 ;
if ( V_26 > V_21 )
V_26 = V_21 ;
F_10 ( V_2 , V_22 , V_31 , V_26 ) ;
V_22 += V_26 * V_30 ;
V_24 -= V_26 * V_30 ;
V_21 -= V_26 ;
if ( V_21 > 0 && V_24 > 0 ) {
F_19 ( V_24 > 3 ) ;
V_3 = F_7 ( V_2 , V_31 ) ;
V_3 = F_20 ( V_3 ) ;
memcpy ( V_22 , & V_3 , V_24 ) ;
V_24 = 0 ;
V_21 -- ;
}
F_19 ( V_21 > 0 && V_24 > 0 ) ;
V_2 -> V_25 = V_24 ;
V_2 -> V_23 = V_22 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_32 ;
T_2 * V_22 = V_2 -> V_23 ;
T_3 V_24 = V_2 -> V_25 ;
int V_26 ;
V_3 = F_7 ( V_2 , V_27 ) ;
V_32 = ( V_3 & V_33 ) >>
V_34 ;
V_26 = V_24 / V_30 ;
if ( V_26 ) {
if ( V_26 > V_32 )
V_26 = V_32 ;
V_24 -= V_26 * V_30 ;
V_32 -= V_26 ;
V_2 -> V_25 = V_24 ;
V_2 -> V_23 = V_22 +
V_26 * V_30 ;
F_22 () ;
F_8 ( V_2 , V_22 , V_7 , V_26 ) ;
V_22 += V_26 * V_30 ;
}
if ( V_32 > 0 && V_24 > 0 ) {
F_19 ( V_24 > 3 ) ;
memcpy ( & V_3 , V_22 , V_24 ) ;
V_3 = F_23 ( V_3 ) ;
V_2 -> V_25 = 0 ;
V_2 -> V_23 = NULL ;
F_22 () ;
F_6 ( V_2 , V_3 , V_7 ) ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
V_3 = F_3 ( V_2 , V_35 ) ;
V_3 |= V_36 ;
V_3 |= V_37 ;
F_1 ( V_2 , V_3 , V_35 ) ;
V_3 = F_3 ( V_2 , V_38 ) ;
V_3 |= V_39 ;
F_1 ( V_2 , V_3 , V_38 ) ;
}
static inline int F_25 ( struct V_1 * V_2 )
{
int V_40 ;
if ( ! V_2 -> V_41 -> V_42 ) {
V_40 = F_26 ( V_2 -> V_43 ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_19 ,
L_2 , V_40 ) ;
return V_40 ;
}
}
V_40 = F_26 ( V_2 -> V_44 ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_19 ,
L_3 , V_40 ) ;
F_28 ( V_2 -> V_43 ) ;
}
return V_40 ;
}
static inline void F_29 ( struct V_1 * V_2 )
{
F_28 ( V_2 -> V_44 ) ;
if ( ! V_2 -> V_41 -> V_42 )
F_28 ( V_2 -> V_43 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_45 = 0 ;
T_1 V_46 ;
V_45 = F_25 ( V_2 ) ;
if ( V_45 < 0 ) {
F_27 ( V_2 -> V_19 , L_4 , V_45 ) ;
return V_45 ;
}
F_31 ( V_2 -> V_47 ) ;
F_32 ( 2 ) ;
F_33 ( V_2 -> V_47 ) ;
if ( V_2 -> V_6 )
F_24 ( V_2 ) ;
V_3 = V_48 | V_49 |
( 0x2 << V_50 ) ;
F_6 ( V_2 , V_3 , V_51 ) ;
F_6 ( V_2 , 0 , V_12 ) ;
V_46 = V_2 -> V_41 -> V_52 ;
V_46 |= V_2 -> V_41 -> V_53 <<
V_54 ;
F_6 ( V_2 , V_46 , V_55 ) ;
if ( ! V_2 -> V_6 ) {
T_1 V_56 = F_7 ( V_2 , V_57 ) ;
V_56 |= V_58 | V_59 ;
F_6 ( V_2 , V_56 , V_57 ) ;
F_6 ( V_2 , 0xfc , V_60 ) ;
F_6 ( V_2 , 0x00 , V_61 ) ;
}
V_3 = 7 << V_62 |
0 << V_63 ;
F_6 ( V_2 , V_3 , V_16 ) ;
if ( F_14 ( V_2 ) )
V_45 = - V_20 ;
F_29 ( V_2 ) ;
if ( V_2 -> V_64 ) {
V_2 -> V_64 = 0 ;
F_34 ( V_2 -> V_65 ) ;
}
return V_45 ;
}
static T_4 F_35 ( int V_65 , void * V_66 )
{
T_1 V_67 ;
const T_1 V_68 = V_69 | V_70 ;
struct V_1 * V_2 = V_66 ;
V_67 = F_7 ( V_2 , V_71 ) ;
if ( V_67 == 0 ) {
F_16 ( V_2 -> V_19 , L_5 ,
F_7 ( V_2 , V_72 ) ,
F_7 ( V_2 , V_73 ) ,
F_7 ( V_2 , V_51 ) ) ;
V_2 -> V_74 |= V_75 ;
if ( ! V_2 -> V_64 ) {
F_36 ( V_2 -> V_65 ) ;
V_2 -> V_64 = 1 ;
}
goto V_45;
}
if ( F_37 ( V_67 & V_68 ) ) {
if ( V_67 & V_69 )
V_2 -> V_74 |= V_76 ;
if ( V_67 & V_70 )
V_2 -> V_74 |= V_77 ;
goto V_45;
}
if ( V_2 -> V_78 && ( V_67 & V_79 ) ) {
if ( V_2 -> V_25 )
F_18 ( V_2 ) ;
else
F_38 () ;
}
if ( ! V_2 -> V_78 && ( V_67 & V_80 ) ) {
if ( V_2 -> V_25 )
F_21 ( V_2 ) ;
else
F_12 ( V_2 , V_80 ) ;
}
F_6 ( V_2 , V_67 , V_71 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_81 , V_82 ) ;
if ( V_67 & V_83 ) {
F_19 ( V_2 -> V_25 ) ;
F_39 ( & V_2 -> V_84 ) ;
}
return V_85 ;
V_45:
F_12 ( V_2 , V_69 | V_70 |
V_83 | V_80 |
V_79 ) ;
F_6 ( V_2 , V_67 , V_71 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_81 , V_82 ) ;
F_39 ( & V_2 -> V_84 ) ;
return V_85 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_86 * V_87 , enum V_88 V_89 )
{
T_1 V_90 ;
T_1 V_11 ;
unsigned long V_91 ;
F_14 ( V_2 ) ;
if ( V_87 -> V_9 == 0 )
return - V_92 ;
V_2 -> V_23 = V_87 -> V_22 ;
V_2 -> V_25 = V_87 -> V_9 ;
V_2 -> V_74 = V_93 ;
V_2 -> V_78 = ( V_87 -> V_94 & V_95 ) ;
F_41 ( & V_2 -> V_84 ) ;
V_90 = ( 0 << V_96 ) |
V_97 |
( V_2 -> V_98 << V_99 ) |
( 1 << V_100 ) ;
F_6 ( V_2 , V_90 , V_7 ) ;
V_90 = V_87 -> V_9 - 1 ;
F_6 ( V_2 , V_90 , V_7 ) ;
V_90 = V_101 ;
if ( V_89 == V_102 )
V_90 |= V_103 ;
else if ( V_89 == V_104 )
V_90 |= V_105 ;
if ( V_87 -> V_94 & V_106 ) {
V_90 |= V_87 -> V_107 ;
V_90 |= V_108 ;
} else {
V_90 |= V_87 -> V_107 << V_109 ;
}
if ( V_87 -> V_94 & V_110 )
V_90 |= V_111 ;
if ( V_87 -> V_94 & V_95 )
V_90 |= V_112 ;
F_6 ( V_2 , V_90 , V_7 ) ;
if ( ! ( V_87 -> V_94 & V_95 ) )
F_21 ( V_2 ) ;
V_11 = V_69 | V_70 ;
if ( V_2 -> V_41 -> V_113 )
V_11 |= V_83 ;
if ( V_87 -> V_94 & V_95 )
V_11 |= V_79 ;
else if ( V_2 -> V_25 )
V_11 |= V_80 ;
F_13 ( V_2 , V_11 ) ;
F_42 ( V_2 -> V_19 , L_6 ,
F_7 ( V_2 , V_12 ) ) ;
V_91 = F_43 ( & V_2 -> V_84 ,
V_114 ) ;
F_12 ( V_2 , V_11 ) ;
if ( V_91 == 0 ) {
F_27 ( V_2 -> V_19 , L_7 ) ;
F_30 ( V_2 ) ;
return - V_20 ;
}
F_42 ( V_2 -> V_19 , L_8 ,
V_91 , F_44 ( & V_2 -> V_84 ) ,
V_2 -> V_74 ) ;
if ( F_45 ( V_2 -> V_74 == V_93 ) )
return 0 ;
if ( V_2 -> V_74 == V_76 )
F_32 ( F_46 ( 2 * 1000000 , V_2 -> V_115 ) ) ;
F_30 ( V_2 ) ;
if ( V_2 -> V_74 == V_76 ) {
if ( V_87 -> V_94 & V_110 )
return 0 ;
return - V_116 ;
}
return - V_117 ;
}
static int F_47 ( struct V_118 * V_119 , struct V_86 V_120 [] ,
int V_121 )
{
struct V_1 * V_2 = F_48 ( V_119 ) ;
int V_122 ;
int V_40 = 0 ;
if ( V_2 -> V_123 )
return - V_124 ;
V_40 = F_25 ( V_2 ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_19 , L_4 , V_40 ) ;
return V_40 ;
}
for ( V_122 = 0 ; V_122 < V_121 ; V_122 ++ ) {
enum V_88 V_125 = V_126 ;
if ( V_122 < ( V_121 - 1 ) ) {
if ( V_120 [ V_122 + 1 ] . V_94 & V_127 )
V_125 = V_102 ;
else
V_125 = V_104 ;
}
V_40 = F_40 ( V_2 , & V_120 [ V_122 ] , V_125 ) ;
if ( V_40 )
break;
}
F_29 ( V_2 ) ;
return V_40 ? : V_122 ;
}
static T_1 F_49 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_48 ( V_119 ) ;
T_1 V_40 = V_128 | V_129 | V_130 |
V_131 ;
if ( V_2 -> V_41 -> V_132 )
V_40 |= V_133 ;
return V_40 ;
}
static int F_50 ( struct V_134 * V_135 )
{
struct V_1 * V_2 ;
struct V_136 * V_137 ;
struct V_138 * V_44 ;
struct V_138 * V_43 ;
void T_5 * V_5 ;
int V_65 ;
int V_40 = 0 ;
int V_139 = V_140 ;
V_137 = F_51 ( V_135 , V_141 , 0 ) ;
V_5 = F_52 ( & V_135 -> V_19 , V_137 ) ;
if ( F_53 ( V_5 ) )
return F_54 ( V_5 ) ;
V_137 = F_51 ( V_135 , V_142 , 0 ) ;
if ( ! V_137 ) {
F_27 ( & V_135 -> V_19 , L_9 ) ;
return - V_92 ;
}
V_65 = V_137 -> V_143 ;
V_44 = F_55 ( & V_135 -> V_19 , L_10 ) ;
if ( F_53 ( V_44 ) ) {
F_27 ( & V_135 -> V_19 , L_11 ) ;
return F_54 ( V_44 ) ;
}
V_2 = F_56 ( & V_135 -> V_19 , sizeof( * V_2 ) , V_144 ) ;
if ( ! V_2 )
return - V_145 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_146 . V_147 = & V_148 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_98 = V_135 -> V_149 ;
V_2 -> V_19 = & V_135 -> V_19 ;
V_2 -> V_47 = F_57 ( & V_135 -> V_19 , L_12 ) ;
if ( F_53 ( V_2 -> V_47 ) ) {
F_27 ( & V_135 -> V_19 , L_13 ) ;
return F_54 ( V_2 -> V_47 ) ;
}
V_40 = F_58 ( V_2 -> V_19 -> V_150 , L_14 ,
& V_2 -> V_115 ) ;
if ( V_40 )
V_2 -> V_115 = 100000 ;
V_2 -> V_41 = & V_151 ;
if ( V_135 -> V_19 . V_150 ) {
const struct V_152 * V_153 ;
V_153 = F_59 ( V_154 , & V_135 -> V_19 ) ;
V_2 -> V_41 = V_153 -> V_8 ;
V_2 -> V_6 = F_60 ( V_135 -> V_19 . V_150 ,
L_15 ) ;
} else if ( V_135 -> V_149 == 3 ) {
V_2 -> V_6 = 1 ;
}
F_61 ( & V_2 -> V_84 ) ;
if ( ! V_2 -> V_41 -> V_42 ) {
V_43 = F_55 ( & V_135 -> V_19 , L_16 ) ;
if ( F_53 ( V_43 ) ) {
F_27 ( & V_135 -> V_19 , L_17 ) ;
return F_54 ( V_43 ) ;
}
V_2 -> V_43 = V_43 ;
}
F_62 ( V_135 , V_2 ) ;
if ( ! V_2 -> V_41 -> V_42 ) {
V_40 = F_63 ( V_2 -> V_43 ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_19 , L_18 , V_40 ) ;
return V_40 ;
}
}
V_139 *= ( V_2 -> V_41 -> V_53 + 1 ) ;
V_40 = F_64 ( V_2 -> V_44 ,
V_2 -> V_115 * V_139 ) ;
if ( V_40 ) {
F_27 ( V_2 -> V_19 , L_19 , V_40 ) ;
goto V_155;
}
V_40 = F_63 ( V_2 -> V_44 ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_19 , L_18 , V_40 ) ;
goto V_155;
}
V_40 = F_30 ( V_2 ) ;
if ( V_40 ) {
F_27 ( & V_135 -> V_19 , L_20 ) ;
goto V_156;
}
V_40 = F_65 ( & V_135 -> V_19 , V_2 -> V_65 ,
F_35 , 0 , F_66 ( & V_135 -> V_19 ) , V_2 ) ;
if ( V_40 ) {
F_27 ( & V_135 -> V_19 , L_21 , V_2 -> V_65 ) ;
goto V_156;
}
F_67 ( & V_2 -> V_146 , V_2 ) ;
V_2 -> V_146 . V_157 = V_158 ;
V_2 -> V_146 . V_159 = V_160 ;
F_68 ( V_2 -> V_146 . V_161 , L_22 ,
sizeof( V_2 -> V_146 . V_161 ) ) ;
V_2 -> V_146 . V_147 = & V_148 ;
V_2 -> V_146 . V_19 . V_162 = & V_135 -> V_19 ;
V_2 -> V_146 . V_163 = V_135 -> V_149 ;
V_2 -> V_146 . V_19 . V_150 = V_135 -> V_19 . V_150 ;
V_40 = F_69 ( & V_2 -> V_146 ) ;
if ( V_40 ) {
F_27 ( & V_135 -> V_19 , L_23 ) ;
goto V_156;
}
return 0 ;
V_156:
F_70 ( V_2 -> V_44 ) ;
V_155:
if ( ! V_2 -> V_41 -> V_42 )
F_70 ( V_2 -> V_43 ) ;
return V_40 ;
}
static int F_71 ( struct V_134 * V_135 )
{
struct V_1 * V_2 = F_72 ( V_135 ) ;
F_73 ( & V_2 -> V_146 ) ;
F_70 ( V_2 -> V_44 ) ;
if ( ! V_2 -> V_41 -> V_42 )
F_70 ( V_2 -> V_43 ) ;
return 0 ;
}
static int F_74 ( struct V_164 * V_19 )
{
struct V_1 * V_2 = F_75 ( V_19 ) ;
F_76 ( & V_2 -> V_146 ) ;
V_2 -> V_123 = true ;
F_77 ( & V_2 -> V_146 ) ;
return 0 ;
}
static int F_78 ( struct V_164 * V_19 )
{
struct V_1 * V_2 = F_75 ( V_19 ) ;
int V_40 ;
F_76 ( & V_2 -> V_146 ) ;
V_40 = F_30 ( V_2 ) ;
if ( V_40 ) {
F_77 ( & V_2 -> V_146 ) ;
return V_40 ;
}
V_2 -> V_123 = false ;
F_77 ( & V_2 -> V_146 ) ;
return 0 ;
}
static int T_6 F_79 ( void )
{
return F_80 ( & V_165 ) ;
}
static void T_7 F_81 ( void )
{
F_82 ( & V_165 ) ;
}
