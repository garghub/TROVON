static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_5 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_6 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_7 ;
}
static inline unsigned F_4 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) ? 64 : 8 ;
}
static unsigned int F_5 ( unsigned int V_8 ,
unsigned int V_9 , unsigned int V_10 )
{
int V_11 ;
for ( V_11 = 2 ; V_11 < V_10 ; V_11 ++ )
if ( V_9 * V_12 [ V_11 ] >= V_8 )
return V_11 ;
return V_10 ;
}
static unsigned int F_6 ( unsigned int V_8 ,
unsigned int V_9 )
{
int V_11 , div = 4 ;
for ( V_11 = 0 ; V_11 < 7 ; V_11 ++ ) {
if ( V_9 * div >= V_8 )
return V_11 ;
div <<= 1 ;
}
return 7 ;
}
static int F_7 ( const int V_13 )
{
return F_8 ( V_13 , V_14 ) ;
}
static bool F_9 ( struct V_15 * V_16 , struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_1 * V_21 = F_10 ( V_16 ) ;
unsigned int V_13 ;
if ( ! V_16 -> V_22 )
return false ;
if ( ! V_20 )
return false ;
V_13 = V_20 -> V_23 ;
if ( ! V_13 )
V_13 = V_18 -> V_23 ;
V_13 = F_7 ( V_13 ) ;
if ( V_13 != 1 && V_13 != 2 && V_13 != 4 )
return false ;
if ( V_20 -> V_24 < V_21 -> V_25 * V_13 )
return false ;
if ( V_20 -> V_24 % ( V_21 -> V_25 * V_13 ) )
return false ;
return true ;
}
static unsigned int F_11 ( struct V_1 * V_21 ,
unsigned int V_9 , unsigned int * V_26 )
{
unsigned int V_27 , V_28 ;
unsigned int V_8 = V_21 -> V_29 ;
if ( F_12 ( V_9 > V_8 ) )
return 0 ;
V_28 = F_13 ( V_8 ) - F_13 ( V_9 ) ;
if ( V_8 > V_9 << V_28 )
V_28 ++ ;
V_28 = V_10 ( 4U , V_28 ) - 4 ;
if ( F_12 ( V_28 > 0xf ) ) {
F_14 ( V_21 -> V_30 , L_1 ,
V_9 , V_8 ) ;
return 0xff ;
}
V_27 = F_8 ( V_8 , V_9 << V_28 ) - 1 ;
F_15 ( V_21 -> V_30 , L_2 ,
V_31 , V_8 , V_9 , V_28 , V_27 ) ;
* V_26 = ( V_8 / ( V_27 + 1 ) ) >> V_28 ;
return ( V_27 << V_32 ) |
( V_28 << V_33 ) ;
}
static void F_16 ( struct V_1 * V_21 , int V_34 )
{
unsigned V_35 = 0 ;
if ( V_34 & V_36 )
V_35 |= V_37 ;
if ( V_34 & V_38 )
V_35 |= V_39 ;
F_17 ( V_35 , V_21 -> V_40 + V_41 ) ;
}
static void F_18 ( struct V_1 * V_21 )
{
T_1 V_42 ;
V_42 = F_19 ( V_21 -> V_40 + V_43 ) ;
V_42 |= V_44 ;
F_17 ( V_42 , V_21 -> V_40 + V_43 ) ;
}
static int F_20 ( struct V_17 * V_18 ,
struct V_45 * V_46 )
{
struct V_1 * V_21 = F_10 ( V_18 -> V_16 ) ;
T_1 V_47 = V_48 ;
T_1 V_49 = V_46 -> V_50 , V_51 , V_42 ;
T_1 V_52 = F_19 ( V_21 -> V_40 + V_53 ) ;
V_47 |= V_54 ;
V_47 |= F_11 ( V_21 , V_46 -> V_50 , & V_49 ) ;
V_21 -> V_55 = V_49 ;
V_47 |= F_21 ( V_18 -> V_56 ) ;
V_47 |= ( V_46 -> V_13 - 1 ) << V_57 ;
V_52 |= F_22 ( V_18 -> V_56 ) ;
if ( V_18 -> V_58 & V_59 )
V_52 |= F_23 ( V_18 -> V_56 ) ;
else
V_52 &= ~ F_23 ( V_18 -> V_56 ) ;
if ( V_18 -> V_58 & V_60 ) {
V_52 |= F_24 ( V_18 -> V_56 ) ;
V_52 |= F_25 ( V_18 -> V_56 ) ;
} else {
V_52 &= ~ F_24 ( V_18 -> V_56 ) ;
V_52 &= ~ F_25 ( V_18 -> V_56 ) ;
}
if ( V_18 -> V_58 & V_61 )
V_52 |= F_26 ( V_18 -> V_56 ) ;
else
V_52 &= ~ F_26 ( V_18 -> V_56 ) ;
if ( V_21 -> V_62 )
V_47 |= V_63 ;
F_17 ( V_47 , V_21 -> V_40 + V_43 ) ;
V_42 = F_19 ( V_21 -> V_40 + V_64 ) ;
if ( V_18 -> V_58 & V_65 )
V_42 |= V_66 ;
else
V_42 &= ~ V_66 ;
F_17 ( V_42 , V_21 -> V_40 + V_64 ) ;
F_17 ( V_52 , V_21 -> V_40 + V_53 ) ;
V_51 = ( 2 * 1000000 ) / V_49 ;
if ( F_27 ( V_51 < 10 ) )
F_28 ( V_51 ) ;
else
F_29 ( V_51 , V_51 + 10 ) ;
F_17 ( F_30 ( V_21 -> V_25 ) |
F_31 ( V_21 -> V_25 ) |
F_32 ( V_21 -> V_25 ) |
V_67 | V_68 |
V_69 , V_21 -> V_40 + V_70 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_21 )
{
return F_19 ( V_21 -> V_40 + V_71 ) & V_72 ;
}
static void F_34 ( struct V_1 * V_21 )
{
while ( F_33 ( V_21 ) )
F_19 ( V_21 -> V_40 + V_73 ) ;
}
static void F_35 ( struct V_1 * V_21 , int V_34 )
{
unsigned int V_35 = 0 ;
if ( V_34 & V_36 )
V_35 |= V_74 ;
if ( V_34 & V_38 )
V_35 |= V_75 ;
F_17 ( V_35 , V_21 -> V_40 + V_76 ) ;
}
static void F_36 ( struct V_1 * V_21 )
{
unsigned int V_42 ;
V_42 = F_19 ( V_21 -> V_40 + V_77 ) ;
V_42 |= V_78 ;
F_17 ( V_42 , V_21 -> V_40 + V_77 ) ;
}
static int F_37 ( struct V_17 * V_18 , struct V_45 * V_46 )
{
struct V_1 * V_21 = F_10 ( V_18 -> V_16 ) ;
unsigned int V_42 = V_79 | V_80 ;
V_42 |= F_6 ( V_21 -> V_29 , V_46 -> V_50 ) <<
V_81 ;
if ( F_2 ( V_21 ) ) {
V_42 |= ( V_46 -> V_13 - 1 ) << V_82 ;
V_42 |= V_83 ;
} else {
V_42 |= ( V_46 -> V_13 - 1 ) << V_84 ;
}
if ( V_18 -> V_58 & V_59 )
V_42 |= V_85 ;
if ( V_18 -> V_58 & V_60 )
V_42 |= V_86 ;
if ( V_18 -> V_58 & V_61 )
V_42 |= V_87 ;
if ( V_18 -> V_88 < 0 )
V_42 |= ( V_18 -> V_88 + 32 ) <<
( F_2 ( V_21 ) ? V_89 :
V_90 ) ;
F_17 ( V_42 , V_21 -> V_40 + V_77 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_21 )
{
return F_19 ( V_21 -> V_40 + V_91 ) & V_92 ;
}
static void F_39 ( struct V_1 * V_21 )
{
while ( F_19 ( V_21 -> V_40 + V_91 ) & V_92 )
F_19 ( V_21 -> V_40 + V_73 ) ;
}
static void F_40 ( struct V_1 * V_21 , int V_34 )
{
unsigned int V_35 = 0 ;
if ( V_34 & V_36 )
V_35 |= V_93 ;
if ( V_34 & V_38 )
V_35 |= V_94 ;
F_17 ( V_35 , V_21 -> V_40 + V_76 ) ;
}
static void F_41 ( struct V_1 * V_21 )
{
unsigned int V_42 ;
V_42 = F_19 ( V_21 -> V_40 + V_77 ) ;
V_42 |= V_95 ;
F_17 ( V_42 , V_21 -> V_40 + V_77 ) ;
}
static int F_42 ( struct V_17 * V_18 , struct V_45 * V_46 )
{
struct V_1 * V_21 = F_10 ( V_18 -> V_16 ) ;
unsigned int V_42 = V_96 | V_97 ;
unsigned int V_10 = F_1 ( V_21 ) ? 16 : 18 ;
V_42 |= F_5 ( V_21 -> V_29 , V_46 -> V_50 , V_10 ) <<
V_98 ;
V_42 |= V_46 -> V_13 - 1 ;
if ( V_18 -> V_58 & V_59 )
V_42 |= V_99 ;
if ( V_18 -> V_58 & V_60 )
V_42 |= V_100 ;
if ( V_18 -> V_58 & V_61 )
V_42 |= V_101 ;
if ( V_18 -> V_88 < 0 )
V_42 |= ( V_18 -> V_88 + 32 ) << V_102 ;
F_17 ( V_42 , V_21 -> V_40 + V_77 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_21 )
{
return F_19 ( V_21 -> V_40 + V_76 ) & V_103 ;
}
static void F_44 ( struct V_1 * V_21 )
{
F_17 ( 1 , V_21 -> V_40 + V_104 ) ;
}
static void F_45 ( struct V_1 * V_21 , int V_34 )
{
unsigned int V_35 = 0 ;
if ( V_34 & V_36 )
V_35 |= V_105 ;
if ( V_34 & V_38 )
V_35 |= V_106 ;
F_17 ( V_35 , V_21 -> V_40 + V_76 ) ;
}
static void F_46 ( struct V_1 * V_21 )
{
unsigned int V_42 ;
V_42 = F_19 ( V_21 -> V_40 + V_77 ) ;
V_42 |= V_107 ;
F_17 ( V_42 , V_21 -> V_40 + V_77 ) ;
}
static int F_47 ( struct V_17 * V_18 , struct V_45 * V_46 )
{
struct V_1 * V_21 = F_10 ( V_18 -> V_16 ) ;
unsigned int V_42 = V_108 | V_109 ;
V_42 |= F_6 ( V_21 -> V_29 , V_46 -> V_50 ) <<
V_110 ;
V_42 |= V_46 -> V_13 - 1 ;
if ( V_18 -> V_58 & V_59 )
V_42 |= V_111 ;
if ( V_18 -> V_58 & V_60 )
V_42 |= V_112 ;
F_17 ( V_42 , V_21 -> V_40 + V_77 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_21 )
{
return F_19 ( V_21 -> V_40 + V_76 ) & V_113 ;
}
static void F_49 ( struct V_1 * V_21 )
{
F_17 ( 1 , V_21 -> V_40 + V_104 ) ;
}
static void F_50 ( struct V_17 * V_18 , int V_114 )
{
int V_115 = V_114 != V_116 ;
int V_117 = ! ( V_18 -> V_58 & V_61 ) ;
if ( ! F_51 ( V_18 -> V_88 ) )
return;
F_52 ( V_18 -> V_88 , V_117 ^ V_115 ) ;
}
static void F_53 ( struct V_1 * V_21 )
{
while ( V_21 -> V_118 < F_4 ( V_21 ) ) {
if ( ! V_21 -> V_119 )
break;
V_21 -> V_120 ( V_21 ) ;
V_21 -> V_118 ++ ;
}
V_21 -> V_3 -> V_121 ( V_21 ) ;
}
static T_2 F_54 ( int V_122 , void * V_123 )
{
struct V_1 * V_21 = V_123 ;
while ( V_21 -> V_3 -> V_124 ( V_21 ) ) {
V_21 -> V_125 ( V_21 ) ;
V_21 -> V_118 -- ;
}
if ( V_21 -> V_119 ) {
F_53 ( V_21 ) ;
return V_126 ;
}
if ( V_21 -> V_118 ) {
V_21 -> V_3 -> V_127 (
V_21 , V_38 ) ;
return V_126 ;
}
V_21 -> V_3 -> V_127 ( V_21 , 0 ) ;
F_55 ( & V_21 -> V_128 ) ;
return V_126 ;
}
static int F_56 ( struct V_15 * V_16 ,
int V_129 )
{
int V_130 ;
enum V_131 V_132 ;
struct V_133 V_125 = {} , V_120 = {} ;
struct V_1 * V_21 = F_10 ( V_16 ) ;
if ( V_129 == V_21 -> V_129 )
return 0 ;
switch ( V_129 ) {
case 4 :
V_132 = V_134 ;
break;
case 2 :
V_132 = V_135 ;
break;
case 1 :
V_132 = V_136 ;
break;
default:
return - V_137 ;
}
V_120 . V_138 = V_139 ;
V_120 . V_140 = V_21 -> V_141 + V_142 ;
V_120 . V_143 = V_132 ;
V_120 . V_144 = V_21 -> V_25 ;
V_130 = F_57 ( V_16 -> V_145 , & V_120 ) ;
if ( V_130 ) {
F_14 ( V_21 -> V_30 , L_3 , V_130 ) ;
return V_130 ;
}
V_125 . V_138 = V_146 ;
V_125 . V_147 = V_21 -> V_141 + V_73 ;
V_125 . V_148 = V_132 ;
V_125 . V_149 = V_21 -> V_25 ;
V_130 = F_57 ( V_16 -> V_22 , & V_125 ) ;
if ( V_130 ) {
F_14 ( V_21 -> V_30 , L_4 , V_130 ) ;
return V_130 ;
}
V_21 -> V_129 = V_129 ;
return 0 ;
}
static int F_58 ( struct V_17 * V_18 ,
struct V_19 * V_150 )
{
struct V_1 * V_21 = F_10 ( V_18 -> V_16 ) ;
struct V_45 V_46 ;
int V_130 ;
V_46 . V_13 = V_150 ? V_150 -> V_23 : V_18 -> V_23 ;
V_46 . V_50 = V_150 ? V_150 -> V_50 : V_18 -> V_151 ;
if ( ! V_46 . V_50 )
V_46 . V_50 = V_18 -> V_151 ;
if ( ! V_46 . V_13 )
V_46 . V_13 = V_18 -> V_23 ;
if ( V_46 . V_13 <= 8 ) {
V_21 -> V_125 = V_152 ;
V_21 -> V_120 = V_153 ;
} else if ( V_46 . V_13 <= 16 ) {
V_21 -> V_125 = V_154 ;
V_21 -> V_120 = V_155 ;
} else {
V_21 -> V_125 = V_156 ;
V_21 -> V_120 = V_157 ;
}
if ( F_9 ( V_21 -> V_158 . V_16 , V_18 , V_150 ) )
V_21 -> V_62 = 1 ;
else
V_21 -> V_62 = 0 ;
if ( V_21 -> V_62 ) {
V_130 = F_56 ( V_18 -> V_16 ,
F_7 ( V_46 . V_13 ) ) ;
if ( V_130 )
return V_130 ;
}
V_21 -> V_3 -> V_46 ( V_18 , & V_46 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_21 )
{
struct V_15 * V_16 = V_21 -> V_158 . V_16 ;
if ( V_16 -> V_22 ) {
F_60 ( V_16 -> V_22 ) ;
V_16 -> V_22 = NULL ;
}
if ( V_16 -> V_145 ) {
F_60 ( V_16 -> V_145 ) ;
V_16 -> V_145 = NULL ;
}
}
static int F_61 ( struct V_159 * V_30 , struct V_1 * V_21 ,
struct V_15 * V_16 )
{
int V_130 ;
if ( F_62 ( L_5 ) )
return 0 ;
V_21 -> V_25 = F_4 ( V_21 ) / 2 ;
V_16 -> V_145 = F_63 ( V_30 , L_6 ) ;
if ( F_64 ( V_16 -> V_145 ) ) {
V_130 = F_65 ( V_16 -> V_145 ) ;
F_15 ( V_30 , L_7 , V_130 ) ;
V_16 -> V_145 = NULL ;
goto V_160;
}
V_16 -> V_22 = F_63 ( V_30 , L_8 ) ;
if ( F_64 ( V_16 -> V_22 ) ) {
V_130 = F_65 ( V_16 -> V_22 ) ;
F_15 ( V_30 , L_9 , V_130 ) ;
V_16 -> V_22 = NULL ;
goto V_160;
}
F_56 ( V_16 , 1 ) ;
F_66 ( & V_21 -> V_161 ) ;
F_66 ( & V_21 -> V_162 ) ;
V_16 -> V_163 = F_9 ;
V_16 -> V_164 = V_165 ;
V_21 -> V_158 . V_16 -> V_166 = V_167 |
V_168 ;
return 0 ;
V_160:
F_59 ( V_21 ) ;
return V_130 ;
}
static void F_67 ( void * V_169 )
{
struct V_1 * V_21 = (struct V_1 * ) V_169 ;
F_55 ( & V_21 -> V_161 ) ;
}
static void F_68 ( void * V_169 )
{
struct V_1 * V_21 = (struct V_1 * ) V_169 ;
F_55 ( & V_21 -> V_162 ) ;
}
static int F_69 ( struct V_1 * V_21 , int V_170 )
{
unsigned long V_171 = 0 ;
V_171 = ( 8 + 4 ) * V_170 / V_21 -> V_55 ;
V_171 += 1 ;
return F_70 ( 2 * V_171 * V_172 ) ;
}
static int F_71 ( struct V_1 * V_21 ,
struct V_19 * V_20 )
{
struct V_173 * V_174 , * V_175 ;
unsigned long V_176 ;
unsigned long V_171 ;
struct V_15 * V_16 = V_21 -> V_158 . V_16 ;
struct V_177 * V_120 = & V_20 -> V_178 , * V_125 = & V_20 -> V_179 ;
V_175 = F_72 ( V_16 -> V_22 ,
V_125 -> V_180 , V_125 -> V_181 , V_146 ,
V_182 | V_183 ) ;
if ( ! V_175 )
return - V_137 ;
V_175 -> V_184 = F_67 ;
V_175 -> V_185 = ( void * ) V_21 ;
F_73 ( V_175 ) ;
F_74 ( & V_21 -> V_161 ) ;
F_75 ( V_16 -> V_22 ) ;
V_174 = F_72 ( V_16 -> V_145 ,
V_120 -> V_180 , V_120 -> V_181 , V_139 ,
V_182 | V_183 ) ;
if ( ! V_174 ) {
F_76 ( V_16 -> V_145 ) ;
return - V_137 ;
}
V_174 -> V_184 = F_68 ;
V_174 -> V_185 = ( void * ) V_21 ;
F_73 ( V_174 ) ;
F_74 ( & V_21 -> V_162 ) ;
F_75 ( V_16 -> V_145 ) ;
V_176 = F_69 ( V_21 , V_20 -> V_24 ) ;
V_171 = F_77 ( & V_21 -> V_162 ,
V_176 ) ;
if ( ! V_171 ) {
F_14 ( V_21 -> V_30 , L_10 ) ;
F_76 ( V_16 -> V_145 ) ;
F_76 ( V_16 -> V_22 ) ;
return - V_186 ;
}
V_171 = F_77 ( & V_21 -> V_161 ,
V_176 ) ;
if ( ! V_171 ) {
F_14 ( & V_16 -> V_30 , L_11 ) ;
V_21 -> V_3 -> V_187 ( V_21 ) ;
F_76 ( V_16 -> V_22 ) ;
return - V_186 ;
}
return V_20 -> V_24 ;
}
static int F_78 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_1 * V_21 = F_10 ( V_18 -> V_16 ) ;
unsigned long V_176 ;
unsigned long V_171 ;
V_21 -> V_188 = V_20 -> V_188 ;
V_21 -> V_189 = V_20 -> V_189 ;
V_21 -> V_119 = V_20 -> V_24 ;
V_21 -> V_118 = 0 ;
F_74 ( & V_21 -> V_128 ) ;
F_53 ( V_21 ) ;
V_21 -> V_3 -> V_127 ( V_21 , V_36 ) ;
V_176 = F_69 ( V_21 , V_20 -> V_24 ) ;
V_171 = F_77 ( & V_21 -> V_128 ,
V_176 ) ;
if ( ! V_171 ) {
F_14 ( & V_18 -> V_30 , L_12 ) ;
V_21 -> V_3 -> V_187 ( V_21 ) ;
return - V_186 ;
}
return V_20 -> V_24 ;
}
static int F_79 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_1 * V_21 = F_10 ( V_18 -> V_16 ) ;
if ( V_21 -> V_62 )
return F_71 ( V_21 , V_20 ) ;
else
return F_78 ( V_18 , V_20 ) ;
}
static int F_80 ( struct V_17 * V_18 )
{
F_15 ( & V_18 -> V_30 , L_13 , V_31 ,
V_18 -> V_58 , V_18 -> V_23 , V_18 -> V_151 ) ;
if ( F_51 ( V_18 -> V_88 ) )
F_81 ( V_18 -> V_88 ,
V_18 -> V_58 & V_61 ? 0 : 1 ) ;
F_50 ( V_18 , V_116 ) ;
return 0 ;
}
static void F_82 ( struct V_17 * V_18 )
{
}
static int
F_83 ( struct V_15 * V_16 , struct V_190 * V_191 )
{
struct V_1 * V_21 = F_10 ( V_16 ) ;
int V_130 ;
V_130 = F_84 ( V_21 -> V_192 ) ;
if ( V_130 )
return V_130 ;
V_130 = F_84 ( V_21 -> V_193 ) ;
if ( V_130 ) {
F_85 ( V_21 -> V_192 ) ;
return V_130 ;
}
return 0 ;
}
static int
F_86 ( struct V_15 * V_16 , struct V_190 * V_191 )
{
struct V_1 * V_21 = F_10 ( V_16 ) ;
F_85 ( V_21 -> V_193 ) ;
F_85 ( V_21 -> V_192 ) ;
return 0 ;
}
static int F_87 ( struct V_194 * V_195 )
{
struct V_196 * V_197 = V_195 -> V_30 . V_198 ;
const struct V_199 * V_200 =
F_88 ( V_201 , & V_195 -> V_30 ) ;
struct V_202 * V_203 =
F_89 ( & V_195 -> V_30 ) ;
struct V_15 * V_16 ;
struct V_1 * V_21 ;
struct V_204 * V_205 ;
int V_11 , V_130 , V_122 ;
if ( ! V_197 && ! V_203 ) {
F_14 ( & V_195 -> V_30 , L_14 ) ;
return - V_137 ;
}
V_16 = F_90 ( & V_195 -> V_30 , sizeof( struct V_1 ) ) ;
if ( ! V_16 )
return - V_206 ;
F_91 ( V_195 , V_16 ) ;
V_16 -> V_207 = F_92 ( 1 , 32 ) ;
V_16 -> V_208 = V_197 ? - 1 : V_195 -> V_209 ;
V_21 = F_10 ( V_16 ) ;
V_21 -> V_158 . V_16 = V_16 ;
V_21 -> V_30 = & V_195 -> V_30 ;
V_21 -> V_3 = V_200 ? V_200 -> V_210 :
(struct V_211 * ) V_195 -> V_212 -> V_213 ;
if ( V_203 ) {
V_16 -> V_214 = V_203 -> V_214 ;
V_16 -> V_215 = F_93 ( & V_16 -> V_30 ,
sizeof( int ) * V_16 -> V_214 , V_216 ) ;
if ( ! V_16 -> V_215 )
return - V_206 ;
for ( V_11 = 0 ; V_11 < V_16 -> V_214 ; V_11 ++ )
V_16 -> V_215 [ V_11 ] = V_203 -> V_217 [ V_11 ] ;
}
V_21 -> V_158 . V_217 = F_50 ;
V_21 -> V_158 . V_218 = F_58 ;
V_21 -> V_158 . V_219 = F_79 ;
V_21 -> V_158 . V_16 -> V_220 = F_80 ;
V_21 -> V_158 . V_16 -> V_221 = F_82 ;
V_21 -> V_158 . V_16 -> V_222 = F_83 ;
V_21 -> V_158 . V_16 -> V_223 = F_86 ;
V_21 -> V_158 . V_16 -> V_224 = V_60 | V_59 | V_61 ;
if ( F_3 ( V_21 ) )
V_21 -> V_158 . V_16 -> V_224 |= V_65 ;
F_66 ( & V_21 -> V_128 ) ;
V_205 = F_94 ( V_195 , V_225 , 0 ) ;
V_21 -> V_40 = F_95 ( & V_195 -> V_30 , V_205 ) ;
if ( F_64 ( V_21 -> V_40 ) ) {
V_130 = F_65 ( V_21 -> V_40 ) ;
goto V_226;
}
V_21 -> V_141 = V_205 -> V_227 ;
V_122 = F_96 ( V_195 , 0 ) ;
if ( V_122 < 0 ) {
V_130 = V_122 ;
goto V_226;
}
V_130 = F_97 ( & V_195 -> V_30 , V_122 , F_54 , 0 ,
F_98 ( & V_195 -> V_30 ) , V_21 ) ;
if ( V_130 ) {
F_14 ( & V_195 -> V_30 , L_15 , V_122 , V_130 ) ;
goto V_226;
}
V_21 -> V_193 = F_99 ( & V_195 -> V_30 , L_16 ) ;
if ( F_64 ( V_21 -> V_193 ) ) {
V_130 = F_65 ( V_21 -> V_193 ) ;
goto V_226;
}
V_21 -> V_192 = F_99 ( & V_195 -> V_30 , L_17 ) ;
if ( F_64 ( V_21 -> V_192 ) ) {
V_130 = F_65 ( V_21 -> V_192 ) ;
goto V_226;
}
V_130 = F_100 ( V_21 -> V_192 ) ;
if ( V_130 )
goto V_226;
V_130 = F_100 ( V_21 -> V_193 ) ;
if ( V_130 )
goto V_228;
V_21 -> V_29 = F_101 ( V_21 -> V_192 ) ;
if ( F_3 ( V_21 ) ) {
V_130 = F_61 ( & V_195 -> V_30 , V_21 , V_16 ) ;
if ( V_130 == - V_229 )
goto V_230;
if ( V_130 < 0 )
F_14 ( & V_195 -> V_30 , L_18 ,
V_130 ) ;
}
V_21 -> V_3 -> V_187 ( V_21 ) ;
V_21 -> V_3 -> V_127 ( V_21 , 0 ) ;
V_16 -> V_30 . V_198 = V_195 -> V_30 . V_198 ;
V_130 = F_102 ( & V_21 -> V_158 ) ;
if ( V_130 ) {
F_14 ( & V_195 -> V_30 , L_19 , V_130 ) ;
goto V_230;
}
for ( V_11 = 0 ; V_11 < V_16 -> V_214 ; V_11 ++ ) {
if ( ! F_51 ( V_16 -> V_215 [ V_11 ] ) )
continue;
V_130 = F_103 ( & V_195 -> V_30 , V_16 -> V_215 [ V_11 ] ,
V_231 ) ;
if ( V_130 ) {
F_14 ( & V_195 -> V_30 , L_20 ,
V_16 -> V_215 [ V_11 ] ) ;
goto V_230;
}
}
F_104 ( & V_195 -> V_30 , L_21 ) ;
F_85 ( V_21 -> V_193 ) ;
F_85 ( V_21 -> V_192 ) ;
return V_130 ;
V_230:
F_105 ( V_21 -> V_193 ) ;
V_228:
F_105 ( V_21 -> V_192 ) ;
V_226:
F_106 ( V_16 ) ;
return V_130 ;
}
static int F_107 ( struct V_194 * V_195 )
{
struct V_15 * V_16 = F_108 ( V_195 ) ;
struct V_1 * V_21 = F_10 ( V_16 ) ;
F_109 ( & V_21 -> V_158 ) ;
F_17 ( 0 , V_21 -> V_40 + V_77 ) ;
F_110 ( V_21 -> V_193 ) ;
F_110 ( V_21 -> V_192 ) ;
F_59 ( V_21 ) ;
F_106 ( V_16 ) ;
return 0 ;
}
