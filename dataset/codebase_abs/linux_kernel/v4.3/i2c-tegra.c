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
unsigned long V_13 = V_14 + V_15 ;
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
V_46 |= V_2 -> V_53 <<
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
if ( V_2 -> V_41 -> V_64 ) {
F_6 ( V_2 , V_65 , V_66 ) ;
while ( F_7 ( V_2 , V_66 ) != 0 ) {
if ( F_15 ( V_14 , V_13 ) ) {
F_16 ( V_2 -> V_19 ,
L_5 ) ;
return - V_20 ;
}
F_17 ( 1 ) ;
}
}
F_29 ( V_2 ) ;
if ( V_2 -> V_67 ) {
V_2 -> V_67 = 0 ;
F_34 ( V_2 -> V_68 ) ;
}
return V_45 ;
}
static T_4 F_35 ( int V_68 , void * V_69 )
{
T_1 V_70 ;
const T_1 V_71 = V_72 | V_73 ;
struct V_1 * V_2 = V_69 ;
V_70 = F_7 ( V_2 , V_74 ) ;
if ( V_70 == 0 ) {
F_16 ( V_2 -> V_19 , L_6 ,
F_7 ( V_2 , V_75 ) ,
F_7 ( V_2 , V_76 ) ,
F_7 ( V_2 , V_51 ) ) ;
V_2 -> V_77 |= V_78 ;
if ( ! V_2 -> V_67 ) {
F_36 ( V_2 -> V_68 ) ;
V_2 -> V_67 = 1 ;
}
goto V_45;
}
if ( F_37 ( V_70 & V_71 ) ) {
if ( V_70 & V_72 )
V_2 -> V_77 |= V_79 ;
if ( V_70 & V_73 )
V_2 -> V_77 |= V_80 ;
goto V_45;
}
if ( V_2 -> V_81 && ( V_70 & V_82 ) ) {
if ( V_2 -> V_25 )
F_18 ( V_2 ) ;
else
F_38 () ;
}
if ( ! V_2 -> V_81 && ( V_70 & V_83 ) ) {
if ( V_2 -> V_25 )
F_21 ( V_2 ) ;
else
F_12 ( V_2 , V_83 ) ;
}
F_6 ( V_2 , V_70 , V_74 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_84 , V_85 ) ;
if ( V_70 & V_86 ) {
F_19 ( V_2 -> V_25 ) ;
F_39 ( & V_2 -> V_87 ) ;
}
return V_88 ;
V_45:
F_12 ( V_2 , V_72 | V_73 |
V_86 | V_83 |
V_82 ) ;
F_6 ( V_2 , V_70 , V_74 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_84 , V_85 ) ;
F_39 ( & V_2 -> V_87 ) ;
return V_88 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_89 * V_90 , enum V_91 V_92 )
{
T_1 V_93 ;
T_1 V_11 ;
unsigned long V_94 ;
F_14 ( V_2 ) ;
if ( V_90 -> V_9 == 0 )
return - V_95 ;
V_2 -> V_23 = V_90 -> V_22 ;
V_2 -> V_25 = V_90 -> V_9 ;
V_2 -> V_77 = V_96 ;
V_2 -> V_81 = ( V_90 -> V_97 & V_98 ) ;
F_41 ( & V_2 -> V_87 ) ;
V_93 = ( 0 << V_99 ) |
V_100 |
( V_2 -> V_101 << V_102 ) |
( 1 << V_103 ) ;
F_6 ( V_2 , V_93 , V_7 ) ;
V_93 = V_90 -> V_9 - 1 ;
F_6 ( V_2 , V_93 , V_7 ) ;
V_93 = V_104 ;
if ( V_92 == V_105 )
V_93 |= V_106 ;
else if ( V_92 == V_107 )
V_93 |= V_108 ;
if ( V_90 -> V_97 & V_109 ) {
V_93 |= V_90 -> V_110 ;
V_93 |= V_111 ;
} else {
V_93 |= V_90 -> V_110 << V_112 ;
}
if ( V_90 -> V_97 & V_113 )
V_93 |= V_114 ;
if ( V_90 -> V_97 & V_98 )
V_93 |= V_115 ;
F_6 ( V_2 , V_93 , V_7 ) ;
if ( ! ( V_90 -> V_97 & V_98 ) )
F_21 ( V_2 ) ;
V_11 = V_72 | V_73 ;
if ( V_2 -> V_41 -> V_116 )
V_11 |= V_86 ;
if ( V_90 -> V_97 & V_98 )
V_11 |= V_82 ;
else if ( V_2 -> V_25 )
V_11 |= V_83 ;
F_13 ( V_2 , V_11 ) ;
F_42 ( V_2 -> V_19 , L_7 ,
F_7 ( V_2 , V_12 ) ) ;
V_94 = F_43 ( & V_2 -> V_87 ,
V_117 ) ;
F_12 ( V_2 , V_11 ) ;
if ( V_94 == 0 ) {
F_27 ( V_2 -> V_19 , L_8 ) ;
F_30 ( V_2 ) ;
return - V_20 ;
}
F_42 ( V_2 -> V_19 , L_9 ,
V_94 , F_44 ( & V_2 -> V_87 ) ,
V_2 -> V_77 ) ;
if ( F_45 ( V_2 -> V_77 == V_96 ) )
return 0 ;
if ( V_2 -> V_77 == V_79 )
F_32 ( F_46 ( 2 * 1000000 , V_2 -> V_118 ) ) ;
F_30 ( V_2 ) ;
if ( V_2 -> V_77 == V_79 ) {
if ( V_90 -> V_97 & V_113 )
return 0 ;
return - V_119 ;
}
return - V_120 ;
}
static int F_47 ( struct V_121 * V_122 , struct V_89 V_123 [] ,
int V_124 )
{
struct V_1 * V_2 = F_48 ( V_122 ) ;
int V_125 ;
int V_40 = 0 ;
if ( V_2 -> V_126 )
return - V_127 ;
V_40 = F_25 ( V_2 ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_19 , L_4 , V_40 ) ;
return V_40 ;
}
for ( V_125 = 0 ; V_125 < V_124 ; V_125 ++ ) {
enum V_91 V_128 = V_129 ;
if ( V_125 < ( V_124 - 1 ) ) {
if ( V_123 [ V_125 + 1 ] . V_97 & V_130 )
V_128 = V_105 ;
else
V_128 = V_107 ;
}
V_40 = F_40 ( V_2 , & V_123 [ V_125 ] , V_128 ) ;
if ( V_40 )
break;
}
F_29 ( V_2 ) ;
return V_40 ? : V_125 ;
}
static T_1 F_49 ( struct V_121 * V_122 )
{
struct V_1 * V_2 = F_48 ( V_122 ) ;
T_1 V_40 = V_131 | ( V_132 & ~ V_133 ) |
V_134 | V_135 ;
if ( V_2 -> V_41 -> V_136 )
V_40 |= V_137 ;
return V_40 ;
}
static int F_50 ( struct V_138 * V_139 )
{
struct V_1 * V_2 ;
struct V_140 * V_141 ;
struct V_142 * V_44 ;
struct V_142 * V_43 ;
void T_5 * V_5 ;
int V_68 ;
int V_40 = 0 ;
int V_143 = V_144 ;
V_141 = F_51 ( V_139 , V_145 , 0 ) ;
V_5 = F_52 ( & V_139 -> V_19 , V_141 ) ;
if ( F_53 ( V_5 ) )
return F_54 ( V_5 ) ;
V_141 = F_51 ( V_139 , V_146 , 0 ) ;
if ( ! V_141 ) {
F_27 ( & V_139 -> V_19 , L_10 ) ;
return - V_95 ;
}
V_68 = V_141 -> V_147 ;
V_44 = F_55 ( & V_139 -> V_19 , L_11 ) ;
if ( F_53 ( V_44 ) ) {
F_27 ( & V_139 -> V_19 , L_12 ) ;
return F_54 ( V_44 ) ;
}
V_2 = F_56 ( & V_139 -> V_19 , sizeof( * V_2 ) , V_148 ) ;
if ( ! V_2 )
return - V_149 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_150 . V_151 = & V_152 ;
V_2 -> V_150 . V_153 = & V_154 ;
V_2 -> V_68 = V_68 ;
V_2 -> V_101 = V_139 -> V_155 ;
V_2 -> V_19 = & V_139 -> V_19 ;
V_2 -> V_47 = F_57 ( & V_139 -> V_19 , L_13 ) ;
if ( F_53 ( V_2 -> V_47 ) ) {
F_27 ( & V_139 -> V_19 , L_14 ) ;
return F_54 ( V_2 -> V_47 ) ;
}
V_40 = F_58 ( V_2 -> V_19 -> V_156 , L_15 ,
& V_2 -> V_118 ) ;
if ( V_40 )
V_2 -> V_118 = 100000 ;
V_2 -> V_41 = & V_157 ;
if ( V_139 -> V_19 . V_156 ) {
const struct V_158 * V_159 ;
V_159 = F_59 ( V_160 , & V_139 -> V_19 ) ;
V_2 -> V_41 = V_159 -> V_8 ;
V_2 -> V_6 = F_60 ( V_139 -> V_19 . V_156 ,
L_16 ) ;
} else if ( V_139 -> V_155 == 3 ) {
V_2 -> V_6 = 1 ;
}
F_61 ( & V_2 -> V_87 ) ;
if ( ! V_2 -> V_41 -> V_42 ) {
V_43 = F_55 ( & V_139 -> V_19 , L_17 ) ;
if ( F_53 ( V_43 ) ) {
F_27 ( & V_139 -> V_19 , L_18 ) ;
return F_54 ( V_43 ) ;
}
V_2 -> V_43 = V_43 ;
}
F_62 ( V_139 , V_2 ) ;
if ( ! V_2 -> V_41 -> V_42 ) {
V_40 = F_63 ( V_2 -> V_43 ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_19 , L_19 , V_40 ) ;
return V_40 ;
}
}
V_2 -> V_53 =
V_2 -> V_41 -> V_161 ;
if ( V_2 -> V_41 -> V_162 &&
( V_2 -> V_118 == 1000000 ) )
V_2 -> V_53 =
V_2 -> V_41 -> V_162 ;
V_143 *= ( V_2 -> V_53 + 1 ) ;
V_40 = F_64 ( V_2 -> V_44 ,
V_2 -> V_118 * V_143 ) ;
if ( V_40 ) {
F_27 ( V_2 -> V_19 , L_20 , V_40 ) ;
goto V_163;
}
V_40 = F_63 ( V_2 -> V_44 ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_19 , L_19 , V_40 ) ;
goto V_163;
}
V_40 = F_30 ( V_2 ) ;
if ( V_40 ) {
F_27 ( & V_139 -> V_19 , L_21 ) ;
goto V_164;
}
V_40 = F_65 ( & V_139 -> V_19 , V_2 -> V_68 ,
F_35 , 0 , F_66 ( & V_139 -> V_19 ) , V_2 ) ;
if ( V_40 ) {
F_27 ( & V_139 -> V_19 , L_22 , V_2 -> V_68 ) ;
goto V_164;
}
F_67 ( & V_2 -> V_150 , V_2 ) ;
V_2 -> V_150 . V_165 = V_166 ;
V_2 -> V_150 . V_167 = V_168 ;
F_68 ( V_2 -> V_150 . V_169 , L_23 ,
sizeof( V_2 -> V_150 . V_169 ) ) ;
V_2 -> V_150 . V_151 = & V_152 ;
V_2 -> V_150 . V_19 . V_170 = & V_139 -> V_19 ;
V_2 -> V_150 . V_171 = V_139 -> V_155 ;
V_2 -> V_150 . V_19 . V_156 = V_139 -> V_19 . V_156 ;
V_40 = F_69 ( & V_2 -> V_150 ) ;
if ( V_40 ) {
F_27 ( & V_139 -> V_19 , L_24 ) ;
goto V_164;
}
return 0 ;
V_164:
F_70 ( V_2 -> V_44 ) ;
V_163:
if ( ! V_2 -> V_41 -> V_42 )
F_70 ( V_2 -> V_43 ) ;
return V_40 ;
}
static int F_71 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = F_72 ( V_139 ) ;
F_73 ( & V_2 -> V_150 ) ;
F_70 ( V_2 -> V_44 ) ;
if ( ! V_2 -> V_41 -> V_42 )
F_70 ( V_2 -> V_43 ) ;
return 0 ;
}
static int F_74 ( struct V_172 * V_19 )
{
struct V_1 * V_2 = F_75 ( V_19 ) ;
F_76 ( & V_2 -> V_150 ) ;
V_2 -> V_126 = true ;
F_77 ( & V_2 -> V_150 ) ;
return 0 ;
}
static int F_78 ( struct V_172 * V_19 )
{
struct V_1 * V_2 = F_75 ( V_19 ) ;
int V_40 ;
F_76 ( & V_2 -> V_150 ) ;
V_40 = F_30 ( V_2 ) ;
if ( V_40 ) {
F_77 ( & V_2 -> V_150 ) ;
return V_40 ;
}
V_2 -> V_126 = false ;
F_77 ( & V_2 -> V_150 ) ;
return 0 ;
}
static int T_6 F_79 ( void )
{
return F_80 ( & V_173 ) ;
}
static void T_7 F_81 ( void )
{
F_82 ( & V_173 ) ;
}
