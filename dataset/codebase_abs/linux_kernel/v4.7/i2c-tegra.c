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
if ( V_2 -> V_41 -> V_51 )
V_3 |= V_52 ;
F_6 ( V_2 , V_3 , V_53 ) ;
F_6 ( V_2 , 0 , V_12 ) ;
V_46 = V_2 -> V_41 -> V_54 ;
V_46 |= V_2 -> V_55 <<
V_56 ;
F_6 ( V_2 , V_46 , V_57 ) ;
if ( ! V_2 -> V_6 ) {
T_1 V_58 = F_7 ( V_2 , V_59 ) ;
V_58 |= V_60 | V_61 ;
F_6 ( V_2 , V_58 , V_59 ) ;
F_6 ( V_2 , 0xfc , V_62 ) ;
F_6 ( V_2 , 0x00 , V_63 ) ;
}
V_3 = 7 << V_64 |
0 << V_65 ;
F_6 ( V_2 , V_3 , V_16 ) ;
if ( F_14 ( V_2 ) )
V_45 = - V_20 ;
if ( V_2 -> V_66 && V_2 -> V_41 -> V_67 )
F_6 ( V_2 , V_68 , V_69 ) ;
if ( V_2 -> V_41 -> V_70 ) {
F_6 ( V_2 , V_71 , V_72 ) ;
while ( F_7 ( V_2 , V_72 ) != 0 ) {
if ( F_15 ( V_14 , V_13 ) ) {
F_16 ( V_2 -> V_19 ,
L_5 ) ;
V_45 = - V_20 ;
goto V_45;
}
F_17 ( 1 ) ;
}
}
if ( V_2 -> V_73 ) {
V_2 -> V_73 = 0 ;
F_34 ( V_2 -> V_74 ) ;
}
V_45:
F_29 ( V_2 ) ;
return V_45 ;
}
static T_4 F_35 ( int V_74 , void * V_75 )
{
T_1 V_76 ;
const T_1 V_77 = V_78 | V_79 ;
struct V_1 * V_2 = V_75 ;
V_76 = F_7 ( V_2 , V_80 ) ;
if ( V_76 == 0 ) {
F_16 ( V_2 -> V_19 , L_6 ,
F_7 ( V_2 , V_81 ) ,
F_7 ( V_2 , V_82 ) ,
F_7 ( V_2 , V_53 ) ) ;
V_2 -> V_83 |= V_84 ;
if ( ! V_2 -> V_73 ) {
F_36 ( V_2 -> V_74 ) ;
V_2 -> V_73 = 1 ;
}
goto V_45;
}
if ( F_37 ( V_76 & V_77 ) ) {
if ( V_76 & V_78 )
V_2 -> V_83 |= V_85 ;
if ( V_76 & V_79 )
V_2 -> V_83 |= V_86 ;
goto V_45;
}
if ( V_2 -> V_87 && ( V_76 & V_88 ) ) {
if ( V_2 -> V_25 )
F_18 ( V_2 ) ;
else
F_38 () ;
}
if ( ! V_2 -> V_87 && ( V_76 & V_89 ) ) {
if ( V_2 -> V_25 )
F_21 ( V_2 ) ;
else
F_12 ( V_2 , V_89 ) ;
}
F_6 ( V_2 , V_76 , V_80 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_90 , V_91 ) ;
if ( V_76 & V_92 ) {
F_19 ( V_2 -> V_25 ) ;
F_39 ( & V_2 -> V_93 ) ;
}
return V_94 ;
V_45:
F_12 ( V_2 , V_78 | V_79 |
V_92 | V_89 |
V_88 ) ;
F_6 ( V_2 , V_76 , V_80 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_90 , V_91 ) ;
F_39 ( & V_2 -> V_93 ) ;
return V_94 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_95 * V_96 , enum V_97 V_98 )
{
T_1 V_99 ;
T_1 V_11 ;
unsigned long V_100 ;
F_14 ( V_2 ) ;
if ( V_96 -> V_9 == 0 )
return - V_101 ;
V_2 -> V_23 = V_96 -> V_22 ;
V_2 -> V_25 = V_96 -> V_9 ;
V_2 -> V_83 = V_102 ;
V_2 -> V_87 = ( V_96 -> V_103 & V_104 ) ;
F_41 ( & V_2 -> V_93 ) ;
V_99 = ( 0 << V_105 ) |
V_106 |
( V_2 -> V_107 << V_108 ) |
( 1 << V_109 ) ;
F_6 ( V_2 , V_99 , V_7 ) ;
V_99 = V_96 -> V_9 - 1 ;
F_6 ( V_2 , V_99 , V_7 ) ;
V_99 = V_110 ;
if ( V_98 == V_111 )
V_99 |= V_112 ;
else if ( V_98 == V_113 )
V_99 |= V_114 ;
if ( V_96 -> V_103 & V_115 ) {
V_99 |= V_96 -> V_116 ;
V_99 |= V_117 ;
} else {
V_99 |= V_96 -> V_116 << V_118 ;
}
if ( V_96 -> V_103 & V_119 )
V_99 |= V_120 ;
if ( V_96 -> V_103 & V_104 )
V_99 |= V_121 ;
F_6 ( V_2 , V_99 , V_7 ) ;
if ( ! ( V_96 -> V_103 & V_104 ) )
F_21 ( V_2 ) ;
V_11 = V_78 | V_79 ;
if ( V_2 -> V_41 -> V_122 )
V_11 |= V_92 ;
if ( V_96 -> V_103 & V_104 )
V_11 |= V_88 ;
else if ( V_2 -> V_25 )
V_11 |= V_89 ;
F_13 ( V_2 , V_11 ) ;
F_42 ( V_2 -> V_19 , L_7 ,
F_7 ( V_2 , V_12 ) ) ;
V_100 = F_43 ( & V_2 -> V_93 ,
V_123 ) ;
F_12 ( V_2 , V_11 ) ;
if ( V_100 == 0 ) {
F_27 ( V_2 -> V_19 , L_8 ) ;
F_30 ( V_2 ) ;
return - V_20 ;
}
F_42 ( V_2 -> V_19 , L_9 ,
V_100 , F_44 ( & V_2 -> V_93 ) ,
V_2 -> V_83 ) ;
if ( F_45 ( V_2 -> V_83 == V_102 ) )
return 0 ;
if ( V_2 -> V_83 == V_85 )
F_32 ( F_46 ( 2 * 1000000 , V_2 -> V_124 ) ) ;
F_30 ( V_2 ) ;
if ( V_2 -> V_83 == V_85 ) {
if ( V_96 -> V_103 & V_119 )
return 0 ;
return - V_125 ;
}
return - V_126 ;
}
static int F_47 ( struct V_127 * V_128 , struct V_95 V_129 [] ,
int V_130 )
{
struct V_1 * V_2 = F_48 ( V_128 ) ;
int V_131 ;
int V_40 = 0 ;
if ( V_2 -> V_132 )
return - V_133 ;
V_40 = F_25 ( V_2 ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_19 , L_4 , V_40 ) ;
return V_40 ;
}
for ( V_131 = 0 ; V_131 < V_130 ; V_131 ++ ) {
enum V_97 V_134 = V_135 ;
if ( V_131 < ( V_130 - 1 ) ) {
if ( V_129 [ V_131 + 1 ] . V_103 & V_136 )
V_134 = V_111 ;
else
V_134 = V_113 ;
}
V_40 = F_40 ( V_2 , & V_129 [ V_131 ] , V_134 ) ;
if ( V_40 )
break;
}
F_29 ( V_2 ) ;
return V_40 ? : V_131 ;
}
static T_1 F_49 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_48 ( V_128 ) ;
T_1 V_40 = V_137 | ( V_138 & ~ V_139 ) |
V_140 | V_141 ;
if ( V_2 -> V_41 -> V_142 )
V_40 |= V_143 ;
return V_40 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_144 * V_145 = V_2 -> V_19 -> V_146 ;
int V_40 ;
V_40 = F_51 ( V_145 , L_10 ,
& V_2 -> V_124 ) ;
if ( V_40 )
V_2 -> V_124 = 100000 ;
V_2 -> V_66 = F_52 ( V_145 ,
L_11 ) ;
}
static int F_53 ( struct V_147 * V_148 )
{
struct V_1 * V_2 ;
struct V_149 * V_150 ;
struct V_151 * V_44 ;
struct V_151 * V_43 ;
void T_5 * V_5 ;
int V_74 ;
int V_40 = 0 ;
int V_152 = V_153 ;
V_150 = F_54 ( V_148 , V_154 , 0 ) ;
V_5 = F_55 ( & V_148 -> V_19 , V_150 ) ;
if ( F_56 ( V_5 ) )
return F_57 ( V_5 ) ;
V_150 = F_54 ( V_148 , V_155 , 0 ) ;
if ( ! V_150 ) {
F_27 ( & V_148 -> V_19 , L_12 ) ;
return - V_101 ;
}
V_74 = V_150 -> V_156 ;
V_44 = F_58 ( & V_148 -> V_19 , L_13 ) ;
if ( F_56 ( V_44 ) ) {
F_27 ( & V_148 -> V_19 , L_14 ) ;
return F_57 ( V_44 ) ;
}
V_2 = F_59 ( & V_148 -> V_19 , sizeof( * V_2 ) , V_157 ) ;
if ( ! V_2 )
return - V_158 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_159 . V_160 = & V_161 ;
V_2 -> V_159 . V_162 = & V_163 ;
V_2 -> V_74 = V_74 ;
V_2 -> V_107 = V_148 -> V_164 ;
V_2 -> V_19 = & V_148 -> V_19 ;
V_2 -> V_47 = F_60 ( & V_148 -> V_19 , L_15 ) ;
if ( F_56 ( V_2 -> V_47 ) ) {
F_27 ( & V_148 -> V_19 , L_16 ) ;
return F_57 ( V_2 -> V_47 ) ;
}
F_50 ( V_2 ) ;
V_2 -> V_41 = & V_165 ;
if ( V_148 -> V_19 . V_146 ) {
V_2 -> V_41 = F_61 ( & V_148 -> V_19 ) ;
V_2 -> V_6 = F_62 ( V_148 -> V_19 . V_146 ,
L_17 ) ;
} else if ( V_148 -> V_164 == 3 ) {
V_2 -> V_6 = 1 ;
}
F_63 ( & V_2 -> V_93 ) ;
if ( ! V_2 -> V_41 -> V_42 ) {
V_43 = F_58 ( & V_148 -> V_19 , L_18 ) ;
if ( F_56 ( V_43 ) ) {
F_27 ( & V_148 -> V_19 , L_19 ) ;
return F_57 ( V_43 ) ;
}
V_2 -> V_43 = V_43 ;
}
F_64 ( V_148 , V_2 ) ;
if ( ! V_2 -> V_41 -> V_42 ) {
V_40 = F_65 ( V_2 -> V_43 ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_19 , L_20 , V_40 ) ;
return V_40 ;
}
}
V_2 -> V_55 =
V_2 -> V_41 -> V_166 ;
if ( V_2 -> V_41 -> V_167 &&
( V_2 -> V_124 == 1000000 ) )
V_2 -> V_55 =
V_2 -> V_41 -> V_167 ;
V_152 *= ( V_2 -> V_55 + 1 ) ;
V_40 = F_66 ( V_2 -> V_44 ,
V_2 -> V_124 * V_152 ) ;
if ( V_40 ) {
F_27 ( V_2 -> V_19 , L_21 , V_40 ) ;
goto V_168;
}
V_40 = F_65 ( V_2 -> V_44 ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_19 , L_20 , V_40 ) ;
goto V_168;
}
if ( V_2 -> V_66 ) {
V_40 = F_26 ( V_2 -> V_44 ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_19 , L_22 ,
V_40 ) ;
goto V_169;
}
}
V_40 = F_30 ( V_2 ) ;
if ( V_40 ) {
F_27 ( & V_148 -> V_19 , L_23 ) ;
goto V_170;
}
V_40 = F_67 ( & V_148 -> V_19 , V_2 -> V_74 ,
F_35 , 0 , F_68 ( & V_148 -> V_19 ) , V_2 ) ;
if ( V_40 ) {
F_27 ( & V_148 -> V_19 , L_24 , V_2 -> V_74 ) ;
goto V_170;
}
F_69 ( & V_2 -> V_159 , V_2 ) ;
V_2 -> V_159 . V_171 = V_172 ;
V_2 -> V_159 . V_173 = V_174 ;
F_70 ( V_2 -> V_159 . V_175 , L_25 ,
sizeof( V_2 -> V_159 . V_175 ) ) ;
V_2 -> V_159 . V_19 . V_176 = & V_148 -> V_19 ;
V_2 -> V_159 . V_177 = V_148 -> V_164 ;
V_2 -> V_159 . V_19 . V_146 = V_148 -> V_19 . V_146 ;
V_40 = F_71 ( & V_2 -> V_159 ) ;
if ( V_40 ) {
F_27 ( & V_148 -> V_19 , L_26 ) ;
goto V_170;
}
return 0 ;
V_170:
if ( V_2 -> V_66 )
F_28 ( V_2 -> V_44 ) ;
V_169:
F_72 ( V_2 -> V_44 ) ;
V_168:
if ( ! V_2 -> V_41 -> V_42 )
F_72 ( V_2 -> V_43 ) ;
return V_40 ;
}
static int F_73 ( struct V_147 * V_148 )
{
struct V_1 * V_2 = F_74 ( V_148 ) ;
F_75 ( & V_2 -> V_159 ) ;
if ( V_2 -> V_66 )
F_28 ( V_2 -> V_44 ) ;
F_72 ( V_2 -> V_44 ) ;
if ( ! V_2 -> V_41 -> V_42 )
F_72 ( V_2 -> V_43 ) ;
return 0 ;
}
static int F_76 ( struct V_178 * V_19 )
{
struct V_1 * V_2 = F_77 ( V_19 ) ;
F_78 ( & V_2 -> V_159 ) ;
V_2 -> V_132 = true ;
F_79 ( & V_2 -> V_159 ) ;
return 0 ;
}
static int F_80 ( struct V_178 * V_19 )
{
struct V_1 * V_2 = F_77 ( V_19 ) ;
int V_40 ;
F_78 ( & V_2 -> V_159 ) ;
V_40 = F_30 ( V_2 ) ;
if ( V_40 ) {
F_79 ( & V_2 -> V_159 ) ;
return V_40 ;
}
V_2 -> V_132 = false ;
F_79 ( & V_2 -> V_159 ) ;
return 0 ;
}
static int T_6 F_81 ( void )
{
return F_82 ( & V_179 ) ;
}
static void T_7 F_83 ( void )
{
F_84 ( & V_179 ) ;
}
